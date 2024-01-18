; ==================================================================================================
; Title:    h2incX_IncFile.inc
; Author:   G. Friedrich
; Version:  C.01.00
; Purpose:  ObjAsm support of h2incX IncFile objects.
; Notes:    See h2incX.asm
; ==================================================================================================


MAX_IF_LEVEL      equ   32      ;Must be a multiple of 4
MAX_BLOCK_NAME    equ   128     ;Buffer size for struct, union, etc. names.
ADD_50_PERCENT    equ   0       ;0 = buffer size 100% larger than file size

INP_STAT struc
  pIn             POINTER ?
  dLineNbr        DWORD   ?
  bNewLine        BYTE    ?
  bIfLevel        BYTE    ?
  bSkipC          BYTE    ?
  bSkipScanPP     BYTE    ?
  bIfStructure    BYTE    MAX_IF_LEVEL dup (?)
  bIfResult       BYTE    MAX_IF_LEVEL dup (?)
  bIfHistory      BYTE    MAX_IF_LEVEL dup (?)
INP_STAT ends
P_INP_STAT typedef ptr INP_STAT

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Object:   IncFile
; Purpose:  Handle all actions to generate an .inc file.

Object IncFile, 123456, Primer
  StaticMethod    Analyse
  StaticMethod    CreateDefFile,      PSTRINGA
  RedefineMethod  Done
  RedefineMethod  Init,               POINTER, PSTRINGA, $ObjPtr(IncFile)
  StaticMethod    GetNextToken
  StaticMethod    GetNextTokenFromPPLine
  StaticMethod    PeekNextToken
  StaticMethod    ParseHeaderFile
  StaticMethod    ParseHeaderLine,    PSTRINGA, DWORD
  StaticMethod    Save,               PSTRINGA
  StaticMethod    AddComment,         PSTRINGA
  StaticMethod    SkipComments,       PSTRINGA
  StaticMethod    StmCopyRestOfPPLine
  StaticMethod    StmSkipRestOfPPLine
  StaticMethod    StmDeleteLastSpace
  StaticMethod    StmWrite,           PSTRINGA
  StaticMethod    StmWriteChar,       CHRA
  StaticMethod    StmWriteComment
  StaticMethod    StmWriteF,          PSTRINGA, ?
  StaticMethod    StmWriteEOL
  StaticMethod    StmWriteIndent
  StaticMethod    LoadInputStatus,    P_INP_STAT
  StaticMethod    SaveInputStatus,    P_INP_STAT
  StaticMethod    ShowError,          PSTRINGA, ?
  StaticMethod    ShowWarning,        PSTRINGA, ?

  DefineVariable  pStmBuffer1,        PSTRINGA, NULL    ;-> Input stream buffer (Token stream)
  DefineVariable  pStmBuffer2,        PSTRINGA, NULL    ;-> Header file & Output stream buffer
  DefineVariable  pStmInpPos,         PSTRINGA, NULL    ;-> Current input stream position
  DefineVariable  pStmOutPos,         PSTRINGA, NULL    ;-> Current output stream position
  DefineVariable  pFileName,          PSTRINGA, NULL    ;-> File name
  DefineVariable  pFullPath,          PSTRINGA, NULL    ;-> Full path
  DefineVariable  pPrevToken,         PSTRINGA, NULL
  DefineVariable  pImportSpec,        PSTRINGA, NULL
  DefineVariable  pCallConv,          PSTRINGA, NULL
  DefineVariable  pEndMacro,          PSTRINGA, NULL
  DefineVariable  pStructName,        PSTRINGA, NULL    ;-> Current struct/union/class name
  DefineVariable  pDefs,              $ObjPtr(List), NULL    ;-> .DEF file content
  DefineVariable  pParent,            $ObjPtr(IncFile), NULL ;-> Parent IncFile (if any)
  DefineVariable  FileTime,           FILETIME, {}      ;Stores ftLastWrite of .h file
  DefineVariable  dBufSize,           DWORD,    0       ;Size of buffers
  DefineVariable  dBlockLevel,        DWORD,    0       ;Block level where pEndMacro becomes active
  DefineVariable  dQualifiers,        DWORD,    0       ;Current qualifiers
  DefineVariable  dLineNbr,           DWORD,    0       ;Current line number
  DefineVariable  dEnumValue,         DWORD,    0       ;Counter for enums
  DefineVariable  dErrors,            DWORD,    0       ;Errors occured in this file conversion
  DefineVariable  dWarnings,          DWORD,    0       ;Warnings occured in this file conversion
  DefineVariable  dBraces,            DWORD,    0       ;Curly brackets count => Block deep
  DefineVariable  dIndentation,       DWORD,    0       ;Indentation level: 0..n
  DefineVariable  bStmOutEOL,         DWORD,    FALSE   ;StmOut line ended. It MUST be a DWORD!
  DefineVariable  bSkipScanPP,        BYTE,     FALSE   ;>0 => don't parse PP lines in StmInp
  DefineVariable  bSkipLogiPP,        BYTE,     FALSE   ;TRUE => don't parse PP lines in StmInp
  DefineVariable  bSkipC,             BYTE,     FALSE   ;>0 => don't parse C lines in StmInp
  DefineVariable  bNewLine,           BYTE,     FALSE   ;Last token was a PCT_EOL
  DefineVariable  bComment,           BYTE,     FALSE   ;Comment flag for "/*" and "*/"
  DefineVariable  bUsePrevToken,      BYTE,     FALSE   ;GetNextToken returns pPrevToken
  DefineVariable  bExternC,           BYTE,     FALSE   ;Extern "C" occured
  DefineVariable  bInsideClass,       BYTE,     FALSE   ;Inside a class definition
  DefineVariable  bInsideInterface,   BYTE,     FALSE   ;Inside an interface definition
  DefineVariable  bSkipUselessCode,   BYTE,     FALSE   ;Flag to avoid [...] repetitions
  DefineVariable  bIfLevel,           BYTE,     0       ;Current 'if' level
  DefineVariable  bIfStructure,       BYTE,     MAX_IF_LEVEL dup(0)  ;If structure stack
  DefineVariable  bIfResult,          BYTE,     MAX_IF_LEVEL dup(0)  ;If result stack
  DefineVariable  bIfHistory,         BYTE,     MAX_IF_LEVEL dup(0)  ;If history stack

