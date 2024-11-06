; ==================================================================================================
; Title:      IsAdmin.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
% include &ObjMemPath&ObjMemWin.cop

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  IsAdmin
; Purpose:    Check if the current user has administrator rights.
; Arguments:  None.
; Return:     eax = TRUE or FALSE.

.code
align ALIGN_CODE
IsAdmin proc uses ebx esi
  local hCurrentThread:HANDLE, hAccessToken:HANDLE, hCurrentProcess:HANDLE
  local dInfoBufferSize:DWORD, pInfoBuffer:DWORD, bSuccess:DWORD
  local psidAdministrators:DWORD
  local siaNtAuthority:SID_IDENTIFIER_AUTHORITY

  invoke GetCurrentThread
  mov hCurrentThread, eax
  invoke OpenThreadToken, hCurrentThread, TOKEN_QUERY, TRUE, addr hAccessToken
  .if eax == 0
    invoke GetLastError
    .if eax != ERROR_NO_TOKEN
      xor eax, eax
      ret
    .endif
    invoke GetCurrentProcess
    mov hCurrentProcess, eax
    invoke OpenProcessToken, hCurrentProcess, TOKEN_QUERY, addr hAccessToken
    .if eax == FALSE
      ret
    .endif
  .endif
  invoke GetTokenInformation, hAccessToken, TokenGroups, NULL, NULL, addr dInfoBufferSize
  .if dInfoBufferSize > 0
    invoke GlobalAlloc, GMEM_FIXED, dInfoBufferSize
    mov pInfoBuffer, eax
    invoke GetTokenInformation, hAccessToken, TokenGroups, pInfoBuffer, dInfoBufferSize, \
                                addr dInfoBufferSize
  .endif
  mov bSuccess, eax
  invoke CloseHandle, hAccessToken

  .if bSuccess == FALSE
    xor eax, eax
    ret
  .endif

  ;Copy SECURITY_NT_AUTHORITY into siaNtAuthority
  m2z DWORD ptr [siaNtAuthority]
  mov WORD ptr [siaNtAuthority + 4], 500h

  invoke AllocateAndInitializeSid, addr siaNtAuthority, 2, SECURITY_BUILTIN_DOMAIN_RID, \
                                   DOMAIN_ALIAS_RID_ADMINS, 0, 0, 0, 0, 0, 0, \
                                   addr psidAdministrators
  .if eax == FALSE
    ret
  .endif

  m2z bSuccess

  mov ebx, pInfoBuffer
  mov ecx, TOKEN_GROUPS.GroupCount[ebx]
  xor esi, esi
  .while esi < ecx
    push esi
    push ecx
    mov ecx, TOKEN_GROUPS.Groups.Sid[ebx]
    mov eax, sizeof TOKEN_GROUPS.Groups
    xor edx, edx
    mul esi        ;eax * esi -> eax
    add ecx, eax
    invoke EqualSid, psidAdministrators, ecx
    pop ecx
    pop esi
    .if eax != 0
      mov bSuccess, TRUE
      .break
    .endif
    inc  esi
  .endw
  invoke FreeSid, psidAdministrators
  invoke GlobalFree, pInfoBuffer
  mov eax, bSuccess
  ret
IsAdmin endp

end
