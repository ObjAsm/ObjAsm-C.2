; ==================================================================================================
; Title:      StrAlloc_TX_UEFI.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, June 2022
;               - First release.
;               - Character and bitness neutral code.
; ==================================================================================================


; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  StrAllocA_UEFI / StrAllocW_UEFI 
; Purpose:    Allocate space for a string with n characters.
; Arguments:  Arg1: Character count without the ZTC.
; Return:     rax -> New allocated string or NULL if failed.

.code
align ALIGN_CODE
ProcName proc dChars:DWORD
  local pBuffer:POINTER

  ?mov ecx, dChars
  lea edx, [sizeof(CHR)*ecx + sizeof(CHR)]              ;Make room for the ZTC
  if TARGET_BITNESS eq 64
    mov r9, pBootServices
    invoke [r9].EFI_BOOT_SERVICES.AllocatePool, EFI_MEMORY_UC, edx, addr pBuffer  ;Not cacheable
  else
    mov ecx, pBootServices
    invoke [ecx].EFI_BOOT_SERVICES.AllocatePool, EFI_MEMORY_UC, edx, addr pBuffer ;Not cacheable
  endif
  .if xax == EFI_SUCCESS 
    mov xax, pBuffer
    m2z CHR ptr [xax]                                   ;Set the ZTC
  .else
    xor eax, eax
  .endif 
  ret
ProcName endp

