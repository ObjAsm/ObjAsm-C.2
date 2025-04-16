; ==================================================================================================
; Title:      Exception32.inc
; Author:     G. Friedrich
; Version:    C.1.1
; Purpose:    ObjAsm 32 bit Exception Handling.
; Notes:      Version C.1.1, March 2021
;               - .endc replaced by .endcatch and .endfy by .endfinally (HSE)
;             Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


; ==================================================================================================
;    Macro definitions
; ==================================================================================================

XFRAME struc                     ;Exception frame
  pNextxFrame     DWORD    ?
  pHandler        DWORD    ?
  pSafePlace      DWORD    ?
  pInformation    DWORD    ?
  flags           DWORD    ?
  SafeEbp         DWORD    ?
XFRAME ends
PXFRAME typedef ptr XFRAME

CONTEXT_NORMAL    equ     CONTEXT_CONTROL or CONTEXT_INTEGER or CONTEXT_SEGMENTS
CONTEXT_ALL       equ     CONTEXT_CONTROL or CONTEXT_INTEGER or CONTEXT_SEGMENTS or \
                          CONTEXT_FLOATING_POINT or CONTEXT_DEBUG_REGISTERS
UNWIND_STACK      equ     000000002H

CStr szSehTitleErr,    "Fatal Error"
CStr szSehUnknownErr,  "An unknown error has occured !"
CStr szSehMemFatalErr, "Memory access violation !", 13, 10, "The program will end now."
CStr szSehNoMsg,       "No message"


;Usual used exceptions:

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

; --------------------------------------------------------------------------------------------------
; Macro:      .try
; Purpose:    Instructions between this .try and the next .Catch or Finally will be protected.
; Arguments:  Arg1: Name of the XFRAME which will deal with exceptions.
;             Arg2: Flags for the exception handler.
;             Arg3: -> some informations for the exception handler.

.try macro ExceptionHandlerName:req, Flags:=<0>, pInformation:=<NULL>
  pushcontext assumes
  assume fs:NOTHING
  push ebp                                              ;Create XFRAME on stack
  push &Flags
  push &pInformation
  push offset @@&ExceptionHandlerName&_SafePlace
  push offset &ExceptionHandlerName&_Handler
  push fs:[0]
  mov fs:[0], esp
  popcontext assumes
endm

; --------------------------------------------------------------------------------------------------
; Macro:      .catch
; Purpose:    The following instructions will be executed if an exception is raised.
; Arguments:  Arg1: Name of the Exception Handler which will deal with the exceptions.
;             Arg2: (optional) Name of the exception record that will be filled on an exception.
; Note:       If we reach this place, some register are filled with the following content:
;             eax -> EXCEPTION_RECORD.
;             ecx = Exception code.
;             edx = pInformation passed to the .try macro.

.catch macro ExceptionHandlerName:req, ExceptionRecordName
  jmp @@&ExceptionHandlerName&_NoErr

@@&ExceptionHandlerName&_SafePlace:
  ifnb <ExceptionRecordName>
    pushcontext assumes
    assume eax:EXCEPTION_RECORD
    assume edx:EXCEPTION_RECORD
    push edx
    push ecx
    lea edx, ExceptionRecordName
    m2m [edx].ExceptionCode,        [eax].ExceptionCode,        ecx
    m2m [edx].ExceptionFlags,       [eax].ExceptionFlags,       ecx
    m2m [edx].pExceptionRecord,     [eax].pExceptionRecord,     ecx
    m2m [edx].ExceptionAddress,     [eax].ExceptionAddress,     ecx
    m2m [edx].NumberParameters,     [eax].NumberParameters,     ecx
    m2m [edx].ExceptionInformation, [eax].ExceptionInformation, ecx
    pop ecx
    pop edx
    popcontext assumes
  endif
endm

; --------------------------------------------------------------------------------------------------
; Macro:      .endcatch
; Purpose:    Follow immediately instructions guarded by a .catch.
; Arguments:  Name of the handler which will deal with exceptions.

.endcatch macro ExceptionHandlerName:req

@@&ExceptionHandlerName&_NoErr:
  pushcontext assumes
  assume fs:NOTHING
  pop fs:0
  add esp, sizeof(XFRAME) - 4
  popcontext assumes
endm

