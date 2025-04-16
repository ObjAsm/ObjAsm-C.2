; ==================================================================================================
; Title:      BenchmarkWin.asm
; Author:     G. Fiedrich and Héctor S. Enrique
; Version:    1.0.0
; Purpose:    ObjAsm compilation file for Windows Benchmark Application.
; Notes:      Version C.2.0, January 2023
;             - First release.
; Note:       Gabriele Paoloni. 2010. How to Benchmark Code Execution Times on Intel IA-32 and IA-64
;             Instruction Set Architectures. Retrieved May 26, 2022, from
;             http://www.intel.com/content/dam/www/public/us/en/documents/white-papers/
;             ia-32-ia-64-benchmark-code-execution-paper.pdf
; ==================================================================================================


% include @Environ(OBJASM_PATH)\Code\Macros\Model.inc   ;Include & initialize standard modules
SysSetup OOP, WIN64, WIDE_STRING, DEBUG(WND)            ;Load OOP files and basic OS support

% include &MacPath&fMath.inc

; Memory Layout
;
;                 pTimes                                             pMinValues    pVariances
;                   |                                                    |             |
;                   V              1        2     ... SIZE_OF_STAT       V             V
;                --------      ---------------------------------     --------      --------
;      1        | Ptr(0) | -> | Loop(0), Loop(0), ... , Loop(0) |    |  Min0  |    |  Var0  |
;      2        | Ptr(1) | -> | Loop(1), Loop(1), ... , Loop(1) |    |  Min1  |    |  Var1  |
;      3        | Ptr(2) | -> | Loop(2), Loop(2), ... , Loop(2) |    |  Min2  |    |  Var2  |
;      .        |   .    |    |    .        .               .   |    |   .    |    |   .    |
;      .        |   .    |    |    .        .               .   |    |   .    |    |   .    |
;      .        |   .    |    |    .        .               .   |    |   .    |    |   .    |
; BOUND_OF_LOOP | Ptr(N) | -> | Loop(N), Loop(N), ... , Loop(N) |    |  MinN  |    |  VarN  |
;                --------      ---------------------------------      --------      --------
;                              QWORDs                                 QWORDs        REAL8s

SIZE_OF_STAT  equ 10000     ;Determins the statistical relevance
BOUND_OF_LOOP equ 100       ;Must be > 1


;Values for performance test
.const
  r8Numerator   REAL8   100000.0
  r8Denominator REAL8   10.0
.data
  r8Result      REAL8   0.0
  FpuEnv        BYTE    108 dup(0)


function_under_glass0 macro
  mov rax, 1
endm

function_under_glass1 macro
  fld  REAL8 ptr [r8Numerator]
  fdiv REAL8 ptr [r8Denominator]
  fdiv REAL8 ptr [r8Denominator]
  fdiv REAL8 ptr [r8Denominator]
  fdiv REAL8 ptr [r8Denominator]
  fstp REAL8 ptr [r8Result]
endm

function_under_glass2 macro
  fsave FpuEnv
  frstor FpuEnv
endm

FunctionUnderGlass macro
  function_under_glass1
endm

SetTaskPriority macro
  invoke GetCurrentProcess
  invoke SetPriorityClass, xax, REALTIME_PRIORITY_CLASS
  invoke GetCurrentThread
  invoke SetThreadPriority, xax, THREAD_PRIORITY_TIME_CRITICAL
endm

ResetTaskPriority macro
  invoke GetCurrentProcess
  invoke SetPriorityClass, xax, ABOVE_NORMAL_PRIORITY_CLASS
  invoke GetCurrentThread
  invoke SetThreadPriority, xax, THREAD_PRIORITY_NORMAL
endm

.code
; --------------------------------------------------------------------------------------------------
; Procedure:  FillTimes
; Purpose:    Measure then runtime of the code to analyze. 2 nested loops are executed.
;             The inner loop calls the code SIZE_OF_STAT times to have a static base.
;             The outer loop increases the loop count of the inner loop from 0 to BOUND_OF_LOOP-1.
;             This procedure makes it possible to distinguish the overhead from the actual runtime
;             by means of a linear regression. The calculations are performed using the min values
;             taken by the inner loop.
; Arguments:  Arg1: -> Times array.
; Return:     Nothing.

FillTimes proc uses rbx rdi rsi r12 r13 r14 pTimes:POINTER
  local qStart:QWORD, qStop:QWORD

  SetTaskPriority

  finit
  repeat 3                                              ;Warm up instruction cache
    CPUID
    RDTSC
    mov DWORD ptr [qStart], eax
    mov DWORD ptr [qStart + sizeof(DWORD)], edx
    RDTSCP
    mov DWORD ptr [qStop], eax
    mov DWORD ptr [qStop + sizeof(DWORD)], edx
    CPUID
  endm

  xor rsi, rsi
  mov r14, pTimes
  .while esi < BOUND_OF_LOOP
    mov r12, POINTER ptr [r14 + sizeof(POINTER)*rsi]
    xor edi, edi
    .while edi < SIZE_OF_STAT
      CPUID                                             ;Serialize, uses eax ebx ecx edx!
      RDTSC                                             ;Clock reading
      mov DWORD ptr [qStart], eax                       ;Store time reading as edx::eax QWORD
      mov DWORD ptr [qStart + sizeof(DWORD)], edx

      mov ebx, esi
      test ebx, ebx
      .while !ZERO?
        FunctionUnderGlass                              ;Invoke code to analyse
        dec ebx
      .endw

      RDTSCP                                            ;Execute all up to this instruction
      mov DWORD ptr [qStop], eax                        ;Store time reading as edx::eax QWORD
      mov DWORD ptr [qStop + sizeof(DWORD)], edx
      CPUID                                             ;Serialize, uses eax ebx ecx edx!

      mov rax, qStop
      mov rdx, qStart
      .if rax < rdx
        DbgWarning "CRITICAL ERROR IN TAKING THE TIME"
        DbgDec rsi, "Loop"
        DbgDec rdi, "Stat"
        DbgDec qStart, "Start"
        DbgDec qStop, "Stop"
        xor eax, eax
      .else
        sub rax, rdx
      .endif

;      ;* Test [A=200, B=140]******************************
;      mov rax, 200
;      mul rsi
;      add rax, 140
;      ;***************************************************

      mov QWORD ptr [r12 + sizeof(QWORD)*rdi], rax      ;Store elapsed time
      inc edi
    .endw
    inc esi
  .endw
  ResetTaskPriority
  ret
FillTimes endp


include PaoloniWin.inc

; --------------------------------------------------------------------------------------------------
; Procedure:  start
; Purpose:    Entry point.
; Arguments:  None.
; Return:     Nothing.

start proc
  SysInit                 ;Runtime model initialization
  invoke Benchmark
  SysDone
  ret
start endp

end start