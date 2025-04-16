; ==================================================================================================
; Title:      CompressMemToFile_X.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2023
;               - First release.
; Links:      https://learn.microsoft.com/en-us/windows/win32/api/compressapi/
; ==================================================================================================


% include &IncPath&Windows\compressapi.inc
% include &ObjMemPath&Common\CompressSignatures.inc

; --------------------------------------------------------------------------------------------------
; Procedure:  CompressMemToFile
; Purpose:    Compress memory with one of the Cabinet compression algorithms & save it to a file.
; Arguments:  Arg1: -> Uncompressed data.
;             Arg2: Uncompressed data size in bytes.
;             Arg3: Compression algorithm [COMPRESS_ALGORITHM_MSZIP, COMPRESS_ALGORITHM_XPRESS,
;                   COMPRESS_ALGORITHM_XPRESS_HUFF, COMPRESS_ALGORITHM_LZMS].
;             Arg4: File HANDLE.
; Return:     eax = TRUE if succeeded, otherwaise FALSE.

.code
align ALIGN_CODE
CompressMemToFile proc pUncompressedData:POINTER, dUncompressedDataSize:DWORD, \
                       dCompressionAlgorithm:DWORD, hFile:HANDLE
  local pCompressedData:POINTER, dCompressedDataSize:DWORD, dHeader:DWORD, dBytesWritten:DWORD

if TARGET_BITNESS eq 32
  invoke CompressMem, pUncompressedData, dUncompressedDataSize, dCompressionAlgorithm
else
  invoke CompressMem, rcx, edx, r8d
endif
  .if xax != NULL
    mov pCompressedData, xax
    mov dCompressedDataSize, ecx
    mov eax, dCompressionAlgorithm
    .if eax == COMPRESS_ALGORITHM_MSZIP
      mov edx, HEADER_MSZIP
    .elseif eax == COMPRESS_ALGORITHM_XPRESS
      mov edx, HEADER_XPRESS
    .elseif eax == COMPRESS_ALGORITHM_XPRESS_HUFF
      mov edx, HEADER_HUFF
    .elseif eax == COMPRESS_ALGORITHM_LZMS
      mov edx, HEADER_LZMS
    .endif
    mov dHeader, edx
    invoke WriteFile, hFile, addr dHeader, sizeof(dHeader), addr dBytesWritten, NULL
    invoke WriteFile, hFile, pCompressedData, dCompressedDataSize, addr dBytesWritten, NULL
    MemFree pCompressedData
    mov eax, TRUE
  .endif
  ret
CompressMemToFile endp
