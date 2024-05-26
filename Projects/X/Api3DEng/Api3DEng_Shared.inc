; ==================================================================================================
; Title:      Api3DEng_Shared.inc
; Author:     G. Friedrich
; Version:    See Api3DEng.asm
; Purpose:    ObjAsm Api3DEng program.
; ==================================================================================================


;General information
APP_TITLE                     textequ   <Api3DEng>
ABOUT_TEXT                    textequ   <Api3DEng - 3D CPU rendering engine>
COPYRIGHT                     textequ   <G. Friedrich   October 2017> 
VER_FILEVERSION               equ       2,0,0,0
VER_FILEVERSION_STR           textequ   <2.0>
VER_PRODUCTVERSION            equ       2,0,0,0
VER_PRODUCTVERSION_STR        textequ   <2.0>

;Build information - updated automatically -
BUILD_NUMBER                  equ       61
BUILD_DATE_STR                textequ   <2024-05-25>
BUILD_BITNESS                 equ       64
BUILD_MODE                    equ       RLS

;Menu IDs
IDM_FILE                      equ       050
IDM_FILE_OPEN                 equ       051
IDM_FILE_SAVE                 equ       052
IDM_FILE_EXIT                 equ       059

IDM_SCENE_CAM1                equ       070
IDM_SCENE_CAM2                equ       071
IDM_SCENE_X1                  equ       072
IDM_SCENE_X2                  equ       073
IDM_SCENE_Y1                  equ       074
IDM_SCENE_Y2                  equ       075
IDM_SCENE_Z1                  equ       076
IDM_SCENE_Z2                  equ       077
IDM_SCENE_ANIMATE             equ       078
IDM_SCENE_DRAWWIRE            equ       079

IDM_HELP                      equ       090
IDM_HELP_HELP                 equ       091
IDM_HELP_ABOUT                equ       092

;Bitmap IDs
IDB_FILE_NEW                  equ       002
IDB_FILE_OPEN                 equ       003
IDB_FILE_SAVE                 equ       004
IDB_FILE_CLOSE                equ       005
IDB_FILE_EXIT                 equ       006

IDB_HELP_HELP                 equ       007
IDB_HELP_ABOUT                equ       008

;Control IDs
IDC_TEXT_ABOUT                equ       100
IDC_STATUSBAR                 equ       102

;Language IDs
IDLANG_ENGLISH                equ       000


BUILD_BIN_FORMAT              equ       EXE
BUILD_BIN_SUFFIX_STR          textequ   <>
