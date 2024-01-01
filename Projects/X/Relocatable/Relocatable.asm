; ==================================================================================================
; Title:      Relocatable.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    Demo code to create a Shared Memory Object, inject some relocatable code into it,
;             execute the relocatable code within the SMO, throw a MessageBox to prove its
;             working / hang the app instance, and finally return to the Caller.
;             K32B.inc first written by Bryant Keller, 2005 and
;             modified by EvilHomer, 2005 (100% Relative, no hardcoded addresses generated)
; Notes:      Version C.1.0, November 2023
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\Code\Macros\Model.inc
SysSetup OOP, WIN64, WIDE_STRING;, DEBUG(WND)

% include &IncPath&Windows\winternl.inc                 ;Required for RelocCode.inc

MakeObjects Primer, SharedMemoryObject


;===================================================================================================

;Important notes:
;  Our Remote CodeBlock has three important labels:
;    - RelocCodeSTART defines the beginning of the codeblock
;    - RelocCodeENTER defines the entrypoint in the codeblock
;    - RelocCodeSTOP  defines the end of the codeblock
;
;  RelocCode.inc MUST be included in the remote code block. It contains a relocatable version of
;  GetProcAddress, as well as a bunch of handy macros for writing relocatable code.
;  It doesn't have to be the first thing in the code block, but it MUST precede any references to
;  its macros.
;
;  The $Delta macro returns the ADDRESS of label, not data stored there

SHARED_SIZE equ PAGESIZE
TypeRelocEnter typedef proto :DWORD

.code
RelocCodeSTART:
include RelocCode.inc

pBaseNTDLL POINTER  NULL    ;Base address of NTDLL.dll
pBaseK32   POINTER  NULL    ;Base address of Kernel32.dll
pBaseU32   POINTER  NULL    ;Base address of User32.dll
hLibU32    HANDLE   0       ;Library handle of User32.dll

USE_API GetModuleHandle
USE_API LoadLibrary
USE_API FreeLibrary
USE_API MessageBox
USE_API GetCurrentProcessId
USE_API wsprintf

String szUser32,  "User32"
String szCaption, "How cool is this? Caller's Process ID = %lu  %c"
String szMessage, "I'm executing from within a Shared Memory Object.", CRLF, \
                  "You can fire up simultaneous instances if you like."
szBuffer  CHR  256 dup (0)

RelocCodeENTER proc uses xbx, cMarker:CHR         ;This is our relocated entry point
  GetDllBases pBaseNTDLL, pBaseK32

  ;Prepare a few common API functions
  LoadApi pBaseK32, GetModuleHandle
  LoadApi pBaseK32, LoadLibrary
  LoadApi pBaseK32, GetCurrentProcessId

  ;Gain access to User32 to be able to call "MessageBox"
  ApiRelCall GetModuleHandle, $Delta(xcx, szUser32)
  .if xax == NULL
    ;Load User32.dll
    ApiRelCall LoadLibrary, $Delta(xcx, szUser32)
    ;Remember that we had to LOAD this DLL
    SetDelta hLibU32, xax, xbx
  .endif
  SetDelta pBaseU32, xax, xbx

  ;Prepare MessageBox and wsprintf
  LoadApi pBaseU32, MessageBox
  LoadApi pBaseU32, wsprintf

  ;Grab the current Process ID
  ApiRelCall GetCurrentProcessId

  ;Format a string with PID
  ApiRelCall wsprintf, $Delta(xcx, szBuffer), $Delta(xdx, szCaption), xax, cMarker

  ;Perform MessageBox
  ApiRelCall MessageBox, NULL, $Delta(xdx, szMessage), $Delta(xax, szBuffer), MB_OK

  ;Unload User32 if required
  .if HANDLE ptr [$Delta(xbx, hLibU32)] != 0
    LoadApi pBaseK32, FreeLibrary
    ApiRelCall FreeLibrary, HANDLE ptr [xbx]
  .endif

  ;Return to Caller
  ret
RelocCodeENTER endp

RelocCodeSTOP:


;===================================================================================================

start proc uses xbx xdi
  local pSMO:$ObjPtr(SharedMemoryObject)

  SysInit

  mov ebx, ' '                                          ;Reset marker 
  mov pSMO, $New(SharedMemoryObject)
  OCall pSMO::SharedMemoryObject.Init, NULL, $OfsCStr("SharedMemoryCode"), SHARED_SIZE, \
                                       FILE_MAP_EXECUTE or FILE_MAP_WRITE
  .if eax != FALSE
    mov xcx, pSMO
    mov xdi, [xcx].$Obj(SharedMemoryObject).pMem
    .if eax == SMO_OPENED_NEW
      DbgClearAll
      ;We just created a NEW SMO. copy our codeblock into it
      DbgText "Writing relocatable code to SMO"
      invoke MemClone, xdi, offset RelocCodeSTART, (RelocCodeSTOP - RelocCodeSTART)
      mov ebx, '*'                                      ;Set marker when SMO was written
    .endif

    ;We're ready to execute our codeblock
    DbgText "Executing relocated code"
    ;Calculate the address of RelocCodeENTER in remote code block and CALL to that location
    add xdi, (RelocCodeENTER - RelocCodeSTART)
    invoke TypeRelocEnter ptr xdi, ebx
    DbgText "Returned from relocated code"

  .endif

  Destroy pSMO                                          ;Unmap SMO from this app instance
  SysDone                                               ;It is only released once it has been
  invoke ExitProcess,0                                  ;released by all applications that 
start endp                                              ;have opened it.

end