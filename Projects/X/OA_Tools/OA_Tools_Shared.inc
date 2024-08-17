; ==================================================================================================
; Title:      OA_Tools_Shared.inc
; Author:     G. Friedrich
; Version:    See OA_Tools.asm
; Purpose:    ObjAsm Tools.
; ==================================================================================================


;Main information
APP_TITLE                     textequ   <ObjAsm Tools>
ABOUT_TEXT                    textequ   <ObjAsm Tools>
COPYRIGHT                     textequ   <G. Friedrich   10.2017>
VER_FILEVERSION               equ       2,0,0,0
VER_FILEVERSION_STR           textequ   <2.0>
VER_PRODUCTVERSION            equ       2,0,0,0
VER_PRODUCTVERSION_STR        textequ   <2.0>

;Build information - updated automatically -
BUILD_NUMBER                  equ       35
BUILD_DATE_STR                textequ   <2024-08-17>
BUILD_BITNESS                 equ       64
BUILD_MODE                    equ       RLS

;Menu IDs - Never start with 0
IDM_APPLICATION               equ       1
IDM_APPL_SETUP                equ       2
IDM_LANGUAGE                  equ       3
IDM_LANG_ENGLISH              equ       4
IDM_LANG_GERMAN               equ       5
IDM_LANG_SPANISH              equ       6
IDM_LANG_CHINESE              equ       7
IDM_APPL_EXIT                 equ       10

IDM_EDIT                      equ       11
IDM_EDIT_CUT                  equ       12
IDM_EDIT_COPY                 equ       13
IDM_EDIT_PASTE                equ       14
IDM_EDIT_DELETE               equ       15
IDM_EDIT_SELECT_ALL           equ       16

IDM_MENU_CHECK                equ       20
IDM_MENU_CHECK_MTD            equ       21
IDM_MENU_CHECK_MTD_REG        equ       22
IDM_MENU_CHECK_MTD_ARG        equ       23
IDM_MENU_CHECK_MTD_LOC        equ       24
IDM_MENU_CHECK_MTD_ALL        equ       25
IDM_MENU_CHECK_PRC            equ       26
IDM_MENU_CHECK_PRC_REG        equ       27
IDM_MENU_CHECK_PRC_ARG        equ       28
IDM_MENU_CHECK_PRC_LOC        equ       29
IDM_MENU_CHECK_PRC_ALL        equ       30
IDM_MENU_CHECK_MAC            equ       31
IDM_MENU_CHECK_MAC_ARG        equ       32
IDM_MENU_CHECK_MAC_LOC        equ       33
IDM_MENU_CHECK_MAC_ALL        equ       34

IDM_CHECK_AGAIN               equ       39

IDM_TOOL                      equ       40
IDM_TOOL_0                    equ       41
IDM_TOOL_1                    equ       42
IDM_TOOL_2                    equ       43
IDM_TOOL_3                    equ       44
IDM_TOOL_4                    equ       45
IDM_TOOL_5                    equ       46
IDM_TOOL_6                    equ       47
IDM_TOOL_7                    equ       48
IDM_TOOL_8                    equ       49
IDM_TOOL_9                    equ       50

IDM_WINDOW                    equ       60
IDM_WINDOW_CASCADE            equ       61
IDM_WINDOW_TILE_HOR           equ       62
IDM_WINDOW_TILE_VER           equ       63
IDM_WINDOW_ARRANGE            equ       64
IDM_WINDOW_SEPARATOR_1        equ       65
IDM_WINDOW_NEXT               equ       66
IDM_WINDOW_PREV               equ       67
IDM_WINDOW_SEPARATOR_2        equ       68
IDM_WINDOW_CLOSE              equ       69
IDM_WINDOW_CLOSE_ALL          equ       70

IDM_HELP                      equ       90
IDM_HELP_SYSINFO              equ       91
IDM_HELP_HELP                 equ       92
IDM_HELP_ABOUT                equ       93

IDM_CONTEXT_SEPARATOR         equ       200
IDM_OPEN_EDITOR               equ       201
IDM_COPY_FILENAME             equ       202

