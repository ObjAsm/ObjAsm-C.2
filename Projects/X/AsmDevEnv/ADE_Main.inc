; ==================================================================================================
; Title:      ADE_Main.inc
; Author:     G. Friedrich
; Version:    See ADE.asm
; Purpose:    ObjAsm Assembler Development Environment.
; ==================================================================================================


CLSSTYLE  equ   CS_BYTEALIGNWINDOW or CS_BYTEALIGNCLIENT or CS_VREDRAW or CS_HREDRAW

TBSTYLE   equ   WS_CHILD or WS_VISIBLE or WS_CLIPCHILDREN or TBSTYLE_TOOLTIPS or \
                CCS_NORESIZE or CCS_NODIVIDER or CCS_ADJUSTABLE or TBSTYLE_FLAT or TBSTYLE_LIST

SBSTYLE   equ   WS_CHILD or WS_VISIBLE or SBARS_TOOLTIPS or SBARS_SIZEGRIP

STSTYLE   equ   WS_CHILD or WS_VISIBLE or WS_TABSTOP or TCS_TABS or TCS_FOCUSNEVER; or TCS_HOTTRACK

.const
ToolbarFile DEF_TOOLBAR {IDC_TOOLBARFILE, TBSTYLE, TBSTYLE_EX_MIXEDBUTTONS, \
                         $OfsTStr("File operations"), {<0,0,0,0>}, 11}
  TBBUTTON {IDB_FILE_NEW,         IDM_FILE_NEW,         TBSTATE_ENABLED, TBSTYLE_BUTTON}
  TBBUTTON {IDB_FILE_OPEN,        IDM_FILE_OPEN,        TBSTATE_ENABLED, TBSTYLE_BUTTON}
  TBBUTTON {IDB_FILE_SAVE,        IDM_FILE_SAVE,        TBSTATE_ENABLED, TBSTYLE_BUTTON}
  TBBUTTON {IDB_FILE_SAVEAS,      IDM_FILE_SAVEAS,      TBSTATE_ENABLED, TBSTYLE_BUTTON}
  TBBUTTON {IDB_FILE_SAVEALL,     IDM_FILE_SAVEALL,     TBSTATE_ENABLED, TBSTYLE_BUTTON}
  TBBUTTON {IDB_FILE_CLOSE,       IDM_FILE_CLOSE,       TBSTATE_ENABLED, TBSTYLE_BUTTON}
  TBBUTTON {IDB_FILE_CLOSEALL,    IDM_FILE_CLOSEALL,    TBSTATE_ENABLED, TBSTYLE_BUTTON}
  TBBUTTON {0,                    -1,                   TBSTATE_ENABLED, TBSTYLE_SEP}
  TBBUTTON {IDB_FILE_PRINT,       IDM_FILE_PRINT,       TBSTATE_ENABLED, TBSTYLE_BUTTON}
  TBBUTTON {0,                    -2,                   TBSTATE_ENABLED, TBSTYLE_SEP}
  TBBUTTON {IDB_FILE_PIN,         IDM_FILE_PIN,         TBSTATE_ENABLED, TBSTYLE_BUTTON or \
                                                                         TBSTYLE_CHECK}

ToolbarEdit DEF_TOOLBAR {IDC_TOOLBAREDIT, TBSTYLE, TBSTYLE_EX_MIXEDBUTTONS, \
                         $OfsTStr("Edit operations"), {<0,0,0,0>}, 6}
  TBBUTTON {IDB_EDIT_CUT,         IDM_EDIT_CUT,         TBSTATE_ENABLED, TBSTYLE_BUTTON}
  TBBUTTON {IDB_EDIT_COPY,        IDM_EDIT_COPY,        TBSTATE_ENABLED, TBSTYLE_BUTTON}
  TBBUTTON {IDB_EDIT_PASTE,       IDM_EDIT_PASTE,       TBSTATE_ENABLED, TBSTYLE_BUTTON}
  TBBUTTON {IDB_EDIT_DELETE,      IDM_EDIT_DELETE,      TBSTATE_ENABLED, TBSTYLE_BUTTON}
  TBBUTTON {0,                    -3,                   TBSTATE_ENABLED, TBSTYLE_SEP}
  TBBUTTON {IDB_EDIT_FIND,        IDM_EDIT_FIND,        TBSTATE_ENABLED, TBSTYLE_BUTTON}

ToolbarWindow DEF_TOOLBAR {IDC_TOOLBARWINDOW, TBSTYLE, TBSTYLE_EX_MIXEDBUTTONS, \
                           $OfsTStr("Window operations"), {<0,0,0,0>}, 7}
  TBBUTTON {IDB_WINDOW_CASCADE,   IDM_WINDOW_CASCADE,   TBSTATE_ENABLED, TBSTYLE_BUTTON}
  TBBUTTON {IDB_WINDOW_TILE_HOR,  IDM_WINDOW_TILE_HOR,  TBSTATE_ENABLED, TBSTYLE_BUTTON}
  TBBUTTON {IDB_WINDOW_TILE_VER,  IDM_WINDOW_TILE_VER,  TBSTATE_ENABLED, TBSTYLE_BUTTON}
  TBBUTTON {IDB_WINDOW_ARRANGE,   IDM_WINDOW_ARRANGE,   TBSTATE_ENABLED, TBSTYLE_BUTTON}
  TBBUTTON {0,                    -4,                   TBSTATE_ENABLED, TBSTYLE_SEP}
  TBBUTTON {IDB_WINDOW_ZOOMIN,    IDM_WINDOW_ZOOMIN,    TBSTATE_ENABLED, TBSTYLE_BUTTON}
  TBBUTTON {IDB_WINDOW_ZOOMOUT,   IDM_WINDOW_ZOOMOUT,   TBSTATE_ENABLED, TBSTYLE_BUTTON}

