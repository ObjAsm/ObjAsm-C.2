; ==================================================================================================
; Title:      StrLScanW.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
% include &ObjMemPath&ObjMemWin.cop

; --------------------------------------------------------------------------------------------------
; Procedure:  StrLScanW
; Purpose:    Scan for a character from the beginning of a WIDE string.
; Arguments:  Arg1: -> Source WIDE string.
;             Arg2: Character to search for.
; Return:     eax -> Character address or NULL if not found.

OPTION PROC:NONE

.code
align ALIGN_CODE
StrLScanW proc pStringW:POINTER, cChar:CHRW
  invoke StrLengthW, [esp + 4]                          ;pStringW
  test eax, eax                                         ;Lenght = 0 ?
  jz @@Exit                                             ;Return NULL
  mov ecx, eax                                          ;ecx (counter) = length
  mov ax, [esp + 8]                                     ;Load Char
  push edi                                              ;Save edi onto stack
  mov edi, [esp + 8]                                    ;pStringW
  repne scasw
  mov eax, 0                                            ;Dont't change flags!
  jne @F
  lea eax, [edi - sizeof(CHRW)]
@@:
  pop edi                                               ;Recover edi
@@Exit:
  ret 8
StrLScanW endp

OPTION PROC:DEFAULT

end
