REM Cleanup unnecessary files. Set file attribeute = write protected to keep them.
if exist !ProjectName!.exe del !ProjectName!.exe
if exist !ProjectName!.dll del !ProjectName!.dll
if exist !ProjectName!.ocx del !ProjectName!.ocx
if exist !ProjectName!.res del !ProjectName!.res
if exist !ProjectName!.rco del !ProjectName!.rco
if exist !ProjectName!.obj del !ProjectName!.obj
if exist !ProjectName!.pdb del !ProjectName!.pdb
if exist !ProjectName!.ilk del !ProjectName!.ilk
if exist !ProjectName!.exp del !ProjectName!.exp
if exist *.err del *.err
if exist *.tmp del *.tmp
if exist RC??????. del RC??????.

if exist !ProjectName!_Shared.inc (
  call !BldInf! !ProjectName!_Shared.inc BUILD_NUMBER=+ BUILD_DATE_STR="%Date%" BUILD_BITNESS=!TARGET_BITNESS! BUILD_MODE=!TARGET_MODE! BUILD_BIN_FORMAT=!TARGET_BIN_FORMAT! BUILD_BIN_SUFFIX_STR="!TARGET_SUFFIX_STR!"
  if errorlevel 1 exit /b 1
  call !Inc2RC! !ProjectName!_Shared.inc !ProjectName!_Shared.rc
  if errorlevel 1 exit /b 1
)

if not [!LogFile!] == [] (
  echo.>> !LogFile!
)