AppStatusbar DEF_STATUSBAR {IDC_STATUSBAR, SBSTYLE, 0, 4}
  DEF_STATUSBAR_PART {220, 100, 3, SBT_NOBORDERS, NULL}
  DEF_STATUSBAR_PART {120,  20, 1, SBT_SUNKEN,    NULL}
  DEF_STATUSBAR_PART {120,  -2, 0, SBT_SUNKEN,    NULL} ;Spring
  DEF_STATUSBAR_PART {120, 100, 2, SBT_SUNKEN,    NULL}

SetupTabCtrl DEF_TABCONTROL {100, STSTYLE, 0, NULL, {<2,2,295,180>}}

CStr szApplicationClassName,    "OAC_Application"
CStr szEditorClassName,         "OAC_Editor"
CStr szEditorDisplayClassName,  "OAC_EditorDisplay"
CStr szEditorViewClassName,     "OAC_EditorView"

; 覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧

FONT_DEF struct
  dInitPointSize    DWORD     ?
  dCurrPointSize    DWORD     ?
  LogFont           LOGFONT   {}
FONT_DEF ends
PFONT_DEF typedef ptr FONT_DEF

COLORSET struct
  Color             COLORREF  ?
  hBrush            HBRUSH    ?
COLORSET ends

FGBG_ATTR struc
  ForeColor         COLORREF  ?
  Background        COLORSET  {}
FGBG_ATTR ends
PFGBG_ATTR typedef ptr FGBG_ATTR

DRAW_ATTR struc
                    FGBG_ATTR {}
                    FONT_DEF  {}
  dFlags            DWORD     0
  FontMetric        POINT     {}            ;Metric of the 'X' character
  hFont             HFONT     ?
DRAW_ATTR ends
PDRAW_ATTR typedef ptr DRAW_ATTR

RANGE struct
  dBegIndex         DWORD     ?
  dEndIndex         DWORD     ?
RANGE ends
PRANGE typedef ptr RANGE

;; 覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧
;; Object:    ScrollBarV
;; Purpose:   Customized drawing of the vertical ScrollBar.
;
;Object ScrollBarVert, ADE_ScrollBarVertID, ScrollBar
;  VirtualEvent      OnPaint,            WM_PAINT
;  VirtualEvent      OnSetScrollInfo,    SBM_SETSCROLLINFO
;ObjectEnd

; 覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧

KEYWORDGROUP struc
                    DRAW_ATTR {}
  pKeyWords         POINTER   ?             ;List of Keywords
  dDescLength       DWORD     ?             ;Description length
  pDescription      PSTRING   ?
KEYWORDGROUP ends
PKEYWORDGROUP typedef ptr KEYWORDGROUP

KWF_CASE_SENSITIVE  equ   BIT00             ;Only if the case match
KWF_CASE_CONVERT    equ   BIT01             ;Convert word to the Keyword case

KEYWORD struc
  pGroup            PKEYWORDGROUP ?
  dFlags            DWORD     ?             ;KWF_XXX
  dLength           DWORD     ?
  pString           PSTRING   ?
KEYWORD ends
PKEYWORD typedef ptr KEYWORD

; 覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧
; Object:     KeywordGroupCollection
; Purpose:    Implement a collection of keyword groups.

Object KeywordGroupCollection, ADE_KeywordGroupListID, DataCollection
  RedefineMethod    DestroyItem,    POINTER
;  RedefineMethod    Insert,             PKEYWORDGROUP, DWORD, DWORD, PSTRING
ObjectEnd

; 覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧
; Object:     KeywordCollection
; Purpose:    Implement a collection of UNICODE keywords and their properties.
;             KeywordCollections are a series of keywords preceeded by a flags (KEYWORD_FLAG) DWORD.
;             Each keyword may have a prefix character in the input list with the following meaning:
;               ^  Keyword is case sensitive.
;               ~  Word must be converted to the keyword case.

Object KeywordCollection, ADE_KeywordListID, SortedDataCollection
  RedefineMethod    Compare,            PKEYWORD, PKEYWORD
  RedefineMethod    Insert,             PKEYWORDGROUP, DWORD, DWORD, PSTRING
ObjectEnd

; 覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧
; Object:     EditorSharedResources
; Purpose:    Editor shared resource manager

Object EditorSharedResources, ADE_EditorSharedResourcesID, Primer
  RedefineMethod    Done
  RedefineMethod    Init,                 POINTER

  ;Cursors:
  DefineVariable    hCursorArrow,         HCURSOR,    0
  DefineVariable    hCursorIBeam,         HCURSOR,    0
  DefineVariable    hCursorSelect,        HCURSOR,    0
  DefineVariable    hCursorHand,          HCURSOR,    0

  ;Bitmaps:
  DefineVariable    hBmpStatusIndRed,     HBITMAP,    0
  DefineVariable    hBmpStatusIndYellow,  HBITMAP,    0
  DefineVariable    hBmpStatusIndGreen,   HBITMAP,    0

  ;Brushes
  DefineVariable    hBrushLineIndRed,     HBRUSH,     0
  DefineVariable    hBrushLineIndYellow,  HBRUSH,     0
  DefineVariable    hBrushLineIndGreen,   HBRUSH,     0
ObjectEnd

; 覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧
; Object:     EditorResources
; Purpose:    Editor resource manager

