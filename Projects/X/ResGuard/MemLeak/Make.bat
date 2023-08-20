@echo off
Set FileName=MemLeak

@echo Project: %FileName%

if exist %FileName%.exe del %FileName%.exe
if exist %FileName%.obj del %FileName%.obj

@echo Compiling resources...
%MASM32_PATH%\BIN\RC.EXE /v /i %OA32_PATH%\Resources /i %OA32_PATH%\Resources\Dialogs %FileName%.rc > Make.txt
if errorlevel 1 goto Error

@echo Making resource object file...
%MASM32_PATH%\BIN\CVTRES.EXE /nologo /machine:ix86 %FileName%.res /out:%FileName%.rco > Make.txt
if errorlevel 1 goto Error

@echo Assembling project...
%MASM32_PATH%\BIN\Ml.exe  /Zd /Zi /c /coff /nologo %FileName%.asm >> Make.txt
if errorlevel 1 goto Error

@echo Linking object modules...
%MASM32_PATH%\BIN\Link.exe  /SUBSYSTEM:WINDOWS /DEBUG /DEBUGTYPE:CV /VERSION:4.0 %FileName%.obj %FileName%.rco >> Make.txt
if errorlevel 1 goto Error
del Make.txt
@echo Ready!
goto TheEnd

:Error
echo.
echo ***************************
echo ********** ERROR **********
echo ***************************

:TheEnd


