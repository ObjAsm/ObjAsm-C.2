; ==================================================================================================
; Title:      GetOption_X.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, July 2024
;               - First release.
;               - Bitness neutral code.
; ==================================================================================================


; --------------------------------------------------------------------------------------------------
; Procedure:  GetOption
; Purpose:    Process a single option.
; Arguments:  Arg1: -> Option definition table. See OPTION_ENTRY definition.
;             Arg2: -> Application options storage.
;             Arg3: -> Argument (WIDE string), e.g. "/Verbosity:1"
; Return:     eax: TRUE if succeeded, otherwise FALSE.
; Note:       String options are WIDE and must be disposed using StrDispose when no longer needed.
;             Char options are of type CHRW.

.code
align ALIGN_CODE
GetOption proc uses xbx xdi xsi, pOptDefTable:POPTION_ENTRY, pStorage:POINTER, pOption:PSTRINGW
  .const
  GetOptionJumpTable label POINTER                      ;Build a jump table
  POINTER @CatStr(<@@>, OPT_IS_BOOL)
  POINTER @CatStr(<@@>, OPT_IS_BIT)
  POINTER @CatStr(<@@>, OPT_IS_CHAR)
  POINTER @CatStr(<@@>, OPT_IS_DECIMAL)
  POINTER @CatStr(<@@>, OPT_IS_STRING)

  .code
  mov xsi, pOptDefTable
  .while TRUE
    mov xdx, [xsi].OPTION_ENTRY.pSwitch                 ;E.g.: "/Verbosity:" 
    cmp xdx, NULL
    jz @@Error                                          ;Not found!
    mov ebx, [xdx - sizeof(DWORD)]                      ;Get switch size in bytes, not including the ZTC
    .if [xsi].OPTION_ENTRY.bType == OPT_IS_BOOL
      add ebx, sizeof CHRW                              ;Include the ZTC to make sure that nothing
    .endif                                              ;   else comes after it
    invoke MemComp, pOption, xdx, ebx
    .break .if eax == 0
    add xsi, sizeof(OPTION_ENTRY)
  .endw

  movzx eax, [xsi].OPTION_ENTRY.bType
  mov xdi, [xsi].OPTION_ENTRY.xOffset
  add xdi, pStorage
  lea xcx, GetOptionJumpTable
  mov xsi, pOption
  jmp POINTER ptr [xcx + xax*sizeof(POINTER)]

  @CatStr(<@@>, OPT_IS_BOOL):
    mov BYTE ptr [xdi], TRUE
    mov eax, TRUE
    jmp @@Exit

  @CatStr(<@@>, OPT_IS_BIT):
    mov ecx, DCHRW ptr [xsi + xbx]                      ;Include the next char too, should be the ZTC
    sub ecx, "0"
    cmp ecx, 10                                         ;If it is not the ZTC, then ecx > 10
    jae @@Error                                         ;Unsigned
    mov eax, 1
    shl eax, cl
    or DWORD ptr [xdi], eax
    mov eax, TRUE
    jmp @@Exit

  @CatStr(<@@>, OPT_IS_CHAR):
    m2m CHRW ptr [xdi], [xsi + xbx], cx
    mov eax, TRUE
    jmp @@Exit

  @CatStr(<@@>, OPT_IS_DECIMAL):
    invoke dec2dwordW, addr [xsi + xbx]
    mov DWORD ptr [xdi], eax
    mov eax, TRUE
    jmp @@Exit

  @CatStr(<@@>, OPT_IS_STRING):
    invoke PathUnquoteSpacesW, addr [xsi + xbx]
    invoke StrNewW, addr [xsi + xbx]                    ;Create a copy
    mov POINTER ptr [xdi], xax
    mov eax, TRUE
    jmp @@Exit

@@Error:
  xor eax, eax
@@Exit:
  ret
GetOption endp
