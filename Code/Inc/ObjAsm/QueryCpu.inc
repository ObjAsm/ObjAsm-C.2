; ==================================================================================================
; Title:      QueryCpu.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    Central definitions file for the ObjAsm CPU query library.
;             Declares all public constants, prototypes, buffer size macros and return-value
;             structures consumed by QueryCpuFeature, QueryCpuValue, QueryCpuStruct and the
;             string-retrieval procedures.
; Notes:      Version C.1.0, June 2026
;               - Initial release.
;               - Bitness-neutral and platform-independent code.
; ==================================================================================================



VENDORSTR_INTEL             textequ <GenuineIntel>      ; Intel
VENDORSTR_AMD               textequ <AuthenticAMD>      ; AMD
VENDORSTR_CENTAUR           textequ <CentaurHauls>      ; VIA / Centaur
VENDORSTR_CYRIX             textequ <CyrixInstead>      ; Cyrix
VENDORSTR_NEXGEN            textequ <NexGenDriven>      ; NexGen (historical)
VENDORSTR_UMC               textequ <UMC UMC UMC >      ; UMC
VENDORSTR_SIS               textequ <SiS SiS SiS >      ; SiS


VENDORSTR_HYPERV_KVM        textequ <KVMKVMKVM>         ; KVM (Linux)
VENDORSTR_HYPERV_HYPERV     textequ <Microsoft Hv>      ; Microsoft Hyper-V
VENDORSTR_HYPERV_VMWARE     textequ <VMwareVMware>      ; VMware
VENDORSTR_HYPERV_XEN        textequ <XenVMMXenVMM>      ; Xen
VENDORSTR_HYPERV_VBOX       textequ <VBoxVBoxVBox>      ; Oracle VirtualBox
VENDORSTR_HYPERV_PARALLELS  textequ <Parallels>         ; Parallels Desktop
VENDORSTR_HYPERV_HYBRID     textequ <Hybrid>            ; Generic / some embedded hypervisors
VENDORSTR_HYPERV_BHYVE      textequ <bhyve>             ; FreeBSD bhyve (may appear truncated/padded)
VENDORSTR_HYPERV_QEMU       textequ <TCGTCGTCG>         ; QEMU TCG (varies by config, not always stable)

QueryCpuBrandStrA   proto :PSTRINGA
QueryCpuBrandStrW   proto :PSTRINGW
if TARGET_STR_TYPE eq STR_TYPE_ANSI
  QueryCpuBrandStr textequ <QueryCpuBrandStrA>
elseif TARGET_STR_TYPE eq STR_TYPE_WIDE
  QueryCpuBrandStr textequ <QueryCpuBrandStrW>
else
  echo Warning: incompatible TARGET_STR_TYPE
endif

QueryCpuVendorStrA  proto :PSTRINGA
QueryCpuVendorStrW  proto :PSTRINGW
if TARGET_STR_TYPE eq STR_TYPE_ANSI
  QueryCpuVendorStr textequ <QueryCpuVendorStrA>
elseif TARGET_STR_TYPE eq STR_TYPE_WIDE
  QueryCpuVendorStr textequ <QueryCpuVendorStrW>
else
  echo Warning: incompatible TARGET_STR_TYPE
endif

QueryCpuHypervisorVendorStrA  proto :PSTRINGA
QueryCpuHypervisorVendorStrW  proto :PSTRINGW
if TARGET_STR_TYPE eq STR_TYPE_ANSI
  QueryCpuHypervisorVendorStr textequ <QueryCpuHypervisorVendorStrA>
elseif TARGET_STR_TYPE eq STR_TYPE_WIDE
  QueryCpuHypervisorVendorStr textequ <QueryCpuHypervisorVendorStrW>
else
  echo Warning: incompatible TARGET_STR_TYPE
endif

MAX_CPU_VENDORSTRING_LENGTH equ  12
MAX_CPU_VENDORSTRING_SIZEA  equ  MAX_CPU_VENDORSTRING_LENGTH + 1
MAX_CPU_VENDORSTRING_SIZEW  equ  2*MAX_CPU_VENDORSTRING_SIZEA

MAX_CPU_BRANDSTRING_LENGTH  equ  48
MAX_CPU_BRANDSTRING_SIZEA   equ  MAX_CPU_BRANDSTRING_LENGTH + 1
MAX_CPU_BRANDSTRING_SIZEW   equ  2*MAX_CPU_BRANDSTRING_SIZEA

