; ==================================================================================================
; Title:      OA_ObjDB_Collections.inc
; Author:     G. Friedrich
; Version:    Check OA_ObjExplorer.asm
; Purpose:    ObjAsm Collections managed by the OA_ObjDB.
; ==================================================================================================


FILEINFORMATION struct
  pFileName       PSTRING   ?           ;-> File Name
  LastWrite       FILETIME  <>          ;Date of last write to this file
  dFlags          DWORD     ?           ;Internal maintenance flags
FILEINFORMATION ends
PFILEINFORMATION typedef ptr FILEINFORMATION

INFORMATION struct
  dFlags          DWORD     ?           ;METHODTYPE_XXX, VARIABLETYPE_XXX,
  pName           PSTRING   ?           ;-> Name.
  pFileInfo       PFILEINFORMATION   ?  ;-> FILEINFORMATION structure
  dLineNumber     DWORD     ?           ;Where to find the info in the text file.
  dHelpLineCount  DWORD     ?           ;Number of lines contained in HelpLines
  pHelpData       PSTRING   ?           ;help strings, each string is a consecutive line
INFORMATION ends
PINFORMATION typedef ptr INFORMATION

OBJECTINFORMATION struct
                  INFORMATION {}
  pAncestorName   PSTRING   ?           ;-> Object Ancestor Name
OBJECTINFORMATION ends
POBJECTINFORMATION typedef ptr OBJECTINFORMATION

OBJMTDINFORMATION struct
                  INFORMATION {}
  pObjectName     PSTRING   ?           ;-> Object Name
  pArguments      PSTRING   ?           ;-> "DWORD, DWORD, POINTER"
OBJMTDINFORMATION ends
POBJMTDINFORMATION typedef ptr OBJMTDINFORMATION

OBJVARINFORMATION struct
                  INFORMATION {}
  pObjectName     PSTRING   ?           ;-> Object Name
  pArgType        PSTRING   ?           ;-> "DWORD"
OBJVARINFORMATION ends
POBJVARINFORMATION typedef ptr OBJVARINFORMATION

INTERFACEINFORMATION struct
                  INFORMATION {}
  pAncestorName   PSTRING   ?           ;-> Interface Ancestor Name
INTERFACEINFORMATION ends
PINTERFACEINFORMATION typedef ptr INTERFACEINFORMATION

INTMTDINFORMATION struct
                  INFORMATION {}
  pInterfaceName  PSTRING   ?           ;-> Interface Name
  pArguments      PSTRING   ?           ;-> "DWORD, DWORD, POINTER"
INTMTDINFORMATION ends
PINTMTDINFORMATION typedef ptr INTMTDINFORMATION

IMPMTDINFORMATION struct
                  INFORMATION {}
  pObjectName     PSTRING   ?           ;-> Object Name
  pArguments      PSTRING   ?           ;-> "DWORD, DWORD, POINTER"
IMPMTDINFORMATION ends
PIMPMTDINFORMATION typedef ptr IMPMTDINFORMATION

SCAN_OFF          equ     0
SCAN_ON_START     equ     BIT00
SCAN_ON_REQUEST   equ     BIT01


; --------------------------------------------------------------------------------------------------
; Object:    FileCollection
; Purpose:   This collection holds all file references of the object database.

Object FilesCollection, OAE_FilesCollectionID, SortedCollection
  RedefineMethod    Compare,        PSTRING, PSTRING
  RedefineMethod    DestroyItem,    PFILEINFORMATION
  RedefineMethod    GetItem,        $ObjPtr(Stream), PDESER_INFO
  RedefineMethod    KeyOf,          PFILEINFORMATION
  RedefineMethod    PutItem,        $ObjPtr(Stream), PFILEINFORMATION
ObjectEnd

; --------------------------------------------------------------------------------------------------
; Object:    ObjInfoCollection
; Purpose:   This collection holds all object definitions found in the scanned files.

Object ObjInfoCollection, OAE_ObjInfoCollectionID, SortedCollection
  RedefineMethod    Compare,        PSTRINGA, PSTRINGA
  RedefineMethod    DestroyItem,    POBJECTINFORMATION
  RedefineMethod    GetItem,        $ObjPtr(Stream), PDESER_INFO
  RedefineMethod    Init,           POINTER, DWORD, DWORD, $ObjPtr(FilesCollection)
  RedefineMethod    KeyOf,          POBJECTINFORMATION
  RedefineMethod    PutItem,        $ObjPtr(Stream), POBJECTINFORMATION

  DefineVariable    pFilesColl,     $ObjPtr(FilesCollection),    NULL
ObjectEnd

; --------------------------------------------------------------------------------------------------
; Object:    ObjMtdInfoCollection
; Purpose:   This collection holds all method definitions found in the scanned files.

Object ObjMtdInfoCollection, OAE_ObjMtdInfoCollectionID, Collection
  RedefineMethod    DestroyItem,    POBJMTDINFORMATION
  RedefineMethod    GetItem,        $ObjPtr(Stream), PDESER_INFO
  RedefineMethod    Init,           POINTER, DWORD, DWORD, $ObjPtr(FilesCollection)
  RedefineMethod    PutItem,        $ObjPtr(Stream), POBJMTDINFORMATION

  DefineVariable    pFilesColl,     $ObjPtr(FilesCollection),    NULL
