@echo off
setlocal ENABLEEXTENSIONS ENABLEDELAYEDEXPANSION
set PATH=%PATH%;%SystemRoot%\system32

set ProjectName=%~n1
REM Clear LogFile variable
set LogFile=%LogFile%

REM Dispaly some information
echo Building resources for !ProjectName! project ...
echo.
if not [!LogFile!] == [] (
  echo Building resources for !ProjectName! project ...> !LogFile!
  echo.>> !LogFile!
)

if exist !ProjectName!.rc (
  REM Set build targets.
  call "%OBJASM_PATH%\Build\OA_TARGET.cmd" %*
  if errorlevel 1 goto Error

  REM Set known tools.
  call "%OBJASM_PATH%\Build\OA_SET.cmd" %*
  if errorlevel 1 goto Error

  REM Prepare for build
  call "%OBJASM_PATH%\Build\OA_PRE.cmd" %*
  if errorlevel 1 goto Error

  REM Compile type libraries
  call "%OBJASM_PATH%\Build\OA_MIDL.cmd" %*
  if errorlevel 1 goto Error

  REM Compile resources
  call "%OBJASM_PATH%\Build\OA_RES.cmd" %*
  if errorlevel 1 goto Error
  goto :EOF

  :Error
  REM call "%OBJASM_PATH%\Build\RA_ERROR.cmd" NOPAUSE
  goto :EOF

) else (

  echo No project file found^^!
  if not [!LogFile!] == [] (
    echo No project file found^^!> !LogFile!
  )
  call "%OBJASM_PATH%\Build\RA_ERROR.cmd" NOPAUSE
)

