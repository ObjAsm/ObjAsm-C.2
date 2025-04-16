; ==================================================================================================
; Title:      ElasticSkin.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm support of window elastic skin object.
; Note:       Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


ELASTICSKIN_DATA struc                  ;Data loaded from resource.
  dBmpResID           DWORD     ?       ;BMP resource ID
  TopLftRect          RECT      {}      ;Corner  (1)
  TopHorRect          RECT      {}      ;Filler  (2)
  TopRgtRect          RECT      {}      ;Corner  (3)
  RgtVerRect          RECT      {}      ;Filler  (4)
  BotRgtRect          RECT      {}      ;Corner  (5)
  BotHorRect          RECT      {}      ;Filler  (6)
  BotLftRect          RECT      {}      ;Corner  (7)
  LftVerRect          RECT      {}      ;Filler  (8)
  TitleRect           RECT      {}      ;Rect    (9)
  WindowMinSize       POINT     {}      ;Minimum allowed window size
  WindowMaxSize       POINT     {}      ;Maximum allowed window size
  dClientBkgndColor   DWORD     ?       ;RGB value
  dTransparentColor   DWORD     ?       ;RGB value
ELASTICSKIN_DATA ends
PELASTICSKIN_DATA typedef ptr ELASTICSKIN_DATA

; --------------------------------------------------------------------------------------------------
; Object:   ElasticSkin
; Purpose:  Implement a window skinning object.
;           It uses the following reginon layout:
;
;    ---------------------------------------------------
;    |      ¦               2                ¦         |       1 Top Left corner
;    |   1  ¦--------------------------------¦    3    |       2 Top Horizontal filler
;    |      ¦               9                ¦         |       3 Top Right corner
;    |-------------------------------------------------|       4 Right Vertical Filler
;    |   ¦                                       ¦     |       5 Bottom Right corner
;    |   ¦                                       ¦     |       6 Bottom Horizontal filler
;    | 8 ¦                 10                    ¦  4  |       7 Bottom Left corner
;    |   ¦                                       ¦     |       8 Left Vertical filler
;    |   ¦                                       ¦     |       9 Title area => TitleRect
;    |-------------------------------------------------|      10 User area => UserRect
;    |          ¦                              ¦       |
;    |     7    ¦              6               ¦   5   |      Note: The whole surface is contained
;    |          ¦                              ¦       |            in the window client RECT.
;    ---------------------------------------------------

Object ElasticSkin, ElasticSkinID, MsgInterceptor
  RedefineMethod    Done
  RedefineMethod    Init,               POINTER, HWND, POINTER, DWORD
  RedefineMethod    WndProc,            DWORD, WPARAM, LPARAM
  Private
  VirtualMethod     SetWindowRegion,    DWORD

  VirtualEvent      OnEraseBkgnd,       WM_ERASEBKGND
  VirtualEvent      OnGetMinMaxInfo,    WM_GETMINMAXINFO
  VirtualEvent      OnNcHitTest,        WM_NCHITTEST
  VirtualEvent      OnNcPaint,          WM_NCPAINT

  DefineVariable    SkinData,           ELASTICSKIN_DATA, {}
  DefineVariable    hSkinDC,            HDC,              0
  DefineVariable    hPrvSkinBmp,        HBITMAP,          0
  DefineVariable    hSkinBmp,           HBITMAP,          0
  DefineVariable    LastWndSize,        POINT,            { 0, 0}
  DefineVariable    TitleRect,          RECT,             { 0, 0, 0, 0}
  DefineVariable    UserRect,           RECT,             { 0, 0, 0, 0}
  DefineVariable    dSizableWnd,        DWORD,            FALSE

  DefineVariable    hTopLftRgn,         HRGN,             0
  DefineVariable    hTopRgtRgn,         HRGN,             0
  DefineVariable    hBotLftRgn,         HRGN,             0
  DefineVariable    hBotRgtRgn,         HRGN,             0

  DefineVariable    hCurTopRgtRgn,      HRGN,             0
  DefineVariable    hCurBotLftRgn,      HRGN,             0
  DefineVariable    hCurBotRgtRgn,      HRGN,             0
  DefineVariable    hCurLftVerRgn,      HRGN,             0
  DefineVariable    hCurRgtVerRgn,      HRGN,             0
  DefineVariable    hCurTopHorRgn,      HRGN,             0
  DefineVariable    hCurBotHorRgn,      HRGN,             0

