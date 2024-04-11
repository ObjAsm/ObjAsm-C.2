; ==================================================================================================
; Title:      h2inc+_IncFile_Parse.inc
; Author:     G. Friedrich
; Version:    C.2.0
; Purpose:    ObjAsm h2inc+ IncFile parser procs.
; Notes:      See h2inc+.asm
; ==================================================================================================


include h2inc+_ParseBlock.inc
include h2inc+_ParseContainerItem.inc
include h2inc+_ParseEnumItem.inc
include h2inc+_ParseEqu.inc
include h2inc+_ParseExtern.inc
include h2inc+_ParseExternItem.inc
include h2inc+_ParseFurtherTypes.inc
include h2inc+_ParseInterfaceBlock.inc
include h2inc+_ParseMacroCall.inc
include h2inc+_ParsePrototype.inc
include h2inc+_ParseTypedef.inc
include h2inc+_ParseTypedefFunction.inc
include h2inc+_ParseTypedefFunctionPtr.inc
include h2inc+_ParseTypedefEnum.inc
include h2inc+_ParseTypedefContainer.inc

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  ParseC
; Purpose:    The following types of declarations are known:
;               1. typedef (struct, enum)
;               2. extern
;               3. prototypes
; Arguments:  xbx -> IncFile.
; Return:     eax = TRUE if succeeded, otherwise FALSE.
; Links:      http://www.inf.fu-berlin.de/lehre/WS11/OS/slides/OS_Declarations_in_C_.pdf
;             https://en.wikipedia.org/wiki/C_syntax
;             https://msdn.microsoft.com/en-us/library/bz4heb45.aspx

