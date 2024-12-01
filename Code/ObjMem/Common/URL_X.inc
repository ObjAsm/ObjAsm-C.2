; ==================================================================================================
; Title:      URL_X.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm URL encoding and decoding routines.
; Notes:      Version C.1.0, December 2020
;               - First release.
;               - These routines don't support UFT8 encoding.
; ==================================================================================================


externdef HexCharTableW:CHRW

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  UrlEscDecode
; Purpose:    Translate a wide string containig URL escape sequences to a plain wide string.
; Arguments:  Arg1: -> Input wide string.
;             Arg2: -> Output Buffer.
;             Arg3: Output Buffer size in BYTEs.
; Return:     eax = Number of chars written, including the ZTC.

UrlEscDecodeGetHex macro
  .if (ax >= "0" && ax <= "9")
    sub ax, "0"
  .elseif ax >= "A" && ax <= "F"
    sub ax, "A" - 10
  .elseif ax >= "a" && ax <= "f"
    sub ax, "a" - 10
  .else
    xor eax, eax
    jmp @@Exit                                          ;Error
  .endif
endm

.code
align ALIGN_CODE
UrlEscDecode proc uses xbx xdi xsi pInputStr:PSTRINGW, pBuffer:PSTRINGW, dCount:DWORD
.const
  UrlEscDecodeJumpTable POINTER @@0, @@1, @@2

.code
align ALIGN_CODE
  mov xsi, pInputStr
  mov xdi, pBuffer
  mov ebx, dCount
  shr ebx, 1
  xor ecx, ecx
  if TARGET_BITNESS eq 64
    lea r8, UrlEscDecodeJumpTable
  endif

  .while ebx != 0
    lodsw                                               ;ax = [xsi]; add xsi, 2

    .if ax == 0
      mov [xdi], ax
      dec ebx
      .break
    .endif

    if TARGET_BITNESS eq 32
      jmp POINTER ptr [UrlEscDecodeJumpTable + sizeof(POINTER)*ecx]
    else
      jmp POINTER ptr [r8 + sizeof(POINTER)*rcx]
    endif

@@0:
    .if ax == "%"
      mov ecx, 1
    .else
      stosw
      dec ebx
    .endif
    .continue
@@1:
    inc ecx
    UrlEscDecodeGetHex
    mov dx, ax
    .continue
@@2:
    xor ecx, ecx
    UrlEscDecodeGetHex
    shl edx, 4
    add ax, dx
    stosw
    dec ebx
  .endw

  mov eax, dCount
  shr eax, 1
  sub eax, ebx
@@Exit:
  ret
UrlEscDecode endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  UrlEscEncode
; Purpose:    Translate a plain wide string to a wide string containig URL escape sequences.
; Arguments:  Arg1: -> Input wide string.
;             Arg2: -> Output Buffer.
;             Arg3: Output Buffer size in BYTEs.
; Return:     eax = Number of chars written.

