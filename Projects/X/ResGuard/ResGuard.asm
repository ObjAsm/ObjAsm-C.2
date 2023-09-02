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


_IMAGEHLP_SOURCE_ equ 0
SYM_NAME_LENGTH   equ 255
CALLER_MAX_DEEP   equ 10

% include @Environ(OBJASM_PATH)\Code\Macros\Model.inc
SysSetup OOP, DLL32, WIDE_STRING, DEBUG(WND), SUFFIX

% includelib &LibPath&Windows\DbgHelp.lib

% include &IncPath&Windows\DbgHelp.inc

CStrW wCaption,    "ResGuard"
CStrW wDebugStart, "Use the debugger to find the lines of", CRLF, \
                   "code that use the listed resources.", CRLF, CRLF,\
                   "Do you want to start the debugger now?", CRLF

HookCount = 0

MakeObjects Primer, Stream, Collection, IAT_Hook

if TARGET_BITNESS eq 32
  STACK textequ <STACKFRAME>

  SYMBOL struct
    IMAGEHLP_SYMBOL   {}
    CHRA              SYM_NAME_LENGTH dup(?)
  SYMBOL ends

  SymGetSymFromAddrX textequ <SymGetSymFromAddr>
else
  STACK textequ <STACKFRAME64>

  SYMBOL struct
    IMAGEHLP_SYMBOL64 {}
    CHRA              SYM_NAME_LENGTH dup(?)
  SYMBOL ends

  SymGetSymFromAddrX textequ <SymGetSymFromAddr64>
endif

CALLER_INFO struct
  xRetAddr    XWORD   ?
  xInstrAddr  XWORD   ?
CALLER_INFO ends

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Object:     CallData
; Purpose:    Store all relevant info about a specific API call, like the call stack and an system
;             identification like a HANDLE, ID, etc.

Object CallData,, Primer
  VirtualMethod   Show,       XWORD, XWORD              ;Callback method

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
  RedefineMethod  Insert,     $ObjPtr(CallData)
  VirtualMethod   Remove,     XWORD, XWORD

  DefineVariable  dMaxCount,  DWORD,    0               ;Maximal count to check the system load
  DefineVariable  dTotCount,  DWORD,    0               ;Cummulated number of calls
ObjectEnd

