; ==================================================================================================
; Title:      StrLower_TX.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, November 2023
;               - First release.
;               - Character and bitness neutral code.
; ==================================================================================================


; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  StrLowerA / StrLowerW
; Purpose:    Convert all characters into upper case.
; Arguments:  Arg1: -> Source string.
; Return:     xax -> String.

OPTION PROC:NONE
align ALIGN_CODE
ProcName proc pString:POINTER

align ALIGN_DATA
.const
  UPPER_CASE_TABLE label BYTE
  ;  NUL SOH STX ETX EDT ENQ ACK BEL  BS TAB  LF  VF  FF  CR  SO  SI
  db 000,000,000,000,000,000,000,000,000,000,000,000,000,000,000,000
  ;  DLE DC1 DC2 DC3 DC4 NAK SYN ETB CAN BM  SUB ESC FS  GS  RS  US
  db 000,000,000,000,000,000,000,000,000,000,000,000,000,000,000,000
  ;  SPC   !   "   #   $   %   &   '   (   )   *   +   ,   -   .   /
  db 000,000,000,000,000,000,000,000,000,000,000,000,000,000,000,000  ;+,/
  ;    0   1   2   3   4   5   6   7   8   9   :   ;   <   =   >   ?
  db 000,000,000,000,000,000,000,000,000,000,000,000,000,000,000,000  ;0..9
  ;    @   A   B   C   D   E   F   G   H   I   J   K   L   M   N   O
  db 000,032,032,032,032,032,032,032,032,032,032,032,032,032,032,032  ;A..O
  ;    P   Q   R   S   T   U   V   W   X   Y   Z   [   \   ]   ^   _
  db 032,032,032,032,032,032,032,032,032,032,032,000,000,000,000,000  ;P..Z
  ;    `   a   b   c   d   e   f   g   h   i   j   k   l   m   n   o
  db 000,000,000,000,000,000,000,000,000,000,000,000,000,000,000,000  ;a..o
  ;    p   q   r   s   t   u   v   w   x   y   z   {   |   }   ~
  db 000,000,000,000,000,000,000,000,000,000,000,000,000,000,000,000  ;p..z
  db 000,000,000,000,000,000,000,000,000,000,000,000,000,000,000,000
  db 000,000,000,000,000,000,000,000,000,000,000,000,000,000,000,000
  db 000,000,000,000,000,000,000,000,000,000,000,000,000,000,000,000
  db 000,000,000,000,000,000,000,000,000,000,000,000,000,000,000,000
  db 000,000,000,000,000,000,000,000,000,000,000,000,000,000,000,000
  db 000,000,000,000,000,000,000,000,000,000,000,000,000,000,000,000
  db 000,000,000,000,000,000,000,000,000,000,000,000,000,000,000,000
  db 000,000,000,000,000,000,000,000,000,000,000,000,000,000,000,000

.code
  ?mov ecx, [esp + 4]                                   ;xcx -> pString
  ??mov r8, rcx
  mov xax, offset UPPER_CASE_TABLE
  .repeat
    movzx edx, CHR ptr [xcx]
    .break .if edx == 0
  if TARGET_STR_TYPE eq STR_TYPE_WIDE
    .if dh == 0
      add dl, BYTE ptr [xax + xdx]
      mov CHR ptr [xcx], $SubReg(xdx, sizeof(CHR))      ;Store the result
    .endif
  else
    add dl, BYTE ptr [xax + xdx]
    mov CHR ptr [xcx], $SubReg(xdx, sizeof(CHR))        ;Store the result
  endif
    add xcx, sizeof CHR
  .until FALSE
if TARGET_BITNESS eq 32
  mov eax, [esp + 4]                                    ;pString
  ret 4
else
  mov rax, r8
  ret
endif
ProcName endp
OPTION PROC:DEFAULT
