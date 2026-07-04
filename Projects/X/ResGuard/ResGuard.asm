; ==================================================================================================
; Title:      ResGuard.asm
; Author:     G. Friedrich
; Version:    C.1.1
; Purpose:    Detection of OS resource leaks using ObjAsm ResGuardxx.dll.
; Notes:      Version C.1.0, August 2023
;               - Initial release.
;             Version C.1.1, June 2026
;               - Code refactored for maintainability.
;               - ProcNames are stored now in the CONST section and a pointer is passed to the
;                 CallData
;               - Fixed registration detour gaps.
;               - Added GDI+, token, SCM, atom, crypto context, process/thread, sockets, pipes,
;                 and several other resource categories.
;             An external package needs to include:
;               - ResGuard.inc
;               - ResGuard32.lib and ResGuard64.lib
;               - ResGuard32.dll and ResGuard64.dll
; Links:      http://www.microsoft.com/msj/0498/hood0498.aspx
;             https://www.ired.team/miscellaneous-reversing-forensics/windows-kernel-internals/windows-x64-calling-convention-stack-frame
;             https://learn.microsoft.com/en-us/windows/win32/api/dbghelp/nf-dbghelp-stackwalk
;             https://learn.microsoft.com/en-us/windows/win32/api/dbghelp/nf-dbghelp-stackwalk64
;             https://stackoverflow.com/questions/5705650/stackwalk64-on-windows-get-symbol-name
; ==================================================================================================


_IMAGEHLP_SOURCE_ equ 0
SYM_NAME_LENGTH   equ 255     ; Max symbol name length
CALLER_MAX_DEEP   equ 10      ; Max caller stack chain depth

% include @Environ(OBJASM_PATH)\Code\Macros\Model.inc
SysSetup OOP, DLL32, SUFFIX, WIDE_STRING, DEBUG(WND)

% includelib &LibPath&Windows\DbgHelp.lib

% include &IncPath&Windows\DbgHelp.inc
% include .\ResGuard_Shared.inc

CStrW wWndCaption,  "ResGuard"
CStrW wDebugStart,  "Use the debugger to find the lines of", CRLF, \
                    "code that use the listed resources.", CRLF, CRLF,\
                    "Do you want to start the debugger now?", CRLF

%CStr szAboutText,  "&APP_TITLE", @CatStr(<!"%TARGET_BITNESS!">), ".dll - Version &VER_PRODUCTVERSION_STR", CRLF, \
                    "Designed with ObjAsm", CRLF, \
                    "© &COPYRIGHT", CRLF, \
                    @CatStr(<!"Build: >, \
                            %BUILD_NUMBER, <->, %ASSEMBLER, <->, \
                            %TARGET_MODE_STR, <->, %TARGET_BITNESS, < from >, %BUILD_DATE_STR, <!">)

HookCount = 0

MakeObjects Primer, Stream, Collection, IAT_Hook

if TARGET_BITNESS eq 32
  STACK textequ <STACKFRAME>

  SYMBOL struct
    IMAGEHLP_SYMBOL   {}
    CHRA              SYM_NAME_LENGTH dup(?)            ; Only ANSI names
  SYMBOL ends

  SymGetSymFromAddrX textequ <SymGetSymFromAddr>
else
  STACK textequ <STACKFRAME64>

  SYMBOL struct
    IMAGEHLP_SYMBOL64 {}
    CHRA              SYM_NAME_LENGTH dup(?)            ; Only ANSI names
  SYMBOL ends

  SymGetSymFromAddrX textequ <SymGetSymFromAddr64>
endif

CALLER_INFO struct
  xRetAddr    XWORD   ?
  xInstrAddr  XWORD   ?
CALLER_INFO ends

CDF_AGGREGATED  equ   BIT00                             ; Set if repeated CallData is aggregated
                                                        ; while showing results to the user in [ ]
; --------------------------------------------------------------------------------------------------
; Object:     CallData
; Purpose:    Store all relevant info about a specific API call, like the call stack and an system
;             identification like a HANDLE, ID, etc.

Object CallData,, Primer
  VirtualMethod   Show,       XWORD, XWORD              ; Callback method

  DefineVariable  dFlags,     DWORD,        0
  DefineVariable  dReps,      DWORD,        0           ; After Aggregate, it holds the repetitions
  DefineVariable  xData1,     XWORD,        0           ; Primary data
  DefineVariable  xData2,     XWORD,        0           ; Auxiliary data
  DefineVariable  pProcName,  PSTRINGA,     NULL        ; -> Proc name
  DefineVariable  dCount,     DWORD,        0           ; Number of filled CALLER_INFO structures
  DefineVariable  CallStack,  CALLER_INFO,  CALLER_MAX_DEEP dup({0, 0})
ObjectEnd

; --------------------------------------------------------------------------------------------------
; Object:     RTC_Collection (RTC: Resource Type Call, RTCC: RTC Collection)
; Purpose:    Collection of CallData Objects aggregated by system resource type.
; Example:    For a resource of type Brush, CallData for CreateSolidBrush, CreateDIBPatternBrush,
;             CreateDIBPatternBrushPt, etc. are aggregated in pRTCC_Brush.

Object RTC_Collection,, Collection
  VirtualMethod   Aggregate
  VirtualMethod   Deaggregate
  RedefineMethod  Insert,     $ObjPtr(CallData)
  VirtualMethod   Remove,     XWORD, XWORD

  DefineVariable  dMaxCount,  DWORD,    0               ; Maximal count to check the system load
  DefineVariable  dTotCount,  DWORD,    0               ; Cumulative number of calls
ObjectEnd

.data                                                   ; Non exported data
  hProcess          HANDLE    0
  xAppRefAddr       XWORD     0
  HookColl          $ObjInst(Collection)                ; Collection of IAT_Hook objects
  RcrcColl          $ObjInst(Collection)                ; Collection of RTC_Collection objects
  FailErrColl       $ObjInst(RTC_Collection)            ; Failed API calls
  LogiErrColl       $ObjInst(RTC_Collection)            ; API calls where a logic error was detected
  dResGuardEnabled  DWORD     FALSE

.code
; ==================================================================================================
;    CallData implementation
; ==================================================================================================

; Check counters
ResTypeCollCount  = 0
ResTypeHookCount  = 0
ShowCollDataCount = 0

; --------------------------------------------------------------------------------------------------
; Method:     CallData.Show
; Purpose:    Callback procedure to display the gathered call data on the "LeakReport" DebugCenter
;             child Window.
; Arguments:  Arg1: Dummy argument.
;             Arg2: Dummy argument.
; Return:     Nothing.

