; ==================================================================================================
; Title:      ScriptHost_Main.inc
; Author:     G. Friedrich
; Version:    See ScriptHost.asm
; Purpose:    ObjAsm ScriptHost Application.
; ==================================================================================================


Object Application, ApplicationID, DialogModal    ;DialogModeless
  VirtualMethod     EnableControls,     DWORD
  VirtualMethod     FileLoad,           PSTRING
  VirtualMethod     FileSave,           PSTRING, POINTER, DWORD

  RedefineMethod    OnCommand,          WPARAM, LPARAM
  RedefineMethod    OnDestroy,          WPARAM, LPARAM
  RedefineMethod    OnInitDialog,       WPARAM, LPARAM
  RedefineMethod    OnSize,             WPARAM, LPARAM

  VirtualEvent      OnDropFiles,        WM_DROPFILES
  VirtualEvent      OnEnableModeless,   SHM_ENABLEMODELESS
  VirtualEvent      OnFinished,         SHM_FINISHED
  VirtualEvent      OnError,            SHM_ERROR

  DefineVariable    pFileName,          PSTRING,    NULL            ;Currently open FileName
  DefineVariable    hEditFont,          HWND,       0

  Embed     SplitterHor,      Splitter
  Embed     WSH,              ScriptHost
ObjectEnd


Object IScriptOutput, -2, IScriptInterface
  InterfaceMethod   Clear
  InterfaceMethod   Write,              BSTR
  InterfaceMethod   Color,              DWORD
  InterfaceMethod   Font,               BSTR, DWORD, DWORD

  RedefineMethod    Init,               POINTER, PSTRINGW, POINTER

  DefineVariable    hControl,           HWND,       0
  DefineVariable    CFD,                CHARFORMAT, {sizeof CHARFORMAT}
ObjectEnd


.code

; ==================================================================================================
;    Application implementation
; ==================================================================================================

SHD_CTRL_LOAD    equ   BIT00
SHD_CTRL_SAVE    equ   BIT01
SHD_CTRL_RUN     equ   BIT02
SHD_CTRL_STOP    equ   BIT03
SHD_CTRL_SCRIPT  equ   BIT04
SHD_CTRL_OUTPUT  equ   BIT05

; --------------------------------------------------------------------------------------------------
; Method:     Application.EnableControls
; Purpose:    Load a file into the memory block.
; Arguments:  Arg1: Enable flag [SHD_xxx...].
; Return:     xax -> MemBlock or NULL if failed.

Method Application.EnableControls, uses xsi, dEnable:DWORD
  SetObject xsi
  invoke GetDlgItem, [xsi].hWnd, IDC_BTN_LOAD
  xor edx, edx
  .ifBitSet dEnable, SHD_CTRL_LOAD
    inc edx
  .endif
  invoke EnableWindow, xax, edx

  invoke GetDlgItem, [xsi].hWnd, IDC_BTN_SAVE
  xor edx, edx
  .ifBitSet dEnable, SHD_CTRL_SAVE
    inc edx
  .endif
  invoke EnableWindow, xax, edx

  invoke GetDlgItem, [xsi].hWnd, IDC_BTN_RUN
  xor edx, edx
  .ifBitSet dEnable, SHD_CTRL_RUN
    inc edx
  .endif
  invoke EnableWindow, xax, edx

  invoke GetDlgItem, [xsi].hWnd, IDC_BTN_STOP
  xor edx, edx
  .ifBitSet dEnable, SHD_CTRL_STOP
    inc edx
  .endif
  invoke EnableWindow, xax, edx

  invoke GetDlgItem, [xsi].hWnd, IDC_RED_SCRIPT
  xor edx, edx
  .ifBitSet dEnable, SHD_CTRL_SCRIPT
    inc edx
  .endif
  invoke EnableWindow, xax, edx

  invoke GetDlgItem, [xsi].hWnd, IDC_RED_OUTPUT
  xor edx, edx
  .ifBitSet dEnable, SHD_CTRL_OUTPUT
    inc edx
  .endif
  invoke EnableWindow, xax, edx

MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Application.FileLoad
; Purpose:    Load a file into the memory block.
; Arguments:  Arg1: -> FileName.
; Return:     eax: TRUE if succeeded, otherwise FALSE.

