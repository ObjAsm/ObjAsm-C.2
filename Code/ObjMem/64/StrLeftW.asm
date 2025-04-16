; ==================================================================================================
; Title:      StrLeftW.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMemWin.cop

; --------------------------------------------------------------------------------------------------
; Procedure:  StrLeftW
; Purpose:    Extract the left n characters of the source WIDE string.
; Arguments:  Arg1: -> Destination buffer.
;             Arg2: -> Source WIDE string.
; Return:     eax = Number of copied characters, not including the ZTC.

.code
align ALIGN_CODE
StrLeftW proc uses rbx pBuffer:POINTER, pSrcStringW:POINTER, dCharCount:DWORD
  invoke StrCLengthW, pSrcStringW, dCharCount
  mov ebx, eax
  shl eax, 1
  invoke MemShift, pBuffer, pSrcStringW, eax
  mov eax, ebx                                          ;Return number of copied chars
  mov rdx, pBuffer
  lea rdx, [rdx + sizeof(CHRW)*rax]
  m2z CHRW ptr [rdx]                                    ;Set ZTC
  ret
StrLeftW endp

end
