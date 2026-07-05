; ==================================================================================================
; Title:      StrSizeA_SSE2.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, May 2026
;               - Initial release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\Code\OA_Setup32.inc
% include &ObjMemPath&ObjMemWin.cop
TARGET_CPU_SIMD_FEATURES = TARGET_CPU_SIMD_FEATURES or CPU_FEATURE_SIMD_SSE2

; --------------------------------------------------------------------------------------------------
; Constant pool
; --------------------------------------------------------------------------------------------------
; SSE2_PREMASK - Pre-string suppression table (16 rows x 16 bytes = 256 bytes).
;
; Row i (i = misalignment 0..15) has i leading 0FFh bytes followed by (16-i) zero bytes.
; OR-ing the first aligned XMM load with row[misalignment] forces every byte that lies
; BEFORE the actual string start to 0FFh, preventing a spurious zero-byte detection.
;
; Memory layout (byte 0 = lowest address):
;   row  0:  00 00 00 00 00 00 00 00  00 00 00 00 00 00 00 00
;   row  1:  FF 00 00 00 00 00 00 00  00 00 00 00 00 00 00 00
;   row  2:  FF FF 00 00 00 00 00 00  00 00 00 00 00 00 00 00
;   ...
;   row 15:  FF FF FF FF FF FF FF FF  FF FF FF FF FF FF FF 00

.const
align 16
SSE2_PREMASK label xmmword
  cnt = 0
  repeat 16                           ; one row per possible misalignment value 0..15
    if cnt gt 0
      DB cnt dup (0FFh)               ; suppress pre-string bytes
    endif
    if (16 - cnt) gt 0
      DB (16 - cnt) dup (00h)         ; string bytes pass through unchanged
    endif
    cnt = cnt + 1
  endm

; --------------------------------------------------------------------------------------------------
; Procedure:  StrSizeA_SSE2
; Purpose:    Determine the size of an ANSI string including the zero terminating character (ZTC).
; Arguments:  Arg1: -> ANSI string.
; Return:     eax = String size in BYTEs including the zero terminating character.

.code
OPTION PROC:NONE
align ALIGN_CODE
StrSizeA_SSE2 proc pStringA:POINTER

  ; -----------------------------------------------------------------------
  ; 1. Align the pointer DOWN to a 16-byte boundary and compute misalignment
  ;
  ;    Aligning DOWN guarantees the first load address is within the same
  ;    page as pStringA (both share bits [31:4]; the page index is bits
  ;    [31:12], which cannot differ after masking only bits [3:0]).
  ; -----------------------------------------------------------------------
  mov   eax, [esp + 4]              ; eax = pStringA (original, unaligned)
  mov   ecx, eax                    ; ecx = copy for misalignment extraction
  and   ecx, 15                     ; ecx = misalignment 0..15
  and   eax, 0FFFFFFF0h             ; eax = aligned-down 16-byte base address

  ; -----------------------------------------------------------------------
  ; 2. First chunk: load, mask, and test
  ;
  ;    The OR with SSE2_PREMASK[misalignment] converts every byte that
  ;    precedes the string start into 0FFh so that pcmpeqb cannot mistake
  ;    them for a zero terminator.
  ;
  ;    This load is safe by the alignment-down guarantee above.
  ; -----------------------------------------------------------------------
  pxor  xmm0, xmm0                  ; xmm0 = all zeros (comparand, not modified again)

  shl   ecx, 4                      ; ecx = misalignment * 16 (row byte offset in table)
  movdqa xmm1, [eax]                ; load first aligned 16-byte chunk
  por   xmm1, [SSE2_PREMASK + ecx]  ; suppress pre-string bytes with OR mask

  pcmpeqb xmm1, xmm0                ; 0FFh in each lane where the byte == 0
  pmovmskb edx, xmm1                ; edx bit i = 1 iff byte i of xmm1 was zero
  test  edx, edx
  jnz   SHORT @@Found               ; ZTC is in this first chunk -> done

  ; -----------------------------------------------------------------------
  ; 3. Main scan loop - one 16-byte aligned chunk per iteration
  ;
  ;    Invariant: eax is always a multiple of 16 (enforced by step 1 and
  ;    by advancing in steps of 16 below).
  ;
  ;    Safety: the load [eax] is issued BEFORE the zero test.  The loop
  ;    exits immediately when a zero is found, so the load that discovers
  ;    the ZTC is the last load issued.  No load is ever made beyond the
  ;    16-byte chunk that contains the ZTC.
  ;
  ;    Because every load is 16-byte aligned and 16 divides 4096 exactly,
  ;    no load can straddle a page boundary.  The load that finds the ZTC
  ;    lies on the same page as the ZTC itself.  QED: page-overrun safe.
  ; -----------------------------------------------------------------------
align ALIGN_CODE
@@Scan:
  add   eax, 16                     ; advance to next aligned 16-byte chunk
  movdqa xmm1, [eax]                ; load chunk (aligned: cannot cross page boundary)
  pcmpeqb xmm1, xmm0                ; compare all 16 bytes against zero in parallel
  pmovmskb edx, xmm1                ; collect zero-byte presence bits
  test  edx, edx
  jz    SHORT @@Scan                ; no zero byte found -> continue

  ; -----------------------------------------------------------------------
  ; 4. Compute return value
  ;
  ;    edx = 16-bit mask; bit i set <=> byte i of the current chunk is zero.
  ;    bsf finds the lowest set bit = byte offset of the ZTC within the chunk.
  ;    eax = base address of the chunk that contains the ZTC.
  ;
  ;    Size = (address_of_ZTC + 1) - pStringA
  ;         = (eax + byte_offset + 1) - pStringA
  ; -----------------------------------------------------------------------
@@Found:
  bsf   edx, edx                    ; edx = byte offset of ZTC within chunk (0..15)
  mov   ecx, [esp + 4]              ; ecx = original pStringA (overlaps bsf latency)
  lea   eax, [eax + edx + 1]        ; eax = address of ZTC + 1
  sub   eax, ecx                    ; eax = byte count including ZTC
  ret   4

StrSizeA_SSE2 endp
OPTION PROC:DEFAULT

end