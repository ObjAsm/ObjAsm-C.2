; ==================================================================================================
; Title:      ADE_FindDialog.inc
; Author:     G. Friedrich
; Version:    See ADE.asm
; Purpose:    ObjAsm Find dialog implementation.
; ==================================================================================================


; ==================================================================================================
; FindDialog implementation
; ==================================================================================================

IDD_DLG_FIND                    equ 2000
IDC_BTN_FIND                    equ 1
IDC_BTN_REPLACE                 equ 1002
IDC_BTN_REPLACEALL              equ 1003
IDC_BTN_HELP                    equ 1004
IDC_BTN_CANCEL                  equ 2
IDC_STC_FIND                    equ 1006
IDC_CBO_FIND                    equ 1007
IDC_STC_REPLACE                 equ 1008
IDC_CBO_REPLACE                 equ 1009
IDC_GRP_SCOPE                   equ 1010
IDC_RBN_CURRFILE                equ 1011
IDC_RBN_OPENFILES               equ 1012
IDC_RBN_PROJFILES               equ 1013
IDC_RBN_ALLFILES                equ 1014
IDC_GRP_OPTIONS                 equ 1015
IDC_CHK_MATCHCASE               equ 1016
IDC_CHK_WHOLEWORD               equ 1017
;IDC_CHK_IGNORESPACE             equ 1018
IDC_CHK_USEREGEX                equ 1019
IDC_GRP_DIRECTION               equ 1020
IDC_RBN_DOWN                    equ 1021
IDC_RBN_UP                      equ 1022
IDC_RBN_ALL                     equ 1023
;IDC_CHK_WRAPAROUND              equ 1024

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

; --------------------------------------------------------------------------------------------------
; Method:     FindDialog.CtlsGet
; Purpose:    Read the setting of all controls.
; Arguments:  None.
; Return:     Nothing.

Method FindDialog.CtlsGet, uses xbx xdi xsi
  local hComboBox:HWND

;  DbgText "FindDialog.CtlsGet"
  SetObject xsi
  OCall [xsi].FindStrings::%StrCollection.DisposeAll
  mov hComboBox, $invoke(GetDlgItem, [xsi].hWnd, IDC_CBO_FIND)
  mov ebx, $32($invoke(SendMessage, hComboBox, CB_GETCOUNT, 0, 0))
  xor edi, edi
  test ebx, ebx
  .while !ZERO?
    invoke SendMessage, hComboBox, CB_GETLBTEXTLEN, edi, 0
    invoke StrAlloc, eax
    OCall [xsi].FindStrings::%StrCollection.Insert, xax
    invoke SendMessage, hComboBox, CB_GETLBTEXT, edi, xax
    inc edi
    dec ebx
  .endw

  OCall [xsi].FindStrings::%StrCollection.DisposeAll
  mov hComboBox, $invoke(GetDlgItem, [xsi].hWnd, IDC_CBO_REPLACE)
  mov ebx, $32($invoke(SendMessage, hComboBox, CB_GETCOUNT, 0, 0))
  xor edi, edi
  test ebx, ebx
  .while !ZERO?
    invoke SendMessage, hComboBox, CB_GETLBTEXTLEN, edi, 0
    invoke StrAlloc, eax
    OCall [xsi].ReplStrings::%StrCollection.Insert, xax
    invoke SendMessage, hComboBox, CB_GETLBTEXT, edi, xax
    inc edi
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
  mov [xsi].Choices.dScope, ebx

  xor ebx, ebx
  invoke IsDlgButtonChecked, [xsi].hWnd, IDC_CHK_MATCHCASE
  .if eax == BST_CHECKED
    BitSet ebx, FDO_MATCH_CASE
  .endif
  invoke IsDlgButtonChecked, [xsi].hWnd, IDC_CHK_WHOLEWORD
  .if eax == BST_CHECKED
    BitSet ebx, FDO_WHOLE_WORD
  .endif
  invoke IsDlgButtonChecked, [xsi].hWnd, IDC_CHK_USEREGEX
  .if eax == BST_CHECKED
    mov ebx, FDO_USE_REGEX
  .endif
  mov [xsi].Choices.dOptions, ebx

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
  mov [xsi].Choices.dDirection, ebx
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     FindDialog.CtlsSet
; Purpose:    Set the controls of the setup dialog.
; Arguments:  None.
; Return:     eax = this procedure should return TRUE to direct Windows to set the keyboard focus to
;                   the control specified by hwndFocus. Otherwise, it should return FALSE to prevent
;                   Windows from setting the default keyboard focus.

