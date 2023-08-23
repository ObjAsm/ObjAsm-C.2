; ==================================================================================================
; Title:      ResGuard.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    Detection of resource leakages using ObjAsm ResGuardxx.dll.
; Notes:      http://www.microsoft.com/msj/0498/hood0498.aspx
;             Version C.1.0, August 2023
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\Code\Macros\Model.inc
SysSetup OOP, DLL64, WIDE_STRING, DEBUG(WND)

% include &IncPath&Windows\ImageHlp.inc

% includelib &LibPath&Windows\ImageHlp.lib


CStrW wLeakReport, "Resource Leakage Report"
CStrW wDebugStart, "Use the debugger to find the lines of", CR, LF, \
                   "code that use the listed resources.", CR, LF, CR, LF,\
                   "Do you want to start the debugger now?"

HookCount = 0

MakeObjects Primer, Stream, Collection, XWCollection, IAT_Hook

.data
  pAppBaseFrame     POINTER   NULL
  dResGuardEnabled  DWORD     FALSE
  HookColl          $ObjInst(Collection)                  ;Collection of IAT_Hook objects
  RcrcColl          $ObjInst(Collection)                  ;Collection of RTC_Collection objects
  FailColl          $ObjInst(Collection)                  ;Collection of failed API calls (GetCallStack)

if TARGET_BITNESS eq 32
  % include &MacPath&Exception32.inc                      ;Exception macros
else
  % include &MacPath&Exception64.inc                      ;Exception macros
endif

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Object:     CallData
; Purpose:    Store all relevant info about a specific API call, like the call stack and an system
;             identification like a HANDLE, ID, etc.

Object CallData,, Primer
  RedefineMethod  Init,         POINTER, $ObjPtr(XWCollection), XWORD

  DefineVariable  pCallStack,   $ObjPtr(XWCollection),  NULL  ;GetCallStack returns an XWCollection
  DefineVariable  xData,        XWORD,    0
ObjectEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Object:     RTC_Collection (RTC: Resource Type Call, RTCC: RTC Collection)
; Purpose:    Collection of CallData Objects aggregated by system resource type (e.g. Brush).
; Example:    pRTC_CollBrush

Object RTC_Collection,, Collection
  RedefineMethod  Insert,       $ObjPtr(CallData)

  DefineVariable  dMaxCount,    DWORD,    0               ;Maximal count to check the system load 
  DefineVariable  dTotCount,    DWORD,    0               ;Cummulated number of calls
ObjectEnd


.code
; ==================================================================================================
;    CallData implementation
; ==================================================================================================

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     CallData.Init
; Purpose:    Initialize the CallData object. 
; Arguments:  Arg1: -> Owner object (generic Collection).
;             Arg2: -> XWCollection. 
;             Arg3: Data identifying the call (HANDLE, ID, etc.).
; Return:     Nothing.

Method CallData.Init, uses xsi, pOwner:POINTER, pCallStack:$ObjPtr(XWCollection), xData:XWORD
  SetObject xsi
  ACall xsi.Init, pOwner
  m2m [xsi].pCallStack, pCallStack, xax
  m2m [xsi].xData, xData, xcx
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
; Procedure:  GetCallStack
; Purpose:    Return the calling address chain in an XWCollection.
; Arguments:  xbp -> Stack.
; Return:     xax -> XWCollection.

if TARGET_BITNESS eq 32
CreateExceptionHandler GetCallSequence_ExceptionHandler, , EXCEPTION_ACCESS_VIOLATION

GetCallStack proc uses ebx
  local pCallStack:$ObjPtr(XWCollection)

  .try GetCallSequence_ExceptionHandler
    mov pCallStack, $New(XWCollection)
    OCall eax::XWCollection.Init, NULL, 10, 10, COL_MAX_CAPACITY
    mov eax, [ebp]                                        ;Remove last caller of the current proc
    .while (eax != pAppBaseFrame && eax != NULL)          ;App start stack frame reached or frame lost
      mov ebx, [eax]                                      ;Exceptions can occure here!
      OCall pCallStack::XWCollection.Insert, POINTER ptr [eax + sizeof(DWORD)] ;Store return address
      mov eax, ebx                                        ;Get previous xbp in xax
    .endw
  .catch GetCallSequence_ExceptionHandler
    OCall pCallStack::XWCollection.Insert, NULL
  .endcatch GetCallSequence_ExceptionHandler
  mov eax, pCallStack                                     ;Return -> caller collection
  ret
GetCallStack endp

else

;https://www.ired.team/miscellaneous-reversing-forensics/windows-kernel-internals/windows-x64-calling-convention-stack-frame
;https://learn.microsoft.com/en-us/windows/win32/api/dbghelp/nf-dbghelp-stackwalk
;https://learn.microsoft.com/en-us/windows/win32/api/dbghelp/nf-dbghelp-stackwalk64
;https://stackoverflow.com/questions/5705650/stackwalk64-on-windows-get-symbol-name

GetCallStack proc uses rbx
  local pCallStack:$ObjPtr(XWCollection)

  .try
    mov pCallStack, $New(XWCollection)
    OCall rax::XWCollection.Init, NULL, 10, 10, COL_MAX_CAPACITY
    mov rax, [rsp]                                        ;Remove last caller of the current proc
;    .while (rax != pAppBaseFrame && rax != NULL)          ;App start xbp reached or frame lost
      mov rbx, [rax]                                      ;Exceptions can occure here!
      OCall pCallStack::XWCollection.Insert, POINTER ptr [rax] ;Store return address
      mov rax, rbx                                        ;Get previous xbp in xax
;    .endw
  .catch
    OCall pCallStack::XWCollection.Insert, NULL
  .endcatch
  .finally
  mov rax, pCallStack                                     ;Return -> caller collection
  ret
GetCallStack endp

endif

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  EntryCreate
; Purpose:    Create an entry (CallData) for the RTC_Collection.
; Arguments:  Arg1: -> RTC_Collection.
;             Arg2: -> XWCollection (Call stack).
;             Arg3: Additional argument to identify the call (HANDLE, ID, etc.).
; Return:     Nothing.

EntryCreate proc pRTC_Coll:$ObjPtr(RTC_Collection), pCallStack:$ObjPtr(XWCollection), xData:XWORD
  OCall pRTC_Coll::Collection.Insert, $New(CallData)
  OCall xax::CallData.Init, pRTC_Coll, pCallStack, xData
  ret
EntryCreate endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  EntryDelete
; Purpose:    Delete an entry (CallData) from the RTC_Collection based on the call identifier.
; Arguments:  Arg1: -> RTC_Collection.
;             Arg2: Argument passed as Arg3 on CreateEntry.
; Return:     eax = TRUE if succeeded, otherwise FALSE.

