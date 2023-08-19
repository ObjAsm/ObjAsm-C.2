; ==================================================================================================
; Title:      dec2dwordW.asm
; Author:     G. Friedrich
; Version:    C.1.1
; Notes:      Version C.1.0, October 2017
;               - First release.
;             Version C.1.1 August 2023
;               - Proc frame bug corrected.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMemWin.cop

.code
; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  dec2dwordW
; Purpose:    Convert a decimal WIDE string to a DWORD.
; Arguments:  Arg1: -> Source WIDE string. Possible leading characters are " ", tab, "+" and "-",
;                   followed by a sequence of chars between "0".."9" and finalized by a ZTC.
;                   Other characters terminate the convertion returning zero.
; Return:     rax = Converted DWORD.
;             rcx = Conversion result. Zero if succeeded, otherwise failed.

OPTION PROC:NONE
align ALIGN_CODE
dec2dwordW proc pStringW:POINTER
  push rsi
  xor eax, eax
  mov rsi, rcx                                          ;rsi -> StringW
  xor ecx, ecx
  xor edx, edx                                          ;Sign buffer
  .repeat
    lodsw
  .until ax != " " && ax != 9                           ;Skip leading blanks
  cmp ax, WORD ptr "+"
  je @F                                                 ;Skip "+" 1 time
  .if ax == WORD ptr "-"
    not rdx
    jmp @F
  .endif

  .repeat
    sub ax, WORD ptr "0"
    .if ax > 9
      xor eax, eax
      mov rcx, -1                                       ;Failed => exit now
      pop rsi
      ret
    .endif
    lea rcx, [rcx + 4*rcx]
    lea rcx, [rax + 2*rcx]                              ;rcx = rax + 10*rcx
@@:
    lodsw
    or ax, ax                                           ;Check for ZTC
  .until ZERO?

  lea rax, [rdx + rcx]                                  ;Sign correction
  xor ecx, ecx                                          ;Success flag
  xor rax, rdx
  pop rsi
  ret
dec2dwordW endp
OPTION PROC:DEFAULT

end
