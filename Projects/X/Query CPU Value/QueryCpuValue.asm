; ==================================================================================================
; Title:      QueryCpuValue.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm QueryCpuValue Test Application.
; Notes:      Version C.1.0, May 2026
;               - Initial release.
; ==================================================================================================



; Check "Initial APIC ID"




% include @Environ(OBJASM_PATH)\Code\Macros\Model.inc
SysSetup OOP, CON32, ANSI_STRING;, DEBUG(WND)

% include &IncPath&Windows\tlhelp32.inc

MakeObjects Primer, Stream, ConsoleApp

include QueryCpuValue_Shared.inc

% include &IncPath&ObjAsm\QueryCpu.inc
% include &ObjMemPath&Common\QCF-Name_PTX.inc
% include &ObjMemPath&Common\QCV-Name_PTX.inc

% include &ObjMemPath&Common\QCV-Table_PX.inc

Object Application, ApplicationID, ConsoleApp           ; Single Document Interface App.
  RedefineMethod    Run                                 ; Run method redefinition
ObjectEnd                                               ; Ends object definition

.code
.code
align ALIGN_CODE
QueryCpuValue2 proc uses xbx xsi dValueIndex:DWORD, pReturnedValue:POINTER
  local dMaxLeaf:DWORD
  local dVendorEBX:DWORD, dVendorECX:DWORD, dVendorEDX:DWORD
  local pEntry:POINTER                  ; Cached table entry pointer
  local dSavedEBX:DWORD                 ; ebx save slot across CPUID calls
  local dSavedLeaf:DWORD                ; leaf save slot
  local dSavedSubleaf:DWORD             ; subleaf save slot
  local dCpuEAX:DWORD                   ; CPUID output capture: eax
  local dCpuEBX:DWORD                   ; CPUID output capture: ebx
  local dCpuECX:DWORD                   ; CPUID output capture: ecx
  local dCpuEDX:DWORD                   ; CPUID output capture: edx

  ; Verify CPUID is available (only in 32-bit mode)
if TARGET_BITNESS eq 32
  invoke QueryCpuidSupported
  test eax, eax
  jz @Failure
endif

  ; Bounds check
  mov eax, dValueIndex
  cmp eax, QCV_COUNT
  jae @Failure

  ; Load table entry pointer (base + index * sizeof(QCV_ENTRY))
  lea xsi, QCV_TABLE
  shl eax, 3                            ; * sizeof(QCV_ENTRY) = 8
  add xsi, xax                          ; xsi -> QCV_ENTRY for this index
  mov pEntry, xsi                       ; cache pointer in local

  ; CPUID(0) - get max basic leaf and vendor string
  xor eax, eax
  xor ecx, ecx
  mov dSavedEBX, ebx
  cpuid
  mov dMaxLeaf,   eax                   ; Capture all CPUID outputs before restoring EBX
  mov dVendorEBX, ebx
  mov dVendorECX, ecx
  mov dVendorEDX, edx
  mov ebx, dSavedEBX                    ; Restore caller EBX last

  ; Vendor filter  (QCF_ENTRY.bVendor)
  ;
  ;   VF_ANY   (0) => accept any vendor, skip all checks
  ;   VF_INTEL (1) => all three vendor DWORDs must match "GenuineIntel"
  ;   VF_AMD   (2) => all three vendor DWORDs must match "AuthenticAMD"
  ;   other        => unknown filter value, treat as failure
  ;
  ;   Full 3-DWORD comparison eliminates false positives from
  ;   hypothetical CPUs sharing only a partial vendor prefix.

  mov xsi, pEntry
  movzx ecx, [xsi].QCV_ENTRY.bVendor
  .if ecx != VF_ANY
    .if ecx == VF_INTEL
      .if dVendorEBX != "uneG" || dVendorEDX != "Ieni" || dVendorECX != "letn"   ;"GenuineIntel"
        jmp @Failure
      .endif
    .elseif ecx == VF_AMD
      .if dVendorEBX != "htuA" || dVendorEDX != "itne" || dVendorECX != "DMAc"   ;"AuthenticAMD"
        jmp @Failure
      .endif
    .else
      jmp @Failure                      ; Unknown vendor code
    .endif
  .endif

  ; Build actual leaf address
  movzx eax, [xsi].QCV_ENTRY.bLeaf
  movzx ecx, [xsi].QCV_ENTRY.bFlags
  test ecx, QCV_FL_EX
  jz @BasicLeaf
  add eax, 80000000h                    ; Extended leaf

  ; Validate extended leaf
  mov dSavedLeaf, eax                   ; Save requested extended leaf
  mov eax, 80000000h
  xor ecx, ecx
  mov dSavedEBX, ebx
  cpuid
  mov ecx, eax                          ; Max extended leaf returned in EAX
  mov ebx, dSavedEBX
  mov eax, dSavedLeaf                   ; Restore requested leaf
  cmp eax, ecx
  ja @Failure
  jmp     @LeafOK

