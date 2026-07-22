if exist %ProjectName%.obj (
  REM Kill stale mspdbsrv to prevent LNK1318 RPC errors
  taskkill /f /im mspdbsrv.exe >nul 2>&1
  set _MSPDBSRV_ENDPOINT_=disabled

  if exist !ProjectName!.res set AuxRes=!ProjectName!.res

  if !TARGET_BIN_FORMAT! == LIB (
    set Extension=lib

    REM --- LibraryCompiler version ---
    set "LibraryCompiler_VER="
    if exist !LibraryCompiler! (
      set "LIB_UNQ=!LibraryCompiler!"
      set "LIB_UNQ=!LIB_UNQ:"=!"
      for /f "delims=" %%L in ('""!LIB_UNQ!" 2^>&1"') do (
        if not defined LibraryCompiler_VER (
          set "LIB_LINE=%%L"
          if "!LIB_LINE!" neq "!LIB_LINE:Version=!" set "LibraryCompiler_VER=!LIB_LINE:*Version =!"
        )
      )
    )

    echo Archiving object modules to !Extension!-file ... ^(LIB !LibraryCompiler_VER!^)
    if not [!LogFile!] == [] (
      echo Archiving object modules to !Extension!-file ... ^(LIB !LibraryCompiler_VER!^)>> !LogFile!
    )

    if [!LogFile!] == [] (
      if exist !LibraryCompiler! (
        !LibraryCompiler! @"%OBJASM_PATH%\Build\Options\OPT_LIB_!TARGET_MODE!_!TARGET_BITNESS!.txt" !ProjectName!.obj !AuxRes! /OUT:!ProjectName!!TARGET_SUFFIX_STR!.!Extension!
        if errorlevel 1 exit /b 1
      ) else (
        echo [93;101mERROR: LibraryCompiler not found[0m
        exit /b 1
      )
    ) else (
      if exist !LibraryCompiler! (
        !LibraryCompiler! @"%OBJASM_PATH%\Build\Options\OPT_LIB_!TARGET_MODE!_!TARGET_BITNESS!.txt" !ProjectName!.obj !AuxRes! /OUT:!ProjectName!!TARGET_SUFFIX_STR!.!Extension!>> !LogFile!
        if errorlevel 1 (echo.>> !LogFile! & exit /b 1)
        echo.>> !LogFile!
      ) else (
        echo ERROR: LibraryCompiler not found>> !LogFile!
        exit /b 1
      )
    )

  ) else (

    REM ------------------------------------------------------------------
    REM EXE / DLL target: link with link.exe
    REM ------------------------------------------------------------------

    REM Select linker based on target bitness (VS linker with fallback)
    if "!TARGET_BITNESS!" == "64" (
      set ActiveLinker=!Linker64!
    ) else (
      set ActiveLinker=!Linker32!
    )
    REM Fall back to legacy single Linker variable if Linker32/64 not set
    REM if not defined ActiveLinker set ActiveLinker=!Linker!

    REM Due to various bugs, default to bundled linker
    set ActiveLinker=!Linker!

    REM --- Linker version ---
    set "Linker_VER="
    if exist !Linker! (
      set "LNK_UNQ=!ActiveLinker!"
      set "LNK_UNQ=!LNK_UNQ:"=!"
      for /f "delims=" %%L in ('""!LNK_UNQ!" 2^>&1"') do (
        if not defined Linker_VER (
          set "LNK_LINE=%%L"
          if "!LNK_LINE!" neq "!LNK_LINE:Version=!" set "Linker_VER=!LNK_LINE:*Version =!"
        )
      )
    )

    echo Linking object modules to !TARGET_BIN_FORMAT!-file ... ^(Linker !Linker_VER!^)
    if not [!LogFile!] == [] (
      echo Linking object modules to !TARGET_BIN_FORMAT!-file ... ^(Linker !Linker_VER!^)>> !LogFile!
    )

    if !TARGET_BIN_FORMAT! == DLL set OptDLL=/DLL /DEF:!ProjectName!.def

    set Extension=exe
    if !TARGET_BIN_FORMAT! == DLL set Extension=dll

    if !TARGET_USER_INTERFACE! == GUI (
      set Subsystem=WIN
    ) else (
      set Subsystem=CON
    )

    if [!LogFile!] == [] (
      if exist !ActiveLinker! (
        !ActiveLinker! @"%OBJASM_PATH%\Build\Options\OPT_LNK_!Subsystem!_!TARGET_MODE!_!TARGET_BITNESS!.txt" !OptDLL! !ProjectName!.obj !AuxRes! /OUT:!ProjectName!!TARGET_SUFFIX_STR!.!Extension!
        if errorlevel 1 exit /b 1
      ) else (
        echo [93;101mERROR: Linker not found[0m
        exit /b 1
      )
    ) else (
      echo !ActiveLinker! >> !LogFile!
	echo "%OBJASM_PATH%\Build\Options\OPT_LNK_!Subsystem!_!TARGET_MODE!_!TARGET_BITNESS!.txt" >> !LogFile!
	echo !OptDLL! >> !LogFile!
	echo !ProjectName!.obj >> !LogFile!
	echo !AuxRes! >> !LogFile!
	echo /OUT:!ProjectName!!TARGET_SUFFIX_STR!.!Extension! >> !LogFile!
	echo " " >> !LogFile!
      if exist !ActiveLinker! (
        !ActiveLinker! @"%OBJASM_PATH%\Build\Options\OPT_LNK_!Subsystem!_!TARGET_MODE!_!TARGET_BITNESS!.txt" !OptDLL! !ProjectName!.obj !AuxRes! /OUT:!ProjectName!!TARGET_SUFFIX_STR!.!Extension!>> !LogFile!
        if errorlevel 1 (echo.>> !LogFile! & exit /b 1)
        echo.>> !LogFile!
      ) else (
        echo ERROR: Linker not found>> !LogFile!
        exit /b 1
      )
    )
  )
)