EntryCompare proc pCallData:$ObjPtr(CallData), xData:XWORD
  mov xcx, pCallData
  xor eax, eax
  mov xdx, xData
  .if xdx == [xcx].$Obj(CallData).xData
    inc eax
  .endif
  ret
EntryCompare endp

EntryDelete proc pRTC_Coll:$ObjPtr(RTC_Collection), xData:XWORD
  OCall pRTC_Coll::RTC_Collection.LastThat, offset EntryCompare, xData, NULL
  .if xax
    OCall pRTC_Coll::RTC_Collection.Dispose, xax
    xor eax, eax
    inc eax
  .endif
  ret
EntryDelete endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  ShowCaller
; Purpose:    Display on the a chain member of the call sequence on the "LeakReport" 
;             DebugCenter child Window
; Arguments:  Arg1: -> Caller address.
;             Arg2: -> Last caller address.
;             Arg3: Dummy.
; Return:     eax = TRUE if the end was reached, otherwise FALSE.

ShowCaller proc uses xbx pCaller:POINTER, pLastCaller:POINTER, xDummy:XWORD
  local cBuffer[256]:CHR

  lea xbx, cBuffer
  .if pCaller == NULL
    FillString [xbx], < EOS>
  .else
    invoke wsprintf, xbx, $OfsCStr(" %08Xh"), pCaller
  .endif
  mov xcx, pCaller
  .if xcx != pLastCaller
    invoke StrCat, xbx, $OfsCStr(" «")
  .endif
  invoke DbgOutText, xbx, DbgColorWarning, DbgColorBackground, \
                     DBG_EFFECT_NORMAL, offset wLeakReport
  xor eax, eax
  .if pCaller == NULL
    inc eax
  .endif
  ret
ShowCaller endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  ShowCallers
; Purpose:    Callback procedure to display on the a chain member of the call sequence on the  
;             "LeakReport" DebugCenter child Window.
; Arguments:  Arg1: -> Caller Collection.
;             Arg2: Dummy argument.
;             Arg3: Dummy argument.
; Return:     Nothing.

ShowCallers proc uses xsi pCallStack:$ObjPtr(XWCollection), xDummy1:XWORD, xDummy2:XWORD
  mov xsi, pCallStack
  .if [xsi].$Obj(XWCollection).dCount > 0
    invoke DbgOutText, $OfsCStr(" •"), DbgColorWarning, DbgColorBackground, \
                       DBG_EFFECT_NORMAL, offset wLeakReport
    mov eax, [xsi].$Obj(XWCollection).dCount
    dec eax
    OCall xsi::XWCollection.ItemAt, eax
    OCall xsi::XWCollection.FirstThat, offset ShowCaller, xax, NULL
    invoke DbgOutText, offset cCRLF, DbgColorForeground, DbgColorBackground, \
                       DBG_EFFECT_NORMAL, offset wLeakReport
  .endif
  ret
ShowCallers endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  EntryShowCallers
; Purpose:    Callback procedure to display on the a chain member of the call sequence on the  
;             "LeakReport" DebugCenter child Window.
; Arguments:  Arg1: -> CallData objct.
;             Arg2: Dummy argument.
;             Arg3: Dummy argument.
; Return:     Nothing.

EntryShowCallers proc pCallData:$ObjPtr(CallData), xDummy1:XWORD, xDummy2:XWORD
  mov xcx, pCallData
  invoke ShowCallers, [xcx].$Obj(CallData).pCallStack, xDummy1, xDummy2
  ret
EntryShowCallers endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      CreateStdHook
; Purpose:    Create a standard hook.
; Arguments:  Arg1: Hook name.
;             Arg2: API argument count.
;             Arg3: ID = x:
;                     x > 0 : Argument x
;                     x = 0 : [xsp]
;                     x < 0 : [Argument -x]
;             Arg4: API success condition.
;             Arg5: RTCD_Coll pointer.
; Return:     Nothing.

CreateStdHook macro HookName:req, ArgCount:req, IDArg:req, SuccessCond:req, pRTC_Coll:req
  local ArgStr, Cnt

  HookCount = HookCount + 1                               ;;Keep track of the hook count
  externdef pRTC_Coll:$ObjPtr(RTC_Collection)             ;;The RTC_Collection will be definend later
  .data
  pHook&HookName&   $ObjPtr(IAT_Hook)   NULL

  ArgStr textequ <>                                       ;;Prepare argument list
  Cnt = 0
  repeat ArgCount
    Cnt = Cnt + 1
    ArgStr CatStr ArgStr, <, >, <Arg>, %Cnt, <:XWORD>
  endm

  .code
  My&HookName& proc ArgStr                                ;;Procedure declaration
    repeat ArgCount                                       ;;Push arguments
      @CatStr(<push Arg>, %Cnt)
      Cnt = Cnt - 1
    endm
    mov xax, pHook&HookName&
    call [xax].$Obj(IAT_Hook).pEntry                      ;;Call original API
    .if dResGuardEnabled == TRUE
      push xax                                            ;;Store API return value
      m2z dResGuardEnabled
      .if xax SuccessCond
        invoke GetCallStack                               ;;Returns an XWCollection in xax
        if IDArg gt 0
          invoke EntryCreate, pRTC_Coll, xax, Arg&IDArg&
        elseif IDArg eq 0
          invoke EntryCreate, pRTC_Coll, xax, [xsp]
        else
          Cnt = 0 - IDArg
          mov xdx, xax
          mov xax, @CatStr(<Arg>, %Cnt)
          invoke EntryCreate, pRTC_Coll, xdx, [xax]
        endif
      .else
        OCall FailColl::Collection.Insert, $invoke(GetCallStack)  ;Insert a XWCollection
      .endif
      mov dResGuardEnabled, TRUE
      pop xax                                             ;;Restore API return value
    .endif
    ret
  My&HookName& endp
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————

DestroyStdHook macro HookName:req, ArgCount:req, IDArg:req, SuccessCond:=<>, pRTC_Coll_List:vararg
  local ArgStr, Cnt, Coll, @@

  HookCount = HookCount + 1                               ;;Keep track of the hook count
  .data
  pHook&HookName&   $ObjPtr(IAT_Hook)   NULL

  ArgStr textequ <>
  Cnt = 0
  repeat ArgCount
    Cnt = Cnt + 1
    ArgStr CatStr ArgStr, <, >, <Arg>, %Cnt, <:XWORD>
  endm

  .code
  My&HookName& proc ArgStr                                ;;Procedure declaration
    repeat ArgCount
      @CatStr(<push Arg>, %Cnt)
      Cnt = Cnt - 1
    endm
    mov xax, pHook&HookName&
    call [xax].$Obj(IAT_Hook).pEntry                      ;;Call API

    .if dResGuardEnabled == TRUE
      push xax                                            ;;Store API return value
      m2z dResGuardEnabled
      ifnb <SuccessCond>
        ;Check success condition
        .if xax SuccessCond
          for pColl, <pRTC_Coll_List>                     ;;Search in all specified RTC_Collection objects
            @CatStr(<invoke EntryDelete, >, pColl, <, Arg>, IDArg)
            test eax, eax
            jnz @@                                        ;;Exit if found
          endm
        .else
          OCall FailColl::Collection.Insert, $invoke(GetCallStack)
        .endif
      else
        ;Always succeed
        for pColl, <pRTC_Coll_List>                       ;;Search in all specified RTC_Collection objects
          @CatStr(<invoke EntryDelete, >, pColl, <, Arg>, IDArg)
          test eax, eax
          jnz @@                                          ;;Exit if found
        endm
      endif
