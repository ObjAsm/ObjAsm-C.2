; ==================================================================================================
; Title:      QCF-Name_PTX.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, May 2026
;               - Initial release.
;               - Platform-independent, string-type-neutral and bitness-neutral code.
; ==================================================================================================


; --------------------------------------------------------------------------------------------------
; Table:      QCF_NAME
; Purpose:    Flat array of POINTER entries providing human-readable display names for each
;             CPU feature indexed by the QCF_xxx constants (0 .. QCF_COUNT-1).
;             Each entry holds a pointer to a zero-terminated string literal produced by
;             $OfsTStr, resolved at assembly time to either an ANSI or WIDE-character string
;             according to TARGET_STR_TYPE. The table is consumed by QueryCpuFeature (and any
;             diagnostic / reporting layer built on top of it) to associate a descriptive label
;             with the TRUE/FALSE result returned for each probed feature.
;             The entry order is identical to that of QCF_TABLE in QCF-Table_PX.inc and
;             must be kept in strict one-to-one correspondence with QCF_COUNT.
;             Features marked "Intel only" or "AMD only" return FALSE on all other vendors.
;             Features marked "always returns FALSE" correspond to Intel-reserved bits that
;             are permanently masked regardless of the actual CPUID output.


.const
align sizeof(POINTER)
QCF_NAME label POINTER
; -- CPUID(1,0).EDX ---------------------------------------------------------------
POINTER $OfsTStr("Floating Point Unit on-chip (FPU)")                             ; 000 QCF_FPU
POINTER $OfsTStr("Virtual 8086 Mode Extensions (VME)")                            ; 001 QCF_VME
POINTER $OfsTStr("Debugging Extensions (DE)")                                     ; 002 QCF_DE
POINTER $OfsTStr("Page Size Extension 4 MB pages (PSE)")                          ; 003 QCF_PSE
POINTER $OfsTStr("Time Stamp Counter (TSC/RDTSC)")                                ; 004 QCF_TSC
POINTER $OfsTStr("Model Specific Registers (MSR)")                                ; 005 QCF_MSR
POINTER $OfsTStr("Physical Address Extension (PAE)")                              ; 006 QCF_PAE
POINTER $OfsTStr("Machine Check Exception (MCE)")                                 ; 007 QCF_MCE
POINTER $OfsTStr("CMPXCHG8B instruction")                                         ; 008 QCF_CX8
POINTER $OfsTStr("APIC on-chip")                                                  ; 009 QCF_APIC
POINTER $OfsTStr("Intel Reserved CPUID(1,0).EDX bit 10 (always returns FALSE)")   ; 010 QCF_INTL_RSVD_10
POINTER $OfsTStr("Fast System Call (SYSENTER/SYSEXIT)")                           ; 011 QCF_SEP
POINTER $OfsTStr("Memory Type Range Registers (MTRR)")                            ; 012 QCF_MTRR
POINTER $OfsTStr("Page Global Enable (PGE)")                                      ; 013 QCF_PGE
POINTER $OfsTStr("Machine Check Architecture (MCA)")                              ; 014 QCF_MCA
POINTER $OfsTStr("Conditional Move (CMOVcc)")                                     ; 015 QCF_CMOV
POINTER $OfsTStr("Page Attribute Table (PAT)")                                    ; 016 QCF_PAT
POINTER $OfsTStr("36-bit Page Size Extension (PSE-36)")                           ; 017 QCF_PSE36
POINTER $OfsTStr("Processor Serial Number (PSN)")                                 ; 018 QCF_PSN
POINTER $OfsTStr("CLFLUSH instruction")                                           ; 019 QCF_CLFSH
POINTER $OfsTStr("Intel Reserved CPUID(1,0).EDX bit 20 (always returns FALSE)")   ; 020 QCF_INTL_RSVD_20
POINTER $OfsTStr("Debug Store (DS)")                                              ; 021 QCF_DS
POINTER $OfsTStr("Thermal Monitor and Software Clock (ACPI)")                     ; 022 QCF_ACPI
POINTER $OfsTStr("MMX Technology")                                                ; 023 QCF_MMX
POINTER $OfsTStr("FXSAVE/FXRSTOR instructions")                                   ; 024 QCF_FXSR
POINTER $OfsTStr("SSE instructions")                                              ; 025 QCF_SSE
POINTER $OfsTStr("SSE2 instructions")                                             ; 026 QCF_SSE2
POINTER $OfsTStr("Self Snoop (SS)")                                               ; 027 QCF_SS
POINTER $OfsTStr("Hyper-Threading Technology (HTT)")                              ; 028 QCF_HTT
POINTER $OfsTStr("Thermal Monitor (TM)")                                          ; 029 QCF_TM
POINTER $OfsTStr("Intel Reserved CPUID(1,0).EDX bit 30 (always returns FALSE)")   ; 030 QCF_INTL_RSVD_30
POINTER $OfsTStr("Pending Break Enable (PBE)")                                    ; 031 QCF_PBE

