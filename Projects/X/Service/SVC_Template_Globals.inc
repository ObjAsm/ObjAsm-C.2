; ==================================================================================================
; Title:      SVC_Template_Globals.inc
; Author:     G. Friedrich
; Notes:      See SVC_Template.asm.
; ==================================================================================================


include SVC_Template_Shared.inc

.const
CStr cServiceName1, "ObjAsmService1"
CStr cServiceDisp1, "ObjAsmService - 1"
CStr cServiceDesc1, "This is a Test Service - 1"

CStr cServiceName2, "ObjAsmService2"
CStr cServiceDisp2, "ObjAsmService - 2"
CStr cServiceDesc2, "This is a Test Service - 2"

CStr cInstallCmd,   "install"
CStr cUninstallCmd, "uninstall"
CStr cLogFileName,  "C:\\Windows\\System32\\ObjAsmService.log"


;Table that contains information of all services hosted by this executable
ServiceHostTable label SERVICE_TABLE_ENTRY              ;1 entry for each service
  SERVICE_TABLE_ENTRY <offset cServiceName1, offset ServiceMainThunk>
  SERVICE_TABLE_ENTRY <offset cServiceName2, offset ServiceMainThunk>
  SERVICE_TABLE_ENTRY <NULL, NULL>
