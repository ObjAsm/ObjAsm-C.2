if exist !ProjectName!.dll (
  echo Converting DLL to EFI image...
  echo Converting DLL to EFI image...>> !LogFile!

  if [!LogFile!] == [] (
    if exist !EfiImageConverter! (
      !EfiImageConverter! app !ProjectName!.dll !ProjectName!.efi
    ) else (
      echo [93;101mERROR: EFI Image Converter not found[0m
      exit /b 1
    )
  ) else (
    if exist !EfiImageConverter! (
      !EfiImageConverter! app !ProjectName!.dll !ProjectName!.efi>> !LogFile!
    ) else (
      echo ERROR: EFI Image Converter not found>> !LogFile!
      exit /b 1
    )
  )
)