ParseC proc uses xdi xsi
  local pToken:PTOKEN, pToken2:PTOKEN, bNextParm:DWORD, bInsideClass:DWORD, bAddSpace:DWORD
  local cMacroBuffer[2048]:CHRA, dProtoQualifier:DWORD, .xdi:XWORD, .xsi:XWORD
	local pOutPos:POINTER, dEOL:DWORD, dIsClass:DWORD, d1:DWORD, p1:POINTER, p2:POINTER, p3:POINTER

  OCall xbx::IncFile.GetNextToken
  .if ZERO?
    DbgPrintF , "¦UD: ParseC - EOF reached", [xbx].$Obj(IncFile).dLineNumber
    ret
  .endif
  mov pToken, xax

  OCall xbx::IncFile.StmWriteComment
  .if eax != FALSE
    OCall xbx::IncFile.StmWriteEOL
  .endif

  mov xax, pToken
  .if CHRA ptr [xax] == ";"                             ;Statement terminator => reset all
    mov [xbx].$Obj(IncFile).pPrevToken, NULL
    mov [xbx].$Obj(IncFile).pImportSpec, NULL
    mov [xbx].$Obj(IncFile).pCallConv, NULL
    mov [xbx].$Obj(IncFile).dQualifiers, 0
    jmp @Exit
  .endif

  ;Check annotation ---------------------------------------------------------
  invoke SkipAnnotations, pToken
  jz @Exit

  mov pToken, $invoke(TranslateToken, xax)

  ;'typedef' test -----------------------------------------------------------
  .if $DoesStringMatchA?([xax], <typedef>)
    mov xsi, [xbx].$Obj(IncFile).pStmOutPos
    mov edi, [xbx].$Obj(IncFile).dStmOutEOL
    DbgPrintF , "¦UD: ParseC - \´typedef\´ found", [xbx].$Obj(IncFile).dLineNumber
    invoke ParseTypedef
    .ifBitClr $ObjTmpl(Application).Options.dSelectiveOutput, OUTPUT_TYPEDEFS
      mov [xbx].$Obj(IncFile).pStmOutPos, xsi
      mov [xbx].$Obj(IncFile).dStmOutEOL, edi
      mov CHRA ptr [xsi], 0
    .endif
    jmp @Exit
  .endif

  ;'union', 'struct', 'class' test ------------------------------------------
  ;'struct' may be a struct declaration, but may be a function returning a struct as well
  invoke IsUnionStructClass?, pToken                    ;edx = TRUE if class detected
  .if eax != FALSE
    DbgPrintF , "¦UD: ParseC - \´union/struct/class\´ found", [xbx].$Obj(IncFile).dLineNumber
    mov dIsClass, edx
    invoke IsFunction?
    .if eax == FALSE
      mov xsi, [xbx].$Obj(IncFile).pStmOutPos
      mov edi, [xbx].$Obj(IncFile).dStmOutEOL
      invoke ParseTypedefContainer, pToken, dIsClass
      .ifBitClr $ObjTmpl(Application).Options.dSelectiveOutput, OUTPUT_TYPEDEFS
        mov [xbx].$Obj(IncFile).pStmOutPos, xsi
        mov [xbx].$Obj(IncFile).dStmOutEOL, edi
        mov CHRA ptr [xsi], 0
      .endif
      jmp @Exit
    .endif
    DbgPrintF , "¦UD: ParseC - \´union/struct\´ ignored (function return type)", \
              [xbx].$Obj(IncFile).dLineNumber
  .endif

  ;'extern' test ------------------------------------------------------------
  mov xax, pToken
  .if $DoesStringMatchA?([xax], <extern>)
    invoke IsFunction?                                  ;In case of an extern function, ignore
    .if eax == FALSE                                    ;'extern' and continue parsing as a proto
      mov xsi, [xbx].$Obj(IncFile).pStmOutPos
      mov edi, [xbx].$Obj(IncFile).dStmOutEOL
      DbgPrintF , "¦UD: ParseC - \´extern\´ found", [xbx].$Obj(IncFile).dLineNumber
      invoke ParseExtern
      .ifBitClr $ObjTmpl(Application).Options.dSelectiveOutput, OUTPUT_EXTERNALS
        mov [xbx].$Obj(IncFile).pStmOutPos, xsi
        mov [xbx].$Obj(IncFile).dStmOutEOL, edi
        mov CHRA ptr [xsi], 0
      .endif
    .endif
    jmp @Exit
  .endif

  ;'enum' test --------------------------------------------------------------
  invoke StrICompA, addr szEnum, pToken               ;Upper- and lowercase!
  .if eax == 0
    DbgPrintF , "¦UD: ParseC - \´enum\´ found", [xbx].$Obj(IncFile).dLineNumber
    invoke ParseTypedefEnum, FALSE
    jmp @Exit
  .endif

  ;Check qualifier ----------------------------------------------------------

  ;First check if name is a known prototype qualifier.
  ;This may also be a macro. In that case, no macro invocation should be generated.

  invoke GetProtoQualifier, pToken
  .if xax != NULL
    mov edx, [xax - sizeof DWORD]
    mov ecx, [xax + xdx]
    mov dProtoQualifier, ecx
    DbgPrintF , "¦UD: ParseC - prototype qualifier ¦SA found, value = ¦UX", \
              [xbx].$Obj(IncFile).dLineNumber, pToken, ecx
    invoke IsMacro?, pToken
    .if eax != 0
      ;OK, it is a macro, check for args in parenthesis
      OCall xbx::IncFile.PeekNextToken
      .if CHRA ptr [xax] == "("
        mov .xsi, xsi
        mov .xdi, xdi
        mov bAddSpace, FALSE
        invoke StrECopyA, addr cMacroBuffer, pToken     ;macro name
        mov xdi, xax
        OCall xbx::IncFile.GetNextToken                 ;"("
        invoke StrECopyA, xdi, xax
        mov xdi, xax
        mov esi, 1
        .repeat
          OCall xbx::IncFile.GetNextToken
          invoke SkipAnnotations, xax
          .break .if ZERO?
          mov pToken2, xax
          .if CHRA ptr [xax] == "("
            inc xsi
            mov bAddSpace, FALSE
          .elseif CHRA ptr [xax] == ")"
            dec xsi
            mov bAddSpace, TRUE
          .else
            .if bAddSpace != FALSE
              invoke StrECopyA, xdi, addr szSpace
              mov xdi, xax
            .endif
            mov bAddSpace, TRUE
          .endif
          invoke StrECopyA, xdi, pToken2
          mov xdi, xax
        .until xsi == 0
        mov xsi, .xsi
        mov xdi, .xdi
        lea eax, cMacroBuffer
      .else
        mov xax, pToken
      .endif
    .else
      mov xax, pToken
    .endif
    mov ecx, dProtoQualifier

    .ifBitSet ecx, PTQ_IMPORT
      lea xdx, szDllImport
      mov [xbx].$Obj(IncFile).pImportSpec, xdx
    .endif
    .ifBitSet ecx, (PTQ_STDCALL or PTQ_CDECL or PTQ_SYSCALL or PTQ_PASCAL or \
                    PTQ_FASTCALL or PTQ_VECTORCALL)
      mov [xbx].$Obj(IncFile).pCallConv, xax
    .endif
    or [xbx].$Obj(IncFile).dQualifiers, ecx
    jmp @Exit
  .endif

  ;Check for macro invocation -----------------------------------------------
  .if [xbx].$Obj(IncFile).dQualifiers == 0              ;No previous qualifiers => it is a macro invocation
    invoke IsMacro?, pToken
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
        jmp @Exit
      .endif
    .endif
  .endif

  ;Check known types --------------------------------------------------------
  .if [xbx].$Obj(IncFile).dQualifiers == 0              ;No previous qualifiers!
    OCall pTypedefs::List.Search, pToken
    .if eax != 0
      jmp @Exit
    .endif
  .endif

  ;Check for prototypes -----------------------------------------------------
  mov xax, pToken
  .if CHRA ptr [xax] == "("
    .if [xbx].$Obj(IncFile).pPrevToken != NULL
      DbgPrintF , "¦UD: ParseC - prototype found", [xbx].$Obj(IncFile).dLineNumber
      mov xsi, [xbx].$Obj(IncFile).pStmOutPos
      mov edi, [xbx].$Obj(IncFile).dStmOutEOL
      invoke ParsePrototype, [xbx].$Obj(IncFile).pPrevToken, [xbx].$Obj(IncFile).pImportSpec, [xbx].$Obj(IncFile).pCallConv
      .ifBitClr $ObjTmpl(Application).Options.dSelectiveOutput, OUTPUT_PROTOTYPES
        mov [xbx].$Obj(IncFile).pStmOutPos, xsi
        mov [xbx].$Obj(IncFile).dStmOutEOL, edi
        mov CHRA ptr [xsi], 0
      .endif
      mov [xbx].$Obj(IncFile).dQualifiers, 0
      jmp @Exit
    .endif
  .endif

  ;Check for names ----------------------------------------------------------
  IsName? pToken
  .if eax != FALSE
    mov xax, pToken
    mov [xbx].$Obj(IncFile).pPrevToken, xax
    DbgPrintF , "¦UD: ParseC - token ¦SA found", [xbx].$Obj(IncFile).dLineNumber, xax
    jmp @Exit
  .endif

  ;Check block  -------------------------------------------------------------
  mov xax, pToken
  .if CHRA ptr [xax] == "{"
    inc [xbx].$Obj(IncFile).dBraces
    mov xax, [xbx].$Obj(IncFile).pStmOutPos
    .if CHRA ptr [xax - 1] == LF
      OCall xbx::IncFile.StmWrite, $OfsCStrA(";{")
      OCall xbx::IncFile.StmWriteEOL
    .endif
    DbgPrintF , "¦UD: ParseC - begin block, new level = ¦UD", \
              [xbx].$Obj(IncFile).dLineNumber, [xbx].$Obj(IncFile).dBraces
  .elseif CHRA ptr [xax] == "}"
    dec [xbx].$Obj(IncFile).dBraces
    mov xax, [xbx].$Obj(IncFile).pStmOutPos
    .if CHRA ptr [xax - 1] == LF
      OCall xbx::IncFile.StmWrite, $OfsCStrA(";}")
      OCall xbx::IncFile.StmWriteEOL
    .endif
    DbgPrintF , "¦UD: ParseC - end block, new level = ¦UD", \
              [xbx].$Obj(IncFile).dLineNumber, [xbx].$Obj(IncFile).dBraces
    mov eax, [xbx].$Obj(IncFile).dBraces
    .if [xbx].$Obj(IncFile).pEndMacro != NULL && eax == [xbx].$Obj(IncFile).dBlockLevel
      OCall xbx::IncFile.StmWriteF, $OfsCStrA("%s_END", LF), [xbx].$Obj(IncFile).pEndMacro
      OCall xbx::IncFile.StmWriteEOL
      mov [xbx].$Obj(IncFile).dBlockLevel, 0
      mov [xbx].$Obj(IncFile).pEndMacro, NULL
    .endif
  .endif

