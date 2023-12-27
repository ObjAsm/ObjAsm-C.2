; ==================================================================================================
; Title:      System.inc
; Author:     G. Friedrich
; Version:    C.2.0
; Purpose:    ObjAsm collection of useful macros.
; Notes:      Version C.1.0, October 2017
;               - First release.
;             Version C.1.1, August 2022
;               - WriteF macro added.
;             Version C.2.0, December 2022
;               - WriteF macro bug using AT corrected, V4/V6 & BI/BN/BZ added.
;               - lodsc macro added (a1sbofo).
;               - GetMemBSS macro added.
; ==================================================================================================


; WinDef.h definitions:
; 
; Type                        | S/U | x86    | x64
; ----------------------------+-----+--------+-------
; BYTE, BOOLEAN               |  U  | 8 bit  | 8 bit
; ----------------------------+-----+--------+-------
; SHORT                       |  S  | 16 bit | 16 bit
; USHORT, WORD                |  U  | 16 bit | 16 bit
; ----------------------------+-----+--------+-------
; INT, LONG                   |  S  | 32 bit | 32 bit
; UINT, ULONG, DWORD          |  U  | 32 bit | 32 bit
; ----------------------------+-----+--------+-------
; INT_PTR, LONG_PTR, LPARAM   |  S  | 32 bit | 64 bit
; UINT_PTR, ULONG_PTR, WPARAM |  U  | 32 bit | 64 bit
; ----------------------------+-----+--------+-------
; INT64, LONGLONG             |  S  | 64 bit | 64 bit
; UINT64, ULONGLONG, QWORD    |  U  | 64 bit | 64 bit


ALIGN_CODE = @WordSize
ALIGN_DATA = 2*@WordSize

MAGICROP        equ    0B8074Ah                         ;Raster operation code that allows halftones

;Equates for @Cpu symbol
CPU_286         equ    0000000000000100y                ;Use: if @Cpu and CPU_xxx ...
CPU_386         equ    0000000000001000y
CPU_486         equ    0000000000010000y
CPU_586         equ    0000000000100000y
CPU_686         equ    0000000001000000y
CPU_MODELS      equ    CPU_286 or CPU_386 or CPU_486 or CPU_586 or CPU_686
CPU_PRIVILEGED  equ    0000000010000000y

RAX_SUBREGS textequ <-RAX-EAX-AX-AL-AH->
RBX_SUBREGS textequ <-RBX-EBX-BX-BL-BH->
RCX_SUBREGS textequ <-RCX-ECX-CX-CL-CH->
RDX_SUBREGS textequ <-RDX-EDX-DX-DL-DH->
RDI_SUBREGS textequ <-RDI-EDI-DI-DIL->
RSI_SUBREGS textequ <-RSI-ESI-SI-SIL->
RBP_SUBREGS textequ <-RBP-EBP-BP-BPL->
RSP_SUBREGS textequ <-RSP-ESP-SP-SPL->
R8_SUBREGS  textequ <-R8-R8D-R8W-R8B->
R9_SUBREGS  textequ <-R9-R9D-R9W-R9B->
R10_SUBREGS textequ <-R10-R10D-R10W-R10B->
R11_SUBREGS textequ <-R11-R11D-R11W-R11B->
R12_SUBREGS textequ <-R12-R12D-R12W-R12B->
R13_SUBREGS textequ <-R13-R13D-R13W-R13B->
R14_SUBREGS textequ <-R14-R14D-R14W-R14B->
R15_SUBREGS textequ <-R15-R15D-R15W-R15B->

;Segment definitions:
;https://learn.microsoft.com/en-en/windows/win32/debug/pe-format
;Use different sections to cluster the data in each section and merge them using the linker
S_CONST   segment para readonly public                  ;.rdata, initialized
S_CONST   ends
S_TEXT    segment para readonly public                  ;like S_CONST
S_TEXT    ends
S_DATA    segment para public                           ;Read/Write = .data, initialized
S_DATA    ends
S_OBJID   segment para readonly public                  ;Object IDs = .rdata, initialized
S_OBJID   ends
S_OBJERR  segment para readonly public                  ;Object Errors = .rdata, initialized
S_OBJERR  ends
S_PROF    segment para public                           ;Read/Write - Profile data = .data, uninit.
S_PROF    ends

??WordChars textequ <ABCDEFGHIJKLMNOPQRSTUVWXYZ_?@>

FPU_CONTEXT struc 1
  wControlWord  WORD    ?
  wUnused0      WORD    ?
  wStatusWord   WORD    ?
  wUnused1      WORD    ?
  wTagWord      WORD    ?
  wUnused2      WORD    ?
  pInstruction  DWORD   ?
  wCodeSegment  WORD    ?
  wUnused3      WORD    ?
  pOperand      DWORD   ?
  wDataSegment  WORD    ?
  wUnused4      WORD    ?
  tST0          TBYTE   ?
  tST1          TBYTE   ?
  tST2          TBYTE   ?
  tST3          TBYTE   ?
  tST4          TBYTE   ?
  tST5          TBYTE   ?
  tST6          TBYTE   ?
  tST7          TBYTE   ?
  Filler        DWORD   ?     ;108 + 4 = 112 => multiple of 16!
FPU_CONTEXT ends
PFPU_CONTEXT typedef ptr FPU_CONTEXT

FPU_CONTEXT_SIZE = sizeof(FPU_CONTEXT)

XMM_CONTEXT_SIZE = 512        ;Storage memory must be aligned to 16

??StackAlignCount = 0         ;Used with StackAlign & StackRestore


;OpAttr test values   '   '   '   '
OAT_REFERENCE     equ 0000000000000001b   ;Reference to a code label
OAT_RELOCATABLE   equ 0000000000000010b   ;Memory variable ([xyz] or xyz, can contain a reg. [xax])
OAT_IMMEDIATE     equ 0000000000000100b   ;Immediate value
OAT_DIRECT_MEM    equ 0000000000001000b   ;Uses direct memory addressing

OAT_REGISTER      equ 0000000000010000b   ;Symbol is a register
OAT_NO_ERROR      equ 0000000000100000b   ;References not undefined and whitout error, usually 1
OAT_SS_RELATIVE   equ 0000000001000000b   ;SS relative
OAT_EXTERNAL      equ 0000000010000000b   ;References to an external label

OAT_LANGUAGE      equ 0000011100000000b   ;Test value
OAT_LANG_NONE     equ 0000000000000000b
OAT_LANG_C        equ 0000000100000000b
OAT_LANG_SYSCALL  equ 0000001000000000b
OAT_LANG_STDCALL  equ 0000001100000000b
OAT_LANG_PASCAL   equ 0000010000000000b
OAT_LANG_FORTRAN  equ 0000010100000000b
OAT_LANG_BASIC    equ 0000011000000000b

OAT_BIT_11        equ 0000100000000000b
OAT_BIT_12        equ 0001000000000000b
OAT_BIT_13        equ 0010000000000000b
OAT_BIT_14        equ 0100000000000000b
OAT_BIT_15        equ 1000000000000000b

; Notes:
;   036 = 0000 0000 0010 0100y = immediate operand or constant
;   037 = 0000 0000 0010 0101y = label, either local or global
;   042 = 0000 0000 0010 1010y = GLOBAL var
;   098 = 0000 0000 0110 0000y = LOCAL  var
;   048 = 0000 0000 0011 0000y = register
;   805 = 0000 0011 0010 0101y = local procedure in code
;   933 = 0000 0011 1010 0101y = external procedure or API call


if TARGET_BITNESS eq 64
  XAX   textequ   <rax>
  XBX   textequ   <rbx>
  XCX   textequ   <rcx>
  XDX   textequ   <rdx>
  XDI   textequ   <rdi>
  XSI   textequ   <rsi>
  XBP   textequ   <rbp>
  XSP   textequ   <rsp>
else
  XAX   textequ   <eax>
  XBX   textequ   <ebx>
  XCX   textequ   <ecx>
  XDX   textequ   <edx>
  XDI   textequ   <edi>
  XSI   textequ   <esi>
  XBP   textequ   <ebp>
  XSP   textequ   <esp>
endif

xax equ XAX
xbx equ XBX
xcx equ XCX
xdx equ XDX
xdi equ XDI
xsi equ XSI
xbp equ XBP
xsp equ XSP

if TARGET_BITNESS eq 32
  CPU_REGISTER union
    byte_     BYTE  ?
    word_     WORD  ?
    dword_    DWORD ?
    struct
      byte_lo BYTE  ?
      byte_hi BYTE  ?
    ends
  CPU_REGISTER ends
else
  CPU_REGISTER union
    byte_     BYTE  ?
    word_     WORD  ?
    dword_    DWORD ?
    qword_    QWORD ?
    struct
      byte_lo BYTE  ?
      byte_hi BYTE  ?
    ends
  CPU_REGISTER ends
endif

; ==================================================================================================
;    Macro implementation
; ==================================================================================================

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      $ArgRev
; Purpose:    Return a reversed order version of a symbol list.
; Arguments:  Arg1: Symbol list.
; Return:     Reversed symbol list.

$ArgRev macro ArgList:vararg
  $$RevList textequ <>
  %for $$RevArg, <ArgList>
    $$RevList CatStr <$$RevArg>, <!,>, $$RevList        ;;Add in reverse order
  endm

  ifnb $$RevList
    $$RevList SubStr $$RevList, 1, @SizeStr(%$$RevList) - 1 ;;Trim last comma
  endif

  exitm <$$RevList>
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      PushAll
; Purpose:    Push recursively all arguments on stack.
; Arguments:  Arg1: List of arguments.
; Return:     Nothing.

