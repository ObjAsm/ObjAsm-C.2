; ==================================================================================================
; Title:      QueryCpuVendorStrA_PX.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, June 2026.
;               - Initial release.
;               - Bitness-neutral and platform-independent code.
; ==================================================================================================


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

.code
align ALIGN_CODE
QueryCpuVendorStrA proc uses xbx xdi pString:PSTRINGA
if TARGET_BITNESS eq 32
  invoke QueryCpuidSupported
  .if eax == FALSE
    mov xcx, pString
    mov CHRA ptr [xcx], 0                               ; Set ZTC
    ret                                                 ; Return eax = FALSE (0)
  .endif
endif
  mov xdi, pString
  xor eax, eax
  cpuid
  mov QCHRA ptr [xdi + 00h], ebx
  mov QCHRA ptr [xdi + 04h], edx
  mov QCHRA ptr [xdi + 08h], ecx
  mov CHRA ptr [xdi + 0Ch], 0                           ; Set ZTC
  mov eax, TRUE
  ret
QueryCpuVendorStrA endp

