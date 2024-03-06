; ==================================================================================================
; Title:      Vector.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm support of Vector base object.
; Notes:      Version C.1.0, February 2024
;               - First release.
; ==================================================================================================


; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Object:     Vector
; Purpose:    Vector is a base object for descendants like DWordVector.

Object Vector, VectorID, Streamable
  VirtualAbstract   Delete,         POINTER               ;pItem
  VirtualAbstract   DeleteAt,       DWORD                 ;Index in range [0..Count-1]
  VirtualAbstract   DeleteAll
  VirtualAbstract   FirstThat,      POINTER, XWORD, XWORD ;-> Func, 2 x Parameter
  VirtualAbstract   FirstThatNot,   POINTER, XWORD, XWORD ;-> Func, 2 x Parameter
  VirtualAbstract   ForEach,        POINTER, XWORD, XWORD ;-> Proc, 2 x Parameter
  VirtualAbstract   ForEachRev,     POINTER, XWORD, XWORD ;-> Proc, 2 x Parameter, reverse order
  VirtualAbstract   IndexOf,        POINTER               ;pItem
  VirtualAbstract   Insert,         POINTER               ;pItem
  VirtualAbstract   InsertAt,       DWORD, POINTER        ;Index, pItem
  VirtualAbstract   ItemAt,         DWORD                 ;Index in range [0..Count-1]
  VirtualAbstract   LastThat,       POINTER, XWORD, XWORD ;-> Func, 2 x Parameter
  VirtualAbstract   LastThatNot,    POINTER, XWORD, XWORD ;-> Func, 2 x Parameter
  RedefineMethod    Load,           $ObjPtr(Stream), PDESER_INFO
  VirtualAbstract   PutAt,          DWORD, POINTER        ;Index, ;pItem
  RedefineMethod    Store,          $ObjPtr(Stream)       ;-> Stream
  Private
  VirtualAbstract   SetLimit,       DWORD                 ;Set new limit (private method)

  DefineVariable    pItems,         POINTER,      NULL
  DefineVariable    dCount,         DWORD,        0
  DefineVariable    dLimit,         DWORD,        0
  DefineVariable    dDelta,         DWORD,        0
  DefineVariable    dMaxCapacity,   DWORD,        0
  DefineVariable    ObjLock,        OBJECT_LOCK,  {}    ;Locking structure for multithreaded access
ObjectEnd


; ==================================================================================================

??VecForEach_ID = 0

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      .VecForEach
; Purpose:    Loop through all items of the TVector.
; Arguments:  Arg1: TVector.
;             Arg2: Optional 32 bit index variable/register. It can not be eax!
; Return:     Nothing.
; Note:       On each loop xax -> Vector item.
; Example:    .VecForEach MyVector::SortedDataVector
;               DbgDec TVEC_ITEM_TYPE ptr [xax]
;             .VecNext

.VecForEach macro Expression:req, Index
  ??VecForEach_ID = ??VecForEach_ID + 1
  ifb <Index>
    @CatStr(<??VecForEach_Index_>, %??VecForEach_ID) textequ GetMemBSS(4)
  else
    @CatStr(<??VecForEach_Index_>, %??VecForEach_ID) textequ <Index>
  endif
  @CatStr(<??VecForEach_Step_>, %??VecForEach_ID) = +1

  PreParseExpr Expression

  ;;Get ??MtdExpr
  if ??Pos3 ne 0
    @Err <.VecForEach Error: method Expression not allowed>
    exitm
  endif

  ;;Get ??ObjExpr
  if ??Pos1 ne 0
    if ??Pos2 ne 0
      ??ObjExpr CatStr @SubStr(<Expression>, ??Pos1 + 2, ??Pos2 - ??Pos1 - 2), \
                       ??ObjPfxSep, \
                       @SubStr(<Expression>, ??Pos2 + 1)
    else
      ??ObjExpr CatStr ??ObjPfx, @SubStr(<Expression>, ??Pos1 + 2)
    endif
  else
    if ??Pos2 ne 0
      ??ObjExpr CatStr @SubStr(<Expression>, 1, ??Pos2 - 1), \
                       ??ObjPfxSep, \
                       @SubStr(<Expression>, ??Pos2 + 1)
    else
      ??ObjExpr CatStr ??ObjPfx, <Expression>
    endif
  endif

  ;;Get ??InsExpr
  if ??Pos1 ne 0
    ??InsExpr SubStr <Expression>, 1, ??Pos1 - 1
  endif

  %ifdef ??ObjExpr
    if @CatStr(%??ObjExpr, <_Error>) eq ??OBJERR_NONE
      if (opattr Index) and OAT_REGISTER
        if @InStr(1, %RAX_SUBREGS, $Upper(&Index)) ne 0
          .err <.VecForEach Error: invalid index register>
        endif

