; ==================================================================================================
; Title:      StrFilterW.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
% include &ObjMemPath&ObjMemWin.cop

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure: StrFilterW
; Purpose:   Perform a case sensitive string match test using wildcards (* and ?).
; Arguments: Arg1: -> Source WIDE string.
;            Arg2: -> Filter WIDE string.
; Return:    eax = TRUE if strings match, otherwise FALSE.

OPTION PROC:NONE

.code
align ALIGN_CODE
StrFilterW proc pStringW:POINTER, pPatternW:POINTER
  push ebx
  push edi
  push esi
  mov edi, [esp + 16]                                   ;edi -> StringW
  mov esi, [esp + 20]                                   ;esi -> pFilterW

  .while 1
    mov bx, [esi]
    .break .if bx == "*"
    mov ax, [edi]
    .break .if ax == 0
    .if (bx != ax) && (bx != "?")
      xor eax, eax
      pop esi
      pop edi
      pop ebx
      ret 8
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
    .elseif (bx == ax) || (bx == "?")
      add edi, 2
      add esi, 2
    .else
      mov edi, ecx
      mov esi, edx
      add ecx, 2
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
StrFilterW endp

OPTION PROC:DEFAULT

end
