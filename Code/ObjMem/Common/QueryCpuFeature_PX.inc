;==================================================================================================
; Title:      QueryCpuFeature_PX.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, June 2026
;               - Initial release, replacing IsHardwareFeaturePresent.
;               - Bitness-neutral and platform-independent code.
;               - Procedure is Table-driven.
;==================================================================================================


; --------------------------------------------------------------------------------------------------
; Procedure:  QueryCpuFeature
; Purpose:    Determine whether a specific CPU hardware feature is present and usable on the
;             current system. The procedure is fully table-driven, consulting the QCF_TABLE
;             descriptor array indexed by the supplied QCF_xxx constant. Each QCF_ENTRY
;             encodes the CPUID leaf, subleaf, output register, bit position, vendor filter,
;             OS-managed state (XCR0) requirement and optional flags needed to probe one feature.
;             On 64-bit targets CPUID is architecturally guaranteed; step 1 is omitted and
;             TRUE is the unconditional result of the availability check.
; Arguments:  Arg1: QCF_xxx index constant (0 .. QCF_COUNT-1) identifying the feature to probe.
; Return:     eax = TRUE (1)  if the feature is present and usable.
;             eax = FALSE (0) if any validation step fails, the index is out of range, or the
;             CPUID instruction is unavailable (32-bit targets only).
; Note:       Requires QCF_Table_PX.inc to be included before this file.

.code
align ALIGN_CODE
QueryCpuFeature proc uses xbx xsi xdi, wFeatureIndex:WORD
  local dMaxLeaf:DWORD                  ; Max basic CPUID leaf from CPUID(0)
  local dMaxExtLeaf:DWORD               ; Max extended CPUID leaf from CPUID(80000000h)
  local dVendorEBX:DWORD                ; Vendor string ebx from CPUID(0) - chars  0..3
  local dVendorEDX:DWORD                ; Vendor string edx from CPUID(0) - chars  4..7
  local dVendorECX:DWORD                ; Vendor string ecx from CPUID(0) - chars  8..11
  local dActualLeaf:DWORD               ; Effective leaf (QCF_ENTRY.bLeaf + 80000000h if QCF_FL_EX set)
  local dCpuidEAX:DWORD                 ; Last CPUID eax output
  local dCpuidEBX:DWORD                 ; Last CPUID ebx output
  local dCpuidECX:DWORD                 ; Last CPUID ecx output
  local dCpuidEDX:DWORD                 ; Last CPUID edx output
  local dSavedBReg:DWORD                ; Preserves cached QCF_ENTRY.bReg across CPUID calls
  local dSavedSubleaf:DWORD             ; Preserves QCF_ENTRY.bSubleaf across CPUID(7,0) / CPUID(0Dh,0)

 ; ------ Step 1: Verify CPUID is available (32-bit only) ------
if TARGET_BITNESS eq 32
   invoke QueryCpuidSupported
   test eax, eax
   jz @@Failure