%       ifdef ??ObjExpr.dItemSize
          xor Index, Index
          .while Index != (??ObjExpr ptr ??InsExpr).dCount
            mov eax, Index
            mul (??ObjExpr ptr ??InsExpr).dItemSize
            add xax, (??ObjExpr ptr ??InsExpr).pItems
        else
          xor Index, Index
          .while Index != (??ObjExpr ptr ??InsExpr).dCount
%           lea xax, [Index*sizeof(&??ObjExpr&_ItemType)]
            add xax, (??ObjExpr ptr ??InsExpr).pItems
        endif
      else
%       ifdef ??ObjExpr.dItemSize
          xor eax, eax
          mov @CatStr(<??VecForEach_Index_>, %??DataVecForEach_ID), eax
          .while eax != (??ObjExpr ptr ??InsExpr).dCount
            mul (??ObjExpr ptr ??InsExpr).dItemType
            add xax, (??ObjExpr ptr ??InsExpr).pItems
        else
          xor eax, eax
          mov @CatStr(<??VecForEach_Index_>, %??VecForEach_ID), eax
          .while eax != (??ObjExpr ptr ??InsExpr).dCount
%           lea xax, [xax*sizeof(&??ObjExpr&_ItemType)]
            add xax, (??ObjExpr ptr ??InsExpr).pItems
        endif
      endif
    endif

  else
    @Err <.VecForEach Error: undefined object Expression>
  endif
endm                                                    ;;xax -> allocated object instance

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      .VecForEachRev
; Purpose:    Loop through all items of the TVector in reverse order.
; Arguments:  Arg1: TVector.
;             Arg2: Optional 32 bit index variable/register. It can not be eax!
; Return:     Nothing.
; Note:       On each loop xax -> TVector item.

.VecForEachRev macro Expression:req, Index
  ??VecForEach_ID = ??VecForEach_ID + 1
  ifb <Index>
    @CatStr(<??VecForEach_Index_>, %??VecForEach_ID) textequ GetMemBSS(4)
  else
    @CatStr(<??VecForEach_Index_>, %??VecForEach_ID) textequ <Index>
  endif
  @CatStr(<??VecForEach_Step_>, %??VecForEach_ID) = -1

  PreParseExpr Expression

  ;;Get ??MtdExpr
  if ??Pos3 ne 0
    @Err <.VecForEachRev Error: method Expression not allowed>
    exitm
  endif

  ;;Get ??ObjExpr
  if ??Pos1 ne 0
    if ??Pos2 ne 0
      ??ObjExpr CatStr @SubStr(<Expression>, ??Pos1 + 2, ??Pos2 - ??Pos1 - 2), \
                       ??ObjPfxSep, \
                       @SubStr(<Expression>, ??Pos2 + 1)
    else
      ??ObjExpr CatStr ??ObjPfx, @SubStr(<Expression>, ??Pos1 + 2)
    endif
  else
    if ??Pos2 ne 0
      ??ObjExpr CatStr @SubStr(<Expression>, 1, ??Pos2 - 1), \
                       ??ObjPfxSep, \
                       @SubStr(<Expression>, ??Pos2 + 1)
    else
      ??ObjExpr CatStr ??ObjPfx, <Expression>
    endif
  endif

  ;;Get ??InsExpr
  if ??Pos1 ne 0
    ??InsExpr SubStr <Expression>, 1, ??Pos1 - 1
  endif

  %ifdef ??ObjExpr
    if @CatStr(%??ObjExpr, <_Error>) eq ??OBJERR_NONE
      if (opattr Index) and OAT_REGISTER
        if @InStr(1, %RAX_SUBREGS, $Upper(&Index)) ne 0
          .err <.VecForEachRev: invalid index register>
        endif

