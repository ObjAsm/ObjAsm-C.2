; ==================================================================================================
; Title:      QueryCpuidSupported_PX.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, May 2026
;               - Initial release
;               - Bitness-neutral and platform-independent code.
;               - Only required in 32-bit mode.
;                 CPUID is always available in 64-bit mode, no availability check needed.
; ==================================================================================================


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

OPTION PROC:NONE

.code
align ALIGN_CODE
QueryCpuidSupported proc
if TARGET_BITNESS eq 32
  ; Verify CPUID is available (EFLAGS.ID = bit 21)
  pushfd
  pop eax
  mov ecx, eax                                          ; Save original EFLAGS
  xor eax, 000200000h                                   ; Toggle ID bit (bit 21)
  push eax
  popfd                                                 ; Attempt to modify EFLAGS.ID
  pushfd
  pop eax                                               ; Read back modified EFLAGS
  push ecx
  popfd                                                 ; Restore original EFLAGS
  xor eax, ecx                                          ; Did ID bit change?
  shr eax, 21
  and eax, 1                                            ; Return TRUE (1) or FALSE (0)
else
  mov eax, 1                                            ; Always return TRUE (1) 
endif
  ret
QueryCpuidSupported endp
OPTION PROC:DEFAULT
