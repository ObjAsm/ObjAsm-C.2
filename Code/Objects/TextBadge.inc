; ==================================================================================================
; Title:      TextBadge.inc
; Author:     G. Friedrich
; Version:    C.2.0
; Purpose:    ObjAsm support of TextBadge objects.
; Notes:      Version C.2.0, November 2025
;               - First release.
; ==================================================================================================


;Badge alignment flags
BAF_LEFT    equ   BIT00
BAF_RIGHT   equ   BIT01
BAF_CENTER  equ   BAF_LEFT or BAF_RIGHT

BAF_TOP     equ   BIT02
BAF_BOTTOM  equ   BIT03
BAF_VCENTER equ   BAF_TOP or BAF_BOTTOM

TBF_DIRTY   equ   BIT04


; --------------------------------------------------------------------------------------------------
; Object:     TextBadge
; Purpose:    This object displays a text on a badge.
;             The render is stored on a memory DC using the Draw method.
;             The Paint method alphablends it to a destination DC.

Object TextBadge, TextBadgeID, Primer
  VirtualMethod     CalcDstRect
  RedefineMethod    Done
  RedefineMethod    Init,               POINTER, HWND, COLORREF, COLORREF
  VirtualMethod     Invalidate
  VirtualMethod     Draw,               PSTRING
  VirtualMethod     Paint,              HDC, BYTE
  VirtualMethod     SetPosition,        SDWORD, SDWORD, DWORD

  DefineVariable    dFlags,             DWORD,    BAF_LEFT or BAF_TOP
  DefineVariable    hWnd,               HWND,     0
  DefineVariable    BackColor,          COLORREF, 0
  DefineVariable    ForeColor,          COLORREF, 0
  DefineVariable    RefPoint,           POINT,    {}
  DefineVariable    DstRect,            RECT,     {}
  DefineVariable    BmpSize,            POINT,    {}
  DefineVariable    hMemDC,             HDC,      0
  DefineVariable    hMemBmp,            HANDLE,   0
  DefineVariable    hPrvMemBmp,         HANDLE,   0
  DefineVariable    dFontPointSize,     DWORD,    9
  DefineVariable    LogFontText,        LOGFONT,  {0, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, DEFAULT_CHARSET, \
                                                   OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, CLEARTYPE_QUALITY, \
                                                   DEFAULT_PITCH or FF_DONTCARE, {"A","r","i","a","l",0}}
ObjectEnd


; ==================================================================================================

if IMPLEMENT

TB_BORDER equ 1     ;Amount of pixels used to border the badge. Min = 1.

; --------------------------------------------------------------------------------------------------
; Method:     TextBadge.CalcDstRect
; Purpose:    Calculate the internal DstRect coordinates.
; Arguments:  None.
; Return:     Nothing.

Method TextBadge.CalcDstRect, uses xsi
  SetObject xsi
  mov eax, [xsi].dFlags
  and eax, BAF_LEFT or BAF_RIGHT
  mov edx, [xsi].RefPoint.x
  .if eax == BAF_RIGHT
    sub edx, [xsi].BmpSize.x
  .elseif eax == BAF_LEFT or BAF_RIGHT
    mov ecx, [xsi].BmpSize.x
    shr ecx, 1
    sub edx, ecx
  .endif
  mov [xsi].DstRect.left, edx
  add edx, [xsi].BmpSize.x
  mov [xsi].DstRect.right, edx

  mov eax, [xsi].dFlags
  and eax, BAF_TOP or BAF_BOTTOM
  mov edx, [xsi].RefPoint.y
  .if eax == BAF_BOTTOM
    sub edx, [xsi].BmpSize.y
  .elseif eax == BAF_TOP or BAF_BOTTOM
    mov ecx, [xsi].BmpSize.y
    shr ecx, 1
    sub edx, ecx
  .endif
  mov [xsi].DstRect.top, edx
  add edx, [xsi].BmpSize.y
  mov [xsi].DstRect.bottom, edx
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     TextBadge.Done
; Purpose:    Finalize the TextBadge object.
; Arguments:  None.
; Return:     Nothing.

Method TextBadge.Done, uses xsi
  SetObject xsi
  invoke SelectObject, [xsi].hMemDC, [xsi].hPrvMemBmp
  invoke DeleteDC, [xsi].hMemDC
  ACall xsi.Done
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     TextBadge.Draw
; Purpose:    Draw the badge on an internal buffer.
; Arguments:  Arg1: -> pText.
; Return:     Nothing.

Method TextBadge.Draw, uses xbx xdi xsi, pText:PSTRING
  local CalcRect:RECT, dTextLength:DWORD, bmi:BITMAPINFO, pPixels:ptr COLORREF
  local hPrvBrush:HBRUSH, hPrvFont:HFONT, dPrvBkMode:DWORD, PrvTextColor:COLORREF
;  local hAlphaBmp:HANDLE, pAlphaPixels:ptr COLORREF

