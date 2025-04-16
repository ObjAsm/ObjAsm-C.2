; ==================================================================================================
; Title:      OAE_PropWnd.inc
; Author:     G. Friedrich
; Version:    Check OA_ObjExplorer.asm
; Purpose:    PropWnd implementation for OA_ObjExplorer.
; ==================================================================================================


VIEW_CTRL_ID equ 546983

$OfsSze macro TextRef:req
% exitm <offset TextRef, sizeof(TextRef)>
endm

; --------------------------------------------------------------------------------------------------
; Procedure:  FindFinalMember
; Purpose:    Used with Collection.LastThatNot to reset the MDT_FINAL flag.
; Arguments:  Arg1: -> Iterated MEMBERDATA.
;             Arg2: -> Source MEMBERDATA.
;             Arg3: Dummy.
; Return:     eax = Zero stops the iteration.

FindFinalMember proc pMemberData:PMEMBERDATA, pSrcData:PMEMBERDATA, xDummy:XWORD
  mov xax, pMemberData
  mov xdx, [xax].MEMBERDATA.pMemberInfo
  mov xcx, pSrcData
  mov xax, [xcx].MEMBERDATA.pMemberInfo
  invoke StrCompA, [xax].INFORMATION.pName, [xdx].INFORMATION.pName
  .if eax == 0                                          ;Method/Variable found
    mov xcx, pMemberData
    BitClr [xcx].MEMBERDATA.dFlags, MDT_FINAL           ;Reset the flag
    mov xdx, [xcx].MEMBERDATA.pDefinition
    .if xdx == NULL
      mov xdx, [xcx].MEMBERDATA.pMemberInfo
    .endif
    mov xcx, pSrcData
    mov [xcx].MEMBERDATA.pDefinition, xdx               ;Copy pDefinition from MemberData in SrcData
  .endif                                                ;eax == 0 => stop search
  ret
FindFinalMember endp

; --------------------------------------------------------------------------------------------------
; Method:     PropWnd.CreateLinkInfo
; Purpose:    Record a LINK_INFO in a DataCollection.
; Arguments:  Arg1: Action to execute when the link is invoked (LIA_xxx).
;             Arg2: -> FileName.
;             Arg3: Parameter.
; Return:     eax = Link ID.

Method PropWnd.CreateLinkInfo, uses xsi, dAction:DWORD, pFileName:PSTRING, dParam:DWORD
  SetObject xsi
  MemAlloc sizeof(LINK_INFO)
  .if xax != NULL
    OCall [xsi].LinkInfos::DataCollection.Insert, xax
    m2m [xax].LINK_INFO.dAction, dAction, edx
    m2m [xax].LINK_INFO.dParam, dParam, edx
    .if pFileName == NULL
      m2z CHR ptr [xax].LINK_INFO.FileName
    .else
      invoke StrCCopy, addr [xax].LINK_INFO.FileName, pFileName, MAX_PATH - 1
    .endif
    mov eax, [xsi].LinkInfos.dCount
    dec eax
  .else
    mov eax , -1
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     PropWnd.Done
; Purpose:    Finalizes the PropWnd object and disposes the MDI child window.
; Arguments:  None.
; Return:     Nothing.

Method PropWnd.Done, uses xbx xsi
  SetObject xsi

  ;Finalize some objects
  OCall [xsi].MarkupStream::MemoryStream.Done
  OCall [xsi].InfoPane::TextView.Done
  OCall [xsi].LinkInfos::DataCollection.Done

  ;Main menu update
  mov xbx, $ObjTmpl(Application).pClientWnd
  dec [xbx].$Obj(ClientWnd).dChildCount
  OCall $ObjTmpl(Application)::Application.EnableActions
  .if [xbx].$Obj(ClientWnd).dChildCount == 0            ;No more child windows ?
    mov xax, $ObjTmpl(Application).pClientWnd
    invoke SendMessage, [xax].$Obj(ClientWnd).hWnd, WM_MDISETMENU, \
                        $ObjTmpl(Application).hMenuInit, NULL
    invoke DrawMenuBar, $ObjTmpl(Application).hWnd      ;Redraw the new menu bar
  .endif

  ;Final object cleanup
  invoke StrDispose, [xsi].pName
  ACall xsi.Done
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     PropWnd.Init
; Purpose:    Initalizes the PropWnd object.
; Arguments:  Arg1: -> Owner object (ClientWnd).
;             Arg2: -> Window Class name.
;             Arg2: -> INFORMATION.
; Return:     Nothing.

