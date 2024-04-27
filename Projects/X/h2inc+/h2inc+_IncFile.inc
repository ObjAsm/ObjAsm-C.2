; ==================================================================================================
; Title:    h2inc+_IncFile.inc
; Author:   G. Friedrich
; Version:  C.2.0
; Purpose:  ObjAsm support of h2inc+ IncFile objects.
; Notes:    See h2inc+.asm
; ==================================================================================================


; ==================================================================================================

if IMPLEMENT

PP_CMD_HANDLER_ENTRY struct
  pCmd      PSTRINGA ?
  pHandler  POINTER ?
PP_CMD_HANDLER_ENTRY ends
PPRE_PROC_CMD typedef ptr PP_CMD_HANDLER_ENTRY

.data

;Preprocessor command table
;Commands not listed here will be commented out
PreProcCmdHandlerTable label PP_CMD_HANDLER_ENTRY
  PP_CMD_HANDLER_ENTRY <$OfsCBStrA("define"),  offset PPCH_Define>
  PP_CMD_HANDLER_ENTRY <$OfsCBStrA("undef"),   offset PPCH_Undef>
  PP_CMD_HANDLER_ENTRY <$OfsCBStrA("include"), offset PPCH_Include>
  PP_CMD_HANDLER_ENTRY <$OfsCBStrA("error"),   offset PPCH_Error>
  PP_CMD_HANDLER_ENTRY <$OfsCBStrA("pragma"),  offset PPCH_Pragma>
  PP_CMD_HANDLER_ENTRY <$OfsCBStrA("if"),      offset PPCH_If>
  PP_CMD_HANDLER_ENTRY <$OfsCBStrA("elif"),    offset PPCH_ElIf>
  PP_CMD_HANDLER_ENTRY <$OfsCBStrA("else"),    offset PPCH_Else>
  PP_CMD_HANDLER_ENTRY <$OfsCBStrA("endif"),   offset PPCH_Endif>
  PP_CMD_HANDLER_ENTRY <$OfsCBStrA("ifdef"),   offset PPCH_Ifdef>
  PP_CMD_HANDLER_ENTRY <$OfsCBStrA("ifndef"),  offset PPCH_Ifndef>
  POINTER NULL

;Table used when IncFile.bSkipLogiPP == TRUE
PreProcCmdNPHandlerTable label PP_CMD_HANDLER_ENTRY
  PP_CMD_HANDLER_ENTRY <$OfsCBStrA("if"),      offset PPCH_IfNP>
  PP_CMD_HANDLER_ENTRY <$OfsCBStrA("elif"),    offset PPCH_ElIf>
  PP_CMD_HANDLER_ENTRY <$OfsCBStrA("else"),    offset PPCH_Else>
  PP_CMD_HANDLER_ENTRY <$OfsCBStrA("endif"),   offset PPCH_Endif>
  PP_CMD_HANDLER_ENTRY <$OfsCBStrA("ifdef"),   offset PPCH_IfNP>
  PP_CMD_HANDLER_ENTRY <$OfsCBStrA("ifndef"),  offset PPCH_IfNP>
  POINTER NULL

;Operator conversion for #if/#elif expressions
OP_CONV_ENTRY struct
  wOp     db 2 dup (?)
  pSubst  PSTRINGA ?
OP_CONV_ENTRY ends

OpConvTable label DWORD
  OP_CONV_ENTRY <{3Dh, 3Dh}, $OfsCBStrA(" eq ")>        ;"=="
  OP_CONV_ENTRY <{21h, 3Dh}, $OfsCBStrA(" ne ")>        ;"!="
  OP_CONV_ENTRY <{3Eh, 3Dh}, $OfsCBStrA(" ge ")>        ;">="
  OP_CONV_ENTRY <{3Ch, 3Dh}, $OfsCBStrA(" le ")>        ;"<="
  OP_CONV_ENTRY <{3Eh, 00h}, $OfsCBStrA(" gt ")>        ;">"
  OP_CONV_ENTRY <{3Ch, 00h}, $OfsCBStrA(" lt ")>        ;"<"
  OP_CONV_ENTRY <{26h, 26h}, $OfsCBStrA(" and ")>       ;"&&"
  OP_CONV_ENTRY <{7Ch, 7Ch}, $OfsCBStrA(" or ")>        ;"||"
  OP_CONV_ENTRY <{26h, 00h}, $OfsCBStrA(" and ")>       ;"&"
  OP_CONV_ENTRY <{7Ch, 00h}, $OfsCBStrA(" or ")>        ;"|"
  OP_CONV_ENTRY <{21h, 00h}, $OfsCBStrA(" not ")>       ;"!"
  OP_CONV_ENTRY <{3Ch, 3Ch}, $OfsCBStrA(" shl ")>       ;"<<"
  OP_CONV_ENTRY <{3Eh, 3Eh}, $OfsCBStrA(" shr ")>       ;">>"
OpConvTabEntries equ ($ - offset(OpConvTable)) / sizeof(OP_CONV_ENTRY)

.const

;Delimiters known by parser
bDelim  db ",;:()[]{}|*<>!~-+=/&#%^"      ;Excluded "?"   "\"?

;2-BYTE opcodes known by parser
w2CharOps dw ">>", "<<", "&&", "||", ">=", "<=", "==", "!=", "->", "::", "##", "++", "--", \
             "+=", "-=", "*=", "/=", "%=", "&=", "|=", "^=", "?:"

d3CharOps dd ">>=", "<<="

.code

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     IncFile.AddComment
; Purpose:    Store the comment for later output.
; Arguments:  Arg1 -> Comment string
; Return:     Nothing.

Method IncFile.AddComment, uses xsi, pCommentText:PSTRINGA
  SetObject xsi
  mov xdx, pCommentText
  inc xdx
  invoke StrCopyA, addr [[xsi].cComment + 1], xdx
  mov [[xsi].cComment], ';'
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     IncFile.CreateDefFile
; Purpose:    Create a new .def file.
; Arguments:  Arg1 -> FileName.
; Return:     eax = TRUE if succeeded, otherwise FALSE.

