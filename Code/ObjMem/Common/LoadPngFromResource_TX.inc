; ==================================================================================================
; Title:      LoadPngFromResource_TX.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, August 2022
;               - First release.
;               - Bitness and String independent code.
; ==================================================================================================


GDIPVER equ 0100h
% include &IncPath&Windows\GdiplusPixelFormats.inc
% include &IncPath&Windows\GdiplusInit.inc
% include &IncPath&Windows\GdiplusEnums.inc
% include &IncPath&Windows\GdiplusGpStubs.inc
% include &IncPath&Windows\GdiPlusFlat.inc

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  LoadPngFromResourceA / LoadPngFromResourceW
; Purpose:    Load a PNG resource and return a bitmap HANDLE.
; Arguments:  Arg1: -> Resource name or ID. 
; Return:     xax = hBitmap or zero if failed.

.code
align ALIGN_CODE
ProcName proc pResName:PSTRING
  local GPSI:GdiplusStartupInput, xToken:XWORD
  local pBitmap:ptr GpBitmap, hBmp:HBITMAP
  local hResource:HRSRC, dResSize:DWORD, pResource:POINTER
  local hGlobal:HANDLE, pIStream:ptr IStream, pMem:POINTER

  mov hBmp, 0
  mov GPSI.GdiplusVersion, 1
  mov GPSI.DebugEventCallback, NULL
  mov GPSI.SuppressBackgroundThread, FALSE
  invoke GdiplusStartup, addr xToken, addr GPSI, NULL
  .if eax == 0
    invoke FindResource, hInstance, pResName, $OfsCStr("PNG")
    .if xax != 0
      mov hResource, xax
      mov dResSize, $32($invoke(SizeofResource, 0, hResource))
      mov pResource, $invoke(LoadResource, hInstance, hResource)
      invoke GlobalAlloc, GMEM_MOVEABLE, dResSize
      .if xax != 0
        mov hGlobal, xax
        mov pMem, $invoke(GlobalLock, hGlobal)
        invoke MemClone, pMem, pResource, dResSize
        invoke GlobalUnlock, hGlobal
        invoke CreateStreamOnHGlobal, hGlobal, 0, addr pIStream
        invoke GdipCreateBitmapFromStream, pIStream, addr pBitmap
        .if eax == 0
          invoke GdipCreateHBITMAPFromBitmap, pBitmap, addr hBmp, 0
          invoke GdipDisposeImage, pBitmap
        .endif
        invoke GlobalFree, hGlobal
      .endif
      invoke FreeResource, hResource
    .endif
    invoke GdiplusShutdown, xToken
  .endif
  mov xax, hBmp
  ret
ProcName endp

