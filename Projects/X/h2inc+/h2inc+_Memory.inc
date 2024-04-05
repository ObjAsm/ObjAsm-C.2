; ==================================================================================================
; Title:    h2incX_Memory.inc
; Author:   G. Friedrich
; Version:  C.1.0
; Purpose:  h2incX memory management routines.
; Notes:    Version 1.0.0, April 2018
;             - First release.
; ==================================================================================================


; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure: MemPoolInit
; Purpose:   Reserve an commit a block of virtual memory.
; Arguments: None.
; Return:    eax -> Allocated memory or NULL if failed.

MemPoolInit proc
    invoke VirtualAlloc, NULL, MEMPOOL_MAX, MEM_RESERVE or MEM_COMMIT, PAGE_READWRITE   ;MEM_COMMIT added
    .if eax != NULL
      mov g_pMemPool, eax
      mov g_pMemPtr, eax
      mov ecx, MEMPOOL_MAX
      add ecx, eax
      mov g_pMemPoolMax, ecx
;      invoke VirtualAlloc, eax, 4*MEMPOOL_SIZE, MEM_RESERVE or MEM_COMMIT, PAGE_READWRITE
      .if eax == NULL
        xor eax, eax
      .endif
    .else
      xor eax, eax
    .endif
    ret
MemPoolInit endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure: MemPoolAlloc
; Purpose:   Allocates a memory block in the string pool.
; Arguments: Arg1: Memory block size.
; Return:    eax -> Memory buffer or NULL if failed.

MemPoolAlloc proc uses esi edi dSize:DWORD
    mov eax, g_pMemPtr
    mov ecx, dSize
    add ecx, eax
    cmp ecx, g_pMemPoolMax
    jnc @Error
    mov g_pMemPtr, ecx
    ret
@Error:
    xor eax, eax
    ret
MemPoolAlloc endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure: MemPoolAddString
; Purpose:   Add string to string pool. Each string has a DWORD value associated with it,
;            which is stored behind the ZTC.
; Arguments: Arg1: -> String.
;            Arg2: Value.
; Return:    eax -> Memory buffer or NULL if failed.

MemPoolAddString proc public uses esi edi pStr:PSTRINGA, dValue:DWORD
    mov edi, pStr
    mov esi, edi
    mov ecx, -1
    mov al, 0
    repnz scasb
    not ecx
    mov edi, g_pMemPtr
    lea eax, [edi + ecx + 4]
    cmp eax, g_pMemPoolMax
    jnc @Error
    mov edx, edi
    rep movsb
    mov eax, dValue
    stosd
    lea eax, [edi + 3]
    and al, 0FCh
    mov g_pMemPtr, eax
    mov eax, edx
    ret
@Error:
    xor eax, eax
    ret
MemPoolAddString endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure: _malloc
; Purpose:   Standard memory allocator
; Arguments: Arg1: Requested memory size.
; Return:    eax -> Memory buffer or NULL if failed.

_malloc proc stdcall public dBytes:DWORD
    invoke MemPoolAlloc, dBytes
    ret
_malloc endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure: _free
; Purpose:   Standard memory deallocator
; Arguments: Arg1: -> Memory block.
; Return:    Nothing.

_free proc stdcall public pMem:ptr
    ret
_free endp
