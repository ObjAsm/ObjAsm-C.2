; ==================================================================================================
; Title:      Api3DEng_Main.inc
; Author:     G. Friedrich
; Version:    See Api3DEng.asm
; Purpose:    ObjAsm API 3D Engine program.
; ==================================================================================================


CLSSTYLE        equ CS_BYTEALIGNWINDOW or CS_BYTEALIGNCLIENT or CS_VREDRAW or CS_HREDRAW
SBSTYLE         equ WS_CHILD or WS_VISIBLE or SBARS_TOOLTIPS or SBARS_SIZEGRIP
ROTSPEED        equ 0.025

FPS               = 60
TIMER_RESOLUTION  = 1
TIMER_PERIOD      = 1000/FPS
OBJECT_RESOLUTION = 1

.const
AppStatusbar DEF_STATUSBAR {IDC_STATUSBAR, SBSTYLE, 0, 4}
  DEF_STATUSBAR_PART {220, 100, 3, SBT_NOBORDERS, NULL}
  DEF_STATUSBAR_PART {120,  20, 1, SBT_SUNKEN,    NULL}
  DEF_STATUSBAR_PART {120,  -2, 0, SBT_SUNKEN,    NULL}       ;Spring
  DEF_STATUSBAR_PART {120, 100, 2, SBT_SUNKEN,    NULL}

CReal4 r4RotInc1,      0.03                                   ;Blue sphere spin angle inc. value
CReal4 r4RotInc2,      -ROTSPEED                              ;Grey sphere spin angle inc. value
CReal4 r4RotIncCam,    0.025                                  ;Camera rotation angle inc. value
CReal4 r4OrbitRadius,  250.0                                  ;Grey sphere orbit radius
CReal4 r4OrbAngInc,    ROTSPEED                               ;Orbit angle inc. for each time slice

DplVctrLight1   D3Vector      { 0000.0,-5000.0,  000.0}       ;Light displacement vector
DplVector1      D3Vector      {  300.0,  250.0,  000.0}       ;Blue sphere initial position
DplVector2      D3Vector      {  550.0,  250.0,  000.0}       ;Grey sphere initial position

; ——————————————————————————————————————————————————————————————————————————————————————————————————

CStr szApi3DEngApp, "OAC_Api3DEngApp"

Object Application, ApplicationID, SdiApp                        ;SDI application.
  StaticMethod      Animate,     DWORD
  StaticMethod      Draw
  RedefineMethod    Done
  RedefineMethod    Init
  RedefineMethod    OnSize,           WPARAM, LPARAM
  StaticMethod      RotateCamera,     DWORD
  StaticMethod      RotateSphere,     DWORD, DWORD
  StaticMethod      SceneWireDraw
  StaticMethod      Startup
  StaticMethod      StatusbarHelp,    POINTER                 ;-> Help string
  StaticMethod      Move1
  StaticMethod      Move2

  VirtualEvent      OnClose,          WM_CLOSE, WM_QUERYENDSESSION
  VirtualEvent      OnCommand,        WM_COMMAND
  VirtualEvent      OnCreate,         WM_CREATE
  VirtualEvent      OnDestroy,        WM_DESTROY
  VirtualEvent      OnEraseBkgnd,     WM_ERASEBKGND
  VirtualEvent      OnKeyDown,        WM_KEYDOWN
  VirtualEvent      OnPaint,          WM_PAINT

  DefineVariable    pIconImageList,   $ObjPtr(MaskedImageList),  NULL
  DefineVariable    pStatusbar,       $ObjPtr(Statusbar),        NULL
  DefineVariable    pXMenu,           $ObjPtr(XMenu),            NULL
  DefineVariable    hMenuInit,        HMENU,      0

  DefineVariable    pScene,           $ObjPtr(D3Scene),          NULL
  DefineVariable    pObject1,         $ObjPtr(D3Object),         NULL
  DefineVariable    pObject2,         $ObjPtr(D3Object),         NULL
  DefineVariable    pCamera1,         $ObjPtr(D3Camera),         NULL
  DefineVariable    pLight1,          $ObjPtr(D3Light),          NULL
  DefineVariable    hMemDC,           HDC,        0
  DefineVariable    hMemBmp,          HBITMAP,    0
  DefineVariable    hMemPen,          HPEN,       0
  DefineVariable    hMemBrush,        HBRUSH,     0
  DefineVariable    hPrevMemBmp,      HBITMAP,    0
  DefineVariable    hPrevMemPen,      HPEN,       0
  DefineVariable    hPrevMemBrush,    HBRUSH,     0
  DefineVariable    dSlow,            DWORD,      FALSE
  DefineVariable    hDrawThread,      HANDLE,     0
  DefineVariable    hEventWorkInit1,  HANDLE,     0
  DefineVariable    hEventWorkInit2,  HANDLE,     0
  DefineVariable    hEventWorkDone1,  HANDLE,     0                       ;Keep hEventWorkDone1 &
  DefineVariable    hEventWorkDone2,  HANDLE,     0                       ;hEventWorkDone2 together
  DefineVariable    hWorkerThread1,   HANDLE,     0
  DefineVariable    hWorkerThread2,   HANDLE,     0
  DefineVariable    dStopDrawing,     DWORD,      FALSE
  DefineVariable    dStopWorking,     DWORD,      FALSE
  DefineVariable    dPauseDrawing,    DWORD,      FALSE
  DefineVariable    dAnimating,       DWORD,      TRUE
  DefineVariable    dFrameCounter,    DWORD,      0
  DefineVariable    hWaitTimer,       HANDLE,     0

  DefineVariable    RotVector1,       D3Vector,   { 000.0, 000.0, 000.0}  ;Blue sphere rot. vector
  DefineVariable    RotVector2,       D3Vector,   { 000.0, 000.0, 000.0}  ;Grey sphere rot. vector
  DefineVariable    r4OrbitAngle,     REAL4,      0.0                     ;Current orbit angle
  DefineVariable    OrbitVector,      D3Vector,   { 000.0, 000.0, 000.0}  ;Orbit vector
  DefineVariable    CamDplVector,     D3Vector,   { 000.0, 000.0, 000.0}  ;Camera displacement
  DefineVariable    CamRotVector,     D3Vector,   { 0.000, 0.000, 0.000}  ;Camera rotation

  Embed   SW,  StopWatch
