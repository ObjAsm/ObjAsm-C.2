; ==================================================================================================
; Title:      h2inc+_IncFile_Proc.inc
; Author:     G. Friedrich
; Version:    See h2inc+.asm
; Purpose:    ObjAsm h2inc+ IncFile procs.
; ==================================================================================================


; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  BStrCompA
; Purpose:    Comparison routine for BStrA strings.
; Arguments:  Arg1 -> String 1.
;             Arg2 -> String 2.
; Return:     eax: comparison result. Zero if strings are identical.

BStrCompA proc uses xdi xsi pBStrA:PSTRINGA, pStrA:PSTRINGA
  mov xsi, pBStrA
  mov xdi, pStrA
  mov ecx, [xsi - sizeof(DWORD)]                        ;Load string size
  repz cmpsb
  mov eax, 0
  .if SIGN?
    dec eax
  .elseif !ZERO?
    inc eax
  .endif
  ret
BStrCompA endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  GetTypeSize
; Purpose:    Get the BYTE size of a given type.
; Arguments:  Arg1: -> Type
; Return:     eax = BYTE size, zero if not found.

GetTypeSize proc pType:PSTRINGA
  OCall pKnwTypeSize::List.Search, pType
  .if eax == FALSE
    OCall pNewTypeSize::List.Search, pType
    .if eax == FALSE
      jmp @Exit
    .else
    	mov edx, ecx
      OCall pNewTypeSize::List.ItemAt, edx
    .endif
  .else
  	mov edx, ecx
    OCall pKnwTypeSize::List.ItemAt, edx
  .endif
  mov edx, [xax - sizeof(DWORD)]
  mov eax, [xax + xdx]
@Exit:
  ret
GetTypeSize endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  InsertStrg, InsertAttr, InsertEqui
; Purpose:    Add an Item to a List.
; Arguments:  Arg1: -> List
;             Arg2: String length (without ZTC)
;             Arg3: ...
;             xbx -> IncFile
; Return:     xax -> Identifier string.

InsertStrg proc pList:POINTER, pStr:PSTRINGA, dLength:DWORD
  local dInsIndex:DWORD

  OCall pList::List.Search, pStr
  .if eax == FALSE
    mov dInsIndex, ecx
    OCall $ObjTmpl(Application).MemHeap::MemoryHeap.AddBStrA, pStr, dLength
    .if xax != NULL
      OCall pList::List.InsertAt, dInsIndex, xax
      ret
    .endif
    OCall xbx::IncFile.ShowError, addr szOutOfSpace
    mov $ObjTmpl(Application).bTerminate, TRUE
    xor eax, eax
  .else
    mov edx, ecx
    OCall pList::List.ItemAt, edx
  .endif
  ret
InsertStrg endp

InsertAttr proc pList:POINTER, pStr:PSTRINGA, dLength:DWORD, dAttr:DWORD
  local dInsIndex:DWORD

  OCall pList::List.Search, pStr
  .if eax == FALSE
    mov dInsIndex, ecx
    OCall $ObjTmpl(Application).MemHeap::MemoryHeap.AddBStrA, pStr, dLength
    .if xax != NULL
      OCall pList::List.InsertAt, dInsIndex, xax
      OCall $ObjTmpl(Application).MemHeap::MemoryHeap.AddDword, dAttr
      .if xax != NULL
        ret
      .endif
    .endif
    OCall xbx::IncFile.ShowError, addr szOutOfSpace
    mov $ObjTmpl(Application).bTerminate, TRUE
    xor eax, eax
  .else
    mov edx, ecx
    OCall pList::List.ItemAt, edx
  .endif
  ret
InsertAttr endp

InsertEqui proc pList:POINTER, pStr:PSTRINGA, dLength:DWORD, pStrEqui:PSTRINGA, dEquSize:DWORD
  local dInsIndex:DWORD

  OCall pList::List.Search, pStr
  .if eax == FALSE
    mov dInsIndex, ecx
    OCall $ObjTmpl(Application).MemHeap::MemoryHeap.AddBStrA, pStr, dLength
    .if xax != NULL
      OCall pList::List.InsertAt, dInsIndex, xax
      OCall $ObjTmpl(Application).MemHeap::MemoryHeap.AddBStrA, pStrEqui, dEquSize
      .if xax != NULL
        ret
      .endif
    .endif
    OCall xbx::IncFile.ShowError, addr szOutOfSpace
    mov $ObjTmpl(Application).bTerminate, TRUE
    xor eax, eax
  .else
    mov edx, ecx
    OCall pList::List.ItemAt, edx
  .endif
  ret
InsertEqui endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  InsertDefItem
; Purpose:    Add a prototype to a list.
; Arguments:  Arg1 -> Function Name.
;             Arg2: Parameter bytes.
; Return:     Nothing.

InsertDefItem proc uses xdi xsi pFuncName:PSTRINGA, dParamBytes:DWORD
  local cProto[1024]:CHRA, cMessage[1024]:CHR

  mov cProto, 0
  lea xdi, cProto
  .ifBitSet [xbx].$Obj(IncFile).dQualifiers, PTQ_STDCALL
    WriteFA xdi, "_¦SA@¦UD", pFuncName, dParamBytes
  .elseIfBitSet [xbx].$Obj(IncFile).dQualifiers, PTQ_CDECL
    WriteFA xdi, "_¦SA", pFuncName
  .else
    WriteFA xdi, "¦SA", pFuncName
  .endif
  lea xdx, cProto
  sub xdi, xdx                                          ;Just the length, without the ZTC
  OCall $ObjTmpl(Application).MemHeap::MemoryHeap.AddBStrA, xdx, edi
  .if xax != NULL
    OCall [xbx].$Obj(IncFile).pDefs::List.Insert, xax
;    .if xax == NULL                                    ;The string may be a duplicate!
;      lea xsi, cMessage
;      WriteF xsi, "inserting \´¦SA\´ def list failed", addr cProto
;      OCall $ObjTmpl(Application)::Application.ShowWarning, WARNING_MAYOR, addr cMessage
;    .endif
  .endif
  ret
InsertDefItem endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  IsLogOperator?
; Purpose:    Check if character in al/ax/eax is a logical operator (comparison & logical)
; Arguments:  al/ax/eax = character(s) to test.
; Return:     eax = TRUE or FALSE.
; Note:       No other register is changed.

IsLogOperator? proc dChars:DWORD
  mov eax, dChars

  and eax, 0FFFFh
  cmp eax, "=="
  jz @IsTrue
  cmp eax, "!="
  jz @IsTrue
  cmp eax, "<="
  jz @IsTrue
  cmp eax, ">="
  jz @IsTrue
  cmp eax, "&&"
  jz @IsTrue
  cmp eax, "||"
  jz @IsTrue

  and eax, 0FFh
  cmp eax, "<"
  jz @IsTrue
  cmp eax, ">"
  jz @IsTrue
  cmp eax, "!"
  jz @IsTrue

  xor eax, eax
  ret
