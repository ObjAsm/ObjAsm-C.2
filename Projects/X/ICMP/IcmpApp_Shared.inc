; ==================================================================================================
; Title:      IcmpApp_Shared.inc
; Author:     G. Friedrich
; Version:    C.2.0
; Purpose:    ObjAsm IcmpApp.
; Notes:      Version C.2.0, December 2022
;               - First release.
; ==================================================================================================


;General information
APP_TITLE                     textequ   <Internet Control Message Protocol Application>
ABOUT_TEXT                    textequ   <Internet Control Message Protocol Application>
COPYRIGHT                     textequ   <G. Friedrich   December 2022> 
VER_FILEVERSION               equ       1,0,0,0
VER_FILEVERSION_STR           textequ   <1.0>
VER_PRODUCTVERSION            equ       1,0,0,0
VER_PRODUCTVERSION_STR        equ       <1.0>

;Build information - updated automatically -
BUILD_NUMBER                  equ       13
BUILD_DATE_STR                textequ   <2024-10-23>
BUILD_BITNESS                 equ       32
BUILD_MODE                    equ       DBG

;Menu IDs
IDM_EXIT                      equ       1000
IDM_PING                      equ       2000
IDM_TRACE                     equ       3000
IDM_DESTINATION               equ       4000
IDM_HELP                      equ       9001
IDM_ABOUT                     equ       9002

IDC_DAB_ICON                  equ       100
IDC_DAB_TEXT                  equ       101


;Destination Dialog
IDD_DLG_DESTINATION           equ       1000
IDC_RBN_IPV4                  equ       1001
IDC_RBN_IPV6                  equ       1002
IDC_RBN_URL                   equ       1003
IDC_EDT_DESTINATION           equ       1004
IDC_GRP                       equ       1005  
IDC_STC_DEST                  equ       1006              

BUILD_BIN_FORMAT              equ       EXE
BUILD_BIN_SUFFIX_STR          textequ   <>
