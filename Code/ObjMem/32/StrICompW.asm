; ==================================================================================================
; Title:      StrICompW.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
% include &ObjMemPath&ObjMemWin.cop

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure: StrICompW
; Purpose:   Compare 2 WIDE strings without case sensitivity.
; Arguments: Arg1: -> Wide string 1.
;            Arg2: -> Wide string 2.
; Return:    If string 1 < string 2, then eax < 0.
;            If string 1 = string 2, then eax = 0.
;            If string 1 > string 2, then eax > 0.

OPTION PROC:NONE

.code
align ALIGN_CODE
StrICompW proc pString1W:POINTER, pString2W:POINTER
  mov ecx, [esp + 4]                                    ;ecx -> String1W
  mov edx, [esp + 8]                                    ;edx -> String2W
  push edi
  xor edi, edi
  xor eax, eax
align ALIGN_CODE                                        ;This line is 4 BYTEs aligned
@@Char:
  mov ax, [edi + ecx]                                   ;Load char to compare
  test ax, ax                                           ;Test if end of string
  jz @@Eq?                                              ;Compute result
  cmp ax, [edi + edx]                                   ;Compare with the char of the other string
  jnz @@ICmp                                            ;Chars are not equal, check if for capitals
  add edi, 2                                            ;Goto for next char
  jmp @@Char
align ALIGN_CODE
@@ICmp:
  cmp ax, 'z'                                           ;Check range 'A'..'Z' or 'a'..'z'
  ja @@Eq?
  cmp ax, 'A'
  jb @@Eq?
  cmp ax, 'a'
  jae @@1
  cmp ax, 'Z'
  ja @@Eq?
@@1:
  xor ax, 20h                                           ;Swap lowercase - uppercase
  cmp ax, [edi + edx]                                   ;Compare again
  jne @@2                                               ;If not equal, compute result
  add edi, 2                                            ;Goto for next char
  jmp @@Char
@@2:
  and ax, not 20h                                       ;Make uppercase
@@Eq?:
  movzx ecx, WORD ptr [edi + edx]                       ;Get char
  cmp cx, 'a'                                           ;Check range 'a'..'z'
  jb @@Exit
  cmp cx, 'z'
  ja @@Exit
  and cx, not 20h                                       ;Make uppercase
@@Exit:
  sub eax, ecx                                          ;Subtract to see which is smaller
  pop edi
  ret 8
StrICompW endp

OPTION PROC:DEFAULT

end
