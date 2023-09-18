@echo off
REM Usage: BuildInfo InfoFile Token=Value ...
REM Increments, decrements, sets or replaces a token value declared in the InfoFile.
REM Tokens that are not found in the info file are added to the end of the file.
REM Declarations have to follow this syntax:
REM   Token textequ <Value>
REM   Token equ     Value
REM   Token =       Value

setlocal ENABLEEXTENSIONS ENABLEDELAYEDEXPANSION

echo BuildInfo is processing %1 ...
if not [!LogFile!] == [] (
  echo BuildInfo is processing %1 ...>> !LogFile!
)

set ArgCount=1
for %%* in (%*) do set /a ArgCount+=1
set /a ArgCount=!ArgCount!/2-1
set /a ArgBound=!ArgCount!-1

if [%~1]==[] (
  echo BuildInfo error: missing file argument
) else (
  set "spaces=                              "
  set SrcFile=%~1
  set DstFile=~Info~.txt
  set LineCount=0

  if exist !DstFile! del !DstFile!

  shift /1
  for /l %%X in (0, 1, !ArgBound!) do (
    call set Token[%%X]=%%1
    call set Value[%%X]=%%2
    shift & shift
  )

  for /f "tokens=1* delims=]" %%A in ('type "!SrcFile!" ^| find /V /N ""') do (
    set /a Linecount+=1
    if [%%B]==[] (
      echo.>> !DstFile!
    ) else (
      for /f "tokens=1,2,* eol=§" %%X in ("%%B") do (
        set NewVal=%%Z
        for /l %%K in (0, 1, !ArgBound!) do (
          if %%X == !Token[%%K]! (
            if !Value[%%K]! == + (
              set /a NewVal=%%Z+1
            ) else (
              if !Value[%%K]! == - (
                set /a NewVal=%%Z-1
              ) else (
                set FirstChar=!Value[%%K]:~0,1!
                if !FirstChar! == ^" (
                  for /f "delims=" %%Q in ('echo %%!Value[%%K]%%') do set NewVal=^<%%~Q^>
                ) else (
                  set NewVal=!Value[%%K]!
                )
              )
            )
            set Token[%%K]=
            set /a Argcount-=1
          )
        )

        if "%%Y" == "equ" (
          call :EmitLineF "%%X" "%%Y" "!NewVal!"
        ) else (
          if "%%Y" == "textequ" (
            call :EmitLineF "%%X" "%%Y" "!NewVal!"
          ) else (
            if "%%Y" == "=" (
              call :EmitLineF "%%X" "%%Y" "!NewVal!"
            ) else (
              echo %%B>> !DstFile!
            )
          )
        )

      )
    )
  )

  if !LineCount! == 0 (
    if exist !DstFile! del !DstFile!
    echo BuildInfo failed processing %1 ...
    exit /b 1
  ) else (

    if not !ArgCount! == 0 echo.>> !DstFile!

    for /l %%X in (0, 1, !ArgBound!) do (
      if not [!Token[%%X]!] == [] (
        set FirstChar=!Value[%%X]:~0,1!
        if !FirstChar! == ^" (
          for /f "delims=" %%Q in ('echo %%!Value[%%X]%%') do set NewVal=^<%%~Q^>
          call :EmitLineF "!Token[%%X]!" "textequ" "!NewVal!"
        ) else (
          if !FirstChar! == + (
            call :EmitLineF "!Token[%%X]!" "equ" "0"
          ) else (
            if !FirstChar! == - (
              call :EmitLineF "!Token[%%X]!" "equ" "0"
            ) else (
              call :EmitLineF "!Token[%%X]!" "equ" "!Value[%%X]!"
            )
          )
        )
      )
    )
    del !SrcFile!
    ren !DstFile! !SrcFile!
  )
)
goto :EOF

:EmitLineF
set "line=%~1!spaces!"
set "line=!line:~0,30!%~2!spaces!"
set "line=!line:~0,40!%~3"
echo !line!>> !DstFile!
goto :EOF
