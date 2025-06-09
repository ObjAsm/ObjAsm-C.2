; ==================================================================================================
; Title:      ADE_Globals.inc
; Author:     G. Friedrich
; Version:    See ADE.asm
; Purpose:    ObjAsm Assembler Development Environment.
; ==================================================================================================


include ADE_Shared.inc

%CStr szAppTitle,   "&APP_TITLE"
%CStr szAboutText,  "&ABOUT_TEXT", 13, 10, \
                    "Version &VER_PRODUCTVERSION_STR", 13, 10, \
                    "Designed with ObjAsm", 13, 10, \
                    "© &COPYRIGHT", 13, 10, 13, 10, \
                    @CatStr(<!">, %BUILD_DATE_STR, \
                            <  -  Build: >, %BUILD_NUMBER, <->, %ASSEMBLER, <->, \
                            %TARGET_MODE_STR, <->, %BUILD_BITNESS, <!">)

CStr szWarning,     "Warning Message"
CStr szWarnNoConf,  "{PA20}", \
                    "[FI55]",\
                      "[B,H+6,C#FF4F4F]Warning{#21}[~]{P}", \
                      "[H+2]No Configuration File found        [~]{P}", \
                      "[C#5F4FFF]", \
                        "[I]Using default values...[~]", \
                      "[~]", \
                    "[~]"
CStr szWarnOldConf, "{PA20}", \
                    "[FI55]",\
                      "[B,H+6,C#FF4F4F]Warning{#21}[~]{P}", \
                      "[H+2]Outdated Configuration File[~]{P}", \
                      "[C#5F4FFF]", \
                        "[I]Using default values where required...[~]", \
                      "[~]", \
                    "[~]"

CStr szWarnNoProj,  "{PA20}", \
                    "[FI55]",\
                      "[B,H+6,C#FF4F4F]Warning{#21}[~]{P}", \
                      "[H+2]No Project File found        [~]{P}", \
                      "[C#5F4FFF]", \
                        "[I]Using default values...[~]", \
                      "[~]", \
                    "[~]"
CStr cWarnOldProj,  "{PA20}", \
                    "[FI55]",\
                      "[B,H+6,C#FF4F4F]Warning{#21}[~]{P}", \
                      "[H+2]Outdated Project File[~]{P}", \
                      "[C#5F4FFF]", \
                        "[I]Using default values where required...[~]", \
                      "[~]", \
                    "[~]"

FONT_MONOSPACED         equ   BIT00
EditorResourcesID       equ   0
EditorSharedResourcesID equ   0

FOLDING_RULE struc
  pStart            PSTRING   ?
  pEnd              PSTRING   ?
  pBetween1         PSTRING   ?
  pBetween2         PSTRING   ?
  dFlags            DWORD     ?
FOLDING_RULE ends
PFOLDING_RULE typedef ptr FOLDING_RULE

CStr szConfigurationFile,     "ADE.ini"
CStr szIdentification,        "Identification"
CStr szVersion,               "Version"
CStr szDescription,           "Description"
CStr szSolution,              "Solution"
CStr szGUI,                   "GUI"
CStr szProject,               "Project"
CStr szGroups,                "Groups"
CStr szFiles,                 "Files"
CStr szName,                  "Name"
CStr szDispName,              "DispName"
CStr szFileName,              "FileName"
CStr szType,                  "Type"
CStr szGroup,                 "Group"
CStr szExpanded,              "Expanded"
CStr szPath,                  "Path"
CStr szEditorCodePrefix,      "Code"
CStr szFont,                  "Font"
CStr szBackground,            "Background"
CStr szHighlight,             "Highlight"
CStr szRegular,               "Regular"
CStr szSelect,                "Select"
CStr szQuote,                 "Quote"
CStr szComment,               "Comment"
CStr szNumber,                "Number"
CStr szOperator,              "Operator"
CStr szLineSpace,             "LineSpace"
CStr szTabWidth,              "TabWidth"
CStr szTab2Spaces,            "Tab2Spaces"
CStr szAlignTabs,             "AlignTabs"
CStr szAlignLines,            "AlignLines"
CStr szRevHorzMouseWheelRot,  "ReverseHorzMouseWheelRotation"
CStr szRevVertMouseWheelRot,  "ReverseVertMouseWheelRotation"
CStr szLineTermination,       "LineTermination"
CStr szLanguage,              "Language"
CStr szFileTypes,             "File Types"
CStr szNewFileTypeDefault,    "NewFileTypeDefault"
CStr szPercieved,             "Percieved"
CStr szPrjMgrColors,          "PrjMgrColors"
CStr szPrjMgrWidth,           "PrjMgrWidth"

CStr szDefaultFontFace,       "Lucida Console"
CStr szMetricChar,            "X"
CStr szON,                    "ON"
CStr szOFF,                   "OFF"
CStr szStrCRLF,               "CRLF"
CStr szStrLF,                 "LF"
CStr szNULL,                  "NULL"
CStr szOverwriteModeLabel,    "OVR"
CStr szInsertModeLabel,       "INS"
CStr szBlockModeLabel,        "BLK"

