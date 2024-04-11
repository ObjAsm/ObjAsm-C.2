; ==================================================================================================
; Title:      h2inc+_ParseExternItem.inc
; Author:     G. Friedrich
; Version:    See h2inc+.asm
; Purpose:    
; ==================================================================================================


.code

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  ParseExternItem
; Purpose:    Get an extern declaration.
; Arguments:  Arg1 -> First Token.
;             xbx -> IncFile.
; Return:     xax -> Next Token.

ParseExternItem proc uses xdi pToken:PTOKEN
  local dTypeCSpec:DWORD, bFunction:DWORD, bStatic:DWORD, bConst:DWORD
  local pType:PSTRINGA, pName:PSTRINGA, cTransBuffer[128]:CHRA

  mov pType, NULL
  mov pName, NULL
  mov bStatic, FALSE
  mov bFunction, FALSE

  mov xax, pToken                                       ;Use token passed in to this proc
  .while TRUE
    .break .if xax == NULL
    invoke SkipAnnotations, pToken
    .break .if ZERO?

    .if $DoesStringMatchA?([xax], <static>)
      mov bStatic, TRUE
      jmp @GetNextToken
    .endif

    .if $DoesStringMatchA?([xax], <const>)
      mov bConst, TRUE
      jmp @GetNextToken
    .endif

    invoke TranslateTypeQualifier, xax
    cmp CHRA ptr [xax], 0
    je @GetNextToken

    .break .if CHRA ptr [xax] == "}" || CHRA ptr [xax] == ";"   ;Statement terminator

    mov pToken, xax
    invoke IsMacro?, xax
    .if eax != 0
      mov edx, ecx
      .if eax == 1
        OCall pMacros::List.ItemAt, edx
      .else
        OCall pKnownMacros::List.ItemAt, edx
      .endif
      mov edx, [xax - sizeof DWORD]
      invoke ParseMacroCall, pToken, DWORD ptr [xax + xdx], TRUE
      .if eax != FALSE
        jmp @GetNextToken
      .endif
    .endif

    mov xax, pToken
    .if CHRA ptr [xax] == "("
      mov xax, pName
      .if xax != NULL
        DbgPrintF , "¦UD: ParseExternItem, function ¦SA found", [xbx].$Obj(IncFile).dLineNumber, pName
      .else
        jmp @Error
      .endif
      mov bFunction, TRUE
      jmp @GetNextToken
    .endif

    ;pToken may be a basic C type
    mov xax, pToken
    .if pType == NULL
      BasicTypeCScan
      mov pToken, xax
      .if dTypeCSpec != 0
        invoke ConvBasicTypeC, dTypeCSpec
        .if eax == 0
          lea xax, szUnkType
        .endif
        mov pType, xax
        mov xax, pToken                                 ;Process last gattered Token
        .continue
      .endif
    .endif

    mov xax, pToken
    .if $DoesStringMatchA?([xax], <"C">)
      jmp @GetNextToken                                 ;Ignore it
    .endif

    mov xax, pToken
    .if $DoesStringMatchA?([xax], <"C++">)
      jmp @GetNextToken                                 ;Ignore it
    .endif

    mov xax, pToken
    mov cl, CHRA ptr [xax]
    .if cl == "[" && pName != NULL                      ;"[]" should only come after a valid name
      .repeat                                           ;Ignore it
        OCall xbx::IncFile.GetNextToken
      .until ZERO? || CHRA ptr [xax] == ";"
      .break
    .endif

    .if cl == "="
      .repeat
        OCall xbx::IncFile.GetNextToken
      .until ZERO? || CHRA ptr [xax] == ";"
      .break
    .endif

    IsName? pToken
    .if eax != FALSE
      mov xax, pToken
      .if pType == NULL
        mov pType, xax
      .elseif pName == NULL
        mov pName, xax
      .else
        DbgErrorF , "¦SU(¦UD): ParseExternItem - unknown Token 1 ¦SA", [xbx].$Obj(IncFile).pHeaderFileName, [xbx].$Obj(IncFile).dLineNumber, pToken
        jmp @Error
      .endif
    .else
      DbgErrorF , "¦SU(¦UD): ParseExternItem - unknown Token 2 ¦SA", [xbx].$Obj(IncFile).pHeaderFileName, [xbx].$Obj(IncFile).dLineNumber, pToken
      jmp @Error
    .endif

@GetNextToken:
    OCall xbx::IncFile.GetNextToken
    mov pToken, xax
  .endw

  .if pName != NULL
    invoke TranslateReservedWord, pName, addr cTransBuffer
    .if bFunction != FALSE
      mov xcx, $OfsCStrA("near")
    .else
      mov xcx, pType
    .endif
    OCall xbx::IncFile.StmWriteF, $OfsCStrA("%s:%s"), xax, xcx
    OCall xbx::IncFile.StmWriteEOL
    mov xax, pToken
  .else
    xor eax, eax
    jmp @Error
  .endif

@Exit:
  ret

@Error:
  DbgErrorF , "¦SU(¦UD): ParseExternItem - error", [xbx].$Obj(IncFile).pHeaderFileName, [xbx].$Obj(IncFile).dLineNumber
  ret
ParseExternItem endp
