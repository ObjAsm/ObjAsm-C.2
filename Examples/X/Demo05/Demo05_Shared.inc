; ==================================================================================================
; Title:      Demo05_Shared.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm Vector Demo.
; Notes:      Version C.1.0, September 2021
;               - First release.
; ==================================================================================================


;General information
APP_TITLE                     textequ   <Vector Demo>
ABOUT_TEXT                    textequ   <Vector Demo Application>
COPYRIGHT                     textequ   <G. Friedrich   September 2021> 
VER_FILEVERSION               equ       2,0,0,0
VER_FILEVERSION_STR           textequ   <2.0>
VER_PRODUCTVERSION            equ       2,0,0,0
VER_PRODUCTVERSION_STR        equ       <2.0>

;Build information - updated automatically -
BUILD_NUMBER                  equ       91
BUILD_DATE_STR                textequ   <2024-08-17>
BUILD_BITNESS                 equ       64
BUILD_MODE                    equ       DBG


BUILD_BIN_FORMAT              equ       EXE
BUILD_BIN_SUFFIX_STR          textequ   <>
