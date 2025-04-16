; ==================================================================================================
; Title:      Memory.inc
; Authors:    G. Friedrich
; Version:    C.1.1
; Purpose:    ObjAsm support of basic memory handling macros.
; Notes:      Version C.1.0, October 2017
;               - First release.
;             Version C.1.1, June 2022
;               - UEFI support added.
; ==================================================================================================


if TARGET_PLATFORM eq PLATFORM_WINDOWS
  externdef hProcessHeap:HANDLE
endif

BIT00    equ    0000000000000001h
BIT01    equ    0000000000000002h
BIT02    equ    0000000000000004h
BIT03    equ    0000000000000008h
BIT04    equ    0000000000000010h
BIT05    equ    0000000000000020h
BIT06    equ    0000000000000040h
BIT07    equ    0000000000000080h
BIT08    equ    0000000000000100h
BIT09    equ    0000000000000200h
BIT10    equ    0000000000000400h
BIT11    equ    0000000000000800h
BIT12    equ    0000000000001000h
BIT13    equ    0000000000002000h
BIT14    equ    0000000000004000h
BIT15    equ    0000000000008000h
BIT16    equ    0000000000010000h
BIT17    equ    0000000000020000h
BIT18    equ    0000000000040000h
BIT19    equ    0000000000080000h
BIT20    equ    0000000000100000h
BIT21    equ    0000000000200000h
BIT22    equ    0000000000400000h
BIT23    equ    0000000000800000h
BIT24    equ    0000000001000000h
BIT25    equ    0000000002000000h
BIT26    equ    0000000004000000h
BIT27    equ    0000000008000000h
BIT28    equ    0000000010000000h
BIT29    equ    0000000020000000h
BIT30    equ    0000000040000000h
BIT31    equ    0000000080000000h
BIT32    equ    0000000100000000h
BIT33    equ    0000000200000000h
BIT34    equ    0000000400000000h
BIT35    equ    0000000800000000h
BIT36    equ    0000001000000000h
BIT37    equ    0000002000000000h
BIT38    equ    0000004000000000h
BIT39    equ    0000008000000000h
BIT40    equ    0000010000000000h
BIT41    equ    0000020000000000h
BIT42    equ    0000040000000000h
BIT43    equ    0000080000000000h
BIT44    equ    0000100000000000h
BIT45    equ    0000200000000000h
BIT46    equ    0000400000000000h
BIT47    equ    0000800000000000h
BIT48    equ    0001000000000000h
BIT49    equ    0002000000000000h
BIT50    equ    0004000000000000h
BIT51    equ    0008000000000000h
BIT52    equ    0010000000000000h
BIT53    equ    0020000000000000h
BIT54    equ    0040000000000000h
BIT55    equ    0080000000000000h
BIT56    equ    0100000000000000h
BIT57    equ    0200000000000000h
BIT58    equ    0400000000000000h
BIT59    equ    0800000000000000h
BIT60    equ    1000000000000000h
BIT61    equ    2000000000000000h
BIT62    equ    4000000000000000h
BIT63    equ    8000000000000000h

if TARGET_BITNESS eq 32
  BIT_SIGN equ BIT31
else
  BIT_SIGN equ BIT63
endif

DOUBLEBYTE union
  WORD                       ?
  struc
    LoByte    BYTE           ?
    HiByte    BYTE           ?
  ends
DOUBLEBYTE ends
pDOUBLEBYTE typedef ptr DOUBLEBYTE

DOUBLEWORD union
  DWORD                      ?
  struc
    LoWrd    DOUBLEBYTE      {}
    HiWrd    DOUBLEBYTE      {}
  ends
DOUBLEWORD ends
PDOUBLEWORD typedef ptr DOUBLEWORD

QUADWORD union
  QWORD                      ?
  struc
    LoDWord    DOUBLEWORD    {}
    HiDWord    DOUBLEWORD    {}
  ends
QUADWORD ends
PQUADWORD typedef QUADWORD

OCTOWORD union
  OWORD                      ?
  struc
    LoQWord    QUADWORD      {}
    HiQWord    QUADWORD      {}
  ends
