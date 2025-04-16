; ==================================================================================================
; Title:      StrICompA.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
% include &ObjMemPath&ObjMemWin.cop

; --------------------------------------------------------------------------------------------------
; Procedure:  StrICompA
; Purpose:    Compare 2 ANSI strings without case sensitivity.
; Arguments:  Arg1: -> ANSI string 1.
;             Arg2: -> ANSI string 2.
; Return:     If string 1 < string 2, then eax < 0.
;             If string 1 = string 2, then eax = 0.
;             If string 1 > string 2, then eax > 0.

OPTION PROC:NONE

.code
align ALIGN_CODE
StrICompA proc pString1A:POINTER, pString2A:POINTER
  mov ecx, [esp + 4]                                    ;ecx -> String1A
  mov edx, [esp + 8]                                    ;edx -> String2A
  push edi
  xor edi, edi
  xor eax, eax
align ALIGN_CODE                                        ;This line is 4 BYTEs aligned
@@Char:
  mov al, [edi + ecx]                                   ;Load char to compare
  test al, al                                           ;Test if end of string
  jz @@Eq?                                              ;Compute result
  cmp al, [edi + edx]                                   ;Compare with the char of the other string
  jnz @@ICmp                                            ;Chars are not equal, check if for capitals
  inc edi                                               ;Goto for next char
  jmp @@Char
align ALIGN_CODE
@@ICmp:
  cmp al, 'z'                                           ;Check range 'A'..'Z' or 'a'..'z'
  ja @@Eq?
  cmp al, 'A'
  jb @@Eq?
  cmp al, 'a'
  jae @@1
  cmp al, 'Z'
  ja @@Eq?
@@1:
  xor al, 20h                                           ;Swap lowercase - uppercase
  cmp al, [edi + edx]                                   ;Compare again
  jne @@2                                               ;If not equal, compute result
  inc edi                                               ;Goto for next char
  jmp @@Char
@@2:
  and al, not 20h                                       ;Make uppercase
@@Eq?:
  movzx ecx, BYTE ptr [edi + edx]                       ;Get char
  cmp cl, 'a'                                           ;Check range 'a'..'z'
  jb @@Exit
  cmp cl, 'z'
  ja @@Exit
  and cl, not 20h                                       ;Make uppercase
@@Exit:
  sub eax, ecx                                          ;Subtract to see which is smaller
  pop edi
  ret 8
StrICompA endp

OPTION PROC:DEFAULT

end
