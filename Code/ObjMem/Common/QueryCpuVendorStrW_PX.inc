; ==================================================================================================
; Title:      QueryCpuVendorStrW_PX.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, June 2026.
;               - Initial release.
;               - Bitness-neutral and platform-independent code.
; ==================================================================================================


; --------------------------------------------------------------------------------------------------
; Procedure:  QueryCpuVendorStrW
; Purpose:    Retrieve the CPU vendor identification string as a wide-character (UTF-16LE) string.
;             Uses CPUID leaf 0 to read the 12-byte vendor ID from ebx, edx and ecx, then
;             zero-extends each byte to a wide character and writes the result to the caller-
;             supplied buffer. On 32-bit targets, the presence of CPUID is verified first;
;             if unsupported, the buffer is zeroed and FALSE is returned immediately.
; Arguments:  Arg1: -> STRINGW buffer that receives the vendor string.
;             The buffer must hold at least MAX_CPU_VENDORSTRING_LENGTH + 1 WIDE characters.
; Return:     eax = TRUE(1)  if the vendor string was retrieved successfully.
;             eax = FALSE(0) if the CPUID instruction is not supported (32-bit targets only).

.code
align ALIGN_CODE
QueryCpuVendorStrW proc uses xbx pString:PSTRINGW
  local bString[MAX_CPU_VENDORSTRING_LENGTH]:CHRA

if TARGET_BITNESS eq 32
  invoke QueryCpuidSupported
  .if eax == FALSE
    mov xcx, pString
    mov CHRA ptr [xcx], 0                               ; Set ZTC
    ret                                                 ; Return eax = FALSE (0)
  .endif
endif
  xor eax, eax
  cpuid
  mov QCHRA ptr [bString + 00h], ebx
  mov QCHRA ptr [bString + 04h], edx
  mov QCHRA ptr [bString + 08h], ecx

  xor ebx, ebx
  mov xdx, pString
  lea xcx, bString
  .while ebx < MAX_CPU_VENDORSTRING_LENGTH
    movzx ax, CHRA ptr [xcx + xbx]
    mov CHRW ptr [xdx + sizeof(CHRW)*xbx], ax
    inc ebx
  .endw
  mov CHRW ptr [xdx + sizeof(CHRW)*xbx], 0              ; Set ZTC
  mov eax, TRUE
  ret
QueryCpuVendorStrW endp

