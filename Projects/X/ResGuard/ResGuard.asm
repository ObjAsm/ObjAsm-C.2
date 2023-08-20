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
SysSetup OOP, DLL32, ANSI_STRING, DEBUG(WND)

% include &IncPath&Windows\ImageHlp.inc

% includelib &LibPath&Windows\ImageHlp.lib


CStr cLeakReport, "Resource Leakage Report"
CStr cDebugStart, "Use the debugger to find the lines of", CR, LF, \
                  "code that use the listed resources.", CR, LF, CR, LF,\
                  "Do you want to start the debugger now?"

HookCount = 0

.data
  dResGuardEnabled    DWORD     FALSE
  pHookColl           POINTER   NULL
  pRcrcColl           POINTER   NULL
  pErrColl            POINTER   NULL
  xBasePointer        XWORD     0

MakeObjects Primer, Stream, Collection, DataCollection, IAT_Hook

if TARGET_BITNESS eq 32
  % include &MacPath&Exception32.inc                      ;Exception Handling macros
else
  % include &MacPath&Exception64.inc                      ;Exception Handling macros
endif

; ——————————————————————————————————————————————————————————————————————————————————————————————————

Object CallData,, Primer
  RedefineMethod  Init,         POINTER, POINTER, XWORD

  DefineVariable  pCallerColl,  POINTER,  NULL
  DefineVariable  xData,        XWORD,    0
ObjectEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————

Object ResCollection,, Collection
  RedefineMethod  InsertAt,     DWORD, POINTER

  DefineVariable  dMaxCount,    DWORD,    0
  DefineVariable  dTotCount,    DWORD,    0
ObjectEnd


.code
; ==================================================================================================
;    CallData implementation
; ==================================================================================================

Method CallData.Init, uses xsi, pOwner:POINTER, pCallerColl:POINTER, xData:XWORD
  SetObject xsi
  ACall xsi.Init, pOwner
  m2m [xsi].pCallerColl, pCallerColl, xax
  m2m [xsi].xData, xData, xcx
MethodEnd


; ==================================================================================================
;    ResCollection implementation
; ==================================================================================================

Method ResCollection.InsertAt, uses xsi, dIndex:DWORD, pItem:POINTER
  SetObject xsi
  ACall xsi.InsertAt, dIndex, pItem
  inc [xsi].dTotCount
  mov eax, [xsi].dCount
  .if eax > [xsi].dMaxCount
    mov [xsi].dMaxCount, eax
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————

;CreateExceptionHandler GetCallSequence_ExceptionHandler, , EXCEPTION_ACCESS_VIOLATION

GetCallSequence proc
  local pCallerColl:POINTER

;  Try GetCallSequence_ExceptionHandler
    mov pCallerColl, $New(DataCollection)
    OCall xax::DataCollection.Init, NULL, 10, 10, COL_MAX_CAPACITY
    mov xax, [xbp]                                        ;Remove last caller of the current proc
    .while (xax != xBasePointer)                             ;App start reached
      push [xax]                                          ;Exceptions can occure here!
      OCall pCallerColl::DataCollection.Insert, POINTER ptr [xax + sizeof(XWORD)] ;Store return address
      pop xax                                             ;Get previous EBP in EAX
    .endw
;  Catch GetCallSequence_ExceptionHandler
    OCall pCallerColl::DataCollection.Insert, NULL
;  endc GetCallSequence_ExceptionHandler
  mov xax, pCallerColl                                    ;Return -> caller collection
  ret
GetCallSequence endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————

EntryCreate proc pCallDataColl:POINTER, pCallerColl:POINTER, xData:XWORD
  New CallData
  OCall pCallDataColl::Collection.Insert, xax
  OCall xax::CallData.Init, pCallDataColl, pCallerColl, xData
  ret
EntryCreate endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————

EntryIsIt proc pItem:POINTER, xData:XWORD
  mov xcx, pItem
  xor eax, eax
  mov xdx, xData
  .if xdx == [xcx].$Obj(CallData).xData
    inc eax
  .endif
  ret
EntryIsIt endp

EntryDelete proc pCallDataColl:POINTER, xData:XWORD
  OCall pCallDataColl::Collection.LastThat, offset EntryIsIt, xData, NULL
  .if xax
    OCall pCallDataColl::Collection.Dispose, xax
    xor eax, eax
    inc eax
  .endif
  ret
EntryDelete endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————

ShowCaller proc uses xbx pCaller:POINTER, pLastCaller:POINTER
  local bBuffer[256]:byte

  lea xbx, bBuffer
  .if pCaller == NULL
    invoke StrCopy, xbx, $OfsCStr(" EOS")
  .else
    invoke wsprintf, xbx, $OfsCStr(" %08Xh"), pCaller
  .endif
  mov xcx, pCaller
  .if xcx != pLastCaller
    invoke StrCat, xbx, $OfsCStr(" «")
  .endif
  invoke DbgOutText, xbx, DbgColorComment, DbgColorBackground, DBG_EFFECT_NORMAL, offset cLeakReport
  xor eax, eax
  .if pCaller == NULL
    inc eax
  .endif
  ret
ShowCaller endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————

ShowCallers proc uses xsi pCallerColl:POINTER, xDummy1:XWORD, xDummy2:XWORD
  mov xsi, pCallerColl
  .if [xsi].$Obj(Collection).dCount > 0
    invoke DbgOutText, $OfsCStr(" ·"), DbgColorComment, DbgColorBackground, DBG_EFFECT_NORMAL, offset cLeakReport
    mov eax, [xsi].$Obj(Collection).dCount
    dec eax
    OCall xsi::DataCollection.ItemAt, eax
    OCall xsi::DataCollection.FirstThat, offset ShowCaller, xax, NULL
    invoke DbgOutText, offset cCRLF, DbgColorComment, DbgColorBackground, DBG_EFFECT_NORMAL, offset cLeakReport
  .endif
  ret
ShowCallers endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————

EntryShowCallers proc pCallData:POINTER, xDummy1:XWORD, xDummy2:XWORD
  mov xcx, pCallData
  invoke ShowCallers, [xcx].$Obj(CallData).pCallerColl, xDummy1, xDummy2
  ret
EntryShowCallers endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————

StdCreateHook macro HookName:req, Args:req, IDArg:req, SuccessCond:req, HookColl:req
  local ArgStr, Cnt

  HookCount = HookCount + 1                               ;;Keep track of the hook count
  externdef HookColl:POINTER                              ;;HookColl will be definend later
  .data
  pHook&HookName&   POINTER   NULL

  ArgStr textequ <>                                       ;;Prepare argument list
  Cnt = 0
  repeat Args
    Cnt = Cnt + 1
    ArgStr CatStr ArgStr, <, >, <Arg>, %Cnt, <:XWORD>
  endm

  .code
  My&HookName& proc ArgStr                                ;;Procedure declaration
    repeat Args                                           ;;Push arguments
      @CatStr(<push Arg>, %Cnt)
      Cnt = Cnt - 1
    endm
    mov xax, pHook&HookName&
    call [xax].$Obj(IAT_Hook).pEntry                      ;;Call API
    .if dResGuardEnabled == TRUE
      push xax                                            ;;Store API return value
      and dResGuardEnabled, FALSE
      .if xax SuccessCond
        invoke GetCallSequence                            ;;Generate Caller collection
        if IDArg gt 0
          invoke EntryCreate, HookColl, xax, Arg&IDArg&
        elseif IDArg eq 0
          invoke EntryCreate, HookColl, xax, [xsp]
        else
          Cnt = 0 - IDArg
          mov xdx, xax
          mov xax, @CatStr(<Arg>, %Cnt)
          invoke EntryCreate, HookColl, xdx, [xax]
        endif
      .else
        OCall pErrColl::Collection.Insert, $invoke(GetCallSequence)
      .endif
      mov dResGuardEnabled, TRUE
      pop xax                                             ;;Restore API return value
    .endif
    ret
  My&HookName& endp
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————