Method IncFile.CreateDefFile, uses xbx xdi xsi, pFileName:PSTRINGW
  local hFile:HANDLE, Result:DWORD, dBytesWritten:DWORD
  local cFile[MAX_PATH]:CHR, cText[512]:CHR

  SetObject xbx
  mov Result, FALSE

  .if [xbx].pDefs != NULL
    mov xdx, [xbx].pDefs
    .if [xdx].$Obj(List).dCount == 0
      mov xax, [xbx].pOwner
      .if [xax].$Obj(Application).Options.dWarningLevel > 2
        OCall [xbx].pOwner::Application.Print, $OfsCStr("No items for .DEF file", CRLF)
      .endif
      jmp @Exit
    .endif

    invoke StrCopyW, addr cFile, pFileName
    invoke StrSizeW, pFileName
    lea xcx, cFile
    .if (eax <= 10) || (CHR ptr [xcx + xax - 8] != '.')
      OCall [xbx].pOwner::Application.Print, $OfsCStr("Invalid .def file name", CRLF)
      jmp @Exit
    .endif
    mov pFileName, xcx
    FillStringW [xcx + xax - 6], <def>                  ;Replace extension

    invoke CreateFileW, pFileName,GENERIC_WRITE, FILE_SHARE_WRITE, NULL, CREATE_ALWAYS, \
                        FILE_ATTRIBUTE_ARCHIVE, 0
    .if xax != INVALID_HANDLE_VALUE
      mov hFile, xax
      invoke WriteFile, hFile, $OfsCStrA("LIBRARY", LF), 7 + 2, addr dBytesWritten, NULL
      invoke WriteFile, hFile, $OfsCStrA("EXPORTS", LF), 7 + 2, addr dBytesWritten, NULL
      xor esi, esi
      .while TRUE
        mov xcx, [xbx].pDefs
        .break .if esi == [xcx].$Obj(List).dCount
        OCall xcx::List.ItemAt, esi
        lea xdi, cText
        WriteF xdi, " \`¦SA\`\n)", PSTRINGA ptr [xax]
        lea xax, cText
        sub xdi, xax
        invoke WriteFile, hFile, addr cText, edi, addr dBytesWritten, NULL
        inc esi
      .endw
      invoke CloseHandle, hFile
      mov Result, TRUE
    .else
      OCall [xbx].pOwner::Application.Print, $OfsCStr("Can't create .def file", CRLF)
    .endif
  .endif
@Exit:
  mov eax, Result
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     IncFile.Done
; Purpose:    Destructor
; Arguments:  None.
; Return:     Nothing.

Method IncFile.Done, uses xbx
  SetObject xbx
  DbgPrintF , "Free StmBuffer1 ¦HX for ¦SU", [xbx].pStmBuffer1, [xbx].pHeaderFileName
  invoke VirtualFree, [xbx].pStmBuffer2, 0, MEM_RELEASE
  DbgPrintF , "Free StmBuffer2 ¦HX for ¦SU", [xbx].pStmBuffer2, [xbx].pHeaderFileName
  invoke VirtualFree, [xbx].pStmBuffer1, 0, MEM_RELEASE

  invoke StrDisposeW, [xbx].pHeaderFilePath
  invoke StrDisposeW, [xbx].pHeaderFileName

  .if [xbx].pDefs != NULL
    Destroy [xbx].pDefs
    mov [xbx].pDefs, NULL
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     IncFile.GetNextTokenC
; Purpose:    Return the next C token from input stream. Comments are handled automatically.
; Arguments:  None.
; Return:     xax -> Token or NULL if EOF is reached. ZERO flag set if xax == NULL.

Method IncFile.GetNextTokenC, uses xbx xdi
  SetObject xbx
  
  .if [xbx].bEOF != FALSE                               ;Don't cross EOF
    if DEBUGGING
      int 3
    endif
    xor eax, eax
    ret
  .endif
  .if [xbx].bUsePrevToken != FALSE
    mov [xbx].bUsePrevToken, FALSE                      ;Reset the flag
    mov xax, [xbx].pPrevToken
  .else
@TryAgain:
    mov xdi, [xbx].pStmInpPos
    mov ecx, -1
    mov al, 0
    repnz scasb
    not ecx                                             ;neg????
    dec ecx                                             ;ecx = character count
    .if ecx == 0
      xor eax, eax                                      ;Return NULL, ZF set
      jmp @Exit
    .endif
    mov xax, xdi
    xchg xax, [xbx].pStmInpPos
    .if DCHRA ptr [xax] == PCT_EOL                      ;Check for EOL
      inc [xbx].dLineNumber
      mov [xbx].bNewLine, TRUE                          ;Set StreamIn new line maker
      .if [xbx].dStmOutEOL != FALSE                     ;Check Stream out EOL
        OCall xbx::IncFile.StmWriteComment
      .endif
      jmp @TryAgain                                     ;Take the next Token
    .endif

    .if CHRA ptr [xax] == "\"                           ;Check for C continuation => combine lines
      inc [xbx].dLineNumber                                ;  This should happen while tokenizing
      mov [xbx].bNewLine, TRUE                          ;Set StreamIn new line maker
      .if [xbx].dStmOutEOL != FALSE                     ;Check Stream out EOL
        OCall xbx::IncFile.StmWriteComment
      .endif
      jmp @TryAgain                                     ;Take the next Token
    .endif

    .if DCHRA ptr [xax] == PCT_COMMENT
      .if [xbx].bSkipScanPP == 0
        OCall xbx::IncFile.AddComment, xax
      .endif
      jmp @TryAgain
    .endif

    ;Each time a new line is started from input stream, check if we have a PP command
    .if [xbx].bNewLine != FALSE && CHRA ptr [xax] == '#'
      OCall xbx::IncFile.StmWriteComment
      invoke RenderPP
      jmp @TryAgain
    .endif
  .endif
  test xax, xax
  setz [xbx].bEOF

