; ==================================================================================================
; Title:      h2inc+_Globals.inc
; Author:     G. Friedrich
; Version:    See h2inc+.asm
; Purpose:    ObjAsm definition of application globals.
; ==================================================================================================


;General equates
MAX_WARNING_LEVEL       equ 3       ;Max value for -Wn switch
WARNING_MAX             equ 0
WARNING_SEVERE          equ 1
WARNING_MAYOR           equ 2
WARNING_MINOR           equ 3

MAX_VERBOSITY_LEVEL     equ 3       ;Max value for -Vn switch
VERBOSITY_SILENT        equ 0
VERBOSITY_IMPORTANT     equ 1
VERBOSITY_NORMAL        equ 2
VERBOSITY_DEAFENING     equ 3

MAX_COND_LEVEL          equ 32      ;Must be a multiple of 4!
MAX_NAME_CHARS          equ 128     ;Buffer size for struct, union, etc. names.
ADD_50_PERCENT          equ 0       ;0 = buffer size 100% larger than file size

COLOR_HEADER            equ FOREGROUND_BLUE or FOREGROUND_GREEN or FOREGROUND_RED or FOREGROUND_INTENSITY
COLOR_REGULAR           equ FOREGROUND_BLUE or FOREGROUND_GREEN or FOREGROUND_RED
COLOR_WARNING           equ FOREGROUND_RED
COLOR_ERROR             equ FOREGROUND_RED or FOREGROUND_INTENSITY
COLOR_QUESTION          equ FOREGROUND_GREEN or FOREGROUND_INTENSITY

;Prototypes
InsertStrg              proto :POINTER, :PSTRINGA, :DWORD
InsertAttr              proto :POINTER, :PSTRINGA, :DWORD, :DWORD
InsertEqui              proto :POINTER, :PSTRINGA, :DWORD, :PSTRINGA, :DWORD
RenderPP                proto
GetStringLiteral        proto
ConvertNumber           proto
RenderC                 proto
RenderBitField          proto :PSTRINGA, :PSTRINGA, :PTOKEN, :PSTRINGA
RenderBlock             proto :PTOKEN, :DWORD
RenderContainer         proto :PSTRINGA, :DWORD
RenderContainerMember   proto :PTOKEN, :PSTRINGA
RenderEnumMember        proto :PTOKEN
RenderDefineConst       proto :PSTRINGA
RenderExtern            proto
RenderExternMember      proto :PTOKEN
RenderFurtherTypes      proto :PSTRINGA, :PSTRINGA, :PTOKEN
RenderInterfaceBlock    proto :PSTRINGA
RenderMacroCall         proto :PSTRINGA, :DWORD, :DWORD
RenderPrototype         proto :PSTRINGA, :PSTRINGA
RenderTypedef           proto
RenderTypedefFunction   proto :PSTRINGA
RenderTypedefFuncPtr    proto :PSTRINGA
RenderTypedefEnum       proto :BOOL

;Additional ASCII Codes
BELL                    equ 07h
BACK                    equ 08h
HTAB                    equ 09h
VTAB                    equ 0Bh
FF                      equ 0Ch

DLLIMPORT_DEFAULT       equ 0
DLLIMPORT_ASSUME        equ 1
DLLIMPORT_IGNORE        equ 2
DLLIMPORT_DEFPROTO      equ 3

OUTPUT_CONSTANTS        equ BIT00
OUTPUT_PROTOTYPES       equ BIT01
OUTPUT_TYPEDEFS         equ BIT02
OUTPUT_CONTAINERS       equ BIT03
OUTPUT_EXTERNALS        equ BIT04

CALLCONV_CDECL          equ 0
CALLCONV_STDCALL        equ 1
CALLCONV_PASCAL         equ 2
CALLCONV_SYSCALL        equ 3
CALLCONV_FASTCALL       equ 4
CALLCONV_VECTORCALL     equ 5

;Extern Linkage Type
ELT_UNDEF               equ 0
ELT_C                   equ 1
ELT_CPP                 equ 2

;Prototype qualifiers
PTQ_CDECL               equ 0001h   ;cdecl
PTQ_STDCALL             equ 0002h   ;stdcall
PTQ_INLINE              equ 0004h   ;inline
PTQ_IMPORT              equ 0008h   ;declspec(dllimport)
PTQ_SYSCALL             equ 0010h   ;syscall
PTQ_PASCAL              equ 0020h   ;pascal
PTQ_FASTCALL            equ 0040h   ;fastcall
PTQ_VECTORCALL          equ 0080h   ;vectorcall
PTQ_STATIC              equ 1000h   ;static

;C Basic Type Specifier
CTS_signed              equ BIT04
CTS_unsigned            equ CTS_signed shl 1
CTS_short               equ CTS_unsigned shl 1
CTS_long                equ CTS_short shl 1
CTS_long2               equ CTS_long shl 1
CTS_void                equ 01
CTS_char                equ 02
CTS_bool                equ 03
CTS_int                 equ 04
CTS_float               equ 05
CTS_double              equ 06
CTS___int8              equ 07
CTS___int16             equ 08
CTS___int32             equ 09
CTS___int64             equ 10
CTS___wchar_t           equ 11

;Types for RenderBlock()
RBT_CONTAINER           equ 0       ;struct/union
RBT_ENUM                equ 1       ;enum
RBT_EXTERN              equ 2       ;extern

;Parser output ctrl codes
PCT_EOL                 equ 0E0h    ;(à) End of Line
PCT_WEAKEOL             equ 0E1h    ;(á) "\" at the end of preprocessor lines
PCT_COMMENT             equ 0E2h    ;(â) Comment token
PCT_IGNORE              equ 0E3h    ;(ã) Ignore token
PCT_MACRO               equ 0E4h    ;(ä) Is a macro

