; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure: MakeTypeC2
; Purpose:   Build a C Type.
; Arguments: Arg1: -> Source Type.
;            Arg2: Unsigned flag.
;            Arg3: Signed flag.
;            Arg4: Long flag.
;            Arg5: -> Destination Type Buffer. Must be at least 256 bytes large!
; Return:    eax -> Destination Type Buffer (= Arg4).

;MakeTypeC2 proc pType:PSTRINGA, dTypeSpecC:DWORD, pDest:PSTRINGA
;    mov ecx, pDest
;
;    xor eax, eax
;    .ifBitSet dTypeSpecC, CTS_signed
;      FillStringA [ecx], <signed >
;      mov eax, 7
;    .elseIfBitSet dTypeSpecC, CTS_unsigned
;      FillStringA [ecx], <unsigned >
;      mov eax, 9
;    .endif
;    
;    .ifBitSet dTypeSpecC, CTS_short
;      FillStringA [ecx + eax], <short >
;      add eax, 6
;    .elseIfBitSet dTypeSpecC, CTS_long
;      FillStringA [ecx + eax], <long >
;      add eax, 5
;    .endif
;
;    .ifBitSet dTypeSpecC, CTS_long2
;      FillStringA [ecx + eax], <long >
;      add eax, 5
;    .endif
;
;    .ifBitSet dTypeSpecC, CTS_void
;      FillStringA [ecx + eax], < >
;      add eax, 1
;    .elseIfBitSet dTypeSpecC, CTS_char
;      FillStringA [ecx + eax], <char >
;      add eax, 5
;    .elseIfBitSet dTypeSpecC, CTS_bool
;      FillStringA [ecx + eax], <bool >
;      add eax, 5
;    .elseIfBitSet dTypeSpecC, CTS_int
;      FillStringA [ecx + eax], <int >
;      add eax, 4
;    .elseIfBitSet dTypeSpecC, CTS_float
;      FillStringA [ecx + eax], <float >
;      add eax, 6
;    .elseIfBitSet dTypeSpecC, CTS_double
;      FillStringA [ecx + eax], <double >
;      add eax, 7
;    .elseIfBitSet dTypeSpecC, CTS___int8
;      FillStringA [ecx + eax], <__int8 >
;      add eax, 7
;    .elseIfBitSet dTypeSpecC, CTS___int16
;      FillStringA [ecx + eax], <__int16 >
;      add eax, 8
;    .elseIfBitSet dTypeSpecC, CTS___int32
;      FillStringA [ecx + eax], <__int32 >
;      add eax, 8
;    .elseIfBitSet dTypeSpecC, CTS___int64
;      FillStringA [ecx + eax], <__int64 >
;      add eax, 8
;    .elseIfBitSet dTypeSpecC, CTS___wchar_t
;      FillStringA [ecx + eax], <__wchar_t >
;      add eax, 10
;    .else
;      .if pType != NULL
;        push ecx
;        invoke StrECopy, addr [ecx + eax], pType
;        mov DCHRA ptr [eax], " "
;        pop ecx
;        sub eax, ecx
;        inc eax                           ;Calc the new eax 
;      .endif
;    .endif
;    
;    .if eax == 0
;      .if pType == NULL
;        FillStringA [ecx], <long >
;      .else
;        invoke StrECopy, ecx, pType
;      .endif
;    .else
;      ;Trim last SPACE
;      mov CHRA ptr [ecx + eax - 1], 0
;    .endif 
;
;    ret
;MakeTypeC2 endp