StdDestroyHook macro HookName:req, Args:req, IDArg:req, SuccessCond:=<>, HookColls:vararg
  local ArgStr, Cnt, Coll, @@

  HookCount = HookCount + 1                               ;;Keep track of the hook count
  .data
  pHook&HookName&   POINTER   NULL

  ArgStr textequ <>
  Cnt = 0
  repeat Args
    Cnt = Cnt + 1
    ArgStr CatStr ArgStr, <, >, <Arg>, %Cnt, <:XWORD>
  endm

  .code
  My&HookName& proc ArgStr                                ;;Procedure declaration
    repeat Args
      @CatStr(<push Arg>, %Cnt)
      Cnt = Cnt - 1
    endm
    mov xax, pHook&HookName&
    call [xax].$Obj(IAT_Hook).pEntry                      ;;Call API

    .if dResGuardEnabled == TRUE
      push xax                                            ;;Store API return value
      and dResGuardEnabled, FALSE
      ifnb <SuccessCond>
        ;Check success condition
        .if xax SuccessCond
          for Coll, <HookColls>                           ;;Search in all specified collections
            @CatStr(<invoke EntryDelete, >, Coll, <, Arg>, IDArg)
            .if eax
              jmp @@                                      ;;Exit if found
            .endif
          endm
        .else
          OCall pErrColl::Collection.Insert, $invoke(GetCallSequence)
        .endif
      else
        ;Always succeed
        for Coll, <HookColls>                             ;;Search in all specified collections
          @CatStr(<invoke EntryDelete, >, Coll, <, Arg>, IDArg)
          .if eax
            jmp @@                                        ;;Exit if found
          .endif
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

StdCreateHook HeapAlloc, 3, 0, <!!= NULL>, pCollHeapMemBlock
StdDestroyHook HeapFree, 3, 3, <!!= FALSE>, pCollHeapMemBlock

HookCount = HookCount + 1
.data
pHookHeapReAlloc  POINTER  NULL

.code
MyHeapReAlloc proc hHeap:HANDLE, dFlags:DWORD, pMem:POINTER, dBytes:DWORD
  push XWORD ptr dBytes                                             ;Prepare stack frame
  push pMem
  push XWORD ptr dFlags
  push hHeap
  mov xax, pHookHeapReAlloc
  call [xax].$Obj(IAT_Hook).pEntry
  .if dResGuardEnabled == TRUE
    .if eax != FALSE
      and dResGuardEnabled, FALSE
      push xax
      invoke EntryDelete, pCollHeapMemBlock, pMem           ;First delete that Entry
      invoke EntryCreate, pCollHeapMemBlock, $invoke(GetCallSequence), [xsp]
    .else
      OCall pErrColl::Collection.Insert, $invoke(GetCallSequence)
    .endif
    pop xax
    mov dResGuardEnabled, TRUE
  .endif
  ret
MyHeapReAlloc endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————

StdCreateHook GlobalAlloc, 2, 0, <!!= NULL>, pCollGlobalMemBlock
StdDestroyHook GlobalFree, 1, 1, <== NULL>, pCollGlobalMemBlock

HookCount = HookCount + 1
.data
pHookGlobalReAlloc  POINTER NULL

.code
MyGlobalReAlloc proc hMem:POINTER, dBytes:DWORD, dFlags:DWORD
  push XWORD ptr dFlags
  push XWORD ptr dBytes                                             ;Prepare stack frame
  push hMem
  mov xax, pHookGlobalReAlloc
  call [xax].$Obj(IAT_Hook).pEntry
  .if dResGuardEnabled == TRUE
    push xax
    and dResGuardEnabled, FALSE
    .if eax != FALSE
      invoke EntryDelete, pCollGlobalMemBlock, hMem       ;First delete that Entry
      invoke EntryCreate, pCollGlobalMemBlock, $invoke(GetCallSequence), [xsp]
    .else
      OCall pErrColl::Collection.Insert, $invoke(GetCallSequence)
    .endif
    mov dResGuardEnabled, TRUE
    pop xax
  .endif
  ret
MyGlobalReAlloc endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————

StdCreateHook LocalAlloc, 2, 0, <!!= NULL>, pCollLocalMemBlock
StdDestroyHook LocalFree, 1, 1, <== NULL>, pCollLocalMemBlock

HookCount = HookCount + 1
.data
pHookLocalReAlloc  POINTER NULL

.code
MyLocalReAlloc proc hMem:POINTER, dBytes:DWORD, dFlags:DWORD
  push XWORD ptr dFlags
  push XWORD ptr dBytes                                             ;Prepare stack frame
  push hMem
  mov xax, pHookLocalReAlloc
  call [xax].$Obj(IAT_Hook).pEntry
  .if dResGuardEnabled == TRUE
    push xax
    and dResGuardEnabled, FALSE
    .if eax != FALSE
      invoke EntryDelete, pCollLocalMemBlock, hMem        ;First delete that Entry
      invoke EntryCreate, pCollLocalMemBlock, $invoke(GetCallSequence), [xsp]
    .else
      OCall pErrColl::Collection.Insert, $invoke(GetCallSequence)
    .endif
    mov dResGuardEnabled, TRUE
    pop xax
  .endif
  ret
MyLocalReAlloc endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————

StdCreateHook CoTaskMemAlloc, 1, 0, <!!= NULL>, pCollCoTaskMemBlock
StdDestroyHook CoTaskMemFree, 1, 1, <>, pCollCoTaskMemBlock

HookCount = HookCount + 1
.data
pHookCoTaskMemRealloc  POINTER NULL

.code
MyCoTaskMemRealloc proc pMem:POINTER, dBytes:DWORD
  push XWORD ptr dBytes                                             ;Prepare stack frame
  push XWORD ptr pMem
  mov xax, pHookCoTaskMemRealloc
  call [xax].$Obj(IAT_Hook).pEntry
  .if dResGuardEnabled == TRUE
    push xax
    and dResGuardEnabled, FALSE
    .if eax != NULL
      invoke EntryDelete, pCollCoTaskMemBlock, pMem        ;First delete that Entry
      invoke EntryCreate, pCollCoTaskMemBlock, $invoke(GetCallSequence), [xsp]
    .else
      OCall pErrColl::Collection.Insert, $invoke(GetCallSequence)
    .endif
    mov dResGuardEnabled, TRUE
    pop xax
  .endif
  ret
MyCoTaskMemRealloc endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————

StdCreateHook VirtualAlloc, 4, 0, <!!= NULL>, pCollVirtualMemBlock
StdDestroyHook VirtualFree, 3, 1, <!!= FALSE>, pCollVirtualMemBlock

