; ==================================================================================================
; Title:      NetComClient_Shared.inc
; Author:     G. Friedrich
; Version:    See NetComClient.asm
; Purpose:    NetCom Client Application.
; ==================================================================================================


;General information
APP_TITLE                     textequ   <NetCom Client>
ABOUT_TEXT                    textequ   <NetComClient>
COPYRIGHT                     textequ   <G. Friedrich   October 2017>
VER_FILEVERSION               equ       1,0,0,0
VER_FILEVERSION_STR           textequ   <1.0>
VER_PRODUCTVERSION            equ       1,0,0,0
VER_PRODUCTVERSION_STR        textequ   <1.0>

;Build information - updated automatically -
BUILD_NUMBER                  equ       1
BUILD_DATE_STR                textequ   <2025-12-30>
BUILD_BITNESS                 equ       64
BUILD_MODE                    equ       RLS

IDM_SEND                      equ       1000
IDM_EXIT                      equ       1001
IDM_HELP                      equ       1100
IDM_ABOUT                     equ       1101

IDD_DLG_SEND                  equ       1000
IDC_BTN_CONNECT               equ       1001
IDC_BTN_DISCONNECT            equ       1002
IDC_EDT_ADDRESS               equ       1005
IDC_EDT_PORT                  equ       1007
IDC_UDN_PORT                  equ       1008

BUILD_BIN_FORMAT              equ       EXE
BUILD_BIN_SUFFIX_STR          textequ   <>
