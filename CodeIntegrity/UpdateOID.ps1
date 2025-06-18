# XCA Enhanced Key Usage Extractor
# This script extracts Enhanced Key Usage OIDs from certutil and formats them for XCA

# Function to get the XCA user settings directory for Windows
function Get-XCAUserDirectory {
    # On Windows, XCA stores user settings in CSIDL_APPDATA\xca
    # This typically resolves to: C:\Users\username\AppData\Roaming\xca
    $appDataPath = [Environment]::GetFolderPath('ApplicationData')
    $xcaPath = Join-Path $appDataPath "xca"
    
    # Create the directory if it doesn't exist
    if (-not (Test-Path $xcaPath)) {
        try {
            New-Item -ItemType Directory -Path $xcaPath -Force | Out-Null
            Write-Host "Created XCA configuration directory: $xcaPath" -ForegroundColor Green
        }
        catch {
            Write-Error "Failed to create XCA configuration directory: $($_.Exception.Message)"
            return $null
        }
    }
    
    return $xcaPath
}

# Function to parse certutil output and extract EKU information
function Parse-CertutilOutput {
    param([string[]]$Output)
    
    $ekuList = @()
    $currentOID = ""
    $currentLongName = ""
    $currentShortName = ""
    
    foreach ($line in $Output) {
        # Skip empty lines and lines that don't contain useful information
        if ([string]::IsNullOrWhiteSpace($line)) { continue }
        
        # Check if this line contains an OID and long name (format: "1.2.3.4 -- Long Name")
        if ($line -match '^(\d+(?:\.\d+)*)\s*--\s*(.+)$') {
            # If we have a previous OID, add it to our list before processing the new one
            if ($currentOID -ne "") {
                $ekuList += @{
                    OID = $currentOID
                    LongName = $currentLongName
                    ShortName = $currentShortName
                }
            }
            
            # Start processing the new OID
            $currentOID = $matches[1].Trim()
            $currentLongName = $matches[2].Trim()
            $currentShortName = "" # Reset for new entry
        }
        # Check if this line contains the short name (format: "  pwszName = Short Name")
        elseif ($line -match '^\s*pwszName\s*=\s*(.+)$') {
            $currentShortName = $matches[1].Trim()
        }
    }
    
    # Don't forget to add the last OID if we have one
    if ($currentOID -ne "") {
        $ekuList += @{
            OID = $currentOID
            LongName = $currentLongName
            ShortName = $currentShortName
        }
    }
    
    return $ekuList
}

# Function to create XCA-compatible files
function Create-XCAFiles {
    param(
        [array]$EKUList,
        [string]$XCADirectory
    )
    
    # Create eku.txt file (Extended Key Usage list for XCA)
    $ekuFilePath = Join-Path $XCADirectory "eku.txt"
    $ekuContent = @()
    
    # Add header comment explaining the file
    $ekuContent += "# Enhanced Key Usage OIDs extracted from Windows certutil"
    $ekuContent += "# Generated on $(Get-Date -Format 'yyyy-MM-dd HH:mm:ss')"
    $ekuContent += "# Format: One entry per line (OID, short name, or long name)"
    $ekuContent += "# These entries reference OID definitions in oids.txt"
    $ekuContent += ""
    
    # Add each EKU entry using the OID (most reliable format)
    # We use OIDs here because they're unambiguous references
    foreach ($eku in $EKUList) {
        if ($eku.OID) {
            $ekuContent += $eku.OID
        }
    }
    
    # Write the eku.txt file
    try {
        $ekuContent | Out-File -FilePath $ekuFilePath -Encoding UTF8
        Write-Host "Successfully created eku.txt with $($EKUList.Count) entries" -ForegroundColor Green
        Write-Host "File location: $ekuFilePath" -ForegroundColor Cyan
    }
    catch {
        Write-Error "Failed to write eku.txt: $($_.Exception.Message)"
        return $false
    }
    
    # Create oids.txt file (Object ID definitions for XCA)
    $oidsFilePath = Join-Path $XCADirectory "oids.txt"
    $oidsContent = @()
    
    # Add header comment explaining the file
    $oidsContent += "# Enhanced Key Usage OID definitions extracted from Windows certutil"
    $oidsContent += "# Generated on $(Get-Date -Format 'yyyy-MM-dd HH:mm:ss')"
    $oidsContent += "# Format: OID:shortname:longname"
    $oidsContent += ""
    
    # Add each OID definition in the format OID:shortname:longname
    foreach ($eku in $EKUList) {
        if ($eku.OID -and $eku.ShortName -and $eku.LongName) {
            # Clean up names to remove any problematic characters
            $shortName = $eku.ShortName -replace ':', '_'
            $longName = $eku.LongName -replace ':', '_'
            $oidsContent += "$($eku.OID):${shortName}:${longName}"
        }
    }
    
    # Write the oids.txt file (append mode in case there's an existing file)
    try {
        # Check if oids.txt already exists
        if (Test-Path $oidsFilePath) {
            Write-Host "Found existing oids.txt, appending new entries..." -ForegroundColor Yellow
            $oidsContent | Add-Content -Path $oidsFilePath -Encoding UTF8
        } else {
            $oidsContent | Out-File -FilePath $oidsFilePath -Encoding UTF8
        }
        Write-Host "Successfully updated oids.txt with EKU definitions" -ForegroundColor Green
        Write-Host "File location: $oidsFilePath" -ForegroundColor Cyan
    }
    catch {
        Write-Error "Failed to write oids.txt: $($_.Exception.Message)"
        return $false
    }
    
    return $true
}

