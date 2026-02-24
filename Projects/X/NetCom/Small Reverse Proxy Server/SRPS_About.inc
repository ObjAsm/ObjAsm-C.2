; ==================================================================================================
; Title:      SRPS_About.inc
; Author:     G. Friedrich
; Version:    See SRPS.asm
; Purpose:    Protocol for a bidirectional Small Reverse Proxy Server.
; ==================================================================================================


; --------------------------------------------------------------------------------------------------
; Object:     DialogAbout
; Purpose:    Generic modal about dialog. It shows a single text on a static control.
;             This dialog uses the DIALOGABOUT resource which must be located in main resource
;             file (*.rc). DialogAbout.rc must be included for this purpose.

Object DialogAbout, DialogAboutID, DialogModal
  RedefineMethod    CtlsSet
  RedefineMethod    Done
  RedefineMethod    Init,             POINTER, HWND
  VirtualEvent      OnCtlColorStatic, WM_CTLCOLORSTATIC
  VirtualEvent      OnNotify,         WM_NOTIFY

  Embed             TxtView,          TextView
ObjectEnd


; ==================================================================================================

if IMPLEMENT

VIEW_CTRL_ID      equ   165874

APP_VISIT_MASM    equ   0
APP_VISIT_OBJASM  equ   1
APP_EMAIL         equ   2
APP_CHECK         equ   3

INFO_BUILD        equ   0
INFO_UPDATE       equ   1

LOGO_COLOR equ  <C#107CBE>
LINK_COLOR equ  <C#0000EE>
INFO_COLOR equ  LOGO_COLOR

$Quoted macro Args:vararg
  exitm @CatStr(<!">, %Args, <!">)
endm

ifdef __UASM__
  ANAME     textequ <UASM>
  AVERSION  equ __UASM__
elseifdef __JWASM__
  ANAME     textequ <JWASM>
  AVERSION  equ __JWASM__
elseifdef __ASMC__
  ANAME     textequ <ASMC>
  AVERSION  equ __ASMC__
else
  ANAME     textequ <MASM>
  AVERSION  equ  @Version
endif

if TARGET_MODE eq MODE_RLS
  DNAME     textequ <RELEASE>
else
  DNAME     textequ <DEBUG>
endif

.data
%String szAboutMarkupDE, \
  "{PA 20}", \
  "[H+1]", \
    "{C 0}", \
    "[FI 180]", \
      "[H+3,B]&ABOUT_TEXT{B}[~]", \
      "[I]Version &VER_PRODUCTVERSION_STR{P}[~]", \
      "[C#3F3F3F]", \
        "Developed using ObjAsm{B}", \
        "© &COPYRIGHT{P}", \
          $Quoted(BUILD_DATE_STR, <<  -  Build: >>, %BUILD_NUMBER, <->, \
                  %ASSEMBLER, <->, %TARGET_MODE_STR, <->, %TARGET_BITNESS), \
          "    [TIP ", $Quoted(INFO_BUILD), ",F'Webdings',H+1,",$Quoted(INFO_COLOR), "]{#F069}[~]", \
        "[~]{B}", \
      "[~]", \
    "[~]"
%ExtendString \
    "{TR 270}{TL 300}", \
    "[FI 0,H+1]{B}{LINE}{B}", \
      "{T}[F'Webdings',C#FF5F5F,H+7]{#F07E}[~]", \
      "  Visit the MASM web portal", \
      "{T}[APP ",$Quoted(APP_VISIT_MASM),",",$Quoted(LINK_COLOR),",U]masm32.com[~]{B}", \
      "{T}or the ObjAsm project", \
      "{T}[APP ",$Quoted(APP_VISIT_OBJASM), ",",$Quoted(LINK_COLOR),",U]www.objasm.x10host.com[~]{P}", \
      "{T}[F'Wingdings',C#0000FF,H+1]{#F02A}[~]", \
      "  Send us an E-Mail to", \
      "{T}[APP ",$Quoted(APP_EMAIL),",",$Quoted(LINK_COLOR),",U]objasm@gmx.net[~]{B}{B}{B}", \
      "[AC][APP ",$Quoted(APP_CHECK),",",$Quoted(LINK_COLOR),",U]Application Updates[~]", \
      "[TIP ", $Quoted(INFO_UPDATE),",F'Webdings',H+1,",$Quoted(INFO_COLOR),"]  {#F069}[~]", \
    "[~]", \
  "[~]"

CStr szUpdateInfo,    "Checks the availability of updates for this application."

%CStr szBuildInfo,    "Build Number:  ", 9, @CatStr(<!">, %BUILD_NUMBER, <!">), 13, \
                      "Assembler:    ", 9, @CatStr(<!">, %ANAME, <!">), 13, \
                      "Version:      ", 9, @CatStr(<!">, %AVERSION, <!">), 13, \
                      "Distribution: ", 9, @CatStr(<!">, %DNAME, <!">), 13, \
                      "Bitness:      ", 9, @CatStr(<!">, %TARGET_BITNESS, <!">)