; --------------------------------------------------------------------------------------------------
; Macro:      .finally
; Purpose:    Following instructions will run even if an exception which can be handled
;             by the exception handler is raised.
; Arguments:  Name of the handler which will deal with exceptions.
; Note:       If we reach this place, some register are filled with the following content:
;             eax -> EXCEPTION_RECORD or NULL if no exception was raised.
;             ecx = Exception code or unchanged if no exception was raised.
;             edx = pInformation passed to the .try macro or unchanged if no exception was raised.

.finally macro ExceptionHandlerName:req
  xor eax, eax
@@&ExceptionHandlerName&_SafePlace:
endm

; --------------------------------------------------------------------------------------------------
; Macro:      .endfinally
; Purpose:    Follow immediately instructions guarded by a .finally.

.endfinally macro
  pushcontext assumes
  assume fs:NOTHING
  pop fs:0
  add esp, sizeof(XFRAME) - 4
  popcontext assumes
endm

; --------------------------------------------------------------------------------------------------
; Macro:      xMsg
; Purpose:    Allow to define a message for an exception.
; Arguments:  Arg1: Name of the handler which will deal with exceptions.
;             Arg2: Message associated with the exception.

xMsg macro MsgName:req, Text:req
  ??Count = -2
  ??ParamCount = 0
  ??Complement = 0

  forc letter, <&Text>
    ??Count = ??Count + 1

    if ??Count eq 4
      ??Count = 0
      ??ParamCount = ??ParamCount + 1
    endif
  endm

  while ??Count lt 4
    ??Complement = ??Complement + 1
    ??Count = ??Count + 1
  endm

  ??ParamCount = ??ParamCount + 1

  .data
  MsgName BYTE Text

  ??Count = 0
  while ??Count lt ??Complement
    ??Count = ??Count + 1
    BYTE 0
  endm

  &MsgName&_nb DWORD ??ParamCount
  .code
endm

; --------------------------------------------------------------------------------------------------
; Macro:      Throw
; Purpose:    Raise an exception.
; Arguments:  Arg1: Code of the exception to raise.
;             Arg2: Name of a xMsg.
; Notes:      If Msg is blank the exception is raised with the message szSehNoMsg in order to
;             allowing the Top Level to know if the user provided a message or not.

Throw macro ExceptionCode:req, msg
  ifnb <msg>
    invoke RaiseException, ExceptionCode, 0, &msg&_nb , offset msg
  else
    invoke RaiseException, ExceptionCode, 0, 2, offset szSehNoMsg
  endif
endm

; --------------------------------------------------------------------------------------------------
; Macro:      InstallTLH
; Purpose:    Install a Top Level Handler.
; Arguments:  Arg1: -> Top Level handler to install.
;             Arg2: Var which will hold the pointer to the old handler.

InstallTLH macro pTLHandler:req, OldTLHandler:req
  invoke SetUnhandledExceptionFilter, pTLHandler
  ifdifi &OldTLHandler, <eax>
    mov OldTLHandler, eax
  endif
endm

; --------------------------------------------------------------------------------------------------
; Macro:      RestoreTLH
; Purpose:    Reinstall the old top level handler.
; Arguments:  var holding the pointer to the old handler.

RestoreTLH macro OldTLHandler:req
  invoke SetUnhandledExceptionFilter, OldTLHandler
endm

; --------------------------------------------------------------------------------------------------
; Macro:      $GetExceptionCode
; Purpose:    Retrieve the Exception Code.
; Arguments:  None.

$GetExceptionCode macro
  exitm <[eax].EXCEPTION_RECORD.ExceptionCode>
endm

; --------------------------------------------------------------------------------------------------
; Macro:      $GetExceptionAddr
; Purpose:    Retrieve the Exception address.
; Arguments:  None.

$GetExceptionAddr macro
  exitm <[eax].EXCEPTION_RECORD.ExceptionAddress>
endm

; --------------------------------------------------------------------------------------------------
; Macro:      CreateExceptionHandler
; Purpose:    Create a handler which can deal with one or more exceptions.
; Arguments:  Arg1: Name of the handler to be created.
;             Arg2: Address of Unwind code.
;             Arg3: List of exceptions codes to deal with.
; Notes:      The error handler MUST be declared as a C procedure for proper stack cleanup!

