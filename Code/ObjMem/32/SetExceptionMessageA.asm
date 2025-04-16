; ==================================================================================================
; Title:      SetExceptionMessageA.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
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
    invoke SetWindowTextA, eax, $OfsCStrA("&Exit")
    invoke GetDlgItem, wParam, IDOK
    invoke SetWindowTextA, eax, $OfsCStrA("&Copy && Exit")
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
  FillStringA [ecx], <FlagStr>
  add ecx, 3
@@:
endm

align ALIGN_CODE
FinalExceptionHandlerA proc uses ebx edi esi pExceptInfo:ptr EXCEPTION_POINTERS
  local cExceptionBuffer[512]:CHRA
  local cExceptionMsg[1024]:CHRA

  ;Execute previous filter
  mov eax, [pPrevUnhandledExceptionFilterA]
  .if eax != NULL
    push pExceptInfo
    call eax
    .if eax == EXCEPTION_CONTINUE_EXECUTION
      ret
    .endif
  .endif

  ;Clean up any things in the callback, like freeing memory and handles
  .if pCallbackA != NULL
    push pExceptInfo
    call pCallbackA
    .if eax != 0
      mov eax, EXCEPTION_EXECUTE_HANDLER
      ret
    .endif
  .endif

  m2z CHRA ptr [cExceptionMsg]
  m2z CHRA ptr [cExceptionBuffer]
  lea ebx, cExceptionMsg

  invoke StrCCopyA, ebx, offset cExUserMessage, lengthof cExceptionMsg - 1

  invoke StrCCatA, ebx, $OfsCStrA($Esc("\nMain Module = ")), lengthof cExceptionMsg - 1
  invoke StrLengthA, ebx
  mov ecx, lengthof cExceptionMsg - 1
  sub ecx, eax
  add eax, ebx
  invoke GetModuleFileNameA, 0, eax, ecx
  invoke StrCCatA, ebx, offset bCRLF, lengthof cExceptionMsg - 1

  mov eax, pExceptInfo
  mov edi, [eax].EXCEPTION_POINTERS.ExceptionRecord
  mov esi, [eax].EXCEPTION_POINTERS.ContextRecord

  invoke FindModuleByAddrA, [edi].EXCEPTION_RECORD.ExceptionAddress, addr cExceptionBuffer

  ;Create the output text
  invoke StrCCatA, ebx, $OfsCStrA($Esc("\nModule = ")), lengthof cExceptionMsg - 1
  invoke StrCCatA, ebx, addr cExceptionBuffer, lengthof cExceptionMsg - 1

  invoke StrCCatA, ebx, $OfsCStrA($Esc("\nException Type = ")), lengthof cExceptionMsg - 1
  invoke GetExceptionStrA, [edi].EXCEPTION_RECORD.ExceptionCode
  invoke StrCCatA, ebx, eax, lengthof cExceptionMsg - 1

  invoke dword2hexA, addr cExceptionBuffer, [edi].EXCEPTION_RECORD.ExceptionAddress
  invoke StrCCatA, ebx, $OfsCStrA($Esc("\nException Address = ")), lengthof cExceptionMsg - 1
  invoke StrCCatA, ebx, addr cExceptionBuffer, lengthof cExceptionMsg - 1
  invoke StrCCatA, ebx, $OfsCStrA($Esc("h\n\nCPU Registers:\n")), lengthof cExceptionMsg - 1
  invoke dword2hexA, addr cExceptionBuffer, [esi].CONTEXT.Eax_
  invoke StrCCatA, ebx, $OfsCStrA("eax = "), lengthof cExceptionMsg - 1
  invoke StrCCatA, ebx, addr cExceptionBuffer, lengthof cExceptionMsg - 1
  invoke StrCCatA, ebx, offset bHexComma, lengthof cExceptionMsg - 1
  invoke dword2hexA, addr cExceptionBuffer, [esi].CONTEXT.Ebx_
  invoke StrCCatA, ebx, $OfsCStrA("ebx = "), lengthof cExceptionMsg - 1
  invoke StrCCatA, ebx, addr cExceptionBuffer, lengthof cExceptionMsg - 1
  invoke StrCCatA, ebx, offset bHexComma, lengthof cExceptionMsg - 1
  invoke dword2hexA, addr cExceptionBuffer, [esi].CONTEXT.Ecx_
  invoke StrCCatA, ebx, $OfsCStrA("ecx = "), lengthof cExceptionMsg - 1
  invoke StrCCatA, ebx, addr cExceptionBuffer, lengthof cExceptionMsg - 1
  invoke StrCCatA, ebx, offset bHexCommaNewLine, lengthof cExceptionMsg - 1

  invoke dword2hexA, addr cExceptionBuffer, [esi].CONTEXT.Edx_
  invoke StrCCatA, ebx, $OfsCStrA("edx = "), lengthof cExceptionMsg - 1
  invoke StrCCatA, ebx, addr cExceptionBuffer, lengthof cExceptionMsg - 1
  invoke StrCCatA, ebx, offset bHexComma, lengthof cExceptionMsg - 1
  invoke dword2hexA, addr cExceptionBuffer, [esi].CONTEXT.Edi_
  invoke StrCCatA, ebx, $OfsCStrA("edi = "), lengthof cExceptionMsg - 1
  invoke StrCCatA, ebx, addr cExceptionBuffer, lengthof cExceptionMsg - 1
  invoke StrCCatA, ebx, offset bHexComma, lengthof cExceptionMsg - 1
  invoke dword2hexA, addr cExceptionBuffer, [esi].CONTEXT.Esi_
  invoke StrCCatA, ebx, $OfsCStrA("esi = "), lengthof cExceptionMsg - 1
  invoke StrCCatA, ebx, addr cExceptionBuffer, lengthof cExceptionMsg - 1
  invoke StrCCatA, ebx, offset bHexCommaNewLine, lengthof cExceptionMsg - 1

  invoke dword2hexA, addr cExceptionBuffer, [esi].CONTEXT.Ebp_
  invoke StrCCatA, ebx, $OfsCStrA("ebp = "), lengthof cExceptionMsg - 1
  invoke StrCCatA, ebx, addr cExceptionBuffer, lengthof cExceptionMsg - 1
  invoke StrCCatA, ebx, offset bHexComma, lengthof cExceptionMsg - 1
  invoke dword2hexA, addr cExceptionBuffer, [esi].CONTEXT.Esp_
  invoke StrCCatA, ebx, $OfsCStrA("esp = "), lengthof cExceptionMsg - 1
  invoke StrCCatA, ebx, addr cExceptionBuffer, lengthof cExceptionMsg - 1
  invoke StrCCatA, ebx, offset bHexComma, lengthof cExceptionMsg - 1
  invoke dword2hexA, addr cExceptionBuffer, [esi].CONTEXT.Eip_
  invoke StrCCatA, ebx, $OfsCStrA("eip = "), lengthof cExceptionMsg - 1
  invoke StrCCatA, ebx, addr cExceptionBuffer, lengthof cExceptionMsg - 1
  invoke StrCCatA, ebx, offset bHexCommaNewLine, lengthof cExceptionMsg - 1

  invoke dword2hexA, addr cExceptionBuffer, [esi].CONTEXT.SegGs
  invoke StrCCatA, ebx, $OfsCStrA("GS = "), lengthof cExceptionMsg - 1
  invoke StrCCatA, ebx, addr cExceptionBuffer, lengthof cExceptionMsg - 1
  invoke StrCCatA, ebx, offset bHexComma, lengthof cExceptionMsg - 1
  invoke dword2hexA, addr cExceptionBuffer, [esi].CONTEXT.SegFs
  invoke StrCCatA, ebx, $OfsCStrA("FS = "), lengthof cExceptionMsg - 1
  invoke StrCCatA, ebx, addr cExceptionBuffer, lengthof cExceptionMsg - 1
  invoke StrCCatA, ebx, offset bHexComma, lengthof cExceptionMsg - 1
  invoke dword2hexA, addr cExceptionBuffer, [esi].CONTEXT.SegEs
  invoke StrCCatA, ebx, $OfsCStrA("ES = "), lengthof cExceptionMsg - 1
  invoke StrCCatA, ebx, addr cExceptionBuffer, lengthof cExceptionMsg - 1
  invoke StrCCatA, ebx, offset bHexCommaNewLine, lengthof cExceptionMsg - 1

  invoke dword2hexA, addr cExceptionBuffer, [esi].CONTEXT.SegDs
  invoke StrCCatA, ebx, $OfsCStrA("DS = "), lengthof cExceptionMsg - 1
  invoke StrCCatA, ebx, addr cExceptionBuffer, lengthof cExceptionMsg - 1
  invoke StrCCatA, ebx, offset bHexComma, lengthof cExceptionMsg - 1
  invoke dword2hexA, addr cExceptionBuffer, [esi].CONTEXT.SegCs
  invoke StrCCatA, ebx, $OfsCStrA("CS = "), lengthof cExceptionMsg - 1
  invoke StrCCatA, ebx, addr cExceptionBuffer, lengthof cExceptionMsg - 1
  invoke StrCCatA, ebx, offset bHexComma, lengthof cExceptionMsg - 1
  invoke dword2hexA, addr cExceptionBuffer, [esi].CONTEXT.SegSs
  invoke StrCCatA, ebx, $OfsCStrA("SS = "), lengthof cExceptionMsg - 1
  invoke StrCCatA, ebx, addr cExceptionBuffer, lengthof cExceptionMsg - 1
  invoke StrCCatCharA, ebx, "h", lengthof cExceptionMsg - 1

  invoke StrCCatA, ebx, $OfsCStrA($Esc("\n\nCPU Flags:   ")), lengthof cExceptionMsg - 1
  ;Build the CPU Flags string
  lea ecx, cExceptionBuffer
  m2z BYTE ptr [ecx]
  mov eax, [esi].CONTEXT.EFlags_
  CpuFlagTest 00, < FC>
  CpuFlagTest 02, < FP>
  CpuFlagTest 04, < FA>
  CpuFlagTest 06, < FZ>
  CpuFlagTest 07, < FS>
  CpuFlagTest 08, < FT>
  CpuFlagTest 09, < FI>
  CpuFlagTest 10, < FD>
  CpuFlagTest 11, < FO>
  m2z BYTE ptr [ecx]
  invoke StrCCatA, ebx, addr cExceptionBuffer, lengthof cExceptionMsg - 1

  invoke StrCCatA, ebx, offset bCRLF, lengthof cExceptionMsg - 1

  ;MessageBox customization
  invoke GetCurrentThreadId
  invoke SetWindowsHookEx, WH_CBT, offset CBTProcA, hInstance, eax
  mov hCBTProcA, eax
  invoke MessageBoxA, 0, ebx, offset cExUserTitle, \
         MB_ICONERROR + MB_OKCANCEL + MB_APPLMODAL + MB_TOPMOST + MB_SETFOREGROUND + MB_DEFBUTTON2
  .if eax == IDOK                                     ;"Copy and Exit" was pressed
    invoke StrSizeA, ebx
    invoke GlobalAlloc, GMEM_MOVEABLE, eax            ;eax = Memory HANDLE = HGLOBAL
    .if eax != 0
      push eax
      push eax
      invoke GlobalLock, eax                          ;eax -> Memory 
      invoke StrCopyA, eax, ebx                       ;Copy string to memory
      call GlobalUnlock
      invoke OpenClipboard, 0
      push CF_TEXT
      call SetClipboardData
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
;                   If this parameter is NULL, the messgebox is always displayed.
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
    m2m pCallbackA, pCallbackFunc, eax
  .else
    m2z pCallbackA
  .endif

  invoke SetUnhandledExceptionFilter, offset FinalExceptionHandlerA
  mov pPrevUnhandledExceptionFilterA, eax

  ret
SetExceptionMessageA endp

end
