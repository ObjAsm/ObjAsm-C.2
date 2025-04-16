; ==================================================================================================
; Title:      StrCPosA.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMemWin.cop

; --------------------------------------------------------------------------------------------------
; Procedure:  StrCPosA
; Purpose:    Scan for ANSI string2 into ANSI string1 with length limitation.
; Arguments:  Arg1: -> Source ANSI string.
;             Arg2: -> ANSI string to search for.
;             Arg3: Maximal character count.
; Return:     rax -> String position or NULL if not found.

.code
align ALIGN_CODE
StrCPosA proc uses rbx rdi rsi pString1A:POINTER, pString2A:POINTER, dMaxChars:DWORD
  invoke StrLengthA, rdx                                ;pString2 -> searched string
  test eax, eax
  je @@Exit                                             ;Returns rax = NULL
  mov ebx, eax                                          ;ebx = length of the searched string

  invoke StrCLengthA, pString1A, dMaxChars              ;pString1A -> string to look in
  mov ecx, eax
  sub ecx, ebx
  inc ecx
  jb @@2

  mov rdi, pString1A
@@1:
  mov rsi, pString2A
  lodsb
  repne scasb                                           ;Search for first character
  jne @@2                                               ;Not found => Exit
  push rdi
  push rcx
  lea rcx, [rbx - 1]
  repe cmpsb                                            ;Check for the rest of the string
  pop rcx
  pop rdi
  jne @@1                                               ;Not equal => try next character
  lea rax, [rdi - 1]                                    ;Found, return position
  jmp @@Exit

@@2:
  xor eax, eax
@@Exit:
  ret
StrCPosA endp

end
