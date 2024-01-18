; ==================================================================================================
; Title:      DB_StructEditorDlg.inc
; Author:     G. Friedrich
; Version:    C.1.1
; Purpose:    ObjAsm Database structure editor dialog.
; Notes:      Version C.1.1, August 2019
;             - First release.
; ==================================================================================================


; ——————————————————————————————————————————————————————————————————————————————————————————————————

SDF_CTRL_EDITOR_ENABLED   equ   BIT00
SDF_CTRL_APPEND_ENABLED   equ   BIT01
SDF_CTRL_DELETE_ENABLED   equ   BIT02
SDF_CTRL_UP_DOWN_ENABLED  equ   BIT03
SDF_CTRL_APPLY_ENABLED    equ   BIT04
SDF_CTRL_CANCEL_ENABLED   equ   BIT05
SDF_CTRL_OK_ENABLED       equ   BIT06

SRF_INIT                  equ   SDF_CTRL_EDITOR_ENABLED or \
                                SDF_CTRL_CANCEL_ENABLED or SDF_CTRL_OK_ENABLED or \
                                SDF_CTRL_APPLY_ENABLED or SDF_CTRL_APPEND_ENABLED or \
                                SDF_CTRL_DELETE_ENABLED or SDF_CTRL_UP_DOWN_ENABLED

SDF_THREAD_STOP           equ   BIT06
SDF_THREAD_READY          equ   BIT07
SDF_THREAD_ERROR          equ   BIT08
SDF_THREAD_CLOSE          equ   BIT09


Object DB_StructEditorDlg,, DialogModal
  VirtualMethod     CtlsEnable
  RedefineMethod    CtlsGet
  RedefineMethod    CtlsSet
  RedefineMethod    Done
  RedefineMethod    Init,             POINTER, HWND, $ObjPtr(DB_Table)

  VirtualMethod     Mutate
  VirtualMethod     MutateData,       PTaskStatus, XWORD, XWORD
  VirtualMethod     ReopenIndex,      PTaskStatus, $ObjPtr(DB_StructEditorLine), XWORD
  VirtualMethod     RebuildIndex,     PTaskStatus, $ObjPtr(DB_StructEditorLine), XWORD

  RedefineMethod    OnCommand,        WPARAM, LPARAM
  RedefineMethod    OnInitDialog,     WPARAM, LPARAM
  RedefineMethod    OnSize,           WPARAM, LPARAM
  VirtualMethod     UpdateStatusbar

  VirtualEvent      OnExitSizeMove,   WM_EXITSIZEMOVE
  VirtualEvent      OnVScroll,        WM_VSCROLL

  DefineVariable    dFlags,           DWORD,    SRF_INIT or SDF_THREAD_READY
  DefineVariable    pMemTasks,        PTaskHeader,  NULL
  DefineVariable    pTable,           $ObjPtr(DB_Table),        NULL
  DefineVariable    pStructEditor,    $ObjPtr(DB_StructEditor), NULL  ;Created by the Dlg Template

  Embed     StatusBar,    Statusbar
ObjectEnd


.code

; ==================================================================================================
;    DB_StructEditorDlg implementation
; ==================================================================================================

;PROGRESS_TIMER_ID = 20

.data
align ALIGN_DATA
StrucDlgChildrenInfo label DL_HEADER
DL_HEADER     {DLF_LOAD_MIN or DLF_LIMIT_MINMAX}    ;DL_HEADER.MaxSize set on OnInitDialog
DL_CHILD_INFO {{100, 100, 000, 000}}    ;OK
DL_CHILD_INFO {{000, 000, 000, 000}}    ;Name
DL_CHILD_INFO {{000, 000, 000, 000}}    ;Type
DL_CHILD_INFO {{000, 000, 000, 000}}    ;Length
DL_CHILD_INFO {{000, 000, 000, 000}}    ;Param
DL_CHILD_INFO {{000, 000, 000, 000}}    ;Index
DL_CHILD_INFO {{000, 000, 100, 100}}    ;Editor
DL_CHILD_INFO {{100, 000, 000, 000}}    ;Append
DL_CHILD_INFO {{100, 000, 000, 000}}    ;Delete
DL_CHILD_INFO {{100, 000, 000, 000}}    ;UpDown scrollbar
DL_CHILD_INFO {{100, 000, 000, 000}}    ;UpDown static
DL_CHILD_INFO {{100, 100, 000, 000}}    ;Apply
DL_CHILD_INFO {{100, 100, 000, 000}}    ;Cancel
DL_CHILD_INFO {{000, 100, 100, 000}}    ;Statusbar

.code
; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     DB_StructEditorDlg.CtlsEnable
; Purpose:    Enable or disable the dialog children controls.
; Arguments:  None.
; Return:     Nothing.

EnableDialogControl macro CtlID:req, FlagID:req
  invoke GetDlgItem, [xsi].hWnd, CtlID
  xor edx, edx
  .ifBitSet [xsi].dFlags, FlagID
    inc edx
  .endif
  invoke EnableWindow, xax, edx
endm

Method DB_StructEditorDlg.CtlsEnable, uses xsi
  local dFlags:DWORD

  SetObject xsi
  m2m dFlags, [xsi].dFlags, eax

  xor edx, edx
  .ifBitSet [xsi].dFlags, SDF_CTRL_EDITOR_ENABLED
    mov xcx, [xsi].pStructEditor
    .if [xcx].$Obj(DB_StructEditor).pSelEditorLine != NULL
      BitSet [xsi].dFlags, SDF_CTRL_DELETE_ENABLED or SDF_CTRL_UP_DOWN_ENABLED
    .else
      BitClr [xsi].dFlags, SDF_CTRL_DELETE_ENABLED or SDF_CTRL_UP_DOWN_ENABLED
    .endif
    inc edx
  .else
    ;Reset flags temporarily
    BitClr [xsi].dFlags, SDF_CTRL_DELETE_ENABLED or SDF_CTRL_UP_DOWN_ENABLED or \
                         SDF_CTRL_APPEND_ENABLED or SDF_CTRL_APPLY_ENABLED
  .endif

  EnableDialogControl IDC_STRUC_EDT,           SDF_CTRL_EDITOR_ENABLED
  EnableDialogControl IDC_STRUC_BTN_APPEND,    SDF_CTRL_APPEND_ENABLED
  EnableDialogControl IDC_STRUC_BTN_DELETE,    SDF_CTRL_DELETE_ENABLED
  EnableDialogControl IDC_STRUC_SCB_UP_DOWN,   SDF_CTRL_UP_DOWN_ENABLED
  EnableDialogControl IDC_STRUC_STC_FIELD_POS, SDF_CTRL_UP_DOWN_ENABLED
  EnableDialogControl IDC_STRUC_BTN_APPLY,     SDF_CTRL_APPLY_ENABLED
  EnableDialogControl IDC_STRUC_BTN_CANCEL,    SDF_CTRL_CANCEL_ENABLED
  EnableDialogControl IDC_STRUC_BTN_OK,        SDF_CTRL_OK_ENABLED

  .ifBitClr [xsi].dFlags, SDF_CTRL_EDITOR_ENABLED
    m2m [xsi].dFlags, dFlags, eax
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     DB_StructEditorDlg.CtlsGet
; Purpose:    Read the controls in this dialog window.
; Arguments:  None.
; Return:     Nothing.

Method DB_StructEditorDlg.CtlsGet
  SetObject xax
  OCall [xax].pStructEditor::DB_StructEditor.CtlsGet, [xax].pTable
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     DB_StructEditorDlg.CtlsSet
; Purpose:    Set the controls in this dialog window.
; Arguments:  None.
; Return:     Nothing.

Method DB_StructEditorDlg.CtlsSet
  SetObject xax
  OCall [xax].pStructEditor::DB_StructEditor.CtlsSet, [xax].pTable
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     DB_StructEditorDlg.Done
; Purpose:    Finalize the DB_QueryDlg object.
; Arguments:  None.
; Return:     Nothing.

Method DB_StructEditorDlg.Done, uses xsi
  SetObject xsi
  OCall [xsi].StatusBar::Statusbar.Done
  ACall xsi.Done
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     DB_StructEditorDlg.Init
; Purpose:    Initialize the DB_StructEditorDlg object.
; Arguments:  Arg1: -> Owner object.
;             Arg2: Parent window HANDLE.
;             Arg3: -> DB_Table.
; Return:     Nothing.

Method DB_StructEditorDlg.Init,, pOwner:POINTER, hParent:HWND, pTable:$ObjPtr(DB_Table)
  SetObject xcx
  mrm [xcx].pTable, pTable, xax
  ACall xcx.Init, pOwner, hParent, IDD_STRUC_EDITOR
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     DB_StructEditorDlg.Mutate
; Purpose:    Start the mutation job.
; Arguments:  None.
; Return:     eax = OBJ_OK if succeeded.

MUTATION_ENTRY struct 1
  bInType     BYTE      ?
  bOutType    BYTE      ?
  wFlags      WORD      ?
  pInProc     POINTER   ?
  pOutProc    POINTER   ?
MUTATION_ENTRY ends
PMUTATION_ENTRY typedef ptr MUTATION_ENTRY