; -- CPUID(1,0).ECX ---------------------------------------------------------------
POINTER $OfsTStr("SSE3 instructions")                                             ; 032 QCF_SSE3
POINTER $OfsTStr("Carry-less Multiplication (PCLMULQDQ)")                         ; 033 QCF_PCLMULQDQ
POINTER $OfsTStr("64-bit DS Area (DTES64)")                                       ; 034 QCF_DTES64
POINTER $OfsTStr("MONITOR/MWAIT instructions")                                    ; 035 QCF_MONITOR
POINTER $OfsTStr("CPL Qualified Debug Store (DS-CPL)")                            ; 036 QCF_DS_CPL
POINTER $OfsTStr("Virtual Machine Extensions (VT-x/VMX)")                         ; 037 QCF_VMX
POINTER $OfsTStr("Safer Mode Extensions (TXT/SMX)")                               ; 038 QCF_SMX
POINTER $OfsTStr("Enhanced Intel SpeedStep (EIST)")                               ; 039 QCF_EIST
POINTER $OfsTStr("Thermal Monitor 2 (TM2)")                                       ; 040 QCF_TM2
POINTER $OfsTStr("Supplemental SSE3 (SSSE3)")                                     ; 041 QCF_SSSE3
POINTER $OfsTStr("L1 Data Cache Context ID (CNXT-ID)")                            ; 042 QCF_CNXT_ID
POINTER $OfsTStr("Silicon Debug MSR (SDBG)")                                      ; 043 QCF_SDBG
POINTER $OfsTStr("Fused Multiply-Add 3-operand (FMA3)")                           ; 044 QCF_FMA
POINTER $OfsTStr("CMPXCHG16B instruction")                                        ; 045 QCF_CX16
POINTER $OfsTStr("xTPR Update Control")                                           ; 046 QCF_xTPR
POINTER $OfsTStr("Perfmon and Debug Capability MSR (PDCM)")                       ; 047 QCF_PDCM
; Note: CPUID(1).ECX bit 16 is architecturally reserved (always 0); no entry.
POINTER $OfsTStr("Process Context Identifiers (PCID)")                            ; 048 QCF_PCID
POINTER $OfsTStr("Direct Cache Access (DCA)")                                     ; 049 QCF_DCA
POINTER $OfsTStr("SSE 4.1 instructions (SSE4.1)")                                 ; 050 QCF_SSE41
POINTER $OfsTStr("SSE 4.2 instructions (SSE4.2)")                                 ; 051 QCF_SSE42
POINTER $OfsTStr("x2APIC support")                                                ; 052 QCF_x2APIC
POINTER $OfsTStr("MOVBE instruction")                                             ; 053 QCF_MOVBE
POINTER $OfsTStr("POPCNT instruction")                                            ; 054 QCF_POPCNT
POINTER $OfsTStr("TSC Deadline timer")                                            ; 055 QCF_TSC_DEADLINE
POINTER $OfsTStr("AES-NI instructions (AES)")                                     ; 056 QCF_AES
POINTER $OfsTStr("XSAVE/XRSTOR/XSETBV/XGETBV")                                    ; 057 QCF_XSAVE
POINTER $OfsTStr("OS enabled XSAVE")                                              ; 058 QCF_OSXSAVE
POINTER $OfsTStr("OS enabled and hardware support AVX")                           ; 059 QCF_AVX
POINTER $OfsTStr("16-bit FP conversion (F16C)")                                   ; 060 QCF_F16C
POINTER $OfsTStr("RDRAND instruction")                                            ; 061 QCF_RDRAND
POINTER $OfsTStr("Hypervisor present")                                            ; 062 QCF_HYPERVISOR

; -- CPUID(80000001h,0).EDX -------------------------------------------------------
POINTER $OfsTStr("SYSCALL/SYSRET (AMD64)")                                        ; 063 QCF_SYSCALL_EX
POINTER $OfsTStr("No-Execute bit (NX/XD)")                                        ; 064 QCF_NX
POINTER $OfsTStr("AMD MMX Extensions")                                            ; 065 QCF_AMD_MMXEXT
POINTER $OfsTStr("FXSAVE/FXRSTOR optimisations")                                  ; 066 QCF_AMD_FFXSR
POINTER $OfsTStr("1 GB page support (PDPE1GB)")                                   ; 067 QCF_1GB_PAGE
POINTER $OfsTStr("RDTSCP + IA32_TSC_AUX")                                         ; 068 QCF_RDTSCP_EX
POINTER $OfsTStr("Long Mode 64-bit (EM64T/AMD64)")                                ; 069 QCF_LM
POINTER $OfsTStr("AMD 3DNow! Extensions")                                         ; 070 QCF_AMD_3DNOWEXT
POINTER $OfsTStr("AMD 3DNow!")                                                    ; 071 QCF_AMD_3DNOW

