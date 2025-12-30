; ==================================================================================================
; Title:      SVC_Server_Globals.inc
; Author:     G. Friedrich
; Notes:      See SVC_Server.asm.
; ==================================================================================================


include SVC_Server_Shared.inc

;Security Descriptor Definition Language
; BA: Built-in Administrators => All access (GA)
; BU: Built-in Users => Read/Write (GRGW)
CStr cSDDL,         "D:(A;;GA;;;BA)(A;;GRGW;;;BU)"

CStr cServiceName1, "ObjAsmService1"
CStr cServiceDisp1, "ObjAsmService - 1"
CStr cServiceDesc1, "This is a Test Service - 1"
CStr cPipeName1,    "\\.\pipe\ObjAsmService1"

CStr cServiceName2, "ObjAsmService2"
CStr cServiceDisp2, "ObjAsmService - 2"
CStr cServiceDesc2, "This is a Test Service - 2"


CStr cInstallCmd,   "install"
CStr cUninstallCmd, "uninstall"
CStr cLogFileName,  "C:\\Windows\\System32\\ObjAsmService.log"


.const
;Table that contains information of all services hosted by this executable
ServiceHostTable label SERVICE_TABLE_ENTRY              ;1 entry for each service
  SERVICE_TABLE_ENTRY <offset cServiceName1, offset ServiceMainThunk>
  SERVICE_TABLE_ENTRY <offset cServiceName2, offset ServiceMainThunk>
  SERVICE_TABLE_ENTRY <NULL, NULL>

CMD_PING          equ 1
CMD_STOP          equ 2
CMD_QUERYSTATE    equ 3
CMD_NOTIFICATION  equ 4

;The header file sddl.h has not been translated yet!
@DefProto DllImport, ConvertStringSecurityDescriptorToSecurityDescriptorA, WIN_STD_CALL_CONV,, <:POINTER, :DWORD, :POINTER, :POINTER>, 16
@DefProto DllImport, ConvertStringSecurityDescriptorToSecurityDescriptorW, WIN_STD_CALL_CONV,, <:POINTER, :DWORD, :POINTER, :POINTER>, 16
ifdef UNICODE
  ConvertStringSecurityDescriptorToSecurityDescriptor equ <ConvertStringSecurityDescriptorToSecurityDescriptorW>
else
  ConvertStringSecurityDescriptorToSecurityDescriptor equ <ConvertStringSecurityDescriptorToSecurityDescriptorA>
endif

SDDL_REVISION_1 equ 1

@DefProto DllImport, WTSSendMessageA, WIN_STD_CALL_CONV,, <:HANDLE, :DWORD, :POINTER, :DWORD, :POINTER, :DWORD, :DWORD, :DWORD, :POINTER, :DWORD>, 40
@DefProto DllImport, WTSSendMessageW, WIN_STD_CALL_CONV,, <:HANDLE, :DWORD, :POINTER, :DWORD, :POINTER, :DWORD, :DWORD, :DWORD, :POINTER, :DWORD>, 40
ifdef UNICODE
  WTSSendMessage equ <WTSSendMessageW>
else
  WTSSendMessage equ <WTSSendMessageA>
endif
