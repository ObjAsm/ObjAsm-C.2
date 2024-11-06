; ==================================================================================================
; Title:      StrRScanA.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMemWin.cop

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  StrRScanA
; Purpose:    Scan from the end of an ANSI string for a character.
; Arguments:  Arg1: -> Source ANSI string.
;             Arg2: Character to search for.
; Return:     rax -> Character address or NULL if not found.

.code
align ALIGN_CODE
StrRScanA proc uses rbx rdi pStringA:POINTER, bChar:CHRA
  mov rdi, rcx                                          ;rdi -> StringA
  mov rbx, rdx
  invoke StrLengthA, rcx                                ;pStringA
  test rax, rax
  je @@Exit                                             ;Lenght = 0
  std
  mov rcx, rax
  lea rdi, [rdi + rax - 1]
  mov al, bl                                            ;al = bChar
  repne scasb
  mov rax, NULL                                         ;Don't change flags!
  jne @F
  lea rax, [rdi + sizeof(CHRA)]
@@:
  cld
@@Exit:
  ret
StrRScanA endp

end
