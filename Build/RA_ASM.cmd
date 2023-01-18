@echo off
setlocal ENABLEEXTENSIONS ENABLEDELAYEDEXPANSION
set PATH=%PATH%;%SystemRoot%\system32

set ProjectName=%~n1
REM Clear LogFile variable
set LogFile=%LogFile%

REM Dispaly some information
echo Assembling !ProjectName! project ...
echo.
if not [!LogFile!] == [] (
  echo Assembling !ProjectName! project ...> !LogFile!
  echo.>> !LogFile!
)

REM Set build targets.
call "%OBJASM_PATH%\Build\OA_TARGET.cmd" %*
if errorlevel 1 goto Error

REM Set known tools.
call "%OBJASM_PATH%\Build\OA_SET.cmd" %*
REM if errorlevel 1 goto Error

REM Assemble project
call "%OBJASM_PATH%\Build\OA_ASM.cmd" %*
if errorlevel 1 goto Error
goto :EOF

:Error
call "%OBJASM_PATH%\Build\RA_ERROR.cmd" NOPAUSE

