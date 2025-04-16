; ==================================================================================================
; Title:      GUID2Str_AXP.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
;               - Bitness and platform independent code.
; ==================================================================================================


; --------------------------------------------------------------------------------------------------
; Procedure:  GUID2StrA
; Purpose:    Convert a GUID to an ANSI string.
; Arguments:  Arg1: -> Destination ANSI string buffer.
;                   It must hold at least 36 characters plus a ZTC (= 37 BYTEs).
;             Arg2: -> GUID.
; Return:     Nothing.

.code
align ALIGN_CODE
GUID2StrA proc uses xdi xsi pBuffer:POINTER, pGUID:POINTER
  if TARGET_BITNESS eq 32
    mov edi, pBuffer                                    ;xdi -> Buffer
    mov esi, pGUID                                      ;xsi -> GUID
  else
    mov rdi, rcx                                        ;xdi -> Buffer
    mov rsi, rdx                                        ;xsi -> GUID
  endif
  invoke dword2hexA, xdi, DWORD ptr [xsi]               ;Convert DWORD to hex
  mov CHRA ptr [xdi + 08], "-"                          ;Append "-"
  add xdi, 9
  invoke dword2hexA, xdi, DWORD ptr [xsi + 4]           ;Convert next DWORD to hex
  mov ecx, QCHRA ptr [xdi + 0]                          ;Rearrange chars
  mov eax, QCHRA ptr [xdi + 4]
  mov QCHRA ptr [xdi + 0], eax
  mov CHRA ptr [xdi + 04], "-"                          ;Insert "-"
  mov QCHRA ptr [xdi + 5], ecx
  mov CHRA ptr [xdi + 09], "-"                          ;Append "-"
  add xdi, 10
  invoke dword2hexA, xdi, DWORD ptr [xsi + 8]           ;Convert next DWORD to hex
  mov ecx, QCHRA ptr [xdi + 0]                          ;Rearrange chars
  mov eax, QCHRA ptr [xdi + 4]
  mov DCHRA ptr [xdi + 2], ax
  shr eax, 16
  mov DCHRA ptr [xdi + 0], ax
  mov DCHRA ptr [xdi + 7], cx
  shr ecx, 16
  mov CHRA ptr [xdi + 04], "-"                          ;Insert "-"
  mov DCHRA ptr [xdi + 5], cx
  add xdi, 9
  invoke dword2hexA, xdi, DWORD ptr [xsi + 12]          ;Convert next DWORD to hex
  mov ecx, QCHRA ptr [xdi + 0]                          ;Rearrange chars
  mov eax, QCHRA ptr [xdi + 4]
  mov DCHRA ptr [xdi + 2], ax
  shr eax, 16
  mov DCHRA ptr [xdi + 0], ax
  mov DCHRA ptr [xdi + 6], cx
  shr ecx, 16
  mov DCHRA ptr [xdi + 4], cx
  ret
GUID2StrA endp
