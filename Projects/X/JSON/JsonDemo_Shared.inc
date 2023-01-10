; ==================================================================================================
; Title:      JsonDemo_Shared.inc
; Author:     G. Friedrich
; Version:    See JsonDemo.asm
; Purpose:    ObjAsm JSON Application.
; ==================================================================================================


;General information
APP_TITLE                     textequ   <JSON Demo>
ABOUT_TEXT                    textequ   <JSON Demo>
COPYRIGHT                     textequ   <G. Friedrich   December 2020> 
VER_FILEVERSION               equ       1,0,0,0
VER_FILEVERSION_STR           textequ   <1.0>
VER_PRODUCTVERSION            equ       1,0,0,0
VER_PRODUCTVERSION_STR        textequ   <1.0>

;Build information - updated automatically -
BUILD_NUMBER                  equ       22
BUILD_DATE_STR                textequ   <2023-01-10>
BUILD_BITNESS                 equ       64
BUILD_MODE                    equ       DBG

;Menu IDs
IDM_EXIT                      equ       1000
IDM_HELP                      equ       1001
IDM_ABOUT                     equ       1999
