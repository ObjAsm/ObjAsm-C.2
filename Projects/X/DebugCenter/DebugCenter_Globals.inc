; ==================================================================================================
; Title:      DebugCenter_Globals.inc
; Author:     G. Friedrich
; Version:    See DebugCenter.asm
; Purpose:    ObjAsm DebugCenter application.
; ==================================================================================================


include DebugCenter_Shared.inc

%CStr szAppTitle, "&APP_TITLE"

if TARGET_STR_TYPE eq STR_TYPE_ANSI
  CStr szRichEdit20, "RichEdit20A"
else
  CStr szRichEdit20, "RichEdit20W"
endif

;Don't change the order of the next 3 string allocations
CStr szLoadFilter,      "Debug Center (*.rtf, *.bmp)", 0, "*.rtf", 3Bh, "*.bmp", 0, \
                        "Rich Text (*.rtf)", 0, "*.rtf"
CStr szBmpFilter,       "Bitmap (*.bmp)", 0, "*.bmp", 0
CStr szRtfFilter,       "Rich Text (*.rtf)", 0, "*.rtf", 0

CStr szRtfExt,          ".rtf"
CStr szBmpExt,          ".bmp"

CStr szDebugCenter,     "Debug Center"
CStr szOAPath,          "OBJASM_PATH"

CStr szCalcClass,       "SciCalc"
CStr szEditClass,       "Edit"
CStr szCalcPath,        "\Calc.exe"

CStr szState,           "State"
CStr szLeftPos,         "Left"
CStr szTopPos,          "Top"
CStr szRightPos,        "Right"
CStr szBottomPos,       "Bottom"
CStr szDirectory,       "Directory"
CStr szVersion,         "Version"
CStr szPath,            "Path"
CStr szDefDirectory,    "C:\"
CStr szLanguage,        "Language"
CStr szTxtZoom,         "TxtZoom"
CStr szBmpZoom,         "BmpZoom"
CStr szExeName,         "DebugCenter.exe"

cSingleLine  CHR  70 dup(2500h), 0
cDoubleLine  CHR  70 dup(2550h), 0


if DEBUGGING eq FALSE
  CStrW szDbgCtrCls, DEBUG_CENTER_CLASS               ;only when DEBUGGING = FALSE
endif

ZOOM_BASE               equ     64
ZOOM_MIN                equ     1
ZOOM_MAX                equ     320                   ;Max reachable value using the mousewheel
ZOOM_DEFAULT            equ     64
ZOOM_STEP               equ     8

DBG_PINNED              equ     BIT31
DBG_BMP                 equ     BIT30

DEBUG_CENTER_ID         equ     10000
DBG_MDI_CLIENT_ID       equ     10001
DBG_MDI_CHILD_ID        equ     10002
DBG_MDI_CHILD_BMP_ID    equ     10003
DBG_MDI_CHILD_CHT_ID    equ     10004
DBG_MDI_CHILD_TXT_ID    equ     10005
REDT_IPTOR_ID           equ     10006

;Bitmap IDs
IDB_APP                 equ     000
IDB_APP_CHILDTXT        equ     001
IDB_APP_CHILDBMP        equ     002

IDB_FILE_OPEN           equ     004
IDB_FILE_SAVE           equ     005
IDB_FILE_SAVEAS         equ     006
IDB_FILE_CLOSE          equ     007
IDB_FILE_PAGEUP         equ     008
IDB_FILE_PRINTERSETUP   equ     009
IDB_FILE_PRINT          equ     010
IDB_FILE_PIN            equ     011
IDB_FILE_SETUP          equ     012
IDB_FILE_EXIT           equ     013

IDB_EDIT_CUT            equ     014
IDB_EDIT_COPY           equ     015
IDB_EDIT_PASTE          equ     016
IDB_EDIT_DELETE         equ     017
IDB_EDIT_ERASE          equ     018
IDB_EDIT_ERASEALL       equ     019
IDB_EDIT_FIND           equ     020
IDB_EDIT_CALC           equ     021

IDB_WINDOW_CASCADE      equ     022
IDB_WINDOW_TILE_HOR     equ     023
IDB_WINDOW_TILE_VER     equ     024
IDB_WINDOW_ARRANGE      equ     025
IDB_WINDOW_NEXT         equ     026
IDB_WINDOW_PREV         equ     027
IDB_WINDOW_ZOOMIN       equ     028
IDB_WINDOW_ZOOMOUT      equ     029
IDB_WINDOW_CLOSE        equ     IDM_WINDOW_CLOSE
IDB_WINDOW_CLOSEALL     equ     030

IDB_HELP_HELP           equ     031
IDB_HELP_ABOUT          equ     032

;Control IDs
IDC_TOOLBARFILE         equ     100
IDC_TOOLBAREDIT         equ     101
IDC_TOOLBARWINDOW       equ     102
IDC_TOOLBARTXT          equ     103
IDC_TOOLBARBMP          equ     104
IDC_STATUSBAR           equ     105

;Language IDs
LANGUAGE_STEP           equ     200
IDLANG_ENGLISH          equ     000
IDLANG_GERMAN           equ     200
IDLANG_ITALIAN          equ     400
IDLANG_RUSSIAN          equ     600
IDLANG_SPANISH          equ     800


DEFAULT_WIDTH           equ     250
DEFAULT_HEIGHT          equ     350
DEBUG_EDIT              equ     1102


;Defaults
TXT_ZOOM_MIN            equ     16
TXT_ZOOM_MAX            equ     256
TXT_ZOOM_BASE           equ     64
TXT_ZOOM_DEFAULT        equ     64
TXT_ZOOM_STEP           equ     8

BMP_ZOOM_MIN            equ     8
BMP_ZOOM_MAX            equ     4096
BMP_ZOOM_DEFAULT        equ     64


;Communication values
DBGCMD_CLS              equ     00000000h
DBGCMD_BKGND            equ     00000001h
DBGCMD_STRING           equ     00000002h
DBGCMD_BMP              equ     00000003h

IDI_TRAY                equ     1020
WM_SHELLNOTIFY          equ     WM_USER + 5
