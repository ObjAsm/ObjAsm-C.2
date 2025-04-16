; ==================================================================================================
; Title:      StrCECopyW.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
% include &ObjMemPath&ObjMemWin.cop

; --------------------------------------------------------------------------------------------------
; Procedure:  StrCECopyW
; Purpose:    Copy the the source WIDE string with length limitation and return the last zero
;             character address.
;             The destination buffer should hold the maximum number of characters + 1.
;             Source and destination strings may overlap.
; Arguments:  Arg1: -> Destination WIDE character buffer.
;             Arg2: -> Source WIDE string.
;             Arg3: Maximal number of characters not including the ZTC.
; Return:     eax -> ZTC.

OPTION PROC:NONE

.code
align ALIGN_CODE
StrCECopyW proc pBuffer:POINTER, pSrcStringW:POINTER, dMaxChars:DWORD
  invoke StrCLengthW, [esp + 12], [esp + 12]            ;pSrcStringW, dMaxChars
  shl eax, 1
  push eax
  invoke MemShift, [esp + 16], [esp + 16], eax          ;pDstStringW, pSrcStringW
  pop eax
  add eax, [esp + 4]
  m2z WORD ptr [eax]                                    ;Set ZTC after mem shifting
  ret 12
StrCECopyW endp

OPTION PROC:DEFAULT

end