Method Application.FileLoad, uses xbx xsi, pFileName:PSTRING
  local hFile:HANDLE, dFileSize:DWORD, dBytesRead:DWORD, pMemBlock:POINTER
  local cBuffer[1024*sizeof CHR]:CHR

  SetObject xsi
  ;Open the file
  xor ebx, ebx
  invoke CreateFile, pFileName, GENERIC_READ, FILE_SHARE_READ, 0, OPEN_EXISTING, \
                     FILE_ATTRIBUTE_NORMAL, 0
  .if xax != INVALID_HANDLE_VALUE
    mov hFile, xax
    ;Get a buffer to read in the file, with room to null-terminate
    invoke GetFileSize, xax, NULL
    .if eax != -1
      mov dFileSize, eax
      inc eax
      MemAlloc eax
      .if xax != NULL
        mov pMemBlock, xax
        lea xax, dBytesRead
        invoke ReadFile, hFile, pMemBlock, dFileSize, xax, 0
        mov ecx, dBytesRead
        .if eax == FALSE || ecx != dFileSize
          MemFree pMemBlock
        .else
          ;Set ZTC
          mov eax, dFileSize
          add xax, pMemBlock
          m2z BYTE ptr [xax]

          invoke SendDlgItemMessageA, [xsi].hWnd, IDC_RED_SCRIPT, WM_SETTEXT, 0, pMemBlock
          MemFree pMemBlock
          OCall xsi.EnableControls, SHD_CTRL_LOAD or SHD_CTRL_SAVE or SHD_CTRL_RUN or\
                                    SHD_CTRL_SCRIPT or SHD_CTRL_OUTPUT
          invoke StrCCopy, addr cBuffer, offset szCaption, lengthof cBuffer
          invoke StrCECat, addr cBuffer, pFileName, lengthof cBuffer
          invoke SendMessage, [xsi].hWnd, WM_SETTEXT, 0, addr cBuffer

          .if [xsi].pFileName != NULL
            invoke StrDispose, [xsi].pFileName
          .endif
          mov [xsi].pFileName, $invoke(StrNew, pFileName)
          inc ebx
        .endif
      .endif
    .endif
    invoke CloseHandle, hFile
  .endif
  mov eax, ebx
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Application.FileSave
; Purpose:    Write memory block into a file.
; Arguments:  Arg1: -> FileName.
;             Arg2: -> Memblock.
;             Arg3: -> MemSize.
; Return:     eax = TRUE if succeeded, otherwise FALSE.

Method Application.FileSave, uses xsi, pFileName:PSTRING, pMemBlock:POINTER, dMemSize:DWORD
  local hFile:HANDLE, dBytesWritten:DWORD, dResult:DWORD
  local cBuffer[1024*sizeof CHR]:CHR

  SetObject xsi
  invoke FileExist, pFileName
  .if eax != FALSE
    invoke MessageBox, [xsi].hWnd, $OfsCStr("File already exist. Overwrite it?"), \
                       offset szCaption, MB_OKCANCEL or MB_ICONWARNING
    .if eax == IDCANCEL
      jmp @@Exit
    .endif
  .endif
  ;Open the file
  invoke CreateFile, pFileName, GENERIC_WRITE, FILE_SHARE_WRITE, 0, \
                     CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, 0
  .if xax != INVALID_HANDLE_VALUE
    mov hFile, xax
    mov dResult, $32($invoke(WriteFile, hFile, pMemBlock, dMemSize, addr dBytesWritten, NULL))
    invoke CloseHandle, hFile

    invoke StrCCopy, addr cBuffer, offset szCaption, lengthof cBuffer
    invoke StrCECat, addr cBuffer, pFileName, lengthof cBuffer
    invoke SendMessage, [xsi].hWnd, WM_SETTEXT, 0, addr cBuffer

    .if [xsi].pFileName != NULL
      invoke StrDispose, [xsi].pFileName
    .endif
    mov [xsi].pFileName, $invoke(StrNew, pFileName)

    mov eax, dResult
  .else
