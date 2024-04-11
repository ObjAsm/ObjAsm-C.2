; ==================================================================================================
; Title:      h2inc+_ParseInterfaceBlock.inc
; Author:     G. Friedrich
; Version:    See h2inc+.asm
; Purpose:  
; ==================================================================================================


.code

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  ParseInterfaceBlock
; Purpose:    Get members of a block (structure, union, enum).
; Arguments:  Arg1 -> Name.
;             xax -> '{'
;             xbx -> IncFile.
; Return:     xax -> Last Token or NULL if failed.

ParseInterfaceBlock proc pName:PSTRINGA
  mov [xbx].$Obj(IncFile).bInsideInterface, TRUE
  .repeat
    invoke ParseTypedefFunctionPtr, NULL
;    invoke ParseContainerItem, xax, pName
    .break .if xax == NULL
    .if CHRA ptr [xax] == ";"
      OCall xbx::IncFile.PeekNextToken
      .break .if xax == NULL
      .if CHRA ptr [xax] == "}"
        OCall xbx::IncFile.GetNextToken               ;Consume it
        .break
      .endif
    .else
      jmp @Error
    .endif
  .until FALSE
  mov [xbx].$Obj(IncFile).bInsideInterface, FALSE
  ret

@Error:
  DbgPrintF , "¦UD: ParseInterfaceBlock - ¦SA, end of struct found [¦UD]", [xbx].$Obj(IncFile).dLineNumber, pName, eax
  mov [xbx].$Obj(IncFile).bInsideInterface, FALSE
  xor eax, eax
  ret
ParseInterfaceBlock endp