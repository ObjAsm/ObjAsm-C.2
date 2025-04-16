; ==================================================================================================
; Title:      StrICompW.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMemWin.cop

; --------------------------------------------------------------------------------------------------
; Procedure:  StrICompW
; Purpose:    Compare 2 WIDE strings without case sensitivity.
; Arguments:  Arg1: -> WIDE string 1.
;             Arg2: -> WIDE string 2.
; Return:     If string 1 < string 2, then eax < 0.
;             If string 1 = string 2, then eax = 0.
;             If string 1 > string 2, then eax > 0.

OPTION PROC:NONE

.code
align ALIGN_CODE
StrICompW proc pStr1W:POINTER, pStr2W:POINTER
  xor r8, r8
  xor eax, eax
@@Char:
  mov ax, [rcx + r8]                                    ;Load char to compare
  test ax, ax                                           ;Test if end of string
  jz @@Eq?                                              ;Compute result
  cmp ax, [rdx + r8]                                    ;Compare with the char of the other string
  jnz @@ICmp                                            ;Chars are not equal, check if for capitals
  add r8, sizeof(CHRW)                                  ;Goto for next char
  jmp @@Char
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
  cmp ax, [rdx + r8]                                    ;Compare again
  jne @@2                                               ;If not equal, compute result
  add r8, sizeof(CHRW)                                  ;Goto for next char
  jmp @@Char
@@2:
  and ax, not 20h                                       ;Make uppercase
@@Eq?:
  movzx ecx, WORD ptr [rdx + r8]                        ;Get char
  cmp cx, 'a'                                           ;Check range 'a'..'z'
  jb @@Exit
  cmp cx, 'z'
  ja @@Exit
  and cx, not 20h                                       ;Make uppercase
@@Exit:
  sub eax, ecx                                          ;Subtract to see which is smaller
  ret
StrICompW endp

OPTION PROC:DEFAULT

end
