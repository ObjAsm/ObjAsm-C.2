; ==================================================================================================
; Title:      TextView.inc
; Author:     G. Friedrich
; Version:    C.1.4
; Purpose:    ObjAsm support of TextView objects.
;             It displays formatted text using styles like font, color, background, etc. and
;             control commands using a MASM friendly markup string.
; Notes:      Version C.1.4, August 2022
;               - @x introduced to select system color x. This solves the color changes when 
;                 the UI is switched to "High Contrast".
;             Version C.1.3, March 2021
;               - Code refactored for better performance. The code is divided into 3 stages:
;                 Parse, Calc and Draw. The code flow can brach into these stages as needed.
;               - Internal strings are always Wide, regardles of the compilation target.
;               - Zoom capability added.
;               - Zoom and Pan gestures added.
;               - Options (Auto-Line-Break, Zoomable, etc.) can be set using markups
;               - Consistent short markups added.
;               - Text callback added to allow the implementation of simple controls, like
;                 radiobuttons or checkboxes.
;             Version C.1.2, October 2020
;               - {TAB} calculation corrected.
;             Version C.1.1, April 2020
;               - First release.
; Links:      https://docs.microsoft.com/en-us/windows/win32/gdi/string-widths-and-heights
;             https://codepundit.wordpress.com/2012/04/14/text-metrics-wow/
;             https://docs.microsoft.com/de-ch/windows/win32/gdi/drawing-text-from-different-fonts-on-the-same-line
; ==================================================================================================


