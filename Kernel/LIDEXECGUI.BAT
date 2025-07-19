@echo off
:START
title Lindows Software Package Installer GUI (%~dpnx0)
cls
echo.
echo.[94m Lindows Software Package Installer GUI (%~dpnx0)
echo.[96m
echo. [I] Install new software package
echo. [U] Uninstall existing package
echo. [L] List all existing packages
echo. [M] Make a new software package
echo.
CHOICE /C IULM /N
IF "%errorlevel%" EQU "1" (goto INST)
IF "%errorlevel%" EQU "2" (goto UNINST)
IF "%errorlevel%" EQU "3" (goto LIST)
IF "%errorlevel%" EQU "4" (goto MAKE)
:INST
cls
set /P LIDpath=[92mPath to *.LID software package: 
echo.
call LIDEXEC INST "%LIDpath%"
goto START
:UNINST
cls
set /P LIDname=[92mPackage name: 
echo.
call LIDEXEC UNINST "%LIDname%"
goto START
:LIST
cls
call LIDEXEC LIST
goto START
:MAKE
cls
set /P LIDname=[92mPackage name: 
echo.
set /P LIDversion=[92mPackage version: 
echo.
set /P LIDcreator=[92mCreator name: 
echo.
set /P LIDinst=[92mPath to INST.CMD: 
echo.
set /P LIDuninst=[92mPath to UNINST.CMD: 
echo.
set /P LIDpayload=[92mPath to PAYLOAD.ZIP: 
echo.
set /P LIDoutput=[92mPath to OUTPUT.LID: 
echo.
call LIDEXEC MAKE "%LIDname%" "%LIDversion%" "%LIDcreator%" "%LIDinst%" "%LIDuninst%" "%LIDpayload%" "%LIDoutput%"
goto START