.code
align ALIGN_CODE
UrlEscEncode proc uses xbx xdi xsi pInputStr:PSTRINGW, pBuffer:PSTRINGW, dCount:DWORD
.const
  UrlEscEncodeJumpTable label POINTER
  ;       NUL  SOH  STX  ETX  EDT  ENQ  ACK  BEL  BS   TAB  LF   VF   FF   CR   SO   SI
  POINTER @@?, @@?, @@?, @@?, @@?, @@?, @@?, @@?, @@?, @@?, @@?, @@?, @@?, @@?, @@?, @@?
  ;       DLE  DC1  DC2  DC3  DC4  NAK  SYN  ETB  CAN  BM   SUB  ESC  FS   GS   RS   US
  POINTER @@?, @@?, @@?, @@?, @@?, @@?, @@?, @@?, @@?, @@?, @@?, @@?, @@?, @@?, @@?, @@?
  ;       SPC   !    "    #    $    %    &    '    (    )    *    +    ,    -    .    /
  POINTER @@@, @@@, @@@, @@@, @@@, @@@, @@@, @@@, @@@, @@@, @@@, @@@, @@@, @@@, @@@, @@@
  ;        0    1    2    3    4    5    6    7    8    9    :    ;    <    =    >    ?
  POINTER @@?, @@?, @@?, @@?, @@?, @@?, @@?, @@?, @@?, @@?, @@@, @@@, @@@, @@@, @@@, @@@
  ;        @    A    B    C    D    E    F    G    H    I    J    K    L    M    N    O
  POINTER @@@, @@?, @@?, @@?, @@?, @@?, @@?, @@?, @@?, @@?, @@?, @@?, @@?, @@?, @@?, @@?
  ;       P    Q    R    S    T    U    V    W    X    Y    Z    [    \    ]    ^    _
  POINTER @@?, @@?, @@?, @@?, @@?, @@?, @@?, @@?, @@?, @@?, @@?, @@@, @@@, @@@, @@?, @@?
  ;       `    a    b    c    d    e    f    g    h    i    j    k    l    m    n    o
  POINTER @@?, @@?, @@?, @@?, @@?, @@?, @@?, @@?, @@?, @@?, @@?, @@?, @@?, @@?, @@?, @@?
  ;       p    q    r    s    t    u    v    w    x    y    z    {    |    }    ~
  POINTER @@?, @@?, @@?, @@?, @@?, @@?, @@?, @@?, @@?, @@?, @@?, @@@, @@@, @@@, @@?, @@?

.code
align ALIGN_CODE
  mov xsi, pInputStr
  mov xdi, pBuffer
  mov ebx, dCount
  shr ebx, 1
  if TARGET_BITNESS eq 64
    lea r8, UrlEscEncodeJumpTable
  endif

  .while ebx != 0
    xor eax, eax
    lodsw                                               ;ax = [xsi]; add xsi, 2

    .if ax > 127
      jmp @@@
    .endif
    if TARGET_BITNESS eq 32
      jmp POINTER ptr [UrlEscEncodeJumpTable + sizeof(POINTER)*eax]
    else
      jmp POINTER ptr [r8 + sizeof(POINTER)*rax]
    endif

@@?:
    stosw
    dec ebx
    .break .if ax == 0
    .continue
@@@:
    movzx edx, ax
    mov ax, '%'
    mov xcx, offset HexCharTableW
    stosw
    mov eax, [xcx + sizeof(DCHRW)*xdx]
    stosd
    sub ebx, 3
  .endw

  mov eax, dCount
  shr eax, 1
  sub eax, ebx
  ret
UrlEscEncode endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     UrlEscEncodeSize
; Purpose:    Calculates the requiered buffer size for UrlEscEncode method.
; Arguments:  Arg1: -> Input wide string.
; Return:     eax = Number of BYTEs requierd, including the ZTC.

UrlEscEncodeSize proc uses xsi pInputStr:PSTRINGW
.const
  UrlEscEncodeSizeTable label POINTER
  ;       NUL  SOH  STX  ETX  EDT  ENQ  ACK  BEL  BS   TAB  LF   VF   FF   CR   SO   SI
  BYTE      1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1
  ;       DLE  DC1  DC2  DC3  DC4  NAK  SYN  ETB  CAN  BM   SUB  ESC  FS   GS   RS   US
  BYTE      1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1
  ;       SPC   !    "    #    $    %    &    '    (    )    *    +    ,    -    .    /
  BYTE      3,   3,   3,   3,   3,   3,   3,   3,   3,   3,   3,   3,   3,   3,   3,   3
  ;        0    1    2    3    4    5    6    7    8    9    :    ;    <    =    >    ?
  BYTE      1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   3,   3,   3,   3,   3,   3
  ;        @    A    B    C    D    E    F    G    H    I    J    K    L    M    N    O
  BYTE      3,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1
  ;       P    Q    R    S    T    U    V    W    X    Y    Z    [    \    ]    ^    _
  BYTE      1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   3,   3,   3,   1,   1
  ;       `    a    b    c    d    e    f    g    h    i    j    k    l    m    n    o
  BYTE      1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1
  ;       p    q    r    s    t    u    v    w    x    y    z    {    |    }    ~
  BYTE      1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   1,   3,   3,   3,   1,   1

.code
align ALIGN_CODE
  mov xsi, pInputStr
  xor ecx, ecx
  xor eax, eax
  if TARGET_BITNESS eq 64 
    lea r8, UrlEscEncodeSizeTable
  endif

  .while TRUE
    lodsw                                               ;ax = [xsi]; add xsi, 2
    .if ax < 128
      if TARGET_BITNESS eq 32
        movzx edx, BYTE ptr [UrlEscEncodeSizeTable + eax]
      else
        movzx edx, BYTE ptr [r8 + rax]
      endif
      add ecx, edx
      .break .if ax == 0
    .else
      add ecx, 3
    .endif
  .endw

  lea eax, [2*ecx]
  ret
UrlEscEncodeSize endp