Method FindDialog.CtlsSet, uses xbx xsi
  local hComboBox:HWND

;  DbgText "FindDialog.CtlsSet"
  SetObject xsi

  ;Fill the comboboxes with initial values
  mov hComboBox, $invoke(GetDlgItem, [xsi].hWnd, IDC_CBO_FIND)
  invoke SendMessage, hComboBox, CB_RESETCONTENT, 0, 0
  .ColForEach [xsi].FindStrings, ebx
    invoke SendMessage, hComboBox, CB_ADDSTRING, 0, xax
  .ColNext

  mov hComboBox, $invoke(GetDlgItem, [xsi].hWnd, IDC_CBO_REPLACE)
  invoke SendMessage, hComboBox, CB_RESETCONTENT, 0, 0
  .ColForEach [xsi].ReplStrings, ebx
    invoke SendMessage, hComboBox, CB_ADDSTRING, 0, xax
  .ColNext

  ;Set the reamining controls
  mov eax, [xsi].Choices.dScope
  add eax, IDC_RBN_CURRFILE
  invoke CheckRadioButton, [xsi].hWnd, IDC_RBN_CURRFILE, IDC_RBN_ALLFILES, eax

  mov eax, BST_UNCHECKED
  .ifBitSet [xsi].Choices.dOptions, FDO_MATCH_CASE
    mov eax, BST_CHECKED
  .endif
  invoke CheckDlgButton, [xsi].hWnd, IDC_CHK_MATCHCASE, eax

  mov eax, BST_UNCHECKED
  .ifBitSet [xsi].Choices.dOptions, FDO_WHOLE_WORD
    mov eax, BST_CHECKED
  .endif
  invoke CheckDlgButton, [xsi].hWnd, IDC_CHK_WHOLEWORD, eax

  mov eax, BST_UNCHECKED
  .ifBitSet [xsi].Choices.dOptions, FDO_USE_REGEX
    mov eax, BST_CHECKED
  .endif
  invoke CheckDlgButton, [xsi].hWnd, IDC_CHK_USEREGEX, eax

  mov eax, [xsi].Choices.dDirection
  add eax, IDC_RBN_DOWN
  invoke CheckRadioButton, [xsi].hWnd, IDC_RBN_DOWN, IDC_RBN_ALL, eax

  mov eax, TRUE
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     FindDialog.Done
; Purpose:    Finalize the FindDialog object.
; Arguments:  None.
; Return:     Nothing.

Method FindDialog.Done, uses xsi
  SetObject xsi
  OCall [xsi].FindStrings::%StrCollection.Done
  OCall [xsi].ReplStrings::%StrCollection.Done
  OCall [xsi].EditorWndHandles::XWCollection.Done
  ACall xsi.Done
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     FindDialog.FindFirst
; Purpose:    Initialize search structures and perform the first search.
; Arguments:  Arg1: -> Editor.
;             Arg2: -> String to find.
; Return:     eax = TRUE if succeeded, otherwise FALSE.

