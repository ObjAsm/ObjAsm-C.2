; ==================================================================================================
; Title:      DatabaseApp_Checks.inc
; Author:     G. Friedrich
; Version:    See DatabaseApp.asm
; Purpose:    ObjAsm Database Application.
; ==================================================================================================


; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Application.Check1
; Purpose:    Perform a check on the Database. Count number of records using "skip +1".
; Arguments:  None.
; Return:     eax = TRUE if the check was successfull.

Method Application.Check1, uses xbx xdi xsi r12
  LocReg pPos:$SubReg(r12, @WordSize)
;  local cBuffer[100*sizeof(CHR)]:CHR
;  local cNumber[20*sizeof(CHR)]:CHR
;  local cField[100*sizeof(CHR)]:CHR

  SetObject xsi
  OCall [xsi].StatusBar::Statusbar.SetPartText, 2, $OfsCStr("Working..."), SBT_SUNKEN
  OCall [xsi].pActiveIndex::DB_Index.SeekTop                     ;eax = Record number

  xor ebx, ebx
  .repeat
    mov edi, eax
    inc ebx
;    FillString cBuffer, < Pass: >
;    invoke dword2dec, addr cNumber, ebx
;    invoke StrLRTrim, addr cNumber, addr cNumber
;    invoke StrECat, addr cBuffer, addr cNumber
;    FillString [xax], < [Rec: >
;    invoke dword2dec, addr cNumber, edi
;    invoke StrLRTrim, addr cNumber, addr cNumber
;    invoke StrECat, addr cBuffer, addr cNumber
;    FillString [xax], <] = >
;    mov $LocReg(pPos), xax
;    OCall [xsi].DBT::DB_Table.DataGetFrom, edi, 1          ;eax = Result, xcx -> Data, edx = Data size
;    mov eax, edx
;    mov xdx, xcx
;    if TARGET_STR_TYPE eq STR_TYPE_ANSI
;      invoke StrCCopyA, $LocReg(pPos), xdx, eax
;    else
;      lea xcx, cField
;      invoke StrCCopyA, xcx, xdx, eax
;      invoke StrA2StrW, $LocReg(pPos), addr cField
;    endif
;    OCall [xsi].StatusBar::Statusbar.SetPartText, 1, addr cBuffer, SBT_SUNKEN

    OCall [xsi].pActiveIndex::DB_Index.Skip, +1                  ;eax = next record number
  .until eax == 0                                       ;eax = 0 => end of database

  .if ebx == [xsi].Table.Descriptor.dNumRecs
    OCall [xsi].StatusBar::Statusbar.SetPartText, 2, $OfsCStr("Test passed"), SBT_SUNKEN
    mov eax, TRUE
  .else
    OCall [xsi].StatusBar::Statusbar.SetPartText, 2, $OfsCStr("Test failed"), SBT_SUNKEN
    xor eax, eax
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Application.Check2
; Purpose:    Perform a check on the Database. Loop through every record using seek and
;             verify the result.
; Arguments:  None.
; Return:     eax = TRUE if the check was successfull.

Method Application.Check2, uses xbx xdi xsi
  local bBuffer1[100*sizeof(CHR)]:CHR
  local bBuffer2[100]:CHRA
;  local bNumber[20*sizeof(CHR)]:CHR

  SetObject xsi
  OCall [xsi].StatusBar::Statusbar.SetPartText, 2, $OfsCStr("Working..."), SBT_SUNKEN
;  OCall [xsi].pActiveIndex::DB_Index.Reindex
;  OCall [xsi].pActiveIndex::DB_Index.SeekTop                     ;eax = number of the first record
  xor ebx, ebx
  lea xdi, bBuffer1
  .repeat
    inc ebx
    OCall [xsi].Table::DB_Table.DataGetFrom, ebx, 2           ;eax = Result, xcx -> Data, edx = data size
    mov eax, edx
    mov xdx, xcx
    lea xcx, bBuffer2
    invoke StrCCopyA, xcx, xdx, eax                     ;Copy record content to bBuffer2
