; ==================================================================================================
; Title:      CreateBitmapFromCompressedFileInRes_X.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2023
;               - First release.
; Links:      https://learn.microsoft.com/en-us/windows/win32/api/compressapi/
; ==================================================================================================


; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  CreateBitmapFromCompressedFileInRes
; Purpose:    Create a bitmap from a compressed bitmap file stored as RCDATA resource.
;             Compression should be done using a Microsoft compression algorithm: XPRESS, XPRESS
;             with Huffman encoding, MSZIP or LZMS.
; Arguments:  Arg1: Instance HANDLE.
;             Arg2: Resource ID.
; Return:     xax = HBITMAP or NULL if failed.

align ALIGN_CODE
CreateBitmapFromCompressedFileInRes proc hInst:HINSTANCE, xResourceID:XWORD
  local pData:POINTER, hBitmap:HBITMAP

  mov hBitmap, 0
if TARGET_BITNESS eq 32
  invoke DecompressFileFromRes, hInst, xResourceID
else
  invoke DecompressFileFromRes, xcx, xdx
endif
  .if xax != NULL
    mov pData, xax
    invoke CreateBitmapFromFileInMem, xax
    .if xax != NULL
      mov hBitmap, xax
    .endif
    MemFree pData
  .endif
  mov xax, hBitmap
  ret
CreateBitmapFromCompressedFileInRes endp
