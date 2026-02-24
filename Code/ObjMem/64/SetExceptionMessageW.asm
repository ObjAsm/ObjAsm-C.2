; ==================================================================================================
; Title:      SetExceptionMessageW.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, February 2026
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMemWin.cop

externdef hInstance:HANDLE

CStrW wHexComma, "h, ", 9
CStrW wHexCommaNewLine, "h, ", 13, 10

.data?
cExUserMessage    CHRW 64 DUP (?)
cExUserTitle      CHRW 64 DUP (?)
pCallbackW        POINTER    ?
hCBTProcW         HANDLE     ?

pPrevUnhandledExceptionFilterW  POINTER  ?

.code
align ALIGN_CODE
CBTProcW proc dCode:DWORD, wParam:WPARAM, lParam:LPARAM
  .if dCode == HCBT_ACTIVATE
    invoke GetDlgItem, wParam, IDCANCEL
    invoke SetWindowTextW, rax, $OfsCStrW("&Exit")
    invoke GetDlgItem, wParam, IDOK
    invoke SetWindowTextW, rax, $OfsCStrW("&Copy && Exit")
    invoke UnhookWindowsHookEx, hCBTProcW
    xor eax, eax
  .else
    invoke CallNextHookEx, hCBTProcW, dCode, wParam, lParam
  .endif
  ret
CBTProcW endp

CpuFlagTest macro BitPos:req, FlagStr:req
  bt eax, BitPos
  jnc @F
  FillStringW [rcx], <FlagStr>
  add rcx, 6
@@:
endm

