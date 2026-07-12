; ==================================================================================================
; Title:      QueryCpuStruct_PX.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, June 2026
;               - Initial release.
;               - Bitness-neutral and platform-independent code.
; ==================================================================================================


; --------------------------------------------------------------------------------------------------
; Procedure:  QueryCpuStruct
; Purpose:    Extract a set of related CPUID fields into a typed structure.
;             Each field is right-shifted and masked to 32 bits, stored in consecutive DWORD slots
;             of the caller-supplied struct.
; Arguments:  Arg1: QCS_xxx index (0-based, must be < QCS_COUNT).
;             Arg2: -> QCSTRUCT_xxx structure.
; Return:     eax = field count   All fields extracted and stored.
;             eax = 0             Failure: out of bounds, vendor mismatch, leaf unsupported.
; Note:       Requires QCS-Table_PX.inc to be included before this file.
;             CPUID is always available in 64-bit mode; no availability check needed.

.code
align ALIGN_CODE
QueryCpuStruct proc uses xbx xdi xsi, dStructIndex:DWORD, pReturnedStruct:POINTER
  local dMaxLeaf:DWORD                  ; Max basic CPUID leaf from CPUID(0)
  local dMaxExtLeaf:DWORD               ; Max extended CPUID leaf from CPUID(80000000h)
  local dVendorEBX:DWORD                ; Vendor string ebx from CPUID(0) - chars  0..3
  local dVendorEDX:DWORD                ; Vendor string edx from CPUID(0) - chars  4..7
  local dVendorECX:DWORD                ; Vendor string ecx from CPUID(0) - chars  8..11
  local dActualLeaf:DWORD               ; Effective leaf (QCS_ENTRY.bLeaf + EX offset if applicable)
  local dActualSubleaf:DWORD            ; Default subleaf from QCS_ENTRY.bSubleaf
  local dCpuidEAX:DWORD                 ; Last CPUID eax output
  local dCpuidEBX:DWORD                 ; Last CPUID ebx output
  local dCpuidECX:DWORD                 ; Last CPUID ecx output
  local dCpuidEDX:DWORD                 ; Last CPUID edx output
  local bLastSubleaf:BYTE               ; Subleaf used for the most recent CPUID call
  local dFieldCount:DWORD               ; Remaining fields to process
  local pStruct:POINTER                 ; Running output pointer into the caller-supplied struct
                                        ; kept as a local so CPUID re-issues cannot clobber it

  ; Verify CPUID is available (only in 32-bit mode)
if TARGET_BITNESS eq 32
  invoke QueryCpuidSupported
  test eax, eax
  jz @@Failure
endif

  ; Bounds check
  mov eax, dStructIndex
  cmp eax, QCS_COUNT
  jae @@Failure

  ; Load QCS_ENTRY pointer
  ; xsi = &QCS_TABLE[dStructIndex]
  lea xsi, QCS_TABLE
  imul eax, sizeof(QCS_ENTRY)
  add xsi, xax                                          ; xsi -> QCS_ENTRY for this index

  ; CPUID(0) - max basic leaf and vendor string
  xor eax, eax
  cpuid                                                 ; eax = max basic leaf
                                                        ; ebx = vendor chars  0..3  ("Genu"/"Auth")
                                                        ; edx = vendor chars  4..7  ("ineI"/"enti")
                                                        ; ecx = vendor chars  8..11 ("ntel"/"cAMD")
  mov dMaxLeaf,   eax
  mov dVendorEBX, ebx                                   ; "Genu" / "Auth"
  mov dVendorEDX, edx                                   ; "ineI" / "enti"
  mov dVendorECX, ecx                                   ; "ntel" / "cAMD"

  ; CPUID(80000000h) - max extended leaf
  ; ecx is ignored by this leaf; no need to zero it.
  mov eax, 80000000h
  cpuid                                                 ; eax = highest extended leaf supported
  mov dMaxExtLeaf, eax

  ; Vendor filter (QCS_ENTRY.bVendor)
  ;
  ;   VF_ANY   (0) => accept any vendor, skip all checks
  ;   VF_INTEL (1) => all three vendor DWORDs must match "GenuineIntel"
  ;   VF_AMD   (2) => all three vendor DWORDs must match "AuthenticAMD"
  ;   other        => unknown filter value, treat as failure
  ;
  ;   Full 3-DWORD comparison eliminates false positives from
  ;   hypothetical CPUs sharing only a partial vendor prefix.

  movzx ecx, [xsi].QCS_ENTRY.bVendor
  .if ecx == VF_INTEL
    .if dVendorEBX != "uneG" || dVendorEDX != "Ieni" || dVendorECX != "letn"  ;"GenuineIntel"
      jmp @@Failure
    .endif
  .elseif ecx == VF_AMD
    .if dVendorEBX != "htuA" || dVendorEDX != "itne" || dVendorECX != "DMAc"  ;"AuthenticAMD"
      jmp @@Failure
    .endif
  .elseif ecx != VF_ANY
    jmp @@Failure                                       ; Unknown QCS_ENTRY.bVendor value => FALSE
  .endif

  ; Build actual leaf and validate
  ;   QCS_ENTRY.bFlags bit QCS_FL_EX:
  ;     0 => basic leaf    (identity, 00000000h + QCS_ENTRY.bLeaf)
  ;     1 => extended leaf (offset,   80000000h + QCS_ENTRY.bLeaf)
  movzx eax, [xsi].QCS_ENTRY.bLeaf
  movzx ecx, [xsi].QCS_ENTRY.bFlags
  test ecx, QCS_FL_EX
  jz @@BasicLeaf

  ; Extended leaf: add 80000000h and validate against max extended leaf
  add eax, 80000000h
  cmp eax, dMaxExtLeaf
  ja @@Failure
  jmp @@LeafOK

