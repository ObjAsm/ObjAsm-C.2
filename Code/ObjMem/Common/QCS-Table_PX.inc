; ==================================================================================================
; Title:      QCS-Table_PX.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, June 2026
;               - Initial release.
;               - Bitness-neutral and platform-independent code.
; ==================================================================================================


; --------------------------------------------------------------------------------------------------
; Tables:     QCS_TABLE and QCS_FIELD_TABLE.
; Purpose:    Descriptor tables used by QueryCpuStruct to extract multi-field CPUID data into
;             caller-supplied typed structs. QCS_TABLE is the main fixed-row table, one QCS_ENTRY
;             per QCS_xxx index constant. QCS_FIELD_TABLE is a flat array of QCS_FIELD_ENTRY
;             descriptors shared by all main table rows; each QCS_ENTRY references a contiguous
;             slice of it via wFieldIndex (start) and bFieldCount (count). Fields are extracted
;             as 32-bit DWORDs, right-shifted and masked according to bBitPos and bBitWidth, and
;             stored consecutively in the caller-supplied struct in descriptor order.
;
; QCS_ENTRY layout (8 bytes per row):
;   bLeaf        Default CPUID leaf (0-255); OR-ed with 80000000h when QCS_FL_EX is set.
;   bSubleaf     Default CPUID subleaf (0-255), used unless QCS_FIELD_ENTRY.bSlOverride != 0.
;   bFieldCount  Number of consecutive QCS_FIELD_ENTRY descriptors belonging to this row.
;   bVendor      Vendor filter: VF_ANY(0)=all, VF_INTEL(1)=Intel only, VF_AMD(2)=AMD only.
;   bFlags       Bit 0 = QCS_FL_EX: resolve leaf as extended (80000000h + bLeaf).
;   wFieldIndex  Index of the first QCS_FIELD_ENTRY in QCS_FIELD_TABLE for this row.
;
; QCS_FIELD_ENTRY layout (4 bytes per descriptor):
;   bReg         CPUID output register to read: RG_EAX(0), RG_EBX(1), RG_ECX(2), RG_EDX(3).
;   bBitPos      Least-significant bit of the field within the selected register (0-31).
;   bBitWidth    Width of the field in bits (1-32); result is right-shifted and masked to 32 bits.
;   bSlOverride  Subleaf override: 0 = use the QCS_ENTRY header subleaf; non-zero = use this
;                value as the subleaf for this individual field's CPUID call.
;
; Table contents (QCS_COUNT = 8):
;
;   Index  Constant          Leaf        Subleaf  Vendor    Fields (in struct order)
;   -----  ----------------  ----------  -------  --------  --------------------------------------------------
;     0    QCS_CPU_VERSION   00000001h       0    VF_ANY    Stepping, Model, Family, ExtModel, ExtFamily
;     1    QCS_CPU_INFO      00000001h       0    VF_ANY    BrandIdx, CLFlushSize, LogicalCount, ApicID
;     2    QCS_AMD_VERSION   80000001h       0    VF_AMD    Stepping, Model, Family, ExtModel, ExtFamily
;     3    QCS_AMD_TOPOLOGY  8000001Eh       0    VF_AMD    ExtApicID, CoreID, ThreadsPerCore,
;                                                           NodeID, NodesPerPkg
;     4    QCS_XSAVE_INFO    0000000Dh     0/1    VF_ANY    XCR0Lower, XCR0Upper, SizeOS (sl=0),
;                                                           SizeAll (sl=1 via bSlOverride)
;     5    QCS_ADDR_SIZES    80000008h       0    VF_ANY    PhysAddrBits, LinAddrBits
;     6    QCS_INTEL_FREQ    00000016h       0    VF_INTEL  BaseFreqMHz, MaxFreqMHz, BusFreqMHz
;     7    QCS_INTEL_TSC     00000015h       0    VF_INTEL  Denominator, Numerator, CrystalHz
;
; Vendor filter values (bVendor):
;   VF_ANY    = 0   Value available on any CPU
;   VF_INTEL  = 1   Intel only (returns 0 on AMD/other)
;   VF_AMD    = 2   AMD only   (returns 0 on Intel/other)
;
; Flags (bFlags):
;   QCS_FL_EX = 01h   Use extended leaf (actual leaf = 0x80000000 + bLeaf)
;
; bSlOverride (in QCS_FIELD_ENTRY):
;   0          Use the subleaf from the QCS_ENTRY header
;   non-zero   Use this value as the subleaf for this field's CPUID call
;
; Return value (QueryCpuStruct):
;   EAX = bFieldCount  All fields extracted and stored in pReturnedStruct
;   EAX = 0            Failure: index out of bounds, vendor mismatch, or leaf unsupported
;
; Fields are stored as consecutive DWORDs in the caller-supplied typed struct, in the same order as
; the QCS_FIELD_ENTRY descriptors.
; --------------------------------------------------------------------------------------------------

; Reuse VF_ANY, VF_INTEL, VF_AMD, RG_EAX..RG_EDX from other tables.

