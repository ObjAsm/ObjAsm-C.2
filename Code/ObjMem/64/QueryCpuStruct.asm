; ==================================================================================================
; Title:      QueryCpuStruct.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, June 2026
;               - Initial release.
;               - Platform-independent code.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMemWin.cop

; --------------------------------------------------------------------------------------------------
; Procedure:  QueryCpuStruct
; Purpose:    Extract a set of related CPUID fields into a typed structure.
;             Each field is right-shifted and masked to 32 bits, stored in consecutive DWORD slots
;             of the caller-supplied struct.
; Arguments:  Arg1: QCS_xxx index (0-based, must be < QCS_COUNT).
;             Arg2: -> QCSTRUCT_xxx structure.
; Return:     eax = field count   All fields extracted and stored.
;             eax = 0             Failure: out of bounds, vendor mismatch, leaf unsupported.
; Note:       Requires QCS-Table_PX.inc to be included before this file.
;             CPUID is always available in 64-bit mode; no availability check needed.

% include &IncPath&ObjAsm\QueryCpu.inc
% include &ObjMemPath&Common\QCS-Table_PX.inc
% include &ObjMemPath&Common\QueryCpuStruct_PX.inc

end
