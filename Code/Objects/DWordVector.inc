; ==================================================================================================
; Title:      DWordVector.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm support of DWordVector objects.
; Notes:      Version C.1.0, February 2024
;               - First release.
; ==================================================================================================


TVectorName         textequ   <DWordVector>
TVectorID           textequ   <DWordVectorID>
TVEC_ITEM_TYPE      textequ   <DWORD>

include .\TVector.inc                                   ;Template file