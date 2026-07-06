; ==================================================================================================
; Title:      QueryCpuValue.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, June 2026
;               - Initial release.
;               - Platform-independent code.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
% include &ObjMemPath&ObjMemWin.cop

; --------------------------------------------------------------------------------------------------
; Procedure:  QueryCpuValue
; Purpose:    Return a numeric value extracted from a CPUID register field.
;             The value is right-shifted and masked to 32 bits and stored in
;             pReturnedValue -> dVals[0].
; Arguments:  Arg1: QCV_xxx index (0-based, must be < QCV_COUNT).
;             Arg2: -> CPU_VALUE structure to receive the result.
; Return:     eax = 1  Value successfully extracted and stored.
;             eax = 0  Failure: index out of bounds, vendor mismatch, or leaf unsupported.
; Note:       Requires QCV-Table_PX.inc to be included before this file.
;             CPUID is always available in 64-bit mode; no availability check needed.

% include &IncPath&ObjAsm\QueryCpu.inc
% include &ObjMemPath&Common\QCV-Table_PX.inc
% include &ObjMemPath&Common\QueryCpuValue_PX.inc

end
