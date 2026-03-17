; ==================================================================================================
; Title:      StrCollection.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm support of StrCollectionA and StrCollectionW objects.
; Notes:      Version C.1.0, October 2017
;               - Initial release.
; ==================================================================================================


if TARGET_STR_TYPE eq STR_TYPE_ANSI
  StrCollection textequ <StrCollectionA>
  %include &ObjPath&StrCollectionA.inc
elseif TARGET_STR_TYPE eq STR_TYPE_WIDE
  StrCollection textequ <StrCollectionW>
  %include &ObjPath&StrCollectionW.inc
else
  echo <Warning: incompatible TARGET_STR_TYPE>
endif
