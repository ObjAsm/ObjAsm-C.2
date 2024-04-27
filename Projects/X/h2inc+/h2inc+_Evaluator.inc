; ==================================================================================================
; Title:    h2inc+_Evaluator.inc
; Author:   G. Friedrich
; Version:  C.2.0
; Purpose:  ObjAsm support of an Evaluator using the 'Shuntng Yard' algorithm.
; Notes:    Version C.2.0, Apil 2024
;             - First release.
; ==================================================================================================


EGN_UNKNOWN     equ   0           ;Can be defined or undefined!
EGN_UNDEF       equ   1
EGN_STRING      equ   2           ;Defined but not possible to be recognised
EGN_NUMBER      equ   3           ;Defined but not possible to be recognised
EGN_ERROR       equ  -1           ;Something went wrong

EVAL_KNOWN_SYMBOL struct
  pToken      PTOKEN      ?
  wGenus      WORD        ?
              WORD        ?
  Value       POINTER     ?       ;Placeholder for DWORD & POINTER values. 'union' doesn't work
EVAL_KNOWN_SYMBOL ends            ;  when initialized

ETT_SYMBOL      equ   1
ETT_IMMEDIATE   equ   2
ETT_OPERATOR    equ   3
ETT_PARENTHESIS equ   4
ETT_RESULT      equ   5

EVAL_TOKEN struct
  LDLL_MEMBER             {}
  pToken      PTOKEN      ?
  wType       WORD        ?       ;Number, Operator, Symbol
  wGenus      WORD        ?
  union
    dValue    DWORD       ?
    pOperator POINTER     ?
  ends
EVAL_TOKEN ends

;Precedence & associativity
EVAL_OPTOR struct
  pToken      PTOKEN      ?
  dPrece      DWORD       ?
  dAssoc      DWORD       ?
  pHandler    POINTER     ?
EVAL_OPTOR ends

ASO_RIGHT equ   BIT00
ASO_LEFT  equ   BIT01

