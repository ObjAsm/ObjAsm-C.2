; ==================================================================================================
; Title:      Hyperlink.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm support of Hyperlink objects.
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


HYPERLINK_BKGNDCOLOR   equ   0     ;Background
HYPERLINK_COLOR1       equ   1     ;Normal color
HYPERLINK_COLOR2       equ   2     ;Visited color

DEF_HYPERLINK   textequ <DEF_BUTTON>
PDEF_HYPERLINK  textequ <PDEF_BUTTON>


; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Object:     Hyperlink
; Purpose:    Implent a thin wrapper around the GDI Hyperlink control.
; Layout:
;
;          Face
;    —————————————————
;   | II |  Press Me  |
;    —————————————————
;    Icon     Text
;
; Possible Caption text format:
;
;  "Shell command"   or
;  "Icon Resource Name | Shell command"   or
;  "Icon Resource Name | Displayed Text | Shell command"   or
;  "Icon Resource Name ¦ String Resource ID"
;
; Example:
;  "ICON_LINK|Visit our Homepage|http://objasm.x10host.com//index.htm"
;  "ICON_MAIL|Send us an Email|mailto:objasm@gmx.net"
;   mailto protocol: https://msdn.microsoft.com/de-de/library/aa767737.aspx

Object Hyperlink, HyperlinkID, Button
  VirtualMethod     CreateUFont
  RedefineMethod    Done
  RedefineMethod    Init,           POINTER, HWND, PDEF_HYPERLINK
  VirtualMethod     Execute
  VirtualMethod     GetArgs
  RedefineMethod    OnCreate,       WPARAM, LPARAM
  RedefineMethod    OnDestroy,      WPARAM, LPARAM
  RedefineMethod    OnGetFont,      WPARAM, LPARAM
  RedefineMethod    OnKeyDown,      WPARAM, LPARAM
  RedefineMethod    OnLButtonDown,  WPARAM, LPARAM
  RedefineMethod    OnLButtonUp,    WPARAM, LPARAM
  RedefineMethod    OnPaint,        WPARAM, LPARAM
  RedefineMethod    OnSetFont,      WPARAM, LPARAM
  StaticMethod      Startup

  RedefineMethod    OnSetText,      WPARAM, LPARAM
  RedefineMethod    WndProc,        DWORD, WPARAM, LPARAM

  VirtualEvent      OnSetColor,     BM_SETCOLOR
  VirtualEvent      OnGetColor,     BM_GETCOLOR

  DefineVariable    hIcon,          HICON,      0
  DefineVariable    pLinkText,      PSTRING,    NULL
  DefineVariable    pLinkCommand,   PSTRING,    NULL
  DefineVariable    dColor1,        DWORD,      $RGB(000,000,255)   ;Not visited color
  DefineVariable    dColor2,        DWORD,      $RGB(128,000,128)   ;Visited color
  DefineVariable    dBkgndColor,    DWORD,      $RGB(128,128,128)   ;Default BG color
  DefineVariable    hFont,          HFONT,      0
  DefineVariable    hUFont,         HFONT,      0
ObjectEnd


; ==================================================================================================

if IMPLEMENT

HLF_VISITED   equ   BIT06

HYPERLINK_CHAR_LITERAL    equ   "|"    ;Literal marker character.
HYPERLINK_CHAR_RESOURCE   equ   "¦"    ;Resource redirctor character.

HYPERLINK_TEXT_SEPARATION  equ   6

CStr szHyperlinkClassName, "Hyperlink"

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Hyperlink.CreateUFont
; Purpose:    Create the underline font used to display the hyperlink.
; Arguments:  None.
; Return:     Nothing.

