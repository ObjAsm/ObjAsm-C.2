; ==================================================================================================
; Title:      GetOptions_X.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, July 2024
;               - First release.
;               - Bitness neutral code.
; ==================================================================================================


; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  GetOptions
; Purpose:    Scan argument list for options.
; Arguments:  Arg1: -> Option definition table.
;             Arg2: -> Application options storage.
;             Arg3: -> List of WIDE string arguments. The list must be finished with a NULL POINTER.
; Return:     eax: TRUE if succeeded, otherwise FALSE.
;             ecx: failed option index.
;             xdx: -> failed WIDE string argument.

.code
align ALIGN_CODE
GetOptions proc uses xbx xsi, pOptDefTable:POPTION_ENTRY, pStorage:POINTER, pOptionList:PSTRINGW
  mov xsi, pOptionList
  xor ebx, ebx
  .while PSTRINGW ptr [xsi] != NULL
    invoke GetOption, pOptDefTable, pStorage, PSTRINGW ptr [xsi]
    .if eax == FALSE
      mov xdx, PSTRINGW ptr [xsi]
      mov ecx, ebx
      xor eax, eax
      jmp @@Exit
    .endif
    inc ebx
    add xsi, sizeof(PSTRINGW)
  .endw
  mov eax, TRUE
@@Exit:
  ret
GetOptions endp
