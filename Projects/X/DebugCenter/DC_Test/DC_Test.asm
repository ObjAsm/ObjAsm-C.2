; ==================================================================================================
; Title:      DC_Test.asm
; Authors:    G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm DebugCenter test application.
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================

WIN32_LEAN_AND_MEAN         equ 1                       ;Necessary to exclude WinSock.inc
INTERNET_PROTOCOL_VERSION   equ 4

% include @Environ(OBJASM_PATH)\Code\Macros\Model.inc   ;Include & initialize standard modules
SysSetup OOP, WIN64, WIDE_STRING, DEBUG(WND, INFO, TRACE, STKGUARD)
;SysSetup OOP, WIN64, WIDE_STRING, DEBUG(NET, INFO, TRACE);, STKGUARD)
;DBG_IP_ADDR textequ <"localhost">
;DBG_IP_ADDR textequ <"192.168.1.43">
;DBG_IP_PORT textequ <8080>


% includelib &LibPath&Windows\shell32.lib
% includelib &LibPath&Windows\shlwapi.lib
% includelib &LibPath&Windows\Wininet.lib
% includelib &LibPath&Windows\Crypt32.lib

% include &MacPath&fMath.inc
% include &IncPath&Windows\ShellApi.inc
% include &IncPath&Windows\wininet.inc

.const
bAuto BYTE FALSE

CStr szMyStr, "Here is my string"
CReal4 r4MyFloat1, 12.3456789
CReal8 r8MyFloat2, 89.2398756225

;Note: use MakeObjects to build the following objects to allow to trace them.
.code
;Build the following objects
MakeObjects Primer, Stream
MakeObjects WinPrimer, Window, Button, Hyperlink, Dialog, DialogModal, DialogAbout
MakeObjects WinApp, SdiApp

include DC_Test_Globals.inc
include DC_Test_Main.inc

pApp equ offset $ObjTmpl(DC_Test)

CReal4 MyXMin, -10.0
CReal4 MyXMax, +10.0

CReal4 MyYMin, -5.0
CReal4 MyYMax, +5.0

CReal4 MyX1,  0.0
CReal4 MyY1, +1.0

CReal4 MyX2,  1.0
CReal4 MyY2, +1.5

CReal4 MyX3,  2.0
CReal4 MyY3, +1.2

CReal4 MyX4,  3.0
CReal4 MyY4, +1.1

start proc
  SysInit

  DbgCloseAll
  invoke AppsUseLightTheme
  DbgDec eax, "AppsUseLightTheme"
  DbgFlashWnd FLASHW_CAPTION, 3
  DbgPinWnd TRUE
  xor eax, eax
  DbgStr xax ;offset szMyStr
  mov xax, offset szMyStr
  DbgStr xax
  DbgStr szMyStr

  DbgBkgndTxt $RGB(128,255,255)
  DbgText "aaa", "bbb"
  DbgComError 000000000h, "COM error"
  DbgComError 08000FFFFh, "COM error"
  DbgComError 08007000Eh, "COM error"
  DbgComError 0FFFFFFFFh, "COM error"
  DbgLine
  DbgText "Hello friends"
  DbgText
  DbgWarning "Here is something wrong"
  DbgWarning
  DbgHex eax, "My text"
  DbgFrontTxt "bbb"

  invoke LoadBitmap, hInstance, $OfsCStr("BMP_TEST1")
  DbgBmp xax, "BMP1"
  invoke LoadBitmap, hInstance, $OfsCStr("BMP_TEST2")
  DbgBmp xax, "BMP2"

;  DbgCloseWnd

