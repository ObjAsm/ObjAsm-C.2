; ==================================================================================================
; Title:      DialogProgress.inc
; Author:     G. Friedrich
; Version:    C.1.1
; Purpose:    ObjAsm Progress dialog.
; Notes:      Version C.1.1, February 2020
;             - First release.
;             - Single worker implementation.
;             - The task information is arranged as a header followed by n TaskSetup structures.
; ==================================================================================================


; --------------------------------------------------------------------------------------------------

TSF_THREAD_CANCEL   equ   BIT00     ;DialogProgress signals the thread should cancel the curr. task
TSF_THREAD_ENDED    equ   BIT01     ;The thread signals it has ended
TSF_TASK_CANCELED   equ   BIT02     ;The thread signals that the current task was cancelled
TSF_TASK_ENDED      equ   BIT03     ;The thread signals that the current task has ended
TSF_TASK_ERROR      equ   BIT04     ;The thread signals that the current task has an error
TSF_TASK_ALL        equ   TSF_TASK_CANCELED or TSF_TASK_ENDED or TSF_TASK_ERROR

TaskStatus struct
  dCurPrgCnt    DWORD     ?         ;Current task progess value
  dFlags        DWORD     ?         ;Thread status flags
TaskStatus ends
PTaskStatus typedef ptr TaskStatus

TaskHeader struct
  dTaskCount    DWORD     ?
  hIcon         HICON     ?
  pMainDesc     PSTRINGA  ?
  pOverallDesc  PSTRINGA  ?
TaskHeader ends
PTaskHeader typedef ptr TaskHeader

TaskSetup struct
  pTaskProc     POINTER   ?         ;Thread procedure
  pOwner        POINTER   ?         ;Thread procedure
  xParam1       XWORD     ?
  xParam2       XWORD     ?
  pDescription  PSTRINGA  ?         ;Job description string
  dPrgCntMax    DWORD     ?         ;Task PrgCnt end value
TaskSetup ends
PTaskSetup typedef ptr TaskSetup

Object DialogProgress,, DialogModal
  RedefineMethod    CtlsSet
  RedefineMethod    Done
  RedefineMethod    Init,             POINTER, HWND, POINTER
  RedefineMethod    OnCommand,        WPARAM, LPARAM
  RedefineMethod    OnInitDialog,     WPARAM, LPARAM
  VirtualMethod     Run

  VirtualEvent      OnCtlColorStatic, WM_CTLCOLORSTATIC
  VirtualEvent      OnTimer,          WM_TIMER

  DefineVariable    dThreadFlags,     DWORD,        0
  DefineVariable    pTaskHeader,      PTaskHeader,  NULL
  DefineVariable    pCurTask,         PTaskSetup,   NULL
  DefineVariable    dCurTask,         DWORD,        0
  DefineVariable    CurTaskStatus,    TaskStatus,   {0, 0}
  DefineVariable    hWorker,          HANDLE,       0       ;Thread HANDLE, single worker
  DefineVariable    hEvent,           HANDLE,       0
  DefineVariable    hTimer,           HANDLE,       0
  DefineVariable    hBrush,           HBRUSH,       0       ;Background brush; Stock object

  DefineVariable    dOvrPrgCntMax,    DWORD,        0
  DefineVariable    dOvrPrgCntLast,   DWORD,        0       ;dOvrPrgCnt from last completed task
ObjectEnd

