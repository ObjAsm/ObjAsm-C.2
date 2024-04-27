; ==================================================================================================
; Title:      h2inc+_RenderContainerMember.inc
; Author:     G. Friedrich
; Version:    See h2inc+.asm
; Purpose:  
; ==================================================================================================

;Example:
;struct Point{
;  int x;
;  int y;
;};
;
;typedef struct Point{
;  int x;
;  int y;
;} Point;

.code

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  RenderContainerMember
; Purpose:    Get a struct or union declaration of a single member.
; Arguments:  Arg1 -> First token after 'union {' or 'struct {'.
;             Arg2 -> Struct or union Name. Can be NULL.
;             xbx -> IncFile.
; Return:     xax -> Last processed token, usually ';' or NULL if failed and ZF set.
; Link:       https://en.cppreference.com/w/c/language/bit_field
; Idea:       Replace _??xx with the name of the parent struct.

RenderContainerMember proc uses xdi pToken:PTOKEN, pContainerName:PSTRINGA
  local dTypeCSpec:DWORD, bStruct:DWORD, pPrvName:PSTRINGA
  local dRes:DWORD, dPtrCount:DWORD, dNameFlags:DWORD
  local pType:PSTRINGA, pName:PSTRINGA, pDupList:POINTER, pEndToken:PSTRINGA
  local cTransBuffer[128]:CHRA, pCurrToken:PTOKEN
  local cMacroBuffer[MAX_BLOCK_NAME]:CHRA, DupList:$Obj(%XWordVector)
  
  local cMember[128]:CHRA, cSuffix[UDWORD2DEC_MAX_CHARS]:CHRA

  ;Initialize 
  m2m pPrvName, [xbx].$Obj(IncFile).pContainerName, xax
  m2m [xbx].$Obj(IncFile).pContainerName, pContainerName, xcx
  New DupList::%XWordVector
  OCall DupList::%XWordVector.Init, xbx, 10, 10, 0FFFFFFFFh/sizeof(POINTER)

  mov bStruct, FALSE
  mov dRes, 0
  mov pEndToken, NULL
  mov pName, NULL
  mov pType, NULL
  mov pDupList, NULL
  mov dPtrCount, 0

  mov xax, pToken                                       ;Use token passed to this proc
  .while TRUE
    test xax, xax
    jz @ErrorEoF
    invoke SkipAnnotations, xax
    jz @ErrorEoF
    .break .if CHRA ptr [xax] == ";"                    ;End of declaration reached
    mov pToken, xax

    .if $DoesStringMatchA?([xax], <struct>)             ;New structure inside this container?
      ;Name management
      mov xax, pContainerName
      .if xax != NULL                                   ;Unnamed struct or union
        .if !$DoesTextMatchA?([xax], <DUMMYSTRUCTNAME>) ;May have a number at the end
          mov xdi, $OfsCStrA("_STRUC")
          jmp @F
        .endif
        mov pContainerName, NULL
      .endif
      lea xdi, cSuffix
      WriteFA xdi, "ANONYMOUS_STRUC¦UD", $ObjTmpl(Application).dStrucNameSuffix  ;Make unique
      lea xdi, cSuffix
@@:
      ;Translation
      invoke RenderContainer, offset(szStruct)
      mov pEndToken, xax
      test xax, xax                                     ;Set/Reset ZF        
      jz @ErrorEoF
      jmp @Exit
    .endif


    .if $DoesStringMatchA?([xax], <union>)              ;New union inside this container?
      ;Name management
      mov xax, pContainerName
      .if xax != NULL                                   ;Unnamed struct or union
        .if !$DoesTextMatchA?([xax], <DUMMYUNIONNAME>)  ;May have a number at the end
          mov xdi, $OfsCStrA("_UNION")
          jmp @F
        .endif
        mov pContainerName, NULL
      .endif
      lea xdi, cSuffix
      WriteFA xdi, "ANONYMOUS_UNION¦UD", $ObjTmpl(Application).dUnionNameSuffix  ;Make unique
      lea xdi, cSuffix
@@:
      ;Translation
      invoke RenderContainer, offset(szUnion)
      mov pEndToken, xax
      jz @ErrorEoF
      jmp @Exit
    .endif

