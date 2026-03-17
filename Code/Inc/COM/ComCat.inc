; ==================================================================================================
; Title:      ComCat.inc
; Author:     G.Friedrich
; Version:    C.1.0
; Purpose:    COM Categories interfacing
; Notes:      Version C.1.0, October 2017
;               - Initial release.
; ==================================================================================================


;DefGUID CLSID_StdComponentCategoriesMgr, <0002E005-0000-0000-C000-000000000046>
;DefGUID IID_ICatInformation, %sIID_ICatInformation


CATEGORYINFO struc
  catid           GUID    {}
  lcid            LCID    ?
  szDescription   OLECHAR 128 dup (?)
CATEGORYINFO ends


COM_INTERFACE_BEG IEnumGUID, IUnknown, <0002E000-0000-0000-C000-000000000046>
  COM_STD_METHOD   Next,       DWORD, POINTER, POINTER
  COM_STD_METHOD   Skip,       DWORD 
  COM_STD_METHOD   Reset
  COM_STD_METHOD   Clone,      POINTER 
COM_INTERFACE_END

IEnumCLSID      textequ <IEnumGUID>
sIID_IEnumCLSID textequ <sIID_IEnumGUID>

IEnumCATID      textequ <IEnumGUID>
sIID_IEnumCATID textequ <sIID_IEnumGUID>


COM_INTERFACE_BEG IEnumCATEGORYINFO, IUnknown, <0002E011-0000-0000-C000-000000000046>
  COM_STD_METHOD   Next,       DWORD, POINTER, POINTER
  COM_STD_METHOD   Skip,       DWORD 
  COM_STD_METHOD   Reset
  COM_STD_METHOD   Clone,      POINTER 
COM_INTERFACE_END


COM_INTERFACE_BEG ICatRegister, IUnknown, <0002E012-0000-0000-C000-000000000046>
  COM_STD_METHOD   RegisterCategories,             DWORD, POINTER 
  COM_STD_METHOD   UnRegisterCategories,           DWORD, POINTER 
  COM_STD_METHOD   RegisterClassImplCategories,    POINTER, DWORD, POINTER 
  COM_STD_METHOD   UnRegisterClassImplCategories,  POINTER, DWORD, POINTER 
  COM_STD_METHOD   RegisterClassReqCategories,     POINTER, DWORD, POINTER
  COM_STD_METHOD   UnRegisterClassReqCategories,   POINTER, DWORD, POINTER 
COM_INTERFACE_END


COM_INTERFACE_BEG ICatInformation, IUnknown, <0002E013-0000-0000-C000-000000000046>
  COM_STD_METHOD   EnumCategories,                 DWORD, POINTER 
  COM_STD_METHOD   GetCategoryDesc,                POINTER, DWORD, POINTER  
  COM_STD_METHOD   EnumClassesOfCategories,        DWORD, POINTER, DWORD, POINTER, POINTER 
  COM_STD_METHOD   IsClassOfCategories,            POINTER, DWORD, POINTER, DWORD, POINTER
  COM_STD_METHOD   EnumImplCategoriesOfClass,      POINTER, POINTER 
  COM_STD_METHOD   EnumReqCategoriesOfClass,       POINTER, POINTER 
COM_INTERFACE_END
