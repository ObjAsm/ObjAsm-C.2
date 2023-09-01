if exist %ProjectName%.obj (
  echo Linking object modules to !TARGET_BIN_FORMAT!-file ...
  if not [!LogFile!] == [] (
    echo Linking object modules to !TARGET_BIN_FORMAT!-file ...>> !LogFile!
  )

  if !TARGET_BIN_FORMAT! == DLL set OptDLL=/DLL /DEF:!ProjectName!.def
  
  if !TARGET_BIN_FORMAT! == DLL (
    set Extension=dll
  ) else (
    set Extension=exe
  )
  
  if exist !ProjectName!.res set AuxRes=!ProjectName!.res

  if [!LogFile!] == [] (
    if exist !Linker! (
      call !Linker! @"%OBJASM_PATH%\Build\Options\OPT_LNK_!TARGET_MODE!_!TARGET_BITNESS!.txt" !OptDLL! !ProjectName!.obj !AuxRes! /OUT:!ProjectName!!TARGET_SUFFIX!.!Extension!
    ) else (
      echo [93;101mERROR: Linker not found[0m
      exit /b 1
    )
  ) else (
    if exist !Linker! (
      call !Linker! @"%OBJASM_PATH%\Build\Options\OPT_LNK_!TARGET_MODE!_!TARGET_BITNESS!.txt" !OptDLL! !ProjectName!.obj !AuxRes! /OUT:!ProjectName!!TARGET_SUFFIX!.!Extension!>> !LogFile!
      echo.>> !LogFile!
    ) else (
      echo ERROR: Linker not found>> !LogFile!
      exit /b 1
    )
  )
)
