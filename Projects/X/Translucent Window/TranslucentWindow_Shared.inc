; ==================================================================================================
; Title:      TranslucentWindow_Shared.inc
; Author:     G. Friedrich
; Version:    See TranslucentWindow.asm
; Purpose:    ObjAsm Splash Application.
; ==================================================================================================


;General information
APP_TITLE                     textequ   <Translucent Window>
ABOUT_TEXT                    textequ   <Translucent Window>
COPYRIGHT                     textequ   <G. Friedrich   August 2022> 
VER_FILEVERSION               equ       1,0,0,0
VER_FILEVERSION_STR           textequ   <1.0>
VER_PRODUCTVERSION            equ       1,0,0,0
VER_PRODUCTVERSION_STR        textequ   <1.0>

;Build information - updated automatically -
BUILD_NUMBER                  equ       18
BUILD_DATE_STR                textequ   <2024-05-26>
BUILD_BITNESS                 equ       64
BUILD_MODE                    equ       RLS

;Menu IDs
IDM_EXIT                      equ       1000
IDM_HELP                      equ       1001
IDM_ABOUT                     equ       1999


BUILD_BIN_FORMAT              equ       EXE
BUILD_BIN_SUFFIX_STR          textequ   <>