; ——————————————————————————————————————————————————————————————————————————————————————————————————

StdCreateHook SysAllocString, 1, 0, <!!= NULL>, pCollSysString
StdCreateHook SysAllocStringLen, 2, 0, <!!= NULL>, pCollSysString
StdCreateHook SysAllocStringByteLen, 2, 0, <!!= NULL>, pCollSysString
StdCreateHook SysReAllocString, 2, 0, <!!= FALSE>, pCollSysString
StdCreateHook SysReAllocStringLen, 3, 0, <!!= FALSE>, pCollSysString
StdDestroyHook SysFreeString, 1, 1, <!!= FALSE>, pCollSysString

; ——————————————————————————————————————————————————————————————————————————————————————————————————

StdCreateHook BeginPaint, 2, 2, <!!= NULL>, pCollPaintStruct
StdDestroyHook EndPaint, 2, 2, <!!= FALSE>, pCollPaintStruct

; ——————————————————————————————————————————————————————————————————————————————————————————————————

StdCreateHook CreatePen, 3, 0, <!!= NULL>, pCollPen
StdCreateHook CreatePenIndirect, 1, 0, <!!= NULL>, pCollPen

; ------------------------------------------------------------------------------

StdCreateHook CreateSolidBrush, 1, 0, <!!= NULL>, pCollBrush
StdCreateHook CreateDIBPatternBrush, 2, 0, <!!= NULL>, pCollBrush
StdCreateHook CreateDIBPatternBrushPt, 2, 0, <!!= NULL>, pCollBrush
StdCreateHook CreateHatchBrush, 2, 0, <!!= NULL>, pCollBrush
StdCreateHook CreatePatternBrush, 1, 0, <!!= NULL>, pCollBrush
StdCreateHook CreateBrushIndirect, 1, 0, <!!= NULL>, pCollBrush

; ------------------------------------------------------------------------------

StdCreateHook CreateBitmap, 5, 0, <!!= NULL>, pCollBitmap
StdCreateHook CreateBitmapIndirect, 1, 0, <!!= NULL>, pCollBitmap
StdCreateHook CreateCompatibleBitmap, 3, 0, <!!= NULL>, pCollBitmap
StdCreateHook CreateDIBitmap, 6, 0, <!!= NULL>, pCollBitmap
StdCreateHook CreateDIBSection, 6, 0, <!!= NULL>, pCollBitmap
StdCreateHook CreateDiscardableBitmap, 3, 0, <!!= NULL>, pCollBitmap
StdCreateHook LoadBitmapA, 2, 0, <!!= NULL>, pCollBitmap
StdCreateHook LoadBitmapW, 2, 0, <!!= NULL>, pCollBitmap

; ------------------------------------------------------------------------------

StdCreateHook CreateEllipticRgn, 4, 0, <!!= NULL>, pCollRegion
StdCreateHook CreateEllipticRgnIndirect, 1, 0, <!!= NULL>, pCollRegion
StdCreateHook CreatePenDataRegion, 2, 0, <!!= NULL>, pCollRegion
StdCreateHook CreatePolygonRgn, 3, 0, <!!= NULL>, pCollRegion
StdCreateHook CreatePolyPolygonRgn, 4, 0, <!!= NULL>, pCollRegion
StdCreateHook CreateRectRgn, 4, 0, <!!= NULL>, pCollRegion
StdCreateHook CreateRectRgnIndirect, 1, 0, <!!= NULL>, pCollRegion
StdCreateHook CreateRoundRectRgn, 6, 0, <!!= NULL>, pCollRegion
StdDestroyHook SetWindowRgn, 3, 2, <!!= FALSE>, pCollRegion      ;This region is destroyed by the window!

; ------------------------------------------------------------------------------

StdCreateHook CopyImage, 5, 0, <!!= NULL>, pCollImage
StdCreateHook LoadImageA, 6, 0, <!!= NULL>, pCollImage
StdCreateHook LoadImageW, 6, 0, <!!= NULL>, pCollImage

; ------------------------------------------------------------------------------

StdCreateHook CreateFontA, 14, 0, <!!= NULL>, pCollFont
StdCreateHook CreateFontW, 14, 0, <!!= NULL>, pCollFont
StdCreateHook CreateFontIndirectA, 1, 0, <!!= NULL>, pCollFont
StdCreateHook CreateFontIndirectW, 1, 0, <!!= NULL>, pCollFont

; ------------------------------------------------------------------------------

StdCreateHook CreatePalette, 1, 0, <!!= NULL>, pCollPalette
StdCreateHook CreateHalftonePalette, 1, 0, <!!= NULL>, pCollPalette

; ------------------------------------------------------------------------------

StdCreateHook CreateColorSpaceA, 1, 0, <!!= NULL>, pCollColorSpace
StdCreateHook CreateColorSpaceW, 1, 0, <!!= NULL>, pCollColorSpace

; ------------------------------------------------------------------------------

StdDestroyHook DeleteObject, 1, 1, <!!= FALSE>, pCollPen, pCollBrush, pCollBitmap, pCollRegion,  \
                             pCollFont, pCollPalette, pCollColorSpace, pCollImage

; ——————————————————————————————————————————————————————————————————————————————————————————————————

StdCreateHook CreateCursor, 7, 0, <!!= NULL>, pCollCursor

HookCount = HookCount + 1
externdef pCollCursor:POINTER
.data
pHookLoadCursorA   POINTER   NULL

.code

MyLoadCursorA proc hInst:HANDLE, pCursorName:POINTER
  push pCursorName
  push hInst
  mov xax, pHookLoadCursorA
  call [xax].$Obj(IAT_Hook).pEntry
  .if dResGuardEnabled == TRUE
    push xax
    and dResGuardEnabled, FALSE
    .if eax != NULL
      .if hInst != NULL
        invoke EntryCreate, pCollCursor, $invoke(GetCallSequence), [xsp]
      .endif
    .else
      OCall pErrColl::Collection.Insert, $invoke(GetCallSequence)
    .endif
    mov dResGuardEnabled, TRUE
    pop xax
  .endif
  ret
MyLoadCursorA endp

HookCount = HookCount + 1
externdef pCollCursor:POINTER
.data
pHookLoadCursorW   POINTER   NULL

.code
MyLoadCursorW proc hInst:HANDLE, pCursorName:POINTER
  push pCursorName
  push hInst
  mov xax, pHookLoadCursorW
  call [xax].$Obj(IAT_Hook).pEntry
  .if dResGuardEnabled == TRUE
    push xax
    and dResGuardEnabled, FALSE
    .if eax != NULL
      .if hInst != NULL
        invoke EntryCreate, pCollCursor, $invoke(GetCallSequence), [xsp]
      .endif
    .else
      OCall pErrColl::Collection.Insert, $invoke(GetCallSequence)
    .endif
    mov dResGuardEnabled, TRUE
    pop xax
  .endif
  ret
MyLoadCursorW endp

StdCreateHook LoadCursorFromFileA, 1, 0, <!!= NULL>, pCollCursor
StdCreateHook LoadCursorFromFileW, 1, 0, <!!= NULL>, pCollCursor

externdef pCollIcon:POINTER
;DestroyCursor and DestroyIcon use the same API
StdDestroyHook DestroyCursor, 1, 1, <!!= FALSE>, pCollCursor, pCollIcon, pCollImage

