; ==================================================================================================
; Title:      ADE_Shared.inc
; Author:     G. Friedrich
; Version:    See ACE.asm
; Purpose:    ObjAsm Assembler Development Environment.
; ==================================================================================================


;General information
APP_TITLE                     textequ   <Assembler Development Environment>
ABOUT_TEXT                    textequ   <Assembler Development Environment>
COPYRIGHT                     textequ   <G. Friedrich   November 2024> 
VER_FILEVERSION               equ       1,0,0,0
VER_FILEVERSION_STR           textequ   <1.0>
VER_PRODUCTVERSION            equ       1,0,0,0
VER_PRODUCTVERSION_STR        textequ   <1.0>

;Build information - updated automatically -
BUILD_NUMBER                  equ       01
BUILD_DATE_STR                textequ   <2025-03-09>
BUILD_BITNESS                 equ       64
BUILD_MODE                    equ       DBG

;Menu IDs
IDM_FILE                      equ       050
IDM_FILE_NEW                  equ       051
IDM_FILE_OPEN                 equ       052
IDM_FILE_SAVE_ALL             equ       053
IDM_FILE_SAVE                 equ       054
IDM_FILE_SAVE_AS              equ       055
IDM_FILE_CLOSE                equ       056
IDM_FILE_SETUP                equ       057
IDM_FILE_EXIT                 equ       058
IDM_FILE_SAVE_CTX             equ       059
IDM_FILE_LOAD_CTX             equ       060
IDM_BREAK                     equ       061

IDM_EDIT                      equ       070  
IDM_EDIT_CUT                  equ       071
IDM_EDIT_COPY                 equ       072
IDM_EDIT_PASTE                equ       073
IDM_EDIT_CLEAR                equ       074
IDM_EDIT_SELECTALL            equ       075
IDM_EDIT_FIND                 equ       076

IDM_LANGUAGE                  equ       090
IDM_LANGUAGE_ENGLISH          equ       091
IDM_LANGUAGE_GERMAN           equ       092
IDM_LANGUAGE_SPANISH          equ       093

IDM_WINDOW                    equ       110
IDM_WINDOW_CASCADE            equ       111
IDM_WINDOW_TILE_HOR           equ       112
IDM_WINDOW_TILE_VER           equ       113
IDM_WINDOW_ARRANGE            equ       114
IDM_WINDOW_CLOSEALL           equ       115

IDM_HELP                      equ       130
IDM_HELP_HELP                 equ       131
IDM_HELP_ABOUT                equ       132

;Dialog IDs 
IDC_CONTROL                   equ       800
IDC_CHOICE1                   equ       810
IDC_CHOICE2                   equ       811
IDC_CHOICE3                   equ       812
IDC_CHOICE4                   equ       813

IBS_EX_HOOVER                 equ       0x000100000

;Bitmap IDs
IDB_APP                       equ       000
IDB_APP_CHILD                 equ       001

IDB_FILE_NEW                  equ       002
IDB_FILE_CLOSE                equ       003
IDB_FILE_SETUP                equ       004
IDB_FILE_EXIT                 equ       005

IDB_COLOR_BLACK               equ       000
IDB_COLOR_RED                 equ       000
IDB_COLOR_GREEN               equ       000
IDB_COLOR_BLUE                equ       000
IDB_COLOR_WHITE               equ       000

IDB_WINDOW_CASCADE            equ       006
IDB_WINDOW_TILE_HOR           equ       007
IDB_WINDOW_TILE_VER           equ       008
IDB_WINDOW_ARRANGE            equ       009
IDB_WINDOW_CLOSEALL           equ       010

IDB_HELP_HELP                 equ       019
IDB_HELP_ABOUT                equ       020

;Control IDs
IDC_TOOLBARFILE               equ       100
IDC_TOOLBARWINDOW             equ       101
IDC_STATUSBAR                 equ       102

IDC_CONTROL                   equ       800
IDC_CHOICE1                   equ       810
IDC_CHOICE2                   equ       811
IDC_CHOICE3                   equ       812
IDC_CHOICE4                   equ       813

;Language IDs
IDLANG_ENGLISH                equ       000
IDLANG_GERMAN                 equ       100
IDLANG_SPANISH                equ       200

IDMENUCOLOR                   equ       2
LANGUAGE_STEP                 equ       100

ID_MDI_MORE                   equ       50009
ID_MDI_LIST                   equ       50010

BUILD_BIN_FORMAT              equ       EXE
BUILD_BIN_SUFFIX_STR          textequ   <>
