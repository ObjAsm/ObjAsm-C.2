; ==================================================================================================
; Title:    h2inc+_IncFile_Parse.inc
; Author:   G. Friedrich
; Version:  C.2.0
; Purpose:  ObjAsm h2inc+ IncFile parser procs.
; Notes:    See h2inc+.asm
; ==================================================================================================


; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure: ParseEqu
; Purpose:   For EQU invocation called by PPCH_Define.
; Arguments: Arg1 -> Name.
; Return:    Nothing.

ParseEqu proc uses xdi xsi pName:PSTRINGA
    local pToken:PTOKEN, pStmOutPos:PSTRINGA, pItems:POINTER
    local bExpression:DWORD, bAddSpace:DWORD, InpStat:INP_STAT
    local dTypeCSpec:DWORD, pType:PSTRINGA

    mov pItems, NULL
    invoke SkipCasts
    OCall xbx::IncFile.GetNextTokenFromPPLine
    .if xax == NULL
      OCall xbx::IncFile.StmWrite, $OfsCStrA("<>")       ;Terminate the equ line
    .else
      ;Find out if the line is an expression ----------------------------------
      mov pToken, xax
      OCall xbx::IncFile.SaveInputStatus, addr InpStat
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
        OCall xbx::IncFile.GetNextTokenFromPPLine
      .endw
      OCall xbx::IncFile.LoadInputStatus, addr InpStat

      ;Write items from PP-Line to the output stream --------------------------
      .if bExpression == FALSE
        OCall xbx::IncFile.StmWriteChar, 3Ch            ;"<"
      .endif
      m2m pStmOutPos, [xbx].$Obj(IncFile).pStmOutPos, xax
      mov pItems, $Create@Stacklist()
      mov xax, pToken
      mov bAddSpace, FALSE
      .while xax != NULL
        DbgPrintF , "¦UD: ParseEqu - item ¦SA found", [xbx].$Obj(IncFile).dLineNumber, xdi

        DoesStringMatchA? [xax], <LongToHandle>
        jz @NextTokenPP                                 ;Hack => ignore this macro

        ;pToken may be a basic C type
        mov xdi, xax
        .if pType == NULL
          BasicTypeCScan
          .if dTypeCSpec != 0
            invoke ConvBasicTypeC, dTypeCSpec
            .if xax == NULL                             ;If conversion failed
              c2m pType, offset szUnkType, xax
            .else
              mov pType, xax
            .endif
            Add@Stacklist pItems, pType                 ;Save item for later evaluation
            OCall xbx::IncFile.StmWrite, pType
            OCall xbx::IncFile.StmWriteChar, SPC
          .endif
        .endif

        mov eax, $GetCount@Stacklist(pItems)
        .if eax != 0 && CHRA ptr [xdi] != ")" && CHRA ptr [xdi] != "," && bAddSpace != FALSE
          OCall xbx::IncFile.StmWriteChar, SPC
        .endif
        invoke IsMacro?, xdi                            ;If it is a macro, check if it has params
        .if eax != 0
          .if eax == 1
            mov edx, ecx
            OCall pMacros::List.ItemAt, edx
          .else
            mov edx, ecx
            OCall pKnownMacros::List.ItemAt, edx
          .endif
          mov edx, [xax - sizeof DWORD]
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
        Add@Stacklist pItems, xdi                       ;Save item for later evaluation
        invoke TranslateNumOperator, xdi
        .if edx == FALSE
          invoke TranslateLogOperator, xax
        .endif
        OCall xbx::IncFile.StmWrite, xax

@NextTokenPP:
        OCall xbx::IncFile.GetNextTokenFromPPLine
      .endw

      OCall xbx::IncFile.StmDeleteLastSpace
      .if bExpression == FALSE
        OCall xbx::IncFile.StmWriteChar, 3Eh            ;">"
      .endif

      ;If equate is a simple text item, then check if the value is a proto qualifier.
      ;If yes, add new equate to qualifier list.
      mov xax, pStmOutPos                                     ;1st char in 2nd member of equate
      .if $ObjTmpl(Application).Options.dDllImport != DLLIMPORT_DEFPROTO && CHRA ptr [xax] > "9"
        mov esi, $GetCount@Stacklist(pItems)
        xor edi, edi
        .while esi != 0
          dec esi
          mov xax, $GetItem@Stacklist(pItems, esi)
          invoke IsQualifier?, xax                      ;ecx = index into list
          .if eax != 0
            .if eax == 1
              mov xdx, pQualifiers
            .else                                       ;eax = 2
              mov xdx, pKnownQualifiers
            .endif
            OCall xdx::List.ItemAt, ecx
            mov edx, [xax - sizeof DWORD]               ;edx = length
            BitSet edi, [xax + xdx]                     ;Get ATTR = PTQ_IMPORT...
          .endif
        .endw

        .if edi != 0
          invoke IsQualifier?, pName                    ;ecx = index into list
          .if eax == 0                                  ;pKnownQualifiers (eax = 2) are immutable
            invoke StrSizeA, pName
            invoke InsertAttr, pQualifiers, pName, eax, edi
          .elseif eax == 1
            OCall pQualifiers::List.ItemAt, ecx
            mov edx, [xax - sizeof DWORD]
            BitSet [xax + xdx], edi                     ;Combine with prev qualifiers
          .endif
        .endif
      .endif
    .endif
    OCall xbx::IncFile.StmWriteComment
    OCall xbx::IncFile.StmWriteEOL

    Destroy@Stacklist pItems                            ;Restore stack
    ret

@Error:
    DbgErrorF , "¦SA(¦UD): ParseEqu - error", [xbx].$Obj(IncFile).pFileName, [xbx].$Obj(IncFile).dLineNumber
    Destroy@Stacklist pItems                            ;Restore stack
    ret
ParseEqu endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure: ParseExternItem
; Purpose:   Get an extern declaration.
; Arguments: Arg1 -> First Token.
; Return:    xax -> Next Token.

ParseExternItem proc uses xdi pToken:PTOKEN
    local dTypeCSpec:DWORD, bFunction:DWORD, bStatic:DWORD, bConst:DWORD
    local pType:PSTRINGA, pName:PSTRINGA, cTransBuffer[128]:CHRA

    mov pType, NULL
    mov pName, NULL
    mov bStatic, FALSE
    mov bFunction, FALSE

    mov xax, pToken                                     ;Use token passed in to this proc
    .while TRUE
      .break .if xax == NULL
      invoke SkipAnnotations, pToken
      .break .if xax == NULL

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
      jz @GetNextToken

      .break .if CHRA ptr [xax] == "}" || CHRA ptr [xax] == ";"   ;Statement terminator

      mov pToken, xax
      invoke IsMacro?, xax
      .if eax != 0
        .if eax == 1
          OCall pMacros::List.ItemAt, ecx
        .else
          OCall pKnownMacros::List.ItemAt, ecx
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
            c2m pType, offset szUnkType, xax
          .else
            mov pType, xax
          .endif
          mov xax, pToken                               ;Process last gattered Token
          .continue
        .endif
      .endif

      mov xax, pToken
      .if $DoesStringMatchA?([xax], <"C">)
        jmp @GetNextToken                               ;Ignore it
      .endif

      mov xax, pToken
      .if $DoesStringMatchA?([xax], <"C++">)
        jmp @GetNextToken                               ;Ignore it
      .endif

      mov xax, pToken
      mov cl, CHRA ptr [xax]
      .if cl == "[" && pName != NULL                   ;"[]" should only come after a valid name
        .repeat                                         ;Ignore it
          OCall xbx::IncFile.GetNextToken
        .until xax == NULL || CHRA ptr [xax] == ";"
        .break
      .endif

      .if cl == "="
        .repeat
          OCall xbx::IncFile.GetNextToken
        .until xax == NULL || CHRA ptr [xax] == ";"
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
          DbgErrorF , "¦SA(¦UD): ParseExternItem - unknown Token 1 ¦SA", [xbx].$Obj(IncFile).pFileName, [xbx].$Obj(IncFile).dLineNumber, pToken
          jmp @Error
        .endif
      .else
        DbgErrorF , "¦SA(¦UD): ParseExternItem - unknown Token 2 ¦SA", [xbx].$Obj(IncFile).pFileName, [xbx].$Obj(IncFile).dLineNumber, pToken
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
    DbgErrorF , "¦SA(¦UD): ParseExternItem - error", [xbx].$Obj(IncFile).pFileName, [xbx].$Obj(IncFile).dLineNumber
    ret
ParseExternItem endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure: ParseFurtherTypes
; Purpose:   Check out if there come some pointer definitions behind.
; Arguments: Arg1 -> Type.
;            Arg2 -> Tag.
;            Arg3 -> Token
; Return:    xax -> Next Token.

ParseFurtherTypes proc uses xdi pType:PSTRINGA, pTag:PSTRINGA, pToken:PTOKEN
    local dPtrCount:DWORD, pName:PSTRINGA, cBuffer[1024]:CHRA, cTransBuffer[128]:CHRA

    mov dPtrCount, 0
    mov pName, NULL
    .while TRUE
      mov xax, pToken
      .if CHRA ptr [xax] == "," || CHRA ptr [xax] == ";"    ;Statement terminator
        .if pName != NULL
          push xax
          mov xdi, pType
          .if xdi == NULL
            mov xdi, pTag
          .endif
          DbgPrintF , "¦UD: ParseFurtherTypes - ¦SA ¦SA", [xbx].$Obj(IncFile).dLineNumber, pName, xdi
          ;Comment out forward declarations
          .if dPtrCount == 0
            invoke StrCompA, pName, xdi
            .if eax == 0
              OCall xbx::IncFile.StmWriteChar, ";"
            .endif
          .endif
          invoke TranslateReservedWord, pName, addr cTransBuffer
          mov pName, xax
          .if dPtrCount == 0
            IsStructure? edi                              ;If the type is a structure, 
            .if eax != FALSE                              ;  then the new type is it too
              IsStructure? pName                          ;Check if it already exist
              .if eax == FALSE
                invoke StrSizeA, pName
                invoke InsertStrg, pStructs, pName, eax
              .endif
            .endif
          .endif

          OCall xbx::IncFile.StmWrite, pName
          OCall xbx::IncFile.StmWrite, $OfsCStrA(" typedef ")
          WritePtr
          OCall xbx::IncFile.StmWrite, xdi
          OCall xbx::IncFile.StmWriteEOL
          pop xax
        .endif
        .break .if CHRA ptr [xax] == ";"                ;Statement terminator
        mov pName, NULL
        mov dPtrCount, 0
      .elseif CHRA ptr [xax] == "*"
        inc dPtrCount
      .else
        invoke TranslateTypeQualifier, pToken
        .if CHRA ptr [xax] != 0
          mov pName, xax
        .endif
      .endif
      OCall xbx::IncFile.GetNextToken
      test xax, xax
      jz @Error
      mov pToken, xax
    .endw
    .if pName != NULL
      OCall xbx::IncFile.StmWriteEOL
    .endif

    ret

@Error:
    DbgErrorF , "¦SA(¦UD): ParseFurtherTypes - error", [xbx].$Obj(IncFile).pFileName, [xbx].$Obj(IncFile).dLineNumber
    ret
ParseFurtherTypes endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure: ParseTypedefFunction
; Purpose:   typedef function occured.
; Arguments: Arg1 -> Name.
;            Arg2: Accept Body flag.
;            Arg3 -> Parent
; Return:    Nothing.
; Syntax:    typedef <qualifiers> returntype name(<parameters>)<{...}>;
;            or in a class definition:
;            <qualifiers> returntype name(<parameters>)<{...}>;

