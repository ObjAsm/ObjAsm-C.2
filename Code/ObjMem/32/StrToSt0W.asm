; ==================================================================================================
; Title:      StrToSt0W.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
% include &ObjMemPath&ObjMemWin.cop

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  StrToSt0W
; Purpose:    Load a WIDE string representation of a floating point number into the st(0)
;             FPU register.
; Arguments:  Arg1: -> ANSI string floating point number.
; Return:     eax = Result code f_OK or f_ERROR.
; Note:       - Based on the work of Raymond Filiatreault (FpuLib).
;             - Source string should not be greater than 19 chars + zero terminator.

.code
align ALIGN_CODE
StrToSt0W proc uses ebx esi edi pSource:POINTER
  local bBuffer[1024]:BYTE

  invoke StrW2StrA, addr bBuffer, pSource
  invoke StrToSt0A, addr bBuffer
  ret
StrToSt0W endp

end