.code
; --------------------------------------------------------------------------------------------------
; Method:       DialogAbout.CtlsSet
; Purpose:      Setup the controls of the About dialog.
; Arguments:    None.
; Return:       Nothing.

Method DialogAbout.CtlsSet, uses xsi
  local CRect:RECT, Def:DEF_TEXTVIEW

  SetObject xsi
  invoke GetClientRect, [xsi].hWnd, addr CRect
  sub CRect.bottom, 55
  mov Def.xCtlID, VIEW_CTRL_ID
  mov Def.dStyle, 0
  mov Def.dExStyle, 0
  c2m Def.pText, offset szAboutMarkupDE, xax
  mov Def.sdPosX, 0
  mov Def.sdPosY, 0
  m2m Def.dWidth, CRect.right, ecx
  m2m Def.dHeight, CRect.bottom, edx
  OCall [xsi].TxtView::TextView.Init, xsi, [xsi].hWnd, addr Def
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:       DialogAbout.Done
; Purpose:      Finalizes the dialog.
; Arguments:    None.
; Return:       Nothing.

Method DialogAbout.Done, uses xsi
  SetObject xsi
  OCall [xsi].TxtView::TextView.Done
  ACall xsi.Done
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:       DialogAbout.Init
; Purpose:      Initialize the about dialog using the "DIALOGABOUT" dialog resource.
; Arguments:    Arg1: -> Owner object.
;               Arg2: Parent window HANDLE.
; Return:       Nothing.

Method DialogAbout.Init,, pOwner:POINTER, hParent:HWND
  SetObject xcx
  ACall xcx::DialogAbout.Init, pOwner, hParent, IDD_ABOUT
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     DialogAbout.OnCtlColorStatic
; Purpose:    Event procedure for WM_CTLCOLORSTATIC message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     xax = Zero brush HANDLE.

Method DialogAbout.OnCtlColorStatic, uses xsi, wParam:WPARAM, lParam:LPARAM
  SetObject xsi
  invoke GetStockObject, WHITE_BRUSH
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     DialogAbout.OnNotify
; Purpose:    Event procedure for WM_NOTIFY message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     Nothing.

Method DialogAbout.OnNotify, uses xdi xsi, wParam:WPARAM, lParam:LPARAM
  local Img:$Obj(Image), DstRect:RECT

  SetObject xsi
  mov xax, wParam
  .if xax == VIEW_CTRL_ID
    mov xdi, lParam
    .if [xdi].NMHDR.code == TVNMC_APP_MOUSEUP
      .if [xdi].TVNM_APP.dID == APP_VISIT_MASM
        invoke ShellExecute, [xsi].hWnd, $OfsCStr("open"), \
                             $OfsCStr("https://masm32.com/"), \
                             NULL, NULL, SW_SHOW
      .elseif [xdi].TVNM_APP.dID == APP_VISIT_OBJASM
        invoke ShellExecute, [xsi].hWnd, $OfsCStr("open"), \
                             $OfsCStr("http://objasm.x10host.com"), \
                             NULL, NULL, SW_SHOW
      .elseif [xdi].TVNM_APP.dID == APP_EMAIL
        invoke ShellExecute, [xsi].hWnd, $OfsCStr("open"), \
                             $OfsCStr("mailto:objasm@gmx.net"), \
                             NULL, NULL, SW_SHOW
      .elseif [xdi].TVNM_APP.dID == APP_CHECK
        invoke MessageBox, [xsi].hWnd, $OfsCStr("No updates available."), \
                                       $OfsCStr("Information"), \
                                       MB_ICONINFORMATION or MB_OK
      .endif

    .elseif [xdi].NMHDR.code == TVNMC_TIP
      .if [xdi].TVNM_TIP.dID == INFO_BUILD
        c2m [xdi].TVNM_TIP.pText, offset szBuildInfo, xax

      .elseif [xdi].TVNM_TIP.dID == INFO_UPDATE
        c2m [xdi].TVNM_TIP.pText, offset szUpdateInfo, xax
      .endif

    .elseif [xdi].NMHDR.code == TVNMC_DRAW
      .if [xdi].TVNM_DRAW.dID == 0
        New Img::Image
        OCall Img::Image.Init, xsi
        OCall Img::Image.LoadFromRes, $OfsCStr("PNG_SRPS")
        mov DstRect.left, 35                            ;X-Coord. inside draw area, padding excl.
        mov DstRect.top, 15                             ;Y-Coord. inside draw area, padding excl.
        mov DstRect.right, 100                          ;Width
        mov DstRect.bottom, 100                         ;Height
        OCall Img::Image.AlphaDraw, [xdi].TVNM_DRAW.hDC, 255, addr DstRect
        OCall Img::Image.Done
      .endif
    .endif
  .endif
MethodEnd

endif
