; ==================================================================================================
; Title:      ADE_FindDialog.inc
; Author:     G. Friedrich
; Version:    See ADE.asm
; Purpose:    ObjAsm Find dialog implementation.
; ==================================================================================================


; ==================================================================================================
; FindDialog implementation
; ==================================================================================================

IDD_DLG_FIND	                	equ 2000
IDC_BTN_FIND	                	equ 1
IDC_BTN_REPLACE	              	equ 1002
IDC_BTN_REPLACEALL	          	equ 1003
IDC_BTN_HELP	                	equ 1004
IDC_BTN_CANCEL	              	equ 2
IDC_STC_FIND	                	equ 1006
IDC_CBO_FIND	                	equ 1007
IDC_STC_REPLACE	              	equ 1008
IDC_CBO_REPLACE	              	equ 1009
IDC_GRP_SCOPE	                	equ 1010
IDC_RBN_CURRFILE	            	equ 1011
IDC_RBN_OPENFILES	            	equ 1012
IDC_RBN_PROJFILES	            	equ 1013
IDC_RBN_ALLFILES	            	equ 1014
IDC_GRP_OPTIONS	              	equ 1015
IDC_CHK_MATCHCASE	            	equ 1016
IDC_CHK_WHOLEWORD	            	equ 1017
IDC_CHK_IGNORESPACE	          	equ 1018
IDC_CHK_USEREGEX	            	equ 1019
IDC_GRP_DIRECTION	            	equ 1020
IDC_RBN_DOWN	                	equ 1021
IDC_RBN_UP	                  	equ 1022
IDC_RBN_ALL	                  	equ 1023
IDC_CHK_WRAPAROUND	          	equ 1024

;SetCtrlText macro ControlID, TextID
;  lea edx, [ebx + TextID]
;  invoke LoadString, hInstance, edx, xdi, lengthof(cBuffer) - 1
;  invoke SetDlgItemText, [xsi].hWnd, ControlID, xdi
;endm

;  ;Set caption and control strings
;  mov xcx, [xsi].pOwner
;  mov ebx, [xcx].$Obj(Application).dLanguage
;  lea xdi, cBuffer
;
;  lea edx, [ebx + IDS_SETUP_CAPTION]
;  invoke LoadString, hInstance, edx, xdi, lengthof(cBuffer) - 1
;  invoke SetWindowText, [xsi].hWnd, xdi
;  SetCtrlText IDC_SETUP_VIEWER_GRP,   IDS_SETUP_VIEWER_GRP

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     FindDialog.CtlsGet
; Purpose:    Read the setting of all controls.
; Arguments:  None.
; Return:     Nothing.

Method FindDialog.CtlsGet, uses xbx xdi xsi
  local hComboBox:HWND

  SetObject xsi
  mov eax, TRUE
  OCall [xsi].FindStrings::%StrCollection.DisposeAll
  mov hComboBox, $invoke(GetDlgItem, [xsi].hWnd, IDC_CBO_FIND)
  mov ebx, $32($invoke(SendMessage, hComboBox, CB_GETCOUNT, 0, 0))
  .while ebx != 0
    invoke SendMessage, hComboBox, CB_GETITEMDATA, xax, 0
    dec ebx
  .endw

  mov ebx, FDS_ALL_FILES
  invoke IsDlgButtonChecked, [xsi].hWnd, IDC_RBN_CURRFILE
  .if eax == BST_CHECKED
    mov ebx, FDS_CURRENT_FILE
  .else
    invoke IsDlgButtonChecked, [xsi].hWnd, IDC_RBN_OPENFILES
    .if eax == BST_CHECKED
      mov ebx, FDS_OPEN_FILES
    .else
      invoke IsDlgButtonChecked, [xsi].hWnd, IDC_RBN_PROJFILES
      .if eax == BST_CHECKED
        mov ebx, FDS_PROJECT_FILES
      .endif
    .endif
  .endif
  mov [xsi].dScope, ebx

  xor ebx, ebx
  invoke IsDlgButtonChecked, [xsi].hWnd, IDC_CHK_MATCHCASE
  .if eax == BST_CHECKED
    BitSet ebx, FDO_MATCH_CASE
  .endif
  invoke IsDlgButtonChecked, [xsi].hWnd, IDC_CHK_WHOLEWORD
  .if eax == BST_CHECKED
    BitSet ebx, FDO_WHOLE_WORD
  .endif
  invoke IsDlgButtonChecked, [xsi].hWnd, IDC_CHK_IGNORESPACE
  .if eax == BST_CHECKED
    BitSet ebx, FDO_IGNORE_SPACE
  .endif
  invoke IsDlgButtonChecked, [xsi].hWnd, IDC_CHK_USEREGEX
  .if eax == BST_CHECKED
    mov ebx, FDO_USE_REGEX
  .endif
  mov [xsi].dOptions, ebx

  mov ebx, FDD_ALL
  invoke IsDlgButtonChecked, [xsi].hWnd, IDC_RBN_DOWN
  .if eax == BST_CHECKED
    mov ebx, FDD_DOWN
  .else
    invoke IsDlgButtonChecked, [xsi].hWnd, IDC_RBN_UP
    .if eax == BST_CHECKED
      mov ebx, FDD_UP
    .endif
  .endif
  mov [xsi].dDirection, ebx
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     FindDialog.CtlsSet
; Purpose:    Set the controls of the setup dialog.
; Arguments:  None.
; Return:     eax = this procedure should return TRUE to direct Windows to set the keyboard focus to
;                   the control specified by hwndFocus. Otherwise, it should return FALSE to prevent
;                   Windows from setting the default keyboard focus.

