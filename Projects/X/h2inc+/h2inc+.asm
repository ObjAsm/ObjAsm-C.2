; ==================================================================================================
; Title:      h2inc+.asm
; Author:     G. Friedrich
; Version:    C.2.0
; Purpose:    Creates MASM include files (.inc) from C header files (.h).
; Links:      http://masm32.com/board/index.php?topic=7006.msg75149#msg75149
;             C++ reference: https://en.cppreference.com/w/cpp
;             Std C: http://www.open-std.org/JTC1/SC22/WG14/www/docs/n1256.pdf
; Notes:      This is the continuation & further development of Japheth's open source h2incX
;             project.
;             Version B.1.0, June 2018
;               - First release.
;             Version C.1.0, September 2018
;               - Improvements:
;                 - Output syntax & and spacing management intoduced.
;                 - Output removal of: ";{", ";}", error & warning count, "#undef", etc.
;                 - Strategy change of @DefProto for x64.
;                 - Ini-File completion.
;                 - TypeC detection introduced.
;                 - Switches on WinAsm.inc set correctly.
;                 - Conditional sentence evaluation to skip code that can't be translated properly.
;                 - Ini-File completed.
;             Version C.2.0, April 2024
;               - Project renamed to h2inc+.
;               - Ported to dual bitness and ANSI/WIDE targets. WIDE is recommended.
;               - Improvements:
;                 - Support for multidimesional arrays added.
;                 - Record bit reversal added.
;                 - @ option added to specify additional options in an env. variable or in a file.
; ==================================================================================================

;void proto WIN_STD_CALL_CONV :ptr __RPC_USER
;          STD_METHOD Draw, :ptr IViewObject, :DWORD, :LONG, :ptr, :ptr DVTARGETDEVICE, :HDC, :HDC, :LPCRECTL, :LPCRECTL, :, :ULONG_PTR
;@DefProto DllImport, PtInRect, WIN_STD_CALL_CONV,, <:ptr RECT, :POINT>, 8  <--- 12
;STD_METHOD Draw, :ptr IViewObjectEx, :DWORD, :LONG, :ptr, :ptr DVTARGETDEVICE, :HDC, :HDC, :LPCRECTL, :LPCRECTL, :s_BITS s_REC <>, :ULONG_PTR
;SIZE_ ?  <-- <>

;          NMDATETIMEFORMATQUERYW struct
;            nmhdr NMHDR <>
;            pszFormat LPCWSTR ?
;            szMax SIZE_ ?   <-- <>
;          NMDATETIMEFORMATQUERYW ends

; TYPEKIND enum failed

;STD_METHOD ccc.Invoke_    dont replace Invoke

;@DefProto DllImport, SetFilePointerEx, WIN_STD_CALL_CONV,, <:HANDLE, :LARGE_INTEGER, :PLARGE_INTEGER, :DWORD>, 16    but should be 20

%include @Environ(OBJASM_PATH)\\Code\\Macros\\Model.inc
SysSetup OOP, CON64, WIDE_STRING, DEBUG(WND);, RESGUARD)
;SILENT=TRUE

% include &MacPath&fMath.inc

% include &IncPath&Windows\ShellApi.inc
% include &IncPath&Windows\shlwapi.inc
% include &IncPath&Windows\WinConTypes.inc

% includelib &LibPath&Windows\shell32.lib
% includelib &LibPath&Windows\shlwapi.lib

% include &MacPath&LDLL.inc
% include &MacPath&LSLL.inc

MakeObjects Primer, Stream, Collection, SortedCollection, StrCollectionA
MakeObjects SortedStrCollectionA, StrCollectionW, SortedStrCollectionW
MakeObjects ConsoleApp, StopWatch

PTOKEN  typedef ptr CHRA

include h2inc+_Shared.inc
include h2inc+_BStrA.inc
include h2inc+_Globals.inc
include h2inc+_List.inc
include h2inc+_MemoryHeap.inc

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Object:   IniFileReader
; Purpose:  Ini file reader.

Object IniFileReader, 0, Primer
  RedefineMethod  Done
  RedefineMethod  Init,         POINTER, $ObjPtr(MemoryHeap)
  StaticMethod    LoadList,     PLIST_SETUP

  DefineVariable  pMemBlock,    POINTER,  NULL
  DefineVariable  dMemSize,     DWORD,    0
  DefineVariable  pMemHeap,     $ObjPtr(MemoryHeap),    NULL
ObjectEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Object:   IncFile
; Purpose:  Handle all actions to generate an .inc file.