@Exit:
  OCall xbx::IncFile.StmWriteComment
  .if eax != FALSE
    OCall xbx::IncFile.StmWriteEOL
  .endif
  mov eax, TRUE
  ret
ParseC endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  ParsePP
; Purpose:    Parse PreProcessor lines.
; Arguments:  xbx -> IncFile.
; Return:     Nothing.

ParsePP proc uses xsi xdi
  local pToken:PTOKEN

  OCall xbx::IncFile.GetNextTokenFromPPLine
  .if xax != NULL
    mov pToken, xax
    DbgPrintF , "¦UD: ParsePP - PP-Command ¦SA found", [xbx].$Obj(IncFile).dLineNumber, pToken

    .if [xbx].$Obj(IncFile).bSkipScanPP == 0
      ;Find and execute the matching handler for the input Token ------------
      mov xax, pToken
      .if [xbx].$Obj(IncFile).bSkipLogiPP == FALSE
        lea xdi, PreProcCmdHandlerTable
        .if [xbx].$Obj(IncFile).dStmOutEOL == FALSE
          OCall xbx::IncFile.StmWriteEOL
        .endif
      .else
        lea xdi, PreProcCmdNPHandlerTable
      .endif

      .while [xdi].PP_CMD_HANDLER_ENTRY.pCmd != NULL
        invoke BStrCompA, [xdi].PP_CMD_HANDLER_ENTRY.pCmd, pToken
        .if eax == 0
          call [xdi].PP_CMD_HANDLER_ENTRY.pHandler
          jmp @F
        .endif
        add xdi, sizeof PP_CMD_HANDLER_ENTRY
      .endw

      ;If no handler found
      .if [xbx].$Obj(IncFile).bSkipScanPP != 0 || [xbx].$Obj(IncFile).bSkipLogiPP == TRUE
        SkipPPLine
      .else
        OCall xbx::IncFile.StmWriteF, $OfsCStrA(";#%s "), pToken
        OCall xbx::IncFile.StmCopyRestOfPPLine
      .endif
    .else
      SkipPPLine
    .endif
@@:
    ;Consume C-Tokens until the next PP-Line is found -----------------------
    .if [xbx].$Obj(IncFile).bSkipC != FALSE
      mov xdi, [xbx].$Obj(IncFile).pStmInpPos
@@:
      .while CHRA ptr [xdi] != '#'                      ;Always a single character
        .if DCHRA ptr [xdi] == PCT_EOL || DCHRA ptr [xdi] == PCT_WEAKEOL
          inc [xbx].$Obj(IncFile).dLineNumber
        .endif
        mov ecx, -1
        mov al, 0
        repnz scasb
        not ecx
        dec ecx                                         ;ecx = character count
        jz @Exit
      .endw
      .if [xbx].$Obj(IncFile).bSkipUselessCode == FALSE
        OCall xbx::IncFile.StmWrite, $OfsCStrA(";[...]")  ;Visualize that we skipped some lines
        OCall xbx::IncFile.StmWriteEOL
        mov [xbx].$Obj(IncFile).bSkipUselessCode, TRUE
      .endif
      mov [xbx].$Obj(IncFile).pStmInpPos, xdi
    .endif
  .endif
@Exit:
  ret
ParsePP endp
