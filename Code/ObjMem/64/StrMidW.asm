; ==================================================================================================
; Title:      StrMidW.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMemWin.cop

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  StrMidW
; Purpose:    Extract a substring from a WIDE source string.
; Arguments:  Arg1: -> Destination WIDE character buffer.
;             Arg2: -> Source WIDE string.
;             Arg3: Start character index. Index ranges [0 .. length-1].
;             Arg3: Character count.
; Return:     eax = Number of copied characters.

.code
align ALIGN_CODE
StrMidW proc pBuffer:POINTER, pSrcStringW:POINTER, dStartChar:DWORD, dCharCount:DWORD
  invoke StrLengthW, rdx
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
    shl rdx, 1
    add rdx, pSrcStringW
    mov r8d, dCharCount
    shl r8d, 1
    invoke MemShift, pBuffer, rdx, r8d
    mov eax, dCharCount                                 ;Set return value = number of copied chars
    mov rdx, pBuffer
    lea rdx, [rdx + sizeof(CHRW)*rax]
  .endif
  m2z CHRW ptr [rdx]                                    ;Set ZTC
  ret
StrMidW endp

end
