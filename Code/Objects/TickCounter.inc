; ==================================================================================================
; Title:      TickCounter.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm support of performance monitoring objects.
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


TCR_STOPPED   equ   0
TCR_RUNNING   equ   1

TCR_LAG_REPS  equ   256     ;Must be a power of 2

; --------------------------------------------------------------------------------------------------
; Object:     TickCounter
; Purpose:    This object is designed for performance monitoring purposes, counting the number of
;             CPU ticks between its Start and Stop method calls. It uses the rdtsc instruction to
;             perform the count. Due to the CPU architecture, the count result depends on many
;             factors, not only from the code. To obtain comparable results, many counts must be
;             averaged.

Object TickCounter, TickCounterID, Primer
  VirtualMethod     GetTicks
  RedefineMethod    Init,           POINTER             ;-> Owner
  VirtualMethod     Reset
  VirtualMethod     Start
  VirtualMethod     Stop

  DefineVariable    qTicksStart,    QWORD,      0       ;Starting tick count
  DefineVariable    qTicksAcc,      QWORD,      0       ;Accumulated ticks
  DefineVariable    qTicksLag,      QWORD,      0       ;Overhead (Start/Stop)
  DefineVariable    dStatus,        DWORD,      TCR_STOPPED
ObjectEnd


; ==================================================================================================

if IMPLEMENT

; --------------------------------------------------------------------------------------------------
; Method:     TickCounter.GetTicks
; Purpose:    Return the tick count.
; Arguments:  None.
; Return:     rax/edx::eax = Tick count.

Method TickCounter.GetTicks
  SetObject xcx
  if TARGET_BITNESS eq 32
    mov eax, DWORD ptr [ecx].qTicksAcc
    mov edx, DWORD ptr [ecx + sizeof DWORD].qTicksAcc
  else
    mov rax, [rcx].qTicksAcc
  endif

MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     TickCounter.Init
; Purpose:    Initialize and calibrate the performance monitor.
; Arguments:  Arg1: -> Owner object.
; Return:     Nothing.

Method TickCounter.Init, uses xbx xsi, pOwner:POINTER
  SetObject xsi
  ACall xsi.Init, pOwner
  if TARGET_BITNESS eq 32
    m2z DWORD ptr [esi].qTicksLag
    m2z DWORD ptr [esi + sizeof DWORD].qTicksLag
  else
    m2z [rsi].qTicksLag
  endif
  mov ebx, TCR_LAG_REPS
  OCall xsi.Reset
  .repeat
    OCall xsi.Start
    OCall xsi.Stop
    dec ebx
  .until ZERO?
  if TARGET_BITNESS eq 32
    mov eax, DWORD ptr [esi].qTicksAcc
    shr eax, $Log2(TCR_LAG_REPS)
    mov DWORD ptr [esi].qTicksLag, eax
    m2z DWORD ptr [esi + sizeof DWORD].qTicksLag
  else
    mov rax, [rsi].qTicksAcc
    shr rax, $Log2(TCR_LAG_REPS)
    mov [rsi].qTicksLag, rax
  endif
  OCall xsi.Reset
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     TickCounter.Reset
; Purpose:    Reset the performance monitor.
; Arguments:  None.
; Return:     Nothing.

Method TickCounter.Reset
  SetObject xcx
  .if [xcx].dStatus == TCR_STOPPED
    if TARGET_BITNESS eq 32
      m2z DWORD ptr [ecx].qTicksAcc
      m2z DWORD ptr [ecx + 4].qTicksAcc
    else
      m2z [rcx].qTicksAcc
    endif
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     TickCounter.Start
; Purpose:    Start the performance monitor.
; Arguments:  None.
; Return:     Nothing.
; Note:       ebx is modified by cpuid

Method TickCounter.Start, uses xbx xsi
  ANNOTATION use:xbx

  SetObject xsi
  .if [xsi].dStatus == TCR_STOPPED
    mov [xsi].dStatus, TCR_RUNNING
    sub eax, eax                                      ;eax = 0
    cpuid                                             ;Serialize, writes xbx
    rdtsc                                             ;Read time stamp counter into edx:eax
    if TARGET_BITNESS eq 32
      mov DWORD ptr [esi].qTicksStart, eax
      mov DWORD ptr [esi + sizeof DWORD].qTicksStart, edx
    else
      shl rdx, 32
      or rax, rdx                                     ;Combine into 64 bit register
      mov [rsi].qTicksStart, rax
    endif
    sub eax, eax                                      ;eax = 0
    cpuid                                             ;Serialize
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     TickCounter.Stop
; Purpose:    Stop the performance monitor.
; Arguments:  None.
; Return:     rax/edx::eax = elapsed time since last stop.
; Note:       ebx is modified by cpuid

Method TickCounter.Stop, uses xbx xsi
  ANNOTATION use:xbx

  SetObject xsi
  .if [xsi].dStatus == TCR_RUNNING
    sub eax, eax                                      ;eax = 0
    cpuid                                             ;Serialize, writes xbx
    rdtsc                                             ;Read time stamp counter into edx:eax
    if TARGET_BITNESS eq 32
      sub eax, DWORD ptr [esi].qTicksStart
      sbb edx, DWORD ptr [esi + sizeof DWORD].qTicksStart
      sub eax, DWORD ptr [esi].qTicksLag
      sbb edx, DWORD ptr [esi + sizeof DWORD].qTicksLag
      add DWORD ptr [esi].qTicksAcc, eax
      adc DWORD ptr [esi + sizeof DWORD].qTicksAcc, edx
    else
      shl rdx, 32
      or rax, rdx                                     ;Combine into 64 bit register
      sub rax, [rsi].qTicksStart
      sub rax, [rsi].qTicksLag
      add [rsi].qTicksAcc, rax
    endif
    mov [xsi].dStatus, TCR_STOPPED
  .endif
MethodEnd

endif