Object EditorResources, ADE_EditorResourcesID, Primer
  RedefineMethod    Done
  RedefineMethod    Init,                 POINTER, PSTRING, PSTRING, HDC, $ObjPtr(EditorSharedResources)
  StaticMethod      Zoom,                 DWORD

  DefineVariable    dReqMainVersion,      DWORD,      1
  DefineVariable    dMinSubVersion,       DWORD,      0
  DefineVariable    dFlags,               DWORD,      0

  ;Colors:
  DefineVariable    EditorBG,             COLORSET,   {DefaultEditorBG}

  ;Code Text Draw attributes:
  DefineVariable    EditorTextRegular,    DRAW_ATTR,  {{DefaultEditorTextRegularFG,  {DefaultEditorTextRegularBG}}}
  DefineVariable    EditorTextSelect,     DRAW_ATTR,  {{DefaultEditorTextSelectFG,   {DefaultEditorTextSelectBG}}}
  DefineVariable    EditorTextHighlight,  DRAW_ATTR,  {{DefaultEditorTextHilightFG,  {DefaultEditorTextHilightBG}}}
  DefineVariable    EditorTextQuote,      DRAW_ATTR,  {{DefaultEditorTextQuoteFG,    {DefaultEditorTextQuoteBG}}}
  DefineVariable    EditorTextComment,    DRAW_ATTR,  {{DefaultEditorTextCommentFG,  {DefaultEditorTextCommentBG}}}
  DefineVariable    EditorTextNumber,     DRAW_ATTR,  {{DefaultEditorTextNumberFG,   {DefaultEditorTextNumberBG}}}
  DefineVariable    EditorTextOperator,   DRAW_ATTR,  {{DefaultEditorTextOperatorFG, {DefaultEditorTextOperatorBG}}}

  ;Control Draw attributes:
  DefineVariable    SelBarTextRegular,    DRAW_ATTR,  {{DefaultSelBarTextRegFG,      {DefaultSelBarTextRegBG}}}
  DefineVariable    SelBarTextSelect,     DRAW_ATTR,  {{DefaultSelBarTextSelFG,      {DefaultSelBarTextSelBG}}}
  DefineVariable    StatusPanelText,      DRAW_ATTR,  {{DefaultStatusPanelTextFG,    {DefaultStatusPanelTextBG}}}

  ;Metrics:
  DefineVariable    dCodeLineSpace,       DWORD,      DefaultLineSpace  ;Vertical separation between lines
  DefineVariable    dTextLineHeight,      DWORD,      12                 ;CodeFontMetric.Y + Linespacing
  DefineVariable    dTabWidth,            DWORD,      DefaultTabWidth   ;TAB in spaces
  DefineVariable    dLineFoldingWidth,    DWORD,      35                ;Width reserved for line folding management
  DefineVariable    dLineIndicatorWidth,  DWORD,      3                 ;Width reserved for line indication
  DefineVariable    dSelBarWidthMin,      DWORD,      60
  DefineVariable    ScrollBarMetric,      POINT,      {17,17}
  DefineVariable    CaretBmpOffset,       POINT,      {0,0} ;Offset to the logical caret, set by CaretNew
  DefineVariable    dZoomFactor,          DWORD,      ZOOM_FACTOR_INIT
  DefineVariable    dInitZoomFactor,      DWORD,      ZOOM_FACTOR_INIT  ;Temp storage

  Embed     KeywordGroups,      KeywordGroupCollection
  Embed     Keywords,           KeywordCollection

  Embed     FoldingRules,       DataCollection              ;Collection of FOLDINGRULE structures
  Embed     AutocompleteRules,  DataCollection              ;Collection of AUTOCOMPLETERULE structures

  ;Shared resources: these resources are managed by EditorSharedResources
  ;Cursors:
  DefineVariable    hCursorArrow,         HCURSOR,    0
  DefineVariable    hCursorIBeam,         HCURSOR,    0
  DefineVariable    hCursorSelect,        HCURSOR,    0
  DefineVariable    hCursorHand,          HCURSOR,    0

  ;Bitmaps:
  DefineVariable    hBmpStatusIndRed,     HBITMAP,    0
  DefineVariable    hBmpStatusIndYellow,  HBITMAP,    0
  DefineVariable    hBmpStatusIndGreen,   HBITMAP,    0

  ;Brushes
  DefineVariable    hBrushLineIndRed,     HBRUSH,     0
  DefineVariable    hBrushLineIndYellow,  HBRUSH,     0
  DefineVariable    hBrushLineIndGreen,   HBRUSH,     0
ObjectEnd

; 覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧
; Object:     EditorTextLine
; Purpose:    Implement a text line for the Editor.

Object EditorTextLine, ADE_EditorTextLineID, Primer
  StaticMethod      CharDelete,           DWORD, DWORD
  StaticMethod      CharInsert,           DWORD, DWORD, POINTER
  StaticMethod      CharReplace,          DWORD, DWORD, POINTER
  StaticMethod      BufferResize,         DWORD
  RedefineMethod    Done
  StaticMethod      Draw,                 POINTER, PRECT, DWORD
  RedefineMethod    Init,                 POINTER
  StaticMethod      LineBreak,            DWORD, DWORD
  StaticMethod      LineDelete,           DWORD
  StaticMethod      LineJoinNext,         DWORD
  StaticMethod      LineJoinPrev,         DWORD
  StaticMethod      SelectionReset
  StaticMethod      SetDirty

  DefineVariable    Link,                 LDLL_MEMBER,{NULL, NULL}
  DefineVariable    pBuffer,              POINTER,    NULL      ;Memory holding wide chars and an ending ZTC
  DefineVariable    dCharCapacity,        DWORD,      0         ;In characters not including the ZTC
  DefineVariable    dLength,              DWORD,      0         ;In characters not including the ZTC
  ;Selection: [0..dLength] 0 means the first char and if dLength, the it includes the ZTC
  DefineVariable    Selection,            RANGE,      {0,0}     ;In characters
  DefineVariable    dBookmark,            DWORD,      0
  DefineVariable    dFlags,               DWORD,      0         ;TLF_xxx
ObjectEnd

; 覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧

