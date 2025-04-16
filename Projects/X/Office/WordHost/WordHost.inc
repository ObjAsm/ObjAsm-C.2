externdef IID_NULL:GUID
externdef IID_IUnknown:GUID

include Office.inc
include Wordc.inc
include Word.inc

Object WordHost,, Primer
 RedefineMethod    Init,         Pointer
 StaticMethod      Close,        Pointer
 RedefineMethod    Done          
 StaticMethod      Open,         BSTR, dword, dword
 StaticMethod      SaveAs,       Pointer, BSTR, dword
 StaticMethod      SetVisible,   dword
 StaticMethod      Quit

 DefineVariable    pIWordApp,    Pointer,  NULL
ObjectEnd



if IMPLEMENT

.const
                     
IID_Application GUID {000020970h,00000h,00000h,{0C0h,000h,000h,000h,000h,000h,000h,046h}}

.code

; -------------------------------------------------------------------------------------------------
; Method:    WordHost.Done
; Purpose:   Finalizes the Host object.
; Arguments: None.
; Return:    Nothing.

Method WordHost.Done, uses esi
    SetObject esi
    .if [esi].pIWordApp != NULL
      ICall [esi].pIWordApp::_Application.Release
    .endif
    ACall esi.Done
MethodEnd

; -------------------------------------------------------------------------------------------------
; Method:    WordHost.Close
; Purpose:   Closes a specified document.
; Arguments: Arg1: -> Document Interface.
; Return:    Error code.
; Link:      http://msdn2.microsoft.com/en-us/library/aa171848(office.11).aspx

Method WordHost.Close,, pDocument:Pointer
    local vArg01:VARIANT, vArg02:VARIANT, vArg03:VARIANT

    mov vArg01.VARIANT.vt, VT_BOOL                ;SaveChanges 
    and vArg01.VARIANT.bstrVal, FALSE
    mov vArg02.VARIANT.vt, VT_I4                  ;OriginalFormat
    mov vArg02.VARIANT.lVal, wdOriginalDocumentFormat
    mov vArg03.VARIANT.vt, VT_BOOL                ;RouteDocument
    and vArg03.VARIANT.boolVal, FALSE                
    
    ICall pDocument::_Document.Close, addr vArg01, addr vArg02, addr vArg03
    .if FAILED(eax)
      DbgComError (eax)
    .endif                                       
MethodEnd

; -------------------------------------------------------------------------------------------------
; Method:    WordHost.Init
; Purpose:   Initializes the Host object and creates an Word Application instance.
; Arguments: -> Owner.
; Return:    Nothing.

Method WordHost.Init, uses esi, pOwner:Pointer
    local ClsID:GUID

    SetObject esi
    ACall esi.Init, pOwner

    invoke CLSIDFromProgID, $OfsCWStr("Word.Application"), addr ClsID
    .if SUCCEEDED(eax)
      invoke CoCreateInstance, addr ClsID, 0, CLSCTX_SERVER, offset IID_Application, \ 
                               addr [esi].pIWordApp
    .endif
MethodEnd

; -------------------------------------------------------------------------------------------------
; Method:    WordHost.Open
; Purpose:   Opens a Workbook from a file.
; Arguments: Arg1: -> Filename.
;            Arg2: Read only flag (TRUE or FALSE).
;            Arg3: Visibility flag (TRUE or FALSE).
; Return:    -> Document interface or NULL.
; Link:      http://msdn2.microsoft.com/en-us/library/aa220317(office.11).aspx

Method WordHost.Open,, pFileName:BSTR, dReadOnly:dword, dIsVisible:dword
    local pDocuments:Pointer, pDocument:Pointer
    local vArg01:VARIANT, vArg02:VARIANT, vArg03:VARIANT, vArg04:VARIANT
    local vArg05:VARIANT, vArg06:VARIANT, vArg07:VARIANT, vArg08:VARIANT
    local vArg09:VARIANT, vArg10:VARIANT, vArg11:VARIANT, vArg12:VARIANT

    SetObject ecx
    and pDocument, NULL
    ICall [ecx].pIWordApp::_Application.get_Documents, addr pDocuments
    .if SUCCEEDED(eax)
      mov vArg01.VARIANT.vt, VT_BSTR            ;File name
      mov eax, pFileName
      m2m vArg01.VARIANT.bstrVal, eax 
      mov vArg03.VARIANT.vt, VT_BOOL            ;Read only
      mov eax, dReadOnly
      mov vArg03.VARIANT.boolVal, ax   
      mov vArg12.VARIANT.vt, VT_BOOL            ;Is Visible
      mov eax, dIsVisible
      mov vArg12.VARIANT.boolVal, ax          
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
    mov eax, pDocument
