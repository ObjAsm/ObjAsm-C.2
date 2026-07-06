; ==================================================================================================
; Title:      QCS-Name_PTX.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, June 2026
;               - Initial release.
;               - Platform-independent, string-type-neutral and bitness-neutral code.
; ==================================================================================================


; --------------------------------------------------------------------------------------------------
; Table:      QCS_NAME
; Purpose:    Flat array of POINTER entries providing human-readable display names for each
;             CPU struct query indexed by the QCS_xxx constants (0 .. QCS_COUNT-1).
;             Each entry holds a pointer to a zero-terminated string literal produced by
;             $OfsTStr, resolved at assembly time to either an ANSI or WIDE-character string
;             according to TARGET_STR_TYPE. The table is consumed by QueryCpuStruct (and any
;             diagnostic / reporting layer built on top of it) to associate a descriptive label
;             with the typed QCSTRUCT_xxx result written into the caller-supplied buffer.
;             The entry order is identical to that of QCS_TABLE in QCS-Table_PX.inc and
;             must be kept in strict one-to-one correspondence with QCS_COUNT.

.const
align sizeof(POINTER)
QCS_NAME label POINTER
POINTER $OfsTStr("Processor version")                           ; 0 QCS_CPU_VERSION
POINTER $OfsTStr("Processor info")                              ; 1 QCS_CPU_INFO
POINTER $OfsTStr("AMD processor version (AMD only)")            ; 2 QCS_AMD_VERSION
POINTER $OfsTStr("AMD topology (AMD only)")                     ; 3 QCS_AMD_TOPOLOGY
POINTER $OfsTStr("XSAVE info")                                  ; 4 QCS_XSAVE_INFO
POINTER $OfsTStr("Address sizes")                               ; 5 QCS_ADDR_SIZES
POINTER $OfsTStr("Processor frequencies in MHz (Intel only)")   ; 6 QCS_INTEL_FREQ
POINTER $OfsTStr("TSC/crystal ratio (Intel only)")              ; 7 QCS_INTEL_TSC
