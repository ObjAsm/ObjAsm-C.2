; ==================================================================================================
; Title:      GridView.inc
; Author:     G. Friedrich
; Version:    C.1.1
; Purpose:    ObjAsm support of GridView objects.
; Notes:      Version C.1.1, May 2020
;               - First release.
; ==================================================================================================


; Design notes:


CStr szGridViewClass, "OAC_GridView", "&$ToStr(%TARGET_BITNESS)", "&TARGET_STR_AFFIX"

;GridView Window Flag
GVWF_RESOURCE      equ   BIT00

DEF_GRIDVIEW struc
  xCtlID        XWORD     ?         ;Contol ID
  dStyle        DWORD     ?         ;Style
  dExStyle      DWORD     ?         ;Extended style
  pTitle        PSTRING   ?         ;-> Window text
  union
    rect        RECT      {}
    struct
      sdPosX    SDWORD    ?         ;X position
      sdPosY    SDWORD    ?         ;Y position
      dWidth    DWORD     ?         ;Width
      dHeight   DWORD     ?         ;Height
    ends
  ends
DEF_GRIDVIEW ends
PDEF_GRIDVIEW typedef ptr DEF_GRIDVIEW


; --------------------------------------------------------------------------------------------------
; Object:     GridView
; Purpose:

Object GridView, GridViewID, Window
  VirtualMethod     Dispatch,           HWND, DWORD, WPARAM, LPARAM
  RedefineMethod    Done
  RedefineMethod    Init,               POINTER, HWND, PDEF_GRIDVIEW
  VirtualMethod     InitRes,            HWND
  StaticMethod      Startup
  RedefineMethod    WndProc,            DWORD, WPARAM, LPARAM

  VirtualEvent      OnButtonDown,       WM_LBUTTONDOWN, WM_MBUTTONDOWN, WM_RBUTTONDOWN
  VirtualEvent      OnButtonUp,         WM_LBUTTONUP, WM_MBUTTONUP, WM_RBUTTONUP
  VirtualEvent      OnCreate,           WM_CREATE
  VirtualEvent      OnCommand,          WM_COMMAND
  VirtualEvent      OnGetFont,          WM_GETFONT
  VirtualEvent      OnMouseMove,        WM_MOUSEMOVE
  VirtualEvent      OnNCDestroy,        WM_NCDESTROY
  VirtualEvent      OnPaint,            WM_PAINT
  VirtualEvent      OnSetFont,          WM_SETFONT
  VirtualEvent      OnSetText,          WM_SETTEXT

  DefineVariable    dFlags,             DWORD,      0     ;Ressource creation?
  DefineVariable    hParent,            HWND,       0
  DefineVariable    hMemDC,             HDC,        0     ;Memory DC
  DefineVariable    hMemBmp,            HBITMAP,    0     ;Memory DC bitmap
  DefineVariable    hPrvBmp,            HBITMAP,    0     ;Previous hMemDC bitmap
  DefineVariable    hPrvBrush,          HBRUSH,     0     ;Previous hMemDC brush
  DefineVariable    hPrvFont,           HFONT,      0     ;Previous hMemDC font
  DefineVariable    Extent,             POINT,      {}    ;Size of the control (ClientRect)
  DefineVariable    Origin,             POINT,      {}

  DefineVariable    DefaultTextColor,   RGBQUAD,    {}    ;B,G,R,0
  DefineVariable    DefaultBackColor,   RGBQUAD,    {}    ;B,G,R,0
  DefineVariable    pDefaultFontFace,   PSTRING,    NULL
  DefineVariable    dDefaultFontSize,   DWORD,      10
  DefineVariable    hToolTip,           HWND,       0

  Embed    GVCols,         DataCollection
  Embed    GVRows,         DataCollection
  Embed    GVCells,        DataCollection
ObjectEnd


; ==================================================================================================

if IMPLEMENT

;Column states
GVCS_SELECTED   equ   BIT00

;Column flags
GVCF_AUTOSIZE   equ   BIT00

GV_COL_DESCRIPTOR struc
  cContent      PSTRING     ?
  dState        DWORD       ?
  dFlags        DWORD       ?
  ForeColor     RGBQUAD     <>
  BackColor     RGBQUAD     <>
  dWidth        DWORD       ?
  Area          RECT        <>
GV_COL_DESCRIPTOR ends
PGV_COL_DESCRIPTOR typedef ptr GV_COL_DESCRIPTOR

