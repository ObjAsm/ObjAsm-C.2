; ==================================================================================================
; Title:      QueryCpuBrandStrA_PX.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, June 2026.
;               - Initial release.
;               - Bitness-neutral and platform-independent code.
; ==================================================================================================


; --------------------------------------------------------------------------------------------------
; Procedure:  QueryCpuBrandStrA
; Purpose:    Retrieve the processor brand identification string as an ANSI string.
;             On 32-bit targets, the presence of CPUID is first verified via
;             QueryCpuidSupported.
;             Each ANSI character is written directly to the caller-supplied buffer, followed
;             by an ANSI zero-terminating character.
; Arguments:  Arg1: -> STRINGA buffer that receives the processor brand string.
;             The buffer must hold at least MAX_CPU_BRANDSTRING_LENGTH + 1 ANSI characters.
; Return:     eax = TRUE (1)  if the brand string was retrieved successfully.
;             eax = FALSE (0) if the CPUID instruction is unavailable (32-bit targets only) or
;             the processor does not support the extended brand string leaves.

.code
align ALIGN_CODE
QueryCpuBrandStrA proc uses xbx xdi pString:PSTRINGA
if TARGET_BITNESS eq 32
  invoke QueryCpuidSupported
  test eax, eax
  jz @F
endif
  mov xdi, pString
  mov eax, 80000000h
  cpuid
  .if eax >= 80000004h                                  ; Check brand string availability
    mov eax, 80000002h                                  ; Get the brand string
    cpuid
    mov QCHRA ptr [xdi + 00h], eax
    mov QCHRA ptr [xdi + 04h], ebx
    mov QCHRA ptr [xdi + 08h], ecx
    mov QCHRA ptr [xdi + 0Ch], edx
    mov eax, 80000003h
    cpuid
    mov QCHRA ptr [xdi + 10h], eax
    mov QCHRA ptr [xdi + 14h], ebx
    mov QCHRA ptr [xdi + 18h], ecx
    mov QCHRA ptr [xdi + 1Ch], edx
    mov eax, 80000004h
    cpuid
    mov QCHRA ptr [xdi + 20h], eax
    mov QCHRA ptr [xdi + 24h], ebx
    mov QCHRA ptr [xdi + 28h], ecx
    mov QCHRA ptr [xdi + 2Ch], edx
    mov CHRA ptr [xdi + 30h], 0                         ; Set ZTC
    mov eax, TRUE
    ret
  .endif
@@:
  mov xcx, pString
  mov CHRA ptr [xcx], 0                                 ; Set ZTC
  mov eax, FALSE
  ret
QueryCpuBrandStrA endp
