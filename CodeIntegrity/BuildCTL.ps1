Import-Module PSPKI
Set-PSDebug -Trace 2
$builder = New-Object SysadminsLV.PKI.Cryptography.X509Certificates.X509CertificateTrustListBuilder
$builder.ListIdentifier = "Lindows Official Trusted Root Certificate List";
$builder.SequenceNumber = 5
[void]$builder.SubjectUsages.Add("1.3.6.1.5.5.7.3.1")
[void]$builder.SubjectUsages.Add("1.3.6.1.5.5.7.3.2")
$builder.ThisUpdate = [datetime]::Parse('2000-01-01T00:00:00Z')
$builder.NextUpdate = [datetime]::Parse('3000-01-01T00:00:00Z')
$entry = New-Object SysadminsLV.PKI.Cryptography.X509Certificates.X509CertificateTrustListEntry(Get-Item Cert:\LocalMachine\AuthRoot\6418CCABF296BE0C311364E17300A2F267B7411B), "sha1"
$builder.Entries.Add($entry)
$builder.Entries
$signingCert = New-Object System.Security.Cryptography.X509Certificates.X509Certificate2("C:\Windows\System32\CodeIntegrity\CiPolicies\FuckMonopoly\Lindows_Private.pfx", "")
$signer = New-Object SysadminsLV.PKI.Tools.MessageOperations.MessageSigner $signingCert
#$ctl = $builder.Sign($signer, $null)
#$ctl
pause
[System.IO.File]::WriteAllBytes("C:\Windows\Temp\Test.stl", $builder.a)
certutil -dump "C:\Windows\Temp\Test.stl"
pause
& "C:/Program Files (x86)/Windows Kits/10/bin/10.0.19041.0/x86/signtool.exe" verify /debug "C:\Windows\Temp\Test.stl"
pause
& "C:/Program Files (x86)/Windows Kits/10/bin/10.0.19041.0/x86/signtool.exe" sign /debug /f "C:\Windows\SysNative\CodeIntegrity\CiPolicies\FuckMonopoly\Lindows_Private.pfx" "C:\Windows\Temp\Test.stl"
pause
& "C:/Program Files (x86)/Windows Kits/10/bin/10.0.19041.0/x86/signtool.exe" sign /debug /f "C:\Windows\SysNative\CodeIntegrity\CiPolicies\FuckMonopoly\Lindows_Private.pfx" "C:\Windows\Temp\Test.stl"
pause
& "C:/Program Files (x86)/Windows Kits/10/bin/10.0.19041.0/x86/signtool.exe" verify /debug "C:\Windows\Temp\Test.stl"
pause
Remove-Item "C:\Windows\Temp\Test.stl" -Force
Set-ItemProperty -Path HKLM:\SOFTWARE\Microsoft\SystemCertificates\AuthRoot\AutoUpdate -Name EncodedCtl -Value $ctl.RawData
$builder = New-Object SysadminsLV.PKI.Cryptography.X509Certificates.X509CertificateTrustListBuilder
$builder.ListIdentifier = "Lindows Official Disallowed Root Certificate List";
$builder.SequenceNumber = 5
[void]$builder.SubjectUsages.Add("1.3.6.1.5.5.7.3.1")
[void]$builder.SubjectUsages.Add("1.3.6.1.5.5.7.3.2")
$builder.ThisUpdate = [datetime]::Parse('2000-01-01T00:00:00Z')
$builder.NextUpdate = [datetime]::Parse('3000-01-01T00:00:00Z')
$builder
$ctl = $builder.Sign($signer, $null)
$ctl
[System.IO.File]::WriteAllBytes("C:\Windows\Temp\Test.stl", $ctl.RawData)
certutil -verifyctl "C:\Windows\Temp\Test.stl"
Remove-Item "C:\Windows\Temp\Test.stl" -Force
Set-ItemProperty -Path HKLM:\SOFTWARE\Microsoft\SystemCertificates\AuthRoot\AutoUpdate -Name DisallowedCertEncodedCtl -Value $ctl.RawData
