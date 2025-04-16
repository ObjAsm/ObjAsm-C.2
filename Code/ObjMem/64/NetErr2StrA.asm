; ==================================================================================================
; Title:      NetErr2StrA.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMemWin.cop

; --------------------------------------------------------------------------------------------------
; Procedure:  NetErr2StrA
; Purpose:    Translate a network error code to an ANSI string.
; Arguments:  Arg1: Error code.
;             Arg2: -> ANSI character buffer.
;             Arg3: Buffer size in characters, inclusive ZTC.
; Return:     eax = Number CHRA stored in the output buffer, excluding the ZTC.

.code
align ALIGN_CODE
NetErr2StrA proc uses rbx rdi dError:DWORD, pBuffer:POINTER, dMaxChars:DWORD
  m2z CHRA ptr [rdx]                                    ;rdx = pBuffer
  invoke LoadLibraryExA, $OfsCStrA("NetMsg.dll"), 0, LOAD_LIBRARY_AS_DATAFILE
  .if rax != 0                                          ;rax = loaded module HANDLE
    mov rbx, rax
    invoke FormatMessageA, FORMAT_MESSAGE_FROM_HMODULE or FORMAT_MESSAGE_FROM_SYSTEM, rbx, \
                           dError, 0, pBuffer, dMaxChars, 0
    mov edi, eax
    invoke FreeLibrary, rbx
    mov eax, edi
  .endif
  ret
NetErr2StrA endp

end
