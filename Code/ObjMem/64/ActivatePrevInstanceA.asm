; ==================================================================================================
; Title:      ActivatePrevInstanceA.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMemWin.cop

; --------------------------------------------------------------------------------------------------
; Procedure:  ActivatePrevInstanceA
; Purpose:    Activate a previously existing instance of an application.
; Arguments:  Arg1: -> ANSI application name.
;             Arg2: -> ANSI class name.
; Return:     rax = TRUE if activated, otherwise FALSE.

.code
align ALIGN_CODE
ActivatePrevInstanceA proc uses rdi pStringIDA:POINTER, pClassNameA:POINTER
  invoke GetPrevInstanceA, rcx, rdx                     ;pStringIDA, pClassNameA
  test rax, rax
  jz @@Exit
  mov rdi, rax                                          ;rdi = hMainWnd or hPopupWnd
  invoke IsIconic, rdi                                  ;If the window is minimized
  .if rax == FALSE
    invoke SetForegroundWindow, rdi                     ;Activate the window
  .else
    invoke ShowWindow, rdi, SW_RESTORE                  ;Restore wnd to its normal placement
  .endif
  xor eax, eax
  inc rax                                               ;Return TRUE
@@Exit:
  ret
ActivatePrevInstanceA endp

end
