; ==================================================================================================
; Title:      ADE_Shared.inc
; Author:     G. Friedrich
; Version:    See ADE.asm
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
BUILD_NUMBER                  equ       132
BUILD_DATE_STR                textequ   <2025-04-17>
BUILD_BITNESS                 equ       64
BUILD_MODE                    equ       DBG

;Menu IDs
IDM_FILE                      equ       050
IDM_FILE_NEW                  equ       051
IDM_FILE_OPEN                 equ       052
IDM_FILE_SAVE                 equ       053
IDM_FILE_SAVEAS               equ       054
IDM_FILE_SAVEALL              equ       055
IDM_FILE_CLOSE                equ       056
IDM_FILE_CLOSEALL             equ       057
IDM_FILE_PAGESETUP            equ       058
IDM_FILE_PRINTERSETUP         equ       059
IDM_FILE_PRINT                equ       060
IDM_FILE_PIN                  equ       061
IDM_FILE_SETUP                equ       062
IDM_FILE_EXIT                 equ       063
IDM_FILE_SAVE_CTX             equ       064
IDM_FILE_LOAD_CTX             equ       065
IDM_FILE_BREAK                equ       066

IDM_EDIT                      equ       070
IDM_EDIT_UNDO                 equ       071
IDM_EDIT_REDO                 equ       072
IDM_EDIT_DELHIST              equ       073
IDM_EDIT_CUT                  equ       074
IDM_EDIT_COPY                 equ       075
IDM_EDIT_PASTE                equ       076
IDM_EDIT_DELETE               equ       077
IDM_EDIT_SELECTALL            equ       078
IDM_EDIT_FIND                 equ       079
IDM_EDIT_INDENT               equ       080
IDM_EDIT_OUTDENT              equ       081
IDM_EDIT_COMMENT              equ       082
IDM_EDIT_UNCOMMENT            equ       083

IDM_LANGUAGE                  equ       090
IDM_LANGUAGE_ENGLISH          equ       091
IDM_LANGUAGE_GERMAN           equ       092
IDM_LANGUAGE_ITALIAN          equ       093
IDM_LANGUAGE_RUSSIAN          equ       094
IDM_LANGUAGE_SPANISH          equ       095

IDM_WINDOW                    equ       110
IDM_WINDOW_CASCADE            equ       111
IDM_WINDOW_TILE_HOR           equ       112
IDM_WINDOW_TILE_VER           equ       113
IDM_WINDOW_ARRANGE            equ       114
IDM_WINDOW_NEXT               equ       115
IDM_WINDOW_PREV               equ       116
IDM_WINDOW_ZOOMIN             equ       117
IDM_WINDOW_ZOOMOUT            equ       118

IDM_HELP                      equ       130
IDM_HELP_HELP                 equ       131
IDM_HELP_ABOUT                equ       132

IDM_NEW_MASM                  equ       140
IDM_NEW_RESOURCE              equ       141
IDM_NEW_TEXT                  equ       142

IDM_CONTEXT_EDITOR            equ       150

;Dialog IDs 
IDC_CONTROL                   equ       800
IDC_CHOICE1                   equ       810
IDC_CHOICE2                   equ       811
IDC_CHOICE3                   equ       812
IDC_CHOICE4                   equ       813

;Bitmap IDs
IDB_APP                       equ       000
IDB_APP_CHILD                 equ       001

IDB_FILE_NEW                  equ       002
IDB_FILE_OPEN                 equ       003
IDB_FILE_SAVE                 equ       004
IDB_FILE_SAVEAS               equ       005
IDB_FILE_SAVEALL              equ       006
IDB_FILE_CLOSE                equ       007
IDB_FILE_CLOSEALL             equ       008
IDB_FILE_PAGESETUP            equ       009
IDB_FILE_PRINTERSETUP         equ       010
IDB_FILE_PRINT                equ       011
IDB_FILE_PIN                  equ       012
IDB_FILE_SETUP                equ       013
IDB_FILE_EXIT                 equ       014

IDB_EDIT_UNDO                 equ       030
IDB_EDIT_REDO                 equ       031
IDB_EDIT_CUT                  equ       015
IDB_EDIT_COPY                 equ       016
IDB_EDIT_PASTE                equ       017
IDB_EDIT_DELETE               equ       018
IDB_EDIT_FIND                 equ       019
IDB_EDIT_INDENT               equ       032
IDB_EDIT_OUTDENT              equ       033
IDB_EDIT_COMMENT              equ       034
IDB_EDIT_UNCOMMENT            equ       035


IDB_WINDOW_CASCADE            equ       020
IDB_WINDOW_TILE_HOR           equ       021
IDB_WINDOW_TILE_VER           equ       022
IDB_WINDOW_ARRANGE            equ       023
IDB_WINDOW_NEXT               equ       024
IDB_WINDOW_PREV               equ       025
IDB_WINDOW_ZOOMIN             equ       026
IDB_WINDOW_ZOOMOUT            equ       027

IDB_HELP_HELP                 equ       028
IDB_HELP_ABOUT                equ       029


;Control IDs
IDC_TOOLBARFILE               equ       100
IDC_TOOLBAREDIT               equ       101
IDC_TOOLBARWINDOW             equ       102
IDC_STATUSBAR                 equ       103

IDC_CONTROL                   equ       800
IDC_CHOICE1                   equ       810
IDC_CHOICE2                   equ       811
IDC_CHOICE3                   equ       812
IDC_CHOICE4                   equ       813

;Language IDs
IDLANG_ENGLISH                equ       000
IDLANG_GERMAN                 equ       200
IDLANG_ITALIAN                equ       400
IDLANG_RUSSIAN                equ       600
IDLANG_SPANISH                equ       800

ID_MDI_MORE                   equ       50009
ID_MDI_LIST                   equ       50010

LANGUAGE_STEP                 equ       200

ID_MDI_MORE                   equ       50009
ID_MDI_LIST                   equ       50010

BUILD_BIN_FORMAT              equ       EXE
BUILD_BIN_SUFFIX_STR          textequ   <>
