; ==================================================================================================
; Title:      StackWalker.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm support of StackWalker objects.
; Notes:      Version C.1.0, August 2023
;               - First release.
; ==================================================================================================

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Object:     StackWalker
; Purpose:    Implement a specialised stack walker object using system routines.

SW_SYM_NAME_LENGTH equ 255

StackWalkerID equ 0
Object StackWalker, StackWalkerID, Primer
  RedefineMethod    Init,       POINTER
  VirtualMethod     FirstFrame
  VirtualMethod     NextFrame

  DefineVariable    hProcess,   HANDLE,       0
  DefineVariable    hThread,    HANDLE,       0
if TARGET_BITNESS eq 32
  DefineVariable    Context,    CONTEXT,          {}
  DefineVariable    Stack,      STACKFRAME,       {}
  DefineVariable    Symbol,     IMAGEHLP_SYMBOL,  {}
else
  DefineVariable    bFiller,    BYTE,         4 dup(0)    ;Align CONTEXT structure to 16
  DefineVariable    Context,    CONTEXT,          {}
  DefineVariable    Stack,      STACKFRAME64,     {}
  DefineVariable    Symbol,     IMAGEHLP_SYMBOL64,{}
endif
  ;This line MUST follow the Symbol definition!
  DefineVariable    cSymName,   CHRA, SW_SYM_NAME_LENGTH dup(0)
  DefineVariable    cProcName,  CHRA, (SW_SYM_NAME_LENGTH + 1) dup(0)
ObjectEnd


; ==================================================================================================
;    StackWalker implementation
; ==================================================================================================

if IMPLEMENT

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     StackWalker.Init
; Purpose:    Initialize the StackWalker object.
; Arguments:  Arg1: -> Owner object.
; Return:     Nothing.
; Link:       https://stackoverflow.com/questions/5705650/stackwalk64-on-windows-get-symbol-name

Method StackWalker.Init, uses xsi, pOwner:POINTER
  SetObject xsi
  ACall xsi.Init, pOwner
  mov [xsi].hProcess, $invoke(GetCurrentProcess())
  mov [xsi].hThread, $invoke(GetCurrentThread())
  invoke SymSetOptions, SYMOPT_UNDNAME or SYMOPT_DEFERRED_LOADS
  invoke SymInitialize, [xsi].hProcess, NULL, TRUE
  mov [xsi].Symbol.MaxNameLength, SW_SYM_NAME_LENGTH
  mov [xsi].Symbol.SizeOfStruct, sizeof $Obj(StackWalker).Symbol
  invoke MemZero, addr [xsi].Stack, sizeof $Obj(StackWalker).Stack
  m2m [xsi].Stack.AddrPC.Mode,    AddrModeFlat, xax
  m2m [xsi].Stack.AddrFrame.Mode, AddrModeFlat, xcx
  m2m [xsi].Stack.AddrStack.Mode, AddrModeFlat, xdx
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     StackWalker.FirstFrame
; Purpose:    Captures the first stack frame.
; Arguments:  None.
; Return:     eax = TRUE if succeeded, otherwise FALSE.

Method StackWalker.FirstFrame, uses xsi
  SetObject xsi
  invoke RtlCaptureContext, addr [xsi].Context
  OCall xsi.NextFrame
if TARGET_BITNESS eq 64
  test eax, eax
  jz @@EOM
  OCall xsi.NextFrame
endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     StackWalker.NextFrame
; Purpose:    Captures the next stack frame.
; Arguments:  None.
; Return:     eax = TRUE if succeeded, otherwise FALSE.

Method StackWalker.NextFrame, uses xsi
  local xDisplacement:XWORD

  SetObject xsi
  m2z xDisplacement
  if TARGET_BITNESS eq 32
    m2m [xsi].Stack.AddrPC.Offset_,    [xsi].Context.Eip_, eax
    m2m [xsi].Stack.AddrFrame.Offset_, [xsi].Context.Ebp_, ecx
    m2m [xsi].Stack.AddrStack.Offset_, [xsi].Context.Esp_, edx
    invoke StackWalk, IMAGE_FILE_MACHINE_I386, [xsi].hProcess, [xsi].hThread, \
                      addr [xsi].Stack, addr [xsi].Context, \
                      NULL, SymFunctionTableAccess, SymGetModuleBase, NULL
    test eax, eax
    jz @@EOM
    invoke SymGetSymFromAddr, [xsi].hProcess, [xsi].Stack.AddrPC.Offset_, 
                              addr xDisplacement, addr [xsi].Symbol
    invoke UnDecorateSymbolName, addr [xsi].Symbol.Name_, addr [xsi].cProcName, 
                                 SW_SYM_NAME_LENGTH, UNDNAME_COMPLETE
  else
    m2m [xsi].Stack.AddrPC.Offset_,    [xsi].Context.Rip_, rax
    m2m [xsi].Stack.AddrFrame.Offset_, [xsi].Context.Rbp_, rcx
    m2m [xsi].Stack.AddrStack.Offset_, [xsi].Context.Rsp_, rdx
    invoke StackWalk64, IMAGE_FILE_MACHINE_AMD64, [xsi].hProcess, [xsi].hThread, \
                        addr [xsi].Stack, addr [xsi].Context, \
                        NULL, SymFunctionTableAccess64, SymGetModuleBase64, NULL
    test eax, eax
    jz @@EOM
    invoke SymGetSymFromAddr64, [xsi].hProcess, [xsi].Stack.AddrPC.Offset_, 
                                addr xDisplacement, addr [xsi].Symbol
    invoke UnDecorateSymbolName, addr [xsi].Symbol.Name_, addr [xsi].cProcName, 
                                 SW_SYM_NAME_LENGTH, UNDNAME_COMPLETE
  endif
  mov eax, TRUE
