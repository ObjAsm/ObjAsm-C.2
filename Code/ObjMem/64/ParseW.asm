; ==================================================================================================
; Title:      ParseW.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMemWin.cop

; --------------------------------------------------------------------------------------------------
; Procedure:  ParseW
; Purpose:    Extract a comma separated substring from a source string.
; Arguments:  Arg1: -> Destination buffer. Must be large enough to hold the WIDE substring.
;             Arg2: -> Source WIDE string.
;             Arg3: Zero based index of the requested WIDE substring.
; Return:     eax = 1: success.
;                   2: insufficient number of components.
;                   3: non matching quotation marks.
;                   4: empty quote.

.code
align ALIGN_CODE
ParseW proc uses rdi rsi pBuffer:POINTER, pInStr:POINTER, ArgNum:DWORD
  local cmdBuffer[2048]:CHRW
  local tmpBuffer[MAX_PATH]:CHRW

; count quotation marks to see if pairs are matched
  xor ecx, ecx              ;zero ecx & use as counter
  mov rsi, pInStr

@@:
  lodsw
  cmp ax, 0
  je @F
  cmp ax, 34                ;[ " ] character
  jne @B
  inc ecx                   ;increment counter
  jmp @B
@@:
  mov eax, ecx              ;put count in eax
  shr ecx, 1                ;integer divide ecx by 2
  shl ecx, 1                ;multiply ecx by 2 to get dividend

  cmp eax, ecx              ;check if they are the same
  je @F
  mov eax, 3                ;return 3 in eax = non matching quotation marks
  jmp @@Exit
@@:
; replace tabs with spaces
  mov rsi, pInStr
  lea rdi, cmdBuffer

@@:
  lodsw
  cmp ax, 0
  je rtOut
  cmp ax, 9                 ;tab
  jne rtIn
  mov ax, 32                ;" "
rtIn:
  stosw
  jmp @B
rtOut:
  stosw                     ;write last byte

; substitute spaces in quoted text with replacement character
  lea rax, cmdBuffer
  mov rsi, rax
  mov rdi, rax

subSt:
  lodsw
  cmp ax, 0
  jne @F
  jmp subOut
@@:
  cmp ax, 34
  jne subNxt
  stosw
  jmp subSl                 ;goto subloop
subNxt:
  stosw
  jmp subSt

subSl:
  lodsw
  cmp ax, 32                ;space
  jne @F
  mov ax, 254               ;substitute character
@@:
  cmp ax, 34
  jne @F
  stosw
  jmp subSt
@@:
  stosw
  jmp subSl

subOut:
  stosw                     ;write last byte

; The following code determines the correct arg number
; and writes the arg into the destination buffer
  lea rax, cmdBuffer
  mov rsi, rax
  lea rdi, tmpBuffer

  xor ecx, ecx              ;use ecx as counter...  ecx = 0

; Strip leading spaces if any
@@:
  lodsw
  cmp ax, 32
  je @B

l2St:
  cmp ecx, ArgNum           ;the number of the required cmdline arg
  je clSubLp2
  lodsw
  cmp ax, 0
  je cl2Out
  cmp ax, 32
  jne cl2Ovr                ;if not space

@@:
  lodsw
  cmp ax, 32                ;catch consecutive spaces
  je @B

  inc ecx                   ;increment arg count
  cmp ax, 0
  je cl2Out

cl2Ovr:
  jmp l2St

clSubLp2:
  stosw
@@:
  lodsw
  cmp ax, 32
  je cl2Out
  cmp ax, 0
  je cl2Out
  stosw
  jmp @B

cl2Out:
  m2z ax
  stosw

; Exit if arg number not reached
  .if ecx < ArgNum
    mov rdi, pBuffer
    xor eax, eax            ;al = 0
    stosw
    mov eax, 2              ;return value of 2 means arg did not exist
    jmp @@Exit
  .endif

; Remove quotation marks and replace the substitution character
  lea rax, tmpBuffer
  mov rsi, rax
  mov rdi, pBuffer

rqStart:
  lodsw
  cmp ax, 0
  je rqOut
  cmp ax, 34                ;don't write [ " ] mark
  je rqStart
  cmp ax, 254
  jne @F
  mov ax, 32                ;substitute space
@@:
  stosw
  jmp rqStart

rqOut:
  stosw                     ;write zero terminator

; Process empty quote
  mov rsi, pBuffer
  lodsw
  cmp ax, 0
  jne @F
  mov eax, 4                ;return value for empty quote
  jmp @@Exit
@@:
  mov eax, 1                ;return value success
@@Exit:
  ret
ParseW endp

end
