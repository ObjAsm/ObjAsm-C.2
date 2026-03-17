; ==================================================================================================
; Title:      Demo05_Shared.inc
; Author:     G. Friedrich
; Purpose:    Shared definitions for ObjAsm demonstration application Demo05.
; Version:    See Demo05.asm

; Description:
;   This file provides project metadata and build information for Demo05.
;   The definitions here are included by the resource script (.rc) and may also be referenced by
;   the application framework.
;
;   Several values (e.g., BUILD_NUMBER, BUILD_DATE_STR) are automatically updated during the build
;   process by "Inc2RC.cmd" to ensure consistent version tracking across all compiled components.

; ==================================================================================================


;General information
APP_TITLE                     textequ   <Vector Demo>
ABOUT_TEXT                    textequ   <Vector Demo Application>
COPYRIGHT                     textequ   <G. Friedrich   September 2021> 
VER_FILEVERSION               equ       2,0,0,0
VER_FILEVERSION_STR           textequ   <2.0>
VER_PRODUCTVERSION            equ       2,0,0,0
VER_PRODUCTVERSION_STR        equ       <2.0>

;Build information - updated automatically -
BUILD_NUMBER                  equ       1
BUILD_DATE_STR                textequ   <17.03.2026>
BUILD_BITNESS                 equ       64
BUILD_MODE                    equ       DBG


BUILD_BIN_FORMAT              equ       EXE
BUILD_BIN_SUFFIX_STR          textequ   <>
