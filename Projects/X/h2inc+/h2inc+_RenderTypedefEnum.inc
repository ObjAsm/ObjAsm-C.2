; ==================================================================================================
; Title:      h2inc+_RenderTypedefEnum.inc
; Author:     G. Friedrich
; Version:    See h2inc+.asm
; Purpose:    ObjAsm h2inc+ translation procedures.
; ==================================================================================================


.code

; --------------------------------------------------------------------------------------------------
; Procedure:  RenderTypedefEnum
; Purpose:    Translate 'typedef enum'.
; Arguments:  Arg1: Typedef flag.
;             xbx -> IncFile.
; Return:     TRUE if succeeded, otherwise FALSE.
; Syntax:     <typedef> <qualifiers> enum <tname> {x<=a>,y<=b>,...} name<,*name>;
;             <typedef> <qualifiers> enum <tname> <:type> {x<=a>,y<=b>,...} name<,*name>;
;             <typedef> <qualifiers> enum <class> <tname> <: type> {x<=a>,y<=b>,...} name<,*name>;
;             simplest form is "enum {x = a, y = b};"

RenderTypedefEnum proc uses xbx bIsTypedef:BOOL
  local pTag:PTOKEN, pName:PTOKEN, pType:PSTRINGA, pToken:PTOKEN, pCurrToken:PTOKEN
  local cWorkBuffer[MAX_NAME_CHARS]:CHRA, dTypeCSpec:DWORD

  OCall $ObjTmpl(Application)::Application.ShowInfo, VERBOSITY_DEAFENING, $OfsCStr("RenderTypedefEnum")
  mov pTag, NULL
  mov pName, NULL
  mov pType, NULL

  OCall xbx::IncFile.GetNextTokenC
  test xax, xax
  jz @ErrorEoF
  invoke SkipAnnotations, xax
  test xax, xax
  jz @ErrorEoF
  invoke SkipMacros, xax
  test xax, xax
  jz @ErrorEoF

  .if CHRA ptr [xax] != '{' && CHRA ptr [xax] != ':'
    mov pTag, xax
    OCall xbx::IncFile.GetNextTokenC
    test xax, xax
    jz @ErrorEoF
  .endif
  mov pToken, xax

  .if xax != NULL && CHRA ptr [xax] == ':'            ;Type specified?
    OCall xbx::IncFile.GetNextTokenC
    test xax, xax
    jz @ErrorEoF

    ;pToken may be a basic C type
    BasicTypeCScan
    .if dTypeCSpec != 0
      mov pToken, xax                                 ;Last gattered Token
      invoke ConvBasicTypeC, dTypeCSpec
      .if xax == NULL                                 ;If conversion failed
        lea xax, szUnkType
      .endif
      mov pType, xax
    .else
      mov pType, xax
      OCall xbx::IncFile.GetNextTokenC
      test xax, xax
      jz @ErrorEoF
      mov pToken, xax
    .endif
  .else
    c2m pType, $OfsCStrA("SDWORD"), xdx               ;Default enum type
  .endif

  mov xax, pToken
  .if xax != NULL && CHRA ptr [xax] == '{'
    .if bIsTypedef != FALSE
      invoke GetBlockName, addr cWorkBuffer           ;xax -> Block Name or NULL
    .else
      xor eax, eax
    .endif
    mov pName, xax
    test xax, xax
    cmovz xax, pTag                                   ;if no name found, use the tag
    .if xax != NULL
      mov pName, xax
      OCall xbx::IncFile.StmWriteF, $OfsCStrA("%hs typedef %hs"), pName, pType
      OCall xbx::IncFile.StmWriteEoL
    .endif
    mov [xbx].$Obj(IncFile).dEnumValue, 0
    invoke RenderBlock, pName, RBT_ENUM
    test xax, xax
    jz @ErrorEoF

    ;Write a typedef with the tagName
    mov xax, pName
    .if xax != NULL && pTag != NULL
      invoke StrCompA, pName, pTag
      .if eax != 0
        OCall xbx::IncFile.StmWriteF, $OfsCStrA("%hs typedef %hs"), pTag, pName
        OCall xbx::IncFile.StmWriteEoL
      .endif
    .endif

    .if bIsTypedef != FALSE
      OCall xbx::IncFile.GetNextTokenC                 ;Skip enum name
      test xax, xax
      jz @ErrorEoF
    .endif
    OCall xbx::IncFile.GetNextTokenC
    .if xax != NULL && pName != NULL && CHRA ptr [xax] != ';'
      invoke RenderFurtherTypes, pName, NULL, xax
      test xax, xax
      jz @ErrorEoF
    .else
      OCall xbx::IncFile.StmWriteEoL                  ;Separator line
    .endif

    .if pName != NULL
      invoke GetTypeSize, pType
      mov ebx, eax
      invoke StrLengthA, pName
      invoke InsertAttr, pNewTypeSize, pName, eax, ebx
    .endif

    mov eax, TRUE

  .else
    ;Syntax "typedef <Annotation> enum OldTypeName <*> NewTypeName;
    mov pCurrToken, xax
    IsValidName? xax
    mov xcx, pCurrToken
    .if eax != FALSE
      OCall xbx::IncFile.StmWriteF, $OfsCStrA("%hs typedef %hs"), xcx, pType
      OCall xbx::IncFile.StmWriteEoL
      mov eax, TRUE
    .elseif CHRA ptr [xcx] == '*'
      OCall xbx::IncFile.GetNextTokenC
      .if xax != NULL
        OCall xbx::IncFile.StmWriteF, $OfsCStrA("%hs typedef ptr %hs"), xax, pType
        OCall xbx::IncFile.StmWriteEoL
      .endif
      mov eax, TRUE
    .else
      xor eax, eax
    .endif
  .endif

  ;Exit ---------------------------------------------------------------------------------
@Exit:
  ret

@ErrorSyntax:
  OCall xbx::IncFile.ShowError, $OfsCStr("RenderTypedefEnum")
  OCall xbx::IncFile.StmWriteError
  invoke GotoNextToken, addr szSemiColon
  xor eax, eax
  ret

@ErrorEoF:
  inc [xbx].$Obj(IncFile).dErrorCount
  OCall xbx::IncFile.StmWriteError
  xor eax, eax
  ret
RenderTypedefEnum endp