@@Exit:
    xor eax, eax
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Application.OnCommand
; Purpose:    Event procedure for WM_COMMAND message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method Application.OnCommand, uses xbx xsi, wParam:WPARAM, lParam:LPARAM
  local AbtDlg:$Obj(DialogAbout), hIcon:HICON
  local OpenFileName:OPENFILENAME, cFileName[MAX_PATH*sizeof CHR]:CHR, cBuffer[1024*sizeof CHR]:CHR
  local pContent:PSTRINGW, pScript:PSTRINGW

  SetObject xsi
  mov xax, wParam

  .if ax == IDC_BTN_LOAD
    mov OpenFileName.lStructSize, sizeof OPENFILENAME
    m2m OpenFileName.hwndOwner, [xsi].hWnd, xax
    m2m OpenFileName.hInstance, hInstance, xcx
    c2m OpenFileName.lpstrFilter, offset szLoadFilter, xax
    m2z OpenFileName.lpstrCustomFilter
    m2z OpenFileName.nMaxCustFilter
    m2z OpenFileName.nFilterIndex
    lea xax, cFileName
    m2z CHR ptr [xax]
    mov OpenFileName.lpstrFile, xax
    mov OpenFileName.nMaxFile, lengthof cFileName - 1
    m2z OpenFileName.lpstrFileTitle
    m2z OpenFileName.nMaxFileTitle
    m2z OpenFileName.lpstrInitialDir
    c2m OpenFileName.lpstrTitle, $OfsCStr("Choose a Visual Basic Script File to load"), xax
    c2m OpenFileName.lpstrDefExt, $OfsCStr(".vbs"), xax
    mov OpenFileName.Flags, OFN_EXPLORER or OFN_FILEMUSTEXIST or OFN_LONGNAMES or OFN_HIDEREADONLY
    m2z OpenFileName.FlagsEx
    invoke GetOpenFileName, addr OpenFileName
    .if eax == TRUE
      OCall xsi.FileLoad, addr cFileName
    .endif
    xor eax, eax

  .elseif ax == IDC_BTN_ABOUT
    New AbtDlg::DialogAbout
    mov hIcon, $invoke(LoadIcon, hInstance, $OfsCStr("ICON_APP"))
    OCall AbtDlg::DialogAbout.Init, xsi, [xsi].hWnd, hIcon, offset szAboutText
    OCall AbtDlg::DialogAbout.Show
    OCall AbtDlg::DialogAbout.Done
    invoke DestroyIcon, hIcon
    xor eax, eax

  .elseif ax == IDCANCEL
    invoke PostThreadMessage, [xsi].WSH.dThreadID, WM_QUIT, 0, 0
    OCall xsi.DestroyDialog, wParam
    xor eax, eax                                      ;Return zero

  .elseif ax == IDC_BTN_SAVE
    mov OpenFileName.lStructSize, sizeof OPENFILENAME
    m2m OpenFileName.hwndOwner, [xsi].hWnd, xax
    m2m OpenFileName.hInstance, hInstance, xcx
    m2m OpenFileName.lpstrFilter, offset szLoadFilter, xax
    m2z OpenFileName.lpstrCustomFilter
    m2z OpenFileName.nMaxCustFilter
    m2z OpenFileName.nFilterIndex
    lea xax, cFileName
    m2z CHR ptr [xax]
    mov OpenFileName.lpstrFile, xax
    mov OpenFileName.nMaxFile, lengthof cFileName - 1
    m2z OpenFileName.lpstrFileTitle
    m2z OpenFileName.nMaxFileTitle
    m2z OpenFileName.lpstrInitialDir
    c2m OpenFileName.lpstrTitle, $OfsCStr("Choose a Visual Basic Script file to save"), xax
    c2m OpenFileName.lpstrDefExt, $OfsCStr(".vbs"), xax
    mov OpenFileName.Flags, OFN_EXPLORER or OFN_FILEMUSTEXIST or OFN_LONGNAMES or OFN_HIDEREADONLY
    m2z OpenFileName.FlagsEx
    invoke GetSaveFileName, addr OpenFileName
    .if eax == TRUE
      invoke SendDlgItemMessage, [xsi].hWnd, IDC_RED_SCRIPT, WM_GETTEXTLENGTH, 0, 0
      lea xbx, [xax + 1]
      mov pScript, $MemAlloc(xbx)
      invoke SendDlgItemMessageA, [xsi].hWnd, IDC_RED_SCRIPT, WM_GETTEXT, xbx, pScript
      OCall xsi.FileSave, addr cFileName, pScript, ebx
      MemFree pScript
    .endif
    xor eax, eax

  .elseif ax == IDC_BTN_RUN
    invoke SendDlgItemMessage, [xsi].hWnd, IDC_RED_SCRIPT, WM_GETTEXTLENGTH, 0, 0
    .if eax != 0
      inc eax
      mov ebx, eax
      shl eax, 1
      MemAlloc eax                                    ;ScriptHost releases it in its own thread
      .if xax != NULL
        mov pScript, xax
        invoke SendDlgItemMessageW, [xsi].hWnd, IDC_RED_SCRIPT, WM_GETTEXT, xbx, pScript
        OCall xsi.EnableControls, SHD_CTRL_STOP
        invoke PostThreadMessage, [xsi].WSH.dThreadID, SHM_EXECUTE, pScript, 0
      .endif
    .endif
    xor eax, eax                                      ;Return zero

  .elseif ax == IDC_BTN_STOP
    ICall [xsi].WSH.pIActiveScript::IActiveScript.InterruptScriptThread, SCRIPTTHREADID_ALL, 0, 0
    xor eax, eax

  .else
    invoke DefWindowProc, [xsi].hWnd, WM_COMMAND, wParam, lParam

  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Application.OnDestroy
