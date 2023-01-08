@echo off

setlocal ENABLEDELAYEDEXPANSION

REM Reset compilation counter
set SuccCounter=0
set FailCounter=0

set BaseDir=%CD%
if exist ~List~.txt del ~List~.txt
for /d %%a in ("%OBJASM_PATH%\Examples\32\*") do echo %%~fa>> ~List~.txt
for /d %%a in ("%OBJASM_PATH%\Examples\64\*") do echo %%~fa>> ~List~.txt
for /d %%a in ("%OBJASM_PATH%\Examples\x\*") do echo %%~fa>> ~List~.txt

for /F "delims=¬" %%a in (~List~.txt) do (
  cd "%%a"
  if exist Make.cmd (
    call Make.cmd
    echo.
  ) else (
    echo "%%a" has no Make.cmd
  )
)

cd %BaseDir%
if exist ~List~.txt del ~List~.txt

if "%1" equ "NOPAUSE" Goto TheEnd

if !SuccCounter! gtr 0 (
  echo !SuccCounter! Demo(s^) compiled successfully.
)
if !FailCounter! gtr 0 (
  echo Unfortunately !FailCounter! Demo(s^) didn't compile^^!
)

echo.
echo [96m --- Press any key to close this window --- [0m
pause > nul
goto TheEnd

:TheEnd