; QCF_xxx - feature index constants
; -- CPUID(1,0).EDX ---------------------------------------------------------------
QCF_FPU                       equ   0     ; Floating Point Unit on-chip (FPU)
QCF_VME                       equ   1     ; Virtual 8086 Mode Extensions (VME)
QCF_DE                        equ   2     ; Debugging Extensions (DE)
QCF_PSE                       equ   3     ; Page Size Extension 4 MB pages (PSE)
QCF_TSC                       equ   4     ; Time Stamp Counter (TSC/RDTSC)
QCF_MSR                       equ   5     ; Model Specific Registers (MSR)
QCF_PAE                       equ   6     ; Physical Address Extension (PAE)
QCF_MCE                       equ   7     ; Machine Check Exception (MCE)
QCF_CX8                       equ   8     ; CMPXCHG8B instruction
QCF_APIC                      equ   9     ; APIC on-chip
QCF_INTL_RSVD_10              equ  10     ; Intel Reserved EDX bit 10 (always returns FALSE)
QCF_SEP                       equ  11     ; Fast System Call (SYSENTER/SYSEXIT)
QCF_MTRR                      equ  12     ; Memory Type Range Registers (MTRR)
QCF_PGE                       equ  13     ; Page Global Enable (PGE)
QCF_MCA                       equ  14     ; Machine Check Architecture (MCA)
QCF_CMOV                      equ  15     ; Conditional Move (CMOVcc)
QCF_PAT                       equ  16     ; Page Attribute Table (PAT)
QCF_PSE36                     equ  17     ; 36-bit Page Size Extension (PSE-36)
QCF_PSN                       equ  18     ; Processor Serial Number (PSN)
QCF_CLFSH                     equ  19     ; CLFLUSH instruction
QCF_INTL_RSVD_20              equ  20     ; Intel Reserved EDX bit 20 (always returns FALSE)
QCF_DS                        equ  21     ; Debug Store (DS)
QCF_ACPI                      equ  22     ; Thermal Monitor and Software Clock (ACPI)
QCF_MMX                       equ  23     ; MMX Technology
QCF_FXSR                      equ  24     ; FXSAVE/FXRSTOR instructions
QCF_SSE                       equ  25     ; SSE instructions
QCF_SSE2                      equ  26     ; SSE2 instructions
QCF_SS                        equ  27     ; Self Snoop (SS)
QCF_HTT                       equ  28     ; Hyper-Threading Technology (HTT)
QCF_TM                        equ  29     ; Thermal Monitor (TM)
QCF_INTL_RSVD_30              equ  30     ; Intel Reserved EDX bit 30 (always returns FALSE)
QCF_PBE                       equ  31     ; Pending Break Enable (PBE)
; -- CPUID(1,0).ECX ---------------------------------------------------------------
QCF_SSE3                      equ  32     ; SSE3 instructions
QCF_PCLMULQDQ                 equ  33     ; Carry-less Multiplication (PCLMULQDQ)
QCF_DTES64                    equ  34     ; 64-bit DS Area (DTES64)
QCF_MONITOR                   equ  35     ; MONITOR/MWAIT instructions
QCF_DS_CPL                    equ  36     ; CPL Qualified Debug Store (DS-CPL)
QCF_VMX                       equ  37     ; Virtual Machine Extensions (VT-x/VMX)
QCF_SMX                       equ  38     ; Safer Mode Extensions (TXT/SMX)
QCF_EIST                      equ  39     ; Enhanced Intel SpeedStep (EIST)
QCF_TM2                       equ  40     ; Thermal Monitor 2 (TM2)
QCF_SSSE3                     equ  41     ; Supplemental SSE3 (SSSE3)
QCF_CNXT_ID                   equ  42     ; L1 Data Cache Context ID (CNXT-ID)
QCF_SDBG                      equ  43     ; Silicon Debug MSR (SDBG)
QCF_FMA                       equ  44     ; Fused Multiply-Add 3-operand (FMA3)
QCF_CX16                      equ  45     ; CMPXCHG16B instruction
QCF_xTPR                      equ  46     ; xTPR Update Control
QCF_PDCM                      equ  47     ; Perfmon and Debug Capability MSR (PDCM)
QCF_PCID                      equ  48     ; Process Context Identifiers (PCID)
QCF_DCA                       equ  49     ; Direct Cache Access (DCA)
QCF_SSE41                     equ  50     ; SSE 4.1 instructions (SSE4.1)
QCF_SSE42                     equ  51     ; SSE 4.2 instructions (SSE4.2)
QCF_x2APIC                    equ  52     ; x2APIC support
QCF_MOVBE                     equ  53     ; MOVBE instruction
QCF_POPCNT                    equ  54     ; POPCNT instruction
QCF_TSC_DEADLINE              equ  55     ; TSC Deadline timer
QCF_AES                       equ  56     ; AES-NI instructions (AES)
QCF_XSAVE                     equ  57     ; XSAVE/XRSTOR/XSETBV/XGETBV
QCF_OSXSAVE                   equ  58     ; OS enabled XSAVE
QCF_AVX                       equ  59     ; OS enabled and hardware support AVX
QCF_F16C                      equ  60     ; 16-bit FP conversion (F16C)
QCF_RDRAND                    equ  61     ; RDRAND instruction
QCF_HYPERVISOR                equ  62     ; Hypervisor present
; -- CPUID(80000001h,0).EDX -------------------------------------------------------
QCF_SYSCALL_EX                equ  63     ; SYSCALL/SYSRET (AMD64)
QCF_NX                        equ  64     ; No-Execute bit (NX/XD)
QCF_AMD_MMXEXT                equ  65     ; AMD MMX Extensions
QCF_AMD_FFXSR                 equ  66     ; FXSAVE/FXRSTOR optimisations
QCF_1GB_PAGE                  equ  67     ; 1 GB page support (PDPE1GB)
QCF_RDTSCP_EX                 equ  68     ; RDTSCP + IA32_TSC_AUX
QCF_LM                        equ  69     ; Long Mode 64-bit (EM64T/AMD64)
QCF_AMD_3DNOWEXT              equ  70     ; AMD 3DNow! Extensions
QCF_AMD_3DNOW                 equ  71     ; AMD 3DNow!
; -- CPUID(80000001h,0).ECX -------------------------------------------------------
QCF_LAHF64                    equ  72     ; LAHF/SAHF in 64-bit mode
QCF_AMD_CMP_LEGACY            equ  73     ; Core MP legacy mode (CmpLegacy)
QCF_AMD_SVM                   equ  74     ; AMD-V Virtualisation (SVM)
QCF_AMD_EXT_APIC              equ  75     ; Extended APIC space (ExtApicSpace)
QCF_AMD_ALT_MOV_CR8           equ  76     ; LOCK MOV CR0 = MOV CR8 (AltMovCr8)
QCF_LZCNT                     equ  77     ; LZCNT/POPCNT (ABM)
QCF_AMD_SSE4A                 equ  78     ; SSE4a instructions
QCF_AMD_MISALIGN              equ  79     ; Misaligned SSE support
QCF_AMD_3DNOW_PF              equ  80     ; 3DNow! Prefetch
QCF_AMD_OSVW                  equ  81     ; OS-visible workaround support (OSVW)
QCF_AMD_IBS                   equ  82     ; Instruction-based sampling (IBS)
QCF_AMD_XOP                   equ  83     ; XOP instructions
QCF_AMD_SKINIT                equ  84     ; SKINIT/STGI instructions
QCF_AMD_WDT                   equ  85     ; Watchdog timer support (WDT)
QCF_AMD_FMA4                  equ  86     ; FMA4 instructions
QCF_AMD_TBM                   equ  87     ; Trailing Bit Manipulation (TBM)
; -- CPUID(7,0).EBX ---------------------------------------------------------------
QCF_FSGSBASE                  equ  88     ; RDFSBASE/RDGSBASE/WRFSBASE/WRGSBASE
QCF_TSC_ADJUST                equ  89     ; IA32_TSC_ADJUST MSR
QCF_SGX                       equ  90     ; Software Guard Extensions (SGX)
QCF_BMI1                      equ  91     ; Bit Manipulation Instructions 1 (BMI1)
QCF_HLE                       equ  92     ; Hardware Lock Elision (HLE)
QCF_AVX2                      equ  93     ; AVX2 instructions
QCF_FDP_EXCPTN_ONLY           equ  94     ; x87 FPU Data Pointer updated only on x87 exceptions
QCF_SMEP                      equ  95     ; Supervisor Mode Execution Prevention (SMEP)
QCF_BMI2                      equ  96     ; Bit Manipulation Instructions 2 (BMI2)
QCF_ERMS                      equ  97     ; Enhanced REP MOVSB/STOSB (ERMS)
QCF_INVPCID                   equ  98     ; INVPCID instruction
QCF_RTM                       equ  99     ; Restricted Transactional Memory (RTM)
QCF_PQM                       equ 100     ; Platform QoS Monitoring (PQM/RDT-M)
QCF_FCS_FDS                   equ 101     ; Deprecates FPU CS and FPU DS values
QCF_MPX                       equ 102     ; Memory Protection Extensions (MPX)
QCF_PQE                       equ 103     ; Platform QoS Enforcement (PQE/RDT-A)
QCF_AVX512F                   equ 104     ; AVX-512 Foundation (AVX512F)
QCF_AVX512DQ                  equ 105     ; AVX-512 Doubleword/Quadword (AVX512DQ)
QCF_RDSEED                    equ 106     ; RDSEED instruction
QCF_ADX                       equ 107     ; Multi-Precision Add-Carry (ADX/ADCX/ADOX)
QCF_SMAP                      equ 108     ; Supervisor Mode Access Prevention (SMAP)
QCF_AVX512IFMA                equ 109     ; AVX-512 Integer Fused Multiply-Add (AVX512IFMA)
QCF_CLFLUSHOPT                equ 110     ; CLFLUSHOPT instruction
QCF_CLWB                      equ 111     ; Cache Line Write-Back (CLWB)
QCF_PT                        equ 112     ; Intel Processor Trace (PT)
QCF_AVX512PF                  equ 113     ; AVX-512 Prefetch (AVX512PF/Xeon Phi)
QCF_AVX512ER                  equ 114     ; AVX-512 Exp/Reciprocal (AVX512ER/Xeon Phi)
QCF_AVX512CD                  equ 115     ; AVX-512 Conflict Detection (AVX512CD)
QCF_SHA                       equ 116     ; SHA-1/SHA-256 hardware instructions (SHA)
QCF_AVX512BW                  equ 117     ; AVX-512 Byte/Word instructions (AVX512BW)
QCF_AVX512VL                  equ 118     ; AVX-512 Vector Length extensions (AVX512VL)
; -- CPUID(7,0).ECX ---------------------------------------------------------------
QCF_PREFETCHWT1               equ 119     ; PREFETCHWT1 instruction (Xeon Phi)
QCF_AVX512VBMI                equ 120     ; AVX-512 Vector Byte Manipulation (AVX512VBMI)
QCF_UMIP                      equ 121     ; User Mode Instruction Prevention (UMIP)
QCF_PKU                       equ 122     ; Protection Keys for User-mode pages (PKU)
QCF_OSPKE                     equ 123     ; OS has enabled Protection Keys (OSPKE)
QCF_WAITPKG                   equ 124     ; UMONITOR/UMWAIT/TPAUSE (WAITPKG)
QCF_AVX512VBMI2               equ 125     ; AVX-512 Vector Byte Manipulation 2 (AVX512VBMI2)
QCF_CET_SS                    equ 126     ; CET Shadow Stack (CET-SS)
QCF_GFNI                      equ 127     ; Galois Field New Instructions (GFNI)
QCF_VAES                      equ 128     ; Vector AES 256/512-bit (VAES)
QCF_VPCLMULQDQ                equ 129     ; Vector PCLMULQDQ 256/512-bit (VPCLMULQDQ)
QCF_AVX512VNNI                equ 130     ; AVX-512 Vector Neural Network (AVX512VNNI)
QCF_AVX512BITALG              equ 131     ; AVX-512 Bit Algorithms (AVX512BITALG)
QCF_TME                       equ 132     ; Total Memory Encryption (TME)
QCF_AVX512VPOPCNTDQ           equ 133     ; AVX-512 Vector POPCNT DW/QW (AVX512VPOPCNTDQ)
QCF_LA57                      equ 134     ; 5-level paging 57-bit VA (LA57)
QCF_RDPID                     equ 135     ; RDPID instruction
QCF_KL                        equ 136     ; Key Locker (LOADIWKEY)
QCF_BUS_LOCK_DETECT           equ 137     ; Bus Lock Detection
QCF_CLDEMOTE                  equ 138     ; CLDEMOTE instruction
QCF_MOVDIRI                   equ 139     ; MOVDIRI instruction
QCF_MOVDIR64B                 equ 140     ; MOVDIR64B instruction
QCF_ENQCMD                    equ 141     ; ENQCMD/ENQCMDS
QCF_SGX_LC                    equ 142     ; SGX Launch Configuration (SGX-LC)
QCF_PKS                       equ 143     ; Protection Keys Supervisor (PKS)
; -- CPUID(7,0).EDX ---------------------------------------------------------------
QCF_SGX_KEYS                  equ 144     ; Attestation Services for Intel SGX (SGX-KEYS)
QCF_AVX512_4VNNIW             equ 145     ; AVX-512 4-register Neural Net Word (AVX5124VNNIW)
QCF_AVX512_4FMAPS             equ 146     ; AVX-512 4-register FMA Single (AVX5124FMAPS)
QCF_FSRM                      equ 147     ; Fast Short REP MOVSB (FSRM)
QCF_UINTR                     equ 148     ; User Interrupts (UINTR)
QCF_AVX512VP2INTER            equ 149     ; AVX-512 Vector Pair Intersection (AVX512VP2INTERSECT)
QCF_SRBDS_CTRL                equ 150     ; SRBDS Mitigation MSR
QCF_MD_CLEAR                  equ 151     ; VERW clears CPU fill buffers (MDS mitigation)
QCF_RTM_ALWAYS_ABORT          equ 152     ; XBEGIN always aborts (RTM mitigation)
QCF_TSX_FORCE_ABORT           equ 153     ; RTM_FORCE_ABORT MSR
QCF_SERIALIZE                 equ 154     ; SERIALIZE instruction
QCF_HYBRID                    equ 155     ; Hybrid processor (P+E cores)
QCF_TSXLDTRK                  equ 156     ; TSX Suspend Load Address Tracking (TSXLDTRK)
QCF_PCONFIG                   equ 157     ; PCONFIG instruction
QCF_LBR_ARCH                  equ 158     ; Architectural Last Branch Records (ARCH_LBR)
QCF_CET_IBT                   equ 159     ; CET Indirect Branch Tracking (CET-IBT)
QCF_AMX_BF16                  equ 160     ; AMX BFloat16 (AMX-BF16)
QCF_AVX512_FP16               equ 161     ; AVX-512 FP16 (AVX512FP16/Sapphire Rapids+)
QCF_AMX_TILE                  equ 162     ; AMX Tile architecture (AMX-TILE)
QCF_AMX_INT8                  equ 163     ; AMX INT8 matrix operations (AMX-INT8)
QCF_INTEL_IBRS_IBPB           equ 164     ; IA32_SPEC_CTRL MSR - IBRS/IBPB (Intel only)
QCF_INTEL_STIBP               equ 165     ; Single Thread Indirect Branch Predictors (Intel only)
QCF_INTEL_L1D_FLUSH           equ 166     ; L1D cache flush MSR (Intel only)
QCF_INTEL_ARCH_CAP            equ 167     ; IA32_ARCH_CAPABILITIES MSR (Intel only)
QCF_INTEL_CORE_CAP            equ 168     ; IA32_CORE_CAPABILITIES MSR (Intel only)
QCF_INTEL_SSBD                equ 169     ; Speculative Store Bypass Disable (Intel only)
; -- CPUID(7,1).EAX ---------------------------------------------------------------
QCF_SHA512                    equ 170     ; SHA-512 hardware acceleration
QCF_SM3                       equ 171     ; SM3 hash (Chinese standard)
QCF_SM4                       equ 172     ; SM4 cipher (Chinese standard)
QCF_RAO_INT                   equ 173     ; Remote Atomic Operations (RAO-INT)
QCF_AVX_VNNI                  equ 174     ; AVX-VNNI INT8 dot AVX2 width
QCF_AVX512_BF16               equ 175     ; AVX-512 BFloat16 (AVX512BF16)
QCF_LASS                      equ 176     ; Linear Address Space Separation (LASS)
QCF_CMPCCXADD                 equ 177     ; CMPccXADD instructions
QCF_FZRM                      equ 178     ; Zero-length REP MOVSB
QCF_FSRS                      equ 179     ; Fast Short REP STOSB
QCF_FSRCS                     equ 180     ; Fast Short REP CMPSB/SCASB
QCF_FRED                      equ 181     ; Flexible Return/Event Delivery (FRED)
QCF_LKGS                      equ 182     ; LKGS instruction
QCF_WRMSRNS                   equ 183     ; Non-serialising WRMSR (WRMSRNS)
QCF_AMX_FP16                  equ 184     ; AMX FP16 matrix operations (AMX-FP16)
QCF_HRESET                    equ 185     ; HRESET instruction
QCF_AVX_IFMA                  equ 186     ; AVX-IFMA 52-bit
QCF_LAM                       equ 187     ; Linear Address Masking (LAM)
QCF_MSRLIST                   equ 188     ; RDMSRLIST/WRMSRLIST
; -- CPUID(7,1).EDX ---------------------------------------------------------------
QCF_AVX_VNNI_INT8             equ 189     ; AVX-VNNI-INT8
QCF_AVX_NE_CONVERT            equ 190     ; AVX-NE-CONVERT
QCF_AMX_COMPLEX               equ 191     ; AMX Complex matrix operations (AMX-COMPLEX)
QCF_AVX_VNNI_INT16            equ 192     ; AVX-VNNI-INT16
QCF_PREFETCHI                 equ 193     ; PREFETCHIT0/1 instructions
QCF_USER_MSR                  equ 194     ; User-mode MSR access (URDMSR/UWRMSR)
QCF_AVX10                     equ 195     ; AVX10 (converged vector ISA)
QCF_APX_F                     equ 196     ; APX Foundation (R16-R31, NDD, NF, ...)
QCF_SLSM                      equ 197     ; Static Lockstep Mode
; -- CPUID(7,2).EDX ---------------------------------------------------------------
QCF_PSFD                      equ 198     ; Predictive Store Forwarding Disable (PSFD)
QCF_IPRED_DIS                 equ 199     ; IPRED_DIS MSR control
QCF_RRSBA_CTRL                equ 200     ; RRSBA behaviour control
QCF_DDPD_U                    equ 201     ; Data-dependent prefetch disable (DDPD)
QCF_BHI_CTRL                  equ 202     ; Branch History Injection control (BHI_CTRL)
QCF_MCDT_NO                   equ 203     ; MXCSR config-dependent timing
QCF_MONITOR_MITG_NO           equ 204     ; MONITOR/UMONITOR capacity mitigation not needed
; -- CPUID(0Dh,1).EAX - XSAVE features -------------------------------------------
QCF_XSAVEOPT                  equ 205     ; XSAVEOPT instruction
QCF_XSAVEC                    equ 206     ; XSAVEC + compacted XRSTOR
QCF_XGETBV_ECX1               equ 207     ; XGETBV with ECX=1
QCF_XSAVES                    equ 208     ; XSAVES/XRSTORS instructions
; -- CPUID(19h,0).EAX - AES Key Locker -------------------------------------------
QCF_AESKLE                    equ 209     ; AES Key Locker
QCF_WIDE_KL                   equ 210     ; Wide Key Locker 256/512-bit
QCF_PLATFORM_KL               equ 211     ; Platform Key Locker
; -- CPUID(80000008h,0).EBX - AMD feature extensions -----------------------------
QCF_AMD_CLZERO                equ 212     ; CLZERO instruction (AMD only)
QCF_AMD_IRPERF                equ 213     ; Instructions-retired count support (AMD only)
QCF_AMD_XSAVEERPTR            equ 214     ; XSAVE always saves/restores FP error pointers (AMD only)
QCF_AMD_INVLPGB               equ 215     ; INVLPGB / TLBSYNC instructions (AMD only)
QCF_AMD_RDPRU                 equ 216     ; RDPRU instruction (AMD only)
QCF_AMD_MBE                   equ 217     ; Memory bandwidth enforcement (AMD only)
QCF_AMD_MCOMMIT               equ 218     ; MCOMMIT instruction (AMD only)
QCF_AMD_WBNOINVD              equ 219     ; WBNOINVD instruction (AMD only)
QCF_AMD_IBPB                  equ 220     ; IBPB support - IA32_PRED_CMD (AMD only)
QCF_AMD_INT_WBINVD            equ 221     ; WBINVD/WBNOINVD are interruptible (AMD only)
QCF_AMD_IBRS                  equ 222     ; IBRS support - IA32_SPEC_CTRL (AMD only)
QCF_AMD_STIBP                 equ 223     ; Single Thread Indirect Branch Predictors (AMD only)
QCF_AMD_SSBD                  equ 224     ; Speculative Store Bypass Disable (AMD only)
; -- CPUID(7,1).EAX - newer Intel features ----------------------------------------
QCF_PBNDKB                    equ 225     ; PBNDKB instruction (Key Locker bounds check)
QCF_AMX_TRANSPOSE             equ 226     ; RETIRED - AMX-TRANSPOSE removed from Intel spec (ISE rev-059)
QCF_AMX_TF32                  equ 227     ; AMX TF32/FP32 matrix operations
QCF_AMX_AVX512                equ 228     ; AMX-AVX512 interaction support
QCF_AMX_MOVRS                 equ 229     ; AMX with MOVRS streaming load support
; -- CPUID(7,1).EDX - newer Intel features ----------------------------------------
QCF_AMX_FP8                   equ 230     ; AMX FP8 matrix operations (Clearwater Forest+)
QCF_AMX_MOVRS2                equ 231     ; AMX MOVRS variant (EDX[23])
QCF_MOVRS                     equ 232     ; MOVRS/MOVURS streaming load instructions
; -- CPUID(7,1).EBX ---------------------------------------------------------------
QCF_INTEL_PPIN                equ 233     ; Protected Processor Inventory Number MSR (Intel only)
; -- CPUID(80000001h,0).ECX - missing AMD features --------------------------------
QCF_AMD_TCE                   equ 234     ; Translation Cache Extension (AMD only)
QCF_AMD_TOPEXT                equ 235     ; Topology extension MSRs (AMD only)
QCF_AMD_PCXCORE               equ 236     ; Core performance counter extensions (AMD only)
QCF_AMD_PCXNB                 equ 237     ; NB/DF performance counter extensions (AMD only)
QCF_AMD_STREAMPERFMON         equ 238     ; Streaming performance monitor support (AMD only)
QCF_AMD_DATABKPTEXT           equ 239     ; Data breakpoint extension (AMD only)
QCF_AMD_PERFTSC               equ 240     ; Performance TSC (AMD only)
QCF_AMD_PERFL2I               equ 241     ; L2I performance counter (AMD only)
QCF_AMD_MONITORX              equ 242     ; MONITORX/MWAITX instructions (AMD only)
QCF_AMD_ADDRMASKEXT           equ 243     ; Address mask extension for breakpoints (AMD only)
; -- CPUID(80000008h,0).EBX - missing AMD security features -----------------------
QCF_AMD_IBRS_ALWAYS_ON        equ 244     ; IBRS preferred always-on mode (AMD only)
QCF_AMD_STIBP_ALWAYS_ON       equ 245     ; STIBP always-on mode (AMD only)
QCF_AMD_IBRS_PREFERRED        equ 246     ; IBRS preferred over software retpoline (AMD only)
QCF_AMD_IBRS_SAME_MODE        equ 247     ; IBRS provides same-mode protection (AMD only)
QCF_AMD_EFER_LMSLE_NO         equ 248     ; EFER.LMSLE not supported (AMD only)
QCF_AMD_INVLPGB_NEST          equ 249     ; Nested INVLPGB support (AMD only)
QCF_AMD_PPIN                  equ 250     ; AMD Protected Processor Inventory Number (AMD only)
QCF_AMD_SSBD_SPEC_CTRL        equ 251     ; SSBD via IA32_SPEC_CTRL MSR (AMD only)
QCF_AMD_VIRT_SSBD             equ 252     ; Virtualized Speculative Store Bypass Disable (AMD only)
QCF_AMD_SSBD_NOT_REQUIRED     equ 253     ; SSB not needed on this microarchitecture (AMD only)
QCF_AMD_CPPC                  equ 254     ; Collaborative Processor Performance Control (AMD only)
QCF_AMD_PSFD                  equ 255     ; Predictive Store Forwarding Disable (AMD only)
QCF_AMD_BTC_NO                equ 256     ; Branch Type Confusion vulnerability not present (AMD only)
QCF_AMD_IBPB_RET              equ 257     ; IBPB also clears return address predictor (AMD only)
; -- CPUID(80000021h,0).EAX - AMD Zen4+ extended features (EFI2) -----------------
QCF_AMD_NO_NESTED_DATA_BP     equ 258     ; Nested data breakpoints not supported (AMD Zen4+)
QCF_AMD_LFENCE_ALWAYS_SERIAL  equ 259     ; LFENCE is always serializing (AMD Zen4+)
QCF_AMD_SMM_PG_CFG_LOCK       equ 260     ; SMM page config locked (AMD Zen4+)
QCF_AMD_NULL_SEL_CLEARS_BASE  equ 261     ; NULL segment selector zeroes hidden base (AMD Zen4+)
QCF_AMD_UPPER_ADDR_IGNORE     equ 262     ; Upper address bits can be masked (AMD Zen4+)
QCF_AMD_AUTOIBRS              equ 263     ; Automatic IBRS; no software retpoline needed (AMD Zen4+)
QCF_AMD_NO_SMMCTL_MSR         equ 264     ; SMMCTL MSR not present (AMD Zen4+)
QCF_AMD_FAST_SHORT_REP_MOVS   equ 265     ; Fast short REP MOVS (AMD Zen4+)
QCF_AMD_PREFETCHCTL_MSR       equ 266     ; PREFETCH control MSR supported (AMD Zen4+)
QCF_AMD_CPUID_USER_DIS        equ 267     ; User-mode CPUID disable supported (AMD Zen4+)
QCF_AMD_EPSF                  equ 268     ; Enhanced Predictive Store Forwarding (AMD Zen4+)
; -- CPUID(80000022h,0).EAX - AMD Performance Monitoring v2 ----------------------
QCF_AMD_PERFMONV2             equ 269     ; Performance Monitoring v2 (AMD Zen4+)
QCF_AMD_LBRV2                 equ 270     ; Last Branch Record v2 (AMD Zen4+)
QCF_AMD_LBR_PMC_FREEZE        equ 271     ; LBR and PMC freeze on PMI (AMD Zen4+)
; -- CPUID(24h,0).EBX - Intel AVX10 vector-width capabilities --------------------
QCF_AVX10_128                 equ 272     ; 128-bit AVX10 vector operations supported (Intel only)
QCF_AVX10_256                 equ 273     ; 256-bit AVX10 vector operations supported (Intel only)
QCF_AVX10_512                 equ 274     ; 512-bit AVX10 vector operations supported (Intel only)
; -- CPUID(7,1).EAX - missing Intel features --------------------------------------
QCF_INVD_DISABLE              equ 275     ; INVD execution prevented after BIOS init (Intel only)
QCF_NMI_SRC                   equ 276     ; NMI source reporting via FRED event data (Intel only)
QCF_MSR_IMM                   equ 277     ; Immediate-form RDMSR/WRMSRNS (MSR_IMM, Intel only)
; -- CPUID(7,1).ECX - Intel Asymmetric RDT ----------------------------------------
QCF_ASYM_RDT_M                equ 278     ; Asymmetric Intel RDT Monitoring capable (Intel only)
QCF_ASYM_RDT_A                equ 279     ; Asymmetric Intel RDT Allocation capable (Intel only)
; -- CPUID(80000021h,0).EAX - missing AMD Zen4/5 features -------------------------
QCF_AMD_FS_GS_BASE_NS         equ 280     ; WRMSR to {FS,GS,KERNEL_GS}_BASE is non-serializing (AMD only)
QCF_AMD_TSA_VERW_CLEAR        equ 281     ; VERW clears transient-scheduler-attack buffers (AMD Zen5+)
QCF_AMD_PREFETCHI             equ 282     ; PREFETCHIT0/1 instructions via 80000021h (AMD only)
QCF_AMD_SBPB                  equ 283     ; Selective Branch Predictor Barrier (AMD, SRSO mitigation)
QCF_AMD_IBPB_BRTYPE           equ 284     ; IBPB flushes branch-type predictors (AMD, SRSO mitigation)
QCF_AMD_SRSO_NO               equ 285     ; Not vulnerable to SRSO/Inception (AMD Zen5+)
QCF_AMD_SRSO_USER_KERNEL_NO   equ 286     ; Not vulnerable to SRSO at user/kernel boundary (AMD Zen5+)
QCF_AMD_SRSO_MSR_FIX          equ 287     ; BP_CFG[BpSpecReduce] available to mitigate SRSO (AMD only)
; -- CPUID(80000021h,0).ECX - AMD Zen5+ TSA immunity ------------------------------
QCF_AMD_TSA_L1_NO             equ 288     ; Not vulnerable to TSA L1 cache attack (AMD Zen5+)
QCF_AMD_TSA_SQ_NO             equ 289     ; Not vulnerable to TSA store-queue attack (AMD Zen5+)
QCF_COUNT                     equ 290     ; Must equal highest index + 1


