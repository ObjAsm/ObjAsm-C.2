; ==================================================================================================
; Title:      WordHost.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm supports of Word Host objects.
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


; ==================================================================================================
;     Object definitions
; ==================================================================================================


externdef IID_NULL:GUID
externdef IID_IUnknown:GUID

; --------------------------------------------------------------------------------------------------
; Object:     WordHost
; Purpose:    Implement a Host object for Word automation.

Object WordHost,, Primer
 RedefineMethod    Init,         POINTER
 StaticMethod      Close,        POINTER
 RedefineMethod    Done
 StaticMethod      Open,         BSTR, DWORD, DWORD
 StaticMethod      SaveAs,       POINTER, BSTR, DWORD
 StaticMethod      SetVisible,   DWORD
 StaticMethod      Quit

 DefineVariable    pIWordApp,    POINTER,  NULL
ObjectEnd


% include &OA_PATH&Projects\X\Office\Office.inc
% include &OA_PATH&Projects\X\Office\Officec.inc
% include &OA_PATH&Projects\X\Office\WordHost\Word.inc
% include &OA_PATH&Projects\X\Office\WordHost\Wordc.inc


if IMPLEMENT

.const

IID_Application GUID {000020970h,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}

.code

; --------------------------------------------------------------------------------------------------
; Method:     WordHost.Done
; Purpose:    Finalize the WordHost object.
; Arguments:  None.
; Return:     Nothing.

Method WordHost.Done, uses xsi
  SetObject xsi
  .if [xsi].pIWordApp != NULL
    ICall [xsi].pIWordApp::_Application.Release
  .endif
  ACall xsi.Done
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     WordHost.Close
; Purpose:    Close a specified document.
; Arguments:  Arg1: -> Document Interface.
; Return:     eax = Error code.
; Link:       http://msdn2.microsoft.com/en-us/library/aa171848(office.11).aspx

Method WordHost.Close,, pDocument:POINTER
  local vArg01:VARIANT, vArg02:VARIANT, vArg03:VARIANT

  mov vArg01.vt, VT_BOOL                                ;SaveChanges
  m2z vArg01.bstrVal
  mov vArg02.vt, VT_I4                                  ;OriginalFormat
  mov vArg02.lVal, wdOriginalDocumentFormat
  mov vArg03.vt, VT_BOOL                                ;RouteDocument
  m2z vArg03.boolVal

  ICall pDocument::_Document.Close, addr vArg01, addr vArg02, addr vArg03
  .if FAILED(eax)
    DbgComError (eax)
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     WordHost.Init
; Purpose:    Initialize the WordHost object and creates an Word Application instance.
; Arguments:  Arg1: -> Owner object.
; Return:     Nothing.

Method WordHost.Init, uses xsi, pOwner:POINTER
  local ClsID:GUID

  SetObject xsi
  ACall xsi.Init, pOwner

  invoke CLSIDFromProgID, $OfsCStrW("Word.Application"), addr ClsID
  .if SUCCEEDED(eax)
    invoke CoCreateInstance, addr ClsID, 0, CLSCTX_SERVER, offset IID_Application, \
                             addr [xsi].pIWordApp
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     WordHost.Open
; Purpose:    Open a Workbook from a file.
; Arguments:  Arg1: -> Filename.
;             Arg2: Read only flag (TRUE or FALSE).
;             Arg3: Visibility flag (TRUE or FALSE).
; Return:     xax -> Document interface or NULL.
; Link:       http://msdn2.microsoft.com/en-us/library/aa220317(office.11).aspx

