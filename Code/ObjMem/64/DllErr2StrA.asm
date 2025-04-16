; ==================================================================================================
; Title:      DllErr2StrA.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMemWin.cop

; --------------------------------------------------------------------------------------------------
; Procedure:  DllErr2StrA
; Purpose:    Translate an error code to an ANSI string stored in a DLL.
; Arguments:  Arg1: Error code.
;             Arg2: -> preallocated ANSI character buffer.
;             Arg3: Buffer size in characters, inclusive ZTC.
;             Arg4: -> DLL ANSI name.
; Return:     Nothing.

.code
align ALIGN_CODE
DllErr2StrA proc uses rbx dError:DWORD, pBuffer:POINTER, dMaxChars:DWORD, pDllNameA:POINTER
  ;ecx = dError, rdx -> Buffer, r8d = dMaxChars, r9 -> DllNameA
  m2z CHRA ptr [rdx]
  invoke LoadLibraryExA, r9, 0, LOAD_LIBRARY_AS_DATAFILE
  .if rax != 0
    mov rbx, rax
    invoke FormatMessageA, FORMAT_MESSAGE_FROM_HMODULE or FORMAT_MESSAGE_FROM_SYSTEM, \
                           rbx, dError, 0, pBuffer, dMaxChars, 0
    xchg rax, rbx
    invoke FreeLibrary, rax
    mov rax, rbx
  .endif
  ret
DllErr2StrA endp

end
