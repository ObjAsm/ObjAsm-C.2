; ==================================================================================================
; Title:      DrawRoundedRect_X.inc
; Author:     G. Friedrich
; Version:    C.2.0
; Notes:      Version C.2.0, November 2025.
;               - First release.
;               - Bitness neutral code.
; ==================================================================================================


; --------------------------------------------------------------------------------------------------
; Procedure:  DrawRoundedRect
; Purpose:    Draw an anti-alised rounded rect.
; Arguments:  Arg1: DC HANDLE.
;             Arg2: Left starting position.
;             Arg3: Top starting position.
;             Arg4: Total width.
;             Arg5: Total height.
;             Arg6: Radius of all corners.
;             Arg7: RGB color used to draw the rounded rectangle.
; Return:     Nothing.

GetPixelAddr macro RegX, RegY
  mov eax, RegY
  mul dWidth
  add eax, RegX
  shl eax, 2
  add xax, pPixels
endm

.code
align ALIGN_CODE
DrawRoundedRect proc uses xbx xdi xsi hDC:HDC, sdLeft:SDWORD, sdTop:SDWORD, \
                                      dWidth:DWORD, dHeight:DWORD, dRadius:DWORD, Color:COLORREF
  local hMemDC:HDC, hMemBmp:HANDLE, hPrvMemBmp:HANDLE, bfn:BLENDFUNCTION
  local bmi:BITMAPINFO, pPixels:ptr COLORREF, pVertPixel:ptr COLORREF
  local dRadiusSquare:DWORD, dSym45:DWORD, MemColor:COLORREF, MemColorOpaque:COLORREF

  mov eax, dHeight
  shr eax, 1
  .if eax < dRadius
    mov dRadius, eax
  .endif

  ;Create DibSection to gain access to the pixels
  mov bmi.bmiHeader.biSize, sizeof(BITMAPINFOHEADER)
  mov eax, dWidth
  mov bmi.bmiHeader.biWidth, eax
  mov ecx, dHeight
  mul ecx
  mov bmi.bmiHeader.biSizeImage, eax
  neg ecx
  mov bmi.bmiHeader.biHeight, ecx
  mov bmi.bmiHeader.biPlanes, 1
  mov bmi.bmiHeader.biBitCount, 32
  mov bmi.bmiHeader.biCompression, BI_RGB

  mov hMemDC, $invoke(CreateCompatibleDC, hDC)
  invoke CreateDIBSection, hDC, addr bmi, DIB_RGB_COLORS, addr pPixels, NULL, 0
  mov hMemBmp, xax
  mov hPrvMemBmp, $invoke(SelectObject, hMemDC, xax)

  ;Draw first quarter of an circle
  ;Setup constants
  mov eax, dRadius
  mov ecx, 19195                                        ;[1 - sin(45)]*65536
  mul ecx
  shr eax, 16                                           ;/65536
  inc eax                                               ;Border + 1
  mov dSym45, eax
  mov eax, dRadius
  mul eax
  mov dRadiusSquare, eax
  mov eax, Color
  RGB2BGR eax
  mov MemColor, eax                                     ;(A)BGR in memory
  or eax, 0FF000000h
  mov MemColorOpaque, eax

  ;Initialize upper left triangle to zero
  xor eax, eax
  mov edx, dRadius
  xor ebx, ebx
  mov xsi, pPixels
  mov edx, dSym45
  add edx, edx
  sub edx, 3                                            ;if possible, go back 3 pixel for a smooth transition
  .while SDWORD ptr ebx < edx                           ;ebx = Y, if edx <= 0 skip the loop
    mov xdi, xsi
    mov ecx, dSym45                                     ;edi = X
    add ecx, ecx
    sub ecx, ebx
    sub ecx, 3
    rep stos COLORREF ptr [xdi]
    mov ecx, dWidth
    lea xsi, [xsi + sizeof(COLORREF)*xcx]
    inc ebx
  .endw

  ;Fill the DibSection inner rect with the background color
  mov xdi, pPixels
  mov eax, dSym45
  mul dWidth
  add eax, dSym45
  shl eax, $Log2(COLORREF)
  add xdi, xax
  mov eax, MemColorOpaque
  mov ebx, dSym45
  .while ebx < dRadius                                  ;ebx = Y
    mov ecx, dRadius
    sub ecx, dSym45                                     ;edi = X
    mov edx, dWidth
    sub edx, ecx
    rep stos COLORREF ptr [xdi]
    shl edx, $Log2(COLORREF)
    add xdi, xdx
    inc ebx
  .endw

  ;Calc D = (R-X)^2 + (R-Y)^2 - R^2
  mov edx, dRadius
  xor ebx, ebx
  .while ebx < dSym45                                   ;ebx = Y
    mov edi, dSym45                                     ;edi = X
    add edi, edi
    sub edi, ebx
    sub edi, 3
    .while edi < dRadius
      mov eax, dRadius
      sub eax, edi
      imul eax
      mov ecx, eax
      mov eax, dRadius
      sub eax, ebx
      imul eax
      add ecx, eax
      sub ecx, dRadiusSquare
      .if (SIGN? || ZERO?)                              ;Inside
        GetPixelAddr ebx, edi
        mov pVertPixel, xax

        ;Fill the rest of the horizontal line
        GetPixelAddr edi, ebx
        mov ecx, dRadius
        sub ecx, edi
        mov edx, ecx
        mov xdi, xax
        mov eax, MemColorOpaque
        rep stos COLORREF ptr [xdi]

        ;Fill the rest of the vertical line
        mov xdi, pVertPixel
        mov ecx, dWidth
        shl ecx, $Log2(COLORREF)                        ;ecx = stride
        .while edx != 0
          mov COLORREF ptr [xdi], eax
          add xdi, xcx                                  ;Move to next vertical pixel
          dec edx
        .endw
        .break
      .endif

      ;Outside => check tolerance
      sub ecx, dRadius                                  ;Inside tolerance = 2*Radius
      sub ecx, dRadius
      .if SIGN?
        neg ecx
        mov eax, ecx
        shl eax, 7                                      ;(shl eax, 8) / 2   (2*Radius)
        xor edx, edx
        div dRadius
        mov ecx, eax

        ;Premultiply each color channel by alpha, required for AlphaBlend API
        mov eax, MemColor
        and eax, 000FF00FFh
        mul ecx
        shr eax, 8
        and eax, 000FF00FFh
        mov esi, eax
        mov eax, MemColor
        and eax, 00000FF00h
        mul ecx
        shr eax, 8
        and eax, 00000FF00h
        or esi, eax
        shl ecx, 24                                     ;Move alpha to the MSB
        or esi, ecx

        GetPixelAddr edi, ebx
        mov COLORREF ptr [xax], esi
        GetPixelAddr ebx, edi
        mov COLORREF ptr [xax], esi
      .endif
      inc edi
    .endw

    inc ebx
  .endw

  ;Mirror the first quarter circle to the right
  mov xdi, pPixels
  xor ebx, ebx
  .while ebx < dRadius
    xor edx, edx
    .while edx < dRadius
      mov eax, [xdi + sizeof(COLORREF)*xdx]
      mov ecx, dWidth
      sub ecx, edx
      mov [xdi + sizeof(COLORREF)*xcx - sizeof(COLORREF)], eax
      inc edx
    .endw
    inc ebx
    mov eax, dWidth
    lea xdi, [xdi + sizeof(COLORREF)*xax]
  .endw

  ;Fill the section between upper quarter circles
  mov xcx, pPixels
  mov ebx, dRadius
  lea xdi, [xcx + sizeof(COLORREF)*xbx]                 ;xdi -> Destination
  mov eax, MemColorOpaque
  mov ecx, dWidth
  neg ebx
  lea edx, [ecx + 2*ebx]
  mov esi, dRadius
  shl esi, 3
  test ebx, ebx
  .while !ZERO?
    mov ecx, edx
    rep stos COLORREF ptr [xdi]
    add xdi, xsi
    inc ebx
  .endw

  ;Mirror the upper section to the bottom
  mov xdi, pPixels                                      ;xdi -> Source pixel
  mov eax, dHeight
  dec eax
  mul dWidth
  lea xcx, [xdi + sizeof(COLORREF)*xax]                 ;xcx -> Destination pixel
  xor ebx, ebx
  .while ebx < dRadius
    xor edx, edx
    .while edx < dWidth
      mov eax, [xdi + sizeof(COLORREF)*xdx]
      mov [xcx + sizeof(COLORREF)*xdx], eax
      inc edx
    .endw
    mov eax, dWidth
    lea xdi, [xdi + sizeof(COLORREF)*xax]
    neg xax
    lea xcx, [xcx + sizeof(COLORREF)*xax]
    inc ebx
  .endw

  ;Fill the gap between upper an lower sections
  mov ebx, dRadius
  mov eax, dWidth
  mov xcx, pPixels
  mul ebx
  lea xdi, [xcx + sizeof(COLORREF)*xax]
  mov eax, MemColorOpaque
  mov edx, dHeight
  sub edx, ebx
  sub edx, ebx
  .while !ZERO? && !SIGN?
    mov ecx, dWidth
    rep stosd COLORREF ptr [xdi]
    dec edx
  .endw

  mov bfn.BlendOp, AC_SRC_OVER
  mov bfn.BlendFlags, 0
  mov bfn.SourceConstantAlpha, 255
  mov bfn.AlphaFormat, AC_SRC_ALPHA
  invoke AlphaBlend, hDC, sdLeft, sdTop, dWidth, dHeight, \
                     hMemDC, 0, 0, dWidth, dHeight, bfn

  invoke DeleteObject, $invoke(SelectObject, hMemDC, hPrvMemBmp)
  invoke DeleteDC, hMemDC
  ret
DrawRoundedRect endp
