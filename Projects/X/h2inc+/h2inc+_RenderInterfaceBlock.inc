; ==================================================================================================
; Title:      h2inc+_RenderInterfaceBlock.inc
; Author:     G. Friedrich
; Version:    See h2inc+.asm
; Purpose:    ObjAsm h2inc+ translation procedures.
; ==================================================================================================


.code

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  RenderInterfaceBlock
; Purpose:    Translate all members of a block (structure, union, enum).
; Arguments:  Arg1 -> Name.
;             xax -> '{'
;             xbx -> IncFile.
; Return:     xax -> Last Token or NULL if failed.
; Link:       https://devblogs.microsoft.com/oldnewthing/20200909-00/?p=104198

RenderInterfaceBlock proc pName:PSTRINGA
  mov [xbx].$Obj(IncFile).bInsideInterface, TRUE
  .repeat
    invoke RenderTypedefFuncPtr, NULL
    jz @Error
    invoke RenderContainerMember, xax, pName
    .break .if xax == NULL
    .if CHRA ptr [xax] == ";"
      OCall xbx::IncFile.PeekNextTokenC
      .break .if ZERO?
      .if CHRA ptr [xax] == "}"
        OCall xbx::IncFile.GetNextTokenC               ;Consume it
        .break
      .endif
    .else
      jmp @Error
    .endif
  .until FALSE
  mov [xbx].$Obj(IncFile).bInsideInterface, FALSE
  ret

@Error:
  DbgPrintF , "¦UD: RenderInterfaceBlock - ¦SA, end of struct found [¦UD]", [xbx].$Obj(IncFile).dLineNumber, pName, eax
  mov [xbx].$Obj(IncFile).bInsideInterface, FALSE
  xor eax, eax
  ret
RenderInterfaceBlock endp