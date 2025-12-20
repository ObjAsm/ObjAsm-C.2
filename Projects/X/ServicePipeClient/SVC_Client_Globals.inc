; ==================================================================================================
; Title:      SVC_Client_Globals.inc
; Author:     G. Friedrich
; Notes:      See SVC_Client.asm
; ==================================================================================================


include SVC_Client_Shared.inc

CStr cPipeName, "\\.\pipe\ObjAsmService1"

CMD_PING        equ 1
CMD_STOP        equ 2
CMD_QUERYSTATE  equ 3