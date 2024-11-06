; ==================================================================================================
; Title:      BStrCScan.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
% include &ObjMemPath&ObjMemWin.cop

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  BStrCScan
; Purpose:    Scan from the beginning of a BStr for a character with length limitation.
; Arguments:  Arg1: -> Source WIDE string.
;             Arg2: Maximal character count.
;             Arg3: Wide character to search for.
; Return:     eax -> Character address or NULL if not found.

OPTION PROC:NONE

.code
align ALIGN_CODE
BStrCScan proc pBStr:POINTER, dMaxChars:DWORD, cChar:CHRW
  mov ecx, [esp + 4]                                    ;ecx -> BStr
  mov eax, [ecx - 4]                                    ;eax = BStr byte size
  test eax, eax                                         ;Size = 0 ?
  jz @@Exit                                             ;Return NULL
  shr eax, 1
  mov ecx, eax                                          ;ecx (counter) = char length
  mov eax, [esp + 8]                                    ;eax = dMaxChars
  cmp ecx, eax
  sbb edx, edx
  and ecx, edx
  not edx
  and eax, edx
  or ecx, eax                                           ;ecx = min(ecx, eax)
  mov ax, [esp + 12]                                    ;load wChar
  push edi                                              ;Save edi onto stack
  mov edi, [esp + 8]                                    ;pBStr
  repne scasw
  mov eax, NULL                                         ;Dont't change flags!
  jne @F
  lea eax, [edi - 2]
@@:
  pop edi                                               ;Recover edi
@@Exit:
  ret 12
BStrCScan endp

OPTION PROC:DEFAULT

end