GV_ROW_DESCRIPTOR struc
  cContent      PSTRING     ?
  dState        DWORD       ?
  dFlags        DWORD       ?
  ForeColor     RGBQUAD     <>
  BackColor     RGBQUAD     <>
  dWidth        DWORD       ?
  Area          RECT        <>
GV_ROW_DESCRIPTOR ends
PGV_ROW_DESCRIPTOR typedef ptr GV_ROW_DESCRIPTOR

GV_CELL_DESCRIPTOR struc
  cContent      PSTRING     ?
  dState        DWORD       ?
  dFlags        DWORD       ?
  ForeColor     RGBQUAD     <>
  BackColor     RGBQUAD     <>
  Area          RECT        <>
GV_CELL_DESCRIPTOR ends
PGV_CELL_DESCRIPTOR typedef ptr GV_CELL_DESCRIPTOR


.code
; --------------------------------------------------------------------------------------------------
; Method:     GridView.Dispatch
; Purpose:    Dispatching of window messages.
; Arguments:  Arg1: Window handle.
;             Arg2: Message identifier.
;             Arg3: First message parameter.
;             Arg4: Second message parameter.
; Return:     eax = This value is the result of the message processing and depends on the message.

Method GridView.Dispatch, uses xsi, hWnd:HWND, uMsg:DWORD, wParam:WPARAM, lParam:LPARAM
;  DbgMessage uMsg
  SetObject xsi
  DispatchEvent <DefWindowProc, hWnd>                   ;xsi -> Object instance
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     GridView.Done
; Purpose:    Finalize the Button object.
; Arguments:  None.
; Return:     Nothing.

Method GridView.Done, uses xsi
  SetObject xsi
;  invoke StrDispose, [xsi].pMarkupText
;
;  invoke SelectObject, [xsi].hMemDC, [xsi].hPrvBmp
;  invoke SelectObject, [xsi].hMemDC, [xsi].hPrvBrush
;  invoke SelectObject, [xsi].hMemDC, [xsi].hPrvFont
;  invoke DeleteDC, [xsi].hMemDC
;
;  OCall [xsi].CoverTasks::DataCollection.Done
;  OCall [xsi].GdiObjects::XWCollection.Done
;  OCall [xsi].TVTabStops::DataCollection.Done
;  OCall [xsi].ActiveTVAreas::DataCollection.Done
;  OCall [xsi].TVStyleStack::XWCollection.Done
;  OCall [xsi].TVStyles::DataCollection.Done
;  OCall [xsi].TVAreas::DataCollection.Done
;
;  invoke DestroyWindow, [xsi].hToolTip

  invoke SetWindowLong, [xsi].hWnd, GWL_USERDATA, NULL

  ACall xsi.Done
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     GridView.Init
; Purpose:    Initialize the GridView object.
; Arguments:  Arg1: -> Owner object.
;             Arg2: Parent window HANDLE.
;             Arg3: -> Definition structure.
; Return:     Nothing.

Method GridView.Init, uses xbx xsi, pOwner:POINTER, hParent:HWND, pDefStruc:PDEF_GRIDVIEW
;  DbgText "GridView.Init"
  SetObject xsi
  m2m [xsi].hParent, hParent, xax
  mov xbx, pDefStruc
  assume xbx:PDEF_GRIDVIEW
  mov eax, [xbx].dStyle
  or eax, WS_CHILD or WS_VISIBLE
  invoke CreateWindowEx, [xbx].dExStyle, offset(szGridViewClass), [xbx].pTitle, \
                         eax, [xbx].sdPosX, [xbx].sdPosY, [xbx].dWidth, [xbx].dHeight, \
                         hParent, [xbx].xCtlID, hInstance, pSelf
  assume xbx:NOTHING
  ACall xsi.Init, pOwner, xax
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     GridView.InitRes
; Purpose:    Initialize the GridView object from a resource.
; Arguments:  Arg1: GridView window handle.
; Return:     Nothing.
; Note:       WM_GETOBJECTINSTANCE may fail if the dialog has not processed WM_INITDIALOG yet.

Method GridView.InitRes, uses xsi, hWnd:HWND
  SetObject xsi
  invoke GetParent, hWnd
  mov [xsi].hParent, xax
  .if xax != 0
    invoke SendMessage, xax, WM_GETOBJECTINSTANCE, 0, 0 ;Get instance POINTER of the parent object
  .endif
  ACall xsi.Init, xax, hWnd
  BitSet [xsi].dFlags, GVWF_RESOURCE
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     GridView.OnButtonDown
; Purpose:    Event procedure for WM_XBUTTONDOWN message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero.

