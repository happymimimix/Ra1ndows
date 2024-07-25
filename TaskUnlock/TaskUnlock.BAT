setlocal enabledelayedexpansion
for /f "skip=3 tokens=1" %%i in ('PPLcontrol.exe list') do (PPLCONTROL.exe unprotect %%i)
endlocal
notcritical.exe