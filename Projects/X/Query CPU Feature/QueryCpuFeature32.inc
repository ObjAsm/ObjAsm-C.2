;================================================================================================== 
; Title:      IsCpuFeaturePresent32.asm
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


;% include @Environ(OBJASM_PATH)\Code\OA_Setup32.inc
;% include &ObjMemPath&ObjMemWin.cop

include ICFP-Table_X.inc

; ==================================================================================================
; Procedure:  IsCpuFeaturePresent
; Purpose:    Check if a CPU hardware feature is present and usable on this system.
; Arguments:  Arg1: wFeature - ICFP_xxx index constant (0 .. ICFP_COUNT-1)
; Return:     EAX = TRUE (1) or FALSE (0)

OPTION PROC:NONE

.code
align ALIGN_CODE
IsCpuFeaturePresent proc wFeatureIndex:WORD

  ; ====================================================================
  ; Step 1: Verify CPUID is available (EFLAGS.ID = bit 21)
  ; ====================================================================
  pushfd
  pop   eax
  mov   ecx, eax                    ; Save original EFLAGS
  xor   eax, 000200000h             ; Toggle ID bit (bit 21)
  push  eax
  popfd                             ; Attempt to modify EFLAGS.ID
  pushfd
  pop   eax                         ; Read back modified EFLAGS
  push  ecx
  popfd                             ; Restore original EFLAGS
  cmp   eax, ecx                    ; Did ID bit change?
  jne   @F
  xor   eax, eax                    ; No => CPUID unsupported => FALSE
  ret   4

align ALIGN_CODE
@@:
  ; ====================================================================
  ; Step 2: Prologue - save callee-saved registers
  ; ====================================================================
  push  ebx
  push  esi
  push  edi
  push  ebp

  ; ====================================================================
  ; Step 3: Bounds check - feature index must be valid
  ; ====================================================================
  movzx eax, WORD PTR [esp + 20]    ; EAX = wFeatureIndex
  cmp   eax, ICFP_COUNT
  jae   @@ReturnFalse               ; Out of range => FALSE

  ; ====================================================================
  ; Step 4: Load descriptor table entry
  ;   Entry size = 8 bytes => offset = index * 8
  ; ====================================================================
  mov   esi, OFFSET ICFP_TABLE      ; ESI = table base
  shl   eax, 3                      ; EAX = index * 8
  add   esi, eax                    ; ESI = pointer to entry

  ; ESI layout:
  ;   [ESI+0] bLeaf
  ;   [ESI+1] bSubleaf
  ;   [ESI+2] bReg
  ;   [ESI+3] bBit
  ;   [ESI+4] bVendor
  ;   [ESI+5] bXCR0
  ;   [ESI+6] bFlags
  ;   [ESI+7] bPad

  ; Cache frequently-used fields
  movzx ebp, BYTE PTR [esi + 2]     ; EBP = bReg
  movzx edi, BYTE PTR [esi + 3]     ; EDI = bBit

  ; ====================================================================
  ; Step 5: CPUID(0) => max basic leaf + vendor string
  ; ====================================================================
  xor   eax, eax
  cpuid                             ; EAX=max basic, EBX/ECX/EDX=vendor

  push  eax                         ; Save max basic leaf
  push  ebx                         ; Save vendor EBX

  ; Stack layout now:
  ; [esp+0]  vendor EBX
  ; [esp+4]  max basic leaf
  ; [esp+8]  saved EBP
  ; [esp+12] saved EDI
  ; [esp+16] saved ESI
  ; [esp+20] saved EBX
  ; [esp+24] return address
  ; [esp+28] wFeatureIndex

  ; ====================================================================
  ; Step 6: Vendor filter check (bVendor at [ESI+4])
  ;
  ;   VF_ANY   (0) => skip
  ;   VF_INTEL (1) => vendor must be "GenuineIntel"
  ;   VF_AMD   (2) => vendor must be "AuthenticAMD"
  ; ====================================================================
  movzx eax, BYTE PTR [esi + 4]     ; EAX = bVendor
  test  eax, eax
  jz    @@SkipVendor                ; VF_ANY => no filtering

  mov   ecx, DWORD PTR [esp]        ; ECX = vendor EBX DWORD

  cmp   eax, VF_INTEL
  je    @@CheckIntel

  ; AMD vendor required
  cmp   ecx, "htuA"                 ; "Auth" from "AuthenticAMD"
  jne   @@ReturnFalse2
  jmp   @@SkipVendor