;Flag values for Known-Macros
MCF_KNOWN               equ 001h    ;Known macro comming from stored values
MCF_HAS_PARAMS          equ 002h    ;Macro has parameters
MCF_SKIP_BRACES         equ 004h    ;Skip first and last parenthesis in macro invocation
MCF_COPY_LINE           equ 008h    ;Assume rest of line belongs to macro invocation
MCF_PARAMS_FOLLOW       equ 010h    ;Assume method parameters coming after macro invocation
MCF_WRITE_END_MACRO     equ 020h    ;End block with a macro invocation (e.g.: xxx_END)
MCF_STRUCT_BEG          equ 040h    ;Macro begins a struct/union definition
MCF_INTERFACE_BEG       equ 080h    ;Add an "??Interface equ <xxx>" line
MCF_INTERFACE_END       equ 100h    ;Add an "??Interface equ <>" line
MCF_ARG_EXPRESSION      equ 200h    ;Force argument handling as an expression
MCF_SKIP_INVOKATION     equ 400h    ;Skip macro invocation

;Flag values for Known-Equates
EQF_KNOWN               equ 001h    ;Known equate comming from Ini-File or default values
EQF_HAS_EOL             equ 002h

;PP conditional types
PCT_IF                  equ 000h    ;"#if"
PCT_ELIF                equ 001h    ;"#elif"
PCT_IFDEF               equ 002h    ;"#ifdef"
PCT_IFNDEF              equ 003h    ;"#ifndef"

;PP conditional result
PPR_FALSE               equ 0
PPR_TRUE                equ 1
PPR_UNKNOWN             equ 2

.const
szEmpty CHRA            0
CStr szIniFileName,     "h2inc+.ini"
CBStrA szUnsigned,      "unsigned"
CBStrA szSigned,        "signed"
CBStrA szStruct,        "struct"
CBStrA szUnion,         "union"
CBStrA szClass,         "class"
CBStrA szEnum,          "enum"
CBStrA szVoid,          "void"
CStrA szSpace,          " "
CStrA szComma,          ","
CStrA szColon,          ":"
CStrA szSemiColon,      ";"
CStrA szUnderscore,     "_"
CStrA szResWordSuffix,  "_"
CStrA szDllImport,      "DllImport"
CStrA szPtrSpace,       "ptr "
CStrA szUnkType,        "??TYPE"
CStr  szOutOfSpace,     "out of symbol space"

CStrA szBYTE,           "BYTE"
CStrA szSBYTE,          "SBYTE"
CStrA szWORD,           "WORD"
CStrA szSWORD,          "SWORD"
CStrA szDWORD,          "DWORD"
CStrA szSDWORD,         "SDWORD"
CStrA szQWORD,          "QWORD"
CStrA szSQWORD,         "SQWORD"
CStrA szOWORD,          "OWORD"
CStrA szSOWORD,         "SOWORD"
CStrA szREAL4,          "REAL4"
CStrA szREAL8,          "REAL8"
CStrA szREAL10,         "REAL10"

CStr szNesting2Deep,    "'if' nesting level too deep"
CStr szElseWoIf,        "'else'/'elif' without 'if'"
CStr szEndifWoIf,       "'endif' without 'if'"


DebugMessage CHRA       512 dup (?)
DebugCaption PSTRINGA   ?

PrependZerosA macro Var, Count
  xor eax, eax
  if Count eq 4
    .if &Var < 10
      FillTextA CHRA ptr [xdi], <000>
      mov eax, ??StrLen
    .elseif &Var < 100
      FillTextA CHRA ptr [xdi], <00>
      mov eax, ??StrLen
    .elseif &Var < 1000
      FillTextA CHRA ptr [xdi], <0>
      mov eax, ??StrLen
    .endif
  elseif Count eq 3
    .if &Var < 10
      FillTextA CHRA ptr [xdi], <00>
      mov eax, ??StrLen
    .elseif &Var < 100
      FillTextA CHRA ptr [xdi], <0>
      mov eax, ??StrLen
    .endif
  else
    .if &Var < 10
      FillTextA CHRA ptr [xdi], <0>
      mov eax, ??StrLen
    .endif
  endif
  exitm <>
endm

INP_STAT struc
  pIn             POINTER   ?
  dLineNumber     DWORD     ?
  dIndentation    DWORD     ?
  bNewLine        BYTE      ?
  bSkipLineC      BYTE      ?
  bSkipLinePP     BYTE      ?
  bCondIfLevel    BYTE      ?
  bCondElseLevel  BYTE      MAX_COND_LEVEL dup (?)
  bCondResult     BYTE      MAX_COND_LEVEL dup (?)
  bCondHistory    BYTE      MAX_COND_LEVEL dup (?)
INP_STAT ends
P_INP_STAT typedef ptr INP_STAT

STMOUT_STAT struc
  pStmOutPos      POINTER   ?
  dStmOutEoL      DWORD     ?
  dIndentation    DWORD     ?
STMOUT_STAT ends
P_STMOUT_STAT typedef ptr STMOUT_STAT

LIST_SETUP struct
  pSectionName    PSTRINGA  ?   ;-> ini section name
  pList           POINTER   ?   ;-> List
  dAlloc          DWORD     ?   ;List memory allocation count
  dIncr           DWORD     ?   ;List memory increment count
  dFlags          DWORD     ?   ;List flags
  pFileName       PSTRINGW  ?   ;Load/Save Filename
  pDefault        POINTER   ?   ;-> default table
LIST_SETUP ends
PLIST_SETUP typedef ptr LIST_SETUP

CF_SNG    equ 0001h             ;Single string
CF_LCS    equ 0002h             ;Single lowercase string
CF_CNV    equ 0004h             ;string -> string conversion
CF_ATR    equ 0008h             ;string -> DWORD conversion
CF_KNW    equ 0010h             ;Load from Ini-File

CONV_ATTR_ENTRY struc
  pName   PSTRINGA ?
  dValue  DWORD    ?