; ——————————————————————————————————————————————————————————————————————————————————————————————————

StdCreateHook CreateIcon, 7, 0, <!!= NULL>, pCollIcon
StdCreateHook CreateIconIndirect, 1, 0, <!!= NULL>, pCollIcon
StdCreateHook CreateIconFromResource, 4, 0, <!!= NULL>, pCollIcon
StdCreateHook CreateIconFromResourceEx, 7, 0, <!!= NULL>, pCollIcon
StdCreateHook LoadIconA, 2, 0, <!!= NULL>, pCollIcon
StdCreateHook LoadIconW, 2, 0, <!!= NULL>, pCollIcon
StdCreateHook ExtractAssociatedIconA, 3, 0, <!!= NULL>, pCollIcon
StdCreateHook ExtractAssociatedIconW, 3, 0, <!!= NULL>, pCollIcon
;DestroyCursor and DestroyIcon use the same API
StdDestroyHook DestroyIcon, 1, 1, <!!= FALSE>, pCollIcon, pCollCursor, pCollImage

; ——————————————————————————————————————————————————————————————————————————————————————————————————

StdCreateHook CreateMenu, 0, 0, <!!= NULL>, pCollMenu
StdCreateHook CreatePopupMenu, 0, 0, <!!= NULL>, pCollMenu
StdCreateHook LoadMenuA, 2, 0, <!!= NULL>, pCollMenu
StdCreateHook LoadMenuW, 2, 0, <!!= NULL>, pCollMenu
StdCreateHook LoadMenuIndirectA, 1, 0, <!!= NULL>, pCollMenu
StdCreateHook LoadMenuIndirectW, 1, 0, <!!= NULL>, pCollMenu
StdDestroyHook DestroyMenu, 1, 1, <!!= FALSE>, pCollMenu

; ——————————————————————————————————————————————————————————————————————————————————————————————————

StdCreateHook CreateMetaFileA, 1, 0, <!!= NULL>, pCollMetaFile
StdCreateHook CreateMetaFileW, 1, 0, <!!= NULL>, pCollMetaFile
StdCreateHook GetMetaFileA, 1, 0, <!!= NULL>, pCollMetaFile
StdCreateHook GetMetaFileW, 1, 0, <!!= NULL>, pCollMetaFile
StdDestroyHook DeleteMetaFile, 1, 1, <!!= FALSE>, pCollMetaFile

; ——————————————————————————————————————————————————————————————————————————————————————————————————

StdCreateHook CreateEnhMetaFileA, 1, 0, <!!= NULL>, pCollEnhMetaFile
StdCreateHook CreateEnhMetaFileW, 1, 0, <!!= NULL>, pCollEnhMetaFile
StdCreateHook GetEnhMetaFileA, 1, 0, <!!= NULL>, pCollEnhMetaFile
StdCreateHook GetEnhMetaFileW, 1, 0, <!!= NULL>, pCollEnhMetaFile
StdDestroyHook DeleteEnhMetaFile, 1, 1, <!!= FALSE>, pCollEnhMetaFile

; ——————————————————————————————————————————————————————————————————————————————————————————————————

StdCreateHook CreateDCA, 4, 0, <!!= NULL>, pCollDeviceContext
StdCreateHook CreateDCW, 4, 0, <!!= NULL>, pCollDeviceContext
StdCreateHook CreateCompatibleDC, 1, 0, <!!= NULL>, pCollDeviceContext
StdCreateHook CreateICA, 4, 0, <!!= NULL>, pCollDeviceContext
StdCreateHook CreateICW, 4, 0, <!!= NULL>, pCollDeviceContext
StdDestroyHook DeleteDC, 1, 1, <!!= FALSE>, pCollDeviceContext

; ——————————————————————————————————————————————————————————————————————————————————————————————————

StdCreateHook CreateAcceleratorTableA, 2, 0, <!!= NULL>, pCollAccTable
StdCreateHook CreateAcceleratorTableW, 2, 0, <!!= NULL>, pCollAccTable
StdCreateHook CopyAcceleratorTableA, 3, 0, <!!= NULL>, pCollAccTable
StdCreateHook CopyAcceleratorTableW, 3, 0, <!!= NULL>, pCollAccTable
StdCreateHook LoadAcceleratorsA, 2, 0, <!!= NULL>, pCollAccTable
StdCreateHook LoadAcceleratorsW, 2, 0, <!!= NULL>, pCollAccTable
StdDestroyHook DestroyAcceleratorTable, 1, 1, <!!= FALSE>, pCollAccTable

; ——————————————————————————————————————————————————————————————————————————————————————————————————

StdCreateHook CreateDesktopA, 6, 0, <!!= NULL>, pCollDesktop
StdCreateHook CreateDesktopW, 6, 0, <!!= NULL>, pCollDesktop
StdDestroyHook CloseDesktop, 1, 1, <!!= FALSE>, pCollDesktop

; ——————————————————————————————————————————————————————————————————————————————————————————————————

StdCreateHook CreateWindowStationA, 4, 0, <!!= NULL>, pCollWindowStation
StdCreateHook CreateWindowStationW, 4, 0, <!!= NULL>, pCollWindowStation
StdDestroyHook CloseWindowStation, 1, 1, <!!= FALSE>, pCollWindowStation

; ——————————————————————————————————————————————————————————————————————————————————————————————————

StdCreateHook CreateFileA, 7, 0, <!!= INVALID_HANDLE_VALUE>, pCollFile
StdCreateHook CreateFileW, 7, 0, <!!= INVALID_HANDLE_VALUE>, pCollFile

; ------------------------------------------------------------------------------

StdCreateHook CreateEventA, 4, 0, <!!= ERROR_ALREADY_EXISTS>, pCollEvent
StdCreateHook CreateEventW, 4, 0, <!!= ERROR_ALREADY_EXISTS>, pCollEvent
StdCreateHook OpenEventA, 3, 0, <!!= NULL>, pCollEvent
StdCreateHook OpenEventW, 3, 0, <!!= NULL>, pCollEvent

; ------------------------------------------------------------------------------

StdCreateHook CreateFileMappingA, 6, 0, <!!= ERROR_ALREADY_EXISTS>, pCollFileMapping
StdCreateHook CreateFileMappingW, 6, 0, <!!= ERROR_ALREADY_EXISTS>, pCollFileMapping

; ------------------------------------------------------------------------------

StdCreateHook CreateMutexA, 3, 0, <!!= ERROR_ALREADY_EXISTS>, pCollMutex
StdCreateHook CreateMutexW, 3, 0, <!!= ERROR_ALREADY_EXISTS>, pCollMutex
StdCreateHook OpenMutexA, 3, 0, <!!= NULL>, pCollMutex
StdCreateHook OpenMutexW, 3, 0, <!!= NULL>, pCollMutex

; ------------------------------------------------------------------------------

HookCount = HookCount + 1
externdef pCollPipe:POINTER
.data
pHookCreatePipe   POINTER   NULL

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
    and dResGuardEnabled, FALSE
    .if eax != FALSE
      invoke EntryCreate, pCollPipe, $invoke(GetCallSequence), hReadPipe
      invoke EntryCreate, pCollPipe, $invoke(GetCallSequence), hWritePipe
    .else
      OCall pErrColl::Collection.Insert, $invoke(GetCallSequence)
    .endif
    mov dResGuardEnabled, TRUE
    pop xax
  .endif
  ret