Method Hyperlink.CreateUFont, uses xsi
  local LogFnt:LOGFONT

  SetObject xsi
  .if [xsi].hUFont
    invoke DeleteObject, [xsi].hUFont                   ;Delete previous font
  .endif
  invoke GetObject, [xsi].hFont, sizeof(LogFnt), addr LogFnt  ;Retrieve attributes of normal font
  mov LogFnt.lfUnderline, TRUE                                ;Set Undeline flag
  mov [xsi].hUFont, $invoke(CreateFontIndirect, addr LogFnt)  ;Create the undelined font
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Hyperlink.Done
; Purpose:    Finalize the Hyperlink object.
; Arguments:  None.
; Return:     Nothing.

Method Hyperlink.Done, uses xsi
  SetObject xsi
  invoke DeleteObject, [xsi].hUFont                     ;Delete font; if not created => fail
  invoke StrDispose, [xsi].pLinkCommand
  invoke StrDispose, [xsi].pLinkText
  ACall xsi.Done                                        ;Execute ancestor's Done destructor
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Hyperlink.Init
; Purpose:    Initialize the Hyperlink object.
; Arguments:  Arg1: -> Owner object.
;             Arg2: Parent window HANDLE.
;             Arg3: -> DEF_HYPERLINK structure.
; Return:     Nothing.

Method Hyperlink.Init, uses xbx xsi, pOwner:POINTER, hParent:HWND, pDefStruc:PDEF_HYPERLINK
  SetObject xsi
  mov xbx, pDefStruc
  assume xbx:PDEF_HYPERLINK
  mov eax, [xbx].dStyle
  or eax, WS_CHILD or WS_VISIBLE or WS_TABSTOP       ;Set additional styles
  invoke CreateWindowEx, [xbx].dExStyle, offset szHyperlinkClassName, [xbx].pTitle, \
                         eax, [xbx].sdPosX, [xbx].sdPosY, [xbx].dWidth, [xbx].dHeight, \
                         hParent, [xbx].xCtlID, hInstance, pSelf
  assume xbx:NOTHING

  ACall xsi.Init, pOwner, xax                         ;Executes ancestor's Init constructor
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Hyperlink.Execute
; Purpose:    Execute the Hyperlink.
; Arguments:  None.
; Return:     Nothing.

Method Hyperlink.Execute, uses xsi
  SetObject xsi
  ;No parent set to allow mantaining open the browser while closeing the application.
  invoke ShellExecute, 0, $OfsCStr("open"), [xsi].pLinkCommand, NULL, NULL, SW_SHOWDEFAULT
  BitSet [xsi].dFlags, HLF_VISITED
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Hyperlink.GetArgs
; Purpose:    Extract the Icon, text and command from the caption string.
; Arguments:  None.
; Return:     Nothing.