OCTOWORD ends
POCTOWORD typedef OCTOWORD


; ==================================================================================================
;    Macro and procedure implementation
; ==================================================================================================

; --------------------------------------------------------------------------------------------------
; Macro:      Static
; Purpose:    Allocate a variable in the Data segment
; Arguments:  Arg1: Name.
;             Arg2: Type.
;             Arg3: Initial value.
; Return:     Nothing.

Static macro VarName:req, VarType:req, VarIni:=<?>
  .data
    VarName   VarType   VarIni
  .code
endm

; --------------------------------------------------------------------------------------------------
; Macro:      MemAlloc / $MemAlloc
; Purpose:    Allocate a memory block on global memory.
; Arguments:  Arg1: Memory block size. For Windows muust be less than 7FFF8h.
;             Arg2: Optional memory allocation flags:
;                   MEM_DEFAULT, MEM_INIT_ZERO, MEM_GENERATE_EXEPTION, MEM_NO_SERIALIZE.
; Return:     xax -> allocated memory block. NULL or exception if failed.
;             UEFI returns an mem block aligned to 8.

MEM_DEFAULT             equ   0
MEM_INIT_ZERO           equ   BIT00
MEM_GENERATE_EXEPTION   equ   BIT01
MEM_NO_SERIALIZE        equ   BIT02
MEM_NO_MOVE             equ   BIT03
MEM_SAFE_FREE           equ   BIT04

MemAlloc macro MemSize:req, Flags:=<MEM_DEFAULT>
  if TARGET_PLATFORM eq PLATFORM_WINDOWS
    $$MemAttr = MEM_DEFAULT
    if (Flags and MEM_INIT_ZERO)
      $$MemAttr = $$MemAttr or HEAP_ZERO_MEMORY
    endif
    if (Flags and MEM_GENERATE_EXEPTION)
      $$MemAttr = $$MemAttr or HEAP_GENERATE_EXCEPTIONS
    endif
    if (Flags and MEM_NO_SERIALIZE)
      $$MemAttr = $$MemAttr or HEAP_NO_SERIALIZE
    endif
    invoke HeapAlloc, hProcessHeap, $$MemAttr, MemSize
  elseif TARGET_PLATFORM eq PLATFORM_UEFI
    ifndef PLATFORM_UEFI_MEMORY
      PLATFORM_UEFI_MEMORY = EFI_MEMORY_TYPE_EfiBootServicesData
    endif
    invoke MemAlloc_UEFI, Flags, MemSize, PLATFORM_UEFI_MEMORY
  endif
  if DEBUGGING
    .if xax == NULL
      DbgWarning "MemAlloc failed"
    .endif
  endif
endm

$MemAlloc macro MemSize, Flags:=<0>
  MemAlloc <MemSize>, <Flags>
  exitm <xax>
endm

; --------------------------------------------------------------------------------------------------
; Macro:      MemReAlloc
; Purpose:    Reallocate a block of memory.
; Arguments:  Arg1: Memory POINTER obtained with MemAlloc/MemReAlloc.
;             Arg2: New memory block size.
;             Arg3: Optional memory allocation flags:
;                   MEM_INIT_ZERO, MEM_GENERATE_EXEPTION, MEM_NO_SERIALIZE, MEM_NO_MOVE
; Return:     xax -> allocated memory block. NULL or exception if failed.

MemReAlloc macro MemPtr:req, MemSize:req, Flags:=<0>
  if TARGET_PLATFORM eq PLATFORM_WINDOWS
    $$MemAttr = MEM_DEFAULT
    if (Flags and MEM_INIT_ZERO)
      $$MemAttr = $$MemAttr or HEAP_ZERO_MEMORY
    endif
    if (Flags and MEM_GENERATE_EXEPTION)
      $$MemAttr = $$MemAttr or HEAP_GENERATE_EXCEPTIONS
    endif
    if (Flags and MEM_NO_SERIALIZE)
      $$MemAttr = $$MemAttr or HEAP_NO_SERIALIZE
    endif
    if (Flags and MEM_NO_MOVE)
      $$MemAttr = $$MemAttr or HEAP_REALLOC_IN_PLACE_ONLY
    endif
    invoke HeapReAlloc, hProcessHeap, $$MemAttr, MemPtr, MemSize
    if DEBUGGING
      .if xax == FALSE
        DbgWarning "MemReAlloc failed"
      .endif
    endif
  elseif TARGET_PLATFORM eq PLATFORM_UEFI
    ;Not implemented
  endif
