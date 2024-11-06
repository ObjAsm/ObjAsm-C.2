; ==================================================================================================
; Title:      CreateBitmapFromFileInMem_X.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
;               - Bitness independent code.
; ==================================================================================================


; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  CreateBitmapFromFileInMem
; Purpose:    Create a bitmap from bitmap file data stored in memory.
; Arguments:  Arg1: -> Bitmap data as stored in a .bmp file:
;                   [BITMAPFILEHEADER][BITMAPINFOHEADER][Bits]
; Return:     xax = HBITMAP.
; Links:      http://www.masmforum.com/board/index.php?topic=16267.msg134453#msg134453

.code
align ALIGN_CODE
CreateBitmapFromFileInMem proc uses xbx xdi pBitmapData:POINTER
  invoke CreateDC, $OfsCStr("DISPLAY"), NULL, NULL, NULL
  .if xax != 0
    mov xdi, xax                                        ;xdi = hDC
    mov xbx, pBitmapData                                ;xbx -> BITMAPFILEHEADER
    lea xdx, [xbx + sizeof BITMAPFILEHEADER]            ;xdx -> BITMAPINFOHEADER
    mov eax, [xbx].BITMAPFILEHEADER.bfOffBits           ;Offset to the bitmap bits
    add xbx, xax                                        ;xbx -> bitmap bits
    invoke CreateDIBitmap, xdi, xdx, CBM_INIT, xbx, xdx, DIB_RGB_COLORS
    mov xbx, xax
    invoke DeleteDC, xdi
    mov xax, xbx
  .endif
  ret
CreateBitmapFromFileInMem endp