LOCATION struct
  pTextLine         $ObjPtr(EditorTextLine)   ?
  dLineNumber       DWORD     ?
  dCharIndex        DWORD     ?
LOCATION ends
PLOCATION typedef ptr LOCATION

SELRANGE struct                         ;Topological order
  pBegSelInfo       PLOCATION ?
  pEndSelInfo       PLOCATION ?
SELRANGE ends
PSELRANGE typedef ptr SELRANGE

; 覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧
; Object:  EditorView
; Purpose: Implement a view of the Editor.
;
; EditorView Layout:
; 覧覧覧覧覧覧覧覧�
;
;      |<--------->| dSelBarWidth
;      |       |<> | dLineFoldingWidth
;      |       | <>| dLineIndicatorWidth
;       覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧�
;      | 1)xxx | ｦ | EditorTextLine N |            |
;      | xxxxx | ｦ |覧覧覧覧覧覧覧覧覧覧覧覧       |
;      | xxxxx |[-]| EditorTextLine N+1     |      |
;      | xxxxx | ｦ |覧覧覧覧覧覧覧覧覧覧覧覧覧�    |  xxxxxxx = line numbers
;      | xxxxx | ｦ | EditorTextLine N+2        |   |  1) Selection bar
;      | xxxxx | ｦ |覧覧覧覧覧覧覧覧覧覧覧覧覧�    |
;      | xxxxx | ｦ-| EditorTextLine N+3    |       |
;      | xxxxx | ｦ |覧覧覧覧覧覧覧覧覧覧覧�        |
;      | xxxxx | ｦ |        ...                    |
;       覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧�
;      |           |                       |   |   |
;      |SelBarWidth|<----- Line width ---->|   |   |
;      |<--------->|<------ Branch width ----->|   |
;      |<--------------- EditorView width -------->|


Object EditorView, ADE_EditorViewID, Window
  StaticMethod      CaretAdjustHorz,      POINTER
  StaticMethod      CaretDestroy
  StaticMethod      CaretHide
  StaticMethod      CaretMoveWordBeg
  StaticMethod      CaretMoveWordEnd
  StaticMethod      CaretNew
  StaticMethod      CaretRefLocSave,      PLOCATION
  StaticMethod      CaretRefLocLoad,      PLOCATION
  StaticMethod      CaretSet
  StaticMethod      CaretShow
  StaticMethod      ClpBrdDelete
  StaticMethod      ClpBrdCopy
  StaticMethod      ClpBrdCut
  StaticMethod      ClpBrdPaste
  StaticMethod      ClientPos2Index,      PPOINT, PPOINT
  StaticMethod      DrawSelectionBar
  RedefineMethod    Done
  StaticMethod      GetCodeData,          DWORD
  StaticMethod      GetLineNumber,        $ObjPtr(EditorTextLine)
  RedefineMethod    Init,                 POINTER, PRECT, $ObjPtr(EditorResources)
  StaticMethod      MoveCaretDown,        DWORD
  StaticMethod      MoveCaretUp,          DWORD
  RedefineMethod    OnSize,               WPARAM, LPARAM
  StaticMethod      ScrollCaretInViewLeft
  StaticMethod      ScrollCaretInViewRight
  StaticMethod      ScrollLineLeft
  StaticMethod      ScrollLineRight
  StaticMethod      ScrollPageLeft,       DWORD
  StaticMethod      ScrollPageRight,      DWORD
  StaticMethod      ScrollVisLineDown
  StaticMethod      ScrollVisLineUp
  StaticMethod      ScrollVisPageDown,    DWORD
  StaticMethod      ScrollVisPageUp,      DWORD
  StaticMethod      SelectBeginAtCaretLocation
  StaticMethod      SelectUpToCaretLocation
  StaticMethod      SetGuiLayout
  StaticMethod      Startup
  StaticMethod      UpdateStatusPanel
  StaticMethod      VertIndex2TextLine,   DWORD
  StaticMethod      VertIndex2LineNumber, DWORD
  RedefineMethod    WndProc,              DWORD, WPARAM, LPARAM

  ;Events
  StaticEvent       OnChar,               WM_CHAR
  StaticEvent       OnCreate,             WM_CREATE
  StaticEvent       OnGesture,            WM_GESTURE
  StaticEvent       OnKeyDown,            WM_KEYDOWN
  StaticEvent       OnKillFocus,          WM_KILLFOCUS
  StaticEvent       OnLButtonDblClk,      WM_LBUTTONDBLCLK 
  StaticEvent       OnLButtonDown,        WM_LBUTTONDOWN
  StaticEvent       OnLButtonUp,          WM_LBUTTONUP
  StaticEvent       OnMouseMove,          WM_MOUSEMOVE
  StaticEvent       OnMouseWheel,         WM_MOUSEWHEEL
  StaticEvent       OnMouseHWheel,        WM_MOUSEHWHEEL
  StaticEvent       OnPaint,              WM_PAINT
  StaticEvent       OnRButtonDown,        WM_RBUTTONDOWN
  StaticEvent       OnSetCursor,          WM_SETCURSOR
  StaticEvent       OnSetFocus,           WM_SETFOCUS

  ;Management
  DefineVariable    dFlags,               DWORD,      0
  DefineVariable    p1stVisLine,          $ObjPtr(EditorTextLine),  NULL  ;-> 1st visible EditorTextLine
  DefineVariable    d1StVisLineCount,     DWORD,      0       ;Count of visible lines up to p1stVisLine
  DefineVariable    d1stVisLineNum,       DWORD,      0       ;Line number of the first visible line
  DefineVariable    d1stVisCharIndex,     DWORD,      0       ;Index into a EditorTextLine chr buffer
  DefineVariable    CaretLocation,        LOCATION,   {NULL, 0, 0}  ;-> TextLine, Char Index
  DefineVariable    sdCaretVisLineOffset, SDWORD,     0       ;Line Count Offset from p1stVisLine; (-) = before
  DefineVariable    sdLineNumberOffset,   SDWORD,     0
  DefineVariable    dLockedVertIndex,     DWORD,      -1      ;Persistant char index when moving the Caret vertically
  DefineVariable    pResources,           $ObjPtr(EditorResources), NULL

  ;Backbuffering => flickerfree display
  DefineVariable    hTextDC,              HDC,        0       ;Memory DC for back buffer drawing
  DefineVariable    hTextBmp,             HBITMAP,    0       ;Back buffer bitmap
  DefineVariable    hPrvTextBmp,          HBITMAP,    0       ;Original MemDC bitmap

  ;Metrics
  DefineVariable    dSelBarWidth,         DWORD,      0

  ;UI elements
  DefineVariable    SelBarRect,           RECT,       {0,0,0,0} ;Selectionbar
  DefineVariable    TextRect,             RECT,       {0,0,0,0} ;RECT containing all visible TextLines
  DefineVariable    dCharMaxFullVis,      DWORD,      0       ;Number of horiz. fully shown characters 
  DefineVariable    dCharMaxPartVis,      DWORD,      0       ;Number of horiz. partially shown characters
  DefineVariable    dLineMaxFullVis,      DWORD,      0       ;Number of vert. fully shown lines
  DefineVariable    dLineMaxPartVis,      DWORD,      0       ;Number of vert. partially shown lines

  ;Touch support
  DefineVariable    dGestureZoomFirst,    DWORD,      0
  DefineVariable    dGestureZoomLast,     DWORD,      0
  DefineVariable    GesturePanPos,        POINT,      {}