Object IncFile,, Primer
  StaticMethod    AddComment,         PSTRINGA
  StaticMethod    CreateDefFile,      PSTRINGW
  RedefineMethod  Done
  RedefineMethod  Init,               POINTER, PSTRINGW, $ObjPtr(IncFile)
  StaticMethod    InputStatusLoad,    P_INP_STAT
  StaticMethod    InputStatusSave,    P_INP_STAT
  StaticMethod    GetNextToken
  StaticMethod    GetNextTokenC
  StaticMethod    GetNextTokenLogicC
  StaticMethod    GetNextTokenPP
  StaticMethod    JumpEndIfPP
  StaticMethod    ParseHeaderFile
  StaticMethod    ParseHeaderLine,    PSTRINGA, DWORD
  StaticMethod    PeekNextTokenC
  StaticMethod    PeekNextTokenLogicC
  StaticMethod    Render
  StaticMethod    Save,               PSTRINGW
  StaticMethod    SkipComments,       PSTRINGA
  StaticMethod    StmCopyRestOfPPLine
  StaticMethod    StmSkipRestOfPPLine
  StaticMethod    StmDeleteLastSpace
  StaticMethod    StmWrite,           PSTRINGA
  StaticMethod    StmWriteChar,       CHRA
  StaticMethod    StmWriteComment
  StaticMethod    StmWriteError
  StaticMethod    StmWriteF,          PSTRINGA, ?
  StaticMethod    StmWriteEoL
  StaticMethod    StmWriteIndent
  StaticMethod    ShowError,          PSTRING, ?
  StaticMethod    ShowInfo,           DWORD, PSTRING, ?
  StaticMethod    ShowSysError,       PSTRING, DWORD
  StaticMethod    ShowWarning,        DWORD, PSTRING, ?

  DefineVariable  pStmBuffer1,        PSTRINGA, NULL    ;-> Input stream buffer (Token stream)
  DefineVariable  pStmBuffer2,        PSTRINGA, NULL    ;-> Header file & Output stream buffer
  DefineVariable  pStmInpPos,         PSTRINGA, NULL    ;-> Current input stream position
  DefineVariable  pStmOutPos,         PSTRINGA, NULL    ;-> Current output stream position
  DefineVariable  dErrorCount,        DWORD,    0       ;Errors occured in this file conversion
  DefineVariable  dWarningCount,      DWORD,    0       ;Warnings occured in this file conversion
  DefineVariable  pHeaderFileName,    PSTRINGW, NULL    ;-> File name (FileName.h)
  DefineVariable  pHeaderFilePath,    PSTRINGW, NULL    ;-> File path (C:\...)
  DefineVariable  pPrevToken,         PSTRINGA, NULL
  DefineVariable  pImportSpec,        PSTRINGA, NULL
  DefineVariable  pContainerName,     PSTRINGA, NULL    ;-> Current struct/union/class name
  DefineVariable  pCallConv,          PSTRINGA, NULL
  DefineVariable  pEndMacro,          PSTRINGA, NULL
  DefineVariable  pDefs,              $ObjPtr(List), NULL    ;-> .def file content
  DefineVariable  pParent,            $ObjPtr(IncFile), NULL ;-> Parent IncFile (if any)
  DefineVariable  CreationFileTime,   FILETIME, {}      ;Stores the creation FILETIME of .h file
  DefineVariable  LastWriteFileTime,  FILETIME, {}      ;Stores the last write FILETIME of .h file
  DefineVariable  dBlockLevel,        DWORD,    0       ;Block level where pEndMacro becomes active
  DefineVariable  dQualifiers,        DWORD,    0       ;Current qualifiers
  DefineVariable  dLineNumber,        DWORD,    0       ;Current line number
  DefineVariable  dEnumValue,         DWORD,    0       ;Counter for enums
  DefineVariable  dBraces,            DWORD,    0       ;Curly brackets count => Block deep
  DefineVariable  dIndentation,       DWORD,    0       ;Indentation level: 0..n
  DefineVariable  dStmOutEoL,         DWORD,    FALSE   ;StmOut line ended. It MUST be a DWORD!
  DefineVariable  dExternLinkage,     DWORD,    ELT_UNDEF   ;Extern linkage type
  DefineVariable  bSkipLineC,         BYTE,     FALSE   ;>0 => don't parse C lines in StmInp
  DefineVariable  bSkipLinePP,        BYTE,     FALSE   ;>0 => don't parse PP lines
  DefineVariable  bSkipCondPP,        BYTE,     FALSE   ;TRUE => don't parse conditional PP lines
  DefineVariable  bNewLine,           BYTE,     FALSE   ;Last token was a PCT_EOL
  DefineVariable  bComment,           BYTE,     FALSE   ;Comment flag for "/*" and "*/"
  DefineVariable  bUsePrevToken,      BYTE,     FALSE   ;GetNextTokenC returns pPrevToken
  DefineVariable  bInsideInterface,   BYTE,     FALSE   ;Inside an interface definition
  DefineVariable  bEnableNFCodeLabel, BYTE,     FALSE   ;Flag to avoid [...] repetitions (Non-Functional Code)
  DefineVariable  bCondIfLevel,       BYTE,     0       ;Current 'if' level
  DefineVariable  bCondElseLevel,     BYTE,     MAX_COND_LEVEL dup(0) ;Else stack
  DefineVariable  bCondResult,        BYTE,     MAX_COND_LEVEL dup(0) ;If result stack
  DefineVariable  bCondHistory,       BYTE,     MAX_COND_LEVEL dup(0) ;If history stack
  DefineVariable  bEOF,               BYTE,     FALSE
  DefineVariable  cComment,           CHRA,     1024 dup (0) ;Comment buffer

