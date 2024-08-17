; ==================================================================================================
; Title:      ResGuard_Shared.inc
; Author:     G. Friedrich
; Version:    See ResGuard.asm
; Purpose:    ObjAsm ResGuard shared information.
; ==================================================================================================


;General information
APP_TITLE                     textequ   <ResGuard>
ABOUT_TEXT                    textequ   <ResGuard>
COPYRIGHT                     textequ   <G. Friedrich   August 2023> 
VER_FILEVERSION               equ       3,1,0,0
VER_FILEVERSION_STR           textequ   <3.1>
VER_PRODUCTVERSION            equ       3,1,0,0
VER_PRODUCTVERSION_STR        textequ   <3.1>

;Build information - updated automatically -
BUILD_NUMBER                  equ       35
BUILD_DATE_STR                textequ   <2024-08-17>
BUILD_BITNESS                 equ       64
BUILD_MODE                    equ       DBG

BUILD_BIN_FORMAT              equ       DLL
BUILD_BIN_SUFFIX_STR          textequ   <64>
