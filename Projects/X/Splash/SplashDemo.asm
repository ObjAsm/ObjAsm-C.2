; ==================================================================================================
; Title:      SplashDemo.asm
; Author:     G. Friedrich
; Version:    1.0.0
; Purpose:    ObjAsm Splash Application.
; Notes:      Version 1.0.0, October 2017
;               - First release.
; ==================================================================================================


%include @Environ(OBJASM_PATH)\\Code\\Macros\\Model.inc ;Include & initialize standard modules
SysSetup OOP, WIN64, WIDE_STRING;, DEBUG(WND, ResGuard)  ;Load OOP files and OS related objects

GDIPVER equ 0100h

;% include &IncPath&Windows\GdiplusPixelFormats.inc
;% include &IncPath&Windows\GdiplusInit.inc
;% include &IncPath&Windows\GdiplusEnums.inc
;% include &IncPath&Windows\GdiplusGpStubs.inc
;% include &IncPath&Windows\GdiPlusFlat.inc

% includelib &LibPath&Windows\shell32.lib
% includelib &LibPath&Windows\shlwapi.lib
% includelib &LibPath&Windows\Ole32.lib
% includelib &LibPath&Windows\GdiPlus.lib

MakeObjects Primer, Stream                              ;Load or build the following objects
MakeObjects WinPrimer, Window, Button, Hyperlink, Dialog, DialogModal, DialogAbout
MakeObjects WinApp, SdiApp
MakeObjects Splash


.code
include SplashDemo_Globals.inc
include SplashDemo_Main.inc


start proc
  local hBmp:HBITMAP

  SysInit

  ResGuard_Start

  invoke LoadPngFromResource, $OfsCStr("PNG_SPLASH")
  mov hBmp, xax
  OCall $ObjTmpl(Splash)::Splash.Init, NULL, xax, $RGB(255, 0, 255)
  OCall $ObjTmpl(Splash)::Splash.FadeIn
  invoke Sleep, 2000
  OCall $ObjTmpl(SplashDemo)::SplashDemo.Init
  invoke Sleep, 1000
  OCall $ObjTmpl(Splash)::Splash.FadeOut
  OCall $ObjTmpl(Splash)::Splash.Done
  invoke DeleteObject, hBmp
  OCall $ObjTmpl(SplashDemo)::SplashDemo.Run
  OCall $ObjTmpl(SplashDemo)::SplashDemo.Done

  ResGuard_Show
  ResGuard_Stop

  SysDone
  invoke ExitProcess, 0
start endp

end
