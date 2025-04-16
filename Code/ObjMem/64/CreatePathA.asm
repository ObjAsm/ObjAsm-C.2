; ==================================================================================================
; Title:      CreatePathA.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMemWin.cop

; --------------------------------------------------------------------------------------------------
; Procedure:  CreatePathA
; Purpose:    Create a path on the destination drive.
; Arguments:  Arg1: -> ANSI path string.
; Return:     Nothing.

.code
align ALIGN_CODE
CreatePathA proc uses rbx rsi pPathNameA:POINTER
  local FFD:WIN32_FIND_DATA
  local cBuffer[MAX_PATH]:CHRA

  lea rbx, cBuffer
  invoke StrECopyA, rbx, pPathNameA
  FillStringA [rax], <\\*.*>
  invoke FindFirstFileA, rbx, addr FFD
  cmp rax, INVALID_HANDLE_VALUE
  je @@0
  invoke FindClose, rax                                 ;Directory just exists!
  mov rax, TRUE
  jmp @@Exit
@@0:
  mov rbx, pPathNameA
  invoke StrLScanA, rbx, "\"
  test rax, rax
  jz @@Exit
  inc rax
  mov rsi, rax
@@1:
  invoke StrLScanA, rsi, "\"
  mov rsi, rax
  test rax, rax
  je @@2
  sub rax, rbx
  invoke StrCCopyA, addr cBuffer, rbx, eax
  jmp @@3
@@2:
  invoke StrCopyA, addr cBuffer, rbx
@@3:
  invoke CreateDirectoryA, addr cBuffer, NULL
  test rsi, rsi
  jz @@Exit
  inc rsi
  jmp @@1
@@Exit:
  ret
CreatePathA endp

end
