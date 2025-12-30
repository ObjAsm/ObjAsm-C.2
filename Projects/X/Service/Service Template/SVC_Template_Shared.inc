; ==================================================================================================
; Title:      SVC_Template_Shared.inc
; Author:     G. Friedrich
; Notes:      See SVC_Template.asm.
; ==================================================================================================


;General information
APP_TITLE                     textequ   <SVC_Template>
ABOUT_TEXT                    textequ   <SVC_Template>
COPYRIGHT                     textequ   <G. Friedrich   December 2025> 
VER_FILEVERSION               equ       1,0,0,0
VER_FILEVERSION_STR           textequ   <1.0>
VER_PRODUCTVERSION            equ       1,0,0,0
VER_PRODUCTVERSION_STR        equ       <1.0>

;Build information - updated automatically -
BUILD_NUMBER                  equ       2
BUILD_DATE_STR                textequ   <2025-12-30>
BUILD_BITNESS                 equ       64
BUILD_MODE                    equ       DBG



BUILD_BIN_FORMAT              equ       EXE
BUILD_BIN_SUFFIX_STR          textequ   <>
