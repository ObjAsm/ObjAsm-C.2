; ==================================================================================================
; Title:      SortedByteVector.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm support of SortedByteVector objects.
; Notes:      Version C.1.0, February 2024
;             - First release.
; ==================================================================================================


TSortedVectorName   textequ   <SortedByteVector>
TSortedVectorID     textequ   <SortedByteVectorID>
AncestorVectorName  textequ   <ByteVector>
TVEC_ITEM_TYPE      textequ   <BYTE>
TVectorDupCheck     equ       TRUE 
TVectorDupInit      equ       FALSE
TVectorOrdering     textequ   <0>
TVectorOrdInit      textequ   <0>

include .\TSortedVector.inc                             ;Template file