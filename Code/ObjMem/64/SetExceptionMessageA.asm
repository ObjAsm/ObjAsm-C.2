; ==================================================================================================
; Title:      SetExceptionMessageA.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, February 2026
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMemWin.cop

externdef hInstance:HANDLE

CStrA bHexComma, "h, ", 9
CStrA bHexCommaNewLine, "h, ", 13, 10

.data?
cExUserMessage    CHRA 64 DUP (?)
cExUserTitle      CHRA 64 DUP (?)
pCallbackA        POINTER    ?
hCBTProcA         HANDLE     ?

pPrevUnhandledExceptionFilterA  POINTER  ?

.code
align ALIGN_CODE
CBTProcA proc dCode:DWORD, wParam:WPARAM, lParam:LPARAM
  .if dCode == HCBT_ACTIVATE
    invoke GetDlgItem, wParam, IDCANCEL
    invoke SetWindowTextA, rax, $OfsCStrA("&Exit")
    invoke GetDlgItem, wParam, IDOK
    invoke SetWindowTextA, rax, $OfsCStrA("&Copy && Exit")
    invoke UnhookWindowsHookEx, hCBTProcA
    xor eax, eax
  .else
    invoke CallNextHookEx, hCBTProcA, dCode, wParam, lParam
  .endif
  ret
CBTProcA endp

CpuFlagTest macro BitPos:req, FlagStr:req
  bt eax, BitPos
  jnc @F
  FillStringA [rcx], <FlagStr>
  add rcx, 3
@@:
endm

