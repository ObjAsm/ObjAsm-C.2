; ==================================================================================================
; Title:      ArduinoCom_Shared.inc
; Author:     G. Friedrich
; Version:    See ArduinoCom.asm
; Purpose:    ObjAsm Arduino Communication program.
; ==================================================================================================


;General information
APP_TITLE                     textequ   <Arduino Communication Demo>
ABOUT_TEXT                    textequ   <Arduino Communication Demo>
COPYRIGHT                     textequ   <G. Friedrich   October 2020> 
VER_FILEVERSION               equ       1,0,0,0
VER_FILEVERSION_STR           textequ   <1.0>
VER_PRODUCTVERSION            equ       1,0,0,0
VER_PRODUCTVERSION_STR        textequ   <1.0>

;Build information - updated automatically -
BUILD_NUMBER                  equ       21
BUILD_DATE_STR                textequ   <2024-01-03>
BUILD_BITNESS                 equ       32
BUILD_MODE                    equ       DBG

;Menu IDs
IDM_SELECTION                 equ       1001
IDM_CONNECT                   equ       1002
IDM_DISCONNECT                equ       1003
IDM_TRANSMIT                  equ       1004
IDM_RECIEVE                   equ       1005
IDM_EXIT                      equ       1010
IDM_HELP                      equ       2001
IDM_ABOUT                     equ       2002


BUILD_BIN_FORMAT              equ       EXE
BUILD_BIN_SUFFIX_STR          textequ   <>
