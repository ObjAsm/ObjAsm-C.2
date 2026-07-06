; ==================================================================================================
; Title:      QCV-Name_PTX.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, June 2026
;               - Initial release.
;               - Platform-independent, string-type-neutral and bitness-neutral code.
; ==================================================================================================


; --------------------------------------------------------------------------------------------------
; Table:      QCV_NAME
; Purpose:    Flat array of POINTER entries providing human-readable display names for each
;             CPU value field indexed by the QCV_xxx constants (0 .. QCV_COUNT-1).
;             Each entry holds a pointer to a zero-terminated string literal produced by
;             $OfsTStr, resolved at assembly time. The table is consumed by QueryCpuValue
;             (and any diagnostic / reporting layer built on top of it) to associate a
;             descriptive label with the numeric result stored in the CPU_VALUE union.
;             The entry order is identical to that of QCV_TABLE in QCV-Table_PX.inc and
;             must be kept in strict one-to-one correspondence with QCV_COUNT.

.const
align sizeof(POINTER)
QCV_NAME label POINTER
POINTER $OfsTStr("Stepping ID")                                     ; 0   QCV_STEPPING
POINTER $OfsTStr("Model ID")                                        ; 1   QCV_MODEL
POINTER $OfsTStr("Family ID")                                       ; 2   QCV_FAMILY
POINTER $OfsTStr("Extended Model ID")                               ; 3   QCV_EXT_MODEL
POINTER $OfsTStr("Extended Family ID")                              ; 4   QCV_EXT_FAMILY
POINTER $OfsTStr("Brand Index")                                     ; 5   QCV_BRAND_IDX
POINTER $OfsTStr("CLFLUSH line size x8 bytes")                      ; 6   QCV_CLFLUSH_SIZE
POINTER $OfsTStr("Max logical processors in package")               ; 7   QCV_LOGICAL_COUNT
POINTER $OfsTStr("Initial APIC ID")                                 ; 8   QCV_APIC_ID
POINTER $OfsTStr("Maximum basic CPUID leaf")                        ; 9   QCV_MAX_BASIC_LEAF
POINTER $OfsTStr("Maximum extended CPUID leaf")                     ; 10  QCV_MAX_EXT_LEAF
POINTER $OfsTStr("Physical address bits")                           ; 11  QCV_PHYS_ADDR_BITS
POINTER $OfsTStr("Linear address bits")                             ; 12  QCV_LIN_ADDR_BITS
POINTER $OfsTStr("Core count minus 1 (AMD only)")                   ; 13  QCV_AMD_CORE_COUNT
POINTER $OfsTStr("APIC ID size (AMD only)")                         ; 14  QCV_AMD_APIC_ID_SIZE
POINTER $OfsTStr("Maximum subleaf index for leaf 7")                ; 15  QCV_MAX_SUBLEAF_7
POINTER $OfsTStr("AVX10 version number (Intel only)")               ; 16  QCV_AVX10_VERSION
POINTER $OfsTStr("XCR0 supported features bits 31:0")               ; 17  QCV_XCR0_LOWER
POINTER $OfsTStr("XCR0 supported features bits 63:32")              ; 18  QCV_XCR0_UPPER
POINTER $OfsTStr("Max XSAVE area size enabled by OS")               ; 19  QCV_XSAVE_SIZE_OS
POINTER $OfsTStr("Max XSAVE area size for all features")            ; 20  QCV_XSAVE_SIZE_ALL
POINTER $OfsTStr("TSC/crystal ratio denominator (Intel only)")      ; 21  QCV_INTEL_TSC_DENOM
POINTER $OfsTStr("TSC/crystal ratio numerator (Intel only)")        ; 22  QCV_INTEL_TSC_NUMER
POINTER $OfsTStr("Core crystal clock frequency in Hz, 0=not available (Intel only)") ; 23  QCV_INTEL_CRYSTAL_HZ
POINTER $OfsTStr("Base frequency in MHz (Intel only)")              ; 24  QCV_INTEL_BASE_FREQ
POINTER $OfsTStr("Maximum frequency in MHz (Intel only)")           ; 25  QCV_INTEL_MAX_FREQ
POINTER $OfsTStr("Bus/reference frequency in MHz (Intel only)")     ; 26  QCV_INTEL_BUS_FREQ
POINTER $OfsTStr("Extended APIC ID (AMD only)")                     ; 27  QCV_AMD_EXT_APIC_ID
POINTER $OfsTStr("Logical core ID (AMD only)")                      ; 28  QCV_AMD_CORE_ID
POINTER $OfsTStr("Threads per core minus 1 (AMD only)")             ; 29  QCV_AMD_THREADS_PER_CORE
POINTER $OfsTStr("Node ID (AMD only)")                              ; 30  QCV_AMD_NODE_ID
POINTER $OfsTStr("Nodes per package minus 1 (AMD only)")            ; 31  QCV_AMD_NODES_PER_PKG
