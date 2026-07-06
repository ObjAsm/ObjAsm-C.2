; ==================================================================================================
; Title:      IsCpuFeaturePresent64.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, May 2026
;               - Initial release, replaceing IsHardwareFeaturePresent.
;               - Procedure is Table-driven.
;               - ICFP_xxx constants are plain WORD indices (0, 1, 2, ...).
;               - New features require only one table row + one EQU constant.
;               - All CPUID addressing (Leaf/Subleaf/Reg/Bit/Vendor/XCR0)
;                 placed into a read-only descriptor table (ICFP_TABLE).
; ==================================================================================================


;% include @Environ(OBJASM_PATH)\Code\OA_Setup64.inc
;% include &ObjMemPath&ObjMemWin.cop

include ICFP-Table_X.inc

; --------------------------------------------------------------------------------------------------
; Procedure:  IsCpuFeaturePresent
; Purpose:    Check if a CPU hardware feature is present and usable on this system.
; Arguments:  Arg1: wFeature - ICFP_xxx index constant (0 .. ICFP_COUNT-1)
; Return:     EAX = TRUE (1) or FALSE (0)

OPTION PROC:NONE

.code
align ALIGN_CODE
IsCpuFeaturePresent proc wFeatureIndex:WORD

  ; ====================================================================
  ; Step 1: Verify CPUID is available (RFLAGS.ID = bit 21)
  ; ====================================================================
  pushfq
  pop   rax
  mov   r9,  rax                    ; Save original RFLAGS (R9 volatile)
  xor   eax, 000200000h             ; Toggle ID bit
  push  rax
  popfq                             ; Write modified RFLAGS
  pushfq
  pop   rax                         ; Read back
  push  r9
  popfq                             ; Restore original RFLAGS
  cmp   eax, r9d                    ; Did bit 21 change?
  jne   @F
  xor   eax, eax                    ; No => CPUID not available => FALSE
  ret

align ALIGN_CODE
@@:
  ; ====================================================================
  ; Step 2: Prologue - save callee-saved registers
  ; ====================================================================
  push  rbx
  push  rsi
  push  rdi
  push  r12
  push  r13
  push  r14
  push  r15

  ; ====================================================================
  ; Step 3: Bounds check - wFeature must be < ICFP_COUNT
  ; ====================================================================
  movzx eax, cx                     ; Zero-extend index to EAX
  cmp   eax, ICFP_COUNT
  jae   @@ReturnFalse               ; Out of range => FALSE

  ; ====================================================================
  ; Step 4: Load table entry pointer
  ;   Entry size = 8 bytes => offset = index * 8 = index SHL 3
  ; ====================================================================
  lea   r12, ICFP_TABLE             ; R12 = table base
  shl   eax, 3                      ; EAX = index * 8
  add   r12, rax                    ; R12 = pointer to entry

  ; R12 layout:
  ;   [R12+0] bLeaf     [R12+1] bSubleaf
  ;   [R12+2] bReg      [R12+3] bBit
  ;   [R12+4] bVendor   [R12+5] bXCR0
  ;   [R12+6] bFlags    [R12+7] bPad

  movzx r13d, BYTE PTR [r12+3]      ; R13B = bBit
  movzx r14d, BYTE PTR [r12+2]      ; R14B = bReg

  ; ====================================================================
  ; Step 5: CPUID(0) => max basic leaf + vendor string
  ; ====================================================================
  xor   eax, eax
  cpuid                             ; EAX=max basic, EBX/ECX/EDX=vendor
  mov   esi, eax                    ; RSI = max basic leaf
  mov   edi, ebx                    ; RDI = vendor EBX ("uneG" / "htuA")

  ; ====================================================================
  ; Step 6: Vendor filter check (bVendor at [R12+4])
  ;
  ;   VF_ANY   (0) => skip
  ;   VF_INTEL (1) => EBX must be "uneG" (first DWORD of "GenuineIntel")
  ;   VF_AMD   (2) => EBX must be "htuA" (first DWORD of "AuthenticAMD")
  ; ====================================================================
  movzx eax, BYTE PTR [r12+4]       ; EAX = bVendor
  test  eax, eax
  jz    @@SkipVendor                ; VF_ANY => skip

  cmp   eax, VF_INTEL
  je    @@CheckIntel
                                    ; VF_AMD
  cmp   edi, "htuA"                 ; "Auth" from "AuthenticAMD"
  jne   @@ReturnFalse
  jmp   @@SkipVendor

@@CheckIntel:
  cmp   edi, "uneG"                 ; "Genu" from "GenuineIntel"
  jne   @@ReturnFalse

@@SkipVendor:
  ; ====================================================================
  ; Step 7: Intel-reserved check (bFlags bit 1 = ICFP_FL_IRSV)
  ;   If set AND we are on Intel => always FALSE
  ; ====================================================================
  movzx eax, BYTE PTR [r12+6]       ; EAX = bFlags
  bt    eax, 1                      ; Test ICFP_FL_IRSV (bit 1)
  jnc   @@SkipIRSV                  ; Not reserved => continue
  cmp   edi, "uneG"                 ; Are we on Intel
  je    @@ReturnFalse               ; Yes => reserved bit => FALSE

