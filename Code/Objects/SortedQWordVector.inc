; ==================================================================================================
; Title:      SortedQWordVector.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm support of QWordVector objects.
; Notes:      Version C.1.0, February 2024
;               - First release.
; ==================================================================================================


TSortedVectorName   textequ   <SortedQWordVector>
TSortedVectorID     textequ   <SortedQWordVectorID>
AncestorVectorName  textequ   <QWordVector>
TVEC_ITEM_TYPE      textequ   <QWORD>
TVectorDupCheck     equ       TRUE 
TVectorDupInit      equ       FALSE
TVectorOrdering     textequ   <0>
TVectorOrdInit      textequ   <0>

include .\TSortedVector.inc                             ;Template file