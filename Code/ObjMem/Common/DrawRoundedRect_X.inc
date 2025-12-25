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
  add xax, $LocReg(pPixels)
endm

.code
align ALIGN_CODE
if TARGET_BITNESS eq 32
DrawRoundedRect proc uses xbx xdi xsi hDC:HDC, sdLeft:SDWORD, sdTop:SDWORD, \
                                      dWidth:DWORD, dHeight:DWORD, dRadius:DWORD, Color:COLORREF
else
DrawRoundedRect proc uses xbx xdi xsi r12 r13 r14 r15 hDC:HDC, sdLeft:SDWORD, sdTop:SDWORD, \
                                      dWidth:DWORD, dHeight:DWORD, dRadius:DWORD, Color:COLORREF
endif
  local hMemDC:HDC, hMemBmp:HANDLE, hPrvMemBmp:HANDLE, bfn:BLENDFUNCTION
  local bmi:BITMAPINFO, pBits:ptr COLORREF, MemColor:COLORREF
  
  ;In x64, use available register instead of locals
  _ProcName_ textequ <DrawRoundedRect>
  LocReg dRadiusSquare:r10d 
  LocReg dSym45:r11d
  LocReg MemColorOpaque:r12d
  
  ;In x64, use available register instead of arguments
  ArgReg dWidth:r14d
  ArgReg dRadius:r15d

  ;Since pBits is required for CreateDIBSection, we need a special handling
  if TARGET_BITNESS eq 32
    DrawRoundedRect_pPixels equ <pBits>                 ;x32 => replace pPixels with local pBits 
  else
    DrawRoundedRect_pPixels equ <r13>                   ;x64 => replace pPixels with r14 register
    mov $ArgReg(dWidth), dWidth
    mov $ArgReg(dRadius), dRadius
  endif

  mov eax, dHeight
  shr eax, 1                                            ;Divide height by 2
  .if eax < $ArgReg(dRadius)
    mov $ArgReg(dRadius), eax                           ;Clamp radius to half height
  .endif

  ;Create DibSection to gain access to the pixels
  mov bmi.bmiHeader.biSize, sizeof(BITMAPINFOHEADER)    ;Set BITMAPINFOHEADER size
  mov eax, dWidth
  mov bmi.bmiHeader.biWidth, eax                        ;Set bitmap width
  mov ecx, dHeight
  mul ecx                                               ;Calculate width*height
  mov bmi.bmiHeader.biSizeImage, eax                    ;Set image size
  neg ecx
  mov bmi.bmiHeader.biHeight, ecx                       ;Negative for top-down bitmap
  mov bmi.bmiHeader.biPlanes, 1                         ;Single plane
  mov bmi.bmiHeader.biBitCount, 32                      ;32-bit color depth
  mov bmi.bmiHeader.biCompression, BI_RGB               ;No compression

  mov hMemDC, $invoke(CreateCompatibleDC, hDC)          ;Create memory DC
  invoke CreateDIBSection, hDC, addr bmi, DIB_RGB_COLORS, addr pBits, NULL, 0 ;Create DIB
  if TARGET_BITNESS eq 64
    mov $LocReg(pPixels), pBits
  endif

  mov hMemBmp, xax                                      ;Store handle to bitmap
  mov hPrvMemBmp, $invoke(SelectObject, hMemDC, xax)    ;Select bitmap into DC

  ;Draw first quarter of a circle
  ;Setup constants
  mov eax, $ArgReg(dRadius)
  mov ecx, 19195                                        ;[1 - sin(45)]*65536
  mul ecx
  shr eax, 16                                           ;Divide by 65536
  inc eax                                               ;Add 1 for border
  mov $LocReg(dSym45), eax                              ;Store offset for 45-degree symmetry
  mov eax, $ArgReg(dRadius)
  mul eax
  mov $LocReg(dRadiusSquare), eax                       ;Store radius squared
  mov eax, Color
  RGB2BGR eax                                           ;Convert to memory BGR
  mov MemColor, eax                                     ;Store BGR color
  or eax, 0FF000000h
  mov $LocReg(MemColorOpaque), eax                      ;Store opaque color (alpha=255)

  ;Initialize upper left triangle to zero
  xor eax, eax
  mov edx, $ArgReg(dRadius)
  xor ebx, ebx
  mov xsi, $LocReg(pPixels)
  mov edx, $LocReg(dSym45)
  add edx, edx
  sub edx, 3                                            ;Step back 3 pixels for smoothing
  .while SDWORD ptr ebx < edx                           ;Loop over Y
    mov xdi, xsi
    mov ecx, $LocReg(dSym45)                            ;Set X count
    add ecx, ecx
    sub ecx, ebx
    sub ecx, 3
    rep stos COLORREF ptr [xdi]                         ;Clear pixels to 0
    mov ecx, dWidth
    lea xsi, [xsi + sizeof(COLORREF)*xcx]               ;Move to next row
    inc ebx
  .endw

  ;Fill the DibSection inner rect with the background color
  mov xdi, $LocReg(pPixels)
  mov eax, $LocReg(dSym45)
  mul dWidth
  add eax, $LocReg(dSym45)
  shl eax, $Log2(COLORREF)
  add xdi, xax                                          ;xdi = starting pixel for inner rect
  mov eax, $LocReg(MemColorOpaque)
  mov ebx, $LocReg(dSym45)
  .while ebx < $ArgReg(dRadius)                         ;Loop over Y
    mov ecx, $ArgReg(dRadius)
    sub ecx, $LocReg(dSym45)                            ;Compute width of row
    mov edx, dWidth
    sub edx, ecx                                        ;Compute remaining width
    rep stos COLORREF ptr [xdi]                         ;Fill row
    shl edx, $Log2(COLORREF)
    add xdi, xdx                                        ;Move to next row
    inc ebx
  .endw

  ;Calc D = (R-X)^2 + (R-Y)^2 - R^2
  mov edx, $ArgReg(dRadius)
  xor ebx, ebx
  .while ebx < $LocReg(dSym45)                          ;Loop Y within 45-degree region
    mov edi, $LocReg(dSym45)                            ;X = dSym45
    add edi, edi
    sub edi, ebx
    sub edi, 3
    .while edi < $ArgReg(dRadius)                       ;Loop X
      mov eax, $ArgReg(dRadius)
      sub eax, edi
      imul eax
      mov ecx, eax
      mov eax, $ArgReg(dRadius)
      sub eax, ebx
      imul eax
      add ecx, eax
      sub ecx, $LocReg(dRadiusSquare)                   ;Compute distance squared - R^2
      .if (SIGN? || ZERO?)                              ;Inside circle
        GetPixelAddr ebx, edi
        mov xsi, xax                                    ;xsi -> Pixel

        ;Fill the rest of the horizontal line
        GetPixelAddr edi, ebx
        mov ecx, $ArgReg(dRadius)
        sub ecx, edi
        mov edx, ecx
        mov xdi, xax
        mov eax, $LocReg(MemColorOpaque)
        rep stos COLORREF ptr [xdi]                     ;Fill horizontal pixels

        ;Fill the rest of the vertical line
        mov xdi, xsi
        mov ecx, dWidth
        shl ecx, $Log2(COLORREF)                        ;stride in bytes
        .while edx != 0
          mov COLORREF ptr [xdi], eax
          add xdi, xcx                                  ;Move to next vertical pixel
          dec edx
        .endw
        .break
      .endif

      ;Outside => check tolerance
      sub ecx, $ArgReg(dRadius)                         ;Adjust for tolerance
      sub ecx, $ArgReg(dRadius)
      .if SIGN?
        neg ecx
        mov eax, ecx
        shl eax, 7                                      ;Scale for alpha blending
        xor edx, edx
        div $ArgReg(dRadius)
        mov ecx, eax

        ;Premultiply each color channel by alpha
        mov eax, MemColor
        and eax, 000FF00FFh
        imul ecx
        shr eax, 8
        and eax, 000FF00FFh
        mov esi, eax
        mov eax, MemColor
        and eax, 00000FF00h
        imul ecx
        shr eax, 8
        and eax, 00000FF00h
        or esi, eax
        shl ecx, 24                                     ;Move alpha to MSB
        or esi, ecx

        GetPixelAddr edi, ebx
        mov COLORREF ptr [xax], esi                     ;Set pixel with alpha
        GetPixelAddr ebx, edi
        mov COLORREF ptr [xax], esi
      .endif
      inc edi
    .endw

    inc ebx
  .endw

  ;Mirror the first quarter circle to the right
  mov xdi, $LocReg(pPixels)
  xor ebx, ebx
  .while ebx < $ArgReg(dRadius)
    xor edx, edx
    .while edx < $ArgReg(dRadius)
      mov eax, [xdi + sizeof(COLORREF)*xdx]
      mov ecx, dWidth
      sub ecx, edx
      mov [xdi + sizeof(COLORREF)*xcx - sizeof(COLORREF)], eax ;Mirror horizontally
      inc edx
    .endw
    inc ebx
    mov eax, dWidth
    lea xdi, [xdi + sizeof(COLORREF)*xax]               ;Move to next row
  .endw

  ;Fill the section between upper quarter circles
  mov xcx, $LocReg(pPixels)
  mov ebx, $ArgReg(dRadius)
  lea xdi, [xcx + sizeof(COLORREF)*xbx]                 ;Destination start
  mov eax, $LocReg(MemColorOpaque)
  mov ecx, dWidth
  neg ebx
  lea edx, [ecx + 2*ebx]
  mov esi, $ArgReg(dRadius)
  shl esi, 3
  test ebx, ebx
  .while !ZERO?
    mov ecx, edx
    rep stos COLORREF ptr [xdi]                         ;Fill horizontal strip
    add xdi, xsi
    inc ebx
  .endw

  ;Mirror the upper section to the bottom
  mov xsi, $LocReg(pPixels)                             ;Source start
  mov eax, dHeight
  dec eax
  imul dWidth
  lea xdi, [xsi + sizeof(COLORREF)*xax]                 ;Destination start
  mov ebx, $ArgReg(dRadius)
  mov eax, dWidth
  mov edx, eax
  shl edx, $Log2(COLORREF) + 1
  test ebx, ebx
  .while !ZERO?
    mov ecx, eax
    rep movsd                                           ;Copy row
    sub xdi, xdx                                        ;Move up to previous row
    dec ebx
  .endw

  ;Fill the gap between upper and lower sections
  mov ebx, $ArgReg(dRadius)
  mov eax, dWidth
  mov xcx, $LocReg(pPixels)
  imul ebx
  lea xdi, [xcx + sizeof(COLORREF)*xax]
  mov eax, $LocReg(MemColorOpaque)
  mov edx, dHeight
  sub edx, ebx
  sub edx, ebx
  .while !ZERO? && !SIGN?
    mov ecx, dWidth
    rep stosd COLORREF ptr [xdi]                        ;Fill gap vertically
    dec edx
  .endw

  mov bfn.BlendOp, AC_SRC_OVER
  mov bfn.BlendFlags, 0
  mov bfn.SourceConstantAlpha, 255
  mov bfn.AlphaFormat, AC_SRC_ALPHA
  invoke AlphaBlend, hDC, sdLeft, sdTop, dWidth, dHeight, \
                     hMemDC, 0, 0, dWidth, dHeight, bfn ;Blend bitmap to DC

  ;Restore DC & delete bitmap
  invoke DeleteObject, $invoke(SelectObject, hMemDC, hPrvMemBmp)
  invoke DeleteDC, hMemDC
  ret
DrawRoundedRect endp
