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

% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
% include &ObjMemPath&ObjMemWin.cop

.code
align ALIGN_CODE
_alloca_probe_8 proc c
  push ecx
  lea ecx, [esp] + 8            ;TOS before entering this function
  sub ecx, eax                  ;New TOS
  and ecx, (8 - 1)              ;Distance from 8 bit align (align down)
  add eax, ecx                  ;Increase allocation Size
  sbb ecx, ecx                  ;ecx = 0xFFFFFFFF if size wrapped around
  or eax, ecx                   ;cap allocation size on wraparound
  pop ecx                       ;Restore ecx
  jmp _chkstk
_alloca_probe_8 endp

end
