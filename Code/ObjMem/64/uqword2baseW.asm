; ==================================================================================================
; Title:      uqword2base.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, November 2024.
;               - First release.
;               - Bitness neutral code.
;             Original proc UINT64__Baseform
;             Modification from bitRAKE's fasmg_playground
;             https://github.com/bitRAKE/fasmg_playground/blob/master/string/baseform.asm
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
TARGET_STR_TYPE = STR_TYPE_WIDE
% include &ObjMemPath&ObjMemWin.cop

ProcName textequ <uqword2baseW>
Signed equ FALSE

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  uqword2baseW
; Purpose:    Convert an unsigned qword to a defined base.
; Arguments:  Arg1: -> Buffer
;             Arg2: Number
;             Arg3: Base.
; Return:     xax -> Transformed number to base x.
;             ecx = BYTEs contained in the buffer, including the ZTC.

% include &ObjMemPath&Common\xword2base_TX.inc

end