endif

  ; ------ Step 2: Bounds check -- feature index must be valid ------
  movzx eax, wFeatureIndex
  cmp eax, QCF_COUNT
  jae @@Failure                         ; Out of range => FALSE
 
  ; ------ Step 3: Load descriptor table entry ------
  ;   xsi = &QCF_TABLE[wFeatureIndex]
  lea xsi, QCF_TABLE
  imul eax, eax, sizeof QCF_ENTRY       ; eax = byte offset into table
  add xsi, xax                          ; xsi = pointer to target QCF_ENTRY
 
  ; Cache QCF_ENTRY.bBit into xdi; it is never clobbered by CPUID so no push/pop needed.
  movzx edi, [xsi].QCF_ENTRY.bBit      ; edi = QCF_ENTRY.bBit (target bit position, 0-31)
 
  ; ------ Step 4: CPUID(0) => max basic leaf + full 12-byte vendor string ------
  ; QCF_ENTRY.bReg is cached after this call because CPUID(0) clobbers ebx.
  xor eax, eax
  cpuid                                 ; eax = max basic leaf
                                        ; ebx = vendor chars  0..3  ("Genu"/"Auth")
                                        ; edx = vendor chars  4..7  ("ineI"/"enti")
                                        ; ecx = vendor chars  8..11 ("ntel"/"cAMD")
  mov dMaxLeaf,   eax
  mov dVendorEBX, ebx                   ; "Genu" / "Auth"
  mov dVendorEDX, edx                   ; "ineI" / "enti"
  mov dVendorECX, ecx                   ; "ntel" / "cAMD"
 
  ; Cache QCF_ENTRY.bReg now that CPUID(0) has finished writing ebx.
  movzx ebx, [xsi].QCF_ENTRY.bReg      ; ebx = QCF_ENTRY.bReg (output register index, 0-3)
 
  ; ------ Step 5: Vendor filter  (QCF_ENTRY.bVendor) ------
  ;
  ;   VF_ANY   (0) => accept any vendor, skip all checks
  ;   VF_INTEL (1) => all three vendor DWORDs must match "GenuineIntel"
  ;   VF_AMD   (2) => all three vendor DWORDs must match "AuthenticAMD"
  ;   other        => unknown filter value, treat as failure
  ;
  ;   Full 3-DWORD comparison eliminates false positives from
  ;   hypothetical CPUs sharing only a partial vendor prefix.
  ;
  movzx ecx, [xsi].QCF_ENTRY.bVendor
 
  .if ecx == VF_INTEL
    .if dVendorEBX != "uneG" || dVendorEDX != "Ieni" || dVendorECX != "letn"   ;"GenuineIntel"
      jmp @@Failure
    .endif
  .elseif ecx == VF_AMD
    .if dVendorEBX != "htuA" || dVendorEDX != "itne" || dVendorECX != "DMAc"   ;"AuthenticAMD"
      jmp @@Failure
    .endif
  .elseif ecx != VF_ANY
    jmp @@Failure                       ; Unknown QCF_ENTRY.bVendor value => FALSE
  .endif
 
  ; ------ Step 6: Intel-reserved bit check  (QCF_ENTRY.bFlags bit 1 = QCF_FL_IRSV) ------
  ;   If this feature is marked Intel-reserved and we are on Intel => FALSE.
  ;   The partial ebx-only check ("Genu") is intentional: no other vendor
  ;   shares that prefix, and VF_INTEL already did a full 3-DWORD check above.
  movzx eax, [xsi].QCF_ENTRY.bFlags
  bt eax, 1                             ; Test QCF_FL_IRSV; CF = 1 when bit is set
  jnc @@SkipIRSV                        ; CF = 0 => not Intel-reserved, skip
 
  .if dVendorEBX == "uneG"              ; Running on Intel?
    jmp @@Failure                       ; QCF_FL_IRSV set => always FALSE on Intel
  .endif
 
@@SkipIRSV:
  ; ------ Step 7: XCR0 / OSXSAVE validation  (QCF_ENTRY.bXCR0) ------
  ;
  ;   XCRLVL_NONE   (0) => no XGETBV check required
  ;   XCRLVL_AVX    (1) => XCR0 AND 006h    must equal 006h    (XMM + YMM)
  ;   XCRLVL_AVX512 (2) => XCR0 AND 0E6h    must equal 0E6h    (XMM+YMM+Opmask+ZMM)
  ;   XCRLVL_AMX    (3) => XCR0 AND 060000h must equal 060000h (XTILECFG+XTILEDATA)
  ;
  ;   IMPORTANT: The CPUID(1,0) call used to test OSXSAVE writes ebx, which holds
  ;   the cached QCF_ENTRY.bReg value. dSavedBReg is used to preserve it across
  ;   that call instead of push/pop, keeping rsp stable throughout the procedure.
  ;
  movzx eax, [xsi].QCF_ENTRY.bXCR0
  test eax, eax
  jz @@SkipXcr                          ; XCRLVL_NONE => no check needed
 
  ; OSXSAVE (CPUID(1).ECX bit 27) must be set before XGETBV is legal.
  mov dSavedBReg, ebx                   ; Save cached QCF_ENTRY.bReg before CPUID clobbers ebx
  mov eax, 1
  xor ecx, ecx
  cpuid                                 ; ecx = CPUID(1,0).ECX feature flags
  mov ebx, dSavedBReg                   ; Restore cached QCF_ENTRY.bReg
 
  bt ecx, 27                            ; Test OSXSAVE bit
  jnc @@Failure                         ; OSXSAVE absent => XGETBV is illegal
 
  xor ecx, ecx
  xgetbv                                ; ecx = 0 => eax::edx = XCR0
 
  mov ecx, eax                          ; ecx = XCR0 low DWORD
 
  ; Re-read QCF_ENTRY.bXCR0 from the table entry; eax is now free.
  movzx eax, [xsi].QCF_ENTRY.bXCR0
 
  cmp eax, XCRLVL_AMX
  je @@XcrAMX
  cmp eax, XCRLVL_AVX512
  je @@XcrAVX512
 
  ; ---- AVX: XMM state (bit 1) + YMM state (bit 2) must both be set ----
  and ecx, 006h
  cmp ecx, 006h
  jne @@Failure
  jmp @@SkipXcr
 