;##\
;    ;union ------------------------------------------------------------------
;    .if $DoesStringMatchA?([xax], <union>)
;      DbgPrintF , "¦UD: RenderContainerMember - ¦SA.union found", [xbx].$Obj(IncFile).dLineNumber, pContainerName
;      OCall xbx::IncFile.StmWrite, addr szUnion
;      inc [xbx].$Obj(IncFile).dIndentation
;      OCall xbx::IncFile.GetNextTokenC
;      test xax, xax
;      jz @Error
;      mov pToken, xax
;      IsValidName? xax
;      .if eax != FALSE
;        OCall xbx::IncFile.GetNextTokenC
;        test xax, xax
;        jz @Error
;      .else
;        mov xax, pToken
;      .endif
;      .if CHRA ptr [xax] == "{"
;        invoke GetBlockName, addr cMacroBuffer
;        .if xax != NULL
;          mov pName, xax
;        .endif
;        mov dNameFlags, edx
;
;        .if xax != NULL
;          .if !$DoesStringMatchA?([xax], <DUMMYUNIONNAME>)  ;Don't write in case of an
;            OCall xbx::IncFile.StmWriteChar, SPC            ; embedded union & DUMMY name
;            invoke TranslateReservedWord, pName, addr cTransBuffer
;            OCall xbx::IncFile.StmWrite, xax
;          .endif
;        .endif
;        OCall xbx::IncFile.StmWriteEOL
;
;        invoke RenderBlock, pName, RBT_CONTAINER
;        test xax, xax
;        jz @Exit
;        invoke SkipName, pName, dNameFlags
;      .else
;        OCall xbx::IncFile.ShowError, $OfsCStrA("union without block")
;        OCall xbx::IncFile.StmWriteEOL
;      .endif
;      mov pType, NULL
;      mov pName, NULL
;      dec [xbx].$Obj(IncFile).dIndentation
;      OCall xbx::IncFile.StmWrite, $OfsCStrA("ends")
;      OCall xbx::IncFile.StmWriteEOL
;
;      DbgPrintF , "¦UD: RenderContainerMember - end of union", [xbx].$Obj(IncFile).dLineNumber
;      jmp @GetNextToken
;    .endif
;
;    ;struct -----------------------------------------------------------------
;    .if $DoesStringMatchA?([xax], <struct>)
;      DbgPrintF , "¦UD: RenderContainerMember - ¦SA.struct found", [xbx].$Obj(IncFile).dLineNumber, pContainerName
;      OCall xbx::IncFile.GetNextTokenC
;      .if xax == NULL || CHRA ptr [xax] == ";"          ;Statement terminator
;        jmp @Error
;      .endif
;      DbgPrintF , "¦UD: RenderContainerMember - ¦SA.struct, next token ¦SA", [xbx].$Obj(IncFile).dLineNumber, pContainerName, xax
;      .if CHRA ptr [xax] != "{"
;        mov pName, xax
;        OCall xbx::IncFile.PeekNextTokenC
;        .if !ZERO? && CHRA ptr [xax] == "{"
;          OCall xbx::IncFile.GetNextTokenC
;        .else
;          mov xax, pName
;          mov pName, NULL
;        .endif
;      .endif
;      .if CHRA ptr [xax] == "{"
;        OCall xbx::IncFile.StmWrite, addr szStruct
;        inc [xbx].$Obj(IncFile).dIndentation
;        invoke GetBlockName, addr cMacroBuffer          ;xax -> Name, edx = flags (if name is a macro)
;        .if xax != NULL
;          mov pName, xax
;        .endif
;        mov dNameFlags, edx
;
;        .if xax != NULL
;          .if !$DoesStringMatchA?([xax], <DUMMYSTRUCTNAME>) ;Don't write in case of an
;            OCall xbx::IncFile.StmWriteChar, SPC            ; embedded structure & DUMMY name
;            invoke TranslateReservedWord, pName, addr cTransBuffer
;            OCall xbx::IncFile.StmWrite, xax
;          .endif
;        .endif
;        OCall xbx::IncFile.StmWriteEOL
;
;        invoke RenderBlock, pName, RBT_CONTAINER
;        test xax, xax
;        jz @Exit
;
;        invoke SkipName, pName, dNameFlags
;
;        ;In case that the structure is repeated [...], we ignore it ---------
;        OCall xbx::IncFile.PeekNextTokenC
;        .if !ZERO? && CHRA ptr [xax] == "["
;          OCall xbx::IncFile.GetNextTokenC
;          invoke SkipBraces, "[", "]"
;        .endif
;
;        dec [xbx].$Obj(IncFile).dIndentation
;        OCall xbx::IncFile.StmWrite, $OfsCStrA("ends")
;        OCall xbx::IncFile.StmWriteEOL
;        DbgPrintF , "¦UD: RenderContainerMember - end of struct", [xbx].$Obj(IncFile).dLineNumber
;
;      .elseif CHRA ptr [xax] == "*"
;        inc dPtrCount
;
;      .else
;        ;Found struct tag ---------------------------------------------------
;        mov pType, xax                                  ;Name of structure
;        mov pName, NULL
;        mov dPtrCount, 0
;        IsValidName? xax
;        .if eax != FALSE
;          .while TRUE
;            OCall xbx::IncFile.GetNextTokenC
;            jz @Error
;            mov cl, [xax]
;            .if cl == "["                               ;It is an array of structures!
;              jmp @DUP
;            .endif
;            .break .if cl == ";" || cl == ","
;            .if CHRA ptr [xax] == "*"
;              inc dPtrCount
;            .else
;              invoke TranslateTypeQualifier, xax
;              .continue .if CHRA ptr [xax] == 0
;              mov pCurrToken, xax
;              IsValidName? xax
;              mov xcx, pCurrToken
;              .if eax != FALSE
;                mov pName, xcx
;              .endif
;            .endif
;          .endw
;          .if pName != NULL
;            .if pType != NULL && dPtrCount == 0
;              OCall xbx::IncFile.StmWriteF, $OfsCStrA("%s %s <>"), pName, pType
;              OCall xbx::IncFile.StmWriteEOL
;            .else
;              OCall xbx::IncFile.StmWriteF, $OfsCStrA("%s POINTER ?"), pName
;              OCall xbx::IncFile.StmWriteEOL
;            .endif
;          .else
;            mov bStruct, TRUE
;            jmp @GetNextToken
;          .endif
;        .else
;          OCall xbx::IncFile.ShowError, $OfsCStrA("unexpected ContainerItem %s after 'struct'"), pType
;        .endif
;      .endif
;      mov pType, NULL
;      mov pName, NULL
;      mov dPtrCount, 0
;      jmp @GetNextToken
;    .endif
;##/

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

    ;private, public or protected -------------------------------------------
    IsPublicPrivateProtected? xax                       ;Check for 'private', 'public', 'protected'
    .if eax != FALSE
      OCall xbx::IncFile.PeekNextTokenC
      .if !ZERO? && CHRA ptr [xax] == ":"
        OCall xbx::IncFile.GetNextTokenC                ;Consume it
        jmp @GetNextToken
      .endif
    .endif

    ;macro ------------------------------------------------------------------
    invoke IsMacro?, pToken                             ;Check in the macro lists
    .if eax != 0
      mov edx, ecx
      .if eax == 1
        OCall pMacros::List.ItemAt, edx
      .else
        OCall pKnownMacros::List.ItemAt, edx
      .endif
      mov edx, [xax - sizeof(DWORD)]                    ;edx = length
      invoke RenderMacroCall, pToken, DWORD ptr [xax + xdx], TRUE
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
      mov edx, [xax - sizeof(DWORD)]                    ;edx = length

      .ifBitSet DWORD ptr [xax + xdx], EQF_HAS_EOL      ;Force an EOL
        OCall xbx::IncFile.StmWrite, pToken
        OCall xbx::IncFile.StmWriteEOL
        jmp @GetNextToken
      .endif
    .endif

    ;Record -----------------------------------------------------------------
    mov xax, pToken
    .if CHRA ptr [xax] == ":"                           ;Record field detected
      ;Name management
      mov xax, pContainerName
      .if xax != NULL                                   ;Unnamed struct or union
        .if !$DoesTextMatchA?([xax], <DUMMYSTRUCTNAME>) ;May have a number at the end
          .if !$DoesTextMatchA?([xax], <DUMMYUNIONNAME>);May have a number at the end
            mov xdi, $OfsCStrA("_REC")
            jmp @F
          .endif
        .endif
        mov pContainerName, NULL
      .endif
      lea xdi, cSuffix
      WriteFA xdi, "ANONYMOUS_REC¦UD", $ObjTmpl(Application).dRecordNameSuffix  ;Make unique
      lea xdi, cSuffix