Method CallData.Show, uses xbx xdi xsi, xDummy1:XWORD, xDummy2:XWORD
  local Symbol:SYMBOL, xDisplacement:XWORD
  local cBuffer[SYM_NAME_LENGTH]:CHRA

  ANNOTATION use:xDummy1 xDummy2

  SetObject xsi
  ;Show a bullet
  .ifBitClr [xsi].dFlags, CDF_AGGREGATED
    ; Draw a bullet
    invoke DbgOutTextW, $OfsCStrW(" ", 2022h, " "), DbgColorString, DbgColorBackground, \
                        DBG_EFFECT_NORMAL, offset wWndCaption
    ; Draw the API procedure name
    invoke DbgOutTextA, [xsi].$Obj(CallData).pProcName, DbgColorString, DbgColorBackground, \
                        DBG_EFFECT_NORMAL, offset wWndCaption

    mov edx, [xsi].dReps
    inc edx
    lea xbx, cBuffer
    FillTextA [xbx], < [>
    lea xcx, [xbx + ??StrSize]
    invoke dword2decA, xcx, edx
    FillStringA [xbx + xax + ??StrSize - 1], <]>
    invoke DbgOutTextA, addr cBuffer, DbgColorString, DbgColorBackground, \
                        DBG_EFFECT_NORMAL, offset wWndCaption

    xor ebx, ebx
    lea xdi, [xsi].CallStack                             ;xdi -> CallData.CallStack
    .while ebx != [xsi].$Obj(CallData).dCount
      ;Draw a left pointing triangle surrounded by spaces
      invoke DbgOutTextW, $OfsCStrW(" ", 25C4h, " "), DbgColorWarning, DbgColorBackground, \
                          DBG_EFFECT_NORMAL, offset wWndCaption
      mov Symbol.MaxNameLength, SYM_NAME_LENGTH
      mov Symbol.SizeOfStruct, sizeof SYMBOL
      invoke SymGetSymFromAddrX, hProcess, [xdi].CALLER_INFO.xInstrAddr,
                                 addr xDisplacement, addr Symbol
      .if eax != FALSE
        invoke UnDecorateSymbolName, addr Symbol.Name_, addr cBuffer, SYM_NAME_LENGTH, UNDNAME_COMPLETE
        .if eax != FALSE
          invoke DbgOutTextA, addr cBuffer, DbgColorWarning, DbgColorBackground, \
                              DBG_EFFECT_NORMAL, offset wWndCaption
        .endif
      .endif
      FillStringA cBuffer, <(>
      lea xcx, [cBuffer + ??StrLen]
      invoke xword2hexA, xcx, [xdi].CALLER_INFO.xRetAddr
      invoke StrCatA, addr cBuffer, $OfsCStrA("h)")
      invoke DbgOutTextA, addr cBuffer, DbgColorComment, DbgColorBackground, \
                          DBG_EFFECT_NORMAL, offset wWndCaption
      add xdi, sizeof CALLER_INFO
      inc ebx
    .endw

    .if ebx == 0
      invoke DbgOutTextW, $OfsCStrW(" ", 2190h, " "), DbgColorWarning, DbgColorBackground, \
                          DBG_EFFECT_NORMAL, offset wWndCaption
      invoke DbgOutText, $OfsCStr("no data"), DbgColorError, DbgColorBackground, \
                         DBG_EFFECT_NORMAL or DBG_EFFECT_NEWLINE, offset wWndCaption
    .else
      invoke DbgOutText, offset cCRLF, DbgColorForeground, DbgColorBackground, \
                         DBG_EFFECT_NORMAL, offset wWndCaption
    .endif
  .endif
MethodEnd


; ==================================================================================================
;    RTC_Collection implementation
; ==================================================================================================

; --------------------------------------------------------------------------------------------------
; Method:     RTC_Collection.Aggregate
; Purpose:    Mark identical calls and add up CallData.Reps. This is usefull when showing the final
;             results to the user.
; Arguments:  None.
; Return:     Nothing.

Method RTC_Collection.Aggregate, uses xbx xdi xsi
  local dOuterIndex:DWORD, dInnerIndex:DWORD

  SetObject xsi
  xor edx, edx
  .while edx != [xsi].dCount
    mov dOuterIndex, edx
    lea edi, [edx + 1]
    mov xbx, $OCall(xsi.ItemAt, edx)                    ; xbx -> CallData
    .ifBitClr [xbx].$Obj(CallData).dFlags, CDF_AGGREGATED
      .while edi != [xsi].dCount
        mov dInnerIndex, edi
        mov xdi, $OCall(xsi.ItemAt, edi)                ; xdi -> CallData
        .ifBitClr [xdi].$Obj(CallData).dFlags, CDF_AGGREGATED
          invoke StrCompA, [xbx].$Obj(CallData).pProcName, [xdi].$Obj(CallData).pProcName
          .if eax == 0
            mov ecx, [xbx].$Obj(CallData).dCount        ; Check the call data
            .if ecx == [xdi].$Obj(CallData).dCount
              mov eax, sizeof(CALLER_INFO)
              mul ecx
              lea xcx, [xbx].$Obj(CallData).CallStack
              lea xdx, [xdi].$Obj(CallData).CallStack
              invoke MemComp, xcx, xdx, eax
              .if eax == 0
                BitSet [xdi].$Obj(CallData).dFlags, CDF_AGGREGATED
                inc [xbx].$Obj(CallData).dReps          ; Increment dReps count
              .endif
            .endif
          .endif
        .endif
        mov edi, dInnerIndex
        inc edi
      .endw
    .endif
    mov edx, dOuterIndex
    inc edx
  .endw
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     RTC_Collection.Deaggregate
; Purpose:    Reset CDF_AGGREGATED flag and CallData.Reps to zero.
; Arguments:  None.
; Return:     Nothing.

Method RTC_Collection.Deaggregate, uses xsi
  SetObject xsi
  xor edx, edx
  mov xax, [xsi].pItems
  .while edx != [xsi].dCount
    mov xcx, [xax]
    BitClr [xcx].$Obj(CallData).dFlags, CDF_AGGREGATED
    mov [xcx].$Obj(CallData).dReps, 0
    add xax, sizeof(POINTER)
    inc edx
  .endw
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     RTC_Collection.Insert
; Purpose:    Insert item at the end of the collection.
; Arguments:  Arg1: -> CallData to store.
; Return:     xax -> Inserted item or NULL if failed.

Method RTC_Collection.Insert, uses xsi, pCallData:$ObjPtr(CallData)
  SetObject xsi
  ACall xsi.Insert, pCallData
  inc [xsi].dTotCount
  mov ecx, [xsi].dCount
  .if ecx > [xsi].dMaxCount
    mov [xsi].dMaxCount, ecx
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     RTC_Collection.Remove
; Purpose:    Remove CallData identified by xData1 and xData2 from the collection.
; Arguments:  Arg1: xData1
;             Arg2: xData2
; Return:     eax = TRUE if succeeded, otherwise FALSE.

xDataCompare proc pCallData:$ObjPtr(CallData), xData1:XWORD, xData2:XWORD
  ?mov ecx, pCallData
  ?mov edx, xData1
  xor eax, eax
  .if xdx == [xcx].$Obj(CallData).xData1
    mov xdx, xData2
    .if xdx == [xcx].$Obj(CallData).xData2
      inc eax
    .endif
  .endif
  ret
xDataCompare endp

Method RTC_Collection.Remove, uses xsi, xData1:XWORD, xData2:XWORD
  SetObject xsi
  OCall xsi.LastThat, offset xDataCompare, xData1, xData2
  .if xax
    OCall xsi.Dispose, xax
    xor eax, eax
    inc eax
  .endif
  ret
MethodEnd

; --------------------------------------------------------------------------------------------------
; Macro:      CreateProcNameStringA
; Purpose:    Creates and sets a ProcName string in the const section only if if does not
;             previously exist.
; Arguments:  Arg1: ProcName.
; Return:     Nothing.

CreateProcNameStringA macro ProcName:req
  ifndef &ProcName&StrA
    @CatStr(<CStrA >, &ProcName&StrA, <, !"ProcName!">)
  endif
endm

; --------------------------------------------------------------------------------------------------
; Macro:      InvokeOriginalCall
; Purpose:    Invoke the original call (before hooking), regardless of the target bitness.
; Arguments:  None.
; Return:     Nothing.

InvokeOriginalCall macro ProcName, ArgCount
  ;At this point, all args are stored on the stack. In 64-bit mode, this was done by the compiler
  if TARGET_BITNESS eq 32
    Cnt = ArgCount
    repeat ArgCount                                     ;; Push all arguments creating a new call stack
      @CatStr(<push Arg>, %Cnt)
      Cnt = Cnt - 1
    endm
  else
    if ArgCount gt 4
      Cnt = ArgCount
      repeat ArgCount - 4                               ;; Push higher arguments creating a new call stack
        m2m XWORD ptr [rsp + (Cnt - 1)*sizeof(XWORD)], @CatStr(<Arg>, %Cnt), xax
        Cnt = Cnt - 1
      endm
    endif
  ;;rcx, rdx, r8 & r9 were not changed; shadow space (20h) remains unchanged
  endif
  mov xax, pHook_&ProcName&
  call [xax].$Obj(IAT_Hook).pEntry                      ;; Invoke original call
endm

; --------------------------------------------------------------------------------------------------
; Macro:      WalkTheStack
; Purpose:    StackWalk(64) bitness neutral substitute. Starting from Context returns the next stack
;             frame into Stack structure.
; Arguments:  None.
; Return:     Nothing.

WalkTheStack macro
  if TARGET_BITNESS eq 32
    m2m Stack.AddrPC.Offset_,     Context.Eip_, rax
    m2m Stack.AddrFrame.Offset_,  Context.Ebp_, rcx
    m2m Stack.AddrStack.Offset_,  Context.Esp_, rdx
    invoke StackWalk,   IMAGE_FILE_MACHINE_I386, hProcess, hThread, \
                        addr Stack, addr Context, \
                        NULL, SymFunctionTableAccess, SymGetModuleBase, NULL
  else
    m2m Stack.AddrPC.Offset_,     Context.Rip_, rax
    m2m Stack.AddrFrame.Offset_,  Context.Rbp_, rcx
    m2m Stack.AddrStack.Offset_,  Context.Rsp_, rdx
    invoke StackWalk64, IMAGE_FILE_MACHINE_AMD64, hProcess, hThread, \
                        addr Stack, addr Context, \
                        NULL, SymFunctionTableAccess64, SymGetModuleBase64, NULL
  endif
endm

; --------------------------------------------------------------------------------------------------
; Macro:      AnalyseStack
; Purpose:    Creates a CallData instance and analyzes the stack starting from the current context.
;             Additionally it sets the CallData.pProcName pointer to the ProcName string from the
;             CONST section created using CreateProcNameStringA. 
; Arguments:  Arg1: ProcName.
; Return:     xbx -> CallData object.
; Note:       uses xbx xdi

AnalyseStack macro ProcName:req
  mov xbx, $New(CallData)
  OCall xbx::CallData.Init, NULL

  mov hThread, $invoke(GetCurrentThread())

  invoke MemZero, addr Stack, sizeof STACK

  invoke RtlCaptureContext, addr Context                ;; Capture current CPU context in Context
  ;; Context.Xbp_ = [xbp]                               Since RtlCaptureContext does change xbp,
  ;; Context.Xsp_ = lea [xbp + 4/8]                     the returned values correspond to the
  ;; Context.Xip_ = [xbp + 4/8] (ret address)           calling procedure

  mov Stack.AddrPC.Mode,     AddrModeFlat
  mov Stack.AddrFrame.Mode,  AddrModeFlat
  mov Stack.AddrStack.Mode,  AddrModeFlat
  mov Stack.AddrReturn.Mode, AddrModeFlat

  lea xdi, [xbx].$Obj(CallData).CallStack               ;; xdi -> CallData first CallStack

  if TARGET_BITNESS eq 32
    .repeat
      WalkTheStack
      .break .if eax == 0
      m2m [edi].CALLER_INFO.xRetAddr, Context.Eip_, edx
      m2m Context.Eip_, Stack.AddrReturn.Offset_, ecx   ;; Temp storage for next iteration
      m2m [edi].CALLER_INFO.xInstrAddr, Stack.AddrPC.Offset_, edx
      inc [ebx].$Obj(CallData).dCount
      add edi, sizeof CALLER_INFO
      mov eax, Stack.AddrFrame.Offset_                  ;; Use the frame pointer
    .until eax == xAppRefAddr || [ebx].$Obj(CallData).dCount == CALLER_MAX_DEEP
  else
    WalkTheStack                                        ;; Get first frame of the detour proc
    .if eax != 0
      .repeat
        m2m [rdi].CALLER_INFO.xRetAddr, Stack.AddrReturn.Offset_, rdx
        WalkTheStack
        .break .if eax == 0
        m2m [rdi].CALLER_INFO.xInstrAddr, Stack.AddrPC.Offset_, rdx
        inc [rbx].$Obj(CallData).dCount
        add rdi, sizeof CALLER_INFO
        mov rax, Stack.AddrStack.Offset_                ;; Use the stack pointer
      .until rax == xAppRefAddr || [rbx].$Obj(CallData).dCount == CALLER_MAX_DEEP
    .endif
  endif
  lea xax, &ProcName&StrA
  mov [xbx].$Obj(CallData).pProcName, xax
endm

; --------------------------------------------------------------------------------------------------
; Macro:      DefineHook
; Purpose:    Allocate the hook POINTER and do some administration stuff.
; Arguments:  Arg1: API procedure name.
;             Arg2: Resource type name, used to group calls related to the same OS resource type.
; Return:     Nothing.

DefineHook macro ProcName:req, ResTypeName
  HookCount = HookCount + 1                             ;; Keep track of the hook count
  ifnb <ResTypeName>
    externdef pRTCC_&ResTypeName&:$ObjPtr(RTC_Collection) ;; The RTC_Collection will be definend later
  endif
  .data
  pHook_&ProcName&  $ObjPtr(IAT_Hook)   NULL            ;; Create a place to store the POINTER
  .code
endm

; --------------------------------------------------------------------------------------------------
; Macro:      AddToResTypeHookList
; Purpose:    Adds an API definition (DllName and ProcName) to the ResTypeHookList.
; Arguments:  Arg1: ResType name.
;             Arg2: DLL full name.
;             Arg3: API procedure name.
; Return:     Nothing.

AddToResTypeHookList macro ResTypeName:req, DllName:req, ProcName:req
  ifndef &ResTypeName&HookList
    &ResTypeName&HookList CatStr <&DllName&_&ProcName&>
    ResTypeCollCount = ResTypeCollCount + 1 
  else
    &ResTypeName&HookList CatStr &ResTypeName&HookList, <,>, <&DllName&_&ProcName&>
  endif
endm

; --------------------------------------------------------------------------------------------------
; Macro:      DetourAcquire
; Purpose:    Creates a detour procedure to intercept calls that acquire an OS resource.
; Arguments:  Arg1: DLL full name.
;             Arg2: API procedure name.
;             Arg3: Procedure argument count.
;             Arg4: ID = x:   ID used to signal where the value identifying the OS resource
;                             (Handle, Pointer, Counter, String) is coming.
;                     x > 0 : Argument x
;                     x = 0 : Call result (return value)
;                     x < 0 : [Argument -x] (dereference)
;             Arg5: Procedure success condition.
;             Arg6: Resource type name, used to group calls related to the same OS resource type.
;             Arg7: (optional) Remove argument index. This is meant for procedures like HeapRealloc,
;                   where the previous HANDLE/POINTER must be removed first.
;             Arg8: (optional) Condition to bypass registering the successful call. This is
;                   meant for procs like LoadCursorA/W with Arg1 = 0, where the resource must not
;                   be released.
; Return:     Nothing.

DetourAcquire macro DllName:req, ProcName:req, ArgCount:req, CallIdentifier:req, SuccessCond:req, \
                    ResTypeName:req, RemoveArgIndex, PassCond
  local ArgStr, Cnt, @@Exit

  CreateProcNameStringA ProcName
  AddToResTypeHookList ResTypeName, DllName, ProcName
  DefineHook ProcName, ResTypeName                      ;; Prepare hook storage

  ArgStr textequ <>                                     ;; Prepare argument list
  Cnt = 0
  repeat ArgCount
    Cnt = Cnt + 1
    ArgStr CatStr ArgStr, <, >, <Arg>, %Cnt, <:XWORD>
  endm

  Detour_&ProcName& proc uses xbx xdi ArgStr            ;; Procedure declaration
    local xCallResult:XWORD
    local hThread:HANDLE, Context:CONTEXT, Stack:STACK  ;; Used by AnalyseStack

    InvokeOriginalCall ProcName, ArgCount

    .if dResGuardEnabled != FALSE
      mov xCallResult, xax

  ifnb <PassCond>
      .if PassCond
        jmp @@Exit
      .endif
  endif
      AnalyseStack ProcName                             ;; xbx -> CallData object

  if CallIdentifier gt 0
      mov xcx, Arg&CallIdentifier&
  elseif CallIdentifier eq 0
      mov xcx, xCallResult
  else
      mov xax, @CatStr(<Arg>, %(-CallIdentifier))
      .if xax != NULL
        mov xcx, [xax]
      .else
        xor ecx, ecx
      .endif
  endif
      mov [xbx].$Obj(CallData).xData1, xcx
;      mov [xbx].$Obj(CallData).xData2, 0

  ifnb <SuccessCond>
      .if SuccessCond
  endif
  ifnb <RemoveArgIndex>
        @CatStr(<OCall >, pRTCC_&ResTypeName, <::RTC_Collection.Remove, Arg>, %RemoveArgIndex, <, 0>)
        .if eax == 0
          lea xax, LogiErrColl
          mov [xbx].$Obj(CallData).pOwner, xax
          OCall xax::RTC_Collection.Insert, xbx
          jmp @@Exit
        .endif
  endif
        OCall pRTCC_&ResTypeName::RTC_Collection.Insert, xbx
        mov xax, pRTCC_&ResTypeName
        mov [xbx].$Obj(CallData).pOwner, xax

  ifnb <SuccessCond>
      .else
        lea xax, FailErrColl
        mov [xbx].$Obj(CallData).pOwner, xax
        OCall xax::RTC_Collection.Insert, xbx
      .endif
  endif
@@Exit:
      mov xax, xCallResult                              ;; Restore call return value
    .endif
    ret
  Detour_&ProcName& endp
endm

; --------------------------------------------------------------------------------------------------
; Macro:      DetourRelease
; Purpose:    Creates a detour procedure to intercept a call that releases an OS resource.
; Arguments:  Arg1: DLL full name.
;             Arg2: API procedure name.
;             Arg3: Procedure argument count.
;             Arg4: ID = x:   ID used to signal where the value identifying the OS resource
;                             (Handle, Pointer, Counter, String) is coming.
;                     x > 0 : Argument x
;                     x = 0 : Call result (return value)
;                     x < 0 : [Argument -x] (dereference)
;             Arg5: Procedure success condition.
;             Arg6: Resource type name, used to group calls related to the same OS resource type.
;             Arg7: (optional) List of additional Resource type names where the OS resource
;                   could have been acquired.
; Return:     Nothing.

DetourRelease macro DllName:req, ProcName:req, ArgCount:req, CallIdentifier:req, SuccessCond:req, \
                    ResTypeName:req, ResTypeNameList:vararg
  local ArgStr, Cnt, @@Exit

  CreateProcNameStringA ProcName
  AddToResTypeHookList ResTypeName, DllName, ProcName
  DefineHook ProcName

  ArgStr textequ <>
  Cnt = 0
  repeat ArgCount
    Cnt = Cnt + 1
    ArgStr CatStr ArgStr, <, >, <Arg>, %Cnt, <:XWORD>
  endm

  Detour_&ProcName& proc uses xbx xdi ArgStr            ;; Procedure declaration
    local xCallResult:XWORD
    local hThread:HANDLE, Context:CONTEXT, Stack:STACK  ;; Used by AnalyseStack        

    InvokeOriginalCall ProcName, ArgCount

    .if dResGuardEnabled != FALSE
      mov xCallResult, xax

      AnalyseStack ProcName                             ;; xbx -> CallData object

  if CallIdentifier gt 0
      mov xcx, Arg&CallIdentifier&
  elseif CallIdentifier eq 0
      mov xcx, xCallResult
  else
      mov xax, @CatStr(<Arg>, %(-CallIdentifier))
      .if xax != NULL
        mov xcx, [xax]
      .else
        xor ecx, ecx
      .endif
  endif
      mov [xbx].$Obj(CallData).xData1, xcx
;      mov [xbx].$Obj(CallData).xData2, 0

  ifnb <SuccessCond>
      .if SuccessCond
  endif
        @CatStr(<OCall pRTCC_>, <ResTypeName>, <::RTC_Collection.Remove, [xbx].$Obj(CallData).xData1, 0>)
        test eax, eax
        jnz @@Exit                                      ;; Exit if removed
        for ResTypeName, <ResTypeNameList>              ;; Search in all additional RTC_Collections
          @CatStr(<OCall pRTCC_>, <ResTypeName>, <::RTC_Collection.Remove, [xbx].$Obj(CallData).xData1, 0>)
          test eax, eax
          jnz @@Exit                                    ;; Exit if removed
        endm
        lea xax, LogiErrColl
        mov [xbx].$Obj(CallData).pOwner, xax
        OCall xax::RTC_Collection.Insert, xbx

  ifnb <SuccessCond>
        jmp @@Exit
      .endif

      lea xax, FailErrColl
      mov [xbx].$Obj(CallData).pOwner, xax
      OCall xax::RTC_Collection.Insert, xbx
  endif
@@Exit:
      mov xax, xCallResult                              ;; Restore call return value
    .endif
    ret
  Detour_&ProcName& endp
endm

; --------------------------------------------------------------------------------------------------
; Macro:      DetourAcquireNamed
; Purpose:    Creates a detour procedure to intercept calls that acquire an OS resource by using
;             an identifier string.
; Arguments:  Arg1: DLL full name.
;             Arg2: API procedure name.
;             Arg3: Procedure argument count.
;             Arg4: ID = x:     (This is the returned value used to identify the OS resource)
;                     x > 0 : Argument x
;                     x = 0 : Call result (return value)
;                     x < 0 : [Argument -x] (dereference)
;             Arg5: Procedure success condition.
;             Arg6: Resource type name, used to group calls related to the same OS resource type.
; Return:     Nothing.

DetourAcquireNamed macro DllName:req, ProcName:req, ArgCount:req, CallIdentifier:req, \
                        SuccessCond:req, ResTypeName:req
  local ArgStr, Cnt

  CreateProcNameStringA ProcName
  AddToResTypeHookList ResTypeName, DllName, ProcName
  DefineHook ProcName, ResTypeName

  ArgStr textequ <>                                     ;; Prepare argument list
  Cnt = 0
  repeat ArgCount
    Cnt = Cnt + 1
    ArgStr CatStr ArgStr, <, >, <Arg>, %Cnt, <:XWORD>
  endm

  Detour_&ProcName& proc uses xbx xdi ArgStr            ;; Procedure declaration
    local xCallResult:XWORD, hThread:HANDLE
    local Context:CONTEXT, Stack:STACK

    InvokeOriginalCall ProcName, ArgCount

    .if dResGuardEnabled != FALSE
      mov xCallResult, xax

      AnalyseStack ProcName                             ;; xbx -> CallData object

  if CallIdentifier gt 0
      mov xcx, Arg&CallIdentifier&
  elseif CallIdentifier eq 0
      mov xcx, xCallResult
  else
      mov xax, @CatStr(<Arg>, %(-CallIdentifier))
      .if xax != NULL
        mov xcx, [xax]
      .else
        xor ecx, ecx
      .endif
  endif
      mov [xbx].$Obj(CallData).xData1, xcx
;      mov [xbx].$Obj(CallData).xData2, 0

      .if SuccessCond
        ;In case that this named proc was called previously, we remove this call data
        OCall pRTCC_&ResTypeName&::RTC_Collection.Remove, [xbx].$Obj(CallData).xData1, [xbx].$Obj(CallData).xData2

        OCall pRTCC_&ResTypeName&::RTC_Collection.Insert, xbx
        mov xax, pRTCC_&ResTypeName&
        mov [xbx].$Obj(CallData).pOwner, xax
      .else
        lea xax, FailErrColl
        mov [xbx].$Obj(CallData).pOwner, xax
        OCall xax::RTC_Collection.Insert, xbx
      .endif

      mov xax, xCallResult                              ;; Restore call return value
    .endif
    ret
  Detour_&ProcName& endp
endm

; --------------------------------------------------------------------------------------------------
; Macro:      DetourAcquireCounted
; Purpose:    Creates a detour procedure to intercept calls that cummulate.
; Arguments:  Arg1: DLL full name.
;             Arg2: API procedure name.
;             Arg3: Procedure argument count.
;             Arg4: Counter name (created separately).
;             Arg5: Procedure success condition.
;             Arg6: Resource type name, used to group calls related to the same OS resource type.
; Return:     Nothing.

DetourAcquireCounted macro DllName:req, ProcName:req, ArgCount:req, CounterName:req, \
                          SuccessCond:req, ResTypeName:req
  local ArgStr, Cnt

  CreateProcNameStringA ProcName
  AddToResTypeHookList ResTypeName, DllName, ProcName
  DefineHook ProcName, ResTypeName

  ArgStr textequ <>                                     ;; Prepare argument list
  Cnt = 0
  repeat ArgCount
    Cnt = Cnt + 1
    ArgStr CatStr ArgStr, <, >, <Arg>, %Cnt, <:XWORD>
  endm

  Detour_&ProcName& proc uses xbx xdi ArgStr            ;; Procedure declaration
    local xCallResult:XWORD, hThread:HANDLE
    local Context:CONTEXT, Stack:STACK

    InvokeOriginalCall ProcName, ArgCount

    .if dResGuardEnabled != FALSE
      mov xCallResult, xax

      AnalyseStack ProcName                             ;; xbx -> CallData object

      .if SuccessCond
        inc CounterName
        m2m [xbx].$Obj(CallData).xData1, CounterName, xax
;        mov [xbx].$Obj(CallData).xData2, 0
        OCall pRTCC_&ResTypeName&::RTC_Collection.Insert, xbx
        mov xax, pRTCC_&ResTypeName&
        mov [xbx].$Obj(CallData).pOwner, xax
      .else
        mov [xbx].$Obj(CallData).xData1, -1
        lea xax, FailErrColl
        mov [xbx].$Obj(CallData).pOwner, xax
        OCall xax::RTC_Collection.Insert, xbx
      .endif

      mov xax, xCallResult                              ;; Restore call return value
    .endif
    ret
  Detour_&ProcName& endp
endm

; --------------------------------------------------------------------------------------------------
; Macro:      DetourReleaseCounted
; Purpose:    Create a counted detour procedure to intercept deallocation APIs.
; Arguments:  Arg1: DLL full name.
;             Arg2: API procedure name.
;             Arg3: Procedure argument count.
;             Arg4: Counter name.
;             Arg5: Procedure success condition.
;             Arg6: Resource type name, used to group calls related to the same OS resource type.
;             Arg7: (optional) List of additional Resource type names where the OS resource
;                   could have been acquired.
; Return:     Nothing.

DetourReleaseCounted macro DllName:req, ProcName:req, ArgCount:req, CounterName:req, \
                           SuccessCond:req, ResTypeName:req, ResTypeNameList:vararg
  local ArgStr, Cnt, @@Exit

  CreateProcNameStringA ProcName
  AddToResTypeHookList ResTypeName, DllName, ProcName
  DefineHook ProcName

  ArgStr textequ <>
  Cnt = 0
  repeat ArgCount
    Cnt = Cnt + 1
    ArgStr CatStr ArgStr, <, >, <Arg>, %Cnt, <:DWORD>
  endm

  Detour_&ProcName& proc uses xbx xdi ArgStr            ;; Procedure declaration
    local xCallResult:XWORD, hThread:HANDLE
    local Context:CONTEXT, Stack:STACK

    InvokeOriginalCall ProcName, ArgCount

    .if dResGuardEnabled != FALSE
      mov xCallResult, xax

      AnalyseStack ProcName                             ;; xbx -> CallData object

      m2m [xbx].$Obj(CallData).xData1, CounterName, xcx
;      mov [xbx].$Obj(CallData).xData2, 0

  ifnb <SuccessCond>
      .if SuccessCond
  endif
        @CatStr(<OCall pRTCC_>, <ResTypeName>, <::RTC_Collection.Remove, >, CounterName, <, 0>)
        test eax, eax
        jnz @@Exit                                      ;; Exit if removed
        for ResTypeName, <ResTypeNameList>              ;; Search in all additional RTC_Collections
          @CatStr(<OCall pRTCC_>, <ResTypeName>, <::RTC_Collection.Remove, >, CounterName, <, 0>)
          .if eax != FALSE
            dec CounterName
            jmp @@Exit                                  ;; Exit if removed
          .endif
        endm
        lea xax, LogiErrColl
        mov [xbx].$Obj(CallData).pOwner, xax
        OCall xax::RTC_Collection.Insert, xbx
  ifnb <SuccessCond>
        jmp @@Exit
      .endif
      lea xax, FailErrColl
      mov [xbx].$Obj(CallData).pOwner, xax
      OCall xax::RTC_Collection.Insert, xbx
  endif
@@Exit:
      mov xax, xCallResult                              ;; Restore call return value
    .endif
    ret
  Detour_&ProcName& endp
endm

; ==================================================================================================

DetourAcquire Kernel32.dll, CreateJobObjectA, 2, 0, <xCallResult !!= NULL>, Job
DetourAcquire Kernel32.dll, CreateJobObjectW, 2, 0, <xCallResult !!= NULL>, Job
DetourAcquire Kernel32.dll, OpenJobObjectA, 3, 0, <xCallResult !!= NULL>, Job
DetourAcquire Kernel32.dll, OpenJobObjectW, 3, 0, <xCallResult !!= NULL>, Job

; --------------------------------------------------------------------------------------------------

DetourAcquire KtmW32.dll, CreateTransactionA, 7, 0, <xCallResult !!= NULL>, Transaction
DetourAcquire KtmW32.dll, CreateTransactionW, 7, 0, <xCallResult !!= NULL>, Transaction
DetourAcquire KtmW32.dll, OpenTransactionA, 6, 0, <xCallResult !!= NULL>, Transaction
DetourAcquire KtmW32.dll, OpenTransactionW, 6, 0, <xCallResult !!= NULL>, Transaction

; --------------------------------------------------------------------------------------------------

DetourAcquire Kernel32.dll, CreatePrivateNamespaceA, 3, 0, <xCallResult !!= NULL>, PrivateNamespace
DetourAcquire Kernel32.dll, CreatePrivateNamespaceW, 3, 0, <xCallResult !!= NULL>, PrivateNamespace
DetourAcquire Kernel32.dll, OpenPrivateNamespaceA, 2, 0, <xCallResult !!= NULL>, PrivateNamespace
DetourAcquire Kernel32.dll, OpenPrivateNamespaceW, 2, 0, <xCallResult !!= NULL>, PrivateNamespace
DetourRelease Kernel32.dll, ClosePrivateNamespace, 2, 1, <BOOLEAN ptr xCallResult !!= 0>, PrivateNamespace

; --------------------------------------------------------------------------------------------------

DetourAcquire Kernel32.dll, HeapAlloc, 3, 0, <xCallResult !!= NULL>, HeapMemBlock
DetourAcquire Kernel32.dll, HeapReAlloc, 4, 0, <xCallResult !!= NULL>, HeapMemBlock, 3
DetourRelease Kernel32.dll, HeapFree, 3, 3, <xCallResult !!= FALSE>, HeapMemBlock

; --------------------------------------------------------------------------------------------------

DetourAcquire Kernel32.dll, GlobalAlloc, 2, 0, <xCallResult !!= NULL>, GlobalMemBlock
DetourAcquire Kernel32.dll, GlobalReAlloc, 3, 0, <xCallResult !!= NULL>, GlobalMemBlock, 1
DetourRelease Kernel32.dll, GlobalFree, 1, 1, <xCallResult == NULL>, GlobalMemBlock

; --------------------------------------------------------------------------------------------------

DetourAcquire Kernel32.dll, LocalAlloc, 2, 0, <xCallResult !!= NULL>, LocalMemBlock
DetourAcquire Kernel32.dll, LocalReAlloc, 3, 0, <xCallResult !!= NULL>, LocalMemBlock, 1
DetourAcquire Kernel32.dll, FormatMessageA, 7, -5, <xCallResult !!= 0>, LocalMemBlock,, <!!(Arg1 & FORMAT_MESSAGE_ALLOCATE_BUFFER)>
DetourAcquire Kernel32.dll, FormatMessageW, 7, -5, <xCallResult !!= 0>, LocalMemBlock,, <!!(Arg1 & FORMAT_MESSAGE_ALLOCATE_BUFFER)>
DetourRelease Kernel32.dll, LocalFree, 1, 1, <xCallResult == NULL>, LocalMemBlock

; --------------------------------------------------------------------------------------------------

DetourAcquire Kernel32.dll, HeapCreate, 3, 0, <xCallResult !!= NULL>, PrivateHeap
DetourRelease Kernel32.dll, HeapDestroy, 1, 1, <xCallResult !!= FALSE>, PrivateHeap

; --------------------------------------------------------------------------------------------------

DetourAcquire Ole32.dll, CoTaskMemAlloc, 1, 0, <xCallResult !!= NULL>, CoTaskMemBlock
DetourAcquire Ole32.dll, CoTaskMemRealloc, 2, 0, <xCallResult !!= NULL>, CoTaskMemBlock, 1
DetourRelease Ole32.dll, CoTaskMemFree, 1, 1, <>, CoTaskMemBlock

; --------------------------------------------------------------------------------------------------

DetourAcquire Kernel32.dll, VirtualAlloc, 4, 0, <xCallResult !!= NULL>, VirtualMemBlock
DetourAcquire Kernel32.dll, VirtualAllocEx, 5, 0, <xCallResult !!= NULL>, VirtualMemBlock
DetourAcquire Kernel32.dll, VirtualAlloc2, 7, 0, <xCallResult !!= NULL>, VirtualMemBlock
DetourRelease Kernel32.dll, VirtualFree, 3, 1, <xCallResult !!= FALSE>, VirtualMemBlock
DetourRelease Kernel32.dll, VirtualFreeEx, 4, 2, <xCallResult !!= FALSE>, VirtualMemBlock
DetourAcquire Kernel32.dll, VirtualAlloc2FromApp, 7, 0, <xCallResult !!= NULL>, VirtualMemBlock

; --------------------------------------------------------------------------------------------------

DetourAcquire OleAut32.dll, SysAllocString, 1, 0, <xCallResult !!= NULL>, SysString
DetourAcquire OleAut32.dll, SysAllocStringLen, 2, 0, <xCallResult !!= NULL>, SysString
DetourAcquire OleAut32.dll, SysAllocStringByteLen, 2, 0, <xCallResult !!= NULL>, SysString
DetourAcquire OleAut32.dll, SysReAllocString, 2, 0, <xCallResult !!= FALSE>, SysString
DetourAcquire OleAut32.dll, SysReAllocStringLen, 3, 0, <xCallResult !!= FALSE>, SysString
DetourRelease OleAut32.dll, SysFreeString, 1, 1, <>, SysString

; --------------------------------------------------------------------------------------------------

DetourAcquire User32.dll, CreateWindowExA, 12, 0, <xCallResult !!= NULL>, Window
DetourAcquire User32.dll, CreateWindowExW, 12, 0, <xCallResult !!= NULL>, Window
DetourRelease User32.dll, DestroyWindow, 1, 1, <xCallResult !!= FALSE>, Window

; --------------------------------------------------------------------------------------------------

DetourAcquire User32.dll, BeginPaint, 2, 0, <xCallResult !!= 0>, PaintStruct
DetourRelease User32.dll, EndPaint, 2, -2, <>, PaintStruct

; --------------------------------------------------------------------------------------------------

DetourAcquire Gdi32.dll, CreatePen, 3, 0, <xCallResult !!= NULL>, Pen
DetourAcquire Gdi32.dll, CreatePenIndirect, 1, 0, <xCallResult !!= NULL>, Pen
DetourAcquire Gdi32.dll, ExtCreatePen, 5, 0, <xCallResult !!= NULL>, Pen

; --------------------------------------------------------------------------------------------------

DetourAcquire Gdi32.dll, CreateSolidBrush, 1, 0, <xCallResult !!= NULL>, Brush
DetourAcquire Gdi32.dll, CreateDIBPatternBrush, 2, 0, <xCallResult !!= NULL>, Brush
DetourAcquire Gdi32.dll, CreateDIBPatternBrushPt, 2, 0, <xCallResult !!= NULL>, Brush
DetourAcquire Gdi32.dll, CreateHatchBrush, 2, 0, <xCallResult !!= NULL>, Brush
DetourAcquire Gdi32.dll, CreatePatternBrush, 1, 0, <xCallResult !!= NULL>, Brush
DetourAcquire Gdi32.dll, CreateBrushIndirect, 1, 0, <xCallResult !!= NULL>, Brush

; --------------------------------------------------------------------------------------------------

DetourAcquire Gdi32.dll, CreateBitmap, 5, 0, <xCallResult !!= NULL>, Bitmap
DetourAcquire Gdi32.dll, CreateBitmapIndirect, 1, 0, <xCallResult !!= NULL>, Bitmap
DetourAcquire Gdi32.dll, CreateCompatibleBitmap, 3, 0, <xCallResult !!= NULL>, Bitmap
DetourAcquire Gdi32.dll, CreateDIBitmap, 6, 0, <xCallResult !!= NULL>, Bitmap
DetourAcquire Gdi32.dll, CreateDIBSection, 6, 0, <xCallResult !!= NULL>, Bitmap
DetourAcquire Gdi32.dll, CreateDiscardableBitmap, 3, 0, <xCallResult !!= NULL>, Bitmap
DetourAcquire User32.dll, LoadBitmapA, 2, 0, <xCallResult !!= NULL>, Bitmap
DetourAcquire User32.dll, LoadBitmapW, 2, 0, <xCallResult !!= NULL>, Bitmap
DetourAcquire GdiPlus.dll, GdipCreateHBITMAPFromBitmap, 3, -2, <xCallResult == 0>, Bitmap

; --------------------------------------------------------------------------------------------------

DetourAcquire Gdi32.dll, CreateEllipticRgn, 4, 0, <xCallResult !!= NULL>, Region
DetourAcquire Gdi32.dll, CreateEllipticRgnIndirect, 1, 0, <xCallResult !!= NULL>, Region
DetourAcquire Gdi32.dll, CreatePolygonRgn, 3, 0, <xCallResult !!= NULL>, Region
DetourAcquire Gdi32.dll, CreatePolyPolygonRgn, 4, 0, <xCallResult !!= NULL>, Region
DetourAcquire Gdi32.dll, CreateRectRgn, 4, 0, <xCallResult !!= NULL>, Region
DetourAcquire Gdi32.dll, CreateRectRgnIndirect, 1, 0, <xCallResult !!= NULL>, Region
DetourAcquire Gdi32.dll, CreateRoundRectRgn, 6, 0, <xCallResult !!= NULL>, Region
DetourAcquire Gdi32.dll, ExtCreateRegion, 3, 0, <xCallResult !!= NULL>, Region
DetourAcquire Gdi32.dll, PathToRegion, 1, 0, <xCallResult !!= NULL>, Region
DetourRelease User32.dll, SetWindowRgn, 3, 2, <xCallResult !!= FALSE>, Region  ;; This region is destroyed by the window!

; --------------------------------------------------------------------------------------------------

DetourAcquire User32.dll, CopyImage, 5, 0, <xCallResult !!= NULL>, Image
DetourAcquire User32.dll, LoadImageA, 6, 0, <xCallResult !!= NULL>, Image
DetourAcquire User32.dll, LoadImageW, 6, 0, <xCallResult !!= NULL>, Image

; --------------------------------------------------------------------------------------------------

DetourAcquire Gdi32.dll, CreateFontA, 14, 0, <xCallResult !!= NULL>, Font
DetourAcquire Gdi32.dll, CreateFontW, 14, 0, <xCallResult !!= NULL>, Font
DetourAcquire Gdi32.dll, CreateFontIndirectA, 1, 0, <xCallResult !!= NULL>, Font
DetourAcquire Gdi32.dll, CreateFontIndirectW, 1, 0, <xCallResult !!= NULL>, Font
DetourAcquire Gdi32.dll, CreateFontIndirectExA, 1, 0, <xCallResult !!= NULL>, Font
DetourAcquire Gdi32.dll, CreateFontIndirectExW, 1, 0, <xCallResult !!= NULL>, Font

; --------------------------------------------------------------------------------------------------

DetourAcquire Gdi32.dll, CreatePalette, 1, 0, <xCallResult !!= NULL>, Palette
DetourAcquire Gdi32.dll, CreateHalftonePalette, 1, 0, <xCallResult !!= NULL>, Palette

; --------------------------------------------------------------------------------------------------

DetourAcquire Gdi32.dll, CreateColorSpaceA, 1, 0, <xCallResult !!= NULL>, ColorSpace
DetourAcquire Gdi32.dll, CreateColorSpaceW, 1, 0, <xCallResult !!= NULL>, ColorSpace

; --------------------------------------------------------------------------------------------------

DetourAcquire Gdi32.dll, GetStockObject, 1, 0, <xCallResult !!= NULL>, StockObject

; --------------------------------------------------------------------------------------------------

DetourAcquire Gdi32.dll, CreateDCA, 4, 0, <xCallResult !!= NULL>, DeviceContext
DetourAcquire Gdi32.dll, CreateDCW, 4, 0, <xCallResult !!= NULL>, DeviceContext
DetourAcquire Gdi32.dll, CreateCompatibleDC, 1, 0, <xCallResult !!= NULL>, DeviceContext
DetourAcquire Gdi32.dll, CreateICA, 4, 0, <xCallResult !!= NULL>, DeviceContext
DetourAcquire Gdi32.dll, CreateICW, 4, 0, <xCallResult !!= NULL>, DeviceContext
DetourRelease Gdi32.dll, DeleteDC, 1, 1, <xCallResult !!= FALSE>, DeviceContext

; --------------------------------------------------------------------------------------------------

DetourRelease Gdi32.dll, DeleteObject, 1, 1, <xCallResult !!= FALSE>, Pen, Brush, Bitmap, \
              Region, Font, Palette, ColorSpace, Image, StockObject, DeviceContext

; --------------------------------------------------------------------------------------------------

DetourAcquire User32.dll, CreateCursor, 7, 0, <xCallResult !!= NULL>, Cursor
DetourAcquire User32.dll, LoadCursorA, 2, 0, <xCallResult !!= NULL>, Cursor,, <Arg1 == NULL>
DetourAcquire User32.dll, LoadCursorW, 2, 0, <xCallResult !!= NULL>, Cursor,, <Arg1 == NULL>
DetourAcquire User32.dll, LoadCursorFromFileA, 1, 0, <xCallResult !!= NULL>, Cursor
DetourAcquire User32.dll, LoadCursorFromFileW, 1, 0, <xCallResult !!= NULL>, Cursor
DetourRelease User32.dll, SetSystemCursor, 2, 1, <xCallResult !!= FALSE>, Cursor  ;; Destroys src Cursor

externdef pRTCC_Icon:$ObjPtr(RTC_Collection)            ; DestroyCursor and DestroyIcon use the same API
DetourRelease User32.dll, DestroyCursor, 1, 1, <xCallResult !!= FALSE>, Cursor, Icon, Image

; --------------------------------------------------------------------------------------------------

DetourAcquire User32.dll, CopyIcon, 1, 0, <xCallResult !!= NULL>, Icon
DetourAcquire User32.dll, CreateIcon, 7, 0, <xCallResult !!= NULL>, Icon
DetourAcquire User32.dll, CreateIconIndirect, 1, 0, <xCallResult !!= NULL>, Icon
DetourAcquire User32.dll, CreateIconFromResource, 4, 0, <xCallResult !!= NULL>, Icon
DetourAcquire User32.dll, CreateIconFromResourceEx, 7, 0, <xCallResult !!= NULL>, Icon
DetourAcquire Shell32.dll, DuplicateIcon, 2, 0, <xCallResult !!= NULL>, Icon
DetourAcquire User32.dll, LoadIconA, 2, 0, <xCallResult !!= NULL>, Icon
DetourAcquire User32.dll, LoadIconW, 2, 0, <xCallResult !!= NULL>, Icon
DetourAcquire Shell32.dll, ExtractIconA, 3, 0, <xCallResult !!= NULL>, Icon
DetourAcquire Shell32.dll, ExtractIconW, 3, 0, <xCallResult !!= NULL>, Icon

; --------------------------------------------------------------------------------------------------
; Macro:      DetourAcquireExtractIconEx
; Purpose:    Creates a detour for ExtractIconExA/W.
;             The return value is a count/status, NOT a handle:
;               0xFFFFFFFF : file not found                       -> tracked as a failed call
;               0          : icon-count query (nIconIndex==-1) or nIcons==0 -> nothing extracted
;               n > 0      : n icons extracted into phiconLarge/phiconSmall (either may be NULL)
;             Each non-NULL HANDLE found in either output array is tracked as a separate Icon.
; Arguments:  Arg1: DLL full name.
;             Arg2: API procedure name.
; Return:     Nothing.

DetourAcquireExtractIconEx macro DllName:req, ProcName:req
  CreateProcNameStringA ProcName
  AddToResTypeHookList Icon, DllName, ProcName
  DefineHook ProcName, Icon

  Detour_&ProcName& proc uses xbx xdi xsi, Arg1:XWORD, Arg2:XWORD, Arg3:XWORD, Arg4:XWORD, Arg5:XWORD
    local xCallResult:XWORD, hThread:HANDLE
    local Context:CONTEXT, Stack:STACK
    local dGotAny:DWORD

    InvokeOriginalCall ProcName, 5

    .if dResGuardEnabled != FALSE
      mov xCallResult, xax

      .if xCallResult == 0xFFFFFFFF                     ;; File not found
        AnalyseStack ProcName                           ;; xbx -> CallData object

        lea xax, FailErrColl
        mov [xbx].$Obj(CallData).pOwner, xax
        OCall xax::RTC_Collection.Insert, xbx

      .elseif xCallResult != 0                          ;; xCallResult icons were extracted
        AnalyseStack ProcName                           ;; xbx -> base CallData (carries the stack trace)
        mov dGotAny, FALSE

        xor edi, edi                                    ;; xdi = array index
        .while xdi < xCallResult
          ;; ---- phiconLarge[xdi] ----
          mov xax, Arg3
          .if xax != NULL
            mov xcx, [xax + xdi*sizeof(HANDLE)]
            .if xcx != NULL
              .if dGotAny == FALSE
                mov [xbx].$Obj(CallData).xData1, xcx
;                mov [xbx].$Obj(CallData).xData2, 0
                mov xax, pRTCC_Icon
                mov [xbx].$Obj(CallData).pOwner, xax
                OCall xax::RTC_Collection.Insert, xbx
                mov dGotAny, TRUE
              .else
                mov xsi, $MemAlloc(sizeof $Obj(CallData))
                s2s $Obj(CallData) ptr [xsi], $Obj(CallData) ptr [xbx], \
                    xmm0, xmm1, xmm2, xmm3, xmm4, xmm5, xmm6, xmm7, xax, xdx
                mov [xsi].$Obj(CallData).xData1, xcx
                mov [xsi].$Obj(CallData).xData2, 0
                mov xax, pRTCC_Icon
                mov [xsi].$Obj(CallData).pOwner, xax
                OCall xax::RTC_Collection.Insert, xsi
              .endif
            .endif
          .endif

          ;; ---- phiconSmall[xdi] ----
          mov xax, Arg4
          .if xax != NULL
            mov xcx, [xax + xdi*sizeof(HANDLE)]
            .if xcx != NULL
              .if dGotAny == FALSE
                mov [xbx].$Obj(CallData).xData1, xcx
;                mov [xbx].$Obj(CallData).xData2, 0
                mov xax, pRTCC_Icon
                mov [xbx].$Obj(CallData).pOwner, xax
                OCall xax::RTC_Collection.Insert, xbx
                mov dGotAny, TRUE
              .else
                mov xsi, $MemAlloc(sizeof $Obj(CallData))
                s2s $Obj(CallData) ptr [xsi], $Obj(CallData) ptr [xbx], \
                    xmm0, xmm1, xmm2, xmm3, xmm4, xmm5, xmm6, xmm7, xax, xdx
                mov [xsi].$Obj(CallData).xData1, xcx
                mov [xsi].$Obj(CallData).xData2, 0
                mov xax, pRTCC_Icon
                mov [xsi].$Obj(CallData).pOwner, xax
                OCall xax::RTC_Collection.Insert, xsi
              .endif
            .endif
          .endif

          inc xdi
        .endw

        .if dGotAny == FALSE                            ;; Both arrays NULL, or no live handles in them
          Destroy xbx
        .endif
      .endif
      ;; xCallResult == 0 (count query / nIcons==0): nothing allocated, no CallData needed

      mov xax, xCallResult                              ;; Restore call return value
    .endif
    ret
  Detour_&ProcName& endp
endm

DetourAcquireExtractIconEx Shell32.dll, ExtractIconExA
DetourAcquireExtractIconEx Shell32.dll, ExtractIconExW

DetourAcquire Shell32.dll, ExtractAssociatedIconA, 3, 0, <xCallResult !!= NULL>, Icon
DetourAcquire Shell32.dll, ExtractAssociatedIconW, 3, 0, <xCallResult !!= NULL>, Icon
DetourAcquire Comctl32.dll, LoadIconMetric, 4, -4, <xCallResult == S_OK>, Icon
DetourAcquire Comctl32.dll, LoadIconWithScaleDown, 5, -5, <xCallResult == S_OK>, Icon
DetourAcquire Comctl32.dll, ImageList_GetIcon, 3, 0, <xCallResult !!= NULL>, Icon
DetourAcquire GdiPlus.dll, GdipCreateHICONFromBitmap, 2, -2, <xCallResult == 0>, Icon

; --------------------------------------------------------------------------------------------------
; Macro:      DetourAcquireSHGetFileInfo
; Purpose:    Creates a detour for SHGetFileInfoA/W.
;             Real signature:
;               DWORD_PTR SHGetFileInfoA(LPCSTR pszPath, DWORD dwFileAttributes,
;                                        SHFILEINFOA *psfi, UINT cbFileInfo, UINT uFlags);
;             psfi->hIcon is the FIRST member of SHFILEINFO(A/W) (offset 0), so dereferencing
;             psfi itself yields hIcon -- but it is only populated when uFlags includes
;             SHGFI_ICON; for any other flag combination (SHGFI_DISPLAYNAME, SHGFI_TYPENAME,
;             SHGFI_EXETYPE, etc.) the field is untouched/undefined and must NOT be tracked.
; Arguments:  Arg1: DLL full name.
;             Arg2: API procedure name.
; Return:     Nothing.

ifndef SHGFI_ICON
  SHGFI_ICON equ 0000100h           ; Define only if not already pulled in via Windows includes
endif

DetourAcquireSHGetFileInfo macro DllName:req, ProcName:req
  CreateProcNameStringA ProcName
  AddToResTypeHookList Icon, DllName, ProcName
  DefineHook ProcName, Icon

  Detour_&ProcName& proc uses xbx xdi, Arg1:XWORD, Arg2:XWORD, Arg3:XWORD, Arg4:XWORD, Arg5:XWORD
    local xCallResult:XWORD, hThread:HANDLE
    local Context:CONTEXT, Stack:STACK

    InvokeOriginalCall ProcName, 5

    .if dResGuardEnabled != FALSE
      mov xCallResult, xax

      mov xax, Arg5
      .if (xax & SHGFI_ICON)                            ;; Only meaningful when an icon was requested
        .if (xCallResult != 0) && (Arg3 != NULL)
          AnalyseStack ProcName                         ;; xbx -> CallData object
          mov xax, Arg3                                 ;; -> SHFILEINFO(A/W); hIcon is the first member
          mov xcx, [xax]                                ;; psfi->hIcon
          .if xcx != NULL
            mov [xbx].$Obj(CallData).xData1, xcx
;            mov [xbx].$Obj(CallData).xData2, 0
            mov xax, pRTCC_Icon
            mov [xbx].$Obj(CallData).pOwner, xax
            OCall xax::RTC_Collection.Insert, xbx
          .else
            Destroy xbx                                 ;; SHGFI_ICON was requested but no icon resulted
          .endif
        .else
          AnalyseStack ProcName                         ;; xbx -> CallData object
          lea xax, FailErrColl
          mov [xbx].$Obj(CallData).pOwner, xax
          OCall xax::RTC_Collection.Insert, xbx
        .endif
      .endif
      ;; SHGFI_ICON not requested: nothing to track, no CallData created

      mov xax, xCallResult                              ;; Restore call return value
    .endif
    ret
  Detour_&ProcName& endp
endm

DetourAcquireSHGetFileInfo Shell32.dll, SHGetFileInfoA
DetourAcquireSHGetFileInfo Shell32.dll, SHGetFileInfoW

; --------------------------------------------------------------------------------------------------
; Macro:      DetourAcquirePrivateExtractIconsX
; Purpose:    Creates a detour procedure to intercept calls that acquire an array of icons.
; Arguments:  Arg1: DLL full name.
;             Arg2: API procedure name.
; Return:     Nothing.

DetourAcquirePrivateExtractIconsX macro DllName:req, ProcName:req
  local ArgStr, Cnt

  CreateProcNameStringA ProcName
  AddToResTypeHookList Icon, DllName, ProcName
  DefineHook ProcName, Icon

  ArgStr textequ <>                                     ;; Prepare argument list
  Cnt = 0
  repeat 8
    Cnt = Cnt + 1
    ArgStr CatStr ArgStr, <, >, <Arg>, %Cnt, <:XWORD>
  endm

  Detour_&ProcName& proc uses xbx xdi xsi ArgStr        ;; Procedure declaration
    local xCallResult:XWORD, hThread:HANDLE
    local Context:CONTEXT, Stack:STACK

    InvokeOriginalCall ProcName, 8

    .if dResGuardEnabled != FALSE
      .if xax != 0
        mov xCallResult, xax
        AnalyseStack ProcName                           ;; xbx -> CallData object
        .if xCallResult == 0xFFFFFFFF                   ;; File is not found
          lea xax, FailErrColl
          mov [xbx].$Obj(CallData).pOwner, xax
          OCall xax::RTC_Collection.Insert, xbx
        .else
          xor esi, esi
          .if Arg5 != NULL 
            .while xsi < xCallResult
              MemAlloc sizeof($Obj(CallData))
              s2s $Obj(CallData) ptr [xax], $Obj(CallData) ptr [xbx], xmm0, xmm1, xmm2, xmm3, xmm4, xmm5, xmm6, xmm7, xcx, xdx
              mov xdx, Arg5
              m2m [xax].$Obj(CallData).xData1, [xdx + xsi*sizeof(HANDLE)], xcx
              mov [xax].$Obj(CallData).xData2, 0
              mov [xax].$Obj(CallData).pOwner, xcx
              OCall pRTCC_Icon::RTC_Collection.Insert, xax
              inc esi
            .endw
          .endif
          Destroy xbx
        .endif
        mov xax, xCallResult                            ;; Restore call return value
      .endif
    .endif
    ret
  Detour_&ProcName& endp
endm

; --------------------------------------------------------------------------------------------------

DetourAcquirePrivateExtractIconsX User32.dll, PrivateExtractIconsA
DetourAcquirePrivateExtractIconsX User32.dll, PrivateExtractIconsW

; DestroyCursor and DestroyIcon use the same API
DetourRelease User32.dll, DestroyIcon, 1, 1, <xCallResult !!= FALSE>, Icon, Cursor, Image

; --------------------------------------------------------------------------------------------------

DetourAcquire User32.dll, CreateMenu, 0, 0, <xCallResult !!= NULL>, Menu
DetourAcquire User32.dll, CreatePopupMenu, 0, 0, <xCallResult !!= NULL>, Menu
DetourAcquire User32.dll, LoadMenuA, 2, 0, <xCallResult !!= NULL>, Menu
DetourAcquire User32.dll, LoadMenuW, 2, 0, <xCallResult !!= NULL>, Menu
DetourAcquire User32.dll, LoadMenuIndirectA, 1, 0, <xCallResult !!= NULL>, Menu
DetourAcquire User32.dll, LoadMenuIndirectW, 1, 0, <xCallResult !!= NULL>, Menu
DetourRelease User32.dll, DestroyMenu, 1, 1, <xCallResult !!= FALSE>, Menu

; --------------------------------------------------------------------------------------------------

DetourAcquire Comctl32.dll, ImageList_Create, 5, 0, <xCallResult !!= NULL>, ImageList
DetourRelease Comctl32.dll, ImageList_Destroy, 1, 1, <xCallResult !!= FALSE>, ImageList

; --------------------------------------------------------------------------------------------------
DetourAcquire Gdi32.dll, CloseMetaFile, 1, 0, <xCallResult !!= NULL>, MetaFile
DetourAcquire Gdi32.dll, CopyMetaFileA, 2, 0, <xCallResult !!= NULL>, MetaFile
DetourAcquire Gdi32.dll, CopyMetaFileW, 2, 0, <xCallResult !!= NULL>, MetaFile
DetourAcquire Gdi32.dll, CreateMetaFileA, 1, 0, <xCallResult !!= NULL>, MetaFile
DetourAcquire Gdi32.dll, CreateMetaFileW, 1, 0, <xCallResult !!= NULL>, MetaFile
DetourAcquire Gdi32.dll, GetMetaFileA, 1, 0, <xCallResult !!= NULL>, MetaFile
DetourAcquire Gdi32.dll, GetMetaFileW, 1, 0, <xCallResult !!= NULL>, MetaFile
DetourAcquire Gdi32.dll, SetMetaFileBitsEx, 2, 0, <xCallResult !!= NULL>, MetaFile
DetourRelease Gdi32.dll, DeleteMetaFile, 1, 1, <xCallResult !!= FALSE>, MetaFile

; --------------------------------------------------------------------------------------------------

DetourAcquire Gdi32.dll, CloseEnhMetaFile, 1, 0, <xCallResult !!= NULL>, EnhMetaFile
DetourAcquire Gdi32.dll, CopyEnhMetaFileA, 2, 0, <xCallResult !!= NULL>, EnhMetaFile
DetourAcquire Gdi32.dll, CopyEnhMetaFileW, 2, 0, <xCallResult !!= NULL>, EnhMetaFile
DetourAcquire Gdi32.dll, CreateEnhMetaFileA, 1, 0, <xCallResult !!= NULL>, EnhMetaFile
DetourAcquire Gdi32.dll, CreateEnhMetaFileW, 1, 0, <xCallResult !!= NULL>, EnhMetaFile
DetourAcquire Gdi32.dll, GetEnhMetaFileA, 1, 0, <xCallResult !!= NULL>, EnhMetaFile
DetourAcquire Gdi32.dll, GetEnhMetaFileW, 1, 0, <xCallResult !!= NULL>, EnhMetaFile
DetourAcquire Gdi32.dll, SetEnhMetaFileBits, 2, 0, <xCallResult !!= NULL>, EnhMetaFile
DetourAcquire Gdi32.dll, SetWinMetaFileBits, 4, 0, <xCallResult !!= NULL>, EnhMetaFile
DetourRelease Gdi32.dll, DeleteEnhMetaFile, 1, 1, <xCallResult !!= FALSE>, EnhMetaFile

; --------------------------------------------------------------------------------------------------

DetourAcquire User32.dll, CreateAcceleratorTableA, 2, 0, <xCallResult !!= NULL>, AccTable
DetourAcquire User32.dll, CreateAcceleratorTableW, 2, 0, <xCallResult !!= NULL>, AccTable
DetourAcquire User32.dll, LoadAcceleratorsA, 2, 0, <xCallResult !!= NULL>, AccTable
DetourAcquire User32.dll, LoadAcceleratorsW, 2, 0, <xCallResult !!= NULL>, AccTable
DetourRelease User32.dll, DestroyAcceleratorTable, 1, 1, <xCallResult !!= FALSE>, AccTable

; --------------------------------------------------------------------------------------------------

DetourAcquire User32.dll, CreateDesktopA, 6, 0, <xCallResult !!= NULL>, Desktop
DetourAcquire User32.dll, CreateDesktopW, 6, 0, <xCallResult !!= NULL>, Desktop
DetourAcquire User32.dll, CreateDesktopExA, 8, 0, <xCallResult !!= NULL>, Desktop
DetourAcquire User32.dll, CreateDesktopExW, 8, 0, <xCallResult !!= NULL>, Desktop
DetourRelease User32.dll, CloseDesktop, 1, 1, <xCallResult !!= FALSE>, Desktop
DetourAcquire User32.dll, OpenDesktopA, 4, 0, <xCallResult !!= NULL>, Desktop
DetourAcquire User32.dll, OpenDesktopW, 4, 0, <xCallResult !!= NULL>, Desktop
DetourAcquire User32.dll, OpenInputDesktop, 3, 0, <xCallResult !!= NULL>, Desktop

; --------------------------------------------------------------------------------------------------

DetourAcquire User32.dll, CreateWindowStationA, 4, 0, <xCallResult !!= NULL>, WindowStation
DetourAcquire User32.dll, CreateWindowStationW, 4, 0, <xCallResult !!= NULL>, WindowStation
DetourAcquire User32.dll, OpenWindowStationA, 3, 0, <xCallResult !!= NULL>, WindowStation
DetourAcquire User32.dll, OpenWindowStationW, 3, 0, <xCallResult !!= NULL>, WindowStation
DetourRelease User32.dll, CloseWindowStation, 1, 1, <xCallResult !!= FALSE>, WindowStation

; --------------------------------------------------------------------------------------------------

DetourAcquire Kernel32.dll, CreateFileA, 7, 0, <xCallResult !!= INVALID_HANDLE_VALUE>, File
DetourAcquire Kernel32.dll, CreateFileW, 7, 0, <xCallResult !!= INVALID_HANDLE_VALUE>, File
DetourAcquire Kernel32.dll, CreateFileTransactedA, 10, 0, <xCallResult !!= INVALID_HANDLE_VALUE>, File
DetourAcquire Kernel32.dll, CreateFileTransactedW, 10, 0, <xCallResult !!= INVALID_HANDLE_VALUE>, File
DetourAcquire Kernel32.dll, ReOpenFile, 4, 0, <xCallResult !!= INVALID_HANDLE_VALUE>, File
DetourAcquire Kernel32.dll, CreateFile2, 5, 0, <xCallResult !!= INVALID_HANDLE_VALUE>, File

; --------------------------------------------------------------------------------------------------

DetourAcquire Advapi32.dll, OpenEncryptedFileRawA, 3, -3, <xCallResult == ERROR_SUCCESS>, EncryptedFile
DetourAcquire Advapi32.dll, OpenEncryptedFileRawW, 3, -3, <xCallResult == ERROR_SUCCESS>, EncryptedFile
DetourRelease Advapi32.dll, CloseEncryptedFileRaw, 1, 1, <>, EncryptedFile

; --------------------------------------------------------------------------------------------------

DetourAcquire Kernel32.dll, CreateEventA, 4, 0, <xCallResult !!= NULL>, Event
DetourAcquire Kernel32.dll, CreateEventW, 4, 0, <xCallResult !!= NULL>, Event
DetourAcquireNamed Kernel32.dll, CreateEventExA, 4, 0, <xCallResult !!= NULL>, Event
DetourAcquireNamed Kernel32.dll, CreateEventExW, 4, 0, <xCallResult !!= NULL>, Event
DetourAcquire Kernel32.dll, OpenEventA, 3, 0, <xCallResult !!= NULL>, Event
DetourAcquire Kernel32.dll, OpenEventW, 3, 0, <xCallResult !!= NULL>, Event

; --------------------------------------------------------------------------------------------------

DetourAcquireNamed Kernel32.dll, CreateFileMappingA, 6, 0, <xCallResult !!= NULL>, FileMapping
DetourAcquireNamed Kernel32.dll, CreateFileMappingW, 6, 0, <xCallResult !!= NULL>, FileMapping
DetourAcquireNamed Kernel32.dll, CreateFileMappingNumaA, 7, 0, <xCallResult !!= NULL>, FileMapping
DetourAcquireNamed Kernel32.dll, CreateFileMappingNumaW, 7, 0, <xCallResult !!= NULL>, FileMapping
DetourAcquireNamed Kernel32.dll, OpenFileMappingA, 3, 0, <xCallResult !!= NULL>, FileMapping
DetourAcquireNamed Kernel32.dll, OpenFileMappingW, 3, 0, <xCallResult !!= NULL>, FileMapping

; --------------------------------------------------------------------------------------------------

DetourAcquire Kernel32.dll, CreateIoCompletionPort, 4, 0, <xCallResult !!= NULL>, IoCompletionPort,, <Arg2 !!= INVALID_HANDLE_VALUE>

; --------------------------------------------------------------------------------------------------

DetourAcquire Kernel32.dll, CreateMutexA, 3, 0, <xCallResult !!= NULL>, Mutex
DetourAcquire Kernel32.dll, CreateMutexW, 3, 0, <xCallResult !!= NULL>, Mutex
DetourAcquire Kernel32.dll, OpenMutexA, 3, 0, <xCallResult !!= NULL>, Mutex
DetourAcquire Kernel32.dll, OpenMutexW, 3, 0, <xCallResult !!= NULL>, Mutex
DetourAcquire Kernel32.dll, CreateMutexExA, 4, 0, <xCallResult !!= NULL>, Mutex
DetourAcquire Kernel32.dll, CreateMutexExW, 4, 0, <xCallResult !!= NULL>, Mutex

; --------------------------------------------------------------------------------------------------

CreateProcNameStringA CreatePipe
AddToResTypeHookList Pipe, Kernel32.dll, CreatePipe
DefineHook CreatePipe, Pipe

; This detour proc handles the Read and Write HANDLEs
Detour_CreatePipe proc uses xbx xdi Arg1:XWORD, Arg2:XWORD, Arg3:XWORD, Arg4:XWORD
  local xCallResult:XWORD, hThread:HANDLE
  local Context:CONTEXT, Stack:STACK

  ANNOTATION use:Arg3 Arg4 Context Stack hThread

  InvokeOriginalCall CreatePipe, 4

  .if dResGuardEnabled != FALSE
    mov xCallResult, xax

    AnalyseStack CreatePipe                             ; xbx -> CallData object

    .if xCallResult != 0
      mov xcx, Arg1                                     ; -> hReadPipe
      .if xcx != NULL
        m2m [xbx].$Obj(CallData).xData1, [xcx], xdx
;        mov [xbx].$Obj(CallData).xData2, 0
        mov xax, pRTCC_Pipe
        mov [xbx].$Obj(CallData).pOwner, xax
        OCall xax::Collection.Insert, xbx
        .if Arg2 != NULL
          ; Clone existing CallData
          mov xdi, $MemAlloc(sizeof $Obj(CallData))
          s2s $Obj(CallData) ptr [xdi], $Obj(CallData) ptr [xbx], xmm0, xmm1, xmm2, xmm3, xmm4, xmm5, xmm6, xmm7, xax, xcx
          mov xcx, Arg2                                 ; -> hWritePipe
          m2m [xdi].$Obj(CallData).xData1, [xcx], xdx
          mov [xdi].$Obj(CallData).xData2, 0
          mov xax, pRTCC_Pipe
          mov [xdi].$Obj(CallData).pOwner, xax
          OCall xax::Collection.Insert, xdi
        .endif
      .else
        Destroy xbx
      .endif
    .else
      lea xax, FailErrColl
      mov [xbx].$Obj(CallData).pOwner, xax
      OCall xax::RTC_Collection.Insert, xbx
    .endif

    mov xax, xCallResult                                ; Restore call return value
  .endif
  ret
Detour_CreatePipe endp

DetourAcquireNamed Kernel32.dll, CreateNamedPipeA, 8, 0, <xCallResult !!= INVALID_HANDLE_VALUE>, Pipe
DetourAcquireNamed Kernel32.dll, CreateNamedPipeW, 8, 0, <xCallResult !!= INVALID_HANDLE_VALUE>, Pipe

; --------------------------------------------------------------------------------------------------
; Macro:      DetourAcquireCreateProcess
; Purpose:    Creates a detour for CreateProcess* variants.
;             Each successful call produces TWO tracked resources:
;               - hProcess stored in pRTCC_Process
;               - hThread  stored in pRTCC_Thread
;             The PROCESS_INFORMATION output struct pointer is always the last argument.
; Arguments:  Arg1: DLL name.
;             Arg2: API procedure name.
;             Arg3: Total argument count.
;             Arg4: Argument index of the LPPROCESS_INFORMATION output pointer.
; Return:     Nothing.

externdef pRTCC_Thread:$ObjPtr(RTC_Collection)

DetourAcquireCreateProcess macro DllName:req, ProcName:req, ArgCount:req, ProcInfoArgIndex:req
  local ArgStr, Cnt

  CreateProcNameStringA ProcName
  AddToResTypeHookList Process, DllName, ProcName
  DefineHook ProcName, Process

  ArgStr textequ <>
  Cnt = 0
  repeat ArgCount
    Cnt = Cnt + 1
    ArgStr CatStr ArgStr, <, >, <Arg>, %Cnt, <:XWORD>
  endm

  Detour_&ProcName& proc uses xbx xdi xsi ArgStr
    local xCallResult:XWORD, hThread:HANDLE
    local Context:CONTEXT, Stack:STACK

    InvokeOriginalCall ProcName, ArgCount

    .if dResGuardEnabled != FALSE
      mov xCallResult, xax

      .if xCallResult != FALSE
        ; ---- Register hProcess ----
        AnalyseStack ProcName                           ; xbx -> CallData object
        mov xax, Arg&ProcInfoArgIndex&                  ; -> PROCESS_INFORMATION
        .if xax != NULL
          m2m [xbx].$Obj(CallData).xData1, [xax].PROCESS_INFORMATION.hProcess, xcx
;          mov [xbx].$Obj(CallData).xData2, 0
          mov xcx, pRTCC_Process
          mov [xbx].$Obj(CallData).pOwner, xcx
          OCall xcx::RTC_Collection.Insert, xbx

          ; ---- Register hThread (clone CallData) ----
          mov xsi, $MemAlloc(sizeof $Obj(CallData))
          s2s $Obj(CallData) ptr [xsi], $Obj(CallData) ptr [xbx], \
              xmm0, xmm1, xmm2, xmm3, xmm4, xmm5, xmm6, xmm7, xax, xcx
          mov xax, Arg&ProcInfoArgIndex&
          m2m [xsi].$Obj(CallData).xData1, [xax].PROCESS_INFORMATION.hThread, xcx
          mov [xsi].$Obj(CallData).xData2, 0
          mov xcx, pRTCC_Thread
          mov [xsi].$Obj(CallData).pOwner, xcx
          OCall xcx::RTC_Collection.Insert, xsi
        .else
          Destroy xbx
        .endif
      .else
        ; ---- Failed call ----
        AnalyseStack ProcName                           ; xbx -> CallData object
        mov [xbx].$Obj(CallData).xData1, 0
;        mov [xbx].$Obj(CallData).xData2, 0
        lea xax, FailErrColl
        mov [xbx].$Obj(CallData).pOwner, xax
        OCall xax::RTC_Collection.Insert, xbx
      .endif

      mov xax, xCallResult
    .endif
    ret
  Detour_&ProcName& endp
endm

DetourAcquireCreateProcess Kernel32.dll, CreateProcessA,           10, 10
DetourAcquireCreateProcess Kernel32.dll, CreateProcessW,           10, 10
DetourAcquireCreateProcess Kernel32.dll, CreateProcessAsUserA,     11, 11
DetourAcquireCreateProcess Kernel32.dll, CreateProcessAsUserW,     11, 11
DetourAcquireCreateProcess Advapi32.dll, CreateProcessWithLogonW,  11, 11   ;; UNICODE only
DetourAcquireCreateProcess Advapi32.dll, CreateProcessWithTokenW,   9,  9
DetourAcquire              Kernel32.dll, OpenProcess, 3, 0, <xCallResult !!= NULL>, Process

; --------------------------------------------------------------------------------------------------

DetourAcquire Kernel32.dll, CreateThread, 6, 0, <xCallResult !!= NULL>, Thread
DetourAcquire Kernel32.dll, CreateRemoteThread, 7, 0, <xCallResult !!= NULL>, Thread
DetourAcquire Kernel32.dll, OpenThread, 3, 0, <xCallResult !!= NULL>, Thread
DetourAcquire Kernel32.dll, CreateRemoteThreadEx, 8, 0, <xCallResult !!= NULL>, Thread

; --------------------------------------------------------------------------------------------------

DetourAcquire Kernel32.dll, CreateSemaphoreA, 4, 0, <xCallResult !!= NULL>, Semaphore
DetourAcquire Kernel32.dll, CreateSemaphoreW, 4, 0, <xCallResult !!= NULL>, Semaphore
DetourAcquire Kernel32.dll, CreateSemaphoreExA, 6, 0, <xCallResult !!= NULL>, Semaphore
DetourAcquire Kernel32.dll, CreateSemaphoreExW, 6, 0, <xCallResult !!= NULL>, Semaphore
DetourAcquire Kernel32.dll, OpenSemaphoreA, 3, 0, <xCallResult !!= NULL>, Semaphore
DetourAcquire Kernel32.dll, OpenSemaphoreW, 3, 0, <xCallResult !!= NULL>, Semaphore

; --------------------------------------------------------------------------------------------------

DetourAcquire Kernel32.dll, DuplicateHandle, 7, -4, <xCallResult !!= 0>, HandleDuplicate

; --------------------------------------------------------------------------------------------------

DetourAcquire Advapi32.dll, OpenProcessToken, 3, -3, <xCallResult !!= FALSE>, Token
DetourAcquire Advapi32.dll, OpenThreadToken, 4, -4, <xCallResult !!= FALSE>, Token
DetourAcquire Advapi32.dll, DuplicateTokenEx, 6, -6, <xCallResult !!= FALSE>, Token
DetourAcquire Advapi32.dll, LogonUserA, 6, -6, <xCallResult !!= FALSE>, Token
DetourAcquire Advapi32.dll, LogonUserW, 6, -6, <xCallResult !!= FALSE>, Token
DetourAcquire Advapi32.dll, DuplicateToken, 3, -3, <xCallResult !!= FALSE>, Token
DetourAcquire Advapi32.dll, CreateRestrictedToken, 9, -9, <xCallResult !!= FALSE>, Token
DetourAcquire Advapi32.dll, LogonUserExA, 10, -6, <xCallResult !!= FALSE>, Token
DetourAcquire Advapi32.dll, LogonUserExW, 10, -6, <xCallResult !!= FALSE>, Token

; --------------------------------------------------------------------------------------------------

DetourAcquireNamed Kernel32.dll, GlobalAddAtomA, 1, 0, <xCallResult !!= 0>, Atom
DetourAcquireNamed Kernel32.dll, GlobalAddAtomW, 1, 0, <xCallResult !!= 0>, Atom

CreateProcNameStringA GlobalDeleteAtom
AddToResTypeHookList Atom, Kernel32.dll, GlobalDeleteAtom
DefineHook GlobalDeleteAtom, Atom

Detour_GlobalDeleteAtom proc uses xbx xdi Arg1:XWORD
  local xCallResult:XWORD, hThread:HANDLE
  local Context:CONTEXT, Stack:STACK

  ANNOTATION use:Context Stack hThread xdi

  invoke SetLastError, ERROR_SUCCESS                    ;; Prime per MSDN: must precede the call
  InvokeOriginalCall GlobalDeleteAtom, 1

  .if dResGuardEnabled != FALSE
    mov xCallResult, xax

    invoke GetLastError
    .if eax == ERROR_SUCCESS
      OCall pRTCC_Atom::RTC_Collection.Remove, Arg1, 0
      test eax, eax
      jnz @@Exit                                        ;; Exit if removed
      AnalyseStack GlobalDeleteAtom                     ;; xbx -> CallData object
      m2m [xbx].$Obj(CallData).xData1, Arg1, xdx
;      mov [xbx].$Obj(CallData).xData2, 0
      lea xax, LogiErrColl
      mov [xbx].$Obj(CallData).pOwner, xax
      OCall xax::RTC_Collection.Insert, xbx
    .else
      AnalyseStack GlobalDeleteAtom                     ;; xbx -> CallData object
      m2m [xbx].$Obj(CallData).xData1, Arg1, xdx
;      mov [xbx].$Obj(CallData).xData2, 0
      lea xax, FailErrColl
      mov [xbx].$Obj(CallData).pOwner, xax
      OCall xax::RTC_Collection.Insert, xbx
    .endif

@@Exit:
    mov xax, xCallResult
  .endif
  ret
Detour_GlobalDeleteAtom endp

; --------------------------------------------------------------------------------------------------

DetourAcquireNamed Kernel32.dll, AddAtomA, 1, 0, <xCallResult !!= 0>, LocalAtom
DetourAcquireNamed Kernel32.dll, AddAtomW, 1, 0, <xCallResult !!= 0>, LocalAtom
DetourRelease Kernel32.dll, DeleteAtom, 1, 1, <xCallResult == 0>, LocalAtom

; --------------------------------------------------------------------------------------------------

DetourAcquireNamed Kernel32.dll, CreateWaitableTimerA, 3, 0, <xCallResult !!= NULL>, WaitableTimer
DetourAcquireNamed Kernel32.dll, CreateWaitableTimerW, 3, 0, <xCallResult !!= NULL>, WaitableTimer
DetourAcquireNamed Kernel32.dll, CreateWaitableTimerExA, 4, 0, <xCallResult !!= NULL>, WaitableTimer
DetourAcquireNamed Kernel32.dll, CreateWaitableTimerExW, 4, 0, <xCallResult !!= NULL>, WaitableTimer
DetourAcquire Kernel32.dll, OpenWaitableTimerA, 3, 0, <xCallResult !!= NULL>, WaitableTimer
DetourAcquire Kernel32.dll, OpenWaitableTimerW, 3, 0, <xCallResult !!= NULL>, WaitableTimer

; --------------------------------------------------------------------------------------------------

CreateProcNameStringA SetTimer
AddToResTypeHookList Timer, User32.dll, SetTimer
DefineHook SetTimer, Timer

Detour_SetTimer proc uses xbx xdi Arg1:XWORD, Arg2:XWORD, Arg3:XWORD, Arg4:XWORD
  local xCallResult:XWORD, hThread:HANDLE
  local Context:CONTEXT, Stack:STACK

  ANNOTATION use:Arg3 Arg4 Context Stack hThread xdi

  InvokeOriginalCall SetTimer, 4

  .if dResGuardEnabled != FALSE
    mov xCallResult, xax

    AnalyseStack SetTimer                               ; xbx -> CallData object

    .if xCallResult != 0
      ; Check if we replace a Window Timer
      OCall pRTCC_Timer::RTC_Collection.Remove, Arg1, Arg2

      m2m [xbx].$Obj(CallData).xData1, Arg1, xax        ; Store hWnd
      .if xax != 0                                      ; hWnd != 0
        mov xcx, Arg2                                   ; uIDEvent
      .else
        mov xcx, xCallResult                            ; New Timer ID
      .endif
      m2m [xbx].$Obj(CallData).xData2, xcx              ; uIDEvent

      mov xax, pRTCC_Timer
      mov [xbx].$Obj(CallData).pOwner, xax
      OCall xax::RTC_Collection.Insert, xbx

    .else
      lea xax, FailErrColl
      mov [xbx].$Obj(CallData).pOwner, xax
      OCall xax::RTC_Collection.Insert, xbx
    .endif

    mov xax, xCallResult                                ; Restore call return value
  .endif
  ret
Detour_SetTimer endp

CreateProcNameStringA KillTimer
AddToResTypeHookList Timer, User32.dll, KillTimer
DefineHook KillTimer, Timer

Detour_KillTimer proc uses xbx xdi Arg1:XWORD, Arg2:XWORD
  local xCallResult:XWORD, hThread:HANDLE
  local Context:CONTEXT, Stack:STACK

  ANNOTATION use:Context Stack hThread xdi

  InvokeOriginalCall KillTimer, 2

  .if dResGuardEnabled != FALSE
    mov xCallResult, xax

    .if xax != 0
      OCall pRTCC_Timer::RTC_Collection.Remove, Arg1, Arg2
      test eax, eax
      jnz @@Exit                                        ; Exit if removed
      invoke DbgOutText, $OfsCStr("Detour_KillTimer failed removing call data"),
                         DbgColorError, DbgColorBackground, \
                         DBG_EFFECT_NORMAL or DBG_EFFECT_NEWLINE, offset wWndCaption
    .else
      AnalyseStack KillTimer                            ; xbx -> CallData object

      m2m [xbx].$Obj(CallData).xData1, Arg1, xdx        ; Store hWnd
      m2m [xbx].$Obj(CallData).xData2, Arg2, xdx        ; uIDEvent

      lea xax, FailErrColl
      mov [xbx].$Obj(CallData).pOwner, xax
      OCall xax::RTC_Collection.Insert, xbx
    .endif
@@Exit:
    mov xax, xCallResult                                ; Restore call return value
  .endif
  ret
Detour_KillTimer endp

; --------------------------------------------------------------------------------------------------

DetourAcquire Kernel32.dll, CreateTimerQueue, 0, 0, <xCallResult !!= NULL>, TimerQueue
DetourRelease Kernel32.dll, DeleteTimerQueueEx, 2, 1, <xCallResult !!= FALSE>, TimerQueue

; --------------------------------------------------------------------------------------------------

DetourAcquire Kernel32.dll, CreateTimerQueueTimer, 7, -1, <xCallResult !!= FALSE>, TimerQueueTimer
DetourRelease Kernel32.dll, DeleteTimerQueueTimer, 3, 2, <xCallResult !!= FALSE>, TimerQueueTimer

; --------------------------------------------------------------------------------------------------

DetourAcquire User32.dll, GetDC, 1, 0, <xCallResult !!= NULL>, DisplayDeviceContext
DetourAcquire User32.dll, GetDCEx, 3, 0, <xCallResult !!= NULL>, DisplayDeviceContext
DetourAcquire User32.dll, GetWindowDC, 1, 0, <xCallResult !!= NULL>, DisplayDeviceContext
DetourRelease User32.dll, ReleaseDC, 2, 2, <xCallResult !!= FALSE>, DisplayDeviceContext

; --------------------------------------------------------------------------------------------------

DetourAcquire GdiPlus.dll, GdipGetDC, 2, -2, <xCallResult !!= 0>, GdipDisplayDeviceContext
DetourRelease GdiPlus.dll, GdipReleaseDC, 2, 2, <xCallResult !!= 0>, GdipDisplayDeviceContext

; --------------------------------------------------------------------------------------------------

DetourAcquire Kernel32.dll, MapViewOfFile, 5, 0, <xCallResult !!= NULL>, MappedView
DetourAcquire Kernel32.dll, MapViewOfFileEx, 6, 0, <xCallResult !!= NULL>, MappedView
DetourAcquire Kernel32.dll, MapViewOfFile2, 7, 0, <xCallResult !!= NULL>, MappedView
DetourRelease Kernel32.dll, UnmapViewOfFile, 1, 1, <xCallResult !!= FALSE>, MappedView
DetourAcquire Kernel32.dll, MapViewOfFileExNuma, 7, 0, <xCallResult !!= NULL>, MappedView
DetourAcquire Kernel32.dll, MapViewOfFileFromApp, 4, 0, <xCallResult !!= NULL>, MappedView

; --------------------------------------------------------------------------------------------------

DetourAcquire Kernel32.dll, CreateActCtxA, 1, 0, <xCallResult !!= INVALID_HANDLE_VALUE>, ActCtx
DetourAcquire Kernel32.dll, CreateActCtxW, 1, 0, <xCallResult !!= INVALID_HANDLE_VALUE>, ActCtx
DetourRelease Kernel32.dll, ReleaseActCtx, 1, 1, <>, ActCtx

; --------------------------------------------------------------------------------------------------

DetourAcquire User32.dll, LoadKeyboardLayoutA, 2, 0, <xCallResult !!= NULL>, KeyboardLayout
DetourAcquire User32.dll, LoadKeyboardLayoutW, 2, 0, <xCallResult !!= NULL>, KeyboardLayout
DetourRelease User32.dll, UnloadKeyboardLayout, 1, 1, <xCallResult !!= FALSE>, KeyboardLayout

; --------------------------------------------------------------------------------------------------

DetourAcquire Kernel32.dll, LoadLibraryA, 1, 0, <xCallResult !!= NULL>, Library
DetourAcquire Kernel32.dll, LoadLibraryW, 1, 0, <xCallResult !!= NULL>, Library
DetourAcquire Kernel32.dll, LoadLibraryExA, 3, 0, <xCallResult !!= NULL>, Library
DetourAcquire Kernel32.dll, LoadLibraryExW, 3, 0, <xCallResult !!= NULL>, Library
DetourAcquire Kernel32.dll, GetModuleHandleExA, 3, -3, <xCallResult !!= FALSE>, Library,, <Arg1 & GET_MODULE_HANDLE_EX_FLAG_UNCHANGED_REFCOUNT>
DetourAcquire Kernel32.dll, GetModuleHandleExW, 3, -3, <xCallResult !!= FALSE>, Library,, <Arg1 & GET_MODULE_HANDLE_EX_FLAG_UNCHANGED_REFCOUNT>
DetourRelease Kernel32.dll, FreeLibrary, 1, 1, <xCallResult !!= FALSE>, Library

; --------------------------------------------------------------------------------------------------

DetourAcquire Winspool.drv, OpenPrinterA, 3, -2, <xCallResult !!= 0>, Printer
DetourAcquire Winspool.drv, OpenPrinterW, 3, -2, <xCallResult !!= 0>, Printer
DetourAcquire Winspool.drv, OpenPrinter2A, 4, -2, <xCallResult !!= 0>, Printer
DetourAcquire Winspool.drv, OpenPrinter2W, 4, -2, <xCallResult !!= 0>, Printer
DetourAcquire Winspool.drv, AddPrinterA, 3, 0, <xCallResult !!= NULL>, Printer
DetourAcquire Winspool.drv, AddPrinterW, 3, 0, <xCallResult !!= NULL>, Printer
DetourRelease Winspool.drv, ClosePrinter, 1, 1, <xCallResult !!= FALSE>, Printer

; --------------------------------------------------------------------------------------------------

DetourAcquire Advapi32.dll, RegCreateKeyA, 3, -3, <xCallResult == ERROR_SUCCESS>, RegKey
DetourAcquire Advapi32.dll, RegCreateKeyW, 3, -3, <xCallResult == ERROR_SUCCESS>, RegKey
DetourAcquire Advapi32.dll, RegCreateKeyExA, 9, -8, <xCallResult == ERROR_SUCCESS>, RegKey
DetourAcquire Advapi32.dll, RegCreateKeyExW, 9, -8, <xCallResult == ERROR_SUCCESS>, RegKey
DetourAcquire Advapi32.dll, RegOpenKeyA, 3, -3, <xCallResult == ERROR_SUCCESS>, RegKey
DetourAcquire Advapi32.dll, RegOpenKeyW, 3, -3, <xCallResult == ERROR_SUCCESS>, RegKey
DetourAcquire Advapi32.dll, RegOpenKeyExA, 5, -5, <xCallResult == ERROR_SUCCESS>, RegKey
DetourAcquire Advapi32.dll, RegOpenKeyExW, 5, -5, <xCallResult == ERROR_SUCCESS>, RegKey
DetourAcquire Advapi32.dll, RegOpenKeyTransactedA, 7, -5, <xCallResult == ERROR_SUCCESS>, RegKey
DetourAcquire Advapi32.dll, RegOpenKeyTransactedW, 7, -5, <xCallResult == ERROR_SUCCESS>, RegKey
DetourAcquire Advapi32.dll, RegCreateKeyTransactedA, 11, -8, <xCallResult == ERROR_SUCCESS>, RegKey
DetourAcquire Advapi32.dll, RegCreateKeyTransactedW, 11, -8, <xCallResult == ERROR_SUCCESS>, RegKey
DetourAcquire Advapi32.dll, RegConnectRegistryA, 3, -3, <xCallResult == ERROR_SUCCESS>, RegKey
DetourAcquire Advapi32.dll, RegConnectRegistryW, 3, -3, <xCallResult == ERROR_SUCCESS>, RegKey
DetourAcquire Advapi32.dll, RegOpenCurrentUser, 2, -2, <xCallResult == ERROR_SUCCESS>, RegKey
DetourAcquire Advapi32.dll, RegOpenUserClassesRoot, 4, -4, <xCallResult == ERROR_SUCCESS>, RegKey
DetourAcquire Setupapi.dll, SetupDiOpenDevRegKey, 6, 0, <xCallResult !!= INVALID_HANDLE_VALUE>, RegKey
DetourAcquire Setupapi.dll, SetupDiCreateDevRegKeyA, 7, 0, <xCallResult !!= INVALID_HANDLE_VALUE>, RegKey
DetourAcquire Setupapi.dll, SetupDiCreateDevRegKeyW, 7, 0, <xCallResult !!= INVALID_HANDLE_VALUE>, RegKey
DetourRelease Advapi32.dll, RegCloseKey, 1, 1, <xCallResult == ERROR_SUCCESS>, RegKey

; --------------------------------------------------------------------------------------------------

DetourAcquire Kernel32.dll, BeginUpdateResourceA, 2, 0, <xCallResult !!= NULL>, UpdateResource
DetourAcquire Kernel32.dll, BeginUpdateResourceW, 2, 0, <xCallResult !!= NULL>, UpdateResource
DetourRelease Kernel32.dll, EndUpdateResourceA, 2, 1, <xCallResult !!= FALSE>, UpdateResource
DetourRelease Kernel32.dll, EndUpdateResourceW, 2, 1, <xCallResult !!= FALSE>, UpdateResource

; --------------------------------------------------------------------------------------------------

DetourAcquire Kernel32.dll, CreateMailslotA, 4, 0, <xCallResult !!= INVALID_HANDLE_VALUE>, Mailslot
DetourAcquire Kernel32.dll, CreateMailslotW, 4, 0, <xCallResult !!= INVALID_HANDLE_VALUE>, Mailslot

; --------------------------------------------------------------------------------------------------

DetourAcquire Kernel32.dll, FindFirstFileA, 2, 0, <xCallResult !!= INVALID_HANDLE_VALUE>, FindFirstFile
DetourAcquire Kernel32.dll, FindFirstFileW, 2, 0, <xCallResult !!= INVALID_HANDLE_VALUE>, FindFirstFile
DetourAcquire Kernel32.dll, FindFirstFileExA, 6, 0, <xCallResult !!= INVALID_HANDLE_VALUE>, FindFirstFile
DetourAcquire Kernel32.dll, FindFirstFileExW, 6, 0, <xCallResult !!= INVALID_HANDLE_VALUE>, FindFirstFile
DetourAcquire Kernel32.dll, FindFirstFileNameW, 4, 0, <xCallResult !!= INVALID_HANDLE_VALUE>, FindFirstFile   ;; UNICODE only
DetourAcquire Kernel32.dll, FindFirstFileTransactedA, 7, 0, <xCallResult !!= INVALID_HANDLE_VALUE>, FindFirstFile
DetourAcquire Kernel32.dll, FindFirstFileTransactedW, 7, 0, <xCallResult !!= INVALID_HANDLE_VALUE>, FindFirstFile
DetourRelease Kernel32.dll, FindClose, 1, 1, <xCallResult !!= FALSE>, FindFirstFile

; --------------------------------------------------------------------------------------------------

DetourAcquire Kernel32.dll, FindFirstChangeNotificationA, 3, 0, <xCallResult !!= INVALID_HANDLE_VALUE>, FindFirstChangeNotif
DetourAcquire Kernel32.dll, FindFirstChangeNotificationW, 3, 0, <xCallResult !!= INVALID_HANDLE_VALUE>, FindFirstChangeNotif
DetourRelease Kernel32.dll, FindCloseChangeNotification, 1, 1, <xCallResult !!= FALSE>, FindFirstChangeNotif

; --------------------------------------------------------------------------------------------------

DetourAcquire Advapi32.dll, OpenEventLogA, 2, 0, <xCallResult !!= NULL>, EventLog
DetourAcquire Advapi32.dll, OpenEventLogW, 2, 0, <xCallResult !!= NULL>, EventLog
DetourAcquire Advapi32.dll, OpenBackupEventLogA, 2, 0, <xCallResult !!= NULL>, EventLog
DetourAcquire Advapi32.dll, OpenBackupEventLogW, 2, 0, <xCallResult !!= NULL>, EventLog
DetourRelease Advapi32.dll, CloseEventLog, 1, 1, <xCallResult !!= FALSE>, EventLog
DetourAcquire Advapi32.dll, RegisterEventSourceA, 2, 0, <xCallResult !!= NULL>, EventLog
DetourAcquire Advapi32.dll, RegisterEventSourceW, 2, 0, <xCallResult !!= NULL>, EventLog
DetourRelease Advapi32.dll, DeregisterEventSource, 1, 1, <xCallResult !!= FALSE>, EventLog

; --------------------------------------------------------------------------------------------------

DetourAcquire Kernel32.dll, InitializeCriticalSection, 1, 1, <>, CriticalSection
DetourAcquire Kernel32.dll, InitializeCriticalSectionAndSpinCount, 2, 1, <>, CriticalSection
DetourAcquire Kernel32.dll, InitializeCriticalSectionEx, 3, 1, <xCallResult !!= FALSE>, CriticalSection
DetourRelease Kernel32.dll, DeleteCriticalSection, 1, 1, <>, CriticalSection

; --------------------------------------------------------------------------------------------------
.data
OleInitializeCount  DWORD  0

.code
DetourAcquireCounted Ole32.dll, OleInitialize, 1, OleInitializeCount, <xCallResult == S_OK>, OleInitialization
DetourReleaseCounted Ole32.dll, OleUninitialize, 0, OleInitializeCount, <>, OleInitialization

; --------------------------------------------------------------------------------------------------

DetourAcquire Advapi32.dll, OpenSCManagerA, 3, 0, <xCallResult !!= NULL>, ServiceHandle
DetourAcquire Advapi32.dll, OpenSCManagerW, 3, 0, <xCallResult !!= NULL>, ServiceHandle
DetourAcquire Advapi32.dll, OpenServiceA, 3, 0, <xCallResult !!= NULL>, ServiceHandle
DetourAcquire Advapi32.dll, OpenServiceW, 3, 0, <xCallResult !!= NULL>, ServiceHandle
DetourAcquire Advapi32.dll, CreateServiceA, 13, 0, <xCallResult !!= NULL>, ServiceHandle
DetourAcquire Advapi32.dll, CreateServiceW, 13, 0, <xCallResult !!= NULL>, ServiceHandle
DetourRelease Advapi32.dll, CloseServiceHandle, 1, 1, <xCallResult !!= FALSE>, ServiceHandle

; --------------------------------------------------------------------------------------------------

DetourAcquire Advapi32.dll, CryptAcquireContextA, 5, -1, <xCallResult !!= FALSE>, CryptContext
DetourAcquire Advapi32.dll, CryptAcquireContextW, 5, -1, <xCallResult !!= FALSE>, CryptContext
DetourRelease Advapi32.dll, CryptReleaseContext, 2, 1, <xCallResult !!= FALSE>, CryptContext

; --------------------------------------------------------------------------------------------------

.data
CoInitializeCount  DWORD  0

.code
DetourAcquireCounted Ole32.dll, CoInitialize, 1, CoInitializeCount, <xCallResult == S_OK>, CoInitialization
DetourAcquireCounted Ole32.dll, CoInitializeEx, 2, CoInitializeCount, <xCallResult == S_OK>, CoInitialization
DetourReleaseCounted Ole32.dll, CoUninitialize, 0, CoInitializeCount, <>, CoInitialization

; --------------------------------------------------------------------------------------------------

DetourAcquire GdiPlus.dll, GdipCreateFromHDC, 2, -2, <xCallResult == 0>, GdipGraphics
DetourAcquire GdiPlus.dll, GdipCreateFromHDC2, 3, -3, <xCallResult == 0>, GdipGraphics
DetourAcquire GdiPlus.dll, GdipCreateFromHWND, 2, -2, <xCallResult == 0>, GdipGraphics
DetourAcquire GdiPlus.dll, GdipCreateFromHWNDICM, 2, -2, <xCallResult == 0>, GdipGraphics
DetourAcquire GdiPlus.dll, GdipGetImageGraphicsContext, 2, -2, <xCallResult == 0>, GdipGraphics
DetourRelease GdiPlus.dll, GdipDeleteGraphics, 1, 1, <xCallResult == 0>, GdipGraphics

; --------------------------------------------------------------------------------------------------

DetourAcquire GdiPlus.dll, GdipCreateMetafileFromFile, 2, -2, <xCallResult == 0>, GdipMetafile
DetourAcquire GdiPlus.dll, GdipCreateMetafileFromStream, 2, -2, <xCallResult == 0>, GdipMetafile
DetourAcquire GdiPlus.dll, GdipCreateMetafileFromEmf, 3, -3, <xCallResult == 0>, GdipMetafile
DetourAcquire GdiPlus.dll, GdipCreateMetafileFromWmf, 4, -4, <xCallResult == 0>, GdipMetafile
DetourAcquire GdiPlus.dll, GdipRecordMetafile, 6, -6, <xCallResult == 0>, GdipMetafile

; --------------------------------------------------------------------------------------------------

DetourAcquire GdiPlus.dll, GdipLoadImageFromFile, 2, -2, <xCallResult == 0>, GdipImage
DetourAcquire GdiPlus.dll, GdipLoadImageFromFileICM, 2, -2, <xCallResult == 0>, GdipImage
DetourAcquire GdiPlus.dll, GdipLoadImageFromStream, 2, -2, <xCallResult == 0>, GdipImage
DetourAcquire GdiPlus.dll, GdipLoadImageFromStreamICM, 2, -2, <xCallResult == 0>, GdipImage
DetourAcquire GdiPlus.dll, GdipCreateBitmapFromFile, 2, -2, <xCallResult == 0>, GdipImage
DetourAcquire GdiPlus.dll, GdipCreateBitmapFromFileICM, 2, -2, <xCallResult == 0>, GdipImage
DetourAcquire GdiPlus.dll, GdipCreateBitmapFromStream, 2, -2, <xCallResult == 0>, GdipImage
DetourAcquire GdiPlus.dll, GdipCreateBitmapFromStreamICM, 2, -2, <xCallResult == 0>, GdipImage
DetourAcquire GdiPlus.dll, GdipCreateBitmapFromScan0, 6, -6, <xCallResult == 0>, GdipImage
DetourAcquire GdiPlus.dll, GdipCreateBitmapFromGdiDib, 2, -2, <xCallResult == 0>, GdipImage
DetourAcquire GdiPlus.dll, GdipCreateBitmapFromHBITMAP, 3, -3, <xCallResult == 0>, GdipImage
DetourAcquire GdiPlus.dll, GdipCreateBitmapFromHICON, 2, -2, <xCallResult == 0>, GdipImage
DetourAcquire GdiPlus.dll, GdipCreateBitmapFromResource, 3, -3, <xCallResult == 0>, GdipImage
DetourAcquire GdiPlus.dll, GdipCloneImage, 2, -2, <xCallResult == 0>, GdipImage
DetourAcquire GdiPlus.dll, GdipCreateBitmapFromDirectDrawSurface, 2, -2, <xCallResult == 0>, GdipImage
DetourRelease GdiPlus.dll, GdipDisposeImage, 1, 1, <xCallResult == 0>, GdipImage, GdipMetafile

; --------------------------------------------------------------------------------------------------

DetourAcquire GdiPlus.dll, GdipCreatePen1, 4, -4, <xCallResult == 0>, GdipPen
DetourAcquire GdiPlus.dll, GdipCreatePen2, 4, -4, <xCallResult == 0>, GdipPen
DetourAcquire GdiPlus.dll, GdipClonePen, 2, -2, <xCallResult == 0>, GdipPen
DetourRelease GdiPlus.dll, GdipDeletePen, 1, 1, <xCallResult == 0>, GdipPen

; --------------------------------------------------------------------------------------------------

DetourAcquire GdiPlus.dll, GdipCreateSolidFill, 2, -2, <xCallResult == 0>, GdipBrush
DetourAcquire GdiPlus.dll, GdipCreateHatchBrush, 4, -4, <xCallResult == 0>, GdipBrush
DetourAcquire GdiPlus.dll, GdipCreateTexture, 4, -4, <xCallResult == 0>, GdipBrush
DetourAcquire GdiPlus.dll, GdipCreateTexture2, 6, -6, <xCallResult == 0>, GdipBrush
DetourAcquire GdiPlus.dll, GdipCreateTextureIA, 6, -6, <xCallResult == 0>, GdipBrush
DetourAcquire GdiPlus.dll, GdipCreateLineBrush, 5, -5, <xCallResult == 0>, GdipBrush
DetourAcquire GdiPlus.dll, GdipCreateLineBrushFromRect, 6, -6, <xCallResult == 0>, GdipBrush
DetourAcquire GdiPlus.dll, GdipCreatePathGradient, 4, -4, <xCallResult == 0>, GdipBrush
DetourAcquire GdiPlus.dll, GdipCreatePathGradientFromPath, 2, -2, <xCallResult == 0>, GdipBrush
DetourAcquire GdiPlus.dll, GdipCloneBrush, 2, -2, <xCallResult == 0>, GdipBrush
DetourRelease GdiPlus.dll, GdipDeleteBrush, 1, 1, <xCallResult == 0>, GdipBrush

; --------------------------------------------------------------------------------------------------

DetourAcquire GdiPlus.dll, GdipCreateFont, 4, -4, <xCallResult == 0>, GdipFont
DetourAcquire GdiPlus.dll, GdipCreateFontFromDC, 2, -2, <xCallResult == 0>, GdipFont
DetourAcquire GdiPlus.dll, GdipCreateFontFromLogfontA, 3, -3, <xCallResult == 0>, GdipFont
DetourAcquire GdiPlus.dll, GdipCreateFontFromLogfontW, 3, -3, <xCallResult == 0>, GdipFont
DetourRelease GdiPlus.dll, GdipDeleteFont, 1, 1, <xCallResult == 0>, GdipFont

; --------------------------------------------------------------------------------------------------

DetourAcquire GdiPlus.dll, GdipCreateFontFamilyFromName, 3, -3, <xCallResult == 0>, GdipFontFamily
DetourAcquire GdiPlus.dll, GdipCloneFontFamily, 2, -2, <xCallResult == 0>, GdipFontFamily
DetourRelease GdiPlus.dll, GdipDeleteFontFamily, 1, 1, <xCallResult == 0>, GdipFontFamily

; --------------------------------------------------------------------------------------------------

DetourAcquire GdiPlus.dll, GdipNewPrivateFontCollection, 1, -1, <xCallResult == 0>, GdipFontCollection
DetourRelease GdiPlus.dll, GdipDeletePrivateFontCollection, 1, 1, <xCallResult == 0>, GdipFontCollection

; --------------------------------------------------------------------------------------------------

DetourAcquire GdiPlus.dll, GdipCreateStringFormat, 2, -2, <xCallResult == 0>, GdipStringFormat
DetourAcquire GdiPlus.dll, GdipStringFormatGetGenericDefault, 1, -1, <xCallResult == 0>, GdipStringFormat
DetourAcquire GdiPlus.dll, GdipStringFormatGetGenericTypographic, 1, -1, <xCallResult == 0>, GdipStringFormat
DetourAcquire GdiPlus.dll, GdipCloneStringFormat, 2, -2, <xCallResult == 0>, GdipStringFormat
DetourRelease GdiPlus.dll, GdipDeleteStringFormat, 1, 1, <xCallResult == 0>, GdipStringFormat

; --------------------------------------------------------------------------------------------------

DetourAcquire GdiPlus.dll, GdipCreatePath, 2, -2, <xCallResult == 0>, GdipPath
DetourAcquire GdiPlus.dll, GdipCreatePath2, 4, -4, <xCallResult == 0>, GdipPath
DetourAcquire GdiPlus.dll, GdipClonePath, 2, -2, <xCallResult == 0>, GdipPath
DetourRelease GdiPlus.dll, GdipDeletePath, 1, 1, <xCallResult == 0>, GdipPath

; --------------------------------------------------------------------------------------------------

DetourAcquire GdiPlus.dll, GdipCreateRegion, 1, -1, <xCallResult == 0>, GdipRegion
DetourAcquire GdiPlus.dll, GdipCreateRegionRect, 2, -2, <xCallResult == 0>, GdipRegion
DetourAcquire GdiPlus.dll, GdipCreateRegionPath, 2, -2, <xCallResult == 0>, GdipRegion
DetourAcquire GdiPlus.dll, GdipCreateRegionRgnData, 3, -3, <xCallResult == 0>, GdipRegion
DetourAcquire GdiPlus.dll, GdipCreateRegionHrgn, 2, -2, <xCallResult == 0>, GdipRegion
DetourAcquire GdiPlus.dll, GdipCloneRegion, 2, -2, <xCallResult == 0>, GdipRegion
DetourRelease GdiPlus.dll, GdipDeleteRegion, 1, 1, <xCallResult == 0>, GdipRegion

; --------------------------------------------------------------------------------------------------

DetourAcquire GdiPlus.dll, GdipCreateMatrix, 1, -1, <xCallResult == 0>, GdipMatrix
DetourAcquire GdiPlus.dll, GdipCreateMatrix2, 7, -7, <xCallResult == 0>, GdipMatrix
DetourAcquire GdiPlus.dll, GdipCreateMatrix3, 3, -3, <xCallResult == 0>, GdipMatrix
DetourAcquire GdiPlus.dll, GdipCloneMatrix, 2, -2, <xCallResult == 0>, GdipMatrix
DetourRelease GdiPlus.dll, GdipDeleteMatrix, 1, 1, <xCallResult == 0>, GdipMatrix

; --------------------------------------------------------------------------------------------------

DetourAcquire GdiPlus.dll, GdipCreateCachedBitmap, 3, -3, <xCallResult == 0>, GdipCachedBitmap
DetourRelease GdiPlus.dll, GdipDeleteCachedBitmap, 1, 1, <xCallResult == 0>, GdipCachedBitmap

; --------------------------------------------------------------------------------------------------

DetourAcquire GdiPlus.dll, GdipCreateImageAttributes, 1, -1, <xCallResult == 0>, GdipImageAttributes
DetourAcquire GdiPlus.dll, GdipCloneImageAttributes, 2, -2, <xCallResult == 0>, GdipImageAttributes
DetourRelease GdiPlus.dll, GdipDisposeImageAttributes, 1, 1, <xCallResult == 0>, GdipImageAttributes

; --------------------------------------------------------------------------------------------------

DetourAcquire GdiPlus.dll, GdipCreateAdjustableArrowCap, 4, -4, <xCallResult == 0>, GdipCustomLineCap
DetourAcquire GdiPlus.dll, GdipCreateCustomLineCap, 5, -5, <xCallResult == 0>, GdipCustomLineCap
DetourAcquire GdiPlus.dll, GdipCloneCustomLineCap, 2, -2, <xCallResult == 0>, GdipCustomLineCap
DetourRelease GdiPlus.dll, GdipDeleteCustomLineCap, 1, 1, <xCallResult == 0>, GdipCustomLineCap

; --------------------------------------------------------------------------------------------------

.data
GdiplusInitializeCount  DWORD  0

.code
DetourAcquireCounted GdiPlus.dll, GdiplusStartup, 3, GdiplusInitializeCount, <xCallResult == 0>, GdipInitialization
DetourReleaseCounted GdiPlus.dll, GdiplusShutdown, 1, GdiplusInitializeCount, <>, GdipInitialization

; --------------------------------------------------------------------------------------------------

DetourAcquire Kernel32.dll, FindFirstVolumeA, 2, 0, <xCallResult !!= INVALID_HANDLE_VALUE>, FindFirstVol
DetourAcquire Kernel32.dll, FindFirstVolumeW, 2, 0, <xCallResult !!= INVALID_HANDLE_VALUE>, FindFirstVol
DetourRelease Kernel32.dll, FindVolumeClose, 1, 1, <xCallResult !!= FALSE>, FindFirstVol

; --------------------------------------------------------------------------------------------------

DetourAcquire Ws2_32.dll, socket, 3, 0, <xCallResult !!= INVALID_SOCKET>, Socket
DetourAcquire Ws2_32.dll, WSASocketA, 6, 0, <xCallResult !!= INVALID_SOCKET>, Socket
DetourAcquire Ws2_32.dll, WSASocketW, 6, 0, <xCallResult !!= INVALID_SOCKET>, Socket
DetourAcquire Ws2_32.dll, accept, 3, 0, <xCallResult !!= INVALID_SOCKET>, Socket
DetourAcquire Ws2_32.dll, WSAAccept, 5, 0, <xCallResult !!= INVALID_SOCKET>, Socket
DetourRelease Ws2_32.dll, closesocket, 1, 1, <xCallResult == 0>, Socket

; --------------------------------------------------------------------------------------------------

DetourAcquire Wininet.dll, InternetOpenA,       5, 0, <xCallResult !!= NULL>, WinINet
DetourAcquire Wininet.dll, InternetOpenW,       5, 0, <xCallResult !!= NULL>, WinINet
DetourAcquire Wininet.dll, InternetConnectA,    8, 0, <xCallResult !!= NULL>, WinINet
DetourAcquire Wininet.dll, InternetConnectW,    8, 0, <xCallResult !!= NULL>, WinINet
DetourRelease Wininet.dll, InternetCloseHandle, 1, 1, <xCallResult !!= FALSE>, WinINet

; --------------------------------------------------------------------------------------------------

DetourAcquire Winhttp.dll, WinHttpOpen, 5, 0, <xCallResult !!= NULL>, WinHttp
DetourAcquire Winhttp.dll, WinHttpConnect, 4, 0, <xCallResult !!= NULL>, WinHttp
DetourAcquire Winhttp.dll, WinHttpOpenRequest, 7, 0, <xCallResult !!= NULL>, WinHttp
DetourRelease Winhttp.dll, WinHttpCloseHandle, 1, 1, <xCallResult !!= FALSE>, WinHttp

; --------------------------------------------------------------------------------------------------

DetourAcquire Bcrypt.dll, BCryptOpenAlgorithmProvider, 4, -1, <xCallResult == 0>, BCryptAlgorithm
DetourRelease Bcrypt.dll, BCryptCloseAlgorithmProvider, 2, 1, <xCallResult == 0>, BCryptAlgorithm
DetourAcquire Bcrypt.dll, BCryptCreateHash, 7, -2, <xCallResult == 0>, BCryptHash
DetourRelease Bcrypt.dll, BCryptDestroyHash, 1,  1, <xCallResult == 0>, BCryptHash
DetourAcquire Bcrypt.dll, BCryptGenerateSymmetricKey, 7, -2, <xCallResult == 0>, BCryptKey
DetourAcquire Bcrypt.dll, BCryptImportKey, 9, -4, <xCallResult == 0>, BCryptKey
DetourAcquire Bcrypt.dll, BCryptImportKeyPair, 7, -4, <xCallResult == 0>, BCryptKey
DetourRelease Bcrypt.dll, BCryptDestroyKey, 1,  1, <xCallResult == 0>, BCryptKey

; --------------------------------------------------------------------------------------------------

DetourAcquire Kernel32.dll, CreateThreadpool, 1, 0, <xCallResult !!= NULL>, ThreadPool
DetourRelease Kernel32.dll, CloseThreadpool, 1, 1, <>, ThreadPool
DetourAcquire Kernel32.dll, CreateThreadpoolWork, 3, 0, <xCallResult !!= NULL>, ThreadPoolWork
DetourRelease Kernel32.dll, CloseThreadpoolWork, 1, 1, <>, ThreadPoolWork
DetourAcquire Kernel32.dll, CreateThreadpoolTimer, 3, 0, <xCallResult !!= NULL>, ThreadPoolTimer
DetourRelease Kernel32.dll, CloseThreadpoolTimer, 1, 1, <>, ThreadPoolTimer
DetourAcquire Kernel32.dll, CreateThreadpoolIo, 4, 0, <xCallResult !!= NULL>, ThreadPoolIo
DetourRelease Kernel32.dll, CloseThreadpoolIo, 1, 1, <>, ThreadPoolIo
DetourAcquire Kernel32.dll, CreateThreadpoolWait, 3, 0, <xCallResult !!= NULL>, ThreadPoolWait
DetourRelease Kernel32.dll, CloseThreadpoolWait, 1, 1, <>, ThreadPoolWait

; --------------------------------------------------------------------------------------------------

DetourRelease Kernel32.dll, CloseHandle, 1, 1, <xCallResult !!= FALSE>, \
              File, FileMapping, Event, Mutex, Semaphore, Pipe, Thread, Process, WaitableTimer, \
              Job, HandleDuplicate, Token, Transaction, Mailslot, Timer, IoCompletionPort




; ==================================================================================================

CreateHooks macro ResTypeName, CollectionInitialSize
  local ApiDef, ProcName, DllName, SepPos, DotPos

  ResTypeHookCount = ResTypeHookCount + 1

  .data
  pRTCC_&ResTypeName&  $ObjPtr(RTC_Collection)  NULL

  .code
  New RTC_Collection
  mov pRTCC_&ResTypeName&, xax
  OCall RcrcColl::Collection.Insert, xax
  OCall xax::RTC_Collection.Init, offset RcrcColl, CollectionInitialSize, CollectionInitialSize, COL_MAX_CAPACITY

  %for ApiDef, <&ResTypeName&HookList>                  ;; Search in all listed RTC_Collections
    New IAT_Hook
    DotPos InStr 1, <ApiDef>, <.>
    SepPos InStr DotPos, <ApiDef>, <_>                  ;; Find the "_" after the first "." (from e.g. .dll)

    mov @CatStr(<pHook>, @SubStr(ApiDef, SepPos)), xax  ;; Save the IAT_Hook in this var
    OCall xax::IAT_Hook.Init, offset HookColl, \
                              $OfsCStrA(@CatStr(<!">, @SubStr(<ApiDef>, 1, SepPos - 1), <!">)), \
                              $OfsCStrA(@CatStr(<!">, @SubStr(<ApiDef>, SepPos + 1), <!">)), \
                              offset @CatStr(<Detour>, @SubStr(<ApiDef>, SepPos)), FALSE
    mov xax, @CatStr(<pHook>, @SubStr(<ApiDef>, SepPos))
    .if [xax].$Obj(IAT_Hook).dErrorCode != OBJ_OK
      Destroy xax
    .else
      OCall HookColl::Collection.Insert, xax            ;; and in a dedicated HookColl collection
    .endif
  endm
endm

; --------------------------------------------------------------------------------------------------
; Procedure: DllDone
; Purpose:   ResGuard finalization and freeing of allocated resources.
;            It restores the original APIs.
; Arguments: None.
; Return:    Nothing.

DllDone proc
  m2z dResGuardEnabled
  OCall HookColl::Collection.Done                       ; Destroy all IAT_Hooks and restore IAT
  OCall RcrcColl::Collection.Done                       ; Destroy all leaked CallData objects in RTC_Collections
  OCall FailErrColl::RTC_Collection.Done                ; Destroy all failed CallData objects
  OCall LogiErrColl::RTC_Collection.Done                ; Destroy all failed CallData objects
  ret
DllDone endp

; --------------------------------------------------------------------------------------------------
; Procedure: DllInit
; Purpose:   ResGuard initialization. It hooks the following APIs from the IAT.
; Arguments: None.
; Return:    Nothing.

DllInit proc
  m2z dResGuardEnabled

  mov hProcess, $invoke(GetCurrentProcess())
  invoke SymSetOptions, SYMOPT_UNDNAME or SYMOPT_DEFERRED_LOADS
  invoke SymInitialize, hProcess, NULL, TRUE

  OCall HookColl::Collection.Init, NULL, HookCount, 10, COL_MAX_CAPACITY
  OCall RcrcColl::Collection.Init, NULL, HookCount, 10, COL_MAX_CAPACITY
  OCall FailErrColl::RTC_Collection.Init, NULL, 10, 10, COL_MAX_CAPACITY
  OCall LogiErrColl::RTC_Collection.Init, NULL, 10, 10, COL_MAX_CAPACITY

  CreateHooks Window, 10
  CreateHooks PaintStruct, 10
  CreateHooks Pen, 10
  CreateHooks Brush, 10
  CreateHooks Bitmap, 10
  CreateHooks Image, 10
  CreateHooks Region, 10
  CreateHooks Font, 10
  CreateHooks Palette, 10
  CreateHooks ColorSpace, 10
  CreateHooks Cursor, 10
  CreateHooks Icon, 10
  CreateHooks Menu, 10
  CreateHooks Timer, 10
  CreateHooks WaitableTimer, 10
  CreateHooks TimerQueue, 10
  CreateHooks TimerQueueTimer, 10
  CreateHooks MetaFile, 10
  CreateHooks EnhMetaFile, 10
  CreateHooks ImageList, 10
  CreateHooks DeviceContext, 10
  CreateHooks DisplayDeviceContext, 10
  CreateHooks GdipDisplayDeviceContext, 10
  CreateHooks StockObject, 10      ; It is not necessary (but it is not harmful) to delete stock objects by calling DeleteObject.
  CreateHooks AccTable, 10
  CreateHooks KeyboardLayout, 10
  CreateHooks Desktop, 10
  CreateHooks Library, 10
  CreateHooks WindowStation, 10
  CreateHooks File, 10
  CreateHooks EncryptedFile, 10
  CreateHooks Event, 10
  CreateHooks FileMapping, 10
  CreateHooks Mutex, 10
  CreateHooks Pipe, 10
  CreateHooks Process, 10
  CreateHooks Thread, 10
  CreateHooks Semaphore, 10
  CreateHooks Printer, 10
  CreateHooks RegKey, 10
  CreateHooks UpdateResource, 10
  CreateHooks Mailslot, 10
  CreateHooks FindFirstFile, 10
  CreateHooks FindFirstChangeNotif, 10
  CreateHooks EventLog, 10
  CreateHooks CriticalSection, 10
  CreateHooks OleInitialization, 10
  CreateHooks CoInitialization, 10
  CreateHooks SysString, 10
  CreateHooks CoTaskMemBlock, 100
  CreateHooks VirtualMemBlock, 100
  CreateHooks LocalMemBlock, 100
  CreateHooks GlobalMemBlock, 100
  CreateHooks HeapMemBlock, 100
  CreateHooks PrivateHeap, 100
  CreateHooks PrivateNamespace, 2
  CreateHooks Job, 2
  CreateHooks Transaction, 2
  CreateHooks HandleDuplicate, 2
  CreateHooks ServiceHandle, 2
  CreateHooks Token, 2
  CreateHooks Atom, 2
  CreateHooks LocalAtom, 2
  CreateHooks CryptContext, 2
  CreateHooks GdipGraphics, 8
  CreateHooks GdipImage, 8
  CreateHooks GdipPen, 2
  CreateHooks GdipBrush, 2
  CreateHooks GdipFont, 4
  CreateHooks GdipFontFamily, 2
  CreateHooks GdipFontCollection, 2
  CreateHooks GdipStringFormat, 2
  CreateHooks GdipPath, 2
  CreateHooks GdipRegion, 2
  CreateHooks GdipMatrix, 2
  CreateHooks GdipCachedBitmap, 2
  CreateHooks GdipImageAttributes, 2
  CreateHooks GdipCustomLineCap, 2
  CreateHooks GdipMetafile, 2
  CreateHooks GdipInitialization, 2
  CreateHooks IoCompletionPort, 2
  CreateHooks MappedView, 2
  CreateHooks ActCtx, 2
  CreateHooks Socket, 2
  CreateHooks FindFirstVol, 2
  CreateHooks WinHttp, 2
  CreateHooks WinINet, 2
  CreateHooks BCryptAlgorithm, 2
  CreateHooks BCryptHash, 2
  CreateHooks BCryptKey, 2
  CreateHooks ThreadPool, 2
  CreateHooks ThreadPoolWork, 2
  CreateHooks ThreadPoolTimer, 2
  CreateHooks ThreadPoolIo, 2
  CreateHooks ThreadPoolWait, 2
  ret
DllInit endp

; --------------------------------------------------------------------------------------------------
; Procedure: ResGuardInit (exported)
; Purpose:   Initialize monitoring and remembers where to stop the stack tracing.
; Arguments: None.
; Return:    Nothing.

ResGuardInit proc
  ANNOTATION prv:ebp

  if TARGET_BITNESS eq 32
    mov xAppRefAddr, ebp
  else
    mov xAppRefAddr, rsp
    add xAppRefAddr, 2*sizeof(POINTER)                 ; Discard ret addr and frame
  endif
  ret
ResGuardInit endp

; --------------------------------------------------------------------------------------------------
; Procedure: ResGuardShow (exported)
; Purpose:   Visualisation of resource usage.
; Arguments: Arg1: -> RTC_Collection.
;            Arg2: Resource type caption.
;            xbx -> Output ANSI buffer.
; Return:    Nothing.

ShowCollectionData macro CollectionName:req, ResTypeCaption:req
  local szLeakCaption

  ShowCollDataCount = ShowCollDataCount + 1

  CStr szLeakCaption, ResTypeCaption, ": current = %li, maximum = %li, total = %li"
  mov xdi, @CatStr(<pRTCC_>, <CollectionName>)
  .if ([xdi].$Obj(RTC_Collection).dCount > 0)
    invoke wsprintf, xbx, offset szLeakCaption, [xdi].$Obj(RTC_Collection).dCount, \
                     [xdi].$Obj(RTC_Collection).dMaxCount, [xdi].$Obj(RTC_Collection).dTotCount
    invoke DbgOutText, xbx, DbgColorForeground, DbgColorBackground, \
                       DBG_EFFECT_NORMAL or DBG_EFFECT_NEWLINE, offset wWndCaption
    OCall xdi::RTC_Collection.Aggregate
    OCall xdi::RTC_Collection.ForEach, $MethodAddr(CallData.Show), NULL, NULL
    OCall xdi::RTC_Collection.Deaggregate
  .endif
endm

RTCC_AddLeaks proc pRTC_Collection:$ObjPtr(RTC_Collection), pLeaks:POINTER, xDummy:XWORD
  ANNOTATION use:xDummy

  ?mov xcx, pRTC_Collection
  ?mov xdx, pLeaks
  mov eax, [xcx].$Obj(RTC_Collection).dCount
  add DWORD ptr [xdx], eax
  ret
RTCC_AddLeaks endp

ResGuardShow proc uses xbx xdi
  local cBuffer[256]:CHRA, dLeaks:DWORD, dFails:DWORD, dLogis:DWORD

  lea xbx, cBuffer
  m2z dResGuardEnabled
  m2z dLeaks
  OCall RcrcColl::Collection.ForEach, offset RTCC_AddLeaks, addr dLeaks, NULL

  .if dLeaks != 0
    invoke wsprintf, xbx, $OfsCStr("Detected Leaks: %li"), dLeaks
    invoke DbgOutText, xbx, DbgColorForeground, DbgColorBackground, \
                       DBG_EFFECT_NORMAL or DBG_EFFECT_NEWLINE, offset wWndCaption

    ; -----------------------------------------------------------------------------------
    ; Note: don't show data for StockObject!
    ShowCollectionData VirtualMemBlock,         "Virtual Mem-Blocks"
    ShowCollectionData GlobalMemBlock,          "Global Mem-Blocks"
    ShowCollectionData LocalMemBlock,           "Local Mem-Blocks"
    ShowCollectionData HeapMemBlock,            "Heap Mem-Blocks"
    ShowCollectionData PrivateHeap,             "Private Heap Mem-Blocks"
    ShowCollectionData CoTaskMemBlock,          "CoTaskMem-Blocks"
    ShowCollectionData AccTable,                "Accelerator Tables"
    ShowCollectionData Bitmap,                  "Bitmaps"
    ShowCollectionData Brush,                   "Brushes"
    ShowCollectionData ImageList,               "ImageLists"
    ShowCollectionData FindFirstChangeNotif,    "FindFirst Change Notification"
    ShowCollectionData ColorSpace,              "Color Spaces"
    ShowCollectionData CriticalSection,         "Critical Sections"
    ShowCollectionData Cursor,                  "Cursors"
    ShowCollectionData Desktop,                 "Desktops"
    ShowCollectionData DeviceContext,           "Device Contexts"
    ShowCollectionData DisplayDeviceContext,    "Display DCs"
    ShowCollectionData EnhMetaFile,             "EnhMetaFiles"
    ShowCollectionData Event,                   "Events"
    ShowCollectionData EventLog,                "Event Logs"
    ShowCollectionData File,                    "Files"
    ShowCollectionData EncryptedFile,           "Encrypted Files"
    ShowCollectionData FileMapping,             "File Mappings"
    ShowCollectionData UpdateResource,          "File Resources"
    ShowCollectionData FindFirstFile,           "Find First File"
    ShowCollectionData Font,                    "Fonts"
    ShowCollectionData Icon,                    "Icons"
    ShowCollectionData Image,                   "Images"
    ShowCollectionData KeyboardLayout,          "Keyboard Layouts"
    ShowCollectionData Library,                 "Libraries"
    ShowCollectionData Mailslot,                "Mail Slots"
    ShowCollectionData Menu,                    "Menus"
    ShowCollectionData MetaFile,                "MetaFiles"
    ShowCollectionData Mutex,                   "Mutexes"
    ShowCollectionData Palette,                 "Palettes"
    ShowCollectionData Window,                  "Windows"
    ShowCollectionData PaintStruct,             "Paint Structures"
    ShowCollectionData Pen,                     "Pens"
    ShowCollectionData StockObject,             "Stock Objects"
    ShowCollectionData Printer,                 "Printers"
    ShowCollectionData PrivateNamespace,        "Private Namespaces"
    ShowCollectionData Process,                 "Processes"
    ShowCollectionData Region,                  "Regions"
    ShowCollectionData RegKey,                  "Registry Keys"
    ShowCollectionData Semaphore,               "Semaphores"
    ShowCollectionData SysString,               "System BStrings"
    ShowCollectionData Thread,                  "Threads"
    ShowCollectionData Timer,                   "Timers"
    ShowCollectionData WaitableTimer,           "Waitable Timers"
    ShowCollectionData TimerQueue,              "Timer Queues"
    ShowCollectionData TimerQueueTimer,         "Timer Queue Timers"
    ShowCollectionData Transaction,             "Transactions"
    ShowCollectionData WindowStation,           "Window Stations"
    ShowCollectionData OleInitialization,       "OLE library initialization"
    ShowCollectionData CoInitialization,        "COM library initialization"
    ShowCollectionData ServiceHandle,           "Service Control Manager"
    ShowCollectionData Token,                   "Tokens"
    ShowCollectionData Atom,                    "Atoms"
    ShowCollectionData LocalAtom,               "Local Atoms"
    ShowCollectionData Job,                     "Jobs"
    ShowCollectionData HandleDuplicate,         "Handle duplication"
    ShowCollectionData CryptContext,            "Cryptgraphy"
    ShowCollectionData IoCompletionPort,        "IO Completion Ports"
    ShowCollectionData MappedView,              "Mapped Views"
    ShowCollectionData ActCtx,                  "activation contexts"
    ShowCollectionData FindFirstVol,            "Volumes"
    ShowCollectionData Socket,                  "Sockets"
    ShowCollectionData GdipDisplayDeviceContext,"GDI+ Display DCs"
    ShowCollectionData GdipGraphics,            "GDI+ Graphics"
    ShowCollectionData GdipImage,               "GDI+ Images"
    ShowCollectionData GdipPen,                 "GDI+ Pens"
    ShowCollectionData GdipBrush,               "GDI+ Brushs"
    ShowCollectionData GdipFont,                "GDI+ Fonts"
    ShowCollectionData GdipFontFamily,          "GDI+ FontFamilies"
    ShowCollectionData GdipFontCollection,      "GDI+ FontCollections"
    ShowCollectionData GdipStringFormat,        "GDI+ StringFormats"
    ShowCollectionData GdipPath,                "GDI+ Paths"
    ShowCollectionData GdipRegion,              "GDI+ Regions"
    ShowCollectionData GdipMatrix,              "GDI+ Matrices"
    ShowCollectionData GdipCachedBitmap,        "GDI+ CachedBitmaps"
    ShowCollectionData GdipImageAttributes,     "GDI+ ImageAttributes"
    ShowCollectionData GdipCustomLineCap,       "GDI+ CustomLineCaps"
    ShowCollectionData GdipMetafile,            "GDI+ Metafiles"
    ShowCollectionData GdipInitialization,      "GDI+ Initialization"
    ShowCollectionData Pipe,                    "Pipes"
    ShowCollectionData WinHttp,                 "WinHTTP Handles"
    ShowCollectionData WinINet,                 "WinINet Handles"
    ShowCollectionData BCryptAlgorithm,         "BCrypt Algorithm Providers"
    ShowCollectionData BCryptHash,              "BCrypt Hashes"
    ShowCollectionData BCryptKey,               "BCrypt Keys"
    ShowCollectionData ThreadPool,              "Thread Pools"
    ShowCollectionData ThreadPoolWork,          "ThreadPool Work"
    ShowCollectionData ThreadPoolTimer,         "ThreadPool Timers"
    ShowCollectionData ThreadPoolIo,            "ThreadPool I/O"
    ShowCollectionData ThreadPoolWait,          "ThreadPool Waits"

    ; -----------------------------------------------------------------------------------
  .endif

  lea xdi, FailErrColl
  m2m dFails, [xdi].$Obj(RTC_Collection).dCount, eax
  .if (eax != 0)
    invoke wsprintf, xbx, $OfsCStr("Failed Calls:   %li"), dFails
    invoke DbgOutText, xbx, DbgColorForeground, DbgColorBackground, \
                       DBG_EFFECT_NORMAL or DBG_EFFECT_NEWLINE, offset wWndCaption
    OCall xdi::RTC_Collection.Aggregate
    OCall xdi::RTC_Collection.ForEach, $MethodAddr(CallData.Show), NULL, NULL
    OCall xdi::RTC_Collection.Deaggregate
  .endif

  lea xdi, LogiErrColl
  m2m dLogis, [xdi].$Obj(RTC_Collection).dCount, eax
  .if (eax != 0)
    invoke wsprintf, xbx, $OfsCStr("Logic Errors:   %li"), dLogis
    invoke DbgOutText, xbx, DbgColorForeground, DbgColorBackground, \
                       DBG_EFFECT_NORMAL or DBG_EFFECT_NEWLINE, offset wWndCaption
    OCall xdi::RTC_Collection.Aggregate
    OCall xdi::RTC_Collection.ForEach, $MethodAddr(CallData.Show), NULL, NULL
    OCall xdi::RTC_Collection.Deaggregate
  .endif

  .if (dLeaks != 0 || dFails != 0 || dLogis != 0)
    invoke MessageBoxW, 0, offset wDebugStart, offset wWndCaption, MB_YESNO or MB_ICONEXCLAMATION or MB_TOPMOST
    .if eax == IDYES
      mov dResGuardEnabled, TRUE
      int 3
    .endif
  .else
    invoke DbgOutText, $OfsCStr("No leaks, failures or logic errors detected."), \
                       DbgColorForeground, DbgColorBackground, \
                       DBG_EFFECT_NORMAL or DBG_EFFECT_NEWLINE, offset wWndCaption
  .endif

  ret
ResGuardShow endp

; --------------------------------------------------------------------------------------------------
; Procedure: ResGuardStart (exported)
; Purpose:   Begins resource monitoring.
; Arguments: None.
; Return:    Nothing.

ResGuardStart proc
  mov dResGuardEnabled, TRUE
  ret
ResGuardStart endp

; --------------------------------------------------------------------------------------------------
; Procedure: ResGuardStop (exported)
; Purpose:   End resource monitoring.
; Arguments: None.
; Return:    Nothing.

ResGuardStop proc
  m2z dResGuardEnabled
  ret
ResGuardStop endp

; --------------------------------------------------------------------------------------------------
; Procedure: ResGuardVersion (exported)
; Purpose:   Shows the ResGuard version information.
; Arguments: None.
; Return:    Nothing.

ResGuardVersion proc
  invoke DbgOutText, addr szAboutText, DbgColorForeground, DbgColorBackground, \
                     DBG_EFFECT_NORMAL or DBG_EFFECT_NEWLINE, offset wWndCaption
  ret
ResGuardVersion endp

; --------------------------------------------------------------------------------------------------
; Procedure: start (exported)
; Purpose:   Entry procedure in the DLL (DllMain).
; Arguments: Arg1: Instance handle.
;            Arg2: Call reason.
;            Arg3: Reserved.
; Return:    TRUE if handled.

start proc public hDllInstance:HANDLE, dReason:DWORD, xReserved:XWORD
  ANNOTATION use:xReserved

  mov eax, dReason
  .if eax == DLL_PROCESS_ATTACH
    SysInit hDllInstance
    invoke DllInit
  .elseif eax == DLL_PROCESS_DETACH
    invoke DllDone
    SysDone
  .endif
  xor eax, eax
  inc eax
  ret
start endp




if (ResTypeCollCount ne ResTypeHookCount) or (ResTypeHookCount ne ShowCollDataCount)
  echo -------------------------------
  echo ATTENTION: some code is missing 
  echo -------------------------------
  % echo @CatStr(%ResTypeCollCount,  < ResTypeCall collections defined>)
  % echo @CatStr(%ResTypeHookCount,  < CreateHooks invocations>)
  % echo @CatStr(%ShowCollDataCount, < ShowCollectionData invocations>)
  echo
endif

end
