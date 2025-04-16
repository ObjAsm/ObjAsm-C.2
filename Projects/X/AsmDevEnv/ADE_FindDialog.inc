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

Method FindDialog.CtlsSet, uses xbx xdi xsi
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
  ACall xsi.Done
MethodEnd

; --------------------------------------------------------------------------------------------------
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
;      OCall xdi::Editor.FindFrom, [xsi].pFindStr, addr [xsi].dLineNumber, addr [xsi].dCharIndex
;    .endif
;  .endif
;  ReleaseObject
;  ret
;FindInOpenFile endp

Method FindDialog.Find, uses xbx xdi xsi, pChildWndObject:POINTER
  local cFindStr[2024]:CHR, hComboBox:HWND, dRet:DWORD

  SetObject xsi
  mov dRet, FALSE

  ;Read the Find combobox
  mov hComboBox, $invoke(GetDlgItem, [xsi].hWnd, IDC_CBO_FIND)
  lea xbx, cFindStr
  invoke SendMessage, hComboBox, WM_GETTEXT, lengthof(cFindStr), xbx
  invoke SendMessage, hComboBox, CB_FINDSTRINGEXACT, -1, xbx
  .if eax == CB_ERR
    invoke SendMessage, hComboBox, CB_INSERTSTRING, 0, xbx
  .endif

  OCall xsi.CtlsGet

  .if [xsi].Choices.dScope == FDS_CURRENT_FILE
    invoke GetObjectID, pChildWndObject
    .if eax == ADE_EditorID

      mov xax, pChildWndObject
      ;Get the start LOCATION
      .if [xsi].dContinue == FALSE
        ;Set SrchBeg
        .if [xsi].Choices.dDirection == FDD_ALL
          ;Get the first editor line
          mov xdx, [xax].$Obj(Editor).LinesHead.pFirstMember
          lea xcx, [xdx - offset $Obj(EditorLine).LineLink]   ;xax -> last EditorLine
          mov [xsi].SrchBeg.pEditorLine, xcx
          mov [xsi].SrchBeg.dLineNumber, 1
          mov [xsi].SrchBeg.dCharIndex, 0
          mov xcx, [xax].$Obj(Editor).pFocusedView
          s2s [xcx].$Obj(EditorView).CaretLocation, [xsi].SrchBeg, xmm0, xmm1, xmm2, xmm3, xdx
          s2s [xcx].$Obj(EditorView).FirstVisChar, [xsi].SrchBeg, xmm0, xmm1, xmm2, xmm3, xdx
          mov [xcx].$Obj(EditorView).sdCaretVisLineOffset, 0
        .else
          .if [xax].$Obj(Editor).SelectionRange.pBegSelInfo != NULL
            .if [xsi].Choices.dDirection == FDD_DOWN
              ;Use the selection begin
              mov xcx, [xax].$Obj(Editor).SelectionRange.pBegSelInfo
              s2s [xsi].SrchBeg, LOCATION ptr [xcx], xmm0, xmm1, xmm2, xmm3, xdx
            .else
              ;Use the selection end
              mov xcx, [xax].$Obj(Editor).SelectionRange.pEndSelInfo
              s2s [xsi].SrchBeg, LOCATION ptr [xcx], xmm0, xmm1, xmm2, xmm3, xdx
            .endif
          .else
            ;Use the current caret location
            mov xcx, [xax].$Obj(Editor).pFocusedView
            s2s [xsi].SrchBeg, [xcx].$Obj(EditorView).CaretLocation, xmm0, xmm1, xmm2, xmm3, xdx
          .endif
        .endif
  
        ;Set SrchEnd
        .if [xsi].Choices.dDirection == FDD_DOWN || [xsi].Choices.dDirection == FDD_ALL  
          ;Get the last editor line
          mov xdx, [xax].$Obj(Editor).LinesHead.pLastMember
          lea xax, [xdx - offset $Obj(EditorLine).LineLink]   ;xax -> last EditorLine
          mov [xsi].SrchEnd.pEditorLine, xax
          mov ecx, [xax].$Obj(EditorLine).dLength
          mov [xsi].SrchEnd.dCharIndex, ecx
          mov [xsi].SrchEnd.dLineNumber, 0                ;Unknown
        .else                                             ;[xsi].Choices.dDirection == FDD_UP
          ;Get the first editor line
          mov xdx, [xax].$Obj(Editor).LinesHead.pFirstMember
          lea xax, [xdx - offset $Obj(EditorLine).LineLink]   ;xax -> last EditorLine
          mov [xsi].SrchEnd.pEditorLine, xax
          mov [xsi].SrchEnd.dCharIndex, 0
          mov [xsi].SrchEnd.dLineNumber, 1
        .endif
      .endif

      OCall pChildWndObject::Editor.FindStr, addr cFindStr, addr [xsi].SrchBeg, addr [xsi].SrchEnd, addr [xsi].Choices
      .if eax != FALSE
        invoke RedrawWindow, [xdi].$Obj(Editor).hWnd, NULL, 0, RDW_INVALIDATE or RDW_UPDATENOW or RDW_ALLCHILDREN
      .endif
      mov dRet, eax
      mov [xsi].dContinue, eax
      invoke GetDlgItem, [xsi].hWnd, IDC_BTN_REPLACE
      invoke EnableWindow, xax, [xsi].dContinue
      
    .endif

  .elseif [xsi].Choices.dScope == FDS_OPEN_FILES
    mov xax, [xsi].pOwner
    mov xbx, [xax].$Obj(MdiApp).pClientWnd
