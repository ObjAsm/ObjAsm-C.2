; ==================================================================================================
; Title:      StrCCatA.asm
; Author:     G. Friedrich
; Version:    C.1.1
; Notes:      Version C.1.0, October 2017
;               - First release.
;             Version C.1.1, July 2022
;               - Return value added.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
% include &ObjMemPath&ObjMemWin.cop

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  StrCCatA
; Purpose:    Concatenate 2 ANSI strings with length limitation.
;             The destination string buffer should have at least enough room for the maximum number
;             of characters + 1.
; Arguments:  Arg1: -> Destination ANSI character buffer.
;             Arg2: -> Source ANSI string.
;             Arg3: Maximal number of charachters that the destination string can hold including the
;                   ZTC.
; Return:     eax = Number of added BYTEs.

OPTION PROC:NONE

.code
align ALIGN_CODE
StrCCatA proc pBuffer:POINTER, pSrcStringA:POINTER, dMaxChars:DWORD
  invoke StrEndA, [esp + 4]
  mov ecx, [esp + 4]                                    ;ecx -> Buffer
  add ecx, [esp + 12]
  sub ecx, eax
  jbe @F                                                ;Destination is too small!
  invoke StrCCopyA, eax, [esp + 12], ecx
  sub eax, sizeof(CHRA)                                 ;Exclude ZTC
  ret 12
@@:
  xor eax, eax
  ret 12
StrCCatA endp

OPTION PROC:DEFAULT

end
