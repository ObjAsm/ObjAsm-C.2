; ==================================================================================================
; Title:      aCRC32C_XP.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.1, March 2022
;               - First release.
; ==================================================================================================


; --------------------------------------------------------------------------------------------------
; Procedure:  aCRC32C
; Purpose:    Compute the CRC-32C (Castagnoli), using the polynomial 11EDC6F41h from an aligned
;             memory block.
; Arguments:  Arg1: -> Aligned memory block.
;             Arg2: Memory block size in BYTEs.
; Return:     eax = CRC32C.
; Link:       https://en.wikipedia.org/wiki/Cyclic_redundancy_check

.code
align ALIGN_CODE
aCRC32C proc uses xbx pAlignedMem:POINTER, dByteCount:DWORD
.const
DigestPosBytesJumpTableA label POINTER
  POINTER @@Digest0PosBytes
  POINTER @@Digest1PosBytes
  POINTER @@Digest2PosBytes
  POINTER @@Digest3PosBytes
if TARGET_BITNESS eq 64
  POINTER @@Digest4PosBytes
  POINTER @@Digest5PosBytes
  POINTER @@Digest6PosBytes
  POINTER @@Digest7PosBytes
endif

.code
  ?mov xcx, pAlignedMem                                 ;xcx -> Key
  ?mov edx, dByteCount                                  ;edx = BYTE count
  mov eax, -1

  .while edx >= sizeof(XWORD)                           ;Digest as much XWORDs as possible
    crc32 xax, XWORD ptr [xcx]
    add xcx, sizeof(XWORD)                              ;Move to next XWORD
    sub edx, sizeof(XWORD)                              ;Decrement ByteCount
  .endw

align ALIGN_CODE
@@DigestPosBytes:
  mov xbx, [xcx]
  mov xcx, offset DigestPosBytesJumpTableA
  jmp POINTER ptr [xcx + xdx*sizeof(POINTER)]           ;Jump to the pos BYTEs digest handler

if TARGET_BITNESS eq 64
align ALIGN_CODE
@@Digest7PosBytes:
  crc32 eax, ebx
  shr xbx, 32
  crc32 eax, bx
  shr xbx, 16
  crc32 eax, bl
  jmp @@Digest0PosBytes

align ALIGN_CODE
@@Digest6PosBytes:
  crc32 eax, ebx
  shr xbx, 32
  crc32 eax, bx
  jmp @@Digest0PosBytes

align ALIGN_CODE
@@Digest5PosBytes:
  crc32 eax, ebx
  shr xbx, 32
  crc32 eax, bl
  jmp @@Digest0PosBytes

align ALIGN_CODE
@@Digest4PosBytes:
  crc32 eax, ebx
  jmp @@Digest0PosBytes
endif

align ALIGN_CODE
@@Digest3PosBytes:
  crc32 eax, bx
  shr ebx, 16
  crc32 eax, bl
  jmp @@Digest0PosBytes

align ALIGN_CODE
@@Digest2PosBytes:
  crc32 eax, bx
  jmp @@Digest0PosBytes

align ALIGN_CODE
@@Digest1PosBytes:
  crc32 eax, bl

align ALIGN_CODE
@@Digest0PosBytes:
  xor eax, -1                                           ;Finish CRC calulation
  ret
aCRC32C endp

