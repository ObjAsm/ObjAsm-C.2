; ==================================================================================================
; Title:      StrIFilterW.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
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
  push ebx
  push edi
  push esi
  mov edi, [esp + 16]                                   ;edi -> StringW
  mov esi, [esp + 20]                                   ;esi -> FilterW
  
  .while 1
    mov bx, [esi]
    .break .if bx == "*"
    mov ax, [edi]
    .break .if ax == 0
    .if bx != "?"
      .if bx != ax
        .if (bx >= "A" && bx <= "Z") || (bx >= "a" && bx <= "z")
          xor bx, 20h
          .if bx != ax
            xor eax, eax
            pop esi
            pop edi
            pop ebx
            ret 8
          .endif
        .endif
      .endif
    .endif
    add edi, 2
    add esi, 2
  .endw

  .while 1
    mov ax, [edi]
    .break .if ax == 0
    mov bx, [esi]
    .if bx == "*"
      add esi, 2
      mov bx, [esi]
      .if bx == 0
        xor eax, eax
        inc eax
        pop esi
        pop edi
        pop ebx
        ret 8
      .endif
      mov ecx, edi
      mov edx, esi
      add ecx, 2
    .elseif bx == "?"
      add edi, 2
      add esi, 2
    .else
      .if bx != ax
        .if (bx >= "A" && bx <= "Z") || (bx >= "a" && bx <= "z")
          xor bx, 20h
          .if bx != ax
            mov edi, ecx
            mov esi, edx
            add ecx, 2
            .continue
          .endif
        .endif
      .endif
      add edi, 2
      add esi, 2
    .endif
  .endw

  .while WORD ptr [esi] == "*"
    add esi, 2
  .endw

  xor eax, eax
  .if WORD ptr [esi] == 0
    inc eax
  .endif
  
  pop esi
  pop edi
  pop ebx
  ret 8
StrIFilterW endp

OPTION PROC:DEFAULT

end
