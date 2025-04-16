; ==================================================================================================
; Title:      DatabaseApp_Main.inc
; Author:     G. Friedrich
; Version:    See DatabaseApp.asm
; Purpose:    ObjAsm Database Application.
; ==================================================================================================


;Cities Database:
;
;  Number of records = ~2'800'000
;
;  Record Structure (bytes):
;  Field  Index Name     Type   Width  Decimals
;    1      0   CC_FIPS   C       2
;    2      1   CC_ISO    C       2
;    3      2   CITY_NAME C       50
;    4      3   ID        I       4
; *** Total ***                  58

;Rodam Database:
;
;  Number of records = 3'113
;
;  Record Structure (bytes):
;  Field  Index Name     Type   Width  Decimals
;    1      0   MFG       C       3
;    2      1   BRG_NBR   C      20
;    3      2   DPITCH    N       8       3
;    4      3   DROLL     N       8       3
;    5      4   ANG       N       5       2
;    6      5   NROLL     N       3
; *** Total ***                  48


USE_CITIES equ 1

ifdef USE_CITIES
  DB_TABLE_NAME     equ   "Cities.dbf"
  DB_INDEX_NAME     equ   "CitiesByName.ndx"
else

;  DB_TABLE_NAME     equ   "DBF\dbase_31.dbf"
  DB_TABLE_NAME     equ   "Rodam.dbf"
  DB_INDEX_NAME_0   equ   "RodamByMfg.ndx"
  DB_INDEX_NAME_1   equ   "RodamByNbr.ndx"
  DB_INDEX_NAME_2   equ   "RodamByDia.ndx"
endif

.const
align ALIGN_DATA
AppStatusbar DEF_STATUSBAR {IDC_APP_SBR, SBR_STYLE, 0, 2}
  DEF_STATUSBAR_PART {350, 200, 1, SBT_SUNKEN, NULL}
  DEF_STATUSBAR_PART {200,  -2, 0, SBT_SUNKEN, NULL}    ;Spring

; --------------------------------------------------------------------------------------------------

CStr szApplicationClass, "OAC_DatabaseExplorer"

Object Application, ApplicationID, SdiApp                  ;Single Document Interface App.
;  VirtualMethod     Check1
;  VirtualMethod     Check2
;  VirtualMethod     Check3
;  VirtualMethod     Check4
;  VirtualMethod     Check5
;  VirtualMethod     Check6
;  VirtualMethod     Check7
;  VirtualMethod     Check8
;  VirtualMethod     Check9
;  VirtualMethod     ListNDX

  RedefineMethod    Done
  RedefineMethod    Init
  VirtualMethod     Pack
  VirtualMethod     PackIndex,      PTaskStatus, $ObjPtr(DB_Index), XWORD
  VirtualMethod     PackTable,      PTaskStatus, XWORD, XWORD
  StaticMethod      Startup
  VirtualMethod     UpdateMenu
  VirtualMethod     UpdateStatusbar
  RedefineMethod    OnSize,         WPARAM, LPARAM

  VirtualEvent      OnCommand,      WM_COMMAND
  VirtualEvent      OnCreate,       WM_CREATE
  VirtualEvent      OnClose,        WM_CLOSE, WM_QUERYENDSESSION
  VirtualEvent      OnDestroy,      WM_DESTROY
  VirtualEvent      OnPaint,        WM_PAINT

  DefineVariable    pActiveIndex,   $ObjPtr(DB_Index),  NULL    ;-> Database index in use
  DefineVariable    dRecNo,         DB_DATA_LINK_TYPE,      0       ;Current RecNo
  DefineVariable    hMenu,          HMENU,              0

  DefineVariable    AppSetup,       APP_SETUP,  {0, FDF_DD?MM?YYYY, "/", ":", "."}

  Embed     StatusBar, Statusbar                                ;Statusbar object

  Embed     Table,  DB_Table                                    ;Database Table
  Embed     Query,  DB_Query                                    ;Database Query
ObjectEnd


.code
; ==================================================================================================
;    Application implementation
; ==================================================================================================

;include DatabaseApp_Checks.inc

; --------------------------------------------------------------------------------------------------
; Method:     Application.Done
; Purpose:    Finalize the SDI application object.
; Arguments:  None.
; Return:     Nothing.

Method Application.Done, uses xsi
  SetObject xsi
  OCall [xsi].StatusBar::Statusbar.Done
  OCall [xsi].Query::DB_Query.Done
  .if [xsi].Table.hFile != INVALID_HANDLE_VALUE
    OCall [xsi].Table::DB_Table.Done                    ;Close the database table & indexes!
  .endif
  ACall xsi.Done
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Application.Init
; Purpose:    Initialize the SDI application object.
; Arguments:  None.
; Return:     Nothing.

