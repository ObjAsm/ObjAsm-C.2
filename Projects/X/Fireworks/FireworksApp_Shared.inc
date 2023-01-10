; ==================================================================================================
; Title:      FireworksApp_Shared.inc
; Author:     G. Friedrich
; Version:    See FireworksApp.asm
; Purpose:    ObjAsm Fireworks shared file.
; ==================================================================================================


;General information
APP_TITLE                     textequ   <Fireworks>
ABOUT_TEXT                    textequ   <Fireworks>
COPYRIGHT                     textequ   <G. Friedrich   July 2006> 
VER_FILEVERSION               equ       1,0,0,0
VER_FILEVERSION_STR           textequ   <1.0>
VER_PRODUCTVERSION            equ       1,0,0,0
VER_PRODUCTVERSION_STR        textequ   <1.0>

;Build information - updated automatically -
BUILD_NUMBER                  equ       6
BUILD_DATE_STR                textequ   <2023-01-10>
BUILD_BITNESS                 equ       64
BUILD_MODE                    equ       RLS

;Menu IDs
IDM_EXIT                      equ       1000
IDM_DIALOG                    equ       1001
IDM_HELP                      equ       2000
IDM_ABOUT                     equ       2001

