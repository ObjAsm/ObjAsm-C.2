@echo off

@echo Project: ResGuard

if exist ResGuard.dll del ResGuard.dll
if exist ResGuard.obj del ResGuard.obj

@echo Compiling resources...
%MASM32_PATH%\BIN\RC.EXE /v /i %OA32_PATH%\Resources /i %OA32_PATH%\Resources\Dialogs ResGuard.rc > Make.txt
if errorlevel 1 goto Error

@echo Making resource object file...
%MASM32_PATH%\BIN\CVTRES.EXE /nologo /machine:ix86 ResGuard.res /out:ResGuard.rco >> Make.txt
if errorlevel 1 goto Error

@echo Assembling...
%MASM32_PATH%\BIN\Ml.exe /c /coff /Cp /nologo ResGuard.asm >> Make.txt
if errorlevel 1 goto Error
del Make.txt

echo Linking...
%MASM32_PATH%\BIN\LINK.EXE /out:ResGuard.dll /nologo /SUBSYSTEM:WINDOWS /DLL /DEF:ResGuard.def ResGuard.obj ResGuard.rco
if errorlevel 1 goto Error

copy ResGuard.inc %MASM32_PATH%\Include\ResGuard.inc
copy ResGuard.lib %MASM32_PATH%\Lib\ResGuard.lib
copy ResGuard.dll %windir%\SYSTEM32\ResGuard.dll
goto TheEnd

:Error
echo.
echo ***************************
echo ********** ERROR **********
echo ***************************

:TheEnd


