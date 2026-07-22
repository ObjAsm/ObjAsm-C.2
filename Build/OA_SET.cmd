REM ============================================================================
REM OA_SET.cmd - ObjAsm Build Environment Setup
REM ============================================================================
REM
REM This script dynamically detects the installed Visual Studio and Windows SDK
REM paths so that you do NOT need to manually look up or hardcode version-specific
REM directories.
REM
REM How it works:
REM   1. Detects system bitness (32/64) via the processor registry key.
REM   2. Uses vswhere.exe (shipped with VS 2017 15.2+) to locate the latest
REM      Visual Studio installation. From that path it derives:
REM        - devenv.exe (Debugger)
REM        - lib.exe    (Library Compiler)
REM      It picks the newest MSVC toolset found under VC\Tools\MSVC.
REM   3. Reads the Windows 10/11 SDK installation folder and version from the
REM      registry (WOW6432Node path) to set WINKIT_PATH dynamically.
REM   4. ObjAsm-specific tools (Assembler, Linker, ResourceCompiler, etc.) are
REM      resolved relative to OBJASM_PATH, which must be set as an environment
REM      variable before calling this script.
REM
REM Requirements:
REM   - OBJASM_PATH environment variable must be set (e.g. C:\ObjAsm)
REM   - Visual Studio 2017 or later must be installed
REM   - Windows SDK 10+ must be installed
REM   - (Optional) EFI_TOOLKIT_PATH for UEFI development
REM
REM ============================================================================

REM --- Detect system bitness ---
"%SystemRoot%\system32\reg.exe" Query "HKLM\Hardware\Description\System\CentralProcessor\0" | "%SystemRoot%\system32\find.exe" /i "x86" > NUL && set SYSTEM_BITNESS=32 || set SYSTEM_BITNESS=64

REM --- Verify OBJASM_PATH is set ---
if not defined OBJASM_PATH (
  echo ERROR: OBJASM_PATH environment variable is not set.
  echo        Please set it to your ObjAsm installation directory, e.g. C:\ObjAsm
  exit /b 1
)

REM ============================================================================
REM Visual Studio Detection via vswhere.exe
REM vswhere.exe is guaranteed to exist at this location since VS 2017 15.2+.
REM It returns the installation path of the most recent VS instance regardless
REM of edition (Community, Professional, Enterprise) or version (2019, 2022...).
REM ============================================================================
set "VSWHERE=%ProgramFiles(x86)%\Microsoft Visual Studio\Installer\vswhere.exe"

if not exist "%VSWHERE%" (
  echo ERROR: vswhere.exe not found at "%VSWHERE%"
  echo        Is Visual Studio 2017 or later installed?
  exit /b 1
)

REM Get the latest VS installation path
for /f "usebackq tokens=*" %%i in (`"%VSWHERE%" -latest -prerelease -property installationPath`) do set "VS_PATH=%%i"

if not defined VS_PATH (
  echo ERROR: vswhere could not find a Visual Studio installation.
  exit /b 1
)

REM --- Derive the Debugger path ---
set Debugger="%VS_PATH%\Common7\IDE\devenv.exe"

REM ============================================================================
REM MSVC Toolset Detection
REM Inside the VS installation, MSVC toolsets live under VC\Tools\MSVC\<version>.
REM We pick the latest version by reverse-sorting the directory names.
REM ============================================================================
set "MSVC_VER="
for /f "tokens=*" %%v in ('dir /b /ad /o-n "%VS_PATH%\VC\Tools\MSVC" 2^>nul') do (
  if not defined MSVC_VER set "MSVC_VER=%%v"
)

if not defined MSVC_VER (
  echo ERROR: No MSVC toolset found under "%VS_PATH%\VC\Tools\MSVC"
  exit /b 1
)

set LibraryCompiler="%VS_PATH%\VC\Tools\MSVC\%MSVC_VER%\bin\Hostx64\x64\lib.exe"


REM ============================================================================
REM Windows SDK Detection via Registry
REM The Windows 10/11 SDK stores its installation path and version in:
REM   HKLM\SOFTWARE\WOW6432Node\Microsoft\Microsoft SDKs\Windows\v10.0
REM We read InstallationFolder and ProductVersion to build the full bin path.
REM ============================================================================
set "WINSDK_PATH="
set "WINSDK_VER="
set "WINSDKKEY=HKLM\SOFTWARE\WOW6432Node\Microsoft\Microsoft SDKs\Windows\v10.0"

