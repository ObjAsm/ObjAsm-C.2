; ==================================================================================================
; Title:      QueryCpuBrandStrA.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, June 2026.
;               - Initial release.
;               - Platform-independent code.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
TARGET_STR_TYPE = STR_TYPE_ANSI
% include &ObjMemPath&ObjMemWin.cop

; --------------------------------------------------------------------------------------------------
; Procedure:  QueryCpuBrandStrA
; Purpose:    Retrieve the processor brand identification string as an ANSI string.
;             On 32-bit targets, the presence of CPUID is first verified via
;             QueryCpuidSupported.
;             Each ANSI character is written directly to the caller-supplied buffer, followed
;             by an ANSI zero-terminating character.
; Arguments:  Arg1: -> STRINGA buffer that receives the processor brand string.
;             The buffer must hold at least MAX_CPU_BRANDSTRING_LENGTH + 1 ANSI characters.
; Return:     eax = TRUE (1)  if the brand string was retrieved successfully.
;             eax = FALSE (0) if the CPUID instruction is unavailable (32-bit targets only) or
;             the processor does not support the extended brand string leaves.

% include &IncPath&ObjAsm\QueryCpu.inc
% include &ObjMemPath&Common\QueryCpuBrandStrA_PX.inc

end
