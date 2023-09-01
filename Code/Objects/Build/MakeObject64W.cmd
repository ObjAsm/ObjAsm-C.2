@echo off
set TARGET_FILE=TestMe
set TARGET_BITNESS=64
set TARGET_MODE=RLS
set TARGET_STR_TYPE=STR_TYPE_WIDE
set TARGET_STR_NAME=WIDE
set TARGET_FOLDER="%OBJASM_PATH%\Code\Objects\Lib\%TARGET_BITNESS%W"

setlocal ENABLEEXTENSIONS ENABLEDELAYEDEXPANSION

echo Building %TARGET_BITNESS% bit %TARGET_STR_NAME% Objects
echo.

pushd
cd %TARGET_FOLDER%
  
REM delete all leftover .obj, .lib & .err files that can disturb LIB.EXE
if exist %TARGET_FILE%.err del %TARGET_FILE%.err
if exist %TARGET_FILE%.obj del %TARGET_FILE%.obj
if exist %TARGET_FILE%.lib del %TARGET_FILE%.lib
  
REM Start assembling all files in Objects.lst
@echo Assembling file ...

call %OBJASM_PATH%\Build\OA_SET.cmd

call %Assembler% @"%OBJASM_PATH%\Build\Options\OPT_ASM_LIB_!TARGET_BITNESS!.txt" "%OBJASM_PATH%\Code\Objects\%TARGET_FILE%.asm"
if exist %TARGET_FILE%.err (
  echo -- Error compiling source files -- Press any key to close this window
  pause > nul
) else (
  REM Create the .lib file
  call %LibraryCompiler% @"%OBJASM_PATH%\Build\Options\OPT_LIB_%TARGET_MODE%_%TARGET_BITNESS%.txt" %TARGET_FILE%.obj /OUT:"%TARGET_FOLDER%\%TARGET_FILE%.lib"
  if not exist "%TARGET_FOLDER%\%TARGET_FILE%.lib" (
    echo -- Error building the lib file -- Press any key to close this window
    pause > nul
  ) else (
    if exist %TARGET_FILE%.obj del %TARGET_FILE%.obj
  )
)

popd
echo.
