; ==================================================================================================
; Title:      ParseA.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
% include &ObjMemPath&ObjMemWin.cop

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  ParseA
; Purpose:    Extract a comma separated substring from a source string.
; Arguments:  Arg1: -> Destination buffer. Must be large enough to hold the ANSI substring.
;             Arg2: -> Source ANSI string.
;             Arg3: Zero based index of the requested ANSI substring.
; Return:     eax = 1: success.
;                   2: insufficient number of components.
;                   3: non matching quotation marks.
;                   4: empty quote.

.code
align ALIGN_CODE
ParseA proc uses edi esi pBuffer:POINTER, pInStr:POINTER, ArgNum:DWORD
  local cmdBuffer[2048]:CHRA
  local tmpBuffer[MAX_PATH]:CHRA

; count quotation marks to see if pairs are matched
  xor ecx, ecx              ;zero ecx & use as counter
  mov esi, pInStr

@@:
  lodsb
  cmp al, 0
  je @F
  cmp al, 34                ;[ " ] character
  jne @B
  inc ecx                   ;increment counter
  jmp @B
@@:
  push ecx                  ;save count
  shr ecx, 1                ;integer divide ecx by 2
  shl ecx, 1                ;multiply ecx by 2 to get dividend

  pop eax                   ;put count in eax
  cmp eax, ecx              ;check if they are the same
  je @F
  mov eax, 3                ;return 3 in eax = non matching quotation marks
  jmp @@Exit
@@:
; replace tabs with spaces
  mov esi, pInStr
  lea edi, cmdBuffer

@@:
  lodsb
  cmp al, 0
  je rtOut
  cmp al, 9                 ;tab
  jne rtIn
  mov al, 32                ;" "
rtIn:
  stosb
  jmp @B
rtOut:
  stosb                     ;write last byte

; substitute spaces in quoted text with replacement character
  lea eax, cmdBuffer
  mov esi, eax
  mov edi, eax

subSt:
  lodsb
  cmp al, 0
  jne @F
  jmp subOut
@@:
  cmp al, 34
  jne subNxt
  stosb
  jmp subSl                 ;goto subloop
subNxt:
  stosb
  jmp subSt

subSl:
  lodsb
  cmp al, 32                ;space
  jne @F
  mov al, 254               ;substitute character
@@:
  cmp al, 34
  jne @F
  stosb
  jmp subSt
@@:
  stosb
  jmp subSl

subOut:
  stosb                     ;write last byte

; The following code determines the correct arg number
; and writes the arg into the destination buffer
  lea eax, cmdBuffer
  mov esi, eax
  lea edi, tmpBuffer

  xor ecx, ecx              ;use ecx as counter...  ecx = 0

; Strip leading spaces if any
@@:
  lodsb
  cmp al, 32
  je @B

l2St:
  cmp ecx, ArgNum           ;the number of the required cmdline arg
  je clSubLp2
  lodsb
  cmp al, 0
  je cl2Out
  cmp al, 32
  jne cl2Ovr                ;if not space

@@:
  lodsb
  cmp al, 32                ;catch consecutive spaces
  je @B

  inc ecx                   ;increment arg count
  cmp al, 0
  je cl2Out

cl2Ovr:
  jmp l2St

clSubLp2:
  stosb
@@:
  lodsb
  cmp al, 32
  je cl2Out
  cmp al, 0
  je cl2Out
  stosb
  jmp @B

cl2Out:
  m2z al
  stosb

; Exit if arg number not reached
  .if ecx < ArgNum
    mov edi, pBuffer
    xor eax, eax            ;al = 0
    stosb
    mov eax, 2              ;return value of 2 means arg did not exist
    jmp @@Exit
  .endif

; Remove quotation marks and replace the substitution character
  lea eax, tmpBuffer
  mov esi, eax
  mov edi, pBuffer

rqStart:
  lodsb
  cmp al, 0
  je rqOut
  cmp al, 34                ;don't write [ " ] mark
  je rqStart
  cmp al, 254
  jne @F
  mov al, 32                ;substitute space
@@:
  stosb
  jmp rqStart

rqOut:
  stosb                     ;write zero terminator

; Process empty quote
  mov esi, pBuffer
  lodsb
  cmp al, 0
  jne @F
  mov eax, 4                ;return value for empty quote
  jmp @@Exit
@@:
  mov eax, 1                ;return value success
@@Exit:
  ret
ParseA endp

end
