; ==================================================================================================
; Title:      OA_Tools_About.inc
; Author:     G. Friedrich
; Version:    See OA_Tools.asm
; Purpose:    ObjAsm Tools.
; ==================================================================================================


; --------------------------------------------------------------------------------------------------
; Object:     OAT_About
; Purpose:    Custom about dialog.

Object OAT_About, , DialogModal
  RedefineMethod    Done
  RedefineMethod    Init,               POINTER, HWND
  RedefineMethod    OnInitDialog,       WPARAM, LPARAM

  VirtualEvent      OnCtlColorStatic,   WM_CTLCOLORSTATIC

  DefineVariable    hStcImage,          HWND,     0
  DefineVariable    hStcApplication,    HWND,     0
  DefineVariable    hStcVersion,        HWND,     0
  DefineVariable    hStcCopyright,      HWND,     0
  DefineVariable    hStcDescription,    HWND,     0
  DefineVariable    hLinkEmail,         HWND,     0
  DefineVariable    hLinkHomePage,      HWND,     0
  DefineVariable    hBmpApplication,    HBITMAP,  0
  DefineVariable    hFontApplication,   HFONT,    0
  DefineVariable    hFontVersion,       HFONT,    0
ObjectEnd


; ==================================================================================================

; --------------------------------------------------------------------------------------------------
; Method:     OAT_About.OnInitDialog
; Purpose:    Event procedure for WM_INITDIALOG message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = FALSE.

SetAboutItemString macro hItem:req, sID:req
  mov edx, edi
  %add edx, &sID
  invoke LoadString, hInstance, edx, xbx, lengthof cBuffer
  invoke SetWindowText, [xsi].hItem, xbx
endm

Method OAT_About.OnInitDialog, uses xbx xdi xsi, wParam:WPARAM, lParam:LPARAM
  local cBuffer[MAX_PATH]:CHR, LogFnt:LOGFONT

  SetObject xsi

  mov [xsi].hStcImage,       $invoke(GetDlgItem, [xsi].hWnd, IDC_STC_IMAGE)
  mov [xsi].hStcApplication, $invoke(GetDlgItem, [xsi].hWnd, IDC_STC_APPLICATION)
  mov [xsi].hStcVersion,     $invoke(GetDlgItem, [xsi].hWnd, IDC_STC_VERSION)
  mov [xsi].hStcCopyright,   $invoke(GetDlgItem, [xsi].hWnd, IDC_STC_COPYRIGHT)
  mov [xsi].hStcDescription, $invoke(GetDlgItem, [xsi].hWnd, IDC_STC_DESCRIPTION)
  mov [xsi].hLinkEmail,      $invoke(GetDlgItem, [xsi].hWnd, IDC_UDC_EMAIL)
  mov [xsi].hLinkHomePage,   $invoke(GetDlgItem, [xsi].hWnd, IDC_UDC_HOMEPAGE)

  invoke SendMessage, [xsi].hWnd, WM_GETFONT, 0, 0
  mov xcx, xax
  invoke GetObject, xcx, sizeof LogFnt, addr LogFnt
  mov LogFnt.lfWeight, FW_SEMIBOLD
  shl LogFnt.lfHeight, 1
  mov [xsi].hFontApplication, $invoke(CreateFontIndirect, addr LogFnt)
  invoke SendMessage, [xsi].hStcApplication, WM_SETFONT, xax, TRUE

  invoke SendMessage, [xsi].hWnd, WM_GETFONT, 0, 0
  mov xcx, xax
  invoke GetObject, xcx, sizeof LogFnt, addr LogFnt
  mov LogFnt.lfWeight, FW_SEMIBOLD
  mov [xsi].hFontVersion, $invoke(CreateFontIndirect, addr LogFnt)
  invoke SendMessage, [xsi].hStcVersion, WM_SETFONT, xax, TRUE

  ;Set strings in the selected language
  mov xcx, [xsi].pOwner                                 ;xcx -> Application
  mov edi, [xcx].$Obj(Application).dLanguage
  lea xbx, cBuffer

  mov edx, edi
  add edx, IDS_ABOUT_CAPTION
  invoke LoadString, hInstance, edx, xbx, lengthof cBuffer
  invoke SetWindowText, [xsi].hWnd, xbx

  SetAboutItemString hStcApplication, IDS_ABOUT_APPLICATION

  mov edx, edi
  add edx, IDS_ABOUT_VERSION
  invoke LoadString, hInstance, edx, xbx, lengthof cBuffer
  lea xbx, cBuffer
  lea xcx, [xbx + xax*sizeof(CHR)]
  invoke StrCopy, xcx, offset szAboutVersion
  invoke SetWindowText, [xsi].hStcVersion, xbx

  invoke SetWindowText, [xsi].hStcCopyright, offset szAboutCopyright

  SetAboutItemString hStcDescription, IDS_ABOUT_DESCRIPTION

  mov edx, edi
  add edx, IDS_ABOUT_EMAIL
  invoke LoadString, hInstance, edx, xbx, lengthof cBuffer
  invoke SendMessage, [xsi].hLinkEmail, WM_SETTEXT, 0, xbx

  mov edx, edi
  add edx, IDS_ABOUT_HOMEPAGE
  invoke LoadString, hInstance, edx, xbx, lengthof cBuffer
  invoke SendMessage, [xsi].hLinkHomePage, WM_SETTEXT, 0, xbx

  invoke LoadPngFromResource, $OfsCStr("PNG_APPLICATION")
  mov [xsi].hBmpApplication, xax
  invoke SendMessage, [xsi].hStcImage, STM_SETIMAGE, IMAGE_BITMAP, xax
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     OAT_About.Done
; Purpose:    Finalize the about object.
; Arguments:  None.
; Return:     Nothing.

