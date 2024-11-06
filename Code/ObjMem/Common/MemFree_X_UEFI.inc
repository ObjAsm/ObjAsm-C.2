; ==================================================================================================
; Title:      MemFree_X_UEFI.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, June 2022
;               - First release.
; ==================================================================================================


; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  MemFree_UEFI
; Purpose:    Dispose a memory block.
; Arguments:  Arg1: -> Memory block.
; Return:     xax = EFI_SUCCESS or an UEFI error code.

.code
align ALIGN_CODE
MemFree_UEFI proc pMemBlock:POINTER
  mov xax, pBootServices
  invoke [xax].EFI_BOOT_SERVICES.FreePool, pMemBlock
  ret 
MemFree_UEFI endp
