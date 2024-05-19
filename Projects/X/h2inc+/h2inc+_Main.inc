; ==================================================================================================
; Title:      h2inc+_Main.inc
; Author:     G. Friedrich
; Version:    See h2inc+.asm
; Purpose:    ObjAsm main code.
; ==================================================================================================


.code

; ==================================================================================================
;    Application implementation
; ==================================================================================================

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Application.Done
; Purpose:    Finalize the Application object.
; Arguments:  None.
; Return:     Nothing.

Method Application.Done, uses xbx xsi
  SetObject xbx

  .if [xbx].bTerminate == FALSE
    ;Save new content lists only
    OCall xbx.ShowInfo, VERBOSITY_NORMAL, $OfsCStr("Saving new lists...")
    lea xsi, NewContentLists
;    OCall xbx.ShowInfo, VERBOSITY_NORMAL, $OfsCStr("Saving all lists...")
;    lea xsi, KnownContentLists                          ;Uncomment to save all lists
    .while POINTER ptr [xsi] != NULL
      .if [xsi].LIST_SETUP.pFileName != NULL
        OCall [xsi].LIST_SETUP.pList::List.SaveToFile, [xsi].LIST_SETUP.pFileName
      .endif
      Destroy [xsi].LIST_SETUP.pList::List.Done
      add xsi, sizeof(LIST_SETUP)
    .endw
  .endif

  OCall xbx.ShowInfo, VERBOSITY_DEAFENING, $OfsCStr("Housekeeping...")
  OCall [xbx].MemHeap::MemoryHeap.Done
  OCall [xbx].IniReader::IniFileReader.Done
  OCall [xbx].SearchPathColl::StrCollectionW.Done
  OCall [xbx].ProcessedFiles::SortedStrCollectionW.Done

  MemFree [xbx].pCL_Args
  MemFree [xbx].pEV_Args

  OCall xbx.ShowInfo, VERBOSITY_NORMAL, $OfsCStr("Program exit")
;  invoke Sleep, 5000
  ACall xbx.Done
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Application.GetOption
; Purpose:    Process a single option.
; Arguments:  Arg1: -> WIDE Argument comming from commandline.
; Return:     eax: TRUE if succeeded, otherwise FALSE.

Method Application.GetOption, uses xbx xdi xsi, pArgument:PSTRINGW
  SetObject xbx
  mov xsi, pArgument
  mov ax, [xsi]
  .if ax == "/" || ax == "-"
    movzx ecx, CHRW ptr [xsi + sizeof(CHRW)]
    lea xdi, CmdLineSwitchTable
    .while TRUE
      movzx eax, [xdi].CMDLINE_SWITCH_ENTRY.wSwitch
      test eax, eax                                     ;Table end marker
      je @@EOM
      .break .if ecx == eax
      add xdi, sizeof(CMDLINE_SWITCH_ENTRY)
    .endw

    mov xdx, [xdi].CMDLINE_SWITCH_ENTRY.xOffset
    lea xcx, [xbx].Options
    add xdx, xcx

    .if [xdi].CMDLINE_SWITCH_ENTRY.bType == CLS_IS_BOOL
      mov BYTE ptr [xdx], TRUE
      mov eax, TRUE
    .elseif [xdi].CMDLINE_SWITCH_ENTRY.bType == CLS_IS_BIT
      movzx ecx, CHRW ptr [xsi + 2*sizeof(CHRW)]
      sub ecx, "0"
      mov eax, 1
      shl eax, cl
      or DWORD ptr [xdx], eax
      mov eax, TRUE
    .elseif [xdi].CMDLINE_SWITCH_ENTRY.bType == CLS_IS_CHAR
      m2m CHRW ptr [xdx], [xsi + 2*sizeof(CHRW)], cx
    .elseif [xdi].CMDLINE_SWITCH_ENTRY.bType == CLS_IS_NUMBER
      movzx ecx, CHRW ptr [xsi + 2*sizeof(CHRW)]
      sub ecx, "0"
      mov DWORD ptr [xdx], ecx
      mov eax, TRUE
    .elseif [xdi].CMDLINE_SWITCH_ENTRY.bType == CLS_IS_STRING
      mov xdi, xdx
      lea xsi, [xsi + 2*sizeof(CHRW)]
      invoke PathUnquoteSpacesW, xsi
      OCall [xbx].MemHeap::MemoryHeap.AddStrW, xsi
      mov POINTER ptr [xdi], xax
      mov eax, TRUE
    .else
      xor eax, eax
    .endif
  .else
    xor eax, eax
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Application.GetOptions
; Purpose:    Scan argument list for options.
; Arguments:  Arg1: -> WIDE Argument list.
;             Arg2: First argument from the list to start with.
;             Arg3: Number of arguments in the ArgList.
;             Arg4: -> Source Text.
; Return:     eax: TRUE if succeeded, otherwise FALSE.

