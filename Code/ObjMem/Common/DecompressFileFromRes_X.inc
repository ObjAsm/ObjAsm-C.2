; ==================================================================================================
; Title:      DecompressFileFromRes_X.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2023
;               - First release.
; Links:      https://learn.microsoft.com/en-us/windows/win32/api/compressapi/
; ==================================================================================================


.code
; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  DecompressFileFromRes
; Purpose:    Load a compressed file stored as RCDATA resource and decompress it.
;             Compression should be done using a Microsoft compression algorithm: XPRESS, XPRESS
;             with Huffman encoding, MSZIP or LZMS.
; Arguments:  Arg1: Instance HANDLE.
;             Arg2: Resource ID.
; Return:     xax -> Uncompressed data or NULL if failed.
;             ecx = Uncompressed data size in BYTEs.

align ALIGN_CODE
DecompressFileFromRes proc hInst:HINSTANCE, xFileResID:XWORD
  local hResInfo:HRSRC, hResData:HGLOBAL
  local pCompressedData:POINTER, dCompressedDataSize:DWORD
  local pUncompressedData:POINTER, dUncompressedDataSize:DWORD

  mov pUncompressedData, NULL
  mov dUncompressedDataSize, 0
  invoke FindResource, hInst, xFileResID, RT_RCDATA
  .if xax != NULL
    mov hResInfo, xax
    invoke SizeofResource, hInst, hResInfo
    .if eax != 0
      mov dCompressedDataSize, eax
      invoke LoadResource, hInst, hResInfo
      .if xax != NULL
        mov hResData, xax
        invoke LockResource, xax
        .if xax != NULL
          mov pCompressedData, xax
          invoke DecompressFileInMem, pCompressedData, dCompressedDataSize
          mov pUncompressedData, xax
          mov dUncompressedDataSize, ecx
        .endif
        invoke FreeResource, hResData                 ;Dec reference count & free mem if zero
      .endif
    .endif
  .endif
  mov xax, pUncompressedData
  mov ecx, dUncompressedDataSize
  ret
DecompressFileFromRes endp
