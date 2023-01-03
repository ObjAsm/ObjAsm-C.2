REM setlocal ENABLEEXTENSIONS ENABLEDELAYEDEXPANSION

REM Usual path: OBJASM_PATH="C:\ObjAsm"
REM It is stored in the registry:
REM   - HKEY_CURRENT_USER\Environment
REM   - HKEY_LOCAL_MACHINE\SYSTEM\CurrentControlSet\Control\Session Manager\Environment

"%SystemRoot%\system32\reg.exe" Query "HKLM\Hardware\Description\System\CentralProcessor\0" | "%SystemRoot%\system32\find.exe" /i "x86" > NUL && set SYSTEM_BITNESS=32 || set SYSTEM_BITNESS=64
set Linker="%OBJASM_PATH%\Build\Tools\Linker\link.exe"
set LibraryCompiler="%MSVS_PATH%\lib.exe"
set BldInf="%OBJASM_PATH%\Build\Tools\BuildInfo.cmd"
set Inc2RC="%OBJASM_PATH%\Build\Tools\Inc2RC.cmd"
set MidlCompiler="%WINKIT_PATH%\x64\midl.exe"
set UICCompiler="%WINKIT_PATH%\x86\UICC.exe"
set ResourceCompiler="%OBJASM_PATH%\Build\Tools\ResourceCompiler\rc.exe"
set EfiImageConverter="%EFI_TOOLKIT_PATH%\build\tools\bin\fwimage"
REM set Debugger="%MSVS_PATH%\..\..\..\..\..\..\..\Common7\IDE\devenv.exe"
set Debugger="C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\Common7\IDE\devenv.exe"
if %SYSTEM_BITNESS%==32 (
  set Assembler="%OBJASM_PATH%\Build\Tools\Assembler\UASM32.exe"
) else (
  set Assembler="%OBJASM_PATH%\Build\Tools\Assembler\UASM64.exe"
)

exit /b 0