Method FindDialog.CtlsSet, uses xbx xdi xsi
  local hComboBox:HWND

  SetObject xsi
  mov hComboBox, $invoke(GetDlgItem, [xsi].hWnd, IDC_CBO_FIND)
  invoke SendMessage, hComboBox, CB_RESETCONTENT, 0, 0
  .ColForEach [xsi].FindStrings, ebx
    invoke SendMessage, hComboBox, CB_ADDSTRING, 0, xax
  .ColNext

  mov hComboBox, $invoke(GetDlgItem, [xsi].hWnd, IDC_CBO_REPLACE)
  invoke SendMessage, hComboBox, CB_RESETCONTENT, 0, 0
  .ColForEach [xsi].ReplaceStrings, ebx
    invoke SendMessage, hComboBox, CB_ADDSTRING, 0, xax
  .ColNext

  mov eax, [xsi].dScope
  add eax, IDC_RBN_CURRFILE
  invoke CheckRadioButton, [xsi].hWnd, IDC_RBN_CURRFILE, IDC_RBN_ALLFILES, eax

  mov eax, BST_UNCHECKED
  .ifBitSet [xsi].dOptions, FDO_MATCH_CASE
    mov eax, BST_CHECKED
  .endif
  invoke CheckDlgButton, [xsi].hWnd, IDC_CHK_MATCHCASE, eax

  mov eax, BST_UNCHECKED
  .ifBitSet [xsi].dOptions, FDO_WHOLE_WORD
    mov eax, BST_CHECKED
  .endif
  invoke CheckDlgButton, [xsi].hWnd, IDC_CHK_WHOLEWORD, eax

  mov eax, BST_UNCHECKED
  .ifBitSet [xsi].dOptions, FDO_IGNORE_SPACE
    mov eax, BST_CHECKED
  .endif
  invoke CheckDlgButton, [xsi].hWnd, IDC_CHK_IGNORESPACE, eax

  mov eax, BST_UNCHECKED
  .ifBitSet [xsi].dOptions, FDO_USE_REGEX
    mov eax, BST_CHECKED
  .endif
  invoke CheckDlgButton, [xsi].hWnd, IDC_CHK_USEREGEX, eax

  mov eax, [xsi].dDirection
  add eax, IDC_RBN_DOWN
  invoke CheckRadioButton, [xsi].hWnd, IDC_RBN_DOWN, IDC_RBN_ALL, eax

  mov eax, BST_UNCHECKED
  .ifBitSet [xsi].dOptions, FDO_WRAP_AROUND
    mov eax, BST_CHECKED
  .endif
  invoke CheckDlgButton, [xsi].hWnd, IDC_CHK_WRAPAROUND, eax
  mov eax, TRUE
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     FindDialog.Done
; Purpose:    Finalize the FindDialog object.
; Arguments:  None.
; Return:     Nothing.

Method FindDialog.Done, uses xsi
  SetObject xsi
  OCall [xsi].FindStrings::%StrCollection.Done
  OCall [xsi].ReplaceStrings::%StrCollection.Done
  ACall xsi.Done
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     FindDialog.Find
; Purpose:    Do the search operation
; Arguments:  Arg1: -> Active child window object.
; Return:     eax = TRUE if succeeded, otherwise FALSE.

;FindInOpenFile proc uses xdi xsi hChildWnd:HWND, pSelf:POINTER
;  SetObject xsi, FindDialog
;  invoke SendMessage, hChildWnd, WM_GETOBJECTINSTANCE, 0, 0
;  .if xax != NULL
;    mov xdi, xax
;    invoke GetObjectID, xdi
;    .if eax == ADE_EditorID
;      OCall xdi::Editor.FindFrom, [xsi].pFindString, addr [xsi].dLineNumber, addr [xsi].dCharIndex
;    .endif
;  .endif
;  ReleaseObject
;  ret
;FindInOpenFile endp

