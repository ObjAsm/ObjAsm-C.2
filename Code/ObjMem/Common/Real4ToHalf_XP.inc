; ==================================================================================================
; Title:      Real4ToHalf_XP.inc
; Author:     AW @ http://masm32.com/board/index.php?topic=7406.0, G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, April 2020.
;               - First release.
;               - Bitness neutral version.
; ==================================================================================================


; --------------------------------------------------------------------------------------------------
; Procedure:  Real4ToHalf
; Purpose:    Convert a REAL4 to an HALF.
; Arguments:  Arg1: REAL4 value.
; Return:     ax = HALF.
; Note:       alternative code using VCVTPS2PH: 
;                movss xmm0, r4Value
;                VCVTPS2PH xmm1, xmm0, 0
;                movd eax, xmm1

.code
align ALIGN_CODE
Real4ToHalf proc uses xbx xsi r4Value:REAL4
  ?mov ecx, r4Value
  mov edx, ecx
  and edx, 80000000h
  shr edx, 10h 
  and ecx, 7FFFFFFFh
  
  .if ecx > 477FE000h
    mov eax, ecx
    and eax, 7F800000h
    .if eax == 7F800000h
      mov eax, ecx
      and eax, 7FFFFFh
      .if eax != 0
        mov eax, 7FFFh
      .else
        mov eax, 7C00h
      .endif
    .else
      mov eax, 7C00h
    .endif
  .else
    .if ecx < 38800000h
      mov ebx, ecx
      shr ebx, 23
      mov eax, 113
      sub eax, ebx 
      mov ebx, ecx
      and ebx, 7FFFFFh
      mov esi, 800000h
      or esi, ebx 
      mov ecx, eax
      shr esi, cl
      mov ecx, esi
    .else
      add ecx, 0C8000000h
    .endif
    mov eax, ecx
    add eax, 0FFFh
    shr ecx, 13
    and ecx, 1
    add eax, ecx
    shr eax, 13
    and eax, 7FFFh
  .endif
  or eax, edx
  and eax, 0FFFFh
  ret
Real4ToHalf endp