@IsTrue:
  mov eax, TRUE
  ret
IsLogOperator? endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  IsNumOperator?
; Purpose:    Check if character in al/ax/eax is a numeric operator (assignment & arithmetic).
; Arguments:  al/ax/eax = character(s) to test.
; Return:     eax = TRUE or FALSE.
; Note:       No other register is changed.

IsNumOperator? proc dChars:DWORD
  mov eax, dChars

  and eax, 0FFFFFFh
  cmp eax, "<<="
  jz @IsTrue
  xor eax, eax
  cmp eax, ">>="
  jz @IsTrue

  and eax, 0FFFFh
  cmp eax, ">>"
  jz @IsTrue
  cmp eax, "<<"
  jz @IsTrue
  cmp eax, "--"
  jz @IsTrue
  cmp eax, "++"
  jz @IsTrue
  cmp eax, "-="
  jz @IsTrue
  cmp eax, "+="
  jz @IsTrue
  cmp eax, "*="
  jz @IsTrue
  cmp eax, "/="
  jz @IsTrue
  cmp eax, "&="
  jz @IsTrue
  cmp eax, "%="
  jz @IsTrue
  cmp eax, "|="
  jz @IsTrue
  cmp eax, "^="
  jz @IsTrue

  and eax, 0FFh
  cmp eax, "="
  jz @IsTrue
  cmp eax, "-"
  jz @IsTrue
  cmp eax, "+"
  jz @IsTrue
  cmp eax, "*"
  jz @IsTrue
  cmp eax, "/"
  jz @IsTrue
  cmp eax, "|"
  jz @IsTrue
  cmp eax, "&"
  jz @IsTrue
  cmp eax, "%"
  jz @IsTrue
  cmp eax, "^"
  jz @IsTrue

  xor eax, eax
  ret
@IsTrue:
  mov eax, TRUE
  ret
IsNumOperator? endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  IsReservedWord?
; Purpose:    Check if token is a reserved word.
; Arguments:  Arg1 -> token to check.
; Return:     eax = FALSE if token is not reserved.

IsReservedWord? proc pToken:PTOKEN
  local cWord[128]:CHRA

  invoke StrCCopyA, addr cWord, pToken, lengthof(cWord) - 1
  invoke StrLowerA, addr cWord
  OCall pKnwResvWords::List.Search, xax
  ret
IsReservedWord? endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  IsMacro?
; Purpose:    Check if token is a macro.
; Arguments:  Arg1 -> token to check.
; Return:     eax = 0 if FALSE, 1 if macro was previously defined, 2 if it is a known macro.
;             ecx = Index in the range [0..Count].

IsMacro? proc pToken:PTOKEN
  OCall pKnwMacros::List.Search, pToken
  .if eax == FALSE
    OCall pNewMacros::List.Search, pToken
  .else
    inc eax
  .endif
  ret
IsMacro? endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  IsEquate
; Purpose:    Check if token is an equate.
; Arguments:  Arg1 -> token to check.
; Return:     eax = 0 if FALSE, 1 if macros was previously defined, 2 if it is a known equate.
;             ecx = Index in the range [0..Count].

IsEquate? proc pToken:PTOKEN
  OCall pKnwEquates::List.Search, pToken
  .if eax == FALSE
    OCall pNewEquates::List.Search, pToken
  .else
    inc eax
  .endif
  ret
IsEquate? endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  IsQualifier?
; Purpose:    Check if token is a qualifier.
; Arguments:  Arg1 -> token to check.
; Return:     eax = 0 if FALSE, 1 if qualifier was previously defined, 2 if it is a known qualifier.
;             ecx = Index in the range [0..Count-1].

IsQualifier? proc pToken:PTOKEN
  OCall pKnwQualifiers::List.Search, pToken
  .if eax == FALSE
    OCall pNewQualifiers::List.Search, pToken
  .else
    inc eax
  .endif
  ret
IsQualifier? endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  IsString?
; Purpose:    Check if token is a string.
; Arguments:  Arg1 -> token to check.
; Return:     eax = TRUE if token is a string, otherwise FALSE.

IsString? proc pToken:PTOKEN
  mov xcx, pToken
  mov al, [xcx]
  .if al == '"'
    jmp @IsTrue
  .elseif al >= "0" && al <= "9"
    inc xcx
    .while CHRA ptr [xcx] != 0
      .if CHRA ptr [xcx] == ','
        jmp @IsTrue
      .endif
      inc xcx
    .endw
  .endif
  xor eax, eax
  ret
@IsTrue:
  mov eax, TRUE
  ret
IsString? endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  IsFunction?
; Purpose:    Determine if current item is a "function" declaration.
;             Required if keyword "struct" has been found in input stream.
;             May be a struct declaration or a function returning a struct (ptr).
;             Workaround:
;               + if '*' is found before next ';' or ',', then it is a function.
;               + if '(' is found before next ';' or ',', then it is a function.
;               + if '{' is found before next ';' or ',', then it is a structure.
; Arguments:  None.
; Return:     eax = TRUE if it is a function, otherwise FALSE.

IsFunction? proc
  local dReturn:DWORD, InpStat:INP_STAT

  OCall xbx::IncFile.InputStatusSave, addr InpStat
  inc [xbx].$Obj(IncFile).bSkipLinePP
  mov dReturn, FALSE
  .while TRUE
    OCall xbx::IncFile.GetNextTokenC
    .break .if xax == NULL
    .continue .if !IsIfLevelActive?(InpStat)
    mov cl, [xax]
    .break .if cl == ';' || cl == ')' || cl == '{'
    .if cl == ',' || cl == '*' || cl == '('
      mov dReturn, TRUE
      .break
    .endif
  .endw

@Exit:
  dec [xbx].$Obj(IncFile).bSkipLinePP
  OCall xbx::IncFile.InputStatusLoad, addr InpStat
  mov eax, dReturn
  ret
IsFunction? endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  IsFunctionPtr?
; Purpose:    Determine if it is a "function" or "function ptr" declaration.
; Arguments:  None.
; Return:     eax = TRUE if present, otherwise FALSE.
; Syntax:     ...(...)(...)

;IsFunctionPtr? proc
;  local dParenthesesCount:DWORD, dReturn:DWORD, InpStat:INP_STAT
;
;  OCall xbx::IncFile.InputStatusSave, addr InpStat
;  inc [xbx].$Obj(IncFile).bSkipLinePP
;  mov dParenthesesCount, 1
;  mov dReturn, FALSE
;  .while dParenthesesCount != 0
;    OCall xbx::IncFile.GetNextTokenC
;    .break .if xax == NULL
;    .continue .if !IsIfLevelActive?(InpStat)
;    .if CHRA ptr [xax] == '('
;      inc dParenthesesCount
;    .elseif CHRA ptr [xax] == ')'
;      dec dParenthesesCount
;    .endif
;  .endw
;  .if xax != NULL                                       ;Last Token != NULL
;    OCall xbx::IncFile.GetNextTokenC
;    .if xax != NULL && CHRA ptr [xax] == '('
;      mov dReturn, TRUE
;    .endif
;  .endif
;
;@Exit:
;  dec [xbx].$Obj(IncFile).bSkipLinePP
;  OCall xbx::IncFile.InputStatusLoad, addr InpStat
;  mov eax, dReturn
;  ret
;IsFunctionPtr? endp

