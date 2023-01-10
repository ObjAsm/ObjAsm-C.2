; ==================================================================================================
; Title:      Dictionary.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm Dictionary demonstration application.
; Notes:      Version C.1.0, January 2022
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\Code\Macros\Model.inc
SysSetup OOP, NUI64, WIDE_STRING, DEBUG(WND)

% include &MacPath&fMath.inc

MakeObjects Primer, Stream, HashMap, Dictionary
MakeObjects Collection, SortedCollection, SortedStrCollectionW
MakeObjects StopWatch

DIC_SIZE = 1024

MY_DIC_ITEM struc
  pKey      PSTRING ?
  dValue    DWORD   ?
MY_DIC_ITEM ends
PMY_DIC_ITEM typedef ptr MY_DIC_ITEM

include WordList.inc

.code
start proc uses xbx xdi xsi
  local Dict:$Obj(Dictionary)
;  local Coll:$Obj(SortedStrCollectionW)
  local SW:$Obj(StopWatch), cBuffer[100]:CHR

  SysInit
  DbgClearAll

  New SW::StopWatch
  OCall SW::StopWatch.Init, NULL

  New Dict::Dictionary
  OCall Dict::Dictionary.Init, NULL, DIC_SIZE

  mov eax, MY_DIC_ITEM_COUNT
  DbgDec eax, "MY_DIC_ITEM_COUNT"
  DbgLine

  ;Insert items
  mov xdi, offset MY_DIC_ITEMS
  OCall SW::StopWatch.Start
  xor ebx, ebx
  .while ebx < MY_DIC_ITEM_COUNT
    mov [xdi].MY_DIC_ITEM.dValue, ebx
    OCall Dict::Dictionary.Insert, xdi
    add xdi, sizeof(MY_DIC_ITEM)
    inc ebx
  .endw
  OCall SW::StopWatch.Stop
  OCall SW::StopWatch.GetTimeStr, addr cBuffer
  DbgStr cBuffer, "µS"
  DbgDec Dict.dBucketsUsed
  DbgDec Dict.dCollisionCount
  DbgText "Dictionary item insertion ready"
  DbgLine

  ;Check number of used buckets
  mov xdi, Dict.pBuckets
  xor ebx, ebx
  xor esi, esi
  .while ebx < DIC_SIZE
    .if POINTER ptr [xdi] != HMP_BUCKET_EMPTY && POINTER ptr [xdi] != HMP_BUCKET_TOMBSTONE
      inc esi
    .endif
    add xdi, sizeof(POINTER)
    inc ebx
  .endw
  DbgDec Dict.dBucketsUsed
  DbgDec esi, "Used buckets"
  DbgText "Dictionary bucket check ready"
  DbgLine

  ;Search all items
  mov xdi, offset MY_DIC_ITEMS
  OCall SW::StopWatch.Reset
  OCall SW::StopWatch.Start
  xor ebx, ebx
  .while ebx < MY_DIC_ITEM_COUNT
    OCall Dict::Dictionary.Search, [xdi].MY_DIC_ITEM.pKey
    add xdi, sizeof(MY_DIC_ITEM)
    inc ebx
  .endw
  OCall SW::StopWatch.Stop
  OCall SW::StopWatch.GetTimeStr, addr cBuffer
  DbgStr cBuffer, "µS"
  DbgText "Dictionary item search ready"
