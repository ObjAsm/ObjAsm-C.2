; ==================================================================================================
; Title:      ErrorMessageBoxW.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
% include &ObjMemPath&ObjMemWin.cop

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  ErrorMessageBoxW
; Purpose:    Show a messagebox containing an error string in the locale lenguage and an user str.
; Arguments:  Arg1: Messagebox parent window HANDLE.
;             Arg2: -> User WIDE string.
;             Arg3: Locale ID.
;             Arg4: API error code.
; Return:     Nothing.

.code
align ALIGN_CODE
ErrorMessageBoxW proc uses ebx hWnd:HWND, pUserMsgW:POINTER, wLangID:WORD, dErrorCode:DWORD
  local pBuffer:POINTER

  lea ecx, pBuffer
  invoke FormatMessageW, FORMAT_MESSAGE_ALLOCATE_BUFFER or FORMAT_MESSAGE_FROM_SYSTEM or \
                         FORMAT_MESSAGE_IGNORE_INSERTS, \
                         NULL, dErrorCode, 0, ecx, 0, NULL
  .if eax != 0
    add eax, eax
    mov ebx, eax
    invoke StrLengthW, pUserMsgW
    add eax, eax
    push eax
    add eax, ebx
    add eax, 9                                          ;4 + 2 + 3 = CRLF + Zero + rounding
    and eax, 0FFFFFFFCh                                 ;Reset the last 2 bits
    neg eax
    mov ecx, -PAGESIZE
    .while SDWORD ptr ecx >= eax                        ;Stack probing
      m2z BYTE ptr [esp + ecx]
      sub ecx, PAGESIZE
    .endw
    pop ecx                                             ;ecx = 2*length(UserMessage)
    add esp, eax
    mov ebx, esp
    push eax
    lea eax, [ebx + ecx + 4]
    push eax
    invoke MemClone, ebx, pUserMsgW, ecx
    pop eax
    mov DWORD ptr [eax - 4], 256*256*10 + 13            ;CR + LF
    invoke StrCopyW, eax, pBuffer
    invoke LocalFree, pBuffer
    invoke MessageBoxExW, hWnd, ebx, offset wError, \
                          MB_ICONERROR + MB_OK + MB_APPLMODAL + MB_TOPMOST + MB_SETFOREGROUND, \
                          wLangID
    pop eax
    add esp, eax                                        ;Restore stack
  .else
    invoke MessageBoxW, hWnd, pUserMsgW, offset wError, \
                        MB_ICONERROR + MB_OK + MB_APPLMODAL + MB_TOPMOST + MB_SETFOREGROUND
  .endif
  ret
ErrorMessageBoxW endp

end
