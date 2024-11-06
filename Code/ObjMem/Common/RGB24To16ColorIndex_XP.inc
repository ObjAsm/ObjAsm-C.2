; ==================================================================================================
; Title:      RGB24To16ColorIndex_XP.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, June 2022.
;               - First release.
;               - Bitness and platform independent code.
; ==================================================================================================


COLOR_BLACK         equ 0x00
COLOR_BLUE          equ 0x01
COLOR_GREEN         equ 0x02
COLOR_CYAN          equ 0x03
COLOR_RED           equ 0x04
COLOR_MAGENTA       equ 0x05
COLOR_BROWN         equ 0x06
COLOR_LIGHTGRAY     equ 0x07
COLOR_DARKGRAY      equ 0x08
COLOR_LIGHTBLUE     equ 0x09
COLOR_LIGHTGREEN    equ 0x0A
COLOR_LIGHTCYAN     equ 0x0B
COLOR_LIGHTRED      equ 0x0C
COLOR_LIGHTMAGENTA  equ 0x0D
COLOR_YELLOW        equ 0x0E
COLOR_WHITE         equ 0x0F

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  RGB24To16Colors
; Purpose:    Map a 24 bit RGB color to a 16 color palette index.
; Arguments:  Arg1: RGB color.
; Return:     eax = Palette index.
; Rules:
;              0   +  0   +  0    =  COLOR_BLACK
;              0   +  0   + BlHi  =  COLOR_LIGHTBLUE
;              0   +  0   + BlLo  =  COLOR_BLUE
;              0   + GrHi +  0    =  COLOR_LIGHTGREEN
;              0   + GrHi + BlHi  =  COLOR_LIGHTCYAN
;              0   + GrHi + BlLo  =  COLOR_LIGHTGREEN
;              0   + GrLo +  0    =  COLOR_GREEN
;              0   + GrLo + BlHi  =  COLOR_LIGHTBLUE
;              0   + GrLo + BlLo  =  COLOR_CYAN
;             
;             RdLo +  0   +  0    =  COLOR_RED
;             RdLo +  0   + BlHi  =  COLOR_LIGHTBLUE
;             RdLo +  0   + BlLo  =  COLOR_MAGENTA
;             RdLo + GrHi +  0    =  COLOR_LIGHTGREEN
;             RdLo + GrHi + BlHi  =  COLOR_LIGHTGRAY
;             RdLo + GrHi + BlLo  =  COLOR_DARKGRAY
;             RdLo + GrLo +  0    =  COLOR_BROWN
;             RdLo + GrLo + BlHi  =  COLOR_DARKGRAY
;             RdLo + GrLo + BlLo  =  COLOR_DARKGRAY
;             
;             RdHi +  0   +  0    =  COLOR_LIGHTRED
;             RdHi +  0   + BlHi  =  COLOR_LIGHTMAGENTA
;             RdHi +  0   + BlLo  =  COLOR_LIGHTMAGENTA
;             RdHi + GrHi +  0    =  COLOR_YELLOW
;             RdHi + GrHi + BlHi  =  COLOR_WHITE
;             RdHi + GrHi + BlLo  =  COLOR_LIGHTGRAY
;             RdHi + GrLo +  0    =  COLOR_BROWN
;             RdHi + GrLo + BlHi  =  COLOR_LIGHTGRAY
;             RdHi + GrLo + BlLo  =  COLOR_DARKGRAY

.code
align ALIGN_CODE
RGB24To16ColorIndex proc dColor:DWORD
  mov ecx, dColor
  xor eax, eax
  mov edx, ecx
  shr ecx, 16
  .if dl == 0
    .if dh == 0
      .if cl == 0
        mov eax, COLOR_BLACK
      .elseIfBitSet cl, BIT07
        mov eax, COLOR_LIGHTBLUE
      .else
        mov eax, COLOR_BLUE
      .endif
    .elseIfBitSet dh, BIT07
      .if cl == 0
        mov eax, COLOR_LIGHTGREEN
      .elseIfBitSet cl, BIT07
        mov eax, COLOR_LIGHTCYAN
      .else
        mov eax, COLOR_LIGHTGREEN
      .endif
    .else
      .if cl == 0
        mov eax, COLOR_GREEN
      .elseIfBitSet cl, BIT07
        mov eax, COLOR_LIGHTBLUE
      .else
        mov eax, COLOR_CYAN
      .endif
    .endif

  .elseIfBitSet dl, BIT07
    .if dh == 0
      .if cl == 0
        mov eax, COLOR_LIGHTRED
      .elseIfBitSet cl, BIT07
        mov eax, COLOR_LIGHTMAGENTA
      .else
        mov eax, COLOR_LIGHTMAGENTA
      .endif
    .elseIfBitSet dh, BIT07
      .if cl == 0
        mov eax, COLOR_YELLOW
      .elseIfBitSet cl, BIT07
        mov eax, COLOR_WHITE
      .else
        mov eax, COLOR_LIGHTGRAY
      .endif
    .else
      .if cl == 0
        mov eax, COLOR_BROWN
      .elseIfBitSet cl, BIT07
        mov eax, COLOR_LIGHTGRAY
      .else
        mov eax, COLOR_DARKGRAY
      .endif
    .endif

  .else
    .if dh == 0
      .if cl == 0
        mov eax, COLOR_RED
      .elseIfBitSet cl, BIT07
        mov eax, COLOR_LIGHTBLUE
      .else
        mov eax, COLOR_MAGENTA
      .endif
    .elseIfBitSet dh, BIT07
      .if cl == 0
        mov eax, COLOR_LIGHTGREEN
      .elseIfBitSet cl, BIT07
        mov eax, COLOR_LIGHTGRAY
      .else
        mov eax, COLOR_DARKGRAY
      .endif
    .else
      .if cl == 0
        mov eax, COLOR_BROWN
      .elseIfBitSet cl, BIT07
        mov eax, COLOR_LIGHTGRAY
      .else
        mov eax, COLOR_DARKGRAY
      .endif
    .endif
  .endif

  ret
RGB24To16ColorIndex endp