Method Application.Init, uses xbx xsi
  local Wwd:DWORD, Wht:DWORD
  local Wtx:DWORD, Wty:DWORD
  local dArguments:DWORD, pArguments:POINTER, pFileNameW:PSTRINGW, bArgumentBuffer[MAX_PATH]:CHRA
 
  SetObject xsi
  
  mov [xsi].pCommandLine, $invoke(GetCommandLineW)
  lea xdx, dArguments
  mov pArguments, $invoke(CommandLineToArgvW, xax, xdx)
  
  mov [xsi].hAccelerators, $invoke(LoadAccelerators, hInstance, $OfsCStr("ACCEL_APP"))

  mov Wwd, 500
  mov Wht, 350
  mov Wtx, $32($invoke(CenterForm, Wwd, $32($invoke(GetSystemMetrics, SM_CXSCREEN))))
  mov Wty, $32($invoke(CenterForm, Wht, $32($invoke(GetSystemMetrics, SM_CYSCREEN))))

  invoke CreateWindowEx, WS_EX_LEFT or WS_EX_APPWINDOW, \
                         offset(szApplicationClass), offset(szAppTitle), WS_OVERLAPPEDWINDOW, \
                         Wtx, Wty, Wwd, Wht, NULL, NULL, hInstance, pSelf

  invoke ShowWindow, [xsi].hWnd, SW_SHOWNORMAL
  invoke UpdateWindow, [xsi].hWnd
  mov [xsi].hMenu, $invoke(GetMenu, [xsi].hWnd)

  .if dArguments > 1
    OCall [xsi].Table::DB_Table.Init, xsi, addr [xsi].AppSetup
    mov xax, pArguments
    add xax, sizeof(PSTRINGW)
    mov xdx, PSTRINGW ptr [xax]
    if TARGET_STR_TYPE eq STR_TYPE_ANSI
      mov pFileNameW, xdx
      invoke WideCharToMultiByte, CP_ACP, 0, pFileNameW, -1, addr bArgumentBuffer, \
                                  lengthof(bArgumentBuffer), NULL, NULL
      lea xdx, bArgumentBuffer
    endif
    OCall [xsi].Table::DB_Table.Use, xdx
    mov [xsi].pActiveIndex, NULL
    mov [xsi].dRecNo, 0
    .if [xsi].Table.Descriptor.dNumRecs != 0
      inc [xsi].dRecNo
    .endif
    OCall xsi.UpdateMenu
    OCall xsi.UpdateStatusbar
    invoke LocalFree, pArguments
  .endif 

;  OCall [xsi].Table::DB_Table.Init, xsi, addr [xsi].AppSetup
;  OCall [xsi].Table::DB_Table.Use, $OfsCStr(DB_TABLE_NAME)
;  .if eax == OBJ_OK
;    mov [xsi].dRecNo, 0
;    .if [xsi].Table.Descriptor.dNumRecs != 0
;      inc [xsi].dRecNo
;    .endif
;
;    if FALSE
;      OCall [xsi].Table::DB_Table.IndexedOn, $OfsCStr(DB_INDEX_NAME_0)
;      OCall [xsi].Table::DB_Table.IndexedOn, $OfsCStr(DB_INDEX_NAME_2)
;      OCall [xsi].Table::DB_Table.IndexedOn, $OfsCStr(DB_INDEX_NAME_1)   ;xcx -> DB_Index
;      mov [xsi].pActiveIndex, xcx
;    else
;      ifdef USE_CITIES
;        New DB_Index
;        .if xax != NULL
;          mov [xsi].pActiveIndex, xax                     ;Store the new created DB_Index
;          OCall [xsi].Table.Fields::Collection.ItemAt, 2  ;xax -> DB_Field
;          OCall [xsi].pActiveIndex::DB_Index.New, xax, $OfsCStr(DB_INDEX_NAME)
;          OCall [xsi].pActiveIndex::DB_Index.Reindex
;          OCall [xsi].pActiveIndex::DB_Index.Flush
;        .endif
;      else
;        New DB_Index
;        .if xax != NULL
;          mov [xsi].pActiveIndex, xax                     ;Store the new created DB_Index
;          OCall [xsi].Table.Fields::Collection.ItemAt, 0  ;xax -> DB_Field
;          OCall [xsi].pActiveIndex::DB_Index.New, xax, $OfsCStr(DB_INDEX_NAME_0)
;          OCall xsi.Check6
;;          OCall [xsi].pActiveIndex::DB_Index.Reindex
;          OCall [xsi].pActiveIndex::DB_Index.Flush
;        .endif
;        New DB_Index
;        .if xax != NULL
;          mov [xsi].pActiveIndex, xax                     ;Store the new created DB_Index
;          OCall [xsi].Table.Fields::Collection.ItemAt, 2  ;xax -> DB_Field
;          OCall [xsi].pActiveIndex::DB_Index.New, xax, $OfsCStr(DB_INDEX_NAME_2)
;          OCall xsi.Check6
;;          OCall [xsi].pActiveIndex::DB_Index.Reindex
;          OCall [xsi].pActiveIndex::DB_Index.Flush
;        .endif
;        New DB_Index
;        .if xax != NULL
;          mov [xsi].pActiveIndex, xax                     ;Store the new created DB_Index
;          OCall [xsi].Table.Fields::Collection.ItemAt, 1  ;xax -> DB_Field
;          OCall [xsi].pActiveIndex::DB_Index.New, xax, $OfsCStr(DB_INDEX_NAME_1)
;          OCall xsi.Check6
;;          OCall [xsi].pActiveIndex::DB_Index.Reindex
;          OCall [xsi].pActiveIndex::DB_Index.Flush
;        .endif
;        New DB_Index
;        .if xax != NULL
;          mov [xsi].pActiveIndex, xax                     ;Store the new created DB_Index
;          OCall [xsi].Table.Fields::Collection.ItemAt, 6  ;xax -> DB_Field
;          OCall [xsi].pActiveIndex::DB_Index.New, xax, $OfsCStr(DB_INDEX_NAME_2)
;          OCall xsi.Check6
;;          OCall [xsi].pActiveIndex::DB_Index.Reindex
;          OCall [xsi].pActiveIndex::DB_Index.Flush
;        .endif
;      endif
;    endif
;  .endif

  OCall xsi.UpdateMenu
  OCall xsi.UpdateStatusbar

MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Application.OnCommand
; Purpose:    Event procedure for WM_COMMAND message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

SW_Start macro
  if DEBUGGING
    New SW::StopWatch
    OCall SW::StopWatch.Init, xsi
    invoke GetCurrentProcess
    mov xbx, xax
    invoke GetPriorityClass, xbx
    mov dPriorityClass, eax
    invoke SetPriorityClass, xbx, THREAD_PRIORITY_TIME_CRITICAL
    OCall SW::StopWatch.Start
  endif
endm

