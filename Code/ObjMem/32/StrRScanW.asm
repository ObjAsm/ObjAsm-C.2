; ==================================================================================================
; Title:      StrRScanW.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
% include &ObjMemPath&ObjMemWin.cop

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  StrRScanW
; Purpose:    Scan from the end of a WIDE string for a character.
; Arguments:  Arg1: -> Source WIDE string.
;             Arg2: Character to search for.
; Return:     eax -> Character address or NULL if not found.

OPTION PROC:NONE

.code
align ALIGN_CODE
StrRScanW proc pStringW:POINTER, cChar:CHRW
  invoke StrLengthW, [esp + 4]                          ;pStringW
  test eax, eax
  je @@Exit                                             ;Lenght = 0
  push edi
  std
  mov edi, [esp + 8]                                    ;edi -> StringW
  mov ecx, eax
  lea edi, [edi + 2*eax - 2]
  mov ax, [esp + 12]                                    ;ax = cChar
  repne scasw
  mov eax, 0                                            ;Don't change flags!
  jne @F
  lea eax, [edi + 2]
@@:
  cld
  pop edi
@@Exit:
    ret 8
StrRScanW endp

OPTION PROC:DEFAULT

end