.const
align ALIGN_DATA
MutationLUT label STD_FIELD_INFO
MUTATION_ENTRY {FDT_BINARY,     FDT_BINARY,      0, offset(MUT_CopyData), NULL}
MUTATION_ENTRY {FDT_BINARY,     FDT_CHAR_ANSI,   0, offset(MUT_FillBlank), offset(MUT_DeleteMemo)}
;MUTATION_ENTRY {FDT_BINARY,     FDT_DATE,        0, offset(MUT_FillBlank), NULL}
;MUTATION_ENTRY {FDT_BINARY,     FDT_REAL4,       0, offset(MUT_FillBlank), NULL}
;MUTATION_ENTRY {FDT_BINARY,     FDT_OLE,         0, offset(MUT_FillBlank), NULL}
;MUTATION_ENTRY {FDT_BINARY,     FDT_SDWORD,      0, offset(MUT_FillBlank), NULL}
;MUTATION_ENTRY {FDT_BINARY,     FDT_BOOL,        0, offset(MUT_FillBlank), NULL}
;MUTATION_ENTRY {FDT_BINARY,     FDT_MEMO_ANSI,   0, offset(MUT_FillBlank), NULL}
;MUTATION_ENTRY {FDT_BINARY,     FDT_NUMERIC,     0, offset(MUT_FillBlank), NULL}
;MUTATION_ENTRY {FDT_BINARY,     FDT_REAL8,       0, offset(MUT_FillBlank), NULL}
;MUTATION_ENTRY {FDT_BINARY,     FDT_REAL10,      0, offset(MUT_FillBlank), NULL}
;MUTATION_ENTRY {FDT_BINARY,     FDT_CURRENCY,    0, offset(MUT_FillBlank), NULL}
;MUTATION_ENTRY {FDT_BINARY,     FDT_CHAR_WIDE,   0, offset(MUT_FillBlank), NULL}
;MUTATION_ENTRY {FDT_BINARY,     FDT_CHAR_UTF8,   0, offset(MUT_FillBlank), NULL}
;MUTATION_ENTRY {FDT_BINARY,     FDT_TIMESTAMP,   0, offset(MUT_FillBlank), NULL}
;MUTATION_ENTRY {FDT_BINARY,     FDT_AUTOINC,     0, offset(MUT_FillBlank), NULL}
;MUTATION_ENTRY {FDT_CHAR_ANSI,  FDT_BINARY,      0, offset(MUT_FillBlank), NULL}
MUTATION_ENTRY {FDT_CHAR_ANSI,  FDT_CHAR_ANSI,   0, offset(MUT_CopyDataFillA), NULL}
MUTATION_ENTRY {FDT_CHAR_ANSI,  FDT_DATE,        0, offset(MUT_ChrAToBuf), offset(MUT_BufToDate)}
MUTATION_ENTRY {FDT_CHAR_ANSI,  FDT_REAL4,       0, offset(MUT_ChrAToFpu), offset(MUT_FpuToR4)}
;MUTATION_ENTRY {FDT_CHAR_ANSI,  FDT_OLE,         0, offset(MUT_FillBlank), NULL}
MUTATION_ENTRY {FDT_CHAR_ANSI,  FDT_SDWORD,      0, offset(MUT_ChrAToFpu), offset(MUT_FpuToInt32)}
MUTATION_ENTRY {FDT_CHAR_ANSI,  FDT_BOOL,        0, offset(MUT_ChrAToBuf), offset(MUT_BufToBool)}
MUTATION_ENTRY {FDT_CHAR_ANSI,  FDT_MEMO_ANSI,   0, offset(MUT_ChrAToBuf), offset(MUT_BufToMemo)}
MUTATION_ENTRY {FDT_CHAR_ANSI,  FDT_NUMERIC,     0, offset(MUT_ChrAToBuf), offset(MUT_BufToNum)}
MUTATION_ENTRY {FDT_CHAR_ANSI,  FDT_REAL8,       0, offset(MUT_ChrAToFpu), offset(MUT_FpuToR8)}
MUTATION_ENTRY {FDT_CHAR_ANSI,  FDT_REAL10,      0, offset(MUT_ChrAToFpu), offset(MUT_FpuToR10)}
MUTATION_ENTRY {FDT_CHAR_ANSI,  FDT_CURRENCY,    0, offset(MUT_ChrAToFpu), offset(MUT_FpuToR8)}
MUTATION_ENTRY {FDT_CHAR_ANSI,  FDT_CHAR_WIDE,   0, offset(MUT_ChrAToBuf), offset(MUT_BufToChrFillW)}
MUTATION_ENTRY {FDT_CHAR_ANSI,  FDT_CHAR_UTF8,   0, offset(MUT_ChrAToBuf), offset(MUT_BufToChr8)}
MUTATION_ENTRY {FDT_CHAR_ANSI,  FDT_TIMESTAMP,   0, offset(MUT_ChrAToFpu), offset(MUT_FpuToTimestamp)}
MUTATION_ENTRY {FDT_CHAR_ANSI,  FDT_AUTOINC,     0, offset(MUT_ChrAToFpu), offset(MUT_FpuToUInt32)}
;MUTATION_ENTRY {FDT_DATE,       FDT_BINARY,      0, offset(MUT_FillBlank), NULL}
MUTATION_ENTRY {FDT_DATE,       FDT_CHAR_ANSI,   0, offset(MUT_DateToBuf), offset(MUT_BufToChrFillA)}
MUTATION_ENTRY {FDT_DATE,       FDT_DATE,        0, offset(MUT_CopyData), offset(MUT_FpuToInt32)}
MUTATION_ENTRY {FDT_DATE,       FDT_REAL4,       0, offset(MUT_DateToFpu), offset(MUT_FpuToR4)}
;MUTATION_ENTRY {FDT_DATE,       FDT_OLE,         0, offset(MUT_FillBlank), NULL}
MUTATION_ENTRY {FDT_DATE,       FDT_SDWORD,      0, offset(MUT_DateToFpu), offset(MUT_FpuToInt32)}
;MUTATION_ENTRY {FDT_DATE,       FDT_BOOL,        0, offset(MUT_FillBlank), NULL}
MUTATION_ENTRY {FDT_DATE,       FDT_MEMO_ANSI,   0, offset(MUT_DateToBuf), offset(MUT_BufToMemo)}
MUTATION_ENTRY {FDT_DATE,       FDT_NUMERIC,     0, offset(MUT_DateToFpu), offset(MUT_FpuToNum)}
MUTATION_ENTRY {FDT_DATE,       FDT_REAL8,       0, offset(MUT_DateToFpu), offset(MUT_FpuToR8)}
MUTATION_ENTRY {FDT_DATE,       FDT_REAL10,      0, offset(MUT_DateToFpu), offset(MUT_FpuToR10)}
;MUTATION_ENTRY {FDT_DATE,       FDT_CURRENCY,    0, offset(MUT_FillBlank), NULL}
MUTATION_ENTRY {FDT_DATE,       FDT_CHAR_WIDE,   0, offset(MUT_DateToBuf), offset(MUT_BufToChrFillW)}
MUTATION_ENTRY {FDT_DATE,       FDT_CHAR_UTF8,   0, offset(MUT_DateToBuf), offset(MUT_BufToChr8)}
MUTATION_ENTRY {FDT_DATE,       FDT_TIMESTAMP,   0, offset(MUT_DateToFpu), offset(MUT_FpuToTimestamp)}
;MUTATION_ENTRY {FDT_DATE,       FDT_AUTOINC,     0, offset(MUT_FillBlank), NULL}
;MUTATION_ENTRY {FDT_REAL4,      FDT_BINARY,      0, offset(MUT_FillBlank), NULL}
MUTATION_ENTRY {FDT_REAL4,      FDT_CHAR_ANSI,   0, offset(MUT_R4ToFpu), offset(MUT_FpuToChrA)}
MUTATION_ENTRY {FDT_REAL4,      FDT_DATE,        0, offset(MUT_R4ToFpu), offset(MUT_FpuToDate)}
MUTATION_ENTRY {FDT_REAL4,      FDT_REAL4,       0, offset(MUT_CopyData), NULL}
;MUTATION_ENTRY {FDT_REAL4,      FDT_OLE,         0, offset(MUT_FillBlank), NULL}
MUTATION_ENTRY {FDT_REAL4,      FDT_SDWORD,      0, offset(MUT_R4ToFpu), offset(MUT_FpuToInt32)}
MUTATION_ENTRY {FDT_REAL4,      FDT_BOOL,        0, offset(MUT_R4ToFpu), offset(MUT_FpuToBool)}
;MUTATION_ENTRY {FDT_REAL4,      FDT_MEMO_ANSI,   0, offset(MUT_FillBlank), NULL}
MUTATION_ENTRY {FDT_REAL4,      FDT_NUMERIC,     0, offset(MUT_R4ToFpu), offset(MUT_FpuToNum)}
MUTATION_ENTRY {FDT_REAL4,      FDT_REAL8,       0, offset(MUT_R4ToFpu), offset(MUT_FpuToR8)}
MUTATION_ENTRY {FDT_REAL4,      FDT_REAL10,      0, offset(MUT_R4ToFpu), offset(MUT_FpuToR10)}
MUTATION_ENTRY {FDT_REAL4,      FDT_CURRENCY,    0, offset(MUT_R4ToFpu), offset(MUT_FpuToR8)}
MUTATION_ENTRY {FDT_REAL4,      FDT_CHAR_WIDE,   0, offset(MUT_R4ToFpu), offset(MUT_FpuToChrW)}
MUTATION_ENTRY {FDT_REAL4,      FDT_CHAR_UTF8,   0, offset(MUT_R4ToFpu), offset(MUT_FpuToChrA)}
MUTATION_ENTRY {FDT_REAL4,      FDT_TIMESTAMP,   0, offset(MUT_R4ToFpu), offset(MUT_FpuToTimestamp)}
MUTATION_ENTRY {FDT_REAL4,      FDT_AUTOINC,     0, offset(MUT_R4ToFpu), offset(MUT_FpuToInt32)}
;MUTATION_ENTRY {FDT_SDWORD,     FDT_BINARY,      0, offset(MUT_FillBlank), NULL}
MUTATION_ENTRY {FDT_SDWORD,     FDT_CHAR_ANSI,   0, offset(MUT_Int32ToFpu), offset(MUT_FpuToChrA)}
MUTATION_ENTRY {FDT_SDWORD,     FDT_DATE,        0, offset(MUT_Int32ToFpu), offset(MUT_FpuToDate)}
MUTATION_ENTRY {FDT_SDWORD,     FDT_REAL4,       0, offset(MUT_Int32ToFpu), offset(MUT_FpuToR4)}
;MUTATION_ENTRY {FDT_SDWORD,     FDT_OLE,         0, offset(MUT_FillBlank), NULL}
MUTATION_ENTRY {FDT_SDWORD,     FDT_SDWORD,      0, offset(MUT_CopyData), NULL}
MUTATION_ENTRY {FDT_SDWORD,     FDT_BOOL,        0, offset(MUT_Int32ToFpu), offset(MUT_FpuToBool)}
;MUTATION_ENTRY {FDT_SDWORD,     FDT_MEMO_ANSI,   0, offset(MUT_FillBlank), NULL}
MUTATION_ENTRY {FDT_SDWORD,     FDT_NUMERIC,     0, offset(MUT_Int32ToFpu), offset(MUT_FpuToNum)}
MUTATION_ENTRY {FDT_SDWORD,     FDT_REAL8,       0, offset(MUT_Int32ToFpu), offset(MUT_FpuToR8)}
MUTATION_ENTRY {FDT_SDWORD,     FDT_REAL10,      0, offset(MUT_Int32ToFpu), offset(MUT_FpuToR10)}
MUTATION_ENTRY {FDT_SDWORD,     FDT_CURRENCY,    0, offset(MUT_Int32ToFpu), offset(MUT_FpuToR8)}
MUTATION_ENTRY {FDT_SDWORD,     FDT_CHAR_WIDE,   0, offset(MUT_Int32ToFpu), offset(MUT_FpuToChrW)}
MUTATION_ENTRY {FDT_SDWORD,     FDT_CHAR_UTF8,   0, offset(MUT_Int32ToFpu), offset(MUT_FpuToChr8)}
MUTATION_ENTRY {FDT_SDWORD,     FDT_TIMESTAMP,   0, offset(MUT_Int32ToFpu), offset(MUT_FpuToTimestamp)}
MUTATION_ENTRY {FDT_SDWORD,     FDT_AUTOINC,     0, offset(MUT_CopyData), NULL}
;MUTATION_ENTRY {FDT_BOOL,       FDT_BINARY,      0, offset(MUT_FillBlank), NULL}
MUTATION_ENTRY {FDT_BOOL,       FDT_CHAR_ANSI,   0, offset(MUT_BoolToFpu), offset(MUT_FpuToChrA)}
;MUTATION_ENTRY {FDT_BOOL,       FDT_DATE,        0, offset(MUT_FillBlank), NULL}
;MUTATION_ENTRY {FDT_BOOL,       FDT_REAL4,       0, offset(MUT_FillBlank), NULL}
;MUTATION_ENTRY {FDT_BOOL,       FDT_OLE,         0, offset(MUT_FillBlank), NULL}
MUTATION_ENTRY {FDT_BOOL,       FDT_SDWORD,      0, offset(MUT_BoolToFpu), offset(MUT_FpuToInt32)}
MUTATION_ENTRY {FDT_BOOL,       FDT_BOOL,        0, offset(MUT_CopyData), NULL}
;MUTATION_ENTRY {FDT_BOOL,       FDT_MEMO_ANSI,   0, offset(MUT_FillBlank), NULL}
MUTATION_ENTRY {FDT_BOOL,       FDT_NUMERIC,     0, offset(MUT_BoolToFpu), offset(MUT_FpuToNum)}
MUTATION_ENTRY {FDT_BOOL,       FDT_REAL8,       0, offset(MUT_BoolToFpu), offset(MUT_FpuToR8)}
MUTATION_ENTRY {FDT_BOOL,       FDT_REAL10,      0, offset(MUT_BoolToFpu), offset(MUT_FpuToR10)}
MUTATION_ENTRY {FDT_BOOL,       FDT_CURRENCY,    0, offset(MUT_BoolToFpu), offset(MUT_FpuToR8)}
MUTATION_ENTRY {FDT_BOOL,       FDT_CHAR_WIDE,   0, offset(MUT_BoolToFpu), offset(MUT_FpuToChrW)}
MUTATION_ENTRY {FDT_BOOL,       FDT_CHAR_UTF8,   0, offset(MUT_BoolToFpu), offset(MUT_FpuToChr8)}
;MUTATION_ENTRY {FDT_BOOL,       FDT_TIMESTAMP,   0, offset(MUT_FillBlank), NULL}
;MUTATION_ENTRY {FDT_BOOL,       FDT_AUTOINC,     0, offset(MUT_FillBlank), NULL}
;MUTATION_ENTRY {FDT_NUMERIC,    FDT_BINARY,      0, offset(MUT_FillBlank), NULL}
MUTATION_ENTRY {FDT_NUMERIC,    FDT_CHAR_ANSI,   0, offset(MUT_NumToFpu), offset(MUT_FpuToChrA)}
MUTATION_ENTRY {FDT_NUMERIC,    FDT_DATE,        0, offset(MUT_NumToFpu), offset(MUT_FpuToDate)}
MUTATION_ENTRY {FDT_NUMERIC,    FDT_REAL4,       0, offset(MUT_NumToFpu), offset(MUT_FpuToR4)}
;MUTATION_ENTRY {FDT_NUMERIC,    FDT_OLE,         0, offset(MUT_FillBlank), NULL}
MUTATION_ENTRY {FDT_NUMERIC,    FDT_SDWORD,      0, offset(MUT_NumToFpu), offset(MUT_FpuToInt32)}
MUTATION_ENTRY {FDT_NUMERIC,    FDT_BOOL,        0, offset(MUT_NumToFpu), offset(MUT_FpuToBool)}
MUTATION_ENTRY {FDT_NUMERIC,    FDT_MEMO_ANSI,    0, offset(MUT_ChrAToBuf), offset(MUT_BufToMemo)}
MUTATION_ENTRY {FDT_NUMERIC,    FDT_NUMERIC,     0, offset(MUT_NumToNum), NULL}
MUTATION_ENTRY {FDT_NUMERIC,    FDT_REAL8,       0, offset(MUT_NumToFpu), offset(MUT_FpuToR8)}
MUTATION_ENTRY {FDT_NUMERIC,    FDT_REAL10,      0, offset(MUT_NumToFpu), offset(MUT_FpuToR10)}
MUTATION_ENTRY {FDT_NUMERIC,    FDT_CURRENCY,    0, offset(MUT_NumToFpu), offset(MUT_FpuToR8)}
MUTATION_ENTRY {FDT_NUMERIC,    FDT_CHAR_WIDE,   0, offset(MUT_NumToFpu), offset(MUT_FpuToChrW)}
MUTATION_ENTRY {FDT_NUMERIC,    FDT_CHAR_UTF8,   0, offset(MUT_NumToFpu), offset(MUT_FpuToChr8)}
MUTATION_ENTRY {FDT_NUMERIC,    FDT_TIMESTAMP,   0, offset(MUT_NumToFpu), offset(MUT_FpuToTimestamp)}
MUTATION_ENTRY {FDT_NUMERIC,    FDT_AUTOINC,     0, offset(MUT_NumToFpu), offset(MUT_FpuToUInt32)}
;MUTATION_ENTRY {FDT_REAL8,      FDT_BINARY,      0, offset(MUT_FillBlank), NULL}
MUTATION_ENTRY {FDT_REAL8,      FDT_CHAR_ANSI,   0, offset(MUT_R8ToFpu), offset(MUT_FpuToChrA)}
MUTATION_ENTRY {FDT_REAL8,      FDT_DATE,        0, offset(MUT_R8ToFpu), offset(MUT_FpuToDate)}
MUTATION_ENTRY {FDT_REAL8,      FDT_REAL4,       0, offset(MUT_R8ToFpu), offset(MUT_FpuToR4)}
;MUTATION_ENTRY {FDT_REAL8,      FDT_OLE,         0, offset(MUT_FillBlank), NULL}
MUTATION_ENTRY {FDT_REAL8,      FDT_SDWORD,      0, offset(MUT_R8ToFpu), offset(MUT_FpuToInt32)}
MUTATION_ENTRY {FDT_REAL8,      FDT_BOOL,        0, offset(MUT_R8ToFpu), offset(MUT_FpuToBool)}
;MUTATION_ENTRY {FDT_REAL8,      FDT_MEMO_ANSI,   0, offset(MUT_FillBlank), NULL}
MUTATION_ENTRY {FDT_REAL8,      FDT_NUMERIC,     0, offset(MUT_R8ToFpu), offset(MUT_FpuToNum)}
MUTATION_ENTRY {FDT_REAL8,      FDT_REAL8,       0, offset(MUT_CopyData), NULL}
MUTATION_ENTRY {FDT_REAL8,      FDT_REAL10,      0, offset(MUT_R8ToFpu), offset(MUT_FpuToR10)}
MUTATION_ENTRY {FDT_REAL8,      FDT_CURRENCY,    0, offset(MUT_CopyData), NULL}
MUTATION_ENTRY {FDT_REAL8,      FDT_CHAR_WIDE,   0, offset(MUT_R8ToFpu), offset(MUT_FpuToChrW)}
MUTATION_ENTRY {FDT_REAL8,      FDT_CHAR_UTF8,   0, offset(MUT_R8ToFpu), offset(MUT_FpuToChr8)}
MUTATION_ENTRY {FDT_REAL8,      FDT_TIMESTAMP,   0, offset(MUT_R8ToFpu), offset(MUT_FpuToTimestamp)}
MUTATION_ENTRY {FDT_REAL8,      FDT_AUTOINC,     0, offset(MUT_R8ToFpu), offset(MUT_FpuToInt32)}
;MUTATION_ENTRY {FDT_REAL10,     FDT_BINARY,      0, offset(MUT_FillBlank), NULL}
MUTATION_ENTRY {FDT_REAL10,     FDT_CHAR_ANSI,   0, offset(MUT_R10ToFpu), offset(MUT_FpuToChrA)}
MUTATION_ENTRY {FDT_REAL10,     FDT_DATE,        0, offset(MUT_R10ToFpu), offset(MUT_FpuToDate)}
MUTATION_ENTRY {FDT_REAL10,     FDT_REAL4,       0, offset(MUT_R10ToFpu), offset(MUT_FpuToR4)}
;MUTATION_ENTRY {FDT_REAL10,     FDT_OLE,         0, offset(MUT_FillBlank), NULL}
MUTATION_ENTRY {FDT_REAL10,     FDT_SDWORD,      0, offset(MUT_R10ToFpu), offset(MUT_FpuToInt32)}
MUTATION_ENTRY {FDT_REAL10,     FDT_BOOL,        0, offset(MUT_R10ToFpu), offset(MUT_FpuToBool)}
;MUTATION_ENTRY {FDT_REAL10,     FDT_MEMO_ANSI,   0, offset(MUT_FillBlank), NULL}
MUTATION_ENTRY {FDT_REAL10,     FDT_NUMERIC,     0, offset(MUT_R10ToFpu), offset(MUT_FpuToNum)}
MUTATION_ENTRY {FDT_REAL10,     FDT_REAL8,       0, offset(MUT_R10ToFpu), offset(MUT_FpuToR8)}
MUTATION_ENTRY {FDT_REAL10,     FDT_REAL10,      0, offset(MUT_CopyData), NULL}
MUTATION_ENTRY {FDT_REAL10,     FDT_CURRENCY,    0, offset(MUT_R10ToFpu), offset(MUT_FpuToR8)}
MUTATION_ENTRY {FDT_REAL10,     FDT_CHAR_WIDE,   0, offset(MUT_R10ToFpu), offset(MUT_FpuToChrW)}
MUTATION_ENTRY {FDT_REAL10,     FDT_CHAR_UTF8,   0, offset(MUT_R10ToFpu), offset(MUT_FpuToChr8)}
MUTATION_ENTRY {FDT_REAL10,     FDT_TIMESTAMP,   0, offset(MUT_R10ToFpu), offset(MUT_FpuToTimestamp)}
MUTATION_ENTRY {FDT_REAL10,     FDT_AUTOINC,     0, offset(MUT_R10ToFpu), offset(MUT_FpuToR10)}
;MUTATION_ENTRY {FDT_CURRENCY,   FDT_BINARY,      0, offset(MUT_FillBlank), NULL}
MUTATION_ENTRY {FDT_CURRENCY,   FDT_CHAR_ANSI,   0, offset(MUT_R8ToFpu), offset(MUT_FpuToChrA)}
MUTATION_ENTRY {FDT_CURRENCY,   FDT_DATE,        0, offset(MUT_R8ToFpu), offset(MUT_FpuToDate)}
MUTATION_ENTRY {FDT_CURRENCY,   FDT_REAL4,       0, offset(MUT_R8ToFpu), offset(MUT_FpuToR4)}
;MUTATION_ENTRY {FDT_CURRENCY,   FDT_OLE,         0, offset(MUT_FillBlank), NULL}
MUTATION_ENTRY {FDT_CURRENCY,   FDT_SDWORD,      0, offset(MUT_R8ToFpu), offset(MUT_FpuToInt32)}
MUTATION_ENTRY {FDT_CURRENCY,   FDT_BOOL,        0, offset(MUT_R8ToFpu), offset(MUT_FpuToBool)}
;MUTATION_ENTRY {FDT_CURRENCY,   FDT_MEMO_ANSI,   0, offset(MUT_FillBlank), NULL}
MUTATION_ENTRY {FDT_CURRENCY,   FDT_NUMERIC,     0, offset(MUT_R8ToFpu), offset(MUT_FpuToNum)}
MUTATION_ENTRY {FDT_CURRENCY,   FDT_REAL8,       0, offset(MUT_CopyData), NULL}
MUTATION_ENTRY {FDT_CURRENCY,   FDT_REAL10,      0, offset(MUT_R8ToFpu), offset(MUT_FpuToR10)}
MUTATION_ENTRY {FDT_CURRENCY,   FDT_CURRENCY,    0, offset(MUT_CopyData), NULL}
MUTATION_ENTRY {FDT_CURRENCY,   FDT_CHAR_WIDE,   0, offset(MUT_R8ToFpu), offset(MUT_FpuToChrW)}
MUTATION_ENTRY {FDT_CURRENCY,   FDT_CHAR_UTF8,   0, offset(MUT_R8ToFpu), offset(MUT_FpuToChr8)}
MUTATION_ENTRY {FDT_CURRENCY,   FDT_TIMESTAMP,   0, offset(MUT_R8ToFpu), offset(MUT_FpuToTimestamp)}
MUTATION_ENTRY {FDT_CURRENCY,   FDT_AUTOINC,     0, offset(MUT_R8ToFpu), offset(MUT_FpuToInt32)}
;MUTATION_ENTRY {FDT_CHAR_WIDE,  FDT_BINARY,      0, offset(MUT_FillBlank), NULL}
MUTATION_ENTRY {FDT_CHAR_WIDE,  FDT_CHAR_ANSI,   0, offset(MUT_ChrWToBuf), offset(MUT_BufToChrFillA)}
MUTATION_ENTRY {FDT_CHAR_WIDE,  FDT_DATE,        0, offset(MUT_ChrWToFpu), offset(MUT_FpuToDate)}
MUTATION_ENTRY {FDT_CHAR_WIDE,  FDT_REAL4,       0, offset(MUT_ChrWToFpu), offset(MUT_FpuToR4)}
;MUTATION_ENTRY {FDT_CHAR_WIDE,  FDT_OLE,         0, offset(MUT_FillBlank), NULL}
MUTATION_ENTRY {FDT_CHAR_WIDE,  FDT_SDWORD,      0, offset(MUT_ChrWToFpu), offset(MUT_FpuToInt32)}
MUTATION_ENTRY {FDT_CHAR_WIDE,  FDT_BOOL,        0, offset(MUT_ChrWToFpu), offset(MUT_FpuToBool)}
MUTATION_ENTRY {FDT_CHAR_WIDE,  FDT_MEMO_ANSI,    0, offset(MUT_ChrWToBuf), offset(MUT_BufToMemo)}
MUTATION_ENTRY {FDT_CHAR_WIDE,  FDT_NUMERIC,     0, offset(MUT_ChrWToFpu), offset(MUT_FpuToNum)}
MUTATION_ENTRY {FDT_CHAR_WIDE,  FDT_REAL8,       0, offset(MUT_ChrWToFpu), offset(MUT_FpuToR8)}
MUTATION_ENTRY {FDT_CHAR_WIDE,  FDT_REAL10,      0, offset(MUT_ChrWToFpu), offset(MUT_FpuToR10)}
MUTATION_ENTRY {FDT_CHAR_WIDE,  FDT_CURRENCY,    0, offset(MUT_ChrWToFpu), offset(MUT_FpuToR8)}
MUTATION_ENTRY {FDT_CHAR_WIDE,  FDT_CHAR_WIDE,   0, offset(MUT_CopyDataFillW), NULL}
MUTATION_ENTRY {FDT_CHAR_WIDE,  FDT_CHAR_UTF8,   0, offset(MUT_ChrWToBuf), offset(MUT_BufToChr8)}
MUTATION_ENTRY {FDT_CHAR_WIDE,  FDT_TIMESTAMP,   0, offset(MUT_ChrWToFpu), offset(MUT_FpuToTimestamp)}
MUTATION_ENTRY {FDT_CHAR_WIDE,  FDT_AUTOINC,     0, offset(MUT_ChrWToFpu), offset(MUT_FpuToInt32)}
;MUTATION_ENTRY {FDT_CHAR_UTF8,  FDT_BINARY,      0, offset(MUT_FillBlank), NULL}
MUTATION_ENTRY {FDT_CHAR_UTF8,  FDT_CHAR_ANSI,   0, offset(MUT_Chr8ToBuf), offset(MUT_BufToChrFillA)}
MUTATION_ENTRY {FDT_CHAR_UTF8,  FDT_DATE,        0, offset(MUT_Chr8ToFpu), offset(MUT_FpuToDate)}
MUTATION_ENTRY {FDT_CHAR_UTF8,  FDT_REAL4,       0, offset(MUT_Chr8ToFpu), offset(MUT_FpuToR4)}
;MUTATION_ENTRY {FDT_CHAR_UTF8,  FDT_OLE,         0, offset(MUT_FillBlank), NULL}
MUTATION_ENTRY {FDT_CHAR_UTF8,  FDT_SDWORD,      0, offset(MUT_Chr8ToFpu), offset(MUT_FpuToInt32)}
MUTATION_ENTRY {FDT_CHAR_UTF8,  FDT_BOOL,        0, offset(MUT_Chr8ToFpu), offset(MUT_FpuToBool)}
MUTATION_ENTRY {FDT_CHAR_UTF8,  FDT_MEMO_ANSI,    0, offset(MUT_Chr8ToBuf), offset(MUT_BufToMemo)}
MUTATION_ENTRY {FDT_CHAR_UTF8,  FDT_NUMERIC,     0, offset(MUT_Chr8ToFpu), offset(MUT_FpuToNum)}
MUTATION_ENTRY {FDT_CHAR_UTF8,  FDT_REAL8,       0, offset(MUT_Chr8ToFpu), offset(MUT_FpuToR8)}
MUTATION_ENTRY {FDT_CHAR_UTF8,  FDT_REAL10,      0, offset(MUT_Chr8ToFpu), offset(MUT_FpuToR10)}
MUTATION_ENTRY {FDT_CHAR_UTF8,  FDT_CURRENCY,    0, offset(MUT_Chr8ToFpu), offset(MUT_FpuToR8)}
MUTATION_ENTRY {FDT_CHAR_UTF8,  FDT_CHAR_WIDE,   0, offset(MUT_Chr8ToBuf), offset(MUT_BufToChrFillW)}
MUTATION_ENTRY {FDT_CHAR_UTF8,  FDT_CHAR_UTF8,   0, offset(MUT_CopyDataFillA), NULL}
MUTATION_ENTRY {FDT_CHAR_UTF8,  FDT_TIMESTAMP,   0, offset(MUT_Chr8ToFpu), offset(MUT_FpuToTimestamp)}
MUTATION_ENTRY {FDT_CHAR_UTF8,  FDT_AUTOINC,     0, offset(MUT_Chr8ToFpu), offset(MUT_FpuToInt32)}
;MUTATION_ENTRY {FDT_TIMESTAMP,  FDT_BINARY,      0, offset(MUT_FillBlank), NULL}
MUTATION_ENTRY {FDT_TIMESTAMP,  FDT_CHAR_ANSI,   0, offset(MUT_TimestampToFpu), offset(MUT_FpuToChrA)}
MUTATION_ENTRY {FDT_TIMESTAMP,  FDT_DATE,        0, offset(MUT_TimestampToFpu), offset(MUT_FpuToDate)}
MUTATION_ENTRY {FDT_TIMESTAMP,  FDT_REAL4,       0, offset(MUT_TimestampToFpu), offset(MUT_FpuToR4)}
;MUTATION_ENTRY {FDT_TIMESTAMP,  FDT_OLE,         0, offset(MUT_FillBlank), NULL}
MUTATION_ENTRY {FDT_TIMESTAMP,  FDT_SDWORD,      0, offset(MUT_TimestampToFpu), offset(MUT_FpuToInt32)}
;MUTATION_ENTRY {FDT_TIMESTAMP,  FDT_BOOL,        0, offset(MUT_FillBlank), NULL}
;MUTATION_ENTRY {FDT_TIMESTAMP,  FDT_MEMO_ANSI,   0, offset(MUT_FillBlank), NULL}
MUTATION_ENTRY {FDT_TIMESTAMP,  FDT_NUMERIC,     0, offset(MUT_TimestampToFpu), offset(MUT_FpuToNum)}
MUTATION_ENTRY {FDT_TIMESTAMP,  FDT_REAL8,       0, offset(MUT_TimestampToFpu), offset(MUT_FpuToR8)}
MUTATION_ENTRY {FDT_TIMESTAMP,  FDT_REAL10,      0, offset(MUT_TimestampToFpu), offset(MUT_FpuToR10)}
;MUTATION_ENTRY {FDT_TIMESTAMP,  FDT_CURRENCY,    0, offset(MUT_FillBlank), NULL}
MUTATION_ENTRY {FDT_TIMESTAMP,  FDT_CHAR_WIDE,   0, offset(MUT_TimestampToFpu), offset(MUT_FpuToR8)}
MUTATION_ENTRY {FDT_TIMESTAMP,  FDT_CHAR_UTF8,   0, offset(MUT_TimestampToFpu), offset(MUT_FpuToChr8)}
MUTATION_ENTRY {FDT_TIMESTAMP,  FDT_TIMESTAMP,   0, offset(MUT_CopyDataFillA), NULL}
;MUTATION_ENTRY {FDT_TIMESTAMP,  FDT_AUTOINC,     0, offset(MUT_FillBlank), NULL}
;MUTATION_ENTRY {FDT_AUTOINC,    FDT_BINARY,      0, offset(MUT_FillBlank), NULL}
MUTATION_ENTRY {FDT_AUTOINC,    FDT_CHAR_ANSI,   0, offset(MUT_UInt32ToFpu), offset(MUT_FpuToChrA)}
;MUTATION_ENTRY {FDT_AUTOINC,    FDT_DATE,        0, offset(MUT_FillBlank), NULL}
MUTATION_ENTRY {FDT_AUTOINC,    FDT_REAL4,       0, offset(MUT_UInt32ToFpu), offset(MUT_FpuToR4)}
;MUTATION_ENTRY {FDT_AUTOINC,    FDT_OLE,         0, offset(MUT_FillBlank), NULL}
MUTATION_ENTRY {FDT_AUTOINC,    FDT_SDWORD,      0, offset(MUT_CopyDataFillA), NULL}
;MUTATION_ENTRY {FDT_AUTOINC,    FDT_BOOL,        0, offset(MUT_FillBlank), NULL}
;MUTATION_ENTRY {FDT_AUTOINC,    FDT_MEMO_ANSI,   0, offset(MUT_FillBlank), NULL}
MUTATION_ENTRY {FDT_AUTOINC,    FDT_NUMERIC,     0, offset(MUT_Int32ToFpu), offset(MUT_FpuToNum)}
MUTATION_ENTRY {FDT_AUTOINC,    FDT_REAL8,       0, offset(MUT_UInt32ToFpu), offset(MUT_FpuToChr8)}
MUTATION_ENTRY {FDT_AUTOINC,    FDT_REAL10,      0, offset(MUT_UInt32ToFpu), offset(MUT_FpuToR10)}
;MUTATION_ENTRY {FDT_AUTOINC,    FDT_CURRENCY,    0, offset(MUT_FillBlank), NULL}
MUTATION_ENTRY {FDT_AUTOINC,    FDT_CHAR_WIDE,   0, offset(MUT_UInt32ToFpu), offset(MUT_FpuToChrW)}
MUTATION_ENTRY {FDT_AUTOINC,    FDT_CHAR_UTF8,   0, offset(MUT_UInt32ToFpu), offset(MUT_FpuToChr8)}
;MUTATION_ENTRY {FDT_AUTOINC,    FDT_TIMESTAMP,   0, offset(MUT_FillBlank), NULL}
MUTATION_ENTRY {FDT_AUTOINC,    FDT_AUTOINC,     0, offset(MUT_CopyDataFillA), NULL}
;MUTATION_ENTRY {FDT_MEMO_ANSI,  FDT_BINARY,      0, offset(MUT_FillBlank), NULL}
;MUTATION_ENTRY {FDT_MEMO_ANSI,  FDT_CHAR_ANSI,   0, offset(MUT_FillBlank), NULL}
;MUTATION_ENTRY {FDT_MEMO_ANSI,  FDT_DATE,        0, offset(MUT_FillBlank), NULL}
;MUTATION_ENTRY {FDT_MEMO_ANSI,  FDT_REAL4,       0, offset(MUT_FillBlank), NULL}
;MUTATION_ENTRY {FDT_MEMO_ANSI,  FDT_OLE,         0, offset(MUT_FillBlank), NULL}
;MUTATION_ENTRY {FDT_MEMO_ANSI,  FDT_SDWORD,      0, offset(MUT_FillBlank), NULL}
;MUTATION_ENTRY {FDT_MEMO_ANSI,  FDT_BOOL,        0, offset(MUT_FillBlank), NULL}
MUTATION_ENTRY {FDT_MEMO_ANSI,  FDT_MEMO_ANSI,        0, offset(MUT_CopyData), NULL}
;MUTATION_ENTRY {FDT_MEMO_ANSI,  FDT_NUMERIC,     0, offset(MUT_FillBlank), NULL}
;MUTATION_ENTRY {FDT_MEMO_ANSI,  FDT_REAL8,       0, offset(MUT_FillBlank), NULL}
;MUTATION_ENTRY {FDT_MEMO_ANSI,  FDT_REAL10,      0, offset(MUT_FillBlank), NULL}
;MUTATION_ENTRY {FDT_MEMO_ANSI,  FDT_CURRENCY,    0, offset(MUT_FillBlank), NULL}
;MUTATION_ENTRY {FDT_MEMO_ANSI,  FDT_CHAR_WIDE,   0, offset(MUT_FillBlank), NULL}
;MUTATION_ENTRY {FDT_MEMO_ANSI,  FDT_CHAR_UTF8,   0, offset(MUT_FillBlank), NULL}
;MUTATION_ENTRY {FDT_MEMO_ANSI,  FDT_TIMESTAMP,   0, offset(MUT_FillBlank), NULL}
;MUTATION_ENTRY {FDT_MEMO_ANSI,  FDT_AUTOINC,     0, offset(MUT_FillBlank), NULL}
;MUTATION_ENTRY {FDT_OLE,        FDT_BINARY,      0, offset(MUT_FillBlank), NULL}
;MUTATION_ENTRY {FDT_OLE,        FDT_CHAR_ANSI,   0, offset(MUT_FillBlank), NULL}
;MUTATION_ENTRY {FDT_OLE,        FDT_DATE,        0, offset(MUT_FillBlank), NULL}
;MUTATION_ENTRY {FDT_OLE,        FDT_REAL4,       0, offset(MUT_FillBlank), NULL}
MUTATION_ENTRY {FDT_OLE,        FDT_OLE,         0, offset(MUT_CopyData), NULL}
;MUTATION_ENTRY {FDT_OLE,        FDT_SDWORD,      0, offset(MUT_FillBlank), NULL}
;MUTATION_ENTRY {FDT_OLE,        FDT_BOOL,        0, offset(MUT_FillBlank), NULL}
;MUTATION_ENTRY {FDT_OLE,        FDT_MEMO_ANSI,   0, offset(MUT_FillBlank), NULL}
;MUTATION_ENTRY {FDT_OLE,        FDT_NUMERIC,     0, offset(MUT_FillBlank), NULL}
;MUTATION_ENTRY {FDT_OLE,        FDT_REAL8,       0, offset(MUT_FillBlank), NULL}
;MUTATION_ENTRY {FDT_OLE,        FDT_REAL10,      0, offset(MUT_FillBlank), NULL}
;MUTATION_ENTRY {FDT_OLE,        FDT_CURRENCY,    0, offset(MUT_FillBlank), NULL}
;MUTATION_ENTRY {FDT_OLE,        FDT_CHAR_WIDE,   0, offset(MUT_FillBlank), NULL}
;MUTATION_ENTRY {FDT_OLE,        FDT_CHAR_UTF8,   0, offset(MUT_FillBlank), NULL}
;MUTATION_ENTRY {FDT_OLE,        FDT_TIMESTAMP,   0, offset(MUT_FillBlank), NULL}
;MUTATION_ENTRY {FDT_OLE,        FDT_AUTOINC,     0, offset(MUT_FillBlank), NULL}
WORD 0