ObjectEnd


; ==================================================================================================

if IMPLEMENT

PP_CMD_HANDLER_ENTRY struct
  pCmd      PSTRINGA ?
  pHandler  POINTER ?
PP_CMD_HANDLER_ENTRY ends
PPRE_PROC_CMD typedef ptr PP_CMD_HANDLER_ENTRY

MakeObjects .\h2incX_Evaluator

.code
include h2incX_IncFile_Mac.inc
include h2incX_IncFile_Proc.inc
include h2incX_IncFile_Parse.inc
include h2incX_Handler.inc

.data

;Preprocessor command table
;Commands not listed here will be commented out
PreProcCmdHandlerTab label PP_CMD_HANDLER_ENTRY
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

;Table used when IncFile.bSkipScanPP(2) == TRUE
PreProcCmdNPHandlerTab label PP_CMD_HANDLER_ENTRY
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

g_OpConvTab label DWORD
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
OpConvTabEntries equ ($ - offset g_OpConvTab) / sizeof OP_CONV_ENTRY

.const

;Delimiters known by parser
bDelim  db ",;:()[]{}|*<>!~-+=/&#%^"      ;Excluded "?"   "\"?

;2-BYTE opcodes known by parser
w2CharOps dw ">>", "<<", "&&", "||", ">=", "<=", "==", "!=", "->", "::", "##", "++", "--", \
             "+=", "-=", "*=", "/=", "%=", "&=", "|=", "^=", "?:"

d3CharOps dd ">>=", "<<="

.code

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:    IncFile.AddComment
; Purpose:   Stores the comment for later output.
; Arguments: Arg1 -> Comment string
; Return:    Nothing.

Method IncFile.AddComment,, pCommentText:PSTRINGA
    mov edx, pCommentText
    inc edx
    invoke StrCopyA, addr [g_szComment + 1], edx
    mov [g_szComment], ';'
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:    IncFile.Analyse
; Purpose:   Start analysis of header file.
; Arguments: Arg1 -> FileName.
;            Arg2 -> Parent.
; Return:    eax = 0 if error occured.

Method IncFile.Analyse, uses ebx edi esi
    local dBytesWritten:DWORD, SysTime:SYSTEMTIME

    SetObject ebx
    DbgPrintF $RGB(0,0,0), <"---------- IncFile.Analyzer begin with '%s' ----------">, [ebx].pFileName
    mrm [ebx].pStmInpPos, [ebx].pStmBuffer1, edi

;    if DEBUGGING
;      invoke CreateFile, $OfsCStrA("~parsed.tmp"), GENERIC_WRITE, FILE_SHARE_WRITE, NULL, \
;                         CREATE_ALWAYS, FILE_ATTRIBUTE_ARCHIVE, 0
;      .if eax != INVALID_HANDLE_VALUE
;        mov esi, eax
;        mov ecx, [ebx].pStmOutPos
;        sub ecx, edi
;        invoke WriteFile, esi, edi, ecx, addr dBytesWritten, NULL
;        invoke CloseHandle, esi
;      .endif
;    endif

    mrm [ebx].pStmOutPos, [ebx].pStmBuffer2, edi
    mov CHRA ptr [edi], 0
    mov [ebx].bComment, FALSE
    mov [ebx].bSkipScanPP, 0
    mov [ebx].dLineNbr, 1
    mov [ebx].bNewLine, TRUE

;    mov esi, offset g_VolatilConvTable
;    .while POINTER ptr [esi] != NULL
;      OCall [esi].CONV_TAB_ENTRY.pList::List.DeleteAll
;      add esi, sizeof CONV_TAB_ENTRY
;    .endw

    OCall ebx::IncFile.StmWrite, $OfsCStrA(";Include file created by h2incX, Version ", VERSION)
    OCall ebx::IncFile.StmWrite, offset g_szCreation
    OCall ebx::IncFile.StmWriteEOL

    OCall ebx::IncFile.StmWrite, $OfsCStrA(";", COPYRIGHT)
    OCall ebx::IncFile.StmWriteEOL

    OCall ebx::IncFile.StmWriteF, $OfsCStrA(";Source file: '%s'"), [ebx].pFullPath
    invoke FileTimeToSystemTime, addr [ebx].FileTime, addr SysTime
    movzx eax, SysTime.wYear
    movzx edx, SysTime.wMonth
    movzx esi, SysTime.wDay
    movzx ecx, SysTime.wHour
    movzx edi, SysTime.wMinute
    OCall ebx::IncFile.StmWriteF, $OfsCStrA(", last modified: %02u/%02u/%02u %02u:%02u"),\
                                  esi, edx, eax, ecx, edi
    OCall ebx::IncFile.StmWriteEOL

    invoke GetCommandLine
    mov esi, eax
    xor eax, eax
    .while CHRA ptr [esi] != 0
      lodsb
      .if al == '"'
        xor ah, 1
      .endif
      .break .if ax == " "
    .endw
    OCall ebx::IncFile.StmWriteF, $OfsCStrA(";Creation parameters: %s"), esi
    OCall ebx::IncFile.StmWriteEOL
    OCall ebx::IncFile.StmWriteEOL
    .repeat
      invoke ParseC
    .until eax == FALSE

    .if [ebx].bIfLevel != 0
      OCall ebx::IncFile.ShowError, $OfsCStrA("unmatching if/endif")
    .endif

