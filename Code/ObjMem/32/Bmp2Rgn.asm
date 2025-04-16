; ==================================================================================================
; Title:      Bmp2Rgn.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
% include &ObjMemPath&ObjMemWin.cop

; --------------------------------------------------------------------------------------------------
; Procedure:  Bmp2Rgn
; Purpose:    Create a GDI region based on a device dependant or independent bitmap (DDB or DIB).
;             This region is defined by the non transparent area delimited by the transparent color.
; Arguments:  Arg1: Bitmap handle.
;             Arg2: RGB transparet color.
; Return:     eax = Region handle or zero if failed.

.code
align ALIGN_CODE
Bmp2Rgn proc uses ebx edi esi hBmp:HANDLE, dTransparentColor:DWORD
  local Bmp:BITMAP, BmpInfoHdr:BITMAPINFOHEADER, hDC:HDC
  local pBuffer:POINTER, pRectBuffer:POINTER, dRectCount:DWORD
  local dCurrScanLine:DWORD, sdIncrement:SDWORD

  invoke GetObject, hBmp, sizeof Bmp, addr Bmp
  .if eax != 0
    mov ecx, dTransparentColor            ;Transform the RGB to a BGR color as it is found in mem.
    rol ecx, 8                            ;  RR GG BB AA
    ror cx, 8                             ;  RR GG AA BB
    rol ecx, 16                           ;  AA BB RR GG
    ror cx, 8                             ;  AA BB GG RR
    mov dTransparentColor, ecx

    mov eax, Bmp.bmWidth
    shl eax, 2
    mov BmpInfoHdr.biSizeImage, eax
    mov BmpInfoHdr.biSize, sizeof BmpInfoHdr
    mov eax, Bmp.bmWidth
    mov BmpInfoHdr.biWidth, eax

    mov ecx, Bmp.bmHeight
    mov BmpInfoHdr.biHeight, ecx

    .if SDWORD ptr (ecx) > 0              ;Detect top-down or bottom-up bitmaps
      mov sdIncrement, -1                 ;Bottom-up bitmap
      mov dCurrScanLine, ecx
    .else
      mov sdIncrement, 1                  ;Top-down bitmap
      mov dCurrScanLine, -1
    .endif

    mov BmpInfoHdr.biPlanes, 1
    mov BmpInfoHdr.biBitCount, 32
    mov BmpInfoHdr.biCompression, BI_RGB

    shl eax, 2                            ;Scanline buffer = Bmp.bmWidth * 4
    push eax
    mul ecx                               ;Max possible number of rects = width x height / 2
    shl eax, 1
    add eax, [esp]
    add eax, sizeof RGNDATAHEADER
    invoke VirtualAlloc, NULL, eax, MEM_RESERVE or MEM_COMMIT, PAGE_READWRITE
    pop ecx
    .if eax != NULL
      mov pBuffer, eax
      add eax, ecx
      mov pRectBuffer, eax
      mov [eax].RGNDATAHEADER.dwSize, sizeof RGNDATAHEADER
      mov [eax].RGNDATAHEADER.iType, RDH_RECTANGLES
      m2z [eax].RGNDATAHEADER.nRgnSize
      add eax, sizeof RGNDATAHEADER - sizeof RECT
      mov edi, eax
      mov hDC, $invoke(GetDC, 0)
      xor ebx, ebx
      mov dRectCount, ebx

      .while ebx < Bmp.bmHeight
        mov ecx, sdIncrement
        add dCurrScanLine, ecx
        invoke GetDIBits, hDC, hBmp, dCurrScanLine, 1, pBuffer, addr BmpInfoHdr, DIB_RGB_COLORS

        mov esi, pBuffer
        xor ecx, ecx                      ;ecx = 0 => not in region flag
        xor edx, edx                      ;Reset Scanline pixel counter
        .while edx < Bmp.bmWidth
          mov eax, [esi]
          and eax, 00FFFFFFh              ;Ignore alpha value
          .if eax == dTransparentColor
            .if ecx != 0                  ;Terminate the current Rect
              mov [edi].RECT.right, edx
              xor ecx, ecx                ;Reset flag
            .endif
          .elseif ecx == 0                ;Start a new Rect
            inc dRectCount
            add edi, sizeof RECT          ;Point to next Rect
            mov eax, ebx
            mov [edi].RECT.left, edx
            inc eax
            mov [edi].RECT.top, ebx
            mov [edi].RECT.bottom, eax
            inc ecx                       ;Set flag
          .endif
          inc edx
          add esi, 4
        .endw

        .if ecx != 0                      ;Close last Rect
          mov [edi].RECT.right, edx
        .endif

        inc ebx
      .endw

      mov eax, pRectBuffer
      mov ecx, dRectCount
      mov [eax].RGNDATAHEADER.nCount, ecx
      shl ecx, 4
      add ecx, sizeof RGNDATAHEADER
      invoke ExtCreateRegion, NULL, ecx, pRectBuffer
      push eax
      invoke ReleaseDC, 0, hDC
      invoke VirtualFree, pBuffer, 0, MEM_RELEASE
      pop eax
    .endif
  .endif
  ret
Bmp2Rgn endp

end