;    FillString bBuffer1, < Rec: >
;    invoke dword2dec, addr bNumber, ebx
;    lea xax, bNumber
;    invoke StrLRTrim, xax, xax
;    invoke StrECat, xdi, addr bNumber
;    FillWord [xax], < = >
;    lea xcx, [xax + 3*sizeof(CHR)]
;    if TARGET_STR_TYPE eq STR_TYPE_WIDE
;      invoke StrA2StrW, xcx, addr bBuffer2
;    else
;      invoke StrCopy, xcx, addr bBuffer2
;    endif
;    OCall [xsi].StatusBar::Statusbar.SetPartText, 1, xdi, SBT_SUNKEN

    OCall [xsi].pActiveIndex::DB_Index.Seek, addr bBuffer2
    test eax, eax
    jz @@Error
    OCall [xsi].Table::DB_Table.DataGetFrom, eax, 2
    mov eax, edx
    lea xdx, bBuffer2
    invoke StrCCompA, xcx, xdx, eax
    test eax, eax
    jnz @@Error
  .until ebx >= [xsi].Table.Descriptor.dNumRecs
  OCall [xsi].StatusBar::Statusbar.SetPartText, 2, $OfsCStr("Test passed"), SBT_SUNKEN
  mov eax, TRUE
  ExitMethod
@@Error:
  OCall [xsi].StatusBar::Statusbar.SetPartText, 2, $OfsCStr("Test failed"), SBT_SUNKEN
  xor eax, eax                                      ;eax = FALSE
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Application.Check3
; Purpose:    Perform a check on the Database. Check if the index file is properly sorted.
; Arguments:  None.
; Return:     eax = TRUE if the check was successfull.

Method Application.Check3, uses xbx xdi xsi r12 r13
  LocReg pData:$SubReg(r12, @WordSize), dDataSize:r13d
  local bBuffer[1000]:CHRA, dFieldIndex:DWORD

  SetObject xsi
  OCall [xsi].StatusBar::Statusbar.SetPartText, 2, $OfsCStr("Working..."), SBT_SUNKEN

  mov xax, [xsi].pActiveIndex
  OCall [xsi].Table.Fields::Collection.IndexOf, [xax].$Obj(DB_Index).pOwner
  mov dFieldIndex, eax

  lea xbx, bBuffer
  xor edi, edi
  OCall [xsi].pActiveIndex::DB_Index.SeekTop                     ;eax = first record in the database
  OCall [xsi].Table::DB_Table.DataGetFrom, eax, dFieldIndex   ;eax = Result, xcx -> Data, edx = Data size
  mov eax, edx
  mov xdx, xcx
  invoke StrCCopyA, xbx, xdx, eax
  inc edi

  .repeat
    OCall [xsi].pActiveIndex::DB_Index.Skip, +1
    .break .if eax == 0                                 ;eax = 0 => end of database
    OCall [xsi].Table::DB_Table.DataGetFrom, eax, dFieldIndex
    mov $LocReg(pData), xcx
    mov $LocReg(dDataSize), edx
    invoke StrCCompA, xbx, $LocReg(pData), $LocReg(dDataSize)
    .if SDWORD ptr eax > 0
      DbgWarning "Corrupted index file..."
      DbgStrA $LocReg(pData)
      OCall [xsi].StatusBar::Statusbar.SetPartText, 2, $OfsCStr("Test failed"), SBT_SUNKEN
      xor eax, eax
      jmp @@Error
    .endif
    invoke StrCCopyA, xbx, $LocReg(pData), $LocReg(dDataSize)
    inc edi
  .until FALSE
  OCall [xsi].StatusBar::Statusbar.SetPartText, 2, $OfsCStr("Test passed"), SBT_SUNKEN
  mov eax, TRUE
  ExitMethod
@@Error:
  OCall [xsi].StatusBar::Statusbar.SetPartText, 2, $OfsCStr("Test failed"), SBT_SUNKEN
  xor eax, eax                                      ;eax = FALSE
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Application.Check4
; Purpose:    Perform a check on the Database. Delete each item from the index.
; Arguments:  None.
; Return:     eax = TRUE if the check was successfull.

Method Application.Check4, uses xbx xsi
  SetObject xsi
  OCall [xsi].StatusBar::Statusbar.SetPartText, 2, $OfsCStr("Working..."), SBT_SUNKEN

  xor ebx, ebx
  .repeat
    inc ebx
    OCall [xsi].pActiveIndex::DB_Index.SeekTop
    .break .if eax == 0
    OCall [xsi].pActiveIndex::DB_Index.Skip, +1
    .break .if eax == 0
    OCall [xsi].pActiveIndex::DB_Index.DeleteKey

    OCall [xsi].pActiveIndex::DB_Index.SeekBottom
    .break .if eax == 0
    OCall [xsi].pActiveIndex::DB_Index.Skip, -1
    .break .if eax == 0
    OCall [xsi].pActiveIndex::DB_Index.DeleteKey
  .until ebx == [xsi].Table.Descriptor.dNumRecs
  OCall [xsi].StatusBar::Statusbar.SetPartText, 2, $OfsCStr("Test passed"), SBT_SUNKEN
  mov eax, TRUE
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Application.Check5
; Purpose:    Perform a check on the Database. Delete each item from the index.
; Arguments:  None.
; Return:     eax = TRUE if the check was successfull.

