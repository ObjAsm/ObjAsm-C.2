; ==================================================================================================
; Title:      StrCECopyA.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
% include &ObjMemPath&ObjMemWin.cop

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  StrCECopyA
; Purpose:    Copy the the source ANSI string with length limitation and return the ending zero
;             character address.
;             The destination buffer should hold the maximum number of characters + 1.
;             Source and destination strings may overlap.
; Arguments:  Arg1: -> Destination ANSI character buffer.
;             Arg2: -> Source ANSI string.
;             Arg3: Maximal number of characters not including the ZTC.
; Return:     eax -> ZTC.

OPTION PROC:NONE

.code
align ALIGN_CODE
StrCECopyA proc pBuffer:POINTER, pSrcStringA:POINTER, dMaxChars:DWORD
  invoke StrCLengthA, [esp + 12], [esp + 12]            ;pSrcStr, dMaxChars
  push eax
  invoke MemShift, [esp + 16], [esp + 16], eax          ;pDstStr, pSrcStr
  pop eax
  add eax, [esp + 4]
  m2z BYTE ptr [eax]                                    ;Set ZTC after mem shifting
  ret 12
StrCECopyA endp

OPTION PROC:DEFAULT

end