@@:
      mov dResGuardEnabled, TRUE
      pop xax                                             ;;Restore API return value
    .endif
    ret
  My&HookName& endp
endm

; ==================================================================================================

CreateStdHook HeapAlloc, 3, 0, <!!= NULL>, pRTCC_HeapMemBlock
DestroyStdHook HeapFree, 3, 3, <!!= FALSE>, pRTCC_HeapMemBlock

HookCount = HookCount + 1
.data
pHookHeapReAlloc  $ObjPtr(IAT_Hook)   NULL

.code
MyHeapReAlloc proc hHeap:HANDLE, dFlags:DWORD, pMem:POINTER, dBytes:DWORD
  push XWORD ptr dBytes                                   ;Prepare stack frame
  push pMem
  push XWORD ptr dFlags
  push hHeap
  mov xax, pHookHeapReAlloc
  call [xax].$Obj(IAT_Hook).pEntry
  .if dResGuardEnabled == TRUE
    .if eax != FALSE
      m2z dResGuardEnabled
      push xax
      invoke EntryDelete, pRTCC_HeapMemBlock, pMem        ;First delete that Entry
      invoke EntryCreate, pRTCC_HeapMemBlock, $invoke(GetCallStack), [xsp]
    .else
      OCall FailColl::Collection.Insert, $invoke(GetCallStack)
    .endif
    pop xax
    mov dResGuardEnabled, TRUE
  .endif
  ret
MyHeapReAlloc endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————

CreateStdHook GlobalAlloc, 2, 0, <!!= NULL>, pRTCC_GlobalMemBlock
DestroyStdHook GlobalFree, 1, 1, <== NULL>, pRTCC_GlobalMemBlock

HookCount = HookCount + 1
.data
pHookGlobalReAlloc  $ObjPtr(IAT_Hook)   NULL

.code
MyGlobalReAlloc proc hMem:POINTER, dBytes:DWORD, dFlags:DWORD
  push XWORD ptr dFlags
  push XWORD ptr dBytes                                   ;Prepare stack frame
  push hMem
  mov xax, pHookGlobalReAlloc
  call [xax].$Obj(IAT_Hook).pEntry
  .if dResGuardEnabled == TRUE
    push xax
    m2z dResGuardEnabled
    .if eax != FALSE
      invoke EntryDelete, pRTCC_GlobalMemBlock, hMem      ;First delete that Entry
      invoke EntryCreate, pRTCC_GlobalMemBlock, $invoke(GetCallStack), [xsp]
    .else
      OCall FailColl::Collection.Insert, $invoke(GetCallStack)
    .endif
    mov dResGuardEnabled, TRUE
    pop xax
  .endif
  ret
MyGlobalReAlloc endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————

CreateStdHook LocalAlloc, 2, 0, <!!= NULL>, pRTCC_LocalMemBlock
DestroyStdHook LocalFree, 1, 1, <== NULL>, pRTCC_LocalMemBlock

HookCount = HookCount + 1
.data
pHookLocalReAlloc  $ObjPtr(IAT_Hook)  NULL

.code
MyLocalReAlloc proc hMem:POINTER, dBytes:DWORD, dFlags:DWORD
  push XWORD ptr dFlags
  push XWORD ptr dBytes                                   ;Prepare stack frame
  push hMem
  mov xax, pHookLocalReAlloc
  call [xax].$Obj(IAT_Hook).pEntry
  .if dResGuardEnabled == TRUE
    push xax
    m2z dResGuardEnabled
    .if eax != FALSE
      invoke EntryDelete, pRTCC_LocalMemBlock, hMem       ;First delete that Entry
      invoke EntryCreate, pRTCC_LocalMemBlock, $invoke(GetCallStack), [xsp]
    .else
      OCall FailColl::Collection.Insert, $invoke(GetCallStack)
    .endif
    mov dResGuardEnabled, TRUE
    pop xax
  .endif
  ret
MyLocalReAlloc endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————

CreateStdHook CoTaskMemAlloc, 1, 0, <!!= NULL>, pRTCC_CoTaskMemBlock
DestroyStdHook CoTaskMemFree, 1, 1, <>, pRTCC_CoTaskMemBlock

HookCount = HookCount + 1
.data
pHookCoTaskMemRealloc  $ObjPtr(IAT_Hook)  NULL

.code
MyCoTaskMemRealloc proc pMem:POINTER, dBytes:DWORD
  push XWORD ptr dBytes                                   ;Prepare stack frame
  push XWORD ptr pMem
  mov xax, pHookCoTaskMemRealloc
  call [xax].$Obj(IAT_Hook).pEntry
  .if dResGuardEnabled == TRUE
    push xax
    m2z dResGuardEnabled
    .if eax != NULL
      invoke EntryDelete, pRTCC_CoTaskMemBlock, pMem      ;First delete that Entry
      invoke EntryCreate, pRTCC_CoTaskMemBlock, $invoke(GetCallStack), [xsp]
    .else
      OCall FailColl::Collection.Insert, $invoke(GetCallStack)
    .endif
    mov dResGuardEnabled, TRUE
    pop xax
  .endif
  ret
MyCoTaskMemRealloc endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————

CreateStdHook VirtualAlloc, 4, 0, <!!= NULL>, pRTCC_VirtualMemBlock
DestroyStdHook VirtualFree, 3, 1, <!!= FALSE>, pRTCC_VirtualMemBlock

; ——————————————————————————————————————————————————————————————————————————————————————————————————

CreateStdHook SysAllocString, 1, 0, <!!= NULL>, pRTCC_SysString
CreateStdHook SysAllocStringLen, 2, 0, <!!= NULL>, pRTCC_SysString
CreateStdHook SysAllocStringByteLen, 2, 0, <!!= NULL>, pRTCC_SysString
CreateStdHook SysReAllocString, 2, 0, <!!= FALSE>, pRTCC_SysString
CreateStdHook SysReAllocStringLen, 3, 0, <!!= FALSE>, pRTCC_SysString
DestroyStdHook SysFreeString, 1, 1, <!!= FALSE>, pRTCC_SysString

; ——————————————————————————————————————————————————————————————————————————————————————————————————