Method Application.Check5, uses xbx xdi xsi
  local dFieldIndex:DWORD

  SetObject xsi
  OCall [xsi].StatusBar::Statusbar.SetPartText, 2, $OfsCStr("Working..."), SBT_SUNKEN

  mov xax, [xsi].pActiveIndex
  OCall [xsi].Table.Fields::Collection.IndexOf, [xax].$Obj(DB_Index).pOwner
  mov dFieldIndex, eax

  xor ebx, ebx
  .repeat
    inc ebx
    OCall [xsi].Table::DB_Table.DataGetFrom, ebx, dFieldIndex ;eax = Result, xcx -> Data, edx = data size
    mov xdx, xcx
    mov xdi, xcx
    OCall [xsi].pActiveIndex::DB_Index.Seek, xdx
    .if eax == 0
      DbgWarning "Key not found"
      DbgDec ebx
      DbgStrA xdi
      jmp @@Error
    .endif
    OCall [xsi].pActiveIndex::DB_Index.DeleteKey
  .until ebx == [xsi].Table.Descriptor.dNumRecs

  mov xdi, [xsi].pActiveIndex
  OCall [xdi].$Obj(DB_Index).MemBlockCache::NdxMemBlockCache.CheckLocks

  OCall [xsi].StatusBar::Statusbar.SetPartText, 2, $OfsCStr("Test ready"), SBT_SUNKEN
  mov eax, TRUE
  ExitMethod
@@Error:
  OCall [xsi].StatusBar::Statusbar.SetPartText, 2, $OfsCStr("Test failed"), SBT_SUNKEN
  xor eax, eax                                      ;eax = FALSE
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Application.Check6
; Purpose:    Insert an all items of the database.
; Arguments:  None.
; Return:     eax = TRUE if the check was successfull.

Method Application.Check6, uses xbx xdi xsi
  local dFieldIndex:DWORD

  SetObject xsi
  OCall [xsi].StatusBar::Statusbar.SetPartText, 2, $OfsCStr("Working..."), SBT_SUNKEN

  ;Find the DB_Field index the DB_Index is build on
  mov xax, [xsi].pActiveIndex
  OCall [xsi].Table.Fields::Collection.IndexOf, [xax].$Obj(DB_Index).pOwner
  mov dFieldIndex, eax

  ;Insert all records
  mov xdi, [xsi].pActiveIndex
  xor ebx, ebx
  .repeat
    inc ebx
    OCall [xsi].Table::DB_Table.DataGetFrom, ebx, dFieldIndex ;eax = Result, xcx -> Data, edx = data size
    mov xdx, xcx
    OCall xdi::DB_Index.InsertKey, xdx, ebx
  .until ebx >= [xsi].Table.Descriptor.dNumRecs

  ;Index intergrity check
  mov ebx, [xsi].Table.Descriptor.dNumRecs
  .repeat
    OCall [xsi].Table::DB_Table.DataGetFrom, ebx, dFieldIndex ;eax = Result, xcx -> Data, edx = data size
    mov xdx, xcx
    mov xdi, xcx
    OCall [xsi].pActiveIndex::DB_Index.Seek, xdx
    .if eax == 0
      ;Not found !!!!!!!!!
      DbgWarning "Integrity test failed: key not found"
      DbgDec ebx
      DbgStrA xdi
      jmp @@Error
    .endif
    dec ebx
  .until ZERO?

  mov xdi, [xsi].pActiveIndex
  OCall [xdi].$Obj(DB_Index).MemBlockCache::NdxMemBlockCache.CheckLocks

  OCall [xsi].StatusBar::Statusbar.SetPartText, 2, $OfsCStr("Test ready"), SBT_SUNKEN
  mov eax, TRUE
  ExitMethod

@@Error:
  OCall [xsi].StatusBar::Statusbar.SetPartText, 2, $OfsCStr("Test failed"), SBT_SUNKEN
  xor eax, eax                                      ;eax = FALSE
MethodEnd
; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Application.Check7
; Purpose:    Displays database objects.
; Arguments:  None.
; Return:     eax = TRUE if the check was successfull.