endm

$MemReAlloc macro MemPtr:req, MemSize:req, Flags:=<0>
  MemReAlloc <MemPtr>, <MemSize>, <Flags>
  exitm <xax>
endm

; --------------------------------------------------------------------------------------------------
; Macro:      MemFree
; Purpose:    Free a memory block previously allocated with MemAlloc or MemReAlloc.
; Arguments:  Arg1: -> allocated memory block.
;             Arg2: Optional memory allocation flags: MEM_NO_SERIALIZE, MEM_SAFE_FREE
; Return:     eax = TRUE if succeeded, otherwise FALSE.

MemFree macro MemPtr:req, Flags:=<0>
  if TARGET_PLATFORM eq PLATFORM_WINDOWS
    $$MemAttr = 0
    if (Flags and MEM_NO_SERIALIZE)
      $$MemAttr = $$MemAttr or HEAP_NO_SERIALIZE
    endif
    if (Flags and MEM_SAFE_FREE)
      .if MemPtr != NULL
        invoke HeapFree, hProcessHeap, $$MemAttr, MemPtr
        if DEBUGGING
          .if xax == FALSE
            DbgWarning "MemFree failed (1)"
          .endif
        endif
      .endif
    else
      invoke HeapFree, hProcessHeap, $$MemAttr, MemPtr
      if DEBUGGING
        .if xax == FALSE
          DbgWarning "MemFree failed (2)"
        .endif
      endif
    endif
  elseif TARGET_PLATFORM eq PLATFORM_UEFI
    if (Flags and MEM_SAFE_FREE)
      .if MemPtr != NULL
        invoke MemFree_UEFI, MemPtr
        if DEBUGGING
          .if xax != EFI_SUCCESS
            DbgWarning "MemFree failed (1)"
          .endif
        endif
      .endif
    else
      invoke MemFree_UEFI, MemPtr
      if DEBUGGING
        .if xax != EFI_SUCCESS
          DbgWarning "MemFree failed (2)"
        .endif
      endif
    endif
  endif
endm

; --------------------------------------------------------------------------------------------------
; Macro:      MemCheck
; Purpose:    Validates a memory block on the process heap.
; Arguments:  Arg1: -> allocated memory block. If NULL, the whole heap is checked.
; Return:     eax = non FALSE if succeeded, otherwise FALSE.

MemCheck macro MemPtr:=<NULL>
  if DEBUGGING
    invoke HeapValidate, hProcessHeap, HEAP_NO_SERIALIZE, MemPtr
    .if eax == 0
      DbgWarning "Process heap corrupted"
    .endif
  endif
endm

; --------------------------------------------------------------------------------------------------
; Macro:      (x)BitClear
; Purpose:    Reset a bit in a value.
; Arguments:  Arg1: Destination.
;             Arg2: Bit to be reset (ie: BIT12)
; Return:     Nothing.

BitClear macro Val:req, Bit:req
  and Val, not (Bit)
endm

xBitClear macro Val:req, Bit:req
  lock and Val, not (Bit)
endm

BitClr  equ <BitClear>
xBitClr equ <xBitClear>

; --------------------------------------------------------------------------------------------------
; Macro:      (x)BitMask
; Purpose:    AND a bit in a value.
; Arguments:  Arg1: Destination.
;             Arg2: Bit to be masked (ie: BIT12)
; Return:     Nothing.

BitMask macro Val:req, Bit:req
  and Val, (Bit)
endm

xBitMask macro Val:req, Bit:req
  lock and Val, (Bit)
endm

BitMsk  equ <BitMask>
xBitMsk equ <xBitMask>