IDM_ZOOM_IN                   equ       300
IDM_ZOOM_OUT                  equ       301

IDM_DROP_CHECK                equ       100
IDM_DROP_CHECK_MTD            equ       101
IDM_DROP_CHECK_MTD_REG        equ       102
IDM_DROP_CHECK_MTD_ARG        equ       103
IDM_DROP_CHECK_MTD_LOC        equ       104
IDM_DROP_CHECK_MTD_ALL        equ       105
IDM_DROP_CHECK_PRC            equ       106
IDM_DROP_CHECK_PRC_REG        equ       107
IDM_DROP_CHECK_PRC_ARG        equ       108
IDM_DROP_CHECK_PRC_LOC        equ       109
IDM_DROP_CHECK_PRC_ALL        equ       110
IDM_DROP_CHECK_MAC            equ       111
IDM_DROP_CHECK_MAC_ARG        equ       112
IDM_DROP_CHECK_MAC_LOC        equ       113
IDM_DROP_CHECK_MAC_ALL        equ       114


;Bitmap IDs
IDB_APPLICATION               equ       0
IDB_CHILD                     equ       1
IDB_APPL_SETUP                equ       2
IDB_APPL_EXIT                 equ       3
IDB_EDIT_CUT                  equ       4
IDB_EDIT_COPY                 equ       5
IDB_EDIT_PASTE                equ       6
IDB_EDIT_DELETE               equ       7
IDB_CHECK                     equ       8
IDB_CHECK_ALL                 equ       9
IDB_WINDOW_CASCADE            equ       10
IDB_WINDOW_TILE_HOR           equ       11
IDB_WINDOW_TILE_VER           equ       12
IDB_WINDOW_ARRANGE            equ       13
IDB_WINDOW_NEXT               equ       14
IDB_WINDOW_PREV               equ       15
IDB_WINDOW_CLOSE              equ       16
IDB_WINDOW_CLOSE_ALL          equ       17
IDB_HELP_HELP                 equ       18
IDB_HELP_ABOUT                equ       19
IDB_OPEN_EDITOR               equ       20
IDB_ZOOM_IN                   equ       21
IDB_ZOOM_OUT                  equ       22


;String IDs
IDS_APPLICATION               equ       0
IDS_APPL_SETUP                equ       1
IDS_LANGUAGE                  equ       2
IDS_LANG_ENGLISH              equ       3
IDS_LANG_GERMAN               equ       4
IDS_LANG_SPANISH              equ       5
IDS_LANG_CHINESE              equ       6
IDS_APPL_EXIT                 equ       10

IDS_EDIT                      equ       11
IDS_EDIT_CUT                  equ       12
IDS_EDIT_COPY                 equ       13
IDS_EDIT_PASTE                equ       14
IDS_EDIT_DELETE               equ       15
IDS_EDIT_SELECT_ALL           equ       16

IDS_MENU_CHECK                equ       17
IDS_MENU_CHECK_MTD            equ       18
IDS_MENU_CHECK_MTD_REG        equ       19
IDS_MENU_CHECK_MTD_ARG        equ       20
IDS_MENU_CHECK_MTD_LOC        equ       21
IDS_MENU_CHECK_MTD_ALL        equ       22
IDS_MENU_CHECK_PRC            equ       23
IDS_MENU_CHECK_PRC_REG        equ       24
IDS_MENU_CHECK_PRC_ARG        equ       25
IDS_MENU_CHECK_PRC_LOC        equ       26
IDS_MENU_CHECK_PRC_ALL        equ       27
IDS_MENU_CHECK_MAC            equ       28
IDS_MENU_CHECK_MAC_ARG        equ       29
IDS_MENU_CHECK_MAC_LOC        equ       30
IDS_MENU_CHECK_MAC_ALL        equ       31

IDS_TOOL                      equ       32
IDS_TOOL_0                    equ       33
IDS_TOOL_1                    equ       34
IDS_TOOL_2                    equ       35
IDS_TOOL_3                    equ       36
IDS_TOOL_4                    equ       37
IDS_TOOL_5                    equ       38
IDS_TOOL_6                    equ       39
IDS_TOOL_7                    equ       40
IDS_TOOL_8                    equ       41
IDS_TOOL_9                    equ       42

