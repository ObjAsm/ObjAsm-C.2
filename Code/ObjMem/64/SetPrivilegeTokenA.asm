; ==================================================================================================
; Title:      SetPrivilegeTokenA.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMemWin.cop

TypeOpenProcessToken      typedef proto :HANDLE, :DWORD, :POINTER
TypeLookupPrivilegeValueA typedef proto :POINTER, :POINTER, :POINTER
TypeAdjustTokenPrivileges typedef proto :HANDLE, :DWORD, :POINTER, :DWORD, :POINTER, :POINTER

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  SetPrivilegeTokenA
; Purpose:    Enable privilege tokens.
; Arguments:  Arg1: Process handle.
;             Arg2: -> Privilege name (ANSI string).
;             Arg3: Eanble = TRUE, disable = FALSE.
; Return:     eax = Zero if failed.

.code
align ALIGN_CODE
SetPrivilegeTokenA proc uses rbx hProcess:HANDLE, pPrivilegeNameA:POINTER, dEnable:DWORD
  local TokenPriv:TOKEN_PRIVILEGES, PrevTokenPriv:TOKEN_PRIVILEGES
  local luid:LUID, hToken:HANDLE, dReturnLenght:DWORD
  local hLibrary:HANDLE
  local pOpenProcessToken:POINTER, pLookupPrivilegeValue:POINTER, pAdjustTokenPrivileges:POINTER

  .if $invoke(IsWinNT) != FALSE
    invoke LoadLibraryA, $OfsCStrA("Advapi32.dll")
    .if rax != 0
      mov hLibrary, rax

      ;Load the NT only functions
      invoke GetProcAddress, hLibrary, $OfsCStrA("OpenProcessToken")
      mov pOpenProcessToken, rax
      invoke GetProcAddress, hLibrary, $OfsCStrA("LookupPrivilegeValueA")
      mov pLookupPrivilegeValue, rax
      invoke GetProcAddress, hLibrary, $OfsCStrA("AdjustTokenPrivileges")
      mov pAdjustTokenPrivileges, rax

      ;Get the token for this process
      invoke TypeOpenProcessToken ptr pOpenProcessToken, \
             hProcess, TOKEN_ADJUST_PRIVILEGES or TOKEN_QUERY, addr hToken

      invoke TypeLookupPrivilegeValueA ptr pLookupPrivilegeValue, NULL, pPrivilegeNameA, addr luid
      .if eax != 0
        ;Get current privilege setting
        mov TokenPriv.PrivilegeCount, 1
        m2m TokenPriv.Privileges.Luid.LowPart, luid.LowPart, eax
        m2m TokenPriv.Privileges.Luid.HighPart, luid.HighPart, ecx
        m2z TokenPriv.Privileges.Attributes
        invoke TypeAdjustTokenPrivileges ptr pAdjustTokenPrivileges, hToken, FALSE, \
               addr TokenPriv, sizeof(TokenPriv), addr PrevTokenPriv, addr dReturnLenght
        .if eax != 0
          ;Set privilege based on previous setting
          mov PrevTokenPriv.PrivilegeCount, 1
          m2m PrevTokenPriv.Privileges.Luid.LowPart, luid.LowPart, eax
          m2m PrevTokenPriv.Privileges.Luid.HighPart, luid.HighPart, ecx
          .if dEnable != FALSE
            BitSet PrevTokenPriv.Privileges.Attributes, SE_PRIVILEGE_ENABLED
          .else
            BitClr PrevTokenPriv.Privileges.Attributes, SE_PRIVILEGE_ENABLED
          .endif
          invoke TypeAdjustTokenPrivileges ptr pAdjustTokenPrivileges, \
                 hToken, FALSE, addr PrevTokenPriv, dReturnLenght, NULL, NULL
        .endif
      .endif
      mov ebx, eax                                    ;Save result value
      invoke CloseHandle, hToken                      ;Close the handle
      invoke FreeLibrary, hLibrary                    ;Free Advapi32 library
      mov eax, ebx                                    ;Restore result value
    .endif
  .endif
  ret
SetPrivilegeTokenA endp

end
