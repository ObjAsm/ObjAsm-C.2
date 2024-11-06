; ==================================================================================================
; Title:      StrLTrimW.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMemWin.cop

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  StrLTrimW
; Purpose:    Trim blank characters from the beginning of a WIDE string.
; Arguments:  Arg1: -> Destination WIDE character buffer.
;             Arg2: -> Source WIDE string.
; Return:     Nothing.

.code
align ALIGN_CODE
StrLTrimW proc uses rbx pBuffer:POINTER, pSrcStringW:POINTER
@@:
  mov ax, [rdx]
  add rdx, sizeof(CHRW)
  cmp ax, ' '                                           ;Loop if space
  je @B
  cmp ax, 9                                             ;Loop if tab
  je @B
  cmp ax, 0                                             ;Return empty string if zero
  jne @F
  mov [rcx], ax                                         ;rcx -> Buffer
  ret
@@:
  sub rdx, sizeof(CHRW)
  mov rbx, rdx
  invoke StrSizeW, rdx
  invoke MemClone, pBuffer, rbx, eax
  ret
StrLTrimW endp

end