@@BasicLeaf:
  ; Basic leaf: validate against max basic leaf
  cmp eax, dMaxLeaf
  ja @@Failure

@@LeafOK:
  ; Save effective leaf and default subleaf before any further CPUID calls
  mov dActualLeaf, eax
  movzx ecx, [xsi].QCS_ENTRY.bSubleaf
  mov dActualSubleaf, ecx

  ; Initialise running output pointer
  ; pStruct is a stack local so it survives all CPUID calls in the loop.
  mov xax, pReturnedStruct
  mov pStruct, xax

  ; Execute initial CPUID(dActualLeaf, dActualSubleaf)
  mov eax, dActualLeaf
  mov ecx, dActualSubleaf
  mov bLastSubleaf, cl
  cpuid                                                 ; Clobbers ebx - persist outputs immediately
  mov dCpuidEAX, eax
  mov dCpuidEBX, ebx
  mov dCpuidECX, ecx
  mov dCpuidEDX, edx

  ; Step 10: Set up field loop
  ;   xdi -> first QCS_FIELD_ENTRY  (advances by sizeof(QCS_FIELD_ENTRY) each iteration)
  ;   dFieldCount = QCS_ENTRY.bFieldCount (countdown to zero)
  movzx eax, [xsi].QCS_ENTRY.bFieldCount
  test eax, eax
  jz @@Failure
  mov dFieldCount, eax

  movzx eax, [xsi].QCS_ENTRY.wFieldIndex
  imul eax, sizeof(QCS_FIELD_ENTRY)
  lea xdi, QCS_FIELD_TABLE
  add xdi, xax                                          ; xdi -> first QCS_FIELD_ENTRY

  ; Field extraction loop
@@FieldLoop:
  ; Subleaf override (QCS_FIELD_ENTRY.bSlOverride)
  ; QCS_FIELD_ENTRY.bSlOverride = 0 => use default subleaf from QCS_ENTRY.bSubleaf (no re-issue)
  ; QCS_FIELD_ENTRY.bSlOverride != 0 and differs from bLastSubleaf => re-issue CPUID
  movzx ecx, [xdi].QCS_FIELD_ENTRY.bSlOverride
  .if ecx != 0
    .if cl != bLastSubleaf
      mov bLastSubleaf, cl                              ; cl already holds the new subleaf
      mov eax, dActualLeaf
      cpuid ; re-issue CPUID with updated QCS_FIELD_ENTRY.bSlOverride
      mov dCpuidEAX, eax                                ; Clobbers ebx - persist outputs immediately
      mov dCpuidEBX, ebx
      mov dCpuidECX, ecx                                ; ecx = CPUID ecx output
      mov dCpuidEDX, edx
    .endif
  .endif

  ; Select source register by QCS_FIELD_ENTRY.bReg
  movzx ecx, [xdi].QCS_FIELD_ENTRY.bReg
  cmp ecx, RG_EDX
  ja @@Failure                                          ; QCS_FIELD_ENTRY.bReg > 3 => table error

  je @@UseEdx
  cmp ecx, RG_ECX
  je @@UseEcx
  cmp ecx, RG_EBX
  je @@UseEbx

  mov edx, dCpuidEAX                                    ; RG_EAX (0)
  jmp @@Shift

@@UseEbx:
  mov edx, dCpuidEBX
  jmp @@Shift

@@UseEcx:
  mov edx, dCpuidECX
  jmp @@Shift

@@UseEdx:
  mov edx, dCpuidEDX

@@Shift:
  ; Right-shift by QCS_FIELD_ENTRY.bBitPos
  movzx ecx, [xdi].QCS_FIELD_ENTRY.bBitPos
  shr edx, cl

  ; Mask to QCS_FIELD_ENTRY.bBitWidth bits
  movzx ecx, [xdi].QCS_FIELD_ENTRY.bBitWidth
  .if ecx < 32
    mov eax, 1
    shl eax, cl
    dec eax                                             ; Mask = (1 << QCS_FIELD_ENTRY.bBitWidth) - 1
    and edx, eax
  .endif

  ; Store into output struct and advance pointer
  mov xax, pStruct
  mov DWORD ptr [xax], edx
  add xax, sizeof(DWORD)                                ; Move to next structure member
  mov pStruct, xax                                      ; Keep pStruct in sync so next cpuid reload is correct

  ; Advance to next QCS_FIELD_ENTRY
  add xdi, sizeof(QCS_FIELD_ENTRY)
  dec dFieldCount
  jnz @@FieldLoop

  ; Return field count
  movzx eax, [xsi].QCS_ENTRY.bFieldCount
  ret

@@Failure:
  xor eax, eax
  ret
QueryCpuStruct endp
