@echo off

if exist ResLeak.obj del ResLeak.obj
if exist ResLeak.exe del ResLeak.exe

\MASM32\BIN\Ml.exe /c /coff ResLeak.asm
if errorlevel 1 goto errasm

\MASM32\BIN\Link.exe  /NOLOGO /MACHINE:X86 /SUBSYSTEM:WINDOWS /DEBUG /DEBUGTYPE:CV ResLeak.obj
if errorlevel 1 goto errlink

dir ResLeak.*
goto TheEnd

:errlink
echo _
echo Link error
goto TheEnd

:errasm
echo _
echo Assembly Error
goto TheEnd

:TheEnd

pause

