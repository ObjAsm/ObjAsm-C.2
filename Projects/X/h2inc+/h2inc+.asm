; ==================================================================================================
; Title:    h2inc+.asm
; Author:   G. Friedrich
; Version:  C.2.0
; Purpose:  Creates MASM include files (.inc) from C header files (.h).
; Links:    http://masm32.com/board/index.php?topic=7006.msg75149#msg75149
;           C++ reference: https://en.cppreference.com/w/cpp
;           Std C: http://www.open-std.org/JTC1/SC22/WG14/www/docs/n1256.pdf
; Notes:    This is the continuation & further development of Japheth's open source h2inc+ project.
;           Version B.1.0, June 2018
;             - First release.
;           Version C.1.0, September 2018
;             - Improvements:
;               - Output syntax & and spacing management intoduced.
;               - Removal of unnecessary output: ";{", ";}", error & warning count, "#undef", etc.
;               - Strategy change of @DefProto for x64.
;               - Ini-File completion.
;               - TypeC detection introduced.
;               - Switches on WinAsm.inc set correctly.
;               - Conditional sentence evaluation to skip code that can't be translated properly.
;               - Ini-File completed.
;           Version C.2.0, April 2024
;             - Project renamed to h2inc+.
;             - Ported to dual bitness.
; ==================================================================================================


%include @Environ(OBJASM_PATH)\\Code\\Macros\\Model.inc
SysSetup OOP, NUI64, WIDE_STRING, DEBUG(WND);, RESGUARD)

% include &IncPath&Windows\ShellApi.inc
% include &IncPath&Windows\shlwapi.inc
% include &IncPath&Windows\WinConTypes.inc

% includelib &LibPath&Windows\shell32.lib
% includelib &LibPath&Windows\shlwapi.lib

include h2inc+_Shared.inc
include h2inc+_BStrA.inc
include h2inc+_Globals.inc
% include &MacPath&LDLL.inc
% include &MacPath&LSLL.inc

MakeObjects Primer, Stream, Collection, SortedCollection, StrCollectionA
MakeObjects SortedStrCollectionA, StrCollectionW, SortedStrCollectionW 
MakeObjects ConsoleApp

include h2inc+_MemoryHeap.inc
include h2inc+_List.inc

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Object:   IniFileReader
; Purpose:  Ini file reader.

Object IniFileReader, 0, Primer
  RedefineMethod  Done
  RedefineMethod  Init,         POINTER, $ObjPtr(MemoryHeap)
  StaticMethod    LoadList,     PCONV_TAB_ENTRY

  DefineVariable  pMemBlock,    POINTER,  NULL
  DefineVariable  dMemSize,     DWORD,    0
  DefineVariable  pMemHeap,     $ObjPtr(MemoryHeap),    NULL
ObjectEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Object:   IncFile
; Purpose:  Handle all actions to generate an .inc file.

Object IncFile,, Primer
  StaticMethod    Analyse
  StaticMethod    CreateDefFile,      PSTRINGW
  RedefineMethod  Done
  RedefineMethod  Init,               POINTER, PSTRINGW, $ObjPtr(IncFile)
  StaticMethod    GetNextToken
  StaticMethod    GetNextTokenFromPPLine
  StaticMethod    PeekNextToken
  StaticMethod    ParseHeaderFile
  StaticMethod    ParseHeaderLine,    PSTRINGA, DWORD
  StaticMethod    Save,               PSTRINGW
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
  StaticMethod    ShowError,          PSTRING, ?
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
  DefineVariable  dStmOutEOL,         DWORD,    FALSE   ;StmOut line ended. It MUST be a DWORD!
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
  DefineVariable  bIfStructure,       BYTE,     MAX_IF_LEVEL dup(0) ;If structure stack
  DefineVariable  bIfResult,          BYTE,     MAX_IF_LEVEL dup(0) ;If result stack
  DefineVariable  bIfHistory,         BYTE,     MAX_IF_LEVEL dup(0) ;If history stack
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
  StaticMethod    ProcessFile,        PSTRINGW, PSTRINGW, $ObjPtr(IncFile)
  StaticMethod    ProcessFiles,       PSTRINGW
  RedefineMethod  Run
  StaticMethod    ShowError,          PSTRING
  StaticMethod    ShowInfo,           DWORD, PSTRING
  StaticMethod    ShowQuestion,       PSTRING
  StaticMethod    ShowWarning,        DWORD, PSTRING

  DefineVariable  dRecordNameSufix,   DWORD,    0       ;Added at the end of record and field names
  DefineVariable  dStructNameSufix,   DWORD,    0       ;Added at the end of DUMMYSTRUCTNAME
  DefineVariable  dUnionNameSufix,    DWORD,    0       ;Added at the end of DUMMYUNIONNAME
  DefineVariable  dStructSuffix,      DWORD,    0       ;Used for nameless structures => STRUCT_xxxx
  if DEBUGGING
  DefineVariable  dIncNestingLevel,   DWORD,    0
  endif
  DefineVariable  bTerminate,         BYTE,     FALSE   ;TRUE => terminate application as soon as possible

  DefineVariable  pFilespec,          PSTRINGA, NULL
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
include h2inc+_IncFile_Parse.inc
include h2inc+_Handler.inc
include h2inc+_Main.inc

start proc                                              ;Program entry point
  SysInit
  DbgClearAll

  OCall $ObjTmpl(Application)::Application.Init         ;Initialize application
  OCall $ObjTmpl(Application)::Application.Run          ;Execute application
  OCall $ObjTmpl(Application)::Application.Done         ;Finalize application

  SysDone                                               ;Runtime finalization of the OOP model
  invoke ExitProcess, 0                                 ;Exit program returning 0 to the OS
start endp

end
