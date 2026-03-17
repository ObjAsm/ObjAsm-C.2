; ==================================================================================================
; Title:      SortedStrCollection.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm support of SortedStrCollectionA and SortedStrCollectionW objects.
; Notes:      Version C.1.0, October 2017
;               - Initial release.
; ==================================================================================================


if TARGET_STR_TYPE eq STR_TYPE_ANSI
  SortedStrCollection textequ <SortedStrCollectionA>
  %include &ObjPath&SortedStrCollectionA.inc
elseif TARGET_STR_TYPE eq STR_TYPE_WIDE
  SortedStrCollection textequ <SortedStrCollectionW>
  %include &ObjPath&SortedStrCollectionW.inc
else
  echo <Warning: incompatible TARGET_STR_TYPE>
endif
