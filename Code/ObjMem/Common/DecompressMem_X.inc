; ==================================================================================================
; Title:      DecompressMem_X.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2023
;               - First release.
; Links:      https://learn.microsoft.com/en-us/windows/win32/api/compressapi/
; ==================================================================================================


% include &IncPath&Windows\compressapi.inc

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  DecompressMem
; Purpose:    Decompress memory that was previously compressed with one of the Cabinet compression
;             algorithms.
; Arguments:  Arg1: -> Compressed data.
;             Arg2: Compressed data size in BYTEs.
;             Arg3: Decompression algorithm [COMPRESS_ALGORITHM_MSZIP, COMPRESS_ALGORITHM_XPRESS,
;                   COMPRESS_ALGORITHM_XPRESS_HUFF, COMPRESS_ALGORITHM_LZMS].
; Return:     xax -> Uncompressed data or NULL if failed.
;             xcx = Uncompressed data size in BYTEs.
; Note:       User should free the decompressed memory when no longer required using MemFree.

.code
align ALIGN_CODE
DecompressMem proc pCompressedData:POINTER, dCompressedDataSize:DWORD, dDecompressionAlgorithm:DWORD
  local hDecompressor:DECOMPRESSOR_HANDLE, xDataSize:XWORD
  local pUncompressedBuffer:POINTER, xUncompressedBufferSize:XWORD, xUncompressedDataSize:XWORD

  mov pUncompressedBuffer, NULL
  mov xUncompressedDataSize, 0

if TARGET_BITNESS eq 32
  .if pCompressedData != NULL && dCompressedDataSize != 0
    mov eax, dCompressedDataSize
    mov xDataSize, eax
else
  .if xcx != NULL && edx != 0
    mov xDataSize, rdx
endif
    ;Create decompressor
    invoke CreateDecompressor, dDecompressionAlgorithm, NULL, addr hDecompressor
    .if eax != FALSE
      ;Get size required
      lea xax, xUncompressedBufferSize
      invoke Decompress, hDecompressor, pCompressedData, xDataSize, NULL, 0, xax
      invoke GetLastError
      .if eax == ERROR_INSUFFICIENT_BUFFER
        ;Alloc buffer required
        MemAlloc xUncompressedBufferSize
        .if xax != NULL
          mov pUncompressedBuffer, xax
          ;Do the actual decompression now
          invoke Decompress, hDecompressor, pCompressedData, xDataSize, \
                             pUncompressedBuffer, xUncompressedBufferSize, \
                             addr xUncompressedDataSize
          .if eax == FALSE
            MemFree pUncompressedBuffer
            mov pUncompressedBuffer, NULL
            mov xUncompressedDataSize, 0
          .endif
        .endif
      .endif
      invoke CloseDecompressor, hDecompressor
    .endif
  .endif
  mov xax, pUncompressedBuffer
  mov xcx, xUncompressedDataSize
  ret
DecompressMem endp
