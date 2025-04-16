; ==================================================================================================
; Title:      OAE_IntPropWnd.inc
; Author:     G. Friedrich
; Version:    Check OA_ObjExplorer.asm
; Purpose:    IntPropWnd implementation for OA_ObjExplorer.
; ==================================================================================================


; --------------------------------------------------------------------------------------------------
; Method:     IntPropWnd.Done
; Purpose:    Finalizes the IntPropWnd object and disposes the MDI child window.
; Arguments:  None.
; Return:     Nothing.

Method IntPropWnd.Done, uses xsi
  SetObject xsi

  ;Release internal data
  OCall [xsi].Methods::DataCollection.Done

  ;Final object cleanup
  ACall xsi.Done
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     IntPropWnd.Init
; Purpose:    Initalizes the IntPropWnd object.
; Arguments:  Arg1: -> Owner object (ClientWnd).
;             Arg2: -> Window Class name.
;             Arg2: -> PINTERFACEINFORMATION.
; Return:     Nothing.

Method IntPropWnd.Init, uses xsi, pOwner:$ObjPtr(ClientWnd), pWndClassName:PSTRING, \
                                  pInfo:PINTERFACEINFORMATION
  SetObject xsi
  OCall [xsi].Methods::DataCollection.Init, xsi, 50, 50, COL_MAX_CAPACITY
  ACall xsi.Init, pOwner, pWndClassName, pInfo
MethodEnd

; --------------------------------------------------------------------------------------------------
; Procedure:  ShowIntMtd
; Purpose:    Emits HTML codes to render interface method member information.
; Arguments:  Arg1: -> MEMBERDATA.
;             Arg2: -> IntPropWnd.
;             Arg3: Dummy.
; Return:     Nothing.

ShowIntMtd proc uses xbx xdi xsi pMemberData:PMEMBERDATA, pSelf:$ObjPtr(IntPropWnd), xDummy:XWORD
  local dBytesWritten:DWORD;, hHtmlFile:HANDLE

  mov xsi, pMemberData
  lea xdi, dBytesWritten
  mov xbx, [xsi].MEMBERDATA.pMemberInfo               ;ebx -> INTMTDINFORMATION
  .ifBitSet [xsi].MEMBERDATA.dFlags, MDT_UNKNOWN
;    invoke WriteFile, hHtmlFile, offset HTML_SEPARATOR, sizeof HTML_SEPARATOR, xdi, NULL
;    invoke WriteFile, hHtmlFile, offset HTML_MIS_00, HTML_MIS_00_SIZE, xdi, NULL
;    ;Attention: In this case ebx -> INTERFACEINFORMATION
;    invoke StrLength, [xbx].INTERFACEINFORMATION.pAncestorName
;    invoke WriteFile, hHtmlFile, [xbx].INTERFACEINFORMATION.pAncestorName, eax, xdi, NULL
;    invoke WriteFile, hHtmlFile, offset HTML_MIS_01, offset HTML_MIS_01_SIZE, xdi, NULL
;    invoke WriteFile, hHtmlFile, offset HTML_SEPARATOR, sizeof HTML_SEPARATOR, xdi, NULL
;    invoke WriteFile, hHtmlFile, offset HTML_MIS_02, offset HTML_MIS_02_SIZE, xdi, NULL
  .else
    mov xcx, pSelf
    .if [xcx].$Obj(IntPropWnd).dShowRedefMtds == FALSE
      .ifBitClr [xsi].MEMBERDATA.dFlags, MDT_FINAL
        ret
      .endif
    .endif