align ALIGN_CODE
FinalExceptionHandlerA proc uses rbx rdi rsi pExceptInfo:ptr EXCEPTION_POINTERS
  local cExceptionBuffer[512]:CHRA
  local cExceptionMsg[1024]:CHRA

  ;Execute previous filter
  mov rax, [pPrevUnhandledExceptionFilterA]
  .if rax != NULL
    mov rcx, pExceptInfo
    call rax
    .if eax == EXCEPTION_CONTINUE_EXECUTION
      ret
    .endif
  .endif

  ;Clean up any things in the callback, like freeing memory and handles
  .if pCallbackA != NULL
    mov rcx, pExceptInfo
    call pCallbackA
    .if eax != 0
      mov eax, EXCEPTION_EXECUTE_HANDLER
      ret
    .endif
  .endif

  m2z CHRA ptr [cExceptionMsg]
  m2z CHRA ptr [cExceptionBuffer]
  lea rbx, cExceptionMsg

  invoke StrCCopyA, rbx, offset cExUserMessage, lengthof cExceptionMsg - 1

  invoke StrCCatA, rbx, $OfsCStrA($Esc("\nMain Module = ")), lengthof cExceptionMsg - 1
  invoke StrLengthA, rbx
  mov ecx, lengthof cExceptionMsg - 1
  sub ecx, eax
  add rax, rbx
  mov rdx, rax
  mov eax, ecx
  invoke GetModuleFileNameA, 0, rdx, eax
  invoke StrCCatA, rbx, offset bCRLF, lengthof cExceptionMsg - 1

  mov rax, pExceptInfo
  mov rdi, [rax].EXCEPTION_POINTERS.ExceptionRecord
  mov rsi, [rax].EXCEPTION_POINTERS.ContextRecord

  invoke FindModuleByAddrA, [rdi].EXCEPTION_RECORD.ExceptionAddress, addr cExceptionBuffer

  ;Create the output text
  invoke StrCCatA, rbx, $OfsCStrA($Esc("\nModule = ")), lengthof cExceptionMsg - 1
  invoke StrCCatA, rbx, addr cExceptionBuffer, lengthof cExceptionMsg - 1

  invoke StrCCatA, rbx, $OfsCStrA($Esc("\nException Type = ")), lengthof cExceptionMsg - 1
  invoke GetExceptionStrA, [rdi].EXCEPTION_RECORD.ExceptionCode
  invoke StrCCatA, rbx, rax, lengthof cExceptionMsg - 1

  invoke qword2hexA, addr cExceptionBuffer, [rdi].EXCEPTION_RECORD.ExceptionAddress
  invoke StrCCatA, rbx, $OfsCStrA($Esc("\nException Address = ")), lengthof cExceptionMsg - 1
  invoke StrCCatA, rbx, addr cExceptionBuffer, lengthof cExceptionMsg - 1
  invoke StrCCatA, rbx, $OfsCStrA($Esc("h\n\nCPU Registers:\n")), lengthof cExceptionMsg - 1

  invoke qword2hexA, addr cExceptionBuffer, [rsi].CONTEXT.Rax_
  invoke StrCCatA, rbx, $OfsCStrA("rax = "), lengthof cExceptionMsg - 1
  invoke StrCCatA, rbx, addr cExceptionBuffer, lengthof cExceptionMsg - 1
  invoke StrCCatA, rbx, offset bHexComma, lengthof cExceptionMsg - 1
  invoke qword2hexA, addr cExceptionBuffer, [rsi].CONTEXT.Rbx_
  invoke StrCCatA, rbx, $OfsCStrA("rbx = "), lengthof cExceptionMsg - 1
  invoke StrCCatA, rbx, addr cExceptionBuffer, lengthof cExceptionMsg - 1
  invoke StrCCatA, rbx, offset bHexCommaNewLine, lengthof cExceptionMsg - 1

  invoke qword2hexA, addr cExceptionBuffer, [rsi].CONTEXT.Rcx_
  invoke StrCCatA, rbx, $OfsCStrA("rcx = "), lengthof cExceptionMsg - 1
  invoke StrCCatA, rbx, addr cExceptionBuffer, lengthof cExceptionMsg - 1
  invoke StrCCatA, rbx, offset bHexComma, lengthof cExceptionMsg - 1
  invoke qword2hexA, addr cExceptionBuffer, [rsi].CONTEXT.Rdx_
  invoke StrCCatA, rbx, $OfsCStrA("rdx = "), lengthof cExceptionMsg - 1
  invoke StrCCatA, rbx, addr cExceptionBuffer, lengthof cExceptionMsg - 1
  invoke StrCCatA, rbx, offset bHexCommaNewLine, lengthof cExceptionMsg - 1

  invoke qword2hexA, addr cExceptionBuffer, [rsi].CONTEXT.Rdi_
  invoke StrCCatA, rbx, $OfsCStrA("rdi = "), lengthof cExceptionMsg - 1
  invoke StrCCatA, rbx, addr cExceptionBuffer, lengthof cExceptionMsg - 1
  invoke StrCCatA, rbx, offset bHexComma, lengthof cExceptionMsg - 1
  invoke qword2hexA, addr cExceptionBuffer, [rsi].CONTEXT.Rsi_
  invoke StrCCatA, rbx, $OfsCStrA("rsi = "), lengthof cExceptionMsg - 1
  invoke StrCCatA, rbx, addr cExceptionBuffer, lengthof cExceptionMsg - 1
  invoke StrCCatA, rbx, offset bHexCommaNewLine, lengthof cExceptionMsg - 1

  invoke qword2hexA, addr cExceptionBuffer, [rsi].CONTEXT.Rbp_
  invoke StrCCatA, rbx, $OfsCStrA("rbp = "), lengthof cExceptionMsg - 1
  invoke StrCCatA, rbx, addr cExceptionBuffer, lengthof cExceptionMsg - 1
  invoke StrCCatA, rbx, offset bHexComma, lengthof cExceptionMsg - 1
  invoke qword2hexA, addr cExceptionBuffer, [rsi].CONTEXT.Rsp_
  invoke StrCCatA, rbx, $OfsCStrA("rsp = "), lengthof cExceptionMsg - 1
  invoke StrCCatA, rbx, addr cExceptionBuffer, lengthof cExceptionMsg - 1
  invoke StrCCatA, rbx, offset bHexCommaNewLine, lengthof cExceptionMsg - 1

  invoke qword2hexA, addr cExceptionBuffer, [rsi].CONTEXT.Rip_
  invoke StrCCatA, rbx, $OfsCStrA("rip = "), lengthof cExceptionMsg - 1
  invoke StrCCatA, rbx, addr cExceptionBuffer, lengthof cExceptionMsg - 1
  invoke StrCCatA, rbx, offset bHexCommaNewLine, lengthof cExceptionMsg - 1
  
  invoke qword2hexA, addr cExceptionBuffer, [rsi].CONTEXT.R8_
  invoke StrCCatA, rbx, $OfsCStrA("r8 = "), lengthof cExceptionMsg - 1
  invoke StrCCatA, rbx, addr cExceptionBuffer, lengthof cExceptionMsg - 1
  invoke StrCCatA, rbx, offset bHexComma, lengthof cExceptionMsg - 1
  invoke qword2hexA, addr cExceptionBuffer, [rsi].CONTEXT.R9_
  invoke StrCCatA, rbx, $OfsCStrA("r9 = "), lengthof cExceptionMsg - 1
  invoke StrCCatA, rbx, addr cExceptionBuffer, lengthof cExceptionMsg - 1
  invoke StrCCatA, rbx, offset bHexCommaNewLine, lengthof cExceptionMsg - 1

  invoke qword2hexA, addr cExceptionBuffer, [rsi].CONTEXT.R10_
  invoke StrCCatA, rbx, $OfsCStrA("r10 = "), lengthof cExceptionMsg - 1
  invoke StrCCatA, rbx, addr cExceptionBuffer, lengthof cExceptionMsg - 1
  invoke StrCCatA, rbx, offset bHexComma, lengthof cExceptionMsg - 1
  invoke qword2hexA, addr cExceptionBuffer, [rsi].CONTEXT.R11_
  invoke StrCCatA, rbx, $OfsCStrA("r11 = "), lengthof cExceptionMsg - 1
  invoke StrCCatA, rbx, addr cExceptionBuffer, lengthof cExceptionMsg - 1
  invoke StrCCatA, rbx, offset bHexCommaNewLine, lengthof cExceptionMsg - 1

  invoke qword2hexA, addr cExceptionBuffer, [rsi].CONTEXT.R12_
  invoke StrCCatA, rbx, $OfsCStrA("r12 = "), lengthof cExceptionMsg - 1
  invoke StrCCatA, rbx, addr cExceptionBuffer, lengthof cExceptionMsg - 1
  invoke StrCCatA, rbx, offset bHexComma, lengthof cExceptionMsg - 1
  invoke qword2hexA, addr cExceptionBuffer, [rsi].CONTEXT.R13_
  invoke StrCCatA, rbx, $OfsCStrA("r13 = "), lengthof cExceptionMsg - 1
  invoke StrCCatA, rbx, addr cExceptionBuffer, lengthof cExceptionMsg - 1
  invoke StrCCatA, rbx, offset bHexCommaNewLine, lengthof cExceptionMsg - 1

  invoke qword2hexA, addr cExceptionBuffer, [rsi].CONTEXT.R14_
  invoke StrCCatA, rbx, $OfsCStrA("r14 = "), lengthof cExceptionMsg - 1
  invoke StrCCatA, rbx, addr cExceptionBuffer, lengthof cExceptionMsg - 1
  invoke StrCCatA, rbx, offset bHexComma, lengthof cExceptionMsg - 1
  invoke qword2hexA, addr cExceptionBuffer, [rsi].CONTEXT.R15_
  invoke StrCCatA, rbx, $OfsCStrA("r15 = "), lengthof cExceptionMsg - 1
  invoke StrCCatA, rbx, addr cExceptionBuffer, lengthof cExceptionMsg - 1
  invoke StrCCatA, rbx, offset bHexCommaNewLine, lengthof cExceptionMsg - 1

  invoke dword2hexA, addr cExceptionBuffer, [rsi].CONTEXT.SegGs
  invoke StrCCatA, rbx, $OfsCStrA("GS = "), lengthof cExceptionMsg - 1
  invoke StrCCatA, rbx, addr cExceptionBuffer, lengthof cExceptionMsg - 1
  invoke StrCCatA, rbx, offset bHexComma, lengthof cExceptionMsg - 1
  invoke dword2hexA, addr cExceptionBuffer, [rsi].CONTEXT.SegFs
  invoke StrCCatA, rbx, $OfsCStrA("FS = "), lengthof cExceptionMsg - 1
  invoke StrCCatA, rbx, addr cExceptionBuffer, lengthof cExceptionMsg - 1
  invoke StrCCatA, rbx, offset bHexComma, lengthof cExceptionMsg - 1
  invoke dword2hexA, addr cExceptionBuffer, [rsi].CONTEXT.SegEs
  invoke StrCCatA, rbx, $OfsCStrA("ES = "), lengthof cExceptionMsg - 1
  invoke StrCCatA, rbx, addr cExceptionBuffer, lengthof cExceptionMsg - 1
  invoke StrCCatA, rbx, offset bHexCommaNewLine, lengthof cExceptionMsg - 1

  invoke dword2hexA, addr cExceptionBuffer, [rsi].CONTEXT.SegDs
  invoke StrCCatA, rbx, $OfsCStrA("DS = "), lengthof cExceptionMsg - 1
  invoke StrCCatA, rbx, addr cExceptionBuffer, lengthof cExceptionMsg - 1
  invoke StrCCatA, rbx, offset bHexComma, lengthof cExceptionMsg - 1
  invoke dword2hexA, addr cExceptionBuffer, [rsi].CONTEXT.SegCs
  invoke StrCCatA, rbx, $OfsCStrA("CS = "), lengthof cExceptionMsg - 1
  invoke StrCCatA, rbx, addr cExceptionBuffer, lengthof cExceptionMsg - 1
  invoke StrCCatA, rbx, offset bHexComma, lengthof cExceptionMsg - 1
  invoke dword2hexA, addr cExceptionBuffer, [rsi].CONTEXT.SegSs
  invoke StrCCatA, rbx, $OfsCStrA("SS = "), lengthof cExceptionMsg - 1
  invoke StrCCatA, rbx, addr cExceptionBuffer, lengthof cExceptionMsg - 1
  invoke StrCCatCharA, rbx, "h", lengthof cExceptionMsg - 1

  invoke StrCCatA, rbx, $OfsCStrA($Esc("\n\nCPU Flags:   ")), lengthof cExceptionMsg - 1

  ;Build the CPU Flags string
  lea rcx, cExceptionBuffer
  m2z BYTE ptr [rcx]
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
  m2z BYTE ptr [rcx]
  invoke StrCCatA, rbx, addr cExceptionBuffer, lengthof cExceptionMsg - 1

  invoke StrCCatA, rbx, offset bCRLF, lengthof cExceptionMsg - 1

  ;MessageBox customization
  invoke GetCurrentThreadId
  invoke SetWindowsHookEx, WH_CBT, offset CBTProcA, hInstance, eax
  mov hCBTProcA, rax
  invoke MessageBoxA, 0, rbx, offset cExUserTitle, \
         MB_ICONERROR + MB_OKCANCEL + MB_APPLMODAL + MB_TOPMOST + MB_SETFOREGROUND + MB_DEFBUTTON2
  .if eax == IDOK                                     ;"Copy and Exit" was pressed
    invoke StrSizeA, rbx
    invoke GlobalAlloc, GMEM_MOVEABLE, eax            ;rax = Memory HANDLE = HGLOBAL
    .if rax != 0
      mov rdi, rax
      invoke GlobalLock, rdi                          ;rax -> Memory 
      invoke StrCopyA, rax, rbx                       ;Copy string to memory
      invoke GlobalUnlock, rdi
      invoke OpenClipboard, 0
      invoke EmptyClipboard
      invoke SetClipboardData, CF_TEXT, rdi
      invoke CloseClipboard
    .endif
  .endif

  mov eax, EXCEPTION_EXECUTE_HANDLER                  ;Terminate the application
  ret
