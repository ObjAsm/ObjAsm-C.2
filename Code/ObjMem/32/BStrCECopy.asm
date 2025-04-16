; ==================================================================================================
; Title:      BStrCECopy.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
% include &ObjMemPath&ObjMemWin.cop

; --------------------------------------------------------------------------------------------------
; Procedure:  BStrCECopy
; Purpose:    Copy the the source BStr with length limitation and return the ZTC address.
;             The destination buffer should hold the maximum number of characters + 1.
; Arguments:  Arg1: -> Destination BStr buffer.
;             Arg2: -> Source BStr.
;             Arg3: Maximal number of charachters.
; Return:     eax -> ZTC.

OPTION PROC:NONE

.code
align ALIGN_CODE
BStrCECopy proc pDstBStr:POINTER, pSrcBStr:POINTER, dMaxLen:DWORD
  mov ecx, [esp + 8]                                    ;ecx -> SrcBStr
  mov eax, [esp + 4]                                    ;eax -> DstBStr
  shl DWORD ptr [esp + 12], 1                           ;dMaxLen => BYTEs
  mov edx, DWORD ptr [ecx - 4]                          
  cmp edx, [esp + 12]                                   ;dMaxLen
  jbe @F                                                
  mov edx, [esp + 12]                                   ;dMaxLen
@@:
  push eax
  push edx
  mov [eax - 4], edx
  invoke MemShift, eax, ecx, edx
  pop edx
  pop eax
  add eax, edx
  m2z WORD ptr [eax]                                    ;Set terminating zero after mem shifting
  ret 12
BStrCECopy endp

OPTION PROC:DEFAULT

end
