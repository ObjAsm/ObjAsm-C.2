; ==================================================================================================
; Title:      DatabaseApp_Shared.inc
; Author:     G. Friedrich
; Version:    See DatabaseApp.asm
; Purpose:    ObjAsm Database Application.
; ==================================================================================================


;General information
APP_TITLE                     textequ   <Database Explorer>
ABOUT_TEXT                    textequ   <Database Explorer - test version ->
COPYRIGHT                     textequ   <G. Friedrich   August 2019> 
VER_FILEVERSION               equ       1,1,0,0
VER_FILEVERSION_STR           textequ   <1.1>
VER_PRODUCTVERSION            equ       1,1,0,0
VER_PRODUCTVERSION_STR        textequ   <1.1>

;Build information - updated automatically -
BUILD_NUMBER                  equ       34
BUILD_DATE_STR                textequ   <2024-10-23>
BUILD_BITNESS                 equ       64
BUILD_MODE                    equ       RLS

IDM_FILE                      equ       1000
IDM_NEW                       equ       1001
IDM_OPEN                      equ       1002
IDM_CLOSE                     equ       1003
IDM_STRUCDSGN                 equ       1004
IDM_INDEXING                  equ       1005
IDM_PACK                      equ       1006
IDM_ZAP                       equ       1007
IDM_EXIT                      equ       1999

IDM_RECORD                    equ       2000
IDM_NAVIGATION                equ       2001
IDM_REC_PREV                  equ       2002
IDM_REC_NEXT                  equ       2003
IDM_REC_TOP                   equ       2004
IDM_REC_BOTT                  equ       2005
IDM_REC_SEEK                  equ       2010
IDM_REC_EDIT                  equ       2020

IDM_QUERY                     equ       3000
IDM_QRY_START1                equ       3001
IDM_QRY_START2                equ       3002
IDM_QRY_CLEAR                 equ       3003
IDM_QRY_VIEW                  equ       3004
IDM_QRY_STORE                 equ       3005
IDM_QRY_RECALL                equ       3006

IDM_HELP                      equ       4000
IDM_ABOUT                     equ       4001
IDM_CHECK1                    equ       4100
IDM_CHECK2                    equ       4101
IDM_CHECK3                    equ       4102
IDM_CHECK4                    equ       4103
IDM_CHECK5                    equ       4104
IDM_CHECK6                    equ       4105
IDM_CHECK7                    equ       4106
IDM_CHECK8                    equ       4107
IDM_CHECK9                    equ       4108
IDM_LIST_NDX                  equ       4109

;Application
IDC_APP_SBR                   equ       1000

IDD_NEW_TABLE                 equ       1000
IDC_NEWTABLE_EDT_FILE_NAME    equ       1001
IDC_NEWTABLE_STC_FILE_NAME    equ       1000
IDC_NEWTABLE_BTN_OK           equ       IDOK
IDC_NEWTABLE_BTN_CANCEL       equ       IDCANCEL

;Index.dlg
IDD_INDEX                     equ       8000
IDC_INDEX_STC_FIELD_NAME      equ       1000
IDC_INDEX_STC_FILE_NAME       equ       1001
IDC_INDEX_CBO_FIELD_NAME      equ       1002
IDC_INDEX_EDT_FILE_NAME       equ       1003
IDC_INDEX_BTN_SEARCH_FILE     equ       1004
IDC_INDEX_BTN_CLOSE           equ       1005
IDC_INDEX_BTN_INDEX           equ       1006
IDC_INDEX_SBR                 equ       1007

;StructureEditor.dlg
IDD_STRUC_EDITOR              equ       5000
IDC_STRUC_STC_NAME            equ       1000
IDC_STRUC_STC_TYPE            equ       1001
IDC_STRUC_STC_LENGTH          equ       1002
IDC_STRUC_STC_PARAM           equ       1003
IDC_STRUC_STC_INDEX           equ       1004
IDC_STRUC_EDT                 equ       1005
IDC_STRUC_BTN_APPEND          equ       1006
IDC_STRUC_BTN_DELETE          equ       1007
IDC_STRUC_SCB_UP_DOWN         equ       1008
IDC_STRUC_STC_FIELD_POS       equ       1009
IDC_STRUC_BTN_APPLY           equ       1010
IDC_STRUC_BTN_OK              equ       IDOK
IDC_STRUC_BTN_CANCEL          equ       IDCANCEL
IDC_STRUC_SBR                 equ       1012

;RecordEditor.dlg
IDD_RECORD_EDITOR             equ       2000
IDC_RECORD_EDT                equ       1000
IDC_RECORD_BTN_APPEND         equ       1001
IDC_RECORD_BTN_DELETE         equ       1002
IDC_RECORD_BTN_RESTORE        equ       1003
IDC_RECORD_BTN_TOP            equ       1004
IDC_RECORD_BTN_PREV           equ       1005
IDC_RECORD_BTN_NEXT           equ       1006
IDC_RECORD_BTN_BOTTOM         equ       1007
IDC_RECORD_CHK_USE_INDEX      equ       1008
IDC_RECORD_CHK_EDIT           equ       1009
IDC_RECORD_BTN_CLOSE          equ       1010
IDC_RECORD_SBR                equ       1011

;Seek.dlg
IDD_SEEK                      equ       3000
IDC_SEEK_STC_INDEX            equ       1000
IDC_SEEK_CBO_INDEX            equ       1001
IDC_SEEK_STC_SEEK_FOR         equ       1002
IDC_SEEK_EDT_SEEK_FOR         equ       1003
IDC_SEEK_BTN_EDIT             equ       1004
IDC_SEEK_BTN_SEEK             equ       1005
IDC_SEEK_BTN_CLOSE            equ       1006
IDC_SEEK_SBR                  equ       1007

;Query.dlg
IDD_QUERY_VIEW                equ       4000
IDC_QUERY_CLOSE               equ       1000
IDC_QUERY_UPDATE              equ       1001


BUILD_BIN_FORMAT              equ       EXE
BUILD_BIN_SUFFIX_STR          textequ   <>
