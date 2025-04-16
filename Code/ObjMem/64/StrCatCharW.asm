; ==================================================================================================
; Title:      StrCatCharW.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMemWin.cop

; --------------------------------------------------------------------------------------------------
; Procedure:  StrCatCharW
; Purpose:    Append a character to the end of an WIDE string.
; Arguments:  Arg1: Destrination ANSI buffer.
;             Arg2: WIDE character.
; Return:     Nothing.

.code
align ALIGN_CODE
StrCatCharW proc pBuffer:POINTER, wChar:CHRW
  invoke StrEndW, rcx                                   ;pBuffer
  movzx ecx, wChar                                      ;wChar
  mov DCHRW ptr [rax], ecx                              ;Writes cChar and ZTC
  ret
StrCatCharW endp

end
