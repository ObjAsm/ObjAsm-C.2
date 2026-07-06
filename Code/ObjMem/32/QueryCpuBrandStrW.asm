; ==================================================================================================
; Title:      QueryCpuBrandStrW.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, June 2026.
;               - Initial release.
;               - Platform-independent code.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
TARGET_STR_TYPE = STR_TYPE_WIDE
% include &ObjMemPath&ObjMemWin.cop

; --------------------------------------------------------------------------------------------------
; Procedure:  QueryCpuBrandStrW
; Purpose:    Retrieve the processor brand identification string as a WIDE-character (UTF-16LE)
;             string. On 32-bit targets, the presence of CPUID is first verified via
;             QueryCpuidSupported.
;             Each WIDE character is written to the caller-supplied buffer, followed by a WIDE
;             zero-terminating character.
; Arguments:  Arg1: -> STRINGW buffer that receives the processor brand string.
;             The buffer must hold at least MAX_CPU_BRANDSTRING_LENGTH + 1 WIDE characters.
; Return:     eax = TRUE (1)  if the brand string was retrieved successfully.
;             eax = FALSE (0) if the CPUID instruction is unavailable (32-bit targets only) or
;             the processor does not support the extended brand string leaves.

% include &IncPath&ObjAsm\QueryCpu.inc
% include &ObjMemPath&Common\QueryCpuBrandStrW_PX.inc

end
