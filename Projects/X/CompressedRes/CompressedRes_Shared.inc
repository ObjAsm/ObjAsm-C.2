; ==================================================================================================
; Title:      CompressedRes_Shared.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm Compressed Resources.
; Notes:      Version C.1.0, October 2023
;               - First release.
; ==================================================================================================


;General information
APP_TITLE                     textequ   <Compressed Resources   -- Hint: move the mouse wheel -->
ABOUT_TEXT                    textequ   <Compressed Resources>
COPYRIGHT                     textequ   <G. Friedrich   October 2023> 
VER_FILEVERSION               equ       1,0,0,0
VER_FILEVERSION_STR           textequ   <1.0>
VER_PRODUCTVERSION            equ       1,0,0,0
VER_PRODUCTVERSION_STR        equ       <1.0>

;Build information - updated automatically -
BUILD_NUMBER                  equ       48
BUILD_DATE_STR                textequ   <2024-08-17>
BUILD_BITNESS                 equ       64
BUILD_MODE                    equ       RLS

;Menu IDs
IDM_EXIT                      equ       1000
IDM_HELP                      equ       1001
IDM_ABOUT                     equ       1999

IDC_TEXT_ABOUT                equ       100

BUILD_BIN_FORMAT              equ       EXE
BUILD_BIN_SUFFIX_STR          textequ   <>