IDS_WINDOW                    equ       43
IDS_WINDOW_CASCADE            equ       44
IDS_WINDOW_TILE_HOR           equ       45
IDS_WINDOW_TILE_VER           equ       46
IDS_WINDOW_ARRANGE            equ       47
IDS_WINDOW_NEXT               equ       48
IDS_WINDOW_PREV               equ       49
IDS_WINDOW_CLOSE              equ       50
IDS_WINDOW_CLOSE_ALL          equ       51

IDS_HELP                      equ       52
IDS_HELP_SYSINFO              equ       53
IDS_HELP_HELP                 equ       54
IDS_HELP_ABOUT                equ       55

IDS_OPEN_EDITOR               equ       56
IDS_COPY_FILENAME             equ       57
IDS_CHECK_AGAIN               equ       58

IDS_ZOOM_IN                   equ       59
IDS_ZOOM_OUT                  equ       60

IDS_HINT_CUT                  equ       61
IDS_HINT_COPY                 equ       62
IDS_HINT_PASTE                equ       63
IDS_HINT_DELETE               equ       64
IDS_HINT_SELECT_ALL           equ       65
IDS_HINT_CASCADE              equ       66
IDS_HINT_TILE_HOR             equ       67
IDS_HINT_TILE_VER             equ       68
IDS_HINT_ARRANGE              equ       69
IDS_HINT_NEXT                 equ       70
IDS_HINT_PREV                 equ       71
IDS_HINT_CLOSE                equ       72
IDS_HINT_CLOSE_ALL            equ       73
IDS_HINT_OPEN_EDITOR          equ       74
IDS_HINT_COPY_FILENAME        equ       75
IDS_HINT_CHECK_AGAIN          equ       76
IDS_HINT_ZOOM_IN              equ       77
IDS_HINT_ZOOM_OUT             equ       78

IDS_WORKING                   equ       79
IDS_CHECK_REG_READY           equ       80
IDS_CHECK_LOC_READY           equ       81
IDS_CHECK_ARG_READY           equ       82
IDS_FILE_EMPTY                equ       83
IDS_FILE_OPEN_ERROR           equ       84
IDS_INTERNAL_FAILURE          equ       85

IDS_SELECT_FILE               equ       86
IDS_SELECT_EDITOR             equ       87
IDS_SELECT_TOOL               equ       88

IDS_DLG_EXIT_CAPTION          equ       89
IDS_DLG_EXIT_QUESTION         equ       90
IDS_DLG_EXIT_YES              equ       91
IDS_DLG_EXIT_NO               equ       92

IDS_TAB1_MAIN                 equ       93
IDS_TAB1_APPLICATION          equ       94
IDS_TAB1_EXTERNAL_EDITOR      equ       95
IDS_TAB1_LINE_TERMINATOR      equ       96
IDS_TAB1_WINDOW               equ       97
IDS_TAB1_ZOOM_FACTOR          equ       98
IDS_TAB1_FONTFACE_NAME        equ       99
IDS_TAB1_FONT_SIZE            equ       100
IDS_TAB1_CHECKS               equ       101
IDS_TAB1_CLOSE_NO_FINDINGS    equ       102
IDS_TAB1_USE_ANNOTATIONS      equ       103
IDS_TAB1_MIXED                equ       104

IDS_TAB2_TOOLS                equ       105
IDS_TAB2_TOOL                 equ       106
IDS_TAB2_NAME                 equ       107
IDS_TAB2_COMMAND              equ       108
IDS_TAB2_NOTE                 equ       109

IDS_TAB3_COLORS               equ       110
IDS_TAB3_COLOR_NOTIF          equ       111
IDS_TAB3_COLOR_COMMENT        equ       112
IDS_TAB3_COLOR_FAILIURE       equ       113
IDS_TAB3_COLOR_BKGROUND       equ       114
IDS_TAB3_COLOR_REG_ERROR      equ       115
IDS_TAB3_COLOR_REG_WARNING    equ       116
IDS_TAB3_COLOR_ARG_WARNING    equ       117
IDS_TAB3_COLOR_LOC_WARNING    equ       118
IDS_TAB3_NOTE                 equ       119

