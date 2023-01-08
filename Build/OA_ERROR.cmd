set /a FailCounter+=1

echo.
echo.[97;101m *************************************** [0m
echo.[97;101m **************** ERROR **************** [0m
echo.[97;101m *************************************** [0m
echo.

if not [!LogFile!] == [] (
  echo.>> !LogFile!
  echo ***************************************>> !LogFile!
  echo **************** ERROR ****************>> !LogFile!
  echo ***************************************>> !LogFile!
  echo.>> !LogFile!
)

if not [%1] == [NOPAUSE] pause
exit /b 1
