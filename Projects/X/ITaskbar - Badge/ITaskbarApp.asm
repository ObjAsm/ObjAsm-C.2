; ==================================================================================================
; Title:      ITaskbarApp.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm ITaskbar Demo.
; Notes:      Version C.1.0, January 2023
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\Code\Macros\Model.inc   ;Include & initialize standard modules
SysSetup OOP, WIN64, WIDE_STRING;, DEBUG(WND)            ;Load OOP files and OS related objects

% includelib &LibPath&Windows\shell32.lib
% includelib &LibPath&Windows\shlwapi.lib
% includelib &LibPath&Windows\Ole32.lib
% includelib &LibPath&Windows\Msimg32.lib

% include &COMPath&COM.inc                              ;COM basic support
% include &IncPath&Windows\shObjIDL.inc

;Load or build the following objects
MakeObjects Primer, Stream, WinPrimer
MakeObjects Window, Button, Hyperlink, Dialog, DialogModal, DialogAbout
MakeObjects WinApp, SdiApp

include ITaskbarApp_Globals.inc                         ;Application globals
include ITaskbarApp_Main.inc                            ;Application object


.const                                                  ;GUID global constants
DefGUID IID_ITaskbarList4, <c43dc798-95d1-4bea-9030-bb99e2983a1a>
DefGUID CLSID_TaskbarList, <56fdf344-fd6d-11d0-958a-006097c9a090>

.data?
ThumbButtonArray THUMBBUTTON 4 dup(<>)

.code

BADGE_SIZE equ 16