ObjectEnd


; ==================================================================================================

if IMPLEMENT

CStr szElasticSkinIptorProp, "ElasticSkinIptor"

externdef hInstance:HANDLE

; --------------------------------------------------------------------------------------------------
; Method:     ElasticSkin.Done
; Purpose:    Finalize the ElasticSkin object.
; Arguments:  None.
; Return:     Nothing.

Method ElasticSkin.Done, uses xsi
  SetObject xsi
  invoke DeleteObject, [xsi].hTopLftRgn
  invoke DeleteObject, [xsi].hTopRgtRgn
  invoke DeleteObject, [xsi].hBotLftRgn
  invoke DeleteObject, [xsi].hBotRgtRgn

  invoke DeleteObject, [xsi].hCurTopRgtRgn
  invoke DeleteObject, [xsi].hCurBotLftRgn
  invoke DeleteObject, [xsi].hCurBotRgtRgn
  invoke DeleteObject, [xsi].hCurLftVerRgn
  invoke DeleteObject, [xsi].hCurRgtVerRgn
  invoke DeleteObject, [xsi].hCurTopHorRgn
  invoke DeleteObject, [xsi].hCurBotHorRgn

  invoke DeleteObject, $invoke(SelectObject, [xsi].hSkinDC, [xsi].hPrvSkinBmp)
  invoke DeleteDC, [xsi].hSkinDC
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     ElasticSkin.Init
; Purpose:    Initialize the ElasticSkin object.
; Arguments:  Arg1: -> Owner object.
;             Arg2: Intercepted window HANDLE.
;             Arg4: Skin resource name.
;             Arg3: Sizable flag.
; Return:     Nothing.

MakeSkinCornerRgn macro RgnName:req
  invoke CreateCompatibleBitmap, [xsi].hSkinDC, \
                                 [xsi].SkinData.&RgnName&Rect.right, \
                                 [xsi].SkinData.&RgnName&Rect.bottom
  mov xbx, xax
  mov hPrvMemBmp, $invoke(SelectObject, hMemDC, xax)
  invoke BitBlt, hMemDC, 0, 0, \
                 [xsi].SkinData.&RgnName&Rect.right, [xsi].SkinData.&RgnName&Rect.bottom, \
                 [xsi].hSkinDC, \
                 [xsi].SkinData.&RgnName&Rect.left, [xsi].SkinData.&RgnName&Rect.top, SRCCOPY
  mov [xsi].h&RgnName&Rgn, $invoke(Bmp2Rgn, xbx, [xsi].SkinData.dTransparentColor)
  invoke DeleteObject, $invoke(SelectObject, hMemDC, hPrvMemBmp)
endm

