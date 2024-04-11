; ==================================================================================================
; Title:      h2inc+_ParseTypedefContainer.inc
; Author:     G. Friedrich
; Version:    See h2inc+.asm
; Purpose:  
; ==================================================================================================


.code

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  ParseTypedefContainer
; Purpose:    Parse Typedef of a structure or union.
; Arguments:  Arg1 -> ContainerType (structure or union).
;             Arg2: Inside class flag.
;             xbx -> IncFile.
; Return:     Nothing
; Syntax:     class tname {};
;             typedef struct/union <macro> tname name;
;             typedef struct/union <macro> <tname> {} name;
;             typedef struct/union <macro> <tname> * name;

ParseTypedefContainer proc pContainerType:PSTRINGA, bInsideClass:BOOL
  local pName:PSTRINGA, pTag:PSTRINGA, pToken:PTOKEN
  local pInherit:POINTER, pSuffix:PSTRINGA
  local bSkipName:DWORD, bHasVTable:DWORD, dPtrCount:DWORD
  local szName[256]:CHRA, szStructName[MAX_BLOCK_NAME]:CHRA, szNoName[64]:CHRA

  mov szStructName, 0
  mov szName, 0
  mov szNoName, 0
  mov pTag, NULL
  mov pName, NULL
  mov pInherit, NULL
  mov dPtrCount, 0
  .if bInsideClass != FALSE
    lea xax, szStruct
    mov pContainerType, xax
    mov [xbx].$Obj(IncFile).bInsideClass, TRUE
  .endif
  DbgPrintF , "¦UD: ParseTypedefContainer - ¦SA", [xbx].$Obj(IncFile).dLineNumber, pContainerType
  OCall xbx::IncFile.GetNextToken
  invoke SkipAnnotations, xax
  jz @Error
  invoke SkipMacros, xax
  jz @Error

  .if CHRA ptr [xax] != "{"
    DbgPrintF , "¦UD: ParseTypedefContainer - token ¦SA assumed tag", [xbx].$Obj(IncFile).dLineNumber, xax
    lea xdx, szName
    mov pTag, $invoke(TranslateReservedWord, xax, xdx)
    mov pName, xax
    OCall xbx::IncFile.GetNextToken
	jz @Error
  .endif

  .if CHRA ptr [xax] == ":"
    .if 0; (!bInsideClass)
      ;invoke printf, $OfsCStrA("¦SU(¦UD): C++ syntax found", LF), [xbx].$Obj(IncFile).pFileName,
      ;               [xbx].$Obj(IncFile).dLineNumber
    .endif
    .while TRUE
      OCall xbx::IncFile.GetNextToken
      .if ZERO? || CHRA ptr [xax] == ";"        ;Statement terminator
        jmp @Error
      .endif
      .break .if CHRA ptr [xax] == "{"
      .continue .if CHRA ptr [xax] == ","
      mov pToken, xax
      .if pInherit == NULL
        mov pInherit, $Create@Stacklist()
      .endif
      Add@Stacklist pInherit, pToken
    .endw
  .endif

  DbgPrintF , "¦UD: ParseTypedefContainer - token ¦SA found", [xbx].$Obj(IncFile).dLineNumber, xax

  .if CHRA ptr [xax] == "{"
    mov bHasVTable, FALSE
    .if bInsideClass != FALSE
      invoke HasVTable?
      mov bHasVTable, eax
    .endif
    invoke GetBlockName, addr szStructName
    mov bSkipName, TRUE
    .if xax == NULL
      mov xax, pTag
      mov bSkipName, FALSE
    .endif

    ;No name at all?
    .if xax == NULL
      ;invoke sprintf, addr szNoName, $OfsCStrA("STRUCT_¦UD"), g_dStructSuffix
      inc $ObjTmpl(Application).dStructSuffix
      lea xax, szNoName
    .endif
    lea xdx, szName
    mov pName, $invoke(TranslateReservedWord, xax, xdx)
    IsStructure? pName
    .if eax == FALSE
      invoke StrSizeA, pName
      invoke InsertStrg, pStructs, pName, eax
    .endif
    lea xax, szEmpty
    mov pSuffix, xax
    .if pInherit != NULL
      invoke HasVirtualBase?, pInherit
      .if eax != FALSE
        c2m pSuffix, $OfsCStrA("$"), xax
      .endif
    .endif

    OCall xbx::IncFile.StmWriteF, $OfsCStrA("%s%s %s"), pName, pSuffix, pContainerType

    ;Get known structure alignment
    OCall pAlignments::List.Search, pName
    .if eax != FALSE
      mov edx, ecx
      OCall pAlignments::List.ItemAt, edx
      mov edx, [xax - sizeof DWORD]                     ;edx = length
      mov eax, [xax + xdx]
    .endif
    .if eax != 0
      OCall xbx::IncFile.StmWriteF, $OfsCStrA(" %u"), eax
    .elseif $ObjTmpl(Application).Options.bAddAlign != FALSE
      OCall xbx::IncFile.StmWrite, $OfsCStrA(" @Align")
    .endif
    OCall xbx::IncFile.StmWriteEOL

    inc [xbx].$Obj(IncFile).dIndentation
    .if bHasVTable != FALSE
      OCall xbx::IncFile.StmWrite, $OfsCStrA("  POINTER  ?   ; 'virtual method table'")
      OCall xbx::IncFile.StmWriteEOL
    .endif
    .if pInherit != NULL
      invoke WriteInherit, pInherit, TRUE
    .endif
    .if bInsideClass != FALSE
      invoke SkipBraces, "{", "}"
      test xax, xax
      jz @Exit
    .else
      invoke ParseBlock, pName, PBT_CONTAINER
      test xax, xax
      jz @Exit
      mov pToken, xax
    .endif
    .if pInherit != NULL
      invoke HasVirtualBase?, pInherit
      .if xax != NULL
        ;OCall xbx::IncFile.StmWriteF, $OfsCStrA("%s %s %s"), pName, pContainerType, pAlignment
        OCall xbx::IncFile.StmWriteF, $OfsCStrA("%s %s"), pName, pContainerType
        OCall xbx::IncFile.StmWriteEOL
        OCall xbx::IncFile.StmWriteF, $OfsCStrA("  %s%s <>"), pName, pSuffix
        OCall xbx::IncFile.StmWriteEOL
        invoke WriteInherit, pInherit, FALSE
        OCall xbx::IncFile.StmWriteF,$OfsCStrA("%s ends"), pName
        OCall xbx::IncFile.StmWriteEOL
      .endif
    .endif
    dec [xbx].$Obj(IncFile).dIndentation
    OCall xbx::IncFile.StmWriteF,$OfsCStrA("%s%s ends", LF), pName, pSuffix
    OCall xbx::IncFile.StmWriteEOL

    .if pTag != NULL && pName != NULL
      invoke StrCompA, pTag, pName
      .if eax != 0
        OCall xbx::IncFile.StmWriteF,$OfsCStrA("%s typedef %s"), pTag, pName
        OCall xbx::IncFile.StmWriteEOL
      .endif
    .endif

    .if bSkipName != FALSE
      OCall xbx::IncFile.GetNextToken  ;skip structure name
    .endif
    OCall xbx::IncFile.GetNextToken
    ;typedef struct/union tagname typename
  .endif

  .if xax != NULL
    invoke ParseFurtherTypes, pName, pTag, xax
  .endif

@Exit:
  mov [xbx].$Obj(IncFile).bInsideClass, FALSE
  Destroy@Stacklist pInherit
  xor eax, eax
  ret

@Error:
  DbgErrorF , "¦SU(¦UD): ParseTypedefContainer - error", [xbx].$Obj(IncFile).pHeaderFileName, [xbx].$Obj(IncFile).dLineNumber
  mov [xbx].$Obj(IncFile).bInsideClass, FALSE
  Destroy@Stacklist pInherit
  ret
ParseTypedefContainer endp