; Purpose:    Event procedure for WM_DESTROY message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero.

Method Application.OnDestroy, uses xsi, wParam:WPARAM, lParam:LPARAM
  SetObject xsi
  .if [xsi].hEditFont != 0
    invoke DeleteObject, [xsi].hEditFont
  .endif

  OCall [xsi].SplitterHor::Splitter.Done

  .if [xsi].pFileName != 0
    invoke StrDispose, [xsi].pFileName
  .endif

  OCall [xsi].WSH::ScriptHost.Done

  ACall xsi.OnDestroy, wParam, lParam
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Application.OnDropFiles
; Purpose:    Event procedure for WM_DROPFILES message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero.

Method Application.OnDropFiles, uses xbx xdi xsi, wParam:WPARAM, lParam:LPARAM
  SetObject xsi
  mov edi, $32($invoke(DragQueryFile, wParam, 0, NULL, 0))
  inc edi                                               ;Include ZTC
  mov xbx, $invoke(StrAlloc, edi)
  invoke DragQueryFile, wParam, 0, xbx, edi             ;Get the FileName
  invoke PathFindExtension, xbx
  .if xax != NULL
    .if $invoke(StrIComp, xax, offset szVbsExt) == 0
      OCall xsi.FileLoad, xbx
      test eax, eax
      jnz @@Exit
    .endif
  .endif
  invoke MessageBox, [xsi].hWnd, offset szFileTypeErr, offset szAppTitle, MB_ICONEXCLAMATION

  @@Exit:
  invoke DragFinish, wParam
  xor eax, eax
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Application.OnEnableModeless
; Purpose:    Event procedure for SHM_ENABLEMODELESS message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     Nothing.

Method Application.OnEnableModeless,, wParam:WPARAM, lParam:LPARAM
  DbgWarning "Application.OnEnableModeless"
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Application.OnError
; Purpose:    Event procedure for SHM_ERROR message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     Nothing.

Method Application.OnError, uses xbx xsi, wParam:WPARAM, lParam:LPARAM
  local cBuffer[1024]:CHR

  SetObject xsi
  .if wParam == 0
    invoke GetLastError
    lea xbx, cBuffer
    invoke FormatMessage, FORMAT_MESSAGE_FROM_SYSTEM, 0, eax, \
                          0, xbx, sizeof cBuffer, 0
    invoke MessageBox, [xsi].hWnd, xbx, offset szError, MB_OK or MB_ICONERROR
  .else
    invoke MessageBox, [xsi].hWnd, wParam, offset szError, MB_OK or MB_ICONERROR
    invoke GlobalFree, wParam
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Application.OnFinished
; Purpose:    Event procedure for SHM_FINISHED message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     Nothing.

Method Application.OnFinished,, wParam:WPARAM, lParam:LPARAM
;  DbgText "Application.OnFinished"
  SetObject xcx
  OCall xcx.EnableControls, SHD_CTRL_LOAD or SHD_CTRL_SAVE or SHD_CTRL_RUN or \
                            SHD_CTRL_SCRIPT or SHD_CTRL_OUTPUT
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Application.OnInitDialog
; Purpose:    Event procedure for WM_INITDIALOG message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero.