CStr szAsmExt,                ".asm"
CStr szIncExt,                ".inc"
CStr szResExt,                ".rc"
CStr szTxtExt,                ".txt"
CStr szIniExt,                ".ini"

CStr szDescADEP,              "Assembler Development Environment - Project file"
CStr szLocalPath,             ".\"

;Don't change the order of the next 3 string allocations
CStr szLoadFilter,            "Assembly files (*.asm, *.inc)", 0, "*.asm;*.inc", 0, \
                              "Text files (*.txt)", 0, "*.txt", 0, \
                              "Other files (*.*)", 0, "*.*", 0
.const
MultiFileSpec label COMDLG_FILTERSPEC
  POINTER $OfsTStrW("All")
  POINTER $OfsTStrW("*.*")
  POINTER $OfsTStrW("Assembly")
  POINTER $OfsTStrW("*.asm")
  POINTER $OfsTStrW("Include")
  POINTER $OfsTStrW("*.inc")
  POINTER $OfsTStrW("Resource")
  POINTER $OfsTStrW("*.rc")
  POINTER $OfsTStrW("Text")
  POINTER $OfsTStrW("*.txt")
MultiFileSpecCount = ($ - MultiFileSpec)/sizeof(COMDLG_FILTERSPEC)

MultiProjSpec label COMDLG_FILTERSPEC
  POINTER $OfsTStrW("All")
  POINTER $OfsTStrW("*.*")
  POINTER $OfsTStrW("Project")
  POINTER $OfsTStrW("*.adep")
MultiProjSpecCount = ($ - MultiProjSpec)/sizeof(COMDLG_FILTERSPEC)

szDefaultEditorFontFace     textequ <szDefaultFontFace>
DefaultEditorFontPointSize  equ   13
DefaultEditorBG             equ   $RGB(000,000,000)
DefaultEditorTextRegularFG  equ   $RGB(196,196,192)
DefaultEditorTextRegularBG  equ   DefaultEditorBG
DefaultEditorTextSelectFG   equ   DefaultEditorTextRegularFG
DefaultEditorTextSelectBG   equ   $RGB(000,128,000)
DefaultEditorTextHilightFG  equ   DefaultEditorTextRegularFG
DefaultEditorTextHilightBG  equ   $RGB(064,128,064)
DefaultEditorTextQuoteFG    equ   DefaultEditorTextRegularFG
DefaultEditorTextQuoteBG    equ   $RGB(064,064,128)
DefaultEditorTextCommentFG  equ   DefaultEditorTextRegularFG
DefaultEditorTextCommentBG  equ   $RGB(096,096,096)
DefaultEditorTextNumberFG   equ   DefaultEditorTextRegularFG
DefaultEditorTextNumberBG   equ   DefaultEditorBG
DefaultEditorTextOperatorFG equ   $RGB(000,000,128)
DefaultEditorTextOperatorBG equ   DefaultEditorBG

szDefaultSelBarFontFace     textequ <szDefaultFontFace>
DefaultSelBarFontPointSize  equ   10
DefaultSelBarTextRegFG      equ   $RGB(255,255,255)
DefaultSelBarTextRegBG      equ   $RGB(063,063,063)
DefaultSelBarTextSelFG      equ   $RGB(127,255,127)
DefaultSelBarTextSelBG      equ   $RGB(127,255,127)

szDefaultStatusFontFace     textequ <szDefaultFontFace>
DefaultStatusTextPointSize  equ   8
DefaultStatusPanelTextFG    equ   $RGB(255,255,255)
DefaultStatusPanelTextBG    equ   $RGB(127,127,127)

DefaultProjFG               equ   $RGB(000,000,000)
DefaultProjBG               equ   $RGB(255,255,255)
DefaultProjLN               equ   $RGB(000,000,000)


DefaultLineSpace            equ   2
DefaultTabWidth             equ   2

IDC_SPLITHORZ               equ   101
IDC_SCROLLBARVERT           equ   110
IDC_SCROLLBARHORZ           equ   111

ZOOM_FACTOR_INIT            equ   1024
ZOOM_FACTOR_MIN             equ   ZOOM_FACTOR_INIT/8
ZOOM_FACTOR_MAX             equ   ZOOM_FACTOR_INIT*8

LINEINDICATOR_SPACE_TOP     equ   3
LINEINDICATOR_SPACE_BOTTOM  equ   5
LINEINDICATOR_SPACE_LEFT    equ   3

ICON_INDEX_GROUP_CLOSE      equ   3
ICON_INDEX_GROUP_OPEN       equ   4
ICON_INDEX_FILE             equ   5
ICON_INDEX_CMD              equ   6


.data
dSetupOption1   DWORD   3     ;None

.data?
hCBTProc        HANDLE  ?

