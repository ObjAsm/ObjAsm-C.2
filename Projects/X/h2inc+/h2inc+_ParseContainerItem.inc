; ==================================================================================================
; Title:      h2inc+_ParseContainerItem.inc
; Author:     G. Friedrich
; Version:    See h2inc+.asm
; Purpose:  
; ==================================================================================================


.code

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  ParseContainerItem
; Purpose:    Get a struct or union declaration item.
; Arguments:  Arg1 -> First Token after 'union' or 'struct' Token.
;             Arg2 -> Struct or union Name.
;             xbx -> IncFile.
; Return:     xax -> Last Token, usually ';' or NULL if failed.
; Link:       https://en.cppreference.com/w/c/language/bit_field
; Idea:       Replace _??xx with the name of the parent struct.

ParseContainerItem proc uses xdi pToken:PTOKEN, pContainerName:PSTRINGA
  local dTypeCSpec:DWORD, bBits:DWORD, bStruct:DWORD, bFirst:DWORD, pPrvName:PSTRINGA
  local dFieldCount:DWORD, dRes:DWORD, dPtrCount:DWORD, dBits:DWORD, dNameFlags:DWORD
  local pType:PSTRINGA, pName:PSTRINGA, pDupList:POINTER, pBits:PSTRINGA, pEndToken:PSTRINGA
  local dReturn:DWORD, InpStat:INP_STAT, cTransBuffer[128]:CHRA, pCurrToken:PTOKEN, cBits[128]:CHRA
  local szMacroBuffer[MAX_BLOCK_NAME]:CHRA, szRecord[64]:CHRA, szBuffer[128]:CHRA
  local RecTypeBits:$Obj(StrCollectionA), pMemberBaseName:PTOKEN

  m2m pPrvName, [xbx].$Obj(IncFile).pContainerName, xax
  m2m [xbx].$Obj(IncFile).pContainerName, pContainerName, xcx
  New RecTypeBits::StrCollectionA
  OCall RecTypeBits::StrCollectionA.Init, xbx, 10, 10, 0FFFFFFFFh / sizeof(POINTER)

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
    .break .if ZERO?
    mov cl, [xax]
    .break .if cl == ";" || cl == "}" || cl == ","
    mov pToken, xax

    ;union ------------------------------------------------------------------
    .if $DoesStringMatchA?([xax], <union>)
      DbgPrintF , "¦UD: ParseContainerItem - ¦SA.union found", [xbx].$Obj(IncFile).dLineNumber, pContainerName
      OCall xbx::IncFile.StmWrite, addr szUnion
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

        invoke ParseBlock, pName, PBT_CONTAINER
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

      DbgPrintF , "¦UD: ParseContainerItem - end of union", [xbx].$Obj(IncFile).dLineNumber
      jmp @GetNextToken
    .endif

    ;struct -----------------------------------------------------------------
    .if $DoesStringMatchA?([xax], <struct>)
      DbgPrintF , "¦UD: ParseContainerItem - ¦SA.struct found", [xbx].$Obj(IncFile).dLineNumber, pContainerName
      OCall xbx::IncFile.GetNextToken
      .if xax == NULL || CHRA ptr [xax] == ";"          ;Statement terminator
        jmp @Error
      .endif
      DbgPrintF , "¦UD: ParseContainerItem - ¦SA.struct, next token ¦SA", [xbx].$Obj(IncFile).dLineNumber, pContainerName, xax
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
        OCall xbx::IncFile.StmWrite, addr szStruct
        inc [xbx].$Obj(IncFile).dIndentation
        invoke GetBlockName, addr szMacroBuffer         ;xax -> Name, edx = flags (if name is a macro)
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

        invoke ParseBlock, pName, PBT_CONTAINER
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
        DbgPrintF , "¦UD: ParseContainerItem - end of struct", [xbx].$Obj(IncFile).dLineNumber

      .elseif CHRA ptr [xax] == "*"
        inc dPtrCount

      .else
        ;Found struct tag ---------------------------------------------------
        mov pType, xax                                  ;Name of structure
        mov pName, NULL
        mov dPtrCount, 0
        IsName? xax
        .if eax != FALSE
          .while TRUE
            OCall xbx::IncFile.GetNextToken
            jz @Error
            mov cl, [xax]
            .if cl == "["                               ;It is an array of structures!
              jmp @DUP
            .endif
            .break .if cl == ";" || cl == ","
            .if CHRA ptr [xax] == "*"
              inc dPtrCount
            .else
              invoke TranslateTypeQualifier, xax
              .continue .if CHRA ptr [xax] == 0
              mov pCurrToken, xax
              IsName? xax
              mov xcx, pCurrToken
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
          OCall xbx::IncFile.ShowError, $OfsCStrA("unexpected ContainerItem %s after 'struct'"), pType
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
      mov edx, ecx
      .if eax == 1
        OCall pMacros::List.ItemAt, edx
      .else
        OCall pKnownMacros::List.ItemAt, edx
      .endif
      mov edx, [xax - sizeof DWORD]                     ;edx = length
      invoke ParseMacroCall, pToken, DWORD ptr [xax + xdx], TRUE
      .if eax != FALSE
        jmp @GetNextToken
      .endif
    .endif

    ;equate containing items ------------------------------------------------
    invoke IsEquate?, pToken
    .if eax != 0
      mov edx, ecx
      .if eax == 1
        OCall pEquates::List.ItemAt, edx
      .else
        OCall pKnownEquates::List.ItemAt, edx
      .endif
      mov edx, [xax - sizeof DWORD]                     ;edx = length

      .ifBitSet DWORD ptr [xax + xdx], EQF_HAS_EOL 
        OCall xbx::IncFile.StmWrite, pToken
        OCall xbx::IncFile.StmWriteEOL
        jmp @GetNextToken
      .endif
    .endif

    ;Record -----------------------------------------------------------------
    mov xax, pToken
    .if CHRA ptr [xax] == ":"                           ;Record field detected
      lea xdi, cBits
      mov pBits, xdi
      mov bFirst, TRUE                                  ;Used to append additional tokens after ":"
      .while TRUE
        mov pToken, $OCall(xbx::IncFile.GetNextToken)
        .break .if ZERO?
        mov cl, [xax]
        .break .if cl == ";" || cl == "}" || cl == ","
        .if bFirst != FALSE
          mov bFirst, FALSE
        .else
          mov DCHRA ptr [xdi], SPC
          inc xdi
        .endif
        invoke TranslateNumOperator, pToken
        .if edx == FALSE
          invoke TranslateLogOperator, xax
        .endif
      mov xdi, $invoke(StrECopyA, xdi, xax)             ;Append additional tokens after the ":"
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
    .if CHRA ptr [xax] == "["                           ;Array => DUP
