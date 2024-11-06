; ==================================================================================================
; Title:      SysStandby.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
% include &ObjMemPath&ObjMemWin.cop

CStrW wSysStandby_SeShutdownPrivilege, "SeShutdownPrivilege"

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  SysStandby
; Purpose:    Set the system in standby modus.
; Arguments:  None.
; Return:     Nothing.

OPTION PROC:NONE

.code
align ALIGN_CODE
SysStandby proc
  invoke GetCurrentProcess
  push eax
  invoke SetPrivilegeTokenW, eax, offset wSysStandby_SeShutdownPrivilege, TRUE
  .if eax != FALSE
    invoke SetSystemPowerState, TRUE, TRUE
  .endif
  pop eax
  invoke SetPrivilegeTokenW, eax, offset wSysStandby_SeShutdownPrivilege, FALSE
  ret
SysStandby endp

OPTION PROC:DEFAULT

end
