; ==================================================================================================
; Title:      StopWatch.inc
; Author:     G. Friedrich
; Version:    C.1.2
; Purpose:    ObjAsm support of performance monitoring objects.
; Link:       http://www.agner.org/assem/
; Notes:      Version C.1.0, October 2017
;               - First release.
;             Version C.1.1, October 2019
;               - Arithmetic bug in StopWatch.Stop 32 bit corrected.
;             Version C.1.2, June 2024
;               - Arithmetic bug in StopWatch.Stop 64 bit corrected.
; ==================================================================================================


SWS_STOPPED    equ    0
SWS_RUNNING    equ    1

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Object:     StopWatch
; Purpose:    This object is designed for performance monitoring purposes, measuring the elapsed
;             time between its Start and Stop method calls. Internally it uses the
;             QueryPerformanceFrequency API to perform the measuring.
;             Due to the CPU architecture, the time measure depends on many factors, not only from
;             the code. To obtain comparable results, many measures must be averaged.
; Example:
;  local SW:$Obj(StopWatch), cBuffer[50]:CHR
;
;  New SW::StopWatch
;  OCall SW::StopWatch.Init, NULL
;  s2s SW.r8Resolution, $CReal8(1000.0), xax, xcx   ;miliseconds
;  OCall SW::StopWatch.Start
;  ...
;  OCall SW::StopWatch.Stop
;  OCall SW::StopWatch.GetTime
;  lea xdi, cBuffer
;  WriteF xdi, "Runtime = ¦UX ms", xax
;  OCall SW::StopWatch.Done

Object StopWatch, StopWatchID, Primer
  VirtualMethod     GetTime
  VirtualMethod     GetTimeStrA,    PSTRINGA
  VirtualMethod     GetTimeStrW,    PSTRINGW
  RedefineMethod    Init,           POINTER               ;-> Owner
  VirtualMethod     Reset
  VirtualMethod     Start
  VirtualMethod     Stop

  DefineVariable    r8Period,       REAL8,      0.0       ;Perf. timer period = 1/frequency
  DefineVariable    r8Resolution,   REAL8,      1000000.0 ;1.0 => Seconds, 1000000.0 => µS
  DefineVariable    qStartCount,    QWORD,      0         ;Starting count
  DefineVariable    qAccCount,      QWORD,      0         ;Accumulated count
  DefineVariable    qLagCount,      QWORD,      0         ;Start/Stop lag count
  DefineVariable    dStatus,        DWORD,      SWS_STOPPED
ObjectEnd

if TARGET_STR_TYPE eq STR_TYPE_ANSI
  $ObjMthd(GetTimeStr) textequ $ObjMthd(GetTimeStrA)
else
  $ObjMthd(GetTimeStr) textequ $ObjMthd(GetTimeStrW)
endif

; ==================================================================================================

if IMPLEMENT

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     StopWatch.GetTime
; Purpose:    Return the elapsed time in the specified resolution as a QWORD.
; Arguments:  None.
; Return:     edx:eax or rax = Accumulated time.

Method StopWatch.GetTime
  local qTime:QWORD

  SetObject xcx
  fild [xcx].qAccCount
  fmul [xcx].r8Period
  fmul [xcx].r8Resolution
  fistp qTime
  if TARGET_BITNESS eq 32
    mov eax, DWORD ptr [qTime]
    mov edx, DWORD ptr [qTime + sizeof(DWORD)]
  else
    mov rax, qTime
  endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     StopWatch.GetTimeStrA
; Purpose:    Return the elapsed time (see r8Resolution member).
; Arguments:  Arg1: -> Buffer where the ANSI string will be written (at least 20 bytes!).
; Return:     Nothing.

Method StopWatch.GetTimeStrA,, pResult:PSTRINGA
  SetObject xcx
  fild [xcx].qAccCount
  fmul [xcx].r8Period
  fmul [xcx].r8Resolution
  invoke St0ToStrA, pResult, 0, 6, f_NOR                ;pResult
  fUnload
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     StopWatch.GetTimeStrW
; Purpose:    Return the elapsed time (see r8Resolution member).
; Arguments:  Arg1: -> Buffer where the WIDE string will be written (at least 20 words!).
; Return:     Nothing.

