; ==================================================================================================
; Title:      SVC_Template.asm
; Author:     G. Friedrich
; Version:    C.2.0
; Purpose:    ObjAsm application.
; Notes:      Version C.2.0
;               - First release.
;               - Implements a service host framework.
;               - Services can be managed via MMC (services.msc) with administrative privileges.
;               - In debug mode, start DebugCenter manually before the services launch.
;                 If not started, services may run noticeably slower.
;               - Instances of Service1 and Service2 are their own templates.
;               - To install the service (as admin):     SVC_Template install
;               - To uninstall the service (as admin):   SVC_Template uninstall
; ==================================================================================================


WIN32_LEAN_AND_MEAN         equ 1                       ;Exclude rarely-used Windows headers
INTERNET_PROTOCOL_VERSION   equ 4                       ;Force IPv4 for WinInet

% include @Environ(OBJASM_PATH)\Code\Macros\Model.inc   ;Load ObjAsm model + macros
;SysSetup OOP, WIN64, WIDE_STRING;, DEBUG(WND)           ;Alternative debug configuration
SysSetup OOP, WIN64, WIDE_STRING, DEBUG(NET, INFO, TRACE) ;Enable network / info / trace debugging
DBG_IP_ADDR textequ <"localhost">                       ;Debug target address
DBG_IP_PORT textequ <8080>                              ;Debug target port

% includelib &LibPath&Windows\shell32.lib               ;Shell API library
% includelib &LibPath&Windows\Wininet.lib               ;WinInet networking

% include &MacPath&fMath.inc                            ;Floating-point math macros
% include &IncPath&Windows\ShellApi.inc                 ;Shell API declarations
% include &IncPath&Windows\wininet.inc                  ;WinInet declarations

;Load or build the following objects:
MakeObjects Primer, Stream, Service                     ;Include required ObjAsm objects

include SVC_Template_Globals.inc                        ;Global constants / data
include SVC_Template_Main.inc                           ;Service object implementations


;Service Host

;SCM service entry:
;  SCM already parsed arguments. Do NOT call GetCommandLineW!
;  This thunk is only called when SCM starts the service.
ServiceMainThunk proc uses xbx dArgC:DWORD, pArgV:POINTER
  mov xax, pArgV                                        ;Get argv array
  mov xbx, PSTRINGW ptr [xax]                           ;xbx -> argv[0]
  invoke StrCompW, xbx, $ObjTmpl(Service1).pName        ;Compare argv[0] with Service1 name
  .if eax == 0
    OCall $ObjTmpl(Service1)::Service1.Init, dArgC, pArgV   ;Initialize Service1 instance
  .else
    invoke StrCompW, xbx, $ObjTmpl(Service2).pName      ;Compare argv[0] with Service2 name
    .if eax == 0
      OCall $ObjTmpl(Service2)::Service2.Init, dArgC, pArgV ;Initialize Service2 instance
    .endif
  .endif
  ret                                                   ;Return to SCM
ServiceMainThunk endp                                   ;End service entry thunk


;Process entry point:
start proc uses xbx
  local dArgCount:DWORD                                 ;Argument count

  SysInit                                               ;Initialize ObjAsm runtime
  DbgClearAll                                           ;Clear debug output
  DbgText "Service called"                              ;Debug trace
  invoke OpenServiceLogFile, offset cLogFileName        ;Open Log-File for writing

  invoke GetCommandLineW                                ;Get full command line
  invoke CommandLineToArgvW, xax, addr dArgCount        ;Parse arguments into argv[]
  mov xbx, xax
  .if dArgCount < 2                                     ;No arguments => SCM start
    invoke StartServiceCtrlDispatcher, offset ServiceHostTable  ;Connect process to SCM
  .else
    add xax, sizeof(PSTRINGW)                           ;Skip executable name
    mov xbx, PSTRINGW ptr [xax]                         ;xbx -> first argument
    invoke StrCompW, xbx, offset cInstallCmd            ;Check for "install" command
    .if eax == 0
      OCall $ObjTmpl(Service1)::Service1.Install        ;Install Service1
      .if eax == 0
        OCall $ObjTmpl(Service2)::Service2.Install      ;Install Service2
      .endif
      mov ebx, eax                                      ;Propagate result
    .else
      invoke StrCompW, xbx, offset cUninstallCmd        ;Check for "uninstall" command
      .if eax == 0
        OCall $ObjTmpl(Service1)::Service1.Uninstall    ;Remove Service1
        .if eax == 0
          OCall $ObjTmpl(Service2)::Service2.Uninstall  ;Remove Service2
        .endif
        mov ebx, eax                                    ;Propagate result
      .else
        mov ebx, 2                                      ;Invalid argument
      .endif
    .endif
  .endif

  invoke CloseServiceLogFile                            ;Close Log-File
  SysDone                                               ;Finalize ObjAsm runtime
  invoke ExitProcess, ebx                               ;Exit process with return code
start endp                                              ;End entry point

end                                                     ;End module