ObjectEnd



; ==================================================================================================
;    Application implementation
; ==================================================================================================

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Application.Animate
; Purpose:    Animate the scene.
; Arguments:  Arg1: => TRUE, starts the animation, FALSE, stops it.
; Return:     Nothing.

Method Application.Animate, uses xsi, dAction:DWORD
  SetObject xsi
  ?mov edx, dAction
  mov [xsi].dAnimating, edx
  .if edx != FALSE
    mov [xsi].dPauseDrawing, FALSE
  .else
    mov [xsi].dPauseDrawing, TRUE
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Application.Draw
; Purpose:    Drawing thread procedure.
; Arguments:  None.
; Return:     Nothing.

Method Application.Draw, uses xsi
  local FT:FILETIME

  SetObject xsi
  mov FT.dwHighDateTime, 0
  mov FT.dwLowDateTime, 0
  invoke timeBeginPeriod, TIMER_RESOLUTION
  invoke SetWaitableTimer, [xsi].hWaitTimer, addr FT, TIMER_PERIOD, NULL, NULL, FALSE

  .while TRUE
    invoke WaitForSingleObject, [xsi].hWaitTimer, 500
    .break .if [xsi].dStopDrawing != FALSE
    .continue .if [xsi].dPauseDrawing != FALSE
    invoke SetEvent, [xsi].hEventWorkInit1                ;Start Worker 1
    invoke SetEvent, [xsi].hEventWorkInit2                ;Start Worker 2
    invoke WaitForMultipleObjects, 2, addr [xsi].hEventWorkDone1, TRUE, -1  ;Wait for completion
    OCall [xsi].pScene::D3Scene.Project                   ;Render the scene
    invoke RedrawWindow, [xsi].hWnd, 0, 0, RDW_ERASE or RDW_INVALIDATE or RDW_UPDATENOW ;Update
  .endw
  invoke CancelWaitableTimer, [xsi].hWaitTimer
  invoke timeEndPeriod, TIMER_RESOLUTION
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Application.Done
; Purpose:    Finalize the SDI application object. Objects associated with window controls are
;             destroyed by Windows automatically when WM_DESTROY is send.
; Arguments:  None.
; Return:     Nothing.

Method Application.Done, uses xsi
  SetObject xsi

  mov [xsi].dStopDrawing, TRUE                          ;Signal stop drawing
  invoke WaitForSingleObject, [xsi].hDrawThread, 100
  invoke CloseHandle, [xsi].hDrawThread

  mov [xsi].dStopWorking, TRUE                          ;Signal stop working
  invoke SetEvent, [xsi].hEventWorkInit1                ;Start Worker 1
  invoke SetEvent, [xsi].hEventWorkInit2                ;Start Worker 2
  invoke WaitForMultipleObjects, 2, addr [xsi].hWorkerThread1, TRUE, 100
  invoke CloseHandle, [xsi].hWorkerThread1
  invoke CloseHandle, [xsi].hWorkerThread2

  invoke CloseHandle, [xsi].hWaitTimer
  invoke DeleteObject, $invoke(SelectObject, [xsi].hMemDC, [xsi].hPrevMemPen)
  invoke DeleteObject, $invoke(SelectObject, [xsi].hMemDC, [xsi].hPrevMemBrush)
  invoke DeleteObject, $invoke(SelectObject, [xsi].hMemDC, [xsi].hPrevMemBmp)
  invoke DeleteDC, [xsi].hMemDC

  Destroy [xsi].pIconImageList
  Destroy [xsi].pStatusbar
  Destroy [xsi].pXMenu

  Destroy [xsi].pScene

  ACall xsi.Done
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Application.Init
; Purpose:    Initialize the SDI application object.
; Arguments:  None.
; Return:     Nothing.

