; ==================================================================================================
; Title:      QCV-Table_PX.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, June 2026
;               - Initial release.
;               - Bitness-neutral and platform-independent code.
; ==================================================================================================


; --------------------------------------------------------------------------------------------------
; Table:      QCV_TABLE
; Purpose:    Descriptor table used by QueryCpuValue to extract single multi-bit CPUID fields
;             into the dVals[0] member of a caller-supplied CPU_VALUE union. The table contains
;             one QCV_ENTRY row per QCV_xxx index constant (QCV_COUNT = 32 entries total).
;
; QCV_ENTRY layout (8 bytes per row):
;   bLeaf      CPUID leaf number (0-255); OR-ed with 80000000h when QCV_FL_EX is set.
;   bSubleaf   CPUID subleaf (0-255).
;   bReg       Output register to read: RG_EAX(0), RG_EBX(1), RG_ECX(2), RG_EDX(3).
;   bBitPos    Least-significant bit of the field within the selected register (0-31).
;   bBitWidth  Width of the field in bits (1-32); result is right-shifted and masked to 32 bits.
;   bVendor    Vendor filter: VF_ANY(0)=all, VF_INTEL(1)=Intel only, VF_AMD(2)=AMD only.
;   bFlags     Bit 0 = QCV_FL_EX: resolve leaf as extended (80000000h + bLeaf).
;   bPad       Reserved (0).
;
;
; Vendor filter values:
;   VF_ANY    = 0   Value available on any CPU
;   VF_INTEL  = 1   Intel only (returns 0 on AMD/other)
;   VF_AMD    = 2   AMD only   (returns 0 on Intel/other)
;
; Flags values:
;   QCV_FL_EX  = 01h  Use extended leaf (0x80000000 + bLeaf)
;
; Notes:
;   - All extracted values are right-shifted and masked to 32 bits, stored in dVals[0].
;   - A return value of 0 indicates failure: vendor mismatch, leaf out of range,
;     or index out of bounds.
; --------------------------------------------------------------------------------------------------

; Reuse VF_ANY, VF_INTEL, VF_AMD, RG_EAX..RG_EDX from QueryCpu.inc

QCV_FL_EX    equ 01h  ; Extended leaf (0x80000000+)

; --------------------------------------------------------------------------------------------------
; QCV_ENTRY - one table row descriptor
; --------------------------------------------------------------------------------------------------

QCV_ENTRY struct
  bLeaf     BYTE  ?   ; CPUID leaf number     (0-255)
  bSubleaf  BYTE  ?   ; CPUID subleaf         (0-255)
  bReg      BYTE  ?   ; Output register       (RG_EAX..RG_EDX)
  bBitPos   BYTE  ?   ; Starting bit position (0-31)
  bBitWidth BYTE  ?   ; Number of bits        (1-32)
  bVendor   BYTE  ?   ; Vendor filter         (VF_ANY / VF_INTEL / VF_AMD)
  bFlags    BYTE  ?   ; QCV_FL_EX or 0
  bPad      BYTE  0   ; Reserved
QCV_ENTRY ends

; --------------------------------------------------------------------------------------------------
; QCV_DEF macro - emits one QCV_ENTRY table row
;
; QCV_DEF leaf, sl, rg, bitpos, bitwidth, vendor, flags
; --------------------------------------------------------------------------------------------------

QCV_DEF macro leaf, sl, rg, bitpos, bitwidth, vendor, flags
  QCV_ENTRY <(leaf), (sl), (rg), (bitpos), (bitwidth), (vendor), (flags), 0>
endm

; Definition in ObjMem.inc

