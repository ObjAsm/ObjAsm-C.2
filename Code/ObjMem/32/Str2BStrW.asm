; ==================================================================================================
; Title:      Str2BStrW.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
% include &ObjMemPath&ObjMemWin.cop

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  Str2BStrW
; Purpose:    Convert a ANSI string into a BStr.
; Arguments:  Arg1: -> Destination BStr buffer = Buffer address + sizeof DWORD.
;             Arg2: -> Source WIDE string.
; Return:     Nothing.

.code
align ALIGN_CODE
Str2BStrW proc pDstBStr:POINTER, pSrcStrW:POINTER
  invoke StrLengthW, pSrcStrW
  shl eax, 1                                            ;eax = # chars * 2
  mov ecx, pDstBStr
  mov dword ptr [ecx - 4], eax                          ;Store it
  invoke StrCopyW, ecx, pSrcStrW                        ;Copy the source string
  ret
Str2BStrW endp

end
