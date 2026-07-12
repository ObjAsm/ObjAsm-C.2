; ==================================================================================================
; Title:      ResGuard_Shared.inc
; Author:     G. Friedrich
; Version:    See ResGuard.asm
; Purpose:    Detection of OS resource leaks using ObjAsm ResGuardxx.dll.
; ==================================================================================================


APP_TITLE                     textequ   <ResGuard>
ABOUT_TEXT                    textequ   <ResGuard>
COPYRIGHT                     textequ   <G. Friedrich - August 2023>
VER_FILEVERSION               equ       1,1,0,0
VER_FILEVERSION_STR           textequ   <1.1>
VER_PRODUCTVERSION            equ       1,1,0,0
VER_PRODUCTVERSION_STR        textequ   <1.1>

;Build information - updated automatically -
BUILD_NUMBER                  equ       26
BUILD_DATE_STR                textequ   <2026-07-12>
BUILD_BITNESS                 equ       32
BUILD_MODE                    equ       DBG

BUILD_BIN_FORMAT              equ       DLL
BUILD_BIN_SUFFIX_STR          textequ   <32>
