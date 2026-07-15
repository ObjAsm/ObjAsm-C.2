; ==================================================================================================
; Title:      ResLeak.asm
; Author:     G. Friedrich
; Purpose:    Detection of resource leakages using ResGuard32.dll for plain MASM applications.
; Version:    C.1.0
; Notes:      Version C.1.0, August 2023
;               - Initial release.
; ==================================================================================================


option casemap:none                 ;Case sensitive
.686p                               ;Use 686 protected mode
.model flat, stdcall                ;Memory model = flat, use StdCall as default calling convention 

% include @Environ(OBJASM_PATH)\\Code\\Inc\\ObjAsm\\ResGuard.inc
% include @Environ(MASM32_PATH)\\Include\\Windows.inc
% include @Environ(MASM32_PATH)\\Include\\Gdi32.inc
% include @Environ(MASM32_PATH)\\Include\\Kernel32.inc

;% includelib @Environ(OBJASM_PATH)\\Code\\Lib\\32\\ObjAsm\\ResGuard32.lib
% includelib @CatStr(<!">, @Environ(OBJASM_PATH), <\\Code\\Lib\\32\\ObjAsm\\ResGuard32.lib!">)
% includelib @Environ(MASM32_PATH)\\Lib\\Gdi32.lib
% includelib @Environ(MASM32_PATH)\\Lib\\Kernel32.lib

.data?
  pMem  DWORD   ?

.code

LeakProc4 proc
  invoke CreatePen, PS_SOLID, 5, 255
  invoke GetProcessHeap
  invoke HeapAlloc, eax, HEAP_ZERO_MEMORY, 1024
  mov pMem, eax
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
  invoke ResGuardVersion
  invoke ResGuardStart
  invoke CreatePen, PS_SOLID, 5, 255
;  invoke DeleteObject, eax
  invoke LeakProc1
  invoke LeakProc3
;  invoke GetProcessHeap
;  invoke HeapFree, eax, 0, pMem
  invoke ResGuardShow
  invoke ResGuardStop
  invoke ExitProcess, 0
start endp

end start