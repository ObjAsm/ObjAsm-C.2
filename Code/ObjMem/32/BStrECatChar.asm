; ==================================================================================================
; Title:      BStrCatChar.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
% include &ObjMemPath&ObjMemWin.cop

; --------------------------------------------------------------------------------------------------
; Procedure:  BStrECatChar
; Purpose:    Append a WIDE character to a BStr and return the address of the ZTC.
;             BStrECatChar does not perform any length checking. The destination buffer must have
;             enough room for at least BStrLength(Destination) + 1 + 1 characters.
; Arguments:  Arg1: -> Destination BStr buffer.
;             Arg2: -> WIDE character.
; Return:     eax -> ZTC.

OPTION PROC:NONE

.code
align ALIGN_CODE
BStrECatChar proc pDstBStr:POINTER, cChar:CHRW
  mov ecx, [esp + 4]                                    ;ecx -> DstBStr
  mov eax, [ecx - 4]                                    ;Get the length of DstBStr
  add eax, ecx
  movzx edx, CHRW ptr [esp + 8]                         ;cChar
  add DWORD ptr [ecx - 4], 2                            ;Correct the length
  mov DWORD ptr [eax], edx                              ;Write character and ZTC
  add eax, 2
  ret 8
BStrECatChar endp

OPTION PROC:DEFAULT

end