Method FindDialog.FindFirst, uses xdi xsi, pEditor:$ObjPtr(Editor), pFindStr:PSTRING
  SetObject xsi
  mov xdi, pEditor
  .if [xsi].Choices.dScope == FDS_CURRENT_FILE
    ;Set SrchBeg
    .if [xsi].Choices.dDirection == FDD_ALL
      ;Start at the first editor line
      mov [xsi].SrchBeg.dLineIndex, 0
      mov [xsi].SrchBeg.dCharIndex, 0
      ;Set view
      mov xcx, [xdi].$Obj(Editor).pFocusedView
      .if xcx != NULL
        s2s [xcx].$Obj(EditorView).FirstVisChar, [xsi].SrchBeg, xax, xdx
      .endif
    .else
      .if [xdi].$Obj(Editor).SelectionRange.pBegSelInfo != NULL && \    ;Something selected?
          [xdi].$Obj(Editor).SelectionRange.pEndSelInfo != NULL
        ;Selection
        .if [xsi].Choices.dDirection == FDD_DOWN
          ;Use the selection begin
          mov xcx, [xdi].$Obj(Editor).SelectionRange.pBegSelInfo
          s2s [xsi].SrchBeg, LOCATION ptr [xcx], xdx, xax
        .else
          ;Use the selection end
          mov xcx, [xdi].$Obj(Editor).SelectionRange.pEndSelInfo
          s2s [xsi].SrchBeg, LOCATION ptr [xcx], xdx, xax
        .endif
      .else
        ;No selection => Use the current caret location
        mov xcx, [xdi].$Obj(Editor).pFocusedView
        s2s [xsi].SrchBeg, [xcx].$Obj(EditorView).CaretLocation, xdx, xax
      .endif
    .endif
    mov xcx, [xdi].$Obj(Editor).pFocusedView
    .if xcx != NULL
      s2s [xcx].$Obj(EditorView).CaretLocation, [xsi].SrchBeg, xax, xdx
    .endif

    ;Set SrchEnd
    .if [xsi].Choices.dDirection == FDD_DOWN || [xsi].Choices.dDirection == FDD_ALL
      mov [xsi].SrchEnd.dLineIndex, -1
      mov [xsi].SrchEnd.dCharIndex, -1
    .else                                               ;FDD_UP
      mov [xsi].SrchEnd.dCharIndex, 0                   ;Get the first editor line
      mov [xsi].SrchEnd.dLineIndex, 0
    .endif
  .else
    ;Set SrchBeg
    mov [xsi].SrchBeg.dLineIndex, 0
    mov [xsi].SrchBeg.dCharIndex, 0
    ;Set SrchEnd
    mov [xsi].SrchEnd.dLineIndex, -1
    mov [xsi].SrchEnd.dCharIndex, -1
  .endif

  OCall xdi::Editor.FindStr, pFindStr, addr [xsi].SrchBeg, addr [xsi].SrchEnd, addr [xsi].Choices
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     FindDialog.FindNext
; Purpose:    Perform successiv search.
; Arguments:  Arg1: -> Editor.
;             Arg2: -> String to find.
; Return:     eax = TRUE if succeeded, otherwise FALSE.

Method FindDialog.FindNext, uses xsi, pEditor:$ObjPtr(Editor), pFindStr:PSTRING
  SetObject xsi
  mov xcx, pEditor
  OCall xcx::Editor.FindStr, pFindStr, addr [xsi].SrchBeg, addr [xsi].SrchEnd, addr [xsi].Choices
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     FindDialog.Find
; Purpose:    Do the search operation.
; Arguments:  Arg1: -> Active child window object.
; Return:     eax = TRUE if succeeded, otherwise FALSE.

CaptureEditorWndHandle proc uses xdi xsi hChildWnd:HWND, pSelf:POINTER
  SetObject xsi, FindDialog
  invoke SendMessage, hChildWnd, WM_GETOBJECTINSTANCE, 0, 0
  .if xax != NULL
    mov xdi, xax
    invoke GetObjectID, xdi
    .if eax == ADE_EditorID
      ;Store the window handle, the object instance may be destroyed at some point
      OCall [xsi].EditorWndHandles::XWCollection.Insert, hChildWnd
    .endif
  .endif
  ReleaseObject
  ret
CaptureEditorWndHandle endp

