; ==================================================================================================
; Title:      TSortedVector.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm support of TSortedVector object template.
; Notes:      Version C.1.0, February 2024
;             - First release.
; ==================================================================================================


; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Object:     TSortedVector
; Purpose:    TVector is an object template for a BYTE, WORD, DWORD, QWORD, REAL4 or REAL8 sorted
;             data item container.
;             The data size is defined at compile time using e.g. TVEC_ITEM_TYPE textequ <DWORD>
;             This implementation supports all collection-like features, but not Item serialisation
;             and destruction, as these are not needed for data items.
;             TSortedVector implements sorted Vectors both with or without duplicate keys.
;             The Duplicates field controls whether duplicates are allowed. It defaults to FALSE,
;             indicating that duplicate keys are not allowed, but after creating a sorted
;             Vector, you can set Duplicates to TRUE to allow elements with duplicate keys in
;             the Vector.
;             The Search method implements a binary search through the items of the vector and
;             uses the .Compare method to compare the items.
; Note:       QWORD and REAL8 Vectors are only supported if TARGET_BITNESS is equal to 64.
;             Vector metadata is computed at compile time and stored in the following symbols:
;               Item Type: <NameSpace>_<ObjName>_ItemType
;               Capacity: <NameSpace>_<ObjName>_MaxCapacity
;               Callback proto: <NameSpace>_<ObjName>__PVecProc
;
; Example:    TSortedVectorName textequ <SortedDwVec>
;             AncestorVectorName textequ <DwVec>
;             TSortedVectorID = 150
;             % include &ObjPath&TSortedVector.inc
;             ...
;             New SortedDwVec
;             OCall xax::SortedDwVec.Init, NULL, 10, 10, OA_SortedDwVec_MaxCapacity


TSV_ASCENDING   equ   0
TSV_DESCENDING  equ   1
TSV_MODIFIABLE  equ   2


%Object TSortedVectorName, TSortedVectorID, AncestorVectorName

%ifb <AncestorVectorName>
  .err <TSortedVector error: Ancestor required.>
else
  TVEC_ITEM_TYPE  equ @CatStr(<%??AncName>, <_ItemType>)
  % &??ObjName&_ItemType    textequ <TVEC_ITEM_TYPE>
  % &??ObjName&_PVecProc    textequ <&??AncName&_PVecProc>
  % &??ObjName&_MaxCapacity textequ <&??AncName&_MaxCapacity>

  DynamicMethod     Compare,      TVEC_ITEM_TYPE, TVEC_ITEM_TYPE
  RedefineMethod    Insert,       TVEC_ITEM_TYPE
  RedefineMethod    Load,         $ObjPtr(Stream), PDESER_INFO
  VirtualMethod     Search,       TVEC_ITEM_TYPE        ;Item to search for
  VirtualMethod     Sort
  RedefineMethod    Store,        $ObjPtr(Stream)

  RedefineMethod    Store,        $ObjPtr(Stream)
  if TVectorDupCheck
    DefineVariable    dDuplicates,  DWORD, TVectorDupInit
  endif
  if TVectorOrdering eq TSV_MODIFIABLE
    DefineVariable    dOrdering,    DWORD, TVectorOrdInit
  endif
endif
ObjectEnd


; ==================================================================================================

if IMPLEMENT

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     TSortedVectorName.Compare
; Purpose:    Compare the two values.
; Arguments:  Arg1: Item 1.
;             Arg2: Item 2.
; Return:     eax =  (-)  if Item1 < Item2
;                     0   if Item1 = Item2
;                    (+)  if Item1 > Item2

%Method TSortedVectorName.Compare, uses xsi, xItem1:TVEC_ITEM_TYPE, xItem2:TVEC_ITEM_TYPE
  SetObject xsi
  if @InStr(1, <%TVEC_ITEM_TYPE>, <REAL>) eq 1          ;Check for floating point items
    if TVectorOrdering eq TSV_MODIFIABLE
      .if [xsi].dOrdering == TSV_ASCENDING
        fld xItem1
        fcomp xItem2
      .else
        fld xItem1
        fcomp xItem2
      .endif
    elseif TVectorOrdering eq TSV_ASCENDING
      fld xItem1
      fcomp xItem2
    elseif TVectorOrdering eq TSV_DESCENDING
      fld xItem2
      fcomp xItem1
    endif
    fGetFlags                                           ;Uses ax
    setnz cl
    sbb eax, eax
    or al, cl
  else                                                  ;Integer comparison
    if TVectorOrdering eq TSV_MODIFIABLE
      .if [xsi].dOrdering == TSV_ASCENDING
        mov $SubReg(eax, sizeof(TVEC_ITEM_TYPE)), xItem1
        sub $SubReg(eax, sizeof(TVEC_ITEM_TYPE)), xItem2
      .else
        mov $SubReg(eax, sizeof(TVEC_ITEM_TYPE)), xItem2
        sub $SubReg(eax, sizeof(TVEC_ITEM_TYPE)), xItem1
      .endif
    elseif TVectorOrdering eq TSV_ASCENDING
      mov $SubReg(eax, sizeof(TVEC_ITEM_TYPE)), xItem1
      sub $SubReg(eax, sizeof(TVEC_ITEM_TYPE)), xItem2
    elseif TVectorOrdering eq TSV_DESCENDING
      mov $SubReg(eax, sizeof(TVEC_ITEM_TYPE)), xItem2
      sub $SubReg(eax, sizeof(TVEC_ITEM_TYPE)), xItem1
    endif
  endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     TSortedVectorName.Insert
