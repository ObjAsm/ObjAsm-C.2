; ==================================================================================================
; Title:      h2inc+_RenderFurtherTypes.inc
; Author:     G. Friedrich
; Version:    See h2inc+.asm
; Purpose:    ObjAsm h2inc+ translation procedures.
; ==================================================================================================


.code

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  RenderFurtherTypes
; Purpose:    Check out if there come some pointer definitions behind.
; Arguments:  Arg1 -> Type.
;             Arg2 -> Tag.
;             Arg3 -> Token
;             xbx -> IncFile.
; Return:     xax -> Next Token.

RenderFurtherTypes proc uses xdi pType:PSTRINGA, pTag:PSTRINGA, pToken:PTOKEN
  local dPtrCount:DWORD, pName:PSTRINGA, pCurrToken:PTOKEN, cTransBuffer[128]:CHRA

  mov dPtrCount, 0
  mov pName, NULL
  .while TRUE
    mov xax, pToken
    .if CHRA ptr [xax] == "," || CHRA ptr [xax] == ";"    ;Statement terminator
      .if pName != NULL
        mov pCurrToken, xax
        mov xdi, pType
        .if xdi == NULL
          mov xdi, pTag
        .endif
        DbgPrintF , "¦UD: RenderFurtherTypes - ¦SA ¦SA", [xbx].$Obj(IncFile).dLineNumber, pName, xdi
        ;Comment out forward declarations
        .if dPtrCount == 0
          invoke StrCompA, pName, xdi
          .if eax == 0
            OCall xbx::IncFile.StmWriteChar, ";"
          .endif
        .endif
        invoke TranslateReservedWord, pName, addr cTransBuffer
        mov pName, xax
        .if dPtrCount == 0
          IsStructure? xdi                              ;If the type is a structure, 
          .if eax != FALSE                              ;  then the new type is it too
            IsStructure? pName                          ;Check if it already exist
            .if eax == FALSE
              invoke StrLengthA, pName
              invoke InsertStrg, pStructs, pName, eax
            .endif
          .endif
        .endif

        OCall xbx::IncFile.StmWrite, pName
        OCall xbx::IncFile.StmWrite, $OfsCStrA(" typedef ")
        WritePtr
        OCall xbx::IncFile.StmWrite, xdi
        OCall xbx::IncFile.StmWriteEoL
        mov xax, pCurrToken
      .endif
      .break .if CHRA ptr [xax] == ";"                ;Statement terminator
      mov pName, NULL
      mov dPtrCount, 0
    .elseif CHRA ptr [xax] == "*"
      inc dPtrCount
    .else
      invoke TranslateTypeQualifier, pToken
      .if CHRA ptr [xax] != 0
        mov pName, xax
      .endif
    .endif
    OCall xbx::IncFile.GetNextTokenC
    jz @Error
    mov pToken, xax
  .endw
  .if pName != NULL
    OCall xbx::IncFile.StmWriteEoL
  .endif

  ret

@Error:
  DbgErrorF , "¦SU(¦UD): RenderFurtherTypes - error", [xbx].$Obj(IncFile).pHeaderFileName, [xbx].$Obj(IncFile).dLineNumber
  ret
RenderFurtherTypes endp
