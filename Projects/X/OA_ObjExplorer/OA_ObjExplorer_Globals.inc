; ==================================================================================================
; Title:      OA_ObjExplorer_Globals.inc
; Author:     G. Friedrich
; Version:    Check OA_ObjExplorer.asm
; Purpose:    ObjAsm Object Explorer globals.
; ==================================================================================================



include OA_ObjExplorer_Shared.inc

%CStr cAppTitle, "&APP_TITLE"

INF_PRJ               equ   BIT00             ;This Info belongs to the current project
INF_INVALID           equ   BIT01             ;This is an info about an invalid object or interface
INF_INTREE            equ   BIT02             ;This Info is loaded into the tree
INF_INTERFACE         equ   BIT31             ;This Info is about a COM interface

INFO_TYPE_OBJECT      equ   0                 ;Link type encoded in the char color
INFO_TYPE_INTERFACE   equ   1

APP_VISIT     equ   0
APP_EMAIL     equ   1
APP_CHECK     equ   2

INFO_BUILD    equ   0
INFO_UPDATE   equ   1

CStr  cIconName,      "ICON_APP"

;Setup strings
CStr  cViewer,        "Viewer"
CStr  cDefViewer,     '"%ProgramFiles%\Notepad++\Notepad++.exe" "%s" -n%lu'     ;Default string
CStr  cLanguage,      "Language"
CStr  cShowRedefMtds, "ShowRedefinedMethods"
CStr  cShowRedefVars, "ShowRedefinedVariables"

CStr  cOpen,          "open"

;Markup Texts
MTXT_NAME           CHR "{PA 20,Z}", \
                        "[H+2,HI 20]", \
                          "[H+3][B][U]Object Name[~]:[~]     "
MTXT_END            CHR   "[~]{P}{P}", \
                        "[~]", 0
MTXT_FILES          CHR "{P}[H+1,B][U]Files[~]:[~]{B}{TABCLR}{TL 30}{TL 165}{TC 800}{TC 950}", \
                        "[B]{T}{T}File Name{T}Last Write Access{T}Status[~]{P}"
MTXT_FILE_INC       CHR "{T}[B]Definition:[~]{T}"
MTXT_FILE_ASM       CHR "{T}[B]Assembly:[~]{T}"
MTXT_FILE_LIB       CHR "{T}[B]Library:[~]{B}"
MTXT_FILE_LIB32A    CHR "{T}[B]   32-bit ANSI:[~]{T}"
MTXT_FILE_LIB32W    CHR "{T}[B]   32-bit WIDE:[~]{T}"
MTXT_FILE_LIB64A    CHR "{T}[B]   64-bit ANSI:[~]{T}"
MTXT_FILE_LIB64W    CHR "{T}[B]   64-bit WIDE:[~]{T}"
MTXT_FILE_NOT_FOUND CHR "[C#FF0000,I]File Not Found[~]"
MTXT_OUTDATED       CHR "[C#FF0000,I]Outdated[~]"
MTXT_INHER          CHR "{P}[H+1,B][U]Inheritance Path[~]:[~]     "
MTXT_ARROW          CHR " [F'Wingdings']{#00E8}[~] "
MTXT_LINK_BEG       CHR "[APP "
MTXT_CHECKBOX_BEG   CHR "[APP "
MTXT_CHECKBOX_END   CHR "]"
MTXT_ICON_BEG       CHR "{C "
MTXT_ICON_END       CHR "}"
MTXT_ICON_VAR_UNK   CHR "{C ", "0" + VARIABLETYPE_UNKNOWN, "}"
MTXT_ICON_VAR_REG   CHR "{C ", "0" + VARIABLETYPE_REGULAR, "}"
MTXT_ICON_VAR_RED   CHR "{C ", "0" + VARIABLETYPE_REDEFINED, "}"
MTXT_ICON_VAR_OBJ   CHR "{C ", "0" + VARIABLETYPE_OBJECT, "}"
MTXT_DOT            CHR "."
MTXT_UNKNOWN        CHR "[C#FF0000,I]Unknown[~]"
MTXT_ABSTRACT       CHR "Abstract"
MTXT_REGULAR        CHR "Regular"
MTXT_REDEFINED      CHR "Redefined"
MTXT_FINAL          CHR "Final"
MTXT_CHECK          CHR "[F'Wingdings 2',C#007F00,B]{#50}[~]"
;MTXT_CROSS          CHR "[F'Wingdings 2',C#FF0000,B]{#4F}[~]"
MTXT_LASTUPDATE     CHR "Last update: [%02hu/%02hu/%02hu %02hu:%02hu:%02hu]{T}"
MTXT_MTDS           CHR "[H+1,B][U]Member Methods[~]:[~]        "
MTXT_MTDS_HEADER    CHR "{P}{TABCLR}{TL 30}{TC 550}{TC 750}{TC 950}[B]{T}Name{T}Type{T}Implementation{T}Status[~]{P}"
MTXT_VARS           CHR "[H+1,B][U]Member Variables[~]:[~]       "
MTXT_VARS_HEADER    CHR "{P}{TABCLR}{TL 30}{TC 550}{TC 750}{TC 950}[B]{T}Name{T}Type{T}Value{T}Status[~]{P}"
MTXT_NO_INFO        CHR "[I]No information available[~]"
MTXT_TPL_DEFAULTS   CHR "[I]Template Defaults[~]"

