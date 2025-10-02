; ==================================================================================================
; Title:      XML_Shared.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm DOM-XML Test.
; Notes:      Version C.1.0, November 2024
;               - First release.
; ==================================================================================================


;General information
APP_TITLE                     textequ   <XML-DOM Test>
ABOUT_TEXT                    textequ   <XML-DOM Test>
COPYRIGHT                     textequ   <G. Friedrich   November 2024> 
VER_FILEVERSION               equ       1,0,0,0
VER_FILEVERSION_STR           textequ   <1.0>
VER_PRODUCTVERSION            equ       1,0,0,0
VER_PRODUCTVERSION_STR        equ       <1.0>

;Build information - updated automatically -
BUILD_NUMBER                  equ       16
BUILD_DATE_STR                textequ   <2025-10-02>
BUILD_BITNESS                 equ       64
BUILD_MODE                    equ       RLS

;Menu IDs
IDM_EXIT                      equ       1000
IDM_HELP                      equ       1001
IDM_ABOUT                     equ       1999

IDC_TEXT_ABOUT                equ       100

BUILD_BIN_FORMAT              equ       EXE
BUILD_BIN_SUFFIX_STR          textequ   <>
