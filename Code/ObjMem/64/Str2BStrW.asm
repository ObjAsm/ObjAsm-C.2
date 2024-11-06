; ==================================================================================================
; Title:      Str2BStrW.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMemWin.cop

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  Str2BStrW
; Purpose:    Convert a WIDE string into a BStr.
; Arguments:  Arg1: -> Destination BStr buffer = Buffer address + sizeof(DWORD).
;             Arg2: -> Source WIDE string.
; Return:     Nothing.

.code
align ALIGN_CODE
Str2BStrW proc pDstBStr:POINTER, pSrcStrW:POINTER
  invoke StrLengthW, pSrcStrW
  shl eax, 1                                            ;eax = # chars * 2
  mov rcx, pDstBStr
  mov DWORD ptr [rcx - sizeof(DWORD)], eax              ;Store it
  invoke StrCopyW, rcx, pSrcStrW                        ;Copy the source string
  ret
Str2BStrW endp

end
