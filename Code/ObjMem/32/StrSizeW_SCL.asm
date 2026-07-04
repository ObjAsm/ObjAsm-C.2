; ==================================================================================================
; Title:      StrSizeW_SCL.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - Initial release.
;             Version C.2.0, May 2026
;               - ~30% faster than C.1.0 on typical workloads.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
% include &ObjMemPath&ObjMemWin.cop

; --------------------------------------------------------------------------------------------------
; Procedure:  StrSizeW_SCL (scalar)
; Purpose:    Determine the size of a WIDE string including the zero terminating character (ZTC).
; Arguments:  Arg1: -> Wide string.
; Return:     eax = String size in BYTEs including the zero terminating character.

.const
align 4
OR_MASKS_W  DD 000000000h                               ; Misalign 0: DWORD-aligned, no masking
            DD 000000000h                               ; Misalign 1: illegal WCHR ptr, treat as 0
            DD 00000FFFFh                               ; Misalign 2: low WORD precedes string
            DD 00000FFFFh                               ; Misalign 3: illegal WCHR ptr, treat as 2

.code
OPTION PROC:NONE
align ALIGN_CODE
StrSizeW_SCL proc pStringW:POINTER
  mov eax, [esp + 4]                                    ; eax -> StringW
  mov ecx, eax                                          ; ecx -> StringW
  and ecx, 3                                            ; BYTE misalignment 0..3 from DWORD boundary
  and eax, 0FFFFFFFCh                                   ; Align down to DWORD boundary
  mov edx, [OR_MASKS_W + ecx*sizeof(DWORD)]             ; Preload mask
  or edx, [eax]                                         ; Suppress pre-string zero CHRWs

  lea ecx, [edx - 00010001h]
  not edx
  and ecx, edx
  and ecx, 80008000h                                    ; Zero-WORD test
  jnz SHORT @@Exit                                      ; Found ZTC

align ALIGN_CODE
@@Scan:
repeat 3
  add eax, sizeof(DWORD)                                ; Next DWORD
  mov edx, [eax]                                        ; Load DWORD
  lea ecx, [edx - 00010001h]
  not edx
  and ecx, edx
  and ecx, 80008000h                                    ; Zero-WORD test
  jnz SHORT @@Exit                                      ; Found ZTC
endm

  add eax, sizeof(DWORD)                                ; Next DWORD
  mov edx, [eax]                                        ; Load DWORD
  lea ecx, [edx - 00010001h]
  not edx
  and ecx, edx
  and ecx, 80008000h                                    ; Zero-WORD test
  jz SHORT @@Scan                                       ; Continue scan

@@Exit:
  mov edx, [esp + 4]                                    ; Reload original ptr, overlaps bsf latency
  bsf ecx, ecx                                          ; Return index of 1st set bit (start BIT00)
  shr ecx, 3                                            ; BYTE offset: 0 or 2
  lea eax, [eax + ecx + 1]                              ; End address + 2
  sub eax, edx                                          ; eax = BYTE count including ZTC
  ret 4
StrSizeW_SCL endp
OPTION PROC:DEFAULT


;.code
;OPTION PROC:NONE
;align ALIGN_CODE
;StrSizeW proc pStringW:POINTER
;  mov eax, DWORD ptr [esp + 4]                          ;eax -> pStringW
;  mov edx, eax
;  and eax, 0FFFFFFFCh                                   ;Remove the last 2 bits to align the addr
;  sub edx, eax                                          ;edx = 0..3
;  mov ecx, DWORD ptr [eax]
;  jmp @@JmpTableW[4*edx]                                ;Jump forward to skip non string BYTEs
;
;  align ALIGN_CODE
;@@JmpTableW:
;  dd offset @@0
;  dd offset @@1
;  dd offset @@2
;  dd offset @@3
;
;  align ALIGN_CODE
;@@0:
;  test ecx, 00000FFFFh
;  jz @0
;@@2:
;  test ecx, 0FFFF0000h
;  jz @2
;  add eax, 4
;  mov ecx, DWORD ptr [eax]
;  jmp @@0
;
;  align ALIGN_CODE
;@@1:
;  test ecx, 000FFFF00h
;  jz @1
;@@3:
;  add eax, 4
;  test ecx, 0FF000000h
;  mov ecx, DWORD ptr [eax]
;  jnz @@1
;  test ecx, 0000000FFh
;  jnz @@1
;  sub eax, DWORD ptr [esp + 4]
;  add eax, 1
;  ret 4
;
;  align ALIGN_CODE
;@0:
;  sub eax, DWORD ptr [esp + 4]
;  add eax, 2
;  ret 4
;
;  align ALIGN_CODE
;@1:
;  sub eax, DWORD ptr [esp + 4]
;  add eax, 3
;  ret 4
;
;  align ALIGN_CODE
;@2:
;  sub eax, DWORD ptr [esp + 4]
;  add eax, 4
;  ret 4
;StrSize endp
;OPTION PROC:DEFAULT

end