QCS_FL_EX     equ 01h                ; Extended leaf (0x80000000+)

; --------------------------------------------------------------------------------------------------
; QCS_ENTRY - main table row structure (8 bytes)
; --------------------------------------------------------------------------------------------------

QCS_ENTRY struct
  bLeaf        BYTE  ?               ; Default CPUID leaf (0-255)
  bSubleaf     BYTE  ?               ; Default CPUID subleaf (0-255)
  bFieldCount  BYTE  ?               ; Number of consecutive QCS_FIELD_ENTRY descriptors
  bVendor      BYTE  ?               ; Vendor filter: VF_ANY / VF_INTEL / VF_AMD
  bFlags       BYTE  ?               ; Bit 0 = QCS_FL_EX
  bPad         BYTE  ?               ; Reserved (0)
  wFieldIndex  WORD  ?               ; Index of first QCS_FIELD_ENTRY in QCS_FIELD_TABLE
QCS_ENTRY ends

; --------------------------------------------------------------------------------------------------
; QCS_FIELD_ENTRY - field descriptor structure (4 bytes)
; --------------------------------------------------------------------------------------------------

QCS_FIELD_ENTRY struct
  bReg         BYTE  ?               ; Register: RG_EAX=0 RG_EBX=1 RG_ECX=2 RG_EDX=3
  bBitPos      BYTE  ?               ; Starting bit position (0-31)
  bBitWidth    BYTE  ?               ; Bits to extract (1-32); result right-shifted/masked to 32 bit
  bSlOverride  BYTE  ?               ; Subleaf override: 0=use header subleaf, non-zero=use this
QCS_FIELD_ENTRY ends

; Definition in QueryCpu.inc

;; QCS_xxx - struct query index constants
;
;; Processor version information - CPUID(1,0).EAX
;; Returns: Stepping, Model, Family, ExtModel, ExtFamily
;QCS_CPU_VERSION       equ   0
;
;; Processor miscellaneous information - CPUID(1,0).EBX
;; Returns: BrandIdx, CLFlushSize, LogicalCount, ApicID
;QCS_CPU_INFO          equ   1
;
;; AMD processor version - CPUID(80000001h,0).EAX (AMD only)
;; Returns: Stepping, Model, Family, ExtModel, ExtFamily
;QCS_AMD_VERSION       equ   2
;
;; AMD processor topology - CPUID(8000001Eh,0) (AMD only)
;; Returns: ExtApicID, CoreID, ThreadsPerCore, NodeID, NodesPerPkg
;QCS_AMD_TOPOLOGY      equ   3
;
;; XSAVE state information - CPUID(0Dh,0/1)
;; Returns: XCR0Lower, XCR0Upper, SizeOS, SizeAll
;QCS_XSAVE_INFO        equ   4
;
;; Physical/linear address sizes - CPUID(80000008h,0).EAX
;; Returns: PhysAddrBits, LinAddrBits
;QCS_ADDR_SIZES        equ   5
;
;; Processor frequency information - CPUID(16h,0) (Intel only)
;; Returns: BaseFreqMHz, MaxFreqMHz, BusFreqMHz
;QCS_INTEL_FREQ        equ   6
;
;; TSC / core crystal clock ratio - CPUID(15h,0) (Intel only)
;; Returns: Denominator, Numerator, CrystalHz
;QCS_INTEL_TSC         equ   7
;
;QCS_COUNT             equ   8       ; Must equal highest index + 1


; --------------------------------------------------------------------------------------------------
; QCS_TABLE - main descriptor table
; --------------------------------------------------------------------------------------------------

align sizeof(POINTER)
QCS_TABLE label QCS_ENTRY
  ;          leaf    sl cnt   vendor   flags    pad   wFieldIdx
  QCS_ENTRY  < 1h,    0,  5, VF_ANY,   0,         0,          0>  ; 0 QCS_CPU_VERSION
  QCS_ENTRY  < 1h,    0,  4, VF_ANY,   0,         0,          5>  ; 1 QCS_CPU_INFO
  QCS_ENTRY  < 1h,    0,  5, VF_AMD,   QCS_FL_EX, 0,          9>  ; 2 QCS_AMD_VERSION
  QCS_ENTRY  <1Eh,    0,  5, VF_AMD,   QCS_FL_EX, 0,         14>  ; 3 QCS_AMD_TOPOLOGY
  QCS_ENTRY  <0Dh,    0,  4, VF_ANY,   0,         0,         19>  ; 4 QCS_XSAVE_INFO
  QCS_ENTRY  < 8h,    0,  2, VF_ANY,   QCS_FL_EX, 0,         23>  ; 5 QCS_ADDR_SIZES
  QCS_ENTRY  <16h,    0,  3, VF_INTEL, 0,         0,         25>  ; 6 QCS_INTEL_FREQ
  QCS_ENTRY  <15h,    0,  3, VF_INTEL, 0,         0,         28>  ; 7 QCS_INTEL_TSC

QCS_COUNT = 8
; Compile-time table size verification
.errnz ((($ - QCS_TABLE) / sizeof(QCS_ENTRY)) - QCS_COUNT), <QCS_TABLE row count mismatch>