@Exit:
  mov [xbx].bNewLine, FALSE
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     IncFile.GetNextTokenPP
; Purpose:    Returns the next token from within a PP command. Comments are handled automatically.
; Arguments:  None.
; Return:     xax -> Token or NULL if token = PCT_EOL or EOF reached. ZERO flag set if xax == NULL.

Method IncFile.GetNextTokenPP, uses xbx xdi
  SetObject xbx
  mov xdi, [xbx].pStmInpPos
@NextToken:
  mov ecx, -1
  mov al, 0                                           ;ZTC
  repnz scasb
  not ecx
  xor eax, eax                                        ;Return NULL
  dec ecx                                             ;ecx = character count
  mov [xbx].bNewLine, FALSE
  .if ecx != 0
    mov xax, xdi
    xchg xax, [xbx].pStmInpPos
    .if CHRA ptr [xax] == PCT_EOL
      inc [xbx].dLineNumber
      mov [xbx].bNewLine, TRUE
      xor eax, eax                                    ;Return NULL
    .else
      .if CHRA ptr [xax] == PCT_WEAKEOL
        inc [xbx].dLineNumber
        jmp @NextToken
      .endif
      .if CHRA ptr [xax] == PCT_IGNORE
        jmp @NextToken
      .endif
      .if CHRA ptr [xax] == PCT_COMMENT
        OCall xbx::IncFile.AddComment, xax
        jmp @NextToken
      .endif
    .endif
  .endif
  test xax, xax
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     IncFile.InputStatusLoad
; Purpose:    Load the input status from an INP_STAT structure.
; Arguments:  Arg1: -> INP_STAT structure.
; Return:     Nothing.

Method IncFile.InputStatusLoad, uses xbx xdi xsi, pStatus:P_INP_STAT
  SetObject xbx
  mov xsi, pStatus
  mov xax, [xsi].INP_STAT.pIn
  mov ecx, [xsi].INP_STAT.dLineNumber
  mov dl, [xsi].INP_STAT.bNewLine
  mov dh, [xsi].INP_STAT.bCondIfLevel
  mov [xbx].pStmInpPos, xax
  mov [xbx].dLineNumber, ecx
  mov [xbx].bNewLine, dl
  mov [xbx].bCondIfLevel, dh
  mov dl, [xsi].INP_STAT.bSkipC
  mov dh, [xsi].INP_STAT.bSkipScanPP
  mov [xbx].bSkipC, dl
  mov [xbx].bSkipScanPP, dh

  mov xax, xsi
  lea xdi, [xbx].bCondElseLevel
  lea xsi, [xax].INP_STAT.bCondElseLevel
  mov ecx, MAX_COND_LEVEL/sizeof(DWORD)
  rep movsd

  lea xdi, [xbx].bCondResult
  lea xsi, [xax].INP_STAT.bCondResult
  mov ecx, MAX_COND_LEVEL/sizeof(DWORD)
  rep movsd

  lea xdi, [xbx].bCondHistory
  lea xsi, [xax].INP_STAT.bCondHistory
  mov ecx, MAX_COND_LEVEL/sizeof(DWORD)
  rep movsd
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     IncFile.InputStatusSave
; Purpose:    Save the input status in an INP_STAT structure.
; Arguments:  Arg1: -> INP_STAT structure.
; Return:     Nothing.

Method IncFile.InputStatusSave, uses xbx xdi xsi, pStatus:P_INP_STAT
  SetObject xbx
  mov xsi, pStatus
  mov xax, [xbx].pStmInpPos
  mov ecx, [xbx].dLineNumber
  mov dl, [xbx].bNewLine
  mov dh, [xbx].bCondIfLevel
  mov [xsi].INP_STAT.pIn, xax
  mov [xsi].INP_STAT.dLineNumber, ecx
  mov [xsi].INP_STAT.bNewLine, dl
  mov [xsi].INP_STAT.bCondIfLevel, dh
  mov dl, [xbx].bSkipC
  mov dh, [xbx].bSkipScanPP
  mov [xsi].INP_STAT.bSkipC, dl
  mov [xsi].INP_STAT.bSkipScanPP, dh

  mov xax, xsi
  lea xdi, [xax].INP_STAT.bCondElseLevel
  lea xsi, [xbx].bCondElseLevel
  mov ecx, MAX_COND_LEVEL/sizeof(DWORD)
  rep movsd

  lea xdi, [xax].INP_STAT.bCondResult
  lea xsi, [xbx].bCondResult
  mov ecx, MAX_COND_LEVEL/sizeof(DWORD)
  rep movsd

  lea xdi, [xax].INP_STAT.bCondHistory
  lea xsi, [xbx].bCondHistory
  mov ecx, MAX_COND_LEVEL/sizeof(DWORD)
  rep movsd
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     IncFile.PeekNextTokenC
; Purpose:    Peek the next C token.
; Arguments:  None.
; Return:     xax -> Token. ZERO flag set if xax == NULL.

Method IncFile.PeekNextTokenC, uses xbx
  local InpStat:INP_STAT, pToken:PTOKEN

  SetObject xbx
  OCall xbx::IncFile.InputStatusSave, addr InpStat
  inc [xbx].bSkipScanPP
  OCall xbx::IncFile.GetNextTokenC
  mov pToken, xax
  dec [xbx].bSkipScanPP
  OCall xbx::IncFile.InputStatusLoad, addr InpStat
  mov xax, pToken
  test xax, xax
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     IncFile.Init
; Purpose:    Instance initialization.
; Arguments:  Arg1 -> Full Path and FileName of the h-file.
;             Arg2 -> Parent IncFile object that created (included) this instance or NULL.
; Return:     eax = TRUE if succeeded, otherwise FALSE.