Method Application.OnInitDialog, uses xbx xsi, wParam:WPARAM, lParam:LPARAM
  local LogFnt:LOGFONT, hDC:HDC

  SetObject xsi
  OCall [xsi].SplitterHor::Splitter.Init, xsi, [xsi].hWnd, SPT_FLAG_HORIZONTAL, 250, 50, 50

  OCall [xsi].WSH::ScriptHost.Init, xsi, [xsi].hWnd, offset CLSID_VBScript, WSF_DEBUG
  .if eax != FALSE
    OCall xsi.EnableControls, SHD_CTRL_LOAD

    mov xbx, $New(Component)
    OCall xbx::Component.Init, addr [xsi].WSH, NULL
    New IScriptOutput
    OCall [xbx].$Obj(Component).Interfaces::Collection.Insert, xax
    OCall xax::IScriptOutput.Init, xbx, NULL, offset IID_IScriptOutput
    invoke PostThreadMessage, [xsi].WSH.dThreadID, SHM_ADDCOMPONENT, $OfsCStrW("OUTPUT"), xbx
  .endif

  .if ([xsi].StartPos.x != -1) || ([xsi].StartPos.y != -1)
    ;Check if the dialog will be fully visible
    invoke MoveWindowVisible, [xsi].hWnd, [xsi].StartPos.x, [xsi].StartPos.y
  .endif

  ;Set the Editbox font to "Lucida Console" 10pt normal
  FillString LogFnt.lfFaceName, <Lucida Console>
  mov hDC, $invoke(GetDC, [xsi].hWnd)
  invoke GetDeviceCaps, hDC, LOGPIXELSY
  invoke MulDiv, 10, eax, -72
  mov LogFnt.lfHeight, eax
  m2z LogFnt.lfWidth
  m2z LogFnt.lfEscapement
  m2z LogFnt.lfOrientation
  mov LogFnt.lfWeight, FW_DONTCARE
  m2z LogFnt.lfItalic
  m2z LogFnt.lfUnderline
  m2z LogFnt.lfStrikeOut
  mov LogFnt.lfCharSet, DEFAULT_CHARSET
  mov LogFnt.lfOutPrecision, OUT_DEFAULT_PRECIS
  mov LogFnt.lfClipPrecision, CLIP_DEFAULT_PRECIS
  mov LogFnt.lfQuality, CLEARTYPE_QUALITY
  mov LogFnt.lfPitchAndFamily, DEFAULT_PITCH or FF_DONTCARE
  mov [xsi].hEditFont, $invoke(CreateFontIndirect, addr LogFnt)
  invoke ReleaseDC, [xsi].hWnd, hDC
  invoke SendDlgItemMessage, [xsi].hWnd, IDC_RED_SCRIPT, WM_SETFONT, [xsi].hEditFont, FALSE

  invoke SendMessage, [xsi].hWnd, WM_SETTEXT, 0, offset szCaption
  invoke SetFocus, $invoke(GetDlgItem, [xsi].hWnd, IDC_BTN_LOAD)
  OCall xsi.CtlsSet
  invoke SendMessage, [xsi].hWnd, WM_SIZE, SIZE_RESTORED, 0 ;Position all controls
  invoke SetForegroundWindow, [xsi].hWnd

  xor eax, eax                                          ;Return FALSE to prevent Windows from
MethodEnd                                               ;setting the default keyboard focus.

; --------------------------------------------------------------------------------------------------
; Method:     Application.OnSize
; Purpose:    Event procedure for WM_SIZE message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

BUTTON_WIDTH      equ   130
BUTTON_HEIGHT     equ   35
BUTTON_HSPACE     equ   10
BUTTON_VSPACE     equ   10
BUTTON_CSPACE     equ   10
BORDER_HSPACE     equ   10
BORDER_VSPACE     equ   10
SPLITTER_VSPACE   equ   1
SPLITTER_HEIGTH   equ   8

