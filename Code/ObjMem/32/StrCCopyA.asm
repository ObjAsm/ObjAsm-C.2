; ==================================================================================================
; Title:      StrCCopyA.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
% include &ObjMemPath&ObjMemWin.cop

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  StrCCopyA
; Purpose:    Copy the the source ANSI string with length limitation.
;             The destination buffer should be big enough to hold the maximum number of
;             characters + 1.
; Arguments:  Arg1: -> Destination buffer.
;             Arg2: -> Source ANSI string.
;             Arg3: Maximal number of charachters to copy, excluding the ZTC.
; Return:     eax = Number of copied BYTEs, including the ZTC.

OPTION PROC:NONE

.code
align ALIGN_CODE
StrCCopyA proc pBuffer:POINTER, pSrcStringA:POINTER, dMaxChars:DWORD
  invoke StrCLengthA, [esp + 12], [esp + 12]            ;pSrcStringA, dMaxChars
  push eax
  add eax, [esp + 8]                                    ;Set ZTC at DstStringA
  m2z CHRA ptr [eax]                                    ;Set ZTC
  push [esp + 12]                                       ;pSrcStringA
  push [esp + 12]                                       ;pBuffer
  call MemShift
  add eax, sizeof(CHRA)                                 ;ZTC size
  ret 12
StrCCopyA endp

OPTION PROC:DEFAULT

end
