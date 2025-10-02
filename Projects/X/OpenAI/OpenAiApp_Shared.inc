; ==================================================================================================
; Title:      OpenAiApp_Shared.inc
; Author:     G. Friedrich
; Version:    C.2.0
; Purpose:    ObjAsm OpenAI Application.
; Notes:      See OpenAIApp.asm
; ==================================================================================================


;General information
APP_TITLE                     textequ   <OpenAI>
ABOUT_TEXT                    textequ   <OpenAI>
COPYRIGHT                     textequ   <G. Friedrich   September 2025> 
VER_FILEVERSION               equ       1,0,0,0
VER_FILEVERSION_STR           textequ   <1.0>
VER_PRODUCTVERSION            equ       1,0,0,0
VER_PRODUCTVERSION_STR        equ       <1.0>

;Build information - updated automatically -
BUILD_NUMBER                  equ       2
BUILD_DATE_STR                textequ   <2025-10-02>
BUILD_BITNESS                 equ       64
BUILD_MODE                    equ       DBG

BUILD_BIN_FORMAT              equ       EXE
BUILD_BIN_SUFFIX_STR          textequ   <>
