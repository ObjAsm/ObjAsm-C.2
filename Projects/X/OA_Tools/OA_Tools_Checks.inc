; ==================================================================================================
; Title:      OA_Tools_Checks.inc
; Author:     G. Friedrich
; Version:    See OA_Tools.asm
; Purpose:    ObjAsm Tools.
; ==================================================================================================


SENTENCE_SIZE   equ 2048
OUTPUT_SIZE     equ 512

RegInfo struc
  bName     CHRA      5 dup(?)    ;Contains at least 1 ZTC
  bSize     BYTE      ?           ;Register word size
  bBitness  BYTE      ?           ;0, 32, 64
  bFiller   BYTE      ?           ;Keep structure aligned
  pSubReg   POINTER   ?
RegInfo ends

DefRegInfo macro RegName:=<>, RegSize:req, Bitness:req, SubReg
  ifb <RegName>
    RegInfo <"", 0, 0, 0, NULL>
  else
    RegInfo_&RegName label RegInfo
    ifb <SubReg>
      RegInfo <"&RegName", RegSize, Bitness, 0, NULL>
    else
      RegInfo <"&RegName", RegSize, Bitness, 0, offset RegInfo_&SubReg>
    endif
  endif
endm

.const
;The following tables are sorted by name length and bName
RegInfoTable_2 label RegInfo                            ;Register name length = 2
  DefRegInfo ah,   08, 32, al
  DefRegInfo al,   08, 32
  DefRegInfo ax,   16, 32, ah
  DefRegInfo bl,   08, 32
  DefRegInfo bp,   16, 32, bpl
  DefRegInfo bx,   16, 32, bl
  DefRegInfo cl,   08, 32
  DefRegInfo cx,   16, 32, cl
  DefRegInfo di,   16, 32, dil
  DefRegInfo dl,   08, 32
  DefRegInfo dx,   16, 32, dl
  DefRegInfo r8,   64, 64, r8d
  DefRegInfo r9,   64, 64, r9d
  DefRegInfo si,   16, 32, sil
  DefRegInfo sp,   16, 32, spl
  DefRegInfo ,     00, 00

RegInfoTable_3 label RegInfo                            ;Register name length = 3
  DefRegInfo bpl,  08, 64
  DefRegInfo dil,  08, 64
  DefRegInfo eax,  32, 32, ax
  DefRegInfo ebp,  32, 32, bp
  DefRegInfo ebx,  32, 32, bx
  DefRegInfo ecx,  32, 32, cx
  DefRegInfo edi,  32, 32, di
  DefRegInfo edx,  32, 32, dx
  DefRegInfo esi,  32, 32, si
  DefRegInfo esp,  32, 32, sp
  DefRegInfo r10,  64, 64, r10d
  DefRegInfo r11,  64, 64, r11d
  DefRegInfo r12,  64, 64, r12d
  DefRegInfo r13,  64, 64, r13d
  DefRegInfo r14,  64, 64, r14d
  DefRegInfo r15,  64, 64, r15d
  DefRegInfo r8b,  08, 64
  DefRegInfo r8d,  32, 64, r8w
  DefRegInfo r8w,  16, 64, r8b
  DefRegInfo r9b,  08, 64
  DefRegInfo r9d,  32, 64, r9w
  DefRegInfo r9w,  16, 64, r9b
  DefRegInfo rax,  64, 64, eax
  DefRegInfo rbp,  64, 64, ebp
  DefRegInfo rbx,  64, 64, ebx
  DefRegInfo rcx,  64, 64, ecx
  DefRegInfo rdi,  64, 64, edi
  DefRegInfo rdx,  64, 64, edx
  DefRegInfo rsi,  64, 64, esi
  DefRegInfo rsp,  64, 64, esp
  DefRegInfo sil,  08, 64
  DefRegInfo spl,  08, 64
  DefRegInfo xax,  00, 00, rax
  DefRegInfo xbp,  00, 00, rbp
  DefRegInfo xbx,  00, 00, rbx
  DefRegInfo xcx,  00, 00, rcx
  DefRegInfo xdi,  00, 00, rdi
  DefRegInfo xdx,  00, 00, rdx
  DefRegInfo xsi,  00, 00, rsi
  DefRegInfo xsp,  00, 00, rsp
  DefRegInfo ,     00, 00

RegInfoTable_4 label RegInfo                            ;Register name length = 4
  DefRegInfo r10b, 08, 64
  DefRegInfo r10d, 32, 64, r10w
  DefRegInfo r10w, 16, 64, r10b
  DefRegInfo r11b, 08, 64
  DefRegInfo r11d, 32, 64, r11w
  DefRegInfo r11w, 16, 64, r11b
  DefRegInfo r12b, 08, 64
  DefRegInfo r12d, 32, 64, r12w
  DefRegInfo r12w, 16, 64, r12b
  DefRegInfo r13b, 08, 64
  DefRegInfo r13d, 32, 64, r13w
  DefRegInfo r13w, 16, 64, r13b
  DefRegInfo r14b, 08, 64
  DefRegInfo r14d, 32, 64, r14w
  DefRegInfo r14w, 16, 64, r14b
  DefRegInfo r15b, 08, 64
  DefRegInfo r15d, 32, 64, r15w
  DefRegInfo r15w, 16, 64, r15b
  DefRegInfo ,     00, 00

RegInfoJumpTable label POINTER
POINTER offset RegInfoTable_2, offset RegInfoTable_3, offset RegInfoTable_4

.code
; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macros      Many
; Purpose:    Build blocks for analysis routines.

CalcNextWordPtr macro
  mov eax, dWordSize
  add xax, pWordStart
endm

SaveWordResult macro
  mov pWordStart, xax
  mov dWordSize, ecx
endm

BreakOrSaveWordResult macro
  .break .if ecx == 0
  SaveWordResult
endm

ReadSentence macro Index:req
  OCall [xsi].LineLengths::DataCollection.ItemAt, Index
  mov ecx, [xax]
  .if ecx > SENTENCE_SIZE
    mov eax, -1
    ExitMethod
  .endif
  lea xdx, bSentence
  m2z CHRA ptr [xdx + xcx]                              ;Set ZTC
  OCall [xsi].DskStream::DiskStream.BinRead, addr bSentence, DWORD ptr [xax]
endm

GetMtdName macro
  CalcNextWordPtr                                       ;xax -> next beginning word
  invoke GetNextWord, xax, FALSE                        ;Object name
  SaveWordResult
  add xax, xcx
  invoke GetNextWord, xax, FALSE                        ;Method name
  inc ecx                                               ;Add the dot between object and method name
  add dWordSize, ecx
  mov pCodeBlockName, $invoke(StrCNewA, pWordStart, dWordSize)
endm

EndMessage macro StrResID:req
  OCall xsi.WriteA, offset bCRLF, [xsi].Color.Notification, 0
  OCall xsi.WriteResStr, StrResID, [xsi].Color.Notification, 0
  OCall xsi.WriteA, offset bCRLF, [xsi].Color.Notification, 0
  OCall xsi.WriteA, offset bCRLF, [xsi].Color.Notification, 0
endm

SkipLineTerminator macro
  .ifBitSet [xsi].dFlags, OATF_TEST_CRLF
    OCall [xsi].DskStream::DiskStream.BinRead, addr bSentence, 2  ;Read CRLF
  .else
    OCall [xsi].DskStream::DiskStream.BinRead, addr bSentence, 1  ;Read CR or LF
  .endif
endm