Method Application.GetOptions, uses xbx xdi xsi, pArgList:POINTER, dStart:DWORD, dCount:DWORD, \
                                                 pSource:PSTRING
  local cMessage[1024]:CHR

  SetObject xbx
  mov edi, dStart
  mov xsi, pArgList
  .while edi < dCount
    mov xdx, PSTRINGW ptr [xsi + xdi*sizeof(PSTRINGW)]
    OCall xbx.GetOption, xdx
    .if eax == FALSE
      lea eax, [edi + 1]
      .if eax == dCount                                 ;Last argument?
        mov xsi, [xsi + xdi*sizeof(PSTRINGW)]
        invoke PathUnquoteSpacesW, xsi
        OCall [xbx].MemHeap::MemoryHeap.AddStrW, xsi
        mov [xbx].pFilespec, xax
      .else
        ReleaseObject
        mov xbx, PSTRINGW ptr [xsi + xdi*sizeof(PSTRINGW)]
        lea xsi, cMessage
        WriteF xsi, "Incorrect parameter #¦UD in \`¦ST\`: ¦SU", eax, pSource, xbx
        SetObject xbx
        OCall xbx.ShowError, addr cMessage
        mov [xbx].Options.bShowUsage, TRUE
        mov [xbx].bTerminate, TRUE
        xor eax, eax
        jmp @@EOM
      .endif
    .endif
    inc edi
  .endw
  mov eax, TRUE
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Application.Init
; Purpose:    Initialize the SDI application object.
;             - Read profile file
;             - Read command line arguments
; Arguments:  None.
; Return:     Nothing.

.code
Method Application.Init, uses xbx xdi xsi
  local cMessage[1024]:CHR, hFile:HANDLE, dBytesRead:DWORD
  local dArgCount:DWORD, LocTime:SYSTEMTIME, cFullSearchPath[MAX_PATH]:CHRW
  local cReadBuffer[1024]:CHRA, cEnvVar[1024]:CHRW

  SetObject xbx
  ACall xbx.Init, NULL

  OCall xbx.ShowInfo, VERBOSITY_NORMAL, $OfsCStr("Initializing...")

  invoke GetSystemTime, addr LocTime                    ;Get conversion time for all files
  lea xdi, [xbx].cIncCreationTime
  WriteFA xdi, "¦BN¦UW/¦BN¦UW/¦BN¦UW ¦BN¦UW:¦BN¦UW:¦BN¦UW", \
               <<<PrependZerosA(LocTime.wDay, 2)>>>,    LocTime.wDay, \
               <<<PrependZerosA(LocTime.wMonth, 2)>>>,  LocTime.wMonth, \
               <<<PrependZerosA(LocTime.wYear, 4)>>>,   LocTime.wYear, \
               <<<PrependZerosA(LocTime.wHour, 2)>>>,   LocTime.wHour, \
               <<<PrependZerosA(LocTime.wMinute, 2)>>>, LocTime.wMinute, \
               <<<PrependZerosA(LocTime.wSecond, 2)>>>, LocTime.wSecond, \

  OCall [xbx].MemHeap::MemoryHeap.Init, xbx, 1000000h, 100000h    ;Grab 10MB
  .if [xbx].MemHeap.dErrorCode != OBJ_OK
    mov [xbx].bTerminate, TRUE
  .endif

  OCall [xbx].IniReader::IniFileReader.Init, xbx, addr [xbx].MemHeap
  OCall [xbx].SearchPathColl::StrCollectionW.Init, xbx, 10, 10, 0FFFFFFFFh/sizeof(PSTRINGW)
  OCall [xbx].ProcessedFiles::SortedStrCollectionW.Init, xbx, 500, 100, 0FFFFFFFFh/sizeof(PSTRINGW)

  cmp [xbx].bTerminate, FALSE
  jne @@EOM

  OCall xbx.ShowInfo, VERBOSITY_NORMAL, $OfsCStr("Reading program arguments...")
  ;Get CL arguments ---------------------------------------------------------------------
  mov xax, $invoke(GetCommandLine)
;  mov xax, $OfsDStrW('h2inc+.exe -@".\h2inc+_Options.txt"')
  OCall xbx.ParseArguments, xax
  mov [xbx].pCL_Args, xax
  mov dArgCount, ecx
  .if ecx == 1
    mov [xbx].Options.bShowUsage, TRUE
    mov [xbx].bTerminate, TRUE
    jmp @@EOM
  .endif