; -- CPUID(80000001h,0).ECX -------------------------------------------------------
POINTER $OfsTStr("LAHF/SAHF in 64-bit mode")                                      ; 072 QCF_LAHF64
POINTER $OfsTStr("Core MP legacy mode (CmpLegacy)")                               ; 073 QCF_AMD_CMP_LEGACY
POINTER $OfsTStr("AMD-V Virtualisation (SVM)")                                    ; 074 QCF_AMD_SVM
POINTER $OfsTStr("Extended APIC space (ExtApicSpace)")                            ; 075 QCF_AMD_EXT_APIC
POINTER $OfsTStr("LOCK MOV CR0 = MOV CR8 (AltMovCr8)")                            ; 076 QCF_AMD_ALT_MOV_CR8
POINTER $OfsTStr("LZCNT/POPCNT (ABM)")                                            ; 077 QCF_LZCNT
POINTER $OfsTStr("SSE4a instructions")                                            ; 078 QCF_AMD_SSE4A
POINTER $OfsTStr("Misaligned SSE support")                                        ; 079 QCF_AMD_MISALIGN
POINTER $OfsTStr("3DNow! Prefetch")                                               ; 080 QCF_AMD_3DNOW_PF
POINTER $OfsTStr("OS-visible workaround support (OSVW)")                          ; 081 QCF_AMD_OSVW
POINTER $OfsTStr("Instruction-based sampling (IBS)")                              ; 082 QCF_AMD_IBS
POINTER $OfsTStr("XOP instructions")                                              ; 083 QCF_AMD_XOP
POINTER $OfsTStr("SKINIT/STGI instructions")                                      ; 084 QCF_AMD_SKINIT
POINTER $OfsTStr("Watchdog timer support (WDT)")                                  ; 085 QCF_AMD_WDT
POINTER $OfsTStr("FMA4 instructions")                                             ; 086 QCF_AMD_FMA4
POINTER $OfsTStr("Trailing Bit Manipulation (TBM)")                               ; 087 QCF_AMD_TBM

; -- CPUID(7,0).EBX ---------------------------------------------------------------
POINTER $OfsTStr("RDFSBASE/RDGSBASE/WRFSBASE/WRGSBASE")                           ; 088 QCF_FSGSBASE
POINTER $OfsTStr("IA32_TSC_ADJUST MSR")                                           ; 089 QCF_TSC_ADJUST
POINTER $OfsTStr("Software Guard Extensions (SGX)")                               ; 090 QCF_SGX
POINTER $OfsTStr("Bit Manipulation Instructions 1 (BMI1)")                        ; 091 QCF_BMI1
POINTER $OfsTStr("Hardware Lock Elision (HLE)")                                   ; 092 QCF_HLE
POINTER $OfsTStr("AVX2 instructions")                                             ; 093 QCF_AVX2
POINTER $OfsTStr("x87 FPU Data Pointer updated only on x87 exceptions")           ; 094 QCF_FDP_EXCPTN_ONLY
POINTER $OfsTStr("Supervisor Mode Execution Prevention (SMEP)")                   ; 095 QCF_SMEP
POINTER $OfsTStr("Bit Manipulation Instructions 2 (BMI2)")                        ; 096 QCF_BMI2
POINTER $OfsTStr("Enhanced REP MOVSB/STOSB (ERMS)")                               ; 097 QCF_ERMS
POINTER $OfsTStr("INVPCID instruction")                                           ; 098 QCF_INVPCID
POINTER $OfsTStr("Restricted Transactional Memory (RTM)")                         ; 099 QCF_RTM
POINTER $OfsTStr("Platform QoS Monitoring (PQM/RDT-M)")                           ; 100 QCF_PQM
POINTER $OfsTStr("Deprecates FPU CS and FPU DS values")                           ; 101 QCF_FCS_FDS
POINTER $OfsTStr("Memory Protection Extensions (MPX)")                            ; 102 QCF_MPX
POINTER $OfsTStr("Platform QoS Enforcement (PQE/RDT-A)")                          ; 103 QCF_PQE
POINTER $OfsTStr("AVX-512 Foundation (AVX512F)")                                  ; 104 QCF_AVX512F
POINTER $OfsTStr("AVX-512 Doubleword/Quadword (AVX512DQ)")                        ; 105 QCF_AVX512DQ
POINTER $OfsTStr("RDSEED instruction")                                            ; 106 QCF_RDSEED
POINTER $OfsTStr("Multi-Precision Add-Carry (ADX/ADCX/ADOX)")                     ; 107 QCF_ADX
POINTER $OfsTStr("Supervisor Mode Access Prevention (SMAP)")                      ; 108 QCF_SMAP
POINTER $OfsTStr("AVX-512 Integer Fused Multiply-Add (AVX512IFMA)")               ; 109 QCF_AVX512IFMA
POINTER $OfsTStr("CLFLUSHOPT instruction")                                        ; 110 QCF_CLFLUSHOPT
POINTER $OfsTStr("Cache Line Write-Back (CLWB)")                                  ; 111 QCF_CLWB
POINTER $OfsTStr("Intel Processor Trace (PT)")                                    ; 112 QCF_PT
POINTER $OfsTStr("AVX-512 Prefetch (AVX512PF/Xeon Phi)")                          ; 113 QCF_AVX512PF
POINTER $OfsTStr("AVX-512 Exp/Reciprocal (AVX512ER/Xeon Phi)")                    ; 114 QCF_AVX512ER
POINTER $OfsTStr("AVX-512 Conflict Detection (AVX512CD)")                         ; 115 QCF_AVX512CD
POINTER $OfsTStr("SHA-1/SHA-256 hardware instructions (SHA)")                     ; 116 QCF_SHA
POINTER $OfsTStr("AVX-512 Byte/Word instructions (AVX512BW)")                     ; 117 QCF_AVX512BW
POINTER $OfsTStr("AVX-512 Vector Length extensions (AVX512VL)")                   ; 118 QCF_AVX512VL

