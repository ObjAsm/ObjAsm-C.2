; ==================================================================================================
; Title:      QCF-Table_PX.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, June 2026
;               - Initial release.
;               - Bitness-neutral and platform-independent code.
; ==================================================================================================


; --------------------------------------------------------------------------------------------------
; Structure: QCF_ENTRY
; Purpose:   Describes one entry in QCF_TABLE (8 bytes, QWORD-aligned)
;
; Field details:
;   bLeaf    - Raw CPUID leaf offset.
;              For basic leaves (QCF_FL_EX clear):  actual leaf = bLeaf  (0..FFh)
;              For extended leaves (QCF_FL_EX set):  actual leaf = 80000000h OR bLeaf
;                e.g. bLeaf=1 => 80000001h,  bLeaf=8 => 80000008h
;   bSubleaf - CPUID subleaf (ECX input). 0 for most leaves.
;              For leaf 7: subleaves 0, 1, 2 are used; proc validates against CPUID(7,0).EAX.
;              For leaf 0Dh: subleaf 1 is used; proc validates that XSAVE is OS-enabled.
;   bReg     - Which CPUID output register holds the target bit:
;                0 = EAX  (RG_EAX)
;                1 = EBX  (RG_EBX)
;                2 = ECX  (RG_ECX)
;                3 = EDX  (RG_EDX)
;   bBit     - Bit position within bReg (0-31)
;   bVendor  - Vendor requirement:
;                0 = VF_ANY   (any vendor)
;                1 = VF_INTEL (Intel only, full 3-DWORD "GenuineIntel" check)
;                2 = VF_AMD   (AMD only,   full 3-DWORD "AuthenticAMD" check)
;   bXCR0    - OS XSAVE state enablement check required before the feature is usable:
;                0 = XCRLVL_NONE   (no XCR0 check)
;                1 = XCRLVL_AVX    (XCR0 bits 1,2 must be set: XMM + YMM)
;                2 = XCRLVL_AVX512 (XCR0 bits 1,2,5,6,7 must be set: XMM+YMM+Opmask+ZMM)
;                3 = XCRLVL_AMX    (XCR0 bits 17,18 must be set: XTILECFG+XTILEDATA)
;   bFlags   - Bit 0 = QCF_FL_EX   (set => extended leaf, OR bLeaf with 80000000h)
;              Bit 1 = QCF_FL_IRSV (set => Intel-reserved bit, always FALSE on Intel)
;   bPad     - Reserved, must be 0

QCF_ENTRY struct
  bLeaf     BYTE   ?   ; CPUID leaf offset (see field details above)
  bSubleaf  BYTE   ?   ; CPUID subleaf               (0-255)
  bReg      BYTE   ?   ; Output register             (0=EAX 1=EBX 2=ECX 3=EDX)
  bBit      BYTE   ?   ; Bit position                (0-31)
  bVendor   BYTE   ?   ; Vendor filter               (0=any 1=Intel 2=AMD)
  bXCR0     BYTE   ?   ; XCR0 check level            (0=none 1=AVX 2=AVX-512 3=AMX)
  bFlags    BYTE   ?   ; Bit 0=EX (extended leaf)  Bit 1=IRSV (Intel reserved)
  bPad      BYTE   ?   ; Reserved, must be 0
QCF_ENTRY ends

; Compile-time layout guard: structure must be exactly 8 bytes
.errnz (sizeof QCF_ENTRY - 8), <QCF_ENTRY must be exactly 8 bytes>

; --------------------------------------------------------------------------------------------------
; Table-entry field constants

XCRLVL_NONE   equ 0
XCRLVL_AVX    equ 1
XCRLVL_AVX512 equ 2   ; Mask 0E6h = bits 1,2,5,6,7: XMM+YMM+Opmask+ZMM_Hi256+Hi16_ZMM
XCRLVL_AMX    equ 3

QCF_FL_EX    equ 01h  ; Extended leaf (actual = 80000000h + bLeaf)
QCF_FL_IRSV  equ 02h  ; Intel reserved bit (always returns FALSE on Intel hardware)
QCF_FL_EX2   equ 05h  ; Extended leaf with 2-byte bLeaf (actual = 80000000h + bLeaf);
                       ; bLeaf field holds offset directly (e.g. 21h => 80000021h)

; --------------------------------------------------------------------------------------------------
; Register index constants (matches bReg field encoding)

RG_EAX equ 0
RG_EBX equ 1
RG_ECX equ 2
RG_EDX equ 3

; --------------------------------------------------------------------------------------------------
; Vendor filter constants (matches bVendor field encoding)

VF_ANY   equ 0
VF_INTEL equ 1
VF_AMD   equ 2

; --------------------------------------------------------------------------------------------------
; QCF_DEF macro - emits one QCF_ENTRY table record
;
; QCF_DEF leaf, sl, rg, bit, vendor, xcr0, flags
; --------------------------------------------------------------------------------------------------

QCF_DEF macro leaf, sl, rg, bit, vendor, xcr0, flags
  QCF_ENTRY <leaf, sl, rg, bit, vendor, xcr0, flags, 0>
endm

; ==================================================================================================
; QCF_TABLE - read-only feature descriptor table
; Layout: QCF_DEF  bLeaf, bSubleaf, bReg, bBit, bVendor, bXCR0, bFlags
;
; Extended-leaf encoding reminder:
;   bLeaf is the raw offset added to 80000000h when QCF_FL_EX is set.
;   bLeaf=1 => CPUID leaf 80000001h
;   bLeaf=8 => CPUID leaf 80000008h
;
; Table entries are sorted by (bFlags[EX], bLeaf, bSubleaf, bReg, bBit).
; Entries with QCF_FL_IRSV always return FALSE regardless of CPUID output.
; ==================================================================================================

