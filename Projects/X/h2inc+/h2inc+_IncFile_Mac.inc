; ==================================================================================================
; Title:    h2inc+_IncFile_Mac.inc
; Author:   G. Friedrich
; Version:  C.2.0
; Purpose:  ObjAsm h2inc+ IncFile macros.
; Notes:    See h2inc+.asm
; ==================================================================================================


;; ——————————————————————————————————————————————————————————————————————————————————————————————————
;; Macros:    xxx@Stacklist
;; Purpose:   Local stack list.
;
;$Create@Stacklist macro
;  push 0                                              ;Stack count
;  exitm <xsp>                                         ;-> Stack reference (-> Count)
;endm
;
;Destroy@Stacklist macro pStackRef
;  .if pStackRef != NULL
;    mov xsp, pStackRef
;    add xsp, sizeof(DWORD)                            ;Dispose Count
;  .endif
;endm
;
;Reset@Stacklist macro pStackRef
;  mov xsp, pStackRef                                  ;Reset stack
;  mov DWORD ptr [xsp], 0                              ;Reset count
;endm
;
;Add@Stacklist macro pStackRef, pItem
;  push pItem                                          ;Save item
;  mov xcx, pStackRef
;  inc DWORD ptr [xcx]                                 ;Increment count
;endm
;
;$GetCount@Stacklist macro pStackRef
;  mov xax, pStackRef
;  exitm <DWORD ptr [xax]>                             ;Return count
;endm
;
;$GetItem@Stacklist macro pStackRef, dIndex
;  mov xax, pStackRef
;  mov ecx, dIndex
;  shl ecx, 2
;  sub xax, xcx
;  exitm <XWORD ptr [xax - sizeof(DWORD)]>
;endm


; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macros:    xxx@Stacklist
; Purpose:   Stack list.

.data?
StackList XWORD 1024 dup(?)                           ;1024 entries should be enough

.data
StackListPtr POINTER offset StackList                 ;-> Next free (XWORD) slot

$Create@Stacklist macro
  mov xax, StackListPtr 
  exitm <xax>                                         ;-> Stack reference
endm

Destroy@Stacklist macro pStackRef
  .if pStackRef != NULL
    mov xax, pStackRef
    mov StackListPtr, xax
  .endif
endm

Reset@Stacklist macro pStackRef
  .if pStackRef != NULL
    mov xax, pStackRef
    mov StackListPtr, xax
  .endif
endm

Add@Stacklist macro pStackRef, pItem
  mov xax, StackListPtr
  if (opattr pItem) and OAT_REGISTER
    mov [xax], pItem                                  ;Save item
  else
    push pItem
    pop [xax]                                         ;Save item
  endif
  add StackListPtr, sizeof(XWORD)
endm

$GetCount@Stacklist macro pStackRef
  mov xax, StackListPtr
  sub xax, pStackRef
  shr eax, $Log2(Sizeof(XWORD))
  exitm <eax>                                         ;Return count
endm

$GetItem@Stacklist macro pStackRef, dIndex
  mov xax, pStackRef
  mov ecx, dIndex
  shl ecx, $Log2(Sizeof(XWORD))
  exitm <XWORD ptr [xax + xcx]>
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:     WritePtr
; Purpose:   StmWrite multiple "ptr".

WritePtr macro
  .while dPtrCount != 0
    OCall xbx::IncFile.StmWrite, offset szPtrSpace
    dec dPtrCount
  .endw
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:     IsStructure?
; Purpose:   Check if token is a structure name.
; Arguments: Arg1 -> Token to test. Must be a Var or a non volatile register.
; Return:    eax = TRUE if token is a known structure name, otherwise FALSE

IsStructure? macro pToken
  OCall pKnownStructs::List.Search, pToken
  .if eax == FALSE
    OCall pStructs::List.Search, pToken
  .endif
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:     IsName?
; Purpose:   Check if token is a valid name.
; Arguments: Arg1 -> Token to test.
; Return:    eax = TRUE if valid, otherwise FALSE.

IsName? macro pToken
  mov xcx, pToken
  mov eax, TRUE
  mov cl, [xcx]
  .if (cl >= "A") && (cl <= "Z")
    jmp @F
  .elseif (cl >= "a") && (cl <= "z")
    jmp @F
  .elseif (cl == "_") || (cl == "?") || (cl == "@")
    jmp @F
  .elseif (cl == "~") && ([xbx].$Obj(IncFile).bInsideClass != FALSE)  ;C++ Class destructor
    jmp @F
  .endif
  xor eax, eax                                        ;FALSE
@@:
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:     BasicTypeCScan
; Purpose:   Helper macro to identifiy basic C types. It sets a variable using CTS_xxx.
; Arguments: xax -> current Token.

BasicTypeCScan macro
  mov dTypeCSpec, 0                                    ;Reset dTypeCSpec
                                                      ;Step 0
  .if $DoesStringMatchA?([xax], <unsigned>)
    BitSet dTypeCSpec, CTS_unsigned
    OCall xbx::IncFile.GetNextToken
    test xax, xax
    jz @Error
    jmp @F
  .endif
  .if $DoesStringMatchA?([xax], <signed>)
    BitSet dTypeCSpec, CTS_signed
    OCall xbx::IncFile.GetNextToken
    test xax, xax
    jz @Error
    jmp @F
  .endif
@@:                                                     ;Step 1
  .if $DoesStringMatchA?([xax], <long>)
    BitSet dTypeCSpec, CTS_long
    OCall xbx::IncFile.GetNextToken
    test xax, xax
    jz @Error
    jmp @F
  .endif
  .if $DoesStringMatchA?([xax], <short>)
    BitSet dTypeCSpec, CTS_short
    OCall xbx::IncFile.GetNextToken
    test xax, xax
    jz @Error
    jmp @F
  .endif
