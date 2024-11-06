; ==================================================================================================
; Title:      StrRScanW.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMemWin.cop

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  StrRScanW
; Purpose:    Scan from the end of a WIDE string for a character.
; Arguments:  Arg1: -> Source WIDE string.
;             Arg2: Character to search for.
; Return:     rax -> Character address or NULL if not found.

.code
align ALIGN_CODE
StrRScanW proc uses rbx rdi pStringW:POINTER, wChar:CHRW
  mov rdi, rcx
  mov rbx, rdx
  invoke StrLengthW, rcx                                ;pStringW
  test rax, rax
  je @@Exit                                             ;Lenght = 0
  std
  mov rcx, rax
  lea rdi, [rdi + 2*rax - 2]
  mov ax, bx                                            ;ax = wChar
  repne scasw
  mov rax, NULL                                         ;Don't change flags!
  jne @F
  lea rax, [rdi + sizeof(CHRW)]
@@:
  cld
@@Exit:
  ret
StrRScanW endp

end
