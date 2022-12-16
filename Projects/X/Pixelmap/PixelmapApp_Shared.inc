; ==================================================================================================
; Title:      PixelmapApp_Shared.inc
; Author:     G. Friedrich
; Version:    See PixelmapApp.asm
; Purpose:    ObjAsm Pixelmap Application.
; ==================================================================================================


;General information
APP_TITLE                     textequ   <Pixelmap Application>
ABOUT_TEXT                    textequ   <Pixelmap Demo Application>
COPYRIGHT                     textequ   <G. Friedrich   October 2017> 
VER_FILEVERSION               equ       1,0,0,0
VER_FILEVERSION_STR           textequ   <1.0>
VER_PRODUCTVERSION            equ       1,0,0,0
VER_PRODUCTVERSION_STR        textequ   <1.0>

;Build information - updated automatically -
BUILD_NUMBER                  equ       19
BUILD_DATE_STR                textequ   <2022-12-15>
BUILD_BITNESS                 equ       64
BUILD_MODE                    equ       RLS

;Menu IDs
IDM_EXIT                      equ       1000
IDM_HELP                      equ       1001
IDM_ABOUT                     equ       1999
