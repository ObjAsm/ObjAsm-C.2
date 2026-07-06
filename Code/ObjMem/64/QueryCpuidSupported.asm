; ==================================================================================================
; Title:      QueryCpuidSupported.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, May 2026
;               - Initial release
;               - Only required in 32-bit mode.
;                 CPUID is always available in 64-bit mode, no availability check needed.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMemWin.cop

; --------------------------------------------------------------------------------------------------
; Procedure:  QueryCpuidSupported
; Purpose:    Determine whether the processor supports the CPUID instruction.
;             On 32-bit targets, detection is performed by attempting to toggle bit 21 (ID flag)
;             of the EFLAGS register. The ID bit is saved, flipped via the stack, read back and
;             then compared against the original value. If the bit changed, the processor honours
;             the ID flag and CPUID is supported. The original EFLAGS are restored before
;             returning. On 64-bit targets, CPUID is architecturally guaranteed to be present,
;             so TRUE is returned unconditionally without touching EFLAGS.
; Arguments:  None.
; Return:     eax = TRUE (1)  if the CPUID instruction is supported.
;             eax = FALSE (0) if the CPUID instruction is not supported (32-bit targets only).

% include &IncPath&ObjAsm\QueryCpu.inc
% include &ObjMemPath&Common\QueryCpuidSupported_PX.inc

end
