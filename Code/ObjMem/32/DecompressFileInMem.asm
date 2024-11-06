; ==================================================================================================
; Title:      DecompressFileInMem.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2023
;               - First release.
; Links:      https://learn.microsoft.com/en-us/windows/win32/api/compressapi/
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
TARGET_STR_TYPE = STR_TYPE_WIDE
% include &ObjMemPath&ObjMemWin.cop

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

% include &ObjMemPath&Common\DecompressFileInMem_X.inc

end
