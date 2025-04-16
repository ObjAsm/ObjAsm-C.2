; ==================================================================================================
; Title:      StrLeftA.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMemWin.cop

; --------------------------------------------------------------------------------------------------
; Procedure:  StrLeftA
; Purpose:    Extract the left n characters of the source ANSI string.
; Arguments:  Arg1: -> Destination character buffer.
;             Arg2: -> Source ANSI string.
; Return:     eax = Number of copied characters, not including the ZTC.

.code
align ALIGN_CODE
StrLeftA proc uses rbx pBuffer:POINTER, pSrcStringA:POINTER, dCharCount:DWORD
  invoke StrCLengthA, pSrcStringA, dCharCount
  mov ebx, eax
  invoke MemShift, pBuffer, pSrcStringA, eax
  mov eax, ebx                                          ;Return number of copied chars
  mov rdx, pBuffer
  add rdx, rax
  m2z CHRA ptr [rdx]                                    ;Set ZTC
  ret
StrLeftA endp

end
