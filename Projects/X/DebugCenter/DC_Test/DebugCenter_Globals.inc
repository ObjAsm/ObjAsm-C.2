; ==================================================================================================
; Title:      DebugCenter_Globals.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm DebugCenter.
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


include DebugCenter_Shared.inc

%CStr szAppTitle, "&APP_TITLE"
%CStr szAboutText,"&ABOUT_TEXT", 13, 10, \
                  "Version &VER_PRODUCTVERSION_STR", 13, 10, \
                  "%s", 13, 10, \
                  "© &COPYRIGHT", 13, 10, 13, 10, \ 
                  @CatStr(<!">, %BUILD_DATE_STR, \
                          <  -  Build: >, %BUILD_NUMBER, <->, %ASSEMBLER, <->, \
                          %TARGET_MODE_STR, <->, %BUILD_BITNESS, <!">)

if TARGET_STR_TYPE eq STR_TYPE_ANSI
  CStr szRichEdit20, "RichEdit20A"
else
  CStr szRichEdit20, "RichEdit20W"
endif

;Don't change the order of the next 3 lines
CStr szLoadFilter,      "Debug Center files (*.rtf, *.bmp)", 0, "*.rtf", 3Bh, "*.bmp", 0, \
                        "Rich Text Format files (*.rtf)", 0, "*.rtf"
CStr szBmpFilter,       "Bitmap files (*.bmp)", 0, "*.bmp", 0
CStr szRtfFilter,       "Rich Text Format files (*.rtf)", 0, "*.rtf", 0

CStr szRtfExt,          ".rtf"
CStr szBmpExt,          ".bmp"

CStr szLoadOneFile,     "Only one file will be loaded."
CStr szFileReadErr,     "Error while reading from file."
CStr szFileWriteErr,    "Error while saving to file."
CStr szFileTypeErr,     "File type error."
CStr szPrtBitBltErr,    "Printer doesn't support BitBlt functions."
CStr szMdiChildWndErr,  "Failed to create a MDI child window."


CStr szDebugCenter,     "Debug Center"
CStr szOAPath,          "OBJASM_PATH"

CStr szCalcClass,       "SciCalc"
CStr szEditClass,       "Edit"
CStr szCalcPath,        "\Calc.exe"

<<<<<<< HEAD
CStr szHelpPath,        "\Help\ObjAsm.pdf"
=======
CStr szHelpPath,        "\Help\ObjAsm_Reference_Volume-I.pdf"
>>>>>>> 8d2d38cd8bdb1efa33cde2e2c978d5419f2baa29

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


DBG_PINNED              equ     BIT31
DBG_BMP                 equ     BIT30

DebugCenterID           equ     10000
DbgMdiClientID          equ     10001
DbgMdiChildID           equ     10002
DbgMdiChildBmpID        equ     10003
DbgMdiChildTxtID        equ     10004
REDT_IPTOR_ID           equ     10005
DbgMdiChildGrphID       equ     10006

;Bitmap IDs
IDB_APP                 equ     000
IDB_APP_CHILDTXT        equ     001
IDB_APP_CHILDBMP        equ     002

IDB_FILE_OPEN           equ     003
IDB_FILE_SAVE           equ     004
IDB_FILE_SAVEAS         equ     005
IDB_FILE_CLOSE          equ     006
IDB_FILE_PAGEUP         equ     007
IDB_FILE_PRINTERSETUP   equ     008
IDB_FILE_PRINT          equ     009
IDB_FILE_PIN            equ     010
IDB_FILE_SETUP          equ     011
IDB_FILE_EXIT           equ     012

IDB_EDIT_CUT            equ     013
IDB_EDIT_COPY           equ     014
IDB_EDIT_PASTE          equ     015
IDB_EDIT_DELETE         equ     016
IDB_EDIT_ERASE          equ     017
IDB_EDIT_ERASEALL       equ     018
IDB_EDIT_FIND           equ     019
IDB_EDIT_CALC           equ     020

IDB_WINDOW_CASCADE      equ     021
IDB_WINDOW_TILE_HOR     equ     022
IDB_WINDOW_TILE_VER     equ     023
IDB_WINDOW_ARRANGE      equ     024
IDB_WINDOW_NEXT         equ     025
IDB_WINDOW_PREV         equ     026
IDB_WINDOW_ZOOMIN       equ     027
IDB_WINDOW_ZOOMOUT      equ     028
IDB_WINDOW_CLOSE        equ     IDM_WINDOW_CLOSE
IDB_WINDOW_CLOSEALL     equ     029

IDB_HELP_HELP           equ     030
IDB_HELP_ABOUT          equ     031

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
TxtZoomMin              equ     16
TxtZoomMax              equ     256
TxtZoomBase             equ     64
TxtZoomDefault          equ     64
TxtZoomStep             equ     8

BmpZoomMin              equ     8
BmpZoomMax              equ     4096
BmpZoomDefault          equ     64


;Communication values
DBGCMD_CLS              equ     00000000h
DBGCMD_BKGND            equ     00000001h
DBGCMD_STRING           equ     00000002h
DBGCMD_BMP              equ     00000003h

IDI_TRAY                equ     1020
WM_SHELLNOTIFY          equ     WM_USER + 5
