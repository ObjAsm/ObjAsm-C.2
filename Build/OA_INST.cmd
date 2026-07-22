@echo off
setlocal ENABLEEXTENSIONS ENABLEDELAYEDEXPANSION
REM ============================================================================
REM OA_INST.cmd - ObjAsm Interactive Installation Script
REM ============================================================================
REM
REM This script performs a complete ObjAsm installation by:
REM   1. Detecting or setting OBJASM_PATH (the installation root)
REM   2. Verifying prerequisites (Visual Studio, Windows SDK, PowerShell)
REM   3. Downloading and installing UASM assembler binaries
REM   4. Setting the OBJASM_PATH environment variable permanently
REM   5. Verifying OA_SET.cmd can detect all required tools
REM   6. Registering DebugCenter.exe
REM   7. (Optional) Compiling the ObjMem library
REM   8. (Optional) Compiling the Objects
REM   9. (Optional) Compiling Examples and Projects
REM
REM Requirements:
REM   - Visual Studio 2017 or later
REM   - Windows SDK 10+
REM   - PowerShell (for UASM download)
REM   - Run as Administrator if you want to set system-wide environment variables
REM
REM Note on CMD syntax:
REM   This script avoids nested if/else blocks with variable expansion to prevent
REM   parsing issues with paths containing parentheses (e.g. "Program Files (x86)").
REM   Instead it uses goto-based flow control which is immune to such issues.
REM
REM ============================================================================

echo.
echo  ============================================================================
echo   ObjAsm Installation Script
echo  ============================================================================
echo.

REM ============================================================================
REM STEP 1: Determine OBJASM_PATH
REM ============================================================================
REM The script is located at %OBJASM_PATH%\Build\OA_INST.cmd
REM So we go one level up from the script's directory to get the ObjAsm root.

pushd "%~dp0\.."
set "DETECTED_PATH=%CD%"
popd

echo  [Step 1/9] ObjAsm Installation Path
echo  ----------------------------------------------------------------------------

if not defined OBJASM_PATH goto :step1_not_set

echo   Current OBJASM_PATH: !OBJASM_PATH!
echo   Detected path:       !DETECTED_PATH!
echo.
if /i "!OBJASM_PATH!"=="!DETECTED_PATH!" (
  echo   OBJASM_PATH matches detected path. OK.
  goto :step1_done
)
echo   WARNING: OBJASM_PATH does not match the detected installation path.
echo.
choice /c YN /m "  Update OBJASM_PATH to '!DETECTED_PATH!'"
if !errorlevel!==1 set "OBJASM_PATH=!DETECTED_PATH!"
goto :step1_done

:step1_not_set
echo   OBJASM_PATH is not set. Detected installation at:
echo   !DETECTED_PATH!
echo.
set "OBJASM_PATH=!DETECTED_PATH!"
echo   Using: !DETECTED_PATH!

:step1_done
echo.

REM ============================================================================
REM STEP 2: Verify Prerequisites
REM ============================================================================
echo  [Step 2/9] Verifying Prerequisites
echo  ----------------------------------------------------------------------------

set "PREREQ_OK=1"

REM --- Check PowerShell ---
where powershell >nul 2>&1
if errorlevel 1 (
  echo   [FAIL] PowerShell not found. Required for UASM download.
  set "PREREQ_OK=0"
) else (
  echo   [OK]   PowerShell available.
)

REM --- Check Visual Studio via vswhere ---
set "VSWHERE=!ProgramFiles(x86)!\Microsoft Visual Studio\Installer\vswhere.exe"
if not exist "!VSWHERE!" goto :step2_no_vs

set "VS_PATH="
for /f "usebackq tokens=*" %%i in (`"!VSWHERE!" -latest -prerelease -property installationPath`) do set "VS_PATH=%%i"
if not defined VS_PATH goto :step2_no_vs_instance
echo   [OK]   Visual Studio found: !VS_PATH!
goto :step2_check_sdk

:step2_no_vs
echo   [FAIL] Visual Studio not found ^(vswhere.exe missing^).
echo          Install Visual Studio 2017 or later from https://www.visualstudio.com/
set "PREREQ_OK=0"
goto :step2_check_sdk

:step2_no_vs_instance
echo   [FAIL] vswhere.exe exists but no VS installation detected.
set "PREREQ_OK=0"

