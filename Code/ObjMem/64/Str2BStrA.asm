; ==================================================================================================
; Title:      Str2BStrA.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMemWin.cop

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  Str2BStrA
; Purpose:    Convert a ANSI string into a BStr.
; Arguments:  Arg1: -> Destination BStr buffer = Buffer address + sizeof(DWORD).
;             Arg2: -> Source ANSI string.
; Return:     eax = String length.

.code
align ALIGN_CODE
Str2BStrA proc uses rdi rsi pDstBStr:POINTER, pSrcStrA:POINTER
  mov rdi, pDstBStr
  mov rsi, pSrcStrA
  invoke StrLengthA, rsi
  mov ecx, eax
  add rsi, rax
  inc ecx
  shl eax, 1
  push rax
  add rdi, rax
  xor eax, eax
  std
@@:
  lodsb
  stosw
  dec ecx
  test ecx, ecx
  jne @B
  cld
  pop rax
  mov rdi, pDstBStr
  mov DCHRW ptr [rdi - sizeof(DCHRW)], eax
  shr eax, 1
  ret
Str2BStrA endp

end
