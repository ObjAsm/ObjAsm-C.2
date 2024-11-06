; ==================================================================================================
; Title:      ComEventsAdvice.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
% include &ObjMemPath&ObjMemWin.cop

% include &MacPath&Objects.inc
% include &COMPath&COM.inc
% include &IncPath&Windows\ocidl.inc

externdef IID_IConnectionPointContainer:GUID

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  ComEventsAdvice
; Purpose:    Notificate the Event source that pISink will recieve Events.
; Arguments:  Arg1: -> Any Source Object Interface.
;             Arg2: -> Sink IUnknown Interface.
;             Arg3: -> IID of the outgoing interface whose connection point object is being
;                   requested (defined by the Source to communicate and implemented by the Sink).
;             Arg4: -> ConnectionPoint interface pointer.
;             Arg5: -> DWORD Cookie.
; Return:     eax = HRESULT.

% include &ObjMemPath&Common\ComEventsAdvice_X.inc

end
