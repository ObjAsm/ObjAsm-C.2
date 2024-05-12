; ==================================================================================================
; Title:      h2inc+_RenderContainer.inc
; Author:     G. Friedrich
; Version:    See h2inc+.asm
; Purpose:    ObjAsm h2inc+ translation procedures.
; ==================================================================================================


.code

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  RenderContainer
; Purpose:    Render a structure or union.
; Arguments:  Arg1 -> ContainerType ("struct" or "union").
;             xbx -> IncFile.
; Return:     xax -> Last token or NULL if failed.
; Syntax:     struct/union <macro> TagName Name;
;             struct/union <macro> <TagName> {...} Name;
;             struct/union <macro> <TagName> * Name;

RenderContainer proc uses xdi pContainerType:PSTRINGA
  local pName:PSTRINGA, pTagName:PSTRINGA, pToken:PTOKEN, pEndToken:PTOKEN
  local bSkipName:DWORD
  local cName[256]:CHRA, cTagName[256]:CHRA, cContainerName[MAX_NAME_CHARS]:CHRA

  OCall $ObjTmpl(Application)::Application.ShowInfo, VERBOSITY_DEAFENING, $OfsCStr("RenderContainer")
  ;Initialization -----------------------------------------------------------------------
  mov cContainerName, 0
  mov cTagName, 0
  mov cName, 0
  mov pTagName, NULL
  mov pName, NULL

  OCall xbx::IncFile.GetNextTokenC
  test xax, xax
  jz @ErrorEoF
  invoke SkipAnnotations, xax
  test xax, xax
  jz @ErrorEoF
  invoke SkipMacros, xax
  test xax, xax
  jz @ErrorEoF

  mov cl, [xax]
  .if cl != '{' && cl != '*'
    lea xdx, cTagName
    mov pTagName, $invoke(TranslateReservedWord, xax, xdx)
    mov pName, xax                                      ;Assume for the moment that Name = TagName
    OCall xbx::IncFile.GetNextTokenC
    test xax, xax
  	jz @ErrorEoF
  .endif

  .if CHRA ptr [xax] == '{'
    invoke GetBlockName, addr cContainerName
    .if xax == NULL                                     ;No block name
      mov bSkipName, FALSE
      mov xax, pTagName
    .else
      mov bSkipName, TRUE
      .if !$DoesTextMatchA?([xax], <DUMMYSTRUCTNAME>)   ;May have a number at the end
        .if !$DoesTextMatchA?([xax], <DUMMYUNIONNAME>)  ;May have a number at the end
          jmp @F
        .endif
      .endif
      mov xax, pTagName
    .endif
@@:
;    ;No name at all?
;    .if xax == NULL
;      lea xdi, cContainerName
;      mov xax, pContainerType
;      .if $DoesStringMatchA?([xax], <struct>)
;        WriteFA xdi, "ANONIMOUS_STRUCT_¦UD", $ObjTmpl(Application).dStrucNameSuffix
;        inc $ObjTmpl(Application).dStrucNameSuffix
;      .else
;        WriteFA xdi, "ANONIMOUS_UNION_¦UD", $ObjTmpl(Application).dUnionNameSuffix
;        inc $ObjTmpl(Application).dUnionNameSuffix
;      .endif
;      lea xax, cContainerName
;    .endif

    ;Start container definition ---------------------------------------------------------
    .if xax == NULL
      OCall xbx::IncFile.StmWriteF, $OfsCStrA("%hs"), pContainerType

    .else
      lea xdx, cName
      mov pName, $invoke(TranslateReservedWord, xax, xdx)
      IsStructure? pName
      .if eax == FALSE
        invoke StrLengthA, pName
        invoke InsertStrg, pNewStructs, pName, eax
      .endif

      OCall xbx::IncFile.StmWriteF, $OfsCStrA("%hs %hs"), pName, pContainerType

      ;Get known structure alignment
      OCall pKnwAlignments::List.Search, pName
      .if eax != FALSE
        mov edx, ecx
        OCall pKnwAlignments::List.ItemAt, edx
        mov edx, [xax - sizeof(DWORD)]                    ;edx = length
        mov eax, [xax + xdx]                              ;eax = alignment
      .endif
      .if eax != 0
        OCall xbx::IncFile.StmWriteF, $OfsCStrA(" %u"), eax
      .elseif $ObjTmpl(Application).Options.bAddAlign != FALSE
        OCall xbx::IncFile.StmWrite, $OfsCStrA(" @Align")
      .endif
    .endif

    inc [xbx].$Obj(IncFile).dIndentation
    OCall xbx::IncFile.StmWriteEoL

    ;Entry: Next token after '{'
    ;Exit: Next Token after '}'
    invoke RenderBlock, pName, RBT_CONTAINER
    test xax, xax
    jz @ErrorEoF

    ;Terminate container definition -----------------------------------------------------
    dec [xbx].$Obj(IncFile).dIndentation
    .if pName != NULL
      OCall xbx::IncFile.StmWriteF, $OfsCStrA("%hs ends", CRLF), pName
    .else
      OCall xbx::IncFile.StmWrite, $OfsCStrA("ends", CRLF)
    .endif
    OCall xbx::IncFile.StmWriteEoL

    ;Create a typedef in case that the TageName and Name are different ------------------
    .if pTagName != NULL && pName != NULL
      invoke StrCompA, pTagName, pName
      .if eax != 0
        OCall xbx::IncFile.StmWriteF,$OfsCStrA("%hs typedef %hs"), pTagName, pName
        OCall xbx::IncFile.StmWriteEoL
      .endif
    .endif

    .if bSkipName != FALSE
      OCall xbx::IncFile.GetNextTokenC                  ;Skip container name
      test xax, xax
      jz @ErrorEoF
    .endif
    OCall xbx::IncFile.GetNextTokenC                    ;Consume ';'
    test xax, xax
    jz @ErrorEoF
    mov pEndToken, xax
  .else
    ; *
    mov pEndToken, xax
  .endif

  .if xax != NULL
    invoke RenderFurtherTypes, pName, pTagName, xax
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
  OCall xbx::IncFile.ShowError, $OfsCStr("RenderContainer")
  OCall xbx::IncFile.StmWriteError
  invoke GotoNextToken, addr szSemiColon
  ret

@ErrorEoF:
  inc [xbx].$Obj(IncFile).dErrorCount
  xor eax, eax
  ret
RenderContainer endp