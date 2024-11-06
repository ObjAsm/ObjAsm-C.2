; ==================================================================================================
; Title:      Err2StrW.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
% include &ObjMemPath&ObjMemWin.cop

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  Err2StrW
; Purpose:    Translate a system error code to a WIDE string.
; Arguments:  Arg1: Error code.
;             Arg2: -> WIDE string buffer.
;             Arg3: Buffer size in characters, inclusive ZTC.
; Return:     Nothing.

OPTION PROC:NONE

.code
align ALIGN_CODE
Err2StrW proc dError:DWORD, pBuffer:POINTER, dMaxChars:DWORD
  mov eax, POINTER ptr [esp + 8]                        ;pBuffer
  m2z BYTE ptr [eax]
  invoke FormatMessageW, FORMAT_MESSAGE_FROM_SYSTEM, 0, \
                         DWORD ptr [esp + 20], \        ;dError
                         0, \
                         POINTER ptr [esp + 16], \      ;pBuffer
                         DWORD ptr [esp + 16], \        ;dMaxChars
                         0
  ret 12
Err2StrW endp

OPTION PROC:DEFAULT

end