; QCV_xxx - value index constants
QCV_STEPPING                  equ   0     ; Stepping ID (EAX[3:0])
QCV_MODEL                     equ   1     ; Model (EAX[7:4])
QCV_FAMILY                    equ   2     ; Family ID (EAX[11:8])
QCV_EXT_MODEL                 equ   3     ; Extended Model ID (EAX[19:16])
QCV_EXT_FAMILY                equ   4     ; Extended Family ID (EAX[27:20])
QCV_BRAND_IDX                 equ   5     ; Brand Index (EBX[7:0])
QCV_CLFLUSH_SIZE              equ   6     ; CLFLUSH line size x8 bytes (EBX[15:8])
QCV_LOGICAL_COUNT             equ   7     ; Max logical processors in package (EBX[23:16])
QCV_APIC_ID                   equ   8     ; Initial APIC ID (EBX[31:24])
QCV_MAX_BASIC_LEAF            equ   9     ; Maximum basic CPUID leaf supported
QCV_MAX_EXT_LEAF              equ  10     ; Maximum extended CPUID leaf supported
QCV_PHYS_ADDR_BITS            equ  11     ; Physical address bits (EAX[7:0])
QCV_LIN_ADDR_BITS             equ  12     ; Linear address bits (EAX[15:8])
QCV_AMD_CORE_COUNT            equ  13     ; Core count minus 1 (AMD only, ECX[7:0])
QCV_AMD_APIC_ID_SIZE          equ  14     ; APIC ID size field (AMD only, ECX[15:12])
QCV_MAX_SUBLEAF_7             equ  15     ; Maximum supported subleaf index for leaf 7
QCV_AVX10_VERSION             equ  16     ; AVX10 converged ISA version number (Intel only, EBX[7:0])
QCV_XCR0_LOWER                equ  17     ; XCR0 supported features bits 31:0  (EAX)
QCV_XCR0_UPPER                equ  18     ; XCR0 supported features bits 63:32 (EDX)
QCV_XSAVE_SIZE_OS             equ  19     ; Max XSAVE area size enabled by OS (EBX[31:0])
QCV_XSAVE_SIZE_ALL            equ  20     ; Max XSAVE area size for all features (EBX[31:0])
QCV_INTEL_TSC_DENOM           equ  21     ; TSC/crystal ratio denominator (EAX[31:0])
QCV_INTEL_TSC_NUMER           equ  22     ; TSC/crystal ratio numerator (EBX[31:0])
QCV_INTEL_CRYSTAL_HZ          equ  23     ; Core crystal clock frequency in Hz (ECX[31:0])
QCV_INTEL_BASE_FREQ           equ  24     ; Base frequency in MHz (EAX[15:0])
QCV_INTEL_MAX_FREQ            equ  25     ; Maximum frequency in MHz (EBX[15:0])
QCV_INTEL_BUS_FREQ            equ  26     ; Bus/reference frequency in MHz (ECX[15:0])
QCV_AMD_EXT_APIC_ID           equ  27     ; Extended APIC ID (EAX[31:0])
QCV_AMD_COMPUTE_UNIT_ID       equ  28     ; Compute unit ID (EBX[7:0])
QCV_AMD_THREADS_PER_CU        equ  29     ; Threads per compute unit minus 1 (EBX[15:8])
QCV_AMD_NODE_ID               equ  30     ; Node ID (ECX[7:0])
QCV_AMD_NODES_PER_PKG         equ  31     ; Nodes per package minus 1 (ECX[10:8])
QCV_COUNT                     equ  32     ; Must equal highest index + 1