; Purpose:    If the target item is not found in the sorted Vector, it is inserted at the
;             correct index position. It calls Search to determine if the item exists, and if not,
;             where to insert it.
; Arguments:  Arg1: -> Item.
; Return:     xax -> Inserted item or NULL if the item was not inserted.

%Method TSortedVectorName.Insert, uses xsi, xItem:TVEC_ITEM_TYPE
  SetObject xsi
  OCall xsi.Search, xItem                               ;eax = success (TRUE/FALSE), ecx = index
  if TVectorDupCheck
    .if eax != FALSE
      xor eax, eax                                      ;xax = NULL (exit value)
      cmp [xsi].dDuplicates, eax
      je @@EOM
    .endif
  endif
  mov edx, ecx
  OCall xsi.InsertAt, edx, xItem
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     TSortedVectorName.Load
; Purpose:    Load a sorted Vector from the stream object by first calling
;             Vector.Load. It then reads the Duplicates field.
; Arguments:  Arg1: -> Stream object.
;             Arg2: -> DESER_INFO.
; Return:     Nothing.

%Method TSortedVectorName.Load, uses xsi, pStream:$ObjPtr(Stream), pDeserInfo:PDESER_INFO
  SetObject xsi
  ACall xsi.Load, pStream, pDeserInfo
  if TVectorDupCheck
    OCall pStream::Stream.BinRead32
    mov [xsi].dDuplicates, eax
  endif
  if TVectorOrdering eq TSV_MODIFIABLE
    OCall pStream::Stream.BinRead32
    mov [xsi].dOrdering, eax
  endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     TSortedVectorName.Search
; Purpose:    Search an item based on its key.
; Arguments:  Arg1: Item to be found.
; Return:     eax: Success condition (TRUE/FALSE).
;             ecx: Index in the range [0..Count]. If the item is not found, ecx is set to the
;                  index where the item would be placed if inserted.

%Method TSortedVectorName.Search, uses xbx xdi xsi r12 r13, xItem:TVEC_ITEM_TYPE
  LocReg dFound:r12d, dLowIndex:r13d

  SetObject xbx
  xor edi, edi                                          ;L = xdi = 0
  mov $LocReg(dLowIndex), edi
  mov esi, [xbx].dCount
  mov $LocReg(dFound), edi                              ;Found flag = FALSE
  dec xsi                                               ;H = xsi = Count - 1
@@0:
  mov edi, $LocReg(dLowIndex)
@@1:
  cmp edi, esi
  jg @@Exit                                             ;> signed compare
  add xdi, xsi
  shr xdi, 1                                            ;(L+H)/2
  mov xdx, [xbx].pItems
  OCall xbx.Compare, TVEC_ITEM_TYPE ptr [xdx + sizeof(TVEC_ITEM_TYPE)*xdi], xItem
  cmp eax, 0                                            ;Can NOT be replaced with "or eax, eax"
  jg @@2                                                ;> signed compare  (ZF=0 and SF=OF)
  jl @@3                                                ;                  (ZF=1)
  mov $LocReg(dFound), TRUE                             ;Found flag = TRUE
  if TVectorDupCheck
    cmp [xbx].dDuplicates, FALSE
    je @@Exit
  endif
@@2:
  lea esi, [edi - 1]                                    ;H = Index - 1
  jmp @@0
@@3:
  inc edi                                               ;L = Index + 1
  mov $LocReg(dLowIndex), edi
  jmp @@1

@@Exit:
  mov ecx, edi                                          ;Return insertion index in ecx
  mov eax, $LocReg(dFound)                              ;Return Found condition in eax
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     TSortedVectorName.Store
; Purpose:    Store the sorted Vector and all its items on the stream object by calling
;             Vector.Store to write the Vector. It then writes the Duplicates
;             field to the stream.
; Arguments:  Arg1: -> Stream object.
; Return:     Nothing.

%Method TSortedVectorName.Store, uses xsi, pStream:$ObjPtr(Stream)
  SetObject xsi
  ACall xsi.Store, pStream
   if TVectorDupCheck
    OCall pStream::Stream.BinWrite32, [xsi].dDuplicates
   endif
  if TVectorOrdering eq TSV_MODIFIABLE
    OCall pStream::Stream.BinWrite32, [xsi].dOrdering
  endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     TSortedVectorName.Sort
; Purpose:    Resort the Vector in place, i.e. if the compare method was changed.
; Arguments:  None.
; Return:     Nothing.

%Method TSortedVectorName.Sort, uses xbx xdi xsi
  SetObject xsi
  mov ebx, [xsi].dCount
  xor eax, eax
  test ebx, ebx
  setnz al                                                ;If exists, skip first item
  mov [xsi].dCount, eax                                   ;Set list new initial count
  .if !ZERO?
    mov xdi, [xsi].pItems
    .while TRUE
      dec ebx
      .break .if ZERO?
      add xdi, sizeof(TVEC_ITEM_TYPE)                     ;Move to next item
      OCall xsi.Insert, TVEC_ITEM_TYPE ptr [xdi]          ;Insert item from that position in the list
    .endw
  .endif
MethodEnd

endif