.const
;https://en.wikipedia.org/wiki/Operators_in_C_and_C%2B%2B#Operator_precedence
EvalOperatorTable label POINTER
  EVAL_OPTOR <$OfsCBStrA("defined"), 00, ASO_RIGHT, offset EvalHandler_defined> ;Macro
  EVAL_OPTOR <$OfsCBStrA("WINAPI_FAMILY_PARTITION"), 00, ASO_RIGHT, offset EvalHandler_WAFP>
  EVAL_OPTOR <$OfsCBStrA(33),    01, ASO_RIGHT, offset EvalHandler_log_not> ;Logical NOT (!)
  EVAL_OPTOR <$OfsCBStrA("~"),   01, ASO_RIGHT, offset EvalHandler_bit_not> ;Bitwise NOT (1's compl)
  EVAL_OPTOR <$OfsCBStrA("*"),   02, ASO_LEFT,  offset EvalHandler_Mul>     ;Multiplication
  EVAL_OPTOR <$OfsCBStrA("/"),   02, ASO_LEFT,  offset EvalHandler_Div>     ;Division
  EVAL_OPTOR <$OfsCBStrA("%"),   02, ASO_LEFT,  offset EvalHandler_Mod>     ;Modulo
  EVAL_OPTOR <$OfsCBStrA("+"),   03, ASO_LEFT,  offset EvalHandler_Add>     ;Addition
  EVAL_OPTOR <$OfsCBStrA("-"),   03, ASO_LEFT,  offset EvalHandler_Sub>     ;Subtraction
  EVAL_OPTOR <$OfsCBStrA(60,60), 04, ASO_LEFT,  offset EvalHandler_ShiftL>  ;Bitwise left shift (<<)
  EVAL_OPTOR <$OfsCBStrA(62,62), 04, ASO_LEFT,  offset EvalHandler_ShiftR>  ;Bitwise right shift(>>)
  EVAL_OPTOR <$OfsCBStrA(60),    05, ASO_LEFT,  offset EvalHandler_lt>      ;Less than (<)
  EVAL_OPTOR <$OfsCBStrA(60,61), 05, ASO_LEFT,  offset EvalHandler_ltoet>   ;L. than or eq. to (<=)
  EVAL_OPTOR <$OfsCBStrA(62),    05, ASO_LEFT,  offset EvalHandler_gt>      ;Greater than (>)
  EVAL_OPTOR <$OfsCBStrA(62,61), 05, ASO_LEFT,  offset EvalHandler_gtoet>   ;G. than or eq. to (>=)
  EVAL_OPTOR <$OfsCBStrA("=="),  06, ASO_LEFT,  offset EvalHandler_eqt>     ;Equal to
  EVAL_OPTOR <$OfsCBStrA(33,"="),06, ASO_LEFT,  offset EvalHandler_neqt>    ;Not equal to
  EVAL_OPTOR <$OfsCBStrA("&"),   07, ASO_LEFT,  offset EvalHandler_bit_and> ;Bitwise AND
  EVAL_OPTOR <$OfsCBStrA("^"),   08, ASO_LEFT,  offset EvalHandler_bit_xor> ;Bitwise XOR (excl. OR)
  EVAL_OPTOR <$OfsCBStrA("|"),   09, ASO_LEFT,  offset EvalHandler_bit_or>  ;Bitwise OR (incl. OR)
  EVAL_OPTOR <$OfsCBStrA("&&"),  10, ASO_LEFT,  offset EvalHandler_log_and> ;Logical AND
  EVAL_OPTOR <$OfsCBStrA("||"),  11, ASO_LEFT,  offset EvalHandler_log_or>  ;Logical OR
  POINTER NULL

;Link: https://naughter.wordpress.com/2017/02/14/changes-in-the-windows-v10-0-15021-sdk-compared-to-windows-v10-0-14393-sdk-part-one/
EvalKnownSymbolTable label POINTER
  EVAL_KNOWN_SYMBOL <$OfsCBStrA("__cplusplus"),           EGN_UNDEF,  NULL> ;C++
  EVAL_KNOWN_SYMBOL <$OfsCBStrA("__cplusplus_winrt"),     EGN_UNDEF,  NULL> ;C++
  EVAL_KNOWN_SYMBOL <$OfsCBStrA("_CPPRTTI"),              EGN_UNDEF,  NULL> ;C++
  EVAL_KNOWN_SYMBOL <$OfsCBStrA("__INTELLISENSE__"),      EGN_UNDEF,  NULL> ;IntelliSense compiler
  EVAL_KNOWN_SYMBOL <$OfsCBStrA("MIDL_PASS"),             EGN_UNDEF,  NULL> ;MIDL
  EVAL_KNOWN_SYMBOL <$OfsCBStrA("__midl"),                EGN_UNDEF,  NULL> ;MIDL
  EVAL_KNOWN_SYMBOL <$OfsCBStrA("USE_MIDL_SYNTAX"),       EGN_UNDEF,  NULL> ;MIDL
  EVAL_KNOWN_SYMBOL <$OfsCBStrA("STRICT_GS_ENABLED"),     EGN_UNDEF,  NULL> ;GS switch enabled
  EVAL_KNOWN_SYMBOL <$OfsCBStrA("_ARM_"),                 EGN_UNDEF,  NULL> ;ARM
  EVAL_KNOWN_SYMBOL <$OfsCBStrA("_M_ARM"),                EGN_UNDEF,  NULL> ;ARM
  EVAL_KNOWN_SYMBOL <$OfsCBStrA("_M_ARM64"),              EGN_UNDEF,  NULL> ;ARM64
  EVAL_KNOWN_SYMBOL <$OfsCBStrA("_ARM64_"),               EGN_UNDEF,  NULL> ;ARM
  EVAL_KNOWN_SYMBOL <$OfsCBStrA("_CHPE_X86_ARM64_"),      EGN_UNDEF,  NULL> ;x86 on ARM
  EVAL_KNOWN_SYMBOL <$OfsCBStrA("_M_ARM_ARMV7VE"),        EGN_UNDEF,  NULL> ;ARM
  EVAL_KNOWN_SYMBOL <$OfsCBStrA("_M_ARM_FP"),             EGN_UNDEF,  NULL> ;ARM
  EVAL_KNOWN_SYMBOL <$OfsCBStrA("_M_MRX000"),             EGN_UNDEF,  NULL> ;
  EVAL_KNOWN_SYMBOL <$OfsCBStrA("_M_ALPHA"),              EGN_UNDEF,  NULL> ;Alpha
  EVAL_KNOWN_SYMBOL <$OfsCBStrA("_M_AXP64"),              EGN_UNDEF,  NULL> ;
  EVAL_KNOWN_SYMBOL <$OfsCBStrA("_MAC"),                  EGN_UNDEF,  NULL> ;Macintosh
  EVAL_KNOWN_SYMBOL <$OfsCBStrA("_MAC_INT_64"),           EGN_UNDEF,  NULL> ;Macintosh
  EVAL_KNOWN_SYMBOL <$OfsCBStrA("_MPPC_"),                EGN_UNDEF,  NULL> ;Macintosh PowerPC
  EVAL_KNOWN_SYMBOL <$OfsCBStrA("_M_PPC"),                EGN_UNDEF,  NULL> ;Macintosh PowerPC
  EVAL_KNOWN_SYMBOL <$OfsCBStrA("_M_MPPC"),               EGN_UNDEF,  NULL> ;Macintosh PowerPC
  EVAL_KNOWN_SYMBOL <$OfsCBStrA("_68K_"),                 EGN_UNDEF,  NULL> ;Motorola 68000
  EVAL_KNOWN_SYMBOL <$OfsCBStrA("_M_M68K"),               EGN_UNDEF,  NULL> ;Motorola 68000
  EVAL_KNOWN_SYMBOL <$OfsCBStrA("RC_INVOKED"),            EGN_UNDEF,  NULL> ;Resource Compiler
  EVAL_KNOWN_SYMBOL <$OfsCBStrA("_M_CEE"),                EGN_UNDEF,  NULL> ;Managed
  EVAL_KNOWN_SYMBOL <$OfsCBStrA("_M_CEE_PURE"),           EGN_UNDEF,  NULL> ;Managed
  EVAL_KNOWN_SYMBOL <$OfsCBStrA("_M_CEE_MIXED"),          EGN_UNDEF,  NULL> ;Managed
  EVAL_KNOWN_SYMBOL <$OfsCBStrA("_M_CEE_SAFE"),           EGN_UNDEF,  NULL> ;Managed
  EVAL_KNOWN_SYMBOL <$OfsCBStrA("_MANAGED"),              EGN_UNDEF,  NULL> ;Managed
  EVAL_KNOWN_SYMBOL <$OfsCBStrA("__CLR_VER"),             EGN_UNDEF,  NULL> ;Managed
  EVAL_KNOWN_SYMBOL <$OfsCBStrA("__cplusplus_cli"),       EGN_UNDEF,  NULL> ;Managed
  EVAL_KNOWN_SYMBOL <$OfsCBStrA("_NO_COM"),               EGN_UNDEF,  NULL> ;COM Interface
  EVAL_KNOWN_SYMBOL <$OfsCBStrA("COBJMACROS"),            EGN_UNDEF,  NULL> ;COM object macros
  EVAL_KNOWN_SYMBOL <$OfsCBStrA("CINTERFACE"),            EGN_UNDEF,  NULL> ;COM object macros
  EVAL_KNOWN_SYMBOL <$OfsCBStrA("_PREFAST_"),             EGN_UNDEF,  NULL> ;PREfast
  EVAL_KNOWN_SYMBOL <$OfsCBStrA("SORTPP_PASS"),           EGN_UNDEF,  NULL> ;SORTPP_PASS
  EVAL_KNOWN_SYMBOL <$OfsCBStrA("_POSIX_"),               EGN_UNDEF,  NULL> ;POSIX
  EVAL_KNOWN_SYMBOL <$OfsCBStrA("__USE_MSXML2_NAMESPACE__"), EGN_UNDEF,  NULL> ;MSXML
  EVAL_KNOWN_SYMBOL <$OfsCBStrA("__USE_MSXML6_NAMESPACE__"), EGN_UNDEF,  NULL> ;MSXML
  EVAL_KNOWN_SYMBOL <$OfsCBStrA("_WINDOWS_NUMERICS_INTEROP_NAMESPACE_"), EGN_UNDEF,  NULL> ;DirectX
  EVAL_KNOWN_SYMBOL <$OfsCBStrA("D2D_USE_C_DEFINITIONS"), EGN_NUMBER, 1>    ;DirectX
  EVAL_KNOWN_SYMBOL <$OfsCBStrA("D3D_DEBUG_INFO"),        EGN_UNDEF,  NULL> ;DirectX
  EVAL_KNOWN_SYMBOL <$OfsCBStrA("_XM_NO_INTRINSICS_"),    EGN_NUMBER, 1>    ;DirectX
  EVAL_KNOWN_SYMBOL <$OfsCBStrA("_XM_SSE_INTRINSICS_"),   EGN_UNDEF,  NULL> ;DirectX
  EVAL_KNOWN_SYMBOL <$OfsCBStrA("_XM_ARM_NEON_INTRINSICS_"), EGN_UNDEF,  NULL> ;DirectX

  EVAL_KNOWN_SYMBOL <$OfsCBStrA("_CTYPE_DISABLE_MACROS"), EGN_NUMBER, 1>    ;
  
  EVAL_KNOWN_SYMBOL <$OfsCBStrA("MICROSOFT_WINDOWS_WINBASE_INTERLOCKED_CPLUSPLUS_H_INCLUDED"), EGN_NUMBER, 0>
  EVAL_KNOWN_SYMBOL <$OfsCBStrA("_API_SET_HOST"),         EGN_UNDEF,  NULL> ;
  EVAL_KNOWN_SYMBOL <$OfsCBStrA("_WIN32"),                EGN_NUMBER, 1>    ;Win32 enabled
  EVAL_KNOWN_SYMBOL <$OfsCBStrA("0"),                     EGN_NUMBER, 0>
  EVAL_KNOWN_SYMBOL <$OfsCBStrA("1"),                     EGN_NUMBER, 1>
  POINTER NULL

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Object:  Evaluator
; Purpose: Implement an Evaluator using the 'Shunting Yard' algorithm.

Object Evaluator, 56123, Primer
  RedefineMethod    Done
  VirtualMethod     Evaluate
  VirtualMethod     GetNextEvalToken

  DefineVariable    Stack,          LDLL_CONTROL, {NULL, NULL}      ;An LSLL can be used here too
  DefineVariable    Queue,          LDLL_CONTROL, {NULL, NULL}
ObjectEnd


; ==================================================================================================

if IMPLEMENT

.code
; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:    Evaluator.Done
; Purpose:   Finalize the object.
; Arguments: None.
; Return:    Nothing.

Method Evaluator.Done, uses xsi
    SetObject xsi
    ACall xsi.Done
    .while TRUE
      lea xcx, [xsi].Queue
      .break .if [xcx].LDLL_CONTROL.pFirstMember == NULL
      mov xax, [xsi].Queue.pLastMember
      LDLL_RemoveLast [xsi].Queue, xcx
      MemFree xax
    .endw

    .while TRUE
      lea xcx, [xsi].Stack
      .break .if [xcx].LDLL_CONTROL.pFirstMember == NULL
      mov xax, [xsi].Queue.pLastMember
      LDLL_RemoveLast [xsi].Queue, xcx
      MemFree xax
    .endw
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:    Evaluator.Evaluate
; Purpose:   Evaluate the PreProcessor #if expression.
; Arguments: None.
; Return:    eax = PPR_FALSE, PPR_TRUE or PPR_UNKNOWN (evaluation result).
; Link:      https://en.wikipedia.org/wiki/Shunting-yard_algorithm

Method Evaluator.Evaluate, uses xdi xsi
    local pAuxToken:PTOKEN

    SetObject xsi

    ;Arrange Tokens in postfix notation using the 'Shunting Yard' algorithm.
    .while TRUE
      OCall xsi.GetNextEvalToken
      .break .if xax == NULL
      mov cx, [xax].EVAL_TOKEN.wType
      .if cx == ETT_RESULT || cx == ETT_SYMBOL || cx == ETT_IMMEDIATE
        LDLL_InsertLast [xsi].Queue, xax

      .elseif [xax].EVAL_TOKEN.wType == ETT_OPERATOR
        .while TRUE
          mov xcx, [xsi].Stack.pLastMember
          .break .if xcx == NULL
          .if [xcx].EVAL_TOKEN.wType == ETT_OPERATOR
            m2m pAuxToken, [xcx].EVAL_TOKEN.pToken, xdx
            mov xdx, [xcx].EVAL_TOKEN.pOperator
            mov ecx, [xdx].EVAL_OPTOR.dPrece
            mov xdi, [xax].EVAL_TOKEN.pOperator
            .if (ecx < [xdi].EVAL_OPTOR.dPrece || \
                (ecx == [xdi].EVAL_OPTOR.dPrece && [xdx].EVAL_OPTOR.dAssoc == ASO_LEFT))
              mov xdi, pAuxToken
              .if CHRA ptr [xdi] != "("
                mov xcx, [xsi].Stack.pLastMember
                LDLL_RemoveLast [xsi].Stack, xdi
                LDLL_InsertLast [xsi].Queue, xcx, xdx
                .continue
              .endif
            .endif
          .endif
          .break
        .endw
        LDLL_InsertLast [xsi].Stack, xax, xdx

      .else
        mov xdx, [xax].EVAL_TOKEN.pToken
        .if CHRA ptr [xdx] == "("
          LDLL_InsertLast [xsi].Stack, xax, xdx

        .elseif CHRA ptr [xdx] == ")"
          .while TRUE
            mov xcx, [xsi].Stack.pLastMember
            .break .if xcx == NULL
            mov xdx, [xcx].EVAL_TOKEN.pToken
            .if CHRA ptr [xdx] != "("
              LDLL_RemoveLast [xsi].Stack, xax
              LDLL_InsertLast [xsi].Queue, xcx, xdi
            .else
              .break
            .endif
          .endw
          LDLL_RemoveLast [xsi].Stack, xdi
          MemFree xax
        .endif
      .endif

    .endw

    .while TRUE
      .break .if [xsi].Stack.pLastMember == NULL
      mov xdx, [xsi].Stack.pLastMember
      LDLL_RemoveLast [xsi].Stack, xax
      LDLL_InsertLast [xsi].Queue, xdx, xax
    .endw

;    ;Show Queue
;    DbgLine
;    mov xax, [xsi].Queue.pFirstMember
;    .while TRUE
;      .break .if xax == NULL
;      DbgStr [xax].EVAL_TOKEN.pToken
;      mov xax, [xax].LDLL_MEMBER.pLinkFwrd
;    .endw
;    DbgLine

    ;Evaluate expression
    .while TRUE
      .break .if [xsi].Queue.pFirstMember == NULL
      mov xax, [xsi].Queue.pFirstMember
@MoveFwrd:
      .if [xax].EVAL_TOKEN.wType == ETT_OPERATOR
        mov xcx, [xax].EVAL_TOKEN.pOperator
        call [xcx].EVAL_OPTOR.pHandler                  ;xax -> EVAL_TOKEN
      .else
        mov xax, [xax].LDLL_MEMBER.pLinkFwrd
        .break .if xax == NULL
        jmp @MoveFwrd
      .endif
    .endw

    ;Now we decide if the result be used to discard a block of definitions in the .h file
    mov edi, PPR_FALSE
    mov xax, [xsi].Queue.pFirstMember
    mov dx, [xax].EVAL_TOKEN.wGenus
    .if dx == EGN_UNKNOWN || dx == EGN_ERROR
      mov edi, PPR_UNKNOWN
    .else
      .if [xax].EVAL_TOKEN.dValue != FALSE
        mov edi, PPR_TRUE
      .endif
    .endif

    LDLL_RemoveFirst [xsi].Queue, xcx
    MemFree xax
    mov eax, edi

@Error:

MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure: EvlHandler_xxx
; Purpose:   Evaluate mathematical or logical expressions.
; Arguments: xax -> EVAL_TOKEN.
; Return:    Nothing.

EvalArg1    equ <[xdx].EVAL_TOKEN>
EvalArg2    equ <[xdi].EVAL_TOKEN>
EvalResult  equ <[xax].EVAL_TOKEN>

EvalHandler_log_not proc
;    DbgText "Handler: not"
    mov EvalResult.wType, ETT_RESULT
    mov EvalResult.pToken, NULL
    mov xdx, [xax].LDLL_MEMBER.pLinkBack                ;Get argument

    .if EvalArg1.wGenus == EGN_NUMBER
      mov EvalResult.wGenus, EGN_NUMBER
      .if EvalArg1.dValue == FALSE
        mov EvalResult.dValue, TRUE
      .else
        mov EvalResult.dValue, FALSE
      .endif

    .elseif EvalArg1.wGenus == EGN_UNKNOWN
      mov EvalResult.wGenus, EGN_UNKNOWN
      mov EvalResult.dValue, TRUE

    .else                                               ;EGN_ERROR & EGN_UNDEF
      mov EvalResult.wGenus, EGN_ERROR
      mov EvalResult.dValue, TRUE
    .endif
    LDLL_Remove [xsi].$Obj(Evaluator).Queue, xdx, xax, xdi
    mov xax, xdx
    MemFree xax
    ret
EvalHandler_log_not endp

EvalHandler_log_and proc
;    DbgText "Handler: &&"
    mov EvalResult.wType, ETT_RESULT
    mov EvalResult.pToken, NULL
    mov xdi, [xax].LDLL_MEMBER.pLinkBack                ;Get 2nd argument
    mov xdx, [xdi].LDLL_MEMBER.pLinkBack                ;Get 1st argument

    .if EvalArg1.wGenus == EGN_NUMBER && EvalArg2.wGenus == EGN_NUMBER
      mov EvalResult.wGenus, EGN_NUMBER
      xor ecx, ecx
      .if EvalArg1.dValue != 0 && EvalArg2.dValue != 0
        inc ecx
      .endif
      mov EvalResult.dValue, ecx

    .elseif EvalArg1.wGenus == EGN_NUMBER && EvalArg1.dValue == 0
      mov EvalResult.wGenus, EGN_NUMBER
      mov EvalResult.dValue, FALSE
    .elseif EvalArg2.wGenus == EGN_NUMBER && EvalArg2.dValue == 0
      mov EvalResult.wGenus, EGN_NUMBER
      mov EvalResult.dValue, FALSE

    .elseif EvalArg1.wGenus == EGN_UNKNOWN || EvalArg2.wGenus == EGN_UNKNOWN
      mov EvalResult.wGenus, EGN_UNKNOWN
      mov EvalResult.dValue, TRUE

    .else                                               ;EGN_ERROR & EGN_UNDEF
      mov EvalResult.wGenus, EGN_ERROR
      mov EvalResult.dValue, TRUE
    .endif
    LDLL_Remove [xsi].$Obj(Evaluator).Queue, xdx, xax, xcx
    mov xax, xdx
    MemFree xax
    LDLL_Remove [xsi].$Obj(Evaluator).Queue, xdi, xax, xcx
    MemFree xdi
    ret
EvalHandler_log_and endp

EvalHandler_log_or proc
;    DbgText "Handler: ||"
    mov EvalResult.wType, ETT_RESULT
    mov EvalResult.pToken, NULL
    mov xdi, [xax].LDLL_MEMBER.pLinkBack                ;Get 2nd argument
    mov xdx, [xdi].LDLL_MEMBER.pLinkBack                ;Get 1st argument

    .if EvalArg1.wGenus == EGN_NUMBER && EvalArg2.wGenus == EGN_NUMBER
      mov EvalResult.wGenus, EGN_NUMBER
      xor ecx, ecx
      .if EvalArg1.dValue != 0 || EvalArg2.dValue != 0
        inc ecx
      .endif
      mov EvalResult.dValue, ecx

    .elseif EvalArg1.wGenus == EGN_NUMBER && EvalArg1.dValue != 0
      mov EvalResult.wGenus, EGN_NUMBER
      mov EvalResult.dValue, TRUE
    .elseif EvalArg2.wGenus == EGN_NUMBER && EvalArg2.dValue != 0
      mov EvalResult.wGenus, EGN_NUMBER
      mov EvalResult.dValue, TRUE

    .elseif EvalArg1.wGenus == EGN_UNKNOWN || EvalArg2.wGenus == EGN_UNKNOWN
      mov EvalResult.wGenus, EGN_UNKNOWN
      mov EvalResult.dValue, TRUE

    .else                                               ;EGN_ERROR & EGN_UNDEF
      mov EvalResult.wGenus, EGN_ERROR
      mov EvalResult.dValue, TRUE
    .endif
    LDLL_Remove [xsi].$Obj(Evaluator).Queue, xdx, xax, xcx
    mov xax, xdx
    MemFree xax
    LDLL_Remove [xsi].$Obj(Evaluator).Queue, xdi, xax, xcx
    MemFree xdi
    ret
EvalHandler_log_or endp

EvalHandler_bit_not proc
;    DbgText "Handler: ~"
    mov EvalResult.wType, ETT_RESULT
    mov EvalResult.pToken, NULL
    mov xdx, [xax].LDLL_MEMBER.pLinkBack                ;Get argument

    .if EvalArg1.wGenus == EGN_NUMBER
      mov EvalResult.wGenus, EGN_NUMBER
      mov ecx, EvalArg1.dValue
      not ecx
      mov EvalResult.dValue, ecx

    .elseif EvalArg1.wGenus == EGN_UNKNOWN
      mov EvalResult.wGenus, EGN_UNKNOWN
      mov EvalResult.dValue, TRUE

    .else                                               ;EGN_ERROR & EGN_UNDEF
      mov EvalResult.wGenus, EGN_ERROR
      mov EvalResult.dValue, TRUE
    .endif
    LDLL_Remove [xsi].$Obj(Evaluator).Queue, xdx, xax, xdi
    mov xax, xdx
    MemFree xax
    ret
EvalHandler_bit_not endp

EvalHandler_bit_and proc
;    DbgText "Handler: &"
    mov EvalResult.wType, ETT_RESULT
    mov EvalResult.pToken, NULL
    mov xdi, [xax].LDLL_MEMBER.pLinkBack                ;Get 2nd argument
    mov xdx, [xdi].LDLL_MEMBER.pLinkBack                ;Get 1st argument

    .if EvalArg1.wGenus == EGN_NUMBER && EvalArg2.wGenus == EGN_NUMBER
      mov EvalResult.wGenus, EGN_NUMBER
      mov ecx, EvalArg1.dValue
      and ecx, EvalArg2.dValue
      mov EvalResult.dValue, ecx

    .elseif EvalArg1.wGenus == EGN_UNKNOWN || EvalArg2.wGenus == EGN_UNKNOWN
      mov EvalResult.wGenus, EGN_UNKNOWN
      mov EvalResult.dValue, TRUE

    .else                                               ;EGN_ERROR & EGN_UNDEF
      mov EvalResult.wGenus, EGN_ERROR
      mov EvalResult.dValue, TRUE
    .endif
    LDLL_Remove [xsi].$Obj(Evaluator).Queue, xdx, xax, xcx
    mov xax, xdx
    MemFree xax
    LDLL_Remove [xsi].$Obj(Evaluator).Queue, xdi, xax, xcx
    MemFree xdi
    ret
EvalHandler_bit_and endp

EvalHandler_bit_or proc
;    DbgText "Handler: |"
    mov EvalResult.wType, ETT_RESULT
    mov EvalResult.pToken, NULL
    mov xdi, [xax].LDLL_MEMBER.pLinkBack                ;Get 2nd argument
    mov xdx, [xdi].LDLL_MEMBER.pLinkBack                ;Get 1st argument

    .if EvalArg1.wGenus == EGN_NUMBER && EvalArg2.wGenus == EGN_NUMBER
      mov EvalResult.wGenus, EGN_NUMBER
      mov ecx, EvalArg1.dValue
      or ecx, EvalArg2.dValue
      mov EvalResult.dValue, ecx

    .elseif EvalArg1.wGenus == EGN_UNKNOWN || EvalArg2.wGenus == EGN_UNKNOWN
      mov EvalResult.wGenus, EGN_UNKNOWN
      mov EvalResult.dValue, TRUE

    .else                                               ;EGN_ERROR & EGN_UNDEF
      mov EvalResult.wGenus, EGN_ERROR
      mov EvalResult.dValue, TRUE
    .endif
    LDLL_Remove [xsi].$Obj(Evaluator).Queue, xdx, xax, xcx
    mov xax, xdx
    MemFree xax
    LDLL_Remove [xsi].$Obj(Evaluator).Queue, xdi, xax, xcx
    MemFree xdi
    ret
EvalHandler_bit_or endp

EvalHandler_bit_xor proc
;    DbgText "Handler: ^"
    mov EvalResult.wType, ETT_RESULT
    mov EvalResult.pToken, NULL
    mov xdi, [xax].LDLL_MEMBER.pLinkBack                ;Get 2nd argument
    mov xdx, [xdi].LDLL_MEMBER.pLinkBack                ;Get 1st argument

    .if EvalArg1.wGenus == EGN_NUMBER && EvalArg2.wGenus == EGN_NUMBER
      mov EvalResult.wGenus, EGN_NUMBER
      mov ecx, EvalArg1.dValue
      xor ecx, EvalArg2.dValue
      mov EvalResult.dValue, ecx

    .elseif EvalArg1.wGenus == EGN_UNKNOWN || EvalArg2.wGenus == EGN_UNKNOWN
      mov EvalResult.wGenus, EGN_UNKNOWN
      mov EvalResult.dValue, TRUE

    .else                                               ;EGN_ERROR & EGN_UNDEF
      mov EvalResult.wGenus, EGN_ERROR
      mov EvalResult.dValue, TRUE
    .endif
    LDLL_Remove [xsi].$Obj(Evaluator).Queue, xdx, xax, xcx
    mov xax, xdx
    MemFree xax
    LDLL_Remove [xsi].$Obj(Evaluator).Queue, xdi, xax, xcx
    MemFree xdi
    ret
EvalHandler_bit_xor endp

EvalHandler_Mul proc
;    DbgText "Handler: *"
    mov EvalResult.wType, ETT_RESULT
    mov EvalResult.pToken, NULL
    mov xdi, [xax].LDLL_MEMBER.pLinkBack                ;Get 2nd argument
    mov xdx, [xdi].LDLL_MEMBER.pLinkBack                ;Get 1st argument

    .if EvalArg1.wGenus == EGN_NUMBER && EvalArg2.wGenus == EGN_NUMBER
      mov ecx, eax
      push xdx
      mov eax, EvalArg1.dValue
      mul EvalArg2.dValue                               ;edx::eax  ignore edx
      xchg ecx, eax
      pop xdx                                           ;Restore edx
      .if edx == 0
        mov EvalResult.wGenus, EGN_NUMBER
        mov EvalResult.dValue, ecx
      .else
        mov EvalResult.wGenus, EGN_ERROR
        mov EvalResult.dValue, ecx
      .endif

    .elseif EvalArg1.wGenus == EGN_UNKNOWN || EvalArg2.wGenus == EGN_UNKNOWN
      mov EvalResult.wGenus, EGN_UNKNOWN
      mov EvalResult.dValue, TRUE

    .else                                               ;EGN_ERROR & EGN_UNDEF
      mov EvalResult.wGenus, EGN_ERROR
      mov EvalResult.dValue, TRUE
    .endif
    LDLL_Remove [xsi].$Obj(Evaluator).Queue, xdx, xax, xcx
    mov xax, xdx
    MemFree xax
    LDLL_Remove [xsi].$Obj(Evaluator).Queue, xdi, xax, xcx
    MemFree xdi
    ret
EvalHandler_Mul endp

EvalHandler_Div proc
;    DbgText "Handler: /"
    mov EvalResult.wType, ETT_RESULT
    mov EvalResult.pToken, NULL
    mov xdi, [xax].LDLL_MEMBER.pLinkBack                ;Get 2nd argument
    mov xdx, [xdi].LDLL_MEMBER.pLinkBack                ;Get 1st argument

    .if EvalArg1.wGenus == EGN_NUMBER && EvalArg2.wGenus == EGN_NUMBER
      .if EvalArg2.dValue != 0
        mov EvalResult.wGenus, EGN_NUMBER
        mov ecx, eax
        push xdx
        mov eax, EvalArg1.dValue
        xor edx, edx
        div EvalArg2.dValue
        xchg ecx, eax
        mov EvalResult.dValue, ecx
        pop xdx
      .else
        mov EvalResult.wGenus, EGN_ERROR
        mov EvalResult.dValue, 0
      .endif
      .if edx == 0
        mov EvalResult.wGenus, EGN_NUMBER
        mov EvalResult.dValue, ecx
      .else
        mov EvalResult.wGenus, EGN_ERROR
        mov EvalResult.dValue, ecx
      .endif

    .elseif EvalArg1.wGenus == EGN_UNKNOWN || EvalArg2.wGenus == EGN_UNKNOWN
      mov EvalResult.wGenus, EGN_UNKNOWN
      mov EvalResult.dValue, TRUE

    .else                                               ;EGN_ERROR & EGN_UNDEF
      mov EvalResult.wGenus, EGN_ERROR
      mov EvalResult.dValue, TRUE
    .endif
    LDLL_Remove [xsi].$Obj(Evaluator).Queue, xdx, xax, xcx
    mov xax, xdx
    MemFree xax
    LDLL_Remove [xsi].$Obj(Evaluator).Queue, xdi, xax, xcx
    MemFree xdi
    ret
EvalHandler_Div endp

EvalHandler_Mod proc
;    DbgText "Handler: %"
    mov EvalResult.wType, ETT_RESULT
    mov EvalResult.pToken, NULL
    mov xdi, [xax].LDLL_MEMBER.pLinkBack                ;Get 2nd argument
    mov xdx, [xdi].LDLL_MEMBER.pLinkBack                ;Get 1st argument

    .if EvalArg1.wGenus == EGN_NUMBER && EvalArg2.wGenus == EGN_NUMBER
      .if EvalArg2.dValue != 0
        mov EvalResult.wGenus, EGN_NUMBER
        mov ecx, eax
        push xdx
        mov eax, EvalArg1.dValue
        xor edx, edx
        div EvalArg2.dValue
        xchg ecx, eax
        mov EvalResult.dValue, edx
        pop xdx
      .else
        mov EvalResult.wGenus, EGN_ERROR
        mov EvalResult.dValue, 0
      .endif
      .if edx == 0
        mov EvalResult.wGenus, EGN_NUMBER
        mov EvalResult.dValue, ecx
      .else
        mov EvalResult.wGenus, EGN_ERROR
        mov EvalResult.dValue, ecx
      .endif

    .elseif EvalArg1.wGenus == EGN_UNKNOWN || EvalArg2.wGenus == EGN_UNKNOWN
      mov EvalResult.wGenus, EGN_UNKNOWN
      mov EvalResult.dValue, TRUE

    .else                                               ;EGN_ERROR & EGN_UNDEF
      mov EvalResult.wGenus, EGN_ERROR
      mov EvalResult.dValue, TRUE
    .endif
    LDLL_Remove [xsi].$Obj(Evaluator).Queue, xdx, xax, xcx
    mov xax, xdx
    MemFree xax
    LDLL_Remove [xsi].$Obj(Evaluator).Queue, xdi, xax, xcx
    MemFree xdi
    ret
EvalHandler_Mod endp

EvalHandler_Add proc
;    DbgText "Handler: +"
    mov EvalResult.wType, ETT_RESULT
    mov EvalResult.pToken, NULL
    mov xdi, [xax].LDLL_MEMBER.pLinkBack                ;Get 2nd argument
    mov xdx, [xdi].LDLL_MEMBER.pLinkBack                ;Get 1st argument

    .if EvalArg1.wGenus == EGN_NUMBER && EvalArg2.wGenus == EGN_NUMBER
      mov EvalResult.wGenus, EGN_NUMBER
      mov ecx, EvalArg1.dValue
      add ecx, EvalArg2.dValue
      mov EvalResult.dValue, ecx

    .elseif EvalArg1.wGenus == EGN_UNKNOWN || EvalArg2.wGenus == EGN_UNKNOWN
      mov EvalResult.wGenus, EGN_UNKNOWN
      mov EvalResult.dValue, TRUE

    .else                                               ;EGN_ERROR & EGN_UNDEF
      mov EvalResult.wGenus, EGN_ERROR
      mov EvalResult.dValue, TRUE
    .endif
    LDLL_Remove [xsi].$Obj(Evaluator).Queue, xdx, xax, xcx
    mov xax, xdx
    MemFree xax
    LDLL_Remove [xsi].$Obj(Evaluator).Queue, xdi, xax, xcx
    MemFree xdi
    ret
EvalHandler_Add endp

EvalHandler_Sub proc
;    DbgText "Handler: -"
    mov EvalResult.wType, ETT_RESULT
    mov EvalResult.pToken, NULL
    mov xdi, [xax].LDLL_MEMBER.pLinkBack                ;Get 2nd argument
    mov xdx, [xdi].LDLL_MEMBER.pLinkBack                ;Get 1st argument

    .if EvalArg1.wGenus == EGN_NUMBER && EvalArg2.wGenus == EGN_NUMBER
      mov EvalResult.wGenus, EGN_NUMBER
      mov ecx, EvalArg1.dValue
      sub ecx, EvalArg2.dValue
      mov EvalResult.dValue, ecx

    .elseif EvalArg1.wGenus == EGN_UNKNOWN || EvalArg2.wGenus == EGN_UNKNOWN
      mov EvalResult.wGenus, EGN_UNKNOWN
      mov EvalResult.dValue, TRUE

    .else                                               ;EGN_ERROR & EGN_UNDEF
      mov EvalResult.wGenus, EGN_ERROR
      mov EvalResult.dValue, TRUE
    .endif
    LDLL_Remove [xsi].$Obj(Evaluator).Queue, xdx, xax, xcx
    mov xax, xdx
    MemFree xax
    LDLL_Remove [xsi].$Obj(Evaluator).Queue, xdi, xax, xcx
    MemFree xdi
    ret
EvalHandler_Sub endp

EvalHandler_ShiftL proc
;    DbgText "Handler: <<"
    mov EvalResult.wType, ETT_RESULT
    mov EvalResult.pToken, NULL
    mov xdi, [xax].LDLL_MEMBER.pLinkBack                ;Get 2nd argument
    mov xdx, [xdi].LDLL_MEMBER.pLinkBack                ;Get 1st argument

    .if EvalArg1.wGenus == EGN_NUMBER && EvalArg2.wGenus == EGN_NUMBER
      mov EvalResult.wGenus, EGN_NUMBER
      push xdx
      mov edx, EvalArg1.dValue
      mov ecx, EvalArg2.dValue
      shl edx, cl
      mov EvalResult.dValue, edx
      pop xdx

    .elseif EvalArg1.wGenus == EGN_UNKNOWN || EvalArg2.wGenus == EGN_UNKNOWN
      mov EvalResult.wGenus, EGN_UNKNOWN
      mov EvalResult.dValue, TRUE

    .else                                               ;EGN_ERROR & EGN_UNDEF
      mov EvalResult.wGenus, EGN_ERROR
      mov EvalResult.dValue, TRUE
    .endif
    LDLL_Remove [xsi].$Obj(Evaluator).Queue, xdx, xax, xcx
    mov xax, xdx
    MemFree xax
    LDLL_Remove [xsi].$Obj(Evaluator).Queue, xdi, xax, xcx
    MemFree xdi
    ret
EvalHandler_ShiftL endp

EvalHandler_ShiftR proc
;    DbgText "Handler: >>"
    mov EvalResult.wType, ETT_RESULT
    mov EvalResult.pToken, NULL
    mov xdi, [xax].LDLL_MEMBER.pLinkBack                ;Get 2nd argument
    mov xdx, [xdi].LDLL_MEMBER.pLinkBack                ;Get 1st argument

    .if EvalArg1.wGenus == EGN_NUMBER && EvalArg2.wGenus == EGN_NUMBER
      mov EvalResult.wGenus, EGN_NUMBER
      push xdx
      mov edx, EvalArg1.dValue
      mov ecx, EvalArg2.dValue
      shr edx, cl
      mov EvalResult.dValue, edx
      pop xdx

    .elseif EvalArg1.wGenus == EGN_UNKNOWN || EvalArg2.wGenus == EGN_UNKNOWN
      mov EvalResult.wGenus, EGN_UNKNOWN
      mov EvalResult.dValue, TRUE

    .else                                               ;EGN_ERROR & EGN_UNDEF
      mov EvalResult.wGenus, EGN_ERROR
      mov EvalResult.dValue, TRUE
    .endif
    LDLL_Remove [xsi].$Obj(Evaluator).Queue, xdx, xax, xcx
    mov xax, xdx
    MemFree xax
    LDLL_Remove [xsi].$Obj(Evaluator).Queue, xdi, xax, xcx
    MemFree xdi
    ret
EvalHandler_ShiftR endp

EvalHandler_lt proc
;    DbgText "Handler: greater than"
    mov EvalResult.wType, ETT_RESULT
    mov EvalResult.pToken, NULL
    mov xdi, [xax].LDLL_MEMBER.pLinkBack                ;Get 2nd argument
    mov xdx, [xdi].LDLL_MEMBER.pLinkBack                ;Get 1st argument

    .if EvalArg1.wGenus == EGN_NUMBER && EvalArg2.wGenus == EGN_NUMBER
      mov EvalResult.wGenus, EGN_NUMBER
      push xdx
      mov ecx, EvalArg1.dValue
      xor edx, edx
      .if ecx < EvalArg2.dValue
        inc edx
      .endif
      mov EvalResult.dValue, edx
      pop xdx

    .elseif EvalArg1.wGenus == EGN_UNKNOWN || EvalArg2.wGenus == EGN_UNKNOWN
      mov EvalResult.wGenus, EGN_UNKNOWN
      mov EvalResult.dValue, TRUE

    .else                                               ;EGN_ERROR & EGN_UNDEF
      mov EvalResult.wGenus, EGN_ERROR
      mov EvalResult.dValue, TRUE
    .endif
    LDLL_Remove [xsi].$Obj(Evaluator).Queue, xdx, xax, xcx
    mov xax, xdx
    MemFree xax
    LDLL_Remove [xsi].$Obj(Evaluator).Queue, xdi, xax, xcx
    MemFree xdi
    ret
EvalHandler_lt endp

EvalHandler_ltoet proc
;    DbgText "Handler: greater than or equal to"
    mov EvalResult.wType, ETT_RESULT
    mov EvalResult.pToken, NULL
    mov xdi, [xax].LDLL_MEMBER.pLinkBack                ;Get 2nd argument
    mov xdx, [xdi].LDLL_MEMBER.pLinkBack                ;Get 1st argument

    .if EvalArg1.wGenus == EGN_NUMBER && EvalArg2.wGenus == EGN_NUMBER
      mov EvalResult.wGenus, EGN_NUMBER
      push xdx
      mov ecx, EvalArg1.dValue
      xor edx, edx
      .if ecx <= EvalArg2.dValue
        inc edx
      .endif
      mov EvalResult.dValue, edx
      pop xdx

    .elseif EvalArg1.wGenus == EGN_UNKNOWN || EvalArg2.wGenus == EGN_UNKNOWN
      mov EvalResult.wGenus, EGN_UNKNOWN
      mov EvalResult.dValue, TRUE

    .else                                               ;EGN_ERROR & EGN_UNDEF
      mov EvalResult.wGenus, EGN_ERROR
      mov EvalResult.dValue, TRUE
    .endif
    LDLL_Remove [xsi].$Obj(Evaluator).Queue, xdx, xax, xcx
    mov xax, xdx
    MemFree xax
    LDLL_Remove [xsi].$Obj(Evaluator).Queue, xdi, xax, xcx
    MemFree xdi
    ret
EvalHandler_ltoet endp

EvalHandler_gt proc
;    DbgText "Handler: greater than"
    mov EvalResult.wType, ETT_RESULT
    mov EvalResult.pToken, NULL
    mov xdi, [xax].LDLL_MEMBER.pLinkBack                ;Get 2nd argument
    mov xdx, [xdi].LDLL_MEMBER.pLinkBack                ;Get 1st argument

    .if EvalArg1.wGenus == EGN_NUMBER && EvalArg2.wGenus == EGN_NUMBER
      mov EvalResult.wGenus, EGN_NUMBER
      push xdx
      mov ecx, EvalArg1.dValue
      xor edx, edx
      .if ecx > EvalArg2.dValue
        inc edx
      .endif
      mov EvalResult.dValue, edx
      pop xdx

    .elseif EvalArg1.wGenus == EGN_UNKNOWN || EvalArg2.wGenus == EGN_UNKNOWN
      mov EvalResult.wGenus, EGN_UNKNOWN
      mov EvalResult.dValue, TRUE

    .else                                               ;EGN_ERROR & EGN_UNDEF
      mov EvalResult.wGenus, EGN_ERROR
      mov EvalResult.dValue, TRUE
    .endif
    LDLL_Remove [xsi].$Obj(Evaluator).Queue, xdx, xax, xcx
    mov xax, xdx
    MemFree xax
    LDLL_Remove [xsi].$Obj(Evaluator).Queue, xdi, xax, xcx
    MemFree xdi
    ret
EvalHandler_gt endp

EvalHandler_gtoet proc
;    DbgText "Handler: greater than or equal to"
    mov EvalResult.wType, ETT_RESULT
    mov EvalResult.pToken, NULL
    mov xdi, [xax].LDLL_MEMBER.pLinkBack                ;Get 2nd argument
    mov xdx, [xdi].LDLL_MEMBER.pLinkBack                ;Get 1st argument

    .if EvalArg1.wGenus == EGN_NUMBER && EvalArg2.wGenus == EGN_NUMBER
      mov EvalResult.wGenus, EGN_NUMBER
      push xdx
      mov ecx, EvalArg1.dValue
      xor edx, edx
      .if ecx >= EvalArg2.dValue
        inc edx
      .endif
      mov EvalResult.dValue, edx
      pop xdx

    .elseif EvalArg1.wGenus == EGN_UNKNOWN || EvalArg2.wGenus == EGN_UNKNOWN
      mov EvalResult.wGenus, EGN_UNKNOWN
      mov EvalResult.dValue, TRUE

    .else                                               ;EGN_ERROR & EGN_UNDEF
      mov EvalResult.wGenus, EGN_ERROR
      mov EvalResult.dValue, TRUE
    .endif
    LDLL_Remove [xsi].$Obj(Evaluator).Queue, xdx, xax, xcx
    mov xax, xdx
    MemFree xax
    LDLL_Remove [xsi].$Obj(Evaluator).Queue, xdi, xax, xcx
    MemFree xdi
    ret
EvalHandler_gtoet endp

EvalHandler_eqt proc
;    DbgText "Handler: greater than"
    mov EvalResult.wType, ETT_RESULT
    mov EvalResult.pToken, NULL
    mov xdi, [xax].LDLL_MEMBER.pLinkBack                ;Get 2nd argument
    mov xdx, [xdi].LDLL_MEMBER.pLinkBack                ;Get 1st argument

    .if EvalArg1.wGenus == EGN_NUMBER && EvalArg2.wGenus == EGN_NUMBER
      mov EvalResult.wGenus, EGN_NUMBER
      push xdx
      mov ecx, EvalArg1.dValue
      xor edx, edx
      .if ecx == EvalArg2.dValue
        inc edx
      .endif
      mov EvalResult.dValue, edx
      pop xdx

    .elseif EvalArg1.wGenus == EGN_UNKNOWN || EvalArg2.wGenus == EGN_UNKNOWN
      mov EvalResult.wGenus, EGN_UNKNOWN
      mov EvalResult.dValue, TRUE

    .else                                               ;EGN_ERROR & EGN_UNDEF
      mov EvalResult.wGenus, EGN_ERROR
      mov EvalResult.dValue, TRUE
    .endif
;    DbgHex EvalResult.wType
;    DbgHex EvalResult.wGenus
;    DbgHex EvalResult.dValue
    LDLL_Remove [xsi].$Obj(Evaluator).Queue, xdx, xax, xcx
    mov xax, xdx
    MemFree xax
    LDLL_Remove [xsi].$Obj(Evaluator).Queue, xdi, xax, xcx
    MemFree xdi
    ret
EvalHandler_eqt endp

EvalHandler_neqt proc
;    DbgText "Handler: greater than or equal to"
    mov EvalResult.wType, ETT_RESULT
    mov EvalResult.pToken, NULL
    mov xdi, [xax].LDLL_MEMBER.pLinkBack                ;Get 2nd argument
    mov xdx, [xdi].LDLL_MEMBER.pLinkBack                ;Get 1st argument

    .if EvalArg1.wGenus != EGN_NUMBER && EvalArg2.wGenus == EGN_NUMBER
      mov EvalResult.wGenus, EGN_NUMBER
      push xdx
      mov ecx, EvalArg1.dValue
      xor edx, edx
      .if ecx < EvalArg2.dValue
        inc edx
      .endif
      mov EvalResult.dValue, edx
      pop xdx

    .elseif EvalArg1.wGenus == EGN_UNKNOWN || EvalArg2.wGenus == EGN_UNKNOWN
      mov EvalResult.wGenus, EGN_UNKNOWN
      mov EvalResult.dValue, TRUE

    .else                                               ;EGN_ERROR & EGN_UNDEF
      mov EvalResult.wGenus, EGN_ERROR
      mov EvalResult.dValue, TRUE
    .endif
    LDLL_Remove [xsi].$Obj(Evaluator).Queue, xdx, xax, xcx
    mov xax, xdx
    MemFree xax
    LDLL_Remove [xsi].$Obj(Evaluator).Queue, xdi, xax, xcx
    MemFree xdi
    ret
EvalHandler_neqt endp

EvalHandler_defined proc
;    DbgText "Handler: defined"
    mov EvalResult.wType, ETT_RESULT
    mov EvalResult.pToken, NULL
    mov xdx, [xax].LDLL_MEMBER.pLinkBack              ;Get argument
    .if EvalArg1.wGenus == EGN_UNDEF
      mov EvalResult.wGenus, EGN_NUMBER
      mov EvalResult.dValue, FALSE
    .elseif (EvalArg1.wGenus == EGN_STRING) || (EvalArg1.wGenus == EGN_NUMBER)
      mov EvalResult.wGenus, EGN_NUMBER
      mov EvalResult.dValue, TRUE

    .elseif EvalArg1.wGenus == EGN_UNKNOWN
      mov EvalResult.wGenus, EGN_UNKNOWN
      mov EvalResult.dValue, TRUE

    .else
      mov EvalResult.wGenus, EGN_ERROR
      mov EvalResult.dValue, TRUE
    .endif
    LDLL_Remove [xsi].$Obj(Evaluator).Queue, xdx, xax, xdi
    mov xax, xdx
    MemFree xax
    ret
EvalHandler_defined endp

EvalHandler_WAFP proc
;    DbgText "Handler: WINAPI_FAMILY_PARTITION"
    mov EvalResult.wType, ETT_RESULT
    mov EvalResult.pToken, NULL
    mov xdx, [xax].LDLL_MEMBER.pLinkBack                ;Get argument
    .if EvalArg1.wGenus == EGN_NUMBER
      mov EvalResult.wGenus, EGN_NUMBER
      m2m EvalResult.dValue, EvalArg1.dValue, eax       ;Copy value

    .elseif EvalArg1.wGenus == EGN_UNKNOWN
      mov EvalResult.wGenus, EGN_UNKNOWN
      mov EvalResult.dValue, TRUE

    .else
      mov EvalResult.wGenus, EGN_ERROR
      mov EvalResult.dValue, TRUE
    .endif
    LDLL_Remove [xsi].$Obj(Evaluator).Queue, xdx, xax, xdi
    mov xax, xdx
    MemFree xax
    ret
EvalHandler_WAFP endp

EvalHandler_nop proc
    ret
EvalHandler_nop endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Evaluator.GetNextEvalToken
; Purpose:    Get a new Token.
; Arguments:  None.
;             xbx -> IncFile
; Return:     xax -> New EVAL_TOKEN.

Method Evaluator.GetNextEvalToken, uses xdi xsi
  local pToken:PTOKEN
  
  OCall xbx::IncFile.GetNextTokenPP
;  DbgStr eax
  jz @@EOM
  mov pToken, xax
  MemAlloc sizeof(EVAL_TOKEN), MEM_INIT_ZERO
  mov xdi, xax
  m2m EvalArg2.pToken, pToken, xcx

  ;Check if it is an operator
  lea xsi, EvalOperatorTable
  .while [xsi].EVAL_OPTOR.pToken != NULL
    invoke StrCompA, [xsi].EVAL_OPTOR.pToken, EvalArg2.pToken
    .if eax == 0
;      DbgText "Operator"
      mov EvalArg2.wType, ETT_OPERATOR
      mov EvalArg2.wGenus, 0
      mov EvalArg2.pOperator, xsi
      jmp @Done
    .endif
    add xsi, sizeof(EVAL_OPTOR)
  .endw

  ;Check if it is a parenthesis
  mov xax, EvalArg2.pToken
  movzx cx, CHRA ptr [xax]
  .if cl == "(" || cl == ")"
    mov EvalArg2.wType, ETT_PARENTHESIS
    mov EvalArg2.wGenus, cx
    mov EvalArg2.dValue, 0
    jmp @Done
  .endif

  ;Check if it is an immediate number
  .if $DoesTextMatchA?([xax], <0x>)
;    DbgText "Hex Number"
    mov EvalArg2.wType, ETT_IMMEDIATE
    mov EvalArg2.wGenus, EGN_NUMBER
    mov xcx, EvalArg2.pToken
    add xcx, 2
    invoke hex2dwordA, xax
    mov EvalArg2.dValue, eax
;    DbgHex eax
    jmp @Done
  .else
    mov cl, [xax]
    .if cl >= "0" && cl <= "9"
;      DbgText "Dec Number"
      mov EvalArg2.wType, ETT_IMMEDIATE
      mov EvalArg2.wGenus, EGN_NUMBER
      invoke dec2dwordA, EvalArg2.pToken
      mov EvalArg2.dValue, eax
;      DbgDec eax
      jmp @Done
    .endif
  .endif

  ;Check if it is a known symbol
  lea xsi, EvalKnownSymbolTable
  .while [xsi].EVAL_KNOWN_SYMBOL.pToken != NULL
    invoke StrCompA, [xsi].EVAL_KNOWN_SYMBOL.pToken, EvalArg2.pToken
    .if eax == 0
      mov EvalArg2.wType, ETT_SYMBOL
;      DbgText "Symbol"
      m2m EvalArg2.wGenus, [xsi].EVAL_KNOWN_SYMBOL.wGenus, ax
      m2m XWORD ptr EvalArg2.dValue, [xsi].EVAL_KNOWN_SYMBOL.Value, xax
      jmp @Done
    .endif
    add xsi, sizeof(EVAL_KNOWN_SYMBOL)
  .endw

  ;If nothing else fits, the it is an unknown symbol
  mov EvalArg2.wType, ETT_SYMBOL
  mov EvalArg2.wGenus, EGN_UNKNOWN
  mov EvalArg2.dValue, 0

@Done:
  mov xax, xdi
MethodEnd

endif
