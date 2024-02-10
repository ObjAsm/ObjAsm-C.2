; ==================================================================================================
; Title:      ByteVector.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm support of ByteVector objects.
; Notes:      Version C.1.0, February 2024
;             - First release.
; ==================================================================================================


TVectorName         textequ   <ByteVector>
TVectorID           textequ   <ByteVectorID>
TVEC_ITEM_TYPE      textequ   <BYTE>

include .\TVector.inc                                   ;Template filedw