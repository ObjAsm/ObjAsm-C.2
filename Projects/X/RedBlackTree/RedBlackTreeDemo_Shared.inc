; ==================================================================================================
; Title:      RedBlackTreeDemo_Shared.inc
; Author:     G. Friedrich
; Version:    See RedBlackTreeDemo.asm
; Purpose:    ObjAsm Red-Black Tree Demo Application.
; ==================================================================================================


;General information
APP_TITLE                     textequ   <RedBlackTree Demo Application>
ABOUT_TEXT                    textequ   <RedBlackTree Demo Application>
COPYRIGHT                     textequ   <G. Friedrich   October 2017> 
VER_FILEVERSION               equ       1,0,0,0
VER_FILEVERSION_STR           textequ   <1.0>
VER_PRODUCTVERSION            equ       1,0,0,0
VER_PRODUCTVERSION_STR        textequ   <1.0>

;Build information - updated automatically -
BUILD_NUMBER                  equ       26
BUILD_DATE_STR                textequ   <2024-12-01>
BUILD_BITNESS                 equ       64
BUILD_MODE                    equ       DBG


BUILD_BIN_FORMAT              equ       EXE
BUILD_BIN_SUFFIX_STR          textequ   <>
