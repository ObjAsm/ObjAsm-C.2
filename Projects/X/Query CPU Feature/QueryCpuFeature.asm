; ==================================================================================================
; Title:      QueryCpuFeature.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm QueryCpuFeature Test Application.
; Notes:      Version C.1.0, May 2026
;               - Initial release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\Code\Macros\Model.inc
SysSetup OOP, CON32, ANSI_STRING;, DEBUG(WND)

% include &IncPath&Windows\tlhelp32.inc

MakeObjects Primer, Stream, ConsoleApp

include QueryCpuFeature_Shared.inc

% include &IncPath&ObjAsm\QueryCpu.inc
% include &ObjMemPath&Common\QCF-Name_PTX.inc

Object Application, ApplicationID, ConsoleApp           ; Single Document Interface App.
  RedefineMethod    Run                                 ; Run method redefinition
ObjectEnd                                               ; Ends object definition

.code
; --------------------------------------------------------------------------------------------------
; Method:     Application.Run
; Purpose:    Output current CPU features.
; Arguments:  None.
; Return:     Nothing.

Method Application.Run, uses xbx xdi xsi
  local BrandString[sizeof(CHR)*MAX_CPU_BRANDSTRING_LENGTH + @WordSize]:CHR
  local VendorString[sizeof(CHR)*MAX_CPU_VENDORSTRING_LENGTH + @WordSize]:CHR
  local cString[1024]:CHR
  local wIndex:WORD, dConsoleMode:DWORD, dPresent:DWORD
  local dCharsWritten:DWORD, Info:CONSOLE_SCREEN_BUFFER_INFO, BufferSize:COORD

  SetObject xsi
  OCall xsi.SetCaption, @CatStr(<$OfsCStr(!">, %APP_TITLE, <!")>)
;  OCall xsi.ClearScreen

  ; Enable QUICK_EDIT_MODE to make copying easier
  invoke GetConsoleMode, [xsi].hInput, addr dConsoleMode
  or dConsoleMode, ENABLE_QUICK_EDIT_MODE or ENABLE_EXTENDED_FLAGS
  invoke SetConsoleMode, [xsi].hInput, dConsoleMode

  invoke GetConsoleScreenBufferInfo, [xsi].hConsole, addr Info
  m2m BufferSize.X, Info.dwSize.X, eax                  ; Keep current width
  mov BufferSize.Y, 9999                                ; Enlarge scrollback for large output
  invoke SetConsoleScreenBufferSize, [xsi].hConsole, BufferSize

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

  lea xbx, offset QCF_NAME
  mov wIndex, 0
  .while wIndex < QCF_COUNT

    ;Get the feature presence and print the result
    invoke QueryCpuFeature, wIndex
;    .if eax == 1
      mov dPresent, eax
      OCall xsi.SetColor, FOREGROUND_INTENSE_WHITE
      lea xdi, cString
      WriteF xdi, "CpuFeature(¦UW) = ¦UD ", wIndex, dPresent
      OCall xsi.Print, addr cString

      ;Print the feature description
      OCall xsi.SetColor, FOREGROUND_INTENSE_CYAN
      lea xdi, cString
      WriteF xdi, "\`¦ST\`", PSTRING ptr [xbx]
      OCall xsi.PrintLn, addr cString
;    .endif

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

  OCall $ObjTmpl(Application)::Application.Init, NULL   ; Initialize application
  OCall $ObjTmpl(Application)::Application.Run          ; Execute application
  OCall $ObjTmpl(Application)::Application.Done         ; Finalize application

  SysDone

  invoke ExitProcess, 0
start endp

end