;  ;Show me all commandline arguments
;  test ecx, ecx
;  .while !ZERO?
;    DbgStrW POINTER ptr [xax], "Show CL Arguments"
;    add xax, sizeof(POINTER)
;    dec ecx
;  .endw

  OCall xbx.GetOptions, [xbx].pCL_Args, 1, dArgCount, $OfsCStr("command line")
  test eax, eax
  jz @@EOM

  ;Get EV arguments ---------------------------------------------------------------------
  mov CHR ptr cEnvVar, 0
  .if [xbx].Options.pEnvVar != NULL
    invoke GetEnvironmentVariableW, [xbx].Options.pEnvVar, addr cEnvVar, lengthof(cEnvVar)
    .if eax == 0
      invoke CreateFileW, [xbx].Options.pEnvVar, GENERIC_READ, FILE_SHARE_READ, NULL, \
                          OPEN_EXISTING, FILE_ATTRIBUTE_ARCHIVE, 0
      .if xax == INVALID_HANDLE_VALUE
        DbgApiError
        lea xsi, cMessage
        WriteF xsi, "parameter source \`¦SU\` not found", [xbx].Options.pEnvVar
        OCall xbx.ShowWarning, WARNING_MAX, addr cMessage
        jmp @F
      .endif
      mov hFile, xax
      invoke ReadFile, hFile, addr cReadBuffer, sizeof(cReadBuffer), addr dBytesRead, NULL
      invoke CloseHandle, hFile
      .if dBytesRead == sizeof(cReadBuffer)
        lea xsi, cMessage
        WriteF xsi, "file \`¦SU\` too large, additional parameters skipped", \
               [xbx].Options.pEnvVar
        OCall xbx.ShowWarning, WARNING_MAX, addr cMessage
        jmp @F
      .endif
      mov eax, dBytesRead
      lea xcx, cReadBuffer
      m2z CHRA ptr [xcx + xax]                          ;Set ZTC
      invoke StrA2StrW, addr cEnvVar, addr cReadBuffer
    .elseif eax == lengthof(cEnvVar) - 1                ;Exclude ZTC
      WriteF xsi, "environment variable \`¦SU\` too large, additional parameters skipped", \
             [xbx].Options.pEnvVar
      OCall xbx.ShowWarning, WARNING_MAX, addr cMessage
      jmp @F
    .endif
  .endif
  OCall xbx.ParseArguments, addr cEnvVar
  mov [xbx].pEV_Args, xax
  mov dArgCount, ecx

;  ;Show me all Environment Variable arguments
;  test ecx, ecx
;  .while !ZERO?
;    DbgStrW POINTER ptr [xax], "Show EV-Arguments"
;    add xax, sizeof(POINTER)
;    dec ecx
;  .endw

  OCall xbx.GetOptions, [xbx].pEV_Args, 0, dArgCount, [xbx].Options.pEnvVar
  test eax, eax
  jz @@EOM

@@:
  ;Check Filespec
  .if [xbx].pFilespec == NULL
    lea xsi, cMessage
    OCall xbx.ShowError, $OfsCStr("filespec missing")
    mov [xbx].Options.bShowUsage, TRUE
    mov [xbx].bTerminate, TRUE
    jmp @@EOM
  .endif

  ;Get all include directories and store them in SearchPathColl
  .if [xbx].Options.pIncludeDirs != NULL
    ;Split the list
    mov xsi, [xbx].Options.pIncludeDirs
    .while TRUE
      invoke StrLScanW, xsi, ','                        ;Left scan
      .if xax != NULL                                   ;No more commas
        m2z CHRW ptr [xax]                              ;Set ZTC
        lea xdi, [xax + sizeof(CHRW)]                   ;Move to next StringW
      .else
        xor edi, edi
      .endif
      invoke StrLRTrimW, xsi, xsi
      .if CHRW ptr [xsi] != 0
        invoke GetFullPathNameW, xsi, lengthof(cFullSearchPath), addr cFullSearchPath, NULL
        invoke FileExistW, addr cFullSearchPath
        .if eax == FALSE
          lea xsi, cMessage
          WriteF xsi, "Include directory \`¦SU\` doesn\´t exist, continue without it?", \
                 addr cFullSearchPath
          OCall xbx.ShowQuestion, addr cMessage
          .if eax != 'Y'
            mov [xbx].bTerminate, TRUE
            jmp @@EOM
          .endif
        .else
          invoke StrNewW, addr cFullSearchPath
          OCall [xbx].SearchPathColl::StrCollectionW.Insert, xax
        .endif
      .endif
      .break .if xdi == NULL
      mov xsi, xdi
    .endw
  .endif