;    OCall ebx::IncFile.StmWriteEOL
;    .if [ebx].dWarnings != 0
;      OCall ebx::IncFile.StmWriteF, $OfsCStrA(";Warnings: %u"), [ebx].dWarnings
;      OCall ebx::IncFile.StmWriteEOL
;    .endif
;    OCall ebx::IncFile.StmWriteF, $OfsCStrA(";Errors: %u"), [ebx].dErrors
;    OCall ebx::IncFile.StmWriteEOL
    DbgPrintF $RGB(0,0,0), <"---------- IncFile.Analize end of '%s' ----------">, [ebx].pFileName
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:    IncFile.CreateDefFile
; Purpose:   Create a new .def file.
; Arguments: Arg1 -> FileName.
; Return:    eax = TRUE if succeeded, otherwise FALSE.

Method IncFile.CreateDefFile, uses ebx esi, pFileName:PSTRINGA
    local hFile:HANDLE, Result:DWORD, dBytesWritten:DWORD
    local cFile[MAX_PATH]:CHR, cText[512]:CHR

    SetObject ebx
    mov Result, FALSE

    .if [ebx].pDefs != NULL
      mov edx, [ebx].pDefs
      .if [edx].$Obj(List).dCount == 0
        .if g_bWarningLevel > 2
          invoke printf, $OfsCStrA("no items for .DEF file", LF)
        .endif
        jmp @Exit
      .endif

      invoke StrCopyA, addr cFile, pFileName
      invoke StrLengthA, pFileName
      lea ecx, cFile
      .if (eax < 5) || (CHR ptr [ecx + eax - 4] != '.')
        invoke printf, $OfsCStrA("invalid file name %s for .def file", LF), pFileName
        jmp @Exit
      .endif
      mov pFileName, ecx
      mov DWORD ptr [ecx + eax - 3], "fed"

      invoke CreateFile, pFileName,GENERIC_WRITE, FILE_SHARE_WRITE, NULL, CREATE_ALWAYS, \
                         FILE_ATTRIBUTE_ARCHIVE, 0
      .if eax != INVALID_HANDLE_VALUE
        mov hFile, eax
        invoke WriteFile, hFile, $OfsCStrA("LIBRARY", LF), 7 + 2, addr dBytesWritten, NULL
        invoke WriteFile, hFile, $OfsCStrA("EXPORTS", LF), 7 + 2, addr dBytesWritten, NULL
        xor esi, esi
        .while TRUE
          mov ecx, [ebx].pDefs
          .break .if esi == [ecx].$Obj(List).dCount
          OCall ecx::List.ItemAt, esi
          invoke sprintf, addr cText, $OfsCStrA(" ", 22h, "%s", 22h, CR, LF), PSTRINGA ptr [eax]
          lea ecx, dBytesWritten
          invoke WriteFile, hFile, addr cText, eax, ecx, NULL
          inc esi
        .endw
        invoke CloseHandle, hFile
        mov Result, TRUE
      .else
        invoke GetLastError
        invoke printf, $OfsCStrA("Can't create file %s [%X]", LF), pFileName, eax
      .endif
    .endif
@Exit:
    mov eax, Result
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:    IncFile.Done
; Purpose:   Destructor
; Arguments: None.
; Return:    Nothing.

Method IncFile.Done, uses ebx
    SetObject ebx
    DbgPrintF $RGB(0,0,0), <"Free StmBuffer1 %X for '%s'">, [ebx].pStmBuffer1, [ebx].pFileName
    invoke VirtualFree, [ebx].pStmBuffer2, 0, MEM_RELEASE
    DbgPrintF $RGB(0,0,0), <"Free StmBuffer2 %X for '%s'">, [ebx].pStmBuffer2, [ebx].pFileName
    invoke VirtualFree, [ebx].pStmBuffer1, 0, MEM_RELEASE

    .if [ebx].pDefs != NULL
      Destroy [ebx].pDefs
      mov [ebx].pDefs, NULL
    .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:    IncFile.GetNextToken
; Purpose:   Returns the next token from input stream. Comments are handled automatically.
; Arguments: None.
; Return:    eax -> Token or NULL if EOF reached.

Method IncFile.GetNextToken, uses ebx edi
    SetObject ebx
    .if [ebx].bUsePrevToken != FALSE
      mov [ebx].bUsePrevToken, FALSE
      mov eax, [ebx].pPrevToken
    .else
