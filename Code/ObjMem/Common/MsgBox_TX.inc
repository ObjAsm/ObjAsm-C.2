; ==================================================================================================
; Title:      MsgBox_TX.inc
; Author:     G. Friedrich
; Version:    C.1.4
; Purpose:    ObjAsm support of MsgBox dialogs.
;             It displays a modified Messagebox using TextView formatted text.
; Notes:      Version C.1.4, June 2021
;               - Header added to transfer caption to properly identify the MsgBox window.
;             Version C.1.3, February 2021
;               - TextView internal update changes. GetExtent replaced.
;             Version C.1.2, May 2020
;               - First release.
;               - The arguments passed to the function are almost the same es the original API.
;               - If an icon is specified, e.g MB_ICONERROR, a text indentation of 65px is
;                 recommended.
;               - Don't use GWLP_USERDATA. It is used internally by the MessageBox implementation.
; ==================================================================================================


% include &MacPath&WinHelpers.inc
% include &MacPath&ConstDiv.inc
% include &IncPath&Windows\CommCtrl.inc
% include &IncPath&Windows\richedit.inc

LoadObjects Primer, Stream
LoadObjects Collection, DataCollection, SortedCollection, SortedDataCollection, XWCollection
LoadObjects WinPrimer, Window, TextView


MBX_BTN_MAX_COUNT  equ 4      ;Max number of buttons shown on the dialog

MBX_ButtonInfo struc          ;Collected information of each button
  hWnd        HWND  ?
  Rect        RECT  {}
MBX_ButtonInfo ends

MBX_DlgInfo struc
  hHook       HANDLE    ?     ;System hook
  hDlg        HWND      ?     ;Dialog HANDLE
  pCaption    PSTRING   ?     ;Dialog caption string
  pText       PSTRING   ?     ;Main text markup string
  dBandHeight DWORD     ?     ;Drawing help, height of grey band at the bottom of the dialog
  dBtnCount   DWORD     ?     ;Index into MsgBoxBtns
  dFlags      DWORD     ?
  Buttons     MBX_ButtonInfo MBX_BTN_MAX_COUNT DUP({?})       ;Button information
MBX_DlgInfo ends

MBX_CAPTION_HEADER       equ <MsgBoxData@>
MBX_CAPTION_HEADER_CHARS = @SizeStr(%MBX_CAPTION_HEADER)

; --------------------------------------------------------------------------------------------------
; Procedure:  MsgBoxA / MsgBoxW
; Purpose:    Show a customized MessageBox.
; Arguments:  Arg1: Parent HANDLE.
;             Arg2: -> Markup text.
;             Arg3: -> Caption text.
;             Arg4: Flags.
; Return:     eax = Zero if failed, otherwise pressed button ID.
; Note:       Caption, text etc. are transferred via a caption string which contains a header and
;             the address of a MsgBoxInfo structure in text form.

.code
align ALIGN_CODE
ProcName proc hParent:HANDLE, pText:POINTER, pCaption:POINTER, dFlags:DWORD
  local cTransferInfo[MBX_CAPTION_HEADER_CHARS + XWORD2HEX_MAX_CHARS]:CHR, MBX_Info:MBX_DlgInfo

  ;Set system hook
  invoke SetWindowsHookEx, WH_CALLWNDPROC, offset MBX_HookProc, 0, $32($invoke(GetCurrentThreadId))

  ;Prepare information to pass to the MessageBox dialog.
  mov MBX_Info.hHook, xax
  m2m MBX_Info.pText, pText, xcx
  m2m MBX_Info.pCaption, pCaption, xdx
% FillText cTransferInfo, MBX_CAPTION_HEADER
  invoke xword2hex, addr [cTransferInfo + MBX_CAPTION_HEADER_CHARS*sizeof(CHR)], addr MBX_Info

  ;Use the caption to pass the pointer to MBX_DlgInfo in form of a string.
  ;MessageBoxIndirect can be used for more options.
  invoke MessageBox, hParent, NULL, addr cTransferInfo, dFlags
  ret
ProcName endp

