; ==================================================================================================
; Title:      MemReAlloc_X_UEFI.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, June 2022
;               - First release.
; ==================================================================================================


; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  MemReAlloc_UEFI
; Purpose:    Shrink or expand a memory block.
; Arguments:  Arg1: -> Memory block
;             Arg2: Memory block size in BYTEs.
;             Arg3: New memory block size in BYTEs.
;             Arg4: Memory block attributes [0, MEM_INIT_ZERO].
; Return:     xax -> New memory block.

.code
align ALIGN_CODE
MemReAlloc_UEFI proc uses xbx pMemBlock:POINTER, dMemSize:DWORD, dNewMemSize:DWORD, dAttr:DWORD
  local pNewMemBlock:POINTER

  mov eax, dNewMemSize
  .if eax != dMemSize
    mov xbx, pBootServices
    invoke [xbx].EFI_BOOT_SERVICES.AllocatePool, EFI_MEMORY_TYPE_EfiBootServicesData, \
                                                 dNewMemSize, addr pNewMemBlock
    mov xcx, EFI_ERROR
    .ifBitSet xax, xcx
      xor eax, eax
    .else
      mov eax, dMemSize
      .if eax < dNewMemSize
        invoke MemClone, pNewMemBlock, pMemBlock, eax
        .ifBitSet dAttr, MEM_INIT_ZERO
          mov ecx, dNewMemSize
          add xcx, pNewMemBlock
          mov edx, dNewMemSize
          sub edx, dMemSize
          invoke MemZero, xcx, edx
        .endif
      .else
        invoke MemClone, pNewMemBlock, pMemBlock, dNewMemSize
      .endif
      mov xax, pNewMemBlock
    .endif
  .else
    mov xax, pMemBlock
  .endif
  ret 
MemReAlloc_UEFI endp
