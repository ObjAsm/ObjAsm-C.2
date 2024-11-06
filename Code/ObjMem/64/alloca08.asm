;*******************************************************************************
;
; Copyright (c) Microsoft Corporation. All rights reserved.
;
; __alloca_probe_8 - align allocation to 8 byte boundary
;
; Purpose:
;       Adjust allocation size so the ESP returned from chkstk will be aligned
;       to 8 bit boundary. Call chkstk to do the real allocation.
;
; Entry:
;       EAX = size of local frame
;
; Exit:
;       Adjusted EAX.
;
; Uses:
;       EAX
;
;*******************************************************************************

% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMemWin.cop

.code
align ALIGN_CODE

_alloca_probe_8 proc c
  ret
_alloca_probe_8 endp

end
