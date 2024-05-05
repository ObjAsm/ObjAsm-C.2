; ==================================================================================================
; Title:      h2inc+_RenderDefineConst.inc
; Author:     G. Friedrich
; Version:    See h2inc+.asm
; Purpose:    ObjAsm h2inc+ translation procedures.
; ==================================================================================================


.code

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  RenderDefineConst
; Purpose:    EQU invocation called by PPCH_Define.
; Arguments:  Arg1 -> Name.
; Return:     Nothing.

RenderDefineConst proc uses xdi xsi pName:PSTRINGA
  local pToken:PTOKEN, pStmOutPos:PSTRINGA, pItems:POINTER
  local bExpression:DWORD, bAddSpace:DWORD, InpStat:INP_STAT
  local dTypeCSpec:DWORD, pType:PSTRINGA

  mov pItems, NULL
  invoke SkipCasts
  OCall xbx::IncFile.GetNextTokenPP
  .if ZERO?
    OCall xbx::IncFile.StmWrite, $OfsCStrA("<>")        ;Terminate the equ line
  .else
    ;Find out if the line is an expression ----------------------------------
    mov pToken, xax
    OCall xbx::IncFile.InputStatusSave, addr InpStat
    mov bExpression, FALSE
    mov xax, pToken

    .while xax != NULL
      mov xdi, xax
      invoke IsString?, xax
      .if eax != FALSE
        mov bExpression, FALSE
        .break
      .endif
      mov al, [xdi]
      .if al >= "0" && al <= "9"
        mov bExpression, TRUE
      .elseif al != "(" && al != ")"
        ;Is Alpha?
        .if al != "?" && al != "@" && al != "_"
          .if al < "A" || al > "Z"
            .if al < "a" || al > "z"
              ;False
              invoke IsNumOperator?, DWORD ptr [xdi]
              .if eax != FALSE
                mov bExpression, TRUE
                .break
              .endif
              invoke IsLogOperator?, DWORD ptr [xdi]
              .if eax != FALSE
                mov bExpression, TRUE
                .break
              .endif
            .endif
          .endif
        .endif
      .endif
      OCall xbx::IncFile.GetNextTokenPP
    .endw
    OCall xbx::IncFile.InputStatusLoad, addr InpStat

    ;Write items from PP-Line to the output stream --------------------------
    .if bExpression == FALSE
      OCall xbx::IncFile.StmWriteChar, 3Ch              ;"<"
    .endif
    m2m pStmOutPos, [xbx].$Obj(IncFile).pStmOutPos, xax
    mov pItems, $Create@Stacklist()
    mov xax, pToken
    mov bAddSpace, FALSE
    .while xax != NULL
      DbgPrintF , "¦UD: RenderDefineConst - item ¦SA found", [xbx].$Obj(IncFile).dLineNumber, xdi

      DoesStringMatchA? [xax], <LongToHandle>
      jz @NextTokenPP                                   ;Hack => ignore this macro

      ;pToken may be a basic C type
      mov xdi, xax
      .if pType == NULL
        BasicTypeCScan
        .if dTypeCSpec != 0
          invoke ConvBasicTypeC, dTypeCSpec
          .if xax == NULL                               ;If conversion failed
            lea xax, szUnkType
          .endif
          mov pType, xax
          Add@Stacklist pItems, pType                   ;Save item for later evaluation
          OCall xbx::IncFile.StmWrite, pType
          OCall xbx::IncFile.StmWriteChar, SPC
        .endif
      .endif

      mov eax, $GetCount@Stacklist(pItems)
      .if eax != 0 && CHRA ptr [xdi] != ")" && CHRA ptr [xdi] != "," && bAddSpace != FALSE
        OCall xbx::IncFile.StmWriteChar, SPC
      .endif
      invoke IsMacro?, xdi                              ;If it is a macro, check if it has params
      .if eax != 0
        .if eax == 1
          mov edx, ecx
          OCall pMacros::List.ItemAt, edx
        .else
          mov edx, ecx
          OCall pKnownMacros::List.ItemAt, edx
        .endif
        mov edx, [xax - sizeof(DWORD)]
        mov ecx, DWORD ptr [xax + xdx]
        xor eax, eax
        .ifBitSet ecx, MCF_HAS_PARAMS
          mov eax, TRUE
        .endif
      .endif
      .if CHRA ptr [xdi] == "(" || eax != FALSE
        mov bAddSpace, FALSE
      .else
        mov eax, $GetCount@Stacklist(pItems)
        .if eax == 0 && (CHRA ptr [xdi] == "-" || CHRA ptr [xdi] == "+")
          mov bAddSpace, FALSE
        .else
          mov bAddSpace, TRUE
        .endif
      .endif
      Add@Stacklist pItems, xdi                         ;Save item for later evaluation
      invoke TranslateNumOperator, xdi
      .if edx == FALSE
        invoke TranslateLogOperator, xax
      .endif
      OCall xbx::IncFile.StmWrite, xax

@NextTokenPP:
      OCall xbx::IncFile.GetNextTokenPP
    .endw

    OCall xbx::IncFile.StmDeleteLastSpace
    .if bExpression == FALSE
      OCall xbx::IncFile.StmWriteChar, 3Eh              ;">"
    .endif

    ;If equate is a simple text item, then check if the value is a proto qualifier.
    ;If yes, add new equate to qualifier list.
    mov xax, pStmOutPos                                 ;1st char in 2nd member of equate
    .if $ObjTmpl(Application).Options.dDllImport != DLLIMPORT_DEFPROTO && CHRA ptr [xax] > "9"
      mov esi, $GetCount@Stacklist(pItems)
      xor edi, edi
      .while esi != 0
        dec esi
        mov xax, $GetItem@Stacklist(pItems, esi)
        invoke IsQualifier?, xax                        ;ecx = index into list
        .if eax != 0
          mov edx, ecx
          .if eax == 1
            mov xcx, pQualifiers
          .else                                         ;eax = 2
            mov xcx, pKnownQualifiers
          .endif
          OCall xcx::List.ItemAt, edx
          mov edx, [xax - sizeof(DWORD)]                ;edx = length
          BitSet edi, [xax + xdx]                       ;Get ATTR = PTQ_IMPORT...
        .endif
      .endw

      .if edi != 0
        invoke IsQualifier?, pName                      ;ecx = index into list
        .if eax == 0                                    ;pKnownQualifiers (eax = 2) are immutable
          invoke StrSizeA, pName
          invoke InsertAttr, pQualifiers, pName, eax, edi
        .elseif eax == 1
          mov edx, ecx
          OCall pQualifiers::List.ItemAt, edx
          mov edx, [xax - sizeof(DWORD)]
          BitSet [xax + xdx], edi                       ;Combine with prev qualifiers
        .endif
      .endif
    .endif
  .endif
  OCall xbx::IncFile.StmWriteComment

  Destroy@Stacklist pItems                              ;Restore stack
  ret

@Error:
@ErrorEoF:
  DbgErrorF , "¦SU(¦UD): RenderDefineConst - error", [xbx].$Obj(IncFile).pHeaderFileName, [xbx].$Obj(IncFile).dLineNumber
  Destroy@Stacklist pItems                              ;Restore stack
  ret
RenderDefineConst endp
