; ==================================================================================================
; Title:      RedBlackTreeDemo.asm
; Author:     G. Friedrich
; Version:    1.0.0
; Purpose:    ObjAsm Red-Black Tree Demo Application.
; Notes:      Version 1.0.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\Code\Macros\Model.inc   ;Include & initialize standard modules
SysSetup OOP, WIN64, WIDE_STRING, DEBUG(WND)            ;Load OOP files and OS related objects

% include &MacPath&fMath.inc                            ;Used for StopWatch

MakeObjects Primer, Stream, DiskStream
MakeObjects RedBlackTree
MakeObjects StopWatch


LOOPS equ 16;00000


Object DataHost, 3658742, Streamable
  RedefineMethod    Init,           POINTER, DWORD
  RedefineMethod    Load,           $ObjPtr(Stream), PDESER_INFO
  RedefineMethod    Store,          $ObjPtr(Stream)

  DefineVariable    RBTN,           RBT_NODE,   {}
  DefineVariable    dKey,           DWORD,      0
ObjectEnd


.data
pSW     POINTER   NULL
cText   CHR       100 dup(0)
FindDH  $ObjInst(DataHost)
DskStm  $ObjInst(DiskStream)

XorShift128PlusSeed XWORD 12358, 65987          ;Seed

.code

XorShift128Plus proc
  mov xax, XWORD ptr [XorShift128PlusSeed]
  mov xdx, XWORD ptr [XorShift128PlusSeed + sizeof XWORD]
  mov XWORD ptr [XorShift128PlusSeed], xdx
  mov xcx, xax
  shl xcx, 23
  xor xax, xcx
  mov xcx, xax
  xor xcx, xdx
  shr xax, 17
  xor xcx, xax
  mov xax, xdx
  shr xax, 26
  xor xcx, xax
  mov XWORD ptr [XorShift128PlusSeed + sizeof XWORD], xcx
  mov xax, XWORD ptr [XorShift128PlusSeed + sizeof XWORD]
  add xax, xdx
  ret
XorShift128Plus endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————

Method RBT.Compare,, pDH1:POINTER, pDH2:POINTER
  ?mov xdx, pDH1
  mov xcx, pDH2
  mov eax, [xdx].$Obj(DataHost).dKey
  sub eax, [xcx].$Obj(DataHost).dKey
  if TARGET_BITNESS eq 64
    movsxd rax, eax
  endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————

ShowObject proc pObject:POINTER, Number:DWORD
  ?mov ecx, pObject
  mov edx, [xcx].$Obj(DataHost).dKey
  DbgHex xcx
  DbgDec edx
;  DbgDec Number
  ret
ShowObject endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————

TestObject proc pObject:POINTER
  ?mov ecx, pObject
  mov edx, [xcx].$Obj(DataHost).dKey
  .if edx == 150
    mov eax, TRUE
  .else
    xor eax, eax
  .endif
  ret
TestObject endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     DataHost.Init
; Purpose:    Initializes the object.
; Arguments:  Arg1: -> Owner.
;             Arg2: Key.
; Return:     Nothing.

Method DataHost.Init,, pOwner:POINTER, dKey:DWORD
  SetObject xcx
  m2m [xcx].dKey, dKey, eax
  ACall xcx.Init, pOwner
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     DataHost.Load
; Purpose:    Loads and initializes the collection from a stream object.
; Arguments:  Arg1: -> Stream object.
;             Arg2: -> DESER_INFO.
; Return:     Nothing.

Method DataHost.Load, uses xsi, pStream:$ObjPtr(Stream), pDeserInfo:PDESER_INFO
  SetObject xsi
  mov [xsi].pOwner, $OCall(pStream::Stream.BinReadX)               ;Must be deserialized
  mov [xsi].dErrorCode, $32($OCall(pStream::Stream.BinRead32))
  mov [xsi].pErrorCaller, $OCall(pStream::Stream.BinReadX)         ;Must be deserialized
  mov [xsi].dKey, $32($OCall(pStream::Stream.BinRead32))
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     DataHost.Store
; Purpose:    Stores the collection in a stream object.
; Arguments:  Arg1: -> Stream object.
; Return:     Nothing.

