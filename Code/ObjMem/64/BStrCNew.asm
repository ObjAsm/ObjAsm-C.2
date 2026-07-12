; ==================================================================================================
; Title:      BStrCNew.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - Initial release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMemWin.cop

; --------------------------------------------------------------------------------------------------
; Procedure:  BStrCNew
; Purpose:    Allocate a new copy of the source BSTR with length limitation.
;             If the pointer to the source string is NULL, BStrCNew returns NULL and doesn't
;             allocate any space. Otherwise, StrCNew makes a duplicate of the source string.
;             The maximal size of the new string is limited to the second parameter.
; Arguments:  Arg1: -> Source BSTR.
;             Arg2: Maximal character count.
; Return:     rax -> New BSTR copy or NULL.

.code
align ALIGN_CODE
BStrCNew proc uses rbx rdi pBStr:POINTER, dMaxChars:DWORD   ;rcx -> DstBStr, edx = dMaxChars
  .if rcx == NULL
    xor eax, eax
  .else
    mov rdi, rcx                                        ; rdi = pBStr
    mov ecx, DWORD ptr [rcx - 4]
    shr ecx, 1                                          ; ecx = # chars
    cmp ecx, edx                                        ; edx = dMaxChars
    cmova ecx, edx
    mov ebx, ecx
    invoke BStrAlloc, ecx
    .if rax != NULL
      add ebx, ebx
      mov DWORD ptr [rax - 4], ebx
      mov rdx, rdi
      mov rdi, rax
      invoke MemClone, rdi, rdx, ebx                    ; Copy string with limit
      mov WORD ptr [rdi + rbx], 0                       ; Set ZTC
      mov rax, rdi
    .endif
  .endif
  ret
BStrCNew endp

end