MyCreatePipe endp

StdCreateHook CreateNamedPipeA, 8, 0, <!!= INVALID_HANDLE_VALUE>, pCollPipe
StdCreateHook CreateNamedPipeW, 8, 0, <!!= INVALID_HANDLE_VALUE>, pCollPipe

; ------------------------------------------------------------------------------

StdCreateHook CreateProcessA, 10, -10, <!!= FALSE>, pCollProcess
StdCreateHook CreateProcessW, 10, -10, <!!= FALSE>, pCollProcess
StdCreateHook OpenProcess, 3, 0, <!!= NULL>, pCollProcess

; ------------------------------------------------------------------------------

StdCreateHook CreateThread, 6, 0, <!!= NULL>, pCollThread
StdCreateHook CreateRemoteThread, 3, 0, <!!= NULL>, pCollThread

; ------------------------------------------------------------------------------

StdCreateHook CreateSemaphoreA, 4, 0, <!!= ERROR_ALREADY_EXISTS>, pCollSemaphore
StdCreateHook CreateSemaphoreW, 4, 0, <!!= ERROR_ALREADY_EXISTS>, pCollSemaphore
StdCreateHook OpenSemaphoreA, 3, 0, <!!= NULL>, pCollSemaphore
StdCreateHook OpenSemaphoreW, 3, 0, <!!= NULL>, pCollSemaphore

; ------------------------------------------------------------------------------

StdDestroyHook CloseHandle, 1, 1, <!!= FALSE>, \
               pCollFile, pCollEvent, pCollFileMapping, pCollMutex, pCollPipe, pCollProcess, \
               pCollThread, pCollSemaphore

; ——————————————————————————————————————————————————————————————————————————————————————————————————

HookCount = HookCount + 1
externdef pCollTimer:POINTER
.data
pHookSetTimer  POINTER NULL

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
    and dResGuardEnabled, FALSE
    .if eax != NULL
      invoke GetCallSequence
      .if hWnd == NULL
        mov ebx, [xsp]
      .else
        mov ebx, idTimer
      .endif
      invoke EntryCreate, pCollTimer, xax, xbx
    .else
      OCall pErrColl::Collection.Insert, $invoke(GetCallSequence)
    .endif
    mov dResGuardEnabled, TRUE
    pop xax
  .endif
  ret
MySetTimer endp

StdDestroyHook KillTimer, 2, 2, <!!= FALSE>, pCollTimer

; ——————————————————————————————————————————————————————————————————————————————————————————————————

StdCreateHook GetDC, 1, 0, <!!= NULL>, pCollDisplayDeviceContext
StdCreateHook GetDCEx, 3, 0, <!!= NULL>, pCollDisplayDeviceContext
StdCreateHook GetWindowDC, 1, 0, <!!= NULL>, pCollDisplayDeviceContext
StdDestroyHook ReleaseDC, 2, 2, <!!= FALSE>, pCollDisplayDeviceContext

; ——————————————————————————————————————————————————————————————————————————————————————————————————

StdCreateHook LoadKeyboardLayoutA, 2, 0, <!!= NULL>, pCollKeyboardLayout
StdCreateHook LoadKeyboardLayoutW, 2, 0, <!!= NULL>, pCollKeyboardLayout
StdDestroyHook UnloadKeyboardLayout, 1, 1, <!!= FALSE>, pCollKeyboardLayout

; ——————————————————————————————————————————————————————————————————————————————————————————————————

StdCreateHook LoadLibraryA, 1, 0, <!!= NULL>, pCollLibrary
StdCreateHook LoadLibraryW, 1, 0, <!!= NULL>, pCollLibrary
StdCreateHook LoadLibraryExA, 3, 0, <!!= NULL>, pCollLibrary
StdCreateHook LoadLibraryExW, 3, 0, <!!= NULL>, pCollLibrary
StdDestroyHook FreeLibrary, 1, 1, <!!= FALSE>, pCollLibrary

; ——————————————————————————————————————————————————————————————————————————————————————————————————

StdCreateHook OpenPrinterA, 3, 0, <!!= NULL>, pCollPrinter
StdCreateHook OpenPrinterW, 3, 0, <!!= NULL>, pCollPrinter
StdCreateHook AddPrinterA, 3, 0, <!!= NULL>, pCollPrinter
StdCreateHook AddPrinterW, 3, 0, <!!= NULL>, pCollPrinter
StdDestroyHook ClosePrinter, 1, 1, <!!= FALSE>, pCollPrinter

; ——————————————————————————————————————————————————————————————————————————————————————————————————

StdCreateHook RegCreateKeyA, 3, -3, <== ERROR_SUCCESS>, pCollRegKey
StdCreateHook RegCreateKeyW, 3, -3, <== ERROR_SUCCESS>, pCollRegKey
StdCreateHook RegCreateKeyExA, 9, -8, <== ERROR_SUCCESS>, pCollRegKey
StdCreateHook RegCreateKeyExW, 9, -8, <== ERROR_SUCCESS>, pCollRegKey
StdDestroyHook RegCloseKey, 1, 1, <== ERROR_SUCCESS>, pCollRegKey

; ——————————————————————————————————————————————————————————————————————————————————————————————————

StdCreateHook BeginUpdateResourceA, 2, 0, <!!= NULL>, pCollUpdateResource
StdCreateHook BeginUpdateResourceW, 2, 0, <!!= NULL>, pCollUpdateResource
StdDestroyHook EndUpdateResourceA, 2, 1, <!!= FALSE>, pCollUpdateResource
StdDestroyHook EndUpdateResourceW, 2, 1, <!!= FALSE>, pCollUpdateResource

; ——————————————————————————————————————————————————————————————————————————————————————————————————

StdCreateHook CreateMailslotA, 4, 0, <!!= INVALID_HANDLE_VALUE>, pCollMailslot
StdCreateHook CreateMailslotW, 4, 0, <!!= INVALID_HANDLE_VALUE>, pCollMailslot

; ——————————————————————————————————————————————————————————————————————————————————————————————————

StdCreateHook FindFirstFileA, 2, 0, <!!= INVALID_HANDLE_VALUE>, pCollFindFirst
StdCreateHook FindFirstFileW, 2, 0, <!!= INVALID_HANDLE_VALUE>, pCollFindFirst
StdDestroyHook FindClose, 1, 1, <!!= FALSE>, pCollFindFirst

; ——————————————————————————————————————————————————————————————————————————————————————————————————

StdCreateHook OpenEventLogA, 2, 0, <!!= NULL>, pCollEventLog
StdCreateHook OpenEventLogW, 2, 0, <!!= NULL>, pCollEventLog
StdDestroyHook CloseEventLog, 1, 1, <!!= FALSE>, pCollEventLog

; ——————————————————————————————————————————————————————————————————————————————————————————————————

StdCreateHook InitializeCriticalSection, 1, 1, <|| 0FFFFFFFFh>, pCollCriticalSection
StdDestroyHook DeleteCriticalSection, 1, 1, <|| 0FFFFFFFFh>, pCollCriticalSection

; ——————————————————————————————————————————————————————————————————————————————————————————————————

