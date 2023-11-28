; ==================================================================================================
; Title:      dec2dwordA.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
% include &ObjMemPath&ObjMemWin.cop

.code
; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  dec2dwordA
; Purpose:    Convert a decimal ANSI string to a DWORD.
; Arguments:  Arg1: -> Source ANSI string. Possible leading characters are " ", tab, "+" and "-",
;                   followed by a sequence of chars between "0".."9" and finalized by a ZTC.
;                   Other characters terminate the convertion returning zero.
; Return:     eax = Converted DWORD.
;             ecx = Conversion result. Zero if succeeded, otherwise failed.

OPTION PROC:NONE
align ALIGN_CODE
dec2dwordA proc pStringA:POINTER
  push esi
  xor eax, eax
  mov esi, [esp + 8]                                    ;esi -> StringA
  xor ecx, ecx
  xor edx, edx                                          ;Sign buffer
  .repeat
    lodsb
  .until al != " " && al != 9                           ;Skip leading blanks
  cmp al, "+"
  je @F                                                 ;Skip "+" 1 time
  .if al == "-"
    not edx
    jmp @F
  .endif

  .repeat
    sub al, "0"
    .if al > 9
      xor eax, eax
      mov ecx, -1                                       ;Failed => exit now
      pop esi
      ret 4
    .endif
    lea ecx, DWORD ptr [ecx + 4*ecx]
    lea ecx, DWORD ptr [eax + 2*ecx]                    ;ecx = eax + 10*ecx
@@:
    lodsb
    or al, al                                           ;Check for ZTC
  .until ZERO?

  lea eax, DWORD ptr [edx + ecx]                        ;Sign correction
  xor ecx, ecx                                          ;Success flag
  xor eax, edx
  pop esi
  ret 4
dec2dwordA endp
OPTION PROC:DEFAULT

end
