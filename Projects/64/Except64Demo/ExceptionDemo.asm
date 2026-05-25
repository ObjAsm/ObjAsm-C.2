; ==================================================================================================
; Title:      ExceptionDemo.asm
; Author:     G. Friedrich, October 2017
; Version:    C.1.0
; Purpose:    ObjAsm 64-bit exception handling demonstration.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\Code\Macros\Model.inc   ;Include & initialize standard modules
SysSetup OOP, NUI64, ANSI_STRING, DEBUG(WND)            ;Load OOP files and basic OS supporting files

;64-BIT
;uasm -c -Zp8 -win64
;link /SUBSYSTEM:console /ENTRY:start /MACHINE:X64

.code
% include &MacPath&Exception64.inc
% include &MacPath&SIMD_Math.inc

.code

;TEST CASES
;Case 1: Exception in procedure with FRAME with exception handler.
proc1 proc FRAME:EHandler uses rbx rdi rsi
  .try
    ;Enter some values to confirm they will not change with the exception.
    mov rbx, 33h
    mov rsi, 44h
    mov rdi, 55h
    mov rax, 0        ;Causes an Access Violation.
    mov rax, [rax]
  .catch
    DbgWarning "Exception in proc1"
    DbgHex QWORD ptr [rax]
    DbgHex ExceptRecord.ExceptionCode
    DbgHex ExceptRecord.ExceptionAddress
    DbgHex OriginalExceptContext.Rbx_
    DbgHex OriginalExceptContext.Rsi_
    DbgHex OriginalExceptContext.Rdi_
  .endcatch
  .finally
    DbgLine2
    ret
  .endfinally
proc1 endp

;Case 2 - Exception in a procedure with FRAME but without exception handler,
;called by a procedure with a FRAME and exception handler.
proc2_1 PROC uses rsi xmm15
  mov rsi, 33h        ;Change rsi to confirm it will be restored in the caller.
  movaps xmm15, XMMWORD ptr Real8ToXmm(1.0, -1.0) ;Change xmm15 as well.
  mov rcx, 0          ;cause divide by zero exception
  div rcx
  movaps xmm15, [rbp-10h]
  ret
proc2_1 endp

proc2_0 PROC FRAME:EHandler uses rsi xmm15
  .try
    mov rsi, 10h      ;It will change in the callee.
    movaps xmm15, XMMWORD ptr Real8ToXmm(50.0, 60.0) ;It in the callee will change as well.
    sub rsp, 20h
    call proc2_1
    add rsp, 20h
  .catch
    DbgWarning "Exception in proc2_0"
    DbgHex QWORD ptr [rax]
    DbgHex ExceptRecord.ExceptionCode
    DbgHex ExceptRecord.ExceptionAddress
    DbgHex ExceptContext.Rsi_
    DbgHex OriginalExceptContext.Rsi_
    DbgHex rsi
;    DbgFloat ExceptContext.Xmm15_.Low_
;    DbgFloat ExceptContext.Xmm15_.High_
;    DbgFloat OriginalExceptContext.Xmm15_.Low_
;    DbgFloat OriginalExceptContext.Xmm15_.High_
  .endcatch
  .finally
    DbgLine2
    ret
  .endfinally
proc2_0 endp

;Case 3 - Similar to Case 2, but when RSP is the frame pointer.
proc3_1 PROC uses rdi rsi
  mov rsi, 11h        ;Change rsi to confirm it will be restored in the caller.
  mov rdi, 22h        ;Change rdi as well.
  mov rax, 0          ;Cause an Access Violation.
  mov rax, [rax]
  ret
proc3_1 endp

proc3_0 PROC FRAME:EHandler uses rdi rsi
  ;When the frame pointer is RSP, it must be static throughtout the procedure
  ;So, we allocate here space for the shadow space of the function calls
  ;and for 2 non-volatile registers we will be using.
  .try
    mov rsi, 15h      ;It will change in the callee.
    mov rdi, 25h      ;In the callee it will change as well.
    call proc3_1
    mov r10, 12
  .catch
    DbgWarning "Exception in proc3_0"
    DbgHex QWORD ptr [rax]
    DbgHex ExceptRecord.ExceptionCode
    DbgHex ExceptRecord.ExceptionAddress
    DbgHex ExceptContext.Rdi_
    DbgHex OriginalExceptContext.Rdi_
    DbgHex rdi
    DbgHex ExceptContext.Rsi_
    DbgHex OriginalExceptContext.Rsi_
    DbgHex rsi
  .endcatch
  .finally
    DbgLine2
    ret
  .endfinally
