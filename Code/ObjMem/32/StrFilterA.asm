; ==================================================================================================
; Title:      StrFilterA.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
% include &ObjMemPath&ObjMemWin.cop

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  StrFilterA
; Purpose:    Perform a case sensitive string match test using wildcards (* and ?).
; Arguments:  Arg1: -> Source ANSI string.
;             Arg2: -> Filter ANSI string.
; Return:     eax = TRUE if strings match, otherwise FALSE.

OPTION PROC:NONE

.code
align ALIGN_CODE
StrFilterA proc pStringA:POINTER, pFilterA:POINTER
  push edi
  push esi
  mov edi, [esp + 12]                                   ;edi -> STRINGA
  mov esi, [esp + 16]                                   ;esi -> FilterA
  
  .while 1
    mov ah, [esi]
    .break .if ah == "*"
    mov al, [edi]
    .break .if al == 0
    .if (ah != al) && (ah != "?")
      xor eax, eax
      pop esi
      pop edi
      ret 8
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
    .elseif (ah == al) || (ah == "?")
      inc edi
      inc esi
    .else
      mov edi, ecx
      mov esi, edx
      inc ecx
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
StrFilterA endp

OPTION PROC:DEFAULT

end