ParseTypedefFunction proc pName:PSTRINGA, bAcceptBody:DWORD, pParent:PSTRINGA
    local pToken:PTOKEN
    local dNum:DWORD, dCallConv:DWORD, dPtrCount:DWORD, bFirstParam:DWORD
    local dTypeCSpec:DWORD, pType:PSTRINGA
    local szFuncName[32]:CHRA, szType[512]:CHRA, szDecoName[1024]:CHRA, cTransBuffer[128]:CHRA

    ;Parse function header ----------------------------------------------------
    mov bFirstParam, FALSE
    invoke TranslateReservedWord, pName, addr cTransBuffer
    mov pName, xax
    .if [xbx].$Obj(IncFile).bInsideClass != FALSE
      mov dNum, 0
      mov xax, pName
      .if CHRA ptr [xax] == "~"
        inc eax
        inc dNum
      .endif
      invoke StrCompA, xax, pParent
      .if eax == 0
        ;invoke sprintf, addr szFuncName, $OfsCStrA("?¦UD"), dNum
        lea eax, szFuncName
        mov pName, xax
      .endif
      mov dCallConv, "A"          ;A = cdecl, G = stdcall
      ;invoke sprintf, addr szDecoName, $OfsCStrA("?¦SA@¦SA@@Q%c___Z"), pName, pParent, dCallConv
      OCall xbx::IncFile.StmWriteF, $OfsCStrA(";externdef syscall %s:near"), addr szDecoName
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
      test xax, xax
      jz @Error

      invoke SkipAnnotations, xax
      test xax, xax
      jz @Error

      .if CHRA ptr [xax] == "*"
        inc dPtrCount
        .continue
      .endif

      .continue .if $DoesStringMatchA?([xax], <struct>) ;Ignore 'struct'
      .continue .if $DoesStringMatchA?([xax], <union>)  ;Ignore 'union'
      .continue .if $DoesStringMatchA?([xax], <enum>)   ;Ignore 'enum'

      ;pToken may be a basic C type
      mov pToken, xax
      .if pType == NULL
        BasicTypeCScan
        mov pToken, xax
        .if dTypeCSpec != 0
          invoke ConvBasicTypeC, dTypeCSpec
          .if xax == NULL                               ;If conversion failed
            c2m pType, offset szUnkType, xax
          .else
            mov pType, xax
            mov xax, pToken
            jmp @ProcessToken
            .continue
          .endif
        .endif
      .endif
      mov pToken, xax
      .if CHRA ptr [xax] == "," || CHRA ptr [xax] == ")"  ;End of function parameter list
        push xax
        .if dPtrCount != 0 || pType != NULL
          .if pType != NULL
            invoke TranslateReservedWord, pType, addr cTransBuffer   ;Maybe it is a reserved word!
            mov pType, xax
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
        pop xax
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
        m2m pType, pToken, eax
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
    DbgErrorF , "¦SA(¦UD): ParseTypedefFunction - error", [xbx].$Obj(IncFile).pFileName, [xbx].$Obj(IncFile).dLineNumber
    ret
ParseTypedefFunction endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure: ParseTypedefFunctionPtr
; Purpose:   typedef function pointer occured.
; Arguments: Arg1 -> Parent.
; Return:    xax -> Last Token, usually ';' or NULL if failed.
;            xdx -> Name.
; Syntax:    typedef function pointer
;            typedef <annotations><qualifiers><returntype> ( <qualifiers> * <name> )(<parameters>)
; Notes:     The first "(" has been read already!
;            This procedure has to be reentrant, since a function parameter may have "function ptr"
;            types. That means, that we have to write to an intermediate buffer (szPrototype) until
;            we returned from the last recursive call.

ParseTypedefFunctionPtr proc uses xdi pParent:PSTRINGA
    local pToken:PTOKEN, pName:PSTRINGA, pType:PSTRINGA
    local dQualifier:DWORD, dPtrCount:DWORD, bFirstParam:DWORD
    local dTypeCSpec:DWORD, dScanStep:DWORD
    local szPrototype[1024*3]:CHRA, szType[128]:CHRA, cTransBuffer[128]:CHRA

    mov dPtrCount, 0
    mov dQualifier, 0
    mov szPrototype, 0
    mov pName, NULL

    ;Get Qualifiers & Name ----------------------------------------------------
    .while TRUE
      OCall xbx::IncFile.GetNextToken
      test xax, xax
      jz @Error
      invoke SkipAnnotations, xax
      test xax, xax
      jz @Error
      mov pToken, xax

      cmp CHRA ptr [xax], ";"                           ;Statement terminator
      jz @Error

      cmp CHRA ptr [xax], "}"                           ;block terminator
      jz @Exit

      .break .if CHRA ptr [xax] == ")"
      .if CHRA ptr [xax] == "*"
        inc dPtrCount
      .else
        invoke GetProtoQualifier, xax
        .if xax != NULL
          mov edx, [xax - sizeof DWORD]
          mov eax, [xax + xdx]
          or dQualifier, eax
        .else
          m2m pName, pToken, eax                        ;Ignore any qualifiers
        .endif
      .endif
    .endw

    DbgPrintF , "¦UD: ParseTypedefFunctionPtr - ¦SA", [xbx].$Obj(IncFile).dLineNumber, pName

    ;Parse function header ----------------------------------------------------
    OCall xbx::IncFile.GetNextToken
    test xax, xax
    jz @Error
    invoke SkipAnnotations, xax
    test xax, xax
    jz @Error
    cmp CHRA ptr [xax], "("
    jnz @Error

    lea xdi, szPrototype                                ;xdi -> Buffer
    xor eax, eax
    .if pName != NULL
      .if ([xbx].$Obj(IncFile).bInsideInterface != FALSE); && (dQualifier & PTQ_STDCALL || dQualifier & PTQ_FASTCALL)
        invoke TranslateReservedWord, pName, addr cTransBuffer
        ;invoke sprintf, xdi, $OfsCStrA("STD_METHOD ¦SA, "), eax ;Use asm adhoc macro
      .else
        invoke GetCallConvString, dQualifier
        .if pParent != NULL
          ;invoke sprintf, xdi, $OfsCStrA("TYPE_¦SA_¦SA typedef proto ¦SA "), pParent, pName, eax
        .else
          ;invoke sprintf, xdi, $OfsCStrA("TYPE_¦SA typedef proto ¦SA "), pName, eax
        .endif
      .endif
      add edi, eax                                      ;Move pointer to the end
    .endif

    ;Parse function parameters ------------------------------------------------
    mov dPtrCount, 0
    mov pType, NULL
    mov bFirstParam, TRUE
    .while TRUE
      OCall xbx::IncFile.GetNextToken
@ProcessToken:
      test xax, xax
      jz @Error
      invoke SkipAnnotations, xax
      test xax, xax
      jz @Error
      .break .if CHRA ptr [xax] == ";"                  ;Statement terminator

      .if CHRA ptr [xax] == "*"
        inc dPtrCount
        .continue
      .endif

      .continue .if $DoesStringMatchA?([xax], <struct>) ;Ignore 'struct'
      .continue .if $DoesStringMatchA?([xax], <union>)  ;Ignore 'union'
      .continue .if $DoesStringMatchA?([xax], <enum>)   ;Ignore 'enum'

      .if CHRA ptr [xax] == "["
        inc dPtrCount
        .repeat
          OCall xbx::IncFile.GetNextToken
        .until xax == NULL || CHRA ptr [xax] == "]" || CHRA ptr [xax] == ";"
        .continue
      .endif

      .if CHRA ptr [xax] == "("
        ;Function ptr as function parameter?
        invoke IsFunctionPtr?
        .if eax != FALSE
          movzx eax, [xbx].$Obj(IncFile).bInsideInterface     ;If we are inside an interface declaration
          push xax                                      ;Then we want to declare a typedef
          mov [xbx].$Obj(IncFile).bInsideInterface, FALSE
          invoke ParseTypedefFunctionPtr, pName         ;Possible recursion here!!!
          mov pToken, xax
          pop xax
          mov [xbx].$Obj(IncFile).bInsideInterface, al
          ;invoke sprintf, addr szType, $OfsCStrA("P¦SA_¦SA"), pName, edx
          lea eax, szType
          mov pType, xax
          mov xax, pToken
          .break .if CHRA ptr [xax] == ";"
        .endif
      .endif

      invoke TranslateTypeQualifier, xax
      .continue .if CHRA ptr [xax] == 0

      ;pToken may be a basic C type -------------------------------------------
      mov pToken, xax
      .if pType == NULL
        BasicTypeCScan
        mov pToken, xax
        .if dTypeCSpec != 0
          invoke ConvBasicTypeC, dTypeCSpec
          .if xax == NULL
            mov xax, offset szUnkType
          .endif
          mov pType, xax
          mov xax, pToken
          jmp @ProcessToken
        .else
          mov pType, xax
        .endif
      .endif

      mov xax, pToken                                   ;Needed
      .if CHRA ptr [xax] == "," || CHRA ptr [xax] == ")"
        .if bFirstParam != FALSE
          mov xcx, pType
          .break .if CHRA ptr [xcx] == 0 && dPtrCount == 0
          .break .if CHRA ptr [xcx] == ")"              ;We have no argument => name()
          FillStringA [xdi], <:>
          add edi, 1
          mov bFirstParam, FALSE
        .else
          FillStringA [xdi], <, :>
          add edi, 3
        .endif

        .while dPtrCount != 0
          FillStringA [xdi], <ptr >
          add edi, 4
          dec dPtrCount
        .endw

        mov xax, pType
        .if xax != NULL && CHRA ptr [xax] != 0
          invoke TranslateReservedWord, pType, addr cTransBuffer
          invoke StrECopy, xdi, xax
          mov edi, eax
        .else
          mov CHRA ptr [xdi], 0
        .endif

        mov xax, pToken
        .break .if CHRA ptr [xax] == ")"                ;Exit here with ')'

        .if CHRA ptr [xdi - 1] == SPC
          dec edi
          mov CHRA ptr [xdi], 0
        .endif

        mov pType, NULL
        mov dPtrCount, 0
        .continue
      .endif

      .if pType == NULL && dPtrCount == 0               ;After an '*' can't come a type
        mov pType, xax
      .endif

    .endw

    .while CHRA ptr [xax] != ";" && CHRA ptr [xax] != ","     ;Consume the rest up to ';' or ','
      OCall xbx::IncFile.GetNextToken
    .endw
    mov pToken, xax

    .if pName != NULL
      OCall xbx::IncFile.StmWrite, addr szPrototype
      OCall xbx::IncFile.StmDeleteLastSpace
      OCall xbx::IncFile.StmWriteEOL

      .if [xbx].$Obj(IncFile).bInsideInterface == FALSE
        .if pParent != NULL
          OCall xbx::IncFile.StmWriteF, $OfsCStrA("P%s_%s"), pParent, pName
        .else
          invoke TranslateReservedWord, pName, addr cTransBuffer
          OCall xbx::IncFile.StmWriteF, $OfsCStrA("%s"), xax
        .endif
        OCall xbx::IncFile.StmWrite, $OfsCStrA(" typedef ptr TYPE")
        .if pParent != NULL
          OCall xbx::IncFile.StmWriteF, $OfsCStrA("%s_%s"), pParent, pName
        .else
          OCall xbx::IncFile.StmWriteF, $OfsCStrA("_%s"), pName
        .endif
        OCall xbx::IncFile.StmWriteEOL
      .endif
    .endif
@Exit:
    mov xdx, pName
    mov xax, pToken
    ret

@Error:
    DbgErrorF , "¦SA(¦UD): ParseTypedefFunctionPtr - error", [xbx].$Obj(IncFile).pFileName, [xbx].$Obj(IncFile).dLineNumber
    mov xdx, pName
    mov xax, pToken
    ret
ParseTypedefFunctionPtr endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure: ParseMemLayoutItem
; Purpose:   Get a struct or union declaration item.
; Arguments: Arg1 -> First Token after 'union' or 'struct' Token.
;            Arg2 -> Struct or union Name.
; Return:    xax -> Last Token, usually ';' or NULL if failed.
; Link:      https://en.cppreference.com/w/c/language/bit_field
; Idea:      Replace _??xx with the name of the parent struct.

ParseMemLayoutItem proc uses xdi pToken:PTOKEN, pMemLayoutName:PSTRINGA
    local dTypeCSpec:DWORD, bBits:DWORD, bStruct:DWORD, bFirst:DWORD, pPrvName:PSTRINGA
    local dFieldCount:DWORD, dRes:DWORD, dPtrCount:DWORD, dBits:DWORD, dNameFlags:DWORD
    local pType:PSTRINGA, pName:PSTRINGA, pDupList:POINTER, pBits:PSTRINGA, pEndToken:PSTRINGA
    local dReturn:DWORD, InpStat:INP_STAT, cTransBuffer[128]:CHRA
    local szMacroBuffer[MAX_BLOCK_NAME]:CHRA, szRecord[64]:CHRA, szBuffer[128]:CHRA, szBits[128]:CHRA

    m2m pPrvName, [xbx].$Obj(IncFile).pStructName, eax
    m2m [xbx].$Obj(IncFile).pStructName, pMemLayoutName, ecx

    mov bBits, FALSE
    mov bStruct, FALSE
    mov dBits, 0
    mov dRes, 0
    mov dFieldCount, 0
    mov pEndToken, NULL