IsFunctionPtr? proc pToken:PTOKEN
  local dParenthesesCount:DWORD, dReturn:DWORD, InpStat:INP_STAT

  OCall xbx::IncFile.InputStatusSave, addr InpStat
  mov dReturn, FALSE
  inc [xbx].$Obj(IncFile).bSkipLinePP
  mov xax, pToken
  test xax, xax
  jz @Exit
  
  ;Search for the first parenthesis
  .while CHRA ptr [xax] != '('
    OCall xbx::IncFile.GetNextTokenC
    test xax, xax
    jz @Exit
    cmp CHRA ptr [xax], ';'
    jz @Exit
  .endw
  
  mov dParenthesesCount, 1
  .while dParenthesesCount != 0
    OCall xbx::IncFile.GetNextTokenC
    test xax, xax
    jz @Exit
    .continue .if !IsIfLevelActive?(InpStat)
    .if CHRA ptr [xax] == '('
      inc dParenthesesCount
    .elseif CHRA ptr [xax] == ')'
      dec dParenthesesCount
    .endif
    cmp CHRA ptr [xax], ';'
    jz @Exit
  .endw

  OCall xbx::IncFile.GetNextTokenC
  test xax, xax
  jz @Exit
  .if CHRA ptr [xax] == '('
    mov dReturn, TRUE
  .endif

@Exit:
  dec [xbx].$Obj(IncFile).bSkipLinePP
  OCall xbx::IncFile.InputStatusLoad, addr InpStat
  mov eax, dReturn
  ret
IsFunctionPtr? endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  IsUnionStruct?
; Purpose:    Check if token is "union" or "struct".
; Arguments:  Arg1 -> token.
; Return:     eax = TRUE if found, otherwise FALSE.

IsUnionStruct? proc pToken:PTOKEN
  mov eax, TRUE
  mov xcx, pToken
  .if !$DoesStringMatchA?([xcx], <struct>)
    .if !$DoesStringMatchA?([xcx], <union>)
      xor eax, eax
    .endif
  .endif
  ret
IsUnionStruct? endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  TranslateToken
; Purpose:    Translate tokens like "__export" or "__stdcall".
; Arguments:  Arg1 -> Token.
; Return:     xax -> translated Token.
;             edx = FASLE if no translation occured.

TranslateToken proc pToken:PTOKEN
  OCall pKnwConvTokens::List.Search, pToken
  .if eax != FALSE
    mov edx, ecx
    OCall pKnwConvTokens::List.ItemAt, edx
    mov edx, [xax - sizeof(DWORD)]
    lea xax, [xax + xdx + sizeof(DWORD)]
  .else
    xor edx, edx
    mov xax, pToken
  .endif
  ret
TranslateToken endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  TranslateReservedWord
; Purpose:    Check if token is a reserved name, if yes, add a "_" suffix
; Arguments:  Arg1: -> Token.
;             Arg2: -> Buffer for translation. Holds translated token + suffix.
; Return:     xax -> Translated token.
;             edx: TRUE if translation occured, otherwise FALSE.

TranslateReservedWord proc pToken:PTOKEN, pTransBuffer:PSTRINGA
  invoke IsReservedWord?, pToken
  .if eax != FALSE
    OCall xbx::IncFile.ShowInfo, VERBOSITY_DEAFENING, $OfsCStr("reserved word '%hs' replaced"), pToken
    invoke StrECopyA, pTransBuffer, pToken
    invoke StrCopyA, xax, addr szResWordSuffix
    mov xax, pTransBuffer
    mov edx, TRUE
    ret
  .endif
  xor edx, edx
  mov xax, pToken
  ret
TranslateReservedWord endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  TranslateStruct
; Purpose:    Translate known struct.
; Arguments:  Arg1 -> Token.
; Return:     xax -> translated structure.
;             edx = FALSE if no macht found.

TranslateStruct proc uses xdi pToken:PTOKEN
  OCall pKnwConvTypes1::List.Search, pToken             ;Common for TYPES & STRUCTS
  .if eax != FALSE
    mov edx, ecx
    OCall pKnwConvTypes1::List.ItemAt, edx
    mov edx, [xax - sizeof(DWORD)]                      ;edx = length
    lea xax, [xax + xdx + sizeof(DWORD)]
  .else
    mov xdi, pKnwConvTypes3                             ;STRUCT
    OCall xdi::List.Search, pToken
    .if eax != FALSE
      mov edx, ecx
      OCall xdi::List.ItemAt, edx
      mov edx, [xax - sizeof(DWORD)]                    ;edx = length
      lea xax, [xax + xdx + sizeof(DWORD)]
    .else
      xor edx, edx
      lea xax, szUnkType
    .endif
  .endif
  ret
TranslateStruct endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  TranslateType
; Purpose:    Translate known type.
; Arguments:  Arg1 -> Token.
; Return:     xax -> translated type.
;             edx = FALSE if no macht found.

TranslateType proc uses xdi pToken:PTOKEN
  OCall pKnwConvTypes1::List.Search, pToken             ;Common for TYPES & STRUCTS
  .if eax != FALSE
    mov edx, ecx
    OCall pKnwConvTypes1::List.ItemAt, edx
    mov edx, [xax - sizeof(DWORD)]                      ;edx = length
    lea xax, [xax + xdx + sizeof(DWORD)]
  .else
    mov xdi, pKnwConvTypes2                           ;TYPE
    OCall xdi::List.Search, pToken
    .if eax != FALSE
      mov edx, ecx
      OCall xdi::List.ItemAt, edx
      mov edx, [xax - sizeof(DWORD)]                    ;edx = length
      lea xax, [xax + xdx + sizeof(DWORD)]
    .else
      xor edx, edx
      mov xax, pToken
    .endif
  .endif
  ret
TranslateType endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  TranslateTypeQualifier
; Purpose:    Convert type qualifiers.
; Arguments:  Arg1 -> Type qualifier.
; Return:     xax -> Converted type qualifier.

TranslateTypeQualifier proc pTypeQual:PTOKEN
  OCall pKnwConvTypeQual::List.Search, pTypeQual        ;Ret: eax: TRUE/FALSE, ecx: Index [0..Count]
  .if eax != FALSE
    mov edx, ecx
    OCall pKnwConvTypeQual::List.ItemAt, edx
    mov edx, [xax - sizeof(DWORD)]                      ;edx = length
    lea xax, [xax + xdx + sizeof(DWORD)]                ;xax -> converted string
  .else
    mov xax, pTypeQual
  .endif
  ret
