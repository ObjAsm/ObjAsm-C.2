; ==================================================================================================
; Title:      BStrECat.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
% include &ObjMemPath&ObjMemWin.cop

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  BStrECat
; Purpose:    Append a BStr to another and return the address of the ending zero character.
;             BStrCat does not perform any length checking. The destination buffer must have room
;             for at least BStrLength(Destination) + BStrLength(Source) + 1 characters.
; Arguments:  Arg1: -> Destination BStr buffer.
;             Arg2: -> Source BStr.
; Return:     eax -> ZTC.

OPTION PROC:NONE

.code
align ALIGN_CODE
BStrECat proc pDstBStr:POINTER, pSrcBStr:POINTER
  mov ecx, [esp + 8]                                    ;ecx -> SrcBStr
  mov edx, [esp + 4]                                    ;edx -> DstBStr
  mov eax, DWORD ptr [ecx - 4]
  mov ecx, DWORD ptr [edx - 4]
  add DWORD ptr [edx - 4], eax                          ;Calc and store new length
  add edx, ecx
  push eax
  add eax, 2
  push edx
  invoke MemShift, edx, [esp + 20], eax                 ;pSrcBStr
  pop edx
  pop eax
  add eax, edx
  ret 8
BStrECat endp

OPTION PROC:DEFAULT

end
