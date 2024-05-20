;Include file created by h2inc+ version C.2.0 on (UTC) 20/05/2024 18:06:34
;(C) G. Friedrich April 2024
;Source file: d:\objasm\projects\x\h2inc+\h\um_10.0.22621.0\commdlg.h
;             Created on (UTC) 06/04/2024 06:15:52
;             Last modified on (UTC) 21/02/2024 18:17:20

include winapifamily.inc
;************************************************************************
;*                                                                       *
;*   commdlg.h -- This module defines the 32-Bit Common Dialog APIs      *
;*                                                                       *
;*   Copyright (c) Microsoft Corporation. All rights reserved.           *
;*                                                                       *
;************************************************************************
if _MSC_VER ge 1200
  ;* nonstandard extension : single line comment *
  ;* padding added after data member *
endif
ifndef _INC_COMMDLG
  _INC_COMMDLG equ <>
  if (WINVER ge 0500h)
    ifdef DEFINE_GUID
      ;  IPrintDialogCallback interface id used by PrintDlgEx.
      ;  {5852A2C3-6530-11D1-B6A3-0000F8757BF9}
      DEFINE_GUID IID_IPrintDialogCallback, 5852a2c3h, 6530h, 11d1h, 0b6h, 0a3h, 0h, 0h, 0f8h, 75h, 7bh, 0f9h
      ;  IPrintDialogServices interface id used by PrintDlgEx.
      ;  {509AAEDA-5639-11D1-B6A1-0000F8757BF9}
      DEFINE_GUID IID_IPrintDialogServices, 509aaedah, 5639h, 11d1h, 0b6h, 0a1h, 0h, 0h, 0f8h, 75h, 7bh, 0f9h
    endif
    ;* WINVER >= 0x0500 *
  endif
  ifndef GUID_DEFS_ONLY
    include prsht.inc
    if  not Defined(_WIN64)
      ;* Assume byte packing throughout *
      include pshpack1.inc
    endif
    ifdef __cplusplus
      ;[...]
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
      ; Define API decoration for direct importing of DLL references.
      ifndef WINCOMMDLGAPI
        if  not Defined(_COMDLG32_)
          WINCOMMDLGAPI equ <DECLSPEC_IMPORT>
        else
          WINCOMMDLGAPI equ <>
        endif
      endif
      ; WINCOMMDLGAPI
      if (WINVER ge 0400h)
        ifndef SNDMSG
          ifdef __cplusplus
            ;[...]
          else
            ifndef _MAC
              SNDMSG equ <SendMessage>
            else
              ;[...]
            endif
            ;* __cplusplus *
          endif
        endif
        ; ifndef SNDMSG
        ;* WINVER >= 0x0400 *
      endif
      ifdef _MAC
        ;[...]
      endif
      TYPE_LPOFNHOOKPROC typedef proto WIN_STD_CALL_CONV :HWND, :UINT, :WPARAM, :LPARAM
      LPOFNHOOKPROC typedef ptr TYPE_LPOFNHOOKPROC

      ifndef CDSIZEOF_STRUCT
        CDSIZEOF_STRUCT macro structname, member
          exitm <((((LPBYTE) (and ((structname *) 0) - member) - ((LPBYTE) ((structname *) 0)))) + sizeof(((structname *) 0) - member))>
        endm
      endif
      ; For compilers that don't support nameless unions
      ifndef DUMMYUNIONNAME
        ifdef NONAMELESSUNION
          DUMMYUNIONNAME equ <u>
        endif
        ; NONAMELESSUNION
      endif
      ; DUMMYUNIONNAME
      OPENFILENAME_NT4A struct
        lStructSize DWORD ?
        hwndOwner HWND ?
        hInstance HINSTANCE ?
        lpstrFilter =POINTER ?
        lpstrCustomFilter POINTER ?
        nMaxCustFilter DWORD ?
        nFilterIndex DWORD ?
        lpstrFile POINTER ?
        nMaxFile DWORD ?
        lpstrFileTitle POINTER ?
        nMaxFileTitle DWORD ?
        lpstrInitialDir =POINTER ?
        lpstrTitle =POINTER ?
        Flags DWORD ?
        nFileOffset WORD ?
        nFileExtension WORD ?
        lpstrDefExt =POINTER ?
        lCustData LPARAM ?
        lpfnHook LPOFNHOOKPROC ?
        lpTemplateName =POINTER ?
      OPENFILENAME_NT4A ends
      tagOFN_NT4A typedef OPENFILENAME_NT4A
      LPOPENFILENAME_NT4A typedef ptr OPENFILENAME_NT4A
      OPENFILENAME_NT4W struct
        lStructSize DWORD ?
        hwndOwner HWND ?
        hInstance HINSTANCE ?
        lpstrFilter =POINTER ?
        lpstrCustomFilter POINTER ?
        nMaxCustFilter DWORD ?
        nFilterIndex DWORD ?
        lpstrFile POINTER ?
        nMaxFile DWORD ?
        lpstrFileTitle POINTER ?
        nMaxFileTitle DWORD ?
        lpstrInitialDir =POINTER ?
        lpstrTitle =POINTER ?
        Flags DWORD ?
        nFileOffset WORD ?
        nFileExtension WORD ?
        lpstrDefExt =POINTER ?
        lCustData LPARAM ?
        lpfnHook LPOFNHOOKPROC ?
        lpTemplateName =POINTER ?
      OPENFILENAME_NT4W ends
      tagOFN_NT4W typedef OPENFILENAME_NT4W
      LPOPENFILENAME_NT4W typedef ptr OPENFILENAME_NT4W
      ifdef UNICODE
        OPENFILENAME_NT4 typedef OPENFILENAME_NT4W
        LPOPENFILENAME_NT4 typedef LPOPENFILENAME_NT4W
      else
        OPENFILENAME_NT4 typedef OPENFILENAME_NT4A
        LPOPENFILENAME_NT4 typedef LPOPENFILENAME_NT4A
      endif
      ; UNICODE
      OPENFILENAMEA struct
        ; (_WIN32_WINNT >= 0x0500)
        lStructSize DWORD ?
        hwndOwner HWND ?
        hInstance HINSTANCE ?
        lpstrFilter =POINTER ?
        lpstrCustomFilter POINTER ?
        nMaxCustFilter DWORD ?
        nFilterIndex DWORD ?
        lpstrFile POINTER ?
        nMaxFile DWORD ?
        lpstrFileTitle POINTER ?
        nMaxFileTitle DWORD ?
        lpstrInitialDir =POINTER ?
        lpstrTitle =POINTER ?
        Flags DWORD ?
        nFileOffset WORD ?
        nFileExtension WORD ?
        lpstrDefExt =POINTER ?
        lCustData LPARAM ?
        lpfnHook LPOFNHOOKPROC ?
        lpTemplateName =POINTER ?
        ifdef _MAC
          ;[...]
        endif
        if (_WIN32_WINNT ge 0500h)
          pvReserved POINTER ?
          dwReserved DWORD ?
          FlagsEx DWORD ?
        endif
        ; (_WIN32_WINNT >= 0x0500)
      OPENFILENAMEA ends
      tagOFNA typedef OPENFILENAMEA
      LPOPENFILENAMEA typedef ptr OPENFILENAMEA
      OPENFILENAMEW struct
        ; (_WIN32_WINNT >= 0x0500)
        lStructSize DWORD ?
        hwndOwner HWND ?
        hInstance HINSTANCE ?
        lpstrFilter =POINTER ?
        lpstrCustomFilter POINTER ?
        nMaxCustFilter DWORD ?
        nFilterIndex DWORD ?
        lpstrFile POINTER ?
        nMaxFile DWORD ?
        lpstrFileTitle POINTER ?
        nMaxFileTitle DWORD ?
        lpstrInitialDir =POINTER ?
        lpstrTitle =POINTER ?
        Flags DWORD ?
        nFileOffset WORD ?
        nFileExtension WORD ?
        lpstrDefExt =POINTER ?
        lCustData LPARAM ?
        lpfnHook LPOFNHOOKPROC ?
        lpTemplateName =POINTER ?
        ifdef _MAC
          ;[...]
        endif
        if (_WIN32_WINNT ge 0500h)
          pvReserved POINTER ?
          dwReserved DWORD ?
          FlagsEx DWORD ?
        endif
        ; (_WIN32_WINNT >= 0x0500)
      OPENFILENAMEW ends
      tagOFNW typedef OPENFILENAMEW
      LPOPENFILENAMEW typedef ptr OPENFILENAMEW
      ifdef UNICODE
        OPENFILENAME typedef OPENFILENAMEW
        LPOPENFILENAME typedef LPOPENFILENAMEW
      else
        OPENFILENAME typedef OPENFILENAMEA
        LPOPENFILENAME typedef LPOPENFILENAMEA
      endif
      ; UNICODE
      if (_WIN32_WINNT ge 0500h)
        OPENFILENAME_SIZE_VERSION_400A equ <CDSIZEOF_STRUCT(OPENFILENAMEA, lpTemplateName)>
        OPENFILENAME_SIZE_VERSION_400W equ <CDSIZEOF_STRUCT(OPENFILENAMEW, lpTemplateName)>
        ifdef UNICODE
          OPENFILENAME_SIZE_VERSION_400 equ <OPENFILENAME_SIZE_VERSION_400W>
        else
          OPENFILENAME_SIZE_VERSION_400 equ <OPENFILENAME_SIZE_VERSION_400A>
        endif
        ; !UNICODE
      endif
      ; (_WIN32_WINNT >= 0x0500)
      @DefProto DllImport, GetOpenFileNameA, WIN_STD_CALL_CONV,, <:LPOPENFILENAMEA>, 4
      @DefProto DllImport, GetOpenFileNameW, WIN_STD_CALL_CONV,, <:LPOPENFILENAMEW>, 4
      ifdef UNICODE
        GetOpenFileName equ <GetOpenFileNameW>
      else
        GetOpenFileName equ <GetOpenFileNameA>
      endif
      ; !UNICODE
      @DefProto DllImport, GetSaveFileNameA, WIN_STD_CALL_CONV,, <:LPOPENFILENAMEA>, 4
      @DefProto DllImport, GetSaveFileNameW, WIN_STD_CALL_CONV,, <:LPOPENFILENAMEW>, 4
      ifdef UNICODE
        GetSaveFileName equ <GetSaveFileNameW>
      else
        GetSaveFileName equ <GetSaveFileNameA>
      endif
      ; !UNICODE
      @DefProto DllImport, GetFileTitleA, WIN_STD_CALL_CONV,, <:LPCSTR, :LPSTR, :WORD>, 12
      @DefProto DllImport, GetFileTitleW, WIN_STD_CALL_CONV,, <:LPCWSTR, :LPWSTR, :WORD>, 12
      ifdef UNICODE
        GetFileTitle equ <GetFileTitleW>
      else
        GetFileTitle equ <GetFileTitleA>
      endif
      ; !UNICODE
      OFN_READONLY equ 00000001h
      OFN_OVERWRITEPROMPT equ 00000002h
      OFN_HIDEREADONLY equ 00000004h
      OFN_NOCHANGEDIR equ 00000008h
      OFN_SHOWHELP equ 00000010h
      OFN_ENABLEHOOK equ 00000020h
      OFN_ENABLETEMPLATE equ 00000040h
      OFN_ENABLETEMPLATEHANDLE equ 00000080h
      OFN_NOVALIDATE equ 00000100h
      OFN_ALLOWMULTISELECT equ 00000200h
      OFN_EXTENSIONDIFFERENT equ 00000400h
      OFN_PATHMUSTEXIST equ 00000800h
      OFN_FILEMUSTEXIST equ 00001000h
      OFN_CREATEPROMPT equ 00002000h
      OFN_SHAREAWARE equ 00004000h
      OFN_NOREADONLYRETURN equ 00008000h
      OFN_NOTESTFILECREATE equ 00010000h
      OFN_NONETWORKBUTTON equ 00020000h
      OFN_NOLONGNAMES equ 00040000h; force no long names for 4.x modules

      if (WINVER ge 0400h)
        OFN_EXPLORER equ 00080000h; new look commdlg

        OFN_NODEREFERENCELINKS equ 00100000h
        OFN_LONGNAMES equ 00200000h; force long names for 3.x modules

        ; OFN_ENABLEINCLUDENOTIFY and OFN_ENABLESIZING require
        ; Windows 2000 or higher to have any effect.
        OFN_ENABLEINCLUDENOTIFY equ 00400000h; send include message to callback

        OFN_ENABLESIZING equ 00800000h
        ;* WINVER >= 0x0400 *
      endif
      if (_WIN32_WINNT ge 0500h)
        OFN_DONTADDTORECENT equ 02000000h
        OFN_FORCESHOWHIDDEN equ 10000000h; Show All files including System and hidden files

      endif
      ; (_WIN32_WINNT >= 0x0500)
      ;FlagsEx Values
      if (_WIN32_WINNT ge 0500h)
        OFN_EX_NOPLACESBAR equ 00000001h
      endif
      ; (_WIN32_WINNT >= 0x0500)
      ; Return values for the registered message sent to the hook function
      ; when a sharing violation occurs.  OFN_SHAREFALLTHROUGH allows the
      ; filename to be accepted, OFN_SHARENOWARN rejects the name but puts
      ; up no warning (returned when the app has already put up a warning
      ; message), and OFN_SHAREWARN puts up the default warning message
      ; for sharing violations.
      ; Note:  Undefined return values map to OFN_SHAREWARN, but are
      ;        reserved for future use.
      OFN_SHAREFALLTHROUGH equ 2
      OFN_SHARENOWARN equ 1
      OFN_SHAREWARN equ 0
      TYPE_LPCCHOOKPROC typedef proto WIN_STD_CALL_CONV :HWND, :UINT, :WPARAM, :LPARAM
      LPCCHOOKPROC typedef ptr TYPE_LPCCHOOKPROC

      if (WINVER ge 0400h)
        ; Structure used for all file based OpenFileName notifications
        OFNOTIFYA struct
          hdr NMHDR <>
          lpOFN LPOPENFILENAMEA ?
          pszFile POINTER ?
          ; May be NULL
        OFNOTIFYA ends
        _OFNOTIFYA typedef OFNOTIFYA
        LPOFNOTIFYA typedef ptr OFNOTIFYA
        ; Structure used for all file based OpenFileName notifications
        OFNOTIFYW struct
          hdr NMHDR <>
          lpOFN LPOPENFILENAMEW ?
          pszFile POINTER ?
          ; May be NULL
        OFNOTIFYW ends
        _OFNOTIFYW typedef OFNOTIFYW
        LPOFNOTIFYW typedef ptr OFNOTIFYW
        ifdef UNICODE
          OFNOTIFY typedef OFNOTIFYW
          LPOFNOTIFY typedef LPOFNOTIFYW
        else
          OFNOTIFY typedef OFNOTIFYA
          LPOFNOTIFY typedef LPOFNOTIFYA
        endif
        ; UNICODE
        ; Structure used for all object based OpenFileName notifications
        OFNOTIFYEXA struct
          hdr NMHDR <>
          lpOFN LPOPENFILENAMEA ?
          psf POINTER ?
          pidl POINTER ?
          ; May be NULL
        OFNOTIFYEXA ends
        _OFNOTIFYEXA typedef OFNOTIFYEXA
        LPOFNOTIFYEXA typedef ptr OFNOTIFYEXA
        ; Structure used for all object based OpenFileName notifications
        OFNOTIFYEXW struct
          hdr NMHDR <>
          lpOFN LPOPENFILENAMEW ?
          psf POINTER ?
          pidl POINTER ?
          ; May be NULL
        OFNOTIFYEXW ends
        _OFNOTIFYEXW typedef OFNOTIFYEXW
        LPOFNOTIFYEXW typedef ptr OFNOTIFYEXW
        ifdef UNICODE
          OFNOTIFYEX typedef OFNOTIFYEXW
          LPOFNOTIFYEX typedef LPOFNOTIFYEXW
        else
          OFNOTIFYEX typedef OFNOTIFYEXA
          LPOFNOTIFYEX typedef LPOFNOTIFYEXA
        endif
        ; UNICODE
        CDN_FIRST equ (0 - 601)
        CDN_LAST equ (0 - 699)
        ; Notifications from Open or Save dialog
        CDN_INITDONE equ (CDN_FIRST - 0000h)
        CDN_SELCHANGE equ (CDN_FIRST - 0001h)
        CDN_FOLDERCHANGE equ (CDN_FIRST - 0002h)
        CDN_SHAREVIOLATION equ (CDN_FIRST - 0003h)
        CDN_HELP equ (CDN_FIRST - 0004h)
        CDN_FILEOK equ (CDN_FIRST - 0005h)
        CDN_TYPECHANGE equ (CDN_FIRST - 0006h)
        if (NTDDI_VERSION ge NTDDI_WIN2K)
          CDN_INCLUDEITEM equ (CDN_FIRST - 0007h)
        endif
        ; (NTDDI_VERSION >= NTDDI_WIN2K)
        CDM_FIRST equ (WM_USER + 100)
        CDM_LAST equ (WM_USER + 200)
        ; Messages to query information from the Open or Save dialogs
        ; lParam = pointer to text buffer that gets filled in
        ; wParam = max number of characters of the text buffer (including NULL)
        ; return = < 0 if error; number of characters needed (including NULL)
        CDM_GETSPEC equ (CDM_FIRST + 0000h)
        CommDlg_OpenSave_GetSpecA macro _hdlg, _psz, _cbmax
          exitm <SNDMSG (_hdlg, CDM_GETSPEC, (_cbmax), (_psz))>
        endm
        CommDlg_OpenSave_GetSpecW macro _hdlg, _psz, _cbmax
          exitm <SNDMSG (_hdlg, CDM_GETSPEC, (_cbmax), (_psz))>
        endm
        ifdef UNICODE
          CommDlg_OpenSave_GetSpec equ <CommDlg_OpenSave_GetSpecW>
        else
          CommDlg_OpenSave_GetSpec equ <CommDlg_OpenSave_GetSpecA>
        endif
        ; !UNICODE
        ; lParam = pointer to text buffer that gets filled in
        ; wParam = max number of characters of the text buffer (including NULL)
        ; return = < 0 if error; number of characters needed (including NULL)
        CDM_GETFILEPATH equ (CDM_FIRST + 0001h)
        CommDlg_OpenSave_GetFilePathA macro _hdlg, _psz, _cbmax
          exitm <SNDMSG (_hdlg, CDM_GETFILEPATH, (_cbmax), (_psz))>
        endm
        CommDlg_OpenSave_GetFilePathW macro _hdlg, _psz, _cbmax
          exitm <SNDMSG (_hdlg, CDM_GETFILEPATH, (_cbmax), (_psz))>
        endm
        ifdef UNICODE
          CommDlg_OpenSave_GetFilePath equ <CommDlg_OpenSave_GetFilePathW>
        else
          CommDlg_OpenSave_GetFilePath equ <CommDlg_OpenSave_GetFilePathA>
        endif
        ; !UNICODE
        ; lParam = pointer to text buffer that gets filled in
        ; wParam = max number of characters of the text buffer (including NULL)
        ; return = < 0 if error; number of characters needed (including NULL)
        CDM_GETFOLDERPATH equ (CDM_FIRST + 0002h)
        CommDlg_OpenSave_GetFolderPathA macro _hdlg, _psz, _cbmax
          exitm <SNDMSG (_hdlg, CDM_GETFOLDERPATH, (_cbmax), (_psz))>
        endm
        CommDlg_OpenSave_GetFolderPathW macro _hdlg, _psz, _cbmax
          exitm <SNDMSG (_hdlg, CDM_GETFOLDERPATH, (_cbmax), (_psz))>
        endm
        ifdef UNICODE
          CommDlg_OpenSave_GetFolderPath equ <CommDlg_OpenSave_GetFolderPathW>
        else
          CommDlg_OpenSave_GetFolderPath equ <CommDlg_OpenSave_GetFolderPathA>
        endif
        ; !UNICODE
        ; lParam = pointer to ITEMIDLIST buffer that gets filled in
        ; wParam = size of the ITEMIDLIST buffer
        ; return = < 0 if error; length of buffer needed
        CDM_GETFOLDERIDLIST equ (CDM_FIRST + 0003h)
        CommDlg_OpenSave_GetFolderIDList macro _hdlg, _pidl, _cbmax
          exitm <SNDMSG (_hdlg, CDM_GETFOLDERIDLIST, (_cbmax), (_pidl))>
        endm
        ; lParam = pointer to a string
        ; wParam = ID of control to change
        ; return = not used
        CDM_SETCONTROLTEXT equ (CDM_FIRST + 0004h)
        CommDlg_OpenSave_SetControlText macro _hdlg, _id, _text
          exitm <SNDMSG (_hdlg, CDM_SETCONTROLTEXT, (_id), (_text))>
        endm
        ; lParam = not used
        ; wParam = ID of control to change
        ; return = not used
        CDM_HIDECONTROL equ (CDM_FIRST + 0005h)
        CommDlg_OpenSave_HideControl macro _hdlg, _id
          exitm <SNDMSG (_hdlg, CDM_HIDECONTROL, (_id), 0)>
        endm
        ; lParam = pointer to default extension (no dot)
        ; wParam = not used
        ; return = not used
        CDM_SETDEFEXT equ (CDM_FIRST + 0006h)
        CommDlg_OpenSave_SetDefExt macro _hdlg, _pszext
          exitm <SNDMSG (_hdlg, CDM_SETDEFEXT, 0, (_pszext))>
        endm
        ;* WINVER >= 0x0400 *
      endif
      ifndef _MAC
        CHOOSECOLORA struct
          lStructSize DWORD ?
          hwndOwner HWND ?
          hInstance HWND ?
          rgbResult COLORREF ?
          lpCustColors POINTER ?
          Flags DWORD ?
          lCustData LPARAM ?
          lpfnHook LPCCHOOKPROC ?
          lpTemplateName =POINTER ?
        CHOOSECOLORA ends
        tagCHOOSECOLORA typedef CHOOSECOLORA
        LPCHOOSECOLORA typedef ptr CHOOSECOLORA
        CHOOSECOLORW struct
          lStructSize DWORD ?
          hwndOwner HWND ?
          hInstance HWND ?
          rgbResult COLORREF ?
          lpCustColors POINTER ?
          Flags DWORD ?
          lCustData LPARAM ?
          lpfnHook LPCCHOOKPROC ?
          lpTemplateName =POINTER ?
        CHOOSECOLORW ends
        tagCHOOSECOLORW typedef CHOOSECOLORW
        LPCHOOSECOLORW typedef ptr CHOOSECOLORW
        ifdef UNICODE
          CHOOSECOLOR typedef CHOOSECOLORW
          LPCHOOSECOLOR typedef LPCHOOSECOLORW
        else
          CHOOSECOLOR typedef CHOOSECOLORA
          LPCHOOSECOLOR typedef LPCHOOSECOLORA
        endif
        ; UNICODE
      else
        ;[...]
        ; UNICODE
      endif
      ;_MAC
      @DefProto DllImport, ChooseColorA, WIN_STD_CALL_CONV,, <:LPCHOOSECOLORA>, 4
      @DefProto DllImport, ChooseColorW, WIN_STD_CALL_CONV,, <:LPCHOOSECOLORW>, 4
      ifdef UNICODE
        ChooseColor equ <ChooseColorW>
      else
        ChooseColor equ <ChooseColorA>
      endif
      ; !UNICODE
      CC_RGBINIT equ 00000001h
      CC_FULLOPEN equ 00000002h
      CC_PREVENTFULLOPEN equ 00000004h
      CC_SHOWHELP equ 00000008h
      CC_ENABLEHOOK equ 00000010h
      CC_ENABLETEMPLATE equ 00000020h
      CC_ENABLETEMPLATEHANDLE equ 00000040h
      if (WINVER ge 0400h)
        CC_SOLIDCOLOR equ 00000080h
        CC_ANYCOLOR equ 00000100h
        ;* WINVER >= 0x0400 *
      endif
      TYPE_LPFRHOOKPROC typedef proto WIN_STD_CALL_CONV :HWND, :UINT, :WPARAM, :LPARAM
      LPFRHOOKPROC typedef ptr TYPE_LPFRHOOKPROC

      FINDREPLACEA struct
        lStructSize DWORD ?
        ; size of this struct 0x20
        hwndOwner HWND ?
        ; handle to owner's window
        hInstance HINSTANCE ?
        ; instance handle of.EXE that
        ;   contains cust. dlg. template
        Flags DWORD ?
        ; one or more of the FR_??
        lpstrFindWhat POINTER ?
        ; ptr. to search string
        lpstrReplaceWith POINTER ?
        ; ptr. to replace string
        wFindWhatLen WORD ?
        ; size of find buffer
        wReplaceWithLen WORD ?
        ; size of replace buffer
        lCustData LPARAM ?
        ; data passed to hook fn.
        lpfnHook LPFRHOOKPROC ?
        ; ptr. to hook fn. or NULL
        lpTemplateName =POINTER ?
        ; custom template name
      FINDREPLACEA ends
      tagFINDREPLACEA typedef FINDREPLACEA
      LPFINDREPLACEA typedef ptr FINDREPLACEA
      FINDREPLACEW struct
        lStructSize DWORD ?
        ; size of this struct 0x20
        hwndOwner HWND ?
        ; handle to owner's window
        hInstance HINSTANCE ?
        ; instance handle of.EXE that
        ;   contains cust. dlg. template
        Flags DWORD ?
        ; one or more of the FR_??
        lpstrFindWhat POINTER ?
        ; ptr. to search string
        lpstrReplaceWith POINTER ?
        ; ptr. to replace string
        wFindWhatLen WORD ?
        ; size of find buffer
        wReplaceWithLen WORD ?
        ; size of replace buffer
        lCustData LPARAM ?
        ; data passed to hook fn.
        lpfnHook LPFRHOOKPROC ?
        ; ptr. to hook fn. or NULL
        lpTemplateName =POINTER ?
        ; custom template name
      FINDREPLACEW ends
      tagFINDREPLACEW typedef FINDREPLACEW
      LPFINDREPLACEW typedef ptr FINDREPLACEW
      ifdef UNICODE
        FINDREPLACE typedef FINDREPLACEW
        LPFINDREPLACE typedef LPFINDREPLACEW
      else
        FINDREPLACE typedef FINDREPLACEA
        LPFINDREPLACE typedef LPFINDREPLACEA
      endif
      ; UNICODE
      FR_DOWN equ 00000001h
      FR_WHOLEWORD equ 00000002h
      FR_MATCHCASE equ 00000004h
      FR_FINDNEXT equ 00000008h
      FR_REPLACE equ 00000010h
      FR_REPLACEALL equ 00000020h
      FR_DIALOGTERM equ 00000040h
      FR_SHOWHELP equ 00000080h
      FR_ENABLEHOOK equ 00000100h
      FR_ENABLETEMPLATE equ 00000200h
      FR_NOUPDOWN equ 00000400h
      FR_NOMATCHCASE equ 00000800h
      FR_NOWHOLEWORD equ 00001000h
      FR_ENABLETEMPLATEHANDLE equ 00002000h
      FR_HIDEUPDOWN equ 00004000h
      FR_HIDEMATCHCASE equ 00008000h
      FR_HIDEWHOLEWORD equ 00010000h
      if (NTDDI_VERSION ge NTDDI_WIN2K)
        FR_RAW equ 00020000h
        if (NTDDI_VERSION ge NTDDI_WIN10_RS5)
          FR_SHOWWRAPAROUND equ 00040000h
          FR_NOWRAPAROUND equ 00080000h
          FR_WRAPAROUND equ 00100000h
        endif
        ; (NTDDI_VERSION >= NTDDI_WIN10_RS5)
        FR_MATCHDIAC equ 20000000h
        FR_MATCHKASHIDA equ 40000000h
        FR_MATCHALEFHAMZA equ 80000000h
      endif
      ; (NTDDI_VERSION >= NTDDI_WIN2K)
      @DefProto DllImport, FindTextA, WIN_STD_CALL_CONV,, <:LPFINDREPLACEA>, 4
      @DefProto DllImport, FindTextW, WIN_STD_CALL_CONV,, <:LPFINDREPLACEW>, 4
      ifdef UNICODE
        FindText equ <FindTextW>
      else
        FindText equ <FindTextA>
      endif
      ; !UNICODE
      ifndef _MAC
        @DefProto DllImport, ReplaceTextA, WIN_STD_CALL_CONV,, <:LPFINDREPLACEA>, 4
        @DefProto DllImport, ReplaceTextW, WIN_STD_CALL_CONV,, <:LPFINDREPLACEW>, 4
        ifdef UNICODE
          ReplaceText equ <ReplaceTextW>
        else
          ReplaceText equ <ReplaceTextA>
        endif
        ; !UNICODE
      else
        ;[...]
        ; !UNICODE
      endif
      FRM_FIRST equ (WM_USER + 100)
      FRM_LAST equ (WM_USER + 200)
      ; Messages to notify the Find or Replace dialogs of the result of a find or replace operation
      ; for accessibility purposes
      ; lParam = pointer to the FINDREPLACE structure that was sent to the client to begin the operation
      ; wParam = FR_* flags indicating which operations were completed
      ; return = not used
      FRM_SETOPERATIONRESULT equ (FRM_FIRST + 0000h)
      CommDlg_FindReplace_SendResult macro _hdlg, _flags, _fr
        exitm <SNDMSG (_hdlg, FRM_SETOPERATIONRESULT, (_flags), (_fr))>
      endm
      ; lParam = pointer to a string to be used to communicate the result of an operation to a user
      ; wParam = not used
      ; return = not used
      FRM_SETOPERATIONRESULTTEXT equ (FRM_FIRST + 0001h)
      CommDlg_FindReplace_SendCustomResult macro _hdlg, _psz
        exitm <SNDMSG (_hdlg, FRM_SETOPERATIONRESULTTEXT, 0, (_psz))>
      endm
      TYPE_LPCFHOOKPROC typedef proto WIN_STD_CALL_CONV :HWND, :UINT, :WPARAM, :LPARAM
      LPCFHOOKPROC typedef ptr TYPE_LPCFHOOKPROC

      CHOOSEFONTA struct
        lStructSize DWORD ?
        hwndOwner HWND ?
        ; caller's window handle
        hDC HDC ?
        ; printer DC/IC or NULL
        lpLogFont LPLOGFONTA ?
        ; ptr. to a LOGFONT struct
        iPointSize SDWORD ?
        ; 10 * size in points of selected font
        Flags DWORD ?
        ; enum. type flags
        rgbColors COLORREF ?
        ; returned text color
        lCustData LPARAM ?
        ; data passed to hook fn.
        lpfnHook LPCFHOOKPROC ?
        ; ptr. to hook function
        lpTemplateName =POINTER ?
        ; custom template name
        hInstance HINSTANCE ?
        ; instance handle of.EXE that
        ;   contains cust. dlg. template
        lpszStyle POINTER ?
        ; return the style field here
        ; must be LF_FACESIZE or bigger
        nFontType WORD ?
        ; same value reported to the EnumFonts
        ;   call back with the extra FONTTYPE_
        ;   bits added
        ___MISSING_ALIGNMENT__ WORD ?
        nSizeMin SDWORD ?
        ; minimum pt size allowed &
        nSizeMax SDWORD ?
        ; max pt size allowed if
        ;   CF_LIMITSIZE is used
      CHOOSEFONTA ends
      tagCHOOSEFONTA typedef CHOOSEFONTA
      CHOOSEFONTW struct
        lStructSize DWORD ?
        hwndOwner HWND ?
        ; caller's window handle
        hDC HDC ?
        ; printer DC/IC or NULL
        lpLogFont LPLOGFONTW ?
        ; ptr. to a LOGFONT struct
        iPointSize SDWORD ?
        ; 10 * size in points of selected font
        Flags DWORD ?
        ; enum. type flags
        rgbColors COLORREF ?
        ; returned text color
        lCustData LPARAM ?
        ; data passed to hook fn.
        lpfnHook LPCFHOOKPROC ?
        ; ptr. to hook function
        lpTemplateName =POINTER ?
        ; custom template name
        hInstance HINSTANCE ?
        ; instance handle of.EXE that
        ;   contains cust. dlg. template
        lpszStyle POINTER ?
        ; return the style field here
        ; must be LF_FACESIZE or bigger
        nFontType WORD ?
        ; same value reported to the EnumFonts
        ;   call back with the extra FONTTYPE_
        ;   bits added
        ___MISSING_ALIGNMENT__ WORD ?
        nSizeMin SDWORD ?
        ; minimum pt size allowed &
        nSizeMax SDWORD ?
        ; max pt size allowed if
        ;   CF_LIMITSIZE is used
      CHOOSEFONTW ends
      tagCHOOSEFONTW typedef CHOOSEFONTW
      ifdef UNICODE
        CHOOSEFONT typedef CHOOSEFONTW
      else
        CHOOSEFONT typedef CHOOSEFONTA
      endif
      ; UNICODE
      LPCHOOSEFONTA typedef ptr CHOOSEFONTA
      LPCHOOSEFONTW typedef ptr CHOOSEFONTW
      ifdef UNICODE
        LPCHOOSEFONT typedef LPCHOOSEFONTW
      else
        LPCHOOSEFONT typedef LPCHOOSEFONTA
      endif
      ; UNICODE
      PCCHOOSEFONTA typedef ptr CHOOSEFONTA
      PCCHOOSEFONTW typedef ptr CHOOSEFONTW
      ifdef UNICODE
        CHOOSEFONT typedef CHOOSEFONTW
        PCCHOOSEFONT typedef PCCHOOSEFONTW
      else
        CHOOSEFONT typedef CHOOSEFONTA
        PCCHOOSEFONT typedef PCCHOOSEFONTA
      endif
      ; UNICODE
      @DefProto DllImport, ChooseFontA, WIN_STD_CALL_CONV,, <:LPCHOOSEFONTA>, 4
      @DefProto DllImport, ChooseFontW, WIN_STD_CALL_CONV,, <:LPCHOOSEFONTW>, 4
      ifdef UNICODE
        ChooseFont equ <ChooseFontW>
      else
        ChooseFont equ <ChooseFontA>
      endif
      ; !UNICODE
      CF_SCREENFONTS equ 00000001h
      CF_PRINTERFONTS equ 00000002h
      CF_BOTH equ <(CF_SCREENFONTS or CF_PRINTERFONTS)>
      CF_SHOWHELP equ 00000004h
      CF_ENABLEHOOK equ 00000008h
      CF_ENABLETEMPLATE equ 00000010h
      CF_ENABLETEMPLATEHANDLE equ 00000020h
      CF_INITTOLOGFONTSTRUCT equ 00000040h
      CF_USESTYLE equ 00000080h
      CF_EFFECTS equ 00000100h
      CF_APPLY equ 00000200h
      CF_ANSIONLY equ 00000400h
      if (WINVER ge 0400h)
        CF_SCRIPTSONLY equ <CF_ANSIONLY>
        ;* WINVER >= 0x0400 *
      endif
      CF_NOVECTORFONTS equ 00000800h
      CF_NOOEMFONTS equ <CF_NOVECTORFONTS>
      CF_NOSIMULATIONS equ 00001000h
      CF_LIMITSIZE equ 00002000h
      CF_FIXEDPITCHONLY equ 00004000h
      CF_WYSIWYG equ 00008000h; must also have CF_SCREENFONTS & CF_PRINTERFONTS

      CF_FORCEFONTEXIST equ 00010000h
      CF_SCALABLEONLY equ 00020000h
      CF_TTONLY equ 00040000h
      CF_NOFACESEL equ 00080000h
      CF_NOSTYLESEL equ 00100000h
      CF_NOSIZESEL equ 00200000h
      if (WINVER ge 0400h)
        CF_SELECTSCRIPT equ 00400000h
        CF_NOSCRIPTSEL equ 00800000h
        CF_NOVERTFONTS equ 01000000h
        ;* WINVER >= 0x0400 *
      endif
      if (WINVER ge 0601h)
        CF_INACTIVEFONTS equ 02000000h
        ;* WINVER >= 0x0601 *
      endif
      ; these are extra nFontType bits that are added to what is returned to the
      ; EnumFonts callback routine
      SIMULATED_FONTTYPE equ 8000h
      PRINTER_FONTTYPE equ 4000h
      SCREEN_FONTTYPE equ 2000h
      BOLD_FONTTYPE equ 0100h
      ITALIC_FONTTYPE equ 0200h
      REGULAR_FONTTYPE equ 0400h
      ; EnumFonts callback routine only uses these bits, so we can use the rest
      ; #define RASTER_FONTTYPE     0x001
      ; #define DEVICE_FONTTYPE     0x002
      ; #define TRUETYPE_FONTTYPE   0x004
      if (NTDDI_VERSION ge NTDDI_WIN2K)
        PS_OPENTYPE_FONTTYPE equ 10000h
        TT_OPENTYPE_FONTTYPE equ 20000h
        TYPE1_FONTTYPE equ 40000h
      endif
      ; (NTDDI_VERSION >= NTDDI_WIN2K)
      if (WINVER ge 0601h)
        SYMBOL_FONTTYPE equ 80000h
        ;* WINVER >= 0x0601 *
      endif
      WM_CHOOSEFONT_GETLOGFONT equ (WM_USER + 1)
      if (NTDDI_VERSION ge NTDDI_WIN2K)
        WM_CHOOSEFONT_SETLOGFONT equ (WM_USER + 101)
        WM_CHOOSEFONT_SETFLAGS equ (WM_USER + 102)
      endif
      ; (NTDDI_VERSION >= NTDDI_WIN2K)
      ; strings used to obtain unique window message for communication
      ; between dialog and caller
      LBSELCHSTRINGA equ <"commdlg_LBSelChangedNotify">
      SHAREVISTRINGA equ <"commdlg_ShareViolation">
      FILEOKSTRINGA equ <"commdlg_FileNameOK">
      COLOROKSTRINGA equ <"commdlg_ColorOK">
      SETRGBSTRINGA equ <"commdlg_SetRGBColor">
      HELPMSGSTRINGA equ <"commdlg_help">
      FINDMSGSTRINGA equ <"commdlg_FindReplace">
      LBSELCHSTRINGW equ <L("commdlg_LBSelChangedNotify")>
      SHAREVISTRINGW equ <L("commdlg_ShareViolation")>
      FILEOKSTRINGW equ <L("commdlg_FileNameOK")>
      COLOROKSTRINGW equ <L("commdlg_ColorOK")>
      SETRGBSTRINGW equ <L("commdlg_SetRGBColor")>
      HELPMSGSTRINGW equ <L("commdlg_help")>
      FINDMSGSTRINGW equ <L("commdlg_FindReplace")>
      ifdef UNICODE
        LBSELCHSTRING equ <LBSELCHSTRINGW>
        SHAREVISTRING equ <SHAREVISTRINGW>
        FILEOKSTRING equ <FILEOKSTRINGW>
        COLOROKSTRING equ <COLOROKSTRINGW>
        SETRGBSTRING equ <SETRGBSTRINGW>
        HELPMSGSTRING equ <HELPMSGSTRINGW>
        FINDMSGSTRING equ <FINDMSGSTRINGW>
      else
        LBSELCHSTRING equ <LBSELCHSTRINGA>
        SHAREVISTRING equ <SHAREVISTRINGA>
        FILEOKSTRING equ <FILEOKSTRINGA>
        COLOROKSTRING equ <COLOROKSTRINGA>
        SETRGBSTRING equ <SETRGBSTRINGA>
        HELPMSGSTRING equ <HELPMSGSTRINGA>
        FINDMSGSTRING equ <FINDMSGSTRINGA>
      endif
      ; HIWORD values for lParam of commdlg_LBSelChangeNotify message
      CD_LBSELNOITEMS equ -1
      CD_LBSELCHANGE equ 0
      CD_LBSELSUB equ 1
      CD_LBSELADD equ 2
      TYPE_LPPRINTHOOKPROC typedef proto WIN_STD_CALL_CONV :HWND, :UINT, :WPARAM, :LPARAM
      LPPRINTHOOKPROC typedef ptr TYPE_LPPRINTHOOKPROC

      TYPE_LPSETUPHOOKPROC typedef proto WIN_STD_CALL_CONV :HWND, :UINT, :WPARAM, :LPARAM
      LPSETUPHOOKPROC typedef ptr TYPE_LPSETUPHOOKPROC

      PRINTDLGA struct
        lStructSize DWORD ?
        hwndOwner HWND ?
        hDevMode HGLOBAL ?
        hDevNames HGLOBAL ?
        hDC HDC ?
        Flags DWORD ?
        nFromPage WORD ?
        nToPage WORD ?
        nMinPage WORD ?
        nMaxPage WORD ?
        nCopies WORD ?
        hInstance HINSTANCE ?
        lCustData LPARAM ?
        lpfnPrintHook LPPRINTHOOKPROC ?
        lpfnSetupHook LPSETUPHOOKPROC ?
        lpPrintTemplateName =POINTER ?
        lpSetupTemplateName =POINTER ?
        hPrintTemplate HGLOBAL ?
        hSetupTemplate HGLOBAL ?
      PRINTDLGA ends
      tagPDA typedef PRINTDLGA
      LPPRINTDLGA typedef ptr PRINTDLGA
      PRINTDLGW struct
        lStructSize DWORD ?
        hwndOwner HWND ?
        hDevMode HGLOBAL ?
        hDevNames HGLOBAL ?
        hDC HDC ?
        Flags DWORD ?
        nFromPage WORD ?
        nToPage WORD ?
        nMinPage WORD ?
        nMaxPage WORD ?
        nCopies WORD ?
        hInstance HINSTANCE ?
        lCustData LPARAM ?
        lpfnPrintHook LPPRINTHOOKPROC ?
        lpfnSetupHook LPSETUPHOOKPROC ?
        lpPrintTemplateName =POINTER ?
        lpSetupTemplateName =POINTER ?
        hPrintTemplate HGLOBAL ?
        hSetupTemplate HGLOBAL ?
      PRINTDLGW ends
      tagPDW typedef PRINTDLGW
      LPPRINTDLGW typedef ptr PRINTDLGW
      ifdef UNICODE
        PRINTDLG typedef PRINTDLGW
        LPPRINTDLG typedef LPPRINTDLGW
      else
        PRINTDLG typedef PRINTDLGA
        LPPRINTDLG typedef LPPRINTDLGA
      endif
      ; UNICODE
      @DefProto DllImport, PrintDlgA, WIN_STD_CALL_CONV,, <:LPPRINTDLGA>, 4
      @DefProto DllImport, PrintDlgW, WIN_STD_CALL_CONV,, <:LPPRINTDLGW>, 4
      ifdef UNICODE
        PrintDlg equ <PrintDlgW>
      else
        PrintDlg equ <PrintDlgA>
      endif
      ; !UNICODE
      if (WINVER ge 0500h)
        ifdef STDMETHOD
          ;-------------------------------------------------------------------------
          ;  IPrintDialogCallback Interface
          ;  IPrintDialogCallback::InitDone()
          ;    This function is called by PrintDlgEx when the system has finished
          ;    initializing the main page of the print dialog.  This function
          ;    should return S_OK if it has processed the action or S_FALSE to let
          ;    PrintDlgEx perform the default action.
          ;  IPrintDialogCallback::SelectionChange()
          ;    This function is called by PrintDlgEx when a selection change occurs
          ;    in the list view that displays the currently installed printers.
          ;    This function should return S_OK if it has processed the action or
          ;    S_FALSE to let PrintDlgEx perform the default action.
          ;  IPrintDialogCallback::HandleMessage(hDlg, uMsg, wParam, lParam, pResult)
          ;    This function is called by PrintDlgEx when a message is sent to the
          ;    child window of the main page of the print dialog.  This function
          ;    should return S_OK if it has processed the action or S_FALSE to let
          ;    PrintDlgEx perform the default action.
          ;  IObjectWithSite::SetSite(punkSite)
          ;    IPrintDialogCallback usually paired with IObjectWithSite.
          ;    Provides the IUnknown pointer of the site to QI for the
          ;    IPrintDialogServices interface.
          ;-------------------------------------------------------------------------
          INTERFACE equ <IPrintDialogCallback>
          ??Interface equ <>
          DECLARE_INTERFACE_IID_(IPrintDialogCallback, IUnknown, "5852A2C3-6530-11D1-B6A3-0000F8757BF9")
            ; *** IUnknown methods ***
            STDMETHOD QueryInterface, :REFIID, :ptr ptr 
            STDMETHOD_ ULONG, AddRef
            STDMETHOD_ ULONG, Release
            ; *** IPrintDialogCallback methods ***
            STDMETHOD InitDone
            STDMETHOD SelectionChange
            STDMETHOD HandleMessage, :HWND, :DWORD, :WPARAM, :LPARAM, :ptr LRESULT
          DECLARE_INTERFACE_IID__END

          ;-------------------------------------------------------------------------
          ;  IPrintDialogServices Interface
          ;  IPrintDialogServices::GetCurrentDevMode(pDevMode, pcbSize)
          ;    Returns the DEVMODE structure for the currently selected printer.
          ;  IPrintDialogServices::GetCurrentPrinterName(pPrinterName, pcchSize)
          ;    Returns the printer name for the currently selected printer.
          ;  IPrintDialogServices::GetCurrentPortName(pPortName, pcchSize)
          ;    Returns the port name for the currently selected printer.
          ;-------------------------------------------------------------------------
          INTERFACE equ <IPrintDialogServices>
          ??Interface equ <>
          DECLARE_INTERFACE_IID_(IPrintDialogServices, IUnknown, "509AAEDA-5639-11D1-B6A1-0000F8757BF9")
            ; *** IUnknown methods ***
            STDMETHOD QueryInterface, :REFIID, :ptr ptr 
            STDMETHOD_ ULONG, AddRef
            STDMETHOD_ ULONG, Release
            ; *** IPrintDialogServices methods ***
            STDMETHOD GetCurrentDevMode, :LPDEVMODE, :ptr DWORD
            STDMETHOD GetCurrentPrinterName, :POINTER, :ptr DWORD
            STDMETHOD GetCurrentPortName, :POINTER, :ptr DWORD
          DECLARE_INTERFACE_IID__END

          ;  Page Range structure for PrintDlgEx.
          PRINTPAGERANGE struct
            nFromPage DWORD ?
            nToPage DWORD ?
          PRINTPAGERANGE ends
          tagPRINTPAGERANGE typedef PRINTPAGERANGE
          LPPRINTPAGERANGE typedef ptr PRINTPAGERANGE
          PCPRINTPAGERANGE typedef ptr PRINTPAGERANGE
          ;  PrintDlgEx structure.
          PRINTDLGEXA struct
            lStructSize DWORD ?
            ; size of structure in bytes
            hwndOwner HWND ?
            ; caller's window handle
            hDevMode HGLOBAL ?
            ; handle to DevMode
            hDevNames HGLOBAL ?
            ; handle to DevNames
            hDC HDC ?
            ; printer DC/IC or NULL
            Flags DWORD ?
            ; PD_ flags
            Flags2 DWORD ?
            ; reserved
            ExclusionFlags DWORD ?
            ; items to exclude from driver pages
            nPageRanges DWORD ?
            ; number of page ranges
            nMaxPageRanges DWORD ?
            ; max number of page ranges
            lpPageRanges LPPRINTPAGERANGE ?
            ; array of page ranges
            nMinPage DWORD ?
            ; min page number
            nMaxPage DWORD ?
            ; max page number
            nCopies DWORD ?
            ; number of copies
            hInstance HINSTANCE ?
            ; instance handle
            lpPrintTemplateName =POINTER ?
            ; template name for app specific area
            lpCallback LPUNKNOWN ?
            ; app callback interface
            nPropertyPages DWORD ?
            ; number of app property pages in lphPropertyPages
            lphPropertyPages POINTER ?
            ; array of app property page handles
            nStartPage DWORD ?
            ; start page id
            dwResultAction DWORD ?
            ; result action if S_OK is returned
          PRINTDLGEXA ends
          tagPDEXA typedef PRINTDLGEXA
          LPPRINTDLGEXA typedef ptr PRINTDLGEXA
          ;  PrintDlgEx structure.
          PRINTDLGEXW struct
            lStructSize DWORD ?
            ; size of structure in bytes
            hwndOwner HWND ?
            ; caller's window handle
            hDevMode HGLOBAL ?
            ; handle to DevMode
            hDevNames HGLOBAL ?
            ; handle to DevNames
            hDC HDC ?
            ; printer DC/IC or NULL
            Flags DWORD ?
            ; PD_ flags
            Flags2 DWORD ?
            ; reserved
            ExclusionFlags DWORD ?
            ; items to exclude from driver pages
            nPageRanges DWORD ?
            ; number of page ranges
            nMaxPageRanges DWORD ?
            ; max number of page ranges
            lpPageRanges LPPRINTPAGERANGE ?
            ; array of page ranges
            nMinPage DWORD ?
            ; min page number
            nMaxPage DWORD ?
            ; max page number
            nCopies DWORD ?
            ; number of copies
            hInstance HINSTANCE ?
            ; instance handle
            lpPrintTemplateName =POINTER ?
            ; template name for app specific area
            lpCallback LPUNKNOWN ?
            ; app callback interface
            nPropertyPages DWORD ?
            ; number of app property pages in lphPropertyPages
            lphPropertyPages POINTER ?
            ; array of app property page handles
            nStartPage DWORD ?
            ; start page id
            dwResultAction DWORD ?
            ; result action if S_OK is returned
          PRINTDLGEXW ends
          tagPDEXW typedef PRINTDLGEXW
          LPPRINTDLGEXW typedef ptr PRINTDLGEXW
          ifdef UNICODE
            PRINTDLGEX typedef PRINTDLGEXW
            LPPRINTDLGEX typedef LPPRINTDLGEXW
          else
            PRINTDLGEX typedef PRINTDLGEXA
            LPPRINTDLGEX typedef LPPRINTDLGEXA
          endif
          ; UNICODE
          @DefProto DllImport, PrintDlgExA, WIN_STD_CALL_CONV,, <:LPPRINTDLGEXA>, 4
          @DefProto DllImport, PrintDlgExW, WIN_STD_CALL_CONV,, <:LPPRINTDLGEXW>, 4
          ifdef UNICODE
            PrintDlgEx equ <PrintDlgExW>
          else
            PrintDlgEx equ <PrintDlgExA>
          endif
          ; !UNICODE
        endif
        ;* WINVER >= 0x0500 *
      endif
      ;  Flags for PrintDlg and PrintDlgEx.
      PD_ALLPAGES equ 00000000h
      PD_SELECTION equ 00000001h
      PD_PAGENUMS equ 00000002h
      PD_NOSELECTION equ 00000004h
      PD_NOPAGENUMS equ 00000008h
      PD_COLLATE equ 00000010h
      PD_PRINTTOFILE equ 00000020h
      PD_PRINTSETUP equ 00000040h
      PD_NOWARNING equ 00000080h
      PD_RETURNDC equ 00000100h
      PD_RETURNIC equ 00000200h
      PD_RETURNDEFAULT equ 00000400h
      PD_SHOWHELP equ 00000800h
      PD_ENABLEPRINTHOOK equ 00001000h
      PD_ENABLESETUPHOOK equ 00002000h
      PD_ENABLEPRINTTEMPLATE equ 00004000h
      PD_ENABLESETUPTEMPLATE equ 00008000h
      PD_ENABLEPRINTTEMPLATEHANDLE equ 00010000h
      PD_ENABLESETUPTEMPLATEHANDLE equ 00020000h
      PD_USEDEVMODECOPIES equ 00040000h
      PD_USEDEVMODECOPIESANDCOLLATE equ 00040000h
      PD_DISABLEPRINTTOFILE equ 00080000h
      PD_HIDEPRINTTOFILE equ 00100000h
      PD_NONETWORKBUTTON equ 00200000h
      if (WINVER ge 0500h)
        PD_CURRENTPAGE equ 00400000h
        PD_NOCURRENTPAGE equ 00800000h
        PD_EXCLUSIONFLAGS equ 01000000h
        PD_USELARGETEMPLATE equ 10000000h
        ;* WINVER >= 0x0500 *
      endif
      if (WINVER ge 0500h)
        ;  Exclusion flags for PrintDlgEx.
        PD_EXCL_COPIESANDCOLLATE equ <(DM_COPIES or DM_COLLATE)>
        ;  Define the start page for the print dialog when using PrintDlgEx.
        START_PAGE_GENERAL equ 0ffffffffh
        ;  Result action ids for PrintDlgEx.
        PD_RESULT_CANCEL equ 0
        PD_RESULT_PRINT equ 1
        PD_RESULT_APPLY equ 2
        ;* WINVER >= 0x0500 *
      endif
      ;  Device Names structure for PrintDlg and PrintDlgEx.
      DEVNAMES struct
        wDriverOffset WORD ?
        wDeviceOffset WORD ?
        wOutputOffset WORD ?
        wDefault WORD ?
      DEVNAMES ends
      tagDEVNAMES typedef DEVNAMES
      LPDEVNAMES typedef ptr DEVNAMES
      PCDEVNAMES typedef ptr DEVNAMES
      DN_DEFAULTPRN equ 0001h
      @DefProto DllImport, CommDlgExtendedError, WIN_STD_CALL_CONV,, <>, 0
      if (WINVER ge 0400h)
        WM_PSD_PAGESETUPDLG equ <(WM_USER)>
        WM_PSD_FULLPAGERECT equ (WM_USER + 1)
        WM_PSD_MINMARGINRECT equ (WM_USER + 2)
        WM_PSD_MARGINRECT equ (WM_USER + 3)
        WM_PSD_GREEKTEXTRECT equ (WM_USER + 4)
        WM_PSD_ENVSTAMPRECT equ (WM_USER + 5)
        WM_PSD_YAFULLPAGERECT equ (WM_USER + 6)
        TYPE_LPPAGEPAINTHOOK typedef proto WIN_STD_CALL_CONV :HWND, :UINT, :WPARAM, :LPARAM
        LPPAGEPAINTHOOK typedef ptr TYPE_LPPAGEPAINTHOOK

        TYPE_LPPAGESETUPHOOK typedef proto WIN_STD_CALL_CONV :HWND, :UINT, :WPARAM, :LPARAM
        LPPAGESETUPHOOK typedef ptr TYPE_LPPAGESETUPHOOK

        PAGESETUPDLGA struct
          lStructSize DWORD ?
          hwndOwner HWND ?
          hDevMode HGLOBAL ?
          hDevNames HGLOBAL ?
          Flags DWORD ?
          ptPaperSize POINT <>
          rtMinMargin RECT <>
          rtMargin RECT <>
          hInstance HINSTANCE ?
          lCustData LPARAM ?
          lpfnPageSetupHook LPPAGESETUPHOOK ?
          lpfnPagePaintHook LPPAGEPAINTHOOK ?
          lpPageSetupTemplateName =POINTER ?
          hPageSetupTemplate HGLOBAL ?
        PAGESETUPDLGA ends
        tagPSDA typedef PAGESETUPDLGA
        LPPAGESETUPDLGA typedef ptr PAGESETUPDLGA
        PAGESETUPDLGW struct
          lStructSize DWORD ?
          hwndOwner HWND ?
          hDevMode HGLOBAL ?
          hDevNames HGLOBAL ?
          Flags DWORD ?
          ptPaperSize POINT <>
          rtMinMargin RECT <>
          rtMargin RECT <>
          hInstance HINSTANCE ?
          lCustData LPARAM ?
          lpfnPageSetupHook LPPAGESETUPHOOK ?
          lpfnPagePaintHook LPPAGEPAINTHOOK ?
          lpPageSetupTemplateName =POINTER ?
          hPageSetupTemplate HGLOBAL ?
        PAGESETUPDLGW ends
        tagPSDW typedef PAGESETUPDLGW
        LPPAGESETUPDLGW typedef ptr PAGESETUPDLGW
        ifdef UNICODE
          PAGESETUPDLG typedef PAGESETUPDLGW
          LPPAGESETUPDLG typedef LPPAGESETUPDLGW
        else
          PAGESETUPDLG typedef PAGESETUPDLGA
          LPPAGESETUPDLG typedef LPPAGESETUPDLGA
        endif
        ; UNICODE
        @DefProto DllImport, PageSetupDlgA, WIN_STD_CALL_CONV,, <:LPPAGESETUPDLGA>, 4
        @DefProto DllImport, PageSetupDlgW, WIN_STD_CALL_CONV,, <:LPPAGESETUPDLGW>, 4
        ifdef UNICODE
          PageSetupDlg equ <PageSetupDlgW>
        else
          PageSetupDlg equ <PageSetupDlgA>
        endif
        ; !UNICODE
        PSD_DEFAULTMINMARGINS equ 00000000h; default (printer's)

        PSD_INWININIINTLMEASURE equ 00000000h; 1st of 4 possible

        PSD_MINMARGINS equ 00000001h; use caller's

        PSD_MARGINS equ 00000002h; use caller's

        PSD_INTHOUSANDTHSOFINCHES equ 00000004h; 2nd of 4 possible

        PSD_INHUNDREDTHSOFMILLIMETERS equ 00000008h; 3rd of 4 possible

        PSD_DISABLEMARGINS equ 00000010h
        PSD_DISABLEPRINTER equ 00000020h
        PSD_NOWARNING equ 00000080h; must be same as PD_*

        PSD_DISABLEORIENTATION equ 00000100h
        PSD_RETURNDEFAULT equ 00000400h; must be same as PD_*

        PSD_DISABLEPAPER equ 00000200h
        PSD_SHOWHELP equ 00000800h; must be same as PD_*

        PSD_ENABLEPAGESETUPHOOK equ 00002000h; must be same as PD_*

        PSD_ENABLEPAGESETUPTEMPLATE equ 00008000h; must be same as PD_*

        PSD_ENABLEPAGESETUPTEMPLATEHANDLE equ 00020000h; must be same as PD_*

        PSD_ENABLEPAGEPAINTHOOK equ 00040000h
        PSD_DISABLEPAGEPAINTING equ 00080000h
        PSD_NONETWORKBUTTON equ 00200000h; must be same as PD_*

        ;* WINVER >= 0x0400 *
      endif
      ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) *
    endif
    ;* RC complains about long symbols in #ifs *
    if  not Defined(RC_INVOKED)
      if Defined(ISOLATION_AWARE_ENABLED) and (ISOLATION_AWARE_ENABLED ne 0)
        ;[...]
      endif
      ;* RC *
    endif
    ifdef __cplusplus
      ;[...]
    endif
    if  not Defined(_WIN64)
      include poppack.inc
    endif
    ;* GUID_DEFS_ONLY *
  endif
  ;* !_INC_COMMDLG *
endif
if _MSC_VER ge 1200
endif
