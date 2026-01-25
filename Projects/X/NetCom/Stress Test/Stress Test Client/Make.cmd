@echo off
REM Usage: 
REM   1. copy this file to the destination folder.
REM   2. execute it to to start the build process.

if exist "%OBJASM_PATH%" (
  call "%OBJASM_PATH%\Build\OA_BUILD.cmd" %*
) else (
  echo Wrong path to ObjAsm. Check your OBJASM_PATH environment variable.
  if not "%1" equ "NOPAUSE" pause
  exit /b 1
)
