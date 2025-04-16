; ==================================================================================================
; Title:      Statusbar.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm support of Statusbar objects based on common controls Version 5.81.
; Notes:      Version C.1.0, October 2017
;               - First release.
;               - To clear a part, use SetPartText with NULL as string argument.
; ==================================================================================================


DEF_STATUSBAR struc
  xCtlID      XWORD     ?   ;Control ID
  dStyle      DWORD     ?   ;Style
  dExStyle    DWORD     ?   ;Extended style
  dCount      DWORD     ?   ;Part count
DEF_STATUSBAR ends
PDEF_STATUSBAR typedef ptr DEF_STATUSBAR

DEF_STATUSBAR_PART struc
  dMaxWidth   DWORD     ?   ;Maximal width of the part in pixel
  dMinWidth   DWORD     ?   ;-2 => dissapears; +2 => minimal width
  dPriority   DWORD     ?   ;Shrink/Expansion order (0 is the first that shrinks)
  dStyle      DWORD     ?   ;SBT_SUNKEN, SBT_NOBORDERS, SBT_POPOUT, SBT_OWNERDRAW
  pTipText    PSTRING   ?   ;-> Tooltip string
DEF_STATUSBAR_PART ends
PDEF_STATUSBAR_PART typedef ptr DEF_STATUSBAR_PART

SBT_SUNKEN      equ    0    ;Default

SB_SETICON      equ    WM_USER + 15
SB_GRIPWIDTH    equ    11h
SBARS_TOOLTIPS  equ    800h
LR_LOADREALSIZE equ    80h

; --------------------------------------------------------------------------------------------------
; Object:     Statusbar
; Purpose:    Implement a thin wrapper around the msctls_statusbar32 GDI control.

Object Statusbar, StatusbarID, WinControl                       ;Class "msctls_statusbar32"
  RedefineMethod    Done
  VirtualMethod     GetPartParentRect,  DWORD, PRECT
  VirtualMethod     GetPartRect,        DWORD, PRECT
  RedefineMethod    Init,               POINTER, HWND, PDEF_STATUSBAR
  VirtualMethod     SetPartText,        DWORD, PSTRING, DWORD
  VirtualMethod     SetPartIcon,        DWORD, HICON
  VirtualMethod     SetPartWidths
  RedefineMethod    WndProc,            DWORD, WPARAM, LPARAM

  DefineVariable    pDefStruc,          PDEF_STATUSBAR, NULL
  DefineVariable    pDataArray,         POINTER,        NULL

  VirtualEvent      OnSize,         WM_SIZE
ObjectEnd


; ==================================================================================================

if IMPLEMENT

; --------------------------------------------------------------------------------------------------
; Method:     Statusbar.Done
; Purpose:    Finalize the Statusbar object, freeing allocated memory.
; Arguments:  None.
; Return:     Nothing.

Method Statusbar.Done, uses xsi
  SetObject xsi
  MemFree [xsi].pDataArray
  Unsubclass Statusbar                                  ;Uses xsi
  ACall xsi.Done
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Statusbar.GetPartParentRect
; Purpose:    Retrieve the relative bounding rectangle of a Part to the Statusbar control. It
;             supports a maximum of 256 parts.
; Arguments:  Arg1: Zero-based part index.
;             Arg2: -> RECT structure.
; Return:     Nothing.

Method Statusbar.GetPartParentRect, uses xsi, dID:DWORD, pRect:PRECT
  local SbRect:RECT

  SetObject xsi
  invoke GetWindowRect, [xsi].hWnd, addr SbRect
  invoke GetParent, [xsi].hWnd
  lea xdx, SbRect
  invoke ScreenToClient, xax, xdx
  invoke SendMessage, [xsi].hWnd, SB_GETRECT, dID, pRect
  mov xcx, pRect
  mov eax, SbRect.left
  add [xcx].RECT.left, eax
  add [xcx].RECT.right, eax
  mov eax, SbRect.top
  add [xcx].RECT.top, eax
  add [xcx].RECT.bottom, eax
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Statusbar.GetPartRect
; Purpose:    Retrieve the bounding rectangle of a Part in a Statusbar control.
; Arguments:  Arg1: Zero-based part index.
;             Arg2: -> RECT structure.
; Return:     Nothing.

Method Statusbar.GetPartRect,, dID:DWORD, pRect:PRECT
  SetObject xcx
  invoke SendMessage, [xcx].hWnd, SB_GETRECT, dID, pRect
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Statusbar.Init
; Purpose:    Initialize the Statusbar object.
; Arguments:  Arg1: -> Owner object.
;             Arg2: Parent window HANDLE.
;             Arg3: -> DEF_STATUSBAR initialization structure.
; Return:     Nothing.