.data?
dStmBufSize DWORD ?
.code

Method IncFile.Init, uses xbx xdi xsi, pOwner:POINTER, pFileName:PSTRINGW, pParent:$ObjPtr(IncFile)
  local hFile:HANDLE, dFileSize:DWORD, dBytesRead:DWORD, dSysError:DWORD
  local cFullFileName[MAX_PATH]:CHRW, cFullIncPathName[MAX_PATH]:CHRW, cMessage[1024]:CHR
  local pName:PSTRINGW;, dStmBufSize:DWORD

  SetObject xbx
  ACall xbx::IncFile.Init, pOwner

  mov xdi, pOwner
  .if [xdi].$Obj(Application).Options.bCreateDefs != FALSE
    mov [xbx].pDefs, $New(List)
    OCall xax::List.Init, NULL, 100, 10, CF_SNGL
  .endif

  ;Extract the FileName
  invoke GetFullPathNameW, pFileName, lengthof(cFullFileName), addr cFullFileName, addr pName
  mov [xbx].pHeaderFilePath, $invoke(StrNewW, addr cFullFileName)
  m2m [xbx].pHeaderFileName, $invoke(StrNewW, pName)

  ;Try to open the file
  invoke CreateFileW, addr cFullFileName, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, 0, 0
  .if xax == INVALID_HANDLE_VALUE
    invoke GetLastError
    .if eax == ERROR_FILE_NOT_FOUND
      .if [xdi].$Obj(Application).Options.pIncludeDirs != NULL
        ;Check if the file exist in the include directory
        invoke StrECopyW, addr cFullIncPathName, [xdi].$Obj(Application).Options.pIncludeDirs
        lea xdx, pName
        invoke StrECopyW, xax, xdx
        invoke CreateFileW, addr cFullIncPathName, GENERIC_READ, FILE_SHARE_READ, NULL, \
                            OPEN_EXISTING, 0, 0
        .if xax != INVALID_HANDLE_VALUE
          lea xcx, cFullIncPathName
          mov pFileName, xcx
          jmp @FileExist
        .endif
        invoke GetLastError
      .endif
    .endif
    mov dSysError, eax

    lea xdi, cMessage
    WriteF xdi, "Warning: opening file \`¦SU\`", pFileName
    .if pParent != NULL
      mov xsi, pParent
      WriteF xdi, " included from file \`¦SU\` at line ¦UD failed", \
             [xsi].$Obj(IncFile).pHeaderFileName, [xsi].$Obj(IncFile).dLineNumber
    .endif
    WriteF xdi, " [Error ¦UD = ", dSysError
    lea xax, cMessage
    sub xax, xdi
    add xax, sizeof(cMessage)
    invoke FormatMessage, FORMAT_MESSAGE_FROM_SYSTEM or FORMAT_MESSAGE_IGNORE_INSERTS, \
                          NULL, dSysError, 0, xdi, eax, NULL
    .if eax == 0
      lea xdi, [xdi - sizeof(CHR)*3]                    ;Remove " = "
    .else
      lea xdi, [xdi + sizeof(CHR)*xax - sizeof(CHR)*2]  ;Remove ending CRLF
    .endif
    WriteF xdi, "]"
    OCall [xbx].pOwner::Application.ShowInfo, VERBOSITY_DEAFENING, addr cMessage

    ;Build a list on a separate window
    DbgStrW pFileName,, "Files not found"
    xor eax, eax
    jmp @@EOM
  .endif

@FileExist:
  mov hFile, xax
  invoke GetFileTime, hFile, addr [xbx].CreationFileTime, NULL, addr [xbx].LastWriteFileTime
  invoke GetFileSize, hFile, NULL
  mov dFileSize, eax
  mov ecx, eax
if ADD_50_PERCENT
  shr ecx, 1          ;add 50% to file size for buffer size
endif
  add eax, ecx        ;add 100% to file size for buffer size

  ;Allocate buffers
  mov dStmBufSize, eax
  invoke VirtualAlloc, NULL, dStmBufSize, MEM_RESERVE or MEM_COMMIT, PAGE_READWRITE
  .if xax != NULL
    mov [xbx].pStmBuffer1, xax
    invoke VirtualAlloc, NULL, dStmBufSize, MEM_RESERVE or MEM_COMMIT, PAGE_READWRITE
    mov [xbx].pStmBuffer2, xax
  .endif
  .if xax == NULL
    OCall xdi::Application.ShowError, $OfsCStr("IncFile.Init - out of memory")
    mov $ObjTmpl(Application).bTerminate, TRUE
    xor eax, eax
    jmp @@EOM
  .endif
  lea xsi, cMessage
  WriteF xsi, "Allocating buffers for \`¦SU\`\n", [xbx].pHeaderFileName
  WriteF xsi, "StmBuffer1 at memory ¦HXh\n", [xbx].pStmBuffer1
  WriteF xsi, "StmBuffer2 at memory ¦HXh", [xbx].pStmBuffer2
  OCall [xbx].pOwner::Application.ShowInfo, VERBOSITY_DEAFENING, addr cMessage

  ;Read the header file content
  invoke ReadFile, hFile, [xbx].pStmBuffer2, dFileSize, addr dBytesRead, NULL
  invoke CloseHandle, hFile

  ;Setup the buffers
  mov eax, dBytesRead
  mov xcx, [xbx].pStmBuffer2
  mov CHRA ptr [xcx + xax], 0
  mov [xbx].pStmInpPos, xcx
  mov xcx, [xbx].pStmBuffer1
  mov CHRA ptr [xcx], 0
  mov [xbx].pStmOutPos, xcx
  mov xax, pParent
  mov [xbx].pParent, xax
  mov [xbx].bNewLine, TRUE

  mov eax, TRUE
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     IncFile.ParseHeaderFile
; Purpose:    Input is C header source, output is tokenized, that is:
;              + Each token is an ASCII string.
;              + Numeric literals (numbers) are converted to ASM format on the fly.
;              + Comments are marked as such.
;              Example:
;                Input stream:  "#define VAR1 0xA+2"\r\n
;                Output stream: "#",0,"define",0,"VAR1",0,"0Ah",0,"+",0,"2",0,PCT_EOL,0
; Arguments:  None.
; Return:     xax -> End of Stream.