Method StopWatch.GetTimeStrW,, pResult:PSTRINGW
  SetObject xcx
  fild [xcx].qAccCount
  fmul [xcx].r8Period
  fmul [xcx].r8Resolution
  invoke St0ToStrW, pResult, 0, 6, f_NOR                ;pResult
  fUnload
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     StopWatch.Init
; Purpose:    Initialize and calibrates the object.
; Arguments:  Arg1: -> Owner object.
; Return:     Nothing.

Method StopWatch.Init, uses xbx xsi, pOwner:POINTER
  local qFreq:QWORD

  SetObject xsi
  ACall xsi.Init, pOwner
  invoke QueryPerformanceFrequency, addr qFreq          ;Get the Performance Frequency
  fild qFreq                                            ;Load the FPU
  fld1
  fdivrp st(1), st(0)                                   ;Compute reciprocal value
  xor eax, eax
  mov DWORD ptr [xsi].qLagCount, eax
  mov DWORD ptr [xsi + sizeof(DWORD)].qLagCount, eax
  fstp [xsi].r8Period                                   ;Store it
  mov ebx, 256
  OCall xsi::StopWatch.Reset
  .repeat
    OCall xsi.Start
    OCall xsi.Stop
    dec ebx
  .until ZERO?
  if TARGET_BITNESS eq 32
    mov eax, DWORD ptr [esi].qAccCount
    shr eax, 8                                          ;Div 256
    mov DWORD ptr [esi].qLagCount, eax
    m2z DWORD ptr [esi + sizeof(DWORD)].qLagCount
  else
    mov rax, [rsi].qAccCount
    shr rax, 8                                          ;Div 256
    mov [rsi].qLagCount, rax
  endif
  OCall xsi.Reset
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     StopWatch.Reset
; Purpose:    Reset the time count.
; Arguments:  None.
; Return:     Nothing.

Method StopWatch.Reset
  SetObject xcx
  .if [xcx].dStatus == SWS_STOPPED
    if TARGET_BITNESS eq 32
      xor eax, eax
      mov DWORD ptr [ecx].qAccCount, eax
      mov DWORD ptr [ecx + sizeof(DWORD)].qAccCount, eax
    else
      m2z [rcx].qAccCount
    endif
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     StopWatch.Start
; Purpose:    Start the time measuring.
; Arguments:  None.
; Return:     Nothing.

Method StopWatch.Start
  local qCount:QWORD

  invoke QueryPerformanceCounter, addr qCount
  SetObject xcx
  .if [xcx].dStatus == SWS_STOPPED
    mov [xcx].dStatus, SWS_RUNNING
    if TARGET_BITNESS eq 32
      mrm DWORD ptr [ecx].qStartCount, DWORD ptr [qCount], eax
      mrm DWORD ptr [ecx + sizeof(DWORD)].qStartCount, DWORD ptr [qCount + sizeof(DWORD)], edx
    else
      mrm [rcx].qStartCount, qCount, rax
    endif
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     StopWatch.Stop
; Purpose:    Stop the time measuring.
; Arguments:  None.
; Return:     Nothing.

Method StopWatch.Stop
  local qCount:QWORD

  invoke QueryPerformanceCounter, addr qCount
  SetObject xcx
  .if [xcx].dStatus == SWS_RUNNING
    if TARGET_BITNESS eq 32
      mov eax, DWORD ptr [qCount]
      mov edx, DWORD ptr [qCount + sizeof(DWORD)]
      sub eax, DWORD ptr [ecx].qStartCount
      sbb edx, DWORD ptr [ecx + sizeof(DWORD)].qStartCount
      sub eax, DWORD ptr [ecx].qLagCount
      sbb edx, 0
      add DWORD ptr [ecx].qAccCount, eax
      adc DWORD ptr [ecx + sizeof(DWORD)].qAccCount, edx
    else
      mov rax, qCount
      sub rax, [rcx].qStartCount
      sub rax, [rcx].qLagCount
      add [rcx].qAccCount, rax
    endif
    mov [xcx].dStatus, SWS_STOPPED
  .endif
MethodEnd

endif
