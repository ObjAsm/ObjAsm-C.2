; ==================================================================================================
; Title:      NetErr2StrA.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
% include &ObjMemPath&ObjMemWin.cop

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  NetErr2StrA
; Purpose:    Translate a network error code to an ANSI string.
; Arguments:  Arg1: Error code.
;             Arg2: -> ANSI character buffer.
;             Arg3: Buffer size in characters, inclusive ZTC.
; Return:     Nothing.

OPTION PROC:NONE

.code
align ALIGN_CODE
NetErr2StrA proc dError:DWORD, pBuffer:POINTER, dMaxChars:DWORD
  mov eax, POINTER ptr [esp + 8]                        ;pBuffer
  m2z BYTE ptr [eax]
  invoke LoadLibraryExA, $OfsCStrA("NetMsg.dll"), 0, LOAD_LIBRARY_AS_DATAFILE
  .if eax != 0
    push eax
    invoke FormatMessageA, FORMAT_MESSAGE_FROM_HMODULE or FORMAT_MESSAGE_FROM_SYSTEM, eax, \
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
  ret 12
NetErr2StrA endp

OPTION PROC:DEFAULT

end
