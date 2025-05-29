; ==================================================================================================
; Title:      dec2xword_TX.inc
; Author:     G. Friedrich
; Version:    C.1.1
; Notes:      Version C.1.0, October 2017
;               - First release.
;             Version C.1.1 August 2023
;               - Proc frame bug corrected.
; ==================================================================================================


.code
; --------------------------------------------------------------------------------------------------
; Procedure:  dec2dwordA/dec2dwordW/dec2qwordA/dec2qwordW
; Purpose:    Convert a decimal string to a DWORD/QWORD.
; Arguments:  Arg1: -> Source string. Possible leading characters are " ", tab, "+" and "-",
;                   followed by a sequence of chars between "0".."9" and finalized by a ZTC.
;                   Other characters terminate the convertion returning zero.
; Return:     eax = Converted DWORD/QWORD.
;             ecx = Conversion result. Zero if succeeded, otherwise failed.

OPTION PROC:NONE

.code
align ALIGN_CODE

CharReg equ $SubReg(xax, sizeof(CHR))

ProcName proc pString:POINTER
  push xsi
if TARGET_BITNESS eq 32
    mov esi, [esp + 8]                                  ;esi -> String
else
    mov rsi, rcx                                        ;rsi -> String
endif
  xor eax, eax
  xor ecx, ecx
  xor edx, edx                                          ;Sign buffer
  .repeat
    lodsc
  .until CharReg != " " && CharReg != 9                 ;Skip leading blanks
  cmp CharReg, "+"
  je @F                                                 ;Skip "+" 1 time
  .if CharReg == "-"
    not xdx
    jmp @F
  .endif

  .repeat
    sub CharReg, "0"
    .if CharReg > 9
      xor eax, eax
      mov ecx, -1                                       ;Failed => exit now
      pop xsi
if TARGET_BITNESS eq 32
      ret 4
else
      ret
endif
    .endif
    lea xcx, [xcx + 4*xcx]
    lea xcx, [xax + 2*xcx]                              ;xcx = xax + 10*xcx
@@:
    lodsc
    or CharReg, CharReg                                 ;Check for ZTC
  .until ZERO?

  lea xax, [xdx + xcx]                                  ;Sign correction
  xor ecx, ecx                                          ;Success flag
  xor xax, xdx
  pop xsi
if TARGET_BITNESS eq 32
  ret 4
else
  ret
endif
ProcName endp

OPTION PROC:DEFAULT