align ALIGN_CODE
FinalExceptionHandlerW proc uses rbx rdi rsi pExceptInfo:ptr EXCEPTION_POINTERS
  local cExceptionBuffer[512]:CHRW
  local cExceptionMsg[1024]:CHRW

  ;Execute previous filter
  mov rax, [pPrevUnhandledExceptionFilterW]
  .if rax != NULL
    mov rcx, pExceptInfo
    call rax
    .if eax == EXCEPTION_CONTINUE_EXECUTION
      ret
    .endif
  .endif

  ;Clean up any things in the callback, like freeing memory and handles
  .if pCallbackW != NULL
    mov rcx, pExceptInfo
    call pCallbackW
    .if eax != 0
      mov eax, EXCEPTION_EXECUTE_HANDLER
      ret
    .endif
  .endif

  m2z CHRW ptr [cExceptionMsg]
  m2z CHRW ptr [cExceptionBuffer]
  lea rbx, cExceptionMsg

  invoke StrCCopyW, rbx, offset cExUserMessage, lengthof cExceptionMsg - 1

  invoke StrCCatW, rbx, $OfsCStrW($Esc("\nMain Module = ")), lengthof cExceptionMsg - 1
  invoke StrLengthW, rbx
  mov ecx, lengthof cExceptionMsg - 1
  sub ecx, eax
  add eax, eax
  add rax, rbx
  mov rdx, rax
  mov eax, ecx
  invoke GetModuleFileNameW, 0, rdx, eax
  invoke StrCCatW, rbx, offset wCRLF, lengthof cExceptionMsg - 1

  mov rax, pExceptInfo
  mov rdi, [rax].EXCEPTION_POINTERS.ExceptionRecord
  mov rsi, [rax].EXCEPTION_POINTERS.ContextRecord

  invoke FindModuleByAddrW, [rdi].EXCEPTION_RECORD.ExceptionAddress, addr cExceptionBuffer

  ;Create the output text
  invoke StrCCatW, rbx, $OfsCStrW($Esc("\nModule = ")), lengthof cExceptionMsg - 1
  invoke StrCCatW, rbx, addr cExceptionBuffer, lengthof cExceptionMsg - 1

  invoke StrCCatW, rbx, $OfsCStrW($Esc("\nException Type = ")), lengthof cExceptionMsg - 1
  invoke GetExceptionStrW, [rdi].EXCEPTION_RECORD.ExceptionCode
  invoke StrCCatW, rbx, rax, lengthof cExceptionMsg - 1

  invoke qword2hexW, addr cExceptionBuffer, [rdi].EXCEPTION_RECORD.ExceptionAddress
  invoke StrCCatW, rbx, $OfsCStrW($Esc("\nException Address = ")), lengthof cExceptionMsg - 1
  invoke StrCCatW, rbx, addr cExceptionBuffer, lengthof cExceptionMsg - 1
  invoke StrCCatW, rbx, $OfsCStrW($Esc("h\n\nCPU Registers:\n")), lengthof cExceptionMsg - 1

  invoke qword2hexW, addr cExceptionBuffer, [rsi].CONTEXT.Rax_
  invoke StrCCatW, rbx, $OfsCStrW("rax = "), lengthof cExceptionMsg - 1
  invoke StrCCatW, rbx, addr cExceptionBuffer, lengthof cExceptionMsg - 1
  invoke StrCCatW, rbx, offset wHexComma, lengthof cExceptionMsg - 1
  invoke qword2hexW, addr cExceptionBuffer, [rsi].CONTEXT.Rbx_
  invoke StrCCatW, rbx, $OfsCStrW("rbx = "), lengthof cExceptionMsg - 1
  invoke StrCCatW, rbx, addr cExceptionBuffer, lengthof cExceptionMsg - 1
  invoke StrCCatW, rbx, offset wHexCommaNewLine, lengthof cExceptionMsg - 1

  invoke qword2hexW, addr cExceptionBuffer, [rsi].CONTEXT.Rcx_
  invoke StrCCatW, rbx, $OfsCStrW("rcx = "), lengthof cExceptionMsg - 1
  invoke StrCCatW, rbx, addr cExceptionBuffer, lengthof cExceptionMsg - 1
  invoke StrCCatW, rbx, offset wHexComma, lengthof cExceptionMsg - 1
  invoke qword2hexW, addr cExceptionBuffer, [rsi].CONTEXT.Rdx_
  invoke StrCCatW, rbx, $OfsCStrW("rdx = "), lengthof cExceptionMsg - 1
  invoke StrCCatW, rbx, addr cExceptionBuffer, lengthof cExceptionMsg - 1
  invoke StrCCatW, rbx, offset wHexCommaNewLine, lengthof cExceptionMsg - 1

  invoke qword2hexW, addr cExceptionBuffer, [rsi].CONTEXT.Rdi_
  invoke StrCCatW, rbx, $OfsCStrW("rdi = "), lengthof cExceptionMsg - 1
  invoke StrCCatW, rbx, addr cExceptionBuffer, lengthof cExceptionMsg - 1
  invoke StrCCatW, rbx, offset wHexComma, lengthof cExceptionMsg - 1
  invoke qword2hexW, addr cExceptionBuffer, [rsi].CONTEXT.Rsi_
  invoke StrCCatW, rbx, $OfsCStrW("rsi = "), lengthof cExceptionMsg - 1
  invoke StrCCatW, rbx, addr cExceptionBuffer, lengthof cExceptionMsg - 1
  invoke StrCCatW, rbx, offset wHexCommaNewLine, lengthof cExceptionMsg - 1

  invoke qword2hexW, addr cExceptionBuffer, [rsi].CONTEXT.Rbp_
  invoke StrCCatW, rbx, $OfsCStrW("rbp = "), lengthof cExceptionMsg - 1
  invoke StrCCatW, rbx, addr cExceptionBuffer, lengthof cExceptionMsg - 1
  invoke StrCCatW, rbx, offset wHexComma, lengthof cExceptionMsg - 1
  invoke qword2hexW, addr cExceptionBuffer, [rsi].CONTEXT.Rsp_
  invoke StrCCatW, rbx, $OfsCStrW("rsp = "), lengthof cExceptionMsg - 1
  invoke StrCCatW, rbx, addr cExceptionBuffer, lengthof cExceptionMsg - 1
  invoke StrCCatW, rbx, offset wHexCommaNewLine, lengthof cExceptionMsg - 1

  invoke qword2hexW, addr cExceptionBuffer, [rsi].CONTEXT.Rip_
  invoke StrCCatW, rbx, $OfsCStrW("rip = "), lengthof cExceptionMsg - 1
  invoke StrCCatW, rbx, addr cExceptionBuffer, lengthof cExceptionMsg - 1
  invoke StrCCatW, rbx, offset wHexCommaNewLine, lengthof cExceptionMsg - 1
  
  invoke qword2hexW, addr cExceptionBuffer, [rsi].CONTEXT.R8_
  invoke StrCCatW, rbx, $OfsCStrW("r8 = "), lengthof cExceptionMsg - 1
  invoke StrCCatW, rbx, addr cExceptionBuffer, lengthof cExceptionMsg - 1
  invoke StrCCatW, rbx, offset wHexComma, lengthof cExceptionMsg - 1
  invoke qword2hexW, addr cExceptionBuffer, [rsi].CONTEXT.R9_
  invoke StrCCatW, rbx, $OfsCStrW("r9 = "), lengthof cExceptionMsg - 1
  invoke StrCCatW, rbx, addr cExceptionBuffer, lengthof cExceptionMsg - 1
  invoke StrCCatW, rbx, offset wHexCommaNewLine, lengthof cExceptionMsg - 1

  invoke qword2hexW, addr cExceptionBuffer, [rsi].CONTEXT.R10_
  invoke StrCCatW, rbx, $OfsCStrW("r10 = "), lengthof cExceptionMsg - 1
  invoke StrCCatW, rbx, addr cExceptionBuffer, lengthof cExceptionMsg - 1
  invoke StrCCatW, rbx, offset wHexComma, lengthof cExceptionMsg - 1
  invoke qword2hexW, addr cExceptionBuffer, [rsi].CONTEXT.R11_
  invoke StrCCatW, rbx, $OfsCStrW("r11 = "), lengthof cExceptionMsg - 1
  invoke StrCCatW, rbx, addr cExceptionBuffer, lengthof cExceptionMsg - 1
  invoke StrCCatW, rbx, offset wHexCommaNewLine, lengthof cExceptionMsg - 1

  invoke qword2hexW, addr cExceptionBuffer, [rsi].CONTEXT.R12_
  invoke StrCCatW, rbx, $OfsCStrW("r12 = "), lengthof cExceptionMsg - 1
  invoke StrCCatW, rbx, addr cExceptionBuffer, lengthof cExceptionMsg - 1
  invoke StrCCatW, rbx, offset wHexComma, lengthof cExceptionMsg - 1
  invoke qword2hexW, addr cExceptionBuffer, [rsi].CONTEXT.R13_
  invoke StrCCatW, rbx, $OfsCStrW("r13 = "), lengthof cExceptionMsg - 1
  invoke StrCCatW, rbx, addr cExceptionBuffer, lengthof cExceptionMsg - 1
  invoke StrCCatW, rbx, offset wHexCommaNewLine, lengthof cExceptionMsg - 1

  invoke qword2hexW, addr cExceptionBuffer, [rsi].CONTEXT.R14_
  invoke StrCCatW, rbx, $OfsCStrW("r14 = "), lengthof cExceptionMsg - 1
  invoke StrCCatW, rbx, addr cExceptionBuffer, lengthof cExceptionMsg - 1
  invoke StrCCatW, rbx, offset wHexComma, lengthof cExceptionMsg - 1
  invoke qword2hexW, addr cExceptionBuffer, [rsi].CONTEXT.R15_
  invoke StrCCatW, rbx, $OfsCStrW("r15 = "), lengthof cExceptionMsg - 1
  invoke StrCCatW, rbx, addr cExceptionBuffer, lengthof cExceptionMsg - 1
  invoke StrCCatW, rbx, offset wHexCommaNewLine, lengthof cExceptionMsg - 1

  invoke dword2hexW, addr cExceptionBuffer, [rsi].CONTEXT.SegGs
  invoke StrCCatW, rbx, $OfsCStrW("GS = "), lengthof cExceptionMsg - 1
  invoke StrCCatW, rbx, addr cExceptionBuffer, lengthof cExceptionMsg - 1
  invoke StrCCatW, rbx, offset wHexComma, lengthof cExceptionMsg - 1
  invoke dword2hexW, addr cExceptionBuffer, [rsi].CONTEXT.SegFs
  invoke StrCCatW, rbx, $OfsCStrW("FS = "), lengthof cExceptionMsg - 1
  invoke StrCCatW, rbx, addr cExceptionBuffer, lengthof cExceptionMsg - 1
  invoke StrCCatW, rbx, offset wHexComma, lengthof cExceptionMsg - 1
  invoke dword2hexW, addr cExceptionBuffer, [rsi].CONTEXT.SegEs
  invoke StrCCatW, rbx, $OfsCStrW("ES = "), lengthof cExceptionMsg - 1
  invoke StrCCatW, rbx, addr cExceptionBuffer, lengthof cExceptionMsg - 1
  invoke StrCCatW, rbx, offset wHexCommaNewLine, lengthof cExceptionMsg - 1

  invoke dword2hexW, addr cExceptionBuffer, [rsi].CONTEXT.SegDs
  invoke StrCCatW, rbx, $OfsCStrW("DS = "), lengthof cExceptionMsg - 1
  invoke StrCCatW, rbx, addr cExceptionBuffer, lengthof cExceptionMsg - 1
  invoke StrCCatW, rbx, offset wHexComma, lengthof cExceptionMsg - 1
  invoke dword2hexW, addr cExceptionBuffer, [rsi].CONTEXT.SegCs
  invoke StrCCatW, rbx, $OfsCStrW("CS = "), lengthof cExceptionMsg - 1
  invoke StrCCatW, rbx, addr cExceptionBuffer, lengthof cExceptionMsg - 1
  invoke StrCCatW, rbx, offset wHexComma, lengthof cExceptionMsg - 1
  invoke dword2hexW, addr cExceptionBuffer, [rsi].CONTEXT.SegSs
  invoke StrCCatW, rbx, $OfsCStrW("SS = "), lengthof cExceptionMsg - 1
  invoke StrCCatW, rbx, addr cExceptionBuffer, lengthof cExceptionMsg - 1
  invoke StrCCatCharW, rbx, "h", lengthof cExceptionMsg - 1

  invoke StrCCatW, rbx, $OfsCStrW($Esc("\n\nCPU Flags:   ")), lengthof cExceptionMsg - 1

  ;Build the CPU Flags string
  lea rcx, cExceptionBuffer
  m2z WORD ptr [rcx]
  mov eax, [rsi].CONTEXT.EFlags_
  CpuFlagTest 00, < FC>
  CpuFlagTest 02, < FP>
  CpuFlagTest 04, < FA>
  CpuFlagTest 06, < FZ>
  CpuFlagTest 07, < FS>
  CpuFlagTest 08, < FT>
  CpuFlagTest 09, < FI>
  CpuFlagTest 10, < FD>
  CpuFlagTest 11, < FO>
  m2z WORD ptr [rcx]
  invoke StrCCatW, rbx, addr cExceptionBuffer, lengthof cExceptionMsg - 1

  invoke StrCCatW, rbx, offset wCRLF, lengthof cExceptionMsg - 1

  ;MessageBox customization
  invoke GetCurrentThreadId
  invoke SetWindowsHookEx, WH_CBT, offset CBTProcW, hInstance, eax
  mov hCBTProcW, rax
  invoke MessageBoxW, 0, rbx, offset cExUserTitle, \
         MB_ICONERROR + MB_OKCANCEL + MB_APPLMODAL + MB_TOPMOST + MB_SETFOREGROUND + MB_DEFBUTTON2
  .if eax == IDOK                                     ;"Copy and Exit" was pressed
    invoke StrSizeW, rbx
    invoke GlobalAlloc, GMEM_MOVEABLE, eax            ;rax = Memory HANDLE = HGLOBAL
    .if rax != 0
      mov rdi, rax
      invoke GlobalLock, rdi                          ;rax -> Memory 
      invoke StrCopyW, rax, rbx                       ;Copy string to memory
      invoke GlobalUnlock, rdi
      invoke OpenClipboard, 0
      invoke EmptyClipboard
      invoke SetClipboardData, CF_TEXT, rdi
      invoke CloseClipboard
    .endif
  .endif

  mov eax, EXCEPTION_EXECUTE_HANDLER                  ;Terminate the application
  ret