@NextMember:
    mov pBits, NULL
    mov pName, NULL
    mov pType, NULL
    mov pDupList, NULL
    mov dPtrCount, 0

    mov xax, pToken                                     ;Use token passed to this proc
    .while TRUE
      .break .if xax == NULL
      invoke SkipAnnotations, xax
      .break .if xax == NULL
      mov cl, [xax]
      .break .if cl == ";" || cl == "}" || cl == ","
      mov pToken, xax

      ;union ------------------------------------------------------------------
      .if $DoesStringMatchA?([xax], <union>)
        DbgPrintF , "¦UD: ParseMemLayoutItem - ¦SA.union found", [xbx].$Obj(IncFile).dLineNumber, pMemLayoutName
        OCall xbx::IncFile.StmWrite, offset szUnion
        inc [xbx].$Obj(IncFile).dIndentation
        OCall xbx::IncFile.GetNextToken
        test xax, xax
        jz @Error
        mov pToken, xax
        IsName? xax
        .if eax != FALSE
          OCall xbx::IncFile.GetNextToken
          test xax, xax
          jz @Error
        .else
          mov xax, pToken
        .endif
        .if CHRA ptr [xax] == "{"
          invoke GetBlockName, addr szMacroBuffer
          .if xax != NULL
            mov pName, xax
          .endif
          mov dNameFlags, edx

          .if xax != NULL
            .if !$DoesStringMatchA?([xax], <DUMMYUNIONNAME>)  ;Don't write in case of an
              OCall xbx::IncFile.StmWriteChar, SPC            ; embedded union & DUMMY name
              invoke TranslateReservedWord, pName, addr cTransBuffer
              OCall xbx::IncFile.StmWrite, xax
            .endif
          .endif
          OCall xbx::IncFile.StmWriteEOL

          invoke ParseBlock, pName, PBT_MEM_LAYOUT
          test xax, xax
          jz @Exit
          invoke SkipName, pName, dNameFlags
        .else
          OCall xbx::IncFile.ShowError, $OfsCStrA("union without block")
          OCall xbx::IncFile.StmWriteEOL
        .endif
        mov pType, NULL
        mov pName, NULL
        dec [xbx].$Obj(IncFile).dIndentation
        OCall xbx::IncFile.StmWrite, $OfsCStrA("ends")
        OCall xbx::IncFile.StmWriteEOL

        DbgPrintF , "¦UD: ParseMemLayoutItem - end of union", [xbx].$Obj(IncFile).dLineNumber
        jmp @GetNextToken
      .endif

      ;struct -----------------------------------------------------------------
      .if $DoesStringMatchA?([xax], <struct>)
        DbgPrintF , "¦UD: ParseMemLayoutItem - ¦SA.struct found", [xbx].$Obj(IncFile).dLineNumber, pMemLayoutName
        OCall xbx::IncFile.GetNextToken
        .if xax == NULL || CHRA ptr [xax] == ";"        ;Statement terminator
          jmp @Error
        .endif
        DbgPrintF , "¦UD: ParseMemLayoutItem - ¦SA.struct, next token ¦SA", [xbx].$Obj(IncFile).dLineNumber, pMemLayoutName, xax
        .if CHRA ptr [xax] != "{"
          mov pName, xax
          OCall xbx::IncFile.PeekNextToken
          .if xax != NULL && CHRA ptr [xax] == "{"
            OCall xbx::IncFile.GetNextToken
          .else
            mov xax, pName
            mov pName, NULL
          .endif
        .endif
        .if CHRA ptr [xax] == "{"
          OCall xbx::IncFile.StmWrite, offset szStruct
          inc [xbx].$Obj(IncFile).dIndentation
          invoke GetBlockName, addr szMacroBuffer       ;xax -> Name, edx = flags (if name is a macro)
          .if xax != NULL
            mov pName, xax
          .endif
          mov dNameFlags, edx

          .if xax != NULL
            .if !$DoesStringMatchA?([xax], <DUMMYSTRUCTNAME>) ;Don't write in case of an
              OCall xbx::IncFile.StmWriteChar, SPC            ; embedded structure & DUMMY name
              invoke TranslateReservedWord, pName, addr cTransBuffer
              OCall xbx::IncFile.StmWrite, xax
            .endif
          .endif
          OCall xbx::IncFile.StmWriteEOL

          invoke ParseBlock, pName, PBT_MEM_LAYOUT
          test xax, xax
          jz @Exit

          invoke SkipName, pName, dNameFlags

          ;In case that the structure is repeated [...], we ignore it ---------
          OCall xbx::IncFile.PeekNextToken
          .if xax != NULL && CHRA ptr [xax] == "["
            OCall xbx::IncFile.GetNextToken
            invoke SkipBraces, "[", "]"
          .endif

          dec [xbx].$Obj(IncFile).dIndentation
          OCall xbx::IncFile.StmWrite, $OfsCStrA("ends")
          OCall xbx::IncFile.StmWriteEOL
          DbgPrintF , "¦UD: ParseMemLayoutItem - end of struct", [xbx].$Obj(IncFile).dLineNumber

        .elseif CHRA ptr [xax] == "*"
          inc dPtrCount

        .else
          ;Found struct tag ---------------------------------------------------
          mov pType, xax                                ;Name of structure
          mov pName, NULL
          mov dPtrCount, 0
          IsName? xax
          .if eax != FALSE
            .while TRUE
              OCall xbx::IncFile.GetNextToken
              test xax, xax
              jz @Error
              mov cl, [xax]
              .if cl == "["                             ;It is an array of structures!
                jmp @DUP
              .endif
              .break .if cl == ";" || cl == ","
              .if CHRA ptr [xax] == "*"
                inc dPtrCount
              .else
                invoke TranslateTypeQualifier, xax
                .continue .if CHRA ptr [xax] == 0
                push xax
                IsName? xax
                pop xcx
                .if eax != FALSE
                  mov pName, xcx
                .endif
              .endif
            .endw
            .if pName != NULL
              .if pType != NULL && dPtrCount == 0
                OCall xbx::IncFile.StmWriteF, $OfsCStrA("%s %s <>"), pName, pType
                OCall xbx::IncFile.StmWriteEOL
              .else
                OCall xbx::IncFile.StmWriteF, $OfsCStrA("%s POINTER ?"), pName
                OCall xbx::IncFile.StmWriteEOL
              .endif
            .else
              mov bStruct, TRUE
              jmp @GetNextToken
            .endif
          .else
            OCall xbx::IncFile.ShowError, $OfsCStrA("unexpected MemLayoutItem %s after 'struct'"), pType
          .endif
        .endif
        mov pType, NULL
        mov pName, NULL
        mov dPtrCount, 0
        jmp @GetNextToken
      .endif

      ;Skip the following keywords --------------------------------------------
      .if $DoesStringMatchA?([xax], <static>)
        jmp @GetNextToken
      .endif

      .if $DoesStringMatchA?([xax], <enum>)
        jmp @GetNextToken
      .endif

      .if $DoesStringMatchA?([xax], <const>)
        jmp @GetNextToken
      .endif

      .if $DoesStringMatchA?([xax], <friend>)
        jmp @GetNextToken
      .endif

      .if $DoesStringMatchA?([xax], <virtual>)
        jmp @GetNextToken
      .endif

      ;private or protected ---------------------------------------------------
      IsPublicPrivateProtected? xax
      .if eax != FALSE
        OCall xbx::IncFile.PeekNextToken
        .if xax != NULL && CHRA ptr [xax] == ":"
          OCall xbx::IncFile.GetNextToken
          jmp @GetNextToken
        .endif
      .endif

      ;macro ------------------------------------------------------------------
      invoke IsMacro?, pToken
      .if eax != 0
        .if eax == 1
          OCall pMacros::List.ItemAt, ecx
        .else
          OCall pKnownMacros::List.ItemAt, ecx
        .endif
        mov edx, [xax - sizeof DWORD]                   ;edx = length
        invoke ParseMacroCall, pToken, DWORD ptr [xax + xdx], TRUE
        .if eax != FALSE
          jmp @GetNextToken
        .endif
      .endif

      ;equate containing items ------------------------------------------------
      invoke IsEquate?, pToken
      .if eax != 0
        .if eax == 1
          OCall pEquates::List.ItemAt, ecx
        .else
          OCall pKnownEquates::List.ItemAt, ecx
        .endif
        mov edx, [xax - sizeof DWORD]                   ;edx = length

        .ifBitSet DWORD ptr [xax + xdx], EQF_HAS_EOL 
          OCall xbx::IncFile.StmWrite, pToken
          OCall xbx::IncFile.StmWriteEOL
          jmp @GetNextToken
        .endif
      .endif

      ;Record -----------------------------------------------------------------
      mov xax, pToken
      .if CHRA ptr [xax] == ":"                         ;Record field
        lea edi, szBits
        mov pBits, xdi
        mov bFirst, TRUE
        .while TRUE
          OCall xbx::IncFile.GetNextToken
          mov pToken, xax
          .break .if xax == NULL
          mov cl, [xax]
          .break .if cl == ";" || cl == "}" || cl == ","
          .if bFirst != FALSE
            mov bFirst, FALSE
          .else
            mov DCHRA ptr [xdi], SPC
            inc edi
          .endif
          invoke TranslateNumOperator, pToken
          .if edx == FALSE
            invoke TranslateLogOperator, xax
          .endif
          invoke StrECopy, xdi, xax
          mov edi, eax
        .endw
        .continue
      .endif

      ;Function or FunctionPtr ------------------------------------------------
      mov xax, pToken
      .if CHRA ptr [xax] == "("
        invoke IsFunctionPtr?
        .if eax != FALSE
          invoke ParseTypedefFunctionPtr, NULL
          .continue
        .else
          invoke IsFunction?
          .if eax != FALSE
            mov xax, pName
            test xax, xax
            cmovz xax, pType
            invoke ParseTypedefFunction, xax, FALSE, NULL
            .continue
          .endif
        .endif
      .endif

      ;Array ------------------------------------------------------------------
      mov xax, pToken
      .if CHRA ptr [xax] == "["                         ;Array => DUP
@DUP:
        .if pType != NULL || pName != NULL              ;Only of we have a Type & a Name
          mov pDupList, $Create@Stacklist()
          .while TRUE
            OCall xbx::IncFile.GetNextToken
            .if xax == NULL || CHRA ptr [xax] == ";"    ;Statement terminator
              jmp @Error
            .endif
            .break .if CHRA ptr [xax] == "]"
            Add@Stacklist pDupList, xax                 ;Add Tokens to the DUP-List
          .endw
          jmp @GetNextToken
        .endif
      .endif

      ;Pointer ----------------------------------------------------------------
      mov xax, pToken
      mov cl, [xax]
      .if cl == "*" || cl == "&"
        inc dPtrCount
        jmp @GetNextToken
      .endif

      invoke TranslateTypeQualifier, pToken
      cmp CHRA ptr [xax], 0
      jz @GetNextToken
      mov pToken, xax

      ;pToken may be a basic C type -------------------------------------------
      .if pType == NULL
        BasicTypeCScan
        mov pToken, xax                                 ;Last gattered Token
        .if dTypeCSpec != 0
          invoke ConvBasicTypeC, dTypeCSpec
          .if xax == NULL                               ;If conversion failed
            mov xax, offset szUnkType
          .endif
          mov pType, xax
          mov xax, pToken
          .continue                                     ;Process the last gattered Token
        .endif
      .endif
      
      IsName? pToken
      .if eax != FALSE
        mov xcx, pToken
        .if pType == NULL
          mov pType, xcx
        .elseif pName == NULL
          mov pName, xcx
        .else
          jmp @Error
        .endif
      .else
        jmp @Error
      .endif