CONV_ATTR_ENTRY ends

CONV_EQUI_ENTRY struc
  pName   PSTRINGA ?
  pEqui   PSTRINGA ?
CONV_EQUI_ENTRY ends

CONV_BASIC_TYPE_ENTRY struc
  dSpec   DWORD    ?
  pName   PSTRINGA ?
CONV_BASIC_TYPE_ENTRY ends


DefListSetup macro EntryName:req, Alloc:req, Incr:req, Flags:=<>, FileName:= <>, SectName:=<>
  ifb <FileName>
    FullFileName equ <NULL>
  else
    FullFileName equ <$OfsCStrW("H2I_&FileName&.lst")>  ;;WIDE Filename
  endif

  if Flags and CF_KNW
%   EntryName LIST_SETUP <$OfsCBStrA("&SectName"), \
              NULL, Alloc, Incr, Flags, FullFileName, offset Default&EntryName&Table>
  else
%   EntryName LIST_SETUP <offset szEmpty, \
              NULL, Alloc, Incr, Flags, FullFileName, NULL>
  endif
  p&EntryName textequ <&EntryName.pList>                ;;Define a commodity equate
endm

.data                                                   ;Must be in .data because of pList
KnownContentLists label LIST_SETUP
DefListSetup  KnwResvWords,    1000, 100, CF_KNW or CF_LCS, <KnwResvWords>,   <Reserved Words>
DefListSetup  KnwTypeSize,     1000, 100, CF_KNW or CF_ATR, <KnwTypeSizes>,   <Type Size>
DefListSetup  KnwMacros,       1000, 100, CF_KNW or CF_ATR, <KnwMacros>,      <Macro Names>
DefListSetup  KnwEquates,      1000, 100, CF_KNW or CF_ATR, <KnwEquate>,      <Equate Names>
DefListSetup  KnwStructs,      1000, 100, CF_KNW or CF_SNG, <KnwStruct>,      <Structure Names>
DefListSetup  KnwQualifiers,   1000, 100, CF_KNW or CF_ATR, <KnwQualif>,      <Prototype Qualifiers>
DefListSetup  KnwSimpleTypes,  1000, 100, CF_KNW or CF_SNG, <KnwTypeNames>,   <Simple Type Names>
DefListSetup  KnwConvTypeQual, 1000, 100, CF_KNW or CF_CNV, <KnwConvQualif>,  <Type Qualifier Conversion>
DefListSetup  KnwConvTypes1,   1000, 100, CF_KNW or CF_CNV, <KnwConvType1>,   <Type Conversion 1>
DefListSetup  KnwConvTypes2,   1000, 100, CF_KNW or CF_CNV, <KnwConvType2>,   <Type Conversion 2>
DefListSetup  KnwConvTypes3,   1000, 100, CF_KNW or CF_CNV, <KnwConvType3>,   <Type Conversion 3>
DefListSetup  KnwConvTokens,   1000, 100, CF_KNW or CF_CNV, <KnwConvToken>,   <Token Conversion>
DefListSetup  KnwAlignments,   1000, 100, CF_KNW or CF_ATR, <KnwAlignment>,   <Alignment>
DefListSetup  KnwAnnotations,  1000, 100, CF_KNW or CF_SNG, <KnwAnnotations>, <Annotations>
NewContentLists label LIST_SETUP
DefListSetup  NewTypeSize,     1000, 100, CF_ATR,           <NewTypeSizes>
DefListSetup  NewMacros,       1000, 100, CF_ATR,           <NewMacros>
DefListSetup  NewEquates,      1000, 100, CF_ATR,           <NewEquate>
DefListSetup  NewStructs,      1000, 100, CF_SNG,           <NewStruct>
DefListSetup  NewQualifiers,   1000, 100, CF_ATR,           <NewQualif>
DefListSetup  NewPrototypes,   1000, 100, CF_SNG,           <NewProtos>
DefListSetup  NewTypedefs,     1000, 100, CF_SNG,           <NewTypdef>
POINTER NULL


.const

;Token conversion, use with care!
DefaultKnwConvTokensTable label POINTER
  CONV_EQUI_ENTRY <$OfsCBStrA("interface"), offset szStruct>
  POINTER NULL

;Known type attribute names, usually not used, since defined in h2inc+.ini.
DefaultKnwConvTypeQualTable label POINTER
  CONV_EQUI_ENTRY <$OfsCBStrA("const"),     offset szEmpty>
  CONV_EQUI_ENTRY <$OfsCBStrA("volatile"),  offset szEmpty>
  CONV_EQUI_ENTRY <$OfsCBStrA("restrict"),  offset szEmpty>
  CONV_EQUI_ENTRY <$OfsCBStrA("_Atomic"),   offset szEmpty>
  CONV_EQUI_ENTRY <$OfsCBStrA("far"),       offset szEmpty>
  CONV_EQUI_ENTRY <$OfsCBStrA("near"),      offset szEmpty>
  CONV_EQUI_ENTRY <$OfsCBStrA("IN"),        offset szEmpty>
  CONV_EQUI_ENTRY <$OfsCBStrA("OUT"),       offset szEmpty>
  POINTER NULL

;Known macro names, usually not used, since defined in h2inc+.ini.
;Meaning of ATTR value:
;  MCF_KNOWN            001h => Skip braces in macro call
;  MCF_HAS_PARAMS       002h => Macro has parameters
;  MCF_SKIP_BRACES      004h => Skip braces in macro call
;  MCF_COPY_LINE        008h => Assume rest of line belongs to macro call
;  MCF_PARAMS_FOLLOW    010h => Assume method parameters coming after macro
;  MCF_WRITE_END_MACRO  020h => End next block with a ???_END macro call
;  MCF_STRUCT_BEG       040h => Macro begins a struct/union
;  MCF_INTERFACE_BEG    080h => Add an "??Interface equ <xxx>" line
;  MCF_INTERFACE_END    100h => Add an "??Interface equ <>" line
;  MCF_ARG_EXPRESSION   200h => Force argument handling as expression
;  MCF_SKIP_INVOKATION  400h => skip macro invokation
;
;  31: STDMETHOD handling: skip braces, copy rest of line assuming that they are function params.
;  35: terminate block with a <macroname>_END macro invocation
;
;Support for MIDL generated header files:
;  67: assume MIDL_INTERFACE: start a struct declaration
; 129: assume BEGIN_INTERFACE: add "??Interface equ <xxx>" line
; 257: assume END_INTERFACE: add "??Interface equ <>" line