Method PropWnd.Init, uses xbx xdi xsi, pOwner:$ObjPtr(ClientWnd), pWndClassName:PSTRING, \
                                       pInfo:PINFORMATION
  local dIsMaximized:DWORD, DefTextView:DEF_TEXTVIEW

  SetObject xsi
  ACall xsi.Init, pOwner, NULL                          ;hWnd is set in WndProc
  m2m [xsi].pInfo, pInfo, xax

  ;Create a local copy of the name (used to refresh the window content)
  mov [xsi].pName, $invoke(StrNew, [xax].INFORMATION.pName)

  ;Initialize some objects
  OCall [xsi].MarkupStream::MemoryStream.Init, xsi, 5*1024, 5*1024, -1
  OCall [xsi].LinkInfos::DataCollection.Init, xsi, 20, 20, COL_MAX_CAPACITY

  ;Apply application setup
  mov xdi, [xsi].pOwner                                 ;xdi -> ClientWnd
  m2m [xsi].dShowRedefMtds, $ObjTmpl(Application).dShowRedefMtds, eax
  m2m [xsi].dShowRedefVars, $ObjTmpl(Application).dShowRedefVars, eax

  ;Polymorphic calls
  OCall xsi.Gather
  OCall xsi.CreateMarkupText

  inc [xdi].$Obj(ClientWnd).dChildCount
  invoke SendMessage, [xdi].$Obj(ClientWnd).hWnd, WM_MDIGETACTIVE, 0, addr dIsMaximized
  .if xax != 0 && dIsMaximized == FALSE                 ;xax = MDI Child HWND
    xor ebx, ebx
  .else
    mov ebx, WS_MAXIMIZE
  .endif
  mov xax, pInfo
  invoke CreateMDIWindow, pWndClassName, [xax].INFORMATION.pName, \
                          ebx, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, \
                          [xdi].$Obj(ClientWnd).hWnd, hInstance, xsi

  mov DefTextView.xCtlID, VIEW_CTRL_ID
  mov DefTextView.dStyle, WS_CHILD or WS_VISIBLE
  m2z DefTextView.dExStyle
  m2m DefTextView.pText, [xsi].MarkupStream.pBuffer, xax
  invoke GetClientRect, [xsi].hWnd, addr DefTextView.rect
  OCall [xsi].InfoPane::TextView.Init, xsi, [xsi].hWnd, addr DefTextView

  OCall $ObjTmpl(Application)::Application.EnableActions
  .if eax != 0
    .if [xdi].$Obj(ClientWnd).dChildCount == 1          ;First child window ?
      invoke SendMessage, [xdi].$Obj(ClientWnd).hWnd, WM_MDISETMENU, \
                          $ObjTmpl(Application).hMenuChild, $ObjTmpl(Application).hMenuChildWnd
      invoke DrawMenuBar, $ObjTmpl(Application).hWnd    ;Redraw the new menu bar
    .endif
  .else
    invoke GetLastError
    invoke ErrorMessageBox, $ObjTmpl(Application).hWnd, $OfsCStr("Window creation error"), \
                            LOCALE_USER_DEFAULT, eax
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     PropWnd.OnClose
; Purpose:    Event procedure for WM_CLOSE message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method PropWnd.OnClose, uses xsi, wParam:WPARAM, lParam:LPARAM
  invoke GetActiveWindow
  SetObject xsi
  .if xax == $ObjTmpl(Application).hWnd
    invoke DefMDIChildProc, [xsi].hWnd, WM_CLOSE, wParam, lParam
  .else
    xor eax, eax
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     PropWnd.OnSize
; Purpose:    Event procedure for WM_SIZE message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero.

