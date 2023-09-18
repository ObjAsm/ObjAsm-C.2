@echo off

if exist ResLeak.exe del ResLeak.exe
if exist ResLeak.obj del ResLeak.obj
if exist ResLeak.ilk del ResLeak.ilk
if exist ResLeak.pdb del ResLeak.pdb

\MASM32\BIN\Ml.exe /c /coff ResLeak.asm
if errorlevel 1 goto errasm

\MASM32\BIN\Link.exe  /NOLOGO /MACHINE:X86 /SUBSYSTEM:WINDOWS /DEBUG /DEBUGTYPE:CV ResLeak.obj
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

