; ==================================================================================================
; Title:      TextViewDemo_Shared.inc
; Author:     G. Friedrich
; Version:    See TextViewDemo.asm
; Purpose:    ObjAsm TextView Demo Application resource file.
; ==================================================================================================


;General information
APP_TITLE                     textequ   <TextView Demo>
ABOUT_TEXT                    textequ   <TextView Demo>
COPYRIGHT                     textequ   <G. Friedrich,  April 2020> 
VER_FILEVERSION               equ       1,0,0,0
VER_FILEVERSION_STR           textequ   <1.0>
VER_PRODUCTVERSION            equ       1,0,0,0
VER_PRODUCTVERSION_STR        textequ   <1.0>

;Build information - updated automatically -
BUILD_NUMBER                  equ       31
BUILD_DATE_STR                textequ   <2025-03-09>
BUILD_BITNESS                 equ       64
BUILD_MODE                    equ       RLS

;Menu IDs
IDM_EXIT                      equ       1000
IDM_HELP                      equ       1001
IDM_ABOUT                     equ       1999


BUILD_BIN_FORMAT              equ       EXE
BUILD_BIN_SUFFIX_STR          textequ   <>