SW_End macro Remark
  if DEBUGGING
    OCall SW::StopWatch.Stop
    OCall SW::StopWatch.GetTimeStrA, addr bTimeStr
    invoke StrCatA, addr bTimeStr, $OfsCStrA(" µS")
    invoke SetPriorityClass, xbx, dPriorityClass
    DbgStrA bTimeStr, Remark
    OCall SW::StopWatch.Done
  endif
endm

ShowStatus macro
;  DbgObject xsi::Application,, "Status"
;  DbgObject [xsi].pActiveIndex::DB_Index,, "Status"
;  mov xbx, [xsi].pActiveIndex
;  DbgObject [xbx].$Obj(DB_Index).MemBlockCache::NdxMemBlockCache,, "Status"
;  mov xcx, [xbx].$Obj(DB_Index).pHeader
;  DbgDec [xcx].NDX_HEADER.dRootBlockNo,,  "Status"
;  DbgDec [xcx].NDX_HEADER.dFreeBlockNo,,  "Status"
;  DbgDec [xcx].NDX_HEADER.dBlockLength,,  "Status"
;  DbgDec [xcx].NDX_HEADER.wKeyLength,,    "Status"
;  DbgDec [xcx].NDX_HEADER.wKeysPerBlock,, "Status"
;  DbgDec [xcx].NDX_HEADER.bFieldDataType,,"Status"
;  DbgDec [xcx].NDX_HEADER.wEntryLength,,  "Status"
;  DbgDec [xcx].NDX_HEADER.wUnique,,       "Status"
;  DbgStrA [xcx].NDX_HEADER.bKeyField,,    "Status"
;  DbgLine2 "Status"
endm

