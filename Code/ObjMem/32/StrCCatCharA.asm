; ==================================================================================================
; Title:      StrCCatCharA.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
% include &ObjMemPath&ObjMemWin.cop

; --------------------------------------------------------------------------------------------------
; Procedure:  StrCCatCharA
; Purpose:    Append a character to the end of an ANSI string with length limitation.
; Arguments:  Arg1: -> Destination ANSI character buffer.
;             Arg2: -> ANSI character.
;             Arg3: Maximal number of characters that fit into the destination buffer.
; Return:     Nothing.

OPTION PROC:NONE

.code
align ALIGN_CODE
StrCCatCharA proc pBuffer:POINTER, cChar:CHRA, dMaxChars:DWORD
  invoke StrEndA, [esp + 4]                             ;pBuffer
  mov ecx, [esp + 4]                                    ;ecx -> Buffer
  add ecx, [esp + 12]                                   ;edx = dMaxChars
  sub ecx, eax
  jbe @F
  movzx ecx, BYTE ptr [esp + 8]
  mov WORD ptr [eax], cx                                ;Write char and ZTC
@@:
  ret 12
StrCCatCharA endp

OPTION PROC:DEFAULT

end