Method IncFile.ParseHeaderFile, uses xbx xdi xsi
  local dPPLineContinuation:DWORD

  SetObject xbx
  mov [xbx].dLineNumber, 1                              ;Reset line counting
  mov dPPLineContinuation, FALSE
  .repeat
    ;Parse a line
    ;  1. Skip any white spaces at the beginning
    ;  2. Check '\' for preprocessor lines (weak EOL)
    ;  3. Call ParseHeaderLine
    ;  4. Adjust pStmInpPos

    ;Skip SPC and TAB chars
    mov xsi, [xbx].pStmInpPos
    .while (CHRA ptr [xsi] == SPC) || (CHRA ptr [xsi] == TAB)
      inc xsi
    .endw

    ;Move to the EOL and replace CRLF by 0
    mov xdx, xsi                                        ;xdx -> effective line start
    xor edi, edi
    .while TRUE
      .break .if CHRA ptr [xsi] == 0
      lodsb
      .if (al == CR) || (al == LF)
        mov CHRA ptr [xsi - 1], 0                       ;Replace by 0
        .if xdi == NULL
          lea xdi, [xsi - 1]                            ;xdi -> first occurence = EOL
        .endif
        .break .if al == LF                             ;Should always be present
      .endif
    .endw
    .if xsi != [xbx].pStmInpPos
      inc [xbx].dLineNumber
    .endif

    .if CHRA ptr [xdx] == '#' || dPPLineContinuation != FALSE   ;PP line or continuation
      mov dPPLineContinuation, FALSE
      mov xcx, xdi                                      ;xdi -> EOL
      .while xcx >= xdx                                 ;xdx -> Line start
        mov al, [xcx]
        .if al == '\'                                   ;Continuation char?
          .while CHRA ptr [xcx]                         ;Fill with spaces up to the EOL
            mov CHRA ptr [xcx], SPC
            inc xcx
          .endw
          mov dPPLineContinuation, TRUE
          .break
        .endif
        .break .if al > SPC                             ;Continuation char is not the last char
        dec xcx
      .endw
    .endif

    OCall xbx::IncFile.ParseHeaderLine, xdx, dPPLineContinuation

    mov xax, xsi
    sub xax, [xbx].pStmInpPos                           ;eax = # of processed chars
    mov [xbx].pStmInpPos, xsi

  .until ZERO?

  mov xax, [xbx].pStmOutPos
  mov CHRA ptr [xax], 0                                 ;Set ZTC at the end of the buffer
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     IncFile.ParseHeaderLine
; Purpose:    Process a source text line
; Arguments:  Arg1 -> Text line into input buffer.
;             Arg2: Weak Line End flag.
; Return:     Nothing.

Method IncFile.ParseHeaderLine, uses xbx xdi xsi, pLine:PSTRINGA, bWeak:DWORD
  local bIsPreProc:DWORD, bIsDefine:DWORD, dTokenCounter:DWORD

  SetObject xbx
  mov bIsPreProc, FALSE
  mov bIsDefine, FALSE
  mov xsi, pLine
  .if CHRA ptr [xsi] == '#'
    mov bIsPreProc, TRUE
  .endif
  OCall xbx.SkipComments, xsi
  mov xdi, [xbx].pStmOutPos
  mov dTokenCounter, 0
  .while TRUE
    mov al, [xsi]
    .break .if al == 0                                  ;EOL?
    mov xdx, xdi                                        ;xdx -> token
    .if al == '/' && CHRA ptr [xsi + 1] == '/'
      .if $ObjTmpl(Application).Options.bIncludeComments != FALSE
        mov al, PCT_COMMENT                             ;Set Marker
        stosb
        invoke StrECopyA, xdi, xsi
        lea xdi, [xax + 1]                              ;xdi -> ZTC + 1
      .endif
      .break
    .endif
    ;Get token
    .while TRUE
      .break .if CHRA ptr [xsi] == 0
      lodsb
      .break .if al == SPC || al == TAB
      .if xdi == xdx && al == '"'
        invoke GetStringLiteral
        .break
      .endif
      .if xdi == xdx && al == 'L' && CHRA ptr [xsi] == '"'
        stosb
        mov al, '('
        stosb
        lodsb
        invoke GetStringLiteral
        mov al, ')'
        stosb
        .break
      .endif

      .if xdi == xdx && al >= '0' && al <= '9'
        dec xsi
        invoke ConvertNumber                          ;Preserves ecx, edx
        .break
      .endif

      ;Check if content of al is a delimiter
      push xdi
      lea xdi, bDelim
      mov ecx, sizeof(bDelim)
      repnz scasb
      pop xdi
      .if ZERO?                                       ;Delimiter found
        .if xdi != xdx
          .if al == '(' && bIsDefine != FALSE && dTokenCounter == 2
            mov al, 0
            stosb
            mov ax, PCT_MACRO
            stosb
          .endif
          dec xsi
        .else
          stosb
          mov ah, [xsi]

          ;check if context of ax is a 2 char operand
          push xdi
          xchg al, ah
          lea xdi, w2CharOps
          mov ecx, sizeof(w2CharOps)/sizeof(WORD)
          repnz scasw
          pop xdi
          .if ZERO?
            movsb
          .endif
        .endif
        .break
      .endif
      stosb
    .endw

    .if xdx != xdi
      mov CHRA ptr [xdi], 0
      inc xdi
      inc dTokenCounter
      .if dTokenCounter == 2 && bIsPreProc != FALSE
        .if $DoesTextMatchA?([xdx], <define>)
          mov bIsDefine, TRUE
        .endif
      .endif
    .endif
  .endw

  .if bWeak != FALSE
    mov ax, PCT_WEAKEOL
  .else
    mov ax, PCT_EOL
  .endif
  stosw
  mov [xbx].pStmOutPos, xdi
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     IncFile.Render
; Purpose:    Start translation of header file into an MASM include file.
; Arguments:  None.
; Return:     eax = 0 if error occured.

