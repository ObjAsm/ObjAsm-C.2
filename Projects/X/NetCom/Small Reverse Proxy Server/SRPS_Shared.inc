; ==================================================================================================
; Title:      SRPS_Shared.inc
; Author:     G. Friedrich
; Purpose:    See SRPS.asm
; ==================================================================================================


;General information
APP_TITLE                     textequ   <SRPS>
ABOUT_TEXT                    textequ   <Smart Reverse Proxy Server>
COPYRIGHT                     textequ   <G. Friedrich   December 2025> 
VER_FILEVERSION               equ       2,0,0,0
VER_FILEVERSION_STR           textequ   <2.0>
VER_PRODUCTVERSION            equ       2,0,0,0
VER_PRODUCTVERSION_STR        equ       <2.0>

;Build information - updated automatically -
BUILD_NUMBER                  equ       42
BUILD_DATE_STR                textequ   <15.01.2026>
BUILD_BITNESS                 equ       64
BUILD_MODE                    equ       DBG


BUILD_BIN_FORMAT              equ       EXE
BUILD_BIN_SUFFIX_STR          textequ   <>

;Res\MainDlgDlg.rc
IDD_DLG_MAIN                  equ       1000
IDC_BTN_START                 equ       1001
IDC_BTN_STOP                  equ       1002
IDC_STC_BACKGROUND            equ       1003

IDC_GRP_CLIENT                equ       1100
IDC_STC_CLIENT_LOCAL_ADDR     equ       1101
IDC_CBO_CLIENT_LOCAL_ADDR     equ       1102
IDC_STC_CLIENT_LOCAL_PORT     equ       1103
IDC_EDT_CLIENT_LOCAL_PORT     equ       1104
IDC_UDN_CLIENT_LOCAL_PORT     equ       1105

IDC_GRP_SERVER                equ       1200
IDC_STC_SERVER_LOCAL_ADDR     equ       1201
IDC_CBO_SERVER_LOCAL_ADDR     equ       1202
IDC_CHK_SERVER_USE_EPHEM_PORT equ       1203
IDC_STC_SERVER_LOCAL_PORT     equ       1204
IDC_EDT_SERVER_LOCAL_PORT     equ       1205
IDC_UDN_SERVER_LOCAL_PORT     equ       1206
IDC_STC_SERVER_REMOTE_ADDR    equ       1207
IDC_CBO_SERVER_REMOTE_ADDR    equ       1208
IDC_STC_SERVER_REMOTE_PORT    equ       1209
IDC_EDT_SERVER_REMOTE_PORT    equ       1210
IDC_UDN_SERVER_REMOTE_PORT    equ       1211
