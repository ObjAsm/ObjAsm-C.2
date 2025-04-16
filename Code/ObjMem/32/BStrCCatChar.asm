; ==================================================================================================
; Title:      BStrCCatChar.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
% include &ObjMemPath&ObjMemWin.cop

; --------------------------------------------------------------------------------------------------
; Procedure: BStrCCatChar
; Purpose:   Append a WIDE character to a BStr with length limitation.
; Arguments: Arg1: -> Destination BStr.
;            Arg2: -> Wide character.
; Return:    Nothing.

OPTION PROC:NONE

.code
align ALIGN_CODE
BStrCCatChar proc pDstBStr:POINTER, wChar:WORD, dMaxChars:DWORD
  mov ecx, [esp + 4]                                    ;ecx -> DstBStr
  shl DWORD ptr [esp + 12], 1                           ;dMaxChars => BYTEs
  mov edx, [ecx - 4]
  cmp edx, [esp + 12]                                   ;dMaxChars
  jae @F                                                ;Destination is full
  add edx, ecx
  movzx eax, WORD ptr wChar
  add DWORD ptr [ecx - 4], 2                            ;Correct length
  mov DWORD ptr [edx], eax                              ;Write character and ZTC
@@:
  ret 12
BStrCCatChar endp

OPTION PROC:DEFAULT

end