;    invoke WriteFile, hHtmlFile, offset HTML_IMD_01, HTML_IMD_01_SIZE, xdi, NULL
;    .if [xbx].INTMTDINFORMATION.dFlags == METHODTYPE_STANDARD
;      invoke WriteFile, hHtmlFile, offset HTML_INTMTD, sizeof HTML_INTMTD, xdi, NULL
;    .else
;      invoke WriteFile, hHtmlFile, offset HTML_INTDSP, sizeof HTML_INTDSP, xdi, NULL
;    .endif
;    invoke WriteFile, hHtmlFile, offset HTML_IMD_02, HTML_IMD_02_SIZE, xdi, NULL
;    .ifBitSet [xsi].MEMBERDATA.dFlags, MDT_FINAL
;      invoke WriteFile, hHtmlFile, offset HTML_COLOR_BLACK, sizeof HTML_COLOR_BLACK, xdi, NULL
;    .else
;      invoke WriteFile, hHtmlFile, offset HTML_COLOR_GRAY, sizeof HTML_COLOR_GRAY, xdi, NULL
;    .endif
;    invoke StrLength, [xbx].INTMTDINFORMATION.pInterfaceName
;    invoke WriteFile, hHtmlFile, [xbx].INTMTDINFORMATION.pInterfaceName, eax, xdi, NULL
;    invoke WriteFile, hHtmlFile, offset HTML_OMD_06, HTML_OMD_06_SIZE, xdi, NULL
;    .ifBitSet [xsi].MEMBERDATA.dFlags, MDT_FINAL
;      invoke WriteFile, hHtmlFile, offset HTML_OPEN_BOLD, sizeof HTML_OPEN_BOLD, xdi, NULL
;    .endif
;    mov ecx, [xbx].INTMTDINFORMATION.dFlags
;    invoke StrLength, [xbx].INTMTDINFORMATION.pName
;    invoke WriteFile, hHtmlFile, [xbx].INTMTDINFORMATION.pName, eax, xdi, NULL
;    mov ecx, [xbx].INTMTDINFORMATION.dFlags
;    .ifBitSet [xsi].MEMBERDATA.dFlags, MDT_FINAL
;      invoke WriteFile, hHtmlFile, offset HTML_CLOSE_BOLD, sizeof HTML_CLOSE_BOLD, xdi, NULL
;    .endif
;    invoke WriteFile, hHtmlFile, offset HTML_OMD_07, HTML_OMD_07_SIZE, xdi, NULL
;    invoke WriteFile, hHtmlFile, offset HTML_OMD_08, HTML_OMD_08_SIZE, xdi, NULL
;    .ifBitSet [xsi].MEMBERDATA.dFlags, MDT_FINAL
;      invoke WriteFile, hHtmlFile, offset HTML_COLOR_BLACK, sizeof HTML_COLOR_BLACK, xdi, NULL
;    .else
;      invoke WriteFile, hHtmlFile, offset HTML_COLOR_GRAY, sizeof HTML_COLOR_GRAY, xdi, NULL
;    .endif
;    invoke WriteFile, hHtmlFile, offset HTML_SEPARATOR, sizeof HTML_SEPARATOR, xdi, NULL
;    mov eax, [xbx].INTMTDINFORMATION.dFlags
;    lea xcx, OMT_TEXT_TABLE
;    mov xbx, PSTRING ptr [xcx + sizeof(PSTRING)*xax]
;    invoke StrLength, xbx
;    invoke WriteFile, hHtmlFile, xbx, eax, xdi, NULL
;    invoke WriteFile, hHtmlFile, offset HTML_SEPARATOR, sizeof HTML_SEPARATOR, xdi, NULL
;    invoke WriteFile, hHtmlFile, offset HTML_OMD_10, HTML_OMD_10_SIZE, xdi, NULL
;    invoke WriteFile, hHtmlFile, offset HTML_OMD_11, HTML_OMD_11_SIZE, xdi, NULL
;    .ifBitSet [xsi].MEMBERDATA.dFlags, MDT_SHOWDETAIL
;      invoke WriteFile, hHtmlFile, offset HTML_OMC_00, HTML_OMC_00_SIZE, xdi, NULL
;      .ifBitSet [xsi].MEMBERDATA.dFlags, MDT_FINAL
;        invoke WriteFile, hHtmlFile, offset HTML_COLOR_BLACK, sizeof HTML_COLOR_BLACK, xdi, NULL
;      .else
;        invoke WriteFile, hHtmlFile, offset HTML_COLOR_GRAY, sizeof HTML_COLOR_GRAY, xdi, NULL
;      .endif
;      invoke WriteFile, hHtmlFile, offset bCRLF, 2, xdi, NULL
;      invoke WriteFile, hHtmlFile, offset HTML_OMC_01, HTML_OMC_01_SIZE, xdi, NULL
;    .endif
  .endif
  ret
