; ==================================================================================================
; Title:      ShortToLongPathNameA.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMemWin.cop

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  ShortToLongPathNameA
; Purpose:    Allocate a new ANSI string containing the long path of a short path string.
; Arguments:  Arg1: -> Short path ANSI string.
; Return:     rax -> Long path ANSI string or NULL if failed.

.code
align ALIGN_CODE
ShortToLongPathNameA proc uses rdi rsi pShortPathNameA:POINTER
  local Buffer[MAX_PATH]:CHRA
  local Result[MAX_PATH]:CHRA
  local FFD:WIN32_FIND_DATA

  invoke StrLScanA, pShortPathNameA, "~"
  test eax, eax
  jz @@0
  invoke StrLScanA, pShortPathNameA, "\"
  test eax, eax
  jnz @@1
@@0:
  invoke StrNewA, pShortPathNameA
  jmp @@Exit
@@1:
  mov rsi, rax
  sub rax, pShortPathNameA
  inc rsi
  invoke StrCCopyA, addr Result, pShortPathNameA, eax
  invoke StrEndA, pShortPathNameA
  mov rdi, rax
@@2:
  invoke StrLScanA, rsi, "\"
  mov rsi, rax
  invoke StrCatCharA, addr Result, "\"
  test rsi, rsi
  jnz @@3
  mov rax, rdi
  jmp @@4
@@3:
  mov rax, rsi
@@4:
  sub rax, pShortPathNameA
  invoke StrCCopyA, addr Buffer, pShortPathNameA, eax
  invoke FindFirstFile, addr Buffer, addr FFD
  invoke FindClose, rax
  invoke StrCatA, addr Result, addr FFD.cFileName
  test rsi, rsi
  jz @@5
  inc rsi
  cmp rsi, rdi
  jne @@2
  invoke StrCatCharA, addr Result, "\"
@@5:
  invoke StrNewA, addr Result
@@Exit:
  ret
ShortToLongPathNameA endp

end