Method Application.Init, uses xbx xdi xsi
  local dWndPosX:DWORD, dWndPosY:DWORD, dWndWidth:DWORD, dWndHeight:DWORD

  SetObject xsi
  ACall xsi.Init

  ;Startup
  mov [xsi].pCommandLine, $invoke(GetCommandLine)
  invoke LoadCommonControls, ICC_BAR_CLASSES            ;Statusbar

  ;Load application & menu icons
  mov xbx, $New(MaskedImageList)
  OCall xbx::MaskedImageList.Init, xsi, 16, 16, 1
  mov [xsi].pIconImageList, xbx
  OCall xbx::MaskedImageList.IconLoadResource, $OfsCStr("ICON_APP")
  OCall xbx::MaskedImageList.IconLoadResource, $OfsCStr("ICON_FILE_OPEN")
  OCall xbx::MaskedImageList.IconLoadResource, $OfsCStr("ICON_FILE_SAVE")
  OCall xbx::MaskedImageList.IconLoadResource, $OfsCStr("ICON_FILE_EXIT")
  OCall xbx::MaskedImageList.IconLoadResource, $OfsCStr("ICON_SCENE_ANIMATE")
  OCall xbx::MaskedImageList.IconLoadResource, $OfsCStr("ICON_SCENE_WIREFRAME")
  OCall xbx::MaskedImageList.IconLoadResource, $OfsCStr("ICON_HELP_HELP")
  OCall xbx::MaskedImageList.IconLoadResource, $OfsCStr("ICON_HELP_ABOUT")

  ;Obtain handles for possible menus and submenus
  mov [xsi].hMenuInit, $invoke(LoadMenu, hInstance, $OfsCStr("MENUINIT"))

  mov [xsi].hAccelerators, $invoke(LoadAccelerators, hInstance, $OfsCStr("ACCELS"))

  mov dWndWidth, 600
  mov dWndHeight, 550
  invoke GetSystemMetrics, SM_CXSCREEN
  invoke CenterForm, dWndWidth, eax
  mov dWndPosX, eax
  invoke GetSystemMetrics, SM_CYSCREEN
  invoke CenterForm, dWndHeight, eax
  mov dWndPosY, eax

  invoke CreateWindowEx, WS_EX_APPWINDOW or WS_EX_WINDOWEDGE,
                         offset szApi3DEngApp, offset szAppTitle, \
                         WS_OVERLAPPEDWINDOW or WS_CLIPCHILDREN, \
                         dWndPosX, dWndPosY, dWndWidth, dWndHeight, \
                         NULL, [xsi].hMenuInit, hInstance, pSelf
  mov [xsi].hWnd, xax

  ;Create XMenu
  mov [xsi].pXMenu, $New(XMenu)
  mov xdi, $MethodAddr(Application.StatusbarHelp)
  OCall [xsi].pXMenu::XMenu.Init, xsi, [xsi].hWnd, 0, [xsi].hMenuInit, xbx, \
                                  xdi, IDLANG_ENGLISH

  OCall [xsi].SW::StopWatch.Init, xsi
  s2s [xsi].SW.r8Resolution, $CReal8(1000.0), xax, xcx   ;miliseconds
  OCall [xsi].SW::StopWatch.Start
  ;-------------------------------------------------------------------------------------

  mov [xsi].hEventWorkInit1, $invoke(CreateEvent, NULL, FALSE, FALSE, NULL)
  mov [xsi].hEventWorkInit2, $invoke(CreateEvent, NULL, FALSE, FALSE, NULL)
  mov [xsi].hEventWorkDone1, $invoke(CreateEvent, NULL, FALSE, FALSE, NULL)
  mov [xsi].hEventWorkDone2, $invoke(CreateEvent, NULL, FALSE, FALSE, NULL)
  mov [xsi].hWaitTimer, $invoke(CreateWaitableTimer, NULL, FALSE, NULL)

  mov xbx, $MethodAddr(Application.Draw)
  mov [xsi].hDrawThread, $invoke(CreateThread, NULL, 0, xbx, xsi, CREATE_SUSPENDED, NULL)
  mov xbx, $MethodAddr(Application.Move1)
  mov [xsi].hWorkerThread1, $invoke(CreateThread, NULL, 0, xbx, xsi, CREATE_SUSPENDED, NULL)
  mov xbx, $MethodAddr(Application.Move2)
  mov [xsi].hWorkerThread2, $invoke(CreateThread, NULL, 0, xbx, xsi, CREATE_SUSPENDED, NULL)

  ;Create the scene, camera and light
  mov [xsi].pScene, $New(D3Scene)
  OCall [xsi].pScene::D3Scene.Init, xsi
  mov [xsi].pCamera1, $OCall([xsi].pScene::D3Scene.NewCamera)
  OCall [xsi].pCamera1::D3Camera.Move, addr [xsi].CamDplVector, addr [xsi].CamRotVector
  mov [xsi].pLight1, $OCall([xsi].pScene::D3Scene.NewLight)
  OCall [xsi].pLight1::D3Light.Move, offset DplVctrLight1

  ;Create big blue sphere
  OCall [xsi].pScene::D3Scene.CreateGeoSphere, OBJECT_RESOLUTION*20, OBJECT_RESOLUTION*16, 100.0, $RGB(0, 0, 255)
  mov [xsi].pObject1, xax
  OCall [xsi].pObject1::D3Object.Move, NULL, offset DplVector1

  ;Create little grey sphere
  OCall [xsi].pScene::D3Scene.CreateGeoSphere, OBJECT_RESOLUTION*12, OBJECT_RESOLUTION*10, 25.0, $RGB(128, 128, 128)
  mov [xsi].pObject2, xax
  OCall [xsi].pObject2::D3Object.Move, NULL, offset DplVector2

  ;Project the scene to the camera
  OCall [xsi].pScene::D3Scene.Project

  ;-------------------------------------------------------------------------------------
  invoke ResumeThread, [xsi].hWorkerThread1
  invoke ResumeThread, [xsi].hWorkerThread2
  invoke ResumeThread, [xsi].hDrawThread

  invoke ShowWindow, [xsi].hWnd, SW_SHOWNORMAL
  invoke UpdateWindow, [xsi].hWnd
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Application.OnClose
; Purpose:    Event procedure for WM_CLOSE and WM_QUERYENDSESSION message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method Application.OnClose, uses xsi, wParam:WPARAM, lParam:LPARAM
  SetObject xsi
  invoke MessageBox, [xsi].hWnd, $OfsCStr("Are you sure ?"), $OfsCStr("Application exit"), \
                 MB_YESNO or MB_ICONQUESTION
  .if eax == IDNO
    xor eax, eax
  .else
    invoke DefWindowProc, [xsi].hWnd, WM_CLOSE, wParam, lParam
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Application.OnCommand
; Purpose:    Event procedure for WM_COMMAND message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method Application.OnCommand, uses xbx xdi xsi, wParam:WPARAM, lParam:LPARAM
  local cBuffer[MAX_PATH]:CHR, Dlg:$Obj(DialogAbout)
  local DskStm:$Obj(DiskStream), DLUT:$Obj(DesLUT), DeserInfo:DESER_INFO, hIcon:HICON

  SetObject xsi
  mov xax, wParam
  .if ax ==  IDM_HELP_HELP
    invoke ExpandEnvironmentStrings, $OfsCStr("%OBJASM_PATH%\Help\ObjAsm_Reference_Volume-I.pdf"), \
                                     addr cBuffer, lengthof(cBuffer)
    invoke PdfView, [xsi].hWnd, addr cBuffer, NULL
    xor eax, eax

  .elseif ax == IDM_HELP_ABOUT
    New Dlg::DialogAbout
    mov hIcon, $invoke(LoadIcon, hInstance, $OfsCStr("ICON_APP"))
    OCall Dlg::DialogAbout.Init, xsi, [xsi].hWnd, hIcon, offset szAboutText
    OCall Dlg::DialogAbout.Show
    OCall Dlg::DialogAbout.Done
    invoke DestroyIcon, hIcon
    xor eax, eax

  .elseif ax == IDM_FILE_OPEN
      invoke FileExist, offset szScene
      .if eax != FALSE
        lea xdi, DskStm
        lea xbx, DLUT
        mov DeserInfo.pDesLUT, xbx
        New xbx::DesLUT
        OCall xbx::DesLUT.Init, xsi, DLT_MEM_PAGE, DLT_MEM_PAGE, DLT_MAX_CAPACITY
        New xdi::DiskStream
        OCall xdi::DiskStream.Init, xsi, offset szScene, 0, 0, NULL, 0, 0, 0
        OCall xdi::DiskStream.BinRead8                  ;Stored object bitness
        .if al == @WordSize
          OCall xdi::DiskStream.BinReadX               ;Read prev. appl instance
          OCall xbx::DesLUT.Insert, xax, xsi            ;Feed with new appl. instance
          Destroy [xsi].pScene
          OCall xdi::DiskStream.Get, addr DeserInfo
          .if xax != NULL
            mov [xsi].pScene, xax
            OCall [xsi].pScene::D3Scene.Deserialize, addr DeserInfo
            OCall xdi::DiskStream.BinRead, addr [xsi].RotVector1,   sizeof(D3Vector)
            OCall xdi::DiskStream.BinRead, addr [xsi].RotVector2,   sizeof(D3Vector)
            mov [xsi].r4OrbitAngle, $32($OCall(xdi::DiskStream.BinRead32))
            OCall xdi::DiskStream.BinRead, addr [xsi].OrbitVector,  sizeof(D3Vector)
            OCall xdi::DiskStream.BinRead, addr [xsi].CamDplVector, sizeof(D3Vector)
            OCall xdi::DiskStream.BinRead, addr [xsi].CamRotVector, sizeof(D3Vector)
            OCall xbx::DesLUT.Done
            OCall xdi::DiskStream.Done

            mov xbx, [xsi].pScene
            mov [xsi].pObject1, $OCall([xbx].$Obj(D3Scene).pObjects::Collection.ItemAt, 0)
            mov [xsi].pObject2, $OCall([xbx].$Obj(D3Scene).pObjects::Collection.ItemAt, 1)
            mov [xsi].pCamera1, $OCall([xbx].$Obj(D3Scene).pCameras::Collection.ItemAt, 0)
            mov [xsi].pLight1, $OCall([xbx].$Obj(D3Scene).pLights::Collection.ItemAt, 0)

            invoke RedrawWindow, [xsi].hWnd, 0, 0, RDW_ERASE or RDW_INVALIDATE or RDW_UPDATENOW
          .else
            invoke MessageBox, [xsi].hWnd, \
                               $OfsCStr("Failed to load scene from stream", 33, 10, 13, \
                                        "Application will be closed."), \
                               $OfsCStr("Error"), MB_OK or  MB_ICONEXCLAMATION
          .endif
        .else
          invoke MessageBox, [xsi].hWnd, \
                             $OfsCStr("Wrong stream wordsize", 33), \
                             $OfsCStr("Error"), MB_OK or  MB_ICONEXCLAMATION
        .endif
      .endif
      xor eax, eax

  .elseif ax == IDM_FILE_SAVE
    lea xdi, DskStm
    New xdi::DiskStream
    OCall xdi::DiskStream.Init, xsi, offset szScene, 0, 0, NULL, 0, 0, 0
    OCall xdi::DiskStream.BinWrite8, @WordSize
    OCall xdi::DiskStream.BinWriteX, xsi                ;Save application instance
    OCall [xsi].pScene::D3Scene.Serialize
    OCall xdi::DiskStream.Put, [xsi].pScene
    OCall xdi::DiskStream.BinWrite, addr [xsi].RotVector1,   sizeof(D3Vector)
    OCall xdi::DiskStream.BinWrite, addr [xsi].RotVector2,   sizeof(D3Vector)
    OCall xdi::DiskStream.BinWrite32, [xsi].r4OrbitAngle
    OCall xdi::DiskStream.BinWrite, addr [xsi].OrbitVector,  sizeof(D3Vector)
    OCall xdi::DiskStream.BinWrite, addr [xsi].CamDplVector, sizeof(D3Vector)
    OCall xdi::DiskStream.BinWrite, addr [xsi].CamRotVector, sizeof(D3Vector)
    OCall xdi::DiskStream.Done
    xor eax, eax

  .elseif ax == IDM_FILE_EXIT
    invoke SendMessage, [xsi].hWnd, WM_CLOSE, 0, 0
    xor eax, eax

  .elseif ax == IDM_SCENE_ANIMATE
    .if [xsi].dAnimating == FALSE
      OCall xsi.Animate, TRUE
    .else
      OCall xsi.Animate, FALSE
    .endif
  .elseif ax == IDM_SCENE_X1
    OCall xsi.RotateSphere, 0, 0
  .elseif ax == IDM_SCENE_X2
    OCall xsi.RotateSphere, 0, 1

  .elseif ax == IDM_SCENE_Y1
    OCall xsi.RotateSphere, 1, 0
  .elseif ax == IDM_SCENE_Y2
    OCall xsi.RotateSphere, 1, 1

  .elseif ax == IDM_SCENE_Z1
    OCall xsi.RotateSphere, 2, 0
  .elseif ax == IDM_SCENE_Z2
    OCall xsi.RotateSphere, 2, 1

  .elseif ax == IDM_SCENE_CAM1
    OCall xsi.RotateCamera, 0
  .elseif ax == IDM_SCENE_CAM2
    OCall xsi.RotateCamera, 1

  .elseif ax == IDM_SCENE_DRAWWIRE
    OCall xsi.SceneWireDraw
  .else
    invoke DefWindowProc, [xsi].hWnd, WM_COMMAND, wParam, lParam
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Application.OnCreate
; Purpose:    Event procedure for WM_CREATE message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = 0 to continue creation of the window.