Method FindDialog.Find, uses xbx xdi xsi, pChildWndObject:POINTER
  local cFindString[2024]:CHR, hComboBox:HWND

  SetObject xsi
  ;Read the Find combobox
  mov hComboBox, $invoke(GetDlgItem, [xsi].hWnd, IDC_CBO_FIND)
  lea xax, cFindString
  mov [xsi].pFindString, xax
  invoke SendMessage, hComboBox, WM_GETTEXT, lengthof(cFindString), xax
  invoke SendMessage, hComboBox, CB_INSERTSTRING, 0, [xsi].pFindString

  .if [xsi].dScope == FDS_CURRENT_FILE
    invoke GetObjectID, pChildWndObject
    .if eax == ADE_EditorID
      OCall pChildWndObject::Editor.FindFrom, [xsi].pFindString, addr [xsi].dLineNumber, addr [xsi].dCharIndex
      .if eax == FALSE
        invoke MessageBox, [xsi].hWnd, $OfsCStr("No more matches found."), $OfsCStr("Find"), MB_OK or MB_ICONINFORMATION
        xor eax, eax
      .endif
    .else
      xor eax, eax
    .endif

  .elseif [xsi].dScope == FDS_OPEN_FILES
    mov xax, [xsi].pOwner
    mov xbx, [xax].$Obj(MdiApp).pClientWnd
;    invoke EnumChildWindows, [xbx].$Obj(ClientWnd).hWnd, offset FindInOpenFile, xsi  doesnt work since it does not stop

  .elseif [xsi].dScope == FDS_PROJECT_FILES

  .elseif [xsi].dScope == FDS_ALL_FILES

  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     FindDialog.Help
; Purpose:    Provide help for this dialog.
; Arguments:  None.
; Return:     Nothing.

Method FindDialog.Help, uses xbx xsi
  SetObject xsi
  invoke MessageBox, [xsi].hWnd, $OfsCStr("Help me please..."), $OfsCStr("Help"), MB_OK or MB_ICONINFORMATION
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     FindDialog.Init
; Purpose:    Initialaize a FindDialog object.
; Arguments:  Arg1: -> Owner object (Application).
; Return:     Nothing.

Method FindDialog.Init, uses xbx xsi, pOwner:POINTER
  SetObject xsi
  mov xax, pOwner
  ACall xsi.Init, pOwner, [xax].$Obj(MdiApp).hWnd, 2000, addr [xax].$Obj(MdiApp).hActiveMlsDlg

  OCall [xsi].FindStrings::%StrCollection.Init, xsi, 20, 20, COL_MAX_CAPACITY
  OCall [xsi].ReplaceStrings::%StrCollection.Init, xsi, 20, 20, COL_MAX_CAPACITY
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     FindDialog.OnActivate
; Purpose:    Event procedure for WM_ACTIVATE message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method FindDialog.OnActivate, uses xbx xsi, wParam:WPARAM, lParam:LPARAM
  ANNOTATION use:wParam lParam

  SetObject xsi
  ACall xsi.OnActivate, wParam, lParam
  mov xax, wParam
  .if ax != WA_INACTIVE
    mov xbx, $invoke(GetDlgItem, [xsi].hWnd, IDC_CBO_FIND)
;    invoke SendMessage, xbx, WM_SETTEXT, 0, Selection
    invoke SendMessage, xbx, CB_SETEDITSEL, 0, 0FFFF0000h
    invoke SetFocus, xbx
  .endif
  xor eax, eax
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     FindDialog.OnCommand
; Purpose:    Event procedure for WM_COMMAND message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method FindDialog.OnCommand, uses xdi xsi, wParam:WPARAM, lParam:LPARAM
  ANNOTATION use:wParam lParam

  SetObject xsi
  LoWord(wParam)
  .if ax == IDC_BTN_HELP
    OCall xsi.Help
  .elseif ax == IDCANCEL
    invoke ShowWindow, [xsi].hWnd, SW_HIDE
  .else
    mov xax, [xsi].pOwner
    mov xcx, [xax].$Obj(MdiApp).pClientWnd
    invoke SendMessage, [xcx].$Obj(ClientWnd).hWnd, WM_MDIGETACTIVE, 0, 0
    invoke SendMessage, xax, WM_GETOBJECTINSTANCE, 0, 0
    .if xax != NULL
      mov xdi, xax
      LoWord(wParam)
      .if ax == IDOK                                        ;Find Button
        OCall xsi.CtlsGet
        OCall xsi.Find, xdi
        .if eax != FALSE
          invoke RedrawWindow, [xdi].$Obj(Editor).hWnd, NULL, 0, RDW_INVALIDATE or RDW_UPDATENOW or RDW_ALLCHILDREN
        .endif

      .elseif ax == IDC_BTN_REPLACE
        OCall xsi.CtlsGet
        OCall xsi.Replace, xdi
        .if eax != FALSE
          invoke RedrawWindow, [xdi].$Obj(Editor).hWnd, NULL, 0, RDW_INVALIDATE or RDW_UPDATENOW or RDW_ALLCHILDREN
        .endif

      .elseif ax == IDC_BTN_REPLACEALL
        OCall xsi.CtlsGet
        OCall xsi.ReplaceAll, xdi
        .if eax != FALSE
          invoke RedrawWindow, [xdi].$Obj(Editor).hWnd, NULL, 0, RDW_INVALIDATE or RDW_UPDATENOW or RDW_ALLCHILDREN
        .endif
      .endif
    .endif
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     FindDialog.OnDestroy
; Purpose:    Event procedure for WM_DESTROY message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     Nothing.