;  DbgText "TextBadge.Draw"

  SetObject xsi
  BitSet [xsi].dFlags, TBF_DIRTY
  .if pText == NULL
    mov [xsi].BmpSize.x, 0
    mov [xsi].BmpSize.y, 0
  .else
    mov CalcRect.left, 0
    mov CalcRect.top, 0
    mov dTextLength, $32($invoke(StrLength, pText))

    invoke GetDeviceCaps, [xsi].hMemDC, LOGPIXELSY
    invoke MulDiv, [xsi].dFontPointSize, eax, -72
    mov [xsi].LogFontText.lfHeight, eax
    invoke CreateFontIndirect, addr [xsi].LogFontText
    mov hPrvFont, $invoke(SelectObject, [xsi].hMemDC, xax)
    invoke CreateSolidBrush, [xsi].BackColor
    mov hPrvBrush, $invoke(SelectObject, [xsi].hMemDC, xax)

    .if dTextLength == 0
      invoke DrawText, [xsi].hMemDC, $OfsCStr("I"), 1, addr CalcRect, DT_CALCRECT or DT_SINGLELINE
      mov ebx, CalcRect.bottom
      add ebx, 2*TB_BORDER
      mov [xsi].BmpSize.x, ebx
      mov [xsi].BmpSize.y, ebx
    .else
      invoke DrawText, [xsi].hMemDC, pText, dTextLength, addr CalcRect, DT_CALCRECT or DT_SINGLELINE
      mov ebx, CalcRect.bottom
      add ebx, 2*TB_BORDER
      mov eax, CalcRect.right
      add eax, 2*TB_BORDER
      lea ecx, [2*ebx + ebx]
      shr ecx, 2
      add eax, ecx
      .if eax < ebx
        mov eax, ebx
      .endif
      mov [xsi].BmpSize.x, eax
      mov [xsi].BmpSize.y, ebx
    .endif

    ;Create DibSection to gain access to the pixels
    mov bmi.bmiHeader.biSize, sizeof(BITMAPINFOHEADER)
    mrm bmi.bmiHeader.biWidth, [xsi].BmpSize.x, eax
    mov ecx, [xsi].BmpSize.y
    mul ecx
    mov bmi.bmiHeader.biSizeImage, eax
    neg ecx
    mov bmi.bmiHeader.biHeight, ecx
    mov bmi.bmiHeader.biPlanes, 1
    mov bmi.bmiHeader.biBitCount, 32
    mov bmi.bmiHeader.biCompression, BI_RGB

    invoke CreateDIBSection, [xsi].hMemDC, addr bmi, DIB_RGB_COLORS, addr pPixels, NULL, 0
    mov [xsi].hMemBmp, xax
    invoke DeleteObject, $invoke(SelectObject, [xsi].hMemDC, xax) ;Delete previous BMP

    ;Empty the DibSection background
    mov xdi, pPixels
    mov eax, bmi.bmiHeader.biSizeImage
    .while eax != 0
      mov COLORREF ptr [xdi], 0                         ;Important: alpha = 0
      dec eax
      add xdi, sizeof(COLORREF)
    .endw

    ;Draw an antialised rounded rectangle with radii = Height/2
    mov edi, [xsi].BmpSize.y
    shr edi, 1
    invoke DrawRoundedRect, [xsi].hMemDC, 0, 0, [xsi].BmpSize.x, [xsi].BmpSize.y, edi, [xsi].BackColor

    .if dTextLength != 0
      mov eax, [xsi].BmpSize.x
      sub eax, CalcRect.right
      shr eax, 1
      add CalcRect.left, eax
      add CalcRect.right, eax

      mov eax, [xsi].BmpSize.y
      sub eax, CalcRect.bottom
      shr eax, 1
      add CalcRect.top, eax
      add CalcRect.bottom, eax

      mov dPrvBkMode, $32($invoke(SetBkMode, [xsi].hMemDC, TRANSPARENT))
      mov PrvTextColor, $32($invoke(SetTextColor, [xsi].hMemDC, [xsi].ForeColor))
      invoke DrawText, [xsi].hMemDC, pText, dTextLength, addr CalcRect, DT_SINGLELINE or DT_NOCLIP or DT_VCENTER
      invoke SetTextColor, [xsi].hMemDC, PrvTextColor
      invoke SetBkMode, [xsi].hMemDC, dPrvBkMode

      ;Fill the alpha value under the text
      mov ebx, CalcRect.top
      .while ebx < CalcRect.bottom
        mov edi, CalcRect.left
        dec edi
        mov eax, ebx
        mul [xsi].BmpSize.x
        add eax, edi
        mov xdx, pPixels
        lea xcx, [xdx + sizeof(COLORREF)*xax]
        .while edi <= CalcRect.right
          or COLORREF ptr [xcx], 0FF000000h
          add xcx, sizeof(COLORREF)
          inc edi
        .endw
        inc ebx
      .endw
    .endif

    ;The following code is to visualize the alpha channel
