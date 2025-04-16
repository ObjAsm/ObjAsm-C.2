; ==================================================================================================
; Title:      StrCNew_T64P.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, June 2022
;               - First release.
; ==================================================================================================


; --------------------------------------------------------------------------------------------------
; Procedure:  StrCNewA / StrCNewW / StrCNewA_UEFI / StrCNewW_UEFI
; Purpose:    Allocate a new copy of the source string with length limitation.
;             If the pointer to the source string is NULL or points to an empty string, StrCNew
;             returns NULL and doesn't allocate any memory space. Otherwise, StrCNew makes a
;             duplicate of the source string. The maximal size of the new string is limited to the
;             second parameter.
; Arguments:  Arg1: -> Source string.
;             Arg2: Maximal character count.
; Return:     rax -> New string copy.

.code
align ALIGN_CODE
ProcName proc uses rbx rdi pString:POINTER, dMaxChars:DWORD
  mov rax, rcx                                          ;rax -> String
  test rax, rax                                         ;Is NULL => fail
  jz @F
  invoke StrCLength, rax, edx
  mov ebx, eax
  invoke StrAlloc, eax
  test rax, rax
  jz @F                                                 ;Allocation failed
  if TARGET_STR_TYPE eq STR_TYPE_WIDE
    shl rbx, 1
  endif
  m2z CHR ptr [rax + rbx]                               ;Set ZTC
  mov rdi, rax
  invoke MemClone, rax, pString, ebx                    ;Copy the source string
  mov rax, rdi
@@:
  ret
ProcName endp

