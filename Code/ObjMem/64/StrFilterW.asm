; ==================================================================================================
; Title:      StrFilterW.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMemWin.cop

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  StrFilterW
; Purpose:    Perform a case sensitive string match test using wildcards (* and ?).
; Arguments:  Arg1: -> Source WIDE string.
;             Arg2: -> Filter WIDE string.
; Return:     eax = TRUE if strings match, otherwise FALSE.

OPTION PROC:NONE

.code
align ALIGN_CODE
StrFilterW proc pStringW:POINTER, pFilterW:POINTER
  push rbx
  ;rcx -> StringA, rdx -> FilterA
  .while TRUE
    mov bx, [rdx]
    .break .if bx == "*"
    mov ax, [rcx]
    .break .if ax == 0
    .if (r10w != ax) && (r10w != "?")
      xor eax, eax
      ret
    .endif
    add rcx, 2
    add rdx, 2
  .endw

  .while TRUE
    mov ax, [rcx]
    .break .if ax == 0
    mov r10w, [rdx]
    .if r10w == "*"
      add rdx, 2
      mov r10w, [rdx]
      .if r10w == 0
        xor eax, eax
        inc eax
        ret
      .endif
      mov r8, rcx
      mov r9, rdx
      add r8, 2
    .elseif (r10w == ax) || (r10w == "?")
      add rcx, 2
      add rdx, 2
    .else
      mov rcx, r8
      mov rdx, r9
      add r8, 2
    .endif
  .endw

  .while CHRW ptr [rdx] == "*"
    add rdx, 2
  .endw

  xor eax, eax
  .if CHRW ptr [rdx] == 0
    inc eax
  .endif

  pop rbx
  ret
StrFilterW endp

OPTION PROC:DEFAULT

end