CreateStdHook BeginPaint, 2, 2, <!!= NULL>, pRTCC_PaintStruct
DestroyStdHook EndPaint, 2, 2, <!!= FALSE>, pRTCC_PaintStruct

; ——————————————————————————————————————————————————————————————————————————————————————————————————

CreateStdHook CreatePen, 3, 0, <!!= NULL>, pRTCC_Pen
CreateStdHook CreatePenIndirect, 1, 0, <!!= NULL>, pRTCC_Pen

; ------------------------------------------------------------------------------

CreateStdHook CreateSolidBrush, 1, 0, <!!= NULL>, pRTCC_Brush
CreateStdHook CreateDIBPatternBrush, 2, 0, <!!= NULL>, pRTCC_Brush
CreateStdHook CreateDIBPatternBrushPt, 2, 0, <!!= NULL>, pRTCC_Brush
CreateStdHook CreateHatchBrush, 2, 0, <!!= NULL>, pRTCC_Brush
CreateStdHook CreatePatternBrush, 1, 0, <!!= NULL>, pRTCC_Brush
CreateStdHook CreateBrushIndirect, 1, 0, <!!= NULL>, pRTCC_Brush

; ------------------------------------------------------------------------------

CreateStdHook CreateBitmap, 5, 0, <!!= NULL>, pRTCC_Bitmap
CreateStdHook CreateBitmapIndirect, 1, 0, <!!= NULL>, pRTCC_Bitmap
CreateStdHook CreateCompatibleBitmap, 3, 0, <!!= NULL>, pRTCC_Bitmap
CreateStdHook CreateDIBitmap, 6, 0, <!!= NULL>, pRTCC_Bitmap
CreateStdHook CreateDIBSection, 6, 0, <!!= NULL>, pRTCC_Bitmap
CreateStdHook CreateDiscardableBitmap, 3, 0, <!!= NULL>, pRTCC_Bitmap
CreateStdHook LoadBitmapA, 2, 0, <!!= NULL>, pRTCC_Bitmap
CreateStdHook LoadBitmapW, 2, 0, <!!= NULL>, pRTCC_Bitmap

; ------------------------------------------------------------------------------

CreateStdHook CreateEllipticRgn, 4, 0, <!!= NULL>, pRTCC_Region
CreateStdHook CreateEllipticRgnIndirect, 1, 0, <!!= NULL>, pRTCC_Region
CreateStdHook CreatePenDataRegion, 2, 0, <!!= NULL>, pRTCC_Region
CreateStdHook CreatePolygonRgn, 3, 0, <!!= NULL>, pRTCC_Region
CreateStdHook CreatePolyPolygonRgn, 4, 0, <!!= NULL>, pRTCC_Region
CreateStdHook CreateRectRgn, 4, 0, <!!= NULL>, pRTCC_Region
CreateStdHook CreateRectRgnIndirect, 1, 0, <!!= NULL>, pRTCC_Region
CreateStdHook CreateRoundRectRgn, 6, 0, <!!= NULL>, pRTCC_Region
DestroyStdHook SetWindowRgn, 3, 2, <!!= FALSE>, pRTCC_Region      ;This region is destroyed by the window!

; ------------------------------------------------------------------------------

CreateStdHook CopyImage, 5, 0, <!!= NULL>, pRTCC_Image
CreateStdHook LoadImageA, 6, 0, <!!= NULL>, pRTCC_Image
CreateStdHook LoadImageW, 6, 0, <!!= NULL>, pRTCC_Image

; ------------------------------------------------------------------------------

CreateStdHook CreateFontA, 14, 0, <!!= NULL>, pRTCC_Font
CreateStdHook CreateFontW, 14, 0, <!!= NULL>, pRTCC_Font
CreateStdHook CreateFontIndirectA, 1, 0, <!!= NULL>, pRTCC_Font
CreateStdHook CreateFontIndirectW, 1, 0, <!!= NULL>, pRTCC_Font

; ------------------------------------------------------------------------------

CreateStdHook CreatePalette, 1, 0, <!!= NULL>, pRTCC_Palette
CreateStdHook CreateHalftonePalette, 1, 0, <!!= NULL>, pRTCC_Palette

; ------------------------------------------------------------------------------

CreateStdHook CreateColorSpaceA, 1, 0, <!!= NULL>, pRTCC_ColorSpace
CreateStdHook CreateColorSpaceW, 1, 0, <!!= NULL>, pRTCC_ColorSpace

; ------------------------------------------------------------------------------

DestroyStdHook DeleteObject, 1, 1, <!!= FALSE>, pRTCC_Pen, pRTCC_Brush, pRTCC_Bitmap, \
                                                pRTCC_Region, pRTCC_Font, pRTCC_Palette, \
                                                pRTCC_ColorSpace, pRTCC_Image

; ——————————————————————————————————————————————————————————————————————————————————————————————————

CreateStdHook CreateCursor, 7, 0, <!!= NULL>, pRTCC_Cursor

HookCount = HookCount + 1
externdef pRTCC_Cursor:$ObjPtr(RTC_Collection)
.data
pHookLoadCursorA   $ObjPtr(IAT_Hook)    NULL

.code

MyLoadCursorA proc hInst:HANDLE, pCursorName:POINTER
  push pCursorName
  push hInst
  mov xax, pHookLoadCursorA
  call [xax].$Obj(IAT_Hook).pEntry
  .if dResGuardEnabled == TRUE
    push xax
    m2z dResGuardEnabled
    .if eax != NULL
      .if hInst != NULL
        invoke EntryCreate, pRTCC_Cursor, $invoke(GetCallStack), [xsp]
      .endif
    .else
      OCall FailColl::Collection.Insert, $invoke(GetCallStack)
    .endif
    mov dResGuardEnabled, TRUE
    pop xax
  .endif
  ret
MyLoadCursorA endp

HookCount = HookCount + 1
externdef pRTCC_Cursor:$ObjPtr(RTC_Collection)
.data
pHookLoadCursorW   $ObjPtr(IAT_Hook)    NULL

.code
MyLoadCursorW proc hInst:HANDLE, pCursorName:POINTER
  push pCursorName
  push hInst
  mov xax, pHookLoadCursorW
  call [xax].$Obj(IAT_Hook).pEntry
  .if dResGuardEnabled == TRUE
    push xax
    m2z dResGuardEnabled
    .if eax != NULL
      .if hInst != NULL
        invoke EntryCreate, pRTCC_Cursor, $invoke(GetCallStack), [xsp]
      .endif
    .else
      OCall FailColl::Collection.Insert, $invoke(GetCallStack)
    .endif
    mov dResGuardEnabled, TRUE
    pop xax
  .endif
  ret
MyLoadCursorW endp

