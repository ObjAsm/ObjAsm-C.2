; ==================================================================================================
; Title:      uCRC32C_XP.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.1, March 2022
;               - First release.
;               - Bitness and platform independent code.
; ==================================================================================================


; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  uCRC32C
; Purpose:    Compute the CRC-32C (Castagnoli), using the polynomial 11EDC6F41h from an unaligned
;             memory block.
; Arguments:  Arg1: -> Unaligned memory block.
;             Arg2: Memory block size in BYTEs.
; Return:     eax = CRC32C.
; Link:       https://en.wikipedia.org/wiki/Cyclic_redundancy_check

align ALIGN_CODE
uCRC32C proc uses xbx pUnalignedMem:POINTER, dByteCount:DWORD
.const
DigestPreBytesJumpTableU label POINTER
POINTER @@Digest0PreBytes
POINTER @@Digest1PreBytes
POINTER @@Digest2PreBytes
POINTER @@Digest3PreBytes
if TARGET_BITNESS eq 64
POINTER @@Digest4PreBytes
POINTER @@Digest5PreBytes
POINTER @@Digest6PreBytes
POINTER @@Digest7PreBytes
endif

DigestPosBytesJumpTableU label POINTER
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
  ?mov xcx, pUnalignedMem                               ;xcx -> Key
  ?mov edx, dByteCount                                  ;edx = BYTE count
  mov xbx, xcx
  and xbx, sizeof(XWORD) - 1                            ;ebx = pKey offset from aligned memory
  lea eax, [edx + ebx]
  cmp eax, sizeof(XWORD)                                ;Check if Skipped BYTEs + ByteCount < sizeof(XWORD)
  jb @@DigestBytes                                      ;If yes => goto digest BYTEs

  sub xcx, xbx                                          ;xcx -> aligned memory
  sub edx, ebx                                          ;Remaining BYTEs after digest of pre BYTEs
  mov xax, offset DigestPreBytesJumpTableU
  lea xbx, [xax + xbx*sizeof(POINTER)]
  mov eax, -1                                           ;Set CRC seed value
  jmp POINTER ptr [xbx]                                 ;Jump to the pre BYTEs digest handler

@@DigestBytes:
  mov xax, xcx
  sub xax, xbx                                          ;xax -> aligned memory
  lea ecx, [8*ebx]
  mov xbx, [xax]                                        ;Load mem into register
  shr xbx, cl                                           ;Skip unused BYTEs
  mov xcx, offset DigestPosBytesJumpTableU
  mov eax, -1                                           ;Set CRC seed value
  jmp POINTER ptr [xcx + xdx*sizeof(POINTER)]           ;Jump to the pos BYTEs digest handler

if TARGET_BITNESS eq 64
align ALIGN_CODE
@@Digest7PreBytes:
  mov xbx, [xcx]
  shr xbx, 8
  crc32 eax, bl
  shr xbx, 8
  crc32 eax, bx
  shr xbx, 16
  crc32 eax, ebx
  add xcx, sizeof(XWORD)
  jmp @@Digest0PreBytes

align ALIGN_CODE
@@Digest6PreBytes:
  mov xbx, [xcx]
  shr xbx, 16
  crc32 eax, bx
  shr xbx, 16
  crc32 eax, ebx
  add xcx, sizeof(XWORD)
  jmp @@Digest0PreBytes

align ALIGN_CODE
@@Digest5PreBytes:
  mov xbx, [xcx]
  shr xbx, 24
  crc32 eax, bl
  shr xbx, 16
  crc32 eax, ebx
  add xcx, sizeof(XWORD)
  jmp @@Digest0PreBytes

align ALIGN_CODE
@@Digest4PreBytes:
  mov xbx, [xcx]
  shr xbx, 32
  crc32 eax, ebx
  add xcx, sizeof(XWORD)
  jmp @@Digest0PreBytes
endif

align ALIGN_CODE
@@Digest3PreBytes:
  mov xbx, [xcx]
  shr xbx, 40
  crc32 eax, bl
  shr xbx, 8
  crc32 eax, bx
  add xcx, sizeof(XWORD)
  jmp @@Digest0PreBytes

align ALIGN_CODE
@@Digest2PreBytes:
  mov xbx, [xcx]
  shr xbx, 48
  crc32 eax, bx
  add xcx, sizeof(XWORD)
  jmp @@Digest0PreBytes

align ALIGN_CODE
@@Digest1PreBytes:
  mov xbx, [xcx]
  shr xbx, 56
  crc32 eax, bl
  add xcx, sizeof(XWORD)

align ALIGN_CODE
@@Digest0PreBytes:
  .while edx >= sizeof(XWORD)                           ;Digest as much XWORDs as possible
    crc32 xax, XWORD ptr [xcx]
    add xcx, sizeof(XWORD)                              ;Move to next XWORD
    sub edx, sizeof(XWORD)                              ;Decrement ByteCount
  .endw

align ALIGN_CODE
@@DigestPosBytes:
  mov xbx, [xcx]
  mov xcx, offset DigestPosBytesJumpTableU
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
uCRC32C endp

