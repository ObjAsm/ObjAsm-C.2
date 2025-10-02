; ==================================================================================================
; Title:      IFileDialogApp_Shared.inc
; Author:     G. Friedrich
; Version:    See IFileDialog.asm
; Purpose:    ObjAsm IFileDialog Application.
; ==================================================================================================


;General information
APP_TITLE                     textequ   <IFileDialogApp>
ABOUT_TEXT                    textequ   <IFileDialog demo>
COPYRIGHT                     textequ   <G. Friedrich   October 2017> 
VER_FILEVERSION               equ       1,0,0,0
VER_FILEVERSION_STR           textequ   <1.0>
VER_PRODUCTVERSION            equ       1,0,0,0
VER_PRODUCTVERSION_STR        textequ   <1.0>

;Build information - updated automatically -
BUILD_NUMBER                  equ       29
BUILD_DATE_STR                textequ   <2025-10-02>
BUILD_BITNESS                 equ       64
BUILD_MODE                    equ       RLS

IDM_OPEN                      equ       1001
IDM_EXIT                      equ       1002
IDM_HELP                      equ       2001
IDM_ABOUT                     equ       2002

BUILD_BIN_FORMAT              equ       EXE
BUILD_BIN_SUFFIX_STR          textequ   <>