Method WordHost.Open,, pFileName:BSTR, dReadOnly:DWORD, dIsVisible:DWORD
  local pDocuments:POINTER, pDocument:POINTER
  local vArg01:VARIANT, vArg02:VARIANT, vArg03:VARIANT, vArg04:VARIANT
  local vArg05:VARIANT, vArg06:VARIANT, vArg07:VARIANT, vArg08:VARIANT
  local vArg09:VARIANT, vArg10:VARIANT, vArg11:VARIANT, vArg12:VARIANT

  SetObject xcx
  m2z pDocument
  ICall [xcx].pIWordApp::_Application.get_Documents, addr pDocuments
  .if SUCCEEDED(eax)
    mov vArg01.vt, VT_BSTR                              ;File name
    mov xax, pFileName
    mov vArg01.bstrVal, xax
    mov vArg03.vt, VT_BOOL                              ;Read only
    mov eax, dReadOnly
    mov vArg03.boolVal, ax
    mov vArg12.vt, VT_BOOL                              ;Is Visible
    mov eax, dIsVisible
    mov vArg12.boolVal, ax
    TypeMissing vArg02, vArg04, vArg05, vArg06, vArg07, vArg08, vArg09, vArg10, vArg11

    ICall pDocuments::Documents.Open, addr vArg01, addr vArg02, addr vArg03, addr vArg04, \
                                      addr vArg05, addr vArg06, addr vArg07, addr vArg08, \
                                      addr vArg09, addr vArg10, addr vArg11, addr vArg12, \
                                      addr pDocument

    .if SUCCEEDED(eax)
      ICall pDocument::_Document.Activate
    .else
      DbgComError eax
    .endif
    ICall pDocuments::Documents.Release
  .endif
  mov xax, pDocument
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     WordHost.SaveAs
; Purpose:    Save a specified Workbook.
; Arguments:  Arg1: -> Document Interface.
;             Arg2: -> New file name.
;             Arg3: New document format.
; Return:     eax = Error code.
; Link:       http://msdn2.microsoft.com/en-us/library/aa220734(office.11).aspx

Method WordHost.SaveAs,, pDocument:POINTER, pNewFileName:BSTR, dFormat:DWORD
  local vArg01:VARIANT, vArg02:VARIANT, vArg03:VARIANT, vArg04:VARIANT
  local vArg05:VARIANT, vArg06:VARIANT, vArg07:VARIANT, vArg08:VARIANT
  local vArg09:VARIANT, vArg10:VARIANT, vArg11:VARIANT

  mov vArg01.vt, VT_BSTR                                ;FileName
  m2m vArg01.bstrVal, pNewFileName, xax
  mov vArg02.vt, VT_I4                                  ;FileFormat
  m2m vArg02.lVal, dFormat, eax
  TypeMissing vArg03, vArg04, vArg05, vArg06, vArg07, vArg08, vArg09, vArg10, vArg11

  ICall pDocument::_Document.SaveAs, addr vArg01, addr vArg02, addr vArg03, addr vArg04, \
                                     addr vArg05, addr vArg06, addr vArg07, addr vArg08, \
                                     addr vArg09, addr vArg10, addr vArg11
  .if FAILED(eax)
    DbgComError (eax)
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     WordHost.SetVisible
; Purpose:    Toggle visibility of the Word Application.
; Arguments:  Arg1: TRUE/FALSE.
; Return:     Nothing.

Method WordHost.SetVisible,, dVisibility:DWORD
  SetObject xcx
  ICall [xcx].pIWordApp::_Application.put_Visible, dVisibility
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     WordHost.Quit
; Purpose:    Quit Word Application.
; Arguments:  None.
; Return:     Nothing.

Method WordHost.Quit
  local vArg01:VARIANT, vArg02:VARIANT, vArg03:VARIANT

  mov vArg01.vt, VT_BOOL                                ;SaveChanges
  m2z vArg01.bstrVal
  mov vArg02.vt, VT_I4                                  ;OriginalFormat
  mov vArg02.lVal, wdOriginalDocumentFormat
  mov vArg03.vt, VT_BOOL                                ;RouteDocument
  m2z vArg03.boolVal

  SetObject xcx
  ICall [xcx].pIWordApp::_Application.Quit, addr vArg01, addr vArg02, addr vArg03
MethodEnd

endif