; QCS_xxx - struct query index constants
QCS_CPU_VERSION               equ   0     ; Processor version information - CPUID(1,0).EAX
QCS_CPU_INFO                  equ   1     ; Processor miscellaneous information - CPUID(1,0).EBX
QCS_AMD_VERSION               equ   2     ; AMD processor version - CPUID(80000001h,0).EAX (AMD only)
QCS_AMD_TOPOLOGY              equ   3     ; AMD processor topology - CPUID(8000001Eh,0) (AMD only)
QCS_XSAVE_INFO                equ   4     ; XSAVE state information - CPUID(0Dh,0/1)
QCS_ADDR_SIZES                equ   5     ; Physical/linear address sizes - CPUID(80000008h,0).EAX
QCS_INTEL_FREQ                equ   6     ; Processor frequency information - CPUID(16h,0) (Intel only)
QCS_INTEL_TSC                 equ   7     ; TSC / core crystal clock ratio - CPUID(15h,0) (Intel only)
QCS_COUNT                     equ   8     ; Must equal highest index + 1


; --------------------------------------------------------------------------------------------------
; CPU_VALUE - return value structure for QueryCpuValue
; --------------------------------------------------------------------------------------------------

CPU_VALUE struct
  union
    oVal  OWORD   ?                 ; full 128-bit access
    qVals QWORD   2 dup(?)          ; two 64-bit values
    dVals DWORD   4 dup(?)          ; four 32-bit values (primary use)
    wVals WORD    8 dup(?)          ; eight 16-bit values
    bVals BYTE   16 dup(?)          ; sixteen 8-bit values
  ends