; Markup specification:
;
; Styles: a series of markup identifiers enclosed in square brackets [] and separated by commas.
;         A value can follow each identifier. For some identifiers, the value is a decimal number
;         or a hex value. Hex values are specified prepending a # character.
;         If an identifier expects a value but it is missing, the control's default is used instead.
;         Each defined style is pushed onto a stack and popped using [~].
;         Markup identifiers are not case sensitive.
;
;     Style identifier: (00 stands for a number)
;         Verbose           Short   Description
;         ALIGN.CENTER        AC    Center alignment.
;         ALIGN.LEFT          AL    Left alignment.
;         ALIGN.RIGHT         AR    Right alignment.
;         APP 00                    Active area: notifies the parent on mouse events.
;         BGCOLOR #000000     G     Text background color as a RGB hex value.
;         BOLD                B     Bold style.
;         BOX #000000         X     Box with background color indicated by the RGB hex value.
;         COLOR #000000       C     Text foreground color indicated by the RGB hex value.
;         CANVAS #000000      N     Control background color indicated by the RGB hex value.
;         FONT 'Font Name'    F     Font face.
;         HANGING 000         HI    Set hanging text indentation.
;         HEIGHT 00           H     Font size in logical units. If + or - is prepended, then the
;                                   value is relative to the previous setting.
;         INDENT 000          FI    Set first text indentation.
;         ITALIC              I     Italic style.
;         STRIKEOUT           O     Strike out style.
;         SUB                 v     Subscript.
;         SUP                 ^     Superscript.
;         TIP 000                   Request Tooltip text from the parent window.
;         TXT 000                   Request text from the parent window.
;         UNDERLINE           U     Underlined.
;
;
;     Example: [FONT 'Segoe UI', SIZE 12, COLOR #7F7F7F, BGCOLOR #000000]
;          or: [FONT 'Segoe UI', SIZE 12, COLOR @6, BGCOLOR @5]
;
;     Notes: - the "#" character denotes a hex value.
;            - the "@" character denotes a system value like a system color.
;              E.g C@8 = Color COLOR_WINDOWTEXT, C@26 = COLOR_HOTLIGHT (links), ...
;              Check valid values for the current OS at 
;              https://docs.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-getsyscolor
;            - a character in the range 0..9 denotes a decimal value.
;
; Commands: a single markup identifier enclosed in curly brackets {}.
;           Command markup identifiers are not case sensitive.
;
;     Command identifier:
;         Verbose           Short   Description
;         #00                       Insert a (Unicode) character specified by the hex value.
;                                   E.g.: {#5B} displays a [.
;         BREAK               B     Line break.
;         COVER               C     Perfom a drawing action by the parent at the end of the
;                                   rendering process, covering previous drawings.
;         DRAW                D     Perfom a drawing action by the parent when it appears on the markup.
;         PADDING 000         PA    Set all padding values.
;         PADDING.BOTTOM 000  PB    Set bottom marign.
;         PADDING.LEFT 000    PL    Set left margin.
;         PADDING.RIGHT 000   PR    Set right margin.
;         PADDING.TOP 000     PT    Set top margin.
;         PARA                P     Paragraph.
;         TAB                 T     Perform a tab.
;         TABL 00             TL    Set a left tabstop. Text is on the right of the tab.
;         TABC 00             TC    Set a center tabstop. Text is placed on the tab center.
;         TABR 00             TR    Set a right tabstop. Test is on the left of the tab.
;         TABCLR                    Reset all tabstops.
;         SIZE.X 000          SX    Set MemBitmap width.
;         SIZE.Y 000          SY    Set MemBitmap heigth.
;         AUTOLINEBREAK       ALB   Activate automatic line break
;
;     Example: {BREAK}
;
;
;
; Supported otions:
; TVO_AUTO_LINEBREAK:If a word extend past the edge of the output view, it breaks the line
;                    automatically between the words.
;
; ****************** NOT IMPLEMENTED YET *******************
; TVO_RTLREADING:    Not implemented.
; TVO_PATH_ELLIPSIS: Replaces characters in the middle of the string with ellipses so that the
;                    result fits in the specified rectangle. If the string contains backslash (\)
;                    characters, TV_PATH_ELLIPSIS preserves as much as possible of the text after
;                    the last backslash.
; TVO_WORD_ELLIPSIS: If the end of a string does not fit in the rectangle, it is truncated and
;                    ellipses are added.
;
; Design notes:
;  - Tab characters are different from {TAB} commands. Tab characters (ASCII 9) are expanded to
;    spaces using the dTab2Spaces (usually = 8) value.
;  - The APP style sends a notification to the parent window to perform an action, like an
;    hyperlink or any another task.
;  - The TIP style sends a notification to the parent window to get information that can be
;    displayed using a Tooltip.
;  - The TXT style sends a notification to the parent window to get text to display.
;  - The DRAW command sends a notification to the parent window to perform a drawing operation
;    once all other text related drawing tasks are finished. This ensures that the control
;    background is completely drawn before the drawing operation is started.
;  - Fist Indent {FI} and Hanging Indent {HI} control the indentation of the first line and the
;    following lines respectively. {B} or {P} initiate a new indentation sequence.


DEF_TEXTVIEW struc
  xCtlID        XWORD       ?             ;Contol ID
  dStyle        DWORD       ?             ;Style
  dExStyle      DWORD       ?             ;Extended style
  pText         PSTRING     ?             ;-> Markup text passed as caption
  union
    rect        RECT        {}
    struct
      sdPosX    SDWORD      ?             ;X position
      sdPosY    SDWORD      ?             ;Y position
      dWidth    DWORD       ?             ;Width
      dHeight   DWORD       ?             ;Height
    ends
  ends
DEF_TEXTVIEW ends
PDEF_TEXTVIEW typedef ptr DEF_TEXTVIEW

;TextView Format Flags
TVO_AUTO_LINEBREAK  equ   BIT00           ;Text lines are automatically broken
TVO_ZOOMABLE        equ   BIT01           ;The text is zoomable
TVO_RTLREADING      equ   BIT02           ;Not implemented
TVO_PATH_ELLIPSIS   equ   BIT03           ;Not implemented
TVP_WORD_ELLIPSIS   equ   BIT04           ;Not implemented

TVDEFAULT_FONT_SIZE equ   10
TVZOOM_BASE         equ   72

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Object:     TextView
; Purpose:    Provide a control that displays formatted text using styles like font, color,
;             background, etc. and control commands using a MASM friendly markup string.

Object TextView, TextViewID, Window
  VirtualMethod     Calc
  VirtualMethod     Dispatch,           HWND, DWORD, WPARAM, LPARAM
  RedefineMethod    Done
  StaticMethod      Draw
  RedefineMethod    Init,               POINTER, HWND, PDEF_TEXTVIEW
  StaticMethod      GetEntryFrom,       $ObjPtr(XWCollection), POINTS
  RedefineMethod    OnSettingChange,    WPARAM, LPARAM
  RedefineMethod    OnSize,             WPARAM, LPARAM
  StaticMethod      Parse
  StaticMethod      Reset
  VirtualMethod     SetExtent
  VirtualMethod     SetZoomFactor,      DWORD
  StaticMethod      Startup
  StaticMethod      WidthToNextStop,    DWORD
  RedefineMethod    WndProc,            DWORD, WPARAM, LPARAM

  VirtualEvent      OnButtonDown,       WM_LBUTTONDOWN, WM_MBUTTONDOWN, WM_RBUTTONDOWN
  VirtualEvent      OnButtonUp,         WM_LBUTTONUP, WM_MBUTTONUP, WM_RBUTTONUP
  VirtualEvent      OnCommand,          WM_COMMAND         ;Parent forwarded
  VirtualEvent      OnCreate,           WM_CREATE
  VirtualEvent      OnCtlColorStatic,   WM_CTLCOLORSTATIC
  VirtualEvent      OnDestroy,          WM_DESTROY
  VirtualEvent      OnGesture,          WM_GESTURE
  VirtualEvent      OnGetFont,          WM_GETFONT
  VirtualEvent      OnGetZoom,          EM_GETZOOM
  VirtualEvent      OnHScroll,          WM_HSCROLL
  VirtualEvent      OnMouseMove,        WM_MOUSEMOVE
  VirtualEvent      OnMouseWheel,       WM_MOUSEWHEEL
  VirtualEvent      OnNotify,           WM_NOTIFY
  VirtualEvent      OnPaint,            WM_PAINT
  VirtualEvent      OnPrintClient,      WM_PRINTCLIENT    ;Requirend by AnimanteWindow
  VirtualEvent      OnSetFont,          WM_SETFONT
  VirtualEvent      OnSetText,          WM_SETTEXT
  VirtualEvent      OnSetZoom,          EM_SETZOOM
  VirtualEvent      OnThemeChanged,     WM_THEMECHANGED
  VirtualEvent      OnVScroll,          WM_VSCROLL

  DefineVariable    pMarkupText,        PSTRING,    NULL
  DefineVariable    dFlags,             DWORD,      0
  DefineVariable    hParent,            HWND,       0
  DefineVariable    hMemDC,             HDC,        0     ;Memory DC
  DefineVariable    hMemBmp,            HBITMAP,    0     ;Memory DC bitmap
  DefineVariable    hPrvBmp,            HBITMAP,    0     ;Previous hMemDC bitmap
  DefineVariable    hPrvBrush,          HBRUSH,     0     ;Previous hMemDC brush
  DefineVariable    hPrvFont,           HFONT,      0     ;Previous hMemDC font
  DefineVariable    Padding,            RECT,       {}    ;No drawable borders
  DefineVariable    Extent,             POINT,      {}    ;Total area size defined by the markup str
  DefineVariable    DrawExtent,         POINT,      {}    ;Actual drawing area size inside Extent
  DefineVariable    IdealDrawExtent,    POINT,      {}    ;Drawing area size required by markup str
  DefineVariable    ClientRect,         RECT,       {}    ;Current Client area
  DefineVariable    Origin,             POINT,      {}    ;Coordinates of the left/top visible corner
  DefineVariable    dOptions,           DWORD,      0     ;See "Supported options" above
  DefineVariable    dLogPixY,           DWORD,      0
  DefineVariable    dAllLinesWidth,     DWORD,      0
  DefineVariable    dGestureZoomFirst,  DWORD,      0
  DefineVariable    dGestureZoomLast,   DWORD,      0
  DefineVariable    GesturePanPos,      POINT,      {}

  DefineVariable    DefaultTextColor,   RGBQUAD,    {}    ;B,G,R,0    Text forground color
  DefineVariable    DefaultBackColor,   RGBQUAD,    {}    ;B,G,R,0    Text background color
  DefineVariable    CanvasColor,        RGBQUAD,    {}    ;B,G,R,0    Control background color
  DefineVariable    hCanvasBrush,       HBRUSH,     0
  DefineVariable    pDefaultFontFace,   PSTRING,    NULL
  DefineVariable    dDefaultFontSize,   DWORD,      TVDEFAULT_FONT_SIZE
  DefineVariable    dZoomFactor,        DWORD,      TVZOOM_BASE
  DefineVariable    dTab2Spaces,        DWORD,      8     ;Default value
  DefineVariable    hToolTip,           HWND,       0

  Embed    LineInfos,     DataCollection            ;TVLINE_INFO items
  Embed    Entries,       DataCollection            ;TVENTRY items, like texts, blanks & commands
  Embed    ActiveAreas,   XWCollection              ;Collection of PTVENTRYs
  Embed    InfoAreas,     XWCollection              ;Collection of PTVENTRYs
  Embed    Styles,        DataCollection            ;DataCollection of TVSTYLE structures
  Embed    StyleStack,    XWCollection              ;Collection of PTVSTYLEs
  Embed    TabStops,      SortedDataCollection      ;SortedDataCollection of PVTABSTOP structures
  Embed    GdiObjects,    XWCollection              ;Collection of GDI HANDLEs
  Embed    CoverTasks,    DataCollection            ;DataCollection of TVNM_DRAW structures
ObjectEnd

; Layout:
;
;           ———————————————————————————————————————————————————————————————
;          |           /\  Top                                             |<--Extent
;          |           \/  Padding                                         |
;          |     —————————————————————————————————————————————————————     |
;          |    |    <-------------- Line Length -------------------->|    |
;          |    |<-->Lorem ipsum dolor sit amet, consetetur sadipscing|<-------DrawExtent
;          |    |  ¦     <------------ Line Length ------------------>|    |
;          |    |  ¦     elitr, sed diam nonumy eirmod tempor invidunt|    |
;          |    |  ¦     <----------- Line Length ---------------->   |    |
;          |    |<------>ut labore et dolore magna aliquyam erat...   |    |
;          |    |  ¦  ¦                                               |    |
;          |    |  ¦  ¦                                               |    |
;          |    |  ¦  Hanging                                         |    |
;  Left    |    |  ¦                                                  |    | Right
;  Padding |<-->|  Indent                                             |<-->| Padding
;          |    |                                                     |    |
;          |    |                                                     |    |
;          |    |                                                     |    |
;          |     —————————————————————————————————————————————————————     |
;          |           /\ Bottom                                           |
;          |           \/ Padding                                          |
;           ——————————————————————————————————————————————————————————————— 
;
;
; Sizeing strategy (pseudo code):
;
; ----------------------------------------------------------
; OnCreate:
;   Parse
;   if Extend.x defined then
;     DrawExtent.x = Extent.x - Padding
;   endif
;   if Extend.y defined then
;     DrawExtent.y = Extent.y - Padding
;   endif
;   if Extent.x and Extent.y defined
;     Calc
;     Draw
;   else
;     if not AUTO_LINEBREAK
;       Calc
;       if Extend.x not defined
;         DrawExtent.x = IdealDrawExtent.x
;         Extend.x = DrawExtent.x + Padding
;       endif
;       if Extend.y not defined
;         DrawExtent.y = IdealDrawExtent.y
;         Extend.y = DrawExtent.y + Padding
;       endif
;       Draw
;     else
;       if Extent.x defined
;         Calc
;         if Extent.y not defined
;           DrawExtent.y = IdealDrawExtent.y
;           Extend.y = DrawExtent.y + Padding
;         endif
;         Draw
;       endif
;     endif
;   endif
;
; ----------------------------------------------------------
; OnSize:
;   if AUTO_LINEBREAK
;     if Extent.x not defined
;       Extend.x = RawClient.x
;       DrawExtent.x = Extend.x - Padding
;       Calc, 1. try
;       if Failed
;         Extend.x = RawClient.x - CxScrollBar
;         DrawExtent.x = Extend.x - Padding
;         Calc, 2. try
;       endif
;       Draw
;     endif
;   endif



; ==================================================================================================

TVTAG struc                               ;Common structure for TVSTAG, TVCTAG & TVOTAG
  dLength       DWORD       ?             ;Mnemonic length
  pMnemonic     PSTRING     ?             ;-> Mnemonic string (without brackets etc.)
TVTAG ends
PTVTAG typedef ptr TVTAG

TVSTYLE struc
  dFlags        DWORD       ?             ;Style flags TVSF_xxx
  TextColor     RGBQUAD     {}
  BackColor     RGBQUAD     {}
  BoxColor      RGBQUAD     {}
  dAlignment    DWORD       ?             ;TVALIGN_xxx
  dIndent       DWORD       ?             ;First line indentation
  dHanging      DWORD       ?             ;Hanging text indentation
  dFontSize     DWORD       ?             ;Font size in logical units
  hFont         HFONT       ?             ;Font HANDLE
  LogFont       LOGFONT     {}
  TextMetric    TEXTMETRIC  {}
  hBackBrush    HBRUSH      ?             ;Background brush HANDLE
  dID           DWORD       ?             ;APP/TIP/DRAW ID
  dTextID       DWORD       ?             ;TXT ID - Handled separately since it can overlap with dID
TVSTYLE ends
PTVSTYLE typedef ptr TVSTYLE

TVENTRY struc
  dType         DWORD       ?             ;TVET_xxx  - TEXT, BLANK, CMD
  Area          RECT        {}            ;Position on the client area
  Extent        RECT        {}            ;Size of the area, left and top members are always zero
  pStyle        PTVSTYLE    ?             ;-> TVSTYLE
  dCharCount    DWORD       ?             ;# of characters in pText. Needed to convert tabs to " "
  pString       PSTRING     ?             ;-> zero terminated string (text or command string argument)
  pTag          PTVTAG      ?             ;Could be any type of TAG that created this entry
  xValue        XWORD       ?             ;Command parameter
TVENTRY ends
PTVENTRY typedef ptr TVENTRY

TVNM_APP struc
  Header        NMHDR       <>
  dID           DWORD       ?             ;App ID
  dButton       DWORD       ?             ;Pressed mouse, CTRL or SHIFT button
  dEntryIndex   DWORD       ?             ;TVENTRY index into Entries collection
TVNM_APP ends
PTVNM_APP typedef ptr TVNM_APP

TVNM_TXT struc
  Header        NMHDR       <>
  dID           DWORD       ?             ;Txt ID
  ppText        POINTER     ?             ;-> TVENTRY.pString
  dEntryIndex   DWORD       ?             ;TVENTRY index into Entries collection
TVNM_TXT ends
PTVNM_TEXT typedef ptr TVNM_TXT

TVNM_TIP struc
  Header        NMHDR       <>
  dID           DWORD       ?
  pText         PSTRING     ?
TVNM_TIP ends
PTVNM_TIP typedef ptr TVNM_TIP

TVNM_DRAW struc
  Header        NMHDR       <>
  dID           DWORD       ?
  hDC           HDC         ?
  Position      POINT       <>
  dLineHeight   DWORD       ?
  Extent        POINT       <>
  Padding       RECT        <>
  pStyle        PTVSTYLE    ?
  dZoomFactor   DWORD       ?
TVNM_DRAW ends
PTVNM_DRAW typedef ptr TVNM_DRAW


if IMPLEMENT

%CStr cTextViewClass&TARGET_STR_AFFIX, "TextView"

;Zoom parameter
TVZOOM_MIN          equ   TVZOOM_BASE/2
TVZOOM_MAX          equ   5*TVZOOM_BASE
TVZOOM_STEP         equ   TVZOOM_BASE/16

;TextView Internal Flags
TVIF_SELF_INST      equ   BIT00           ;Object was instanced by CreateWindowEx
TVIF_EXTENT_X_SET   equ   BIT01           ;Extent.x was defined with a SIZE.X command
TVIF_EXTENT_Y_SET   equ   BIT02           ;Extent.y was defined with a SIZE.Y command
TVIF_SHOW_SB_HORZ   equ   BIT04           ;Horz ScrollBar is shown
TVIF_SHOW_SB_VERT   equ   BIT05           ;Vert ScrollBar is shown
TVIF_TOOLTIP_ACTIVE equ   BIT06           ;Tooltip is active
TVIF_TOOLTIP_SHOW   equ   BIT07
TVIF_IN_ONSIZE      equ   BIT08           ;Inside OnSize

;Special characters
TVTAG_STYLE_OPEN    equ   "["             ;{#5B}
TVTAG_STYLE_CLOSE   equ   "]"
TVTAG_CMD_OPEN      equ   "{"             ;{#7B}
TVTAG_CMD_CLOSE     equ   "}"

;TVENTRY types
TVET_TEXT           equ   1
TVET_BLANK          equ   2
TVET_CMD            equ   3

;TVSTYLE flags
TVSF_SUP            equ   BIT00           ;Superscript
TVSF_SUB            equ   BIT01           ;Subscript
TVSF_ACTIVE         equ   BIT02           ;Active area
TVSF_TIP            equ   BIT03           ;Tip area
TVSF_TEXTCALLBACK   equ   BIT04           ;Text callback
TVSF_BOX            equ   BIT05           ;Boxed
TVSF_INCR           equ   BIT06           ;"+" sign detected while parsing the font size
TVSF_DECR           equ   BIT07           ;"-" sign detected while parsing the font size

;TVSTYLE change flag
TVSC_NOTHING        equ   0
TVSC_FONT           equ   BIT00
TVSC_BACKCOLOR      equ   BIT01

;TextView Alignment
TVALIGN_LEFT        equ   0
TVALIGN_CENTER      equ   1
TVALIGN_RIGHT       equ   2

;TABSTOP types
TVTAB_TYPE_LEFT     equ   0
TVTAB_TYPE_CENTER   equ   1
TVTAB_TYPE_RIGHT    equ   2

;TVNM_XX.NMHDR.code values
TVNMC_APP_MOUSEOVER equ   1
TVNMC_APP_MOUSEDOWN equ   2
TVNMC_APP_MOUSEUP   equ   3
TVNMC_TIP           equ   4
TVNMC_TXT           equ   5
TVNMC_DRAW          equ   6

TVTOOLTIP_WNDID     equ   62348912


TVStyleHandler typedef proto :POINTER
PTVStyleHandler typedef ptr TVStyleHandler

TVSTAG struc                              ;TV Style TAG
                TVTAG     <>
  pHandler      POINTER   ?               ;Style handler offset
TVSTAG ends
PTVSTAG typedef ptr TVSTAG

TVCTAG struc                              ;TV Command TAG
                TVTAG     <>
  pCalcHandler  POINTER   ?               ;Calc handler offset
  pDrawHandler  POINTER   ?               ;Draw handler offset
TVCTAG ends
PTVCTAG typedef ptr TVCTAG

TVOTAG struc                              ;TV Option TAG
                TVTAG     <>
  pHandler      POINTER   ?               ;Option handler offset (= command handler)
TVOTAG ends
PTOCTAG typedef ptr TVOTAG

TVTABSTOP struc
  dPosition     DWORD     ?
  bType         BYTE      ?               ;TVTAB_TYPE_xxx
TVTABSTOP ends
PVTABSTOP typedef ptr TVTABSTOP

TVLINE_INFO struc
  Position      POINT     <>
  dLength       DWORD     ?
  dHeight       DWORD     ?
  dBegEntryIdx  DWORD     ?
  dEndEntryIdx  DWORD     ?
  dAlignment    DWORD     ?
  dBoxed        DWORD     ?
  BoxColor      RGBQUAD   <>
  dMaxAscent    DWORD     ?
  dLastAscent   DWORD     ?
  dMaxDescent   DWORD     ?
  dMaxExtLeading  DWORD     ?
  dTotalWith    DWORD     ?
TVLINE_INFO ends
PTVLINE_INFO typedef ptr TVLINE_INFO

;Note: keep the TVTAGs ordered by ascending length order and then in ascending Mnemonic order!
;      Otherwise the Mnemonics could not be found.

.const

DefineStyleTag macro Mnem, HandlerName
  local StrName

  TStr StrName, Mnem
  TVSTAG <<lengthof(StrName), StrName>, TVSH_&HandlerName>
endm

TVTAG_STYLES label TVSTAG
  DefineStyleTag "B",             BOLD                  ;Bold
  DefineStyleTag "C",             COLOR                 ;Text color
  DefineStyleTag "F",             FONT                  ;Font
  DefineStyleTag "G",             BGCOLOR               ;Background color
  DefineStyleTag "H",             HEIGHT                ;Font height
  DefineStyleTag "I",             ITALIC                ;Italic
  DefineStyleTag "N",             CANVAS                ;Canvas color
  DefineStyleTag "O",             STRIKEOUT             ;Strikeout
  DefineStyleTag "U",             UNDERLINE             ;Underline
  DefineStyleTag "X",             BOX                   ;Boxed
  DefineStyleTag "^",             SUP                   ;Superscript
  DefineStyleTag "v",             SUB                   ;Subscript
  DefineStyleTag "AC",            ALIGNCENTER           ;Align Center
  DefineStyleTag "AL",            ALIGNLEFT             ;Align Left
  DefineStyleTag "AR",            ALIGNRIGHT            ;Align Right
  DefineStyleTag "FI",            INDENT                ;First indent
  DefineStyleTag "HI",            HANGING               ;Hanging indent
  DefineStyleTag "APP",           APP                   ;Application notification
  DefineStyleTag "BOX",           BOX                   ;Boxed
  DefineStyleTag "SUB",           SUB                   ;Subscript
  DefineStyleTag "SUP",           SUP                   ;Superscript
  DefineStyleTag "TIP",           TIP                   ;ToolTip callback
  DefineStyleTag "TXT",           TXT                   ;Text callback
  DefineStyleTag "BOLD",          BOLD                  ;Bold
  DefineStyleTag "FONT",          FONT                  ;Font
  DefineStyleTag "COLOR",         COLOR                 ;Text color
  DefineStyleTag "CANVAS",        CANVAS                ;Canvas color
  DefineStyleTag "HEIGHT",        HEIGHT                ;Font height
  DefineStyleTag "INDENT",        INDENT                ;First indent
  DefineStyleTag "ITALIC",        ITALIC                ;Italic
  DefineStyleTag "BGCOLOR",       BGCOLOR               ;Background color
  DefineStyleTag "HANGING",       HANGING               ;Hanging indent
  DefineStyleTag "STRIKEOUT",     STRIKEOUT             ;Strikeout
  DefineStyleTag "UNDERLINE",     UNDERLINE             ;Underline
  DefineStyleTag "ALIGN.LEFT",    ALIGNLEFT             ;Align Left
  DefineStyleTag "ALIGN.RIGHT",   ALIGNRIGHT            ;Align Right
  DefineStyleTag "ALIGN.CENTER",  ALIGNCENTER           ;Align Center
  DWORD 0                                               ;End marker

DefineCmdTag macro TagOffsetName, Mnemonic, HandlerName
  local StrName

  TStr StrName, Mnemonic
  ifnb <TagOffsetName>
    TVCTAG_&TagOffsetName::
  endif
  TVCTAG <<lengthof(StrName), StrName>, TVCCH_&HandlerName, TVCDH_&HandlerName>
endm

;Isolated TVCTAG
  TVCTAG_CHAR::
  TVCTAG <<0, NULL>, TVCCH_CHAR, TVCDH_CHAR>            ;Character

TVTAG_CMDS label TVCTAG
  DefineCmdTag BREAK_S,   "B",        BREAK             ;Line Break (soft break)
  DefineCmdTag ,          "C",        COVER             ;Draw the foreground
  DefineCmdTag ,          "D",        DRAW              ;Draw the background
  DefineCmdTag PARA_S,    "P",        PARA              ;Paragraph
  DefineCmdTag ,          "L",        LINE              ;Horizontal line
  DefineCmdTag TAB_S,     "T",        TAB               ;Perform a Tabstop
  DefineCmdTag ,          "TC",       TABC              ;Set center Tabstop
  DefineCmdTag ,          "TL",       TABL              ;Set left Tabstop
  DefineCmdTag ,          "TR",       TABR              ;Set right Tabstop
  DefineCmdTag TAB,       "TAB",      TAB               ;Perform a Tabstop
  DefineCmdTag ,          "DRAW",     DRAW              ;Regular draw
  DefineCmdTag ,          "LINE",     LINE              ;Horizontal line
  DefineCmdTag PARA,      "PARA",     PARA              ;Paragraph
  DefineCmdTag ,          "TABC",     TABC              ;Set center Tabstop
  DefineCmdTag ,          "TABL",     TABL              ;Set left Tabstop
  DefineCmdTag ,          "TABR",     TABR              ;Set right Tabstop
  DefineCmdTag BREAK,     "BREAK",    BREAK             ;Line break (soft break)
  DefineCmdTag ,          "COVER",    COVER             ;Cover drawing
  DefineCmdTag ,          "TABCLR",   TABCLR            ;Reset all tabstops
  DWORD 0                                               ;End marker

DefineOptTag macro Mnem, HandlerName
  local StrName

  TStr StrName, Mnem
  TVOTAG <<lengthof(StrName), StrName>, TVOH_&HandlerName>
endm

TVTAG_OPTIONS label TVOTAG
  DefineOptTag "Z",               ZOOMABLE              ;Set Zoomable option
  DefineOptTag "PA",              PADDING               ;Set all paddings
  DefineOptTag "PB",              PADDING_BOT           ;Set bottom padding
  DefineOptTag "PL",              PADDING_LFT           ;Set left padding
  DefineOptTag "PR",              PADDING_RGT           ;Set right padding
  DefineOptTag "PT",              PADDING_TOP           ;Set top padding
  DefineOptTag "SX",              SIZE_X                ;Set draw area width
  DefineOptTag "SY",              SIZE_Y                ;Set draw area height
  DefineOptTag "ALB",             AUTO_LINEBREAK        ;Activate automatic linebreak option
  DefineOptTag "SIZE.X",          SIZE_X                ;Set draw area width
  DefineOptTag "SIZE.Y",          SIZE_Y                ;Set draw area height
  DefineOptTag "PADDING",         PADDING               ;Set all paddings simultaneously
  DefineOptTag "ZOOMABLE",        ZOOMABLE              ;Set Zoomable option
  DefineOptTag "PADDING.TOP",     PADDING_TOP           ;Set top padding
  DefineOptTag "PADDING.LEFT",    PADDING_LFT           ;Set left padding
  DefineOptTag "AUTOLINEBREAK",   AUTO_LINEBREAK        ;Activate automatic linebreak option
  DefineOptTag "PADDING.RIGHT",   PADDING_RGT           ;Set right padding
  DefineOptTag "PADDING.BOTTOM",  PADDING_BOT           ;Set bottom padding
  DWORD 0                                               ;End marker

.code

;DecodeGesture proc uses xbx xdi xsi hWnd:HWND, dMessage:DWORD, wParam:WPARAM, lParam:LPARAM
;  local GestInfo:GESTUREINFO, bResult:BOOL, bHandled:BOOL, dError:DWORD
;
;  ;Create a structure to populate and retrieve the extra message info.
;  invoke MemZero, addr GestInfo, sizeof GestInfo
;
;  mov GestInfo.cbSize, sizeof GestInfo
;
;  mov bResult, $32($invoke(GetGestureInfo, lParam, addr GestInfo))
;  mov bHandled, FALSE
;
;  .if bResult
;    ;Now interpret the gesture
;    .if GestInfo.dwID == GID_ZOOM
;      DbgText "Zooming gesture"
;      ;Code for zooming goes here
;      mov bHandled, TRUE
;    .elseif GestInfo.dwID == GID_PAN
;      DbgText "Panning gesture"
;      ;Code for panning goes here
;      mov bHandled, TRUE
;    .elseif GestInfo.dwID == GID_ROTATE
;      ;Code for rotation goes here
;      DbgText "Rotating gesture"
;      mov bHandled, TRUE
;    .elseif GestInfo.dwID == GID_TWOFINGERTAP
;      ;Code for two-finger tap goes here
;      DbgText "Two-Finger tap gesture"
;      mov bHandled, TRUE
;    .elseif GestInfo.dwID == GID_PRESSANDTAP
;      DbgText "Roll over gesture"
;      ;Code for roll over goes here
;      mov bHandled, TRUE
;    .else
;      DbgText "Unknown gesture"
;      ;A gesture was not recognized
;    .endif
;  .else
;    DbgApiError
;  .endif
;  .if bHandled
;    xor eax, eax
;  .else
;    invoke DefWindowProc, hWnd, dMessage, wParam, lParam
;  .endif
;  ret
;DecodeGesture endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     GdiObjects.DestroyItem
; Purpose:    Auxiliar function to release a GDI Object from the collection.
; Arguments:  Arg1: Object HANDLE.
; Return:     Nothing.

Method GdiObjects.DestroyItem,, hObject:HANDLE
  .if hObject != 0
    invoke DeleteObject, hObject
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Entries.DestroyItem
; Purpose:    Auxiliar function to release the string from the collection.
; Arguments:  Arg1: -> TVENTRY.
; Return:     Nothing.

Method Entries.DestroyItem,, pItem:POINTER
  .if pItem != NULL
    mov xcx, pItem
    invoke StrDispose, [xcx].TVENTRY.pString            ;Safe if pString = NULL
    MemFree pItem
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     TabStops.Compare
; Purpose:    Comparison of VTABSTOPs.
; Arguments:  Arg1: -> TVTABSTOP 1
;             Arg2: -> TVTABSTOP 2
; Return:     eax: Comparison result.

Method TabStops.Compare,, pItem1:PVTABSTOP, pItem2:PVTABSTOP
  ?mov xdx, pItem1
  mov xcx, pItem2
  mov eax, [xdx].TVTABSTOP.dPosition
  sub eax, [xcx].TVTABSTOP.dPosition
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     TextView.Calc
; Purpose:    Calulate internal values and the maximal extent used to render the markup text.
; Arguments:  None.
; Return:     eax = TRUE if succeeded, otherwise FALSE.
; Note:       On entry, extent must contain valid values. If automatic line break is set,
;             only Extent.x is necessary.
;             On exit, IdealDrawExtent is set.

Method TextView.Calc, uses xbx xdi xsi
  local dLineLength:DWORD, dLineAlignment:DWORD, TVTabStop:TVTABSTOP
  local dHangingFlag:DWORD, dLineIndent:DWORD, dAdjacentTextItems:DWORD, dWidth:DWORD
  local dLastAscent:DWORD, dMaxAscent:DWORD, dMaxDescent:DWORD, dMaxHeight:DWORD, dMaxExtLeading:DWORD
  local dCurEntryIdx:DWORD, dLineEntryIdx:DWORD, dLineBegEntryIdx:DWORD, dLineEndEntryIdx:DWORD
  local CurLinePos:POINT, cChars[10]:CHR
  local dBoxed:DWORD, BoxColor:RGBQUAD, hFont:HFONT, TxtNotif:TVNM_TXT, xCtrlID:XWORD

;  local SW:$Obj(StopWatch), cBuffer[1024]:CHR

;  DbgText "TextView.Calc"

  SetObject xsi

;  New SW::StopWatch
;  OCall SW::StopWatch.Init, xsi
;  OCall SW::StopWatch.Start

  mov xCtrlID, $invoke(GetMenu, [xsi].hWnd)

  m2z [xsi].IdealDrawExtent.x
  m2z [xsi].IdealDrawExtent.y

  .ifBitSet [xsi].dOptions, TVO_AUTO_LINEBREAK          ;If TVO_AUTO_LINEBREAK is set, the line width
    mov eax, [xsi].DrawExtent.x                         ;is defined by DrawExtent.x
  .elseIfBitSet [xsi].dFlags, TVIF_EXTENT_X_SET         ;If SIZE_X is used, the line width
    mov eax, [xsi].DrawExtent.x                         ;is defined by DrawExtent.x
  .else
    xor eax, eax
  .endif
  mov [xsi].dAllLinesWidth, eax

  OCall [xsi].LineInfos::DataCollection.DisposeAll
  OCall [xsi].TabStops::SortedDataCollection.DisposeAll

  ;Evaluate the width of all text and blank areas and convert CHAR commands to text
  .for (ebx = 0 : ebx != [xsi].Entries.dCount : ebx++)
    mov xdi, $OCall([xsi].Entries::DataCollection.ItemAt, ebx)
    mov xax, [xdi].TVENTRY.pTag
    mov xcx, TVCTAG_CHAR
    .if xax == xcx
      mov xax, [xdi].TVENTRY.xValue
      .if eax > 0FFFFh                                  ;Character > BMP
        mov edx, eax
        mov cx, ax
        shr edx, 6
        shr cx, 18
        mov dh, al
        and cx, 00000111y
        shr eax, 12
        and edx, 0011111100111111y
        add cx, 11110000y
        add edx, 1000000010000000y
        and eax, 00111111y
        shl edx, 16
        mov dl, cl
        add al, 10000000y
        mov dh, al
        mov DCHRW ptr cChars[0], edx
        m2z CHRW ptr cChars[4]                          ;mov edx, 0D834DD1Eh  mov DCHR ptr cChars[0], edx
        mov [xdi].TVENTRY.dCharCount, 2                 ;m2z CHR ptr cChars[4]
      .else
        mov DCHRW ptr cChars[0], eax
        mov [xdi].TVENTRY.dCharCount, 1
      .endif

      mov [xdi].TVENTRY.pString, $invoke(StrNewW, addr cChars)
      mov [xdi].TVENTRY.dType, TVET_TEXT                ;Mutate from TVET_CMD to TVET_TEXT
      m2z [xdi].TVENTRY.pTag
    .endif

    .if [xdi].TVENTRY.pString != NULL
      mov xax, [xdi].TVENTRY.pStyle
      m2m hFont, [xax].TVSTYLE.hFont, edx

      .ifBitSet [xax].TVSTYLE.dFlags, TVSF_TEXTCALLBACK
        m2m TxtNotif.dID, [xax].TVSTYLE.dTextID, ecx
        OCall [xsi].Entries::DataCollection.IndexOf, xax
        mov TxtNotif.dEntryIndex, eax
        mrm TxtNotif.Header.hwndFrom, [xsi].hWnd, xcx
        m2m TxtNotif.Header.idFrom, xCtrlID, xax
        mov TxtNotif.Header.code, TVNMC_TXT
        lea xax, [xdi].TVENTRY.pString
        mov TxtNotif.ppText, xax
        invoke SendMessage, [xsi].hParent, WM_NOTIFY, xCtrlID, addr TxtNotif
      .endif

      invoke SelectObject, [xsi].hMemDC, hFont
      invoke DrawTextW, [xsi].hMemDC, [xdi].TVENTRY.pString, -1, addr [xdi].TVENTRY.Extent, \
                        DT_CALCRECT or DT_NOPREFIX or DT_SINGLELINE
      mov xax, [xdi].TVENTRY.pStyle
      mov ecx, [xax].TVSTYLE.TextMetric.tmOverhang
      sub [xdi].TVENTRY.Extent.right, ecx
    .endif
  .endfor

  ;Master loop ===============================================================================
  m2z CurLinePos.y
  m2z dCurEntryIdx
  m2z dLineIndent
  mov dLineAlignment, TVALIGN_LEFT
  mov dHangingFlag, FALSE
  mov dBoxed, FALSE
  .while TRUE
    mov edx, dCurEntryIdx
    .break .if edx >= [xsi].Entries.dCount
    mov dLineBegEntryIdx, edx

    ;Start a new line
    m2z dLineLength
    m2z dMaxAscent
    m2z dLastAscent
    m2z dMaxDescent
    m2z dMaxExtLeading
    m2z CurLinePos.x
    m2z dAdjacentTextItems

    ;Get the metric of the current line ——————————————————————————————————————— 
    .while TRUE
      mov edx, dCurEntryIdx
      .break .if edx >= [xsi].Entries.dCount
      mov dLineEndEntryIdx, edx

      mov xdi, $OCall([xsi].Entries::DataCollection.ItemAt, edx)
      mov xax, [xdi].TVENTRY.pTag
      test xax, xax
      jz @@EndHandler
      jmp POINTER ptr [xax].TVCTAG.pCalcHandler

      ; ————————————————————————————————————————————————————————————— 
      ; Routines:   TVCH_xxx
      ; Purpose:    Handler for TextView Commands.
      ; Arguments:  xsi -> TextView
      ;             xdi -> TVENTRY
      ; Note:       ebx can be used in the command routines.
      ;##\

    TVCCH_TAB::
;      DbgText "TAB"

      ;Get current x-Position
      mov ecx, dLineIndent
      add ecx, dLineLength
      ;Scale it using the current zoom factor
      invoke MulDiv, ecx, TVZOOM_BASE, [xsi].dZoomFactor
      ;Search in the TabStop collection
      inc eax                                           ;Search beginning from the next position
      mov TVTabStop.dPosition, eax
      OCall [xsi].TabStops::SortedDataCollection.Search, addr TVTabStop
      .if ecx != [xsi].TabStops.dCount
        mov edx, ecx
        OCall [xsi].TabStops::SortedDataCollection.ItemAt, edx
      .else
        xor eax, eax
      .endif

      .if xax != NULL
        .if [xax].TVTABSTOP.bType == TVTAB_TYPE_LEFT
          invoke MulDiv, [xax].TVTABSTOP.dPosition, [xsi].dZoomFactor, TVZOOM_BASE
          sub eax, dLineLength
          sub eax, dLineIndent
        .else
          mov xbx, xax
          OCall xsi.WidthToNextStop, dCurEntryIdx      ;Returns eax = cummulated width
          .if eax != 0
            mov dWidth, eax
            invoke MulDiv, [xbx].TVTABSTOP.dPosition, [xsi].dZoomFactor, TVZOOM_BASE
            .if [xbx].TVTABSTOP.bType == TVTAB_TYPE_CENTER
              shr dWidth, 1
            .endif
            sub eax, dWidth
            sub eax, dLineIndent
            sub eax, dLineLength
          .endif
        .endif
      .else
        ;Get the size of dTab2Spaces spaces
        mov xax, [xdi].TVENTRY.pStyle
        invoke SelectObject, [xsi].hMemDC, [xax].TVSTYLE.hFont
        invoke DrawTextW, [xsi].hMemDC, $OfsCStr(" "), -1, addr [xdi].TVENTRY.Extent, \
                          DT_CALCRECT or DT_NOPREFIX or DT_SINGLELINE
        mov xdx, [xdi].TVENTRY.pStyle
        mov eax, [xdi].TVENTRY.Extent.right
        sub eax, [xdx].TVSTYLE.TextMetric.tmOverhang
        imul eax, [xsi].dTab2Spaces
      .endif
      mov [xdi].TVENTRY.Extent.right, eax
      jmp @@EndHandler

    TVCCH_TABL::
;      DbgText "TABL"
      MemAlloc sizeof(TVTABSTOP)
      m2m [xax].TVTABSTOP.dPosition, DWORD ptr [xdi].TVENTRY.xValue, ecx
      mov [xax].TVTABSTOP.bType, TVTAB_TYPE_LEFT
      OCall [xsi].$Obj(TextView).TabStops::DataCollection.Insert, xax
      jmp @@EndHandler

    TVCCH_TABC::
;      DbgText "TABC"
      MemAlloc sizeof(TVTABSTOP)
      m2m [xax].TVTABSTOP.dPosition, DWORD ptr [xdi].TVENTRY.xValue, ecx
      mov [xax].TVTABSTOP.bType, TVTAB_TYPE_CENTER
      OCall [xsi].$Obj(TextView).TabStops::DataCollection.Insert, xax
      jmp @@EndHandler

    TVCCH_TABR::
;      DbgText "TABR"
      MemAlloc sizeof(TVTABSTOP)
      m2m [xax].TVTABSTOP.dPosition, DWORD ptr [xdi].TVENTRY.xValue, ecx
      mov [xax].TVTABSTOP.bType, TVTAB_TYPE_RIGHT
      OCall [xsi].TabStops::DataCollection.Insert, xax
      jmp @@EndHandler

    TVCCH_TABCLR::
;      DbgText "TABCLR"
      OCall [xsi].TabStops::DataCollection.DisposeAll
      jmp @@EndHandler

    TVCCH_LINE::
    TVCCH_PARA::
    TVCCH_BREAK::
;      DbgText "BREAK"
      mov xcx, [xdi].TVENTRY.pStyle
      mov dMaxAscent, $uMax(dMaxAscent, [xcx].TVSTYLE.TextMetric.tmAscent, eax)
      mov dMaxDescent, $uMax(dMaxDescent, [xcx].TVSTYLE.TextMetric.tmDescent, eax)
      mov dMaxExtLeading, $uMax(dMaxExtLeading, [xcx].TVSTYLE.TextMetric.tmExternalLeading, eax)
      add dCurEntryIdx, 1
      mov dHangingFlag, FALSE
      .break                                            ;Exit line

    TVCCH_CHAR::
    TVCCH_COVER::                                       ;Evaluated in Draw method
    TVCCH_DRAW::                                        ;Evaluated in Draw method

      ;##/
      ; ————————————————————————————————————————————————————————————— 
@@EndHandler:

      mov xcx, [xdi].TVENTRY.pStyle
      .ifBitSet [xcx].TVSTYLE.dFlags, TVSF_BOX          ;Remember this flag. It can be set anywhere
        add dBoxed, 1                                   ;in the current line.
        m2m BoxColor, [xcx].TVSTYLE.BoxColor, edx       ;Remember also the last box color
      .endif

      .if [xdi].TVENTRY.dType == TVET_TEXT
        add dAdjacentTextItems, 1                       ;Keep track of adjacent text entries
      .endif

      mov xcx, [xdi].TVENTRY.pStyle
      .if [xdi].TVENTRY.dType != TVET_CMD
        mov dMaxAscent, $uMax(dMaxAscent, [xcx].TVSTYLE.TextMetric.tmAscent, eax)
        mov dMaxDescent, $uMax(dMaxDescent, [xcx].TVSTYLE.TextMetric.tmDescent, eax)
        mov dMaxExtLeading, $uMax(dMaxExtLeading, [xcx].TVSTYLE.TextMetric.tmExternalLeading, eax)
        m2m dLineAlignment, [xcx].TVSTYLE.dAlignment, eax   ;;Remember also the last alignment
      .endif

      .if dHangingFlag != FALSE
        mov ecx, [xcx].TVSTYLE.dHanging
      .else
        mov ecx, [xcx].TVSTYLE.dIndent
      .endif
      invoke MulDiv, ecx, [xsi].dZoomFactor, TVZOOM_BASE
      mov dLineIndent, eax

      mov xcx, [xdi].TVENTRY.pStyle
      mov eax, [xdi].TVENTRY.Extent.right               ;Entry length
      .ifBitSet [xsi].dOptions, TVO_AUTO_LINEBREAK
        .if [xdi].TVENTRY.dType != TVET_CMD
          mov edx, dLineLength
          .if edx != 0                                  ;We have at least one visible area drawn
            add edx, dLineIndent
            add edx, eax
            add edx, [xcx].TVSTYLE.TextMetric.tmOverhang  ;Overhang of the last TVArea
            .if edx > [xsi].dAllLinesWidth
              mov dHangingFlag, TRUE                    ;Activate Hanging for the next line
              .if [xdi].TVENTRY.dType == TVET_TEXT
                mov ecx, dAdjacentTextItems
                mov edx, dLineEndEntryIdx
                sub edx, ecx
                .if edx > dLineBegEntryIdx
                  sub dLineEndEntryIdx, ecx
                  add dCurEntryIdx, 1
                  sub dCurEntryIdx, ecx
                .else
                  add dLineLength, eax
                  add dCurEntryIdx, ecx
                .endif
              .else
                add dLineLength, eax
                add dCurEntryIdx, 1
              .endif
              .break                                    ;Exit Line loop

            .endif
          .endif
        .endif
      .endif

      add dLineLength, eax
      add dCurEntryIdx, 1

      .if [xdi].TVENTRY.dType == TVET_BLANK
        mov dAdjacentTextItems, 0                       ;Reset dAdjacentTextItems
      .endif

    .endw
    ;End line metric analysis ————————————————————————————————————————————————— 

    ;Update IdealDrawExtent.x
    .ifBitClr [xsi].dOptions, TVO_AUTO_LINEBREAK
      mov edx, dLineLength
      add edx, dLineIndent
      .if [xsi].IdealDrawExtent.x < edx
        mov [xsi].IdealDrawExtent.x, edx
      .endif
    .endif

    ;Update [xsi].dAllLinesWidth
    .ifBitClr [xsi].dFlags, TVIF_EXTENT_X_SET
      mov edx, dLineLength
      add edx, dLineIndent
      .if [xsi].dAllLinesWidth < edx
        mov [xsi].dAllLinesWidth, edx
      .endif
    .endif

    ;Calculate dMaxHeight for the current line
    mov eax, dMaxAscent
    add eax, dMaxDescent
    mov dMaxHeight, eax

    ;Save tha data we have so far
    MemAlloc sizeof(TVLINE_INFO), MEM_INIT_ZERO
    OCall [xsi].LineInfos::DataCollection.Insert, xax
    m2m [xax].TVLINE_INFO.Position.x, dLineIndent, edx
    m2m [xax].TVLINE_INFO.Position.y, CurLinePos.y, ecx
    m2m [xax].TVLINE_INFO.dLength, dLineLength, edx
    m2m [xax].TVLINE_INFO.dHeight, dMaxHeight, ecx
    m2m [xax].TVLINE_INFO.dBegEntryIdx, dLineBegEntryIdx, edx
    m2m [xax].TVLINE_INFO.dEndEntryIdx, dLineEndEntryIdx, ecx
    m2m [xax].TVLINE_INFO.dAlignment, dLineAlignment, edx
    m2m [xax].TVLINE_INFO.dBoxed, dBoxed, ecx
    m2m [xax].TVLINE_INFO.BoxColor, BoxColor, edx
    m2m [xax].TVLINE_INFO.dMaxAscent, dMaxAscent, ecx
    m2m [xax].TVLINE_INFO.dLastAscent, dLastAscent, edx
    m2m [xax].TVLINE_INFO.dMaxDescent, dMaxDescent, ecx
    m2m [xax].TVLINE_INFO.dMaxExtLeading, dMaxExtLeading, edx

    mov dBoxed, 0

    mov xax, [xdi].TVENTRY.pTag
    mov xcx, TVCTAG_PARA
    mov xdx, TVCTAG_PARA_S
    .if xax == xcx || xax == xdx
      mov edx, dMaxHeight
      mov ecx, CurLinePos.y
      shr edx, 1                                        ;Half line height
      add ecx, edx
      mov CurLinePos.y, ecx
    .endif

    ;Prepare for next line
    mov edx, dMaxHeight
    add edx, dMaxExtLeading
    add CurLinePos.y, edx                               ;Set new y position
    m2z CurLinePos.x                                    ;Reset Line position

    add dLineEntryIdx, 1
  .endw

  m2m [xsi].IdealDrawExtent.y, CurLinePos.y, edx

;  OCall SW::StopWatch.Stop
;  OCall SW::StopWatch.GetTimeStr, addr cBuffer
;  DbgStr cBuffer, "Calc"

  mov eax, TRUE
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     TextView.Dispatch
; Purpose:    Dispatching of window messages.
; Arguments:  Arg1: Window handle.
;             Arg2: Message identifier.
;             Arg3: First message parameter.
;             Arg4: Second message parameter.
; Return:     eax = This value is the result of the message processing and depends on the message.

Method TextView.Dispatch, uses xsi, hWnd:HWND, uMsg:DWORD, wParam:WPARAM, lParam:LPARAM
;  DbgMessage uMsg
  SetObject xsi
  DispatchEvent <DefWindowProc, hWnd>                   ;xsi -> Object instance
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     TextView.Done
; Purpose:    Finalize the Button object.
; Arguments:  None.
; Return:     Nothing.

Method TextView.Done, uses xsi
  SetObject xsi
  invoke DestroyWindow, [xsi].hWnd
  ACall xsi.Done
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     TextView.Draw
; Purpose:    Draw the parsed text onto the MemDC.
; Arguments:  None.
; Return:     eax = TRUE if succeeded, otherwise FALSE.

Method TextView.Draw, uses xbx xdi xsi
  local xCtrlID:XWORD, pLineInfo:PTVLINE_INFO, TxtNotif:TVNM_TXT
  local dBoxed:DWORD, hBoxBrush:HBRUSH
  local dLineIdx:DWORD, CurLinePos:POINT, NewLinePos:POINT
  local DrawRect:RECT, OutRect:RECT, BoxRect:RECT
  local dCurEntryIdx:DWORD, dLineBegEntryIdx:DWORD, dLineEndEntryIdx:DWORD
  local DrawNotification:TVNM_DRAW
  local dLineEntryIdx:DWORD, dLineAlignment:DWORD
  local dLineIndent:DWORD, dLineLength:DWORD, dMaxExtLeading:DWORD
  local dMaxAscent:DWORD, dLastAscent:DWORD, dMaxDescent:DWORD, dLastDescent:DWORD

;  local SW:$Obj(StopWatch), cBuffer[1024]:CHR

;  DbgText "TextView.Draw"
  SetObject xsi

;  New SW::StopWatch
;  OCall SW::StopWatch.Init, xsi
;  OCall SW::StopWatch.Start

  mov xCtrlID, $invoke(GetMenu, [xsi].hWnd)
  OCall [xsi].CoverTasks::DataCollection.DisposeAll
  OCall [xsi].ActiveAreas::XWCollection.DeleteAll
  OCall [xsi].InfoAreas::XWCollection.DeleteAll

  mov dLineIdx, 0
  .while TRUE
    mov edx, dLineIdx
    .break .if edx >= [xsi].LineInfos.dCount
    OCall [xsi].LineInfos::DataCollection.ItemAt, dLineIdx
    m2m dLineBegEntryIdx, [xax].TVLINE_INFO.dBegEntryIdx, ecx
    m2m dLineEndEntryIdx, [xax].TVLINE_INFO.dEndEntryIdx, edx
    m2m dLineAlignment, [xax].TVLINE_INFO.dAlignment, ecx
    m2m dLineIndent, [xax].TVLINE_INFO.Position.x, edx
    m2m dLineLength, [xax].TVLINE_INFO.dLength, ecx
    m2m dMaxAscent, [xax].TVLINE_INFO.dMaxAscent, ecx
    m2m dLastAscent, [xax].TVLINE_INFO.dLastAscent, edx
    m2m dMaxDescent, [xax].TVLINE_INFO.dMaxDescent, ecx
    m2m dMaxExtLeading, [xax].TVLINE_INFO.dMaxExtLeading, edx

    ;Calculate alignment and fill the gap on the front, including the indent
    .if dLineAlignment == TVALIGN_RIGHT
      mov ecx, [xsi].dAllLinesWidth
      sub ecx, dLineIndent
      sub ecx, dLineLength
    .elseif dLineAlignment == TVALIGN_CENTER
      mov ecx, [xsi].dAllLinesWidth
      sub ecx, dLineIndent
      sub ecx, dLineLength
      sar ecx, 1
    .else
      xor ecx, ecx
    .endif

    m2m CurLinePos.y, [xax].TVLINE_INFO.Position.y, edx
    mov edx, [xax].TVLINE_INFO.Position.x
    .if SDWORD ptr ecx > 0
      add edx, ecx
    .endif
    mov CurLinePos.x, edx

    m2m dLineEntryIdx, dLineBegEntryIdx, edx
    .while TRUE
      mov edx, dLineEntryIdx
      .break .if edx > dLineEndEntryIdx

      mov xdi, $OCall([xsi].Entries::DataCollection.ItemAt, edx)

      mov xbx, [xdi].TVENTRY.pStyle                     ;xbx -> TVSTYLE
      .if [xdi].TVENTRY.pString != NULL
        mrm [xdi].TVENTRY.Area.left, CurLinePos.x, edx
        add edx, [xdi].TVENTRY.Extent.right
        mov ecx, [xsi].dAllLinesWidth
        add ecx, [xsi].Padding.left
        .if edx > ecx
          mov edx, ecx
        .endif
        mov [xdi].TVENTRY.Area.right, edx
        mov NewLinePos.x, edx

        .ifBitSet [xbx].TVSTYLE.dFlags, TVSF_SUP
          ;[SUP] text
          mov edx, CurLinePos.y
          add edx, dMaxAscent
          sub edx, dLastAscent
          mov [xdi].TVENTRY.Area.top, edx
          add edx, [xbx].TVSTYLE.TextMetric.tmHeight
          mov [xdi].TVENTRY.Area.bottom, edx
        .elseIfBitSet [xbx].TVSTYLE.dFlags, TVSF_SUB
          ;[SUB] text
          mov edx, CurLinePos.y
          add edx, dMaxAscent
          add edx, dLastDescent
          mov [xdi].TVENTRY.Area.bottom, edx
          sub edx, [xbx].TVSTYLE.TextMetric.tmHeight
          mov [xdi].TVENTRY.Area.top, edx
        .else
          ;Regular text
          mov eax, dMaxAscent
          mrm dLastAscent, [xbx].TVSTYLE.TextMetric.tmAscent, ecx   ;Remember this value
          sub eax, ecx                                  ;Y offset
          mrm dLastDescent, [xbx].TVSTYLE.TextMetric.tmDescent, ecx ;Remember this value
          mov edx, CurLinePos.y
          add edx, eax
          mov [xdi].TVENTRY.Area.top, edx
          add edx, [xbx].TVSTYLE.TextMetric.tmHeight
          mov [xdi].TVENTRY.Area.bottom, edx
        .endif

        m2m CurLinePos.x, NewLinePos.x, ecx
      .else
        .if [xdi].TVENTRY.Extent.right != 0
          ;{TAB}
          mov edx, [xdi].TVENTRY.Extent.right
          add CurLinePos.x, edx
        .endif
      .endif
      inc dLineEntryIdx
    .endw
    inc dLineIdx
  .endw

  mov DrawRect.left, 0
  mov DrawRect.top, 0
  mov edx, [xsi].DrawExtent.x
  mov eax, [xsi].DrawExtent.y
  mov DrawRect.right, edx
  mov DrawRect.bottom, eax

  ;Never create a zero sized bitmap
  .if edx == 0
    inc edx
  .endif
  .if eax == 0
    inc eax
  .endif
  mov [xsi].hMemBmp, $invoke(CreateCompatibleBitmap, [xsi].hMemDC, edx, eax)
  invoke DeleteObject, $invoke(SelectObject, [xsi].hMemDC, xax)

  m2z OutRect.left
  m2z OutRect.top
  s2s POINT ptr OutRect.right, [xsi].DrawExtent, xax, xcx, xmm0, xmm1

  invoke FillRect, [xsi].hMemDC, addr OutRect, [xsi].hCanvasBrush

  ;Main loop ==================================================================
  m2z dLineIdx
  .while TRUE
    mov edx, dLineIdx
    .break .if edx >= [xsi].LineInfos.dCount

    ;Start a new line
    mov pLineInfo, $OCall([xsi].LineInfos::DataCollection.ItemAt, dLineIdx)
    mrm dLineBegEntryIdx, [xax].TVLINE_INFO.dBegEntryIdx, edx
    m2m dLineEndEntryIdx, [xax].TVLINE_INFO.dEndEntryIdx, ecx
    mov dCurEntryIdx, edx
    s2s CurLinePos, [xax].TVLINE_INFO.Position, xcx, xdx, xmm0, xmm1, xmm2

    .if [xax].TVLINE_INFO.dBoxed != 0
      m2z BoxRect.left
      mrm BoxRect.top, CurLinePos.y, edx
      m2m BoxRect.right, [xsi].DrawExtent.x, ecx
      add edx, [xax].TVLINE_INFO.dHeight
      mov BoxRect.bottom, edx
      mov hBoxBrush, $invoke(CreateSolidBrush, [xax].TVLINE_INFO.BoxColor)
      invoke IntersectRect, addr OutRect, addr DrawRect, addr BoxRect
      invoke FillRect, [xsi].hMemDC, addr OutRect, hBoxBrush
      invoke DeleteObject, hBoxBrush
    .endif

    ;Line loop ================================================================
    .while TRUE
      mov eax, dCurEntryIdx
      .break .if eax > dLineEndEntryIdx
      mov xdi, $OCall([xsi].Entries::DataCollection.ItemAt, dCurEntryIdx)
      mov xax, [xdi].TVENTRY.pTag
      test xax, xax
      jz @@EndHandler
      jmp POINTER ptr [xax].TVCTAG.pDrawHandler

      ; ————————————————————————————————————————————————————————————— 
      ; Routines:   TVCH_xxx
      ; Purpose:    Handler for TextView Commands.
      ; Arguments:  xsi -> TextView
      ;             xdi -> TVENTRY
      ; Note:       ebx can be used in the command routines.
      ;##\

    TVCDH_DRAW::
;      DbgText "BACKDRAW"
      mov DrawNotification.Header.code, TVNMC_DRAW
      m2m DrawNotification.Header.hwndFrom, [xsi].hWnd, xcx
      invoke GetMenu, [xsi].hWnd
      mov DrawNotification.Header.idFrom, xax
      m2m DrawNotification.dID, DWORD ptr [xdi].TVENTRY.xValue, edx
      m2m DrawNotification.hDC, [xsi].hMemDC, xcx
      s2s DrawNotification.Position, CurLinePos, xcx, xdx, xmm0, xmm1, xmm2, xmm3
      mov xax, pLineInfo
      m2m DrawNotification.dLineHeight, [xax].TVLINE_INFO.dHeight, xdx
      s2s DrawNotification.Extent, [xsi].Extent, xcx, xdx, xmm0, xmm1, xmm2, xmm3
      s2s DrawNotification.Padding, [xsi].Padding, xcx, xdx, xmm0, xmm1, xmm2, xmm3
      m2m DrawNotification.pStyle, [xdi].TVENTRY.pStyle, xcx
      m2m DrawNotification.dZoomFactor, [xsi].dZoomFactor, xcx
      invoke SendMessage, [xsi].hParent, WM_NOTIFY, xCtrlID, addr DrawNotification
      jmp @@EndHandler

    TVCDH_LINE::
;      DbgText "LINE"
      mov xax, [xdi].TVENTRY.pStyle
      mov ecx, [xax].TVSTYLE.TextMetric.tmHeight
      mov ebx, ecx
      shr ebx, 1
      add ebx, CurLinePos.y
      add ecx, [xax].TVSTYLE.TextMetric.tmExternalLeading
      add CurLinePos.y, ecx

      mov eax, [xsi].Extent.y
      .if eax > ebx
        invoke MoveToEx, [xsi].hMemDC, CurLinePos.x, ebx, NULL
        invoke LineTo, [xsi].hMemDC, [xsi].DrawExtent.x, ebx
      .endif
      jmp @@EndHandler

    TVCDH_COVER::
;      DbgText "FOREDRAW"
      MemAlloc sizeof(TVNM_DRAW)
      mov [xax].TVNM_DRAW.Header.code, TVNMC_DRAW
      m2m [xax].TVNM_DRAW.Header.hwndFrom, [xsi].hWnd, xdx
      m2m [xax].TVNM_DRAW.Header.idFrom, xCtrlID, xcx
      m2m [xax].TVNM_DRAW.dID, DWORD ptr [xdi].TVENTRY.xValue, edx
      m2m [xax].TVNM_DRAW.hDC, [xsi].hMemDC, xcx
      s2s [xax].TVNM_DRAW.Position, CurLinePos, xcx, xdx, xmm0
      mov xcx, pLineInfo
      m2m [xax].TVNM_DRAW.dLineHeight, [xcx].TVLINE_INFO.dHeight, xdx
      s2s [xax].TVNM_DRAW.Extent, [xsi].Extent, xcx, xdx, xmm0
      s2s [xax].TVNM_DRAW.Padding, [xsi].Padding, xcx, xdx, xmm0
      m2m [xax].TVNM_DRAW.pStyle, [xdi].TVENTRY.pStyle, xcx
      m2m [xax].TVNM_DRAW.dZoomFactor, [xsi].dZoomFactor, xcx
      OCall [xsi].CoverTasks::DataCollection.Insert, xax
      jmp @@EndHandler

    TVCDH_PARA::
    TVCDH_BREAK::
    TVCDH_CHAR::
    TVCDH_TAB::
    TVCDH_TABL::
    TVCDH_TABC::
    TVCDH_TABR::
    TVCDH_TABCLR::
      ;##/
      ; ————————————————————————————————————————————————————————————— 
@@EndHandler:

      mov xbx, [xdi].TVENTRY.pStyle                    ;xbx -> TVSTYLE
      .if [xdi].TVENTRY.pString != NULL
        invoke SetTextColor, [xsi].hMemDC, [xbx].TVSTYLE.TextColor
        invoke SelectObject, [xsi].hMemDC,  [xbx].TVSTYLE.hFont

        invoke IntersectRect, addr OutRect, addr DrawRect, addr [xdi].TVENTRY.Area
        ;If the style background color is not the default color, then draw a new background
        mov ecx, [xbx].TVSTYLE.BackColor
        .if ecx != [xsi].DefaultBackColor
          invoke FillRect, [xsi].hMemDC, addr OutRect, [xbx].TVSTYLE.hBackBrush
        .endif

        .ifBitSet [xbx].TVSTYLE.dFlags, TVSF_TEXTCALLBACK
          m2m TxtNotif.dID, [xbx].TVSTYLE.dTextID, ecx
          OCall [xsi].Entries::DataCollection.IndexOf, xax
          mov TxtNotif.dEntryIndex, eax
          mrm TxtNotif.Header.hwndFrom, [xsi].hWnd, xcx
          m2m TxtNotif.Header.idFrom, xCtrlID, xax
          mov TxtNotif.Header.code, TVNMC_TXT
          lea xax, [xdi].TVENTRY.pString
          mov TxtNotif.ppText, xax
          invoke SendMessage, [xsi].hParent, WM_NOTIFY, xCtrlID, addr TxtNotif

          mov xcx, [xdi].TVENTRY.pString
        .endif

;        invoke Rectangle, [xsi].hMemDC, [xdi].TVENTRY.Area.left, [xdi].TVENTRY.Area.top, \
;                                        [xdi].TVENTRY.Area.right, [xdi].TVENTRY.Area.bottom
        invoke DrawTextW, [xsi].hMemDC, [xdi].TVENTRY.pString, -1, addr OutRect, \
                          DT_NOPREFIX or DT_SINGLELINE
        .ifBitSet [xbx].TVSTYLE.dFlags, TVSF_ACTIVE
          ;Uncomment to show the active area
;          invoke Rectangle, [xsi].hMemDC, [xdi].TVENTRY.Area.left, [xdi].TVENTRY.Area.top, \
;                                          [xdi].TVENTRY.Area.right, [xdi].TVENTRY.Area.bottom
          OCall [xsi].ActiveAreas::XWCollection.Insert, xdi
          mov eax, [xbx].TVSTYLE.dID
          mov [xdi].TVENTRY.xValue, xax
        .endif

        .ifBitSet [xbx].TVSTYLE.dFlags, TVSF_TIP
          ;Uncomment to show the info area
;          invoke Rectangle, [xsi].hMemDC, [xdi].TVENTRY.Area.left, [xdi].TVENTRY.Area.top, \
;                                          [xdi].TVENTRY.Area.right, [xdi].TVENTRY.Area.bottom
          OCall [xsi].InfoAreas::XWCollection.Insert, xdi
          mov eax, [xbx].TVSTYLE.dID
          mov [xdi].TVENTRY.xValue, xax
        .endif

        m2m CurLinePos.x, NewLinePos.x, ecx
      .else
        mov ecx, [xdi].TVENTRY.Extent.right
        .if ecx != 0
          ;{TAB}
          mov edx, [xdi].TVENTRY.Extent.right
          add CurLinePos.x, edx
        .endif
      .endif
      add dCurEntryIdx, 1
    .endw
    add dLineIdx, 1
  .endw

  ;Final step: call all parent foreground drawing tasks on the just drawn TextView background
  .for (ebx = 0 : ebx != [xsi].CoverTasks.dCount : ebx++)
    OCall [xsi].CoverTasks::DataCollection.ItemAt, ebx
    invoke SendMessage, [xsi].hParent, WM_NOTIFY, xCtrlID, xax
  .endfor

;  OCall SW::StopWatch.Stop
;  OCall SW::StopWatch.GetTimeStr, addr cBuffer
;  DbgStr cBuffer, "Draw"

  mov eax, TRUE
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     TextView.GetEntryFrom
; Purpose:    Return the TVENTRY under the mouse pointer.
; Arguments:  Arg1: -> Collection (ActiveAreas or InfoAreas)
;             Arg2: -> POINT (mouse coordinates in client space).
; Return:     xax -> TVENTRY or NULL.

Method TextView.GetEntryFrom, uses xbx xdi xsi, pCollection:$ObjPtr(XWCollection), Point:POINTS
  local MouseClientPos:POINT

  SetObject xsi
  PntS2Pnt MouseClientPos, Point                        ;Uses eax
  mov ecx, MouseClientPos.x
  .if SDWORD ptr ecx >= [xsi].Padding.left
    mov eax, [xsi].ClientRect.right
    sub eax, [xsi].Padding.left
    .if SDWORD ptr ecx < eax
      mov edx, MouseClientPos.y
      .if SDWORD ptr edx >= [xsi].Padding.top
        mov eax, [xsi].ClientRect.bottom
        sub eax, [xsi].Padding.top
        .if SDWORD ptr edx < eax
          sub ecx, [xsi].Padding.left
          sub edx, [xsi].Padding.top
          add ecx, [xsi].Origin.x
          add edx, [xsi].Origin.y
          mov MouseClientPos.x, ecx
          mov MouseClientPos.y, edx
          xor eax, eax
          xor ebx, ebx
          ReleaseObject
          mov xsi, pCollection

          .while ebx != [xsi].$Obj(XWCollection).dCount
            mov xdi, $OCall(pCollection::XWCollection.ItemAt, ebx)
            invoke PtInRect, addr [xax].TVENTRY.Area, MouseClientPos
            test eax, eax
            mov xax, xdi
            jnz @@EOM                                   ;Return -> TVENTRY
            inc ebx
          .endw
        .endif
      .endif
    .endif
  .endif
  xor eax, eax                                          ;Return NULL
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     TextView.Init
; Purpose:    Initialize the TextView object.
; Arguments:  Arg1: -> Owner object.
;             Arg2: Parent window HANDLE.
;             Arg3: -> Definition structure.
; Return:     Nothing.

Method TextView.Init, uses xbx xsi, pOwner:POINTER, hParent:HWND, pDefStruc:PDEF_TEXTVIEW
;  DbgText "TextView.Init"
  SetObject xsi
  m2m [xsi].hParent, hParent, xax
  mov xbx, pDefStruc
  assume xbx:PDEF_TEXTVIEW
  mov eax, [xbx].dStyle
  or eax, WS_CHILD or WS_VISIBLE
  %invoke CreateWindowEx, [xbx].dExStyle, offset cTextViewClass&TARGET_STR_AFFIX, [xbx].pText, \
                         eax, [xbx].sdPosX, [xbx].sdPosY, [xbx].dWidth, [xbx].dHeight, \
                         hParent, [xbx].xCtlID, hInstance, pSelf
  assume xbx:NOTHING
  ACall xsi.Init, pOwner, xax
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     TextView.OnButtonDown
; Purpose:    Event procedure for WM_XBUTTONDOWN message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero.
; Link:       https://docs.microsoft.com/en-us/windows/win32/tablet/system-events-and-mouse-messages

Method TextView.OnButtonDown, uses xsi, wParam:WPARAM, lParam:LPARAM
  local AppNotif:TVNM_APP, xCtrlID:XWORD

;  DbgText "TextView.OnButtonDown"
  SetObject xsi
  mov xax, lParam
  lea xdx, [xsi].ActiveAreas
  OCall xsi.GetEntryFrom, xdx, eax
  .if xax != NULL
    mov xcx, [xax].TVENTRY.pStyle
    m2m AppNotif.dID, [xcx].TVSTYLE.dID, edx
    OCall [xsi].Entries::DataCollection.IndexOf, xax
    mov AppNotif.dEntryIndex, eax
    mrm AppNotif.Header.hwndFrom, [xsi].hWnd, xcx
    mov xCtrlID, $invoke(GetMenu, xcx)
    m2m AppNotif.Header.idFrom, xCtrlID, xax
    mov AppNotif.Header.code, TVNMC_APP_MOUSEDOWN
    mov xax, wParam
    mov AppNotif.dButton, eax
    invoke SendMessage, [xsi].hParent, WM_NOTIFY, xCtrlID, addr AppNotif
  .endif
  xor eax, eax
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     TextView.OnButtonUp
; Purpose:    Event procedure for WM_XBUTTONUP message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero.

Method TextView.OnButtonUp, uses xsi, wParam:WPARAM, lParam:LPARAM
  local AppNotif:TVNM_APP, xCtrlID:XWORD

;  DbgText "TextView.OnButtonUp"
  SetObject xsi
  mov xax, lParam
  lea xdx, [xsi].ActiveAreas
  OCall xsi.GetEntryFrom, xdx, eax
  .if xax != NULL
    m2m AppNotif.dID, DWORD ptr [xax].TVENTRY.xValue, ecx
    OCall [xsi].Entries::DataCollection.IndexOf, xax
    mov AppNotif.dEntryIndex, eax
    mrm AppNotif.Header.hwndFrom, [xsi].hWnd, xcx
    mov xCtrlID, $invoke(GetMenu, xcx)
    m2m AppNotif.Header.idFrom, xCtrlID, xax
    mov AppNotif.Header.code, TVNMC_APP_MOUSEUP
    mov xax, wParam
    mov AppNotif.dButton, eax
    invoke SendMessage, [xsi].hParent, WM_NOTIFY, xCtrlID, addr AppNotif
  .endif
  xor eax, eax
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     TextView.OnCommand
; Purpose:    Event procedure for WM_COMMAND message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero.

Method TextView.OnCommand, uses xsi, wParam:WPARAM, lParam:LPARAM
  SetObject xsi
  ;If we recieve WM_COMMANDs from a child window, replay them to the parent.
  ;eax = message ID
;  DbgHex eax, "MsgID", "Messages"
;  .if eax == WM_COMMAND
;    mov xdx, wParam
;    DbgHex dx
;    shr edx, 16
;    DbgHex dx
;    DbgHex lParam
;  .endif
  invoke SendMessage, [xsi].hParent, eax, wParam, lParam
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     TextView.OnCreate
; Purpose:    Event procedure for WM_CREATE message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero.

Method TextView.OnCreate, uses xsi, wParam:WPARAM, lParam:LPARAM
  local hDC:HDC, dStrSize:DWORD, ToolInfo:TOOLINFO, GestConf[5]:GESTURECONFIG

;  DbgText "TextView.OnCreate"

  SetObject xsi

  ;Get the markuptext
  invoke GetWindowTextLength, [xsi].hWnd                ;Does not include the ZTC
  add eax, 1                                            ;Include ZTC
  mov dStrSize, eax
  mov [xsi].pMarkupText, $invoke(StrAlloc, eax)
  invoke GetWindowText, [xsi].hWnd, xax, dStrSize       ;dStrSize must include the ZTC

  ;Initialize and customize collections
  OCall [xsi].Entries::DataCollection.Init, xsi, 10, 10, COL_MAX_CAPACITY
  OCall [xsi].Styles::DataCollection.Init, xsi, 10, 10, COL_MAX_CAPACITY
  OCall [xsi].StyleStack::XWCollection.Init, xsi, 10, 10, COL_MAX_CAPACITY
  OCall [xsi].ActiveAreas::XWCollection.Init, xsi, 10, 10, COL_MAX_CAPACITY
  OCall [xsi].InfoAreas::XWCollection.Init, xsi, 10, 10, COL_MAX_CAPACITY
  OCall [xsi].TabStops::DataCollection.Init, xsi, 10, 10, COL_MAX_CAPACITY
  OCall [xsi].GdiObjects::XWCollection.Init, xsi, 10, 10, COL_MAX_CAPACITY
  OCall [xsi].CoverTasks::DataCollection.Init, xsi, 10, 10, COL_MAX_CAPACITY
  OCall [xsi].LineInfos::DataCollection.Init, xsi, 10, 10, COL_MAX_CAPACITY
  Override [xsi].GdiObjects::XWCollection.DestroyItem, GdiObjects.DestroyItem
  Override [xsi].Entries::DataCollection.DestroyItem, Entries.DestroyItem
  Override [xsi].TabStops::SortedDataCollection.Compare, TabStops.Compare

  ;Setup internal variables
  mov [xsi].pDefaultFontFace, $invoke(StrNew, $OfsCStr("Segoe UI"))

  ;Create memory resources
  mov hDC, $invoke(GetDC, [xsi].hParent)
  mov [xsi].hMemDC, $invoke(CreateCompatibleDC, hDC)
  invoke SetBkMode, [xsi].hMemDC, TRANSPARENT
  mov [xsi].hMemBmp, $invoke(CreateCompatibleBitmap, hDC, 1, 1)     ;Create a minimal Bitmap
  invoke ReleaseDC, [xsi].hParent, hDC
  mov [xsi].hPrvBmp, $invoke(SelectObject, [xsi].hMemDC, [xsi].hMemBmp)
  mov [xsi].hPrvFont, $invoke(GetCurrentObject, [xsi].hMemDC, OBJ_FONT)
  mov [xsi].hPrvBrush, $invoke(GetCurrentObject, [xsi].hMemDC, OBJ_BRUSH)
  mov [xsi].dLogPixY, $32($invoke(GetDeviceCaps, [xsi].hMemDC, LOGPIXELSY))

  ;Create a ToolTip window to display popup information when hoovering over an TIP area
  invoke CreateWindowEx, WS_EX_TOPMOST, $OfsCStr("tooltips_class32"), NULL, \
                         WS_POPUP or TTS_NOPREFIX or TTS_ALWAYSTIP, \
                         CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, \
                         [xsi].hWnd, 0, hInstance, NULL
  mov [xsi].hToolTip, xax
  invoke SendMessage, [xsi].hToolTip, TTM_ACTIVATE, FALSE, 0
  BitClr [xsi].dFlags, TVIF_TOOLTIP_ACTIVE
  invoke SetWindowPos, [xsi].hToolTip, HWND_TOPMOST, 0, 0, 0, 0, \
                       SWP_NOMOVE or SWP_NOSIZE or SWP_NOACTIVATE
  invoke SendMessage, [xsi].hToolTip, TTM_SETMAXTIPWIDTH, 0, 500    ;Set max width to
                                                                    ;enable line breaks
  mov ToolInfo.cbSize, sizeof(ToolInfo)
  mov ToolInfo.uFlags, TTF_SUBCLASS or TTF_IDISHWND
  mrm ToolInfo.hwnd, [xsi].hWnd, xax
  mov ToolInfo.uId, xax
  mov ToolInfo.hinst, 0
  mov ToolInfo.lpszText, NULL
  mov ToolInfo.lParam, 0
  invoke SendMessage, [xsi].hToolTip, TTM_ADDTOOL, 0, addr ToolInfo ;Associate the tooltip

  ;Configure gesture messages
  lea xax, GestConf
  mov [xax].GESTURECONFIG.dwID, GID_ZOOM
  mov [xax].GESTURECONFIG.dwWant, GC_ZOOM
  mov [xax].GESTURECONFIG.dwBlock, 0
  add xax, sizeof GESTURECONFIG
  mov [xax].GESTURECONFIG.dwID, GID_PAN
  mov [xax].GESTURECONFIG.dwWant, GC_PAN_WITH_SINGLE_FINGER_VERTICALLY or \
                                  GC_PAN_WITH_SINGLE_FINGER_HORIZONTALLY or GC_PAN_WITH_INERTIA
  mov [xax].GESTURECONFIG.dwBlock, GC_PAN_WITH_GUTTER
  add xax, sizeof GESTURECONFIG
  mov [xax].GESTURECONFIG.dwID, GID_ROTATE
  mov [xax].GESTURECONFIG.dwWant, 0
  mov [xax].GESTURECONFIG.dwBlock, GC_ROTATE
  add xax, sizeof GESTURECONFIG
  mov [xax].GESTURECONFIG.dwID, GID_TWOFINGERTAP
  mov [xax].GESTURECONFIG.dwWant, 0
  mov [xax].GESTURECONFIG.dwBlock, GC_TWOFINGERTAP
  add xax, sizeof GESTURECONFIG
  mov [xax].GESTURECONFIG.dwID, GID_PRESSANDTAP
  mov [xax].GESTURECONFIG.dwWant, 0
  mov [xax].GESTURECONFIG.dwBlock, GC_PRESSANDTAP
  add xax, sizeof GESTURECONFIG
;  invoke SetGestureConfig, [xsi].hWnd, 0, sizeof(GestConf)/sizeof(GESTURECONFIG), \
;                           addr GestConf, sizeof(GESTURECONFIG)

  OCall xsi.Parse                                       ;Always parse the markup string
  OCall xsi.SetExtent

  xor eax, eax                                          ;Return zero to continue window creation
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     TextView.OnCtlColorStatic
; Purpose:    Event procedure for WM_CTLCOLORSTATIC message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     xax = Brush HANDLE used to paint the background of the static control.

Method TextView.OnCtlColorStatic, uses xsi, wParam:WPARAM, lParam:LPARAM
;  DbgText "TextView.OnCtlColorStatic"
  SetObject xsi
  invoke SetTextColor, wParam, [xsi].DefaultTextColor
  invoke SetBkColor, wParam, [xsi].DefaultBackColor
  ;After a Render call, this collection item holds the background brush
  OCall [xsi].GdiObjects::XWCollection.ItemAt, 1
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     TextView.OnDestroy
; Purpose:    Event handler for WM_DESTROY message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero.

Method TextView.OnDestroy, uses xsi, wParam:WPARAM, lParam:LPARAM
;  DbgText "TextView.OnDestroy"
  SetObject xsi
  OCall [xsi].Entries::DataCollection.Done
  OCall [xsi].ActiveAreas::XWCollection.Done
  OCall [xsi].InfoAreas::XWCollection.Done
  OCall [xsi].Styles::DataCollection.Done
  OCall [xsi].StyleStack::XWCollection.Done
  OCall [xsi].TabStops::SortedDataCollection.Done
  OCall [xsi].GdiObjects::XWCollection.Done
  OCall [xsi].CoverTasks::DataCollection.Done
  OCall [xsi].LineInfos::DataCollection.Done

  invoke DeleteObject, [xsi].hCanvasBrush

  invoke StrDispose, [xsi].pMarkupText

  invoke SelectObject, [xsi].hMemDC, [xsi].hPrvBmp
  invoke DeleteObject, xax
  invoke SelectObject, [xsi].hMemDC, [xsi].hPrvBrush
  invoke SelectObject, [xsi].hMemDC, [xsi].hPrvFont
  invoke DeleteDC, [xsi].hMemDC

  invoke DestroyWindow, [xsi].hToolTip
  invoke StrDispose, [xsi].pDefaultFontFace

  xor eax, eax
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     TextView.OnGesture
; Purpose:    Event procedure for WM_GESTURE message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.
; Link:       https://docs.microsoft.com/en-us/windows/win32/wintouch/improving-the-single-finger-panning-experience

Method TextView.OnGesture, uses xsi, wParam:WPARAM, lParam:LPARAM
  local GestInfo:GESTUREINFO, bResult:BOOL, bHandled:BOOL, ScrollInfo:SCROLLINFO
;  local Pnt1:POINT, bHasChanged:BOOL, dError:DWORD

;  DbgText "TextView.OnGesture"
  SetObject xsi

  ;Populate and retrieve the extra message info.
  invoke MemZero, addr GestInfo, sizeof GestInfo
  mov GestInfo.cbSize, sizeof GestInfo
  mov bResult, $32($invoke(GetGestureInfo, lParam, addr GestInfo))
  mov bHandled, FALSE

  ;DbgDec GestInfo.dwID
  .if bResult != FALSE
    ;Now interpret the gesture
    .if GestInfo.dwID == GID_ZOOM
      .ifBitSet [xsi].dOptions, TVO_ZOOMABLE
        .ifBitSet GestInfo.dwFlags, GF_BEGIN
          mov eax, DWORD ptr GestInfo.ullArguments
          mov [xsi].dGestureZoomFirst, eax
          mov [xsi].dGestureZoomLast, eax
        .else
          mov ecx, DWORD ptr GestInfo.ullArguments
          .if ecx != [xsi].dGestureZoomLast               ;Take an action if the value has changed
            mov [xsi].dGestureZoomLast, ecx               ;Remember the last value
            sub ecx, [xsi].dGestureZoomFirst

            invoke MulDiv, ecx, TVZOOM_STEP, WHEEL_DELTA  ;Handle it like the mousewheel
            mov edx, [xsi].dZoomFactor
            add edx, eax
            OCall xsi.SetZoomFactor, edx
            OCall xsi.Reset
            OCall xsi.Parse                               ;Required to rebuild all styles
            OCall xsi.SetExtent
            Pnt2Reg32 eax, ([xsi].ClientRect.right).POINT
            invoke SendMessage, [xsi].hWnd, WM_SIZE, SIZE_RESTORED, eax
            invoke RedrawWindow, [xsi].hWnd, NULL, 0, RDW_INVALIDATE or RDW_UPDATENOW

            mov ScrollInfo.cbSize, sizeof SCROLLINFO
            mov ScrollInfo.fMask, SIF_POS or SIF_PAGE
            m2m ScrollInfo.nPos, [xsi].Origin.y, edx
            m2m ScrollInfo.nPage, [xsi].ClientRect.bottom, edx
            invoke SetScrollInfo, [xsi].hWnd, SB_VERT, addr ScrollInfo, TRUE
          .endif
        .endif
      .endif
      mov bHandled, TRUE

      ;Handle the pan gesture the compatibility way

;    .elseif GestInfo.dwID == GID_PAN
;      ;Code for panning goes here
;      .ifBitSet GestInfo.dwFlags, GF_BEGIN
;        movsx eax, GestInfo.ptsLocation.x
;        movsx ecx, GestInfo.ptsLocation.y
;        mov [xsi].GesturePanPos.x, eax
;        mov [xsi].GesturePanPos.y, ecx
;
;      .else
;        movsx ecx, GestInfo.ptsLocation.x
;        mov eax, ecx
;        sub eax, [xsi].GesturePanPos.x
;        mov [xsi].GesturePanPos.x, ecx
;        mov bHasChanged, FALSE
;
;        .ifBitSet [xsi].dFlags, TVIF_SHOW_SB_HORZ
;          mov bHasChanged, TRUE
;          .if SDWORD ptr eax > [xsi].Origin.x
;            mov [xsi].Origin.x, 0
;          .else
;            mov edx, [xsi].ClientRect.right
;            sub edx, [xsi].Padding.left
;            sub edx, [xsi].Padding.right                ;edx = drawable width on the client window
;
;            mov ecx, [xsi].DrawExtent.x
;            sub ecx, [xsi].Origin.x
;            add ecx, eax                                ;ecx = new visible height
;
;            .if SDWORD ptr ecx < edx
;              mov eax, [xsi].DrawExtent.x
;              sub eax, edx
;              mov [xsi].Origin.x, eax
;            .else
;              sub [xsi].Origin.x, eax
;            .endif
;          .endif
;          invoke SetScrollPos, [xsi].hWnd, SB_HORZ, [xsi].Origin.x, TRUE
;        .endif
;
;        movsx ecx, GestInfo.ptsLocation.y
;        mov eax, ecx
;        sub eax, [xsi].GesturePanPos.y                  ;eax = delta pos y
;        mov [xsi].GesturePanPos.y, ecx
;
;        .ifBitSet [xsi].dFlags, TVIF_SHOW_SB_VERT
;          .if SDWORD ptr eax > [xsi].Origin.y
;          mov bHasChanged, TRUE
;            mov [xsi].Origin.y, 0
;          .else
;            mov edx, [xsi].ClientRect.bottom
;            sub edx, [xsi].Padding.top
;            sub edx, [xsi].Padding.bottom               ;edx = drawable height on the client window
;
;            mov ecx, [xsi].DrawExtent.y
;            sub ecx, [xsi].Origin.y
;            add ecx, eax                                ;ecx = new visible height
;
;            .if SDWORD ptr ecx < edx
;              mov eax, [xsi].DrawExtent.y
;              sub eax, edx
;              mov [xsi].Origin.y, eax
;            .else
;              sub [xsi].Origin.y, eax
;            .endif
;          .endif
;          invoke SetScrollPos, [xsi].hWnd, SB_VERT, [xsi].Origin.y, TRUE
;        .endif
;
;        .if bHasChanged
;          invoke RedrawWindow, [xsi].hWnd, NULL, 0, RDW_INVALIDATE or RDW_UPDATENOW
;        .endif
;      .endif
;      invoke DefWindowProc, [xsi].hWnd, WM_GESTURE, wParam, lParam
;      ret
;
;      mov bHandled, TRUE

      invoke CloseGestureInfoHandle, lParam             ;Close the gesture handle
    .endif
;  .else
;    DbgApiError "WM_GESTURE"
  .endif

  .if bHandled
    xor eax, eax
  .else
    invoke DefWindowProc, [xsi].hWnd, WM_GESTURE, wParam, lParam
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     TextView.OnGetFont
; Purpose:    Event procedure for WM_GETFONT message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     xax = Font handle or zero.

Method TextView.OnGetFont, uses xsi, wParam:WPARAM, lParam:LPARAM
;  DbgText "TextView.OnGetFont"
  SetObject xsi
  xor eax, eax
  .if [xsi].GdiObjects.dCount != 0
    OCall [xsi].GdiObjects::XWCollection.ItemAt, 0
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     TextView.OnGetZoom
; Purpose:    Event procedure for EM_GETZOOM message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     Nothing.

Method TextView.OnGetZoom, uses xsi, wParam:WPARAM, lParam:LPARAM
;  DbgText "TextView.OnGetZoom"
  SetObject xsi
  mov xcx, wParam
  m2m DWORD ptr [xcx], [xsi].dZoomFactor, eax
  mov xcx, lParam
  mov DWORD ptr [xcx], TVZOOM_BASE
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     TextView.OnHScroll
; Purpose:    Event procedure for WM_HSCROLL message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method TextView.OnHScroll, uses xsi, wParam:WPARAM, lParam:LPARAM
  local ScrollInfo:SCROLLINFO

  SetObject xsi
  mov xax, wParam
  .if ax == SB_THUMBPOSITION || ax == SB_THUMBTRACK
    shr eax, 16                                         ;Position is in HiWord
    mov [xsi].Origin.x, eax

  .elseif ax == SB_LINELEFT                             ;Scrolls left by one unit
    sub [xsi].Origin.x, 10
    .if SIGN?
      m2z [xsi].Origin.x
    .endif

  .else
    mov ScrollInfo.cbSize, sizeof(ScrollInfo)
    mov ScrollInfo.fMask, SIF_RANGE or SIF_PAGE
    invoke GetScrollInfo, [xsi].hWnd, SB_HORZ, addr ScrollInfo

    mov xax, wParam
    .if ax == SB_LINERIGHT
      mov eax, [xsi].Origin.x
      add eax, 10
      mov edx, ScrollInfo.nMax
      sub edx, ScrollInfo.nPage
      add edx, 1
      .if eax > edx
        mov eax, edx
      .endif
      mov [xsi].Origin.x, eax

    .elseif ax == SB_PAGERIGHT
      mov eax, [xsi].Origin.x
      add eax, ScrollInfo.nPage
      mov edx, ScrollInfo.nMax
      sub edx, ScrollInfo.nPage
      add edx, 1
      .if eax > edx
        mov eax, edx
      .endif
      mov [xsi].Origin.x, eax

    .elseif ax == SB_PAGELEFT
      mov eax, ScrollInfo.nPage
      sub [xsi].Origin.x, eax
      .if SIGN?
        m2z [xsi].Origin.x
      .endif

    .endif
  .endif

  invoke SetScrollPos, [xsi].hWnd, SB_HORZ, [xsi].Origin.x, TRUE
  invoke RedrawWindow, [xsi].hWnd, NULL, 0, RDW_INVALIDATE
  xor eax, eax
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     TextView.OnMouseMove
; Purpose:    Event procedure for WM_MOUSEMOVE message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero.

Method TextView.OnMouseMove, uses xsi, wParam:WPARAM, lParam:LPARAM
  local AppNotif:TVNM_APP, xCtrlID:XWORD, xCursor:XWORD
  local ToolInfo:TOOLINFO, TipNotif:TVNM_TIP

;  DbgText "TextView.OnMouseMove"
  SetObject xsi
  mov xCursor, IDC_ARROW
  mov xax, lParam                                       ;low-order word = x-coordinate of the cursor
  lea xdx, [xsi].InfoAreas
  OCall xsi.GetEntryFrom, xdx, eax
  .if xax != NULL
    .ifBitClr [xsi].dFlags, TVIF_TOOLTIP_ACTIVE
      mov xcx, [xax].TVENTRY.pStyle
      m2m TipNotif.dID, DWORD ptr [xcx].TVSTYLE.dID, edx
      mrm TipNotif.Header.hwndFrom, [xsi].hWnd, xcx
      mov xCtrlID, $invoke(GetMenu, xcx)
      mov TipNotif.Header.idFrom, xax
      mov TipNotif.Header.code, TVNMC_TIP
      mov TipNotif.pText, NULL
      invoke SendMessage, [xsi].hParent, WM_NOTIFY, xCtrlID, addr TipNotif
      mov ToolInfo.cbSize, sizeof(ToolInfo)
      m2m ToolInfo.lpszText, TipNotif.pText, xcx
      mrm ToolInfo.hwnd, [xsi].hWnd, xax
      mov ToolInfo.uId, xax
      invoke SendMessage, [xsi].hToolTip, TTM_UPDATETIPTEXT, 0, addr ToolInfo
      invoke SendMessage, [xsi].hToolTip, TTM_ACTIVATE, TRUE, 0
      BitSet [xsi].dFlags, TVIF_TOOLTIP_ACTIVE
    .endif
    .ifBitClr [xsi].dFlags, TVIF_TOOLTIP_SHOW
      mov xCursor, IDC_HELP
    .endif
  .else
    .ifBitSet [xsi].dFlags, TVIF_TOOLTIP_ACTIVE
      invoke SendMessage, [xsi].hToolTip, TTM_ACTIVATE, FALSE, 0
      BitClr [xsi].dFlags, TVIF_TOOLTIP_ACTIVE
    .endif
  .endif

  mov xax, lParam                                       ;low-order word = x-coordinate of the cursor
  lea xdx, [xsi].ActiveAreas
  OCall xsi.GetEntryFrom, xdx, eax
  .if xax != NULL
    m2m AppNotif.dID, DWORD ptr [xax].TVENTRY.xValue, ecx
    mrm AppNotif.Header.hwndFrom, [xsi].hWnd, xcx
    mov xCtrlID, $invoke(GetMenu, xcx)
    mov AppNotif.Header.idFrom, xax
    mov AppNotif.Header.code, TVNMC_APP_MOUSEOVER
    mov xax, wParam
    mov AppNotif.dButton, eax
    invoke SendMessage, [xsi].hParent, WM_NOTIFY, xCtrlID, addr AppNotif
    mov xCursor, IDC_HAND
  .endif

  invoke SetCursor, $invoke(LoadCursor, 0, xCursor)

  xor eax, eax
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     TextView.OnMouseWheel
; Purpose:    Event procedure for WM_MOUSEWHEEL message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero.

Method TextView.OnMouseWheel, uses xsi, wParam:WPARAM, lParam:LPARAM
  local ScrollInfo:SCROLLINFO

  SetObject xsi
  mov xax, wParam
  .ifBitSet ax, MK_CONTROL                              ;If CONTROL is pressed then ZOOM in/out
    .ifBitSet [xsi].dOptions, TVO_ZOOMABLE
      sar eax, 16                                       ;ax = multiples or divisions of WHEEL_DELTA
      invoke MulDiv, eax, TVZOOM_STEP, WHEEL_DELTA
      mov edx, [xsi].dZoomFactor
      add edx, eax
      OCall xsi.SetZoomFactor, edx
      OCall xsi.Reset
      OCall xsi.Parse                                   ;Required to rebuild all styles
      OCall xsi.SetExtent
      Pnt2Reg32 eax, ([xsi].ClientRect.right).POINT
      invoke SendMessage, [xsi].hWnd, WM_SIZE, SIZE_RESTORED, eax
      invoke RedrawWindow, [xsi].hWnd, NULL, 0, RDW_INVALIDATE or RDW_UPDATENOW

      mov ScrollInfo.cbSize, sizeof SCROLLINFO
      mov ScrollInfo.fMask, SIF_POS or SIF_PAGE
      m2m ScrollInfo.nPos, [xsi].Origin.y, edx
      m2m ScrollInfo.nPage, [xsi].ClientRect.bottom, edx
      invoke SetScrollInfo, [xsi].hWnd, SB_VERT, addr ScrollInfo, TRUE

    .endif
  .elseIfBitSet ax, MK_SHIFT                            ;If SHIFT is pressed then act on the horz SB
    .ifBitSet [xsi].dFlags, TVIF_SHOW_SB_HORZ           ;Check if the ScrollBar is shown
      shr eax, 16
      .if SWORD ptr ax > 0
        OCall xsi.OnHScroll, SB_LINEUP, 0
      .else
        OCall xsi.OnHScroll, SB_LINEDOWN, 0
      .endif
    .endif
  .else
    .ifBitSet [xsi].dFlags, TVIF_SHOW_SB_VERT           ;Check if the ScrollBar is shown
      shr eax, 16
      .if SWORD ptr ax > 0
        OCall xsi.OnVScroll, SB_LINEUP, 0
      .else
        OCall xsi.OnVScroll, SB_LINEDOWN, 0
      .endif
    .endif
  .endif
  xor eax, eax
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     TextView.OnNotify
; Purpose:    Event procedure for WM_NOTIFY message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero.

Method TextView.OnNotify,, wParam:WPARAM, lParam:LPARAM
;  DbgText "TextView.OnNotify"
  SetObject xcx
  mov xax, lParam
  mov xdx, [xcx].hToolTip
  .if [xax].NMHDR.hwndFrom == xdx
    .if [xax].NMHDR.code == TTN_SHOW
      BitSet [xcx].dFlags, TVIF_TOOLTIP_SHOW
    .elseif [xax].NMHDR.code == TTN_POP
      BitClr [xcx].dFlags, TVIF_TOOLTIP_SHOW
    .endif
    xor eax, eax
  .else
    invoke SendMessage, [xcx].hParent, WM_NOTIFY, wParam, lParam  ;Forward the msg to the parent wnd
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     TextView.OnPaint
; Purpose:    Event procedure for WM_PAINT message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method TextView.OnPaint, uses xbx xdi xsi, wParam:WPARAM, lParam:LPARAM
  local PS:PAINTSTRUCT, hDC:HDC, FRect:RECT

;  DbgText "TextView.OnPaint"
  SetObject xsi
  mov hDC, $invoke(BeginPaint, [xsi].hWnd, addr PS)

  mov eax, [xsi].ClientRect.right
  mov ecx, [xsi].Extent.x
  sub ecx, [xsi].Origin.x
  uMin ecx, eax, edi
  sub edi, [xsi].Padding.left
  sub edi, [xsi].Padding.right                          ;edi = visible x-extent of the DC

  mov eax, [xsi].ClientRect.bottom
  mov ecx, [xsi].Extent.y
  sub ecx, [xsi].Origin.y
  uMin ecx, eax, ebx
  sub ebx, [xsi].Padding.top
  sub ebx, [xsi].Padding.bottom                         ;ebx = visible y-extent of the DC

  invoke BitBlt, hDC, [xsi].Padding.left, [xsi].Padding.top, edi, ebx, \
                 [xsi].hMemDC, [xsi].Origin.x, [xsi].Origin.y, SRCCOPY

  mov FRect.top, 0
  m2m FRect.bottom, [xsi].ClientRect.bottom, ecx
  ;Fill the left vertical padding strip
  mov eax, [xsi].Padding.left
  .if SDWORD ptr eax > 0
    mov FRect.left, 0
    mov FRect.right, eax
    invoke FillRect, hDC, addr FRect, [xsi].hCanvasBrush
  .endif

  ;Fill the right vertical strip
  mov eax, edi
  add eax, [xsi].Padding.left
  mov edx, [xsi].ClientRect.right
  .if SDWORD ptr eax <= edx
    mov FRect.left, eax
    mov FRect.right, edx
    invoke FillRect, hDC, addr FRect, [xsi].hCanvasBrush
  .endif

  ;Fill the top horizontal padding strip
  mov edx, [xsi].Padding.left
  add edi, edx
  mov FRect.left, edx
  mov FRect.right, edi
  mov ecx, [xsi].Padding.top
  .if SDWORD ptr ecx > 0
    mov FRect.bottom, ecx
    invoke FillRect, hDC, addr FRect, [xsi].hCanvasBrush
  .endif

  ;Fill the bottom horizontal strip
  mov eax, ebx
  add eax, [xsi].Padding.top
  mov edx, [xsi].ClientRect.bottom
  .if SDWORD ptr eax <= edx
    mov FRect.top, eax
    mov FRect.bottom, edx
    invoke FillRect, hDC, addr FRect, [xsi].hCanvasBrush
  .endif

  invoke EndPaint, [xsi].hWnd, addr PS
  xor eax, eax
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     TextView.OnPrintClient
; Purpose:    Event procedure for WM_PRINTCLIENT message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method TextView.OnPrintClient, uses xbx xdi xsi, wParam:WPARAM, lParam:LPARAM
  local FRect:RECT, BitmapInfo:BITMAP

;  DbgText "TextView.OnPrintClient"
  SetObject xsi

  .ifBitSet lParam, PRF_ERASEBKGND
    invoke GetCurrentObject, wParam, OBJ_BITMAP
    mov xcx, xax
    invoke GetObject, xcx, sizeof(BitmapInfo), addr BitmapInfo
    m2z FRect.left
    m2z FRect.top
    m2m FRect.right, BitmapInfo.bmWidth, eax
    m2m FRect.bottom, BitmapInfo.bmHeight, eax
    invoke FillRect, wParam, addr FRect, [xsi].hCanvasBrush
  .endif

  .ifBitSet lParam, PRF_CLIENT
    mov eax, [xsi].ClientRect.right
    mov ecx, [xsi].Extent.x
    sub ecx, [xsi].Origin.x
    uMin ecx, eax, edi
    sub edi, [xsi].Padding.left
    sub edi, [xsi].Padding.right                          ;edi = visible x-extent of the DC

    mov eax, [xsi].ClientRect.bottom
    mov ecx, [xsi].Extent.y
    sub ecx, [xsi].Origin.y
    uMin ecx, eax, ebx
    sub ebx, [xsi].Padding.top
    sub ebx, [xsi].Padding.bottom                         ;ebx = visible y-extent of the DC

    invoke BitBlt, wParam, [xsi].Padding.left, [xsi].Padding.top, edi, ebx, \
                           [xsi].hMemDC, [xsi].Origin.x, [xsi].Origin.y, SRCCOPY

    ;Fill the left vertical padding strip
    mov eax, [xsi].Padding.left
    .if SDWORD ptr eax > 0
      mov FRect.left, 0
      mov FRect.top, 0
      mov FRect.right, eax
      m2m FRect.bottom, [xsi].ClientRect.bottom, ecx
      invoke FillRect, wParam, addr FRect, [xsi].hCanvasBrush
    .endif

    ;Fill the right vertical strip
    mov eax, edi
    add eax, [xsi].Padding.left
    mov edx, [xsi].ClientRect.right
    .if SDWORD ptr eax <= edx
      mov FRect.left, eax
      mov FRect.right, edx
      invoke FillRect, wParam, addr FRect, [xsi].hCanvasBrush
    .endif

    ;Fill the top horizontal padding strip
    mov ecx, [xsi].Padding.top
    .if SDWORD ptr ecx > 0
      mov edx, [xsi].Padding.left
      add edi, edx
      mov FRect.left, edx
      mov FRect.right, edi
      mov FRect.bottom, ecx
      invoke FillRect, wParam, addr FRect, [xsi].hCanvasBrush
    .endif

    ;Fill the bottom horizontal strip
    mov eax, ebx
    add eax, [xsi].Padding.top
    mov edx, [xsi].ClientRect.bottom
    .if SDWORD ptr eax <= edx
      mov FRect.top, eax
      mov FRect.bottom, edx
      invoke FillRect, wParam, addr FRect, [xsi].hCanvasBrush
    .endif
  .endif

  xor eax, eax
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     TextView.OnSetFont
; Purpose:    Event procedure for WM_SETFONT message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     Nothing.

Method TextView.OnSetFont, uses xsi, wParam:WPARAM, lParam:LPARAM
  local LogFont:LOGFONT

;  DbgText "TextView.OnSetFont"
  SetObject xsi
  invoke GetObject, wParam, sizeof(LogFont), addr LogFont
  .if xax != 0
    invoke StrReplace, addr [xsi].pDefaultFontFace, addr LogFont.lfFaceName
    OCall xsi.Reset
    OCall xsi.Parse
    OCall xsi.Calc
    .if lParam != FALSE
      OCall xsi.Draw
    .endif
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     TextView.OnSetText
; Purpose:    Event procedure for WM_SETTEXT message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     Nothing.

Method TextView.OnSetText, uses xsi, wParam:WPARAM, lParam:LPARAM
  ;DbgText "TextView.OnSetText"
  SetObject xsi
  invoke DefWindowProc, [xsi].hWnd, WM_SETTEXT, wParam, lParam
  invoke StrReplace, addr [xsi].pMarkupText, lParam
  OCall xsi.Reset
  OCall xsi.Parse
  OCall xsi.SetExtent
  OCall xsi.Calc
  Pnt2Reg32 eax, ([xsi].ClientRect.right).POINT
  invoke SendMessage, [xsi].hWnd, WM_SIZE, SIZE_RESTORED, eax
  invoke RedrawWindow, [xsi].hWnd, NULL, 0, RDW_INVALIDATE or RDW_UPDATENOW
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     TextView.OnSettingChange
; Purpose:    Event procedure for WM_SETTINGCHANGE message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zerio if handled.

Method TextView.OnSettingChange, uses xsi, wParam:WPARAM, lParam:LPARAM
;  DbgText "TextView.OnSettingChange"
  SetObject xsi
  ACall xsi.OnSettingChange, wParam, lParam
  OCall xsi.Reset
  OCall xsi.Parse
  OCall xsi.SetExtent
  OCall xsi.Calc
  Pnt2Reg32 eax, ([xsi].ClientRect.right).POINT
  invoke SendMessage, [xsi].hWnd, WM_SIZE, SIZE_RESTORED, eax
  invoke RedrawWindow, [xsi].hWnd, NULL, 0, RDW_INVALIDATE or RDW_UPDATENOW
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     TextView.OnSetZoom
; Purpose:    Event procedure for EM_SETZOOM message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     Nothing.

Method TextView.OnSetZoom, uses xsi, wParam:WPARAM, lParam:LPARAM
;  DbgText "TextView.OnSetZoom"
  SetObject xsi
  invoke MulDiv, 1, DWORD ptr wParam, DWORD ptr lParam
  OCall xsi.SetZoomFactor, eax
  OCall xsi.Reset
  OCall xsi.Parse                               ;Required to rebuild all styles
  OCall xsi.SetExtent
  invoke RedrawWindow, [xsi].hWnd, NULL, 0, RDW_INVALIDATE or RDW_UPDATENOW
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     TextView.OnSize
; Purpose:    Event procedure for WM_SIZE message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.
; Note:       DONT change the scrollbar visibility. It triggers another WM_SIZE!

Method TextView.OnSize, uses xsi, wParam:WPARAM, lParam:LPARAM
  local ScrollInfo:SCROLLINFO
  local RawClientRect:RECT
  local dCxVertScrollBar:DWORD, dCyHorzScrollBar:DWORD

  SetObject xsi
;  DbgText "OnSize"
  .if wParam != SIZE_MINIMIZED
    .ifBitClr [xsi].dFlags, TVIF_IN_ONSIZE
      BitSet [xsi].dFlags, TVIF_IN_ONSIZE

      ;Initialize some values
      mov dCxVertScrollBar, $32($invoke(GetSystemMetrics, SM_CXVSCROLL))
      mov dCyHorzScrollBar, $32($invoke(GetSystemMetrics, SM_CYHSCROLL))
      BitClr [xsi].dFlags, TVIF_SHOW_SB_HORZ or TVIF_SHOW_SB_VERT
      invoke GetClientRect, [xsi].hWnd, addr [xsi].ClientRect

      ;Calc RawClientRect
      s2s RawClientRect, [xsi].ClientRect, xax, xcx, xdx, xmm0, xmm1
      invoke GetWindowLongPtr, [xsi].hWnd, GWL_STYLE
      .ifBitSet eax, WS_HSCROLL
        mov ecx, dCyHorzScrollBar
        add RawClientRect.bottom, ecx
      .endif
      .ifBitSet eax, WS_VSCROLL
        mov ecx, dCxVertScrollBar
        add RawClientRect.right, ecx
      .endif

      s2s POINT ptr [xsi].ClientRect.right, POINT ptr RawClientRect.right, xax, xcx, xmm0

      .ifBitSet [xsi].dOptions, TVO_AUTO_LINEBREAK
        .ifBitClr [xsi].dFlags, TVIF_EXTENT_X_SET
          mov [xsi].Extent.x, eax                       ;Assume that that is the new extent.x
          sub eax, [xsi].Padding.left
          sub eax, [xsi].Padding.right
          mov [xsi].DrawExtent.x, eax
        .endif
        OCall xsi.Calc                                  ;1. Check
        m2m [xsi].DrawExtent.y, [xsi].IdealDrawExtent.y, ecx
        add ecx, [xsi].Padding.top
        add ecx, [xsi].Padding.bottom
        mov [xsi].Extent.y, ecx
        .if ecx > RawClientRect.bottom                  ;Check if a vertical scrollbar is needed
          BitSet [xsi].dFlags, TVIF_SHOW_SB_VERT        ;yes => Recalculate extent.y
          mov eax, [xsi].ClientRect.right               ;Adjust [xsi].ClientRect.right
          sub eax, dCxVertScrollBar
          mov [xsi].ClientRect.right, eax
          mov [xsi].Extent.x, eax
          sub eax, [xsi].Padding.left
          sub eax, [xsi].Padding.right
          mov [xsi].DrawExtent.x, eax
          OCall xsi.Calc                                ;2. check
          m2m [xsi].DrawExtent.y, [xsi].IdealDrawExtent.y, ecx
          add ecx, [xsi].Padding.top
          add ecx, [xsi].Padding.bottom
          mov [xsi].Extent.y, ecx
        .endif
        OCall xsi.Draw
        m2z [xsi].Origin.x
        BitClr [xsi].dFlags, TVIF_SHOW_SB_HORZ
        invoke ShowScrollBar, [xsi].hWnd, SB_HORZ, FALSE  ;Never shown if TVO_AUTO_LINEBREAK is set

      .else
        .if eax < [xsi].Extent.x                        ;Check and adjust [xsi].ClientRect.bottom
          BitSet [xsi].dFlags, TVIF_SHOW_SB_HORZ
          mov ecx, dCyHorzScrollBar
          sub [xsi].ClientRect.bottom, ecx
        .endif
        mov ecx, [xsi].ClientRect.bottom
        .if ecx < [xsi].Extent.y                        ;Check and adjust [xsi].ClientRect.bottom
          BitSet [xsi].dFlags, TVIF_SHOW_SB_VERT
          mov eax, dCxVertScrollBar
          sub [xsi].ClientRect.right, eax
          .ifBitClr [xsi].dFlags, TVIF_SHOW_SB_HORZ
            mov eax, [xsi].ClientRect.right
            .if eax < [xsi].Extent.x                    ;Check again and adjust [xsi].ClientRect.bottom
              BitSet [xsi].dFlags, TVIF_SHOW_SB_HORZ
              mov ecx, dCyHorzScrollBar
              sub [xsi].ClientRect.bottom, ecx
              .ifBitClr [xsi].dFlags, TVIF_SHOW_SB_VERT
                mov ecx, [xsi].ClientRect.bottom
                .if ecx < [xsi].Extent.y                ;Check again and adjust [xsi].ClientRect.right
                  BitSet [xsi].dFlags, TVIF_SHOW_SB_VERT
                  mov eax, dCxVertScrollBar
                  sub [xsi].ClientRect.right, eax
                .endif
              .endif
            .endif
          .endif
        .endif

        ;Handle horizontal ScrollBar
        .ifBitSet [xsi].dFlags, TVIF_SHOW_SB_HORZ
          mov edx, [xsi].ClientRect.right
          mov eax, [xsi].Extent.x
          sub eax, [xsi].Origin.x
          .if eax < edx
            sub edx, eax
            sub [xsi].Origin.x, edx
          .endif
          mov eax, [xsi].Extent.x
          dec eax
          invoke SetScrollRange, [xsi].hWnd, SB_HORZ, 0, eax, FALSE
          mov ScrollInfo.cbSize, sizeof SCROLLINFO
          mov ScrollInfo.fMask, SIF_POS or SIF_PAGE
          m2m ScrollInfo.nPos, [xsi].Origin.x, edx
          m2m ScrollInfo.nPage, [xsi].ClientRect.right, edx
          invoke SetScrollInfo, [xsi].hWnd, SB_HORZ, addr ScrollInfo, FALSE
          invoke ShowScrollBar, [xsi].hWnd, SB_HORZ, TRUE
        .else
          m2z [xsi].Origin.x
          invoke ShowScrollBar, [xsi].hWnd, SB_HORZ, FALSE
        .endif
      .endif

      ;Handle vertical ScrollBar
      .ifBitSet [xsi].dFlags, TVIF_SHOW_SB_VERT
        mov edx, [xsi].ClientRect.bottom
        mov ecx, [xsi].Extent.y
        sub ecx, [xsi].Origin.y
        .if ecx < edx
          sub edx, ecx
          sub [xsi].Origin.y, edx
        .endif
        mov eax, [xsi].Extent.y
        dec eax
        invoke SetScrollRange, [xsi].hWnd, SB_VERT, 0, eax, FALSE
        mov ScrollInfo.cbSize, sizeof SCROLLINFO
        mov ScrollInfo.fMask, SIF_POS or SIF_PAGE
        m2m ScrollInfo.nPos, [xsi].Origin.y, edx
        m2m ScrollInfo.nPage, [xsi].ClientRect.bottom, edx
        invoke SetScrollInfo, [xsi].hWnd, SB_VERT, addr ScrollInfo, FALSE
        invoke ShowScrollBar, [xsi].hWnd, SB_VERT, TRUE
      .else
        m2z [xsi].Origin.y
        invoke ShowScrollBar, [xsi].hWnd, SB_VERT, FALSE
      .endif

      BitClr [xsi].dFlags, TVIF_IN_ONSIZE
    .endif
  .endif

  xor eax, eax
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     TextView.OnThemeChanged
; Purpose:    Event procedure for WM_THEMECHANGED message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method TextView.OnThemeChanged, uses xsi, wParam:WPARAM, lParam:LPARAM
;  DbgText "TextView.OnThemeChanged"
  SetObject xsi
  OCall xsi.Reset
  OCall xsi.Parse
  OCall xsi.SetExtent
  OCall xsi.Calc
  Pnt2Reg32 eax, ([xsi].ClientRect.right).POINT
  invoke SendMessage, [xsi].hWnd, WM_SIZE, SIZE_RESTORED, eax
  invoke RedrawWindow, [xsi].hWnd, NULL, 0, RDW_INVALIDATE or RDW_UPDATENOW
  xor eax, eax
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     TextView.OnVScroll
; Purpose:    Event procedure for WM_VSCROLL message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method TextView.OnVScroll, uses xsi, wParam:WPARAM, lParam:LPARAM
  local ScrollInfo:SCROLLINFO

  SetObject xsi
  mov xax, wParam
  .if ax == SB_THUMBPOSITION || ax == SB_THUMBTRACK
    shr eax, 16
    mov [xsi].Origin.y, eax

  .elseif ax == SB_LINELEFT
    sub [xsi].Origin.y, 10
    .if SIGN?
      m2z [xsi].Origin.y
    .endif

  .else
    mov ScrollInfo.cbSize, sizeof(ScrollInfo)
    mov ScrollInfo.fMask, SIF_RANGE or SIF_PAGE
    invoke GetScrollInfo, [xsi].hWnd, SB_VERT, addr ScrollInfo

    mov xax, wParam
    .if ax == SB_LINERIGHT
      mov eax, [xsi].Origin.y
      add eax, 10
      mov edx, ScrollInfo.nMax
      sub edx, ScrollInfo.nPage
      add edx, 1
      .if eax > edx
        mov eax, edx
      .endif
      mov [xsi].Origin.y, eax

    .elseif ax == SB_PAGERIGHT
      mov eax, [xsi].Origin.y
      add eax, ScrollInfo.nPage
      mov edx, ScrollInfo.nMax
      sub edx, ScrollInfo.nPage
      add edx, 1
      .if eax > edx
        mov eax, edx
      .endif
      mov [xsi].Origin.y, eax

    .elseif ax == SB_PAGELEFT
      mov eax, ScrollInfo.nPage
      sub [xsi].Origin.y, eax
      .if SIGN?
        m2z [xsi].Origin.y
      .endif

    .endif
  .endif

  invoke SetScrollPos, [xsi].hWnd, SB_VERT, [xsi].Origin.y, TRUE
  invoke RedrawWindow, [xsi].hWnd, NULL, 0, RDW_INVALIDATE
  xor eax, eax
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     TextView.Parse
; Purpose:    Parse input markup text string using a state machine.
; Arguments:  None.
; Return:     eax = TRUE if succeeded, otherwise FALSE.

;Styles:    [FONT "ARIAL", HEIGHT 10, ...]Some Text.[~]
;Command:   {TABC 120}{BR}

;States:
;  [  Markup  Numeric  ,  Markup  'String'  ]TEXT[ ~  ~ ~  ]
; 04  5     6 #RRGGBB  4  5     6 A       9 01     C        1
;             7      9            B       9  Space
;             Decimal                        2    1
;             8      9                       Tab
;             +                              3    1
;             -

;Transitions:
;From  To   Condition        Description
; 00  04    == "["           Markup start
; 00  02    == " "           White mode
; 00  03    == Tab           Check ExpandTab
; 00  01    else             Text

; 01  04    == "["           Markup start
; 01  02    == " "           White mode
; 01  03    == Tab           Check ExpandTab

; 02  03    == Tab
; 02  01    <> " "
;
; 03  01    TabExpand == 1   Expand to dTab2Spaces spaces
; 03  01    == Tab           Create Command
;
; 04  12    == "~"           Markup pop
; 04  05    == "A...Z"       Markup name
; 04  00    <> White

; 05  06    == White
; 05  01    == "]"           Markup close
; 05  00    <> "A..Z"

; 06  07    == "#"           Markup hex value
; 06  08    == "0..9"        Markup decimal value
; 06  09    == "@"           Markup system color value
; 06  10    == "'"           Markup single quoted string value
; 06  11    == '"'           Markup double quoted string value
; 06  01    == "]"           Markup close

; 07  09    == " "
; 07  04    == ,             Next Markup
; 07  01    == "]"           Evaluate hex value & Markup push
; 07  00    <> "A..F"

; 08  09    == " "
; 08  04    == ,             Next Markup, evaluate decimal value
; 08  01    == "]"           Markup close, evaluate decimal value
; 08  00    <> "0..9"

; 09  04    == ","
; 09  01    == "]"
; 09  00    == <> White

; 10  09    == "'"

; 11  09    == '"'

; 12  01    == "]"
; 12  00    <> "~", " ", Tab

; ...

GetTagFromTable proc uses xbx xdi xsi pTable:POINTER, dTagSize:DWORD, pBeg:POINTER, pEnd:POINTER
  mov xsi, pTable
  mov ebx, dTagSize
  xor eax, eax
  mov xdi, pEnd
  sub xdi, pBeg
  if TARGET_STR_TYPE eq STR_TYPE_WIDE
    shr edi, 1
  endif
  .while TRUE
    mov ecx, [xsi].TVSTAG.dLength
    .break .if ecx == 0                                 ;Last TAG reached
    .break .if ecx > edi                                ;Not found condition
    .if ZERO?                                           ;Length match if ZERO?
      invoke StrCIComp, pBeg, [xsi].TVSTAG.pMnemonic, edi ;Check string
      .if SDWORD ptr eax < 0
        xor eax, eax
        .break
      .endif
      .if ZERO?
        mov xax, xsi                                    ;Found
        .break
      .endif
      xor eax, eax
    .endif
    add xsi, xbx                                        ;Move to nect TAG
  .endw
  ret
GetTagFromTable endp

$NewTVENTRY macro pCurStyle
  MemAlloc sizeof(TVENTRY), MEM_INIT_ZERO
;  DbgHex xax, "New TVENTRY"
  OCall [xsi].Entries::DataCollection.Insert, xax
  ifnb <pCurStyle>
    m2m [xax].TVENTRY.pStyle, pCurStyle, xdx
  endif
  exitm <xax>
endm

DupTVStyle macro
  mov dStyleChange, TVSC_NOTHING
  MemAlloc sizeof(TVSTYLE)
;  DbgHex xax, "New TVSTYLE"
  OCall [xsi].Styles::DataCollection.Insert, xax
  OCall [xsi].StyleStack::DataCollection.Insert, xax
  .if xdi == NULL                                       ;If current style = NULL => load def. values
    m2m [xax].TVSTYLE.TextColor, [xsi].DefaultTextColor, ecx
    m2m [xax].TVSTYLE.BackColor, [xsi].DefaultBackColor, ecx
    mov [xax].TVSTYLE.dAlignment, TVALIGN_LEFT
    m2z [xax].TVSTYLE.dIndent
    m2z [xax].TVSTYLE.dHanging
    m2m [xax].TVSTYLE.dFontSize, [xsi].dDefaultFontSize, ecx
    m2z [xax].TVSTYLE.hFont
    m2z [xax].TVSTYLE.hBackBrush
    m2z [xax].TVSTYLE.dFlags
    m2z [xax].TVSTYLE.dID
  .else
    s2s TVSTYLE ptr [xax], TVSTYLE ptr [xdi], xcx, xdx, xmm0, xmm1, xmm2, xmm3, xmm4, xmm5, xmm6
  .endif
  mov xdi, xax
endm

CreateTVStyleFont macro
;  DbgDec [xdi].TVSTYLE.dFontSize, "Creating Font"
  invoke MulDiv, [xdi].TVSTYLE.dFontSize, [xsi].dLogPixY, -72
  mov [xdi].TVSTYLE.LogFont.lfHeight, eax
  mov [xdi].TVSTYLE.LogFont.lfCharSet, DEFAULT_CHARSET
  mov [xdi].TVSTYLE.hFont, $invoke(CreateFontIndirect, addr [xdi].TVSTYLE.LogFont)
  OCall [xsi].GdiObjects::DataCollection.Insert, xax
  invoke SelectObject, [xsi].hMemDC, [xdi].TVSTYLE.hFont
  invoke GetTextMetrics, [xsi].hMemDC, addr [xdi].TVSTYLE.TextMetric
endm

CreateTVSytleResources macro
  .ifBitSet dStyleChange, TVSC_FONT
    CreateTVStyleFont
  .endif
  .ifBitSet dStyleChange, TVSC_BACKCOLOR
    mov [xdi].TVSTYLE.hBackBrush, $invoke(CreateSolidBrush, [xdi].TVSTYLE.BackColor)
    OCall [xsi].GdiObjects::DataCollection.Insert, xax
    invoke SelectObject, [xsi].hMemDC, xax
  .endif
endm

GetSingleTVStyleName macro HasArguments:req
  m2z CHR ptr cBuffer                                   ;Clear buffer
  invoke GetTagFromTable, offset TVTAG_STYLES, sizeof TVSTAG, pBlockBeg, pBlockEnd
  .if xax != NULL
    mov xax, [xax].TVSTAG.pHandler
    .if cCurChr == TVTAG_STYLE_CLOSE
      invoke TVStyleHandler ptr xax, NULL
      BitSet dStyleChange, eax                          ;Remember style changes
      CreateTVSytleResources
      mov dTVStateID, TVSID_INIT
      add pBlockEnd, sizeof(CHR)
  if HasArguments eq TRUE
    .elseif cCurChr == ","
      invoke TVStyleHandler ptr xax, NULL
      BitSet dStyleChange, eax                          ;Remember style changes
      mov dTVStateID, TVSID_STYLE
      add pBlockEnd, sizeof(CHR)
    .else
      mov pTVStyleHandler, xax
      mov dTVStateID, TVSID_STYLE_NAME_END              ;Delimiter detected
      .if IsBlankChar
        add pBlockEnd, sizeof(CHR)
      .endif
    .endif
  else
    .else
      invoke TVStyleHandler ptr xax, NULL
      BitSet dStyleChange, eax                          ;Remember style changes
      add pBlockEnd, sizeof(CHR)
    .endif
  endif

  .else                                                 ;ecx == VMT_NONE
    mov dTVStateID, TVSID_ERROR
    DbgWarning "Parsing error: Style identifier not found"
  .endif
endm

DefineTextViewState macro StateName:req
  TVSID_&StateName equ TVStateID
  TVStateID = TVStateID + 1
  POINTER offset TVSTATE_&StateName
endm

IsStyleNameChar textequ <((cCurChr !>= "A" && cCurChr !<= "Z") || \
                          (cCurChr !>= "a" && cCurChr !<= "z") || \
                           cCurChr == "." || cCurChr == "_")>
IsCmdNameChar   textequ IsStyleNameChar
IsHexChar       textequ <((cCurChr !>= "A" && cCurChr !<= "F") || \
                          (cCurChr !>= "a" && cCurChr !<= "f") || \
                          (cCurChr !>= "0" && cCurChr !<= "9"))>
IsDecChar       textequ <(cCurChr !>= "0" && cCurChr !<= "9")>
IsBlankChar     textequ <(cCurChr == " " || cCurChr == 9)>
IsDelimiterChar textequ <(cCurChr == " " || cCurChr == 9 || \
                          cCurChr == "'" || cCurChr == '"' || \
                          cCurChr == "+" || cCurChr == '-' || \
                          cCurChr == "#" || cCurChr == '@' || \
                          cCurChr == ',' || \
                          (cCurChr !>= "0" && cCurChr !<= "9"))>

.code
Method TextView.Parse, uses xdi xsi
  local cCurChr:CHR, dTVStateID:DWORD, dCharCount:DWORD, dBufferChars:DWORD
  local pBlockBeg:PSTRING, pBlockEnd:PSTRING, pCmdBeg:PSTRING, pCmdEnd:PSTRING
  local pEntry:PTVENTRY, dStyleChange:DWORD
  local pTVStyleHandler:PTVStyleHandler, dValue:DWORD, cBuffer[1024]:CHR
;  local SW:$Obj(StopWatch)

  ;xsi -> TextView
  ;xdi -> current TVSTYLE

  ;Create state jump table
  .const
  TVStateID = 0                                         ;Set first TVStateID = 0
  ViewStates label POINTER                              ;Build jump table and define EQUs
  DefineTextViewState ERROR                             ;TVStateID = 00
  DefineTextViewState INIT                              ;TVStateID = 01
  DefineTextViewState TEXT                              ;TVStateID = 02
  DefineTextViewState BLANK                             ;TVStateID = 03
  DefineTextViewState STYLE                             ;TVStateID = 04
  DefineTextViewState STYLE_NAME                        ;TVStateID = 05
  DefineTextViewState STYLE_NAME_END                    ;TVStateID = 06
  DefineTextViewState STYLE_HEX                         ;TVStateID = 07
  DefineTextViewState STYLE_DEC                         ;TVStateID = 08
  DefineTextViewState STYLE_SYSCOLOR                    ;TVStateID = 09
  DefineTextViewState STYLE_VAL_END                     ;TVStateID = 10
  DefineTextViewState STYLE_STR1                        ;TVStateID = 11
  DefineTextViewState STYLE_STR2                        ;TVStateID = 12
  DefineTextViewState STYLE_POP                         ;TVStateID = 13
  DefineTextViewState CMD                               ;TVStateID = 14
  DefineTextViewState CMD_ANALIZE                       ;TVStateID = 15
  DefineTextViewState CMD_END                           ;TVStateID = 16
  DefineTextViewState CMD_NAME                          ;TVStateID = 17
  DefineTextViewState CMD_NAME_END                      ;TVStateID = 18
  DefineTextViewState CMD_DEC                           ;TVStateID = 19
  DefineTextViewState CMD_DEC_END                       ;TVStateID = 20
  DefineTextViewState CMD_CHR                           ;TVStateID = 21
  DefineTextViewState CMD_CHR_END                       ;TVStateID = 22
;  DefineTextViewState CMD_STR1                          ;TVStateID = 23
;  DefineTextViewState CMD_STR2                          ;TVStateID = 24
;  DefineTextViewState CMD_STR_END                       ;TVStateID = 25

  .code
;  DbgText "TextView.Parse"

  SetObject xsi

;  New SW::StopWatch
;  OCall SW::StopWatch.Init, xsi
;  OCall SW::StopWatch.Start

  ;Get default colors
  invoke SendMessage, [xsi].hParent, WM_CTLCOLORSTATIC, [xsi].hMemDC, [xsi].hWnd
  mov [xsi].DefaultTextColor, $32($invoke(GetSysColor, COLOR_WINDOWTEXT))
  mov [xsi].DefaultBackColor, $32($invoke(GetSysColor, COLOR_WINDOW))
  mov [xsi].CanvasColor, eax

  mov xdx, [xsi].pMarkupText
  mov pBlockBeg, xdx
  mov pBlockEnd, xdx

  ;Create first TVSTYLE and store initial MemDC values
  mov dStyleChange, TVSC_NOTHING
  MemAlloc sizeof(TVSTYLE)
  OCall [xsi].Styles::DataCollection.Insert, xax
  OCall [xsi].StyleStack::DataCollection.Insert, xax
  mov xdi, xax

  mov [xdi].TVSTYLE.dAlignment, TVALIGN_LEFT
  m2z [xdi].TVSTYLE.dIndent
  m2z [xax].TVSTYLE.dHanging
  m2z [xdi].TVSTYLE.dFlags
  m2z [xax].TVSTYLE.dID

  m2m [xdi].TVSTYLE.dFontSize, [xsi].dDefaultFontSize, eax

  invoke StrCCopy, addr [xdi].TVSTYLE.LogFont.lfFaceName, [xsi].pDefaultFontFace, 32
  m2z [xdi].TVSTYLE.LogFont.lfWidth
  m2z [xdi].TVSTYLE.LogFont.lfEscapement
  m2z [xdi].TVSTYLE.LogFont.lfOrientation
  mov [xdi].TVSTYLE.LogFont.lfCharSet, DEFAULT_CHARSET
  mov [xdi].TVSTYLE.LogFont.lfOutPrecision, OUT_DEFAULT_PRECIS
  mov [xdi].TVSTYLE.LogFont.lfClipPrecision, CLIP_DEFAULT_PRECIS
  mov [xdi].TVSTYLE.LogFont.lfQuality, CLEARTYPE_QUALITY
  mov [xdi].TVSTYLE.LogFont.lfPitchAndFamily, DEFAULT_PITCH or FF_DONTCARE
  mov [xdi].TVSTYLE.LogFont.lfWeight, FW_NORMAL
  m2z [xdi].TVSTYLE.LogFont.lfItalic
  m2z [xdi].TVSTYLE.LogFont.lfUnderline
  m2z [xdi].TVSTYLE.LogFont.lfStrikeOut
  CreateTVStyleFont                                     ;Resource #0

  m2m [xdi].TVSTYLE.TextColor, [xsi].DefaultTextColor, eax
  m2m [xdi].TVSTYLE.BackColor, [xsi].DefaultBackColor, eax
  mov [xdi].TVSTYLE.hBackBrush, $invoke(CreateSolidBrush, [xdi].TVSTYLE.BackColor)

  OCall [xsi].GdiObjects::DataCollection.Insert, xax    ;Resource #1
  invoke SelectObject, [xsi].hMemDC, xax                ;Select text background brush

  mov dTVStateID, TVSID_INIT                            ;Set initial state

  .while TRUE
    mov xdx, pBlockEnd
    m2m cCurChr, CHR ptr [xdx], ecx
    .if $SubReg(ecx, sizeof(CHR)) == 0                  ;End of markup string?
      .if dTVStateID == TVSID_TEXT
        mov xax, pBlockEnd
        sub xax, pBlockBeg
        if TARGET_STR_TYPE eq STR_TYPE_WIDE
          shr eax, 1
        endif
        invoke StrCNew, pBlockBeg, eax
        mov xcx, pEntry
        mov [xcx].TVENTRY.pString, xax
      .endif
      .break
    .endif

    mov xdx, offset ViewStates
    mov ecx, dTVStateID
    jmp POINTER ptr [xdx + sizeof(POINTER)*xcx]

    TVSTATE_INIT:
      mov pEntry, NULL
      .if cCurChr == TVTAG_STYLE_OPEN
        DupTVStyle
        add pBlockEnd, sizeof(CHR)
        mov dTVStateID, TVSID_STYLE

      .else
        mov pEntry, $NewTVENTRY(xdi)                    ;xdi -> current Style
        .if cCurChr == TVTAG_CMD_OPEN
          mov [xax].TVENTRY.dType, TVET_CMD
          add pBlockEnd, sizeof(CHR)
          mov dTVStateID, TVSID_CMD

        .elseif cCurChr == " "
          mov [xax].TVENTRY.dType, TVET_BLANK
          mov [xax].TVENTRY.dCharCount, 1
          add pBlockEnd, sizeof(CHR)
          mov dTVStateID, TVSID_BLANK
        .else
          .if cCurChr == 9
            ;Handle it as regular blanks
            mov [xax].TVENTRY.dType, TVET_BLANK
            m2m [xax].TVENTRY.dCharCount, [xsi].dTab2Spaces, ecx
            add pBlockEnd, sizeof(CHR)
            mov dTVStateID, TVSID_TEXT
          .else
            mov [xax].TVENTRY.dType, TVET_TEXT
            mov [xax].TVENTRY.dCharCount, 1
            mrm pBlockBeg, pBlockEnd, xcx
            add xcx, sizeof(CHR)
            mov pBlockEnd, xcx
            mov dTVStateID, TVSID_TEXT
          .endif
        .endif
      .endif
      .continue

    TVSTATE_TEXT:
      .if cCurChr == TVTAG_STYLE_OPEN || cCurChr == TVTAG_CMD_OPEN || IsBlankChar
        mov xax, pBlockEnd
        sub xax, pBlockBeg
        if TARGET_STR_TYPE eq STR_TYPE_ANSI
          mov dCharCount, eax
          inc eax                                       ;Include the ZTC
          mov dBufferChars, eax
          invoke StrAllocW, dCharCount
          mov xcx, pEntry
          mov [xcx].TVENTRY.pString, xax
          mov edx, dCharCount
          m2z CHRW ptr [xax + sizeof(CHRW)*xdx]         ;Set ZTC
          invoke MultiByteToWideChar, CP_ACP, 0, pBlockBeg, dCharCount, xax, dBufferChars
        else
          shr eax, 1
          invoke StrCNewW, pBlockBeg, eax
          mov xcx, pEntry
          mov [xcx].TVENTRY.pString, xax
        endif
        .if cCurChr == TVTAG_STYLE_OPEN
          DupTVStyle
          mov dTVStateID, TVSID_STYLE

        .elseif cCurChr == TVTAG_CMD_OPEN
          mov pEntry, $NewTVENTRY(xdi)
          mov [xax].TVENTRY.dType, TVET_CMD
          mov dTVStateID, TVSID_CMD

        .elseif cCurChr == " "
          mov pEntry, $NewTVENTRY(xdi)
          mov [xax].TVENTRY.dType, TVET_BLANK
          mov [xax].TVENTRY.dCharCount, 1
          mov dTVStateID, TVSID_BLANK

        .elseif cCurChr == 9
          mov pEntry, $NewTVENTRY(xdi)
          ;Handle it as a regular character
          mov [xax].TVENTRY.dType, TVET_BLANK
          mov ecx, [xsi].dTab2Spaces
          add [xax].TVENTRY.dCharCount, ecx
          mov dTVStateID, TVSID_BLANK
        .endif

      .else
        mov xax, pEntry
        add [xax].TVENTRY.dCharCount, 1
      .endif
      add pBlockEnd, sizeof(CHR)
      .continue

    TVSTATE_BLANK:
      .if cCurChr == 9
        ;Handle it as a regular character
        mov xax, pEntry
        add [xax].TVENTRY.dCharCount, ecx
        mov ecx, [xsi].dTab2Spaces

      .elseif cCurChr == " "
        mov xax, pEntry
        add [xax].TVENTRY.dCharCount, 1

      .elseif cCurChr == TVTAG_STYLE_OPEN
        mov xax, pEntry
        invoke StrRepChrW, " ", [xax].TVENTRY.dCharCount
        mov xcx, pEntry
        mov [xcx].TVENTRY.pString, xax
        DupTVStyle
        mov dTVStateID, TVSID_STYLE

      .elseif cCurChr == TVTAG_CMD_OPEN
        mov xax, pEntry
        invoke StrRepChrW, " ", [xax].TVENTRY.dCharCount
        mov xcx, pEntry
        mov [xcx].TVENTRY.pString, xax
        mov pEntry, $NewTVENTRY(xdi)
        mov [xax].TVENTRY.dType, TVET_CMD
        mov dTVStateID, TVSID_CMD

      .else
        mov xax, pEntry
        invoke StrRepChrW, " ", [xax].TVENTRY.dCharCount
        mov xcx, pEntry
        mov [xcx].TVENTRY.pString, xax
        mov pEntry, $NewTVENTRY(xdi)
        mov [xax].TVENTRY.dType, TVET_TEXT
        mov [xax].TVENTRY.dCharCount, 1
        m2m pBlockBeg, pBlockEnd, xcx
        mov dTVStateID, TVSID_TEXT
      .endif
      add pBlockEnd, sizeof(CHR)
      .continue

    ;Styles -------------------------------------------------------------------

    TVSTATE_STYLE:
      .if IsBlankChar
        add pBlockEnd, sizeof(CHR)                      ;Skip blanks

      .elseif cCurChr == "~"
        mov dValue, 1                                   ;Initialize to 1
        mov dTVStateID, TVSID_STYLE_POP
        add pBlockEnd, sizeof(CHR)

      .elseif IsStyleNameChar
        m2m pBlockBeg, pBlockEnd, xcx                   ;Remember beginning
        add xcx, sizeof(CHR)
        mov pBlockEnd, xcx
        mov dTVStateID, TVSID_STYLE_NAME

      .else
        add pBlockEnd, sizeof(CHR)                      ;Bad character
        mov dTVStateID, TVSID_ERROR
        DbgWarning "Parsing error in TVSTATE_STYLE"
      .endif
      .continue

    TVSTATE_STYLE_NAME:
      .if IsDelimiterChar || cCurChr == TVTAG_STYLE_CLOSE
        GetSingleTVStyleName TRUE
      .else
        .if !IsStyleNameChar                            ;Bad character
          mov dTVStateID, TVSID_ERROR
          DbgWarning "Parsing error in TVSTATE_STYLE_NAME"
        .endif
        add pBlockEnd, sizeof(CHR)
      .endif
      .continue

    TVSTATE_STYLE_NAME_END:
      .if cCurChr == TVTAG_STYLE_CLOSE || cCurChr == ","
        GetSingleTVStyleName FALSE

      .elseif cCurChr == "#"
        mov dTVStateID, TVSID_STYLE_HEX
        mov xcx, pBlockEnd
        add xcx, sizeof(CHR)
        mov pBlockBeg, xcx
        mov pBlockEnd, xcx

      .elseif cCurChr == "@"
        mov dTVStateID, TVSID_STYLE_SYSCOLOR
        mov xcx, pBlockEnd
        add xcx, sizeof(CHR)
        mov pBlockBeg, xcx
        mov pBlockEnd, xcx

      .elseif IsDecChar
        mov dTVStateID, TVSID_STYLE_DEC
        mrm pBlockBeg, pBlockEnd, xcx
        add xcx, sizeof(CHR)
        mov pBlockEnd, xcx

      .elseif cCurChr == "+"
        mov dTVStateID, TVSID_STYLE_DEC
        mov xcx, pBlockEnd
        add xcx, sizeof(CHR)
        mov pBlockBeg, xcx
        mov pBlockEnd, xcx
        BitSet [xdi].TVSTYLE.dFlags, TVSF_INCR

      .elseif cCurChr == "-"
        mov dTVStateID, TVSID_STYLE_DEC
        mov xcx, pBlockEnd
        add xcx, sizeof(CHR)
        mov pBlockBeg, xcx
        mov pBlockEnd, xcx
        BitSet [xdi].TVSTYLE.dFlags, TVSF_DECR

      .elseif cCurChr == "'"
        mov xcx, pBlockEnd
        add xcx, sizeof(CHR)
        mov pBlockBeg, xcx                              ;Remember beginning
        mov pBlockEnd, xcx
        mov dTVStateID, TVSID_STYLE_STR1

      .elseif cCurChr == '"'
        mov xcx, pBlockEnd
        add xcx, sizeof(CHR)
        mov pBlockBeg, xcx                              ;Remember beginning
        mov pBlockEnd, xcx
        mov dTVStateID, TVSID_STYLE_STR2

      .elseif IsBlankChar
        add pBlockEnd, sizeof(CHR)                      ;Skip blanks

      .else
        add pBlockEnd, sizeof(CHR)                      ;Bad character
        mov dTVStateID, TVSID_ERROR
        DbgWarning "Parsing error in TVSTATE_STYLE_NAME_END"
      .endif
      .continue

    TVSTATE_STYLE_HEX:
      .if IsBlankChar || cCurChr == "," || cCurChr == TVTAG_STYLE_CLOSE
        FillString cBuffer, <00000000>                  ;Complete with zeros
        mov edx, 8*sizeof(CHR)
        mov xax, pBlockEnd
        sub xax, pBlockBeg
        .if eax > 0 && eax <= 6*sizeof(CHR)             ;0 < # of digits <= 6 (RGB)
          sub xdx, xax
          invoke MemClone, addr [cBuffer + xdx], pBlockBeg, eax
        .endif
        mov DWORD ptr cBuffer, $32($invoke(hex2dword, addr cBuffer))
        m2z CHR ptr [cBuffer + sizeof(DWORD)]           ;Just in case
        invoke pTVStyleHandler, addr cBuffer
        or dStyleChange, eax

        .if IsBlankChar
          mov dTVStateID, TVSID_STYLE_VAL_END
        .elseif cCurChr == ","
          mov dTVStateID, TVSID_STYLE
        .else                                           ;"]"
          CreateTVSytleResources
          mov dTVStateID, TVSID_INIT
        .endif

      .elseif !IsHexChar
        mov dTVStateID, TVSID_ERROR                     ;Bad character
        DbgWarning "Parsing error in TVSTATE_STYLE_HEX"
      .endif
      add pBlockEnd, sizeof(CHR)
      .continue

    TVSTATE_STYLE_DEC:
      .if IsBlankChar || cCurChr == "," || cCurChr == TVTAG_STYLE_CLOSE
        mov xax, pBlockEnd
        sub xax, pBlockBeg
        lea xcx, cBuffer
        m2z CHR ptr [xcx + xax]                         ;ZTC
        invoke MemClone, xcx, pBlockBeg, eax
        mov DWORD ptr cBuffer, $32($invoke(dec2dword, addr cBuffer))
        m2z CHR ptr [cBuffer + sizeof(DWORD)]           ;Just in case
        invoke pTVStyleHandler, addr cBuffer
        or dStyleChange, eax

        .if IsBlankChar
          mov dTVStateID, TVSID_STYLE_VAL_END
        .elseif cCurChr == ","
          mov dTVStateID, TVSID_STYLE
        .else                                           ;"]"
          CreateTVSytleResources
          mov dTVStateID, TVSID_INIT
        .endif

      .elseif !IsDecChar                                ;Bad characters
        mov dTVStateID, TVSID_ERROR
        DbgWarning "Parsing error in TVSTATE_STYLE_DEC"
      .endif
      add pBlockEnd, sizeof(CHR)
      .continue

    TVSTATE_STYLE_SYSCOLOR:
      .if IsBlankChar || cCurChr == "," || cCurChr == TVTAG_STYLE_CLOSE
        mov xax, pBlockEnd
        sub xax, pBlockBeg
        lea xcx, cBuffer
        m2z CHR ptr [xcx + xax]                         ;ZTC
        invoke MemClone, xcx, pBlockBeg, eax
        invoke dec2dword, addr cBuffer
        invoke GetSysColor, eax
        BGR2RGB eax
        mov DWORD ptr cBuffer, eax
        m2z CHR ptr [cBuffer + sizeof(DWORD)]           ;Just in case
        invoke pTVStyleHandler, addr cBuffer
        or dStyleChange, eax

        .if IsBlankChar
          mov dTVStateID, TVSID_STYLE_VAL_END
        .elseif cCurChr == ","
          mov dTVStateID, TVSID_STYLE
        .else                                           ;"]"
          CreateTVSytleResources
          mov dTVStateID, TVSID_INIT
        .endif

      .elseif !IsDecChar                                ;Bad characters
        mov dTVStateID, TVSID_ERROR
        DbgWarning "Parsing error in TVSTATE_STYLE_SYSCOLOR"
      .endif
      add pBlockEnd, sizeof(CHR)
      .continue

    TVSTATE_STYLE_VAL_END:
      .if cCurChr == ","
        add pBlockEnd, sizeof(CHR)
        mov dTVStateID, TVSID_STYLE

      .elseif cCurChr == TVTAG_STYLE_CLOSE
        CreateTVSytleResources
        mov dTVStateID, TVSID_INIT
        add pBlockEnd, sizeof(CHR)

      .elseif IsBlankChar
        add pBlockEnd, sizeof(CHR)

      .else
        mov dTVStateID, TVSID_ERROR
        DbgWarning "Parsing error in TVSTATE_STYLE_VAL_END"
      .endif
      .continue

    TVSTATE_STYLE_STR1:
      .if cCurChr == "'"
        mov xax, pBlockEnd
        sub xax, pBlockBeg
        lea xcx, [cBuffer]
        m2z CHR ptr [xcx + xax]                         ;Set ZTC
        invoke MemClone, xcx, pBlockBeg, eax
        invoke pTVStyleHandler, addr cBuffer
        or dStyleChange, eax
        mov dTVStateID, TVSID_STYLE_VAL_END
      .endif
      add pBlockEnd, sizeof(CHR)
      .continue

    TVSTATE_STYLE_STR2:
      .if cCurChr == '"'
        mov xax, pBlockEnd
        sub xax, pBlockBeg
        lea xcx, [cBuffer]
        m2z CHR ptr [xcx + xax]                         ;Set ZTC
        invoke MemClone, xcx, pBlockBeg, eax
        invoke pTVStyleHandler, addr cBuffer
        or dStyleChange, eax
        mov dTVStateID, TVSID_STYLE_VAL_END
      .endif
      add pBlockEnd, sizeof(CHR)
      .continue

    TVSTATE_STYLE_POP:
      .if cCurChr == "~"                                ;For each "~" pop a TVSTYLE from stack
        add dValue, 1

      .elseif cCurChr == TVTAG_STYLE_CLOSE
        add dValue, 1                                   ;Delete itself
        mov eax, [xsi].StyleStack.dCount
        sub eax, dValue
        .if SDWORD ptr eax < 1                          ;Leave the first
          mov eax, 1
        .endif

        mov [xsi].StyleStack.dCount, eax
        sub eax, 1
        mov xdi, $OCall([xsi].StyleStack::DataCollection.ItemAt, eax)
        mov dTVStateID, TVSID_INIT

      .elseif !IsBlankChar
        mov dTVStateID, TVSID_ERROR
        DbgWarning "Parsing error in TVSTATE_STYLE_POP"
      .endif
      add pBlockEnd, sizeof(CHR)
      .continue

    ;Commands -----------------------------------------------------------------

    TVSTATE_CMD:
      .if IsBlankChar
        add pBlockEnd, sizeof(CHR)                      ;Skip blanks

      .elseif cCurChr == "#"
        mov xcx, pBlockEnd                              ;Remember beginning
        add xcx, sizeof(CHR)                            ;Skip "#" char
        mov pBlockBeg, xcx
        mov pBlockEnd, xcx
        mov xdx, pEntry
        m2m [xdx].TVENTRY.pTag, TVCTAG_CHAR, xax
        mov dTVStateID, TVSID_CMD_CHR

      .elseif IsCmdNameChar
        mov xcx, pBlockEnd
        mov pCmdBeg, xcx                                ;Remember beginning of command
        mov pBlockBeg, xcx
        add xcx, sizeof(CHR)
        mov pBlockEnd, xcx                              ;Move to next char
        mov dTVStateID, TVSID_CMD_NAME

      .else
        mov dTVStateID, TVSID_ERROR
        add pBlockEnd, sizeof(CHR)                      ;Bad character
        DbgWarning "Parsing error in TVSTATE_CMD"
      .endif
      .continue

    TVSTATE_CMD_ANALIZE:
      ;We handle here the TextView options, since they apply for the complete text
      invoke GetTagFromTable, offset TVTAG_OPTIONS, sizeof TVOTAG, pCmdBeg, pCmdEnd
      .if xax != NULL
        mov dTVStateID, TVSID_CMD_END
        jmp [xax].TVOTAG.pHandler

      TVOH_AUTO_LINEBREAK::
        BitSet [xsi].dOptions, TVO_AUTO_LINEBREAK
        OCall [xsi].Entries::DataCollection.Dispose, pEntry
        .continue

      TVOH_ZOOMABLE::
        BitSet [xsi].dOptions, TVO_ZOOMABLE
        OCall [xsi].Entries::DataCollection.Dispose, pEntry
        .continue

      TVOH_PADDING_LFT::
        mov xdx, pEntry
        mov xcx, [xdx].TVENTRY.xValue
        mov [xsi].Padding.left, ecx
        OCall [xsi].Entries::DataCollection.Dispose, xdx
        .continue

      TVOH_PADDING_TOP::
        mov xdx, pEntry
        mov xcx, [xdx].TVENTRY.xValue
        mov [xsi].Padding.top, ecx
        OCall [xsi].Entries::DataCollection.Dispose, xdx
        .continue

      TVOH_PADDING_RGT::
        mov xdx, pEntry
        mov xcx, [xdx].TVENTRY.xValue
        mov [xsi].Padding.right, ecx
        OCall [xsi].Entries::DataCollection.Dispose, xdx
        .continue

      TVOH_PADDING_BOT::
        mov xdx, pEntry
        mov xcx, [xdx].TVENTRY.xValue
        mov [xsi].Padding.bottom, ecx
        OCall [xsi].Entries::DataCollection.Dispose, xdx
        .continue

      TVOH_PADDING::
        mov xdx, pEntry
        mov xcx, [xdx].TVENTRY.xValue
        mov [xsi].Padding.left, ecx
        mov [xsi].Padding.top, ecx
        mov [xsi].Padding.right, ecx
        mov [xsi].Padding.bottom, ecx
        OCall [xsi].Entries::DataCollection.Dispose, xdx
        .continue

      TVOH_SIZE_X::
        mov xdx, pEntry
        mov xcx, [xdx].TVENTRY.xValue
        BitSet [xsi].dFlags, TVIF_EXTENT_X_SET
        mov [xsi].Extent.x, ecx
        OCall [xsi].Entries::DataCollection.Dispose, xdx
        .continue

      TVOH_SIZE_Y::
        mov xdx, pEntry
        mov xcx, [xdx].TVENTRY.xValue
        BitSet [xsi].dFlags, TVIF_EXTENT_Y_SET
        mov [xsi].Extent.y, ecx
        OCall [xsi].Entries::DataCollection.Dispose, xdx
        .continue

      .else
        invoke GetTagFromTable, offset TVTAG_CMDS, sizeof TVCTAG, pCmdBeg, pCmdEnd
        .if xax != NULL
          mov xdx, pEntry
          mov [xdx].TVENTRY.pTag, xax
          mov dTVStateID, TVSID_CMD_END
        .else
          mov dTVStateID, TVSID_ERROR
          DbgWarning "Parsing error: Command identifier not found"
          add pBlockEnd, sizeof(CHR)
        .endif
      .endif
      .continue

    TVSTATE_CMD_END:
      .if cCurChr == ","
        mov pEntry, $NewTVENTRY(xdi)
        mov [xax].TVENTRY.dType, TVET_CMD
        mov dTVStateID, TVSID_CMD                       ;Process next command after colon
      .else
        mov dTVStateID, TVSID_INIT
      .endif
      add pBlockEnd, sizeof(CHR)                        ;Discard the char
      .continue

    TVSTATE_CMD_NAME:
      .if IsDelimiterChar || cCurChr == TVTAG_CMD_CLOSE
        m2m pCmdEnd, pBlockEnd, xax
        mov dTVStateID, TVSID_CMD_NAME_END              ;Don't move to next char
      .else
        .if !IsCmdNameChar
          mov dTVStateID, TVSID_ERROR                   ;Bad character
          DbgWarning "Parsing error in TVSTATE_CMD_NAME"
        .endif
        add pBlockEnd, sizeof(CHR)
      .endif
      .continue

    TVSTATE_CMD_NAME_END:
      .if cCurChr == "," || cCurChr == TVTAG_CMD_CLOSE
        mov dTVStateID, TVSID_CMD_ANALIZE               ;Don't move to next char

      .elseif IsDecChar
        mov dTVStateID, TVSID_CMD_DEC
        mrm pBlockBeg, pBlockEnd, xcx
        add xcx, sizeof(CHR)                            ;Move to next char
        mov pBlockEnd, xcx

      .elseif IsBlankChar
        add pBlockEnd, sizeof(CHR)                      ;Skip blanks

;      .elseif cCurChr == "'"
;        mov xcx, pBlockEnd
;        add xcx, sizeof(CHR)
;        mov pBlockBeg, xcx                              ;Remember beginning
;        mov pBlockEnd, xcx
;        mov dTVStateID, TVSID_CMD_STR1
;
;      .elseif cCurChr == '"'
;        mov xcx, pBlockEnd
;        add xcx, sizeof(CHR)
;        mov pBlockBeg, xcx                              ;Remember beginning
;        mov pBlockEnd, xcx
;        mov dTVStateID, TVSID_CMD_STR2

      .else
        add pBlockEnd, sizeof(CHR)                      ;Bad character
        mov dTVStateID, TVSID_ERROR
        DbgWarning "Parsing error in TVSTATE_CMD_NAME_END"
      .endif
      .continue

    TVSTATE_CMD_DEC:
      .if IsBlankChar || cCurChr == TVTAG_CMD_CLOSE || cCurChr == ","
        mov xax, pBlockEnd
        sub xax, pBlockBeg
        lea xcx, cBuffer
        m2z CHR ptr [xcx + xax]                         ;ZTC
        invoke MemClone, xcx, pBlockBeg, eax
        invoke dec2dword, addr cBuffer
        mov xdx, pEntry
        mov [xdx].TVENTRY.xValue, xax
        mov dTVStateID, TVSID_CMD_DEC_END

      .else
        .if !IsDecChar                                  ;Bad characters
          mov dTVStateID, TVSID_ERROR
          DbgWarning "Parsing error in TVSTATE_CMD_DEC"
        .endif
        add pBlockEnd, sizeof(CHR)
      .endif
      .continue

    TVSTATE_CMD_DEC_END:
      .if cCurChr == "," || cCurChr == TVTAG_CMD_CLOSE
        mov dTVStateID, TVSID_CMD_ANALIZE
      .else
        .if !IsBlankChar
          mov dTVStateID, TVSID_ERROR
          DbgWarning "Parsing error in TVSTATE_CMD_DEC_END"
        .endif
        add pBlockEnd, sizeof(CHR)
      .endif
      .continue

    TVSTATE_CMD_CHR:
      .if IsBlankChar || cCurChr == TVTAG_CMD_CLOSE || cCurChr == ","
        FillString cBuffer, <00000000>                  ;Complete with zeros
        mov edx, 8*sizeof(CHR)
        mov xax, pBlockEnd
        sub xax, pBlockBeg
        .if eax > 0 && eax <= 6*sizeof(CHR)             ;0 < # of digits <= 6 (RGB)
          sub xdx, xax
          invoke MemClone, addr [cBuffer + xdx], pBlockBeg, eax
        .endif
        invoke hex2dword, addr cBuffer
        mov xcx, pEntry
        mov [xcx].TVENTRY.xValue, xax
        mov dTVStateID, TVSID_CMD_CHR_END               ;Don't move to next char
      .else
        .if !IsHexChar
          mov dTVStateID, TVSID_ERROR                   ;Bad character
          DbgWarning "Parsing error in TVSTATE_CMD_CHR"
        .endif
        add pBlockEnd, sizeof(CHR)
      .endif
      .continue

    TVSTATE_CMD_CHR_END:
      .if cCurChr == "," || cCurChr == TVTAG_CMD_CLOSE
        mov dTVStateID, TVSID_CMD_END                   ;Don't move to next char
      .else
        .if !IsBlankChar
          mov dTVStateID, TVSID_ERROR
          DbgWarning "Parsing error in TVSTATE_CMD_CHR_END"
        .endif
        add pBlockEnd, sizeof(CHR)
      .endif
      .continue

;    TVSTATE_CMD_STR1:
;      .if cCurChr == "'"
;        mov xdx, pBlockEnd
;        sub xdx, pBlockBeg
;        invoke StrCNew, pBlockBeg, edx
;        mov xcx, pEntry
;        mov [xcx].TVENTRY.pString, xax
;        mov dTVStateID, TVSID_CMD_STR_END
;      .endif
;      add pBlockEnd, sizeof(CHR)
;      .continue
;
;    TVSTATE_CMD_STR2:
;      .if cCurChr == '"'
;        mov xdx, pBlockEnd
;        sub xdx, pBlockBeg
;        invoke StrCNew, pBlockBeg, edx
;        mov xcx, pEntry
;        mov [xcx].TVENTRY.pString, xax
;        mov dTVStateID, TVSID_CMD_STR_END
;      .endif
;      add pBlockEnd, sizeof(CHR)
;      .continue
;
;    TVSTATE_CMD_STR_END:
;      .if cCurChr == TVTAG_CMD_CLOSE
;        mov dTVStateID, TVSID_CMD_ANALIZE
;
;      .elseif !IsBlankChar
;        add pBlockEnd, sizeof(CHR)
;        mov dTVStateID, TVSID_ERROR
;        DbgWarning "Parsing error in TVSTATE_CMD_STR_END"
;      .endif
;      .continue

    TVSTATE_ERROR:
      add pBlockEnd, sizeof(CHR)
      .break

  .endw

  mov [xsi].hCanvasBrush, $invoke(CreateSolidBrush, [xsi].CanvasColor)

;  OCall SW::StopWatch.Stop
;  OCall SW::StopWatch.GetTimeStr, addr cBuffer
;  DbgStr cBuffer, "Parsing"

  mov eax, TRUE

MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     TextView.Reset
; Purpose:    Reset all collections, freeing associated resources.
; Arguments:  None.
; Return:     Nothing.

Method TextView.Reset, uses xsi
  SetObject xsi
  OCall [xsi].Entries::DataCollection.DisposeAll
  OCall [xsi].ActiveAreas::XWCollection.DeleteAll
  OCall [xsi].InfoAreas::XWCollection.DeleteAll
  OCall [xsi].Styles::DataCollection.DisposeAll
  OCall [xsi].StyleStack::XWCollection.DeleteAll
  OCall [xsi].TabStops::SortedDataCollection.DisposeAll
  OCall [xsi].GdiObjects::XWCollection.DisposeAll
  OCall [xsi].CoverTasks::DataCollection.DisposeAll
  OCall [xsi].LineInfos::DataCollection.DisposeAll
  invoke DeleteObject, [xsi].hCanvasBrush
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     TextView.SetExtent
; Purpose:    Defines the extent values accorting to the parsed information.
; Arguments:  None.
; Return:     Nothing.

Method TextView.SetExtent, uses xsi
  SetObject xsi
  mov eax, [xsi].dFlags
  .ifBitSet eax, TVIF_EXTENT_X_SET
    mov ecx, [xsi].Extent.x
    sub ecx, [xsi].Padding.left
    sub ecx, [xsi].Padding.right
    mov [xsi].DrawExtent.x, ecx
  .endif

  .ifBitSet eax, TVIF_EXTENT_Y_SET
    mov ecx, [xsi].Extent.y
    sub ecx, [xsi].Padding.top
    sub ecx, [xsi].Padding.bottom
    mov [xsi].DrawExtent.y, ecx
  .endif

  and eax, (TVIF_EXTENT_X_SET or TVIF_EXTENT_Y_SET)
  .if eax == (TVIF_EXTENT_X_SET or TVIF_EXTENT_Y_SET)   ;Both flags must be set
    OCall xsi.Calc
    OCall xsi.Draw
  .else
    .ifBitClr [xsi].dOptions, TVO_AUTO_LINEBREAK
      OCall xsi.Calc
      mov eax, [xsi].dFlags
      .ifBitClr eax, TVIF_EXTENT_X_SET
        mrm [xsi].DrawExtent.x, [xsi].IdealDrawExtent.x, ecx
        add ecx, [xsi].Padding.left
        add ecx, [xsi].Padding.right
        mov [xsi].Extent.x, ecx
      .endif
      .ifBitClr eax, TVIF_EXTENT_Y_SET
        mrm [xsi].DrawExtent.y, [xsi].IdealDrawExtent.y, ecx
        add ecx, [xsi].Padding.top
        add ecx, [xsi].Padding.bottom
        mov [xsi].Extent.y, ecx
      .endif
      OCall xsi.Draw
    .else
      .ifBitSet [xsi].dFlags, TVIF_EXTENT_X_SET
        OCall xsi.Calc
        .ifBitClr [xsi].dFlags, TVIF_EXTENT_Y_SET
          mrm [xsi].DrawExtent.y, [xsi].IdealDrawExtent.y, ecx
          add ecx, [xsi].Padding.top
          add ecx, [xsi].Padding.bottom
          mov [xsi].Extent.y, ecx
        .endif
      .endif
    .endif
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     TextView.SetZoomFactor
; Purpose:    Set the zoom factor within min max limits.
; Arguments:  Arg1: New zoom factor candidate.
; Return:     Nothing.

Method TextView.SetZoomFactor, uses xsi, dNewZoomFactor:DWORD
  SetObject xsi
  mov eax, dNewZoomFactor
  .if SDWORD ptr eax <= TVZOOM_MIN
    mov eax, TVZOOM_MIN
  .elseif SDWORD ptr eax >= TVZOOM_MAX
    mov eax, TVZOOM_MAX
  .endif
  mov [xsi].dZoomFactor, eax
  invoke MulDiv, TVDEFAULT_FONT_SIZE, eax, TVZOOM_BASE
  mov [xsi].dDefaultFontSize, eax
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     TextView.Startup
; Purpose:    Register the TextView window class with the operating system.
; Arguments:  None.
; Return:     Nothing.

Method TextView.Startup
  local WC:WNDCLASSEX

  mov WC.cbSize, sizeof(WNDCLASSEX)
  m2z WC.style
  m2m WC.lpfnWndProc, $MethodAddr(TextView.WndProc), xax
  m2z WC.cbClsExtra
  m2z WC.cbWndExtra
  m2m WC.hInstance, hInstance, xax
  mov WC.hbrBackground, 0;COLOR_WINDOW + 1
  m2z WC.lpszMenuName
  %mov xax, offset cTextViewClass&TARGET_STR_AFFIX
  mov WC.lpszClassName, xax
  m2z WC.hIcon
  m2z WC.hCursor
  m2z WC.hIconSm

  invoke RegisterClassEx, addr WC
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     TextView.WidthToNextStop
; Purpose:    Return the next TVENTRY of type TVET_TEXT or TAB command.
; Arguments:  Arg1: Current TVENTRY index.
; Return:     eax = cummulated width to next stop (TAB, BREAK or PARA)

Method TextView.WidthToNextStop, uses xbx xdi xsi, dEntryIndex:DWORD
  SetObject xsi
  mov ebx, dEntryIndex
  inc ebx
  xor edi, edi
  .while ebx < [xsi].Entries.dCount
    OCall [xsi].Entries::DataCollection.ItemAt, ebx
    mov edx, [xax].TVENTRY.dType
    .if edx == TVET_CMD
      mov xcx, [xax].TVENTRY.pTag
      mov xax, TVCTAG_TAB
      mov xdx, TVCTAG_TAB_S
      .break .if xcx == xax || xcx == xdx
      mov xax, TVCTAG_BREAK
      mov xdx, TVCTAG_BREAK_S
      .break .if xcx == xax || xcx == xdx
      mov xax, TVCTAG_PARA
      mov xdx, TVCTAG_PARA_S
      .break .if xcx == xax || xcx == xdx
    .elseif edx == TVET_TEXT || edx == TVET_BLANK
      add edi, [xax].TVENTRY.Extent.right
    .endif
    inc ebx
  .endw
  mov eax, edi
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     TextView.WindowProc
; Purpose:    Dispatching of window messages.
; Arguments:  Arg1: Message identifier.
;             Arg2: First message parameter.
;             Arg3: Second message parameter.
; Return:     eax = This value is the result of the message processing and depends on the msg ID.
;             Window HANDLE is passed in pSelf (hidden parameter).

Method TextView.WndProc, uses xsi, uMsg:DWORD, wParam:WPARAM, lParam:LPARAM
  ;DbgMessage uMsg,, "TextView.WndProc"
  .if uMsg == WM_NCCREATE
    mov xax, lParam
    .if [xax].CREATESTRUCT.lpCreateParams == NULL
      ;If lpCreateParams is 0, then it is a resource call => Create new object instance
      mov xsi, $New(TextView)
      invoke GetParent, pSelf
      mov [xsi].$Obj(TextView).hParent, xax
      .if xax != 0
        invoke SendMessage, xax, WM_GETOBJECTINSTANCE, 0, 0 ;Get instance POINTER of the parent object
      .endif
      ACall xsi::TextView.Init, xax, pSelf              ;Window.Init
      BitSet [xsi].$Obj(TextView).dFlags, TVIF_SELF_INST
    .else
      ;Init call
      mov xsi, [xax].CREATESTRUCT.lpCreateParams
      m2m [xsi].$Obj(TextView).hWnd, pSelf, xax
    .endif
    invoke SetWindowLongPtr, pSelf, GWLP_USERDATA, xsi
    OCall xsi::TextView.Dispatch, pSelf, uMsg, wParam, lParam
  .else
    invoke GetWindowLongPtr, pSelf, GWLP_USERDATA       ;if GWLP_USERDATA wasn't set,
    .if xax == NULL                                     ;GetWindowLongPtr returns NULL
      invoke DefWindowProc, pSelf, uMsg, wParam, lParam
    .else
      mov xsi, xax
      OCall xsi::TextView.Dispatch, pSelf, uMsg, wParam, lParam
      .if uMsg == WM_NCDESTROY
        .ifBitSet [xsi].$Obj(TextView).dFlags, TVIF_SELF_INST
          ACall xsi::TextView.Done
          MemFree xsi 
        .endif
      .endif
    .endif
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedures: TVSH_xxx
; Purpose:    Handler for TextView TVSTYLE changes.
; Arguments:  Arg1: xsi -> TextView object.
;             Arg2: xdi -> TVSTYLE.
;             Arg3: -> Buffer.
; Return:     eax = Indicates what was changed and needs to be updated:
;                   TVSC_NOTHING, TVSC_FONT, TVSC_BACKCOLOR

;##\
TVSH_APP proc pBuffer:POINTER
;  DbgText "APP"
  ?mov xcx, pBuffer
  .if xcx == NULL
    mov eax, -1
  .else
    mov eax, [xcx]
  .endif
  mov [xdi].TVSTYLE.dID, eax
  BitSet [xdi].TVSTYLE.dFlags, TVSF_ACTIVE
  mov eax, TVSC_NOTHING
  ret
TVSH_APP endp

TVSH_BOX proc pBuffer:POINTER
;  DbgText "BOX"
  ?mov xcx, pBuffer
  .if xcx == NULL
    mov eax, [xsi].$Obj(TextView).DefaultBackColor
  .else
    mov eax, [xcx]
    BGR2RGB eax                                         ;Swap Red <-> Blue
  .endif
  mov [xdi].TVSTYLE.BoxColor, eax
  BitSet [xdi].TVSTYLE.dFlags, TVSF_BOX
  mov eax, TVSC_NOTHING
  ret
TVSH_BOX endp

TVSH_SUB proc pBuffer:POINTER
;  DbgText "SUB"
  mov eax, [xdi].TVSTYLE.dFontSize
  shr eax, 1
  mov [xdi].TVSTYLE.dFontSize, eax
  BitSet [xdi].TVSTYLE.dFlags, TVSF_SUB
  mov eax, TVSC_FONT
  ret
TVSH_SUB endp

TVSH_SUP proc pBuffer:POINTER
;  DbgText "SUP"
  mov eax, [xdi].TVSTYLE.dFontSize
  shr eax, 1
  mov [xdi].TVSTYLE.dFontSize, eax
  BitSet [xdi].TVSTYLE.dFlags, TVSF_SUP
  mov eax, TVSC_FONT
  ret
TVSH_SUP endp

TVSH_TXT proc pBuffer:POINTER
;  DbgText "TXT"
  ?mov xcx, pBuffer
  .if xcx == NULL
    mov eax, -1
  .else
    mov eax, [xcx]
  .endif
  mov [xdi].TVSTYLE.dTextID, eax
  BitSet [xdi].TVSTYLE.dFlags, TVSF_TEXTCALLBACK
  mov eax, TVSC_NOTHING
  ret
TVSH_TXT endp

TVSH_BOLD proc pBuffer:POINTER
;  DbgText "BOLD"
  mov [xdi].TVSTYLE.LogFont.lfWeight, FW_BOLD
  mov eax, TVSC_FONT
  ret
TVSH_BOLD endp

TVSH_FONT proc pBuffer:POINTER
;  DbgText "FONT"
  lea xcx, [xdi].TVSTYLE.LogFont.lfFaceName
  mov xdx, pBuffer
  .if xdx == NULL
    mov xdx, [xsi].$Obj(TextView).pDefaultFontFace
  .endif
  invoke StrCopy, xcx, xdx
  mov eax, TVSC_FONT
  ret
TVSH_FONT endp

TVSH_TIP proc pBuffer:POINTER
;  DbgText "TIP"
  ?mov xcx, pBuffer
  .if xcx == NULL
    mov eax, -1
  .else
    mov eax, [xcx]
  .endif
  mov [xdi].TVSTYLE.dID, eax
  BitSet [xdi].TVSTYLE.dFlags, TVSF_TIP
  mov eax, TVSC_NOTHING
  ret
TVSH_TIP endp

TVSH_ALIGNCENTER proc pBuffer:POINTER
;  DbgText "ALIGN"
  mov [xdi].TVSTYLE.dAlignment, TVALIGN_CENTER
  mov eax, TVSC_NOTHING
  ret
TVSH_ALIGNCENTER endp

TVSH_ALIGNLEFT proc pBuffer:POINTER
;  DbgText "ALIGN"
  mov [xdi].TVSTYLE.dAlignment, TVALIGN_LEFT
  mov eax, TVSC_NOTHING
  ret
TVSH_ALIGNLEFT endp

TVSH_ALIGNRIGHT proc pBuffer:POINTER
;  DbgText "ALIGN"
  mov [xdi].TVSTYLE.dAlignment, TVALIGN_RIGHT
  mov eax, TVSC_NOTHING
  ret
TVSH_ALIGNRIGHT endp

TVSH_COLOR proc pBuffer:POINTER
;  DbgText "COLOR"
  ?mov xcx, pBuffer
  .if xcx == NULL
    mov eax, [xsi].$Obj(TextView).DefaultTextColor
  .else
    mov eax, [xcx]
    BGR2RGB eax                                         ;Swap Red <-> Blue
  .endif
  mov [xdi].TVSTYLE.TextColor, eax
  mov eax, TVSC_NOTHING
  ret
TVSH_COLOR endp

TVSH_CANVAS proc pBuffer:POINTER
;  DbgText "CANVAS"
  ?mov xcx, pBuffer
  .if xcx == NULL
    mov eax, [xsi].$Obj(TextView).DefaultTextColor
  .else
    mov eax, [xcx]
    BGR2RGB eax                                         ;Swap Red <-> Blue
  .endif
  mov [xsi].$Obj(TextView).CanvasColor, eax
  mov eax, TVSC_NOTHING
  ret
TVSH_CANVAS endp

TVSH_HEIGHT proc pBuffer:POINTER
;  DbgText "HEIGHT"
  ?mov xcx, pBuffer
  .if xcx == NULL
    mov eax, [xsi].$Obj(TextView).dDefaultFontSize
  .else
    .ifBitSet [xdi].TVSTYLE.dFlags, TVSF_INCR
      mov eax, [xdi].TVSTYLE.dFontSize
      add eax, [xcx]
    .elseIfBitSet [xdi].TVSTYLE.dFlags, TVSF_DECR
      mov eax, [xdi].TVSTYLE.dFontSize
      sub eax, [xcx]
      .if SIGN?
        xor eax, eax
      .endif
    .else
      mov eax, [xcx]
    .endif
    BitClr [xdi].TVSTYLE.dFlags, TVSF_INCR or TVSF_DECR
  .endif
  mov [xdi].TVSTYLE.dFontSize, eax
  mov eax, TVSC_FONT
  ret
TVSH_HEIGHT endp

TVSH_INDENT proc pBuffer:POINTER
;  DbgText "INDENT"
  ?mov xcx, pBuffer
  .if xcx == NULL
    xor eax, eax
  .else
    mov eax, [xcx]
  .endif
  mov [xdi].TVSTYLE.dIndent, eax
  mov eax, TVSC_NOTHING
  ret
TVSH_INDENT endp

TVSH_ITALIC proc pBuffer:POINTER
;  DbgText "ITALIC"
  mov [xdi].TVSTYLE.LogFont.lfItalic, TRUE
  mov eax, TVSC_FONT
  ret
TVSH_ITALIC endp

TVSH_BGCOLOR proc pBuffer:POINTER
;  DbgText "BGCOLOR"
  ?mov xcx, pBuffer
  .if xcx == NULL
    mov eax, [xsi].$Obj(TextView).DefaultBackColor
  .else
    mov eax, [xcx]
    BGR2RGB eax                                         ;Swap Red <-> Blue
  .endif
  mov [xdi].TVSTYLE.BackColor, eax
  mov eax, TVSC_BACKCOLOR
  ret
TVSH_BGCOLOR endp

TVSH_HANGING proc pBuffer:POINTER
;  DbgText "HANGING"
  ?mov xcx, pBuffer
  .if xcx == NULL
    xor eax, eax
  .else
    mov eax, [xcx]
  .endif
  mov [xdi].TVSTYLE.dHanging, eax
  mov eax, TVSC_NOTHING
  ret
TVSH_HANGING endp

TVSH_STRIKEOUT proc pBuffer:POINTER
;  DbgText "STRIKEOUT"
  mov [xdi].TVSTYLE.LogFont.lfStrikeOut, TRUE
  mov eax, TVSC_FONT
  ret
TVSH_STRIKEOUT endp

TVSH_UNDERLINE proc pBuffer:POINTER
;  DbgText "UNDERLINE"
  mov [xdi].TVSTYLE.LogFont.lfUnderline, TRUE
  mov eax, TVSC_FONT
  ret
TVSH_UNDERLINE endp
;##/

endif
