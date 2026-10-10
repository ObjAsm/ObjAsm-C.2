; ==================================================================================================
; Title:      Statusbar.inc
; Author:     G. Friedrich
; Version:    C.1.1
; Purpose:    ObjAsm support of Statusbar objects based on common controls Version 5.81.
; Notes:      Version C.1.0, October 2017
;               - Initial release.
;               - To clear a part, use SetPartText with NULL as string argument.
;             Version C.1.1, October 2026
;               - SetPartWidths: SBARS_SIZEGRIP is now tested correctly, the horizontal border
;                 width is taken from SB_GETBORDERS, IsZoomed replaces GetWindowPlacement and
;                 guards were added for missing data and non-positive available width.
;               - SetPartText: the part style is no longer shifted (SBT_* are or'ed directly).
;               - Init: the parts are created before their styles and initial tip texts are
;                 applied. DEF_STATUSBAR_PART.pTipText is now used.
;               - OnSize: the control is resized first, then the part widths are calculated.
;               - Done: unsubclass before freeing memory, the data pointer is cleared.
;               - GetPartParentRect: uses MapWindowPoints.
;               - SetPartTipText now uses its own tooltips_class32 control with one tool per part.
;                 The tip is shown on hover even if the part text is not truncated. A NULL or empty
;                 string removes the tip. The control is created on demand.
;               - The built-in status bar tooltips (SBARS_TOOLTIPS) are masked out at creation to
;                 avoid a second tip for truncated parts.
;               - The tools use TTF_SUBCLASS, so the tooltip control receives the mouse messages
;                 by itself. New method: UpdateTipRects. New variable: hTooltip.
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
  pTipText    PSTRING   ?   ;-> Initial Tooltip string
DEF_STATUSBAR_PART ends
PDEF_STATUSBAR_PART typedef ptr DEF_STATUSBAR_PART

SBT_SUNKEN    equ    0    ;Default
SB_GRIPWIDTH  equ    11h

;Size of TOOLINFO up to and including lpszText (the "V1" size, accepted by all comctl32 versions):
;  cbSize + uFlags (8), rect (16), hwnd, uId, hinst, lpszText (4 pointers)
;  x86 = 40 bytes, x64 = 56 bytes
SB_TOOLINFO_SIZE equ 8 + sizeof(RECT) + 4 * sizeof(POINTER)

; --------------------------------------------------------------------------------------------------
; Object:     Statusbar
; Purpose:    Implement a thin wrapper around the msctls_statusbar32 GDI control.

Object Statusbar, StatusbarID, WinControl                       ;Class "msctls_statusbar32"
  RedefineMethod    Done
  VirtualMethod     GetPartParentRect,  DWORD, PRECT
  VirtualMethod     GetPartRect,        DWORD, PRECT
  RedefineMethod    Init,               POINTER, HWND, PDEF_STATUSBAR
  VirtualMethod     SetPartText,        DWORD, PSTRING, DWORD
  VirtualMethod     SetPartTipText,     DWORD, PSTRING
  VirtualMethod     UpdateTipRects
  VirtualMethod     SetPartIcon,        DWORD, HICON
  VirtualMethod     SetPartWidths
  RedefineMethod    WndProc,            DWORD, WPARAM, LPARAM

  DefineVariable    pDefStruc,          PDEF_STATUSBAR, NULL
  DefineVariable    pDataArray,         POINTER,        NULL
  DefineVariable    hTooltip,           HWND,           NULL

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
  .if [xsi].hTooltip != NULL                            ;Destroy it before unsubclassing
    invoke DestroyWindow, [xsi].hTooltip
    mov [xsi].hTooltip, NULL
  .endif
  Unsubclass Statusbar                                  ;Uses xsi
  MemFree [xsi].pDataArray
  mov [xsi].pDataArray, NULL
  ACall xsi.Done
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Statusbar.GetPartParentRect
; Purpose:    Retrieve the bounding rectangle of a Part relative to the parent window client area.
;             It supports a maximum of 256 parts.
; Arguments:  Arg1: Zero-based part index.
;             Arg2: -> RECT structure.
; Return:     Nothing.

Method Statusbar.GetPartParentRect, uses xsi, dID:DWORD, pRect:PRECT
  SetObject xsi
  invoke SendMessage, [xsi].hWnd, SB_GETRECT, dID, pRect
  invoke GetParent, [xsi].hWnd
  invoke MapWindowPoints, [xsi].hWnd, xax, pRect, 2     ;Convert left/top and right/bottom
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
;             Arg3: -> DEF_STATUSBAR initialization structure. It is followed immediately by
;                   DEF_STATUSBAR.dCount DEF_STATUSBAR_PART structures. The whole definition must
;                   stay valid during the lifetime of the control, because it is evaluated on
;                   every WM_SIZE. DEF_STATUSBAR_PART.pTipText may be NULL.
; Return:     Nothing.

Method Statusbar.Init, uses xbx xdi xsi, pOwner:POINTER, hParent:HWND, pDefStruc:PDEF_STATUSBAR
  local dPartCount:DWORD

  SetObject xsi
  mrm [xsi].pDefStruc, pDefStruc, xbx

  assume xbx:PDEF_STATUSBAR
  mov edi, [xbx].dStyle
  and edi, NOT SBARS_TOOLTIPS                           ;Tips are handled by our own tooltip control
  invoke CreateWindowEx, [xbx].dExStyle, $OfsCStr("msctls_statusbar32"), NULL, \
                         edi, 0, 0, 0, 0, hParent, [xbx].xCtlID, hInstance, 0
  ACall xsi.Init, pOwner, xax
  Subclass Statusbar                                    ;Uses xsi

  mrm dPartCount, [xbx].dCount, eax                     ;Part count
  shl eax, $Log2(sizeof(DWORD))                         ;Storage for DWORDs
  mov [xsi].pDataArray, $MemAlloc(eax)                  ;Allocate memory for part widths calculation
  assume xbx:NOTHING

  ;Let the control size itself to its parent, so that its width is not 0 and the parts exist
  ;before their styles and tip texts are set.
  invoke SendMessage, [xsi].hWnd, WM_SIZE, 0, 0
  OCall xsi.SetPartWidths

  ;Set the style and the initial tip text of all parts.
  add xbx, sizeof(DEF_STATUSBAR)
  xor edi, edi
  .while edi != dPartCount
    OCall xsi.SetPartText, edi, NULL, [xbx].DEF_STATUSBAR_PART.dStyle
    .if [xbx].DEF_STATUSBAR_PART.pTipText != NULL
      OCall xsi.SetPartTipText, edi, [xbx].DEF_STATUSBAR_PART.pTipText
    .endif
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
  mov eax, dStyle                                       ;SBT_* are already in the right position
  or eax, dID
  invoke SendMessage, [xsi].hWnd, SB_SETTEXT, eax, pText
  .if ebx != dStyle                           ;To reduce flicker, redraw only if style has changed
    invoke SendMessage, [xsi].hWnd, SB_GETRECT, dID, addr Rct
    invoke InvalidateRect, [xsi].hWnd, addr Rct, TRUE
    invoke UpdateWindow, [xsi].hWnd
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Statusbar.SetPartTipText
; Purpose:    Set the tip text of a part of the Statusbar. A separate tooltip control with one tool
;             per part is used, so the tip is also shown if the part text is not truncated.
; Arguments:  Arg1: Zero-based part index.
;             Arg2: -> String. NULL or an empty string removes the tip of the part.
; Return:     Nothing.
; Note:       The tooltip control is created on demand. The text is copied by the tooltip control.

Method Statusbar.SetPartTipText, uses xbx xsi, dID:DWORD, pText:PSTRING
  local TI:TOOLINFO

  SetObject xsi

  xor ebx, ebx                                          ;ebx = TRUE if a tip text is given
  mov xax, pText
  .if xax != NULL
    .if CHR ptr [xax] != 0
      inc ebx
    .endif
  .endif

  .if [xsi].hTooltip == NULL
    test ebx, ebx
    jz @@EOM                                            ;Nothing to remove
    invoke CreateWindowEx, WS_EX_TOPMOST, $OfsCStr("tooltips_class32"), NULL, \
                           WS_POPUP or TTS_NOPREFIX or TTS_ALWAYSTIP, \
                           CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, \
                           [xsi].hWnd, NULL, hInstance, NULL
    mov [xsi].hTooltip, xax
    test xax, xax
    jz @@EOM
  .endif

  ;Identify the tool: window + part index
  mov TI.cbSize, SB_TOOLINFO_SIZE
  mov TI.uFlags, 0
  m2m TI.hwnd, [xsi].hWnd, xax
  mov eax, dID
  mov TI.uId, xax
  mov TI.hinst, NULL
  mov TI.lpszText, NULL
  mov TI.lParam, 0
  invoke SendMessage, [xsi].hTooltip, TTM_GETTOOLINFO, 0, addr TI   ;eax = TRUE if tool exists

  .if ebx == 0
    .if eax != FALSE
      invoke SendMessage, [xsi].hTooltip, TTM_DELTOOL, 0, addr TI
    .endif
  .else
    .if eax != FALSE
      m2m TI.lpszText, pText, xax
      invoke SendMessage, [xsi].hTooltip, TTM_UPDATETIPTEXT, 0, addr TI
    .else
      invoke SetRectEmpty, addr TI.rect                 ;Used if the part does not exist yet,
      invoke SendMessage, [xsi].hWnd, SB_GETRECT, dID, addr TI.rect  ;  UpdateTipRects fixes it later
      mov TI.uFlags, TTF_SUBCLASS                       ;The tooltip control hooks the mouse messages
      m2m TI.lpszText, pText, xax
      invoke SendMessage, [xsi].hTooltip, TTM_ADDTOOL, 0, addr TI
    .endif
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Statusbar.UpdateTipRects
; Purpose:    Adjust the tool rectangles of all existing part tips to the current part layout.
; Arguments:  None.
; Return:     Nothing.

Method Statusbar.UpdateTipRects, uses xbx xdi xsi
  local TI:TOOLINFO

  SetObject xsi
  .if [xsi].hTooltip == NULL || [xsi].pDefStruc == NULL
    jmp @@EOM
  .endif

  mov xax, [xsi].pDefStruc
  mov ebx, [xax].DEF_STATUSBAR.dCount
  xor edi, edi
  .while edi != ebx
    mov TI.cbSize, SB_TOOLINFO_SIZE
    mov TI.uFlags, 0
    m2m TI.hwnd, [xsi].hWnd, xax
    mov TI.uId, xdi
    mov TI.hinst, NULL
    mov TI.lpszText, NULL
    mov TI.lParam, 0
    invoke SendMessage, [xsi].hTooltip, TTM_GETTOOLINFO, 0, addr TI
    .if eax != FALSE                                    ;Only parts that have a tip
      invoke SendMessage, [xsi].hWnd, SB_GETRECT, edi, addr TI.rect
      .if eax != FALSE
        invoke SendMessage, [xsi].hTooltip, TTM_NEWTOOLRECT, 0, addr TI
      .endif
    .endif
    inc edi
  .endw
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Statusbar.SetPartIcon
; Purpose:    Set the icon of a part of the statusbar.
; Arguments:  Arg1: Zero-based part index.
;             Arg2: Icon handle. Use "LoadImage" to get the icon in the correct size.
; Return:     Nothing.

Method Statusbar.SetPartIcon,, dID:DWORD, hIcon:HICON
  SetObject xax
  invoke SendMessage, [xax].hWnd, SB_SETICON, dID, hIcon
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Statusbar.SetPartWidths
; Purpose:    Calculate the widths of all parts according to the definition structure and the total
;             statusbar width.
; Arguments:  None.
; Return:     Nothing.
; Note:       The priorities of the parts must be unique and in the range 0 .. PartCount - 1.
;             Otherwise the part widths are left unchanged.

Method Statusbar.SetPartWidths, uses xbx xdi xsi

  SB_WIDTH struc
    dHorzBorder   DWORD   ?
    dVertBorder   DWORD   ?
    dVertDivider  DWORD   ?
  SB_WIDTH ends

  local SBW:SB_WIDTH, Rct:RECT, pPartData:PDEF_STATUSBAR_PART
  local dPartCount:DWORD, dAvailWidth:DWORD

  SetObject xsi

  .if [xsi].pDataArray == NULL || [xsi].pDefStruc == NULL
    jmp @@EOM                                           ;Not initialized yet
  .endif

  invoke GetClientRect, [xsi].hWnd, addr Rct
  mov ebx, Rct.right                                    ;Skip if window width = 0
  .if ebx != 0

    ;Calculate dAvailWidth = effective available width incl. vertical dividers
    invoke SendMessage, [xsi].hWnd, SB_GETBORDERS, 0, addr SBW
    mov eax, SBW.dHorzBorder
    add eax, eax
    sub ebx, eax                                        ;Subtract 2x horizontal borders
    invoke GetWindowLongPtr, [xsi].hWnd, GWL_STYLE
    .if eax & SBARS_SIZEGRIP
      invoke GetParent, [xsi].hWnd
      invoke IsZoomed, xax                              ;On maximized main windows
      .if eax == FALSE                                  ;  the GripSize is not shown
        sub ebx, SB_GRIPWIDTH                           ;ebx = Grip width
      .endif
    .endif
    mov dAvailWidth, ebx
    test ebx, ebx                                       ;Skip if there is no space left
    jle @@EOM

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
    OCall xsi.UpdateTipRects                            ;Keep the tip rectangles in sync
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Statusbar.OnSize
; Purpose:    Event procedure for WM_SIZE message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if not handled.

Method Statusbar.OnSize, uses xsi, wParam:WPARAM, lParam:LPARAM
  local xResult:XWORD

  SetObject xsi
  ;Let the control resize itself first, then calculate the parts with the new width.
  invoke CallWindowProc, [xsi].pPrevWndProc, [xsi].hWnd, WM_SIZE, wParam, lParam
  mov xResult, xax
  OCall xsi.SetPartWidths
  mov xax, xResult
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







;; ==================================================================================================
;; Title:      Statusbar.inc
;; Author:     G. Friedrich
;; Version:    C.1.0
;; Purpose:    ObjAsm support of Statusbar objects based on common controls Version 5.81.
;; Notes:      Version C.1.0, October 2017
;;               - Initial release.
;;               - To clear a part, use SetPartText with NULL as string argument.
;; ==================================================================================================
;
;
;DEF_STATUSBAR struc
;  xCtlID      XWORD     ?   ;Control ID
;  dStyle      DWORD     ?   ;Style
;  dExStyle    DWORD     ?   ;Extended style
;  dCount      DWORD     ?   ;Part count
;DEF_STATUSBAR ends
;PDEF_STATUSBAR typedef ptr DEF_STATUSBAR
;
;DEF_STATUSBAR_PART struc
;  dMaxWidth   DWORD     ?   ;Maximal width of the part in pixel
;  dMinWidth   DWORD     ?   ;-2 => dissapears; +2 => minimal width
;  dPriority   DWORD     ?   ;Shrink/Expansion order (0 is the first that shrinks)
;  dStyle      DWORD     ?   ;SBT_SUNKEN, SBT_NOBORDERS, SBT_POPOUT, SBT_OWNERDRAW
;  pTipText    PSTRING   ?   ;-> Initial Tooltip string
;DEF_STATUSBAR_PART ends
;PDEF_STATUSBAR_PART typedef ptr DEF_STATUSBAR_PART
;
;SBT_SUNKEN      equ    0    ;Default
;
;SB_SETICON      equ    WM_USER + 15
;SB_GRIPWIDTH    equ    11h
;SBARS_TOOLTIPS  equ    800h
;LR_LOADREALSIZE equ    80h
;
;; --------------------------------------------------------------------------------------------------
;; Object:     Statusbar
;; Purpose:    Implement a thin wrapper around the msctls_statusbar32 GDI control.
;
;Object Statusbar, StatusbarID, WinControl                       ;Class "msctls_statusbar32"
;  RedefineMethod    Done
;  VirtualMethod     GetPartParentRect,  DWORD, PRECT
;  VirtualMethod     GetPartRect,        DWORD, PRECT
;  RedefineMethod    Init,               POINTER, HWND, PDEF_STATUSBAR
;  VirtualMethod     SetPartText,        DWORD, PSTRING, DWORD
;  VirtualMethod     SetPartTipText,     DWORD, PSTRING
;  VirtualMethod     SetPartIcon,        DWORD, HICON
;  VirtualMethod     SetPartWidths
;  RedefineMethod    WndProc,            DWORD, WPARAM, LPARAM
;
;  DefineVariable    pDefStruc,          PDEF_STATUSBAR, NULL
;  DefineVariable    pDataArray,         POINTER,        NULL
;
;  VirtualEvent      OnSize,         WM_SIZE
;ObjectEnd
;
;
;; ==================================================================================================
;
;if IMPLEMENT
;
;; --------------------------------------------------------------------------------------------------
;; Method:     Statusbar.Done
;; Purpose:    Finalize the Statusbar object, freeing allocated memory.
;; Arguments:  None.
;; Return:     Nothing.
;
;Method Statusbar.Done, uses xsi
;  SetObject xsi
;  MemFree [xsi].pDataArray
;  Unsubclass Statusbar                                  ;Uses xsi
;  ACall xsi.Done
;MethodEnd
;
;; --------------------------------------------------------------------------------------------------
;; Method:     Statusbar.GetPartParentRect
;; Purpose:    Retrieve the relative bounding rectangle of a Part to the Statusbar control. It
;;             supports a maximum of 256 parts.
;; Arguments:  Arg1: Zero-based part index.
;;             Arg2: -> RECT structure.
;; Return:     Nothing.
;
;Method Statusbar.GetPartParentRect, uses xsi, dID:DWORD, pRect:PRECT
;  local SbRect:RECT
;
;  SetObject xsi
;  invoke GetWindowRect, [xsi].hWnd, addr SbRect
;  invoke GetParent, [xsi].hWnd
;  lea xdx, SbRect
;  invoke ScreenToClient, xax, xdx
;  invoke SendMessage, [xsi].hWnd, SB_GETRECT, dID, pRect
;  mov xcx, pRect
;  mov eax, SbRect.left
;  add [xcx].RECT.left, eax
;  add [xcx].RECT.right, eax
;  mov eax, SbRect.top
;  add [xcx].RECT.top, eax
;  add [xcx].RECT.bottom, eax
;MethodEnd
;
;; --------------------------------------------------------------------------------------------------
;; Method:     Statusbar.GetPartRect
;; Purpose:    Retrieve the bounding rectangle of a Part in a Statusbar control.
;; Arguments:  Arg1: Zero-based part index.
;;             Arg2: -> RECT structure.
;; Return:     Nothing.
;
;Method Statusbar.GetPartRect,, dID:DWORD, pRect:PRECT
;  SetObject xcx
;  invoke SendMessage, [xcx].hWnd, SB_GETRECT, dID, pRect
;MethodEnd
;
;; --------------------------------------------------------------------------------------------------
;; Method:     Statusbar.Init
;; Purpose:    Initialize the Statusbar object.
;; Arguments:  Arg1: -> Owner object.
;;             Arg2: Parent window HANDLE.
;;             Arg3: -> DEF_STATUSBAR initialization structure.
;; Return:     Nothing.
;
;Method Statusbar.Init, uses xbx xdi xsi, pOwner:POINTER, hParent:HWND, pDefStruc:PDEF_STATUSBAR
;  local dPartCount:DWORD
;
;  SetObject xsi
;  mrm [xsi].pDefStruc, pDefStruc, xbx
;
;  assume xbx:PDEF_STATUSBAR
;  invoke CreateWindowEx, [xbx].dExStyle, $OfsCStr("msctls_statusbar32"), NULL, \
;                         [xbx].dStyle, 0, 0, 0, 0, hParent, [xbx].xCtlID, hInstance, 0
;  ACall xsi.Init, pOwner, xax
;  Subclass Statusbar                                    ;Uses xsi
;
;  mrm dPartCount, [xbx].dCount, eax                     ;Part count
;  shl eax, $Log2(sizeof(DWORD))                         ;Storage for DWORDs
;  mov [xsi].pDataArray, $MemAlloc(eax)                  ;Allocate memory for part widths calculation
;  assume xbx:NOTHING
;
;  OCall xsi.SetPartWidths
;
;  ;Set the style of all parts.
;  add xbx, sizeof(DEF_STATUSBAR)
;  xor edi, edi
;  .while edi != dPartCount
;    OCall xsi.SetPartText, edi, NULL, [xbx].DEF_STATUSBAR_PART.dStyle
;    add xbx, sizeof(DEF_STATUSBAR_PART)
;    inc edi
;  .endw
;MethodEnd
;
;; --------------------------------------------------------------------------------------------------
;; Method:     Statusbar.SetPartText
;; Purpose:    Set the text of a part of the Statusbar.
;; Arguments:  Arg1: Zero-based part index.
;;             Arg2: -> String. The text for each part is limited to 127 characters.
;;             Arg3: Part style:
;;                   SBT_SUNKEN, SBT_NOBORDERS, SBT_POPOUT, SBT_RTLREADING, SBT_OWNERDRAW.
;; Return:     Nothing.
;
;Method Statusbar.SetPartText, uses xbx xsi, dID:DWORD, pText:PSTRING, dStyle:DWORD
;  local Rct:RECT
;
;  SetObject xsi
;  invoke SendMessage, [xsi].hWnd, SB_GETTEXTLENGTH, dID, 0  ;Return = Length + Style * 2^16
;  shr eax, 16                                           ;eax = current drawing style
;  mov ebx, eax
;  mov eax, dStyle
;  shl eax, 8
;  or eax, dID
;  invoke SendMessage, [xsi].hWnd, SB_SETTEXT, eax, pText
;  .if ebx != dStyle                           ;To reduce flicker, redraw only if style has changed
;    invoke SendMessage, [xsi].hWnd, SB_GETRECT, dID, addr Rct
;    invoke InvalidateRect, [xsi].hWnd, addr Rct, TRUE
;    invoke UpdateWindow, [xsi].hWnd
;  .endif
;MethodEnd
;
;; --------------------------------------------------------------------------------------------------
;; Method:     Statusbar.SetPartTipText
;; Purpose:    Set the tip text of a part of the Statusbar.
;; Arguments:  Arg1: Zero-based part index.
;;             Arg2: -> String.
;; Return:     Nothing.
;
;Method Statusbar.SetPartTipText,, dID:DWORD, pText:PSTRING
;  SetObject xax
;  invoke SendMessage, [xax].hWnd, SB_SETTIPTEXT, dID, pText
;  DbgApiError
;MethodEnd
;
;; --------------------------------------------------------------------------------------------------
;; Method:     Statusbar.SetPartIcon
;; Purpose:    Set the icon of a part of the statusbar.
;; Arguments:  Arg1: Zero-based part index.
;;             Arg2: Icon handle. Use "LoadImage" to get the icon in the correct size.
;; Return:     Nothing.
;
;Method Statusbar.SetPartIcon,, dID:DWORD, hIcon:HICON
;  SetObject xax
;  invoke SendMessage, [xax].hWnd, SB_SETICON, dID, hIcon
;MethodEnd
;
;; --------------------------------------------------------------------------------------------------
;; Method:     Statusbar.SetPartWidths
;; Purpose:    Calculate the widths of all parts according to the definition structure and the total
;;             statusbar width.
;; Arguments:  None.
;; Return:     Nothing.
;
;Method Statusbar.SetPartWidths, uses xbx xdi xsi
;
;  SB_WIDTH struc
;    dHorzBorder   DWORD   ?
;    dVertBorder   DWORD   ?
;    dVertDivider  DWORD   ?
;  SB_WIDTH ends
;
;  local SBW:SB_WIDTH, Rct:RECT, WP:WINDOWPLACEMENT, pPartData:PDEF_STATUSBAR_PART
;  local dPartCount:DWORD, dAvailWidth:DWORD
;
;  SetObject xsi
;
;  invoke GetClientRect, [xsi].hWnd, addr Rct
;  mov ebx, Rct.right                                    ;Skip if window width = 0
;  .if ebx != 0
;
;    ;Calculate dAvailWidth = effective available width incl. vertical dividers
;    invoke SendMessage, [xsi].hWnd, SB_GETBORDERS, 0, addr SBW
;    add eax, eax
;    sub ebx, eax                                        ;Subrtract 2x borders
;    invoke GetWindowLongPtr, [xsi].hWnd, GWL_STYLE
;    .if eax || SBARS_SIZEGRIP
;      invoke GetParent, [xsi].hWnd
;      mov WP.length_, sizeof(WP)
;      lea xdx, WP
;      invoke GetWindowPlacement, xax, xdx               ;On maximized main windows
;      .if WP.showCmd != SW_MAXIMIZE                     ;  the GripSize is not shown
;        sub ebx, SB_GRIPWIDTH                           ;ebx = Grip width
;      .endif
;    .endif
;    mov dAvailWidth, ebx
;
;    mov xbx, [xsi].pDataArray
;    mov xdi, [xsi].pDefStruc
;    mrm dPartCount, [xdi].DEF_STATUSBAR.dCount, ecx
;    add xdi, sizeof(DEF_STATUSBAR)                      ;Skip DEF_STATUSBAR and go to
;    mov pPartData, xdi                                  ;  the 1st DEF_STATUSBAR_PART
;
;    ;Fill CurPartWidth structure with dMaxWidth
;    test ecx, ecx
;    .while !ZERO?
;      m2m [xbx], [xdi].DEF_STATUSBAR_PART.dMaxWidth, eax
;      add xdi, sizeof(DEF_STATUSBAR_PART)
;      add xbx, sizeof(DWORD)
;      dec ecx
;    .endw
;
;    xor ebx, ebx                                        ;ebx = Priority
;    .while ebx != dPartCount
;      mov xcx, pPartData
;      xor eax, eax
;      .while eax != dPartCount                          ;Find part with priority = ebx
;        cmp ebx, [xcx].DEF_STATUSBAR_PART.dPriority
;        jz @F                                           ;eax = found part index
;        add xcx, sizeof(DEF_STATUSBAR_PART)
;        inc eax
;      .endw
;      jmp @@EOM                                         ;Something went wrong with the
;    @@:                                                 ;  definitions => exit
;      mov xdx, [xsi].pDataArray
;      lea xdi, [xdx + sizeof(DWORD)*xax]
;      m2m [xdi], [xcx].DEF_STATUSBAR_PART.dMinWidth, eax
;
;      ;Add all widths & Dividers = eax
;      mov ecx, dPartCount
;      mov xdx, [xsi].pDataArray                         ;xdx -> current part widths
;      xor eax, eax
;      .if ecx != 0
;        .repeat
;          add eax, [xdx]                                ;Get part width
;          add eax, SBW.dVertDivider                     ;Add a vertical divider
;          add xdx, sizeof(DWORD)                        ;Goto next part
;          dec ecx
;        .until ZERO?
;        sub eax, SBW.dVertDivider                       ;Last part has no vertical divider
;      .endif
;
;      .if eax < dAvailWidth
;        mov edx, dAvailWidth                            ;Calc width for this priority level
;        sub edx, eax
;        add [xdi], edx
;        .break
;      .endif
;      inc ebx
;    .endw
;
;    ;Convert the widths array to a position array
;    mov eax, dAvailWidth
;    mov xdx, [xsi].pDataArray                           ;xdx -> part width array
;    mov ecx, dPartCount
;    lea xdi, [xdx + sizeof(DWORD)*xcx]                  ;Go to last part + 1
;    mov edx, -1                                         ;-1 => extend to the border of the window
;    test ecx, ecx
;    .while !ZERO?
;      sub xdi, sizeof(DWORD)
;      sub eax, DWORD ptr [xdi]                          ;Subtract width before we overwrite it
;      mov [xdi], edx                                    ;Store position
;      sub eax, SBW.dVertDivider                         ;Calculate new position
;      mov edx, eax
;      dec ecx
;    .endw
;
;    invoke SendMessage, [xsi].hWnd, SB_SETPARTS, dPartCount, [xsi].pDataArray
;  .endif
;MethodEnd
;
;; --------------------------------------------------------------------------------------------------
;; Method:     Statusbar.OnSize
;; Purpose:    Event procedure for WM_SIZE message.
;; Arguments:  Arg1: First message parameter.
;;             Arg2: Second message parameter.
;; Return:     eax = Zero if not handled.
;
;Method Statusbar.OnSize, uses xsi, wParam:WPARAM, lParam:LPARAM
;  SetObject xsi
;  OCall xsi.SetPartWidths
;  mov xdx, [xsi].hWnd
;  invoke CallWindowProc, [xsi].pPrevWndProc, xdx, WM_SIZE, wParam, lParam
;MethodEnd
;
;; --------------------------------------------------------------------------------------------------
;; Method:     Statusbar.WndProc
;; Purpose:    Processing of window messages. Before invoking it, the window must be subclassed.
;; Arguments:  Arg1: Message identifier.
;;             Arg2: First message parameter.
;;             Arg3: Second message parameter.
;; Return:     eax = The value is the result of the message processing and depends on the message ID.
;; Note:       Window handle is passed in pSelf (hidden parameter).
;
;Method Statusbar.WndProc,, uMsg:DWORD, wParam:WPARAM, lParam:LPARAM
;;  DbgMessage uMsg
;  GetSubclassingInst Statusbar, pSelf
;  OCall xax::Statusbar.Dispatch, pSelf, uMsg, wParam, lParam
;MethodEnd
;
;endif