DefaultKnwMacrosTable label POINTER
  CONV_ATTR_ENTRY <$OfsCBStrA("BEGIN_INTERFACE"),           MCF_KNOWN or MCF_INTERFACE_BEG>
  CONV_ATTR_ENTRY <$OfsCBStrA("DECLARE_HANDLE"),            MCF_KNOWN or MCF_HAS_PARAMS>
  CONV_ATTR_ENTRY <$OfsCBStrA("DECLARE_INTERFACE"),         MCF_KNOWN or MCF_HAS_PARAMS or MCF_WRITE_END_MACRO>
  CONV_ATTR_ENTRY <$OfsCBStrA("DECLARE_INTERFACE_"),        MCF_KNOWN or MCF_HAS_PARAMS or MCF_WRITE_END_MACRO>
  CONV_ATTR_ENTRY <$OfsCBStrA("DECLARE_INTERFACE_IID"),     MCF_KNOWN or MCF_HAS_PARAMS or MCF_WRITE_END_MACRO>
  CONV_ATTR_ENTRY <$OfsCBStrA("DECLARE_INTERFACE_IID_"),    MCF_KNOWN or MCF_HAS_PARAMS or MCF_WRITE_END_MACRO>
  CONV_ATTR_ENTRY <$OfsCBStrA("DECLSPEC_UUID"),             MCF_KNOWN or MCF_HAS_PARAMS>
  CONV_ATTR_ENTRY <$OfsCBStrA("DECLSPEC_XFGVIRT"),          MCF_KNOWN or MCF_HAS_PARAMS or MCF_SKIP_INVOKATION>
  CONV_ATTR_ENTRY <$OfsCBStrA("DEFINE_GUID"),               MCF_KNOWN or MCF_HAS_PARAMS or MCF_SKIP_BRACES>
  CONV_ATTR_ENTRY <$OfsCBStrA("END_INTERFACE"),             MCF_KNOWN or MCF_INTERFACE_END>
  CONV_ATTR_ENTRY <$OfsCBStrA("MIDL_INTERFACE"),            MCF_KNOWN or MCF_HAS_PARAMS or MCF_WRITE_END_MACRO or MCF_STRUCT_BEG>
  CONV_ATTR_ENTRY <$OfsCBStrA("SHSTDAPI_"),                 MCF_KNOWN or MCF_HAS_PARAMS>
  CONV_ATTR_ENTRY <$OfsCBStrA("STDMETHOD"),                 MCF_KNOWN or MCF_HAS_PARAMS or MCF_SKIP_BRACES or MCF_COPY_LINE or MCF_PARAMS_FOLLOW>
  CONV_ATTR_ENTRY <$OfsCBStrA("STDMETHOD_"),                MCF_KNOWN or MCF_HAS_PARAMS or MCF_SKIP_BRACES or MCF_COPY_LINE or MCF_PARAMS_FOLLOW>
  CONV_ATTR_ENTRY <$OfsCBStrA("WINOLEAPI_"),                MCF_KNOWN or MCF_HAS_PARAMS>
  CONV_ATTR_ENTRY <$OfsCBStrA("WINAPI_FAMILY_PARTITION"),   MCF_KNOWN or MCF_HAS_PARAMS or MCF_ARG_EXPRESSION>
  CONV_ATTR_ENTRY <$OfsCBStrA("WINAPI_PARTITION_DESKTOP"),  MCF_KNOWN or MCF_HAS_PARAMS or MCF_ARG_EXPRESSION>
  CONV_ATTR_ENTRY <$OfsCBStrA("WINAPI_PARTITION_APP"),      MCF_KNOWN or MCF_HAS_PARAMS or MCF_ARG_EXPRESSION>
  CONV_ATTR_ENTRY <$OfsCBStrA("WINAPI_PARTITION_PHONE_APP"),MCF_KNOWN or MCF_HAS_PARAMS or MCF_ARG_EXPRESSION>
  CONV_ATTR_ENTRY <$OfsCBStrA("WINAPI_PARTITION_SYSTEM"),   MCF_KNOWN or MCF_HAS_PARAMS or MCF_ARG_EXPRESSION>
  CONV_ATTR_ENTRY <$OfsCBStrA("WINAPI_PARTITION_PHONE"),    MCF_KNOWN or MCF_HAS_PARAMS or MCF_ARG_EXPRESSION>
  POINTER NULL

;Known equate default names, usually not used, since defined in h2inc+.ini.
DefaultKnwEquatesTable label POINTER
;  CONV_ATTR_ENTRY <$OfsCBStrA(""),           EQF_KNOWN>
  POINTER NULL

;Known structure default names, usually not used, since defined in h2inc+.ini.
DefaultKnwStructsTable label POINTER
  POINTER $OfsCBStrA("POINT")
  POINTER NULL

