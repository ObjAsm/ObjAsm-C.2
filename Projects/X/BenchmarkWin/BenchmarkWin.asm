; ==================================================================================================
; Title:      BenchmarkWin.asm
; Author:     G. Friedrich
; Version:    C.2.1
; Purpose:    ObjAsm compilation file for benchmarking code execution times on Windows,
;             using the Paoloni method.
; Notes:      Version C.2.0, January 2023
;               - Initial release (G. Friedrich & Héctor S. Enrique).
;             Version C.2.1, May 2026
;               - See PaoloniWin.inc
; ==================================================================================================


% include @Environ(OBJASM_PATH)\Code\Macros\Model.inc   ; Include & initialize standard modules
SysSetup OOP, WIN64, ANSI_STRING, DEBUG(WND)            ; Load OOP files and basic OS support
% include &MacPath&fMath.inc

; ==================================================================================================

; Values for performance test
.const
  r8Numerator   REAL8   100000.0
  r8Denominator REAL8   10.0
.data
  r8Result      REAL8   0.0
  FpuEnv        BYTE    108 dup(0)

; ==================================================================================================


SIZE_OF_STAT  equ 10000                     ; Determines the statistical relevance
BOUND_OF_LOOP equ 100                       ; Number of iterations per measurement (must be > 1)

ProcedureUnderGlass0 macro                  ; Lightweight test procedure
  mov xax, 1
endm

ProcedureUnderGlass1 macro                  ; Mediumweight test procedure
  fld  REAL8 ptr [r8Numerator]
  fdiv REAL8 ptr [r8Denominator]
  fdiv REAL8 ptr [r8Denominator]
  fdiv REAL8 ptr [r8Denominator]
  fdiv REAL8 ptr [r8Denominator]
  fstp REAL8 ptr [r8Result]
endm

ProcedureUnderGlass2 macro                  ; Heavyweight test procedure
  fsave FpuEnv
  frstor FpuEnv
endm

ProcedureUnderGlass macro
  ProcedureUnderGlass1                      ; Select here the procedure you want tho test
endm

include PaoloniWin.inc


; --------------------------------------------------------------------------------------------------
; Procedure:  start
; Purpose:    Entry point.
; Arguments:  None.
; Return:     Nothing.
start proc
  SysInit                                   ; Runtime model initialization
  invoke Benchmark                          ; Run the full measurement
  .if eax != FALSE                          ; If measurement succeeded
    invoke ShowStats                        ; Print the full report to DebugCenter
  .endif
  SysDone                                   ; Runtime model shutdown
  ret
start endp
end start