StdCreateCountedHook macro HookName:req, Args:req, Counter:req, SuccessCond:req, HookColl:req
  local ArgStr, Cnt

  HookCount = HookCount + 1                               ;;Keep track of the hook count
  externdef HookColl:POINTER                              ;;HookColl will be definend later
  .data
  pHook&HookName&   POINTER   NULL

  ArgStr textequ <>                                       ;;Prepare argument list
  Cnt = 0
  repeat Args
    Cnt = Cnt + 1
    ArgStr CatStr ArgStr, <, >, <Arg>, %Cnt, <:XWORD>
  endm

  .code
  My&HookName& proc ArgStr                                ;;Procedure declaration
    repeat Args                                           ;;Push arguments
      @CatStr(<push Arg>, %Cnt)
      Cnt = Cnt - 1
    endm
    mov xax, pHook&HookName&
    call [xax].$Obj(IAT_Hook).pEntry                      ;;Call API
    .if dResGuardEnabled == TRUE
      push xax                                            ;;Store API return value
      and dResGuardEnabled, FALSE
      .if eax SuccessCond
        invoke GetCallSequence                            ;;Generate Caller collection
        invoke EntryCreate, HookColl, xax, Counter
        inc Counter
      .else
        OCall pErrColl::Collection.Insert, $invoke(GetCallSequence)
      .endif
      mov dResGuardEnabled, TRUE
      pop xax                                             ;;Restore API return value
    .endif
    ret
  My&HookName& endp
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————

StdDestroyCountedHook macro HookName:req, Args:req, Counter:req, SuccessCond:req, HookColls:vararg
  local ArgStr, Cnt, Coll, @@

  HookCount = HookCount + 1                               ;;Keep track of the hook count
  .data
  pHook&HookName&   POINTER   NULL

  ArgStr textequ <>
  Cnt = 0
  repeat Args
    Cnt = Cnt + 1
    ArgStr CatStr ArgStr, <, >, <Arg>, %Cnt, <:DWORD>
  endm

  .code
  My&HookName& proc ArgStr                                ;;Procedure declaration
    repeat Args
      @CatStr(<push Arg>, %Cnt)
      Cnt = Cnt - 1
    endm
    mov xax, pHook&HookName&
    call [xax].$Obj(IAT_Hook).pEntry                      ;;Call API

    .if dResGuardEnabled == TRUE
      push xax                                            ;;Store API return value
      and dResGuardEnabled, FALSE
      .if eax SuccessCond
        dec Counter
        for Coll, <HookColls>                             ;;Search in all specified collections
          @CatStr(<invoke EntryDelete, >, Coll, <, >, Counter)
          .if eax
            jmp @@                                        ;;Exit if found
          .endif
        endm
      .else
        OCall pErrColl::Collection.Insert, $invoke(GetCallSequence)
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
StdCreateCountedHook OleInitialize, 1, OleInitializeCount, <== S_OK>, pCollOleInitialization
StdDestroyCountedHook OleUninitialize, 0, OleInitializeCount, <|| 0FFFFFFFFh>, pCollOleInitialization

; ——————————————————————————————————————————————————————————————————————————————————————————————————
.data
CoInitializeCount  DWORD  0

.code
StdCreateCountedHook CoInitialize, 1, CoInitializeCount, <== S_OK>, pCollCoInitialization
StdCreateCountedHook CoInitializeEx, 2, CoInitializeCount, <== S_OK>, pCollCoInitialization
StdDestroyCountedHook CoUninitialize, 0, CoInitializeCount, <|| 0FFFFFFFFh>, pCollCoInitialization

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
;    OCall pHookColl::Collection.FirstThat, offset CheckApiHook, xax
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
  OCall xax::IAT_Hook.Init, pHookColl, $OfsCStr("&HookLib&.dll"), $OfsCStr("&HookProc&"), offset My&HookProc&, FALSE
  mov xax, pHook&HookProc&
  .if [xax].$Obj(IAT_Hook).dErrorCode != OBJ_OK
    Destroy xax
  .else
    OCall pHookColl::Collection.Insert, xax               ;;  and in a collection (pHookColl)
  .endif
endm

NewColl macro ResCollName:req, ColSize:req
  .data
  pColl&ResCollName&  POINTER  NULL

  .code
  New ResCollection
  mov pColl&ResCollName&, xax
  OCall pRcrcColl::Collection.Insert, xax
  OCall xax::ResCollection.Init, pRcrcColl, %ColSize, %ColSize, COL_MAX_CAPACITY
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Name:      ResGuardDone
; Purpose:   RegGuard finalization and freeing of allocated resorces.
;            It restores the original APIs.
; Arguments: None.
; Return:    Nothing.

ResGuardDone proc
  and dResGuardEnabled, FALSE
  Destroy pHookColl                                       ;Destroy all Hooks and restore APIs
  Destroy pRcrcColl                                       ;Destroy collected resorces data
  Destroy pErrColl                                        ;Destroy Error collection
  ret
ResGuardDone endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Name:      ResGuardInit
; Purpose:   ResGuard initialization. It hooks the following APIs from the IAT.
; Arguments: None.
; Return:    Nothing.

