; ==================================================================================================
; Title:      Paoloni2010.inc
; Author:     Héctor S. Enrique
; Version:    1.0.0
; Purpose:    Include file for UEFI Benchmark Application.
; Version:    Version 1.0.0, May 2022
;             - First release.
;
; Note:       Gabriele Paoloni, 2010. How to Benchmark Code Execution Times on Intel IA-32 and IA-64
;             Instruction Set Architectures. Retrieved May 26, 2022, from
;             http://www.intel.com/content/dam/www/public/us/en/documents/white-papers/ia-32-ia-64-benchmark-code-execution-paper.pdf
;
; ==================================================================================================


.code
; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  Benchmark
; Purpose:    Perform the Paolini benchmark.
; Arguments:  None.
; Return:     rax = UEFI error code.

Benchmark proc uses rbx rdi rsi
  local pTimes:POINTER, pVariances:POINTER, r8Variance:REAL8, qSpurious:QWORD, pMinValues:POINTER
  local qMaxDiff:QWORD, qMaxTime:QWORD, qMinTime:QWORD, qPrevMinTime:QWORD
  local r8AccVariance:REAL8, qMaxMaxDiff:QWORD, r8VarOfVars:REAL8, r8MinsMSE:REAL8, r8VarTotal:REAL8
  local r8Measure:REAL8, r8Overhead:REAL8
  local SlrData:SLR_DATA

  mov rsi, pBootServices
  invoke [rsi].EFI_BOOT_SERVICES.AllocatePool, EFI_MEMORY_UC, BOUND_OF_LOOP*sizeof(REAL8), addr pVariances
  .if pVariances == NULL
    PrintC "%EUnable to allocate memory for Variances"
    mov rax, EFI_ABORTED
  .else
    invoke [rsi].EFI_BOOT_SERVICES.AllocatePool, EFI_MEMORY_UC, BOUND_OF_LOOP*sizeof(QWORD), addr pMinValues
    .if pMinValues == NULL
      PrintC "%EUnable to allocate memory for MinValues"
      invoke [rsi].EFI_BOOT_SERVICES.FreePool, pVariances
    .else
      invoke [rsi].EFI_BOOT_SERVICES.AllocatePool, EFI_MEMORY_UC, BOUND_OF_LOOP*sizeof(POINTER), addr pTimes
      .if pTimes == NULL
        PrintC "%EUnable to allocate memory for Times"
        invoke [rsi].EFI_BOOT_SERVICES.FreePool, pMinValues
        invoke [rsi].EFI_BOOT_SERVICES.FreePool, pVariances
        mov rax, EFI_ABORTED
      .else
        xor ebx, ebx
        .while rbx < BOUND_OF_LOOP
          mov rax, pTimes
          invoke [rsi].EFI_BOOT_SERVICES.AllocatePool, EFI_MEMORY_UC, SIZE_OF_STAT*sizeof(REAL8), addr [rax + sizeof(POINTER)*rbx]
          .break .if rax != EFI_SUCCESS
          inc rbx
        .endw
        .if rbx != BOUND_OF_LOOP
          PrintC "%EUnable to allocate memory for Time[%d]", rbx
          .while rbx != 0
            dec rbx
            mov rdx, pTimes
            invoke [rsi].EFI_BOOT_SERVICES.FreePool, addr [rdx + sizeof(POINTER)*rbx]
            dec rbx
          .endw
          invoke [rsi].EFI_BOOT_SERVICES.FreePool, pTimes
          invoke [rsi].EFI_BOOT_SERVICES.FreePool, pMinValues
          invoke [rsi].EFI_BOOT_SERVICES.FreePool, pVariances
          mov rax, EFI_ABORTED
        .else
          invoke FillTimes, pTimes

          xor ebx, ebx
          mov qSpurious, rbx
          mov qMaxMaxDiff, rbx
          mov qPrevMinTime, rbx
          mov r8AccVariance, rbx
          .while rbx < BOUND_OF_LOOP
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

            mov rdx, pVariances
            mov rdi, pTimes
            lea rsi, [rdx + sizeof(REAL8)*rbx]
            invoke CalcVarianceQW, POINTER ptr [rdi + sizeof(POINTER)*rbx], SIZE_OF_STAT, rsi
            fld REAL8 ptr [rsi]
            fst r8Variance
            fadd r8AccVariance
            fstp r8AccVariance
;            PrintLn "Loop size: %d; Variance: %f; max. Deviation: %d; min. Time: %d", rbx, r8Variance, qMaxDiff, qMinTime
            inc rbx
          .endw

          invoke CalcVarianceR8, pVariances, BOUND_OF_LOOP, addr r8VarOfVars

          fld r8AccVariance
          fidiv dBoundOfLoop
          fstp r8VarTotal

          m2m SlrData.pData, pMinValues, xax
          mov SlrData.xCount, BOUND_OF_LOOP
          invoke SLR_Init, addr SlrData
          invoke SLR_Calc_AB_MSE_QW, addr SlrData
          m2m r8Measure, SlrData.r8Slope, xax
          fld SlrData.r8Intercept                       ;Since the first data point is at X=1
          fsub r8Measure                                ; we have to correct one position for X=0
          fstp r8Overhead
          m2m r8MinsMSE, SlrData.r8MSE, xax

          PrintLn "Spurious min. values  = %d", qSpurious
          PrintLn "Max. difference       = %d cycles", qMaxMaxDiff
          PrintLn "MSE of min. values    =%f cycles^2", r8MinsMSE
          PrintLn "Total variance        =%f cycles^2", r8VarTotal
          PrintLn "Variance of variances =%f cycles^4", r8VarOfVars
          PrintLn "Overhead              =%f cycles", r8Overhead
          PrintLn "Code Execution Time   =%f cycles", r8Measure

          ;Release allocated memory
          mov rsi, pBootServices
          mov rbx, BOUND_OF_LOOP
          mov rdi, pTimes
          .repeat
            invoke [rsi].EFI_BOOT_SERVICES.FreePool, addr [rdi]
            add rdi, sizeof(POINTER)
            dec rbx
          .until ZERO?

          invoke [rsi].EFI_BOOT_SERVICES.FreePool, pMinValues
          invoke [rsi].EFI_BOOT_SERVICES.FreePool, pVariances
          invoke [rsi].EFI_BOOT_SERVICES.FreePool, pTimes
          mov rax, EFI_SUCCESS
        .endif
      .endif
    .endif
  .endif
  ret
Benchmark endp
