; ==================================================================================================
; Title:      PaoloniWin.inc
; Author:     G. Friedrich
; Version:    C.2.1
; Purpose:    Include file implementing the Paoloni benchmark method for measuring cycle-accurate
;             code execution times on Windows.
; Version:    Version C.2.0, January 2023
;               - Initial release.
;             Version C.2.1, May 2026
;               - 32-bit code path added.
;               - Code refactored.
;               - Overview and instructions added.
;
; Note:       Gabriele Paoloni, 2010. How to Benchmark Code Execution Times on Intel IA-32 and IA-64
;             Instruction Set Architectures. Retrieved May 26, 2022, from
;             http://www.intel.com/content/dam/www/public/us/en/documents/white-papers/
;             ia-32-ia-64-benchmark-code-execution-paper.pdf
;             Based on BenchmarkUEFI by HSE.
;
; ==================================================================================================

; ==================================================================================================
; HOW TO USE THE PAOLONI BENCHMARK FRAMEWORK
; ==================================================================================================
;
; OVERVIEW
; --------
; This framework measures the cycle-accurate execution time of any code snippet on Intel x86/x64
; using the Paoloni method: two nested loops with RDTSC/RDTSCP timestamps, followed by linear
; regression to separate measurement overhead from actual runtime.
;
; The framework runs your code in a double loop:
;   - Outer loop (BOUND_OF_LOOP iterations): increases the inner loop count from 0 to N-1
;   - Inner loop (SIZE_OF_STAT repetitions): samples timing at each loop count for statistical
;     stability
; Linear regression on the minimum values then separates:
;   - Slope     -> actual code execution time  (r8Measure,  in clock ticks)
;   - Intercept -> measurement overhead        (r8Overhead, in clock ticks)
;
; --------------------------------------------------------------------------------------------------
; STEP 1 - CONFIGURE THE CONSTANTS  (in your .asm file, before including PaoloniWin.inc)
; --------------------------------------------------------------------------------------------------
;
;   SIZE_OF_STAT  equ 100    ; Statistical samples per loop count. Higher = more stable results.
;   BOUND_OF_LOOP equ 500    ; Number of loop-count steps. Must be > 1.
;
;   Rule of thumb: SIZE_OF_STAT x BOUND_OF_LOOP is the total number of measurements.
;   100 x 500 = 50,000 is a reasonable default. Increase SIZE_OF_STAT in noisy environments.
;
; --------------------------------------------------------------------------------------------------
; STEP 2 - DEFINE THE CODE UNDER TEST
; --------------------------------------------------------------------------------------------------
;
;   Define the ProcedureUnderGlass macro with the code you want to benchmark:
;
;     ProcedureUnderGlass macro
;       invoke MyFunction, addr MyData    ; <- replace with your own code or function call
;     endm
;
;   The macro is called inside the timing loop, so keep it to a single logical operation:
;   one function call, one instruction sequence, etc.
;
; --------------------------------------------------------------------------------------------------
; STEP 3 - CALL Benchmark FROM YOUR ENTRY POINT
; --------------------------------------------------------------------------------------------------
;
;   start proc
;     SysInit                   ; Runtime model initialization
;     invoke Benchmark          ; Runs the full measurement
;     .if eax != FALSE
;       invoke ShowStats        ; Prints the full report to DebugCenter
;     .endif
;     SysDone                   ; Runtime model shutdown
;     ret
;   start endp
;
;   To benchmark across varying conditions (e.g. different string lengths), call Benchmark
;   in a loop and read r8Measure after each call:
;
;     .while dStrSize <= 64
;       mov BYTE ptr [xsi], 0
;       invoke Benchmark
;       .break .if eax == FALSE
;       DbgWriteF DbgColorBlue, "MyFunc", "|F1", r8Measure
;       mov BYTE ptr [xsi], 'X'
;       inc xsi
;       add dStrSize, 1
;     .endw
;
; --------------------------------------------------------------------------------------------------
; STEP 4 - READ THE RESULTS
; --------------------------------------------------------------------------------------------------
;
;   After Benchmark returns, the following global variables are populated:
;
;     r8Measure    [Tick]    Actual code execution time       <- the main result
;     r8Overhead   [Tick]    Measurement overhead (RDTSC + CPUID cost)
;     dSpurious    [-]       Spurious minimum values          (quality indicator, should be low)
;     qMaxMaxDiff  [Tick]    Max spread across all samples    (noise indicator)
;     r8MeanVar    [Tick^2]  Mean variance across loop counts
;     r8VarOfVars  [Tick^4]  Variance of variances            (stability indicator)
;     r8MinsMSE    [Tick^2]  Linear regression MSE            (fit quality, lower is better)
;     r8R2         [-]       R^2 coefficient                  (should be close to 1.0)
;
;   Call ShowStats to dump all of the above to DebugCenter in a formatted table.
;
; --------------------------------------------------------------------------------------------------
; STEP 5 - INTERPRET THE OUTPUT
; --------------------------------------------------------------------------------------------------
;
;   A healthy run looks like:
;
;     Spurious =    1           [-]       Number of Spurious min. Values
;     MaxMaxDiff =  120086      [Tick]    Max. Spread of the Values
;     MeanVar =     2.344E+0005 [Tick^2]  Mean Variance
;     VarOfVars =   1.289E+0011 [Tick^4]  Variance of Variances
;     MinsMSE =     4.826E+0001 [Tick^2]  Linear Regression MSE
;     R2 =          9.994E-0001 [-]       Determination Coefficient
;     Overhead =    26.7        [Tick]    Measurement Overhead
;     Measure =     9.5         [Tick]    Code Execution Time    <- your result
;
;   Quality checks:
;     R^2 >= 0.999  -> linear fit is good, result is trustworthy
;     Spurious ~ 0  -> minimal interference from OS scheduling
;     MSE low relative to Measure -> regression is accurate
;   If R^2 is low or Spurious is high, close background applications and re-run.
;
; --------------------------------------------------------------------------------------------------
; NOTES
; --------------------------------------------------------------------------------------------------
;
;   - The framework automatically elevates thread priority to REALTIME_PRIORITY_CLASS during
;     measurement and restores it afterward. Avoid running other CPU-heavy tasks simultaneously.
;   - Works in both 32-bit and 64-bit builds. The TARGET_BITNESS conditional handles the
;     difference transparently.
;   - Results are in CPU clock ticks, not nanoseconds. Divide by your CPU frequency to convert
;     if needed (e.g. 9.5 ticks / 3.5 GHz ~ 2.7 ns).
;
; ==================================================================================================
;
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
;
; ==================================================================================================


