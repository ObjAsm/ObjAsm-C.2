; ==================================================================================================
; Title:      PaoloniWin.inc
; Author:     G. Friedrich
; Version:    C.2.0
; Purpose:    Include file for Windows Benchmark Application.
; Version:    Version C.2.0, January 2023
;             - First release.
;
; Note:       Gabriele Paoloni, 2010. How to Benchmark Code Execution Times on Intel IA-32 and IA-64
;             Instruction Set Architectures. Retrieved May 26, 2022, from
;             http://www.intel.com/content/dam/www/public/us/en/documents/white-papers/ia-32-ia-64-benchmark-code-execution-paper.pdf
;             Based on BenchmarkUEFI by HSE.
;
; ==================================================================================================

;DebugCenter output:
;
;  Spurious =    1           [-]        Number of Spurious min. Values
;  MaxMaxDiff =  120086      [Tick]     Max. Spread of the Values
;  MeanVar =     2.344E+0005 [Tick^2]   Mean Variance
;  VarOfVars =   1.289E+0011 [Tick^4]   Variance of Variances
;  MinsMSE =     4.826E+0001 [Tick^2]   Linear Regression MSE
;  R² =          9.994E-0001 [-]        Determination Coefficient
;  Overhead =    26.7        [Tick]     Measurement Overhead
;  Measure =     9.5         [Tick]     Code Execution Time


.const
  dBoundOfLoop  DWORD   BOUND_OF_LOOP

.code
; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  Benchmark
; Purpose:    Perform the Paoloni benchmark.
; Arguments:  None.
; Return:     rax = Error code.

