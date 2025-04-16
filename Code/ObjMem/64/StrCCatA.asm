; ==================================================================================================
; Title:      StrCCatA.asm
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
; Procedure:  StrCCatA
; Purpose:    Concatenate 2 ANSI strings with length limitation.
;             The destination string buffer should have at least enough room for the maximum number
;             of characters + 1.
; Arguments:  Arg1: -> Destination ANSI character buffer.
;             Arg2: -> Source ANSI string.
;             Arg3: Maximal number of charachters that the destination string can hold including the
;                   ZTC.
; Return:     rax = Number of added BYTEs.

.code
align ALIGN_CODE
StrCCatA proc pDstStringA:POINTER, pSrcStringA:POINTER, dMaxChars:DWORD
  invoke StrEndA, rcx
  mov r8d, dMaxChars
  add r8, pDstStringA
  sub r8, rax
  jbe @F                                                ;Destination is too small!
  invoke StrCCopyA, rax, pSrcStringA, r8d
  sub rax, sizeof(CHRA)                                 ;Exclude ZTC
  ret
@@:
  xor eax, eax
  ret
StrCCatA endp

end
