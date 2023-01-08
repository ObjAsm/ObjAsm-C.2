; ==================================================================================================
; Title:      Demo03_Shared.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm demonstration program 3.
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


;General information
APP_TITLE                     textequ   <Demo03>
ABOUT_TEXT                    textequ   <Demo03 - WinControls>
COPYRIGHT                     textequ   <G. Friedrich   October 2017> 
VER_FILEVERSION               equ       2,0,0,0
VER_FILEVERSION_STR           textequ   <2.0>
VER_PRODUCTVERSION            equ       2,0,0,0
VER_PRODUCTVERSION_STR        equ       <2.0>

;Build information - updated automatically -
BUILD_NUMBER                  equ       95
BUILD_DATE_STR                textequ   <2023-01-08>
BUILD_BITNESS                 equ       64
BUILD_MODE                    equ       RLS

;Menu IDs
IDM_FILE_NEW                  equ       50
IDM_FILE_OPEN                 equ       51
IDM_FILE_SAVE                 equ       52
IDM_FILE_SAVEAS               equ       53

IDM_EDIT_CUT                  equ       54
IDM_EDIT_COPY                 equ       55
IDM_EDIT_PASTE                equ       56

IDM_HELLO                     equ       1000
IDM_EXIT                      equ       1001
IDM_ABOUT                     equ       1999

;Bitmap IDs
IDB_FILE_NEW                  equ       00
IDB_FILE_OPEN                 equ       01
IDB_FILE_SAVE                 equ       02
IDB_FILE_SAVEAS               equ       03
IDB_FILE_RCV                  equ       07
IDB_FILE_SND                  equ       08

IDB_EDIT_CUT                  equ       04
IDB_EDIT_COPY                 equ       05
IDB_EDIT_PASTE                equ       06

;Control IDs
IDC_TOOLBARFILE               equ       100
IDC_TOOLBAREDIT               equ       101
IDC_STATUSBAR                 equ       102

IDC_STATIC1                   equ       100
IDC_STATIC2                   equ       101
IDC_STATIC3                   equ       102
IDC_RADIO1                    equ       200
IDC_RADIO2                    equ       201
IDC_RADIO3                    equ       202
IDC_CHECK1                    equ       300