Method Application.OnCreate, uses xsi, wParam:WPARAM, lParam:LPARAM
  SetObject xsi
  mov [xsi].pStatusbar, $New(Statusbar)
  OCall [xsi].pStatusbar::Statusbar.Init, xsi, [xsi].hWnd, offset AppStatusbar
  xor eax, eax
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Application.OnDestroy
; Purpose:    Event procedure for WM_DESTROY message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero.

Method Application.OnDestroy, uses xsi, wParam:WPARAM, lParam:LPARAM
  SetObject xsi
  invoke DestroyMenu, [xsi].hMenuInit
  invoke DestroyAcceleratorTable, [xsi].hAccelerators
  xor eax, eax
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Application.OnEraseBkgnd
; Purpose:    Event procedure for WM_ERASEBKGND message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Non zero if handled.

Method Application.OnEraseBkgnd,, wParam:WPARAM, lParam:LPARAM
  mov eax, 1                            ;To avoid flicker, we take care of repainting the background
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Application.OnKeyDown
; Purpose:    Event procedure for WM_KEYDOWN message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method Application.OnKeyDown, uses xsi, wParam:WPARAM, lParam:LPARAM
  SetObject xsi
  .if wParam == VK_SPACE
    .if [xsi].dAnimating == FALSE
      OCall xsi.Animate, TRUE
    .else
      OCall xsi.Animate, FALSE
    .endif
  .elseif wParam == VK_NUMPAD7
    OCall xsi.Animate, FALSE
    OCall xsi.RotateSphere, 0, 0
  .elseif wParam == VK_NUMPAD4
    OCall xsi.Animate, FALSE
    OCall xsi.RotateSphere, 0, 1
  .elseif wParam == VK_NUMPAD8
    OCall xsi.Animate, FALSE
    OCall xsi.RotateSphere, 1, 0
  .elseif wParam == VK_NUMPAD5
    OCall xsi.Animate, FALSE
    OCall xsi.RotateSphere, 1, 1
  .elseif wParam == VK_NUMPAD9
    OCall xsi.Animate, FALSE
    OCall xsi.RotateSphere, 2, 0
  .elseif wParam == VK_NUMPAD6
    OCall xsi.Animate, FALSE
    OCall xsi.RotateSphere, 2, 1
  .elseif wParam == VK_NUMPAD1
    OCall xsi.Animate, FALSE
    OCall xsi.RotateCamera, 0
  .elseif wParam == VK_NUMPAD3
    OCall xsi.Animate, FALSE
    OCall xsi.RotateCamera, 1
  .elseif wParam == "T"
    OCall xsi.Animate, FALSE
    OCall xsi.SceneWireDraw
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Application.OnPaint
; Purpose:    Event procedure for WM_PAINT message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method Application.OnPaint, uses xbx xsi, wParam:WPARAM, lParam:LPARAM
  local PS:PAINTSTRUCT, hDC:HDC, Rct:RECT, xTime:XWORD, cBuffer[100]:CHR

  SetObject xsi
  inc [xsi].dFrameCounter
  OCall [xsi].SW::StopWatch.Stop
  OCall [xsi].SW::StopWatch.GetTime
  .if xax != 0
    mov xTime, xax
    mov eax, [xsi].dFrameCounter
    mov ecx, 1000
    mul ecx
    xor edx, edx
    div xTime
    lea xbx, cBuffer
    WriteF xbx, "¦UX fps", xax
    invoke SetWindowText, [xsi].hWnd, addr cBuffer
  .endif
  OCall [xsi].SW::StopWatch.Start

  mov hDC, $invoke(BeginPaint, [xsi].hWnd, addr PS)
  invoke GetClientRect, [xsi].hWnd, addr Rct
  .if [xsi].dSlow != FALSE
    invoke FillRect, hDC, addr Rct, $invoke(GetStockObject, DKGRAY_BRUSH)
    invoke Sleep, 500
    OCall [xsi].pCamera1::D3Camera.Draw, hDC, TRUE
  .else
    invoke FillRect, [xsi].hMemDC, addr Rct, $invoke(GetStockObject, DKGRAY_BRUSH)
    OCall [xsi].pCamera1::D3Camera.Draw, [xsi].hMemDC, FALSE
    invoke BitBlt, hDC, 0, 0, Rct.right, Rct.bottom, [xsi].hMemDC, 0, 0, SRCCOPY
  .endif
  invoke EndPaint, [xsi].hWnd, addr PS

  xor eax, eax                                          ;Return zero
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Application.OnSize
; Purpose:    Event procedure for WM_SIZE message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method Application.OnSize, uses xbx xsi, wParam:WPARAM, lParam:LPARAM
  local Rct:RECT, hDC:HDC

  .if wParam != SIZE_MINIMIZED
    SetObject xsi
    invoke DefWindowProc, [xsi].hWnd, WM_SIZE, wParam, lParam
    invoke GetClientRect, [xsi].hWnd, addr Rct
    mov xbx, [xsi].pStatusbar
    invoke MoveWindow, [xbx].$Obj(Statusbar).hWnd, 0, 0, 0, 0, TRUE
    invoke UpdateWindow, [xbx].$Obj(Statusbar).hWnd

    .if [xsi].hMemDC != 0
      invoke DeleteObject, $invoke(SelectObject, [xsi].hMemDC, [xsi].hPrevMemPen)
      invoke DeleteObject, $invoke(SelectObject, [xsi].hMemDC, [xsi].hPrevMemBrush)
      invoke DeleteObject, $invoke(SelectObject, [xsi].hMemDC, [xsi].hPrevMemBmp)
      invoke DeleteDC, [xsi].hMemDC
    .endif
    mov hDC, $invoke(GetDC, [xsi].hWnd)
    mov [xsi].hMemDC, $invoke(CreateCompatibleDC, hDC)
    mov [xsi].hMemBmp, $invoke(CreateCompatibleBitmap, hDC, Rct.right, Rct.bottom)
    mov [xsi].hPrevMemBmp, $invoke(SelectObject, [xsi].hMemDC, [xsi].hMemBmp)
    mov [xsi].hMemPen, $invoke(CreatePen, PS_NULL, 1, 0)