TranslateTypeQualifier endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  TranslateNumOperator
; Purpose:    Translate operator in #define lines.
; Arguments:  Arg1 -> Token.
; Return:     xax -> translated or original Token.
;             edx: TRUE if translated, otherwise FALSE.

TranslateNumOperator proc pToken:PTOKEN
  mov xax, pToken
  mov eax, [xax]

  mov edx, TRUE
  and eax, 0FFFFh
  .if eax == ">>"
    mov xax, $OfsCStrA("shr")
  .elseif (eax == "<<")
    mov xax, $OfsCStrA("shl")
  .else
    and eax, 0FFh
    .if eax == '-'
      mov xax, $OfsCStrA("-")
    .elseif eax == '+'
      mov xax, $OfsCStrA("+")
    .elseif eax == '*'
      mov xax, $OfsCStrA("*")
    .elseif eax == '/'
      mov xax, $OfsCStrA("/")
    .elseif eax == '|'
      mov xax, $OfsCStrA("or")
    .elseif eax == '&'
      mov xax, $OfsCStrA("and")
    .elseif (ax == '~')
      mov xax, $OfsCStrA("not")
    .else
      mov xax, pToken
      xor edx, edx
    .endif
  .endif
  ret
TranslateNumOperator endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  TranslateLogOperator
; Purpose:    Translate operator in #define lines.
; Arguments:  Arg1 -> Token.
; Return:     xax -> translated or original Token.
;             edx: TRUE if translated, otherwise FALSE.

TranslateLogOperator proc pToken:PTOKEN
  mov xax, pToken
  mov eax, [xax]
  mov edx, TRUE

  and eax, 0FFFFh
  .if eax == "=="
    mov xax, $OfsCStrA("eq")
  .elseif (eax == "!=")
    mov xax, $OfsCStrA("ne")
  .elseif (eax == "<=")
    mov xax, $OfsCStrA("le")
  .elseif (eax == ">=")
    mov xax, $OfsCStrA("ge")
  .elseif (eax == "&&")
    mov xax, $OfsCStrA("and")
  .elseif (eax == "||")
    mov xax, $OfsCStrA("or")
  .else
    and eax, 0FFFFh
    .if eax == "<"
      mov xax, $OfsCStrA("lt")
    .elseif eax == ">"
      mov xax, $OfsCStrA("gt")
    .elseif eax == "!"
      mov xax, $OfsCStrA("not")
    .else
      mov xax, pToken
      xor edx, eax
    .endif
  .endif
  ret
TranslateLogOperator endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  ConvBasicTypeC
; Purpose:    Convert a basic "C" type to an "asm" type.
; Arguments:  Arg1: C type specifier (see CTS_xxx equates)
; Return:     xax -> asm type string or NULL if not found.

ConvBasicTypeC proc dTypeSpecC:DWORD
  lea xcx, ConvertBasicTypeTable
  xor eax, eax
  .while TRUE
    mov edx, [xcx].CONV_BASIC_TYPE_ENTRY.dSpec
    .break .if xdx == NULL
    .if edx == dTypeSpecC
      mov xax, [xcx].CONV_BASIC_TYPE_ENTRY.pName
      ret
    .endif
    add xcx, sizeof(CONV_BASIC_TYPE_ENTRY)
  .endw
  ret
ConvBasicTypeC endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  DeleteSimpleParentheses
; Purpose:    Delete surrounding parentheses.
; Arguments:  None.
; Return:     Nothing.

DeleteSimpleParentheses proc uses xsi
  local InpStat:INP_STAT

  OCall xbx::IncFile.InputStatusSave, addr InpStat
  OCall xbx::IncFile.GetNextTokenPP
  .if xax != NULL && CHRA ptr [xax] == '('
    mov xsi, xax
    OCall xbx::IncFile.GetNextTokenPP
    .if xax != NULL
      .if CHRA ptr [xax] == "-"
        OCall xbx::IncFile.GetNextTokenPP
        test xax, xax
        jz @Exit
      .endif
      mov cl, [xax]
      .if cl >= "0" && cl <= "9"
        OCall xbx::IncFile.GetNextTokenPP
        .if xax != NULL && CHRA ptr [xax] == ')'
          mov BYTE ptr [xsi], PCT_IGNORE                ;Ignore opening parenthesis
          mov BYTE ptr [xax], PCT_IGNORE                ;Ignore closing parenthesis
        .endif
      .endif
    .endif
  .endif
@Exit:
  OCall xbx::IncFile.InputStatusLoad, addr InpStat
  ret
DeleteSimpleParentheses endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  SkipCasts
; Purpose:    Skip typecasts in preprocessor lines.
; Arguments:  None.
; Return:     Nothing.

SkipCasts proc uses xdi
  local pToken: PTOKEN, pCastStack:POINTER, bIsName:DWORD, InpStat:INP_STAT

  mov pCastStack, NULL
  mov bIsName, FALSE
  OCall xbx::IncFile.InputStatusSave, addr InpStat
  .while TRUE
    OCall xbx::IncFile.GetNextTokenPP
    .break .if xax == NULL
    mov pToken, xax

    ;Skip MACRO(type) patterns ----------------------------------------------
    .if bIsName == FALSE
      IsValidName? pToken
      .if eax != FALSE
        mov bIsName, TRUE
      .endif
    .endif

    mov xax, pToken
    .if CHRA ptr [xax] == '(' && bIsName != FALSE
      mov bIsName, FALSE
      .continue
    .endif

    ;Check for '(' ... <*> ')' pattern --------------------------------------
    mov xax, pToken
    .if CHRA ptr [xax] == '('
      .if pCastStack == NULL
        mov pCastStack, $Create@Stacklist(xcx)          ;xcx aux register
      .else
        Reset@Stacklist pCastStack, xcx                 ;xcx aux register
      .endif
      Add@Stacklist pCastStack, xax, xdx                ;Save '('
      .continue
    .endif

    .if pCastStack != NULL
      .if CHRA ptr [xax] == ')'
        mov BYTE ptr [xax], PCT_IGNORE                  ;Mark ')'
        mov edi, $GetCount@Stacklist(pCastStack)
        .while edi != 0
          dec edi
          mov xax, $GetItem@Stacklist(pCastStack, edi)
          mov BYTE ptr [xax], PCT_IGNORE                ;Mark all tokens in the stack
        .endw
        Destroy@Stacklist pCastStack
        mov pCastStack, NULL
        mov bIsName, FALSE
        .continue
      .endif

      OCall pKnwSimpleTypes::List.Search, pToken
      .if eax == FALSE                                  ;Only Simple Types allowed betw. parenthesis
        Destroy@Stacklist pCastStack
        mov pCastStack, NULL
      .else
        Add@Stacklist pCastStack, pToken
      .endif
    .else
      IsValidName? pToken
      mov bIsName, eax
    .endif
  .endw