Method Statusbar.Init, uses xbx xdi xsi, pOwner:POINTER, hParent:HWND, pDefStruc:PDEF_STATUSBAR
  local dPartCount:DWORD

  SetObject xsi
  mrm [xsi].pDefStruc, pDefStruc, xbx

  assume xbx:PDEF_STATUSBAR
  invoke CreateWindowEx, [xbx].dExStyle, $OfsCStr("msctls_statusbar32"), NULL, \
                         [xbx].dStyle, 0, 0, 0, 0, hParent, [xbx].xCtlID, hInstance, 0
  ACall xsi.Init, pOwner, xax
  Subclass Statusbar                                    ;Uses xsi

  mrm dPartCount, [xbx].dCount, eax                     ;Part count
  shl eax, $Log2(sizeof(DWORD))                         ;Storage for DWORDs
  mov [xsi].pDataArray, $MemAlloc(eax)                  ;Allocate memory for part widths calculation
  assume xbx:NOTHING

  OCall xsi.SetPartWidths

  ;Set the style of all parts.
  add xbx, sizeof(DEF_STATUSBAR)
  xor edi, edi
  .while edi != dPartCount
    OCall xsi.SetPartText, edi, NULL, [xbx].DEF_STATUSBAR_PART.dStyle
    add xbx, sizeof(DEF_STATUSBAR_PART)
    inc edi
  .endw
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Statusbar.SetPartText
; Purpose:    Set the text of a part of the Statusbar.
; Arguments:  Arg1: Zero-based part index.
;             Arg2: -> String. The text for each part is limited to 127 characters.
;             Arg3: Part style:
;                   SBT_SUNKEN, SBT_NOBORDERS, SBT_POPOUT, SBT_RTLREADING, SBT_OWNERDRAW.
; Return:     Nothing.

Method Statusbar.SetPartText, uses xbx xsi, dID:DWORD, pText:PSTRING, dStyle:DWORD
  local Rct:RECT

  SetObject xsi
  invoke SendMessage, [xsi].hWnd, SB_GETTEXTLENGTH, dID, 0  ;Return = Length + Style * 2^16
  shr eax, 16                                           ;eax = current drawing style
  mov ebx, eax
  mov eax, dStyle
  shl eax, 8
  or eax, dID
  invoke SendMessage, [xsi].hWnd, SB_SETTEXT, eax, pText
  .if ebx != dStyle                           ;To reduce flicker, redraw only if style has changed
    invoke SendMessage, [xsi].hWnd, SB_GETRECT, dID, addr Rct
    invoke InvalidateRect, [xsi].hWnd, addr Rct, TRUE
    invoke UpdateWindow, [xsi].hWnd
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Statusbar.SetPartIcon
; Purpose:    Set the icon of a part of the statusbar.
; Arguments:  Arg1: Zero-based part index.
;             Arg2: Icon handle. Use "LoadImage" to get the icon in the correct size.
; Return:     Nothing.

Method Statusbar.SetPartIcon,, dID:DWORD, hIcon:HICON
  SetObject xcx
  invoke SendMessage, [xcx].hWnd, SB_SETICON, dID, hIcon
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Statusbar.SetPartWidths
; Purpose:    Calculate the widths of all parts according to the definition structure and the total
;             statusbar width.
; Arguments:  None.
; Return:     Nothing.

