if exist !ProjectName!.xml (
  echo Compiling UI resources ...
  echo Compiling UI resources ...>> !LogFile!

  if [!LogFile!] == [] (
    if exist !UICCompiler! (
      !UICCompiler! !ProjectName!.xml /header:!ProjectName!.h /res:!ProjectName!.rib
      if errorlevel 1 exit /b 1
    ) else (
      echo [93;101mERROR: UIC Compiler not found[0m
      exit /b 1
    )
  ) else (
    if exist !UICCompiler! (
      !UICCompiler! !ProjectName!.xml /header:!ProjectName!.h /res:!ProjectName!.rib>> !LogFile!
      if errorlevel 1 (echo.>> !LogFile! & exit /b 1)
    ) else (
      echo ERROR: UIC Compiler not found>> !LogFile!
      exit /b 1
    )
  )
)
