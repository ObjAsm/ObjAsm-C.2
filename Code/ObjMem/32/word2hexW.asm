; ==================================================================================================
; Title:      word2hexW.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, July 2022
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
% include &ObjMemPath&ObjMemWin.cop

externdef HexCharTableW:CHRW

; --------------------------------------------------------------------------------------------------
; Procedure:  word2hexW
; Purpose:    Convert a WORD to its hexadecimal WIDE string representation.
; Arguments:  Arg1: -> Destination WIDE string buffer.
;             Arg2: WORD value.
; Return:     Nothing.
; Notes:      The destination buffer must be at least 9 BYTEs large to allocate the output string
;             (4 character WORDs + ZTC = 9 BYTEs).

OPTION PROC:NONE

.code
align ALIGN_CODE
word2hexW proc pBuffer:POINTER, wValue:WORD
  mov edx, [esp + 4]                                    ;edx -> Buffer
  mov cx, [esp + 8]                                     ;cx = wValue
  movzx eax, ch
  mov eax, DCHRW ptr HexCharTableW[sizeof(DCHRW)*eax]
  mov DCHRW ptr [edx], eax
  movzx eax, cl
  mov eax, DCHRW ptr HexCharTableW[sizeof(DCHRW)*eax]
  mov DCHRW ptr [edx + sizeof(DCHRW)], eax
  m2z CHRW ptr [edx + 2*sizeof(DCHRW)]                  ;Set ZTC
  ret 8
word2hexW endp

OPTION PROC:DEFAULT

end
