; ==================================================================================================
; Title:      QueryCpuVendorStrA.asm
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
; Procedure:  QueryCpuVendorStrA
; Purpose:    Retrieve the CPU vendor identification string as an ANSI string.
;             Uses CPUID leaf 0 to read the 12-byte vendor ID from ebx, edx and ecx, then
;             copies each byte directly into the caller-supplied buffer.
;             On 32-bit targets, the presence of CPUID is verified first;
;             if unsupported, the buffer is zeroed and FALSE is returned immediately.
; Arguments:  Arg1: -> STRINGA buffer that receives the vendor string.
;             The buffer must hold at least MAX_CPU_VENDORSTRING_LENGTH + 1 ANSI characters.
; Return:     eax = TRUE(1)  if the vendor string was retrieved successfully.
;             eax = FALSE(0) if the CPUID instruction is not supported (32-bit targets only).

% include &IncPath&ObjAsm\QueryCpu.inc
% include &ObjMemPath&Common\QueryCpuVendorStrA_PX.inc

end