;Resource file:
;IDD_PROGRESS_SINGLETASK DIALOGEX 5,5,241,103
;CAPTION "Progress information"
;FONT 9,"Segoe UI",400,0
;STYLE 0x10C80090
;EXSTYLE 0x00000000
;BEGIN
;  CONTROL "&Cancel",IDCANCEL,"Button",0x50010001,176,81,55,14,0x00000000
;  CONTROL "",IDC_PRG_STC_BLANK,"Static",0x58000006,0,0,245,74,0x00000000
;  CONTROL "",IDC_PRG_STC_ICON,"Static",0x50000243,8,8,27,25,0x00000000
;  CONTROL "",IDC_PRG_RED_DESCRIPTION,"RichEdit20W",0x50000804,41,8,190,32,0x00000000
;  CONTROL "",IDC_PRG_RED_TASK,"RichEdit20W",0x50000800,8,43,223,10,0x00000000
;  CONTROL "",IDC_PRG_PGB_TASK,"msctls_progress32",0x50000000,8,54,223,11,0x00000000
;  CONTROL "&Always on Top",IDC_PRG_CHK_ALWAYS_ON_TOP,"Button",0x50010003,8,81,153,13,0x00000000
;END
;
;IDD_PROGRESS_MULTITASK DIALOGEX 5,5,241,133
;CAPTION "Progress information"
;FONT 9,"Segoe UI",400,0
;STYLE 0x10C80090
;EXSTYLE 0x00000000
;BEGIN
;  CONTROL "&Cancel",IDCANCEL,"Button",0x50010001,176,112,55,14,0x00000000
;  CONTROL "",IDC_PRG_STC_BLANK,"Static",0x58000006,0,0,245,104,0x00000000
;  CONTROL "",IDC_PRG_STC_ICON,"Static",0x50000243,8,8,27,25,0x00000000
;  CONTROL "",IDC_PRG_RED_DESCRIPTION,"RichEdit20W",0x50000804,41,8,190,32,0x00000000
;  CONTROL "",IDC_PRG_RED_OVERALL,"RichEdit20W",0x50000800,8,43,223,10,0x00000000
;  CONTROL "",IDC_PRG_PGB_OVERALL,"msctls_progress32",0x50000000,8,54,223,11,0x00000000
;  CONTROL "",IDC_PRG_RED_TASK,"RichEdit20W",0x50000800,8,72,223,10,0x00000000
;  CONTROL "",IDC_PRG_PGB_TASK,"msctls_progress32",0x50000000,8,83,223,11,0x00000000
;  CONTROL "&Always on Top",IDC_PRG_CHK_ALWAYS_ON_TOP,"Button",0x50010003,8,112,153,13,0x00000000
;END


; ==================================================================================================

if IMPLEMENT

.code
; ==================================================================================================
;    DialogProgress implementation
; ==================================================================================================

;Progress.dlg
IDD_PROGRESS_SINGLETASK       equ       9000
IDD_PROGRESS_MULTITASK        equ       9100
IDC_PRG_STC_ICON              equ       1000
IDC_PRG_RED_DESCRIPTION       equ       1001
IDC_PRG_RED_OVERALL           equ       1002
IDC_PRG_PGB_OVERALL           equ       1003
IDC_PRG_RED_TASK              equ       1004
IDC_PRG_PGB_TASK              equ       1005
IDC_PRG_STC_BLANK             equ       1006
IDC_PRG_CHK_ALWAYS_ON_TOP     equ       1007

DIALOG_PROGRESS_TIMER_ID  equ   12793

PTaskProc typedef proto :POINTER, :PTaskStatus, :XWORD, :XWORD

; --------------------------------------------------------------------------------------------------
; Procedure:  EdtStmCallback
; Purpose:    Read in the content of a RechEdit control.
; Arguments:  Arg1: -> RTF ANSI string.
;             Arg2: -> Buffer to write in.
;             Arg3: Buffer size in bytes.
;             Arg4: -> Variable to write the number of transfered bytes.
; Return:     eax = Zero to indicate success.

EdtStmCallback proc pString:PSTRINGA, pBuffer:POINTER, dNumBytes:DWORD, pBytesTransferred:POINTER
  .if pString != NULL
    invoke StrSizeA, pString
    .if eax > dNumBytes
      mov eax, dNumBytes
    .endif
    mov xcx, pBytesTransferred
    mov [xcx], eax
    invoke MemClone, pBuffer, pString, eax
  .endif
  xor eax, eax
  ret
EdtStmCallback endp

; --------------------------------------------------------------------------------------------------
; Method:     DialogProgress.CtlsSet
; Purpose:    Set the controls in this dialog window.
; Arguments:  None.
; Return:     Nothing.

Method DialogProgress.CtlsSet, uses xdi xsi
  local EdtStm:EDITSTREAM

  SetObject xsi
  ;Set overall controls
  mov xdi, [xsi].pTaskHeader
  mov EdtStm.EDITSTREAM.dwError, 0
  c2m EdtStm.EDITSTREAM.pfnCallback, offset(EdtStmCallback), xax
  m2m EdtStm.EDITSTREAM.dwCookie, [xdi].TaskHeader.pMainDesc, xax
  invoke SendDlgItemMessage, [xsi].hWnd, IDC_PRG_RED_DESCRIPTION, EM_STREAMIN, SF_RTF, addr EdtStm
  m2m EdtStm.EDITSTREAM.dwCookie, [xdi].TaskHeader.pOverallDesc, xax
  invoke SendDlgItemMessage, [xsi].hWnd, IDC_PRG_RED_OVERALL, EM_STREAMIN, SF_RTF, addr EdtStm
  invoke SendDlgItemMessage, [xsi].hWnd, IDC_PRG_STC_ICON, STM_SETICON, [xdi].TaskHeader.hIcon, 0
  mov eax, [xsi].dOvrPrgCntMax
  invoke SendDlgItemMessage, [xsi].hWnd, IDC_PRG_PGB_OVERALL, PBM_SETRANGE32, 0, xax
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     DialogProgress.Done
; Purpose:    Finalize the DB_QueryDlg object.
; Arguments:  None.
; Return:     Nothing.