@@:
;  ;Show me all include directories
;  .ColForEach [xbx].SearchPathColl, edi
;    DbgStrW xax
;  .ColNext

  ;Check the Output directory
  invoke GetFullPathNameW, [xbx].Options.pOutDir, MAX_PATH, addr [xbx].cOutputDir, NULL
  invoke FileExistW, addr [xbx].cOutputDir
  .if xax == FALSE
    lea xdi, cMessage
    WriteF xdi, "Output directory \`¦SU\` doesn\´t exist", addr [xbx].cOutputDir
    OCall xbx.ShowError, addr cMessage
    mov [xbx].bTerminate, TRUE
    jmp @@EOM
  .endif

  ;Load the lists
  lea xsi, KnownContentLists
  .if [xbx].Options.bLoadLists == FALSE
    OCall xbx.ShowInfo, VERBOSITY_NORMAL, $OfsCStr("Loading ini-file lists...")
    .while POINTER ptr [xsi] != NULL
      .if [xsi].LIST_SETUP.pList == NULL
        mov [xsi].LIST_SETUP.pList, $New(List)      ;Create the list
        OCall xax::List.Init, NULL, [xsi].LIST_SETUP.dAlloc, \
                                    [xsi].LIST_SETUP.dIncr, [xsi].LIST_SETUP.dFlags
      .endif
      .ifBitSet [xsi].LIST_SETUP.dFlags, CF_KNW
        OCall [xbx].IniReader::IniFileReader.LoadList, xsi
        .if eax == FALSE
          OCall xbx.ShowError, $OfsCStr(".ini-file corrupt")
          mov [xbx].bTerminate, TRUE
          jmp @@EOM
        .endif
      .endif
      add xsi, sizeof(LIST_SETUP)
    .endw
  .else
    OCall xbx.ShowInfo, VERBOSITY_NORMAL, $OfsCStr("Loading file lists...")
    .while POINTER ptr [xsi] != NULL
      .if [xsi].LIST_SETUP.pList == NULL
        mov [xsi].LIST_SETUP.pList, $New(List)      ;Create the list
        OCall xax::List.Init, NULL, [xsi].LIST_SETUP.dAlloc, \
                                    [xsi].LIST_SETUP.dIncr, [xsi].LIST_SETUP.dFlags
      .endif
      OCall [xsi].LIST_SETUP.pList::List.LoadFromFile, [xsi].LIST_SETUP.pFileName
      .if eax == FALSE
        lea xdi, cMessage
        WriteF xdi, "list file \`¦SU\`corrupt", [xsi].LIST_SETUP.pFileName
        OCall xbx.ShowError, addr cMessage
        mov [xbx].bTerminate, TRUE
        jmp @@EOM
      .endif
      add xsi, sizeof(LIST_SETUP)
    .endw
  .endif

; ### Merge the lists ###
;  ;Load the lists
;  lea xsi, PersistConvTable
;  OCall xbx.ShowInfo, VERBOSITY_NORMAL, $OfsCStr("Loading ini-file lists...")
;  .while POINTER ptr [xsi] != NULL
;    .if [xsi].LIST_SETUP.pList == NULL
;      mov [xsi].LIST_SETUP.pList, $New(List)      ;Create the list
;      OCall xax::List.Init, NULL, [xsi].LIST_SETUP.dAlloc, \
;                                  [xsi].LIST_SETUP.dIncr, [xsi].LIST_SETUP.dFlags
;    .endif
;    .ifBitSet [xsi].LIST_SETUP.dFlags, CF_KNW
;      OCall [xbx].IniReader::IniFileReader.LoadList, xsi
;      .if eax == FALSE
;        OCall xbx.ShowError, $OfsCStr(".ini-file corrupt")
;        mov [xbx].bTerminate, TRUE
;        jmp @@EOM
;      .endif
;    .endif
;    add xsi, sizeof(LIST_SETUP)
;  .endw
;
;  lea xsi, PersistConvTable
;  OCall xbx.ShowInfo, VERBOSITY_NORMAL, $OfsCStr("Loading file lists...")
;  .while POINTER ptr [xsi] != NULL
;    .if [xsi].LIST_SETUP.pList == NULL
;      mov [xsi].LIST_SETUP.pList, $New(List)      ;Create the list
;      OCall xax::List.Init, NULL, [xsi].LIST_SETUP.dAlloc, \
;                                  [xsi].LIST_SETUP.dIncr, [xsi].LIST_SETUP.dFlags
;    .endif
;    OCall [xsi].LIST_SETUP.pList::List.LoadFromFile, [xsi].LIST_SETUP.pFileName
;    .if eax == FALSE
;      lea xdi, cMessage
;      WriteF xdi, "list file \`¦SU\`corrupt", [xsi].LIST_SETUP.pFileName
;      OCall xbx.ShowError, addr cMessage
;      mov [xbx].bTerminate, TRUE
;      jmp @@EOM
;    .endif
;    add xsi, sizeof(LIST_SETUP)
;  .endw

  ;If no dSelectiveOutput is marked, all are selected
  .if [xbx].Options.dSelectiveOutput == 0
    mov [xbx].Options.dSelectiveOutput, -1
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Application.ParseArguments
; Purpose:    Parse a WIDE CL-string and return an array of PSTRINGW to the command line arguments,
;             along with a count of such arguments. Delimiters are white chars or CRLF.
; Arguments:  Arg1: -> Input WIDE string.
; Return:     xax -> Array of PSTRINGWs.
;             ecx = Argument count.
; Note:       1. Mermory allocated to hold the PSTRINGWs must be freed using MemFree.
;             2. Arguments that are followed by an quoted string are retuned with the opening quote
;                and the closing quote removed.

Method Application.ParseArguments, uses xbx xdi xsi, pArgumentStringW:PSTRINGW
.const
JumpTable label POINTER
  POINTER offset @@1
  POINTER offset @@2
  POINTER offset @@3
  POINTER offset @@4
  POINTER offset @@5

.code
  MemAlloc 1024
  mov xsi, pArgumentStringW
  xor ebx, ebx                                          ;Argument Count
  mov edx, 1                                            ;Statemachine step

