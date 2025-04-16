; ==================================================================================================
; Title:      BStrCNew.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMemWin.cop

; --------------------------------------------------------------------------------------------------
; Procedure:  BStrCNew
; Purpose:    Allocate a new copy of the source BStr with length limitation.
;             If the pointer to the source string is NULL, BStrCNew returns NULL and doesn't
;             allocate any space. Otherwise, StrCNew makes a duplicate of the source string.
;             The maximal size of the new string is limited to the second parameter.
; Arguments:  Arg1: -> Source BStr.
;             Arg2: Maximal character count.
; Return:     rax -> New BStr copy or NULL.

.code
align ALIGN_CODE
BStrCNew proc uses rdi pBStr:POINTER, dMaxChars:DWORD   ;rcx -> DstBStr, edx = dMaxChars
  .if rcx == NULL
    xor eax, eax
  .else
    mov rdi, rcx
    mov ecx, DWORD ptr [rcx - 4]
    shr ecx, 1
    cmp rcx, rdx
    cmova rcx, rdx
    invoke BStrAlloc, ecx
    .if rax != NULL
      mov rdx, rdi
      mov rdi, rax
      invoke BStrCopy, rax, rdx
      mov rax, rdi
    .endif
  .endif
  ret
BStrCNew endp

end