.code
Method DB_StructEditorDlg.Mutate, uses xbx xdi xsi
  local pEditorLine:$ObjPtr(DB_StructEditorLine), ProgDlg:$Obj(DialogProgress)
  local dDataMutation:DWORD, dIndexUpdateCount:DWORD, dTaskCount:DWORD, dChanges:DWORD
  local cBuffer[LOCAL_BUFFER_SIZE]:CHR, bBuffer[LOCAL_BUFFER_SIZE]:CHRA
  local bMsgBuffer[LOCAL_BUFFER_SIZE]:CHRA

  SetObject xsi
  ;Get the number of necessary TaskSetup structures and get all changes
  mov dDataMutation, FALSE
  mov dIndexUpdateCount, 0
  mov dChanges, 0
  mov xdi, [xsi].pStructEditor
  xor ebx, ebx
  .while ebx != [xdi].$Obj(DB_StructEditor).EditorLines.dCount
    OCall [xdi].$Obj(DB_StructEditor).EditorLines::Collection.ItemAt, ebx
    mov ecx, [xax].$Obj(DB_StructEditorLine).dFlags
    or dChanges, ecx
    .ifBitSet ecx, SEL_FLAG_CHANGE_DATA or SEL_FLAG_CHANGE_POS
      mov dDataMutation, TRUE
    .endif
    invoke SendMessage, [xax].$Obj(DB_StructEditorLine).hEdtFieldIndex, WM_GETTEXTLENGTH, 0, 0
    .if eax != 0
      inc dIndexUpdateCount
    .endif
    inc ebx
  .endw

  mov xdx, [xsi].pTable
  mov ecx, [xdx].$Obj(DB_Table).Fields.dCount
  .if ecx != [xdi].$Obj(DB_StructEditor).EditorLines.dCount
    mov dDataMutation, TRUE
    or dChanges, SEL_FLAG_CHANGE_POS                    ;Set if the counts are different
  .endif

  mov dTaskCount, 0
  .if dDataMutation != FALSE
    inc dTaskCount
  .endif
  mov ecx, dIndexUpdateCount
  add dTaskCount, ecx

  and dChanges, SEL_FLAG_CHANGE_ANY
  jz @@EOM

  mov eax, dTaskCount
  .if eax != 0
    imul eax, sizeof(TaskSetup)
    add eax, sizeof(TaskHeader)
    MemAlloc eax
    .if xax == NULL
      OCall xsi.ErrorReport, NULL, DB_OUT_OF_MEMORY
      DbgWarning "DB_StructEditorDlg.Mutate: Out of memory creating TaskSetups", \
                 offset(szDbgObjErr)
      ExitMethod
    .endif
    mov [xsi].pMemTasks, xax
    mov xdi, xax

    ;Set Task header
    m2m [xdi].TaskHeader.dTaskCount, dTaskCount, eax
    c2m [xdi].TaskHeader.pMainDesc, $OfsCStrA("{\rtf1\sa50\fs19\b Description:\b0", \
        "\par\fs18 The table data are changed and/or rearrenged according to the new ", \
        "structure setup and affected indexes are updated.}"), xax
    c2m [xdi].TaskHeader.pOverallDesc, $OfsCStrA("{\rtf1\b Overall progress:\b0}"), xax
    mov [xdi].TaskHeader.hIcon, $invoke(LoadImage, hInstance, $OfsCStr("ICON_MUTATION"), \
                                        IMAGE_ICON, 0, 0, LR_DEFAULTCOLOR)
    add xdi, sizeof(TaskHeader)

    ;FIRST set data mutation TaskSetup
    .if dDataMutation != FALSE
      m2m [xdi].TaskSetup.pTaskProc, $MethodAddr(DB_StructEditorDlg.MutateData), xax
      mov [xdi].TaskSetup.pOwner, xsi
      mov [xdi].TaskSetup.xParam1, 0
      mov [xdi].TaskSetup.xParam2, 0
      ProgressText textequ <{\rtf1\b Task:\b0  Data on table \ul >
      FillTextA cBuffer, <%ProgressText>
      mov xdx, [xsi].pTable
      invoke PathFindFileName, [xdx].$Obj(DB_Table).pFileName
      lea xcx, [cBuffer + @SizeStr(%ProgressText)]
      if TARGET_STR_TYPE eq STR_TYPE_ANSI
        invoke StrECopy, xcx, xax
      else
        invoke StrW2StrA, xcx, xax
        invoke StrEndA, addr cBuffer
      endif
      FillStringA [xax], <\ul0  is being modified...}>
      mov [xdi].TaskSetup.pDescription, $invoke(StrNewA, addr cBuffer)
      mov xcx, [xsi].pTable
      m2m [xdi].TaskSetup.dPrgCntMax, [xcx].$Obj(DB_Table).Descriptor.dNumRecs, eax
      add xdi, sizeof(TaskSetup)
    .else
      OCall xsi.CtlsGet                                 ;Read ctrls even if no data mutation is done
    .endif

    ;NOW set index TaskSetup
    xor ebx, ebx
    .while TRUE
      mov xax, [xsi].pStructEditor
      .break .if ebx == [xax].$Obj(DB_StructEditor).EditorLines.dCount
      OCall [xax].$Obj(DB_StructEditor).EditorLines::Collection.ItemAt, ebx
      mov pEditorLine, xax
      invoke SendMessage, [xax].$Obj(DB_StructEditorLine).hEdtFieldIndex, WM_GETTEXTLENGTH, 0, 0
      .if eax != 0
        mov xcx, pEditorLine
        invoke SendMessageA, [xcx].$Obj(DB_StructEditorLine).hEdtFieldIndex, WM_GETTEXT, \
                             LOCAL_BUFFER_SIZE, addr bBuffer
        invoke PathFindFileNameA, addr bBuffer

        mov [xdi].TaskSetup.pOwner, xsi
        m2m [xdi].TaskSetup.xParam1, pEditorLine, xcx   ;-> DB_StructEditorLine
        mov [xdi].TaskSetup.xParam2, xbx                ;Index

        ProgressText textequ <{\rtf1\b Task:\b0  Index \ul >
        FillTextA bMsgBuffer, <%ProgressText>
        lea xcx, [bMsgBuffer + @SizeStr(%ProgressText)]
        invoke StrECopyA, xcx, xax
        ProgressText textequ <\ul0  for table field >
        FillStringA [xax], <%ProgressText>
        mov xcx, pEditorLine
        invoke SendMessageA, [xcx].$Obj(DB_StructEditorLine).hEdtFieldName, WM_GETTEXT, \
                             DB_FIELD_NAME_SIZE, addr [xax + @SizeStr(%ProgressText)]
        invoke StrEndA, addr bMsgBuffer

        ;Note: SEL_FLAG_CHANGE_NAME could be handled changing only a field in the index header
        mov xcx, pEditorLine
        .ifBitSet [xcx].$Obj(DB_StructEditorLine).dFlags, SEL_FLAG_CHANGE_DATA or SEL_FLAG_CHANGE_INDEX
          FillStringA [xax], < is being updated...}>
          m2m [xdi].TaskSetup.pTaskProc, $MethodAddr(DB_StructEditorDlg.RebuildIndex), xax
          mov xcx, [xsi].pTable
          mov eax, [xcx].$Obj(DB_Table).Descriptor.dNumRecs
          add eax, eax                                  ;Best guess
        .else
          FillStringA [xax], <\ul0  is being opened...}>
          m2m [xdi].TaskSetup.pTaskProc, $MethodAddr(DB_StructEditorDlg.ReopenIndex), xax
          xor eax, eax
        .endif
        mov [xdi].TaskSetup.dPrgCntMax, eax
        mov [xdi].TaskSetup.pDescription, $invoke(StrNewA, addr bMsgBuffer)
        add xdi, sizeof(TaskSetup)
      .endif
      inc ebx
    .endw

    ;Invoke Progress dialog
    New ProgDlg::DialogProgress
    OCall ProgDlg::DialogProgress.Init, xsi, [xsi].hWnd, [xsi].pMemTasks
    OCall ProgDlg::DialogProgress.Show
    OCall ProgDlg::DialogProgress.Done

    ;Free resources
    mov xdi, [xsi].pMemTasks
  ;  invoke StrDisposeA, [xdi].TaskHeader.pMainDesc
  ;  invoke StrDisposeA, [xdi].TaskHeader.pOverallDesc
    invoke DestroyIcon, [xdi].TaskHeader.hIcon
    add xdi, sizeof(TaskHeader)                         ;Skip the overall setup
    xor ebx, ebx
    .while ebx < dTaskCount
      invoke StrDispose, [xdi].TaskSetup.pDescription   ;Does nothing if argument is NULL
      inc ebx
      add xdi, sizeof(TaskSetup)                        ;Move to next taskSetup
    .endw
    MemFree [xsi].pMemTasks
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     DB_StructEditorDlg.MutateData
; Purpose:    Table data mutation.
; Arguments:  Arg1: -> TaskStatus.
;             Arg2: unused argument.
;             Arg3: unused argument.
; Return:     Nothing.