@GetNextToken:
      OCall xbx::IncFile.GetNextToken
    .endw
    mov pEndToken, xax

    ;Write member to stream ---------------------------------------------------
    .if pBits != NULL                                   ;Check for bit field => record
      .if pName == NULL                                 ;It is possible that NO name is supplied!
        lea eax, szBuffer                               ;=> create one
        mov pName, xax
        ;invoke sprintf, eax, $OfsCStrA("Bitfield¦UD"), dFieldCount
      .endif

      ;Write record declaration -----------------------------------------------
      .if bBits == FALSE
        mov bBits, TRUE
        DbgPrintF , "¦UD: ParseMemLayoutItem - new Bitfield: ¦SA", [xbx].$Obj(IncFile).dLineNumber, pType
        mov xcx, $OfsCStrA("DUMMYRECORDNAME")
        mov xax, pMemLayoutName
        .if xax != NULL                                 ;Unnamed struct or union
          .if !$DoesStringMatchA?([xax], <DUMMYSTRUCTNAME>)
            .if !$DoesStringMatchA?([xax], <DUMMYUNIONNAME>)
              mov ecx, eax
            .endif
          .endif
        .endif
        ;invoke sprintf, addr szRecord, $OfsCStrA("¦SA_??¦UD"), ecx, g_dRecordNameSufix
        .if $ObjTmpl(Application).Options.bNoRecords == FALSE
          OCall xbx::IncFile.StmWrite, addr szRecord
          OCall xbx::IncFile.StmWrite, $OfsCStrA(" record ")
        .endif
      .endif

      .if $ObjTmpl(Application).Options.bNoRecords == FALSE
        DbgPrintF , "¦UD: ParseMemLayoutItem - new bits: ¦SA", [xbx].$Obj(IncFile).dLineNumber, pName
        OCall xbx::IncFile.StmWriteF, $OfsCStrA("%s_??%u:%s"), pName, $ObjTmpl(Application).dRecordNameSufix, pBits
      .else
        invoke dec2dwordA, pBits
        mov ecx, dBits
        xor edx, edx
        .while eax != 0
          bts edx, ecx
          inc ecx
          dec eax
        .endw
        mov dBits, ecx
        OCall xbx::IncFile.StmWriteF, $OfsCStrA("%s_%s equ 0%xh"), addr szRecord, pName, edx
        OCall xbx::IncFile.StmWriteEOL
      .endif

      ;Determine if we are at the end of a record declaration -----------------
      OCall xbx::IncFile.SaveInputStatus, addr InpStat
      inc [xbx].$Obj(IncFile).bSkipScanPP
      mov dReturn, TRUE
      .while TRUE
        OCall xbx::IncFile.GetNextToken
        .break .if xax == NULL
        .continue .if !IsIfLevelActive?(InpStat)
        mov cl, [xax]
        .break .if cl == "," || cl == ";"                 ;Statement terminator
        .if cl == ":"
          mov dReturn, FALSE
          .break
        .endif
      .endw
      dec [xbx].$Obj(IncFile).bSkipScanPP
      OCall xbx::IncFile.LoadInputStatus, addr InpStat

      .if dReturn != FALSE
        inc $ObjTmpl(Application).dRecordNameSufix
        .if $ObjTmpl(Application).Options.bNoRecords == FALSE
          OCall xbx::IncFile.StmWriteEOL
        .endif
        .if $ObjTmpl(Application).Options.bRecordsInUnions != FALSE
          OCall xbx::IncFile.StmWrite, offset szUnion
          OCall xbx::IncFile.StmWriteEOL
          ;Tab here
          OCall xbx::IncFile.StmWrite, pType
          OCall xbx::IncFile.StmWrite, $OfsCStrA(" ?")
          OCall xbx::IncFile.StmWriteEOL
        .elseif $ObjTmpl(Application).Options.bNoRecords != FALSE
          OCall xbx::IncFile.StmWriteF, $OfsCStrA("%s "), addr szRecord 
          IsStructure? pType
          .if eax != FALSE
            OCall xbx::IncFile.StmWrite, $OfsCStrA("<>")
          .else
            OCall xbx::IncFile.StmWriteChar, "?"
          .endif
          OCall xbx::IncFile.StmWriteEOL
        .endif

        .if $ObjTmpl(Application).Options.bNoRecords == FALSE
          OCall xbx::IncFile.StmWrite, addr szRecord
          OCall xbx::IncFile.StmWrite, $OfsCStrA(" <>")
          OCall xbx::IncFile.StmWriteEOL
        .endif
        .if $ObjTmpl(Application).Options.bRecordsInUnions != FALSE
          OCall xbx::IncFile.StmWrite, $OfsCStrA("ends")
          OCall xbx::IncFile.StmWriteEOL
        .endif

      .else
        .if $ObjTmpl(Application).Options.bNoRecords == FALSE
          OCall xbx::IncFile.StmWrite, $OfsCStrA(", ")
        .endif
        inc dFieldCount
        OCall xbx::IncFile.GetNextToken
        mov pToken, xax
        jmp @NextMember
      .endif

    .elseif pName != NULL
      ;Write regular struct/union member --------------------------------------
      .if dPtrCount != 0
        c2m pType, $OfsCStrA("POINTER"), xax
      .else
        .if pType == NULL
          IsStructure? pName
          .if eax != FALSE
            xor eax, eax
            xchg xax, pName
            mov pType, xax
          .endif
        .endif
      .endif

      .if pName != NULL
        invoke TranslateReservedWord, pName, addr cTransBuffer
        OCall xbx::IncFile.StmWrite, xax
      .endif
      .if pType != NULL
        OCall xbx::IncFile.StmWriteChar, SPC
        invoke TranslateReservedWord, pType, addr cTransBuffer
        OCall xbx::IncFile.StmWrite, xax
        .if pDupList != NULL
          OCall xbx::IncFile.StmWriteChar, SPC
          invoke WriteStackList, pDupList
          OCall xbx::IncFile.StmWrite, $OfsCStrA($Esc(" dup \{"))
        .else
          OCall xbx::IncFile.StmWriteChar, SPC
        .endif
        IsStructure? pType
        .if eax != FALSE
          OCall xbx::IncFile.StmWrite, $OfsCStrA("<>")
        .else
          OCall xbx::IncFile.StmWriteChar, "?"
        .endif
        .if pDupList != NULL
          OCall xbx::IncFile.StmWriteChar, 29h          ;")"
        .endif
      .endif
      OCall xbx::IncFile.StmWriteComment
      OCall xbx::IncFile.StmWriteEOL
      ;------------------------------------------------------------------------

      mov xax, pToken
      .if xax != NULL && CHRA ptr [xax] == ","
        OCall xbx::IncFile.GetNextToken
        mov pToken, xax
        jmp @NextMember
      .endif
    .endif

@Exit:
  Destroy@Stacklist pDupList
  mov xax, pEndToken
  ret

@Error:
  DbgErrorF , "¦SA(¦UD): ParseMemLayoutItem - error", [xbx].$Obj(IncFile).pFileName, [xbx].$Obj(IncFile).dLineNumber
  m2m [xbx].$Obj(IncFile).pStructName, pPrvName, eax
  OCall xbx::IncFile.ShowError, $OfsCStrA("unexpected '%s' MemLayoutItem: %s"), pMemLayoutName, pToken
  mov xax, pEndToken
  ret
ParseMemLayoutItem endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure: ParseEnumItem
; Purpose:   Get an enum item declaration.
; Arguments: Arg1 -> Token.
; Return:    xax -> Last Token, usually ';' or NULL if failed.
; Idea:      linear code, not looping.

ParseEnumItem proc uses xdi pToken:PTOKEN
  GED_MacroInvocation macro
    invoke IsMacro?, pToken
    .if eax != 0
      .if eax == 1
        OCall pMacros::List.ItemAt, ecx
      .else
        OCall pKnownMacros::List.ItemAt, ecx
      .endif
      mov edx, [xax - sizeof DWORD]                 ;edx = length
      invoke ParseMacroCall, pToken, DWORD ptr [xax + xdx], FALSE
      mov bFirstToken, FALSE
      jmp @GetNextToken
    .endif
  endm

  local sdValue:SDWORD, dStep:DWORD, bFirstToken:DWORD, bNegative:DWORD, cTransBuffer[128]:CHRA

  mov xax, pToken                                       ;Use token passed to this proc
  mov sdValue, 0
  .while TRUE
    mov dStep, 0
    mov bFirstToken, TRUE
    .while TRUE
      .if xax == NULL || CHRA ptr [xax] == ";"          ;Statement terminator
        jmp @Error
      .endif

      .if dStep == 0
        .if CHRA ptr [xax] == "," || CHRA ptr [xax] == "}"  ;Item terminator or end of declaration
          .break
        .endif

        GED_MacroInvocation

        mov xax, pToken
        invoke TranslateReservedWord, xax, addr cTransBuffer
        OCall xbx::IncFile.StmWrite, xax
        mov dStep, 1
        jmp @GetNextToken
      .endif

      .if dStep == 1
        mov xax, pToken
        .if CHRA ptr [xax] == "," || CHRA ptr [xax] == "}"  ;Item terminator or end of declaration
          OCall xbx::IncFile.StmWriteF, $OfsCStrA(" equ %d"), sdValue
          inc sdValue
          OCall xbx::IncFile.StmWriteEOL
          .break
        .endif

        .if CHRA ptr [xax] == "="
          OCall xbx::IncFile.StmWrite, $OfsCStrA(" equ ") ;Use equ (unchangeable)
          mov bFirstToken, TRUE
          mov bNegative, FALSE
          mov dStep, 2
          jmp @GetNextToken
        .endif
      .endif

      .if dStep == 2
        .if bFirstToken != FALSE
          .if CHRA ptr [xax] == "," || CHRA ptr [xax] == "}"
            OCall xbx::IncFile.StmWriteF, $OfsCStrA("%d"), sdValue
            inc sdValue
            OCall xbx::IncFile.StmWriteEOL
            .break
          .endif
        .else
          .if CHRA ptr [xax] == "," || CHRA ptr [xax] == "}"
            OCall xbx::IncFile.StmDeleteLastSpace
            OCall xbx::IncFile.StmWriteEOL
            .break
          .endif
        .endif

        GED_MacroInvocation

        mov xax, pToken
        .if CHRA ptr [xax] == "("                     ;On enumerations, we will skip ... = (int) xxxx
          mov bFirstToken, FALSE
          invoke SkipBraces, "(", ")"
          test xax, xax
          jz @Error
          jmp @GetNextToken
        .endif

        .if (CHRA ptr [xax] == "-" || CHRA ptr [xax] == "+") && bFirstToken != FALSE
          .if CHRA ptr [xax] == "-"
            mov bNegative, TRUE
          .endif
          OCall xbx::IncFile.StmWrite, xax
          mov bFirstToken, FALSE
          jmp @GetNextToken
        .endif

        invoke TranslateNumOperator, xax
        OCall xbx::IncFile.StmWrite, xax
        OCall xbx::IncFile.StmWriteChar, SPC
        mov bFirstToken, FALSE

        mov xax, pToken
        .if CHRA ptr [xax] >= "0"
          invoke dec2dwordA, pToken
          inc eax                                       ;Increment for next enum item
          .if bNegative != FALSE
            neg eax
            inc eax
          .endif
          mov sdValue, eax
        .endif
      .endif

@GetNextToken:
      OCall xbx::IncFile.GetNextToken
      mov pToken, xax
    .endw
    mov xax, pToken
    .break .if CHRA ptr [xax] == "}"                    ;Statment terminator
    OCall xbx::IncFile.GetNextToken
    mov pToken, xax
  .endw

  mov xax, pToken
  ret

@Error:
  DbgErrorF , "¦SA(¦UD): ParseEnumItem - error", [xbx].$Obj(IncFile).pFileName, [xbx].$Obj(IncFile).dLineNumber
  OCall xbx::IncFile.ShowError, $OfsCStrA("unexpected enum item = %s"), pToken
  mov xax, pToken
  ret
ParseEnumItem endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure: ParseBlock
; Purpose:   Get members of a block (structure, union, enum).
; Arguments: Arg1 -> Name.
;            Arg2: Mode.
;              PBT_MEM_LAYOUT: variable declaration in (struct|union)
;              PBT_EXTERN: extern declaration.
;              PBT_ENUM: enum declaration.
; Return:    xax -> Last Token or NULL if failed.

ParseBlock proc uses xsi pName:PSTRINGA, dMode:DWORD
    local wIf:WORD

    movzx eax, [xbx].$Obj(IncFile).bIfLevel
    mov ah, [xbx].$Obj(IncFile).bIfStructure[xax - 1]
    mov wIf, ax

    mov esi, 1
    .repeat
      OCall xbx::IncFile.GetNextToken
      .break .if xax == NULL
      invoke SkipAnnotations, xax
      .break .if xax == NULL

      movzx ecx, [xbx].$Obj(IncFile).bIfLevel
      mov ch, [xbx].$Obj(IncFile).bIfStructure[xcx - 1]
      .if (cl == BYTE ptr wIf) && (ch != BYTE ptr wIf + 1)
        mov [xbx].$Obj(IncFile).pPrevToken, xax
        mov [xbx].$Obj(IncFile).bUsePrevToken, TRUE
        xor eax, eax
        jmp @Exit
      .endif

      .if CHRA ptr [xax] == "{"
        inc esi
        .continue

      .elseif CHRA ptr [xax] == "}"
        dec esi

      .else
        .if dMode == PBT_ENUM
          invoke ParseEnumItem, xax

        .elseif dMode == PBT_MEM_LAYOUT
          invoke ParseMemLayoutItem, xax, pName

        .else
          invoke ParseExternItem, xax
        .endif

        .break .if xax == NULL
        .if CHRA ptr [xax] == "}"
          dec esi
        .endif
      .endif
    .until esi == 0