Method FindDialog.Find, uses xbx xdi xsi
  local cFindStr[2024]:CHR, hComboBox:HWND, dRetValue:DWORD

  SetObject xsi
  mov dRetValue, FALSE

  OCall xsi.CtlsGet
  ;Read the "Find" combobox
  mov hComboBox, $invoke(GetDlgItem, [xsi].hWnd, IDC_CBO_FIND)
  lea xbx, cFindStr
  invoke SendMessage, hComboBox, WM_GETTEXT, lengthof(cFindStr), xbx
  invoke SendMessage, hComboBox, CB_FINDSTRINGEXACT, -1, xbx
  .if eax == CB_ERR
    invoke SendMessage, hComboBox, CB_INSERTSTRING, 0, xbx
  .endif


  .if [xsi].Choices.dScope == FDS_CURRENT_FILE
    .if [xsi].dContinue == FALSE
      mov [xsi].hEditor, 0
      mov xax, [xsi].pOwner
      mov xcx, [xax].$Obj(MdiApp).pClientWnd
      invoke SendMessage, [xcx].$Obj(ClientWnd).hWnd, WM_MDIGETACTIVE, 0, 0
      mov xbx, xax
      invoke SendMessage, xax, WM_GETOBJECTINSTANCE, 0, 0
      .if xax != NULL
        mov xdi, xax
        invoke GetObjectID, xdi
        .if eax == ADE_EditorID
          mov [xsi].hEditor, xbx
        .endif
      .endif
    .else
      invoke SendMessage, [xsi].hEditor, WM_GETOBJECTINSTANCE, 0, 0
      mov xdi, xax
    .endif
    
    .if xdi != NULL
      .if [xsi].dContinue == FALSE
        OCall xsi.FindFirst, xdi, addr cFindStr
      .else
        OCall xsi.FindNext, xdi, addr cFindStr
      .endif
      mov [xsi].dContinue, eax
      mov dRetValue, eax
      .if eax != FALSE
        invoke RedrawWindow, [xdi].$Obj(Editor).hWnd, NULL, 0, RDW_INVALIDATE or RDW_UPDATENOW or RDW_ALLCHILDREN
        mov xax, [xsi].pOwner
        mov xcx, [xax].$Obj(MdiApp).pClientWnd
        invoke SendMessage, [xcx].$Obj(ClientWnd).hWnd, WM_MDIACTIVATE, [xdi].$Obj(Editor).hWnd, 0
        invoke GetDlgItem, [xsi].hWnd, IDC_BTN_REPLACE
        invoke EnableWindow, xax, [xsi].dContinue
      .endif
    .else
      mov [xsi].dContinue, FALSE
      mov dRetValue, FALSE
    .endif


  .elseif [xsi].Choices.dScope == FDS_OPEN_FILES
    .if [xsi].dContinue == FALSE
      ;Gatter all open editors in EditorWndHandles collection
      mov xax, [xsi].pOwner
      mov xbx, [xax].$Obj(MdiApp).pClientWnd
      OCall [xsi].EditorWndHandles::XWCollection.DisposeAll
      invoke EnumChildWindows, [xbx].$Obj(ClientWnd).hWnd, offset CaptureEditorWndHandle, xsi
      mov [xsi].dContinueSameEditor, FALSE
    .endif

    .while TRUE
      mov eax, [xsi].EditorWndHandles.dCount
      .break .if eax == 0
      OCall [xsi].EditorWndHandles::XWCollection.ItemAt, 0  ;Get the first Editor in the collection
      mov [xsi].hEditor, xax                            ;Used in replace command
      invoke SendMessage, xax, WM_GETOBJECTINSTANCE, 0, 0
      .if xax != NULL
        mov xdi, xax
        .if [xsi].dContinueSameEditor == FALSE
          OCall xsi.FindFirst, xdi, addr cFindStr
        .else
          OCall xsi.FindNext, xdi, addr cFindStr
        .endif
        mov [xsi].dContinueSameEditor, eax

        .if eax == FALSE
          ;Nothing found => continue with the next Editor
          invoke RedrawWindow, [xdi].$Obj(Editor).hWnd, NULL, 0, RDW_INVALIDATE or RDW_UPDATENOW or RDW_ALLCHILDREN
          OCall [xsi].EditorWndHandles::XWCollection.DeleteAt, 0
          .continue
        .endif
      .else
        OCall [xsi].EditorWndHandles::XWCollection.DeleteAt, 0  ;Not exist => remove it
        .continue
      .endif
      mov eax, TRUE
      .break
    .endw
    mov [xsi].dContinue, eax
    mov dRetValue, eax

    .if eax != FALSE
      mov xcx, [xdi].$Obj(Editor).pOwner
      invoke RedrawWindow, [xdi].$Obj(Editor).hWnd, NULL, 0, RDW_INVALIDATE or RDW_UPDATENOW or RDW_ALLCHILDREN
      mov xax, [xsi].pOwner
      mov xcx, [xax].$Obj(MdiApp).pClientWnd
      invoke SendMessage, [xcx].$Obj(ClientWnd).hWnd, WM_MDIACTIVATE, [xdi].$Obj(Editor).hWnd, 0
      invoke GetDlgItem, [xsi].hWnd, IDC_BTN_REPLACE
      invoke EnableWindow, xax, [xsi].dContinue
    .endif


  .elseif [xsi].Choices.dScope == FDS_PROJECT_FILES


  .elseif [xsi].Choices.dScope == FDS_ALL_FILES


  .endif
  mov eax, dRetValue
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     FindDialog.Help
; Purpose:    Provide help for this dialog.
; Arguments:  None.
; Return:     Nothing.

Method FindDialog.Help, uses xsi
  SetObject xsi
  invoke MessageBox, [xsi].hWnd, $OfsCStr("Help me please..."), $OfsCStr("Help"), MB_OK or MB_ICONINFORMATION
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     FindDialog.Init
; Purpose:    Initialaize a FindDialog object.
; Arguments:  Arg1: -> Owner object (Application).
; Return:     Nothing.

