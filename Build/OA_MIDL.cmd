if exist !ProjectName!.idl (
  echo Compiling Type Library ...

  if exist !ProjectName!.tlb del !ProjectName!.tlb
  if [!LogFile!] == [] (
    if exist !MidlCompiler! (
      call !MidlCompiler! /I %OBJASM_PATH%\Code\Inc\COM\IDL @"%OBJASM_PATH%\Build\Options\OPT_MIDL_!TARGET_BITNESS!.txt" !ProjectName!.idl
    ) else (
      echo [93;101mERROR: MidlCompiler not found[0m
      exit /b 1
    )
  ) else (
    if exist !MidlCompiler! (
      echo Compiling Type Library ...>> !LogFile!
      call !MidlCompiler! /I %OBJASM_PATH%\Code\Inc\COM\IDL @"%OBJASM_PATH%\Build\Options\OPT_MIDL_!TARGET_BITNESS!.txt" !ProjectName!.idl>> !LogFile!
      echo.>> !LogFile!
    ) else (
      echo ERROR: MidlCompiler not found>> !LogFile!
      exit /b 1
    )
  )
)