@Error:
  OCall xbx::IncFile.InputStatusLoad, addr InpStat
  Destroy@Stacklist pCastStack
  ret
SkipCasts endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  SkipSimpleBraces
; Purpose:    Skip braces of '(' <number> ')' pattern.
; Arguments:  None.
; Return:     Nothing.

SkipSimpleBraces proc
  local InpStat:INP_STAT

  OCall xbx::IncFile.InputStatusSave, addr InpStat
  .repeat
    IsValidName? [xbx].$Obj(IncFile).pStmInpPos
    .if eax != FALSE
      invoke DeleteSimpleParentheses                    ;Remove them from input stream
    .endif
    OCall xbx::IncFile.GetNextTokenPP
  .until xax == NULL
  OCall xbx::IncFile.InputStatusLoad, addr InpStat
  ret
SkipSimpleBraces endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  SkipBraces
; Purpose:    Skip all Tokens between braces.
; Arguments:  Arg1: opening brace.
;             Arg2: closing brace.
; Return:     xax -> Last Token or NULL.

SkipBraces proc uses xsi cOpenBrace:CHRA, cCloseBrace:CHRA
  mov esi, 1
  .repeat
    OCall xbx::IncFile.GetNextTokenC
    .break .if xax == NULL
    mov cl, [xax]
    .if cl == cOpenBrace
      inc esi
    .elseif cl == cCloseBrace
      dec esi
    .endif
  .until ZERO?
  ret
SkipBraces endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  GetInterfaceName
; Purpose:    Get the name of an interface.
; Arguments:  Arg1: -> Source Name.
;             Arg2: -> Destination Interface.
; Return:     Nothing.

GetInterfaceName proc uses xdi xsi pName:PSTRINGA, pInterface:PSTRINGA
  mov xsi, pName
  mov xdi, pInterface
  mov cl, 0
  .repeat
    lodsb
    .if al != "_"
      inc cl
    .elseif cl != 0
      mov al, 0
    .endif
    stosb
  .until al == 0
  ret
GetInterfaceName endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  SkipName
; Purpose:    Skip name of a struct/union.
; Arguments:  Arg1 -> Name.
;             Arg2: Name flags. if != 0 => skip parentheses.
; Return:     Nothing.

SkipName proc pName:PSTRINGA, dFlags:DWORD
  .if pName != NULL
    OCall xbx::IncFile.GetNextTokenC                    ;Skip name
    mov eax, dFlags
    .if eax != 0
      OCall xbx::IncFile.PeekNextTokenC
      .if xax != NULL && CHRA ptr [xax] == '('
        .while TRUE
          OCall xbx::IncFile.GetNextTokenC
          .break .if xax == NULL
          .break .if CHRA ptr [xax] == ')'
        .endw
      .endif
    .endif
  .endif
  ret
SkipName endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  SkipAnnotations
; Purpose:    Skip all comming annotations.
; Arguments:  Arg1 -> Token.
;             xbx -> IncFile.
; Return:     xax -> Next Token or NULL. If xax == NULL, ZERO is set.

SkipAnnotations proc pToken:PTOKEN
  OCall pKnwAnnotations::List.Search, pToken
  .if eax != FALSE
    OCall xbx::IncFile.GetNextTokenC
    .if xax != NULL
      .if CHRA ptr [xax] == '('
        invoke SkipBraces, '(', ')'
        OCall xbx::IncFile.GetNextTokenC
      .endif
      .if xax != NULL
        invoke SkipAnnotations, xax                     ;Check next Token recursively
      .endif
    .endif
  .else
    mov xax, pToken                                     ;If no annotation found, return old Token
    cmp xax, NULL
  .endif
  ret
SkipAnnotations endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  SkipMacros
; Purpose:    Skip all comming macros.
; Arguments:  Arg1 -> Token.
;             xbx -> IncFile.
; Return:     xax -> Next Token or NULL. If xax == NULL, ZERO is set.

SkipMacros proc pToken:PTOKEN
  invoke IsMacro?, pToken
  .if eax != 0
    OCall xbx::IncFile.GetNextTokenC
    .if xax != NULL
      .if CHRA ptr [xax] == '('
        invoke SkipBraces, '(', ')'
        OCall xbx::IncFile.GetNextTokenC
      .endif
      .if xax != NULL
        invoke SkipMacros, xax                          ;Check next Token recursively
      .endif
    .endif
  .else
    mov xax, pToken
    cmp xax, NULL
  .endif
  ret
SkipMacros endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  If_ElIf
; Purpose:    Process "#if"/"#elif" lines.
; Arguments:  Arg1: PP conditional type: "#if" or "#elif".
; Return:     Nothing.

If_ElIf proc uses xsi bCondType:DWORD
  local Evtor:$Obj(Evaluator)
  local InpStat:INP_STAT, bCondResult:BYTE

  movzx esi, [xbx].$Obj(IncFile).bCondIfLevel
  mrm bCondResult, [xbx].$Obj(IncFile).bCondResult[xsi - 1], al   ;Get current result
  .if bCondType == PCT_IF || (bCondType == PCT_ELIF && al != PPR_TRUE)
    OCall xbx::IncFile.InputStatusSave, addr InpStat
    New Evtor::Evaluator
    OCall Evtor::Evaluator.Init, xbx
    OCall Evtor::Evaluator.Evaluate                     ;Evaluate conditional expression
    mov bCondResult, al                                 ;al = PPR_FALSE, PPR_TRUE or PPR_UNKNOWN
    OCall Evtor::Evaluator.Done
    OCall xbx::IncFile.InputStatusLoad, addr InpStat

    mrm [xbx].$Obj(IncFile).bCondResult[xsi - 1], bCondResult, al ;Store result
    .if bCondType == PCT_IF
      mov [xbx].$Obj(IncFile).bCondHistory[xsi - 1], al   ;Store result in history stack
    .else
      mov cl, [xbx].$Obj(IncFile).bCondHistory[xsi - 1]
      .if al > cl
        mov [xbx].$Obj(IncFile).bCondHistory[xsi - 1], al ;Store result in history stack
      .endif
    .endif
  .endif

  ;Write conditional sentence
  .if bCondType == PCT_IF
    OCall xbx::IncFile.StmWrite, $OfsCStrA("if ")
  .else
    OCall xbx::IncFile.StmWrite, $OfsCStrA("elseif ")
  .endif
  mov [xbx].$Obj(IncFile).bEnableNFCodeLabel, TRUE

  .while TRUE
    OCall xbx::IncFile.GetNextTokenPP
    .break .if xax == NULL
    mov xsi, xax
    .if $DoesStringMatchA?([xsi], <defined>)
      OCall xbx::IncFile.StmWrite, $OfsCBStrA("Defined")
      OCall xbx::IncFile.GetNextTokenPP                 ;Read '('
      .break .if xax == NULL
      mov xsi, xax
      .if CHRA ptr [xsi] == '('                         ;It is written defined or defiend(...)
        OCall xbx::IncFile.StmWrite, xsi
        OCall xbx::IncFile.GetNextTokenPP
        .break .if xax == NULL
        OCall xbx::IncFile.StmWrite, xax
        OCall xbx::IncFile.GetNextTokenPP
        .break .if xax == NULL
        OCall xbx::IncFile.StmWrite, xax
      .else
        OCall xbx::IncFile.StmWriteChar, 28h            ;'('
        OCall xbx::IncFile.StmWrite, xsi
        OCall xbx::IncFile.StmWriteChar, 29h            ;')'
      .endif
    .else
      mov dl, [xsi]
      .if dl >= "0" && dl <= "9"                        ;Check if number (begins with 0..9)
        OCall xbx::IncFile.StmWrite, xsi
      .else
        ;Translate operators in an "#if" expression.
        mov ecx, OpConvTabEntries
        lea xax, OpConvTable
        test ecx, ecx
        .while !ZERO?
          mov dx, DCHRA ptr [xax].OP_CONV_ENTRY.wOp
          .if [xsi] == dx
            mov xsi, [xax].OP_CONV_ENTRY.pSubst
            .break
          .endif
          add xax, sizeof(OP_CONV_ENTRY)
          dec ecx
        .endw

        OCall xbx::IncFile.StmWrite, xsi
      .endif
    .endif
  .endw
  OCall xbx::IncFile.StmWriteEoL

  .if bCondResult == PPR_FALSE
    mov [xbx].$Obj(IncFile).bSkipCondPP, TRUE           ;Swap the PP-command dispatcher tables
    mov [xbx].$Obj(IncFile).bSkipLineC, TRUE
  .else
    mov [xbx].$Obj(IncFile).bSkipCondPP, FALSE
    mov [xbx].$Obj(IncFile).bSkipLineC, FALSE
  .endif

  ret