.const
  dBoundOfLoop  DWORD   BOUND_OF_LOOP

.data?
  dSpurious     DWORD   ?
  qMaxMaxDiff   QWORD   ?
  r8MeanVar     REAL8   ?
  r8VarOfVars   REAL8   ?
  r8MinsMSE     REAL8   ?
  r8R2          REAL8   ?
  r8Overhead    REAL8   ?
  r8Measure     REAL8   ?

SetTaskPriority macro
  invoke GetCurrentProcess
  invoke SetPriorityClass, xax, REALTIME_PRIORITY_CLASS     ; Minimize OS scheduling interference
  invoke GetCurrentThread
  invoke SetThreadPriority, xax, THREAD_PRIORITY_TIME_CRITICAL
endm

ResetTaskPriority macro
  invoke GetCurrentProcess
  invoke SetPriorityClass, xax, ABOVE_NORMAL_PRIORITY_CLASS ; Restore normal process priority
  invoke GetCurrentThread
  invoke SetThreadPriority, xax, THREAD_PRIORITY_NORMAL
endm

.code
; --------------------------------------------------------------------------------------------------
; Procedure:  FillTimes
; Purpose:    Measure the runtime of the code to analyze. 2 nested loops are executed.
;             The inner loop calls the code SIZE_OF_STAT times to have a static base.
;             The outer loop increases the loop count of the inner loop from 0 to BOUND_OF_LOOP-1.
;             This procedure makes it possible to distinguish the overhead from the actual runtime
;             by means of a linear regression. The calculations are performed using the min values
;             taken by the inner loop.
; Arguments:  Arg1: -> Times array.
; Return:     Nothing.

