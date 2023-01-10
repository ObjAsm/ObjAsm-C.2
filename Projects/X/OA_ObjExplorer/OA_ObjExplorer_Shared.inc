; ==================================================================================================
; Title:      OA_ObjExplorer_Shared.inc
; Author:     G. Friedrich
; Version:    Check OA_ObjExplorer.asm
; Purpose:    ObjAsm Object Explorer.
; ==================================================================================================


;General information
APP_TITLE                     textequ   <Object Explorer>
ABOUT_TEXT                    textequ   <ObjAsm - Object Explorer>
COPYRIGHT                     textequ   <G. Friedrich   October 2021>
VER_FILEVERSION               equ       2,0,1,0
VER_FILEVERSION_STR           textequ   <2.0>
VER_PRODUCTVERSION            equ       2,0,1,0
VER_PRODUCTVERSION_STR        textequ   <2.0.1>

;Build information - updated automatically -
BUILD_NUMBER                  equ       55
BUILD_DATE_STR                textequ   <2023-01-10>
BUILD_BITNESS                 equ       64
BUILD_MODE                    equ       RLS

;Menu IDs
IDM_FILE                      equ       050
IDM_FILE_REFRESH              equ       051
IDM_FILE_SEARCH               equ       052
IDM_FILE_SETUP                equ       053
IDM_FILE_EXIT                 equ       054

IDM_LANGUAGE                  equ       060
IDM_LANGUAGE_ENGLISH          equ       061
IDM_LANGUAGE_GERMAN           equ       062
IDM_LANGUAGE_SPANISH          equ       063

IDM_SELECTALL                 equ       070
IDM_COPY                      equ       071
IDM_PRINTPREVIEW              equ       072
IDM_PRINT                     equ       073

IDM_WINDOW                    equ       080
IDM_WIND_CASCADE              equ       081
IDM_WIND_TILE_HOR             equ       082
IDM_WIND_TILE_VER             equ       083
IDM_WIND_ARRANGE              equ       084
IDM_WIND_NEXT                 equ       085
IDM_WIND_PREV                 equ       086
IDM_WIND_CLOSE                equ       087
IDM_WIND_CLOSEALL             equ       088
IDM_WIND_ZOOMIN               equ       089
IDM_WIND_ZOOMOUT              equ       090

IDM_HELP                      equ       100
IDM_HELP_HELP                 equ       101
IDM_HELP_ABOUT                equ       102

IDM_OPEN_OBJ_PROP_WND         equ       500
IDM_OPEN_INT_PROP_WND         equ       501

IDM_TREE_SHOW_OBJ             equ       600
IDM_TREE_SHOW_INT             equ       601
IDM_TREE_SHOW_PRJ             equ       602
IDM_TREE_SHOW_ERR             equ       603

;Bitmap IDs
IDB_APP                       equ       000
IDB_FILE_REFRESH              equ       001
IDB_FILE_SEARCH               equ       002
IDB_FILE_SETUP                equ       003
IDB_FILE_EXIT                 equ       004
IDB_WIND_CASCADE              equ       005
IDB_WIND_TILE_HORZ            equ       006
IDB_WIND_TILE_VERT            equ       007
IDB_WIND_ARRANGE              equ       008
IDB_WIND_NEXT                 equ       009
IDB_WIND_PREV                 equ       010
IDB_WIND_CLOSE                equ       011
IDB_WIND_CLOSEALL             equ       012
IDB_WIND_ZOOMIN               equ       013
IDB_WIND_ZOOMOUT              equ       014
IDB_HELP_HELP                 equ       015
IDB_HELP_ABOUT                equ       016

;Control IDs
IDC_TEXT_ABOUT                equ       100

IDC_TOOLBARFILE               equ       100
IDC_TOOLBARWINDOW             equ       101
IDC_STATUSBAR                 equ       102

;Language IDs
LANGUAGE_STEP                 equ       200
IDLANG_ENGLISH                equ       000
IDLANG_GERMAN                 equ       200
IDLANG_SPANISH                equ       400

;String IDs
IDS_REFRESH                   equ       80
IDS_SEARCH                    equ       81
IDS_SETUP                     equ       82
IDS_WIND_CASCADE              equ       83
IDS_WIND_TILE_HORZ            equ       84
IDS_WIND_TILE_VERT            equ       85
IDS_WIND_ARRANGE              equ       86
IDS_WIND_NEXT                 equ       87
IDS_WIND_PREV                 equ       88
IDS_WIND_CLOSE                equ       89
IDS_WIND_CLOSE_ALL            equ       90
IDS_WIND_ZOOMIN               equ       91
IDS_WIND_ZOOMOUT              equ       92

IDS_SHOW_OBJ                  equ       95
IDS_SHOW_INT                  equ       96
IDS_SHOW_PRJ                  equ       97
IDS_SHOW_ERR                  equ       98

IDS_SETUP_CAPTION             equ       100
IDS_SETUP_OK                  equ       101
IDS_SETUP_CANCEL              equ       102
IDS_SETUP_VIEWER_GRP          equ       103
IDS_SETUP_VIEWER_APP          equ       104
IDS_SETUP_VIEWER_TEXT         equ       105
IDS_SETUP_PROP_GRP            equ       106
IDS_SETUP_PROP_CHK_MTD        equ       107
IDS_SETUP_PROP_CHK_VAR        equ       108
IDS_SELECT                    equ       109

IDS_FIND_CAPTION              equ       120
IDS_FIND_SEARCH               equ       121
IDS_FIND_OBJ                  equ       122
IDS_FIND_INT                  equ       123
IDS_FIND_HELP                 equ       124

;Res\ObjExplorer_SetupDlg.rc
IDD_SETUP_DLG                 equ       5000
IDC_SETUP_VIEWER_GRP          equ       2001
IDC_SETUP_VIEWER_STC          equ       2002
IDC_SETUP_VIEWER_EDIT         equ       2003
IDC_SETUP_VIEWER_BTN          equ       2004
IDC_SETUP_VIEWER_TEXT         equ       2005
IDC_SETUP_PROP_GRP            equ       2010
IDC_SETUP_PROP_CHK_MTD        equ       2011
IDC_SETUP_PROP_CHK_VAR        equ       2012

;Res\ObjExplorer_FindDlg.rc
IDD_FIND_DLG                  equ       6000
IDC_FIND_EDIT                 equ       1001
IDC_FIND_BTN_SEARCH           equ       1002
IDC_FIND_LISTBOX              equ       1003
IDC_FIND_RBN_OBJ              equ       1004
IDC_FIND_RBN_INT              equ       1005
IDC_FIND_STC_HELP             equ       1006


IDM_CONTEXT                   equ       3000

