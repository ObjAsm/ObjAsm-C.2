; ==================================================================================================
; Title:      QueryCpuStruct.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm QueryCpuStruct Test Application.
; Notes:      Version C.1.0, May 2026
;               - Initial release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\Code\Macros\Model.inc
SysSetup OOP, CON32, ANSI_STRING;, DEBUG(WND)

% include &IncPath&Windows\tlhelp32.inc

MakeObjects Primer, Stream, ConsoleApp

include QueryCpuStruct_Shared.inc

% include &IncPath&ObjAsm\QueryCpu.inc
% include &ObjMemPath&Common\QCF-Name_PTX.inc
% include &ObjMemPath&Common\QCS-Name_PTX.inc

CStr NotAvailable, "Not available" 

Object Application, ApplicationID, ConsoleApp           ; Single Document Interface App.
  RedefineMethod    Run                                 ; Run method redefinition
ObjectEnd                                               ; Ends object definition

; --------------------------------------------------------------------------------------------------
; Method:     Application.Run
; Purpose:    Output current CPU features.
; Arguments:  None.
; Return:     Nothing.

PrintStructMember macro FieldID:req
  OCall xsi.SetColor, FOREGROUND_WHITE
  OCall xsi.Print, $OfsCStr("&FieldID = ")
  OCall xsi.SetColor, FOREGROUND_INTENSE_GREEN
  invoke dword2dec, addr cString, &FieldID
  OCall xsi.PrintLn, addr cString
endm

Method Application.Run, uses xbx xdi xsi
  local BrandString[sizeof(CHR)*MAX_CPU_BRANDSTRING_LENGTH + @WordSize]:CHR
  local VendorString[sizeof(CHR)*MAX_CPU_VENDORSTRING_LENGTH + @WordSize]:CHR
  local cString[1024]:CHR
  local wIndex:WORD, dConsoleMode:DWORD
  local CpuVersion:QCSTRUCT_CPU_VERSION
  local CpuInfo:QCSTRUCT_CPU_INFO
  local CpuAmdTopology:QCSTRUCT_AMD_TOPOLOGY
  local CpuXSaveInfo:QCSTRUCT_XSAVE_INFO
  local CpuAddrSizes:QCSTRUCT_ADDR_SIZES
  local CpuIntelFreq:QCSTRUCT_INTEL_FREQ
  local CpuIntelTSC:QCSTRUCT_INTEL_TSC

  SetObject xsi
  OCall xsi.SetCaption, @CatStr(<$OfsCStr(!">, %APP_TITLE, <!")>)
;  OCall xsi.ClearScreen

  ; Enable QUICK_EDIT_MODE to make copying easier
  invoke GetConsoleMode, [xsi].hInput, addr dConsoleMode
  or dConsoleMode, ENABLE_QUICK_EDIT_MODE or ENABLE_EXTENDED_FLAGS
  invoke SetConsoleMode, [xsi].hInput, dConsoleMode

if TARGET_BITNESS eq 32
  invoke QueryCpuidSupported
  .if eax == FALSE
    OCall xsi.SetColor, FOREGROUND_INTENSE_RED
    OCall xsi.PrintLn, $OfsCStr("This processor does not support the CPUID instruction")
    jmp @@Exit
  .endif
