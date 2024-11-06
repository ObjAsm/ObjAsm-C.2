; ==================================================================================================
; Title:      CompressMem.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2023
;               - First release.
; Links:      https://learn.microsoft.com/en-us/windows/win32/api/compressapi/
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
TARGET_STR_TYPE = STR_TYPE_WIDE
% include &ObjMemPath&ObjMemWin.cop

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

% include &ObjMemPath&Common\CompressMem_X.inc

end