@@0:
  lea xdi, JumpTable
  mov cx, CHRW ptr [xsi]
  cmp cx, 0
  je @@9
  jmp POINTER ptr [xdi + xdx*sizeof(POINTER) - sizeof(POINTER)]

@@1:
  .if cx == SPC || cx == TAB || cx == LF || cx == CR  ;Start search
    add xsi, sizeof(CHRW)
    jmp @@0
  .endif
  mov edx, 2
  jmp @@0

@@2:
  push xsi                                              ;Save start address
  inc ebx
  mov edx, 3
  jmp @@0

@@3:
  .if cx == '"'                                         ;Opening quote
    add xsi, sizeof(CHRW)                               ;Skip the quote
    mov edx, 4
    jmp @@0
  .elseif cx == SPC || cx == TAB || cx == LF || cx == CR
    mov edx, 5
    jmp @@0
  .endif
  add xsi, sizeof(CHRW)
  jmp @@0

@@4:
  .if cx == '"'                                         ;Search closing quote
    add xsi, sizeof(CHRW)                               ;Skip the quote
    mov edx, 5
    jmp @@0
  .endif
  add xsi, sizeof(CHRW)                                 ;Skip the quote
  jmp @@0

@@5:
  mov CHRW ptr [xsi], 0                                 ;ZTC
  add xsi, sizeof(CHRW)
  mov edx, 1                                            ;Start again
  jmp @@0

@@9:
  mov ecx, ebx
  test ecx, ecx
  .while !ZERO?
    pop xdx
    mov PSTRINGW ptr [xax + xcx*sizeof(PSTRINGW) - sizeof(PSTRINGW)], xdx
    dec ecx
  .endw
  mov ecx, ebx                                          ;Return argument count in ecx
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Application.ProcessFile
; Purpose:    Process a single .h file
; Arguments:  Arg1: -> FileName.
;             Arg2: -> Parent IncFile that calls ProcessFile due to an "include" PP command.
; Return:     eax = TRUE if succeded, otherwise FALSE.

ITF_SKIPPED     equ   0
ITF_NOT_FOUND   equ   1
ITF_JUST_PROC   equ   2
ITF_REPROC      equ   3

Method Application.ProcessFile, uses xbx xdi xsi, \
                      pHeaderFilePath: PSTRINGW, pHeaderFileName:PSTRINGW, pParent:$ObjPtr(IncFile)
  local IncludeFile:$Obj(IncFile), dResult:DWORD, cMessage[1024]:CHR
  local cHeaderFullFileName[MAX_PATH]:CHRW, cIncludeFullFileName[MAX_PATH]:CHRW
  local cSearchFullFileName[MAX_PATH]:CHRW

  SetObject xbx

;if DEBUGGING
;  DbgSaveContext
;  DbgSetDestWnd "Include Tree"
;  mov ecx, [xbx].dIncNestingLevel
;  lea xdi, cMessage
;  .if SDWORD ptr ecx <= 0                               ;Just in case something goes wrong
;    mov [xbx].dIncNestingLevel, 0
;  .else
;    WriteFW xdi, "\n"
;    shl ecx, 1
;    mov ax, SPC
;    rep stosw                                           ;Indentation
;  .endif
;  WriteFW xdi, "¦SU", pHeaderFileName
;  invoke DbgOutTextW, addr cMessage, DbgColorForeground, DbgColorBackground, \
;                      DBG_EFFECT_NORMAL, ??DbgDstWnd
;  DbgLoadContext
;  inc [xbx].dIncNestingLevel
;endif

  ;Locate the file ----------------------------------------------------------------------
  mov dResult, FALSE
  invoke PathCombineW, addr cHeaderFullFileName, pHeaderFilePath, pHeaderFileName
  invoke FileExistW, addr cHeaderFullFileName
  .if eax == FALSE
    ;Try to find the file in all search paths
    .ColForEach [xbx].SearchPathColl, edi
      invoke StrECopyW, addr cSearchFullFileName, xax   ;xax -> ZTC
      .if CHRW ptr [xax - sizeof(CHRW)] != '\'
        mov CHRW ptr [xax], '\'
        add xax, sizeof(CHRW)
      .endif
      invoke StrCopyW, xax, pHeaderFileName
      invoke FileExistW, addr cSearchFullFileName
      .if eax != FALSE
        invoke StrCopyW, addr cHeaderFullFileName, addr cSearchFullFileName
        .break
      .endif
    .ColNext

    .if edi == [xbx].SearchPathColl.dCount              ;Not found => show message
      lea xdi, cMessage
      WriteF xdi, "Warning: the header file \`¦SU\`", addr cHeaderFullFileName
      .if pParent != NULL
        mov xsi, pParent
        WriteF xdi, " included from file \`¦SU\` at line ¦UD", \
               addr cHeaderFullFileName, [xsi].$Obj(IncFile).dLineNumber
      .endif
      WriteF xdi, " could not be found"
      OCall xbx.ShowInfo, VERBOSITY_NORMAL, addr cMessage
      mov dResult, FALSE
      mov ecx, ITF_NOT_FOUND
      jmp @F
    .endif
  .endif

  ;Don't process files more than once ---------------------------------------------------
  invoke StrLowerW, addr cHeaderFullFileName            ;Convert to LC to avoid case sensitivity
  OCall [xbx].ProcessedFiles::SortedStrCollectionW.Search, addr cHeaderFullFileName
  .if eax == FALSE                                      ;Not found in the list!
    invoke StrNewW, addr cHeaderFullFileName
    OCall [xbx].ProcessedFiles::SortedStrCollectionW.Insert, xax

    lea xdi, cMessage
    .if pParent != NULL
      mov xsi, pParent
      WriteF xdi, "¦SU(¦UD): ", \
             [xsi].$Obj(IncFile).pHeaderFileName, \
             [xsi].$Obj(IncFile).dLineNumber
    .endif
