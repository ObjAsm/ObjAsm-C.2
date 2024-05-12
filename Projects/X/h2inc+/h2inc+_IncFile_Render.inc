; ==================================================================================================
; Title:      h2inc+_IncFile_Render.inc
; Author:     G. Friedrich
; Version:    See h2inc+.asm
; Purpose:    ObjAsm h2inc+ IncFile render procedures.
; ==================================================================================================


include h2inc+_RenderBitField.inc
include h2inc+_RenderBlock.inc
include h2inc+_RenderContainer.inc
include h2inc+_RenderContainerMember.inc
include h2inc+_RenderDefineConst.inc
include h2inc+_RenderEnum.inc
include h2inc+_RenderEnumMember.inc
include h2inc+_RenderExtern.inc
include h2inc+_RenderExternMember.inc
include h2inc+_RenderFurtherTypes.inc
include h2inc+_RenderInterfaceBlock.inc
include h2inc+_RenderMacroCall.inc
include h2inc+_RenderPrototype.inc
include h2inc+_RenderTypedef.inc
include h2inc+_RenderTypedefFunction.inc
include h2inc+_RenderTypedefFuncPtr.inc
include h2inc+_RenderTypedefEnum.inc

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  RenderC
; Purpose:    Translate from C to MASM syntax.
;             The following types of C declarations are known:
;               1. typedef (struct, union, enum)
;               2. struct, union
;               3. extern
;               4. prototypes
;               5. enum
; Arguments:  xbx -> IncFile.
; Return:     eax = TRUE if succeeded, otherwise FALSE.
; Links:      http://www.inf.fu-berlin.de/lehre/WS11/OS/slides/OS_Declarations_in_C_.pdf
;             https://en.wikipedia.org/wiki/C_syntax
;             https://msdn.microsoft.com/en-us/library/bz4heb45.aspx

RenderC proc uses xdi xsi
  local pToken:PTOKEN, pMacroToken:PTOKEN, bAddSpace:DWORD
  local cMacroBuffer[2048]:CHRA, dProtoQualifier:DWORD, .xdi:XWORD, .xsi:XWORD

  ;Set Initial state
  mov [xbx].$Obj(IncFile).bEOF, FALSE
  mov [xbx].$Obj(IncFile).bComment, FALSE
  mov [xbx].$Obj(IncFile).bSkipLineC, 0
  mov [xbx].$Obj(IncFile).bSkipLinePP, 0
  mov [xbx].$Obj(IncFile).dLineNumber, 1
  mov [xbx].$Obj(IncFile).bNewLine, TRUE
  mov [xbx].$Obj(IncFile).pPrevToken, NULL
  mov [xbx].$Obj(IncFile).pImportSpec, NULL
  mov [xbx].$Obj(IncFile).pCallConv, NULL
  mov [xbx].$Obj(IncFile).dQualifiers, 0

  .while TRUE
    OCall xbx::IncFile.GetNextTokenC
@ProcessToken:
    test xax, xax
    jz @Exit
    mov pToken, xax
    OCall xbx::IncFile.StmWriteComment

    mov xax, pToken
    .if CHRA ptr [xax] == ';'                           ;Statement terminator => reset all
      mov [xbx].$Obj(IncFile).pPrevToken, NULL
      mov [xbx].$Obj(IncFile).pImportSpec, NULL
      mov [xbx].$Obj(IncFile).pCallConv, NULL
      mov [xbx].$Obj(IncFile).dQualifiers, 0
      .continue
    .endif

    ;Check annotation ---------------------------------------------------------
    invoke SkipAnnotations, pToken
    test xax, xax
    jz @Exit

    mov pToken, $invoke(TranslateToken, xax)

    ;'typedef' test -----------------------------------------------------------
    DoesStringMatchA? [xax], <typedef>
    jnz @F
    mov xdi, [xbx].$Obj(IncFile).pStmOutPos
    mov esi, [xbx].$Obj(IncFile).dStmOutEoL
    invoke RenderTypedef
    test xax, xax
    jz @Exit
    OCall xbx::IncFile.StmWriteEoL                      ;Only on top level containers
    .ifBitClr $ObjTmpl(Application).Options.dSelectiveOutput, OUTPUT_TYPEDEFS
      ;Restore entrypoint
      mov [xbx].$Obj(IncFile).pStmOutPos, xdi
      mov [xbx].$Obj(IncFile).dStmOutEoL, esi
      mov CHRA ptr [xdi], 0                             ;Set ZTC on output stream
    .endif
    .continue
