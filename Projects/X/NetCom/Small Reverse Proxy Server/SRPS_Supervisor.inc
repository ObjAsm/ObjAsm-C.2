; ==================================================================================================
; Title:      SRPS_Supervisor.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm support of SRPS_Supervisor objects.
;             Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


; --------------------------------------------------------------------------------------------------
; Object:  NetComSrpsSupervisor
; Purpose: Controls overall status of the NetComEngine

Object NetComSrpsSupervisor,, NetComSupervisor
;  RedefineMethod  Done
;  RedefineMethod  Init,               POINTER             ;-> NetComEngine
ObjectEnd


.code

if IMPLEMENT

; ==================================================================================================
;    NetComSrpsSupervisor implementation
; ==================================================================================================

;; --------------------------------------------------------------------------------------------------
;; Method:     NetComSrpsSupervisor.Done
;; Purpose:    Finalize this object.
;; Arguments:  None.
;; Return:     Nothing.
;
;Method NetComSrpsSupervisor.Done, uses xsi
;  SetObject xsi
;  ACall xsi.Done
;MethodEnd
;
;; --------------------------------------------------------------------------------------------------
;; Method:     NetComSrpsSupervisor.Init
;; Purpose:    Initialize this object.
;; Arguments:  Arg1: -> Owner object.
;;             Arg2: -> String representing the service or the port number as a string.
;; Return:     eax = Zero if succeeded, otherwise an error code.
;
;Method NetComSrpsSupervisor.Init, uses xsi, pOwner:POINTER;, pServiceName:PSTRING
;  SetObject xsi
;  xor eax, eax
;MethodEnd
;
;; --------------------------------------------------------------------------------------------------
;; Method:     NetComSrpsSupervisor.Worker
;; Purpose:    This thread is responsible making all administrative work on the engine.
;; Arguments:  None.
;; Return:     Nothing.
;
;Method NetComSrpsSupervisor.Worker, uses xbx xdi xsi
;MethodEnd



endif
