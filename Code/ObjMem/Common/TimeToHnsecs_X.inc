; ==================================================================================================
; Title:      TimeToHnsecs_X.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2023
;               - First release.
; ==================================================================================================


; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  TimeToHnsecs
; Purpose:    Convert DTL_TIME information into hecto-nano-seconds.
; Arguments:  Arg1: -> hnsecs or NULL
;             Arg2: -> DTL_TIME
; Return:     rax or edx::eax = Time.

.code
align ALIGN_CODE
if TARGET_BITNESS eq 32
  TimeToHnsecs proc uses ebx edi pHnsecs:PDTL_HNSECS, pTime:PDTL_TIME
    mov edx, pTime
    movzx eax, [edx].DTL_TIME.wHour
    mov ecx, 60*60*10000
    mul ecx
    mov ebx, eax
    mov edi, edx
    movzx eax, [edx].DTL_TIME.wMinute
    mov ecx, 60*10000
    mul ecx
    add ebx, eax
    adc edi, edx
    movzx eax, [edx].DTL_TIME.wSecond
    mov ecx, 10000
    mul ecx
    add ebx, eax
    adc edi, edx
    movzx eax, [edx].DTL_TIME.wMilli
    mov ecx, 10
    mul ecx
    add eax, ebx
    adc edx, edi
    mov edx, pHnsecs
    .if edx != NULL
      mov [edx].DTL_HNSECS.dLow, eax
      mov [edx].DTL_HNSECS.dHigh, edx
    .endif
    ret
  TimeToHnsecs endp
else
  TimeToHnsecs proc uses rbx pHnsecs:PDTL_HNSECS, pTime:PDTL_TIME
    mov rdx, pTime
    movzx eax, [rdx].DTL_TIME.wHour
    mov rcx, 60*60*10000
    mul rcx
    mov rbx, rax
    movzx eax, [rdx].DTL_TIME.wMinute
    mov rcx, 60*10000
    mul rcx
    add rbx, rax
    movzx eax, [rdx].DTL_TIME.wSecond
    mov rcx, 10000
    mul rcx
    add rbx, rax
    movzx eax, [rdx].DTL_TIME.wMilli
    mov rcx, 10
    mul rcx
    add rax, rbx
    mov rdx, pHnsecs
    .if rdx != NULL
      mov [rdx], rax
    .endif
    ret
  TimeToHnsecs endp
endif
