@echo off

if exist ResLeak.exe del ResLeak.exe
if exist ResLeak.obj del ResLeak.obj
if exist ResLeak.ilk del ResLeak.ilk
if exist ResLeak.pdb del ResLeak.pdb

\ObjAsm\Build\Tools\uasm64.exe /c /coff ResLeak.asm
if errorlevel 1 goto errasm

\ObjAsm\Build\Tools\Linker\link.exe  /NOLOGO /MACHINE:X86 /SUBSYSTEM:WINDOWS /DEBUG /DEBUGTYPE:CV ResLeak.obj
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