Method GridView.OnButtonDown, uses xsi, wParam:WPARAM, lParam:LPARAM
;  local AppNotification:TVNM_APP, xCtrlID:XWORD

;  DbgText "GridView.OnButtonDown"
;  SetObject xsi
;  mov xax, lParam
;  OCall xsi.GetActiveArea, eax
;  .if xax != NULL
;;    DbgDec [xax].TVAREA.dValue, "Mouse button down over active area"
;    m2m AppNotification.dID, [xax].TVAREA.dValue, ecx
;    mov xCtrlID, $invoke(GetMenu, [xsi].hWnd)
;    m2m AppNotification.Header.hwndFrom, [xsi].hWnd, xax
;    m2m AppNotification.Header.idFrom, xCtrlID, xax
;    mov AppNotification.Header.code, TVNMC_APP_MOUSEDOWN
;    mov xax, wParam
;    mov AppNotification.dButton, eax
;    invoke SendMessage, [xsi].hParent, WM_NOTIFY, xCtrlID, addr AppNotification
;  .endif
  xor eax, eax
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     GridView.OnButtonUp
; Purpose:    Event procedure for WM_XBUTTONUP message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero.

Method GridView.OnButtonUp, uses xsi, wParam:WPARAM, lParam:LPARAM
;  local AppNotification:TVNM_APP, xCtrlID:XWORD

;  DbgText "GridView.OnButtonUp"
;  SetObject xsi
;  mov xax, lParam
;  OCall xsi.GetActiveArea, eax
;  .if xax != NULL
;;    DbgDec [xax].TVAREA.dValue, "Mouse button up over active area"
;    m2m AppNotification.dID, [xax].TVAREA.dValue, ecx
;    mov xCtrlID, $invoke(GetMenu, [xsi].hWnd)
;    m2m AppNotification.Header.hwndFrom, [xsi].hWnd, xax
;    m2m AppNotification.Header.idFrom, xCtrlID, xax
;    mov AppNotification.Header.code, TVNMC_APP_MOUSEUP
;    mov xax, wParam
;    mov AppNotification.dButton, eax
;    invoke SendMessage, [xsi].hParent, WM_NOTIFY, xCtrlID, addr AppNotification
;  .endif
  xor eax, eax
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     GridView.OnCreate
; Purpose:    Event procedure for WM_CREATE message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero.

Method GridView.OnCreate, uses xsi, wParam:WPARAM, lParam:LPARAM
  local hDC:HDC, CRect:RECT, dStrSize:DWORD

;  DbgText "GridView.OnCreate"

  SetObject xsi
  ;Get the markuptext
  invoke GetWindowTextLength, [xsi].hWnd                ;Does not include the ZTC
  add eax, 1                                            ;Include ZTC
  mov dStrSize, eax
;  mov [xsi].pMarkupText, $invoke(StrAlloc, eax)
  invoke GetWindowText, [xsi].hWnd, xax, dStrSize       ;dStrSize must include the ZTC

  ;Initialize and customize collections
;  OCall [xsi].TVAreas::DataCollection.Init, xsi, 10, 10, COL_MAX_CAPACITY
;  OCall [xsi].TVStyles::DataCollection.Init, xsi, 10, 10, COL_MAX_CAPACITY
;  OCall [xsi].TVStyleStack::XWCollection.Init, xsi, 10, 10, COL_MAX_CAPACITY
;  OCall [xsi].ActiveTVAreas::DataCollection.Init, xsi, 10, 10, COL_MAX_CAPACITY
;  OCall [xsi].TVTabStops::DataCollection.Init, xsi, 10, 10, COL_MAX_CAPACITY
;  OCall [xsi].GdiObjects::XWCollection.Init, xsi, 10, 10, COL_MAX_CAPACITY
;  OCall [xsi].CoverTasks::DataCollection.Init, xsi, 10, 10, COL_MAX_CAPACITY
;  Override [xsi].GdiObjects::XWCollection.DestroyItem, GdiObjects.DestroyItem
;  Override [xsi].TVAreas::DataCollection.DestroyItem, TVAreas.DestroyItem
;  Override [xsi].TVTabStops::SortedDataCollection.Compare, TVTabStops.Compare

  ;Setup internal variables
  invoke GetClientRect, [xsi].hWnd, addr CRect
  m2m [xsi].Extent.x, CRect.right, xax
  m2m [xsi].Extent.y, CRect.bottom, xax
  m2m [xsi].pDefaultFontFace, $OfsCStr("Segoe UI"), xax

  ;Create memory resources
  mov hDC, $invoke(GetDC, [xsi].hParent)
  mov [xsi].hMemDC, $invoke(CreateCompatibleDC, hDC)
  invoke CreateCompatibleBitmap, hDC, [xsi].Extent.x, [xsi].Extent.y
  mov [xsi].hMemBmp, xax
  invoke ReleaseDC, [xsi].hParent, hDC
  mov [xsi].hPrvBmp, $invoke(SelectObject, [xsi].hMemDC, [xsi].hMemBmp)
  mov [xsi].hPrvFont, $invoke(GetCurrentObject, [xsi].hMemDC, OBJ_FONT)
