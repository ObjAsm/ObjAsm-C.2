; ==================================================================================================
; Title:      ActivatePrevInstanceW.asm
; Author:     G. Friedrich / J. Trudgen
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMemWin.cop

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  ActivatePrevInstanceW
; Purpose:    Activate a previously existing instance of an application.
; Arguments:  Arg1: -> WIDE application name.
;             Arg2: -> WIDE class name.
; Return:     rax = TRUE if activated, otherwise FALSE.

.code
align ALIGN_CODE
ActivatePrevInstanceW proc uses rdi pStringIDW:POINTER, pClassNameW:POINTER
  invoke GetPrevInstanceW, rcx, rdx                     ;pStringIDW, pClassNameW
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
ActivatePrevInstanceW endp

end
