; ==================================================================================================
; Title:      StrLScanW.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMemWin.cop

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  StrLScanW
; Purpose:    Scan for a character from the beginning of a WIDE string. 
; Arguments:  Arg1: -> Source WIDE string.
;             Arg2: Character to search for.
; Return:     rax -> Character address or NULL if not found.

.code
align ALIGN_CODE
StrLScanW proc uses rbx rdi pStringW:POINTER, wChar:CHRW
  mov rbx, rdx
  mov rdi, rcx
  invoke StrLengthW, rdi                                ;pStringW
  test rax, rax                                         ;Lenght = 0 ?
  jz @F                                                 ;Return NULL
  mov rcx, rax                                          ;ecx (counter) = length
  mov ax, bx                                            ;Load wChar
  repne scasw
  mov eax, NULL                                         ;Dont't change flags!
  jne @F
  lea rax, [rdi - sizeof(CHRW)]
@@:
  ret
StrLScanW endp

end