;; QCV_xxx - value index constants
;
;; CPUID(1,0).EAX - Processor version information
;QCV_STEPPING           equ     0     ; Stepping ID (EAX[3:0])
;QCV_MODEL              equ     1     ; Model (EAX[7:4])
;QCV_FAMILY             equ     2     ; Family ID (EAX[11:8])
;QCV_EXT_MODEL          equ     3     ; Extended Model ID (EAX[19:16])
;QCV_EXT_FAMILY         equ     4     ; Extended Family ID (EAX[27:20])
;
;; CPUID(1,0).EBX - Miscellaneous information
;QCV_BRAND_IDX          equ     5     ; Brand Index (EBX[7:0])
;QCV_CLFLUSH_SIZE       equ     6     ; CLFLUSH line size x8 bytes (EBX[15:8])
;QCV_LOGICAL_COUNT      equ     7     ; Max logical processors in package (EBX[23:16])
;QCV_APIC_ID            equ     8     ; Initial APIC ID (EBX[31:24])
;
;; CPUID(0,0).EAX - Maximum basic leaf
;QCV_MAX_BASIC_LEAF     equ     9     ; Maximum basic CPUID leaf supported
;
;; CPUID(80000000h,0).EAX - Maximum extended leaf
;QCV_MAX_EXT_LEAF       equ     10    ; Maximum extended CPUID leaf supported
;
;; CPUID(80000008h,0).EAX - Address size information (cross-vendor)
;QCV_PHYS_ADDR_BITS     equ     11    ; Physical address bits (EAX[7:0])
;QCV_LIN_ADDR_BITS      equ     12    ; Linear address bits (EAX[15:8])
;
;; CPUID(80000008h,0).ECX - AMD core topology
;QCV_AMD_CORE_COUNT     equ     13    ; Core count minus 1 (AMD only, ECX[7:0])
;QCV_AMD_APIC_ID_SIZE   equ     14    ; APIC ID size field (AMD only, ECX[15:12])
;                                     ;   WARNING: on Family 17h+ without leaf 80000026h, core-ID
;                                     ;   shifts are derived from leaf 8000001Eh EBX[15:8] instead.
;
;; CPUID(7,0).EAX - Maximum subleaf for leaf 7
;QCV_MAX_SUBLEAF_7      equ     15    ; Maximum supported subleaf index for leaf 7
;
;; CPUID(24h,0).EBX - AVX10 version
;QCV_AVX10_VERSION      equ     16    ; AVX10 converged ISA version number (Intel only, EBX[7:0])
;
;; CPUID(0Dh,0) - XCR0 supported state mask
;QCV_XCR0_LOWER         equ     17    ; XCR0 supported features bits 31:0  (EAX)
;QCV_XCR0_UPPER         equ     18    ; XCR0 supported features bits 63:32 (EDX)
;
;; CPUID(0Dh,0).EBX / CPUID(0Dh,1).EBX - XSAVE area sizes
;QCV_XSAVE_SIZE_OS      equ     19    ; Max XSAVE area size enabled by OS (EBX[31:0])
;QCV_XSAVE_SIZE_ALL     equ     20    ; Max XSAVE area size for all features (EBX[31:0])
;
;; CPUID(15h,0) - TSC / core crystal clock ratio (Intel only)
;QCV_INTEL_TSC_DENOM    equ     21    ; TSC/crystal ratio denominator (EAX[31:0])
;QCV_INTEL_TSC_NUMER    equ     22    ; TSC/crystal ratio numerator (EBX[31:0])
;QCV_INTEL_CRYSTAL_HZ   equ     23    ; Core crystal clock frequency in Hz (ECX[31:0])
;                                     ;   WARNING: ECX == 0 means frequency not enumerated (common on
;                                     ;   Skylake/Kaby Lake and many others). Callers must treat 0 as
;                                     ;   "not available", not as a valid frequency.
;
;; CPUID(16h,0) - Processor frequency information (Intel only)
;QCV_INTEL_BASE_FREQ    equ     24    ; Base frequency in MHz (EAX[15:0])
;QCV_INTEL_MAX_FREQ     equ     25    ; Maximum frequency in MHz (EBX[15:0])
;QCV_INTEL_BUS_FREQ     equ     26    ; Bus/reference frequency in MHz (ECX[15:0])
;
;; CPUID(8000001Eh,0) - AMD processor topology (AMD only)
;QCV_AMD_EXT_APIC_ID    equ     27    ; Extended APIC ID (EAX[31:0])
;QCV_AMD_CORE_ID        equ     28    ; Logical core ID (EBX[7:0]) — was "Compute Unit ID"; CU concept
;                                     ;   obsolete since Zen. Field is logical core ID on all Zen CPUs.
;QCV_AMD_THREADS_PER_CORE equ   29    ; Threads per core minus 1 (EBX[9:8], 2 bits) — was 8-bit
;                                     ;   "threads per CU"; upper 6 bits are reserved/zero on Zen.
;QCV_AMD_NODE_ID        equ     30    ; Node ID (ECX[7:0])
;QCV_AMD_NODES_PER_PKG  equ     31    ; Nodes per package minus 1 (ECX[10:8])
;                                     ;   WARNING: obsolete on Zen 2+ server parts. Prefer CPUID leaf
;                                     ;   80000026h for CCX/CCD (die) topology where supported.
;
;QCV_COUNT              equ     32    ; Must equal highest index + 1