ObjectEnd

; 覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧
; Object:  EditorDisplay
; Purpose: Implement a Display of the Editor.
;
; EditorDisplay Layout:
; 覧覧覧覧覧覧覧覧覧覧
;
;       覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧�
;      |                                        |V |
;      |                                        |e |
;      |   EditorView                           |r |
;      |                                        |t |
;      |                                        |. |
;      |                                        |  |
;      |                                        |S |
;      |                                        |B |
;      |                                        |a |
;      |                                        |r |
;      |覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧慾
;      |StatusPanel| Horizontal Scrollbar       |**| Splitter
;       覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧�
;      |                                           |
;      |<----------- EditorDisplay width---------->|


Object EditorDisplay, ADE_EditorDisplayID, Window
  RedefineMethod    Done
  StaticMethod      InformDeletionOf,     DWORD
  StaticMethod      InformInsertionOf,    DWORD
  RedefineMethod    Init,                 POINTER, PRECT, $ObjPtr(EditorResources)
  StaticMethod      DrawStatusPanel
  RedefineMethod    OnSize,               WPARAM, LPARAM
  StaticMethod      SetGuiLayout
  StaticMethod      SetupScrollBarHorz
  StaticMethod      SetupScrollBarVert
  StaticMethod      Startup

  VirtualEvent      OnCreate,             WM_CREATE
  VirtualEvent      OnScrollHorz,         WM_HSCROLL
  VirtualEvent      OnPaint,              WM_PAINT
  VirtualEvent      OnSetFocus,           WM_SETFOCUS
  VirtualEvent      OnScrollVert,         WM_VSCROLL

  DefineVariable    pResources,           $ObjPtr(EditorResources), NULL

  ;UI elements
  Embed             View,                 EditorView
  Embed             ScrollBarVert,        ScrollBar
  Embed             ScrollBarHorz,        ScrollBar

  DefineVariable    PosIndDirty,          POINT,      {04,3}
  DefineVariable    PosInd2,              POINT,      {24,3}
  DefineVariable    PosInd3,              POINT,      {44,3}
  DefineVariable    StatusPanelRect,      RECT,       {0,0,0,0}
  DefineVariable    SplitterRect,         RECT,       {0,0,0,0}
  DefineVariable    ScrollPage,           POINT,      {10,10} ;CharPage and LinePage to scroll

  ;Backbuffering => flickerfree display
  DefineVariable    hPanelDC,             HDC,        0       ;Memory DC for back buffer drawing
  DefineVariable    hPanelBmp,            HBITMAP,    0       ;Back buffer bitmap
  DefineVariable    hPrvPanelBmp,         HBITMAP,    0       ;Original MemDC bitmap

ObjectEnd

; 覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧

Object ChildWnd, ADE_ChildWndID, MdiChildWnd                  ;MDI child window.
  VirtualAbstract   ClpBrdDelete
  VirtualAbstract   ClpBrdCopy
  VirtualAbstract   ClpBrdCut
  VirtualAbstract   ClpBrdPaste
  VirtualAbstract   ClpBrdSetBtns
  RedefineMethod    Done
  RedefineMethod    Init,                 POINTER             ;-> Owner
  VirtualAbstract   Print
  VirtualAbstract   Save
  VirtualAbstract   UpdateStatusbar

  VirtualEvent      OnMdiActivate,        WM_MDIACTIVATE

  DefineVariable    pFullFileName,        PSTRING,    NULL

  Embed   Snapper,  Magnetism
ObjectEnd

; 覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧

; Editor Layout:
; 覧覧覧覧覧覧�
;                                             (NULL)
;                                               ^
;                                               |
;                            EditorTextLine(0).Link <----
;                                               ^|       |
;                                               |V       |
;                                                        |
;                                               ...      |
;                                                        |
;                                               ^|       |
;                                               |V       |   Editor.TextLines
;  Editor.p1stVisLine ---->  EditorTextLine(M).Link       ---- FirstMember
;                                               ^|        ---- LastMember
;                                               |V       |
;                                                        |
;                                               ...      |
;                                                        |
;                                               ^|       |
;                                               |V       |
;                            EditorTextLine(N).Link <----
;                                                |
;                                                V
;                                              (NULL)


