; ==================================================================================================
; Title:      ParseCmdLineArgs_X.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, July 2024
;               - First release.
;               - Bitness neutral code.
; ==================================================================================================


; --------------------------------------------------------------------------------------------------
; Procedure:  ParseCmdLineArgs
; Purpose:    Parse a WIDE command line string and return an array of PSTRINGW to the arguments,
;             along with a count of these arguments. Delimiters are white chars and CRLF.
; Arguments:  Arg1: -> Input WIDE string.
; Return:     xax -> List of PSTRINGWs. If the memory allocation for the list failed, xax is NULL.
;             ecx = Argument count.
; Note:       1. Memory allocated to hold the PSTRINGWs must be freed using MemFree.
;             2. The PSTRINGW list is always terminated with a NULL pointer. 
;             3. Quoted arguments are retuned without quotation marks.
;             4. The input string is modified with ZTCs at the end of each argument.

.code
align ALIGN_CODE
ParseCmdLineArgs proc uses xbx xdi xsi, pCmdLineStrW:PSTRINGW
  mov xsi, pCmdLineStrW
  xor ebx, ebx                                          ;Argument Count
  lea xdx, @@1                                          ;Statemachine first step

  .while TRUE
    mov cx, CHRW ptr [xsi]                              ;Read WIDE character
    .break .if cx == 0                                   ;ZTC?
    jmp xdx

  @@1:
    .if cx == SPC || cx == TAB || cx == LF || cx == CR  ;Start search
      add xsi, sizeof(CHRW)
      .continue
    .endif
    lea xdx, @@2
    .continue

  @@2:
    push xsi                                            ;Save start address on the stack
    inc ebx
    lea xdx, @@3
    .continue

  @@3:
    .if cx == '"'                                       ;Opening quote
      add xsi, sizeof(CHRW)                             ;Skip the quote
      lea xdx, @@4
      .continue
    .elseif cx == SPC || cx == TAB || cx == LF || cx == CR
      lea xdx, @@5
      .continue
    .endif
    add xsi, sizeof(CHRW)
    .continue

  @@4:
    .if cx == '"'                                       ;Search closing quote
      add xsi, sizeof(CHRW)                             ;Skip the quote
      lea xdx, @@5
      .continue
    .endif
    add xsi, sizeof(CHRW)                               ;Skip the quote
    .continue

  @@5:
    mov CHRW ptr [xsi], 0                               ;Set ZTC
    add xsi, sizeof(CHRW)
    lea xdx, @@1                                        ;Start again
    .continue

  .endw

  lea eax, [sizeof(POINTER)*ebx + sizeof(POINTER)]      ;Add room for the ending NULL pointer
  sub xsp, 20h
  MemAlloc eax                                          ;Allocate return buffer
  add xsp, 20h
  mov ecx, ebx
  .if xax != NULL
    mov PSTRINGW ptr [xax + xcx*sizeof(PSTRINGW)], NULL
    test ecx, ecx
    .while !ZERO?
      pop PSTRINGW ptr [xax + xcx*sizeof(PSTRINGW) - sizeof(PSTRINGW)]
      dec ecx
    .endw
  .else
    shl xcx, $Log2(sizeof(POINTER))                     ;xcx = used stack space
    add xsp, xcx                                        ;Restore the stack
  .endif
  mov ecx, ebx                                          ;Return argument count in ecx
  ret
ParseCmdLineArgs endp
