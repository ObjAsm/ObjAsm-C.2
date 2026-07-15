@echo off

if exist ResLeak.exe del ResLeak.exe
if exist ResLeak.obj del ResLeak.obj
if exist ResLeak.ilk del ResLeak.ilk
if exist ResLeak.pdb del ResLeak.pdb

"%MASM32_PATH%\BIN\Ml.exe" /c /coff "%OBJASM_PATH%\Projects\X\ResGuard\MASM_Leak\ResLeak.asm"
if errorlevel 1 goto errasm

echo "%OBJASM_PATH%\Build\Tools\Linker\link.exe" /NOLOGO /MACHINE:X86 /SUBSYSTEM:WINDOWS /DEBUG /DEBUGTYPE:CV "%OBJASM_PATH%\Projects\X\ResGuard\MASM_Leak\ResLeak.obj"
"C:\Users\FRGE\OneDrive - V-ZUG AG\_MySoftware_\ObjAsm\\Build\Tools\Linker\link.exe" /NOLOGO /MACHINE:X86 /SUBSYSTEM:WINDOWS /DEBUG /DEBUGTYPE:CV "C:\Users\FRGE\OneDrive - V-ZUG AG\_MySoftware_\ObjAsm\\Projects\X\ResGuard\MASM_Leak\ResLeak.obj"
rem "%MASM32_PATH%\BIN\Link.exe"             /NOLOGO /MACHINE:X86 /SUBSYSTEM:WINDOWS /DEBUG /DEBUGTYPE:CV "%OBJASM_PATH%\Projects\X\ResGuard\MASM_Leak\ResLeak.obj"
if errorlevel 1 goto errlink

dir ResLeak.*
goto TheEnd

:errlink
echo.
echo Link error
goto TheEnd

:errasm
echo.
echo Assembly Error
goto TheEnd

:TheEnd

pause

