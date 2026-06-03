; ==================================================================================================
; Title:      IsHardwareFeaturePresent.asm
; Author:     G. Friedrich
; Version:    C.2.0
; Notes:      Version C.1.0, October 2017
;               - Initial release.
;             Version C.2.0, May 2026
;               - EFLAGS.ID (bit 21) is restored after the test.
;               - ESI saved; max basic leaf from CPUID(0) cached.
;               - Max basic leaf check added before CPUID(1).
;               - Extended leaf check added before CPUID(80000001h).
;               - Intel reserved bits consolidated to shared @@ReturnFalse.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\Code\OA_Setup64.inc
% include &ObjMemPath&ObjMemWin.cop

; --------------------------------------------------------------------------------------------------
; Procedure:  IsHardwareFeaturePresent
; Purpose:    Check if a CPU hardware feature is present on the system.
; Arguments:  Arg1: CPUID feature ID (CL, x64 Microsoft calling convention).
; Notes:      Check IHFP_xxx equates in ObjMem.inc file.
; Return:     eax = TRUE or FALSE.

OPTION PROC:NONE

.code
align ALIGN_CODE
IsHardwareFeaturePresent proc
  ; --------------------------------------------------------------------
  ; Step 1: Test CPUID availability (RFLAGS.ID = bit 21)
  ;
  ; R9 is volatile => no save needed for the temporary RFLAGS copy.
  ; XOR operates on EAX (lower 32 bits) which is where bit 21 lives;
  ; the upper 32 bits of RFLAGS are always reserved/zero.
  ; --------------------------------------------------------------------
  pushfq
  pop rax
  mov r9, rax                       ; Save original RFLAGS in R9 (volatile)
  xor eax, 000200000h               ; Toggle bit 21 (RFLAGS.ID)
  push rax
  popfq                             ; Write modified RFLAGS
  pushfq
  pop rax                           ; Read back current RFLAGS
  push r9
  popfq                             ; Restore original RFLAGS (bit 21 must not remain modified)
  cmp eax, r9d                      ; Was bit 21 successfully toggled?
  jne @F
  xor eax, eax                      ; No => CPUID not available => FALSE
  ret

align ALIGN_CODE
@@:
  ; --------------------------------------------------------------------
  ; Step 2: Save callee-saved registers & execute CPUID(0)
  ; --------------------------------------------------------------------
  push rbx
  push rsi
  push r12

  movzx r12d, cl                    ; Cache bFeature in R12B (survives all CPUID calls)

  xor eax, eax                      ; CPUID function 0
  cpuid                             ; EAX = max basic leaf, EBX/EDX/ECX = vendor ID
  mov esi, eax                      ; Cache max basic leaf in ESI

  ; --------------------------------------------------------------------
  ; Step 3: Check vendor string => "GenuineIntel"=>
  ;   EBX = "Genu"  => little-endian DWORD = "uneG"
  ;   EDX = "ineI"  => little-endian DWORD = "Ieni"
  ;   ECX = "ntel"  => little-endian DWORD = "letn"
  ; --------------------------------------------------------------------
  cmp ebx, "uneG"
  jne @@NoIntelCPU
  cmp edx, "Ieni"
  jne @@NoIntelCPU
  cmp ecx, "letn"
  jne @@NoIntelCPU

  ; --------------------------------------------------------------------
  ; Intel path: filter out reserved EDX bits 10, 20, 30
  ; All three comparisons jump to shared @@ReturnFalse
  ; --------------------------------------------------------------------
  cmp r12b, 30
  je @@ReturnFalse
  cmp r12b, 20
  je @@ReturnFalse
  cmp r12b, 10
  je @@ReturnFalse
  jmp @@Next                        ; No reserved bit => proceed to feature query

; ---------------------------------------------------------------------
; Shared exit label for all FALSE returns
; (Intel reserved, no basic leaf, no extended leaf)
; ---------------------------------------------------------------------
align ALIGN_CODE
@@ReturnFalse:
  xor eax, eax
  pop r12
  pop rsi
  pop rbx
  ret

; ---------------------------------------------------------------------
; Non-Intel path: bFeature 30–31 => CPUID(80000001h)
; ---------------------------------------------------------------------
align ALIGN_CODE
@@NoIntelCPU:
  cmp r12b, 30
  jl @@Next                         ; < 30 => basic leaf path
  cmp r12b, 31
  jg @@Next                         ; > 31 => basic leaf path (ECX bits)

  ; Check extended leaf availability before calling CPUID(80000001h)
  mov eax, 80000000h
  cpuid                             ; EAX = highest supported extended leaf
  cmp eax, 80000001h
  jb @@ReturnFalse                  ; Extended leaf 80000001h not available => FALSE

  mov eax, 80000001h
  cpuid                             ; EDX = extended feature flags
  jmp @@Exam

