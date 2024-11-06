; ==================================================================================================
; Title:      HnsecsToTime_X.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2023
;               - First release.
; ==================================================================================================


% include &MacPath&QuadWord.inc

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  HnsecsToTime
; Purpose:    Convert hecto-nano-seconds into DTL_TIME information.
; Arguments:  Arg1: -> DTL_TIME
;             Arg2: -> hecto-nano-seconds
; Return:     eax = TRUE id succeeded, otherwise FALSE.

.code
align ALIGN_CODE
HnsecsToTime proc uses xbx pTime:PDTL_TIME, pHnsecs:PDTL_HNSECS
  if TARGET_BITNESS eq 32
    mov ecx, pHnsecs
    mov eax, [ecx]
    mov edx, [ecx + 4]
    mov ebx, 10000                                  ;Remove all up to ms
    qddiv
    mov ebx, 1000
    qddiv
    mov ecx, pTime
    mov [ecx].DTL_TIME.wMilli, bx
    mov ebx, 60
    qddiv
    mov ecx, pTime
    mov [ecx].DTL_TIME.wSecond, bx
    mov ebx, 60
    qddiv
    mov ecx, pTime
    mov [ecx].DTL_TIME.wMinute, bx
    mov [ecx].DTL_TIME.wHour, ax
    .if edx != 0 || eax > 0FFFFh                    ;Overflow?
      xor eax, eax
    .else
      mov eax, TRUE
    .endif
  else
    mov rcx, pHnsecs
    mov rax, [rcx]
    mov ebx, 10000                                  ;Remove all up to ms
    xor edx, edx
    div rbx
    mov rcx, pTime
    mov ebx, 1000                                   ;Get ms and secs
    xor edx, edx
    div rbx
    mov [rcx].DTL_TIME.wMilli, dx
    xor edx, edx
    mov ebx, 60
    div rbx
    mov [rcx].DTL_TIME.wSecond, dx
    xor edx, edx
    div rbx
    mov [rcx].DTL_TIME.wMinute, dx
    mov [rcx].DTL_TIME.wHour, ax
    .if rax > 0FFFFh                                ;Overflow
      xor eax, eax
    .else
      mov eax, TRUE
    .endif
  endif
  ret
HnsecsToTime endp

