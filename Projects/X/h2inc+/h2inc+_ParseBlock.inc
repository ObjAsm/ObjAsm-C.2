; ==================================================================================================
; Title:      h2inc+_ParseBlock.inc
; Author:     G. Friedrich
; Version:    See h2inc+.asm
; Purpose:  
; ==================================================================================================


.code

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  ParseBlock
; Purpose:    Get members of a block (structure, union, enum).
; Arguments:  Arg1 -> Name.
;             Arg2: Mode.
;               PBT_CONTAINER: variable declaration in (struct|union)
;               PBT_EXTERN: extern declaration.
;               PBT_ENUM: enum declaration.
;             xbx -> IncFile.
; Return:     xax -> Last Token or NULL if failed.

ParseBlock proc uses xsi pName:PSTRINGA, dMode:DWORD
  local wIf:WORD

  movzx eax, [xbx].$Obj(IncFile).bIfLevel
  mov ah, [xbx].$Obj(IncFile).bIfStructure[xax - 1]
  mov wIf, ax

  mov esi, 1
  .repeat
    OCall xbx::IncFile.GetNextToken
    .break .if ZERO?
    invoke SkipAnnotations, xax
    .break .if ZERO?

    movzx ecx, [xbx].$Obj(IncFile).bIfLevel
    mov ch, [xbx].$Obj(IncFile).bIfStructure[xcx - 1]
    .if (cl == BYTE ptr wIf) && (ch != BYTE ptr wIf + 1)
      mov [xbx].$Obj(IncFile).pPrevToken, xax
      mov [xbx].$Obj(IncFile).bUsePrevToken, TRUE
      xor xax, xax
      jmp @Exit
    .endif

    .if CHRA ptr [xax] == "{"
      inc esi
      .continue

    .elseif CHRA ptr [xax] == "}"
      dec esi

    .else
      .if dMode == PBT_ENUM
        invoke ParseEnumItem, xax

      .elseif dMode == PBT_CONTAINER
        invoke ParseContainerItem, xax, pName

      .else
        invoke ParseExternItem, xax
      .endif

      .break .if xax == NULL
      .if CHRA ptr [xax] == "}"
        dec esi
      .endif
    .endif
  .until esi == 0

@Exit:
  DbgPrintF , "¦UD: ParseBlock - ¦SA, end of struct found [¦UD]", [xbx].$Obj(IncFile).dLineNumber, pName, eax
  ret
ParseBlock endp

