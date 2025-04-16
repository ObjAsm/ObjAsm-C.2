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
; Procedure:  BStrCatChar
; Purpose:    Append a character to the end of a BStr.
; Arguments:  Arg1: Destrination BStr.
;             Arg2: Wide character.
; Return:     Nothing.

OPTION PROC:NONE

.code
align ALIGN_CODE
BStrCatChar proc pDstBStr:POINTER, wChar:WORD
  mov ecx, [esp + 4]                                    ;ecx = pDstBStr
  mov eax, [ecx - 4]                                    ;Get the length of DstBStr
  add eax, ecx
  movzx edx, WORD ptr [esp + 8]                         ;wChar
  add DWORD ptr [ecx - 4], 2                            ;Correct length
  mov DWORD ptr [eax], edx                              ;Write character and ZTC
  ret 8
BStrCatChar endp

OPTION PROC:DEFAULT

end
