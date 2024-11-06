; ==================================================================================================
; Title:      Err2StrA.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMemWin.cop

% include &MacPath&Strings.inc

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  Err2StrA
; Purpose:    Translate a system error code to an ANSI string.
; Arguments:  Arg1: Error code.
;             Arg2: -> ANSI string buffer.
;             Arg3: Buffer size in characters, inclusive ZTC.
; Return:     Nothing.

.code
align ALIGN_CODE
Err2StrA proc dError:DWORD, pBuffer:POINTER, dMaxChars:DWORD
  .if rdx != NULL
    m2z CHRA ptr [rdx]
    mov eax, ecx
    mov r10, rdx
    mov r11d, r8d
    invoke FormatMessageA, FORMAT_MESSAGE_FROM_SYSTEM, 0, eax, 0, r10, r11d, 0
  .endif
  ret
Err2StrA endp

end
