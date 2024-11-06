; ==================================================================================================
; Title:      StrDispose_TX_UEFI.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, June 2022
;               - First release.
;               - Character and bitness neutral code.
; ==================================================================================================


; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  StrDispose_UEFI
; Purpose:    Free the memory allocated for the string using StrNew_UEFI, StrCNew_UEFI, 
;             StrLENew_UEFI or StrAlloc_UEFI.
;             If the pointer to the string is NULL, StrDispose_UEFI does nothing.
; Arguments:  Arg1: -> String.
; Return:     Nothing.

.code
align ALIGN_CODE
StrDispose_UEFI proc pString:POINTER
  ?mov ecx, pString 
  .if xcx != NULL
    mov xax, pBootServices
    invoke [xax].EFI_BOOT_SERVICES.FreePool, xcx
  .endif
  ret
StrDispose_UEFI endp
