; ==================================================================================================
; Title:      StrNew_TXP.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, June 2022
;               - First release.
;               - Character, bitness and platform independent code.
; ==================================================================================================


; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  StrNewA, StrNewW, StrNewA_UEFI, StrNewW_UEFI
; Purpose:    Allocate a new copy of the source string.
;             If the pointer to the source string is NULL, StrNew returns NULL and doesn't allocate
;             any memory space. Otherwise, StrNew makes a duplicate of the source string.
;             The allocated memory space is Length(String) + ZTC.
; Arguments:  Arg1: -> Source WIDE string.
; Return:     xax -> New string copy.

.code
align ALIGN_CODE
ProcName proc uses xbx xdi xsi pString:POINTER
  if TARGET_BITNESS eq 32
    mov eax, pString                                    ;eax -> String
  else
    mov rax, rcx                                        ;rax -> String
  endif
  test xax, xax                                         ;Is NULL => fail
  jz @F
  mov xsi, xax                                          ;xsi -> String
  invoke StrLength, xax
  lea ebx, [sizeof(CHR)*eax + sizeof(CHR)]              ;Include ZTC
  invoke StrAlloc, eax
  test xax, xax                                         ;Check allocation
  jz @F                                                 ;Allocation failed
  mov xdi, xax
  invoke MemClone, xax, xsi, ebx                        ;Copy the source string
  mov xax, xdi
@@:
  ret
ProcName endp