@@:

    ;'union', 'struct' test ---------------------------------------------------
    .if !$DoesStringMatchA?([xax], <struct>)
      DoesStringMatchA? [xax], <union>
      jnz @F
    .endif
    ;'struct/union' may be a struct/union declaration, but may be a function returning it as well
    ; In that case, ignore struct/union and continue rendering as a proto
    invoke IsFunction?
    .if eax == FALSE
      mov xdi, [xbx].$Obj(IncFile).pStmOutPos
      mov esi, [xbx].$Obj(IncFile).dStmOutEoL
      invoke RenderContainer, pToken                    ;Returns last token
      test xax, xax
      jz @Exit
      mov pToken, xax
      OCall xbx::IncFile.PeekNextTokenC
      .if xax != NULL && CHRA ptr [xax] == '{'
        OCall xbx::IncFile.StmWriteEoL                  ;Only on top level containers
        .ifBitClr $ObjTmpl(Application).Options.dSelectiveOutput, OUTPUT_CONTAINERS
          mov [xbx].$Obj(IncFile).pStmOutPos, xdi
          mov [xbx].$Obj(IncFile).dStmOutEoL, esi
          mov CHRA ptr [xdi], 0
        .endif
        mov xax, pToken
        test xax, xax                                   ;Set/Reset ZF
        jmp @ProcessToken
      .endif
    .endif
    mov xax, pToken
@@:

    ;'extern' test ------------------------------------------------------------
    DoesStringMatchA? [xax], <extern>
    jnz @F
    ;'extern' may be a extern declaration, but may be a function returning it as well
    ; In that case, ignore extern and continue rendering as a proto
    invoke IsFunction?
    .if eax == FALSE
      mov xdi, [xbx].$Obj(IncFile).pStmOutPos
      mov esi, [xbx].$Obj(IncFile).dStmOutEoL
      invoke RenderExtern
      test xax, xax
      jz @Exit
      .ifBitClr $ObjTmpl(Application).Options.dSelectiveOutput, OUTPUT_EXTERNALS
        mov [xbx].$Obj(IncFile).pStmOutPos, xdi
        mov [xbx].$Obj(IncFile).dStmOutEoL, esi
        mov CHRA ptr [xdi], 0
      .endif
      .continue
    .endif
    mov xax, pToken
@@:

    ;'enum' test --------------------------------------------------------------
    .if !$DoesStringMatchA?([xax], <enum>)
      DoesStringMatchA? [xax], <ENUM>
      jnz @F
    .endif
    mov xdi, [xbx].$Obj(IncFile).pStmOutPos
    mov esi, [xbx].$Obj(IncFile).dStmOutEoL
    invoke RenderEnum
    test eax, eax
    jz @Exit
    .ifBitClr $ObjTmpl(Application).Options.dSelectiveOutput, OUTPUT_CONSTANTS
      mov [xbx].$Obj(IncFile).pStmOutPos, xdi
      mov [xbx].$Obj(IncFile).dStmOutEoL, esi
      mov CHRA ptr [xdi], 0
    .endif
    .continue
@@:

    ;'class' test ------------------------------------------------------------
    DoesStringMatchA? [xax], <class>
    jnz @F
    .while !ZERO?
      OCall xbx::IncFile.GetNextTokenC
      test xax, xax
      jz @Exit
      .break .if CHRA ptr [xax] == '{'
    .endw
    invoke GotoClosingToken, '{', '}'
    .continue

