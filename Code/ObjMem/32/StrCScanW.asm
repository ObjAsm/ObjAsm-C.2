; ==================================================================================================
; Title:      StrCScanW.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
% include &ObjMemPath&ObjMemWin.cop

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  StrCScanW
; Purpose:    Scan from the beginning of a WIDE string for a character with length limitation.
; Arguments:  Arg1: -> Source WIDE string.
;             Arg2: Maximal character count.
;             Arg3: Wide character to search for.
; Return:     eax -> Character address or NULL if not found.

OPTION PROC:NONE

.code
align ALIGN_CODE
StrCScanW proc pStringW:POINTER, dMaxCount:DWORD, cChar:CHRW
  invoke StrLengthW, [esp + 4]                          ;pStringW
  test eax, eax                                         ;Lenght = 0 ?
  jz @@Exit                                             ;Return NULL
  mov ecx, eax                                          ;ecx (counter) = length
  mov eax, [esp + 8]                                    ;eax = dMaxCount
  cmp ecx, eax
  sbb edx, edx
  and ecx, edx
  not edx
  and eax, edx
  or ecx, eax                                           ;ecx = min(ecx, eax)
  mov ax, [esp + 12]                                    ;load cChar
  push edi                                              ;Save edi onto stack
  mov edi, [esp + 8]                                    ;pStringW
  repne scasw
  mov eax, 0                                            ;Dont't change flags!
  jne @F
  lea eax, [edi - 1]
@@:
  pop edi                                               ;Recover edi
@@Exit:
  ret 12
StrCScanW endp

OPTION PROC:DEFAULT

end
