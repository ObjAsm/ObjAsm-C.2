; ==================================================================================================
; Title:      QueryCpuValue_PX.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, June 2026
;               - Initial release.
;               - Bitness-neutral and platform-independent code.
; ==================================================================================================


; --------------------------------------------------------------------------------------------------
; Procedure:  QueryCpuValue
; Purpose:    Return a numeric value extracted from a CPUID register field.
;             The value is right-shifted and masked to 32 bits and stored in
;             pReturnedValue -> dVals[0].
; Arguments:  Arg1: QCV_xxx index (0-based, must be < QCV_COUNT).
;             Arg2: -> CPU_VALUE structure to receive the result.
; Return:     eax = 1  Value successfully extracted and stored.
;             eax = 0  Failure: index out of bounds, vendor mismatch, or leaf unsupported.
; Note:       Requires QCV-Table_PX.inc to be included before this file.
;             CPUID is always available in 64-bit mode; no availability check needed.

.code
align ALIGN_CODE
QueryCpuValue proc uses xbx xsi dValueIndex:DWORD, pReturnedValue:POINTER
  local dMaxLeaf:DWORD
  local dVendorEBX:DWORD, dVendorECX:DWORD, dVendorEDX:DWORD
  local pEntry:POINTER                  ; Cached table entry pointer
  local dSavedEBX:DWORD                 ; ebx save slot across CPUID calls
  local dSavedLeaf:DWORD                ; Leaf save slot
  local dSavedSubleaf:DWORD             ; Subleaf save slot
  local dCpuEAX:DWORD                   ; CPUID output capture: eax
  local dCpuEBX:DWORD                   ; CPUID output capture: ebx
  local dCpuECX:DWORD                   ; CPUID output capture: ecx
  local dCpuEDX:DWORD                   ; CPUID output capture: edx

  ; Verify CPUID is available (only in 32-bit mode)
if TARGET_BITNESS eq 32
  invoke QueryCpuidSupported
  test eax, eax
  jz @Failure
endif

  ; Bounds check
  mov eax, dValueIndex
  cmp eax, QCV_COUNT
  jae @Failure

  ; Load table entry pointer (base + index * sizeof(QCV_ENTRY))
  lea xsi, QCV_TABLE
  shl eax, 3                            ; * sizeof(QCV_ENTRY) = 8
  add xsi, xax                          ; xsi -> QCV_ENTRY for this index
  mov pEntry, xsi                       ; Cache pointer in local

  ; CPUID(0) - get max basic leaf and vendor string
  xor eax, eax
  xor ecx, ecx
  mov dSavedEBX, ebx
  cpuid
  mov dMaxLeaf,   eax                   ; Capture all CPUID outputs before restoring EBX
  mov dVendorEBX, ebx
  mov dVendorECX, ecx
  mov dVendorEDX, edx
  mov ebx, dSavedEBX                    ; Restore caller EBX last

  ; Vendor filter  (QCF_ENTRY.bVendor)
  ;
  ;   VF_ANY   (0) => accept any vendor, skip all checks
  ;   VF_INTEL (1) => all three vendor DWORDs must match "GenuineIntel"
  ;   VF_AMD   (2) => all three vendor DWORDs must match "AuthenticAMD"
  ;   other        => unknown filter value, treat as failure
  ;
  ;   Full 3-DWORD comparison eliminates false positives from
  ;   hypothetical CPUs sharing only a partial vendor prefix.

  mov xsi, pEntry
  movzx ecx, [xsi].QCV_ENTRY.bVendor
  .if ecx != VF_ANY
    .if ecx == VF_INTEL
      .if dVendorEBX != "uneG" || dVendorEDX != "Ieni" || dVendorECX != "letn"   ;"GenuineIntel"
        jmp @Failure
      .endif
    .elseif ecx == VF_AMD
      .if dVendorEBX != "htuA" || dVendorEDX != "itne" || dVendorECX != "DMAc"   ;"AuthenticAMD"
        jmp @Failure
      .endif
    .else
      jmp @Failure                      ; Unknown vendor code
    .endif
  .endif

  ; Build actual leaf address
  movzx eax, [xsi].QCV_ENTRY.bLeaf
  movzx ecx, [xsi].QCV_ENTRY.bFlags
  test ecx, QCV_FL_EX
  jz @BasicLeaf
  add eax, 80000000h                    ; Extended leaf

  ; Validate extended leaf
  mov dSavedLeaf, eax                   ; Save requested extended leaf
  mov eax, 80000000h
  xor ecx, ecx
  mov dSavedEBX, ebx
  cpuid
  mov ecx, eax                          ; Max extended leaf returned in EAX
  mov ebx, dSavedEBX
  mov eax, dSavedLeaf                   ; Restore requested leaf
  cmp eax, ecx
  ja @Failure
  jmp @LeafOK

@BasicLeaf:
  ; Validate basic leaf
  cmp eax, dMaxLeaf
  ja @Failure

  ; Special case: leaf 7, subleaf > 0 => validate against CPUID(7,0).EAX max subleaf
  .if eax == 7
    mov xsi, pEntry
    movzx ecx, [xsi].QCV_ENTRY.bSubleaf
    .if ecx > 0
      mov dSavedLeaf,    eax            ; Save leaf (7)
      mov dSavedSubleaf, ecx            ; Save requested subleaf
      xor ecx, ecx                      
      mov eax, 7                        
      mov dSavedEBX, ebx                
      cpuid                             
      mov ecx, eax                      ; Max subleaf for leaf 7 in EAX
      mov ebx, dSavedEBX                
      mov eax, dSavedSubleaf            ; Requested subleaf
      cmp eax, ecx                      
      ja @Failure                       
      mov eax, dSavedLeaf               ; Restore leaf (7) for Step 8
    .endif
  .endif

@LeafOK:
  ; Execute CPUID(leaf, subleaf)
  ; Capture all four outputs into locals before any register is reused,
  ; so bReg selection does not overwrite the ECX result.
  mov xsi, pEntry
  movzx ecx, [xsi].QCV_ENTRY.bSubleaf
  mov dSavedEBX, ebx
  cpuid
  mov dCpuEAX, eax
  mov dCpuEBX, ebx
  mov dCpuECX, ecx
  mov dCpuEDX, edx
  mov ebx, dSavedEBX                    ; Restore caller ebx

  ; Select result register by bReg
  movzx ecx, [xsi].QCV_ENTRY.bReg
  .if ecx == RG_EAX
    mov edx, dCpuEAX
  .elseif ecx == RG_EBX
    mov edx, dCpuEBX
  .elseif ecx == RG_ECX
    mov edx, dCpuECX
  .else                                 ; RG_EDX
    mov edx, dCpuEDX
  .endif

  ; Extract field (right-shift and mask)
  movzx ecx, [xsi].QCV_ENTRY.bBitPos
  shr edx, cl                           ; Right-shift
  movzx ecx, [xsi].QCV_ENTRY.bBitWidth
  .if ecx < 32
    mov eax, 1
    shl eax, cl
    dec eax                             ; Mask = (1 << width) - 1
    and edx, eax
  .endif
  ; edx = extracted value

  ; Store result and return 1
  mov xax, pReturnedValue
  mov DWORD ptr [xax], edx              ; -> dVals[0]
  mov eax, 1
  ret

@Failure:
  xor eax, eax
  ret
QueryCpuValue endp
