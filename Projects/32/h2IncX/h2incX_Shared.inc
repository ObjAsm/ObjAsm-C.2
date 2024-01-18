; ==================================================================================================
; Title:      h2incX_Shared.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    Share some values with rc.exe.
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


;General information
APP_TITLE                     textequ   <h2incX>
ABOUT_TEXT                    textequ   <h2incX>
COPYRIGHT                     textequ   <G. Friedrich   October 2017> 
VER_FILEVERSION               equ       2,0,0,0
VER_FILEVERSION_STR           textequ   <2.0>
VER_PRODUCTVERSION            equ       2,0,0,0
VER_PRODUCTVERSION_STR        equ       <2.0>

;Build information - updated automatically -
BUILD_NUMBER                  equ       139
BUILD_DATE_STR                textequ   <2024-01-18>
BUILD_BITNESS                 equ       32
BUILD_MODE                    equ       DBG

BUILD_BIN_FORMAT              equ       EXE
BUILD_BIN_SUFFIX_STR          textequ   <>
