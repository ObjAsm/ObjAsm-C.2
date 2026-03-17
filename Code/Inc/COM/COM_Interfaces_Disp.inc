; ==================================================================================================
; Title:      COM_Interfaces_Disp.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm common COM Dispatch Interfaces.
; Notes:      Most of the interfaces can be found in the OBJIDL.H file.
;             Version 1.0.0, October 2017
;               - Initial release.
; ==================================================================================================


sIID_IFontEventsDisp            textequ   <4EF6100A-AF88-11D0-9846-00C04FC29993>
sIID_IPictureDisp               textequ   <7BF80981-BF32-101A-8BBB-00AA00300CAB>


; ==================================================================================================
;    Dispatch Interface definitions
; ==================================================================================================


;IFontDisp provides only a subset of the IFont methods for automation servers!

COM_INTERFACE_BEG IFontDisp, IDispatch, <BEF6E003-A874-101A-8BBA-00AA00300CAB>
  COM_MTD_DSP   get_Name,                    :ptr BSTR
  COM_MTD_DSP   put_Name,                    :BSTR
  COM_MTD_DSP   get_Size,                    :POINTER
  COM_MTD_DSP   put_Size,                    :QWORD
  COM_MTD_DSP   get_Bold,                    :POINTER
  COM_MTD_DSP   put_Bold,                    :DWORD
  COM_MTD_DSP   get_Italic,                  :POINTER
  COM_MTD_DSP   put_Italic,                  :DWORD
  COM_MTD_DSP   get_Underline,               :POINTER
  COM_MTD_DSP   put_Underline,               :DWORD
  COM_MTD_DSP   get_Strikethrough,           :POINTER
  COM_MTD_DSP   put_Strikethrough,           :DWORD
  COM_MTD_DSP   get_Weight,                  :POINTER
  COM_MTD_DSP   put_Weight,                  :DWORD
  COM_MTD_DSP   get_Charset,                 :POINTER
  COM_MTD_DSP   put_Charset,                 :DWORD
COM_INTERFACE_END

DEFINE_COM_MTD_DSP  IFontDisp, get_Name,          000h, PROPERTYGET, VT_BSTR
DEFINE_COM_MTD_DSP  IFontDisp, put_Name,          000h, PROPERTYPUT, VT_BSTR
DEFINE_COM_MTD_DSP  IFontDisp, get_Size,          002h, PROPERTYGET, VT_I8
DEFINE_COM_MTD_DSP  IFontDisp, put_Size,          002h, PROPERTYPUT, VT_I8
DEFINE_COM_MTD_DSP  IFontDisp, get_Bold,          003h, PROPERTYGET, VT_I4
DEFINE_COM_MTD_DSP  IFontDisp, put_Bold,          003h, PROPERTYPUT, VT_I4
DEFINE_COM_MTD_DSP  IFontDisp, get_Italic,        004h, PROPERTYGET, VT_I4
DEFINE_COM_MTD_DSP  IFontDisp, put_Italic,        004h, PROPERTYPUT, VT_I4
DEFINE_COM_MTD_DSP  IFontDisp, get_Underline,     005h, PROPERTYGET, VT_I4
DEFINE_COM_MTD_DSP  IFontDisp, put_Underline,     005h, PROPERTYPUT, VT_I4
DEFINE_COM_MTD_DSP  IFontDisp, get_Strikethrough, 006h, PROPERTYGET, VT_I4
DEFINE_COM_MTD_DSP  IFontDisp, put_Strikethrough, 006h, PROPERTYPUT, VT_I4
DEFINE_COM_MTD_DSP  IFontDisp, get_Weight,        007h, PROPERTYGET, VT_I4
DEFINE_COM_MTD_DSP  IFontDisp, put_Weight,        007h, PROPERTYPUT, VT_I4
DEFINE_COM_MTD_DSP  IFontDisp, get_Charset,       008h, PROPERTYGET, VT_I4
DEFINE_COM_MTD_DSP  IFontDisp, put_Charset,       008h, PROPERTYPUT, VT_I4