;    invoke EnumChildWindows, [xbx].$Obj(ClientWnd).hWnd, offset FindInOpenFile, xsi  doesnt work since it does not stop

  .elseif [xsi].Choices.dScope == FDS_PROJECT_FILES

  .elseif [xsi].Choices.dScope == FDS_ALL_FILES

  .endif
  mov eax, dRet
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     FindDialog.Help
; Purpose:    Provide help for this dialog.
; Arguments:  None.
; Return:     Nothing.

Method FindDialog.Help, uses xbx xsi
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
Method FindDialog.Init, uses xbx xsi, pOwner:POINTER
  SetObject xsi
  mov xax, pOwner
  ACall xsi.Init, pOwner, [xax].$Obj(MdiApp).hWnd, 2000, addr [xax].$Obj(MdiApp).hActiveMlsDlg

  c2m [xsi].pDynamicLayout, offset DlgChildrenInfo, xcx

  OCall [xsi].FindStrings::%StrCollection.Init, xsi, 20, 20, COL_MAX_CAPACITY
  OCall [xsi].ReplStrings::%StrCollection.Init, xsi, 20, 20, COL_MAX_CAPACITY
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     FindDialog.OnActivate
; Purpose:    Event procedure for WM_ACTIVATE message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method FindDialog.OnActivate, uses xbx xsi, wParam:WPARAM, lParam:LPARAM
  local cBuffer[2024]:CHR, hComboBox:HWND

  ANNOTATION use:wParam lParam

  SetObject xsi
  ACall xsi.OnActivate, wParam, lParam
  mov xax, wParam
  .if ax != WA_INACTIVE                                   ;If any form of activation

    invoke GetDlgItem, [xsi].hWnd, IDC_BTN_REPLACE
    invoke EnableWindow, xax, [xsi].dContinue 

    mov hComboBox, $invoke(GetDlgItem, [xsi].hWnd, IDC_CBO_FIND)

    ;Find the active editor
    mov xax, [xsi].pOwner
    mov xcx, [xax].$Obj(MdiApp).pClientWnd
    invoke SendMessage, [xcx].$Obj(ClientWnd).hWnd, WM_MDIGETACTIVE, 0, 0
    invoke SendMessage, xax, WM_GETOBJECTINSTANCE, 0, 0
    .if xax != NULL
      mov xdi, xax
      invoke GetObjectID, xdi
      .if eax == ADE_EditorID
        ;If something is selected, write it to the ComboBox
        mov xax, [xdi].$Obj(Editor).SelectionRange.SELRANGE.pBegSelInfo
        mov xcx, [xdi].$Obj(Editor).SelectionRange.SELRANGE.pEndSelInfo
        .if xax != NULL && xcx != NULL
          mov xdx, [xax].LOCATION.pEditorLine
          ;Only if the selection is on the same line!
          .if xdx == [xcx].LOCATION.pEditorLine
            mov xdx, [xdx].$Obj(EditorLine).pBuffer
            mov ebx, [xax].LOCATION.dCharIndex
            lea xdx, [xdx + xbx*sizeof(CHR)]              ;xdx -> Selection begin
            mov eax, [xcx].LOCATION.dCharIndex
            sub eax, ebx                                  ;eax = char count
            lea xcx, cBuffer
            invoke StrCCopy, xcx, xdx, eax
            invoke SendMessage, hComboBox, WM_SETTEXT, 0, addr cBuffer
          .endif
        .endif
      .endif
    .endif
    invoke SendMessage, hComboBox, CB_SETEDITSEL, 0, 0FFFF0000h   ;Select complete content
    invoke SetFocus, hComboBox                            ;Always to focus on the ComboBox
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
    ;Any change on the FINDDLGCHOICES controls will stop the continuation
    mov [xsi].dContinue, FALSE
    invoke GetDlgItem, [xsi].hWnd, IDC_BTN_REPLACE
    invoke EnableWindow, xax, FALSE 
  .else
    mov xax, [xsi].pOwner
    mov xcx, [xax].$Obj(MdiApp).pClientWnd
    invoke SendMessage, [xcx].$Obj(ClientWnd).hWnd, WM_MDIGETACTIVE, 0, 0
    invoke SendMessage, xax, WM_GETOBJECTINSTANCE, 0, 0
    .if xax != NULL
      mov xdi, xax
      LoWord(wParam)
      .if ax == IDOK                                        ;Find Button
        OCall xsi.Find, xdi
        .if eax == FALSE
          invoke MessageBox, [xsi].hWnd, $OfsCStr("No matches found."), $OfsCStr("Find"), MB_OK or MB_ICONINFORMATION
        .endif

      .elseif ax == IDC_BTN_REPLACE
        OCall xsi.Replace, xdi
        .if eax == FALSE
          invoke MessageBox, [xsi].hWnd, $OfsCStr("No matches found."), $OfsCStr("Replace"), MB_OK or MB_ICONINFORMATION
        .endif

      .elseif ax == IDC_BTN_REPLACEALL
        OCall xsi.ReplaceAll, xdi
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
; Arguments:  Arg1: -> Active child window object.
; Return:     eax = TRUE if succeeded, otherwise FALSE.