@TryAgain:
      mov edi, [ebx].pStmInpPos
      mov ecx, -1
      mov al, 0
      repnz scasb
      not ecx
      dec ecx                                           ;ecx = character count
      .if ecx == 0
        xor eax, eax                                    ;Return NULL
        jmp @Exit
      .endif
      mov eax, edi
      xchg eax, [ebx].pStmInpPos
      .if DCHRA ptr [eax] == PCT_EOL                    ;Check for EOL
        inc [ebx].dLineNbr
        mov [ebx].bNewLine, TRUE                        ;Set StreamIn new line maker
        .if [ebx].bStmOutEOL != FALSE                   ;Check Stream out EOL
          OCall ebx::IncFile.StmWriteComment
          .if eax != FALSE
            OCall ebx::IncFile.StmWriteEOL
          .endif
        .endif
        jmp @TryAgain                                   ;Take the next Token
      .endif

      .if CHRA ptr [eax] == "\"                         ;Check for C continuation => combine lines
        inc [ebx].dLineNbr                              ;  This should happen while tokenizing
        mov [ebx].bNewLine, TRUE                        ;Set StreamIn new line maker
        .if [ebx].bStmOutEOL != FALSE                   ;Check Stream out EOL
          OCall ebx::IncFile.StmWriteComment
          .if eax != FALSE
            OCall ebx::IncFile.StmWriteEOL
          .endif
        .endif
        jmp @TryAgain                                   ;Take the next Token
      .endif

      .if DCHRA ptr [eax] == PCT_COMMENT
        .if [ebx].bSkipScanPP == 0
          OCall ebx::IncFile.AddComment, eax
        .endif
        jmp @TryAgain
      .endif

      ;Each time a new line is started from input stream, check if we have a PP command
      .if [ebx].bNewLine != FALSE && CHRA ptr [eax] == '#'
        OCall ebx::IncFile.StmWriteComment
        .if eax != FALSE
          OCall ebx::IncFile.StmWriteEOL
        .endif
        invoke ParsePP
        jmp @TryAgain
      .endif
    .endif

@Exit:
    mov [ebx].bNewLine, FALSE
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:    IncFile.GetNextTokenFromPPLine
; Purpose:   Returns the next token from within a PP command. Comments are handled automatically.
; Arguments: None.
; Return:    eax -> Token or NULL if Token = PCT_EOL or EOF reached.

Method IncFile.GetNextTokenFromPPLine, uses ebx edi
    SetObject ebx
    mov edi, [ebx].pStmInpPos
@NextToken:
    mov ecx, -1
    mov al, 0                                           ;ZTC
    repnz scasb
    not ecx
    xor eax, eax                                        ;Return NULL
    dec ecx                                             ;ecx = character count
    mov [ebx].bNewLine, FALSE
    .if ecx != 0
      mov eax, edi
      xchg eax, [ebx].pStmInpPos
      .if CHRA ptr [eax] == PCT_EOL
        inc [ebx].dLineNbr
        mov [ebx].bNewLine, TRUE
        xor eax, eax                                    ;Return NULL
      .else
        .if CHRA ptr [eax] == PCT_WEAKEOL
          inc [ebx].dLineNbr
          jmp @NextToken
        .endif
        .if CHRA ptr [eax] == PCT_IGNORE
          jmp @NextToken
        .endif
        .if CHRA ptr [eax] == PCT_COMMENT
          OCall ebx::IncFile.AddComment, eax
          jmp @NextToken
        .endif
      .endif
    .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:    IncFile.PeekNextToken
; Purpose:   Peeks the next token.
; Arguments: None.
; Return:    eax = token.

Method IncFile.PeekNextToken, uses ebx
    local InpStat:INP_STAT

    SetObject ebx
    OCall ebx::IncFile.SaveInputStatus, addr InpStat
    inc [ebx].bSkipScanPP
    OCall ebx::IncFile.GetNextToken
    push eax
    dec [ebx].bSkipScanPP
    OCall ebx::IncFile.LoadInputStatus, addr InpStat
    pop eax
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:    IncFile.Init
; Purpose:   Constructor
; Arguments: Arg1 -> FileName.
;            Arg2 -> Parent IncFile that created (include) this instance.
; Return:    eax = FALSE if error occured, otherwise TRUE.

Method IncFile.Init, uses ebx, pOwner:POINTER, pFileName:PSTRINGA, pParent:$ObjPtr(IncFile)
    local hFile:HANDLE, dFileSize:DWORD, dBytesRead:DWORD
    local ftLastWrite:FILETIME, cFileName[MAX_PATH]:CHR, szName[256]:CHRA, szExt[256]:CHRA

    SetObject ebx
    ACall ebx::IncFile.Init, pOwner

    .if g_bCreateDefs != FALSE
      mov [ebx].pDefs, $New(List)
      OCall eax::List.Init, NULL, 100, 10, CF_SNGL
    .endif

    invoke _splitpath, pFileName, NULL, NULL, addr szName, addr szExt
    invoke CreateFile, pFileName, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, 0, 0
    .if eax == INVALID_HANDLE_VALUE
      .if g_pIncDir != NULL
        invoke _makepath, addr cFileName, NULL, g_pIncDir, addr szName, addr szExt
        invoke CreateFile, addr cFileName, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, 0, 0
        .if eax != INVALID_HANDLE_VALUE
          lea ecx, cFileName
          mov pFileName, ecx
          jmp @FileExist
        .endif
      .endif
      .if pParent != NULL
        mov ecx, pParent
        mov edx, [ecx].$Obj(IncFile).pFileName
        invoke printf, $OfsCStrA("%s(%u): "), [ecx].$Obj(IncFile).pFileName, [ecx].$Obj(IncFile).dLineNbr
      .endif
      invoke GetLastError
      invoke printf, $OfsCStrA("Can't open file '%s' [Error: %X]", LF), pFileName, eax
      mov eax, pFileName
      DbgStr eax,, "Files not found"
      xor eax, eax
      jmp @@EOM
    .endif