.data
align ALIGN_DATA
DlgChildrenInfo label DL_HEADER
DL_HEADER     {DLF_LOAD_MINMAX or DLF_LIMIT_MIN or DLF_LIMIT_MAX_Y or DLF_ADD_GRIPPER}
DL_CHILD_INFO {{000, 000, 000, 000}}      ;Search Label
DL_CHILD_INFO {{000, 000, 100, 000}}      ;Search Combo
DL_CHILD_INFO {{000, 000, 000, 000}}      ;Replace Label
DL_CHILD_INFO {{000, 000, 100, 000}}      ;Replace Combo
DL_CHILD_INFO {{000, 000, 000, 100}}      ;Group Scope
DL_CHILD_INFO {{000, 000, 000, 000}}      ;Radio button Curr File
DL_CHILD_INFO {{000, 000, 000, 000}}      ;Radio button Open Files
DL_CHILD_INFO {{000, 000, 000, 000}}      ;Radio button Proj Files
DL_CHILD_INFO {{000, 000, 000, 000}}      ;Radio button All Files
DL_CHILD_INFO {{000, 000, 000, 100}}      ;Group Options
DL_CHILD_INFO {{000, 000, 000, 000}}      ;Checkbox Match Case
DL_CHILD_INFO {{000, 000, 000, 000}}      ;Checkbox Whole Word
DL_CHILD_INFO {{000, 000, 000, 000}}      ;Checkbox Use RegEx
DL_CHILD_INFO {{000, 000, 000, 100}}      ;Group Direction
DL_CHILD_INFO {{000, 000, 000, 000}}      ;Radio button Down
DL_CHILD_INFO {{000, 000, 000, 000}}      ;Radio button Up
DL_CHILD_INFO {{000, 000, 000, 000}}      ;Radio button All
DL_CHILD_INFO {{100, 000, 000, 000}}      ;Search button
DL_CHILD_INFO {{100, 000, 000, 000}}      ;Replace button
DL_CHILD_INFO {{100, 000, 000, 000}}      ;Replace All button
DL_CHILD_INFO {{100, 100, 000, 000}}      ;Help button
DL_CHILD_INFO {{100, 100, 000, 000}}      ;Cancel button

