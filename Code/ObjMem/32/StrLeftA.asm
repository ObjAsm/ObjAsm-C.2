; ==================================================================================================
; Title:      StrLeftA.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
% include &ObjMemPath&ObjMemWin.cop

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure: StrLeftA
; Purpose:   Extract the left n characters of the source ANSI string.
; Arguments: Arg1: -> Destination character buffer.
;            Arg2: -> Source ANSI string.
; Return:    eax = Number of copied characters, not including the ZTC.

OPTION PROC:NONE

.code
align ALIGN_CODE
StrLeftA proc pBuffer:POINTER, pSrcStringA:POINTER, dCharCount:DWORD
  invoke StrCLengthA, [esp + 12], [esp + 12]            ;pSrcStringA, dCharCount
  push eax
  invoke MemShift, [esp + 16], [esp + 16], eax          ;pBuffer, pSrcStringA
  pop eax                                               ;Return number of copied chars
  mov edx, [esp + 4]                                    ;pBuffer
  add edx, eax
  m2z BYTE ptr [edx]                                    ;Set ZTC
  ret 12
StrLeftA endp

OPTION PROC:DEFAULT

end
