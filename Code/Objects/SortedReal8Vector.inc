; ==================================================================================================
; Title:      SortedReal8Vector.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm support of SortedReal8Vector objects.
; Notes:      Version C.1.0, February 2024
;               - First release.
; ==================================================================================================


TSortedVectorName   textequ   <SortedReal8Vector>
TSortedVectorID     textequ   <SortedReal8VectorID>
AncestorVectorName  textequ   <Real8Vector>
TVEC_ITEM_TYPE      textequ   <REAL8>
TVectorDupCheck     equ       TRUE 
TVectorDupInit      equ       FALSE
TVectorOrdering     textequ   <0>
TVectorOrdInit      textequ   <0>

include .\TSortedVector.inc                             ;Template file