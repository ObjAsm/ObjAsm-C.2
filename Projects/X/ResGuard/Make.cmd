@echo off
REM Start build process of the ResGuard DLL

setlocal ENABLEEXTENSIONS ENABLEDELAYEDEXPANSION

set TARGET_BITNESS=64

if exist "%OBJASM_PATH%" (
  if exist *.asm (
    REM Set ProjectName to the name of the .asm file on the current directory
    for %%* in (*.asm) do set ProjectName=%%~n*
    set LogFile=Make.log

    REM Dispaly some information
    echo [96mBuilding !ProjectName! project ...[0m
    echo Building !ProjectName! project ...>!LogFile!
    echo.
    echo.>>!LogFile!

    REM Set build targets.
    call "%OBJASM_PATH%\Build\OA_TARGET.cmd" %*
    if errorlevel 1 goto Error

    REM Display targets on screen
    echo.  Platform:       [93m!TARGET_PLATFORM![0m
    echo.  User Interface: [93m!TARGET_USER_INTERFACE![0m
    echo.  Binary Format:  [93m!TARGET_BIN_FORMAT![0m
    echo.  Bitness:        [93m!TARGET_BITNESS![0m
    echo.  OOP support:    [93m!TARGET_SUPPORT_OOP![0m
    echo.  String Type:    [93m!TARGET_STRING_TYPE![0m
    echo.  Mode:           [93m!TARGET_MODE_STR![0m
    echo.

    REM Set known tools.
    call "%OBJASM_PATH%\Build\OA_SET.cmd" %*
    if errorlevel 1 goto Error

    REM Prepare for build
    call "%OBJASM_PATH%\Build\OA_PRE.cmd" %*
    if errorlevel 1 goto Error

    REM Compile type libraries
    call "%OBJASM_PATH%\Build\OA_MIDL.cmd" %*
    if errorlevel 1 goto Error

    REM Compile resources
    call "%OBJASM_PATH%\Build\OA_RES.cmd" %*
    if errorlevel 1 goto Error

    REM Assemble project
    call "%OBJASM_PATH%\Build\OA_ASM.cmd" %*
    if errorlevel 1 goto Error

    REM Link project
    call "%OBJASM_PATH%\Build\OA_LINK.cmd" %*
    if errorlevel 1 goto Error

    REM Housekeeping
    call "%OBJASM_PATH%\Build\OA_POS.cmd" %*
    if errorlevel 1 goto :EOF

    @Echo Installing !TARGET_BITNESS!-bit version...
    copy ResGuard.inc "%OBJASM_PATH%\Code\Inc\ObjAsm\ResGuard.inc">>!LogFile!
    if !TARGET_BITNESS! == 32 (
      copy ResGuard32.lib "%OBJASM_PATH%\Code\Lib\32\ObjAsm\ResGuard32.lib">>!LogFile!
      copy ResGuard32.dll %windir%\SYSTEM32\ResGuard32.dll>>!LogFile!
      copy ResGuard32.dll "%OBJASM_PATH%\Projects\X\ResGuard\LeakTest1\ResGuard32.dll">>!LogFile!
    ) else (
      copy ResGuard64.lib "%OBJASM_PATH%\Code\Lib\64\ObjAsm\ResGuard64.lib">>!LogFile!
      copy ResGuard64.dll %windir%\SYSTEM32\ResGuard64.dll>>!LogFile!
      copy ResGuard64.dll "%OBJASM_PATH%\Projects\X\ResGuard\LeakTest1\ResGuard64.dll">>!LogFile!
    )
    goto :EOF

    :Error
    call "%OBJASM_PATH%\Build\OA_ERROR.cmd" %*
    goto :EOF
  
  ) else (
    echo No project file found^^!
    if not [!LogFile!] == [] (
      echo No project file found^^!>!LogFile!
    )
    call "%OBJASM_PATH%\Build\OA_ERROR.cmd" %*
  )

) else (
  echo Wrong path to ObjAsm. Check your OBJASM_PATH environment variable.
  if not "%1" equ "NOPAUSE" pause
  exit /b 1
)