; -- CPUID(7,0).ECX ---------------------------------------------------------------
POINTER $OfsTStr("PREFETCHWT1 instruction (Xeon Phi)")                            ; 119 QCF_PREFETCHWT1
POINTER $OfsTStr("AVX-512 Vector Byte Manipulation (AVX512VBMI)")                 ; 120 QCF_AVX512VBMI
POINTER $OfsTStr("User Mode Instruction Prevention (UMIP)")                       ; 121 QCF_UMIP
POINTER $OfsTStr("Protection Keys for User-mode pages (PKU)")                     ; 122 QCF_PKU
POINTER $OfsTStr("OS has enabled Protection Keys (OSPKE)")                        ; 123 QCF_OSPKE
POINTER $OfsTStr("UMONITOR/UMWAIT/TPAUSE (WAITPKG)")                              ; 124 QCF_WAITPKG
POINTER $OfsTStr("AVX-512 Vector Byte Manipulation 2 (AVX512VBMI2)")              ; 125 QCF_AVX512VBMI2
POINTER $OfsTStr("CET Shadow Stack (CET-SS)")                                     ; 126 QCF_CET_SS
POINTER $OfsTStr("Galois Field New Instructions (GFNI)")                          ; 127 QCF_GFNI
POINTER $OfsTStr("Vector AES 256/512-bit (VAES)")                                 ; 128 QCF_VAES
POINTER $OfsTStr("Vector PCLMULQDQ 256/512-bit (VPCLMULQDQ)")                     ; 129 QCF_VPCLMULQDQ
POINTER $OfsTStr("AVX-512 Vector Neural Network (AVX512VNNI)")                    ; 130 QCF_AVX512VNNI
POINTER $OfsTStr("AVX-512 Bit Algorithms (AVX512BITALG)")                         ; 131 QCF_AVX512BITALG
POINTER $OfsTStr("Total Memory Encryption (TME)")                                 ; 132 QCF_TME
POINTER $OfsTStr("AVX-512 Vector POPCNT DW/QW (AVX512VPOPCNTDQ)")                 ; 133 QCF_AVX512VPOPCNTDQ
POINTER $OfsTStr("5-level paging 57-bit VA (LA57)")                               ; 134 QCF_LA57
POINTER $OfsTStr("RDPID instruction")                                             ; 135 QCF_RDPID
POINTER $OfsTStr("Key Locker (LOADIWKEY)")                                        ; 136 QCF_KL
POINTER $OfsTStr("Bus Lock Detection")                                            ; 137 QCF_BUS_LOCK_DETECT
POINTER $OfsTStr("CLDEMOTE instruction")                                          ; 138 QCF_CLDEMOTE
POINTER $OfsTStr("MOVDIRI instruction")                                           ; 139 QCF_MOVDIRI
POINTER $OfsTStr("MOVDIR64B instruction")                                         ; 140 QCF_MOVDIR64B
POINTER $OfsTStr("ENQCMD/ENQCMDS")                                                ; 141 QCF_ENQCMD
POINTER $OfsTStr("SGX Launch Configuration (SGX-LC)")                             ; 142 QCF_SGX_LC
POINTER $OfsTStr("Protection Keys Supervisor (PKS)")                              ; 143 QCF_PKS

