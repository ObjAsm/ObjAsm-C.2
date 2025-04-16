; ==================================================================================================
; Title:      WaitForProcess.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release. Based on Donkey's code (http://donkey.visualassembler.com/).
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMemWin.cop

; --------------------------------------------------------------------------------------------------
; Procedure:  WaitForProcess
; Purpose:    Synchronisation procedure that waits until a process has finished.
; Arguments:  Arg1: Process ID.
;             Arg2: Timeout value in ms.
; Return:     eax = Wait result (WAIT_ABANDONED, WAIT_OBJECT_0 or WAIT_TIMEOUT) or -1 if failed.

.code
align ALIGN_CODE
WaitForProcess proc uses rdi rsi dProcessID:DWORD, dTimeOut:DWORD
  invoke OpenProcess, SYNCHRONIZE, FALSE, dProcessID
  test rax, rax
  jnz @F
  dec rax                                               ;-1 = failure
  ret
@@:
  mov rdi, rax                                          ;Save process handle
  invoke WaitForSingleObject, rdi, dTimeOut
  mov rsi, rax
  invoke CloseHandle, rdi                               ;hProcess
  mov rax, rsi                                          ;eax = Wait result
  ret
WaitForProcess endp

end