Method DB_StructEditorDlg.MutateData, uses xbx xdi xsi, pStatus:PTaskStatus, Arg1:XWORD, Arg2:XWORD
  local hTempFile:HANDLE, dBytesRead:DWORD, dBytesWritten:DWORD, dAutoInc:DWORD, qNow:QWORD
  local dRecNo:DB_DATA_LINK_TYPE, dLastRecNo:DB_DATA_LINK_TYPE, dFieldNo:DWORD
  local wBufferIn[LOCAL_BUFFER_SIZE]:CHRW, wBufferOut[LOCAL_BUFFER_SIZE]:CHRW
  local pCopyBuffer:POINTER, pRecordBuffer:POINTER, dNewRecordLength:DWORD, pRecPos:POINTER
  local pStructEditorLine:$ObjPtr(DB_StructEditorLine)

;  DbgText "DB_StructEditorDlg.MutateData"
  SetObject xsi

  ;Read mutation information and detect if there were changes in the table structure
  OCall [xsi].pStructEditor::DB_StructEditor.CtlsRead
  mov xax, [xsi].pTable
  mov dFieldNo, 0
  mov dNewRecordLength, 1                               ;Deletion mark
  assume xbx:PMUTATION_ENTRY
  .repeat
    mov eax, dFieldNo
    mov xcx, [xsi].pStructEditor
    .break .if eax >= [xcx].$Obj(DB_StructEditor).EditorLines.dCount
    OCall [xcx].$Obj(DB_StructEditor).EditorLines::Collection.ItemAt, eax
    movzx ecx, [xax].$Obj(DB_StructEditorLine).MutationInfo.bActLength
    add dNewRecordLength, ecx
    mov xbx, offset(MutationLUT)
    mov cl, [xax].$Obj(DB_StructEditorLine).MutationInfo.bPrvType
    mov ch, [xax].$Obj(DB_StructEditorLine).MutationInfo.bActType
    lea xdi, [xax].$Obj(DB_StructEditorLine).MutationInfo
    .repeat
      mov dx, WORD ptr [xbx]
      .if dx == 0
        ;Not found  => fill with blanks
        mov xcx, offset(MUT_FillBlank)
        mov [xax].$Obj(DB_StructEditorLine).MutationInfo.pInProc, xcx
        mov [xax].$Obj(DB_StructEditorLine).MutationInfo.pOutProc, NULL
        mov [xax].$Obj(DB_StructEditorLine).MutationInfo.wFlags, 0
        .break
      .endif
      .if cx == dx
        m2m [xax].$Obj(DB_StructEditorLine).MutationInfo.pInProc, [xbx].pInProc, xcx
        m2m [xax].$Obj(DB_StructEditorLine).MutationInfo.pOutProc, [xbx].pOutProc, xdx
        m2m [xax].$Obj(DB_StructEditorLine).MutationInfo.wFlags, [xbx].wFlags, cx
        .break
      .endif
      add xbx, sizeof(MUTATION_ENTRY)
    .until FALSE
    inc dFieldNo
  .until FALSE
  assume xbx:NOTHING

  MemAlloc dNewRecordLength
  .if xax == NULL
    OCall xsi.ErrorReport, NULL, DB_OUT_OF_MEMORY
    DbgWarning "DB_StructEditorDlg.MutationJob: Out of memory creating a record buffer", \
               offset(szDbgObjErr)
    mov xax, pStatus
    BitSet [xax].TaskStatus.dFlags, TSF_TASK_ERROR
    ExitMethod
  .endif
  mov pRecordBuffer, xax

  invoke CreateTempFile
  .if xax == INVALID_HANDLE_VALUE
    OCall xsi.ErrorReport, NULL, DB_INVALID_TEMPFILE
    DbgWarning "DB_StructEditorDlg.MutationJob: failed to create a temp file", \
               offset(szDbgObjErr)
    mov xax, pStatus
    BitSet [xax].TaskStatus.dFlags, TSF_TASK_ERROR
    jmp @@End
  .endif
  mov hTempFile, xax

  mov xcx, [xsi].pTable
  m2m dLastRecNo, [xcx].$Obj(DB_Table).Descriptor.dNumRecs, eax

  ;Mutate all records
  mov dRecNo, 0
  .repeat
    m2m pRecPos, pRecordBuffer, xax
    mov xax, pStatus
    .ifBitSet [xax].TaskStatus.dFlags, TSF_THREAD_CANCEL
      BitSet [xax].TaskStatus.dFlags, TSF_TASK_CANCELED
      jmp @@CloseTempFile
    .endif
    inc dRecNo
    mov eax, dRecNo
    .break .if eax > dLastRecNo

    ;Write Delete mark
    OCall [xsi].pTable::DB_Table.Deleted?, dRecNo
    mov xdx, pRecPos
    .if ecx == FALSE
      mov CHRA ptr [xdx], " "
    .else
      mov CHRA ptr [xdx], "*"
    .endif
    inc pRecPos

    ;Begin record mutation
    mov dFieldNo, 0
    .repeat
      mov eax, dFieldNo
      mov xcx, [xsi].pStructEditor
      .break .if eax >= [xcx].$Obj(DB_StructEditor).EditorLines.dCount
      OCall [xcx].$Obj(DB_StructEditor).EditorLines::Collection.ItemAt, eax
      mov xbx, xax                                      ;xbx -> DB_StructEditorLine
      lea xdi, [xbx].$Obj(DB_StructEditorLine).MutationInfo
      mov eax, [xbx].$Obj(DB_StructEditorLine).dPrvFieldPos
      .if eax == -1
        invoke DB_GetStdFieldInfo, [xdi].FIELD_MUTATION.bActType
        mov cl, [xax].STD_FIELD_INFO.bFillType
        .if cl == SFM_ZERO
          lea xdx, bZeros
        .elseif cl == SFM_BLANKA
          lea xdx, bBlanks
        .elseif cl == SFM_BLANKW
          lea xdx, wBlanks
        .elseif cl == SFM_LOGIC
          lea xdx, bLogic
        .elseif cl == SFM_AUTOINC
          m2m dAutoInc, [xdi].FIELD_MUTATION.dActParam, xax
          inc [xdi].FIELD_MUTATION.dActParam
          lea xdx, dAutoInc
        .elseif cl == SFM_NOW
          invoke DB_NowToTimestamp, addr qNow
          lea xdx, qNow
        .endif
      .else
        OCall [xsi].pTable::DB_Table.DataGetFrom, dRecNo, eax
        .if eax != OBJ_OK
          OCall xsi.ErrorReport, NULL, DB_READ_ERROR
          DbgWarning "DB_StructEditorDlg.MutationJob: failed to read a record", \
                     offset(szDbgObjErr)
          mov xax, pStatus
          BitSet [xax].TaskStatus.dFlags, TSF_TASK_ERROR
          jmp @@CloseTempFile
        .endif
        mov xdx, xcx                                    ;xdx -> Field data
        .ifBitSet [xbx].$Obj(DB_StructEditorLine).dFlags, SEL_FLAG_CHANGE_TYPE or \
                                                          SEL_FLAG_CHANGE_LENGTH or \
                                                          SEL_FLAG_CHANGE_PARAM
          mov xax, [xdi].FIELD_MUTATION.pInProc
          .if xax != NULL
            lea xcx, wBufferIn
            invoke PMutInProc ptr xax, xcx, xdx, xdi
            .if eax != 0                                ;0: OK => continue, otherwise fill w/blanks
              lea xdx, bBlanks
              jmp @F
            .endif
          .endif
          mov xax, [xdi].FIELD_MUTATION.pOutProc
          lea xdx, wBufferIn
          .if xax != NULL
            lea xcx, wBufferOut
            invoke PMutOutProc ptr xax, xcx, xdx, xdi
            .if eax == 0
              lea xdx, wBufferOut
            .else
              lea xdx, bBlanks
            .endif
          .endif
        .endif
      .endif
    @@:
      movzx ebx, [xbx].$Obj(DB_StructEditorLine).MutationInfo.bActLength
      invoke MemClone, pRecPos, xdx, ebx
      add pRecPos, xbx
      inc dFieldNo
    .until FALSE
    invoke WriteFile, hTempFile, pRecordBuffer, dNewRecordLength, addr dBytesWritten, NULL

    ;Update progress information
    mov xax, pStatus
    m2m [xax].TaskStatus.dCurPrgCnt, dRecNo, ecx
  .until FALSE
  MemFree pRecordBuffer

  ;Update changes comming from AutoInc fields
  mov dFieldNo, 0
  lea xdi, wBufferIn                                    ;Reuse this buffer
  .repeat
    mov eax, dFieldNo
    mov xcx, [xsi].pStructEditor
    .break .if eax == [xcx].$Obj(DB_StructEditor).EditorLines.dCount
    OCall [xcx].$Obj(DB_StructEditor).EditorLines::Collection.ItemAt, dFieldNo
    mov pStructEditorLine, xax
    .if [xax].$Obj(DB_StructEditorLine).dPrvFieldPos == -1  ;Is this StructEditorLine new?
      .if [xax].$Obj(DB_StructEditorLine).MutationInfo.bActType == FDT_AUTOINC
        mov xbx, xax                                    ;xbx -> DB_StructEditorLine
        invoke dword2dec, xdi, [xbx].$Obj(DB_StructEditorLine).MutationInfo.dActParam
        invoke SetWindowText, [xbx].$Obj(DB_StructEditorLine).hEdtFieldParam, xdi
        invoke DB_GetStdFieldInfo, FDT_AUTOINC
        .ifBitSet [xax].STD_FIELD_INFO.bFlags, SFF_READ_ONLY
          invoke EnableWindow, [xbx].$Obj(DB_StructEditorLine).hEdtFieldParam, FALSE
        .endif
      .endif
    .endif
    inc dFieldNo
  .until FALSE

  ;Flush and dispose all old records.
  mov xbx, [xsi].pTable
  OCall [xbx].$Obj(DB_Table).Records::DB_RecordCache.DisposeAll

  ;Update table fields
  OCall xsi.CtlsGet

  ;Copy the new content on the temp file to the table file.
  MemAlloc COPY_BUFFER_SIZE
  .if xax == NULL
    OCall xsi.ErrorReport, NULL, DB_OUT_OF_MEMORY
    DbgWarning "DB_StructEditorDlg.MutationJob: Out of memory creating a copy buffer", \
               offset(szDbgObjErr)
    mov xax, pStatus
    BitSet [xax].TaskStatus.dFlags, TSF_TASK_ERROR
    jmp @@CloseTempFile
  .endif
  mov pCopyBuffer, xax

  invoke SetFilePointerEx, hTempFile, 0, NULL, FILE_BEGIN
  movzx eax, [xbx].$Obj(DB_Table).Descriptor.wHeaderLen
  if TARGET_BITNESS eq 32
    xor edx, edx
    invoke SetFilePointerEx, [xbx].$Obj(DB_Table).hFile, edx::eax, NULL, FILE_BEGIN
  else
    invoke SetFilePointerEx, [xbx].$Obj(DB_Table).hFile, rax, NULL, FILE_BEGIN
  endif
  movzx xax, [xbx].$Obj(DB_Table).Descriptor.wRecordLen
  mov ecx, [xbx].$Obj(DB_Table).Descriptor.dNumRecs
  mul xcx
  mov xdi, xax

  .while xdi >= COPY_BUFFER_SIZE
    invoke ReadFile, hTempFile, pCopyBuffer, COPY_BUFFER_SIZE, addr dBytesRead, NULL
    invoke WriteFile, [xbx].$Obj(DB_Table).hFile, pCopyBuffer, COPY_BUFFER_SIZE, \
                      addr dBytesWritten, NULL
    sub xdi, COPY_BUFFER_SIZE
  .endw
  .if !ZERO?
    invoke ReadFile, hTempFile, pCopyBuffer, edi, addr dBytesRead, NULL
    invoke WriteFile, [xbx].$Obj(DB_Table).hFile, pCopyBuffer, edi, addr dBytesWritten, NULL
  .endif
  invoke SetEndOfFile, [xbx].$Obj(DB_Table).hFile

