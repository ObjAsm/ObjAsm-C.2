; ==================================================================================================
; Title:      ADE_About.inc
; Author:     G. Friedrich
; Version:    See ACE.asm
; Purpose:    ObjAsm Assembler Development Environment.
; ==================================================================================================


; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Object:     DialogAbout
; Purpose:    Generic modal about dialog. It shows a single text on a static control.
;             This dialog uses the DIALOGABOUT resurce which must be located in application resource
;             file (*.rc). DialogAbout.rc may be included for this purpose.

Object DialogAbout, ADE_DialogAboutID, DialogModal
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

APP_VISIT_OBJASM  equ   0
APP_EMAIL         equ   1
APP_HELP          equ   2

INFO_BUILD        equ   0
INFO_UPDATE       equ   1

LOGO_COLOR equ  <C#107CBE>
LINK_COLOR equ  <C@26>
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


.const

String szAboutMarkup, \
  "{SX 600, PA 20}", \
  "[H+1]", \
    "{C 0}", \
    "[FI 190]", \
      "[H+3,B]&ABOUT_TEXT{B}[~]", \
      "[I]Version &VER_PRODUCTVERSION_STR{P}[~]", \
      "[C@17]", \
        "%s{B}", \
        "© &COPYRIGHT{P}", \
          $Quoted(BUILD_DATE_STR, <<  -  Build: >>, %BUILD_NUMBER, <->, \
                  %ASSEMBLER, <->, %TARGET_MODE_STR, <->, %TARGET_BITNESS), \
          "    [TIP ", $Quoted(INFO_BUILD), ",F'Webdings',H+1,",$Quoted(INFO_COLOR), "]{#F069}[~]", \
        "[~]{B}", \
      "[~]", \
    "[~]"
ExtendString \
    "{TR 280}{TL 300}", \
    "[FI 0,H+1]{B}{LINE}{B}", \
      "{T}[F'Webdings',C#FF5F5F,H+7]{#F07E}[~]", \
      "  %s", \
      "{T}[APP ",$Quoted(APP_VISIT_OBJASM), ",",$Quoted(LINK_COLOR),",U]www.objasm.x10host.com[~]{P}", \
      "{T}[F'Wingdings',C#0000FF,H+1]{#F02A}[~]", \
      "  %s", \
      "{T}[APP ",$Quoted(APP_EMAIL),",",$Quoted(LINK_COLOR),",U]objasm@gmx.net[~]", \
    "[~]", \
  "[~]"

%CStr szBuildInfo,    "Buildnumber:  ", 9, @CatStr(<!">, %BUILD_NUMBER, <!">), 13, \
                      "Assembler:    ", 9, @CatStr(<!">, %ANAME, <!">), 13, \
                      "Version:      ", 9, @CatStr(<!">, %AVERSION, <!">), 13, \
                      "Distribution: ", 9, @CatStr(<!">, %DNAME, <!">), 13, \
                      "Bitness:      ", 9, @CatStr(<!">, %TARGET_BITNESS, <!">)


.code
; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:       DialogAbout.CtlsSet
; Purpose:      Setup the controls of the About dialog.
; Arguments:    None.
; Return:       Nothing.

Method DialogAbout.CtlsSet, uses xbx xsi
  local CRect:RECT, TV_Def:DEF_TEXTVIEW
  local cResStr1[100]:CHR, cResStr2[100]:CHR, cResStr3[100]:CHR
  local cAboutStr[1024]:CHR

  SetObject xsi
  mov xax, [xsi].pOwner
;  mov ebx, [xax].$Obj(Application).dLanguage
;  invoke LoadString, hInstance, addr [ebx + 104], addr cAboutStr, lengthof(cAboutStr)
;  invoke SendMessage, [xsi].hWnd, WM_SETTEXT, 0, addr cAboutStr
;
;  invoke LoadString, hInstance, addr [ebx + 105], addr cResStr1, lengthof(cResStr1)
;  invoke LoadString, hInstance, addr [ebx + 106], addr cResStr2, lengthof(cResStr2)
;  invoke LoadString, hInstance, addr [ebx + 107], addr cResStr3, lengthof(cResStr3)
  lea xbx, cAboutStr
