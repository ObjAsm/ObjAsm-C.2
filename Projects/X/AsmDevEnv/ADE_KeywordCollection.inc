; ==================================================================================================
; Title:      ADE_KeywordCollection.inc
; Author:     G. Friedrich
; Version:    See ACE.asm
; Purpose:    ObjAsm KeywordCollection object implementation.
; ==================================================================================================


; ==================================================================================================
; KeywordCollection implementation
; ==================================================================================================

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:    KeywordCollection.Compare
; Purpose:   Compare the WIDE strings Key1 and Key2.
; Arguments: Arg1: -> First key.
;            Arg2: -> Second key.
; Return:    eax =   (-)  if Key1 < Key2
;                     0   if Key1 = Key2
;                    (+)  if Key1 > Key2

Method KeywordCollection.Compare,, pCollKey:PKEYWORD, pTestKey:PKEYWORD
;  ?mov xdx, pCollKey                                    ; -> KEYWORD structure (Items)
;  mov xcx, pTestKey                                     ; -> KEYWORD structure (Target)
;  
;  invoke StrCIComp, [xcx].KEYWORD.pString, $OfsCStr("endif"), 5
;  .if eax == 0
;    int 3
;  .endif
;  mov xdx, pCollKey                                    ; -> KEYWORD structure (Items)
;
;  mov xcx, pTestKey                                     ; -> KEYWORD structure (Target)
;  mov eax, [xcx].KEYWORD.dLength                        ;Get the string length
;  sub eax, [xdx].KEYWORD.dLength
;  .if ZERO?
;    mov eax, [xdx].KEYWORD.dLength
;    .ifAnyBitSet [xdx].KEYWORD.dFlags, KWF_CASE_SENSITIVE or KWF_CASE_CONVERT 
;      invoke StrCComp, [xcx].KEYWORD.pString, [xdx].KEYWORD.pString, eax
;    .else
;      invoke StrCIComp, [xcx].KEYWORD.pString, [xdx].KEYWORD.pString, eax
;    .endif
;  .endif

  ?mov xdx, pCollKey                                    ; -> KEYWORD structure (Items)
  mov eax, [xdx].KEYWORD.dLength                        ;Get the string length
  mov xcx, pTestKey                                     ; -> KEYWORD structure (Target)
  .if eax == [xcx].KEYWORD.dLength                      ;Compare lengths
    .ifAnyBitSet [xdx].KEYWORD.dFlags, KWF_CASE_SENSITIVE or KWF_CASE_CONVERT 
      invoke StrCIComp, [xcx].KEYWORD.pString, [xdx].KEYWORD.pString, eax           ;§§§§§§§§§§§§§§§§§§§§§§§§§§§
    .else
      invoke StrCIComp, [xcx].KEYWORD.pString, [xdx].KEYWORD.pString, eax
    .endif
  .else
    mov edx, [xcx].KEYWORD.dLength
    sub eax, edx
;    neg eax
  .endif


;  ?mov xdx, pKey1                                       ; -> KEYWORD structure (Items)
;  mov xcx, pKey2                                        ; -> KEYWORD structure (Target)
;  mov eax, [xcx].KEYWORD.dLength                        ;Get the string length
;  .if eax < [xdx].KEYWORD.dLength
;    invoke StrCIComp, [xcx].KEYWORD.pString, [xdx].KEYWORD.pString, eax
;    .if eax == 0
;      dec eax
;    .endif
;  .elseif eax < [xdx].KEYWORD.dLength
;    mov eax, [xdx].KEYWORD.dLength
;    invoke StrCIComp, [xcx].KEYWORD.pString, [xdx].KEYWORD.pString, eax
;    .if eax == 0
;      inc eax
;    .endif
;  .else
;    invoke StrCIComp, [xcx].KEYWORD.pString, [xdx].KEYWORD.pString, eax
;  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     KeywordCollection.Insert
; Purpose:    If the target item is not found in the sorted collection, it is inserted at the
;             correct index position. Calls Search to determine if the item exists, and if not,
;             where to insert it.
; Arguments:  Arg1: -> KeywordGoup
;             Arg2: Keyword flags
;             Arg3: String length
;             Arg3: -> String
; Return:     xax -> Inserted item or NULL if the item was not inserted.
; Note:       Don't change the order of method arguments! They build a KEYWORD structure.

Method KeywordCollection.Insert, uses xbx xsi, pGroup:PKEYWORDGROUP, dFlags:DWORD, \
                                               dLength:DWORD, pString:PSTRING
  SetObject xsi
  MemAlloc sizeof(KEYWORD)
  .if xax != NULL
    mov xbx, xax                                          ;xbx -> KEYWORD 
    m2m [xbx].KEYWORD.pGroup, pGroup, xdx
    m2m [xbx].KEYWORD.dFlags, dFlags, ecx
    m2m [xbx].KEYWORD.dLength, dLength, eax  
    m2m [xbx].KEYWORD.pString, pString, xdx   
    OCall xsi.KeyOf, xbx
    OCall xsi.Search, xax                                 ;eax = Found (TRUE/FALSE), ecx = Index
    .if eax == FALSE                                      ;Found?
      mov edx, ecx
      OCall xsi.InsertAt, edx, xbx
    .else
      DbgText "--- Duplicate Keyword ---"
      DbgStr [xbx].KEYWORD.pString
      DbgHex [xbx].KEYWORD.dFlags
      MemFree xbx
      xor eax, eax
    .endif
  .endif
MethodEnd