If_ElIf endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  Ifdef_Ifndef
; Purpose:    Process "#ifdef"/"#ifndef" lines.
; Arguments:  Arg1: PP conditional type: "#ifdef" or "#ifndef".
; Return:     Nothing.

Ifdef_Ifndef proc uses xdi xsi bCondType:DWORD
  local pToken:PTOKEN, bCondResult:BYTE, cTransBuffer[128]:CHRA

  movzx esi, [xbx].$Obj(IncFile).bCondIfLevel
  mrm bCondResult, [xbx].$Obj(IncFile).bCondResult[xsi - 1], al ;Get current result
  .if al != PPR_TRUE
    OCall xbx::IncFile.GetNextTokenPP
    test xax, xax
    jz @ErrorEoF
    mov pToken, xax

    ;Check if it is a known symbol
    lea xdi, EvalKnownSymbolTable
    .while [xdi].EVAL_KNOWN_SYMBOL.pToken != NULL
      invoke StrCompA, pToken, [xdi].EVAL_KNOWN_SYMBOL.pToken
      .if eax == 0                                      ;Found
        .if bCondType == PCT_IFDEF
          .if [xdi].EVAL_KNOWN_SYMBOL.wGenus == EGN_UNDEF
            mov bCondResult, PPR_FALSE
          .elseif [xdi].EVAL_KNOWN_SYMBOL.wGenus == EGN_UNKNOWN
            mov bCondResult, PPR_UNKNOWN
          .else
            mov bCondResult, PPR_TRUE
          .endif
        .elseif bCondType == PCT_IFNDEF
          .if [xdi].EVAL_KNOWN_SYMBOL.wGenus == EGN_UNDEF
            mov bCondResult, PPR_TRUE
          .elseif [xdi].EVAL_KNOWN_SYMBOL.wGenus == EGN_UNKNOWN
            mov bCondResult, PPR_UNKNOWN
          .else
            mov bCondResult, PPR_FALSE
          .endif
        .else
          mov bCondResult, PPR_UNKNOWN
        .endif
        jmp @Found
      .endif
      add xdi, sizeof(EVAL_KNOWN_SYMBOL)
    .endw
    mov bCondResult, PPR_UNKNOWN

@Found:
    mrm [xbx].$Obj(IncFile).bCondResult[xsi - 1], bCondResult, al ;Store result
    mov [xbx].$Obj(IncFile).bCondHistory[xsi - 1], al   ;Store result in history stack

    .if bCondType == PCT_IFDEF
      OCall xbx::IncFile.StmWrite, $OfsCStrA("ifdef ")
    .else
      OCall xbx::IncFile.StmWrite, $OfsCStrA("ifndef ")
    .endif
    invoke TranslateReservedWord, pToken, addr cTransBuffer
    OCall xbx::IncFile.StmWrite, xax
    OCall xbx::IncFile.StmCopyRestOfPPLine
    OCall xbx::IncFile.StmWriteEoL
    mov [xbx].$Obj(IncFile).bEnableNFCodeLabel, TRUE
  .else
    SkipPPLine
  .endif

  .if bCondResult == PPR_FALSE
    mov [xbx].$Obj(IncFile).bSkipCondPP, TRUE           ;Swap the PP-command dispatcher tables
    mov [xbx].$Obj(IncFile).bSkipLineC, TRUE
  .else
    mov [xbx].$Obj(IncFile).bSkipCondPP, FALSE
    mov [xbx].$Obj(IncFile).bSkipLineC, FALSE
  .endif
  ret

@ErrorEoF:
  OCall xbx::IncFile.ShowError, $OfsCStr("unexpected EOL")
  OCall xbx::IncFile.StmWrite, $OfsCStrA("if 0; unexpected EOL")
  SkipPPLine
  ret
Ifdef_Ifndef endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  WriteStackList
; Purpose:    Writes tokens contained in a StackList to the output stream.
; Arguments:  Arg1 -> StackList.
; Return:     Nothing.

WriteStackList proc uses xdi xsi pStackList:POINTER
  local bAddSpace:DWORD, pToken:PTOKEN

  mov edi, $GetCount@Stacklist(pStackList)
  .if edi != 0
    xor esi, esi
    mov bAddSpace, FALSE
    .while edi != 0
      mov xax, $GetItem@Stacklist(pStackList, esi)
      inc esi
      .if CHRA ptr [xax] == '('
        mov bAddSpace, FALSE
      .else
        mov pToken, xax
        mov eax, $GetCount@Stacklist(pStackList)
        .if esi >= eax
          mov bAddSpace, FALSE
        .else
          mov xax, $GetItem@Stacklist(pStackList, esi)
          .if CHRA ptr [xax] == ')' || CHRA ptr [xax] == "."
            mov bAddSpace, FALSE
          .else
            mov bAddSpace, TRUE
          .endif
        .endif
        invoke TranslateNumOperator, pToken
      .endif
      OCall xbx::IncFile.StmWrite, xax
      .if bAddSpace != FALSE
        OCall xbx::IncFile.StmWriteChar, SPC
      .endif
      dec edi
    .endw
  .else
    OCall xbx::IncFile.StmWriteChar, "0"
  .endif
  ret