CreateStdHook LoadCursorFromFileA, 1, 0, <!!= NULL>, pRTCC_Cursor
CreateStdHook LoadCursorFromFileW, 1, 0, <!!= NULL>, pRTCC_Cursor

externdef pCollIcon:POINTER
;DestroyCursor and DestroyIcon use the same API
DestroyStdHook DestroyCursor, 1, 1, <!!= FALSE>, pRTCC_Cursor, pRTCC_Icon, pRTCC_Image

; ——————————————————————————————————————————————————————————————————————————————————————————————————

CreateStdHook CreateIcon, 7, 0, <!!= NULL>, pRTCC_Icon
CreateStdHook CreateIconIndirect, 1, 0, <!!= NULL>, pRTCC_Icon
CreateStdHook CreateIconFromResource, 4, 0, <!!= NULL>, pRTCC_Icon
CreateStdHook CreateIconFromResourceEx, 7, 0, <!!= NULL>, pRTCC_Icon
CreateStdHook LoadIconA, 2, 0, <!!= NULL>, pRTCC_Icon
CreateStdHook LoadIconW, 2, 0, <!!= NULL>, pRTCC_Icon
CreateStdHook ExtractAssociatedIconA, 3, 0, <!!= NULL>, pRTCC_Icon
CreateStdHook ExtractAssociatedIconW, 3, 0, <!!= NULL>, pRTCC_Icon
;DestroyCursor and DestroyIcon use the same API
DestroyStdHook DestroyIcon, 1, 1, <!!= FALSE>, pRTCC_Icon, pRTCC_Cursor, pRTCC_Image

; ——————————————————————————————————————————————————————————————————————————————————————————————————

CreateStdHook CreateMenu, 0, 0, <!!= NULL>, pRTCC_Menu
CreateStdHook CreatePopupMenu, 0, 0, <!!= NULL>, pRTCC_Menu
CreateStdHook LoadMenuA, 2, 0, <!!= NULL>, pRTCC_Menu
CreateStdHook LoadMenuW, 2, 0, <!!= NULL>, pRTCC_Menu
CreateStdHook LoadMenuIndirectA, 1, 0, <!!= NULL>, pRTCC_Menu
CreateStdHook LoadMenuIndirectW, 1, 0, <!!= NULL>, pRTCC_Menu
DestroyStdHook DestroyMenu, 1, 1, <!!= FALSE>, pRTCC_Menu

; ——————————————————————————————————————————————————————————————————————————————————————————————————

CreateStdHook CreateMetaFileA, 1, 0, <!!= NULL>, pRTCC_MetaFile
CreateStdHook CreateMetaFileW, 1, 0, <!!= NULL>, pRTCC_MetaFile
CreateStdHook GetMetaFileA, 1, 0, <!!= NULL>, pRTCC_MetaFile
CreateStdHook GetMetaFileW, 1, 0, <!!= NULL>, pRTCC_MetaFile
DestroyStdHook DeleteMetaFile, 1, 1, <!!= FALSE>, pRTCC_MetaFile

; ——————————————————————————————————————————————————————————————————————————————————————————————————

CreateStdHook CreateEnhMetaFileA, 1, 0, <!!= NULL>, pRTCC_EnhMetaFile
CreateStdHook CreateEnhMetaFileW, 1, 0, <!!= NULL>, pRTCC_EnhMetaFile
CreateStdHook GetEnhMetaFileA, 1, 0, <!!= NULL>, pRTCC_EnhMetaFile
CreateStdHook GetEnhMetaFileW, 1, 0, <!!= NULL>, pRTCC_EnhMetaFile
DestroyStdHook DeleteEnhMetaFile, 1, 1, <!!= FALSE>, pRTCC_EnhMetaFile

; ——————————————————————————————————————————————————————————————————————————————————————————————————

CreateStdHook CreateDCA, 4, 0, <!!= NULL>, pRTCC_DeviceContext
CreateStdHook CreateDCW, 4, 0, <!!= NULL>, pRTCC_DeviceContext
CreateStdHook CreateCompatibleDC, 1, 0, <!!= NULL>, pRTCC_DeviceContext
CreateStdHook CreateICA, 4, 0, <!!= NULL>, pRTCC_DeviceContext
CreateStdHook CreateICW, 4, 0, <!!= NULL>, pRTCC_DeviceContext
DestroyStdHook DeleteDC, 1, 1, <!!= FALSE>, pRTCC_DeviceContext

; ——————————————————————————————————————————————————————————————————————————————————————————————————

CreateStdHook CreateAcceleratorTableA, 2, 0, <!!= NULL>, pRTCC_AccTable
CreateStdHook CreateAcceleratorTableW, 2, 0, <!!= NULL>, pRTCC_AccTable
CreateStdHook CopyAcceleratorTableA, 3, 0, <!!= NULL>, pRTCC_AccTable
CreateStdHook CopyAcceleratorTableW, 3, 0, <!!= NULL>, pRTCC_AccTable
CreateStdHook LoadAcceleratorsA, 2, 0, <!!= NULL>, pRTCC_AccTable
CreateStdHook LoadAcceleratorsW, 2, 0, <!!= NULL>, pRTCC_AccTable
DestroyStdHook DestroyAcceleratorTable, 1, 1, <!!= FALSE>, pRTCC_AccTable

; ——————————————————————————————————————————————————————————————————————————————————————————————————

CreateStdHook CreateDesktopA, 6, 0, <!!= NULL>, pRTCC_Desktop
CreateStdHook CreateDesktopW, 6, 0, <!!= NULL>, pRTCC_Desktop
DestroyStdHook CloseDesktop, 1, 1, <!!= FALSE>, pRTCC_Desktop

; ——————————————————————————————————————————————————————————————————————————————————————————————————

CreateStdHook CreateWindowStationA, 4, 0, <!!= NULL>, pRTCC_WindowStation
CreateStdHook CreateWindowStationW, 4, 0, <!!= NULL>, pRTCC_WindowStation
DestroyStdHook CloseWindowStation, 1, 1, <!!= FALSE>, pRTCC_WindowStation

; ——————————————————————————————————————————————————————————————————————————————————————————————————

CreateStdHook CreateFileA, 7, 0, <!!= INVALID_HANDLE_VALUE>, pRTCC_File
CreateStdHook CreateFileW, 7, 0, <!!= INVALID_HANDLE_VALUE>, pRTCC_File

; ------------------------------------------------------------------------------

CreateStdHook CreateEventA, 4, 0, <!!= ERROR_ALREADY_EXISTS>, pRTCC_Event
CreateStdHook CreateEventW, 4, 0, <!!= ERROR_ALREADY_EXISTS>, pRTCC_Event
CreateStdHook OpenEventA, 3, 0, <!!= NULL>, pRTCC_Event
CreateStdHook OpenEventW, 3, 0, <!!= NULL>, pRTCC_Event

; ------------------------------------------------------------------------------