.code
Method FindDialog.Init, uses xsi, pOwner:POINTER
  SetObject xsi
  mov xax, pOwner
  ACall xsi.Init, pOwner, [xax].$Obj(MdiApp).hWnd, 2000, addr [xax].$Obj(MdiApp).hActiveMlsDlg

  c2m [xsi].pDynamicLayout, offset DlgChildrenInfo, xcx

  OCall [xsi].FindStrings::%StrCollection.Init, xsi, 20, 20, COL_MAX_CAPACITY
  OCall [xsi].ReplStrings::%StrCollection.Init, xsi, 20, 20, COL_MAX_CAPACITY
  OCall [xsi].EditorWndHandles::XWCollection.Init, xsi, 20, 20, COL_MAX_CAPACITY
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     FindDialog.OnActivate
; Purpose:    Event procedure for WM_ACTIVATE message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method FindDialog.OnActivate, uses xbx xdi xsi, wParam:WPARAM, lParam:LPARAM
  local cBuffer[2024]:CHR, hComboBox:HWND

  ANNOTATION use:wParam lParam

  SetObject xsi
  ACall xsi.OnActivate, wParam, lParam
  mov xax, wParam
  .if ax != WA_INACTIVE                                 ;If any form of activation

    invoke GetDlgItem, [xsi].hWnd, IDC_BTN_REPLACE
    invoke EnableWindow, xax, [xsi].dContinue

    mov hComboBox, $invoke(GetDlgItem, [xsi].hWnd, IDC_CBO_FIND)

    ;Find the active editor
    mov xax, [xsi].pOwner
    mov xcx, [xax].$Obj(MdiApp).pClientWnd
    invoke SendMessage, [xcx].$Obj(ClientWnd).hWnd, WM_MDIGETACTIVE, 0, 0
    invoke SendMessage, xax, WM_GETOBJECTINSTANCE, 0, 0
    .if xax != NULL
      mov xbx, xax
      invoke GetObjectID, xbx
      .if eax == ADE_EditorID
        ;If something is selected, write it to the ComboBox
        mov xax, [xbx].$Obj(Editor).SelectionRange.SELRANGE.pBegSelInfo
        mov xcx, [xbx].$Obj(Editor).SelectionRange.SELRANGE.pEndSelInfo
        .if xax != NULL && xcx != NULL
          mov edx, [xax].LOCATION.dLineIndex
          ;Only if the selection is on the same line!
          .if edx == [xcx].LOCATION.dLineIndex
            .if edx < [xbx].$Obj(Editor).Lines.dCount
              OCall [xbx].$Obj(Editor).Lines::Collection.ItemAt, edx
              mov xdx, [xax].$Obj(EditorLine).pBuffer
              mov xcx, [xbx].$Obj(Editor).SelectionRange.pBegSelInfo
              mov edi, [xcx].LOCATION.dCharIndex
              lea xdx, [xdx + xdi*sizeof(CHR)]          ;xdx -> Selection begin
              mov xcx, [xbx].$Obj(Editor).SelectionRange.pEndSelInfo
              mov ebx, [xax].$Obj(EditorLine).dLength
              mov eax, [xcx].LOCATION.dCharIndex
              .if eax == -1
                mov eax, ebx
              .endif
              sub eax, edi                              ;eax = char count
              invoke StrCCopy, addr cBuffer, xdx, eax
              invoke SendMessage, hComboBox, WM_SETTEXT, 0, addr cBuffer
            .endif
          .endif
        .endif
      .endif
    .endif
    invoke SendMessage, hComboBox, CB_SETEDITSEL, 0, 0FFFF0000h   ;Select complete content
    invoke SetFocus, hComboBox                          ;Always to focus on the ComboBox
  .endif
  xor eax, eax
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     FindDialog.OnCommand
; Purpose:    Event procedure for WM_COMMAND message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method FindDialog.OnCommand, uses xbx xdi xsi, wParam:WPARAM, lParam:LPARAM
  local cMessage[1024]:CHR

  ANNOTATION use:wParam lParam

  SetObject xsi
  LoWord(wParam)
  .if ax == IDC_BTN_HELP
    OCall xsi.Help
  .elseif ax == IDCANCEL
    mov [xsi].dContinue, FALSE
    invoke ShowWindow, [xsi].hWnd, SW_HIDE
  .elseif ax != IDOK && ax != IDC_BTN_REPLACE && ax != IDC_BTN_REPLACEALL
    ;Any change on dialog controls will prevent further processing.
    .if ax == IDC_CBO_FIND || ax == IDC_CBO_REPLACE
      mov xax, wParam
      shr eax, 16
      .if ax != CBN_SELCHANGE || ax != CBN_EDITCHANGE   ;Only this ComboBox messages will reset the search
        ExitMethod
      .endif
    .endif

    ;Manage the Direction radiobuttons according to the file Scope
    .if ax == IDC_RBN_CURRFILE
      invoke GetDlgItem, [xsi].hWnd, IDC_RBN_DOWN
      invoke EnableWindow, xax, TRUE
      invoke GetDlgItem, [xsi].hWnd, IDC_RBN_UP
      invoke EnableWindow, xax, TRUE
    .elseif ax == IDC_RBN_OPENFILES || ax == IDC_RBN_PROJFILES || ax == IDC_RBN_ALLFILES
      invoke GetDlgItem, [xsi].hWnd, IDC_RBN_DOWN
      invoke EnableWindow, xax, FALSE
      invoke GetDlgItem, [xsi].hWnd, IDC_RBN_UP
      invoke EnableWindow, xax, FALSE
      invoke CheckRadioButton, [xsi].hWnd, IDC_RBN_DOWN, IDC_RBN_ALL, IDC_RBN_ALL
    .endif

    mov [xsi].dContinue, FALSE
    invoke GetDlgItem, [xsi].hWnd, IDC_BTN_REPLACE
    invoke EnableWindow, xax, FALSE

  .else
    mov xax, [xsi].pOwner
    mov xcx, [xax].$Obj(MdiApp).pClientWnd
    invoke SendMessage, [xcx].$Obj(ClientWnd).hWnd, WM_MDIGETACTIVE, 0, 0
    invoke SendMessage, xax, WM_GETOBJECTINSTANCE, 0, 0
    .if xax != NULL
      mov xdi, xax                                      ;xdi -> Editor
      LoWord(wParam)
      .if ax == IDOK                                    ;Find Button
        OCall xsi.Find
        .if eax == FALSE
          invoke MessageBox, [xsi].hWnd, $OfsCStr("No matches found."), $OfsCStr("Find"), MB_OK or MB_ICONINFORMATION
        .endif

      .elseif ax == IDC_BTN_REPLACE
        OCall xsi.Replace
        .if eax == FALSE
          invoke MessageBox, [xsi].hWnd, $OfsCStr("No matches found."), $OfsCStr("Replace"), MB_OK or MB_ICONINFORMATION
        .endif

      .elseif ax == IDC_BTN_REPLACEALL
        OCall xsi.ReplaceAll
        .if eax == 0
          invoke MessageBox, [xsi].hWnd, $OfsCStr("No matches found."), $OfsCStr("Replace all"), MB_OK or MB_ICONINFORMATION
        .else
          lea xbx, cMessage
          WriteF xbx, "¦UD matches replaced.", eax
          invoke MessageBox, [xsi].hWnd, addr cMessage, $OfsCStr("Replace all"), MB_OK or MB_ICONINFORMATION
        .endif
      .endif
    .endif
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
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