;Known prototype qualifier default names, usually not used, since defined in h2inc+.ini.
DefaultKnwQualifiersTable label POINTER
  CONV_ATTR_ENTRY <$OfsCBStrA("__cdecl"),    PTQ_CDECL>
  CONV_ATTR_ENTRY <$OfsCBStrA("_cdecl"),     PTQ_CDECL>
  CONV_ATTR_ENTRY <$OfsCBStrA("__stdcall"),  PTQ_STDCALL>
  CONV_ATTR_ENTRY <$OfsCBStrA("_stdcall"),   PTQ_STDCALL>
  CONV_ATTR_ENTRY <$OfsCBStrA("stdcall"),    PTQ_STDCALL>
  CONV_ATTR_ENTRY <$OfsCBStrA("WINAPI"),     PTQ_STDCALL>
  CONV_ATTR_ENTRY <$OfsCBStrA("WINAPIV"),    PTQ_CDECL>
  CONV_ATTR_ENTRY <$OfsCBStrA("APIENTRY"),   PTQ_STDCALL>
  CONV_ATTR_ENTRY <$OfsCBStrA("__inline"),   PTQ_INLINE>
  POINTER NULL

;Type sizes default values. Required if a type is a parameter with size > 4.
;Usually not used, since defined in h2inc+.ini.
DefaultKnwTypeSizeTable label POINTER
  CONV_ATTR_ENTRY <$OfsCBStrA("BYTE"),        01>
  CONV_ATTR_ENTRY <$OfsCBStrA("CHAR"),        01>
  CONV_ATTR_ENTRY <$OfsCBStrA("CY"),          08>
  CONV_ATTR_ENTRY <$OfsCBStrA("DATE"),        08>
  CONV_ATTR_ENTRY <$OfsCBStrA("DOUBLE"),      08>
  CONV_ATTR_ENTRY <$OfsCBStrA("DWORD"),       04>
  CONV_ATTR_ENTRY <$OfsCBStrA("DWORD64"),     08>
  CONV_ATTR_ENTRY <$OfsCBStrA("DWORDLONG"),   08>
  CONV_ATTR_ENTRY <$OfsCBStrA("DWORD_PTR"),   08>
  CONV_ATTR_ENTRY <$OfsCBStrA("INT64"),       08>
  CONV_ATTR_ENTRY <$OfsCBStrA("LONG"),        04>
  CONV_ATTR_ENTRY <$OfsCBStrA("LONG64"),      08>
  CONV_ATTR_ENTRY <$OfsCBStrA("LONGLONG"),    08>
  CONV_ATTR_ENTRY <$OfsCBStrA("LONG_PTR"),    08>
  CONV_ATTR_ENTRY <$OfsCBStrA("OWORD"),       16>
  CONV_ATTR_ENTRY <$OfsCBStrA("POINT"),       08>
  CONV_ATTR_ENTRY <$OfsCBStrA("PROPVARIANT"), 16>
  CONV_ATTR_ENTRY <$OfsCBStrA("QWORD"),       08>
  CONV_ATTR_ENTRY <$OfsCBStrA("SHORT"),       02>
  CONV_ATTR_ENTRY <$OfsCBStrA("UINT32"),      04>
  CONV_ATTR_ENTRY <$OfsCBStrA("UINT64"),      08>
  CONV_ATTR_ENTRY <$OfsCBStrA("ULONG"),       04>
  CONV_ATTR_ENTRY <$OfsCBStrA("ULONG64"),     08>
  CONV_ATTR_ENTRY <$OfsCBStrA("ULONGLONG"),   08>
  CONV_ATTR_ENTRY <$OfsCBStrA("ULONG_PTR"),   08>
  CONV_ATTR_ENTRY <$OfsCBStrA("VARIANT"),     16>
  CONV_ATTR_ENTRY <$OfsCBStrA("VARIANTARG"),  16>
  CONV_ATTR_ENTRY <$OfsCBStrA("WCHAR"),       02>
  CONV_ATTR_ENTRY <$OfsCBStrA("WORD"),        02>
  POINTER NULL

;Simple types default values, usually not used, since defined in h2inc+.ini.
DefaultKnwSimpleTypesTable label POINTER
  POINTER $OfsCBStrA("BYTE")
  POINTER $OfsCBStrA("SBYTE")
  POINTER $OfsCBStrA("WORD")
  POINTER $OfsCBStrA("SWORD")
  POINTER $OfsCBStrA("DWORD")
  POINTER $OfsCBStrA("SDWORD")
  POINTER $OfsCBStrA("QWORD")
  POINTER $OfsCBStrA("LONG")
  POINTER $OfsCBStrA("ULONG")
  POINTER $OfsCBStrA("REAL4")
  POINTER $OfsCBStrA("REAL8")
  POINTER $OfsCBStrA("BOOL")
  POINTER $OfsCBStrA("CHAR")
  POINTER $OfsCBStrA("ptr")
  POINTER $OfsCBStrA("PVOID")
  POINTER $OfsCBStrA("WCHAR")
  POINTER $OfsCBStrA("WPARAM")
  POINTER $OfsCBStrA("LPARAM")
  POINTER $OfsCBStrA("LRESULT")
  POINTER $OfsCBStrA("HANDLE")
  POINTER $OfsCBStrA("HINSTANCE")
  POINTER $OfsCBStrA("HGLOBAL")
  POINTER $OfsCBStrA("HLOCAL")
  POINTER $OfsCBStrA("HWND")
  POINTER $OfsCBStrA("HMENU")
  POINTER $OfsCBStrA("HDC")
  POINTER $OfsCBStrA("HRESULT")
  POINTER NULL

;Type conversion 1 default values, usually not used since defined in h2inc+.ini.
DefaultKnwConvTypes1Table label POINTER
  CONV_EQUI_ENTRY <$OfsCBStrA("DWORDLONG"),      $OfsCBStrA("QWORD")>
  CONV_EQUI_ENTRY <$OfsCBStrA("ULONGLONG"),      $OfsCBStrA("QWORD")>
  CONV_EQUI_ENTRY <$OfsCBStrA("LONGLONG"),       $OfsCBStrA("SQWORD")>
  CONV_EQUI_ENTRY <$OfsCBStrA("double"),         $OfsCBStrA("REAL8")>
  CONV_EQUI_ENTRY <$OfsCBStrA("float"),          $OfsCBStrA("REAL4")>
  POINTER NULL

