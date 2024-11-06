; ==================================================================================================
; Title:      BStrCat.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
% include &ObjMemPath&ObjMemWin.cop

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  BStrCat
; Purpose:    Concatenate 2 BStrs.
; Arguments:  Arg1: Destrination BStr.
;             Arg2: Source BStr.
; Return:     Nothing.

OPTION PROC:NONE

.code
align ALIGN_CODE
BStrCat proc pDstBStr:POINTER, pSrcBStr:POINTER
  mov ecx, [esp + 8]                                    ;ecx -> SrcBStr
  mov edx, [esp + 4]                                    ;edx -> DstBStr
  mov eax, DWORD ptr [ecx - 4]
  mov ecx, DWORD ptr [edx - 4]
  add DWORD ptr [edx - 4], eax                          ;Store new length
  add edx, ecx
  add eax, 2
  invoke MemShift, edx, [esp + 12], eax                 ;pSrcBStr
  ret 8
BStrCat endp

OPTION PROC:DEFAULT

end
