; ==================================================================================================
; Title:      ADE_ClientWnd.inc
; Author:     G. Friedrich
; Version:    See ADE.asm
; Purpose:    ObjAsm Assembler Development Environment.
; ==================================================================================================


; ==================================================================================================
; ClientWnd implementation
; ==================================================================================================

; --------------------------------------------------------------------------------------------------
; Method:     ClientWnd.Deserialize
; Purpose:    Restore serialized members to its original values.
; Arguments:  Arg1: -> DESER_INFO.
; Return:     Nothing.

Method ClientWnd.Deserialize, uses xbx xsi, pDeserInfo:PDESER_INFO
  SetObject xsi
  ;Deserialization work here
  ACall xsi.Deserialize, pDeserInfo
  ;...

  ;Loop child windows in Z order
  .if [xsi].dChildCount != 0
    invoke GetTopWindow, [xsi].hWnd
    .while xax != 0
      mov xbx, xax
      invoke SendMessage, xbx, WM_GETOBJECTINSTANCE, 0, 0
      .if xax != NULL
        OCall xax::ChildWnd.Deserialize, pDeserInfo
      .endif
      invoke GetWindow, xbx, GW_HWNDPREV
    .endw
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     ClientWnd.Done
; Purpose:    Finalize the ClientWnd object.
; Arguments:  None.
; Return:     Nothing.

Method ClientWnd.Done, uses xsi
  SetObject xsi
  invoke DeleteObject, [xsi].hBackgroundBrush
  ACall xsi.Done
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     ClientWnd.Init
; Purpose:    Initialize the MdiCodeClientWnd object.
; Arguments:  Arg1: -> Owner object.
; Return:     Nothing.

Method ClientWnd.Init, uses xsi, pOwner:POINTER
  local hBmp:HBITMAP

  SetObject xsi
  ACall xsi.Init, pOwner
  mov hBmp, $invoke(LoadBitmap, hInstance, $OfsCStr("BMP_BACKGROUND"))
  mov [xsi].hBackgroundBrush, $invoke(CreatePatternBrush, hBmp)
  invoke DeleteObject, hBmp
  invoke DragAcceptFiles, [xsi].hWnd, TRUE
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     ClientWnd.Load
; Purpose:    Load and initialize the ClientWnd instance from a stream object.
; Arguments:  Arg1: -> Stream object.
;             Arg2: -> DESER_INFO.
; Return:     Nothing.

Method ClientWnd.Load, uses xbx xdi xsi, pStream:$ObjPtr(Stream), pDeserInfo:PDESER_INFO
  SetObject xsi
  mov xbx, pDeserInfo
  ACall xsi.Load, pStream, pDeserInfo                 ;Returns hWnd
  OCall [xbx].DESER_INFO.pDesLUT::DesLUT.Insert, xax, [xsi].hWnd

  mov edi, $32($OCall(pStream::Stream.BinRead32))     ;edi = ChildCount

  ;Reload child MDI windows
  .while edi != 0
    OCall pStream::Stream.Get, pDeserInfo             ;[xsi].dChildCount is incr. with each Get
    dec edi
  .endw
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     ClientWnd.OnDropFiles
; Purpose:    Event procedure for WM_DROPFILES message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero.

Method ClientWnd.OnDropFiles, uses xbx xdi xsi, wParam:WPARAM, lParam:LPARAM
  local pFileName:PSTRINGW, pEditor:$ObjPtr(Editor)

  ANNOTATION use:wParam lParam

  SetObject xsi
  mov xbx, $invoke(DragQueryFileW, wParam, -1, NULL, 0)
  .while xbx > 0
    dec xbx
    invoke DragQueryFileW, wParam, ebx, NULL, 0
    inc eax                                             ;Include ZTC
    mov edi, eax
    mov pFileName, $invoke(StrAllocW, eax)
    invoke DragQueryFileW, wParam, ebx, xax, edi
    OCall [xsi].pOwner::Application.Launch, pFileName
    invoke StrDispose, pFileName
  .endw
  invoke DragFinish, wParam
  xor eax, eax
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     ClientWnd.OnEraseBkgnd
; Purpose:    Event procedure for WM_ERASEBKGND message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Non zero => we do the job.