Method IncFile.Render, uses xbx xdi xsi
  local cMessage[1024]:CHRA
;  local dBytesWritten:DWORD

  SetObject xbx

  ;Initial message
  lea xdi, cMessage
  WriteF xdi, "Analysis of \`¦SU\` started", [xbx].pHeaderFileName
  OCall [xbx].pOwner::Application.ShowInfo, VERBOSITY_DEAFENING, addr cMessage

  ;Prepare buffers
  mrm [xbx].pStmInpPos, [xbx].pStmBuffer1, xdi

;  if DEBUGGING
;    invoke CreateFileW, $OfsCStrA("~parsed.tmp"), GENERIC_WRITE, FILE_SHARE_WRITE, NULL, \
;                        CREATE_ALWAYS, FILE_ATTRIBUTE_ARCHIVE, 0
;    .if xax != INVALID_HANDLE_VALUE
;      mov xsi, xax
;      mov xcx, [xbx].pStmOutPos
;      sub xcx, xdi
;      invoke WriteFile, xsi, xdi, xcx, addr dBytesWritten, NULL
;      invoke CloseHandle, xsi
;    .endif
;  endif

  mrm [xbx].pStmOutPos, [xbx].pStmBuffer2, xdi
  mov CHRA ptr [xdi], 0
  if DEBUGGING
    invoke MemZero, xdi, dStmBufSize
  endif 

  ;Reset volatile data lists
  lea xsi, VolatilConvTable
  .while POINTER ptr [xsi] != NULL
    OCall [xsi].CONV_TAB_ENTRY.pList::List.DeleteAll
    add xsi, sizeof(CONV_TAB_ENTRY)
  .endw

  ;Start translation
  invoke RenderC                                         ;xbx is passed implicitly

  ;Check if level
  .if [xbx].bCondIfLevel != 0
    OCall xbx::IncFile.ShowError, $OfsCStr("unmatching if/endif")
  .endif

  ;Final message
  lea xdi, cMessage
  WriteF xdi, "Analysis of \`¦SU\` completed", [xbx].pHeaderFileName
  OCall [xbx].pOwner::Application.ShowInfo, VERBOSITY_DEAFENING, addr cMessage
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     IncFile.Save
; Purpose:    Write output buffer to file.
; Arguments:  Arg1 -> Full Path and FileName of the inc-file.
; Return:     eax = TRUE is succeded, otherwise FALSE.

Method IncFile.Save, uses xbx xdi xsi, pFullFileName:PSTRINGW
  local Result:DWORD, hFile:HANDLE, dBytesWritten:DWORD, cMessage[1024]:CHR
  local cIncHeader[2024]:CHRA, dStmBufferContent2:DWORD
  local CreationSysTime:SYSTEMTIME, LastWriteSysTime:SYSTEMTIME

  SetObject xbx
  mov Result, FALSE
  invoke StrSizeA, [xbx].pStmBuffer2
  mov dStmBufferContent2, eax
  invoke CreateFileW, pFullFileName, GENERIC_WRITE, FILE_SHARE_WRITE, NULL, \
                      CREATE_ALWAYS, FILE_ATTRIBUTE_ARCHIVE, 0
  .if xax != INVALID_HANDLE_VALUE
    mov hFile, xax

    ;Create the inc-file header
    lea xdi, cIncHeader
    mov xsi, [xbx].pOwner
    WriteFA xdi, ";Include file created by h2inc+ version ¦SA on (UTC) ¦SA\n", \
                 $OfsCStrA(@CatStr(<!">,<%VERSION>,<!">)), \
                 addr [xsi].$Obj(Application).cIncCreationTime
    WriteFA xdi, ";¦SA\n", $OfsCStrA(@CatStr(<!">,<%COPYRIGHT>,<!">))

    invoke FileTimeToSystemTime, addr [xbx].CreationFileTime, addr CreationSysTime
    invoke FileTimeToSystemTime, addr [xbx].LastWriteFileTime, addr LastWriteSysTime
    WriteFA xdi, ";Source file: ¦SU\¦SU\n", [xbx].pHeaderFilePath, [xbx].pHeaderFileName
    WriteFA xdi, ";             Created on (UTC) ¦BN¦UW/¦BN¦UW/¦BN¦UW ¦BN¦UW:¦BN¦UW:¦BN¦UW\n", \
                 <<<PrependZerosA(CreationSysTime.wDay, 2)>>>,     CreationSysTime.wDay, \
                 <<<PrependZerosA(CreationSysTime.wMonth, 2)>>>,   CreationSysTime.wMonth, \
                 <<<PrependZerosA(CreationSysTime.wYear, 4)>>>,    CreationSysTime.wYear, \
                 <<<PrependZerosA(CreationSysTime.wHour, 2)>>>,    CreationSysTime.wHour, \
                 <<<PrependZerosA(CreationSysTime.wMinute, 2)>>>,  CreationSysTime.wMinute, \
                 <<<PrependZerosA(CreationSysTime.wSecond, 2)>>>,  CreationSysTime.wSecond
    WriteFA xdi, ";             Last modified on (UTC) ¦BN¦UW/¦BN¦UW/¦BN¦UW ¦BN¦UW:¦BN¦UW:¦BN¦UW\n", \
                 <<<PrependZerosA(LastWriteSysTime.wDay, 2)>>>,    LastWriteSysTime.wDay, \
                 <<<PrependZerosA(LastWriteSysTime.wMonth, 2)>>>,  LastWriteSysTime.wMonth, \
                 <<<PrependZerosA(LastWriteSysTime.wYear, 4)>>>,   LastWriteSysTime.wYear, \
                 <<<PrependZerosA(LastWriteSysTime.wHour, 2)>>>,   LastWriteSysTime.wHour, \
                 <<<PrependZerosA(LastWriteSysTime.wMinute, 2)>>>, LastWriteSysTime.wMinute, \
                 <<<PrependZerosA(LastWriteSysTime.wSecond, 2)>>>, LastWriteSysTime.wSecond

    .if [xbx].dErrorCount != 0 || [xbx].dWarningCount != 0
      WriteFA xdi, ";Errors = ¦UD\n", [xbx].dErrorCount
      WriteFA xdi, ";Warnings = ¦UD\n", [xbx].dWarningCount
    .endif
    WriteFA xdi, "\n"

    ;Write the inc-file header to file
    lea xsi, cIncHeader
    sub xsi, xdi
    neg esi
    invoke WriteFile, hFile, addr cIncHeader, esi, addr dBytesWritten, NULL

    ;Write the inc-file content to file
    invoke WriteFile, hFile, [xbx].pStmBuffer2, dStmBufferContent2, addr dBytesWritten, NULL
    mov eax, dBytesWritten
    .if eax == dStmBufferContent2
      mov Result, TRUE
    .else
      invoke GetLastError
      mov esi, eax
      lea xdi, cMessage
      WriteF xdi, "saving file \`¦SU\`", pFullFileName
      OCall xbx.ShowSysError, addr cMessage, esi
    .endif

    ;Close the inc-file
    invoke CloseHandle, hFile
  .else
    invoke GetLastError
    mov esi, eax
    lea xdi, cMessage
    WriteF xdi, "creating file \`¦SU\`", pFullFileName
    OCall xbx.ShowSysError, addr cMessage, esi
  .endif
  mov eax, Result
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     IncFile.SkipComments
; Purpose:    Skip comments "/* ... */" in a line
; Arguments:  Arg1: -> Line
; Return:     None.

