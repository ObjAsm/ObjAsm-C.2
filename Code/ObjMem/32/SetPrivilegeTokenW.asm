; ==================================================================================================
; Title:      SetPrivilegeTokenW.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
% include &ObjMemPath&ObjMemWin.cop

TypeOpenProcessToken      typedef proto :HANDLE, :DWORD, :POINTER
TypeLookupPrivilegeValueW typedef proto :POINTER, :POINTER, :POINTER
TypeAdjustTokenPrivileges typedef proto :HANDLE, :DWORD, :POINTER, :DWORD, :POINTER, :POINTER

; --------------------------------------------------------------------------------------------------
; Procedure:  SetPrivilegeTokenW
; Purpose:    Enable privilege tokens.
; Arguments:  Arg1: Process handle.
;             Arg2: -> Privilege name (ANSI string).
;             Arg3: Eanble = TRUE, disable = FALSE
; Return:     eax = Zero if failed.

.code
align ALIGN_CODE
SetPrivilegeTokenW proc hProcess:HANDLE, pPrivilegeNameW:POINTER, dEnable:DWORD
  local TokenPriv:TOKEN_PRIVILEGES, PrevTokenPriv:TOKEN_PRIVILEGES
  local luid:LUID, hToken:HANDLE, dReturnLenght:DWORD
  local hLibrary:HANDLE
  local pOpenProcessToken:POINTER, pLookupPrivilegeValue:POINTER, pAdjustTokenPrivileges:POINTER

  .if $invoke(IsWinNT) != FALSE
    invoke LoadLibraryW, $OfsCStrW("Advapi32.dll")
    .if eax != 0
      mov hLibrary, eax

      ;Load the NT only functions
      invoke GetProcAddress, hLibrary, $OfsCStrA("OpenProcessToken")
      mov pOpenProcessToken, eax
      invoke GetProcAddress, hLibrary, $OfsCStrA("LookupPrivilegeValueW")
      mov pLookupPrivilegeValue, eax
      invoke GetProcAddress, hLibrary, $OfsCStrA("AdjustTokenPrivileges")
      mov pAdjustTokenPrivileges, eax

      ;Get the token for this process
      invoke TypeOpenProcessToken ptr pOpenProcessToken, \
             hProcess, TOKEN_ADJUST_PRIVILEGES or TOKEN_QUERY, addr hToken

      invoke TypeLookupPrivilegeValueW ptr pLookupPrivilegeValue, NULL, pPrivilegeNameW, addr luid
      .if eax != 0
        ;Get current privilege setting
        mov TokenPriv.PrivilegeCount, 1
        m2m TokenPriv.Privileges.Luid.LowPart, luid.LowPart, eax
        m2m TokenPriv.Privileges.Luid.HighPart, luid.HighPart, ecx
        m2z TokenPriv.Privileges.Attributes
        invoke TypeAdjustTokenPrivileges ptr pAdjustTokenPrivileges, hToken, FALSE, \
               addr TokenPriv, sizeof TokenPriv, addr PrevTokenPriv, addr dReturnLenght
        .if eax != 0
          ;Set privilege based on previous setting
          mov PrevTokenPriv.PrivilegeCount, 1
          mrm PrevTokenPriv.Privileges.Luid.LowPart, luid.LowPart, eax
          mrm PrevTokenPriv.Privileges.Luid.HighPart, luid.HighPart, eax
          .if dEnable != FALSE
            BitSet PrevTokenPriv.Privileges.Attributes, SE_PRIVILEGE_ENABLED
          .else
            BitClr PrevTokenPriv.Privileges.Attributes, SE_PRIVILEGE_ENABLED
          .endif
          invoke TypeAdjustTokenPrivileges ptr pAdjustTokenPrivileges, \
                 hToken, FALSE, addr PrevTokenPriv, dReturnLenght, NULL, NULL
        .endif
      .endif
      push eax                                          ;Save result value
      invoke CloseHandle, hToken                        ;Close the handle
      invoke FreeLibrary, hLibrary                      ;Free Advapi32 library
      pop eax                                           ;Restore result value
    .endif
  .endif
  ret
SetPrivilegeTokenW endp

end
