; ==================================================================================================
; Title:      StrECopyW.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
% include &ObjMemPath&ObjMemWin.cop

; --------------------------------------------------------------------------------------------------
; Procedure:  StrECopyW
; Purpose:    Copy a WIDE to a buffer and return the address of the ZTC.
;             Source and destination strings may overlap.
; Arguments:  Arg1: -> Destination WIDE character buffer.
;             Arg2: -> Source WIDE string.
; Return:     eax -> ZTC.

OPTION PROC:NONE

.code
align ALIGN_CODE
StrECopyW proc pBuffer:POINTER, pSrcStringW:POINTER
  invoke StrLengthW, [esp + 8]                          ;pSrcStringW
  shl eax, 1                                            ;Calc number of BYTEs
  push eax                                              ;Save it
  add eax, 2                                            ;Include ZTC
  invoke MemShift, [esp + 16], [esp + 16], eax          ;pBuffer, pSrcStringW
  pop eax                                               ;Restore
  add eax, [esp + 4]                                    ;Add pDstStringW
  ret 8
StrECopyW endp

OPTION PROC:DEFAULT

end
