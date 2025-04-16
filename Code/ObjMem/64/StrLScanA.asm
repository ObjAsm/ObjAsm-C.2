; ==================================================================================================
; Title:      StrLScanA.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMemWin.cop

; --------------------------------------------------------------------------------------------------
; Procedure:  StrLScanA
; Purpose:    Scan for a character from the beginning of an ANSI string. 
; Arguments:  Arg1: -> Source ANSI string.
;             Arg2: Character to search.
; Return:     rax -> Character address or NULL if not found.

.code
align ALIGN_CODE
StrLScanA proc uses rbx rdi pStringA:POINTER, bChar:CHRA
  mov bl, dl
  mov rdi, rcx
  invoke StrLengthA, rcx                                ;pStringA
  test eax, eax                                         ;Lenght = 0 ?
  jz @F                                                 ;Return NULL
  mov rcx, rax                                          ;rcx (counter) = length
  mov al, bl                                            ;Load bChar
  repne scasb
  mov rax, NULL                                         ;Dont't change flags!
  jne @F
  lea rax, [rdi - sizeof(CHRA)]
@@:
  ret
StrLScanA endp

end
