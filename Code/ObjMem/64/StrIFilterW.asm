; ==================================================================================================
; Title:      StrIFilterW.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMemWin.cop

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  StrIFilterW
; Purpose:    Perform a case insensitive string match test using wildcards (* and ?).
; Arguments:  Arg1: -> Source WIDE string.
;             Arg2: -> Filter WIDE string.
; Return:     eax = TRUE if strings match, otherwise FALSE.

OPTION PROC:NONE

.code
align ALIGN_CODE
StrIFilterW proc pStringW:POINTER, pFilterW:POINTER
  ;rcx -> StringW, rdx -> FilterW
  .while TRUE
    mov r10w, [rdx]
    .break .if r10w == "*"
    mov ax, [rcx]
    .break .if ax == 0
    .if r10w != "?"
      .if r10w != ax
        .if (r10w >= "A" && r10w <= "Z") || (r10w >= "a" && r10w <= "z")
          xor r10w, " "
          .if r10w != ax
            xor eax, eax
            ret
          .endif
        .endif
      .endif
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
    .elseif r10w == "?"
      add rcx, 2
      add rdx, 2
    .else
      .if r10w != ax
        .if (r10w >= "A" && r10w <= "Z") || (r10w >= "a" && r10w <= "z")
          xor r10w, 20h
          .if r10w != ax
            mov rcx, r8
            mov rdx, r9
            add r8, 2
            .continue
          .endif
        .endif
      .endif
      add rcx, 2
      add rdx, 2
    .endif
  .endw

  .while CHRW ptr [rdx] == "*"
    add rdx, 2
  .endw

  xor eax, eax
  .if CHRW ptr [rdx] == 0
    inc eax
  .endif

  ret
StrIFilterW endp

OPTION PROC:DEFAULT

end