Method Hyperlink.GetArgs, uses xbx xdi xsi
  local pPos1:POINTER, pPos2:POINTER, cBuffer[512]:CHR, xTemp:XWORD

  SetObject xsi
  xor eax, eax
  mov pPos2, xax

  lea xbx, cBuffer
  invoke StrCopy, xbx, [xsi].pTextBuffer
  invoke StrLScan, xbx, HYPERLINK_CHAR_RESOURCE         ;Resource indicator char
  .if xax != NULL
    mov CHR ptr [xax], HYPERLINK_CHAR_LITERAL
    add xax, sizeof(CHR)
    mov xdi, xax
    invoke dec2dword, xax
    mov edx, eax
    mov xax, sizeof(cBuffer)
    add xax, xbx
    sub xax, xdi
    invoke LoadString, hInstance, edx, xdi, eax
  .endif

  mov pPos1, $invoke(StrLScan, xbx, HYPERLINK_CHAR_LITERAL)     ;Literal indicator char
  .if xax != NULL
    add xax, sizeof(CHR)
    invoke StrLScan, xax, HYPERLINK_CHAR_LITERAL                ;Second Literal indicator char
    .if xax != NULL
      mov pPos2, xax
    .endif
  .endif

  .if pPos1 == NULL
     mov [xsi].pLinkText, $invoke(StrNew, xbx)
     mov [xsi].pLinkCommand, $invoke(StrNew, xbx)
  .else
    mov xcx, pPos1
    m2z CHR ptr [xcx]
    invoke LoadImage, hInstance, xbx, IMAGE_ICON, 16, 16, LR_DEFAULTCOLOR
    .if xax != 0
      .if [xsi].hIcon != 0
        mov xTemp, xax
        invoke DeleteObject, [xsi].hIcon
        mov xax, xTemp
      .endif
      mov [xsi].hIcon, xax 
    .endif
    
    add pPos1, sizeof(CHR)
    .if pPos2 == NULL
      .if [xsi].pLinkText != NULL
        invoke StrDispose, [xsi].pLinkText
      .endif
      mov [xsi].pLinkText, $invoke(StrNew, pPos1)
      .if [xsi].pLinkCommand != NULL
        invoke StrDispose, [xsi].pLinkCommand
      .endif
      mov [xsi].pLinkCommand, $invoke(StrNew, pPos1)
    .else
      mov xcx, pPos2
      m2z CHR ptr [xcx]
      add pPos2, sizeof(CHR)
      .if [xsi].pLinkText != NULL
        invoke StrDispose, [xsi].pLinkText
      .endif
      mov [xsi].pLinkText, $invoke(StrNew, pPos1)
      .if [xsi].pLinkCommand != NULL
        invoke StrDispose, [xsi].pLinkCommand
      .endif
      mov [xsi].pLinkCommand, $invoke(StrNew, pPos2)
    .endif
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Hyperlink.OnCreate
; Purpose:    Event procedure for WM_CREATE message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero to continue creation of the window, else -1.

Method Hyperlink.OnCreate, uses xsi, wParam:WPARAM, lParam:LPARAM
  local hDC:HDC, hParent:HWND

  SetObject xsi
  mov xax, lParam

  mov [xsi].pTextBuffer, $invoke(StrNew, [xax].CREATESTRUCT.lpszName)
  OCall xsi.GetArgs

  invoke GetClientRect, [xsi].hWnd, addr [xsi].FaceRect
  invoke MemClone, addr [xsi].IconRect, addr [xsi].FaceRect, sizeof(RECT)
  invoke MemClone, addr [xsi].TextRect, addr [xsi].FaceRect, sizeof(RECT)

  m2m [xsi].IconRect.right, [xsi].IconRect.bottom, eax

  m2m [xsi].TextRect.left, [xsi].IconRect.right, eax
  add [xsi].TextRect.left, HYPERLINK_TEXT_SEPARATION

  mov hParent, $invoke(GetParent, [xsi].hWnd)
  mov hDC, $invoke(GetDC, hParent)
  mov [xsi].hMemDC, $invoke(CreateCompatibleDC, hDC)
  invoke CreateCompatibleBitmap, hDC, [xsi].FaceRect.right, [xsi].FaceRect.bottom
  mov [xsi].hMemBmp, xax
  invoke ReleaseDC, hParent, hDC

  mov [xsi].hPrevBmp, $invoke(SelectObject, [xsi].hMemDC, [xsi].hMemBmp)
  xor eax, eax
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Hyperlink.OnDestroy
; Purpose:    Event procedure for WM_DESTROY message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero.

Method Hyperlink.OnDestroy, uses xsi, wParam:WPARAM, lParam:LPARAM
  SetObject xsi
  invoke DeleteObject, $invoke(SelectObject, [xsi].hMemDC, [xsi].hPrevBmp)
  invoke DeleteDC, [xsi].hMemDC
  invoke DestroyIcon, [xsi].hIcon
  xor eax, eax
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Hyperlink.OnGetColor
; Purpose:    Event procedure for BM_GETCOLOR message.
; Arguments:  Arg1: First message parameter = color index (0: Background, 1: Normal, 2: Visited).
;             Arg2: Second message parameter = not used.
; Return:     eax = Requested color.