ShowIntMtd endp

; --------------------------------------------------------------------------------------------------
; Macro:      OutputFileInfo
; Purpose:    Compares the current and the stored FileTime data and emits HTML codes to display it.
; Arguments:  Arg1: FileTimeVar.
;             Arg2: Evaluate flag.
; Return:     Nothing.

OutputFileInfo macro FileTimeVar:req, Evaluate:=<0>           ;xbx must -> filename
  invoke StrLength, xbx
  invoke WriteFile, [xsi].hHtmlFile, xbx, eax, xdi, NULL
  invoke WriteFile, [xsi].hHtmlFile, offset HTML_FLS_04, HTML_FLS_04_SIZE, xdi, NULL
  .if $invoke(FileExist, xbx) != FALSE
    invoke CreateFile, xbx, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_ARCHIVE, 0
    mov xbx, xax
    lea xax, FileTimeVar
    invoke GetFileTime, xbx, NULL, NULL, xax                  ;Get LastWriteTime
    invoke CloseHandle, xbx
    invoke FileTimeToSystemTime, addr FileTimeVar, addr SysTimeUTC
    invoke SystemTimeToTzSpecificLocalTime, NULL, addr SysTimeUTC, addr SysTimeLocal
    movzx eax, SysTimeLocal.wSecond
    mov dSecond, eax
    movzx eax, SysTimeLocal.wMinute
    mov dMinute, eax
    movzx eax, SysTimeLocal.wHour
    mov dHour, eax
    movzx eax, SysTimeLocal.wYear
    mov dYear, eax
    movzx eax, SysTimeLocal.wMonth
    mov dMonth, eax
    movzx eax, SysTimeLocal.wDay
    mov dDay, eax
    lea xbx, cBuffer
    invoke wsprintf, xbx, $OfsCStr("%02d/%02d/%02d %02d:%02d:%02d"), dDay, dMonth, dYear, dHour, dMinute, dSecond
    invoke WriteFile, [xsi].hHtmlFile, xbx, eax, xdi, NULL
    invoke WriteFile, [xsi].hHtmlFile, offset HTML_FLS_05, HTML_FLS_05_SIZE, xdi, NULL
    if Evaluate eq 0
      invoke WriteFile, [xsi].hHtmlFile, offset HTML_COLOR_BLACK, sizeof HTML_COLOR_BLACK, xdi, NULL
      invoke WriteFile, [xsi].hHtmlFile, offset HTML_SEPARATOR, sizeof HTML_SEPARATOR, xdi, NULL
      invoke WriteFile, [xsi].hHtmlFile, offset HTML_OK, sizeof HTML_OK, xdi, NULL
      invoke WriteFile, [xsi].hHtmlFile, offset HTML_SEPARATOR, sizeof HTML_SEPARATOR, xdi, NULL
    else
      invoke CompareFileTime, addr LastWriteTimeLib, addr LastWriteTimeDef
      mov ebx, eax
      invoke CompareFileTime, addr LastWriteTimeLib, addr LastWriteTimeAsm
      or eax, ebx
      .ifBitSet eax, BIT31
        invoke WriteFile, [xsi].hHtmlFile, offset HTML_COLOR_RED, sizeof HTML_COLOR_RED, xdi, NULL
        invoke WriteFile, [xsi].hHtmlFile, offset HTML_SEPARATOR, sizeof HTML_SEPARATOR, xdi, NULL
        invoke WriteFile, [xsi].hHtmlFile, offset HTML_OUTDATED, sizeof HTML_OUTDATED, xdi, NULL
        invoke WriteFile, [xsi].hHtmlFile, offset HTML_SEPARATOR, sizeof HTML_SEPARATOR, xdi, NULL
      .else
        invoke WriteFile, [xsi].hHtmlFile, offset HTML_COLOR_BLACK, sizeof HTML_COLOR_BLACK, xdi, NULL
        invoke WriteFile, [xsi].hHtmlFile, offset HTML_SEPARATOR, sizeof HTML_SEPARATOR, xdi, NULL
        invoke WriteFile, [xsi].hHtmlFile, offset HTML_OK, sizeof HTML_OK, xdi, NULL
        invoke WriteFile, [xsi].hHtmlFile, offset HTML_SEPARATOR, sizeof HTML_SEPARATOR, xdi, NULL
  .endif
    endif
  .else
    invoke WriteFile, [xsi].hHtmlFile, offset HTML_FNF_01, HTML_FNF_01_SIZE, xdi, NULL
    invoke WriteFile, [xsi].hHtmlFile, offset HTML_FLS_05, HTML_FLS_05_SIZE, xdi, NULL
    invoke WriteFile, [xsi].hHtmlFile, offset HTML_COLOR_RED, sizeof HTML_COLOR_RED, xdi, NULL
    invoke WriteFile, [xsi].hHtmlFile, offset HTML_SEPARATOR, sizeof HTML_SEPARATOR, xdi, NULL
    invoke WriteFile, [xsi].hHtmlFile, offset HTML_FNF_00, HTML_FNF_00_SIZE, xdi, NULL
    invoke WriteFile, [xsi].hHtmlFile, offset HTML_SEPARATOR, sizeof HTML_SEPARATOR, xdi, NULL
  .endif