IDS_SETUP                     equ       120
IDS_CANCEL                    equ       121

IDS_CODEBLOCK_NAME            equ       122
IDS_REGISTERS                 equ       123
IDS_ARGUMENTS                 equ       124
IDS_LOCALS                    equ       125
IDS_REG_WARNING               equ       126
IDS_ARG_WARNING               equ       127
IDS_LOC_WARNING               equ       128
IDS_REG_ERROR                 equ       129

IDS_SELECTION_FILE_NAME       equ       130
IDS_SELECTION_OPEN            equ       131
IDS_SELECTION_FILTER_NAME_0   equ       132
IDS_SELECTION_FILTER_NAME_1   equ       133
IDS_SELECTION_FILTER_NAME_2   equ       134

IDS_ABOUT_CAPTION             equ       135
IDS_ABOUT_APPLICATION         equ       136
IDS_ABOUT_VERSION             equ       137
IDS_ABOUT_DESCRIPTION         equ       138
IDS_ABOUT_EMAIL               equ       139
IDS_ABOUT_HOMEPAGE            equ       140

IDS_TOOL_FILTER_NAME_0        equ       141
IDS_TOOL_FILTER_NAME_1        equ       142
IDS_TOOL_FILTER_NAME_2        equ       143
IDS_TOOL_FILTER_NAME_3        equ       144

IDS_DROP_CHECK_MTD            equ       145
IDS_DROP_CHECK_MTD_REG        equ       146
IDS_DROP_CHECK_MTD_ARG        equ       147
IDS_DROP_CHECK_MTD_LOC        equ       148
IDS_DROP_CHECK_MTD_ALL        equ       149
IDS_DROP_CHECK_PRC            equ       150
IDS_DROP_CHECK_PRC_REG        equ       151
IDS_DROP_CHECK_PRC_ARG        equ       152
IDS_DROP_CHECK_PRC_LOC        equ       153
IDS_DROP_CHECK_PRC_ALL        equ       154
IDS_DROP_CHECK_MAC            equ       155
IDS_DROP_CHECK_MAC_ARG        equ       156
IDS_DROP_CHECK_MAC_LOC        equ       157
IDS_DROP_CHECK_MAC_ALL        equ       158


;Control IDs
IDC_TOOLBAR_EDIT              equ       100
IDC_TOOLBAR_WINDOW            equ       101
IDC_STATUSBAR                 equ       102


;Language IDs
IDLANG_ENGLISH                equ       0
IDLANG_GERMAN                 equ       1000
IDLANG_SPANISH                equ       2000
IDLANG_CHINESE                equ       3000
LANGUAGE_STEP                 equ       1000


ID_MDI_MORE                   equ       50009
ID_MDI_LIST                   equ       50010


;Dialog IDs
;Res\Tab1.dlg
SETUP_TAB_MAIN                equ       1000
IDC_GRP_APPLICATION           equ       2000
IDC_STC_EXTERNAL_EDITOR       equ       2010
IDC_EDT_EXTERNAL_EDITOR       equ       2020
IDC_BTN_SEARCH_EDITOR         equ       2030
IDC_GRP_LINE_TERMINATOR       equ       2040
IDC_RBN_CRLF                  equ       2050
IDC_RBN_LF                    equ       2060
IDC_RBN_CR                    equ       2070

IDC_GRP_WINDOW                equ       3000
IDC_STC_ZOOM                  equ       3010
IDC_EDT_ZOOM                  equ       3020
IDC_STC_ZOOM_LEGEND           equ       3030
IDC_STC_FONTFACE_NAME         equ       3040
IDC_CBO_FONTFACE_NAME         equ       3050
IDC_STC_FONTFACE_LEGEND       equ       3060
IDC_STC_FONT_SIZE             equ       3070
IDC_EDT_FONT_SIZE             equ       3080
IDC_STC_FONT_SIZE_LEGEND      equ       3090

