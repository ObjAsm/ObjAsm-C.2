; ==================================================================================================
; Title:      SVC_Client_Shared.inc
; Author:     G. Friedrich
; Notes:      See SVC_Client.asm
; ==================================================================================================


;General information
APP_TITLE                     textequ   <SVC_Client>
ABOUT_TEXT                    textequ   <SVC_Client>
COPYRIGHT                     textequ   <G. Friedrich   December 2025> 
VER_FILEVERSION               equ       2,0,0,0
VER_FILEVERSION_STR           textequ   <2.0>
VER_PRODUCTVERSION            equ       2,0,0,0
VER_PRODUCTVERSION_STR        equ       <2.0>

;Build information - updated automatically -
BUILD_NUMBER                  equ       29
BUILD_DATE_STR                textequ   <2025-12-20>
BUILD_BITNESS                 equ       64
BUILD_MODE                    equ       RLS


BUILD_BIN_FORMAT              equ       EXE
BUILD_BIN_SUFFIX_STR          textequ   <>


;Res\MainWnd.dlg
IDD_DLG_MAIN                  equ       2000

IDOK                          equ       1
IDC_STC_CMD                   equ       2001
IDC_EDT_CMD                   equ       2002
IDC_BTN_SEND                  equ       2003
IDC_STC_RESP                  equ       2004
IDC_EDT_RESP                  equ       2005