@DUP:
      .if pType != NULL || pName != NULL                ;Only of we have a Type & a Name
        mov pDupList, $Create@Stacklist()
        .while TRUE
          OCall xbx::IncFile.GetNextToken
          .if ZERO? || CHRA ptr [xax] == ";"            ;Statement terminator
            jmp @Error
          .endif
          .break .if CHRA ptr [xax] == "]"
          Add@Stacklist pDupList, xax, xdx              ;Add Tokens to the DUP-List
;          .if CHRA ptr [xax] == "]"
;            OCall DupList::%XWordVector.Insert, $OfsCStr(")")
;            .break
;          .endif
;;          DbgStr xax,, "DUPs"
        OCall DupList::%XWordVector.Insert, xax         ;Add Tokens to the DUP-List
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
          lea xax, szUnkType
        .endif
        mov pType, xax
        mov xax, pToken
        .continue                                     ;Process the last gattered Token
      .endif
    .endif
    
    IsName? pToken
    .if eax != FALSE
      mov xcx, pToken
      .if pType == NULL                                 ;First get a type
        mov pType, xcx
      .elseif pName == NULL                             ;Then get a name
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
      lea xax, szBuffer                               ;=> create one
      mov pName, xax
      invoke wsprintf, xax, $OfsCStr("Bitfield%u"), dFieldCount
    .endif

    ;Write record declaration -----------------------------------------------
    .if bBits == FALSE
      mov bBits, TRUE
      DbgPrintF , "¦UD: ParseContainerItem - new Bitfield: ¦SA", [xbx].$Obj(IncFile).dLineNumber, pType
      mov xcx, $OfsCStr("DUMMYRECORDNAME")              ;Set Default
      mov xax, pContainerName
      .if xax != NULL                                 ;Unnamed struct or union
        .if !$DoesStringMatchA?([xax], <DUMMYSTRUCTNAME>)
          .if !$DoesStringMatchA?([xax], <DUMMYUNIONNAME>)
            mov xcx, xax
          .endif
        .endif
      .endif
      
      lea xdi,  szRecord
      WriteF xdi, $OfsCStrA("¦SA_??¦UD"), xcx, $ObjTmpl(Application).dRecordNameSufix
      .if $ObjTmpl(Application).Options.bNoRecords == FALSE
        OCall xbx::IncFile.StmWrite, addr szRecord
        OCall xbx::IncFile.StmWrite, $OfsCStrA(" record ")
      .endif
    .endif

    .if $ObjTmpl(Application).Options.bNoRecords == FALSE
      DbgPrintF , "¦UD: ParseContainerItem - new bits: ¦SA", [xbx].$Obj(IncFile).dLineNumber, pName
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
      .break .if ZERO?
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
        OCall xbx::IncFile.StmWrite, addr szUnion
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

        ;Write Bit fields in reverse order (MASM and C differs in the order)
        inc [xbx].$Obj(IncFile).dIndentation
        .while RecTypeBits.$Obj(StrCollectionA).dCount != 0
          mov edx, RecTypeBits.$Obj(StrCollectionA).dCount
          dec edx
          OCall RecTypeBits::StrCollectionA.ItemAt, edx
          OCall xbx::IncFile.StmWrite, xax
          mov edx, RecTypeBits.$Obj(StrCollectionA).dCount
          dec edx
          OCall RecTypeBits::StrCollectionA.DisposeAt, edx
          .if RecTypeBits.$Obj(StrCollectionA).dCount != 0
            OCall xbx::IncFile.StmWrite, $OfsCStr(",")
          .else
            dec [xbx].$Obj(IncFile).dIndentation
          .endif
          OCall xbx::IncFile.StmWriteEOL
        .endw
        OCall xbx::IncFile.StmWriteF, $OfsCStr("%s_REC%u %s_RTP%u ", 3Ch, 3Eh), \
                                      pMemberBaseName, $ObjTmpl(Application).dRecordNameSufix,\
                                      pMemberBaseName, $ObjTmpl(Application).dRecordNameSufix
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
      mov pToken, $OCall(xbx::IncFile.GetNextToken)
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
        OCall xbx::IncFile.StmWriteChar, ")"
      .endif
    .endif
    OCall xbx::IncFile.StmWriteComment
    OCall xbx::IncFile.StmWriteEOL
    ;------------------------------------------------------------------------

    mov xax, pToken
    .if xax != NULL && CHRA ptr [xax] == ","
      mov pToken, $OCall(xbx::IncFile.GetNextToken)
      jmp @NextMember
    .endif
  .endif

@Exit:
  Destroy@Stacklist pDupList
;  OCall RecTypeBits::StrCollectionA.Done
  mov xax, pEndToken
  ret

@Error:
  DbgErrorF , "¦SU(¦UD): ParseContainerItem - error", [xbx].$Obj(IncFile).pHeaderFileName, [xbx].$Obj(IncFile).dLineNumber
  m2m [xbx].$Obj(IncFile).pContainerName, pPrvName, xax
  OCall xbx::IncFile.ShowError, $OfsCStrA("unexpected '%s' ContainerItem: %s"), pContainerName, pToken
  mov xax, pEndToken
  ret
ParseContainerItem endp