;    WriteF xdi, "Include header file \`¦SU\`", addr cHeaderFullFileName
;    OCall xbx.ShowInfo, VERBOSITY_IMPORTANT, addr cMessage

    ;Create output FileName
    lea xdi, cIncludeFullFileName
    WriteFW xdi, "¦SU\\¦SU", \
            addr [xbx].cOutputDir, \
            pHeaderFileName
    invoke StrRScanW, addr cIncludeFullFileName, "."
    .if xax == NULL
      invoke StrEndW, addr cIncludeFullFileName
    .endif
    FillStringW [xax], <.inc>

    ;Check if output inc-file already exists --------------------------------------------
    .if [xbx].Options.bOverwrite == FALSE
      invoke FileExistW, addr cIncludeFullFileName
      .if eax != FALSE                                    ;File alread exists!
        .if [xbx].Options.bBatchmode != FALSE
          .if [xbx].Options.dWarningLevel >= MAX_WARNING_LEVEL
            lea xdi, cMessage
            .if pParent != NULL
              mov xsi, pParent
              WriteF xdi, "¦SU(¦UD): ", \
                     [xsi].$Obj(IncFile).pHeaderFileName, \
                     [xsi].$Obj(IncFile).dLineNumber
            .endif
            WriteF xsi, "\`¦SU\` file already exists, file \`¦SU\` skipped", \
                   addr cIncludeFullFileName, \
                   addr cHeaderFullFileName
            OCall xbx.ShowInfo, VERBOSITY_NORMAL, addr cMessage
          .endif
        .else
          lea xdi, cMessage
          WriteF xdi, "File \`¦SU\` already exists, overwrite it?", \
                 addr cIncludeFullFileName
          OCall xbx.ShowQuestion, addr cMessage
          .if eax == "C"
            mov [xbx].bTerminate, TRUE
            mov dResult, FALSE
            mov ecx, ITF_SKIPPED
            jmp @F
          .elseif eax == "N"
            lea xdi, cMessage
            WriteF xdi, "File \`¦SU\` not processed.", \
                   addr cHeaderFullFileName
            OCall xbx.ShowInfo, VERBOSITY_DEAFENING, addr cMessage
            mov dResult, FALSE
            mov ecx, ITF_SKIPPED
            jmp @F
          .endif
        .endif
      .endif
    .endif

    ;Initialize an IncFile local instance -----------------------------------------------
    New IncludeFile::IncFile
;    DbgStrW cHeaderFullFileName,, "Rendered Files"
    OCall IncludeFile::IncFile.Init, xbx, addr cHeaderFullFileName, pParent
    .if eax != FALSE
      ;Start real processing
      OCall IncludeFile::IncFile.ParseHeaderFile
      OCall IncludeFile::IncFile.Render
      OCall IncludeFile::IncFile.Save, addr cIncludeFullFileName  ;Save include file
      mov dResult, eax
      OCall IncludeFile::IncFile.CreateDefFile, addr cIncludeFullFileName
;      if DEBUGGING
;        DbgSaveContext
;        DbgSetDestWnd "Include Tree"
;        invoke DbgOutTextA, $OfsCStrA(" "), DbgColorForeground, DbgColorBackground, \
;                            0, ??DbgDstWnd
;        DbgLoadContext
;      endif
    .else
      mov dResult, FALSE
;      if DEBUGGING
;        DbgSaveContext
;        DbgSetDestWnd "Include Tree"
;        .if ecx == ITF_SKIPPED
;          mov xcx, $OfsCStrA(" - Skipped by user")
;          invoke DbgOutTextA, xcx, DbgColorGreen, DbgColorBackground, \
;                              DBG_EFFECT_NORMAL, ??DbgDstWnd
;        .elseif ecx == ITF_NOT_FOUND
;          mov xcx, $OfsCStrA(" - not found")
;          invoke DbgOutTextA, xcx, DbgColorRed, DbgColorBackground, \
;                              DBG_EFFECT_NORMAL, ??DbgDstWnd
;        .elseif ecx == ITF_JUST_PROC
;          mov xcx, $OfsCStrA(" - already processed")
;          invoke DbgOutTextA, xcx, DbgColorBlue, DbgColorBackground, \
;                              DBG_EFFECT_NORMAL, ??DbgDstWnd
;        .elseif ecx == ITF_REPROC
;          mov xcx, $OfsCStrA(" - reprocessed")
;          invoke DbgOutTextA, xcx, DbgColorForeground, DbgColorBackground, \
;                              DBG_EFFECT_NORMAL, ??DbgDstWnd
;        .else
;          mov xcx, $OfsCStrA("???")
;          invoke DbgOutTextA, xcx, DbgColorForeground, DbgColorBackground, \
;                              DBG_EFFECT_NORMAL, ??DbgDstWnd
;        .endif
;        DbgLoadContext
;      endif
    .endif
    OCall IncludeFile::IncFile.Done