;Type conversion 2 default values, usually not used since defined in h2inc+.ini.
;https://learn.microsoft.com/de-de/windows/win32/winprog/windows-data-types?redirectedfrom=MSDN
DefaultKnwConvTypes2Table label POINTER
  CONV_EQUI_ENTRY <$OfsCBStrA("int"),            $OfsCBStrA("SDWORD")>
  CONV_EQUI_ENTRY <$OfsCBStrA("unsigned int"),   $OfsCBStrA("DWORD")>
  CONV_EQUI_ENTRY <$OfsCBStrA("short"),          $OfsCBStrA("SWORD")>
  CONV_EQUI_ENTRY <$OfsCBStrA("unsigned short"), $OfsCBStrA("WORD")>
  CONV_EQUI_ENTRY <$OfsCBStrA("long"),           $OfsCBStrA("SDWORD")>
  CONV_EQUI_ENTRY <$OfsCBStrA("unsigned long"),  $OfsCBStrA("DWORD")>
  CONV_EQUI_ENTRY <$OfsCBStrA("char"),           $OfsCBStrA("SBYTE")>
  CONV_EQUI_ENTRY <$OfsCBStrA("unsigned char"),  $OfsCBStrA("BYTE")>
  CONV_EQUI_ENTRY <$OfsCBStrA("wchar_t"),        $OfsCBStrA("WORD")>
  CONV_EQUI_ENTRY <$OfsCBStrA("LPCSTR"),         $OfsCBStrA("LPSTR")>
  CONV_EQUI_ENTRY <$OfsCBStrA("LPCWSTR"),        $OfsCBStrA("LPWSTR")>
  CONV_EQUI_ENTRY <$OfsCBStrA("UINT"),           $OfsCBStrA("DWORD")>
  CONV_EQUI_ENTRY <$OfsCBStrA("ULONG"),          $OfsCBStrA("DWORD")>
  CONV_EQUI_ENTRY <$OfsCBStrA("LONG"),           $OfsCBStrA("SDWORD")>
  CONV_EQUI_ENTRY <$OfsCBStrA("float"),          $OfsCBStrA("REAL4")>
  CONV_EQUI_ENTRY <$OfsCBStrA("double"),         $OfsCBStrA("REAL8")>
  POINTER NULL

;Type conversion 3 default values, usually not used since defined in h2inc+.ini.
DefaultKnwConvTypes3Table label POINTER
  CONV_EQUI_ENTRY < $OfsCBStrA("POINT"),         $OfsCBStrA("QWORD")>
  POINTER NULL

;Structure alignments default values, usually not used since defined in h2inc+.ini.
DefaultKnwAlignmentsTable label POINTER
  POINTER NULL

;Reserved words default values, usually not used since defined in h2inc+.ini.
DefaultKnwResvWordsTable label POINTER
  POINTER $OfsCBStrA("al")
  POINTER $OfsCBStrA("bl")
  POINTER $OfsCBStrA("cl")
  POINTER $OfsCBStrA("dl")
  POINTER $OfsCBStrA("ax")
  POINTER $OfsCBStrA("bx")
  POINTER $OfsCBStrA("cx")
  POINTER $OfsCBStrA("dx")
  POINTER $OfsCBStrA("si")
  POINTER $OfsCBStrA("di")
  POINTER $OfsCBStrA("bp")
  POINTER $OfsCBStrA("sp")
  POINTER $OfsCBStrA("eax")
  POINTER $OfsCBStrA("ebx")
  POINTER $OfsCBStrA("ecx")
  POINTER $OfsCBStrA("edx")
  POINTER $OfsCBStrA("esi")
  POINTER $OfsCBStrA("edi")
  POINTER $OfsCBStrA("ebp")
  POINTER $OfsCBStrA("esp")
  POINTER $OfsCBStrA("rax")
  POINTER $OfsCBStrA("rbx")
  POINTER $OfsCBStrA("rcx")
  POINTER $OfsCBStrA("rdx")
  POINTER $OfsCBStrA("rsi")
  POINTER $OfsCBStrA("rdi")
  POINTER $OfsCBStrA("rbp")
  POINTER $OfsCBStrA("r8")
  POINTER $OfsCBStrA("r9")
  POINTER $OfsCBStrA("r10")
  POINTER $OfsCBStrA("r11")
  POINTER $OfsCBStrA("r12")
  POINTER $OfsCBStrA("r13")
  POINTER $OfsCBStrA("r14")
  POINTER $OfsCBStrA("r15")
  POINTER $OfsCBStrA("r16")
  POINTER NULL

DefaultKnwAnnotationsTable label POINTER
  POINTER NULL

