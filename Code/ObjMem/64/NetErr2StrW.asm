; ==================================================================================================
; Title:      NetErr2StrW.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMemWin.cop

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  NetErr2StrW
; Purpose:    Translate a network error code to a WIDE string.
; Arguments:  Arg1: Error code.
;             Arg2: -> WIDE string buffer.
;             Arg3: Buffer size in characters, inclusive ZTC.
; Return:     eax = Number CHRW stored in the output buffer, excluding the ZTC.

.code
align ALIGN_CODE
NetErr2StrW proc uses rbx rdi dError:DWORD, pBuffer:POINTER, dMaxChars:DWORD
  m2z CHRW ptr [rdx]
  invoke LoadLibraryExW, $OfsCStrW("NetMsg.dll"), 0, LOAD_LIBRARY_AS_DATAFILE
  .if rax != 0
    mov rbx, rax
    invoke FormatMessageW, FORMAT_MESSAGE_FROM_HMODULE or FORMAT_MESSAGE_FROM_SYSTEM, rbx, \
                          dError, 0, pBuffer, dMaxChars, 0
    mov rdi, rax
    invoke FreeLibrary, rbx
    mov rax, rdi
  .endif
  ret
NetErr2StrW endp

end
