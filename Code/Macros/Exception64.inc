; ==================================================================================================
; Title:      Exception64.inc
; Author:     G. Friedrich
; Version:    C.1.1
; Purpose:    ObjAsm 64 bit Exception Handling. See ...Code\ObjMem\64\EHandler.asm
; Notes:      Version C.1.1, March 2021
;               - .endc replaced by .endcatch and .endfy by .endfinally (HSE)
; Notes:      Version 1.0.0, October 2017
;               - First release.
; ==================================================================================================


externdef OriginalExceptContext:CONTEXT
externdef ExceptContext:CONTEXT
externdef ExceptRecord:EXCEPTION_RECORD
externdef LSH_RetValue:QWORD

externdef ExcepDataStart:near


;Usual exception codes:

EXCEPTION_WAIT_0                    equ    000000000H
EXCEPTION_ABANDONED_WAIT_0          equ    000000080H
EXCEPTION_USER_APC                  equ    0000000C0H
EXCEPTION_TIMEOUT                   equ    000000102H
EXCEPTION_PENDING                   equ    000000103H
EXCEPTION_SEGMENT_NOTIFICATION      equ    040000005H
EXCEPTION_GUARD_PAGE_VIOLATION      equ    080000001H
EXCEPTION_DATATYPE_MISALIGNMENT     equ    080000002H
EXCEPTION_BREAKPOINT                equ    080000003H       ;Exception 3
EXCEPTION_SINGLE_STEP               equ    080000004H       ;Exception 1
EXCEPTION_ACCESS_VIOLATION          equ    0C0000005H       ;Typically exception 13
EXCEPTION_IN_PAGE_ERROR             equ    0C0000006H
EXCEPTION_NO_MEMORY                 equ    0C0000017H
EXCEPTION_ILLEGAL_INSTRUCTION       equ    0C000001DH
EXCEPTION_NONCONTINUABLE_EXCEPTION  equ    0C0000025H
EXCEPTION_INVALID_DISPOSITION       equ    0C0000026H
EXCEPTION_ARRAY_BOUNDS_EXCEEDED     equ    0C000008CH       ;Exception 5
EXCEPTION_FLOAT_DENORMAL_OPERAND    equ    0C000008DH
EXCEPTION_FLOAT_DIVIDE_BY_ZERO      equ    0C000008EH
EXCEPTION_FLOAT_INEXACT_RESULT      equ    0C000008FH
EXCEPTION_FLOAT_INVALID_OPERATION   equ    0C0000090H
EXCEPTION_FLOAT_OVERFLOW            equ    0C0000091H
EXCEPTION_FLOAT_STACK_CHECK         equ    0C0000092H
EXCEPTION_FLOAT_UNDERFLOW           equ    0C0000093H
EXCEPTION_INTEGER_DIVIDE_BY_ZERO    equ    0C0000094H       ;Exception 0
EXCEPTION_INTEGER_OVERFLOW          equ    0C0000095H       ;Exception 4
EXCEPTION_PRIVILEGED_INSTRUCTION    equ    0C0000096H       ;Typically exception 13
EXCEPTION_STACK_OVERFLOW            equ    0C00000FDH
EXCEPTION_CONTROL_C_EXIT            equ    0C000013AH


EXCEPDATA_END_MARKER                equ     <-1>

TRY_INFO struc
  TryBeg    QWORD ?
  TryEnd    QWORD ?
TRY_INFO ends

SEG_EXCEP_DATA segment para ".data"
  ExcepDataStart  label near
                  QWORD EXCEPDATA_END_MARKER    ;End of all TRY_INFO structures marker
  org $ - sizeof(QWORD)                         ;Overwrite, if there are more TRY_INFO structures
SEG_EXCEP_DATA ends


; ==================================================================================================
;    Macro definitions
; ==================================================================================================

??ExceptNesting = 0
??ExceptCounter = 0
??ExceptDecl = FALSE

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      .try
; Purpose:    Initialize a protected area.
; Arguments:  None.
; Return:     Nothing.

.try macro
  .code                                                 ;;Required to generate correct addresses
  @CatStr(<??TryBeg_>, %??ExceptNesting) = $
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      .catch
; Purpose:    Finalizes a protected area. The following code is executed in case of an exception.
; Arguments:  None.
; Return:     Nothing.
; Note:       This macro can be ommited.

.catch macro
  .code                                                 ;;Required to generate correct addresses
  ??ExceptDecl = TRUE                                   ;;.catch was not omitted
  ??ExceptCounter = ??ExceptCounter + 1                 ;;Incremental number for unique labeling
  %jmp @CatStr(<??Finally_>, %??ExceptCounter)
  @CatStr(<??TryEnd_>, %??ExceptNesting) = $
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      .endcatch
; Purpose:    32 bit compatibility macro.
; Arguments:  None.
; Return:     Nothing.
; Note:       This macro can be ommited.

.endcatch macro
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      .finally
; Purpose:    The following code is always executed.
; Arguments:  None.
; Return:     Nothing.
; Note:       This macro must always be present!

.finally macro
  .code                                                 ;;Required to generate correct addresses
  if ??ExceptDecl eq TRUE
    @CatStr(<??Finally_>, %??ExceptCounter):            ;;Define jump label
    ??ExceptDecl = FALSE                                ;;Reset flag
  else
    @CatStr(<??TryEnd_>, %??ExceptNesting) = $
  endif

  SEG_EXCEP_DATA segment
    POINTER @CatStr(<??TryBeg_>, %??ExceptNesting)
    POINTER @CatStr(<??TryEnd_>, %??ExceptNesting)

    QWORD EXCEPDATA_END_MARKER
    org $ - sizeof(QWORD)                               ;;Overwrite, if more TRY_INFO structs come
  SEG_EXCEP_DATA ends
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      .finally
; Purpose:    32 bit compatibility macro.
; Arguments:  None.
; Return:     Nothing.
; Note:       This macro can be ommited.

.endfinally macro
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      CreateExceptionHandler
; Purpose:    Dummy for compatibility with 64 bit.
; Arguments:  Arg1: Name of the handler to be created.
;             Arg2: Address of Unwind code.
;             Arg3: List of exceptions codes to deal with.

CreateExceptionHandler macro HandlerName:req, UnwindCodeLabel:=<>, xCodes:vararg
endm