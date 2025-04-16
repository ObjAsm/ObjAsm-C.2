; ==================================================================================================
; Title:      StrRightA.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
% include &ObjMemPath&ObjMemWin.cop

; --------------------------------------------------------------------------------------------------
; Procedure:  StrRightA
; Purpose:    Copy the right n characters from the source string into the destination buffer.
; Arguments:  Arg1: -> Destination ANSI character buffer.
;             Arg2: -> Source ANSI string.
;             Arg3: Character count.
; Return:     Nothing.

OPTION PROC:NONE

.code
align ALIGN_CODE
StrRightA proc pBuffer:POINTER, pSrcStringA:POINTER, dCharCount:DWORD
  invoke StrLengthA, [esp + 8]                          ;pSrcStringA
  mov ecx, eax
  cmp eax, [esp + 12]                                   ;dCharCount
  jbe @F                                                ;unsigned compare!
  mov eax, [esp + 12]                                   ;eax = dCharCount
@@:
  sub ecx, eax
  add ecx, [esp + 8]                                    ;pSrcStringA
  push eax
  invoke MemShift, [esp + 16], ecx, eax
  pop eax                                               ;Return number of copied chars
  mov edx, eax
  add edx, [esp + 4]
  m2z BYTE ptr [edx]                                    ;Set ZTC
  ret 12
StrRightA endp

OPTION PROC:DEFAULT

end
