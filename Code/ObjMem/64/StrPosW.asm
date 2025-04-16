; ==================================================================================================
; Title:      StrPosW.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMemWin.cop

; --------------------------------------------------------------------------------------------------
; Procedure:  StrPosW
; Purpose:    Find the occurence of string2 into string1.
; Arguments:  Arg1: -> Source WIDE string.
;             Arg2: -> Searched WIDE string.
; Return:     rax -> String occurence or NULL if not found.

.code
align ALIGN_CODE
StrPosW proc uses rbx rdi rsi pString1W:POINTER, pString2W:POINTER
  mov rdi, rcx                                          ;rdi -> String1W
  mov r10, rdx                                          ;rsi -> String2W

  invoke StrLengthW, rdx                                ;pString2W -> searched string
  test rax, rax
  je @@Exit                                             ;Returns eax = NULL
  mov rbx, rax                                          ;rbx = length of the searched string

  invoke StrLengthW, rdi                                ;pString1W -> string to look in
  mov rcx, rax
  sub rcx, rbx
  inc rcx
  jb @@2

@@1:
  mov rsi, r10                                          ;rsi -> pString2W
  lodsw
  repne scasw                                           ;Search for first character
  jne @@2                                               ;Not found => Exit
  mov r8, rdi
  mov r9, rcx
  lea rcx, [rbx - 1]
  repe cmpsw                                            ;Check for the rest of the string
  mov rcx, r9
  mov rdi, r8
  jne @@1                                               ;Not equal => try next character
  lea rax, [rdi - sizeof(CHRW)]                         ;Found, return position
  jmp @@Exit

@@2:
  xor eax, eax
@@Exit:
  ret
StrPosW endp

end