@FileExist:
    mov hFile, eax
    invoke StrSizeA, pFileName
    OCall g_pMemPool::MemPool.AddBStrA, pFileName, eax
    mov [ebx].pFullPath, eax
    invoke _makepath, addr cFileName, NULL, NULL, addr szName, addr szExt
    invoke StrSizeA, addr cFileName
    OCall g_pMemPool::MemPool.AddBStrA, addr cFileName, eax
    mov [ebx].pFileName, eax
;    DbgStr [ebx].pFileName,, "FileNames"
    invoke GetFileTime, hFile, NULL, NULL, addr ftLastWrite
    invoke FileTimeToLocalFileTime, addr ftLastWrite, addr [ebx].FileTime

    invoke GetFileSize, hFile, NULL
    mov dFileSize, eax
    mov ecx, eax

if ADD_50_PERCENT
    shr ecx, 1          ;add 50% to file size for buffer size
endif
    add eax, ecx        ;add 100% to file size for buffer size

    mov [ebx].dBufSize, eax
    invoke VirtualAlloc, NULL, [ebx].dBufSize, MEM_RESERVE or MEM_COMMIT, PAGE_READWRITE
    .if eax != NULL
      mov [ebx].pStmBuffer1, eax
      DbgPrintF $RGB(0,0,0), <"Alloc StmBuffer1 for %s returned %X">, [ebx].pFileName, eax
      invoke VirtualAlloc, NULL, [ebx].dBufSize, MEM_RESERVE or MEM_COMMIT, PAGE_READWRITE
      mov [ebx].pStmBuffer2, eax
      DbgPrintF $RGB(0,0,0), <"Alloc StmBuffer2 for %s returned %X">, [ebx].pFileName, eax
    .endif
    .if eax == NULL
      invoke printf, $OfsCStrA("Fatal error: out of memory", LF)
      mov g_bTerminate, TRUE
      xor eax, eax
      jmp @@EOM
    .endif
    invoke ReadFile, hFile, [ebx].pStmBuffer2, dFileSize, addr dBytesRead, NULL
    invoke CloseHandle, hFile
    mov eax, dBytesRead
    mov ecx, [ebx].pStmBuffer2
    mov CHRA ptr [ecx + eax], 0
    mov [ebx].pStmInpPos, ecx
    mov ecx, [ebx].pStmBuffer1
    mov CHRA ptr [ecx], 0
    mov [ebx].pStmOutPos, ecx
    mov eax, pParent
    mov [ebx].pParent, eax
    mov BYTE ptr [ebx].bNewLine, TRUE
    mov eax, TRUE
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:    IncFile.ParseHeaderFile
; Purpose:   Input is C header source, output is tokenized, that is:
;             + each token is an ASCII string
;             + numeric literals (numbers) are converted to ASM already
;             + comments are marked as such
;             example:
;             input stream: "#define VAR1 0xA+2"\r\n
;             output stream: "#",0,"define",0,"VAR1",0,"0Ah",0,"+",0,"2",0,PCT_EOL,0
; Arguments: None.
; Return:    eax -> End of Stream.

Method IncFile.ParseHeaderFile, uses ebx edi esi
    local bContinuation:DWORD

    SetObject ebx
    mov [ebx].dLineNbr, 1
    mov bContinuation, FALSE
    .repeat
      ;Parse a line
      ;  1. skip any white spaces at the beginning
      ;  2. check '\' for preprocessor lines (weak EOL)
      ;  3. call parseline
      ;  4. adjust [ebx].pStmInpPos

      mov esi, [ebx].pStmInpPos
      .while (CHRA ptr [esi] == " ") || (CHRA ptr [esi] == TAB)
        inc esi
      .endw
      mov edx, esi
      xor edi, edi
      .while TRUE
        .break .if CHRA ptr [esi] == 0
        lodsb
        .if (al == CR) || (al == LF)
          mov CHRA ptr [esi - 1], 0
          .if edi == NULL
            lea edi, [esi - 1]
          .endif
          .break .if al == LF
        .endif
      .endw
      .if esi != [ebx].pStmInpPos
        inc [ebx].dLineNbr
      .endif

      mov ah, 0
      .if bContinuation != FALSE || CHRA ptr [edx] == '#'
        mov bContinuation, FALSE
        mov ecx, edi
        .while ecx >= edx
          mov al, [ecx]
          .if al == '\'
            .while CHRA ptr [ecx]
              mov CHRA ptr [ecx], " "
              inc ecx
            .endw
            mov ah, 1
            mov bContinuation, TRUE
            .break
          .endif
          .break .if al >= " "
          dec ecx
        .endw
      .endif

      movzx eax, ah
      OCall ebx::IncFile.ParseHeaderLine, edx, eax

      mov eax, esi
      sub eax, [ebx].pStmInpPos
      mov [ebx].pStmInpPos, esi

    .until eax == 0

    mov eax, [ebx].pStmOutPos
    mov CHRA ptr [eax], 0
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:    IncFile.ParseHeaderLine
; Purpose:   Get a source text line and
;             1. skip any white spaces at the beginning
;             2. check '\' for preprocessor lines (weak EOL)
;             3. call parseline
;             4. adjust [ebx].$Obj(IncFile).pStmInpPos
; Arguments: Arg1 -> Text line into input buffer.
;            Arg2: Weak Line End flag.
; Return:    eax = line length (0 means EOF).

