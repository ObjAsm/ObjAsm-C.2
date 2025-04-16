; ==================================================================================================
; Title:      StrCCompA.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
% include &ObjMemPath&ObjMemWin.cop

; --------------------------------------------------------------------------------------------------
; Procedure:  StrCCompA
; Purpose:    Compare 2 ANSI strings with case sensitivity up to a maximal number of characters.
; Arguments:  Arg1: -> ANSI string 1.
;             Arg2: -> ANSI string 2.
;             Arg3: Maximal number of characters to compare.
; Return:     If string 1 < string 2, then eax < 0.
;             If string 1 = string 2, then eax = 0.
;             If string 1 > string 2, then eax > 0.

OPTION PROC:NONE

.code
align ALIGN_CODE
StrCCompA proc pString1A:POINTER, pString2A:POINTER, dMaxChars:DWORD
  push ebx                                              ;Save ebx
  mov ecx, [esp + 8]                                    ;ecx -> String1A
  xor eax, eax
  mov edx, [esp + 12]                                   ;edx -> String2A
  mov ebx, [esp + 16]
  inc ebx
align ALIGN_CODE
@@Char:
  dec ebx
  jnz @@Next
  xor eax, eax                                          ;eax = 0 (same string)
  pop ebx                                               ;Restore ebx
  ret 12                                                ;Return
align ALIGN_CODE
@@Next:
  mov al, [ecx]                                         ;Load char to compare
  test al, al                                           ;Test if end of string
  jz @@Eq?                                              ;Compute result
  cmp al, [edx]                                         ;Compare with the char of the other string
  jnz @@Eq?                                             ;Chars are not equal
  inc ecx                                               ;Goto for next char
  inc edx
  jmp @@Char
align ALIGN_CODE
@@Eq?:
  movzx ecx, BYTE ptr [edx]                             ;Get char
  sub eax, ecx                                          ;Subtract to see which is lower
  pop ebx                                               ;Restore ebx
  ret 12                                                ;Return
StrCCompA endp

OPTION PROC:DEFAULT

end