GetRegisters macro
  .repeat
    CalcNextWordPtr                                     ;xax -> first word after "uses"
    mov pWord, xax
    invoke GetNextWord, xax, FALSE
    BreakOrSaveWordResult
    invoke GetRegisterInfo, xax, dWordSize
    .break .if xax == NULL                              ;It is not a register!

    ;"uses" only accept registers where size = bitness
    .if !(([xax].RegInfo.bSize == 00) && ([xsi].dFlags & OATF_TEST_MX)) || \
        !(([xax].RegInfo.bSize == 64) && ([xsi].dFlags & OATF_TEST_64)) || \
        !(([xax].RegInfo.bSize == 32) && ([xsi].dFlags & OATF_TEST_32))
      .break
    .endif
    invoke StrCNewA, pWordStart, dWordSize
    invoke StrLowerA, xax
    OCall PrsvRegNames::SortedStrCollectionA.Insert, xax
  .until FALSE
endm

GetVariables macro
  .repeat
    invoke GetNextWord, xax, FALSE                      ;Variable name
    BreakOrSaveWordResult
    invoke StrCNewA, pWordStart, dWordSize
    OCall VarNames::SortedStrCollectionA.Insert, xax

    ;Seek for comma and colon
    CalcNextWordPtr
    mov pChar, xax
    invoke StrLScanA, xax, ";"                          ;Get position of next ";"
    mov pColon, xax
    invoke StrLScanA, pChar, ","                        ;Get position of next ","
    .if xax <= pColon                                   ;Comma comes before colon
      .break .if xax == NULL                            ;Comma doesn't exit
    .else
      .break .if pColon != NULL                         ;Colon really exit?
    .endif
  .until FALSE
endm

GetArguments macro IsMethod:=<FALSE>, SkipStrings
  CalcNextWordPtr                                       ;xax -> next beginning word
  .repeat
    invoke GetNextWord, xax, SkipStrings
    BreakOrSaveWordResult
    if IsMethod eq FALSE
      mov xbx, offset ProcAttrList
      .while PSTRINGA ptr [xbx] != NULL
        invoke StrCICompA, PSTRINGA ptr [xbx], pWordStart, dWordSize
        test eax, eax
        jz @F                                           ;Skip this reserved word
        add xbx, sizeof PSTRINGA
      .endw
    endif
    invoke StrCICompA, pWordStart, offset szUses, dWordSize
    test eax, eax
    jz @F                                               ;Skip "uses"
    invoke GetRegisterInfo, pWordStart, dWordSize
    mov ecx, 1                                          ;Set marker
    .break .if xax == NULL                              ;Skip any register
  @@:
    CalcNextWordPtr                                     ;xax -> next beginning word
  .until FALSE

  .if ecx != 0
    mov xax, pWordStart
    GetVariables
  .endif
endm

EchoRegFindings macro StrResID:req, ColorID:req
  invoke StrLengthA, addr bOutput
  .if eax > 0
    inc dFindings
    OCall xsi.WriteA, offset bCRLF, [xsi].Color.Notification, 0
    OCall xsi.WriteResStr, StrResID, [xsi].ColorID, CFE_BOLD
    OCall xsi.WriteA, offset bCRLF, [xsi].Color.Notification, 0
    OCall xsi.WriteResStr, IDS_CODEBLOCK_NAME, [xsi].Color.Notification, 0
    OCall xsi.WriteA, pCodeBlockName, [xsi].Color.Notification, CFE_BOLD
    OCall xsi.WriteLineNumber, dCodeBlockLineNumber
    OCall xsi.WriteResStr, IDS_REGISTERS, [xsi].Color.Notification, 0
    OCall xsi.WriteA, addr bOutput, [xsi].Color.Notification, CFE_BOLD
    OCall xsi.WriteA, offset bCRLF, [xsi].Color.Notification, 0
    OCall xsi.WriteResStr, IDS_WORKING, [xsi].Color.Notification, 0
  .endif
endm

EchoVarFindings macro MsgResID:req, ColorID:req, TypeResID:req
  .if VarNames.dCount > 0
    inc dFindings
    OCall xsi.WriteA, offset bCRLF, [xsi].Color.Notification, 0
    OCall xsi.WriteResStr, MsgResID, [xsi].ColorID, CFE_BOLD
    OCall xsi.WriteA, offset bCRLF, [xsi].Color.Notification, 0
    OCall xsi.WriteResStr, IDS_CODEBLOCK_NAME, [xsi].Color.Notification, 0
    OCall xsi.WriteA, pCodeBlockName, [xsi].Color.Notification, CFE_BOLD
    OCall xsi.WriteLineNumber, dCodeBlockLineNumber
    OCall xsi.WriteResStr, TypeResID, [xsi].Color.Notification, 0
    OCall VarNames::SortedStrCollectionA.ForEach, addr ShowVarName, xsi, [xsi].Color.Notification
    OCall xsi.WriteA, offset bCRLF, [xsi].Color.Notification, 0
    OCall xsi.WriteResStr, IDS_WORKING, [xsi].Color.Notification, 0
  .endif
endm

EvaluateRegResult macro
  mov dInCodeBlock, FALSE
  lea xbx, bOutput
  m2z CHRA ptr [xbx]

  ;Verify if non volatile registers were properly preserved
  .ifBitSet [xsi].dFlags, OATF_TEST_MX
    invoke OutputIfRegisterWasNotPreservedButUsed, $OfsCStrA("xbx"), xbx, addr UsedRegNames, addr PrsvRegNames
    invoke OutputIfRegisterWasNotPreservedButUsed, $OfsCStrA("xdi"), xbx, addr UsedRegNames, addr PrsvRegNames
    invoke OutputIfRegisterWasNotPreservedButUsed, $OfsCStrA("xsi"), xbx, addr UsedRegNames, addr PrsvRegNames
    invoke OutputIfRegisterWasNotPreservedButUsed, $OfsCStrA("xbp"), xbx, addr UsedRegNames, addr PrsvRegNames
  .elseIfBitSet [xsi].dFlags, OATF_TEST_32
    invoke OutputIfRegisterWasNotPreservedButUsed, $OfsCStrA("ebx"), xbx, addr UsedRegNames, addr PrsvRegNames
    invoke OutputIfRegisterWasNotPreservedButUsed, $OfsCStrA("edi"), xbx, addr UsedRegNames, addr PrsvRegNames
    invoke OutputIfRegisterWasNotPreservedButUsed, $OfsCStrA("esi"), xbx, addr UsedRegNames, addr PrsvRegNames
    invoke OutputIfRegisterWasNotPreservedButUsed, $OfsCStrA("ebp"), xbx, addr UsedRegNames, addr PrsvRegNames
  .elseIfBitSet [xsi].dFlags, OATF_TEST_64
    invoke OutputIfRegisterWasNotPreservedButUsed, $OfsCStrA("rbx"), xbx, addr UsedRegNames, addr PrsvRegNames
    invoke OutputIfRegisterWasNotPreservedButUsed, $OfsCStrA("rdi"), xbx, addr UsedRegNames, addr PrsvRegNames
    invoke OutputIfRegisterWasNotPreservedButUsed, $OfsCStrA("rsi"), xbx, addr UsedRegNames, addr PrsvRegNames
    invoke OutputIfRegisterWasNotPreservedButUsed, $OfsCStrA("rbp"), xbx, addr UsedRegNames, addr PrsvRegNames
    invoke OutputIfRegisterWasNotPreservedButUsed, $OfsCStrA("r12"), xbx, addr UsedRegNames, addr PrsvRegNames
    invoke OutputIfRegisterWasNotPreservedButUsed, $OfsCStrA("r13"), xbx, addr UsedRegNames, addr PrsvRegNames
    invoke OutputIfRegisterWasNotPreservedButUsed, $OfsCStrA("r14"), xbx, addr UsedRegNames, addr PrsvRegNames
    invoke OutputIfRegisterWasNotPreservedButUsed, $OfsCStrA("r15"), xbx, addr UsedRegNames, addr PrsvRegNames
  .endif

  EchoRegFindings IDS_REG_ERROR, Color.RegError

  ;Verify if preserved registers were really used
  m2z CHRA ptr [xbx]
  OCall PrsvRegNames::SortedStrCollectionA.ForEach, addr OutputIfRegisterWasNotUsed, xbx, addr UsedRegNames

  EchoRegFindings IDS_REG_WARNING, Color.RegWarning

  OCall PrsvRegNames::SortedStrCollectionA.DisposeAll
  OCall UsedRegNames::SortedStrCollectionA.DisposeAll
  invoke StrDisposeA, pCodeBlockName