Method IncFile.SkipComments, uses xbx xdi xsi, pLine:PSTRINGA
  SetObject xbx
  .if $ObjTmpl(Application).Options.bIncludeComments != FALSE
    mov xdi, [xbx].pStmOutPos
    mov al, PCT_COMMENT
    stosb
  .endif
  mov xsi, pLine
  mov al, 0
  .while TRUE
    mov ah, al
    lodsb
    .break .if al == 0
    .break .if ax == "//" && [xbx].bComment == FALSE
    .if [xbx].bComment != 0 && ax == "*/"
      mov DCHRA ptr [xsi - 2], 2020h
      mov [xbx].bComment, FALSE
    .endif
    .if ax == '/*' && [xbx].bComment == FALSE
      mov [xbx].bComment, TRUE
      mov DCHRA ptr [xsi - 2], 2020h
    .endif
    .if [xbx].bComment != FALSE
      .if $ObjTmpl(Application).Options.bIncludeComments != FALSE
        stosb
      .endif
      mov CHRA ptr [xsi - 1], SPC
    .endif
  .endw
  .if $ObjTmpl(Application).Options.bIncludeComments != FALSE
    .if CHRA ptr [xdi - 1] == PCT_COMMENT
      mov CHRA ptr [xdi - 1], 0
    .else
      mov al, 0
      stosb
      mov [xbx].pStmOutPos, xdi
    .endif
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     IncFile.StmCopyRestOfPPLine
; Purpose:    copy rest of line to the output stream.
; Arguments:  None.
; Return:     eax = TRUE if succeeded, otherwise FALSE.

Method IncFile.StmCopyRestOfPPLine
  local pToken:PTOKEN

  .while TRUE
    OCall pSelf::IncFile.GetNextTokenPP
    .break .if ZERO?
    mov pToken, xax
    OCall pSelf::IncFile.StmWriteChar, " "
    OCall pSelf::IncFile.StmWrite, pToken
  .endw
  OCall pSelf::IncFile.StmWriteComment
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     IncFile.StmSkipRestOfPPLine
; Purpose:    Skip the rest of line.
; Arguments:  None.
; Return:     eax = TRUE if succeeded, otherwise FALSE.

Method IncFile.StmSkipRestOfPPLine
  SkipPPLine
  OCall pSelf::IncFile.StmWriteComment
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     IncFile.StmDeleteLastSpace
; Purpose:    Deletes last space from output stream.
; Arguments:  None.
; Return:     eax = TRUE if succeeded, otherwise FALSE.

Method IncFile.StmDeleteLastSpace
  SetObject xcx
  mov xax, [xcx].pStmOutPos
  .if CHRA ptr [xax - 1] == " "
    mov CHRA ptr [xax - 1], 0
    dec [xcx].pStmOutPos
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     IncFile.StmWrite
; Purpose:    Write a string to the output stream. Indentation is implemented here.
; Arguments:  Arg1 -> Text.
; Return:     xax -> current StreamOut position.

Method IncFile.StmWrite, uses xbx, pText:PSTRINGA
  SetObject xbx
  .if [xbx].dStmOutEOL != FALSE
    mov [xbx].dStmOutEOL, FALSE
    OCall xbx::IncFile.StmWriteIndent
  .endif
  invoke StrECopyA, [xbx].pStmOutPos, pText
  mov [xbx].pStmOutPos, xax
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     IncFile.StmWriteComment
; Purpose:    Writes the current comments to the output stream.
; Arguments:  None.
; Return:     Nothing.