for /f "tokens=2*" %%a in ('reg query "%WINSDKKEY%" /v InstallationFolder 2^>nul') do set "WINSDK_PATH=%%b"
for /f "tokens=2*" %%a in ('reg query "%WINSDKKEY%" /v ProductVersion 2^>nul') do set "WINSDK_VER=%%b.0"

if not defined WINSDK_PATH (
  echo WARNING: Windows SDK not found in registry. MIDL and UICC will not be available.
) else (
  set "WINKIT_PATH=%WINSDK_PATH%bin\%WINSDK_VER%"
)

REM --- Tools from Windows SDK ---
if defined WINKIT_PATH (
  set MidlCompiler="%WINKIT_PATH%\x64\midl.exe"
  set UICCompiler="%WINKIT_PATH%\x86\UICC.exe"
  set "RC_SDK=%WINKIT_PATH%\x64\rc.exe"
) else (
  set MidlCompiler=
  set UICCompiler=
  set RC_SDK=
)

REM ============================================================================
REM Linker Selection (VS linker with bundled fallback)
REM ============================================================================
REM The VS linker is selected based on host system bitness and target bitness.
REM Host bitness determines which link.exe binary runs on this machine.
REM Target bitness (32/64) determines which linker variant to use at link time.
REM Fallback: bundled linker under Build\Tools\Linker\ if VS detection fails.
REM ============================================================================
set "MSVC_BIN=%VS_PATH%\VC\Tools\MSVC\%MSVC_VER%\bin"

if %SYSTEM_BITNESS%==64 (
  set Linker32="%MSVC_BIN%\Hostx64\x86\link.exe"
  set Linker64="%MSVC_BIN%\Hostx64\x64\link.exe"
) else (
  set Linker32="%MSVC_BIN%\Hostx86\x86\link.exe"
  set Linker64="%MSVC_BIN%\Hostx86\x64\link.exe"
)

REM Verify VS linker exists, fall back to bundled linker if not
if not exist %Linker32% (
  set Linker32="%OBJASM_PATH%\Build\Tools\Linker\link.exe"
  set Linker64="%OBJASM_PATH%\Build\Tools\Linker\link.exe"
)

REM Compatible legacy linker v14.00 (VS 2015)
set Linker="%OBJASM_PATH%\Build\Tools\Linker\link.exe"

REM ============================================================================
REM Resource Compiler Selection (Windows SDK rc.exe with bundled fallback)
REM ============================================================================
REM Prefer the Microsoft Resource Compiler shipped with the Windows
REM SDK: it is kept current with the OS and supports the newest resource
REM types (manifests, DPI awareness, etc.). Fall back to the bundled copy
REM under Build\Tools\ResourceCompiler\ if the SDK isn't installed or its
REM rc.exe can't be found, mirroring the Linker fallback logic above.
REM ============================================================================
if defined RC_SDK if exist "%RC_SDK%" (
  set ResourceCompiler="%RC_SDK%"
) else (
  set ResourceCompiler="%OBJASM_PATH%\Build\Tools\ResourceCompiler\rc.exe"
)

REM ============================================================================
REM ObjAsm Tools (resolved relative to OBJASM_PATH)
REM ============================================================================
set BldInf="%OBJASM_PATH%\Build\Tools\BuildInfo.cmd"
set Inc2RC="%OBJASM_PATH%\Build\Tools\Inc2RC.cmd"

REM ============================================================================
REM EFI Toolkit (optional, only if EFI_TOOLKIT_PATH is set)
REM ============================================================================
if defined EFI_TOOLKIT_PATH (
  set EfiImageConverter="%EFI_TOOLKIT_PATH%\build\tools\bin\fwimage.exe"
) else (
  set EfiImageConverter=
)

REM ============================================================================
REM Assembler selection based on system bitness
REM ============================================================================
if %SYSTEM_BITNESS%==32 (
  set Assembler="%OBJASM_PATH%\Build\Tools\Assembler\UASM32.exe"
) else (
  set Assembler="%OBJASM_PATH%\Build\Tools\Assembler\UASM64.exe"
)

exit /b 0