Method Application.OnCommand, uses xbx xsi, wParam:WPARAM, lParam:LPARAM
  local AbtDlg:$Obj(DialogAbout), hIcon:HICON, SW:$Obj(StopWatch)
  local RecDlg:$Obj(DB_RecordEditorDlg), StrucDlg:$Obj(DB_StructEditorDlg)
  local IndexDlg:$Obj(DB_IndexDlg), SeekDlg:$Obj(DB_SeekDlg), NewTableDlg:$Obj(DB_NewTableDlg);, QueryDlg:$Obj(DB_QueryDlg)
  local bTimeStr[30]:BYTE, dPriorityClass:DWORD
  local pIFODlg: POINTER, MFS:MultiFileSpec, pIFileDialog2:POINTER
  local pISIArr:POINTER, dCount:DWORD, pIShellItem:POINTER, pDisplayName:POINTER
  local cBuffer[LOCAL_BUFFER_SIZE]:CHR

  ANNOTATION use:SW bTimeStr dPriorityClass xbx

  SetObject xsi
  mov xax, wParam

  .if ax == IDM_NEW
    New NewTableDlg::DB_NewTableDlg
    OCall NewTableDlg::DB_NewTableDlg.Init, xsi, [xsi].hWnd, addr cBuffer
    OCall NewTableDlg::DB_NewTableDlg.Show
    .if ax == IDOK
      .if [xsi].Table.hFile != INVALID_HANDLE_VALUE
        OCall [xsi].Table::DB_Table.Done
      .endif
      mov [xsi].pActiveIndex, NULL
      OCall [xsi].Table::DB_Table.Init, xsi, addr [xsi].AppSetup
      OCall [xsi].Table::DB_Table.New, addr cBuffer, TRUE
      .if eax == OBJ_OK
        New StrucDlg::DB_StructEditorDlg
        OCall StrucDlg::DB_StructEditorDlg.Init, xsi, [xsi].hWnd, addr [xsi].Table
        OCall StrucDlg::DB_StructEditorDlg.Show
        OCall StrucDlg::DB_StructEditorDlg.Done
      .endif
    .endif
    OCall NewTableDlg::DB_NewTableDlg.Done
    OCall xsi.UpdateMenu
    OCall xsi.UpdateStatusbar
    xor eax, eax

  .elseif ax == IDM_OPEN
    invoke CoCreateInstance, offset CLSID_FileOpenDialog, NULL, CLSCTX_INPROC_SERVER, \
                             offset IID_IFileOpenDialog, addr pIFODlg
    .if SUCCEEDED(eax)
      c2m MFS.FS0.pszName, $OfsCStr("All"), xax
      c2m MFS.FS0.pszSpec, $OfsCStr("*.*"), xcx
      c2m MFS.FS1.pszName, $OfsCStr("Database"), xax
      c2m MFS.FS1.pszSpec, $OfsCStr("*.dbf"), xcx

      ICall pIFODlg::IFileOpenDialog.SetFileTypes, sizeof(MultiFileSpec)/sizeof(COMDLG_FILTERSPEC), \
                                                   addr MFS
      ICall pIFODlg::IFileOpenDialog.SetFileTypeIndex, 2
      ICall pIFODlg::IFileOpenDialog.SetOptions, 0
      ICall pIFODlg::IFileOpenDialog.SetTitle, $OfsCStr("Open a Database Table...")
      ICall pIFODlg::IFileOpenDialog.SetOkButtonLabel, $OfsCStr("&Open")
      ICall pIFODlg::IFileOpenDialog.SetFileNameLabel, $OfsCStr("Selected file name: ")

      ICall pIFODlg::IFileOpenDialog.QueryInterface, offset IID_IFileDialog2, addr pIFileDialog2
      .if SUCCEEDED(eax)
        ICall pIFileDialog2::IFileDialog2.SetCancelButtonLabel, $OfsCStr("&Cancel")
        ICall pIFileDialog2::IFileDialog2.Release
      .endif

      ICall pIFODlg::IFileOpenDialog.Show, [xsi].hWnd
      .if SUCCEEDED(eax)
        ICall pIFODlg::IFileOpenDialog.GetResults, addr pISIArr
        ICall pISIArr::IShellItemArray.GetCount, addr dCount
        ICall pISIArr::IShellItemArray.GetItemAt, 0, addr pIShellItem
        ICall pIShellItem::IShellItem.GetDisplayName, SIGDN_FILESYSPATH, addr pDisplayName

        .if [xsi].Table.hFile != INVALID_HANDLE_VALUE
          OCall [xsi].Table::DB_Table.Done
        .endif
        OCall [xsi].Table::DB_Table.Init, xsi, addr [xsi].AppSetup
        OCall [xsi].Table::DB_Table.Use, pDisplayName
        mov [xsi].pActiveIndex, NULL
        mov [xsi].dRecNo, 0
        .if [xsi].Table.Descriptor.dNumRecs != 0
          inc [xsi].dRecNo
        .endif

        ICall pIShellItem::IShellItem.Release
        ICall pISIArr::IShellItemArray.Release
      .endif
      ICall pIFODlg::IFileOpenDialog.Release
    .endif
    OCall xsi.UpdateMenu
    OCall xsi.UpdateStatusbar
    xor eax, eax

  .elseif ax == IDM_CLOSE
    .if [xsi].Table.hFile != INVALID_HANDLE_VALUE
      OCall [xsi].Table::DB_Table.Done
      mov [xsi].dRecNo, 0
    .endif
    mov [xsi].pActiveIndex, NULL
    OCall xsi.UpdateMenu
    OCall xsi.UpdateStatusbar
    xor eax, eax

  .elseif ax == IDM_STRUCDSGN
    New StrucDlg::DB_StructEditorDlg
    OCall StrucDlg::DB_StructEditorDlg.Init, xsi, [xsi].hWnd, addr [xsi].Table
    OCall StrucDlg::DB_StructEditorDlg.Show
    OCall StrucDlg::DB_StructEditorDlg.Done
    OCall xsi.UpdateMenu
    OCall xsi.UpdateStatusbar
    xor eax, eax

  .elseif ax == IDM_INDEXING
    New IndexDlg::DB_IndexDlg
    OCall IndexDlg::DB_IndexDlg.Init, xsi, [xsi].hWnd, addr [xsi].Table
    OCall IndexDlg::DB_IndexDlg.Show
    OCall IndexDlg::DB_IndexDlg.Done
    OCall xsi.UpdateMenu
    OCall xsi.UpdateStatusbar
    xor eax, eax

  .elseif ax == IDM_PACK
    OCall xsi.Pack
    mov [xsi].dRecNo, 0
    .if [xsi].Table.Descriptor.dNumRecs != 0
      inc [xsi].dRecNo
    .endif
    OCall xsi.UpdateMenu
    OCall xsi.UpdateStatusbar
    xor eax, eax

  .elseif ax == IDM_ZAP
    invoke MessageBox, [xsi].hWnd, \
                       $OfsCStr("Are you sure you want to delete the database content?"), \
                       $OfsCStr("ATTENTION"), MB_YESNO or MB_DEFBUTTON2 or MB_ICONEXCLAMATION
    .if eax == IDYES
      mov [xsi].dRecNo, 0
      OCall [xsi].Table::DB_Table.Zap
      OCall xsi.UpdateMenu
      OCall xsi.UpdateStatusbar
    .endif
    xor eax, eax

  .elseif ax == IDM_EXIT
    invoke SendMessage, [xsi].hWnd, WM_SYSCOMMAND, SC_CLOSE, NULL
    .if [xsi].Table.hFile != INVALID_HANDLE_VALUE
      OCall [xsi].Table::DB_Table.Done
    .endif
    xor eax, eax

  .elseif ax == IDM_REC_TOP
    .if [xsi].pActiveIndex != NULL
      SW_Start
      mov [xsi].dRecNo, $32($OCall([xsi].pActiveIndex::DB_Index.SeekTop))
      SW_End "Seek top"
      OCall xsi.UpdateStatusbar
    .endif
    xor eax, eax

  .elseif ax == IDM_REC_BOTT
    .if [xsi].pActiveIndex != NULL
      SW_Start
      mov [xsi].dRecNo, $32($OCall([xsi].pActiveIndex::DB_Index.SeekBottom))
      SW_End "Seek bottom"
      OCall xsi.UpdateStatusbar
    .endif
    xor eax, eax

  .elseif ax == IDM_REC_NEXT
    .if [xsi].pActiveIndex != NULL
      .if [xsi].dRecNo != 0
        SW_Start
        mov [xsi].dRecNo, $32($OCall([xsi].pActiveIndex::DB_Index.Skip, 1))
        SW_End "Skip +1"
        .if eax == 0
          invoke MessageBox, [xsi].hWnd, \
            $OfsCStr($Esc("Bottom limit of Database reached\:\nContinue with a seek operation...")), \
            $OfsCStr("Database information..."), MB_ICONINFORMATION or MB_OK
        .endif
        OCall xsi.UpdateStatusbar
      .endif
    .endif
    xor eax, eax

  .elseif ax == IDM_REC_PREV
    .if [xsi].pActiveIndex != NULL
      .if [xsi].dRecNo != 0
        SW_Start
        mov [xsi].dRecNo, $32($OCall([xsi].pActiveIndex::DB_Index.Skip, -1))
        SW_End "Skip -1"
        .if eax == 0
          invoke MessageBox, [xsi].hWnd, \
            $OfsCStr($Esc("Top limit of Database reached\:\nContinue with a seek operation...")), \
            $OfsCStr("Database information..."), MB_ICONINFORMATION or MB_OK
        .endif
        OCall xsi.UpdateStatusbar
      .endif
    .endif
    xor eax, eax

  .elseif ax == IDM_REC_SEEK
    New SeekDlg::DB_SeekDlg
    OCall SeekDlg::DB_SeekDlg.Init, xsi, [xsi].hWnd, \
                                    addr [xsi].Table, [xsi].pActiveIndex, addr [xsi].dRecNo
    OCall SeekDlg::DB_SeekDlg.Show
    OCall SeekDlg::DB_SeekDlg.Done
    OCall xsi.UpdateStatusbar
    xor eax, eax

  .elseif ax == IDM_REC_EDIT
    New RecDlg::DB_RecordEditorDlg
    OCall RecDlg::DB_RecordEditorDlg.Init, xsi, [xsi].hWnd, addr [xsi].Table, [xsi].dRecNo
    OCall RecDlg::DB_RecordEditorDlg.Show
    ;Get the Index and last RecNo from the dialog
    m2m [xsi].pActiveIndex, RecDlg.pActiveIndex, xax
    m2m [xsi].dRecNo, RecDlg.dRecNo, xax
    OCall RecDlg::DB_RecordEditorDlg.Done
    OCall xsi.UpdateMenu
    OCall xsi.UpdateStatusbar
    xor eax, eax