endm

EvaluateVarResult macro MsgResID:req, TypeResID:req, ColorID:req
  mov dInCodeBlock, FALSE
  EchoVarFindings MsgResID, ColorID, TypeResID
  OCall VarNames::SortedStrCollectionA.DisposeAll
  invoke StrDisposeA, pCodeBlockName
  jmp @@NextLine
endm

CheckRegInSentence macro
  .if (dInCodeBlock != FALSE) && (dWordSize != 0)
    .repeat
      invoke GetRegisterInfo, pWordStart, dWordSize
      .if xax != NULL
        mov cl, [xax].RegInfo.bSize
        .ifBitSet [xsi].dFlags, OATF_TEST_64
          cmp cl, 0                             ;Ignore mixed mode registers
          je @F
        .elseIfBitSet [xsi].dFlags, OATF_TEST_32
          cmp cl, 0                             ;Ignore mixed mode registers
          je @F
          cmp cl, 64                            ;Ignore 64 bit registers
          je @F
        .endif

        ;Add register name
        invoke StrCNewA, pWordStart, dWordSize
        mov pWord, xax
        OCall UsedRegNames::SortedStrCollectionA.Insert, xax
        .if eax == NULL
          invoke StrDisposeA, pWord
        .endif
      .endif

    @@:
      CalcNextWordPtr                           ;xax -> next beginning word
      invoke GetNextWord, xax, FALSE
      BreakOrSaveWordResult
    .until FALSE
  .endif
endm

CheckVarInSentence macro SkipStrings
  .repeat
    CalcNextWordPtr                                     ;xax -> next beginning word
    mov pChar, xax
    m2m bChar, [xax], cl                                ;Remember character
    m2z CHRA ptr [xax]                                  ;Set ZTC
    OCall VarNames::SortedStrCollectionA.Search, pWordStart
    .if eax != FALSE
      mov edx, ecx
      OCall VarNames::SortedStrCollectionA.DisposeAt, edx
    .endif
    mov xdx, pChar
    m2m [xdx], bChar, cl                                ;Restore character
    invoke GetNextWord, xdx, SkipStrings
    BreakOrSaveWordResult
  .until FALSE
endm

HandleRegAnnotation macro
  CalcNextWordPtr                                       ;xax -> next beginning word
  invoke GetNextWord, xax, FALSE
  BreakOrSaveWordResult
  invoke StrCCompA, pWordStart, offset szPrv, dWordSize
  .if eax == 0
    .repeat
      CalcNextWordPtr                                   ;xax -> next beginning word
      invoke GetNextWord, xax, FALSE
      BreakOrSaveWordResult
      invoke GetRegisterInfo, pWordStart, dWordSize
      .break .if xax == NULL
      invoke StrCNewA, pWordStart, dWordSize
      OCall PrsvRegNames::SortedStrCollectionA.Insert, xax
      invoke GetNextWord, pWordStart, FALSE
      BreakOrSaveWordResult
    .until FALSE
    jmp @@NextLine
  .endif
  invoke StrCCompA, pWordStart, offset szUse, dWordSize
  .if eax == 0
    .repeat
      CalcNextWordPtr                                   ;xax -> next beginning word
      invoke GetNextWord, xax, FALSE
      BreakOrSaveWordResult
      ;Remove this name from the PrsvRegNames SortedStrCollectionA
      invoke GetRegisterInfo, pWordStart, dWordSize
      test xax, xax
      .continue .if ZERO?                               ;Skip non register names
      CalcNextWordPtr                                   ;xax -> next beginning word
      mov pChar, xax
      m2m bChar, [xax], cl                              ;Remember character
      m2z CHRA ptr [xax]                                ;Set ZTC
      OCall PrsvRegNames::SortedStrCollectionA.Search, pWordStart
      .if eax != FALSE
        mov edx, ecx
        OCall PrsvRegNames::SortedStrCollectionA.DisposeAt, edx
      .endif
      mov xdx, pChar
      m2m [xdx], bChar, cl                              ;Restore character
    .until FALSE
  .endif
  jmp @@NextLine
endm

HandleVarAnnotation macro
  CalcNextWordPtr                                       ;xax -> next beginning word
  invoke GetNextWord, xax, FALSE
  BreakOrSaveWordResult
  invoke StrCCompA, pWordStart, offset szUse, dWordSize
  .if eax == 0
    .repeat
      CalcNextWordPtr                                   ;xax -> next beginning word
      invoke GetNextWord, xax, FALSE
      BreakOrSaveWordResult
      ;Remove this name from the PrsvRegNames SortedStrCollectionA
      invoke GetRegisterInfo, pWordStart, dWordSize
      test xax, xax
      .continue .if !ZERO?                              ;Skip register names
      CalcNextWordPtr                                   ;xax -> next beginning word
      mov pChar, xax
      m2m bChar, [xax], cl                              ;Remember character
      m2z CHRA ptr [xax]                                ;Set ZTC
      OCall VarNames::SortedStrCollectionA.Search, pWordStart
      .if eax != FALSE
        mov edx, ecx
        OCall VarNames::SortedStrCollectionA.DisposeAt, edx
      .endif
      mov xdx, pChar
      m2m [xdx], bChar, cl                              ;Restore character
    .until FALSE
  .endif
  jmp @@NextLine
endm

HandleComment macro
  lea xax, bSentence
  .if bCommentChar == 0
    invoke GetNextWord, xax, FALSE
    test ecx, ecx
    jz @@NextLine
    SaveWordResult
    xchg xax, xcx
    invoke StrCICompA, xcx, offset szComment, eax
    .if eax == 0
      CalcNextWordPtr
      .While TRUE
        mov cl, CHRA ptr [xax]
        test cl, cl
        jz @@NextLine
        .break .if cl != " " && cl != 9
        inc xax
      .endw
      mov bCommentChar, cl
      inc xax
      jmp @F
    .endif
  .else
    @@:
    mov xcx, xax
    invoke StrLScanA, xcx, bCommentChar
    .if xax != NULL
      m2z bCommentChar
    .endif
    jmp @@NextLine
  .endif
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  GetRegisterInfo
; Purpose:    Check if the PegName is a full word sized register.
; Arguments:  Arg1: -> Register name.
;             Arg2: Register name length.
; Return:     xax -> RegInfo or NULL.

