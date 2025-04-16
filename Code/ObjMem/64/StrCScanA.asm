; ==================================================================================================
; Title:      StrCScanA.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMemWin.cop

; --------------------------------------------------------------------------------------------------
; Procedure:  StrCScanA
; Purpose:    Scan from the beginning of ANSI string for a character with length limitation.
; Arguments:  Arg1: -> Source ANSI string.
;             Arg2: Maximal character count.
;             Arg3: ANSI character to search for.
; Return:     rax -> Character address or NULL if not found.

.code
align ALIGN_CODE
StrCScanA proc uses rdi pStringA:POINTER, dMaxCount:DWORD, bChar:CHRA
  mov rdi, rcx
  invoke StrLengthA, rcx                                ;pStringA
  .if eax != 0
    mov rcx, rax                                        ;rcx (counter) = length
    mov rax, rdx                                        ;rax = dMaxCount
    cmp rcx, rax
    sbb rdx, rdx
    and rcx, rdx
    not rdx
    and rax, rdx
    or rcx, rax                                         ;rcx = min(rcx, rax)
    mov al, bChar
    repne scasb
    mov rax, NULL                                       ;Dont't change flags!
    .if ZERO?                                           ;Found!
      lea rax, [rdi - sizeof(CHRA)]
    .endif
  .endif
  ret
StrCScanA endp

end