;Caret Blink timeout: SPI_SETCARETTIMEOUT

Object Editor, ADE_EditorID, ChildWnd
  RedefineMethod    ClpBrdDelete
  RedefineMethod    ClpBrdCopy
  RedefineMethod    ClpBrdCut
  RedefineMethod    ClpBrdPaste
  RedefineMethod    ClpBrdSetBtns
  RedefineMethod    Done
  VirtualMethod     FindFrom,             PSTRING, POINTER, POINTER
  VirtualMethod     InformDeletionOf,     DWORD
  VirtualMethod     InformInsertionOf,    DWORD
  RedefineMethod    Init,                 POINTER, $ObjPtr(EditorResources), PSTRING      ;-> Owner, -> FileName
  VirtualMethod     LineNew,              DWORD
  RedefineMethod    Load,                 $ObjPtr(Stream), PDESER_INFO
  VirtualMethod     Open,                 PSTRING
  RedefineMethod    OnSize,               WPARAM, LPARAM
  RedefineMethod    Print
  RedefineMethod    Save
  VirtualMethod     SaveAs
  VirtualMethod     SelectAll
  VirtualMethod     SelectionDelete
  VirtualMethod     SelectionResetAll                                  
  VirtualMethod     SelectionResetLines                             ;Reset selection on lines only
  VirtualMethod     SelectionSet
  VirtualMethod     SetDirty,             DWORD
  StaticMethod      Startup
  RedefineMethod    Store,                $ObjPtr(Stream)
  RedefineMethod    UpdateStatusbar
  RedefineMethod    WndProc,              DWORD, WPARAM, LPARAM

  DefineVariable    dFlags,               DWORD,      0
  DefineVariable    pResources,           $ObjPtr(EditorResources), NULL
  DefineVariable    TextLines,            LDLL_CONTROL, {NULL, NULL}
  DefineVariable    dTotalLineCount,      DWORD,      0             ;Total count of TextLines
  DefineVariable    dVisTextLineCount,    DWORD,      0
  DefineVariable    dMaxTextLineChrCount, DWORD,      0
  DefineVariable    pHilitedWord,         PSTRING,    NULL
  DefineVariable    dHilitedLen,          DWORD,      0

  DefineVariable    SelectionFst,         LOCATION,   {NULL, 0, 0}  ;First selected location
  DefineVariable    SelectionLst,         LOCATION,   {NULL, 0, 0}  ;Last selected location
  DefineVariable    SelectionRange,       SELRANGE,   {NULL, NULL}  ;-> LOCATION; Set by SelectionSet
  DefineVariable    dSelectionVisLineCnt, DWORD,      0             ;Set by SelectionSet
  DefineVariable    pFocusedView,         $ObjPtr(EditorView),  NULL

  StaticEvent       OnClose,              WM_CLOSE
  StaticEvent       OnEnterSizeMove,      WM_ENTERSIZEMOVE
  StaticEvent       OnExitSizeMove,       WM_EXITSIZEMOVE
  StaticEvent       OnSetFocus,           WM_SETFOCUS

  Embed     EditorDisplays,       Collection
ObjectEnd

; 覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧

Object ClientWnd, ADE_ClientWndID, MdiClientWnd                 ;MDI client window.
  RedefineMethod    Deserialize,          PDESER_INFO
  RedefineMethod    Done
  RedefineMethod    Init,                 POINTER               ;-> Owner
  RedefineMethod    Load,                 $ObjPtr(Stream), PDESER_INFO
  RedefineMethod    Store,                $ObjPtr(Stream)
  StaticMethod      UpdateEditors
  RedefineMethod    WndProc,              DWORD, WPARAM, LPARAM

  StaticEvent       OnDropFiles,          WM_DROPFILES
  StaticEvent       OnEraseBkgnd,         WM_ERASEBKGND
  StaticEvent       OnPaint,              WM_PAINT

  DefineVariable    hBackgroundBrush,     HBRUSH,     0         ;Background brush
  DefineVariable    dChildCount,          DWORD,      0
  DefineVariable    dUnnamedCount,        DWORD,      0         ;Incremental ID for unnamed ChildWnds

  ;Management
  DefineVariable    hLastFocusedWnd,      HANDLE,     0
  DefineVariable    dFlags,               DWORD,      0
  
ObjectEnd

; 覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧

FDS_CURRENT_FILE    equ   0
FDS_OPEN_FILES      equ   1
FDS_PROJECT_FILES   equ   2
FDS_ALL_FILES       equ   3

FDO_MATCH_CASE      equ   BIT00 
FDO_WHOLE_WORD      equ   BIT01
FDO_IGNORE_SPACE    equ   BIT02
FDO_USE_REGEX       equ   BIT04
FDO_WRAP_AROUND     equ   BIT05 

FDD_DOWN            equ   0 
FDD_UP              equ   1
FDD_ALL             equ   2

Object FindDialog, , DialogModeless
  RedefineMethod    CtlsGet
  RedefineMethod    CtlsSet
  StaticMethod      Find
  StaticMethod      Replace
  StaticMethod      ReplaceAll
  StaticMethod      Help
  RedefineMethod    Done
  RedefineMethod    Init,               POINTER
  RedefineMethod    OnCommand,          WPARAM, LPARAM
  RedefineMethod    OnDestroy,          WPARAM, LPARAM
  
  Embed   FindStrings,      %StrCollection
  Embed   ReplaceStrings,   %StrCollection
  
  DefineVariable  dScope,       DWORD,    FDS_CURRENT_FILE
  DefineVariable  dOptions,     DWORD,    0
  DefineVariable  dDirection,   DWORD,    FDD_DOWN
  
  DefineVariable  pFindString,  PSTRING,  NULL 
  DefineVariable  dLineNumber,  DWORD,    1           ;Search Start
  DefineVariable  dCharIndex,   DWORD,    0
