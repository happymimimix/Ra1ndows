@echo off
title Lindows Software Package Installer (%~dpnx0)
net.exe session 1>NUL 2>NUL && (goto as_admin) || (goto not_admin)
:not_admin
echo.[91mIMPORTANT! 
echo.This script requires administrator privileges! 
goto EOF
:as_admin
echo|set/p=[0m[1m[40m
IF /i "%~1" EQU "INST" (goto INST)
IF /i "%~1" EQU "UNINST" (goto UNINST)
IF /i "%~1" EQU "LIST" (goto LIST)
IF /i "%~1" EQU "MAKE" (goto MAKE)
POWERSHELL -Command "ECHO '[92mUsage: ' '' 'Install new software package: ' 'LIDEXEC.CMD INST [Path/To/SoftwarePackage.LID]' '' 'Uninstall existing package: ' 'LIDEXEC.CMD UNINST [PackageName]' '' 'List all existing packages: ' 'LIDEXEC.CMD LIST' '' 'Make a new software package: ' 'LIDEXEC.CMD MAKE [PackageName] [PackageVersion] [CreatorName] [Path/To/INST.CMD] [Path/To/UNINST.CMD] [Path/To/PAYLOAD.ZIP] [Path/To/Output.LID]'"
goto EOF
:INST
IF NOT EXIST "%~dpnx2" (goto ERR1)
IF NOT EXIST "%~dpn2.LID" (goto ERR14)
echo.[92mProcessing package "%~dpnx2"
del "C:\ETC\LidExecTemp" /f /s /q 1>NUL 2>NUL
rmdir "C:\ETC\LidExecTemp" /s /q 1>NUL 2>NUL
mkdir "C:\ETC\LidExecTemp"
del "%~dpn2.zip" /s /q 1>NUL 2>NUL
ren "%~dpnx2" "%~n2.zip"
Powershell Expand-Archive -Path """%~dpn2.zip""" -DestinationPath """C:\ETC\LidExecTemp""" -Force
del "%~dpn2.LID" /s /q 1>NUL 2>NUL
ren "%~dpn2.zip" "%~n2.LID"
IF NOT EXIST "C:\ETC\LidExecTemp\About.nfo" (goto ERR2)
IF NOT EXIST "C:\ETC\LidExecTemp\Inst.cmd" (goto ERR2)
IF NOT EXIST "C:\ETC\LidExecTemp\Uninst.cmd" (goto ERR2)
IF NOT EXIST "C:\ETC\LidExecTemp\Payload.zip" (goto ERR2)
del "C:\ETC\LidExecTemp\About.zip" /s /q 1>NUL 2>NUL
ren "C:\ETC\LidExecTemp\About.nfo" "About.zip"
Powershell Expand-Archive -Path """C:\ETC\LidExecTemp\About.zip""" -DestinationPath """C:\ETC\LidExecTemp\About""" -Force
wmic OS get LocalDateTime | find /v "LocalDateTime" > "C:\ETC\LidExecTemp\About\InstallDate.ini"
del "C:\ETC\LidExecTemp\About.nfo" /s /q 1>NUL 2>NUL
ren "C:\ETC\LidExecTemp\About.zip" "About.nfo"
IF NOT EXIST "C:\ETC\LidExecTemp\About\Name.ini" (goto ERR2)
IF NOT EXIST "C:\ETC\LidExecTemp\About\Version.ini" (goto ERR2)
IF NOT EXIST "C:\ETC\LidExecTemp\About\Creator.ini" (goto ERR2)
IF NOT EXIST "C:\ETC\LidExecTemp\About\InstallDate.ini" (goto ERR2)
SET /P Name=<"C:\ETC\LidExecTemp\About\Name.ini"
SET /P Version=<"C:\ETC\LidExecTemp\About\Version.ini"
SET /P Creator=<"C:\ETC\LidExecTemp\About\Creator.ini"
SET /P InstallDate=<"C:\ETC\LidExecTemp\About\InstallDate.ini"
set InstallDate=%InstallDate:~0,8%
rmdir "C:\ETC\LidExecTemp\About" /s /q
echo.[92mInstalling package %Name%
REG ADD "HKLM\SOFTWARE\LindowsExclusive\%Name%" /f
REG ADD "HKLM\SOFTWARE\LindowsExclusive\%Name%" /v "InstallDate" /t REG_SZ /d "%InstallDate%" /f
REG ADD "HKLM\SOFTWARE\LindowsExclusive\%Name%" /v "Creator" /t REG_SZ /d "%Creator%" /f
REG ADD "HKLM\SOFTWARE\LindowsExclusive\%Name%" /v "Version" /t REG_SZ /d "%Version%" /f
REG ADD "HKLM\SOFTWARE\LindowsExclusive\%Name%" /v "UninstallerPath" /t REG_SZ /d "C:\Bin\%Name%\Uninst.cmd" /f
REG ADD "HKLM\SOFTWARE\Microsoft\Windows\CurrentVersion\Uninstall\%Name%" /v DisplayName /t REG_SZ /d "[LID] %Name%" /f
REG ADD "HKLM\SOFTWARE\Microsoft\Windows\CurrentVersion\Uninstall\%Name%" /v Publisher /t REG_SZ /d "%Creator%" /f
REG ADD "HKLM\SOFTWARE\Microsoft\Windows\CurrentVersion\Uninstall\%Name%" /v DisplayVersion /t REG_SZ /d "%Version%" /f
REG ADD "HKLM\SOFTWARE\Microsoft\Windows\CurrentVersion\Uninstall\%Name%" /v UninstallString /t REG_SZ /d "CMD.exe /c LIDEXEC UNINST \"%Name%\"" /f
REG ADD "HKLM\SOFTWARE\Microsoft\Windows\CurrentVersion\Uninstall\%Name%" /v NoModify /t REG_DWORD /d 1 /f
mkdir "C:\Bin\%Name%"
echo.[92mCopying files
copy "C:\ETC\LidExecTemp\Inst.cmd" "C:\Bin\%Name%\Inst.cmd" /v /y
copy "C:\ETC\LidExecTemp\Uninst.cmd" "C:\Bin\%Name%\Uninst.cmd" /v /y
copy "C:\ETC\LidExecTemp\Payload.zip" "C:\Bin\%Name%\Payload.zip" /v /y
rmdir "C:\ETC\LidExecTemp" /s /q
echo.[92mRunning installation script[0m
pushd "C:\Bin\%Name%"
call "C:\Bin\%Name%\Inst.cmd" &&del "C:\Bin\%Name%\Inst.cmd" /f /q
popd
echo.[92mInstallation finished
goto EOF
:UNINST
REG QUERY "HKLM\SOFTWARE\LindowsExclusive\%~2">nul
IF "%errorlevel%" NEQ "0" (goto ERR3)
echo.[92mUninstalling package %~2
setlocal enabledelayedexpansion
for /f "tokens=*" %%j in ('reg query "HKLM\SOFTWARE\LindowsExclusive\%~2" /v UninstallerPath /f * /d ^| find /v "HKEY" ^| find /v "End"') do (
set UninstallerPath=%%j
set UninstallerPath=!UninstallerPath:~29!
)
setlocal disabledelayedexpansion
REG DELETE "HKLM\SOFTWARE\LindowsExclusive\%~2" /va /f
REG DELETE "HKLM\SOFTWARE\LindowsExclusive\%~2" /f
REG DELETE "HKLM\SOFTWARE\Microsoft\Windows\CurrentVersion\Uninstall\%~2" /va /f
REG DELETE "HKLM\SOFTWARE\Microsoft\Windows\CurrentVersion\Uninstall\%~2" /f
echo.[92mRunning uninstallation script[0m
pushd "C:\Bin\%~2"
call "%UninstallerPath%" &&del "%UninstallerPath%" /f /q
popd
endlocal
endlocal
echo.[92mUninstallation finished
goto EOF
:LIST
setlocal enabledelayedexpansion
echo.[92mList of installed Lindows packages on this device: [96m
for /f "tokens=*" %%i in ('reg query "HKLM\SOFTWARE\LindowsExclusive" /f * /k ^| find /v "End"') do (
set Name=%%i
set Name=!Name:~31!
for /f "tokens=*" %%j in ('reg query "HKLM\SOFTWARE\LindowsExclusive\!Name!" /v Creator /f * /d ^| find /v "HKEY" ^| find /v "End"') do (
set Creator=%%j
set Creator=!Creator:~21!
)
for /f "tokens=*" %%j in ('reg query "HKLM\SOFTWARE\LindowsExclusive\!Name!" /v Version /f * /d ^| find /v "HKEY" ^| find /v "End"') do (
set Version=%%j
set Version=!Version:~21!
)
for /f "tokens=*" %%j in ('reg query "HKLM\SOFTWARE\LindowsExclusive\!Name!" /v InstallDate /f * /d ^| find /v "HKEY" ^| find /v "End"') do (
set InstallDate=%%j
set InstallDate=!InstallDate:~25!
)
echo.Name: !Name!	^| Creator: !Creator!	^| Version: !Version!	^| Installation date: !InstallDate:~0,4!/!InstallDate:~4,2!/!InstallDate:~6,2!
echo.
)
endlocal
goto EOF
:MAKE
echo.[92mBuilding package "%~2"
del "C:\ETC\LidExecTemp" /f /s /q 1>NUL 2>NUL
rmdir "C:\ETC\LidExecTemp" /s /q 1>NUL 2>NUL
mkdir "C:\ETC\LidExecTemp\About"
IF "%~2" EQU "" (goto ERR4)
IF "%~3" EQU "" (goto ERR5)
IF "%~4" EQU "" (goto ERR6)
IF "%~5" EQU "" (goto ERR7)
IF "%~6" EQU "" (goto ERR8)
IF "%~7" EQU "" (goto ERR9)
IF "%~8" EQU "" (goto ERR10)
echo.%~2>"C:\ETC\LidExecTemp\About\Name.ini"
echo.%~3>"C:\ETC\LidExecTemp\About\Version.ini"
echo.%~4>"C:\ETC\LidExecTemp\About\Creator.ini"
Powershell Compress-Archive -DestinationPath """C:\ETC\LidExecTemp\About.zip""" -Force -Path """C:\ETC\LidExecTemp\About\*""" -CompressionLevel Optimal
del "C:\ETC\LidExecTemp\About.nfo" /s /q 1>NUL 2>NUL
ren "C:\ETC\LidExecTemp\About.zip" "About.nfo"
del "C:\ETC\LidExecTemp\About" /f /s /q
rmdir "C:\ETC\LidExecTemp\About" /s /q
IF NOT EXIST "%~dpnx5" (goto ERR11)
IF NOT EXIST "%~dpnx6" (goto ERR12)
IF NOT EXIST "%~dpnx7" (goto ERR13)
copy "%~dpnx5" "C:\ETC\LidExecTemp\Inst.cmd" /v /y
copy "%~dpnx6" "C:\ETC\LidExecTemp\Uninst.cmd" /v /y
copy "%~dpnx7" "C:\ETC\LidExecTemp\Payload.zip" /v /y
Powershell Compress-Archive -DestinationPath """%~dpn8.zip""" -Force -Path """C:\ETC\LidExecTemp\*""" -CompressionLevel Optimal
del "%~dpn8.LID" /s /q 1>NUL 2>NUL
ren "%~dpn8.zip" "%~n8.LID"
del "C:\ETC\LidExecTemp" /f /s /q
rmdir "C:\ETC\LidExecTemp" /s /q
echo.[92mBuild success
goto EOF
:ERR1
echo.[91mThe package "%~dpnx2" doesn't exist. 
goto EOF
:ERR2
rmdir "C:\ETC\LidExecTemp" /s /q
echo.[91mThe package "%~dpnx2" is invalid. 
goto EOF
:ERR3
echo.[91mThe package "%~2" doesn't exist. 
goto EOF
:ERR4
rmdir "C:\ETC\LidExecTemp" /s /q
echo.[91mMissing parameter: Package name. 
goto EOF
:ERR5
rmdir "C:\ETC\LidExecTemp" /s /q
echo.[91mMissing parameter: Package version. 
goto EOF
:ERR6
rmdir "C:\ETC\LidExecTemp" /s /q
echo.[91mMissing parameter: Creator name. 
goto EOF
:ERR7
rmdir "C:\ETC\LidExecTemp" /s /q
echo.[91mMissing parameter: INST.CMD. 
goto EOF
:ERR8
rmdir "C:\ETC\LidExecTemp" /s /q
echo.[91mMissing parameter: UNINST.CMD. 
goto EOF
:ERR9
rmdir "C:\ETC\LidExecTemp" /s /q
echo.[91mMissing parameter: PAYLOAD.ZIP. 
goto EOF
:ERR10
rmdir "C:\ETC\LidExecTemp" /s /q
echo.[91mMissing parameter: OUTPUT.LID. 
goto EOF
:ERR11
rmdir "C:\ETC\LidExecTemp" /s /q
echo.[91mThe file "%~dpnx5" doesn't exist. 
goto EOF
:ERR12
rmdir "C:\ETC\LidExecTemp" /s /q
echo.[91mThe file "%~dpnx6" doesn't exist. 
goto EOF
:ERR13
rmdir "C:\ETC\LidExecTemp" /s /q
echo.[91mThe file "%~dpnx7" doesn't exist. 
goto EOF
:ERR14
echo.[91mUnacceptable format. Packages must have *.LID extension. 
goto EOF
:EOF
echo.[0m
pause
exit /b