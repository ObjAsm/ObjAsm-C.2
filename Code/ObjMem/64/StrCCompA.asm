; ==================================================================================================
; Title:      StrCCompA.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
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
StrCCompA proc pStr1A:POINTER, pStr2A:POINTER, dMaxChars:DWORD
  ;rcx -> Str1A, rdx -> Str2A, r8d = dMaxChars
  xor eax, eax
  inc r8d
@@Char:
  dec r8d
  jnz @@Next
  xor eax, eax                                          ;eax = 0 (same string)
  ret                                                   ;Return
@@Next:
  mov al, [rcx]                                         ;Load char to compare
  test al, al                                           ;Test end of string
  jz @@Eq?                                              ;Compute result
  cmp al, [rdx]                                         ;Compare with the char of the other string
  jnz @@Eq?                                             ;Chars are not equal
  inc rcx                                               ;Goto for next char
  inc rdx
  jmp @@Char
@@Eq?:
  movzx ecx, CHRA ptr [rdx]                             ;Get char
  sub eax, ecx                                          ;Subtract to see which is lower
  ret                                                   ;Return
StrCCompA endp

OPTION PROC:DEFAULT

end
