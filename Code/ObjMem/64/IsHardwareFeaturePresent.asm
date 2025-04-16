; ==================================================================================================
; Title:      IsHardwareFeaturePresent.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release. Based on Donkey's code (http://donkey.visualassembler.com/).
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMemWin.cop

; --------------------------------------------------------------------------------------------------
; Procedure:  IsHardwareFeaturePresent
; Purpose:    Check if a CPU hardware feature is present on the system.
; Arguments:  Arg1: CPUID feature ID.
; Return:     rax = TRUE or FALSE.

.code
align ALIGN_CODE
IsHardwareFeaturePresent proc uses rbx bFeature:BYTE
  ;This will test to see if CPUID is available on the system
  mov r8b, cl
  pushfq
  pop rax
  mov rcx, rax
  xor rax, 000200000h                                   ;Try to change bit 21
  push rax
  popfq
  pushfq
  pop rax
  cmp rax, rcx
  jne @F
  xor eax, eax                                          ;Bit could not be changed => return failure
  ret

@@:
  ;CPUID is avialable, only 486SX and below do not have it anyway
  xor eax, eax                                          ;CPUID function number 0
  cpuid                                                 ;edi and esi are not changed
  cmp ebx, "uneG"                                       ;Check for "GenuineIntel" signature
  jne @@NoIntelCPU
  cmp edx, "Ieni"
  jne @@NoIntelCPU
  cmp ecx, "letn"
  jne @@NoIntelCPU
  mov cl, [rsp + 8]                                     ;Mask out bits 10, 20 and 30 that are
  cmp cl, 30                                            ; reserved in Intel CPUs
  je @F
  cmp cl, 20
  je @F
  cmp cl, 10
  jne @@Next

@@:
  xor eax, eax                                          ;Return failure
  ret

@@NoIntelCPU:
  mov cl, [rsp + 8]                                     ;bFeature
  cmp cl, 30
  jl @@Next
  cmp cl, 31
  jg @@Next
  mov eax, 80000001h                                    ;CPUID function number 80000001h
  cpuid
  jmp @@Exam

@@Next:
  xor eax, eax
  inc eax                                               ;CPUID function number 1
  cmp cl, 31                                            ;> 31 => test ecx
  ja @@ECX?
  cpuid                                                 ;cpuid returns info in eax, ebx, ecx & edx
  jmp @@Exam

@@ECX?:
  sub BYTE ptr [rsp + 8], 32
  cpuid                                                 ;cpuid returns info in eax, ebx, ecx & edx
  mov edx, ecx

@@Exam:
  mov cl, r8b
  mov eax, edx
  shr eax, cl
  and rax, 1                                            ;Returns rax = TRUE if feature is present
  ret
IsHardwareFeaturePresent endp

end