; --------------------------------------------------------------------------------------------------
; Macro:      BitSet
; Purpose:    Set a bit in a value.
; Arguments:  Arg1: Destination.
;             Arg2: Bit to be set (ie: BIT15)
; Return:     Nothing.

BitSet macro Val:req, Bit:req
  or Val, (Bit)
endm

xBitSet macro Val:req, Bit:req
  lock or Val, (Bit)
endm

; --------------------------------------------------------------------------------------------------
; Macro:      (x)BitToggle
; Purpose:    Toggle a bit in a value.
; Arguments:  Arg1: Destination.
;             Arg2: Bit to be toggled (ie: BIT15)
; Return:     Nothing.

BitToggle macro Val:req, Bit:req
  xor Val, (Bit)
endm

xBitToggle macro Val:req, Bit:req
  lock xor Val, (Bit)
endm

BitTog  equ <BitToggle>
xBitTog equ <xBitToggle>

; --------------------------------------------------------------------------------------------------
; Macro:      .ifBitSet
; Purpose:    Start a conditional clauses, that must be terminated with .endif.
;             Examine if any of the indicated bits are set.
; Arguments:  Arg1: Bit holding variable.
;             Arg2: Bit to be tested for (ie: BIT12)
; Return:     Nothing.

.ifBitSet macro Var:req, Bit:req
  .if (Var & (Bit))
endm

.ifAnyBitSet equ <.ifBitSet>

; --------------------------------------------------------------------------------------------------
; Macro:      .elseIfBitSet
; Purpose:    Continue a conditional clauses, that must be terminated with .endif.
;             Examine if any of the indicated bits are set.
; Arguments:  Arg1: Bit holding variable.
;             Arg2: Bit to be tested for (ie: BIT12)
; Return:     Nothing.

.elseIfBitSet macro Var:req, Bit:req
  .elseif (Var & (Bit))
endm

.elseIfAnyBitSet equ <.elseIfBitSet>

; --------------------------------------------------------------------------------------------------
; Macro:      .ifBitClr
; Purpose:    Start a coditional clauses, that must be terminated with .endif.
;             Examine if all of the indicated bits are not set.
; Arguments:  Arg1: Bit holding variable.
;             Arg2: Bit to be tested for (ie: BIT12)
; Return:     Nothing.

.ifBitClr macro Var:req, Bit:req
  .if !(Var & (Bit))
endm

.ifAllBitsClr equ <.ifBitClr>

; --------------------------------------------------------------------------------------------------
; Macro:      .elseIfBitClr
; Purpose:    Start a coditional clauses, that must be terminated with .endif.
;             Examine if all of the indicated bits are not set.
; Arguments:  Arg1: Bit holding variable.
;             Arg2: Bit to be tested for (ie: BIT12)
; Return:     Nothing.

.elseIfBitClr macro Var:req, Bit:req
  .elseif !(Var & (Bit))
endm

.elseIfAllBitsClr equ <.elseIfBitClr>

; --------------------------------------------------------------------------------------------------
; Macro:      JmpIfBitSet
; Purpose:    Jump if a bit is set.
; Arguments:  Arg1: Bit holding variable.
;             Arg2: Bit to be tested for (ie: BIT12)
; Return:     Nothing.

JmpIfBitSet macro Var:req, Bit:req, Location:req
  test Var, (Bit)
  jnz Location
endm

; --------------------------------------------------------------------------------------------------
; Macro:      JmpIfBitClr
; Purpose:    Jump if a bit is not set.
; Arguments:  Arg1: Bit holding variable.
;             Arg2: Bit to be tested for (ie: BIT12)
; Return:     Nothing.

JmpIfBitClr macro Var:req, Bit:req, Location:req
  test Var, (Bit)
  jz Location
endm

; --------------------------------------------------------------------------------------------------
; Macro:      CloneGuid
; Purpose:    Copy the content of a GUID from a location to another.
; Arguments:  Arg1: Destination GUID.
;             Arg2: Source GUID.
;             Arg3: optional register to be used.
; Return:     Nothing.

