; ==================================================================================================
; Title:      NetComServer_Shared.inc
; Author:     G. Friedrich
; Version:    See NetComServer.asm
; Purpose:    NetCom Server Application.
; ==================================================================================================


;General information
APP_TITLE                     textequ   <NetCom Server>
ABOUT_TEXT                    textequ   <NetComServer>
COPYRIGHT                     textequ   <G. Friedrich   October 2017> 
VER_FILEVERSION               equ       1,0,0,0
VER_FILEVERSION_STR           textequ   <1.0>
VER_PRODUCTVERSION            equ       1,0,0,0
VER_PRODUCTVERSION_STR        textequ   <1.0>

;Build information - updated automatically -
BUILD_NUMBER                  equ       17
BUILD_DATE_STR                textequ   <2025-12-30>
BUILD_BITNESS                 equ       64
BUILD_MODE                    equ       DBG

IDM_SEND                      equ       1000
IDM_EXIT                      equ       1001
IDM_HELP                      equ       1100
IDM_ABOUT                     equ       1101

BUILD_BIN_FORMAT              equ       EXE
BUILD_BIN_SUFFIX_STR          textequ   <>
