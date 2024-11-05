; ==================================================================================================
; Title:      DebugCenter.asm
; Authors:    G. Friedrich
; Version     2.3.0
; Purpose:    ObjAsm DebugCenter application.
; Notes:      Version 1.1.0, October 2017
;               - First release. Ported to BNC.
;             Version 2.1.0, October 2019
;               - Added more color and font customization by HSE.
;             Version 2.1.1, October 2021
;               - First click into ChildTxt bug corrected.
;               - Find text bug corrected.
;               - Word break routine added to ChildTxt to improve usability.
;             Version 2.2.0, September 2022
;               - Background color command added.
;               - Some miscellaneous commands added (see Debug.inc for a complete list).
;             Version 2.2.1, September 2023
;               - Background color corrected when a text file is loaded.
;               - ChildText MDI behaviour corrected.
;             Version 2.3.0, November 2023
;               - Communication via HTTP-Server added.
;
;                 The URL registration for Http.sys requires extended rights.
;                 To avoid having to start DebugCenter with admin rights every time, a permanent
;                 registration can be carried out using NETSH. NETSH must be executed from a
;                 command console with admin rights. Enter the following command in the console:
;                 netsh http add urlacl url=http://+:8080/ sddl=D:(A;;GX;;;;S-1-1-0) listen=yes delegate=no
;                 "sddl=D:(A;;GX;;;;S-1-1-0)" is the replacement for the localised EVERYONE.
;                 A registration for the currently logged in user can be done by entering:
;                 netsh http add urlacl url=http://+:8080/ user=%USERDOMAIN%\%USERNAME%
;                 The URL must be exacly the same as the used in the code!
;
;             Version 2.4.0, October 2024
;               - Information from child windows added to the statusbar.
;               - Plotting capabilities added.
;                 Original idea from HSE - https://masm32.com/board/index.php?topic=12321.0
;               - XMenu flashing update. 
; ==================================================================================================

;Wishlist:
;- Upgrade resource definitions like OA_Tools


WIN32_LEAN_AND_MEAN         equ 1                       ;Necessary to exclude WinSock.inc
INTERNET_PROTOCOL_VERSION   equ 4

% include @Environ(OBJASM_PATH)\Code\Macros\Model.inc   ;Include & initialize standard modules
SysSetup OOP, WIN64, WIDE_STRING;, DEBUG(CON, INFO)     ;Load OOP files and OS related objects

% include &MacPath&fMath.inc
% include &MacPath&DlgTmpl.inc                          ;Load dialog tempate support
% include &MacPath&ConstDiv.inc
% include &COMPath&COM.inc

% include &IncPath&Windows\ole2.inc
% include &IncPath&Windows\shlobj.inc
% include &IncPath&Windows\richedit.inc
% include &IncPath&Windows\ShellApi.inc
% include &IncPath&Windows\CommCtrl.inc
% include &IncPath&Windows\CommDlg.inc
% include &IncPath&Windows\IImgCtx.inc
% include &IncPath&Windows\UxTheme.inc
% include &IncPath&Windows\vsstyle.inc
% include &IncPath&Windows\WinSock2.inc
% include &IncPath&Windows\http.inc


% includelib &LibPath&Windows\Kernel32.lib
% includelib &LibPath&Windows\Shell32.lib
% includelib &LibPath&Windows\Ole32.lib
% includelib &LibPath&Windows\Comctl32.lib
% includelib &LibPath&Windows\ComDlg32.lib
% includelib &LibPath&Windows\shlwapi.lib
% includelib &LibPath&Windows\Msimg32.lib
% includelib &LibPath&Windows\UxTheme.lib
% includelib &LibPath&Windows\httpapi.lib
% includelib &LibPath&Windows\wininet.lib
% includelib &LibPath&Windows\OleAut32.lib

INCLUDE_CHART_SETUP_DIALOG = TRUE

if DEBUGGING eq FALSE
  % include &MacPath&DebugShare.inc
endif

MakeObjects Primer, Stream, DiskStream                  ;Load or build the following objects
MakeObjects Collection, DataCollection, SortedCollection, SortedDataCollection, XWCollection
MakeObjects WinPrimer, Window, WinApp, MdiApp
MakeObjects Button, Hyperlink, IconButton, ColorButton
MakeObjects RegKey, IDL, IniFile
MakeObjects Dialog, DialogModal, DialogModalIndirect
MakeObjects DialogModeless, DialogModelessIndirect
MakeObjects SimpleImageList, MaskedImageList
MakeObjects MsgInterceptor, XMenu, Magnetism
MakeObjects WinControl, Toolbar, Rebar, Statusbar, TabCtrl, Tooltip, TextView, Image
MakeObjects Array, Chart, ChartXY


include DebugCenter_DlgFindText.inc
include DebugCenter_Globals.inc                         ;Include application globals
include DebugCenter_HttpServer.inc
include DebugCenter_Main.inc                            ;Include DebugCenter main object

start proc uses xbx                                     ;Program entry point
  mov xbx, $invoke(LoadLibrary, $OfsCStr("RichEd20.dll"))
  SysInit                                               ;Runtime initialization of OOP model

  OCall $ObjTmpl(Application)::Application.Init         ;Initialize the object data
  OCall $ObjTmpl(Application)::Application.Run          ;Execute the application
  OCall $ObjTmpl(Application)::Application.Done         ;Finalize it

  SysDone                                               ;Runtime finalization of the OOP model
  invoke FreeLibrary, xbx                               ;Unload RichEdit library

  invoke ExitProcess, 0                                 ;Exit program returning 0 to the OS
start endp

end