ResGuardInit proc
  and dResGuardEnabled, FALSE

  mov xBasePointer, xbp

  mov pHookColl, $New(Collection)
  OCall xax::Collection.Init, NULL, HookCount, 10, COL_MAX_CAPACITY
  mov pRcrcColl, $New(Collection)
  OCall xax::Collection.Init, NULL, HookCount, 10, COL_MAX_CAPACITY
  mov pErrColl, $New(Collection)
  OCall xax::Collection.Init, NULL, 10, 10, COL_MAX_CAPACITY

  NewColl PaintStruct, 10
  NewHook BeginPaint, User32
  NewHook EndPaint, User32

  NewColl Pen, 10
  NewHook CreatePen, GDI32
  NewHook CreatePenIndirect, GDI32

  NewColl Brush, 10
  NewHook CreateSolidBrush, GDI32
  NewHook CreateDIBPatternBrush, GDI32
  NewHook CreateDIBPatternBrushPt, GDI32
  NewHook CreateHatchBrush, GDI32
  NewHook CreatePatternBrush, GDI32
  NewHook CreateBrushIndirect, GDI32

  NewColl Bitmap, 10
  NewHook CreateBitmap, GDI32
  NewHook CreateBitmapIndirect, GDI32
  NewHook CreateCompatibleBitmap, GDI32
  NewHook CreateDIBitmap, GDI32
  NewHook CreateDIBSection, GDI32
  NewHook CreateDiscardableBitmap, GDI32
  NewHook LoadBitmapA, User32
  NewHook LoadBitmapW, User32

  NewColl Image, 10
  NewHook LoadImageA, User32
  NewHook LoadImageW, User32
  NewHook CopyImage, User32

  NewColl Region, 10
  NewHook CreateEllipticRgn, GDI32
  NewHook CreateEllipticRgnIndirect, GDI32
  NewHook CreatePenDataRegion, GDI32
  NewHook CreatePolygonRgn, GDI32
  NewHook CreatePolyPolygonRgn, GDI32
  NewHook CreateRectRgn, GDI32
  NewHook CreateRectRgnIndirect, GDI32
  NewHook CreateRoundRectRgn, GDI32
  NewHook SetWindowRgn, User32

  NewColl Font, 10
  NewHook CreateFontA, GDI32
  NewHook CreateFontW, GDI32
  NewHook CreateFontIndirectA, GDI32
  NewHook CreateFontIndirectW, GDI32

  NewColl Palette, 10
  NewHook CreatePalette, GDI32
  NewHook CreateHalftonePalette, GDI32

  NewColl ColorSpace, 10
  NewHook CreateColorSpaceA, GDI32
  NewHook CreateColorSpaceW, GDI32

  NewHook DeleteObject, GDI32

  NewColl Cursor, 10
  NewHook CreateCursor, User32
  NewHook DestroyCursor, User32                 ;DestroyIcon and DestroyCursor use the same API!

  NewColl Icon, 10
  NewHook CreateIcon, User32
  NewHook CreateIconIndirect, User32
  NewHook CreateIconFromResource, User32
  NewHook CreateIconFromResourceEx, User32
  NewHook LoadIconA, User32
  NewHook LoadIconW, User32
  NewHook ExtractAssociatedIconA, Shell32
  NewHook ExtractAssociatedIconW, Shell32
  NewHook DestroyIcon, User32                   ;DestroyIcon and DestroyCursor use the same API!

  NewColl Menu, 10
  NewHook CreateMenu, User32
  NewHook CreatePopupMenu, User32
  NewHook LoadMenuA, User32
  NewHook LoadMenuW, User32
  NewHook LoadMenuIndirectA, User32
  NewHook LoadMenuIndirectW, User32
  NewHook DestroyMenu, User32

  NewColl Timer, 10
  NewHook SetTimer, User32
  NewHook KillTimer, User32

  NewColl MetaFile, 10
  NewHook CreateMetaFileA, GDI32
  NewHook CreateMetaFileW, GDI32
  NewHook GetMetaFileA, GDI32
  NewHook GetMetaFileW, GDI32
  NewHook DeleteMetaFile, GDI32

  NewColl EnhMetaFile, 10
  NewHook CreateEnhMetaFileA, GDI32
  NewHook CreateEnhMetaFileW, GDI32
  NewHook GetEnhMetaFileA, GDI32
  NewHook GetEnhMetaFileW, GDI32
  NewHook DeleteEnhMetaFile, GDI32

  NewColl DeviceContext, 10
  NewHook CreateDCA, GDI32
  NewHook CreateDCW, GDI32
  NewHook CreateCompatibleDC, GDI32
  NewHook CreateICA, GDI32
  NewHook CreateICW, GDI32
  NewHook DeleteDC, GDI32

  NewColl DisplayDeviceContext, 10
  NewHook GetDC, User32
  NewHook GetDCEx, User32
  NewHook GetWindowDC, User32
  NewHook ReleaseDC, User32

  NewColl AccTable, 10
  NewHook CreateAcceleratorTableA, User32
  NewHook CreateAcceleratorTableW, User32
  NewHook CopyAcceleratorTableA, User32
  NewHook CopyAcceleratorTableW, User32
  NewHook LoadAcceleratorsA, User32
  NewHook LoadAcceleratorsW, User32
  NewHook DestroyAcceleratorTable, User32

  NewColl KeyboardLayout, 10
  NewHook LoadKeyboardLayoutA, User32
  NewHook LoadKeyboardLayoutW, User32
  NewHook UnloadKeyboardLayout, User32

  NewColl Desktop, 10
  NewHook CreateDesktopA, User32
  NewHook CreateDesktopW, User32
  NewHook CloseDesktop, User32

  NewColl Library, 10
  NewHook LoadLibraryA, Kernel32
  NewHook LoadLibraryW, Kernel32
  NewHook LoadLibraryExA, Kernel32
  NewHook LoadLibraryExW, Kernel32
  NewHook FreeLibrary, Kernel32

  NewColl WindowStation, 10
  NewHook CreateWindowStationA, User32
  NewHook CreateWindowStationW, User32
  NewHook CloseWindowStation, User32

  NewColl File, 10
  NewHook CreateFileA, Kernel32
  NewHook CreateFileW, Kernel32

  NewColl Event, 10
  NewHook CreateEventA, Kernel32
  NewHook CreateEventW, Kernel32
  NewHook OpenEventA, Kernel32
  NewHook OpenEventW, Kernel32

  NewColl FileMapping, 10
  NewHook CreateFileMappingA, Kernel32
  NewHook CreateFileMappingW, Kernel32

  NewColl Mutex, 10
  NewHook CreateMutexA, Kernel32
  NewHook CreateMutexW, Kernel32
  NewHook OpenMutexA, Kernel32
  NewHook OpenMutexW, Kernel32

  NewColl Pipe, 10
  NewHook CreatePipe, Kernel32
  NewHook CreateNamedPipeA, Kernel32
  NewHook CreateNamedPipeW, Kernel32

  NewColl Process, 10
  NewHook CreateProcessA, Kernel32
  NewHook CreateProcessW, Kernel32
  NewHook OpenProcess, Kernel32

  NewColl Thread, 10
  NewHook CreateThread, Kernel32
  NewHook CreateRemoteThread, Kernel32

  NewColl Semaphore, 10
  NewHook CreateSemaphoreA, Kernel32
  NewHook CreateSemaphoreW, Kernel32
  NewHook OpenSemaphoreA, Kernel32
  NewHook OpenSemaphoreW, Kernel32

  NewHook CloseHandle, Kernel32

  NewColl Printer, 10
  NewHook OpenPrinterA, WinSpool
  NewHook OpenPrinterW, WinSpool
  NewHook AddPrinterA, WinSpool
  NewHook AddPrinterW, WinSpool
  NewHook ClosePrinter, WinSpool

  NewColl RegKey, 10
  NewHook RegCreateKeyA, AdvApi32
  NewHook RegCreateKeyW, AdvApi32
  NewHook RegCreateKeyExA, AdvApi32
  NewHook RegCreateKeyExW, AdvApi32
  NewHook RegCloseKey, AdvApi32

  NewColl UpdateResource, 10
  NewHook BeginUpdateResourceA, Kernel32
  NewHook BeginUpdateResourceW, Kernel32
  NewHook EndUpdateResourceA, Kernel32
  NewHook EndUpdateResourceW, Kernel32

  NewColl Mailslot, 10
  NewHook CreateMailslotA, Kernel32
  NewHook CreateMailslotW, Kernel32

  NewColl FindFirst, 10
  NewHook FindFirstFileA, Kernel32
  NewHook FindFirstFileW, Kernel32
  NewHook FindClose, Kernel32

  NewColl EventLog, 10
  NewHook OpenEventLogA, Kernel32
  NewHook OpenEventLogW, Kernel32
  NewHook CloseEventLog, Kernel32

  NewColl CriticalSection, 10
  NewHook InitializeCriticalSection, Kernel32
  NewHook DeleteCriticalSection, Kernel32

  NewColl OleInitialization, 10
  NewHook OleInitialize, Ole32
  NewHook OleUninitialize, Ole32

  NewColl CoInitialization, 10
  NewHook CoInitialize, Ole32
  NewHook CoInitializeEx, Ole32
  NewHook CoUninitialize, Ole32

  NewColl SysString, 10
  NewHook SysAllocString, OleAuto
  NewHook SysAllocStringLen, OleAuto
  NewHook SysAllocStringByteLen, OleAuto
  NewHook SysReAllocString, OleAuto
  NewHook SysReAllocStringLen, OleAuto
  NewHook SysFreeString, OleAuto

  NewColl CoTaskMemBlock, 100
  NewHook CoTaskMemAlloc, Ole32
  NewHook CoTaskMemRealloc, Ole32
  NewHook CoTaskMemFree, Ole32

  NewColl VirtualMemBlock, 100
  NewHook VirtualAlloc, Kernel32
  NewHook VirtualFree, Kernel32

  NewColl LocalMemBlock, 100
  NewHook LocalFree, Kernel32
  NewHook LocalReAlloc, Kernel32
  NewHook LocalAlloc, Kernel32

  NewColl GlobalMemBlock, 100
  NewHook GlobalFree, Kernel32
  NewHook GlobalReAlloc, Kernel32
  NewHook GlobalAlloc, Kernel32

  NewColl HeapMemBlock, 100
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
  .if (dHasLeaks == FALSE) && ([xdi].$Obj(ResCollection).dCount > 0)
    inc dHasLeaks
  .endif
  .if ([xdi].$Obj(ResCollection).dTotCount > 0)
    invoke wsprintf, xbx, offset szLeakOutput, [xdi].$Obj(ResCollection).dCount, \
                     [xdi].$Obj(ResCollection).dMaxCount, [xdi].$Obj(ResCollection).dTotCount
    invoke DbgOutText, xbx, DbgColorComment, DbgColorBackground, \
                       DBG_EFFECT_NORMAL or DBG_EFFECT_NEWLINE, \
                       offset cLeakReport
    OCall xdi::ResCollection.ForEach, offset EntryShowCallers, NULL, NULL
  .endif
