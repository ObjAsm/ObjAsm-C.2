; ==================================================================================================
; Title:      ErrorMessageBoxA.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
% include &ObjMemPath&ObjMemWin.cop

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  ErrorMessageBoxA
; Purpose:    Show a Messagebox containing an error string in the locale language and an user str.
; Arguments:  Arg1: Messagebox parent window HANDLE.
;             Arg2: -> User ANSI string.
;             Arg3: Locale ID.
;             Arg4: API error code.
; Return:     Nothing.

.code
align ALIGN_CODE
ErrorMessageBoxA proc uses ebx hWnd:HWND, pUserMsgA:POINTER, wLangID:WORD, dErrorCode:DWORD
  local pBuffer:POINTER

  lea ecx, pBuffer
  invoke FormatMessageA, FORMAT_MESSAGE_ALLOCATE_BUFFER or FORMAT_MESSAGE_FROM_SYSTEM or \
                         FORMAT_MESSAGE_IGNORE_INSERTS, \
                         NULL, dErrorCode, 0, ecx, 0, NULL
  .if eax != 0
    mov ebx, eax
    invoke StrLengthA, pUserMsgA
    push eax
    add eax, ebx
    add eax, 4                                          ;2 + 1 + 3 = CRLF + Zero + rounding
    and eax, 0FFFFFFFCh                                 ;Reset the last 2 bits
    neg eax
    mov ecx, -PAGESIZE
    .while SDWORD ptr ecx >= eax                        ;Stack probing
      m2z BYTE ptr [esp + ecx]
      sub ecx, PAGESIZE
    .endw
    pop ecx                                             ;ecx = length(UserMessage)
    add esp, eax
    mov ebx, esp
    push eax
    lea eax, [ebx + ecx + 2]
    push eax
    invoke MemClone, ebx, pUserMsgA, ecx
    pop eax
    mov WORD ptr [eax - 2], 256*10 + 13                 ;CR + LF
    invoke StrCopyA, eax, pBuffer
    invoke LocalFree, pBuffer
    invoke MessageBoxExA, hWnd, ebx, offset bError, \
                          MB_ICONERROR + MB_OK + MB_APPLMODAL + MB_TOPMOST + MB_SETFOREGROUND, \
                          wLangID
    pop eax
    add esp, eax                                        ;Restore stack
  .else
    invoke MessageBoxA, hWnd, pUserMsgA, offset bError, \
                          MB_ICONERROR + MB_OK + MB_APPLMODAL + MB_TOPMOST + MB_SETFOREGROUND
  .endif
  ret
ErrorMessageBoxA endp

end
