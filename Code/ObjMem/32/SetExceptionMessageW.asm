; ==================================================================================================
; Title:      SetExceptionMessageW.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
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
    invoke SetWindowTextW, eax, $OfsCStrW("&Exit")
    invoke GetDlgItem, wParam, IDOK
    invoke SetWindowTextW, eax, $OfsCStrW("&Copy && Exit")
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
  FillStringW [ecx], <FlagStr>
  add ecx, 6
@@:
endm

align ALIGN_CODE
FinalExceptionHandlerW proc uses ebx edi esi pExceptInfo:ptr EXCEPTION_POINTERS
  local cExceptionBuffer[1024]:CHRW
  local cExceptionMsg[2048]:CHRW

  ;Execute previous filter
  mov eax, [pPrevUnhandledExceptionFilterW]
  .if eax != NULL
    push pExceptInfo
    call eax
    .if eax == EXCEPTION_CONTINUE_EXECUTION
      ret
    .endif
  .endif

  ;Clean up any things in the callback, like freeing memory and handles
  .if pCallbackW != NULL
    push pExceptInfo
    call pCallbackW
    .if eax != 0
      mov eax, EXCEPTION_EXECUTE_HANDLER
      ret
    .endif
  .endif

  m2z CHRW ptr [cExceptionMsg]
  m2z CHRW ptr [cExceptionBuffer]
  lea ebx, cExceptionMsg

  invoke StrCCopyW, ebx, offset cExUserMessage, lengthof cExceptionMsg - 1

  invoke StrCCatW, ebx, $OfsCStrW($Esc("\nMain Module = ")), lengthof cExceptionMsg - 1
  invoke StrLengthW, ebx
  mov ecx, lengthof cExceptionMsg - 1
  sub ecx, eax
  lea eax, [ebx + 2*eax]
  invoke GetModuleFileNameW, 0, eax, ecx
  invoke StrCCatW, ebx, offset wCRLF, lengthof cExceptionMsg - 1

  mov eax, pExceptInfo
  mov edi, [eax].EXCEPTION_POINTERS.ExceptionRecord
  mov esi, [eax].EXCEPTION_POINTERS.ContextRecord

  invoke FindModuleByAddrW, [edi].EXCEPTION_RECORD.ExceptionAddress, addr cExceptionBuffer

  ;Create the output text
  invoke StrCCatW, ebx, $OfsCStrW($Esc("\nModule = ")), lengthof cExceptionMsg - 1
  invoke StrCCatW, ebx, addr cExceptionBuffer, lengthof cExceptionMsg - 1

  invoke StrCCatW, ebx, $OfsCStrW($Esc("\nException Type = ")), lengthof cExceptionMsg - 1
  invoke GetExceptionStrW, [edi].EXCEPTION_RECORD.ExceptionCode
  invoke StrCCatW, ebx, eax, lengthof cExceptionMsg - 1

  invoke dword2hexW, addr cExceptionBuffer, [edi].EXCEPTION_RECORD.ExceptionAddress
  invoke StrCCatW, ebx, $OfsCStrW($Esc("\nException Address = ")), lengthof cExceptionMsg - 1
  invoke StrCCatW, ebx, addr cExceptionBuffer, lengthof cExceptionMsg - 1
  invoke StrCCatW, ebx, $OfsCStrW($Esc("h\n\nCPU Registers:\n")), lengthof cExceptionMsg - 1
  invoke dword2hexW, addr cExceptionBuffer, [esi].CONTEXT.Eax_
  invoke StrCCatW, ebx, $OfsCStrW("eax = "), lengthof cExceptionMsg - 1
  invoke StrCCatW, ebx, addr cExceptionBuffer, lengthof cExceptionMsg - 1
  invoke StrCCatW, ebx, offset wHexComma, lengthof cExceptionMsg - 1
  invoke dword2hexW, addr cExceptionBuffer, [esi].CONTEXT.Ebx_
  invoke StrCCatW, ebx, $OfsCStrW("ebx = "), lengthof cExceptionMsg - 1
  invoke StrCCatW, ebx, addr cExceptionBuffer, lengthof cExceptionMsg - 1
  invoke StrCCatW, ebx, offset wHexComma, lengthof cExceptionMsg - 1
  invoke dword2hexW, addr cExceptionBuffer, [esi].CONTEXT.Ecx_
  invoke StrCCatW, ebx, $OfsCStrW("ecx = "), lengthof cExceptionMsg - 1
  invoke StrCCatW, ebx, addr cExceptionBuffer, lengthof cExceptionMsg - 1
  invoke StrCCatW, ebx, offset wHexCommaNewLine, lengthof cExceptionMsg - 1

  invoke dword2hexW, addr cExceptionBuffer, [esi].CONTEXT.Edx_
  invoke StrCCatW, ebx, $OfsCStrW("edx = "), lengthof cExceptionMsg - 1
  invoke StrCCatW, ebx, addr cExceptionBuffer, lengthof cExceptionMsg - 1
  invoke StrCCatW, ebx, offset wHexComma, lengthof cExceptionMsg - 1
  invoke dword2hexW, addr cExceptionBuffer, [esi].CONTEXT.Edi_
  invoke StrCCatW, ebx, $OfsCStrW("edi = "), lengthof cExceptionMsg - 1
  invoke StrCCatW, ebx, addr cExceptionBuffer, lengthof cExceptionMsg - 1
  invoke StrCCatW, ebx, offset wHexComma, lengthof cExceptionMsg - 1
  invoke dword2hexW, addr cExceptionBuffer, [esi].CONTEXT.Esi_
  invoke StrCCatW, ebx, $OfsCStrW("esi = "), lengthof cExceptionMsg - 1
  invoke StrCCatW, ebx, addr cExceptionBuffer, lengthof cExceptionMsg - 1
  invoke StrCCatW, ebx, offset wHexCommaNewLine, lengthof cExceptionMsg - 1

  invoke dword2hexW, addr cExceptionBuffer, [esi].CONTEXT.Ebp_
  invoke StrCCatW, ebx, $OfsCStrW("ebp = "), lengthof cExceptionMsg - 1
  invoke StrCCatW, ebx, addr cExceptionBuffer, lengthof cExceptionMsg - 1
  invoke StrCCatW, ebx, offset wHexComma, lengthof cExceptionMsg - 1
  invoke dword2hexW, addr cExceptionBuffer, [esi].CONTEXT.Esp_
  invoke StrCCatW, ebx, $OfsCStrW("esp = "), lengthof cExceptionMsg - 1
  invoke StrCCatW, ebx, addr cExceptionBuffer, lengthof cExceptionMsg - 1
  invoke StrCCatW, ebx, offset wHexComma, lengthof cExceptionMsg - 1
  invoke dword2hexW, addr cExceptionBuffer, [esi].CONTEXT.Eip_
  invoke StrCCatW, ebx, $OfsCStrW("eip = "), lengthof cExceptionMsg - 1
  invoke StrCCatW, ebx, addr cExceptionBuffer, lengthof cExceptionMsg - 1
  invoke StrCCatW, ebx, offset wHexCommaNewLine, lengthof cExceptionMsg - 1

  invoke dword2hexW, addr cExceptionBuffer, [esi].CONTEXT.SegGs
  invoke StrCCatW, ebx, $OfsCStrW("GS = "), lengthof cExceptionMsg - 1
  invoke StrCCatW, ebx, addr cExceptionBuffer, lengthof cExceptionMsg - 1
  invoke StrCCatW, ebx, offset wHexComma, lengthof cExceptionMsg - 1
  invoke dword2hexW, addr cExceptionBuffer, [esi].CONTEXT.SegFs
  invoke StrCCatW, ebx, $OfsCStrW("FS = "), lengthof cExceptionMsg - 1
  invoke StrCCatW, ebx, addr cExceptionBuffer, lengthof cExceptionMsg - 1
  invoke StrCCatW, ebx, offset wHexComma, lengthof cExceptionMsg - 1
  invoke dword2hexW, addr cExceptionBuffer, [esi].CONTEXT.SegEs
  invoke StrCCatW, ebx, $OfsCStrW("ES = "), lengthof cExceptionMsg - 1
  invoke StrCCatW, ebx, addr cExceptionBuffer, lengthof cExceptionMsg - 1
  invoke StrCCatW, ebx, offset wHexCommaNewLine, lengthof cExceptionMsg - 1

  invoke dword2hexW, addr cExceptionBuffer, [esi].CONTEXT.SegDs
  invoke StrCCatW, ebx, $OfsCStrW("DS = "), lengthof cExceptionMsg - 1
  invoke StrCCatW, ebx, addr cExceptionBuffer, lengthof cExceptionMsg - 1
  invoke StrCCatW, ebx, offset wHexComma, lengthof cExceptionMsg - 1
  invoke dword2hexW, addr cExceptionBuffer, [esi].CONTEXT.SegCs
  invoke StrCCatW, ebx, $OfsCStrW("CS = "), lengthof cExceptionMsg - 1
  invoke StrCCatW, ebx, addr cExceptionBuffer, lengthof cExceptionMsg - 1
  invoke StrCCatW, ebx, offset wHexComma, lengthof cExceptionMsg - 1
  invoke dword2hexW, addr cExceptionBuffer, [esi].CONTEXT.SegSs
  invoke StrCCatW, ebx, $OfsCStrW("SS = "), lengthof cExceptionMsg - 1
  invoke StrCCatW, ebx, addr cExceptionBuffer, lengthof cExceptionMsg - 1
  invoke StrCCatCharW, ebx, "h", lengthof cExceptionMsg - 1
  
  invoke StrCCatW, ebx, $OfsCStrW($Esc("\n\nCPU Flags:   ")), lengthof cExceptionMsg - 1
  ;Build the CPU Flags string
  lea ecx, cExceptionBuffer
  m2z WORD ptr [ecx]
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
  m2z WORD ptr [ecx]
  invoke StrCCatW, ebx, addr cExceptionBuffer, lengthof cExceptionMsg - 1

  invoke StrCCatW, ebx, offset wCRLF, lengthof cExceptionMsg - 1

  ;MessageBox customization
  invoke GetCurrentThreadId
  invoke SetWindowsHookEx, WH_CBT, offset CBTProcW, hInstance, eax
  mov hCBTProcW, eax
  invoke MessageBoxW, 0, ebx, offset cExUserTitle, \
         MB_ICONERROR + MB_OKCANCEL + MB_APPLMODAL + MB_TOPMOST + MB_SETFOREGROUND + MB_DEFBUTTON2
  .if eax == IDOK                                     ;"Copy and Exit" was pressed
    invoke StrSizeW, ebx
    invoke GlobalAlloc, GMEM_MOVEABLE, eax            ;eax = Memory HANDLE = HGLOBAL
    .if eax != 0
      push eax
      push eax
      invoke GlobalLock, eax                          ;eax -> Memory 
      invoke StrCopyW, eax, ebx                       ;Copy string to memory
      call GlobalUnlock
      invoke OpenClipboard, 0
      invoke EmptyClipboard
      push CF_UNICODETEXT
      call SetClipboardData
      invoke CloseClipboard
    .endif
  .endif

  mov eax, EXCEPTION_EXECUTE_HANDLER                  ;Terminate the application
  ret
FinalExceptionHandlerW endp

; --------------------------------------------------------------------------------------------------
; Procedure: SetExceptionMessageW
; Purpose:   Install a final exception handler that displays a messagebox showing detailed exception
;            information and a user text.
; Arguments: Arg1: -> User WIDE message string.
;            Arg2: -> Messagebox WIDE title string.
;            Arg3: -> Callback procedure fired when an exception reaches the final handler.
;                  If the callback returns zero, the messagebox is displayed, otherwise
;                  EXCEPTION_EXECUTE_HANDLER is passed to the OS without showing the messagebox.
;                  If this parameter is NULL, the messgebox is displayed.
; Return:    Nothing.

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
    m2m pCallbackW, pCallbackFunc, eax
  .else
    m2z pCallbackW
  .endif

  invoke SetUnhandledExceptionFilter, offset FinalExceptionHandlerW
  mov pPrevUnhandledExceptionFilterW, eax

  ret
SetExceptionMessageW endp

end
