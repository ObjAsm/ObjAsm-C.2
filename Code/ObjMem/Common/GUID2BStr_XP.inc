; ==================================================================================================
; Title:      GUID2BStr_XP.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
;               - Bitness and platform independent code.
; ==================================================================================================


; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  GUID2BStr
; Purpose:    Convert a GUID to a BStr.
; Arguments:  Arg1: -> Destination BStr Buffer. It must hold at least
;                   36 characters plus a terminating zero.
;             Arg2: -> GUID.
; Return:     Nothing.

.code
align ALIGN_CODE
GUID2BStr proc uses xdi xsi pBString:POINTER, pGUID:POINTER
  if TARGET_BITNESS eq 32
    mov edi, pBString                                   ;xdi -> BString
    mov esi, pGUID                                      ;xsi -> GUID
  else
    mov rdi, rcx                                        ;xdi -> BString
    mov rsi, rdx                                        ;xsi -> GUID
  endif
  mov DWORD ptr [xdi - 4], 72                           ;Byte size of the string
  invoke dword2hexW, xdi, DWORD ptr [xsi]               ;Convert DWORD to hex
  mov CHRW ptr [xdi + 16], "-"                          ;Append "-"
  add xdi, 18
  invoke dword2hexW, xdi, DWORD ptr [xsi + 4]           ;Convert next DWORD to hex
  mov eax, DCHRW ptr [xdi + 08]                         ;Rearrange chars
  mov ecx, DCHRW ptr [xdi + 12]
  xchg DCHRW ptr [xdi + 00], eax
  xchg DCHRW ptr [xdi + 04], ecx
  mov CHRW ptr [xdi + 08], "-"                          ;Insert "-"
  mov DCHRW ptr [xdi + 10], eax
  mov DCHRW ptr [xdi + 14], ecx
  mov CHRW ptr [xdi + 18], "-"                          ;Append "-"
  add xdi, 20
  invoke dword2hexW, xdi, DWORD ptr [xsi + 8]           ;Convert next DWORD to hex
  mov eax, DCHRW ptr [xdi + 08]                         ;Rearrange chars
  mov ecx, DCHRW ptr [xdi + 12]
  xchg DCHRW ptr [xdi + 00], ecx
  xchg DCHRW ptr [xdi + 04], eax
  mov CHRW ptr [xdi + 08], "-"                          ;Insert "-"
  mov DCHRW ptr [xdi + 14], ecx
  mov DCHRW ptr [xdi + 10], eax
  add xdi, 18
  invoke dword2hexW, xdi, DWORD ptr [xsi + 12]          ;Convert next DWORD to hex
  mov eax, DCHRW ptr [xdi + 08]                         ;Rearrange chars
  mov ecx, DCHRW ptr [xdi + 12]
  xchg DCHRW ptr [xdi + 00], ecx
  xchg DCHRW ptr [xdi + 04], eax
  mov DCHRW ptr [xdi + 12], ecx
  mov DCHRW ptr [xdi + 08], eax
  ret
GUID2BStr endp

