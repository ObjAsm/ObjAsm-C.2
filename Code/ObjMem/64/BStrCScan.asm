; ==================================================================================================
; Title:      BStrCScan.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMemWin.cop

; --------------------------------------------------------------------------------------------------
; Procedure:  BStrCScan
; Purpose:    Scan from the beginning of a BStr for a character with length limitation.
; Arguments:  Arg1: -> Source WIDE string.
;             Arg2: Maximal character count.
;             Arg3: WIDE character to search for.
; Return:     rax -> Character address or NULL if not found.

OPTION PROC:NONE

.code
align ALIGN_CODE
BStrCScan proc pBStr:POINTER, dMaxChars:DWORD, wChar:WORD
  push rdi 
  ;rcx -> BStr, edx = dMaxChars, r8w = wChar  
  mov eax, [rcx - 4]                                    ;eax = BStr byte size
  test eax, eax                                         ;Size = 0 ?
  jz @F                                                 ;Return NULL
  shr eax, 1                                            ;eax (counter) = char length
  mov r9d, eax                                         
  cmp eax, edx                                          ;edx = dMaxChars
  sbb r10, r10
  and r9, r10
  not r10
  and eax, r10d
  or r9d, eax                                           ;r9 = min(edx, eax)
  mov ax, r8w                                           ;load wChar
  mov rdi, rcx
  repne scasw
  mov rax, NULL                                         ;Dont't change flags!
  jne @F
  lea rax, [rcx - 2]
@@:
  pop rdi
  ret
BStrCScan endp

OPTION PROC:DEFAULT

end
