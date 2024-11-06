; ==================================================================================================
; Title:      StrCCatCharW.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
% include &ObjMemPath&ObjMemWin.cop

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  StrCCatCharW
; Purpose:    Append a character to the end of a WIDE string with length limitation.
; Arguments:  Arg1: -> Destination WIDE character buffer.
;             Arg2: -> Wide character.
;             Arg3: Maximal number of characters that fit into the destination buffer.
; Return:     Nothing.

OPTION PROC:NONE

.code
align ALIGN_CODE
StrCCatCharW proc pBuffer:POINTER, cChar:CHRW, dMaxChars:DWORD
  invoke StrEndW, [esp + 4]                             ;pBuffer
  mov ecx, [esp + 4]                                    ;ecx -> Buffer
  mov edx, [esp + 12]                                   ;edx = dMaxChars
  lea ecx, [ecx + 2*edx]
  sub ecx, eax
  jbe @F
  movzx ecx, WORD ptr [esp + 8]                         ;Write char and ZTC
  mov [eax], ecx
@@:
  ret 12
StrCCatCharW endp

OPTION PROC:DEFAULT

end
