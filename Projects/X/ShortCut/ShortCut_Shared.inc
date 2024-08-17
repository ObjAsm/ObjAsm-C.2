; ==================================================================================================
; Title:      ShortCut_Shared.inc
; Author:     G. Friedrich
; Version:    See ShortCut.asm
; Purpose:    ObjAsm Shortcut Application.
; ==================================================================================================


;General information
APP_TITLE                     textequ   <ShortCut>
ABOUT_TEXT                    textequ   <ShortCut>
COPYRIGHT                     textequ   <G. Friedrich   October 2017> 
VER_FILEVERSION               equ       1,0,0,0
VER_FILEVERSION_STR           textequ   <1.0>
VER_PRODUCTVERSION            equ       1,0,0,0
VER_PRODUCTVERSION_STR        textequ   <1.0>

;Build information - updated automatically -
BUILD_NUMBER                  equ       22
BUILD_DATE_STR                textequ   <2024-08-17>
BUILD_BITNESS                 equ       64
BUILD_MODE                    equ       RLS

BUILD_BIN_FORMAT              equ       EXE
BUILD_BIN_SUFFIX_STR          textequ   <>
