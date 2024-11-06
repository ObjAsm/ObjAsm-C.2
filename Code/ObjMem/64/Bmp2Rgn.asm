; ==================================================================================================
; Title:      Bmp2Rgn.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMemWin.cop

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  Bmp2Rgn
; Purpose:    Create a GDI region based on a device dependant or independent bitmap (DDB or DIB).
;             This region is defined by the non transparent area delimited by the transparent color.
; Arguments:  Arg1: Bitmap HANDLE.
;             Arg2: RGB transparet color.
; Return:     rax = Region HANDLE or zero if failed.

.code
align ALIGN_CODE
Bmp2Rgn proc uses rbx rdi rsi hBmp:HANDLE, dTransparentColor:DWORD
  local Bmp:BITMAP, BmpInfoHdr:BITMAPINFOHEADER, hDC:HDC
  local pBuffer:POINTER, pRectBuffer:POINTER, dRectCount:DWORD
  local dCurrScanLine:DWORD, sdIncrement:SDWORD

  invoke GetObject, hBmp, sizeof(Bmp), addr Bmp
  .if rax != 0
    mov ecx, dTransparentColor            ;Transform the RGB to a BGR color as it is found in mem.
    rol ecx, 8                            ;  RR GG BB AA
    ror cx, 8                             ;  RR GG AA BB
    rol ecx, 16                           ;  AA BB RR GG
    ror cx, 8                             ;  AA BB GG RR
    mov dTransparentColor, ecx

    mov eax, Bmp.bmWidth
    mov BmpInfoHdr.biWidth, eax
    shl eax, $Log2(sizeof(DWORD))         ;Bmp.bmWidth * 4
    mov BmpInfoHdr.biSizeImage, eax
    mov BmpInfoHdr.biSize, sizeof(BmpInfoHdr)

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

    mov ebx, eax
    mul ecx                               ;Max possible number of rects = width x height / 2
    shl eax, 1                            ;max Rects => size
    add eax, ebx                          ;add a scanline
    add eax, sizeof(RGNDATAHEADER)
    invoke VirtualAlloc, NULL, eax, MEM_RESERVE or MEM_COMMIT, PAGE_READWRITE
    .if rax != NULL
      mov pBuffer, rax
      add rax, rbx
      mov pRectBuffer, rax
      mov [rax].RGNDATAHEADER.dwSize, sizeof(RGNDATAHEADER)
      mov [rax].RGNDATAHEADER.iType, RDH_RECTANGLES
      m2z [rax].RGNDATAHEADER.nRgnSize
      add rax, sizeof(RGNDATAHEADER) - sizeof(RECT)
      mov rdi, rax
      mov hDC, $invoke(GetDC, 0)
      xor ebx, ebx
      mov dRectCount, ebx

      .while ebx < Bmp.bmHeight
        mov ecx, sdIncrement
        add dCurrScanLine, ecx
        mov rsi, pBuffer
        invoke GetDIBits, hDC, hBmp, dCurrScanLine, 1, rsi, addr BmpInfoHdr, DIB_RGB_COLORS

        xor ecx, ecx                      ;rcx = 0 => not in region flag
        xor edx, edx                      ;Reset Scanline pixel counter
        .while edx < Bmp.bmWidth
          mov eax, [rsi]
          and eax, 00FFFFFFh              ;Ignore alpha value
          .if eax == dTransparentColor
            .if ecx != 0                  ;Terminate the current Rect
              mov [rdi].RECT.right, edx
              xor ecx, ecx                ;Reset flag
            .endif
          .elseif ecx == 0                ;Start a new Rect
            inc dRectCount
            add rdi, sizeof(RECT)         ;Point to next Rect
            mov eax, ebx
            mov [rdi].RECT.left, edx
            inc eax
            mov [rdi].RECT.top, ebx
            mov [rdi].RECT.bottom, eax
            inc ecx                       ;Set flag
          .endif
          inc edx
          add rsi, 4                      ;Move to next Pixel
        .endw

        .if ecx != 0                      ;Close last Rect
          mov [rdi].RECT.right, edx
        .endif

        inc ebx
      .endw

      mov rax, pRectBuffer
      mov edx, dRectCount
      mov [rax].RGNDATAHEADER.nCount, edx
      shl edx, $Log2(sizeof(RECT))
      add edx, sizeof(RGNDATAHEADER)
      invoke ExtCreateRegion, NULL, edx, pRectBuffer
      mov rbx, rax
      invoke ReleaseDC, 0, hDC
      invoke VirtualFree, pBuffer, 0, MEM_RELEASE
      mov rax, rbx
    .endif
  .endif
  ret
Bmp2Rgn endp

end
