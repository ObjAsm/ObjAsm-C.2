@echo off
setlocal ENABLEEXTENSIONS ENABLEDELAYEDEXPANSION
title=ObjAsm Object Library maker

REM Set the following variables =========================================
set ObjectName=MyObject
set TARGET_BITNESS=32
set TARGET_STR_TYPE=STR_TYPE_ANSI

REM ==================================================================

if "%TARGET_STR_TYPE%" == "STR_TYPE_ANSI" (
  cd %OBJASM_PATH%\Code\Objects\lib\!TARGET_BITNESS!A
) else (
  cd %OBJASM_PATH%\Code\Objects\lib\!TARGET_BITNESS!W
)
set TARGET_MODE=RLS
set LogFile=!ObjectName!.log

if exist !ObjectName!.err (del !ObjectName!.err)
if exist !ObjectName!.obj (del !ObjectName!.obj)
if exist !ObjectName!.lib (del !ObjectName!.lib)
if exist !ObjectName!.log (del !ObjectName!.log)

call %OBJASM_PATH%\Build\OA_SET.cmd

echo Building !ObjectName! object ...>!LogFile!
call %Assembler% @"%OBJASM_PATH%\Build\Options\OPT_ASM_LIB_!TARGET_BITNESS!.txt" "%OBJASM_PATH%\Code\Objects\!ObjectName!.asm">>!LogFile! 
if exist !ObjectName!.err (
  echo --- Error compiling source files --->>!LogFile!
  echo. --- Error compiling source file ---
  echo. --- Press any key to close this window ---
  pause>nul
) else (
  REM Create the .lib file
  call %LibraryCompiler% @"%OBJASM_PATH%\Build\Options\OPT_LIB_!TARGET_MODE!_!TARGET_BITNESS!.txt" "!ObjectName!.obj" /OUT:"!ObjectName!.lib">>!LogFile!
  if exist !ObjectName!.lib (
    if exist !ObjectName!.obj (del !ObjectName!.obj) 
    echo Succeeded building library !ObjectName!.lib>>!LogFile!
    echo Succeeded building library !ObjectName!.lib
    echo.
    timeout /T 8
  ) else (
    echo --- Failed building library library !ObjectName!.lib --->>!LogFile!
    echo. --- Failed building library library !ObjectName!.lib ---
    echo. --- Press any key to close this window ---
    pause>nul
  )
)