ObjectEnd

; 覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧

Object Application, AsmDevEnvID, MdiApp                         ;MDI application.
  VirtualMethod     ChangeLanguage,       DWORD                 ;IDLANG_XXX
  RedefineMethod    Deserialize,          PDESER_INFO
  RedefineMethod    Done
  RedefineMethod    Init
  RedefineMethod    Load,                 $ObjPtr(Stream), PDESER_INFO
  VirtualMethod     LoadContext,          PSTRING
  StaticMethod      ManageGuiCmds,        DWORD
  RedefineMethod    OnSize,               WPARAM, LPARAM
  VirtualMethod     SaveContext,          PSTRING
  StaticMethod      Startup
  VirtualMethod     StatusbarHelp,        PSTRING               ;-> Help string
  RedefineMethod    Store,                $ObjPtr(Stream)

  StaticEvent       OnClose,              WM_CLOSE, WM_QUERYENDSESSION
  StaticEvent       OnCommand,            WM_COMMAND
  StaticEvent       OnCreate,             WM_CREATE
  StaticEvent       OnDestroy,            WM_DESTROY
  StaticEvent       OnEraseBkgnd,         WM_ERASEBKGND

  DefineVariable    dLangID,              DWORD,      IDLANG_ENGLISH
  DefineVariable    hMenuInit,            HMENU,      0
  DefineVariable    hMenuChild,           HMENU,      0
  DefineVariable    hMenuChildWnd,        HMENU,      0
  DefineVariable    hMenuContextEditor,   HMENU,      0
  DefineVariable    dFlags,               DWORD,      0
  DefineVariable    pDirectory,           PSTRING,    NULL
  
  DefineVariable    PrintMargin,          RECT,       {}
  DefineVariable    hDevMode,             HGLOBAL,    0
  DefineVariable    hDevNames,            HGLOBAL,    0

  ;UI elements
  Embed     IconImageList,          MaskedImageList
  Embed     RBar,                   Rebar
  Embed     SBar,                   Statusbar
  Embed     TbFile,                 Toolbar
  Embed     TbEdit,                 Toolbar
  Embed     TbWindow,               Toolbar
  Embed     Menu,                   XMenu
  Embed     ProjWnd,                ProjectWnd
  Embed     PropWnd,                PropertiesWnd
  Embed     SplitterVert,           Splitter
  Embed     SplitterHorz,           Splitter
  Embed     EditorSharedResources,  EditorSharedResources
  Embed     CodeEditorResources,    EditorResources
  Embed     FindDlg,                FindDialog
  
  Embed     ProjFiles,              %StrCollection

ObjectEnd

; 覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧

Object Tab1,, DialogModeless
  RedefineMethod    Done
  RedefineMethod    Init,               POINTER, HWND, POINTER

  VirtualEvent      OnCtlColorStatic,   WM_CTLCOLORSTATIC

  DefineVariable    hBackBrush,         HBRUSH,   0
ObjectEnd

; 覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧

Object Tab2,, DialogModeless
  RedefineMethod    CtlsGet
  RedefineMethod    CtlsSet
ObjectEnd

; 覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧

Object SetupDialog,, DialogModal
  RedefineMethod    CtlsGet
  RedefineMethod    CtlsSet
  RedefineMethod    Done
  RedefineMethod    Init,               POINTER, HWND
  RedefineMethod    OnCommand,          WPARAM, LPARAM
  RedefineMethod    OnDestroy,          WPARAM, LPARAM
  RedefineMethod    OnInitDialog,       WPARAM, LPARAM

  Embed     TabControl,       TabCtrl
  Embed     TabDialog1,       Tab1
  Embed     TabDialog2,       Tab2
  Embed     IconImageList,    MaskedImageList
ObjectEnd

; 覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧

DbgEditorMembers macro InstanceReg, Dest
  DbgHex InstanceReg, "Editor Instance", Dest
  DbgBin [InstanceReg].$Obj(Editor).dFlags,, Dest
  DbgHex [InstanceReg].$Obj(Editor).pResources,, Dest
  DbgDec [InstanceReg].$Obj(Editor).dTotalLineCount,, Dest
  DbgDec [InstanceReg].$Obj(Editor).dVisTextLineCount,, Dest
  DbgDec [InstanceReg].$Obj(Editor).dMaxTextLineChrCount,, Dest
  DbgLine Dest
  DbgHex [InstanceReg].$Obj(Editor).SelectionRange.pBegSelInfo,, Dest
  DbgHex [InstanceReg].$Obj(Editor).SelectionRange.pEndSelInfo,, Dest
  lea xdi, [InstanceReg].$Obj(Editor).SelectionFst
  DbgHex xdi, "SelectionFst", Dest
  DbgHex [InstanceReg].$Obj(Editor).SelectionFst.pTextLine,, Dest
  mov xdi, [InstanceReg].$Obj(Editor).SelectionFst.pTextLine
  .if xdi != NULL
    DbgStrW [xdi].$Obj(EditorTextLine).pBuffer,, Dest
  .endif
  DbgDec [InstanceReg].$Obj(Editor).SelectionFst.dCharIndex,, Dest
  DbgDec [InstanceReg].$Obj(Editor).SelectionFst.dLineNumber,, Dest
  lea xdi, [InstanceReg].$Obj(Editor).SelectionLst
  DbgHex xdi, "SelectionLst", Dest
  DbgHex [InstanceReg].$Obj(Editor).SelectionLst.pTextLine,, Dest
  mov xdi, [InstanceReg].$Obj(Editor).SelectionLst.pTextLine
  .if xdi != NULL
    DbgStrW [xdi].$Obj(EditorTextLine).pBuffer,, Dest
  .endif
  DbgDec [InstanceReg].$Obj(Editor).SelectionLst.dCharIndex,, Dest
  DbgDec [InstanceReg].$Obj(Editor).SelectionLst.dLineNumber,, Dest
  DbgDec [InstanceReg].$Obj(Editor).dSelectionVisLineCnt,, Dest
