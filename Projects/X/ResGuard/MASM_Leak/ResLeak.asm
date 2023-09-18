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

LeakProc4 proc
  invoke CreatePen, PS_SOLID, 5, 255
  ret
LeakProc4 endp

LeakProc3 proc
  invoke LeakProc4
  ret
LeakProc3 endp

LeakProc2 proc uses esi
  local Count2:DWORD

  invoke CreatePen, PS_SOLID, 5, 255
  add Count2, 2
  ret
LeakProc2 endp

LeakProc1 proc uses ebx
  local Count:DWORD

  invoke LeakProc2
  inc Count
  ret
LeakProc1 endp

start proc
  invoke ResGuardInit
  invoke ResGuardStart
  invoke CreatePen, PS_SOLID, 5, 255
  invoke LeakProc1
  invoke LeakProc3
  invoke ResGuardShow
  invoke ResGuardStop
  invoke ExitProcess, 0
start endp

end start