; ==================================================================================================
; Title:      StrTitle_TX.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, November 2023
;               - First release.
;               - Character and bitness neutral code.
; ==================================================================================================


; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  StrTitleA / StrTitleW
; Purpose:    Capitalize the first character of each word. The rest is converted to lowercase.
; Arguments:  Arg1: -> Source string.
; Return:     xax -> Formatted String.

OPTION PROC:NONE
align ALIGN_CODE
ProcName proc uses xbx pString:POINTER

align ALIGN_DATA
.const
  TITLE_CASE_TABLE label BYTE
  ;  NUL SOH STX ETX EDT ENQ ACK BEL  BS TAB  LF  VF  FF  CR  SO  SI
  db 000,000,000,000,000,000,000,000,000,000,000,000,000,000,000,000
  ;  DLE DC1 DC2 DC3 DC4 NAK SYN ETB CAN BM  SUB ESC FS  GS  RS  US
  db 000,000,000,000,000,000,000,000,000,000,000,000,000,000,000,000
  ;  SPC   !   "   #   $   %   &   '   (   )   *   +   ,   -   .   /
  db 004,004,004,004,004,004,004,004,004,004,004,004,004,004,004,004  ;+,/
  ;    0   1   2   3   4   5   6   7   8   9   :   ;   <   =   >   ?
  db 000,000,000,000,000,000,000,000,000,000,004,004,004,004,004,004  ;0..9
  ;    @   A   B   C   D   E   F   G   H   I   J   K   L   M   N   O
  db 004,001,001,001,001,001,001,001,001,001,001,001,001,001,001,001  ;A..O
  ;    P   Q   R   S   T   U   V   W   X   Y   Z   [   \   ]   ^   _
  db 001,001,001,001,001,001,001,001,001,001,001,004,004,004,004,004  ;P..Z
  ;    `   a   b   c   d   e   f   g   h   i   j   k   l   m   n   o
  db 004,002,002,002,002,002,002,002,002,002,002,002,002,002,002,002  ;a..o
  ;    p   q   r   s   t   u   v   w   x   y   z   {   |   }   ~
  db 002,002,002,002,002,002,002,002,002,002,002,004,004,004,004,000  ;p..z
  db 000,000,000,000,000,000,000,000,000,000,000,000,000,000,000,000
  db 000,000,000,000,000,000,000,000,000,000,000,000,000,000,000,000
  db 000,000,000,000,000,000,000,000,000,000,000,000,000,000,000,000
  db 000,000,000,000,000,000,000,000,000,000,000,000,000,000,000,000
  db 000,000,000,000,000,000,000,000,000,000,000,000,000,000,000,000
  db 000,000,000,000,000,000,000,000,000,000,000,000,000,000,000,000
  db 000,000,000,000,000,000,000,000,000,000,000,000,000,000,000,000
  db 000,000,000,000,000,000,000,000,000,000,000,000,000,000,000,000

TC_IS_UPPER equ 1
TC_IS_LOWER equ 2
TC_IS_SEPAR equ 4

TC_NEED_UPPER equ 1
TC_NEED_LOWER equ 2

.code
if TARGET_BITNESS eq 32
  mov ecx, [esp + 4]
else
  ??mov r8, rcx
  push rbx
  mov rbx, offset TITLE_CASE_TABLE
endif
  mov al, TC_NEED_UPPER                                 ;Always start with TC_NEED_UPPER 
  .repeat
    movzx edx, CHR ptr [xcx]
    .break .if edx == 0
if TARGET_STR_TYPE eq STR_TYPE_WIDE
    .if dh == 0
endif
if TARGET_BITNESS eq 32
      mov ah, BYTE ptr [TITLE_CASE_TABLE + edx]
else
      mov ah, BYTE ptr [rbx + rdx]
endif
      .if al == TC_NEED_UPPER
        .ifBitSet ah, TC_IS_LOWER
          sub edx, 32
        .endif
        .ifBitClr ah, TC_IS_SEPAR
          mov al, TC_NEED_LOWER
        .endif
      .else
        .ifBitSet ah, TC_IS_UPPER
          add edx, 32
        .endif
        .ifBitSet ah, TC_IS_SEPAR
          mov al, TC_NEED_UPPER
        .endif
      .endif
if TARGET_STR_TYPE eq STR_TYPE_WIDE
    .endif
endif
    mov CHR ptr [xcx], $SubReg(edx, sizeof(CHR))        ;Store the result
    add xcx, sizeof CHR
  .until FALSE
if TARGET_BITNESS eq 32
  mov eax, [esp + 4]                                    ;Return pString
  ret 4
else
  pop rbx
  mov rax, r8
  ret
endif
ProcName endp
OPTION PROC:DEFAULT
