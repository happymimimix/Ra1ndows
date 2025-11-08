FOR /D %%U in ("C:\Users\*") DO (
ATTRIB "%%~dpnU" -S -H
DEL "%%~dpnU\AppData\Local\Microsoft\WindowsApps" /F /S /Q
RMDIR "%%~dpnU\AppData\Local\Microsoft\WindowsApps" /S /Q
)
pause