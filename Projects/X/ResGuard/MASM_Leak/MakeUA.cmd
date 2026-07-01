@echo off

if exist ResLeak.exe del ResLeak.exe
if exist ResLeak.obj del ResLeak.obj
if exist ResLeak.ilk del ResLeak.ilk
if exist ResLeak.pdb del ResLeak.pdb

"%OBJASM_PATH%\Build\Tools\uasm64.exe" /c /coff "%OBJASM_PATH%\Projects\X\ResGuard\MASM_Leak\ResLeak.asm"
if errorlevel 1 goto errasm

"%OBJASM_PATH%\Build\Tools\Linker\link.exe" /NOLOGO /MACHINE:X86 /SUBSYSTEM:WINDOWS /DEBUG /DEBUGTYPE:CV "%OBJASM_PATH%\Projects\X\ResGuard\MASM_Leak\ResLeak.obj"
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