ConvertBasicTypeTable label DWORD
CONV_BASIC_TYPE_ENTRY <CTS_char,                                          offset szSBYTE>
CONV_BASIC_TYPE_ENTRY <CTS_signed or CTS_char,                            offset szSBYTE>
CONV_BASIC_TYPE_ENTRY <CTS_unsigned or CTS_char,                          offset szBYTE>
CONV_BASIC_TYPE_ENTRY <CTS_bool,                                          offset szBYTE>
CONV_BASIC_TYPE_ENTRY <CTS___int8,                                        offset szSBYTE>
CONV_BASIC_TYPE_ENTRY <CTS_signed or CTS___int8,                          offset szSBYTE>
CONV_BASIC_TYPE_ENTRY <CTS_unsigned or CTS___int8,                        offset szBYTE>
CONV_BASIC_TYPE_ENTRY <CTS___int16,                                       offset szSWORD>
CONV_BASIC_TYPE_ENTRY <CTS_signed or CTS___int16,                         offset szSWORD>
CONV_BASIC_TYPE_ENTRY <CTS_unsigned or CTS___int16,                       offset szWORD>
CONV_BASIC_TYPE_ENTRY <CTS_short,                                         offset szSWORD>
CONV_BASIC_TYPE_ENTRY <CTS_short or CTS_int,                              offset szSWORD>
CONV_BASIC_TYPE_ENTRY <CTS_signed or CTS_short,                           offset szSWORD>
CONV_BASIC_TYPE_ENTRY <CTS_signed or CTS_short or CTS_int,                offset szSWORD>
CONV_BASIC_TYPE_ENTRY <CTS_unsigned or CTS_short,                         offset szWORD>
CONV_BASIC_TYPE_ENTRY <CTS_unsigned or CTS_short or CTS_int,              offset szWORD>
CONV_BASIC_TYPE_ENTRY <CTS___wchar_t,                                     offset szWORD>
CONV_BASIC_TYPE_ENTRY <CTS___int32,                                       offset szSDWORD>
CONV_BASIC_TYPE_ENTRY <CTS_signed or CTS___int32,                         offset szSDWORD>
CONV_BASIC_TYPE_ENTRY <CTS_unsigned or CTS___int32,                       offset szDWORD>
CONV_BASIC_TYPE_ENTRY <CTS_signed,                                        offset szSDWORD>
CONV_BASIC_TYPE_ENTRY <CTS_unsigned,                                      offset szDWORD>
CONV_BASIC_TYPE_ENTRY <CTS_int,                                           offset szSDWORD>
CONV_BASIC_TYPE_ENTRY <CTS_signed or CTS_int,                             offset szSDWORD>
CONV_BASIC_TYPE_ENTRY <CTS_unsigned or CTS_int,                           offset szDWORD>
CONV_BASIC_TYPE_ENTRY <CTS_long,                                          offset szSDWORD>
CONV_BASIC_TYPE_ENTRY <CTS_signed or CTS_long,                            offset szSDWORD>
CONV_BASIC_TYPE_ENTRY <CTS_unsigned or CTS_long,                          offset szDWORD>
CONV_BASIC_TYPE_ENTRY <CTS___int64,                                       offset szSQWORD>
CONV_BASIC_TYPE_ENTRY <CTS_signed or CTS___int64,                         offset szSQWORD>
CONV_BASIC_TYPE_ENTRY <CTS_unsigned or CTS___int64,                       offset szQWORD>
CONV_BASIC_TYPE_ENTRY <CTS_long or CTS_int,                               offset szSWORD>
CONV_BASIC_TYPE_ENTRY <CTS_signed or CTS_long or CTS_int,                 offset szSDWORD>
CONV_BASIC_TYPE_ENTRY <CTS_unsigned or CTS_long or CTS_int,               offset szDWORD>
CONV_BASIC_TYPE_ENTRY <CTS_long or CTS_long2,                             offset szSQWORD>
CONV_BASIC_TYPE_ENTRY <CTS_unsigned or CTS_long or CTS_long2,             offset szQWORD>
CONV_BASIC_TYPE_ENTRY <CTS_signed or CTS_long or CTS_long2,               offset szSQWORD>
CONV_BASIC_TYPE_ENTRY <CTS_long or CTS_long2 or CTS_int,                  offset szSQWORD>
CONV_BASIC_TYPE_ENTRY <CTS_signed or CTS_long or CTS_long2 or CTS_int,    offset szSQWORD>
CONV_BASIC_TYPE_ENTRY <CTS_unsigned or CTS_long or CTS_long2 or CTS_int,  offset szQWORD>
CONV_BASIC_TYPE_ENTRY <CTS_float,                                         offset szREAL4>
CONV_BASIC_TYPE_ENTRY <CTS_double,                                        offset szREAL8>
CONV_BASIC_TYPE_ENTRY <CTS_long or CTS_double,                            offset szREAL10>
CONV_BASIC_TYPE_ENTRY <CTS_void,                                          offset szEmpty>
DWORD 0

;Command line switch table
CMDLINE_SWITCH_ENTRY struct
  wSwitch   CHRW    ?
  bType     BYTE    ?
  xOffset   XWORD   ?
CMDLINE_SWITCH_ENTRY ends

CLS_IS_BOOL     equ 0
CLS_IS_BIT      equ 1
CLS_IS_NUMBER   equ 2
CLS_IS_CHAR     equ 3
CLS_IS_STRING   equ 4

OPTIONS struct
  bShowUsage          BYTE      FALSE         ;-h | -? command line switch
  pEnvVar             PSTRINGW  NULL          ;-@ command line switch
  bAddAlign           BYTE      FALSE         ;-a command line switch
  bBatchmode          BYTE      FALSE         ;-b command line switch
  bIncludeComments    BYTE      FALSE         ;-c command line switch
  dDllImport          DWORD     0             ;-d command line switch
  bCreateDefs         BYTE      FALSE         ;-e command line switch
  pIncludeDirs        PSTRINGW  NULL          ;-I command line switch
  bProcessInclude     BYTE      FALSE         ;-i command line switch
  dDefaultCallConv    DWORD     0             ;-k command line switch
  bLoadLists          BYTE      FALSE         ;-l command line switch
  bUntypedMembers     BYTE      FALSE         ;-m command line switch
  pOutDir             PSTRINGW  NULL          ;-o command line switch
  bUntypedParams      BYTE      FALSE         ;-p command line switch; STRUCTS = TRUE  TYPES = FALSE
  dSelectiveOutput    DWORD     0             ;-s command line switch
  dVerbosityLevel     DWORD     0             ;-v command line switch
  dWarningLevel       DWORD     0             ;-W command line switch
  bOverwrite          BYTE      FALSE         ;-y command line switch
OPTIONS ends

