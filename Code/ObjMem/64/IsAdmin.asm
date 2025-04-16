; ==================================================================================================
; Title:      IsAdmin.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMemWin.cop

; --------------------------------------------------------------------------------------------------
; Procedure:  IsAdmin
; Purpose:    Check if the current user has administrator rights.
; Arguments:  None.
; Return:     rax = TRUE or FALSE.

.code
align ALIGN_CODE
IsAdmin proc uses rbx rdi rsi
  local hCurrentThread:HANDLE, hAccessToken:HANDLE, hCurrentProcess:HANDLE
  local dInfoBufferSize:DWORD, pInfoBuffer:POINTER, qSuccess:QWORD
  local psidAdministrators:POINTER
  local siaNtAuthority:SID_IDENTIFIER_AUTHORITY

  mov hCurrentThread, $invoke(GetCurrentThread)
  invoke OpenThreadToken, hCurrentThread, TOKEN_QUERY, TRUE, addr hAccessToken
  .if eax == 0
    invoke GetLastError
    .if eax != ERROR_NO_TOKEN
      xor eax, eax
      ret
    .endif
    mov hCurrentProcess, $invoke(GetCurrentProcess)
    invoke OpenProcessToken, hCurrentProcess, TOKEN_QUERY, addr hAccessToken
    .if rax == FALSE
      ret
    .endif
  .endif
  invoke GetTokenInformation, hAccessToken, TokenGroups, NULL, NULL, addr dInfoBufferSize
  .if dInfoBufferSize > 0
    invoke GlobalAlloc, GMEM_FIXED, dInfoBufferSize
    mov pInfoBuffer, rax
    invoke GetTokenInformation, hAccessToken, TokenGroups, pInfoBuffer, \
                                dInfoBufferSize, addr dInfoBufferSize
  .endif
  mov qSuccess, rax
  invoke CloseHandle, hAccessToken

  .if qSuccess == FALSE
    xor eax, eax
    ret
  .endif

  ;Copy SECURITY_NT_AUTHORITY into siaNtAuthority
  m2z DWORD ptr [siaNtAuthority]
  mov WORD ptr [siaNtAuthority + 4], 500h

  invoke AllocateAndInitializeSid, addr siaNtAuthority, 2, \
                                   SECURITY_BUILTIN_DOMAIN_RID, DOMAIN_ALIAS_RID_ADMINS, \
                                   0, 0, 0, 0, 0, 0, addr psidAdministrators
  .if rax == FALSE
    ret
  .endif

  m2z qSuccess

  mov rbx, pInfoBuffer
  mov ecx, TOKEN_GROUPS.GroupCount[rbx]
  xor rsi, rsi
  .while rsi < rcx
    mov rdi, rcx
    mov rdx, TOKEN_GROUPS.Groups.Sid[rbx]
    mov rax, sizeof(TOKEN_GROUPS.Groups)
    xor ecx, ecx
    mul esi        ;eax * esi -> eax
    add rdx, rax
    invoke EqualSid, psidAdministrators, rdx
    mov rcx, rdi
    .if rax != 0
      mov qSuccess, TRUE
      .break
    .endif
    inc rsi
  .endw
  invoke FreeSid, psidAdministrators
  invoke GlobalFree, pInfoBuffer
  mov rax, qSuccess
  ret
IsAdmin endp

end
