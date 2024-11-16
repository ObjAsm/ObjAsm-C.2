; ==================================================================================================
; Title:      DecompressMem.asm
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
; Procedure:  DecompressMem
; Purpose:    Decompress memory that was previously compressed with one of the Cabinet compression
;             algorithms.
; Arguments:  Arg1: -> Compressed data.
;             Arg2: Compressed data size in BYTEs.
;             Arg3: Decompression algorithm [COMPRESS_ALGORITHM_MSZIP, COMPRESS_ALGORITHM_XPRESS,
;                   COMPRESS_ALGORITHM_XPRESS_HUFF, COMPRESS_ALGORITHM_LZMS].
; Return:     rax -> Uncompressed data or NULL if failed.
;             ecx = Uncompressed data size in BYTEs.
; Note:       User should free the decompressed memory when no longer required using MemFree.

% include &ObjMemPath&Common\DecompressMem_X.inc

end