@@XcrAVX512:
  ; ---- AVX-512: XMM+YMM+Opmask (5)+Hi256 (6)+ZMM (7) ----
  and ecx, 0E6h
  cmp ecx, 0E6h
  jne @@Failure
  jmp @@SkipXcr
 
@@XcrAMX:
  ; ---- AMX: XTILECFG (bit 17) + XTILEDATA (bit 18) ----
  and ecx, 060000h
  cmp ecx, 060000h
  jne @@Failure
 
@@SkipXcr:
  ; ------ Step 8: Resolve effective CPUID leaf ------
  ;   QCF_ENTRY.bFlags bit 0 (QCF_FL_EX):
  ;     0 => basic leaf    (identity, 00000000h + QCF_ENTRY.bLeaf)
  ;     1 => extended leaf (offset,   80000000h + QCF_ENTRY.bLeaf)
  movzx eax, [xsi].QCF_ENTRY.bLeaf
  movzx ecx, [xsi].QCF_ENTRY.bFlags
 
  bt ecx, 0                             ; Test QCF_FL_EX
  jnc @@BasicLeaf
 
  ; ---- Extended leaf: validate against CPUID(80000000h).EAX ----
  or eax, 80000000h
  mov dActualLeaf, eax
 
  mov dSavedBReg, ebx                   ; Save cached QCF_ENTRY.bReg before CPUID clobbers ebx
  mov eax, 80000000h
  cpuid                                 ; eax = highest extended leaf supported
  mov ebx, dSavedBReg                   ; Restore cached QCF_ENTRY.bReg
  mov dMaxExtLeaf, eax
 
  cmp eax, dActualLeaf
  jb @@Failure                          ; Requested leaf beyond CPU's extended range
  jmp @@ValidateSubleaf
 
@@BasicLeaf:
  ; ---- Basic leaf: validate against CPUID(0).EAX ----
  mov dActualLeaf, eax
 
  cmp dMaxLeaf, eax
  jb @@Failure                          ; Requested leaf beyond CPU's basic range
 
@@ValidateSubleaf:
  ; ---- Leaf 7 subleaf validation (CPUID(7,0).EAX = max subleaf for leaf 7) ----
  ;   Only non-zero subleaves need validation; subleaf 0 always exists.
  cmp dActualLeaf, 7
  je @@CheckLeaf7Subleaf
 
  ; ---- Leaf 0Dh subleaf validation ----
  ;   CPUID(0Dh,0).EAX enumerates supported XSAVE components. Subleaf 1
  ;   (used by QCF_XSAVEOPT/XSAVEC/XGETBV_ECX1/XSAVES) is only valid when
  ;   the CPU reports it. We conservatively require max-subleaf >= 1.
  cmp dActualLeaf, 0Dh
  je @@CheckLeafDhSubleaf
 
  jmp @@DoCpuid
 
@@CheckLeaf7Subleaf:
  movzx ecx, [xsi].QCF_ENTRY.bSubleaf
  test ecx, ecx
  jz @@DoCpuid                          ; QCF_ENTRY.bSubleaf = 0 always present; skip check
 
  mov dSavedBReg,    ebx                ; Save cached QCF_ENTRY.bReg before CPUID clobbers ebx
  mov dSavedSubleaf, ecx                ; Save requested QCF_ENTRY.bSubleaf across CPUID
  mov eax, 7
  xor ecx, ecx
  cpuid                                 ; eax = max supported subleaf for leaf 7
  mov ecx, dSavedSubleaf                ; Restore requested QCF_ENTRY.bSubleaf
  mov ebx, dSavedBReg                   ; Restore cached QCF_ENTRY.bReg
  cmp eax, ecx
  jb @@Failure                          ; Requested QCF_ENTRY.bSubleaf unsupported
  jmp @@DoCpuid
 