Method Application.OnSize, uses xbx xsi, wParam:WPARAM, lParam:LPARAM
  local DlgRect:RECT, SpHorRect:RECT
  local hControl:HWND, CtlRect:RECT
  local X1:DWORD, Y1:DWORD
  local dEditWidth:DWORD

  DbgText "Application.OnSize"
  .if wParam != SIZE_MINIMIZED
    SetObject xsi
    invoke GetClientRect, [xsi].hWnd, addr DlgRect

    ;Get horizontal Splitter position
    invoke GetWindowRect, [xsi].SplitterHor.hWnd, addr SpHorRect
    invoke ScreenToClient, [xsi].hWnd, addr SpHorRect.left
    invoke ScreenToClient, [xsi].hWnd, addr SpHorRect.right

    ;Place Code Edit control
    mov hControl, $invoke(GetDlgItem, [xsi].hWnd, IDC_RED_SCRIPT)
    invoke GetWindowRect, hControl, addr CtlRect
    mov ecx, DlgRect.right
    sub ecx, BUTTON_WIDTH + 2*BORDER_HSPACE + BUTTON_CSPACE
    mov dEditWidth, ecx
    mov eax, SpHorRect.top
    sub eax, BORDER_VSPACE + SPLITTER_VSPACE
    invoke MoveWindow, hControl, BORDER_HSPACE, BORDER_VSPACE, dEditWidth, eax, FALSE

    ;Place Output Edit control
    mov hControl, $invoke(GetDlgItem, [xsi].hWnd, IDC_RED_OUTPUT)
    mov eax, SpHorRect.top
    add eax, SPLITTER_HEIGTH + SPLITTER_VSPACE
    mov ebx, DlgRect.bottom
    sub ebx, eax
    sub ebx, BORDER_VSPACE
    invoke MoveWindow, hControl, BORDER_HSPACE, eax, dEditWidth, ebx, FALSE

    ;Place horizontal Splitter control
    invoke MoveWindow, [xsi].SplitterHor.hWnd, BORDER_HSPACE, SpHorRect.top, dEditWidth, \
                       SPLITTER_HEIGTH, FALSE

    ;Place Button controls
    mov hControl, $invoke(GetDlgItem, [xsi].hWnd, IDC_BTN_LOAD)
    mov eax, dEditWidth
    add eax, BORDER_HSPACE + BUTTON_CSPACE
    mov X1, eax
    mov Y1, BORDER_VSPACE
    invoke MoveWindow, hControl, X1, Y1, BUTTON_WIDTH, BUTTON_HEIGHT, FALSE

    mov hControl, $invoke(GetDlgItem, [xsi].hWnd, IDC_BTN_SAVE)
    add Y1, BUTTON_HEIGHT + BUTTON_VSPACE
    invoke MoveWindow, hControl, X1, Y1, BUTTON_WIDTH, BUTTON_HEIGHT, FALSE

    mov hControl, $invoke(GetDlgItem, [xsi].hWnd, IDC_BTN_RUN)
    add Y1, BUTTON_HEIGHT + 4*BUTTON_VSPACE
    invoke MoveWindow, hControl, X1, Y1, BUTTON_WIDTH, BUTTON_HEIGHT, FALSE

    mov hControl, $invoke(GetDlgItem, [xsi].hWnd, IDC_BTN_STOP)
    add Y1, BUTTON_HEIGHT + BUTTON_VSPACE
    invoke MoveWindow, hControl, X1, Y1, BUTTON_WIDTH, BUTTON_HEIGHT, FALSE

    mov hControl, $invoke(GetDlgItem, [xsi].hWnd, IDC_BTN_ABOUT)
    mov eax, DlgRect.bottom
    sub eax, 4*BORDER_VSPACE + BUTTON_HEIGHT
    mov ecx, Y1
    add ecx, BUTTON_VSPACE + BUTTON_HEIGHT
    .if SDWORD ptr eax < ecx
      mov eax, ecx
    .endif
    invoke MoveWindow, hControl, X1, eax, BUTTON_WIDTH, BUTTON_HEIGHT, FALSE

    mov hControl, $invoke(GetDlgItem, [xsi].hWnd, IDC_SBR_GRIPPER)
    invoke GetClientRect, hControl, addr CtlRect
    mov edx, DlgRect.right
    sub edx, CtlRect.right
    mov eax, DlgRect.bottom
    sub eax, CtlRect.bottom
    invoke MoveWindow, hControl, edx, eax, CtlRect.right, CtlRect.bottom, FALSE

    ;Redraw all child windows
    invoke RedrawWindow, [xsi].hWnd, NULL, NULL, \
                         RDW_ERASE or RDW_INVALIDATE or RDW_UPDATENOW or RDW_ALLCHILDREN

    xor eax, eax                                        ;Return zero
  .endif
MethodEnd


; ==================================================================================================
;    IScriptOutput implementation
; ==================================================================================================

; --------------------------------------------------------------------------------------------------
; Method:     IScriptOutput.Init
; Purpose:    Initialize the IScriptOutput interface object.
; Arguments:  Arg1: -> Owner object.
;             Arg2: -> TypeLib resource index (UNICODE string). If NULL, /1 is taken.
;             Arg3: -> Interfeace GUID.
; Return:     eax = TRUE if succeeded, otherwise FALSE.

