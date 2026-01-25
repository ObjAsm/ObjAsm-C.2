; ==================================================================================================
; Title:      DebugCenter_Globals.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm DebugCenter application.
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


;General information
APP_TITLE                     textequ   <DebugCenter test>
ABOUT_TEXT                    textequ   <DebugCenter test>
COPYRIGHT                     textequ   <G. Friedrich   October 2017> 
VER_FILEVERSION               equ       2,0,0,0
VER_FILEVERSION_STR           textequ   <2.0>
VER_PRODUCTVERSION            equ       2,0,0,0
VER_PRODUCTVERSION_STR        equ       <2.0>

;Build information - updated automatically -
BUILD_NUMBER                  equ       251
BUILD_DATE_STR                textequ   <20.01.2026>
BUILD_BITNESS                 equ       64
BUILD_MODE                    equ       DBG

;Menu IDs
IDM_EXIT                      equ       1000
IDM_HELP                      equ       1001
IDM_ABOUT                     equ       1999


BUILD_BIN_FORMAT              equ       EXE
BUILD_BIN_SUFFIX_STR          textequ   <>
