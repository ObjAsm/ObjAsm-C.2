; ==================================================================================================
; Title:      h2inc+_IncFile_Mac.inc
; Author:     G. Friedrich
; Version:    See h2inc+.asm
; Purpose:    ObjAsm h2inc+ IncFile macros.
; ==================================================================================================


; --------------------------------------------------------------------------------------------------
; Macros:     xxx@Stacklist
; Purpose:    Memory list implemented like a stack. Total max capacity 1024 entries.

.data?
StackList XWORD 1024 dup(?)                             ;1024 entries should be enough

.data
StackListPtr POINTER offset StackList                   ;-> Next free (XWORD) slot

$Create@Stacklist macro AuxReg:=<xax>
  mov AuxReg, StackListPtr
  exitm <AuxReg>                                        ;-> Stack base
endm

Destroy@Stacklist macro pStackBase:req, AuxReg:=<xax>
  .if pStackBase != NULL
    mov AuxReg, pStackBase
    mov StackListPtr, AuxReg
  .endif
endm

Reset@Stacklist macro pStackBase:req, AuxReg:=<xax>
  .if pStackBase != NULL
    mov AuxReg, pStackBase
    mov StackListPtr, AuxReg
  .endif
endm

Add@Stacklist macro pStackBase:req, pItem:req, AuxReg:=<xax>
  mov AuxReg, StackListPtr
  if (opattr pItem) and OAT_REGISTER
    mov [AuxReg], pItem                                 ;Save item
  else
    push pItem
    pop [AuxReg]                                        ;Save item
  endif
  add StackListPtr, sizeof(XWORD)
endm

$GetCount@Stacklist macro pStackBase:req, AuxReg:=<xax>
  mov AuxReg, StackListPtr
  sub AuxReg, pStackBase
  shr $SubReg(AuxReg, sizeof(DWORD)), $Log2(Sizeof(XWORD))
  exitm <$SubReg(AuxReg, sizeof(DWORD))>                ;Return count
endm

$GetItem@Stacklist macro pStackBase:req, dIndex:req, AuxReg1:=<xax>, AuxReg2:=<xcx>
  mov AuxReg1, pStackBase
  mov $SubReg(AuxReg2, sizeof(DWORD)), dIndex
  shl $SubReg(AuxReg2, sizeof(DWORD)), $Log2(Sizeof(XWORD))
  exitm <XWORD ptr [AuxReg1 + AuxReg2]>
endm

; --------------------------------------------------------------------------------------------------
; Macro:      WritePtr
; Purpose:    StmWrite multiple "ptr".

WritePtr macro
  .while dPtrCount != 0
    OCall xbx::IncFile.StmWrite, addr szPtrSpace
    dec dPtrCount
  .endw
endm

; --------------------------------------------------------------------------------------------------
; Macro:      IsStructure?
; Purpose:    Check if token is a structure name.
; Arguments:  Arg1: -> Token to be tested. Must be a Var or a non volatile register.
; Return:     eax = TRUE if token is a known structure name, otherwise FALSE

IsStructure? macro pToken:req
  OCall pKnwStructs::List.Search, pToken
  .if eax == FALSE
    OCall pNewStructs::List.Search, pToken
  .endif
endm

; --------------------------------------------------------------------------------------------------
; Macro:      IsValidName?
; Purpose:    Check if token is a valid name.
; Arguments:  Arg1: -> Token to be tested.
; Return:     eax = TRUE if valid, otherwise FALSE.

IsValidName? macro pToken:req
  mov xcx, pToken
  mov eax, TRUE
  mov cl, [xcx]
  .if ((cl >= "A") && (cl <= "Z")) || ((cl >= "a") && (cl <= "z"))
    jmp @F
  .elseif (cl == "_") || (cl == "?") || (cl == "@") || (cl == "~")
    jmp @F
  .endif
  xor eax, eax                                          ;FALSE
@@:
endm

; --------------------------------------------------------------------------------------------------
; Macro:      BasicTypeCScan
; Purpose:    Helper macro to identifiy basic C types. It sets dTypeCSpec using CTS_xxx.
; Arguments:  xax -> Current token.
; Return:     xax -> Next token.
;             dTypeCSpec with matching CTS_xxx value.

