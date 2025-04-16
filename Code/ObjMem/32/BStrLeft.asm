; ==================================================================================================
; Title:      BStrLeft.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
% include &ObjMemPath&ObjMemWin.cop

; --------------------------------------------------------------------------------------------------
; Procedure: BStrLeft
; Purpose:   Extract the left n characters of the source BStr.
; Arguments: Arg1: -> Destination BStr buffer.
;            Arg2: -> Source BStr.
; Return:    eax = Number of copied characters, not including the ZTC.

OPTION PROC:NONE

.code
align ALIGN_CODE
BStrLeft proc pDstBStr:POINTER, pSrcBStr:POINTER, dCharCount:DWORD
  mov ecx, [esp + 8]                                    ;ecx -> SrcBStr
  mov eax, DWORD ptr [ecx - 4]
  cmp eax, [esp + 12]                                   ;dCharCount
  jle @F
  mov eax, [esp + 12]                                   ;eax = dCharCount
@@:
  push eax
  shl eax, 1
  push eax
  invoke MemShift, [esp + 20], ecx, eax                 ;pDstBStr
  pop ecx
  mov edx, [esp + 8]                                    ;pDstBStr
  mov DWORD ptr [edx - 4], ecx
  add edx, ecx
  m2z WORD ptr [edx]                                    ;Set zero terminator
  pop eax
  ret 12
BStrLeft endp

OPTION PROC:DEFAULT

end