@@CloseTempFile:
  invoke CloseHandle, hTempFile
@@End:
  MemFree pCopyBuffer
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     DB_StructEditorDlg.OnCommand
; Purpose:    Event procedure for WM_COMMAND message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method DB_StructEditorDlg.OnCommand, uses xbx xdi xsi, wParam:WPARAM, lParam:LPARAM
  local pEditorLine:$ObjPtr(DB_StructEditorLine), EBT:EDITBALLOONTIP

  SetObject xsi
  mov xax, wParam
  .if ax == IDC_STRUC_BTN_APPEND
    New DB_StructEditorLine
    .if xax == NULL
      OCall xsi.ErrorReport, NULL, DB_OUT_OF_MEMORY
      DbgWarning "DB_StructEditorDlg.OnCommand: out of memory creating a DB_StructEditorLine", \
                 offset(szDbgObjErr)
    .else
      mov xdi, xax

      ;Increase the View
      mov xcx, [xsi].pStructEditor
      mov eax, [xcx].$Obj(DB_StructEditor).Separation.y
      add [xcx].$Obj(DB_StructEditor).ViewExtent.y, eax
      ;Move the origin if needed
      mov eax, [xcx].$Obj(DB_StructEditor).CtlSize.y
      .if eax < [xcx].$Obj(DB_StructEditor).ViewExtent.y
        sub eax, [xcx].$Obj(DB_StructEditor).ViewExtent.y
        mov [xcx].$Obj(DB_StructEditor).ViewOrigin.y, eax
      .endif
      ;Calculate the new max Y size of the dialog
      mov eax, [xcx].$Obj(DB_StructEditor).Separation.y
      add StrucDlgChildrenInfo.DL_HEADER.MaxSize.y, eax

      ;Initialize and insert the new DB_StructEditorLine
      lea xbx, [xcx].$Obj(DB_StructEditor).EditorLines
      OCall xdi::DB_StructEditorLine.Init, xbx
      OCall xbx::Collection.Insert, xdi
      OCall xdi::DB_StructEditorLine.CtlsSetDefaults
      mov [xdi].$Obj(DB_StructEditorLine).dFlags, SEL_FLAG_CHANGE_ANY

      ;Arrage all again
      OCall [xsi].pStructEditor::DB_StructEditor.Select, xdi
      OCall [xsi].pStructEditor::DB_StructEditor.CtlsMove

      ;Set a baloon notification
      mov EBT.cbStruct, sizeof(EDITBALLOONTIP)
      c2m EBT.pszTitle, $OfsCStrW("Field name:"), xax
      c2m EBT.pszText, $OfsCStrW("Enter max. 10 ANSI characters.", 13, \
                                 "An empty name is not allowed."), xcx
      mov EBT.ttiIcon, TTI_INFO
      invoke SendMessage, [xdi].$Obj(DB_StructEditorLine).hEdtFieldName, EM_SHOWBALLOONTIP, \
                          0, addr EBT
    .endif
    xor eax, eax

  .elseif ax == IDC_STRUC_BTN_DELETE
    xor eax, eax
    mov xdi, [xsi].pStructEditor
    mov xax, [xdi].$Obj(DB_StructEditor).pSelEditorLine
    .if xax != NULL
      mov ebx, $32($OCall([xdi].$Obj(DB_StructEditor).EditorLines::Collection.IndexOf, xax))
      OCall [xsi].pStructEditor::DB_StructEditor.Select, NULL
      OCall [xdi].$Obj(DB_StructEditor).EditorLines::Collection.DisposeAt, ebx

      ;Decrease the View
      mov xcx, [xsi].pStructEditor
      mov eax, [xcx].$Obj(DB_StructEditor).Separation.y
      sub [xcx].$Obj(DB_StructEditor).ViewExtent.y, eax
      ;Move the origin if needed
      mov eax, [xcx].$Obj(DB_StructEditor).CtlSize.y
      .if eax < [xcx].$Obj(DB_StructEditor).ViewExtent.y
        sub eax, [xcx].$Obj(DB_StructEditor).ViewExtent.y
        mov [xcx].$Obj(DB_StructEditor).ViewOrigin.y, eax
      .else
        mov [xcx].$Obj(DB_StructEditor).ViewOrigin.y, 0
      .endif
      ;Calculate the new max Y size of the dialog
      mov eax, [xcx].$Obj(DB_StructEditor).Separation.y
      sub StrucDlgChildrenInfo.DL_HEADER.MaxSize.y, eax

      ;Check Status of all following EditorLines
      .while ebx < [xdi].$Obj(DB_StructEditor).EditorLines.dCount
        mov pEditorLine, $OCall([xdi].$Obj(DB_StructEditor).EditorLines::Collection.ItemAt, ebx)
        OCall pEditorLine::DB_StructEditorLine.CheckChanges
        OCall pEditorLine::DB_StructEditorLine.DisplayInfo
        inc ebx
      .endw

      ;Arrage all again
      OCall [xsi].pStructEditor::DB_StructEditor.CtlsMove
    .endif

  .elseif ax == IDC_STRUC_BTN_APPLY
    OCall xsi.Mutate
    xor eax, eax

  .elseif ax == IDC_STRUC_BTN_OK
    OCall xsi.Mutate
    OCall xsi.DestroyDialog, wParam
    xor eax, eax

  .elseif ax == IDC_STRUC_EDT                           ;Notification from DB_StructEditor.Select
    OCall xsi.CtlsEnable

  .elseif ax == IDC_STRUC_BTN_CANCEL
    OCall xsi.DestroyDialog, wParam
    xor eax, eax                                      ;Return zero

  .else
    mov eax, 1
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     DB_StructEditorDlg.OnExitSizeMove
; Purpose:    Event procedure for WM_EXITSIZEMOVE message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     Nothing.