@@CheckIntel:
  cmp   ecx, "uneG"                 ; "Genu" from "GenuineIntel"
  jne   @@ReturnFalse2

@@SkipVendor:
  ; ====================================================================
  ; Step 7: Intel-reserved check (bFlags bit 1 = ICFP_FL_IRSV)
  ;   If feature bit is Intel-reserved and CPU is Intel => FALSE
  ; ====================================================================
  movzx eax, BYTE PTR [esi + 6]     ; EAX = bFlags
  bt    eax, 1                      ; Test ICFP_FL_IRSV
  jnc   @@SkipIRSV                  ; Not reserved => continue

  mov   ecx, DWORD PTR [esp]        ; Reload vendor EBX
  cmp   ecx, "uneG"                 ; Intel CPU?
  je    @@ReturnFalse2              ; Reserved bit on Intel => FALSE

@@SkipIRSV:
  ; ====================================================================
  ; Step 8: XCR0 / OSXSAVE validation
  ;
  ;   XCRLVL_NONE   (0) => skip
  ;   XCRLVL_AVX    (1) => XCR0 AND 006h    = 006h
  ;   XCRLVL_AVX512 (2) => XCR0 AND 0E6h   = 0E6h
  ;   XCRLVL_AMX    (3) => XCR0 AND 060000h = 060000h
  ; ====================================================================
  movzx eax, BYTE PTR [esi + 5]     ; EAX = bXCR0 level
  test  eax, eax
  jz    @@SkipXcr                   ; No XGETBV requirement

  push  eax                         ; Save XCR0 level across CPUID

  ; OSXSAVE must be enabled before XGETBV is legal
  mov   eax, 1
  xor   ecx, ecx
  cpuid                             ; ECX = CPUID(1).ECX feature bits

  bt    ecx, 27                     ; OSXSAVE bit
  jnc   @@XcrFail                   ; No OSXSAVE => FALSE

  pop   eax                         ; Restore XCR0 level
  push  eax                         ; Preserve for later comparisons

  xor   ecx, ecx
  db    0Fh,01h,0D0h                ; XGETBV

  mov   ebx, eax                    ; EBX = XCR0 low dword

  pop   eax                         ; EAX = saved XCR level

  cmp   eax, XCRLVL_AMX
  je    @@XcrAMX

  cmp   eax, XCRLVL_AVX512
  je    @@XcrAVX512

  ; --------------------------------------------------------------------
  ; AVX validation: require XMM + YMM state enabled
  ; --------------------------------------------------------------------
  and   ebx, 006h
  cmp   ebx, 006h
  jne   @@ReturnFalse2
  jmp   @@SkipXcr

@@XcrAVX512:
  ; --------------------------------------------------------------------
  ; AVX-512 validation:
  ; Require XMM, YMM, Opmask, Hi256, ZMM state
  ; --------------------------------------------------------------------
  and   ebx, 0E6h
  cmp   ebx, 0E6h
  jne   @@ReturnFalse2
  jmp   @@SkipXcr

@@XcrAMX:
  ; --------------------------------------------------------------------
  ; AMX validation:
  ; Require XTILECFG + XTILEDATA enabled
  ; --------------------------------------------------------------------
  and   ebx, 060000h
  cmp   ebx, 060000h
  jne   @@ReturnFalse2

  jmp   @@SkipXcr

@@XcrFail:
  add   esp, 4                      ; Discard saved XCR level
  jmp   @@ReturnFalse2