Method Application.Check7, uses xbx xdi xsi
  SetObject xsi
  OCall [xsi].StatusBar::Statusbar.SetPartText, 2, $OfsCStr("Working..."), SBT_SUNKEN

  lea xbx, [xsi].Table
  DbgObject xbx::DB_Table
  xor edi, edi
  .while TRUE
    .break .if edi == [xbx].$Obj(DB_Table).Fields.dCount
    OCall [xbx].$Obj(DB_Table).Fields::Collection.ItemAt, edi
    DbgObject xax::DB_Field
    inc edi
  .endw
  DbgLine2

  OCall [xsi].StatusBar::Statusbar.SetPartText, 2, $OfsCStr("Ready"), SBT_SUNKEN
  xor eax, eax                                      ;eax = FALSE
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Application.Check8
; Purpose:    Perform a check on the Database. Insert an item.
; Arguments:  None.
; Return:     eax = TRUE if the check was successfull.

SwapCount = 1536

Method Application.Check8, uses xbx xdi xsi r12 r13 r14 r15
  local XWC1:$Obj(XWCollection), XWC2:$Obj(XWCollection)
  local dMasterCounter:DWORD, dFieldIndex:DWORD

  SetObject xsi

  mov xax, [xsi].pActiveIndex
  OCall [xsi].Table.Fields::Collection.IndexOf, [xax].$Obj(DB_Index).pOwner
  mov dFieldIndex, eax

  OCall [xsi].pActiveIndex::DB_Index.Reindex, NULL
  OCall [xsi].StatusBar::Statusbar.SetPartText, 2, $OfsCStr("Working..."), SBT_SUNKEN

  New XWC1::XWCollection
  OCall XWC1::XWCollection.Init, xsi, 1000, 1000, COL_MAX_CAPACITY

  New XWC2::XWCollection
  OCall XWC2::XWCollection.Init, xsi, 1000, 1000, COL_MAX_CAPACITY

  xor ebx, ebx
  .repeat
    inc ebx
    OCall XWC1::XWCollection.Insert, xbx
  .until ebx == 3113

  m2z dMasterCounter
  .repeat
    inc dMasterCounter
    mov edx, XWC1.dCount
    dec edx
    shr edx, 1
    mov edi, edx
    OCall XWC1::XWCollection.ItemAt, edi
    OCall [xsi].Table::DB_Table.DataGetFrom, eax, dFieldIndex  ;eax = Result, xcx -> Data, edx = data size
    mov xdx, xcx
;    mov r15, xcx
    OCall [xsi].pActiveIndex::DB_Index.Seek, xdx
    .if eax == 0
      DbgWarning "Key not found"
      DbgDec dMasterCounter
;      DbgStrA r15
      jmp @@Error
    .endif
    OCall [xsi].pActiveIndex::DB_Index.DeleteKey
    OCall XWC1::XWCollection.DeleteAt, edi
    OCall XWC2::XWCollection.Insert, xax
  .until dMasterCounter == 1556

  m2z dMasterCounter
  .repeat
    inc dMasterCounter
    DbgDec dMasterCounter

    xor ebx, ebx
    .repeat
      mov ecx, XWC1.$Obj(XWCollection).dCount
      dec ecx
      invoke Random32, ecx
      mov edi, eax
      OCall XWC1::XWCollection.ItemAt, edi
      OCall [xsi].Table::DB_Table.DataGetFrom, eax, dFieldIndex  ;eax = Result, xcx -> Data, edx = data size
      mov xdx, xcx
;      mov r15, xcx
      OCall [xsi].pActiveIndex::DB_Index.Seek, xdx
      .if eax == 0
        DbgWarning "Key not found"
        DbgDec dMasterCounter
;        DbgStrA r15
        jmp @@Error
      .endif
      OCall [xsi].pActiveIndex::DB_Index.DeleteKey
      OCall XWC1::XWCollection.DeleteAt, edi
      OCall XWC2::XWCollection.Insert, xax
      inc ebx
    .until ebx == SwapCount
;    DbgText "To XWC2 done"

    xor ebx, ebx
    .repeat
      mov ecx, XWC2.$Obj(XWCollection).dCount
      dec ecx
      invoke Random32, ecx
      mov edi, eax
      OCall XWC2::XWCollection.ItemAt, edi
;      mov r12d, eax
      OCall [xsi].Table::DB_Table.DataGetFrom, eax, dFieldIndex ;eax = Result, xcx -> Data, edx = data size
      mov xdx, xcx