Method OAT_About.Done, uses xsi
  SetObject xsi
  invoke DeleteObject, [xsi].hFontApplication
  invoke DeleteObject, [xsi].hFontVersion
  invoke DeleteObject, [xsi].hBmpApplication
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:       OAT_About.Init
; Purpose:      Initialize the about dialog using the "OAT_About" dialog resource.
; Arguments:    Arg1: -> Owner object.
;               Arg2: Parent window HANDLE.
; Return:       Nothing.

Method OAT_About.Init,, pOwner:POINTER, hParent:HWND
  SetObject xcx
  ACall xcx::OAT_About.Init, pOwner, hParent, IDD_DLG_ABOUT
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     OAT_About.OnCtlColorStatic
; Purpose:    Event procedure for WM_CTLCOLORSTATIC message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = 0.

Method OAT_About.OnCtlColorStatic, uses xsi, wParam:WPARAM, lParam:LPARAM
  local HC:HIGHCONTRAST, dColor1:DWORD, dColor2:DWORD

  SetObject xsi
  mov xax, lParam
  .if xax == [xsi].hLinkEmail || xax == [xsi].hLinkHomePage
    mov HC.cbSize, sizeof HIGHCONTRAST
    invoke SystemParametersInfo, SPI_GETHIGHCONTRAST, 0, addr HC, FALSE
    .ifBitSet HC.dwFlags, HCF_HIGHCONTRASTON
      invoke GetSysColor, COLOR_HOTLIGHT
      mov dColor1, eax
      mov dColor2, eax
    .else
      mov dColor1, $RGB(000,000,255)
      mov dColor2, $RGB(128,000,128)
    .endif
    invoke SendMessage, lParam, WM_GETOBJECTINSTANCE, 0, 0
    .if xax != 0
      m2m [xax].$Obj(Hyperlink).dColor1, dColor1, ecx 
      m2m [xax].$Obj(Hyperlink).dColor2, dColor2, ecx 
    .endif
  .endif
  xor eax, eax
MethodEnd
