; ==================================================================================================
; Title:      StrDispose.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMemWin.cop

; --------------------------------------------------------------------------------------------------
; Procedure:  StrDispose
; Purpose:    Free the memory allocated for the string using StrNew, StrCNew, StrLENew or
;             StrAlloc.
;             If the pointer to the string is NULL, StrDispose does nothing.
; Arguments:  Arg1: -> String.
; Return:     Nothing.

.code
align ALIGN_CODE
StrDispose proc pString:POINTER
  .if rcx != NULL
    invoke GlobalFree, rcx
  .endif
  ret
StrDispose endp

end
