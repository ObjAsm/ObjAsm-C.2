; ==================================================================================================
; Title:      StrSizeW.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - Initial release.
;             Version C.2.0, May 2026
;               - ~30% faster than C.1.0 on typical workloads.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMemWin.cop

; --------------------------------------------------------------------------------------------------
; Procedure:  StrSizeW
; Purpose:    Determine the size of a WIDE string including the ZTC.
; Arguments:  Arg1: -> WIDE string.
; Return:     rax = Size of the string in BYTEs.

.const
align sizeof(QWORD)
OR_MASKS_W  DQ 0000000000000000h   ; WCHR offset 0: all 4 WCHARs belong to string
            DQ 000000000000FFFFh   ; WCHR offset 1: 1 WCHR before string
            DQ 00000000FFFFFFFFh   ; WCHR offset 2: 2 WCHRs before string
            DQ 0000FFFFFFFFFFFFh   ; WCHR offset 3: 3 WCHRs before string

.code
OPTION PROC:NONE
align ALIGN_CODE
StrSizeW proc pStringW:POINTER
  mov rdx, rcx                                          ; rdx -> StringW
  mov r10, rcx                                          ; r10 -> StringW
  and rdx, 0FFFFFFFFFFFFFFF8h                           ; Align down to QWORD boundary
  and r10d, 7                                           ; BYTE misalignment 0..7 from QWORD boundary
  lea rax, OR_MASKS_W
  mov r8, [rax + r10*(sizeof(QWORD)/2)]                 ; Load mask for pre-string BYTEs in 1st QWORD
  mov r11, 0001000100010001h                            ; Subtract 1 from each WORD independently
  mov r10, 8000800080008000h                            ; High-bit mask: set only where original WORD was 00h
  or r8, [rdx]                                          ; Load first QWORD, set pre-string WORDs to FFFFh
  mov r9, r8
  sub r8, r11                                           ; Borrow propagates through 0000h WORDs only
  not r9                                                ; 0000h WORDs become FFFFh, non-zero WORDs become < 8000h
  and r8, r9                                            ; High bit set only where original WORD was 0000h
  and r8, r10                                           ; Isolate high bits: non-zero => zero WORD found
  jnz SHORT @@Exit                                      ; Zero WORD found in first QWORD

align ALIGN_CODE
@@Scan:
repeat 3
  add rdx, sizeof(QWORD)                                ; Next QWORD
  mov r8, [rdx]                                         ; Load DWORD
  mov r9, r8
  sub r8, r11
  not r9
  and r8, r9
  and r8, r10                                           ; Zero-WORD test
  jnz SHORT @@Exit                                      ; Found ZTC
endm

  add rdx, sizeof(QWORD)                                ; Advance to next QWORD (4th, closes unrolled group)
  mov r8, [rdx]                                         ; Load QWORD                                        
  mov r9, r8                                                                                                
  sub r8, r11                                           ; Borrow propagates through 0000h WORDs only          
  not r9                                                ; 0000h WORDs become FFFFh, non-zero WORDs become < 8000h 
  and r8, r9                                            ; High bit set only where original WORD was 0000h     
  and r8, r10                                           ; Isolate high bits: non-zero => zero WORD found    
  jz SHORT @@Scan                                       ; No zero WORD found => continue scanning           

@@Exit:
  bsf r8, r8                                            ; Bit index of lowest set bit (= high bit of null WORD)
  shr r8d, 3                                            ; Convert bit index to BYTE index within QWORD: 0, 2, 4, 6  
  lea rax, [rdx + r8 + 1]                               ; One past null terminator (BYTE address + 1)          
  sub rax, rcx                                          ; Size in BYTEs including null terminator              
  ret
StrSizeW endp
OPTION PROC:DEFAULT


;.code
;OPTION PROC:NONE
;align ALIGN_CODE
;StrSizeW proc pStringW:POINTER
;  mov rax, rcx
;  mov rdx, rcx
;  and rax, -8                     ;Remove the last 3 bits to align the addr, this avoids a GPF
;  sub rdx, rax                    ;rdx = 0..7
;  mov r9, [rax]
;  mov r8, r9
;  shr r9, 32
;  lea r10, @@JmpTableW
;  jmp POINTER ptr [r10 + sizeof(POINTER)*rdx]           ;Jump forward to skip non string BYTEs
;
;align @WordSize
;@@JmpTableW:
;  POINTER offset @@0
;  POINTER offset @@1
;  POINTER offset @@2
;  POINTER offset @@3
;  POINTER offset @@4
;  POINTER offset @@5
;  POINTER offset @@6
;  POINTER offset @@7
;
;@@0:
;  test r8d, 00000FFFFh
;  jz @0
;@@2:
;  test r8d, 0FFFF0000h
;  jz @2
;@@4:
;  test r9d, 00000FFFFh
;  jz @4
;@@6:
;  test r9d, 0FFFF0000h
;  jz @6
;  add rax, @WordSize
;  mov r9, [rax]
;  mov r8, r9
;  shr r9, 32
;  jmp @@0
;
;@@1:
;  test r8d, 000FFFF00h
;  jz @1
;@@3:
;  test r8d, 0FF000000h
;  jnz @@5
;  test r9d, 0000000FFh
;  jz @3
;@@5:
;  test r9d, 000FFFF00h
;  jz @5
;@@7:
;  add rax, @WordSize
;  mov r10, [rax]
;  mov r8, r10
;  shr r10, 32
;  test r9d, 0FF000000h
;  mov r9, r10
;  jnz @@1
;
;  test r8d, 0000000FFh
;  jnz @@1
;  sub rax, rcx
;  add rax, 1
;  ret
;
;@0:
;  sub rax, rcx
;  add rax, 2
;  ret
;@1:
;  sub rax, rcx
;  add eax, 3
;  ret
;@2:
;  sub rax, rcx
;  add rax, 4
;  ret
;@3:
;  sub rax, rcx
;  add rax, 5
;  ret
;@4:
;  sub rax, rcx
;  add eax, 6
;  ret
;@5:
;  sub rax, rcx
;  add rax, 7
;  ret
;@6:
;  sub rax, rcx
;  add rax, 8
;  ret
;StrSizeW endp
;
;OPTION PROC:DEFAULT

end