Method Hyperlink.OnGetColor,, wParam:WPARAM, lParam:LPARAM
  SetObject xcx
  .if wParam == HYPERLINK_BKGNDCOLOR
    mov eax, [xcx].dBkgndColor
  .elseif wParam == HYPERLINK_COLOR1
    mov eax, [xcx].dColor1
  .elseif wParam == HYPERLINK_COLOR2
    mov eax, [xcx].dColor2
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Hyperlink.OnGetFont
; Purpose:    Event procedure for WM_GETFONT message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     xax = Requested font HANDLE.

Method Hyperlink.OnGetFont,, wParam:WPARAM, lParam:LPARAM
  SetObject xcx
  mov xax, [xcx].hFont
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Hyperlink.OnKeyDown
; Purpose:    Event procedure for WM_KEYDOWN message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     Zero if handled.

Method Hyperlink.OnKeyDown, uses xsi, wParam:WPARAM, lParam:LPARAM
  SetObject xsi
  mov xax, wParam
  .if $SubReg(xax, sizeof(CHR)) == " "                  ;Space was pressed!
    OCall xsi.Execute
    xor eax, eax
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Hyperlink.OnLButtonDown
; Purpose:    Event procedure for WM_LBUTTONDOWN message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero.

Method Hyperlink.OnLButtonDown, uses xsi, wParam:WPARAM, lParam:LPARAM
  local Pnt:POINT

  SetObject xsi
  .ifBitClr [xsi].dFlags, BTF_DISABLED
    PntS2Pnt Pnt, lParam
    .if $invoke(PtInRect, addr [xsi].FaceRect, Pnt) != FALSE
      invoke SetFocus, [xsi].hWnd
      BitSet [xsi].dFlags, (BTF_PRESSED or BTF_FOCUSED)
      BitClr [xsi].dFlags, BTF_HOVERED
      invoke RedrawWindow, [xsi].hWnd, NULL, NULL, RDW_UPDATENOW or RDW_INVALIDATE
    .endif
  .endif
  xor eax, eax
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Hyperlink.OnLButtonUp
; Purpose:    Event procedure for WM_LBUTTONUP message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero.

Method Hyperlink.OnLButtonUp, uses xsi, wParam:WPARAM, lParam:LPARAM
  local Pnt:POINT

  SetObject xsi
  .ifBitClr [xsi].dFlags, BTF_DISABLED
    .ifBitSet [xsi].dFlags, BTF_PRESSED
      BitClr [xsi].dFlags, (BTF_PRESSED or BTF_HOVERED)
      PntS2Pnt Pnt, lParam
      .if $invoke(PtInRect, addr [xsi].FaceRect, Pnt) != FALSE
        OCall xsi.Execute
      .else
        invoke ReleaseCapture
      .endif
      invoke RedrawWindow, [xsi].hWnd, NULL, NULL, RDW_UPDATENOW or RDW_INVALIDATE
    .endif
  .endif
  xor eax, eax
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Hyperlink.OnPaint
; Purpose:    Event procedure for WM_PAINT message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero.

HS_STYLE equ DT_LEFT or DT_VCENTER or DT_SINGLELINE or DT_END_ELLIPSIS

