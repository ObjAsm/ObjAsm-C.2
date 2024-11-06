; ==================================================================================================
; Title:      CompressMem_X.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2023
;               - First release.
; Links:      https://learn.microsoft.com/en-us/windows/win32/api/compressapi/
; ==================================================================================================


% include &IncPath&Windows\compressapi.inc

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  CompressMem
; Purpose:    Compress memory with one of the Cabinet compression algorithms. 
; Arguments:  Arg1: -> Uncompressed data.
;             Arg2: Uncompressed data size in bytes.
;             Arg3: Compression algorithm [COMPRESS_ALGORITHM_MSZIP, COMPRESS_ALGORITHM_XPRESS,
;                   COMPRESS_ALGORITHM_XPRESS_HUFF, COMPRESS_ALGORITHM_LZMS].
; Return:     xax -> Compressed data or NULL if failed.
;             ecx = Compressed data size in BYTEs.
; Note:       User should free the returned memory when no longer required using MemFree.

.code
align ALIGN_CODE
CompressMem proc pUncompressedData:POINTER, dUncompressedDataSize:DWORD, dCompressionAlgorithm:DWORD 
  local hCompressor:COMPRESSOR_HANDLE
  local pCompressedBuffer:POINTER, xCompressedBufferSize:XWORD
  local xCompressedDataSize:XWORD
  
  mov pCompressedBuffer, NULL
  mov xCompressedDataSize, 0

  ;Create compressor, COMPRESS_ALGORITHM_LZMS & COMPRESS_ALGORITHM_XPRESS_HUFF
  invoke CreateCompressor, dCompressionAlgorithm, NULL, addr hCompressor
  .if eax != FALSE
    ;Get size required first
if TARGET_BITNESS eq 32
    invoke Compress, hCompressor, pUncompressedData, dUncompressedDataSize, \
                     NULL, 0, addr xCompressedBufferSize
else
    mov r8d, dUncompressedDataSize
    invoke Compress, hCompressor, pUncompressedData, r8, \
                     NULL, 0, addr xCompressedBufferSize
endif
    invoke GetLastError
    .if eax == ERROR_INSUFFICIENT_BUFFER
      ;Alloc buffer required
      MemAlloc xCompressedBufferSize
      .if xax != NULL
        mov pCompressedBuffer, xax
        ;Do actual compression now
if TARGET_BITNESS eq 32
        invoke Compress, hCompressor, pUncompressedData, dUncompressedDataSize, \
                         pCompressedBuffer, xCompressedBufferSize, addr xCompressedDataSize
else
        mov r8d, dUncompressedDataSize
        invoke Compress, hCompressor, pUncompressedData, r8, \
                         pCompressedBuffer, xCompressedBufferSize, addr xCompressedDataSize
endif
        .if eax == FALSE
          MemFree pCompressedBuffer
          mov pCompressedBuffer, NULL
          mov xCompressedDataSize, 0
        .endif
      .endif
    .endif
    invoke CloseCompressor, hCompressor
  .endif
  mov xax, pCompressedBuffer
  mov xcx, xCompressedDataSize
  ret
CompressMem endp