Method DB_StructEditorDlg.OnExitSizeMove, uses xsi, wParam:WPARAM, lParam:LPARAM
;  DbgText "DB_StructEditorDlg.OnExitSizeMove"
  SetObject xsi
  invoke SendMessage, [xsi].hWnd, DM_REPOSITION, 0, 0
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     DB_StructEditorDlg.OnInitDialog
; Purpose:    Event procedure for WM_INITDIALOG message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = TRUE to direct the system to set the keyboard focus to the control specified by
;             wParam. Otherwise, it should return FALSE to prevent the system from setting the
;             default keyboard focus.

.const
align ALIGN_DATA
StrucEditorDlgStatusbar DEF_STATUSBAR {IDC_STRUC_SBR, SBR_STYLE, 0, 1}
  DEF_STATUSBAR_PART {400, -2, 0, SBT_SUNKEN, NULL}     ;Table information

.code
Method DB_StructEditorDlg.OnInitDialog, uses xbx xdi xsi, wParam:WPARAM, lParam:LPARAM
  local CRect:RECT, WRect:RECT

;  DbgText "DB_StructEditorDlg.OnInitDialog"
  SetObject xsi
  c2m [xsi].pDynamicLayout, offset StrucDlgChildrenInfo, xcx

  invoke GetDlgItem, [xsi].hWnd, IDC_STRUC_EDT
  mov [xsi].pStructEditor, $invoke(SendMessage, xax, WM_GETOBJECTINSTANCE, 0, 0)
  mov [xax].$Obj(DB_StructEditor).pOwner, xsi
  OCall xax::DB_StructEditor.CtlsInit
  OCall [xsi].StatusBar::Statusbar.Init, xsi, [xsi].hWnd, offset(StrucEditorDlgStatusbar)

  ;Position the column labels according the new sizes
  invoke GetDlgItem, [xsi].hWnd, IDC_STRUC_EDT
  lea xdx, WRect
  invoke GetWindowRect, xax, xdx
  invoke ScreenToClient, [xsi].hWnd, addr WRect.left
  mov xdi, [xsi].pStructEditor
  assume xdi:$ObjPtr(DB_StructEditor)
  mov ebx, WRect.left
  mov eax, [xdi].EdtSize.y
  sub WRect.top, eax
  add ebx, [xdi].InfoSize.x
  add ebx, [xdi].Separation.x
  invoke GetDlgItem, [xsi].hWnd, IDC_STRUC_STC_NAME
  invoke SetWindowPos, xax, 0, ebx, WRect.top, 0, 0, SWP_NOSIZE or SWP_NOZORDER
  add ebx, [xdi].dFldNameWidth
  add ebx, [xdi].Separation.x
  invoke GetDlgItem, [xsi].hWnd, IDC_STRUC_STC_TYPE
  invoke SetWindowPos, xax, 0, ebx, WRect.top, 0, 0, SWP_NOSIZE or SWP_NOZORDER
  add ebx, [xdi].dFldTypeWidth
  add ebx, [xdi].Separation.x
  invoke GetDlgItem, [xsi].hWnd, IDC_STRUC_STC_LENGTH
  invoke SetWindowPos, xax, 0, ebx, WRect.top, 0, 0, SWP_NOSIZE or SWP_NOZORDER
  add ebx, [xdi].dFldLengthWidth
  add ebx, [xdi].Separation.x
  invoke GetDlgItem, [xsi].hWnd, IDC_STRUC_STC_PARAM
  invoke SetWindowPos, xax, 0, ebx, WRect.top, 0, 0, SWP_NOSIZE or SWP_NOZORDER
  add ebx, [xdi].dFldParamWidth
  add ebx, [xdi].Separation.x
  invoke GetDlgItem, [xsi].hWnd, IDC_STRUC_STC_INDEX
  invoke SetWindowPos, xax, 0, ebx, WRect.top, 0, 0, SWP_NOSIZE or SWP_NOZORDER
  assume xdi:NOTHING

  ;Reposition dialog controls and set content
  ACall xsi.OnInitDialog, wParam, lParam

  ;Set the max Y size to the value when the DB_StructEditor is completely visible
  invoke GetClientRect, [xsi].hWnd, addr CRect
  mov xcx, [xsi].pStructEditor
  mov eax, CRect.bottom
  sub eax, [xcx].$Obj(DB_StructEditor).CtlSize.y
  add eax, [xcx].$Obj(DB_StructEditor).ViewExtent.y
  mov StrucDlgChildrenInfo.DL_HEADER.MaxSize.y, eax

  OCall xsi.CtlsEnable                                  ;Set the enable status of the dialog ctls
  OCall xsi.UpdateStatusbar

  mov eax, TRUE                                         ;Let Windows set the default keyboard focus
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     DB_StructEditorDlg.OnSize
; Purpose:    Event procedure for WM_SIZE message.
; Arguments:  Arg1: First message parameter. wParam = SIZE_xxx
;             Arg2: Second message parameter. lParam = POINTS containing client area size.
; Return:     eax = Zero if handled.

