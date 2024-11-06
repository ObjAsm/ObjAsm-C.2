; ==================================================================================================
; Title:      GetObjectTemplate_XP.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017.
;               - First release.
;               - Bitness and platform independent code.
; ==================================================================================================


externdef p1stOMD:POINTER

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  GetObjectTemplate
; Purpose:    Get the template address of an object type ID.
; Arguments:  Arg1: Object type ID.
; Return:     xax -> Object template or NULL if not found.
;             ecx = Object template size or zero if not found.

.code
align ALIGN_CODE
GetObjectTemplate proc dObjectID:DWORD
  mov eax, dObjectID
  .if eax != 0
    mov xdx, p1stOMD                                        ;Load first -> Object Metadata
    .while xdx != NULL                                      ;End of List? If YES => return 0
      mov xcx, [xdx + sizeof(POINTER) + sizeof(XWORD)]      ;xcx -> DMT entry
      mov xcx, [xcx - sizeof(POINTER)]                      ;xcx -> ETT count
      .if eax == [xcx - 2*sizeof(DWORD)]                    ;check for matching object ID
        mov ecx, [xdx + sizeof(POINTER)]                    ;ecx = sizeof(TPL)
        lea xax, [xdx + sizeof(POINTER) + sizeof(XWORD)]    ;xax -> object template
        ret
      .else
        mov xdx, [xdx]                                      ;Move to next object metadata block
      .endif
    .endw
    xor eax, eax
  .endif
  xor ecx, ecx
  ret
GetObjectTemplate endp
