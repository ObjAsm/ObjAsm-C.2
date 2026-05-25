; ==================================================================================================
; Title:      StrSizeA.asm
; Author:     G. Friedrich
; Version:    C.2.0
; Notes:      Version C.1.0, October 2017
;               - Initial release.
;             Version C.2.0, May 2026
;               - ~30% faster than C.1.0 on typical workloads.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMemWin.cop

; --------------------------------------------------------------------------------------------------
; Procedure:  StrSizeA
; Purpose:    Determine the size of an ANSI string including the zero terminating character (ZTC).
; Arguments:  Arg1: -> ANSI string.
; Return:     eax = Size of the string in BYTEs including the zero terminating character.

.const
align sizeof(QWORD)
OR_MASKS_A  DQ 0000000000000000h   ; 0 misaligned bytes  - mask nothing
            DQ 00000000000000FFh   ; 1 misaligned byte   - mask byte 0
            DQ 000000000000FFFFh   ; 2 misaligned bytes  - mask bytes 0..1
            DQ 0000000000FFFFFFh   ; 3 misaligned bytes  - mask bytes 0..2
            DQ 00000000FFFFFFFFh   ; 4 misaligned bytes  - mask bytes 0..3
            DQ 000000FFFFFFFFFFh   ; 5 misaligned bytes  - mask bytes 0..4
            DQ 0000FFFFFFFFFFFFh   ; 6 misaligned bytes  - mask bytes 0..5
            DQ 00FFFFFFFFFFFFFFh   ; 7 misaligned bytes  - mask bytes 0..6

.code
OPTION PROC:NONE
align ALIGN_CODE
StrSizeA proc pStringA:POINTER
  mov rdx, rcx                                          ; rdx -> StringA
  mov r10, rcx                                          ; r10 -> StringA
  and rdx, 0FFFFFFFFFFFFFFF8h                           ; Align rdx down to QWORD boundary
  and r10, 7                                            ; BYTE misalignment (0..7) from QWORD boundary
  lea rax, OR_MASKS_A
  mov r8, [rax + r10*sizeof(QWORD)]                     ; Load mask for pre-string BYTEs in 1st QWORD
  mov r11, 0101010101010101h                            ; Subtract 1 from each BYTE independently
  mov r10, 8080808080808080h                            ; High-bit mask: set only where original BYTE was 00h
  or r8, [rdx]                                          ; Load first QWORD, set pre-string BYTEs to FFh
  mov r9, r8
  sub r8, r11                                           ; Borrow propagates through 00h BYTEs only
  not r9                                                ; 00h BYTEs become FFh, non-zero BYTEs become < 80h
  and r8, r9                                            ; High bit set only where original BYTE was 00h
  and r8, r10                                           ; Isolate high bits: non-zero => zero BYTE found
  jnz SHORT @@Exit                                      ; Zero BYTE found in first QWORD

align ALIGN_CODE
@@Scan:
repeat 3
  add rdx, sizeof(QWORD)                                ; Advance to next QWORD
  mov r8, [rdx]                                         ; Load QWORD
  mov r9, r8
  sub r8, r11                                           ; Borrow propagates through 00h BYTEs only
  not r9                                                ; 00h BYTEs become FFh, non-zero BYTEs become < 80h
  and r8, r9                                            ; High bit set only where original BYTE was 00h
  and r8, r10                                           ; Isolate high bits: non-zero => zero BYTE found
  jnz SHORT @@Exit                                      ; Zero BYTE found - go compute length
endm
  add rdx, sizeof(QWORD)                                ; Advance to next QWORD (4th, closes unrolled group)
  mov r8, [rdx]                                         ; Load QWORD
  mov r9, r8
  sub r8, r11                                           ; Borrow propagates through 00h BYTEs only
  not r9                                                ; 00h BYTEs become FFh, non-zero BYTEs become < 80h
  and r8, r9                                            ; High bit set only where original BYTE was 00h
  and r8, r10                                           ; Isolate high bits: non-zero => zero BYTE found
  jz SHORT @@Scan                                       ; No zero BYTE found => continue scanning

@@Exit:
  bsf r8, r8                                            ; Bit index of lowest set bit (= high bit of null BYTE)
  shr r8d, 3                                            ; Convert bit index to BYTE index within QWORD (0..7)
  lea rax, [rdx + r8 + 1]                               ; One past null terminator (BYTE address + 1)
  sub rax, rcx                                          ; Size in BYTEs including null terminator
  ret
StrSizeA endp
OPTION PROC:DEFAULT


;OPTION PROC:NONE
;.code
;align ALIGN_CODE
;StrSizeA proc pStringA:POINTER
;  mov rax, rcx
;  mov rdx, rcx
;  mov r8, rcx
;  and rax, 0FFFFFFFFFFFFFFFCh                           ;Remove the last 2 bits to align the addr
;  sub rdx, rax                                          ;edx = 0..3
;  mov ecx, DWORD ptr [rax]
;  lea r9, @@0
;  lea r10, [r9 + 8*rdx]                                 ;code size (test + jz) = 8 BYTEs
;  jmp r10                                               ;Jump forward to skip non string BYTEs
;
;@@0:
;  test ecx, 0000000FFh
;  jz @0
;@@1:
;  test ecx, 00000FF00h
;  jz @1
;@@2:
;  test ecx, 000FF0000h
;  jz @2
;@@3:
;  test ecx, 0FF000000h
;  jz @3
;  add rax, 4
;  mov ecx, [rax]
;
;  repeat 3
;    test cl, cl
;    jz @0
;    test ch, ch
;    jz @1
;    test ecx, 000FF0000h
;    jz @2
;    test ecx, 0FF000000h
;    jz @3
;    add rax, 4
;    mov ecx, DWORD ptr [rax]
;  endm
;
;  jmp @@0
;
;@0:
;  sub rax, r8
;  add rax, 1
;  ret
;@1:
;  sub rax, r8
;  add rax, 2
;  ret
;@2:
;  sub rax, r8
;  add rax, 3
;  ret
;@3:
;  sub rax, r8
;  add rax, 4
;  ret
;StrSizeA endp
;OPTION PROC:DEFAULT

end
