; ==================================================================================================
; Title:      FindFileA.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
TARGET_STR_TYPE = STR_TYPE_ANSI
% include &ObjMemPath&ObjMemWin.cop

ProcName textequ <FindFileA>
??SearchInDir textequ <??SearchInDirA>
FIND_FILE_PARAMS textequ <FIND_FILE_PARAMSA>

FIND_FILE_PARAMSA struct
  pFileName   POINTER    ?
  pRetBuffer  POINTER    ?
  pFilter     POINTER    ?
  cPreStr     CHRA       MAX_PATH DUP(?)
FIND_FILE_PARAMSA ends

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  FindFileA
; Purpose:    Search for a file in a list of paths.
; Arguments:  Arg1: -> File name.
;             Arg2: -> List of path strings. The end of the list is indicated with a ZTC.
;             Arg3: -> Buffer containing the full path and file name in which the file was found.
;                      Buffer length = MAX_PATH.
; Return:     eax = Number of chars copied to the destination buffer. 0 if the file was not found.
; Example:    invoke FindFile, $OfsCStr("free.inc"), $OfsCStr("\Here*",0), addr cBuf
;               Search free.inc in all \Here and suddirectories.

% include &ObjMemPath&Common\FindFile_TX.inc

end
