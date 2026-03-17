; ==================================================================================================
; Title:      Demo08_Shared.inc
; Author:     G. Friedrich
; Purpose:    Shared definitions for ObjAsm demonstration application Demo08.
; Version:    See Demo08.asm

; Description:
;   This file provides project metadata and build information for Demo08.
;   The definitions here are included by the resource script (.rc) and may also be referenced by
;   the application framework.
;
;   Several values (e.g., BUILD_NUMBER, BUILD_DATE_STR) are automatically updated during the build
;   process by "Inc2RC.cmd" to ensure consistent version tracking across all compiled components.

; ==================================================================================================


;General information
APP_TITLE                     textequ   <Demo08>
ABOUT_TEXT                    textequ   <DlgApp Demo>
COPYRIGHT                     textequ   <G. Friedrich   September 2021> 
VER_FILEVERSION               equ       2,0,0,0
VER_FILEVERSION_STR           textequ   <2.0>
VER_PRODUCTVERSION            equ       2,0,0,0
VER_PRODUCTVERSION_STR        equ       <2.0>

;Build information - updated automatically -
BUILD_NUMBER                  equ       2
BUILD_DATE_STR                textequ   <17.03.2026>
BUILD_BITNESS                 equ       64
BUILD_MODE                    equ       RLS

;Res\MainDlgDlg.rc
IDD_DLG_MAIN                  equ       1000
IDC_STC_MESSAGE               equ       1001


BUILD_BIN_FORMAT              equ       EXE
BUILD_BIN_SUFFIX_STR          textequ   <>
