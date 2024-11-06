; ==================================================================================================
; Title:      SysStandby.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMemWin.cop

CStrW wSysStandby_SeShutdownPrivilege, "SeShutdownPrivilege"

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  SysStandby
; Purpose:    Set the system in standby modus.
; Arguments:  None.
; Return:     Nothing.

.code
align ALIGN_CODE
SysStandby proc uses rdi
  invoke GetCurrentProcess
  mov rdi, rax
  invoke SetPrivilegeTokenW, rax, offset wSysStandby_SeShutdownPrivilege, TRUE
  .if rax != FALSE
    invoke SetSystemPowerState, TRUE, TRUE
  .endif
  invoke SetPrivilegeTokenW, rdi, offset wSysStandby_SeShutdownPrivilege, FALSE
  ret
SysStandby endp

end
