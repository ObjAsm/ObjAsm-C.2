; ==================================================================================================
; Title:      ADE_Globals.inc
; Author:     G. Friedrich
; Version:    See ADE.asm
; Purpose:    ObjAsm Assembler Development Environment.
; ==================================================================================================


include ADE_Shared.inc

%CStr szAppTitle, "&APP_TITLE"
%CStr szAboutText,"&ABOUT_TEXT", 13, 10, \
                  "Version &VER_PRODUCTVERSION_STR", 13, 10, \
                  "Designed with ObjAsm", 13, 10, \
                  "© &COPYRIGHT", 13, 10, 13, 10, \
                  @CatStr(<!">, %BUILD_DATE_STR, \
                          <  -  Build: >, %BUILD_NUMBER, <->, %ASSEMBLER, <->, \
                          %TARGET_MODE_STR, <->, %BUILD_BITNESS, <!">)

CStr cWarning,    "Warning Message"
CStr cWarnNoConf, "{PA20}", \
                  "[FI55]",\
                    "[B,H+6,C#FF4F4F]Warning{#21}[~]{P}", \
                    "[H+2]No Configuration File found        [~]{P}", \
                    "[C#5F4FFF]", \
                      "[I]Using default values...[~]", \
                    "[~]", \
                  "[~]"
CStr cWarnOldConf,"{PA20}", \
                  "[FI55]",\
                    "[B,H+6,C#FF4F4F]Warning{#21}[~]{P}", \
                    "[H+2]Outdated Configuration File[~]{P}", \
                    "[C#5F4FFF]", \
                      "[I]Using default values where required...[~]", \
                    "[~]", \
                  "[~]"

CStr cWarnNoProj, "{PA20}", \
                  "[FI55]",\
                    "[B,H+6,C#FF4F4F]Warning{#21}[~]{P}", \
                    "[H+2]No Project File found        [~]{P}", \
                    "[C#5F4FFF]", \
                      "[I]Using default values...[~]", \
                    "[~]", \
                  "[~]"
CStr cWarnOldProj,"{PA20}", \
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

CStr cIdentification,             "Identification"
CStr cVersion,                    "Version"
CStr cDescription,                "Description"
CStr cGUI,                        "GUI"
CStr cProject,                    "Project"
CStr cGroups,                     "Groups"
CStr cFiles,                      "Files"
CStr cName,                       "Name"
CStr cPath,                       "Path"
CStr cEditorCodePrefix,           "Code"
CStr cFont,                       "Font"
CStr cBackground,                 "Background"
CStr cHighlight,                  "Highlight"
CStr cRegular,                    "Regular"
CStr cSelect,                     "Select"
CStr cQuote,                      "Quote"
CStr cComment,                    "Comment"
CStr cNumber,                     "Number"
CStr cOperator,                   "Operator"
CStr cLineSpace,                  "LineSpace"
CStr cTabWidth,                   "TabWidth"
CStr cTab2Spaces,                 "Tab2Spaces"
CStr cAlignTabs,                  "AlignTabs"
CStr cAlignLines,                 "AlignLines"
CStr cRevHorzMouseWheelRot,       "ReverseHorzMouseWheelRotation"
CStr cRevVertMouseWheelRot,       "ReverseVertMouseWheelRotation"
CStr cLineTermination,            "LineTermination"
CStr cLanguage,                   "Language"
CStr cPercieved,                  "Percieved"

CStr cDefaultFontFace,            "Lucida Console"
CStr cMetricChar,                 "X"
CStr cON,                         "ON"
CStr cOFF,                        "OFF"
CStr cStrCRLF,                    "CRLF"
CStr cStrLF,                      "LF"
CStr cNULL,                       "NULL"
CStr cOverwriteModeLabel,         "OVR"
CStr cInsertModeLabel,            "INS"
CStr cBlockModeLabel,             "BLK"

CStr cAsmExt,                     ".asm"
CStr cIncExt,                     ".inc"
CStr cResExt,                     ".rc"
CStr cTxtExt,                     ".txt"
CStr cIniExt,                     ".ini"

;Don't change the order of the next 3 string allocations
CStr cLoadFilter,                 "Assembly files (*.asm, *.inc)", 0, "*.asm;*.inc", 0, \
                                  "Text files (*.txt)", 0, "*.txt", 0, \
                                  "Other files (*.*)", 0, "*.*", 0

MultiFileSpec label COMDLG_FILTERSPEC
  POINTER $OfsCStrW("All")
  POINTER $OfsCStrW("*.*")
  POINTER $OfsCStrW("Assembly")
  POINTER $OfsCStrW("*.asm")
  POINTER $OfsCStrW("Include")
  POINTER $OfsCStrW("*.inc")
  POINTER $OfsCStrW("Resource")
  POINTER $OfsCStrW("*.rc")
  POINTER $OfsCStrW("Text")
  POINTER $OfsCStrW("*.txt")
MultiFileSpecCount = ($ - MultiFileSpec)/sizeof(COMDLG_FILTERSPEC)

MultiProjSpec label COMDLG_FILTERSPEC
  POINTER $OfsCStrW("All")
  POINTER $OfsCStrW("*.*")
  POINTER $OfsCStrW("Project")
  POINTER $OfsCStrW("*.adep")
MultiProjSpecCount = ($ - MultiProjSpec)/sizeof(COMDLG_FILTERSPEC)

cDefaultEditorFontFace      textequ <cDefaultFontFace>
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

cDefaultSelBarFontFace      textequ <cDefaultFontFace>
DefaultSelBarFontPointSize  equ   10
DefaultSelBarTextRegFG      equ   $RGB(255,255,255)
DefaultSelBarTextRegBG      equ   $RGB(063,063,063)
DefaultSelBarTextSelFG      equ   $RGB(127,255,127)
DefaultSelBarTextSelBG      equ   $RGB(127,255,127)

cDefaultStatusFontFace      textequ <cDefaultFontFace>
DefaultStatusTextPointSize  equ   8
DefaultStatusPanelTextFG    equ   $RGB(255,255,255)
DefaultStatusPanelTextBG    equ   $RGB(127,127,127)

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

.data
dSetupOption1   DWORD   3     ;None

.data?
hCBTProc        HANDLE  ?

