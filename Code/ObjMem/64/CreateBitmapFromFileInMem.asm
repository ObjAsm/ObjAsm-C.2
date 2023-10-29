; ==================================================================================================
; Title:      CreateBitmapFromFileInMem.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2023
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
TARGET_STR_TYPE = STR_TYPE_WIDE
% include &ObjMemPath&ObjMemWin.cop

.code
; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  CreateBitmapFromFileInMem
; Purpose:    Create a bitmap from bitmap file data stored in memory.
; Arguments:  Arg1: -> Bitmap data as stored in a .bmp file:
;                   [BITMAPFILEHEADER][BITMAPINFOHEADER][Bits]
; Return:     xax = HBITMAP.
; Links:      http://www.masmforum.com/board/index.php?topic=16267.msg134453#msg134453

% include &ObjMemPath&Common\CreateBitmapFromFileInMem_X.inc

end

