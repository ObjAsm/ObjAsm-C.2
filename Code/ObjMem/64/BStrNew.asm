; ==================================================================================================
; Title:      BStrNew.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMemWin.cop

; --------------------------------------------------------------------------------------------------
; Procedure:  BStrNew
; Purpose:    Allocate an new copy of the source BStr.
;             If the pointer to the source string is NULL or points to an empty string, BStrNew
;             returns NULL and doesn't allocate any heap space. Otherwise, BStrNew makes a duplicate
;             of the source string.
;             The allocated space is Length(String) + 1 character.
; Arguments:  Arg1: -> Source BStr.
; Return:     rax -> New BStr copy or NULL.

.code
align ALIGN_CODE
BStrNew proc uses rdi pBStr:POINTER
  .if rcx == NULL
    xor eax, eax
  .else
    mov rdi, rcx
    mov ecx, DWORD ptr [rcx - 4]
    shr ecx, 1
    invoke BStrAlloc, ecx
    .if rax != NULL
      mov rdx, rdi
      mov rdi, rax
      invoke BStrCopy, rax, rdx
      mov rax, rdi
    .endif
  .endif
  ret
BStrNew endp

end
