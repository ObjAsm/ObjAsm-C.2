; ==================================================================================================
; Title:      SRP_Shared.inc
; Author:     G. Friedrich
; Purpose:    See SRP.asm
; ==================================================================================================


;General information
APP_TITLE                     textequ   <Simple Reverse Proxy>
ABOUT_TEXT                    textequ   <Simple Reverse Proxy>
COPYRIGHT                     textequ   <G. Friedrich   December 2025> 
VER_FILEVERSION               equ       2,0,0,0
VER_FILEVERSION_STR           textequ   <2.0>
VER_PRODUCTVERSION            equ       2,0,0,0
VER_PRODUCTVERSION_STR        equ       <2.0>

;Build information - updated automatically -
BUILD_NUMBER                  equ       24
BUILD_DATE_STR                textequ   <2025-12-29>
BUILD_BITNESS                 equ       64
BUILD_MODE                    equ       DBG


BUILD_BIN_FORMAT              equ       EXE
BUILD_BIN_SUFFIX_STR          textequ   <>

;Res\MainDlgDlg.rc
IDD_DLG_MAIN                  equ       1000
IDC_BTN_START                 equ       1001
IDC_BTN_STOP                  equ       1002
IDC_STC_BACKGROUND            equ       1003
IDC_STC_LOCAL_HOST_ADDRESS    equ       1004
IDC_CBO_LOCAL_HOST_ADDRESS    equ       1005
IDC_STC_LOCAL_HOST_PORT       equ       1006
IDC_EDT_LOCAL_HOST_PORT       equ       1007
IDC_UDN_LOCAL_HOST_PORT       equ       1008
IDC_STC_DESTINATION_ADDRESS   equ       1009
IDC_IPA_DESTINATION_ADDRESS   equ       1010
IDC_STC_DESTINATION_PORT      equ       1011
IDC_EDT_DESTINATION_PORT      equ       1012
IDC_UDN_DESTINATION_PORT      equ       1013