;  .elseif ax == IDM_QRY_START1
;    OCall [xsi].pQuery::DBQuery.Start, 0, addr FilterProc1   ;MFG
;    New QueryDlg::DB_QueryDlg
;    OCall QueryDlg::DB_QueryDlg.Init, xsi, [xsi].hWnd, offset szDlgQuery
;    OCall QueryDlg::DB_QueryDlg.Show
;    OCall QueryDlg::DB_QueryDlg.Done
;    xor eax, eax
;
;  .elseif ax == IDM_QRY_START2
;    OCall [xsi].pQuery::DBQuery.Start, 1, addr FilterProc2   ;BRG_NBR
;    OCall QueryDlg::DB_QueryDlg.Init, xsi, [xsi].hWnd, offset szDlgQuery
;    OCall QueryDlg::DB_QueryDlg.Show
;    OCall QueryDlg::DB_QueryDlg.Done
;    xor eax, eax
;
;  .elseif ax == IDM_QRY_CLEAR
;    OCall [xsi].pQuery::DBQuery.DeleteAll
;    xor eax, eax
;
;  .elseif ax == IDM_QRY_VIEW
;    OCall QueryDlg::DB_QueryDlg.Init, xsi, [xsi].hWnd, offset szDlgQuery
;    OCall QueryDlg::DB_QueryDlg.Show
;    OCall QueryDlg::DB_QueryDlg.Done
;    xor eax, eax
;
;  .elseif ax == IDM_QRY_STORE
;    mov pStream, $New(DiskStream.Init, esi, offset szQueryFile)
;    OCall [xsi].pQuery::DBQuery.Store, pStream
;    Destroy pStream
;    xor eax, eax
;
;  .elseif ax == IDM_QRY_RECALL
;    mov pStream, $New(DiskStream.Init, esi, offset szQueryFile)
;    OCall [xsi].pQuery::DBQuery.Load, pStream, esi
;    Destroy pStream
;    xor eax, eax


;  .elseif ax == IDM_CHECK1
;    .if [xsi].pActiveIndex != NULL
;      SW_Start
;      OCall xsi.Check1
;      SW_End "Check 1"
;      mov [xsi].dRecNo, $32($OCall([xsi].pActiveIndex::DB_Index.SeekTop))
;      .if eax != 0
;        OCall xsi.UpdateStatusbar
;      .endif
;      ShowStatus
;    .endif
;    xor eax, eax
;
;  .elseif ax == IDM_CHECK2
;    .if [xsi].pActiveIndex != NULL
;      SW_Start
;      repeat 1;000
;      OCall xsi.Check2
;      endm
;      SW_End "Check 2"
;      mov [xsi].dRecNo, $32($OCall([xsi].pActiveIndex::DB_Index.SeekTop))
;      .if eax != 0
;        OCall xsi.UpdateStatusbar
;      .endif
;      ShowStatus
;    .endif
;    xor eax, eax
;
;  .elseif ax == IDM_CHECK3
;    .if [xsi].pActiveIndex != NULL
;      SW_Start
;      OCall xsi.Check3
;      SW_End "Check 3"
;      mov [xsi].dRecNo, $32($OCall([xsi].pActiveIndex::DB_Index.SeekTop))
;      .if eax != 0
;        OCall xsi.UpdateStatusbar
;      .endif
;      ShowStatus
;    .endif
;    xor eax, eax
;
;  .elseif ax == IDM_CHECK4
;    .if [xsi].pActiveIndex != NULL
;      SW_Start
;      OCall xsi.Check4
;      SW_End "Check 4"
;      mov [xsi].dRecNo, $32($OCall([xsi].pActiveIndex::DB_Index.SeekTop))
;      .if eax != 0
;        OCall xsi.UpdateStatusbar
;      .endif
;      ShowStatus
;    .endif
;    xor eax, eax
;
;  .elseif ax == IDM_CHECK5
;    .if [xsi].pActiveIndex != NULL
;      SW_Start
;      OCall xsi.Check5
;      SW_End "Check 5"
;      OCall xsi.UpdateStatusbar
;      ShowStatus
;    .endif
;    xor eax, eax
;
;  .elseif ax == IDM_CHECK6
;    .if [xsi].pActiveIndex != NULL
;      SW_Start
;      OCall xsi.Check6
;      SW_End "Check 6"
;      OCall xsi.UpdateStatusbar
;      ShowStatus
;    .endif
;    xor eax, eax
;
;  .elseif ax == IDM_CHECK7
;    SW_Start
;    OCall xsi.Check7
;    SW_End "Check 7"
;    OCall xsi.UpdateStatusbar
;    ShowStatus
;    xor eax, eax
;
;  .elseif ax == IDM_CHECK8
;    .if [xsi].pActiveIndex != NULL
;      SW_Start
;      OCall xsi.Check8
;      SW_End "Check 8"
;      OCall xsi.UpdateStatusbar
;      ShowStatus
;    .endif
;    xor eax, eax
;
;  .elseif ax == IDM_CHECK9
;    .if [xsi].pActiveIndex != NULL
;      SW_Start
;      OCall xsi.Check9
;      SW_End "Check 9"
;      OCall xsi.UpdateStatusbar
;      ShowStatus
;    .endif
;    xor eax, eax
;
;  .elseif ax == IDM_LIST_NDX
;    .if [xsi].pActiveIndex != NULL
;      SW_Start
;      OCall xsi.ListNDX
;      SW_End "List index"
;      OCall xsi.UpdateStatusbar
;      ShowStatus
;    .endif
;    xor eax, eax

  .elseif ax == IDM_ABOUT
    New AbtDlg::DialogAbout
    mov hIcon, $invoke(LoadIcon, hInstance, $OfsCStr("ICON_APP"))
    OCall AbtDlg::DialogAbout.Init, xsi, [xsi].hWnd, hIcon, offset(szAboutText)
    OCall AbtDlg::DialogAbout.Show
    OCall AbtDlg::DialogAbout.Done
    invoke DestroyIcon, hIcon
    xor eax, eax

  .else
    invoke DefWindowProc, [xsi].hWnd, WM_COMMAND, wParam, lParam
  .endif

MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Application.OnClose
; Purpose:    Event procedure for WM_CLOSE message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method Application.OnClose, uses xsi, wParam:WPARAM, lParam:LPARAM
  SetObject xsi
  invoke MessageBox, [xsi].hWnd, $OfsCStr("Are you sure ?"), $OfsCStr("Application exit"), \
                     MB_ICONQUESTION or MB_YESNO
  .if eax == IDNO
    xor eax, eax
  .else
    invoke DefWindowProc, [xsi].hWnd, WM_CLOSE, wParam, lParam
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Application.OnCreate
; Purpose:    Event procedure for WM_CREATE message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method Application.OnCreate, uses xsi, wParam:WPARAM, lParam:LPARAM
  SetObject xsi
  OCall [xsi].StatusBar::Statusbar.Init, xsi, [xsi].hWnd, offset(AppStatusbar)
  xor eax, eax
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Application.OnDestroy
; Purpose:    Event procedure for WM_DESTROY message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method Application.OnDestroy, uses xsi, wParam:WPARAM, lParam:LPARAM
  SetObject xsi
  invoke DestroyAcceleratorTable, [xsi].hAccelerators
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Application.OnPaint
; Purpose:    Event procedure for WM_PAINT message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method Application.OnPaint, uses xbx xsi, wParam:WPARAM, lParam:LPARAM
  local PS:PAINTSTRUCT, hDC:HDC, Rct:RECT

  SetObject xsi
  invoke BeginPaint, [xsi].hWnd, addr PS
  mov hDC, xax

  invoke GetWindowRect, [xsi].StatusBar.hWnd, addr Rct
  mov ebx, Rct.bottom
  sub ebx, Rct.top

  invoke GetClientRect, [xsi].hWnd, addr Rct
  sub Rct.bottom, ebx
  invoke DrawEdge, hDC, addr Rct, EDGE_SUNKEN, BF_RECT

  invoke EndPaint, [xsi].hWnd, addr PS
  mov eax, TRUE
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Application.OnSize
; Purpose:    Event procedure for WM_SIZE message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method Application.OnSize, uses xsi, wParam:WPARAM, lParam:LPARAM
  local Rct:RECT

  .if wParam != SIZE_MINIMIZED
    SetObject xsi
    invoke DefWindowProc, [xsi].hWnd, WM_SIZE, wParam, lParam
    invoke GetClientRect, [xsi].hWnd, addr Rct
    invoke MoveWindow, [xsi].StatusBar.hWnd, 0, 0, 0, 0, TRUE
    invoke UpdateWindow, [xsi].StatusBar.hWnd
  .endif

  xor eax, eax                ;Return zero
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Application.Pack
; Purpose:    Remove deleted records from database and update indexes.
; Arguments:  None.
; Return:     Nothing.

