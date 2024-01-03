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
BUILD_NUMBER                  equ       15
BUILD_DATE_STR                textequ   <2024-01-03>
BUILD_BITNESS                 equ       64
BUILD_MODE                    equ       RLS

IDM_SEND                      equ       1000
IDM_EXIT                      equ       1001
IDM_HELP                      equ       1100
IDM_ABOUT                     equ       1101

IDD_DLG_SEND                  equ       1000
IDC_BTN_CONNECT               equ       2001
IDC_BTN_DISCONNECT            equ       2002
IDC_EDT_ADDRESS               equ       2003
IDC_EDT_PORT                  equ       2005
IDC_EDT_CONNECTIONS           equ       2007
IDC_BTN_SEND                  equ       3001
IDC_EDT_DATA                  equ       3002
IDC_EDT_REPETITIONS           equ       3004

BUILD_BIN_FORMAT              equ       EXE
BUILD_BIN_SUFFIX_STR          textequ   <>