; -- CPUID(7,0).EDX ---------------------------------------------------------------
POINTER $OfsTStr("Attestation Services for Intel SGX (SGX-KEYS)")                 ; 144 QCF_SGX_KEYS
POINTER $OfsTStr("AVX-512 4-register Neural Net Word (AVX5124VNNIW)")             ; 145 QCF_AVX512_4VNNIW
POINTER $OfsTStr("AVX-512 4-register FMA Single (AVX5124FMAPS)")                  ; 146 QCF_AVX512_4FMAPS
POINTER $OfsTStr("Fast Short REP MOVSB (FSRM)")                                   ; 147 QCF_FSRM
POINTER $OfsTStr("User Interrupts (UINTR)")                                       ; 148 QCF_UINTR
POINTER $OfsTStr("AVX-512 Vector Pair Intersection (AVX512VP2INTERSECT)")         ; 149 QCF_AVX512VP2INTER
POINTER $OfsTStr("SRBDS Mitigation MSR")                                          ; 150 QCF_SRBDS_CTRL
POINTER $OfsTStr("VERW clears CPU fill buffers (MDS mitigation)")                 ; 151 QCF_MD_CLEAR
POINTER $OfsTStr("XBEGIN always aborts (RTM mitigation)")                         ; 152 QCF_RTM_ALWAYS_ABORT
POINTER $OfsTStr("RTM_FORCE_ABORT MSR")                                           ; 153 QCF_TSX_FORCE_ABORT
POINTER $OfsTStr("SERIALIZE instruction")                                         ; 154 QCF_SERIALIZE
POINTER $OfsTStr("Hybrid processor (P+E cores)")                                  ; 155 QCF_HYBRID
POINTER $OfsTStr("TSX Suspend Load Address Tracking (TSXLDTRK)")                  ; 156 QCF_TSXLDTRK
POINTER $OfsTStr("PCONFIG instruction")                                           ; 157 QCF_PCONFIG
POINTER $OfsTStr("Architectural Last Branch Records (ARCH_LBR)")                  ; 158 QCF_LBR_ARCH
POINTER $OfsTStr("CET Indirect Branch Tracking (CET-IBT)")                        ; 159 QCF_CET_IBT
POINTER $OfsTStr("AMX BFloat16 (AMX-BF16)")                                       ; 160 QCF_AMX_BF16
POINTER $OfsTStr("AVX-512 FP16 (AVX512FP16/Sapphire Rapids+)")                    ; 161 QCF_AVX512_FP16
POINTER $OfsTStr("AMX Tile architecture (AMX-TILE)")                              ; 162 QCF_AMX_TILE
POINTER $OfsTStr("AMX INT8 matrix operations (AMX-INT8)")                         ; 163 QCF_AMX_INT8
POINTER $OfsTStr("IA32_SPEC_CTRL MSR - IBRS/IBPB (Intel only)")                   ; 164 QCF_INTEL_IBRS_IBPB
POINTER $OfsTStr("Single Thread Indirect Branch Predictors (Intel only)")         ; 165 QCF_INTEL_STIBP
POINTER $OfsTStr("L1D cache flush MSR (Intel only)")                              ; 166 QCF_INTEL_L1D_FLUSH
POINTER $OfsTStr("IA32_ARCH_CAPABILITIES MSR (Intel only)")                       ; 167 QCF_INTEL_ARCH_CAP
POINTER $OfsTStr("IA32_CORE_CAPABILITIES MSR (Intel only)")                       ; 168 QCF_INTEL_CORE_CAP
POINTER $OfsTStr("Speculative Store Bypass Disable (Intel only)")                 ; 169 QCF_INTEL_SSBD

; -- CPUID(7,1).EAX ---------------------------------------------------------------
POINTER $OfsTStr("SHA-512 hardware acceleration")                                 ; 170 QCF_SHA512
POINTER $OfsTStr("SM3 hash (Chinese standard)")                                   ; 171 QCF_SM3
POINTER $OfsTStr("SM4 cipher (Chinese standard)")                                 ; 172 QCF_SM4
POINTER $OfsTStr("Remote Atomic Operations (RAO-INT)")                            ; 173 QCF_RAO_INT
POINTER $OfsTStr("AVX-VNNI INT8 dot AVX2 width")                                  ; 174 QCF_AVX_VNNI
POINTER $OfsTStr("AVX-512 BFloat16 (AVX512BF16)")                                 ; 175 QCF_AVX512_BF16
POINTER $OfsTStr("Linear Address Space Separation (LASS)")                        ; 176 QCF_LASS
POINTER $OfsTStr("CMPccXADD instructions")                                        ; 177 QCF_CMPCCXADD
POINTER $OfsTStr("Zero-length REP MOVSB")                                         ; 178 QCF_FZRM
POINTER $OfsTStr("Fast Short REP STOSB")                                          ; 179 QCF_FSRS
POINTER $OfsTStr("Fast Short REP CMPSB/SCASB")                                    ; 180 QCF_FSRCS
POINTER $OfsTStr("Flexible Return/Event Delivery (FRED)")                         ; 181 QCF_FRED
POINTER $OfsTStr("LKGS instruction")                                              ; 182 QCF_LKGS
POINTER $OfsTStr("Non-serialising WRMSR (WRMSRNS)")                               ; 183 QCF_WRMSRNS
POINTER $OfsTStr("AMX FP16 matrix operations (AMX-FP16)")                         ; 184 QCF_AMX_FP16
POINTER $OfsTStr("HRESET instruction")                                            ; 185 QCF_HRESET
POINTER $OfsTStr("AVX-IFMA 52-bit")                                               ; 186 QCF_AVX_IFMA
POINTER $OfsTStr("Linear Address Masking (LAM)")                                  ; 187 QCF_LAM
POINTER $OfsTStr("RDMSRLIST/WRMSRLIST")                                           ; 188 QCF_MSRLIST

