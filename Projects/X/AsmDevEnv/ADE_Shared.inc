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
BUILD_NUMBER                  equ       12
BUILD_DATE_STR                textequ   <2025-06-01>
BUILD_BITNESS                 equ       64
BUILD_MODE                    equ       RLS

;Menu IDs
IDM_FILE                      equ       050
IDM_FILE_NEW                  equ       051
IDM_FILE_NEW_MASM             equ       052
IDM_FILE_NEW_RESOURCE         equ       053
IDM_FILE_NEW_TEXT             equ       054
IDM_FILE_OPEN                 equ       055
IDM_FILE_SAVE                 equ       056
IDM_FILE_SAVEAS               equ       057
IDM_FILE_SAVEALL              equ       058
IDM_FILE_CLOSE                equ       059
IDM_FILE_CLOSEALL             equ       060
IDM_FILE_PAGESETUP            equ       061
IDM_FILE_PRINTERSETUP         equ       062
IDM_FILE_PRINT                equ       063
IDM_FILE_PIN                  equ       064
IDM_FILE_SETUP                equ       065
IDM_FILE_EXIT                 equ       066
IDM_FILE_SAVE_CTX             equ       067
IDM_FILE_LOAD_CTX             equ       068
IDM_FILE_BREAK                equ       069

IDM_PROJECT                   equ       100
IDM_PROJ_EDIT                 equ       101
IDM_PROJ_NEW                  equ       102
IDM_PROJ_OPEN                 equ       103
IDM_PROJ_SAVE                 equ       104
IDM_PROJ_SAVEAS               equ       105
IDM_PROJ_NEWGROUP             equ       106
IDM_PROJ_GROUP                equ       107
IDM_PROJ_GROUP_EDIT           equ       108
IDM_PROJ_GROUP_NEW            equ       109
IDM_PROJ_GROUP_ADDFILE        equ       110
IDM_PROJ_GROUP_DELETE         equ       111
IDM_PROJ_FILE_EDIT            equ       112
IDM_PROJ_FILE_OPEN            equ       113
IDM_PROJ_FILE_REMOVE          equ       114
IDM_PROJ_CMD_EDIT             equ       115
IDM_PROJ_CMD_EXECUTE          equ       116
IDM_PROJ_CMD_REMOVE           equ       117

IDM_EDIT                      equ       150
IDM_EDIT_UNDO                 equ       151
IDM_EDIT_REDO                 equ       152
IDM_EDIT_DELHIST              equ       153
IDM_EDIT_CUT                  equ       154
IDM_EDIT_COPY                 equ       155
IDM_EDIT_PASTE                equ       156
IDM_EDIT_DELETE               equ       157
IDM_EDIT_SELECTALL            equ       158
IDM_EDIT_FIND                 equ       159
IDM_EDIT_INDENT               equ       160
IDM_EDIT_OUTDENT              equ       161
IDM_EDIT_COMMENT              equ       162
IDM_EDIT_UNCOMMENT            equ       163
IDM_EDIT_INETSEARCH           equ       164
IDM_EDIT_UPPERCASE            equ       165
IDM_EDIT_LOWERCASE            equ       166
IDM_EDIT_TRIMENDBLANKS        equ       167

IDM_LANGUAGE                  equ       200
IDM_LANGUAGE_ENGLISH          equ       201
IDM_LANGUAGE_GERMAN           equ       202
IDM_LANGUAGE_ITALIAN          equ       203
IDM_LANGUAGE_RUSSIAN          equ       204
IDM_LANGUAGE_SPANISH          equ       205

IDM_WINDOW                    equ       250
IDM_WINDOW_CASCADE            equ       251
IDM_WINDOW_TILE_HOR           equ       252
IDM_WINDOW_TILE_VER           equ       253
IDM_WINDOW_ARRANGE            equ       254
IDM_WINDOW_NEXT               equ       255
IDM_WINDOW_PREV               equ       256
IDM_WINDOW_ZOOMIN             equ       257
IDM_WINDOW_ZOOMOUT            equ       258

IDM_HELP                      equ       900
IDM_HELP_HELP                 equ       901
IDM_HELP_ABOUT                equ       902

IDM_CONTEXT_EDITOR            equ       500

IDM_CONTEXT_PROJECT           equ       600
IDM_CONTEXT_GROUP             equ       601
IDM_CONTEXT_FILE              equ       602
IDM_CONTEXT_COMMAND           equ       603


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

IDB_PROJ_OPEN                 equ       0
IDB_PROJ_SAVE                 equ       1
IDB_PROJ_CLOSE                equ       2

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
