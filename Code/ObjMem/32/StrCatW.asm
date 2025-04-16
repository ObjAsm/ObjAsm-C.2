; ==================================================================================================
; Title:      StrCatW.asm
; Author:     G. Friedrich
; Version:    C.1.1
; Notes:      Version C.1.0, October 2017
;               - First release.
;             Version C.1.1, July 2022
;               - Return value added.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
% include &ObjMemPath&ObjMemWin.cop

; --------------------------------------------------------------------------------------------------
; Procedure:  StrCatW
; Purpose:    Concatenate 2 WIDE strings.
; Arguments:  Arg1: Destrination WIDE string.
;             Arg2: Source WIDE string.
; Return:     Nothing.

OPTION PROC:NONE

.code
align ALIGN_CODE
StrCatW proc pDstStrW:POINTER, pSrcStrW:POINTER
  invoke StrEndW, [esp + 4]                             ;pDstStrW
  invoke StrCopyW, eax, [esp + 8]                       ;pSrcStrW
  sub eax, sizeof(CHRW)                                 ;Sizeof ZTC
  ret 8
StrCatW endp

OPTION PROC:DEFAULT

end