FinalExceptionHandlerA endp

; --------------------------------------------------------------------------------------------------
; Procedure:  SetExceptionMessageA
; Purpose:    Install a final exception handler that displays a messagebox showing detailed exception
;             information and a user text.
; Arguments:  Arg1: -> User ANSI message string.
;             Arg2: -> Messagebox ANSI title string.
;             Arg3: -> Callback procedure fired when an exception reaches the final handler.
;                   If the callback returns zero, the messagebox is displayed, otherwise
;                   EXCEPTION_EXECUTE_HANDLER is passed to the OS without showing the messagebox.
;                   If this parameter is NULL, the messgebox is displayed.
; Return:     Nothing.

align ALIGN_CODE
SetExceptionMessageA proc pMessageA:POINTER, pTitleA:POINTER, pCallbackFunc:POINTER
  ;Because the exception handler is not set up at this point, we have to
  ;be especially careful so verify the pointers before using them.
  .if $invoke(IsBadStringPtr, pMessageA, 1) == FALSE
    invoke StrCCopyA, offset cExUserMessage, pMessageA, \
                      lengthof cExUserMessage - lengthof bCRLF - 1
    invoke StrCatA, offset cExUserMessage, offset bCRLF
  .else
    invoke StrCopyA, offset cExUserMessage, \
                     $OfsCStrA($Esc("An unrecoverable exception has occurred\n"))
  .endif

  .if $invoke(IsBadStringPtr, pTitleA, 1) == FALSE
    invoke StrCCopyA, offset cExUserTitle, pTitleA, lengthof cExUserTitle - 1
  .else
    invoke StrCopyA, offset cExUserTitle, $OfsCStrA("Exception report")
  .endif

  .if $invoke(IsBadCodePtr, pCallbackFunc) == FALSE
    m2m pCallbackA, pCallbackFunc, rax
  .else
    m2z pCallbackA
  .endif

  invoke SetUnhandledExceptionFilter, offset FinalExceptionHandlerA
  mov pPrevUnhandledExceptionFilterA, rax

  ret
SetExceptionMessageA endp

end