FinalExceptionHandlerW endp

; --------------------------------------------------------------------------------------------------
; Procedure:  SetExceptionMessageW
; Purpose:    Install a final exception handler that displays a messagebox showing detailed exception
;             information and a user text.
; Arguments:  Arg1: -> User WIDE message string.
;             Arg2: -> Messagebox WIDE title string.
;             Arg3: -> Callback procedure fired when an exception reaches the final handler.
;                   If the callback returns zero, the messagebox is displayed, otherwise
;                   EXCEPTION_EXECUTE_HANDLER is passed to the OS without showing the messagebox.
;                   If this parameter is NULL, the messgebox is displayed.
; Return:     Nothing.

align ALIGN_CODE
SetExceptionMessageW proc pMessageW:POINTER, pTitleW:POINTER, pCallbackFunc:POINTER
  ;Because the exception handler is not set up at this point, we have to
  ;be especially careful so verify the pointers before using them.
  .if $invoke(IsBadStringPtr, pMessageW, 1) == FALSE
    invoke StrCCopyW, offset cExUserMessage, pMessageW, \
                      lengthof cExUserMessage - lengthof wCRLF - 1
    invoke StrCatW, offset cExUserMessage, offset wCRLF
  .else
    invoke StrCopyW, offset cExUserMessage, \
                     $OfsCStrW($Esc("An unrecoverable exception has occurred\n"))
  .endif

  .if $invoke(IsBadStringPtr, pTitleW, 1) == FALSE
    invoke StrCCopyW, offset cExUserTitle, pTitleW, lengthof cExUserTitle - 1
  .else
    invoke StrCopyW, offset cExUserTitle, $OfsCStrW("Exception report")
  .endif

  .if $invoke(IsBadCodePtr, pCallbackFunc) == FALSE
    m2m pCallbackW, pCallbackFunc, rax
  .else
    m2z pCallbackW
  .endif

  invoke SetUnhandledExceptionFilter, offset FinalExceptionHandlerW
  mov pPrevUnhandledExceptionFilterW, rax

  ret
SetExceptionMessageW endp

end