;    mov [xsi].hMemPen, $invoke(CreatePen, PS_SOLID, 1, 0)
    mov [xsi].hPrevMemPen, $invoke(SelectObject, [xsi].hMemDC, [xsi].hMemPen)
    mov [xsi].hMemBrush, $invoke(CreateSolidBrush, 0)
    mov [xsi].hPrevMemBrush, $invoke(SelectObject, [xsi].hMemDC, [xsi].hMemBrush)
    invoke ReleaseDC, [xsi].hWnd, hDC
  .endif

  xor eax, eax                                          ;Return zero
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Application.MoveX
; Purpose:    ThreadProc for each Object to move.
; Arguments:  None.
; Return:     Nothing.

Method Application.Move1, uses xsi
  SetObject xsi
  .While TRUE
    invoke WaitForSingleObject, [xsi].hEventWorkInit1, -1
    .break .if [xsi].dStopWorking != FALSE
    lea xdx, [xsi].RotVector1

    fld [xdx].D3Vector.r4X
    fadd r4RotInc1
    fFitTrigRange
    fstp [xdx].D3Vector.r4X

    fld [xdx].D3Vector.r4Y
    fadd r4RotInc1
    fFitTrigRange
    fstp [xdx].D3Vector.r4Y

    fld [xdx].D3Vector.r4Z
    fadd r4RotInc1
    fFitTrigRange
    fstp [xdx].D3Vector.r4Z

    OCall [xsi].pObject1::D3Object.Move, addr [xsi].RotVector1, offset DplVector1
    invoke SetEvent, [xsi].hEventWorkDone1
  .endw
