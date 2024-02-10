; ==================================================================================================
; Title:      WordVector.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm support of WordVector objects.
; Notes:      Version C.1.0, February 2024
;               - First release.
; ==================================================================================================


TVectorName         textequ   <WordVector>
TVectorID           textequ   <WordVectorID>
TVEC_ITEM_TYPE      textequ   <WORD>

include .\TVector.inc                                   ;Template file