Method Application.Pack, uses xbx xdi xsi
  local ProgDlg:$Obj(DialogProgress), dTaskCount:DWORD
  local cBuffer[LOCAL_BUFFER_SIZE]:CHR, bBuffer[LOCAL_BUFFER_SIZE]:CHRA
  local bMsgBuffer[LOCAL_BUFFER_SIZE]:CHRA, pMemTasks:POINTER
  local pField:$ObjPtr(DB_Field), pIndex:$ObjPtr(DB_Index)

  SetObject xsi
  ;Get the number of necessary TaskSetup structures and get all changes
  mov dTaskCount, 1
  xor ebx, ebx
  .while ebx != [xsi].Table.Fields.dCount
    OCall [xsi].Table.Fields::Collection.ItemAt, ebx
    .if [xax].$Obj(DB_Field).pIndex != NULL
      inc dTaskCount
    .endif
    inc ebx
  .endw

  mov eax, dTaskCount
  imul eax, sizeof(TaskSetup)
  add eax, sizeof(TaskHeader)
  MemAlloc eax
  .if xax == NULL
    OCall xsi.ErrorReport, NULL, DB_OUT_OF_MEMORY
    DbgWarning "Application.Pack: Out of memory creating TaskSetups", offset(szDbgObjErr)
    ExitMethod
  .endif
  mov pMemTasks, xax
  mov xdi, xax

  ;Set Task header
  m2m [xdi].TaskHeader.dTaskCount, dTaskCount, eax
  c2m [xdi].TaskHeader.pMainDesc, $OfsCStrA("{\rtf1\sa50\fs19\b Description:\b0", \
      "\par\fs18 Deleted records are removed from the table.\line ", \
      "Indexes are updated accordingly.}"), xax
  c2m [xdi].TaskHeader.pOverallDesc, $OfsCStrA("{\rtf1\b Overall progress:\b0}"), xax
  mov [xdi].TaskHeader.hIcon, $invoke(LoadImage, hInstance, $OfsCStr("ICON_MUTATION"), \
                                      IMAGE_ICON, 0, 0, LR_DEFAULTCOLOR)
  add xdi, sizeof(TaskHeader)

  ;FIRST set Pack TaskSetup
  m2m [xdi].TaskSetup.pTaskProc, $MethodAddr(Application.PackTable), xax
  mov [xdi].TaskSetup.pOwner, xsi
  mov [xdi].TaskSetup.xParam1, 0
  mov [xdi].TaskSetup.xParam2, 0
  ProgressText textequ <{\rtf1\b Task:\b0  Deleted records on table \ul >
  FillTextA cBuffer, <%ProgressText>
  invoke PathFindFileName, [xsi].Table.pFileName
  lea xcx, [cBuffer + @SizeStr(%ProgressText)]
  if TARGET_STR_TYPE eq STR_TYPE_ANSI
    invoke StrECopy, xcx, xax
  else
    invoke StrW2StrA, xcx, xax
    invoke StrEndA, addr cBuffer
  endif
  FillStringA [xax], <\ul0  are being removed...}>
  mov [xdi].TaskSetup.pDescription, $invoke(StrNewA, addr cBuffer)
  m2m [xdi].TaskSetup.dPrgCntMax, [xsi].Table.Descriptor.dNumRecs, eax
  add xdi, sizeof(TaskSetup)

  ;NOW set index TaskSetup
  xor ebx, ebx
  .while TRUE
    .break .if ebx == [xsi].Table.Fields.dCount
    OCall [xsi].Table.Fields::Collection.ItemAt, ebx
    mov pField, xax
    .if [xax].$Obj(DB_Field).pIndex != NULL
      mov xdx, [xax].$Obj(DB_Field).pIndex
      mov pIndex, xdx
      if TARGET_STR_TYPE eq STR_TYPE_ANSI
        invoke StrCopy, addr bBuffer, [xdx].$Obj(DB_Index).pFileName
      else
        invoke StrW2StrA, addr bBuffer, [xdx].$Obj(DB_Index).pFileName
      endif
      m2m [xdi].TaskSetup.pTaskProc, $MethodAddr(Application.PackIndex), xax
      mov [xdi].TaskSetup.pOwner, xsi
      m2m [xdi].TaskSetup.xParam1, pIndex, xdx
      mov [xdi].TaskSetup.xParam2, 0

      invoke PathFindFileNameA, addr bBuffer
      ProgressText textequ <{\rtf1\b Task:\b0  Index \ul >
      FillTextA bMsgBuffer, <%ProgressText>
      lea xcx, [bMsgBuffer + @SizeStr(%ProgressText)]
      invoke StrECopyA, xcx, xax
      ProgressText textequ <\ul0  of table field >
      FillStringA [xax], <%ProgressText>
      mov xcx, pField
      add xax, @SizeStr(%ProgressText)
      lea xdx, [xcx].$Obj(DB_Field).Descriptor.bName
      invoke StrECopyA, xax, xdx
      FillStringA [xax], < is being updated...}>
      mov eax, [xsi].Table.Descriptor.dNumRecs
      add eax, eax                                  ;Best guess
      mov [xdi].TaskSetup.dPrgCntMax, eax
      mov [xdi].TaskSetup.pDescription, $invoke(StrNewA, addr bMsgBuffer)
      add xdi, sizeof(TaskSetup)
    .endif
    inc ebx
  .endw

  ;Invoke Progress dialog
  New ProgDlg::DialogProgress
  OCall ProgDlg::DialogProgress.Init, xsi, [xsi].hWnd, pMemTasks
  OCall ProgDlg::DialogProgress.Show
  OCall ProgDlg::DialogProgress.Done

  ;Free resources
  mov xdi, pMemTasks
;  invoke StrDisposeA, [xdi].TaskHeader.pMainDesc
;  invoke StrDisposeA, [xdi].TaskHeader.pOverallDesc
  invoke DestroyIcon, [xdi].TaskHeader.hIcon
  add xdi, sizeof(TaskHeader)                         ;Skip the overall setup
  xor ebx, ebx
  .while ebx < dTaskCount
    invoke StrDispose, [xdi].TaskSetup.pDescription   ;Does nothing if argument is NULL
    inc ebx
    add xdi, sizeof(TaskSetup)                        ;Move to next taskSetup
  .endw
  MemFree pMemTasks
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Application.PackIndex
; Purpose:    Update index as part of the Pack process.
; Arguments:  Arg1: -> TaskStatus.
;             Arg2: Unused.
;             Arg3: Unused.
; Return:     Nothing.

Method Application.PackIndex,, pStatus:PTaskStatus, pIndex:$ObjPtr(DB_Index), Unused2:XWORD
  DbgText "Application.PackIndex"
  OCall pIndex::DB_Index.Reindex, pStatus
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Application.PackTable
; Purpose:    Remove deleted records from the table as part of the Pack process.
; Arguments:  Arg1: -> TaskStatus.
;             Arg2: Unused.
;             Arg3: Unused.
; Return:     Nothing.

Method Application.PackTable, uses xbx xsi, pStatus:PTaskStatus, Unused1:XWORD, Unused2:XWORD
;  DbgText "Application.PackTable"
  SetObject xsi
  mov bl, [xsi].Table.Descriptor.bNdxOnDemand
  mov [xsi].Table.Descriptor.bNdxOnDemand, FALSE
  OCall [xsi].Table::DB_Table.Pack, pStatus
  mov [xsi].Table.Descriptor.bNdxOnDemand, bl
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Application.Startup
; Purpose:    Register the object class with the OS.
; Arguments:  None.
; Return:     Nothing.