;  invoke wsprintf, xbx, offset szAboutMarkup, addr cResStr1, addr cResStr2, addr cResStr3
  invoke wsprintf, xbx, offset szAboutMarkup, NULL, $OfsCStr("Visit our Homepage"), $OfsCStr("Send us an E-Mail")

  invoke GetClientRect, [xsi].hWnd, addr CRect
  sub CRect.bottom, 55
  mov TV_Def.xCtlID, VIEW_CTRL_ID
  mov TV_Def.dStyle, 0
  mov TV_Def.dExStyle, 0
  m2m TV_Def.pText, xbx
  mov TV_Def.sdPosX, 0
  mov TV_Def.sdPosY, 0
  m2m TV_Def.dWidth, CRect.right, ecx
  m2m TV_Def.dHeight, CRect.bottom, edx
  OCall [xsi].TxtView::TextView.Init, xsi, [xsi].hWnd, addr TV_Def
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:       DialogAbout.Done
; Purpose:      Finalizes the dialog.
; Arguments:    None.
; Return:       Nothing.

Method DialogAbout.Done, uses xsi
  SetObject xsi
  OCall [xsi].TxtView::TextView.Done
  ACall xsi.Done
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:       DialogAbout.Init
; Purpose:      Initialize the about dialog using the "DIALOGABOUT" dialog resource.
; Arguments:    Arg1: -> Owner object.
;               Arg2: Parent window HANDLE.
; Return:       Nothing.

Method DialogAbout.Init,, pOwner:POINTER, hParent:HWND
  SetObject xcx
  ACall xcx::DialogAbout.Init, pOwner, hParent, 1000
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     DialogAbout.OnCtlColorStatic
; Purpose:    Event procedure for WM_CTLCOLORSTATIC message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     xax = Zero brush HANDLE.

Method DialogAbout.OnCtlColorStatic, uses xsi, wParam:WPARAM, lParam:LPARAM
  SetObject xsi
  invoke GetStockObject, WHITE_BRUSH
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     DialogAbout.OnNotify
; Purpose:    Event procedure for WM_NOTIFY message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     Nothing.

Method DialogAbout.OnNotify, uses xdi xsi, wParam:WPARAM, lParam:LPARAM
  local Img:$Obj(Image), DstRect:RECT, cFileName[MAX_PATH]:CHR

  SetObject xsi
  mov xax, wParam
  .if xax == VIEW_CTRL_ID
    mov xdi, lParam
    .if [xdi].NMHDR.code == TVNMC_APP_MOUSEUP
      .if [xdi].TVNM_APP.dID == APP_VISIT_OBJASM
        invoke ShellExecute, [xsi].hWnd, $OfsCStr("open"), \
                             $OfsCStr("http://objasm.x10host.com/index.htm"), \
                             NULL, NULL, SW_SHOW
      .elseif [xdi].TVNM_APP.dID == APP_EMAIL
        invoke ShellExecute, [xsi].hWnd, $OfsCStr("open"), \
                             $OfsCStr("mailto:objasm@gmx.net"), \
                             NULL, NULL, SW_SHOW
      .elseif [xdi].TVNM_APP.dID == APP_HELP
        invoke ExpandEnvironmentStrings, $OfsCStr("%OBJASM_PATH%\Help\ObjAsm_Reference_Volume-I.pdf"), \
                                         addr cFileName, lengthof(cFileName)
        invoke PdfView, [xsi].hWnd, addr cFileName, $OfsCStr("Debugging")
      .endif

    .elseif [xdi].NMHDR.code == TVNMC_TIP
      .if [xdi].TVNM_TIP.dID == INFO_BUILD
        c2m [xdi].TVNM_TIP.pText, offset szBuildInfo, xax
      .endif

    .elseif [xdi].NMHDR.code == TVNMC_DRAW
      .if [xdi].TVNM_DRAW.dID == 0
        New Img::Image
        OCall Img::Image.Init, xsi
        OCall Img::Image.LoadFromRes, $OfsCStr("PNG_ADE")
        mov DstRect.left, 40                            ;X-Coord. inside draw area, padding excl.
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
