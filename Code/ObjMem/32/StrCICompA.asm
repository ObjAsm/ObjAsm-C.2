; ==================================================================================================
; Title:      StrCICompA.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
% include &ObjMemPath&ObjMemWin.cop

; --------------------------------------------------------------------------------------------------
; Procedure:  StrCICompA
; Purpose:    Compare 2 ANSI strings without case sensitivity and length limitation.
; Arguments:  Arg1: -> ANSI string 1.
;             Arg2: -> ANSI string 2.
; Return:     If string 1 < string 2, then eax < 0.
;             If string 1 = string 2, then eax = 0.
;             If string 1 > string 2, then eax > 0.

OPTION PROC:NONE

.code
align ALIGN_CODE
StrCICompA proc pString1A:POINTER, pString2A:POINTER, dMaxChars:DWORD
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
  jnz @@ICmp                                            ;Chars are not equal, check if for capitals
  inc ecx                                               ;Goto for next char
  inc edx
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
  cmp al, [edx]                                         ;Compare again
  jne @@2                                               ;If not equal, compute result
  inc ecx                                               ;Goto for next char
  inc edx
  jmp @@Char
@@2:
  and al, not 20h                                       ;Make uppercase
@@Eq?:
  movzx ecx, BYTE ptr [edx]                             ;Get char
  cmp cl, 'a'                                           ;Check range 'a'..'z'
  jb @@Exit
  cmp cl, 'z'
  ja @@Exit
  and cl, not 20h                                       ;Make uppercase
@@Exit:
  sub eax, ecx                                          ;Subtract to see which is smaller
  pop ebx
  ret 12
StrCICompA endp

OPTION PROC:DEFAULT

end

