; ==================================================================================================
; Title:      XTreeViewDemo_Shared.inc
; Author:     G. Friedrich
; Version:    See XTreeViewDemo.asm
; Purpose:    ObjAsm XTreeview Demo Application.
; ==================================================================================================


;General information
APP_TITLE                     textequ   <XTreeView Demo>
ABOUT_TEXT                    textequ   <Demo>
COPYRIGHT                     textequ   <G. Friedrich   October 2017> 
VER_FILEVERSION               equ       1,0,0,0
VER_FILEVERSION_STR           textequ   <1.0>
VER_PRODUCTVERSION            equ       1,0,0,0
VER_PRODUCTVERSION_STR        textequ   <1.0>

;Build information - updated automatically -
BUILD_NUMBER                  equ       27
BUILD_DATE_STR                textequ   <2024-12-01>
BUILD_BITNESS                 equ       64
BUILD_MODE                    equ       RLS

;Menu IDs
IDM_EXIT                      equ       1000
IDM_HELP                      equ       1001
IDM_ABOUT                     equ       1999
IDM_CONTEXT                   equ       3000

BUILD_BIN_FORMAT              equ       EXE
BUILD_BIN_SUFFIX_STR          textequ   <>