Benchmark proc uses rbx rdi rsi
  local pTimes:POINTER, pVariances:POINTER, r8Variance:REAL8, qSpurious:QWORD, pMinValues:POINTER
  local qMaxDiff:QWORD, qMaxTime:QWORD, qMinTime:QWORD, qPrevMinTime:QWORD
  local r8AccVariance:REAL8, qMaxMaxDiff:QWORD, r8VarOfVars:REAL8, r8MinsMSE:REAL8, r8MeanVar:REAL8
  local r8Measure:REAL8, r8Overhead:REAL8, r8VarMins:REAL8, r8R2:REAL8
  local SlrData:SLR_DATA

  mov pVariances, $MemAlloc(BOUND_OF_LOOP*sizeof(REAL8))
  .if pVariances == NULL
    DbgWarning "Unable to allocate memory for Variances"
    mov rax, 0
  .else
    mov pMinValues, $MemAlloc(BOUND_OF_LOOP*sizeof(QWORD))
    .if pMinValues == NULL
      DbgWarning "Unable to allocate memory for MinValues"
      MemFree pVariances
      mov rax, 0
    .else
      mov pTimes, $MemAlloc(BOUND_OF_LOOP*sizeof(POINTER))
      .if pTimes == NULL
        DbgWarning "Unable to allocate memory for Times"
        MemFree pMinValues
        MemFree pVariances
        mov rax, 0
      .else
        xor ebx, ebx
        .while rbx < BOUND_OF_LOOP
          MemAlloc SIZE_OF_STAT*sizeof(REAL8)
          mov rcx, pTimes
          mov [rcx + sizeof(POINTER)*rbx], rax
          .break .if rax == 0
          inc rbx
        .endw
        .if rbx != BOUND_OF_LOOP
          DbgWarning "Unable to allocate memory for Time[%d]", rbx
          .while rbx != 0
            dec rbx
            mov rax, pTimes
            MemFree [rax + sizeof(POINTER)*rbx]
            dec rbx
          .endw
          MemFree pTimes
          MemFree pMinValues
          MemFree pVariances
          mov rax, 0
        .else
          invoke FillTimes, pTimes

          xor ebx, ebx
          mov qSpurious, rbx
          mov qMaxMaxDiff, rbx
          mov qPrevMinTime, rbx
          mov r8AccVariance, rbx
          .while rbx < BOUND_OF_LOOP

            ;Get Min and Max tick values
            mov qMinTime, -1
            mov qMaxTime, 0

            xor edi, edi
            mov rax, pTimes
            mov rcx, POINTER ptr [rax + sizeof(POINTER)*rbx]
            .while rdi < SIZE_OF_STAT
              mov rdx, QWORD ptr [rcx + sizeof(QWORD)*rdi]
              .if qMinTime > rdx
                mov qMinTime, rdx
              .endif
              .if qMaxTime < rdx
                mov qMaxTime, rdx
              .endif
              inc edi
            .endw
            mov rax, qMaxTime
            sub rax, qMinTime
            mov qMaxDiff, rax
            .if rax > qMaxMaxDiff
              mov qMaxMaxDiff, rax
            .endif

            mov rcx, pMinValues
            mov rax, qMinTime
            mov QWORD ptr [rcx + sizeof(QWORD)*rbx], rax

            mov rcx, qPrevMinTime
            .if (rcx != 0) && (rcx > rax)
              inc qSpurious
            .endif
            mov qPrevMinTime, rax

            ;Calc Variance of tick values for the same number of loops
            mov rdx, pVariances
            mov rdi, pTimes
            lea rsi, [rdx + sizeof(REAL8)*rbx]
            invoke CalcVarianceQW, POINTER ptr [rdi + sizeof(POINTER)*rbx], SIZE_OF_STAT, rsi

            ;Cummulate the Variance values
            fld REAL8 ptr [rsi]
            fst r8Variance
            fadd r8AccVariance
            fstp r8AccVariance

            inc rbx
          .endw

          ;Calc the Variance of the Variances
          invoke CalcVarianceR8, pVariances, BOUND_OF_LOOP, addr r8VarOfVars

          fld r8AccVariance
          fidiv dBoundOfLoop
          fstp r8MeanVar

          m2m SlrData.pData, pMinValues, xax
          mov SlrData.xCount, BOUND_OF_LOOP
          invoke SLR_Init, addr SlrData
          invoke SLR_Calc_AB_MSE_QW, addr SlrData
          m2m r8Measure, SlrData.r8Slope, xax
          m2m r8Overhead, SlrData.r8Intercept, xcx
          m2m r8MinsMSE, SlrData.r8MSE, xax

          invoke CalcVarianceQW, pMinValues, BOUND_OF_LOOP, addr r8VarMins
          fld1
          fld SlrData.r8MSE
          fdiv r8VarMins
          fsubp st(1), st(0)
          fstp r8R2

          ALIGN_1 = 14
          ALIGN_2 = 26
          ALIGN_3 = 38
          DbgWriteF ,, "Spurious = ¦AT¦UQ ¦AT[-]¦ATNumber of Spurious min. Values", ALIGN_1, qSpurious, ALIGN_2, ALIGN_3
          DbgWriteF ,, "MaxMaxDiff = ¦AT¦UQ ¦AT[Tick]¦ATMax. Spread of the Values", ALIGN_1, qMaxMaxDiff, ALIGN_2, ALIGN_3
          DbgWriteF ,, "MeanVar = ¦AT¦E3 ¦AT[Tick^2]¦ATMean Variance", ALIGN_1, r8MeanVar, ALIGN_2, ALIGN_3
          DbgWriteF ,, "VarOfVars = ¦AT¦E3 ¦AT[Tick^4]¦ATVariance of Variances", ALIGN_1, r8VarOfVars, ALIGN_2, ALIGN_3
          DbgWriteF ,, "MinsMSE = ¦AT¦E3 ¦AT[Tick^2]¦ATLinear Regression MSE", ALIGN_1,  r8MinsMSE, ALIGN_2, ALIGN_3
          DbgWriteF ,, "R² = ¦AT¦E3 ¦AT[-]¦ATDetermination Coefficient", ALIGN_1,  r8R2, ALIGN_2, ALIGN_3
          DbgWriteF ,, "Overhead = ¦AT¦F1 ¦AT[Tick]¦ATMeasurement Overhead", ALIGN_1,  r8Overhead, ALIGN_2, ALIGN_3
          DbgWriteF DbgColorBlue,, "Measure = ¦AT¦F1 ¦AT[Tick]¦ATCode Execution Time", ALIGN_1,  r8Measure, ALIGN_2, ALIGN_3
          DbgLine

;          mov rbx, BOUND_OF_LOOP
;          mov rdi, pMinValues
;          .repeat
;            DbgDec QWORD ptr [rdi]
;            add rdi, sizeof(QWORD)
;            dec rbx
;          .until ZERO?

          ;Release allocated memory
          mov rbx, BOUND_OF_LOOP
          mov rdi, pTimes
          .repeat
            MemFree POINTER ptr [rdi]
            add rdi, sizeof(POINTER)
            dec rbx
          .until ZERO?

          MemFree pMinValues
          MemFree pVariances
          MemFree pTimes
          mov rax, 0
        .endif
      .endif
    .endif
  .endif
  ret
Benchmark endp

