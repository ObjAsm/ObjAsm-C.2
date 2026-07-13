; ==================================================================================================
; Title:      BStrECat.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - Initial release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMemWin.cop

; --------------------------------------------------------------------------------------------------
; Procedure:  BStrECat
; Purpose:    Append a BSTR to another and return the address of the ZTC.
;             BStrCat does not perform any length checking. The destination buffer must have room
;             for at least BStrLength(Destination) + BStrLength(Source) + 1 characters.
; Arguments:  Arg1: -> Destination BSTR buffer.
;             Arg2: -> Added BSTR.
; Return:     rax -> ZTC.

.code
align ALIGN_CODE
BStrECat proc uses rbx pDstBStr:POINTER, pAddBStr:POINTER  ; rcx -> DstBStr, rdx -> AddBStr
  mov rbx, rcx
  invoke BStrCat, rcx, rdx
  mov eax, [rbx - 4]
  add rax, rbx
  ret
BStrECat endp

end