:step2_check_sdk
REM --- Check Windows SDK ---
set "WINSDKKEY=HKLM\SOFTWARE\WOW6432Node\Microsoft\Microsoft SDKs\Windows\v10.0"
set "WINSDK_FOUND="
set "WINSDK_VER_FOUND="
for /f "tokens=2*" %%a in ('reg query "!WINSDKKEY!" /v InstallationFolder 2^>nul') do set "WINSDK_FOUND=%%b"
for /f "tokens=2*" %%a in ('reg query "!WINSDKKEY!" /v ProductVersion 2^>nul') do set "WINSDK_VER_FOUND=%%b"

if not defined WINSDK_FOUND goto :step2_no_sdk
echo   [OK]   Windows SDK found: !WINSDK_FOUND! ^(v!WINSDK_VER_FOUND!^)
goto :step2_prereq_check

:step2_no_sdk
echo   [FAIL] Windows SDK not found in registry.
echo          Install from https://developer.microsoft.com/en-us/windows/downloads/windows-sdk/
set "PREREQ_OK=0"

:step2_prereq_check
echo.
if "!PREREQ_OK!"=="1" goto :step3
echo   Some prerequisites are missing. Installation may be incomplete.
choice /c YN /m "  Continue anyway"
if !errorlevel!==2 goto :abort

REM ============================================================================
REM STEP 3: Download and Install UASM
REM ============================================================================
:step3
echo.
echo  [Step 3/9] UASM Assembler
echo  ----------------------------------------------------------------------------

set "ASM_DIR=!OBJASM_PATH!\Build\Tools\Assembler"
set "NEED_UASM=0"

if not exist "!ASM_DIR!\UASM64.exe" set "NEED_UASM=1"
if not exist "!ASM_DIR!\UASM32.exe" set "NEED_UASM=1"

if "!NEED_UASM!"=="0" goto :step3_uasm_exists

echo   UASM binaries not found in: !ASM_DIR!
echo   Downloading UASM from terraspace.co.uk...
echo.
call "!OBJASM_PATH!\Build\Tools\Assembler\Download_UASM.cmd"
if errorlevel 1 goto :step3_download_failed
goto :step3_done

:step3_download_failed
echo.
echo   [FAIL] UASM download failed. UASM is required for all build steps.
echo          Please install manually from: http://www.terraspace.co.uk/uasm.html
echo          Place UASM32.exe and UASM64.exe in: !ASM_DIR!
echo.
echo          Installation cannot continue without UASM.
goto :abort

:step3_uasm_exists
set "UASM32_VER="
set "UASM64_VER="
for /f "tokens=2 delims= " %%a in ('""!ASM_DIR!\UASM32.exe" 2>&1"') do if not defined UASM32_VER set "UASM32_VER=%%~a"
for /f "tokens=2 delims= " %%a in ('""!ASM_DIR!\UASM64.exe" 2>&1"') do if not defined UASM64_VER set "UASM64_VER=%%~a"
echo   [OK]   UASM32.exe found ^(!UASM32_VER!^)
echo   [OK]   UASM64.exe found ^(!UASM64_VER!^)
echo.
choice /c YN /m "  Re-download UASM to update to latest version"
if !errorlevel!==2 goto :step3_done
call "!OBJASM_PATH!\Build\Tools\Assembler\Download_UASM.cmd"
if errorlevel 1 echo   [WARN] Update failed, but existing UASM binaries are still in place.

:step3_done
echo.

REM ============================================================================
REM STEP 4: Set OBJASM_PATH Environment Variable Permanently
REM ============================================================================
echo  [Step 4/9] Setting OBJASM_PATH Environment Variable
echo  ----------------------------------------------------------------------------

REM Check if already set in user environment
set "REG_OBJASM="
for /f "tokens=2*" %%a in ('reg query "HKCU\Environment" /v OBJASM_PATH 2^>nul') do set "REG_OBJASM=%%b"

if not defined REG_OBJASM goto :step4_not_set