;  DbgLine
;
;  ;Delete all items
;  mov xdi, offset MY_DIC_ITEMS
;  OCall SW::StopWatch.Reset
;  OCall SW::StopWatch.Start
;  xor ebx, ebx
;  .while ebx < MY_DIC_ITEM_COUNT
;    OCall Dict::Dictionary.Delete, [xdi].MY_DIC_ITEM.pKey
;    add xdi, sizeof(MY_DIC_ITEM)
;    inc ebx
;  .endw
;  OCall SW::StopWatch.Stop
;  OCall SW::StopWatch.GetTimeStr, addr cBuffer
;  DbgStr cBuffer, "µS"
;  DbgDec Dict.dTombstones
;  DbgText "Dictionary item deletion ready"
;  DbgLine
;
;  ;Check for non deleted items
;  mov xdi, Dict.pBuckets
;  xor ebx, ebx
;  xor esi, esi
;  .while ebx < DIC_SIZE
;    .if POINTER ptr [xdi] != HTL_BUCKET_EMPTY && POINTER ptr [xdi] != HTL_BUCKET_TOMBSTONE
;      mov xax, [xdi]
;      DbgDec [xax].MY_DIC_ITEM.dValue
;      inc esi
;    .endif
;    add xdi, sizeof(POINTER)
;    inc ebx
;  .endw
;  DbgDec Dict.dBucketsUsed
;  DbgDec esi, "Used buckets"
;  DbgText "Dictionary bucket check ready"
  DbgLine2

  OCall SW::StopWatch.Reset
  OCall SW::StopWatch.Start
  OCall Dict::Dictionary.Resize, 2048*2
  DbgDec Dict.dBucketsUsed
  DbgDec Dict.dCollisionCount
  OCall SW::StopWatch.Stop
  OCall SW::StopWatch.GetTimeStr, addr cBuffer
  DbgStr cBuffer, "µS"
  DbgLine

  ;Search all items
  mov xdi, offset MY_DIC_ITEMS
  OCall SW::StopWatch.Reset
  OCall SW::StopWatch.Start
  xor ebx, ebx
  .while ebx < MY_DIC_ITEM_COUNT
    OCall Dict::Dictionary.Search, [xdi].MY_DIC_ITEM.pKey
    add xdi, sizeof(MY_DIC_ITEM)
    inc ebx
  .endw
  OCall SW::StopWatch.Stop
  OCall SW::StopWatch.GetTimeStr, addr cBuffer
  DbgStr cBuffer, "µS"
  DbgText "Dictionary item search ready after resize"

  DbgLine2

  OCall Dict::Dictionary.Done

;  Performance comparison against SortedStrCollection
;
;  New Coll::SortedStrCollectionW
;  OCall Coll::SortedStrCollectionW.Init, NULL, 1024, 1024, -1
;
;  ;Insert items
;  mov xdi, offset MY_DIC_ITEMS
;  OCall SW::StopWatch.Start
;  xor ebx, ebx
;  .while ebx < MY_DIC_ITEM_COUNT
;    mov [xdi].MY_DIC_ITEM.dValue, ebx
;    OCall Coll::SortedStrCollectionW.Insert, [xdi].MY_DIC_ITEM.pKey
;    add xdi, sizeof(MY_DIC_ITEM)
;    inc ebx
;  .endw
;  OCall SW::StopWatch.Stop
;  OCall SW::StopWatch.GetTimeStr, addr cBuffer
;  DbgStr cBuffer, "µS"
;  DbgText "Collection item insertion ready"
;  DbgLine
;
;  ;Search all items
;  mov xdi, offset MY_DIC_ITEMS
;  OCall SW::StopWatch.Reset
;  OCall SW::StopWatch.Start
;  xor ebx, ebx
;  .while ebx < MY_DIC_ITEM_COUNT
;    OCall Coll::SortedStrCollectionW.Search, [xdi].MY_DIC_ITEM.pKey
;    add xdi, sizeof(MY_DIC_ITEM)
;    inc ebx
;  .endw
;  OCall SW::StopWatch.Stop
;  OCall SW::StopWatch.GetTimeStr, addr cBuffer
;  DbgStr cBuffer, "µS"
;  DbgText "Items search ready"
;  DbgLine
;
;  ;Delete all items
;  mov xdi, offset MY_DIC_ITEMS
;  OCall SW::StopWatch.Reset
;  OCall SW::StopWatch.Start
;  xor ebx, ebx
;  .while ebx < MY_DIC_ITEM_COUNT
;    OCall Coll::SortedStrCollectionW.Delete, [xdi].MY_DIC_ITEM.pKey
;    add xdi, sizeof(MY_DIC_ITEM)
;    inc ebx
;  .endw
;  OCall SW::StopWatch.Stop
;  OCall SW::StopWatch.GetTimeStr, addr cBuffer
;  DbgStr cBuffer, "µS"
;  DbgText "Item deletion ready"
;  DbgLine
;
;  OCall Coll::SortedStrCollectionW.Done



  OCall SW::StopWatch.Done

  DbgText "Ready"
  SysDone

  invoke ExitProcess, 0
start endp

end
