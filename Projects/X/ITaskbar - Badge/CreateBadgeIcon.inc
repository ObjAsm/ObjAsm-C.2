CreateBadgeIcon proc uses xbx xdi xsi hDC:HDC, pText:PSTRING, dForeColor:DWORD, dBackColor:DWORD
  local hMemDC:HDC, hTxtDC:HDC, hIcoDC:HDC, BadgeRect:RECT
  local hMemBmp:HBITMAP, hPrvMemBmp:HBITMAP, hMskBmp:HBITMAP
  local hIcoBmp:HBITMAP, hPrvIcoBmp:HBITMAP, hTxtBmp:HBITMAP, hPrvTxtBmp:HBITMAP
  local IconInfo:ICONINFO, hIcon:HICON
  local hFont:HFONT, hPrvFont:HFONT, LogFnt:LOGFONT
  local BmpInfo:BITMAPINFO, pIcoBmpBuffer:POINTER, pTxtBmpBuffer:POINTER

  mov BadgeRect.left, 0
  mov BadgeRect.top, 0
  mov BadgeRect.right, BADGE_SIZE
  mov BadgeRect.bottom, BADGE_SIZE

  mov BmpInfo.bmiHeader.biSize, sizeof(BITMAPINFOHEADER)
  mov BmpInfo.bmiHeader.biWidth, BADGE_SIZE
  mov BmpInfo.bmiHeader.biHeight, BADGE_SIZE
  mov BmpInfo.bmiHeader.biPlanes, 1
  mov BmpInfo.bmiHeader.biBitCount, 32
  mov BmpInfo.bmiHeader.biCompression, BI_RGB
  mov BmpInfo.bmiHeader.biSizeImage, 4*BADGE_SIZE*BADGE_SIZE
  mov BmpInfo.bmiHeader.biXPelsPerMeter, 0
  mov BmpInfo.bmiHeader.biYPelsPerMeter, 0
  mov BmpInfo.bmiHeader.biClrUsed, 0
  mov BmpInfo.bmiHeader.biClrImportant, 0

  mov hMemDC, $invoke(CreateCompatibleDC, hDC)
  mov hTxtDC, $invoke(CreateCompatibleDC, hDC)
  mov hIcoDC, $invoke(CreateCompatibleDC, hDC)
  mov hMemBmp, $invoke(CreateCompatibleBitmap, hDC, BADGE_SIZE, BADGE_SIZE)
  mov hMskBmp, $invoke(CreateCompatibleBitmap, hDC, BADGE_SIZE, BADGE_SIZE)
  mov hIcoBmp, $invoke(CreateDIBSection, 0, addr BmpInfo, DIB_RGB_COLORS, addr pIcoBmpBuffer, 0, 0)
  mov hTxtBmp, $invoke(CreateDIBSection, 0, addr BmpInfo, DIB_RGB_COLORS, addr pTxtBmpBuffer, 0, 0)

  mov hPrvMemBmp, $invoke(SelectObject, hMemDC, hMemBmp)
  mov hPrvIcoBmp, $invoke(SelectObject, hIcoDC, hIcoBmp)
  mov hPrvTxtBmp, $invoke(SelectObject, hTxtDC, hTxtBmp)

  ;Create a mask for the badge form using the alpha channel too
  invoke LoadIcon, hInstance, $OfsCStr("ICON_BADGE_MASK")
  invoke DrawIconEx, hIcoDC, 0, 0, xax, BADGE_SIZE, BADGE_SIZE, 0, 0, DI_IMAGE

  ;Colorize the badge background
  mov xbx, pIcoBmpBuffer
  xor edi, edi
  mov ecx, dBackColor
  and ecx, 00FFFFFFh
  RGB2BGR ecx
  .while edi < BADGE_SIZE
    xor esi, esi
    .while esi < BADGE_SIZE
      mov eax, [xbx]
      and eax, 0FF000000h                               ;Keep the alpha value
      or eax, ecx                                       ;Replace with the background color
      mov [xbx], eax                                    ;Store
      add xbx, sizeof(DWORD)
      inc esi
    .endw
    inc edi
  .endw

  ;Draw badge text
  FillString LogFnt.lfFaceName, <Segoe UI>
  invoke GetDeviceCaps, hDC, LOGPIXELSY
  invoke MulDiv, 8, eax, -72
  mov LogFnt.lfHeight, eax
  m2z LogFnt.lfWidth
  m2z LogFnt.lfEscapement
  m2z LogFnt.lfOrientation
  mov LogFnt.lfWeight, FW_DONTCARE
  m2z LogFnt.lfItalic
  m2z LogFnt.lfUnderline
  m2z LogFnt.lfStrikeOut
  mov LogFnt.lfCharSet, DEFAULT_CHARSET
  mov LogFnt.lfOutPrecision, OUT_DEFAULT_PRECIS
  mov LogFnt.lfClipPrecision, CLIP_DEFAULT_PRECIS
  mov LogFnt.lfQuality, NONANTIALIASED_QUALITY;CLEARTYPE_QUALITY
  mov LogFnt.lfPitchAndFamily, DEFAULT_PITCH or FF_DONTCARE
  mov hFont, $invoke(CreateFontIndirect, addr LogFnt)
  mov hPrvFont, $invoke(SelectObject, hMemDC, hFont)
  invoke PatBlt, hTxtDC, 0, 0, BADGE_SIZE, BADGE_SIZE, BLACKNESS
  mov edx, dForeColor
  test edx, edx                                         ;Check if it 0
  setz dl                                               ;Make it a bit different
  RGB2BGR edx
  invoke SetTextColor, hTxtDC, edx
  invoke SetBkMode, hTxtDC, TRANSPARENT
  invoke StrLength, pText
  lea xbx, BadgeRect
  invoke DrawText, hTxtDC, pText, eax, xbx, DT_CENTER or DT_VCENTER or DT_SINGLELINE

  ;Fix the alpha values and copy the new information into the IcoBuffer
  mov xbx, pTxtBmpBuffer
  mov xcx, pIcoBmpBuffer
  xor edi, edi
  .while edi < BADGE_SIZE
    xor esi, esi
    .while esi < BADGE_SIZE
      mov eax, [xbx]
      .if eax != 0
        or eax, 0FF000000h
        mov [xcx], eax
      .endif
      add xbx, sizeof(DWORD)
      add xcx, sizeof(DWORD)
      inc esi
    .endw
    inc edi
  .endw
  invoke BitBlt, hMemDC, 0, 0, BADGE_SIZE, BADGE_SIZE, hIcoDC, 0, 0, SRCPAINT

  mov IconInfo.fIcon, TRUE
  mov IconInfo.xHotspot, 0
  mov IconInfo.yHotspot, 0
  m2m IconInfo.hbmMask, hMskBmp, xax
  m2m IconInfo.hbmColor, hMemBmp, xcx

  mov hIcon, $invoke(CreateIconIndirect, addr IconInfo)

  ;Housekeeping
  invoke DeleteObject, $invoke(SelectObject, hMemDC, hPrvFont)
  invoke DeleteObject, $invoke(SelectObject, hMemDC, hPrvMemBmp)
  invoke DeleteDC, hMemDC
  invoke DeleteObject, $invoke(SelectObject, hIcoDC, hPrvIcoBmp)
  invoke DeleteDC, hIcoDC
  invoke DeleteObject, $invoke(SelectObject, hTxtDC, hPrvTxtBmp)
  invoke DeleteDC, hTxtDC
  invoke DeleteObject, hMskBmp

  mov xax, hIcon
  ret
CreateBadgeIcon endp