@@:
    ;Check qualifier ----------------------------------------------------------

    ;First check if name is a known prototype qualifier.
    ;This may also be a macro. In that case, no macro invocation should be generated.

    invoke GetProtoQualifier, pToken                    ;cdecl, stdcall, declspec(dllimport), ...
    .if xax != NULL
      mov edx, [xax - sizeof(DWORD)]
      mov ecx, [xax + xdx]
      mov dProtoQualifier, ecx                          ;E.g. PTQ_CDECL
      invoke IsMacro?, pToken
      .if eax != 0
        ;OK, it is a macro, check for args in parenthesis
        OCall xbx::IncFile.PeekNextTokenC
        .if xax != NULL && CHRA ptr [xax] == '('
          mov .xsi, xsi
          mov .xdi, xdi
          mov bAddSpace, FALSE
          invoke StrECopyA, addr cMacroBuffer, pToken   ;Macro name
          mov xdi, xax                                  ;End of buffer
          OCall xbx::IncFile.GetNextTokenC              ;Get '('
          test xax, xax
          jz @Exit
          invoke StrECopyA, xdi, xax
          mov xdi, xax                                  ;End of buffer
          mov esi, 1                                    ;esi = parenthesis level
          .repeat
            OCall xbx::IncFile.GetNextTokenC
            .break .if xax == NULL
            invoke SkipAnnotations, xax
            .break .if xax == NULL
            mov pMacroToken, xax
            .if CHRA ptr [xax] == '('
              inc xsi
              mov bAddSpace, FALSE
            .elseif CHRA ptr [xax] == ')'
              dec xsi
              mov bAddSpace, TRUE
            .else
              .if bAddSpace != FALSE
                WriteFA xdi, " "
              .endif
              mov bAddSpace, TRUE                       ;Add space always
            .endif
            invoke StrECopyA, xdi, pMacroToken
            mov xdi, xax
          .until xsi == 0
          mov xsi, .xsi
          mov xdi, .xdi
          lea xax, cMacroBuffer
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
      .continue
    .endif

    ;Check for macro invocation -----------------------------------------------
    .if [xbx].$Obj(IncFile).dQualifiers == 0              ;No previous qualifiers => it is a macro invocation
      invoke IsMacro?, pToken
      .if eax != 0                                        ;Found in the Macro lists
        mov edx, ecx
        .if eax == 1
          OCall pNewMacros::List.ItemAt, edx
        .else
          OCall pKnwMacros::List.ItemAt, edx
        .endif
        mov edx, [xax - sizeof(DWORD)]
        invoke RenderMacroCall, pToken, DWORD ptr [xax + xdx], TRUE
        .if eax != FALSE
          .continue
        .endif
      .endif
    .endif

    ;Check known types --------------------------------------------------------
    .if [xbx].$Obj(IncFile).dQualifiers == 0              ;No previous qualifiers!
      OCall pNewTypedefs::List.Search, pToken
      .if eax != 0
        .continue                                         ;Ignore it
      .endif
    .endif

    ;Check for prototypes -----------------------------------------------------
    mov xax, pToken
    .if CHRA ptr [xax] == '('
      .if [xbx].$Obj(IncFile).pPrevToken != NULL
        mov xdi, [xbx].$Obj(IncFile).pStmOutPos
        mov esi, [xbx].$Obj(IncFile).dStmOutEoL
        invoke RenderPrototype, [xbx].$Obj(IncFile).pPrevToken, [xbx].$Obj(IncFile).pImportSpec
        .ifBitClr $ObjTmpl(Application).Options.dSelectiveOutput, OUTPUT_PROTOTYPES
          mov [xbx].$Obj(IncFile).pStmOutPos, xdi
          mov [xbx].$Obj(IncFile).dStmOutEoL, esi
          mov CHRA ptr [xdi], 0
        .endif
        mov [xbx].$Obj(IncFile).dQualifiers, 0
        .continue
      .endif
    .endif

    ;Check for names ----------------------------------------------------------
    IsValidName? pToken
    .if eax != FALSE
      mov xax, pToken
      mov [xbx].$Obj(IncFile).pPrevToken, xax
      .continue
    .endif

    ;Check for a block  -------------------------------------------------------
    mov xax, pToken
    .if CHRA ptr [xax] == '{'
      inc [xbx].$Obj(IncFile).dBraces
;      mov xax, [xbx].$Obj(IncFile).pStmOutPos
;      .if CHRA ptr [xax - 1] == LF
;        OCall xbx::IncFile.StmWrite, $OfsCStrA(";{")
;        OCall xbx::IncFile.StmWriteEoL
;      .endif
    .elseif CHRA ptr [xax] == '}'
      dec [xbx].$Obj(IncFile).dBraces