; -- CPUID(7,1).EDX ---------------------------------------------------------------
POINTER $OfsTStr("AVX-VNNI-INT8")                                                 ; 189 QCF_AVX_VNNI_INT8
POINTER $OfsTStr("AVX-NE-CONVERT")                                                ; 190 QCF_AVX_NE_CONVERT
POINTER $OfsTStr("AMX Complex matrix operations (AMX-COMPLEX)")                   ; 191 QCF_AMX_COMPLEX
POINTER $OfsTStr("AVX-VNNI-INT16")                                                ; 192 QCF_AVX_VNNI_INT16
POINTER $OfsTStr("PREFETCHIT0/1 instructions")                                    ; 193 QCF_PREFETCHI
POINTER $OfsTStr("User-mode MSR access (URDMSR/UWRMSR)")                          ; 194 QCF_USER_MSR
POINTER $OfsTStr("AVX10 (converged vector ISA)")                                  ; 195 QCF_AVX10
POINTER $OfsTStr("APX Foundation (R16-R31, NDD, NF, ...)")                        ; 196 QCF_APX_F
POINTER $OfsTStr("Static Lockstep Mode")                                          ; 197 QCF_SLSM

; -- CPUID(7,2).EDX ---------------------------------------------------------------
POINTER $OfsTStr("Predictive Store Forwarding Disable (PSFD)")                    ; 198 QCF_PSFD
POINTER $OfsTStr("IPRED_DIS MSR control")                                         ; 199 QCF_IPRED_DIS
POINTER $OfsTStr("RRSBA behaviour control")                                       ; 200 QCF_RRSBA_CTRL
POINTER $OfsTStr("Data-dependent prefetch disable (DDPD)")                        ; 201 QCF_DDPD_U
POINTER $OfsTStr("Branch History Injection control (BHI_CTRL)")                   ; 202 QCF_BHI_CTRL
POINTER $OfsTStr("MXCSR config-dependent timing")                                 ; 203 QCF_MCDT_NO
POINTER $OfsTStr("MONITOR/UMONITOR capacity mitigation not needed")               ; 204 QCF_MONITOR_MITG_NO

; -- CPUID(0Dh,1).EAX - XSAVE features -------------------------------------------
POINTER $OfsTStr("XSAVEOPT instruction")                                          ; 205 QCF_XSAVEOPT
POINTER $OfsTStr("XSAVEC + compacted XRSTOR")                                     ; 206 QCF_XSAVEC
POINTER $OfsTStr("XGETBV with ECX=1")                                             ; 207 QCF_XGETBV_ECX1
POINTER $OfsTStr("XSAVES/XRSTORS instructions")                                   ; 208 QCF_XSAVES

; -- CPUID(19h,0).EAX - AES Key Locker -------------------------------------------
POINTER $OfsTStr("AES Key Locker")                                                ; 209 QCF_AESKLE
POINTER $OfsTStr("Wide Key Locker 256/512-bit")                                   ; 210 QCF_WIDE_KL
POINTER $OfsTStr("Platform Key Locker")                                           ; 211 QCF_PLATFORM_KL

; -- CPUID(80000008h,0).EBX - AMD feature extensions -----------------------------
POINTER $OfsTStr("CLZERO instruction (AMD only)")                                 ; 212 QCF_AMD_CLZERO
POINTER $OfsTStr("Instructions-retired count support (AMD only)")                 ; 213 QCF_AMD_IRPERF
POINTER $OfsTStr("XSAVE always saves/restores FP error pointers (AMD only)")      ; 214 QCF_AMD_XSAVEERPTR
POINTER $OfsTStr("INVLPGB / TLBSYNC instructions (AMD only)")                     ; 215 QCF_AMD_INVLPGB
POINTER $OfsTStr("RDPRU instruction (AMD only)")                                  ; 216 QCF_AMD_RDPRU
POINTER $OfsTStr("Memory bandwidth enforcement (AMD only)")                       ; 217 QCF_AMD_MBE
POINTER $OfsTStr("MCOMMIT instruction (AMD only)")                                ; 218 QCF_AMD_MCOMMIT
POINTER $OfsTStr("WBNOINVD instruction (AMD only)")                               ; 219 QCF_AMD_WBNOINVD
POINTER $OfsTStr("IBPB support - IA32_PRED_CMD (AMD only)")                       ; 220 QCF_AMD_IBPB
POINTER $OfsTStr("WBINVD/WBNOINVD are interruptible (AMD only)")                  ; 221 QCF_AMD_INT_WBINVD
POINTER $OfsTStr("IBRS support - IA32_SPEC_CTRL (AMD only)")                      ; 222 QCF_AMD_IBRS
POINTER $OfsTStr("Single Thread Indirect Branch Predictors (AMD only)")           ; 223 QCF_AMD_STIBP
POINTER $OfsTStr("Speculative Store Bypass Disable (AMD only)")                   ; 224 QCF_AMD_SSBD

; -- CPUID(7,1).EAX - newer Intel features ----------------------------------------
POINTER $OfsTStr("PBNDKB instruction (Key Locker bounds check)")                  ; 225 QCF_PBNDKB
POINTER $OfsTStr("RETIRED - AMX-TRANSPOSE removed from Intel spec (ISE rev-059)") ; 226 QCF_AMX_TRANSPOSE
POINTER $OfsTStr("AMX TF32/FP32 matrix operations")                               ; 227 QCF_AMX_TF32
POINTER $OfsTStr("AMX-AVX512 interaction support")                                ; 228 QCF_AMX_AVX512
POINTER $OfsTStr("AMX with MOVRS streaming load support")                         ; 229 QCF_AMX_MOVRS