MethodEnd

; -------------------------------------------------------------------------------------------------
; Method:    WordHost.SaveAs
; Purpose:   Saves a specified Workbook.
; Arguments: Arg1: -> Document Interface.
;            Arg2: -> New file name.
;            Arg3: New document format.
; Return:    Error code.
; Link:      http://msdn2.microsoft.com/en-us/library/aa220734(office.11).aspx

Method WordHost.SaveAs,, pDocument:Pointer, pNewFileName:BSTR, dFormat:dword
    local vArg01:VARIANT, vArg02:VARIANT, vArg03:VARIANT, vArg04:VARIANT
    local vArg05:VARIANT, vArg06:VARIANT, vArg07:VARIANT, vArg08:VARIANT
    local vArg09:VARIANT, vArg10:VARIANT, vArg11:VARIANT

    mov vArg01.VARIANT.vt, VT_BSTR                ;FileName
    m2m vArg01.VARIANT.bstrVal, pNewFileName, eax
    mov vArg02.VARIANT.vt, VT_I4                  ;FileFormat
    m2m vArg02.VARIANT.lVal, dFormat, eax
    mov vArg03.VARIANT.vt, VT_BOOL                ;LockComments
    and vArg03.VARIANT.boolVal, FALSE
    mov vArg05.VARIANT.vt, VT_BOOL                ;AddToRecentFiles
    and vArg05.VARIANT.boolVal, FALSE
    mov vArg07.VARIANT.vt, VT_BOOL                ;ReadOnlyRecommended
    and vArg07.VARIANT.boolVal, FALSE
    mov vArg08.VARIANT.vt, VT_BOOL                ;EmbedTrueTypeFonts
    and vArg08.VARIANT.boolVal, FALSE
    mov vArg09.VARIANT.vt, VT_BOOL                ;SaveNativePictureFormat
    mov vArg09.VARIANT.boolVal, TRUE
    mov vArg10.VARIANT.vt, VT_BOOL                ;SaveFormsData
    mov vArg10.VARIANT.boolVal, TRUE
    mov vArg11.VARIANT.vt, VT_BOOL                ;SaveAsAOCELetter
    mov vArg11.VARIANT.boolVal, TRUE
    TypeMissing vArg04, vArg06                    ;Passwords read/write
    
    ICall pDocument::_Document.SaveAs, addr vArg01, addr vArg02, addr vArg03, addr vArg04, \
                                       addr vArg05, addr vArg06, addr vArg07, addr vArg08, \
                                       addr vArg09, addr vArg10, addr vArg11
    .if FAILED(eax)
      DbgComError (eax)
    .endif                                       
MethodEnd

; -------------------------------------------------------------------------------------------------
; Method:    WordHost.SetVisible
; Purpose:   Toggles visibility of the Word Application.
; Arguments: TRUE/FALSE.
; Return:    Nothing.

Method WordHost.SetVisible,, dVisibility:dword
    SetObject ecx
    ICall [ecx].pIWordApp::_Application.put_Visible, dVisibility
MethodEnd

; -------------------------------------------------------------------------------------------------
; Method:    WordHost.Quit
; Purpose:   Quits Word Application.
; Arguments: None
; Return:    Nothing.

Method WordHost.Quit
    local vArg01:VARIANT, vArg02:VARIANT, vArg03:VARIANT

    mov vArg01.VARIANT.vt, VT_BOOL                ;SaveChanges 
    and vArg01.VARIANT.bstrVal, FALSE
    mov vArg02.VARIANT.vt, VT_I4                  ;OriginalFormat
    mov vArg02.VARIANT.lVal, wdOriginalDocumentFormat
    mov vArg03.VARIANT.vt, VT_BOOL                ;RouteDocument
    and vArg03.VARIANT.boolVal, FALSE                

    SetObject ecx
    ICall [ecx].pIWordApp::_Application.Quit, addr vArg01, addr vArg02, addr vArg03
MethodEnd

endif
