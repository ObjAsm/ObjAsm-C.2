; ==================================================================================================
; Title:      DebugCenter_DlgFindText.inc
; Author:     G. Friedrich
; Version:    See DebugCenter.asm
; Purpose:    ObjAsm support of Find Text dialog objects.
; ==================================================================================================

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Object:     DialogFindText
; Purpose:    This object is a modeless dialog created from a template. It implements a text search
;             dialog.
; Notes:      These objects are destroyed by the OS when a WM_DESTROY is received.
;             They should NOT be destroyed directly by the user!

Object DialogFindText, DialogFindTextID, DialogModelessIndirect
  RedefineMethod    CtlsGet
  RedefineMethod    CtlsSet
  RedefineMethod    Done
  RedefineMethod    Init,           POINTER, HWND, $ObjPtr(Stream)  ;-> Owner, -> Parent, -> Stream
  RedefineMethod    OnCommand,      WPARAM, LPARAM
  RedefineMethod    OnInitDialog,   WPARAM, LPARAM

  DefineVariable    pStream,        $ObjPtr(Stream),    NULL
ObjectEnd


; ==================================================================================================

if IMPLEMENT

IDC_FTXT_FIND             equ   IDOK
IDC_FTXT_COMBO            equ   201
IDC_FTXT_MATCHCASECHECK   equ   202
IDC_FTXT_WHOLEWORDCHECK   equ   203
IDC_FTXT_FINDDOWNRADIO    equ   204
IDC_FTXT_FINDUPRADIO      equ   205
IDC_STATIC                equ   -1

FTXT_STYLE  equ   WS_CHILD or DS_MODALFRAME or DS_3DLOOK or DS_CENTER or DS_CENTERMOUSE or \
                  DS_SETFOREGROUND or DS_NOFAILCREATE or WS_CAPTION or WS_SYSMENU or WS_POPUP or \
                  DS_SETFONT or WS_VISIBLE

.const
CStr szNotification, "Notification"

DIALOGEX DIALOGFINDTEXT, 0, 0, 200, 75, 0, 10, \
              FTXT_STYLE, 0, \
              0, , " Find Text", "Segoe UI", 9, 700, FALSE, ANSI_CHARSET

DEFPUSHBUTTON "&Find", IDC_FTXT_FIND, 140,51,52,15
PUSHBUTTON    "&Close", IDCANCEL, 140,32,52,15
LTEXT         "&Text:", IDC_STATIC, 9,10,15,8
COMBOBOX      ,IDC_FTXT_COMBO, 32,7,160,14, \
              CBS_DROPDOWN or WS_VSCROLL or WS_TABSTOP or CBS_HASSTRINGS
GROUPBOX      "Options", IDC_STATIC, 8,25,65,40
CONTROL       "&Match Case", IDC_FTXT_MATCHCASECHECK, "Button", BS_AUTOCHECKBOX or WS_TABSTOP, \
              15,37,52,11
CONTROL       "&Whole Word", IDC_FTXT_WHOLEWORDCHECK, "Button", BS_AUTOCHECKBOX or WS_TABSTOP, \
              15,49,52,11
GROUPBOX      "Direction",IDC_STATIC,82,25,45,40
CONTROL       "&Up",   IDC_FTXT_FINDUPRADIO,   "Button", BS_AUTORADIOBUTTON, 88,37,36,11
CONTROL       "&Down", IDC_FTXT_FINDDOWNRADIO, "Button", BS_AUTORADIOBUTTON, 88,49,36,11


.code
; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     DialogFindText.CtlsGet
; Purpose:    Read the controls of the FindText dialog.
; Arguments:  None.
; Return:     Nothing.

Method DialogFindText.CtlsGet, uses xbx xdi xsi
  local dValue:DWORD, pBuffer:POINTER

  SetObject xsi
  .if [xsi].pStream != NULL
    mov dValue, $32($invoke(IsDlgButtonChecked, [xsi].hWnd, IDC_FTXT_MATCHCASECHECK))
    OCall [xsi].pStream::Stream.BinWrite, addr dValue, 4
    mov dValue, $32($invoke(IsDlgButtonChecked, [xsi].hWnd, IDC_FTXT_WHOLEWORDCHECK))
    OCall [xsi].pStream::Stream.BinWrite, addr dValue, 4

    .if $invoke(IsDlgButtonChecked, [xsi].hWnd, IDC_FTXT_FINDDOWNRADIO) == BST_CHECKED
      mov edx, IDC_FTXT_FINDDOWNRADIO
    .else
      mov edx, IDC_FTXT_FINDUPRADIO
    .endif
    OCall [xsi].pStream::Stream.BinWrite32, edx

    mov xbx, $invoke(GetDlgItem, [xsi].hWnd, IDC_FTXT_COMBO)
    mov dValue, $32($invoke(SendMessage, xbx, CB_GETCOUNT, 0, eax))
    OCall [xsi].pStream::Stream.BinWrite32, dValue
    xor edi, edi
    .while edi < dValue
      invoke SendMessage, xbx, CB_GETLBTEXTLEN, xdi, 0
      add eax, sizeof(CHR)                              ;Add room for the ZTC
      mov pBuffer, $MemAlloc(eax)
      invoke SendMessage, xbx, CB_GETLBTEXT, edi, pBuffer
      OCall [xsi].pStream::Stream.StrWrite, pBuffer
      MemFree pBuffer
      inc edi
    .endw
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     DialogFindText.CtlsSet
; Purpose:    Setup the controls of the FindText dialog.
; Arguments:  None.
; Return:     Nothing.

