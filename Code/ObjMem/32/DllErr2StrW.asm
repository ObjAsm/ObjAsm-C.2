; ==================================================================================================
; Title:      DllErr2StrW.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
% include &ObjMemPath&ObjMemWin.cop

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  DllErr2StrW
; Purpose:    Translate an error code to a WIDE string stored in a DLL.
; Arguments:  Arg1: Error code.
;             Arg2: -> WIDE character buffer.
;             Arg3: Buffer size in characters, inclusive ZTC.
;             Arg4: -> DLL WIDE name.
; Return:     Nothing.

OPTION PROC:NONE

.code
align ALIGN_CODE
DllErr2StrW proc dError:DWORD, pBuffer:POINTER, dMaxChars:DWORD, pDllNameW:POINTER
  mov eax, POINTER ptr [esp + 8]                        ;pBuffer
  m2z WORD ptr [eax]
  invoke LoadLibraryExW, POINTER ptr [esp + 24], 0, LOAD_LIBRARY_AS_DATAFILE  ;pDllNameW
  .if eax != 0
    push eax
    invoke FormatMessageW, FORMAT_MESSAGE_FROM_HMODULE or FORMAT_MESSAGE_FROM_SYSTEM, eax, \
                           DWORD ptr [esp + 24], \      ;dError
                           0, \
                           POINTER ptr [esp + 20], \    ;pBuffer
                           DWORD ptr [esp + 20], \      ;dMaxChars
                           0
    pop ecx
    push eax
    invoke FreeLibrary, ecx
    pop eax
  .endif
  ret 16
DllErr2StrW endp

OPTION PROC:DEFAULT

end