MethodEnd

endif

;
;
;; ——————————————————————————————————————————————————————————————————————————————————————————————————
;; Method:     StackWalker.Init
;; Purpose:    Initialize the StackWalker object.
;; Arguments:  Arg1: -> Owner object.
;; Return:     Nothing.
;; Link:       https://stackoverflow.com/questions/5705650/stackwalk64-on-windows-get-symbol-name
;
;Method StackWalker.Init, uses xbx xdi xsi, pOwner:POINTER
;  local bResult:BOOL, hProcess:HANDLE, hThread:HANDLE, Context:CONTEXT, dFrame:DWORD
;  local cName[SW_SYM_NAME_LENGTH]:CHRA, xDisplacement:XWORD
;  if TARGET_BITNESS eq 32
;    local Stack:STACKFRAME, pSymbol:ptr IMAGEHLP_SYMBOL
;  else
;    local Stack:STACKFRAME64, pSymbol:ptr IMAGEHLP_SYMBOL64
;  endif
;
;  SetObject xsi
;  ACall xsi.Init, pOwner
;
;  invoke RtlCaptureContext, addr Context
;  invoke MemZero, addr Stack, sizeof Stack
;
;  mov hProcess, $invoke(GetCurrentProcess())
;  mov hThread, $invoke(GetCurrentThread())
;  m2z xDisplacement
;  if TARGET_BITNESS eq 32
;    m2m Stack.AddrPC.Offset_,    Context.Eip_, xax
;    m2m Stack.AddrPC.Mode,       AddrModeFlat, xax
;    m2m Stack.AddrStack.Offset_, Context.Esp_, xax
;    m2m Stack.AddrStack.Mode,    AddrModeFlat, xax
;    m2m Stack.AddrFrame.Offset_, Context.Ebp_, xax
;    m2m Stack.AddrFrame.Mode,    AddrModeFlat, xax
;  else
;    m2m Stack.AddrPC.Offset_,    Context.Rip_, xax
;    m2m Stack.AddrPC.Mode,       AddrModeFlat, xax
;    m2m Stack.AddrStack.Offset_, Context.Rsp_, xax
;    m2m Stack.AddrStack.Mode,    AddrModeFlat, xax
;    m2m Stack.AddrFrame.Offset_, Context.Rbp_, xax
;    m2m Stack.AddrFrame.Mode,    AddrModeFlat, xax
;  endif
;
;  invoke SymSetOptions, SYMOPT_UNDNAME or SYMOPT_DEFERRED_LOADS
;  invoke SymInitialize, hProcess, NULL, TRUE
;  if TARGET_BITNESS eq 32
;    mov pSymbol, $MemAlloc(sizeof IMAGEHLP_SYMBOL + SW_SYM_NAME_LENGTH)
;  else
;    mov pSymbol, $MemAlloc(sizeof IMAGEHLP_SYMBOL64 + SW_SYM_NAME_LENGTH)
;  endif
;
;  xor ebx, ebx
;  .while TRUE
;    if TARGET_BITNESS eq 32
;      invoke StackWalk, IMAGE_FILE_MACHINE_I386, hProcess, hThread, addr Stack, addr Context,
;                        NULL, SymFunctionTableAccess, SymGetModuleBase, NULL
;      .break .if eax == FALSE
;      mov edi, pSymbol
;      mov [edi].IMAGEHLP_SYMBOL.MaxNameLength, SW_SYM_NAME_LENGTH
;      mov [edi].IMAGEHLP_SYMBOL.SizeOfStruct, sizeof IMAGEHLP_SYMBOL
;      invoke SymGetSymFromAddr, hProcess, Stack.AddrPC.Offset_, addr xDisplacement, edi
;      invoke UnDecorateSymbolName, addr [edi].IMAGEHLP_SYMBOL.Name_, addr cName, SW_SYM_NAME_LENGTH, UNDNAME_COMPLETE
;    else
;      invoke StackWalk64, IMAGE_FILE_MACHINE_AMD64, hProcess, hThread, addr Stack, addr Context,
;                          NULL, SymFunctionTableAccess64, SymGetModuleBase64, NULL
;      .break .if eax == FALSE
;      mov rdi, pSymbol
;      mov [rdi].IMAGEHLP_SYMBOL64.MaxNameLength, SW_SYM_NAME_LENGTH
;      mov [rdi].IMAGEHLP_SYMBOL64.SizeOfStruct, sizeof IMAGEHLP_SYMBOL64
;      invoke SymGetSymFromAddr64, hProcess, Stack.AddrPC.Offset_, addr xDisplacement, rdi
;      invoke UnDecorateSymbolName, addr [rdi].IMAGEHLP_SYMBOL64.Name_, addr cName, SW_SYM_NAME_LENGTH, UNDNAME_COMPLETE
;    endif
;
;    DbgStrA cName
;
;    inc ebx
;  .endw
;  MemFree pSymbol
;
;MethodEnd
;