;  DbgClearCht "MyChart"
  DbgChtOption DBG_CHT_SCALEX_MIN, MyXMin, "MyChart"
  DbgChtOption DBG_CHT_SCALEX_MAX, MyXMax, "MyChart"
  DbgChtOption DBG_CHT_SCALEX_TITLE, "MyTitleX", "MyChart"
  DbgChtOption DBG_CHT_SCALEX_AUTO, bAuto, "MyChart"

  DbgChtOption DBG_CHT_SCALEY_MIN, MyYMin, "MyChart"
  DbgChtOption DBG_CHT_SCALEY_MAX, MyYMax, "MyChart"
  DbgChtOption DBG_CHT_SCALEY_TITLE, "MyTitleY", "MyChart"
  DbgChtOption DBG_CHT_SCALEY_AUTO, bAuto, "MyChart"

  DbgChtSeriesAdd 1, +0.5, +0.5, "MyChart"
  DbgChtSeriesAdd 1, MyX2, MyY2, "MyChart"
  DbgChtSeriesAdd 2, MyX3, MyY3, "MyChart"
  DbgChtSeriesAdd 2, MyX4, MyY4, "MyChart"

  DbgChtSeriesOption DBG_CHT_SERIES_COLOR, 1, $RGB(255,0,0), "MyChart"
  DbgChtSeriesOption DBG_CHT_SERIES_MARKER, 1, 3, "MyChart"
;  DbgCloseCht "MyChart"

  DbgTileHor

  DbgLine2
  DbgTraceObject $ObjTmpl(DC_Test)
  OCall $ObjTmpl(DC_Test)::DC_Test.Init                         ;Initialize the object data
  OCall $ObjTmpl(DC_Test)::DC_Test.ErrorSet, STM_OPEN_ERROR     ;20000014h
  DbgObject $ObjTmpl(DC_Test)::DC_Test                          ;Check the dErrorCode value! 
  DbgIMT $ObjTmpl(DC_Test)::DC_Test 
  DbgVMT $ObjTmpl(DC_Test)::DC_Test 
  OCall $ObjTmpl(DC_Test)::DC_Test.Run                          ;Execute the application
  OCall $ObjTmpl(DC_Test)::DC_Test.Done                         ;Finalize it

  DbgHex pApp, "Here in Code"
;  DbgTraceShow DC_Test,, "Performance data"
  DbgLine
  DbgText "Hip hop..."
  DbgHex hInstance
  lea xax, szMyStr
  DbgHex eax
  DbgHex ax
  DbgHex al
  DbgHex BYTE ptr [xax], "Here in Code"
  DbgStr szMyStr, "This is my string"
  DbgLine2
  lea xcx, szMyStr
  DbgMem xcx, 29, DBG_MEM_STR, "Dump Here"
  DbgMem xcx, 29, DBG_MEM_UI8, "Dump Here"
  DbgMem xcx, 29, DBG_MEM_UI16, "Dump Here"
  DbgMem xcx, 29, DBG_MEM_UI32, "Dump Here"
  DbgMem xcx, 29, DBG_MEM_I8, "Dump Here"
  DbgMem xcx, 29, DBG_MEM_I16, "Dump Here"
  DbgMem xcx, 29, DBG_MEM_I32, "Dump Here"
  DbgMem xcx, 29, DBG_MEM_R8, "Dump Here"
  DbgMem xcx, 29, DBG_MEM_R4, "Dump Here"
  DbgLine
  DbgMem xcx, 29,, "Default is String"
  DbgLine
  fld r4MyFloat1
  fld r8MyFloat2
  DbgFPU "FPU here"
  DbgLine
  mov ecx, -1
  DbgHex ecx
  DbgBin ecx
  DbgDec ecx
  DbgFloat r4MyFloat1, "REAL4"
  DbgFloat r8MyFloat2, "REAL8"
  DbgBin ecx
  DbgApiError
  DbgLine
  DbgGlobalMemUsage "Memory usage here"
  DbgLine
  xor ecx, ecx
  ASSERT ecx, "ecx should not be zero here"
  DbgText "Test ready. Bye..."
  DbgFrontBmp "BMP1"
  DbgBkgndBmp $RGB(128,255,255), "BMP1"
  DbgFlashMenu $RGB(255,0,0), 5
  DbgZoomIn "BMP2"
  DbgFrontWnd
  DbgClearTxt "Performance data"
  DbgClearBmp "BMP1"
  DbgPinWnd FALSE

  SysDone

  invoke ExitProcess, 0
start endp

end
