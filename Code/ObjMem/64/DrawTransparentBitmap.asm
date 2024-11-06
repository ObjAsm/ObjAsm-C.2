; ==================================================================================================
; Title:      DrawTransparentBitmap.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMemWin.cop

TBM_FIRSTPIXEL equ  80000000h

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  DrawTransparentBitmap
; Purpose:    Draw a bitmap with transparency on a device context.
; Arguments:  Arg1: DC HANDLE.
;             Arg2: Bitmap HANDLE to draw.
;             Arg3; X start position on DC.
;             Arg4: Y start position on DC.
;             Arg5: RGB transparent color. Use TBM_FIRSTPIXEL to indicate that the pixel in the
;                   upper left corner contains the transparent color.
; Return:     Nothing.
; Notes:      Original source by Microsoft.
;             "HOWTO: Drawing Transparent Bitmaps (Q79212)"
;             (http://support.microsoft.com/default.aspx?scid=kb;EN-US;q79212)
;             Transcribed by Ernest Murphy.

.code
align ALIGN_CODE
DrawTransparentBitmap proc hDC:HDC, hBitmap:HBITMAP, xStart:DWORD, yStart:DWORD,
                           cTransparentColor:DWORD
  local BmpData:BITMAP                                    ;Structure holding bitmap data
  local hTempDC:HDC, dPrevColor:DWORD, PntSize:POINT
  local hObjDC :HDC, hAndObjBmp:HBITMAP,  hPrevObjBmp:HBITMAP
  local hBackDC:HDC, hAndBackBmp:HBITMAP, hPrevBackBmp:HBITMAP
  local hSaveDC:HDC, hSaveBmp:HBITMAP,    hPrevSaveBmp:HBITMAP
  local hMemDC :HDC, hAndMemBmp:HBITMAP,  hPrevMemBmp:HBITMAP

  mov hTempDC, $invoke(CreateCompatibleDC, hDC)           ;Get a compatible DC
  invoke SelectObject, hTempDC, hBitmap                   ;Select the bitmap into it

  invoke GetObject, hBitmap, sizeof(BITMAP), addr BmpData ;Get info about bitmap
  m2m PntSize.x, BmpData.BITMAP.bmWidth, eax              ;Get width of bitmap
  m2m PntSize.y, BmpData.BITMAP.bmHeight, ecx             ;Get height of bitmap
  invoke DPtoLP, hTempDC, addr PntSize, 1                 ;Convert from device to
                                                          ; logical points
  ; WARNING: This function fails if the device coordinates exceed 27 bits, or if the
  ;          converted logical coordinates exceed 32 bits. In the case of such an overflow,
  ;          the results for all the points are undefined.

  ; Create some DCs to hold temporary data.
  mov hBackDC, $invoke(CreateCompatibleDC, hDC)           ;Create another DC
  mov hObjDC,  $invoke(CreateCompatibleDC, hDC)           ;Create a third DC
  mov hMemDC,  $invoke(CreateCompatibleDC, hDC)           ;Create a fourth DC
  mov hSaveDC, $invoke(CreateCompatibleDC, hDC)           ;Create a fifth DC

  ; Create a bitmap for each DC. DCs are required for a number of GDI functions.
  mov hAndBackBmp, $invoke(CreateBitmap, PntSize.x, PntSize.y, 1, 1, NULL)  ;Monochrome Bmp
  mov hAndObjBmp,  $invoke(CreateBitmap, PntSize.x, PntSize.y, 1, 1, NULL)  ;Monochrome Bmp
  mov hAndMemBmp,  $invoke(CreateCompatibleBitmap, hDC, PntSize.x, PntSize.y)  ;Normal Bmp
  mov hSaveBmp,    $invoke(CreateCompatibleBitmap, hDC, PntSize.x, PntSize.y)  ;Noraml Bmp

  ; Each DC must select a bitmap object to store pixel data.
  mov hPrevBackBmp, $invoke(SelectObject, hBackDC, hAndBackBmp)
  mov hPrevObjBmp,  $invoke(SelectObject, hObjDC, hAndObjBmp)
  mov hPrevMemBmp,  $invoke(SelectObject, hMemDC, hAndMemBmp)
  mov hPrevSaveBmp, $invoke(SelectObject, hSaveDC, hSaveBmp)

  ; Set proper mapping mode of the DC holding the 'Bitmap'
  invoke GetMapMode, hDC
  invoke SetMapMode, hTempDC, eax

  ; Save the bitmap sent here, because it will be overwritten.
  invoke BitBlt, hSaveDC, 0, 0, PntSize.x, PntSize.y, hTempDC, 0, 0, SRCCOPY

  ; Set the background color of the source DC to the color.
  ; contained in the parts of the bitmap that should be transparent
  .if (cTransparentColor == TBM_FIRSTPIXEL)
    invoke GetPixel, hTempDC, 0, 0
    mov cTransparentColor, eax
  .endif
  invoke SetBkColor, hTempDC, cTransparentColor
  mov dPrevColor, eax

  ; Create the object mask for the bitmap by performing a BitBlt
  ; from the source bitmap to a monochrome bitmap. hTempDC -> Mono hObjDC
  invoke BitBlt, hObjDC, 0, 0, PntSize.x, PntSize.y, hTempDC, 0, 0, SRCCOPY

  ; Set the background color of the source DC back to the original color.
  invoke SetBkColor, hTempDC, dPrevColor

  ; Create the inverse of the object mask. hObjDC -> Inverse hBackDC
  invoke BitBlt, hBackDC, 0, 0, PntSize.x, PntSize.y, hObjDC, 0, 0, NOTSRCCOPY

  ; Copy the background of the main DC to the destination.
  ; hDC (dest) -> hMemDC
  invoke BitBlt, hMemDC, 0, 0, PntSize.x, PntSize.y, hDC, xStart, yStart, SRCCOPY

  ; Mask out the places where the bitmap will be placed.
  ; hMemDC = hMemDC and hObjDC (+ mask)
  invoke BitBlt, hMemDC, 0, 0, PntSize.x, PntSize.y, hObjDC, 0, 0, SRCAND

  ; Mask out the transparent colored pixels on the bitmap.
  ; hTempDC = hTempDC and hBackDC (- mask)
  invoke BitBlt, hTempDC, 0, 0, PntSize.x, PntSize.y, hBackDC, 0, 0, SRCAND

  ; XOR the bitmap with the background on the destination DC.
  ; hMemDC = hMemDC xor hTempDC (origional)
  invoke BitBlt, hMemDC, 0, 0, PntSize.x, PntSize.y, hTempDC, 0, 0, SRCPAINT

  ; Copy the destination to the screen.
  ; hDC (Destination) = hMemDC (Dest & Bit with transparent)
  invoke BitBlt, hDC, xStart, yStart, PntSize.x, PntSize.y, hMemDC, 0, 0, SRCCOPY

  ; Place the original bitmap back into the bitmap sent here.
  ; Retore the original picture in hTempDC
  invoke BitBlt, hTempDC, 0, 0, PntSize.x, PntSize.y, hSaveDC, 0, 0, SRCCOPY

  ; Delete the memory bitmaps.
  invoke DeleteObject, $invoke(SelectObject, hBackDC, hPrevBackBmp)
  invoke DeleteObject, $invoke(SelectObject, hObjDC, hPrevObjBmp)
  invoke DeleteObject, $invoke(SelectObject, hMemDC, hPrevMemBmp)
  invoke DeleteObject, $invoke(SelectObject, hSaveDC, hPrevSaveBmp)

  ; Delete the memory DCs.
  invoke DeleteDC, hMemDC
  invoke DeleteDC, hBackDC
  invoke DeleteDC, hObjDC
  invoke DeleteDC, hSaveDC
  invoke DeleteDC, hTempDC

  ret
DrawTransparentBitmap endp

end