endif

  invoke QueryCpuVendorStr, addr VendorString
  OCall xsi.SetColor, FOREGROUND_INTENSE_WHITE
  OCall xsi.Print, $OfsCStr("CPU Vendor String: ")
  OCall xsi.SetColor, FOREGROUND_INTENSE_GREEN
  OCall xsi.PrintLn, addr VendorString

  invoke QueryCpuBrandStr, addr BrandString
  .if eax != FALSE
    OCall xsi.SetColor, FOREGROUND_INTENSE_WHITE
    OCall xsi.Print, $OfsCStr("CPU Brand String: ")
    OCall xsi.SetColor, FOREGROUND_INTENSE_GREEN
    OCall xsi.PrintLn, addr BrandString
  .endif

  invoke QueryCpuHypervisorVendorStr, addr VendorString
  .if eax != FALSE
    OCall xsi.SetColor, FOREGROUND_INTENSE_WHITE
    OCall xsi.Print, $OfsCStr("CPU Hypervisor Vendor String: ")
    OCall xsi.SetColor, FOREGROUND_INTENSE_GREEN
    OCall xsi.PrintLn, addr VendorString
  .endif

  OCall xsi.PrintLn, NULL

  lea xbx, QCS_NAME
  
  OCall xsi.SetColor, FOREGROUND_INTENSE_CYAN
  OCall xsi.PrintLn, POINTER ptr [xbx]
  add xbx, sizeof(POINTER)
  invoke QueryCpuStruct, QCS_CPU_VERSION, addr CpuVersion
  .if eax != 0
    PrintStructMember <CpuVersion.dStepping>
    PrintStructMember <CpuVersion.dModel>
    PrintStructMember <CpuVersion.dFamily>
    PrintStructMember <CpuVersion.dExtModel>
    PrintStructMember <CpuVersion.dExtFamily>
  .else
    OCall xsi.SetColor, FOREGROUND_INTENSE_RED
    OCall xsi.PrintLn, addr NotAvailable
  .endif
  OCall xsi.PrintLn, NULL

  OCall xsi.SetColor, FOREGROUND_INTENSE_CYAN
  OCall xsi.PrintLn, POINTER ptr [xbx]
  add xbx, sizeof(POINTER)
  invoke QueryCpuStruct, QCS_CPU_INFO, addr CpuInfo
  .if eax != 0
    PrintStructMember <CpuInfo.dBrandIdx>
    PrintStructMember <CpuInfo.dCLFlushSize>
    PrintStructMember <CpuInfo.dLogicalCount>
    PrintStructMember <CpuInfo.dApicID>
  .else
    OCall xsi.SetColor, FOREGROUND_INTENSE_RED
    OCall xsi.PrintLn, addr NotAvailable
  .endif
  OCall xsi.PrintLn, NULL

  OCall xsi.SetColor, FOREGROUND_INTENSE_CYAN
  OCall xsi.PrintLn, POINTER ptr [xbx]
  add xbx, sizeof(POINTER)
  invoke QueryCpuStruct, QCS_AMD_VERSION, addr CpuVersion
  .if eax != 0
    PrintStructMember <CpuVersion.dStepping>
    PrintStructMember <CpuVersion.dModel>
    PrintStructMember <CpuVersion.dFamily>
    PrintStructMember <CpuVersion.dExtModel>
    PrintStructMember <CpuVersion.dExtFamily>
  .else
    OCall xsi.SetColor, FOREGROUND_INTENSE_RED
    OCall xsi.PrintLn, addr NotAvailable
  .endif
  OCall xsi.PrintLn, NULL
  
  OCall xsi.SetColor, FOREGROUND_INTENSE_CYAN
  OCall xsi.PrintLn, POINTER ptr [xbx]
  add xbx, sizeof(POINTER)
  invoke QueryCpuStruct, QCS_AMD_TOPOLOGY, addr CpuAmdTopology
  .if eax != 0
    PrintStructMember <CpuAmdTopology.dExtApicID>
    PrintStructMember <CpuAmdTopology.dCompUnitID>
    PrintStructMember <CpuAmdTopology.dThreadsPerCU>
    PrintStructMember <CpuAmdTopology.dNodeID>
    PrintStructMember <CpuAmdTopology.dNodesPerPkg>
  .else
    OCall xsi.SetColor, FOREGROUND_INTENSE_RED
    OCall xsi.PrintLn, addr NotAvailable
  .endif
  OCall xsi.PrintLn, NULL
  
  OCall xsi.SetColor, FOREGROUND_INTENSE_CYAN
  OCall xsi.PrintLn, POINTER ptr [xbx]
  add xbx, sizeof(POINTER)
  invoke QueryCpuStruct, QCS_XSAVE_INFO, addr CpuXSaveInfo
  .if eax != 0
    PrintStructMember <CpuXSaveInfo.dXCR0Lower>
    PrintStructMember <CpuXSaveInfo.dXCR0Upper>
    PrintStructMember <CpuXSaveInfo.dSizeOS>
    PrintStructMember <CpuXSaveInfo.dSizeAll>
  .else
    OCall xsi.SetColor, FOREGROUND_INTENSE_RED
    OCall xsi.PrintLn, addr NotAvailable
  .endif
  OCall xsi.PrintLn, NULL
  
  OCall xsi.SetColor, FOREGROUND_INTENSE_CYAN
  OCall xsi.PrintLn, POINTER ptr [xbx]
  add xbx, sizeof(POINTER)
  invoke QueryCpuStruct, QCS_ADDR_SIZES, addr CpuAddrSizes
  .if eax != 0
    PrintStructMember <CpuAddrSizes.dPhysAddrBits>
    PrintStructMember <CpuAddrSizes.dLinAddrBits>
  .else
    OCall xsi.SetColor, FOREGROUND_INTENSE_RED
    OCall xsi.PrintLn, addr NotAvailable
  .endif
  OCall xsi.PrintLn, NULL
  
  OCall xsi.SetColor, FOREGROUND_INTENSE_CYAN
  OCall xsi.PrintLn, POINTER ptr [xbx]
  add xbx, sizeof(POINTER)
  invoke QueryCpuStruct, QCS_INTEL_FREQ, addr CpuIntelFreq
  .if eax != 0
    PrintStructMember <CpuIntelFreq.dBaseFreqMHz>
    PrintStructMember <CpuIntelFreq.dMaxFreqMHz>
    PrintStructMember <CpuIntelFreq.dBusFreqMHz>
  .else
    OCall xsi.SetColor, FOREGROUND_INTENSE_RED
    OCall xsi.PrintLn, addr NotAvailable
  .endif
  OCall xsi.PrintLn, NULL

  OCall xsi.SetColor, FOREGROUND_INTENSE_CYAN
  OCall xsi.PrintLn, POINTER ptr [xbx]
  add xbx, sizeof(POINTER)
  invoke QueryCpuStruct, QCS_INTEL_TSC, addr CpuIntelTSC
  .if eax != 0
    PrintStructMember <CpuIntelTSC.dDenominator>
    PrintStructMember <CpuIntelTSC.dNumerator>
    PrintStructMember <CpuIntelTSC.dCrystalHz>
  .else
    OCall xsi.SetColor, FOREGROUND_INTENSE_RED
    OCall xsi.PrintLn, addr NotAvailable
  .endif

@@Exit:
  OCall xsi.PrintLn, NULL
  OCall xsi.SetColor, FOREGROUND_WHITE
  mov eax, [xsi].dFlags
  and eax, (CAF_OWNCONSOLE or CAF_INTERACTIVE)
  .if eax == (CAF_OWNCONSOLE or CAF_INTERACTIVE)
    OCall xsi.WriteLn, $OfsCStr("Press 'X' to exit...")
    .repeat
      OCall xsi.GetInputCharUC
      cmp eax, 'X'
    .until ZERO?
  .endif
MethodEnd


.code
start proc
  SysInit

  OCall $ObjTmpl(Application)::Application.Init, NULL   ; Initialize application
  OCall $ObjTmpl(Application)::Application.Run          ; Execute application
  OCall $ObjTmpl(Application)::Application.Done         ; Finalize application

  SysDone

  invoke ExitProcess, 0
start endp

end