FillTimes proc uses xbx xdi xsi pTimes:POINTER
  local qStart:QWORD, qStop:QWORD

  SetTaskPriority

  finit
  repeat 3                                              ; Warm up instruction cache and RDTSC pipeline
    CPUID
    RDTSC
    mov DWORD ptr [qStart], eax
    mov DWORD ptr [qStart + sizeof(DWORD)], edx
    RDTSCP
    mov DWORD ptr [qStop], eax
    mov DWORD ptr [qStop + sizeof(DWORD)], edx
    CPUID
  endm

  xor esi, esi                                          ; Outer loop counter (0..BOUND_OF_LOOP-1)
  .while esi < BOUND_OF_LOOP
    xor edi, edi                                        ; Inner loop counter (0..SIZE_OF_STAT-1)
    .while edi < SIZE_OF_STAT
      CPUID                                             ; Serialize, uses eax ebx ecx edx!
      RDTSC                                             ; Clock reading
      mov DWORD ptr [qStart], eax                       ; Store time reading as edx::eax QWORD
      mov DWORD ptr [qStart + sizeof(DWORD)], edx
      mov ebx, esi                                      ; Repeat count = outer loop index
      test ebx, ebx
      .while !ZERO?
        ProcedureUnderGlass                             ; Invoke code to analyse
        dec ebx
      .endw

      RDTSCP                                            ; Execute all preceding instructions first
      mov DWORD ptr [qStop], eax                        ; Store time reading as edx::eax QWORD
      mov DWORD ptr [qStop + sizeof(DWORD)], edx
      CPUID                                             ; Serialize, uses eax ebx ecx edx!

      mov xcx, pTimes                                   ; Store elapsed time in Times[esi][edi]
      mov xdx, POINTER ptr [xcx + sizeof(POINTER)*xsi]
      lea xcx, [xdx + sizeof(QWORD)*xdi]
    if TARGET_BITNESS eq 64
      mov rax, qStop
      sub rax, qStart
      mov [rcx], rax                                    ; Store elapsed time
    else
      mov eax, DWORD ptr [qStop]
      mov edx, DWORD ptr [qStop + sizeof(DWORD)]
      sub eax, DWORD ptr [qStart]
      sbb edx, DWORD ptr [qStart + sizeof(DWORD)]
      mov [ecx], eax                                    ; Store elapsed time (low)
      mov [ecx + sizeof(DWORD)], edx                    ; Store elapsed time (high)
    endif
      inc edi
    .endw
    inc esi
  .endw

  ResetTaskPriority
  ret
FillTimes endp

; --------------------------------------------------------------------------------------------------
; Procedure:  Benchmark
; Purpose:    Perform the Paoloni benchmark.
; Arguments:  None.
; Return:     eax: TRUE if succeeded, otherwise FALSE.