; -- CPUID(7,1).EDX - newer Intel features ----------------------------------------
POINTER $OfsTStr("AMX FP8 matrix operations (Clearwater Forest+)")                ; 230 QCF_AMX_FP8
POINTER $OfsTStr("AMX MOVRS variant (EDX[23])")                                   ; 231 QCF_AMX_MOVRS2
POINTER $OfsTStr("MOVRS/MOVURS streaming load instructions")                      ; 232 QCF_MOVRS

; -- CPUID(7,1).EBX ---------------------------------------------------------------
POINTER $OfsTStr("Protected Processor Inventory Number MSR (Intel only)")         ; 233 QCF_INTEL_PPIN

; -- CPUID(80000001h,0).ECX - additional AMD features ----------------------------
POINTER $OfsTStr("Translation Cache Extension (AMD only)")                        ; 234 QCF_AMD_TCE
POINTER $OfsTStr("Topology extension MSRs (AMD only)")                            ; 235 QCF_AMD_TOPEXT
POINTER $OfsTStr("Core performance counter extensions (AMD only)")                ; 236 QCF_AMD_PCXCORE
POINTER $OfsTStr("NB/DF performance counter extensions (AMD only)")               ; 237 QCF_AMD_PCXNB
POINTER $OfsTStr("Streaming performance monitor support (AMD only)")              ; 238 QCF_AMD_STREAMPERFMON
POINTER $OfsTStr("Data breakpoint extension (AMD only)")                          ; 239 QCF_AMD_DATABKPTEXT
POINTER $OfsTStr("Performance TSC (AMD only)")                                    ; 240 QCF_AMD_PERFTSC
POINTER $OfsTStr("L2I performance counter (AMD only)")                            ; 241 QCF_AMD_PERFL2I
POINTER $OfsTStr("MONITORX/MWAITX instructions (AMD only)")                       ; 242 QCF_AMD_MONITORX
POINTER $OfsTStr("Address mask extension for breakpoints (AMD only)")             ; 243 QCF_AMD_ADDRMASKEXT

; -- CPUID(80000008h,0).EBX - AMD security features (continued) ------------------
POINTER $OfsTStr("IBRS preferred always-on mode (AMD only)")                      ; 244 QCF_AMD_IBRS_ALWAYS_ON
POINTER $OfsTStr("STIBP always-on mode (AMD only)")                               ; 245 QCF_AMD_STIBP_ALWAYS_ON
POINTER $OfsTStr("IBRS preferred over software retpoline (AMD only)")             ; 246 QCF_AMD_IBRS_PREFERRED
POINTER $OfsTStr("IBRS provides same-mode protection (AMD only)")                 ; 247 QCF_AMD_IBRS_SAME_MODE
POINTER $OfsTStr("EFER.LMSLE not supported (AMD only)")                           ; 248 QCF_AMD_EFER_LMSLE_NO
POINTER $OfsTStr("Nested INVLPGB support (AMD only)")                             ; 249 QCF_AMD_INVLPGB_NEST
POINTER $OfsTStr("AMD Protected Processor Inventory Number (AMD only)")           ; 250 QCF_AMD_PPIN
POINTER $OfsTStr("SSBD via IA32_SPEC_CTRL MSR (AMD only)")                        ; 251 QCF_AMD_SSBD_SPEC_CTRL
POINTER $OfsTStr("Virtualized Speculative Store Bypass Disable (AMD only)")       ; 252 QCF_AMD_VIRT_SSBD
POINTER $OfsTStr("SSB not needed on this microarchitecture (AMD only)")           ; 253 QCF_AMD_SSBD_NOT_REQUIRED
POINTER $OfsTStr("Collaborative Processor Performance Control (AMD only)")        ; 254 QCF_AMD_CPPC
POINTER $OfsTStr("Predictive Store Forwarding Disable (AMD only)")                ; 255 QCF_AMD_PSFD
POINTER $OfsTStr("Branch Type Confusion vulnerability not present (AMD only)")    ; 256 QCF_AMD_BTC_NO
POINTER $OfsTStr("IBPB also clears return address predictor (AMD only)")          ; 257 QCF_AMD_IBPB_RET

