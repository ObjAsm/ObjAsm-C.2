; ==================================================================================================
; Title:      StrCECatA.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
% include &ObjMemPath&ObjMemWin.cop

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  StrCECatA
; Purpose:    Concatenate 2 ANSI strings with length limitation and return the ending zero character
;             address. The destination string buffer should have at least enough room for the maximum
;             number of characters + 1.
; Arguments:  Arg1: -> Destination ANSI character buffer.
;             Arg2: -> Source ANSI string.
;             Arg3: Maximal number of charachters that the destination string can hold including the
;                   ZTC.
; Return:     eax -> ZTC.

OPTION PROC:NONE

.code
align ALIGN_CODE
StrCECatA proc pBuffer:POINTER, pSrcStringA:POINTER, dMaxChars:DWORD
  invoke StrEndA, [esp + 4]                             ;pBuffer
  mov ecx, [esp + 12]                                   ;ecx = dMaxChars
  add ecx, [esp + 4]                                    ;pBuffer
  sub ecx, eax
  jbe @F                                                ;Destination is too small!
  invoke StrCECopyA, eax, [esp + 12], ecx               ;pSrcStringA
@@:
  ret 12
StrCECatA endp

OPTION PROC:DEFAULT

end
