; ==================================================================================================
; Title:      DbgBuildBmpMsg_X.inc
; Author:     G. Friedrich
; Version:    C.1.1
; Notes:      Version C.1.0, November 2023
;               - First release.
; ==================================================================================================


; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  DbgBuildBmpMsg
; Purpose:    Debug helper proc that builds a structure in memory to send a bitmap to the
;             DebugCenter server.
; Arguments:  Arg1: Bitamp HANDLE.
;             Arg2: Background RGB color value.
;             Arg3: -> Destination Window WIDE name.
; Return:     xax -> Allocated memory containig the message.
;                   When no longer needed, it should be deallocated using MemFree.
;             ecx = Byte size of the allocated memory block.

; dSize = sizeof(DBG_HEADER_INFO) + sizeof(pDest) + sizeof(DBG_BMP_INFO) + sizeof(Bitmap)
;         ---------------------------------------   --------------------------------------
;                         dSize1                                     dSize2

.code
align ALIGN_CODE
DbgBuildBmpMsg proc uses xdi xsi hBmp:HANDLE, dBackColor:DWORD, pDest:POINTER
  local pData:POINTER, hDC:HDC, BMI:BITMAPINFO, dSize:DWORD, dSize1:DWORD, dSize2:DWORD

  mov dSize, 0
  .if hBmp != 0
    invoke GetDC, 0
    .if xax
      mov pData, NULL
      mov hDC, xax
      ;Get the Bitmap attributes
      mov BMI.bmiHeader.biSize, sizeof(BITMAPINFOHEADER)
      m2z BMI.bmiHeader.biBitCount
      invoke GetDIBits, hDC, hBmp, 0, 1, NULL, addr BMI, DIB_RGB_COLORS ;Fill only BITMAPINFO
      ;Get memory to transfer the header info & bitmap bits and set DIB properties we want
      mov eax, BMI.bmiHeader.biWidth
      mul BMI.bmiHeader.biHeight
      shl eax, $Log2(sizeof(RGBQUAD))
      mov BMI.bmiHeader.biSizeImage, eax
      add eax, sizeof(DBG_BMP_INFO)
      mov dSize2, eax                                   ;dSize2 = sizeof(DBG_BMP_INFO) + BMP data size
      mov edi, eax
      invoke StrSizeW, pDest
      mov esi, eax                                      ;esi = sizeof(pDest)
      add eax, sizeof(DBG_HEADER_INFO)
      mov dSize1, eax                                   ;dSize1 = sizeof(DBG_HEADER_INFO) + sizeof(pDest)
      add edi, eax
      mov dSize, edi
      MemAlloc edi
      .if xax != NULL
        mov pData, xax
        mov [xax].DBG_HEADER_INFO.bBlockID, DBG_MSG_HDR ;Set block type = header
        mov [xax].DBG_HEADER_INFO.bInfo, 0
        m2m [xax].DBG_HEADER_INFO.dBlockLen, dSize1, edx
        lea xcx, [xax + sizeof(DBG_HEADER_INFO)]
        invoke MemClone, xcx, pDest, esi                ;Copy string "Destrination"
        mov xax, pData
        mov ecx, [xax].DBG_HEADER_INFO.dBlockLen
        add xcx, pData
        mov [xcx].DBG_BMP_INFO.bBlockID, DBG_MSG_BMP    ;Set block type = bitmap
        mov [xax].DBG_BMP_INFO.bInfo, 0
        m2m [xcx].DBG_BMP_INFO.dBlockLen, dSize2, edx
        m2m [xcx].DBG_BMP_INFO.dBackColor, dBackColor, eax
        mov BMI.bmiHeader.biBitCount, 32
        mov BMI.bmiHeader.biCompression, BI_RGB
        lea xdi, [xcx + sizeof(DBG_BMP_INFO)]
        invoke MemClone, addr [xcx].DBG_BMP_INFO.BmpHeader, addr BMI, sizeof(DBG_BMP_INFO.BmpHeader)
        invoke GetDIBits, hDC, hBmp, 0, BMI.bmiHeader.biHeight, xdi, addr BMI, DIB_RGB_COLORS
      .endif
      invoke ReleaseDC, 0, hDC
      mov xax, pData
      mov ecx, dSize
    .else
      xor ecx, ecx
    .endif
  .else
    xor ecx, ecx
  .endif
  ret
DbgBuildBmpMsg endp