@@SkipIRSV:
  ; ====================================================================
  ; Step 8: OSXSAVE + XGETBV check (bXCR0 at [R12+5])
  ;
  ;   XCRLVL_NONE   (0) => skip
  ;   XCRLVL_AVX    (1) => XCR0 AND 006h    = 006h  (XMM + YMM)
  ;   XCRLVL_AVX512 (2) => XCR0 AND 0E6h   = 0E6h  (XMM+YMM+Opmask+ZMM)
  ;   XCRLVL_AMX    (3) => XCR0 AND 060000h = 060000h (XTILECFG+XTILEDATA)
  ; ====================================================================
  movzx eax, BYTE PTR [r12+5]       ; EAX = bXCR0
  test  eax, eax
  jz    @@SkipXcr                   ; Level 0 => no XGETBV check

  ; OSXSAVE required before XGETBV (otherwise #UD exception)
  push  rax                         ; Save XCR0 level across CPUID
  mov   eax, 1
  xor   ecx, ecx
  cpuid                             ; ECX = CPUID(1).ECX feature flags
  pop   rax                         ; Restore XCR0 level
  bt    ecx, 27                     ; CPUID(1).ECX[27] = OSXSAVE
  jnc   @@ReturnFalse               ; OS has not enabled XSAVE => FALSE

  xor   ecx, ecx
  xgetbv                            ; EAX = XCR0[31:0], EDX = XCR0[63:32]
  mov   r9d, eax                    ; R9D = XCR0 low dword (volatile, no save)

  ; Re-read level since we used EAX for XGETBV result
  movzx ecx, BYTE PTR [r12+5]       ; ECX = bXCR0 again
  cmp   ecx, XCRLVL_AMX
  je    @@XcrAMX
  cmp   ecx, XCRLVL_AVX512
  je    @@XcrAVX512

  and   r9d, 006h                   ; AVX: bits 1 (XMM) + 2 (YMM)
  cmp   r9d, 006h
  jne   @@ReturnFalse
  jmp   @@SkipXcr

@@XcrAVX512:
  and   r9d, 0E6h                   ; Bits 1,2,5,6,7
  cmp   r9d, 0E6h
  jne   @@ReturnFalse
  jmp   @@SkipXcr

@@XcrAMX:
  and   r9d, 060000h                ; Bits 17 (XTILECFG) + 18 (XTILEDATA)
  cmp   r9d, 060000h
  jne   @@ReturnFalse

@@SkipXcr:
  ; ====================================================================
  ; Step 9: Build actual CPUID leaf address
  ;   bFlags bit 0 (ICFP_FL_EX): if set => leaf = 0x80000000 + bLeaf
  ; ====================================================================
  movzx r15d, BYTE PTR [r12]        ; R15D = bLeaf (raw)
  movzx eax,  BYTE PTR [r12+6]      ; EAX  = bFlags
  bt    eax, 0                      ; Test ICFP_FL_EX (bit 0)
  jnc   @@BasicLeaf
  or    r15d, 80000000h             ; => extended leaf address

  ; -- Extended leaf: verify via CPUID(80000000h) ----------------------
  mov   eax, 80000000h
  cpuid                             ; EAX = max supported extended leaf
  cmp   eax, r15d
  jb    @@ReturnFalse               ; Not supported => FALSE
  jmp   @@DoCpuid

@@BasicLeaf:
  ; -- Basic leaf: verify max basic leaf >= requested -------------------
  cmp   esi, r15d                   ; max basic leaf (cached in RSI) >= bLeaf
  jb    @@ReturnFalse               ; Not supported => FALSE

  ; -- Leaf 7: additional subleaf availability check --------------------
  cmp   r15d, 7
  jne   @@DoCpuid                   ; Only leaf 7 needs subleaf count check
  movzx ecx, BYTE PTR [r12+1]       ; ECX = bSubleaf
  test  ecx, ecx
  jz    @@DoCpuid                   ; Subleaf 0 always exists if leaf 7 exists

  ; Verify CPUID(7,0).EAX = max subleaf index for leaf 7
  push  rcx                         ; Save bSubleaf
  mov   eax, 7
  xor   ecx, ecx
  cpuid                             ; EAX = max subleaf for leaf 7
  pop   rcx
  cmp   eax, ecx                    ; max subleaf >= requested subleaf
  jb    @@ReturnFalse

@@DoCpuid:
  ; ====================================================================
  ; Step 10: Execute CPUID(leaf, subleaf)
  ; ====================================================================
  mov   eax, r15d                   ; Leaf
  movzx ecx, BYTE PTR [r12+1]       ; Subleaf
  cpuid                             ; => EAX, EBX, ECX, EDX

  ; ====================================================================
  ; Step 11: Select output register by bReg [R12+2]
  ;   0=EAX  1=EBX  2=ECX  3=EDX
  ; ====================================================================
  cmp   r14b, RG_EDX
  je    @@Exam                      ; EDX => already in EDX
  cmp   r14b, RG_ECX
  je    @@SelEcx
  cmp   r14b, RG_EBX
  je    @@SelEbx
  mov   edx, eax                    ; RG_EAX
  jmp   @@Exam
@@SelEbx:
  mov   edx, ebx
  jmp   @@Exam
@@SelEcx:
  mov   edx, ecx

  ; ====================================================================
  ; Step 12: Extract bit R13B from EDX => EAX = 0 or 1
  ; ====================================================================
@@Exam:
  mov   cl,  r13b                   ; Bit position
  shr   edx, cl                     ; Shift requested bit to position 0
  and   edx, 1                      ; Mask all other bits
  mov   eax, edx                    ; EAX = TRUE (1) or FALSE (0)

  pop   r15
  pop   r14
  pop   r13
  pop   r12
  pop   rdi
  pop   rsi
  pop   rbx
  ret

align ALIGN_CODE
@@ReturnFalse:
  xor   eax, eax
  pop   r15
  pop   r14
  pop   r13
  pop   r12
  pop   rdi
  pop   rsi
  pop   rbx
  ret

IsCpuFeaturePresent endp
OPTION PROC:DEFAULT

;end

