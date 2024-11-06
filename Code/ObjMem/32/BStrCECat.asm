; ==================================================================================================
; Title:      BStrCECat.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
% include &ObjMemPath&ObjMemWin.cop

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  BStrCECat
; Purpose:    Concatenate 2 BStrs with length limitation and return the ending zero character
;             address. The destination string buffer should have at least enough room for the
;             maximum number of characters + 1.
; Arguments:  Arg1: -> Destination BStr buffer.
;             Arg2: -> Source BStr.
;             Arg3: Maximal number of charachters that the destination string can hold including
;                   the zero terminating character.
; Return:     eax -> ZTC.

OPTION PROC:NONE

.code
align ALIGN_CODE
BStrCECat proc pDstBStr:POINTER, pSrcBStr:POINTER, dMaxChars:DWORD
  mov ecx, [esp + 8]                                    ;ecx -> SrcBStr
  mov eax, [esp + 4]                                    ;eax -> DstBStr
  sub ecx, 4
  sub eax, 4
  shl DWORD ptr [esp + 12], 1                           ;Convert dMaxChars to BYTEs
  mov edx, DWORD ptr [eax]
  cmp edx, [esp + 12]                                   ;dMaxChars
  jb @F
  mov eax, [esp + 4]                                    ;pDstBStr
  add eax, [esp + 12]                                   ;Destination is longer/equal than Max BYTEs
  ret 12
@@:
  add edx, DWORD ptr [ecx]
  cmp edx, [esp + 12]                                   ;dMaxChars
  jbe @F
  mov edx, [esp + 12]                                   ;dMaxChars
@@:
  sub edx, DWORD ptr [eax]
  add eax, DWORD ptr [eax]
  add eax, 4
  add ecx, 4
  push eax
  push edx
  invoke MemShift, eax, ecx, edx
  pop eax
  pop ecx
  add eax, ecx
  m2z WORD ptr [eax]                                    ;Set terminating zero after mem shifting
  ret 12
BStrCECat endp

OPTION PROC:DEFAULT

end