# Main execution block
try {
    Write-Host "XCA Enhanced Key Usage Extractor" -ForegroundColor Magenta
    Write-Host "=================================" -ForegroundColor Magenta
    Write-Host ""
    
    # Step 1: Get the XCA user directory
    Write-Host "Locating XCA configuration directory..." -ForegroundColor Yellow
    $xcaDir = Get-XCAUserDirectory
    if (-not $xcaDir) {
        throw "Failed to get or create XCA configuration directory"
    }
    Write-Host "XCA directory: $xcaDir" -ForegroundColor Green
    Write-Host ""
    
    # Step 2: Run certutil to get Enhanced Key Usage OIDs
    Write-Host "Extracting Enhanced Key Usage OIDs from Windows..." -ForegroundColor Yellow
    try {
        $certutilOutput = & certutil -oid 7 2>&1
        if ($LASTEXITCODE -ne 0) {
            throw "certutil command failed with exit code $LASTEXITCODE"
        }
        Write-Host "Successfully executed certutil -oid 7" -ForegroundColor Green
    }
    catch {
        throw "Failed to run certutil: $($_.Exception.Message)"
    }
    Write-Host ""
    
    # Step 3: Parse the output
    Write-Host "Parsing certutil output..." -ForegroundColor Yellow
    $ekuList = Parse-CertutilOutput -Output $certutilOutput
    if ($ekuList.Count -eq 0) {
        throw "No Enhanced Key Usage OIDs found in certutil output"
    }
    Write-Host "Found $($ekuList.Count) Enhanced Key Usage OIDs" -ForegroundColor Green
    Write-Host ""
    
    # Step 4: Display found OIDs for verification
    Write-Host "Enhanced Key Usage OIDs found:" -ForegroundColor Yellow
    foreach ($eku in $ekuList) {
        Write-Host "  $($eku.OID) - $($eku.LongName)" -ForegroundColor Cyan
        if ($eku.ShortName) {
            Write-Host "    Short name: $($eku.ShortName)" -ForegroundColor Gray
        }
    }
    Write-Host ""
    
    # Step 5: Create XCA files
    Write-Host "Creating XCA configuration files..." -ForegroundColor Yellow
    $success = Create-XCAFiles -EKUList $ekuList -XCADirectory $xcaDir
    if (-not $success) {
        throw "Failed to create XCA configuration files"
    }
    Write-Host ""
    
    # Success message with instructions
    Write-Host "SUCCESS!" -ForegroundColor Green
    Write-Host "========" -ForegroundColor Green
    Write-Host "Enhanced Key Usage configuration files have been created for XCA:" -ForegroundColor Green
    Write-Host "  - eku.txt: Contains the list of Enhanced Key Usage OIDs" -ForegroundColor Cyan
    Write-Host "  - oids.txt: Contains OID definitions with names" -ForegroundColor Cyan
    Write-Host ""
    Write-Host "Next steps:" -ForegroundColor Yellow
    Write-Host "1. Restart XCA to load the new configuration" -ForegroundColor White
    Write-Host "2. The Enhanced Key Usage options should now be available when creating certificates" -ForegroundColor White
    Write-Host "3. You can find these files in: $xcaDir" -ForegroundColor White
    
}
catch {
    Write-Error "Script execution failed: $($_.Exception.Message)"
    Write-Host ""
    Write-Host "Troubleshooting tips:" -ForegroundColor Yellow
    Write-Host "1. Make sure you're running PowerShell as Administrator" -ForegroundColor White
    Write-Host "2. Ensure certutil.exe is available in your PATH" -ForegroundColor White
    Write-Host "3. Check that you have write permissions to the XCA directory" -ForegroundColor White
    exit 1
}