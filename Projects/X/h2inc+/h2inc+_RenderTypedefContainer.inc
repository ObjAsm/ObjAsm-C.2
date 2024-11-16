; ==================================================================================================
; Title:      h2inc+_RenderTypedefContainer.inc
; Author:     G. Friedrich
; Version:    See h2inc+.asm
; Purpose:    ObjAsm h2inc+ translation procedures.
; ==================================================================================================


.code

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  RenderTypedefContainer
; Purpose:    Parse Typedef of a structure or union.
; Arguments:  Arg1: -> ContainerType (structure or union).
;             xbx -> IncFile.
; Return:     xax -> Last token or NULL if failed.
; Syntax:     typedef struct/union <macro> tname name;
;             typedef struct/union <macro> <tname> {} name;
;             typedef struct/union <macro> <tname> * name;

RenderTypedefContainer proc pContainerType:PSTRINGA
  local pName:PSTRINGA, pTag:PSTRINGA, pToken:PTOKEN, pEndToken:PTOKEN
  local pSuffix:PSTRINGA
  local bSkipName:DWORD, dPtrCount:DWORD
  local cName[MAX_NAME_CHARS]:CHRA, cStructName[MAX_NAME_CHARS]:CHRA, cNoName[64]:CHRA

  mov cStructName, 0
  mov cName, 0
  mov cNoName, 0
  mov pTag, NULL
  mov pName, NULL
  mov dPtrCount, 0
  OCall xbx::IncFile.GetNextTokenC
  invoke SkipAnnotations, xax
  test xax, xax
  jz @ErrorEoF
  invoke SkipMacros, xax
  test xax, xax
  jz @ErrorEoF

  .if CHRA ptr [xax] != '{'
    lea xdx, cName
    mov pTag, $invoke(TranslateReservedWord, xax, xdx)
    mov pName, xax
    OCall xbx::IncFile.GetNextTokenC
    test xax, xax
	  jz @ErrorEoF
  .endif

  .if CHRA ptr [xax] == '{'
    invoke GetBlockName, addr cStructName
    mov bSkipName, TRUE
    .if xax == NULL
      mov xax, pTag
      mov bSkipName, FALSE
    .endif

    ;No name at all?
    .if xax == NULL
      invoke wsprintfA, addr cNoName, $OfsCStrA("STRUCT_%u"), $ObjTmpl(Application).dStrucNameSuffix
      inc $ObjTmpl(Application).dStrucNameSuffix
      lea xax, cNoName
    .endif
    lea xdx, cName
    mov pName, $invoke(TranslateReservedWord, xax, xdx)
    IsStructure? pName
    .if eax == FALSE
      invoke StrLengthA, pName
      invoke InsertStrg, pNewStructs, pName, eax
    .endif
    lea xax, szEmpty
    mov pSuffix, xax

    OCall xbx::IncFile.StmWriteF, $OfsCStrA("%hs%hs %hs"), pName, pSuffix, pContainerType

    ;Get known structure alignment
    OCall pKnwAlignments::List.Search, pName
    .if eax != FALSE
      mov edx, ecx
      OCall pKnwAlignments::List.ItemAt, edx
      mov edx, [xax - sizeof(DWORD)]                    ;edx = length
      mov eax, [xax + xdx]
    .endif
    .if eax != 0
      OCall xbx::IncFile.StmWriteF, $OfsCStrA(" %u"), eax
    .elseif $ObjTmpl(Application).Options.bAddAlign != FALSE
      OCall xbx::IncFile.StmWrite, $OfsCStrA(" @Align")
    .endif
    OCall xbx::IncFile.StmWriteEoL

    inc [xbx].$Obj(IncFile).dIndentation
    invoke RenderBlock, pName, RBT_CONTAINER
    test xax, xax
    jz @ErrorEoF
    mov pToken, xax
    dec [xbx].$Obj(IncFile).dIndentation
    OCall xbx::IncFile.StmWriteF,$OfsCStrA("%hs%hs ends", CRLF), pName, pSuffix
    OCall xbx::IncFile.StmWriteEoL

    .if pTag != NULL && pName != NULL
      invoke StrCompA, pTag, pName
      .if eax != 0
        OCall xbx::IncFile.StmWriteF,$OfsCStrA("%hs typedef %hs"), pTag, pName
        OCall xbx::IncFile.StmWriteEoL
      .endif
    .endif

    .if bSkipName != FALSE
      OCall xbx::IncFile.GetNextTokenC  ;skip structure name
    .endif
    OCall xbx::IncFile.GetNextTokenC
    ;typedef struct/union tagname typename
  .endif

  .if xax != NULL
    invoke RenderFurtherTypes, pName, pTag, xax
    test xax, xax
    jz @ErrorEoF
    mov pEndToken, xax
  .endif

  ;Exit ---------------------------------------------------------------------------------
@Exit:
  mov xax, pEndToken
  ret

@ErrorSyntax:
  inc [xbx].$Obj(IncFile).dErrorCount
  OCall xbx::IncFile.ShowError, $OfsCStr("RenderTypedefContainer")
  OCall xbx::IncFile.StmWriteError
  invoke GotoNextToken, addr szSemiColon
  ret

@ErrorEoF:
  inc [xbx].$Obj(IncFile).dErrorCount
  OCall xbx::IncFile.StmWriteError
  xor eax, eax
  ret
RenderTypedefContainer endp