Method FindDialog.Replace, uses xbx xsi, pChildWndObject:POINTER
  local cReplStr[2024]:CHR, hComboBox:HWND, dRet:DWORD, dNeedUpdate:DWORD

  SetObject xsi
  mov dRet, FALSE
  mov dNeedUpdate, FALSE
  
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
    invoke GetObjectID, pChildWndObject
    .if eax == ADE_EditorID
      OCall pChildWndObject::Editor.SelectionReplace, addr cReplStr
      .if eax == FALSE
        invoke MessageBox, [xsi].hWnd, $OfsCStr("Nothing selected."), $OfsCStr("Replace"), MB_OK or MB_ICONINFORMATION
      .else
        mov dNeedUpdate, TRUE
      .endif
      OCall xsi.Find, pChildWndObject
      mov dRet, eax
      .if eax == FALSE && dNeedUpdate != FALSE
        invoke RedrawWindow, [xdi].$Obj(Editor).hWnd, NULL, 0, RDW_INVALIDATE or RDW_UPDATENOW or RDW_ALLCHILDREN
      .endif
    .endif

  .elseif [xsi].Choices.dScope == FDS_OPEN_FILES

  .elseif [xsi].Choices.dScope == FDS_PROJECT_FILES

  .elseif [xsi].Choices.dScope == FDS_ALL_FILES

  .endif
  mov eax, dRet
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     FindDialog.ReplaceAll
; Purpose:    Replace all occurrences with the content of the replace combobox.
; Arguments:  Arg1: -> Active child window object.
; Return:     eax = TRUE if succeeded, otherwise FALSE.

Method FindDialog.ReplaceAll, uses xbx xdi xsi, pChildWndObject:POINTER
  local cFindStr[2024]:CHR, cReplStr[2024]:CHR, hComboBox:HWND, hChildWnd:HWND, dReplCounter:DWORD

  SetObject xsi
  mov dReplCounter, FALSE

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
    invoke GetObjectID, pChildWndObject
    .if eax == ADE_EditorID
      mov eax, TRUE
      .if [xsi].dContinue == FALSE
        OCall xsi.Find, pChildWndObject
      .endif

      .While eax == TRUE
        OCall pChildWndObject::Editor.SelectionReplace, addr cReplStr
        .if eax == FALSE
          invoke MessageBox, [xsi].hWnd, $OfsCStr("Replacement failed."), $OfsCStr("Replace all"), MB_OK or MB_ICONERROR
          .break
        .endif
        inc dReplCounter
        OCall pChildWndObject::Editor.FindStr, addr cFindStr, addr [xsi].SrchBeg, addr [xsi].SrchEnd, addr [xsi].Choices
      .endw
      .if dReplCounter != 0
        invoke RedrawWindow, [xdi].$Obj(Editor).hWnd, NULL, 0, RDW_INVALIDATE or RDW_UPDATENOW or RDW_ALLCHILDREN
      .endif
      mov [xsi].dContinue, FALSE
    .endif

  .elseif [xsi].Choices.dScope == FDS_OPEN_FILES

  .elseif [xsi].Choices.dScope == FDS_PROJECT_FILES

  .elseif [xsi].Choices.dScope == FDS_ALL_FILES

  .endif
  mov eax, dReplCounter
MethodEnd