;    invoke CreateDIBSection, [xsi].hMemDC, addr bmi, DIB_RGB_COLORS, addr pAlphaPixels, NULL, 0
;    mov hAlphaBmp, xax
;    mov xcx, pPixels
;    mov xdi, pAlphaPixels
;    xor ebx, ebx
;    .while ebx < bmi.bmiHeader.biSizeImage
;      ;Build a grayscale pixel based on its alpha value
;      mov eax, [xcx]
;      shr eax, 24
;      mov ah, al
;      mov dx, ax
;      shl eax, 16
;      mov ax, dx
;      mov [xdi], eax
;      add xcx, sizeof(COLORREF)
;      add xdi, sizeof(COLORREF)
;      inc ebx
;    .endw
;    DbgBmp hAlphaBmp
;    invoke DeleteObject, hAlphaBmp

    invoke DeleteObject, $invoke(SelectObject, [xsi].hMemDC, hPrvBrush)
    invoke DeleteObject, $invoke(SelectObject, [xsi].hMemDC, hPrvFont)
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     TextBadge.Init
; Purpose:    Initialize the object.
; Arguments:  Arg1: -> Owner object.
;             Arg2: HANDLE of the window to draw on.
;             Arg3: Foreground color.
;             Arg4: Background color.
; Return:     Nothing.

Method TextBadge.Init, uses xsi, pOwner:POINTER, hWnd:HWND, \
                                 ForeColor:COLORREF, BackColor:COLORREF
  local hDC:HDC

  SetObject xsi
  ACall xsi.Init, pOwner
  BitClr [xsi].dFlags, TBF_DIRTY
  m2m [xsi].hWnd, hWnd, xax
  m2m [xsi].ForeColor, ForeColor, eax
  m2m [xsi].BackColor, BackColor, eax
  mov hDC, $invoke(GetDC, hWnd)
  mov [xsi].hMemDC, $invoke(CreateCompatibleDC, hDC)
  mov [xsi].hMemBmp, $invoke(CreateCompatibleBitmap, hDC, 1, 1)   ;Create a compatible BMP
  mov [xsi].hPrvMemBmp, $invoke(SelectObject, [xsi].hMemDC, xax)  ;Select it to set the color format
  invoke ReleaseDC, hWnd, hDC
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     TextBadge.Invalidate
; Purpose:    Invalidate the rect used to paint the new drawn badge.
; Arguments:  None.
; Return:     Nothing.

Method TextBadge.Invalidate, uses xsi
  SetObject xsi

  ;Invalidate previous DstRect
  invoke InvalidateRect, [xsi].hWnd, addr [xsi].DstRect, TRUE

  .ifBitSet [xsi].dFlags, TBF_DIRTY
    BitClr [xsi].dFlags, TBF_DIRTY
    OCall xsi.CalcDstRect

    invoke InvalidateRect, [xsi].hWnd, addr [xsi].DstRect, FALSE
  .endif 
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     TextBadge.Paint
; Purpose:    Paint the Badge on a Device Context.
; Arguments:  Arg1: DC HANDLE.
;             Arg2: Transparency value [0..255].
; Return:     Nothing.

Method TextBadge.Paint, uses xsi, hDC:HDC, bTransparency:BYTE
  local bfn:BLENDFUNCTION

;  DbgText "TextBadge.Paint"
  SetObject xsi
  .if [xsi].BmpSize.x != 0 && [xsi].BmpSize.y != 0
    .ifBitSet [xsi].dFlags, TBF_DIRTY
      OCall xsi.CalcDstRect
      BitClr [xsi].dFlags, TBF_DIRTY
    .endif
    ;https://learn.microsoft.com/en-us/windows/win32/api/wingdi/ns-wingdi-blendfunction
    mov bfn.BlendOp, AC_SRC_OVER
    mov bfn.BlendFlags, 0
    m2m bfn.SourceConstantAlpha, bTransparency, al
    mov bfn.AlphaFormat, AC_SRC_ALPHA
    invoke AlphaBlend, hDC, [xsi].DstRect.left, [xsi].DstRect.top, [xsi].BmpSize.x, [xsi].BmpSize.y, \
                       [xsi].hMemDC, 0, 0, [xsi].BmpSize.x, [xsi].BmpSize.y, bfn
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     TextBadge.SetPosition
; Purpose:    Set the Badge position and alignment flags.
; Arguments:  Arg1: x position.
;             Arg2: y position.
;             Arg3: Alignment; describes how the x,y coords are interpreted in the Paint method.
; Return:     Nothing.

Method TextBadge.SetPosition, uses xsi, sdX:SDWORD, sdY:SDWORD, dAlignment:DWORD
;  DbgText "TextBadge.SetPosition"
  SetObject xsi

  ;Store the reference point. Its meaning depends on the alignement
  m2m [xsi].RefPoint.x, sdX, eax
  m2m [xsi].RefPoint.y, sdY, eax
  m2m [xsi].dFlags, dAlignment, eax
  BitSet [xsi].dFlags, TBF_DIRTY
MethodEnd

endif
