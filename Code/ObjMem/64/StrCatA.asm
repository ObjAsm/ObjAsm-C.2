; ==================================================================================================
; Title:      StrCatA.asm
; Author:     G. Friedrich
; Version:    C.1.1
; Notes:      Version C.1.0, October 2017
;               - First release.
;             Version C.1.1, July 2022
;               - Return value added.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMemWin.cop

; --------------------------------------------------------------------------------------------------
; Procedure:  StrCatA
; Purpose:    Concatenate 2 ANSI strings.
; Arguments:  Arg1: Destrination ANSI buffer.
;             Arg2: Source ANSI string.
; Return:     Nothing.

.code
align ALIGN_CODE
StrCatA proc pDstStrA:POINTER, pSrcStrA:POINTER
  invoke StrEndA, rcx                                   ;pDstStrA
  invoke StrCopyA, rax, pSrcStrA
  sub rax, sizeof(CHRA)                                 ;Sizeof ZTC
  ret
StrCatA endp

end
