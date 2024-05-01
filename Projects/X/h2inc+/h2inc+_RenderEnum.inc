; ==================================================================================================
; Title:      h2inc+_RenderEnum.inc
; Author:     G. Friedrich
; Version:    See h2inc+.asm
; Purpose:    ObjAsm h2inc+ translation procedures.
; ==================================================================================================


.code

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  RenderEnum
; Purpose:    Parse 'enum'.
; Arguments:  xbx -> IncFile.
; Return:     TRUE if succeeded, otherwise FALSE
; Syntax:     <typedef> <qualifiers> enum <tname> {x<=a>,y<=b>,...} name<,*name>;
;             <typedef> <qualifiers> enum <tname> <:type> {x<=a>,y<=b>,...} name<,*name>;
;             <typedef> <qualifiers> enum <class> <tname> <: type> {x<=a>,y<=b>,...} name<,*name>;
;             simplest form is "enum {x = a, y = b};"

RenderEnum proc
  local pTag:PTOKEN, pName:PTOKEN, pType:PSTRINGA, pToken:PTOKEN, pCurrToken:PTOKEN
  local cWorkBuffer[MAX_BLOCK_NAME]:CHRA, dTypeCSpec:DWORD

  mov pTag, NULL
  mov pName, NULL
  mov pType, NULL

  OCall xbx::IncFile.GetNextTokenC
  invoke SkipAnnotations, xax
  jz @ErrorEoF
  invoke SkipMacros, xax
  jz @ErrorEoF

  .if CHRA ptr [xax] != "{" && CHRA ptr [xax] != ":"
    mov pTag, xax
    OCall xbx::IncFile.GetNextTokenC
  .endif
  mov pToken, xax

  .if xax != NULL && CHRA ptr [xax] == ":"            ;Type specified?
    OCall xbx::IncFile.GetNextTokenC
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
      OCall xbx::IncFile.GetNextTokenC
      jz @Error
      mov pToken, xax
    .endif
  .else
    c2m pType, $OfsCStrA("SDWORD"), xdx               ;Default enum type
  .endif

  mov xax, pToken
  .if xax != NULL && CHRA ptr [xax] == "{"
    xor eax, eax
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

    ;Write a typedef with the tagName
    mov xax, pName
    .if xax != NULL && pTag != NULL
      invoke StrCompA, pName, pTag
      .if eax != 0
        OCall xbx::IncFile.StmWriteF, $OfsCStrA("%hs typedef %hs"), pTag, pName
        OCall xbx::IncFile.StmWriteEoL
      .endif
    .endif

    OCall xbx::IncFile.GetNextTokenC
    .if !ZERO? && pName != NULL && CHRA ptr [xax] != ";"
      invoke RenderFurtherTypes, pName, NULL, xax
    .else
      OCall xbx::IncFile.StmWriteEoL                  ;Separator line
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
    .elseif CHRA ptr [xcx] == "*"
      OCall xbx::IncFile.GetNextTokenC
      .if !ZERO?
        OCall xbx::IncFile.StmWriteF, $OfsCStrA("%hs typedef ptr %hs"), xax, pType
        OCall xbx::IncFile.StmWriteEoL
      .endif
      mov eax, TRUE
    .else
      xor eax, eax
    .endif
  .endif

  ret

@Error:
@ErrorEoF:
  DbgErrorF , "¦SU(¦UD): RenderEnum - error", [xbx].$Obj(IncFile).pHeaderFileName, [xbx].$Obj(IncFile).dLineNumber
  ret
RenderEnum endp