GetRegisterInfo proc pRegName:PSTRINGA, dRegLen:DWORD
  ?mov edx, dRegLen
  .if (edx <= 4) && (edx >= 2)
    mov xax, pRegName
    .if edx == 2
      movzx ecx, WORD ptr [xax]                         ;Read 2 bytes
      or ecx, 00002020h                                 ;Convert to lowercase
      and ecx, 0000FFFFh
    .else
      mov ecx, [xax]                                    ;Read 4 bytes (if edx = 3, ZTC too)
      or ecx, 20202020h                                 ;Convert to lowercase
      .if edx == 3
        and ecx, 00FFFFFFh
      .endif
    .endif
    mov xax, offset RegInfoJumpTable
    mov xdx, [xax + sizeof(POINTER)*xdx - 2*sizeof(POINTER)]

    .repeat
      mov eax, [xdx]
      .if eax == 0                                      ;End of table
        ret
      .endif
      .if eax == ecx
        mov xax, xdx
        ret
      .endif
      add xdx, sizeof RegInfo
    .until FALSE
  .else
    xor eax, eax
  .endif
  ret
GetRegisterInfo endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  CheckIfRegisterWasUsed
; Purpose:    verify if a register or any of its subregisters are present in the UsedRegNames
;             collection.
; Arguments:  Arg1: -> Register name.
;             Arg2: -> UsedRegNames SortedStrCollectionA.
; Return:     eax = TRUE/FALSE.

CheckIfRegisterWasUsed proc uses xbx pRegName:PSTRINGA, pUsedRegNames:$ObjPtr(SortedStrCollectionA)
  mov xbx, pRegName
  .repeat
    OCall pUsedRegNames::SortedStrCollectionA.Search, xbx
    .break .if eax != FALSE
    ;Check the subregister
    invoke StrLengthA, xbx
    invoke GetRegisterInfo, xbx, eax
    mov xax, [xax].RegInfo.pSubReg
    .break .if xax == NULL
    mov xbx, xax
  .until FALSE
  ret
CheckIfRegisterWasUsed endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  OutputIfRegisterWasNotUsed
; Purpose:    Procedure to verify if a register or any of its subregisters are present
;             in the UsedRegNames collection. If they are not, then write the starting register
;             to the output buffer.
; Arguments:  Arg1: -> Register name.
;             Arg2: -> Output character buffer.
;             Arg3: -> UsedRegNames SortedStrCollectionA.
; Return:     Nothing.

OutputIfRegisterWasNotUsed proc uses xbx pRegName:PSTRINGA, pOutput:PSTRINGA, \
                                         pUsedRegNames:$ObjPtr(SortedStrCollectionA)
  mov xbx, pRegName
  .repeat
    OCall pUsedRegNames::SortedStrCollectionA.Search, xbx
    .break .if eax != FALSE
    ;Check the subregister
    invoke StrLengthA, xbx
    invoke GetRegisterInfo, xbx, eax
    mov xax, [xax].RegInfo.pSubReg
    .if xax == NULL
      invoke StrCatCharA, pOutput, " "
      invoke StrCatA, pOutput, pRegName
      .break
    .endif
    mov xbx, xax
  .until FALSE
  ret
OutputIfRegisterWasNotUsed endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  OutputIfRegisterWasUsed
; Purpose:    Procedure to verify if a register or any of its subregisters are present
;             in the UsedRegNames collection. If they were, write them all to the output buffer.
; Arguments:  Arg1: -> Register name.
;             Arg2: -> Output character buffer.
;             Arg3: -> UsedRegNames SortedStrCollectionA.
; Return:     Nothing.

OutputIfRegisterWasUsed proc uses xbx pRegName:PSTRINGA, pOutput:PSTRINGA, \
                                      pUsedRegNames:$ObjPtr(SortedStrCollectionA)
  mov xbx, pRegName
  .repeat
    OCall pUsedRegNames::SortedStrCollectionA.Search, xbx
    .if eax != FALSE
      invoke StrCatCharA, pOutput, " "
      invoke StrCatA, pOutput, xbx
    .endif
    ;Check the subregister
    invoke StrLengthA, xbx
    invoke GetRegisterInfo, xbx, eax
    mov xbx, [xax].RegInfo.pSubReg
    .break .if xbx == NULL
  .until FALSE
  ret
OutputIfRegisterWasUsed endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  OutputIfRegisterWasNotPreservedButUsed
; Purpose:    Verify if a register was NOT preserved and if it or any of its subregisters were
;             used. If the were, output them all to the output buffer.
; Arguments:  Arg1: -> Register name.
;             Arg2: -> Output character buffer.
;             Arg3: -> UsedRegNames SortedStrCollectionA.
;             Arg4: -> PrsvRegNames SortedStrCollectionA.
; Return:     Nothing.

OutputIfRegisterWasNotPreservedButUsed proc pRegName:PSTRINGA, \
                                            pOutput:PSTRINGA, \
                                            pUsedRegNames:$ObjPtr(SortedStrCollectionA), \
                                            pPrsvRegNames:$ObjPtr(SortedStrCollectionA)
  OCall pPrsvRegNames::SortedStrCollectionA.Search, pRegName
  .if eax == FALSE
    invoke OutputIfRegisterWasUsed, pRegName, pOutput, pUsedRegNames
  .endif
  ret
OutputIfRegisterWasNotPreservedButUsed endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  ShowVarName
; Purpose:    Callback procedure.
; Arguments:  Arg1: -> Variable name.
;             Arg2: -> Output OAT_Child.
;             Arg3: Output color.
; Return:     Nothing.

ShowVarName proc pVarName:PSTRINGA, pChild:$ObjPtr(OAT_Child), Color:RGBQUAD
  OCall pChild::OAT_Child.WriteA, $OfsCStrA(" "), Color, CFE_BOLD
  OCall pChild::OAT_Child.WriteA, pVarName, Color, CFE_BOLD
  ret
ShowVarName endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  GetNextWord
; Purpose:    Search for the next word in a specified sentence.
; Arguments:  Arg1: -> Sentence.
; Return:     xax -> Word beginning.
;             ecx = Word length. If a comment character ";" is found, ecx = 0.

