; ==================================================================================================
; Title:      Demo04.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm demonstration program Demo04.
; Notes:      Version C.1.0, October 2017
;               - Initial release.
;
; Description:
;   This module provides the entry point and initialization sequence for Demo04. It demonstrates:
;     - Runtime initialization of the ObjAsm OOP environment for a 64-bit Windows application
;     - Loading of the required object classes from the ObjAsm framework
;     - Use of a type-customizable container template (Demo04_Template.inc)
;     - Creation of multiple container instances of TContainer with different underlying data types
;       (QWORD, DWORD, WORD, BYTE, XWORD)
;     - Invocation of the Application object through the standard Init => Run => Done lifecycle
;
; ==================================================================================================


% include @Environ(OBJASM_PATH)\Code\Macros\Model.inc   ; Include and initialize standard modules
SysSetup OOP, WIN64, WIDE_STRING, DEBUG(WND)            ; Load OOP framework and OS-related objects

% includelib &LibPath&Windows\shell32.lib
% includelib &LibPath&Windows\shlwapi.lib

; Load or build the following objects
MakeObjects Primer, Stream, WinPrimer, Window
MakeObjects Button, Hyperlink, Dialog, DialogModal, DialogAbout
MakeObjects WinApp, SdiApp

; Demonstration of object type customization using Demo04_Template.inc
include Demo04_Template.inc

; Create five container objects of different element sizes.
; They are initialized and displayed by the Application object.
if TARGET_BITNESS eq 64
  TContainer QContainer, -1, QWORD
endif
TContainer DContainer, -2, DWORD
TContainer WContainer, -3, WORD
TContainer BContainer, -4, BYTE
TContainer XContainer, -5, XWORD

include Demo04_Globals.inc                              ; Application globals
include Demo04_Main.inc                                 ; Application object

start proc                                              ; Program entry point
  SysInit                                               ; Initialize ObjAsm runtime

  OCall $ObjTmpl(Application)::Application.Init         ; Initialize application
  OCall $ObjTmpl(Application)::Application.Run          ; Execute application
  OCall $ObjTmpl(Application)::Application.Done         ; Finalize application

  SysDone                                               ; Shutdown ObjAsm runtime
  invoke ExitProcess, 0                                 ; Exit program with return code 0
start endp

end