@Exit:
    DbgPrintF , "¦UD: ParseBlock - ¦SA, end of struct found [¦UD]", [xbx].$Obj(IncFile).dLineNumber, pName, eax
    ret
ParseBlock endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure: ParseInterfaceBlock
; Purpose:   Get members of a block (structure, union, enum).
; Arguments: Arg1 -> Name.
;            xax -> '{'
; Return:    xax -> Last Token or NULL if failed.

ParseInterfaceBlock proc pName:PSTRINGA
    mov [xbx].$Obj(IncFile).bInsideInterface, TRUE
    .repeat
      invoke ParseTypedefFunctionPtr, NULL
;      invoke ParseMemLayoutItem, xax, pName
      .break .if xax == NULL
      .if CHRA ptr [xax] == ";"
        OCall xbx::IncFile.PeekNextToken
        .break .if xax == NULL
        .if CHRA ptr [xax] == "}"
          OCall xbx::IncFile.GetNextToken               ;Consume it
          .break
        .endif
      .else
        jmp @Error
      .endif
    .until FALSE
    mov [xbx].$Obj(IncFile).bInsideInterface, FALSE
    ret

@Error:
    DbgPrintF , "¦UD: ParseInterfaceBlock - ¦SA, end of struct found [¦UD]", [xbx].$Obj(IncFile).dLineNumber, pName, eax
    mov [xbx].$Obj(IncFile).bInsideInterface, FALSE
    xor eax, eax
    ret
ParseInterfaceBlock endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure: ParseTypedefEnum
; Purpose:   Parse 'typedef enum'.
; Arguments: Arg1: Typedef flag.
; Return:    TRUE if succeeded, otherwise FALSE
; Syntax:    <typedef> <qualifiers> enum <tname> {x<=a>,y<=b>,...} name<,*name>;
;            <typedef> <qualifiers> enum <tname> <:type> {x<=a>,y<=b>,...} name<,*name>;
;            <typedef> <qualifiers> enum <class> <tname> <: type> {x<=a>,y<=b>,...} name<,*name>;
;            simplest form is "enum {x = a, y = b};"

ParseTypedefEnum proc uses xdi bIsTypedef:BOOL
    local pTag:PTOKEN, pName:PTOKEN, pType:PSTRINGA, pToken:PTOKEN
    local szBlockName[MAX_BLOCK_NAME]:CHRA, szType[100]:CHRA
    local dTypeCSpec:DWORD, dScanStep:DWORD

    mov pTag, NULL
    mov pName, NULL
    mov pType, NULL

    OCall xbx::IncFile.GetNextToken
    invoke SkipAnnotations, xax
    test xax, xax
    jz @Error
    invoke SkipMacros, xax
    test xax, xax
    jz @Error

    .if CHRA ptr [xax] != "{" && CHRA ptr [xax] != ":"
      mov pTag, xax
      OCall xbx::IncFile.GetNextToken
    .endif
    mov pToken, xax

    .if xax != NULL && CHRA ptr [xax] == ":"            ;Type specified?
      OCall xbx::IncFile.GetNextToken
      test xax, xax
      jz @Error

      ;pToken may be a basic C type
      BasicTypeCScan
      .if dTypeCSpec != 0
        mov pToken, xax                                 ;Last gattered Token
        invoke ConvBasicTypeC, dTypeCSpec
        .if xax == NULL                                 ;If conversion failed
          mov xax, offset szUnkType
        .endif
        mov pType, xax
      .else
        mov pType, xax
        OCall xbx::IncFile.GetNextToken
        test xax, xax
        jz @Error
        mov pToken, xax
      .endif
    .else
      c2m pType, $OfsCStrA("SDWORD"), xax               ;Default enum type
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
      .if xax != NULL && pName != NULL && CHRA ptr [xax] != ";"
        invoke ParseFurtherTypes, pName, NULL, xax
      .else
        OCall xbx::IncFile.StmWriteEOL                  ;Separator line
      .endif

      mov eax, TRUE

    .else
      ;Syntax "typedef <Annotation> enum OldTypeName <*> NewTypeName;
      push xax
      IsName? xax
      pop xcx
      .if eax != FALSE
        OCall xbx::IncFile.StmWriteF, $OfsCStrA("%s typedef %s"), xcx, pType
        OCall xbx::IncFile.StmWriteEOL
        mov eax, TRUE
      .elseif CHRA ptr [xcx] == "*"
        OCall xbx::IncFile.GetNextToken
        .if xax != NULL
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
    DbgErrorF , "¦SA(¦UD): ParseTypedefEnum - error", [xbx].$Obj(IncFile).pFileName, [xbx].$Obj(IncFile).dLineNumber
    ret
ParseTypedefEnum endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure: ParseTypedefUnionStruct
; Purpose:   Parse Typedef of a structure or union.
; Arguments: Arg1 -> MemLayoutType (structure or union).
;            Arg2: Inside class flag.
;            xbx -> IncFile.
; Return:    Nothing
; Syntax:    class tname {};
;            typedef struct/union <macro> tname name;
;            typedef struct/union <macro> <tname> {} name;
;            typedef struct/union <macro> <tname> * name;

ParseTypedefUnionStruct proc pMemLayoutType:PSTRINGA, bInsideClass:BOOL
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
    c2m pMemLayoutType, offset szStruct, xax
    mov [xbx].$Obj(IncFile).bInsideClass, TRUE
  .endif
  DbgPrintF , "¦UD: ParseTypedefUnionStruct - ¦SA", [xbx].$Obj(IncFile).dLineNumber, pMemLayoutType
  OCall xbx::IncFile.GetNextToken
  invoke SkipAnnotations, xax
  test xax, xax
  jz @Error
  invoke SkipMacros, xax
  test xax, xax
  jz @Error

  .if CHRA ptr [xax] != "{"
    DbgPrintF , "¦UD: ParseTypedefUnionStruct - token ¦SA assumed tag", [xbx].$Obj(IncFile).dLineNumber, xax
    lea xdx, szName
    invoke TranslateReservedWord, xax, xdx
    mov pTag, xax
    mov pName, xax
    OCall xbx::IncFile.GetNextToken
  .endif
  test xax, xax
  jz @Error

  .if CHRA ptr [xax] == ":"
    .if 0; (!bInsideClass)
      ;invoke printf, $OfsCStrA("¦SA(¦UD): C++ syntax found", LF), [xbx].$Obj(IncFile).pFileName,
      ;               [xbx].$Obj(IncFile).dLineNumber
    .endif
    .while TRUE
      OCall xbx::IncFile.GetNextToken
      .if xax == NULL || CHRA ptr [xax] == ";"        ;Statement terminator
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

  DbgPrintF , "¦UD: ParseTypedefUnionStruct - token ¦SA found", [xbx].$Obj(IncFile).dLineNumber, xax

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
      lea eax, szNoName
    .endif
    lea xdx, szName
    invoke TranslateReservedWord, xax, xdx
    mov pName, xax
    IsStructure? pName
    .if eax == FALSE
      invoke StrSizeA, pName
      invoke InsertStrg, pStructs, pName, eax
    .endif
    c2m pSuffix, offset szEmpty, xax
    .if pInherit != NULL
      invoke HasVirtualBase?, pInherit
      .if eax != FALSE
        c2m pSuffix, $OfsCStrA("$"), xax
      .endif
    .endif

    OCall xbx::IncFile.StmWriteF, $OfsCStrA("%s%s %s"), pName, pSuffix, pMemLayoutType

    ;Get known structure alignment
    OCall pAlignments::List.Search, pName
    .if eax != FALSE
      OCall pAlignments::List.ItemAt, ecx
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
      invoke ParseBlock, pName, PBT_MEM_LAYOUT
      test xax, xax
      jz @Exit
      mov pToken, xax
    .endif
    .if pInherit != NULL
      invoke HasVirtualBase?, pInherit
      .if xax != NULL
        ;OCall xbx::IncFile.StmWriteF, $OfsCStrA("%s %s %s"), pName, pMemLayoutType, pAlignment
        OCall xbx::IncFile.StmWriteF, $OfsCStrA("%s %s"), pName, pMemLayoutType
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
  DbgErrorF , "¦SA(¦UD): ParseTypedefUnionStruct - error", [xbx].$Obj(IncFile).pFileName, [xbx].$Obj(IncFile).dLineNumber
  mov [xbx].$Obj(IncFile).bInsideClass, FALSE
  Destroy@Stacklist pInherit
  ret
ParseTypedefUnionStruct endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure: ParseTypedef
; Purpose:   typedef occured.
; Arguments: xsi -> tokens behind "typedef"
; Return:    Nothing.
; Syntax:    typedef <annotations><qualifiers> type <<far|near> *> newname<[]>;
;            typedef struct/union <macro> <tname> {} name;
;            typedef struct/union <macro> <tname> * name;
;            typedef <annotations><qualifiers> enum <tname> {<annotations>x<=a>,<annotations>y<=b>,...} name;
;            typedef <annotations><qualifiers> returntype (<qualifiers> *name)(<parameters>);
;            typedef <annotations><qualifiers> returntype name(<parameters>);

ParseTypedef proc
    local pToken:PTOKEN, pName:PSTRINGA, pType:PSTRINGA, pDup:PSTRINGA
    local dSquareBracketCount:DWORD, dPtrCount:DWORD, bValid:DWORD, dTypeCSpec:DWORD
    local szTmpType[256]:CHRA, szBuffer[256]:CHRA
    local InpStat:INP_STAT

    DbgPrintF , "¦UD: ParseTypedef - begin", [xbx].$Obj(IncFile).dLineNumber
    mov pType, NULL

@GetNextToken:
    OCall xbx::IncFile.GetNextToken
@ProcessToken:
    .if xax != NULL
      invoke SkipAnnotations, xax
      .if xax != NULL
        invoke TranslateToken, xax
        .if edx == FALSE
          invoke TranslateTypeQualifier, xax
          cmp CHRA ptr [xax], 0
          jz @GetNextToken
        .endif
      .endif
    .endif
    mov pToken, xax
    test xax, xax
    jz @Error

    cmp CHRA ptr [xax], ";"                             ;Statement terminator?
    jz @Error                                           ; Yes => error

    .if CHRA ptr [xax] == "["
      DbgPrintF , "¦UD: ParseTypedef - \´[\´ found", [xbx].$Obj(IncFile).dLineNumber
      OCall xbx::IncFile.SaveInputStatus, addr InpStat
      OCall xbx::IncFile.GetNextToken
      .if xax != NULL
        .if $DoesStringMatchA?([xax], <public>)
          OCall xbx::IncFile.GetNextToken
          .if xax != NULL && CHRA ptr [xax] == "]"
            DbgPrintF , "¦UD: ParseTypedef - \´]\´ found", [xbx].$Obj(IncFile).dLineNumber
            jmp @GetNextToken                                ;Sure????
          .endif
        .endif
      .endif
      OCall xbx::IncFile.LoadInputStatus, addr InpStat
    .endif

    ;syntax: "typedef <macro()> xxx"
    invoke IsMacro?, pToken                             ;Check if it is an already known macro
    .if eax != 0                                        ;0, 1, ...
      DbgPrintF , "¦UD: ParseTypedef - macro invocation ¦SA", [xbx].$Obj(IncFile).dLineNumber, pToken
      .if eax == 1
        OCall pMacros::List.ItemAt, ecx
      .else
        OCall pKnownMacros::List.ItemAt, ecx
      .endif
      mov edx, [xax - sizeof DWORD]                       ;Get offset to Macro-Attr
      invoke ParseMacroCall, pToken, DWORD ptr [xax + xdx], TRUE
      test xax, xax                                       ;FALSE if it was not a macro
      jnz @GetNextToken
    .endif

    ;Syntax: "typedef union|struct"?
    invoke IsUnionStructClass?, pToken
    .if eax != 0
      DbgPrintF , "¦UD: ParseTypedef - ¦SA found", [xbx].$Obj(IncFile).dLineNumber, pToken
      invoke ParseTypedefUnionStruct, pToken, edx
      xor eax, eax
      jmp @Exit
    .endif

    ;Syntax: "typedef enum"?
    mov xax, pToken
    .if $DoesStringMatchA?([xax], <enum>)
      DbgPrintF , "¦UD: ParseTypedef - \´enum\´ found", [xbx].$Obj(IncFile).dLineNumber
      invoke ParseTypedefEnum, TRUE
      xor eax, eax
      jmp @Exit
    .endif

    .if pType == NULL
      ;pToken may be a basic C type
      mov xax, pToken
      BasicTypeCScan
      mov pToken, xax                                   ;Last gattered Token
      .if dTypeCSpec != 0
        invoke ConvBasicTypeC, dTypeCSpec
        .if xax == NULL                                 ;If conversion failed
          mov xax, offset szUnkType
        .endif
        mov pType, xax
        mov xax, pToken
        jmp @ProcessToken                               ;Process the last gattered Token in eax
      .else
        lea xdx, szBuffer
        invoke TranslateReservedWord, xax, xdx
        mov pType, xax
        jmp @GetNextToken
      .endif
    .endif

    ;Get the new Name and write all to the output stream
    mov xax, pToken
    mov dSquareBracketCount, 0
    mov dPtrCount, 0
    mov pName, NULL
    mov pDup, NULL
    .while TRUE
      .if CHRA ptr [xax] == "," || CHRA ptr [xax] == ";"
        .if pName != NULL
          mov bValid, TRUE
          ;Don't add "<newname> typedef <oldname>" entries if <newname> == <oldname>
          .if dPtrCount == 0
            invoke StrCompA, pName, pType
            .if eax == 0
              mov bValid, FALSE
            .endif
          .endif
          .if bValid != FALSE
            invoke TranslateReservedWord, pName, addr szBuffer
            push xax