BasicTypeCScan macro
  mov dTypeCSpec, 0                                     ;Reset dTypeCSpec
                                                        ;Step 0
  .if $DoesStringMatchA?([xax], <unsigned>)
    BitSet dTypeCSpec, CTS_unsigned
    OCall xbx::IncFile.GetNextTokenC
    test xax, xax
    jz @ErrorEoF
    jmp @F
  .endif
  .if $DoesStringMatchA?([xax], <signed>)
    BitSet dTypeCSpec, CTS_signed
    OCall xbx::IncFile.GetNextTokenC
    test xax, xax
    jz @ErrorEoF
    jmp @F
  .endif
@@:                                                     ;Step 1
  .if $DoesStringMatchA?([xax], <long>)
    BitSet dTypeCSpec, CTS_long
    OCall xbx::IncFile.GetNextTokenC
    test xax, xax
    jz @ErrorEoF
    jmp @F
  .endif
  .if $DoesStringMatchA?([xax], <short>)
    BitSet dTypeCSpec, CTS_short
    OCall xbx::IncFile.GetNextTokenC
    test xax, xax
    jz @ErrorEoF
    jmp @F
  .endif
@@:                                                     ;Step 2
  .if $DoesStringMatchA?([xax], <long>)
    BitSet dTypeCSpec, CTS_long2
    OCall xbx::IncFile.GetNextTokenC
    test xax, xax
    jz @ErrorEoF
    jmp @F
  .endif
@@:                                                     ;Step 3
  .if $DoesStringMatchA?([xax], <void>)
    BitSet dTypeCSpec, CTS_void
    OCall xbx::IncFile.GetNextTokenC
    test xax, xax
    jz @ErrorEoF
    jmp @F
  .endif
  .if $DoesStringMatchA?([xax], <char>)
    BitSet dTypeCSpec, CTS_char
    OCall xbx::IncFile.GetNextTokenC
    test xax, xax
    jz @ErrorEoF
    jmp @F
  .endif
  .if $DoesStringMatchA?([xax], <bool>)
    BitSet dTypeCSpec, CTS_bool
    OCall xbx::IncFile.GetNextTokenC
    test xax, xax
    jz @ErrorEoF
    jmp @F
  .endif
  .if $DoesStringMatchA?([xax], <int>)
    BitSet dTypeCSpec, CTS_int
    OCall xbx::IncFile.GetNextTokenC
    test xax, xax
    jz @ErrorEoF
    jmp @F
  .endif
  .if $DoesStringMatchA?([xax], <float>)
    BitSet dTypeCSpec, CTS_float
    OCall xbx::IncFile.GetNextTokenC
    test xax, xax
    jz @ErrorEoF
    jmp @F
  .endif
  .if $DoesStringMatchA?([xax], <double>)
    BitSet dTypeCSpec, CTS_double
    OCall xbx::IncFile.GetNextTokenC
    test xax, xax
    jz @ErrorEoF
    jmp @F
  .endif
  .if $DoesStringMatchA?([xax], <__int8>)
    BitSet dTypeCSpec, CTS___int8
    OCall xbx::IncFile.GetNextTokenC
    test xax, xax
    jz @ErrorEoF
    jmp @F
  .endif
  .if $DoesStringMatchA?([xax], <__int16>)
    BitSet dTypeCSpec, CTS___int16
    OCall xbx::IncFile.GetNextTokenC
    test xax, xax
    jz @ErrorEoF
    jmp @F
  .endif
  .if $DoesStringMatchA?([xax], <__int32>)
    BitSet dTypeCSpec, CTS___int32
    OCall xbx::IncFile.GetNextTokenC
    test xax, xax
    jz @ErrorEoF
    jmp @F
  .endif
  .if $DoesStringMatchA?([xax], <__int64>)
    BitSet dTypeCSpec, CTS___int64
    OCall xbx::IncFile.GetNextTokenC
    test xax, xax
    jz @ErrorEoF
    jmp @F
  .endif
  .if $DoesStringMatchA?([xax], <__wchar_t>)
    BitSet dTypeCSpec, CTS___wchar_t
    OCall xbx::IncFile.GetNextTokenC
    test xax, xax
    jz @ErrorEoF
;      jmp @F
  .endif
@@:                                                     ;Exit
endm

; --------------------------------------------------------------------------------------------------
; Macro:      IsIfLevelActive?
; Purpose:    Check if a given If-Level is active.
; Arguments:  Arg1: INP_STAT variable.
;             xbx -> IncFile.
; Return:     ZF set if current if level is NOT active.

