@echo off
setlocal ENABLEEXTENSIONS ENABLEDELAYEDEXPANSION
title=ObjAsm Object Library  

REM Set the following variables
set FileName=...
set TARGET_BITNESS=32
set TARGET_STR_TYPE=STR_TYPE_ANSI


set TARGET_MODE=RLS
set LogFile=MakeMyObject.log

if exist !FileName!.err (del !FileName!.err) 
if exist !FileName!.obj (del !FileName!.obj) 
if exist !FileName!.lib (del !FileName!.lib) 

call %OBJASM_PATH%\Build\OA_SET.cmd

echo Building !FileName! object ...>!LogFile!
call %Assembler% @"%OBJASM_PATH%\Build\Options\OPT_ASM_LIB_!TARGET_BITNESS!.txt" "!FileName!.asm">>!LogFile! 
if exist !FileName!.err (
  echo --- Error compiling source files --->>!LogFile!
  echo. --- Error compiling source file ---
  echo. --- Press any key to close this window ---
  pause>nul
) else (
  REM Create the .lib file
  call %LibraryCompiler% @"%OBJASM_PATH%\Build\Options\OPT_LIB_!TARGET_MODE!_!TARGET_BITNESS!.txt" "!FileName!.obj" /OUT:"!FileName!.lib">>!LogFile!
  if exist !FileName!.lib (
    if exist !FileName!.obj (del !FileName!.obj) 
    echo Succeeded building library !FileName!.lib>>!LogFile!
    echo Succeeded building library !FileName!.lib
    echo.
    timeout /T 5
  ) else (
    echo --- Failed building library library !FileName!.lib --->>!LogFile!
    echo. --- Failed building library library !FileName!.lib ---
    echo. --- Press any key to close this window ---
    pause>nul
  )
)