; --------------------------------------------------------------------------------------------------
; Method:     FindDialog.Replace
; Purpose:    Replace the editor selection with the content of the replace combobox.
; Arguments:  None.
; Return:     eax = TRUE if succeeded, otherwise FALSE.

Method FindDialog.Replace, uses xbx xsi
  local cReplStr[2024]:CHR, hComboBox:HWND, dRetValue:DWORD, dNeedRedrawing:DWORD, dActionGroup:DWORD

  SetObject xsi
  mov dRetValue, FALSE

  OCall xsi.CtlsGet
  ;Read the "Replace" combobox
  mov hComboBox, $invoke(GetDlgItem, [xsi].hWnd, IDC_CBO_REPLACE)
  lea xbx, cReplStr
  invoke SendMessage, hComboBox, WM_GETTEXT, lengthof(cReplStr), xbx
  invoke SendMessage, hComboBox, CB_FINDSTRINGEXACT, -1, xbx
  .if eax == CB_ERR
    invoke SendMessage, hComboBox, CB_INSERTSTRING, 0, xbx
  .endif

  invoke SendMessage, [xsi].hEditor, WM_GETOBJECTINSTANCE, 0, 0
  .if xax != NULL
    mov xbx, xax
    mov dActionGroup, $32($OCall([xbx].$Obj(Editor).Actions::ActionCollection.GetNewActionGroup))
    OCall xbx::Editor.CreateSelAction, dActionGroup
    OCall xbx::Editor.SelectionReplace, addr cReplStr, dActionGroup
    mov dNeedRedrawing, eax
    .if eax == FALSE
      invoke MessageBox, [xsi].hWnd, $OfsCStr("Nothing selected."), $OfsCStr("Replace"), MB_OK or MB_ICONINFORMATION
    .endif
    OCall xsi.Find
    mov dRetValue, eax
    .if dNeedRedrawing != FALSE
      invoke RedrawWindow, [xbx].$Obj(Editor).hWnd, NULL, 0, RDW_INVALIDATE or RDW_UPDATENOW or RDW_ALLCHILDREN
    .endif
  .endif
  mov eax, dRetValue
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     FindDialog.ReplaceAll
; Purpose:    Replace all occurrences with the content of the replace combobox.
; Arguments:  None.
; Return:     eax = TRUE if succeeded, otherwise FALSE.

