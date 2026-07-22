if exist !ProjectName!.asm (
  REM --- Assembler version ---
  set "Assembler_VER="
  if exist !Assembler! (
    set "ASM_UNQ=!Assembler!"
    set "ASM_UNQ=!ASM_UNQ:"=!"
    for /f "tokens=2 delims= " %%v in ('""!ASM_UNQ!" 2^>&1"') do if not defined Assembler_VER set "Assembler_VER=%%v"
    if defined Assembler_VER set "Assembler_VER=!Assembler_VER:,=!"
  )

  echo Assembling !ProjectName!.asm project ... ^(UASM !Assembler_VER!^)
  if [!LogFile!] == [] (
    if exist !Assembler! (
      call !Assembler! @"%OBJASM_PATH%\Build\Options\OPT_ASM_!TARGET_MODE!_!TARGET_BITNESS!.txt" !ProjectName!.asm
    ) else (
      echo [93;101mERROR: Assembler not found[0m
      exit /b 1
    )
  ) else (
    if exist !Assembler! (
      echo Assembling !ProjectName!.asm project ... ^(UASM !Assembler_VER!^)>> !LogFile!
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