.const
SeparatorLUT label BYTE
  ;  NUL  SOH  STX  ETX  EDT  ENQ  ACK  BEL  BS   TAB  LF   VF   FF   CR   SO   SI
  db 001h,001h,001h,001h,001h,001h,001h,001h,001h,001h,001h,001h,001h,001h,001h,001h
  ;  DLE  DC1  DC2  DC3  DC4  NAK  SYN  ETB  CAN  BM   SUB  ESC  FS   GS   RS   US
  db 001h,001h,001h,001h,001h,001h,001h,001h,001h,001h,001h,001h,001h,001h,001h,001h
  ;  SPC    !    "    #    $    %    &    '    (    )    *    +    ,    -    .    /
  db 001h,001h,001h,000h,000h,001h,001h,001h,001h,001h,001h,001h,001h,001h,001h,001h
  ;    0    1    2    3    4    5    6    7    8    9    :    ;    <    =    >    ?
  db 000h,000h,000h,000h,000h,000h,000h,000h,000h,000h,001h,001h,001h,001h,001h,000h
  ;    @    A    B    C    D    E    F    G    H    I    J    K    L    M    N    O
  db 000h,000h,000h,000h,000h,000h,000h,000h,000h,000h,000h,000h,000h,000h,000h,000h
  ;    P    Q    R    S    T    U    V    W    X    Y    Z    [    \    ]    ^    _
  db 000h,000h,000h,000h,000h,000h,000h,000h,000h,000h,000h,001h,001h,001h,001h,000h
  ;    `    a    b    c    d    e    f    g    h    i    j    k    l    m    n    o
  db 001h,000h,000h,000h,000h,000h,000h,000h,000h,000h,000h,000h,000h,000h,000h,000h
  ;    p    q    r    s    t    u    v    w    x    y    z    {    |    }    ~
  db 000h,000h,000h,000h,000h,000h,000h,000h,000h,000h,000h,001h,001h,001h,001h,000h
  db 000h,000h,000h,000h,000h,000h,000h,000h,000h,000h,000h,000h,000h,000h,000h,000h
  db 000h,000h,000h,000h,000h,000h,000h,000h,000h,000h,000h,000h,000h,000h,000h,000h
  db 000h,000h,000h,000h,000h,000h,000h,000h,000h,000h,000h,000h,000h,000h,000h,000h
  db 000h,000h,000h,000h,000h,000h,000h,000h,000h,000h,000h,000h,000h,000h,000h,000h
  db 000h,000h,000h,000h,000h,000h,000h,000h,000h,000h,000h,000h,000h,000h,000h,000h
  db 000h,000h,000h,000h,000h,000h,000h,000h,000h,000h,000h,000h,000h,000h,000h,000h
  db 000h,000h,000h,000h,000h,000h,000h,000h,000h,000h,000h,000h,000h,000h,000h,000h
  db 000h,000h,000h,000h,000h,000h,000h,000h,000h,000h,000h,000h,000h,000h,000h,000h

.code
GetNextWord proc uses xbx pStart:PSTRINGA, dSkipStrings:DWORD
  local dInWord:DWORD, dInString:DWORD, bStrDelimiter:CHRA

  xor eax, eax
  xor ecx, ecx
  mov dInWord, ecx
  mov dInString, ecx
  mov xbx, pStart
  .repeat
    mov al, [xbx]
    .if dInString != FALSE
      .if al == 0                                       ;End Of Sentence
        mov xax, xbx
        ret
      .else
        .if al == bStrDelimiter
          mov dInString, FALSE
        .endif
        inc xbx
      .endif
    .else
      .if ((al == "'") || (al == '"')) && dSkipStrings == FALSE
        mov dInString, TRUE
        mov bStrDelimiter, al
        inc xbx
      .else
        .if al == 0
          .if dInWord == FALSE
            mov xax, xbx
          .else
            mov xax, xbx
            sub xax, xcx
          .endif
          ret
        .else
          .if al == ";"
            mov xax, xbx
            sub xax, xcx
            ret
          .else
            mov xdx, offset SeparatorLUT
            .if BYTE ptr [xdx + xax] != 0
              .if dInWord != FALSE
                mov xax, xbx
                sub xax, xcx
                ret
              .else
                ;A dot is allowed only if it is the first character of a variable name.
                .if al == "." && xbx > pStart && \
                    (CHRA ptr [xbx - 1] == " " || CHRA ptr [xbx - 1] == 9)
                  inc xcx
                .endif
                inc xbx
              .endif
            .else
              mov dInWord, TRUE
              inc xbx
              inc xcx
            .endif
          .endif
        .endif
      .endif
    .endif
  .until FALSE
  ret
GetNextWord endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     OAT_App.CheckMtdArg
; Purpose:    Verify the use object method arguments.
; Arguments:  None.
; Return:     eax: Number of findings.

Method OAT_Child.CheckMtdArg, uses xbx xdi xsi
  local VarNames:$Obj(SortedStrCollectionA)
  local bOutput[OUTPUT_SIZE]:CHRA, dFindings:DWORD
  local bSentence[SENTENCE_SIZE]:CHRA
  local pCodeBlockName:PSTRINGA, dCodeBlockLineNumber:DWORD, dInCodeBlock:DWORD, bCommentChar:CHRA
  local pWordStart:PSTRINGA, dWordSize:DWORD, pWord:PSTRINGA, pChar:PSTRINGA, bChar:CHRA, pColon:PSTRINGA

  ANNOTATION use:bChar bOutput pChar pCodeBlockName pColon pWord
  ANNOTATION use:xbx

  SetObject xsi
  mov dInCodeBlock, FALSE
  m2z bCommentChar
  m2z dFindings
  OCall xsi.WriteResStr, IDS_WORKING, [xsi].Color.Notification, 0
  New VarNames::SortedStrCollectionA
  OCall VarNames::SortedStrCollectionA.Init, xsi, 10, 5, COL_MAX_CAPACITY

  xor edi, edi                                          ;Reset line counter
  .repeat
    ReadSentence edi

    HandleComment

    invoke GetNextWord, addr bSentence, FALSE
    test ecx, ecx
    jz @@NextLine
    SaveWordResult

    ;Search for the word "Method" at the beginning of a sentence
    .if dInCodeBlock == FALSE
      invoke StrCCompA, pWordStart, offset szMethod, dWordSize
      .if eax == 0
        inc dInCodeBlock
        mov dCodeBlockLineNumber, edi
        OCall xsi.WriteA, offset szDot, [xsi].Color.Notification, 0
        GetMtdName                                      ;pCodeBlockName
        GetArguments TRUE, FALSE
      .endif
      jmp @@NextLine
    .endif

    invoke StrCCompA, pWordStart, offset szMethodEnd, dWordSize
    .if eax == 0
      ;NOFRAME is a special keyword from ObjAsm32 and should not be considered as an argument.
      .ifBitSet [xsi].dFlags, OATF_TEST_32
        OCall VarNames::SortedStrCollectionA.Search, $OfsCStrA("NOFRAME")
        .if eax != FALSE
          mov edx, ecx
          OCall VarNames::SortedStrCollectionA.DisposeAt, edx
        .endif
      .endif
      EvaluateVarResult IDS_ARG_WARNING, IDS_ARGUMENTS, Color.ArgWarning
    .endif

    .ifBitSet [xsi].dFlags, OATF_TEST_ANNOT
      invoke StrCCompA, pWordStart, offset szANNOTATION, dWordSize
      .if eax == 0
        HandleVarAnnotation
      .endif
    .endif

    CheckVarInSentence FALSE

@@NextLine:
    inc edi
    .break .if edi == [xsi].LineLengths.dCount
    SkipLineTerminator
  .until FALSE
  OCall VarNames::SortedStrCollectionA.Done
  EndMessage IDS_CHECK_ARG_READY
  mov eax, dFindings
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     OAT_App.CheckMtdLoc
; Purpose:    Verify the use of method local variables in the currently opened stream.
; Arguments:  None.
; Return:     eax = Number of findings. -1 means an error.

Method OAT_Child.CheckMtdLoc, uses xbx xdi xsi
  local VarNames:$Obj(SortedStrCollectionA)
  local bSentence[SENTENCE_SIZE]:CHRA, bChar:CHRA, dFindings:DWORD, bCommentChar:CHRA
  local pCodeBlockName:PSTRINGA, dCodeBlockLineNumber:DWORD, dInCodeBlock:DWORD
  local pWordStart:PSTRINGA, dWordSize:DWORD, pChar:PSTRINGA, pColon:PSTRINGA

  ANNOTATION use:bChar pChar pCodeBlockName pColon

  SetObject xsi
  mov dInCodeBlock, FALSE
  m2z bCommentChar
  m2z dFindings
  OCall xsi.WriteResStr, IDS_WORKING, [xsi].Color.Notification, 0
  New VarNames::SortedStrCollectionA
  OCall VarNames::SortedStrCollectionA.Init, xsi, 10, 5, COL_MAX_CAPACITY

  xor edi, edi                                          ;Reset line counter
  .repeat
    ReadSentence edi

    HandleComment

    invoke GetNextWord, addr bSentence, FALSE           ;Get the first word in the sentence
    test ecx, ecx
    jz @@NextLine
    SaveWordResult

    .if dInCodeBlock == FALSE
      invoke StrCCompA, pWordStart, offset szMethod, dWordSize
      .if eax == 0                                      ;Method?
        inc dInCodeBlock
        mov dCodeBlockLineNumber, edi
        OCall xsi.WriteA, offset szDot, [xsi].Color.Notification, 0
        GetMtdName                                      ;pCodeBlockName
      .endif
      jmp @@NextLine
    .endif

    invoke StrCCompA, pWordStart, offset szMethodEnd, dWordSize
    .if eax == 0
      EvaluateVarResult IDS_LOC_WARNING, IDS_LOCALS, Color.LocWarning
    .endif

    invoke StrCICompA, pWordStart, offset szLocal, dWordSize
    .if eax == 0
      CalcNextWordPtr                                   ;xax -> next beginning word
      GetVariables
      jmp @@NextLine
    .endif

    .ifBitSet [xsi].dFlags, OATF_TEST_ANNOT
      invoke StrCCompA, pWordStart, offset szANNOTATION, dWordSize
      .if eax == 0
        HandleVarAnnotation
      .endif
    .endif

    CheckVarInSentence FALSE

@@NextLine:
    inc edi
    .break .if edi == [xsi].LineLengths.dCount
    SkipLineTerminator
  .until FALSE
  OCall VarNames::SortedStrCollectionA.Done
  EndMessage IDS_CHECK_LOC_READY
  mov eax, dFindings
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     OAT_Child.CheckMtdReg
; Purpose:    Verify the use and preservation of non volatile registers on object methods.
; Arguments:  None.
; Return:     eax = Number of findings. -1 means an error.

Method OAT_Child.CheckMtdReg, uses xbx xdi xsi
  local PrsvRegNames:$Obj(SortedStrCollectionA), UsedRegNames:$Obj(SortedStrCollectionA)
  local bOutput[OUTPUT_SIZE]:CHRA, dFindings:DWORD, pChar:PSTRINGA, bChar:CHRA
  local bSentence[SENTENCE_SIZE]:CHRA, bCommentChar:CHRA
  local pCodeBlockName:PSTRINGA, dCodeBlockLineNumber:DWORD, dInCodeBlock:DWORD
  local pWordStart:PSTRINGA, dWordSize:DWORD, pWord:PSTRINGA

  ANNOTATION use:xbx bChar pChar Output pCodeBlockName pWord bOutput xbx

  SetObject xsi
  mov dInCodeBlock, FALSE
  m2z bCommentChar
  m2z dFindings
  OCall xsi.WriteResStr, IDS_WORKING, [xsi].Color.Notification, 0
  New PrsvRegNames::SortedStrCollectionA
  OCall PrsvRegNames::SortedStrCollectionA.Init, xsi, 10, 10, COL_MAX_CAPACITY
  New UsedRegNames::SortedStrCollectionA
  OCall UsedRegNames::SortedStrCollectionA.Init, xsi, 50, 10, COL_MAX_CAPACITY

  xor edi, edi                                          ;Reset line counter
  .repeat
    ReadSentence edi

    HandleComment

    ;Search for the word "Method" at the beginning of a sentence
    invoke GetNextWord, addr bSentence, FALSE
    test ecx, ecx
    jz @@NextLine
    SaveWordResult

    .if dInCodeBlock == FALSE
      invoke StrCCompA, pWordStart, offset szMethod, dWordSize
      .if eax == 0
        inc dInCodeBlock
        mov dCodeBlockLineNumber, edi
        OCall xsi.WriteA, offset szDot, [xsi].Color.Notification, 0
        GetMtdName                                      ;pCodeBlockName
        CalcNextWordPtr                                 ;xax -> next beginning word
        .repeat
          invoke GetNextWord, xax, FALSE
          BreakOrSaveWordResult
          invoke StrCICompA, xax, offset szUses, dWordSize
          .break .if eax == 0
          CalcNextWordPtr                               ;xax -> next beginning word
        .until FALSE

        .if eax == 0
          GetRegisters
        .endif
      .endif
      jmp @@NextLine
    .endif

    invoke StrCCompA, pWordStart, offset szMethodEnd, dWordSize
    .if eax == 0
      EvaluateRegResult
      jmp @@NextLine
    .endif

    .ifBitSet [xsi].dFlags, OATF_TEST_ANNOT
      invoke StrCCompA, pWordStart, offset szANNOTATION, dWordSize
      .if eax == 0
        HandleRegAnnotation
      .endif
    .endif

    invoke StrCICompA, pWordStart, offset szUsing, dWordSize
    .if eax == 0
      GetRegisters
      jmp @@NextLine   
    .endif

    CheckRegInSentence

@@NextLine:
    inc edi
    .break .if edi == [xsi].LineLengths.dCount
    SkipLineTerminator
  .until FALSE
  OCall PrsvRegNames::SortedStrCollectionA.Done
  OCall UsedRegNames::SortedStrCollectionA.Done
  EndMessage IDS_CHECK_REG_READY
  mov eax, dFindings
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     OAT_Child.CheckPrcArg
; Purpose:    Verify the use object procedure arguments.
; Arguments:  None.
; Return:     eax = Number of findings. -1 means an error.

Method OAT_Child.CheckPrcArg, uses xbx xdi xsi
  local VarNames:$Obj(SortedStrCollectionA)
  local bSentence[SENTENCE_SIZE]:CHRA, bChar:CHRA, dFindings:DWORD, bCommentChar:CHRA
  local pCodeBlockName:PSTRINGA, dCodeBlockLineNumber:DWORD, dInCodeBlock:DWORD
  local pWordStart:PSTRINGA, dWordSize:DWORD, pChar:PSTRINGA, pColon:PSTRINGA
  local pPrvWordStart:PSTRINGA, dPrvWordSize:DWORD

  ANNOTATION use:xbx bChar pChar pColon

  SetObject xsi
  mov dInCodeBlock, FALSE
  m2z bCommentChar
  m2z dFindings
  OCall xsi.WriteResStr, IDS_WORKING, [xsi].Color.Notification, 0
  New VarNames::SortedStrCollectionA
  OCall VarNames::SortedStrCollectionA.Init, xsi, 10, 5, COL_MAX_CAPACITY

  xor edi, edi                                          ;Reset line counter
  .repeat
    ReadSentence edi

    ;Search for the word "proc" at the second word of a sentence
    invoke GetNextWord, addr bSentence, FALSE
    test ecx, ecx
    jz @@NextLine
    .if dInCodeBlock == FALSE
      mov pPrvWordStart, xax
      mov dPrvWordSize,  ecx
      invoke GetNextWord, addr [xax + xcx], FALSE
      test ecx, ecx
      jz @@NextLine
      SaveWordResult
      invoke StrCICompA, pWordStart, offset szProc, dWordSize
      .if eax == 0
        inc dInCodeBlock
        mov dCodeBlockLineNumber, edi
        OCall xsi.WriteA, offset szDot, [xsi].Color.Notification, 0
        mov pCodeBlockName, $invoke(StrCNewA, pPrvWordStart, dPrvWordSize)
        GetArguments FALSE, FALSE
      .endif
      jmp @@NextLine
    .endif

    SaveWordResult
    invoke StrCCompA, pWordStart, pCodeBlockName, dWordSize
    .if eax == 0
      CalcNextWordPtr
      invoke GetNextWord, xax, FALSE
      .if xax != NULL
        xchg xax, xcx
        invoke StrCICompA, xcx, offset szEndp, eax
        .if eax == 0
          EvaluateVarResult IDS_ARG_WARNING, IDS_ARGUMENTS, Color.ArgWarning
        .endif
      .endif
    .endif

    .ifBitSet [xsi].dFlags, OATF_TEST_ANNOT
      invoke StrCCompA, pWordStart, offset szANNOTATION, dWordSize
      .if eax == 0
        HandleVarAnnotation
      .endif
    .endif

    CheckVarInSentence FALSE

@@NextLine:
    inc edi
    .break .if edi == [xsi].LineLengths.dCount
    SkipLineTerminator
  .until FALSE
  OCall VarNames::SortedStrCollectionA.Done
  EndMessage IDS_CHECK_ARG_READY
  mov eax, dFindings
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:   	OAT_Child.CheckPrcLoc
; Purpose:  	Verify the use of procedure local variables in the currently opened stream.
; Arguments:	None.
; Return:     eax = Number of findings. -1 means an error.

Method OAT_Child.CheckPrcLoc, uses xbx xdi xsi
  local VarNames:$Obj(SortedStrCollectionA)
  local bSentence[SENTENCE_SIZE]:CHRA, bChar:CHRA, dFindings:DWORD, bCommentChar:CHRA
  local pCodeBlockName:PSTRINGA, dCodeBlockLineNumber:DWORD, dInCodeBlock:DWORD
  local pWordStart:PSTRINGA, dWordSize:DWORD, pChar:PSTRINGA, pColon:PSTRINGA
  local pPrvWordStart:PSTRINGA, dPrvWordSize:DWORD

  ANNOTATION use:bChar pChar pColon

  SetObject xsi
  mov dInCodeBlock, FALSE
  m2z bCommentChar
  m2z dFindings
  OCall xsi.WriteResStr, IDS_WORKING, [xsi].Color.Notification, 0
  New VarNames::SortedStrCollectionA
  OCall VarNames::SortedStrCollectionA.Init, xsi, 10, 5, COL_MAX_CAPACITY

  xor edi, edi                                          ;Reset line counter
  .repeat
    ReadSentence edi

    HandleComment

    ;Search for the word "proc" at the second word of a sentence
    invoke GetNextWord, addr bSentence, FALSE
    test ecx, ecx
    jz @@NextLine
    .if dInCodeBlock == FALSE
      mov pPrvWordStart, xax
      mov dPrvWordSize,  ecx
      invoke GetNextWord, addr [xax + xcx], FALSE
      test ecx, ecx
      jz @@NextLine
      SaveWordResult
      invoke StrCICompA, pWordStart, offset szProc, dWordSize
      .if eax == 0
        inc dInCodeBlock
        mov dCodeBlockLineNumber, edi
        OCall xsi.WriteA, offset szDot, [xsi].Color.Notification, 0
        mov pCodeBlockName, $invoke(StrCNewA, pPrvWordStart, dPrvWordSize)
      .endif
      jmp @@NextLine
    .endif

    SaveWordResult
    invoke StrCCompA, pWordStart, pCodeBlockName, dWordSize
    .if eax == 0
      CalcNextWordPtr
      invoke GetNextWord, xax, FALSE
      .if xax != NULL
        xchg xax, xcx
        invoke StrCICompA, xcx, offset szEndp, eax
        .if eax == 0
          EvaluateVarResult IDS_LOC_WARNING, IDS_LOCALS, Color.LocWarning
        .endif
      .endif
    .endif

    invoke StrCICompA, pWordStart, offset szLocal, dWordSize
    .if eax == 0
      CalcNextWordPtr                                   ;xax -> next beginning word
      GetVariables
      jmp @@NextLine
    .endif

    .ifBitSet [xsi].dFlags, OATF_TEST_ANNOT
      invoke StrCCompA, pWordStart, offset szANNOTATION, dWordSize
      .if eax == 0
        HandleVarAnnotation
      .endif
    .endif

    CheckVarInSentence FALSE

@@NextLine:
    inc edi
    .break .if edi == [xsi].LineLengths.dCount
    SkipLineTerminator
  .until FALSE
  OCall VarNames::SortedStrCollectionA.Done
  EndMessage IDS_CHECK_LOC_READY
  mov eax, dFindings
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:   	OAT_Child.CheckPrcReg
; Purpose:  	Verify the use and preservation of non volatile registers on object methods.
; Arguments:	None.
; Return:     eax = Number of findings. -1 means an error.

Method OAT_Child.CheckPrcReg, uses xbx xdi xsi
  local PrsvRegNames:$Obj(SortedStrCollectionA), UsedRegNames:$Obj(SortedStrCollectionA)
  local bOutput[OUTPUT_SIZE]:CHRA, dFindings:DWORD
  local bSentence[SENTENCE_SIZE]:CHRA, bCommentChar:CHRA
  local pCodeBlockName:PSTRINGA, dCodeBlockLineNumber:DWORD, dInCodeBlock:DWORD
  local pWordStart:PSTRINGA, dWordSize:DWORD, pWord:PSTRINGA
  local pPrvWordStart:PSTRINGA, dPrvWordSize:DWORD
  local bChar:CHRA, pChar:PSTRINGA

  ANNOTATION use:xbx bChar bOutput pChar pWord xbx

  SetObject xsi

  mov dInCodeBlock, FALSE
  m2z bCommentChar
  m2z dFindings
  OCall xsi.WriteResStr, IDS_WORKING, [xsi].Color.Notification, 0
  New PrsvRegNames::SortedStrCollectionA
  OCall PrsvRegNames::SortedStrCollectionA.Init, xsi, 10, 10, COL_MAX_CAPACITY
  New UsedRegNames::SortedStrCollectionA
  OCall UsedRegNames::SortedStrCollectionA.Init, xsi, 50, 10, COL_MAX_CAPACITY

  xor edi, edi                                          ;Reset line counter
  .repeat
    ReadSentence edi

    HandleComment

    ;Search for the word "proc" at the second word of a sentence
    invoke GetNextWord, addr bSentence, FALSE
    test ecx, ecx
    jz @@NextLine
    .if dInCodeBlock == FALSE
      mov pPrvWordStart, xax
      mov dPrvWordSize,  ecx
      invoke GetNextWord, addr [xax + xcx], FALSE
      test ecx, ecx
      jz @@NextLine
      SaveWordResult
      invoke StrCICompA, pWordStart, offset szProc, dWordSize
      .if eax == 0
        inc dInCodeBlock
        mov dCodeBlockLineNumber, edi
        OCall xsi.WriteA, offset szDot, [xsi].Color.Notification, 0
        mov pCodeBlockName, $invoke(StrCNewA, pPrvWordStart, dPrvWordSize)
        CalcNextWordPtr                                 ;xax -> next beginning word
        .repeat
          invoke GetNextWord, xax, FALSE
          BreakOrSaveWordResult
          invoke StrCICompA, xax, offset szUses, dWordSize
          .break .if eax == 0
          CalcNextWordPtr                               ;xax -> next beginning word
        .until FALSE
        .if eax == 0                                    ;Get registers after the "uses" keyword
          GetRegisters
        .endif
      .endif
      jmp @@NextLine
    .endif

    SaveWordResult
    invoke StrCCompA, pWordStart, pCodeBlockName, dWordSize
    .if eax == 0
      CalcNextWordPtr
      invoke GetNextWord, xax, FALSE
      .if xax != NULL
        xchg xax, xcx
        invoke StrCICompA, xcx, offset szEndp, eax
        .if eax == 0
          EvaluateRegResult
          jmp @@NextLine
        .endif
      .endif
    .endif

    .ifBitSet [xsi].dFlags, OATF_TEST_ANNOT
      invoke StrCCompA, pWordStart, offset szANNOTATION, dWordSize
      .if eax == 0
        HandleRegAnnotation
      .endif
    .endif

    invoke StrCICompA, pWordStart, offset szUsing, dWordSize
    .if eax == 0
      GetRegisters
      jmp @@NextLine   
    .endif

    CheckRegInSentence

@@NextLine:
    inc edi
    .break .if edi == [xsi].LineLengths.dCount
    SkipLineTerminator
  .until FALSE

  OCall PrsvRegNames::SortedStrCollectionA.Done
  OCall UsedRegNames::SortedStrCollectionA.Done
  EndMessage IDS_CHECK_REG_READY
  mov eax, dFindings
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     OAT_Child.CheckMacArg
; Purpose:    Verify the use object procedure arguments.
; Arguments:  None.
; Return:     eax = Number of findings. -1 means an error.

Method OAT_Child.CheckMacArg, uses xbx xdi xsi
  local VarNames:$Obj(SortedStrCollectionA)
  local bSentence[SENTENCE_SIZE]:CHRA, bChar:CHRA, dFindings:DWORD, bCommentChar:CHRA
  local pCodeBlockName:PSTRINGA, dCodeBlockLineNumber:DWORD, dInCodeBlock:DWORD
  local pWordStart:PSTRINGA, dWordSize:DWORD, pChar:PSTRINGA, pColon:PSTRINGA
  local pPrvWordStart:PSTRINGA, dPrvWordSize:DWORD, dMacroLevel:DWORD

  ANNOTATION use:xbx bChar pChar pColon

  SetObject xsi
  mov dInCodeBlock, FALSE
  m2z dMacroLevel
  m2z bCommentChar
  m2z dFindings
  OCall xsi.WriteResStr, IDS_WORKING, [xsi].Color.Notification, 0
  New VarNames::SortedStrCollectionA
  OCall VarNames::SortedStrCollectionA.Init, xsi, 10, 5, COL_MAX_CAPACITY

  xor edi, edi                                          ;Reset line counter
  .repeat
    ReadSentence edi

    HandleComment

    ;Search for the word "macro" at the second word of a sentence
    invoke GetNextWord, addr bSentence, TRUE
    test ecx, ecx
    jz @@NextLine
    .if dInCodeBlock == FALSE
      mov pPrvWordStart, xax
      mov dPrvWordSize,  ecx
      invoke GetNextWord, addr [xax + xcx], TRUE
      test ecx, ecx
      jz @@NextLine
      SaveWordResult
      invoke StrCICompA, pWordStart, offset szMacro, dWordSize
      .if eax == 0
        inc dMacroLevel
        inc dInCodeBlock
        mov dCodeBlockLineNumber, edi
        OCall xsi.WriteA, offset szDot, [xsi].Color.Notification, 0
        mov pCodeBlockName, $invoke(StrCNewA, pPrvWordStart, dPrvWordSize)
        GetArguments FALSE, TRUE
      .endif
      jmp @@NextLine
    .endif

    SaveWordResult
    ;Check the first word in the sentence
    mov xbx, offset MacroBlockList
    .while PSTRINGA ptr [xbx] != NULL
      invoke StrCICompA, PSTRINGA ptr [xbx], pWordStart, dWordSize
      .if eax == 0
        inc dMacroLevel
        jmp @@NextWord
      .endif
      add xbx, sizeof PSTRINGA
    .endw

    invoke StrCICompA, pWordStart, offset szEndm, dWordSize
    .if eax == 0
      dec dMacroLevel
      .if ZERO?
        EvaluateVarResult IDS_ARG_WARNING, IDS_ARGUMENTS, Color.ArgWarning
      .endif
    .endif

@@NextWord:
    .ifBitSet [xsi].dFlags, OATF_TEST_ANNOT
      invoke StrCCompA, pWordStart, offset szANNOTATION, dWordSize
      .if eax == 0
        HandleVarAnnotation
      .endif
    .endif

    CheckVarInSentence TRUE

@@NextLine:
    inc edi
    .break .if edi == [xsi].LineLengths.dCount
    SkipLineTerminator
  .until FALSE
  OCall VarNames::SortedStrCollectionA.Done
  EndMessage IDS_CHECK_ARG_READY
  mov eax, dFindings
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:   	OAT_Child.CheckMacLoc
; Purpose:  	Verify the use of procedure local variables in the currently opened stream.
; Arguments:	None.
; Return:     eax = Number of findings. -1 means an error.

Method OAT_Child.CheckMacLoc, uses xbx xdi xsi
  local VarNames:$Obj(SortedStrCollectionA)
  local bSentence[SENTENCE_SIZE]:CHRA, bChar:CHRA, dFindings:DWORD, bCommentChar:CHRA
  local pCodeBlockName:PSTRINGA, dCodeBlockLineNumber:DWORD, dInCodeBlock:DWORD
  local pWordStart:PSTRINGA, dWordSize:DWORD, pChar:PSTRINGA, pColon:PSTRINGA
  local pPrvWordStart:PSTRINGA, dPrvWordSize:DWORD, dMacroLevel:DWORD

  ANNOTATION use:bChar pChar pColon

  SetObject xsi
  mov dInCodeBlock, FALSE
  m2z dMacroLevel
  m2z bCommentChar
  m2z dFindings
  OCall xsi.WriteResStr, IDS_WORKING, [xsi].Color.Notification, 0
  New VarNames::SortedStrCollectionA
  OCall VarNames::SortedStrCollectionA.Init, xsi, 10, 5, COL_MAX_CAPACITY

  xor edi, edi                                          ;Reset line counter
  .repeat
    ReadSentence edi

    HandleComment

    ;Search for the word "proc" at the second word of a sentence
    invoke GetNextWord, addr bSentence, TRUE
    test ecx, ecx
    jz @@NextLine
    .if dInCodeBlock == FALSE
      mov pPrvWordStart, xax
      mov dPrvWordSize,  ecx
      invoke GetNextWord, addr [xax + xcx], TRUE
      test ecx, ecx
      jz @@NextLine
      SaveWordResult
      invoke StrCICompA, pWordStart, offset szMacro, dWordSize
      .if eax == 0
        inc dInCodeBlock
        mov dCodeBlockLineNumber, edi
        OCall xsi.WriteA, offset szDot, [xsi].Color.Notification, 0
        mov pCodeBlockName, $invoke(StrCNewA, pPrvWordStart, dPrvWordSize)
      .endif
      jmp @@NextLine
    .endif

    SaveWordResult
    ;Check the first word in the sentence
    mov xbx, offset MacroBlockList
    .while PSTRINGA ptr [xbx] != NULL
      invoke StrCICompA, PSTRINGA ptr [xbx], pWordStart, dWordSize
      .if eax == 0
        inc dMacroLevel
        jmp @@NextWord
      .endif
      add xbx, sizeof PSTRINGA
    .endw

    invoke StrCICompA, pWordStart, offset szEndm, dWordSize
    .if eax == 0
      dec dMacroLevel
      .if ZERO?
        EvaluateVarResult IDS_LOC_WARNING, IDS_LOCALS, Color.LocWarning
      .endif
    .endif

    invoke StrCICompA, pWordStart, offset szLocal, dWordSize
    .if eax == 0
      CalcNextWordPtr                                 ;xax -> next beginning word
      GetVariables
      jmp @@NextLine
    .endif

@@NextWord:
    .ifBitSet [xsi].dFlags, OATF_TEST_ANNOT
      invoke StrCCompA, pWordStart, offset szANNOTATION, dWordSize
      .if eax == 0
        HandleVarAnnotation
      .endif
    .endif

    CheckVarInSentence TRUE

@@NextLine:
    inc edi
    .break .if edi == [xsi].LineLengths.dCount
    SkipLineTerminator
  .until FALSE
  OCall VarNames::SortedStrCollectionA.Done
  EndMessage IDS_CHECK_LOC_READY
  mov eax, dFindings
MethodEnd