@BasicLeaf:
  ; Validate basic leaf
  cmp eax, dMaxLeaf
  ja @Failure

  ; Special case: leaf 7, subleaf > 0 => validate against CPUID(7,0).EAX max subleaf
  .if eax == 7
    mov xsi, pEntry
    movzx ecx, [xsi].QCV_ENTRY.bSubleaf
    .if ecx > 0
      mov dSavedLeaf,    eax            ; Save leaf (7)
      mov dSavedSubleaf, ecx            ; Save requested subleaf
      xor ecx, ecx                      
      mov eax, 7                        
      mov dSavedEBX, ebx                
      cpuid                             
      mov ecx, eax                      ; Max subleaf for leaf 7 in EAX
      mov ebx, dSavedEBX                
      mov eax, dSavedSubleaf            ; Requested subleaf
      cmp eax, ecx                      
      ja @Failure                       
      mov eax, dSavedLeaf               ; Restore leaf (7) for Step 8
    .endif
  .endif

@LeafOK:
  ; Execute CPUID(leaf, subleaf)
  ; Capture all four outputs into locals before any register is reused,
  ; so bReg selection does not overwrite the ECX result.
  mov xsi, pEntry
  movzx ecx, [xsi].QCV_ENTRY.bSubleaf
  mov dSavedEBX, ebx
  cpuid
  mov dCpuEAX, eax
  mov dCpuEBX, ebx
  mov dCpuECX, ecx
  mov dCpuEDX, edx
  mov ebx, dSavedEBX                    ; Restore caller ebx

  ; Select result register by bReg
  movzx ecx, [xsi].QCV_ENTRY.bReg
  .if ecx == RG_EAX
    mov edx, dCpuEAX
  .elseif ecx == RG_EBX
    mov edx, dCpuEBX
  .elseif ecx == RG_ECX
    mov edx, dCpuECX
  .else                                 ; RG_EDX
    mov edx, dCpuEDX
  .endif

  ; Extract field (right-shift and mask)
  movzx ecx, [xsi].QCV_ENTRY.bBitPos
  shr edx, cl                           ; right-shift
  movzx ecx, [xsi].QCV_ENTRY.bBitWidth
  .if ecx < 32
    mov eax, 1
    shl eax, cl
    dec eax                             ; Mask = (1 << width) - 1
    and edx, eax
  .endif
  ; edx = extracted value

  ; Store result and return 1
  mov xax, pReturnedValue
  mov DWORD ptr [xax], edx              ; -> dVals[0]
  mov eax, 1
  ret

@Failure:
  xor eax, eax
  ret
QueryCpuValue2 endp

; --------------------------------------------------------------------------------------------------
; Method:     Application.Run
; Purpose:    Output current CPU features.
; Arguments:  None.
; Return:     Nothing.

Method Application.Run, uses xbx xdi xsi
  local BrandString[sizeof(CHR)*MAX_CPU_BRANDSTRING_LENGTH + @WordSize]:CHR
  local VendorString[sizeof(CHR)*MAX_CPU_VENDORSTRING_LENGTH + @WordSize]:CHR
  local cString[1024]:CHR
  local wIndex:WORD, dConsoleMode:DWORD, CpuValue:CPU_VALUE

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


  lea xbx, offset QCV_NAME
  mov wIndex, 0
  .while wIndex < QCV_COUNT

    ;Get the feature presence and print the result
    int 3
    invoke QueryCpuValue, wIndex, addr CpuValue
    DbgDec eax
    DbgDec DWORD ptr CpuValue
    .if eax != 0
      OCall xsi.SetColor, FOREGROUND_INTENSE_WHITE
      lea xdi, cString
      WriteF xdi, "CpuValue(¦UW) = ¦UD ", wIndex, DWORD ptr CpuValue
      OCall xsi.Print, addr cString
    .else
      OCall xsi.SetColor, FOREGROUND_INTENSE_WHITE
      lea xdi, cString
      WriteF xdi, "CpuValue(¦UW) =", wIndex
      OCall xsi.Print, addr cString
      OCall xsi.SetColor, FOREGROUND_INTENSE_RED
      OCall xsi.Print, $OfsCStr(" not available ")
    .endif
    ;Print the feature description
    OCall xsi.SetColor, FOREGROUND_INTENSE_CYAN
    lea xdi, cString
    WriteF xdi, "\=¦ST\=", PSTRING ptr [xbx]
    OCall xsi.PrintLn, addr cString

    ;Go to the next feature
    add xbx, sizeof(POINTER)
    inc wIndex
  .endw

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


start proc
  SysInit
  DbgClearAll
  ResGuard_Version
  ResGuard_Start

  OCall $ObjTmpl(Application)::Application.Init, NULL   ; Initialize application
  OCall $ObjTmpl(Application)::Application.Run          ; Execute application
  OCall $ObjTmpl(Application)::Application.Done         ; Finalize application

  ResGuard_Stop
  ResGuard_Show
  SysDone

  invoke ExitProcess, 0
start endp

end