endm

ResGuardShow proc uses xbx xdi
  local cBuffer[256]:CHR, dHasLeaks:DWORD

  and dResGuardEnabled, FALSE
  and dHasLeaks, FALSE
  lea xbx, cBuffer

  ; -----------------------------------------------------------------------------------
  ShowCollectionData pCollVirtualMemBlock,      "Virtual Mem-Blocks:"
  ShowCollectionData pCollGlobalMemBlock,       "Global Mem-Blocks: "
  ShowCollectionData pCollLocalMemBlock,        "Local Mem-Blocks:  "
  ShowCollectionData pCollHeapMemBlock,         "Heap Mem-Blocks:   "
  ShowCollectionData pCollCoTaskMemBlock,       "CoTaskMem-Blocks:  "
  ShowCollectionData pCollSysString,            "System BStrings:   "
  ShowCollectionData pCollPen,                  "GDI Pens:          "
  ShowCollectionData pCollBrush,                "GDI Brushes:       "
  ShowCollectionData pCollBitmap,               "GDI Bitmaps:       "
  ShowCollectionData pCollImage,                "GDI Images:        "
  ShowCollectionData pCollRegion,               "GDI Regions:       "
  ShowCollectionData pCollFont,                 "GDI Fonts:         "
  ShowCollectionData pCollPalette,              "GDI Palettes:      "
  ShowCollectionData pCollColorSpace,           "GDI Color Spaces:  "
  ShowCollectionData pCollMetaFile,             "GDI MetaFiles:     "
  ShowCollectionData pCollEnhMetaFile,          "GDI EnhMetaFiles:  "
  ShowCollectionData pCollCursor,               "Cursors:           "
  ShowCollectionData pCollIcon,                 "Icons:             "
  ShowCollectionData pCollMenu,                 "Menus:             "
  ShowCollectionData pCollTimer,                "Timers:            "
  ShowCollectionData pCollAccTable,             "Accelerator Tables:"
  ShowCollectionData pCollDeviceContext,        "Device Contexts:   "
  ShowCollectionData pCollDisplayDeviceContext, "Display DCs:       "
  ShowCollectionData pCollPaintStruct,          "Paint Structures:  "
  ShowCollectionData pCollDesktop,              "Desktops:          "
  ShowCollectionData pCollKeyboardLayout,       "Keyboard Layouts:  "
  ShowCollectionData pCollWindowStation,        "Window Stations:   "
;  ShowCollectionData pCollLibrary,              "Libraries:         "
  ShowCollectionData pCollFile,                 "Files:             "
  ShowCollectionData pCollFileMapping,          "File Mappings:     "
  ShowCollectionData pCollEvent,                "Events:            "
  ShowCollectionData pCollMutex,                "Mutexes:           "
  ShowCollectionData pCollProcess,              "Processes:         "
  ShowCollectionData pCollThread,               "Threads:           "
  ShowCollectionData pCollSemaphore,            "Semaphores:        "
  ShowCollectionData pCollPrinter,              "Printers:          "
  ShowCollectionData pCollRegKey,               "Registry Keys:     "
  ShowCollectionData pCollUpdateResource,       "File Resources:    "
  ShowCollectionData pCollMailslot,             "Mail Slots:        "
  ShowCollectionData pCollFindFirst,            "Find First:        "
  ShowCollectionData pCollEventLog,             "Event Logs:        "
  ShowCollectionData pCollCriticalSection,      "Critical Sections: "
  ShowCollectionData pCollOleInitialization,    "OLE active library:"
  ShowCollectionData pCollCoInitialization,     "COM active library:"
  ; -----------------------------------------------------------------------------------

  mov xdi, pErrColl
  .if ([xdi].$Obj(Collection).dCount > 0)
    invoke wsprintf, xbx, $OfsCStr("Hooked API fails:   %li"), [xdi].$Obj(Collection).dCount
    invoke DbgOutText, xbx, DbgColorComment, DbgColorBackground, \
                       DBG_EFFECT_NORMAL or DBG_EFFECT_NEWLINE, \
                       offset cLeakReport
    OCall xdi::Collection.ForEach, offset ShowCallers, NULL, NULL
  .endif
  .if (dHasLeaks == FALSE) && ([xdi].$Obj(Collection).dCount > 0)
    inc dHasLeaks
  .endif

  DbgLine offset cLeakReport
  mov dResGuardEnabled, TRUE

  .if dHasLeaks
    invoke MessageBox, 0, offset cDebugStart, offset cLeakReport, MB_YESNO or MB_ICONEXCLAMATION
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

ResetCollData proc pResColl:POINTER, xDummy1:XWORD, xDummy2:XWORD
  OCall pResColl::ResCollection.DisposeAll
  mov xcx, pResColl
  xor eax, eax
  mov [xcx].$Obj(ResCollection).dMaxCount, eax
  mov [xcx].$Obj(ResCollection).dTotCount, eax
  ret
ResetCollData endp

ResGuardStart proc
  and dResGuardEnabled, FALSE
  OCall pRcrcColl::Collection.ForEach, offset ResetCollData, NULL, NULL
  invoke DbgOutText, $OfsCStr("ResGuard started"), \
                     DbgColorComment, DbgColorBackground, \
                     DBG_EFFECT_NORMAL or DBG_EFFECT_NEWLINE, offset cLeakReport
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
  invoke DbgOutText, $OfsCStr("ResGuard stopped"), \
                     DbgColorComment, DbgColorBackground, \
                     DBG_EFFECT_NORMAL or DBG_EFFECT_NEWLINE, offset cLeakReport
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
