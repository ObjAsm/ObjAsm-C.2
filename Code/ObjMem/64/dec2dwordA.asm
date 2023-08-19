; ==================================================================================================
; Title:      dec2dwordA.asm
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
; Procedure:  dec2dwordA
; Purpose:    Convert a decimal ANSI string to a DWORD.
; Arguments:  Arg1: -> Source ANSI string. Possible leading characters are " ", tab, "+" and "-",
;                   followed by a sequence of chars between "0".."9" and finalized by a ZTC.
;                   Other characters terminate the convertion returning zero.
; Return:     eax = Converted DWORD.
;             rcx = Conversion result. Zero if succeeded, otherwise failed.

OPTION PROC:NONE
align ALIGN_CODE
dec2dwordA proc pStringA:POINTER
  push rsi
  mov rsi, rcx                                          ;rsi -> StringA
  xor eax, eax
  xor ecx, ecx
  xor edx, edx                                          ;Sign buffer
  .repeat
    lodsb
  .until al != " " && al != 9                           ;Skip leading blanks
  cmp al, "+"
  je @F                                                 ;Skip "+" 1 time
  .if al == "-"
    not rdx
    jmp @F
  .endif

  .repeat
    sub al, "0"
    .if al > 9
      xor eax, eax
      mov rcx, -1                                       ;Failed => exit now
      pop rsi
      ret
    .endif
    lea rcx, DWORD ptr [rcx + 4*rcx]
    lea rcx, DWORD ptr [rax + 2*rcx]                    ;rcx = rax + 10*rcx
@@:
    lodsb
    or al, al                                           ;Check for ZTC
  .until ZERO?

  lea rax, DWORD ptr [rdx + rcx]                        ;Sign correction
  xor ecx, ecx                                          ;Success flag
  xor rax, rdx
  pop rsi
  ret
dec2dwordA endp
OPTION PROC:DEFAULT

end
