;Include file created by h2incX, Version C.01.00, 15/01/2023 09:18
;(C) 2018-today by Biterider, 2005-2009 by Japheth
;Source file: 'dwmapi.h', last modified: 19/10/2022 13:01

ifndef _DWMAPI_H_
  _DWMAPI_H_ equ <>
  include winapifamily.inc
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    ifndef DWMAPI
      if  not Defined(_DWMAPI_)
        DWMAPI equ <EXTERN_C DECLSPEC_IMPORT HRESULT STDAPICALLTYPE>
        DWMAPI_ macro type_
          exitm <EXTERN_C DECLSPEC_IMPORT type_ STDAPICALLTYPE>
        endm
      else
        DWMAPI equ <STDAPI>
        DWMAPI_ macro type_
          exitm <STDAPI_(type_)>
        endm
      endif
    endif
    ifndef MILCORE_KERNEL_COMPONENT
      include wtypes.inc
      include uxtheme.inc
    endif
    include pshpack1.inc
    DWM_BB_ENABLE equ 00000001h
    DWM_BB_BLURREGION equ 00000002h
    DWM_BB_TRANSITIONONMAXIMIZED equ 00000004h
    DWM_BLURBEHIND struct
      dwFlags DWORD ?
      fEnable BOOL ?
      hRgnBlur HRGN ?
      fTransitionOnMaximized BOOL ?
    DWM_BLURBEHIND ends
    _DWM_BLURBEHIND typedef DWM_BLURBEHIND
    PDWM_BLURBEHIND typedef ptr DWM_BLURBEHIND
    
    DWMWINDOWATTRIBUTE typedef SDWORD
    DWMWA_NCRENDERING_ENABLED equ 1
    DWMWA_NCRENDERING_POLICY equ 2
    DWMWA_TRANSITIONS_FORCEDISABLED equ 3
    DWMWA_ALLOW_NCPAINT equ 4
    DWMWA_CAPTION_BUTTON_BOUNDS equ 5
    DWMWA_NONCLIENT_RTL_LAYOUT equ 6
    DWMWA_FORCE_ICONIC_REPRESENTATION equ 7
    DWMWA_FLIP3D_POLICY equ 8
    DWMWA_EXTENDED_FRAME_BOUNDS equ 9
    DWMWA_HAS_ICONIC_BITMAP equ 10
    DWMWA_DISALLOW_PEEK equ 11
    DWMWA_EXCLUDED_FROM_PEEK equ 12
    DWMWA_CLOAK equ 13
    DWMWA_CLOAKED equ 14
    DWMWA_FREEZE_REPRESENTATION equ 15
    DWMWA_PASSIVE_UPDATE_MODE equ 16
    DWMWA_USE_HOSTBACKDROPBRUSH equ 17
    DWMWA_USE_IMMERSIVE_DARK_MODE equ 20
    DWMWA_WINDOW_CORNER_PREFERENCE equ 33
    DWMWA_BORDER_COLOR equ 34
    DWMWA_CAPTION_COLOR equ 35
    DWMWA_TEXT_COLOR equ 36
    DWMWA_VISIBLE_FRAME_BORDER_THICKNESS equ 37
    DWMWA_SYSTEMBACKDROP_TYPE equ 38
    DWMWA_LAST equ 39
    
    DWM_WINDOW_CORNER_PREFERENCE typedef SDWORD
    DWMWCP_DEFAULT equ 0
    DWMWCP_DONOTROUND equ 1
    DWMWCP_ROUND equ 2
    DWMWCP_ROUNDSMALL equ 3
    
    DWMWA_COLOR_DEFAULT equ 0FFFFFFFFh
    DWMWA_COLOR_NONE equ 0FFFFFFFEh
    DWM_SYSTEMBACKDROP_TYPE typedef SDWORD
    DWMSBT_AUTO equ 0
    DWMSBT_NONE equ 1
    DWMSBT_MAINWINDOW equ 2
    DWMSBT_TRANSIENTWINDOW equ 3
    DWMSBT_TABBEDWINDOW equ 4
    
    DWMNCRENDERINGPOLICY typedef SDWORD
    DWMNCRP_USEWINDOWSTYLE equ 0
    DWMNCRP_DISABLED equ 1
    DWMNCRP_ENABLED equ 2
    DWMNCRP_LAST equ 3
    
    DWMFLIP3DWINDOWPOLICY typedef SDWORD
    DWMFLIP3D_DEFAULT equ 0
    DWMFLIP3D_EXCLUDEBELOW equ 1
    DWMFLIP3D_EXCLUDEABOVE equ 2
    DWMFLIP3D_LAST equ 3
    
    DWM_CLOAKED_APP equ 00000001h
    DWM_CLOAKED_SHELL equ 00000002h
    DWM_CLOAKED_INHERITED equ 00000004h
    HTHUMBNAIL typedef HANDLE
    PHTHUMBNAIL typedef ptr HTHUMBNAIL
    DWM_TNP_RECTDESTINATION equ 00000001h
    DWM_TNP_RECTSOURCE equ 00000002h
    DWM_TNP_OPACITY equ 00000004h
    DWM_TNP_VISIBLE equ 00000008h
    DWM_TNP_SOURCECLIENTAREAONLY equ 00000010h
    DWM_THUMBNAIL_PROPERTIES struct
      dwFlags DWORD ?
      rcDestination RECT <>
      rcSource RECT <>
      opacity BYTE ?
      fVisible BOOL ?
      fSourceClientAreaOnly BOOL ?
    DWM_THUMBNAIL_PROPERTIES ends
    _DWM_THUMBNAIL_PROPERTIES typedef DWM_THUMBNAIL_PROPERTIES
    PDWM_THUMBNAIL_PROPERTIES typedef ptr DWM_THUMBNAIL_PROPERTIES
    
    DWM_FRAME_COUNT typedef ULONGLONG
    QPC_TIME typedef ULONGLONG
    UNSIGNED_RATIO struct
      uiNumerator UINT32 ?
      uiDenominator UINT32 ?
    UNSIGNED_RATIO ends
    _UNSIGNED_RATIO typedef UNSIGNED_RATIO
    DWM_TIMING_INFO struct
      cbSize UINT32 ?
      rateRefresh UNSIGNED_RATIO <>
      qpcRefreshPeriod QPC_TIME ?
      rateCompose UNSIGNED_RATIO <>
      qpcVBlank QPC_TIME ?
      cRefresh DWM_FRAME_COUNT ?
      cDXRefresh UINT ?
      qpcCompose QPC_TIME ?
      cFrame DWM_FRAME_COUNT ?
      cDXPresent UINT ?
      cRefreshFrame DWM_FRAME_COUNT ?
      cFrameSubmitted DWM_FRAME_COUNT ?
      cDXPresentSubmitted UINT ?
      cFrameConfirmed DWM_FRAME_COUNT ?
      cDXPresentConfirmed UINT ?
      cRefreshConfirmed DWM_FRAME_COUNT ?
      cDXRefreshConfirmed UINT ?
      cFramesLate DWM_FRAME_COUNT ?
      cFramesOutstanding UINT ?
      cFrameDisplayed DWM_FRAME_COUNT ?
      qpcFrameDisplayed QPC_TIME ?
      cRefreshFrameDisplayed DWM_FRAME_COUNT ?
      cFrameComplete DWM_FRAME_COUNT ?
      qpcFrameComplete QPC_TIME ?
      cFramePending DWM_FRAME_COUNT ?
      qpcFramePending QPC_TIME ?
      cFramesDisplayed DWM_FRAME_COUNT ?
      cFramesComplete DWM_FRAME_COUNT ?
      cFramesPending DWM_FRAME_COUNT ?
      cFramesAvailable DWM_FRAME_COUNT ?
      cFramesDropped DWM_FRAME_COUNT ?
      cFramesMissed DWM_FRAME_COUNT ?
      cRefreshNextDisplayed DWM_FRAME_COUNT ?
      cRefreshNextPresented DWM_FRAME_COUNT ?
      cRefreshesDisplayed DWM_FRAME_COUNT ?
      cRefreshesPresented DWM_FRAME_COUNT ?
      cRefreshStarted DWM_FRAME_COUNT ?
      cPixelsReceived ULONGLONG ?
      cPixelsDrawn ULONGLONG ?
      cBuffersEmpty DWM_FRAME_COUNT ?
    DWM_TIMING_INFO ends
    _DWM_TIMING_INFO typedef DWM_TIMING_INFO
    DWM_SOURCE_FRAME_SAMPLING typedef SDWORD
    DWM_SOURCE_FRAME_SAMPLING_POINT equ 0
    DWM_SOURCE_FRAME_SAMPLING_COVERAGE equ 1
    DWM_SOURCE_FRAME_SAMPLING_LAST equ 2
    
    DWM_PRESENT_PARAMETERS struct
      cbSize UINT32 ?
      fQueue BOOL ?
      cRefreshStart DWM_FRAME_COUNT ?
      cBuffer UINT ?
      fUseSourceRate BOOL ?
      rateSource UNSIGNED_RATIO <>
      cRefreshesPerFrame UINT ?
      eSampling DWM_SOURCE_FRAME_SAMPLING ?
    DWM_PRESENT_PARAMETERS ends
    _DWM_PRESENT_PARAMETERS typedef DWM_PRESENT_PARAMETERS
    DWM_FRAME_DURATION_DEFAULT equ -1
    DwmDefWindowProc proto WIN_STD_CALL_CONV :HWND, :UINT, :WPARAM, :LPARAM, :ptr LRESULT
    @DefProto DllImport, DwmEnableBlurBehindWindow, WIN_STD_CALL_CONV,, <:HWND, :ptr DWM_BLURBEHIND>, 8
    DWM_EC_DISABLECOMPOSITION equ 0
    DWM_EC_ENABLECOMPOSITION equ 1
    @DefProto DllImport, DwmEnableComposition, WIN_STD_CALL_CONV,, <:UINT>, 4
    if NTDDI_VERSION ge NTDDI_WIN8
    endif
    @DefProto DllImport, DwmEnableMMCSS, WIN_STD_CALL_CONV,, <:BOOL>, 4
    @DefProto DllImport, DwmExtendFrameIntoClientArea, WIN_STD_CALL_CONV,, <:HWND, :ptr MARGINS>, 8
    @DefProto DllImport, DwmGetColorizationColor, WIN_STD_CALL_CONV,, <:ptr DWORD, :ptr BOOL>, 8
    @DefProto DllImport, DwmGetCompositionTimingInfo, WIN_STD_CALL_CONV,, <:HWND, :ptr DWM_TIMING_INFO>, 8
    @DefProto DllImport, DwmGetWindowAttribute, WIN_STD_CALL_CONV,, <:HWND, :DWORD, :PVOID, :DWORD>, 16
    @DefProto DllImport, DwmIsCompositionEnabled, WIN_STD_CALL_CONV,, <:ptr BOOL>, 4
    @DefProto DllImport, DwmModifyPreviousDxFrameDuration, WIN_STD_CALL_CONV,, <:HWND, :INT_, :BOOL>, 12
    @DefProto DllImport, DwmQueryThumbnailSourceSize, WIN_STD_CALL_CONV,, <:HTHUMBNAIL, :PSIZE>, 8
    @DefProto DllImport, DwmRegisterThumbnail, WIN_STD_CALL_CONV,, <:HWND, :HWND, :PHTHUMBNAIL>, 12
    @DefProto DllImport, DwmSetDxFrameDuration, WIN_STD_CALL_CONV,, <:HWND, :INT_>, 8
    @DefProto DllImport, DwmSetPresentParameters, WIN_STD_CALL_CONV,, <:HWND, :ptr DWM_PRESENT_PARAMETERS>, 8
    @DefProto DllImport, DwmSetWindowAttribute, WIN_STD_CALL_CONV,, <:HWND, :DWORD, :LPCVOID, :DWORD>, 16
    @DefProto DllImport, DwmUnregisterThumbnail, WIN_STD_CALL_CONV,, <:HTHUMBNAIL>, 4
    @DefProto DllImport, DwmUpdateThumbnailProperties, WIN_STD_CALL_CONV,, <:HTHUMBNAIL, :ptr DWM_THUMBNAIL_PROPERTIES>, 8
    if (_WIN32_WINNT ge 0601h)
      DWM_SIT_DISPLAYFRAME equ 00000001h
      @DefProto DllImport, DwmSetIconicThumbnail, WIN_STD_CALL_CONV,, <:HWND, :HBITMAP, :DWORD>, 12
      @DefProto DllImport, DwmSetIconicLivePreviewBitmap, WIN_STD_CALL_CONV,, <:HWND, :HBITMAP, :ptr POINT, :DWORD>, 16
      @DefProto DllImport, DwmInvalidateIconicBitmaps, WIN_STD_CALL_CONV,, <:HWND>, 4
    endif
    @DefProto DllImport, DwmAttachMilContent, WIN_STD_CALL_CONV,, <:HWND>, 4
    @DefProto DllImport, DwmDetachMilContent, WIN_STD_CALL_CONV,, <:HWND>, 4
    @DefProto DllImport, DwmFlush, WIN_STD_CALL_CONV,, <>, 0
    ifndef MILCORE_KERNEL_COMPONENT
      ifndef _MIL_MATRIX3X2D_DEFINED
        MilMatrix3x2D struct
          S_11 DOUBLE ?
          S_12 DOUBLE ?
          S_21 DOUBLE ?
          S_22 DOUBLE ?
          DX_ DOUBLE ?
          DY DOUBLE ?
        MilMatrix3x2D ends
        _MilMatrix3x2D typedef MilMatrix3x2D
        _MIL_MATRIX3X2D_DEFINED equ <>
      endif
      ifndef MILCORE_MIL_MATRIX3X2D_COMPAT_TYPEDEF
        MIL_MATRIX3X2D typedef MilMatrix3x2D
        MILCORE_MIL_MATRIX3X2D_COMPAT_TYPEDEF equ <>
      endif
      @DefProto DllImport, DwmGetGraphicsStreamTransformHint, WIN_STD_CALL_CONV,, <:UINT, :ptr MilMatrix3x2D>, 8
      @DefProto DllImport, DwmGetGraphicsStreamClient, WIN_STD_CALL_CONV,, <:UINT, :ptr UUID>, 8
    endif
    @DefProto DllImport, DwmGetTransportAttributes, WIN_STD_CALL_CONV,, <:ptr BOOL, :ptr BOOL, :ptr DWORD>, 12
    DWMTRANSITION_OWNEDWINDOW_TARGET typedef SDWORD
    DWMTRANSITION_OWNEDWINDOW_NULL equ -1
    DWMTRANSITION_OWNEDWINDOW_REPOSITION equ 0
    
    @DefProto DllImport, DwmTransitionOwnedWindow, WIN_STD_CALL_CONV,, <:HWND, :DWMTRANSITION_OWNEDWINDOW_TARGET>, 8
    if (NTDDI_VERSION ge NTDDI_WIN8)
      GESTURE_TYPE typedef SDWORD
      GT_PEN_TAP equ 0
      GT_PEN_DOUBLETAP equ 1
      GT_PEN_RIGHTTAP equ 2
      GT_PEN_PRESSANDHOLD equ 3
      GT_PEN_PRESSANDHOLDABORT equ 4
      GT_TOUCH_TAP equ 5
      GT_TOUCH_DOUBLETAP equ 6
      GT_TOUCH_RIGHTTAP equ 7
      GT_TOUCH_PRESSANDHOLD equ 8
      GT_TOUCH_PRESSANDHOLDABORT equ 9
      GT_TOUCH_PRESSANDTAP equ 10
      
      @DefProto DllImport, DwmRenderGesture, WIN_STD_CALL_CONV,, <:GESTURE_TYPE, :UINT, :ptr DWORD, :ptr POINT>, 16
      @DefProto DllImport, DwmTetherContact, WIN_STD_CALL_CONV,, <:DWORD, :BOOL, :POINT>, 16
      DWM_SHOWCONTACT typedef SDWORD
      DWMSC_DOWN equ 00000001h
      DWMSC_UP equ 00000002h
      DWMSC_DRAG equ 00000004h
      DWMSC_HOLD equ 00000008h
      DWMSC_PENBARREL equ 00000010h
      DWMSC_NONE equ 00000000h
      DWMSC_ALL equ 0FFFFFFFFh
      
      DEFINE_ENUM_FLAG_OPERATORS(DWM_SHOWCONTACT)
      @DefProto DllImport, DwmShowContact, WIN_STD_CALL_CONV,, <:DWORD, :DWM_SHOWCONTACT>, 8
    endif
    if (NTDDI_VERSION ge NTDDI_WIN10_RS4)
      DWM_TAB_WINDOW_REQUIREMENTS typedef SDWORD
      DWMTWR_NONE equ 0000h
      DWMTWR_IMPLEMENTED_BY_SYSTEM equ 0001h
      DWMTWR_WINDOW_RELATIONSHIP equ 0002h
      DWMTWR_WINDOW_STYLES equ 0004h
      DWMTWR_WINDOW_REGION equ 0008h
      DWMTWR_WINDOW_DWM_ATTRIBUTES equ 0010h
      DWMTWR_WINDOW_MARGINS equ 0020h
      DWMTWR_TABBING_ENABLED equ 0040h
      DWMTWR_USER_POLICY equ 0080h
      DWMTWR_GROUP_POLICY equ 0100h
      DWMTWR_APP_COMPAT equ 0200h
      
      DEFINE_ENUM_FLAG_OPERATORS(DWM_TAB_WINDOW_REQUIREMENTS)
      @DefProto DllImport, DwmGetUnmetTabRequirements, WIN_STD_CALL_CONV,, <:HWND, :ptr DWM_TAB_WINDOW_REQUIREMENTS>, 8
    endif
    include poppack.inc
  endif
endif
 