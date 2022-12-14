; ==================================================================================================
; Title:      Demo10_Shared.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm demonstration program 10.
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


;General information
APP_TITLE                     textequ   <Demo10>
ABOUT_TEXT                    textequ   <Demo10 - Advanced Controls>
COPYRIGHT                     textequ   <G. Friedrich   October 2017> 
VER_FILEVERSION               equ       2,0,0,0
VER_FILEVERSION_STR           textequ   <2.0>
VER_PRODUCTVERSION            equ       2,0,0,0
VER_PRODUCTVERSION_STR        equ       <2.0>

;Build information - updated automatically -
BUILD_NUMBER                  equ       148
BUILD_DATE_STR                textequ   <2022-12-12>
BUILD_BITNESS                 equ       64
BUILD_MODE                    equ       RLS

;Menu IDs
IDM_FILE                      equ       050
IDM_FILE_NEW                  equ       051
IDM_FILE_CLOSE                equ       052
IDM_FILE_ERROR                equ       053
IDM_FILE_SETUP                equ       054
IDM_FILE_EXIT                 equ       055

IDM_LANGUAGE                  equ       060
IDM_LANGUAGE_ENGLISH          equ       061
IDM_LANGUAGE_GERMAN           equ       062
IDM_LANGUAGE_SPANISH          equ       063

IDM_COLOR                     equ       070
IDM_COLOR_BLACK               equ       071
IDM_COLOR_RED                 equ       072
IDM_COLOR_GREEN               equ       073
IDM_COLOR_BLUE                equ       074
IDM_COLOR_WHITE               equ       075

IDM_WINDOW                    equ       080
IDM_WINDOW_CASCADE            equ       081
IDM_WINDOW_TILE_HOR           equ       082
IDM_WINDOW_TILE_VER           equ       083
IDM_WINDOW_ARRANGE            equ       084
IDM_WINDOW_CLOSEALL           equ       085

IDM_HELP                      equ       090
IDM_HELP_HELP                 equ       091
IDM_HELP_ABOUT                equ       092

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

IDB_WINDOW_CASCADE            equ       007
IDB_WINDOW_TILE_HOR           equ       008
IDB_WINDOW_TILE_VER           equ       009
IDB_WINDOW_ARRANGE            equ       010
IDB_WINDOW_CLOSEALL           equ       011

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
