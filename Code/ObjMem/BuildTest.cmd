REM This file is only used to check changes in individual files before building the entire library

REM Change the targets according the intended check
@echo off
set TARGET_BITNESS=64
set TARGET_MODE=RLS
set FileName=AppsUseLightTheme.asm

setlocal ENABLEEXTENSIONS ENABLEDELAYEDEXPANSION

call "%OBJASM_PATH%\Code\ObjMem\InstallObjMemInc.cmd"
echo.

pushd
cd %OBJASM_PATH%\Code\ObjMem\!TARGET_BITNESS!

REM delete all leftover .obj, .lib & .err files that can disturb the assembler
if exist !FileName!.err del !FileName!.err
if exist !FileName!.obj del !FileName!.obj
if exist !FileName!.lib del !FileName!.lib

REM Start assembling all files in current directory
@echo [96mAssembling !FileName! for !TARGET_BITNESS! bit ...[0m
call %OBJASM_PATH%\Build\OA_SET.cmd
call !Assembler! @"%OBJASM_PATH%\Build\Options\OPT_ASM_LIB_!TARGET_BITNESS!.txt" !FileName!
if exist *.err (
  echo. --- Error compiling !FileName! source ---
  echo. --- Press any key to close this window ---
  pause > nul
) else (
  echo Assembling succeeded^^!
  echo. --- Press any key to close this window ---
  pause > nul
)
popd