endm

DbgEditorDisplayMembers macro InstanceReg, Dest
  DbgHex InstanceReg, "Display Instance", Dest
  DbgHex [InstanceReg].$Obj(EditorDisplay).pResources,, Dest
endm

DbgEditorViewMembers macro InstanceReg, Dest
    DbgHex InstanceReg, "View Instance", Dest
  DbgHex [InstanceReg].$Obj(EditorView).CaretLocation.pTextLine,, Dest
  mov xdi, [InstanceReg].$Obj(EditorView).CaretLocation.pTextLine
  .if xdi != NULL
    DbgStr [xdi].$Obj(EditorTextLine).pBuffer,, Dest
  .endif
  DbgDec [InstanceReg].$Obj(EditorView).CaretLocation.dLineNumber,, Dest
  DbgDec [InstanceReg].$Obj(EditorView).CaretLocation.dCharIndex,, Dest
  DbgDec [InstanceReg].$Obj(EditorView).sdCaretVisLineOffset,, Dest
  DbgLine Dest
  DbgHex [InstanceReg].$Obj(EditorView).p1stVisLine,, Dest
  mov xdi, [InstanceReg].$Obj(EditorView).p1stVisLine
  .if xdi != NULL
    DbgStr [xdi].$Obj(EditorTextLine).pBuffer,, Dest
  .endif
  DbgDec [InstanceReg].$Obj(EditorView).d1StVisLineCount,, Dest
  DbgDec [InstanceReg].$Obj(EditorView).d1stVisLineNum,, Dest
  DbgDec [InstanceReg].$Obj(EditorView).d1stVisCharIndex,, Dest
  DbgDec [InstanceReg].$Obj(EditorView).dLockedVertIndex,, Dest
  DbgDec [InstanceReg].$Obj(EditorView).dCharMaxFullVis,, Dest
  DbgDec [InstanceReg].$Obj(EditorView).dLineMaxFullVis,, Dest
  DbgBin [InstanceReg].$Obj(EditorView).dFlags,, Dest
endm

DbgEditor macro InstanceReg, InfoText, Dest
  if DEBUGGING
    DbgSaveContext
    DbgClearTxt Dest
    DbgEditorMembers InstanceReg, Dest
    DbgLoadContext
  endif
endm

DbgEditorDisplay macro InstanceReg, InfoText, Dest
  if DEBUGGING
    DbgSaveContext
    DbgClearTxt Dest
    DbgEditorDisplayMembers InstanceReg, Dest
    DbgLine2 Dest
    lea xbx, [InstanceReg].$Obj(EditorDisplay).View
    DbgEditorDisplayMembers xbx, Dest
    DbgLine2 Dest
    mov xbx, [xbx].$Obj(EditorView).pOwner
    mov xbx, [xbx].$Obj(EditorDisplay).pOwner
    DbgEditorMembers xbx, Dest
    DbgLoadContext
  endif
endm

DbgEditorView macro InstanceReg, InfoText, Dest
  if DEBUGGING
    DbgSaveContext
    DbgClearTxt Dest
    DbgEditorViewMembers InstanceReg, Dest
    DbgLine2 Dest
    mov xbx, [InstanceReg].$Obj(EditorView).pOwner
    DbgEditorDisplayMembers xbx, Dest
    DbgLine2 Dest
    mov xbx, [xbx].$Obj(EditorDisplay).pOwner
    DbgEditorMembers xbx, Dest
    DbgLoadContext
  endif
endm

DbgTextLine macro InstanceReg, InfoText, Dest
  if DEBUGGING
    DbgSaveContext
    DbgClearTxt Dest
    DbgHex InstanceReg, "Instance", Dest
    DbgHex [InstanceReg].$Obj(EditorTextLine).Link.pLinkFwrd,, Dest
    DbgHex [InstanceReg].$Obj(EditorTextLine).Link.pLinkBack,, Dest
    DbgHex [InstanceReg].$Obj(EditorTextLine).pBuffer,, Dest
    DbgStrW [InstanceReg].$Obj(EditorTextLine).pBuffer,, Dest
    DbgDec [InstanceReg].$Obj(EditorTextLine).dCharCapacity,, Dest
    DbgDec [InstanceReg].$Obj(EditorTextLine).dLength,, Dest
    DbgDec [InstanceReg].$Obj(EditorTextLine).Selection.dBegIndex,, Dest
    DbgDec [InstanceReg].$Obj(EditorTextLine).Selection.dEndIndex,, Dest
    DbgDec [InstanceReg].$Obj(EditorTextLine).dBookmark,, Dest
    DbgBin [InstanceReg].$Obj(EditorTextLine).dFlags,, Dest
    DbgLine Dest
    mov xbx, [InstanceReg].$Obj(EditorTextLine).pOwner
    DbgEditorMembers xbx, Dest
    DbgLoadContext
  endif
endm

; 覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧

include ADE_Helper.inc
include ADE_About.inc
include ADE_Application.inc
include ADE_EditorSharedResources.inc
include ADE_EditorResources.inc
include ADE_ClientWnd.inc
include ADE_ChildWnd.inc
include ADE_Editor.inc
include ADE_SetupDialog.inc
include ADE_KeywordGroupCollection.inc
include ADE_KeywordCollection.inc
include ADE_EditorDisplay.inc
include ADE_EditorView_1.inc
include ADE_EditorView_2.inc
include ADE_EditorTextLine.inc
include ADE_FindDialog.inc

