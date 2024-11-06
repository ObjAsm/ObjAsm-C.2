; ==================================================================================================
; Title:      StrCCompW.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
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
StrCCompW proc pStr1W:POINTER, pStr2W:POINTER, dMaxChars:DWORD
  ;rcx -> Str1A, rdx -> Str2A, r8d = dMaxChars
  xor eax, eax
  inc r8d
@@Char:
  dec r8d
  jnz @@Next
  xor eax, eax                                          ;eax = 0 (same string)
  ret                                                   ;Return
@@Next:
  mov ax, [rcx]                                         ;Load char to compare
  test ax, ax                                           ;Test end of string
  jz @@Eq?                                              ;Compute result
  cmp ax, [rdx]                                         ;Compare with the char of the other string
  jnz @@Eq?                                             ;Chars are not equal
  add rcx, sizeof(CHRW)                                 ;Goto for next char
  add rdx, sizeof(CHRW)
  jmp @@Char
@@Eq?:
  movzx ecx, CHRW ptr [rdx]                             ;Get char
  sub eax, ecx                                          ;Subtract to see which is lower
  ret                                                   ;Return
StrCCompW endp

OPTION PROC:DEFAULT

end
