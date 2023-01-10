; ==================================================================================================
; Title:      HttpServer_Shared.inc
; Author:     G. Friedrich
; Version:    See HttpServer.asm
; Purpose:    ObjAsm HTTP Server.
; ==================================================================================================


;General information
APP_TITLE                     textequ   <HTTP Server>
ABOUT_TEXT                    textequ   <HTTP Server>
COPYRIGHT                     textequ   <G. Friedrich   December 2020> 
VER_FILEVERSION               equ       1,0,0,0
VER_FILEVERSION_STR           textequ   <1.0>
VER_PRODUCTVERSION            equ       1,0,0,0
VER_PRODUCTVERSION_STR        textequ   <1.0>

;Build information - updated automatically -
BUILD_NUMBER                  equ       19
BUILD_DATE_STR                textequ   <2023-01-10>
BUILD_BITNESS                 equ       32
BUILD_MODE                    equ       RLS

;Menu IDs
IDM_EXIT                      equ       1000
IDM_HELP                      equ       1001
IDM_ABOUT                     equ       1999