CreateBadgeIcon proc uses xbx xdi xsi hDC:HDC, pText:PSTRING, dForeColor:DWORD, dBackColor:DWORD
  local hMemDC:HDC, hTxtDC:HDC, hIcoDC:HDC, BadgeRect:RECT
  local hMemBmp:HBITMAP, hPrvMemBmp:HBITMAP, hMskBmp:HBITMAP
  local hIcoBmp:HBITMAP, hPrvIcoBmp:HBITMAP, hTxtBmp:HBITMAP, hPrvTxtBmp:HBITMAP
  local IconInfo:ICONINFO, hIcon:HICON
  local hFont:HFONT, hPrvFont:HFONT, LogFnt:LOGFONT
  local BmpInfo:BITMAPINFO, pIcoBmpBuffer:POINTER, pTxtBmpBuffer:POINTER

  mov BadgeRect.left, 0
  mov BadgeRect.top, 0
  mov BadgeRect.right, BADGE_SIZE
  mov BadgeRect.bottom, BADGE_SIZE

  mov BmpInfo.bmiHeader.biSize, sizeof(BITMAPINFOHEADER)
  mov BmpInfo.bmiHeader.biWidth, BADGE_SIZE
  mov BmpInfo.bmiHeader.biHeight, BADGE_SIZE
  mov BmpInfo.bmiHeader.biPlanes, 1
  mov BmpInfo.bmiHeader.biBitCount, 32
  mov BmpInfo.bmiHeader.biCompression, BI_RGB
  mov BmpInfo.bmiHeader.biSizeImage, 4*BADGE_SIZE*BADGE_SIZE
  mov BmpInfo.bmiHeader.biXPelsPerMeter, 0
  mov BmpInfo.bmiHeader.biYPelsPerMeter, 0
  mov BmpInfo.bmiHeader.biClrUsed, 0
  mov BmpInfo.bmiHeader.biClrImportant, 0

  mov hMemDC, $invoke(CreateCompatibleDC, hDC)
  mov hTxtDC, $invoke(CreateCompatibleDC, hDC)
  mov hIcoDC, $invoke(CreateCompatibleDC, hDC)
  mov hMemBmp, $invoke(CreateCompatibleBitmap, hDC, BADGE_SIZE, BADGE_SIZE)
  mov hMskBmp, $invoke(CreateCompatibleBitmap, hDC, BADGE_SIZE, BADGE_SIZE)
  mov hIcoBmp, $invoke(CreateDIBSection, 0, addr BmpInfo, DIB_RGB_COLORS, addr pIcoBmpBuffer, 0, 0)
  mov hTxtBmp, $invoke(CreateDIBSection, 0, addr BmpInfo, DIB_RGB_COLORS, addr pTxtBmpBuffer, 0, 0)

  mov hPrvMemBmp, $invoke(SelectObject, hMemDC, hMemBmp)
  mov hPrvIcoBmp, $invoke(SelectObject, hIcoDC, hIcoBmp)
  mov hPrvTxtBmp, $invoke(SelectObject, hTxtDC, hTxtBmp)

  ;Create a mask for the badge form using the alpha channel too
  invoke LoadIcon, hInstance, $OfsCStr("ICON_BADGE_MASK")
  invoke DrawIconEx, hIcoDC, 0, 0, xax, BADGE_SIZE, BADGE_SIZE, 0, 0, DI_IMAGE

  ;Colorize the badge background
  mov xbx, pIcoBmpBuffer
  xor edi, edi
  mov ecx, dBackColor
  and ecx, 00FFFFFFh
  RGB2BGR ecx
  .while edi < BADGE_SIZE
    xor esi, esi
    .while esi < BADGE_SIZE
      mov eax, [xbx]
      and eax, 0FF000000h                               ;Keep the alpha value
      or eax, ecx                                       ;Replace with the background color
      mov [xbx], eax                                    ;Store
      add xbx, sizeof(DWORD)
      inc esi
    .endw
    inc edi
  .endw

  ;Draw badge text
  FillString LogFnt.lfFaceName, <Segoe UI>
  invoke GetDeviceCaps, hDC, LOGPIXELSY
  invoke MulDiv, 8, eax, -72
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
  mov LogFnt.lfQuality, NONANTIALIASED_QUALITY;CLEARTYPE_QUALITY
  mov LogFnt.lfPitchAndFamily, DEFAULT_PITCH or FF_DONTCARE
  mov hFont, $invoke(CreateFontIndirect, addr LogFnt)
  mov hPrvFont, $invoke(SelectObject, hMemDC, hFont)
  invoke PatBlt, hTxtDC, 0, 0, BADGE_SIZE, BADGE_SIZE, BLACKNESS
  mov edx, dForeColor
  test edx, edx                                         ;Check if it 0
  setz dl                                               ;Make it a bit different
  RGB2BGR edx
  invoke SetTextColor, hTxtDC, edx
  invoke SetBkMode, hTxtDC, TRANSPARENT
  invoke StrLength, pText
  lea xbx, BadgeRect
  invoke DrawText, hTxtDC, pText, eax, xbx, DT_CENTER or DT_VCENTER or DT_SINGLELINE

  ;Fix the alpha values and copy the new information into the IcoBuffer
  mov xbx, pTxtBmpBuffer
  mov xcx, pIcoBmpBuffer
  xor edi, edi
  .while edi < BADGE_SIZE
    xor esi, esi
    .while esi < BADGE_SIZE
      mov eax, [xbx]
      .if eax != 0
        or eax, 0FF000000h
        mov [xcx], eax
      .endif
      add xbx, sizeof(DWORD)
      add xcx, sizeof(DWORD)
      inc esi
    .endw
    inc edi
  .endw
  invoke BitBlt, hMemDC, 0, 0, BADGE_SIZE, BADGE_SIZE, hIcoDC, 0, 0, SRCPAINT

  mov IconInfo.fIcon, TRUE
  mov IconInfo.xHotspot, 0
  mov IconInfo.yHotspot, 0
  m2m IconInfo.hbmMask, hMskBmp, xax
  m2m IconInfo.hbmColor, hMemBmp, xcx

  mov hIcon, $invoke(CreateIconIndirect, addr IconInfo)

  ;Housekeeping
  invoke DeleteObject, $invoke(SelectObject, hMemDC, hPrvFont)
  invoke DeleteObject, $invoke(SelectObject, hMemDC, hPrvMemBmp)
  invoke DeleteDC, hMemDC
  invoke DeleteObject, $invoke(SelectObject, hIcoDC, hPrvIcoBmp)
  invoke DeleteDC, hIcoDC
  invoke DeleteObject, $invoke(SelectObject, hTxtDC, hPrvTxtBmp)
  invoke DeleteDC, hTxtDC
  invoke DeleteObject, hMskBmp

  mov xax, hIcon
  ret
CreateBadgeIcon endp