;      OCall [xsi].pActiveIndex::DB_Index.InsertKey, xdx, r12d
      OCall XWC2::XWCollection.DeleteAt, edi
      OCall XWC1::XWCollection.Insert, xax
      inc ebx
    .until ebx == SwapCount
;    DbgText "To XWC1 done"

    ;Index intergrity check
    mov ebx, XWC1.$Obj(XWCollection).dCount
    .repeat
      dec ebx
      OCall XWC1::XWCollection.ItemAt, ebx
      OCall [xsi].Table::DB_Table.DataGetFrom, eax, dFieldIndex ;eax = Result, xcx -> Data, edx = data size
      mov xdx, xcx
;      mov r14, xcx
      OCall [xsi].pActiveIndex::DB_Index.Seek, xdx
      .if eax == 0
        DbgWarning "Integrity test failed: key not found"
        DbgDec dMasterCounter
        DbgDec ebx
;        DbgStrA r14
;        DbgStrA r15
        jmp @@Error
      .endif
    .until ebx == 0
 ;   DbgText "Check done"
    DbgDec dMasterCounter

  .until dMasterCounter == 100000

  mov edi, XWC2.$Obj(XWCollection).dCount
  .repeat
    dec edi
    OCall XWC2::XWCollection.ItemAt, edi
;    mov r12d, eax
    OCall [xsi].Table::DB_Table.DataGetFrom, eax, dFieldIndex ;eax = Result, xcx -> Data, edx = data size
    mov xdx, xcx
;    OCall [xsi].pActiveIndex::DB_Index.InsertKey, xdx, r12d
    OCall XWC2::XWCollection.DeleteAt, edi
    OCall XWC1::XWCollection.Insert, xax
  .until edi == 0

  DbgDec XWC1.$Obj(XWCollection).dCount
  DbgDec XWC2.$Obj(XWCollection).dCount

  mov xax, [xsi].pActiveIndex
  DbgDec [xax].$Obj(DB_Index).dEOFBlockNo

  OCall [xsi].StatusBar::Statusbar.SetPartText, 2, $OfsCStr("Test ready"), SBT_SUNKEN
  OCall XWC1::XWCollection.Done
  OCall XWC2::XWCollection.Done
  mov eax, TRUE
  ExitMethod
@@Error:
  OCall [xsi].StatusBar::Statusbar.SetPartText, 2, $OfsCStr("Test failed"), SBT_SUNKEN
  OCall XWC1::XWCollection.Done
  OCall XWC2::XWCollection.Done
  xor eax, eax                                      ;eax = FALSE
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Application.Check9
; Purpose:    Perform a check on the Database index.
; Arguments:  None.
; Return:     eax = TRUE if the check was successfull.

Method Application.Check9, uses xbx xdi xsi
  local dFieldIndex:DWORD

  SetObject xsi
  OCall [xsi].StatusBar::Statusbar.SetPartText, 2, $OfsCStr("Working..."), SBT_SUNKEN

  ;Find the DB_Field index the DB_Index is build on
  mov xax, [xsi].pActiveIndex
  mov xdx, [xax].$Obj(DB_Index).pOwner
  DbgStrCA [xdx].$Obj(DB_Field).Descriptor.bName, DB_FIELD_NAME_SIZE
  OCall [xsi].Table.Fields::Collection.IndexOf, xdx
  mov dFieldIndex, eax

  ;Index intergrity check
  xor ebx, ebx
  .repeat
    inc ebx
    OCall [xsi].Table::DB_Table.DataGetFrom, ebx, dFieldIndex ;eax = Result, xcx -> Data, edx = data size
    mov xdx, xcx
    mov xdi, xcx
    OCall [xsi].pActiveIndex::DB_Index.Seek, xdx
    .if eax == 0
      DbgWarning "Integrity test failed: key not found"
      DbgDec ebx
      DbgStrA xdi
;      jmp @@Error
    .endif
  .until ebx == [xsi].Table.Descriptor.dNumRecs

  DbgText "Index integrity check done"
  OCall [xsi].StatusBar::Statusbar.SetPartText, 2, $OfsCStr("Test ready"), SBT_SUNKEN
  mov eax, TRUE
  ExitMethod
@@Error:
  OCall [xsi].StatusBar::Statusbar.SetPartText, 2, $OfsCStr("Test failed"), SBT_SUNKEN
  xor eax, eax                                      ;eax = FALSE
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Application.ListNDX
; Purpose:    Outputs the index blocks on DebugCenter.
; Arguments:  None.
; Return:     Nothing.