@@:                                                     ;Step 2
  .if $DoesStringMatchA?([xax], <long>)
    BitSet dTypeCSpec, CTS_long2
    OCall xbx::IncFile.GetNextToken
    test xax, xax
    jz @Error
    jmp @F
  .endif
@@:                                                     ;Step 3
  .if $DoesStringMatchA?([xax], <void>)
    BitSet dTypeCSpec, CTS_void
    OCall xbx::IncFile.GetNextToken
    test xax, xax
    jz @Error
    jmp @F
  .endif
  .if $DoesStringMatchA?([xax], <char>)
    BitSet dTypeCSpec, CTS_char
    OCall xbx::IncFile.GetNextToken
    test xax, xax
    jz @Error
    jmp @F
  .endif
  .if $DoesStringMatchA?([xax], <bool>)
    BitSet dTypeCSpec, CTS_bool
    OCall xbx::IncFile.GetNextToken
    test xax, xax
    jz @Error
    jmp @F
  .endif
  .if $DoesStringMatchA?([xax], <int>)
    BitSet dTypeCSpec, CTS_int
    OCall xbx::IncFile.GetNextToken
    test xax, xax
    jz @Error
    jmp @F
  .endif
  .if $DoesStringMatchA?([xax], <float>)
    BitSet dTypeCSpec, CTS_float
    OCall xbx::IncFile.GetNextToken
    test xax, xax
    jz @Error
    jmp @F
  .endif
  .if $DoesStringMatchA?([xax], <double>)
    BitSet dTypeCSpec, CTS_double
    OCall xbx::IncFile.GetNextToken
    test xax, xax
    jz @Error
    jmp @F
  .endif
  .if $DoesStringMatchA?([xax], <__int8>)
    BitSet dTypeCSpec, CTS___int8
    OCall xbx::IncFile.GetNextToken
    test xax, xax
    jz @Error
    jmp @F
  .endif
  .if $DoesStringMatchA?([xax], <__int16>)
    BitSet dTypeCSpec, CTS___int16
    OCall xbx::IncFile.GetNextToken
    test xax, xax
    jz @Error
    jmp @F
  .endif
  .if $DoesStringMatchA?([xax], <__int32>)
    BitSet dTypeCSpec, CTS___int32
    OCall xbx::IncFile.GetNextToken
    test xax, xax
    jz @Error
    jmp @F
  .endif
  .if $DoesStringMatchA?([xax], <__int64>)
    BitSet dTypeCSpec, CTS___int64
    OCall xbx::IncFile.GetNextToken
    test xax, xax
    jz @Error
    jmp @F
  .endif
  .if $DoesStringMatchA?([xax], <__wchar_t>)
    BitSet dTypeCSpec, CTS___wchar_t
    OCall xbx::IncFile.GetNextToken
    test xax, xax
    jz @Error
;      jmp @F
  .endif
@@:                                                     ;Exit
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:     IsIfLevelActive?
; Purpose:   Check if a given If-Level is active.
; Arguments: Arg1: INP_STAT variable.
; Return:    ZERO set if current if level is NOT active.

IsIfLevelActive? macro InpStat
  movzx edx, InpStat.bIfLevel
  mov cl, InpStat.bIfStructure[xdx - 1]
  mov ch, [xbx].$Obj(IncFile).bIfStructure[xdx - 1]
  exitm <(dl != [xbx].$Obj(IncFile).bIfLevel || cl == ch)>
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:     IsPublicPrivateProtected?
; Purpose:   Check if token is 'private', 'public' or 'protected'.
; Arguments: Arg1 -> token.
; Return:    eax = TRUE if found, otherwise FALSE.

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

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:     IncIfLevel
; Purpose:   Increment '#if' level.
; Arguments: None.
; Return:    Nothing.

IncIfLevel macro
  .if [xbx].$Obj(IncFile).bIfLevel == MAX_IF_LEVEL
    OCall xbx::IncFile.ShowError, offset szNesting2Deep
  .else
    inc [xbx].$Obj(IncFile).bIfLevel
    movzx eax, [xbx].$Obj(IncFile).bIfLevel
    mov [xbx].$Obj(IncFile).bIfStructure[xax - 1], 0
    mov [xbx].$Obj(IncFile).bIfResult[xax - 1], PPR_FALSE
    mov [xbx].$Obj(IncFile).bIfHistory[xax - 1], PPR_FALSE
  .endif
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:     IncElseLevel
; Purpose:   Increment '#else' level.
; Arguments: None.
; Return:    Nothing.

IncElseLevel macro
  movzx eax, [xbx].$Obj(IncFile).bIfLevel
  .if eax != 0
    inc [xbx].$Obj(IncFile).bIfStructure[xax - 1]
  .else
    OCall xbx::IncFile.ShowError, offset szElseWoIf
  .endif
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:     DecIfLevel
; Purpose:   Decrement '#if' level.
; Arguments: None.
; Return:    Nothing.

DecIfLevel macro
  .if [xbx].$Obj(IncFile).bIfLevel != 0
    dec [xbx].$Obj(IncFile).bIfLevel
  .else
    OCall xbx::IncFile.ShowError, offset szEndifWoIf
  .endif
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:     SkipPPLine
; Purpose:   Skip PP tokens until EOL.
; Arguments: None.
; Return:    Nothing.

SkipPPLine macro
  .repeat
    OCall xbx::IncFile.GetNextTokenFromPPLine
  .until xax == NULL
endm
