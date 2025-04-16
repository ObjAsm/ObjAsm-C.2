; ==================================================================================================
; Title:      StrCICompW.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
% include &ObjMemPath&ObjMemWin.cop

; --------------------------------------------------------------------------------------------------
; Procedure:  StrCICompW
; Purpose:    Compare 2 WIDE strings without case sensitivity and length limitation.
; Arguments:  Arg1: -> Wide string 1.
;             Arg2: -> Wide string 2.
; Return:     If string 1 < string 2, then eax < 0.
;             If string 1 = string 2, then eax = 0.
;             If string 1 > string 2, then eax > 0.

OPTION PROC:NONE

.code
align ALIGN_CODE
StrCICompW proc pString1W:POINTER, pString2W:POINTER, dMaxLen:DWORD
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
  jnz @@ICmp                                            ;Chars are not equal, check if for capitals
  add ecx, 2                                            ;Goto for next char
  add edx, 2                                            
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
  cmp ax, [edx]                                         ;Compare again
  jne @@2                                               ;If not equal, compute result
  add ecx, 2                                            ;Goto for next char
  add edx, 2                                            
  jmp @@Char                                            
@@2:                                                    
  and ax, not 20h                                       ;Make uppercase
@@Eq?:                                                  
  movzx ecx, WORD ptr [edx]                             ;Get char
  cmp cx, 'a'                                           ;Check range 'a'..'z'
  jb @@Exit                                             
  cmp cx, 'z'                                           
  ja @@Exit                                             
  and cx, not 20h                                       ;Make uppercase
@@Exit:                                                 
  sub eax, ecx                                          ;Subtract to see which is smaller
  pop ebx
  ret 12
StrCICompW endp

OPTION PROC:DEFAULT

end