@@:
      ;Translation
      invoke RenderBitField, pContainerName, pType, pName, xdi
      mov pEndToken, xax
      test xax, xax
      jz @ErrorEoF
      jmp @Exit
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
          invoke ParseTypedefFunction, xax, FALSE       ;No return value
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
          OCall xbx::IncFile.GetNextTokenC
          .if ZERO? || CHRA ptr [xax] == ";"            ;Statement terminator
            jmp @Error
          .endif
          .break .if CHRA ptr [xax] == "]"
          Add@Stacklist pDupList, xax, xdx              ;Add Tokens to the DUP-List
          .if CHRA ptr [xax] == "]"
            OCall DupList::%XWordVector.Insert, $OfsCStrA(")")
            .break
          .endif
;          DbgStr xax,, "DUPs"
          OCall DupList::%XWordVector.Insert, xax       ;Add Tokens to the DUP-List
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
      BasicTypeCScan                                    ;Sets dTypeCSpec
      mov pToken, xax                                   ;Last gattered token
      .if dTypeCSpec != 0
        invoke ConvBasicTypeC, dTypeCSpec               
        .if xax == NULL                                 ;If conversion failed
          lea xax, szUnkType
        .endif
        mov pType, xax
        mov xax, pToken
        .continue                                       ;Process the last gattered Token
      .endif
    .endif
    
    IsValidName? pToken
    .if eax != FALSE
      mov xcx, pToken
      .if pType == NULL                                 ;First get a type
        mov pType, xcx
      .elseif pName == NULL                             ;Then get a name
        mov pName, xcx
      .else
        jmp @ErrorSyntax
      .endif
    .else
      jmp @ErrorSyntax
    .endif