CPU_VALUE ends


; --------------------------------------------------------------------------------------------------
; Returned struct types - one per QCS_xxx index
; --------------------------------------------------------------------------------------------------

QCSTRUCT_CPU_VERSION struct         ; Intel/AMD
  dStepping     DWORD  ?            ; Stepping ID          EAX[3:0]
  dModel        DWORD  ?            ; Model ID             EAX[7:4]
  dFamily       DWORD  ?            ; Family ID            EAX[11:8]
  dExtModel     DWORD  ?            ; Extended Model ID    EAX[19:16]
  dExtFamily    DWORD  ?            ; Extended Family ID   EAX[27:20]
QCSTRUCT_CPU_VERSION ends

QCSTRUCT_CPU_INFO struct
  dBrandIdx     DWORD  ?            ; Brand Index          EBX[7:0]
  dCLFlushSize  DWORD  ?            ; CLFLUSH size x8      EBX[15:8]
  dLogicalCount DWORD  ?            ; Max logical CPUs     EBX[23:16]
  dApicID       DWORD  ?            ; Initial APIC ID      EBX[31:24]
QCSTRUCT_CPU_INFO ends

QCSTRUCT_AMD_TOPOLOGY struct
  dExtApicID    DWORD  ?            ; Extended APIC ID     EAX[31:0]
  dCompUnitID   DWORD  ?            ; Compute unit ID      EBX[7:0]
  dThreadsPerCU DWORD  ?            ; Threads per CU - 1   EBX[15:8]
  dNodeID       DWORD  ?            ; Node ID              ECX[7:0]
  dNodesPerPkg  DWORD  ?            ; Nodes per pkg - 1    ECX[10:8]
