; ==================================================================================================
; Title:      BStrECopy.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
% include &ObjMemPath&ObjMemWin.cop

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure: BStrECopy
; Purpose:   Copy a BStr to a buffer and return the address of the ZTC.
;            Source and destination strings may overlap.
; Arguments: Arg1: -> Destination BStr buffer.
;            Arg2: -> Source BStr buffer.
; Return:    eax -> ZTC.


OPTION PROC:NONE

.code
align ALIGN_CODE
BStrECopy proc pDstBStr:POINTER, pSrcBStr:POINTER
  mov eax, [esp + 4]                                    ;eax -> DstBStr
  mov ecx, [esp + 8]                                    ;ecx -> SrcBStr
  sub ecx, 4
  sub eax, 4
  mov edx, DWORD ptr [ecx]
  push edx
  add edx, 6
  invoke MemShift, eax, ecx, edx
  pop eax
  add eax, [esp + 4]                                    ;pDstBStr
  ret 8
BStrECopy endp

OPTION PROC:DEFAULT

end