.const
align 8
QCF_TABLE label QCF_ENTRY

  ; -- CPUID(1,0).EDX --------------------------------------------------------------
  QCF_DEF  1, 0, RG_EDX,  0, VF_ANY,   XCRLVL_NONE,  0            ; 000 QCF_FPU
  QCF_DEF  1, 0, RG_EDX,  1, VF_ANY,   XCRLVL_NONE,  0            ; 001 QCF_VME
  QCF_DEF  1, 0, RG_EDX,  2, VF_ANY,   XCRLVL_NONE,  0            ; 002 QCF_DE
  QCF_DEF  1, 0, RG_EDX,  3, VF_ANY,   XCRLVL_NONE,  0            ; 003 QCF_PSE
  QCF_DEF  1, 0, RG_EDX,  4, VF_ANY,   XCRLVL_NONE,  0            ; 004 QCF_TSC
  QCF_DEF  1, 0, RG_EDX,  5, VF_ANY,   XCRLVL_NONE,  0            ; 005 QCF_MSR
  QCF_DEF  1, 0, RG_EDX,  6, VF_ANY,   XCRLVL_NONE,  0            ; 006 QCF_PAE
  QCF_DEF  1, 0, RG_EDX,  7, VF_ANY,   XCRLVL_NONE,  0            ; 007 QCF_MCE
  QCF_DEF  1, 0, RG_EDX,  8, VF_ANY,   XCRLVL_NONE,  0            ; 008 QCF_CX8
  QCF_DEF  1, 0, RG_EDX,  9, VF_ANY,   XCRLVL_NONE,  0            ; 009 QCF_APIC
  QCF_DEF  1, 0, RG_EDX, 10, VF_INTEL, XCRLVL_NONE,  QCF_FL_IRSV  ; 010 QCF_INTL_RSVD_10
  QCF_DEF  1, 0, RG_EDX, 11, VF_ANY,   XCRLVL_NONE,  0            ; 011 QCF_SEP
  QCF_DEF  1, 0, RG_EDX, 12, VF_ANY,   XCRLVL_NONE,  0            ; 012 QCF_MTRR
  QCF_DEF  1, 0, RG_EDX, 13, VF_ANY,   XCRLVL_NONE,  0            ; 013 QCF_PGE
  QCF_DEF  1, 0, RG_EDX, 14, VF_ANY,   XCRLVL_NONE,  0            ; 014 QCF_MCA
  QCF_DEF  1, 0, RG_EDX, 15, VF_ANY,   XCRLVL_NONE,  0            ; 015 QCF_CMOV
  QCF_DEF  1, 0, RG_EDX, 16, VF_ANY,   XCRLVL_NONE,  0            ; 016 QCF_PAT
  QCF_DEF  1, 0, RG_EDX, 17, VF_ANY,   XCRLVL_NONE,  0            ; 017 QCF_PSE36
  QCF_DEF  1, 0, RG_EDX, 18, VF_INTEL, XCRLVL_NONE,  0            ; 018 QCF_PSN
  QCF_DEF  1, 0, RG_EDX, 19, VF_ANY,   XCRLVL_NONE,  0            ; 019 QCF_CLFSH
  QCF_DEF  1, 0, RG_EDX, 20, VF_INTEL, XCRLVL_NONE,  QCF_FL_IRSV  ; 020 QCF_INTL_RSVD_20
  QCF_DEF  1, 0, RG_EDX, 21, VF_INTEL, XCRLVL_NONE,  0            ; 021 QCF_DS
  QCF_DEF  1, 0, RG_EDX, 22, VF_INTEL, XCRLVL_NONE,  0            ; 022 QCF_ACPI
  QCF_DEF  1, 0, RG_EDX, 23, VF_ANY,   XCRLVL_NONE,  0            ; 023 QCF_MMX
  QCF_DEF  1, 0, RG_EDX, 24, VF_ANY,   XCRLVL_NONE,  0            ; 024 QCF_FXSR
  QCF_DEF  1, 0, RG_EDX, 25, VF_ANY,   XCRLVL_NONE,  0            ; 025 QCF_SSE
  QCF_DEF  1, 0, RG_EDX, 26, VF_ANY,   XCRLVL_NONE,  0            ; 026 QCF_SSE2
  QCF_DEF  1, 0, RG_EDX, 27, VF_INTEL, XCRLVL_NONE,  0            ; 027 QCF_SS
  QCF_DEF  1, 0, RG_EDX, 28, VF_ANY,   XCRLVL_NONE,  0            ; 028 QCF_HTT
  QCF_DEF  1, 0, RG_EDX, 29, VF_INTEL, XCRLVL_NONE,  0            ; 029 QCF_TM
  QCF_DEF  1, 0, RG_EDX, 30, VF_INTEL, XCRLVL_NONE,  QCF_FL_IRSV  ; 030 QCF_INTL_RSVD_30
  QCF_DEF  1, 0, RG_EDX, 31, VF_INTEL, XCRLVL_NONE,  0            ; 031 QCF_PBE

  ; -- CPUID(1,0).ECX --------------------------------------------------------------
  QCF_DEF  1, 0, RG_ECX,  0, VF_ANY,   XCRLVL_NONE,  0            ; 032 QCF_SSE3
  QCF_DEF  1, 0, RG_ECX,  1, VF_ANY,   XCRLVL_NONE,  0            ; 033 QCF_PCLMULQDQ
  QCF_DEF  1, 0, RG_ECX,  2, VF_INTEL, XCRLVL_NONE,  0            ; 034 QCF_DTES64
  QCF_DEF  1, 0, RG_ECX,  3, VF_ANY,   XCRLVL_NONE,  0            ; 035 QCF_MONITOR
  QCF_DEF  1, 0, RG_ECX,  4, VF_INTEL, XCRLVL_NONE,  0            ; 036 QCF_DS_CPL
  QCF_DEF  1, 0, RG_ECX,  5, VF_INTEL, XCRLVL_NONE,  0            ; 037 QCF_VMX
  QCF_DEF  1, 0, RG_ECX,  6, VF_INTEL, XCRLVL_NONE,  0            ; 038 QCF_SMX
  QCF_DEF  1, 0, RG_ECX,  7, VF_INTEL, XCRLVL_NONE,  0            ; 039 QCF_EIST
  QCF_DEF  1, 0, RG_ECX,  8, VF_INTEL, XCRLVL_NONE,  0            ; 040 QCF_TM2
  QCF_DEF  1, 0, RG_ECX,  9, VF_ANY,   XCRLVL_NONE,  0            ; 041 QCF_SSSE3
  QCF_DEF  1, 0, RG_ECX, 10, VF_INTEL, XCRLVL_NONE,  0            ; 042 QCF_CNXT_ID
  QCF_DEF  1, 0, RG_ECX, 11, VF_INTEL, XCRLVL_NONE,  0            ; 043 QCF_SDBG
  QCF_DEF  1, 0, RG_ECX, 12, VF_ANY,   XCRLVL_AVX,   0            ; 044 QCF_FMA
  QCF_DEF  1, 0, RG_ECX, 13, VF_ANY,   XCRLVL_NONE,  0            ; 045 QCF_CX16
  QCF_DEF  1, 0, RG_ECX, 14, VF_INTEL, XCRLVL_NONE,  0            ; 046 QCF_xTPR
  QCF_DEF  1, 0, RG_ECX, 15, VF_INTEL, XCRLVL_NONE,  0            ; 047 QCF_PDCM
  QCF_DEF  1, 0, RG_ECX, 17, VF_ANY,   XCRLVL_NONE,  0            ; 048 QCF_PCID
  QCF_DEF  1, 0, RG_ECX, 18, VF_INTEL, XCRLVL_NONE,  0            ; 049 QCF_DCA
  QCF_DEF  1, 0, RG_ECX, 19, VF_ANY,   XCRLVL_NONE,  0            ; 050 QCF_SSE41
  QCF_DEF  1, 0, RG_ECX, 20, VF_ANY,   XCRLVL_NONE,  0            ; 051 QCF_SSE42
  QCF_DEF  1, 0, RG_ECX, 21, VF_ANY,   XCRLVL_NONE,  0            ; 052 QCF_x2APIC
  QCF_DEF  1, 0, RG_ECX, 22, VF_ANY,   XCRLVL_NONE,  0            ; 053 QCF_MOVBE
  QCF_DEF  1, 0, RG_ECX, 23, VF_ANY,   XCRLVL_NONE,  0            ; 054 QCF_POPCNT
  QCF_DEF  1, 0, RG_ECX, 24, VF_ANY,   XCRLVL_NONE,  0            ; 055 QCF_TSC_DEADLINE
  QCF_DEF  1, 0, RG_ECX, 25, VF_ANY,   XCRLVL_NONE,  0            ; 056 QCF_AES
  QCF_DEF  1, 0, RG_ECX, 26, VF_ANY,   XCRLVL_NONE,  0            ; 057 QCF_XSAVE
  QCF_DEF  1, 0, RG_ECX, 27, VF_ANY,   XCRLVL_NONE,  0            ; 058 QCF_OSXSAVE
  QCF_DEF  1, 0, RG_ECX, 28, VF_ANY,   XCRLVL_AVX,   0            ; 059 QCF_AVX
  QCF_DEF  1, 0, RG_ECX, 29, VF_ANY,   XCRLVL_AVX,   0            ; 060 QCF_F16C
  QCF_DEF  1, 0, RG_ECX, 30, VF_ANY,   XCRLVL_NONE,  0            ; 061 QCF_RDRAND
  QCF_DEF  1, 0, RG_ECX, 31, VF_ANY,   XCRLVL_NONE,  0            ; 062 QCF_HYPERVISOR

  ; -- CPUID(80000001h,0).EDX - Extended features ----------------------------------
  ; bLeaf=1, QCF_FL_EX => actual leaf = 80000001h
  QCF_DEF  1, 0, RG_EDX, 11, VF_ANY,   XCRLVL_NONE,  QCF_FL_EX    ; 063 QCF_SYSCALL_EX
  QCF_DEF  1, 0, RG_EDX, 20, VF_ANY,   XCRLVL_NONE,  QCF_FL_EX    ; 064 QCF_NX
  QCF_DEF  1, 0, RG_EDX, 22, VF_AMD,   XCRLVL_NONE,  QCF_FL_EX    ; 065 QCF_AMD_MMXEXT
  QCF_DEF  1, 0, RG_EDX, 25, VF_AMD,   XCRLVL_NONE,  QCF_FL_EX    ; 066 QCF_AMD_FFXSR
  QCF_DEF  1, 0, RG_EDX, 26, VF_ANY,   XCRLVL_NONE,  QCF_FL_EX    ; 067 QCF_1GB_PAGE
  QCF_DEF  1, 0, RG_EDX, 27, VF_ANY,   XCRLVL_NONE,  QCF_FL_EX    ; 068 QCF_RDTSCP_EX
  QCF_DEF  1, 0, RG_EDX, 29, VF_ANY,   XCRLVL_NONE,  QCF_FL_EX    ; 069 QCF_LM
  QCF_DEF  1, 0, RG_EDX, 30, VF_AMD,   XCRLVL_NONE,  QCF_FL_EX    ; 070 QCF_AMD_3DNOWEXT
  QCF_DEF  1, 0, RG_EDX, 31, VF_AMD,   XCRLVL_NONE,  QCF_FL_EX    ; 071 QCF_AMD_3DNOW

  ; -- CPUID(80000001h,0).ECX - Extended features ----------------------------------
  ; bLeaf=1, QCF_FL_EX => actual leaf = 80000001h
  QCF_DEF  1, 0, RG_ECX,  0, VF_ANY,   XCRLVL_NONE,  QCF_FL_EX    ; 072 QCF_LAHF64
  QCF_DEF  1, 0, RG_ECX,  1, VF_AMD,   XCRLVL_NONE,  QCF_FL_EX    ; 073 QCF_AMD_CMP_LEGACY
  QCF_DEF  1, 0, RG_ECX,  2, VF_AMD,   XCRLVL_NONE,  QCF_FL_EX    ; 074 QCF_AMD_SVM
  QCF_DEF  1, 0, RG_ECX,  3, VF_AMD,   XCRLVL_NONE,  QCF_FL_EX    ; 075 QCF_AMD_EXT_APIC
  QCF_DEF  1, 0, RG_ECX,  4, VF_AMD,   XCRLVL_NONE,  QCF_FL_EX    ; 076 QCF_AMD_ALT_MOV_CR8
  QCF_DEF  1, 0, RG_ECX,  5, VF_ANY,   XCRLVL_NONE,  QCF_FL_EX    ; 077 QCF_LZCNT
  QCF_DEF  1, 0, RG_ECX,  6, VF_AMD,   XCRLVL_NONE,  QCF_FL_EX    ; 078 QCF_AMD_SSE4A
  QCF_DEF  1, 0, RG_ECX,  7, VF_AMD,   XCRLVL_NONE,  QCF_FL_EX    ; 079 QCF_AMD_MISALIGN
  QCF_DEF  1, 0, RG_ECX,  8, VF_AMD,   XCRLVL_NONE,  QCF_FL_EX    ; 080 QCF_AMD_3DNOW_PF
  QCF_DEF  1, 0, RG_ECX,  9, VF_AMD,   XCRLVL_NONE,  QCF_FL_EX    ; 081 QCF_AMD_OSVW
  QCF_DEF  1, 0, RG_ECX, 10, VF_AMD,   XCRLVL_NONE,  QCF_FL_EX    ; 082 QCF_AMD_IBS
  QCF_DEF  1, 0, RG_ECX, 11, VF_AMD,   XCRLVL_NONE,  QCF_FL_EX    ; 083 QCF_AMD_XOP
  QCF_DEF  1, 0, RG_ECX, 12, VF_AMD,   XCRLVL_NONE,  QCF_FL_EX    ; 084 QCF_AMD_SKINIT
  QCF_DEF  1, 0, RG_ECX, 13, VF_AMD,   XCRLVL_NONE,  QCF_FL_EX    ; 085 QCF_AMD_WDT
  QCF_DEF  1, 0, RG_ECX, 16, VF_AMD,   XCRLVL_NONE,  QCF_FL_EX    ; 086 QCF_AMD_FMA4
  QCF_DEF  1, 0, RG_ECX, 21, VF_AMD,   XCRLVL_NONE,  QCF_FL_EX    ; 087 QCF_AMD_TBM

  ; -- CPUID(7,0).EBX --------------------------------------------------------------
  QCF_DEF  7, 0, RG_EBX,  0, VF_ANY,   XCRLVL_NONE,  0            ; 088 QCF_FSGSBASE
  QCF_DEF  7, 0, RG_EBX,  1, VF_ANY,   XCRLVL_NONE,  0            ; 089 QCF_TSC_ADJUST
  QCF_DEF  7, 0, RG_EBX,  2, VF_INTEL, XCRLVL_NONE,  0            ; 090 QCF_SGX
  QCF_DEF  7, 0, RG_EBX,  3, VF_ANY,   XCRLVL_NONE,  0            ; 091 QCF_BMI1
  QCF_DEF  7, 0, RG_EBX,  4, VF_INTEL, XCRLVL_NONE,  0            ; 092 QCF_HLE
  QCF_DEF  7, 0, RG_EBX,  5, VF_ANY,   XCRLVL_AVX,   0            ; 093 QCF_AVX2
  QCF_DEF  7, 0, RG_EBX,  6, VF_INTEL, XCRLVL_NONE,  0            ; 094 QCF_FDP_EXCPTN_ONLY
  QCF_DEF  7, 0, RG_EBX,  7, VF_ANY,   XCRLVL_NONE,  0            ; 095 QCF_SMEP
  QCF_DEF  7, 0, RG_EBX,  8, VF_ANY,   XCRLVL_NONE,  0            ; 096 QCF_BMI2
  QCF_DEF  7, 0, RG_EBX,  9, VF_ANY,   XCRLVL_NONE,  0            ; 097 QCF_ERMS
  QCF_DEF  7, 0, RG_EBX, 10, VF_ANY,   XCRLVL_NONE,  0            ; 098 QCF_INVPCID
  QCF_DEF  7, 0, RG_EBX, 11, VF_INTEL, XCRLVL_NONE,  0            ; 099 QCF_RTM
  QCF_DEF  7, 0, RG_EBX, 12, VF_INTEL, XCRLVL_NONE,  0            ; 100 QCF_PQM
  QCF_DEF  7, 0, RG_EBX, 13, VF_INTEL, XCRLVL_NONE,  0            ; 101 QCF_FCS_FDS
  QCF_DEF  7, 0, RG_EBX, 14, VF_INTEL, XCRLVL_NONE,  0            ; 102 QCF_MPX
  QCF_DEF  7, 0, RG_EBX, 15, VF_INTEL, XCRLVL_NONE,  0            ; 103 QCF_PQE
  QCF_DEF  7, 0, RG_EBX, 16, VF_ANY,   XCRLVL_AVX512,0            ; 104 QCF_AVX512F
  QCF_DEF  7, 0, RG_EBX, 17, VF_ANY,   XCRLVL_AVX512,0            ; 105 QCF_AVX512DQ
  QCF_DEF  7, 0, RG_EBX, 18, VF_ANY,   XCRLVL_NONE,  0            ; 106 QCF_RDSEED
  QCF_DEF  7, 0, RG_EBX, 19, VF_ANY,   XCRLVL_NONE,  0            ; 107 QCF_ADX
  QCF_DEF  7, 0, RG_EBX, 20, VF_ANY,   XCRLVL_NONE,  0            ; 108 QCF_SMAP
  QCF_DEF  7, 0, RG_EBX, 21, VF_ANY,   XCRLVL_AVX512,0            ; 109 QCF_AVX512IFMA
  QCF_DEF  7, 0, RG_EBX, 23, VF_ANY,   XCRLVL_NONE,  0            ; 110 QCF_CLFLUSHOPT
  QCF_DEF  7, 0, RG_EBX, 24, VF_ANY,   XCRLVL_NONE,  0            ; 111 QCF_CLWB
  QCF_DEF  7, 0, RG_EBX, 25, VF_INTEL, XCRLVL_NONE,  0            ; 112 QCF_PT
  QCF_DEF  7, 0, RG_EBX, 26, VF_INTEL, XCRLVL_AVX512,0            ; 113 QCF_AVX512PF
  QCF_DEF  7, 0, RG_EBX, 27, VF_INTEL, XCRLVL_AVX512,0            ; 114 QCF_AVX512ER
  QCF_DEF  7, 0, RG_EBX, 28, VF_ANY,   XCRLVL_AVX512,0            ; 115 QCF_AVX512CD
  QCF_DEF  7, 0, RG_EBX, 29, VF_ANY,   XCRLVL_NONE,  0            ; 116 QCF_SHA
  QCF_DEF  7, 0, RG_EBX, 30, VF_ANY,   XCRLVL_AVX512,0            ; 117 QCF_AVX512BW
  QCF_DEF  7, 0, RG_EBX, 31, VF_ANY,   XCRLVL_AVX512,0            ; 118 QCF_AVX512VL

  ; -- CPUID(7,0).ECX --------------------------------------------------------------
  QCF_DEF  7, 0, RG_ECX,  0, VF_INTEL, XCRLVL_NONE,  0            ; 119 QCF_PREFETCHWT1
  QCF_DEF  7, 0, RG_ECX,  1, VF_ANY,   XCRLVL_AVX512,0            ; 120 QCF_AVX512VBMI
  QCF_DEF  7, 0, RG_ECX,  2, VF_ANY,   XCRLVL_NONE,  0            ; 121 QCF_UMIP
  QCF_DEF  7, 0, RG_ECX,  3, VF_ANY,   XCRLVL_NONE,  0            ; 122 QCF_PKU
  QCF_DEF  7, 0, RG_ECX,  4, VF_ANY,   XCRLVL_NONE,  0            ; 123 QCF_OSPKE
  QCF_DEF  7, 0, RG_ECX,  5, VF_INTEL, XCRLVL_NONE,  0            ; 124 QCF_WAITPKG
  QCF_DEF  7, 0, RG_ECX,  6, VF_ANY,   XCRLVL_AVX512,0            ; 125 QCF_AVX512VBMI2
  QCF_DEF  7, 0, RG_ECX,  7, VF_ANY,   XCRLVL_NONE,  0            ; 126 QCF_CET_SS
  QCF_DEF  7, 0, RG_ECX,  8, VF_ANY,   XCRLVL_NONE,  0            ; 127 QCF_GFNI
  QCF_DEF  7, 0, RG_ECX,  9, VF_ANY,   XCRLVL_AVX,   0            ; 128 QCF_VAES
  QCF_DEF  7, 0, RG_ECX, 10, VF_ANY,   XCRLVL_AVX,   0            ; 129 QCF_VPCLMULQDQ
  QCF_DEF  7, 0, RG_ECX, 11, VF_ANY,   XCRLVL_AVX512,0            ; 130 QCF_AVX512VNNI
  QCF_DEF  7, 0, RG_ECX, 12, VF_ANY,   XCRLVL_AVX512,0            ; 131 QCF_AVX512BITALG
  QCF_DEF  7, 0, RG_ECX, 13, VF_INTEL, XCRLVL_NONE,  0            ; 132 QCF_TME
  QCF_DEF  7, 0, RG_ECX, 14, VF_ANY,   XCRLVL_AVX512,0            ; 133 QCF_AVX512VPOPCNTDQ
  QCF_DEF  7, 0, RG_ECX, 16, VF_ANY,   XCRLVL_NONE,  0            ; 134 QCF_LA57
  QCF_DEF  7, 0, RG_ECX, 22, VF_ANY,   XCRLVL_NONE,  0            ; 135 QCF_RDPID
  QCF_DEF  7, 0, RG_ECX, 23, VF_INTEL, XCRLVL_NONE,  0            ; 136 QCF_KL
  QCF_DEF  7, 0, RG_ECX, 24, VF_INTEL, XCRLVL_NONE,  0            ; 137 QCF_BUS_LOCK_DETECT
  QCF_DEF  7, 0, RG_ECX, 25, VF_INTEL, XCRLVL_NONE,  0            ; 138 QCF_CLDEMOTE
  QCF_DEF  7, 0, RG_ECX, 27, VF_INTEL, XCRLVL_NONE,  0            ; 139 QCF_MOVDIRI
  QCF_DEF  7, 0, RG_ECX, 28, VF_INTEL, XCRLVL_NONE,  0            ; 140 QCF_MOVDIR64B
  QCF_DEF  7, 0, RG_ECX, 29, VF_INTEL, XCRLVL_NONE,  0            ; 141 QCF_ENQCMD
  QCF_DEF  7, 0, RG_ECX, 30, VF_INTEL, XCRLVL_NONE,  0            ; 142 QCF_SGX_LC
  QCF_DEF  7, 0, RG_ECX, 31, VF_INTEL, XCRLVL_NONE,  0            ; 143 QCF_PKS

  ; -- CPUID(7,0).EDX --------------------------------------------------------------
  QCF_DEF  7, 0, RG_EDX,  1, VF_INTEL, XCRLVL_NONE,  0            ; 144 QCF_SGX_KEYS
  QCF_DEF  7, 0, RG_EDX,  2, VF_INTEL, XCRLVL_AVX512,0            ; 145 QCF_AVX512_4VNNIW
  QCF_DEF  7, 0, RG_EDX,  3, VF_INTEL, XCRLVL_AVX512,0            ; 146 QCF_AVX512_4FMAPS
  QCF_DEF  7, 0, RG_EDX,  4, VF_ANY,   XCRLVL_NONE,  0            ; 147 QCF_FSRM
  QCF_DEF  7, 0, RG_EDX,  5, VF_INTEL, XCRLVL_NONE,  0            ; 148 QCF_UINTR
  QCF_DEF  7, 0, RG_EDX,  8, VF_ANY,   XCRLVL_AVX512,0            ; 149 QCF_AVX512VP2INTER
  QCF_DEF  7, 0, RG_EDX,  9, VF_INTEL, XCRLVL_NONE,  0            ; 150 QCF_SRBDS_CTRL
  QCF_DEF  7, 0, RG_EDX, 10, VF_INTEL, XCRLVL_NONE,  0            ; 151 QCF_MD_CLEAR
  QCF_DEF  7, 0, RG_EDX, 11, VF_INTEL, XCRLVL_NONE,  0            ; 152 QCF_RTM_ALWAYS_ABORT
  QCF_DEF  7, 0, RG_EDX, 13, VF_INTEL, XCRLVL_NONE,  0            ; 153 QCF_TSX_FORCE_ABORT
  QCF_DEF  7, 0, RG_EDX, 14, VF_INTEL, XCRLVL_NONE,  0            ; 154 QCF_SERIALIZE
  QCF_DEF  7, 0, RG_EDX, 15, VF_INTEL, XCRLVL_NONE,  0            ; 155 QCF_HYBRID
  QCF_DEF  7, 0, RG_EDX, 16, VF_INTEL, XCRLVL_NONE,  0            ; 156 QCF_TSXLDTRK
  QCF_DEF  7, 0, RG_EDX, 18, VF_INTEL, XCRLVL_NONE,  0            ; 157 QCF_PCONFIG
  QCF_DEF  7, 0, RG_EDX, 19, VF_INTEL, XCRLVL_NONE,  0            ; 158 QCF_LBR_ARCH
  QCF_DEF  7, 0, RG_EDX, 20, VF_ANY,   XCRLVL_NONE,  0            ; 159 QCF_CET_IBT
  QCF_DEF  7, 0, RG_EDX, 22, VF_INTEL, XCRLVL_AMX,   0            ; 160 QCF_AMX_BF16
  QCF_DEF  7, 0, RG_EDX, 23, VF_ANY,   XCRLVL_AVX512,0            ; 161 QCF_AVX512_FP16
  QCF_DEF  7, 0, RG_EDX, 24, VF_INTEL, XCRLVL_AMX,   0            ; 162 QCF_AMX_TILE
  QCF_DEF  7, 0, RG_EDX, 25, VF_INTEL, XCRLVL_AMX,   0            ; 163 QCF_AMX_INT8
  QCF_DEF  7, 0, RG_EDX, 26, VF_INTEL, XCRLVL_NONE,  0            ; 164 QCF_INTEL_IBRS_IBPB
  QCF_DEF  7, 0, RG_EDX, 27, VF_INTEL, XCRLVL_NONE,  0            ; 165 QCF_INTEL_STIBP
  QCF_DEF  7, 0, RG_EDX, 28, VF_INTEL, XCRLVL_NONE,  0            ; 166 QCF_INTEL_L1D_FLUSH
  QCF_DEF  7, 0, RG_EDX, 29, VF_INTEL, XCRLVL_NONE,  0            ; 167 QCF_INTEL_ARCH_CAP
  QCF_DEF  7, 0, RG_EDX, 30, VF_INTEL, XCRLVL_NONE,  0            ; 168 QCF_INTEL_CORE_CAP
  QCF_DEF  7, 0, RG_EDX, 31, VF_INTEL, XCRLVL_NONE,  0            ; 169 QCF_INTEL_SSBD

  ; -- CPUID(7,1).EAX --------------------------------------------------------------
  QCF_DEF  7, 1, RG_EAX,  0, VF_ANY,   XCRLVL_NONE,  0            ; 170 QCF_SHA512
  QCF_DEF  7, 1, RG_EAX,  1, VF_ANY,   XCRLVL_NONE,  0            ; 171 QCF_SM3
  QCF_DEF  7, 1, RG_EAX,  2, VF_ANY,   XCRLVL_NONE,  0            ; 172 QCF_SM4
  QCF_DEF  7, 1, RG_EAX,  3, VF_INTEL, XCRLVL_NONE,  0            ; 173 QCF_RAO_INT
  QCF_DEF  7, 1, RG_EAX,  4, VF_ANY,   XCRLVL_AVX,   0            ; 174 QCF_AVX_VNNI
  QCF_DEF  7, 1, RG_EAX,  5, VF_ANY,   XCRLVL_AVX512,0            ; 175 QCF_AVX512_BF16
  QCF_DEF  7, 1, RG_EAX,  6, VF_INTEL, XCRLVL_NONE,  0            ; 176 QCF_LASS
  QCF_DEF  7, 1, RG_EAX,  7, VF_INTEL, XCRLVL_NONE,  0            ; 177 QCF_CMPCCXADD
  QCF_DEF  7, 1, RG_EAX, 10, VF_INTEL, XCRLVL_NONE,  0            ; 178 QCF_FZRM
  QCF_DEF  7, 1, RG_EAX, 11, VF_INTEL, XCRLVL_NONE,  0            ; 179 QCF_FSRS
  QCF_DEF  7, 1, RG_EAX, 12, VF_INTEL, XCRLVL_NONE,  0            ; 180 QCF_FSRCS
  QCF_DEF  7, 1, RG_EAX, 17, VF_INTEL, XCRLVL_NONE,  0            ; 181 QCF_FRED
  QCF_DEF  7, 1, RG_EAX, 18, VF_INTEL, XCRLVL_NONE,  0            ; 182 QCF_LKGS
  QCF_DEF  7, 1, RG_EAX, 19, VF_INTEL, XCRLVL_NONE,  0            ; 183 QCF_WRMSRNS
  QCF_DEF  7, 1, RG_EAX, 21, VF_INTEL, XCRLVL_AMX,   0            ; 184 QCF_AMX_FP16
  QCF_DEF  7, 1, RG_EAX, 22, VF_INTEL, XCRLVL_NONE,  0            ; 185 QCF_HRESET
  QCF_DEF  7, 1, RG_EAX, 23, VF_ANY,   XCRLVL_AVX,   0            ; 186 QCF_AVX_IFMA
  QCF_DEF  7, 1, RG_EAX, 26, VF_INTEL, XCRLVL_NONE,  0            ; 187 QCF_LAM
  QCF_DEF  7, 1, RG_EAX, 27, VF_INTEL, XCRLVL_NONE,  0            ; 188 QCF_MSRLIST

  ; -- CPUID(7,1).EDX --------------------------------------------------------------
  QCF_DEF  7, 1, RG_EDX,  4, VF_ANY,   XCRLVL_AVX,   0            ; 189 QCF_AVX_VNNI_INT8
  QCF_DEF  7, 1, RG_EDX,  5, VF_ANY,   XCRLVL_AVX,   0            ; 190 QCF_AVX_NE_CONVERT
  QCF_DEF  7, 1, RG_EDX,  8, VF_INTEL, XCRLVL_AMX,   0            ; 191 QCF_AMX_COMPLEX
  QCF_DEF  7, 1, RG_EDX, 10, VF_ANY,   XCRLVL_AVX,   0            ; 192 QCF_AVX_VNNI_INT16
  QCF_DEF  7, 1, RG_EDX, 14, VF_ANY,   XCRLVL_NONE,  0            ; 193 QCF_PREFETCHI
  QCF_DEF  7, 1, RG_EDX, 15, VF_ANY,   XCRLVL_NONE,  0            ; 194 QCF_USER_MSR
  QCF_DEF  7, 1, RG_EDX, 19, VF_ANY,   XCRLVL_AVX512,0            ; 195 QCF_AVX10
  QCF_DEF  7, 1, RG_EDX, 21, VF_INTEL, XCRLVL_NONE,  0            ; 196 QCF_APX_F
  QCF_DEF  7, 1, RG_EDX, 24, VF_INTEL, XCRLVL_NONE,  0            ; 197 QCF_SLSM

  ; -- CPUID(7,2).EDX --------------------------------------------------------------
  QCF_DEF  7, 2, RG_EDX,  0, VF_INTEL, XCRLVL_NONE,  0            ; 198 QCF_PSFD
  QCF_DEF  7, 2, RG_EDX,  1, VF_INTEL, XCRLVL_NONE,  0            ; 199 QCF_IPRED_DIS
  QCF_DEF  7, 2, RG_EDX,  2, VF_INTEL, XCRLVL_NONE,  0            ; 200 QCF_RRSBA_CTRL
  QCF_DEF  7, 2, RG_EDX,  3, VF_INTEL, XCRLVL_NONE,  0            ; 201 QCF_DDPD_U
  QCF_DEF  7, 2, RG_EDX,  4, VF_INTEL, XCRLVL_NONE,  0            ; 202 QCF_BHI_CTRL
  QCF_DEF  7, 2, RG_EDX,  5, VF_INTEL, XCRLVL_NONE,  0            ; 203 QCF_MCDT_NO
  QCF_DEF  7, 2, RG_EDX,  7, VF_INTEL, XCRLVL_NONE,  0            ; 204 QCF_MONITOR_MITG_NO

  ; -- CPUID(0Dh,1).EAX - XSAVE features ------------------------------------------
  ; Subleaf 1 of leaf 0Dh is always present when the leaf itself is supported
  ; (max basic leaf >= 0Dh).  The proc additionally checks CPUID(0Dh,0).EAX != 0
  ; to ensure the OS has enabled at least one XSAVE state component.
  QCF_DEF 0Dh,1, RG_EAX,  0, VF_ANY,   XCRLVL_NONE,  0            ; 205 QCF_XSAVEOPT
  QCF_DEF 0Dh,1, RG_EAX,  1, VF_ANY,   XCRLVL_NONE,  0            ; 206 QCF_XSAVEC
  QCF_DEF 0Dh,1, RG_EAX,  2, VF_ANY,   XCRLVL_NONE,  0            ; 207 QCF_XGETBV_ECX1
  QCF_DEF 0Dh,1, RG_EAX,  3, VF_ANY,   XCRLVL_NONE,  0            ; 208 QCF_XSAVES

  ; -- CPUID(19h,0).EAX - AES Key Locker ------------------------------------------
  QCF_DEF 19h,0, RG_EAX,  0, VF_INTEL, XCRLVL_NONE,  0            ; 209 QCF_AESKLE
  QCF_DEF 19h,0, RG_EAX,  2, VF_INTEL, XCRLVL_NONE,  0            ; 210 QCF_WIDE_KL
  QCF_DEF 19h,0, RG_EAX,  4, VF_INTEL, XCRLVL_NONE,  0            ; 211 QCF_PLATFORM_KL

  ; -- CPUID(80000008h,0).EBX - AMD feature extensions ----------------------------
  ; bLeaf=8, QCF_FL_EX => actual leaf = 80000008h
  QCF_DEF  8, 0, RG_EBX,  0, VF_AMD,   XCRLVL_NONE,  QCF_FL_EX    ; 212 QCF_AMD_CLZERO
  QCF_DEF  8, 0, RG_EBX,  1, VF_AMD,   XCRLVL_NONE,  QCF_FL_EX    ; 213 QCF_AMD_IRPERF
  QCF_DEF  8, 0, RG_EBX,  2, VF_AMD,   XCRLVL_NONE,  QCF_FL_EX    ; 214 QCF_AMD_XSAVEERPTR
  QCF_DEF  8, 0, RG_EBX,  3, VF_AMD,   XCRLVL_NONE,  QCF_FL_EX    ; 215 QCF_AMD_INVLPGB
  QCF_DEF  8, 0, RG_EBX,  4, VF_AMD,   XCRLVL_NONE,  QCF_FL_EX    ; 216 QCF_AMD_RDPRU
  QCF_DEF  8, 0, RG_EBX,  6, VF_AMD,   XCRLVL_NONE,  QCF_FL_EX    ; 217 QCF_AMD_MBE
  QCF_DEF  8, 0, RG_EBX,  8, VF_AMD,   XCRLVL_NONE,  QCF_FL_EX    ; 218 QCF_AMD_MCOMMIT
  QCF_DEF  8, 0, RG_EBX,  9, VF_AMD,   XCRLVL_NONE,  QCF_FL_EX    ; 219 QCF_AMD_WBNOINVD
  QCF_DEF  8, 0, RG_EBX, 12, VF_AMD,   XCRLVL_NONE,  QCF_FL_EX    ; 220 QCF_AMD_IBPB
  QCF_DEF  8, 0, RG_EBX, 13, VF_AMD,   XCRLVL_NONE,  QCF_FL_EX    ; 221 QCF_AMD_INT_WBINVD
  QCF_DEF  8, 0, RG_EBX, 14, VF_AMD,   XCRLVL_NONE,  QCF_FL_EX    ; 222 QCF_AMD_IBRS
  QCF_DEF  8, 0, RG_EBX, 15, VF_AMD,   XCRLVL_NONE,  QCF_FL_EX    ; 223 QCF_AMD_STIBP
  QCF_DEF  8, 0, RG_EBX, 24, VF_AMD,   XCRLVL_NONE,  QCF_FL_EX    ; 224 QCF_AMD_SSBD

  ; -- CPUID(7,1).EAX - newer Intel features ----------------------------------------
  QCF_DEF  7, 1, RG_EAX, 24, VF_INTEL, XCRLVL_NONE,  0            ; 225 QCF_PBNDKB
  QCF_DEF  7, 1, RG_EAX, 28, VF_INTEL, XCRLVL_AMX,   QCF_FL_IRSV  ; 226 QCF_AMX_TRANSPOSE (RETIRED)
  QCF_DEF  7, 1, RG_EAX, 29, VF_INTEL, XCRLVL_AMX,   0            ; 227 QCF_AMX_TF32
  QCF_DEF  7, 1, RG_EAX, 30, VF_INTEL, XCRLVL_AMX,   0            ; 228 QCF_AMX_AVX512
  QCF_DEF  7, 1, RG_EAX, 31, VF_INTEL, XCRLVL_AMX,   0            ; 229 QCF_AMX_MOVRS

  ; -- CPUID(7,1).EDX - newer Intel features ----------------------------------------
  QCF_DEF  7, 1, RG_EDX, 22, VF_INTEL, XCRLVL_AMX,   0            ; 230 QCF_AMX_FP8
  QCF_DEF  7, 1, RG_EDX, 23, VF_INTEL, XCRLVL_AMX,   0            ; 231 QCF_AMX_MOVRS2
  QCF_DEF  7, 1, RG_EDX, 25, VF_INTEL, XCRLVL_NONE,  0            ; 232 QCF_MOVRS

  ; -- CPUID(7,1).EBX --------------------------------------------------------------
  QCF_DEF  7, 1, RG_EBX,  0, VF_INTEL, XCRLVL_NONE,  0            ; 233 QCF_INTEL_PPIN

  ; -- CPUID(80000001h,0).ECX - additional AMD features ----------------------------
  ; bLeaf=1, QCF_FL_EX => actual leaf = 80000001h
  QCF_DEF  1, 0, RG_ECX, 17, VF_AMD,   XCRLVL_NONE,  QCF_FL_EX    ; 234 QCF_AMD_TCE
  QCF_DEF  1, 0, RG_ECX, 22, VF_AMD,   XCRLVL_NONE,  QCF_FL_EX    ; 235 QCF_AMD_TOPEXT
  QCF_DEF  1, 0, RG_ECX, 23, VF_AMD,   XCRLVL_NONE,  QCF_FL_EX    ; 236 QCF_AMD_PCXCORE
  QCF_DEF  1, 0, RG_ECX, 24, VF_AMD,   XCRLVL_NONE,  QCF_FL_EX    ; 237 QCF_AMD_PCXNB
  QCF_DEF  1, 0, RG_ECX, 25, VF_AMD,   XCRLVL_NONE,  QCF_FL_EX    ; 238 QCF_AMD_STREAMPERFMON
  QCF_DEF  1, 0, RG_ECX, 26, VF_AMD,   XCRLVL_NONE,  QCF_FL_EX    ; 239 QCF_AMD_DATABKPTEXT
  QCF_DEF  1, 0, RG_ECX, 27, VF_AMD,   XCRLVL_NONE,  QCF_FL_EX    ; 240 QCF_AMD_PERFTSC
  QCF_DEF  1, 0, RG_ECX, 28, VF_AMD,   XCRLVL_NONE,  QCF_FL_EX    ; 241 QCF_AMD_PERFL2I
  QCF_DEF  1, 0, RG_ECX, 29, VF_AMD,   XCRLVL_NONE,  QCF_FL_EX    ; 242 QCF_AMD_MONITORX
  QCF_DEF  1, 0, RG_ECX, 30, VF_AMD,   XCRLVL_NONE,  QCF_FL_EX    ; 243 QCF_AMD_ADDRMASKEXT

  ; -- CPUID(80000008h,0).EBX - AMD security features (continued) ------------------
  ; bLeaf=8, QCF_FL_EX => actual leaf = 80000008h
  QCF_DEF  8, 0, RG_EBX, 16, VF_AMD,   XCRLVL_NONE,  QCF_FL_EX    ; 244 QCF_AMD_IBRS_ALWAYS_ON
  QCF_DEF  8, 0, RG_EBX, 17, VF_AMD,   XCRLVL_NONE,  QCF_FL_EX    ; 245 QCF_AMD_STIBP_ALWAYS_ON
  QCF_DEF  8, 0, RG_EBX, 18, VF_AMD,   XCRLVL_NONE,  QCF_FL_EX    ; 246 QCF_AMD_IBRS_PREFERRED
  QCF_DEF  8, 0, RG_EBX, 19, VF_AMD,   XCRLVL_NONE,  QCF_FL_EX    ; 247 QCF_AMD_IBRS_SAME_MODE
  QCF_DEF  8, 0, RG_EBX, 20, VF_AMD,   XCRLVL_NONE,  QCF_FL_EX    ; 248 QCF_AMD_EFER_LMSLE_NO
  QCF_DEF  8, 0, RG_EBX, 21, VF_AMD,   XCRLVL_NONE,  QCF_FL_EX    ; 249 QCF_AMD_INVLPGB_NEST
  QCF_DEF  8, 0, RG_EBX, 23, VF_AMD,   XCRLVL_NONE,  QCF_FL_EX    ; 250 QCF_AMD_PPIN
  QCF_DEF  8, 0, RG_EBX, 25, VF_AMD,   XCRLVL_NONE,  QCF_FL_EX    ; 251 QCF_AMD_SSBD_SPEC_CTRL
  QCF_DEF  8, 0, RG_EBX, 26, VF_AMD,   XCRLVL_NONE,  QCF_FL_EX    ; 252 QCF_AMD_VIRT_SSBD
  QCF_DEF  8, 0, RG_EBX, 27, VF_AMD,   XCRLVL_NONE,  QCF_FL_EX    ; 253 QCF_AMD_SSBD_NOT_REQUIRED
  QCF_DEF  8, 0, RG_EBX, 28, VF_AMD,   XCRLVL_NONE,  QCF_FL_EX    ; 254 QCF_AMD_CPPC
  QCF_DEF  8, 0, RG_EBX, 29, VF_AMD,   XCRLVL_NONE,  QCF_FL_EX    ; 255 QCF_AMD_PSFD
  QCF_DEF  8, 0, RG_EBX, 30, VF_AMD,   XCRLVL_NONE,  QCF_FL_EX    ; 256 QCF_AMD_BTC_NO
  QCF_DEF  8, 0, RG_EBX, 31, VF_AMD,   XCRLVL_NONE,  QCF_FL_EX    ; 257 QCF_AMD_IBPB_RET

  ; -- CPUID(80000021h,0).EAX - AMD Zen4+ extended features (EFI2) ----------------
  ; bLeaf=21h, QCF_FL_EX => actual leaf = 80000021h
  ; Guard: query only if max extended leaf >= 80000021h
  QCF_DEF 21h,0, RG_EAX,  0, VF_AMD,   XCRLVL_NONE,  QCF_FL_EX    ; 258 QCF_AMD_NO_NESTED_DATA_BP
  QCF_DEF 21h,0, RG_EAX,  2, VF_AMD,   XCRLVL_NONE,  QCF_FL_EX    ; 259 QCF_AMD_LFENCE_ALWAYS_SERIAL
  QCF_DEF 21h,0, RG_EAX,  3, VF_AMD,   XCRLVL_NONE,  QCF_FL_EX    ; 260 QCF_AMD_SMM_PG_CFG_LOCK
  QCF_DEF 21h,0, RG_EAX,  6, VF_AMD,   XCRLVL_NONE,  QCF_FL_EX    ; 261 QCF_AMD_NULL_SEL_CLEARS_BASE
  QCF_DEF 21h,0, RG_EAX,  7, VF_AMD,   XCRLVL_NONE,  QCF_FL_EX    ; 262 QCF_AMD_UPPER_ADDR_IGNORE
  QCF_DEF 21h,0, RG_EAX,  8, VF_AMD,   XCRLVL_NONE,  QCF_FL_EX    ; 263 QCF_AMD_AUTOIBRS
  QCF_DEF 21h,0, RG_EAX,  9, VF_AMD,   XCRLVL_NONE,  QCF_FL_EX    ; 264 QCF_AMD_NO_SMMCTL_MSR
  QCF_DEF 21h,0, RG_EAX, 10, VF_AMD,   XCRLVL_NONE,  QCF_FL_EX    ; 265 QCF_AMD_FAST_SHORT_REP_MOVS
  QCF_DEF 21h,0, RG_EAX, 13, VF_AMD,   XCRLVL_NONE,  QCF_FL_EX    ; 266 QCF_AMD_PREFETCHCTL_MSR
  QCF_DEF 21h,0, RG_EAX, 17, VF_AMD,   XCRLVL_NONE,  QCF_FL_EX    ; 267 QCF_AMD_CPUID_USER_DIS
  QCF_DEF 21h,0, RG_EAX, 18, VF_AMD,   XCRLVL_NONE,  QCF_FL_EX    ; 268 QCF_AMD_EPSF

  ; -- CPUID(80000022h,0).EAX - AMD Performance Monitoring v2 ---------------------
  ; bLeaf=22h, QCF_FL_EX => actual leaf = 80000022h
  ; Guard: query only if max extended leaf >= 80000022h
  QCF_DEF 22h,0, RG_EAX,  0, VF_AMD,   XCRLVL_NONE,  QCF_FL_EX    ; 269 QCF_AMD_PERFMONV2
  QCF_DEF 22h,0, RG_EAX,  1, VF_AMD,   XCRLVL_NONE,  QCF_FL_EX    ; 270 QCF_AMD_LBRV2
  QCF_DEF 22h,0, RG_EAX,  2, VF_AMD,   XCRLVL_NONE,  QCF_FL_EX    ; 271 QCF_AMD_LBR_PMC_FREEZE

  ; -- CPUID(24h,0).EBX - Intel AVX10 vector-width capabilities -------------------
  ; Guard: query only if QCF_AVX10 is set and max basic leaf >= 24h
  QCF_DEF 24h,0, RG_EBX, 16, VF_INTEL, XCRLVL_AVX512,0            ; 272 QCF_AVX10_128
  QCF_DEF 24h,0, RG_EBX, 17, VF_INTEL, XCRLVL_AVX512,0            ; 273 QCF_AVX10_256
  QCF_DEF 24h,0, RG_EBX, 18, VF_INTEL, XCRLVL_AVX512,0            ; 274 QCF_AVX10_512

  ; -- CPUID(7,1).EAX - additional Intel features ---------------------------------
  QCF_DEF  7, 1, RG_EAX,  8, VF_INTEL, XCRLVL_NONE,  0            ; 275 QCF_INVD_DISABLE
  QCF_DEF  7, 1, RG_EAX, 20, VF_INTEL, XCRLVL_NONE,  0            ; 276 QCF_NMI_SRC
  QCF_DEF  7, 1, RG_EAX, 25, VF_INTEL, XCRLVL_NONE,  0            ; 277 QCF_MSR_IMM

  ; -- CPUID(7,1).ECX - Intel Asymmetric RDT ---------------------------------------
  ; Guard: query only if max basic leaf >= 7 and CPUID(7,0).EAX >= 1
  QCF_DEF  7, 1, RG_ECX,  0, VF_INTEL, XCRLVL_NONE,  0            ; 278 QCF_ASYM_RDT_M
  QCF_DEF  7, 1, RG_ECX,  1, VF_INTEL, XCRLVL_NONE,  0            ; 279 QCF_ASYM_RDT_A

  ; -- CPUID(80000021h,0).EAX - AMD Zen5 extended features ------------------------
  ; Guard: query only if max extended leaf >= 80000021h
  QCF_DEF 21h,0, RG_EAX,  1, VF_AMD,   XCRLVL_NONE,  QCF_FL_EX    ; 280 QCF_AMD_FS_GS_BASE_NS
  QCF_DEF 21h,0, RG_EAX,  5, VF_AMD,   XCRLVL_NONE,  QCF_FL_EX    ; 281 QCF_AMD_TSA_VERW_CLEAR
  QCF_DEF 21h,0, RG_EAX, 24, VF_AMD,   XCRLVL_NONE,  QCF_FL_EX    ; 282 QCF_AMD_PREFETCHI
  QCF_DEF 21h,0, RG_EAX, 27, VF_AMD,   XCRLVL_NONE,  QCF_FL_EX    ; 283 QCF_AMD_SBPB
  QCF_DEF 21h,0, RG_EAX, 28, VF_AMD,   XCRLVL_NONE,  QCF_FL_EX    ; 284 QCF_AMD_IBPB_BRTYPE
  QCF_DEF 21h,0, RG_EAX, 29, VF_AMD,   XCRLVL_NONE,  QCF_FL_EX    ; 285 QCF_AMD_SRSO_NO
  QCF_DEF 21h,0, RG_EAX, 30, VF_AMD,   XCRLVL_NONE,  QCF_FL_EX    ; 286 QCF_AMD_SRSO_USER_KERNEL_NO
  QCF_DEF 21h,0, RG_EAX, 31, VF_AMD,   XCRLVL_NONE,  QCF_FL_EX    ; 287 QCF_AMD_SRSO_MSR_FIX

  ; -- CPUID(80000021h,0).ECX - AMD Zen5+ TSA immunity bits ------------------------
  ; Guard: query only if max extended leaf >= 80000021h
  QCF_DEF 21h,0, RG_ECX,  1, VF_AMD,   XCRLVL_NONE,  QCF_FL_EX    ; 288 QCF_AMD_TSA_L1_NO
  QCF_DEF 21h,0, RG_ECX,  2, VF_AMD,   XCRLVL_NONE,  QCF_FL_EX    ; 289 QCF_AMD_TSA_SQ_NO

; Compile-time table size verification
QCF_TABLE_SIZE equ ($ - QCF_TABLE) / (sizeof QCF_ENTRY)
.errnz (QCF_TABLE_SIZE - QCF_COUNT), <QCF_TABLE row count mismatch - update QCF_COUNT>
