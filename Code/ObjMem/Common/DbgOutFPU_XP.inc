; ==================================================================================================
; Title:      DbgOutFPU_XP.inc
; Author:     G. Friedrich
; Version:    C.1.1
; Notes:      Version C.1.0, October 2017.
;               - First release.
;             Version C.1.1, July 2022.
;               - Level count corrected. Value displayed in Visual studio does not match the FPU
;                 TagWord. Here it is explained http://www.ray.masmcode.com/tutorial/fpuchap1.htm
; ==================================================================================================


; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  DbgOutFPU / DbgOutFPU_UEFI
; Purpose:    Display the content of the FPU.
; Arguments:  Arg1: -> Destination Window WIDE name.
;             Arg2: Foreground RGB color value.
;             Arg3: Background RGB color value.
; Return:     Nothing.

align ALIGN_CODE
ProcName proc uses xbx xdi xsi pDest:POINTER, dForeColor:DWORD, dBackColor:DWORD
  local FPU_Buffer:FPU_CONTEXT, dLevels:DWORD
  local bBuffer[128]:CHRA, bFPExept[30]:CHRA

  fsave FPU_Buffer
  movzx ecx, FPU_Buffer.wStatusWord
  movzx eax, FPU_Buffer.wTagWord
  shr ecx, 10
  and ecx, 00001110b                                  ;Get top of barrel x 2
  ror ax, cl                                          ;Move first bit couple to the lower bit position
  xor edx, edx
  .while edx < 8                                      ;Count how much are <> 011b
    mov cx, ax
    and cx, 0000000000000011b
    .break .if cx == 0000000000000011b
    shr ax, 2
    inc edx
  .endw
  mov dLevels, edx                                    ;Store the result

  invoke StrECopyA, addr bBuffer, $OfsCStrA("FPU Levels : ")
  invoke udword2decA, xax, dLevels                    ;Display Levels found
  invoke DbgOutTextA, addr bBuffer, dForeColor, dBackColor, DBG_EFFECT_NEWLINE, pDest

  movzx eax, WORD ptr FPU_Buffer.wStatusWord
  shr eax, 6                                          ;ax  = 000000X* XXY*Y*ZZ
  shl al, 3                                           ;ax  = 000000X* *Y*ZZ---
  shl ax, 1                                           ;ax  = 00000X** Y*ZZ----
  shl al, 1                                           ;ax  = 00000X** *ZZ-----
  shr eax, 7                                          ;ax  = -------0 0000X***
  and eax, 7                                          ;ax  = 00000000 00000***
  .if eax == 0                                        ;If ST > Source
    mov xcx, $OfsCStrA("Conditional: ST !> Source")
  .elseif eax == 1                                    ;If ST < Source
    mov xcx, $OfsCStrA("Conditional: ST !< Source")
  .elseif eax == 4                                    ;IF ST = Source
    mov xcx, $OfsCStrA("Conditional: ST = Source")
  .else                                               ;Anything else
    mov xcx, $OfsCStrA("Conditional: Undefined")
  .endif
  invoke DbgOutTextA, xcx, dForeColor, dBackColor, DBG_EFFECT_NEWLINE, pDest

  invoke StrCopyA, addr bFPExept, $OfsCStrA("Exceptions : e s p u o z d i")  ;FPU Exceptions
  movzx eax, WORD ptr FPU_Buffer.wStatusWord          ;eax = Status first found
  xor ecx, ecx                                        ;ecx = 0
  lea xdx, [bFPExept + 13]                            ;edx = First Exception Bit address
  .while ecx < 8                                      ;Go thru 8 exception bits
    rol al, 1                                         ;Rol the exception bits left 1
    jc @F                                             ;See if a '1' Passed out
    or BYTE ptr [xdx], 20h                            ;No, then force lower case (not set)
    jmp @Next                                         ;    and onto next section
@@:
    and BYTE ptr [xdx], 0DFh                          ;Yes, then Force Upper case (Exception set)
@Next:                                                ;and onto next section
    add xdx, 2                                        ;Since Spaces, inc 2 in string
    inc ecx                                           ;Next bit!
  .endw
  invoke DbgOutTextA, addr bFPExept, dForeColor, dBackColor, DBG_EFFECT_NEWLINE, pDest

  xor esi, esi                                        ;esi = Counter = 0
  lea xdi, FPU_Buffer.tST0
  .while esi < dLevels                                ;Go through all known stack entries
    finit
    fld TBYTE ptr [xdi]
    mov xbx, $invoke(StrECopyA, addr bBuffer, $OfsCStrA("  st("))
    invoke udword2decA, xax, esi                      ;Display levels
    invoke StrECopyA, addr [xbx + xax - 1], $OfsCStrA(") = ")
    invoke St0ToStrA, xax, 0, 7, f_SCI
    invoke DbgOutTextA, addr bBuffer, dForeColor, dBackColor, DBG_EFFECT_NEWLINE, pDest
    add xdi, sizeof(TBYTE)                            ;Next entry
    inc esi
  .endw

  ret
ProcName endp