Method PropWnd.OnSize, uses xsi, wParam:WPARAM, lParam:LPARAM
  local CRect:RECT

  SetObject xsi
  .if wParam != SIZE_MINIMIZED
    invoke GetClientRect, [xsi].hWnd, addr CRect
    .if xax != NULL
      invoke SetWindowPos, [xsi].InfoPane.hWnd, HWND_BOTTOM, \
                           CRect.left, CRect.top, CRect.right, CRect.bottom, SWP_NOZORDER
    .endif
  .endif
  invoke DefMDIChildProc, [xsi].hWnd, WM_SIZE, wParam, lParam
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     PropWnd.ShowFileInfo
; Purpose:    Show file information.
; Arguments:  Arg1: -> Full path FileName.
;             Arg2: Show Link.
;             Arg3: Line Number.
;             Arg4: -> FileTime storage of this file.
;             Arg5: -> Reference SysTime 1.
;             Arg6: -> Reference SysTime 2.
; Return:     Nothing.

Method PropWnd.ShowFileInfo, uses xbx xsi, pFileName:PSTRING, dShowLink:DWORD, dLineNumber:DWORD, \
                                           pFileTime:PFILETIME, \
                                           pFileTime1:PFILETIME, pFileTime2:PFILETIME
  local hFile:HANDLE, cBuffer[100]:CHR, cNumBuffer[20]:CHR
  local LocalSysTime:SYSTEMTIME, SysTimeUTC:SYSTEMTIME

  SetObject xsi
  invoke CreateFile, pFileName, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, \
                     FILE_ATTRIBUTE_ARCHIVE, 0
  .if xax != INVALID_HANDLE_VALUE
    mov hFile, xax
    .if dShowLink != FALSE
      ;Show the link
      OCall [xsi].MarkupStream::MemoryStream.BinWrite, $OfsSze(MTXT_LINK_BEG)
      OCall xsi.CreateLinkInfo, LIA_OPEN_FILE, pFileName, dLineNumber
      invoke dword2dec, addr cNumBuffer, eax
      OCall xsi::PropWnd.WriteString, addr cNumBuffer
      OCall [xsi].MarkupStream::MemoryStream.BinWrite, $OfsSze(MTXT_LINK_END)
      OCall xsi::PropWnd.WriteString, pFileName
      OCall [xsi].MarkupStream::MemoryStream.BinWrite, $OfsSze(MTXT_STYLE_CLOSE)
    .else
      OCall xsi::PropWnd.WriteString, pFileName
    .endif
    OCall [xsi].MarkupStream::MemoryStream.BinWrite, $OfsSze(MTXT_TAB)

    invoke GetFileTime, hFile, NULL, NULL, pFileTime
    invoke CloseHandle, hFile
    invoke FileTimeToSystemTime, pFileTime, addr SysTimeUTC
    invoke SystemTimeToTzSpecificLocalTime, NULL, addr SysTimeUTC, addr LocalSysTime

    invoke wsprintf, addr cBuffer, $OfsCStr("%02hu/%02hu/%02hu %02hu:%02hu:%04hu"), \
                     LocalSysTime.wDay, LocalSysTime.wMonth, LocalSysTime.wYear, \
                     LocalSysTime.wHour, LocalSysTime.wMinute, LocalSysTime.wSecond
    OCall [xsi].MarkupStream::MemoryStream.BinWrite, addr cBuffer, 19*sizeof(CHR)
    OCall [xsi].MarkupStream::MemoryStream.BinWrite, $OfsSze(MTXT_TAB)
    xor ebx, ebx
    .if pFileTime1 != NULL
      invoke CompareFileTime, pFileTime, pFileTime1
      mov ebx, eax
    .endif
    .if pFileTime2 != NULL
      invoke CompareFileTime, pFileTime, pFileTime2
      or ebx, eax
    .endif
    .ifBitSet ebx, BIT31
      OCall [xsi].MarkupStream::MemoryStream.BinWrite, $OfsSze(MTXT_OUTDATED)
    .else
      OCall [xsi].MarkupStream::MemoryStream.BinWrite, $OfsSze(MTXT_CHECK)
    .endif
  .else
    OCall [xsi].MarkupStream::MemoryStream.BinWrite, $OfsSze(MTXT_FILE_NOT_FOUND)
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     PropWnd.WriteString
; Purpose:    Show file information.
; Arguments:  Arg1: -> String.
; Return:     Nothing.

Method PropWnd.WriteString, uses xsi, pString:PSTRING
  SetObject xsi
  invoke StrLength, pString
  if TARGET_STR_TYPE eq STR_TYPE_WIDE
    add eax, eax
  endif
  OCall [xsi].MarkupStream::MemoryStream.BinWrite, pString, eax

MethodEnd


