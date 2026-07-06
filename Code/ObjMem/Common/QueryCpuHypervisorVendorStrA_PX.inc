; ==================================================================================================
; Title:      QueryCpuHypervisorVendorStrA_PX.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, June 2026.
;               - Initial release.
;               - Bitness-neutral and platform-independent code.
; ==================================================================================================


; --------------------------------------------------------------------------------------------------
; Procedure:  QueryCpuHypervisorVendorStrA
; Purpose:    Retrieve the hypervisor vendor identification string as an ANSI string.
;             First verifies that a hypervisor is present by calling QueryCpuFeature with
;             QCF_HYPERVISOR. If confirmed, uses CPUID leaf 40000000h to read the 12-byte vendor
;             ID from ebx, ecx and edx, then copies each byte directly into the caller-supplied
;             buffer. If no hypervisor is detected, the buffer is zeroed and FALSE is returned
;             immediately.
; Arguments:  Arg1: -> STRINGA buffer that receives the hypervisor vendor string.
;             The buffer must hold at least MAX_CPU_VENDORSTRING_LENGTH + 1 ANSI characters.
; Return:     eax = TRUE (1)  if a hypervisor is present and the vendor string was retrieved.
;             eax = FALSE (0) if no hypervisor is detected.

.code
align ALIGN_CODE
QueryCpuHypervisorVendorStrA proc uses xbx xdi pString:PSTRINGA
  mov xdi, pString
  invoke QueryCpuFeature, QCF_HYPERVISOR
  .if eax != FALSE  
    mov eax, 40000000h
    cpuid
    mov QCHRA ptr [xdi + 00h], ebx
    mov QCHRA ptr [xdi + 04h], ecx
    mov QCHRA ptr [xdi + 08h], edx
    mov CHRA ptr [xdi + 0Ch], 0                         ; Set ZTC
    mov eax, TRUE
    ret
  .endif
  mov CHRA ptr [xdi], 0                                 ; Set ZTC
  mov eax, FALSE
  ret
QueryCpuHypervisorVendorStrA endp

