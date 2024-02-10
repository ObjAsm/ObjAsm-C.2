; ==================================================================================================
; Title:      QWordVector.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm support of QWordVector objects.
; Notes:      Version C.1.0, February 2024
;               - First release.
; ==================================================================================================


TVectorName         textequ   <QWordVector>
TVectorID           textequ   <QWordVectorID>
TVEC_ITEM_TYPE      textequ   <QWORD>

include .\TVector.inc                                   ;Template file
