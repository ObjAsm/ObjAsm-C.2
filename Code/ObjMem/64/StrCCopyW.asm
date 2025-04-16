; ==================================================================================================
; Title:      StrCCopyW.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMemWin.cop

; --------------------------------------------------------------------------------------------------
; Procedure:  StrCCopyW
; Purpose:    Copy the the source WIDE string with length limitation.
;             The destination buffer should be big enough to hold the maximum number of
;             characters + 1.
; Arguments:  Arg1: -> Destination buffer.
;             Arg2: -> Source WIDE string.
;             Arg3: Maximal number of charachters to copy, excluding the ZTC.
; Return:     rax = Number of copied BYTEs, including the ZTC.

.code
align ALIGN_CODE
StrCCopyW proc uses rdi pBuffer:POINTER, pSrcStringW:POINTER, dMaxChars:DWORD
  ;rcx = pBuffer, rdx = pSrcStringW, r8d = dMaxChars
  mov rdi, rcx                                          ;rdi = pBuffer
  invoke StrCLengthW, rdx, r8d                          ;pSrcStr, dMaxChars
  shl eax, 1
  m2z CHRW ptr [rdi + rax]                              ;Set ZTC
  invoke MemShift, rdi, pSrcStringW, eax
  add rax, sizeof(CHRW)                                 ;ZTC size
  ret
StrCCopyW endp

end