CreateStdHook CreateFileMappingA, 6, 0, <!!= ERROR_ALREADY_EXISTS>, pRTCC_FileMapping
CreateStdHook CreateFileMappingW, 6, 0, <!!= ERROR_ALREADY_EXISTS>, pRTCC_FileMapping

; ------------------------------------------------------------------------------

CreateStdHook CreateMutexA, 3, 0, <!!= ERROR_ALREADY_EXISTS>, pRTCC_Mutex
CreateStdHook CreateMutexW, 3, 0, <!!= ERROR_ALREADY_EXISTS>, pRTCC_Mutex
CreateStdHook OpenMutexA, 3, 0, <!!= NULL>, pRTCC_Mutex
CreateStdHook OpenMutexW, 3, 0, <!!= NULL>, pRTCC_Mutex

; ------------------------------------------------------------------------------

HookCount = HookCount + 1
externdef pRTCC_Pipe:$ObjPtr(RTC_Collection)
.data
pHookCreatePipe   $ObjPtr(IAT_Hook)     NULL

.code
MyCreatePipe proc hReadPipe:HANDLE, hWritePipe:HANDLE, pPipeAttr:POINTER, dSize:DWORD
  push XWORD ptr dSize
  push pPipeAttr
  push hWritePipe
  push hReadPipe
  mov xax, pHookCreatePipe
  call [xax].$Obj(IAT_Hook).pEntry
  .if dResGuardEnabled == TRUE
    push xax
    m2z dResGuardEnabled
    .if eax != FALSE
      invoke EntryCreate, pRTCC_Pipe, $invoke(GetCallStack), hReadPipe
      invoke EntryCreate, pRTCC_Pipe, $invoke(GetCallStack), hWritePipe
    .else
      OCall FailColl::Collection.Insert, $invoke(GetCallStack)
    .endif
    mov dResGuardEnabled, TRUE
    pop xax
  .endif
  ret
MyCreatePipe endp

CreateStdHook CreateNamedPipeA, 8, 0, <!!= INVALID_HANDLE_VALUE>, pRTCC_Pipe
CreateStdHook CreateNamedPipeW, 8, 0, <!!= INVALID_HANDLE_VALUE>, pRTCC_Pipe

; ------------------------------------------------------------------------------

CreateStdHook CreateProcessA, 10, -10, <!!= FALSE>, pRTCC_Process
CreateStdHook CreateProcessW, 10, -10, <!!= FALSE>, pRTCC_Process
CreateStdHook OpenProcess, 3, 0, <!!= NULL>, pRTCC_Process

; ------------------------------------------------------------------------------

CreateStdHook CreateThread, 6, 0, <!!= NULL>, pRTCC_Thread
CreateStdHook CreateRemoteThread, 3, 0, <!!= NULL>, pRTCC_Thread

; ------------------------------------------------------------------------------

CreateStdHook CreateSemaphoreA, 4, 0, <!!= ERROR_ALREADY_EXISTS>, pRTCC_Semaphore
CreateStdHook CreateSemaphoreW, 4, 0, <!!= ERROR_ALREADY_EXISTS>, pRTCC_Semaphore
CreateStdHook OpenSemaphoreA, 3, 0, <!!= NULL>, pRTCC_Semaphore
CreateStdHook OpenSemaphoreW, 3, 0, <!!= NULL>, pRTCC_Semaphore

; ------------------------------------------------------------------------------

DestroyStdHook CloseHandle, 1, 1, <!!= FALSE>, \
               pRTCC_File, pRTCC_Event, pRTCC_FileMapping, pRTCC_Mutex, pRTCC_Pipe, pRTCC_Process, \
               pRTCC_Thread, pRTCC_Semaphore

; ——————————————————————————————————————————————————————————————————————————————————————————————————

HookCount = HookCount + 1
externdef pRTCC_Timer:$ObjPtr(RTC_Collection)
.data
pHookSetTimer   $ObjPtr(IAT_Hook)   NULL

.code
MySetTimer proc uses xbx hWnd:HANDLE, idTimer:DWORD, uTimeout:DWORD, tmprc:POINTER
  push tmprc
  push XWORD ptr uTimeout
  push XWORD ptr idTimer
  push hWnd
  mov xax, pHookSetTimer
  call [xax].$Obj(IAT_Hook).pEntry
  .if dResGuardEnabled == TRUE
    push xax
    m2z dResGuardEnabled
    .if eax != NULL
      invoke GetCallStack
      .if hWnd == NULL
        mov ebx, [xsp]
      .else
        mov ebx, idTimer
      .endif
      invoke EntryCreate, pRTCC_Timer, xax, xbx
    .else
      OCall FailColl::Collection.Insert, $invoke(GetCallStack)
    .endif
    mov dResGuardEnabled, TRUE
    pop xax
  .endif
  ret
MySetTimer endp

DestroyStdHook KillTimer, 2, 2, <!!= FALSE>, pRTCC_Timer

; ——————————————————————————————————————————————————————————————————————————————————————————————————

CreateStdHook GetDC, 1, 0, <!!= NULL>, pRTCC_DisplayDeviceContext
CreateStdHook GetDCEx, 3, 0, <!!= NULL>, pRTCC_DisplayDeviceContext
CreateStdHook GetWindowDC, 1, 0, <!!= NULL>, pRTCC_DisplayDeviceContext
DestroyStdHook ReleaseDC, 2, 2, <!!= FALSE>, pRTCC_DisplayDeviceContext

; ——————————————————————————————————————————————————————————————————————————————————————————————————

CreateStdHook LoadKeyboardLayoutA, 2, 0, <!!= NULL>, pRTCC_KeyboardLayout
CreateStdHook LoadKeyboardLayoutW, 2, 0, <!!= NULL>, pRTCC_KeyboardLayout
DestroyStdHook UnloadKeyboardLayout, 1, 1, <!!= FALSE>, pRTCC_KeyboardLayout

; ——————————————————————————————————————————————————————————————————————————————————————————————————

CreateStdHook LoadLibraryA, 1, 0, <!!= NULL>, pRTCC_Library
CreateStdHook LoadLibraryW, 1, 0, <!!= NULL>, pRTCC_Library
CreateStdHook LoadLibraryExA, 3, 0, <!!= NULL>, pRTCC_Library
CreateStdHook LoadLibraryExW, 3, 0, <!!= NULL>, pRTCC_Library
DestroyStdHook FreeLibrary, 1, 1, <!!= FALSE>, pRTCC_Library

; ——————————————————————————————————————————————————————————————————————————————————————————————————

CreateStdHook OpenPrinterA, 3, 0, <!!= NULL>, pRTCC_Printer
CreateStdHook OpenPrinterW, 3, 0, <!!= NULL>, pRTCC_Printer
CreateStdHook AddPrinterA, 3, 0, <!!= NULL>, pRTCC_Printer
CreateStdHook AddPrinterW, 3, 0, <!!= NULL>, pRTCC_Printer
DestroyStdHook ClosePrinter, 1, 1, <!!= FALSE>, pRTCC_Printer

