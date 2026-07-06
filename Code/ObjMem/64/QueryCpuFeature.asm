; ==================================================================================================
; Title:      QueryCpuFeature.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, June 2026
;               - Initial release, replacing IsHardwareFeaturePresent.
;               - Platform-independent code.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMemWin.cop

; --------------------------------------------------------------------------------------------------
; Procedure:  QueryCpuFeature
; Purpose:    Determine whether a specific CPU hardware feature is present and usable on the
;             current system. The procedure is fully table-driven, consulting the QCF_TABLE
;             descriptor array indexed by the supplied QCF_xxx constant. Each QCF_ENTRY
;             encodes the CPUID leaf, subleaf, output register, bit position, vendor filter,
;             OS-managed state (XCR0) requirement and optional flags needed to probe one feature.
;             On 64-bit targets CPUID is architecturally guaranteed; step 1 is omitted and
;             TRUE is the unconditional result of the availability check.
; Arguments:  Arg1: QCF_xxx index constant (0 .. QCF_COUNT-1) identifying the feature to probe.
; Return:     eax = TRUE (1)  if the feature is present and usable.
;             eax = FALSE (0) if any validation step fails, the index is out of range, or the
;             CPUID instruction is unavailable (32-bit targets only).
; Note:       Requires QCF_Table_PX.inc to be included before this file.

% include &IncPath&ObjAsm\QueryCpu.inc
% include &ObjMemPath&Common\QCF-Table_PX.inc
% include &ObjMemPath&Common\QueryCpuFeature_PX.inc

end