; --------------------------------------------------------------------------------------------------
; Procedure:  MB_WndProc
; Purpose:    WndProc for the customized Messagebox.
; Arguments:  Arg1: Dialog HANDLE.
;             Arg2: Message ID.
;             Arg3: wParam.
;             Arg4: lParam.
; Return:     eax = Depends on the message ID.

%CStr cMBX_Prop_&TARGET_SUFFIX, "MBX_DlgInfo&TARGET_SUFFIX"

MBX_TEXTVIEW_CTLID  equ 0FFFFh                          ;Reuse the ID of the static text control

MBXF_JUST_DRAWN     equ BIT00

align ALIGN_CODE
MBX_EnumDlgItems proc private uses xbx xdi hItem:HWND, lParam:LPARAM
  mov xbx, lParam
  .if [xbx].MBX_DlgInfo.dBtnCount < MBX_BTN_MAX_COUNT
    invoke GetMenu, hItem                               ;Get the control ID stored as hMenu
    .if eax <= IDCONTINUE                               ;Last known button ID
      imul eax, [xbx].MBX_DlgInfo.dBtnCount, sizeof(MBX_ButtonInfo)
      lea xdi, [xbx + xax].MBX_DlgInfo.Buttons
      mrm [xdi].MBX_ButtonInfo.hWnd, hItem, xcx
      invoke GetWindowRect, xcx, addr [xdi].MBX_ButtonInfo.Rect

      ;Calculate with, height and client position of each button
      mov ecx, [xdi].MBX_ButtonInfo.Rect.bottom
      sub ecx, [xdi].MBX_ButtonInfo.Rect.top
      mov [xdi].MBX_ButtonInfo.Rect.bottom, ecx

      mov edx, [xdi].MBX_ButtonInfo.Rect.right
      sub edx, [xdi].MBX_ButtonInfo.Rect.left
      mov [xdi].MBX_ButtonInfo.Rect.right, edx
      invoke ScreenToClient, [xbx].MBX_DlgInfo.hDlg, addr [xdi].MBX_ButtonInfo.Rect.left

      add [xbx].MBX_DlgInfo.dBtnCount, 1                ;Move index to next MBX_ButtonInfo
    .endif
    mov eax, TRUE                                       ;Continue enumeration
  .else
    xor eax, eax                                        ;Stop enumeration
  .endif
  ret
MBX_EnumDlgItems endp


align ALIGN_CODE
MBX_WndProc proc private uses xbx xdi xsi hDlg:HWND, uMsg:DWORD, wParam:WPARAM, lParam:LPARAM
  local TVDef:DEF_TEXTVIEW, CRect:RECT, WRect:RECT, WndSize:POINT, CtlOfs:POINT

;  DbgMessage uMsg, "MsgBoxBlgProc.WndProc"
  .if uMsg == WM_INITDIALOG

