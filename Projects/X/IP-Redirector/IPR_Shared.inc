; ==================================================================================================
; Title:      IPR_Shared.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm application.
; Notes:      Version C.1.0, January 2023
;               - First release.
; ==================================================================================================


;General information
APP_TITLE                     textequ   <IP Redirector>
ABOUT_TEXT                    textequ   <IP Redirector>
COPYRIGHT                     textequ   <G. Friedrich   January 2023> 
VER_FILEVERSION               equ       2,0,0,0
VER_FILEVERSION_STR           textequ   <2.0>
VER_PRODUCTVERSION            equ       2,0,0,0
VER_PRODUCTVERSION_STR        equ       <2.0>

;Build information - updated automatically -
BUILD_NUMBER                  equ       6
BUILD_DATE_STR                textequ   <2024-01-05>
BUILD_BITNESS                 equ       64
BUILD_MODE                    equ       RLS

;Res\MainDlgDlg.rc
IDD_DLG_MAIN                  equ       1000
IDC_STC_MESSAGE               equ       1001


BUILD_BIN_FORMAT              equ       EXE
BUILD_BIN_SUFFIX_STR          textequ   <>
