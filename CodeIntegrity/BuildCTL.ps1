Import-Module PSPKI
$builder = New-Object SysadminsLV.PKI.Cryptography.X509Certificates.X509CertificateTrustListBuilder
$builder.ListIdentifier = "Lindows Official Trusted Root Certificate List";
$builder.SequenceNumber = 5
$builder.HashAlgorithm = "sha256"
[void]$builder.SubjectUsages.Add("1.3.6.1.5.5.7.3.1")
[void]$builder.SubjectUsages.Add("1.3.6.1.5.5.7.3.2")
$builder.ThisUpdate = [datetime]::Parse('2000-01-01T00:00:00Z')
$builder.NextUpdate = [datetime]::Parse('8000-01-01T00:00:00Z')
$entry = New-Object SysadminsLV.PKI.Cryptography.X509Certificates.X509CertificateTrustListEntry(Get-Item Cert:\LocalMachine\AuthRoot\8ACCC807E644C37588F8D3744E6B8D45C280853C), "sha256"
$builder.Entries.Add($entry)
$signingCert = New-Object System.Security.Cryptography.X509Certificates.X509Certificate2("C:\Windows\System32\CodeIntegrity\CiPolicies\FuckMonopoly\Lindows_Private.pfx", "")
$signer = New-Object SysadminsLV.PKI.Tools.MessageOperations.MessageSigner $signingCert
$builder
try {
    $ctl = $builder.Sign($signer, $null)
    Write-Host "签名成功。"
} catch {
    Write-Host "签名失败：" $_.Exception.Message
}
# 检查 CTL 是否包含签名
if ($ctl.Signers.Count -eq 0) {
    Write-Host "CTL 未包含签名！"
} else {
    Write-Host "CTL 已签名，签名者：" $ctl.Signers[0].Certificate.Subject
}
$ctl
[System.IO.File]::WriteAllBytes("C:\Windows\Temp\Test.stl", $ctl.RawData)
certutil -dump "C:\Windows\Temp\Test.stl"
& "C:/Program Files (x86)/Windows Kits/10/bin/10.0.19041.0/x86/signtool.exe" verify "C:\Windows\Temp\Test.stl"
pause
Remove-Item "C:\Windows\Temp\Test.stl" -Force
Set-ItemProperty -Path HKLM:\SOFTWARE\Microsoft\SystemCertificates\AuthRoot\AutoUpdate -Name EncodedCtl -Value $ctl.RawData
$builder = New-Object SysadminsLV.PKI.Cryptography.X509Certificates.X509CertificateTrustListBuilder
$builder.ListIdentifier = "Lindows Official Disallowed Root Certificate List";
$builder.SequenceNumber = 5
$builder.HashAlgorithm = "sha256"
[void]$builder.SubjectUsages.Add("1.3.6.1.5.5.7.3.1")
[void]$builder.SubjectUsages.Add("1.3.6.1.5.5.7.3.2")
$builder.ThisUpdate = [datetime]::Parse('2000-01-01T00:00:00Z')
$builder.NextUpdate = [datetime]::Parse('8000-01-01T00:00:00Z')
$builder
$ctl = $builder.Sign($signer, $null)
$ctl
[System.IO.File]::WriteAllBytes("C:\Windows\Temp\Test.stl", $ctl.RawData)
certutil -verifyctl "C:\Windows\Temp\Test.stl"
Remove-Item "C:\Windows\Temp\Test.stl" -Force
Set-ItemProperty -Path HKLM:\SOFTWARE\Microsoft\SystemCertificates\AuthRoot\AutoUpdate -Name DisallowedCertEncodedCtl -Value $ctl.RawData
