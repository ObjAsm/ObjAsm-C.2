; ==================================================================================================
; Title:      BStrCScan.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - Initial release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMemWin.cop

; --------------------------------------------------------------------------------------------------
; Procedure:  BStrCScan
; Purpose:    Scan from the beginning of a BSTR for a character with length limitation.
; Arguments:  Arg1: -> Source WIDE string.
;             Arg2: Maximal character count.
;             Arg3: WIDE character to search for.
; Return:     rax -> Character address or NULL if not found.

OPTION PROC:NONE

.code
align ALIGN_CODE
BStrCScan proc pBStr:POINTER, dMaxChars:DWORD, wChar:WORD
  push rdi 
  ;rcx -> BSTR, edx = dMaxChars, r8w = wChar  
  mov eax, [rcx - 4]                                    ; eax = BSTR byte size
  .if eax != 0                                          ; Size = 0 ?
    shr eax, 1                                          ; eax (counter) = char length
    mov r9d, eax                                         
    cmp eax, edx                                        ; edx = dMaxChars
    sbb r10, r10
    and r9, r10
    not r10
    and edx, r10d
    or r9d, edx                                         ; r9 = min(edx, eax)
    mov ax, r8w                                         ; Load wChar
    mov rdi, rcx                                        ; rdi = BSTR pointer (save before rcx is reused)
    mov ecx, r9d                                        ; rcx = scan count
    repne scasw
    mov rax, NULL                                       ; Don't change flags!
    jne @F
    lea rax, [rdi - 2]
  .endif
@@:
  pop rdi
  ret
BStrCScan endp

OPTION PROC:DEFAULT

end
