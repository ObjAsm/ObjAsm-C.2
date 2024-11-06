; ==================================================================================================
; Title:      CreatePathW.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMemWin.cop

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  CreatePathW
; Purpose:    Create a path on the destination drive.
; Arguments:  Arg1: -> WIDE path string.
; Return:     Nothing.

.code
align ALIGN_CODE
CreatePathW proc uses rbx rsi pPathNameW:POINTER
  local FFD:WIN32_FIND_DATAW
  local cBuffer[MAX_PATH]:CHRW

  lea rbx, cBuffer
  invoke StrECopyW, rbx, pPathNameW
  FillStringW [rax], <\\*.*>
  invoke FindFirstFileW, rbx, addr FFD
  cmp rax, INVALID_HANDLE_VALUE
  je @@0
  invoke FindClose, rax                                 ;Directory just exists!
  mov rax, TRUE
  jmp @@Exit
@@0:
  mov rbx, pPathNameW
  invoke StrLScanW, rbx, "\"
  test rax, rax
  jz @@Exit
  add rax, 2
  mov rsi, rax
@@1:
  invoke StrLScanW, rsi, "\"
  mov rsi, rax
  test rax, rax
  je @@2
  sub rax, rbx
  shr rax, 1
  invoke StrCCopyW, addr cBuffer, rbx, eax
  jmp @@3
@@2:
  invoke StrCopyW, addr cBuffer, rbx
@@3:
  invoke CreateDirectoryW, addr cBuffer, NULL
  test rsi, rsi
  jz @@Exit
  add rsi, 2
  jmp @@1
@@Exit:
  ret
CreatePathW endp

end