; --------------------------------------------------------------------------------------------------
; QCS_FIELD_TABLE - flat array of field descriptors
; --------------------------------------------------------------------------------------------------

align sizeof(QCS_FIELD_ENTRY)
QCS_FIELD_TABLE label QCS_FIELD_ENTRY

  ; -- QCS_CPU_VERSION fields (wFieldIndex=0, bFieldCount=5) ----------------------------
  QCS_FIELD_ENTRY  <RG_EAX,  0,  4, 0>   ; 00 Stepping
  QCS_FIELD_ENTRY  <RG_EAX,  4,  4, 0>   ; 01 Model
  QCS_FIELD_ENTRY  <RG_EAX,  8,  4, 0>   ; 02 Family
  QCS_FIELD_ENTRY  <RG_EAX, 16,  4, 0>   ; 03 ExtModel
  QCS_FIELD_ENTRY  <RG_EAX, 20,  8, 0>   ; 04 ExtFamily

  ; -- QCS_CPU_INFO fields (wFieldIndex=5, bFieldCount=4) -------------------------------
  QCS_FIELD_ENTRY  <RG_EBX,  0,  8, 0>   ; 05 BrandIdx
  QCS_FIELD_ENTRY  <RG_EBX,  8,  8, 0>   ; 06 CLFlushSize
  QCS_FIELD_ENTRY  <RG_EBX, 16,  8, 0>   ; 07 LogicalCount
  QCS_FIELD_ENTRY  <RG_EBX, 24,  8, 0>   ; 08 ApicID

  ; -- QCS_AMD_VERSION fields (wFieldIndex=9, bFieldCount=5) ---------------------------
  QCS_FIELD_ENTRY  <RG_EAX,  0,  4, 0>   ; 09 Stepping
  QCS_FIELD_ENTRY  <RG_EAX,  4,  4, 0>   ; 10 Model
  QCS_FIELD_ENTRY  <RG_EAX,  8,  4, 0>   ; 11 Family
  QCS_FIELD_ENTRY  <RG_EAX, 16,  4, 0>   ; 12 ExtModel
  QCS_FIELD_ENTRY  <RG_EAX, 20,  8, 0>   ; 13 ExtFamily

  ; -- QCS_AMD_TOPOLOGY fields (wFieldIndex=14, bFieldCount=5) -------------------------
  QCS_FIELD_ENTRY  <RG_EAX,  0, 32, 0>   ; 14 ExtApicID
  QCS_FIELD_ENTRY  <RG_EBX,  0,  8, 0>   ; 15 CoreID
  QCS_FIELD_ENTRY  <RG_EBX,  8,  2, 0>   ; 16 ThreadsPerCore
  QCS_FIELD_ENTRY  <RG_ECX,  0,  8, 0>   ; 17 NodeID
  QCS_FIELD_ENTRY  <RG_ECX,  8,  3, 0>   ; 18 NodesPerPkg

  ; -- QCS_XSAVE_INFO fields (wFieldIndex=19, bFieldCount=4) ---------------------------
  ; bSlOverride=0 uses header subleaf (0); bSlOverride=1 overrides to subleaf 1
  QCS_FIELD_ENTRY  <RG_EAX,  0, 32, 0>   ; 19 XCR0Lower  (subleaf 0)
  QCS_FIELD_ENTRY  <RG_EDX,  0, 32, 0>   ; 20 XCR0Upper  (subleaf 0)
  QCS_FIELD_ENTRY  <RG_EBX,  0, 32, 0>   ; 21 SizeOS     (subleaf 0)
  QCS_FIELD_ENTRY  <RG_EBX,  0, 32, 1>   ; 22 SizeAll    (subleaf 1)

  ; -- QCS_ADDR_SIZES fields (wFieldIndex=23, bFieldCount=2) ---------------------------
  QCS_FIELD_ENTRY  <RG_EAX,  0,  8, 0>   ; 23 PhysAddrBits
  QCS_FIELD_ENTRY  <RG_EAX,  8,  8, 0>   ; 24 LinAddrBits

  ; -- QCS_INTEL_FREQ fields (wFieldIndex=25, bFieldCount=3) ---------------------------
  QCS_FIELD_ENTRY  <RG_EAX,  0, 16, 0>   ; 25 BaseFreqMHz
  QCS_FIELD_ENTRY  <RG_EBX,  0, 16, 0>   ; 26 MaxFreqMHz
  QCS_FIELD_ENTRY  <RG_ECX,  0, 16, 0>   ; 27 BusFreqMHz

  ; -- QCS_INTEL_TSC fields (wFieldIndex=28, bFieldCount=3) ----------------------------
  QCS_FIELD_ENTRY  <RG_EAX,  0, 32, 0>   ; 28 Denominator
  QCS_FIELD_ENTRY  <RG_EBX,  0, 32, 0>   ; 29 Numerator
  QCS_FIELD_ENTRY  <RG_ECX,  0, 32, 0>   ; 30 CrystalHz
