; ==================================================================================================
; Title:      QueryCpuBrandStrW_PX.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, June 2026.
;               - Initial release.
;               - Bitness-neutral and platform-independent code.
; ==================================================================================================


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

.code
align ALIGN_CODE
QueryCpuBrandStrW proc uses xbx xdi pString:PSTRINGW
  local bString[MAX_CPU_BRANDSTRING_LENGTH]:CHRA

if TARGET_BITNESS eq 32
  invoke QueryCpuidSupported
  test eax, eax
  jz @F
endif
  mov eax, 80000000h
  lea xdi, bString
  cpuid
  .if eax >= 80000004h                                  ; Check brand string availability
    mov eax, 80000002h                                  ; Get the brand string
    cpuid
    mov [xdi + 00h], eax
    mov [xdi + 04h], ebx
    mov [xdi + 08h], ecx
    mov [xdi + 0Ch], edx
    mov eax, 80000003h
    cpuid
    mov [xdi + 10h], eax
    mov [xdi + 14h], ebx
    mov [xdi + 18h], ecx
    mov [xdi + 1Ch], edx
    mov eax, 80000004h
    cpuid
    mov [xdi + 20h], eax
    mov [xdi + 24h], ebx
    mov [xdi + 28h], ecx
    mov [xdi + 2Ch], edx

    xor ebx, ebx
    mov xdx, pString
    lea xcx, bString
    .while ebx < MAX_CPU_BRANDSTRING_LENGTH
      movzx ax, CHRA ptr [xcx + xbx]
      mov CHRW ptr [xdx + sizeof(CHRW)*xbx], ax
      inc ebx
    .endw
    mov CHRW ptr [xdx + sizeof(CHRW)*xbx], 0            ; Set ZTC
    mov eax, TRUE
    ret
  .endif
@@:
  mov xcx, pString
  mov CHRW ptr [xcx], 0                                 ; Set ZTC
  mov eax, FALSE
  ret
QueryCpuBrandStrW endp

