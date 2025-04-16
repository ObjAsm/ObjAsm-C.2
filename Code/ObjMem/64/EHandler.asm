; ==================================================================================================
; Title:      EHandler.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMemWin.cop

externdef OriginalExceptContext:CONTEXT
externdef ExceptContext:CONTEXT
externdef ExceptRecord:EXCEPTION_RECORD
externdef LSH_RetValue:QWORD

externdef ExcepDataStart:near

EXCEPDATA_END_MARKER        equ     <-1>
EXCEPTION_NONCONTINUABLE    equ     01h             ;Noncontinuable exception
EXCEPTION_UNWIND            equ     66h

DISPATCHER_CONTEXT struc
  ControlPc         QWORD ?
  ImageBase         QWORD ?
  FunctionEntry     LPVOID ?
  EstablisherFrame  QWORD ?
  TargetIp          QWORD ?
  ContextRecord     LPVOID ?
  LanguageHandler   LPVOID ?
  HandlerData       LPVOID ?
  HistoryTable      LPVOID ?
  ScopeIndex        DWORD ?
  Fill0             DWORD ?
DISPATCHER_CONTEXT ends
PDISPATCHER_CONTEXT typedef ptr DISPATCHER_CONTEXT

EXCEPTION_RECORD struc
  ExceptionCode     DWORD ?
  ExceptionFlags    DWORD ?
  ExceptionRecord   LPVOID ?
  ExceptionAddress  LPVOID ?
  NumberParameters  DWORD ?
  ExceptionInformation QWORD EXCEPTION_MAXIMUM_PARAMETERS dup (?)
EXCEPTION_RECORD ends

TRY_INFO struc
  TryBeg    QWORD ?
  TryEnd    QWORD ?
TRY_INFO ends

.data
;The following data is not thread safe!
align 16
OriginalExceptContext CONTEXT <>
ExceptContext         CONTEXT <>
ExceptRecord          EXCEPTION_RECORD <>
LSH_RetValue          QWORD ?                   ;Language Specific Handler, return value


; --------------------------------------------------------------------------------------------------
; Procedure:  EHandler
; Purpose:    ASM exception handler
; Arguments:  Arg1: -> Exception Record.
;             Arg2: -> Establisher Frame.
;             Arg3: -> ContextRecord
;             Arg4: -> DispatcherContext
; Link:       https://docs.microsoft.com/en-us/cpp/build/language-specific-handler
;             http://www.nynaeve.net/?p=113
; Return:     rax = ExceptionContinueSearch.

.code
align ALIGN_CODE
EHandler proc uses rsi rdi pExceptionRecord:POINTER, pEstablisherFrame:POINTER, \
                           pContextRecord:POINTER, pDispatcherContext:POINTER
  local ImgBase:POINTER, TargetGp:POINTER

  ;Copy Contexts as they unwind. This serves for reporting purposes.
  cld                               ;Just in case
  mov rdi, offset OriginalExceptContext
  mov rax, pDispatcherContext
  mov rsi, [rax].DISPATCHER_CONTEXT.ContextRecord
  mov rcx, sizeof(CONTEXT)/sizeof(QWORD)
  rep movsq

  mov rcx, pExceptionRecord
  .ifBitSet [rcx].EXCEPTION_RECORD.ExceptionFlags, EXCEPTION_NONCONTINUABLE
    invoke ExitProcess, -1
  .endif

  .ifBitClr [rcx].EXCEPTION_RECORD.ExceptionFlags, EXCEPTION_UNWIND
    ;On 1st pass of each exception, save passed data structures for further exception reporting
    mov rsi, pExceptionRecord
    mov rdi, offset ExceptRecord
    mov rcx, sizeof(EXCEPTION_RECORD)/sizeof(DWORD)
    rep movsd
    mov rsi, pContextRecord
    mov rdi, offset ExceptContext
    mov rcx, sizeof(CONTEXT)/sizeof(QWORD)
    rep movsq

    ;Search for a IMAGE_RUNTIME_FUNCTION_ENTRY that matches to the exception address.
    mov rax, pDispatcherContext
    invoke RtlLookupFunctionEntry, [rax].DISPATCHER_CONTEXT.ControlPc, addr ImgBase, addr TargetGp
    .if rax == NULL                 ;Is return value valid?
      ;We shouldn't arrive here, even with leaf functions, but in case...
      invoke ExitProcess, -2
    .endif

    mov rcx, ImgBase
    mov r8d, [rax].IMAGE_RUNTIME_FUNCTION_ENTRY.BeginAddress
    add r8, rcx                     ;r8 = begin address
    mov r9d, [rax].IMAGE_RUNTIME_FUNCTION_ENTRY.EndAddress
    add r9, rcx                     ;r9 = ending address

    ;Search for the TRY_INFO structure in range (nested innermost structures come first).
    mov rsi, ExcepDataStart
    mov rdi, pDispatcherContext
    mov rdi, [rdi].DISPATCHER_CONTEXT.ControlPc

    .while QWORD ptr [rsi] != EXCEPDATA_END_MARKER
      mov rcx, [rsi].TRY_INFO.TryBeg
      cmp rcx, r8
      jb @F
      cmp rcx, rdi
      ja @F
      mov rdx, [rsi].TRY_INFO.TryEnd
      cmp rdx, r9
      ja @F
      cmp rdx, rdi
      jb @F
      mov LSH_RetValue, -1
      mov r10, pDispatcherContext
      invoke RtlUnwindEx, pEstablisherFrame, rdx, pExceptionRecord, addr LSH_RetValue, \
                          addr OriginalExceptContext, [r10].DISPATCHER_CONTEXT.HistoryTable
      ;Should not return. If it returns there is an error. We don't expect to come here, but anyway.
      invoke ExitProcess, -3
@@:
      add rsi, sizeof(TRY_INFO)
    .endw

    ;No TRY_INFO structure that matches => continue searching in parent procedures.
  .endif

  mov eax, ExceptionContinueSearch

  ret
EHandler endp

end
