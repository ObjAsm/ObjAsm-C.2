; ==================================================================================================
; Title:      StrMidA.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMemWin.cop

; --------------------------------------------------------------------------------------------------
; Procedure:  StrMidA
; Purpose:    Extract a substring from an ANSI source string.
; Arguments:  Arg1: -> Destination ANSI character buffer.
;             Arg2: -> Source ANSI string.
;             Arg3: Start character index. Index ranges [0 .. length-1].
;             Arg3: Character count.
; Return:     eax = Number of copied characters.

.code
align ALIGN_CODE
StrMidA proc pBuffer:POINTER, pSrcStringA:POINTER, dStartChar:DWORD, dCharCount:DWORD
  invoke StrLengthA, rdx
  mov ecx, eax
  inc ecx
  .if eax <= dStartChar
    mov rdx, pBuffer                                    ;Source too small
    xor eax, eax
  .else
    sub eax, dStartChar
    .if eax < dCharCount
      sub ecx, dStartChar
      mov dCharCount, ecx
    .endif
    mov edx, dStartChar
    add rdx, pSrcStringA
    invoke MemShift, pBuffer, rdx, dCharCount
    mov eax, dCharCount                                 ;Set return value = number of copied chars
    mov rdx, pBuffer
    add rdx, rax
  .endif
  m2z CHRA ptr [rdx]                                    ;Set ZTC
  ret
StrMidA endp

end