Method IncFile.ParseHeaderLine, uses ebx edi esi, pLine:PSTRINGA, bWeak:DWORD
    local bIsPreProc:DWORD, bIsDefine:DWORD

    SetObject ebx
    mov bIsPreProc, FALSE
    mov bIsDefine, FALSE
    mov esi, pLine
    .if CHRA ptr [esi] == '#'
      mov bIsPreProc, TRUE
    .endif
    OCall ebx.SkipComments, esi
    mov edi, [ebx].pStmOutPos
    xor ecx, ecx                ;token counter
    .while TRUE
      mov al, [esi]
      .break .if al == 0
      mov edx, edi              ;edx holds start of token
      .if al == '/' && CHRA ptr [esi + 1] == '/'
        .if g_bIncludeComments != FALSE
          mov al, PCT_COMMENT
          stosb
          invoke StrECopyA, edi, esi
          lea edi, [eax + 1]
        .endif
        .break
      .endif
      ;Get 1 token
      .while TRUE
        .break .if CHRA ptr [esi] == 0
        lodsb
        .break .if al == " " || al == 9
        .if edi == edx && al == '"'
          invoke GetStringLiteral
          .break
        .endif
        .if edi == edx && al == 'L' && CHRA ptr [esi] == '"'
          stosb
          mov al, '('
          stosb
          lodsb
          invoke GetStringLiteral
          mov al, ')'
          stosb
          .break
        .endif

        .if edi == edx && al >= '0' && al <= '9'
          dec esi
          invoke ConvertNumber                          ;Preserves ecx, edx
          .break
        .endif

        ;Check if content of al is a delimiter
        push edi
        push ecx
        mov edi, offset bDelim
        mov ecx, sizeof bDelim
        repnz scasb
        pop ecx
        pop edi
        .if ZERO?
          .if edi != edx
            .if al == '(' && bIsDefine != FALSE && ecx == 2
              mov al, 0
              stosb
              mov ax, PCT_MACRO
              stosb
            .endif
            dec esi
          .else
            stosb
            mov ah, [esi]

            ;check if context of ax is a 2 char operand
            push edi
            push ecx
            xchg al, ah
            mov edi, offset w2CharOps
            mov ecx, sizeof w2CharOps / sizeof WORD
            repnz scasw
            pop ecx
            pop edi

            .if ZERO?
              movsb
            .endif
          .endif
          .break
        .endif
        stosb
      .endw
      .if edx != edi
        mov CHRA ptr [edi], 0
        inc edi
        inc ecx
        .if ecx == 2 && bIsPreProc != FALSE
          .if $DoesTextMatchA?([edx], <define>)
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
    mov [ebx].pStmOutPos, edi
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:    IncFile.Save
; Purpose:   Write output buffer to file.
; Arguments: Arg1 -> FileName
; Return:    eax = TRUE is succeded, otherwise FALSE.

Method IncFile.Save, uses ebx edi, pFileName:PSTRINGA
    local Result:DWORD, hFile:HANDLE, dBytesWritten:DWORD

    SetObject ebx
    mov Result, TRUE
    invoke StrSizeA, [ebx].pStmBuffer2
    .if eax != 0
      mov edi, eax
      invoke CreateFile, pFileName, GENERIC_WRITE, FILE_SHARE_WRITE, NULL, \
                         CREATE_ALWAYS, FILE_ATTRIBUTE_ARCHIVE, 0
      .if eax != INVALID_HANDLE_VALUE
        mov hFile, eax
        invoke WriteFile, hFile, [ebx].pStmBuffer2, edi, addr dBytesWritten, NULL
        .if dBytesWritten != edi
          invoke GetLastError
          invoke printf, $OfsCStrA("%s: Write error [%X]", LF), pFileName, eax
          mov Result, FALSE
        .endif
        invoke CloseHandle, hFile
      .else
        invoke GetLastError
        invoke printf, $OfsCStrA("Can't create file %s [%X]", LF), pFileName, eax
        mov Result, FALSE
      .endif
    .endif
    mov eax, Result
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:    IncFile.SkipComments
; Purpose:   Skip comments "/* ... */" in a line
; Arguments: Arg1: -> Line
; Return:    None.

Method IncFile.SkipComments, uses ebx edi esi, pLine:PSTRINGA
    SetObject ebx
    .if g_bIncludeComments != FALSE
      mov edi, [ebx].pStmOutPos
      mov al, PCT_COMMENT
      stosb
    .endif
    mov esi, pLine
    mov al, 0
    .while TRUE
      mov ah, al
      lodsb
      .break .if al == 0
      .break .if ax == "//" && [ebx].bComment == FALSE
      .if [ebx].bComment != 0 && ax == "*/"
        mov DCHRA ptr [esi - 2], 2020h
        mov [ebx].bComment, FALSE
      .endif
      .if ax == '/*' && [ebx].bComment == FALSE
        mov [ebx].bComment, TRUE
        mov DCHRA ptr [esi - 2], 2020h
      .endif
      .if [ebx].bComment != FALSE
        .if g_bIncludeComments != FALSE
          stosb
        .endif
        mov CHRA ptr [esi - 1], " "
      .endif
    .endw
    .if g_bIncludeComments != FALSE
      .if BYTE ptr [edi - 1] == PCT_COMMENT
        mov CHRA ptr [edi - 1], 0
      .else
        mov al, 0
        stosb
        mov [ebx].pStmOutPos, edi
      .endif
    .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:    IncFile.StmCopyRestOfPPLine