CmdLineSwitchTable label BYTE
  CMDLINE_SWITCH_ENTRY <"?", CLS_IS_BOOL,   offset OPTIONS.bShowUsage>
  CMDLINE_SWITCH_ENTRY <"h", CLS_IS_BOOL,   offset OPTIONS.bShowUsage>
  CMDLINE_SWITCH_ENTRY <"@", CLS_IS_STRING, offset OPTIONS.pEnvVar>
  CMDLINE_SWITCH_ENTRY <"a", CLS_IS_BOOL,   offset OPTIONS.bAddAlign>
  CMDLINE_SWITCH_ENTRY <"b", CLS_IS_BOOL,   offset OPTIONS.bBatchmode>
  CMDLINE_SWITCH_ENTRY <"c", CLS_IS_BOOL,   offset OPTIONS.bIncludeComments>
  CMDLINE_SWITCH_ENTRY <"d", CLS_IS_NUMBER, offset OPTIONS.dDllImport>
  CMDLINE_SWITCH_ENTRY <"e", CLS_IS_BOOL,   offset OPTIONS.bCreateDefs>
  CMDLINE_SWITCH_ENTRY <"I", CLS_IS_STRING, offset OPTIONS.pIncludeDirs>
  CMDLINE_SWITCH_ENTRY <"i", CLS_IS_BOOL,   offset OPTIONS.bProcessInclude>
  CMDLINE_SWITCH_ENTRY <"k", CLS_IS_NUMBER, offset OPTIONS.dDefaultCallConv>
  CMDLINE_SWITCH_ENTRY <"l", CLS_IS_BOOL,   offset OPTIONS.bLoadLists>
  CMDLINE_SWITCH_ENTRY <"m", CLS_IS_BOOL,   offset OPTIONS.bUntypedMembers>
  CMDLINE_SWITCH_ENTRY <"o", CLS_IS_STRING, offset OPTIONS.pOutDir>
  CMDLINE_SWITCH_ENTRY <"p", CLS_IS_BOOL,   offset OPTIONS.bUntypedParams>
  CMDLINE_SWITCH_ENTRY <"s", CLS_IS_BIT,    offset OPTIONS.dSelectiveOutput>
  CMDLINE_SWITCH_ENTRY <"V", CLS_IS_NUMBER, offset OPTIONS.dVerbosityLevel>
  CMDLINE_SWITCH_ENTRY <"W", CLS_IS_NUMBER, offset OPTIONS.dWarningLevel>
  CMDLINE_SWITCH_ENTRY <"y", CLS_IS_BOOL,   offset OPTIONS.bOverwrite>
  BYTE 0

String cUsageHeader,"h2inc+ version ", @CatStr(<!">,<%VERSION>,<!">), ", ", @CatStr(<!">,<%COPYRIGHT>,<!">), CRLF
String cUsageText,  "Usage: h2inc+ [Options] Filespec", CRLF
  ExtendString      "  Options: (prepended by '-' or '/')", CRLF
  ExtendString      "    -@[name]: specify an environment variable or", CRLF
  ExtendString      "              ASCII file that contains further options", CRLF
  ExtendString      "    -a: add @Align to STRUCT/UNION declarations", CRLF
  ExtendString      "    -b: batch mode without user interaction", CRLF
  ExtendString      "    -c: include comments in output", CRLF
  ExtendString      "    -d[0|1|2|3]: define __declspec(dllimport) handling (default = 0)", CRLF
  ExtendString      "      0: decide depending on values in h2inc+.ini", CRLF
  ExtendString      "      1: always assume __declspec(dllimport) is set", CRLF
  ExtendString      "      2: always assume __declspec(dllimport) is not set", CRLF
  ExtendString      "      3: if possible, use @DefProto macro to define prototypes", CRLF
  ExtendString      "    -e: write full decorated names of function prototypes to a def-file", CRLF
  ExtendString      "    -h | -?: show usage help", CRLF
  ExtendString      "    -I[directory list]: specify additional directories to search for header files", CRLF
  ExtendString      "    -i: process #include lines", CRLF
  ExtendString      "    -k[0|1|2|3|4|5]: set default calling convention for prototypes", CRLF
  ExtendString      "      0: CDECL", CRLF
  ExtendString      "      1: STDCALL", CRLF
  ExtendString      "      2: PASCAL", CRLF
  ExtendString      "      3: SYSCALL", CRLF
  ExtendString      "      4: FASTCALL", CRLF
  ExtendString      "      5: VECTORCALL", CRLF
  ExtendString      "    -l: Load previously generated lists, default is from ini-file", CRLF
  ExtendString      "    -m: generate untyped structure members (DWORDs/QWORDs)", CRLF
  ExtendString      "    -o[directory]: set the output directory (default is the current directory)", CRLF
  ExtendString      "    -p: generate untyped parameters (DWORDs/QWORDs) in prototypes", CRLF
  ExtendString      "    -s[0|1|2|3|4]: selective output (default = all)", CRLF
  ExtendString      "      0: constants and enums", CRLF
  ExtendString      "      1: prototypes", CRLF
  ExtendString      "      2: typedefs", CRLF
  ExtendString      "      3: structs/unions", CRLF
  ExtendString      "      4: externals", CRLF
  ExtendString      "    -V[0|1|2|3]: verbosity (default = 0)", CRLF
  ExtendString      "      0: Silent", CRLF
  ExtendString      "      1: Important messages only", CRLF
  ExtendString      "      2: Less-important messages", CRLF
  ExtendString      "      3: All messages", CRLF
  ExtendString      "    -W[0|1|2|3]: set warning level (default = 0)", CRLF
  ExtendString      "      0: No warnings", CRLF
  ExtendString      "      1: Severe warnings only", CRLF
  ExtendString      "      2: Severe and some less-severe warnings", CRLF
  ExtendString      "      3: All warnings", CRLF
  ExtendString      "    -y: overwrite existing .inc files without confirmation", CRLF
  ExtendString      " Filespec:", CRLF
  ExtendString      "  e.g. .\h\*.h", CRLF
