;==================================================================================================
; Title:        DarylUEFI.asm
; Author:       Héctor S. Enrique
; Version:      1.0.0
; Purpose:      ObjAsm version of "Multiprocessing with UEFI, Daryl McDaniel"
;               (Software and Solutions Group, Intel), UEFI Plugfest, June 22 - 24, 2010,
; Version:      1.0.0, December 2022
;               - Initial release.
; Links:        https://uefi.org/sites/default/files/resources/Plugfest_Multiprocessing-with_UEFI-McDaniel.pdf
; ==================================================================================================


% include @Environ(OBJASM_PATH)\Code\Macros\Model.inc   ;Include & initialize standard modules
SysSetup OOP, WIDE_STRING, UEFI64                       ;Load OOP files and basic OS support

NUMLOOPS equ 30

TCB struct                                              ;Task Control Block
  xMaxCount   XWORD     NUMLOOPS
  xReady      XWORD     0
  xResult     XWORD     0
  xProcNum    XWORD     0
TCB ends
PTCB typedef ptr TCB

CStr crlf$, 13, 10

.data
tcb         TCB         {}
pIServiceMP POINTER     NULL                            ;Multiprocessor Service Interface
hEvent      EFI_HANDLE  0
Status      EFI_STATUS  0

.code
;-------------
; Client Task
;-------------

ClientTask proc uses xbx pTCB:PTCB
  local xLoopCount:XWORD
  local xCounter:XWORD

  ;PrintLn "ClientTask running..."
  mov xbx, pTCB
  assume xbx:PTCB

  ;Count from 1 to xLoopCount
  m2m xLoopCount, [xbx].xMaxCount, xax  ;How high to qCount.
  mov xCounter, 0
do1:
  inc xCounter                          ;Do WORK
  .while [xbx].xReady != 0              ;WaituntilResult has been Consumed
    nop                                 ;CpuPause();//Hint to CPU that this is a spin loop
  .endw
  m2m [xbx].xResult, xCounter, xax      ;Report my results
  mov [xbx].xReady, 1                   ;Signal that xResult has been Produced.
  dec xLoopCount
  jnz do1                               ;Do WORK Loop Count times
  ;We have now done all of our work and could exit right now.

  ;For debugging and paranoia's sake, send one last "special" value.
  .while [xbx].xReady != 0              ;Wait until xResult has been Consumed.
    nop                                 ;CpuPause();//Hint to CPU that this is a spin loop
  .endw

  m2m [xbx].xResult, 0xFEEDFACE, xax    ;Indicate that Client Task is exiting
  mov [xbx].xReady, 1                   ;This should be ignored
  assume xbx:nothing
  ret
ClientTask endp

;-----------
; Root Task
;-----------

