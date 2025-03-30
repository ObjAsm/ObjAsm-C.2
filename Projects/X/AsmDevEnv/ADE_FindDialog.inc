; ==================================================================================================
; Title:      ADE_FindDialog.inc
; Author:     G. Friedrich
; Version:    See ADE.asm
; Purpose:    ObjAsm Find dialog implementation.
; ==================================================================================================


; ==================================================================================================
; FindDialog implementation
; ==================================================================================================

IDD_DLG_FIND										equ 2000
IDC_BTN_FIND										equ 1
IDC_BTN_REPLACE									equ 1002
IDC_BTN_REPLACEALL							equ 1003
IDC_BTN_HELP										equ 1004
IDC_BTN_CANCEL									equ 2
IDC_STC_FIND										equ 1006
IDC_CBO_FIND										equ 1007
IDC_STC_REPLACE									equ 1008
IDC_CBO_REPLACE									equ 1009
IDC_GRP_SCOPE										equ 1010
IDC_RBN_CURRFILE								equ 1011
IDC_RBN_OPENFILES								equ 1012
IDC_RBN_PROJFILES								equ 1013
IDC_RBN_ALLFILES								equ 1014
IDC_GRP_OPTIONS									equ 1015
IDC_CHK_MATCHCASE								equ 1016
IDC_CHK_WHOLEWORD								equ 1017
IDC_CHK_IGNORESPACE							equ 1018
IDC_CHK_USEREGEX								equ 1019
IDC_GRP_DIRECTION								equ 1020
IDC_RBN_DOWN										equ 1021
IDC_RBN_UP											equ 1022
IDC_RBN_ALL											equ 1023
IDC_CHK_WRAPAROUND							equ 1024

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
; Arguments:  None.
; Return:     Nothing.

FindInOpenFile proc uses xdi hChildWnd:HWND, pSelf:POINTER
  SetObject xsi, FindDialog
  mov xdi, $invoke(SendMessage, hChildWnd, WM_GETOBJECTINSTANCE, 0, 0)
  invoke GetObjectID, xdi
  .if eax == ADE_EditorID
    OCall xdi::Editor.FindFrom, [xsi].pFindString, addr [xsi].dLineNumber, addr [xsi].dCharIndex
  .endif
  ReleaseObject
  ret
FindInOpenFile endp

Method FindDialog.Find, uses xbx xdi xsi
  local pFindString:PSTRING
  
  SetObject xsi
  invoke StrNew, $OfsCStr("Method")
  mov [xsi].pFindString, xax
  
  .if [xsi].dScope == FDS_CURRENT_FILE
    mov xax, [xsi].pOwner
    mov xbx, [xax].$Obj(MdiApp).pClientWnd
    invoke SendMessage, [xbx].$Obj(ClientWnd).hWnd, WM_MDIGETACTIVE, 0, 0
    .if xax != 0
      invoke FindInOpenFile, xax, xsi
      DbgDec eax
    .endif
    
  .elseif [xsi].dScope == FDS_OPEN_FILES
    mov xax, [xsi].pOwner
    mov xbx, [xax].$Obj(MdiApp).pClientWnd
    invoke EnumChildWindows, [xbx].$Obj(ClientWnd).hWnd, offset FindInOpenFile, xsi
  
  .elseif [xsi].dScope == FDS_PROJECT_FILES
  
  .elseif [xsi].dScope == FDS_ALL_FILES
  
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     FindDialog.Init
; Purpose:    Initialaize a FindDialog object.
; Arguments:  Arg1: -> Owner object (Application).
; Return:     Nothing.

Method FindDialog.Init, uses xbx xsi, pOwner:POINTER
  SetObject xsi
  mov xax, pOwner
  ACall xsi.Init, pOwner, [xax].$Obj(MdiApp).hWnd, 2000, [xax].$Obj(MdiApp).hActiveMlsDlg

  OCall [xsi].FindStrings::%StrCollection.Init, xsi, 20, 20, COL_MAX_CAPACITY
  OCall [xsi].ReplaceStrings::%StrCollection.Init, xsi, 20, 20, COL_MAX_CAPACITY
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     FindDialog.OnCommand
; Purpose:    Event procedure for WM_COMMAND message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method FindDialog.OnCommand, uses xsi, wParam:WPARAM, lParam:LPARAM
  ANNOTATION use:wParam lParam

  SetObject xsi
  LoWord(wParam)
  .if ax == IDOK                                        ;Find Button
    OCall xsi.CtlsGet
    OCall xsi.Find
  .elseif ax == IDC_BTN_REPLACE
    OCall xsi.CtlsGet
;    OCall xsi.Replace
  .elseif ax == IDC_BTN_REPLACEALL
    OCall xsi.CtlsGet
;    OCall xsi.ReplaceAll
  .elseif ax == IDC_BTN_HELP
;    OCall xsi.Help
  .elseif ax == IDCANCEL
    OCall xsi.DestroyDialog, wParam
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
