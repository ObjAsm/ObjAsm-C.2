; ==================================================================================================
; Title:      ErrorMessageBoxA.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMemWin.cop

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  ErrorMessageBoxA
; Purpose:    Show a messagebox containing an error string in the locale lenguage and an user string.
; Arguments:  Arg1: Messagebox parent window HANDLE.
;             Arg2: -> User ANSI string.
;             Arg3: Locale ID.
;             Arg4: API error code. 
; Return:     Nothing.

.code
align ALIGN_CODE
ErrorMessageBoxA proc uses rbx rdi rsi hWnd:HWND, pUserMsgA:POINTER, wLangID:WORD, dErrorCode:DWORD
  local pBuffer:POINTER

  invoke FormatMessageA, FORMAT_MESSAGE_ALLOCATE_BUFFER or FORMAT_MESSAGE_FROM_SYSTEM, \
                         NULL, dErrorCode, 0, addr pBuffer, 0, 0
  .if rax != 0
    mov rbx, rax
    invoke StrLengthA, pUserMsgA
    mov rdi, rax
    add rax, rbx
    add rax, 4                                          ;2 + 1 + 3 = CRLF + Zero + rounding
    and rax, 0FFFFFFFFFFFFFFFCh                         ;Reset the last 2 bits
    neg rax
    mov rcx, -PAGESIZE
    .while SQWORD ptr rcx >= rax                        ;Stack probing
      m2z BYTE ptr [rsp + rcx]
      sub rcx, PAGESIZE
    .endw
    mov rcx, rdi                                        ;rcx = length(UserMessage)
    sub rsp, rax
    mov rbx, rsp
    mov rdi, rax
    lea rax, [rbx + rcx + 2]
    mov rsi, rax
    mov r8, rcx
    invoke MemClone, rbx, pUserMsgA, r8d
    mov DCHRA ptr [rsi - 2], 256*10 + 13                ;CR + LF
    invoke StrCopyA, rax, pBuffer
    invoke LocalFree, pBuffer
    invoke MessageBoxExA, hWnd, rbx, offset bError, \
                          MB_ICONERROR + MB_OK + MB_APPLMODAL + MB_TOPMOST + MB_SETFOREGROUND, \
                          wLangID
    add rsp, rdi                                        ;Restore stack
  .else
    invoke MessageBoxA, hWnd, pUserMsgA, offset bError, \
                        MB_ICONERROR + MB_OK + MB_APPLMODAL + MB_TOPMOST + MB_SETFOREGROUND
  .endif
  ret
ErrorMessageBoxA endp 

end
