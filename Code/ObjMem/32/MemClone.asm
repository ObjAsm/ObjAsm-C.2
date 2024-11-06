; ==================================================================================================
; Title:      MemClone.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
% include &ObjMemPath&ObjMemWin.cop

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  MemClone
; Purpose:    Copy a memory block from a source to a destination buffer.
;             Source and destination must NOT overlap.
;             Destination buffer must be at least as large as number of BYTEs to copy, otherwise a
;             fault may be triggered.
; Arguments:  Arg1: -> Destination buffer.
;             Arg2: -> Source buffer.
;             Arg3: Number of BYTEs to copy.
; Return:     Nothing.

OPTION PROC:NONE

.code
align ALIGN_CODE
MemClone proc pDstMem:POINTER, pSrcMem:POINTER, dCount:DWORD
  push edi
  push esi
  mov edi, [esp + 12]                                   ;edi -> DstMem
  mov esi, [esp + 16]                                   ;esi -> SrcMem
  mov ecx, [esp + 20]                                   ;ecx = dCount
  shr ecx, 2
  rep movsd
  mov ecx, [esp + 20]                                   ;dCount
  and ecx, 3
  rep movsb
  pop esi
  pop edi
  ret 12
MemClone endp

OPTION PROC:DEFAULT

end
