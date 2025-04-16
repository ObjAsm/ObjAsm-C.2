; ==================================================================================================
; Title:      ComEventsUnadvice.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMemWin.cop

% include &MacPath&Objects.inc
% include &COMPath&COM.inc
% include &IncPath&Windows\ocidl.inc

; --------------------------------------------------------------------------------------------------
; Procedure:  ComEventsUnadvice
; Purpose:    Notificate the Event source that pISource will NOT recieve Events any more.
; Arguments:  Arg1: -> Previous ConnectionPoint interface.
;             Arg2: DWORD Cookie received from previous ComEventsAdvice call.
; Return:     eax = HRESULT.

% include &ObjMemPath&Common\ComEventsUnadvice_X.inc

end