%       ifdef ??ObjExpr.dItemSize
          mov Index, (??ObjExpr ptr ??InsExpr).dCount
          dec Index
          .while !SIGN?
            mov eax, Index
            mul (??ObjExpr ptr ??InsExpr).dItemSize
            add xax, (??ObjExpr ptr ??InsExpr).pItems
        else
          mov Index, (??ObjExpr ptr ??InsExpr).dCount
          dec Index
          .while !SIGN?
%           lea xax, [Index*sizeof(&??ObjExpr&_ItemType)]
            add xax, (??ObjExpr ptr ??InsExpr).pItems
        endif
      else
%       ifdef ??ObjExpr.dItemSize
          mov eax, (??ObjExpr ptr ??InsExpr).dCount
          dec eax
          mov @CatStr(<??VecForEach_Index_>, %??VecForEach_ID), eax
          .while !SIGN?
            mul (??ObjExpr ptr ??InsExpr).dItemType
            add xax, (??ObjExpr ptr ??InsExpr).pItems
        else
          mov eax, (??ObjExpr ptr ??InsExpr).dCount
          dec eax
          mov @CatStr(<??VecForEach_Index_>, %??VecForEach_ID), eax
          .while !SIGN?
%           lea xax, [xax*sizeof(&??ObjExpr&_ItemType)]
            add xax, (??ObjExpr ptr ??InsExpr).pItems
        endif
      endif
    endif

  else
    @Err <.VecForEachRev Error: undefined object Expression>
  endif
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      .VecNext
; Purpose:    Move to the next TVector item.
; Arguments:  None
; Return:     Nothing.

.VecNext macro
    if @CatStr(<??VecForEach_Step_>, %??VecForEach_ID) eq +1
      inc @CatStr(<??VecForEach_Index_>, %??VecForEach_ID)
    else
      dec @CatStr(<??VecForEach_Index_>, %??VecForEach_ID)
    endif
    if not (opattr @CatStr(<??VecForEach_Index_>, %??VecForEach_ID)) and OAT_REGISTER
      mov eax, @CatStr(<??VecForEach_Index_>, %??VecForEach_ID)
    endif
  .endw
  ??VecForEach_ID = ??VecForEach_ID - 1
endm


; ==================================================================================================

if IMPLEMENT

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Vector.Load
; Purpose:    Load and initializes the Vector from a Stream object.
; Arguments:  Arg1: -> Stream object.
;             Arg2: -> DESER_INFO.
; Return:     Nothing.

Method Vector.Load, uses xbx xdi xsi, pStream:$ObjPtr(Stream), pDeserInfo:PDESER_INFO
  ArgReg pStream:rdx, pDeserInfo:r8

  SetObject xsi
  ACall xsi.Load, $ArgReg(pStream), $ArgReg(pDeserInfo)
  OCall pStream::Stream.BinRead32                       ;Read count
  mov edi, eax                                          ;edi = Count
  OCall pStream::Stream.BinRead32                       ;Read dLimit
  mov ebx, eax

  OCall pStream::Stream.BinRead32                       ;Read dDelta
  mov [xsi].dDelta, eax
  OCall pStream::Stream.BinRead32                       ;Read dMaxCapacity
  mov [xsi].dMaxCapacity, eax

  xor eax, eax
  mov [xsi].pItems, xax
  mov [xsi].dCount, eax
  mov [xsi].dLimit, eax
  OCall xsi.SetLimit, ebx
  test eax, eax                                         ;Test for OBJ_OK
  jne @@Error
  mov [xsi].dCount, edi

  ret
@@Error:
  OCall xsi.ErrorReport, NULL, eax
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Vector.Store
; Purpose:    Store the collection in a stream object.
; Arguments:  Arg1: -> Stream object.
; Return:     Nothing.

Method Vector.Store, uses xdi xsi, pStream:$ObjPtr(Stream)
  ArgReg pStream:rdx

  SetObject xsi
  mov xdi, $ArgReg(pStream)
  ACall xsi.Store, $ArgReg(pStream)
  OCall xdi::Stream.BinWrite32, [xsi].dCount
  OCall xdi::Stream.BinWrite32, [xsi].dLimit
  OCall xdi::Stream.BinWrite32, [xsi].dDelta
  OCall xdi::Stream.BinWrite32, [xsi].dMaxCapacity
MethodEnd

endif