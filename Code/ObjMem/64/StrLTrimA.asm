; ==================================================================================================
; Title:      StrLTrimA.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017.
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMemWin.cop

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  StrLTrimA
; Purpose:    Trim blank characters from the beginning of an ANSI string.
; Arguments:  Arg1: -> Destination ANSI character buffer.
;             Arg2: -> Source ANSI string.
; Return:     Nothing.

.code
align ALIGN_CODE
StrLTrimA proc uses rbx pBuffer:POINTER, pSrcStringA:POINTER
@@:
  mov al, [rdx]
  inc rdx
  cmp al, ' '                                           ;Loop if space
  je @B
  cmp al, 9                                             ;Loop if tab
  je @B
  cmp al, 0                                             ;Return empty string if zero
  jne @F
  mov [rcx], al                                         ;rcx -> Buffer
  ret
@@:
  dec rdx
  mov rbx, rdx
  invoke StrSizeA, rdx
  invoke MemClone, pBuffer, rbx, eax
  ret
StrLTrimA endp

end