WriteStackList endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  GetCallConvString
; Purpose:    Return the correct calling convention.
; Arguments:  Arg1 -> CallConv qualifier (PTQ_xxx).
; Return:     xax -> CallConv string. Can not be NULL.

GetCallConvString proc dQualifiers:DWORD
  mov ecx, dQualifiers
  .ifBitSet ecx, PTQ_CDECL
    mov xax, $OfsCStrA("c")
  .elseIfBitSet ecx, PTQ_SYSCALL
    mov xax, $OfsCStrA("syscall")
  .elseIfBitSet ecx, PTQ_FASTCALL
    mov xax, $OfsCStrA("fastcall")
  .elseIfBitSet ecx, PTQ_VECTORCALL
    mov xax, $OfsCStrA("vectorcall")
  .elseIfBitSet ecx, PTQ_PASCAL
    mov xax, $OfsCStrA("pascal")
  .else
    mov xax, $OfsCStrA("WIN_STD_CALL_CONV")
  .endif
  ret
GetCallConvString endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  GetProtoQualifier
; Purpose:    Check proto qualifier (E.g. CALLBACK, WINAPI, WINGDIAPI, THEMEAPI, etc.).
; Arguments:  Arg1 -> Token.
; Return:     xax -> List item or NULL if not found.
; Link:       https://learn.microsoft.com/en-us/cpp/cpp/declspec?view=msvc-170

GetProtoQualifier proc pToken:PTOKEN
  local InpStat:INP_STAT, dLevel:DWORD

  mov xax, pToken
  ;Check for MS extended attribute for storage-class information (align, deprecated, noinline, ...)
  .if $DoesStringMatchA?([xax], <__declspec>)
    OCall xbx::IncFile.InputStatusSave, addr InpStat
    OCall xbx::IncFile.GetNextTokenC
    .if xax != NULL && CHRA ptr [xax] == '('
      OCall xbx::IncFile.GetNextTokenC
      .if xax != NULL
        mov pToken, xax                                 ;Remember only the first token
        mov dLevel, 1                                   ;  and ignore the rest up to the closing
        .while dLevel != 0                              ;  parenthesis
          OCall xbx::IncFile.GetNextTokenC
          test xax, xax
          jz @Exit
          mov cl, [xax]
          .if cl == ')'
            dec dLevel
          .elseif cl == '('
            inc dLevel
          .endif
        .endw
      .else
        OCall xbx::IncFile.InputStatusLoad, addr InpStat
      .endif
    .else
@@:
      OCall xbx::IncFile.InputStatusLoad, addr InpStat
    .endif
  .endif

  OCall pKnwQualifiers::List.Search, pToken
  .if eax != FALSE
    mov edx, ecx
    OCall pKnwQualifiers::List.ItemAt, edx
  .else
    OCall pNewQualifiers::List.Search, pToken
    .if eax != FALSE
      mov edx, ecx
      OCall pNewQualifiers::List.ItemAt, edx
    .endif
  .endif

@Exit:
  ret
GetProtoQualifier endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  GetBlockName
; Purpose:    Find name of a struct/union, if any.
; Arguments:  Arg1 -> Buffer used when the name is a macro invocation.
; Return:     xax -> Block Name or NULL.
;             edx = flags (if name is a macro).

GetBlockName proc uses xdi xsi pMacroNameBuffer:PSTRINGA
  local dBraceCount:DWORD, dFlags:DWORD
  local pName:PSTRINGA, InpStat:INP_STAT, PrevOutStat:STMOUT_STAT

  mov pName, NULL
  mov dFlags, FALSE
  OCall xbx::IncFile.InputStatusSave, addr InpStat
  inc [xbx].$Obj(IncFile).bSkipLinePP

  ;Skip declaration ---------------------------------------------------------
  mov dBraceCount, 1
  .while dBraceCount != 0
    OCall xbx::IncFile.GetNextTokenC
    .break .if xax == NULL
    .continue .if !IsIfLevelActive?(InpStat)
    .if CHRA ptr [xax] == '{'
      inc dBraceCount
    .elseif CHRA ptr [xax] == '}'
      dec dBraceCount
    .endif
  .endw

  .if xax != NULL
    OCall xbx::IncFile.GetNextTokenC
    .if xax != NULL && CHRA ptr [xax] != ';'            ;Statement terminator
      .if CHRA ptr [xax] == '*'
        jmp @Exit
      .endif
      mov pName, xax

      ;There may come a type qualifier or a '*' in which case there is no name
      invoke TranslateTypeQualifier, xax
      .if CHRA ptr [xax] == 0
        mov pName, NULL
        jmp @Exit
      .endif

      invoke IsMacro?, pName
      .if eax != 0
        mov dFlags, TRUE
        .if eax == 2
          mov edx, ecx
          OCall pKnwMacros::List.ItemAt, edx
          mov edx, [xax - sizeof(DWORD)]                ;edx = length
          mov ecx, [xax + xdx]
          BitSet ecx, MCF_KNOWN                         ;Just in case
        .else
          xor ecx, ecx
        .endif
        
        ;Render the macro into a buffer to get the name
        StmOutSave PrevOutStat                          ;Save output stream status
        mov [xbx].$Obj(IncFile).dIndentation, 0
        m2m [xbx].$Obj(IncFile).pStmOutPos, pMacroNameBuffer, xax   ;Write into this buffer
        mov edx, ecx
        invoke RenderMacroCall, pName, edx, FALSE
        StmOutLoad PrevOutStat                          ;Restore initial output stream status
        m2m pName, pMacroNameBuffer, xax
      .endif

    .endif
  .endif

@Exit:
  dec [xbx].$Obj(IncFile).bSkipLinePP
  OCall xbx::IncFile.InputStatusLoad, addr InpStat
  mov xax, pName
  mov edx, dFlags
  ret
GetBlockName endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  ConvertNumber
; Purpose:    Converts number from C syntax to MASM syntax.
; Arguments:  xsi -> Input stream.
;             xdi -> Output stream.
; Return:     Nothing.
; Note:       Must preserve ecx edx.