proc3_0 endp

;Case 4 - Nested exceptions.
proc4 PROC FRAME:EHandler
  .try
    .try
      .try
        db 0FFh       ;A third nested exception (Invalid Opcode).
        db 0FFh
      .catch
        DbgWarning "Exception in proc4 (A)"
        DbgHex QWORD ptr [rax]
        DbgHex ExceptRecord.ExceptionCode
        DbgHex ExceptRecord.ExceptionAddress
      .endcatch
      .finally
        DbgLine2
        int 3         ;Breakpoint exception (It will pause execution under a debugger).
      .endfinally
    .catch
      DbgWarning "Exception in proc4 (B)"
      DbgHex QWORD ptr [rax]
      DbgHex ExceptRecord.ExceptionCode
      DbgHex ExceptRecord.ExceptionAddress
    .endcatch
    .finally
      DbgLine2
      ;Raise a continuable exception.
      invoke RaiseException, 0FFh, 0, 0, 0
    .endfinally
  .catch
    DbgWarning "Exception in proc4 (C)"
    DbgHex QWORD ptr [rax]
    DbgHex ExceptRecord.ExceptionCode
    DbgHex ExceptRecord.ExceptionAddress
  .endcatch
  .finally
    DbgLine2
    ret
  .endfinally
proc4 endp

;Case 5 - Multiple (non-nested) exceptions in the same procedure
proc5 PROC FRAME:EHandler
  .try
    ;Make stack unaligned for a vector instruction.
    ;We can modify the stack because we have a frame pointer.
    sub rsp, 18h
    movaps xmm0, XMMWORD ptr [rsp]
  .catch
    DbgWarning "Exception in proc5 (A)"
    DbgHex QWORD ptr [rax]
    DbgHex ExceptRecord.ExceptionCode
    DbgHex ExceptRecord.ExceptionAddress
  .endcatch
  .finally
    DbgLine2
  .endfinally

  .try
    hlt               ;cause another exception
  .catch
    DbgWarning "Exception in proc5 (B)"
    DbgHex QWORD ptr [rax]
    DbgHex ExceptRecord.ExceptionCode
    DbgHex ExceptRecord.ExceptionAddress
  .endcatch
  .finally
    DbgLine2
    ret
  .endfinally
proc5 endp

;Case 6 - Exception in a leaf procedure, there is no Catch Block in caller,
;the exception will be passed to caller's parent, which in this case
;is start and the program will terminate normally.
proc6_1 PROC
  hlt                 ;Prileged instruction.
  ret
proc6_1 endp

proc6_0 PROC FRAME:EHandler
  call proc6_1
  ret
proc6_0 endp


start proc FRAME:EHandler
  SysInit
  DbgClearTxt
  .try
    ;Case 1 - Exception in procedure with FRAME with exception handler.
    call proc1

    ;Case 2 - Exception in procedure with FRAME but without exception handler,
    ;called by a procedure with a FRAME and exception handler.
    call proc2_0

    ;Case 3 - Similar to Case 2, but when RSP is the frame pointer.
    call proc3_0

    ;Case 4 - Nested exceptions.
    call proc4

    ;Case 5 - Multiple (non-nested) exceptions in the same procedure.
    call proc5

    ;Case 6- Exception in Leaf procedure, no Catch Block in caller,
    ;the exception will be passed to caller's parent.
    call proc6_0

  .catch
    DbgWarning "Exception in main"
    DbgHex ExceptRecord.ExceptionCode
    DbgHex ExceptRecord.ExceptionAddress
  .endcatch

  .finally
    DbgLine2
    DbgText "READY"
    SysDone
    invoke ExitProcess, 0
    ret
  .endfinally
start endp

end start                                           ;End of code and define the program entry point
