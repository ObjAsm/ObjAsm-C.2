; ==================================================================================================
; Title:      ResLeak.asm
; Author:     G. Friedrich
; Purpose:    Detection of resource leakages using ResGuardxx.dll for plain MASM applications.
; Version:    C.1.0
; Notes:      Version C.1.0, August 2023
;               - First release.
; ==================================================================================================


option casemap:none                 ;Case sensitive
.686p                               ;Use 686 protected mode
.model flat, stdcall                ;Memory model = flat, use StdCall as default calling convention 

include \Masm32\Include\Windows.inc
include D:\ObjAsm\Code\Inc\ObjAsm\ResGuard.inc
include \Masm32\Include\Gdi32.inc
include \Masm32\Include\Kernel32.inc

includelib D:\ObjAsm\Code\Lib\32\ObjAsm\ResGuard32.lib
includelib \Masm32\Lib\Gdi32.lib
includelib \Masm32\Lib\Kernel32.lib

.code
start:
  invoke ResGuardInit, ebp
  invoke ResGuardStart
  invoke CreatePen, PS_SOLID, 5, 255
  invoke ResGuardShow
  invoke ResGuardStop
  invoke ExitProcess, 0
end start