Method Statusbar.SetPartWidths, uses xbx xdi xsi

  SB_WIDTH struc
    dHorzBorder   DWORD   ?
    dVertBorder   DWORD   ?
    dVertDivider  DWORD   ?
  SB_WIDTH ends

  local SBW:SB_WIDTH, Rct:RECT, WP:WINDOWPLACEMENT, pPartData:PDEF_STATUSBAR_PART
  local dPartCount:DWORD, dAvailWidth:DWORD

  SetObject xsi

  invoke GetClientRect, [xsi].hWnd, addr Rct
  mov ebx, Rct.right                                    ;Skip if window width = 0
  .if ebx != 0

    ;Calculate dAvailWidth = effective available width incl. vertical dividers
    invoke SendMessage, [xsi].hWnd, SB_GETBORDERS, 0, addr SBW
    add eax, eax
    sub ebx, eax                                        ;Subrtract 2x borders
    invoke GetWindowLongPtr, [xsi].hWnd, GWL_STYLE
    .if eax || SBARS_SIZEGRIP
      invoke GetParent, [xsi].hWnd
      mov WP.length_, sizeof(WP)
      lea xdx, WP
      invoke GetWindowPlacement, xax, xdx               ;On maximized main windows
      .if WP.showCmd != SW_MAXIMIZE                     ;  the GripSize is not shown
        sub ebx, SB_GRIPWIDTH                           ;ebx = Grip width
      .endif
    .endif
    mov dAvailWidth, ebx

    mov xbx, [xsi].pDataArray
    mov xdi, [xsi].pDefStruc
    mrm dPartCount, [xdi].DEF_STATUSBAR.dCount, ecx
    add xdi, sizeof(DEF_STATUSBAR)                      ;Skip DEF_STATUSBAR and go to
    mov pPartData, xdi                                  ;  the 1st DEF_STATUSBAR_PART

    ;Fill CurPartWidth structure with dMaxWidth
    test ecx, ecx
    .while !ZERO?
      m2m [xbx], [xdi].DEF_STATUSBAR_PART.dMaxWidth, eax
      add xdi, sizeof(DEF_STATUSBAR_PART)
      add xbx, sizeof(DWORD)
      dec ecx
    .endw

    xor ebx, ebx                                        ;ebx = Priority
    .while ebx != dPartCount
      mov xcx, pPartData
      xor eax, eax
      .while eax != dPartCount                          ;Find part with priority = ebx
        cmp ebx, [xcx].DEF_STATUSBAR_PART.dPriority
        jz @F                                           ;eax = found part index
        add xcx, sizeof(DEF_STATUSBAR_PART)
        inc eax
      .endw
      jmp @@EOM                                         ;Something went wrong with the
    @@:                                                 ;  definitions => exit
      mov xdx, [xsi].pDataArray
      lea xdi, [xdx + sizeof(DWORD)*xax]
      m2m [xdi], [xcx].DEF_STATUSBAR_PART.dMinWidth, eax

      ;Add all widths & Dividers = eax
      mov ecx, dPartCount
      mov xdx, [xsi].pDataArray                         ;xdx -> current part widths
      xor eax, eax
      .if ecx != 0
        .repeat
          add eax, [xdx]                                ;Get part width
          add eax, SBW.dVertDivider                     ;Add a vertical divider
          add xdx, sizeof(DWORD)                        ;Goto next part
          dec ecx
        .until ZERO?
        sub eax, SBW.dVertDivider                       ;Last part has no vertical divider
      .endif

      .if eax < dAvailWidth
        mov edx, dAvailWidth                            ;Calc width for this priority level
        sub edx, eax
        add [xdi], edx
        .break
      .endif
      inc ebx
    .endw

    ;Convert the widths array to a position array
    mov eax, dAvailWidth
    mov xdx, [xsi].pDataArray                           ;xdx -> part width array
    mov ecx, dPartCount
    lea xdi, [xdx + sizeof(DWORD)*xcx]                  ;Go to last part + 1
    mov edx, -1                                         ;-1 => extend to the border of the window
    test ecx, ecx
    .while !ZERO?
      sub xdi, sizeof(DWORD)
      sub eax, DWORD ptr [xdi]                          ;Subtract width before we overwrite it
      mov [xdi], edx                                    ;Store position
      sub eax, SBW.dVertDivider                         ;Calculate new position
      mov edx, eax
      dec ecx
    .endw

    invoke SendMessage, [xsi].hWnd, SB_SETPARTS, dPartCount, [xsi].pDataArray
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Statusbar.OnSize
; Purpose:    Event procedure for WM_SIZE message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if not handled.

Method Statusbar.OnSize, uses xsi, wParam:WPARAM, lParam:LPARAM
  SetObject xsi
  OCall xsi.SetPartWidths
  mov xdx, [xsi].hWnd
  invoke CallWindowProc, [xsi].pPrevWndProc, xdx, WM_SIZE, wParam, lParam
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Statusbar.WndProc
; Purpose:    Processing of window messages. Before invoking it, the window must be subclassed.
; Arguments:  Arg1: Message identifier.
;             Arg2: First message parameter.
;             Arg3: Second message parameter.
; Return:     eax = The value is the result of the message processing and depends on the message ID.
; Note:       Window handle is passed in pSelf (hidden parameter).

Method Statusbar.WndProc,, uMsg:DWORD, wParam:WPARAM, lParam:LPARAM
;  DbgMessage uMsg
  GetSubclassingInst Statusbar, pSelf
  OCall xax::Statusbar.Dispatch, pSelf, uMsg, wParam, lParam
MethodEnd

endif
