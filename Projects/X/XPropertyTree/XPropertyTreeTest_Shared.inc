; ==================================================================================================
; Title:      XPropertyTreeTest_Shared.inc
; Author:     G. Friedrich
; Version:    XPropertyTreeTest.asm
; Purpose:    ObjAsm XPropertyTree Test Application.
; ==================================================================================================


;General information
APP_TITLE                     textequ   <XPropertyTree Demo>
ABOUT_TEXT                    textequ   <XPropertyTree>
COPYRIGHT                     textequ   <G. Friedrich   October 2017> 
VER_FILEVERSION               equ       1,0,0,0
VER_FILEVERSION_STR           textequ   <1.0>
VER_PRODUCTVERSION            equ       1,0,0,0
VER_PRODUCTVERSION_STR        textequ   <1.0>

;Build information - updated automatically -
BUILD_NUMBER                  equ       30
BUILD_DATE_STR                textequ   <2024-10-23>
BUILD_BITNESS                 equ       64
BUILD_MODE                    equ       RLS

;Menu IDs
IDM_EXIT                      equ       1000
IDM_HELP                      equ       1001
IDM_ABOUT                     equ       1999
IDM_CONTEXT                   equ       3000

BUILD_BIN_FORMAT              equ       EXE
BUILD_BIN_SUFFIX_STR          textequ   <>