;            .if edx != 0 && g_bWarningLevel > 0
;              OCall xbx::IncFile.ShowWarning, $OfsCStrA("reserved word %s used as typedef"), pName
;            .endif
            pop pName                                   ;Assign translated name
          .endif
          DbgPrintF , "¦UD: ParseTypedef - new typedef ¦SA = ¦SA", [xbx].$Obj(IncFile).dLineNumber, pName, pType

          .if bValid != FALSE
            .if dPtrCount == 0
              IsStructure? pType                        ;If the type is a structure, 
              .if eax != FALSE                          ;  then the new type is it too
                IsStructure? pName                      ;Check if it already exist
                .if eax == FALSE
                  invoke StrSizeA, pName
                  invoke InsertStrg, pStructs, pName, eax
                .endif
              .endif
            .endif

            ;If there is an array index, create a 'struct' instead of a 'typedef'!
            .if pDup != NULL && dPtrCount == 0
              OCall xbx::IncFile.StmWrite, pName
              OCall xbx::IncFile.StmWrite, $OfsCStrA(" struct")
              OCall xbx::IncFile.StmWriteEOL
              inc [xbx].$Obj(IncFile).dIndentation
              OCall xbx::IncFile.StmWrite, pType
              OCall xbx::IncFile.StmWriteChar, SPC
              OCall xbx::IncFile.StmWrite, pDup
              IsStructure? pType                        ;Check if pType is already a known struct
              .if eax == FALSE
                OCall xbx::IncFile.StmWrite, $OfsCStrA(" dup (?)")
              .else
                OCall xbx::IncFile.StmWrite, $OfsCStrA(" dup (<>)")
              .endif
              OCall xbx::IncFile.StmWriteEOL
              dec [xbx].$Obj(IncFile).dIndentation
              OCall xbx::IncFile.StmWrite, pName
              OCall xbx::IncFile.StmWrite, $OfsCStrA(" ends")
              OCall xbx::IncFile.StmWriteEOL

            .else
              OCall xbx::IncFile.StmWrite, pName
              OCall xbx::IncFile.StmWrite, $OfsCStrA(" typedef ")
              WritePtr
              mov xax, pType
              .if CHRA ptr [xax] == 0
                OCall xbx::IncFile.StmDeleteLastSpace
              .else
                OCall xbx::IncFile.StmWrite, pType
              .endif
              OCall xbx::IncFile.StmWriteEOL

              invoke StrSizeA, pName
              invoke InsertStrg, pTypedefs, pName, eax
            .endif
          .endif
        .endif

        mov dPtrCount, 0
        mov pName, NULL
        mov xax, pToken
        .break .if CHRA ptr [xax] == ";"                ;Statement terminator? => exit
      .endif

      .if CHRA ptr [xax] == "("
        invoke IsFunctionPtr?
        .if eax != FALSE
          invoke ParseTypedefFunctionPtr, NULL
        .else
          invoke IsFunction?
          .if eax != FALSE
            mov xax, pName
            test xax, xax
            cmovz xax, pType
            invoke ParseTypedefFunction, xax, FALSE, NULL
          .endif
        .endif
        mov pName, NULL
        test eax, eax
        jnz @Exit

      .elseif CHRA ptr [xax] == "*" && dSquareBracketCount == 0
        inc dPtrCount

      .elseif CHRA ptr [xax] == "["
        DbgPrintF , "¦UD: ParseTypedef - \´[\´ found", [xbx].$Obj(IncFile).dLineNumber
        inc dSquareBracketCount

      .elseif CHRA ptr [xax] == "]"
        DbgPrintF , "¦UD: ParseTypedef - \´]\´ found", [xbx].$Obj(IncFile).dLineNumber
        dec dSquareBracketCount

      .else
        .if dSquareBracketCount != 0
          .if pDup != 0
            push xax
            invoke StrSizeA, xax
            push xax
            invoke StrSizeA, pDup
            pop xcx
            add eax, ecx                                ;length1 + length2 + 2
            MemAlloc eax
            push xbx
            mov ebx, eax
            invoke StrECopyA, xbx, pDup
            push xax
            MemFree pDup
            mov pDup, xbx
            pop xcx
            mov CHRA ptr [xcx], "*"
            inc ecx
            invoke StrCopyA, xcx, [xsp + 4]
            pop xbx
            pop xax
          .else
            invoke StrNewA, xax
            mov pDup, xax
          .endif
          DbgPrintF , "¦UD: ParseTypedef - array size ¦SA found", [xbx].$Obj(IncFile).dLineNumber, xax
        .else
          mov pToken, xax
          IsName? xax
          .if eax != FALSE
            mov xax, pToken
            mov pName, xax
          .endif
        .endif
      .endif

      OCall xbx::IncFile.GetNextToken
      test xax, xax                                     ;No more tokens? => error
      jz @Error
      invoke SkipAnnotations, xax
      test xax, xax
      jz @Error                                         ;No more tokens? => error
      mov pToken, xax
    .endw

@Exit:
    ret

@Error:
    .if xax != NULL
      OCall xbx::IncFile.ShowError, $OfsCStrA("unexpected item %s in typedef [¦UD]"), pToken, eax
    .endif
    DbgErrorF , "¦SA(¦UD): ParseTypedef - error", [xbx].$Obj(IncFile).pFileName, [xbx].$Obj(IncFile).dLineNumber
    ret
ParseTypedef endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure: ParseExtern
; Purpose:   Parse extern.
; Arguments: None.
; Return:    Nothing.

ParseExtern proc
    local pToken:PTOKEN

    .while TRUE
      OCall xbx::IncFile.GetNextToken
      .break .if xax == NULL
      .break .if CHRA ptr [xax] == ";"                  ;Statement terminator
      mov pToken, xax
      .if DWORD ptr [xax] == ',"C"' && DCHRA ptr [xax + sizeof DWORD] == "0"
        OCall xbx::IncFile.StmWrite, $OfsCStrA(";extern ", 22h, "C", 22h)      ;"   C linkage
        OCall xbx::IncFile.StmWriteEOL
        mov [xbx].$Obj(IncFile).bExternC, TRUE
        .break
      .elseif DWORD ptr [xax] == '++C"' && DWORD ptr [xax + 4] == '0,"'
        OCall xbx::IncFile.StmWrite, $OfsCStrA(";extern ", 22h, "C++", 22h)    ;"   C++ linkage
        OCall xbx::IncFile.StmWriteEOL
        .break
      .endif
      OCall xbx::IncFile.StmWrite, $OfsCStrA("externdef ")
      .if [xbx].$Obj(IncFile).bExternC != FALSE
        OCall xbx::IncFile.StmWrite, $OfsCStrA("c ")
      .endif
      invoke ParseExternItem, pToken
      .break
    .endw

    ret

@Error:
    DbgErrorF , "¦SA(¦UD): ParseExtern - error", [xbx].$Obj(IncFile).pFileName, [xbx].$Obj(IncFile).dLineNumber
    ret
ParseExtern endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure: ParsePrototype
; Purpose:   Parse a function prototype.
; Arguments: Arg1 -> Function name.
;            Arg2 -> Import specification (for example WINOLEAPI). Can be NULL.
;            Arg3 -> Call convention (for example WINAPI). Can be NULL.
; Return:    Nothing.
; Link:      https://msdn.microsoft.com/en-us/library/zw3za17w.aspx
; Format:    [Annotation] [Import-Spec] return-type [Call-Conv] Function-Name[(Argument-List)]

ParsePrototype proc uses xdi pProcName:PSTRINGA, pImportSpec:PSTRINGA, pCallConv:PSTRINGA
    local pName:PSTRINGA, pToken:PTOKEN, pPrefix:PSTRINGA, pCallConvStr:PSTRINGA
    local bFunctionPtr:DWORD, dPtrCount:DWORD, dParenthesisCount:DWORD, dParamBytes:DWORD
    local InpStat:INP_STAT, szSuffix[8]:CHRA, szBuffer[512]:CHRA
    local dTypeCSpec:DWORD, pType:PSTRINGA, cTransBuffer[128]:CHRA
    local pStmOutPos:POINTER, dStmOutEOL:DWORD

    ;Parse function header ----------------------------------------------------
    invoke GetCallConvString, [xbx].$Obj(IncFile).dQualifiers
    mov pCallConvStr, xax

    DbgPrintF , "¦UD: ParsePrototype - name = ¦SA, pImportSpec = ¦SA", [xbx].$Obj(IncFile).dLineNumber, pProcName, pImportSpec
    .if $ObjTmpl(Application).Options.dDllImport != DLLIMPORT_DEFPROTO && pImportSpec != NULL
    .else
      .if $ObjTmpl(Application).Options.dDllImport == DLLIMPORT_ASSUME
        or [xbx].$Obj(IncFile).dQualifiers, PTQ_IMPORT
      .elseif $ObjTmpl(Application).Options.dDllImport == DLLIMPORT_IGNORE
        and [xbx].$Obj(IncFile).dQualifiers, not PTQ_IMPORT
      .endif
    .endif

    .if $ObjTmpl(Application).Options.dDllImport == DLLIMPORT_DEFPROTO && pImportSpec != NULL
      invoke IsReservedWord?, pProcName
      .if eax != FALSE
        OCall xbx::IncFile.ShowWarning, WARNING_MAYOR, $OfsCStrA("Reserved word '%s' used as prototype"), pProcName
        mov xax, offset szResWordSuffix
      .else
        mov xax, NULL
      .endif
      push xax
      OCall xbx::IncFile.StmWriteF, $OfsCStrA("@DefProto %s, %s, %s,"), pImportSpec, pProcName, pCallConvStr
      pop xax
      .if xax != NULL
        OCall xbx::IncFile.StmWriteF, $OfsCStrA(" %s"), xax    ;ProcName suffix
      .endif
      OCall xbx::IncFile.StmWrite, $OfsCStrA(", ", 3Ch)  ;", <"
    .else
      .if ([xbx].$Obj(IncFile).dQualifiers & PTQ_IMPORT)
        OCall xbx::IncFile.StmWriteF, $OfsCStrA("TYPE_%s typedef proto %s"), pProcName, xax
      .else
        invoke TranslateReservedWord, pProcName, addr cTransBuffer
        mov xdx, offset szEmpty
        .if xcx != xdx
          OCall xbx::IncFile.StmWriteF, $OfsCStrA("%s proto %s"), xax, pCallConvStr
        .else
          OCall xbx::IncFile.StmWriteF, $OfsCStrA("%s proto"), xax
        .endif
      .endif
    .endif

    ;Parse function parameters ------------------------------------------------
    mov [xbx].$Obj(IncFile).pPrevToken, NULL
    mov pType, NULL
    mov pName, NULL
    mov bFunctionPtr, FALSE
    mov dPtrCount, 0
    mov dParamBytes, 0
    mov dParenthesisCount, 1
    .while dParenthesisCount != 0
      OCall xbx::IncFile.GetNextToken
