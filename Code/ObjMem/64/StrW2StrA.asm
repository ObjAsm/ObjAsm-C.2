; ==================================================================================================
; Title:      StrW2StrA.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMemWin.cop

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  StrW2StrA
; Purpose:    Convert a WIDE string into an ANSI string. WIDE characters are converted to BYTEs by
;             decimation of the high byte.
; Arguments:  Arg1: -> Destination ANSI character buffer.
;             Arg2: -> Source WIDE string.
; Return:     rax = Number of characters.

OPTION PROC:NONE

.code
align ALIGN_CODE
StrW2StrA proc pBuffer:POINTER, pSrcStringW:POINTER
  push rdi
  push rsi
  mov rdi, rcx                                          ;rdi -> Buffer
  mov rsi, rdx                                          ;rsi -> SrcStringW
@@1:
  lodsw
  or ah, ah                                             ;check high order byte if it is zero
  jz @@2
  xor eax, eax                                          ;No convertion is possible!
  jmp @@Exit
@@2:
  stosb
  or ax, ax                                             ;Check for ZTC
  jne @@1
  sub rdi, rcx                                          ;pBuffer
  mov rax, rdi                                          ;Return number of chars
@@Exit:
  pop rsi
  pop rdi
  ret
StrW2StrA endp

OPTION PROC:DEFAULT

end
