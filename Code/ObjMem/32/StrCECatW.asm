; ==================================================================================================
; Title:      StrCECatW.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
% include &ObjMemPath&ObjMemWin.cop

; --------------------------------------------------------------------------------------------------
; Procedure:  StrCECatW
; Purpose:    Concatenate 2 WIDE strings with length limitation and return the ending zero character
;             address. The destination string buffer should have at least enough room for the
;             maximum number of characters + 1.
; Arguments:  Arg1: -> Destination WIDE character buffer.
;             Arg2: -> Source WIDE string.
;             Arg3: Maximal number of charachters that the destination string can hold including the
;                   ZTC.
; Return:     eax -> ZTC.

OPTION PROC:NONE

.code
align ALIGN_CODE
StrCECatW proc pBuffer:POINTER, pSrcStringW:POINTER, dMaxChars:DWORD
  invoke StrEndW, [esp + 4]                             ;pBuffer
  mov ecx, [esp + 12]                                   ;ecx = dMaxChars
  shl ecx, 1
  add ecx, [esp + 4]                                    ;pBuffer
  sub ecx, eax
  jbe @@Exit                                            ;Destination is too small!
  shr ecx, 1
  invoke StrCECopyW, eax, [esp + 12], ecx               ;pSrcStringW
@@Exit:
  ret 12
StrCECatW endp

OPTION PROC:DEFAULT

end
