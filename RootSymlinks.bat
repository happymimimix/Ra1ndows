rem Stop hiding shit
ATTRIB -S -H "C:\\*" /S /D /L
rem Get around Microsoft's shit code in Explorer.exe
DEL "C:\System Volume Information" /F /S /Q
RMDIR "C:\System Volume Information" /S /Q
MKDIR "C:\Windows\VolumeInfo"
MKLINK "C:\System Volume Information" "C:\Windows\VolumeInfo" /J
rem NO MORE LOCALIZED NAMES
DEL "C:\Program Files\desktop.ini" /F /Q
DEL "C:\Program Files (x86)\desktop.ini" /F /Q
DEL "C:\ProgramData\desktop.ini" /F /Q
DEL "C:\Users\desktop.ini" /F /Q
rem This directory structure makes more sense
RMDIR "C:\Bin" /S /Q
MOVE /Y "C:\Program Files" "C:\Bin"
MOVE /Y "C:\Program Files (x86)" "C:\Bin\WOW6432Node"
MKDIR "C:\Users\Public\AppData"
RMDIR "C:\Users\Public\AppData\Roaming" /S /Q
MOVE /Y "C:\ProgramData" "C:\Users\Public\AppData\Roaming"
MKLINK "C:\Program Files" "C:\Bin" /J
MKLINK "C:\Program Files (x86)" "C:\Bin\WOW6432Node" /J
MKLINK "C:\ProgramData" "C:\Users\Public\AppData\Roaming" /J
rem Make sure we have the Documents and Settings symlink correctly setup
DEL "C:\Documents and Settings" /F /Q
RMDIR "C:\Documents and Settings" /Q
MKLINK "C:\Documents and Settings" "C:\Users" /J
rem Make SysNative available to 64bit apps as well! 
MKLINK "C:\Windows\SysNative" "C:\Windows\System32" /J
rem Make 32bit and 64bit programs share the same systemprofile
ATTRIB -S -H "C:\Windows\SysNative\config\systemprofile"
ATTRIB -S -H "C:\Windows\SysWOW64\config\systemprofile"
MOVE /Y "C:\Windows\SysNative\config\systemprofile" "C:\Users\SYSTEM"
DEL "C:\Windows\SysNative\config\systemprofile" /F /S /Q
RMDIR "C:\Windows\SysNative\config\systemprofile" /S /Q
DEL "C:\Windows\SysWOW64\config\systemprofile" /F /S /Q
RMDIR "C:\Windows\SysWOW64\config\systemprofile" /S /Q
MKLINK "C:\Windows\SysNative\config\systemprofile" "C:\Users\SYSTEM" /J
MKLINK "C:\Windows\SysWOW64\config\systemprofile" "C:\Users\SYSTEM" /J
rem Make the SYSTEM user actually usable
XCOPY "C:\Users\Default\*" "C:\Users\SYSTEM\" /B /A /V /E /R /I /G /H /O /C /K /Y
pause
