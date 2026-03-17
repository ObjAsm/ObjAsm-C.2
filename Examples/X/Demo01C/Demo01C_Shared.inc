; ==================================================================================================
; Title:      Demo01C_Shared.inc
; Author:     G. Friedrich
; Purpose:    Shared definitions for ObjAsm application Demo01C.
; Version:    See Demo01C.asm
;
; Description:
;   This file provides project metadata and build information for Demo01C.
;   The definitions here are included by the resource script (.rc) and may also be referenced by
;   the application framework. Values such as BUILD_NUMBER and BUILD_DATE_STR are updated
;   automatically during the build process by Inc2RC.cmd.
;
; ==================================================================================================


; General information
APP_TITLE                     textequ   <Demo01C>
ABOUT_TEXT                    textequ   <Demo01C>
COPYRIGHT                     textequ   <G. Friedrich   October 2017> 
VER_FILEVERSION               equ       2,0,0,0
VER_FILEVERSION_STR           textequ   <2.0>
VER_PRODUCTVERSION            equ       2,0,0,0
VER_PRODUCTVERSION_STR        equ       <2.0>

; Build information - updated automatically -
BUILD_NUMBER                  equ       1
BUILD_DATE_STR                textequ   <16.03.2026>
BUILD_BITNESS                 equ       64
BUILD_MODE                    equ       DBG

; Binary Output Format
BUILD_BIN_FORMAT              equ       EXE
BUILD_BIN_SUFFIX_STR          textequ   <>