; ---------------------------------------------------------------------
; Basic leaf path: CPUID(1) => EDX (bFeature  0–31)
;                           => ECX (bFeature 32–63)
; ---------------------------------------------------------------------
align ALIGN_CODE
@@Next:
  test esi, esi                     ; ESI = max basic leaf from CPUID(0)
  jz @@ReturnFalse                  ; Max leaf = 0 => CPUID(1) not available

  xor eax, eax
  inc eax                           ; EAX = 1
  cmp r12b, 31                      ; bFeature > 31 => query ECX bits
  ja @@ECX?
  cpuid                             ; EDX = feature flags (bits  0–31)
  jmp @@Exam

align ALIGN_CODE
@@ECX?:
  sub r12b, 32                      ; Normalise feature index to ECX bit range (0–31)
  cpuid                             ; ECX = feature flags (bits 32–63 of query)
  mov edx, ecx                      ; ECX => EDX for unified @@Exam path

; ---------------------------------------------------------------------
; Shared evaluation: test bit bFeature in EDX
; ---------------------------------------------------------------------
@@Exam:
  mov cl,  r12b                     ; Reload (possibly normalised) feature index
  mov eax, edx                      ; Feature flags into EAX
  shr eax, cl                       ; Shift requested bit into position 0
  and eax, 1                        ; Mask all other bits => TRUE (1) or FALSE (0)
  pop r12
  pop rsi
  pop rbx
  ret

IsHardwareFeaturePresent endp
OPTION PROC:DEFAULT

end


;; --------------------------------------------------------------------------------------------------
;; Procedure:  IsHardwareFeaturePresent
;; Purpose:    Check if a CPU hardware feature is present on the system.
;; Arguments:  Arg1: CPUID feature ID.
;; Return:     rax = TRUE or FALSE.
;
;.code
;align ALIGN_CODE
;IsHardwareFeaturePresent proc uses rbx bFeature:BYTE
;  ; This will test to see if CPUID is available on the system
;  mov r8b, cl
;  pushfq
;  pop rax
;  mov rcx, rax
;  xor rax, 000200000h                                   ; Try to change bit 21
;  push rax
;  popfq
;  pushfq
;  pop rax
;  cmp rax, rcx
;  jne @F
;  xor eax, eax                                          ; Bit could not be changed => return failure
;  ret
;
;@@:
;  ; CPUID is avialable, only 486SX and below do not have it anyway
;  xor eax, eax                                          ; CPUID function number 0
;  cpuid                                                 ; edi and esi are not changed
;  cmp ebx, "uneG"                                       ; Check for "GenuineIntel" signature
;  jne @@NoIntelCPU
;  cmp edx, "Ieni"
;  jne @@NoIntelCPU
;  cmp ecx, "letn"
;  jne @@NoIntelCPU
;  mov cl, [rsp + 8]                                     ; Mask out bits 10, 20 and 30 that are
;  cmp cl, 30                                            ;  reserved in Intel CPUs
;  je @F
;  cmp cl, 20
;  je @F
;  cmp cl, 10
;  jne @@Next
;
;@@:
;  xor eax, eax                                          ; Return failure
;  ret
;
;@@NoIntelCPU:
;  mov cl, [rsp + 8]                                     ; bFeature
;  cmp cl, 30
;  jl @@Next
;  cmp cl, 31
;  jg @@Next
;  mov eax, 80000001h                                    ; CPUID function number 80000001h
;  cpuid
;  jmp @@Exam
;
;@@Next:
;  xor eax, eax
;  inc eax                                               ; CPUID function number 1
;  cmp cl, 31                                            ; > 31 => test ecx
;  ja @@ECX?
;  cpuid                                                 ; CPUID returns info in eax, ebx, ecx & edx
;  jmp @@Exam
;
;@@ECX?:
;  sub BYTE ptr [rsp + 8], 32
;  cpuid                                                 ; CPUID returns info in eax, ebx, ecx & edx
;  mov edx, ecx
;
;@@Exam:
;  mov cl, r8b
;  mov eax, edx
;  shr eax, cl
;  and rax, 1                                            ; Returns rax = TRUE if feature is present
;  ret
;IsHardwareFeaturePresent endp