Method Hyperlink.OnPaint, uses xsi, wParam:WPARAM, lParam:LPARAM
  local PS:PAINTSTRUCT, dPrvColor:DWORD, dPrvBackMode:DWORD, hPrvFont:HFONT 
  local hBgBrush:HBRUSH, hStcBrush:HBRUSH

  SetObject xsi

  invoke GetParent, [xsi].hWnd
  mov hStcBrush, $invoke(SendMessage, xax, WM_CTLCOLORSTATIC, [xsi].hMemDC, [xsi].hWnd)
  .if xax == 0
    invoke CreateSolidBrush, [xsi].dBkgndColor
  .endif
  mov hBgBrush, xax

  invoke FillRect, [xsi].hMemDC, addr [xsi].FaceRect, hBgBrush
  mov edx, [xsi].IconRect.bottom
  sub edx, 16
  shr edx, 1
  invoke DrawIconEx, [xsi].hMemDC, edx, edx, [xsi].hIcon, 16, 16, 0, 0, DI_NORMAL
  invoke SetBkMode, [xsi].hMemDC, TRANSPARENT
  mov dPrvBackMode, eax
  .ifBitClr [xsi].dFlags, BTF_DISABLED
    .ifBitClr [xsi].dFlags, HLF_VISITED
      mov eax, [xsi].dColor1
    .else
      mov eax, [xsi].dColor2
    .endif
    invoke SetTextColor, [xsi].hMemDC, eax
    mov dPrvColor, eax

    .ifBitClr [xsi].dFlags, (BTF_HOVERED or BTF_PRESSED or BTF_FOCUSED)
      mov xax, [xsi].hFont
    .else
      mov xax, [xsi].hUFont
    .endif
    mov hPrvFont, $invoke(SelectObject, [xsi].hMemDC, xax)
    invoke DrawTextEx, [xsi].hMemDC, [xsi].pLinkText, -1, addr [xsi].TextRect, HS_STYLE, NULL
;    .ifBitSet [xsi].dFlags, BTF_FOCUSED
;      invoke MemClone, addr [xsi].TextRect, addr [xsi].TextRect, sizeof(RECT)
;      invoke DrawTextEx, [xsi].hMemDC, [xsi].pLinkText, -1, addr [xsi].TextRect, \
;                         DT_CALCRECT or HS_STYLE, NULL
;      GrowRect [xsi].TextRect, 1, 1
;      invoke DrawFocusRect, [xsi].hMemDC, addr [xsi].TextRect
;    .endif
  .else
    mov hPrvFont, $invoke(SelectObject, [xsi].hMemDC, [xsi].hFont)
    invoke GetSysColor, COLOR_BTNHILIGHT
    invoke SetTextColor, [xsi].hMemDC, eax
    mov dPrvColor, eax
    MoveRect [xsi].TextRect, 1
    invoke DrawTextEx, [xsi].hMemDC, [xsi].pLinkText, -1, addr [xsi].TextRect, HS_STYLE, NULL
    MoveRect [xsi].TextRect, -1
    invoke GetSysColor, COLOR_BTNSHADOW
    invoke SetTextColor, [xsi].hMemDC, eax
    invoke DrawTextEx, [xsi].hMemDC, [xsi].pLinkText, -1, addr [xsi].TextRect, HS_STYLE, NULL
    invoke SetTextColor, [xsi].hMemDC, dPrvColor
  .endif
  invoke SelectObject, PS.hdc, hPrvFont
  invoke SetBkMode, [xsi].hMemDC, dPrvBackMode

  ;Now, copy the content of the memory DC to the drawing DC.
  invoke BeginPaint, [xsi].hWnd, addr PS
  invoke BitBlt, PS.hdc, 0, 0, [xsi].FaceRect.right, [xsi].FaceRect.bottom, \
                 [xsi].hMemDC, 0, 0, SRCCOPY
  .if hStcBrush == 0
    invoke DeleteObject, hBgBrush
  .endif
  invoke EndPaint, [xsi].hWnd, addr PS
  xor eax, eax
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Hyperlink.OnSetColor
; Purpose:    Event procedure for BM_SETCOLOR message.
; Arguments:  Arg1: First message parameter = color index (0: Background, 1: Normal, 2: Visited).
;             Arg2: Second message parameter = RGB color.
; Return:     eax = Zero.

Method Hyperlink.OnSetColor, uses xsi, wParam:WPARAM, lParam:LPARAM
  SetObject xsi
  .if wParam == HYPERLINK_BKGNDCOLOR
    mov xdx, lParam
    mov [xsi].dBkgndColor, edx
  .elseif wParam == HYPERLINK_COLOR1
    mov xdx, lParam
    mov [xsi].dColor1, edx
  .elseif wParam == HYPERLINK_COLOR2
    mov xdx, lParam
    mov [xsi].dColor2, edx
  .endif
  invoke RedrawWindow, [xsi].hWnd, NULL, NULL, RDW_UPDATENOW or RDW_INVALIDATE
  xor eax, eax
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Hyperlink.OnSetFont
; Purpose:    Event procedure for WM_SETFONT message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero.

