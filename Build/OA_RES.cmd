if exist !ProjectName!.rc (
  REM --- Resource Compiler version ---
  set "ResourceCompiler_VER="
  if exist "!ResourceCompiler!" (
    set "RC_UNQ=!ResourceCompiler!"
    set "RC_UNQ=!RC_UNQ:"=!"
    for /f "delims=" %%L in ('"!RC_UNQ!" /? 2^>^&1') do (
      if not defined ResourceCompiler_VER (
        set "RC_LINE=%%L"
        if "!RC_LINE!" neq "!RC_LINE:Version=!" (
          set "ResourceCompiler_VER=!RC_LINE:*Version =!"
          set "ResourceCompiler_VER=!ResourceCompiler_VER:~0,-1!"
        )
      )
    )
  )

  echo Compiling !ProjectName!.rc resources ... ^(RC !ResourceCompiler_VER!^)

  if [!LogFile!] == [] (
    if exist !ResourceCompiler! (
      call !ResourceCompiler! /nologo /v /r /x /w /i"%OBJASM_PATH%\Resources" !ProjectName!.rc
      if errorlevel 1 exit /b 1
    ) else (
      echo [93;101mERROR: Resource Compiler not found[0m
      exit /b 1
    )
  ) else (
    if exist !ResourceCompiler! (
      echo Compiling !ProjectName!.rc resources ... ^(RC !ResourceCompiler_VER!^)>> !LogFile!
      call !ResourceCompiler! /nologo /v /r /x /w /i"%OBJASM_PATH%\Resources" !ProjectName!.rc >> !LogFile!
      if errorlevel 1 (echo.>> !LogFile! & exit /b 1)
      echo.>> !LogFile!
    ) else (
      echo ERROR: Resource Compiler not found>> !LogFile!
      exit /b 1
    )
  )
)