; Purpose:   copy rest of line to the output stream.
; Arguments: None.
; Return:    eax = TRUE if succeeded, otherwise FALSE.

Method IncFile.StmCopyRestOfPPLine
    .while TRUE
      OCall pSelf::IncFile.GetNextTokenFromPPLine
      .break .if eax == NULL
      push eax
      OCall pSelf::IncFile.StmWriteChar, " "
      pop eax
      OCall pSelf::IncFile.StmWrite, eax
    .endw
    OCall pSelf::IncFile.StmWriteComment
    OCall pSelf::IncFile.StmWriteEOL
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:    IncFile.StmSkipRestOfPPLine
; Purpose:   Skip the rest of line.
; Arguments: None.
; Return:    eax = TRUE if succeeded, otherwise FALSE.

Method IncFile.StmSkipRestOfPPLine
    SkipPPLine
    OCall pSelf::IncFile.StmWriteComment
    OCall pSelf::IncFile.StmWriteEOL
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:    IncFile.StmDeleteLastSpace
; Purpose:   Deletes last space from output stream.
; Arguments: None.
; Return:    eax = TRUE if succeeded, otherwise FALSE.

Method IncFile.StmDeleteLastSpace
    SetObject ebx
    mov eax, [ebx].pStmOutPos
    .if CHRA ptr [eax - 1] == " "
      mov CHRA ptr [eax - 1], 0
      dec [ebx].pStmOutPos
    .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:    IncFile.StmWrite
; Purpose:   Write a string to the output stream. Indentation is implemented here.
; Arguments: Arg1 -> Text.
; Return:    eax -> current StreamOut position.

Method IncFile.StmWrite, uses ebx, pText:PSTRINGA
    SetObject ebx
    .if [ebx].bStmOutEOL != FALSE
      mov [ebx].bStmOutEOL, FALSE
      OCall ebx::IncFile.StmWriteIndent
    .endif
    invoke StrECopyA, [ebx].pStmOutPos, pText
    mov [ebx].pStmOutPos, eax
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:    IncFile.StmWriteComment
; Purpose:   Writes the current comments to the output stream.
; Arguments: None.
; Return:    eax = TRUE if succeeded, otherwise FALSE.

Method IncFile.StmWriteComment
    xor eax, eax
    .if g_bIncludeComments != FALSE && CHRA ptr [g_szComment + 1] != 0
      OCall pSelf::IncFile.StmWrite, addr g_szComment
      mov CHRA ptr [g_szComment + 1], 0                 ;Set ZTC after ";"
      mov eax, TRUE
    .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:    IncFile.StmWriteChar
; Purpose:   Write a character to the output stream.
; Arguments: Arg1: ANSI Character.
; Return:    eax -> current StreamOut position.

Method IncFile.StmWriteChar, uses ebx, bChar:CHR
    SetObject ebx
    .if [ebx].bStmOutEOL != FALSE
      mov [ebx].bStmOutEOL, FALSE
      OCall ebx::IncFile.StmWriteIndent
    .endif
    mov eax, [ebx].pStmOutPos
    movzx cx, bChar
    mov [eax], cx                                       ;Write also a ZTC
    inc [ebx].pStmOutPos
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:    IncFile.StmWriteF
; Purpose:   Write a formated string to the output stream.
; Arguments: Arg1: -> Format.
;            Arg2: -> Arguments.
; Return:    eax -> current StreamOut position.

Method IncFile.StmWriteF, uses ebx, pFormat:PSTRINGA, Args:vararg
    SetObject ebx
    .if [ebx].bStmOutEOL != FALSE
      mov [ebx].bStmOutEOL, FALSE
      OCall ebx::IncFile.StmWriteIndent
    .endif
    invoke vsprintf, [ebx].pStmOutPos, pFormat, addr [pFormat + sizeof(PSTRINGA)] ;-> Arguments
    add [ebx].pStmOutPos, eax
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:    IncFile.StmWriteEOL
; Purpose:   Write a <CR, LF> sequence (End of Line) to the output stream.
; Arguments: None.
; Return:    eax -> current StreamOut position.

Method IncFile.StmWriteEOL, uses ebx
    SetObject ebx
    .if [ebx].bStmOutEOL != FALSE
      mov [ebx].bStmOutEOL, FALSE
      OCall ebx::IncFile.StmWriteIndent
    .endif
    invoke StrECopyA, [ebx].pStmOutPos, $OfsCStr(CR, LF)
    mov [ebx].pStmOutPos, eax
    mov [ebx].bStmOutEOL, TRUE
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:    IncFile.StmWriteIndent
; Purpose:   Write code indentation
; Arguments: None.
; Return:    Nothing.

Method IncFile.StmWriteIndent, uses ebx esi
    SetObject ebx
    mov esi, [ebx].$Obj(IncFile).dIndentation
    .if SDWORD ptr esi < 0                        ;Just in case something goes wrong
      mov [ebx].$Obj(IncFile).dIndentation, 0
    .else
      shl esi, 1
      .while !ZERO?
        OCall ebx::IncFile.StmWriteChar, " "
        dec esi
      .endw
    .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:    IncFile.LoadInputStatus
