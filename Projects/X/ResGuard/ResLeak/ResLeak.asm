; ==================================================================================================
; Title:   ResLeak.asm
; Author:  G. Friedrich  @ July 2005
; Version: 1.0.0
; Purpose: Resource Leakage demonstration for non ObjAsm32 applications.
; ==================================================================================================


option casemap:none                 ;Case sensitive
.686p                               ;Use 686 protected mode
.model flat, stdcall                ;Memory model = flat, use StdCall as default calling convention 


include \Masm32\Include\Windows.inc
include \Masm32\Include\ResGuard.inc
include \Masm32\Include\Gdi32.inc
include \Masm32\Include\Kernel32.inc

includelib \Masm32\Lib\ResGuard.lib
includelib \Masm32\Lib\Gdi32.lib
includelib \Masm32\Lib\Kernel32.lib

.code
start:
    invoke ResGuardStart
    invoke CreatePen, PS_SOLID, 5, 255
    invoke ResGuardShow
    invoke ResGuardStop
    invoke ExitProcess, 0
end start
