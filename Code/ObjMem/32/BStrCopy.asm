; ==================================================================================================
; Title:      BStrCopy.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
% include &ObjMemPath&ObjMemWin.cop

; --------------------------------------------------------------------------------------------------
; Procedure:  BStrCopy
; Purpose:    Copy a BStr to a destination buffer.
; Arguments:  Arg1: Destrination BStr buffer.
;             Arg2: Source BStr.
; Return:     Nothing.

OPTION PROC:NONE

.code
align ALIGN_CODE
BStrCopy proc pDstBStr:POINTER, pSrcBStr:POINTER
  mov ecx, [esp + 8]                                    ;ecx -> SrcBStr
  mov eax, [esp + 4]                                    ;eax -> DstBStr
  sub ecx, 4
  sub eax, 4
  mov edx, DWORD ptr [ecx]
  add edx, 6                                            ;4+2 = char count + zero terminating word
  invoke MemShift, eax, ecx, edx
  ret 8
BStrCopy endp

OPTION PROC:DEFAULT

end