PushAll macro ArgList:vararg
  $$EaxUsed = FALSE
  %for $$Arg, <ArgList>
    ifnb <$$Arg>
      $$UArg textequ $Upper($$Arg)
      if $$EaxUsed ne FALSE
        $$IsEax = FALSE
        $$EaxPos InStr 1, $$UArg, <EAX>
        if $$EaxPos ne 0
           $$IsEax = TRUE
          if $$EaxPos gt 1
            if @InStr(1, %??WordChars, @SubStr(%$$UArg, $$EaxPos - 1, 1)) gt 0
              $$IsEax = FALSE
            endif
          endif
          if ( $$EaxPos ne 0 and $$EaxPos le @SizeStr(%$$UArg) - 3)
            if @InStr(1, %??WordChars, @SubStr(%$$UArg, $$EaxPos + 3, 1)) gt 0
              $$IsEax = FALSE
            endif
          endif
        endif
        if $$IsEax ne FALSE
          .err <EAX register already in use.>
          exitm
        else
          $$EaxPos InStr 1, $$UArg, <AX>
          if $$EaxPos ne 0
            $$IsEax = TRUE
            if $$EaxPos gt 1
              if @InStr(1, %??WordChars, @SubStr(%$$UArg, $$EaxPos - 1, 1)) gt 0
                $$IsEax = FALSE
              endif
            endif
            if ($$EaxPos ne 0 and $$EaxPos le @SizeStr(%$$UArg) - 2)
              if @InStr(1, %??WordChars, @SubStr(%$$UArg, $$EaxPos + 2, 1)) gt 0
                $$IsEax = FALSE
              endif
            endif
          endif
        endif
        if $$IsEax ne FALSE
          .err <AX register already in use.>
          exitm
        else
           $$EaxPos InStr 1, $$UArg, <AL>
          if $$EaxPos ne 0
             $$IsEax = TRUE
            if $$EaxPos gt 1
              if @InStr(1, %??WordChars, @SubStr(%$$UArg, $$EaxPos - 1, 1)) gt 0
                $$IsEax = FALSE
              endif
            endif
            if ($$EaxPos ne 0 and  $$EaxPos le @SizeStr(%$$UArg) - 2)
              if @InStr(1, %??WordChars, @SubStr(%$$UArg, $$EaxPos + 2, 1)) gt 0
                $$IsEax = FALSE
              endif
            endif
          endif
        endif
        if $$IsEax ne FALSE
          .err <AL register already in use.>
          exitm
        endif
      endif

      $$Pos1 InStr 1, $$UArg, <ADDR >
      if $$Pos1 eq 1
        $$Attributes = opattr(@SubStr($$Arg, $$Pos1 + 5))
        if ($$Attributes eq (OAT_RELOCATABLE or OAT_NO_ERROR)) or \
           ($$Attributes eq (OAT_RELOCATABLE or OAT_NO_ERROR or OAT_SS_RELATIVE))
          $$EaxUsed = TRUE
          lea eax, @SubStr($$Arg, 6)
          push eax
        else
          if @InStr(6, $$Arg, <[>)
            $$EaxUsed = TRUE
            lea eax, @SubStr($$Arg, 6)
            push eax
          else
            push offset(@SubStr($$Arg, 6))
          endif
        endif
      else
        if $IsFloat($$Arg)
          db 68h
          REAL4 $$Arg                                   ;;push REAL4 value
        else
          push $$Arg                                    ;;push one argument and repeat
        endif
      endif
    endif
  endm
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      PopAll
; Purpose:    Pop a list of arguments of the stack.
; Arguments:  Arg1: List of arguments.
; Return:     Nothing.

PopAll macro ArgList:vararg
  %for $$Arg, <ArgList>
    pop $$Arg                                           ;;push one argument and repeat
  endm
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      PushAllRev
; Purpose:    Push all arguments on stack in reverse order.
; Arguments:  Arg1: List of arguments.
; Return:     Nothing.

PushAllRev macro ArgList:vararg
  PushAll $ArgRev(ArgList)
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      PopAllRev
; Purpose:    Pop recursively all arguments on stack in reverse order.
; Arguments:  Arg1: List of arguments.
; Return:     Nothing.

PopAllRev macro ArgList:vararg
  $$ArgList textequ $ArgRev(ArgList)
  %for $$Arg, <$$ArgList>
    pop $$Arg                                           ;;pop one argument and repeat
  endm
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      c2m
; Purpose:    Move a constant value to a QWORD, DWORD, WORD or BYTE memory address.
; Arguments:  Arg1: destination memory symbol.
;             Arg2: source constant value.
;             Arg3: register used to move the memory content. If not specified, r13 is used.
; Return:     Nothing.

c2m macro DstMem:req, SrcCst:req, AuxReg
  $$DstSize = type(DstMem)

  if (opattr SrcCst) and (OAT_IMMEDIATE or OAT_REFERENCE)  ;;Is an immediate or reference value
    if (opattr DstMem) and OAT_REGISTER                    ;;If DstMem is a register
      .err c2m - destination argument is not a memory address
      exitm
    endif

    if $$DstSize le 4
      mov DstMem, SrcCst
    else
      ifb <AuxReg>
        .err c2m - Auxiliary register required!
      else
        mov $SubReg(AuxReg, 8), SrcCst                     ;;Use mov in combination with AuxReg
        mov DstMem, $SubReg(AuxReg, 8)
      endif
    endif
  else
    %echo $ToStr(%opattr(SrcCst))
    .err c2m - source argument is not a constant value!
  endif
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      m2m
; Purpose:    Move a QWORD, DWORD, WORD or BYTE value from a memory address to another.
;             Auxiliary register may not be used.
; Arguments:  Arg1: Destination memory symbol.
;             Arg2: Source memory symbol.
;             Arg3: Auxiliary register used to move the memory content.
;                   If not specified, the stack may be used.
; Return:     Nothing.

m2m macro DstMem:req, SrcMem:req, AuxReg
  $$DstSize = type(DstMem)
  if (opattr SrcMem) and (OAT_IMMEDIATE or OAT_REFERENCE)   ;;Is an immediate or reference value
    $$SrcSize = $$DstSize
  else
    $$SrcSize = type(SrcMem)
  endif

  if $$DstSize eq 0
    if $$SrcSize eq 0
      $$DstSize = @WordSize
      $$SrcSize = @WordSize
    else
      $$DstSize = $$SrcSize
    endif
  elseif $$SrcSize eq 0
    $$SrcSize = $$DstSize
  endif

  if (opattr DstMem) and OAT_REGISTER                   ;;If DstMem is a register
    if $$DstSize eq $$SrcSize
      mov DstMem, SrcMem                                ;;use mov
    elseif $$DstSize gt $$SrcSize
      if $$DstSize eq 8 and $$SrcSize eq 4
        mov $SubReg(DstMem, 4), SrcMem
      else
        movzx DstMem, SrcMem
      endif
    else
      .err m2m - destination size is smaller than source size!
    endif
  else
    if ((opattr SrcMem) and OAT_REGISTER) and ($$DstSize eq $$SrcSize)
      mov DstMem, SrcMem                                ;;use mov
    else
      ifb <AuxReg>
        if TARGET_BITNESS eq 64
          .err m2m - Not supported in 64 bit mode without an auxiliar register!
        else
          if ($$SrcSize eq @WordSize) and ($$DstSize eq @WordSize)
            push DWORD ptr SrcMem
            pop DWORD ptr DstMem
          else
            .err m2m - Can not transfer different different argument sizes without an auxiliar register!
          endif
        endif
      else
        if (opattr SrcMem) and OAT_REGISTER             ;;If SrcMem is a register
          if $$DstSize gt $$SrcSize
            if $$DstSize eq 8
              if $$SrcSize eq 4
                mov $SubReg(AuxReg, 4), SrcMem
              else
                movzx $SubReg(AuxReg, 4), SrcMem
              endif
            else
              movzx $SubReg(AuxReg, $$DstSize), SrcMem  ;;use movzx; sign expansion is not supported
            endif
            mov DstMem, $SubReg(AuxReg, $$DstSize)
          elseif $$DstSize eq $$SrcSize
            mov DstMem, SrcMem
          else
            .err m2m - destination size is smaller than source size!
          endif
        else
          if $$DstSize eq $$SrcSize
            if (opattr SrcMem) and (OAT_IMMEDIATE or OAT_REFERENCE)
              if $$DstSize le 4
                mov DstMem, SrcMem
              else
                mov $SubReg(AuxReg, $$SrcSize), SrcMem  ;;Use mov in combination with AuxReg
                mov DstMem, $SubReg(AuxReg, $$DstSize)
              endif
            else
              mov $SubReg(AuxReg, $$SrcSize), SrcMem    ;;Use mov in combination with AuxReg
              mov DstMem, $SubReg(AuxReg, $$DstSize)
            endif
          elseif $$DstSize gt $$SrcSize
            if $$DstSize eq 8
              if $$SrcSize eq 4
                mov $SubReg(AuxReg, 4), SrcMem
              else
                movzx $SubReg(AuxReg, 4), SrcMem
              endif
            else
              movzx $SubReg(AuxReg, $$DstSize), SrcMem  ;;use movzx; sign expansion is not supported
            endif
            mov DstMem, $SubReg(AuxReg, $$DstSize)
          else
            .err m2m - destination size is smaller than source size!
          endif
        endif
      endif
    endif
  endif
endm
; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      mrm
; Purpose:    Move a QWORD, DWORD, WORD or BYTE value from a memory address to another using
;             always the auxiliary register.
; Arguments:  Arg1: destination memory symbol.
;             Arg2: source memory symbol.
;             Arg3: register used to move the memory content.
; Return:     Nothing.

mrm macro DstMem:req, SrcMem:req, AuxReg:req
  $$DstSize = type(DstMem)
  if (opattr SrcMem) and (OAT_IMMEDIATE or OAT_REFERENCE)   ;;Is an immediate or reference value
    $$SrcSize = $$DstSize
  else
    $$SrcSize = type(SrcMem)
  endif
  if $$DstSize eq 0
    if $$SrcSize eq 0
      $$DstSize = @WordSize
      $$SrcSize = @WordSize
    else
      $$DstSize = $$SrcSize
    endif
  elseif $$SrcSize eq 0
    $$SrcSize = $$DstSize
  endif

  if (opattr DstMem) and OAT_REGISTER                   ;;If DstMem is a register
    if $$DstSize eq $$SrcSize
      mov $SubReg(AuxReg, $$SrcSize), SrcMem
      mov DstMem, SrcMem
    elseif $$DstSize eq 8 and $$SrcSize eq 4            ;;Special case
      mov $SubReg(AuxReg, $$SrcSize), SrcMem
      mov $SubReg(DstMem, $$SrcSize), SrcMem            ;;High32 are zeroed automatically by the CPU
    elseif $$DstSize gt $$SrcSize
      movzx $SubReg(AuxReg, $$DstSize), SrcMem
      mov DstMem, $SubReg(AuxReg, $$DstSize)
    else
      .err mrm - destination size is smaller than source size!
    endif
  elseif (opattr SrcMem) and OAT_REGISTER               ;;If SrcMem is a register
    if $$DstSize eq $$SrcSize
      mov $SubReg(AuxReg, $$SrcSize), SrcMem
      mov DstMem, $SubReg(AuxReg, $$SrcSize)
    elseif $$DstSize eq 8 and $$SrcSize eq 4            ;;Special case
      mov $SubReg(AuxReg, $$SrcSize), SrcMem
      mov DstMem, $SubReg(AuxReg, $$DstSize)
    elseif $$DstSize gt $$SrcSize
      movzx $SubReg(AuxReg, $$DstSize), SrcMem
      mov DstMem, $SubReg(AuxReg, $$DstSize)
    else
      .err mrm - destination size is smaller than source size!
    endif
  else
    if $$DstSize eq $$SrcSize
      mov $SubReg(AuxReg, $$SrcSize), SrcMem
      mov DstMem, $SubReg(AuxReg, $$SrcSize)
    elseif $$DstSize eq 8 and $$SrcSize eq 4            ;;Special case
      mov $SubReg(AuxReg, $$SrcSize), SrcMem
      mov DstMem, $SubReg(AuxReg, $$DstSize)
    elseif $$DstSize gt $$SrcSize
      movzx $SubReg(AuxReg, $$DstSize), SrcMem
      mov DstMem, $SubReg(AuxReg, $$DstSize)
    else
      .err mrm - destination size is smaller than source size!
    endif
  endif
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      m2z
; Purpose:    Zero the content of a memory location.
; Arguments:  Arg1: Memory location.
; Return:     Nothing.
; Note:       On older CPUs, like a PIII, "and DstMem, 0" is faster than "mov DstMem, 0".

m2z macro DstMem:req
  mov DstMem, 0
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      s2s
; Purpose:    Clone a structure to another structure of the same type.
; Arguments:  Arg1: Destination structure.
;             Arg2: Source structure. Structure size must match the destination structure!
;             Arg3: Available registers for the copy operation.
; Return:     Nothing.
; Note:       Use only AVX istructions to avoid AVX/SSE transition penalties.
;             Try using vmovdqu later.

s2sCpy macro Get, Put, RegSelector, RegType, UsedRegSize, DstStruc, SrcStruc, RegList, RegCnt
  ;Do copy using the indicated registers and instructions
  $$RegsUsed = 0
  $$RegSize = type(RegType)
  repeat ((($$DstStrucSize and -$$RegSize)/$$RegSize) + RegCnt - 1)/RegCnt
    ;Load into registers
    for $$Reg, <RegList>
      if $$SrcStrucSize ge $$RegSize
        Get RegSelector($$Reg, UsedRegSize), RegType ptr SrcStruc[$$SrcOffset]
        $$SrcStrucSize = $$SrcStrucSize - $$RegSize
        $$SrcOffset = $$SrcOffset + $$RegSize
        $$RegsUsed = $$RegsUsed + 1
        if $$RegsUsed gt RegCnt
          $$RegsUsed = 1                                ;Cycle again from the beginning
        endif
      endif
    endm
    ;Write to memory
    for $$Reg, <RegList>
      if $$DstStrucSize ge $$RegSize
        Put RegType ptr DstStruc[$$DstOffset], RegSelector($$Reg, UsedRegSize)
        $$DstStrucSize = $$DstStrucSize - $$RegSize
        $$DstOffset = $$DstOffset + $$RegSize
      endif
    endm
  endm

  ;Rotate regs if necessary
  if $$RegsUsed eq 1
    if RegCnt gt 1
      $$Pos1 instr 1, <RegList>, <,>
      if $$Pos1 ne 0
        $$sz1 SubStr <RegList>, $$Pos1 + 1
        $$sz2 SubStr <RegList>, 1, $$Pos1 - 1
        exitm @CatStr(<$$sz1>, <,>, <$$sz2>)
      endif
    endif
  endif
  exitm <RegList>
endm

s2s macro Dst:req, Src:req, RegList:vararg
  ;Build register lists
  $$LstRegMM textequ <>
  $$RegCntMM = 0
  $$LstRegGP textequ <>
  $$RegCntGP = 0
  for $$Reg, <RegList>
    $$Pos1 Instr 1, <$$Reg>, <mm>
    if $$Pos1 ne 0
      $$LstRegMM CatStr $$LstRegMM, <,>, <$$Reg>
      $$RegCntMM = $$RegCntMM + 1
    else
      $$LstRegGP CatStr $$LstRegGP, <,>, <$$Reg>
      $$RegCntGP = $$RegCntGP + 1
    endif
  endm

  if @SizeStr(%$$LstRegMM) ne 0
    $$LstRegMM SubStr $$LstRegMM, 2
  endif
  if @SizeStr(%$$LstRegGP) ne 0
    $$LstRegGP SubStr $$LstRegGP, 2
  endif

  ;Start copying
  $$SrcStrucSize = type(Src)
  $$DstStrucSize = type(Dst)

  ;*************************************************************************************************
  ;$$RegCntMM = 0   ;Uncomment to skip MM regs for older CPUs that don't support vector instructions
  ;*************************************************************************************************

  if $$SrcStrucSize eq $$DstStrucSize
    $$SrcOffset = 0
    $$DstOffset = 0
    ;32 and 16 bytes: try first with mm registers
    if $$RegCntMM ne 0
      $$LstRegMM textequ s2sCpy(vmovups, vmovups, $SubRegMM, ymmword, 32, Dst, Src, %$$LstRegMM, %$$RegCntMM)
      $$LstRegMM textequ s2sCpy(vmovups, vmovups, $SubRegMM, xmmword, 16, Dst, Src, %$$LstRegMM, %$$RegCntMM)
    endif

    ;8 bytes:
    if TARGET_BITNESS eq 32
      if $$RegCntMM ne 0
        $$LstRegMM textequ s2sCpy(vmovlps, vmovlps, $SubRegMM, mmword, 16, Dst, Src, %$$LstRegMM, %$$RegCntMM)
      endif
    else
      ;In 64 bit: try first with gp registers and then with mm registers
      if $$RegCntGP ne 0
        $$LstRegGP textequ s2sCpy(mov, mov, $SubReg, QWORD, 8, Dst, Src, %$$LstRegGP, %$$RegCntGP)
      elseif $$RegCntMM ne 0
        $$LstRegMM textequ s2sCpy(vmovlps, vmovlps, $SubRegMM, mmword, 16, Dst, Src, %$$LstRegMM, %$$RegCntMM)
      endif
    endif

    ;Rest: use always general purpose registers
    if $$RegCntGP ne 0
      $$LstRegGP textequ s2sCpy(mov, mov, $SubReg, DWORD, 4, Dst, Src, %$$LstRegGP, %$$RegCntGP)
      $$LstRegGP textequ s2sCpy(mov, mov, $SubReg,  WORD, 2, Dst, Src, %$$LstRegGP, %$$RegCntGP)
      $$LstRegGP textequ s2sCpy(mov, mov, $SubReg,  BYTE, 1, Dst, Src, %$$LstRegGP, %$$RegCntGP)
    else
      .err <s2s - register list required>
    endif
  else
    .err <s2s - different structure sizes>
  endif
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      JumpOn
; Purpose:    Create a jump table and executes a jump to a label according the content of a
;             register.
; Arguments:  Arg1: Case register.
;             Arg2: Jump labels.
; Return:     Nothing.
; Example:    JumpOn eax, @@10, @@20, @@30

JumpOn macro RegName:req, Labels:vararg
  local JumpTable

  .const
  $$Count = 0
  for $$Arg, <Labels>
    ife $$Count
      JumpTable  POINTER  offset($$Arg)
    else
      POINTER  offset($$Arg)
    endif
    $$Count = $$Count + 1
  endm

  .code
  cmp RegName, $$Count
  jae @F
  if TARGET_BITNESS eq 32
    jmp POINTER ptr [offset(JumpTable) + sizeof(POINTER)*RegName]
  else
    shl RegName, $Log2(sizeof(POINTER))
    mov r10, offset(JumpTable)
    jmp POINTER ptr [RegName + r10]
  endif
@@:
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      FillStringA
; Purpose:    Fill an ANSI string with text using a series of mov DWORD/WORD/BYTE instructions.
;             It doesn't work with QWORDs.
; Arguments:  Arg1: String to be filled.
;             Arg2: Text.
; Return:     $$Len = Number of copied chars, excluding the ZTC.
;             $$Size = Number of BYTEs copied, including the ZTC.
; Example:    FillStringA myString, <Hello>

FillStringA macro StrVar:req, Text:req
  $$Len = 0
  $$j = 0
  forc $$Char, <Text>
    $$j = ('&$$Char' shl (($$Len and 3) * 8)) + $$j
    if ($$Len and 3) eq 3
      mov DWORD ptr StrVar[($$Len and -4)], $$j
      $$j = 0
    endif
    $$Len = $$Len + 1
  endm

  if ($$Len and 3) eq 0
    m2z BYTE ptr StrVar[$$Len]
  elseif ($$Len and 3) eq 1
    mov WORD ptr StrVar[$$Len - 1], $$j
  elseif ($$Len and 3) eq 2
    mov WORD ptr StrVar[$$Len - 2], $$j
    m2z BYTE ptr StrVar[$$Len]
  else
    mov DWORD ptr StrVar[($$Len - 3)], $$j
  endif
  $$Size = $$Len + 1
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      FillStringB
; Purpose:    Fill a BSTR string with text using a series of mov DWORD/WORD/BYTE instructions.
;             It doesn't work with QWORDs.
; Arguments:  Arg1: String to be filled.
;             Arg2: Text.
; Return:     $$Len = Number of copied chars, excluding the ZTC.
;             $$Size = Number of BYTEs copied, including the ZTC and header DWORD.
; Example:    FillStringB myString, <Hello>

FillStringB macro StrVar:req, Text:req
  $$Len = 0
  $$j = 0
  forc $$Char, <Text>
    $$j = ('&$$Char' shl (($$Len and 1) * 16)) + $$j
    if ($$Len and 1) eq 1
      mov DWORD ptr StrVar[($$Len and -2)*2 + 4], $$j
      $$j = 0
    endif
    $$Len = $$Len + 1
  endm

  if ($$Len and 1) eq 0
    m2z WORD ptr StrVar[$$Len*2 + 4]
  elseif ($$Len and 1) eq 1
    mov DWORD ptr StrVar[($$Len - 1)*2 + 4], $$j
  endif

  mov DWORD ptr StrVar[0], 2*$$Len                      ;;Set byte count
  $$Size = sizeof(WORD)*($$Len + 1) + sizeof(DWORD)
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      FillStringW
; Purpose:    Fill a UNICODE string with text using a series of mov DWORD/WORD/BYTE
;             instructions.
; Arguments:  Arg1: String to be filled.
;             Arg2: Text.
; Return:     $$Len = Number of copied chars, excluding the ZTC.
;             $$Size = Number of BYTEs copied, including the ZTC.
; Example:    FillStringW myString, <Hello>

FillStringW macro StrVar:req, Text:req
  $$Len = 0
  $$j = 0
  forc $$Char, <Text>
    $$j = ('&$$Char' shl (($$Len and 1) * 16)) + $$j
    if ($$Len and 1) eq 1
      mov DWORD ptr StrVar[($$Len and -2)*2], $$j
      $$j = 0
    endif
    $$Len = $$Len + 1
  endm

  if ($$Len and 1) eq 0
    m2z WORD ptr StrVar[$$Len*2]
  elseif ($$Len and 1) eq 1
    mov DWORD ptr StrVar[($$Len - 1)*2], $$j
  endif
  $$Size = sizeof(WORD)*($$Len + 1)
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————

if TARGET_STR_TYPE eq STR_TYPE_ANSI
  FillString equ FillStringA
elseif TARGET_STR_TYPE eq STR_TYPE_WIDE
  FillString equ FillStringW
else
  .echo <FillString is undefined>
endif

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      FillWordA
; Purpose:    Fill with a sequence of ANSI characters using a series of mov DWORD/WORD/BYTE.
;             It doesn't work with QWORDs.
; Arguments:  Arg1: String to be filled.
;             Arg2: Text.
; Return:     $$Len = Number of copied chars.
;             $$Size = Number of BYTEs copied.
; Example:    FillWordA myBuffer, <Hello>

FillWordA macro StrVar:req, Text:req
  $$Len = 0
  $$j = 0
  forc $$Char, <Text>
    $$j = ('&$$Char' shl (($$Len and 3) * 8)) + $$j
    if ($$Len and 3) eq 3
      mov DWORD ptr StrVar[($$Len and -4)], $$j
      $$j = 0
    endif
    $$Len = $$Len + 1
  endm

  if ($$Len and 3) eq 1
    mov BYTE ptr StrVar[$$Len - 1], $$j
  elseif ($$Len and 3) eq 2
    mov WORD ptr StrVar[$$Len - 2], $$j
  elseif ($$Len and 3) eq 3
    mov WORD ptr StrVar[$$Len - 3], $$j and 0FFFFh
    mov BYTE ptr StrVar[$$Len - 1], $$j shr 16
  endif
  $$Size = $$Len
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      FillWordW
; Purpose:    Fill with a sequence of WIDE characters using a series of mov DWORD/WORD.
;             It doesn't work with QWORDs.
; Arguments:  Arg1: String to be filled.
;             Arg2: Text.
; Return:     $$Len = Number of copied chars.
;             $$Size = Number of BYTEs copied.
; Example:    FillWordW myBuffer, <Hello>

FillWordW macro StrVar:req, Text:req
  $$Len = 0
  $$j = 0
  forc $$Char, <Text>
    $$j = ('&$$Char' shl (($$Len and 1) * 16)) + $$j
    if ($$Len and 1) eq 1
      mov DWORD ptr StrVar[($$Len and -2)*2], $$j
      $$j = 0
    endif
    $$Len = $$Len + 1
  endm

  if ($$Len and 1) eq 1
    mov WORD ptr StrVar[($$Len - 1)*2], $$j
  endif
  $$Size = sizeof(WORD)*$$Len
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————

if TARGET_STR_TYPE eq STR_TYPE_ANSI
  FillWord equ FillWordA
elseif TARGET_STR_TYPE eq STR_TYPE_WIDE
  FillWord equ FillWordW
else
  .echo <FillWord is undefined>
endif

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      DoesWordMatchA?
; Purpose:    Compare a sequence of ANSI characters with a text using a series of
;             cmp DWORD/WORD/BYTE instructions.
; Arguments:  Arg1: Location containing the word to be compared.
;             Arg2: Text.
; Return:     In case that NoMatchLabel is not specified use the flags.
;             ZERO? indicates that the word matches.
; Example:    DoesWordMatchA? myWord, <Hello>
;             DoesWordMatchA? myWord, !<  >
; Note:       Arg1 must have read access for the size of Arg2!

DoesWordMatchA? macro StrVar:req, Text:req, NoMatchLabel
  local ExitLabel

  $$i = 0
  $$j = 0
  $$k SizeStr <Text>
  forc $$Char, <Text>
    $$j = ('&$$Char' shl (($$i and 3)*8)) + $$j

    if ($$i and 3) eq 3
      cmp DWORD ptr StrVar[($$i and -4)], $$j
      ifb <NoMatchLabel>
        if $$k ne $$i + 1                               ;;Supress last "jne" instruction
          jne ExitLabel
        endif
      else
        jne NoMatchLabel
      endif
      $$j = 0
    endif
    $$i = $$i + 1
  endm

  if ($$i and 3) eq 1
    cmp BYTE ptr StrVar[$$i - 1], $$j
  elseif ($$i and 3) eq 2
    cmp WORD ptr StrVar[$$i - 2], $$j
  elseif ($$i and 3) eq 3
    cmp WORD ptr StrVar[$$i - 3], ($$j and 0000FFFFh)
    ifb <NoMatchLabel>
      jne ExitLabel
    else
      jne NoMatchLabel
    endif
    cmp BYTE ptr StrVar[$$i - 1], ($$j shr 16)
  endif
  ifnb <NoMatchLabel>
    jne NoMatchLabel
  endif
ExitLabel:
endm

$DoesWordMatchA? macro StrVar:req, Text:req
  DoesWordMatchA? StrVar, Text
  exitm <ZERO?>
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      DoesWordMatchW?
; Purpose:    Compare a sequence of WIDE characters with a text using a series of
;             cmp DWORD/WORD instructions.
; Arguments:  Arg1: Location containing the word to be compared.
;             Arg2: Text.
; Return:     In case that NoMatchLabel is not specified use the flags.
;             ZERO? indicates that the word matches.
; Example:    DoesWordMatchW? myWord, <Hello>
;             DoesWordMatchW? myWord, !<  >
; Note:       Arg1 must have read access for the size of Arg2!

DoesWordMatchW? macro StrVar:req, Text:req, NoMatchLabel
  local ExitLabel

  $$i = 0
  $$j = 0
  $$k SizeStr <Text>
  forc $$Char, <Text>
    $$j = ('&$$Char' shl (($$i and 1)*16)) + $$j

    if ($$i and 1) eq 1
      cmp DWORD ptr StrVar[($$i and -2)*2], $$j
      ifb <NoMatchLabel>
        if $$k ne $$i + 1                               ;;Supress last "jne" instruction
          jne ExitLabel
        endif
      else
        jne NoMatchLabel
      endif
      $$j = 0
    endif
    $$i = $$i + 1
  endm

  if ($$i and 1) eq 1
    cmp WORD ptr StrVar[($$i and -2)*2], $$j
  endif
  ifnb <NoMatchLabel>
    jne NoMatchLabel
  endif
ExitLabel:
endm

$DoesWordMatchW? macro StrVar:req, Text:req
  DoesWordMatchW? StrVar, Text
  exitm <ZERO?>
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————

if TARGET_STR_TYPE eq STR_TYPE_ANSI
  DoesWordMatch? equ DoesWordMatchA?
  $DoesWordMatch? equ $DoesWordMatchA?
elseif TARGET_STR_TYPE eq STR_TYPE_WIDE
  DoesWordMatch? equ DoesWordMatchW?
  $DoesWordMatch? equ $DoesWordMatchW?
else
  .echo <DoesWordMatch? is undefined>
endif

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      DoesStringMatchA?
; Purpose:    Compare a string of ANSI characters with a text using a series of
;             cmp DWORD/WORD/BYTE instructions. The ZTC is included in the comparison.
; Arguments:  Arg1: Location containing the string to be compared.
;             Arg2: Text.
; Return:     In case that NoMatchLabel is not specified use the flags.
;             Zero indicates that the word matches.
; Example:    DoesStringMatchA? myString, <Hello>
; Note:       Arg1 must have read access for the size of Arg2!

DoesStringMatchA? macro StrVar:req, Text:req, NoMatchLabel
  local ExitLabel

  $$i = 0
  $$j = 0
  forc $$Char, <Text>
    $$j = ('&$$Char' shl (($$i and 3)*8)) + $$j

    if ($$i and 3) eq 3
      cmp DWORD ptr StrVar[($$i and -4)], $$j
      ifb <NoMatchLabel>
        if @SizeStr(&Text) ne $$i                       ;;Supress last "jne"
          jne ExitLabel
        endif
      else
        jne NoMatchLabel
      endif
      $$j = 0
    endif
    $$i = $$i + 1
  endm

  if ($$i and 3) eq 0
    cmp BYTE ptr StrVar[$$i], 0
  elseif ($$i and 3) eq 1
    cmp WORD ptr StrVar[$$i - 1], $$j
  elseif ($$i and 3) eq 2
    cmp WORD ptr StrVar[$$i - 2], $$j
    ifb <NoMatchLabel>
      jne ExitLabel
    else
      jne NoMatchLabel
    endif
    cmp BYTE ptr StrVar[$$i], 0
  elseif ($$i and 3) eq 3
    cmp DWORD ptr StrVar[$$i - 3], ($$j and 00FFFFFFh)
  endif
  ifnb <NoMatchLabel>
    jne NoMatchLabel
  endif
ExitLabel:
endm

$DoesStringMatchA? macro StrVar:req, Text:req
  DoesStringMatchA? StrVar, Text
  exitm <ZERO?>
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      DoesStringMatchW?
; Purpose:    Compare a string of WIDE characters with a text using a series of
;             cmp DWORD/WORD instructions. The ZTC is included in the comparison.
; Arguments:  Arg1: Location containing the string to be compared.
;             Arg2: Text.
; Return:     In case that NoMatchLabel is not specified use the flags.
;             Zero indicates that the word matches.
; Example:    DoesStringMatchW? myString, <Hello>
; Note:       Arg1 must have read access for the size of Arg2!

DoesStringMatchW? macro StrVar:req, Text:req, NoMatchLabel
  local ExitLabel

  $$i = 0
  $$j = 0
  forc $$Char, <Text>
    $$j = ('&$$Char' shl (($$i and 1)*16)) + $$j

    if ($$i and 1) eq 1
      cmp DWORD ptr StrVar[($$i and -2)*2], $$j
      ifb <NoMatchLabel>
        jne ExitLabel
      else
        jne NoMatchLabel
      endif
      $$j = 0
    endif
    $$i = $$i + 1
  endm

  if ($$i and 1) eq 1
    cmp DWORD ptr StrVar[($$i and -2)*2], $$j
  else
    cmp WORD ptr StrVar[($$i and -2)*2], 0
  endif
  ifnb <NoMatchLabel>
    jne NoMatchLabel
  endif
ExitLabel:
endm

$DoesStringMatchW? macro StrVar:req, Text:req
  DoesStringMatchW? StrVar, Text
  exitm <ZERO?>
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————

if TARGET_STR_TYPE eq STR_TYPE_ANSI
  DoesStringMatch? equ DoesStringMatchA?
  $DoesStringMatch? equ $DoesStringMatchA?
elseif TARGET_STR_TYPE eq STR_TYPE_WIDE
  DoesStringMatch? equ DoesStringMatchW?
  $DoesStringMatch? equ $DoesStringMatchW?
else
  .echo <DoesStringMatch? is undefined>
endif

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      WriteF
; Purpose:    Write a formated string to memory. If format includes format specifiers (subsequences
;             beginning with ¦), the additional arguments following format are formatted & inserted
;             in the resulting string replacing their respective specifiers.
;             Escape sequences are supported to overcome MASM limitations. Escape sequences begin
;             with a \ character.
; Arguments:  Arg1: Non-volatile register pointing to the beginning of the output buffer.
;                   It is used internally and its value is restored before return.
;             Arg2: Single or double Quoted format string. Only ANSI characters are allowed.
;                   format specifiers start with the "¦" character, followed by 2 characters
;                   specifying the type (and the decimal places for floating-point numbers) of the
;                   subsequent arguments.
;             Arg3-N: Additional arguments. Must be non-volatile registers, FPU registers or
;                   memory symbols.
; Return:     On return Arg1 points to the ZTC, which helps appending other strings 
;             or calculate the number of written bytes.
; Notes:      - Format specifiers:
;                 SB signed BYTE as decimal
;                 SW signed WORD as decimal
;                 SD signed DWORD as decimal
;                 SQ signed QWORD as decimal
;                 SX signed DWORD/QWORD as decimal
;                 UB unsigned BYTE as decimal
;                 UW unsigned WORD as decimal
;                 UD unsigned DWORD as decimal
;                 UQ unsigned QWORD as decimal
;                 UX unsigned DWORD/QWORD as decimal
;                 Fn Floating Point with n decimals, regular notation. n ranges from 0 to F
;                 En Floating Point with n decimals, scientific notation. n ranges from 0 to F
;                 H4 DWORD as hexadecimal
;                 H8 QWORD as hexadecimal
;                 HX DWORD/QWORD as hexadecimal
;                 SA ANSI string
;                 SU WIDE string (Unicode)
;                 ST ANSI/WIDE string
;                 GD GUID
;                 WE Windows API Error as description string
;                 CE COM Error as description string
;                 UE UEFI Error as description string
;                 MT Move to character position
;                 AT fill with spaces up to character position
;                 V4 IPv4 address in the format xxx.xxx.xxx.xxx, input has to be in NBO
;                 V6 IPv6 address in the format xxxx:xxxx:... , input has to be in NBO
;                 CA ANSI Character
;                 CW WIDE Character
;                 CT ANSI/WIDE Character
;                 BI Build in a macro. Use <<...>> to define the included code. Arg1 -> dest. buffer
;                 BN Build in a macro that returns in eax the nr of bytes written, excluding the ZTC
;                 BZ Build in a macro that returns in eax the nr of bytes written, including the ZTC
;
;             - Escape sequences:
;                 n  Carriage Return and Line Feed
;                 r  Carriage Return
;                 l  Line Feed
;                 0  ZTC
;                 t  Horizontal Tab
;                 [  "<" character
;                 ]  ">" character
;                 :  "!" character
;                 ´  "'" character
;                 \  "\" character
;
;             - Format specifiers and escape sequences are case sensitive.
;             - To use V4/V6 add the following lines in the asm file:
;                 % includelib &LibPath&Windows\Ntdll.lib
;                 % include &IncPath&Windows\ip2string.inc
;
; Example:    WriteF xdi, "Memory at ¦H8h: ¦F3", xsi, REAL4 ptr [xsi]
;             WriteF xdi, "The value is: ¦BZ Units", <<invoke udword2dec, xdi, 15>>


WriteF macro DstReg:req, Format:req, Args:vararg
  local pBegin

  ;;Scan for ¦AT, ¦MT or ¦BI. They require pBegin 
  $$WF_Replace = 0                                      ;;Replace flag
  $$WF_CharCount = 0
  $$WF_ReplType textequ <>
  $$BeginRequired = 0
  forc $$WF_Character, <Format>
    if $$BeginRequired eq 0
      $$WF_CharCount = $$WF_CharCount + 1
      if $$WF_CharCount eq 1                            ;;Ignore first character = "
      elseif $$WF_CharCount ne @SizeStr(Format)         ;;Ignore $$WF_LastChar character = "
        $$WF_LastChar Catstr <$$WF_Character>
        if $$WF_Replace
          if @SizeStr(%$$WF_ReplType) eq 0
            $$WF_ReplType Catstr <$$WF_Character>       ;;Get first char
          else
            $$WF_ReplType Catstr $$WF_ReplType, <$$WF_Character>   ;;Append second char
            ifidn $$WF_ReplType, <AT>
              $$BeginRequired = 1
            elseifidn $$WF_ReplType, <MT>
              $$BeginRequired = 1
            elseifidn $$WF_ReplType, <BI>
              $$BeginRequired = 1
            endif
            $$WF_ReplType textequ <>                    ;;Reset replace type
            $$WF_Replace = 0
          endif
        else
          ifidn <&$$WF_Character>, <¦>
            $$WF_Replace = 1                            ;;Set replace flag
          endif
        endif
      endif
    endif
  endm

  if $$BeginRequired eq 1
    .data?
      pBegin  POINTER   ?
  
    .code
    mov pBegin, DstReg
  endif
  
  ;;Start doing the job
  .code
  $$Count = 0
  for Arg, <Args>
    @CatStr(<$$WF_Arg>, %$$Count) textequ <Arg>
    $$Count = $$Count + 1
  endm

  $$WF_ArgCount = 0
  $$WF_Text textequ <>
  $$WF_Replace = 0                                      ;;Replace flag
  $$WF_CharCount = 0
  $$WF_ReplType textequ <>
  $$WF_Escape = 0                                       ;;Escape flag

  forc $$WF_Character, <Format>
    $$WF_CharCount = $$WF_CharCount + 1
    if $$WF_CharCount eq 1                              ;;Ignore first character = "
    elseif $$WF_CharCount ne @SizeStr(Format)           ;;Ignore $$WF_LastChar character = "
      $$WF_LastChar Catstr <$$WF_Character>
      if $$WF_Replace
        if @SizeStr(%$$WF_ReplType) eq 0
          $$WF_ReplType Catstr <$$WF_Character>         ;;Get first char
        else
          $$WF_ReplType Catstr $$WF_ReplType, <$$WF_Character>   ;;Append second char
          ifidn $$WF_ReplType, <SB>
            FillWord [DstReg], <%$$WF_Text>
            $$WF_Text textequ <>
            if $$Len ne 0
              add DstReg, $$Len*sizeof(CHR)
            endif
            movsx eax, @CatStr(<$$WF_Arg>, %$$WF_ArgCount)
            invoke sdword2dec, DstReg, eax
            lea DstReg, [DstReg + xax - sizeof(CHR)]
            $$WF_ArgCount = $$WF_ArgCount + 1

          elseifidn $$WF_ReplType, <SW>
            FillWord [DstReg], <%$$WF_Text>
            $$WF_Text textequ <>
            if $$Len ne 0
              add DstReg, $$Len*sizeof(CHR)
            endif
            movsx eax, @CatStr(<$$WF_Arg>, %$$WF_ArgCount)
            invoke sdword2dec, DstReg, eax
            lea DstReg, [DstReg + xax - sizeof(CHR)]
            $$WF_ArgCount = $$WF_ArgCount + 1

          elseifidn $$WF_ReplType, <SD>
            FillWord [DstReg], <%$$WF_Text>
            $$WF_Text textequ <>
            if $$Len ne 0
              add DstReg, $$Len*sizeof(CHR)
            endif
            invoke sdword2dec, DstReg, @CatStr(<$$WF_Arg>, %$$WF_ArgCount)
            lea DstReg, [DstReg + xax - sizeof(CHR)]
            $$WF_ArgCount = $$WF_ArgCount + 1

          elseifidn $$WF_ReplType, <SQ>
            FillWord [DstReg], <%$$WF_Text>
            $$WF_Text textequ <>
            if $$Len ne 0
              add DstReg, $$Len*sizeof(CHR)
            endif
            invoke sqword2dec, DstReg, @CatStr(<$$WF_Arg>, %$$WF_ArgCount)
            lea DstReg, [DstReg + xax - sizeof(CHR)]
            $$WF_ArgCount = $$WF_ArgCount + 1

          elseifidn $$WF_ReplType, <SX>
            FillWord [DstReg], <%$$WF_Text>
            $$WF_Text textequ <>
            if $$Len ne 0
              add DstReg, $$Len*sizeof(CHR)
            endif
            invoke sxword2dec, DstReg, @CatStr(<$$WF_Arg>, %$$WF_ArgCount)
            lea DstReg, [DstReg + xax - sizeof(CHR)]
            $$WF_ArgCount = $$WF_ArgCount + 1

          elseifidn $$WF_ReplType, <UB>
            FillWord [DstReg], <%$$WF_Text>
            $$WF_Text textequ <>
            if $$Len ne 0
              add DstReg, $$Len*sizeof(CHR)
            endif
            movzx eax, @CatStr(<$$WF_Arg>, %$$WF_ArgCount)
            invoke udword2dec, DstReg, eax
            lea DstReg, [DstReg + xax - sizeof(CHR)]
            $$WF_ArgCount = $$WF_ArgCount + 1

          elseifidn $$WF_ReplType, <UW>
            FillWord [DstReg], <%$$WF_Text>
            $$WF_Text textequ <>
            if $$Len ne 0
              add DstReg, $$Len*sizeof(CHR)
            endif
            movzx eax, @CatStr(<$$WF_Arg>, %$$WF_ArgCount)
            invoke udword2dec, DstReg, eax
            lea DstReg, [DstReg + xax - sizeof(CHR)]
            $$WF_ArgCount = $$WF_ArgCount + 1

          elseifidn $$WF_ReplType, <UD>
            FillWord [DstReg], <%$$WF_Text>
            $$WF_Text textequ <>
            if $$Len ne 0
              add DstReg, $$Len*sizeof(CHR)
            endif
            invoke udword2dec, DstReg, @CatStr(<$$WF_Arg>, %$$WF_ArgCount)
            lea DstReg, [DstReg + xax - sizeof(CHR)]
            $$WF_ArgCount = $$WF_ArgCount + 1

          elseifidn $$WF_ReplType, <UQ>
            FillWord [DstReg], <%$$WF_Text>
            $$WF_Text textequ <>
            if $$Len ne 0
              add DstReg, $$Len*sizeof(CHR)
            endif
            invoke uqword2dec, DstReg, @CatStr(<$$WF_Arg>, %$$WF_ArgCount)
            lea DstReg, [DstReg + xax - sizeof(CHR)]
            $$WF_ArgCount = $$WF_ArgCount + 1

          elseifidn $$WF_ReplType, <UX>
            FillWord [DstReg], <%$$WF_Text>
            $$WF_Text textequ <>
            if $$Len ne 0
              add DstReg, $$Len*sizeof(CHR)
            endif
            invoke uxword2dec, DstReg, @CatStr(<$$WF_Arg>, %$$WF_ArgCount)
            lea DstReg, [DstReg + xax - sizeof(CHR)]
            $$WF_ArgCount = $$WF_ArgCount + 1

          elseifidn $$WF_ReplType, <H4>
            FillWord [DstReg], <%$$WF_Text>
            $$WF_Text textequ <>
            if $$Len ne 0
              add DstReg, $$Len*sizeof(CHR)
            endif
            invoke dword2hex, DstReg, @CatStr(<$$WF_Arg>, %$$WF_ArgCount)
            add DstReg, (DWORD2HEX_MAX_CHARS - 1)*sizeof(CHR)
            $$WF_ArgCount = $$WF_ArgCount + 1

          elseifidn $$WF_ReplType, <H8>
            FillWord [DstReg], <%$$WF_Text>
            $$WF_Text textequ <>
            if $$Len ne 0
              add DstReg, $$Len*sizeof(CHR)
            endif
            invoke qword2hex, DstReg, @CatStr(<$$WF_Arg>, %$$WF_ArgCount)
            add DstReg, (QWORD2HEX_MAX_CHARS - 1)*sizeof(CHR)
            $$WF_ArgCount = $$WF_ArgCount + 1

          elseifidn $$WF_ReplType, <HX>
            FillWord [DstReg], <%$$WF_Text>
            $$WF_Text textequ <>
            if $$Len ne 0
              add DstReg, $$Len*sizeof(CHR)
            endif
            invoke xword2hex, DstReg, @CatStr(<$$WF_Arg>, %$$WF_ArgCount)
            add DstReg, 2*@WordSize*sizeof(CHR)
            $$WF_ArgCount = $$WF_ArgCount + 1

          elseifidn @SubStr(<%$$WF_ReplType>, 1, 1), <F>
            FillWord [DstReg], <%$$WF_Text>
            $$WF_Text textequ <>
            if $$Len ne 0
              add DstReg, $$Len*sizeof(CHR)
            endif
            fld @CatStr(<$$WF_Arg>, %$$WF_ArgCount)
            invoke St0ToStr, DstReg, 0, @CatStr(<0>, @SubStr(<%$$WF_ReplType>, 2, 1), <h>), f_NOR
            fUnload
            invoke StrSize, DstReg
            lea DstReg, [DstReg + xax - sizeof(CHR)]
            $$WF_ArgCount = $$WF_ArgCount + 1

          elseifidn @SubStr(<%$$WF_ReplType>, 1, 1), <E>
            FillWord [DstReg], <%$$WF_Text>
            $$WF_Text textequ <>
            if $$Len ne 0
              add DstReg, $$Len*sizeof(CHR)
            endif
            fld @CatStr(<$$WF_Arg>, %$$WF_ArgCount)
            invoke St0ToStr, DstReg, 0, @CatStr(<0>, @SubStr(<%$$WF_ReplType>, 2, 1), <h>), f_SCI
            fUnload
            invoke StrSize, DstReg
            lea DstReg, [DstReg + xax - sizeof(CHR)]
            $$WF_ArgCount = $$WF_ArgCount + 1

          elseifidn $$WF_ReplType, <SA>
            FillWord [DstReg], <%$$WF_Text>
            $$WF_Text textequ <>
            if $$Len ne 0
              add DstReg, $$Len*sizeof(CHR)
            endif
            if TARGET_STR_TYPE eq STR_TYPE_WIDE
              invoke StrA2StrW, DstReg, @CatStr(<$$WF_Arg>, %$$WF_ArgCount)
              invoke StrSizeW, DstReg
              lea DstReg, [DstReg + xax - Sizeof(CHRW)]
              $$WF_ArgCount = $$WF_ArgCount + 1
            else
              invoke StrCopyA, DstReg, @CatStr(<$$WF_Arg>, %$$WF_ArgCount)
              lea DstReg, [DstReg + xax - sizeof(CHRA)]
              $$WF_ArgCount = $$WF_ArgCount + 1
            endif

          elseifidn $$WF_ReplType, <SU>
            FillWord [DstReg], <%$$WF_Text>
            $$WF_Text textequ <>
            if $$Len ne 0
              add DstReg, $$Len*sizeof(CHR)
            endif
            if TARGET_STR_TYPE eq STR_TYPE_WIDE
              invoke StrCopyW, DstReg, @CatStr(<$$WF_Arg>, %$$WF_ArgCount)
              lea DstReg, [DstReg + xax - sizeof(CHRW)]
              $$WF_ArgCount = $$WF_ArgCount + 1
            else
              invoke StrW2StrA, DstReg, @CatStr(<$$WF_Arg>, %$$WF_ArgCount)
              invoke StrSizeA, DstReg
              lea DstReg, [DstReg + xax - sizeof(CHRA)]
              $$WF_ArgCount = $$WF_ArgCount + 1
            endif

          elseifidn $$WF_ReplType, <ST>
            FillWord [DstReg], <%$$WF_Text>
            $$WF_Text textequ <>
            if $$Len ne 0
              add DstReg, $$Len*sizeof(CHR)
            endif
            invoke StrCopy, DstReg, @CatStr(<$$WF_Arg>, %$$WF_ArgCount)
            lea DstReg, [DstReg + xax - sizeof(CHR)]
            $$WF_ArgCount = $$WF_ArgCount + 1

          elseifidn $$WF_ReplType, <CA>
            m2m CHRA ptr [DstReg], @CatStr(<$$WF_Arg>, %$$WF_ArgCount), eax
            add DstReg, sizeof(CHRA)

          elseifidn $$WF_ReplType, <CW>
            m2m CHRW ptr [DstReg], @CatStr(<$$WF_Arg>, %$$WF_ArgCount), eax
            add DstReg, sizeof(CHRW)

          elseifidn $$WF_ReplType, <CT>
            m2m CHR ptr [DstReg], @CatStr(<$$WF_Arg>, %$$WF_ArgCount), eax
            add DstReg, sizeof(CHR)

          elseifidn $$WF_ReplType, <GD>
            FillWord [DstReg], <%$$WF_Text>
            $$WF_Text textequ <>
            if $$Len ne 0
              add DstReg, $$Len*sizeof(CHR)
            endif
            invoke GUID2Str, DstReg, @CatStr(<$$WF_Arg>, %$$WF_ArgCount)
            add DstReg, (GUID2STR_MAX_CHARS - 1)*sizeof(CHR)
            $$WF_ArgCount = $$WF_ArgCount + 1

          elseifidn $$WF_ReplType, <WE>
            FillWord [DstReg], <%$$WF_Text>
            $$WF_Text textequ <>
            if $$Len ne 0
              add DstReg, $$Len*sizeof(CHR)
            endif
            if TARGET_PLATFORM eq PLATFORM_WINDOWS
              invoke FormatMessage, FORMAT_MESSAGE_FROM_SYSTEM, 0, @CatStr(<$$WF_Arg>, %$$WF_ArgCount), 0, DstReg, 256, 0
              .if eax != 0
                lea DstReg, [DstReg + xax*sizeof(CHR) - 2*sizeof(CHR)]
                $$WF_ArgCount = $$WF_ArgCount + 1
              .endif
            else
              .err <Invalid format specifier>
            endif

          elseifidn $$WF_ReplType, <CE>
            FillWord [DstReg], <%$$WF_Text>
            $$WF_Text textequ <>
            if $$Len ne 0
              add DstReg, $$Len*sizeof(CHR)
            endif
            if TARGET_PLATFORM eq PLATFORM_WINDOWS
              invoke ComGetErrStr, @CatStr(<$$WF_Arg>, %$$WF_ArgCount)
              .if xax != NULL
                mov DstReg, $invoke(StrECopy, DstReg, xax)
                $$WF_ArgCount = $$WF_ArgCount + 1
              .endif
            else
              .err <Invalid format specifier>
            endif

          elseifidn $$WF_ReplType, <UE>
            FillWord [DstReg], <%$$WF_Text>
            $$WF_Text textequ <>
            if $$Len ne 0
              add DstReg, $$Len*sizeof(CHR)
            endif
            if TARGET_PLATFORM eq PLATFORM_UEFI
              invoke UefiGetErrStr, @CatStr(<$$WF_Arg>, %$$WF_ArgCount)
              .if xax != NULL
                mov DstReg, $invoke(StrECopy, DstReg, xax)
                $$WF_ArgCount = $$WF_ArgCount + 1
              .endif
            else
              .err <Invalid format specifier>
            endif

          elseifidn $$WF_ReplType, <V4>
            FillWord [DstReg], <%$$WF_Text>
            $$WF_Text textequ <>
            if $$Len ne 0
              add DstReg, $$Len*sizeof(CHR)
            endif
            invoke RtlIpv4AddressToString, @CatStr(<$$WF_Arg>, %$$WF_ArgCount), DstReg
            mov DstReg, xax
            $$WF_ArgCount = $$WF_ArgCount + 1

          elseifidn $$WF_ReplType, <V6>
            FillWord [DstReg], <%$$WF_Text>
            $$WF_Text textequ <>
            if $$Len ne 0
              add DstReg, $$Len*sizeof(CHR)
            endif
            invoke RtlIpv6AddressToString, @CatStr(<$$WF_Arg>, %$$WF_ArgCount), DstReg
            mov DstReg, xax
            $$WF_ArgCount = $$WF_ArgCount + 1

          elseifidn $$WF_ReplType, <BI>
            FillWord [DstReg], <%$$WF_Text>
            $$WF_Text textequ <>
            if $$Len ne 0
              add DstReg, $$Len*sizeof(CHR)
            endif
            @CatStr(<$$WF_Arg>, %$$WF_ArgCount)
            invoke StrEnd, pBegin
            mov DstReg, xax
            $$WF_ArgCount = $$WF_ArgCount + 1

          elseifidn $$WF_ReplType, <BN>
            FillWord [DstReg], <%$$WF_Text>
            $$WF_Text textequ <>
            if $$Len ne 0
              add DstReg, $$Len*sizeof(CHR)
            endif
            @CatStr(<$$WF_Arg>, %$$WF_ArgCount)
            add DstReg, xax
            $$WF_ArgCount = $$WF_ArgCount + 1

          elseifidn $$WF_ReplType, <BZ>
            FillWord [DstReg], <%$$WF_Text>
            $$WF_Text textequ <>
            if $$Len ne 0
              add DstReg, $$Len*sizeof(CHR)
            endif
            @CatStr(<$$WF_Arg>, %$$WF_ArgCount)
            lea DstReg, [DstReg + xax - sizeof(CHR)]
            $$WF_ArgCount = $$WF_ArgCount + 1

          elseifidn $$WF_ReplType, <AT>
            FillWord [DstReg], <%$$WF_Text>
            $$WF_Text textequ <>
            if $$Len ne 0
              add DstReg, $$Len*sizeof(CHR)
            endif
            mov xax, @CatStr(<$$WF_Arg>, %$$WF_ArgCount)
            mov xcx, DstReg
            sub xcx, pBegin
            if TARGET_STR_TYPE eq STR_TYPE_WIDE
              shr xcx, 1
            endif
            sub xax, xcx
            if TARGET_STR_TYPE eq STR_TYPE_WIDE
              .while SDWORD ptr eax > 1               ;;Fill with spaces
                mov DCHRW ptr [DstReg], " " shl 16 + " "
                add DstReg, sizeof(DCHRW)
                sub eax, 2
              .endw
            else
              .while SDWORD ptr eax > 3               ;;Fill with spaces
                mov QCHRA ptr [DstReg], "    "
                add DstReg, sizeof(QCHRA)
                sub eax, 4
              .endw
              .if SDWORD ptr eax > 1
                mov DCHRA ptr [DstReg], "  "
                add DstReg, sizeof(DCHRA)
                sub eax, 2
                cmp eax, 1
              .endif
            endif
            .if ZERO?
              mov CHR ptr [DstReg], " "
              add DstReg, sizeof(CHR)
            .endif
            $$WF_ArgCount = $$WF_ArgCount + 1

          elseifidn $$WF_ReplType, <MT>
            FillWord [DstReg], <%$$WF_Text>
            $$WF_Text textequ <>
            if $$Len ne 0
              add DstReg, $$Len*sizeof(CHR)
            endif
            mov xax, @CatStr(<$$WF_Arg>, %$$WF_ArgCount)
            mov xcx, DstReg
            sub xcx, pBegin
            if TARGET_STR_TYPE eq STR_TYPE_WIDE
              shr xcx, 1
            endif
            sub xax, xcx
            .if SDWORD ptr eax < 0                      ;;If negative, move pointer
              mov DstReg, pBegin
              mov xcx, @CatStr(<$$WF_Arg>, %$$WF_ArgCount)
              if TARGET_STR_TYPE eq STR_TYPE_WIDE
                shl xcx, 1
              endif
              add DstReg, xcx
              m2z CHR ptr [DstReg]                      ;;Set ZTC
            .else
              if TARGET_STR_TYPE eq STR_TYPE_WIDE
                .while SDWORD ptr eax > 1               ;;Fill with spaces
                  mov DCHRW ptr [DstReg], " " shl 16 + " "
                  add DstReg, sizeof(DCHRW)
                  sub eax, 2
                .endw
              else
                .while SDWORD ptr eax > 3               ;;Fill with spaces
                  mov QCHRA ptr [DstReg], "    "
                  add DstReg, sizeof(QCHRA)
                  sub eax, 4
                .endw
                .if SDWORD ptr eax > 1
                  mov DCHRA ptr [DstReg], "  "
                  add DstReg, sizeof(DCHRA)
                  sub eax, 2
                  cmp eax, 1
                .endif
              endif
              .if ZERO?
                mov CHR ptr [DstReg], " "
                add DstReg, sizeof(CHR)
              .endif
            .endif
            $$WF_ArgCount = $$WF_ArgCount + 1

          else                                          ;;No matching format specifiers found
            $$WF_Text CatStr $$WF_Text, <¦>, $$WF_ReplType  ;;Emit the format specifiers

          endif
          $$WF_Replace = 0                              ;;Reset replace flag
          $$WF_ReplType textequ <>                      ;;Reset replace type
        endif

      elseif $$WF_Escape
        $$WF_Escape = 0                                 ;;Reset escape flag
        ifidn <$$WF_Character>, <n>
          FillWord [DstReg], <%$$WF_Text>
          $$WF_Text textequ <>
          if $$Len ne 0
            add DstReg, $$Len*sizeof(CHR)
          endif
          mov DCHR ptr [DstReg], 10 shl (8*sizeof(CHR)) + 13
          add DstReg, 2*sizeof(CHR)
        elseifidn <$$WF_Character>, <r>
          FillWord [DstReg], <%$$WF_Text>
          $$WF_Text textequ <>
          if $$Len ne 0
            add DstReg, $$Len*sizeof(CHR)
          endif
          mov CHR ptr [DstReg], 13
          add DstReg, sizeof(CHR)
        elseifidn <$$WF_Character>, <l>
          FillWord [DstReg], <%$$WF_Text>
          $$WF_Text textequ <>
          if $$Len ne 0
            add DstReg, $$Len*sizeof(CHR)
          endif
          mov CHR ptr [DstReg], 10
          add DstReg, sizeof(CHR)
        elseifidn <$$WF_Character>, <0>
          FillWord [DstReg], <%$$WF_Text>
          $$WF_Text textequ <>
          if $$Len ne 0
            add DstReg, $$Len*sizeof(CHR)
          endif
          mov CHR ptr [DstReg], 0
          add DstReg, sizeof(CHR)
        elseifidn <$$WF_Character>, <t>
          FillWord [DstReg], <%$$WF_Text>
          $$WF_Text textequ <>
          if $$Len ne 0
            add DstReg, $$Len*sizeof(CHR)
          endif
          mov CHR ptr [DstReg], 9
          add DstReg, sizeof(CHR)
        elseifidn <$$WF_Character>, <[>
          FillWord [DstReg], <%$$WF_Text>
          $$WF_Text textequ <>
          if $$Len ne 0
            add DstReg, $$Len*sizeof(CHR)
          endif
          mov CHR ptr [DstReg], '<'
          add DstReg, sizeof(CHR)
        elseifidn <$$WF_Character>, <]>
          FillWord [DstReg], <%$$WF_Text>
          $$WF_Text textequ <>
          if $$Len ne 0
            add DstReg, $$Len*sizeof(CHR)
          endif
          mov CHR ptr [DstReg], '>'
          add DstReg, sizeof(CHR)
        elseifidn <$$WF_Character>, <:>
          FillWord [DstReg], <%$$WF_Text>
          $$WF_Text textequ <>
          if $$Len ne 0
            add DstReg, $$Len*sizeof(CHR)
          endif
          mov CHR ptr [DstReg], '!'
          add DstReg, sizeof(CHR)
        elseifidn <$$WF_Character>, <´>
          FillWord [DstReg], <%$$WF_Text>
          $$WF_Text textequ <>
          if $$Len ne 0
            add DstReg, $$Len*sizeof(CHR)
          endif
          mov CHR ptr [DstReg], "'"
          add DstReg, sizeof(CHR)
        elseifidn <$$WF_Character>, <\>
          $$WF_Text CatStr $$WF_Text, <\>
        else
          $$WF_Text CatStr $$WF_Text, <\>;, <&$$WF_Character>
          ifidn <&$$WF_Character>, <¦>
            $$WF_Replace = 1                            ;;Set replace flag
          else
            $$WF_Text CatStr $$WF_Text, <&$$WF_Character>
          endif
        endif
      else
        ifidn <&$$WF_Character>, <¦>
          $$WF_Replace = 1                              ;;Set replace flag
        elseifidn <&$$WF_Character>, <\>
          $$WF_Escape = 1                               ;;Set escape flag
        else
          $$WF_Text CatStr $$WF_Text, <&$$WF_Character>
        endif
      endif
    endif
  endm

  FillString [DstReg], %$$WF_Text                       ;;If there is something in the buffer,
  if $$Len ne 0
    add DstReg, $$Len*sizeof(CHR)
  endif
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      IsCharTypeA?
; Purpose:    Compare an ANSI character with a pedefined type of characters.
; Arguments:  Arg1: Character to be evaluated.
;             Arg2: Character type.
;             Arg3: (optional) Character table
; Return:     Flags. Zero indicates that the character is NOT of the char type.
;             On return, al contains the tested character.
; Example:    IsCharTypeA? [myString+5], CharTypeText
;             .if $IsCharTypeA?([myString+5], CharTypeText)

CharTypeAlpha     equ   BIT00
CharTypeNumeric   equ   BIT01
CharTypeMathOp    equ   BIT02
CharTypeArray     equ   BIT03
CharTypeLogic     equ   BIT04

IsCharTypeA? macro CHARA:req, CharType:req
  ifndef CharLookupTableA
  .const
  CharLookupTableA label CHRA
    ;  NUL  SOH  STX  ETX  EDT  ENQ  ACK  BEL  BS   TAB  LF   VF   FF   CR   SO   SI
    db 000h,000h,000h,000h,000h,000h,000h,000h,000h,000h,000h,000h,000h,000h,000h,000h
    ;  DLE  DC1  DC2  DC3  DC4  NAK  SYN  ETB  CAN  BM   SUB  ESC  FS   GS   RS   US
    db 000h,000h,000h,000h,000h,000h,000h,000h,000h,000h,000h,000h,000h,000h,000h,000h
    ;  SPC    !    "    #    $    %    &    '    (    )    *    +    ,    -    .    /
    db 001h,014h,000h,001h,001h,004h,014h,000h,00Ch,00Ch,004h,004h,000h,004h,000h,004h  ;#, $
    ;    0    1    2    3    4    5    6    7    8    9    :    ;    <    =    >    ?
    db 002h,002h,002h,002h,002h,002h,002h,002h,002h,002h,000h,000h,010h,010h,010h,011h  ;0..9, ?
    ;    @    A    B    C    D    E    F    G    H    I    J    K    L    M    N    O
    db 001h,001h,001h,001h,001h,001h,001h,001h,001h,001h,001h,001h,001h,001h,001h,001h  ;@, A..O
    ;    P    Q    R    S    T    U    V    W    X    Y    Z    [    \    ]    ^    _
    db 001h,001h,001h,001h,001h,001h,001h,001h,001h,001h,001h,008h,004h,008h,014h,001h  ;P..Z, _
    ;    `    a    b    c    d    e    f    g    h    i    j    k    l    m    n    o
    db 000h,001h,001h,001h,001h,001h,001h,001h,001h,001h,001h,001h,001h,001h,001h,001h  ;a..o
    ;    p    q    r    s    t    u    v    w    x    y    z    {    |    }    ~
    db 001h,001h,001h,001h,001h,001h,001h,001h,001h,001h,001h,008h,014h,008h,014h,000h  ;p..z
    db 000h,000h,000h,000h,000h,000h,000h,000h,000h,000h,000h,000h,000h,000h,000h,000h
    db 000h,000h,000h,000h,000h,000h,000h,000h,000h,000h,000h,000h,000h,000h,000h,000h
    db 000h,000h,000h,000h,000h,000h,000h,000h,000h,000h,000h,000h,000h,000h,000h,000h
    db 000h,000h,000h,000h,000h,000h,000h,000h,000h,000h,000h,000h,000h,000h,000h,000h
    db 000h,000h,000h,000h,000h,000h,000h,000h,000h,000h,000h,000h,000h,000h,000h,000h
    db 000h,000h,000h,000h,000h,000h,000h,000h,000h,000h,000h,000h,000h,000h,000h,000h
    db 000h,000h,000h,000h,000h,000h,000h,000h,000h,000h,000h,000h,000h,000h,000h,000h
    db 000h,000h,000h,000h,000h,000h,000h,000h,000h,000h,000h,000h,000h,000h,000h,000h
  .code
  endif

  if TARGET_BITNESS eq 32
    movzx eax, CHARA
    test CHRA ptr [CharLookupTableA + eax], CharType
  else
    movzx eax, CHARA
    mov xdx, offset CharLookupTableA
    test CHRA ptr [xdx + xax], CharType
  endif
endm

$IsCharTypeA? macro CHARA:req, CharType:req
  IsCharTypeA? CHARA, CharType
  exitm <!ZERO?>
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      ($)Choose
; Purpose:    Choose returns a value from a list of choices based on an index value.
; Arguments:  Arg1: Index.
;             Arg2: First choise.
;             Arg3: Rest of choices.
; Return:     Choosen value.

Choose macro Index:req, Choise1:req, Choises:vararg
  local ChoiseCount, Choise

  ChoiseCount = 0
  .if Index == 0
    mov xax, Choise1
    for Choise, <Choises>
      ChoiseCount = ChoiseCount + 1
      @CatStr(<.elseif Index == >, <&ChoiseCount>)
      mov xax, Choise
    endm
  .else
    xor eax, eax          ;;Returns NULL
  .endif
endm

Choose32 macro Index:req, Choise1:req, Choises:vararg
  local ChoiseCount, Choise

  ChoiseCount = 0
  .if Index == 0
    mov eax, Choise1
    for Choise, <Choises>
      ChoiseCount = ChoiseCount + 1
      @CatStr(<.elseif Index == >, <&ChoiseCount>)
      mov eax, Choise
    endm
  .else
    xor eax, eax          ;;Returns NULL
  .endif
endm

$Choose macro Index:req, Choise1:req, Choises:vararg
  Choose Index, Choise1, Choises
  exitm <xax>
endm

$Choose32 macro Index:req, Choise1:req, Choises:vararg
  Choose32 Index, Choise1, Choises
  exitm <eax>
endm

Choose1 macro Index:req, Choises:vararg
  local ChoiseCount, Choise, ConstData

  .const
  ChoiseCount = 0
  for Choise, <Choises>
    ife ChoiseCount
      ConstData dq Choise
    else
      dq dChoise
    endif
    ChoiseCount = ChoiseCount + 1
  endm

  .code
  .if Index <= ChoiseCount
    if (opattr Index) and OAT_REGISTER                  ;;Is dIndex a register?
      mov xax, [offset(ConstData) + @WordSize*dIndex]
    else
      mov xax, dIndex
      mov xax, [offset(ConstData) + @WordSize*xax]
    endif
  .else
    xor eax, eax
  .endif
endm

$Choose1 macro dIndex:req, dChoise1:req, dChoises:vararg
  Choose1 dIndex, dChoise1, dChoises
  exitm <xax>
endm


$ChooseAddr macro dArgs:vararg
  ChooseAddr dArgs
  exitm <xax>
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      (C/D)Real??
; Purpose:    Declare a named floating point value in the data/const memory segment.
; Arguments:  Arg1: Name of the floating point variable.
;             Arg2: Value of the floating point variable.

DReal4 macro Name, Value
  S_DATA segment
  align @WordSize
  Name REAL4 Value
  S_DATA ends
endm

DReal8 macro Name, Value
  S_DATA segment
  align @WordSize
  Name REAL8 Value
  S_DATA ends
endm

DReal10 macro Name, Value
  S_DATA segment
  align @WordSize
  Name REAL10 Value
  S_DATA ends
endm

CReal4 macro Name, Value
  S_CONST segment
  align @WordSize
  Name REAL4 Value
  S_CONST ends
endm

CReal8 macro Name, Value
  S_CONST Segment
  align @WordSize
  Name REAL8 Value
  S_CONST ends
endm

CReal10 macro Name, Value
  S_CONST segment
  align @WordSize
  Name REAL10 Value
  S_CONST ends
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      $CReal??
; Purpose:    Create in memory a REAL4 constant. Repeated declarations use the same memory location.
; Arguments:  Arg1: Value of the floating point variable.
; Return:     Symbol of the declared REAL4 value.
; Note:       The $CReal?? macro are intended to avoid the creation of multiple instances of the same
;             floating point constant.

$CReal4 macro Value
  ;;Generate a symbol name according to the specified value
  ;; e.g. +0.25 => CR4_P0p25
  ;;      -0.55 => CR4_M0p55
  $$RealName CatStr <CR4_>
  $$StartPos = 1
  ifidni @SubStr(Value, 1, 1), <->
    $$RealName CatStr $$RealName, <M>
    $$StartPos = 2
  else
    $$RealName CatStr $$RealName, <P>
    ifidni @SubStr(Value, 1, 1), <+>
      $$StartPos = 2
    endif
  endif

  $$RealDotPos InStr $$StartPos, <Value>, <.>
  align @WordSize
  if $$RealDotPos eq 0
    $$RealName CatStr $$RealName, @SubStr(Value, $$StartPos), <p0>
  else      ;Check for additional <+> or <-> in the exponent
    $$RealExpPos InStr $$RealDotPos + 1, <Value>, <e>
    if $$RealExpPos eq 0
      $$RealExpPos InStr $$RealDotPos + 1, <Value>, <E>
    endif
    if $$RealExpPos eq 0
      $$RealName CatStr $$RealName, @SubStr(Value, $$StartPos, $$RealDotPos - $$StartPos), \
                                            <p>, @SubStr(Value, $$RealDotPos + 1)
    else
      ifidn @SubStr(Value, $$RealExpPos + 1, 1), <+>
        $$RealName CatStr $$RealName, @SubStr(Value, $$StartPos, $$RealDotPos - $$StartPos), <p>, \
                          @SubStr(Value, $$RealDotPos + 1, $$RealExpPos - $$RealDotPos - 1), <EP>, \
                          @SubStr(Value, $$RealExpPos + 2)
      else
        ifidn @SubStr(Value, $$RealExpPos + 1, 1), <->
          $$RealName CatStr $$RealName, @SubStr(Value, $$StartPos, $$RealDotPos - $$StartPos), <p>, \
                            @SubStr(Value, $$RealDotPos + 1, $$RealExpPos - $$RealDotPos - 1), <EM>, \
                            @SubStr(Value, $$RealExpPos + 2)
        else
          $$RealName CatStr $$RealName, @SubStr(Value, $$StartPos, $$RealDotPos - $$StartPos), <p>, \
                            @SubStr(Value, $$RealDotPos + 1, $$RealExpPos - $$RealDotPos - 1), <EP>, \
                            @SubStr(Value, $$RealExpPos + 1)
        endif
      endif
    endif
  endif

  ;;Check if it does exist
%   ifndef $$RealName
    S_CONST segment
      align @WordSize
      if $$RealDotPos eq 0
;;        %echo @CatStr(<Defining CONST REAL4=>, Value, <.0 using >, %$$RealName, < symbol name at line >, %@Line, < of >, @FileCur)
        $$RealName REAL4 @CatStr(Value, <.0>)
      else
;;        %echo @CatStr(<Defining CONST REAL4=>, Value, < using >, %$$RealName, < symbol name at line >, %@Line, < of >, @FileCur)
        $$RealName REAL4 Value
      endif
    S_CONST ends
;;    else
;;      %echo @CatStr(<Reusing  CONST REAL4=>, Value, < using >, %$$RealName, < symbol name at line >, %@Line, < of >, @FileCur)
  endif
  exitm $$RealName
endm

$CReal8 macro Value
  ;;Generate a symbol name according to the specified value
  ;; e.g. +0.25 => CR8_P0p25
  ;;      -0.55 => CR8_M0p55
  $$RealName CatStr <CR8_>
  $$StartPos = 1
  ifidni @SubStr(Value, 1, 1), <->
    $$RealName CatStr $$RealName, <M>
    $$StartPos = 2
  else
    $$RealName CatStr $$RealName, <P>
    ifidni @SubStr(Value, 1, 1), <+>
      $$StartPos = 2
    endif
  endif

  $$RealDotPos InStr $$StartPos, <Value>, <.>
  if $$RealDotPos eq 0
    $$RealName CatStr $$RealName, @SubStr(Value, $$StartPos), <p0>
  else      ;Check for additional <+> or <-> in the exponent
    $$RealExpPos InStr $$RealDotPos + 1, <Value>, <e>
    if $$RealExpPos eq 0
      $$RealExpPos InStr $$RealDotPos + 1, <Value>, <E>
    endif
    if $$RealExpPos eq 0
      $$RealName CatStr $$RealName, @SubStr(Value, $$StartPos, $$RealDotPos - $$StartPos), <p>, \
                                            @SubStr(Value, $$RealDotPos + 1)
    else
      ifidn @SubStr(Value, $$RealExpPos + 1, 1), <+>
        $$RealName CatStr $$RealName, @SubStr(Value, $$StartPos, $$RealDotPos - $$StartPos), <p>, \
                          @SubStr(Value, $$RealDotPos + 1, $$RealExpPos - $$RealDotPos - 1), <EP>, \
                          @SubStr(Value, $$RealExpPos + 2)
      else
        ifidn @SubStr(Value, $$RealExpPos + 1, 1), <->
          $$RealName CatStr $$RealName, @SubStr(Value, $$StartPos, $$RealDotPos - $$StartPos), <p>, \
                            @SubStr(Value, $$RealDotPos + 1, $$RealExpPos - $$RealDotPos - 1), <EM>, \
                            @SubStr(Value, $$RealExpPos + 2)
        else
          $$RealName CatStr $$RealName, @SubStr(Value, $$StartPos, $$RealDotPos - $$StartPos), <p>, \
                            @SubStr(Value, $$RealDotPos + 1, $$RealExpPos - $$RealDotPos - 1), <EP>, \
                            @SubStr(Value, $$RealExpPos + 1)
        endif
      endif
    endif
  endif

  ;;Check if it does exist
%   ifndef $$RealName
    S_CONST segment
      align @WordSize
      if $$RealDotPos eq 0
;;        %echo @CatStr(<Defining CONST REAL8=>, Value, <.0 using >, %$$RealName, < symbol name at line >, %@Line, < of >, @FileCur)
        $$RealName REAL8 @CatStr(Value, <.0>)
      else
;;        %echo @CatStr(<Defining CONST REAL8=>, Value, < using >, %$$RealName, < symbol name at line >, %@Line, < of >, @FileCur)
        $$RealName REAL8 Value
      endif
    S_CONST ends
;;    else
;;      %echo @CatStr(<Reusing  CONST REAL8=>, Value, < using >, %$$RealName, < symbol name at line >, %@Line, < of >, @FileCur)
  endif
  exitm $$RealName
endm

$CReal10 macro Value
  ;;Generate a symbol name according to the specified value
  ;; e.g. +0.25 => CR10_P0p25
  ;;      -0.55 => CR10_M0p55
  $$RealName CatStr <CR10_>
  $$StartPos = 1
  ifidni @SubStr(Value, 1, 1), <->
    $$RealName CatStr $$RealName, <M>
    $$StartPos = 2
  else
    $$RealName CatStr $$RealName, <P>
    ifidni @SubStr(Value, 1, 1), <+>
      $$StartPos = 2
    endif
  endif

  $$RealDotPos InStr $$StartPos, <Value>, <.>
  if $$RealDotPos eq 0
    $$RealName CatStr $$RealName, @SubStr(Value, $$StartPos), <p0>
  else      ;Check for additional <+> or <-> in the exponent
    $$RealExpPos InStr $$RealDotPos + 1, <Value>, <e>
    if $$RealExpPos eq 0
      $$RealExpPos InStr $$RealDotPos + 1, <Value>, <E>
    endif
    if $$RealExpPos eq 0
      $$RealName CatStr $$RealName, @SubStr(Value, $$StartPos, $$RealDotPos - $$StartPos), <p>, \
                                            @SubStr(Value, $$RealDotPos + 1)
    else
      ifidn @SubStr(Value, $$RealExpPos + 1, 1), <+>
        $$RealName CatStr $$RealName, @SubStr(Value, $$StartPos, $$RealDotPos - $$StartPos), <p>, \
                          @SubStr(Value, $$RealDotPos + 1, $$RealExpPos - $$RealDotPos - 1), <EP>, \
                          @SubStr(Value, $$RealExpPos + 2)
      else
        ifidn @SubStr(Value, $$RealExpPos + 1, 1), <->
          $$RealName CatStr $$RealName, @SubStr(Value, $$StartPos, $$RealDotPos - $$StartPos), <p>, \
                            @SubStr(Value, $$RealDotPos + 1, $$RealExpPos - $$RealDotPos - 1), <EM>, \
                            @SubStr(Value, $$RealExpPos + 2)
        else
          $$RealName CatStr $$RealName, @SubStr(Value, $$StartPos, $$RealDotPos - $$StartPos), <p>, \
                            @SubStr(Value, $$RealDotPos + 1, $$RealExpPos - $$RealDotPos - 1), <EP>, \
                            @SubStr(Value, $$RealExpPos + 1)
        endif
      endif
    endif
  endif

  ;;Check if it does exist
%   ifndef $$RealName
    S_CONST segment
      align @WordSize
      if $$RealDotPos eq 0
;;        %echo @CatStr(<Defining CONST REAL10=>, Value, <.0 using >, %$$RealName, < symbol name at line >, %@Line, < of >, @FileCur)
        $$RealName REAL10 @CatStr(Value, <.0>)
      else
;;        %echo @CatStr(<Defining CONST REAL10=>, Value, < using >, %$$RealName, < symbol name at line >, %@Line, < of >, @FileCur)
        $$RealName REAL10 Value
      endif
    S_CONST ends
;;    else
;;      %echo @CatStr(<Reusing  CONST REAL10=>, Value, < using >, %$$RealName, < symbol name at line >, %@Line, < of >, @FileCur)
  endif
  exitm $$RealName
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      $DReal??
; Purpose:    Declare a floating point variable as a vaiable.
; Arguments:  Arg1: Value of the floating point variable.
; Return:     Symbol of the floting point value.

$DReal4 macro Value
  local Name
  align @WordSize
  DReal4 Name, Value
  exitm <Name>
endm

$DReal8 macro Value
  local Name
  align @WordSize
  DReal8 Name, Value
  exitm <Name>
endm

$DReal10 macro Value
  local Name
  align @WordSize
  DReal10 Name, Value
  exitm <Name>
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      sMax / $sMax
; Purpose:    Return the maximum of 2 signed values.
; Arguments:  Arg1: First signed word.
;             Arg2: Second signed word.
;             Arg3: Optional destiantion register. Default is xax.
; Return:     DstReg/rax/eax/ax/al = Biggest signed value.

sMax macro Var1:req, Var2:req, DstReg:=<xax>
  $$Attribute = type(Var1)
  $$Reg textequ $SubReg(DstReg, $$Attribute)
  $$Word textequ $SubWord(<SQWORD>, $$Attribute)

  ifidni <Var2>, $$Reg
    .if $$Word ptr $$Reg < Var1
      mov $$Reg, Var1
    .endif
  else
    ifdifi <Var1>, $$Reg
      mov $$Reg, Var1
    endif
    .if $$Word ptr $$Reg < Var2
      mov $$Reg, Var2
    .endif
  endif
endm

$sMax macro Var1:req, Var2:req, DstReg:=<xax>
  sMax Var1, Var2, DstReg
  %exitm <$SubReg(DstReg, type(Var1))>
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      sMin / $sMin
; Purpose:    Return the minimum of 2 signed values.
; Arguments:  Arg1: First signed word.
;             Arg2: Second signed word.
;             Arg3: Optional destiantion register. Default is xax.
; Return:     DstReg/rax/eax/ax/al = Smallest signed value.

sMin macro Var1:req, Var2:req, DstReg:=<xax>
  $$Attribute = type(Var1)
  $$Reg textequ $SubReg(DstReg, $$Attribute)
  $$Word textequ $SubWord(<SQWORD>, $$Attribute)

  ifidni <Var2>, $$Reg
    .if $$Word ptr $$Reg > Var1
      mov $$Reg, Var1
    .endif
  else
    ifdifi <Var1>, $$Reg
      mov $$Reg, Var1
    endif
    .if $$Word ptr $$Reg > Var2
      mov $$Reg, Var2
    .endif
  endif
endm

$sMin macro Var1:req, Var2:req, DstReg:=<xax>
  sMin Var1, Var2, DstReg
  %exitm <$SubReg(DstReg, type(Var1))>
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      uMax / $uMax
; Purpose:    Return the maximum of 2 values.
; Arguments:  Arg1: First word.
;             Arg2: Second word.
;             Arg3: Optional destiantion register. Default is xax.
; Return:     DstReg/rax/eax/ax/al = Biggest value.

uMax macro Var1:req, Var2:req, DstReg:=<xax>
  $$Attribute = type(Var1)
  $$Reg textequ $SubReg(DstReg, $$Attribute)
  $$Word textequ $SubWord(<QWORD>, $$Attribute)

  ifidni <Var2>, $$Reg
    .if $$Word ptr $$Reg < Var1
      mov $$Reg, Var1
    .endif
  else
    ifdifi <Var1>, $$Reg
      mov $$Reg, Var1
    endif
    .if $$Word ptr $$Reg < Var2
      mov $$Reg, Var2
    .endif
  endif
endm

$uMax macro Var1:req, Var2:req, DstReg:=<xax>
  uMax Var1, Var2, DstReg
  %exitm <$SubReg(DstReg, type(Var1))>
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      uMin / $uMin
; Purpose:    Return the minimum of 2 values.
; Arguments:  Arg1: First value.
;             Arg2: Second value.
;             Arg3: Optional destiantion register. Default is xax.
; Return:     DstReg/rax/eax/ax/al = Smallest value.

uMin macro Var1:req, Var2:req, DstReg:=<xax>
  $$Attribute = type(Var1)
  $$Reg textequ $SubReg(DstReg, $$Attribute)
  $$Word textequ $SubWord(<QWORD>, $$Attribute)

  ifidni <Var2>, $$Reg
    .if $$Word ptr $$Reg > Var1
      mov $$Reg, Var1
    .endif
  else
    ifdifi <Var1>, $$Reg
      mov $$Reg, Var1
    endif
    .if $$Word ptr $$Reg > Var2
      mov $$Reg, Var2
    .endif
  endif
endm

$uMin macro Var1:req, Var2:req, DstReg:=<xax>
  uMin Var1, Var2, DstReg
  %exitm <$SubReg(DstReg, type(Var1))>
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      $uMini / uMini
; Purpose:    Return the smallest of 2 values.
; Arguments:  Arg1: Default rax = a, rcx = b
; Return:     Reg1/rax/eax/ax/al = $uMini(a,b)
; Uses:       Default are rax, rcx, rdx (Reg2 and AuxReg are trashed).

uMini macro Reg1:=<xax>, Reg2:=<xcx>, AuxReg:=<xdx>
  $$Attribute = type(Reg1)
  $$AuxReg textequ $SubReg(AuxReg, $$Attribute)

  cmp Reg1, Reg2
  sbb $$AuxReg, $$AuxReg
  and Reg1, $$AuxReg
  not $$AuxReg
  and Reg2, $$AuxReg
  or Reg1, Reg2
endm

$uMini macro Reg1:=<xax>, Reg2:=<xcx>, AuxReg:=<xdx>
  uMini Reg1, Reg2, AuxReg
  exitm <Reg1>
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      $uMaxi / uMaxi
; Purpose:    Return the maximum of 2 values.
; Arguments:  Arg1: Default rax = a, rcx = b
; Return:     Reg1/rax/eax/ax/al = $uMaxi(a,b)
; Uses:       Default are rax, rcx, rdx (Reg2 and AuxReg are trashed).

uMaxi macro Reg1:=<xax>, Reg2:=<xcx>, AuxReg:=<xdx>
  $$Attribute = type(Reg1)
  $$AuxReg textequ $SubReg(AuxReg, $$Attribute)

  cmp Reg1, Reg2
  sbb $$AuxReg, $$AuxReg
  and Reg2, $$AuxReg
  not $$AuxReg
  and Reg1, $$AuxReg
  or Reg1, Reg2
endm

$uMaxi macro Reg1:=<xax>, Reg2:=<xcx>, AuxReg:=<xdx>
  Maxi Reg1, Reg2, AuxReg
  exitm <Reg1>
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      $sMaxi / sMaxi
; Purpose:    Return the maximum of 2 signed values.
; Arguments:  rax = a, rdx = b
; Return:     rax/eax/ax/al = min(a,b), rdx/edx/dx/dl = max(a,b)
; Uses:       rax, rdx.

sMaxi macro Var1:req, Var2:req
  %ifidni <Var2>, <xax>
    .err <sMaxi - rax/eax/ax/al not allowed as second argument.>
  else
    %ifdifi <Var1>, <rax>
      mov xax, Var1
    endif
    sub xax, Var2                                       ;;a=a-b
    cdq                                                 ;;Sign-extend of eax => edx::eax
    not xdx                                             ;;d=0 if a<b,  d=-1  if a>=b
    and xax, xdx                                        ;;a=0 if a<b,  a=a-b if a>=b
    add xax, Var2                                       ;;a=b if a<b,  a=a   if a>=b
  endif
endm

$sMaxi macro Var1:req, Var2:req
  sMaxi Var1, Var2
  exitm <xax>
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      uMiniMaxi
; Purpose:    Return the minimum and maximun of 2 values.
; Arguments:  Reg1, Reg2
; Return:     Reg1 = min(Reg1, Reg2), Reg2 = max(Reg1, Reg2)
; Uses:       Reg1, Reg2, AuxReg1, AuxReg2

uMiniMaxi macro Reg1:=<xax>, Reg2:=<xbx>, AuxReg1:=<xcx>, AuxReg2:=<xdx>
  mov AuxReg2, Reg2
  sub AuxReg2, Reg1
  sbb AuxReg1, AuxReg1
  and AuxReg1, AuxReg2
  add Reg1, AuxReg1                                     ;;Reg1 = min(Reg1, Reg2)
  sub Reg2, AuxReg1                                     ;;Reg2 = max(Reg1, Reg2)
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      sMean / $sMean
; Purpose:    Compute (Reg1 + Reg2)/2 (signed values).
; Arguments:  Arg1: Reg1.
;             Arg2: Reg2.
;             Arg3: AuxReg.
; Return:     rax/eax/ax/al = (Reg1 + Reg2)/2.
; Uses:       Default rax, rcx, rdx (AuxReg is trashed).
; Note:       This algorithm can not overflow!

sMean macro Reg1:=<xax>, Reg2:=<xcx>, AuxReg:=<xdx>
  ifidni <Reg1>, <AuxReg>
    .err <sMean - use another auxiliar register.>
  else
    ifidni <Reg2>, <AuxReg>
      .err <sMean - use another auxiliar register.>
    else
      mov AuxReg, Reg1
      xor AuxReg, Reg2
      and Reg1, Reg2
      sar AuxReg, 1
      add Reg1, AuxReg
    endif
  endif
endm

$sMean macro Reg1:=<xax>, Reg2:=<xcx>, AuxReg:=<xdx>
  Mean Reg1, Reg2, AuxReg
  exitm <Reg1>
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      LoadRegIfLessThan
; Purpose:    Compare Reg with a value and load it according to the result.
; Arguments:  Arg1: Register to be comparend.
;             Arg2: Than value or register.
;             Arg3: Then value or register.
;             Arg4: Otherwise value or register.
;             Arg5: [optional] auxiliar register. Default edx.
; Return:     Register.

LoadRegIfLessThan macro Reg:req, Than:req, Then:req, Otherwise:req, AuxReg:=<xdx>
  sub Reg, Than
  sar Reg, 63
  ifidni <Otherwise>, <0>
    and xax, Then
  else
    if (opattr Then) and OAT_REGISTER                   ;;Is Then a register?
      sub Then, Otherwise
      and Reg, Then
      add Reg, Otherwise
    else
      ifidni <Reg>, <AuxReg>
        .err <LoadRegIfLessThan - Register corruption, use another auxiliar register.>
      else
        ifdifi <AuxReg>, <Then>
          mov AuxReg, Then
        endif
        sub AuxReg, Otherwise
        and Reg, AuxReg
        add Reg, Otherwise
      endif
    endif
  endif
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      HiWord / $HiWord
; Purpose:    Retrieve the high WORD from a DWORD.
; Arguments:  Arg1: DWORD.
; Return:     eax = High WORD.

HiWord macro Value, Reg:=<xax>
  ifdifi <Value>, <Reg>
    mov Reg, Value
  endif
  shr Reg, 16
  if type(Reg) gt 4
    and Reg, 0FFFFh                                     ;;Set to low WORD
  endif
endm

$HiWord macro Value, Reg:=<xax>
  HiWord Value
  exitm <Reg>
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      LoWord / $LoWord
; Purpose:    Retrieve the low WORD from a DWORD.
; Arguments:  Arg1: DWORD.
; Return:     eax = Low WORD.

LoWord macro Value, Reg:=<xax>
  ifdifi <Value>, <Reg>
    mov Reg, Value
  endif
  and Reg, 0FFFFh                                       ;;Set to low WORD
endm

$LoWord macro Value, Reg:=<xax>
  LoWord Value
  exitm <Reg>
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      $addr
; Purpose:    Get the runtime address of the operand. Used in those cases where "addr" is not
;             allowed.
; Arguments:  Arg1: Operand.
; Return:     Memory address of operand.

$addr macro Operand:req
  lea xax, [Operand]
  exitm <xax>
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      PushArgsFor
; Purpose:    Push all arguments on stack in reverse order.
; Arguments:  Arg1: API name.
;             Arg2: List of arguments.
; Return:     Nothing.

PushArgsFor macro ProcName:req, ArgList:vararg
  $$Arg = (opattr ProcName) and OAT_LANGUAGE            ;;$$Arg = Calling convention
  if $$Arg eq 0
    .err <Unknown procedure>
  elseif ($$Arg and 0000010000000000b)                  ;;Pascal, Fortran, Basic => push from L->R
    PushAll ArgList
  else                                                  ;;C, SYSCALL, STDCALL 0> push from R->L
    PushAllRev ArgList
  endif
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      $RGB
; Purpose:    Calculate a RGB value of the specified R/G/B/Alpha arguments.
; Arguments:  Arg1: Red component.
;             Arg2: Green component.
;             Arg3: Blue component.
;             Arg4: Alpha component (if any).
; Return:     RGB DWORD value (CRGB).

$RGB macro bRed:req, bGreen:req, bBlue:req, bAlpha:=<0>
  if bRed gt 255 or bRed lt 0
    .err <$RGB - Red color component out of limit.>
  endif
  if bGreen gt 255 or bGreen lt 0
    .err <$RGB - Green color component out of limit.>
  endif
  if bBlue gt 255 or bBlue lt 0
    .err <$RGB - Blue color component out of limit.>
  endif
  if bAlpha gt 255 or bAlpha lt 0
    .err <$RGB - Alpha color component out of limit.>
  endif
  exitm <256*(256*(256*bAlpha+bBlue)+bGreen)+bRed>
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      $BGR
; Purpose:    Calculate a RGB value of the specified B/G/R/Alpha arguments.
; Arguments:  Arg1: Blue component.
;             Arg2: Green component.
;             Arg3: Red component.
;             Arg4: Alpha component (if any).
; Return:     RGB DWORD value (RGBQUAD).

$BGR macro bBlue:req, bGreen:req, bRed:req, bAlpha:=<0>
  if bBlue gt 255 or bBlue lt 0
    .err <$BGR - Blue color component out of limit.>
  endif
  if bGreen gt 255 or bGreen lt 0
    .err <$BGR - Green color component out of limit.>
  endif
  if bRed gt 255 or bRed lt 0
    .err <$BGR - Red color component out of limit.>
  endif
  if bAlpha gt 255 or bAlpha lt 0
    .err <$BGR - Alpha color component out of limit.>
  endif
  exitm <256*(256*(256*bAlpha+bRed)+bGreen)+bBlue>
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      RGB2BGR
; Purpose:    Convert the color from RGB to BGR as it is usually stored in memory.
; Arguments:  Arg1: 32 bit register containeing the RGB/BRG color.

RGB2BGR macro Reg32                                     ;; AA RR GG BB
  rol Reg32, 8                                          ;; RR GG BB AA
  ror @SubStr(Reg32, 2), 8                              ;; RR GG AA BB
  rol Reg32, 16                                         ;; AA BB RR GG
  ror @SubStr(Reg32, 2), 8                              ;; AA BB GG RR
endm

BGR2RGB equ RGB2BGR   ;This macro can also be used for the inverse conversion.

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      $Lower
; Purpose:    Convert a text symbol to lowercase.
; Arguments:  Arg1: String symbol.

$Lower macro SymTxt:req
  $$LowerTxt textequ <>
  %forc $$LowerLetter, <SymTxt>
    $$LowerPos InStr <ABCDEFGHIJKLMNOPQRSTUVWXYZ>, <$$LowerLetter>
    if $$LowerPos gt 0
      $$LowerChar SubStr <abcdefghijklmnopqrstuvwxyz>, $$LowerPos, 1
    else
      $$LowerChar textequ <$$LowerLetter>
    endif
    $$LowerTxt CatStr $$LowerTxt, $$LowerChar
  endm
  exitm $$LowerTxt
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      $Upper
; Purpose:    Convert a text symbol to uppercase.
; Arguments:  Arg1: Text symbol.

$Upper macro SymTxt:req
  $$UpperTxt textequ <>
  %forc $$UpperLetter, <SymTxt>
    $$UpperPos InStr <abcdefghijklmnopqrstuvwxyz>, <$$UpperLetter>
    if $$UpperPos gt 0
      $$UpperChar SubStr <ABCDEFGHIJKLMNOPQRSTUVWXYZ>, $$UpperPos, 1
    else
      $$UpperChar textequ <$$UpperLetter>
    endif
    $$UpperTxt CatStr $$UpperTxt, $$UpperChar
  endm
  exitm $$UpperTxt
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      $IsFloat
; Purpose:    Check if a passed text is a floating point value.
; Arguments:  Arg1: Text representing a float.
; Link:       http://masm32.com/board/index.php?topic=4709.15
; Return:     TRUE for any REAL4/8/10 variable or decimal FP literal.
; Autor:      qWord
;
$IsFloat macro Arg:req
  ;handle memory operands and integer values
  if (opattr Arg) AND 2
    if (type Arg) eq (type REAL4) OR (type Arg) eq (type REAL8) OR (type Arg) eq (type REAL10)
      exitm <-1>
    endif
    exitm <0>
  elseif (opattr Arg)
    exitm <0>
  endif

  ;; Test for valid FP literal
  ;;
  ;; Used state machine
  ;;  state | end state | description
  ;;  ------+-----------+------------
  ;;   1    |    no     |   initial state
  ;;   2    |    no     |   sign
  ;;   3    |    no     |   integer digits
  ;;   4    |    yes    |   decimal dot and (optional) fraction digits
  ;;   5    |    no     |   exponent indicator
  ;;   6    |    no     |   exponent sign
  ;;   7    |    yes    |   exponent digits
  ;;
  ;; Transitions
  ;;  state | characters | new state
  ;;  ------+------------+------------
  ;;   1    |    +-      |  2
  ;;   1    |    0-9     |  3
  ;;   2    |    0-9     |  3
  ;;   3    |    0-9     |  3
  ;;   3    |    .       |  4
  ;;   4    |    0-9     |  4
  ;;   4    |    eE      |  5
  ;;   5    |    +-      |  6
  ;;   5    |    0-9     |  7
  ;;   6    |    0-9     |  7
  ;;   7    |    0-9     |  7
  ;;

  isflt_pos   = 1
  isflt_state = 1
  forc char,<&Arg>
  ;  %echo CHAR <char>, STATE: @CatStr(%isflt_state), POS: @CatStr(%isflt_pos)
    isflt_sigma substr <23 3344567 7 7>, isflt_state*2-1,2
    isflt_pos instr isflt_pos, <+-0123456789.0123456789Ee+-0123456789>, <&char>
    isflt_new_state substr <02233333333334444444444455667777777777>, isflt_pos+1,1
    isflt_transition instr isflt_sigma, isflt_new_state
    ife isflt_transition
      isflt_state = 0
      exitm
    endif
    isflt_state = isflt_new_state
    isflt_pos = @SubStr(<03030303030303030303030314141414141414141414142626282828282828282828282828>,%isflt_pos*2-1,2)
  endm

  if isflt_state eq 4 or isflt_state eq 7
    exitm <TRUE>
  endif
  exitm <FALSE>
endm

;; ——————————————————————————————————————————————————————————————————————————————————————————————————
;; Macro:      f4push
;; Purpose:    Push a series of REAL4 values diretly onto stack.
;; Arguments:  Arg1: REAL4 values.
;
;f4push macro r4Values:vararg
;    $$ArgList textequ $ArgRev(r4Values)
;%   for $$Arg, <$$ArgList>
;      db 68h                                            ;;push opcode
;      REAL4 $$Arg                                       ;;push argument = REAL4
;    endm
;endm
;
;; ——————————————————————————————————————————————————————————————————————————————————————————————————
;; Macro:      f4mov
;; Purpose:    Perform a mov with a REAL4 value.
;; Arguments:  Arg1: move destination.
;;             Arg2: REAL4 value.
;
;f4mov macro Destination:req, r4Value:req
;    mov Destination, 0FFFFFFFFh                         ;;Compile this
;    org $-4                                             ;;Replace 0FFFFFFFFh with
;    REAL4 r4Value                                       ;;  the REAL4 value
;endm
;
; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      $invoke
; Purpose:    Accelerator macro that calls a procedure and returns its return value in eax.
; Arguments:  Arg1: Procedure name to be called.
;             Arg2: Procedure arguments.
; Return:     Return value of the procedure in eax.

$invoke macro Func:req, Args:vararg
  ifnb <Args>
    invoke Func, Args
  else
    invoke Func
  endif
  exitm <xax>
endm

?invoke macro Func:req, Args:vararg
  ifnb <Args>
    invoke Func, Args
  else
    invoke Func
  endif
  exitm <eax>
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      $call
; Purpose:    Call invocation that returns eax.
; Arguments:  Arg1: Procedure name.
; Return:     Nothing.

$call macro Func:req
  call Func
  exitm <xax>
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      $MakeWord
; Purpose:    Compute a WORD value.
; Arguments:  Arg1: High order BYTE.
;             Arg2: Low order BYTE.
; Return:     DWORD value.

$MakeWord macro bHigh:=<0>, bLow:=<0>
  exitm <((bHigh shl 8) or bLow)>
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      $MakeDWord
; Purpose:    Compute a DWORD value.
; Arguments:  Arg1: High order WORD.
;             Arg2: Low order WORD.
; Return:     DWORD value.

$MakeDWord macro wHigh:=<0>, wLow:=<0>
  exitm <((wHigh shl 16) or wLow)>
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      IsPositive
; Purpose:    Return TRUE if the signed integer argument is >= 0, otherwise FALSE.
; Arguments:  Arg1: SDWORD
; Return:     TRUE or FALSE.

IsPositive macro Arg:req
  neg Arg
  shr Arg, 8*@WordSize - 1
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      IsNegative
; Purpose:    Return TRUE if the signed integer argument is < 0, otherwise FALSE.
; Arguments:  Arg1: SDWORD
; Return:     TRUE or FALSE.

IsNegative macro Arg:req
  shr Arg, 8*@WordSize - 1
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      MSB32
; Purpose:    Compute the most significant "1" bit in a DWORD.
; Arguments:  Arg1: Argument value in a register.
;             Arg2: (optional) Auxiliar register.
; Return:     Result in input register.

MSB32 macro Reg32:req, AuxReg:=<edx>
  ifidni <Reg32>, <AuxReg>
    .err <MSB32 - register corruption, use another auxiliar register.>
  else
    $$Count = 1
    repeat 5
      mov AuxReg, Reg32
      shr Reg32, $$Count
      or Reg32, AuxReg
      $$Count = 2 * $$Count
    endm
    mov AuxReg, Reg32
    shr Reg32, 1
    not Reg32
    and Reg32, AuxReg
  endif
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      LSB32
; Purpose:    Compute the least significant "1" bit in a DWORD.
; Arguments:  Arg1: Argument value in a register.
;             Arg2: (optional) Auxiliar register.
; Return:     Result in input register.

LSB32 macro Reg32:req, AuxReg:=<edx>
  ifidni <Reg>, <AuxReg>
    .err <LSB32 - register corruption, use another auxiliar register.>
  else
    mov AuxReg, Reg32
    neg Reg32
    and Reg32, AuxReg
  endif
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      NLPo2
; Purpose:    Compute the Next Largest Power of 2 of a DWORD.
; Arguments:  Arg1: Argument value in a register.
;             Arg2: (optional) Auxiliar register.
; Return:     Result in input register.

NLPo2 macro Reg32:req, AuxReg:=<edx>
  ifidni <Reg>, <AuxReg>
    .err <NLPo2: register corruption, use another auxiliar register.>
  else
    $$Count = 1
    repeat 5
      mov AuxReg, Reg32
      shr Reg32, $$Count
      or Reg32, AuxReg
      $$Count = 2 * $$Count
    endm
    inc Reg32
  endif
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      PopulationCount32
; Purpose:    Count the number of "1"s in a DWORD.
; Arguments:  Arg1: Argument value in a register.
;             Arg2: (optional) Auxiliar register.
; Return:     Result in input register.

PopulationCount32 macro Reg32:req, AuxReg:=<edx>
  ifidni <Reg32>, <AuxReg>
    .err <PopulationCount32 - register corruption, use another auxiliar register.>
  else
    mov AuxReg, Reg32
    shr Reg32, 1
    and Reg32, 055555555h
    sub AuxReg, Reg32
    mov Reg32, AuxReg
    shr Reg32, 2
    and AuxReg, 033333333h
    and Reg32, 033333333h
    add AuxReg, Reg32
    mov Reg32, AuxReg
    shr Reg32, 4
    add Reg32, AuxReg
    and Reg32, 00F0F0F0Fh
    mov AuxReg, Reg32
    shr AuxReg, 8
    add Reg32, AuxReg
    mov AuxReg, Reg32
    shr AuxReg, 16
    add Reg32, AuxReg
    and Reg32, 00000003Fh
  endif
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      TZC32 Trailing Zero Count
; Purpose:    Count the number of trailing "0"s in a DWORD.
; Arguments:  Arg1: Argument value in a register.
;             Arg2: (optional) Auxiliar register.
; Return:     Result in input register.

TZC32 macro Reg32:req, AuxReg:=<edx>
  ifidni <Reg32>, <AuxReg>
    .err <TZC32: register corruption, use another auxiliar register.>
  else
    LSB32 Reg32, AuxReg
    dec Reg32
    PopulationCount Reg32, AuxReg
  endif
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      ReverseBits32
; Purpose:    Reverse the bits in a DWORD.
; Arguments:  Arg1: Argument value in a register.
;             Arg2: (optional) Auxiliar register.
; Return:     Result in input register.

ReverseBits32 macro Reg32:req, AuxReg:=<edx>
  ifidni <Reg32>, <AuxReg>
    .err <ReverseBits32 - Register corruption, use another auxiliar register.>
  else
    mov AuxReg, Reg32
    and Reg32, 0AAAAAAAAh
    shr Reg32, 1
    and AuxReg, 055555555h
    shl AuxReg, 1
    or Reg32, AuxReg

    mov AuxReg, Reg32
    and Reg32, 0CCCCCCCCh
    shr Reg32, 2
    and AuxReg, 033333333h
    shl AuxReg, 2
    or Reg32, AuxReg

    mov AuxReg, Reg32
    and Reg32, 0F0F0F0F0h
    shr Reg32, 4
    and AuxReg, 00F0F0F0Fh
    shl AuxReg, 4
    or Reg32, AuxReg

    mov AuxReg, Reg32
    and Reg32, 0FF00FF00h
    shr Reg32, 8
    and AuxReg, 000FF00FFh
    shl AuxReg, 8
    or Reg32, AuxReg

    mov AuxReg, Reg32
    shr Reg32, 16
    shl AuxReg, 16
    or Reg32, AuxReg
  endif
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      ReverseBitsShort32
; Purpose:    Reverse the bits in a DWORD.
; Arguments:  Arg1: Input register value.
;             Arg2: Output regiter value.
; Return:     Result in input register.
; Note:       Uses ecx.

ReverseBitsShort32 macro Reg32In:req, Reg32Out:req
  xor Reg32Out, Reg32Out
  mov ecx, 32
  ror Reg32In, 1
  jnc $+5
  btc Reg32Out, ecx
  loopz $-7
  ror Reg32Out, 1
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      IsInRange?
; Purpose:    Check if a specified value is in the range [Base...Top].
; Arguments:  Arg1: Value (register)
;             Arg2: Bottom.
;             Arg3: Top.
;             Arg4: (optional) Auxiliar register.
; Return:     Value (Arg) is 0 if it is in range, otherwise -1.
; Note:       Add an inc to Arg to the end of the macro to return TRUE or FALSE.

IsInRange? macro Arg:req, Bot:req, Top:req, AuxReg:=<xdx>
  ifidni <Arg>, <AuxReg>
    .err <IsInRange? - Register corruption, use another auxiliar register.>
  else
    if (opattr Arg) and OAT_REGISTER                    ;;Is Arg a register?
      cmp Top, Arg                                      ;;Set borrow flag for upper limit
      sbb AuxReg, AuxReg                                ;;Make 1111 or 0000 mask
      sub Arg, Bot                                      ;;Set borrow flag for lower limit
      sbb Arg, Arg                                      ;;Make 1111 or 0000 mask
      or Arg, AuxReg                                    ;;Combine masks
;;      inc Arg                                           ;;Convert to BOOL (TRUE / FALSE)
    else
      .err <IsInRange? - Arg must be a register.>
    endif
  endif
endm

$IsInRange? macro Arg:req, Bot:req, Top:req, AuxReg:=<xdx>
  IsInRange? Arg, Bot, Top, AuxReg
  exitm <ZERO?>
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      IsNotBetween?
; Purpose:    Check if a specified value is in between the range [Bot...Top], excluding the limits.
; Arguments:  Arg1: Value (register)
;             Arg2: Bottom
;             Arg3: Top
;             Arg4: (optional) Auxiliar register
; Return:     Value (Arg) is 0 if it is in range, otherwise -1.
; Note:       Add an inc to Arg to the end of the macro to return TRUE or FALSE.

IsNotBetween? macro Arg:req, Bot:req, Top:req, AuxReg:=<xdx>
  ifidni <Arg>, <AuxReg>
    .err <IsNotBetween - register corruption, use another auxiliar register.>
  else
    if (opattr Arg) and OAT_REGISTER                    ;;Is Arg a register?
      mov AuxArg, Arg
      cmp Bot, Arg                                      ;;Set borrow flag for lower limit
      sbb AuxReg, AuxReg                                ;;Make 1111 or 0000 mask
      sub Arg, Top                                      ;;Set borrow flag for upper limit
      sbb Arg, Arg                                      ;;Make 1111 or 0000 mask
      and Arg, AuxReg                                   ;;Combine masks
;;      inc Arg                                           ;;Convert to BOOL (TRUE / FALSE)
    else
      .err <IsNotBetween - Arg must be a register.>
    endif
  endif
endm

$IsNotBetween? macro Arg:req, Bot:req, Top:req, AuxReg:=<xdx>
  IsNotBetween? Arg, Bot, Top, AuxReg
  exitm <ZERO?>
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      ClearLocals
; Purpose:    Clear all locals.
; Note:       Source of Edgar Harris (Donkey).

ClearLocals macro
  mov xdx, xdi                                          ;;Preserve xdi
  mov xcx, xbp                                          ;;Get the size of the stack
  sub xcx, xsp
  lea xdi, [xbp]                                        ;;Base of local variables
  sub xdi, xcx
  shr xcx, $Log2(@WordSize)
  xor eax, eax                                          ;;Fill with zeros
  rep stosx
  mov xdi, xdx                                          ;;Restore xdi
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      ht
; Purpose:    Insert a hint BYTE (hint taken) for conditional jumps.
; Note:       Must be inserted immediately before the conditional jump.
;             The rules for static prediction are:
;              - A forward branch defaults to not taken.
;              - A backward branch defaults to taken.
;             Once the processor has enough information, dynamic rules take over.

ht macro
  db 3Eh
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      hnt
; Purpose:    Insert a hint BYTE (hint not taken) for conditional jumps.
; Note:       Must be inserted immediately before the conditional jump.

hnt macro
  db 2Eh
endm

;; ——————————————————————————————————————————————————————————————————————————————————————————————————
;; Macro:      PrologueEx/EpilogEx
;; Purpose:    Extended functionality for procedure Prolog and Epilog generation.
;; Arguments:  Arg1: ProcName contains the name of the procedure.
;;             Arg2: Flags contains a WORD-size bit mask of settings:
;;                     Bits 0-2: Language type (000 - unspecified, 001 C, 010 SYSCALL, 011 STDCALL,
;;                            100 PASCAL, 101 FORTRAN, 110 BASIC, (111 is reserved).
;;                     Bit 3: (reserved).
;;                     Bit 4: 1 if the caller will restore the stack, 0 if the callee must.
;;                     Bit 5: FAR procedure.
;;                     Bit 6: PRIVATE procedure.
;;                     Bit 7: EXPORT procedure.
;;             Arg3: ArgBytes contains the number of bytes used by arguments.
;;             Arg4: LocalBytes contains the number of bytes defined using the local directive for
;;                   this procedure.
;;             Arg5: RegList contains a comma-delimited list of USES parameters
;;                   (registers which are to be preserved).
;;             Arg6: UserParms contains a list of other parameters specified.
;; Link:       http://msdn.microsoft.com/en-us/library/4zc781yh.aspx
;
;PrologueEx macro ProcName, Flags, ArgBytes, LocalBytes, RegList, UserParms:vararg
;  $$ClearStack = 0
;  $$NoFrame = 0
;  $$ForceFrame = 0
;
;  ifnb <UserParms>
;    %for param, <UserParms>
;      ifidni <param>, <FORCEFRAME>
;        $$ForceFrame = 1
;      elseifidni <param>, <NOFRAME>
;        $$NoFrame = 1
;      elseifidni <param>, <CLEARSTACK>
;        $$ClearStack = 1
;      endif
;    endm
;  endif
;  ;Der StackFrame wird immer erstellt, wenn local(LocalBytes <> 0) definiert ist. Niemals wenn
;  ;NOFRAME angegeben ist. Falls NOFRAME nicht, dafür aber FORCEFRAME definiert oder
;  ;ArgBytes <> 0 ist
;  if (LocalBytes ne 0) or ($$NoFrame eq 0 and $$ForceFrame + ArgBytes gt 0)
;    ;echo Build StackFrame
;    push rbp
;    mov rbp, rsp
;    ifdef PROFILING
;      ??DbgTracePrcCount CatStr <PrcCnt_>, <ProcName>
;      ??DbgTracePrcTicks CatStr <PrcTck_>, <ProcName>
;
;      ;;Create trace variables in the S_PROF
;      %ifndef ??DbgTracePrcCount
;        S_PROF segment
;          ??DbgTracePrcCount  DWORD  0
;          ??DbgTracePrcTicks  QWORD  0
;        S_PROF ends
;      endif
;      inc ??DbgTracePrcCount                          ;;Increment access counter
;      ;push eax
;      push rdx
;      rdtsc                                           ;;Get current tick count
;      sub ??DbgTracePrcTicks.LARGE_INTEGER.LowPart, eax
;      sbb ??DbgTracePrcTicks.LARGE_INTEGER.HighPart, edx
;      pop rdx
;      ;pop eax
;    endif
;
;    if LocalBytes gt 0
;      sub rsp, LocalBytes
;      if $$ClearStack gt 0
;        if LocalBytes le 20
;          $$ClearStack = LocalBytes
;          repeat $$ClearStack/4
;            mov DWORD ptr [rbp-$$ClearStack], 0
;            $$ClearStack = $$ClearStack - 4
;          endm
;        else
;          push rcx
;          push rdi
;          mov rcx, LocalBytes / 4
;          mov rdi,rbp
;          add rdi,-LocalBytes
;          xor eax, eax
;          rep stosd
;          pop rdi
;          pop rcx
;        endif
;      endif
;    endif
;  endif
;
;  ;; USES clause
;  ifnb <RegList>
;    for reg, RegList
;      push reg
;    endm
;  endif
;
;  exitm <LocalBytes>
;endm
;
;EpilogueEx macro ProcName, Flags, ArgBytes, LocalBytes, RegList, UserParms:vararg
;
;;;  Flags bit 8 will be set (1) if the epilogue was called using IRET, clear (0) if RET was used.
;;;  RegList is in reverse order from the prologue to make it easier to code.
;
;  $$NoFrame = 0
;  $$ForceFrame = 0
;  ifnb <UserParms>
;    %for param, <UserParms>
;      ifidni <param>, <FORCEFRAME>
;        $$ForceFrame = 1
;      elseifidni <param>, <NOFRAME>
;        $$NoFrame = 1
;      endif
;    endm
;  endif
;
;  ifdef PROFILING
;    ??DbgTracePrcCount CatStr <PrcCnt_>, <ProcName>
;    ??DbgTracePrcTicks CatStr <PrcTck_>, <ProcName>
;    push eax
;    push edx
;    rdtsc                                             ;;Get current tick count.
;    add ??DbgTracePrcTicks.LARGE_INTEGER.LowPart, eax ;;Compute tick difference.
;    adc ??DbgTracePrcTicks.LARGE_INTEGER.HighPart, edx
;    pop edx
;    pop eax
;  endif
;
;  ;;USES clause
;  ifnb <RegList>
;    for reg, RegList
;      pop reg
;    endm
;  endif
;
;  ;Der StackFrame wird immer erstellt, wenn local(LocalBytes <> 0) definiert ist.
;  ;Niemals wenn NOFRAME angegeben ist.
;  ;Falls NOFRAME nicht, dafür aber FORCEFRAME definiert oder ArgBytes <> 0 ist
;  if (LocalBytes ne 0) or ($$NoFrame eq 0 and $$ForceFrame + ArgBytes gt 0)
;    leave
;    ;echo Leave the Frame in Epilogue
;  endif
;
;  if Flags and 80h
;    iret
;  elseif (Flags AND 10h) or (ArgBytes eq 0)
;    ;; caller will restore stack
;    ret
;  else
;    ;; callee must restore stack
;    retn ArgBytes
;  endif
;endm
;
;; ——————————————————————————————————————————————————————————————————————————————————————————————————
;; Macro:     StackProbe
;; Purpose:   Allow a procedure to safely use LOCAL variables with a total size of more than the
;;            PageSize, using an unrolled stack probing method.
;; Usage:     OPTION PROLOGUE:StackProbe
;;            MyProcedure PROC ; ...
;;            ; ...
;;            MyProcedure ENDP
;;            OPTION PROLOGUE:PROLOGUEDEF
;; ML Manual: Your macro function must return the ParmBytes parameter. However, if the prologue
;;            places other values on the stack after pushing BP and these values are not referenced
;;            by any of the local variables, the exit value must be the number of bytes for procedure
;;            locals plus any space between BP and the locals. Therefore, ParmBytes is not always
;;            equal to the bytes occupied by the local.
;; Return:    Total byte count of local space. Usually LocalBytes.
;
;StackProbe macro ProcName, Flags, ArgBytes, LocalBytes, RegList, UserParms:vararg
;  ;;Set up stack frame
;  if LocalBytes gt 0
;    push xbp
;    mov xbp, xsp
;    if LocalBytes ge PAGESIZE                         ;Defined in Model.inc
;      ;;Round up to next page size
;      $$MaxProbe = (LocalBytes + PAGESIZE - 1) and (-PAGESIZE)
;      $$CurrProbe = PAGESIZE
;      ;;Unrolled stack probing
;      while $$CurrProbe le $$MaxProbe
;        ;;Probe stack
;        mov DWORD ptr [xbp - $$CurrProbe], xax
;        $$CurrProbe = $$CurrProbe + PAGESIZE
;      endm
;    endif
;    add xsp, -LocalBytes
;  elseif ArgBytes gt 0
;    push xbp
;    mov xbp, xsp
;  endif
;
;  ;;uses clause
;  ifnb <RegList>
;    for $$Reg, RegList
;      push $$Reg
;    endm
;  endif
;
;  exitm %LocalBytes
;endm
;
; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:     _Pause_
; Purpose:   Emulate the pause instruction.
; Note:      http://siyobik.info/index.php?module=x86&id=232

_Pause_ macro
  db 0F3h, 090h
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      FillMemZero
; Purpose:    Fill a memory range with zeros.
; Arguments:  Arg1: Mem to be filled.
;             Arg2: Mem size.
; Return:     Nothing.
; Example:    FillMemZero myString, 5

FillMemZero macro Var:req, ByteCount:req
  $$i = 0
  while $$i + sizeof(QWORD) le ByteCount
    m2z QWORD ptr Var[$$i]
    $$i = $$i + sizeof(QWORD)
  endm

  if (ByteCount and 4) eq 4
    m2z DWORD ptr Var[$$i]
    $$i = $$i + sizeof(DWORD)
  endif
  if (ByteCount and 2) eq 2
    m2z WORD ptr Var[$$i]
    $$i = $$i + sizeof(WORD)
  endif
  if (ByteCount and 1) eq 1
    m2z BYTE ptr Var[$$i]
  endif
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      FillMemByte
; Purpose:    Fill a memory range with a BYTE value.
; Arguments:  Arg1: Mem to be filled.
;             Arg2: Mem size.
;             Arg3: BYTE value.
; Return:     Nothing.

FillMemByte macro Var:req, ByteSize:req, ByteVal:req
  $$i = 0
  while $$i + 4 le ByteSize
    mov DWORD ptr Var[($$i)], 256*(256*(256*ByteVal + ByteVal) + ByteVal) + ByteVal
    $$i = $$i + 4
  endm

  if (ByteSize and 3) eq 1
    mov BYTE ptr Var[$$i], ByteVal
  elseif (ByteSize and 3) eq 2
    mov WORD ptr Var[$$i], 256*(256*ByteVal + ByteVal) + ByteVal
  elseif (ByteSize and 3) eq 3
    mov WORD ptr Var[$$i], 256*(256*ByteVal + ByteVal) + ByteVal
    mov BYTE ptr Var[$$i + 2], ByteVal
  endif
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      FillMemWord
; Purpose:    Fill a memory range with a WORD value.
; Arguments:  Arg1: Mem to be filled.
;             Arg2: Mem size.
;             Arg3: WORD value.
; Return:     Nothing.

FillMemWord macro Var:req, ByteSize:req, WordVal:req
  $$i = 0
  while $$i + 4 le ByteSize
    mov DWORD ptr Var[($$i)], 256*256*WordVal + WordVal
    $$i = $$i + 4
  endm

  if (ByteSize and 3) eq 2
    mov WORD ptr Var[$$i], WordVal
  endif
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      SaveFpuContext
; Purpose:    Save the FPU context that can be restored using LoadFpuContext. FPU is reinitialized.
; Arguments:  None.
; Return:     Nothing.

SaveFpuContext macro FpuContext:= <>
  ifb <FpuContext>
    sub xsp, FPU_CONTEXT_SIZE
    fsave [xsp]                                         ;;This instruction reinitializes the FPU
  else
    fsave FpuContext                                    ;;This instruction reinitializes the FPU
  endif
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      LoadFpuContext
; Purpose:    Reload the FPU context that was stored using SaveFpuContext.
; Arguments:  None.
; Return:     Nothing.

LoadFpuContext macro FpuContext:=<>
  ifb <FpuContext>
    frstor [xsp]
    add xsp, FPU_CONTEXT_SIZE
  else
    frstor FpuContext
  endif
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      $SubWord
; Purpose:    Return a subword according to the requested size.
; Arguments:  Arg1: Word type (signed or unsigned).
;             Arg2: Required size [1, 2, 4, 8].
; Return:     Word.

$SubWord macro WordType:req, WordSize:req
  SubWord textequ <-|-QWORD-DWORD-WORD-BYTE-|-SQWORD-SDWORD-SWORD-SBYTE-|->
  %$$Pos1 InStr <SubWord>, <@CatStr(<->, $Upper(WordType), <->)>
  if $$Pos1 eq 0
    .err <$SubWord - invalid word.>
    exitm <>
  else
    $$Pos1 = $$Pos1 - 2             ;2 = length of "-|"

    $$Flag = TRUE
    ;Search preceeding <-|-> marker
    while $$Flag
      %ifdif <@SubStr(<%SubWord>, $$Pos1, 3)>, <-|->
        $$Pos1 = $$Pos1 - 1
      else
        $$Flag = FALSE
      endif
    endm

    ;Search ending marker <->
    %$$Pos2 InStr $$Pos1 + 5, <SubWord>, <->
    if WordSize eq 8
      %exitm <@SubStr(<%SubWord>, $$Pos1 + 3, $$Pos2 - $$Pos1 - 3)>
    else
      $$Pos1 = $$Pos2 + 1
      %$$Pos2 InStr $$Pos1 + 2, <SubWord>, <->
      if WordSize eq 4
        %exitm <@SubStr(<%SubWord>, $$Pos1, $$Pos2 - $$Pos1)>
      else
        $$Pos1 = $$Pos2 + 1
        %$$Pos2 InStr $$Pos1 + 2, <SubWord>, <->
        if WordSize eq 2
          %exitm <@SubStr(<%SubWord>, $$Pos1, $$Pos2 - $$Pos1)>
        else
          $$Pos1 = $$Pos2 + 1
          %$$Pos2 InStr $$Pos1 + 2, <SubWord>, <->
          if WordSize eq 1
            %exitm <@SubStr(<%SubWord>, $$Pos1, $$Pos2 - $$Pos1)>
          else
            .err <$SubWord - invalid word size.>
          endif
        endif
      endif
    endif
  endif
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      $SubReg
; Purpose:    Return a subregister according to the requested size.
; Arguments:  Arg1: Register name.
;             Arg2: Required register size [1, 2, 4, 8] in bytes.
; Return:     Register.

$SubReg macro Reg:req, RegSize:req
  SubRegs textequ <-|-RAX-EAX-AX-AL-|-RBX-EBX-BX-BL-|-RCX-ECX-CX-CL-|-RDX-EDX-DX-DL-|-RDI-EDI-DI-DIL-|-RSI-ESI-SI-SIL-|-RBP-EBP-BP-BPL-|-RSP-ESP-SP-SPL-|-R8-R8D-R8W-R8B-|-R9-R9D-R9W-R9B-|-R10-R10D-R10W-R10B-|-R11-R11D-R11W-R11B-|-R12-R12D-R12W-R12B-|-R13-R13D-R13W-R13B-|-R14-R14D-R14W-R14B-|-R15-R15D-R15W-R15B-|->
  %$$Pos1 InStr <SubRegs>, <@CatStr(<->, $Upper(Reg), <->)>
  if $$Pos1 eq 0
    .err <$SubReg - invalid register.>
    exitm <>
  else
    $$Pos1 = $$Pos1 - 2             ;2 = length of "-|"

    $$Flag = TRUE
    ;Search preceeding <-|-> marker
    while $$Flag
      %ifdif <@SubStr(<%SubRegs>, $$Pos1, 3)>, <-|->
        $$Pos1 = $$Pos1 - 1
      else
        $$Flag = FALSE
      endif
    endm

    ;Search ending marker <->
    %$$Pos2 InStr $$Pos1 + 5, <SubRegs>, <->
    if RegSize eq 8
      %exitm <@SubStr(<%SubRegs>, $$Pos1 + 3, $$Pos2 - $$Pos1 - 3)>
    else
      $$Pos1 = $$Pos2 + 1
      %$$Pos2 InStr $$Pos1 + 2, <SubRegs>, <->
      if RegSize eq 4
        %exitm <@SubStr(<%SubRegs>, $$Pos1, $$Pos2 - $$Pos1)>
      else
        $$Pos1 = $$Pos2 + 1
        %$$Pos2 InStr $$Pos1 + 2, <SubRegs>, <->
        if RegSize eq 2
          %exitm <@SubStr(<%SubRegs>, $$Pos1, $$Pos2 - $$Pos1)>
        else
          $$Pos1 = $$Pos2 + 1
            %$$Pos2 InStr $$Pos1 + 2, <SubRegs>, <->
          if RegSize eq 1
            %exitm <@SubStr(<%SubRegs>, $$Pos1, $$Pos2 - $$Pos1)>
          else
            .err <$SubReg - invalid register size.>
          endif
        endif
      endif
    endif
  endif
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      $SubRegMM
; Purpose:    Return a mm subregister according to the requested size.
; Arguments:  Arg1: Register name.
;             Arg2: Required register size [16, 32, 64] (xmm, ymm, zmm) in bytes.
; Return:     Register.

$SubRegMM macro Reg:req, RegSize:req
  $$RegMM textequ $Upper(Reg)
  if @InStr(1, <%$$RegMM>, <MM>) eq 0
    .err <$SubRegMM - invalid register.>
    exitm <>
  else
    if RegSize eq 16
      %exitm <@CatStr(<X>, @SubStr(<%$$RegMM>, 2))>
    elseif RegSize eq 32
      %exitm <@CatStr(<Y>, @SubStr(<%$$RegMM>, 2))>
    elseif RegSize eq 64
      %exitm <@CatStr(<Z>, @SubStr(<%$$RegMM>, 2))>
    else
      .err <$SubRegMM - invalid register size.>
      exitm <>
    endif
  endif
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      $ChrReg
; Purpose:    Return a subregister according to the CHR size.
; Arguments:  Arg1: Register name.
; Return:     Register.

$ChrReg macro Reg:req
  if TARGET_STR_TYPE eq STR_TYPE_ANSI
    exitm $SubReg(Reg, 1)
  else
    exitm $SubReg(Reg, 2)
  endif
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      $64, $32, $16, $8
; Purpose:    Return a subregister according to the destination size.
; Arguments:  Arg1: Register name.
; Return:     Register.

$64 macro Reg:req
  %exitm <$SubReg(Reg, 8)>
endm

$32 macro Reg:req
  %exitm <$SubReg(Reg, 4)>
endm

$16 macro Reg:req
  %exitm <$SubReg(Reg, 2)>
endm

$8 macro Reg:req
  %exitm <$SubReg(Reg, 1)>
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      GetInterruptTicks
; Purpose:    Return the interrupt tick count since system start.
;             Interrupt ticks are triggered each 100 ns! The count is monotone.
;             The count is gattered from a system shared memory area known as KUSER_SHARED_DATA,
;             which is always at the same location (7FFE0000h) on Windows systems since NT.
; Arguments:  Arg1: (optional) Destination memory where the count should be stored (QWORD).
; Return:     rax = tick count.

GetInterruptTicks macro Dest
  if TARGET_BITNESS eq 32
    mov ecx, 7FFE0000h + 8                              ;KUSER_SHARED_DATA.InterruptTime @ MM_SHARED_USER_DATA_VA
    .while TRUE
      mov edx, [ecx + 4]                                ;KSYSTEM_TIME.High1Time
      mov eax, [ecx]                                    ;KSYSTEM_TIME.LowPart
      .break .if edx == [ecx + 8]                       ;KSYSTEM_TIME.High2Time
    .endw
    ifnb <Dest>
      mov DWORD ptr [Dest], eax
      mov DWORD ptr [Dest + 4], edx
    endif
  else
    mov r11d, 7FFE0000h + 8                             ;KUSER_SHARED_DATA.InterruptTime @ MM_SHARED_USER_DATA_VA
    mov rax, [r11]                                      ;KSYSTEM_TIME.High1Time
    ifnb <Dest>
      mov QWORD ptr [Dest], rax
    endif
  endif
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      $Log2
; Purpose:    Return the Log2 of a Number at compile time.
; Arguments:  Arg1: Input Number.
; Return:     Log base 2 of Number.

$Log2 macro Number:req
  $$Text textequ <>
  pushcontext radix
  .radix 2
  $$Text textequ %Number
  popcontext radix
  if Number ne 0
    exitm @CatStr(%(@SizeStr(%$$Text)-1))
  else
    exitm <0>
  endif
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      StackAlign
; Purpose:    Align down the stack to a specified boundary.
; Arguments:  Boundary in bytes.
; Note:       Uses an auxiliary register, default is edx.

if TARGET_BITNESS eq 32
  StackAlign macro Boundary:req, AuxReg:=<edx>
    if Boundary eq 4 or Boundary eq 8 or Boundary eq 16 or Boundary eq 32 or Boundary eq 64 or Boundary eq 128
      ??StackAlignCount = ??StackAlignCount + 1           ;;Increment counter
      mov AuxReg, esp                                     ;;Save esp
      sub esp, 4                                          ;;Reserve room for a DWORD
      and esp, not (Boundary - 1)                         ;;Align stack
      mov [esp], AuxReg                                   ;;Save previous esp value
    else
      .err <invalid alignment argument>
    endif
  endm
else
  StackAlign macro Boundary:req, AuxReg:=<r15>
    if Boundary eq 4 or Boundary eq 8 or Boundary eq 16 or Boundary eq 32 or Boundary eq 64 or Boundary eq 128
      ??StackAlignCount = ??StackAlignCount + 1           ;;Increment counter
      mov AuxReg, rsp                                     ;;Save esp
      sub rsp, @WordSize                                  ;;Reserve room for a QWORD
      and rsp, -Boundary                                  ;;Align stack
      mov [rsp], AuxReg                                   ;;Save previous esp value
    else
      .err <StackAlign - invalid alignment.>
    endif
  endm
endif

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      StackRestore
; Purpose:    Restore the stack to the previous boundary.
; Arguments:  None.

if TARGET_BITNESS eq 32
  StackRestore macro AdditionalSpace
    if ??StackAlignCount ne 0
      ifnb <AdditionalSpace>
        add esp, &AdditionalSpace
      endif
      pop esp                                             ;;Restore esp
      ??StackAlignCount = ??StackAlignCount - 1           ;;Decrement counter
    else
      .err <invalid alignment restoration>
    endif
  endm
else
  StackRestore macro AdditionalSpace
    if ??StackAlignCount ne 0
      ifnb <AdditionalSpace>
        add rsp, &AdditionalSpace
      endif
      pop r15
      mov rsp, r15                                        ;;Restore rsp
      ??StackAlignCount = ??StackAlignCount - 1           ;;Decrement counter
    else
      .err <StackRestore - invalid alignment.>
    endif
  endm
endif

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      $CurSeg
; Purpose:    Returns the simplified current segment name.
; Arguments:  None.

$CurSeg  macro
  $$Arg textequ @CurSeg
  ifidn $$Arg, <CONST>
    exitm <.const>
  elseifidn $$Arg, <_BSS>
    exitm <.data?>
  elseifidn $$Arg, <_DATA>
    exitm <.data>
  elseifidn $$Arg, <_TEXT>
    exitm <.code>
  else
    exitm <>
  endif
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      EchoOpAttr
; Purpose:    Echo OpAttr value.
; Arguments:  None.

EchoOpAttr macro Value
  $$Attr = opattr(Value)
  if $$Attr and OAT_REFERENCE
    echo OpAttr(Value) = Bit0 set: References a code label
  endif
  if $$Attr and OAT_RELOCATABLE
    echo OpAttr(Value) = Bit1 set: Is a memory variable or has a relocatable data label
  endif
  if $$Attr and OAT_IMMEDIATE
    echo OpAttr(Value) = Bit2 set: Is an immediate value
  endif
  if $$Attr and OAT_DIRECT_MEM
    echo OpAttr(Value) = Bit3 set: Uses direct memory addressing
  endif
  if $$Attr and OAT_REGISTER
    echo OpAttr(Value) = Bit4 set: Is a register value
  endif
  if $$Attr and OAT_NO_ERROR
    echo OpAttr(Value) = Bit5 set: References no undefined symbols and is without error
  endif
  if $$Attr and OAT_SS_RELATIVE
    echo OpAttr(Value) = Bit6 set: Is relative to SS
  endif
  if $$Attr and OAT_EXTERNAL
    echo OpAttr(Value) = Bit7 set: References an external label
  endif
  if $$Attr and OAT_LANGUAGE eq OAT_LANG_NONE
    echo OpAttr(Value) = Bit8-10: No language type
  endif
  if $$Attr and OAT_LANGUAGE eq OAT_LANG_C
    echo OpAttr(Value) = Bit8-10: C language
  endif
  if $$Attr and OAT_LANGUAGE eq OAT_LANG_SYSCALL
    echo OpAttr(Value) = Bit8-10: SYSCALL language
  endif
  if $$Attr and OAT_LANGUAGE eq OAT_LANG_STDCALL
    echo OpAttr(Value) = Bit8-10: STDCALL language
  endif
  if $$Attr and OAT_LANGUAGE eq OAT_LANG_PASCAL
    echo OpAttr(Value) = Bit8-10: Pascal language
  endif
  if $$Attr and OAT_LANGUAGE eq OAT_LANG_FORTRAN
    echo OpAttr(Value) = Bit8-10: Fortran language
  endif
  if $$Attr and OAT_LANGUAGE eq OAT_LANG_BASIC
    echo OpAttr(Value) = Bit8-10= Basic language
  endif
  if $$Attr and OAT_BIT_11
    echo OpAttr(Value) = Bit11 set
  endif
  if $$Attr and OAT_BIT_12
    echo OpAttr(Value) = Bit12 set
  endif
  if $$Attr and OAT_BIT_13
    echo OpAttr(Value) = Bit13 set
  endif
  if $$Attr and OAT_BIT_14
    echo OpAttr(Value) = Bit14 set
  endif
  if $$Attr and OAT_BIT_15
    echo OpAttr(Value) = Bit15 set
  endif
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      ANNOTATION
; Purpose:    Pass a hint to external tools.
; Arguments:  Hints, separated by commas.
; Examples:   ANNOTATION prv:rdi rsi
;             ANNOTATION use:Point Arg1 xdi

ANNOTATION macro What:vararg
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      $ToStr
; Purpose:    Used to echo a numeric symbol.
; Arguments:  Symbol name.
; Use:        %echo $ToStr(%Number)

$ToStr macro Num
  exitm <Num>
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      $HexYY and variations
; Purpose:    Used to echo a numeric symbol in hexadecimal notation.
; Arguments:  Symbol name.
; Use:        %echo $Hex32(%Number)

$Hex32 macro Num32
  pushcontext radix
  .radix 16
  ??HexStr catstr %Num32, <h>
  popcontext radix
  exitm ??HexStr
endm

$Hex64 macro Num64
  pushcontext radix
  .radix 16
  ??HexStr catstr %HIGH32 Num64, %LOW32 Num64, <h>
  popcontext radix
  exitm ??HexStr
endm

$Hex64Lo macro Num64
  pushcontext radix
  .radix 16
  ??HexStr catstr %LOW32 Num64, <h>
  popcontext radix
  exitm ??HexStr
endm

$Hex64Hi macro Num64
  pushcontext radix
  .radix 16
  ??HexStr catstr %HIGH32 Num64, <h>
  popcontext radix
  exitm ??HexStr
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      ?mov
; Purpose:    Compile mov instruction if TARGET_BITNESS = 32.
; Arguments:  Arg1: First mov.
;             Arg2: Second mov.

?mov macro Arg1:req, Arg2:req
if TARGET_BITNESS eq 32
  mov Arg1, Arg2
endif
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      ??mov
; Purpose:    Compile mov instruction if TARGET_BITNESS = 64.
; Arguments:  Arg1: First mov.
;             Arg2: Second mov.

??mov macro Arg1:req, Arg2:req
  if TARGET_BITNESS eq 64
    mov Arg1, Arg2
  endif
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      LocReg
; Purpose:    Declares the use of a symbol as a register or as a local.
;             if TARGET_BITNESS eq 64, all occurences of the symbol are replaced by the register
;             name, otherwise the local is used.
; Arguments:  Expression of the form SymbolName1:Register1, SymbolName2:Register2...
; Example:    LocReg pOwner:rdx

LocReg macro ExpressionList:vararg
  ifb <??ObjectContext>
    .err LocReg - out of method context
  else
    for $$Expression, <ExpressionList>
      $$Pos1 InStr <$$Expression>, <:>
      if $$Pos1 ne 0
        $$SName textequ @CatStr(%??ObjectContext, %??MethodContext, <_>, @SubStr(<$$Expression>, 1, $$Pos1 - 1))
        $$RName SubStr <$$Expression>, $$Pos1 + 1
      else
        .err LocReg - syntax error: $$Expression
      endif

      if TARGET_BITNESS eq 64
        %$$SName equ $$RName
      else
        %ifidni <$$RName>, <$SubReg($$RName, 1)>
          local $$SName:BYTE
        %elseifidni <$$RName>, <$SubReg($$RName, 2)>
          local $$SName:WORD
        %elseifidni <$$RName>, <$SubReg($$RName, 4)>
          %local $$SName:DWORD
        %elseifidni <$$RName>, <$SubReg($$RName, 8)>
          local $$SName:QWORD
        else
          echo $$RName - Unknown register size
        endif
      endif
    endm
  endif
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      $LocReg
; Purpose:    Replaces the Expression with the corresponding local or register.
; Arguments:  SymbolName declared with LocReg.

$LocReg macro SymbolName
  ifb <??ObjectContext>
    .err $LocReg - out of method context
  else
    exitm @CatStr(%??ObjectContext, %??MethodContext, <_>, SymbolName)
  endif
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      $LocReg32
; Purpose:    Replaces the Expression with the corresponding local or 32 bit register.
; Arguments:  SymbolName declared with LocReg.

$LocReg32 macro SymbolName
  ifb <??ObjectContext>
    .err $LocReg - out of method context
  else
    if (opattr @CatStr(%??ObjectContext, %??MethodContext, <_>, SymbolName)) and OAT_REGISTER
      exitm $SubReg(@CatStr(%??ObjectContext, %??MethodContext, <_>, SymbolName), 4)
    else
      exitm @CatStr(%??ObjectContext, %??MethodContext, <_>, SymbolName)
    endif
  endif
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      ArgReg
; Purpose:    Declares the use of a symbol as a register or as an method argument argument.
;             If TARGET_BITNESS eq 64, all occurences of the symbol are replaced by the register
;             name, otherwise the method argument is used.
; Arguments:  Expression of the form SymbolName1:Register1, SymbolName2:Register2...
; Example:    ArgReg pOwner:rdx

ArgReg macro ExpressionList:vararg
  ifb <??ObjectContext>
    .err ArgReg - out of method context
  else
    for $$Expression, <ExpressionList>
      $$Pos1 InStr <$$Expression>, <:>
      if $$Pos1 ne 0
        $$SName textequ @CatStr(%??ObjectContext, %??MethodContext, <_>, @SubStr(<$$Expression>, 1, $$Pos1 - 1))
        $$RName SubStr <$$Expression>, $$Pos1 + 1
      else
        .err ArgReg - syntax error: $$Expression
      endif

      if TARGET_BITNESS eq 64
        %$$SName equ $$RName
      else
        %$$SName SubStr <$$Expression>, 1, $$Pos1 - 1
      endif
    endm
  endif
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      $ArgReg
; Purpose:    Replaces the Expression with the corresponding argument or register.
; Arguments:  SymbolName.

$ArgReg macro SymbolName
  ifb <??ObjectContext>
    .err $ArgReg - out of method context
  else
    exitm @CatStr(%??ObjectContext, %??MethodContext, <_>, SymbolName)
  endif
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      $ArgReg32
; Purpose:    Replaces the Expression with the corresponding argument or 32 bit register.
; Arguments:  SymbolName.

$ArgReg32 macro SymbolName
  ifb <??ObjectContext>
    .err $ArgReg - out of method context
  else
    if (opattr @CatStr(%??ObjectContext, %??MethodContext, <_>, SymbolName)) and OAT_REGISTER
      exitm $SubReg(@CatStr(%??ObjectContext, %??MethodContext, <_>, SymbolName), 4)
    else
      exitm @CatStr(%??ObjectContext, %??MethodContext, <_>, SymbolName)
    endif
  endif
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      pushfx
; Purpose:    Compile pushfd or pushfq according to TARGET_BITNESS.
; Arguments:  None.

if TARGET_BITNESS eq 32
  pushfx equ <pushfd>
else
  pushfx equ <pushfq>
endif

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      popfx
; Purpose:    Compile popfd or popfq according to TARGET_BITNESS.
; Arguments:  None.

if TARGET_BITNESS eq 32
  popfx equ <popfd>
else
  popfx equ <popfq>
endif

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      pushaq
; Purpose:    Simile to pushad but for 64 bit. Order of pushed values equal to pushad.
; Arguments:  None.
; Note:       rsp is not the value of the instruction begin, like it is using pushad.

pushaq macro
  push rax                                              ;;15
  push rcx                                              ;;14
  push rdx                                              ;;13
  push rbx                                              ;;12
  push rsp                                              ;;11
  push rbp                                              ;;10
  push rsi                                              ;; 9
  push rdi                                              ;; 8
  push r8                                               ;; 7
  push r9                                               ;; 6
  push r10                                              ;; 5
  push r11                                              ;; 4
  push r12                                              ;; 3
  push r13                                              ;; 2
  push r14                                              ;; 1
  push r15                                              ;; 0
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      popaq
; Purpose:    Simile to popaq but for 64 bit.
; Arguments:  None.

popaq macro
  pop r15
  pop r14
  pop r13
  pop r12
  pop r11
  pop r10
  pop r9
  pop r8
  pop rdi
  pop rsi
  pop rbp
  pop rsp
  pop rbx
  pop rdx
  pop rcx
  pop rax
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      pushax
; Purpose:    Compile pushad or pushaq according to TARGET_BITNESS.
; Arguments:  None.

if TARGET_BITNESS eq 32
  pushax equ <pushad>
else
  pushax equ <pushaq>
endif

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      popax
; Purpose:    Compile popad or popaq according to TARGET_BITNESS.
; Arguments:  None.

if TARGET_BITNESS eq 32
  popax equ <popad>
else
  popax equ <popaq>
endif

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      stosx
; Purpose:    Compile stosd or stosq according to TARGET_BITNESS.
; Arguments:  None.

if TARGET_BITNESS eq 32
  stosx equ <stosd>
else
  stosx equ <stosq>
endif

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      stosc
; Purpose:    Compile stosb or stosw according to TARGET_STR_TYPE.
; Arguments:  None.

if TARGET_STR_TYPE eq STR_TYPE_ANSI
  stosc equ <stosb>
else
  stosc equ <stosw>
endif

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      movsc
; Purpose:    Compile movsb or movsw according to TARGET_STR_TYPE.
; Arguments:  None.

if TARGET_STR_TYPE eq STR_TYPE_ANSI
  movsc equ <movsb>
else
  movsc equ <movsw>
endif

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      scasc
; Purpose:    Compile scasb or scasw according to TARGET_STR_TYPE.
; Arguments:  None.

if TARGET_STR_TYPE eq STR_TYPE_ANSI
  scasc equ <scasb>
else
  scasc equ <scasw>
endif

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      lodsc
; Purpose:    Compile lodsb or lodsw according to TARGET_STR_TYPE.
; Arguments:  None.

if TARGET_STR_TYPE eq STR_TYPE_ANSI
  lodsc equ <lodsb>
else
  lodsc equ <lodsw>
endif

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      @Random
; Purpose:    Compile-time random number generator.
; Arguments:  Arg1: Range.
; Return:     Integer [0..Range-1]

@Random macro Range
  ifndef @RandSeed
    @RandSeed = @CatStr(@SubStr(<%@Time>, 1, 2), @SubStr(<%@Time>, 4, 2), @SubStr(<%@Time>, 7, 2))
  endif
  ;Xn = (aXn-1 + b) mod m
  @RandSeed = ((@RandSeed*0A126CDF1h) + 0CA379C13h) mod 024DC5A39h
  exitm %@CatStr(%(@RandSeed mod (Range)))
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      @Err
; Purpose:    Compile-time error generation.
; Arguments:  Arg1: Message
; Return:     Nothing.

@Err macro Text:=<>
  %echo Text
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      GetMemBSS
; Purpose:    Reserve a data block from the bss segment (block starting symbol).
;             bss is equivalent to .data? and contains uninitialized static variables.
; Arguments:  Arg1: Data size.
; Return:     Symbol name.

GetMemBSS macro DataSize:= <0>
  local DataName

  bss segment
  align @WordSize
  if DataSize eq 0
    .err <Invalid argument in GetMemBSS>
  elseif DataSize eq 1
    DataName BYTE ?
  elseif DataSize eq 2
    DataName WORD ?
  elseif DataSize eq 4
    DataName DWORD ?
  elseif DataSize eq 8
    DataName QWORD ?
  elseif DataSize eq 16
    DataName OWORD ?
  else
    DataName BYTE DataSize dup(?)
  endif
  bss ends
  exitm <DataName>
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      Enum
; Purpose:    Implement the well known Enum C-functionality.
; Arguments:  Arg1: Enumeration start.
;             Arg2..n: Enumeration list.
; Example:    Enum <Pepa, Pepe, Pepi>, 1

Enum macro Args, InitCount:=<0>
  $$Count = InitCount
  for $$Arg, <Args>
    $$Arg equ $$Count
    $$Count = $$Count + 1
  endm
endm