ObjectEnd


; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Object:   Application
; Purpose:  Main Application
; Notes:    - File and path names are handled using WIDE strings.
;           - Text is handled using ANSI strings.

Object Application, MyConsoleAppID, ConsoleApp          ;Console Interface App.
  RedefineMethod  Done
  StaticMethod    GetOption,          PSTRINGW
  StaticMethod    GetOptions,         POINTER, DWORD, DWORD, PSTRING
  RedefineMethod  Init
  StaticMethod    ParseArguments,     PSTRINGW
  StaticMethod    ProcessFile,        PSTRINGW, PSTRINGW, $ObjPtr(IncFile)
  StaticMethod    ProcessFiles,       PSTRINGW
  RedefineMethod  Run
  StaticMethod    ShowError,          PSTRING
  StaticMethod    ShowInfo,           DWORD, PSTRING
  StaticMethod    ShowQuestion,       PSTRING
  StaticMethod    ShowWarning,        DWORD, PSTRING

  DefineVariable  dTotalErrorCount,   DWORD,    0       ;Total errors occured in this session
  DefineVariable  dTotalWarningCount, DWORD,    0       ;Total warnings occured in this session
  DefineVariable  dRecordNameSuffix,  DWORD,    0       ;Added at the end of record and field names
  DefineVariable  dStrucNameSuffix,   DWORD,    0       ;Added at the end of DUMMYSTRUCTNAME/nameless
  DefineVariable  dUnionNameSuffix,   DWORD,    0       ;Added at the end of DUMMYUNIONNAME/nameless
  if DEBUGGING
  DefineVariable  dIncNestingLevel,   DWORD,    0
  endif
  DefineVariable  bTerminate,         BYTE,     FALSE   ;TRUE => terminate application as soon as possible

  DefineVariable  pFilespec,          PSTRINGW, NULL
  DefineVariable  cOutputDir,         CHRW,     MAX_PATH dup(0)

  DefineVariable  Options,            OPTIONS,  {}
  DefineVariable  pCL_Args,           POINTER,  NULL
  DefineVariable  pEV_Args,           POINTER,  NULL

  DefineVariable  cIncCreationTime,   CHRA,     24 dup(0) ;Creation time for all converted .h files

  Embed   MemHeap,          MemoryHeap                  ;Memory Pool (like a heap)
  Embed   IniReader,        IniFileReader               ;Ini-File Reader
  Embed   SearchPathColl,   StrCollectionW              ;Collection of additional include directories
  Embed   ProcessedFiles,   SortedStrCollectionW        ;Collection of processed files to avoid repetition

ObjectEnd

.code
include h2inc+_IniFileReader.inc
include h2inc+_Evaluator.inc
include h2inc+_IncFile_Mac.inc
include h2inc+_IncFile.inc
include h2inc+_IncFile_Proc.inc
include h2inc+_IncFile_Render.inc
include h2inc+_PPCHandler.inc                           ;Pre-Processor Command Handler
include h2inc+_Main.inc

.code
  
start proc uses xdi                                     ;Program entry point
  local cBuffer[50]:CHR

  SysInit
  ifndef SILENT
  DbgClearAll
  endif
  OCall $ObjTmpl(StopWatch)::StopWatch.Init, NULL
  s2s $ObjTmpl(StopWatch).r8Resolution, $CReal8(1000.0), xax, xcx   ;Resolution 1 ms

  OCall $ObjTmpl(StopWatch)::StopWatch.Start
  OCall $ObjTmpl(Application)::Application.Init         ;Initialize application
  OCall $ObjTmpl(Application)::Application.Run          ;Execute application

  OCall $ObjTmpl(StopWatch)::StopWatch.Stop
  .if $ObjTmpl(Application).Options.bShowUsage == FALSE
    ;Show session results
    OCall $ObjTmpl(StopWatch)::StopWatch.GetTime
    lea xdi, cBuffer
    WriteF xdi, "Runtime = ¦UX ms", xax
    OCall $ObjTmpl(Application)::Application.ShowInfo, VERBOSITY_IMPORTANT, addr cBuffer
    lea xdi, cBuffer
    WriteF xdi, "Errors = ¦UD", $ObjTmpl(Application).dTotalErrorCount
    OCall $ObjTmpl(Application)::Application.ShowInfo, VERBOSITY_IMPORTANT, addr cBuffer
    lea xdi, cBuffer
    WriteF xdi, "Warnings = ¦UD", $ObjTmpl(Application).dTotalWarningCount
    OCall $ObjTmpl(Application)::Application.ShowInfo, VERBOSITY_IMPORTANT, addr cBuffer
  .endif

  OCall $ObjTmpl(StopWatch)::StopWatch.Done
  OCall $ObjTmpl(Application)::Application.Done         ;Finalize application

  SysDone                                               ;Runtime finalization of the OOP model
  invoke ExitProcess, $ObjTmpl(Application).bTerminate  ;Exit returning the termination flag
start endp

end