Method ClientWnd.OnEraseBkgnd,, wParam:WPARAM, lParam:LPARAM
  ANNOTATION use:wParam lParam

  mov eax, 1
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     ClientWnd.OnPaint
; Purpose:    Event procedure for WM_PAINT message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method ClientWnd.OnPaint, uses xsi, wParam:WPARAM, lParam:LPARAM
  local PS:PAINTSTRUCT, Rct:RECT

  ANNOTATION use:wParam lParam

  SetObject xsi
  invoke BeginPaint, [xsi].hWnd, addr PS
  invoke GetClientRect, [xsi].hWnd, addr Rct
  invoke FillRect, PS.hdc, addr Rct, [xsi].hBackgroundBrush
  invoke EndPaint, [xsi].hWnd, addr PS
  invoke CallWindowProc, [xsi].$Obj(ClientWnd).pPrevWndProc, \
                         [xsi].$Obj(ClientWnd).hWnd, \
                         WM_PAINT, wParam, lParam
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     ClientWnd.Store
; Purpose:    Store ClientWnd instance in a stream object.
; Arguments:  Arg1: -> Stream object.
; Return:     Nothing.

Method ClientWnd.Store, uses xbx xsi, pStream:$ObjPtr(Stream)
  SetObject xsi
  ACall xsi.Store, pStream                              ;Store pSelf ... hWnd
  OCall pStream::Stream.BinWrite32, [xsi].dChildCount

  ;Store child windows in Z order from bottom to top

  .if [xsi].dChildCount != 0
    ;Move to the bottom of the window z order
    invoke GetBottomWindow, [xsi].hWnd

    .while xax != 0
      mov xbx, xax
      invoke SendMessage, xbx, WM_GETOBJECTINSTANCE, 0, 0
      .if xax != NULL
        OCall pStream::Stream.Put, xax
      .endif
      invoke GetWindow, xbx, GW_HWNDPREV
    .endw
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     ClientWnd.UpdateEditors
; Purpose:    Update all open Editor instances.
; Arguments:  None.
; Return:     Nothing.

UpdateEditor proc uses xbx xdi xsi hWnd:HWND, hMdiActiveWnd:HWND
  local pDisplay:$ObjPtr(EditorDisplay)
  
  invoke SendMessage, hWnd, WM_GETOBJECTINSTANCE, 0, 0
  .if xax != NULL
    mov xbx, xax
    invoke GetObjectID, xax
    .if eax == ADE_EditorID
      .ColForEach [xbx].$Obj(Editor).EditorDisplays, esi
        mov pDisplay, xax
        lea xdi, [xax].$Obj(EditorDisplay).View
        OCall xdi::EditorView.SetGuiLayout
        mov xcx, pDisplay
        invoke RedrawWindow, [xcx].$Obj(EditorDisplay).hWnd, NULL, 0, RDW_INVALIDATE or RDW_UPDATENOW
        mov xax, hWnd
        .if xax == hMdiActiveWnd
          OCall xdi::EditorView.CaretDestroy
          OCall xdi::EditorView.CaretNew
          OCall xdi::EditorView.CaretSet
          OCall xdi::EditorView.CaretShow
        .endif
      .ColNext
    .endif
  .endif
  mov eax, TRUE                                         ;Continue enumeration
  ret
UpdateEditor endp

Method ClientWnd.UpdateEditors, uses xsi
  SetObject xsi
  invoke SendMessage, [xsi].hWnd, WM_MDIGETACTIVE, 0, 0
  invoke EnumChildWindows, [xsi].hWnd, offset UpdateEditor, xax
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     ClientWnd.WindowProc
; Purpose:    Processing of window messages.
; Arguments:  Arg1: Message identifier.
;             Arg2: First message parameter.
;             Arg3: Second message parameter.
;             Window HANDLE is passed in pSelf.
; Return:     eax = Result of the message processing and depends on the message ID.

Method ClientWnd.WndProc,, uMsg:DWORD, wParam:WPARAM, lParam:LPARAM
;  DbgMessage uMsg,, "ClientWnd"
  GetSubclassingInst MdiClientWnd, pSelf
  OCall xax::MdiClientWnd.Dispatch, pSelf, uMsg, wParam, lParam
MethodEnd