MethodEnd

Method Application.Move2, uses xsi
  SetObject xsi
  .While TRUE
    invoke WaitForSingleObject, [xsi].hEventWorkInit2, -1
    .break .if [xsi].dStopWorking != FALSE
    lea xdx, [xsi].OrbitVector
    fld r4OrbitRadius
    fld [xsi].r4OrbitAngle
    fsincos
    fmul st(0), st(2)
    fstp [xdx].D3Vector.r4X
    fmulp st(1), st(0)
    fstp [xdx].D3Vector.r4Z
    m2z [xdx].D3Vector.r4Y
    invoke VectorAddVector, xdx, xdx, offset DplVector1

    fld [xsi].r4OrbitAngle
    fadd r4OrbAngInc
    fstp [xsi].r4OrbitAngle

    lea xdx, [xsi].RotVector2
    fld [xdx].D3Vector.r4Y
    fadd r4RotInc2
    fstp [xdx].D3Vector.r4Y

    OCall [xsi].pObject2::D3Object.Move, addr [xsi].RotVector2 , addr [xsi].OrbitVector
    invoke SetEvent, [xsi].hEventWorkDone2
  .endw
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Application.RotateCamera
; Purpose:    Rotate the scene camera.
; Arguments:  Direction.
; Return:     Nothing.

