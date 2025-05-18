for /f "tokens=3" %%a in ('bcdedit /enum {current} ^| findstr /i description') do set "Name=%%a"
bcdedit /set hypervisorlaunchtype Auto
bcdedit /copy {current} /d "%Name% (Hyper-V Enabled)"
bcdedit /set hypervisorlaunchtype Off
pause
