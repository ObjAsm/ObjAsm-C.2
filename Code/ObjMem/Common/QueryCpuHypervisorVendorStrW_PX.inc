; ==================================================================================================
; Title:      QueryCpuHypervisorVendorStrW_PX.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, June 2026.
;               - Initial release.
;               - Bitness-neutral and platform-independent code.
; ==================================================================================================


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

.code
align ALIGN_CODE
QueryCpuHypervisorVendorStrW proc uses xbx pString:PSTRINGW
  local bString[MAX_CPU_VENDORSTRING_LENGTH]:CHRA

  invoke QueryCpuFeature, QCF_HYPERVISOR
  .if eax != FALSE  
    mov eax, 40000000h
    cpuid
    mov QCHRA ptr [bString + 00h], ebx
    mov QCHRA ptr [bString + 04h], ecx
    mov QCHRA ptr [bString + 08h], edx

    xor ebx, ebx
    mov xdx, pString
    lea xcx, bString
    .while ebx < MAX_CPU_VENDORSTRING_LENGTH
      movzx ax, CHRA ptr [xcx + xbx]
      mov CHRW ptr [xdx + sizeof(CHRW)*xbx], ax
      inc ebx
    .endw
    mov CHRW ptr [xdx + sizeof(CHRW)*xbx], 0            ; Set ZTC
    mov eax, TRUE
    ret
  .endif
  mov xcx, pString
  mov CHRW ptr [xcx], 0                                 ; Set ZTC
  mov eax, FALSE
  ret
QueryCpuHypervisorVendorStrW endp