endm

; --------------------------------------------------------------------------------------------------
; Method:     IntPropWnd.Gather
; Purpose:    Collect all informations of this object.
; Arguments:  None.
; Return:     Nothing.

Method IntPropWnd.Gather, uses xsi
  SetObject xsi
  OCall xsi.GatherMethods, [xsi].pInfo
MethodEnd

; --------------------------------------------------------------------------------------------------
; Procedure:  GatherIntMtds
; Purpose:    Recursion procedure used to collect interface method information.
; Arguments:  Arg1: -> INTMTDINFORMATION.
;             Arg2: -> Interface name.
;             Arg3: -> IntPropWnd.
; Return:     Nothing.

GatherIntMtds proc uses xbx xdi xsi pIntMtdInfo:PINTMTDINFORMATION, pInterfaceName:PSTRING, pSelf:$ObjPtr(IntPropWnd)
  SetObject xsi, IntPropWnd
  mov xbx, pIntMtdInfo
  .if $invoke(StrCompA, [xbx].INTMTDINFORMATION.pInterfaceName, pInterfaceName) == 0
    mov xdi, $MemAlloc(sizeof(MEMBERDATA))
    mov [xdi].MEMBERDATA.pMemberInfo, xbx
    mov [xdi].MEMBERDATA.dFlags, MDT_FINAL
    m2z [xdi].MEMBERDATA.pDefinition
    .if [xbx].INTMTDINFORMATION.dFlags == METHODTYPE_REDEFINED
      OCall [xsi].Methods::DataCollection.LastThatNot, offset FindFinalMember, xdi, NULL
    .endif
    OCall [xsi].Methods::DataCollection.Insert, xdi
  .endif
  ret
GatherIntMtds endp

; --------------------------------------------------------------------------------------------------
; Method:     IntPropWnd.GatherMethods
; Purpose:    Collect all method information of this object.
; Arguments:  Arg1: -> OBJECTINFORMATION.
; Return:     Nothing.

Method IntPropWnd.GatherMethods, uses xsi, pInfo:PINTERFACEINFORMATION
  SetObject xsi
  OCall [xsi].Methods::DataCollection.DisposeAll

  mov xcx, pInfo
  mov xdx, [xcx].INTERFACEINFORMATION.pAncestorName
  .if xdx != NULL
    OCall $ObjTmpl(Application)::Application.FindIntInfo, xdx
    .if xax != NULL
      OCall xsi.GatherMethods, xax
    .else
      ;Stop recursion
      MemAlloc sizeof(MEMBERDATA)
      OCall [xsi].Methods::DataCollection.Insert, xax
      m2m [xax].MEMBERDATA.pMemberInfo, pInfo, xdx
      mov [xax].MEMBERDATA.dFlags, MDT_UNKNOWN
      m2z [xax].MEMBERDATA.pDefinition
    .endif
  .endif

  mov xax, pInfo
  mov xcx, $ObjTmpl(Application).pObjDB
  OCall [xcx].$Obj(OA_ObjDB).IntMethodColl::IntMtdInfoCollection.ForEach, \
                                         offset GatherIntMtds, [xax].INTERFACEINFORMATION.pName, xsi
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     IntPropWnd.ShowInheritance
; Purpose:    Method that is called recursively to output an inheritance path.
; Arguments:  Arg1: -> INTERFACENFORMATION.
;             Arg2: Flag to signal if the current item should generate a link.
; Return:     Nothing.

