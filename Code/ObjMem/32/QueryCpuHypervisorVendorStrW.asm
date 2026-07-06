; ==================================================================================================
; Title:      QueryCpuHypervisorVendorStrW.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, June 2026.
;               - Initial release.
;               - platform-independent code.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
TARGET_STR_TYPE = STR_TYPE_ANSI
% include &ObjMemPath&ObjMemWin.cop

; --------------------------------------------------------------------------------------------------
; Procedure:  QueryCpuHypervisorVendorStrW
; Purpose:    Retrieve the hypervisor vendor identification string as a WIDE-character (UTF-16LE)
;             string. First verifies that a hypervisor is present by calling QueryCpuFeature with
;             QCF_HYPERVISOR. If confirmed, uses CPUID leaf 40000000h to read the 12-byte vendor
;             ID from ebx, ecx and edx, then zero-extends each BYTE to a WIDE character and writes
;             the result to the caller-supplied buffer. If no hypervisor is detected, the buffer
;             is zeroed and FALSE is returned immediately.
; Arguments:  Arg1: -> STRINGW buffer that receives the hypervisor vendor string.
;             The buffer must hold at least MAX_CPU_VENDORSTRING_LENGTH + 1 WIDE characters.
; Return:     eax = TRUE (1)  if a hypervisor is present and the vendor string was retrieved.
;             eax = FALSE (0) if no hypervisor is detected.

% include &IncPath&ObjAsm\QueryCpu.inc
% include &ObjMemPath&Common\QueryCpuHypervisorVendorStrW_PX.inc

end
