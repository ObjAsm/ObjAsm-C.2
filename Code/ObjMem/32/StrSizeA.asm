; ==================================================================================================
; Title:      StrSizeA.asm
; Author:     G. Friedrich
; Version:    C.2.0
; Notes:      Version C.1.0, October 2017
;               - Initial release.
;             Version C.2.0, May 2026
;               - ~30% faster than C.1.0 on typical workloads.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
% include &ObjMemPath&ObjMemWin.cop

; --------------------------------------------------------------------------------------------------
; Procedure:  StrSizeA
; Purpose:    Determine the size of an ANSI string including the zero terminating character (ZTC).
; Arguments:  Arg1: -> ANSI string.
; Return:     eax = Size of the string in BYTEs including the zero terminating character.

.const
align sizeof(DWORD)
OR_MASKS_A  DD 000000000h
            DD 0000000FFh
            DD 00000FFFFh
            DD 000FFFFFFh

.code
OPTION PROC:NONE
align ALIGN_CODE
StrSizeA proc pStringA:POINTER
  mov eax, [esp + 4]                                    ; eax -> StringA
  mov ecx, eax                                          ; ecx -> StringA
  and ecx, 3                                            ; BYTE misalignment 0..3 from DWORD boundary
  and eax, 0FFFFFFFCh                                   ; Align down to DWORD boundary
  mov edx, [OR_MASKS_A + ecx*sizeof(DWORD)]             ; Preload mask
  or edx, [eax]                                         ; Suppress pre-string zero CHRAs

  lea ecx, [edx - 01010101h]
  not edx
  and ecx, edx
  and ecx, 80808080h                                    ; Zero-BYTE test
  jnz SHORT @@Exit                                      ; Found ZTC

align ALIGN_CODE
@@Scan:
repeat 3
  add eax, sizeof(DWORD)                                ; Next DWORD
  mov edx, [eax]                                        ; Load DWORD
  lea ecx, [edx - 01010101h]
  not edx
  and ecx, edx
  and ecx, 80808080h                                    ; Zero-BYTE test
  jnz SHORT @@Exit                                      ; Found ZTC
endm

  add eax, sizeof(DWORD)                                ; Next DWORD
  mov edx, [eax]                                        ; Load DWORD
  lea ecx, [edx - 01010101h]
  not edx
  and ecx, edx
  and ecx, 80808080h                                    ; Zero-BYTE test
  jz SHORT @@Scan                                       ; Continue scan

@@Exit:
  mov edx, [esp + 4]                                    ; Reload original ptr, overlaps bsf latency
  bsf ecx, ecx                                          ; Return index of 1st set bit (start BIT00)
  shr ecx, 3                                            ; BYTE offset 0..3
  lea eax, [eax + ecx + sizeof(CHRA)]                   ; End address + 1
  sub eax, edx                                          ; eax = BYTE count including ZTC
  ret 4
StrSizeA endp
OPTION PROC:DEFAULT


;.code
;OPTION PROC:NONE
;align ALIGN_CODE
;StrSizeA proc pStringA:POINTER
;  mov eax, DWORD ptr [esp + 4]
;  mov edx, eax
;  and eax, 0FFFFFFFCh                                   ;Remove the last 2 bits to align the addr
;  sub edx, eax                                          ;edx = 0..3
;  mov ecx, DWORD ptr [eax]
;  lea edx, [offset @@0 + 8*edx]                         ;Jump forward to skip non string BYTEs
;  jmp edx
;
;  align ALIGN_CODE
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
;  add eax, 4
;  mov ecx, DWORD ptr [eax]
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
;    add eax, 4
;    mov ecx, DWORD ptr [eax]
;  endm
;
;  jmp @@0
;
;@0:
;  sub eax, [esp + 4]
;  add eax, 1
;  ret 4
;@1:
;  sub eax, [esp + 4]
;  add eax, 2
;  ret 4
;@2:
;  sub eax, [esp + 4]
;  add eax, 3
;  ret 4
;@3:
;  sub eax, [esp + 4]
;  add eax, 4
;  ret 4
;StrSizeA endp
;
;OPTION PROLOGUE:PROLOGUEDEF
;OPTION EPILOGUE:EPILOGUEDEF

end
