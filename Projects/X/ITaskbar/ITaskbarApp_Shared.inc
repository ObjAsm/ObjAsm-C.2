; ==================================================================================================
; Title:      ITaskbarApp_Shared.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm ITaskbar Demo.
; Notes:      Version C.1.0, January 2023
;               - First release.
; ==================================================================================================


;General information
APP_TITLE                     textequ   <ITaskbar Demo>
ABOUT_TEXT                    textequ   <ITaskbar Demo>
COPYRIGHT                     textequ   <G. Friedrich   January 2023> 
VER_FILEVERSION               equ       2,0,0,0
VER_FILEVERSION_STR           textequ   <2.0>
VER_PRODUCTVERSION            equ       2,0,0,0
VER_PRODUCTVERSION_STR        equ       <2.0>

;Build information - updated automatically -
BUILD_NUMBER                  equ       41
BUILD_DATE_STR                textequ   <2024-12-01>
BUILD_BITNESS                 equ       64
BUILD_MODE                    equ       RLS

;Menu IDs
IDM_EXIT                      equ       1000
IDM_HELP                      equ       1001
IDM_ABOUT                     equ       1999

BUILD_BIN_FORMAT              equ       EXE
BUILD_BIN_SUFFIX_STR          textequ   <>