;if DEBUGGING
;  .else
;    mov ecx, ITF_JUST_PROC
;@@:
;    DbgSaveContext
;    DbgSetDestWnd "Include Tree"
;    .if ecx == ITF_SKIPPED
;      mov xcx, $OfsCStrA(" - Skipped by user")
;      invoke DbgOutTextA, xcx, DbgColorGreen, DbgColorBackground, \
;                          DBG_EFFECT_NORMAL, ??DbgDstWnd
;    .elseif ecx == ITF_NOT_FOUND
;      mov xcx, $OfsCStrA(" - not found")
;      invoke DbgOutTextA, xcx, DbgColorRed, DbgColorBackground, \
;                          DBG_EFFECT_NORMAL, ??DbgDstWnd
;    .elseif ecx == ITF_JUST_PROC
;      mov xcx, $OfsCStrA(" - already processed")
;      invoke DbgOutTextA, xcx, DbgColorBlue, DbgColorBackground, \
;                          DBG_EFFECT_NORMAL, ??DbgDstWnd
;    .elseif ecx == ITF_REPROC
;      mov xcx, $OfsCStrA(" - reprocessed")
;      invoke DbgOutTextA, xcx, DbgColorForeground, DbgColorBackground, \
;                          DBG_EFFECT_NORMAL, ??DbgDstWnd
;    .else
;      mov xcx, $OfsCStrA("???")
;      invoke DbgOutTextA, xcx, DbgColorForeground, DbgColorBackground, \
;                          DBG_EFFECT_NORMAL, ??DbgDstWnd
;    .endif
;    DbgLoadContext
;else
@@:
;endif
  .endif

if DEBUGGING
  dec [xbx].dIncNestingLevel
endif
  mov eax, dResult
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Application.ProcessFiles
; Purpose:    Process all .h files in the current path.
; Arguments:  Arg1: -> FileSpec (e.g. C:\MyHeaderfiles\*.h).
; Return:     Nothing.

Method Application.ProcessFiles, uses xbx xdi xsi, pFileSpec:PSTRINGW
  local hFFHandle:HANDLE, cMessage[1024]:CHR
  local FindData:WIN32_FIND_DATAW, cFullFileSpec[MAX_PATH]:CHRW, pFilePart:PSTRINGW

  SetObject xbx
  ;GetFullPathName resolves the path using the current directory! Everything else is the FilePart
  invoke GetFullPathNameW, pFileSpec, lengthof(cFullFileSpec), addr cFullFileSpec, addr pFilePart
  invoke FindFirstFileW, pFileSpec, addr FindData
  .if xax != INVALID_HANDLE_VALUE
    mov hFFHandle, xax
    .repeat
      .if FindData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY

        .if DCHRW ptr FindData.cFileName == '.'
          jmp @F
        .elseif DCHRW ptr FindData.cFileName == ('.' shl 16 or '.') && \
                CHRW ptr FindData.cFileName[4] == 0
          jmp @F
        .endif

        .if [xbx].Options.bBatchmode == FALSE
          lea xsi, cMessage
          WriteF xsi, "\`¦SU\` is a directory, process all files in it?", addr FindData.cFileName
          OCall xbx.ShowQuestion, addr cMessage
        .else
          mov eax, 'Y'
        .endif

        .if eax == "C"
          mov [xbx].bTerminate, TRUE
        .elseif eax == 'Y'
          invoke StrRScanW, addr cFullFileSpec, "\"
          .if xax != NULL
            mov CHRW ptr [xax], 0
          .endif
          mov xdi, xax
          WriteFW xdi, "\¦SU\*.h", addr FindData.cFileName
          OCall xbx.ProcessFiles, addr cFullFileSpec
        .endif
        jmp @F
      .endif

      invoke StrRScanW, addr cFullFileSpec, "\"
      .if xax != NULL
        mov CHRW ptr [xax], 0
      .endif
      mov xdi, xax
      OCall xbx.ProcessFile, addr cFullFileSpec, addr FindData.cFileName, NULL

@@:
      .break .if [xbx].bTerminate != FALSE
      invoke FindNextFile, hFFHandle, addr FindData
    .until eax == 0

    invoke FindClose, hFFHandle
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Application.Run
; Purpose:    Execute the application.
;             Loop through all header files, calling ProcessFile for each one.
; Arguments:  None.
; Return:     Nothing.

