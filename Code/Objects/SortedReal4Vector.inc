; ==================================================================================================
; Title:      SortedReal4Vector.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm support of SortedReal4Vector objects.
; Notes:      Version C.1.0, February 2024
;               - First release.
; ==================================================================================================


TSortedVectorName   textequ   <SortedReal4Vector>
TSortedVectorID     textequ   <SortedReal4VectorID>
AncestorVectorName  textequ   <Real4Vector>
TVEC_ITEM_TYPE      textequ   <REAL4>
TVectorDupCheck     equ       TRUE 
TVectorDupInit      equ       FALSE
TVectorOrdering     textequ   <0>
TVectorOrdInit      textequ   <0>

include .\TSortedVector.inc                             ;Template file