@ProcessToken:
      .break .if xax == NULL || CHRA ptr [xax] == ";"   ;Statement terminator
      invoke SkipAnnotations, xax
      .break .if xax == NULL

      .if CHRA ptr [xax] == "," || CHRA ptr [xax] == ")"
        mov pToken, xax
        .if pType != NULL || dPtrCount != 0
          mov xax, pType
          .if xax == NULL && dPtrCount != 0
            mov xax, offset szEmpty                     ;Make sure it is a valid PSTRINGA
          .else
            .if dPtrCount == 0 && pName == NULL
              .break .if $DoesStringMatchA?([xax], <void>)
              .break .if $DoesStringMatchA?([xax], <VOID>)
            .endif
          .endif
                                                        ;Don't interpret xxx(void) as parameter
          .if dPtrCount != 0 || CHRA ptr [xax] != 0
            .if dParamBytes != 0 || $ObjTmpl(Application).Options.dDllImport != DLLIMPORT_DEFPROTO || pImportSpec == NULL
              OCall xbx::IncFile.StmWrite, offset szSpace
            .endif
            OCall xbx::IncFile.StmWrite, offset szColon
            .if dPtrCount != 0
              mov eax, sizeof DWORD                     ;Size of a 32 bit POINTER
            .else
              ;Get type sizes (for structures used as parameters). Only relevant for 32 bit!
              OCall pTypeSize::List.Search, pType
              .if eax != FALSE
                OCall pTypeSize::List.ItemAt, ecx
                mov edx, [xax - sizeof DWORD]
                mov eax, [xax + xdx]
              .else
                mov eax, sizeof DWORD                   ;Default for 32 bit!
              .endif
            .endif
            add dParamBytes, eax
          .endif
          WritePtr                                      ;on exit, dPtrCount = 0
          mov xax, pType
          .if xax != NULL && CHRA ptr [xax] != 0
            OCall xbx::IncFile.StmWrite, pType
          .else
            OCall xbx::IncFile.StmDeleteLastSpace
          .endif
          mov pType, NULL
          mov pName, NULL
          mov bFunctionPtr, FALSE
        .endif

        mov xax, pToken
        .if CHRA ptr [xax] == ")"
          dec dParenthesisCount
        .else
          OCall xbx::IncFile.StmWrite, xax
        .endif

      .elseif CHRA ptr [xax] == "*" || CHRA ptr [xax] == "&"
        inc dPtrCount

      .elseif CHRA ptr [xax] == "["
        inc dPtrCount
        .repeat
          OCall xbx::IncFile.GetNextToken
        .until xax == NULL || CHRA ptr [xax] == "]" || CHRA ptr [xax] == ";"

      .elseif CHRA ptr [xax] == "("
        ;Function ptr as function parameter?
        invoke IsFunctionPtr?
        .if eax != FALSE
          m2m pStmOutPos, [xbx].$Obj(IncFile).pStmOutPos, xax
          m2m dStmOutEOL, [xbx].$Obj(IncFile).dStmOutEOL, ecx
          invoke ParseTypedefFunctionPtr, NULL
          m2m [xbx].$Obj(IncFile).pStmOutPos, pStmOutPos, xax
          m2m [xbx].$Obj(IncFile).dStmOutEOL, dStmOutEOL, ecx
          ;Alternative code without explicit declaration of the Function pointer
          invoke SkipBraces, "(", ")"
          OCall xbx::IncFile.GetNextToken
          invoke SkipBraces, "(", ")"
          mov dPtrCount, TRUE
          mov pName, NULL
          mov pType, NULL
        .else
          inc dParenthesisCount
        .endif

      .else
        invoke TranslateTypeQualifier, xax
        .continue .if CHRA ptr [xax] == 0
        .continue .if $DoesStringMatchA?([xax], <struct>) ;Ignore 'struct'
        .continue .if $DoesStringMatchA?([xax], <union>)  ;Ignore 'union'
        .continue .if $DoesStringMatchA?([xax], <enum>)   ;Ignore 'enum'

        .if $DoesStringMatchA?([xax], <...>)
          c2m pType, $OfsCStrA("vararg"), xax
          c2m pName, offset szEmpty, xax
          .continue
        .endif

        ;pToken may be a basic C type
        mov pToken, xax
        .if pType == NULL
          BasicTypeCScan
          mov pToken, xax
          .if dTypeCSpec != 0
            invoke ConvBasicTypeC, dTypeCSpec
            .if xax == NULL                             ;If conversion failed
              c2m pType, offset szUnkType,xax
            .else
              mov pType, xax
              mov xax, pToken
              jmp @ProcessToken
            .endif
            mov xax, pToken
          .endif
        .endif

        lea xdx, szBuffer
        invoke TranslateReservedWord, xax, xdx
        .if pType == NULL
          mov pType, xax
        .elseif pName == NULL
          mov pName, xax
        .endif
      .endif
    .endw

    .if $ObjTmpl(Application).Options.dDllImport == DLLIMPORT_DEFPROTO 
      .if pImportSpec != NULL
        OCall xbx::IncFile.StmWriteChar, 3Eh              ;">"
        mov xax, pCallConvStr
        .if CHRA ptr [xax] != "c"                         ;cdecl doesn't need decoration suffix
          OCall xbx::IncFile.StmWriteF, $OfsCStrA(", &u"), dParamBytes
        .endif
      .endif
    .endif
    OCall xbx::IncFile.StmWriteEOL

    .if !($ObjTmpl(Application).Options.dDllImport == DLLIMPORT_DEFPROTO && pImportSpec != NULL)
      .ifBitSet [xbx].$Obj(IncFile).dQualifiers, PTQ_IMPORT
        .if ([xbx].$Obj(IncFile).dQualifiers & PTQ_STDCALL)
          c2m pPrefix, offset szUnderscore, xax
          lea xdi, szSuffix
          WriteFA xdi, "@¦UD", dParamBytes
        .elseif ([xbx].$Obj(IncFile).dQualifiers & PTQ_CDECL)
          c2m pPrefix, offset szUnderscore, xax
          mov szSuffix, 0
        .else
          c2m pPrefix, offset szEmpty, xax
          mov szSuffix, 0
        .endif

        OCall xbx::IncFile.StmWriteF, $OfsCStrA("externdef stdcall _imp_%s%s%s: ptr proto_%s"), \
                                      pPrefix, pProcName, addr szSuffix, pProcName
        OCall xbx::IncFile.StmWriteEOL
        invoke TranslateReservedWord, pProcName, addr cTransBuffer
        mov ecx, eax
        OCall xbx::IncFile.StmWriteF, $OfsCStrA("%s equ ", 3Ch, "_imp_%s%s%s", 3Eh), \     ;"<" ">"
                                      xcx, pPrefix, pProcName, addr szSuffix
        OCall xbx::IncFile.StmWriteEOL
      .endif
    .endif
    invoke StrSizeA, pProcName
    invoke InsertStrg, pPrototypes, pProcName, eax

    .if $ObjTmpl(Application).Options.bCreateDefs != FALSE
      invoke InsertDefItem, pProcName, dParamBytes
    .endif
    .ifBitSet [xbx].$Obj(IncFile).dQualifiers, PTQ_INLINE
      ;Skip inline C-code block
      OCall xbx::IncFile.SaveInputStatus, addr InpStat
      OCall xbx::IncFile.GetNextToken
      .if xax != NULL && CHRA ptr [xax] == "{"
        invoke SkipBraces, "{", "}"
      .else
        OCall xbx::IncFile.LoadInputStatus, addr InpStat
      .endif
    .endif

@Exit:
    ret

@Error:
    DbgErrorF , "¦SA(¦UD): ParsePrototype - error", [xbx].$Obj(IncFile).pFileName, [xbx].$Obj(IncFile).dLineNumber
    ret
ParsePrototype endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure: ParseMacroCall
; Purpose:   A known macro has been found.
; Arguments: Arg1 -> Macro Name
;            Arg2: Macro Flags (MCF_xxx).
;            Arg3: Flag to write LF after macro invocation.
; Return:    eax = returns TRUE if macro was invoked, otherwise FALSE (turned out to be
;            NO macro invocation).

ParseMacroCall proc pMacroName:PSTRINGA, dMacroFlags:DWORD, bWriteLF:DWORD
    local pToken:PTOKEN, pType:PSTRINGA, pName:PSTRINGA, pStmOutPos:PSTRINGA, bAddSpace:DWORD
    local dPtrCount:DWORD, dParenthesesCount:DWORD, bSkipTheRest:DWORd
    local dTypeCSpec:DWORD, dScanStep:DWORD, pArgStack:POINTER, cTransBuffer[128]:CHRA

    m2m pStmOutPos, [xbx].$Obj(IncFile).pStmOutPos, eax

    DbgPrintF , "¦UD: ParseMacroCall - found: ¦SA", \
              [xbx].$Obj(IncFile).dLineNumber, pMacroName

    .ifBitSet dMacroFlags, MCF_SKIP_INVOKATION
      OCall xbx::IncFile.PeekNextToken
      .if xax != NULL
        .if CHRA ptr [xax] == "("
          OCall xbx::IncFile.GetNextToken                 ;Consume it
          invoke SkipBraces, "(", ")"
        .endif
      .endif
      mov eax, TRUE
      ret
    .endif

    mov pArgStack, $Create@Stacklist()

    .ifBitSet dMacroFlags, MCF_INTERFACE_END
      OCall xbx::IncFile.StmWrite, $OfsCStrA("??Interface equ <>")  ;Reset ??Interface symbol
      OCall xbx::IncFile.StmWriteEOL
      mov [xbx].$Obj(IncFile).bInsideInterface, FALSE
    .endif

    OCall xbx::IncFile.PeekNextToken
    .if xax != NULL && CHRA ptr [xax] == "("
      OCall xbx::IncFile.StmWrite, pMacroName
      OCall xbx::IncFile.GetNextToken                   ;Can NOT fail, we peeked a token previously
      .ifBitClr dMacroFlags, MCF_SKIP_BRACES
        OCall xbx::IncFile.StmWrite, xax
      .else
        OCall xbx::IncFile.StmWriteChar, SPC
      .endif
      mov dParenthesesCount, 1
      mov bAddSpace, FALSE
      .while TRUE
        OCall xbx::IncFile.GetNextToken
        .break .if xax == NULL
        Add@Stacklist pArgStack, xax
        .if CHRA ptr [xax] == "("
          inc dParenthesesCount
          mov bAddSpace, FALSE
        .elseif CHRA ptr [xax] == ")"
          dec dParenthesesCount
          mov bAddSpace, TRUE
          .break .if dParenthesesCount == 0
        .else
          .if CHRA ptr [xax] != ","
            push xax
            .if bAddSpace != FALSE
              OCall xbx::IncFile.StmWriteChar, SPC
            .endif
            pop xax
            .ifBitSet dMacroFlags, MCF_PARAMS_FOLLOW
              invoke TranslateReservedWord, xax, addr cTransBuffer   ;Arguments can not be reserved words
            .endif
            invoke TranslateNumOperator, xax
            DbgPrintF , "¦UD: ParseMacroCall - Parameter = ¦SA", [xbx].$Obj(IncFile).dLineNumber, xax
            mov bAddSpace, TRUE
          .endif
        .endif
        OCall xbx::IncFile.StmWrite, xax
      .endw

      .ifBitClr dMacroFlags, MCF_SKIP_BRACES
        OCall xbx::IncFile.StmWriteChar, 29h            ;")"
      .endif

      ;Up to now we processed MacroName(...). Now comes the rest of the line.
      .ifBitSet dMacroFlags, MCF_COPY_LINE              ;Rest of line belongs to macro invocation
        mov pType, NULL
        mov pName, NULL
        mov dPtrCount, 0
        mov dTypeCSpec, 0
        mov dScanStep, 0
        mov bSkipTheRest, FALSE
        .while TRUE
          .ifBitSet dMacroFlags, MCF_PARAMS_FOLLOW
            OCall xbx::IncFile.GetNextToken
            .break .if xax == NULL || CHRA ptr [xax] == ";"     ;Statement terminator
          .else
            OCall xbx::IncFile.GetNextTokenFromPPLine
            .break .if xax == NULL
          .endif
          .continue .if bSkipTheRest != FALSE

