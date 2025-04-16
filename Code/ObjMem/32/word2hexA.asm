; ==================================================================================================
; Title:      word2hexA.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, July 2022
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
% include &ObjMemPath&ObjMemWin.cop

externdef HexCharTableA:CHRA

; --------------------------------------------------------------------------------------------------
; Procedure:  word2hexA
; Purpose:    Convert a WORD to its hexadecimal ANSI string representation.
; Arguments:  Arg1: -> Destination ANSI string buffer.
;             Arg2: WORD value.
; Return:     Nothing.
; Notes:      The destination buffer must be at least 5 BYTEs large to allocate the output string
;             (4 character BYTEs + ZTC = 5 BYTEs).

OPTION PROC:NONE

.code
align ALIGN_CODE
word2hexA proc pBuffer:POINTER, wValue:WORD
  mov edx, [esp + 4]                                    ;edx -> Buffer
  mov cx, [esp + 8]                                     ;cx = wValue
  movzx eax, ch
  mov ax, DCHRA ptr HexCharTableA[sizeof(DCHRA)*eax]
  mov DCHRA ptr [edx], ax
  movzx eax, cl
  mov ax, DCHRA ptr HexCharTableA[sizeof(DCHRA)*eax]
  mov DCHRA ptr [edx + sizeof(DCHRA)], ax
  m2z CHRA ptr [edx + 2*sizeof(DCHRA)]                  ;Set ZTC
  ret 8
word2hexA endp

OPTION PROC:DEFAULT

end
