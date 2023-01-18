if exist !ProjectName!.asm (
  echo Assembling !ProjectName!.asm project ...
  if [!LogFile!] == [] (
    if exist !Assembler! (
      call !Assembler! @"%OBJASM_PATH%\Build\Options\OPT_ASM_!TARGET_MODE!_!TARGET_BITNESS!.txt" !ProjectName!.asm
    ) else (
      echo [93;101mERROR: Assembler not found[0m
      exit /b 1
    )
  ) else (
    if exist !Assembler! (
      echo Assembling !ProjectName!.asm project ...>> !LogFile!
      call !Assembler! @"%OBJASM_PATH%\Build\Options\OPT_ASM_!TARGET_MODE!_!TARGET_BITNESS!.txt" !ProjectName!.asm >> !LogFile!
      echo.>> !LogFile!
    ) else (
      echo ERROR: Assembler not found>> !LogFile!
      exit /b 1
    )
  )
) else (
  echo No assembler file ^(*.asm^) found^^!
  if not [!LogFile!] == [] (
    echo No assembler file ^(*.asm^) found^^!> !LogFile!
  )
  exit /b 1
)