%   mov xdx, offset cMBX_Prop_&TARGET_SUFFIX
    mov xdi, $invoke(GetProp, hDlg, xdx)
    mov [xdi].MBX_DlgInfo.dFlags, 0

    ;Destroy the original static control were the messagebox text is usually displayed,
    ;we don't need it anymore
    invoke GetDlgItem, hDlg, 0FFFFh                     ;0FFFFh = static control ID
    invoke DestroyWindow, xax

    ;Get button information
    m2m [xdi].MBX_DlgInfo.hDlg, hDlg, xax
    mov [xdi].MBX_DlgInfo.dBtnCount, 0                  ;Start with the first button
    invoke EnumChildWindows, hDlg, offset MBX_EnumDlgItems, xdi

    ;Calculate the height of the grey band at the bottom
    invoke GetClientRect, hDlg, addr CRect              ;Get the original client rect
    mov ecx, CRect.bottom
    sub ecx, [xdi].MBX_DlgInfo.Buttons.Rect.top
    shl ecx, 1
    sub ecx, [xdi].MBX_DlgInfo.Buttons.Rect.bottom
    mov [xdi].MBX_DlgInfo.dBandHeight, ecx

    ;Setup TextView
    mov TVDef.xCtlID, MBX_TEXTVIEW_CTLID
    mov TVDef.dStyle, 0
    mov TVDef.dExStyle, 0
    mov TVDef.sdPosX, 0
    mov TVDef.sdPosY, 0
    mov TVDef.dWidth, 200                               ;Min TextView width
    mov TVDef.dHeight, 100                              ;Min TextView height
    m2m TVDef.pText, [xdi].MBX_DlgInfo.pText, xax

    ;Adjust dialog size according to the TextView size
    mov TVDef.dWidth, $uMax(TVDef.dWidth, CRect.right)
    mov eax, CRect.bottom
    sub eax, [xdi].MBX_DlgInfo.dBandHeight
    mov TVDef.dHeight, $uMax(eax, TVDef.dHeight)

    mov xbx, $New(TextView)
    OCall xbx::TextView.Init, NULL, hDlg, addr TVDef

    ;Set TextView as parent of the static control that holds the icon.
    ;This way it is placed on top of TextView control.
    invoke GetDlgItem, hDlg, 14h                        ;14h = icon control ID
    .if xax != 0
      invoke SetParent, xax, [xbx].$Obj(TextView).hWnd
    .endif

    ;Update the dialog size and position
    invoke GetWindowRect, hDlg, addr WRect
    mov ecx, WRect.right
    sub ecx, WRect.left
    mov eax, [xbx].$Obj(TextView).Extent.x
    mov edx, CRect.right
    sub eax, edx
    add ecx, eax
    mov WndSize.x, ecx
    mov CtlOfs.x, eax
    sar eax, 1
    sub WRect.left, eax

    mov ecx, WRect.bottom
    sub ecx, WRect.top
    mov eax, [xbx].$Obj(TextView).Extent.y
    sub eax, CRect.bottom
    add eax, [xdi].MBX_DlgInfo.dBandHeight
    add ecx, eax
    mov WndSize.y, ecx
    mov CtlOfs.y, eax
    sar eax, 1
    sub WRect.top, eax

    invoke MoveWindow, hDlg, WRect.left, WRect.top, WndSize.x, WndSize.y, FALSE

    ;Update TextView size
    invoke GetClientRect, hDlg, addr CRect              ;Get the updated client rect
    mov ecx, [xdi].MBX_DlgInfo.dBandHeight
    sub CRect.bottom, ecx
    invoke MoveWindow, [xbx].$Obj(TextView).hWnd, 0, 0, CRect.right, CRect.bottom, FALSE

    ;Modify button positions
    xor ebx, ebx
    .while ebx < [xdi].MBX_DlgInfo.dBtnCount
      imul eax, ebx, sizeof(MBX_ButtonInfo)
      lea xsi, [[xdi].MBX_DlgInfo.Buttons + xax]
      mov eax, CtlOfs.x
      mov ecx, CtlOfs.y
      add [xsi].MBX_ButtonInfo.Rect.left, eax
      add [xsi].MBX_ButtonInfo.Rect.top,  ecx
      invoke MoveWindow, [xsi].MBX_ButtonInfo.hWnd, \
                         [xsi].MBX_ButtonInfo.Rect.left, [xsi].MBX_ButtonInfo.Rect.top, \
                         [xsi].MBX_ButtonInfo.Rect.right, [xsi].MBX_ButtonInfo.Rect.bottom, \
                         FALSE
      add ebx, 1
    .endw

  .elseif uMsg == WM_NOTIFY                             ;Forward the message to the parent window
    .if wParam == MBX_TEXTVIEW_CTLID
      invoke GetParent, hDlg
      invoke SendMessage, xax, WM_NOTIFY, wParam, lParam
    .endif

  .elseif uMsg == WM_HELP                               ;Forward the message to the parent window
    invoke GetParent, hDlg
    invoke SendMessage, xax, WM_HELP, wParam, lParam
    invoke DefDlgProc, hDlg, uMsg, wParam, lParam

  .elseif uMsg == WM_PAINT
    ;Draw a grey band at the bottom like is is done in the latest OS versions
    %mov xdx, offset cMBX_Prop_&TARGET_SUFFIX
    mov xdi, $invoke(GetProp, hDlg, xdx)
    .ifBitClr [xdi].MBX_DlgInfo.dFlags, MBXF_JUST_DRAWN
      BitSet [xdi].MBX_DlgInfo.dFlags, MBXF_JUST_DRAWN
      invoke GetClientRect, hDlg, addr CRect
      mov ecx, CRect.bottom
      sub ecx, [xdi].MBX_DlgInfo.dBandHeight
      mov CRect.top, ecx
      invoke GetSysColor, COLOR_BTNFACE
      mov xsi, $invoke(CreateSolidBrush, eax)
      mov xbx, $invoke(GetDC, hDlg)
      invoke FillRect, xbx, addr CRect, xsi
      invoke DeleteObject, xsi
      invoke ReleaseDC, hDlg, xbx
    .endif

  .elseif uMsg == WM_ERASEBKGND
    ret

  .elseif uMsg == WM_DESTROY
    ;Set the parent of the icon control to the original hDlg
    mov xbx, $invoke(GetDlgItem, hDlg, MBX_TEXTVIEW_CTLID)
    invoke GetDlgItem, xbx, 14h                         ;14h = icon control ID
    .if xax != 0
      invoke SetParent, xax, hDlg                       ;Restore original parent
    .endif

    ;Destroy the TextView control
    invoke SendMessage, xbx, WM_GETOBJECTINSTANCE, 0, 0
    .if xax != NULL
      Destroy xax                                       ;Destroy TextView object
    .endif

  .elseif uMsg == WM_NCDESTROY                          ;Last message recieved
    invoke GetDlgItem, hDlg, MBX_TEXTVIEW_CTLID
