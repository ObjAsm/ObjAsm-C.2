@echo off
setlocal ENABLEEXTENSIONS ENABLEDELAYEDEXPANSION
set PATH=%PATH%;%SystemRoot%\system32

set ProjectName=%~n1

REM Dispaly some information
echo Debugging !ProjectName! project ...
echo.

if exist !ProjectName!.exe (
  REM Set build targets.
  call "%OBJASM_PATH%\Build\OA_TARGET.cmd" %*
  REM Set known tools.
  call "%OBJASM_PATH%\Build\OA_SET.cmd" %*
  !Debugger! %*
) else (
  echo [93;101mNo executable found^^![0m
  call "%OBJASM_PATH%\Build\OA_ERROR.cmd" NOPAUSE
)

