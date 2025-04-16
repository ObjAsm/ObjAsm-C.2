; ==================================================================================================
; Title:      StrIFilterA.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
% include &ObjMemPath&ObjMemWin.cop

; --------------------------------------------------------------------------------------------------
; Procedure:  StrIFilterA
; Purpose:    Perform a case insensitive string match test using wildcards (* and ?).
; Arguments:  Arg1: -> Source ANSI string.
;             Arg2: -> Filter ANSI string.
; Return:     eax = TRUE if strings match, otherwise FALSE.

OPTION PROC:NONE

.code
align ALIGN_CODE
StrIFilterA proc pStringA:POINTER, pFilterA:POINTER
  push edi
  push esi
  mov edi, [esp + 12]                                   ;edi -> STRINGA
  mov esi, [esp + 16]                                   ;esi -> pFilterA

  .while 1
    mov ah, [esi]
    .break .if ah == "*"
    mov al, [edi]
    .break .if al == 0
    .if ah != "?"
      .if ah != al
        .if (ah >= "A" && ah <= "Z") || (ah >= "a" && ah <= "z")
          xor ah, 20h
          .if ah != al
            xor eax, eax
            pop esi
            pop edi
            ret 8
          .endif
        .endif
      .endif
    .endif
    inc edi
    inc esi
  .endw

  .while 1
    mov al, [edi]
    .break .if al == 0
    mov ah, [esi]
    .if ah == "*"
      inc esi
      mov ah, [esi]
      .if ah == 0
        xor eax, eax
        inc eax
        pop esi
        pop edi
        ret 8
      .endif
      mov ecx, edi
      mov edx, esi
      inc ecx
    .elseif ah == "?"
      inc edi
      inc esi
    .else
      .if ah != al
        .if (ah >= "A" && ah <= "Z") || (ah >= "a" && ah <= "z")
          xor ah, 20h
          .if ah != al
            mov edi, ecx
            mov esi, edx
            inc ecx
            .continue
          .endif
        .endif
      .endif
      inc edi
      inc esi
    .endif
  .endw

  .while BYTE ptr [esi] == "*"
    inc esi
  .endw

  xor eax, eax
  .if BYTE ptr [esi] == 0
    inc eax
  .endif

  pop esi
  pop edi
  ret 8
StrIFilterA endp

OPTION PROC:DEFAULT

end