CreateExceptionHandler macro HandlerName:req, UnwindCodeLabel:=<>, xCodes:vararg
  local @@NoUnwind, @@TakeCareOfIt, @@UnWindReturn, @@ToNext, @@Exit

  ifnb <UnwindCodeLabel>
    &UnwindCodeLabel proto :DWORD                       ;;Pass SafeEbp for local access to vars
  endif

  &HandlerName&_Handler proc c uses ebx esi edi pxRecord:POINTER, pxFrame:PXFRAME, pContext:POINTER
    mov ebx, pxRecord                                   ;;Get exception record
    mov eax, [ebx].EXCEPTION_RECORD.ExceptionFlags      ;;Get exception flags

    test eax, EXCEPTION_NONCONTINUABLE
    jnz @@ToNext

    test eax, UNWIND_STACK
    jz @@NoUnwind

    ;;Free local resources & stack here (if necessary)!
    ifnb <UnwindCodeLabel>
      mov edx, pxFrame
      push [edx].XFRAME.SafeEbp
      call UnwindCodeLabel
    endif

    jmp @@ToNext

  @@NoUnwind:
    ifnb <xCodes>
      mov eax, [ebx].EXCEPTION_RECORD.ExceptionCode     ;;Get exception code
      ;;Take care of own exceptions
      for Arg, <xCodes>
        cmp eax, Arg
        je @@TakeCareOfIt
      endm
      ;;Exception is not caught here
      jmp @@ToNext
    endif

  @@TakeCareOfIt:
    ;;Unwind to allow other handlers to free the stack
    push NULL
    push pxRecord
    push offset @@UnWindReturn
    push pxFrame
    call RtlUnwind                                      ;;RtlUnwind may destroy ebx, edi or esi!

  @@UnWindReturn:
    ;;Change the context to continue execution of the program
    mov esi, pContext
    mov edx, pxFrame
    mov [esi].CONTEXT.Esp_, edx
    m2m [esi].CONTEXT.Eip_, [edx].XFRAME.pSafePlace
    m2m [esi].CONTEXT.Edx_, [edx].XFRAME.pInformation
    m2m [esi].CONTEXT.Ebp_, [edx].XFRAME.SafeEbp
    mov eax, pxRecord
    m2m [esi].CONTEXT.Ecx_, [eax].EXCEPTION_RECORD.ExceptionCode
    mov [esi].CONTEXT.Eax_, eax                         ;;eax -> Exception record

    ;;Save all information on entry in the save place
    ;;since some infos are stored on the stack

    xor eax, eax                                        ;;ExceptionContinueExecution
    jmp @@Exit

  @@ToNext:
    xor eax, eax
    inc eax                                             ;;ExceptionContinueSearch

  @@Exit:
    ret

  &HandlerName&_Handler endp
endm

; --------------------------------------------------------------------------------------------------
; Macro:      TopLevelHandler
; Purpose:    Create a top level handler to deal with exceptions not catched.
; Arguments:  Arg1: Name of the top level handler to be created.

TopLevelHandler macro THLName
  THLName proc uses esi PxPointers
    mov eax, PxPointers
    mov ebx, [eax].EXCEPTION_POINTERS.pExceptionRecord
    mov edx, [eax].EXCEPTION_POINTERS.ContextRecord

    mov eax, [ebx].EXCEPTION_RECORD.ExceptionCode

    ;If it's a memory access violation exception
    .if eax == EXCEPTION_ACCESS_VIOLATION
      invoke MessageBox, 0, offset szSehMemFatalErr, offset szSehTitleErr, MB_OK or MB_ICONERROR
      xor eax, eax
      inc eax                                           ;EXCEPTION_CONTINUE_SEARCH
    .else
      mov [edx].CONTEXT.ContextFlags, CONTEXT_NORMAL

      ;Test if a message was provided (it must be a string)
      lea eax, [ebx].EXCEPTION_RECORD.ExceptionInformation
      lea edx, szSehNoMsg
      mov edx, [edx]
      .if [eax] == edx
        lea eax, szSehUnknownErr
      .endif

      invoke MessageBox, 0, eax, offset szSehTitleErr, MB_OK or MB_ICONERROR
      xor eax, eax                                      ;EXCEPTION_CONTINUE_EXECUTION
    .endif
    ret
  THLName endp
endm
