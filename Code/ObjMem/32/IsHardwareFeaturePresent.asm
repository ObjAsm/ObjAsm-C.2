; ==================================================================================================
; Title:      IsHardwareFeaturePresent.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
% include &ObjMemPath&ObjMemWin.cop

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  IsHardwareFeaturePresent
; Purpose:    Check if a CPU hardware feature is present on the system.
; Notes:      Check IHFP_xxx equates in ObjMem.inc file.
; Arguments:  Arg1: CPUID feature ID.
; Return:     eax = TRUE or FALSE.

OPTION PROC:NONE

.code
align ALIGN_CODE
IsHardwareFeaturePresent proc bFeature:BYTE
  ;This will test to see if CPUID is available on the system
  pushfd
  pop eax
  mov ecx, eax
  xor eax, 000200000h                                   ;Try to change bit 21
  push eax
  popfd
  pushfd
  pop eax
  cmp eax, ecx
  jne @F
  xor eax, eax                                          ;Bit could not be changed => return failure
  ret 4

align ALIGN_CODE
@@:
  ;CPUID is avialable, only 486SX and below do not have it anyway
  push ebx
  xor eax, eax                                          ;CPUID function number 0
  cpuid                                                 ;edi and esi are not changed
  cmp ebx, "uneG"                                       ;Check for "GenuineIntel" signature
  jne @@NoIntelCPU
  cmp edx, "Ieni"
  jne @@NoIntelCPU
  cmp ecx, "letn"
  jne @@NoIntelCPU
  mov cl, [esp + 8]                                     ;Mask out bits 10, 20 and 30 that are
  cmp cl, 30                                            ; reserved in Intel CPUs
  je @F
  cmp cl, 20
  je @F
  cmp cl, 10
  jne @@Next

@@:
  xor eax, eax                                          ;Return failure
  pop ebx
  ret 4

align ALIGN_CODE
@@NoIntelCPU:
  mov cl, [esp + 8]                                     ;bFeature
  cmp cl, 30
  jl @@Next
  cmp cl, 31
  jg @@Next
  mov eax, 80000001h                                    ;CPUID function number 80000001h
  cpuid
  jmp @@Exam

align ALIGN_CODE
@@Next:
  xor eax, eax
  inc eax                                               ;CPUID function number 1
  cmp cl, 31                                            ;> 31 => test ecx
  ja @@ECX?
  cpuid                                                 ;cpuid returns info in eax, ebx, ecx & edx
  jmp @@Exam

align ALIGN_CODE
@@ECX?:
  sub BYTE ptr [esp + 8], 32
  cpuid                                                 ;cpuid returns info in eax, ebx, ecx & edx
  mov edx, ecx

@@Exam:
  mov cl, [esp + 8]                                     ;bFeature
  mov eax, edx
  shr eax, cl
  and eax, 1                                            ;Returns eax = TRUE if feature is present
  pop ebx
  ret 4
IsHardwareFeaturePresent endp

OPTION PROC:DEFAULT

end