Method DataHost.Store, uses xsi, pStream:$ObjPtr(Stream)
  SetObject xsi
  OCall pStream::Stream.BinWriteX, [xsi].pOwner
  OCall pStream::Stream.BinWrite32, [xsi].dErrorCode
  OCall pStream::Stream.BinWriteX, [xsi].pErrorCaller
  OCall pStream::Stream.BinWrite32, [xsi].dKey
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  Deserialize
; Purpose:    .
; Arguments:  Arg1: -> DesLUT object.
;             Arg2:
;             Arg3:
;             Arg4:
; Return:     Nothing.

Deserialize proc uses xbx xsi, pDesLUT:$ObjPtr(DesLUT), pEntry:PDLT_ENTRY, xArg1:XWORD, xArg2:XWORD
  mov xbx, xcx
  mov xsi, [xdx]
  OCall xbx::DesLUT.Find, [xsi].RBT_NODE.pLeftNode
  mov [xsi].RBT_NODE.pLeftNode, xax
  OCall xbx::DesLUT.Find, [xsi].RBT_NODE.pRightNode
  mov [xsi].RBT_NODE.pRightNode, xax
  OCall xbx::DesLUT.Find, [xsi].RBT_NODE.pParentNode
  mov [xsi].RBT_NODE.pParentNode, xax
  ret
Deserialize endp



; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Main code
; ——————————————————————————————————————————————————————————————————————————————————————————————————

start proc uses xbx xdi xsi
  SysInit

;  invoke GetCurrentProcess
;  invoke SetPriorityClass, rax, REALTIME_PRIORITY_CLASS

  mov pSW, $New(StopWatch)
  OCall pSW::StopWatch.Init, NULL

  mov xbx, $New(RedBlackTree)
  OCall xbx::RedBlackTree.Init, NULL, $ObjTmpl(DataHost).RBTN - $ObjTmpl(DataHost)
  Override xbx::RedBlackTree.Compare, RBT.Compare
  xor edi, edi
  .repeat
    mov xsi, $New(DataHost)
    OCall xsi::DataHost.Init, xbx, edi
    OCall xbx::RedBlackTree.Insert, xsi
    add edi, 1
  .until edi == LOOPS

  invoke RedBlackTree_Show, xbx, $ObjTmpl(DataHost).dKey - $ObjTmpl(DataHost)

  OCall DskStm::DiskStream.Init, NULL, $OfsCStr("RBTree.data"), 0, 0, NULL, 0, 0, 0
  OCall DskStm::DiskStream.Put, xbx
  OCall DskStm::DiskStream.Done
  OCall xbx::RedBlackTree.DisposeAll
  OCall xbx::RedBlackTree.Done

  OCall DskStm::DiskStream.Init, NULL, $OfsCStr("RBTree.data"), 0, 0, NULL, 0, 0, 0
  OCall $ObjTmpl(DesLUT)::DesLUT.Init, NULL, 100, 100, -1
  mov xbx, $OCall(DskStm::DiskStream.Get, NULL)
;  OCall $ObjTmpl(DesLUT)::DesLUT.ForEach, offset Deserialize, NULL, NULL
  OCall $ObjTmpl(DesLUT)::DesLUT.Done
  OCall DskStm::DiskStream.Done

  invoke RedBlackTree_Show, xbx, $ObjTmpl(DataHost).dKey - $ObjTmpl(DataHost)

;  mov FindDH.dKey, 7
;  OCall xbx::RedBlackTree.Find, offset FindDH
;  DbgHex rax

;  OCall pSW::StopWatch.Start
;
;  OCall xbx::RedBlackTree.GetFirst
;  .while rax != 0
;    OCall xbx::RedBlackTree.GetNext, rax
;  .endw
;
;  OCall pSW::StopWatch.Stop
;  OCall pSW::StopWatch.GetTimeStr, offset cText
;  invoke StrCat, offset cText, $OfsCStr(" µs")
;
;  DbgStr cText
;
;  .while [xbx].RedBlackTree.dCount > 8
;    invoke XorShift128Plus
;    and eax, 7
;    mov edi, eax
;    DbgHex eax
;    OCall xbx::RedBlackTree.GetFirst
;    test edi, edi
;    .while !ZERO?
;      OCall xbx::RedBlackTree.GetNext, rax
;      dec edi
;    .endw
;;    OCall xbx::RedBlackTree.Dispose, rax
;  .endw
;
  OCall xbx::RedBlackTree.DisposeAll

  Destroy xbx

  SysDone

  invoke ExitProcess, 0
start endp

end