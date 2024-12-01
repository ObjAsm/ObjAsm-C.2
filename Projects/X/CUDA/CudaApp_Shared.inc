; ==================================================================================================
; Title:      CudaApp_Shared.inc
; Author:     G. Friedrich
; Version:    See Application.asm
; Purpose:    ObjAsm CUDA application.
; ==================================================================================================


;General information
APP_TITLE                     textequ   <CudaApp>
ABOUT_TEXT                    textequ   <CUDA Demo Application>
COPYRIGHT                     textequ   <G. Friedrich   October 2017> 
VER_FILEVERSION               equ       1,0,0,0
VER_FILEVERSION_STR           textequ   <1.0>
VER_PRODUCTVERSION            equ       1,0,0,0
VER_PRODUCTVERSION_STR        textequ   <1.0>

;Build information - updated automatically -
BUILD_NUMBER                  equ       47
BUILD_DATE_STR                textequ   <2024-12-01>
BUILD_BITNESS                 equ       64
BUILD_MODE                    equ       RLS

;Res\MainDlgDlg.rc
IDD_DLG_MAIN                  equ       1000
IDC_STC_MESSAGE               equ       1001

BUILD_BIN_FORMAT              equ       EXE
BUILD_BIN_SUFFIX_STR          textequ   <>