@GetNextToken:
    OCall xbx::IncFile.GetNextTokenC
  .endw
  mov pEndToken, xax





  ;Write member to stream ---------------------------------------------------
  .if FALSE;cRecBitBuffer != 0                                ;Check for bit field => record
;##\
;    int 3
;    .if pName == NULL                                   ;It is possible that NO name is supplied!
;      lea xax, cBuffer                                 ;=> create one
;      mov pName, xax
;      invoke wsprintf, xax, $OfsCStrA("Bitfield%u"), dFieldCount
;    .endif

;    ;Write record declaration -----------------------------------------------
;    DbgPrintF , "¦UD: RenderContainerMember - new Bitfield: ¦SA", [xbx].$Obj(IncFile).dLineNumber, pType
;    mov xdx, $OfsCStrA("DUMMYRECORDNAME")               ;Set Default
;    mov xax, pContainerName
;    .if xax != NULL                                     ;Unnamed struct or union
;      .if !$DoesStringMatchA?([xax], <DUMMYSTRUCTNAME>)
;        .if !$DoesStringMatchA?([xax], <DUMMYUNIONNAME>)
;          mov xdx, xax
;        .endif
;      .endif
;    .endif
;    
;    lea xdi, szRecord
;    WriteFA xdi, "¦SA_REC¦UD", xdx, $ObjTmpl(Application).dRecordNameSuffix
;    .if $ObjTmpl(Application).Options.bNoRecords == FALSE
;      OCall xbx::IncFile.StmWrite, addr szRecord
;      OCall xbx::IncFile.StmWrite, $OfsCStrA(" record ")
;    .endif
;
;    .if $ObjTmpl(Application).Options.bNoRecords == FALSE
;      DbgPrintF , "¦UD: RenderContainerMember - new bits: ¦SA", [xbx].$Obj(IncFile).dLineNumber, pName
;      OCall xbx::IncFile.StmWrite, addr cRecBitBuffer
;    .else
;      invoke dec2dwordA, addr cRecBitBuffer
;      mov ecx, dBits
;      xor edx, edx
;      .while eax != 0
;        bts edx, ecx
;        inc ecx
;        dec eax
;      .endw
;      mov dBits, ecx
;      OCall xbx::IncFile.StmWriteF, $OfsCStrA("%s_%s equ 0%xh"), addr szRecord, pName, edx
;      OCall xbx::IncFile.StmWriteEOL
;    .endif
;
;    ;Determine if we are at the end of a record declaration -----------------
;    OCall xbx::IncFile.InputStatusSave, addr InpStat
;    inc [xbx].$Obj(IncFile).bSkipScanPP
;    mov dReturn, TRUE
;    .while TRUE
;      OCall xbx::IncFile.GetNextTokenC
;      .break .if ZERO?
;      .continue .if !IsIfLevelActive?(InpStat)
;      mov cl, [xax]
;      .break .if cl == "," || cl == ";"                 ;Statement terminator
;      .if cl == ":"
;        mov dReturn, FALSE
;        .break
;      .endif
;    .endw
;    dec [xbx].$Obj(IncFile).bSkipScanPP
;    OCall xbx::IncFile.InputStatusLoad, addr InpStat
;
;    .if dReturn != FALSE
;      inc $ObjTmpl(Application).dRecordNameSuffix
;      .if $ObjTmpl(Application).Options.bNoRecords == FALSE
;        OCall xbx::IncFile.StmWriteEOL
;      .endif
;      .if $ObjTmpl(Application).Options.bRecordsInUnions != FALSE
;        OCall xbx::IncFile.StmWrite, addr szUnion
;        OCall xbx::IncFile.StmWriteEOL
;        ;Tab here
;        OCall xbx::IncFile.StmWrite, pType
;        OCall xbx::IncFile.StmWrite, $OfsCStrA(" ?")
;        OCall xbx::IncFile.StmWriteEOL
;      .elseif $ObjTmpl(Application).Options.bNoRecords != FALSE
;        OCall xbx::IncFile.StmWriteF, $OfsCStrA("%s "), addr szRecord 
;        IsStructure? pType
;        .if eax != FALSE
;          OCall xbx::IncFile.StmWrite, $OfsCStrA("<>")
;        .else
;          OCall xbx::IncFile.StmWriteChar, "?"
;        .endif
;        OCall xbx::IncFile.StmWriteEOL
;      .endif
;
;      .if $ObjTmpl(Application).Options.bNoRecords == FALSE
;        OCall xbx::IncFile.StmWrite, addr szRecord
;        OCall xbx::IncFile.StmWrite, $OfsCStrA(" <>")
;
;        ;Write Bit fields in reverse order (MASM and C differs in the order)
;        inc [xbx].$Obj(IncFile).dIndentation
;        .while RecTypeBits.$Obj(StrCollectionA).dCount != 0
;          mov edx, RecTypeBits.$Obj(StrCollectionA).dCount
;          dec edx
;          OCall RecTypeBits::StrCollectionA.ItemAt, edx
;          OCall xbx::IncFile.StmWrite, xax
;          mov edx, RecTypeBits.$Obj(StrCollectionA).dCount
;          dec edx
;          OCall RecTypeBits::StrCollectionA.DisposeAt, edx
;          .if RecTypeBits.$Obj(StrCollectionA).dCount != 0
;            OCall xbx::IncFile.StmWrite, $OfsCStrA(",")
;          .else
;            dec [xbx].$Obj(IncFile).dIndentation
;          .endif
;          OCall xbx::IncFile.StmWriteEOL
;        .endw
;        OCall xbx::IncFile.StmWriteF, $OfsCStrA("%s_REC%u %s_RTP%u ", 3Ch, 3Eh), \
;                                      pMemberBaseName, $ObjTmpl(Application).dRecordNameSuffix,\
;                                      pMemberBaseName, $ObjTmpl(Application).dRecordNameSuffix
;        OCall xbx::IncFile.StmWriteEOL
;      .endif
;      .if $ObjTmpl(Application).Options.bRecordsInUnions != FALSE
;        OCall xbx::IncFile.StmWrite, $OfsCStrA("ends")
;        OCall xbx::IncFile.StmWriteEOL
;      .endif
;
;    .else
;      .if $ObjTmpl(Application).Options.bNoRecords == FALSE
;        OCall xbx::IncFile.StmWrite, $OfsCStrA(", ")
;      .endif
;      inc dFieldCount
;      mov pToken, $OCall(xbx::IncFile.GetNextTokenC)
;      jmp @NextMember
;    .endif
;##/

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
      OCall xbx::IncFile.StmWriteEOL

    .endif
    OCall xbx::IncFile.StmWriteComment
    ;------------------------------------------------------------------------

  .endif

@Exit:
  Destroy@Stacklist pDupList
  OCall DupList::%XWordVector.Done
  mov xax, pEndToken
  test xax, xax
  ret

@ErrorSyntax:             ;Search last ";"
@Error:
@ErrorEoF:
  DbgErrorF , "¦SU(¦UD): RenderContainerMember - error", [xbx].$Obj(IncFile).pHeaderFileName, [xbx].$Obj(IncFile).dLineNumber
  m2m [xbx].$Obj(IncFile).pContainerName, pPrvName, xax
  OCall xbx::IncFile.ShowError, $OfsCStrA("unexpected '%s' ContainerItem: %s"), pContainerName, pToken
  mov xax, pEndToken
  test xax, xax
  ret
RenderContainerMember endp
