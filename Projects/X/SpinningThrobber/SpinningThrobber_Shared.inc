; ==================================================================================================
; Title:      SpinningThrobber_Shared.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm Spinning Throbber.
; Notes:      Version C.1.0, August 2022
;               - First release.
; ==================================================================================================


;General information
APP_TITLE                     textequ   <Spinning Throbber>
ABOUT_TEXT                    textequ   <Spinning Throbber>
COPYRIGHT                     textequ   <G. Friedrich   August 2022> 
VER_FILEVERSION               equ       2,0,0,0
VER_FILEVERSION_STR           textequ   <2.0>
VER_PRODUCTVERSION            equ       2,0,0,0
VER_PRODUCTVERSION_STR        equ       <2.0>

;Build information - updated automatically -
BUILD_NUMBER                  equ       46
BUILD_DATE_STR                textequ   <2025-10-02>
BUILD_BITNESS                 equ       64
BUILD_MODE                    equ       RLS

;Menu IDs
IDM_EXIT                      equ       1001
IDM_START_1                   equ       2001
IDM_START_2                   equ       2002
IDM_STOP_1                    equ       3001
IDM_STOP_2                    equ       3002
IDM_HELP                      equ       5001
IDM_ABOUT                     equ       5002

BUILD_BIN_FORMAT              equ       EXE
BUILD_BIN_SUFFIX_STR          textequ   <>
