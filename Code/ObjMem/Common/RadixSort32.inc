; ==================================================================================================
; Title:      RadixSort32.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - Initial release.
; Purpose:    Helper macros for modular build of radix sort routines.
; ==================================================================================================


;Zero all 256 radix counters
ResetRadixCounters macro                                
  xor eax, eax
  mov ecx, 255*4
  .repeat                                               ;16 loops
    ??Cnt = 0
    repeat 4
      mov [esp + ecx - ??Cnt], eax
      ??Cnt = ??Cnt + 4
    endm
    sub ecx, 4*4
  .until SIGN?
endm                                                    ;On exit, eax = 0


;Calc 32 bit data radix counts
CountRadixData32 macro Arg:req, Src:req                 ;On entry eax must be zero
  .repeat                                               ;eax = 0
    movzx ecx, BYTE ptr [Src + eax + Arg]
    add eax, 4
    inc DWORD ptr [esp + ecx*4]                         ;Increment Counter
    cmp eax, ebx
  .until ZERO?
endm

;Calc 64 bit data radix counts
CountRadixData64 macro Arg:req, Src:req                 ;On entry eax must be zero
  .repeat                                               ;eax = 0
    movzx ecx, BYTE ptr [Src + eax + Arg]
    add eax, 8
    inc DWORD ptr [esp + ecx*4]                         ;Increment Counter
    cmp eax, ebx
  .until ZERO?
endm

;Calc pointed data radix counts
CountRadixPtr macro Arg:req, Src:req                    ;On entry eax must be zero
  .repeat                                               ;eax = 0
    mov edx, [Src + eax]                                ;edx -> structure
    movzx ecx, BYTE ptr [edx + ebp + Arg]               ;ebp = data offset into data structure
    add eax, 4
    inc DWORD ptr [esp + ecx*4]                         ;Increment Counter
    cmp eax, ebx
  .until ZERO?
endm


;Change counts to indices into shadow array
GetRadixCountToIndex macro                              
  xor edx, edx
  xor ecx, ecx
  not edx                                               ;edx = -1
  .repeat
    lea eax, [esp + ecx]
    add ecx, 4
    add edx, [eax]
    cmp ecx, 256*4
    mov [eax], edx
  .until ZERO?                                          ;edx = Count - 1
endm

;Change counts to indices into shadow array but negative numbers first
GetRadixCountToIndexNegFirst macro RevNegFloatOrder:=<FALSE>                          
  xor edx, edx                                        
  mov ecx, 128*4
  not edx                                               ;edx = -1
  .repeat
    lea eax, [esp + ecx]
    add ecx, 4
    add edx, [eax]
    cmp ecx, 256*4
    mov [eax], edx
  .until ZERO?

  if RevNegFloatOrder eq TRUE
    mov ebx, edx                                        ;Save negative float count - 1 in ebx
  endif

  xor ecx, ecx
  .repeat
    lea eax, [esp + ecx]
    add ecx, 4
    add edx, [eax]
    cmp ecx, 128*4
    mov [eax], edx
  .until ZERO?                                          ;edx = Count - 1
endm


;Sort 32 bit data from Src to Dst buffer using the radix indices
SortRadixData32 macro Arg:req, Dst:req, Src:req, RevNegFloatOrder:=<FALSE>
  shl edx, 2                                            ;edx = (Count - 1)*4
  .repeat
    movzx ecx, BYTE ptr [Src + edx + Arg]               ;Get the radix
    mov eax, [esp + ecx*4]                              ;Get offset
    dec DWORD ptr [esp + ecx*4]                         ;Decrement offset for the next lookup
    if RevNegFloatOrder eq TRUE
      .if ecx > 127
        neg eax
        add eax, ebx
      .endif
    endif
    mrm [Dst + eax*4], [Src + edx], ecx                 ;Copy data
    sub edx, 4                                          ;Loop until all data was processed
  .until SIGN?
endm

;Sort 64 bit data from Src to Dst buffer using the radix indices
SortRadixData64 macro Arg:req, Dst:req, Src:req, RevNegFloatOrder:=<FALSE>
  shl edx, 3                                            ;edx = (Count - 1)*8
  .repeat
    movzx ecx, BYTE ptr [Src + edx + Arg]               ;Get the radix
    mov eax, [esp + ecx*4]                              ;Get offset
    dec DWORD ptr [esp + ecx*4]                         ;Decrement offset for the next lookup
    if RevNegFloatOrder eq TRUE
      .if ecx > 127
        neg eax
        add eax, ebx
      .endif
    endif
    mrm [Dst + eax*8], [Src + edx], ecx                 ;Copy 64 bit data
    mrm [Dst + eax*8 + 4], [Src + edx + 4], ecx
    sub edx, 8                                          ;Loop until all data was processed
  .until SIGN?
endm

;Sort POINTERs from Src to Dst buffer using the radix indices
SortRadixPtr macro Arg:req, Dst:req, Src:req, RevNegFloatOrder:=<FALSE>
  shl edx, 2                                            ;edx = (Count - 1)*4
  .repeat
    mov eax, [Src + edx]                                ;ecx -> structure
    movzx ecx, BYTE ptr [eax + ebp + Arg]               ;Get the radix
    mov eax, [esp + ecx*4]                              ;Get offset
    dec DWORD ptr [esp + ecx*4]                         ;Decrement offset for the next lookup
    if RevNegFloatOrder eq TRUE
      .if ecx > 127
        neg eax
        add eax, ebx
      .endif
    endif
    mrm [Dst + eax*4], [Src + edx], ecx                 ;Copy data
    sub edx, 4                                          ;Loop until all data was processed
  .until SIGN?
endm


;32 bit data radix pass
RadixPass32 macro Arg:req, Dst:req, Src:req
  ResetRadixCounters
  CountRadixData32 Arg, Src
  GetRadixCountToIndex
  SortRadixData32 Arg, Dst, Src                         ;Copy data (32 bit data)
endm

;64 bit data radix pass
RadixPass64 macro Arg:req, Dst:req, Src:req
  ResetRadixCounters
  CountRadixData64 Arg, Src
  GetRadixCountToIndex
  SortRadixData64 Arg, Dst, Src                         ;Copy data (64 bit data)
endm

;Pointed data radix pass
RadixPassPtr macro Arg:req, Dst:req, Src:req
  ResetRadixCounters
  CountRadixPtr Arg, Src
  GetRadixCountToIndex
  SortRadixPtr Arg, Dst, Src                            ;Copy data (POINTER)
endm
