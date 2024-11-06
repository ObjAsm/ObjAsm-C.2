; ==================================================================================================
; Title:      StrRScanA.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
% include &ObjMemPath&ObjMemWin.cop

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure: StrRScanA
; Purpose:   Scan from the end of an ANSI string for a character.
; Arguments: Arg1: -> Source ANSI string.
;            Arg2: Character to search for.
; Return:    eax -> Character address or NULL if not found.

OPTION PROC:NONE

.code
align ALIGN_CODE
StrRScanA proc pStringA:POINTER, cChar:CHRA
  invoke StrLengthA, [esp + 4]                          ;pStringA
  test eax, eax
  je @@Exit                                             ;Lenght = 0
  push edi
  std
  mov edi, [esp + 8]                                    ;edi -> STRINGA
  mov ecx, eax
  lea edi, [edi + eax - 1]
  mov al, [esp + 12]                                    ;al = cChar
  repne scasb
  mov eax, 0                                            ;Don't change flags!
  jne @F
  lea eax, [edi + 1]
@@:
  cld
  pop edi
@@Exit:
  ret 8
StrRScanA endp

OPTION PROC:DEFAULT

end
