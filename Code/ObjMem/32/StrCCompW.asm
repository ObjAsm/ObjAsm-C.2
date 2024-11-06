; ==================================================================================================
; Title:      StrCCompW.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
% include &ObjMemPath&ObjMemWin.cop

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  StrCCompW
; Purpose:    Compare 2 WIDE strings with case sensitivity up to a maximal number of characters.
; Arguments:  Arg1: -> WIDE string 1.
;             Arg2: -> WIDE string 2.
;             Arg3: Maximal number of characters to compare.
; Return:     If string 1 < string 2, then eax < 0.
;             If string 1 = string 2, then eax = 0.
;             If string 1 > string 2, then eax > 0.

OPTION PROC:NONE

.code
align ALIGN_CODE
StrCCompW proc pString1W:POINTER, pString2W:POINTER, dMaxChars:DWORD
  push ebx                                              ;Save ebx
  mov ecx, [esp + 8]                                    ;ecx -> String1W
  xor eax, eax
  mov edx, [esp + 12]                                   ;edx -> String2W
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
  mov ax, [ecx]                                         ;Load char to compare
  test ax, ax                                           ;Test if end of string
  jz @@Eq?                                              ;Compute result
  cmp ax, [edx]                                         ;Compare with the char of the other string
  jnz @@Eq?                                             ;Chars are not equal
  add ecx, 2                                            ;Goto for next char
  add edx, 2
  jmp @@Char
align ALIGN_CODE
@@Eq?:
  movzx ecx, WORD ptr [edx]                             ;Get char
  sub eax, ecx                                          ;Subtract to see which is lower
  pop ebx                                               ;Restore ebx
  ret 12                                                ;Return
StrCCompW endp

OPTION PROC:DEFAULT

end