;  mov [xsi].dLogPixY, $32($invoke(GetDeviceCaps, [xsi].hMemDC, LOGPIXELSY))

  ;Create a ToolTip window to display popup information when hoovering over an INFO area
  invoke CreateWindowEx, WS_EX_TOPMOST, $OfsCStr("tooltips_class32"), NULL, \
                         WS_POPUP or TTS_NOPREFIX or TTS_ALWAYSTIP, \
                         CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, \
                         [xsi].hWnd, NULL, hInstance, NULL
  mov [xsi].hToolTip, xax
  invoke SetWindowPos, [xsi].hToolTip, HWND_TOPMOST, 0, 0, 0, 0, \
                       SWP_NOMOVE or SWP_NOSIZE or SWP_NOACTIVATE
  invoke SendMessage, [xsi].hToolTip, TTM_SETMAXTIPWIDTH, 0, 1000

  xor eax, eax                                          ;Return zero to continue window creation
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     GridView.OnCommand
; Purpose:    Event procedure for WM_COMMAND message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = If an application processes this message, it should return zero.

Method GridView.OnCommand, uses xsi, wParam:WPARAM, lParam:LPARAM
  DbgText "GridView.OnCommand"
  SetObject xsi
  mov xax, wParam
  .if ax == IDOK
    xor eax, eax                                        ;Return zero
  .elseif ax == IDCANCEL
    xor eax, eax                                        ;Return zero
  .else
    mov eax, 1
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     GridView.OnGetFont
; Purpose:    Event procedure for WM_GETFONT message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     xax = Font handle or zero.

Method GridView.OnGetFont, uses xsi, wParam:WPARAM, lParam:LPARAM
  DbgText "GridView.OnGetFont"
  SetObject xsi
  xor eax, eax
;  .if [xsi].GdiObjects.dCount != 0
;    OCall [xsi].GdiObjects::XWCollection.ItemAt, 0
;  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     GridView.OnPaint
; Purpose:    Event procedure for WM_PAINT message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method GridView.OnPaint, uses xbx xsi, wParam:WPARAM, lParam:LPARAM
  local PS:PAINTSTRUCT, hDC:HDC, CRect:RECT

  SetObject xsi
  mov hDC, $invoke(BeginPaint, [xsi].hWnd, addr PS)
  invoke GetClientRect, [xsi].hWnd, addr CRect

  uMin [xsi].Extent.x, CRect.right, eax
  uMin [xsi].Extent.y, CRect.bottom, ebx
  sub eax, [xsi].Origin.x
  sub ebx, [xsi].Origin.y
  invoke BitBlt, hDC, 0, 0, eax, ebx, [xsi].hMemDC, [xsi].Origin.x, [xsi].Origin.y, SRCCOPY

  invoke EndPaint, [xsi].hWnd, addr PS
  xor eax, eax
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     GridView.OnMouseMove
; Purpose:    Event procedure for WM_MOUSEMOVE message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero.

Method GridView.OnMouseMove, uses xsi, wParam:WPARAM, lParam:LPARAM
;  local AppNotification:TVNM_APP, xCtrlID:XWORD
;
;;  DbgText "GridView.OnMouseMove"
;  SetObject xsi
;  mov xax, lParam
;  OCall xsi.GetActiveArea, eax
;  .if xax != NULL
;;    DbgDec [xax].TVAREA.dValue, "Mouse over active area"
;    m2m AppNotification.dID, [xax].TVAREA.dValue, ecx
;    mov xCtrlID, $invoke(GetMenu, [xsi].hWnd)
;    m2m AppNotification.Header.hwndFrom, [xsi].hWnd, xax
;    m2m AppNotification.Header.idFrom, xCtrlID, xax
;    mov AppNotification.Header.code, TVNMC_APP_MOUSEOVER
;    mov xax, wParam
;    mov AppNotification.dButton, eax
;    invoke SendMessage, [xsi].hParent, WM_NOTIFY, xCtrlID, addr AppNotification
;    invoke SetCursor, $invoke(LoadCursor, 0, IDC_HAND)
;  .else
;    invoke SetCursor, $invoke(LoadCursor, 0, IDC_ARROW)
;  .endif
  xor eax, eax
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     GridView.OnNCDestroy
; Purpose:    Event procedure for WM_NCDESTROY message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero.