IDC_GRP_CHECKS                equ       4000
IDC_CHK_CLOSE_NO_FINDING      equ       4010
IDC_CHK_USE_ANNOTATIONS       equ       4020
IDC_GRP_BITNESS               equ       4030
IDC_RBN_32BIT                 equ       4040
IDC_RBN_64BIT                 equ       4050
IDC_RBN_MIXED                 equ       4060

;Res\Tab2.dlg
SETUP_TAB_TOOLS               equ       2000
IDC_STC_TOOL                  equ       2010
IDC_STC_NAME                  equ       2020
IDC_STC_CMD                   equ       2030
IDC_STC_TOOL_0                equ       3000
IDC_EDT_NAME_0                equ       3010
IDC_EDT_CMD_0                 equ       3020
IDC_BTN_SEARCH_0              equ       3030
IDC_STC_TOOL_1                equ       3100
IDC_EDT_NAME_1                equ       3110
IDC_EDT_CMD_1                 equ       3120
IDC_BTN_SEARCH_1              equ       3130
IDC_STC_TOOL_2                equ       3200
IDC_EDT_NAME_2                equ       3210
IDC_EDT_CMD_2                 equ       3220
IDC_BTN_SEARCH_2              equ       3230
IDC_STC_TOOL_3                equ       3300
IDC_EDT_NAME_3                equ       3310
IDC_EDT_CMD_3                 equ       3320
IDC_BTN_SEARCH_3              equ       3330
IDC_STC_TOOL_4                equ       3400
IDC_EDT_NAME_4                equ       3410
IDC_EDT_CMD_4                 equ       3420
IDC_BTN_SEARCH_4              equ       3430
IDC_STC_TOOL_5                equ       3500
IDC_EDT_NAME_5                equ       3510
IDC_EDT_CMD_5                 equ       3520
IDC_BTN_SEARCH_5              equ       3530
IDC_STC_TOOL_6                equ       3600
IDC_EDT_NAME_6                equ       3610
IDC_EDT_CMD_6                 equ       3620
IDC_BTN_SEARCH_6              equ       3630
IDC_STC_TOOL_7                equ       3700
IDC_EDT_NAME_7                equ       3710
IDC_EDT_CMD_7                 equ       3720
IDC_BTN_SEARCH_7              equ       3730
IDC_STC_TOOL_8                equ       3800
IDC_EDT_NAME_8                equ       3810
IDC_EDT_CMD_8                 equ       3820
IDC_BTN_SEARCH_8              equ       3830
IDC_STC_TOOL_9                equ       3900
IDC_EDT_NAME_9                equ       3910
IDC_EDT_CMD_9                 equ       3920
IDC_BTN_SEARCH_9              equ       3930
IDC_STC_NOTE2                 equ       4000

;Res\Tab3.dlg
SETUP_TAB_COLORS              equ       3000
IDC_UDC_NOTIFICATION          equ       1000
IDC_UDC_COMMENT               equ       1001
IDC_UDC_FAILIURE              equ       1002
IDC_UDC_BKGROUND              equ       1003
IDC_UDC_REG_ERROR             equ       1004
IDC_UDC_REG_WARNING           equ       1005
IDC_UDC_ARG_WARNING           equ       1006
IDC_UDC_LOC_WARNING           equ       1007
IDC_STC_NOTE3                 equ       4000

;Res\OAT_About.dlg
IDD_DLG_ABOUT                 equ       9000
IDC_STC_BKGROUND              equ       1010
IDC_STC_IMAGE                 equ       1020
IDC_STC_APPLICATION           equ       1030
IDC_STC_VERSION               equ       1040
IDC_STC_COPYRIGHT             equ       1050
IDC_STC_DESCRIPTION           equ       1060
IDC_UDC_EMAIL                 equ       1070
IDC_UDC_HOMEPAGE              equ       1080

BUILD_BIN_FORMAT              equ       EXE
BUILD_BIN_SUFFIX_STR          textequ   <>