Benchmark proc uses xbx xdi xsi
  local pTimes:POINTER, pVariances:POINTER, r8Variance:REAL8, pMinValues:POINTER
  local qMaxTime:QWORD, qMinTime:QWORD, qPrevMinTime:QWORD
  local r8AccVariance:REAL8, r8VarMins:REAL8, SlrData:SLR_DATA

  mov pVariances, $MemAlloc(BOUND_OF_LOOP*sizeof(REAL8))
  .if pVariances == NULL
    DbgWarning "Unable to allocate memory for Variances"
    mov eax, FALSE
  .else
    mov pMinValues, $MemAlloc(BOUND_OF_LOOP*sizeof(QWORD))
    .if pMinValues == NULL
      DbgWarning "Unable to allocate memory for MinValues"
      MemFree pVariances
      mov eax, FALSE
    .else
      mov pTimes, $MemAlloc(BOUND_OF_LOOP*sizeof(POINTER))
      .if pTimes == NULL
        DbgWarning "Unable to allocate memory for time pointers"
        MemFree pMinValues
        MemFree pVariances
        mov eax, FALSE
      .else
        xor ebx, ebx
        .while xbx < BOUND_OF_LOOP                      ; Allocate one row per outer loop count
          MemAlloc SIZE_OF_STAT*sizeof(REAL8)
          mov xcx, pTimes
          mov [xcx + sizeof(POINTER)*xbx], xax
          .break .if xax == 0                           ; Abort on allocation failure
          inc ebx
        .endw
        .if xbx != BOUND_OF_LOOP
          DbgWarning "Unable to allocate memory for all time values"
          .while xbx != 0                               ; Free all successfully allocated rows
            dec xbx
            mov xax, pTimes
            MemFree [xax + sizeof(POINTER)*xbx]
          .endw
          MemFree pTimes
          MemFree pMinValues
          MemFree pVariances
          mov eax, FALSE
        .else
          invoke FillTimes, pTimes                      ; Collect all timing measurements
          xor ebx, ebx
          mov dSpurious, ebx                            ; Reset statistics
        if TARGET_BITNESS eq 32
          mov DWORD ptr [qMaxMaxDiff], ebx
          mov DWORD ptr [qMaxMaxDiff + sizeof(DWORD)], ebx
          mov DWORD ptr [qPrevMinTime], ebx
          mov DWORD ptr [qPrevMinTime + sizeof(DWORD)], ebx
          mov DWORD ptr [r8AccVariance], ebx
          mov DWORD ptr [r8AccVariance + sizeof(DWORD)], ebx
        else
          mov qMaxMaxDiff, rbx
          mov qPrevMinTime, rbx
          mov r8AccVariance, rbx
        endif
          .while ebx < BOUND_OF_LOOP

            ;Get Min and Max tick values for this loop count
          if TARGET_BITNESS eq 32
            mov DWORD ptr [qMinTime], -1
            mov DWORD ptr [qMinTime + sizeof(DWORD)], -1
            mov DWORD ptr [qMaxTime], 0
            mov DWORD ptr [qMaxTime + sizeof(DWORD)], 0
          else
            mov qMinTime, -1
            mov qMaxTime, 0
          endif

            xor edi, edi
            .while edi < SIZE_OF_STAT                   ; Scan all samples for this loop count
              mov xax, pTimes
              mov xcx, POINTER ptr [xax + sizeof(POINTER)*xbx]
            if TARGET_BITNESS eq 32
              mov eax, [ecx + sizeof(QWORD)*edi]
              mov edx, [ecx + sizeof(QWORD)*edi + sizeof(DWORD)]

              mov ecx, DWORD ptr [qMinTime + sizeof(DWORD)]   ; Get high DWORD of qMinTime
              .if ecx > edx || (ecx == edx && DWORD ptr [qMinTime] > eax)
                mov DWORD ptr [qMinTime], eax
                mov DWORD ptr [qMinTime + sizeof(DWORD)], edx
              .endif

              mov ecx, DWORD ptr [qMaxTime + sizeof(DWORD)]   ; Get high DWORD of qMaxTime
              .if ecx < edx || (ecx == edx && DWORD ptr [qMaxTime] < eax)
                mov DWORD ptr [qMaxTime], eax
                mov DWORD ptr [qMaxTime + sizeof(DWORD)], edx
              .endif
            else
              mov rax, [rcx + sizeof(QWORD)*rdi]
              .if qMinTime > rax
                mov qMinTime, rax
              .endif

              .if qMaxTime < rax
                mov qMaxTime, rax
              .endif
            endif
              inc edi
            .endw

            ; Update qMaxMaxDiff if this row's spread is the largest seen so far
          if TARGET_BITNESS eq 32
            mov eax, DWORD ptr [qMaxTime]
            mov edx, DWORD ptr [qMaxTime + sizeof(DWORD)]
            sub eax, DWORD ptr [qMinTime]
            sbb edx, DWORD ptr [qMinTime + sizeof(DWORD)]

            mov ecx, DWORD ptr [qMaxMaxDiff + sizeof(DWORD)]
            .if ecx < edx || (ecx == edx && DWORD ptr [qMaxMaxDiff] < eax)
              mov DWORD ptr [qMaxMaxDiff], eax
              mov DWORD ptr [qMaxMaxDiff + sizeof(DWORD)], edx
            .endif
          else
            mov rax, qMaxTime
            sub rax, qMinTime
            .if rax > qMaxMaxDiff
              mov qMaxMaxDiff, rax
            .endif
          endif

            ; Store the minimum tick value for this loop count (used for linear regression)
            mov xcx, pMinValues
          if TARGET_BITNESS eq 32
            mov eax, DWORD ptr qMinTime
            mov edx, DWORD ptr [qMinTime + sizeof(DWORD)]
            mov [ecx + sizeof(QWORD)*ebx], eax
            mov [ecx + sizeof(QWORD)*ebx + sizeof(DWORD)], edx
          else
            mov rax, qMinTime
            mov [rcx + sizeof(QWORD)*rbx], rax
          endif

            ; Count spurious minima: a min smaller than the previous is physically impossible
          if TARGET_BITNESS eq 32
            mov ecx, DWORD ptr [qPrevMinTime + sizeof(DWORD)]   ; Get high DWORD of qPrevMinTime
            .if (ecx != 0 || DWORD ptr (qPrevMinTime) != 0)
              .if (ecx > eax) || (ecx == edx && DWORD ptr [qPrevMinTime] < eax)
                inc dSpurious
              .endif
            .endif
            mov DWORD ptr [qPrevMinTime], eax
            mov DWORD ptr [qPrevMinTime + sizeof(DWORD)], edx
          else
            mov rcx, qPrevMinTime
            .if (rcx != 0) && (rcx > rax)
              inc dSpurious
            .endif
            mov qPrevMinTime, rax
          endif

            ; Calc Variance of tick values for the same number of loops
            mov xdx, pVariances
            mov xdi, pTimes
            lea xsi, [xdx + sizeof(REAL8)*xbx]
            invoke CalcVarianceQW, POINTER ptr [xdi + sizeof(POINTER)*xbx], SIZE_OF_STAT, xsi

            ; Cumulate the Variance values
            fld REAL8 ptr [xsi]
            fst r8Variance
            fadd r8AccVariance
            fstp r8AccVariance

            inc xbx
          .endw

          ; Calc the Variance of the Variances
          invoke CalcVarianceR8, pVariances, BOUND_OF_LOOP, addr r8VarOfVars

          fld r8AccVariance                             ; Calc mean variance across all loop counts
          fidiv dBoundOfLoop
          fstp r8MeanVar

          m2m SlrData.pData, pMinValues, xax            ; Linear regression on min values:
          mov SlrData.xCount, BOUND_OF_LOOP             ; slope = code time, intercept = overhead
          invoke SLR_Init, addr SlrData
          invoke SLR_Calc_AB_MSE_QW, addr SlrData
          s2s r8Measure, SlrData.r8Slope, xax, xdx
          s2s r8Overhead, SlrData.r8Intercept, xcx, xax
          s2s r8MinsMSE, SlrData.r8MSE, xax, xdx

          invoke CalcVarianceQW, pMinValues, BOUND_OF_LOOP, addr r8VarMins
          fld1                                          ; Calc R^2 = 1 - MSE/Var(mins)
          fld SlrData.r8MSE
          fdiv r8VarMins
          fsubp st(1), st(0)
          fstp r8R2

          ; Release allocated memory
          mov ebx, BOUND_OF_LOOP
          mov xdi, pTimes
          .repeat
            MemFree POINTER ptr [xdi]
            add xdi, sizeof(POINTER)
            dec xbx
          .until ZERO?

          MemFree pMinValues
          MemFree pVariances
          MemFree pTimes
          mov eax, TRUE
        .endif
      .endif
    .endif
  .endif
  ret
