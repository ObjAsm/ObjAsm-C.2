; ==================================================================================================
; Title:      WinPrimer.inc
; Author:     G. Friedrich
; Version:    C.1.2
; Purpose:    ObjAsm support of WinPrimer objects.
; Notes:      Version C.1.0, October 2017
;               - First release.
;             Version C.1.1, February 2021
;               - Done method added. Call DestroyWindow at life end of descendents.
;             Version C.1.2
;               - WM_GETOBJECTINSTANCE changed to BFFFh to avoid conflicts with OS control messages.
; ==================================================================================================


WM_GETOBJECTINSTANCE  equ   0BFFFh                       ;Last possible WM_APP message

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Object:     WinPrimer
; Purpose:    Implement a base object for windows user interface descendant objects.

Object WinPrimer, WinPrimerID, Streamable
  RedefineMethod    Done
  RedefineMethod    Init,         POINTER, HWND         ;-> Owner, Window HANDLE
  RedefineMethod    Load,         $ObjPtr(Stream), PDESER_INFO
  RedefineMethod    Store,        $ObjPtr(Stream)

  VirtualEvent      OnGetObjectInstance,  WM_GETOBJECTINSTANCE

  ;Messages forwarded to child windows
  VirtualEvent      OnPaletteIsChanging,  WM_PALETTEISCHANGING
  VirtualEvent      OnPaletteChanged,     WM_PALETTECHANGED
  VirtualEvent      OnSettingChange,      WM_SETTINGCHANGE
  VirtualEvent      OnSysColorChange,     WM_SYSCOLORCHANGE

  DefineVariable    hWnd,         HWND,       0
ObjectEnd


; ==================================================================================================

if IMPLEMENT

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     WinPrimer.Done
; Purpose:    Destroy the window.
; Arguments:  None
; Return:     Nothing.

Method WinPrimer.Done, uses xsi
  SetObject xsi
;  .if [xsi].hWnd != 0
;    invoke DestroyWindow, [xsi].hWnd
;    mov [xsi].hWnd, 0
;  .endif
  ACall xsi.Done
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     WinPrimer.Init
; Purpose:    Initialize the WinPrimer object.
; Arguments:  Arg1: -> Owner object.
;             Arg2: Window HANDLE.
; Return:     Nothing.

Method WinPrimer.Init,, pOwner:POINTER, hWnd:HWND
  SetObject xcx
  m2m [xcx].hWnd, hWnd, xax
  ACall xcx.Init, pOwner
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     WinPrimer.Load
; Purpose:    Load and initialize the WinPrimer instance from a stream object. Descendant objects
;             should redefine this method and load new members.
; Arguments:  Arg1: -> Stream object.
;             Arg2: -> DesLUT object.
; Return:     xax = Previous hWnd value.

Method WinPrimer.Load, uses xsi, pStream:$ObjPtr(Stream), pDeserInfo:PDESER_INFO
  SetObject xsi
  ACall xsi.Load, pStream, pDeserInfo
  OCall pStream::Stream.BinReadX
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:    WinPrimer.OnGetObjectInstance
; Purpose:   Event procedure for WM_GETINSATNCE message. Returns the object instance if the
;            hWnd is known, calling "SendMessage hWnd, WM_GETOBJECTINSTANCE, 0, 0".
; Arguments: Arg1: First message parameter.
;            Arg2: Second message parameter.
; Return:    xax -> Object address.

Method WinPrimer.OnGetObjectInstance,, wParam:WPARAM, lParam:LPARAM
  mov xax, pSelf
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     WinPrimer.OnPaletteChanged
; Purpose:    Event handler for WM_PALETTECHANGED message.
;             This message is sent by the OS to all top-level and overlapped windows after the
;             window with the keyboard focus realizes its logical palette.
;             This message enables windows that do not have the keyboard focus to realize their
;             logical palettes and update their client areas (See also WM_QUERYNEWPALETTE).
;             Descendants of WinPrimer forward this message to their child windows.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     Nothing.
; Note:       To avoid creating an infinite loop, a window that receives this message must not
;             realize its palette, unless it determines that wParam does not contain its own window
;             HANDLE.

Method WinPrimer.OnPaletteChanged,, wParam:WPARAM, lParam:LPARAM
;  SetObject xcx
;  invoke SendChildrenMessage, [xcx].hWnd, WM_PALETTECHANGED, wParam, lParam
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     WinPrimer.OnPaletteIsChanging
; Purpose:    Event handler for WM_PALETTEISCHANGING message.
;             The WM_PALETTEISCHANGING message informs applications that an application is going to
;             realize its logical palette. The application changing its palette does not wait for
;             acknowledgment of this message before changing the palette and sending the
;             WM_PALETTECHANGED message. As a result, the palette may already be changed by the time
;             an application receives this message.
;             If the application either ignores or fails to process this message and a second
;             application realizes its palette while the first is using palette indexes, there is a
;             strong possibility that the user will see unexpected colors during subsequent drawing
;             operations.
;             Descendants of WinPrimer forward this message to their child windows.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Always zero (handled).
; Note:       To avoid creating an infinite loop, a window that receives this message must not
;             realize its palette, unless it determines that wParam does not contain its own window
;             HANDLE.

Method WinPrimer.OnPaletteIsChanging,, wParam:WPARAM, lParam:LPARAM
  SetObject xcx
  invoke SendChildrenMessage, [xcx].hWnd, WM_PALETTEISCHANGING, wParam, lParam
  xor eax, eax
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     WinPrimer.OnSettingChange
; Purpose:    Event handler for WM_SETTINGCHANGE message (same as WM_WININICHANGE).
;             This message is sent to all top-level windows when the SystemParametersInfo function
;             changes a system-wide setting or when policy settings have changed.
;             Descendants of WinPrimer forward this message to their child windows.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Always zero (handled).

Method WinPrimer.OnSettingChange,, wParam:WPARAM, lParam:LPARAM
  SetObject xcx
  invoke SendChildrenMessage, [xcx].hWnd, WM_SETTINGCHANGE, wParam, lParam
  xor eax, eax
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     WinPrimer.OnSysColorChange
; Purpose:    Event handler for WM_SYSCOLORCHANGE message.
;             This message is sent to all top-level windows when a change is made to a system color
;             setting. Descendants of WinPrimer forward this message to their child windows.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     Nothing.
; Note:       If the application has brushes using the existing system colors, it should delete
;             those brushes and recreate them using the new system colors.

Method WinPrimer.OnSysColorChange,, wParam:WPARAM, lParam:LPARAM
  SetObject xcx
  invoke SendChildrenMessage, [xcx].hWnd, WM_SYSCOLORCHANGE, wParam, lParam
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     WinPrimer.Store
; Purpose:    Store the WinPrimer instance in a stream object. Descendant objects should redefine
;             this method and store new members.
; Arguments:  Arg1: -> Stream object.
; Return:     Nothing.

Method WinPrimer.Store, uses xsi, pStream:$ObjPtr(Stream)
  SetObject xsi
  ACall xsi.Store, pStream
  OCall pStream::Stream.BinWriteX, [xsi].hWnd
MethodEnd

endif
