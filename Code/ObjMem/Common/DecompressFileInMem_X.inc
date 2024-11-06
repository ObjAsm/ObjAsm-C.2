; ==================================================================================================
; Title:      DecompressFileInMem_X.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2023
;               - First release.
; Links:      https://learn.microsoft.com/en-us/windows/win32/api/compressapi/
; ==================================================================================================


% include &IncPath&Windows\compressapi.inc
% include &ObjMemPath&Common\CompressSignatures.inc

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  DecompressFileInMem
; Purpose:    Decompress file data that was previously compressed with one of the Cabinet
;             compression algorithms. Checks for header signature first to verify that there is a
;             compressed data and what algorithm to use.
; Arguments:  Arg1: -> Compressed data.
;             Arg2: Compressed data size in BYTEs.
; Return:     xax -> Uncompressed data or NULL if failed.
;             ecx = Uncompressed data size in BYTEs.
; Note:       User should free the decompressed memory when no longer required using MemFree.

.code
align ALIGN_CODE
DecompressFileInMem proc pCompressedBuffer:POINTER, dCompressedBufferSize:DWORD
  ?mov ecx, pCompressedBuffer
  cmp xcx, NULL
  jz Error
  ?mov edx, dCompressedBufferSize
  sub edx, sizeof(DWORD)
  cmp edx, 0
  jle Error
  mov eax, [xcx]
  .if eax == HEADER_MSZIP
    mov eax, COMPRESS_ALGORITHM_MSZIP
  .elseif eax == HEADER_XPRESS
    mov eax, COMPRESS_ALGORITHM_XPRESS
  .elseif eax == HEADER_HUFF
    mov eax, COMPRESS_ALGORITHM_XPRESS_HUFF
  .elseif eax == HEADER_LZMS
    mov eax, COMPRESS_ALGORITHM_LZMS
  .else
    jmp Error
  .endif
  add xcx, sizeof(DWORD)                                ;Skip header signature
  invoke DecompressMem, xcx, edx, eax
  ret

Error:
  xor eax, eax
  xor ecx, ecx
  ret
DecompressFileInMem endp