ObjectEnd

; --------------------------------------------------------------------------------------------------
; Object:    ObjVarInfoCollection
; Purpose:   This collection holds all variable definitions found in the scanned files.

Object ObjVarInfoCollection, OAE_ObjVarInfoCollectionID, Collection
  RedefineMethod    DestroyItem,    POBJVARINFORMATION
  RedefineMethod    GetItem,        $ObjPtr(Stream), PDESER_INFO
  RedefineMethod    Init,           POINTER, DWORD, DWORD, $ObjPtr(FilesCollection)
  RedefineMethod    PutItem,        $ObjPtr(Stream), POBJVARINFORMATION

  DefineVariable    pFilesColl,     $ObjPtr(FilesCollection),    NULL
ObjectEnd

; --------------------------------------------------------------------------------------------------
; Object:    IntInfoCollection
; Purpose:   This collection holds all interface definitions found in the scanned files.

Object IntInfoCollection, OAE_IntInfoCollectionID, SortedCollection
  RedefineMethod    Compare,        PSTRINGA, PSTRINGA
  RedefineMethod    DestroyItem,    PINTERFACEINFORMATION
  RedefineMethod    GetItem,        $ObjPtr(Stream), PDESER_INFO
  RedefineMethod    KeyOf,          PINTERFACEINFORMATION
  RedefineMethod    Init,           POINTER, DWORD, DWORD, $ObjPtr(FilesCollection)
  RedefineMethod    PutItem,        $ObjPtr(Stream), PINTERFACEINFORMATION

  DefineVariable    pFilesColl,     $ObjPtr(FilesCollection),    NULL
ObjectEnd

; --------------------------------------------------------------------------------------------------
; Object:    IntMtdInfoCollection
; Purpose:   This collection holds all interface method definitions found in the scanned files.

Object IntMtdInfoCollection, OAE_IntMtdInfoCollectionID, Collection
  RedefineMethod    DestroyItem,    PINTMTDINFORMATION
  RedefineMethod    GetItem,        $ObjPtr(Stream), PDESER_INFO
  RedefineMethod    Init,           POINTER, DWORD, DWORD, $ObjPtr(FilesCollection)
  RedefineMethod    PutItem,        $ObjPtr(Stream), PINTMTDINFORMATION

  DefineVariable    pFilesColl,     $ObjPtr(FilesCollection),    NULL
ObjectEnd

; --------------------------------------------------------------------------------------------------
; Object:    ImpMtdInfoCollection
; Purpose:   This collection holds all implemented methods found in the scanned files.

Object ImpMtdInfoCollection, OAE_ImpMtdInfoCollectionID, Collection
  RedefineMethod    DestroyItem,    PIMPMTDINFORMATION
  RedefineMethod    GetItem,        $ObjPtr(Stream), PDESER_INFO
  RedefineMethod    Init,           POINTER, DWORD, DWORD, $ObjPtr(FilesCollection)
  RedefineMethod    PutItem,        $ObjPtr(Stream), PIMPMTDINFORMATION

  DefineVariable    pFilesColl,     $ObjPtr(FilesCollection),    NULL
ObjectEnd


; ==================================================================================================

if IMPLEMENT

; ==================================================================================================
;  FilesCollection implementation
; ==================================================================================================

; --------------------------------------------------------------------------------------------------
; Method:     FilesCollection.Compare
; Purpose:    Compares the strings Key1 and Key2.
; Arguments:  Arg1: -> First key string.
;             Arg2: -> Second key string.
; Return:     eax = (-)  if Key1 < Key2
;                    0   if Key1 = Key2
;                   (+)  if Key1 > Key2

Method FilesCollection.Compare,, pKeyStr1:PSTRING, pKeyStr2:PSTRING
  invoke StrIComp, pKeyStr1, pKeyStr2                   ;Without case!
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     FilesCollection.DestroyItem
; Purpose:    Overridden method.
; Arguments:  Arg1: -> FILEINFORMATION.
; Return:     Nothing.

Method FilesCollection.DestroyItem,, pItem:PFILEINFORMATION
  mov xax, pItem
  invoke StrDispose, [xax].FILEINFORMATION.pFileName
  MemFree pItem
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     FilesCollection.GetItem
; Purpose:    Loads an item from a stream object.
; Arguments:  Arg1: -> Stream.
;             Arg2: -> DESER_INFO.
; Return:     xax -> New loaded FILEINFORMATION structure.

Method FilesCollection.GetItem, uses xbx, pStream:$ObjPtr(Stream), pDeserInfo:PDESER_INFO
  mov xbx, $MemAlloc(sizeof(FILEINFORMATION))
  mov [xbx].FILEINFORMATION.pFileName, $OCall(pStream::Stream.StrRead)
  OCall pStream::Stream.BinRead, addr [xbx].FILEINFORMATION.LastWrite, sizeof FILETIME
  m2z [xbx].FILEINFORMATION.dFlags                    ;Reset flags when loaded from stream
  mov xax, xbx
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     FilesCollection.KeyOf
; Purpose:    Overridden method.
; Arguments:  Arg1: -> FILEINFORMATION.
; Return:     xax -> Sorting key of the item.