Benchmark endp

; --------------------------------------------------------------------------------------------------
; Procedure:  ShowStats
; Purpose:    Output on DebugCenter the statistical evaluation. DEBUGGING must be activated.
; Arguments:  None.
; Return:     Nothing.

ShowStats proc
  ALIGN_1 = 14
  ALIGN_2 = 26
  ALIGN_3 = 38
  DbgWriteF ,, "Spurious = ¦AT¦UD ¦AT[-]¦ATNumber of Spurious min. Values", \
            ALIGN_1, dSpurious, ALIGN_2, ALIGN_3
  DbgWriteF ,, "MaxMaxDiff = ¦AT¦UQ ¦AT[Tick]¦ATMax. Spread of the Values", \
            ALIGN_1, qMaxMaxDiff, ALIGN_2, ALIGN_3
  DbgWriteF ,, "MeanVar = ¦AT¦E3 ¦AT[Tick^2]¦ATMean Variance", \
            ALIGN_1, r8MeanVar, ALIGN_2, ALIGN_3
  DbgWriteF ,, "VarOfVars = ¦AT¦E3 ¦AT[Tick^4]¦ATVariance of Variances", \
            ALIGN_1, r8VarOfVars, ALIGN_2, ALIGN_3
  DbgWriteF ,, "MinsMSE = ¦AT¦E3 ¦AT[Tick^2]¦ATLinear Regression MSE", \
            ALIGN_1,  r8MinsMSE, ALIGN_2, ALIGN_3
  DbgWriteF ,, "R² = ¦AT¦E3 ¦AT[-]¦ATDetermination Coefficient", \
            ALIGN_1,  r8R2, ALIGN_2, ALIGN_3
  DbgWriteF ,, "Overhead = ¦AT¦F1 ¦AT[Tick]¦ATMeasurement Overhead", \
            ALIGN_1,  r8Overhead, ALIGN_2, ALIGN_3
  DbgWriteF DbgColorBlue,, "Measure = ¦AT¦F1 ¦AT[Tick]¦ATCode Execution Time", \
            ALIGN_1,  r8Measure, ALIGN_2, ALIGN_3
  DbgLine
  ret
ShowStats endp