Method IntPropWnd.ShowInheritance, uses xbx xdi xsi, pInterfaceInfo:PINTERFACEINFORMATION, dLink:DWORD
  local dBytesWritten:DWORD;, cHexBuffer[12]:CHR

  SetObject xsi
  lea xdi, dBytesWritten
  mov xcx, pInterfaceInfo
  mov xbx, [xcx].INTERFACEINFORMATION.pAncestorName
  .if xbx != NULL
    OCall $ObjTmpl(Application)::Application.FindIntInfo, xbx
    .if xax != NULL
      OCall xsi::IntPropWnd.ShowInheritance, xax, TRUE
    .else
      ;Stop recursion
;      invoke WriteFile, [xsi].hHtmlFile, offset HTML_ANF_00, HTML_ANF_00_SIZE, xdi, NULL
;      invoke StrLength, xbx
;      invoke WriteFile, [xsi].hHtmlFile, xbx, eax, xdi, NULL
;      invoke WriteFile, [xsi].hHtmlFile, offset HTML_ANF_01, HTML_ANF_01_SIZE, xdi, NULL
    .endif
;    invoke WriteFile, [xsi].hHtmlFile, offset HTML_INH_04, HTML_INH_04_SIZE, xdi, NULL
  .endif

  mov xcx, pInterfaceInfo
  mov xbx, [xcx].INTERFACEINFORMATION.pName
;  .if dLink != FALSE
;    invoke WriteFile, [xsi].hHtmlFile, offset HTML_INH_01, HTML_INH_01_SIZE, xdi, NULL
;    invoke xword2hex, addr cHexBuffer, pInterfaceInfo
;    invoke WriteFile, [xsi].hHtmlFile, addr cHexBuffer, TARGET_BITNESS/4, xdi, NULL
;    invoke WriteFile, [xsi].hHtmlFile, offset HTML_INH_02, HTML_INH_02_SIZE, xdi, NULL
;    invoke StrLength, xbx
;    invoke WriteFile, [xsi].hHtmlFile, xbx, eax, xdi, NULL
;    invoke WriteFile, [xsi].hHtmlFile, offset HTML_INH_03, HTML_INH_03_SIZE, xdi, NULL
;  .else
;    invoke WriteFile, [xsi].hHtmlFile, offset HTML_INH_05, HTML_INH_05_SIZE, xdi, NULL
;    invoke StrLength, xbx
;    invoke WriteFile, [xsi].hHtmlFile, xbx, eax, xdi, NULL
;    invoke WriteFile, [xsi].hHtmlFile, offset HTML_INH_06, HTML_INH_06_SIZE, xdi, NULL
;  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     IntPropWnd.Startup
; Purpose:    Registers the object with the OS.
; Arguments:  None.
; Return:     Nothing.

Method IntPropWnd.Startup
  local WC:WNDCLASSEX

  mov WC.cbSize, sizeof WNDCLASSEX
  mov WC.style, CS_HREDRAW or CS_VREDRAW or CS_BYTEALIGNWINDOW or CS_BYTEALIGNCLIENT
  m2m WC.lpfnWndProc, $MethodAddr(IntPropWnd.WndProc), xdx
  mov WC.cbClsExtra, 0
  mov WC.cbWndExtra, 0
  m2m WC.hInstance, hInstance, xdx
  mov WC.hbrBackground, 0
  mov WC.lpszMenuName, NULL
  m2m WC.lpszClassName, offset cIntPropClass, xax
  mov WC.hIcon, $invoke(LoadIcon, hInstance, $OfsCStr("ICON_INT_STD"))
  mov WC.hIconSm, 0
  mov WC.hCursor, $invoke(LoadCursor, NULL, IDC_ARROW)

  invoke RegisterClassEx, addr WC
MethodEnd