TaskBarAnimation proc uses xbx xdi hWnd:HWND
  local pTBL:POINTER, hIcon:HICON, wBuffer[256]:CHRW, hDC:HDC
  local cBuffer[20]:CHR

  ;ThumbButtons setup
  lea xbx, ThumbButtonArray
  invoke LoadIcon, hInstance, $OfsCStr("ICON_RED_DOT")
  mov [xbx].THUMBBUTTON.dwMask, THB_ICON or THB_TOOLTIP or THB_FLAGS
  mov [xbx].THUMBBUTTON.iId, 1
  mov [xbx].THUMBBUTTON.hIcon, xax
  FillStringW [xbx].THUMBBUTTON.szTip, <Red action>
  mov [xbx].THUMBBUTTON.dwFlags, THBF_ENABLED

  add xbx, sizeof(THUMBBUTTON)
  invoke LoadIcon, hInstance, $OfsCStr("ICON_GREEN_DOT")
  mov [xbx].THUMBBUTTON.dwMask, THB_ICON or THB_TOOLTIP or THB_FLAGS
  mov [xbx].THUMBBUTTON.iId, 2
  mov [xbx].THUMBBUTTON.hIcon, xax
  FillStringW [xbx].THUMBBUTTON.szTip, <Green action>
  mov [xbx].THUMBBUTTON.dwFlags, THBF_ENABLED

  add xbx, sizeof(THUMBBUTTON)
  invoke LoadIcon, hInstance, $OfsCStr("ICON_YELLOW_DOT")
  mov [xbx].THUMBBUTTON.dwMask, THB_ICON or THB_TOOLTIP or THB_FLAGS
  mov [xbx].THUMBBUTTON.iId, 3
  mov [xbx].THUMBBUTTON.hIcon, xax
  FillStringW [xbx].THUMBBUTTON.szTip, <Yellow action>
  mov [xbx].THUMBBUTTON.dwFlags, THBF_ENABLED

  add xbx, sizeof(THUMBBUTTON)
  invoke LoadIcon, hInstance, $OfsCStr("ICON_BLUE_DOT")
  mov [xbx].THUMBBUTTON.dwMask, THB_ICON or THB_TOOLTIP or THB_FLAGS
  mov [xbx].THUMBBUTTON.iId, 4
  mov [xbx].THUMBBUTTON.hIcon, xax
  FillStringW [xbx].THUMBBUTTON.szTip, <Blue action>
  mov [xbx].THUMBBUTTON.dwFlags, THBF_ENABLED

  ;Initialize COM library
  invoke CoInitializeEx, NULL, COINIT_APARTMENTTHREADED
  invoke CoCreateInstance, offset CLSID_TaskbarList, NULL,
                           CLSCTX_INPROC_SERVER, offset IID_ITaskbarList4, addr pTBL
  .if SUCCEEDED(eax)                                    ;If creation was successful
    ;Initialize and setup
    ICall pTBL::ITaskbarList4.HrInit
    ICall pTBL::ITaskbarList4.AddTab, hWnd
    ICall pTBL::ITaskbarList4.ActivateTab, hWnd

    ;Add a customized Thumbnail Tooltip
    lea xdi, wBuffer
    invoke GetCurrentProcessId
    FillStringW wBuffer, <ITaskbarApp - ProcessID: >
    invoke udword2decW, addr [wBuffer + ??StrSize - 2], eax
    ICall pTBL::ITaskbarList4.SetThumbnailTooltip, hWnd, addr wBuffer

    ;Add the 4 Thumbbar buttons
    ICall pTBL::ITaskbarList4.ThumbBarAddButtons, hWnd, 4, offset ThumbButtonArray

    mov hDC, $invoke(GetWindowDC, hWnd)
    .for(xbx = 1: ebx != 10: ebx ++)
      invoke udword2dec, addr cBuffer, ebx
      mov hIcon, $invoke(CreateBadgeIcon, hDC, addr cBuffer, $RGB(0,255,255), $RGB(255,128,32))
      ICall pTBL::ITaskbarList4.SetOverlayIcon, hWnd, hIcon, $OfsCStrW("Attention")
      invoke Sleep, 500
      invoke DestroyIcon, hIcon
    .endfor

    .for(xbx = 8: ebx != -1: ebx --)
      invoke udword2dec, addr cBuffer, ebx
      mov hIcon, $invoke(CreateBadgeIcon, hDC, addr cBuffer, $RGB(0,0,0), $RGB(32,196,32))
      ICall pTBL::ITaskbarList4.SetOverlayIcon, hWnd, hIcon, $OfsCStrW("Attention")
      invoke Sleep, 500
      invoke DestroyIcon, hIcon
    .endfor

    ICall pTBL::ITaskbarList4.SetOverlayIcon, hWnd, 0, NULL
    ICall pTBL::ITaskbarList4.Release

  .endif
  invoke CoUninitialize
  ret
TaskBarAnimation endp


start proc                                              ;Program entry point
  SysInit                                               ;Runtime initialization of OOP model

  OCall $ObjTmpl(Application)::Application.Init         ;Initialize application

  ;Start Taskbar animation in a new thread,
  ;otherwise the GUI will freeze in the meantime.
  invoke CreateThread, NULL, 0, addr TaskBarAnimation, $ObjTmpl(Application).hWnd, 0, NULL

  OCall $ObjTmpl(Application)::Application.Run          ;Execute application
  OCall $ObjTmpl(Application)::Application.Done         ;Finalize application

  SysDone                                               ;Runtime finalization of the OOP model
  invoke ExitProcess, 0                                 ;Exit program returning 0 to the OS
start endp

end
