; ==================================================================================================
; Title:      SortedWordVector.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm support of SortedWordVector objects.
; Notes:      Version C.1.0, February 2024
;               - First release.
; ==================================================================================================


TSortedVectorName   textequ   <SortedWordVector>
TSortedVectorID     textequ   <SortedWordVectorID>
AncestorVectorName  textequ   <WordVector>
TVEC_ITEM_TYPE      textequ   <WORD>
TVectorDupCheck     equ       TRUE 
TVectorDupInit      equ       FALSE
TVectorOrdering     textequ   <0>
TVectorOrdInit      textequ   <0>

include .\TSortedVector.inc                             ;Template file