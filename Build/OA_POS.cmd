if !TARGET_MODE! == RLS (
  if exist !ProjectName!.res del !ProjectName!.res
  if exist !ProjectName!.rco del !ProjectName!.rco
  if exist !ProjectName!.obj del !ProjectName!.obj
  if exist !ProjectName!.pdb del !ProjectName!.pdb
  if exist !ProjectName!.ilk del !ProjectName!.ilk
  if exist !ProjectName!.exp del !ProjectName!.exp
  if exist *.err del *.err
  if exist *.tmp del *.tmp
  if exist RC??????. del RC??????.
  if exist !LogFile! del !LogFile!
  if !TARGET_PLATFORM! == UEFI (
    if exist !ProjectName!.dll del !ProjectName!.dll
  )
)

set /a SuccCounter+=1
