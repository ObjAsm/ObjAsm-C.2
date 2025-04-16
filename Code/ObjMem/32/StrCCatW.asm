; ==================================================================================================
; Title:      StrCCatW.asm
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
; Procedure:  StrCCatW
; Purpose:    Concatenate 2 WIDE strings with length limitation.
;             The destination string buffer should have at least enough room for the maximum number
;             of characters + 1.
; Arguments:  Arg1: -> Destination WIDE character buffer.
;             Arg2: -> Source WIDE string.
;             Arg3: Maximal number of charachters that the destination string can hold including the
;                   ZTC.
; Return:     eax = Number of added BYTEs.

OPTION PROC:NONE

.code
align ALIGN_CODE
StrCCatW proc pBuffer:POINTER, pSrcStringW:POINTER, dMaxChars:DWORD
  invoke StrEndW, [esp + 4]                             ;pBuffer
  mov ecx, [esp + 12]                                   ;ecx = dMaxChars
  shl ecx, 1
  add ecx, [esp + 4]                                    ;ecx -> Buffer
  sub ecx, eax
  jbe @F                                                ;Destination is too small!
  shr ecx, 1
  invoke StrCCopyW, eax, [esp + 12], ecx                ;pSrcStringW
  sub eax, sizeof(CHRW)                                 ;Exclude ZTC
  ret 12
@@:
  xor eax, eax
  ret 12
StrCCatW endp

OPTION PROC:DEFAULT

end
