; ==================================================================================================
; Title:      StrLRTrimW.asm
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
; Procedure:  StrLRTrimW
; Purpose:    Trim blank and tab characters from the beginning and the end of a WIDE string.
; Arguments:  Arg1: -> Destination WIDE character buffer.
;             Arg2: -> Source WIDE string.
; Return:     Nothing.
; Note:       Source and Destination may overlap.

.code
align ALIGN_CODE
StrLRTrimW proc uses rdi rsi pBuffer:POINTER, pSrcStringW:POINTER
  ;rcx = pBuffer, rdx = pSrcStringA
  mov rsi, rdx                                          ;rdx = pSrcStringA
  .repeat
    lodsw
  .until ax != ' ' && ax != 9
  .if ax != 0
    mov rdi, rcx                                        ;rcx = pBuffer
    invoke StrEndW, rsi                                 ;rsi -> second character
    .repeat
      sub rax, 2
      mov cx, [rax]
    .until cx != ' ' && cx != 9
    sub rsi, 2
    sub rax, rsi
    add rax, 2
    .if rdi != rsi
      mov rdx, rsi
      lea rsi, [rdi + rax]
      invoke MemClone, rdi, rdx, eax
      m2z CHRW ptr [rsi]                                ;Set ZTC
    .else
      m2z CHRW ptr [rdi + rax]                          ;Set ZTC
    .endif
  .else
    mov [rcx], ax                                       ;Set ZTC
  .endif
  ret
StrLRTrimW endp

end