Method IncFile.StmWriteComment, uses xsi
  SetObject xsi
  xor eax, eax
  mov xcx, [xsi].pOwner
  .if [xcx].$Obj(Application).Options.bIncludeComments != FALSE && CHRA ptr [[xsi].cComment + 1] != 0
    OCall xsi::IncFile.StmWrite, addr [xsi].cComment
    mov CHRA ptr [[xsi].cComment + 1], 0                 ;Set ZTC after ";"
    OCall xbx::IncFile.StmWriteEOL
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     IncFile.StmWriteChar
; Purpose:    Write a character to the output stream.
; Arguments:  Arg1: ANSI Character.
; Return:     xax -> current StreamOut position.

Method IncFile.StmWriteChar, uses xbx, bChar:CHRA
  SetObject xbx
  .if [xbx].dStmOutEOL != FALSE
    mov [xbx].dStmOutEOL, FALSE
    OCall xbx::IncFile.StmWriteIndent
  .endif
  mov xax, [xbx].pStmOutPos
  movzx cx, bChar
  mov [xax], cx                                       ;Write also a ZTC
  inc [xbx].pStmOutPos
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     IncFile.StmWriteError
; Purpose:    Write an error line to the output stream.
; Arguments:  None.
; Return:     Nothing.

Method IncFile.StmWriteError, uses xbx
  SetObject xbx
  OCall xbx.StmWrite, $OfsCStrA(CRLF, " ********* ERROR ********* ")
  OCall xbx.StmWriteEOL
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     IncFile.StmWriteF
; Purpose:    Write a formated string to the output stream.
; Arguments:  Arg1: -> Format.
;             Arg2: -> Arguments.
; Return:     xax -> current StreamOut position.

Method IncFile.StmWriteF, uses xbx, pFormat:PSTRINGA, Args:vararg
  SetObject xbx
  .if [xbx].dStmOutEOL != FALSE
    mov [xbx].dStmOutEOL, FALSE
    OCall xbx::IncFile.StmWriteIndent
  .endif
  invoke wvsprintfA, [xbx].pStmOutPos, pFormat, addr Args ;-> Arguments
  add [xbx].pStmOutPos, xax
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     IncFile.StmWriteEOL
; Purpose:    Write a <CRLF> sequence (End of Line) to the output stream.
; Arguments:  None.
; Return:     xax -> current StreamOut position.

Method IncFile.StmWriteEOL, uses xbx
  SetObject xbx
  .if [xbx].dStmOutEOL != FALSE
    mov [xbx].dStmOutEOL, FALSE
    OCall xbx::IncFile.StmWriteIndent
  .endif
  invoke StrECopyA, [xbx].pStmOutPos, $OfsCStrA(CRLF)
  mov [xbx].pStmOutPos, xax
  mov [xbx].dStmOutEOL, TRUE
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     IncFile.StmWriteIndent
; Purpose:    Write code indentation
; Arguments:  None.
; Return:     Nothing.

Method IncFile.StmWriteIndent, uses xbx xsi
  SetObject xbx
  mov esi, [xbx].$Obj(IncFile).dIndentation
  .if SDWORD ptr esi < 0                        ;Just in case something goes wrong
    mov [xbx].$Obj(IncFile).dIndentation, 0
  .else
    shl esi, 1
    .while !ZERO?
      OCall xbx::IncFile.StmWriteChar, SPC
      dec esi
    .endw
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     IncFile.ShowError
; Purpose:    Shows an error condition.
; Arguments:  Arg1: -> Format String.
;             Arg2-n: Format arguments
; Return:     Nothing.

Method IncFile.ShowError, uses xbx xdi, pFormat:PSTRING, Args:vararg
  local cMessage[1024]:CHR

  SetObject xbx
  inc [xbx].dErrorCount
  lea xdi, cMessage
  WriteF xdi, "¦SU(¦UD) - Error = ", [xbx].pHeaderFileName, [xbx].dLineNumber
  invoke wsprintf, xdi, pFormat, addr Args
  OCall [xbx].pOwner::Application.ShowError, addr cMessage
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     IncFile.ShowSysError
; Purpose:    Shows a system error condition.
; Arguments:  Arg1: -> Info String.
;             Arg2: Error Code.
; Return:     Nothing.

Method IncFile.ShowSysError, uses xbx xdi, pInfo:PSTRING, dErrorCode:DWORD
  local cMessage[1024]:CHR

  SetObject xbx
  lea xdi, cMessage
  .if pInfo != NULL
    WriteF xdi, "¦ST ", pInfo
  .endif
  WriteF xdi, "[Error ¦UD = ", dErrorCode
  lea xax, cMessage
  sub xax, xdi
  add xax, sizeof(cMessage)
  invoke FormatMessage, FORMAT_MESSAGE_FROM_SYSTEM, NULL, dErrorCode, 0, xdi, eax, 0
  .if eax == 0
    lea xdi, [xdi - sizeof(CHR)*3]                     ;Remove " = "
  .else
    lea xdi, [xdi + sizeof(CHR)*xax - sizeof(CHR)*2]   ;Remove ending CRLF
  .endif
  WriteF xdi, "]"

  OCall [xbx].pOwner::Application.ShowError, addr cMessage
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     IncFile.ShowWarning
; Purpose:    Shows a warning condition.
; Arguments:  Arg1: Level [0..3].
;             Arg2: -> Format String.
;             Arg2-n: Format arguments
; Return:     Nothing.

Method IncFile.ShowWarning, uses xbx xdi, dWarningLevel:DWORD, pFormat:PSTRING, Args:vararg
  local cMessage[1024]:CHR

  SetObject xbx
  inc [xbx].dWarningCount
  lea xdi, cMessage
  WriteF xdi, "¦SU(¦UD) = ", [xbx].pHeaderFileName, [xbx].dLineNumber
  invoke wsprintf, xdi, pFormat, addr Args
  OCall [xbx].pOwner::Application.ShowWarning, dWarningLevel, addr cMessage
MethodEnd

endif