Method Application.RotateCamera, uses xsi, dDirection:DWORD
  SetObject xsi

  OCall xsi.Animate, FALSE                         ;Stop animation

  lea xdx, [xsi].CamRotVector
  fld [xdx].D3Vector.r4X
  .if dDirection == 0                                   ;Increment
    fadd r4RotIncCam
  .else
    fsub r4RotIncCam                                    ;Decrement
  .endif
  fFitTrigRange
  fstp [xdx].D3Vector.r4X

  OCall [xsi].pCamera1::D3Camera.Move, addr [xsi].CamRotVector, NULL
  OCall [xsi].pScene::D3Scene.Project
  invoke RedrawWindow, [xsi].hWnd, 0, 0, RDW_ERASE or RDW_INVALIDATE or RDW_UPDATENOW
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Application.RotateSphere
; Purpose:    Rotate the big blue sphere.
; Arguments:  Arg1: Rotation axis.
;             Arg2: Direction.
; Return:     Nothing.

Method Application.RotateSphere, uses xsi, dAxis:DWORD, dDirection:DWORD
  SetObject xsi, Application

  OCall xsi.Animate, FALSE                         ;Stop animation
  OCall [xsi].pScene::D3Scene.Clear

  lea xdx, [xsi].RotVector1
  .if dAxis == 0                                        ;X axis
    fld [xdx].D3Vector.r4X
    .if dDirection == 0                                 ;Increment
      fadd r4RotInc1
    .else
      fsub r4RotInc1                                    ;Decrement
    .endif
    fFitTrigRange
    fstp [xdx].D3Vector.r4X
  .elseif dAxis == 1                                    ;Y axis
    fld [xdx].D3Vector.r4Y
    .if dDirection == 0                                 ;Increment
      fadd r4RotInc1
    .else
      fsub r4RotInc1                                    ;Decrement
    .endif
    fFitTrigRange
    fstp [xdx].D3Vector.r4Y
  .else                                                 ;Z axis
    fld [xdx].D3Vector.r4Z
    .if dDirection == 0                                 ;Increment
      fadd r4RotInc1
    .else
      fsub r4RotInc1                                    ;Decrement
    .endif
    fFitTrigRange
    fstp [xdx].D3Vector.r4Z
  .endif

  OCall [xsi].pObject1::D3Object.Move, addr [xsi].RotVector1, offset DplVector1
  OCall [xsi].pScene::D3Scene.Project
  invoke RedrawWindow, [xsi].hWnd, 0, 0, RDW_ERASE or RDW_INVALIDATE or RDW_UPDATENOW
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Application.SceneWireDraw
; Purpose:    Draw the scene showing all triangles with wires.
; Arguments:  None
; Return:     Nothing.