REM Already set - check if it matches
if /i "!REG_OBJASM!"=="!OBJASM_PATH!" (
  echo   [OK]   OBJASM_PATH already set correctly in user environment.
  goto :step4_done
)
echo   Current registry value: !REG_OBJASM!
echo   New value:              !OBJASM_PATH!
choice /c YN /m "  Update OBJASM_PATH in user environment"
if !errorlevel!==2 goto :step4_done
reg add "HKCU\Environment" /v OBJASM_PATH /t REG_SZ /d "!OBJASM_PATH!" /f >nul
echo   Updated.
goto :step4_broadcast

:step4_not_set
echo   OBJASM_PATH is not set in user environment.
echo   Setting to: !OBJASM_PATH!
choice /c YN /m "  Set OBJASM_PATH permanently for current user"
if !errorlevel!==2 goto :step4_done
reg add "HKCU\Environment" /v OBJASM_PATH /t REG_SZ /d "!OBJASM_PATH!" /f >nul
echo   Done.

:step4_broadcast
REM Broadcast WM_SETTINGCHANGE so other processes pick up the new variable
REM without requiring a reboot or re-login.
echo   Broadcasting environment change to running applications...
powershell -NoProfile -ExecutionPolicy Bypass -Command ^
  "Add-Type -Namespace Win32 -Name NativeMethods -MemberDefinition '[DllImport(\"user32.dll\", SetLastError = true, CharSet = CharSet.Auto)] public static extern IntPtr SendMessageTimeout(IntPtr hWnd, uint Msg, UIntPtr wParam, string lParam, uint fuFlags, uint uTimeout, out UIntPtr lpdwResult);'; $HWND_BROADCAST = [IntPtr]0xffff; $WM_SETTINGCHANGE = 0x1a; $result = [UIntPtr]::Zero; [Win32.NativeMethods]::SendMessageTimeout($HWND_BROADCAST, $WM_SETTINGCHANGE, [UIntPtr]::Zero, 'Environment', 2, 5000, [ref]$result) | Out-Null"
echo   [OK]   Environment variable is now available to new processes.

:step4_done
echo.

REM ============================================================================
REM STEP 5: Verify OA_SET.cmd
REM ============================================================================
:step5
echo  [Step 5/9] Verifying Build Environment ^(OA_SET.cmd^)
echo  ----------------------------------------------------------------------------

call "!OBJASM_PATH!\Build\OA_SET.cmd"
if errorlevel 1 goto :step5_failed

echo   [OK]   Build environment configured successfully.
echo          Assembler:        !Assembler!
echo          Linker:           !Linker!
echo          LibraryCompiler:  !LibraryCompiler!
echo          ResourceCompiler: !ResourceCompiler!
echo          Debugger:         !Debugger!

if not exist !ResourceCompiler! (
  echo.
  echo   [WARN] ResourceCompiler points to a file that does not exist:
  echo          !ResourceCompiler!
  echo          Install the Windows SDK, or place rc.exe in:
  echo          !OBJASM_PATH!\Build\Tools\ResourceCompiler\
)
goto :step6

:step5_failed
echo   [FAIL] OA_SET.cmd reported errors. Check the output above.
echo          You may need to install missing components before proceeding.
choice /c YN /m "  Continue anyway"
if !errorlevel!==2 goto :abort

REM ============================================================================
REM STEP 6: Register DebugCenter
REM ============================================================================
:step6
echo.
echo  [Step 6/9] DebugCenter Registration
echo  ----------------------------------------------------------------------------

set "DBGCENTER=!OBJASM_PATH!\Projects\X\DebugCenter\DebugCenter.exe"
if not exist "!DBGCENTER!" goto :step6_not_found

REM Check if DebugCenter is already registered
reg query "HKCU\Software\DebugCenter" /v Path >nul 2>&1
if not errorlevel 1 (
  echo   [OK]   DebugCenter already registered.
  goto :step7
)

echo   DebugCenter.exe found at: !DBGCENTER!
echo   Running it once to register...
start "" "!DBGCENTER!"
echo   [OK]   DebugCenter launched ^(it will register itself^).
goto :step7

:step6_not_found
echo   [SKIP] DebugCenter.exe not found at expected location.
echo          Expected: !DBGCENTER!

REM ============================================================================
REM STEP 7: (Optional) Compile ObjMem Library
REM ============================================================================
:step7
echo.
echo  [Step 7/9] Compile ObjMem Library ^(Optional^)
echo  ----------------------------------------------------------------------------

