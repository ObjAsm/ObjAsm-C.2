; ==================================================================================================
; Title:      StrPosA.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMemWin.cop

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  StrPosA
; Purpose:    Find the occurence of string 2 into string1.
; Arguments:  Arg1: -> Source ANSI string.
;             Arg2: -> Searched ANSI string.
; Return:     rax -> String occurence or NULL if not found.

.code
align ALIGN_CODE
StrPosA proc uses rbx rdi rsi pString1A:POINTER, pString2A:POINTER
  mov rdi, rcx                                          ;rdi -> String1A
  mov r10, rdx                                          ;rsi -> String2A
  
  invoke StrLengthA, rdx                                ;pString2A -> searched string
  test rax, rax
  je @@Exit                                             ;Returns eax = NULL
  mov rbx, rax                                          ;rbx = length of the searched string

  invoke StrLengthA, rdi                                ;pString1A -> string to look in
  mov rcx, rax
  sub rcx, rbx
  inc rcx
  jb @@2

@@1:
  mov rsi, r10
  lodsb
  repne scasb                                           ;Search for first character
  jne @@2                                               ;Not found => Exit
  mov r8, rdi
  mov r9, rcx
  lea rcx, [rbx - 1]
  repe cmpsb                                            ;Check for the rest of the string
  mov rcx, r9
  mov rdi, r8
  jne @@1                                               ;Not equal => try next character
  lea rax, [rdi - sizeof(CHRA)]                         ;Found, return position
  jmp @@Exit

@@2:
  xor eax, eax
@@Exit:
  ret
StrPosA endp

end