Method Application.SceneWireDraw, uses xsi
  SetObject xsi
  OCall xsi.Animate, FALSE
  mov [xsi].dSlow, TRUE
  invoke RedrawWindow, [xsi].hWnd, 0, 0, RDW_ERASE or RDW_INVALIDATE or RDW_UPDATENOW
  mov [xsi].dSlow, FALSE
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Application.Startup
; Purpose:    Register the object with the OS.
; Arguments:  None.
; Return:     Nothing.

Method Application.Startup
  local WC:WNDCLASSEX

  mov WC.cbSize, sizeof(WNDCLASSEX)
  mov WC.style, CLSSTYLE
  m2m WC.lpfnWndProc, $MethodAddr(Application.WndProc), xax
  m2z WC.cbClsExtra
  m2z WC.cbWndExtra
  m2m WC.hInstance, hInstance, xax
  mov WC.hbrBackground, $invoke(GetStockObject, BLACK_BRUSH)
  m2z WC.lpszMenuName
  c2m WC.lpszClassName, offset szApi3DEngApp, xax
  mov WC.hIcon, $invoke(LoadIcon, hInstance, $OfsCStr("ICON_APP"))
  mov WC.hCursor, $invoke(LoadCursor, 0, IDC_ARROW)
  m2z WC.hIconSm

  invoke RegisterClassEx, addr WC
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Application.StatusbarHelp
; Purpose:    Display a help string on panel 0 of the statusbar.
; Arguments:  Arg1: -> help string.
; Return:     Nothing.

Method Application.StatusbarHelp,, pHelpStr:POINTER
  SetObject xcx
  OCall [xcx].pStatusbar::Statusbar.SetPartText, 0, pHelpStr, SBT_NOBORDERS
MethodEnd
