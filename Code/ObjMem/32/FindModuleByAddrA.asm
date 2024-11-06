; ==================================================================================================
; Title:      FindModuleByAddrA.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release. Code from E. Hansen.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
% include &ObjMemPath&ObjMemWin.cop

% include &IncPath&Windows\Psapi.inc

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  FindModuleByAddrA
; Purpose:    Find the module name from an address on a WinNT system.
; Arguments:  Arg1: Address.
;             Arg2: -> ANSI module name buffer.
; Return:     eax = Number of characters copied into the buffer.

.code
align ALIGN_CODE
FindModuleByAddrA proc uses edi esi ebx pAddress:POINTER, pModuleNameA:POINTER
  local dPID:DWORD
  local hProcess:HANDLE
  local hMods[1024]:HANDLE
  local cbNeeded:DWORD
  local ModInfo:MODULEINFO
  local hModule:HANDLE
  local hLib:HANDLE
  local pEnumProcessModules:POINTER
  local pGetModuleInformation:POINTER
  local cModName[MAX_PATH]:CHRA

  invoke GetModuleHandle, 0                             ;Important to ensure that
  invoke LoadLibraryA, $OfsCStr("psapi.dll")            ;  LoadLibrary works well
  test eax, eax
  jnz @F
  ret
@@:
  mov hLib,eax
  invoke GetProcAddress, hLib, $OfsCStrA("EnumProcessModules")
  mov pEnumProcessModules, eax
  test eax, eax
  jnz @F
  ret
@@:
  invoke GetProcAddress, hLib, $OfsCStrA("GetModuleInformation")
  mov [pGetModuleInformation], eax
  test eax, eax
  jnz @F
  ret
@@:

  mov eax, pModuleNameA
  m2z BYTE ptr [eax]                                    ;Set terminating zero

  mov ebx, pAddress
  invoke GetCurrentProcessId
  mov dPID, eax
  invoke OpenProcess, PROCESS_QUERY_INFORMATION + PROCESS_VM_READ, FALSE, dPID
  mov hProcess, eax

  lea eax, cbNeeded
  push eax
  push 1024
  lea eax, hMods
  push eax
  push hProcess
  call pEnumProcessModules
  test eax, eax
  jz @@Done
    mov edi, cbNeeded
    shr edi, 2
    lea eax, hMods
    mov esi, eax
@@L1:
    mov eax, [esi]
    mov hModule, eax
    add esi, 4

    push sizeof MODULEINFO
    lea eax, ModInfo
    push eax
    push hModule
    push hProcess
    call pGetModuleInformation
    test eax, eax
    jz @@Done
    cmp ebx, ModInfo.lpBaseOfDll
    jg @@L2
      dec edi
      test edi, edi
      js @@Done
      jmp @@L1
@@L2:
      mov eax, ModInfo.SizeOfImage
      add eax, ModInfo.lpBaseOfDll
      cmp ebx, eax
      jl @@L3
      dec edi
      test edi, edi
      js @@Done
      jmp @@L1
@@L3:
    invoke GetModuleFileNameA, hModule, addr cModName, lengthof cModName
    invoke GetFileTitleA, addr cModName, pModuleNameA, lengthof cModName

@@Done:
  invoke CloseHandle, hProcess
  invoke FreeLibrary, hLib
  invoke StrLengthA, pModuleNameA
  ret
FindModuleByAddrA endp

end