if TARGET_BITNESS eq 32
  CloneGUID macro DstGUID:req, SrcGUID:req, AuxReg:=<>
    m2m DWORD ptr [DstGUID], DWORD ptr [SrcGUID], AuxReg
    m2m DWORD ptr [DstGUID + 04], DWORD ptr [SrcGUID + 04], AuxReg
    m2m DWORD ptr [DstGUID + 08], DWORD ptr [SrcGUID + 08], AuxReg
    m2m DWORD ptr [DstGUID + 12], DWORD ptr [SrcGUID + 12], AuxReg
  endm
else
  CloneGUID macro DstGUID:req, SrcGUID:req, AuxReg:=<>
    m2m QWORD ptr [DstGUID], QWORD ptr [SrcGUID], AuxReg
    m2m QWORD ptr [DstGUID + 08], QWORD ptr [SrcGUID + 08], AuxReg
  endm
endif

; --------------------------------------------------------------------------------------------------
; Macro:      ($)StackAlloc
; Purpose:    Reserve a chunk of memory from stack.
; Arguments:  Arg1: Requested memory size in bytes.
; Return:     rax -> Buffer begin.
; Notes:      StackAlloc and StackFree must always be paired and no values ought remain in the stack
;             between these macros.
;             Stack probing is performed automatically.

if TARGET_BITNESS eq 32
  StackAlloc macro AllocSize:req
  % ??Attributes = opattr(AllocSize)
    if ??Attributes eq 00100100y                        ;;Constant expression
      if AllocSize gt PAGESIZE
        ??StackCorr = PAGESIZE
        repeat AllocSize/PAGESIZE
          mov BYTE ptr [esp - ??StackCorr], 0           ;;Probe
          ??StackCorr = ??StackCorr + PAGESIZE
        endm
      endif
      sub esp, AllocSize
      mov eax, esp
      push AllocSize
    else
  %   ifdifi <AllocSize>, <eax>
        mov eax, AllocSize
      endif
  %   ifdifi <AllocSize>, <ecx>
        mov ecx, eax
      endif
      shr eax, $Log2(PAGESIZE)                        ;;Log2 PAGESIZE
      mov edx, -PAGESIZE
      .while !ZERO?
        mov BYTE ptr [esp + edx], 0                     ;;Probe
        sub edx, PAGESIZE
        dec eax
      .endw
      sub esp, ecx
      mov eax, esp
      push ecx
    endif
  endm
else
  StackAlloc macro AllocSize:req
  % ??Attributes = opattr(AllocSize)
    if ??Attributes eq 00100100y                        ;;Constant expression
      ??AllocSize = (AllocSize + 2*@WordSize - 1)/2*@WordSize ;Multiple of @WordSize
      if ??AllocSize gt PAGESIZE
        ??StackCorr = PAGESIZE
        repeat ??AllocSize/PAGESIZE
          mov BYTE ptr [rsp - ??StackCorr], 0           ;;Probe
          ??StackCorr = ??StackCorr + PAGESIZE
        endm
      endif
      sub rsp, ??AllocSize
      mov rax, rsp
      push ??AllocSize
    else
  %   ifdifi <AllocSize>, <rax>
        mov rax, AllocSize
      endif
      add rax, 2*@WordSize - 1
      and rax, -2*@WordSize
      mov rcx, rax
      shr rax, $Log2(PAGESIZE)                          ;;Log2 PAGESIZE
      mov rdx, -PAGESIZE
      .while !ZERO?
        mov BYTE ptr [rsp + rdx], 0                     ;;Probe
        sub rdx, PAGESIZE
        dec rax
      .endw
      sub rsp, rcx
      mov rax, rsp
      sub rsp, @WordSize
      add rcx, @WordSize
      push rcx
    endif
  endm
endif

$StackAlloc macro AllocSize:req
  StackAlloc AllocSize
  exitm <xax>
endm


; --------------------------------------------------------------------------------------------------
; Macro:      StackFree
; Purpose:    Release the reserved stack space with StackAlloc.
; Arguments:  None.
; Return:     Nothing.

StackFree macro
  pop xax
  add xsp, xax
endm
