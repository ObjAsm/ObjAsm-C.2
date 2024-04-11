; ==================================================================================================
; Title:      h2inc+_ParseTypedefFunction.inc
; Author:     G. Friedrich
; Version:    See h2inc+.asm
; Purpose:    
; ==================================================================================================


.code

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  ParseTypedefFunction
; Purpose:    typedef function occured.
; Arguments:  Arg1 -> Name.
;             Arg2: Accept Body flag.
;             Arg3 -> Parent
; Return:     Nothing.
; Syntax:     typedef <qualifiers> returntype name(<parameters>)<{...}>;
;             or in a class definition:
;             <qualifiers> returntype name(<parameters>)<{...}>;

ParseTypedefFunction proc pName:PSTRINGA, bAcceptBody:DWORD, pParent:PSTRINGA
    local pToken:PTOKEN, pCurrToken:PTOKEN
  local dNum:DWORD, dCallConv:DWORD, dPtrCount:DWORD, bFirstParam:DWORD
  local dTypeCSpec:DWORD, pType:PSTRINGA, cFuncName[256]:CHRA, cDecoName[256]:CHRA
  local szFuncName[32]:CHRA, szType[512]:CHRA, szDecoName[1024]:CHRA, cTransBuffer[128]:CHRA

  ;Parse function header ----------------------------------------------------
  mov bFirstParam, FALSE
  mov pName, $invoke(TranslateReservedWord, pName, NULL)
  .if [xbx].$Obj(IncFile).bInsideClass != FALSE
    mov dNum, 0
    mov xax, pName
    .if CHRA ptr [xax] == "~"
      inc xax
      inc dNum
    .endif
    invoke StrCompA, xax, pParent
    .if xax == 0
      invoke wsprintf, addr cFuncName, $OfsCStr("?%u"), dNum
      lea xax, cFuncName
      mov pName, xax
    .endif
    mov dCallConv, "A"          ;A = cdecl, G = stdcall
    invoke wsprintf, addr cDecoName, $OfsCStr("?%s@%s@@Q%c___Z"), pName, pParent, dCallConv
    OCall xbx::IncFile.StmWriteF, $OfsCStr(";externdef syscall %s:near"), addr cDecoName
    OCall xbx::IncFile.StmWriteEOL
    OCall xbx::IncFile.StmWriteF, $OfsCStrA(";%s proto :ptr %s "), addr szDecoName, pParent
    mov bFirstParam, TRUE
  .else
    OCall xbx::IncFile.StmWriteF, $OfsCStrA("%s typedef proto "), pName
  .endif

  ;Parse function parameters ------------------------------------------------
  mov pType, NULL
  mov dPtrCount, 0
  .while TRUE
    OCall xbx::IncFile.GetNextToken
@ProcessToken:
    jz @Error

    invoke SkipAnnotations, xax
    jz @Error

    .if CHRA ptr [xax] == "*"
      inc dPtrCount
      .continue
    .endif

    .continue .if $DoesStringMatchA?([xax], <struct>)   ;Ignore 'struct'
    .continue .if $DoesStringMatchA?([xax], <union>)    ;Ignore 'union'
    .continue .if $DoesStringMatchA?([xax], <enum>)     ;Ignore 'enum'

    ;pToken may be a basic C type
    mov pToken, xax
    .if pType == NULL
      BasicTypeCScan
      mov pToken, xax
      .if dTypeCSpec != 0
        invoke ConvBasicTypeC, dTypeCSpec
        .if xax == NULL                                 ;If conversion failed
          lea xax, szUnkType
          mov pType, xax
        .else
          mov pType, xax
          mov xax, pToken
          test xax, xax
          jmp @ProcessToken
          .continue
        .endif
      .endif
    .endif
    mov pToken, xax
    .if CHRA ptr [xax] == "," || CHRA ptr [xax] == ")"  ;End of function parameter list
      mov pCurrToken, xax
      .if dPtrCount != 0 || pType != NULL
        .if pType != NULL
          mov pType, $invoke(TranslateReservedWord, pType, addr cTransBuffer)  ;Maybe it is a reserved word!
        .endif
        mov xax, pType

        .if dPtrCount != 0 || CHRA ptr [xax] != 0
          .if bFirstParam != FALSE
            OCall xbx::IncFile.StmWrite, $OfsCStrA(", ")
            mov bFirstParam, FALSE
          .endif
          OCall xbx::IncFile.StmWriteChar, ":"
        .endif
        WritePtr
        .if pType != NULL
          OCall xbx::IncFile.StmWrite, pType
        .endif
        OCall xbx::IncFile.StmDeleteLastSpace
      .endif
      mov xax, pCurrToken
      .break .if CHRA ptr [xax] == ")"
      OCall xbx::IncFile.StmWrite, $OfsCStrA(", ")
      mov pType, NULL
      mov dPtrCount, 0
      .continue
    .endif

    mov pToken, xax
    invoke TranslateTypeQualifier, xax
    .continue .if CHRA ptr [xax] == 0
    .if pType == NULL
      m2m pType, pToken, xax
    .endif
  .endw
  OCall xbx::IncFile.StmWriteEOL

  .if bAcceptBody != FALSE
    OCall xbx::IncFile.PeekNextToken
    .if xax != NULL && CHRA ptr [xax] == "{"
      invoke SkipBraces, "{", "}"
    .endif
  .endif

  ret

@Error:
  DbgErrorF , "¦SU(¦UD): ParseTypedefFunction - error", [xbx].$Obj(IncFile).pHeaderFileName, [xbx].$Obj(IncFile).dLineNumber
  ret
ParseTypedefFunction endp
