; ==================================================================================================
; Title:      StkGrdCallback.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
% include &ObjMemPath&ObjMemWin.cop

CStr StkGrdTitle,   "Stack overrun detected !!"
CStr StkGrdMessage, "The application may be unstable.", 10, 13,\
                    "Do you want to continue ?", 10, 13,\
                    "Press 'No' to launch the debugger or ", 10, 13,\
                    "'Cancel' to abort the application."

; --------------------------------------------------------------------------------------------------
; Procedure:  StkGrdCallback
; Purpose:    StackGuard notification callback procedure.
;             It is called when StackGuard is active and a stack overrun was detected.
;             It displays a MessageBox asking to abort. If yes, then Exitprocess is called
;             immediately.
; Arguments:  None.
; Return:     ZERO flag set if NO was pressed

OPTION PROC:NONE

.code
align ALIGN_CODE
StkGrdCallback proc
  pushad                                                ;Save all registers
  invoke MessageBox, 0, offset StkGrdMessage, offset StkGrdTitle, \
                     MB_YESNOCANCEL or MB_DEFBUTTON3 or MB_ICONEXCLAMATION or MB_TASKMODAL
  .if eax == IDCANCEL
    invoke ExitProcess, -1                              ;Return -1 to indicate failure
  .endif
  cmp eax, IDNO
  popad                                                 ;Restore registers
  ret
StkGrdCallback endp

OPTION PROC:DEFAULT

end
