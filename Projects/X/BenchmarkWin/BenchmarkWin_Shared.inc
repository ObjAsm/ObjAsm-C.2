; ==================================================================================================
; Title:      BenchmarkWin_Shared.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm shared values.
; ==================================================================================================


;General information
APP_TITLE                     textequ   <Benchmark>
ABOUT_TEXT                    textequ   <Benchmark>
COPYRIGHT                     textequ   <G. Friedrich   January 2023> 
VER_FILEVERSION               equ       1,0,0,0
VER_FILEVERSION_STR           textequ   <1.0>
VER_PRODUCTVERSION            equ       1,0,0,0
VER_PRODUCTVERSION_STR        equ       <1.0>

;Build information - updated automatically -
BUILD_NUMBER                  equ       10
BUILD_DATE_STR                textequ   <2023-01-19>
BUILD_BITNESS                 equ       64
BUILD_MODE                    equ       DBG

