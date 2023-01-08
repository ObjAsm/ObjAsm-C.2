
call %OBJASM_PATH%\Build\OA_SET.cmd

call %Assembler% @"%OBJASM_PATH%\Build\Options\OPT_ASM_LIB_!TARGET_BITNESS!.txt" "%OBJASM_PATH%\Code\Objects\%1.asm"
if exist *.err (
  echo. --- Error compiling source file ---
  echo. --- Press any key to continue ---
  pause > nul
) else (
  REM Create the .lib file
  call %LibraryCompiler% @"%OBJASM_PATH%\Build\Options\OPT_LIB_%TARGET_MODE%_%TARGET_BITNESS%.txt" %1.obj /OUT:"%TARGET_FOLDER%\%1.lib"
  if not exist "%TARGET_FOLDER%\%1.lib" (
    echo. --- Error building the lib file ---
    echo. --- Press any key to continue ---
    pause > nul
  ) else (
    if exist *.obj del *.obj
  )
)
