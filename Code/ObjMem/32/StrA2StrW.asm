; ==================================================================================================
; Title:      StrA2StrW.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
% include &ObjMemPath&ObjMemWin.cop

.code
; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  StrA2StrW
; Purpose:    Convert a ANSI string into a WIDE string.
; Arguments:  Arg1: -> Destination WIDE string buffer.
;             Arg2: -> Source ANSI string.
; Return:     eax = Number of chars in string, not including the ZTC.

OPTION PROLOGUE:NONE
OPTION EPILOGUE:NONE

align ALIGN_CODE
StrA2StrW proc pDstStrW:POINTER, pSrcStrA:POINTER
  push edi
  push esi
  mov edi, [esp + 12]                                   ;edi -> DstStrW
  mov esi, [esp + 16]                                   ;esi -> SrcStrA
  invoke StrLengthA, esi
  mov ecx, eax
  push eax
  add esi, eax
  inc ecx
  shl eax, 1
  add edi, eax
  xor eax, eax
  std
@@:
  lodsb
  stosw
  dec ecx
  jne @B
  cld
  pop eax
  pop esi
  pop edi
  ret 8
StrA2StrW endp

OPTION PROLOGUE:PrologueDef
OPTION EPILOGUE:EpilogueDef

end