; -- CPUID(80000021h,0).EAX - AMD Zen4+ extended features (EFI2) -----------------
POINTER $OfsTStr("Nested data breakpoints not supported (AMD Zen4+)")             ; 258 QCF_AMD_NO_NESTED_DATA_BP
POINTER $OfsTStr("LFENCE is always serializing (AMD Zen4+)")                      ; 259 QCF_AMD_LFENCE_ALWAYS_SERIAL
POINTER $OfsTStr("SMM page config locked (AMD Zen4+)")                            ; 260 QCF_AMD_SMM_PG_CFG_LOCK
POINTER $OfsTStr("NULL segment selector zeroes hidden base (AMD Zen4+)")          ; 261 QCF_AMD_NULL_SEL_CLEARS_BASE
POINTER $OfsTStr("Upper address bits can be masked (AMD Zen4+)")                  ; 262 QCF_AMD_UPPER_ADDR_IGNORE
POINTER $OfsTStr("Automatic IBRS; no software retpoline needed (AMD Zen4+)")      ; 263 QCF_AMD_AUTOIBRS
POINTER $OfsTStr("SMMCTL MSR not present (AMD Zen4+)")                            ; 264 QCF_AMD_NO_SMMCTL_MSR
POINTER $OfsTStr("Fast short REP MOVS (AMD Zen4+)")                               ; 265 QCF_AMD_FAST_SHORT_REP_MOVS
POINTER $OfsTStr("PREFETCH control MSR supported (AMD Zen4+)")                    ; 266 QCF_AMD_PREFETCHCTL_MSR
POINTER $OfsTStr("User-mode CPUID disable supported (AMD Zen4+)")                 ; 267 QCF_AMD_CPUID_USER_DIS
POINTER $OfsTStr("Enhanced Predictive Store Forwarding (AMD Zen4+)")              ; 268 QCF_AMD_EPSF

; -- CPUID(80000022h,0).EAX - AMD Performance Monitoring v2 ---------------------
POINTER $OfsTStr("Performance Monitoring v2 (AMD Zen4+)")                         ; 269 QCF_AMD_PERFMONV2
POINTER $OfsTStr("Last Branch Record v2 (AMD Zen4+)")                             ; 270 QCF_AMD_LBRV2
POINTER $OfsTStr("LBR and PMC freeze on PMI (AMD Zen4+)")                         ; 271 QCF_AMD_LBR_PMC_FREEZE

; -- CPUID(24h,0).EBX - Intel AVX10 vector-width capabilities --------------------
POINTER $OfsTStr("128-bit AVX10 vector operations supported (Intel only)")        ; 272 QCF_AVX10_128
POINTER $OfsTStr("256-bit AVX10 vector operations supported (Intel only)")        ; 273 QCF_AVX10_256
POINTER $OfsTStr("512-bit AVX10 vector operations supported (Intel only)")        ; 274 QCF_AVX10_512

; -- CPUID(7,1).EAX - additional Intel features ----------------------------------
POINTER $OfsTStr("INVD execution prevented after BIOS init (Intel only)")         ; 275 QCF_INVD_DISABLE
POINTER $OfsTStr("NMI source reporting via FRED event data (Intel only)")         ; 276 QCF_NMI_SRC
POINTER $OfsTStr("Immediate-form RDMSR/WRMSRNS (MSR_IMM, Intel only)")            ; 277 QCF_MSR_IMM

; -- CPUID(7,1).ECX - Intel Asymmetric RDT ---------------------------------------
POINTER $OfsTStr("Asymmetric Intel RDT Monitoring capable (Intel only)")          ; 278 QCF_ASYM_RDT_M
POINTER $OfsTStr("Asymmetric Intel RDT Allocation capable (Intel only)")          ; 279 QCF_ASYM_RDT_A

; -- CPUID(80000021h,0).EAX - AMD Zen5 extended features -------------------------
POINTER $OfsTStr("WRMSR to {FS,GS,KERNEL_GS}_BASE is non-serializing (AMD only)") ; 280 QCF_AMD_FS_GS_BASE_NS
POINTER $OfsTStr("VERW clears transient-scheduler-attack buffers (AMD Zen5+)")    ; 281 QCF_AMD_TSA_VERW_CLEAR
POINTER $OfsTStr("PREFETCHIT0/1 instructions via 80000021h (AMD only)")           ; 282 QCF_AMD_PREFETCHI
POINTER $OfsTStr("Selective Branch Predictor Barrier (AMD, SRSO mitigation)")     ; 283 QCF_AMD_SBPB
POINTER $OfsTStr("IBPB flushes branch-type predictors (AMD, SRSO mitigation)")    ; 284 QCF_AMD_IBPB_BRTYPE
POINTER $OfsTStr("Not vulnerable to SRSO/Inception (AMD Zen5+)")                  ; 285 QCF_AMD_SRSO_NO
POINTER $OfsTStr("Not vulnerable to SRSO at user/kernel boundary (AMD Zen5+)")    ; 286 QCF_AMD_SRSO_USER_KERNEL_NO
POINTER $OfsTStr("BP_CFG[BpSpecReduce] available to mitigate SRSO (AMD only)")    ; 287 QCF_AMD_SRSO_MSR_FIX

; -- CPUID(80000021h,0).ECX - AMD Zen5+ TSA immunity bits ------------------------
POINTER $OfsTStr("Not vulnerable to TSA L1 cache attack (AMD Zen5+)")             ; 288 QCF_AMD_TSA_L1_NO
POINTER $OfsTStr("Not vulnerable to TSA store-queue attack (AMD Zen5+)")          ; 289 QCF_AMD_TSA_SQ_NO