.data                                                   ;Non exported data
  hProcess          HANDLE    0
  xAppRefAddr       XWORD     0
  dResGuardEnabled  DWORD     FALSE
  HookColl          $ObjInst(Collection)                ;Collection of IAT_Hook objects
  RcrcColl          $ObjInst(Collection)                ;Collection of RTC_Collection objects
  FailColl          $ObjInst(RTC_Collection)            ;Collection of failed API calls; it acts
                                                        ;  like a RTC_Collection
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
  invoke DbgOutTextW, $OfsCStrW(" ", 2022h, " "), DbgColorString, DbgColorBackground, \
                     DBG_EFFECT_NORMAL, offset wCaption
  invoke DbgOutTextA, addr [xsi].$Obj(CallData).cProcName, DbgColorString, DbgColorBackground, \
                      DBG_EFFECT_NORMAL, offset wCaption
  xor ebx, ebx
  lea xdi, [xsi].CallStack                              ;xdi -> CallData.CallStack
  .while ebx != [xsi].$Obj(CallData).dCount
    invoke DbgOutTextW, $OfsCStrW(" ", 2190h, " "), DbgColorWarning, DbgColorBackground, \  ;Arrow
                        DBG_EFFECT_NORMAL, offset wCaption
    mov Symbol.MaxNameLength, SYM_NAME_LENGTH
    mov Symbol.SizeOfStruct, sizeof SYMBOL
    invoke SymGetSymFromAddrX, hProcess, [xdi].CALLER_INFO.xInstrAddr,
                               addr xDisplacement, addr Symbol
    .if eax != FALSE
      invoke UnDecorateSymbolName, addr Symbol.Name_, addr cBuffer, SYM_NAME_LENGTH, UNDNAME_COMPLETE
      .if eax != FALSE
        invoke DbgOutTextA, addr cBuffer, DbgColorWarning, DbgColorBackground, \
                            DBG_EFFECT_NORMAL, offset wCaption
      .endif
    .endif
    FillStringA cBuffer, <(>
    lea xcx, [cBuffer + 1]
    invoke xword2hexA, xcx, [xdi].CALLER_INFO.xRetAddr
    invoke StrCatA, addr cBuffer, $OfsCStrA("h)")
    invoke DbgOutTextA, addr cBuffer, DbgColorComment, DbgColorBackground, \
                        DBG_EFFECT_NORMAL, offset wCaption
    add xdi, sizeof CALLER_INFO
    inc ebx
  .endw

  .if ebx == 0
    invoke DbgOutText, $OfsCStr("No data"), DbgColorError, DbgColorBackground, \
                       DBG_EFFECT_NORMAL or DBG_EFFECT_NEWLINE, offset wCaption
  .else
    invoke DbgOutText, offset cCRLF, DbgColorForeground, DbgColorBackground, \
                       DBG_EFFECT_NORMAL, offset wCaption
  .endif
MethodEnd


; ==================================================================================================
;    RTC_Collection implementation
; ==================================================================================================

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
; Purpose:    StackWalk(64) bitness neutral substitute.
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

  invoke RtlCaptureContext, addr Context
  mov Stack.AddrPC.Mode,     AddrModeFlat
  mov Stack.AddrFrame.Mode,  AddrModeFlat
  mov Stack.AddrStack.Mode,  AddrModeFlat
  mov Stack.AddrReturn.Mode, AddrModeFlat

  lea xdi, [xbx].$Obj(CallData).CallStack               ;;xdi -> CallData.CallStack

  if TARGET_BITNESS eq 32
    mov edx, [ebp + sizeof DWORD]                       ;;Get Ret addr from stack
    mov [edi].CALLER_INFO.xRetAddr, edx
    m2m [edi].CALLER_INFO.xInstrAddr, Context.Eip_, ecx
    add edi, sizeof CALLER_INFO
    inc [ebx].$Obj(CallData).dCount
    WalkTheStack                                        ;;Get first frame of the detour proc
    .if eax != 0
      .repeat
        mov edx, Stack.AddrReturn.Offset_
        mov [edi].CALLER_INFO.xRetAddr, edx
        WalkTheStack
        .break .if eax == 0
        mov edx, Stack.AddrPC.Offset_
        mov [edi].CALLER_INFO.xInstrAddr, edx
        inc [ebx].$Obj(CallData).dCount
        add edi, sizeof CALLER_INFO
        mov eax, Stack.AddrFrame.Offset_                ;;Use the stack pointer
      .until eax == xAppRefAddr || [ebx].$Obj(CallData).dCount == CALLER_MAX_DEEP
    .endif
  else
    WalkTheStack                                        ;;Get first frame of the detour proc
    .if eax != 0
      .repeat
        mov rdx, Stack.AddrReturn.Offset_
        mov [rdi].CALLER_INFO.xRetAddr, rdx
        WalkTheStack
        .break .if eax == 0
        mov rdx, Stack.AddrPC.Offset_
        mov [rdi].CALLER_INFO.xInstrAddr, rdx
        inc [rbx].$Obj(CallData).dCount
        add rdi, sizeof CALLER_INFO
        mov rax, Stack.AddrStack.Offset_                ;;Use the stack pointer
      .until rax == xAppRefAddr || [rbx].$Obj(CallData).dCount == CALLER_MAX_DEEP
    .endif
  endif
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      DetourStdCreate
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

DetourStdCreate macro ApiName:req, ArgCount:req, CallIdentifier:req, SuccessCond:req,
                      pRTC_Coll:req, RemoveArgIndex, PassCond
  local ArgStr, Cnt

  HookCount = HookCount + 1                             ;;Keep track of the hook count
  externdef pRTC_Coll:$ObjPtr(RTC_Collection)           ;;The RTC_Collection will be definend later
  .data
  pHook&ApiName&   $ObjPtr(IAT_Hook)   NULL

  ArgStr textequ <>                                     ;;Prepare argument list
  Cnt = 0
  repeat ArgCount
    Cnt = Cnt + 1
    ArgStr CatStr ArgStr, <, >, <Arg>, %Cnt, <:XWORD>
  endm

  .code
  Dtr&ApiName& proc uses xbx xdi ArgStr                 ;;Procedure declaration
    local xApiResult:XWORD, hThread:HANDLE
    local Context:CONTEXT, Stack:STACK

    InvokeOriginalAPI ApiName, ArgCount

    .if dResGuardEnabled != FALSE
      mov xApiResult, xax
      m2z dResGuardEnabled                              ;;Shut Resguard off while analysis is in progress

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

      .if xApiResult SuccessCond
        ifb <PassCond>
          ifnb <RemoveArgIndex>
            @CatStr(<OCall >, pRTC_Coll, <::RTC_Collection.Remove, Arg>, RemoveArgIndex, <, 0>)
          endif
          OCall pRTC_Coll::Collection.Insert, xbx
          mov xax, pRTC_Coll
          mov [xbx].$Obj(CallData).pOwner, xax
        else
          Destroy xbx
        endif
      .else
        lea xax, FailColl
        mov [xbx].$Obj(CallData).pOwner, xax
        OCall xax::Collection.Insert, xbx
      .endif

      mov dResGuardEnabled, TRUE
      mov xax, xApiResult                               ;;Restore API return value
    .endif
    ret
  Dtr&ApiName& endp
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      DetourStdDestroy
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

DetourStdDestroy macro ApiName:req, ArgCount:req, CallIdentifier:req, SuccessCond:req,
                       pRTC_Coll_List:vararg
  local ArgStr, Cnt, Coll, @@Exit

  HookCount = HookCount + 1                             ;;Keep track of the hook count
  .data
  pHook&ApiName&   $ObjPtr(IAT_Hook)   NULL

  ArgStr textequ <>
  Cnt = 0
  repeat ArgCount
    Cnt = Cnt + 1
    ArgStr CatStr ArgStr, <, >, <Arg>, %Cnt, <:XWORD>
  endm

  .code
  Dtr&ApiName& proc uses xbx xdi ArgStr                 ;;Procedure declaration
    local xApiResult:XWORD, hThread:HANDLE
    local Context:CONTEXT, Stack:STACK

    InvokeOriginalAPI ApiName, ArgCount

    .if dResGuardEnabled != FALSE
      mov xApiResult, xax
      m2z dResGuardEnabled                              ;;Shut Resguard off while analysis is in progress

      ifnb <SuccessCond>
        .if xax SuccessCond
          for pColl, <pRTC_Coll_List>                   ;;Search in all specified RTC_Collection objects
            @CatStr(<OCall >, pColl, <::RTC_Collection.Remove, Arg>, CallIdentifier, <, 0>)
            test eax, eax
            jnz @@Exit                                  ;;Exit if found
          endm
          invoke DbgOutText, $OfsCStr("Dtr&ApiName& failed to remove call data"),
                             DbgColorError, DbgColorBackground, \
                             DBG_EFFECT_NORMAL or DBG_EFFECT_NEWLINE, offset wCaption
          jmp @@Exit
        .endif
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

        lea xax, FailColl
        mov [xbx].$Obj(CallData).pOwner, xax
        OCall xax::RTC_Collection.Insert, xbx
      else
        for pColl, <pRTC_Coll_List>                     ;;Search in all specified RTC_Collection objects
          @CatStr(<OCall >, pColl, <::RTC_Collection.Remove, Arg>, CallIdentifier, <, 0>)
          test eax, eax
          jnz @@Exit                                    ;;Exit if found
        endm
        invoke DbgOutText, $OfsCStr("Dtr&ApiName& failed to remove call data"),
                           DbgColorError, DbgColorBackground, \
                           DBG_EFFECT_NORMAL or DBG_EFFECT_NEWLINE, offset wCaption
      endif
@@Exit:
      mov dResGuardEnabled, TRUE
      mov xax, xApiResult                               ;;Restore API return value
    .endif
    ret
  Dtr&ApiName& endp
endm

; ==================================================================================================

DetourStdCreate HeapAlloc, 3, 0, <!!= NULL>, pRTCC_HeapMemBlock
DetourStdCreate HeapReAlloc, 4, 0, <!!= NULL>, pRTCC_HeapMemBlock, 3
DetourStdDestroy HeapFree, 3, 3, <!!= FALSE>, pRTCC_HeapMemBlock

; ——————————————————————————————————————————————————————————————————————————————————————————————————

DetourStdCreate GlobalAlloc, 2, 0, <!!= NULL>, pRTCC_GlobalMemBlock
DetourStdCreate GlobalReAlloc, 3, 0, <!!= NULL>, pRTCC_GlobalMemBlock, 1
DetourStdDestroy GlobalFree, 1, 1, <== NULL>, pRTCC_GlobalMemBlock

; ——————————————————————————————————————————————————————————————————————————————————————————————————

DetourStdCreate LocalAlloc, 2, 0, <!!= NULL>, pRTCC_LocalMemBlock
DetourStdCreate LocalReAlloc, 3, 0, <!!= NULL>, pRTCC_LocalMemBlock, 1
DetourStdDestroy LocalFree, 1, 1, <== NULL>, pRTCC_LocalMemBlock

; ——————————————————————————————————————————————————————————————————————————————————————————————————

DetourStdCreate CoTaskMemAlloc, 1, 0, <!!= NULL>, pRTCC_CoTaskMemBlock
DetourStdCreate CoTaskMemRealloc, 1, 0, <!!= NULL>, pRTCC_CoTaskMemBlock, 1
DetourStdDestroy CoTaskMemFree, 1, 1, <>, pRTCC_CoTaskMemBlock

; ——————————————————————————————————————————————————————————————————————————————————————————————————

DetourStdCreate VirtualAlloc, 4, 0, <!!= NULL>, pRTCC_VirtualMemBlock
DetourStdDestroy VirtualFree, 3, 1, <!!= FALSE>, pRTCC_VirtualMemBlock

; ——————————————————————————————————————————————————————————————————————————————————————————————————

DetourStdCreate SysAllocString, 1, 0, <!!= NULL>, pRTCC_SysString
DetourStdCreate SysAllocStringLen, 2, 0, <!!= NULL>, pRTCC_SysString
DetourStdCreate SysAllocStringByteLen, 2, 0, <!!= NULL>, pRTCC_SysString
DetourStdCreate SysReAllocString, 2, 0, <!!= FALSE>, pRTCC_SysString
DetourStdCreate SysReAllocStringLen, 3, 0, <!!= FALSE>, pRTCC_SysString
DetourStdDestroy SysFreeString, 1, 1, <!!= FALSE>, pRTCC_SysString

; ——————————————————————————————————————————————————————————————————————————————————————————————————

DetourStdCreate BeginPaint, 2, 2, <!!= NULL>, pRTCC_PaintStruct
DetourStdDestroy EndPaint, 2, 2, <!!= FALSE>, pRTCC_PaintStruct

; ——————————————————————————————————————————————————————————————————————————————————————————————————

DetourStdCreate CreatePen, 3, 0, <!!= NULL>, pRTCC_Pen
DetourStdCreate CreatePenIndirect, 1, 0, <!!= NULL>, pRTCC_Pen

; ------------------------------------------------------------------------------

DetourStdCreate CreateSolidBrush, 1, 0, <!!= NULL>, pRTCC_Brush
DetourStdCreate CreateDIBPatternBrush, 2, 0, <!!= NULL>, pRTCC_Brush
DetourStdCreate CreateDIBPatternBrushPt, 2, 0, <!!= NULL>, pRTCC_Brush
DetourStdCreate CreateHatchBrush, 2, 0, <!!= NULL>, pRTCC_Brush
DetourStdCreate CreatePatternBrush, 1, 0, <!!= NULL>, pRTCC_Brush
DetourStdCreate CreateBrushIndirect, 1, 0, <!!= NULL>, pRTCC_Brush

; ------------------------------------------------------------------------------

DetourStdCreate CreateBitmap, 5, 0, <!!= NULL>, pRTCC_Bitmap
DetourStdCreate CreateBitmapIndirect, 1, 0, <!!= NULL>, pRTCC_Bitmap
DetourStdCreate CreateCompatibleBitmap, 3, 0, <!!= NULL>, pRTCC_Bitmap
DetourStdCreate CreateDIBitmap, 6, 0, <!!= NULL>, pRTCC_Bitmap
DetourStdCreate CreateDIBSection, 6, 0, <!!= NULL>, pRTCC_Bitmap
DetourStdCreate CreateDiscardableBitmap, 3, 0, <!!= NULL>, pRTCC_Bitmap
DetourStdCreate LoadBitmapA, 2, 0, <!!= NULL>, pRTCC_Bitmap
DetourStdCreate LoadBitmapW, 2, 0, <!!= NULL>, pRTCC_Bitmap

; ------------------------------------------------------------------------------

DetourStdCreate CreateEllipticRgn, 4, 0, <!!= NULL>, pRTCC_Region
DetourStdCreate CreateEllipticRgnIndirect, 1, 0, <!!= NULL>, pRTCC_Region
DetourStdCreate CreatePenDataRegion, 2, 0, <!!= NULL>, pRTCC_Region
DetourStdCreate CreatePolygonRgn, 3, 0, <!!= NULL>, pRTCC_Region
DetourStdCreate CreatePolyPolygonRgn, 4, 0, <!!= NULL>, pRTCC_Region
DetourStdCreate CreateRectRgn, 4, 0, <!!= NULL>, pRTCC_Region
DetourStdCreate CreateRectRgnIndirect, 1, 0, <!!= NULL>, pRTCC_Region
DetourStdCreate CreateRoundRectRgn, 6, 0, <!!= NULL>, pRTCC_Region
DetourStdDestroy SetWindowRgn, 3, 2, <!!= FALSE>, pRTCC_Region  ;This region is destroyed by the window!

; ------------------------------------------------------------------------------

DetourStdCreate CopyImage, 5, 0, <!!= NULL>, pRTCC_Image
DetourStdCreate LoadImageA, 6, 0, <!!= NULL>, pRTCC_Image
DetourStdCreate LoadImageW, 6, 0, <!!= NULL>, pRTCC_Image

; ------------------------------------------------------------------------------

DetourStdCreate CreateFontA, 14, 0, <!!= NULL>, pRTCC_Font
DetourStdCreate CreateFontW, 14, 0, <!!= NULL>, pRTCC_Font
DetourStdCreate CreateFontIndirectA, 1, 0, <!!= NULL>, pRTCC_Font
DetourStdCreate CreateFontIndirectW, 1, 0, <!!= NULL>, pRTCC_Font

; ------------------------------------------------------------------------------

DetourStdCreate CreatePalette, 1, 0, <!!= NULL>, pRTCC_Palette
DetourStdCreate CreateHalftonePalette, 1, 0, <!!= NULL>, pRTCC_Palette

; ------------------------------------------------------------------------------

DetourStdCreate CreateColorSpaceA, 1, 0, <!!= NULL>, pRTCC_ColorSpace
DetourStdCreate CreateColorSpaceW, 1, 0, <!!= NULL>, pRTCC_ColorSpace

; ------------------------------------------------------------------------------

DetourStdDestroy DeleteObject, 1, 1, <!!= FALSE>, pRTCC_Pen, pRTCC_Brush, pRTCC_Bitmap, \
                                                pRTCC_Region, pRTCC_Font, pRTCC_Palette, \
                                                pRTCC_ColorSpace, pRTCC_Image

; ——————————————————————————————————————————————————————————————————————————————————————————————————

DetourStdCreate CreateCursor, 7, 0, <!!= NULL>, pRTCC_Cursor
DetourStdCreate LoadCursorA, 2, 0, <!!= NULL>, pRTCC_Cursor,, <Arg1 != NULL>
DetourStdCreate LoadCursorW, 2, 0, <!!= NULL>, pRTCC_Cursor,, <Arg1 != NULL>

DetourStdCreate LoadCursorFromFileA, 1, 0, <!!= NULL>, pRTCC_Cursor
DetourStdCreate LoadCursorFromFileW, 1, 0, <!!= NULL>, pRTCC_Cursor

externdef pRTCC_Icon:$ObjPtr(RTC_Collection)
;DestroyCursor and DestroyIcon use the same API
DetourStdDestroy DestroyCursor, 1, 1, <!!= FALSE>, pRTCC_Cursor, pRTCC_Icon, pRTCC_Image

; ——————————————————————————————————————————————————————————————————————————————————————————————————

DetourStdCreate CreateIcon, 7, 0, <!!= NULL>, pRTCC_Icon
DetourStdCreate CreateIconIndirect, 1, 0, <!!= NULL>, pRTCC_Icon
DetourStdCreate CreateIconFromResource, 4, 0, <!!= NULL>, pRTCC_Icon
DetourStdCreate CreateIconFromResourceEx, 7, 0, <!!= NULL>, pRTCC_Icon
DetourStdCreate LoadIconA, 2, 0, <!!= NULL>, pRTCC_Icon
DetourStdCreate LoadIconW, 2, 0, <!!= NULL>, pRTCC_Icon
DetourStdCreate ExtractAssociatedIconA, 3, 0, <!!= NULL>, pRTCC_Icon
DetourStdCreate ExtractAssociatedIconW, 3, 0, <!!= NULL>, pRTCC_Icon
;DestroyCursor and DestroyIcon use the same API
DetourStdDestroy DestroyIcon, 1, 1, <!!= FALSE>, pRTCC_Icon, pRTCC_Cursor, pRTCC_Image

; ——————————————————————————————————————————————————————————————————————————————————————————————————

DetourStdCreate CreateMenu, 0, 0, <!!= NULL>, pRTCC_Menu
DetourStdCreate CreatePopupMenu, 0, 0, <!!= NULL>, pRTCC_Menu
DetourStdCreate LoadMenuA, 2, 0, <!!= NULL>, pRTCC_Menu
DetourStdCreate LoadMenuW, 2, 0, <!!= NULL>, pRTCC_Menu
DetourStdCreate LoadMenuIndirectA, 1, 0, <!!= NULL>, pRTCC_Menu
DetourStdCreate LoadMenuIndirectW, 1, 0, <!!= NULL>, pRTCC_Menu
DetourStdDestroy DestroyMenu, 1, 1, <!!= FALSE>, pRTCC_Menu

; ——————————————————————————————————————————————————————————————————————————————————————————————————

DetourStdCreate CreateMetaFileA, 1, 0, <!!= NULL>, pRTCC_MetaFile
DetourStdCreate CreateMetaFileW, 1, 0, <!!= NULL>, pRTCC_MetaFile
DetourStdCreate GetMetaFileA, 1, 0, <!!= NULL>, pRTCC_MetaFile
DetourStdCreate GetMetaFileW, 1, 0, <!!= NULL>, pRTCC_MetaFile
DetourStdDestroy DeleteMetaFile, 1, 1, <!!= FALSE>, pRTCC_MetaFile

; ——————————————————————————————————————————————————————————————————————————————————————————————————

DetourStdCreate CreateEnhMetaFileA, 1, 0, <!!= NULL>, pRTCC_EnhMetaFile
DetourStdCreate CreateEnhMetaFileW, 1, 0, <!!= NULL>, pRTCC_EnhMetaFile
DetourStdCreate GetEnhMetaFileA, 1, 0, <!!= NULL>, pRTCC_EnhMetaFile
DetourStdCreate GetEnhMetaFileW, 1, 0, <!!= NULL>, pRTCC_EnhMetaFile
DetourStdDestroy DeleteEnhMetaFile, 1, 1, <!!= FALSE>, pRTCC_EnhMetaFile

; ——————————————————————————————————————————————————————————————————————————————————————————————————

DetourStdCreate CreateDCA, 4, 0, <!!= NULL>, pRTCC_DeviceContext
DetourStdCreate CreateDCW, 4, 0, <!!= NULL>, pRTCC_DeviceContext
DetourStdCreate CreateCompatibleDC, 1, 0, <!!= NULL>, pRTCC_DeviceContext
DetourStdCreate CreateICA, 4, 0, <!!= NULL>, pRTCC_DeviceContext
DetourStdCreate CreateICW, 4, 0, <!!= NULL>, pRTCC_DeviceContext
DetourStdDestroy DeleteDC, 1, 1, <!!= FALSE>, pRTCC_DeviceContext

; ——————————————————————————————————————————————————————————————————————————————————————————————————

DetourStdCreate CreateAcceleratorTableA, 2, 0, <!!= NULL>, pRTCC_AccTable
DetourStdCreate CreateAcceleratorTableW, 2, 0, <!!= NULL>, pRTCC_AccTable
DetourStdCreate CopyAcceleratorTableA, 3, 0, <!!= NULL>, pRTCC_AccTable
DetourStdCreate CopyAcceleratorTableW, 3, 0, <!!= NULL>, pRTCC_AccTable
DetourStdCreate LoadAcceleratorsA, 2, 0, <!!= NULL>, pRTCC_AccTable
DetourStdCreate LoadAcceleratorsW, 2, 0, <!!= NULL>, pRTCC_AccTable
DetourStdDestroy DestroyAcceleratorTable, 1, 1, <!!= FALSE>, pRTCC_AccTable

; ——————————————————————————————————————————————————————————————————————————————————————————————————

DetourStdCreate CreateDesktopA, 6, 0, <!!= NULL>, pRTCC_Desktop
DetourStdCreate CreateDesktopW, 6, 0, <!!= NULL>, pRTCC_Desktop
DetourStdDestroy CloseDesktop, 1, 1, <!!= FALSE>, pRTCC_Desktop

; ——————————————————————————————————————————————————————————————————————————————————————————————————

DetourStdCreate CreateWindowStationA, 4, 0, <!!= NULL>, pRTCC_WindowStation
DetourStdCreate CreateWindowStationW, 4, 0, <!!= NULL>, pRTCC_WindowStation
DetourStdDestroy CloseWindowStation, 1, 1, <!!= FALSE>, pRTCC_WindowStation

; ——————————————————————————————————————————————————————————————————————————————————————————————————

DetourStdCreate CreateFileA, 7, 0, <!!= INVALID_HANDLE_VALUE>, pRTCC_File
DetourStdCreate CreateFileW, 7, 0, <!!= INVALID_HANDLE_VALUE>, pRTCC_File

; ------------------------------------------------------------------------------

DetourStdCreate CreateEventA, 4, 0, <!!= ERROR_ALREADY_EXISTS>, pRTCC_Event
DetourStdCreate CreateEventW, 4, 0, <!!= ERROR_ALREADY_EXISTS>, pRTCC_Event
DetourStdCreate OpenEventA, 3, 0, <!!= NULL>, pRTCC_Event
DetourStdCreate OpenEventW, 3, 0, <!!= NULL>, pRTCC_Event

; ------------------------------------------------------------------------------

DetourStdCreate CreateFileMappingA, 6, 0, <!!= ERROR_ALREADY_EXISTS>, pRTCC_FileMapping
DetourStdCreate CreateFileMappingW, 6, 0, <!!= ERROR_ALREADY_EXISTS>, pRTCC_FileMapping

; ------------------------------------------------------------------------------

DetourStdCreate CreateMutexA, 3, 0, <!!= ERROR_ALREADY_EXISTS>, pRTCC_Mutex
DetourStdCreate CreateMutexW, 3, 0, <!!= ERROR_ALREADY_EXISTS>, pRTCC_Mutex
DetourStdCreate OpenMutexA, 3, 0, <!!= NULL>, pRTCC_Mutex
DetourStdCreate OpenMutexW, 3, 0, <!!= NULL>, pRTCC_Mutex

; ------------------------------------------------------------------------------

HookCount = HookCount + 1
externdef pRTCC_Pipe:$ObjPtr(RTC_Collection)
.data
pHookCreatePipe   $ObjPtr(IAT_Hook)     NULL

.code
DtrCreatePipe proc uses xbx xdi Arg1:XWORD, Arg2:XWORD, Arg3:XWORD, Arg4:XWORD
  local xApiResult:XWORD, hThread:HANDLE
  local Context:CONTEXT, Stack:STACK

  InvokeOriginalAPI CreatePipe, 4

  .if dResGuardEnabled != FALSE
    ;Start analysis
    mov xApiResult, xax
    m2z dResGuardEnabled                                ;Shut Resguard off while analysis is in progress

    AnalyseStack
    FillStringA [xbx].$Obj(CallData).cProcName, <CreatePipe>

    .if xApiResult != 0
      mov xcx, Arg1                                     ;-> hReadPipe
      .if xcx != NULL
        m2m [xbx].$Obj(CallData).xData1, [xcx], xdx
        OCall pRTCC_Pipe::Collection.Insert, xbx
        mov xax, pRTCC_Pipe
        mov [xbx].$Obj(CallData).pOwner, xax
        OCall xax::Collection.Insert, xbx
        .if Arg2 != NULL
          ;Clone existing CallData
          mov xdi, $MemAlloc(sizeof $Obj(CallData))
          s2s $Obj(CallData) ptr [xdi], $Obj(CallData) ptr [xbx], xmm1, xmm2, xax, xcx
          mov xcx, Arg2                                 ;-> hWritePipe
          m2m [xdi].$Obj(CallData).xData1, [xcx], xdx
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
      OCall xax::Collection.Insert, xbx
    .endif

    mov dResGuardEnabled, TRUE
    mov xax, xApiResult                                 ;Restore API return value
  .endif
  ret
DtrCreatePipe endp

DetourStdCreate CreateNamedPipeA, 8, 0, <!!= INVALID_HANDLE_VALUE>, pRTCC_Pipe
DetourStdCreate CreateNamedPipeW, 8, 0, <!!= INVALID_HANDLE_VALUE>, pRTCC_Pipe

; ------------------------------------------------------------------------------

DetourStdCreate CreateProcessA, 10, -10, <!!= FALSE>, pRTCC_Process
DetourStdCreate CreateProcessW, 10, -10, <!!= FALSE>, pRTCC_Process
DetourStdCreate OpenProcess, 3, 0, <!!= NULL>, pRTCC_Process

; ------------------------------------------------------------------------------

DetourStdCreate CreateThread, 6, 0, <!!= NULL>, pRTCC_Thread
DetourStdCreate CreateRemoteThread, 3, 0, <!!= NULL>, pRTCC_Thread

; ------------------------------------------------------------------------------

DetourStdCreate CreateSemaphoreA, 4, 0, <!!= ERROR_ALREADY_EXISTS>, pRTCC_Semaphore
DetourStdCreate CreateSemaphoreW, 4, 0, <!!= ERROR_ALREADY_EXISTS>, pRTCC_Semaphore
DetourStdCreate OpenSemaphoreA, 3, 0, <!!= NULL>, pRTCC_Semaphore
DetourStdCreate OpenSemaphoreW, 3, 0, <!!= NULL>, pRTCC_Semaphore

; ------------------------------------------------------------------------------

DetourStdDestroy CloseHandle, 1, 1, <!!= FALSE>, \
                 pRTCC_File, pRTCC_Event, pRTCC_FileMapping, pRTCC_Mutex, pRTCC_Pipe, \
                 pRTCC_Process, pRTCC_Thread, pRTCC_Semaphore

; ——————————————————————————————————————————————————————————————————————————————————————————————————

HookCount = HookCount + 2
externdef pRTCC_Timer:$ObjPtr(RTC_Collection)
.data
pHookSetTimer   $ObjPtr(IAT_Hook)   NULL
pHookKillTimer  $ObjPtr(IAT_Hook)   NULL

.code
DtrSetTimer proc uses xbx xdi Arg1:XWORD, Arg2:XWORD, Arg3:XWORD, Arg4:XWORD
  local xApiResult:XWORD, hThread:HANDLE
  local Context:CONTEXT, Stack:STACK

  InvokeOriginalAPI SetTimer, 4

  .if dResGuardEnabled != FALSE
    mov xApiResult, xax
    m2z dResGuardEnabled                                ;Shut Resguard off while analysis is in progress

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
      OCall xax::Collection.Insert, xbx
    .endif

    mov dResGuardEnabled, TRUE
    mov xax, xApiResult                                 ;Restore API return value
  .endif
  ret
DtrSetTimer endp
DtrKillTimer proc uses xbx xdi Arg1:XWORD, Arg2:XWORD
  local xApiResult:XWORD, hThread:HANDLE
  local Context:CONTEXT, Stack:STACK

  InvokeOriginalAPI KillTimer, 2

  .if dResGuardEnabled != FALSE
    mov xApiResult, xax
    m2z dResGuardEnabled                                ;Shut Resguard off while analysis is in progress

    .if xax != 0
      OCall pRTCC_Timer::RTC_Collection.Remove, Arg2, Arg1
      test eax, eax
      jnz @@Exit                                        ;Exit if found
      invoke DbgOutText, $OfsCStr("DtrKillTimer failed to remove call data"),
                         DbgColorError, DbgColorBackground, \
                         DBG_EFFECT_NORMAL or DBG_EFFECT_NEWLINE, offset wCaption
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
    mov dResGuardEnabled, TRUE
    mov xax, xApiResult                                 ;Restore API return value
  .endif
  ret
DtrKillTimer endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————

DetourStdCreate GetDC, 1, 0, <!!= NULL>, pRTCC_DisplayDeviceContext
DetourStdCreate GetDCEx, 3, 0, <!!= NULL>, pRTCC_DisplayDeviceContext
DetourStdCreate GetWindowDC, 1, 0, <!!= NULL>, pRTCC_DisplayDeviceContext
DetourStdDestroy ReleaseDC, 2, 2, <!!= FALSE>, pRTCC_DisplayDeviceContext

; ——————————————————————————————————————————————————————————————————————————————————————————————————

DetourStdCreate LoadKeyboardLayoutA, 2, 0, <!!= NULL>, pRTCC_KeyboardLayout
DetourStdCreate LoadKeyboardLayoutW, 2, 0, <!!= NULL>, pRTCC_KeyboardLayout
DetourStdDestroy UnloadKeyboardLayout, 1, 1, <!!= FALSE>, pRTCC_KeyboardLayout

; ——————————————————————————————————————————————————————————————————————————————————————————————————

DetourStdCreate LoadLibraryA, 1, 0, <!!= NULL>, pRTCC_Library
DetourStdCreate LoadLibraryW, 1, 0, <!!= NULL>, pRTCC_Library
DetourStdCreate LoadLibraryExA, 3, 0, <!!= NULL>, pRTCC_Library
DetourStdCreate LoadLibraryExW, 3, 0, <!!= NULL>, pRTCC_Library
DetourStdDestroy FreeLibrary, 1, 1, <!!= FALSE>, pRTCC_Library

; ——————————————————————————————————————————————————————————————————————————————————————————————————

DetourStdCreate OpenPrinterA, 3, 0, <!!= NULL>, pRTCC_Printer
DetourStdCreate OpenPrinterW, 3, 0, <!!= NULL>, pRTCC_Printer
DetourStdCreate AddPrinterA, 3, 0, <!!= NULL>, pRTCC_Printer
DetourStdCreate AddPrinterW, 3, 0, <!!= NULL>, pRTCC_Printer
DetourStdDestroy ClosePrinter, 1, 1, <!!= FALSE>, pRTCC_Printer

; ——————————————————————————————————————————————————————————————————————————————————————————————————

DetourStdCreate RegCreateKeyA, 3, -3, <== ERROR_SUCCESS>, pRTCC_RegKey
DetourStdCreate RegCreateKeyW, 3, -3, <== ERROR_SUCCESS>, pRTCC_RegKey
DetourStdCreate RegCreateKeyExA, 9, -8, <== ERROR_SUCCESS>, pRTCC_RegKey
DetourStdCreate RegCreateKeyExW, 9, -8, <== ERROR_SUCCESS>, pRTCC_RegKey
DetourStdDestroy RegCloseKey, 1, 1, <== ERROR_SUCCESS>, pRTCC_RegKey

; ——————————————————————————————————————————————————————————————————————————————————————————————————

DetourStdCreate BeginUpdateResourceA, 2, 0, <!!= NULL>, pRTCC_UpdateResource
DetourStdCreate BeginUpdateResourceW, 2, 0, <!!= NULL>, pRTCC_UpdateResource
DetourStdDestroy EndUpdateResourceA, 2, 1, <!!= FALSE>, pRTCC_UpdateResource
DetourStdDestroy EndUpdateResourceW, 2, 1, <!!= FALSE>, pRTCC_UpdateResource

; ——————————————————————————————————————————————————————————————————————————————————————————————————

DetourStdCreate CreateMailslotA, 4, 0, <!!= INVALID_HANDLE_VALUE>, pRTCC_Mailslot
DetourStdCreate CreateMailslotW, 4, 0, <!!= INVALID_HANDLE_VALUE>, pRTCC_Mailslot

; ——————————————————————————————————————————————————————————————————————————————————————————————————

DetourStdCreate FindFirstFileA, 2, 0, <!!= INVALID_HANDLE_VALUE>, pRTCC_FindFirst
DetourStdCreate FindFirstFileW, 2, 0, <!!= INVALID_HANDLE_VALUE>, pRTCC_FindFirst
DetourStdDestroy FindClose, 1, 1, <!!= FALSE>, pRTCC_FindFirst

; ——————————————————————————————————————————————————————————————————————————————————————————————————

DetourStdCreate OpenEventLogA, 2, 0, <!!= NULL>, pRTCC_EventLog
DetourStdCreate OpenEventLogW, 2, 0, <!!= NULL>, pRTCC_EventLog
DetourStdDestroy CloseEventLog, 1, 1, <!!= FALSE>, pRTCC_EventLog

; ——————————————————————————————————————————————————————————————————————————————————————————————————

DetourStdCreate InitializeCriticalSection, 1, 1, <|| 0FFFFFFFFh>, pRTCC_CriticalSection
DetourStdDestroy DeleteCriticalSection, 1, 1, <|| 0FFFFFFFFh>, pRTCC_CriticalSection

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      DetourCntCreate
; Purpose:    Create a counted detour procedure to intercept allocation APIs.
; Arguments:  Arg1: API name.
;             Arg2: API argument count.
;             Arg3: Counter name.
;             Arg4: API success condition.
;             Arg5: RTCD_Coll pointer.
; Return:     Nothing.

DetourCntCreate macro ApiName:req, ArgCount:req, CounterName:req, SuccessCond:req, pRTC_Coll:req
  local ArgStr, Cnt

  HookCount = HookCount + 1                             ;;Keep track of the hook count
  externdef pRTC_Coll:$ObjPtr(RTC_Collection)           ;;The RTC_Collection will be definend later
  .data
  pHook&ApiName&   $ObjPtr(IAT_Hook)   NULL

  ArgStr textequ <>                                     ;;Prepare argument list
  Cnt = 0
  repeat ArgCount
    Cnt = Cnt + 1
    ArgStr CatStr ArgStr, <, >, <Arg>, %Cnt, <:XWORD>
  endm

  .code
  Dtr&ApiName& proc ArgStr                              ;;Procedure declaration
    local xApiResult:XWORD, hThread:HANDLE
    local Context:CONTEXT, Stack:STACK

    InvokeOriginalAPI ApiName, ArgCount

    .if dResGuardEnabled != FALSE
      mov xApiResult, xax
      m2z dResGuardEnabled                              ;;Shut Resguard off while analysis is in progress

      AnalyseStack
      FillStringA [xbx].$Obj(CallData).cProcName, <ApiName>

      .if xApiResult SuccessCond
        m2m [xbx].$Obj(CallData).xData1, CounterName, xax
        inc CounterName
        OCall pRTC_Coll::Collection.Insert, xbx
        mov xax, pRTC_Coll
        mov [xbx].$Obj(CallData).pOwner, xax
      .else
        mov [xbx].$Obj(CallData).xData1, -1
        lea xax, FailColl
        mov [xbx].$Obj(CallData).pOwner, xax
        OCall xax::Collection.Insert, xbx
      .endif

      mov dResGuardEnabled, TRUE
      mov xax, xApiResult                               ;;Restore API return value
    .endif
    ret
  Dtr&ApiName& endp
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      DetourCntDestroy
; Purpose:    Create a counted detour procedure to intercept deallocation APIs.
; Arguments:  Arg1: API name.
;             Arg2: API argument count.
;             Arg3: Counter name.
;             Arg4: API success condition.
;             Arg5: RTCD_Coll pointer list (One deallocation API for several allocation APIs).
; Return:     Nothing.

DetourCntDestroy macro ApiName:req, ArgCount:req, CounterName:req, SuccessCond:req, pRTC_Coll_List:vararg
  local ArgStr, Cnt, Coll, @@Exit

  HookCount = HookCount + 1                             ;;Keep track of the hook count
  .data
  pHook&ApiName&   $ObjPtr(IAT_Hook)   NULL

  ArgStr textequ <>
  Cnt = 0
  repeat ArgCount
    Cnt = Cnt + 1
    ArgStr CatStr ArgStr, <, >, <Arg>, %Cnt, <:DWORD>
  endm

  .code
  Dtr&ApiName& proc ArgStr                              ;;Procedure declaration
    local xApiResult:XWORD, hThread:HANDLE
    local Context:CONTEXT, Stack:STACK

    InvokeOriginalAPI ApiName, ArgCount

    .if dResGuardEnabled != FALSE
      mov xApiResult, xax
      m2z dResGuardEnabled                              ;;Shut Resguard off while analysis is in progress

      ifnb <SuccessCond>
        .if xax SuccessCond
          for pColl, <pRTC_Coll_List>                   ;;Search in all specified RTC_Collection objects
            @CatStr(<OCall >, pColl, <::RTC_Collection.Remove, >, CounterName, <, 0>)
            dec CounterName
            test eax, eax
            jnz @@Exit                                  ;;Exit if found
          endm
          invoke DbgOutText, $OfsCStr("Dtr&ApiName& failed to remove call data"),
                             DbgColorError, DbgColorBackground, \
                             DBG_EFFECT_NORMAL or DBG_EFFECT_NEWLINE, offset wCaption
          jmp @@Exit
        .endif
        AnalyseStack
        FillStringA [xbx].$Obj(CallData).cProcName, <ApiName>
        m2m [xbx].$Obj(CallData).xData1, -1, xcx

        lea xax, FailColl
        mov [xbx].$Obj(CallData).pOwner, xax
        OCall xax::RTC_Collection.Insert, xbx
      else
        for pColl, <pRTC_Coll_List>                     ;;Search in all specified RTC_Collection objects
          @CatStr(<OCall >, pColl, <::RTC_Collection.Remove, >, CounterName, <, 0>)
          dec CounterName
          test eax, eax
          jnz @@Exit                                    ;;Exit if found
        endm
        invoke DbgOutText, $OfsCStr("Dtr&ApiName& failed to remove call data"),
                           DbgColorError, DbgColorBackground, \
                           DBG_EFFECT_NORMAL or DBG_EFFECT_NEWLINE, offset wCaption
      endif
@@Exit:
      mov dResGuardEnabled, TRUE
      mov xax, xApiResult                               ;;Restore API return value
    .endif
    ret
  Dtr&ApiName& endp
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
.data
OleInitializeCount  DWORD  0

.code
DetourCntCreate OleInitialize, 1, OleInitializeCount, <== S_OK>, pRTCC_OleInitialization
DetourCntDestroy OleUninitialize, 0, OleInitializeCount, <|| 0FFFFFFFFh>, pRTCC_OleInitialization

; ——————————————————————————————————————————————————————————————————————————————————————————————————
.data
CoInitializeCount  DWORD  0

.code
DetourCntCreate CoInitialize, 1, CoInitializeCount, <== S_OK>, pRTCC_CoInitialization
DetourCntCreate CoInitializeEx, 2, CoInitializeCount, <== S_OK>, pRTCC_CoInitialization
DetourCntDestroy CoUninitialize, 0, CoInitializeCount, <|| 0FFFFFFFFh>, pRTCC_CoInitialization

; ==================================================================================================

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

  NewRTCC PaintStruct, 10
  NewHook BeginPaint, User32
  NewHook EndPaint, User32

  NewRTCC Pen, 10
  NewHook CreatePen, GDI32
  NewHook CreatePenIndirect, GDI32

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
  NewHook SetWindowRgn, User32

  NewRTCC Font, 10
  NewHook CreateFontA, GDI32
  NewHook CreateFontW, GDI32
  NewHook CreateFontIndirectA, GDI32
  NewHook CreateFontIndirectW, GDI32

  NewRTCC Palette, 10
  NewHook CreatePalette, GDI32
  NewHook CreateHalftonePalette, GDI32

  NewRTCC ColorSpace, 10
  NewHook CreateColorSpaceA, GDI32
  NewHook CreateColorSpaceW, GDI32

  NewHook DeleteObject, GDI32

  NewRTCC Cursor, 10
  NewHook CreateCursor, User32
  NewHook DestroyCursor, User32                 ;DestroyIcon and DestroyCursor use the same API!

  NewRTCC Icon, 10
  NewHook CreateIcon, User32
  NewHook CreateIconIndirect, User32
  NewHook CreateIconFromResource, User32
  NewHook CreateIconFromResourceEx, User32
  NewHook LoadIconA, User32
  NewHook LoadIconW, User32
  NewHook ExtractAssociatedIconA, Shell32
  NewHook ExtractAssociatedIconW, Shell32
  NewHook DestroyIcon, User32                   ;DestroyIcon and DestroyCursor use the same API!

  NewRTCC Menu, 10
  NewHook CreateMenu, User32
  NewHook CreatePopupMenu, User32
  NewHook LoadMenuA, User32
  NewHook LoadMenuW, User32
  NewHook LoadMenuIndirectA, User32
  NewHook LoadMenuIndirectW, User32
  NewHook DestroyMenu, User32

  NewRTCC Timer, 10
  NewHook SetTimer, User32
  NewHook KillTimer, User32

  NewRTCC MetaFile, 10
  NewHook CreateMetaFileA, GDI32
  NewHook CreateMetaFileW, GDI32
  NewHook GetMetaFileA, GDI32
  NewHook GetMetaFileW, GDI32
  NewHook DeleteMetaFile, GDI32

  NewRTCC EnhMetaFile, 10
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
  NewHook CloseWindowStation, User32

  NewRTCC File, 10
  NewHook CreateFileA, Kernel32
  NewHook CreateFileW, Kernel32

  NewRTCC Event, 10
  NewHook CreateEventA, Kernel32
  NewHook CreateEventW, Kernel32
  NewHook OpenEventA, Kernel32
  NewHook OpenEventW, Kernel32

  NewRTCC FileMapping, 10
  NewHook CreateFileMappingA, Kernel32
  NewHook CreateFileMappingW, Kernel32

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
  NewHook OpenProcess, Kernel32

  NewRTCC Thread, 10
  NewHook CreateThread, Kernel32
  NewHook CreateRemoteThread, Kernel32

  NewRTCC Semaphore, 10
  NewHook CreateSemaphoreA, Kernel32
  NewHook CreateSemaphoreW, Kernel32
  NewHook OpenSemaphoreA, Kernel32
  NewHook OpenSemaphoreW, Kernel32

  NewHook CloseHandle, Kernel32

  NewRTCC Printer, 10
  NewHook OpenPrinterA, WinSpool
  NewHook OpenPrinterW, WinSpool
  NewHook AddPrinterA, WinSpool
  NewHook AddPrinterW, WinSpool
  NewHook ClosePrinter, WinSpool

  NewRTCC RegKey, 10
  NewHook RegCreateKeyA, AdvApi32
  NewHook RegCreateKeyW, AdvApi32
  NewHook RegCreateKeyExA, AdvApi32
  NewHook RegCreateKeyExW, AdvApi32
  NewHook RegCloseKey, AdvApi32

  NewRTCC UpdateResource, 10
  NewHook BeginUpdateResourceA, Kernel32
  NewHook BeginUpdateResourceW, Kernel32
  NewHook EndUpdateResourceA, Kernel32
  NewHook EndUpdateResourceW, Kernel32

  NewRTCC Mailslot, 10
  NewHook CreateMailslotA, Kernel32
  NewHook CreateMailslotW, Kernel32

  NewRTCC FindFirst, 10
  NewHook FindFirstFileA, Kernel32
  NewHook FindFirstFileW, Kernel32
  NewHook FindClose, Kernel32

  NewRTCC EventLog, 10
  NewHook OpenEventLogA, Kernel32
  NewHook OpenEventLogW, Kernel32
  NewHook CloseEventLog, Kernel32

  NewRTCC CriticalSection, 10
  NewHook InitializeCriticalSection, Kernel32
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
  NewHook LocalFree, Kernel32
  NewHook LocalReAlloc, Kernel32
  NewHook LocalAlloc, Kernel32

  NewRTCC GlobalMemBlock, 100
  NewHook GlobalFree, Kernel32
  NewHook GlobalReAlloc, Kernel32
  NewHook GlobalAlloc, Kernel32

  NewRTCC HeapMemBlock, 100
  NewHook HeapFree, Kernel32
  NewHook HeapReAlloc, Kernel32
  NewHook HeapAlloc, Kernel32

  ret
DllInit endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure: ResGuardInit (expoerted)
; Purpose:   Initialize monitoring.
; Arguments: Arg1: Application reference address to stop stack analysis.
; Return:    Nothing.

ResGuardInit proc xRefAddr:XWORD
  m2m xAppRefAddr, xRefAddr, xax
  ret
ResGuardInit endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure: ResGuardShow (expoerted)
; Purpose:   Visualisation of resource usage.
; Arguments: Arg1: -> RTC_Collection.
;            Arg2: Resource type caption.
;            xbx -> Output ANSI buffer.
; Return:    Nothing.

ShowCollectionData macro pRTC_Collection:req, ResTypeCaption:req
  local szLeakCaption

  CStr szLeakCaption, ResTypeCaption, " cur. = %3li, max. = %5li, tot. = %5li"
  mov xdi, pRTC_Collection
  .if (dHasLeaks == FALSE) && ([xdi].$Obj(RTC_Collection).dCount > 0)
    inc dHasLeaks
  .endif
  .if ([xdi].$Obj(RTC_Collection).dCount > 0)
    invoke wsprintf, xbx, offset szLeakCaption, [xdi].$Obj(RTC_Collection).dCount, \
                     [xdi].$Obj(RTC_Collection).dMaxCount, [xdi].$Obj(RTC_Collection).dTotCount
    invoke DbgOutText, xbx, DbgColorForeground, DbgColorBackground, \
                       DBG_EFFECT_NORMAL or DBG_EFFECT_NEWLINE, offset wCaption
    OCall xdi::RTC_Collection.ForEach, $MethodAddr(CallData.Show), NULL, NULL
  .endif
endm

ResGuardShow proc uses xbx xdi
  local cBuffer[256]:CHRA, dHasLeaks:DWORD

  m2z dResGuardEnabled
  m2z dHasLeaks
  lea xbx, cBuffer

  ; -----------------------------------------------------------------------------------
  ShowCollectionData pRTCC_VirtualMemBlock,      "Virtual Mem-Blocks:"
  ShowCollectionData pRTCC_GlobalMemBlock,       "Global Mem-Blocks: "
  ShowCollectionData pRTCC_LocalMemBlock,        "Local Mem-Blocks:  "
  ShowCollectionData pRTCC_HeapMemBlock,         "Heap Mem-Blocks:   "
  ShowCollectionData pRTCC_CoTaskMemBlock,       "CoTaskMem-Blocks:  "
  ShowCollectionData pRTCC_SysString,            "System BStrings:   "
  ShowCollectionData pRTCC_Pen,                  "GDI Pens:          "
  ShowCollectionData pRTCC_Brush,                "GDI Brushes:       "
  ShowCollectionData pRTCC_Bitmap,               "GDI Bitmaps:       "
  ShowCollectionData pRTCC_Image,                "GDI Images:        "
  ShowCollectionData pRTCC_Region,               "GDI Regions:       "
  ShowCollectionData pRTCC_Font,                 "GDI Fonts:         "
  ShowCollectionData pRTCC_Palette,              "GDI Palettes:      "
  ShowCollectionData pRTCC_ColorSpace,           "GDI Color Spaces:  "
  ShowCollectionData pRTCC_MetaFile,             "GDI MetaFiles:     "
  ShowCollectionData pRTCC_EnhMetaFile,          "GDI EnhMetaFiles:  "
  ShowCollectionData pRTCC_Cursor,               "Cursors:           "
  ShowCollectionData pRTCC_Icon,                 "Icons:             "
  ShowCollectionData pRTCC_Menu,                 "Menus:             "
  ShowCollectionData pRTCC_Timer,                "Timers:            "
  ShowCollectionData pRTCC_AccTable,             "Accelerator Tables:"
  ShowCollectionData pRTCC_DeviceContext,        "Device Contexts:   "
  ShowCollectionData pRTCC_DisplayDeviceContext, "Display DCs:       "
  ShowCollectionData pRTCC_PaintStruct,          "Paint Structures:  "
  ShowCollectionData pRTCC_Desktop,              "Desktops:          "
  ShowCollectionData pRTCC_KeyboardLayout,       "Keyboard Layouts:  "
  ShowCollectionData pRTCC_WindowStation,        "Window Stations:   "
  ShowCollectionData pRTCC_Library,              "Libraries:         "
  ShowCollectionData pRTCC_File,                 "Files:             "
  ShowCollectionData pRTCC_FileMapping,          "File Mappings:     "
  ShowCollectionData pRTCC_Event,                "Events:            "
  ShowCollectionData pRTCC_Mutex,                "Mutexes:           "
  ShowCollectionData pRTCC_Process,              "Processes:         "
  ShowCollectionData pRTCC_Thread,               "Threads:           "
  ShowCollectionData pRTCC_Semaphore,            "Semaphores:        "
  ShowCollectionData pRTCC_Printer,              "Printers:          "
  ShowCollectionData pRTCC_RegKey,               "Registry Keys:     "
  ShowCollectionData pRTCC_UpdateResource,       "File Resources:    "
  ShowCollectionData pRTCC_Mailslot,             "Mail Slots:        "
  ShowCollectionData pRTCC_FindFirst,            "Find First:        "
  ShowCollectionData pRTCC_EventLog,             "Event Logs:        "
  ShowCollectionData pRTCC_CriticalSection,      "Critical Sections: "
  ShowCollectionData pRTCC_OleInitialization,    "OLE active library:"
  ShowCollectionData pRTCC_CoInitialization,     "COM active library:"
  ; -----------------------------------------------------------------------------------

  lea xdi, FailColl
  .if ([xdi].$Obj(RTC_Collection).dCount > 0)
    invoke wsprintf, xbx, $OfsCStr("Failed API calls:   %li"), [xdi].$Obj(Collection).dCount
    invoke DbgOutText, xbx, DbgColorForeground, DbgColorBackground, \
                       DBG_EFFECT_NORMAL or DBG_EFFECT_NEWLINE, offset wCaption
    OCall FailColl::RTC_Collection.ForEach, $MethodAddr(CallData.Show), NULL, NULL
  .endif
  .if (dHasLeaks == FALSE) && ([xdi].$Obj(Collection).dCount > 0)
    inc dHasLeaks
  .endif

  mov dResGuardEnabled, TRUE

  .if dHasLeaks
    invoke MessageBoxW, 0, offset wDebugStart, offset wCaption, MB_YESNO or MB_ICONEXCLAMATION
    .if eax == IDYES
      int 3
    .endif
  .endif

  ret
ResGuardShow endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure: ResGuardStart (expoerted)
; Purpose:   Begins resource monitoring.
; Arguments: None.
; Return:    Nothing.

ResGuardStart proc uses xbx
  m2z dResGuardEnabled
  xor ebx, ebx
  .while ebx < RcrcColl.dCount
    OCall RcrcColl::Collection.ItemAt, ebx
    m2z [xax].$Obj(RTC_Collection).dMaxCount
    m2z [xax].$Obj(RTC_Collection).dTotCount
    OCall xax::RTC_Collection.DisposeAll
    inc ebx
  .endw
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