Method FindDialog.OnDestroy, uses xsi, wParam:WPARAM, lParam:LPARAM
  ANNOTATION use:wParam lParam

  SetObject xsi
  invoke SetWindowLongPtr, [xsi].hWnd, DWLP_USER, NULL
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     FindDialog.Replace
; Purpose:    Replace the editor selection with the content of the replace combobox.
; Arguments:  Arg1: -> Active child window object.
; Return:     eax = TRUE if succeeded, otherwise FALSE.

Method FindDialog.Replace, uses xbx xsi, pChildWndObject:POINTER
  local cReplString[2024]:CHR, hComboBox:HWND

  SetObject xsi
  ;Read the Replace combobox
  mov hComboBox, $invoke(GetDlgItem, [xsi].hWnd, IDC_CBO_REPLACE)
  lea xax, cReplString
  mov [xsi].pReplString, xax
  invoke SendMessage, hComboBox, WM_GETTEXT, lengthof(cReplString), xax
  invoke SendMessage, hComboBox, CB_INSERTSTRING, 0, [xsi].pReplString

  .if [xsi].dScope == FDS_CURRENT_FILE
    invoke GetObjectID, pChildWndObject
    .if eax == ADE_EditorID
      OCall pChildWndObject::Editor.SelectionReplace, [xsi].pReplString
      .if eax == FALSE
        invoke MessageBox, [xsi].hWnd, $OfsCStr("Nothing selected."), $OfsCStr("Replace"), MB_OK or MB_ICONINFORMATION
        xor eax, eax
      .endif
    .else
      xor eax, eax
    .endif

  .elseif [xsi].dScope == FDS_OPEN_FILES

  .elseif [xsi].dScope == FDS_PROJECT_FILES

  .elseif [xsi].dScope == FDS_ALL_FILES

  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     FindDialog.ReplaceAll
; Purpose:    Replace all occurrences with the content of the replace combobox.
; Arguments:  Arg1: -> Active child window object.
; Return:     eax = TRUE if succeeded, otherwise FALSE.

Method FindDialog.ReplaceAll, uses xbx xdi xsi, pChildWndObject:POINTER
  local cFindString[2024]:CHR, cReplString[2024]:CHR, hComboBox:HWND, hChildWnd:HWND

  SetObject xsi
  ;Read the Find combobox
  mov hComboBox, $invoke(GetDlgItem, [xsi].hWnd, IDC_CBO_FIND)
  lea xax, cFindString
  mov [xsi].pFindString, xax
  invoke SendMessage, hComboBox, WM_GETTEXT, lengthof(cFindString), xax
  invoke SendMessage, hComboBox, CB_INSERTSTRING, 0, [xsi].pFindString

  ;Read the Replace combobox
  mov hComboBox, $invoke(GetDlgItem, [xsi].hWnd, IDC_CBO_REPLACE)
  lea xax, cReplString
  mov [xsi].pReplString, xax
  invoke SendMessage, hComboBox, WM_GETTEXT, lengthof(cReplString), xax
  invoke SendMessage, hComboBox, CB_INSERTSTRING, 0, [xsi].pReplString

  .if [xsi].dScope == FDS_CURRENT_FILE
    invoke GetObjectID, pChildWndObject
    .if eax == ADE_EditorID
    @@:
      OCall pChildWndObject::Editor.SelectionReplace, [xsi].pReplString
      OCall pChildWndObject::Editor.FindFrom, [xsi].pFindString, addr [xsi].dLineNumber, addr [xsi].dCharIndex
      cmp eax, FALSE
      jnz @B
      invoke MessageBox, [xsi].hWnd, $OfsCStr("All matches replaced."), $OfsCStr("Replace all"), MB_OK or MB_ICONINFORMATION
      mov eax, TRUE
    .else
      xor eax, eax
    .endif

  .elseif [xsi].dScope == FDS_OPEN_FILES

  .elseif [xsi].dScope == FDS_PROJECT_FILES

  .elseif [xsi].dScope == FDS_ALL_FILES

  .endif
MethodEnd