Method DB_StructEditorDlg.OnSize, uses xsi, wParam:WPARAM, lParam:LPARAM
  local EditorRect:RECT

;  DbgText "DB_StructEditorDlg.OnSize"
  SetObject xsi
  ACall xsi.OnSize, wParam, lParam

  ;Forward the message to the structure editor control control.
  mov xcx, [xsi].pStructEditor
  invoke GetClientRect, [xcx].$Obj(DB_StructEditor).hWnd, addr EditorRect
  mov ecx, EditorRect.right
  mov eax, EditorRect.bottom
  shl eax, 16
  mov ax, cx
  invoke SendDlgItemMessage, [xsi].hWnd, IDC_STRUC_EDT, WM_SIZE, SIZE_RESTORED, xax

  xor eax, eax
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     DB_StructEditorDlg.OnVScroll
; Purpose:    Event procedure for WM_VSCROLL message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     Nothing.

Method DB_StructEditorDlg.OnVScroll, uses xbx xdi xsi, wParam:WPARAM, lParam:LPARAM
  local dPosition:DWORD

;  DbgText "DB_StructEditorDlg.OnVScroll"
  SetObject xsi
  mov xdi, [xsi].pStructEditor
  mov xbx, [xdi].$Obj(DB_StructEditor).pSelEditorLine
  .if xbx != NULL
    invoke GetDlgItem, [xsi].hWnd, IDC_STRUC_SCB_UP_DOWN
    .if xax == lParam && [xdi].$Obj(DB_StructEditor).EditorLines.dCount > 1
      .if wParam == SB_LINEUP
        OCall [xdi].$Obj(DB_StructEditor).EditorLines::Collection.IndexOf, xbx
        .if eax > 0
          dec eax
          mov dPosition, eax

          OCall [xdi].$Obj(DB_StructEditor).EditorLines::Collection.Delete, xbx
          OCall [xdi].$Obj(DB_StructEditor).EditorLines::Collection.InsertAt, dPosition, xbx
          OCall xbx::DB_StructEditorLine.CheckChanges
          OCall xbx::DB_StructEditorLine.DisplayInfo

          mov eax, dPosition
          inc eax
          mov xbx, $OCall([xdi].$Obj(DB_StructEditor).EditorLines::Collection.ItemAt, eax)
          OCall xbx::DB_StructEditorLine.CheckChanges
          OCall xbx::DB_StructEditorLine.DisplayInfo

          OCall xdi::DB_StructEditor.CtlsMove
        .endif
      .elseif wParam == SB_LINEDOWN
        OCall [xdi].$Obj(DB_StructEditor).EditorLines::Collection.IndexOf, xbx
        mov ecx, [xdi].$Obj(DB_StructEditor).EditorLines.dCount
        dec ecx
        .if eax < ecx
          inc eax
          mov dPosition, eax

          OCall [xdi].$Obj(DB_StructEditor).EditorLines::Collection.Delete, xbx
          OCall [xdi].$Obj(DB_StructEditor).EditorLines::Collection.InsertAt, dPosition, xbx
          OCall xbx::DB_StructEditorLine.CheckChanges
          OCall xbx::DB_StructEditorLine.DisplayInfo

          mov eax, dPosition
          dec eax
          mov xbx, $OCall([xdi].$Obj(DB_StructEditor).EditorLines::Collection.ItemAt, eax)
          OCall xbx::DB_StructEditorLine.CheckChanges
          OCall xbx::DB_StructEditorLine.DisplayInfo

          OCall xdi::DB_StructEditor.CtlsMove
        .endif
      .endif
    .endif
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     DB_StructEditorDlg.RebuildIndex
; Purpose:    Table index mutation.
; Arguments:  Arg1: -> TaskStatus.
;             Arg2: -> DB_StructEditorLine.
;             Arg3: -> Field index.
; Return:     Nothing.