; ——————————————————————————————————————————————————————————————————————————————————————————————————

CreateStdHook RegCreateKeyA, 3, -3, <== ERROR_SUCCESS>, pRTCC_RegKey
CreateStdHook RegCreateKeyW, 3, -3, <== ERROR_SUCCESS>, pRTCC_RegKey
CreateStdHook RegCreateKeyExA, 9, -8, <== ERROR_SUCCESS>, pRTCC_RegKey
CreateStdHook RegCreateKeyExW, 9, -8, <== ERROR_SUCCESS>, pRTCC_RegKey
DestroyStdHook RegCloseKey, 1, 1, <== ERROR_SUCCESS>, pRTCC_RegKey

; ——————————————————————————————————————————————————————————————————————————————————————————————————

CreateStdHook BeginUpdateResourceA, 2, 0, <!!= NULL>, pRTCC_UpdateResource
CreateStdHook BeginUpdateResourceW, 2, 0, <!!= NULL>, pRTCC_UpdateResource
DestroyStdHook EndUpdateResourceA, 2, 1, <!!= FALSE>, pRTCC_UpdateResource
DestroyStdHook EndUpdateResourceW, 2, 1, <!!= FALSE>, pRTCC_UpdateResource

; ——————————————————————————————————————————————————————————————————————————————————————————————————

CreateStdHook CreateMailslotA, 4, 0, <!!= INVALID_HANDLE_VALUE>, pRTCC_Mailslot
CreateStdHook CreateMailslotW, 4, 0, <!!= INVALID_HANDLE_VALUE>, pRTCC_Mailslot

; ——————————————————————————————————————————————————————————————————————————————————————————————————

CreateStdHook FindFirstFileA, 2, 0, <!!= INVALID_HANDLE_VALUE>, pRTCC_FindFirst
CreateStdHook FindFirstFileW, 2, 0, <!!= INVALID_HANDLE_VALUE>, pRTCC_FindFirst
DestroyStdHook FindClose, 1, 1, <!!= FALSE>, pRTCC_FindFirst

; ——————————————————————————————————————————————————————————————————————————————————————————————————

CreateStdHook OpenEventLogA, 2, 0, <!!= NULL>, pRTCC_EventLog
CreateStdHook OpenEventLogW, 2, 0, <!!= NULL>, pRTCC_EventLog
DestroyStdHook CloseEventLog, 1, 1, <!!= FALSE>, pRTCC_EventLog

; ——————————————————————————————————————————————————————————————————————————————————————————————————

CreateStdHook InitializeCriticalSection, 1, 1, <|| 0FFFFFFFFh>, pRTCC_CriticalSection
DestroyStdHook DeleteCriticalSection, 1, 1, <|| 0FFFFFFFFh>, pRTCC_CriticalSection

; ——————————————————————————————————————————————————————————————————————————————————————————————————

CreateCountedHook macro HookName:req, ArgCount:req, Counter:req, SuccessCond:req, pRTC_Coll:req
  local ArgStr, Cnt

  HookCount = HookCount + 1                               ;;Keep track of the hook count
  externdef pRTC_Coll:$ObjPtr(RTC_Collection)             ;;The RTC_Collection will be definend later
  .data
  pHook&HookName&   $ObjPtr(IAT_Hook)   NULL

  ArgStr textequ <>                                       ;;Prepare argument list
  Cnt = 0
  repeat ArgCount
    Cnt = Cnt + 1
    ArgStr CatStr ArgStr, <, >, <Arg>, %Cnt, <:XWORD>
  endm

  .code
  My&HookName& proc ArgStr                                ;;Procedure declaration
    repeat ArgCount                                       ;;Push arguments
      @CatStr(<push Arg>, %Cnt)
      Cnt = Cnt - 1
    endm
    mov xax, pHook&HookName&
    call [xax].$Obj(IAT_Hook).pEntry                      ;;Call API
    .if dResGuardEnabled == TRUE
      push xax                                            ;;Store API return value
      m2z dResGuardEnabled
      .if eax SuccessCond
        invoke GetCallStack                               ;;Generate Caller collection
        invoke EntryCreate, pRTC_Coll, xax, Counter
        inc Counter
      .else
        OCall FailColl::Collection.Insert, $invoke(GetCallStack)
      .endif
      mov dResGuardEnabled, TRUE
      pop xax                                             ;;Restore API return value
    .endif
    ret
  My&HookName& endp
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————

DestroyCountedHook macro HookName:req, ArgCount:req, Counter:req, SuccessCond:req, pRTC_Coll_List:vararg
  local ArgStr, Cnt, Coll, @@

  HookCount = HookCount + 1                               ;;Keep track of the hook count
  .data
  pHook&HookName&   $ObjPtr(IAT_Hook)   NULL

  ArgStr textequ <>
  Cnt = 0
  repeat ArgCount
    Cnt = Cnt + 1
    ArgStr CatStr ArgStr, <, >, <Arg>, %Cnt, <:DWORD>
  endm

  .code
  My&HookName& proc ArgStr                                ;;Procedure declaration
    repeat ArgCount
      @CatStr(<push Arg>, %Cnt)
      Cnt = Cnt - 1
    endm
    mov xax, pHook&HookName&
    call [xax].$Obj(IAT_Hook).pEntry                      ;;Call API

    .if dResGuardEnabled == TRUE
      push xax                                            ;;Store API return value
      m2z dResGuardEnabled
      .if eax SuccessCond
        dec Counter
        for pColl, <pRTC_Coll_List>                      ;;Search in all specified RTC_Collection objects
          @CatStr(<invoke EntryDelete, >, pColl, <, >, Counter)
          test eax, eax
          jnz @@                                          ;;Exit if found
        endm
      .else
        OCall FailColl::Collection.Insert, $invoke(GetCallStack)
      .endif
@@:
      mov dResGuardEnabled, TRUE
      pop xax                                             ;;Restore API return value
    .endif
    ret
  My&HookName& endp
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
.data
OleInitializeCount  DWORD  0

.code
CreateCountedHook OleInitialize, 1, OleInitializeCount, <== S_OK>, pRTCC_OleInitialization
DestroyCountedHook OleUninitialize, 0, OleInitializeCount, <|| 0FFFFFFFFh>, pRTCC_OleInitialization

; ——————————————————————————————————————————————————————————————————————————————————————————————————
.data
CoInitializeCount  DWORD  0

.code
CreateCountedHook CoInitialize, 1, CoInitializeCount, <== S_OK>, pRTCC_CoInitialization
CreateCountedHook CoInitializeEx, 2, CoInitializeCount, <== S_OK>, pRTCC_CoInitialization
DestroyCountedHook CoUninitialize, 0, CoInitializeCount, <|| 0FFFFFFFFh>, pRTCC_CoInitialization