IsIfLevelActive? macro InpStat
  movzx edx, InpStat.bCondIfLevel
  mov cl, InpStat.bCondElseLevel[xdx - 1]
  mov ch, [xbx].$Obj(IncFile).bCondElseLevel[xdx - 1]
  exitm <(dl != [xbx].$Obj(IncFile).bCondIfLevel || cl == ch)>
endm

; --------------------------------------------------------------------------------------------------
; Macro:      IsPublicPrivateProtected?
; Purpose:    Check if token is 'private', 'public' or 'protected'.
; Arguments:  Arg1: -> Token.
; Return:     eax = TRUE if found, otherwise FALSE.

IsPublicPrivateProtected? macro pToken
  mov xcx, pToken
  mov eax, TRUE
  .if !$DoesStringMatchA?([xcx], <public>)
    .if !$DoesStringMatchA?([xcx], <private>)
      .if !$DoesStringMatchA?([xcx], <protected>)
        xor eax, eax
      .endif
    .endif
  .endif
endm

; --------------------------------------------------------------------------------------------------
; Macro:      IncIfLevel
; Purpose:    Increment '#if' level.
; Arguments:  None.
; Return:     Nothing.

IncIfLevel macro
  .if [xbx].$Obj(IncFile).bCondIfLevel == MAX_COND_LEVEL
    OCall xbx::IncFile.ShowError, addr szNesting2Deep
  .else
    inc [xbx].$Obj(IncFile).bCondIfLevel
    movzx eax, [xbx].$Obj(IncFile).bCondIfLevel
    mov [xbx].$Obj(IncFile).bCondElseLevel[xax - 1], 0
    mov [xbx].$Obj(IncFile).bCondResult[xax - 1], PPR_FALSE
    mov [xbx].$Obj(IncFile).bCondHistory[xax - 1], PPR_FALSE
  .endif
endm

; --------------------------------------------------------------------------------------------------
; Macro:      IncElseLevel
; Purpose:    Increment '#else' level.
; Arguments:  None.
; Return:     Nothing.

IncElseLevel macro
  movzx eax, [xbx].$Obj(IncFile).bCondIfLevel
  .if eax != 0
    inc [xbx].$Obj(IncFile).bCondElseLevel[xax - 1]
  .else
    OCall xbx::IncFile.ShowError, addr szElseWoIf
  .endif
endm

; --------------------------------------------------------------------------------------------------
; Macro:      DecIfLevel
; Purpose:    Decrement '#if' level.
; Arguments:  xbx -> IncFile.
; Return:     Nothing.

DecIfLevel macro
  .if [xbx].$Obj(IncFile).bCondIfLevel != 0
    dec [xbx].$Obj(IncFile).bCondIfLevel
  .else
    OCall xbx::IncFile.ShowError, addr szEndifWoIf
  .endif
endm

; --------------------------------------------------------------------------------------------------
; Macro:      SkipPPLine
; Purpose:    Skip PP tokens until EOL.
; Arguments:  xbx -> IncFile.
; Return:     Nothing.

SkipPPLine macro
  .repeat
    OCall xbx::IncFile.GetNextTokenPP
  .until xax == NULL
endm

; --------------------------------------------------------------------------------------------------
; Macro:      StmOutLoad
; Purpose:    Restore the StmOut status from a local storage variable.
; Arguments:  Arg1: -> STMOUT_STAT.
;             Arg2: Optional return register.
; Return:     RetReg = [xbx].$Obj(IncFile).pStmOutPos.

StmOutLoad macro Var, RetReg:=<xax>
  m2m [xbx].$Obj(IncFile).dIndentation, Var.dIndentation, eax
  m2m [xbx].$Obj(IncFile).dStmOutEoL, Var.dStmOutEoL, eax
  mrm [xbx].$Obj(IncFile).pStmOutPos, Var.pStmOutPos, RetReg
endm

; --------------------------------------------------------------------------------------------------
; Macro:      StmOutSave
; Purpose:    Save the StmOut status on a local variable.
; Arguments:  -> STMOUT_STAT.
;             Arg2: Optional return register.
; Return:     RetReg = [xbx].$Obj(IncFile).pStmOutPos.

StmOutSave macro Var, RetReg:=<xax>
  m2m Var.dStmOutEoL, [xbx].$Obj(IncFile).dStmOutEoL, eax
  m2m Var.dIndentation, [xbx].$Obj(IncFile).dIndentation, eax
  mrm Var.pStmOutPos, [xbx].$Obj(IncFile).pStmOutPos, RetReg
endm