ConvertNumber proc uses xcx xdx
  xor eax, eax
  mov cx, [xsi]
  .if cx == "x0" || cx == "X0"
    add xsi, 2
    .if CHRA ptr [xsi] > "9"
      mov al, "0"
      stosb
    .endif
    mov dl, 1
  .else
    mov dl, 0
  .endif
  xor ecx, ecx
  .while TRUE
    mov al, [xsi]
    ;Is alphanumeric?
    .if al != "?" && al != "@" && al != "_"
      .if al < "A" || al > "Z"
        .if al < "a" || al > "z"
          .if al < "0" || al > "9"
            ;FALSE
            .if al == "."
              or dl, 2
            .else
              .break
            .endif
          .endif
        .endif
      .endif
    .endif
    movsb
    inc ecx
  .endw
  mov dh, 0
  .if ecx > 3
    mov ax, [xdi - 3]
    or ax, 2020h
    .if al == "i"
      mov ax, [xdi - 2]
      .if ax == "46" || ax == "23" || eax == "61"
        lea xdi, [xdi - 3]
        inc dh
      .endif
    .elseif ah == "i" && CHRA ptr [xdi - 1] == "8"
      lea xdi, [xdi - 2]
      inc dh
    .elseif ecx > 4
      mov eax, [xdi - 4]
      or al, 20h
      .if eax == "821i"
        lea xdi, [xdi - 4]
        inc dh
      .endif
    .endif
    .if dh != 0
      mov al, [xdi - 1]
      or al, 20h
      .if al == "u"
        dec xdi
      .endif
      jmp @Skip
    .endif
  .endif
  .if ecx > 1
    mov al, [xdi - 1]
    or al, 20h
    .if al == "l" || al == "u"
      dec xdi
      .if ecx > 2
        mov ah, [xdi - 1]
        or ah, 20h
        .if ah != al && ah == "u"
          dec xdi
        .endif
      .endif
    .elseif al == "e"
      test dl, 2
      .if !ZERO?
        mov CHRA ptr [xdi - 1], "E"
        mov al, [xsi]
        .if al == "-" || al == "+"
          movsb
          .while TRUE
            mov al, [xsi]
            .if al >= "A"
              or al, 20h
            .endif
            .if (((al >= "0") && (al <= "9")) || (al == "f") || (al == "l"))
              movsb
            .else
              .break
            .endif
          .endw
        .endif
      .endif
    .endif
    test dl, 2
    .if !ZERO?
      mov al, [xdi - 1]
      or al,20h
      .if (al == "f") || (al == "l")
        dec xdi
      .endif
    .endif
  .endif
@Skip:
  test dl, 1
  .if !ZERO?
    mov al, "h"
    stosb
  .endif
  ret
ConvertNumber endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  AddEscStr
; Purpose:    Add some chars to the output stream.
; Arguments:  xsi -> Input stream.
;             xdi -> Output stream.
; Return:     Nothing.
; Note:       Must preserve ecx edx.
;             ch: bit 0 = 1: previous item is enclosed in '"'
;                 bit 1 = 1: no previous char

AddEscStr proc
  push xax
  .if ch == 0
    mov al, '"'
    stosb
  .endif
  .if !(ch & 2)
    mov al, ','
    stosb
  .endif
  pop xax
  xchg al, ah
  stosw
  mov al, "h"
  stosb
  ret
AddEscStr endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure: GetStringLiteral
; Purpose:   String processing.
; Arguments: xsi -> Input stream.
;            xdi -> Output stream.
; Return:    Nothing.
; Note:      Must preserve ecx edx.
;            ch: bit 0 = 1: previous item is enclosed in '"'
;                bit 1 = 1: no previous char

GetStringLiteral proc uses xcx
  mov ch, 2
  .repeat
    lodsb
    .if al == "\"
      lodsb
      .if al >= "0" && al <= "7"
        .if ch == 0
          mov al, '"'
          stosb
        .endif
        mov al, ','
        stosb
        dec xsi
        mov cl, 3
        .while cl != 0
          mov al, [xsi]
          .if al >= "0" && al <= "7"
            stosb
          .else
            .break
          .endif
          inc xsi
          dec cl
        .endw
        .if cl != 3
          mov al, "o"
          stosb
        .endif
      .elseif al == "a"
        mov ax, BELL
        invoke AddEscStr
      .elseif al == "b"
        mov ax, BACK
        invoke AddEscStr
      .elseif al == "f"
        mov ax, FF
        invoke AddEscStr
      .elseif al == "n"
        mov ax, LF
        invoke AddEscStr
      .elseif al == "r"
        mov ax, CR
        invoke AddEscStr
      .elseif al == "t"
        mov ax, HTAB
        invoke AddEscStr
      .elseif al == "v"
        mov ax, VTAB
        invoke AddEscStr
      .elseif al == "x"
        .if ch == 0
          mov al, '"'
          stosb
        .endif
        mov al, ','
        stosb
        mov cl, 3
        .while cl != 0
          mov al, [xsi]
          or al, 20h
          .if al >= "0" && al <= "9"
            stosb
          .elseif al >= "a" && al <= "f"
            .if cl == 3
              mov CHRA ptr [xdi], "0"
              inc xdi
            .endif
            stosb
          .else
            .break
          .endif
          inc xsi
          dec cl
        .endw
        .if cl != 3
          mov al, "h"
          stosb
        .endif
      .elseif al == '"'
        .if ch != 0
          mov al, ','
          stosb
          mov al, '"'
          stosb
        .endif
        stosb
        stosb
        mov ch, 0
        .continue
      .else
        jmp @NormalChar
      .endif
      mov ch, 1
      .continue
    .endif
@NormalChar:
    .if ch != 0
      .if al == '"'
        .break
      .else
        mov ah, al
        .if ch & 1
          mov al, ','
          stosb
        .endif
        mov al, '"'
        stosb
        mov al, ah
      .endif
    .endif
    .if al == 0
      dec xsi
      mov al, '"'
    .endif
    stosb
    mov ch, 0
  .until al == '"'
  ret
GetStringLiteral endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  GotoClosingToken
; Purpose:    Move the input pointer to the ending token.
; Arguments:  Arg1: Opening token.
;             Arg2: Closing token.
; Return:     xax -> Closing token or NULL on EoF and SF set.

GotoClosingToken proc uses xsi cOpeningToken:CHRA, cClosingToken:CHRA
  mov xax, [xbx].$Obj(IncFile).pStmInpPos
  mov esi, 1
  .while TRUE                                               ;Search for the next closing token
    mov cl, [xax]
    .if cl ==  cOpeningToken
      inc esi
    .elseif cl == cClosingToken
      dec esi
      .if ZERO?
        test xax, xax                                       ;SF = 0
        .break
      .endif
    .endif
    OCall xbx::IncFile.GetNextTokenC
    test xax, xax
    jz @ErrorEoF
  .endw

@ErrorEoF:
  ret
GotoClosingToken endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure: GotoNextToken
; Purpose:   Move the input pointer to the token.
; Arguments: Arg1: Token.
; Return:    xax -> Token or NULL on EoF.

GotoNextToken proc uses xsi pToken:PTOKEN
  mov xsi, [xbx].$Obj(IncFile).pStmInpPos                   ;pStmInpPos is one token in advance
  cmp CHRA ptr [xsi], 0
  .while !ZERO?
    invoke StrCompA, xsi, pToken
    .if eax == 0
      mov xax, xsi
      .break
    .endif
    OCall xbx::IncFile.GetNextTokenC
    test xax, xax
    mov xsi, xax
  .endw
  ret
GotoNextToken endp
