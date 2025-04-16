; ==================================================================================================
; Title:      MemBlock.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm MemBlock macro and procedure implementations.
; Notes:      Version C.1.0, January 2023
;               - First release.
; ==================================================================================================


; MemBlock layout:
;                                                              MemBlock points here!
;        Offset BYTEs    WORD     WORD      DWORD         DWORD    v
;       ------------------------------------------------------------------------------------
;  ... |  Padding     | Offset | Flags |  BYTE Size  | BYTE Usage  | BYTE Payload           | ...
;       ------------------------------------------------------------------------------------
;      ^                                                           ^
;      Heap Alignment 8/16                                         Alignment 4/8/16/32/...
;
;                                                     <------------------------------------>
;                                                      BSTR if the payload is a WIDE string


; ==================================================================================================


;MemBlock Flags
;The remainig bits are left for application specific use
MBF_WRITABLE  equ BIT00
MBF_DYNAMIC   equ BIT01

MemBlockHeader struct
  wOffset   WORD  ?           ;Offset from start of heap allocation to start of the MemBlockHeader
  wFlags    WORD  ?           ;Flags
  dSize     DWORD ?           ;Payload size in BYTEs
  dUsed     DWORD ?           ;Payload usage (incl. ZTC) in BYTEs
MemBlockHeader ends
MEMBLOCK_HEADER_SIZE equ sizeof(MemBlockHeader)

MemBlock struct
  MemBlockHeader  <>
  bPayload  BYTE  0 dup(?)
MemBlock ends

;The heap allocation granularity is 8 for 32-bit applications and 16 for a 64-bit applications.
;https://techcommunity.microsoft.com/t5/ask-the-performance-team/what-a-heap-of-part-one/ba-p/372424
HEAP_ALLOC_GRANULARITY = TARGET_BITNESS/4

;The heap allocation alignment is 8 for 32-bit applications and 16 for 64-bit applications.
HEAP_ALLOC_ALIGNMENT = TARGET_BITNESS/4

;For heap allocations, padding bytes are required to control payload alignment.
;This value can be changed according to the requirements of the architecture, such as SSE or AVX.
MEMBLOCK_PAYLOAD_ALIGNMENT = 16                 ;SSE architecture, PARA alignment
MEMBLOCK_PAYLOAD_GRANULARITY = 16*sizeof(CHR)   ;At least 128-bit for XMM register access

; --------------------------------------------------------------------------------------------------
; Procedure:  MemBlockAlloc
; Purpose:    Allocate a MemBlock with a given payload size.
; Arguments:  Arg1: Min. payload size in BYTEs.
; Return:     xax -> MemBlock.bPayload or NULL if failed.
; Note:       The allocated memory size is a multiple of MEMBLOCK_ALLOC_GRANULARITY
;             and the free space on the payload is at least equal to MEMBLOCK_ALLOC_GRANULARITY.
.code
align ALIGN_CODE
MemBlockAlloc_X proc uses xbx dMinPayloadSize:DWORD
  ?mov ecx, dMinPayloadSize
  lea ebx, [MEMBLOCK_PAYLOAD_ALIGNMENT + MEMBLOCK_HEADER_SIZE + ecx + MEMBLOCK_PAYLOAD_GRANULARITY]
  and ebx, -HEAP_ALLOC_GRANULARITY
  MemAlloc xbx
  test xax, xax
  jz @@Error
  lea xcx, [xax + MEMBLOCK_HEADER_SIZE + MEMBLOCK_PAYLOAD_ALIGNMENT]
  and xcx, -MEMBLOCK_PAYLOAD_ALIGNMENT
  sub xcx, xax
  sub xcx, MEMBLOCK_HEADER_SIZE
  .while SIGN?
    add xcx, MEMBLOCK_PAYLOAD_ALIGNMENT
  .endw
  add xax, xcx
  mov [xax].MemBlockHeader.wFlags, MBF_DYNAMIC or MBF_WRITABLE
  mov [xax].MemBlockHeader.wOffset, cx
  sub ebx, MEMBLOCK_HEADER_SIZE
  sub ebx, ecx
  mov [xax].MemBlockHeader.dSize, ebx
  mov [xax].MemBlockHeader.dUsed, 0
  add xax, MEMBLOCK_HEADER_SIZE
@@Error:
  ret
MemBlockAlloc_X endp

; --------------------------------------------------------------------------------------------------
; Procedure:  MemBlockFree
; Purpose:    Deallocate an MemBlock.
; Arguments:  Arg1: -> MemBlock.bPayload.
; Return:     Nothing.

.code
align ALIGN_CODE
MemBlockFree_X proc pMemBlockPayload:POINTER
  ?mov xcx, pMemBlockPayload
  lea xax, [xcx - MEMBLOCK_HEADER_SIZE]
  .ifBitSet [xax].MemBlockHeader.wFlags, MBF_DYNAMIC
    movzx xcx, [xax].MemBlockHeader.wOffset
    sub xax, xcx
    MemFree xax
  .else
    DbgWarning "MemBlockFree: MemBlock is not DYNAMIC"
  .endif
  ret
MemBlockFree_X endp

; --------------------------------------------------------------------------------------------------
; Procedure:  MemBlockClone
; Purpose:    Clone a MemBlock.
; Arguments:  Arg1: -> MemBlock.bPayload.
; Return:     xax -> Cloned MemBlock.bPayload.
; Note:       MemBlockHeader.wFlags are set to MBF_DYNAMIC || MBF_WRITABLE.

.code
align ALIGN_CODE
MemBlockClone_X proc uses xbx xdi pMemBlockPayload:POINTER
  ?mov xcx, pMemBlockPayload
  lea xax, [xcx - MEMBLOCK_HEADER_SIZE]
  mov ebx, [xax].MemBlockHeader.dSize
  add ebx, MEMBLOCK_HEADER_SIZE
  MemAlloc xbx
  test xax, xax
  jz @@Error
  mov xdi, xax
  mov xcx, pMemBlockPayload
  lea xdx, [xcx - MEMBLOCK_HEADER_SIZE]
  invoke MemClone, xax, xdx, ebx
  mov xax, xdi
  mov [xdi].MemBlockHeader.wFlags, MBF_DYNAMIC or MBF_WRITABLE
@@Error:
  ret
MemBlockClone_X endp
