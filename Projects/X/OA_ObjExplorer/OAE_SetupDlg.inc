; ==================================================================================================
; Title:      OAE_SetupDlg.inc
; Author:     G. Friedrich
; Version:    Check OA_ObjExplorer.asm
; Purpose:    SetupDlg implementation for OA_ObjExplorer.
; ==================================================================================================
;

;##\

SetCtrlText macro ControlID, TextID
  lea edx, [ebx + TextID]
  invoke LoadString, hInstance, edx, xdi, lengthof(cBuffer) - 1
  invoke SetDlgItemText, [xsi].hWnd, ControlID, xdi
endm

; --------------------------------------------------------------------------------------------------
; Method:     SetupDlg.CtlsGet
; Purpose:    Reads the setting of all controls.
; Arguments:  None.
; Return:     Nothing.

Method SetupDlg.CtlsGet, uses xbx xdi xsi
  local hWnd:HWND

  SetObject xsi
  mov xdi, [xsi].pOwner
  invoke StrDispose, [xdi].$Obj(Application).pViewerApp
  mov hWnd, $invoke(GetDlgItem, [xsi].hWnd, IDC_SETUP_VIEWER_EDIT)
  mov ebx, $32($invoke(GetWindowTextLength, xax))
  mov [xdi].$Obj(Application).pViewerApp, $invoke(StrAlloc, ebx)
  inc ebx
  invoke GetWindowText, hWnd, xax, ebx

  invoke IsDlgButtonChecked, [xsi].hWnd, IDC_SETUP_PROP_CHK_MTD
  mov [xdi].$Obj(Application).dShowRedefMtds, eax
  invoke IsDlgButtonChecked, [xsi].hWnd, IDC_SETUP_PROP_CHK_VAR
  mov [xdi].$Obj(Application).dShowRedefVars, eax

  mov eax, TRUE
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     SetupDlg.CtlsSet
; Purpose:    Sets the controls of the setup dialog.
; Arguments:  None.
; Return:     eax = TRUE to direct Windows to set the keyboard focus. Otherwise FALSE to prevent
;                   Windows from setting the default keyboard focus.

Method SetupDlg.CtlsSet, uses xbx xdi xsi
  local cBuffer[1024]:CHR

  SetObject xsi

  ;Set caption and control strings
  mov xcx, [xsi].pOwner
  mov ebx, [xcx].$Obj(Application).dLanguage
  lea xdi, cBuffer

  lea edx, [ebx + IDS_SETUP_CAPTION]
  invoke LoadString, hInstance, edx, xdi, lengthof(cBuffer) - 1
  invoke SetWindowText, [xsi].hWnd, xdi
  SetCtrlText IDC_SETUP_VIEWER_GRP,   IDS_SETUP_VIEWER_GRP
  SetCtrlText IDC_SETUP_VIEWER_STC,   IDS_SETUP_VIEWER_APP
  SetCtrlText IDC_SETUP_VIEWER_TEXT,  IDS_SETUP_VIEWER_TEXT
  SetCtrlText IDC_SETUP_PROP_GRP,     IDS_SETUP_PROP_GRP
  SetCtrlText IDC_SETUP_PROP_CHK_MTD, IDS_SETUP_PROP_CHK_MTD
  SetCtrlText IDC_SETUP_PROP_CHK_VAR, IDS_SETUP_PROP_CHK_VAR
  SetCtrlText IDOK, IDS_SETUP_OK
  SetCtrlText IDCANCEL, IDS_SETUP_CANCEL

  ;Set control values
  mov xdi, [xsi].pOwner
  assume xdi:$ObjPtr(Application)
  invoke SetDlgItemText, [xsi].hWnd, IDC_SETUP_VIEWER_EDIT,  [xdi].pViewerApp
  invoke CheckDlgButton, [xsi].hWnd, IDC_SETUP_PROP_CHK_MTD, [xdi].dShowRedefMtds
  invoke CheckDlgButton, [xsi].hWnd, IDC_SETUP_PROP_CHK_VAR, [xdi].dShowRedefVars
  assume xdi:nothing

  mov eax, TRUE
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     SetupDlg.Init
; Purpose:    Initialaizes a dialog.
; Arguments:  Arg1: -> Owner object.
;             Arg2: -> Parent window handle.
; Return:     Nothing.

Method SetupDlg.Init,, pOwner:POINTER, hParentWnd:HANDLE
  SetObject xcx
  ACall xcx.Init, pOwner, hParentWnd, IDD_SETUP_DLG
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     SetupDlg.OnCommand
; Purpose:    Event procedure for WM_COMMAND message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     Nothing.

Method SetupDlg.OnCommand, uses xdi xsi, wParam:WPARAM, lParam:LPARAM
  local OpenFileName:OPENFILENAME, cInitDir[MAX_PATH]:CHR, cFileName[MAX_PATH]:CHR
  local cBuffer[1024]:CHR

  SetObject xsi
  LoWord(wParam)
  .if ax == IDOK
    OCall xsi.CtlsGet
    OCall xsi.DestroyDialog, wParam
  .elseif ax == IDCANCEL
    OCall xsi.DestroyDialog, wParam
  .elseif ax == IDC_SETUP_VIEWER_BTN
    lea xdi, cInitDir
    invoke GetDlgItemText, [xsi].hWnd, IDC_SETUP_VIEWER_EDIT, xdi, lengthof(cInitDir) - 1

    mov OpenFileName.lStructSize, sizeof OPENFILENAME
    m2m OpenFileName.hwndOwner, [xsi].hWnd, xax
    m2m OpenFileName.hInstance, hInstance, xax
    mov OpenFileName.lpstrFilter, NULL
    mov OpenFileName.lpstrCustomFilter, NULL
    mov OpenFileName.nMaxCustFilter, 0
    mov OpenFileName.nFilterIndex, 0
    lea xax, cFileName
    mov CHR ptr [xax], 0
    mov OpenFileName.lpstrFile, xax
    mov OpenFileName.nMaxFile, lengthof(cFileName) - 1
    mov OpenFileName.lpstrFileTitle, NULL
    mov OpenFileName.nMaxFileTitle, 0
    lea xax, cInitDir
    mov OpenFileName.lpstrInitialDir, xax
    mov xax, [xsi].pOwner
    mov ecx, [xax].$Obj(Application).dLanguage
    lea edx, [ecx + IDS_SELECT]
    lea xax, cBuffer
    mov OpenFileName.lpstrTitle, xax
    invoke LoadString, hInstance, edx, xax, lengthof(cBuffer) - 1
    mov OpenFileName.lpstrDefExt, NULL
    mov OpenFileName.Flags, OFN_EXPLORER or OFN_FILEMUSTEXIST or OFN_LONGNAMES or OFN_HIDEREADONLY
    invoke GetOpenFileName, addr OpenFileName

    .if eax != 0
      invoke SetDlgItemText, [xsi].hWnd, IDC_SETUP_VIEWER_EDIT, addr cFileName
    .endif
    xor eax, eax
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     SetupDlg.OnDestroy
; Purpose:    Event procedure for WM_DESTROY message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     Nothing.

Method SetupDlg.OnDestroy, uses xsi, wParam:WPARAM, lParam:LPARAM
  SetObject xsi
  invoke SetWindowLongPtr, [xsi].hWnd, DWLP_USER, NULL
MethodEnd


;##/

