; ==================================================================================================
; Title:      GetExceptionStrW.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMemWin.cop

% include &MacPath&Strings.inc

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  GetExceptionStrW
; Purpose:    Translate an exception code to a WIDE string.
; Arguments:  Arg1: Exception code.
; Return:     rax -> WIDE string.

OPTION PROC:NONE

.code
align ALIGN_CODE
GetExceptionStrW proc dExceptionCode:DWORD
  cmp ecx, 0C0000005h                                   ;EXCEPTION_ACCESS_VIOLATION
  jne @F
  mov rax, $OfsCStrW("EXCEPTION_ACCESS_VIOLATION")
  ret
@@:
  cmp ecx, 0C000008Ch                                   ;EXCEPTION_ARRAY_BOUNDS_EXCEEDED
  jne @F
  mov rax, $OfsCStrW("EXCEPTION_ARRAY_BOUNDS_EXCEEDED")
  ret
@@:
  cmp ecx, 080000003h                                   ;EXCEPTION_BREAKPOINT
  jne @F
  mov rax, $OfsCStrW("EXCEPTION_BREAKPOINT")
  ret
@@:
  cmp ecx, 080000002h                                   ;EXCEPTION_DATATYPE_MISALIGNMENT
  jne @F
  mov rax, $OfsCStrW("EXCEPTION_DATATYPE_MISALIGNMENT")
  ret
@@:
  cmp ecx, 0C000008Dh                                   ;EXCEPTION_FLT_DENORMAL_OPERAND
  jne @F
  mov rax, $OfsCStrW("EXCEPTION_FLT_DENORMAL_OPERAND")
  ret
@@:
  cmp ecx, 0C000008Eh                                   ;EXCEPTION_FLT_DIVIDE_BY_ZERO
  jne @F
  mov rax, $OfsCStrW("EXCEPTION_FLT_DIVIDE_BY_ZERO")
  ret
@@:
  cmp ecx, 0C000008Fh                                   ;EXCEPTION_FLT_INEXACT_RESULT
  jne @F
  mov rax, $OfsCStrW("EXCEPTION_FLT_INEXACT_RESULT")
  ret
@@:
  cmp ecx, 0C0000090h                                   ;EXCEPTION_FLT_INVALID_OPERATION
  jne @F
  mov rax, $OfsCStrW("EXCEPTION_FLT_INVALID_OPERATION")
  ret
@@:
  cmp ecx, 0C0000091h                                   ;EXCEPTION_FLT_OVERFLOW
  jne @F
  mov rax, $OfsCStrW("EXCEPTION_FLT_OVERFLOW")
  ret
@@:
  cmp ecx, 0C0000092h                                   ;EXCEPTION_FLT_STACK_CHECK
  jne @F
  mov rax, $OfsCStrW("EXCEPTION_FLT_STACK_CHECK")
  ret
@@:
  cmp ecx, 0C0000093h                                   ;EXCEPTION_FLT_UNDERFLOW
  jne @F
  mov rax, $OfsCStrW("EXCEPTION_FLT_UNDERFLOW")
  ret
@@:
  cmp ecx, 0C000001Dh                                   ;EXCEPTION_ILLEGAL_INSTRUCTION
  jne @F
  mov rax, $OfsCStrW("EXCEPTION_ILLEGAL_INSTRUCTION")
  ret
@@:
  cmp ecx, 0C0000006h                                   ;EXCEPTION_IN_PAGE_ERROR
  jne @F
  mov rax, $OfsCStrW("EXCEPTION_IN_PAGE_ERROR")
  ret
@@:
  cmp ecx, 0C0000094h                                   ;EXCEPTION_INT_DIVIDE_BY_ZERO
  jne @F
  mov rax, $OfsCStrW("EXCEPTION_INT_DIVIDE_BY_ZERO")
  ret
@@:
  cmp ecx, 0C0000095h                                   ;EXCEPTION_INT_OVERFLOW
  jne @F
  mov rax, $OfsCStrW("EXCEPTION_INT_OVERFLOW")
  ret
@@:
  cmp ecx, 080000004h                                   ;EXCEPTION_SINGLE_STEP
  jne @F
  mov rax, $OfsCStrW("EXCEPTION_SINGLE_STEP")
  ret
@@:
  mov rax, $OfsCStrW("UNKNOWN_EXCEPTION")
  ret
GetExceptionStrW endp

OPTION PROC:DEFAULT

end
