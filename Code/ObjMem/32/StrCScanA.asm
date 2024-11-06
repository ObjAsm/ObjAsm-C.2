; ==================================================================================================
; Title:      StrCScanA.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
% include &ObjMemPath&ObjMemWin.cop

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  StrCScanA
; Purpose:    Scan from the beginning of ANSI string for a character with length limitation.
; Arguments:  Arg1: -> Source ANSI string.
;             Arg2: Maximal character count.
;             Arg3: ANSI character to search for.
; Return:     eax -> Character address or NULL if not found.

OPTION PROC:NONE

.code
align ALIGN_CODE
StrCScanA proc pStringA:POINTER, dMaxCount:DWORD, cChar:CHRA
  invoke StrLengthA, [esp + 4]                          ;pStringA
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
  mov al, [esp + 12]                                    ;load cChar
  push edi                                              ;Save edi onto stack
  mov edi, [esp + 8]                                    ;pStringA
  repne scasb
  mov eax, 0                                            ;Dont't change flags!
  jne @F
  lea eax, [edi - 1]
@@:
  pop edi                                               ;Recover edi
@@Exit:
  ret 12
StrCScanA endp

OPTION PROC:DEFAULT

end
