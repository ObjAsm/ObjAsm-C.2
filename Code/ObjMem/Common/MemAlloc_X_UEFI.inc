; ==================================================================================================
; Title:      MemAlloc_X_UEFI.inc
; Author:     HSE, G. Friedrich
; Version:    C.1.1
; Notes:      Version C.1.1, September 2022
;               - Arg3 = Memory type added by HSE.
;             Version C.1.0, June 2022
;               - First release.
; ==================================================================================================


; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  MemAlloc_UEFI
; Purpose:    Allocate a memory block.
; Arguments:  Arg1: Memory block attributes [0, MEM_INIT_ZERO].
;             Arg2: Memory block size in BYTEs.
;             Arg3: Memory type.
; Return:     xax -> Memory block or NULL if failed.

.code
align ALIGN_CODE
MemAlloc_UEFI proc uses xbx dAttr:DWORD, dMemSize:DWORD, dType:DWORD
  local pMemBlock:POINTER

  mov xbx, pBootServices
  invoke [xbx].EFI_BOOT_SERVICES.AllocatePool, dType, dMemSize, addr pMemBlock
  mov xcx, EFI_ERROR
  .ifBitSet xax, xcx
    xor eax, eax
  .else
    .ifBitSet dAttr, MEM_INIT_ZERO
      invoke MemZero, pMemBlock, dMemSize
    .endif
    mov xax, pMemBlock
  .endif
  ret
MemAlloc_UEFI endp
