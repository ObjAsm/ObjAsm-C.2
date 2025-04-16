; ==================================================================================================
; Title:      StrLRTrimA.asm
; Author:     G. Friedrich
; Version:    C.1.1
; Notes:      Version C.1.0, October 2017
;               - First release.
;             Version C.1.1, September 2019
;               - Bug on string size corrected.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMemWin.cop

; --------------------------------------------------------------------------------------------------
; Procedure:  StrLRTrimA
; Purpose:    Trim blank and tab characters from the beginning and the end of an ANSI string.
; Arguments:  Arg1: -> Destination ANSI character buffer.
;             Arg2: -> Source ANSI string.
; Return:     Nothing.
; Note:       Source and Destination may overlap.

.code
align ALIGN_CODE
StrLRTrimA proc uses rdi rsi pBuffer:POINTER, pSrcStringA:POINTER
  ;rcx = pBuffer, rdx = pSrcStringA
  mov rsi, rdx                                          ;rdx = pSrcStringA
  .repeat
    lodsb
  .until al != ' ' && al != 9
  .if al != 0
    mov rdi, rcx                                        ;rcx = pBuffer
    invoke StrEndA, rsi                                 ;rsi -> second character
    .repeat
      dec rax
      mov cl, [rax]
    .until cl != ' ' && cl != 9
    dec rsi
    sub rax, rsi
    inc rax
    .if rdi != rsi
      mov rdx, rsi
      lea rsi, [rdi + rax]
      invoke MemClone, rdi, rdx, eax
      m2z CHRA ptr [rsi]                                ;Set ZTC
    .else
      m2z CHRA ptr [rdi + rax]                          ;Set ZTC
    .endif
  .else
    mov [rcx], al                                       ;Set ZTC
  .endif
  ret
StrLRTrimA endp

end