Method Hyperlink.OnSetFont, uses xsi, wParam:WPARAM, lParam:LPARAM
  SetObject xsi
  m2m [xsi].hFont, wParam, xax
  OCall CreateUFont
  .if lParam != FALSE
    invoke RedrawWindow, [xsi].hWnd, NULL, NULL, RDW_UPDATENOW or RDW_INVALIDATE
  .endif
  xor eax, eax
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Hyperlink.OnSetText
; Purpose:    Event procedure for WM_SETTEXT message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = TRUE.

Method Hyperlink.OnSetText, uses xsi, wParam:WPARAM, lParam:LPARAM
  SetObject xsi
  mov [xsi].pTextBuffer, $invoke(StrNew, lParam)
  OCall xsi.GetArgs
  invoke RedrawWindow, [xsi].hWnd, NULL, NULL, RDW_UPDATENOW or RDW_INVALIDATE
  mov eax, TRUE
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Hyperlink.Startup
; Purpose:    Register the Hyperlink window class with the operating system.
; Arguments:  None.
; Return:     Nothing.

Method Hyperlink.Startup
  local WC:WNDCLASSEX

  mov WC.cbSize, sizeof(WNDCLASSEX)
  mov WC.style, CS_HREDRAW or CS_VREDRAW or CS_PARENTDC
  m2m WC.lpfnWndProc, $MethodAddr(Hyperlink.WndProc), xax
  m2z WC.cbClsExtra
  m2z WC.cbWndExtra
  m2m WC.hInstance, hInstance, xax
  m2z WC.hbrBackground
  m2z WC.lpszMenuName
  c2m WC.lpszClassName, offset szHyperlinkClassName, xax
  m2z WC.hIcon
  mov WC.hCursor, $invoke(LoadCursor, hInstance, $OfsCStr("CURSOR_HAND"))
  m2z WC.hIconSm

  invoke RegisterClassEx, addr WC
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Hyperlink.WindowProc
; Purpose:    Processing of window messages.
; Arguments:  Arg1: Message identifier.
;             Arg2: First message parameter.
;             Arg3: Second message parameter.
; Return:     eax = This value is the result of the message processing and depends on the msg ID.
; Note:       Window HANDLE is passed in pSelf (hidden parameter).

Method Hyperlink.WndProc, uses xsi, uMsg:DWORD, wParam:WPARAM, lParam:LPARAM
;  DbgMessage uMsg
  .if uMsg == WM_NCCREATE
    mov xax, lParam
    .if [xax].CREATESTRUCT.lpCreateParams == NULL
      ;If lpCreateParams is 0, then it is a resource call => Create new object instance
      mov xsi, $New(Hyperlink)
      OCall xsi::Hyperlink.InitRes, pSelf
      mov xcx, pSelf
    .else
      ;From Init call
      mov xsi, [xax].CREATESTRUCT.lpCreateParams
      mrm [xsi].$Obj(Hyperlink).hWnd, pSelf, xcx
    .endif
    invoke SetWindowLongPtr, xcx, GWLP_USERDATA, xsi
    OCall xsi::Hyperlink.Dispatch, pSelf, uMsg, wParam, lParam
  .else
    invoke GetWindowLongPtr, pSelf, GWLP_USERDATA       ;if GWLP_USERDATA wasn't set,
    .if xax == NULL                                     ;GetWindowLong returns NULL
      invoke DefWindowProc, pSelf, uMsg, wParam, lParam
    .else
      OCall xax::Hyperlink.Dispatch, pSelf, uMsg, wParam, lParam
    .endif
  .endif
MethodEnd

endif