Method DialogFindText.CtlsSet, uses xbx xdi xsi
  local dValue:DWORD, dSelBeg:DWORD, dSelEnd:DWORD

  SetObject xsi
  mov xbx, $invoke(GetDlgItem, [xsi].hWnd, IDC_FTXT_COMBO)
  .if [xsi].pStream == NULL
    invoke CheckDlgButton, [xsi].hWnd, IDC_FTXT_MATCHCASECHECK, BST_UNCHECKED
    invoke CheckDlgButton, [xsi].hWnd, IDC_FTXT_WHOLEWORDCHECK, BST_UNCHECKED

    invoke CheckRadioButton, [xsi].hWnd, IDC_FTXT_FINDDOWNRADIO, IDC_FTXT_FINDUPRADIO, \
                                         IDC_FTXT_FINDDOWNRADIO
  .else
    OCall [xsi].pStream::Stream.BinRead, addr dValue, 4
    invoke CheckDlgButton, [xsi].hWnd, IDC_FTXT_MATCHCASECHECK, dValue
    OCall [xsi].pStream::Stream.BinRead, addr dValue, 4
    invoke CheckDlgButton, [xsi].hWnd, IDC_FTXT_WHOLEWORDCHECK, dValue

    OCall [xsi].pStream::Stream.BinRead, addr dValue, 4
    invoke CheckRadioButton, [xsi].hWnd, IDC_FTXT_FINDDOWNRADIO, IDC_FTXT_FINDUPRADIO, dValue

    OCall [xsi].pStream::Stream.BinRead, addr dValue, 4
    .while dValue > 0
      OCall [xsi].pStream::Stream.StrRead
      invoke SendMessage, xbx, CB_ADDSTRING, 0, eax
      dec dValue
    .endw
  .endif

  ;Add current selection
  invoke SendMessage, [xsi].hParent, EM_GETSEL, addr dSelBeg, addr dSelEnd
  mov eax, dSelEnd
  sub eax, dSelBeg
  .if eax == 0
    invoke SendMessage, xbx, CB_SETCURSEL, 0, -1
  .else
    inc eax                                             ;Add room for the zero terminator
    mov xdi, $MemAlloc(eax)
    invoke SendMessage, [xsi].hParent, EM_GETSELTEXT, 0, xdi
    invoke SendMessage, xbx, CB_ADDSTRING, 0, xdi
    invoke SendMessage, xbx, CB_SETCURSEL, 0, eax
    MemFree xdi
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     DialogFindText.Done
; Purpose:    Finalize the DialogFindText dialog object.
; Arguments:  None.
; Return:     Nothing.

Method DialogFindText.Done, uses xsi
;  DbgText "DialogFindText.Done"
  SetObject xsi
  OCall xsi.CtlsGet
  invoke SetFocus, [xsi].hParent
  ACall xsi.Done
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     DialogFindText.Init
; Purpose:    Initialize the DialogFindText dialog object.
; Arguments:  Arg1: -> Owner object.
;             Arg2: Parent window HANDLE.
;             Arg3: -> Stream object.
; Return:     Nothing.

Method DialogFindText.Init,, pOwner:POINTER, hParent:HWND, pStream:$ObjPtr(Stream)
;  DbgText "DialogFindText.Init"
  SetObject xcx
  m2m [xcx].pStream, pStream, xax
  mov xdx, pOwner
  lea xax, [xdx].$Obj(WinApp).hActiveMlsDlg
  ACall Init, xdx, hParent, offset DIALOGFINDTEXT, xax
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     DialogFindText.OnCommand
; Purpose:    Event procedure for WM_COMMAND message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     Nothing.

