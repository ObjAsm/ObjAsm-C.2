; ==================================================================================================
; Title:      DLApp_Shared.inc
; Author:     G. Friedrich
; Version:    See DLApp.asm
; Purpose:    ObjAsm Dynamic Window Layout Application.
; ==================================================================================================


;General information
APP_TITLE                     textequ   <Dynamic Layout Application>
ABOUT_TEXT                    textequ   <Dynamic Layout Application>
COPYRIGHT                     textequ   <G. Friedrich   October 2017> 
VER_FILEVERSION               equ       1,0,0,0
VER_FILEVERSION_STR           textequ   <1.0>
VER_PRODUCTVERSION            equ       1,0,0,0
VER_PRODUCTVERSION_STR        textequ   <1.0>

;Build information - updated automatically -
BUILD_NUMBER                  equ       32
BUILD_DATE_STR                textequ   <2024-05-29>
BUILD_BITNESS                 equ       64
BUILD_MODE                    equ       RLS

;Menu IDs
IDM_EXIT                      equ       1000
IDM_DIALOG                    equ       1001
IDM_HELP                      equ       2000
IDM_ABOUT                     equ       2001


BUILD_BIN_FORMAT              equ       EXE
BUILD_BIN_SUFFIX_STR          textequ   <>