; ==================================================================================================

;CheckApiHook proc pIAT32Hook:POINTER, pAPI:POINTER
;  mov xcx, pIAT_Hook
;  xor eax, eax
;  mov xdx, [xcx].$Obj(IAT_Hook).pEntry
;  .if xdx == pAPI
;    inc eax
;  .endif
;  ret
;CheckApiHook endp
;
;ValidateHook proc uses xbx pModuleName:POINTER, pProcName:POINTER
;  invoke GetProcAddress, $invoke(GetModuleHandle, pModuleName), pProcName
;  .if xax
;    OCall pRTC_Coll::Collection.FirstThat, offset CheckApiHook, xax
;    .if xax
;      DbgStr pProcName
;      DbgText "API already hooked"
;    .endif
;  .endif
;  ret
;ValidateHook endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————

NewHook macro HookProc:req, HookLib:req
;  invoke ValidateHook, "&HookLib&.dll", "&HookProc&"
% New IAT_Hook
  mov pHook&HookProc&, xax                                ;;Save the IAT_Hook in this var
  OCall xax::IAT_Hook.Init, offset HookColl, $OfsCStrA("&HookLib&.dll"), $OfsCStrA("&HookProc&"), \
                            offset My&HookProc&, FALSE
  mov xax, pHook&HookProc&
  .if [xax].$Obj(IAT_Hook).dErrorCode != OBJ_OK
    Destroy xax
  .else
    OCall HookColl::Collection.Insert, xax                ;;and in a dedicated HookColl collection
  .endif
endm

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
; Name:      ResGuardDone
; Purpose:   RegGuard finalization and freeing of allocated resorces.
;            It restores the original APIs.
; Arguments: None.
; Return:    Nothing.

ResGuardDone proc
  m2z dResGuardEnabled
  OCall HookColl::Collection.Done                         ;Destroy all Hooks and restore APIs
  OCall RcrcColl::Collection.Done                         ;Destroy collected resorces data
  OCall FailColl::Collection.Done                         ;Destroy Error collection
  ret
ResGuardDone endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Name:      ResGuardInit
; Purpose:   ResGuard initialization. It hooks the following APIs from the IAT.
; Arguments: None.
; Return:    Nothing.

ResGuardInit proc
  m2z dResGuardEnabled

  OCall HookColl::Collection.Init, NULL, HookCount, 10, COL_MAX_CAPACITY
  OCall RcrcColl::Collection.Init, NULL, HookCount, 10, COL_MAX_CAPACITY
  OCall FailColl::Collection.Init, NULL, 10, 10, COL_MAX_CAPACITY

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
ResGuardInit endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Name:      ResGuardShow
; Purpose:   Visualisation of resource usage.
; Arguments: xbx -> output ANSI buffer.
; Return:    Nothing.

ShowCollectionData macro ResCollectionPointer, NamePointer
  local szLeakOutput

  CStr szLeakOutput, NamePointer, " cur. = %3li, max. = %5li, tot. = %5li"
  mov xdi, ResCollectionPointer
  .if (dHasLeaks == FALSE) && ([xdi].$Obj(RTC_Collection).dCount > 0)
    inc dHasLeaks
  .endif
  .if ([xdi].$Obj(RTC_Collection).dTotCount > 0)
    invoke wsprintf, xbx, offset szLeakOutput, [xdi].$Obj(RTC_Collection).dCount, \
                     [xdi].$Obj(RTC_Collection).dMaxCount, [xdi].$Obj(RTC_Collection).dTotCount
    invoke DbgOutText, xbx, DbgColorForeground, DbgColorBackground, \
                       DBG_EFFECT_NORMAL or DBG_EFFECT_NEWLINE, offset wLeakReport
    OCall xdi::RTC_Collection.ForEach, offset EntryShowCallers, NULL, NULL
  .endif
endm

ResGuardShow proc uses xbx xdi
  local cBuffer[256]:CHR, dHasLeaks:DWORD

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
  .if ([xdi].$Obj(Collection).dCount > 0)
    invoke wsprintf, xbx, $OfsCStr("Hooked API fails:   %li"), [xdi].$Obj(Collection).dCount
    invoke DbgOutText, xbx, DbgColorForeground, DbgColorBackground, \
                       DBG_EFFECT_NORMAL or DBG_EFFECT_NEWLINE, offset wLeakReport
    OCall FailColl::Collection.ForEach, offset ShowCallers, NULL, NULL
  .endif
  .if (dHasLeaks == FALSE) && ([xdi].$Obj(Collection).dCount > 0)
    inc dHasLeaks
  .endif

  DbgLine offset wLeakReport
  mov dResGuardEnabled, TRUE

  .if dHasLeaks
    invoke MessageBoxW, 0, offset wDebugStart, offset wLeakReport, MB_YESNO or MB_ICONEXCLAMATION
    .if eax == IDYES
      int 3
    .endif
  .endif

  ret
ResGuardShow endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Name:      ResGuardStart
; Purpose:   Begins resource monitoring.
; Arguments: None.
; Return:    Nothing.

ResetCollData proc pResColl:$ObjPtr(RTC_Collection), xDummy1:XWORD, xDummy2:XWORD
  OCall pResColl::RTC_Collection.DisposeAll
  mov xcx, pResColl
  xor eax, eax
  mov [xcx].$Obj(RTC_Collection).dMaxCount, eax
  mov [xcx].$Obj(RTC_Collection).dTotCount, eax
  ret
ResetCollData endp

ResGuardStart proc
  if TARGET_BITNESS eq 32
    mov pAppBaseFrame, ebp
  else
    mov pAppBaseFrame, rsp
  endif
  m2z dResGuardEnabled
  OCall RcrcColl::Collection.ForEach, offset ResetCollData, NULL, NULL
  mov dResGuardEnabled, TRUE
  ret
ResGuardStart endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Name:      ResGuardStop
; Purpose:   Ends resource monitoring.
; Arguments: None.
; Return:    Nothing.

ResGuardStop proc
  m2z dResGuardEnabled
  ret
ResGuardStop endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Name:      Start (DllMain)
; Purpose:   Entry procedure in the DLL.
; Arguments: Arg1: Instance handle.
;            Arg2: Call reason.
;            Arg3: Reserved.
; Return:    TRUE if handled.

start proc public hDllInstance:HANDLE, dReason:DWORD, xReserved:XWORD
  mov eax, dReason
  .if eax == DLL_PROCESS_ATTACH
    SysInit hDllInstance
    invoke ResGuardInit
  .elseif eax == DLL_PROCESS_DETACH
    SysDone
    invoke ResGuardDone
  .endif
  xor eax, eax
  inc eax
  ret
start endp

end