Method DialogFindText.OnCommand, uses xbx xdi xsi, wParam:WPARAM, lParam:LPARAM
  local FTXTX:FINDTEXTEX, dSelBeg:DWORD, dSelEnd:DWORD, dFlags:DWORD, pBuffer:POINTER, dSize:dWORD
  local dComboIndex:DWORD, cMsg[1024]:CHR

  SetObject xsi
  LoWord(wParam)
  .if ax == IDC_FTXT_FIND
    mov xbx, $invoke(GetDlgItem, [xsi].hWnd, IDC_FTXT_COMBO)
    invoke SendMessage, [xsi].hParent, EM_GETSEL, addr dSelBeg, addr dSelEnd
    .if $invoke(IsDlgButtonChecked, [xsi].hWnd, IDC_FTXT_FINDDOWNRADIO) == BST_CHECKED
      m2m FTXTX.chrg.cpMin, dSelEnd, edx
      mov FTXTX.chrg.cpMax, -1
      mov dFlags, FR_DOWN
    .else
      m2m FTXTX.chrg.cpMin, dSelBeg, edx
      m2z FTXTX.chrg.cpMax
      m2z dFlags
    .endif

    .if $invoke(IsDlgButtonChecked, [xsi].hWnd, IDC_FTXT_MATCHCASECHECK) == BST_CHECKED
      or dFlags, FR_MATCHCASE
    .endif
    .if $invoke(IsDlgButtonChecked, [xsi].hWnd, IDC_FTXT_WHOLEWORDCHECK) == BST_CHECKED
      or dFlags, FR_WHOLEWORD
    .endif

    invoke SendMessage, xbx, CB_GETCURSEL, 0, 0
    .if xax == -1
      invoke SendMessage, xbx, WM_GETTEXTLENGTH, 0, 0
      .if xax == 0
        mov edx, $ObjTmpl(DebugCenter).dLanguage
        add edx, 127
        invoke LoadString, hInstance, edx, addr cMsg, lengthof cMsg - 1
        invoke MessageBox, [xsi].hWnd, addr cMsg, offset szNotification, MB_OK or MB_ICONEXCLAMATION
        ExitMethod
      .endif
      lea xax, [sizeof(CHR)*xax + sizeof(CHR)]          ;Add room for the ZTC
      mov dSize, eax
      mov xdi, $MemAlloc(dSize)
      invoke SendMessage, xbx, WM_GETTEXT, dSize, xax
      invoke SendMessage, xbx, CB_FINDSTRINGEXACT, -1, xdi
      .if eax == CB_ERR
        invoke SendMessage, xbx, CB_ADDSTRING, 0, xdi
      .endif
      mov dComboIndex, eax
      MemFree xdi
      invoke SendMessage, xbx, CB_SETCURSEL, dComboIndex, 0
    .else
      mov dComboIndex, eax
    .endif

    invoke SendMessage, xbx, CB_GETLBTEXTLEN, dComboIndex, 0
    lea xax, [sizeof(CHR)*xax + sizeof(CHR)]            ;Add room for the ZTC
    mov dSize, eax
    mov pBuffer, $MemAlloc(dSize)
    mov FTXTX.lpstrText, xax
    invoke SendMessage, xbx, CB_GETLBTEXT, dComboIndex, xax
    invoke SendMessage, [xsi].hParent, EM_FINDTEXTEX, dFlags, addr FTXTX
    .if eax == -1
      mov edx, $ObjTmpl(DebugCenter).dLanguage
      add edx, 128
      invoke LoadString, hInstance, edx, addr cMsg, lengthof cMsg - 1
      invoke MessageBox, [xsi].hWnd, addr cMsg, offset szNotification, MB_OK or MB_ICONEXCLAMATION
    .else
      invoke SendMessage, [xsi].hParent, EM_SETSEL, FTXTX.chrgText.cpMin, FTXTX.chrgText.cpMax
      invoke SetFocus, [xsi].hParent
    .endif
    MemFree pBuffer

  .elseif ax == IDCANCEL
    OCall xsi.DestroyDialog, wParam
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     DialogFindText.OnInitDialog
; Purpose:    Event procedure for WM_INITDIALOG message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero.

Method DialogFindText.OnInitDialog, uses xsi, wParam:WPARAM, lParam:LPARAM
  SetObject xsi

  .if ([xsi].StartPos.x != -1) || ([xsi].StartPos.y != -1)
    ;Check if the dialog will be fully visible
    invoke MoveWindowVisible, [xsi].hWnd, [xsi].StartPos.x, [xsi].StartPos.y
  .endif

  invoke WndFadeIn, [xsi].hWnd, 0, 255, 15, 20

  invoke SetFocus, $invoke(GetDlgItem, [xsi].hWnd, IDC_FTXT_COMBO)
  OCall xsi.CtlsSet

  invoke SetForegroundWindow, [xsi].hWnd
  xor eax, eax                                          ;Return zero
MethodEnd

endif