Method DialogProgress.Done, uses xsi
  SetObject xsi
  invoke CloseHandle, [xsi].hWorker
  invoke CloseHandle, [xsi].hEvent
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     DialogProgress.Init
; Purpose:    Initialaize a DialogProgress object.
; Arguments:  Arg1: -> Owner object.
;             Arg2: Parent window HANDLE.
;             Arg4: -> TaskHeader, followed by TaskSetup structures.
; Return:     Nothing.

.code
Method DialogProgress.Init,, pOwner:POINTER, hParent:HWND, pTasks:POINTER
  SetObject xcx
  m2m [xcx].pTaskHeader, pTasks, xax
  .if [xax].TaskHeader.dTaskCount == 1
    mov eax, IDD_PROGRESS_SINGLETASK
  .else
    mov eax, IDD_PROGRESS_MULTITASK
  .endif
  ACall xcx.Init, pOwner, hParent, xax
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     DialogProgress.OnCommand
; Purpose:    Event procedure for WM_COMMAND message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method DialogProgress.OnCommand, uses xsi, wParam:WPARAM, lParam:LPARAM
;  DbgText "DialogProgress.OnCommand"
  SetObject xsi
  mov xax, wParam
  .if ax == IDCANCEL
    BitSet [xsi].CurTaskStatus.dFlags, TSF_THREAD_CANCEL  ;Set flag for the running thread
    xor eax, eax                                          ;Return zero
  .elseif ax == IDC_PRG_CHK_ALWAYS_ON_TOP
    invoke SendDlgItemMessage, [xsi].hWnd, IDC_PRG_CHK_ALWAYS_ON_TOP, BM_GETCHECK, 0, 0
    .if eax == BST_CHECKED
      mov xdx, HWND_TOPMOST
    .else
      mov xdx, HWND_NOTOPMOST
    .endif
    invoke SetWindowPos, [xsi].hWnd, xdx, 0, 0, 0, 0, SWP_NOMOVE or SWP_NOSIZE
  .else
    mov eax, -1
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     DialogProgress.OnInitDialog
; Purpose:    Event procedure for WM_INITDIALOG message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = TRUE to direct the system to set the keyboard focus to the control specified by
;             wParam. Otherwise, it should return FALSE to prevent the system from setting the
;             default keyboard focus.

Method DialogProgress.OnInitDialog, uses xbx xdi xsi, wParam:WPARAM, lParam:LPARAM
  local EdtStm:EDITSTREAM

  SetObject xsi

  ;Initialize startup parameter
  mov xax, [xsi].pTaskHeader
  mov edi, [xax].TaskHeader.dTaskCount
  add xax, sizeof(TaskHeader)
  xor xbx, xbx
  test edi, edi
  .while !ZERO?
    add ebx, [xax].TaskSetup.dPrgCntMax
    add xax, sizeof(TaskSetup)
    dec edi
  .endw
  mov [xsi].dOvrPrgCntMax, ebx

  ;Create background white brush
  mov [xsi].hBrush, $invoke(GetStockObject, WHITE_BRUSH)

  ;Initialize and set dialog controls
  ACall xsi.OnInitDialog, wParam, lParam

  ;Setup first task dialog information
  mov xdi, [xsi].pTaskHeader
  add xdi, sizeof(TaskHeader)
  mov [xsi].pCurTask, xdi
  mov EdtStm.EDITSTREAM.dwError, 0
  c2m EdtStm.EDITSTREAM.pfnCallback, offset(EdtStmCallback), xax
  m2m EdtStm.EDITSTREAM.dwCookie, [xdi].TaskSetup.pDescription, xax
  invoke SendDlgItemMessage, [xsi].hWnd, IDC_PRG_RED_TASK, EM_STREAMIN, SF_RTF, addr EdtStm
  mov eax, [xdi].TaskSetup.dPrgCntMax
  invoke SendDlgItemMessage, [xsi].hWnd, IDC_PRG_PGB_TASK, PBM_SETRANGE32, 0, xax

  ;Create a thread and a synch event
  mov [xsi].hEvent, $invoke(CreateEvent, NULL, FALSE, TRUE, NULL)   ;Signaled
  mov [xsi].hWorker, $invoke(CreateThread, NULL, 0, $MethodAddr(DialogProgress.Run), xsi, 0, 0)

  ;Setup a timer to monitor the task progress
  mov [xsi].hTimer, $invoke(SetTimer, [xsi].hWnd, DIALOG_PROGRESS_TIMER_ID, 250, NULL)

MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     DialogProgress.OnCtlColorStatic
; Purpose:    Event procedure for WM_CTLCOLORSTATIC message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     xax = Brush HANDLE or zero.