Method FilesCollection.KeyOf,, pItem:PFILEINFORMATION
  mov xcx, pItem
  mov xax, [xcx].FILEINFORMATION.pFileName
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     FilesCollection.PutItem
; Purpose:    Stores an item of the collection in a stream object.
; Arguments:  Arg1: -> Stream.
;             Arg2: -> FILEINFORMATION.
; Return:     Nothing.

Method FilesCollection.PutItem, uses xbx, pStream:$ObjPtr(Stream), pItem:PFILEINFORMATION
  mov xbx, pItem
  OCall pStream::Stream.StrWrite, [xbx].FILEINFORMATION.pFileName
  OCall pStream::Stream.BinWrite, addr [xbx].FILEINFORMATION.LastWrite, sizeof FILETIME
MethodEnd


; ==================================================================================================
;  ObjInfoCollection implementation
; ==================================================================================================

; --------------------------------------------------------------------------------------------------
; Method:     ObjInfoCollection.Compare
; Purpose:    Compares the strings Key1 and Key2.
; Arguments:  Arg1: -> First key string.
;             Arg2: -> Second key string.
; Return:     eax = (-)  if Key1 < Key2
;                    0   if Key1 = Key2
;                   (+)  if Key1 > Key2

Method ObjInfoCollection.Compare,, pKeyStr1:PSTRINGA, pKeyStr2:PSTRINGA
  invoke StrCompA, pKeyStr1, pKeyStr2
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     ObjInfoCollection.DestroyItem
; Purpose:    Overridden method.
; Arguments:  Arg1: -> OBJECTINFORMATION.
; Return:     Nothing.

Method ObjInfoCollection.DestroyItem, uses xbx xdi, pItem:POBJECTINFORMATION
  mov xbx, pItem                                 ;pItem
  invoke StrDispose, [xbx].OBJECTINFORMATION.pName
  invoke StrDispose, [xbx].OBJECTINFORMATION.pAncestorName
;  mov xdi, [xbx].OBJECTINFORMATION.pHelpData
;  .while xdi != NULL
;    mov xax, xdi
;    mov xdi, [xdi]
;    MemFree xax
;  .endw
  MemFree xbx
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     ObjInfoCollection.GetItem
; Purpose:    Loads an item from a stream object.
; Arguments:  Arg1: -> Stream.
;             Arg2: -> DESER_INFO.
; Return:     xax -> New loaded OBJECTINFORMATION structure.

Method ObjInfoCollection.GetItem, uses xbx xdi xsi, pStream:$ObjPtr(Stream), pDeserInfo:PDESER_INFO
  local dSize:DWORD

  mov xbx, $MemAlloc(sizeof(OBJECTINFORMATION))
  mov [xbx].OBJECTINFORMATION.dFlags, $32($OCall(pStream::Stream.BinRead32))
  mov [xbx].OBJECTINFORMATION.pName, $OCall(pStream::Stream.StrRead)
  mov [xbx].OBJECTINFORMATION.pAncestorName, $OCall(pStream::Stream.StrRead)
  mov [xbx].OBJECTINFORMATION.dHelpLineCount, $32($OCall(pStream::Stream.BinRead32))
  mov edi, eax
  lea xsi, [xbx].OBJECTINFORMATION.pHelpData
  .while edi != 0
    OCall pStream::Stream.BinRead32
    mov dSize, eax
    add eax, sizeof(POINTER)
    invoke StrAllocA, eax
    mov [xsi], xax
    mov xsi, xax
    add xax, sizeof(POINTER)
    OCall pStream::Stream.BinRead, xax, dSize
;    DbgStr BYTE ptr [xsi + sizeof(POINTER)]
    dec edi
  .endw
  m2z POINTER ptr [xsi]
  OCall pStream::Stream.BinRead32                       ;FILEINFORMATION index
  SetObject xcx
  OCall [xcx].pFilesColl::FilesCollection.ItemAt, eax
  mov [xbx].OBJECTINFORMATION.pFileInfo, xax
  mov xax, xbx
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     ObjInfoCollection.KeyOf
; Purpose:    Overridden method.
; Arguments:  Arg1: -> Item.
; Return:     xax -> Sorting key of the item.

