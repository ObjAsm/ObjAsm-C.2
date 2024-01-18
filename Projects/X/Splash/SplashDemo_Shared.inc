; ==================================================================================================
; Title:      SplashDemo_Shared.inc
; Author:     G. Friedrich
; Version:    See SplashDemo.asm
; Purpose:    ObjAsm Splash Application.
; ==================================================================================================


;General information
APP_TITLE                     textequ   <SplashDemo>
ABOUT_TEXT                    textequ   <SplashDemo>
COPYRIGHT                     textequ   <G. Friedrich   October 2017> 
VER_FILEVERSION               equ       1,0,0,0
VER_FILEVERSION_STR           textequ   <1.0>
VER_PRODUCTVERSION            equ       1,0,0,0
VER_PRODUCTVERSION_STR        textequ   <1.0>

;Build information - updated automatically -
BUILD_NUMBER                  equ       25
BUILD_DATE_STR                textequ   <2024-01-18>
BUILD_BITNESS                 equ       64
BUILD_MODE                    equ       RLS

;Menu IDs
IDM_EXIT                      equ       1000
IDM_HELP                      equ       1001
IDM_ABOUT                     equ       1999


BUILD_BIN_FORMAT              equ       EXE
BUILD_BIN_SUFFIX_STR          textequ   <>