Method DB_StructEditorDlg.RebuildIndex, uses xbx xsi, pStatus:PTaskStatus, \
                                                      pEditorLine:$ObjPtr(DB_StructEditorLine), \
                                                      xFieldIndex:XWORD
  local pIndex:$ObjPtr(DB_Index), cBuffer[LOCAL_BUFFER_SIZE]:CHR

;  DbgText "DB_StructEditorDlg.RebuildIndex"
  SetObject xsi

  lea xbx, cBuffer
  mov xax, pEditorLine
  mov xcx, [xax].$Obj(DB_StructEditorLine).hEdtFieldIndex
  invoke GetWindowText, xcx, xbx, LOCAL_BUFFER_SIZE/sizeof(CHR)

  mov xax, pEditorLine
  New DB_Index
  .if xax == NULL
    OCall xsi.ErrorReport, NULL, DB_OUT_OF_MEMORY
    DbgWarning "DB_StructEditorDlg.RebuildIndex: Out of memory creating a DB_Index", \
               offset(szDbgObjErr)
    mov xax, pStatus
    BitSet [xax].TaskStatus.dFlags, TSF_TASK_ERROR
    ExitMethod
  .endif
  mov pIndex, xax
  mov xcx, [xsi].pTable
  OCall [xcx].$Obj(DB_Table).Fields::Collection.ItemAt, DWORD ptr xFieldIndex
  OCall pIndex::DB_Index.New, xax, xbx
  OCall pIndex::DB_Index.Reindex, pStatus
  .if eax == OBJ_OK
    mov xcx, pEditorLine
    m2m [xcx].$Obj(DB_StructEditorLine).pPrvFieldIndex, pIndex, xax
    BitClr [xcx].$Obj(DB_StructEditorLine).dFlags, SEL_FLAG_CHANGE_INDEX
    BitSet [xcx].$Obj(DB_StructEditorLine).dFlags, SEL_FLAG_CHANGES_SAVED
    OCall xcx::DB_StructEditorLine.DisplayInfo
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     DB_StructEditorDlg.ReopenIndex
; Purpose:    Table association of an existing index.
; Arguments:  Arg1: -> TaskStatus.
;             Arg2: -> DB_StructEditorLine.
;             Arg3: -> DB_Field.
; Return:     Nothing.

Method DB_StructEditorDlg.ReopenIndex, uses xbx xsi, pStatus:PTaskStatus, \
                                                     pEditorLine:$ObjPtr(DB_StructEditorLine), \
                                                     xFieldIndex:XWORD
  local pIndex:$ObjPtr(DB_Index), cBuffer[LOCAL_BUFFER_SIZE]:CHR

;  DbgText "DB_StructEditorDlg.ReopenIndex"
  SetObject xsi

  lea xbx, cBuffer
  mov xax, pEditorLine
  mov xcx, [xax].$Obj(DB_StructEditorLine).hEdtFieldIndex
  invoke GetWindowText, xcx, xbx, LOCAL_BUFFER_SIZE/sizeof(CHR)
  mov xax, pEditorLine
  New DB_Index
  .if xax == NULL
    OCall xsi.ErrorReport, NULL, DB_OUT_OF_MEMORY
    DbgWarning "DB_StructEditorDlg.MutationJob: Out of memory creating a DB_Index", \
               offset(szDbgObjErr)
    mov xax, pStatus
    BitSet [xax].TaskStatus.dFlags, TSF_TASK_ERROR
    ExitMethod
  .endif
  mov pIndex, xax
  mov xcx, [xsi].pTable
  OCall [xcx].$Obj(DB_Table).Fields::Collection.ItemAt, DWORD ptr xFieldIndex
  OCall pIndex::DB_Index.Open, xax, xbx
  mov xcx, pEditorLine
  m2m [xcx].$Obj(DB_StructEditorLine).pPrvFieldIndex, pIndex, xax
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     DB_StructEditorDlg.UpdateStatusbar
; Purpose:    Update relevant database information on the statusbar.
; Arguments:  None.
; Return:     Nothing.

Method DB_StructEditorDlg.UpdateStatusbar, uses xbx xdi xsi
  local cBuffer[LOCAL_BUFFER_SIZE]:CHR, qFileSize:QWORD

  SetObject xsi
  lea xbx, cBuffer
  mov xdi, [xsi].pTable
  FillText [xbx], < Table: >
  add xbx, 8*sizeof(CHR)
;  mov xcx, [xsi].pTable
;  invoke GetFinalPathNameByHandle, [xcx].$Obj(DB_Table).hFile, xbx, lengthof(cBuffer), FILE_NAME_NORMALIZED
  invoke StrECopy, xbx, [xdi].$Obj(DB_Table).pFileName
  FillText [xax], < (Size: >
  lea xbx, [xax + 8*sizeof(CHR)]
  invoke GetFileSizeEx, [xdi].$Obj(DB_Table).hFile, addr qFileSize
  invoke qword2dec, xbx, qFileSize
  invoke StrEnd, xbx
  FillText [xax], < bytes, Records: >
  lea xbx, [xax + 17*sizeof(CHR)]
  invoke dword2dec, xbx, [xdi].$Obj(DB_Table).Descriptor.dNumRecs
  invoke StrEnd, xbx
  FillString [xax], <)>

  OCall [xsi].StatusBar::Statusbar.SetPartText, 0, addr cBuffer, SBT_SUNKEN
MethodEnd