RootTask proc uses xbx xsi pTCB:PTCB
  local xRemaining:XWORD

  PrintLn "RootTask running..."

  mov xsi, pTCB
  assume xsi:PTCB

  ;Retrieve and Display NUMLOOPS values from the Client Task
  xor ebx, ebx
  .while xbx < NUMLOOPS                 ;Wait until the Client Task signals data is ready
    .while [xsi].xReady == 0
      nop                               ;{CpuPause();//HinttoCPUthatweareinaspin-loop}
    .endw
    ;Display what we received from the Client
    mov xax, NUMLOOPS
    sub xax, xbx
    mov xRemaining, xax
    PrintLn " %d : %d . %d . %d . %d ", xRemaining, [xsi].xProcNum, [xsi].xMaxCount, [xsi].xResult, [xsi].xReady
    mov [rsi].xReady, 0                 ;Tell the Client Task it can run
    inc rbx
  .endw

  ;Give the Client Task a chance to signal it has finished.
  .while [rsi].xReady == 0              ;0xFEEDFACE
    nop                                 ;CpuPause();//HinttoCPUthatweareinaspin-loop}
  .endw
  ;Print the final state of the tcb.
  PrintLn "END : %d . %d . %h . %d ", [rsi].xProcNum, [rsi].xMaxCount, [rsi].xResult, [rsi].xReady
  assume rsi:nothing
  ret
RootTask endp


start proc uses xbx xdi xsi ImageHandle:EFI_HANDLE, pSysTable:PTR_EFI_SYSTEM_TABLE
  local ProcessorInfo:EFI_PROCESSOR_INFORMATION
  local xProcessorNum:XWORD, xEnabledProcessorNum:XWORD
  local cBuffer[100]:CHR, pBuffer:POINTER

  ;Runtime model initialization
  SysInit ImageHandle, pSysTable
  
  mov xbx, pConsoleOut
  assume xbx:ptr ConOut
  invoke [xbx].ClearScreen, xbx
  ;Color change: Bits 0..3 are the foreground color, and bits 4..6 are the background color
  invoke [xbx].SetAttribute, xbx, EFI_YELLOW or EFI_BACKGROUND_BLACK
  invoke [xbx].OutputString, xbx, $OfsCStr("Multiprocessing with UEFI", 13, 10, 13, 10)
  invoke [xbx].OutputString, xbx, xdi
  invoke [xbx].SetAttribute, xbx, EFI_LIGHTGRAY or EFI_BACKGROUND_BLACK

  ;------------------------------------
  ; Beginning of Daryl McDaniel
  ;------------------------------------

    ;-----------
    ; GetMpInfo
    ;-----------

    ;Find the MP Services Protocol

    mov xdi, pBootServices
    invoke [xdi].EFI_BOOT_SERVICES.LocateProtocol, addr EFI_MP_SERVICES_PROTOCOL_GUID, NULL, addr pIServiceMP

    mov Status, xax
    .if xax
      PrintLn "Unable to locate the MP Service procotol: %r ", Status
    .else
      PrintLn "LocateProtocol OK"

      ;Get Number of Processors and Number of Enabled Processors
      mov xcx, pIServiceMP
      invoke [xcx].EFI_MP_SERVICES.GetNumberOfProcessors, xcx, addr xProcessorNum, addr xEnabledProcessorNum
      mov Status, xax
      .if xax
        PrintLn "Unable to get the number of processors: %r ", Status
      .else
        PrintLn "GetNumberOfProcessors OK, result = %d ", xProcessorNum

        ;Get Processor Health and Location information
        mov tcb.xProcNum, 2
        mov xcx, pIServiceMP
        invoke [xcx].EFI_MP_SERVICES.GetProcessorInfo, xcx, tcb.xProcNum, addr ProcessorInfo
        mov Status, xax
        .if xax
          PrintLn "Unable to get information for processor %d : %r ", tcb.xProcNum, Status
        .else
          PrintLn "GetProcessorInfo OK"
        .endif

      .endif

      ;-----------------------------
      ; Start Application Processors
      ;-----------------------------

      ;Create an Event, required to call StartupThisAP in non-blocking mode
      mov xdi, pBootServices
      invoke [xdi].EFI_BOOT_SERVICES.CreateEvent, 0, TPL_NOTIFY, NULL, NULL, addr hEvent
      mov Status, xax
      .if xax == EFI_SUCCESS
        PrintLn "Successful Event creation."

        ;Start a Task on the specified Processor
        mov xcx, pIServiceMP
;        invoke [xcx].EFI_MP_SERVICES.StartupThisAP, xcx, addr ClientTask, tcb.xProcNum, hEvent, 0, addr tcb, 0
        invoke [xcx].EFI_MP_SERVICES.StartupThisAP, xcx, addr ClientTask, tcb.xProcNum, hEvent, 1000, addr tcb, NULL
        mov Status, xax
        .if xax == EFI_SUCCESS
          PrintLn "Task successfully started"
        .else
          PrintLn "Failed to start Task on CPU%d : %r ", tcb.xProcNum, Status
        .endif
      .else
        PrintLn "Event creation failed : %r ", Status
      .endif

      invoke RootTask, addr tcb
   .endif

  ;------------------------------------
  ; End of Daryl McDaniel
  ;------------------------------------

  invoke [xbx].SetAttribute, xbx, EFI_LIGHTGREEN or EFI_BACKGROUND_BLACK
  invoke [xbx].OutputString, xbx, $OfsCStr(13, 10, "press a key to continue...")

  invoke Wait4Key

  invoke [xbx].SetAttribute, xbx, EFI_YELLOW or EFI_BACKGROUND_BLACK
  invoke [xbx].OutputString, xbx, $OfsCStr(13, 10, "bye bye...", 13, 10)
  assume xbx:nothing

  SysDone

  mov xbx, pBootServices
  invoke [xbx].EFI_BOOT_SERVICES.Exit, ImageHandle, EFI_SUCCESS, 0, NULL

start endp

end
