; ==================================================================================================
; Title:      SortedDWordVector.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm support of SortedDWordVector objects.
; Notes:      Version C.1.0, February 2024
;               - First release.
; ==================================================================================================


TSortedVectorName   textequ   <SortedDWordVector>
TSortedVectorID     textequ   <SortedDWordVectorID>
AncestorVectorName  textequ   <DWordVector>
TVEC_ITEM_TYPE      textequ   <DWORD>
TVectorDupCheck     equ       TRUE 
TVectorDupInit      equ       FALSE
TVectorOrdering     textequ   <0>
TVectorOrdInit      textequ   <0>

include .\TSortedVector.inc                             ;Template file