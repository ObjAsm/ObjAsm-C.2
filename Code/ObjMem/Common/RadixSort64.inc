; ==================================================================================================
; Title:      RadixSort64.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    Helper macros for modular build of radix sort routines.
; Notes:      Version C.1.0, October 2017
;               - Initial release.
; ==================================================================================================


;Zero all 256 radix counters
ResetRadixCounters macro
  xor eax, eax
  mov ecx, 255*sizeof(DWORD)
  .repeat                                               ;16 loops
    ??Cnt = 0
    repeat 4
      mov [rsp + rcx - ??Cnt], eax
      ??Cnt = ??Cnt + sizeof(DWORD)
    endm
    sub ecx, 4*sizeof(DWORD)
  .until SIGN?
endm                                                    ;On exit, eax = 0


;Calc 32 bit data radix counts
CountRadixData32 macro Arg:req, Src:req                 ;On entry eax must be zero
  .repeat                                               ;rax = 0
    movzx rcx, BYTE ptr [Src + rax + Arg]
    add rax, sizeof(DWORD)
    inc DWORD ptr [rsp + rcx*sizeof(DWORD)]             ;Increment Counter
    cmp rax, rbx
  .until ZERO?
endm

;Calc 64 bit data radix counts
CountRadixData64 macro Arg:req, Src:req                 ;On entry eax must be zero
  .repeat                                               ;rax = 0
    movzx rcx, BYTE ptr [Src + rax + Arg]
    add rax, sizeof(QWORD)
    inc DWORD ptr [rsp + rcx*sizeof(DWORD)]             ;Increment Counter
    cmp rax, rbx
  .until ZERO?
endm

;Calc pointed data radix counts
CountRadixPtr macro Arg:req, Src:req                    ;On entry eax must be zero
  .repeat                                               ;rax = 0
    mov rdx, [Src + rax]                                ;rdx -> structure
    movzx rcx, BYTE ptr [rdx + r8 + Arg]                ;r8 = data offset into data structure
    add rax, sizeof(DWORD)
    inc DWORD ptr [rsp + rcx*sizeof(DWORD)]             ;Increment Counter
    cmp eax, ebx
  .until ZERO?
endm


;Change counts to indices into shadow array
GetRadixCountToIndex macro
  xor edx, edx
  xor ecx, ecx
  not rdx                                               ;rdx = -1
  .repeat
    lea rax, [rsp + rcx]
    add rcx, sizeof(DWORD)
    add edx, [rax]
    cmp rcx, 256*sizeof(DWORD)
    mov [rax], edx
  .until ZERO?                                          ;rdx = Count - 1
endm

;Change counts to indices into shadow array but negative numbers first
GetRadixCountToIndexNegFirst macro RevNegFloatOrder:=<FALSE>
  xor edx, edx
  mov ecx, 128*sizeof(DWORD)
  not edx                                               ;rdx = -1
  .repeat
    lea rax, [rsp + rcx]
    add rcx, sizeof(DWORD)
    add edx, [rax]
    cmp rcx, 256*sizeof(DWORD)
    mov [rax], edx
  .until ZERO?

  if RevNegFloatOrder eq TRUE
    mov rbx, rdx                                        ;Save negative float count - 1 in rbx
  endif

  xor ecx, ecx
  .repeat
    lea rax, [rsp + rcx]
    add rcx, sizeof(DWORD)
    add edx, [rax]
    cmp rcx, 128*sizeof(DWORD)
    mov [rax], edx
  .until ZERO?                                          ;rdx = Count - 1
endm


;Sort 32 bit data from Src to Dst buffer using the radix indices
SortRadixData32 macro Arg:req, Dst:req, Src:req, RevNegFloatOrder:=<FALSE>
  shl rdx, $Log2(Sizeof(DWORD))                         ;rdx = (Count - 1)*sizeof(DWORD)
  .repeat
    movzx rcx, BYTE ptr [Src + rdx + Arg]               ;Get the radix
    mov eax, [rsp + rcx*sizeof(DWORD)]                  ;Get offset
    dec DWORD ptr [rsp + rcx*sizeof(DWORD)]             ;Decrement offset for the next lookup
    if RevNegFloatOrder eq TRUE
      .if rcx > 127
        neg rax
        add rax, rbx
      .endif
    endif
    mrm DWORD ptr [Dst + rax*sizeof(DWORD)], [Src + rdx], ecx   ;Copy data
    sub rdx, sizeof(DWORD)                              ;Loop until all data was processed
  .until SIGN?
endm

;Sort 64 bit data from Src to Dst buffer using the radix indices
SortRadixData64 macro Arg:req, Dst:req, Src:req, RevNegFloatOrder:=<FALSE>
  shl rdx, $Log2(Sizeof(QWORD))                         ;rdx = (Count - 1)*sizeof(QWORD)
  .repeat
    movzx rcx, BYTE ptr [Src + rdx + Arg]               ;Get the radix
    mov rax, [rsp + rcx*sizeof(DWORD)]                  ;Get offset
    dec DWORD ptr [rsp + rcx*sizeof(DWORD)]             ;Decrement offset for the next lookup
    if RevNegFloatOrder eq TRUE
      .if rcx > 127
        neg rax
        add rax, rbx
      .endif
    endif
    mrm QWORD ptr [Dst + rax*sizeof(QWORD)], [Src + rdx], rcx   ;Copy 64 bit data
    sub edx, sizeof(QWORD)                              ;Loop until all data was processed
  .until SIGN?
endm

;Sort POINTERs from Src to Dst buffer using the radix indices
SortRadixPtr macro Arg:req, Dst:req, Src:req, RevNegFloatOrder:=<FALSE>
  shl rdx, $Log2(Sizeof(DWORD))                         ;rdx = (Count - 1)*sizeof(DWORD)
  .repeat
    mov eax, [Src + rdx]                                ;rax -> structure
    movzx rcx, BYTE ptr [rax + r8 + Arg]                ;Get the radix
    mov rax, [rsp + rcx*sizeof(DWORD)]                  ;Get offset
    dec DWORD ptr [rsp + rcx*sizeof(DWORD)]             ;Decrement offset for the next lookup
    if RevNegFloatOrder eq TRUE
      .if rcx > 127
        neg rax
        add rax, rbx
      .endif
    endif
    mrm QWORD ptr [Dst + rax*sizeof(QWORD)], [Src + rdx], rcx   ;Copy data
    sub rdx, sizeof(QWORD)                              ;Loop until all data was processed
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