@@CheckLeafDhSubleaf:
  movzx ecx, [xsi].QCF_ENTRY.bSubleaf
  test ecx, ecx
  jz @@DoCpuid                          ; QCF_ENTRY.bSubleaf = 0 always present; skip check
 
  mov dSavedBReg,    ebx                ; Save cached QCF_ENTRY.bReg before CPUID clobbers ebx
  mov dSavedSubleaf, ecx                ; Save requested QCF_ENTRY.bSubleaf across CPUID
  mov eax, 0Dh
  xor ecx, ecx
  cpuid                                 ; eax = CPUID(0Dh,0).EAX = XSAVE component bitmap
                                        ; For leaf 0Dh, subleaf 1 is always present
                                        ; when the leaf itself is supported (max basic
                                        ; leaf >= 0Dh, already verified in @@BasicLeaf).
                                        ; A CPU that enumerates leaf 0Dh must implement
                                        ; subleaf 1 per Intel/AMD SDM. We check eax != 0
                                        ; as a minimal sanity guard (eax = 0 means no XSAVE
                                        ; state components are enabled by the OS).
  mov ecx, dSavedSubleaf                ; Restore requested QCF_ENTRY.bSubleaf
  mov ebx, dSavedBReg                   ; Restore cached QCF_ENTRY.bReg
  test eax, eax
  jz @@Failure                          ; No XSAVE state components => subleaf 1 useless
 
@@DoCpuid:
  ; ------ Step 9: Execute CPUID(leaf, subleaf) and persist all four outputs ------
  ; dSavedBReg is used to preserve cached QCF_ENTRY.bReg across the final CPUID call;
  ; rsp is not touched.
  mov eax, dActualLeaf
  movzx ecx, [xsi].QCF_ENTRY.bSubleaf
 
  mov dSavedBReg, ebx                   ; Preserve cached QCF_ENTRY.bReg across final CPUID call
  cpuid
  mov dCpuidEAX, eax                    ; Persist all outputs before any register is reused
  mov dCpuidEBX, ebx
  mov dCpuidECX, ecx
  mov dCpuidEDX, edx
  mov ebx, dSavedBReg                   ; Restore cached QCF_ENTRY.bReg (index 0-3)
 
  ; ------ Step 10: Select output register by QCF_ENTRY.bReg ------
  ;   ebx = cached QCF_ENTRY.bReg index (0-3).
  ;   Guard: QCF_ENTRY.bReg > 3 is a table error; fail cleanly.
  ;   32-bit ebx compare is sufficient: QCF_ENTRY.bReg is a zero-extended BYTE
  ;   so the upper bits of xbx are always 0.
  cmp ebx, RG_EDX
  ja @@Failure                          ; QCF_ENTRY.bReg > 3 => invalid, return FALSE
 
  je @@UseEdx
  cmp ebx, RG_ECX
  je @@UseEcx
  cmp ebx, RG_EBX
  je @@UseEbx
 
  mov edx, dCpuidEAX                    ; RG_EAX (0)
  jmp @@Exam
 
@@UseEbx:
  mov edx, dCpuidEBX
  jmp @@Exam
 
@@UseEcx:
  mov edx, dCpuidECX
  jmp @@Exam
 
@@UseEdx:
  mov edx, dCpuidEDX
 
@@Exam:
  ; ------ Step 11: Extract target bit  (edi = cached QCF_ENTRY.bBit position, 0-31) ------
  ;   Use ecx for the shift count; CL is the only part read by SHR.
  ;   The 32-bit edi form is sufficient since QCF_ENTRY.bBit is always 0-31.
  mov ecx, edi                          ; ecx = QCF_ENTRY.bBit position for SHR
  shr edx, cl                           ; Shift target bit to position 0
  and edx, 1                            ; Isolate the single result bit
  mov eax, edx                          ; eax = TRUE (1) or FALSE (0)
  ret
 
align ALIGN_CODE
@@Failure:
  xor eax, eax                          ; eax = FALSE (0)
  ret
QueryCpuFeature endp
