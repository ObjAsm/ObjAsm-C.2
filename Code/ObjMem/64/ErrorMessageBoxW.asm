; ==================================================================================================
; Title:      ErrorMessageBoxW.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMemWin.cop

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  ErrorMessageBoxW
; Purpose:    Show a messagebox containing an error string in the locale lenguage and an user string.
; Arguments:  Arg1: Messagebox parent window HANDLE.
;             Arg2: -> User WIDE string.
;             Arg3: Locale ID.
;             Arg4: API error code. 
; Return:     Nothing.

.code
align ALIGN_CODE
ErrorMessageBoxW proc uses rbx rdi rsi hWnd:HWND, pUserMsgW:POINTER, wLangID:WORD, dErrorCode:DWORD
  local pBuffer:POINTER

  invoke FormatMessageW, FORMAT_MESSAGE_ALLOCATE_BUFFER or FORMAT_MESSAGE_FROM_SYSTEM, \
                         NULL, dErrorCode, 0, addr pBuffer, 0, 0
  .if rax != 0
    add rax, rax
    mov rbx, rax
    invoke StrLengthW, pUserMsgW
    add rax, rax
    mov rdi, rax
    add rax, rbx
    add rax, 9                                      ;4 + 2 + 3 = CRLF + Zero + rounding
    and rax, 0FFFFFFFFFFFFFFFCh                     ;Reset the last 2 bits
    neg rax
    mov rcx, -PAGESIZE
    .while SQWORD ptr rcx >= rax                    ;Stack probing
      m2z BYTE ptr [rsp + rcx]
      sub rcx, PAGESIZE
    .endw
    mov rcx, rbx                                    ;rcx = 2*length(UserMessage)
    sub rsp, rax
    mov rbx, rsp
    mov rdi, rax
    lea rax, [rbx + rcx + 4]
    mov rsi, rax
    mov r8, rcx
    invoke MemClone, rbx, pUserMsgW, r8d
    mov DCHRW ptr [rsi - 4], 256*256*10 + 13        ;CR + LF
    invoke StrCopyW, rax, pBuffer
    invoke LocalFree, pBuffer
    invoke MessageBoxExW, hWnd, rbx, offset wError, \
                          MB_ICONERROR + MB_OK + MB_APPLMODAL + MB_TOPMOST + MB_SETFOREGROUND, \
                          wLangID
    add rsp, rdi                                    ;Restore stack
  .else
    invoke MessageBoxW, hWnd, pUserMsgW, offset wError, \
                        MB_ICONERROR + MB_OK + MB_APPLMODAL + MB_TOPMOST + MB_SETFOREGROUND
  .endif
  ret
ErrorMessageBoxW endp 

end
