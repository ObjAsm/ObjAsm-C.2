; ==================================================================================================
; Title:      SysShutdown.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release. Based on E. Harris' code (http://donkey.visualassembler.com/).
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
% include &ObjMemPath&ObjMemWin.cop

SHTDN_REASON_FLAG_COMMENT_REQUIRED          equ 01000000h
SHTDN_REASON_FLAG_DIRTY_PROBLEM_ID_REQUIRED equ 02000000h
SHTDN_REASON_FLAG_CLEAN_UI                  equ 04000000h
SHTDN_REASON_FLAG_DIRTY_UI                  equ 08000000h

SHTDN_REASON_FLAG_USER_DEFINED              equ 40000000h
SHTDN_REASON_FLAG_PLANNED                   equ 80000000h

SHTDN_REASON_MAJOR_OTHER                    equ 00000000h
SHTDN_REASON_MAJOR_NONE                     equ 00000000h
SHTDN_REASON_MAJOR_HARDWARE                 equ 00010000h
SHTDN_REASON_MAJOR_OPERATINGSYSTEM          equ 00020000h
SHTDN_REASON_MAJOR_SOFTWARE                 equ 00030000h
SHTDN_REASON_MAJOR_APPLICATION              equ 00040000h
SHTDN_REASON_MAJOR_SYSTEM                   equ 00050000h
SHTDN_REASON_MAJOR_POWER                    equ 00060000h

SHTDN_REASON_MINOR_OTHER                    equ 00000000h
SHTDN_REASON_MINOR_NONE                     equ 000000FFh
SHTDN_REASON_MINOR_MAINTENANCE              equ 00000001h
SHTDN_REASON_MINOR_INSTALLATION             equ 00000002h
SHTDN_REASON_MINOR_UPGRADE                  equ 00000003h
SHTDN_REASON_MINOR_RECONFIG                 equ 00000004h
SHTDN_REASON_MINOR_HUNG                     equ 00000005h
SHTDN_REASON_MINOR_UNSTABLE                 equ 00000006h
SHTDN_REASON_MINOR_DISK                     equ 00000007h
SHTDN_REASON_MINOR_PROCESSOR                equ 00000008h
SHTDN_REASON_MINOR_NETWORKCARD              equ 00000009h
SHTDN_REASON_MINOR_POWER_SUPPLY             equ 0000000Ah
SHTDN_REASON_MINOR_CORDUNPLUGGED            equ 0000000Bh
SHTDN_REASON_MINOR_ENVIRONMENT              equ 0000000Ch
SHTDN_REASON_MINOR_HARDWARE_DRIVER          equ 0000000Dh
SHTDN_REASON_MINOR_OTHERDRIVER              equ 0000000Eh
SHTDN_REASON_MINOR_BLUESCREEN               equ 0000000Fh

SHTDN_REASON_UNKNOWN                        equ SHTDN_REASON_MINOR_NONE

SHTDN_REASON_VALID_BIT_MASK                 equ 0C0FFFFFFh

externdef wSysStandby_SeShutdownPrivilege:WORD

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  SysShutdown
; Purpose:    Shut down the system.
; Arguments:  Arg1: Shutdown type.
;             Arg2: Shutdown reason (see System Shutdown Reason Codes).
; Return:     Nothing.

.code
align ALIGN_CODE
SysShutdown proc dType:DWORD, dReason:DWORD
  invoke GetCurrentProcess
  invoke SetPrivilegeTokenW, eax, offset wSysStandby_SeShutdownPrivilege, TRUE
  invoke ExitWindowsEx, dType, dReason
  ret
SysShutdown endp

end