Method ObjInfoCollection.KeyOf,, pItem:POBJECTINFORMATION
  mov xcx, pItem
  mov xax, [xcx].OBJECTINFORMATION.pName                ;xax -> Object name
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     ObjInfoCollection.Init
; Purpose:    (Constructor) Initializes the object.
; Arguments:  Arg1: -> Owner object.
;             Arg2: Initial capacity of the collection (#items).
;             Arg3: Growing factor of the collection (#items).
;             Arg4: -> Files collection.
; Return:     Nothing.

Method ObjInfoCollection.Init,, pOwner:POINTER, dLimit:DWORD, dDelta:DWORD, pFilesColl:$ObjPtr(FilesCollection)
  SetObject xcx
  m2m [xcx].pFilesColl, pFilesColl, xdx
  mov [xcx].dDuplicates, TRUE
  ACall xcx.Init, pOwner, dLimit, dDelta, COL_MAX_CAPACITY
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     ObjInfoCollection.PutItem
; Purpose:    Stores an item of the collection in a stream object.
; Arguments:  Arg1: -> Stream.
;             Arg2: -> OBJECTINFORMATION.
; Return:     Nothing.

Method ObjInfoCollection.PutItem, uses xbx xdi, pStream:$ObjPtr(Stream), pItem:POBJECTINFORMATION
  mov xbx, pItem
  OCall pStream::Stream.BinWrite32, [xbx].OBJECTINFORMATION.dFlags
  OCall pStream::Stream.StrWriteA, [xbx].OBJECTINFORMATION.pName
  OCall pStream::Stream.StrWriteA, [xbx].OBJECTINFORMATION.pAncestorName
  OCall pStream::Stream.BinWrite32, [xbx].OBJECTINFORMATION.dHelpLineCount
  mov xdi, [xbx].OBJECTINFORMATION.pHelpData
  .while xdi != NULL
    lea xdx, [xdi + sizeof(POINTER)]
    OCall pStream::Stream.StrWriteA, xdx
    mov xdi, [xdi]
  .endw
  SetObject xcx
  OCall [xcx].pFilesColl::FilesCollection.IndexOf, [xbx].OBJECTINFORMATION.pFileInfo
  OCall pStream::Stream.BinWrite32, eax
MethodEnd


; ==================================================================================================
;  ObjMtdInfoCollection implementation
; ==================================================================================================

; --------------------------------------------------------------------------------------------------
; Method:     ObjMtdInfoCollection.DestroyItem
; Purpose:    Overridden method.
; Arguments:  Arg1: -> OBJMTDINFORMATION.
; Return:     Nothing.

Method ObjMtdInfoCollection.DestroyItem, uses xbx xdi, pItem:POBJMTDINFORMATION
  mov xbx, pItem
  invoke StrDispose, [xbx].OBJMTDINFORMATION.pObjectName
  invoke StrDispose, [xbx].OBJMTDINFORMATION.pName
  invoke StrDispose, [xbx].OBJMTDINFORMATION.pArguments
;  mov xdi, [xbx].OBJMTDINFORMATION.pHelpData
;  .while xdi != NULL
;    mov xax, xdi
;    mov xdi, [xdi]
;    MemFree xax
;  .endw
  MemFree xbx
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     ObjMtdInfoCollection.GetItem
; Purpose:    Loads an item from a stream object.
; Arguments:  Arg1: -> Stream.
;             Arg2: -> DESER_INFO.
; Return:     xax -> New loaded OBJMTDINFORMATION structure.

Method ObjMtdInfoCollection.GetItem, uses xbx xdi xsi, pStream:$ObjPtr(Stream), pDeserInfo:PDESER_INFO
  local dSize:DWORD

  mov xbx, $MemAlloc(sizeof(OBJMTDINFORMATION))
  mov [xbx].OBJMTDINFORMATION.dFlags, $32($OCall(pStream::Stream.BinRead32))
  mov [xbx].OBJMTDINFORMATION.pObjectName, $OCall(pStream::Stream.StrRead)
  mov [xbx].OBJMTDINFORMATION.pName, $OCall(pStream::Stream.StrRead)
  mov [xbx].OBJMTDINFORMATION.dHelpLineCount, $32($OCall(pStream::Stream.BinRead32))
  mov xdi, xax
  lea xsi, [xbx].OBJMTDINFORMATION.pHelpData
  .while xdi != 0
    OCall pStream::Stream.BinRead32
    mov dSize, eax
    add eax, sizeof(POINTER)
    invoke StrAlloc, eax
    mov [xsi], xax
    mov xsi, xax
    add xax, sizeof(POINTER)
    OCall pStream::Stream.BinRead, xax, dSize
    dec edi
  .endw
  m2z POINTER ptr [xsi]
  OCall pStream::Stream.BinRead32                       ;FILEINFORMATION index
  SetObject xcx
  OCall [xcx].pFilesColl::FilesCollection.ItemAt, eax
  mov [xbx].OBJMTDINFORMATION.pFileInfo, xax
  mov [xbx].OBJMTDINFORMATION.pArguments, $OCall(pStream::Stream.StrRead)
  mov xax, xbx
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     ObjMtdInfoCollection.Init
; Purpose:    (Constructor) Initializes the object.
; Arguments:  Arg1: -> Owner object.
;             Arg2: Initial capacity of the collection (#items).
;             Arg3: Growing factor of the collection (#items).
;             Arg4: -> Files collection.
; Return:     Nothing.

Method ObjMtdInfoCollection.Init,, pOwner:POINTER, dLimit:DWORD, dDelta:DWORD, \
                                   pFilesColl:$ObjPtr(FilesCollection)
  SetObject xcx
  m2m [xcx].pFilesColl, pFilesColl, xdx
  ACall xcx.Init, pOwner, dLimit, dDelta, COL_MAX_CAPACITY
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     ObjMtdInfoCollection.PutItem
; Purpose:    Stores an item of the collection in a stream object.
; Arguments:  Arg1: -> Stream.
;             Arg2: -> OBJMTDINFORMATION.
; Return:     Nothing.

Method ObjMtdInfoCollection.PutItem, uses xbx xdi, pStream:$ObjPtr(Stream), pItem:POBJMTDINFORMATION
  mov xbx, pItem
  OCall pStream::Stream.BinWrite32, [xbx].OBJMTDINFORMATION.dFlags
  OCall pStream::Stream.StrWriteA, [xbx].OBJMTDINFORMATION.pObjectName
  OCall pStream::Stream.StrWriteA, [xbx].OBJMTDINFORMATION.pName
  OCall pStream::Stream.BinWrite32, [xbx].OBJMTDINFORMATION.dHelpLineCount
  mov xdi, [xbx].OBJMTDINFORMATION.pHelpData
  .while xdi != NULL
    lea xdx, [xdi + sizeof(POINTER)]
    OCall pStream::Stream.StrWriteA, xdx
    mov xdi, [xdi]
  .endw
  SetObject xcx
  OCall [xcx].pFilesColl::FilesCollection.IndexOf, [xbx].OBJMTDINFORMATION.pFileInfo
  OCall pStream::Stream.BinWrite32, eax
  OCall pStream::Stream.StrWriteA, [xbx].OBJMTDINFORMATION.pArguments
MethodEnd


; ==================================================================================================
;  ObjVarInfoCollection implementation
; ==================================================================================================

; --------------------------------------------------------------------------------------------------
; Method:     ObjVarInfoCollection.DestroyItem
; Purpose:    Overridden method.
; Arguments:  Arg1: -> OBJVARINFORMATION.
; Return:     Nothing.

Method ObjVarInfoCollection.DestroyItem, uses xbx xdi, pItem:POBJVARINFORMATION
  mov xbx, pItem
  invoke StrDispose, [xbx].OBJVARINFORMATION.pObjectName
  invoke StrDispose, [xbx].OBJVARINFORMATION.pName
  invoke StrDispose, [xbx].OBJVARINFORMATION.pArgType
  mov xdi, [xbx].OBJVARINFORMATION.pHelpData
  .while xdi != NULL
    mov xax, xdi
    mov xdi, [xdi]
    MemFree xax
  .endw
  MemFree xbx
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     ObjVarInfoCollection.GetItem
; Purpose:    Loads an item from a stream object.
; Arguments:  Arg1: -> Stream.
;             Arg2: -> DESER_INFO.
; Return:     xax -> New loaded OBJVARINFORMATION structure.

Method ObjVarInfoCollection.GetItem, uses xbx xdi xsi, pStream:$ObjPtr(Stream), pDeserInfo:PDESER_INFO
  local dSize:DWORD

  mov xbx, $MemAlloc(sizeof(OBJVARINFORMATION))
  mov [xbx].OBJVARINFORMATION.dFlags, $32($OCall(pStream::Stream.BinRead32))
  mov [xbx].OBJVARINFORMATION.pObjectName, $OCall(pStream::Stream.StrRead)
  mov [xbx].OBJVARINFORMATION.pName, $OCall(pStream::Stream.StrRead)
  mov [xbx].OBJVARINFORMATION.dHelpLineCount, $32($OCall(pStream::Stream.BinRead32))
  mov xdi, xax
  lea xsi, [xbx].OBJVARINFORMATION.pHelpData
  .while xdi != 0
    OCall pStream::Stream.BinRead32
    mov dSize, eax
    add eax, sizeof(POINTER)
    invoke StrAlloc, eax
    mov [xsi], xax
    mov xsi, xax
    add xax, sizeof(POINTER)
    OCall pStream::Stream.BinRead, xax, dSize
    dec edi
  .endw
  m2z POINTER ptr [xsi]
  OCall pStream::Stream.BinRead32                     ;FILEINFORMATION index
  SetObject xcx
  OCall [xcx].pFilesColl::FilesCollection.ItemAt, eax
  mov [xbx].OBJVARINFORMATION.pFileInfo, xax
  mov [xbx].OBJVARINFORMATION.pArgType, $OCall(pStream::Stream.StrRead)
  mov xax, xbx
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     ObjVarInfoCollection.Init
; Purpose:    (Constructor) Initializes the object.
; Arguments:  Arg1: -> Owner object.
;             Arg2: Initial capacity of the collection (#items).
;             Arg3: Growing factor of the collection (#items).
;             Arg4: -> Files collection.
; Return:     Nothing.

Method ObjVarInfoCollection.Init,, pOwner:POINTER, dLimit:DWORD, dDelta:DWORD, \
                                   pFilesColl:$ObjPtr(FilesCollection)
  SetObject xcx
  m2m [xcx].pFilesColl, pFilesColl, xdx
  ACall xcx.Init, pOwner, dLimit, dDelta, COL_MAX_CAPACITY
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     ObjVarInfoCollection.PutItem
; Purpose:    Stores an item of the collection in a stream object.
; Arguments:  Arg1: -> Stream.
;             Arg2: -> OBJVARINFORMATION.
; Return:     Nothing.

Method ObjVarInfoCollection.PutItem, uses xbx xdi, pStream:$ObjPtr(Stream), pItem:POBJVARINFORMATION
  mov xbx, pItem
  OCall pStream::Stream.BinWrite32, [xbx].OBJVARINFORMATION.dFlags
  OCall pStream::Stream.StrWriteA, [xbx].OBJVARINFORMATION.pObjectName
  OCall pStream::Stream.StrWriteA, [xbx].OBJVARINFORMATION.pName
  OCall pStream::Stream.BinWrite32, [xbx].OBJVARINFORMATION.dHelpLineCount
  mov xdi, [xbx].OBJVARINFORMATION.pHelpData
  .while xdi != NULL
    lea xdx, [xdi + sizeof(POINTER)]
    OCall pStream::Stream.StrWriteA, xdx
    mov xdi, [xdi]
  .endw
  SetObject xcx
  OCall [xcx].pFilesColl::FilesCollection.IndexOf, [xbx].OBJVARINFORMATION.pFileInfo
  OCall pStream::Stream.BinWrite32, eax
  OCall pStream::Stream.StrWriteA, [xbx].OBJVARINFORMATION.pArgType
MethodEnd


; ==================================================================================================
;  IntInfoCollection implementation
; ==================================================================================================

; --------------------------------------------------------------------------------------------------
; Method:     IntInfoCollection.Compare
; Purpose:    Compares the strings Key1 and Key2.
; Arguments:  Arg1: -> First key string.
;             Arg2: -> Second key string.
; Return:     eax = (-)  if Key1 < Key2
;                    0   if Key1 = Key2
;                   (+)  if Key1 > Key2

Method IntInfoCollection.Compare,, pKeyStr1:PSTRINGA, pKeyStr2:PSTRINGA
  invoke StrCompA, pKeyStr1, pKeyStr2
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     IntInfoCollection.DestroyItem
; Purpose:    Overridden method.
; Arguments:  Arg1: -> INTERFACEINFORMATION.
; Return:     Nothing.

Method IntInfoCollection.DestroyItem, uses xbx xdi, pItem:PINTERFACEINFORMATION
  mov xbx, pItem
  invoke StrDispose, [xbx].INTERFACEINFORMATION.pName
  invoke StrDispose, [xbx].INTERFACEINFORMATION.pAncestorName
;  mov xdi, [xbx].INTERFACEINFORMATION.pHelpData
;  .while xdi != NULL
;    mov xax, xdi
;    mov xdi, [xdi]
;    MemFree xax
;  .endw
  MemFree xbx
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     IntInfoCollection.GetItem
; Purpose:    Loads an item from a stream object.
; Arguments:  Arg1: -> Stream object containing an object.
;             Arg2: -> DESER_INFO.
; Return:     xax -> New loaded INTERFACEINFORMATION structure.

Method IntInfoCollection.GetItem, uses xbx xdi xsi, pStream:$ObjPtr(Stream), pDeserInfo:PDESER_INFO
  local dSize:DWORD

  mov xbx, $MemAlloc(sizeof(INTERFACEINFORMATION))
  mov [xbx].INTERFACEINFORMATION.dFlags, $32($OCall(pStream::Stream.BinRead32))
  mov [xbx].INTERFACEINFORMATION.pName, $OCall(pStream::Stream.StrRead)
  mov [xbx].INTERFACEINFORMATION.pAncestorName, $OCall(pStream::Stream.StrRead)
  mov [xbx].INTERFACEINFORMATION.dHelpLineCount, $32($OCall(pStream::Stream.BinRead32))
  mov edi, eax
  lea xsi, [xbx].INTERFACEINFORMATION.pHelpData
  .while edi != 0
    OCall pStream::Stream.BinRead32
    mov dSize, eax
    add eax, sizeof(POINTER)
    invoke StrAlloc, eax
    mov [xsi], xax
    mov xsi, xax
    add xax, sizeof(POINTER)
    OCall pStream::Stream.BinRead, xax, dSize
    dec edi
  .endw
  m2z POINTER ptr [xsi]
  OCall pStream::Stream.BinRead32
  SetObject xcx
  OCall [xcx].pFilesColl::FilesCollection.ItemAt, eax
  mov [xbx].INTERFACEINFORMATION.pFileInfo, xax
  mov xax, xbx
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     IntInfoCollection.KeyOf
; Purpose:    Overridden method.
; Arguments:  Arg1: -> INTERFACEINFORMATION.
; Return:     xax -> Sorting key of the item.

Method IntInfoCollection.KeyOf,, pItem:PINTERFACEINFORMATION
  mov xcx, pItem
  mov xax, [xcx].INTERFACEINFORMATION.pName
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     IntInfoCollection.Init
; Purpose:    (Constructor) Initializes the object.
; Arguments:  Arg1: -> Owner object.
;             Arg2: Initial capacity of the collection (#items).
;             Arg3: Growing factor of the collection (#items).
;             Arg4: -> Files collection.
; Return:     Nothing.

Method IntInfoCollection.Init,, pOwner:POINTER, dLimit:DWORD, dDelta:DWORD, \
                                pFilesColl:$ObjPtr(FilesCollection)
  SetObject xcx
  m2m [xcx].pFilesColl, pFilesColl, xdx
  mov [xcx].dDuplicates, TRUE
  ACall xcx.Init, pOwner, dLimit, dDelta, COL_MAX_CAPACITY
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     IntInfoCollection.PutItem
; Purpose:    Stores an item of the collection in a stream object.
; Arguments:  Arg1: -> Stream.
;             Arg2: -> INTERFACEINFORMATION.
; Return:     Nothing.

Method IntInfoCollection.PutItem, uses xbx xdi, pStream:$ObjPtr(Stream), pItem:PINTERFACEINFORMATION
  mov xbx, pItem
  OCall pStream::Stream.BinWrite32, [xbx].INTERFACEINFORMATION.dFlags
  OCall pStream::Stream.StrWriteA, [xbx].INTERFACEINFORMATION.pName
  OCall pStream::Stream.StrWriteA, [xbx].INTERFACEINFORMATION.pAncestorName
  OCall pStream::Stream.BinWrite32, [xbx].INTERFACEINFORMATION.dHelpLineCount
  mov xdi, [xbx].INTERFACEINFORMATION.pHelpData
  .while xdi != NULL
    lea xdx, [xdi + sizeof(POINTER)]
    OCall pStream::Stream.StrWriteA, xdx
    mov xdi, [xdi]
  .endw
  SetObject xcx
  OCall [xcx].pFilesColl::FilesCollection.IndexOf, [xbx].INTERFACEINFORMATION.pFileInfo
  OCall pStream::Stream.BinWrite32, eax
MethodEnd


; ==================================================================================================
;  IntMtdInfoCollection implementation
; ==================================================================================================

; --------------------------------------------------------------------------------------------------
; Method:     IntMtdInfoCollection.DestroyItem
; Purpose:    Overridden method.
; Arguments:  Arg1: -> INTMTDINFORMATION.
; Return:     Nothing.

Method IntMtdInfoCollection.DestroyItem, uses xbx xdi, pItem:PINTMTDINFORMATION
  mov xbx, pItem
  invoke StrDispose, [xbx].INTMTDINFORMATION.pInterfaceName
  invoke StrDispose, [xbx].INTMTDINFORMATION.pName
  invoke StrDispose, [xbx].INTMTDINFORMATION.pArguments
;  mov xdi, [xbx].INTMTDINFORMATION.pHelpData
;  .while xdi != NULL
;    mov xax, xdi
;    mov xdi, [xdi]
;    MemFree xax
;  .endw
  MemFree xbx
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     IntMtdInfoCollection.GetItem
; Purpose:    Loads an item from a stream object.
; Arguments:  Arg1: -> Stream object containing an object.
;             Arg2: -> DESER_INFO.
; Return:     xax -> New loaded INTMTDINFORMATION structure.

Method IntMtdInfoCollection.GetItem, uses xbx xdi xsi, pStream:$ObjPtr(Stream), pDeserInfo:PDESER_INFO
  local dSize:DWORD

  mov xbx, $MemAlloc(sizeof(INTMTDINFORMATION))
  mov [xbx].INTMTDINFORMATION.dFlags, $32($OCall(pStream::Stream.BinRead32))
  mov [xbx].INTMTDINFORMATION.pInterfaceName, $OCall(pStream::Stream.StrRead)
  mov [xbx].INTMTDINFORMATION.pName, $OCall(pStream::Stream.StrRead)
  mov [xbx].INTMTDINFORMATION.dHelpLineCount, $32($OCall(pStream::Stream.BinRead32))
  mov xdi, xax
  lea xsi, [xbx].INTMTDINFORMATION.pHelpData
  .while xdi != 0
    OCall pStream::Stream.BinRead32
    mov dSize, eax
    add eax, sizeof(POINTER)
    invoke StrAlloc, eax
    mov [xsi], xax
    mov xsi, xax
    add xax, sizeof(POINTER)
    OCall pStream::Stream.BinRead, xax, dSize
    dec edi
  .endw
  m2z POINTER ptr [xsi]
  OCall pStream::Stream.BinRead32                     ;FILEINFORMATION index
  SetObject xcx
  OCall [xcx].pFilesColl::FilesCollection.ItemAt, eax
  mov [xbx].INTMTDINFORMATION.pFileInfo, xax
  mov [xbx].INTMTDINFORMATION.pArguments, $OCall(pStream::Stream.StrRead)
  mov xax, xbx
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     IntMtdInfoCollection.Init
; Purpose:    (Constructor) Initializes the object.
; Arguments:  Arg1: -> Owner object.
;             Arg2: Initial capacity of the collection (#items).
;             Arg3: Growing factor of the collection (#items).
;             Arg4: -> Files collection.
; Return:     Nothing.

Method IntMtdInfoCollection.Init,, pOwner:POINTER, dLimit:DWORD, dDelta:DWORD, \
                                   pFilesColl:$ObjPtr(FilesCollection)
  SetObject xcx
  m2m [xcx].pFilesColl, pFilesColl, xdx
  ACall xcx.Init, pOwner, dLimit, dDelta, COL_MAX_CAPACITY
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     IntMtdInfoCollection.PutItem
; Purpose:    Stores an item of the collection in a stream object.
; Arguments:  Arg1: -> Stream.
;             Arg2: -> INTMTDINFORMATION.
; Return:     Nothing.

Method IntMtdInfoCollection.PutItem, uses xbx xdi, pStream:$ObjPtr(Stream), pItem:PINTMTDINFORMATION
  mov xbx, pItem
  OCall pStream::Stream.BinWrite32, [xbx].INTMTDINFORMATION.dFlags
  OCall pStream::Stream.StrWriteA, [xbx].INTMTDINFORMATION.pInterfaceName
  OCall pStream::Stream.StrWriteA, [xbx].INTMTDINFORMATION.pName
  OCall pStream::Stream.BinWrite32, [xbx].INTMTDINFORMATION.dHelpLineCount
  mov xdi, [xbx].INTMTDINFORMATION.pHelpData
  .while xdi != NULL
    OCall pStream::Stream.StrWriteA, addr [xdi + sizeof(POINTER)]
    mov xdi, [xdi]
  .endw
  SetObject xcx
  OCall [xcx].pFilesColl::FilesCollection.IndexOf, [xbx].INTERFACEINFORMATION.pFileInfo
  OCall pStream::Stream.BinWrite32, eax
  OCall pStream::Stream.StrWriteA, [xbx].INTMTDINFORMATION.pArguments
MethodEnd


; ==================================================================================================
;  ImpMtdInfoCollection implementation
; ==================================================================================================

; --------------------------------------------------------------------------------------------------
; Method:     ImpMtdInfoCollection.DestroyItem
; Purpose:    Overridden method.
; Arguments:  Arg1: -> IMPMTDINFORMATION.
; Return:     Nothing.

Method ImpMtdInfoCollection.DestroyItem, uses xbx xdi, pItem:PIMPMTDINFORMATION
  mov xbx, pItem
  invoke StrDispose, [xbx].IMPMTDINFORMATION.pObjectName
  invoke StrDispose, [xbx].IMPMTDINFORMATION.pName
  invoke StrDispose, [xbx].IMPMTDINFORMATION.pArguments
;  mov xdi, [xbx].IMPMTDINFORMATION.pHelpData
;  .while xdi != NULL
;    mov xax, xdi
;    mov xdi, [xdi]
;    MemFree xax
;  .endw
  MemFree xbx
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     ImpMtdInfoCollection.GetItem
; Purpose:    Loads an item from a stream object.
; Arguments:  Arg1: -> Stream object containing an object.
;             Arg2: -> DESER_INFO.
; Return:     xax -> New loaded IMPMTDINFORMATION structure.

Method ImpMtdInfoCollection.GetItem, uses xbx xdi xsi, pStream:$ObjPtr(Stream), pDeserInfo:PDESER_INFO
  local dSize:DWORD

  mov xbx, $MemAlloc(sizeof(IMPMTDINFORMATION))
  mov [xbx].IMPMTDINFORMATION.dFlags, $32($OCall(pStream::Stream.BinRead32))
  mov [xbx].IMPMTDINFORMATION.pObjectName, $OCall(pStream::Stream.StrRead)
  mov [xbx].IMPMTDINFORMATION.pName, $OCall(pStream::Stream.StrRead)
  mov [xbx].IMPMTDINFORMATION.dHelpLineCount, $32($OCall(pStream::Stream.BinRead32))
  mov edi, eax
  lea xsi, [xbx].IMPMTDINFORMATION.pHelpData
  .while edi != 0
    OCall pStream::Stream.BinRead32
    mov dSize, eax
    add eax, sizeof(POINTER)
    invoke StrAlloc, eax
    mov [xsi], xax
    mov xsi, xax
    add xax, sizeof(POINTER)
    OCall pStream::Stream.BinRead, xax, dSize
    dec edi
  .endw
  m2z POINTER ptr [xsi]
  OCall pStream::Stream.BinRead32                     ;FILEINFORMATION index
  SetObject xcx
  OCall [xcx].pFilesColl::FilesCollection.ItemAt, eax
  mov [xbx].IMPMTDINFORMATION.pFileInfo, xax
  mov [xbx].IMPMTDINFORMATION.pArguments, $OCall(pStream::Stream.StrRead)
  mov xax, xbx
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     ImpMtdInfoCollection.Init
; Purpose:    (Constructor) Initializes the object.
; Arguments:  Arg1: -> Owner object.
;             Arg2: Initial capacity of the collection (#items).
;             Arg3: Growing factor of the collection (#items).
;             Arg4: -> Files collection.
; Return:     Nothing.

Method ImpMtdInfoCollection.Init,, pOwner:POINTER, dLimit:DWORD, dDelta:DWORD, \
                                   pFilesColl:$ObjPtr(FilesCollection)
  SetObject xcx
  m2m [xcx].pFilesColl, pFilesColl, xdx
  ACall xcx.Init, pOwner, dLimit, dDelta, COL_MAX_CAPACITY
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     ImpMtdInfoCollection.PutItem
; Purpose:    Stores an item of the collection in a stream object.
; Arguments:  Arg1: -> Stream.
;             Arg2: -> IMPMTDINFORMATION.
; Return:     Nothing.

Method ImpMtdInfoCollection.PutItem, uses xbx xdi, pStream:$ObjPtr(Stream), pItem:PIMPMTDINFORMATION
  mov xbx, pItem
  OCall pStream::Stream.BinWrite32, [xbx].IMPMTDINFORMATION.dFlags
  OCall pStream::Stream.StrWriteA, [xbx].IMPMTDINFORMATION.pObjectName
  OCall pStream::Stream.StrWriteA, [xbx].IMPMTDINFORMATION.pName
  OCall pStream::Stream.BinWrite32, [xbx].IMPMTDINFORMATION.dHelpLineCount
  mov xdi, [xbx].IMPMTDINFORMATION.pHelpData
  .while xdi != NULL
    OCall pStream::Stream.StrWriteA, addr [xdi + sizeof(POINTER)]
    mov xdi, [xdi]
  .endw
  SetObject xcx
  OCall [xcx].pFilesColl::FilesCollection.IndexOf, [xbx].IMPMTDINFORMATION.pFileInfo
  OCall pStream::Stream.BinWrite32, eax
  OCall pStream::Stream.StrWriteA, [xbx].IMPMTDINFORMATION.pArguments
MethodEnd

endif