Method GridView.OnNCDestroy, uses xsi, wParam:WPARAM, lParam:LPARAM
;  DbgText "GridView.OnNCDestroy"

;  SetObject xsi
;  .ifBitSet [xsi].dFlags, TVWF_RESOURCE
;    Destroy xsi
;  .endif
  xor eax, eax
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     GridView.OnSetFont
; Purpose:    Event procedure for WM_SETFONT message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     Nothing.

Method GridView.OnSetFont, uses xsi, wParam:WPARAM, lParam:LPARAM
  local LogFont:LOGFONT

  DbgText "GridView.OnSetFont"
  SetObject xsi
;  invoke GetObject, wParam, sizeof(LogFont), addr LogFont
;  .if eax != 0
;    invoke StrDispose, [xsi].pDefaultFontFace
;    mov [xsi].pDefaultFontFace, $invoke(StrNew, addr LogFont.lfFaceName)
;    OCall xsi.Reset
;    OCall xsi.Parse
;    .if lParam != FALSE
;      OCall xsi.Render
;    .endif
;  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     GridView.OnSetText
; Purpose:    Event procedure for WM_SETTEXT message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     Nothing.

Method GridView.OnSetText, uses xsi, wParam:WPARAM, lParam:LPARAM
  DbgText "GridView.OnSetText"
  SetObject xsi
  invoke DefWindowProc, [xsi].hWnd, WM_SETTEXT, wParam, lParam
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     GridView.Startup
; Purpose:    Register the GridView window class with the operating system.
; Arguments:  None.
; Return:     Nothing.

Method GridView.Startup
  local WC:WNDCLASSEX

  mov WC.cbSize, sizeof(WNDCLASSEX)
  m2z WC.style
  m2m WC.lpfnWndProc, $MethodAddr(GridView.WndProc), xax
  m2z WC.cbClsExtra
  m2z WC.cbWndExtra
  m2m WC.hInstance, hInstance, xax
  mov WC.hbrBackground, COLOR_WINDOW + 1
  m2z WC.lpszMenuName
  c2m WC.lpszClassName, offset szGridViewClass, xax
  m2z WC.hIcon
  m2z WC.hCursor
  m2z WC.hIconSm

  invoke RegisterClassEx, addr WC
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     GridView.WindowProc
; Purpose:    Dispatching of window messages.
; Arguments:  Arg1: Message identifier.
;             Arg2: First message parameter.
;             Arg3: Second message parameter.
; Return:     eax = This value is the result of the message processing and depends on the msg ID.
;             Window HANDLE is passed in pSelf (hidden parameter).

Method GridView.WndProc, uses xsi, uMsg:DWORD, wParam:WPARAM, lParam:LPARAM
;  DbgMessage uMsg, "GridView.WndProc"
  .if uMsg == WM_NCCREATE
    mov xax, lParam
    .if [xax].CREATESTRUCT.lpCreateParams == NULL
      ;If lpCreateParams is 0, then it is a resource call => Create new object instance
      mov xsi, $New(GridView)
      OCall xsi::GridView.InitRes, pSelf
    .else
      ;Init call
      mov xsi, [xax].CREATESTRUCT.lpCreateParams
      mrm [xsi].$Obj(GridView).hWnd, pSelf, xax
    .endif
    invoke SetWindowLongPtr, pSelf, GWLP_USERDATA, xsi
    OCall xsi::GridView.Dispatch, pSelf, uMsg, wParam, lParam
  .else
    invoke GetWindowLongPtr, pSelf, GWLP_USERDATA       ;if GWLP_USERDATA wasn't set,
    .if xax == NULL                                     ;GetWindowLongPtr returns NULL
      invoke DefWindowProc, pSelf, uMsg, wParam, lParam
    .else
      OCall xax::GridView.Dispatch, pSelf, uMsg, wParam, lParam
    .endif
  .endif
MethodEnd

endif