Method Application.Run, uses xbx
  SetObject xbx
  .if [xbx].Options.bShowUsage == TRUE
    OCall xbx.SetColor, COLOR_HEADER
    OCall xbx.Print, addr cUsageHeader
    OCall xbx.SetColor, COLOR_REGULAR
    OCall xbx.Print, addr cUsageText
  .endif

  .if [xbx].bTerminate == FALSE
    OCall xbx.ProcessFiles, [xbx].pFilespec             ;<= analysis starts here
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:    Application.ShowError
; Purpose:   Shows a error message.
; Arguments: Arg1: -> Error Message.
; Return:    Nothing.

Method Application.ShowError, uses xbx xdi, pErrorMessage:PSTRING
  local cMessage[1024]:CHR

  SetObject xbx
  lea xdi, cMessage
  WriteF xdi, "Error: ¦ST\n", pErrorMessage

  OCall xbx.SetColor, COLOR_ERROR
  OCall xbx.Print, addr cMessage
  OCall xbx.SetColor, COLOR_REGULAR

;  if DEBUGGING
;    DbgSaveContext TRUE
;    DbgSetDestWnd "Output"
;    invoke DbgOutText, addr cMessage, DbgColorWarning, DbgColorBackground, 0, ??DbgDstWnd
;    DbgLoadContext
;  endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:    Application.ShowInfo
; Purpose:   Shows an info message.
; Arguments: Arg1: Verbosity Level [0..3].
;            Arg2: -> Info Message.
; Return:    Nothing.

Method Application.ShowInfo, uses xbx, dVerbosityLevel:DWORD, pInfoMessage:PSTRING
  SetObject xbx
  ?mov edx, dVerbosityLevel
  .if [xbx].Options.dVerbosityLevel >= edx
    OCall xbx.SetColor, COLOR_REGULAR
    OCall xbx.PrintLn, pInfoMessage

;    if DEBUGGING
;      DbgSaveContext TRUE
;      DbgSetDestWnd "Output"
;      invoke DbgOutText, pInfoMessage, DbgColorMessage, DbgColorBackground, \
;                         DBG_EFFECT_NEWLINE, ??DbgDstWnd
;      DbgLoadContext
;    endif
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:    Application.ShowQuestion
; Purpose:   Shows a question message and waits for an answer.
; Arguments: Arg1: -> Question message.
; Return:    al/ax = Answer character.

Method Application.ShowQuestion, uses xbx xdi, pQuestionText:PSTRING
  local cMessage[1024]:CHR

  SetObject xbx
  OCall xbx.SetColor, COLOR_QUESTION
  lea xdi, cMessage
  WriteF xdi, "¦ST [", pQuestionText
  OCall xbx.Print, addr cMessage
  OCall xbx.SetColor, COLOR_HEADER
  OCall xbx.Print, $OfsCStr("Y")
  OCall xbx.SetColor, COLOR_QUESTION
  OCall xbx.Print, $OfsCStr("]es, [")
  OCall xbx.SetColor, COLOR_HEADER
  OCall xbx.Print, $OfsCStr("N")
  OCall xbx.SetColor, COLOR_QUESTION
  OCall xbx.Print, $OfsCStr("]o, [")
  OCall xbx.SetColor, COLOR_HEADER
  OCall xbx.Print, $OfsCStr("C")
  OCall xbx.SetColor, COLOR_QUESTION
  OCall xbx.Print, $OfsCStr("]ancel ")
  .repeat
    OCall xbx.GetCharUC
  .until eax == 'Y' || eax == 'N' || eax == 'C'
  mov edi, eax                                          ;Save result
  mov DCHR ptr cMessage, $SubReg(eax, sizeof(DCHR))
  OCall xbx.SetColor, COLOR_HEADER
  OCall xbx.Print, addr cMessage
  OCall xbx.SetColor, COLOR_REGULAR
  FillQuotedString cMessage, CRLF
  OCall xbx.Print, addr cMessage
  mov eax, edi                                          ;Restore result
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:    Application.ShowWarning
; Purpose:   Shows a warning message.
; Arguments: Arg1: Warning Level [0..3].
;            Arg2: -> Warning Message.
; Return:    Nothing.

Method Application.ShowWarning, uses xbx xdi, dWarningLevel:DWORD, pWarningMessage:PSTRING
  local cMessage[1024]:CHR

  SetObject xbx
  ?mov edx, dWarningLevel
  .if [xbx].Options.dWarningLevel >= edx
    lea xdi, cMessage
    WriteF xdi, "Warning: ¦ST\n", pWarningMessage

    OCall xbx.SetColor, COLOR_WARNING
    OCall xbx.Print, addr cMessage
    OCall xbx.SetColor, COLOR_REGULAR

;    if DEBUGGING
;      DbgSaveContext TRUE
;      DbgSetDestWnd "Output"
;      invoke DbgOutText, addr cMessage, DbgColorWarning, DbgColorBackground, 0, ??DbgDstWnd
;      DbgLoadContext
;    endif
  .endif
MethodEnd