Method DialogProgress.OnCtlColorStatic, uses xsi, wParam:WPARAM, lParam:LPARAM
;  DbgText "DialogProgress.OnCtlColorStatic"
  SetObject xsi
  invoke GetDlgItem, [xsi].hWnd, IDC_PRG_STC_ICON
  .if xax == lParam
    mov xax, [xsi].hBrush
  .else
    xor eax, eax
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     DialogProgress.OnTimer
; Purpose:    Event procedure for WM_TIMER message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if the message is processed.

Method DialogProgress.OnTimer, uses xbx xdi xsi, wParam:WPARAM, lParam:LPARAM
  local EdtStm:EDITSTREAM

;  DbgText "DialogProgress.OnTimer"
  SetObject xsi

  .if wParam == DIALOG_PROGRESS_TIMER_ID
  @@:
    .ifBitSet [xsi].CurTaskStatus.dFlags, TSF_THREAD_ENDED
      invoke KillTimer, [xsi].hWnd, DIALOG_PROGRESS_TIMER_ID
      OCall xsi.DestroyDialog, wParam
    .else
      mov ecx, [xsi].dCurTask                           ;0..n-1
      mov xdx, [xsi].pTaskHeader
      imul ecx, sizeof(TaskSetup)
      add ecx, sizeof(TaskHeader)
      mov ebx, [xdx + xcx].TaskSetup.dPrgCntMax
      .ifBitSet [xsi].CurTaskStatus.dFlags, TSF_TASK_ENDED
        add [xsi].dOvrPrgCntLast, ebx

        ;Move to next TaskSetup
        mov xdi, [xsi].pCurTask
        add xdi, sizeof(TaskSetup)
        mov [xsi].pCurTask, xdi
        inc [xsi].dCurTask

        ;Setup dialog task information
        mov EdtStm.EDITSTREAM.dwError, 0
        c2m EdtStm.EDITSTREAM.pfnCallback, offset(EdtStmCallback), xax
        m2m EdtStm.EDITSTREAM.dwCookie, [xdi].TaskSetup.pDescription, xax
        invoke SendDlgItemMessage, [xsi].hWnd, IDC_PRG_RED_TASK, EM_STREAMIN, SF_RTF, addr EdtStm
        mov eax, [xdi].TaskSetup.dPrgCntMax
        invoke SendDlgItemMessage, [xsi].hWnd, IDC_PRG_PGB_TASK, PBM_SETRANGE32, 0, xax

        ;Trigger new task
        invoke SetEvent, [xsi].hEvent
      .else
        mov ecx, [xsi].CurTaskStatus.dCurPrgCnt
        .if ecx < ebx
          mov ebx, ecx
        .endif
        mov eax, [xsi].dOvrPrgCntLast
        add eax, ebx
        invoke SendDlgItemMessage, [xsi].hWnd, IDC_PRG_PGB_OVERALL, PBM_SETPOS, eax, 0
        invoke SendDlgItemMessage, [xsi].hWnd, IDC_PRG_PGB_TASK, PBM_SETPOS, ebx, 0
      .endif
    .endif
    xor eax, eax
  .else
    mov eax, -1
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     DialogProgress.Run
; Purpose:    Worker thread.
; Arguments:  None.
; Return:     Nothing.

Method DialogProgress.Run, uses xbx xdi xsi
  SetObject xsi
  xor ebx, ebx
  .while TRUE
    mov xax, [xsi].pTaskHeader
    .break .if ebx == [xax].TaskHeader.dTaskCount
    invoke WaitForSingleObject, [xsi].hEvent, INFINITE
    mov xdi, [xsi].pCurTask
    assume xdi:PTaskSetup
    .if [xdi].pTaskProc != NULL
      mov [xsi].CurTaskStatus.dCurPrgCnt, 0
      BitClr [xsi].CurTaskStatus.dFlags, TSF_TASK_ALL
      invoke PTaskProc ptr [xdi].pTaskProc, [xdi].pOwner, addr [xsi].CurTaskStatus, \
                           [xdi].xParam1, [xdi].xParam2
      BitSet [xsi].CurTaskStatus.dFlags, TSF_TASK_ENDED     ;Just in case we forgot to to set it
      test [xsi].CurTaskStatus.dFlags, TSF_TASK_CANCELED
      .break .if !ZERO?
    .else
      BitSet [xsi].CurTaskStatus.dFlags, TSF_TASK_ENDED     ;We can proceed with the next task
    .endif
    assume xdi:NOTHING
    inc ebx
  .endw
  BitSet [xsi].CurTaskStatus.dFlags, TSF_THREAD_ENDED
MethodEnd

endif
