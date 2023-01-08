if exist !ProjectName!.rc (
  echo Compiling !ProjectName!.rc resources ...

  if [!LogFile!] == [] (
    if exist !ResourceCompiler! (
      call !ResourceCompiler! /nologo /v /r /x /w /i"%OBJASM_PATH%\Resources" !ProjectName!.rc
    ) else (
      echo [93;101mERROR: Resource Compiler not found[0m
      exit /b 1
    )
  ) else (
    if exist !ResourceCompiler! (
      echo Compiling !ProjectName!.rc resources ...>> !LogFile!
      call !ResourceCompiler! /nologo /v /r /x /w /i"%OBJASM_PATH%\Resources" !ProjectName!.rc >> !LogFile!
      echo.>> !LogFile!
    ) else (
      echo ERROR: Resource Compiler not found>> !LogFile!
      exit /b 1
    )
  )
)