QCSTRUCT_AMD_TOPOLOGY ends

QCSTRUCT_XSAVE_INFO struct
  dXCR0Lower    DWORD  ?            ; XCR0 bits 31:0       CPUID(Dh,0).EAX
  dXCR0Upper    DWORD  ?            ; XCR0 bits 63:32      CPUID(Dh,0).EDX
  dSizeOS       DWORD  ?            ; XSAVE size (OS)      CPUID(Dh,0).EBX
  dSizeAll      DWORD  ?            ; XSAVE size (all)     CPUID(Dh,1).EBX
QCSTRUCT_XSAVE_INFO ends

QCSTRUCT_ADDR_SIZES struct
  dPhysAddrBits DWORD  ?            ; Physical addr bits   EAX[7:0]
  dLinAddrBits  DWORD  ?            ; Linear addr bits     EAX[15:8]
QCSTRUCT_ADDR_SIZES ends

QCSTRUCT_INTEL_FREQ struct
  dBaseFreqMHz  DWORD  ?            ; Base frequency MHz   EAX[15:0]
  dMaxFreqMHz   DWORD  ?            ; Max frequency MHz    EBX[15:0]
  dBusFreqMHz   DWORD  ?            ; Bus frequency MHz    ECX[15:0]
QCSTRUCT_INTEL_FREQ ends

QCSTRUCT_INTEL_TSC struct
  dDenominator  DWORD  ?            ; TSC ratio denom      EAX[31:0]
  dNumerator    DWORD  ?            ; TSC ratio numer      EBX[31:0]
  dCrystalHz    DWORD  ?            ; Crystal freq Hz      ECX[31:0]
QCSTRUCT_INTEL_TSC ends


; Table-entry field constants
VF_ANY        equ 0
VF_INTEL      equ 1
VF_AMD        equ 2

RG_EAX        equ 0
RG_EBX        equ 1
RG_ECX        equ 2
RG_EDX        equ 3
