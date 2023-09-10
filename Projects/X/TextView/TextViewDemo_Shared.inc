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
BUILD_NUMBER                  equ       23
BUILD_DATE_STR                textequ   <2023-09-10>
BUILD_BITNESS                 equ       64
BUILD_MODE                    equ       DBG

;Menu IDs
IDM_EXIT                      equ       1000
IDM_HELP                      equ       1001
IDM_ABOUT                     equ       1999