Method Application.Startup
  local WC:WNDCLASSEX

  mov WC.cbSize, sizeof(WNDCLASSEX)
  mov WC.style, CLS_STYLE
  m2m WC.lpfnWndProc, $MethodAddr(Application.WndProc), xdx
  m2z WC.cbClsExtra
  m2z WC.cbWndExtra
  m2m WC.hInstance, hInstance, xdx
  invoke LoadBitmap, hInstance, $OfsCStr("BMP_BACKGROUND")
  mov WC.hbrBackground, $invoke(CreatePatternBrush, xax)
  c2m WC.lpszMenuName, $OfsCStr("MENU_APP"), xax
  c2m WC.lpszClassName, offset(szApplicationClass), xcx
  mov WC.hIcon, $invoke(LoadIcon, hInstance, $OfsCStr("ICON_APP"))
  mov WC.hCursor, $invoke(LoadCursor, 0, IDC_ARROW)
  mov WC.hIconSm, 0

  invoke RegisterClassEx, addr WC
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:    Application.UpdateMenu
; Purpose:   Enable or disable menu items according to the current database status.
; Arguments: None.
; Return:    Nothing.

Method Application.UpdateMenu, uses xsi
  SetObject xsi
  .if [xsi].Table.hFile == INVALID_HANDLE_VALUE
    invoke EnableMenuItem, [xsi].hMenu, IDM_NEW,          MF_ENABLED
    invoke EnableMenuItem, [xsi].hMenu, IDM_OPEN,         MF_ENABLED
    invoke EnableMenuItem, [xsi].hMenu, IDM_CLOSE,        MF_DISABLED
    invoke EnableMenuItem, [xsi].hMenu, IDM_STRUCDSGN,    MF_DISABLED
    invoke EnableMenuItem, [xsi].hMenu, IDM_INDEXING,     MF_DISABLED
    invoke EnableMenuItem, [xsi].hMenu, IDM_PACK,         MF_DISABLED
    invoke EnableMenuItem, [xsi].hMenu, IDM_ZAP,          MF_DISABLED
    invoke EnableMenuItem, [xsi].hMenu, IDM_RECORD,       MF_DISABLED
    invoke EnableMenuItem, [xsi].hMenu, IDM_REC_SEEK,     MF_DISABLED
  .else
    invoke EnableMenuItem, [xsi].hMenu, IDM_NEW,          MF_DISABLED
    invoke EnableMenuItem, [xsi].hMenu, IDM_OPEN,         MF_DISABLED
    invoke EnableMenuItem, [xsi].hMenu, IDM_CLOSE,        MF_ENABLED
    invoke EnableMenuItem, [xsi].hMenu, IDM_STRUCDSGN,    MF_ENABLED
    invoke EnableMenuItem, [xsi].hMenu, IDM_RECORD,       MF_ENABLED
    .if [xsi].Table.Descriptor.dNumRecs != 0
      invoke EnableMenuItem, [xsi].hMenu, IDM_INDEXING,   MF_ENABLED
      invoke EnableMenuItem, [xsi].hMenu, IDM_PACK,       MF_ENABLED
      invoke EnableMenuItem, [xsi].hMenu, IDM_ZAP,        MF_ENABLED
      invoke EnableMenuItem, [xsi].hMenu, IDM_REC_SEEK,   MF_ENABLED
      .if [xsi].pActiveIndex == NULL
        invoke EnableMenuItem, [xsi].hMenu, IDM_NAVIGATION, MF_DISABLED
      .else
        invoke EnableMenuItem, [xsi].hMenu, IDM_NAVIGATION, MF_ENABLED
      .endif
    .else
      invoke EnableMenuItem, [xsi].hMenu, IDM_INDEXING,   MF_DISABLED
      invoke EnableMenuItem, [xsi].hMenu, IDM_PACK,       MF_DISABLED
      invoke EnableMenuItem, [xsi].hMenu, IDM_ZAP,        MF_DISABLED
      invoke EnableMenuItem, [xsi].hMenu, IDM_REC_SEEK,   MF_DISABLED
      invoke EnableMenuItem, [xsi].hMenu, IDM_NAVIGATION, MF_DISABLED
    .endif

  .endif
  invoke DrawMenuBar, [xsi].hWnd
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:    Application.UpdateStatusbar
; Purpose:   Update the info on the Statusbar.
; Arguments: None.
; Return:    Nothing.

Method Application.UpdateStatusbar, uses xbx xdi xsi
  local cBuffer[LOCAL_BUFFER_SIZE]:CHR

  SetObject xsi
  lea xdi, cBuffer

  .if [xsi].Table.hFile == INVALID_HANDLE_VALUE
    FillString [xdi], <No table in use>
    OCall [xsi].StatusBar::Statusbar.SetPartText, 0, xdi, SBT_SUNKEN
    OCall [xsi].StatusBar::Statusbar.SetPartText, 1, NULL, SBT_SUNKEN
  .else
    PartStr textequ <Table: >
    FillString [xdi], <%PartStr>
    invoke StrCopy, addr [xdi + @SizeStr(%PartStr)*sizeof(CHR)], [xsi].Table.pFileName
    OCall [xsi].StatusBar::Statusbar.SetPartText, 0, xdi, SBT_SUNKEN
    FillString [xdi], < Record >
    lea xbx, [xdi + 8*sizeof(CHR)]
    invoke dword2dec, xbx, [xsi].dRecNo
    invoke StrLRTrim, xbx, xbx
    invoke StrEnd, xbx
    FillString [xax], < of >
    lea xbx, [xax + 4*sizeof(CHR)]
    invoke dword2dec, xbx, [xsi].Table.Descriptor.dNumRecs
    invoke StrLRTrim, xbx, xbx
    OCall [xsi].StatusBar::Statusbar.SetPartText, 1, xdi, SBT_SUNKEN
  .endif
MethodEnd