set "MAKEOBJMEM=!OBJASM_PATH!\Code\ObjMem\MakeObjMem3264.cmd"
if not exist "!MAKEOBJMEM!" goto :step7_not_found

echo   Build script found: !MAKEOBJMEM!
echo.
choice /c YN /m "  Compile the ObjMem library (32-bit and 64-bit)"
if !errorlevel!==2 goto :step7_skip
echo.
echo   Compiling ObjMem library...
call "!MAKEOBJMEM!"
if errorlevel 1 (
  echo   [WARN] ObjMem compilation reported errors.
) else (
  echo   [OK]   ObjMem library compiled successfully.
)
goto :step8

:step7_not_found
echo   [SKIP] MakeObjMem3264.cmd not found.
goto :step8

:step7_skip
echo   Skipped.

REM ============================================================================
REM STEP 8: (Optional) Compile Objects
REM ============================================================================
:step8
echo.
echo  [Step 8/9] Compile Objects ^(Optional^)
echo  ----------------------------------------------------------------------------

set "MAKEOBJECTS=!OBJASM_PATH!\Code\Objects\Build\MakeObjects3264AW.cmd"
if not exist "!MAKEOBJECTS!" goto :step8_not_found

echo   Build script found: !MAKEOBJECTS!
echo.
choice /c YN /m "  Compile all Objects (32/64-bit, ANSI/Wide)"
if !errorlevel!==2 goto :step8_skip
echo.
echo   Compiling Objects...
call "!MAKEOBJECTS!"
if errorlevel 1 (
  echo   [WARN] Object compilation reported errors.
) else (
  echo   [OK]   Objects compiled successfully.
)
goto :step9

:step8_not_found
echo   [SKIP] MakeObjects3264AW.cmd not found.
goto :step9

:step8_skip
echo   Skipped.

REM ============================================================================
REM STEP 9: (Optional) Compile Examples and Projects
REM ============================================================================
:step9
echo.
echo  [Step 9/9] Compile Examples and Projects ^(Optional^)
echo  ----------------------------------------------------------------------------

set "MAKEEXAMPLES=!OBJASM_PATH!\Examples\MakeAll.cmd"
set "MAKEPROJECTS=!OBJASM_PATH!\Projects\MakeAll.cmd"

set "HAS_EXAMPLES=0"
set "HAS_PROJECTS=0"
if exist "!MAKEEXAMPLES!" set "HAS_EXAMPLES=1"
if exist "!MAKEPROJECTS!" set "HAS_PROJECTS=1"

if "!HAS_EXAMPLES!"=="1" echo   Examples build script found: !MAKEEXAMPLES!
if "!HAS_PROJECTS!"=="1" echo   Projects build script found: !MAKEPROJECTS!

if "!HAS_EXAMPLES!"=="0" if "!HAS_PROJECTS!"=="0" (
  echo   [SKIP] No MakeAll.cmd scripts found.
  goto :install_done
)

echo.
choice /c YN /m "  Compile Examples and Projects"
if !errorlevel!==2 goto :step9_skip

if "!HAS_EXAMPLES!"=="1" (
  echo.
  echo   Compiling Examples...
  call "!MAKEEXAMPLES!"
  if errorlevel 1 (
    echo   [WARN] Examples compilation reported errors.
  ) else (
    echo   [OK]   Examples compiled successfully.
  )
)
if "!HAS_PROJECTS!"=="1" (
  echo.
  echo   Compiling Projects...
  call "!MAKEPROJECTS!"
  if errorlevel 1 (
    echo   [WARN] Projects compilation reported errors.
  ) else (
    echo   [OK]   Projects compiled successfully.
  )
)
goto :install_done

:step9_skip
echo   Skipped.

REM ============================================================================
REM Installation Complete
REM ============================================================================
:install_done
echo.
echo  ============================================================================
echo   Installation Complete!
echo  ============================================================================
echo.
echo   OBJASM_PATH = !OBJASM_PATH!
echo.
echo   The environment variable is available immediately to new processes.
echo.
echo   Run OA_SET.cmd before building any ObjAsm project:
echo     call "!OBJASM_PATH!\Build\OA_SET.cmd"
echo.
echo  ============================================================================
echo.

endlocal
exit /b 0

:abort
echo.
echo  Installation aborted.
endlocal
exit /b 1