; --------------------------------------------------------------------------------------------------
; QCV_TABLE - value descriptor table
; --------------------------------------------------------------------------------------------------

align sizeof(POINTER)
QCV_TABLE label QCV_ENTRY

  ; -- CPUID(1,0).EAX - Processor version ----------------------------------------------
  QCV_ENTRY <  1,   0,   RG_EAX,  0,  4, VF_ANY,   0 >         ; 000 QCV_STEPPING
  QCV_ENTRY <  1,   0,   RG_EAX,  4,  4, VF_ANY,   0 >         ; 001 QCV_MODEL
  QCV_ENTRY <  1,   0,   RG_EAX,  8,  4, VF_ANY,   0 >         ; 002 QCV_FAMILY
  QCV_ENTRY <  1,   0,   RG_EAX, 16,  4, VF_ANY,   0 >         ; 003 QCV_EXT_MODEL
  QCV_ENTRY <  1,   0,   RG_EAX, 20,  8, VF_ANY,   0 >         ; 004 QCV_EXT_FAMILY

  ; -- CPUID(1,0).EBX - Miscellaneous information --------------------------------------
  QCV_ENTRY <  1,   0,   RG_EBX,  0,  8, VF_ANY,   0 >         ; 005 QCV_BRAND_IDX
  QCV_ENTRY <  1,   0,   RG_EBX,  8,  8, VF_ANY,   0 >         ; 006 QCV_CLFLUSH_SIZE
  QCV_ENTRY <  1,   0,   RG_EBX, 16,  8, VF_ANY,   0 >         ; 007 QCV_LOGICAL_COUNT
  QCV_ENTRY <  1,   0,   RG_EBX, 24,  8, VF_ANY,   0 >         ; 008 QCV_APIC_ID

  ; -- CPUID(0,0).EAX - Maximum basic leaf ---------------------------------------------
  QCV_ENTRY <  0,   0,   RG_EAX,  0, 32, VF_ANY,   0 >         ; 009 QCV_MAX_BASIC_LEAF

  ; -- CPUID(80000000h,0).EAX - Maximum extended leaf ----------------------------------
  QCV_ENTRY <  0,   0,   RG_EAX,  0, 32, VF_ANY,   QCV_FL_EX > ; 010 QCV_MAX_EXT_LEAF

  ; -- CPUID(80000008h,0).EAX - Address size information -------------------------------
  QCV_ENTRY <  8,   0,   RG_EAX,  0,  8, VF_ANY,   QCV_FL_EX > ; 011 QCV_PHYS_ADDR_BITS
  QCV_ENTRY <  8,   0,   RG_EAX,  8,  8, VF_ANY,   QCV_FL_EX > ; 012 QCV_LIN_ADDR_BITS

  ; -- CPUID(80000008h,0).ECX - AMD core topology --------------------------------------
  QCV_ENTRY <  8,   0,   RG_ECX,  0,  8, VF_AMD,   QCV_FL_EX > ; 013 QCV_AMD_CORE_COUNT
  QCV_ENTRY <  8,   0,   RG_ECX, 12,  4, VF_AMD,   QCV_FL_EX > ; 014 QCV_AMD_APIC_ID_SIZE

  ; -- CPUID(7,0).EAX - Maximum subleaf for leaf 7 -------------------------------------
  QCV_ENTRY <  7,   0,   RG_EAX,  0, 32, VF_ANY,   0 >         ; 015 QCV_MAX_SUBLEAF_7

  ; -- CPUID(24h,0).EBX - AVX10 version (Intel only) ----------------------------------
  QCV_ENTRY <  24h, 0,   RG_EBX,  0,  8, VF_INTEL, 0 >         ; 016 QCV_AVX10_VERSION

  ; -- CPUID(0Dh,0) - XCR0 supported state mask ----------------------------------------
  QCV_ENTRY <  0Dh, 0,   RG_EAX,  0, 32, VF_ANY,   0 >         ; 017 QCV_XCR0_LOWER
  QCV_ENTRY <  0Dh, 0,   RG_EDX,  0, 32, VF_ANY,   0 >         ; 018 QCV_XCR0_UPPER

  ; -- CPUID(0Dh,0).EBX / CPUID(0Dh,1).EBX - XSAVE area sizes -------------------------
  QCV_ENTRY <  0Dh, 0,   RG_EBX,  0, 32, VF_ANY,   0 >         ; 019 QCV_XSAVE_SIZE_OS
  QCV_ENTRY <  0Dh, 1,   RG_EBX,  0, 32, VF_ANY,   0 >         ; 020 QCV_XSAVE_SIZE_ALL

  ; -- CPUID(15h,0) - TSC / core crystal clock ratio (Intel only) ----------------------
  QCV_ENTRY <  15h, 0,   RG_EAX,  0, 32, VF_INTEL, 0 >         ; 021 QCV_INTEL_TSC_DENOM
  QCV_ENTRY <  15h, 0,   RG_EBX,  0, 32, VF_INTEL, 0 >         ; 022 QCV_INTEL_TSC_NUMER
  QCV_ENTRY <  15h, 0,   RG_ECX,  0, 32, VF_INTEL, 0 >         ; 023 QCV_INTEL_CRYSTAL_HZ

  ; -- CPUID(16h,0) - Processor frequency information (Intel only) ---------------------
  QCV_ENTRY <  16h, 0,   RG_EAX,  0, 16, VF_INTEL, 0 >         ; 024 QCV_INTEL_BASE_FREQ
  QCV_ENTRY <  16h, 0,   RG_EBX,  0, 16, VF_INTEL, 0 >         ; 025 QCV_INTEL_MAX_FREQ
  QCV_ENTRY <  16h, 0,   RG_ECX,  0, 16, VF_INTEL, 0 >         ; 026 QCV_INTEL_BUS_FREQ

  ; -- CPUID(8000001Eh,0) - AMD processor topology (AMD only) --------------------------
  QCV_ENTRY <  1Eh, 0,   RG_EAX,  0, 32, VF_AMD,   QCV_FL_EX > ; 027 QCV_AMD_EXT_APIC_ID
  QCV_ENTRY <  1Eh, 0,   RG_EBX,  0,  8, VF_AMD,   QCV_FL_EX > ; 028 QCV_AMD_CORE_ID
  QCV_ENTRY <  1Eh, 0,   RG_EBX,  8,  2, VF_AMD,   QCV_FL_EX > ; 029 QCV_AMD_THREADS_PER_CORE
  QCV_ENTRY <  1Eh, 0,   RG_ECX,  0,  8, VF_AMD,   QCV_FL_EX > ; 030 QCV_AMD_NODE_ID
  QCV_ENTRY <  1Eh, 0,   RG_ECX,  8,  3, VF_AMD,   QCV_FL_EX > ; 031 QCV_AMD_NODES_PER_PKG

; Compile-time table size verification
QCV_TABLE_SIZE equ ($ - QCV_TABLE) / sizeof(QCV_ENTRY)
.errnz (QCV_TABLE_SIZE - QCV_COUNT), <QCV_TABLE row count mismatch - update QCV_COUNT>