Method IScriptOutput.Init, uses xsi, pOwner:POINTER, pResIndexStr:PSTRINGW, pIID:POINTER
  local hDC:HDC

  SetObject xsi
  ACall xsi.Init, pOwner, pResIndexStr, pIID
  mov xdx, [xsi].pOwner
  mov xax, [xdx].$Obj(Component).pOwner
  mov [xsi].hControl, $invoke(GetDlgItem, [xax].$Obj(ScriptHost).hWnd, IDC_RED_OUTPUT)

  ;Fill the CHARFORMATA structure with default values
  mov [xsi].CFD.dwMask, CFM_BOLD or CFM_COLOR  or CFM_FACE or CFM_ITALIC or CFM_SIZE \
                                    or CFM_STRIKEOUT or CFM_UNDERLINE
  m2z [xsi].CFD.dwEffects
  mov hDC, $invoke(GetWindowDC, [xsi].hControl)
  invoke GetDeviceCaps, hDC, LOGPIXELSY
  invoke MulDiv, 11, 1920, eax
  mov [xsi].CFD.yHeight, eax
  invoke ReleaseDC, [xsi].hControl, hDC
  m2z [xsi].CFD.crTextColor
  FillString [xsi].CFD.szFaceName, <Lucida Console>
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     IScriptOutput.Clear
; Purpose:    Erase the application output window.
; Arguments:  None.
; Return:     eax = HRESULT.

Method IScriptOutput.Clear, uses xsi
  local hDC:HDC

  DbgText "IScriptOutput.Clear"
  SetObject xsi
  invoke SendMessage, [xsi].hControl, EM_SETSEL, 0, -1
  invoke SendMessage, [xsi].hControl, EM_REPLACESEL, TRUE, NULL
  m2z [xsi].CFD.dwEffects
  mov hDC, $invoke(GetWindowDC, [xsi].hControl)
  invoke GetDeviceCaps, hDC, LOGPIXELSY
  invoke MulDiv, 11, 1920, eax
  mov [xsi].CFD.yHeight, eax
  invoke ReleaseDC, [xsi].hControl, hDC
  m2z [xsi].CFD.crTextColor
  invoke SendMessage, [xsi].hControl, EM_SETCHARFORMAT, SCF_SELECTION, addr [xsi].CFD
  xor eax, eax                                          ;S_OK
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     IScriptOutput.Write
; Purpose:    Output some text on the application output window.
; Arguments:  Arg1: BSTR, text to output.
; Return:     eax = HRESULT.

Method IScriptOutput.Write, uses xsi, pString:BSTR
  DbgText "IScriptOutput.Write"
  SetObject xsi
  invoke SendMessage, [xsi].hControl, EM_SETCHARFORMAT, SCF_SELECTION, addr [xsi].CFD
  invoke SendMessageW, [xsi].hControl, EM_REPLACESEL, TRUE, pString
  invoke SendMessage, [xsi].hControl, EM_SCROLLCARET, 0, 0      ;Move caret into view
  xor eax, eax                                          ;S_OK
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     IScriptOutput.Color
; Purpose:    Set the text color of the output window.
; Arguments:  Arg1: RGB value.
; Return:     eax = HRESULT.

Method IScriptOutput.Color,, dColor:DWORD
  DbgText "IScriptOutput.Color"
  SetObject xcx
  m2m [xcx].CFD.crTextColor, dColor, edx
  xor eax, eax                                          ;S_OK
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     IScriptOutput.Font
; Purpose:    Set the text font of the output window.
; Arguments:  Arg1: Font face BStr.
;             Arg2: Font size.
;             Arg3: Font effects.
; Return:     eax = HRESULT.

Method IScriptOutput.Font, uses xsi, pFaceStr:BSTR, dHeight:DWORD, dEffects:DWORD
  local hDC:HDC

  DbgText "IScriptOutput.Font"
  SetObject xsi
  mov hDC, $invoke(GetWindowDC, [xsi].hControl)
  invoke GetDeviceCaps, hDC, LOGPIXELSY
  invoke MulDiv, dHeight, 1920, eax
  mov [xsi].CFD.yHeight, eax
  invoke ReleaseDC, [xsi].hControl, hDC
  invoke BStr2Str, addr [xsi].CFD.szFaceName, pFaceStr
  m2m [xsi].CFD.dwEffects, dEffects, edx
  xor eax, eax                                          ;S_OK
MethodEnd
