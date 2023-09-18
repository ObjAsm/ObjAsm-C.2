; ==================================================================================================
; Title:      ResGuard.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    Detection of resource leakages using ObjAsm ResGuardxx.dll.
; Notes:      http://www.microsoft.com/msj/0498/hood0498.aspx
;             Version C.1.0, August 2023
;               - First release.
; Links:      https://www.ired.team/miscellaneous-reversing-forensics/windows-kernel-internals/windows-x64-calling-convention-stack-frame
;             https://learn.microsoft.com/en-us/windows/win32/api/dbghelp/nf-dbghelp-stackwalk
;             https://learn.microsoft.com/en-us/windows/win32/api/dbghelp/nf-dbghelp-stackwalk64
;             https://stackoverflow.com/questions/5705650/stackwalk64-on-windows-get-symbol-name
; ==================================================================================================

;Todo: add GDI+ procs

_IMAGEHLP_SOURCE_ equ 0
SYM_NAME_LENGTH   equ 255
CALLER_MAX_DEEP   equ 10

% include @Environ(OBJASM_PATH)\Code\Macros\Model.inc
SysSetup OOP, DLL32, SUFFIX, WIDE_STRING, DEBUG(WND)

% includelib &LibPath&Windows\DbgHelp.lib

% include &IncPath&Windows\DbgHelp.inc

CStrW wWndCaption, "ResGuard"
CStrW wDebugStart, "Use the debugger to find the lines of", CRLF, \
                   "code that use the listed resources.", CRLF, CRLF,\
                   "Do you want to start the debugger now?", CRLF

HookCount = 0

MakeObjects Primer, Stream, Collection, IAT_Hook

if TARGET_BITNESS eq 32
  STACK textequ <STACKFRAME>

  SYMBOL struct
    IMAGEHLP_SYMBOL   {}
    CHRA              SYM_NAME_LENGTH dup(?)            ;Only ANSI names
  SYMBOL ends

  SymGetSymFromAddrX textequ <SymGetSymFromAddr>
else
  STACK textequ <STACKFRAME64>

  SYMBOL struct
    IMAGEHLP_SYMBOL64 {}
    CHRA              SYM_NAME_LENGTH dup(?)            ;Only ANSI names
  SYMBOL ends

  SymGetSymFromAddrX textequ <SymGetSymFromAddr64>
endif

CALLER_INFO struct
  xRetAddr    XWORD   ?
  xInstrAddr  XWORD   ?
CALLER_INFO ends

CDF_AGGREGATED  equ   BIT00                             ;Set if it is aggregated into another

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Object:     CallData
; Purpose:    Store all relevant info about a specific API call, like the call stack and an system
;             identification like a HANDLE, ID, etc.

Object CallData,, Primer
  VirtualMethod   Show,       XWORD, XWORD              ;Callback method

  DefineVariable  dFlags,     DWORD,        0
  DefineVariable  dReps,      DWORD,        0           ;After Aggregate, it holds the repetitions
  DefineVariable  xData1,     XWORD,        0           ;Primary data
  DefineVariable  xData2,     XWORD,        0           ;Auxiliary data
  DefineVariable  cProcName,  CHRA,         SYM_NAME_LENGTH dup(0)
  DefineVariable  dCount,     DWORD,        0           ;Number if filled CALLER_INFO structures
  DefineVariable  CallStack,  CALLER_INFO,  CALLER_MAX_DEEP dup({0, 0})
ObjectEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Object:     RTC_Collection (RTC: Resource Type Call, RTCC: RTC Collection)
; Purpose:    Collection of CallData Objects aggregated by system resource type.
; Example:    For a resource of type Brush, CallData for CreateSolidBrush, CreateDIBPatternBrush,
;             CreateDIBPatternBrushPt, etc. are aggregated in pRTCC_Brush.

Object RTC_Collection,, Collection
  VirtualMethod   Aggregate
  VirtualMethod   Deaggregate
  RedefineMethod  Insert,     $ObjPtr(CallData)
  VirtualMethod   Remove,     XWORD, XWORD

  DefineVariable  dMaxCount,  DWORD,    0               ;Maximal count to check the system load
  DefineVariable  dTotCount,  DWORD,    0               ;Cummulated number of calls
ObjectEnd

.data                                                   ;Non exported data
  hProcess          HANDLE    0
  xAppRefAddr       XWORD     0
  HookColl          $ObjInst(Collection)                ;Collection of IAT_Hook objects
  RcrcColl          $ObjInst(Collection)                ;Collection of RTC_Collection objects
  FailColl          $ObjInst(RTC_Collection)            ;Failed API calls
  LogiColl          $ObjInst(RTC_Collection)            ;API calls where a logic error was detected
  dResGuardEnabled  DWORD     FALSE

.code
; ==================================================================================================
;    CallData implementation
; ==================================================================================================

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     CallData.Show
; Purpose:    Callback procedure to display the gattered call data on the "LeakReport" DebugCenter
;             child Window.
; Arguments:  Arg1: Dummy argument.
;             Arg2: Dummy argument.
; Return:     Nothing.

