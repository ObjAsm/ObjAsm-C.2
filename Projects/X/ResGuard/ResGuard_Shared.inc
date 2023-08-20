; ==================================================================================================
; Title:      ResGuard_Shared.inc
; Author:     G. Friedrich
; Version:    See ResGuard.asm
; Purpose:    ObjAsm ResGuard shared information.
; ==================================================================================================


;General information
APP_TITLE                     textequ   <ResGuard>
ABOUT_TEXT                    textequ   <ResGuard>
COPYRIGHT                     textequ   <G. Friedrich   October 2017> 
VER_FILEVERSION               equ       2,0,0,0
VER_FILEVERSION_STR           textequ   <2.0>
VER_PRODUCTVERSION            equ       2,0,0,0
VER_PRODUCTVERSION_STR        textequ   <2.0>

;Build information - updated automatically -
BUILD_NUMBER                  equ       2
BUILD_DATE_STR                textequ   <2023-08-20>
BUILD_BITNESS                 equ       64
BUILD_MODE                    equ       DBG
