; ==================================================================================================
; Title:      StkGrdCallback.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, September 2018.
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMemWin.cop

CStr StkGrdTitle,   "Stack overrun detected !!"
CStr StkGrdMessage, "The application may be unstable.", 10, 13,\
                    "Do you want to continue ?", 10, 13,\
                    "Press 'No' to launch the debugger or ", 10, 13,\
                    "'Cancel' to abort the application."

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  StkGrdCallback
; Purpose:    StackGuard notification callback procedure.
;             It is called when StackGuard is active and a stack overrun was detected.
;             It displays a MessageBox asking to abort. If yes, then Exitprocess is called
;             immediately.
; Arguments:  None.
; Return:     Nothing.

.code
align ALIGN_CODE
StkGrdCallback proc
  push rbp                                              ;Save all registers
  push rax
  push rbx
  push rcx
  push rdx
  push rdi
  push rsi
  push r8
  push r9
  push r10
  push r11
  push r12
  push r13
  push r14
  push r15
  invoke MessageBox, 0, offset StkGrdMessage, offset StkGrdTitle, \
                     MB_YESNOCANCEL or MB_DEFBUTTON3 or MB_ICONEXCLAMATION or MB_TASKMODAL
  .if eax == IDCANCEL
    invoke ExitProcess, -1                              ;Return -1 to indicate failure
  .endif
  cmp eax, IDNO
  pop r15
  pop r14
  pop r13
  pop r12
  pop r11                                               ;;Restore CPU registers
  pop r10
  pop r9
  pop r8
  pop rsi
  pop rdi
  pop rdx
  pop rcx
  pop rbx
  pop rax
  pop rbp
  ret
StkGrdCallback endp

end
