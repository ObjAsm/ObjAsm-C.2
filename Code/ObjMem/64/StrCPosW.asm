; ==================================================================================================
; Title:      StrCPosW.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMemWin.cop

; --------------------------------------------------------------------------------------------------
; Procedure:  StrCPosW
; Purpose:    Scan for WIDE string2 into WIDE string1 with length limitation.
; Arguments:  Arg1: -> Source WIDE string.
;             Arg2: -> WIDE string to search for.
;             Arg3: Maximal character count.
; Return:     rax -> String position or NULL if not found.

.code
align ALIGN_CODE
StrCPosW proc uses rbx rdi rsi pString1W:POINTER, pString2W:POINTER, dMaxChars:DWORD
  invoke StrLengthW, rdx                                ;pString2W -> searched string
  test eax, eax
  je @@Exit                                             ;Returns rax = NULL
  mov ebx, eax                                          ;ebx = length of the searched string

  invoke StrCLengthW, pString1W, dMaxChars              ;pString1A -> string to look in
  mov ecx, eax
  sub ecx, ebx
  inc ecx
  jb @@2

  mov rdi, pString1W
@@1:
  mov rsi, pString2W
  lodsw
  repne scasw                                           ;Search for first character
  jne @@2                                               ;Not found => Exit
  push rdi
  push rcx
  lea rcx, [rbx - 1]
  repe cmpsw                                            ;Check for the rest of the string
  pop rcx
  pop rdi
  jne @@1                                               ;Not equal => try next character
  lea rax, [rdi - 2]                                    ;Found, return position
  jmp @@Exit

@@2:
  xor eax, eax
@@Exit:
  ret
StrCPosW endp

end
