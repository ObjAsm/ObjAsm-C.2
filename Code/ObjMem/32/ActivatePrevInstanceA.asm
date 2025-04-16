; ==================================================================================================
; Title:      ActivatePrevInstanceA.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
% include &ObjMemPath&ObjMemWin.cop

; --------------------------------------------------------------------------------------------------
; Procedure:  ActivatePrevInstanceA
; Purpose:    Activate a previously existing instance of an application.
; Arguments:  Arg1: -> ANSI application name.
;             Arg2: -> ANSI class name.
; Return:     eax = TRUE if activated, otherwise FALSE.

.code
align ALIGN_CODE
ActivatePrevInstanceA proc uses edi pStringIDA:POINTER, pClassNameA:POINTER
  invoke GetPrevInstanceA, pStringIDA, pClassNameA
  test eax, eax
  jz @@Exit
  mov edi, eax                                          ;edi = hMainWnd or hPopupWnd
  invoke IsIconic, edi                                  ;If the window is minimized
  .if eax == FALSE
    invoke SetForegroundWindow, edi                     ;Activate the window
  .else
    invoke ShowWindow, edi, SW_RESTORE                  ;Restore wnd to its normal placement
  .endif
  xor eax, eax
  inc eax                                               ;Return TRUE
@@Exit:
  ret
ActivatePrevInstanceA endp

end
