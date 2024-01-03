; ==================================================================================================
; Title:      ML_GUI_Shared.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm Multilanguage GUI.
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


;General information
APP_TITLE                     textequ   <Multilanguage GUI>
ABOUT_TEXT                    textequ   <Multilanguage GUI>
COPYRIGHT                     textequ   <G. Friedrich   November 2022> 
VER_FILEVERSION               equ       2,0,0,0
VER_FILEVERSION_STR           textequ   <2.0>
VER_PRODUCTVERSION            equ       2,0,0,0
VER_PRODUCTVERSION_STR        equ       <2.0>

;Build information - updated automatically -
BUILD_NUMBER                  equ       59
BUILD_DATE_STR                textequ   <2024-01-03>
BUILD_BITNESS                 equ       64
BUILD_MODE                    equ       RLS

;Menu IDs
IDM_FILE                      equ       1000
IDM_TEST                      equ       1001
IDM_EXIT                      equ       1002

IDM_LANGUAGE                  equ       2000
IDM_LANG_BOSNIAN              equ       2001
IDM_LANG_CHINESE              equ       2002
IDM_LANG_CZECH                equ       2003
IDM_LANG_ENGLISH              equ       2004
IDM_LANG_FRENCH               equ       2005
IDM_LANG_GERMAN               equ       2006
IDM_LANG_GREEK                equ       2007
IDM_LANG_POLNISH              equ       2008
IDM_LANG_SPANISH              equ       2009
IDM_LANG_RUSSIAN              equ       2010

IDM_HELP                      equ       3000
IDM_APPHELP                   equ       3001
IDM_APPABOUT                  equ       4002


BUILD_BIN_FORMAT              equ       EXE
BUILD_BIN_SUFFIX_STR          textequ   <>