Method FindDialog.ReplaceAll, uses xbx xdi xsi
  local cFindStr[2024]:CHR, cReplStr[2024]:CHR, hComboBox:HWND, dActionGroup:DWORD
  local dReplCounter:DWORD, dTotalReplCounter:DWORD

  ANNOTATION use:pChildWndObject

  SetObject xsi

  ;Read the Find combobox
  mov hComboBox, $invoke(GetDlgItem, [xsi].hWnd, IDC_CBO_FIND)
  lea xbx, cFindStr
  invoke SendMessage, hComboBox, WM_GETTEXT, lengthof(cFindStr), xbx
  invoke SendMessage, hComboBox, CB_FINDSTRINGEXACT, -1, xbx
  .if eax == CB_ERR
    invoke SendMessage, hComboBox, CB_INSERTSTRING, 0, xbx
  .endif

  ;Read the Replace combobox
  mov hComboBox, $invoke(GetDlgItem, [xsi].hWnd, IDC_CBO_REPLACE)
  lea xbx, cReplStr
  invoke SendMessage, hComboBox, WM_GETTEXT, lengthof(cReplStr), xbx
  invoke SendMessage, hComboBox, CB_FINDSTRINGEXACT, -1, xbx
  .if eax == CB_ERR
    invoke SendMessage, hComboBox, CB_INSERTSTRING, 0, xbx
  .endif

  OCall xsi.CtlsGet

  .if [xsi].Choices.dScope == FDS_CURRENT_FILE
    mov xax, [xsi].pOwner
    mov xcx, [xax].$Obj(MdiApp).pClientWnd
    invoke SendMessage, [xcx].$Obj(ClientWnd).hWnd, WM_MDIGETACTIVE, 0, 0
    invoke SendMessage, xax, WM_GETOBJECTINSTANCE, 0, 0
    .if xax != NULL
      mov xbx, xax
      mov dTotalReplCounter, 0
      invoke GetObjectID, xbx
      .if eax == ADE_EditorID
        OCall xsi.FindFirst, xbx, addr cFindStr
        .if eax != FALSE
          mov dActionGroup, $32($OCall([xbx].$Obj(Editor).Actions::ActionCollection.GetNewActionGroup))
          OCall xbx::Editor.CreateSelAction, dActionGroup
          OCall xbx::Editor.SelectionReplace, addr cReplStr, dActionGroup
          add dTotalReplCounter, eax
          .while TRUE
            OCall xsi.FindNext, xbx, addr cFindStr
            .break .if eax == FALSE
            OCall xbx::Editor.SelectionReplace, addr cReplStr, dActionGroup
            add dTotalReplCounter, eax
          .endw
        .endif
      .endif
      .if dTotalReplCounter != 0
        invoke RedrawWindow, [xbx].$Obj(Editor).hWnd, NULL, 0, RDW_INVALIDATE or RDW_UPDATENOW or RDW_ALLCHILDREN
      .endif
      mov xax, [xsi].pOwner
      mov xcx, [xax].$Obj(MdiApp).pClientWnd
      invoke SendMessage, [xcx].$Obj(ClientWnd).hWnd, WM_MDIACTIVATE, [xbx].$Obj(Editor).hWnd, 0
      invoke GetDlgItem, [xsi].hWnd, IDC_BTN_REPLACE
      invoke EnableWindow, xax, FALSE
    .endif

  .elseif [xsi].Choices.dScope == FDS_OPEN_FILES
    mov xax, [xsi].pOwner
    mov xbx, [xax].$Obj(MdiApp).pClientWnd
    OCall [xsi].EditorWndHandles::XWCollection.DisposeAll
    invoke EnumChildWindows, [xbx].$Obj(ClientWnd).hWnd, offset CaptureEditorWndHandle, xsi
    mov dTotalReplCounter, 0

    .while TRUE
      .break .if [xsi].EditorWndHandles.dCount == 0
      OCall [xsi].EditorWndHandles::XWCollection.ItemAt, 0   ;Get the first Editor in the collection
      invoke SendMessage, xax, WM_GETOBJECTINSTANCE, 0, 0
      .if xax != NULL
        mov xbx, xax
        mov dReplCounter, 0
        invoke GetObjectID, xbx
        .if eax == ADE_EditorID
          OCall xsi.FindFirst, xbx, addr cFindStr
          .if eax != FALSE
            mov dActionGroup, $32($OCall([xbx].$Obj(Editor).Actions::ActionCollection.GetNewActionGroup))
            OCall xbx::Editor.CreateSelAction, dActionGroup
            OCall xbx::Editor.SelectionReplace, addr cReplStr, dActionGroup
            add dReplCounter, eax
            .while TRUE
              OCall xsi.FindNext, xbx, addr cFindStr
              .break .if eax == FALSE
              OCall xbx::Editor.SelectionReplace, addr cReplStr, dActionGroup
              add dReplCounter, eax
            .endw
          .endif
        .endif
        .if dReplCounter != 0
          invoke RedrawWindow, [xbx].$Obj(Editor).hWnd, NULL, 0, RDW_INVALIDATE or RDW_UPDATENOW or RDW_ALLCHILDREN
        .endif
      .endif
      mov eax, dReplCounter
      add dTotalReplCounter, eax
      OCall [xsi].EditorWndHandles::XWCollection.DisposeAt, 0
      mov xax, [xsi].pOwner
      mov xcx, [xax].$Obj(MdiApp).pClientWnd
      invoke SendMessage, [xcx].$Obj(ClientWnd).hWnd, WM_MDIACTIVATE, [xbx].$Obj(Editor).hWnd, 0
    .endw
    invoke GetDlgItem, [xsi].hWnd, IDC_BTN_REPLACE
    invoke EnableWindow, xax, FALSE
        

  .elseif [xsi].Choices.dScope == FDS_PROJECT_FILES

  .elseif [xsi].Choices.dScope == FDS_ALL_FILES

  .endif
  mov eax, dTotalReplCounter
MethodEnd
