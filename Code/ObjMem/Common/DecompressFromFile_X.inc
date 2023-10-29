; ==================================================================================================
; Title:      DecompressFromFile_X.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2023
;               - First release.
; Links:      https://learn.microsoft.com/en-us/windows/win32/api/compressapi/
; ==================================================================================================


.code
; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  DecompressFromFile
; Purpose:    Decompress file data that was previously compressed with one of the Cabinet
;             compression algorithms. Checks for header signature first to verify that there is a
;             compressed data and what algorithm to use.
; Arguments:  Arg1: -> Compressed data.
;             Arg2: Compressed data size in BYTEs.
; Return:     xax -> Uncompressed data or NULL if failed.
;             ecx = Uncompressed data size in BYTEs.
; Note:       User should free the decompressed memory when no longer required using MemFree.

align ALIGN_CODE
DecompressFromFile proc hFile:HANDLE
  local dBytesRead:DWORD
  local pCompressedBuffer:POINTER, dCompressedBufferSize:DWORD
  local pUncompressedData:POINTER, dUncompressedDataSize:DWORD

  mov pUncompressedData, NULL
  mov dUncompressedDataSize, 0
if TARGET_BITNESS eq 32
  invoke GetFileSize, hFile, NULL
else
  invoke GetFileSize, xcx, NULL
endif
  mov dCompressedBufferSize, eax
  MemAlloc eax
  .if xax != NULL
    mov pCompressedBuffer, xax
    invoke ReadFile, hFile, pCompressedBuffer, dCompressedBufferSize, addr dBytesRead, NULL
    .if eax != FALSE
      invoke DecompressFileInMem, pCompressedBuffer, dBytesRead
      mov pUncompressedData, xax
      mov dUncompressedDataSize, ecx
    .endif
    MemFree pCompressedBuffer
  .endif
  mov xax, pUncompressedData
  mov ecx, dUncompressedDataSize
  ret
DecompressFromFile endp

