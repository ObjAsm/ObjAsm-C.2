; ==================================================================================================
; Title:      StrLeftW.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
% include &ObjMemPath&ObjMemWin.cop

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  StrLeftW
; Purpose:    Extract the left n characters of the source WIDE string.
; Arguments:  Arg1: -> Destination buffer.
;             Arg2: -> Source WIDE string.
; Return:     eax = Number of copied characters, not including the ZTC.

OPTION PROC:NONE

.code
align ALIGN_CODE
StrLeftW proc pBuffer:POINTER, pSrcStringW:POINTER, dCharCount:DWORD
  invoke StrCLengthW, [esp + 12], [esp + 12]            ;pSrcStringW, dCharCount
  push eax
  shl eax, 1
  invoke MemShift, [esp + 16], [esp + 16], eax          ;pBuffer, pSrcStringW
  pop eax                                               ;Return number of copied chars
  mov edx, [esp + 4]                                    ;pBuffer
  lea edx, [edx + 2 * eax]
  m2z WORD ptr [edx]                                    ;Set ZTC
  ret 12
StrLeftW endp

OPTION PROC:DEFAULT

end