%   invoke RemoveProp, hDlg, offset cMBX_Prop_&TARGET_SUFFIX

  .endif
  invoke DefDlgProc, hDlg, uMsg, wParam, lParam

  ret
MBX_WndProc endp

; --------------------------------------------------------------------------------------------------
; Procedure:  MB_HookProc
; Purpose:    Procedure used by the hook set by MsgBox.
; Arguments:  Arg1: Hook code.
;             Arg2: Nonzero if the msg was sent by the current thread, otherwise zero.
;             Arg3: -> CWPSTRUCT.
; Return:     eax = Zero if handled.

align ALIGN_CODE
MBX_HookProc proc private uses xbx xdi dCode:DWORD, wParam:WPARAM, lParam:LPARAM
  local cTransferInfo[MBX_CAPTION_HEADER_CHARS + 2*sizeof(POINTER) + 1]:CHR

  ANNOTATION use:wParam

  .if dCode == HC_ACTION                               ;Ignore the rest
    mov xbx, lParam
    ;The first recieved WM_NCCALCSIZE corresponds to the dialog window.
    ;It is the first dialog message where the caption is set
    .if [xbx].CWPSTRUCT.message == WM_NCCALCSIZE
      invoke GetWindowText, [xbx].CWPSTRUCT.hwnd, addr cTransferInfo, lengthof(cTransferInfo)
%     .if $DoesTextMatch?(cTransferInfo, MBX_CAPTION_HEADER)
        mov xdi, $invoke(hex2xword, addr [cTransferInfo + MBX_CAPTION_HEADER_CHARS*sizeof(CHR)])
        ;Save a pointer to MBX_DlgInfo as a window property
%       invoke SetProp, [xbx].CWPSTRUCT.hwnd, offset cMBX_Prop_&TARGET_SUFFIX, xdi
        ;Release the hook
        invoke UnhookWindowsHookEx, [xdi].MBX_DlgInfo.hHook
        ;Set correct caption
        invoke SetWindowText, [xbx].CWPSTRUCT.hwnd, [xdi].MBX_DlgInfo.pCaption
        ;Set the new WndProc
        invoke SetWindowLongPtr, [xbx].CWPSTRUCT.hwnd, GWLP_WNDPROC, offset MBX_WndProc
      .endif
    .endif
  .endif
  mov eax, 1
  ret
MBX_HookProc endp
