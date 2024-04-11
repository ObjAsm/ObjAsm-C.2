; ==================================================================================================
; Title:      h2inc+_ParseTypedefEnum.inc
; Author:     G. Friedrich
; Version:    See h2inc+.asm
; Purpose:  
; ==================================================================================================


.code

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  ParseTypedefEnum
; Purpose:    Parse 'typedef enum'.
; Arguments:  Arg1: Typedef flag.
;             xbx -> IncFile.
; Return:     TRUE if succeeded, otherwise FALSE
; Syntax:     <typedef> <qualifiers> enum <tname> {x<=a>,y<=b>,...} name<,*name>;
;             <typedef> <qualifiers> enum <tname> <:type> {x<=a>,y<=b>,...} name<,*name>;
;             <typedef> <qualifiers> enum <class> <tname> <: type> {x<=a>,y<=b>,...} name<,*name>;
;             simplest form is "enum {x = a, y = b};"

ParseTypedefEnum proc uses xdi bIsTypedef:BOOL
  local pTag:PTOKEN, pName:PTOKEN, pType:PSTRINGA, pToken:PTOKEN, pCurrToken:PTOKEN
  local szBlockName[MAX_BLOCK_NAME]:CHRA, szType[100]:CHRA
  local dTypeCSpec:DWORD, dScanStep:DWORD

  mov pTag, NULL
  mov pName, NULL
  mov pType, NULL

  OCall xbx::IncFile.GetNextToken
  invoke SkipAnnotations, xax
  jz @Error
  invoke SkipMacros, xax
  jz @Error

  .if CHRA ptr [xax] != "{" && CHRA ptr [xax] != ":"
    mov pTag, xax
    OCall xbx::IncFile.GetNextToken
  .endif
  mov pToken, xax

  .if xax != NULL && CHRA ptr [xax] == ":"            ;Type specified?
    OCall xbx::IncFile.GetNextToken
    jz @Error

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
      OCall xbx::IncFile.GetNextToken
      jz @Error
      mov pToken, xax
    .endif
  .else
    c2m pType, $OfsCStrA("SDWORD"), xdx               ;Default enum type
  .endif

  mov xax, pToken
  .if xax != NULL && CHRA ptr [xax] == "{"
    .if bIsTypedef != FALSE
      invoke GetBlockName, addr szBlockName
    .else
      xor eax, eax
    .endif
    mov pName, xax
    test xax, xax
    cmovz xax, pTag                                   ;if no name found, use the tag
    .if xax != NULL
      mov pName, xax
      OCall xbx::IncFile.StmWriteF, $OfsCStrA("%s typedef %s"), pName, pType
      OCall xbx::IncFile.StmWriteEOL
    .endif
    mov [xbx].$Obj(IncFile).dEnumValue, 0
    invoke ParseBlock, pName, PBT_ENUM

    ;Write a typedaf with the tagName
    mov xax, pName
    .if xax != NULL && pTag != NULL
      invoke StrCompA, pName, pTag
      .if eax != 0
        OCall xbx::IncFile.StmWriteF, $OfsCStrA("%s typedef %s"), pTag, pName
        OCall xbx::IncFile.StmWriteEOL
      .endif
    .endif

    .if bIsTypedef != FALSE
      OCall xbx::IncFile.GetNextToken                 ;Skip enum name
    .endif
    OCall xbx::IncFile.GetNextToken
    .if !ZERO? && pName != NULL && CHRA ptr [xax] != ";"
      invoke ParseFurtherTypes, pName, NULL, xax
    .else
      OCall xbx::IncFile.StmWriteEOL                  ;Separator line
    .endif

    mov eax, TRUE

  .else
    ;Syntax "typedef <Annotation> enum OldTypeName <*> NewTypeName;
    mov pCurrToken, xax
    IsName? xax
    mov xcx, pCurrToken
    .if eax != FALSE
      OCall xbx::IncFile.StmWriteF, $OfsCStrA("%s typedef %s"), xcx, pType
      OCall xbx::IncFile.StmWriteEOL
      mov eax, TRUE
    .elseif CHRA ptr [xcx] == "*"
      OCall xbx::IncFile.GetNextToken
      .if !ZERO?
        OCall xbx::IncFile.StmWriteF, $OfsCStrA("%s typedef ptr %s"), xax, pType
        OCall xbx::IncFile.StmWriteEOL
      .endif
      mov eax, TRUE
    .else
      xor eax, eax
    .endif
  .endif

  ret

@Error:
  DbgErrorF , "¦SU(¦UD): ParseTypedefEnum - error", [xbx].$Obj(IncFile).pHeaderFileName, [xbx].$Obj(IncFile).dLineNumber
  ret
ParseTypedefEnum endp
