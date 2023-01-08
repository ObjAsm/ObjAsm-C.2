@echo off

setlocal ENABLEEXTENSIONS ENABLEDELAYEDEXPANSION

echo [96mBuilding %TARGET_BITNESS% bit %TARGET_STR_NAME% Objects ...[0m

echo.

if [%TARGET_BITNESS%] == [] (
  echo [93;101mMissing targets...[0m
  call %OBJASM_PATH%\Build\OA_ERROR.cmd
) else (
  pushd
  cd %TARGET_FOLDER%
  
  REM delete all leftover .obj, .lib & .err files that can disturb LIB.EXE
  if exist *.err del *.err
  if exist *.obj del *.obj
  if exist *.lib del *.lib
  
  REM Start assembling all files in Objects.lst
  @echo Assembling files ...

  for /F "delims=," %%A IN (%OBJASM_PATH%\Code\Objects\Build\ObjectsX.lst) do (call "%OBJASM_PATH%\Code\Objects\Build\MakeObject.cmd" %%A)
  if [%TARGET_BITNESS%] == [32] (
    for /F "delims=," %%A IN (%OBJASM_PATH%\Code\Objects\Build\Objects32.lst) do (call "%OBJASM_PATH%\Code\Objects\Build\MakeObject.cmd" %%A)
  ) else (
    for /F "delims=," %%A IN (%OBJASM_PATH%\Code\Objects\Build\Objects64.lst) do (call "%OBJASM_PATH%\Code\Objects\Build\MakeObject.cmd" %%A)
  )
  popd
  echo.
)