;      mov xax, [xbx].$Obj(IncFile).pStmOutPos
;      .if CHRA ptr [xax - 1] == LF
;        OCall xbx::IncFile.StmWrite, $OfsCStrA(";}")
;        OCall xbx::IncFile.StmWriteEoL
;      .endif
      mov eax, [xbx].$Obj(IncFile).dBraces
      .if [xbx].$Obj(IncFile).pEndMacro != NULL && eax == [xbx].$Obj(IncFile).dBlockLevel
        dec [xbx].$Obj(IncFile).dIndentation
        OCall xbx::IncFile.StmWriteF, $OfsCStrA("%hs_END", CRLF), [xbx].$Obj(IncFile).pEndMacro
        OCall xbx::IncFile.StmWriteEoL
        mov [xbx].$Obj(IncFile).dBlockLevel, 0
        mov [xbx].$Obj(IncFile).pEndMacro, NULL
      .endif
    .endif
    OCall xbx::IncFile.StmWriteComment
  .endw

@Exit:
  ret
RenderC endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  RenderPP
; Purpose:    Render PreProcessor lines.
; Arguments:  xbx -> IncFile.
;             Behaviour modifiers: bSkipLineC, bSkipLinePP, bSkipCondPP
; Return:     Nothing.

RenderPP proc uses xdi
  local pToken:PTOKEN

  OCall xbx::IncFile.GetNextTokenPP
  .if xax != NULL
    mov pToken, xax
    .if [xbx].$Obj(IncFile).bSkipLinePP == 0            ;0 = No
      ;Find and execute the matching handler for the input Token ------------------------
      mov xax, pToken
      .if [xbx].$Obj(IncFile).bSkipCondPP == FALSE
;        .if [xbx].$Obj(IncFile).dStmOutEoL == FALSE     ;If no EoL was issued, then
;          OCall xbx::IncFile.StmWriteEoL                ;  start a new line
;        .endif
        lea xdi, PreProcCmdHandlerTable
      .else
        lea xdi, PreProcCmdNPHandlerTable
      .endif

      .while [xdi].PP_CMD_HANDLER_ENTRY.pCmd != NULL
        invoke BStrCompA, [xdi].PP_CMD_HANDLER_ENTRY.pCmd, pToken
        .if eax == 0
          call [xdi].PP_CMD_HANDLER_ENTRY.pHandler
          jmp @F
        .endif
        add xdi, sizeof(PP_CMD_HANDLER_ENTRY)
      .endw

      ;If no handler found
      .if [xbx].$Obj(IncFile).bSkipLinePP != 0 || [xbx].$Obj(IncFile).bSkipCondPP == TRUE
        SkipPPLine
      .else
        OCall xbx::IncFile.StmWriteF, $OfsCStrA(";#%hs "), pToken
        OCall xbx::IncFile.StmCopyRestOfPPLine
        OCall xbx::IncFile.StmWriteEoL
      .endif
    .else
      SkipPPLine
    .endif

@@:
    ;Skip non-functional C code ---------------------------------------------------------
    .if [xbx].$Obj(IncFile).bSkipLineC != FALSE
      ;Consume C-Tokens until the next PP-Line is found
      mov xdi, [xbx].$Obj(IncFile).pStmInpPos
      .while CHRA ptr [xdi] != '#'                      ;Always a single character
        .if DCHRA ptr [xdi] == PCT_EOL || DCHRA ptr [xdi] == PCT_WEAKEOL
          inc [xbx].$Obj(IncFile).dLineNumber
        .endif
        mov ecx, -1
        mov al, 0
        repnz scasb
        not ecx
        dec ecx                                         ;ecx = character count
        jz @Exit                                        ;Exit if no
      .endw
      .if [xbx].$Obj(IncFile).bEnableNFCodeLabel == TRUE
        OCall xbx::IncFile.StmWrite, $OfsCStrA(";[...]")  ;Visualize that we skipped the NF-code
        OCall xbx::IncFile.StmWriteEoL
        mov [xbx].$Obj(IncFile).bEnableNFCodeLabel, FALSE
      .endif
      mov [xbx].$Obj(IncFile).pStmInpPos, xdi
    .endif
  .endif

@Exit:
  ret
RenderPP endp