@@SkipXcr:
  ; ====================================================================
  ; Step 9: Build actual CPUID leaf address
  ;   bFlags bit 0 (ICFP_FL_EX):
  ;     0 => basic leaf
  ;     1 => extended leaf (0x80000000 + bLeaf)
  ; ====================================================================
  movzx eax, BYTE PTR [esi]         ; EAX = bLeaf
  movzx ecx, BYTE PTR [esi + 6]     ; ECX = bFlags

  bt    ecx, 0                      ; Test ICFP_FL_EX
  jnc   @@BasicLeaf

  ; --------------------------------------------------------------------
  ; Extended leaf handling
  ; --------------------------------------------------------------------
  or    eax, 80000000h              ; Convert to extended leaf

  push  eax                         ; Save requested leaf

  mov   eax, 80000000h
  cpuid                             ; EAX = max extended leaf

  pop   ecx                         ; ECX = requested extended leaf

  cmp   eax, ecx
  jb    @@ReturnFalse2              ; Unsupported => FALSE

  mov   eax, ecx
  jmp   @@DoCpuid

@@BasicLeaf:
  ; --------------------------------------------------------------------
  ; Basic leaf validation
  ; --------------------------------------------------------------------
  cmp   DWORD PTR [esp + 4], eax    ; max basic leaf >= requested?
  jb    @@ReturnFalse2

  ; --------------------------------------------------------------------
  ; Leaf 7 subleaf validation
  ; CPUID(7,0).EAX = max supported subleaf index
  ; --------------------------------------------------------------------
  cmp   eax, 7
  jne   @@DoCpuid

  movzx ecx, BYTE PTR [esi + 1]     ; ECX = requested subleaf
  test  ecx, ecx
  jz    @@DoCpuid                   ; Subleaf 0 always exists

  push  ecx

  mov   eax, 7
  xor   ecx, ecx
  cpuid                             ; EAX = max subleaf index

  pop   ecx

  cmp   eax, ecx
  jb    @@ReturnFalse2              ; Requested subleaf unsupported

  mov   eax, 7

@@DoCpuid:
  ; ====================================================================
  ; Step 10: Execute CPUID(leaf, subleaf)
  ; ====================================================================
  movzx ecx, BYTE PTR [esi + 1]     ; ECX = subleaf
  cpuid                             ; => EAX, EBX, ECX, EDX

  ; ====================================================================
  ; IMPORTANT:
  ; Preserve CPUID ECX result BEFORE ECX is reused
  ; ====================================================================
  mov   esi, ecx                    ; Save CPUID ECX result

  ; ====================================================================
  ; Step 11: Select output register by bReg
  ;   0=EAX  1=EBX  2=ECX  3=EDX
  ; ====================================================================
  cmp   ebp, RG_EDX
  je    @@UseEdx
  cmp   ebp, RG_ECX
  je    @@UseEcx
  cmp   ebp, RG_EBX
  je    @@UseEbx
  mov   edx, eax
  jmp   @@Exam
@@UseEbx:
  mov   edx, ebx
  jmp   @@Exam
@@UseEcx:
  mov   edx, esi
  jmp   @@Exam

@@UseEdx:
  ; EDX already contains requested register

@@Exam:
  ; ====================================================================
  ; Step 12: Extract target bit
  ; ====================================================================
  mov   ecx, edi                    ; ECX = bit position
  shr   edx, cl                     ; Shift target bit into bit 0
  and   edx, 1                      ; Isolate result
  mov   eax, edx                    ; EAX = TRUE (1) or FALSE (0)

  ; ====================================================================
  ; Epilogue — restore registers and return
  ; ====================================================================
  add   esp, 8                      ; Discard vendor/maxleaf cache
  pop   ebp
  pop   edi
  pop   esi
  pop   ebx
  ret   4

align ALIGN_CODE
@@ReturnFalse2:
  add   esp, 8                      ; Discard vendor/maxleaf cache

@@ReturnFalse:
  xor   eax, eax                    ; FALSE
  pop   ebp
  pop   edi
  pop   esi
  pop   ebx
  ret   4

IsCpuFeaturePresent endp

OPTION PROC:DEFAULT

;end