Method Application.ListNDX, uses xbx xdi xsi
  local dBlockNo:DWORD, dEntryIndex:DWORD, xEntryLen:XWORD, dKeyLen:DWORD
  local qFileSize:QWORD, dBlockCount:DWORD

  if DEBUGGING

  SetObject xsi
  OCall [xsi].StatusBar::Statusbar.SetPartText, 2, $OfsCStr("Working..."), SBT_SUNKEN

  mov xdi, [xsi].pActiveIndex
  mov xdx, [xdi].$Obj(DB_Index).pHeader

  DbgText "Header Information *****************************************************************************", "Index listing"
  DbgDec [xdx].NDX_HEADER.dRootBlockNo,,  "Index listing"
  DbgDec [xdx].NDX_HEADER.dFreeBlockNo,,  "Index listing"
  DbgDec [xdx].NDX_HEADER.dBlockLength,,  "Index listing"
  DbgDec [xdx].NDX_HEADER.wKeyLength,,    "Index listing"
  DbgDec [xdx].NDX_HEADER.wKeysPerBlock,, "Index listing"
  DbgDec [xdx].NDX_HEADER.bFieldDataType,,"Index listing"
  DbgDec [xdx].NDX_HEADER.wEntryLength,,  "Index listing"
  DbgDec [xdx].NDX_HEADER.wUnique,,       "Index listing"
  DbgStrA [xdx].NDX_HEADER.bKeyField,,    "Index listing"

  movzx xax, [xdx].NDX_HEADER.wKeyLength
  mov dKeyLen, eax
  add xax, NDX_LINK_SIZE
  mov xEntryLen, xax

  ;Write all buffers to file to get the correct file size
  OCall [xdi].$Obj(DB_Index).MemBlockCache::NdxMemBlockCache.Flush
  invoke GetFileSizeEx, [xdi].$Obj(DB_Index).hFile, addr qFileSize
  mov eax, DWORD ptr [qFileSize]
  mov edx, DWORD ptr [qFileSize + sizeof(DWORD)]
  div [xdi].$Obj(DB_Index).dBlockLength
  dec eax                                               ;Don't add the header in the count
  mov dBlockCount, eax
  DbgDec dBlockCount, "Total number of blocks", "Index listing"

  .if dBlockCount > 0
    ;Save all NdxMemBlocks in the cache
    OCall [xdi].$Obj(DB_Index).MemBlockCache::NdxMemBlockCache.Flush
    BitClr dDbgOpt, DBG_OPT_SHOWINFO
    mov dBlockNo, 1
    .repeat
      OCall [xdi].$Obj(DB_Index).MemBlockCache::NdxMemBlockCache.Get, dBlockNo    ;xcx -> NdxMemBlock
      .break .if eax != OBJ_OK
      DbgText "BLOCK ==============================================================================", "Index listing"
      DbgDec dBlockNo,, "Index listing"
      DbgDec [xcx].$Obj(NdxMemBlock).Buffer.wKeyCount,, "Index listing"
      DbgBin [xcx].$Obj(NdxMemBlock).Buffer.wFlags,, "Index listing"
      movzx ebx, [xcx].$Obj(NdxMemBlock).Buffer.wKeyCount
      m2z dEntryIndex
      test ebx, ebx
      .while !ZERO?
        DbgText "Entry ..................................................", "Index listing"
        DbgDec dEntryIndex,, "Index listing"
        DbgDec [xcx].$Obj(NdxMemBlock).Buffer.Entries.dRecNo,, "Index listing"
        DbgStrCA [xcx].$Obj(NdxMemBlock).Buffer.Entries.bKey, dKeyLen,, "Index listing"
        add xcx, xEntryLen
        inc dEntryIndex
        dec ebx
      .endw
      DbgText "::::::::::::::::::::::::::::::::::::::::::::::::::::::::", "Index listing"
      DbgDec [xcx].$Obj(NdxMemBlock).Buffer.Entries.dGT_BlockNo,, "Index listing"

      inc dBlockNo
      mov eax, dBlockNo
    .until eax > dBlockCount
    BitSet dDbgOpt, DBG_OPT_SHOWINFO
  .endif

  OCall [xsi].StatusBar::Statusbar.SetPartText, 2, NULL, SBT_SUNKEN
  mov eax, TRUE

  endif
MethodEnd
