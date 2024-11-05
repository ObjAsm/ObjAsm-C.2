; ==================================================================================================
; Title:      DebugCenter_Shared.inc
; Author:     G. Friedrich
; Version:    See DebugCenter.asm
; Purpose:    ObjAsm DebugCenter application.
; ==================================================================================================


;General information
APP_TITLE                     textequ   <Debug Center>
ABOUT_TEXT                    textequ   <Debug Center>
COPYRIGHT                     textequ   <G. Friedrich   October 2017> 
VER_FILEVERSION               equ       2,4,0,0
VER_FILEVERSION_STR           textequ   <2.4.0>
VER_PRODUCTVERSION            equ       2,4,0,0
VER_PRODUCTVERSION_STR        textequ   <2.4.0>

;Build information - updated automatically -
BUILD_NUMBER                  equ       42
BUILD_DATE_STR                textequ   <2024-11-02>
BUILD_BITNESS                 equ       64
BUILD_MODE                    equ       RLS

;Menu IDs
IDM_FILE                      equ       050
IDM_FILE_OPEN                 equ       051
IDM_FILE_SAVE                 equ       052
IDM_FILE_SAVEAS               equ       053
IDM_FILE_CLOSE                equ       054
IDM_FILE_PAGESETUP            equ       055
IDM_FILE_PRINTERSETUP         equ       056
IDM_FILE_PRINT                equ       057
IDM_FILE_PIN                  equ       058
IDM_FILE_SETUP                equ       059
IDM_FILE_EXIT                 equ       060

IDM_EDIT                      equ       100
IDM_EDIT_CUT                  equ       101
IDM_EDIT_COPY                 equ       102
IDM_EDIT_PASTE                equ       103
IDM_EDIT_CLEAR                equ       104
IDM_EDIT_SELECTALL            equ       105
IDM_EDIT_ERASE                equ       106
IDM_EDIT_ERASEALL             equ       107
IDM_EDIT_FIND                 equ       108
IDM_EDIT_CALC                 equ       109

IDM_LANGUAGE                  equ       150
IDM_LANGUAGE_ENGLISH          equ       151
IDM_LANGUAGE_GERMAN           equ       152
IDM_LANGUAGE_ITALIAN          equ       153
IDM_LANGUAGE_RUSSIAN          equ       154
IDM_LANGUAGE_SPANISH          equ       155

IDM_WINDOW                    equ       200
IDM_WINDOW_CASCADE            equ       201
IDM_WINDOW_TILE_HOR           equ       202
IDM_WINDOW_TILE_VER           equ       203
IDM_WINDOW_ARRANGE            equ       204
IDM_WINDOW_NEXT               equ       205
IDM_WINDOW_PREV               equ       206
IDM_WINDOW_ZOOMIN             equ       210
IDM_WINDOW_ZOOMOUT            equ       211
IDM_WINDOW_CLOSEALL           equ       212

IDM_HELP                      equ       990
IDM_HELP_HELP                 equ       991
IDM_HELP_ABOUT                equ       992

IDM_SYSTRAY                   equ       950
IDM_CONTEXT                   equ       960
IDM_RESTORE                   equ       0F6CAh

BUILD_BIN_FORMAT              equ       EXE
BUILD_BIN_SUFFIX_STR          textequ   <>