; Purpose:   Load the input status from an INP_STAT structure.
; Arguments: Arg1: -> INP_STAT.
; Return:    Nothing.

Method IncFile.LoadInputStatus, uses ebx edi esi, pStatus:P_INP_STAT
    SetObject ebx
    mov esi, pStatus
    mov eax, [esi].INP_STAT.pIn
    mov ecx, [esi].INP_STAT.dLineNbr
    mov dl, [esi].INP_STAT.bNewLine
    mov dh, [esi].INP_STAT.bIfLevel
    mov [ebx].pStmInpPos, eax
    mov [ebx].dLineNbr, ecx
    mov [ebx].bNewLine, dl
    mov [ebx].bIfLevel, dh
    mov dl, [esi].INP_STAT.bSkipC
    mov dh, [esi].INP_STAT.bSkipScanPP
    mov [ebx].bSkipC, dl
    mov [ebx].bSkipScanPP, dh

    mov eax, esi
    lea edi, [ebx].bIfStructure
    lea esi, [eax].INP_STAT.bIfStructure
    mov ecx, MAX_IF_LEVEL/sizeof(DWORD)
    rep movsd

    lea edi, [ebx].bIfResult
    lea esi, [eax].INP_STAT.bIfResult
    mov ecx, MAX_IF_LEVEL/sizeof(DWORD)
    rep movsd

    lea edi, [ebx].bIfHistory
    lea esi, [eax].INP_STAT.bIfHistory
    mov ecx, MAX_IF_LEVEL/sizeof(DWORD)
    rep movsd
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:    IncFile.SaveInputStatus
; Purpose:   Save the input status in an INP_STAT structure.
; Arguments: Arg1: -> INP_STAT.
; Return:    Nothing.

Method IncFile.SaveInputStatus, uses ebx edi esi, pStatus:P_INP_STAT
    SetObject ebx
    mov esi, pStatus
    mov eax, [ebx].pStmInpPos
    mov ecx, [ebx].dLineNbr
    mov dl, [ebx].bNewLine
    mov dh, [ebx].bIfLevel
    mov [esi].INP_STAT.pIn, eax
    mov [esi].INP_STAT.dLineNbr, ecx
    mov [esi].INP_STAT.bNewLine, dl
    mov [esi].INP_STAT.bIfLevel, dh
    mov dl, [ebx].bSkipC
    mov dh, [ebx].bSkipScanPP
    mov [esi].INP_STAT.bSkipC, dl
    mov [esi].INP_STAT.bSkipScanPP, dh

    mov eax, esi
    lea edi, [eax].INP_STAT.bIfStructure
    lea esi, [ebx].bIfStructure
    mov ecx, MAX_IF_LEVEL/sizeof(DWORD)
    rep movsd

    lea edi, [eax].INP_STAT.bIfResult
    lea esi, [ebx].bIfResult
    mov ecx, MAX_IF_LEVEL/sizeof(DWORD)
    rep movsd

    lea edi, [eax].INP_STAT.bIfHistory
    lea esi, [ebx].bIfHistory
    mov ecx, MAX_IF_LEVEL/sizeof(DWORD)
    rep movsd
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:    IncFile.ShowError
; Purpose:   Shows an error condition.
; Arguments: Arg1: -> Format String.
;            Arg2-n: Format arguments
; Return:    Nothing.

Method IncFile.ShowError, uses ebx edi, pFormat:PSTRINGA, Args:vararg
    local cBuffer[1024]:CHR

    SetObject ebx
    lea edi, cBuffer
    invoke sprintf, edi, $OfsCStrA("%s(%u): Error - "), [ebx].pFileName, [ebx].dLineNbr
    lea edx, [edi + eax]
    lea ecx, [pFormat + sizeof(PSTRINGA)]
    invoke vsprintf, edx, pFormat, ecx
    invoke printf, $OfsCStrA("%s", LF), edi
    inc [ebx].dErrors

    if DEBUGGING
      DbgSaveContext TRUE, edi                   ;ebx = edi
      DbgSetDestWnd "Output"
      invoke DbgOutTextA, ebx, DbgColorError, DbgColorBackground, DBG_EFFECT_NEWLINE, ??DbgDstWnd
      DbgLoadContext
    endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:    IncFile.ShowWarning
; Purpose:   Shows a warning condition.
; Arguments: Arg1: -> Format String.
;            Arg2-n: Format arguments
; Return:    Nothing.

Method IncFile.ShowWarning, uses ebx edi, pFormat:PSTRINGA, Args:vararg
    local cBuffer[1024]:CHR

    SetObject ebx
    lea edi, cBuffer
    invoke sprintf, edi, $OfsCStrA("%s(%u): Warning - "), [ebx].pFileName, [ebx].dLineNbr
    lea edx, [edi + eax]
    lea ecx, [pFormat + sizeof(PSTRINGA)]
    invoke vsprintf, edx, pFormat, ecx
    invoke printf, $OfsCStrA("%s", LF), edi
    inc [ebx].dWarnings

    if DEBUGGING
      DbgSaveContext TRUE, edi                   ;ebx = edi
      DbgSetDestWnd "Output"
      invoke DbgOutTextA, ebx, DbgColorWarning, DbgColorBackground, DBG_EFFECT_NEWLINE, ??DbgDstWnd
      DbgLoadContext
    endif
MethodEnd

endif