Method CallData.Show, uses xbx xdi xsi, xDummy1:XWORD, xDummy2:XWORD
  local Symbol:SYMBOL, xDisplacement:XWORD
  local cBuffer[SYM_NAME_LENGTH]:CHRA

  SetObject xsi
  ;Show a bullet
  .ifBitClr [xsi].dFlags, CDF_AGGREGATED
    invoke DbgOutTextW, $OfsCStrW(" ", 2022h, " "), DbgColorString, DbgColorBackground, \
                        DBG_EFFECT_NORMAL, offset wWndCaption

    invoke DbgOutTextA, addr [xsi].$Obj(CallData).cProcName, DbgColorString, DbgColorBackground, \
                        DBG_EFFECT_NORMAL, offset wWndCaption

    mov edx, [xsi].dReps
    inc edx
    lea xbx, cBuffer
    FillWordA [xbx], < [>
    lea xcx, [xbx + $$Size]
    invoke dword2decA, xcx, edx
    FillStringA [xbx + xax + $$Size - 1], <]>
    invoke DbgOutTextA, addr cBuffer, DbgColorString, DbgColorBackground, \
                        DBG_EFFECT_NORMAL, offset wWndCaption

    xor ebx, ebx
    lea xdi, [xsi].CallStack                            ;xdi -> CallData.CallStack
    .while ebx != [xsi].$Obj(CallData).dCount
      ;Show an arrow
      invoke DbgOutTextW, $OfsCStrW(" ", 2190h, " "), DbgColorWarning, DbgColorBackground, \
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
      FillStringA cBuffer, < (>
      lea xcx, [cBuffer + 2]
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

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     RTC_Collection.Aggregate
; Purpose:    Mark identical calls and add up CallData.Reps.
; Arguments:  None.
; Return:     Nothing.

Method RTC_Collection.Aggregate, uses xbx xdi xsi
  local dOuterIndex:DWORD, dInnerIndex:DWORD

  SetObject xsi
  xor edx, edx
  .while edx != [xsi].dCount
    mov dOuterIndex, edx
    lea edi, [edx + 1]
    mov xbx, $OCall(xsi.ItemAt, edx)                    ;xbx -> CallData
    .ifBitClr [xbx].$Obj(CallData).dFlags, CDF_AGGREGATED
      .while edi != [xsi].dCount
        mov dInnerIndex, edi
        mov xdi, $OCall(xsi.ItemAt, edi)                ;xdi -> CallData
        .ifBitClr [xdi].$Obj(CallData).dFlags, CDF_AGGREGATED
          lea xcx, [xbx].$Obj(CallData).cProcName
          lea xdx, [xdi].$Obj(CallData).cProcName
          invoke StrCompA, xcx, xdx                     ;Check the API name
          .if eax == 0
            mov ecx, [xbx].$Obj(CallData).dCount        ;Check the call data
            .if ecx == [xdi].$Obj(CallData).dCount
              mov eax, sizeof(CALLER_INFO)
              mul ecx
              lea xcx, [xbx].$Obj(CallData).CallStack
              lea xdx, [xdi].$Obj(CallData).CallStack
              invoke MemComp, xcx, xdx, eax
              .if eax == 0
                BitSet [xdi].$Obj(CallData).dFlags, CDF_AGGREGATED
                inc [xbx].$Obj(CallData).dReps          ;Increment dReps count
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

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     RTC_Collection.Deaggregate
; Purpose:    Reset marks and CallData.Reps.
; Arguments:  None.
; Return:     Nothing.

Method RTC_Collection.Deaggregate, uses xsi
  SetObject xsi
  xor edx, edx
  mov xax, [xsi].pItems
  .while edx != [xsi].dCount
    mov xcx, [xax]
    mov [xcx].$Obj(CallData).dFlags, 0
    mov [xcx].$Obj(CallData).dReps, 0
    add xax, sizeof(POINTER)
    inc edx
  .endw
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
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

; ——————————————————————————————————————————————————————————————————————————————————————————————————
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

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      InvokeOriginalAPI
; Purpose:    Invoke the original API (before hooking), regarless of the target bittness.
; Arguments:  None.
; Return:     Nothing.

InvokeOriginalAPI macro ApiName, ArgCount
  ;At this point, all args are stored on the stack. In 64 bit mode, this was done by the compiler
  if TARGET_BITNESS eq 32
    Cnt = ArgCount
    repeat ArgCount                                     ;;Push all arguments creating a new call stack
      @CatStr(<push Arg>, %Cnt)
      Cnt = Cnt - 1
    endm
  else
    if ArgCount gt 4
      Cnt = ArgCount
      repeat ArgCount - 4                               ;;Push higher arguments creating a new call stack
        m2m XWORD ptr [rsp + (Cnt - 1)*sizeof(XWORD)], @CatStr(<Arg>, %Cnt), xax
        Cnt = Cnt - 1
      endm
    endif
  ;;rcx, rdx, r8 & r9 were not changed; Stack reservation (20h) remains unchanged
  endif
  mov xax, pHook&ApiName&
  call [xax].$Obj(IAT_Hook).pEntry                      ;;Call original API
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
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

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      AnalyseStack
; Purpose:    Analize the stack starting from the current context.
; Arguments:  None.
; Return:     xbx -> CallData object.
; Note:       uses xbx xdi

AnalyseStack macro
  mov xbx, $New(CallData)
  OCall xbx::CallData.Init, NULL

  mov hThread, $invoke(GetCurrentThread())

  invoke MemZero, addr Stack, sizeof STACK

  invoke RtlCaptureContext, addr Context                ;;Capture current CPU context in Context
  ;;Context.Xbp_ = [xbp]                                Since RtlCaptureContext does change xbp,
  ;;Context.Xsp_ = lea [xbp + 4/8]                      the returned values correspond to the
  ;;Context.Xip_ = [xbp + 4/8] (ret address)            calling procedure

  mov Stack.AddrPC.Mode,     AddrModeFlat
  mov Stack.AddrFrame.Mode,  AddrModeFlat
  mov Stack.AddrStack.Mode,  AddrModeFlat
  mov Stack.AddrReturn.Mode, AddrModeFlat

  lea xdi, [xbx].$Obj(CallData).CallStack               ;;xdi -> CallData first CallStack

  if TARGET_BITNESS eq 32
    .repeat
      WalkTheStack
      .break .if eax == 0
      m2m [edi].CALLER_INFO.xRetAddr, Context.Eip_, edx
      m2m Context.Eip_, Stack.AddrReturn.Offset_, ecx   ;;Temp storage for next iteration
      m2m [edi].CALLER_INFO.xInstrAddr, Stack.AddrPC.Offset_, edx
      inc [ebx].$Obj(CallData).dCount
      add edi, sizeof CALLER_INFO
      mov eax, Stack.AddrFrame.Offset_                  ;;Use the frame pointer
    .until eax == xAppRefAddr || [ebx].$Obj(CallData).dCount == CALLER_MAX_DEEP
  else
    WalkTheStack                                        ;;Get first frame of the detour proc
    .if eax != 0
      .repeat
        m2m [rdi].CALLER_INFO.xRetAddr, Stack.AddrReturn.Offset_, rdx
        WalkTheStack
        .break .if eax == 0
        m2m [rdi].CALLER_INFO.xInstrAddr, Stack.AddrPC.Offset_, rdx
        inc [rbx].$Obj(CallData).dCount
        add rdi, sizeof CALLER_INFO
        mov rax, Stack.AddrStack.Offset_                ;;Use the stack pointer
      .until rax == xAppRefAddr || [rbx].$Obj(CallData).dCount == CALLER_MAX_DEEP
    .endif
  endif
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      DefineHook
; Purpose:    Define the Hook pointer and do some administration stuff.
; Arguments:  Arg1: API name.
;             Arg2: (optional) RTCD_Coll pointer.
; Return:     Nothing.

DefineHook macro ApiName:req, pRTC_Coll
  HookCount = HookCount + 1                             ;;Keep track of the hook count
  ifnb <pRTC_Coll>
    externdef pRTC_Coll:$ObjPtr(RTC_Collection)         ;;The RTC_Collection will be definend later
  endif
  .data
  pHook&ApiName&   $ObjPtr(IAT_Hook)   NULL
  .code
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      DetourCreate
; Purpose:    Create a standard detour procedure to intercept allocation APIs.
; Arguments:  Arg1: API name.
;             Arg2: API argument count.
;             Arg3: ID = x:
;                     x > 0 : Argument x
;                     x = 0 : API result (return value)
;                     x < 0 : [Argument -x]
;             Arg4: API success condition.
;             Arg5: RTCD_Coll pointer.
;             Arg6: (optional) Remove argument index. This is meant for APIs like HeapRealloc,
;                   where the previous HANDLE/POINTER must be removed first.
;             Arg7: (optional) Condition to bypass registering the successful API call. This is
;                   meant for APIs like LoadCursorA/W with Arg1 = 0, where the resource must not
;                   be released.
; Return:     Nothing.

DetourCreate macro ApiName:req, ArgCount:req, CallIdentifier:req, SuccessCond:req, \
                   pRTC_Coll:req, RemoveArgIndex, PassCond
  local ArgStr, Cnt, @@Exit

  DefineHook ApiName, pRTC_Coll

  ArgStr textequ <>                                     ;;Prepare argument list
  Cnt = 0
  repeat ArgCount
    Cnt = Cnt + 1
    ArgStr CatStr ArgStr, <, >, <Arg>, %Cnt, <:XWORD>
  endm

  Dtr&ApiName& proc uses xbx xdi ArgStr                 ;;Procedure declaration
    local xApiResult:XWORD, hThread:HANDLE
    local Context:CONTEXT, Stack:STACK

    InvokeOriginalAPI ApiName, ArgCount

    .if dResGuardEnabled != FALSE
      mov xApiResult, xax

      AnalyseStack
      FillStringA [xbx].$Obj(CallData).cProcName, <ApiName>
  if CallIdentifier gt 0
      mov xcx, Arg&CallIdentifier&
  elseif CallIdentifier eq 0
      mov xcx, xApiResult
  else
      mov xax, @CatStr(<Arg>, %(-CallIdentifier))
      .if xax != NULL
        mov xcx, [xax]
      .else
        xor ecx, ecx
      .endif
  endif
      mov [xbx].$Obj(CallData).xData1, xcx
      mov [xbx].$Obj(CallData).xData2, 0

  ifnb <SuccessCond>
      .if SuccessCond
  endif
  ifnb <PassCond>
        .if PassCond
          Destroy xbx
        .else
  endif
  ifnb <RemoveArgIndex>
          @CatStr(<OCall >, pRTC_Coll, <::RTC_Collection.Remove, Arg>, RemoveArgIndex, <, 0>)
          .if eax == 0
            lea xax, LogiColl
            mov [xbx].$Obj(CallData).pOwner, xax
            OCall xax::RTC_Collection.Insert, xbx
            jmp @@Exit
          .endif
  endif
          OCall pRTC_Coll::RTC_Collection.Insert, xbx
          mov xax, pRTC_Coll
          mov [xbx].$Obj(CallData).pOwner, xax
  ifnb <PassCond>
        .endif
  endif
  ifnb <SuccessCond>
      .else
        lea xax, FailColl
        mov [xbx].$Obj(CallData).pOwner, xax
        OCall xax::RTC_Collection.Insert, xbx
      .endif
  endif
@@Exit:
      mov xax, xApiResult                               ;;Restore API return value
    .endif
    ret
  Dtr&ApiName& endp
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      DetourDestroy
; Purpose:    Create a standard detour procedure to intercept deallocation APIs.
; Arguments:  Arg1: API name.
;             Arg2: API argument count.
;             Arg3: ID = x:
;                     x > 0 : Argument x
;                     x = 0 : [xsp]
;                     x < 0 : [Argument -x]
;             Arg4: API success condition.
;             Arg5: RTCD_Coll pointer list (One deallocation API for several allocation APIs).
; Return:     Nothing.

DetourDestroy macro ApiName:req, ArgCount:req, CallIdentifier:req, SuccessCond:req,
                    pRTC_Coll_List:vararg
  local ArgStr, Cnt, Coll, @@Exit

  DefineHook ApiName

  ArgStr textequ <>
  Cnt = 0
  repeat ArgCount
    Cnt = Cnt + 1
    ArgStr CatStr ArgStr, <, >, <Arg>, %Cnt, <:XWORD>
  endm

  Dtr&ApiName& proc uses xbx xdi ArgStr                 ;;Procedure declaration
    local xApiResult:XWORD, hThread:HANDLE
    local Context:CONTEXT, Stack:STACK

    InvokeOriginalAPI ApiName, ArgCount

    .if dResGuardEnabled != FALSE
      mov xApiResult, xax

      AnalyseStack
      FillStringA [xbx].$Obj(CallData).cProcName, <ApiName>
  if CallIdentifier gt 0
      mov xcx, Arg&CallIdentifier&
  elseif CallIdentifier eq 0
      mov xcx, xApiResult
  else
      mov xax, @CatStr(<Arg>, %(-CallIdentifier))
      .if xax != NULL
        mov xcx, [xax]
      .else
        xor ecx, ecx
      .endif
  endif
      mov [xbx].$Obj(CallData).xData1, xcx
      mov [xbx].$Obj(CallData).xData2, 0

  ifnb <SuccessCond>
      .if SuccessCond
  endif
        for pColl, <pRTC_Coll_List>                   ;;Search in all specified RTC_Collection objects
          @CatStr(<OCall >, pColl, <::RTC_Collection.Remove, Arg>, CallIdentifier, <, 0>)
          test eax, eax
          jnz @@Exit                                  ;;Exit if found
        endm
        lea xax, LogiColl
        mov [xbx].$Obj(CallData).pOwner, xax
        OCall xax::RTC_Collection.Insert, xbx

  ifnb <SuccessCond>
        jmp @@Exit
      .endif

      lea xax, FailColl
      mov [xbx].$Obj(CallData).pOwner, xax
      OCall xax::RTC_Collection.Insert, xbx
  endif
@@Exit:
      mov xax, xApiResult                               ;;Restore API return value
    .endif
    ret
  Dtr&ApiName& endp
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      DetourCreateNamed
; Purpose:    Create a standard detour procedure to intercept allocation named APIs.
; Arguments:  Arg1: API name.
;             Arg2: API argument count.
;             Arg3: ID = x:
;                     x > 0 : Argument x
;                     x = 0 : API result (return value)
;                     x < 0 : [Argument -x]
;             Arg4: API success condition.
;             Arg5: RTCD_Coll pointer.
; Return:     Nothing.

DetourCreateNamed macro ApiName:req, ArgCount:req, CallIdentifier:req, SuccessCond:req, pRTC_Coll:req
  local ArgStr, Cnt

  DefineHook ApiName, pRTC_Coll

  ArgStr textequ <>                                     ;;Prepare argument list
  Cnt = 0
  repeat ArgCount
    Cnt = Cnt + 1
    ArgStr CatStr ArgStr, <, >, <Arg>, %Cnt, <:XWORD>
  endm

  Dtr&ApiName& proc uses xbx xdi ArgStr                 ;;Procedure declaration
    local xApiResult:XWORD, hThread:HANDLE
    local Context:CONTEXT, Stack:STACK

    InvokeOriginalAPI ApiName, ArgCount

    .if dResGuardEnabled != FALSE
      mov xApiResult, xax

      AnalyseStack
      FillStringA [xbx].$Obj(CallData).cProcName, <ApiName>
  if CallIdentifier gt 0
      mov xcx, Arg&CallIdentifier&
  elseif CallIdentifier eq 0
      mov xcx, xApiResult
  else
      mov xax, @CatStr(<Arg>, %(-CallIdentifier))
      .if xax != NULL
        mov xcx, [xax]
      .else
        xor ecx, ecx
      .endif
  endif
      mov [xbx].$Obj(CallData).xData1, xcx
      mov [xbx].$Obj(CallData).xData2, 0

      .if SuccessCond
        ;In case that this named API was called previously, we remove this call data
        OCall pRTC_Coll::RTC_Collection.Remove, [xbx].$Obj(CallData).xData1, [xbx].$Obj(CallData).xData2

        OCall pRTC_Coll::RTC_Collection.Insert, xbx
        mov xax, pRTC_Coll
        mov [xbx].$Obj(CallData).pOwner, xax
      .else
        lea xax, FailColl
        mov [xbx].$Obj(CallData).pOwner, xax
        OCall xax::RTC_Collection.Insert, xbx
      .endif

      mov xax, xApiResult                               ;;Restore API return value
    .endif
    ret
  Dtr&ApiName& endp
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      DetourCreateCounted
; Purpose:    Create a counted detour procedure to intercept allocation APIs.
; Arguments:  Arg1: API name.
;             Arg2: API argument count.
;             Arg3: Counter name.
;             Arg4: API success condition.
;             Arg5: RTCD_Coll pointer.
; Return:     Nothing.

DetourCreateCounted macro ApiName:req, ArgCount:req, CounterName:req, SuccessCond:req, pRTC_Coll:req
  local ArgStr, Cnt

  DefineHook ApiName, pRTC_Coll

  ArgStr textequ <>                                     ;;Prepare argument list
  Cnt = 0
  repeat ArgCount
    Cnt = Cnt + 1
    ArgStr CatStr ArgStr, <, >, <Arg>, %Cnt, <:XWORD>
  endm

  Dtr&ApiName& proc uses xbx xdi ArgStr                 ;;Procedure declaration
    local xApiResult:XWORD, hThread:HANDLE
    local Context:CONTEXT, Stack:STACK

    InvokeOriginalAPI ApiName, ArgCount

    .if dResGuardEnabled != FALSE
      mov xApiResult, xax

      AnalyseStack
      FillStringA [xbx].$Obj(CallData).cProcName, <ApiName>

      .if SuccessCond
        inc CounterName
        m2m [xbx].$Obj(CallData).xData1, CounterName, xax
        mov [xbx].$Obj(CallData).xData2, 0
        OCall pRTC_Coll::RTC_Collection.Insert, xbx
        mov xax, pRTC_Coll
        mov [xbx].$Obj(CallData).pOwner, xax
      .else
        mov [xbx].$Obj(CallData).xData1, -1
        lea xax, FailColl
        mov [xbx].$Obj(CallData).pOwner, xax
        OCall xax::RTC_Collection.Insert, xbx
      .endif

      mov xax, xApiResult                               ;;Restore API return value
    .endif
    ret
  Dtr&ApiName& endp
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      DetourDestroyCounted
; Purpose:    Create a counted detour procedure to intercept deallocation APIs.
; Arguments:  Arg1: API name.
;             Arg2: API argument count.
;             Arg3: Counter name.
;             Arg4: API success condition.
;             Arg5: RTCD_Coll pointer list (One deallocation API for several allocation APIs).
; Return:     Nothing.

DetourDestroyCounted macro ApiName:req, ArgCount:req, CounterName:req, SuccessCond:req, pRTC_Coll_List:vararg
  local ArgStr, Cnt, Coll, @@Exit

  DefineHook ApiName

  ArgStr textequ <>
  Cnt = 0
  repeat ArgCount
    Cnt = Cnt + 1
    ArgStr CatStr ArgStr, <, >, <Arg>, %Cnt, <:DWORD>
  endm

  Dtr&ApiName& proc uses xbx xdi ArgStr                 ;;Procedure declaration
    local xApiResult:XWORD, hThread:HANDLE
    local Context:CONTEXT, Stack:STACK

    InvokeOriginalAPI ApiName, ArgCount

    .if dResGuardEnabled != FALSE
      mov xApiResult, xax

      AnalyseStack
      FillStringA [xbx].$Obj(CallData).cProcName, <ApiName>
      m2m [xbx].$Obj(CallData).xData1, CounterName, xcx
      mov [xbx].$Obj(CallData).xData2, 0

  ifnb <SuccessCond>
      .if SuccessCond
  endif
        for pColl, <pRTC_Coll_List>                     ;;Search in all specified RTC_Collection objects
          @CatStr(<OCall >, pColl, <::RTC_Collection.Remove, >, CounterName, <, 0>)
          .if eax != FALSE
            dec CounterName
            jmp @@Exit                                  ;;Exit if found
          .endif
        endm
        lea xax, LogiColl
        mov [xbx].$Obj(CallData).pOwner, xax
        OCall xax::RTC_Collection.Insert, xbx
  ifnb <SuccessCond>
        jmp @@Exit
      .endif
      lea xax, FailColl
      mov [xbx].$Obj(CallData).pOwner, xax
      OCall xax::RTC_Collection.Insert, xbx
  endif
@@Exit:
      mov xax, xApiResult                               ;;Restore API return value
    .endif
    ret
  Dtr&ApiName& endp
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      NewHook
; Purpose:    Create a new hook.
; Arguments:  Arg1: API procedure name.
;             Arg2: API library name.
; Return:     Nothing.

NewHook macro ProcName:req, LibName:req
% New IAT_Hook
  mov pHook&ProcName&, xax                              ;;Save the IAT_Hook in this var
  OCall xax::IAT_Hook.Init, offset HookColl, $OfsCStrA("&LibName&.dll"), $OfsCStrA("&ProcName&"), \
                            offset Dtr&ProcName&, FALSE
  mov xax, pHook&ProcName&
  .if [xax].$Obj(IAT_Hook).dErrorCode != OBJ_OK
    Destroy xax
  .else
    OCall HookColl::Collection.Insert, xax              ;;and in a dedicated HookColl collection
  .endif
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      NewRTCC
; Purpose:    Create a new RTC_Collection.
; Arguments:  Arg1: Resource type name.
;             Arg2: Initial collection size.
; Return:     Nothing.

NewRTCC macro ResTypeName:req, ColSize:req
  .data
  pRTCC_&ResTypeName&  $ObjPtr(RTC_Collection)  NULL

  .code
  New RTC_Collection
  mov pRTCC_&ResTypeName&, xax
  OCall RcrcColl::Collection.Insert, xax
  OCall xax::RTC_Collection.Init, offset RcrcColl, %ColSize, %ColSize, COL_MAX_CAPACITY
endm

; ==================================================================================================

DetourCreate CreateJobObjectA, 2, 0, <xApiResult !!= NULL>, pRTCC_Job
DetourCreate CreateJobObjectW, 2, 0, <xApiResult !!= NULL>, pRTCC_Job

; ——————————————————————————————————————————————————————————————————————————————————————————————————

DetourCreate CreateTransactionA, 7, 0, <xApiResult !!= NULL>, pRTCC_Transaction
DetourCreate CreateTransactionW, 7, 0, <xApiResult !!= NULL>, pRTCC_Transaction

; ——————————————————————————————————————————————————————————————————————————————————————————————————

DetourCreate CreatePrivateNamespaceA, 3, 0, <xApiResult !!= NULL>, pRTCC_PrivateNamespace
DetourCreate CreatePrivateNamespaceW, 3, 0, <xApiResult !!= NULL>, pRTCC_PrivateNamespace
DetourDestroy ClosePrivateNamespace, 3, 3, <xApiResult !!= FALSE>, pRTCC_PrivateNamespace

; ——————————————————————————————————————————————————————————————————————————————————————————————————

DetourCreate HeapAlloc, 3, 0, <xApiResult !!= NULL>, pRTCC_HeapMemBlock
DetourCreate HeapReAlloc, 4, 0, <xApiResult !!= NULL>, pRTCC_HeapMemBlock, 3
DetourDestroy HeapFree, 3, 3, <xApiResult !!= FALSE>, pRTCC_HeapMemBlock

; ——————————————————————————————————————————————————————————————————————————————————————————————————

DetourCreate GlobalAlloc, 2, 0, <xApiResult !!= NULL>, pRTCC_GlobalMemBlock
DetourCreate GlobalReAlloc, 3, 0, <xApiResult !!= NULL>, pRTCC_GlobalMemBlock, 1
DetourDestroy GlobalFree, 1, 1, <xApiResult == NULL>, pRTCC_GlobalMemBlock

; ——————————————————————————————————————————————————————————————————————————————————————————————————

DetourCreate LocalAlloc, 2, 0, <xApiResult !!= NULL>, pRTCC_LocalMemBlock
DetourCreate LocalReAlloc, 3, 0, <xApiResult !!= NULL>, pRTCC_LocalMemBlock, 1
DetourDestroy LocalFree, 1, 1, <xApiResult == NULL>, pRTCC_LocalMemBlock

; ——————————————————————————————————————————————————————————————————————————————————————————————————

DetourCreate CoTaskMemAlloc, 1, 0, <xApiResult !!= NULL>, pRTCC_CoTaskMemBlock
DetourCreate CoTaskMemRealloc, 1, 0, <xApiResult !!= NULL>, pRTCC_CoTaskMemBlock, 1
DetourDestroy CoTaskMemFree, 1, 1, <>, pRTCC_CoTaskMemBlock

; ——————————————————————————————————————————————————————————————————————————————————————————————————

DetourCreate VirtualAlloc, 4, 0, <xApiResult !!= NULL>, pRTCC_VirtualMemBlock
DetourDestroy VirtualFree, 3, 1, <xApiResult !!= FALSE>, pRTCC_VirtualMemBlock

; ——————————————————————————————————————————————————————————————————————————————————————————————————

DetourCreate SysAllocString, 1, 0, <xApiResult !!= NULL>, pRTCC_SysString
DetourCreate SysAllocStringLen, 2, 0, <xApiResult !!= NULL>, pRTCC_SysString
DetourCreate SysAllocStringByteLen, 2, 0, <xApiResult !!= NULL>, pRTCC_SysString
DetourCreate SysReAllocString, 2, 0, <xApiResult !!= FALSE>, pRTCC_SysString
DetourCreate SysReAllocStringLen, 3, 0, <xApiResult !!= FALSE>, pRTCC_SysString
DetourDestroy SysFreeString, 1, 1, <xApiResult !!= FALSE>, pRTCC_SysString

; ——————————————————————————————————————————————————————————————————————————————————————————————————

DetourCreate BeginPaint, 2, 2, <xApiResult !!= NULL>, pRTCC_PaintStruct
DetourDestroy EndPaint, 2, 2, <xApiResult !!= FALSE>, pRTCC_PaintStruct

; ——————————————————————————————————————————————————————————————————————————————————————————————————

DetourCreate CreatePen, 3, 0, <xApiResult !!= NULL>, pRTCC_Pen
DetourCreate CreatePenIndirect, 1, 0, <xApiResult !!= NULL>, pRTCC_Pen
DetourCreate ExtCreatePen, 5, 0, <xApiResult !!= NULL>, pRTCC_Pen

; ------------------------------------------------------------------------------

DetourCreate CreateSolidBrush, 1, 0, <xApiResult !!= NULL>, pRTCC_Brush
DetourCreate CreateDIBPatternBrush, 2, 0, <xApiResult !!= NULL>, pRTCC_Brush
DetourCreate CreateDIBPatternBrushPt, 2, 0, <xApiResult !!= NULL>, pRTCC_Brush
DetourCreate CreateHatchBrush, 2, 0, <xApiResult !!= NULL>, pRTCC_Brush
DetourCreate CreatePatternBrush, 1, 0, <xApiResult !!= NULL>, pRTCC_Brush
DetourCreate CreateBrushIndirect, 1, 0, <xApiResult !!= NULL>, pRTCC_Brush

; ------------------------------------------------------------------------------

DetourCreate CreateBitmap, 5, 0, <xApiResult !!= NULL>, pRTCC_Bitmap
DetourCreate CreateBitmapIndirect, 1, 0, <xApiResult !!= NULL>, pRTCC_Bitmap
DetourCreate CreateCompatibleBitmap, 3, 0, <xApiResult !!= NULL>, pRTCC_Bitmap
DetourCreate CreateDIBitmap, 6, 0, <xApiResult !!= NULL>, pRTCC_Bitmap
DetourCreate CreateDIBSection, 6, 0, <xApiResult !!= NULL>, pRTCC_Bitmap
DetourCreate CreateDiscardableBitmap, 3, 0, <xApiResult !!= NULL>, pRTCC_Bitmap
DetourCreate LoadBitmapA, 2, 0, <xApiResult !!= NULL>, pRTCC_Bitmap
DetourCreate LoadBitmapW, 2, 0, <xApiResult !!= NULL>, pRTCC_Bitmap
DetourCreate GdipCreateHBITMAPFromBitmap, 3, -2, <xApiResult == 0>, pRTCC_Bitmap

; ------------------------------------------------------------------------------

DetourCreate CreateEllipticRgn, 4, 0, <xApiResult !!= NULL>, pRTCC_Region
DetourCreate CreateEllipticRgnIndirect, 1, 0, <xApiResult !!= NULL>, pRTCC_Region
DetourCreate CreatePenDataRegion, 2, 0, <xApiResult !!= NULL>, pRTCC_Region
DetourCreate CreatePolygonRgn, 3, 0, <xApiResult !!= NULL>, pRTCC_Region
DetourCreate CreatePolyPolygonRgn, 4, 0, <xApiResult !!= NULL>, pRTCC_Region
DetourCreate CreateRectRgn, 4, 0, <xApiResult !!= NULL>, pRTCC_Region
DetourCreate CreateRectRgnIndirect, 1, 0, <xApiResult !!= NULL>, pRTCC_Region
DetourCreate CreateRoundRectRgn, 6, 0, <xApiResult !!= NULL>, pRTCC_Region
DetourCreate ExtCreateRegion, 3, 0, <xApiResult !!= NULL>, pRTCC_Region
DetourDestroy SetWindowRgn, 3, 2, <xApiResult !!= FALSE>, pRTCC_Region  ;This region is destroyed by the window!

; ------------------------------------------------------------------------------

DetourCreate CopyImage, 5, 0, <xApiResult !!= NULL>, pRTCC_Image
DetourCreate LoadImageA, 6, 0, <xApiResult !!= NULL>, pRTCC_Image
DetourCreate LoadImageW, 6, 0, <xApiResult !!= NULL>, pRTCC_Image

; ------------------------------------------------------------------------------

DetourCreate CreateFontA, 14, 0, <xApiResult !!= NULL>, pRTCC_Font
DetourCreate CreateFontW, 14, 0, <xApiResult !!= NULL>, pRTCC_Font
DetourCreate CreateFontIndirectA, 1, 0, <xApiResult !!= NULL>, pRTCC_Font
DetourCreate CreateFontIndirectW, 1, 0, <xApiResult !!= NULL>, pRTCC_Font
DetourCreate CreateFontIndirectExA, 1, 0, <xApiResult !!= NULL>, pRTCC_Font
DetourCreate CreateFontIndirectExW, 1, 0, <xApiResult !!= NULL>, pRTCC_Font

; ------------------------------------------------------------------------------

DetourCreate CreatePalette, 1, 0, <xApiResult !!= NULL>, pRTCC_Palette
DetourCreate CreateHalftonePalette, 1, 0, <xApiResult !!= NULL>, pRTCC_Palette

; ------------------------------------------------------------------------------

DetourCreate CreateColorSpaceA, 1, 0, <xApiResult !!= NULL>, pRTCC_ColorSpace
DetourCreate CreateColorSpaceW, 1, 0, <xApiResult !!= NULL>, pRTCC_ColorSpace

; ——————————————————————————————————————————————————————————————————————————————————————————————————

DetourCreate GetStockObject, 1, 0, <xApiResult !!= NULL>, pRTCC_StockObject

; ——————————————————————————————————————————————————————————————————————————————————————————————————

DetourCreate CreateDCA, 4, 0, <xApiResult !!= NULL>, pRTCC_DeviceContext
DetourCreate CreateDCW, 4, 0, <xApiResult !!= NULL>, pRTCC_DeviceContext
DetourCreate CreateCompatibleDC, 1, 0, <xApiResult !!= NULL>, pRTCC_DeviceContext
DetourCreate CreateICA, 4, 0, <xApiResult !!= NULL>, pRTCC_DeviceContext
DetourCreate CreateICW, 4, 0, <xApiResult !!= NULL>, pRTCC_DeviceContext
DetourDestroy DeleteDC, 1, 1, <xApiResult !!= FALSE>, pRTCC_DeviceContext

; ------------------------------------------------------------------------------

DetourDestroy DeleteObject, 1, 1, <xApiResult !!= FALSE>, pRTCC_Pen, pRTCC_Brush, pRTCC_Bitmap, \
                                                pRTCC_Region, pRTCC_Font, pRTCC_Palette, \
                                                pRTCC_ColorSpace, pRTCC_Image, pRTCC_StockObject, \
                                                pRTCC_DeviceContext

; ——————————————————————————————————————————————————————————————————————————————————————————————————

DetourCreate CreateCursor, 7, 0, <xApiResult !!= NULL>, pRTCC_Cursor
DetourCreate CopyCursor, 1, 1, <>, pRTCC_Cursor
DetourCreate LoadCursorA, 2, 0, <xApiResult !!= NULL>, pRTCC_Cursor,, <Arg1 == NULL>
DetourCreate LoadCursorW, 2, 0, <xApiResult !!= NULL>, pRTCC_Cursor,, <Arg1 == NULL>
DetourCreate LoadCursorFromFileA, 1, 0, <xApiResult !!= NULL>, pRTCC_Cursor
DetourCreate LoadCursorFromFileW, 1, 0, <xApiResult !!= NULL>, pRTCC_Cursor

DetourDestroy SetSystemCursor, 2, 1, <xApiResult !!= FALSE>, pRTCC_Cursor       ;;Destroys src Cursor

externdef pRTCC_Icon:$ObjPtr(RTC_Collection)
;DestroyCursor and DestroyIcon use the same API
DetourDestroy DestroyCursor, 1, 1, <xApiResult !!= FALSE>, pRTCC_Cursor, pRTCC_Icon, pRTCC_Image

; ——————————————————————————————————————————————————————————————————————————————————————————————————

DetourCreate CopyIcon, 1, 0, <xApiResult !!= NULL>, pRTCC_Icon
DetourCreate CreateIcon, 7, 0, <xApiResult !!= NULL>, pRTCC_Icon
DetourCreate CreateIconIndirect, 1, 0, <xApiResult !!= NULL>, pRTCC_Icon
DetourCreate CreateIconFromResource, 4, 0, <xApiResult !!= NULL>, pRTCC_Icon
DetourCreate CreateIconFromResourceEx, 7, 0, <xApiResult !!= NULL>, pRTCC_Icon
DetourCreate DuplicateIcon, 2, 0, <xApiResult !!= NULL>, pRTCC_Icon
DetourCreate ExtractIconA, 2, 0, <xApiResult !!= NULL>, pRTCC_Icon
DetourCreate ExtractIconW, 2, 0, <xApiResult !!= NULL>, pRTCC_Icon
DetourCreate ExtractIconExA, 2, 0, <xApiResult !!= NULL>, pRTCC_Icon
DetourCreate ExtractIconExW, 2, 0, <xApiResult !!= NULL>, pRTCC_Icon
DetourCreate ExtractAssociatedIconA, 3, 0, <xApiResult !!= NULL>, pRTCC_Icon
DetourCreate ExtractAssociatedIconW, 3, 0, <xApiResult !!= NULL>, pRTCC_Icon
DetourCreate LoadIconA, 2, 0, <xApiResult !!= NULL>, pRTCC_Icon
DetourCreate LoadIconW, 2, 0, <xApiResult !!= NULL>, pRTCC_Icon
DetourCreate LoadIconMetric, 4, -4, <xApiResult == S_OK>, pRTCC_Icon
DetourCreate LoadIconWithScaleDown, 5, -5, <xApiResult == S_OK>, pRTCC_Icon
DetourCreate GdipCreateHICONFromBitmap, 2, -2, <xApiResult == 0>, pRTCC_Icon

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      DetourPrivateExtractIconsX
; Purpose:    Create a standard detour procedure to intercept allocation APIs.
; Arguments:  Arg1: API name.
; Return:     Nothing.

DetourPrivateExtractIconsX macro ApiName:req
  local ArgStr, Cnt

  DefineHook ApiName, pRTCC_Icon

  ArgStr textequ <>                                     ;;Prepare argument list
  Cnt = 0
  repeat 8
    Cnt = Cnt + 1
    ArgStr CatStr ArgStr, <, >, <Arg>, %Cnt, <:XWORD>
  endm

  Dtr&ApiName& proc uses xbx xdi xsi ArgStr             ;;Procedure declaration
    local xApiResult:XWORD, hThread:HANDLE
    local Context:CONTEXT, Stack:STACK

    InvokeOriginalAPI ApiName, 8

    .if dResGuardEnabled != FALSE
      mov xApiResult, xax

      .if xApiResult == 0
        Destroy xbx
      .else
        FillStringA [xbx].$Obj(CallData).cProcName, <ApiName>
        AnalyseStack
        .if xApiResult == 0xFFFFFFFF                    ;;File is not found
          lea xax, FailColl
          mov [xbx].$Obj(CallData).pOwner, xax
          OCall xax::RTC_Collection.Insert, xbx
        .else
          xor esi, esi
          .while xsi < xApiResult
            MemAlloc sizeof($Obj(CallData))
            s2s $Obj(CallData) ptr [xax], $Obj(CallData) ptr [xbx], xmm0, xmm1, xmm2, xmm3, xmm4, xmm5, xmm6, xmm7, xcx, xdx
            mov xdx, Arg5                               ;;phicon
            m2m [xax].$Obj(CallData).xData1, [xdx + xsi*sizeof(HANDLE)], xcx
            mov [xax].$Obj(CallData).xData2, 0
            mov [xax].$Obj(CallData).pOwner, xcx
            OCall pRTCC_Icon::RTC_Collection.Insert, xax
            inc esi
          .endw
          Destroy xbx
        .endif
      .endif
      mov xax, xApiResult                               ;;Restore API return value
    .endif
    ret
  Dtr&ApiName& endp
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————

DetourPrivateExtractIconsX PrivateExtractIconsA

DetourPrivateExtractIconsX PrivateExtractIconsW

;DestroyCursor and DestroyIcon use the same API
DetourDestroy DestroyIcon, 1, 1, <xApiResult !!= FALSE>, pRTCC_Icon, pRTCC_Cursor, pRTCC_Image

; ——————————————————————————————————————————————————————————————————————————————————————————————————

DetourCreate CreateMenu, 0, 0, <xApiResult !!= NULL>, pRTCC_Menu
DetourCreate CreatePopupMenu, 0, 0, <xApiResult !!= NULL>, pRTCC_Menu
DetourCreate LoadMenuA, 2, 0, <xApiResult !!= NULL>, pRTCC_Menu
DetourCreate LoadMenuW, 2, 0, <xApiResult !!= NULL>, pRTCC_Menu
DetourCreate LoadMenuIndirectA, 1, 0, <xApiResult !!= NULL>, pRTCC_Menu
DetourCreate LoadMenuIndirectW, 1, 0, <xApiResult !!= NULL>, pRTCC_Menu
DetourDestroy DestroyMenu, 1, 1, <xApiResult !!= FALSE>, pRTCC_Menu

; ——————————————————————————————————————————————————————————————————————————————————————————————————

DetourCreate CloseMetaFile, 1, 0, <xApiResult !!= NULL>, pRTCC_MetaFile
DetourCreate CopyMetaFileA, 2, 0, <xApiResult !!= NULL>, pRTCC_MetaFile
DetourCreate CopyMetaFileW, 2, 0, <xApiResult !!= NULL>, pRTCC_MetaFile
DetourCreate CreateMetaFileA, 1, 0, <xApiResult !!= NULL>, pRTCC_MetaFile
DetourCreate CreateMetaFileW, 1, 0, <xApiResult !!= NULL>, pRTCC_MetaFile
DetourCreate GetMetaFileA, 1, 0, <xApiResult !!= NULL>, pRTCC_MetaFile
DetourCreate GetMetaFileW, 1, 0, <xApiResult !!= NULL>, pRTCC_MetaFile
DetourDestroy DeleteMetaFile, 1, 1, <xApiResult !!= FALSE>, pRTCC_MetaFile

; ——————————————————————————————————————————————————————————————————————————————————————————————————

DetourCreate CloseEnhMetaFile, 1, 0, <xApiResult !!= NULL>, pRTCC_EnhMetaFile
DetourCreate CopyEnhMetaFileA, 2, 0, <xApiResult !!= NULL>, pRTCC_EnhMetaFile
DetourCreate CopyEnhMetaFileW, 2, 0, <xApiResult !!= NULL>, pRTCC_EnhMetaFile
DetourCreate CreateEnhMetaFileA, 1, 0, <xApiResult !!= NULL>, pRTCC_EnhMetaFile
DetourCreate CreateEnhMetaFileW, 1, 0, <xApiResult !!= NULL>, pRTCC_EnhMetaFile
DetourCreate GetEnhMetaFileA, 1, 0, <xApiResult !!= NULL>, pRTCC_EnhMetaFile
DetourCreate GetEnhMetaFileW, 1, 0, <xApiResult !!= NULL>, pRTCC_EnhMetaFile
DetourDestroy DeleteEnhMetaFile, 1, 1, <xApiResult !!= FALSE>, pRTCC_EnhMetaFile

; ——————————————————————————————————————————————————————————————————————————————————————————————————

DetourCreate CreateAcceleratorTableA, 2, 0, <xApiResult !!= NULL>, pRTCC_AccTable
DetourCreate CreateAcceleratorTableW, 2, 0, <xApiResult !!= NULL>, pRTCC_AccTable
DetourCreate CopyAcceleratorTableA, 3, 0, <xApiResult !!= NULL>, pRTCC_AccTable
DetourCreate CopyAcceleratorTableW, 3, 0, <xApiResult !!= NULL>, pRTCC_AccTable
DetourCreate LoadAcceleratorsA, 2, 0, <xApiResult !!= NULL>, pRTCC_AccTable
DetourCreate LoadAcceleratorsW, 2, 0, <xApiResult !!= NULL>, pRTCC_AccTable
DetourDestroy DestroyAcceleratorTable, 1, 1, <xApiResult !!= FALSE>, pRTCC_AccTable

; ——————————————————————————————————————————————————————————————————————————————————————————————————

DetourCreate CreateDesktopA, 6, 0, <xApiResult !!= NULL>, pRTCC_Desktop
DetourCreate CreateDesktopW, 6, 0, <xApiResult !!= NULL>, pRTCC_Desktop
DetourCreate CreateDesktopExA, 8, 0, <xApiResult !!= NULL>, pRTCC_Desktop
DetourCreate CreateDesktopExW, 8, 0, <xApiResult !!= NULL>, pRTCC_Desktop
DetourDestroy CloseDesktop, 1, 1, <xApiResult !!= FALSE>, pRTCC_Desktop

; ——————————————————————————————————————————————————————————————————————————————————————————————————

DetourCreate CreateWindowStationA, 4, 0, <xApiResult !!= NULL>, pRTCC_WindowStation
DetourCreate CreateWindowStationW, 4, 0, <xApiResult !!= NULL>, pRTCC_WindowStation
DetourCreate OpenWindowStationA, 3, 0, <xApiResult !!= NULL>, pRTCC_WindowStation
DetourCreate OpenWindowStationW, 3, 0, <xApiResult !!= NULL>, pRTCC_WindowStation
DetourDestroy CloseWindowStation, 1, 1, <xApiResult !!= FALSE>, pRTCC_WindowStation

; ——————————————————————————————————————————————————————————————————————————————————————————————————

DetourCreate CreateFileA, 7, 0, <xApiResult !!= INVALID_HANDLE_VALUE>, pRTCC_File
DetourCreate CreateFileW, 7, 0, <xApiResult !!= INVALID_HANDLE_VALUE>, pRTCC_File
DetourCreate CreateFileTransactedA, 10, 0, <xApiResult !!= INVALID_HANDLE_VALUE>, pRTCC_File
DetourCreate CreateFileTransactedW, 10, 0, <xApiResult !!= INVALID_HANDLE_VALUE>, pRTCC_File

; ------------------------------------------------------------------------------

DetourCreate CreateEventA, 4, 0, <xApiResult !!= NULL>, pRTCC_Event
DetourCreate CreateEventW, 4, 0, <xApiResult !!= NULL>, pRTCC_Event
DetourCreateNamed CreateEventExA, 4, 0, <xApiResult !!= NULL>, pRTCC_Event
DetourCreateNamed CreateEventExW, 4, 0, <xApiResult !!= NULL>, pRTCC_Event
DetourCreate OpenEventA, 3, 0, <xApiResult !!= NULL>, pRTCC_Event
DetourCreate OpenEventW, 3, 0, <xApiResult !!= NULL>, pRTCC_Event

; ------------------------------------------------------------------------------

DetourCreateNamed CreateFileMappingA, 6, 0, <xApiResult !!= NULL>, pRTCC_FileMapping
DetourCreateNamed CreateFileMappingW, 6, 0, <xApiResult !!= NULL>, pRTCC_FileMapping
DetourCreateNamed CreateFileMappingNumaA, 7, 0, <xApiResult !!= NULL>, pRTCC_FileMapping
DetourCreateNamed CreateFileMappingNumaW, 7, 0, <xApiResult !!= NULL>, pRTCC_FileMapping

; ------------------------------------------------------------------------------

DetourCreate CreateMutexA, 3, 0, <xApiResult !!= NULL>, pRTCC_Mutex
DetourCreate CreateMutexW, 3, 0, <xApiResult !!= NULL>, pRTCC_Mutex
DetourCreate OpenMutexA, 3, 0, <xApiResult !!= NULL>, pRTCC_Mutex
DetourCreate OpenMutexW, 3, 0, <xApiResult !!= NULL>, pRTCC_Mutex

; ------------------------------------------------------------------------------

DefineHook CreatePipe, pRTCC_Pipe

;This detour proc handles the Read and Write HANDLEs
DtrCreatePipe proc uses xbx xdi Arg1:XWORD, Arg2:XWORD, Arg3:XWORD, Arg4:XWORD
  local xApiResult:XWORD, hThread:HANDLE
  local Context:CONTEXT, Stack:STACK

  InvokeOriginalAPI CreatePipe, 4

  .if dResGuardEnabled != FALSE
    mov xApiResult, xax

    AnalyseStack
    FillStringA [xbx].$Obj(CallData).cProcName, <CreatePipe>

    .if xApiResult != 0
      mov xcx, Arg1                                     ;-> hReadPipe
      .if xcx != NULL
        m2m [xbx].$Obj(CallData).xData1, [xcx], xdx
        mov [xbx].$Obj(CallData).xData2, 0
        OCall pRTCC_Pipe::Collection.Insert, xbx
        mov xax, pRTCC_Pipe
        mov [xbx].$Obj(CallData).pOwner, xax
        OCall xax::Collection.Insert, xbx
        .if Arg2 != NULL
          ;Clone existing CallData
          mov xdi, $MemAlloc(sizeof $Obj(CallData))
          s2s $Obj(CallData) ptr [xdi], $Obj(CallData) ptr [xbx], xmm0, xmm1, xmm2, xmm3, xmm4, xmm5, xmm6, xmm7, xax, xcx
          mov xcx, Arg2                                 ;-> hWritePipe
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
      lea xax, FailColl
      mov [xbx].$Obj(CallData).pOwner, xax
      OCall xax::RTC_Collection.Insert, xbx
    .endif

    mov xax, xApiResult                                 ;Restore API return value
  .endif
  ret
DtrCreatePipe endp

DetourCreateNamed CreateNamedPipeA, 8, 0, <xApiResult !!= INVALID_HANDLE_VALUE>, pRTCC_Pipe
DetourCreateNamed CreateNamedPipeW, 8, 0, <xApiResult !!= INVALID_HANDLE_VALUE>, pRTCC_Pipe

; ------------------------------------------------------------------------------

DetourCreate CreateProcessA, 10, -10, <xApiResult !!= FALSE>, pRTCC_Process
DetourCreate CreateProcessW, 10, -10, <xApiResult !!= FALSE>, pRTCC_Process
DetourCreate CreateProcessAsUserA, 11, -11, <xApiResult !!= FALSE>, pRTCC_Process
DetourCreate CreateProcessAsUserW, 11, -11, <xApiResult !!= FALSE>, pRTCC_Process
DetourCreate CreateProcessWithLogonA, 11, -11, <xApiResult !!= FALSE>, pRTCC_Process
DetourCreate CreateProcessWithLogonW, 11, -11, <xApiResult !!= FALSE>, pRTCC_Process
DetourCreate OpenProcess, 3, 0, <xApiResult !!= NULL>, pRTCC_Process

; ------------------------------------------------------------------------------

DetourCreate CreateThread, 6, 0, <xApiResult !!= NULL>, pRTCC_Thread
DetourCreate CreateRemoteThread, 3, 0, <xApiResult !!= NULL>, pRTCC_Thread

; ------------------------------------------------------------------------------

DetourCreate CreateSemaphoreA, 4, 0, <xApiResult !!= NULL>, pRTCC_Semaphore
DetourCreate CreateSemaphoreW, 4, 0, <xApiResult !!= NULL>, pRTCC_Semaphore
DetourCreate CreateSemaphoreExA, 6, 0, <xApiResult !!= NULL>, pRTCC_Semaphore
DetourCreate CreateSemaphoreExW, 6, 0, <xApiResult !!= NULL>, pRTCC_Semaphore
DetourCreate OpenSemaphoreA, 3, 0, <xApiResult !!= NULL>, pRTCC_Semaphore
DetourCreate OpenSemaphoreW, 3, 0, <xApiResult !!= NULL>, pRTCC_Semaphore

; ------------------------------------------------------------------------------

DetourCreate DuplicateHandle, 7, -4, <xApiResult !!= 0>, pRTCC_DuplicateHandle

; ------------------------------------------------------------------------------

DetourDestroy CloseHandle, 1, 1, <xApiResult !!= FALSE>, \
                 pRTCC_File, pRTCC_FileMapping, pRTCC_Event, \
                 pRTCC_Mutex, pRTCC_Semaphore, \
                 pRTCC_Pipe, \
                 pRTCC_Thread, pRTCC_Process, pRTCC_Job, \
                 pRTCC_DuplicateHandle

; ——————————————————————————————————————————————————————————————————————————————————————————————————

DetourCreateNamed CreateWaitableTimerA, 3, 0, <xApiResult !!= NULL>, pRTCC_Timer
DetourCreateNamed CreateWaitableTimerW, 3, 0, <xApiResult !!= NULL>, pRTCC_Timer
DetourCreateNamed CreateWaitableTimerExA, 4, 0, <xApiResult !!= NULL>, pRTCC_Timer
DetourCreateNamed CreateWaitableTimerExW, 4, 0, <xApiResult !!= NULL>, pRTCC_Timer

DefineHook SetTimer, pRTCC_Timer

DtrSetTimer proc uses xbx xdi Arg1:XWORD, Arg2:XWORD, Arg3:XWORD, Arg4:XWORD
  local xApiResult:XWORD, hThread:HANDLE
  local Context:CONTEXT, Stack:STACK

  InvokeOriginalAPI SetTimer, 4

  .if dResGuardEnabled != FALSE
    mov xApiResult, xax

    AnalyseStack
    FillStringA [xbx].$Obj(CallData).cProcName, <SetTimer>

    .if xApiResult != 0
      ;Check if we replace a Window Timer
      OCall pRTCC_Timer::RTC_Collection.Remove, Arg2, Arg1

      m2m [xbx].$Obj(CallData).xData2, Arg1, xdx        ;Store hWnd
      .if xax == FALSE                                  ;=> new Timer
        mov xcx, Arg2                                   ;uIDEvent
      .else
        mov xcx, xApiResult                             ;New Timer ID
      .endif
      m2m [xbx].$Obj(CallData).xData1, xcx              ;uIDEvent

      mov xax, pRTCC_Timer
      mov [xbx].$Obj(CallData).pOwner, xax
      OCall xax::RTC_Collection.Insert, xbx

    .else
      lea xax, FailColl
      mov [xbx].$Obj(CallData).pOwner, xax
      OCall xax::RTC_Collection.Insert, xbx
    .endif

    mov xax, xApiResult                                 ;Restore API return value
  .endif
  ret
DtrSetTimer endp

DefineHook KillTimer, pRTCC_Timer

DtrKillTimer proc uses xbx xdi Arg1:XWORD, Arg2:XWORD
  local xApiResult:XWORD, hThread:HANDLE
  local Context:CONTEXT, Stack:STACK

  InvokeOriginalAPI KillTimer, 2

  .if dResGuardEnabled != FALSE
    mov xApiResult, xax

    .if xax != 0
      OCall pRTCC_Timer::RTC_Collection.Remove, Arg2, Arg1
      test eax, eax
      jnz @@Exit                                        ;Exit if found
      invoke DbgOutText, $OfsCStr("DtrKillTimer failed removing call data"),
                         DbgColorError, DbgColorBackground, \
                         DBG_EFFECT_NORMAL or DBG_EFFECT_NEWLINE, offset wWndCaption
    .else
      AnalyseStack
      FillStringA [xbx].$Obj(CallData).cProcName, <KillTimer>
      m2m [xbx].$Obj(CallData).xData2, Arg1, xdx        ;Store hWnd
      m2m [xbx].$Obj(CallData).xData1, Arg2, xdx        ;uIDEvent

      lea xax, FailColl
      mov [xbx].$Obj(CallData).pOwner, xax
      OCall xax::RTC_Collection.Insert, xbx
    .endif
@@Exit:
    mov xax, xApiResult                                 ;Restore API return value
  .endif
  ret
DtrKillTimer endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————

DetourCreate GetDC, 1, 0, <xApiResult !!= NULL>, pRTCC_DisplayDeviceContext
DetourCreate GetDCEx, 3, 0, <xApiResult !!= NULL>, pRTCC_DisplayDeviceContext
DetourCreate GetWindowDC, 1, 0, <xApiResult !!= NULL>, pRTCC_DisplayDeviceContext
DetourDestroy ReleaseDC, 2, 2, <xApiResult !!= FALSE>, pRTCC_DisplayDeviceContext

; ——————————————————————————————————————————————————————————————————————————————————————————————————

DetourCreate GdipGetDC, 2, -2, <xApiResult !!= 0>, pRTCC_GdipDisplayDeviceContext
DetourDestroy GdipReleaseDC, 2, 2, <xApiResult !!= 0>, pRTCC_GdipDisplayDeviceContext

; ——————————————————————————————————————————————————————————————————————————————————————————————————
DetourCreate LoadKeyboardLayoutA, 2, 0, <xApiResult !!= NULL>, pRTCC_KeyboardLayout
DetourCreate LoadKeyboardLayoutW, 2, 0, <xApiResult !!= NULL>, pRTCC_KeyboardLayout
DetourDestroy UnloadKeyboardLayout, 1, 1, <xApiResult !!= FALSE>, pRTCC_KeyboardLayout

; ——————————————————————————————————————————————————————————————————————————————————————————————————

DetourCreate LoadLibraryA, 1, 0, <xApiResult !!= NULL>, pRTCC_Library
DetourCreate LoadLibraryW, 1, 0, <xApiResult !!= NULL>, pRTCC_Library
DetourCreate LoadLibraryExA, 3, 0, <xApiResult !!= NULL>, pRTCC_Library
DetourCreate LoadLibraryExW, 3, 0, <xApiResult !!= NULL>, pRTCC_Library
DetourDestroy FreeLibrary, 1, 1, <xApiResult !!= FALSE>, pRTCC_Library

; ——————————————————————————————————————————————————————————————————————————————————————————————————

DetourCreate OpenPrinterA, 3, -2, <xApiResult !!= NULL>, pRTCC_Printer
DetourCreate OpenPrinterW, 3, -2, <xApiResult !!= NULL>, pRTCC_Printer
DetourCreate OpenPrinter2A, 4, -2, <xApiResult !!= NULL>, pRTCC_Printer
DetourCreate OpenPrinter2W, 4, -2, <xApiResult !!= NULL>, pRTCC_Printer
DetourCreate AddPrinterA, 3, 0, <xApiResult !!= NULL>, pRTCC_Printer
DetourCreate AddPrinterW, 3, 0, <xApiResult !!= NULL>, pRTCC_Printer
DetourDestroy ClosePrinter, 1, 1, <xApiResult !!= FALSE>, pRTCC_Printer

; ——————————————————————————————————————————————————————————————————————————————————————————————————

DetourCreate RegCreateKeyA, 3, -3, <xApiResult == ERROR_SUCCESS>, pRTCC_RegKey
DetourCreate RegCreateKeyW, 3, -3, <xApiResult == ERROR_SUCCESS>, pRTCC_RegKey
DetourCreate RegCreateKeyExA, 9, -8, <xApiResult == ERROR_SUCCESS>, pRTCC_RegKey
DetourCreate RegCreateKeyExW, 9, -8, <xApiResult == ERROR_SUCCESS>, pRTCC_RegKey
DetourCreate RegOpenKeyA, 3, -3, <xApiResult == ERROR_SUCCESS>, pRTCC_RegKey
DetourCreate RegOpenKeyW, 3, -3, <xApiResult == ERROR_SUCCESS>, pRTCC_RegKey
DetourCreate RegOpenKeyExA, 5, -5, <xApiResult == ERROR_SUCCESS>, pRTCC_RegKey
DetourCreate RegOpenKeyExW, 5, -5, <xApiResult == ERROR_SUCCESS>, pRTCC_RegKey
DetourCreate RegOpenKeyTransactedA, 7, -5, <xApiResult == ERROR_SUCCESS>, pRTCC_RegKey
DetourCreate RegOpenKeyTransactedW, 7, -5, <xApiResult == ERROR_SUCCESS>, pRTCC_RegKey
DetourDestroy RegCloseKey, 1, 1, <xApiResult == ERROR_SUCCESS>, pRTCC_RegKey

; ——————————————————————————————————————————————————————————————————————————————————————————————————

DetourCreate BeginUpdateResourceA, 2, 0, <xApiResult !!= NULL>, pRTCC_UpdateResource
DetourCreate BeginUpdateResourceW, 2, 0, <xApiResult !!= NULL>, pRTCC_UpdateResource
DetourDestroy EndUpdateResourceA, 2, 1, <xApiResult !!= FALSE>, pRTCC_UpdateResource
DetourDestroy EndUpdateResourceW, 2, 1, <xApiResult !!= FALSE>, pRTCC_UpdateResource

; ——————————————————————————————————————————————————————————————————————————————————————————————————

DetourCreate CreateMailslotA, 4, 0, <xApiResult !!= INVALID_HANDLE_VALUE>, pRTCC_Mailslot
DetourCreate CreateMailslotW, 4, 0, <xApiResult !!= INVALID_HANDLE_VALUE>, pRTCC_Mailslot

; ——————————————————————————————————————————————————————————————————————————————————————————————————

DetourCreate FindFirstFileA, 2, 0, <xApiResult !!= INVALID_HANDLE_VALUE>, pRTCC_FindFirstFile
DetourCreate FindFirstFileW, 2, 0, <xApiResult !!= INVALID_HANDLE_VALUE>, pRTCC_FindFirstFile
DetourCreate FindFirstFileExA, 6, 0, <xApiResult !!= INVALID_HANDLE_VALUE>, pRTCC_FindFirstFile
DetourCreate FindFirstFileExW, 6, 0, <xApiResult !!= INVALID_HANDLE_VALUE>, pRTCC_FindFirstFile
DetourCreate FindFirstFileNameA, 4, 0, <xApiResult !!= INVALID_HANDLE_VALUE>, pRTCC_FindFirstFile
DetourCreate FindFirstFileNameW, 4, 0, <xApiResult !!= INVALID_HANDLE_VALUE>, pRTCC_FindFirstFile
DetourCreate FindFirstFileTransactedA, 7, 0, <xApiResult !!= INVALID_HANDLE_VALUE>, pRTCC_FindFirstFile
DetourCreate FindFirstFileTransactedW, 7, 0, <xApiResult !!= INVALID_HANDLE_VALUE>, pRTCC_FindFirstFile
DetourDestroy FindClose, 1, 1, <xApiResult !!= FALSE>, pRTCC_FindFirstFile

; ——————————————————————————————————————————————————————————————————————————————————————————————————

DetourCreate FindFirstChangeNotificationA, 3, 0, <xApiResult !!= INVALID_HANDLE_VALUE>, pRTCC_FindFirstChangeNotif
DetourCreate FindFirstChangeNotificationW, 3, 0, <xApiResult !!= INVALID_HANDLE_VALUE>, pRTCC_FindFirstChangeNotif
DetourDestroy FindCloseChangeNotification, 1, 1, <xApiResult !!= FALSE>, pRTCC_FindFirstFile

; ——————————————————————————————————————————————————————————————————————————————————————————————————

DetourCreate OpenEventLogA, 2, 0, <xApiResult !!= NULL>, pRTCC_EventLog
DetourCreate OpenEventLogW, 2, 0, <xApiResult !!= NULL>, pRTCC_EventLog
DetourDestroy CloseEventLog, 1, 1, <xApiResult !!= FALSE>, pRTCC_EventLog

; ——————————————————————————————————————————————————————————————————————————————————————————————————

DetourCreate InitializeCriticalSection, 1, 1, <>, pRTCC_CriticalSection
DetourCreate InitializeCriticalSectionAndSpinCount, 2, 1, <>, pRTCC_CriticalSection
DetourDestroy DeleteCriticalSection, 1, 1, <>, pRTCC_CriticalSection

; ——————————————————————————————————————————————————————————————————————————————————————————————————
.data
OleInitializeCount  DWORD  0

.code
DetourCreateCounted OleInitialize, 1, OleInitializeCount, <xApiResult == S_OK>, pRTCC_OleInitialization
DetourDestroyCounted OleUninitialize, 0, OleInitializeCount, <>, pRTCC_OleInitialization

; ——————————————————————————————————————————————————————————————————————————————————————————————————
.data
CoInitializeCount  DWORD  0

.code
DetourCreateCounted CoInitialize, 1, CoInitializeCount, <xApiResult == S_OK>, pRTCC_CoInitialization
DetourCreateCounted CoInitializeEx, 2, CoInitializeCount, <xApiResult == S_OK>, pRTCC_CoInitialization
DetourDestroyCounted CoUninitialize, 0, CoInitializeCount, <>, pRTCC_CoInitialization

; ==================================================================================================

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure: DllDone
; Purpose:   RegGuard finalization and freeing of allocated resorces.
;            It restores the original APIs.
; Arguments: None.
; Return:    Nothing.

DllDone proc
  m2z dResGuardEnabled
  OCall HookColl::Collection.Done                       ;Destroy all IAT_Hooks and restore IAT
  OCall RcrcColl::Collection.Done                       ;Destroy all leaked CallData objects in RTC_Collections
  OCall FailColl::RTC_Collection.Done                   ;Destroy all failed CallData objects
  OCall LogiColl::RTC_Collection.Done                   ;Destroy all failed CallData objects
  ret
DllDone endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
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
  OCall FailColl::RTC_Collection.Init, NULL, 10, 10, COL_MAX_CAPACITY
  OCall LogiColl::RTC_Collection.Init, NULL, 10, 10, COL_MAX_CAPACITY

  NewRTCC PaintStruct, 10
  NewHook BeginPaint, User32
  NewHook EndPaint, User32

  NewRTCC Pen, 10
  NewHook CreatePen, GDI32
  NewHook CreatePenIndirect, GDI32
  NewHook ExtCreatePen, GDI32

  NewRTCC Brush, 10
  NewHook CreateSolidBrush, GDI32
  NewHook CreateDIBPatternBrush, GDI32
  NewHook CreateDIBPatternBrushPt, GDI32
  NewHook CreateHatchBrush, GDI32
  NewHook CreatePatternBrush, GDI32
  NewHook CreateBrushIndirect, GDI32

  NewRTCC Bitmap, 10
  NewHook CreateBitmap, GDI32
  NewHook CreateBitmapIndirect, GDI32
  NewHook CreateCompatibleBitmap, GDI32
  NewHook CreateDIBitmap, GDI32
  NewHook CreateDIBSection, GDI32
  NewHook CreateDiscardableBitmap, GDI32
  NewHook LoadBitmapA, User32
  NewHook LoadBitmapW, User32
  NewHook GdipCreateHBITMAPFromBitmap, Gdiplus

  NewRTCC Image, 10
  NewHook LoadImageA, User32
  NewHook LoadImageW, User32
  NewHook CopyImage, User32

  NewRTCC Region, 10
  NewHook CreateEllipticRgn, GDI32
  NewHook CreateEllipticRgnIndirect, GDI32
  NewHook CreatePenDataRegion, GDI32
  NewHook CreatePolygonRgn, GDI32
  NewHook CreatePolyPolygonRgn, GDI32
  NewHook CreateRectRgn, GDI32
  NewHook CreateRectRgnIndirect, GDI32
  NewHook CreateRoundRectRgn, GDI32
  NewHook ExtCreateRegion, GDI32
  NewHook SetWindowRgn, User32

  NewRTCC Font, 10
  NewHook CreateFontA, GDI32
  NewHook CreateFontW, GDI32
  NewHook CreateFontIndirectA, GDI32
  NewHook CreateFontIndirectW, GDI32
  NewHook CreateFontIndirectExA, GDI32
  NewHook CreateFontIndirectExW, GDI32

  NewRTCC Palette, 10
  NewHook CreatePalette, GDI32
  NewHook CreateHalftonePalette, GDI32

  NewRTCC ColorSpace, 10
  NewHook CreateColorSpaceA, GDI32
  NewHook CreateColorSpaceW, GDI32

  NewHook DeleteObject, GDI32

  NewRTCC Cursor, 10
  NewHook CreateCursor, User32
  NewHook CopyCursor, User32
  NewHook LoadCursorA, User32
  NewHook LoadCursorW, User32
  NewHook LoadCursorFromFileA, User32
  NewHook LoadCursorFromFileW, User32
  NewHook SetSystemCursor, User32
  NewHook DestroyCursor, User32                 ;DestroyIcon and DestroyCursor use the same API!

  NewRTCC Icon, 10
  NewHook CopyIcon, User32
  NewHook CreateIcon, User32
  NewHook CreateIconIndirect, User32
  NewHook CreateIconFromResource, User32
  NewHook CreateIconFromResourceEx, User32
  NewHook DuplicateIcon, User32
  NewHook ExtractIconA, Shell32
  NewHook ExtractIconW, Shell32
  NewHook ExtractIconExA, Shell32
  NewHook ExtractIconExW, Shell32
  NewHook ExtractAssociatedIconA, Shell32
  NewHook ExtractAssociatedIconW, Shell32
  NewHook LoadIconA, User32
  NewHook LoadIconW, User32
  NewHook GdipCreateHICONFromBitmap, Gdiplus
  NewHook PrivateExtractIconsA, User32
  NewHook PrivateExtractIconsW, User32
  NewHook LoadIconMetric, Comctl32
  NewHook LoadIconWithScaleDown, Comctl32
  NewHook DestroyIcon, User32                   ;DestroyIcon and DestroyCursor use the same API!

  NewRTCC Menu, 10
  NewHook CreateMenu, User32
  NewHook CreatePopupMenu, User32
  NewHook LoadMenuA, User32
  NewHook LoadMenuW, User32
  NewHook LoadMenuIndirectA, User32
  NewHook LoadMenuIndirectW, User32
;  NewHook DeleteMenu, User32                    ;Destroys submenus!
  NewHook DestroyMenu, User32

  NewRTCC Timer, 10
  NewHook SetTimer, User32
  NewHook CreateWaitableTimerA, User32
  NewHook CreateWaitableTimerW, User32
  NewHook CreateWaitableTimerExA, User32
  NewHook CreateWaitableTimerExW, User32
  NewHook KillTimer, User32

  NewRTCC MetaFile, 10
  NewHook CloseMetaFile, GDI32
  NewHook CopyMetaFileA, GDI32
  NewHook CopyMetaFileW, GDI32
  NewHook CreateMetaFileA, GDI32
  NewHook CreateMetaFileW, GDI32
  NewHook GetMetaFileA, GDI32
  NewHook GetMetaFileW, GDI32
  NewHook DeleteMetaFile, GDI32

  NewRTCC EnhMetaFile, 10
  NewHook CloseEnhMetaFile, GDI32
  NewHook CopyEnhMetaFileA, GDI32
  NewHook CopyEnhMetaFileW, GDI32
  NewHook CreateEnhMetaFileA, GDI32
  NewHook CreateEnhMetaFileW, GDI32
  NewHook GetEnhMetaFileA, GDI32
  NewHook GetEnhMetaFileW, GDI32
  NewHook DeleteEnhMetaFile, GDI32

  NewRTCC DeviceContext, 10
  NewHook CreateDCA, GDI32
  NewHook CreateDCW, GDI32
  NewHook CreateCompatibleDC, GDI32
  NewHook CreateICA, GDI32
  NewHook CreateICW, GDI32
  NewHook DeleteDC, GDI32

  NewRTCC DisplayDeviceContext, 10
  NewHook GetDC, User32
  NewHook GetDCEx, User32
  NewHook GetWindowDC, User32
  NewHook ReleaseDC, User32

  NewRTCC GdipDisplayDeviceContext, 10
  NewHook GdipGetDC, Gdiplus
  NewHook GdipReleaseDC, Gdiplus

  NewRTCC StockObject, 10
  NewHook GetStockObject, User32      ;It is not necessary (but it is not harmful) to delete stock objects by calling DeleteObject.

  NewRTCC AccTable, 10
  NewHook CreateAcceleratorTableA, User32
  NewHook CreateAcceleratorTableW, User32
  NewHook CopyAcceleratorTableA, User32
  NewHook CopyAcceleratorTableW, User32
  NewHook LoadAcceleratorsA, User32
  NewHook LoadAcceleratorsW, User32
  NewHook DestroyAcceleratorTable, User32

  NewRTCC KeyboardLayout, 10
  NewHook LoadKeyboardLayoutA, User32
  NewHook LoadKeyboardLayoutW, User32
  NewHook UnloadKeyboardLayout, User32

  NewRTCC Desktop, 10
  NewHook CreateDesktopA, User32
  NewHook CreateDesktopW, User32
  NewHook CreateDesktopExA, User32
  NewHook CreateDesktopExW, User32
  NewHook CloseDesktop, User32

  NewRTCC Library, 10
  NewHook LoadLibraryA, Kernel32
  NewHook LoadLibraryW, Kernel32
  NewHook LoadLibraryExA, Kernel32
  NewHook LoadLibraryExW, Kernel32
  NewHook FreeLibrary, Kernel32

  NewRTCC WindowStation, 10
  NewHook CreateWindowStationA, User32
  NewHook CreateWindowStationW, User32
  NewHook OpenWindowStationA, User32
  NewHook OpenWindowStationW, User32
  NewHook CloseWindowStation, User32

  NewRTCC File, 10
  NewHook CreateFileA, Kernel32
  NewHook CreateFileW, Kernel32
  NewHook CreateFileTransactedA, Kernel32
  NewHook CreateFileTransactedW, Kernel32

  NewRTCC Event, 10
  NewHook CreateEventA, Kernel32
  NewHook CreateEventW, Kernel32
  NewHook CreateEventExA, Kernel32
  NewHook CreateEventExW, Kernel32
  NewHook OpenEventA, Kernel32
  NewHook OpenEventW, Kernel32

  NewRTCC FileMapping, 10
  NewHook CreateFileMappingA, Kernel32
  NewHook CreateFileMappingW, Kernel32
  NewHook CreateFileMappingNumaA, Kernel32
  NewHook CreateFileMappingNumaW, Kernel32

  NewRTCC Mutex, 10
  NewHook CreateMutexA, Kernel32
  NewHook CreateMutexW, Kernel32
  NewHook OpenMutexA, Kernel32
  NewHook OpenMutexW, Kernel32

  NewRTCC Pipe, 10
  NewHook CreatePipe, Kernel32
  NewHook CreateNamedPipeA, Kernel32
  NewHook CreateNamedPipeW, Kernel32

  NewRTCC Process, 10
  NewHook CreateProcessA, Kernel32
  NewHook CreateProcessW, Kernel32
  NewHook CreateProcessAsUserA, Kernel32
  NewHook CreateProcessAsUserW, Kernel32
  NewHook CreateProcessWithLogonA, Kernel32
  NewHook CreateProcessWithLogonW, Kernel32
  NewHook OpenProcess, Kernel32

  NewRTCC Thread, 10
  NewHook CreateThread, Kernel32
  NewHook CreateRemoteThread, Kernel32

  NewRTCC Semaphore, 10
  NewHook CreateSemaphoreA, Kernel32
  NewHook CreateSemaphoreW, Kernel32
  NewHook CreateSemaphoreExA, Kernel32
  NewHook CreateSemaphoreExW, Kernel32
  NewHook OpenSemaphoreA, Kernel32
  NewHook OpenSemaphoreW, Kernel32

  NewHook CloseHandle, Kernel32

  NewRTCC Printer, 10
  NewHook OpenPrinterA, WinSpool
  NewHook OpenPrinterW, WinSpool
  NewHook OpenPrinter2A, WinSpool
  NewHook OpenPrinter2W, WinSpool
  NewHook AddPrinterA, WinSpool
  NewHook AddPrinterW, WinSpool
  NewHook ClosePrinter, WinSpool

  NewRTCC RegKey, 10
  NewHook RegCreateKeyA, AdvApi32
  NewHook RegCreateKeyW, AdvApi32
  NewHook RegCreateKeyExA, AdvApi32
  NewHook RegCreateKeyExW, AdvApi32
  NewHook RegOpenKeyA, AdvApi32
  NewHook RegOpenKeyW, AdvApi32
  NewHook RegOpenKeyExA, AdvApi32
  NewHook RegOpenKeyExW, AdvApi32
  NewHook RegOpenKeyTransactedA, AdvApi32
  NewHook RegOpenKeyTransactedW, AdvApi32
  NewHook RegCloseKey, AdvApi32

  NewRTCC UpdateResource, 10
  NewHook BeginUpdateResourceA, Kernel32
  NewHook BeginUpdateResourceW, Kernel32
  NewHook EndUpdateResourceA, Kernel32
  NewHook EndUpdateResourceW, Kernel32

  NewRTCC Mailslot, 10
  NewHook CreateMailslotA, Kernel32
  NewHook CreateMailslotW, Kernel32

  NewRTCC FindFirstFile, 10
  NewHook FindFirstFileA, Kernel32
  NewHook FindFirstFileW, Kernel32
  NewHook FindFirstFileExA, Kernel32
  NewHook FindFirstFileExW, Kernel32
  NewHook FindFirstFileNameA, Kernel32
  NewHook FindFirstFileNameW, Kernel32
  NewHook FindFirstFileTransactedA, Kernel32
  NewHook FindFirstFileTransactedW, Kernel32
  NewHook FindClose, Kernel32

  NewRTCC FindFirstChangeNotif, 10
  NewHook FindFirstChangeNotificationA, Kernel32
  NewHook FindFirstChangeNotificationW, Kernel32
  NewHook FindCloseChangeNotification, Kernel32

  NewRTCC EventLog, 10
  NewHook OpenEventLogA, Kernel32
  NewHook OpenEventLogW, Kernel32
  NewHook CloseEventLog, Kernel32

  NewRTCC CriticalSection, 10
  NewHook InitializeCriticalSection, Kernel32
  NewHook InitializeCriticalSectionAndSpinCount, Kernel32
  NewHook DeleteCriticalSection, Kernel32

  NewRTCC OleInitialization, 10
  NewHook OleInitialize, Ole32
  NewHook OleUninitialize, Ole32

  NewRTCC CoInitialization, 10
  NewHook CoInitialize, Ole32
  NewHook CoInitializeEx, Ole32
  NewHook CoUninitialize, Ole32

  NewRTCC SysString, 10
  NewHook SysAllocString, OleAuto
  NewHook SysAllocStringLen, OleAuto
  NewHook SysAllocStringByteLen, OleAuto
  NewHook SysReAllocString, OleAuto
  NewHook SysReAllocStringLen, OleAuto
  NewHook SysFreeString, OleAuto

  NewRTCC CoTaskMemBlock, 100
  NewHook CoTaskMemAlloc, Ole32
  NewHook CoTaskMemRealloc, Ole32
  NewHook CoTaskMemFree, Ole32

  NewRTCC VirtualMemBlock, 100
  NewHook VirtualAlloc, Kernel32
  NewHook VirtualFree, Kernel32

  NewRTCC LocalMemBlock, 100
  NewHook LocalAlloc, Kernel32
  NewHook LocalFree, Kernel32
  NewHook LocalReAlloc, Kernel32

  NewRTCC GlobalMemBlock, 100
  NewHook GlobalAlloc, Kernel32
  NewHook GlobalFree, Kernel32
  NewHook GlobalReAlloc, Kernel32

  NewRTCC HeapMemBlock, 100
  NewHook HeapAlloc, Kernel32
  NewHook HeapFree, Kernel32
  NewHook HeapReAlloc, Kernel32

  NewRTCC PrivateNamespace, 2
  NewHook CreatePrivateNamespaceA, Kernel32
  NewHook CreatePrivateNamespaceW, Kernel32

  NewRTCC Job, 2
  NewHook CreateJobObjectA, Kernel32
  NewHook CreateJobObjectW, Kernel32

  NewRTCC Transaction, 2
  NewHook CreateTransactionA, KtmW32
  NewHook CreateTransactionW, KtmW32

  NewRTCC DuplicateHandle, 2
  NewHook DuplicateHandle, Kernel32
  ;https://learn.microsoft.com/en-us/windows/win32/sync/object-names

  ret
DllInit endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure: ResGuardInit (exported)
; Purpose:   Initialize monitoring and remembers where to stop the stack tracing.
; Arguments: None.
; Return:    Nothing.

ResGuardInit proc
  if TARGET_BITNESS eq 32
    mov xAppRefAddr, ebp
  else
    mov xAppRefAddr, rsp
    add xAppRefAddr, 2*sizeof(POINTER)                 ;Discard ret addr and frame
  endif
  ret
ResGuardInit endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure: ResGuardShow (exported)
; Purpose:   Visualisation of resource usage.
; Arguments: Arg1: -> RTC_Collection.
;            Arg2: Resource type caption.
;            xbx -> Output ANSI buffer.
; Return:    Nothing.

ShowCollectionData macro pRTC_Collection:req, ResTypeCaption:req
  local szLeakCaption

  CStr szLeakCaption, ResTypeCaption, ": current = %li, maximum = %li, total = %li"
  mov xdi, pRTC_Collection
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
    ShowCollectionData pRTCC_VirtualMemBlock,         "Virtual Mem-Blocks"
    ShowCollectionData pRTCC_GlobalMemBlock,          "Global Mem-Blocks"
    ShowCollectionData pRTCC_LocalMemBlock,           "Local Mem-Blocks"
    ShowCollectionData pRTCC_HeapMemBlock,            "Heap Mem-Blocks"
    ShowCollectionData pRTCC_CoTaskMemBlock,          "CoTaskMem-Blocks"

    ShowCollectionData pRTCC_AccTable,                "Accelerator Tables"
    ShowCollectionData pRTCC_Bitmap,                  "Bitmaps"
    ShowCollectionData pRTCC_Brush,                   "Brushes"
    ShowCollectionData pRTCC_FindFirstChangeNotif,    "FindFirst Change Notification"
    ShowCollectionData pRTCC_ColorSpace,              "Color Spaces"
    ShowCollectionData pRTCC_CriticalSection,         "Critical Sections"
    ShowCollectionData pRTCC_Cursor,                  "Cursors"
    ShowCollectionData pRTCC_Desktop,                 "Desktops"
    ShowCollectionData pRTCC_DeviceContext,           "Device Contexts"
    ShowCollectionData pRTCC_DisplayDeviceContext,    "Display DCs"
    ShowCollectionData pRTCC_GdipDisplayDeviceContext,"GDI+ Display DCs"
    ShowCollectionData pRTCC_EnhMetaFile,             "EnhMetaFiles"
    ShowCollectionData pRTCC_Event,                   "Events"
    ShowCollectionData pRTCC_EventLog,                "Event Logs"
    ShowCollectionData pRTCC_File,                    "Files"
    ShowCollectionData pRTCC_FileMapping,             "File Mappings"
    ShowCollectionData pRTCC_UpdateResource,          "File Resources"
    ShowCollectionData pRTCC_FindFirstFile,           "Find First File"
    ShowCollectionData pRTCC_Font,                    "Fonts"
    ShowCollectionData pRTCC_Icon,                    "Icons"
    ShowCollectionData pRTCC_Image,                   "Images"
    ShowCollectionData pRTCC_KeyboardLayout,          "Keyboard Layouts"
    ShowCollectionData pRTCC_Library,                 "Libraries"
    ShowCollectionData pRTCC_Mailslot,                "Mail Slots"
    ShowCollectionData pRTCC_Menu,                    "Menus"
    ShowCollectionData pRTCC_MetaFile,                "MetaFiles"
    ShowCollectionData pRTCC_Mutex,                   "Mutexes"
    ShowCollectionData pRTCC_Palette,                 "Palettes"
    ShowCollectionData pRTCC_PaintStruct,             "Paint Structures"
    ShowCollectionData pRTCC_Pen,                     "Pens"
    ShowCollectionData pRTCC_Printer,                 "Printers"
    ShowCollectionData pRTCC_PrivateNamespace,        "Private Namespaces"
    ShowCollectionData pRTCC_Process,                 "Processes"
    ShowCollectionData pRTCC_Region,                  "Regions"
    ShowCollectionData pRTCC_RegKey,                  "Registry Keys"
    ShowCollectionData pRTCC_Semaphore,               "Semaphores"
    ShowCollectionData pRTCC_SysString,               "System BStrings"
    ShowCollectionData pRTCC_Thread,                  "Threads"
    ShowCollectionData pRTCC_Timer,                   "Timers"
    ShowCollectionData pRTCC_Transaction,             "Transactions"
    ShowCollectionData pRTCC_WindowStation,           "Window Stations"

    ShowCollectionData pRTCC_OleInitialization,       "OLE library initialization"
    ShowCollectionData pRTCC_CoInitialization,        "COM library initialization"
    ; -----------------------------------------------------------------------------------
  .endif

  lea xdi, FailColl
  m2m dFails, [xdi].$Obj(RTC_Collection).dCount, eax
  .if (eax != 0)
    invoke wsprintf, xbx, $OfsCStr("Failed Calls:   %li"), dFails
    invoke DbgOutText, xbx, DbgColorForeground, DbgColorBackground, \
                       DBG_EFFECT_NORMAL or DBG_EFFECT_NEWLINE, offset wWndCaption
    OCall xdi::RTC_Collection.Aggregate
    OCall xdi::RTC_Collection.ForEach, $MethodAddr(CallData.Show), NULL, NULL
    OCall xdi::RTC_Collection.Deaggregate
  .endif

  lea xdi, LogiColl
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

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure: ResGuardStart (exported)
; Purpose:   Begins resource monitoring.
; Arguments: None.
; Return:    Nothing.

ResGuardStart proc
  mov dResGuardEnabled, TRUE
  ret
ResGuardStart endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure: ResGuardStop (exported)
; Purpose:   End resource monitoring.
; Arguments: None.
; Return:    Nothing.

ResGuardStop proc
  m2z dResGuardEnabled
  ret
ResGuardStop endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure: start (exported)
; Purpose:   Entry procedure in the DLL (DllMain).
; Arguments: Arg1: Instance handle.
;            Arg2: Call reason.
;            Arg3: Reserved.
; Return:    TRUE if handled.

start proc public hDllInstance:HANDLE, dReason:DWORD, xReserved:XWORD
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

end
