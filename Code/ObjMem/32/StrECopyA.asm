; ==================================================================================================
; Title:      StrECopyA.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
% include &ObjMemPath&ObjMemWin.cop

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  StrECopyA
; Purpose:    Copy an ANSI to a buffer and return the address of the ending zero character.
;             Source and destination strings may overlap.
; Arguments:  Arg1: -> Destination ANSI character buffer.
;             Arg2: -> Source ANSI string.
; Return:     eax -> ZTC.

OPTION PROC:NONE

.code
align ALIGN_CODE
StrECopyA proc pBuffer:POINTER, pSrcStr:POINTER
  invoke StrLengthA, [esp + 8]
  push eax
  inc eax
  invoke MemShift, [esp + 16], [esp + 16], eax
  pop eax
  add eax, [esp + 4]
  ret 8
StrECopyA endp

OPTION PROC:DEFAULT

end
