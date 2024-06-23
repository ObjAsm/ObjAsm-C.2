; ==================================================================================================
; Title:      h2inc+_Shared.inc
; Author:     G. Friedrich
; Version:    See h2inc+.asm
; Purpose:    ObjAsm shared values with rc.exe.
; ==================================================================================================


;General information
APP_TITLE                     textequ   <h2inc+>
ABOUT_TEXT                    textequ   <h2inc+>
VERSION                       textequ   <C.2.0>
COPYRIGHT                     textequ   <(C) G. Friedrich April 2024>
VER_FILEVERSION               equ       2,0,0,0
VER_FILEVERSION_STR           textequ   <2.0>
VER_PRODUCTVERSION            equ       2,0,0,0
VER_PRODUCTVERSION_STR        textequ   <2.0>

;Build information - updated automatically -
BUILD_NUMBER                  equ       11
BUILD_DATE_STR                textequ   <2024-06-23>
BUILD_BITNESS                 equ       64
BUILD_MODE                    equ       DBG

BUILD_BIN_FORMAT              equ       EXE
BUILD_BIN_SUFFIX_STR          textequ   <>
