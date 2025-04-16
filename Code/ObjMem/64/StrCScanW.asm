; ==================================================================================================
; Title:      StrCScanW.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMemWin.cop

; --------------------------------------------------------------------------------------------------
; Procedure:  StrCScanW
; Purpose:    Scan from the beginning of a WIDE string for a character with length limitation.
; Arguments:  Arg1: -> Source WIDE string.
;             Arg2: Maximal character count.
;             Arg3: WIDE character to search for.
; Return:     rax -> Character address or NULL if not found.

.code
align ALIGN_CODE
StrCScanW proc uses rdi pStringW:POINTER, dMaxCount:DWORD, wChar:CHRW
  mov rdi, rcx                                          ;pStringW
  invoke StrLengthW, rcx                                ;pStringW
  .if eax != 0
    mov rcx, rax                                        ;rcx (counter) = length
    mov eax, dMaxCount
    cmp rcx, rax
    sbb rdx, rdx
    and rcx, rdx
    not rdx
    and rax, rdx
    or rcx, rax                                         ;rcx = min(rcx, rax)
    mov ax, wChar
    repne scasw
    mov rax, NULL                                       ;Dont't change flags!
    .if ZERO?                                           ;Found!
      lea rax, [rdi - sizeof(CHRW)]
    .endif
  .endif
  ret
StrCScanW endp

end