MTXT_STYLE_ITALIC   CHR "[I]"
MTXT_STYLE_BOLD     CHR "[B]"
MTXT_STYLE_NONE     CHR "[H+0]"
MTXT_STYLE_CLOSE    CHR "[~]"
MTXT_PARA           CHR "{P}"
MTXT_BREAK          CHR "{B}"
MTXT_TAB            CHR "{T}"

MTXT_REDEF_CHECK    CHR "[F'Wingdings 2']{#F052}[~] Show redefined"
MTXT_REDEF_UNCHECK  CHR "[F'Wingdings 2']{#F0A3}[~] Show redefined"


METHODTYPE_UNKNOWN          equ   0
METHODTYPE_STATIC           equ   1
METHODTYPE_VIRTUAL          equ   2
METHODTYPE_VIRTUAL_ABSTRACT equ   3
METHODTYPE_VIRTUAL_EVENT    equ   4
METHODTYPE_DYNAMIC          equ   5
METHODTYPE_DYNAMIC_ABSTRACT equ   6
METHODTYPE_DYNAMIC_EVENT    equ   7
METHODTYPE_INTERFACE        equ   8
METHODTYPE_INLINE           equ   9
METHODTYPE_REDEFINED        equ   10

METHODTYPE_STANDARD         equ   11
METHODTYPE_DISPATCH         equ   12


VARIABLETYPE_UNKNOWN        equ   0
VARIABLETYPE_REGULAR        equ   1
VARIABLETYPE_REDEFINED      equ   2
VARIABLETYPE_OBJECT         equ   3

.data
MTXT_COLOR_REGULAR  CHR "[C@8]"           ;COLOR_WINDOWTEXT
MTXT_COLOR_DISABLED CHR "[C@17]"          ;COLOR_GRAYTEXT
MTXT_COLOR_ERROR    CHR "[C#FF0000]"
MTXT_LINK_END       CHR ",C@26]"          ;COLOR_HOTLIGHT

.const
;Lookup tables

;Object Method Types
OMT_TEXT_TABLE \
  PSTRING $OfsTStr("Unknown")
  PSTRING $OfsTStr("Static")
  PSTRING $OfsTStr("Virtual")
  PSTRING $OfsTStr("Virtual")             ;Abstract
  PSTRING $OfsTStr("Virtual Event")       ;Event
  PSTRING $OfsTStr("Dynamic")
  PSTRING $OfsTStr("Dynamic")             ;Abstract
  PSTRING $OfsTStr("Dynamic Event")       ;Event
  PSTRING $OfsTStr("Interface")
  PSTRING $OfsTStr("Inline")
  PSTRING $OfsTStr("Redefined")