Method ElasticSkin.Init, uses xbx xsi, pOwner:POINTER, hWnd:HWND, pSkinRes:POINTER, dSizableWnd:DWORD
  local hDC:HDC, hMemDC:HDC, hPrvMemBmp:HBITMAP         ;Don't change this line!

  ANNOTATION use:hPrvMemBmp                             ;hPrvMemBmp is used by macros

  SetObject xsi
  ACall xsi.Init, pOwner, hWnd, offset szElasticSkinIptorProp
  m2m [xsi].dSizableWnd, dSizableWnd, eax
  ;Load skin
  invoke FindResource, hInstance, $OfsCStr("SKIN"), pSkinRes
  .if xax != NULL
    ;Load the Resource
    invoke LoadResource, hInstance, xax
    .if xax != NULL
      ;Copy the resource info
      mov xbx, xax
      invoke MemClone, addr [xsi].SkinData, xax, sizeof ELASTICSKIN_DATA
      invoke FreeResource, xbx
      mov edx, [xsi].SkinData.dBmpResID
      mov [xsi].hSkinBmp, $invoke(LoadBitmap, hInstance, xdx)
      mov hDC, $invoke(GetDC, 0)
      mov [xsi].hSkinDC, $invoke(CreateCompatibleDC, hDC)
      invoke ReleaseDC, 0, hDC
      mov [xsi].hPrvSkinBmp, $invoke(SelectObject, [xsi].hSkinDC, [xsi].hSkinBmp)

      ;Create skin reginons
      mov hMemDC, $invoke(CreateCompatibleDC, [xsi].hSkinDC)

      ;Make corner regions (don't change)
      MakeSkinCornerRgn TopLft
      MakeSkinCornerRgn TopRgt
      MakeSkinCornerRgn BotLft
      MakeSkinCornerRgn BotRgt

      ;Initialize current regions (Don't initialize hCurTopLftRgn, it doesn't exist!)
      mov [xsi].hCurTopRgtRgn, $invoke(CreateRectRgn, 0, 0, 0, 0)
      mov [xsi].hCurBotLftRgn, $invoke(CreateRectRgn, 0, 0, 0, 0)
      mov [xsi].hCurBotRgtRgn, $invoke(CreateRectRgn, 0, 0, 0, 0)

      invoke DeleteDC, hMemDC
    .endif
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     ElasticSkin.OnEraseBkgnd
; Purpose:    Processing of WM_ERASEBKGND message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Non zero.

Method ElasticSkin.OnEraseBkgnd, uses xsi, wParam:WPARAM, lParam:LPARAM
  local hBrush:HBRUSH

  SetObject xsi
  mov hBrush, $invoke(CreateSolidBrush, [xsi].SkinData.dClientBkgndColor)
  invoke FillRect, wParam, addr [xsi].UserRect, hBrush
  invoke DeleteObject, hBrush
  xor eax, eax
  inc eax
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     ElasticSkin.OnGetMinMaxInfo
; Purpose:    Processing of WM_GETMINMAXINFO message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero.

Method ElasticSkin.OnGetMinMaxInfo,, wParam:WPARAM, lParam:LPARAM
  SetObject xcx
  mov xdx, lParam
  s2s [xdx].MINMAXINFO.ptMinTrackSize, [xcx].SkinData.WindowMinSize, xax
  .if [xcx].SkinData.WindowMaxSize.x != -1
    m2m [xdx].MINMAXINFO.ptMaxTrackSize.x, [xcx].SkinData.WindowMaxSize.x, eax
  .endif
  .if [xcx].SkinData.WindowMaxSize.y != -1
    m2m [xdx].MINMAXINFO.ptMaxTrackSize.y, [xcx].SkinData.WindowMaxSize.y, eax
  .endif
  xor eax, eax
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     ElasticSkin.OnNcHitTest
; Purpose:    Processing of WM_NCHITTEST message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Hit region handle.
; Note:       Win98 doesn't return always TRUE for a positive PtInRegion call => Check for
;             not FALSE.

Method ElasticSkin.OnNcHitTest, uses xsi, wParam:WPARAM, lParam:LPARAM
  local Pnt:POINT, Rct:RECT

  SetObject xsi
  invoke GetWindowRect, [xsi].hWnd, addr Rct
  mov xax, lParam                 ;Convert clicked X position relative to the window frame
  cwde
  sub eax, Rct.left
  mov Pnt.x, eax

  mov xax, lParam                 ;Convert clicked Y position relative to the window frame
  shr eax, 16
  cwde
  sub eax, Rct.top
  mov Pnt.y, eax

  .if $invoke(PtInRect, addr [xsi].TitleRect, Pnt) != FALSE
    mov eax, HTCAPTION
  .else
    .if [xsi].dSizableWnd == FALSE
      ;Default processing
      invoke CallWindowProc, [xsi].pPrevWndProc, [xsi].hWnd, WM_NCHITTEST, wParam, lParam
    .else
      .if $invoke(PtInRegion, [xsi].hTopLftRgn, Pnt.x, Pnt.y) != FALSE
        mov eax, HTTOPLEFT
      .else
        .if $invoke(PtInRegion, [xsi].hCurTopRgtRgn, Pnt.x, Pnt.y) != FALSE
          mov eax, HTTOPRIGHT
        .else
          .if $invoke(PtInRegion, [xsi].hCurBotRgtRgn, Pnt.x, Pnt.y) != FALSE
            mov eax, HTBOTTOMRIGHT
          .else
            .if $invoke(PtInRegion, [xsi].hCurBotLftRgn, Pnt.x, Pnt.y) != FALSE
              mov eax, HTBOTTOMLEFT
            .else
              .if $invoke(PtInRegion, [xsi].hCurTopHorRgn, Pnt.x, Pnt.y) != FALSE
                mov eax, HTTOP
              .else
                .if $invoke(PtInRegion, [xsi].hCurBotHorRgn, Pnt.x, Pnt.y) != FALSE
                  mov eax, HTBOTTOM
                .else
                  .if $invoke(PtInRegion, [xsi].hCurRgtVerRgn, Pnt.x, Pnt.y) != FALSE
                    mov eax, HTRIGHT
                  .else
                    .if $invoke(PtInRegion, [xsi].hCurLftVerRgn, Pnt.x, Pnt.y) != FALSE
                      mov eax, HTLEFT
                    .else
                      ;Default processing
                      invoke CallWindowProc, [xsi].pPrevWndProc, [xsi].hWnd, WM_NCHITTEST, \
                                             wParam, lParam
                    .endif
                  .endif
                .endif
              .endif
            .endif
          .endif
        .endif
      .endif
    .endif
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     ElasticSkin.OnNcPaint
; Purpose:    Processing of WM_NCPAINT message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method ElasticSkin.OnNcPaint, uses xbx xsi, wParam:WPARAM, lParam:LPARAM
  local hDC:HDC, Rct:RECT

  SetObject xsi

  OCall xsi.SetWindowRegion, TRUE

  mov hDC, $invoke(GetWindowDC, [xsi].hWnd)
  invoke GetClientRect, [xsi].hWnd, addr Rct

  ;Draw the Top Left Corner
  invoke BitBlt, hDC, 0, 0, [xsi].SkinData.TopLftRect.right, [xsi].SkinData.TopLftRect.bottom, \
                 [xsi].hSkinDC, 0, 0, SRCCOPY

  ;Draw the Top Right Corner
  mov eax, Rct.right
  sub eax, [xsi].SkinData.TopRgtRect.right
  invoke BitBlt, hDC, eax, 0, [xsi].SkinData.TopRgtRect.right, [xsi].SkinData.TopRgtRect.bottom, \
               [xsi].hSkinDC, [xsi].SkinData.TopRgtRect.left, [xsi].SkinData.TopRgtRect.top, SRCCOPY

  ;Draw the Bottom Right Corner
  mov edx, Rct.right
  sub edx, [xsi].SkinData.BotRgtRect.right
  mov ebx, Rct.bottom
  sub ebx, [xsi].SkinData.BotRgtRect.bottom
  invoke BitBlt, hDC, edx, ebx, [xsi].SkinData.BotRgtRect.right, [xsi].SkinData.BotRgtRect.bottom, \
               [xsi].hSkinDC, [xsi].SkinData.BotRgtRect.left, [xsi].SkinData.BotRgtRect.top, SRCCOPY

  ;Draw the Bottom Left Corner
  invoke BitBlt, hDC, 0, ebx, [xsi].SkinData.BotLftRect.right, [xsi].SkinData.BotLftRect.bottom, \
               [xsi].hSkinDC, [xsi].SkinData.BotLftRect.left, [xsi].SkinData.BotLftRect.top, SRCCOPY

  ;Draw the Top Horizontal Filler & Title background
  mov eax, Rct.right
  sub eax, [xsi].SkinData.TopLftRect.right
  sub eax, [xsi].SkinData.TopRgtRect.right
  mov ebx, [xsi].SkinData.TopHorRect.bottom
  add ebx, [xsi].SkinData.TitleRect.bottom
  invoke StretchBlt, hDC, [xsi].SkinData.TopHorRect.left, [xsi].SkinData.TopHorRect.top, eax, ebx, \
                     [xsi].hSkinDC, [xsi].SkinData.TopHorRect.left, [xsi].SkinData.TopHorRect.top, \
                     [xsi].SkinData.TopHorRect.right, ebx, SRCCOPY

  ;Draw the Bottom Horizontal Filler
  mov eax, Rct.right
  sub eax, [xsi].SkinData.BotLftRect.right
  sub eax, [xsi].SkinData.BotRgtRect.right
  mov ebx, Rct.bottom
  sub ebx, [xsi].SkinData.BotHorRect.bottom
  invoke StretchBlt, hDC, [xsi].SkinData.BotHorRect.left, ebx, \
                     eax, [xsi].SkinData.BotHorRect.bottom, \
                     [xsi].hSkinDC, [xsi].SkinData.BotHorRect.left, [xsi].SkinData.BotHorRect.top, \
                     [xsi].SkinData.BotHorRect.right, [xsi].SkinData.BotHorRect.bottom, SRCCOPY

  ;Draw the Left Vertical Filler
  mov ebx, Rct.bottom
  sub ebx, [xsi].SkinData.TopLftRect.bottom
  sub ebx, [xsi].SkinData.BotLftRect.bottom
  invoke StretchBlt, hDC, [xsi].SkinData.LftVerRect.left, [xsi].SkinData.LftVerRect.top, \
                     [xsi].SkinData.LftVerRect.right, ebx, \
                     [xsi].hSkinDC, [xsi].SkinData.LftVerRect.left, [xsi].SkinData.LftVerRect.top, \
                     [xsi].SkinData.LftVerRect.right, [xsi].SkinData.LftVerRect.bottom, SRCCOPY

  ;Draw the Right Vertical Filler
  mov eax, Rct.right
  sub eax, [xsi].SkinData.RgtVerRect.right
  mov ebx, Rct.bottom
  sub ebx, [xsi].SkinData.TopRgtRect.bottom
  sub ebx, [xsi].SkinData.BotRgtRect.bottom
  invoke StretchBlt, hDC, eax, [xsi].SkinData.RgtVerRect.top, \
                     [xsi].SkinData.RgtVerRect.right, ebx, \
                     [xsi].hSkinDC, [xsi].SkinData.RgtVerRect.left, [xsi].SkinData.RgtVerRect.top, \
                     [xsi].SkinData.RgtVerRect.right, [xsi].SkinData.RgtVerRect.bottom, SRCCOPY

  invoke ReleaseDC, [xsi].hWnd, hDC
  invoke CallWindowProc, [xsi].pPrevWndProc, [xsi].hWnd, WM_NCPAINT, wParam, lParam
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     ElasticSkin.SetWindowRegion
; Purpose:    Create and apply a region for the window based on the loaded bitmap.
; Arguments:  Arg1: Redraw flag.
; Return:     Nothing.

Method ElasticSkin.SetWindowRegion, uses xbx xsi, dRedrawFlag:DWORD
  local Rct:RECT, hAuxRgn:HRGN, dChangeWidth:DWORD, dChangeHeight:DWORD

  SetObject xsi
  ;Get window extend
  invoke GetClientRect, [xsi].hWnd, addr Rct

  mov eax, Rct.right
  mov ecx, Rct.bottom
  .if eax != [xsi].LastWndSize.x
    mov dChangeWidth, TRUE
  .else
    m2z dChangeWidth
  .endif
  .if ecx != [xsi].LastWndSize.y
    mov dChangeHeight, TRUE
  .else
    m2z dChangeHeight
  .endif

  .if (dChangeWidth == FALSE) && (dChangeHeight == FALSE)
    ExitMethod
  .else
    mov [xsi].LastWndSize.x, eax
    mov [xsi].LastWndSize.y, ecx
  .endif

  ;Determine the UserRect area
  m2m [xsi].UserRect.top, [xsi].SkinData.TopLftRect.bottom, eax
  m2m [xsi].UserRect.left, [xsi].SkinData.LftVerRect.right, edx
  mov eax, Rct.right
  sub eax, [xsi].SkinData.RgtVerRect.right
  mov [xsi].UserRect.right, eax
  mov ecx, Rct.bottom
  sub ecx, [xsi].SkinData.BotHorRect.bottom
  mov [xsi].UserRect.bottom, ecx

  mov hAuxRgn, $invoke(CreateRectRgn, 0, 0, 0, 0)

  .if dChangeWidth == TRUE
    ;Determine the TitleRect area
    mrm [xsi].TitleRect.top, [xsi].SkinData.TitleRect.top, edx
    mrm [xsi].TitleRect.left, [xsi].SkinData.TitleRect.left, edx
    mov eax, Rct.right
    sub eax, [xsi].SkinData.TopRgtRect.right
    mov [xsi].TitleRect.right, eax
    mov ecx, [xsi].SkinData.TitleRect.top
    add ecx, [xsi].SkinData.TitleRect.bottom
    mov [xsi].TitleRect.bottom, ecx

    ;Create Top Right corner region
    invoke CombineRgn, hAuxRgn, [xsi].hTopRgtRgn, 0, RGN_COPY
    mov eax, Rct.right
    sub eax, [xsi].SkinData.TopRgtRect.right
    invoke OffsetRgn, hAuxRgn, eax, 0
    invoke CombineRgn, [xsi].hCurTopRgtRgn, hAuxRgn, 0, RGN_COPY
  .endif

  .if dChangeHeight == TRUE
    ;Create Bottom Left corner region
    invoke CombineRgn, hAuxRgn, [xsi].hBotLftRgn, 0, RGN_COPY
    mov ebx, Rct.bottom
    sub ebx, [xsi].SkinData.BotLftRect.bottom
    invoke OffsetRgn, hAuxRgn, 0, ebx
    invoke CombineRgn, [xsi].hCurBotLftRgn, hAuxRgn, 0, RGN_COPY
  .endif

  ;Create Bottom Right corner region
  invoke CombineRgn, hAuxRgn, [xsi].hBotRgtRgn, 0, RGN_COPY
  mov edx, Rct.right
  sub edx, [xsi].SkinData.BotRgtRect.right
  mov ebx, Rct.bottom
  sub ebx, [xsi].SkinData.BotRgtRect.bottom
  invoke OffsetRgn, hAuxRgn, edx, ebx
  invoke CombineRgn, [xsi].hCurBotRgtRgn, hAuxRgn, 0, RGN_COPY

  invoke DeleteObject, hAuxRgn

; /////////////////////////////////////////////////////////////////////////////////////////////////

  .if dChangeWidth == TRUE
    ;Create Top Horizontal filler region
    .if [xsi].hCurTopHorRgn
      invoke DeleteObject, [xsi].hCurTopHorRgn
    .endif
    mov ebx, [xsi].SkinData.TopHorRect.top
    .while ebx < [xsi].SkinData.TopHorRect.bottom
      invoke GetPixel, [xsi].hSkinDC, [xsi].SkinData.TopHorRect.left, ebx
      .break .if eax != [xsi].SkinData.dTransparentColor
      inc ebx
    .endw
    mov eax, Rct.right
    sub eax, [xsi].SkinData.TopRgtRect.right
    invoke CreateRectRgn, [xsi].SkinData.TopHorRect.left, ebx, eax, [xsi].SkinData.TopHorRect.bottom
    mov [xsi].hCurTopHorRgn, xax
  .endif

  .if dChangeHeight == TRUE
    ;Create Left Vertical filler region
    .if [xsi].hCurLftVerRgn
      invoke DeleteObject, [xsi].hCurLftVerRgn
    .endif
    mov ebx, [xsi].SkinData.LftVerRect.left
    .while ebx < [xsi].SkinData.LftVerRect.right
      invoke GetPixel, [xsi].hSkinDC, ebx, [xsi].SkinData.LftVerRect.top
      .break .if eax != [xsi].SkinData.dTransparentColor
      inc ebx
    .endw
    mov eax, Rct.bottom
    sub eax, [xsi].SkinData.BotLftRect.bottom
    invoke CreateRectRgn, ebx, [xsi].SkinData.LftVerRect.top, [xsi].SkinData.LftVerRect.right, eax
    mov [xsi].hCurLftVerRgn, xax
  .endif

  ;Create Bottom Horizontal filler region
  .if [xsi].hCurBotHorRgn
    invoke DeleteObject, [xsi].hCurBotHorRgn
  .endif
  mov ebx, [xsi].SkinData.BotHorRect.top
  add ebx, [xsi].SkinData.BotHorRect.bottom
  .while ebx > [xsi].SkinData.TopHorRect.top
    dec ebx
    invoke GetPixel, [xsi].hSkinDC, [xsi].SkinData.BotHorRect.left, ebx
    .break .if eax != [xsi].SkinData.dTransparentColor
  .endw
  inc ebx
  mov eax, Rct.right
  sub eax, [xsi].SkinData.BotRgtRect.right
  mov edx, Rct.bottom
  sub edx, [xsi].SkinData.BotHorRect.bottom
  sub ebx, [xsi].SkinData.BotHorRect.top
  add ebx, edx
  invoke CreateRectRgn, [xsi].SkinData.BotHorRect.left, edx, eax, ebx
  mov [xsi].hCurBotHorRgn, xax

  ;Create Right Vertical filler region
  .if [xsi].hCurRgtVerRgn
    invoke DeleteObject, [xsi].hCurRgtVerRgn
  .endif
  mov ebx, [xsi].SkinData.RgtVerRect.left
  add ebx, [xsi].SkinData.RgtVerRect.right
  .while ebx > [xsi].SkinData.RgtVerRect.left
    dec ebx
    invoke GetPixel, [xsi].hSkinDC, ebx, [xsi].SkinData.RgtVerRect.top
    .break .if eax != [xsi].SkinData.dTransparentColor
  .endw
  inc ebx
  mov ecx, Rct.right
  sub ecx, [xsi].SkinData.RgtVerRect.right
  mov eax, Rct.bottom
  sub eax, [xsi].SkinData.BotRgtRect.bottom
  sub ebx, [xsi].SkinData.RgtVerRect.left
  add ebx, ecx
  invoke CreateRectRgn, ecx, [xsi].SkinData.RgtVerRect.top, ebx, eax
  mov [xsi].hCurRgtVerRgn, xax

  ;Create a region for the UserRect
  mov xbx, $invoke(CreateRectRgnIndirect, addr [xsi].UserRect)

  ;Create a region for the TitleRect
  mov hAuxRgn, $invoke(CreateRectRgnIndirect, addr [xsi].TitleRect)

  ;Append all created regions and assign it to the window
  invoke CombineRgn, xbx, xbx, hAuxRgn, RGN_OR
  invoke CombineRgn, xbx, xbx, [xsi].hTopLftRgn, RGN_OR
  invoke CombineRgn, xbx, xbx, [xsi].hCurTopRgtRgn, RGN_OR
  invoke CombineRgn, xbx, xbx, [xsi].hCurBotRgtRgn, RGN_OR
  invoke CombineRgn, xbx, xbx, [xsi].hCurBotLftRgn, RGN_OR
  invoke CombineRgn, xbx, xbx, [xsi].hCurTopHorRgn, RGN_OR
  invoke CombineRgn, xbx, xbx, [xsi].hCurBotHorRgn, RGN_OR
  invoke CombineRgn, xbx, xbx, [xsi].hCurLftVerRgn, RGN_OR
  invoke CombineRgn, xbx, xbx, [xsi].hCurRgtVerRgn, RGN_OR

  invoke DeleteObject, hAuxRgn
  invoke SetWindowRgn, [xsi].hWnd, xbx, dRedrawFlag
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     ElasticSkin.WndProc
; Purpose:    Processing of window messages.
; Arguments:  Arg1: Message identifier.
;             Arg2: First message parameter.
;             Arg3: Second message parameter.
; Return:     eax = This value is the result of the message processing and depends on the msg ID.
; Note:       Window handle is passed in pSelf (hidden parameter).

Method ElasticSkin.WndProc,, uMsg:DWORD, wParam:WPARAM, lParam:LPARAM
;  DbgMessage uMsg
  invoke GetProp, pSelf, offset szElasticSkinIptorProp  ;pSelf = hWnd
  OCall xax::ElasticSkin.Dispatch, pSelf, uMsg, wParam, lParam
MethodEnd

endif