@ProcessToken:
          .ifBitSet dMacroFlags, MCF_PARAMS_FOLLOW
            invoke SkipAnnotations, xax
            .if CHRA ptr [xax] == ")" || CHRA ptr [xax] == ","
              push xax
              mov xax, pType
              test xax, xax
              cmovz xax, pName
              .if xax != NULL
                DbgPrintF , "¦UD: ParseMacroCall - Param = ¦SA", [xbx].$Obj(IncFile).dLineNumber, xax
                push xax
                OCall xbx::IncFile.StmWrite, $OfsCStrA(", :")
                WritePtr
                pop xax
                movzx edx, $ObjTmpl(Application).Options.bUntypedParams
                invoke TranslateType, xax, edx
                OCall xbx::IncFile.StmWrite, xax
              .endif
              mov pType, NULL
              mov pName, NULL
              mov dPtrCount, 0
              mov dTypeCSpec, 0
              mov dScanStep, 0
              pop xax
              .continue .if CHRA ptr [xax] == ","
            .endif
            .if CHRA ptr [xax] == "("
              inc dParenthesesCount
              .continue
            .endif
            .if CHRA ptr [xax] == ")"
              dec dParenthesesCount
              .continue
            .endif
            .if CHRA ptr [xax] == "*"
              inc dPtrCount
              .continue
            .endif
            .if CHRA ptr [xax] == "["
              inc dPtrCount
              invoke SkipBraces, "[", "]"
              test xax, xax
              jz @Exit
              .continue
            .endif
            .if CHRA ptr [xax] == "="
              mov bSkipTheRest, TRUE
              .continue
            .endif
            
            mov ecx, [xax]
            or ecx, 20202020h                           ;Convert to lowercase
            .if ecx == "siht"
              mov cx, [xax + 4]
              .continue .if cx == "_" || cl == 0        ;Skip THIS and THIS_
            .endif

            invoke TranslateTypeQualifier, xax
            .continue .if CHRA ptr [xax] == 0
            mov pToken, xax

            .if pType == NULL
              BasicTypeCScan
              mov pToken, xax
              .if dTypeCSpec != 0
                invoke ConvBasicTypeC, dTypeCSpec
                .if xax == NULL
                  mov xax, offset szUnkType
                .endif
                mov pType, xax
                mov xax, pToken
                jmp @ProcessToken
              .endif
            .endif

            mov xax, pToken
            .if pType == NULL
              mov pType, xax
              .continue
            .endif
            .if pName == NULL
              mov pName, xax
              .continue
            .endif
            jmp @Error
          .endif
          OCall xbx::IncFile.StmWrite, xax
        .endw
      .endif
    .else
      .ifBitClr dMacroFlags, MCF_HAS_PARAMS
        OCall xbx::IncFile.StmWrite, pMacroName
      .else
        xor eax, eax                                    ;It wasn't a macro or some error happend
        jmp @Exit
      .endif
    .endif
    .ifBitSet dMacroFlags, MCF_END_MACRO
      mov xax, pMacroName
      mov [xbx].$Obj(IncFile).pEndMacro, xax
      mov eax, [xbx].$Obj(IncFile).dBraces
      mov [xbx].$Obj(IncFile).dBlockLevel, eax
    .endif

@Done:
    .if bWriteLF != FALSE
      OCall xbx::IncFile.StmWriteEOL
    .endif
    .ifBitSet dMacroFlags, MCF_INTERFACE_BEG
      .if [xbx].$Obj(IncFile).pStructName != NULL
        OCall xbx::IncFile.StmWriteF, $OfsCStrA("??Interface equ <%s>"), [xbx].$Obj(IncFile).pStructName
        OCall xbx::IncFile.StmWriteEOL
        mov [xbx].$Obj(IncFile).bInsideInterface, TRUE
      .endif
    .endif
    .ifBitSet $ObjTmpl(Application).Options.dSelectiveOutput, OUTPUT_CONSTANTS
      mrm [xbx].$Obj(IncFile).pStmOutPos, pStmOutPos, ecx
      mov CHRA ptr [xcx], 0
    .endif

    .ifBitSet dMacroFlags, MCF_STRUCT_BEG
      inc [xbx].$Obj(IncFile).dIndentation
      OCall xbx::IncFile.GetNextToken
      .if CHRA ptr [xax] == "{"
        mov xcx, $GetItem@Stacklist(pArgStack, 0)
        invoke ParseBlock, xcx, PBT_MEM_LAYOUT
        invoke ParseInterfaceBlock, xcx
        dec [xbx].$Obj(IncFile).dIndentation
        OCall xbx::IncFile.StmWriteF, $OfsCStrA("END_%s"), pMacroName
        OCall xbx::IncFile.StmWriteEOL
      .else
        jmp @Error
      .endif
    .endif
    mov eax, TRUE

@Exit:
    Destroy@Stacklist pArgStack
    ret

@Error:
    DbgErrorF , "¦SA(¦UD): ParseMacroCall - error", \
                [xbx].$Obj(IncFile).pFileName, [xbx].$Obj(IncFile).dLineNumber
    Destroy@Stacklist pArgStack
    xor eax, eax
    ret
ParseMacroCall endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure: ParseC
; Purpose:   The following types of declarations are known:
;              1. typedef (struct, enum)
;              2. extern
;              3. prototypes
; Arguments: None.
; Return:    eax = TRUE if succeeded, otherwise FALSE.
; Links:     http://www.inf.fu-berlin.de/lehre/WS11/OS/slides/OS_Declarations_in_C_.pdf
;            https://en.wikipedia.org/wiki/C_syntax
;            https://msdn.microsoft.com/en-us/library/bz4heb45.aspx

ParseC proc uses xdi xsi
    local pToken:PTOKEN, pToken2:PTOKEN, bNextParm:DWORD, bInsideClass:DWORD, bAddSpace:DWORD
    local cMacroBuffer[2048]:CHRA, dProtoQualifier:DWORD, .xdi:XWORD,.xsi:XWORD

    OCall xbx::IncFile.GetNextToken
    .if xax == NULL
      DbgPrintF , "¦UD: ParseC - EOF reached", [xbx].$Obj(IncFile).dLineNumber
      ret
    .endif
    mov pToken, xax

    OCall xbx::IncFile.StmWriteComment
    .if eax != FALSE
      OCall xbx::IncFile.StmWriteEOL
    .endif

    mov xax, pToken
    .if CHRA ptr [xax] == ";"                           ;Statement terminator => reset all
      mov [xbx].$Obj(IncFile).pPrevToken, NULL
      mov [xbx].$Obj(IncFile).pImportSpec, NULL
      mov [xbx].$Obj(IncFile).pCallConv, NULL
      mov [xbx].$Obj(IncFile).dQualifiers, 0
      jmp @Exit
    .endif

    ;Check annotation ---------------------------------------------------------
    invoke SkipAnnotations, pToken
    test xax, xax
    jz @Exit

    invoke TranslateToken, xax
    mov pToken, xax

    ;'typedef' test -----------------------------------------------------------
    .if $DoesStringMatchA?([xax], <typedef>)
      mov xsi, [xbx].$Obj(IncFile).pStmOutPos
      mov edi, [xbx].$Obj(IncFile).dStmOutEOL
      DbgPrintF , "¦UD: ParseC - \´typedef\´ found", [xbx].$Obj(IncFile).dLineNumber
      invoke ParseTypedef
      .ifBitClr $ObjTmpl(Application).Options.dSelectiveOutput, OUTPUT_TYPEDEFS
        mov [xbx].$Obj(IncFile).pStmOutPos, xsi
        mov [xbx].$Obj(IncFile).dStmOutEOL, edi
        mov CHRA ptr [xcx], 0
      .endif
      jmp @Exit
    .endif

    ;'union', 'struct', 'class' test ------------------------------------------
    ;'struct' may be a struct declaration, but may be a function returning a struct as well
    invoke IsUnionStructClass?, pToken                  ;edx = TRUE if class detected
    .if eax != FALSE
      DbgPrintF , "¦UD: ParseC - \´union/struct/class\´ found", [xbx].$Obj(IncFile).dLineNumber
      push xdx
      invoke IsFunction?
      pop xdx
      .if eax == FALSE
        mov xsi, [xbx].$Obj(IncFile).pStmOutPos
        mov edi, [xbx].$Obj(IncFile).dStmOutEOL
        invoke ParseTypedefUnionStruct, pToken, edx
        .ifBitClr $ObjTmpl(Application).Options.dSelectiveOutput, OUTPUT_TYPEDEFS
          mov [xbx].$Obj(IncFile).pStmOutPos, xsi
          mov [xbx].$Obj(IncFile).dStmOutEOL, edi
          mov CHRA ptr [xcx], 0
        .endif
        jmp @Exit
      .endif
      DbgPrintF , "¦UD: ParseC - \´union/struct\´ ignored (function return type)", \
                [xbx].$Obj(IncFile).dLineNumber
    .endif

    ;'extern' test ------------------------------------------------------------
    mov xax, pToken
    .if $DoesStringMatchA?([xax], <extern>)
      invoke IsFunction?                                ;In case of an extern function, ignore
      .if eax == FALSE                                  ;'extern' and continue parsing as a proto
        mov xsi, [xbx].$Obj(IncFile).pStmOutPos
        mov edi, [xbx].$Obj(IncFile).dStmOutEOL
        DbgPrintF , "¦UD: ParseC - \´extern\´ found", [xbx].$Obj(IncFile).dLineNumber
        invoke ParseExtern
        .ifBitClr $ObjTmpl(Application).Options.dSelectiveOutput, OUTPUT_EXTERNALS
          mov [xbx].$Obj(IncFile).pStmOutPos, xsi
          mov [xbx].$Obj(IncFile).dStmOutEOL, edi
          mov CHRA ptr [xcx], 0
        .endif
      .endif
      jmp @Exit
    .endif

    ;'enum' test --------------------------------------------------------------
    invoke StrICompA, offset szEnum, pToken             ;Upper- and lowercase!
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
          invoke StrECopy, addr cMacroBuffer, pToken   ;macro name
          mov edi, eax
          OCall xbx::IncFile.GetNextToken               ;"("
          invoke StrECopy, xdi, xax
          mov edi, eax
          mov esi, 1
          .repeat
            OCall xbx::IncFile.GetNextToken
            invoke SkipAnnotations, xax
            .break .if xax == NULL
            mov pToken2, xax
            .if CHRA ptr [xax] == "("
              inc esi
              mov bAddSpace, FALSE
            .elseif CHRA ptr [xax] == ")"
              dec esi
              mov bAddSpace, TRUE
            .else
              .if bAddSpace != FALSE
                invoke StrECopy, xdi, offset szSpace
                mov edi, eax
              .endif
              mov bAddSpace, TRUE
            .endif
            invoke StrECopy, xdi, pToken2
            mov edi, eax
          .until esi == 0
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
        c2m [xbx].$Obj(IncFile).pImportSpec, offset szDllImport, xdx
      .endif
      .ifBitSet ecx, (PTQ_STDCALL or PTQ_CDECL or PTQ_SYSCALL or PTQ_PASCAL or \
                      PTQ_FASTCALL or PTQ_VECTORCALL)
        mov [xbx].$Obj(IncFile).pCallConv, xax
      .endif
      or [xbx].$Obj(IncFile).dQualifiers, ecx
      jmp @Exit
    .endif

    ;Check for macro invocation -----------------------------------------------
    .if [xbx].$Obj(IncFile).dQualifiers == 0                  ;No previous qualifiers => it is a macro invocation
      invoke IsMacro?, pToken
      .if eax != 0
        .if eax == 1
          OCall pMacros::List.ItemAt, ecx
        .else
          OCall pKnownMacros::List.ItemAt, ecx
        .endif
        mov edx, [xax - sizeof DWORD]
        invoke ParseMacroCall, pToken, DWORD ptr [xax + xdx], TRUE
        .if eax != FALSE
          jmp @Exit
        .endif
      .endif
    .endif

    ;Check known types --------------------------------------------------------
    .if [xbx].$Obj(IncFile).dQualifiers == 0                  ;No previous qualifiers!
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
          mov CHRA ptr [xcx], 0
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
; Procedure: ParsePP
; Purpose:   Parse PreProcessor lines.
; Arguments: None.
; Return:    Nothing.

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
          mov xdi, offset PreProcCmdHandlerTable
          .if [xbx].$Obj(IncFile).dStmOutEOL == FALSE
            OCall xbx::IncFile.StmWriteEOL
          .endif
        .else
          mov xdi, offset PreProcCmdNPHandlerTab
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
        .while CHRA ptr [xdi] != '#'                        ;Always a single character
          .if DCHRA ptr [xdi] == PCT_EOL || DCHRA ptr [xdi] == PCT_WEAKEOL
            inc [xbx].$Obj(IncFile).dLineNumber
          .endif
          mov ecx, -1
          mov al, 0
          repnz scasb
          not ecx
          dec ecx                                           ;ecx = character count
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
