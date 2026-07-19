@echo off
REM ============================================================================
REM Download_UASM.cmd - Automatic UASM Assembler Download and Installation
REM ============================================================================
REM
REM This script downloads the latest known UASM binaries (32-bit and 64-bit)
REM from terraspace.co.uk and places them in the current directory.
REM
REM It uses PowerShell (available on Windows 7+) for downloading and extracting.
REM
REM Usage:
REM   Ensure OBJASM_PATH is set, then run this script from anywhere.
REM   It will download and extract UASM32.exe and UASM64.exe into
REM   %OBJASM_PATH%\Build\Tools\Assembler automatically.
REM
REM To update to a newer UASM version:
REM   Change the UASM_VERSION variable below to match the new release.
REM   The URL pattern is: https://www.terraspace.co.uk/uasm<ver>_x86.zip
REM                        https://www.terraspace.co.uk/uasm<ver>_x64.zip
REM
REM ============================================================================

set "UASM_VERSION=257"
set "UASM_BASE_URL=https://www.terraspace.co.uk"
set "UASM_X86_ZIP=uasm%UASM_VERSION%_x86.zip"
set "UASM_X64_ZIP=uasm%UASM_VERSION%_x64.zip"
set "TARGET_DIR=%OBJASM_PATH%\Build\Tools\Assembler"
set "TEMP_DIR=%TARGET_DIR%\_uasm_temp"

echo ============================================================================
echo  UASM Assembler Downloader
echo  Version: %UASM_VERSION% (2.57)
echo  Source:  %UASM_BASE_URL%
echo  Target:  %TARGET_DIR%
echo ============================================================================
echo.

REM --- Verify OBJASM_PATH is set ---
if not defined OBJASM_PATH (
  echo ERROR: OBJASM_PATH environment variable is not set.
  echo        Please set it to your ObjAsm installation directory, e.g. C:\ObjAsm
  exit /b 1
)

REM --- Verify target directory exists ---
if not exist "%TARGET_DIR%" (
  echo ERROR: Target directory does not exist: %TARGET_DIR%
  echo        Please verify your OBJASM_PATH setting.
  exit /b 1
)

REM --- Check if PowerShell is available ---
where powershell >nul 2>&1
if errorlevel 1 (
  echo ERROR: PowerShell is required but not found on this system.
  exit /b 1
)

REM --- Create temp directory ---
if exist "%TEMP_DIR%" rmdir /s /q "%TEMP_DIR%"
mkdir "%TEMP_DIR%"

REM --- Download 32-bit package ---
echo Downloading %UASM_X86_ZIP%...
powershell -NoProfile -ExecutionPolicy Bypass -Command ^
  "[Net.ServicePointManager]::SecurityProtocol = [Net.SecurityProtocolType]::Tls12; Invoke-WebRequest -Uri '%UASM_BASE_URL%/%UASM_X86_ZIP%' -OutFile '%TEMP_DIR%\%UASM_X86_ZIP%'"

if not exist "%TEMP_DIR%\%UASM_X86_ZIP%" (
  echo ERROR: Failed to download %UASM_X86_ZIP%
  goto :cleanup_error
)
echo   OK.

REM --- Download 64-bit package ---
echo Downloading %UASM_X64_ZIP%...
powershell -NoProfile -ExecutionPolicy Bypass -Command ^
  "[Net.ServicePointManager]::SecurityProtocol = [Net.SecurityProtocolType]::Tls12; Invoke-WebRequest -Uri '%UASM_BASE_URL%/%UASM_X64_ZIP%' -OutFile '%TEMP_DIR%\%UASM_X64_ZIP%'"

if not exist "%TEMP_DIR%\%UASM_X64_ZIP%" (
  echo ERROR: Failed to download %UASM_X64_ZIP%
  goto :cleanup_error
)
echo   OK.

REM --- Extract 32-bit package ---
echo Extracting %UASM_X86_ZIP%...
powershell -NoProfile -ExecutionPolicy Bypass -Command ^
  "Expand-Archive -Path '%TEMP_DIR%\%UASM_X86_ZIP%' -DestinationPath '%TEMP_DIR%\x86' -Force"

REM --- Extract 64-bit package ---
echo Extracting %UASM_X64_ZIP%...
powershell -NoProfile -ExecutionPolicy Bypass -Command ^
  "Expand-Archive -Path '%TEMP_DIR%\%UASM_X64_ZIP%' -DestinationPath '%TEMP_DIR%\x64' -Force"

REM --- Find and copy UASM executables ---
echo.
echo Installing UASM binaries to: %TARGET_DIR%

REM Search for UASM32.exe (might be in a subfolder or named differently)
set "FOUND_32="
for /r "%TEMP_DIR%\x86" %%f in (UASM32.exe uasm32.exe UASM.exe uasm.exe) do (
  if not defined FOUND_32 (
    copy /y "%%f" "%TARGET_DIR%\UASM32.exe" >nul
    set "FOUND_32=1"
    echo   UASM32.exe installed from %%f
  )
)
if not defined FOUND_32 (
  echo WARNING: Could not find UASM32.exe in the x86 package.
  echo          You may need to manually copy it from: %TEMP_DIR%\x86
)

REM Search for UASM64.exe
set "FOUND_64="
for /r "%TEMP_DIR%\x64" %%f in (UASM64.exe uasm64.exe UASM.exe uasm.exe) do (
  if not defined FOUND_64 (
    copy /y "%%f" "%TARGET_DIR%\UASM64.exe" >nul
    set "FOUND_64=1"
    echo   UASM64.exe installed from %%f
  )
)
if not defined FOUND_64 (
  echo WARNING: Could not find UASM64.exe in the x64 package.
  echo          You may need to manually copy it from: %TEMP_DIR%\x64
)

REM --- Cleanup ---
echo.
echo Cleaning up temporary files...
rmdir /s /q "%TEMP_DIR%"

echo.
if defined FOUND_32 if defined FOUND_64 (
  echo ============================================================================
  echo  SUCCESS: UASM 2.%UASM_VERSION:~0,1%.%UASM_VERSION:~1% installed successfully.
  echo  Location: %TARGET_DIR%
  echo ============================================================================
  exit /b 0
)

echo WARNING: Not all binaries were installed. Check the output above.
exit /b 1

:cleanup_error
echo.
echo Cleaning up after error...
if exist "%TEMP_DIR%" rmdir /s /q "%TEMP_DIR%"
exit /b 1
