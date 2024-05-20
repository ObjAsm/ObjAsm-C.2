;Include file created by h2inc+ version C.2.0 on (UTC) 20/05/2024 18:06:34
;(C) G. Friedrich April 2024
;Source file: d:\objasm\projects\x\h2inc+\h\um_10.0.22621.0\commctrl.h
;             Created on (UTC) 06/04/2024 06:15:52
;             Last modified on (UTC) 21/02/2024 18:17:18

;\*****************************************************************************
ifndef _INC_COMMCTRL
  _INC_COMMCTRL equ <>
  if Defined(_MSC_VER) and (_MSC_VER ge 1200)
    ;* nonstandard extension : single line comment *
    ;* nonstandard extension used : nameless struct/union *
    ;* padding added after data member *
  endif
  include winapifamily.inc
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    ifndef _HRESULT_DEFINED
      _HRESULT_DEFINED equ <>
      HRESULT typedef SDWORD
    endif
    ; !_HRESULT_DEFINED
    ifndef NOUSER
      ; Define API decoration for direct importing of DLL references.
      ifndef WINCOMMCTRLAPI
        if  not Defined(_COMCTL32_) and Defined(_WIN32)
          WINCOMMCTRLAPI equ <DECLSPEC_IMPORT>
        else
          WINCOMMCTRLAPI equ <>
        endif
      endif
      ; WINCOMMCTRLAPI
      ; For compilers that don't support nameless unions
      ifndef DUMMYUNIONNAME
        ifdef NONAMELESSUNION
          DUMMYUNIONNAME equ <u>
          DUMMYUNIONNAME2 equ <u2>
          DUMMYUNIONNAME3 equ <u3>
          DUMMYUNIONNAME4 equ <u4>
          DUMMYUNIONNAME5 equ <u5>
        else
          DUMMYUNIONNAME equ <>
          DUMMYUNIONNAME2 equ <>
          DUMMYUNIONNAME3 equ <>
          DUMMYUNIONNAME4 equ <>
          DUMMYUNIONNAME5 equ <>
        endif
      endif
      ; DUMMYUNIONNAME
      ifdef __cplusplus
        ;[...]
      endif
      ; Users of this header may define any number of these constants to avoid
      ; the definitions of each functional group.
      ;    NOTOOLBAR    Customizable bitmap-button toolbar control.
      ;    NOUPDOWN     Up and Down arrow increment/decrement control.
      ;    NOSTATUSBAR  Status bar control.
      ;    NOMENUHELP   APIs to help manage menus, especially with a status bar.
      ;    NOTRACKBAR   Customizable column-width tracking control.
      ;    NODRAGLIST   APIs to make a listbox source and sink drag&drop actions.
      ;    NOPROGRESS   Progress gas gauge.
      ;    NOHOTKEY     HotKey control
      ;    NOHEADER     Header bar control.
      ;    NOIMAGEAPIS  ImageList apis.
      ;    NOLISTVIEW   ListView control.
      ;    NOTREEVIEW   TreeView control.
      ;    NOTABCONTROL Tab control.
      ;    NOANIMATE    Animate control.
      ;    NOBUTTON     Button control.
      ;    NOSTATIC     Static control.
      ;    NOEDIT       Edit control.
      ;    NOLISTBOX    Listbox control.
      ;    NOCOMBOBOX   Combobox control.
      ;    NOSCROLLBAR  Scrollbar control.
      ;    NOTASKDIALOG Task Dialog.
      ;=============================================================================
      include prsht.inc
      ifndef SNDMSG
        ifdef __cplusplus
          ;[...]
        else
          ifndef _MAC
            SNDMSG equ <SendMessage>
          else
            ;[...]
          endif
          ;_MAC
        endif
      endif
      ; ifndef SNDMSG
      ifdef _MAC
        ;[...]
            ; _WLMDLL
          ; _WLM_NOFORCE_LIBS
        ; RC_INVOKED
      endif
      ;_MAC
      @DefProto DllImport, InitCommonControls, WIN_STD_CALL_CONV,, <>, 0
      INITCOMMONCONTROLSEX struct
        dwSize DWORD ?
        ; size of this structure
        dwICC DWORD ?
        ; flags indicating which classes to be initialized
      INITCOMMONCONTROLSEX ends
      tagINITCOMMONCONTROLSEX typedef INITCOMMONCONTROLSEX
      LPINITCOMMONCONTROLSEX typedef ptr INITCOMMONCONTROLSEX
      ICC_LISTVIEW_CLASSES equ 00000001h; listview, header

      ICC_TREEVIEW_CLASSES equ 00000002h; treeview, tooltips

      ICC_BAR_CLASSES equ 00000004h; toolbar, statusbar, trackbar, tooltips

      ICC_TAB_CLASSES equ 00000008h; tab, tooltips

      ICC_UPDOWN_CLASS equ 00000010h; updown

      ICC_PROGRESS_CLASS equ 00000020h; progress

      ICC_HOTKEY_CLASS equ 00000040h; hotkey

      ICC_ANIMATE_CLASS equ 00000080h; animate

      ICC_WIN95_CLASSES equ 000000FFh
      ICC_DATE_CLASSES equ 00000100h; month picker, date picker, time picker, updown

      ICC_USEREX_CLASSES equ 00000200h; comboex

      ICC_COOL_CLASSES equ 00000400h; rebar (coolbar) control

      ICC_INTERNET_CLASSES equ 00000800h
      ICC_PAGESCROLLER_CLASS equ 00001000h; page scroller

      ICC_NATIVEFNTCTL_CLASS equ 00002000h; native font control

      if (NTDDI_VERSION ge NTDDI_WINXP)
        ICC_STANDARD_CLASSES equ 00004000h
        ICC_LINK_CLASS equ 00008000h
      endif
      ; (NTDDI_VERSION >= NTDDI_WINXP)
      @DefProto DllImport, InitCommonControlsEx, WIN_STD_CALL_CONV,, <:ptr INITCOMMONCONTROLSEX>, 4
      ODT_HEADER equ 100
      ODT_TAB equ 101
      ODT_LISTVIEW equ 102
      ;====== Ranges for control message IDs =======================================
      LVM_FIRST equ 1000h; ListView messages

      TV_FIRST equ 1100h; TreeView messages

      HDM_FIRST equ 1200h; Header messages

      TCM_FIRST equ 1300h; Tab control messages

      PGM_FIRST equ 1400h; Pager control messages

      if (NTDDI_VERSION ge NTDDI_WINXP)
        ECM_FIRST equ 1500h; Edit control messages

        BCM_FIRST equ 1600h; Button control messages

        CBM_FIRST equ 1700h; Combobox control messages

      endif
      ; (NTDDI_VERSION >= NTDDI_WINXP)
      CCM_FIRST equ 2000h; Common control shared messages

      CCM_LAST equ (CCM_FIRST + 200h)
      CCM_SETBKCOLOR equ (CCM_FIRST + 1); lParam is bkColor

      COLORSCHEME struct
        dwSize DWORD ?
        clrBtnHighlight COLORREF ?
        ; highlight color
        clrBtnShadow COLORREF ?
        ; shadow color
      COLORSCHEME ends
      tagCOLORSCHEME typedef COLORSCHEME
      LPCOLORSCHEME typedef ptr COLORSCHEME
      CCM_SETCOLORSCHEME equ (CCM_FIRST + 2); lParam is color scheme

      CCM_GETCOLORSCHEME equ (CCM_FIRST + 3); fills in COLORSCHEME pointed to by lParam

      CCM_GETDROPTARGET equ (CCM_FIRST + 4)
      CCM_SETUNICODEFORMAT equ (CCM_FIRST + 5)
      CCM_GETUNICODEFORMAT equ (CCM_FIRST + 6)
      if (NTDDI_VERSION ge NTDDI_WINXP)
        COMCTL32_VERSION equ 6
      else
        COMCTL32_VERSION equ 5
      endif
      CCM_SETVERSION equ (CCM_FIRST + 7h)
      CCM_GETVERSION equ (CCM_FIRST + 8h)
      CCM_SETNOTIFYWINDOW equ (CCM_FIRST + 9h); wParam == hwndParent.

      if (NTDDI_VERSION ge NTDDI_WINXP)
        CCM_SETWINDOWTHEME equ (CCM_FIRST + 0bh)
        CCM_DPISCALE equ (CCM_FIRST + 0ch); wParam == Awareness

      endif
      ; for tooltips
      INFOTIPSIZE equ 1024
      ;====== WM_NOTIFY Macros =====================================================
      HANDLE_WM_NOTIFY macro hwnd, wParam, lParam, fn
        exitm <(fn) ((hwnd), (wParam), (NMHDR *) (lParam))>
      endm
      FORWARD_WM_NOTIFY macro hwnd, idFrom, pnmhdr, fn
        exitm <(fn) ((hwnd), WM_NOTIFY, (idFrom), (NMHDR *) (pnmhdr))>
      endm
      ;====== Generic WM_NOTIFY notification codes =================================
      NM_OUTOFMEMORY equ (NM_FIRST - 1)
      NM_CLICK equ (NM_FIRST - 2); uses NMCLICK struct

      NM_DBLCLK equ (NM_FIRST - 3)
      NM_RETURN equ (NM_FIRST - 4)
      NM_RCLICK equ (NM_FIRST - 5); uses NMCLICK struct

      NM_RDBLCLK equ (NM_FIRST - 6)
      NM_SETFOCUS equ (NM_FIRST - 7)
      NM_KILLFOCUS equ (NM_FIRST - 8)
      NM_CUSTOMDRAW equ (NM_FIRST - 12)
      NM_HOVER equ (NM_FIRST - 13)
      NM_NCHITTEST equ (NM_FIRST - 14); uses NMMOUSE struct

      NM_KEYDOWN equ (NM_FIRST - 15); uses NMKEY struct

      NM_RELEASEDCAPTURE equ (NM_FIRST - 16)
      NM_SETCURSOR equ (NM_FIRST - 17); uses NMMOUSE struct

      NM_CHAR equ (NM_FIRST - 18); uses NMCHAR struct

      NM_TOOLTIPSCREATED equ (NM_FIRST - 19); notify of when the tooltips window is create

      NM_LDOWN equ (NM_FIRST - 20)
      NM_RDOWN equ (NM_FIRST - 21)
      NM_THEMECHANGED equ (NM_FIRST - 22)
      if (NTDDI_VERSION ge NTDDI_VISTA)
        NM_FONTCHANGED equ (NM_FIRST - 23)
        NM_CUSTOMTEXT equ (NM_FIRST - 24); uses NMCUSTOMTEXT struct

        NM_TVSTATEIMAGECHANGING equ (NM_FIRST - 24); uses NMTVSTATEIMAGECHANGING struct, defined after HTREEITEM

      endif
      ifndef CCSIZEOF_STRUCT
        CCSIZEOF_STRUCT macro structname, member
          exitm <((((LPBYTE) (and ((structname *) 0) - member) - ((LPBYTE) ((structname *) 0)))) + sizeof(((structname *) 0) - member))>
        endm
      endif
      ;====== Generic WM_NOTIFY notification structures ============================
      NMTOOLTIPSCREATED struct
        hdr NMHDR <>
        hwndToolTips HWND ?
      NMTOOLTIPSCREATED ends
      tagNMTOOLTIPSCREATED typedef NMTOOLTIPSCREATED
      LPNMTOOLTIPSCREATED typedef ptr NMTOOLTIPSCREATED
      NMMOUSE struct
        hdr NMHDR <>
        dwItemSpec XWORD ?
        dwItemData XWORD ?
        pt POINT <>
        dwHitInfo LPARAM ?
        ; any specifics about where on the item or control the mouse is
      NMMOUSE ends
      tagNMMOUSE typedef NMMOUSE
      LPNMMOUSE typedef ptr NMMOUSE
      NMCLICK typedef NMMOUSE
      LPNMCLICK typedef LPNMMOUSE
      ; Generic structure to request an object of a specific type.
      NMOBJECTNOTIFY struct
        hdr NMHDR <>
        iItem SDWORD ?
        ifdef __IID_DEFINED__
          piid POINTER ?
        else
          piid POINTER ?
        endif
        pObject POINTER ?
        hResult HRESULT ?
        dwFlags DWORD ?
        ; control specific flags (hints as to where in iItem it hit)
      NMOBJECTNOTIFY ends
      tagNMOBJECTNOTIFY typedef NMOBJECTNOTIFY
      LPNMOBJECTNOTIFY typedef ptr NMOBJECTNOTIFY
      ; Generic structure for a key
      NMKEY struct
        hdr NMHDR <>
        nVKey DWORD ?
        uFlags DWORD ?
      NMKEY ends
      tagNMKEY typedef NMKEY
      LPNMKEY typedef ptr NMKEY
      ; Generic structure for a character
      NMCHAR struct
        hdr NMHDR <>
        ch_ DWORD ?
        dwItemPrev DWORD ?
        ; Item previously selected
        dwItemNext DWORD ?
        ; Item to be selected
      NMCHAR ends
      tagNMCHAR typedef NMCHAR
      LPNMCHAR typedef ptr NMCHAR
      if (_WIN32_IE ge 0600h)
        NMCUSTOMTEXT struct
          hdr NMHDR <>
          hDC HDC ?
          lpString =POINTER ?
          nCount SDWORD ?
          lpRect LPRECT ?
          uFormat DWORD ?
          fLink DWORD ?
        NMCUSTOMTEXT ends
        tagNMCUSTOMTEXT typedef NMCUSTOMTEXT
        LPNMCUSTOMTEXT typedef ptr NMCUSTOMTEXT
      endif
      ; _WIN32_IE >= 0x0600
      ;====== WM_NOTIFY codes (NMHDR.code values) ==================================
      NM_FIRST equ (0 - 0); generic to all controls

      NM_LAST equ (0 - 99)
      LVN_FIRST equ (0 - 100); listview

      LVN_LAST equ (0 - 199)
      ; Property sheet reserved      (0U-200U) -  (0U-299U) - see prsht.h
      HDN_FIRST equ (0 - 300); header

      HDN_LAST equ (0 - 399)
      TVN_FIRST equ (0 - 400); treeview

      TVN_LAST equ (0 - 499)
      TTN_FIRST equ (0 - 520); tooltips

      TTN_LAST equ (0 - 549)
      TCN_FIRST equ (0 - 550); tab control

      TCN_LAST equ (0 - 580)
      ; Shell reserved               (0U-580U) -  (0U-589U)
      CDN_FIRST equ (0 - 601); common dialog (new)

      CDN_LAST equ (0 - 699)
      TBN_FIRST equ (0 - 700); toolbar

      TBN_LAST equ (0 - 720)
      UDN_FIRST equ (0 - 721); updown

      UDN_LAST equ (0 - 729)
      DTN_FIRST equ (0 - 740); datetimepick

      DTN_LAST equ (0 - 745); DTN_FIRST - 5

      MCN_FIRST equ (0 - 746); monthcal

      MCN_LAST equ (0 - 752); MCN_FIRST - 6

      DTN_FIRST2 equ (0 - 753); datetimepick2

      DTN_LAST2 equ (0 - 799)
      CBEN_FIRST equ (0 - 800); combo box ex

      CBEN_LAST equ (0 - 830)
      RBN_FIRST equ (0 - 831); rebar

      RBN_LAST equ (0 - 859)
      IPN_FIRST equ (0 - 860); internet address

      IPN_LAST equ (0 - 879); internet address

      SBN_FIRST equ (0 - 880); status bar

      SBN_LAST equ (0 - 899)
      PGN_FIRST equ (0 - 900); Pager Control

      PGN_LAST equ (0 - 950)
      ifndef WMN_FIRST
        WMN_FIRST equ (0 - 1000)
        WMN_LAST equ (0 - 1200)
      endif
      if (NTDDI_VERSION ge NTDDI_WINXP)
        BCN_FIRST equ (0 - 1250)
        BCN_LAST equ (0 - 1350)
      endif
      if (NTDDI_VERSION ge NTDDI_VISTA)
        TRBN_FIRST equ (0 - 1501); trackbar

        TRBN_LAST equ (0 - 1519)
      endif
      if (NTDDI_VERSION ge NTDDI_WIN10_RS5)
        EN_FIRST equ (0 - 1520); edit control

        EN_LAST equ (0 - 1540)
      endif
      MSGF_COMMCTRL_BEGINDRAG equ 4200h
      MSGF_COMMCTRL_SIZEHEADER equ 4201h
      MSGF_COMMCTRL_DRAGSELECT equ 4202h
      MSGF_COMMCTRL_TOOLBARCUST equ 4203h
      ;==================== CUSTOM DRAW ==========================================
      ; custom draw return flags
      ; values under 0x00010000 are reserved for global custom draw values.
      ; above that are for specific controls
      CDRF_DODEFAULT equ 00000000h
      CDRF_NEWFONT equ 00000002h
      CDRF_SKIPDEFAULT equ 00000004h
      CDRF_DOERASE equ 00000008h; draw the background

      CDRF_SKIPPOSTPAINT equ 00000100h; don't draw the focus rect

      CDRF_NOTIFYPOSTPAINT equ 00000010h
      CDRF_NOTIFYITEMDRAW equ 00000020h
      CDRF_NOTIFYSUBITEMDRAW equ 00000020h; flags are the same, we can distinguish by context

      CDRF_NOTIFYPOSTERASE equ 00000040h
      ; drawstage flags
      ; values under 0x00010000 are reserved for global custom draw values.
      ; above that are for specific controls
      CDDS_PREPAINT equ 00000001h
      CDDS_POSTPAINT equ 00000002h
      CDDS_PREERASE equ 00000003h
      CDDS_POSTERASE equ 00000004h
      ; the 0x000010000 bit means it's individual item specific
      CDDS_ITEM equ 00010000h
      CDDS_ITEMPREPAINT equ <(CDDS_ITEM or CDDS_PREPAINT)>
      CDDS_ITEMPOSTPAINT equ <(CDDS_ITEM or CDDS_POSTPAINT)>
      CDDS_ITEMPREERASE equ <(CDDS_ITEM or CDDS_PREERASE)>
      CDDS_ITEMPOSTERASE equ <(CDDS_ITEM or CDDS_POSTERASE)>
      CDDS_SUBITEM equ 00020000h
      ; itemState flags
      CDIS_SELECTED equ 0001h
      CDIS_GRAYED equ 0002h
      CDIS_DISABLED equ 0004h
      CDIS_CHECKED equ 0008h
      CDIS_FOCUS equ 0010h
      CDIS_DEFAULT equ 0020h
      CDIS_HOT equ 0040h
      CDIS_MARKED equ 0080h
      CDIS_INDETERMINATE equ 0100h
      if (NTDDI_VERSION ge NTDDI_WINXP)
        CDIS_SHOWKEYBOARDCUES equ 0200h
      endif
      if (NTDDI_VERSION ge NTDDI_VISTA)
        CDIS_NEARHOT equ 0400h
        CDIS_OTHERSIDEHOT equ 0800h
        CDIS_DROPHILITED equ 1000h
      endif
      NMCUSTOMDRAW struct
        hdr NMHDR <>
        dwDrawStage DWORD ?
        hdc HDC ?
        rc RECT <>
        dwItemSpec XWORD ?
        ; this is control specific, but it's how to specify an item.  valid only with CDDS_ITEM bit set
        uItemState DWORD ?
        lItemlParam LPARAM ?
      NMCUSTOMDRAW ends
      tagNMCUSTOMDRAWINFO typedef NMCUSTOMDRAW
      LPNMCUSTOMDRAW typedef ptr NMCUSTOMDRAW
      NMTTCUSTOMDRAW struct
        nmcd NMCUSTOMDRAW <>
        uDrawFlags DWORD ?
      NMTTCUSTOMDRAW ends
      tagNMTTCUSTOMDRAW typedef NMTTCUSTOMDRAW
      LPNMTTCUSTOMDRAW typedef ptr NMTTCUSTOMDRAW
      NMCUSTOMSPLITRECTINFO struct
        hdr NMHDR <>
        rcClient RECT <>
        rcButton RECT <>
        rcSplit RECT <>
      NMCUSTOMSPLITRECTINFO ends
      tagNMCUSTOMSPLITRECTINFO typedef NMCUSTOMSPLITRECTINFO
      LPNMCUSTOMSPLITRECTINFO typedef ptr NMCUSTOMSPLITRECTINFO
      NM_GETCUSTOMSPLITRECT equ (BCN_FIRST + 0003h)
      ;====== IMAGE APIS ===========================================================
      ifndef NOIMAGEAPIS
        CLR_NONE equ 0FFFFFFFFh
        CLR_DEFAULT equ 0FF000000h
        ifndef HIMAGELIST
          HIMAGELIST typedef ptr _IMAGELIST
        endif
        ifndef IMAGELISTDRAWPARAMS
          IMAGELISTDRAWPARAMS struct
            cbSize DWORD ?
            himl HIMAGELIST ?
            i SDWORD ?
            hdcDst HDC ?
            x SDWORD ?
            y SDWORD ?
            cx_ SDWORD ?
            cy SDWORD ?
            xBitmap SDWORD ?
            ; x offest from the upperleft of bitmap
            yBitmap SDWORD ?
            ; y offset from the upperleft of bitmap
            rgbBk COLORREF ?
            rgbFg COLORREF ?
            fStyle DWORD ?
            dwRop DWORD ?
            if (_WIN32_IE ge 0501h)
              fState DWORD ?
              Frame_ DWORD ?
              crEffect COLORREF ?
            endif
          IMAGELISTDRAWPARAMS ends
          _IMAGELISTDRAWPARAMS typedef IMAGELISTDRAWPARAMS
          LPIMAGELISTDRAWPARAMS typedef ptr IMAGELISTDRAWPARAMS
          IMAGELISTDRAWPARAMS_V3_SIZE equ <CCSIZEOF_STRUCT(IMAGELISTDRAWPARAMS, dwRop)>
        endif
        ILC_MASK equ 00000001h
        ILC_COLOR equ 00000000h
        ILC_COLORDDB equ 000000FEh
        ILC_COLOR4 equ 00000004h
        ILC_COLOR8 equ 00000008h
        ILC_COLOR16 equ 00000010h
        ILC_COLOR24 equ 00000018h
        ILC_COLOR32 equ 00000020h
        ILC_PALETTE equ 00000800h; (not implemented)

        if (NTDDI_VERSION ge NTDDI_WINXP)
          ILC_MIRROR equ 00002000h; Mirror the icons contained, if the process is mirrored

          ILC_PERITEMMIRROR equ 00008000h; Causes the mirroring code to mirror each item when inserting a set of images, verses the whole strip

        endif
        if (NTDDI_VERSION ge NTDDI_VISTA)
          ILC_ORIGINALSIZE equ 00010000h; Imagelist should accept smaller than set images and apply OriginalSize based on image added

          ILC_HIGHQUALITYSCALE equ 00020000h; Imagelist should enable use of the high quality scaler.

        endif
        @DefProto DllImport, ImageList_Create, WIN_STD_CALL_CONV,, <:SDWORD, :SDWORD, :UINT, :SDWORD, :SDWORD>, 20
        @DefProto DllImport, ImageList_Destroy, WIN_STD_CALL_CONV,, <:HIMAGELIST>, 4
        @DefProto DllImport, ImageList_GetImageCount, WIN_STD_CALL_CONV,, <:HIMAGELIST>, 4
        @DefProto DllImport, ImageList_SetImageCount, WIN_STD_CALL_CONV,, <:HIMAGELIST, :UINT>, 8
        @DefProto DllImport, ImageList_Add, WIN_STD_CALL_CONV,, <:HIMAGELIST, :HBITMAP, :HBITMAP>, 12
        @DefProto DllImport, ImageList_ReplaceIcon, WIN_STD_CALL_CONV,, <:HIMAGELIST, :SDWORD, :HICON>, 12
        @DefProto DllImport, ImageList_SetBkColor, WIN_STD_CALL_CONV,, <:HIMAGELIST, :COLORREF>, 8
        @DefProto DllImport, ImageList_GetBkColor, WIN_STD_CALL_CONV,, <:HIMAGELIST>, 4
        @DefProto DllImport, ImageList_SetOverlayImage, WIN_STD_CALL_CONV,, <:HIMAGELIST, :SDWORD, :SDWORD>, 12
        ImageList_AddIcon macro himl, hicon
          exitm <ImageList_ReplaceIcon (himl, - 1, hicon)>
        endm
        ILD_NORMAL equ 00000000h
        ILD_TRANSPARENT equ 00000001h
        ILD_MASK equ 00000010h
        ILD_IMAGE equ 00000020h
        ILD_ROP equ 00000040h
        ILD_BLEND25 equ 00000002h
        ILD_BLEND50 equ 00000004h
        ILD_OVERLAYMASK equ 00000F00h
        INDEXTOOVERLAYMASK macro i
          exitm <((i) shl 8)>
        endm
        ILD_PRESERVEALPHA equ 00001000h; This preserves the alpha channel in dest

        ILD_SCALE equ 00002000h; Causes the image to be scaled to cx, cy instead of clipped

        ILD_DPISCALE equ 00004000h
        if (NTDDI_VERSION ge NTDDI_VISTA)
          ILD_ASYNC equ 00008000h
        endif
        ILD_SELECTED equ <ILD_BLEND50>
        ILD_FOCUS equ <ILD_BLEND25>
        ILD_BLEND equ <ILD_BLEND50>
        CLR_HILIGHT equ <CLR_DEFAULT>
        ILS_NORMAL equ 00000000h
        ILS_GLOW equ 00000001h
        ILS_SHADOW equ 00000002h
        ILS_SATURATE equ 00000004h
        ILS_ALPHA equ 00000008h
        if (NTDDI_VERSION ge NTDDI_VISTA)
          ILGT_NORMAL equ 00000000h
          ILGT_ASYNC equ 00000001h
        endif
        @DefProto DllImport, ImageList_Draw, WIN_STD_CALL_CONV,, <:HIMAGELIST, :SDWORD, :HDC, :SDWORD, :SDWORD, :UINT>, 24
        ifdef _WIN32
          if (NTDDI_VERSION ge NTDDI_VISTA)
            HBITMAP_CALLBACK equ (- 1); only for SparseImageList

          endif
          @DefProto DllImport, ImageList_Replace, WIN_STD_CALL_CONV,, <:HIMAGELIST, :SDWORD, :HBITMAP, :HBITMAP>, 16
          @DefProto DllImport, ImageList_AddMasked, WIN_STD_CALL_CONV,, <:HIMAGELIST, :HBITMAP, :COLORREF>, 12
          @DefProto DllImport, ImageList_DrawEx, WIN_STD_CALL_CONV,, <:HIMAGELIST, :SDWORD, :HDC, :SDWORD, :SDWORD, :SDWORD, :SDWORD, :COLORREF, :COLORREF, :UINT>, 40
          @DefProto DllImport, ImageList_DrawIndirect, WIN_STD_CALL_CONV,, <:ptr IMAGELISTDRAWPARAMS>, 4
          @DefProto DllImport, ImageList_Remove, WIN_STD_CALL_CONV,, <:HIMAGELIST, :SDWORD>, 8
          @DefProto DllImport, ImageList_GetIcon, WIN_STD_CALL_CONV,, <:HIMAGELIST, :SDWORD, :UINT>, 12
          @DefProto DllImport, ImageList_LoadImageA, WIN_STD_CALL_CONV,, <:HINSTANCE, :LPCSTR, :SDWORD, :SDWORD, :COLORREF, :UINT, :UINT>, 28
          @DefProto DllImport, ImageList_LoadImageW, WIN_STD_CALL_CONV,, <:HINSTANCE, :LPCWSTR, :SDWORD, :SDWORD, :COLORREF, :UINT, :UINT>, 28
          ifdef UNICODE
            ImageList_LoadImage equ <ImageList_LoadImageW>
          else
            ImageList_LoadImage equ <ImageList_LoadImageA>
          endif
          ILCF_MOVE equ (00000000h)
          ILCF_SWAP equ (00000001h)
          @DefProto DllImport, ImageList_Copy, WIN_STD_CALL_CONV,, <:HIMAGELIST, :SDWORD, :HIMAGELIST, :SDWORD, :UINT>, 20
          @DefProto DllImport, ImageList_BeginDrag, WIN_STD_CALL_CONV,, <:HIMAGELIST, :SDWORD, :SDWORD, :SDWORD>, 16
          @DefProto DllImport, ImageList_EndDrag, WIN_STD_CALL_CONV,, <>, 0
          @DefProto DllImport, ImageList_DragEnter, WIN_STD_CALL_CONV,, <:HWND, :SDWORD, :SDWORD>, 12
          @DefProto DllImport, ImageList_DragLeave, WIN_STD_CALL_CONV,, <:HWND>, 4
          @DefProto DllImport, ImageList_DragMove, WIN_STD_CALL_CONV,, <:SDWORD, :SDWORD>, 8
          @DefProto DllImport, ImageList_SetDragCursorImage, WIN_STD_CALL_CONV,, <:HIMAGELIST, :SDWORD, :SDWORD, :SDWORD>, 16
          @DefProto DllImport, ImageList_DragShowNolock, WIN_STD_CALL_CONV,, <:BOOL>, 4
          @DefProto DllImport, ImageList_GetDragImage, WIN_STD_CALL_CONV,, <:ptr POINT, :ptr POINT>, 8
          ImageList_RemoveAll macro himl
            exitm <ImageList_Remove (himl, - 1)>
          endm
          ImageList_ExtractIcon macro hi, himl, i
            exitm <ImageList_GetIcon (himl, i, 0)>
          endm
          ImageList_LoadBitmap macro hi, lpbmp, cx_, cGrow, crMask
            exitm <ImageList_LoadImage (hi, lpbmp, cx_, cGrow, crMask, IMAGE_BITMAP, 0)>
          endm
          @DefProto DllImport, ImageList_Read, WIN_STD_CALL_CONV,, <:ptr IStream>, 4
          @DefProto DllImport, ImageList_Write, WIN_STD_CALL_CONV,, <:HIMAGELIST, :ptr IStream>, 8
          if (NTDDI_VERSION ge NTDDI_WINXP)
            ILP_NORMAL equ 0; Writes or reads the stream using new sematics for this version of comctl32

            ILP_DOWNLEVEL equ 1; Write or reads the stream using downlevel sematics.

            @DefProto DllImport, ImageList_ReadEx, WIN_STD_CALL_CONV,, <:DWORD, :ptr IStream, :REFIID, :ptr PVOID>, 16
            @DefProto DllImport, ImageList_WriteEx, WIN_STD_CALL_CONV,, <:HIMAGELIST, :DWORD, :ptr IStream>, 12
          endif
          ifndef IMAGEINFO
            IMAGEINFO struct
              hbmImage HBITMAP ?
              hbmMask HBITMAP ?
              Unused1 SDWORD ?
              Unused2 SDWORD ?
              rcImage RECT <>
            IMAGEINFO ends
            _IMAGEINFO typedef IMAGEINFO
            LPIMAGEINFO typedef ptr IMAGEINFO
          endif
          @DefProto DllImport, ImageList_GetIconSize, WIN_STD_CALL_CONV,, <:HIMAGELIST, :ptr SDWORD, :ptr SDWORD>, 12
          @DefProto DllImport, ImageList_SetIconSize, WIN_STD_CALL_CONV,, <:HIMAGELIST, :SDWORD, :SDWORD>, 12
          @DefProto DllImport, ImageList_GetImageInfo, WIN_STD_CALL_CONV,, <:HIMAGELIST, :SDWORD, :ptr IMAGEINFO>, 12
          @DefProto DllImport, ImageList_Merge, WIN_STD_CALL_CONV,, <:HIMAGELIST, :SDWORD, :HIMAGELIST, :SDWORD, :SDWORD, :SDWORD>, 24
          @DefProto DllImport, ImageList_Duplicate, WIN_STD_CALL_CONV,, <:HIMAGELIST>, 4
        endif
        if (NTDDI_VERSION ge NTDDI_WINXP)
          @DefProto DllImport, HIMAGELIST_QueryInterface, WIN_STD_CALL_CONV,, <:HIMAGELIST, :REFIID, :ptr ptr>, 12
          ifdef __cplusplus
            ;[...]
          else
            IImageListToHIMAGELIST macro himl
              exitm <((himl))>
            endm
          endif
        endif
      endif
      ;====== HEADER CONTROL =======================================================
      ifndef NOHEADER
        ifdef _WIN32
          WC_HEADERA equ <"SysHeader32">
          WC_HEADERW equ <L("SysHeader32")>
          ifdef UNICODE
            WC_HEADER equ <WC_HEADERW>
          else
            WC_HEADER equ <WC_HEADERA>
          endif
        else
          ;[...]
        endif
        ; begin_r_commctrl
        HDS_HORZ equ 0000h
        HDS_BUTTONS equ 0002h
        HDS_HOTTRACK equ 0004h
        HDS_HIDDEN equ 0008h
        HDS_DRAGDROP equ 0040h
        HDS_FULLDRAG equ 0080h
        HDS_FILTERBAR equ 0100h
        if (NTDDI_VERSION ge NTDDI_WINXP)
          HDS_FLAT equ 0200h
        endif
        if (NTDDI_VERSION ge NTDDI_VISTA)
          HDS_CHECKBOXES equ 0400h
          HDS_NOSIZING equ 0800h
          HDS_OVERFLOW equ 1000h
        endif
        ; end_r_commctrl
        HDFT_ISSTRING equ 0000h; HD_ITEM.pvFilter points to a HD_TEXTFILTER

        HDFT_ISNUMBER equ 0001h; HD_ITEM.pvFilter points to a INT

        HDFT_ISDATE equ 0002h; HD_ITEM.pvFilter points to a DWORD (dos date)

        HDFT_HASNOVALUE equ 8000h; clear the filter, by setting this bit

        ifdef UNICODE
          HD_TEXTFILTER equ <HD_TEXTFILTERW>
          HDTEXTFILTER equ <HD_TEXTFILTERW>
          LPHD_TEXTFILTER equ <LPHD_TEXTFILTERW>
          LPHDTEXTFILTER equ <LPHD_TEXTFILTERW>
        else
          HD_TEXTFILTER equ <HD_TEXTFILTERA>
          HDTEXTFILTER equ <HD_TEXTFILTERA>
          LPHD_TEXTFILTER equ <LPHD_TEXTFILTERA>
          LPHDTEXTFILTER equ <LPHD_TEXTFILTERA>
        endif
        HD_TEXTFILTERA struct
          pszText POINTER ?
          ; [in] pointer to the buffer containing the filter (ANSI)
          cchTextMax SDWORD ?
          ; [in] max size of buffer/edit control buffer
        HD_TEXTFILTERA ends
        _HD_TEXTFILTERA typedef HD_TEXTFILTERA
        LPHD_TEXTFILTERA typedef ptr HD_TEXTFILTERA
        HD_TEXTFILTERW struct
          pszText POINTER ?
          ; [in] pointer to the buffer contiaining the filter (UNICODE)
          cchTextMax SDWORD ?
          ; [in] max size of buffer/edit control buffer
        HD_TEXTFILTERW ends
        _HD_TEXTFILTERW typedef HD_TEXTFILTERW
        LPHD_TEXTFILTERW typedef ptr HD_TEXTFILTERW
        HD_ITEMA equ <HDITEMA>
        HD_ITEMW equ <HDITEMW>
        HD_ITEM equ <HDITEM>
        HDITEMA struct
          mask_ DWORD ?
          cxy SDWORD ?
          pszText POINTER ?
          hbm HBITMAP ?
          cchTextMax SDWORD ?
          fmt SDWORD ?
          lParam LPARAM ?
          iImage SDWORD ?
          ; index of bitmap in ImageList
          iOrder SDWORD ?
          ; where to draw this item
          type_ DWORD ?
          ; [in] filter type (defined what pvFilter is a pointer to)
          pvFilter POINTER ?
          ; [in] filter data see above
          if (NTDDI_VERSION ge NTDDI_VISTA)
            state DWORD ?
          endif
        HDITEMA ends
        _HD_ITEMA typedef HDITEMA
        LPHDITEMA typedef ptr HDITEMA
        HDITEMA_V1_SIZE equ <CCSIZEOF_STRUCT(HDITEMA, lParam)>
        HDITEMW_V1_SIZE equ <CCSIZEOF_STRUCT(HDITEMW, lParam)>
        HDITEMW struct
          mask_ DWORD ?
          cxy SDWORD ?
          pszText POINTER ?
          hbm HBITMAP ?
          cchTextMax SDWORD ?
          fmt SDWORD ?
          lParam LPARAM ?
          iImage SDWORD ?
          ; index of bitmap in ImageList
          iOrder SDWORD ?
          type_ DWORD ?
          ; [in] filter type (defined what pvFilter is a pointer to)
          pvFilter POINTER ?
          ; [in] fillter data see above
          if (NTDDI_VERSION ge NTDDI_VISTA)
            state DWORD ?
          endif
        HDITEMW ends
        _HD_ITEMW typedef HDITEMW
        LPHDITEMW typedef ptr HDITEMW
        ifdef UNICODE
          HDITEM equ <HDITEMW>
          LPHDITEM equ <LPHDITEMW>
          HDITEM_V1_SIZE equ <HDITEMW_V1_SIZE>
        else
          HDITEM equ <HDITEMA>
          LPHDITEM equ <LPHDITEMA>
          HDITEM_V1_SIZE equ <HDITEMA_V1_SIZE>
        endif
        HDI_WIDTH equ 0001h
        HDI_HEIGHT equ <HDI_WIDTH>
        HDI_TEXT equ 0002h
        HDI_FORMAT equ 0004h
        HDI_LPARAM equ 0008h
        HDI_BITMAP equ 0010h
        HDI_IMAGE equ 0020h
        HDI_DI_SETITEM equ 0040h
        HDI_ORDER equ 0080h
        HDI_FILTER equ 0100h
        if (NTDDI_VERSION ge NTDDI_VISTA)
          HDI_STATE equ 0200h
        endif
        ; HDF_ flags are shared with the listview control (LVCFMT_ flags)
        HDF_LEFT equ 0000h; Same as LVCFMT_LEFT

        HDF_RIGHT equ 0001h; Same as LVCFMT_RIGHT

        HDF_CENTER equ 0002h; Same as LVCFMT_CENTER

        HDF_JUSTIFYMASK equ 0003h; Same as LVCFMT_JUSTIFYMASK

        HDF_RTLREADING equ 0004h; Same as LVCFMT_LEFT

        HDF_BITMAP equ 2000h
        HDF_STRING equ 4000h
        HDF_OWNERDRAW equ 8000h; Same as LVCFMT_COL_HAS_IMAGES

        HDF_IMAGE equ 0800h; Same as LVCFMT_IMAGE

        HDF_BITMAP_ON_RIGHT equ 1000h; Same as LVCFMT_BITMAP_ON_RIGHT

        if (NTDDI_VERSION ge NTDDI_WINXP)
          HDF_SORTUP equ 0400h
          HDF_SORTDOWN equ 0200h
        endif
        if (NTDDI_VERSION ge NTDDI_VISTA)
          HDF_CHECKBOX equ 0040h
          HDF_CHECKED equ 0080h
          HDF_FIXEDWIDTH equ 0100h; Can't resize the column; same as LVCFMT_FIXED_WIDTH

          HDF_SPLITBUTTON equ 1000000h; Column is a split button; same as LVCFMT_SPLITBUTTON

        endif
        if (NTDDI_VERSION ge NTDDI_VISTA)
          HDIS_FOCUSED equ 00000001h
        endif
        HDM_GETITEMCOUNT equ (HDM_FIRST + 0)
        Header_GetItemCount macro hwndHD
          exitm <SNDMSG ((hwndHD), HDM_GETITEMCOUNT, 0, 0)>
        endm
        HDM_INSERTITEMA equ (HDM_FIRST + 1)
        HDM_INSERTITEMW equ (HDM_FIRST + 10)
        ifdef UNICODE
          HDM_INSERTITEM equ <HDM_INSERTITEMW>
        else
          HDM_INSERTITEM equ <HDM_INSERTITEMA>
        endif
        Header_InsertItem macro hwndHD, i, phdi
          exitm <SNDMSG ((hwndHD), HDM_INSERTITEM, (i), (const HD_ITEM *) (phdi))>
        endm
        HDM_DELETEITEM equ (HDM_FIRST + 2)
        Header_DeleteItem macro hwndHD, i
          exitm <SNDMSG ((hwndHD), HDM_DELETEITEM, (i), 0)>
        endm
        HDM_GETITEMA equ (HDM_FIRST + 3)
        HDM_GETITEMW equ (HDM_FIRST + 11)
        ifdef UNICODE
          HDM_GETITEM equ <HDM_GETITEMW>
        else
          HDM_GETITEM equ <HDM_GETITEMA>
        endif
        Header_GetItem macro hwndHD, i, phdi
          exitm <SNDMSG ((hwndHD), HDM_GETITEM, (i), (HD_ITEM *) (phdi))>
        endm
        HDM_SETITEMA equ (HDM_FIRST + 4)
        HDM_SETITEMW equ (HDM_FIRST + 12)
        ifdef UNICODE
          HDM_SETITEM equ <HDM_SETITEMW>
        else
          HDM_SETITEM equ <HDM_SETITEMA>
        endif
        Header_SetItem macro hwndHD, i, phdi
          exitm <SNDMSG ((hwndHD), HDM_SETITEM, (i), (const HD_ITEM *) (phdi))>
        endm
        HD_LAYOUT equ <HDLAYOUT>
        HDLAYOUT struct
          prc POINTER ?
          pwpos POINTER ?
        HDLAYOUT ends
        _HD_LAYOUT typedef HDLAYOUT
        LPHDLAYOUT typedef ptr HDLAYOUT
        HDM_LAYOUT equ (HDM_FIRST + 5)
        Header_Layout macro hwndHD, playout
          exitm <SNDMSG ((hwndHD), HDM_LAYOUT, 0, (HD_LAYOUT *) (playout))>
        endm
        HHT_NOWHERE equ 0001h
        HHT_ONHEADER equ 0002h
        HHT_ONDIVIDER equ 0004h
        HHT_ONDIVOPEN equ 0008h
        HHT_ONFILTER equ 0010h
        HHT_ONFILTERBUTTON equ 0020h
        HHT_ABOVE equ 0100h
        HHT_BELOW equ 0200h
        HHT_TORIGHT equ 0400h
        HHT_TOLEFT equ 0800h
        if (NTDDI_VERSION ge NTDDI_VISTA)
          HHT_ONITEMSTATEICON equ 1000h
          HHT_ONDROPDOWN equ 2000h
          HHT_ONOVERFLOW equ 4000h
        endif
        HD_HITTESTINFO equ <HDHITTESTINFO>
        HDHITTESTINFO struct
          pt POINT <>
          flags DWORD ?
          iItem SDWORD ?
        HDHITTESTINFO ends
        _HD_HITTESTINFO typedef HDHITTESTINFO
        LPHDHITTESTINFO typedef ptr HDHITTESTINFO
        HDSIL_NORMAL equ 0
        HDSIL_STATE equ 1
        HDM_HITTEST equ (HDM_FIRST + 6)
        HDM_GETITEMRECT equ (HDM_FIRST + 7)
        Header_GetItemRect macro hwnd, iItem, lprc
          exitm <SNDMSG ((hwnd), HDM_GETITEMRECT, (iItem), (lprc))>
        endm
        HDM_SETIMAGELIST equ (HDM_FIRST + 8)
        Header_SetImageList macro hwnd, himl
          exitm <SNDMSG ((hwnd), HDM_SETIMAGELIST, HDSIL_NORMAL, (himl))>
        endm
        Header_SetStateImageList macro hwnd, himl
          exitm <SNDMSG ((hwnd), HDM_SETIMAGELIST, HDSIL_STATE, (himl))>
        endm
        HDM_GETIMAGELIST equ (HDM_FIRST + 9)
        Header_GetImageList macro hwnd
          exitm <SNDMSG ((hwnd), HDM_GETIMAGELIST, HDSIL_NORMAL, 0)>
        endm
        Header_GetStateImageList macro hwnd
          exitm <SNDMSG ((hwnd), HDM_GETIMAGELIST, HDSIL_STATE, 0)>
        endm
        HDM_ORDERTOINDEX equ (HDM_FIRST + 15)
        Header_OrderToIndex macro hwnd, i
          exitm <SNDMSG ((hwnd), HDM_ORDERTOINDEX, (i), 0)>
        endm
        HDM_CREATEDRAGIMAGE equ (HDM_FIRST + 16); wparam = which item (by index)

        Header_CreateDragImage macro hwnd, i
          exitm <SNDMSG ((hwnd), HDM_CREATEDRAGIMAGE, (i), 0)>
        endm
        HDM_GETORDERARRAY equ (HDM_FIRST + 17)
        Header_GetOrderArray macro hwnd, iCount, lpi
          exitm <SNDMSG ((hwnd), HDM_GETORDERARRAY, (iCount), (lpi))>
        endm
        HDM_SETORDERARRAY equ (HDM_FIRST + 18)
        Header_SetOrderArray macro hwnd, iCount, lpi
          exitm <SNDMSG ((hwnd), HDM_SETORDERARRAY, (iCount), (lpi))>
        endm
        ; lparam = int array of size HDM_GETITEMCOUNT
        ; the array specifies the order that all items should be displayed.
        ; e.g.  { 2, 0, 1}
        ; says the index 2 item should be shown in the 0ths position
        ;      index 0 should be shown in the 1st position
        ;      index 1 should be shown in the 2nd position
        HDM_SETHOTDIVIDER equ (HDM_FIRST + 19)
        Header_SetHotDivider macro hwnd, fPos, dw_
          exitm <SNDMSG ((hwnd), HDM_SETHOTDIVIDER, (fPos), (dw_))>
        endm
        ; convenience message for external dragdrop
        ; wParam = BOOL  specifying whether the lParam is a dwPos of the cursor
        ;              position or the index of which divider to hotlight
        ; lParam = depends on wParam  (-1 and wParm = FALSE turns off hotlight)
        HDM_SETBITMAPMARGIN equ (HDM_FIRST + 20)
        Header_SetBitmapMargin macro hwnd, iWidth
          exitm <SNDMSG ((hwnd), HDM_SETBITMAPMARGIN, (iWidth), 0)>
        endm
        HDM_GETBITMAPMARGIN equ (HDM_FIRST + 21)
        Header_GetBitmapMargin macro hwnd
          exitm <SNDMSG ((hwnd), HDM_GETBITMAPMARGIN, 0, 0)>
        endm
        HDM_SETUNICODEFORMAT equ <CCM_SETUNICODEFORMAT>
        Header_SetUnicodeFormat macro hwnd, fUnicode
          exitm <SNDMSG ((hwnd), HDM_SETUNICODEFORMAT, (fUnicode), 0)>
        endm
        HDM_GETUNICODEFORMAT equ <CCM_GETUNICODEFORMAT>
        Header_GetUnicodeFormat macro hwnd
          exitm <SNDMSG ((hwnd), HDM_GETUNICODEFORMAT, 0, 0)>
        endm
        HDM_SETFILTERCHANGETIMEOUT equ (HDM_FIRST + 22)
        Header_SetFilterChangeTimeout macro hwnd, i
          exitm <SNDMSG ((hwnd), HDM_SETFILTERCHANGETIMEOUT, 0, (i))>
        endm
        HDM_EDITFILTER equ (HDM_FIRST + 23)
        Header_EditFilter macro hwnd, i, fDiscardChanges
          exitm <SNDMSG ((hwnd), HDM_EDITFILTER, (i), MAKELPARAM(fDiscardChanges, 0))>
        endm
        ; Clear filter takes -1 as a column value to indicate that all
        ; the filter should be cleared.  When this happens you will
        ; only receive a single filter changed notification.
        HDM_CLEARFILTER equ (HDM_FIRST + 24)
        Header_ClearFilter macro hwnd, i
          exitm <SNDMSG ((hwnd), HDM_CLEARFILTER, (i), 0)>
        endm
        Header_ClearAllFilters macro hwnd
          exitm <SNDMSG ((hwnd), HDM_CLEARFILTER, - 1, 0)>
        endm
        if (_WIN32_IE ge 0600h)
          HDM_TRANSLATEACCELERATOR equ <CCM_TRANSLATEACCELERATOR>
        endif
        if (NTDDI_VERSION ge NTDDI_VISTA)
          HDM_GETITEMDROPDOWNRECT equ (HDM_FIRST + 25); rect of item's drop down button

          Header_GetItemDropDownRect macro hwnd, iItem, lprc
            exitm <SNDMSG ((hwnd), HDM_GETITEMDROPDOWNRECT, (iItem), (lprc))>
          endm
          HDM_GETOVERFLOWRECT equ (HDM_FIRST + 26); rect of overflow button

          Header_GetOverflowRect macro hwnd, lprc
            exitm <SNDMSG ((hwnd), HDM_GETOVERFLOWRECT, 0, (lprc))>
          endm
          HDM_GETFOCUSEDITEM equ (HDM_FIRST + 27)
          Header_GetFocusedItem macro hwnd
            exitm <SNDMSG ((hwnd), HDM_GETFOCUSEDITEM, (0), (0))>
          endm
          HDM_SETFOCUSEDITEM equ (HDM_FIRST + 28)
          Header_SetFocusedItem macro hwnd, iItem
            exitm <SNDMSG ((hwnd), HDM_SETFOCUSEDITEM, (0), (iItem))>
          endm
        endif
        ; (NTDDI_VERSION >= NTDDI_VISTA)
        HDN_ITEMCHANGINGA equ (HDN_FIRST - 0)
        HDN_ITEMCHANGINGW equ (HDN_FIRST - 20)
        HDN_ITEMCHANGEDA equ (HDN_FIRST - 1)
        HDN_ITEMCHANGEDW equ (HDN_FIRST - 21)
        HDN_ITEMCLICKA equ (HDN_FIRST - 2)
        HDN_ITEMCLICKW equ (HDN_FIRST - 22)
        HDN_ITEMDBLCLICKA equ (HDN_FIRST - 3)
        HDN_ITEMDBLCLICKW equ (HDN_FIRST - 23)
        HDN_DIVIDERDBLCLICKA equ (HDN_FIRST - 5)
        HDN_DIVIDERDBLCLICKW equ (HDN_FIRST - 25)
        HDN_BEGINTRACKA equ (HDN_FIRST - 6)
        HDN_BEGINTRACKW equ (HDN_FIRST - 26)
        HDN_ENDTRACKA equ (HDN_FIRST - 7)
        HDN_ENDTRACKW equ (HDN_FIRST - 27)
        HDN_TRACKA equ (HDN_FIRST - 8)
        HDN_TRACKW equ (HDN_FIRST - 28)
        HDN_GETDISPINFOA equ (HDN_FIRST - 9)
        HDN_GETDISPINFOW equ (HDN_FIRST - 29)
        HDN_BEGINDRAG equ (HDN_FIRST - 10)
        HDN_ENDDRAG equ (HDN_FIRST - 11)
        HDN_FILTERCHANGE equ (HDN_FIRST - 12)
        HDN_FILTERBTNCLICK equ (HDN_FIRST - 13)
        if (_WIN32_IE ge 0600h)
          HDN_BEGINFILTEREDIT equ (HDN_FIRST - 14)
          HDN_ENDFILTEREDIT equ (HDN_FIRST - 15)
        endif
        if (NTDDI_VERSION ge NTDDI_VISTA)
          HDN_ITEMSTATEICONCLICK equ (HDN_FIRST - 16)
          HDN_ITEMKEYDOWN equ (HDN_FIRST - 17)
          HDN_DROPDOWN equ (HDN_FIRST - 18)
          HDN_OVERFLOWCLICK equ (HDN_FIRST - 19)
        endif
        ifdef UNICODE
          HDN_ITEMCHANGING equ <HDN_ITEMCHANGINGW>
          HDN_ITEMCHANGED equ <HDN_ITEMCHANGEDW>
          HDN_ITEMCLICK equ <HDN_ITEMCLICKW>
          HDN_ITEMDBLCLICK equ <HDN_ITEMDBLCLICKW>
          HDN_DIVIDERDBLCLICK equ <HDN_DIVIDERDBLCLICKW>
          HDN_BEGINTRACK equ <HDN_BEGINTRACKW>
          HDN_ENDTRACK equ <HDN_ENDTRACKW>
          HDN_TRACK equ <HDN_TRACKW>
          HDN_GETDISPINFO equ <HDN_GETDISPINFOW>
        else
          HDN_ITEMCHANGING equ <HDN_ITEMCHANGINGA>
          HDN_ITEMCHANGED equ <HDN_ITEMCHANGEDA>
          HDN_ITEMCLICK equ <HDN_ITEMCLICKA>
          HDN_ITEMDBLCLICK equ <HDN_ITEMDBLCLICKA>
          HDN_DIVIDERDBLCLICK equ <HDN_DIVIDERDBLCLICKA>
          HDN_BEGINTRACK equ <HDN_BEGINTRACKA>
          HDN_ENDTRACK equ <HDN_ENDTRACKA>
          HDN_TRACK equ <HDN_TRACKA>
          HDN_GETDISPINFO equ <HDN_GETDISPINFOA>
        endif
        HD_NOTIFYA equ <NMHEADERA>
        HD_NOTIFYW equ <NMHEADERW>
        HD_NOTIFY equ <NMHEADER>
        NMHEADERA struct
          hdr NMHDR <>
          iItem SDWORD ?
          iButton SDWORD ?
          pitem POINTER ?
        NMHEADERA ends
        tagNMHEADERA typedef NMHEADERA
        LPNMHEADERA typedef ptr NMHEADERA
        NMHEADERW struct
          hdr NMHDR <>
          iItem SDWORD ?
          iButton SDWORD ?
          pitem POINTER ?
        NMHEADERW ends
        tagNMHEADERW typedef NMHEADERW
        LPNMHEADERW typedef ptr NMHEADERW
        ifdef UNICODE
          NMHEADER equ <NMHEADERW>
          LPNMHEADER equ <LPNMHEADERW>
        else
          NMHEADER equ <NMHEADERA>
          LPNMHEADER equ <LPNMHEADERA>
        endif
        NMHDDISPINFOW struct
          hdr NMHDR <>
          iItem SDWORD ?
          mask_ DWORD ?
          pszText POINTER ?
          cchTextMax SDWORD ?
          iImage SDWORD ?
          lParam LPARAM ?
        NMHDDISPINFOW ends
        tagNMHDDISPINFOW typedef NMHDDISPINFOW
        LPNMHDDISPINFOW typedef ptr NMHDDISPINFOW
        NMHDDISPINFOA struct
          hdr NMHDR <>
          iItem SDWORD ?
          mask_ DWORD ?
          pszText POINTER ?
          cchTextMax SDWORD ?
          iImage SDWORD ?
          lParam LPARAM ?
        NMHDDISPINFOA ends
        tagNMHDDISPINFOA typedef NMHDDISPINFOA
        LPNMHDDISPINFOA typedef ptr NMHDDISPINFOA
        ifdef UNICODE
          NMHDDISPINFO equ <NMHDDISPINFOW>
          LPNMHDDISPINFO equ <LPNMHDDISPINFOW>
        else
          NMHDDISPINFO equ <NMHDDISPINFOA>
          LPNMHDDISPINFO equ <LPNMHDDISPINFOA>
        endif
        NMHDFILTERBTNCLICK struct
          hdr NMHDR <>
          iItem SDWORD ?
          rc RECT <>
        NMHDFILTERBTNCLICK ends
        tagNMHDFILTERBTNCLICK typedef NMHDFILTERBTNCLICK
        LPNMHDFILTERBTNCLICK typedef ptr NMHDFILTERBTNCLICK
      endif
      ; NOHEADER
      ;====== TOOLBAR CONTROL ======================================================
      ifndef NOTOOLBAR
        ifdef _WIN32
          TOOLBARCLASSNAMEW equ <L("ToolbarWindow32")>
          TOOLBARCLASSNAMEA equ <"ToolbarWindow32">
          ifdef UNICODE
            TOOLBARCLASSNAME equ <TOOLBARCLASSNAMEW>
          else
            TOOLBARCLASSNAME equ <TOOLBARCLASSNAMEA>
          endif
        else
          ;[...]
        endif
        TBBUTTON struct
          iBitmap SDWORD ?
          idCommand SDWORD ?
          fsState BYTE ?
          fsStyle BYTE ?
          ifdef _WIN64
            bReserved BYTE 6 dup (?)
            ; padding for alignment
          elseif Defined(_WIN32)
            bReserved BYTE 2 dup (?)
            ; padding for alignment
          endif
          dwData XWORD ?
          iString SXWORD ?
        TBBUTTON ends
        _TBBUTTON typedef TBBUTTON
        PTBBUTTON typedef ptr TBBUTTON
        LPTBBUTTON typedef ptr TBBUTTON
        LPCTBBUTTON typedef ptr TBBUTTON
        COLORMAP struct
          from COLORREF ?
          to COLORREF ?
        COLORMAP ends
        _COLORMAP typedef COLORMAP
        LPCOLORMAP typedef ptr COLORMAP
        @DefProto DllImport, CreateToolbarEx, WIN_STD_CALL_CONV,, <:HWND, :DWORD, :UINT, :SDWORD, :HINSTANCE, :UINT_PTR, :LPCTBBUTTON, :SDWORD, :SDWORD, :SDWORD, :SDWORD, :SDWORD, :UINT>, 52
        @DefProto DllImport, CreateMappedBitmap, WIN_STD_CALL_CONV,, <:HINSTANCE, :INT_PTR, :UINT, :LPCOLORMAP, :SDWORD>, 20
        CMB_MASKED equ 02h
        TBSTATE_CHECKED equ 01h
        TBSTATE_PRESSED equ 02h
        TBSTATE_ENABLED equ 04h
        TBSTATE_HIDDEN equ 08h
        TBSTATE_INDETERMINATE equ 10h
        TBSTATE_WRAP equ 20h
        TBSTATE_ELLIPSES equ 40h
        TBSTATE_MARKED equ 80h
        ; begin_r_commctrl
        TBSTYLE_BUTTON equ 0000h; obsolete; use BTNS_BUTTON instead

        TBSTYLE_SEP equ 0001h; obsolete; use BTNS_SEP instead

        TBSTYLE_CHECK equ 0002h; obsolete; use BTNS_CHECK instead

        TBSTYLE_GROUP equ 0004h; obsolete; use BTNS_GROUP instead

        TBSTYLE_CHECKGROUP equ <(TBSTYLE_GROUP or TBSTYLE_CHECK)>; obsolete; use BTNS_CHECKGROUP instead

        TBSTYLE_DROPDOWN equ 0008h; obsolete; use BTNS_DROPDOWN instead

        TBSTYLE_AUTOSIZE equ 0010h; obsolete; use BTNS_AUTOSIZE instead

        TBSTYLE_NOPREFIX equ 0020h; obsolete; use BTNS_NOPREFIX instead

        TBSTYLE_TOOLTIPS equ 0100h
        TBSTYLE_WRAPABLE equ 0200h
        TBSTYLE_ALTDRAG equ 0400h
        TBSTYLE_FLAT equ 0800h
        TBSTYLE_LIST equ 1000h
        TBSTYLE_CUSTOMERASE equ 2000h
        TBSTYLE_REGISTERDROP equ 4000h
        TBSTYLE_TRANSPARENT equ 8000h
        ; end_r_commctrl
        TBSTYLE_EX_DRAWDDARROWS equ 00000001h
        ; begin_r_commctrl
        BTNS_BUTTON equ <TBSTYLE_BUTTON>; 0x0000

        BTNS_SEP equ <TBSTYLE_SEP>; 0x0001

        BTNS_CHECK equ <TBSTYLE_CHECK>; 0x0002

        BTNS_GROUP equ <TBSTYLE_GROUP>; 0x0004

        BTNS_CHECKGROUP equ <TBSTYLE_CHECKGROUP>; (TBSTYLE_GROUP | TBSTYLE_CHECK)

        BTNS_DROPDOWN equ <TBSTYLE_DROPDOWN>; 0x0008

        BTNS_AUTOSIZE equ <TBSTYLE_AUTOSIZE>; 0x0010; automatically calculate the cx of the button

        BTNS_NOPREFIX equ <TBSTYLE_NOPREFIX>; 0x0020; this button should not have accel prefix

        BTNS_SHOWTEXT equ 0040h; ignored unless TBSTYLE_EX_MIXEDBUTTONS is set

        BTNS_WHOLEDROPDOWN equ 0080h; draw drop-down arrow, but without split arrow section

        ; end_r_commctrl
        TBSTYLE_EX_MIXEDBUTTONS equ 00000008h
        TBSTYLE_EX_HIDECLIPPEDBUTTONS equ 00000010h; don't show partially obscured buttons

        TBSTYLE_EX_MULTICOLUMN equ 00000002h; conflicts w/ TBSTYLE_WRAPABLE

        TBSTYLE_EX_VERTICAL equ 00000004h
        if (NTDDI_VERSION ge NTDDI_WINXP)
          TBSTYLE_EX_DOUBLEBUFFER equ 00000080h; Double Buffer the toolbar

        endif
        ; Custom Draw Structure
        NMTBCUSTOMDRAW struct
          nmcd NMCUSTOMDRAW <>
          hbrMonoDither HBRUSH ?
          hbrLines HBRUSH ?
          ; For drawing lines on buttons
          hpenLines HPEN ?
          ; For drawing lines on buttons
          clrText COLORREF ?
          ; Color of text
          clrMark COLORREF ?
          ; Color of text bk when marked. (only if TBSTATE_MARKED)
          clrTextHighlight COLORREF ?
          ; Color of text when highlighted
          clrBtnFace COLORREF ?
          ; Background of the button
          clrBtnHighlight COLORREF ?
          ; 3D highlight
          clrHighlightHotTrack COLORREF ?
          ; In conjunction with fHighlightHotTrack
          ; will cause button to highlight like a menu
          rcText RECT <>
          ; Rect for text
          nStringBkMode SDWORD ?
          nHLStringBkMode SDWORD ?
          if (NTDDI_VERSION ge NTDDI_WINXP)
            iListGap SDWORD ?
          endif
        NMTBCUSTOMDRAW ends
        _NMTBCUSTOMDRAW typedef NMTBCUSTOMDRAW
        LPNMTBCUSTOMDRAW typedef ptr NMTBCUSTOMDRAW
        ; Toolbar custom draw return flags
        TBCDRF_NOEDGES equ 00010000h; Don't draw button edges

        TBCDRF_HILITEHOTTRACK equ 00020000h; Use color of the button bk when hottracked

        TBCDRF_NOOFFSET equ 00040000h; Don't offset button if pressed

        TBCDRF_NOMARK equ 00080000h; Don't draw default highlight of image/text for TBSTATE_MARKED

        TBCDRF_NOETCHEDEFFECT equ 00100000h; Don't draw etched effect for disabled items

        TBCDRF_BLENDICON equ 00200000h; Use ILD_BLEND50 on the icon image

        TBCDRF_NOBACKGROUND equ 00400000h; Use ILD_BLEND50 on the icon image

        if (NTDDI_VERSION ge NTDDI_VISTA)
          TBCDRF_USECDCOLORS equ 00800000h; Use CustomDrawColors to RenderText regardless of VisualStyle

        endif
        TB_ENABLEBUTTON equ (WM_USER + 1)
        TB_CHECKBUTTON equ (WM_USER + 2)
        TB_PRESSBUTTON equ (WM_USER + 3)
        TB_HIDEBUTTON equ (WM_USER + 4)
        TB_INDETERMINATE equ (WM_USER + 5)
        TB_MARKBUTTON equ (WM_USER + 6)
        TB_ISBUTTONENABLED equ (WM_USER + 9)
        TB_ISBUTTONCHECKED equ (WM_USER + 10)
        TB_ISBUTTONPRESSED equ (WM_USER + 11)
        TB_ISBUTTONHIDDEN equ (WM_USER + 12)
        TB_ISBUTTONINDETERMINATE equ (WM_USER + 13)
        TB_ISBUTTONHIGHLIGHTED equ (WM_USER + 14)
        TB_SETSTATE equ (WM_USER + 17)
        TB_GETSTATE equ (WM_USER + 18)
        TB_ADDBITMAP equ (WM_USER + 19)
        ifdef _WIN32
          TBADDBITMAP struct
            hInst HINSTANCE ?
            nID XWORD ?
          TBADDBITMAP ends
          tagTBADDBITMAP typedef TBADDBITMAP
          LPTBADDBITMAP typedef ptr TBADDBITMAP
          HINST_COMMCTRL equ ((HINSTANCE) - 1)
          IDB_STD_SMALL_COLOR equ 0
          IDB_STD_LARGE_COLOR equ 1
          IDB_VIEW_SMALL_COLOR equ 4
          IDB_VIEW_LARGE_COLOR equ 5
          IDB_HIST_SMALL_COLOR equ 8
          IDB_HIST_LARGE_COLOR equ 9
          if (NTDDI_VERSION ge NTDDI_VISTA)
            IDB_HIST_NORMAL equ 12
            IDB_HIST_HOT equ 13
            IDB_HIST_DISABLED equ 14
            IDB_HIST_PRESSED equ 15
          endif
          ; (NTDDI_VERSION >= NTDDI_VISTA)
          ; icon indexes for standard bitmap
          STD_CUT equ 0
          STD_COPY equ 1
          STD_PASTE equ 2
          STD_UNDO equ 3
          STD_REDOW equ 4
          STD_DELETE equ 5
          STD_FILENEW equ 6
          STD_FILEOPEN equ 7
          STD_FILESAVE equ 8
          STD_PRINTPRE equ 9
          STD_PROPERTIES equ 10
          STD_HELP equ 11
          STD_FIND equ 12
          STD_REPLACE equ 13
          STD_PRINT equ 14
          ; icon indexes for standard view bitmap
          VIEW_LARGEICONS equ 0
          VIEW_SMALLICONS equ 1
          VIEW_LIST equ 2
          VIEW_DETAILS equ 3
          VIEW_SORTNAME equ 4
          VIEW_SORTSIZE equ 5
          VIEW_SORTDATE equ 6
          VIEW_SORTTYPE equ 7
          VIEW_PARENTFOLDER equ 8
          VIEW_NETCONNECT equ 9
          VIEW_NETDISCONNECT equ 10
          VIEW_NEWFOLDER equ 11
          VIEW_VIEWMENU equ 12
          HIST_BACK equ 0
          HIST_FORWARD equ 1
          HIST_FAVORITES equ 2
          HIST_ADDTOFAVORITES equ 3
          HIST_VIEWTREE equ 4
        endif
        TB_ADDBUTTONSA equ (WM_USER + 20)
        TB_INSERTBUTTONA equ (WM_USER + 21)
        TB_DELETEBUTTON equ (WM_USER + 22)
        TB_GETBUTTON equ (WM_USER + 23)
        TB_BUTTONCOUNT equ (WM_USER + 24)
        TB_COMMANDTOINDEX equ (WM_USER + 25)
        ifdef _WIN32
          TBSAVEPARAMSA struct
            hkr HKEY ?
            pszSubKey =POINTER ?
            pszValueName =POINTER ?
          TBSAVEPARAMSA ends
          tagTBSAVEPARAMSA typedef TBSAVEPARAMSA
          LPTBSAVEPARAMSA typedef ptr TBSAVEPARAMSA
          TBSAVEPARAMSW struct
            hkr HKEY ?
            pszSubKey =POINTER ?
            pszValueName =POINTER ?
          TBSAVEPARAMSW ends
          tagTBSAVEPARAMSW typedef TBSAVEPARAMSW
          LPTBSAVEPARAMW typedef ptr TBSAVEPARAMSW
          ifdef UNICODE
            TBSAVEPARAMS equ <TBSAVEPARAMSW>
            LPTBSAVEPARAMS equ <LPTBSAVEPARAMSW>
          else
            TBSAVEPARAMS equ <TBSAVEPARAMSA>
            LPTBSAVEPARAMS equ <LPTBSAVEPARAMSA>
          endif
        endif
        ; _WIN32
        TB_SAVERESTOREA equ (WM_USER + 26)
        TB_SAVERESTOREW equ (WM_USER + 76)
        TB_CUSTOMIZE equ (WM_USER + 27)
        TB_ADDSTRINGA equ (WM_USER + 28)
        TB_ADDSTRINGW equ (WM_USER + 77)
        TB_GETITEMRECT equ (WM_USER + 29)
        TB_BUTTONSTRUCTSIZE equ (WM_USER + 30)
        TB_SETBUTTONSIZE equ (WM_USER + 31)
        TB_SETBITMAPSIZE equ (WM_USER + 32)
        TB_AUTOSIZE equ (WM_USER + 33)
        TB_GETTOOLTIPS equ (WM_USER + 35)
        TB_SETTOOLTIPS equ (WM_USER + 36)
        TB_SETPARENT equ (WM_USER + 37)
        TB_SETROWS equ (WM_USER + 39)
        TB_GETROWS equ (WM_USER + 40)
        TB_SETCMDID equ (WM_USER + 42)
        TB_CHANGEBITMAP equ (WM_USER + 43)
        TB_GETBITMAP equ (WM_USER + 44)
        TB_GETBUTTONTEXTA equ (WM_USER + 45)
        TB_GETBUTTONTEXTW equ (WM_USER + 75)
        TB_REPLACEBITMAP equ (WM_USER + 46)
        TB_SETINDENT equ (WM_USER + 47)
        TB_SETIMAGELIST equ (WM_USER + 48)
        TB_GETIMAGELIST equ (WM_USER + 49)
        TB_LOADIMAGES equ (WM_USER + 50)
        TB_GETRECT equ (WM_USER + 51); wParam is the Cmd instead of index

        TB_SETHOTIMAGELIST equ (WM_USER + 52)
        TB_GETHOTIMAGELIST equ (WM_USER + 53)
        TB_SETDISABLEDIMAGELIST equ (WM_USER + 54)
        TB_GETDISABLEDIMAGELIST equ (WM_USER + 55)
        TB_SETSTYLE equ (WM_USER + 56)
        TB_GETSTYLE equ (WM_USER + 57)
        TB_GETBUTTONSIZE equ (WM_USER + 58)
        TB_SETBUTTONWIDTH equ (WM_USER + 59)
        TB_SETMAXTEXTROWS equ (WM_USER + 60)
        TB_GETTEXTROWS equ (WM_USER + 61)
        ifdef UNICODE
          TB_GETBUTTONTEXT equ <TB_GETBUTTONTEXTW>
          TB_SAVERESTORE equ <TB_SAVERESTOREW>
          TB_ADDSTRING equ <TB_ADDSTRINGW>
        else
          TB_GETBUTTONTEXT equ <TB_GETBUTTONTEXTA>
          TB_SAVERESTORE equ <TB_SAVERESTOREA>
          TB_ADDSTRING equ <TB_ADDSTRINGA>
        endif
        TB_GETOBJECT equ (WM_USER + 62); wParam == IID, lParam void **ppv

        TB_GETHOTITEM equ (WM_USER + 71)
        TB_SETHOTITEM equ (WM_USER + 72); wParam == iHotItem

        TB_SETANCHORHIGHLIGHT equ (WM_USER + 73); wParam == TRUE/FALSE

        TB_GETANCHORHIGHLIGHT equ (WM_USER + 74)
        TB_MAPACCELERATORA equ (WM_USER + 78); wParam == ch, lParam int * pidBtn

        TBINSERTMARK struct
          iButton SDWORD ?
          dwFlags DWORD ?
        TBINSERTMARK ends
        LPTBINSERTMARK typedef ptr TBINSERTMARK
        TBIMHT_AFTER equ 00000001h; TRUE = insert After iButton, otherwise before

        TBIMHT_BACKGROUND equ 00000002h; TRUE iff missed buttons completely

        TB_GETINSERTMARK equ (WM_USER + 79); lParam == LPTBINSERTMARK

        TB_SETINSERTMARK equ (WM_USER + 80); lParam == LPTBINSERTMARK

        TB_INSERTMARKHITTEST equ (WM_USER + 81); wParam == LPPOINT lParam == LPTBINSERTMARK

        TB_MOVEBUTTON equ (WM_USER + 82)
        TB_GETMAXSIZE equ (WM_USER + 83); lParam == LPSIZE

        TB_SETEXTENDEDSTYLE equ (WM_USER + 84); For TBSTYLE_EX_*

        TB_GETEXTENDEDSTYLE equ (WM_USER + 85); For TBSTYLE_EX_*

        TB_GETPADDING equ (WM_USER + 86)
        TB_SETPADDING equ (WM_USER + 87)
        TB_SETINSERTMARKCOLOR equ (WM_USER + 88)
        TB_GETINSERTMARKCOLOR equ (WM_USER + 89)
        TB_SETCOLORSCHEME equ <CCM_SETCOLORSCHEME>; lParam is color scheme

        TB_GETCOLORSCHEME equ <CCM_GETCOLORSCHEME>; fills in COLORSCHEME pointed to by lParam

        TB_SETUNICODEFORMAT equ <CCM_SETUNICODEFORMAT>
        TB_GETUNICODEFORMAT equ <CCM_GETUNICODEFORMAT>
        TB_MAPACCELERATORW equ (WM_USER + 90); wParam == ch, lParam int * pidBtn

        ifdef UNICODE
          TB_MAPACCELERATOR equ <TB_MAPACCELERATORW>
        else
          TB_MAPACCELERATOR equ <TB_MAPACCELERATORA>
        endif
        TBREPLACEBITMAP struct
          hInstOld HINSTANCE ?
          nIDOld XWORD ?
          hInstNew HINSTANCE ?
          nIDNew XWORD ?
          nButtons SDWORD ?
        TBREPLACEBITMAP ends
        LPTBREPLACEBITMAP typedef ptr TBREPLACEBITMAP
        ifdef _WIN32
          TBBF_LARGE equ 0001h
          TB_GETBITMAPFLAGS equ (WM_USER + 41)
          TBIF_IMAGE equ 00000001h
          TBIF_TEXT equ 00000002h
          TBIF_STATE equ 00000004h
          TBIF_STYLE equ 00000008h
          TBIF_LPARAM equ 00000010h
          TBIF_COMMAND equ 00000020h
          TBIF_SIZE equ 00000040h
          TBIF_BYINDEX equ 80000000h; this specifies that the wparam in Get/SetButtonInfo is an index, not id

          TBBUTTONINFOA struct
            cbSize DWORD ?
            dwMask DWORD ?
            idCommand SDWORD ?
            iImage SDWORD ?
            fsState BYTE ?
            fsStyle BYTE ?
            cx_ WORD ?
            lParam XWORD ?
            pszText POINTER ?
            cchText SDWORD ?
          TBBUTTONINFOA ends
          LPTBBUTTONINFOA typedef ptr TBBUTTONINFOA
          TBBUTTONINFOW struct
            cbSize DWORD ?
            dwMask DWORD ?
            idCommand SDWORD ?
            iImage SDWORD ?
            fsState BYTE ?
            fsStyle BYTE ?
            cx_ WORD ?
            lParam XWORD ?
            pszText POINTER ?
            cchText SDWORD ?
          TBBUTTONINFOW ends
          LPTBBUTTONINFOW typedef ptr TBBUTTONINFOW
          ifdef UNICODE
            TBBUTTONINFO equ <TBBUTTONINFOW>
            LPTBBUTTONINFO equ <LPTBBUTTONINFOW>
          else
            TBBUTTONINFO equ <TBBUTTONINFOA>
            LPTBBUTTONINFO equ <LPTBBUTTONINFOA>
          endif
          ; BUTTONINFO APIs do NOT support the string pool.
          TB_GETBUTTONINFOW equ (WM_USER + 63)
          TB_SETBUTTONINFOW equ (WM_USER + 64)
          TB_GETBUTTONINFOA equ (WM_USER + 65)
          TB_SETBUTTONINFOA equ (WM_USER + 66)
          ifdef UNICODE
            TB_GETBUTTONINFO equ <TB_GETBUTTONINFOW>
            TB_SETBUTTONINFO equ <TB_SETBUTTONINFOW>
          else
            TB_GETBUTTONINFO equ <TB_GETBUTTONINFOA>
            TB_SETBUTTONINFO equ <TB_SETBUTTONINFOA>
          endif
          TB_INSERTBUTTONW equ (WM_USER + 67)
          TB_ADDBUTTONSW equ (WM_USER + 68)
          TB_HITTEST equ (WM_USER + 69)
          ; New post Win95/NT4 for InsertButton and AddButton.  if iString member
          ; is a pointer to a string, it will be handled as a string like listview
          ; (although LPSTR_TEXTCALLBACK is not supported).
          ifdef UNICODE
            TB_INSERTBUTTON equ <TB_INSERTBUTTONW>
            TB_ADDBUTTONS equ <TB_ADDBUTTONSW>
          else
            TB_INSERTBUTTON equ <TB_INSERTBUTTONA>
            TB_ADDBUTTONS equ <TB_ADDBUTTONSA>
          endif
          TB_SETDRAWTEXTFLAGS equ (WM_USER + 70); wParam == mask lParam == bit values

          TB_GETSTRINGW equ (WM_USER + 91)
          TB_GETSTRINGA equ (WM_USER + 92)
          ifdef UNICODE
            TB_GETSTRING equ <TB_GETSTRINGW>
          else
            TB_GETSTRING equ <TB_GETSTRINGA>
          endif
          TB_SETBOUNDINGSIZE equ (WM_USER + 93)
          TB_SETHOTITEM2 equ (WM_USER + 94); wParam == iHotItem,  lParam = dwFlags

          TB_HASACCELERATOR equ (WM_USER + 95); wParam == char, lParam = &iCount

          TB_SETLISTGAP equ (WM_USER + 96)
          TB_GETIMAGELISTCOUNT equ (WM_USER + 98)
          TB_GETIDEALSIZE equ (WM_USER + 99); wParam == fHeight, lParam = psize

          ; before using WM_USER + 103, recycle old space above (WM_USER + 97)
          TB_TRANSLATEACCELERATOR equ <CCM_TRANSLATEACCELERATOR>
          if (NTDDI_VERSION ge NTDDI_WINXP)
            TBMF_PAD equ 00000001h
            TBMF_BARPAD equ 00000002h
            TBMF_BUTTONSPACING equ 00000004h
            TBMETRICS struct
              cbSize DWORD ?
              dwMask DWORD ?
              cxPad SDWORD ?
              ; PAD
              cyPad SDWORD ?
              cxBarPad SDWORD ?
              ; BARPAD
              cyBarPad SDWORD ?
              cxButtonSpacing SDWORD ?
              ; BUTTONSPACING
              cyButtonSpacing SDWORD ?
            TBMETRICS ends
            LPTBMETRICS typedef ptr TBMETRICS
            TB_GETMETRICS equ (WM_USER + 101)
            TB_SETMETRICS equ (WM_USER + 102)
          endif
          if (NTDDI_VERSION ge NTDDI_VISTA)
            TB_GETITEMDROPDOWNRECT equ (WM_USER + 103); Rect of item's drop down button

            TB_SETPRESSEDIMAGELIST equ (WM_USER + 104)
            TB_GETPRESSEDIMAGELIST equ (WM_USER + 105)
          endif
          ; (NTDDI_VERSION >= NTDDI_VISTA)
          if (NTDDI_VERSION ge NTDDI_WINXP)
            TB_SETWINDOWTHEME equ <CCM_SETWINDOWTHEME>
          endif
          TBN_GETBUTTONINFOA equ (TBN_FIRST - 0)
          TBN_BEGINDRAG equ (TBN_FIRST - 1)
          TBN_ENDDRAG equ (TBN_FIRST - 2)
          TBN_BEGINADJUST equ (TBN_FIRST - 3)
          TBN_ENDADJUST equ (TBN_FIRST - 4)
          TBN_RESET equ (TBN_FIRST - 5)
          TBN_QUERYINSERT equ (TBN_FIRST - 6)
          TBN_QUERYDELETE equ (TBN_FIRST - 7)
          TBN_TOOLBARCHANGE equ (TBN_FIRST - 8)
          TBN_CUSTHELP equ (TBN_FIRST - 9)
          TBN_DROPDOWN equ (TBN_FIRST - 10)
          TBN_GETOBJECT equ (TBN_FIRST - 12)
          ; Structure for TBN_HOTITEMCHANGE notification
          NMTBHOTITEM struct
            hdr NMHDR <>
            idOld SDWORD ?
            idNew SDWORD ?
            dwFlags DWORD ?
            ; HICF_*
          NMTBHOTITEM ends
          tagNMTBHOTITEM typedef NMTBHOTITEM
          LPNMTBHOTITEM typedef ptr NMTBHOTITEM
          ; Hot item change flags
          HICF_OTHER equ 00000000h
          HICF_MOUSE equ 00000001h; Triggered by mouse

          HICF_ARROWKEYS equ 00000002h; Triggered by arrow keys

          HICF_ACCELERATOR equ 00000004h; Triggered by accelerator

          HICF_DUPACCEL equ 00000008h; This accelerator is not unique

          HICF_ENTERING equ 00000010h; idOld is invalid

          HICF_LEAVING equ 00000020h; idNew is invalid

          HICF_RESELECT equ 00000040h; hot item reselected

          HICF_LMOUSE equ 00000080h; left mouse button selected

          HICF_TOGGLEDROPDOWN equ 00000100h; Toggle button's dropdown state

          TBN_HOTITEMCHANGE equ (TBN_FIRST - 13)
          TBN_DRAGOUT equ (TBN_FIRST - 14); this is sent when the user clicks down on a button then drags off the button

          TBN_DELETINGBUTTON equ (TBN_FIRST - 15); uses TBNOTIFY

          TBN_GETDISPINFOA equ (TBN_FIRST - 16); This is sent when the  toolbar needs  some display information

          TBN_GETDISPINFOW equ (TBN_FIRST - 17); This is sent when the  toolbar needs  some display information

          TBN_GETINFOTIPA equ (TBN_FIRST - 18)
          TBN_GETINFOTIPW equ (TBN_FIRST - 19)
          TBN_GETBUTTONINFOW equ (TBN_FIRST - 20)
          TBN_RESTORE equ (TBN_FIRST - 21)
          TBN_SAVE equ (TBN_FIRST - 22)
          TBN_INITCUSTOMIZE equ (TBN_FIRST - 23)
          TBNRF_HIDEHELP equ 00000001h
          TBNRF_ENDCUSTOMIZE equ 00000002h
          TBN_WRAPHOTITEM equ (TBN_FIRST - 24)
          TBN_DUPACCELERATOR equ (TBN_FIRST - 25)
          TBN_WRAPACCELERATOR equ (TBN_FIRST - 26)
          TBN_DRAGOVER equ (TBN_FIRST - 27)
          TBN_MAPACCELERATOR equ (TBN_FIRST - 28)
          NMTBSAVE struct
            hdr NMHDR <>
            pData POINTER ?
            pCurrent POINTER ?
            cbData DWORD ?
            iItem SDWORD ?
            cButtons SDWORD ?
            tbButton TBBUTTON <>
          NMTBSAVE ends
          tagNMTBSAVE typedef NMTBSAVE
          LPNMTBSAVE typedef ptr NMTBSAVE
          NMTBRESTORE struct
            hdr NMHDR <>
            pData POINTER ?
            pCurrent POINTER ?
            cbData DWORD ?
            iItem SDWORD ?
            cButtons SDWORD ?
            cbBytesPerRecord SDWORD ?
            tbButton TBBUTTON <>
          NMTBRESTORE ends
          tagNMTBRESTORE typedef NMTBRESTORE
          LPNMTBRESTORE typedef ptr NMTBRESTORE
          NMTBGETINFOTIPA struct
            hdr NMHDR <>
            pszText POINTER ?
            cchTextMax SDWORD ?
            iItem SDWORD ?
            lParam LPARAM ?
          NMTBGETINFOTIPA ends
          tagNMTBGETINFOTIPA typedef NMTBGETINFOTIPA
          LPNMTBGETINFOTIPA typedef ptr NMTBGETINFOTIPA
          NMTBGETINFOTIPW struct
            hdr NMHDR <>
            pszText POINTER ?
            cchTextMax SDWORD ?
            iItem SDWORD ?
            lParam LPARAM ?
          NMTBGETINFOTIPW ends
          tagNMTBGETINFOTIPW typedef NMTBGETINFOTIPW
          LPNMTBGETINFOTIPW typedef ptr NMTBGETINFOTIPW
          ifdef UNICODE
            TBN_GETINFOTIP equ <TBN_GETINFOTIPW>
            NMTBGETINFOTIP equ <NMTBGETINFOTIPW>
            LPNMTBGETINFOTIP equ <LPNMTBGETINFOTIPW>
          else
            TBN_GETINFOTIP equ <TBN_GETINFOTIPA>
            NMTBGETINFOTIP equ <NMTBGETINFOTIPA>
            LPNMTBGETINFOTIP equ <LPNMTBGETINFOTIPA>
          endif
          TBNF_IMAGE equ 00000001h
          TBNF_TEXT equ 00000002h
          TBNF_DI_SETITEM equ 10000000h
          NMTBDISPINFOA struct
            hdr NMHDR <>
            dwMask DWORD ?
            ; [in] Specifies the values requested .[out] Client ask the data to be set for future use
            idCommand SDWORD ?
            ; [in] id of button we're requesting info for
            lParam XWORD ?
            ; [in] lParam of button
            iImage SDWORD ?
            ; [out] image index
            pszText POINTER ?
            ; [out] new text for item
            cchText SDWORD ?
            ; [in] size of buffer pointed to by pszText
          NMTBDISPINFOA ends
          LPNMTBDISPINFOA typedef ptr NMTBDISPINFOA
          NMTBDISPINFOW struct
            hdr NMHDR <>
            dwMask DWORD ?
            ;[in] Specifies the values requested .[out] Client ask the data to be set for future use
            idCommand SDWORD ?
            ; [in] id of button we're requesting info for
            lParam XWORD ?
            ; [in] lParam of button
            iImage SDWORD ?
            ; [out] image index
            pszText POINTER ?
            ; [out] new text for item
            cchText SDWORD ?
            ; [in] size of buffer pointed to by pszText
          NMTBDISPINFOW ends
          LPNMTBDISPINFOW typedef ptr NMTBDISPINFOW
          ifdef UNICODE
            TBN_GETDISPINFO equ <TBN_GETDISPINFOW>
            NMTBDISPINFO equ <NMTBDISPINFOW>
            LPNMTBDISPINFO equ <LPNMTBDISPINFOW>
          else
            TBN_GETDISPINFO equ <TBN_GETDISPINFOA>
            NMTBDISPINFO equ <NMTBDISPINFOA>
            LPNMTBDISPINFO equ <LPNMTBDISPINFOA>
          endif
          ; Return codes for TBN_DROPDOWN
          TBDDRET_DEFAULT equ 0
          TBDDRET_NODEFAULT equ 1
          TBDDRET_TREATPRESSED equ 2; Treat as a standard press button

          ifdef UNICODE
            TBN_GETBUTTONINFO equ <TBN_GETBUTTONINFOW>
          else
            TBN_GETBUTTONINFO equ <TBN_GETBUTTONINFOA>
          endif
          TBNOTIFYA equ <NMTOOLBARA>
          TBNOTIFYW equ <NMTOOLBARW>
          LPTBNOTIFYA equ <LPNMTOOLBARA>
          LPTBNOTIFYW equ <LPNMTOOLBARW>
          TBNOTIFY equ <NMTOOLBAR>
          LPTBNOTIFY equ <LPNMTOOLBAR>
          NMTOOLBARA struct
            hdr NMHDR <>
            iItem SDWORD ?
            tbButton TBBUTTON <>
            cchText SDWORD ?
            pszText POINTER ?
            rcButton RECT <>
          NMTOOLBARA ends
          tagNMTOOLBARA typedef NMTOOLBARA
          LPNMTOOLBARA typedef ptr NMTOOLBARA
          NMTOOLBARW struct
            hdr NMHDR <>
            iItem SDWORD ?
            tbButton TBBUTTON <>
            cchText SDWORD ?
            pszText POINTER ?
            rcButton RECT <>
          NMTOOLBARW ends
          tagNMTOOLBARW typedef NMTOOLBARW
          LPNMTOOLBARW typedef ptr NMTOOLBARW
          ifdef UNICODE
            NMTOOLBAR equ <NMTOOLBARW>
            LPNMTOOLBAR equ <LPNMTOOLBARW>
          else
            NMTOOLBAR equ <NMTOOLBARA>
            LPNMTOOLBAR equ <LPNMTOOLBARA>
          endif
        endif
      endif
      ; NOTOOLBAR
      ;====== REBAR CONTROL ========================================================
      ifndef NOREBAR
        ifdef _WIN32
          REBARCLASSNAMEW equ <L("ReBarWindow32")>
          REBARCLASSNAMEA equ <"ReBarWindow32">
          ifdef UNICODE
            REBARCLASSNAME equ <REBARCLASSNAMEW>
          else
            REBARCLASSNAME equ <REBARCLASSNAMEA>
          endif
        else
          ;[...]
        endif
        RBIM_IMAGELIST equ 00000001h
        ; begin_r_commctrl
        RBS_TOOLTIPS equ 00000100h
        RBS_VARHEIGHT equ 00000200h
        RBS_BANDBORDERS equ 00000400h
        RBS_FIXEDORDER equ 00000800h
        RBS_REGISTERDROP equ 00001000h
        RBS_AUTOSIZE equ 00002000h
        RBS_VERTICALGRIPPER equ 00004000h; this always has the vertical gripper (default for horizontal mode)

        RBS_DBLCLKTOGGLE equ 00008000h
        ; end_r_commctrl
        REBARINFO struct
          cbSize DWORD ?
          fMask DWORD ?
          ifndef NOIMAGEAPIS
            himl HIMAGELIST ?
          else
            himl HANDLE ?
          endif
        REBARINFO ends
        tagREBARINFO typedef REBARINFO
        LPREBARINFO typedef ptr REBARINFO
        RBBS_BREAK equ 00000001h; break to new line

        RBBS_FIXEDSIZE equ 00000002h; band can't be sized

        RBBS_CHILDEDGE equ 00000004h; edge around top & bottom of child window

        RBBS_HIDDEN equ 00000008h; don't show

        RBBS_NOVERT equ 00000010h; don't show when vertical

        RBBS_FIXEDBMP equ 00000020h; bitmap doesn't move during band resize

        RBBS_VARIABLEHEIGHT equ 00000040h; allow autosizing of this child vertically

        RBBS_GRIPPERALWAYS equ 00000080h; always show the gripper

        RBBS_NOGRIPPER equ 00000100h; never show the gripper

        RBBS_USECHEVRON equ 00000200h; display drop-down button for this band if it's sized smaller than ideal width

        RBBS_HIDETITLE equ 00000400h; keep band title hidden

        RBBS_TOPALIGN equ 00000800h; keep band in top row

        if (NTDDI_VERSION ge NTDDI_VISTA)
        endif
        RBBIM_STYLE equ 00000001h
        RBBIM_COLORS equ 00000002h
        RBBIM_TEXT equ 00000004h
        RBBIM_IMAGE equ 00000008h
        RBBIM_CHILD equ 00000010h
        RBBIM_CHILDSIZE equ 00000020h
        RBBIM_SIZE equ 00000040h
        RBBIM_BACKGROUND equ 00000080h
        RBBIM_ID equ 00000100h
        RBBIM_IDEALSIZE equ 00000200h
        RBBIM_LPARAM equ 00000400h
        RBBIM_HEADERSIZE equ 00000800h; control the size of the header

        if (NTDDI_VERSION ge NTDDI_VISTA)
          RBBIM_CHEVRONLOCATION equ 00001000h
          RBBIM_CHEVRONSTATE equ 00002000h
        endif
        REBARBANDINFOA struct
          cbSize DWORD ?
          fMask DWORD ?
          fStyle DWORD ?
          clrFore COLORREF ?
          clrBack COLORREF ?
          lpText POINTER ?
          cch DWORD ?
          iImage SDWORD ?
          hwndChild HWND ?
          cxMinChild DWORD ?
          cyMinChild DWORD ?
          cx_ DWORD ?
          hbmBack HBITMAP ?
          wID DWORD ?
          cyChild DWORD ?
          cyMaxChild DWORD ?
          cyIntegral DWORD ?
          cxIdeal DWORD ?
          lParam LPARAM ?
          cxHeader DWORD ?
          if (NTDDI_VERSION ge NTDDI_VISTA)
            rcChevronLocation RECT <>
            ; the rect is in client co-ord wrt hwndChild
            uChevronState DWORD ?
            ; STATE_SYSTEM_*
          endif
        REBARBANDINFOA ends
        tagREBARBANDINFOA typedef REBARBANDINFOA
        LPREBARBANDINFOA typedef ptr REBARBANDINFOA
        LPCREBARBANDINFOA typedef ptr REBARBANDINFOA
        REBARBANDINFOA_V3_SIZE equ <CCSIZEOF_STRUCT(REBARBANDINFOA, wID)>
        REBARBANDINFOW_V3_SIZE equ <CCSIZEOF_STRUCT(REBARBANDINFOW, wID)>
        REBARBANDINFOA_V6_SIZE equ <CCSIZEOF_STRUCT(REBARBANDINFOA, cxHeader)>
        REBARBANDINFOW_V6_SIZE equ <CCSIZEOF_STRUCT(REBARBANDINFOW, cxHeader)>
        REBARBANDINFOW struct
          cbSize DWORD ?
          fMask DWORD ?
          fStyle DWORD ?
          clrFore COLORREF ?
          clrBack COLORREF ?
          lpText POINTER ?
          cch DWORD ?
          iImage SDWORD ?
          hwndChild HWND ?
          cxMinChild DWORD ?
          cyMinChild DWORD ?
          cx_ DWORD ?
          hbmBack HBITMAP ?
          wID DWORD ?
          cyChild DWORD ?
          cyMaxChild DWORD ?
          cyIntegral DWORD ?
          cxIdeal DWORD ?
          lParam LPARAM ?
          cxHeader DWORD ?
          if (NTDDI_VERSION ge NTDDI_VISTA)
            rcChevronLocation RECT <>
            ; the rect is in client co-ord wrt hwndChild
            uChevronState DWORD ?
            ; STATE_SYSTEM_*
          endif
        REBARBANDINFOW ends
        tagREBARBANDINFOW typedef REBARBANDINFOW
        LPREBARBANDINFOW typedef ptr REBARBANDINFOW
        LPCREBARBANDINFOW typedef ptr REBARBANDINFOW
        ifdef UNICODE
          REBARBANDINFO equ <REBARBANDINFOW>
          LPREBARBANDINFO equ <LPREBARBANDINFOW>
          LPCREBARBANDINFO equ <LPCREBARBANDINFOW>
          REBARBANDINFO_V3_SIZE equ <REBARBANDINFOW_V3_SIZE>
          REBARBANDINFO_V6_SIZE equ <REBARBANDINFOW_V6_SIZE>
        else
          REBARBANDINFO equ <REBARBANDINFOA>
          LPREBARBANDINFO equ <LPREBARBANDINFOA>
          LPCREBARBANDINFO equ <LPCREBARBANDINFOA>
          REBARBANDINFO_V3_SIZE equ <REBARBANDINFOA_V3_SIZE>
          REBARBANDINFO_V6_SIZE equ <REBARBANDINFOA_V6_SIZE>
        endif
        RB_INSERTBANDA equ (WM_USER + 1)
        RB_DELETEBAND equ (WM_USER + 2)
        RB_GETBARINFO equ (WM_USER + 3)
        RB_SETBARINFO equ (WM_USER + 4)
        RB_SETBANDINFOA equ (WM_USER + 6)
        RB_SETPARENT equ (WM_USER + 7)
        RB_HITTEST equ (WM_USER + 8)
        RB_GETRECT equ (WM_USER + 9)
        RB_INSERTBANDW equ (WM_USER + 10)
        RB_SETBANDINFOW equ (WM_USER + 11)
        RB_GETBANDCOUNT equ (WM_USER + 12)
        RB_GETROWCOUNT equ (WM_USER + 13)
        RB_GETROWHEIGHT equ (WM_USER + 14)
        RB_IDTOINDEX equ (WM_USER + 16); wParam == id

        RB_GETTOOLTIPS equ (WM_USER + 17)
        RB_SETTOOLTIPS equ (WM_USER + 18)
        RB_SETBKCOLOR equ (WM_USER + 19); sets the default BK color

        RB_GETBKCOLOR equ (WM_USER + 20); defaults to CLR_NONE

        RB_SETTEXTCOLOR equ (WM_USER + 21)
        RB_GETTEXTCOLOR equ (WM_USER + 22); defaults to 0x00000000

        if (NTDDI_VERSION ge NTDDI_WINXP)
          RBSTR_CHANGERECT equ 0001h; flags for RB_SIZETORECT

        endif
        RB_SIZETORECT equ (WM_USER + 23); resize the rebar/break bands and such to this rect (lparam)

        RB_SETCOLORSCHEME equ <CCM_SETCOLORSCHEME>; lParam is color scheme

        RB_GETCOLORSCHEME equ <CCM_GETCOLORSCHEME>; fills in COLORSCHEME pointed to by lParam

        ifdef UNICODE
          RB_INSERTBAND equ <RB_INSERTBANDW>
          RB_SETBANDINFO equ <RB_SETBANDINFOW>
        else
          RB_INSERTBAND equ <RB_INSERTBANDA>
          RB_SETBANDINFO equ <RB_SETBANDINFOA>
        endif
        ; for manual drag control
        ; lparam == cursor pos
        ; -1 means do it yourself.
        ; -2 means use what you had saved before
        RB_BEGINDRAG equ (WM_USER + 24)
        RB_ENDDRAG equ (WM_USER + 25)
        RB_DRAGMOVE equ (WM_USER + 26)
        RB_GETBARHEIGHT equ (WM_USER + 27)
        RB_GETBANDINFOW equ (WM_USER + 28)
        RB_GETBANDINFOA equ (WM_USER + 29)
        ifdef UNICODE
          RB_GETBANDINFO equ <RB_GETBANDINFOW>
        else
          RB_GETBANDINFO equ <RB_GETBANDINFOA>
        endif
        RB_MINIMIZEBAND equ (WM_USER + 30)
        RB_MAXIMIZEBAND equ (WM_USER + 31)
        RB_GETDROPTARGET equ <(CCM_GETDROPTARGET)>
        RB_GETBANDBORDERS equ (WM_USER + 34); returns in lparam = lprc the amount of edges added to band wparam

        RB_SHOWBAND equ (WM_USER + 35); show/hide band

        RB_SETPALETTE equ (WM_USER + 37)
        RB_GETPALETTE equ (WM_USER + 38)
        RB_MOVEBAND equ (WM_USER + 39)
        RB_SETUNICODEFORMAT equ <CCM_SETUNICODEFORMAT>
        RB_GETUNICODEFORMAT equ <CCM_GETUNICODEFORMAT>
        if (NTDDI_VERSION ge NTDDI_WINXP)
          RB_GETBANDMARGINS equ (WM_USER + 40)
          RB_SETWINDOWTHEME equ <CCM_SETWINDOWTHEME>
        endif
        if (_WIN32_IE ge 0600h)
          RB_SETEXTENDEDSTYLE equ (WM_USER + 41)
          RB_GETEXTENDEDSTYLE equ (WM_USER + 42)
        endif
        ; _WIN32_IE >= 0x0600
        RB_PUSHCHEVRON equ (WM_USER + 43)
        if (NTDDI_VERSION ge NTDDI_VISTA)
          RB_SETBANDWIDTH equ (WM_USER + 44); set width for docked band

        endif
        ; (NTDDI_VERSION >= NTDDI_VISTA)
        RBN_HEIGHTCHANGE equ (RBN_FIRST - 0)
        RBN_GETOBJECT equ (RBN_FIRST - 1)
        RBN_LAYOUTCHANGED equ (RBN_FIRST - 2)
        RBN_AUTOSIZE equ (RBN_FIRST - 3)
        RBN_BEGINDRAG equ (RBN_FIRST - 4)
        RBN_ENDDRAG equ (RBN_FIRST - 5)
        RBN_DELETINGBAND equ (RBN_FIRST - 6); Uses NMREBAR

        RBN_DELETEDBAND equ (RBN_FIRST - 7); Uses NMREBAR

        RBN_CHILDSIZE equ (RBN_FIRST - 8)
        RBN_CHEVRONPUSHED equ (RBN_FIRST - 10)
        if (_WIN32_IE ge 0600h)
          RBN_SPLITTERDRAG equ (RBN_FIRST - 11)
        endif
        ; _WIN32_IE >= 0x0600
        RBN_MINMAX equ (RBN_FIRST - 21)
        if (NTDDI_VERSION ge NTDDI_WINXP)
          RBN_AUTOBREAK equ (RBN_FIRST - 22)
        endif
        NMREBARCHILDSIZE struct
          hdr NMHDR <>
          uBand DWORD ?
          wID DWORD ?
          rcChild RECT <>
          rcBand RECT <>
        NMREBARCHILDSIZE ends
        tagNMREBARCHILDSIZE typedef NMREBARCHILDSIZE
        LPNMREBARCHILDSIZE typedef ptr NMREBARCHILDSIZE
        NMREBAR struct
          hdr NMHDR <>
          dwMask DWORD ?
          ; RBNM_*
          uBand DWORD ?
          fStyle DWORD ?
          wID DWORD ?
          lParam LPARAM ?
        NMREBAR ends
        tagNMREBAR typedef NMREBAR
        LPNMREBAR typedef ptr NMREBAR
        ; Mask flags for NMREBAR
        RBNM_ID equ 00000001h
        RBNM_STYLE equ 00000002h
        RBNM_LPARAM equ 00000004h
        NMRBAUTOSIZE struct
          hdr NMHDR <>
          fChanged DWORD ?
          rcTarget RECT <>
          rcActual RECT <>
        NMRBAUTOSIZE ends
        tagNMRBAUTOSIZE typedef NMRBAUTOSIZE
        LPNMRBAUTOSIZE typedef ptr NMRBAUTOSIZE
        NMREBARCHEVRON struct
          hdr NMHDR <>
          uBand DWORD ?
          wID DWORD ?
          lParam LPARAM ?
          rc RECT <>
          lParamNM LPARAM ?
        NMREBARCHEVRON ends
        tagNMREBARCHEVRON typedef NMREBARCHEVRON
        LPNMREBARCHEVRON typedef ptr NMREBARCHEVRON
        if (_WIN32_IE ge 0600h)
          NMREBARSPLITTER struct
            hdr NMHDR <>
            rcSizing RECT <>
          NMREBARSPLITTER ends
          tagNMREBARSPLITTER typedef NMREBARSPLITTER
          LPNMREBARSPLITTER typedef ptr NMREBARSPLITTER
        endif
        if (NTDDI_VERSION ge NTDDI_WINXP)
          RBAB_AUTOSIZE equ 0001h; These are not flags and are all mutually exclusive

          RBAB_ADDBAND equ 0002h
          NMREBARAUTOBREAK struct
            hdr NMHDR <>
            uBand DWORD ?
            wID DWORD ?
            lParam LPARAM ?
            uMsg DWORD ?
            fStyleCurrent DWORD ?
            fAutoBreak DWORD ?
          NMREBARAUTOBREAK ends
          tagNMREBARAUTOBREAK typedef NMREBARAUTOBREAK
          LPNMREBARAUTOBREAK typedef ptr NMREBARAUTOBREAK
        endif
        RBHT_NOWHERE equ 0001h
        RBHT_CAPTION equ 0002h
        RBHT_CLIENT equ 0003h
        RBHT_GRABBER equ 0004h
        RBHT_CHEVRON equ 0008h
        if (_WIN32_IE ge 0600h)
          RBHT_SPLITTER equ 0010h
        endif
        RBHITTESTINFO struct
          pt POINT <>
          flags DWORD ?
          iBand SDWORD ?
        RBHITTESTINFO ends
        _RB_HITTESTINFO typedef RBHITTESTINFO
        LPRBHITTESTINFO typedef ptr RBHITTESTINFO
      endif
      ; NOREBAR
      ;====== TOOLTIPS CONTROL =====================================================
      ifndef NOTOOLTIPS
        ifdef _WIN32
          TOOLTIPS_CLASSW equ <L("tooltips_class32")>
          TOOLTIPS_CLASSA equ <"tooltips_class32">
          ifdef UNICODE
            TOOLTIPS_CLASS equ <TOOLTIPS_CLASSW>
          else
            TOOLTIPS_CLASS equ <TOOLTIPS_CLASSA>
          endif
        else
          ;[...]
        endif
        LPTOOLINFOA equ <LPTTTOOLINFOA>
        LPTOOLINFOW equ <LPTTTOOLINFOW>
        TOOLINFOA equ <TTTOOLINFOA>
        TOOLINFOW equ <TTTOOLINFOW>
        LPTOOLINFO equ <LPTTTOOLINFO>
        TOOLINFO equ <TTTOOLINFO>
        TTTOOLINFOA_V1_SIZE equ <CCSIZEOF_STRUCT(TTTOOLINFOA, lpszText)>
        TTTOOLINFOW_V1_SIZE equ <CCSIZEOF_STRUCT(TTTOOLINFOW, lpszText)>
        TTTOOLINFOA_V2_SIZE equ <CCSIZEOF_STRUCT(TTTOOLINFOA, lParam)>
        TTTOOLINFOW_V2_SIZE equ <CCSIZEOF_STRUCT(TTTOOLINFOW, lParam)>
        TTTOOLINFOA_V3_SIZE equ <CCSIZEOF_STRUCT(TTTOOLINFOA, lpReserved)>
        TTTOOLINFOW_V3_SIZE equ <CCSIZEOF_STRUCT(TTTOOLINFOW, lpReserved)>
        TTTOOLINFOA struct
          cbSize DWORD ?
          uFlags DWORD ?
          hwnd HWND ?
          uId XWORD ?
          rect RECT <>
          hinst HINSTANCE ?
          lpszText POINTER ?
          lParam LPARAM ?
          if (NTDDI_VERSION ge NTDDI_WINXP)
            lpReserved POINTER ?
          endif
        TTTOOLINFOA ends
        tagTOOLINFOA typedef TTTOOLINFOA
        PTOOLINFOA typedef ptr TTTOOLINFOA
        LPTTTOOLINFOA typedef ptr TTTOOLINFOA
        TTTOOLINFOW struct
          cbSize DWORD ?
          uFlags DWORD ?
          hwnd HWND ?
          uId XWORD ?
          rect RECT <>
          hinst HINSTANCE ?
          lpszText POINTER ?
          lParam LPARAM ?
          if (NTDDI_VERSION ge NTDDI_WINXP)
            lpReserved POINTER ?
          endif
        TTTOOLINFOW ends
        tagTOOLINFOW typedef TTTOOLINFOW
        PTOOLINFOW typedef ptr TTTOOLINFOW
        LPTTTOOLINFOW typedef ptr TTTOOLINFOW
        ifdef UNICODE
          TTTOOLINFO equ <TTTOOLINFOW>
          PTOOLINFO equ <PTOOLINFOW>
          LPTTTOOLINFO equ <LPTTTOOLINFOW>
          TTTOOLINFO_V1_SIZE equ <TTTOOLINFOW_V1_SIZE>
        else
          PTOOLINFO equ <PTOOLINFOA>
          TTTOOLINFO equ <TTTOOLINFOA>
          LPTTTOOLINFO equ <LPTTTOOLINFOA>
          TTTOOLINFO_V1_SIZE equ <TTTOOLINFOA_V1_SIZE>
        endif
        ; begin_r_commctrl
        TTS_ALWAYSTIP equ 01h
        TTS_NOPREFIX equ 02h
        TTS_NOANIMATE equ 10h
        TTS_NOFADE equ 20h
        TTS_BALLOON equ 40h
        TTS_CLOSE equ 80h
        if (NTDDI_VERSION ge NTDDI_VISTA)
          TTS_USEVISUALSTYLE equ 100h; Use themed hyperlinks

        endif
        ; end_r_commctrl
        TTF_IDISHWND equ 0001h
        ; Use this to center around trackpoint in trackmode
        ; -OR- to center around tool in normal mode.
        ; Use TTF_ABSOLUTE to place the tip exactly at the track coords when
        ; in tracking mode.  TTF_ABSOLUTE can be used in conjunction with TTF_CENTERTIP
        ; to center the tip absolutely about the track point.
        TTF_CENTERTIP equ 0002h
        TTF_RTLREADING equ 0004h
        TTF_SUBCLASS equ 0010h
        TTF_TRACK equ 0020h
        TTF_ABSOLUTE equ 0080h
        TTF_TRANSPARENT equ 0100h
        TTF_PARSELINKS equ 1000h
        TTF_DI_SETITEM equ 8000h; valid only on the TTN_NEEDTEXT callback

        TTDT_AUTOMATIC equ 0
        TTDT_RESHOW equ 1
        TTDT_AUTOPOP equ 2
        TTDT_INITIAL equ 3
        ; ToolTip Icons (Set with TTM_SETTITLE)
        TTI_NONE equ 0
        TTI_INFO equ 1
        TTI_WARNING equ 2
        TTI_ERROR equ 3
        if (NTDDI_VERSION ge NTDDI_VISTA)
          TTI_INFO_LARGE equ 4
          TTI_WARNING_LARGE equ 5
          TTI_ERROR_LARGE equ 6
        endif
        ; (NTDDI_VERSION >= NTDDI_VISTA)
        ; Tool Tip Messages
        TTM_ACTIVATE equ (WM_USER + 1)
        TTM_SETDELAYTIME equ (WM_USER + 3)
        TTM_ADDTOOLA equ (WM_USER + 4)
        TTM_ADDTOOLW equ (WM_USER + 50)
        TTM_DELTOOLA equ (WM_USER + 5)
        TTM_DELTOOLW equ (WM_USER + 51)
        TTM_NEWTOOLRECTA equ (WM_USER + 6)
        TTM_NEWTOOLRECTW equ (WM_USER + 52)
        TTM_RELAYEVENT equ (WM_USER + 7); Win7: wParam = GetMessageExtraInfo() when relaying WM_MOUSEMOVE

        TTM_GETTOOLINFOA equ (WM_USER + 8)
        TTM_GETTOOLINFOW equ (WM_USER + 53)
        TTM_SETTOOLINFOA equ (WM_USER + 9)
        TTM_SETTOOLINFOW equ (WM_USER + 54)
        TTM_HITTESTA equ (WM_USER + 10)
        TTM_HITTESTW equ (WM_USER + 55)
        TTM_GETTEXTA equ (WM_USER + 11)
        TTM_GETTEXTW equ (WM_USER + 56)
        TTM_UPDATETIPTEXTA equ (WM_USER + 12)
        TTM_UPDATETIPTEXTW equ (WM_USER + 57)
        TTM_GETTOOLCOUNT equ (WM_USER + 13)
        TTM_ENUMTOOLSA equ (WM_USER + 14)
        TTM_ENUMTOOLSW equ (WM_USER + 58)
        TTM_GETCURRENTTOOLA equ (WM_USER + 15)
        TTM_GETCURRENTTOOLW equ (WM_USER + 59)
        TTM_WINDOWFROMPOINT equ (WM_USER + 16)
        TTM_TRACKACTIVATE equ (WM_USER + 17); wParam = TRUE/FALSE start end  lparam = LPTOOLINFO

        TTM_TRACKPOSITION equ (WM_USER + 18); lParam = dwPos

        TTM_SETTIPBKCOLOR equ (WM_USER + 19)
        TTM_SETTIPTEXTCOLOR equ (WM_USER + 20)
        TTM_GETDELAYTIME equ (WM_USER + 21)
        TTM_GETTIPBKCOLOR equ (WM_USER + 22)
        TTM_GETTIPTEXTCOLOR equ (WM_USER + 23)
        TTM_SETMAXTIPWIDTH equ (WM_USER + 24)
        TTM_GETMAXTIPWIDTH equ (WM_USER + 25)
        TTM_SETMARGIN equ (WM_USER + 26); lParam = lprc

        TTM_GETMARGIN equ (WM_USER + 27); lParam = lprc

        TTM_POP equ (WM_USER + 28)
        TTM_UPDATE equ (WM_USER + 29)
        TTM_GETBUBBLESIZE equ (WM_USER + 30)
        TTM_ADJUSTRECT equ (WM_USER + 31)
        TTM_SETTITLEA equ (WM_USER + 32); wParam = TTI_*, lParam = char* szTitle

        TTM_SETTITLEW equ (WM_USER + 33); wParam = TTI_*, lParam = wchar* szTitle

        if (NTDDI_VERSION ge NTDDI_WINXP)
          TTM_POPUP equ (WM_USER + 34)
          TTM_GETTITLE equ (WM_USER + 35); wParam = 0, lParam = TTGETTITLE*

          TTGETTITLE struct
            dwSize DWORD ?
            uTitleBitmap DWORD ?
            cch DWORD ?
            pszTitle POINTER ?
          TTGETTITLE ends
          _TTGETTITLE typedef TTGETTITLE
          PTTGETTITLE typedef ptr TTGETTITLE
        endif
        ifdef UNICODE
          TTM_ADDTOOL equ <TTM_ADDTOOLW>
          TTM_DELTOOL equ <TTM_DELTOOLW>
          TTM_NEWTOOLRECT equ <TTM_NEWTOOLRECTW>
          TTM_GETTOOLINFO equ <TTM_GETTOOLINFOW>
          TTM_SETTOOLINFO equ <TTM_SETTOOLINFOW>
          TTM_HITTEST equ <TTM_HITTESTW>
          TTM_GETTEXT equ <TTM_GETTEXTW>
          TTM_UPDATETIPTEXT equ <TTM_UPDATETIPTEXTW>
          TTM_ENUMTOOLS equ <TTM_ENUMTOOLSW>
          TTM_GETCURRENTTOOL equ <TTM_GETCURRENTTOOLW>
          TTM_SETTITLE equ <TTM_SETTITLEW>
        else
          TTM_ADDTOOL equ <TTM_ADDTOOLA>
          TTM_DELTOOL equ <TTM_DELTOOLA>
          TTM_NEWTOOLRECT equ <TTM_NEWTOOLRECTA>
          TTM_GETTOOLINFO equ <TTM_GETTOOLINFOA>
          TTM_SETTOOLINFO equ <TTM_SETTOOLINFOA>
          TTM_HITTEST equ <TTM_HITTESTA>
          TTM_GETTEXT equ <TTM_GETTEXTA>
          TTM_UPDATETIPTEXT equ <TTM_UPDATETIPTEXTA>
          TTM_ENUMTOOLS equ <TTM_ENUMTOOLSA>
          TTM_GETCURRENTTOOL equ <TTM_GETCURRENTTOOLA>
          TTM_SETTITLE equ <TTM_SETTITLEA>
        endif
        if (NTDDI_VERSION ge NTDDI_WINXP)
          TTM_SETWINDOWTHEME equ <CCM_SETWINDOWTHEME>
        endif
        LPHITTESTINFOW equ <LPTTHITTESTINFOW>
        LPHITTESTINFOA equ <LPTTHITTESTINFOA>
        LPHITTESTINFO equ <LPTTHITTESTINFO>
        TTHITTESTINFOA struct
          hwnd HWND ?
          pt POINT <>
          ti TTTOOLINFOA <>
        TTHITTESTINFOA ends
        _TT_HITTESTINFOA typedef TTHITTESTINFOA
        LPTTHITTESTINFOA typedef ptr TTHITTESTINFOA
        TTHITTESTINFOW struct
          hwnd HWND ?
          pt POINT <>
          ti TTTOOLINFOW <>
        TTHITTESTINFOW ends
        _TT_HITTESTINFOW typedef TTHITTESTINFOW
        LPTTHITTESTINFOW typedef ptr TTHITTESTINFOW
        ifdef UNICODE
          TTHITTESTINFO equ <TTHITTESTINFOW>
          LPTTHITTESTINFO equ <LPTTHITTESTINFOW>
        else
          TTHITTESTINFO equ <TTHITTESTINFOA>
          LPTTHITTESTINFO equ <LPTTHITTESTINFOA>
        endif
        TTN_GETDISPINFOA equ (TTN_FIRST - 0)
        TTN_GETDISPINFOW equ (TTN_FIRST - 10)
        TTN_SHOW equ (TTN_FIRST - 1)
        TTN_POP equ (TTN_FIRST - 2)
        TTN_LINKCLICK equ (TTN_FIRST - 3)
        ifdef UNICODE
          TTN_GETDISPINFO equ <TTN_GETDISPINFOW>
        else
          TTN_GETDISPINFO equ <TTN_GETDISPINFOA>
        endif
        TTN_NEEDTEXT equ <TTN_GETDISPINFO>
        TTN_NEEDTEXTA equ <TTN_GETDISPINFOA>
        TTN_NEEDTEXTW equ <TTN_GETDISPINFOW>
        TOOLTIPTEXTW equ <NMTTDISPINFOW>
        TOOLTIPTEXTA equ <NMTTDISPINFOA>
        LPTOOLTIPTEXTA equ <LPNMTTDISPINFOA>
        LPTOOLTIPTEXTW equ <LPNMTTDISPINFOW>
        TOOLTIPTEXT equ <NMTTDISPINFO>
        LPTOOLTIPTEXT equ <LPNMTTDISPINFO>
        NMTTDISPINFOA_V1_SIZE equ <CCSIZEOF_STRUCT(NMTTDISPINFOA, uFlags)>
        NMTTDISPINFOW_V1_SIZE equ <CCSIZEOF_STRUCT(NMTTDISPINFOW, uFlags)>
        NMTTDISPINFOA struct
          hdr NMHDR <>
          lpszText POINTER ?
          szText SBYTE 80 dup (?)
          hinst HINSTANCE ?
          uFlags DWORD ?
          lParam LPARAM ?
        NMTTDISPINFOA ends
        tagNMTTDISPINFOA typedef NMTTDISPINFOA
        LPNMTTDISPINFOA typedef ptr NMTTDISPINFOA
        NMTTDISPINFOW struct
          hdr NMHDR <>
          lpszText POINTER ?
          szText WORD 80 dup (?)
          hinst HINSTANCE ?
          uFlags DWORD ?
          lParam LPARAM ?
        NMTTDISPINFOW ends
        tagNMTTDISPINFOW typedef NMTTDISPINFOW
        LPNMTTDISPINFOW typedef ptr NMTTDISPINFOW
        ifdef UNICODE
          NMTTDISPINFO equ <NMTTDISPINFOW>
          LPNMTTDISPINFO equ <LPNMTTDISPINFOW>
          NMTTDISPINFO_V1_SIZE equ <NMTTDISPINFOW_V1_SIZE>
        else
          NMTTDISPINFO equ <NMTTDISPINFOA>
          LPNMTTDISPINFO equ <LPNMTTDISPINFOA>
          NMTTDISPINFO_V1_SIZE equ <NMTTDISPINFOA_V1_SIZE>
        endif
      endif
      ; NOTOOLTIPS
      ;====== STATUS BAR CONTROL ===================================================
      ifndef NOSTATUSBAR
        ; begin_r_commctrl
        SBARS_SIZEGRIP equ 0100h
        SBARS_TOOLTIPS equ 0800h
        ; this is a status bar flag, preference to SBARS_TOOLTIPS
        SBT_TOOLTIPS equ 0800h
        ; end_r_commctrl
        @DefProto DllImport, DrawStatusTextA, WIN_STD_CALL_CONV,, <:HDC, :LPCRECT, :LPCSTR, :UINT>, 16
        @DefProto DllImport, DrawStatusTextW, WIN_STD_CALL_CONV,, <:HDC, :LPCRECT, :LPCWSTR, :UINT>, 16
        @DefProto DllImport, CreateStatusWindowA, WIN_STD_CALL_CONV,, <:LONG, :LPCSTR, :HWND, :UINT>, 16
        @DefProto DllImport, CreateStatusWindowW, WIN_STD_CALL_CONV,, <:LONG, :LPCWSTR, :HWND, :UINT>, 16
        ifdef UNICODE
          CreateStatusWindow equ <CreateStatusWindowW>
          DrawStatusText equ <DrawStatusTextW>
        else
          CreateStatusWindow equ <CreateStatusWindowA>
          DrawStatusText equ <DrawStatusTextA>
        endif
        ifdef _WIN32
          STATUSCLASSNAMEW equ <L("msctls_statusbar32")>
          STATUSCLASSNAMEA equ <"msctls_statusbar32">
          ifdef UNICODE
            STATUSCLASSNAME equ <STATUSCLASSNAMEW>
          else
            STATUSCLASSNAME equ <STATUSCLASSNAMEA>
          endif
        else
          ;[...]
        endif
        SB_SETTEXTA equ (WM_USER + 1)
        SB_SETTEXTW equ (WM_USER + 11)
        SB_GETTEXTA equ (WM_USER + 2)
        SB_GETTEXTW equ (WM_USER + 13)
        SB_GETTEXTLENGTHA equ (WM_USER + 3)
        SB_GETTEXTLENGTHW equ (WM_USER + 12)
        ifdef UNICODE
          SB_GETTEXT equ <SB_GETTEXTW>
          SB_SETTEXT equ <SB_SETTEXTW>
          SB_GETTEXTLENGTH equ <SB_GETTEXTLENGTHW>
          SB_SETTIPTEXT equ <SB_SETTIPTEXTW>
          SB_GETTIPTEXT equ <SB_GETTIPTEXTW>
        else
          SB_GETTEXT equ <SB_GETTEXTA>
          SB_SETTEXT equ <SB_SETTEXTA>
          SB_GETTEXTLENGTH equ <SB_GETTEXTLENGTHA>
          SB_SETTIPTEXT equ <SB_SETTIPTEXTA>
          SB_GETTIPTEXT equ <SB_GETTIPTEXTA>
        endif
        SB_SETPARTS equ (WM_USER + 4)
        SB_GETPARTS equ (WM_USER + 6)
        SB_GETBORDERS equ (WM_USER + 7)
        SB_SETMINHEIGHT equ (WM_USER + 8)
        SB_SIMPLE equ (WM_USER + 9)
        SB_GETRECT equ (WM_USER + 10)
        SB_ISSIMPLE equ (WM_USER + 14)
        SB_SETICON equ (WM_USER + 15)
        SB_SETTIPTEXTA equ (WM_USER + 16)
        SB_SETTIPTEXTW equ (WM_USER + 17)
        SB_GETTIPTEXTA equ (WM_USER + 18)
        SB_GETTIPTEXTW equ (WM_USER + 19)
        SB_GETICON equ (WM_USER + 20)
        SB_SETUNICODEFORMAT equ <CCM_SETUNICODEFORMAT>
        SB_GETUNICODEFORMAT equ <CCM_GETUNICODEFORMAT>
        SBT_OWNERDRAW equ 1000h
        SBT_NOBORDERS equ 0100h
        SBT_POPOUT equ 0200h
        SBT_RTLREADING equ 0400h
        SBT_NOTABPARSING equ 0800h
        SB_SETBKCOLOR equ <CCM_SETBKCOLOR>; lParam = bkColor

        ; status bar notifications
        SBN_SIMPLEMODECHANGE equ (SBN_FIRST - 0)
        ; refers to the data saved for simple mode
        SB_SIMPLEID equ 00ffh
      endif
      ; NOSTATUSBAR
      ;====== MENU HELP ============================================================
      ifndef NOMENUHELP
        @DefProto DllImport, MenuHelp, WIN_STD_CALL_CONV,, <:UINT, :WPARAM, :LPARAM, :HMENU, :HINSTANCE, :HWND, :ptr UINT>, 28
        @DefProto DllImport, ShowHideMenuCtl, WIN_STD_CALL_CONV,, <:HWND, :UINT_PTR, :LPINT>, 12
        @DefProto DllImport, GetEffectiveClientRect, WIN_STD_CALL_CONV,, <:HWND, :LPRECT, :ptr INT_>, 12
        MINSYSCOMMAND equ <SC_SIZE>
      endif
      ;====== TRACKBAR CONTROL =====================================================
      ifndef NOTRACKBAR
        ifdef _WIN32
          TRACKBAR_CLASSA equ <"msctls_trackbar32">
          TRACKBAR_CLASSW equ <L("msctls_trackbar32")>
          ifdef UNICODE
            TRACKBAR_CLASS equ <TRACKBAR_CLASSW>
          else
            TRACKBAR_CLASS equ <TRACKBAR_CLASSA>
          endif
        else
          ;[...]
        endif
        ; begin_r_commctrl
        TBS_AUTOTICKS equ 0001h
        TBS_VERT equ 0002h
        TBS_HORZ equ 0000h
        TBS_TOP equ 0004h
        TBS_BOTTOM equ 0000h
        TBS_LEFT equ 0004h
        TBS_RIGHT equ 0000h
        TBS_BOTH equ 0008h
        TBS_NOTICKS equ 0010h
        TBS_ENABLESELRANGE equ 0020h
        TBS_FIXEDLENGTH equ 0040h
        TBS_NOTHUMB equ 0080h
        TBS_TOOLTIPS equ 0100h
        TBS_REVERSED equ 0200h; Accessibility hint: the smaller number (usually the min value) means "high" and the larger number (usually the max value) means "low"

        TBS_DOWNISLEFT equ 0400h; Down=Left and Up=Right (default is Down=Right and Up=Left)

        if (_WIN32_IE ge 0600h)
          TBS_NOTIFYBEFOREMOVE equ 0800h; Trackbar should notify parent before repositioning the slider due to user action (enables snapping)

        endif
        if (NTDDI_VERSION ge NTDDI_VISTA)
          TBS_TRANSPARENTBKGND equ 1000h; Background is painted by the parent via WM_PRINTCLIENT

        endif
        ; end_r_commctrl
        TBM_GETPOS equ <(WM_USER)>
        TBM_GETRANGEMIN equ (WM_USER + 1)
        TBM_GETRANGEMAX equ (WM_USER + 2)
        TBM_GETTIC equ (WM_USER + 3)
        TBM_SETTIC equ (WM_USER + 4)
        TBM_SETPOS equ (WM_USER + 5)
        TBM_SETRANGE equ (WM_USER + 6)
        TBM_SETRANGEMIN equ (WM_USER + 7)
        TBM_SETRANGEMAX equ (WM_USER + 8)
        TBM_CLEARTICS equ (WM_USER + 9)
        TBM_SETSEL equ (WM_USER + 10)
        TBM_SETSELSTART equ (WM_USER + 11)
        TBM_SETSELEND equ (WM_USER + 12)
        TBM_GETPTICS equ (WM_USER + 14)
        TBM_GETTICPOS equ (WM_USER + 15)
        TBM_GETNUMTICS equ (WM_USER + 16)
        TBM_GETSELSTART equ (WM_USER + 17)
        TBM_GETSELEND equ (WM_USER + 18)
        TBM_CLEARSEL equ (WM_USER + 19)
        TBM_SETTICFREQ equ (WM_USER + 20)
        TBM_SETPAGESIZE equ (WM_USER + 21)
        TBM_GETPAGESIZE equ (WM_USER + 22)
        TBM_SETLINESIZE equ (WM_USER + 23)
        TBM_GETLINESIZE equ (WM_USER + 24)
        TBM_GETTHUMBRECT equ (WM_USER + 25)
        TBM_GETCHANNELRECT equ (WM_USER + 26)
        TBM_SETTHUMBLENGTH equ (WM_USER + 27)
        TBM_GETTHUMBLENGTH equ (WM_USER + 28)
        TBM_SETTOOLTIPS equ (WM_USER + 29)
        TBM_GETTOOLTIPS equ (WM_USER + 30)
        TBM_SETTIPSIDE equ (WM_USER + 31)
        ; TrackBar Tip Side flags
        TBTS_TOP equ 0
        TBTS_LEFT equ 1
        TBTS_BOTTOM equ 2
        TBTS_RIGHT equ 3
        TBM_SETBUDDY equ (WM_USER + 32); wparam = BOOL fLeft; (or right)

        TBM_GETBUDDY equ (WM_USER + 33); wparam = BOOL fLeft; (or right)

        TBM_SETPOSNOTIFY equ (WM_USER + 34)
        TBM_SETUNICODEFORMAT equ <CCM_SETUNICODEFORMAT>
        TBM_GETUNICODEFORMAT equ <CCM_GETUNICODEFORMAT>
        TB_LINEUP equ 0
        TB_LINEDOWN equ 1
        TB_PAGEUP equ 2
        TB_PAGEDOWN equ 3
        TB_THUMBPOSITION equ 4
        TB_THUMBTRACK equ 5
        TB_TOP equ 6
        TB_BOTTOM equ 7
        TB_ENDTRACK equ 8
        ; custom draw item specs
        TBCD_TICS equ 0001h
        TBCD_THUMB equ 0002h
        TBCD_CHANNEL equ 0003h
        if (NTDDI_VERSION ge NTDDI_VISTA)
          TRBN_THUMBPOSCHANGING equ (TRBN_FIRST - 1)
          ; Structure for Trackbar's TRBN_THUMBPOSCHANGING notification
          NMTRBTHUMBPOSCHANGING struct
            hdr NMHDR <>
            dwPos DWORD ?
            nReason SDWORD ?
          NMTRBTHUMBPOSCHANGING ends
          tagTRBTHUMBPOSCHANGING typedef NMTRBTHUMBPOSCHANGING
        endif
      endif
      ; trackbar
      ;====== DRAG LIST CONTROL ====================================================
      ifndef NODRAGLIST
        DRAGLISTINFO struct
          uNotification DWORD ?
          hWnd HWND ?
          ptCursor POINT <>
        DRAGLISTINFO ends
        tagDRAGLISTINFO typedef DRAGLISTINFO
        LPDRAGLISTINFO typedef ptr DRAGLISTINFO
        DL_BEGINDRAG equ (WM_USER + 133)
        DL_DRAGGING equ (WM_USER + 134)
        DL_DROPPED equ (WM_USER + 135)
        DL_CANCELDRAG equ (WM_USER + 136)
        DL_CURSORSET equ 0
        DL_STOPCURSOR equ 1
        DL_COPYCURSOR equ 2
        DL_MOVECURSOR equ 3
        DRAGLISTMSGSTRING equ <TEXT("commctrl_DragListMsg")>
        @DefProto DllImport, MakeDragList, WIN_STD_CALL_CONV,, <:HWND>, 4
        @DefProto DllImport, DrawInsert, WIN_STD_CALL_CONV,, <:HWND, :HWND, :SDWORD>, 12
        @DefProto DllImport, LBItemFromPt, WIN_STD_CALL_CONV,, <:HWND, :POINT, :BOOL>, 12
      endif
      ;====== UPDOWN CONTROL =======================================================
      ifndef NOUPDOWN
        ifdef _WIN32
          UPDOWN_CLASSA equ <"msctls_updown32">
          UPDOWN_CLASSW equ <L("msctls_updown32")>
          ifdef UNICODE
            UPDOWN_CLASS equ <UPDOWN_CLASSW>
          else
            UPDOWN_CLASS equ <UPDOWN_CLASSA>
          endif
        else
          ;[...]
        endif
        UDACCEL struct
          nSec DWORD ?
          nInc DWORD ?
        UDACCEL ends
        _UDACCEL typedef UDACCEL
        LPUDACCEL typedef ptr UDACCEL
        UD_MAXVAL equ 7fffh
        UD_MINVAL equ <(- UD_MAXVAL)>
        ; begin_r_commctrl
        UDS_WRAP equ 0001h
        UDS_SETBUDDYINT equ 0002h
        UDS_ALIGNRIGHT equ 0004h
        UDS_ALIGNLEFT equ 0008h
        UDS_AUTOBUDDY equ 0010h
        UDS_ARROWKEYS equ 0020h
        UDS_HORZ equ 0040h
        UDS_NOTHOUSANDS equ 0080h
        UDS_HOTTRACK equ 0100h
        ; end_r_commctrl
        UDM_SETRANGE equ (WM_USER + 101)
        UDM_GETRANGE equ (WM_USER + 102)
        UDM_SETPOS equ (WM_USER + 103)
        UDM_GETPOS equ (WM_USER + 104)
        UDM_SETBUDDY equ (WM_USER + 105)
        UDM_GETBUDDY equ (WM_USER + 106)
        UDM_SETACCEL equ (WM_USER + 107)
        UDM_GETACCEL equ (WM_USER + 108)
        UDM_SETBASE equ (WM_USER + 109)
        UDM_GETBASE equ (WM_USER + 110)
        UDM_SETRANGE32 equ (WM_USER + 111)
        UDM_GETRANGE32 equ (WM_USER + 112); wParam & lParam are LPINT

        UDM_SETUNICODEFORMAT equ <CCM_SETUNICODEFORMAT>
        UDM_GETUNICODEFORMAT equ <CCM_GETUNICODEFORMAT>
        UDM_SETPOS32 equ (WM_USER + 113)
        UDM_GETPOS32 equ (WM_USER + 114)
        @DefProto DllImport, CreateUpDownControl, WIN_STD_CALL_CONV,, <:DWORD, :SDWORD, :SDWORD, :SDWORD, :SDWORD, :HWND, :SDWORD, :HINSTANCE, :HWND, :SDWORD, :SDWORD, :SDWORD>, 48
        NM_UPDOWN equ <NMUPDOWN>
        LPNM_UPDOWN equ <LPNMUPDOWN>
        NMUPDOWN struct
          hdr NMHDR <>
          iPos SDWORD ?
          iDelta SDWORD ?
        NMUPDOWN ends
        _NM_UPDOWN typedef NMUPDOWN
        LPNMUPDOWN typedef ptr NMUPDOWN
        UDN_DELTAPOS equ (UDN_FIRST - 1)
      endif
      ; NOUPDOWN
      ;====== PROGRESS CONTROL =====================================================
      ifndef NOPROGRESS
        ifdef _WIN32
          PROGRESS_CLASSA equ <"msctls_progress32">
          PROGRESS_CLASSW equ <L("msctls_progress32")>
          ifdef UNICODE
            PROGRESS_CLASS equ <PROGRESS_CLASSW>
          else
            PROGRESS_CLASS equ <PROGRESS_CLASSA>
          endif
        else
          ;[...]
        endif
        ; begin_r_commctrl
        PBS_SMOOTH equ 01h
        PBS_VERTICAL equ 04h
        ; end_r_commctrl
        PBM_SETRANGE equ (WM_USER + 1)
        PBM_SETPOS equ (WM_USER + 2)
        PBM_DELTAPOS equ (WM_USER + 3)
        PBM_SETSTEP equ (WM_USER + 4)
        PBM_STEPIT equ (WM_USER + 5)
        PBM_SETRANGE32 equ (WM_USER + 6); lParam = high, wParam = low

        PBRANGE struct
          iLow SDWORD ?
          iHigh SDWORD ?
        PBRANGE ends
        PPBRANGE typedef ptr PBRANGE
        PBM_GETRANGE equ (WM_USER + 7); wParam = return (TRUE ? low : high). lParam = PPBRANGE or NULL

        PBM_GETPOS equ (WM_USER + 8)
        PBM_SETBARCOLOR equ (WM_USER + 9); lParam = bar color

        PBM_SETBKCOLOR equ <CCM_SETBKCOLOR>; lParam = bkColor

        ; begin_r_commctrl
        if (NTDDI_VERSION ge NTDDI_WINXP)
          PBS_MARQUEE equ 08h
        endif
        ; (NTDDI_VERSION >= NTDDI_WINXP)
        ; end_r_commctrl
        if (NTDDI_VERSION ge NTDDI_WINXP)
          PBM_SETMARQUEE equ (WM_USER + 10)
        endif
        ; (NTDDI_VERSION >= NTDDI_WINXP)
        ; begin_r_commctrl
        if (NTDDI_VERSION ge NTDDI_VISTA)
          PBS_SMOOTHREVERSE equ 10h
        endif
        ; (NTDDI_VERSION >= NTDDI_VISTA)
        ; end_r_commctrl
        if (NTDDI_VERSION ge NTDDI_VISTA)
          PBM_GETSTEP equ (WM_USER + 13)
          PBM_GETBKCOLOR equ (WM_USER + 14)
          PBM_GETBARCOLOR equ (WM_USER + 15)
          PBM_SETSTATE equ (WM_USER + 16); wParam = PBST_[State] (NORMAL, ERROR, PAUSED)

          PBM_GETSTATE equ (WM_USER + 17)
          PBST_NORMAL equ 0001h
          PBST_ERROR equ 0002h
          PBST_PAUSED equ 0003h
        endif
        ; (NTDDI_VERSION >= NTDDI_VISTA)
      endif
      ; NOPROGRESS
      ;====== HOTKEY CONTROL =======================================================
      ifndef NOHOTKEY
        HOTKEYF_SHIFT equ 01h
        HOTKEYF_CONTROL equ 02h
        HOTKEYF_ALT equ 04h
        ifdef _MAC
          ;[...]
        else
          HOTKEYF_EXT equ 08h
        endif
        HKCOMB_NONE equ 0001h
        HKCOMB_S equ 0002h
        HKCOMB_C equ 0004h
        HKCOMB_A equ 0008h
        HKCOMB_SC equ 0010h
        HKCOMB_SA equ 0020h
        HKCOMB_CA equ 0040h
        HKCOMB_SCA equ 0080h
        HKM_SETHOTKEY equ (WM_USER + 1)
        HKM_GETHOTKEY equ (WM_USER + 2)
        HKM_SETRULES equ (WM_USER + 3)
        ifdef _WIN32
          HOTKEY_CLASSA equ <"msctls_hotkey32">
          HOTKEY_CLASSW equ <L("msctls_hotkey32")>
          ifdef UNICODE
            HOTKEY_CLASS equ <HOTKEY_CLASSW>
          else
            HOTKEY_CLASS equ <HOTKEY_CLASSA>
          endif
        else
          ;[...]
        endif
      endif
      ; NOHOTKEY
      ; begin_r_commctrl
      ;====== COMMON CONTROL STYLES ================================================
      CCS_TOP equ 00000001h
      CCS_NOMOVEY equ 00000002h
      CCS_BOTTOM equ 00000003h
      CCS_NORESIZE equ 00000004h
      CCS_NOPARENTALIGN equ 00000008h
      CCS_ADJUSTABLE equ 00000020h
      CCS_NODIVIDER equ 00000040h
      CCS_VERT equ 00000080h
      CCS_LEFT equ <(CCS_VERT or CCS_TOP)>
      CCS_RIGHT equ <(CCS_VERT or CCS_BOTTOM)>
      CCS_NOMOVEX equ <(CCS_VERT or CCS_NOMOVEY)>
      ; end_r_commctrl
      ;====== SysLink control =========================================
      ifdef _WIN32
        if (NTDDI_VERSION ge NTDDI_WINXP)
          INVALID_LINK_INDEX equ (- 1)
          MAX_LINKID_TEXT equ 48
          L_MAX_URL_LENGTH equ <(2048 + 32 + sizeof("://"))>
          WC_LINK equ <L("SysLink")>
          ; begin_r_commctrl
          LWS_TRANSPARENT equ 0001h
          LWS_IGNORERETURN equ 0002h
          if (NTDDI_VERSION ge NTDDI_VISTA)
            LWS_NOPREFIX equ 0004h
            LWS_USEVISUALSTYLE equ 0008h
            LWS_USECUSTOMTEXT equ 0010h
            LWS_RIGHT equ 0020h
          endif
          ; (NTDDI_VERSION >= NTDDI_VISTA)
          ; end_r_commctrl
          LIF_ITEMINDEX equ 00000001h
          LIF_STATE equ 00000002h
          LIF_ITEMID equ 00000004h
          LIF_URL equ 00000008h
          LIS_FOCUSED equ 00000001h
          LIS_ENABLED equ 00000002h
          LIS_VISITED equ 00000004h
          if (NTDDI_VERSION ge NTDDI_VISTA)
            LIS_HOTTRACK equ 00000008h
            LIS_DEFAULTCOLORS equ 00000010h; Don't use any custom text colors

          endif
          LITEM struct
            mask_ DWORD ?
            iLink SDWORD ?
            state DWORD ?
            stateMask DWORD ?
            szID WORD MAX_LINKID_TEXT dup (?)
            szUrl WORD L_MAX_URL_LENGTH dup (?)
          LITEM ends
          tagLITEM typedef LITEM
          PLITEM typedef ptr LITEM
          LHITTESTINFO struct
            pt POINT <>
            item LITEM <>
          LHITTESTINFO ends
          tagLHITTESTINFO typedef LHITTESTINFO
          PLHITTESTINFO typedef ptr LHITTESTINFO
          NMLINK struct
            hdr NMHDR <>
            item LITEM <>
          NMLINK ends
          tagNMLINK typedef NMLINK
          PNMLINK typedef ptr NMLINK
          ;  SysLink notifications
          ;  NM_CLICK   // wParam: control ID, lParam: PNMLINK, ret: ignored.
          ;  LinkWindow messages
          LM_HITTEST equ (WM_USER + 300h); wParam: n/a, lparam: PLHITTESTINFO, ret: BOOL

          LM_GETIDEALHEIGHT equ (WM_USER + 301h); wParam: cxMaxWidth, lparam: n/a, ret: cy

          LM_SETITEM equ (WM_USER + 302h); wParam: n/a, lparam: LITEM*, ret: BOOL

          LM_GETITEM equ (WM_USER + 303h); wParam: n/a, lparam: LITEM*, ret: BOOL

          LM_GETIDEALSIZE equ <(LM_GETIDEALHEIGHT)>; wParam: cxMaxWidth, lparam: SIZE*, ret: cy

        endif
      endif
      ; _WIN32
      ;====== End SysLink control =========================================
      ;====== LISTVIEW CONTROL =====================================================
      ifndef NOLISTVIEW
        ifdef _WIN32
          WC_LISTVIEWA equ <"SysListView32">
          WC_LISTVIEWW equ <L("SysListView32")>
          ifdef UNICODE
            WC_LISTVIEW equ <WC_LISTVIEWW>
          else
            WC_LISTVIEW equ <WC_LISTVIEWA>
          endif
        else
          ;[...]
        endif
        ; begin_r_commctrl
        LVS_ICON equ 0000h
        LVS_REPORT equ 0001h
        LVS_SMALLICON equ 0002h
        LVS_LIST equ 0003h
        LVS_TYPEMASK equ 0003h
        LVS_SINGLESEL equ 0004h
        LVS_SHOWSELALWAYS equ 0008h
        LVS_SORTASCENDING equ 0010h
        LVS_SORTDESCENDING equ 0020h
        LVS_SHAREIMAGELISTS equ 0040h
        LVS_NOLABELWRAP equ 0080h
        LVS_AUTOARRANGE equ 0100h
        LVS_EDITLABELS equ 0200h
        LVS_OWNERDATA equ 1000h
        LVS_NOSCROLL equ 2000h
        LVS_TYPESTYLEMASK equ 0fc00h
        LVS_ALIGNTOP equ 0000h
        LVS_ALIGNLEFT equ 0800h
        LVS_ALIGNMASK equ 0c00h
        LVS_OWNERDRAWFIXED equ 0400h
        LVS_NOCOLUMNHEADER equ 4000h
        LVS_NOSORTHEADER equ 8000h
        ; end_r_commctrl
        LVM_SETUNICODEFORMAT equ <CCM_SETUNICODEFORMAT>
        ListView_SetUnicodeFormat macro hwnd, fUnicode
          exitm <SNDMSG ((hwnd), LVM_SETUNICODEFORMAT, (fUnicode), 0)>
        endm
        LVM_GETUNICODEFORMAT equ <CCM_GETUNICODEFORMAT>
        ListView_GetUnicodeFormat macro hwnd
          exitm <SNDMSG ((hwnd), LVM_GETUNICODEFORMAT, 0, 0)>
        endm
        LVM_GETBKCOLOR equ (LVM_FIRST + 0)
        ListView_GetBkColor macro hwnd
          exitm <SNDMSG ((hwnd), LVM_GETBKCOLOR, 0, 0)>
        endm
        LVM_SETBKCOLOR equ (LVM_FIRST + 1)
        ListView_SetBkColor macro hwnd, clrBk
          exitm <SNDMSG ((hwnd), LVM_SETBKCOLOR, 0, (clrBk))>
        endm
        LVM_GETIMAGELIST equ (LVM_FIRST + 2)
        ListView_GetImageList macro hwnd, iImageList
          exitm <SNDMSG ((hwnd), LVM_GETIMAGELIST, (INT) (iImageList), 0)>
        endm
        LVSIL_NORMAL equ 0
        LVSIL_SMALL equ 1
        LVSIL_STATE equ 2
        LVSIL_GROUPHEADER equ 3
        LVM_SETIMAGELIST equ (LVM_FIRST + 3)
        ListView_SetImageList macro hwnd, himl, iImageList
          exitm <SNDMSG ((hwnd), LVM_SETIMAGELIST, (iImageList), (himl))>
        endm
        LVM_GETITEMCOUNT equ (LVM_FIRST + 4)
        ListView_GetItemCount macro hwnd
          exitm <SNDMSG ((hwnd), LVM_GETITEMCOUNT, 0, 0)>
        endm
        LVIF_TEXT equ 00000001h
        LVIF_IMAGE equ 00000002h
        LVIF_PARAM equ 00000004h
        LVIF_STATE equ 00000008h
        LVIF_INDENT equ 00000010h
        LVIF_NORECOMPUTE equ 00000800h
        if (NTDDI_VERSION ge NTDDI_WINXP)
          LVIF_GROUPID equ 00000100h
          LVIF_COLUMNS equ 00000200h
        endif
        if (NTDDI_VERSION ge NTDDI_VISTA)
          LVIF_COLFMT equ 00010000h; The piColFmt member is valid in addition to puColumns

        endif
        LVIS_FOCUSED equ 0001h
        LVIS_SELECTED equ 0002h
        LVIS_CUT equ 0004h
        LVIS_DROPHILITED equ 0008h
        LVIS_GLOW equ 0010h
        LVIS_ACTIVATING equ 0020h
        LVIS_OVERLAYMASK equ 0F00h
        LVIS_STATEIMAGEMASK equ 0F000h
        INDEXTOSTATEIMAGEMASK macro i
          exitm <((i) shl 12)>
        endm
        I_INDENTCALLBACK equ (- 1)
        LV_ITEMA equ <LVITEMA>
        LV_ITEMW equ <LVITEMW>
        if (NTDDI_VERSION ge NTDDI_WINXP)
          I_GROUPIDCALLBACK equ (- 1)
          I_GROUPIDNONE equ (- 2)
        endif
        LV_ITEM equ <LVITEM>
        LVITEMA_V1_SIZE equ <CCSIZEOF_STRUCT(LVITEMA, lParam)>
        LVITEMW_V1_SIZE equ <CCSIZEOF_STRUCT(LVITEMW, lParam)>
        if (NTDDI_VERSION ge NTDDI_VISTA)
          ; Will be unused downlevel, but sizeof(LVITEMA) must be equal to sizeof(LVITEMW)
          LVITEMA_V5_SIZE equ <CCSIZEOF_STRUCT(LVITEMA, puColumns)>
          LVITEMW_V5_SIZE equ <CCSIZEOF_STRUCT(LVITEMW, puColumns)>
          ifdef UNICODE
            LVITEM_V5_SIZE equ <LVITEMW_V5_SIZE>
          else
            LVITEM_V5_SIZE equ <LVITEMA_V5_SIZE>
          endif
        endif
        ; Will be unused downlevel, but sizeof(LVITEMA) must be equal to sizeof(LVITEMW)
        LVITEMA struct
          mask_ DWORD ?
          iItem SDWORD ?
          iSubItem SDWORD ?
          state DWORD ?
          stateMask DWORD ?
          pszText POINTER ?
          cchTextMax SDWORD ?
          iImage SDWORD ?
          lParam LPARAM ?
          iIndent SDWORD ?
          if (NTDDI_VERSION ge NTDDI_WINXP)
            iGroupId SDWORD ?
            cColumns DWORD ?
            ; tile view columns
            puColumns PUINT ?
          endif
          if (NTDDI_VERSION ge NTDDI_VISTA)
            piColFmt POINTER ?
            ; Will be unused downlevel, but sizeof(LVITEMA) must be equal to sizeof(LVITEMW)
            iGroup SDWORD ?
            ; readonly. only valid for owner data.
          endif
        LVITEMA ends
        tagLVITEMA typedef LVITEMA
        LPLVITEMA typedef ptr LVITEMA
        LVITEMW struct
          mask_ DWORD ?
          iItem SDWORD ?
          iSubItem SDWORD ?
          state DWORD ?
          stateMask DWORD ?
          pszText POINTER ?
          cchTextMax SDWORD ?
          iImage SDWORD ?
          lParam LPARAM ?
          iIndent SDWORD ?
          if (NTDDI_VERSION ge NTDDI_WINXP)
            iGroupId SDWORD ?
            cColumns DWORD ?
            ; tile view columns
            puColumns PUINT ?
          endif
          if (NTDDI_VERSION ge NTDDI_VISTA)
            piColFmt POINTER ?
            iGroup SDWORD ?
            ; readonly. only valid for owner data.
          endif
        LVITEMW ends
        tagLVITEMW typedef LVITEMW
        LPLVITEMW typedef ptr LVITEMW
        ifdef UNICODE
          LVITEM equ <LVITEMW>
          LPLVITEM equ <LPLVITEMW>
          LVITEM_V1_SIZE equ <LVITEMW_V1_SIZE>
        else
          LVITEM equ <LVITEMA>
          LPLVITEM equ <LPLVITEMA>
          LVITEM_V1_SIZE equ <LVITEMA_V1_SIZE>
        endif
        LPSTR_TEXTCALLBACKW equ (- 1)
        LPSTR_TEXTCALLBACKA equ (- 1)
        ifdef UNICODE
          LPSTR_TEXTCALLBACK equ <LPSTR_TEXTCALLBACKW>
        else
          LPSTR_TEXTCALLBACK equ <LPSTR_TEXTCALLBACKA>
        endif
        I_IMAGECALLBACK equ (- 1)
        I_IMAGENONE equ (- 2)
        if (NTDDI_VERSION ge NTDDI_WINXP)
          ; For tileview
          I_COLUMNSCALLBACK equ (- 1)
        endif
        LVM_GETITEMA equ (LVM_FIRST + 5)
        LVM_GETITEMW equ (LVM_FIRST + 75)
        ifdef UNICODE
          LVM_GETITEM equ <LVM_GETITEMW>
        else
          LVM_GETITEM equ <LVM_GETITEMA>
        endif
        ListView_GetItem macro hwnd, pitem
          exitm <SNDMSG ((hwnd), LVM_GETITEM, 0, (LV_ITEM *) (pitem))>
        endm
        LVM_SETITEMA equ (LVM_FIRST + 6)
        LVM_SETITEMW equ (LVM_FIRST + 76)
        ifdef UNICODE
          LVM_SETITEM equ <LVM_SETITEMW>
        else
          LVM_SETITEM equ <LVM_SETITEMA>
        endif
        ListView_SetItem macro hwnd, pitem
          exitm <SNDMSG ((hwnd), LVM_SETITEM, 0, (const LV_ITEM *) (pitem))>
        endm
        LVM_INSERTITEMA equ (LVM_FIRST + 7)
        LVM_INSERTITEMW equ (LVM_FIRST + 77)
        ifdef UNICODE
          LVM_INSERTITEM equ <LVM_INSERTITEMW>
        else
          LVM_INSERTITEM equ <LVM_INSERTITEMA>
        endif
        ListView_InsertItem macro hwnd, pitem
          exitm <SNDMSG ((hwnd), LVM_INSERTITEM, 0, (const LV_ITEM *) (pitem))>
        endm
        LVM_DELETEITEM equ (LVM_FIRST + 8)
        ListView_DeleteItem macro hwnd, i
          exitm <SNDMSG ((hwnd), LVM_DELETEITEM, (i), 0)>
        endm
        LVM_DELETEALLITEMS equ (LVM_FIRST + 9)
        ListView_DeleteAllItems macro hwnd
          exitm <SNDMSG ((hwnd), LVM_DELETEALLITEMS, 0, 0)>
        endm
        LVM_GETCALLBACKMASK equ (LVM_FIRST + 10)
        ListView_GetCallbackMask macro hwnd
          exitm <SNDMSG ((hwnd), LVM_GETCALLBACKMASK, 0, 0)>
        endm
        LVM_SETCALLBACKMASK equ (LVM_FIRST + 11)
        ListView_SetCallbackMask macro hwnd, mask_
          exitm <SNDMSG ((hwnd), LVM_SETCALLBACKMASK, (mask_), 0)>
        endm
        LVNI_ALL equ 0000h
        LVNI_FOCUSED equ 0001h
        LVNI_SELECTED equ 0002h
        LVNI_CUT equ 0004h
        LVNI_DROPHILITED equ 0008h
        LVNI_STATEMASK equ <(LVNI_FOCUSED or LVNI_SELECTED or LVNI_CUT or LVNI_DROPHILITED)>
        LVNI_VISIBLEORDER equ 0010h
        LVNI_PREVIOUS equ 0020h
        LVNI_VISIBLEONLY equ 0040h
        LVNI_SAMEGROUPONLY equ 0080h
        LVNI_ABOVE equ 0100h
        LVNI_BELOW equ 0200h
        LVNI_TOLEFT equ 0400h
        LVNI_TORIGHT equ 0800h
        LVNI_DIRECTIONMASK equ <(LVNI_ABOVE or LVNI_BELOW or LVNI_TOLEFT or LVNI_TORIGHT)>
        LVM_GETNEXTITEM equ (LVM_FIRST + 12)
        ListView_GetNextItem macro hwnd, i, flags
          exitm <SNDMSG ((hwnd), LVM_GETNEXTITEM, (i), MAKELPARAM((flags), 0))>
        endm
        LVFI_PARAM equ 0001h
        LVFI_STRING equ 0002h
        LVFI_SUBSTRING equ 0004h; Same as LVFI_PARTIAL

        LVFI_PARTIAL equ 0008h
        LVFI_WRAP equ 0020h
        LVFI_NEARESTXY equ 0040h
        LV_FINDINFOA equ <LVFINDINFOA>
        LV_FINDINFOW equ <LVFINDINFOW>
        LV_FINDINFO equ <LVFINDINFO>
        LVFINDINFOA struct
          flags DWORD ?
          psz =POINTER ?
          lParam LPARAM ?
          pt POINT <>
          vkDirection DWORD ?
        LVFINDINFOA ends
        tagLVFINDINFOA typedef LVFINDINFOA
        LPFINDINFOA typedef ptr LVFINDINFOA
        LVFINDINFOW struct
          flags DWORD ?
          psz =POINTER ?
          lParam LPARAM ?
          pt POINT <>
          vkDirection DWORD ?
        LVFINDINFOW ends
        tagLVFINDINFOW typedef LVFINDINFOW
        LPFINDINFOW typedef ptr LVFINDINFOW
        ifdef UNICODE
          LVFINDINFO equ <LVFINDINFOW>
        else
          LVFINDINFO equ <LVFINDINFOA>
        endif
        LVM_FINDITEMA equ (LVM_FIRST + 13)
        LVM_FINDITEMW equ (LVM_FIRST + 83)
        ifdef UNICODE
          LVM_FINDITEM equ <LVM_FINDITEMW>
        else
          LVM_FINDITEM equ <LVM_FINDITEMA>
        endif
        ListView_FindItem macro hwnd, iStart, plvfi
          exitm <SNDMSG ((hwnd), LVM_FINDITEM, (iStart), (const LV_FINDINFO *) (plvfi))>
        endm
        LVIR_BOUNDS equ 0
        LVIR_ICON equ 1
        LVIR_LABEL equ 2
        LVIR_SELECTBOUNDS equ 3
        LVM_GETITEMRECT equ (LVM_FIRST + 14)
        ListView_GetItemRect macro hwnd, i, prc, code
          exitm <SNDMSG ((hwnd), LVM_GETITEMRECT, (i), ((prc) ? (((RECT *) (prc)) - left = (code), (RECT *) (prc)) : (RECT *) NULL))>
        endm
        LVM_SETITEMPOSITION equ (LVM_FIRST + 15)
        ListView_SetItemPosition macro hwndLV, i, x, y
          exitm <SNDMSG ((hwndLV), LVM_SETITEMPOSITION, (i), MAKELPARAM((x), (y)))>
        endm
        LVM_GETITEMPOSITION equ (LVM_FIRST + 16)
        ListView_GetItemPosition macro hwndLV, i, ppt
          exitm <SNDMSG ((hwndLV), LVM_GETITEMPOSITION, (i), (POINT *) (ppt))>
        endm
        LVM_GETSTRINGWIDTHA equ (LVM_FIRST + 17)
        LVM_GETSTRINGWIDTHW equ (LVM_FIRST + 87)
        ifdef UNICODE
          LVM_GETSTRINGWIDTH equ <LVM_GETSTRINGWIDTHW>
        else
          LVM_GETSTRINGWIDTH equ <LVM_GETSTRINGWIDTHA>
        endif
        ListView_GetStringWidth macro hwndLV, psz
          exitm <SNDMSG ((hwndLV), LVM_GETSTRINGWIDTH, 0, (LPCTSTR) (psz))>
        endm
        LVHT_NOWHERE equ 00000001h
        LVHT_ONITEMICON equ 00000002h
        LVHT_ONITEMLABEL equ 00000004h
        LVHT_ONITEMSTATEICON equ 00000008h
        LVHT_ONITEM equ <(LVHT_ONITEMICON or LVHT_ONITEMLABEL or LVHT_ONITEMSTATEICON)>
        LVHT_ABOVE equ 00000008h
        LVHT_BELOW equ 00000010h
        LVHT_TORIGHT equ 00000020h
        LVHT_TOLEFT equ 00000040h
        LVHT_EX_GROUP_HEADER equ 10000000h
        LVHT_EX_GROUP_FOOTER equ 20000000h
        LVHT_EX_GROUP_COLLAPSE equ 40000000h
        LVHT_EX_GROUP_BACKGROUND equ 80000000h
        LVHT_EX_GROUP_STATEICON equ 01000000h
        LVHT_EX_GROUP_SUBSETLINK equ 02000000h
        LVHT_EX_GROUP equ <(LVHT_EX_GROUP_BACKGROUND or LVHT_EX_GROUP_COLLAPSE or LVHT_EX_GROUP_FOOTER or LVHT_EX_GROUP_HEADER or LVHT_EX_GROUP_STATEICON or LVHT_EX_GROUP_SUBSETLINK)>
        LVHT_EX_ONCONTENTS equ 04000000h; On item AND not on the background

        LVHT_EX_FOOTER equ 08000000h
        LV_HITTESTINFO equ <LVHITTESTINFO>
        LVHITTESTINFO_V1_SIZE equ <CCSIZEOF_STRUCT(LVHITTESTINFO, iItem)>
        LVHITTESTINFO struct
          pt POINT <>
          flags DWORD ?
          iItem SDWORD ?
          iSubItem SDWORD ?
          ; this is was NOT in win95.  valid only for LVM_SUBITEMHITTEST
          if (NTDDI_VERSION ge NTDDI_VISTA)
            iGroup SDWORD ?
            ; readonly. index of group. only valid for owner data.
            ; supports single item in multiple groups.
          endif
        LVHITTESTINFO ends
        tagLVHITTESTINFO typedef LVHITTESTINFO
        LPLVHITTESTINFO typedef ptr LVHITTESTINFO
        LVM_HITTEST equ (LVM_FIRST + 18)
        ListView_HitTest macro hwndLV, pinfo
          exitm <SNDMSG ((hwndLV), LVM_HITTEST, 0, (LV_HITTESTINFO *) (pinfo))>
        endm
        ListView_HitTestEx macro hwndLV, pinfo
          exitm <SNDMSG ((hwndLV), LVM_HITTEST, - 1, (LV_HITTESTINFO *) (pinfo))>
        endm
        LVM_ENSUREVISIBLE equ (LVM_FIRST + 19)
        ListView_EnsureVisible macro hwndLV, i, fPartialOK
          exitm <SNDMSG ((hwndLV), LVM_ENSUREVISIBLE, (i), MAKELPARAM((fPartialOK), 0))>
        endm
        LVM_SCROLL equ (LVM_FIRST + 20)
        ListView_Scroll macro hwndLV, dx_, dy
          exitm <SNDMSG ((hwndLV), LVM_SCROLL, (dx_), (dy))>
        endm
        LVM_REDRAWITEMS equ (LVM_FIRST + 21)
        ListView_RedrawItems macro hwndLV, iFirst, iLast
          exitm <SNDMSG ((hwndLV), LVM_REDRAWITEMS, (iFirst), (iLast))>
        endm
        LVA_DEFAULT equ 0000h
        LVA_ALIGNLEFT equ 0001h
        LVA_ALIGNTOP equ 0002h
        LVA_SNAPTOGRID equ 0005h
        LVM_ARRANGE equ (LVM_FIRST + 22)
        ListView_Arrange macro hwndLV, code
          exitm <SNDMSG ((hwndLV), LVM_ARRANGE, (code), 0)>
        endm
        LVM_EDITLABELA equ (LVM_FIRST + 23)
        LVM_EDITLABELW equ (LVM_FIRST + 118)
        ifdef UNICODE
          LVM_EDITLABEL equ <LVM_EDITLABELW>
        else
          LVM_EDITLABEL equ <LVM_EDITLABELA>
        endif
        ListView_EditLabel macro hwndLV, i
          exitm <SNDMSG ((hwndLV), LVM_EDITLABEL, (i), 0)>
        endm
        LVM_GETEDITCONTROL equ (LVM_FIRST + 24)
        ListView_GetEditControl macro hwndLV
          exitm <SNDMSG ((hwndLV), LVM_GETEDITCONTROL, 0, 0)>
        endm
        LV_COLUMNA equ <LVCOLUMNA>
        LV_COLUMNW equ <LVCOLUMNW>
        LV_COLUMN equ <LVCOLUMN>
        LVCOLUMNA_V1_SIZE equ <CCSIZEOF_STRUCT(LVCOLUMNA, iSubItem)>
        LVCOLUMNW_V1_SIZE equ <CCSIZEOF_STRUCT(LVCOLUMNW, iSubItem)>
        LVCOLUMNA struct
          mask_ DWORD ?
          fmt SDWORD ?
          cx_ SDWORD ?
          pszText POINTER ?
          cchTextMax SDWORD ?
          iSubItem SDWORD ?
          iImage SDWORD ?
          iOrder SDWORD ?
          if (NTDDI_VERSION ge NTDDI_VISTA)
            cxMin SDWORD ?
            ; min snap point
            cxDefault SDWORD ?
            ; default snap point
            cxIdeal SDWORD ?
            ; read only. ideal may not eqaul current width if auto sized (LVS_EX_AUTOSIZECOLUMNS) to a lesser width.
          endif
        LVCOLUMNA ends
        tagLVCOLUMNA typedef LVCOLUMNA
        LPLVCOLUMNA typedef ptr LVCOLUMNA
        LVCOLUMNW struct
          mask_ DWORD ?
          fmt SDWORD ?
          cx_ SDWORD ?
          pszText POINTER ?
          cchTextMax SDWORD ?
          iSubItem SDWORD ?
          iImage SDWORD ?
          iOrder SDWORD ?
          if (NTDDI_VERSION ge NTDDI_VISTA)
            cxMin SDWORD ?
            ; min snap point
            cxDefault SDWORD ?
            ; default snap point
            cxIdeal SDWORD ?
            ; read only. ideal may not eqaul current width if auto sized (LVS_EX_AUTOSIZECOLUMNS) to a lesser width.
          endif
        LVCOLUMNW ends
        tagLVCOLUMNW typedef LVCOLUMNW
        LPLVCOLUMNW typedef ptr LVCOLUMNW
        ifdef UNICODE
          LVCOLUMN equ <LVCOLUMNW>
          LPLVCOLUMN equ <LPLVCOLUMNW>
          LVCOLUMN_V1_SIZE equ <LVCOLUMNW_V1_SIZE>
        else
          LVCOLUMN equ <LVCOLUMNA>
          LPLVCOLUMN equ <LPLVCOLUMNA>
          LVCOLUMN_V1_SIZE equ <LVCOLUMNA_V1_SIZE>
        endif
        LVCF_FMT equ 0001h
        LVCF_WIDTH equ 0002h
        LVCF_TEXT equ 0004h
        LVCF_SUBITEM equ 0008h
        LVCF_IMAGE equ 0010h
        LVCF_ORDER equ 0020h
        if (NTDDI_VERSION ge NTDDI_VISTA)
          LVCF_MINWIDTH equ 0040h
          LVCF_DEFAULTWIDTH equ 0080h
          LVCF_IDEALWIDTH equ 0100h
        endif
        ; LVCFMT_ flags up to FFFF are shared with the header control (HDF_ flags).
        ; Flags above FFFF are listview-specific.
        LVCFMT_LEFT equ 0000h; Same as HDF_LEFT

        LVCFMT_RIGHT equ 0001h; Same as HDF_RIGHT

        LVCFMT_CENTER equ 0002h; Same as HDF_CENTER

        LVCFMT_JUSTIFYMASK equ 0003h; Same as HDF_JUSTIFYMASK

        LVCFMT_IMAGE equ 0800h; Same as HDF_IMAGE

        LVCFMT_BITMAP_ON_RIGHT equ 1000h; Same as HDF_BITMAP_ON_RIGHT

        LVCFMT_COL_HAS_IMAGES equ 8000h; Same as HDF_OWNERDRAW

        if (NTDDI_VERSION ge NTDDI_VISTA)
          LVCFMT_FIXED_WIDTH equ 00100h; Can't resize the column; same as HDF_FIXEDWIDTH

          LVCFMT_NO_DPI_SCALE equ 40000h; If not set, CCM_DPISCALE will govern scaling up fixed width

          LVCFMT_FIXED_RATIO equ 80000h; Width will augment with the row height

          ; The following flags
          LVCFMT_LINE_BREAK equ 100000h; Move to the top of the next list of columns

          LVCFMT_FILL equ 200000h; Fill the remainder of the tile area. Might have a title.

          LVCFMT_WRAP equ 400000h; This sub-item can be wrapped.

          LVCFMT_NO_TITLE equ 800000h; This sub-item doesn't have an title.

          LVCFMT_TILE_PLACEMENTMASK equ <(LVCFMT_LINE_BREAK or LVCFMT_FILL)>
          LVCFMT_SPLITBUTTON equ 1000000h; Column is a split button; same as HDF_SPLITBUTTON

        endif
        LVM_GETCOLUMNA equ (LVM_FIRST + 25)
        LVM_GETCOLUMNW equ (LVM_FIRST + 95)
        ifdef UNICODE
          LVM_GETCOLUMN equ <LVM_GETCOLUMNW>
        else
          LVM_GETCOLUMN equ <LVM_GETCOLUMNA>
        endif
        ListView_GetColumn macro hwnd, iCol, pcol
          exitm <SNDMSG ((hwnd), LVM_GETCOLUMN, (iCol), (LV_COLUMN *) (pcol))>
        endm
        LVM_SETCOLUMNA equ (LVM_FIRST + 26)
        LVM_SETCOLUMNW equ (LVM_FIRST + 96)
        ifdef UNICODE
          LVM_SETCOLUMN equ <LVM_SETCOLUMNW>
        else
          LVM_SETCOLUMN equ <LVM_SETCOLUMNA>
        endif
        ListView_SetColumn macro hwnd, iCol, pcol
          exitm <SNDMSG ((hwnd), LVM_SETCOLUMN, (iCol), (const LV_COLUMN *) (pcol))>
        endm
        LVM_INSERTCOLUMNA equ (LVM_FIRST + 27)
        LVM_INSERTCOLUMNW equ (LVM_FIRST + 97)
        ifdef UNICODE
          LVM_INSERTCOLUMN equ <LVM_INSERTCOLUMNW>
        else
          LVM_INSERTCOLUMN equ <LVM_INSERTCOLUMNA>
        endif
        ListView_InsertColumn macro hwnd, iCol, pcol
          exitm <SNDMSG ((hwnd), LVM_INSERTCOLUMN, (iCol), (const LV_COLUMN *) (pcol))>
        endm
        LVM_DELETECOLUMN equ (LVM_FIRST + 28)
        ListView_DeleteColumn macro hwnd, iCol
          exitm <SNDMSG ((hwnd), LVM_DELETECOLUMN, (iCol), 0)>
        endm
        LVM_GETCOLUMNWIDTH equ (LVM_FIRST + 29)
        ListView_GetColumnWidth macro hwnd, iCol
          exitm <SNDMSG ((hwnd), LVM_GETCOLUMNWIDTH, (iCol), 0)>
        endm
        LVSCW_AUTOSIZE equ -1
        LVSCW_AUTOSIZE_USEHEADER equ -2
        LVM_SETCOLUMNWIDTH equ (LVM_FIRST + 30)
        ListView_SetColumnWidth macro hwnd, iCol, cx_
          exitm <SNDMSG ((hwnd), LVM_SETCOLUMNWIDTH, (iCol), MAKELPARAM((cx_), 0))>
        endm
        LVM_GETHEADER equ (LVM_FIRST + 31)
        ListView_GetHeader macro hwnd
          exitm <SNDMSG ((hwnd), LVM_GETHEADER, 0, 0)>
        endm
        LVM_CREATEDRAGIMAGE equ (LVM_FIRST + 33)
        ListView_CreateDragImage macro hwnd, i, lpptUpLeft
          exitm <SNDMSG ((hwnd), LVM_CREATEDRAGIMAGE, (i), (LPPOINT) (lpptUpLeft))>
        endm
        LVM_GETVIEWRECT equ (LVM_FIRST + 34)
        ListView_GetViewRect macro hwnd, prc
          exitm <SNDMSG ((hwnd), LVM_GETVIEWRECT, 0, (RECT *) (prc))>
        endm
        LVM_GETTEXTCOLOR equ (LVM_FIRST + 35)
        ListView_GetTextColor macro hwnd
          exitm <SNDMSG ((hwnd), LVM_GETTEXTCOLOR, 0, 0)>
        endm
        LVM_SETTEXTCOLOR equ (LVM_FIRST + 36)
        ListView_SetTextColor macro hwnd, clrText
          exitm <SNDMSG ((hwnd), LVM_SETTEXTCOLOR, 0, (clrText))>
        endm
        LVM_GETTEXTBKCOLOR equ (LVM_FIRST + 37)
        ListView_GetTextBkColor macro hwnd
          exitm <SNDMSG ((hwnd), LVM_GETTEXTBKCOLOR, 0, 0)>
        endm
        LVM_SETTEXTBKCOLOR equ (LVM_FIRST + 38)
        ListView_SetTextBkColor macro hwnd, clrTextBk
          exitm <SNDMSG ((hwnd), LVM_SETTEXTBKCOLOR, 0, (clrTextBk))>
        endm
        LVM_GETTOPINDEX equ (LVM_FIRST + 39)
        ListView_GetTopIndex macro hwndLV
          exitm <SNDMSG ((hwndLV), LVM_GETTOPINDEX, 0, 0)>
        endm
        LVM_GETCOUNTPERPAGE equ (LVM_FIRST + 40)
        ListView_GetCountPerPage macro hwndLV
          exitm <SNDMSG ((hwndLV), LVM_GETCOUNTPERPAGE, 0, 0)>
        endm
        LVM_GETORIGIN equ (LVM_FIRST + 41)
        ListView_GetOrigin macro hwndLV, ppt
          exitm <SNDMSG ((hwndLV), LVM_GETORIGIN, 0, (POINT *) (ppt))>
        endm
        LVM_UPDATE equ (LVM_FIRST + 42)
        ListView_Update macro hwndLV, i
          exitm <SNDMSG ((hwndLV), LVM_UPDATE, (i), 0)>
        endm
        LVM_SETITEMSTATE equ (LVM_FIRST + 43)
        ListView_SetItemState macro hwndLV, i, data, mask_
          exitm <{ LV_ITEM _macro_lvi ; _macro_lvi.stateMask = (mask_) ; _macro_lvi.state = (data) ; SNDMSG ((hwndLV), LVM_SETITEMSTATE, (i), (LV_ITEM *) and _macro_lvi) ; }>
        endm
        ListView_SetCheckState macro hwndLV, i, fCheck
          exitm <ListView_SetItemState(hwndLV, i, INDEXTOSTATEIMAGEMASK((fCheck) ?2 : 1), LVIS_STATEIMAGEMASK)>
        endm
        LVM_GETITEMSTATE equ (LVM_FIRST + 44)
        ListView_GetItemState macro hwndLV, i, mask_
          exitm <SNDMSG ((hwndLV), LVM_GETITEMSTATE, (i), (mask_))>
        endm
        ListView_GetCheckState macro hwndLV, i
          exitm <((((SNDMSG ((hwndLV), LVM_GETITEMSTATE, (i), LVIS_STATEIMAGEMASK))) shr 12) - 1)>
        endm
        LVM_GETITEMTEXTA equ (LVM_FIRST + 45)
        LVM_GETITEMTEXTW equ (LVM_FIRST + 115)
        ifdef UNICODE
          LVM_GETITEMTEXT equ <LVM_GETITEMTEXTW>
        else
          LVM_GETITEMTEXT equ <LVM_GETITEMTEXTA>
        endif
        ListView_GetItemText macro hwndLV, i, iSubItem_, pszText_, cchTextMax_
          exitm <{ LV_ITEM _macro_lvi ; _macro_lvi.iSubItem = (iSubItem_) ; _macro_lvi.cchTextMax = (cchTextMax_) ; _macro_lvi.pszText = (pszText_) ; SNDMSG ((hwndLV), LVM_GETITEMTEXT, (i), (LV_ITEM *) and _macro_lvi) ; }>
        endm
        LVM_SETITEMTEXTA equ (LVM_FIRST + 46)
        LVM_SETITEMTEXTW equ (LVM_FIRST + 116)
        ifdef UNICODE
          LVM_SETITEMTEXT equ <LVM_SETITEMTEXTW>
        else
          LVM_SETITEMTEXT equ <LVM_SETITEMTEXTA>
        endif
        ListView_SetItemText macro hwndLV, i, iSubItem_, pszText_
          exitm <{ LV_ITEM _macro_lvi ; _macro_lvi.iSubItem = (iSubItem_) ; _macro_lvi.pszText = (pszText_) ; SNDMSG ((hwndLV), LVM_SETITEMTEXT, (i), (LV_ITEM *) and _macro_lvi) ; }>
        endm
        ; these flags only apply to LVS_OWNERDATA listviews in report or list mode
        LVSICF_NOINVALIDATEALL equ 00000001h
        LVSICF_NOSCROLL equ 00000002h
        LVM_SETITEMCOUNT equ (LVM_FIRST + 47)
        ListView_SetItemCount macro hwndLV, cItems
          exitm <SNDMSG ((hwndLV), LVM_SETITEMCOUNT, (cItems), 0)>
        endm
        ListView_SetItemCountEx macro hwndLV, cItems, dwFlags
          exitm <SNDMSG ((hwndLV), LVM_SETITEMCOUNT, (cItems), (dwFlags))>
        endm
        TYPE_PFNLVCOMPARE typedef proto WIN_STD_CALL_CONV :LPARAM, :LPARAM, :LPARAM
        PFNLVCOMPARE typedef ptr TYPE_PFNLVCOMPARE

        LVM_SORTITEMS equ (LVM_FIRST + 48)
        ListView_SortItems macro hwndLV, _pfnCompare, _lPrm
          exitm <SNDMSG ((hwndLV), LVM_SORTITEMS, (_lPrm), (PFNLVCOMPARE) (_pfnCompare))>
        endm
        LVM_SETITEMPOSITION32 equ (LVM_FIRST + 49)
        ListView_SetItemPosition32 macro hwndLV, i, x0, y0
          exitm <{ POINT ptNewPos ; ptNewPos.x = (x0) ; ptNewPos.y = (y0) ; SNDMSG ((hwndLV), LVM_SETITEMPOSITION32, (i), and ptNewPos) ; }>
        endm
        LVM_GETSELECTEDCOUNT equ (LVM_FIRST + 50)
        ListView_GetSelectedCount macro hwndLV
          exitm <SNDMSG ((hwndLV), LVM_GETSELECTEDCOUNT, 0, 0)>
        endm
        LVM_GETITEMSPACING equ (LVM_FIRST + 51)
        ListView_GetItemSpacing macro hwndLV, fSmall
          exitm <SNDMSG ((hwndLV), LVM_GETITEMSPACING, fSmall, 0)>
        endm
        LVM_GETISEARCHSTRINGA equ (LVM_FIRST + 52)
        LVM_GETISEARCHSTRINGW equ (LVM_FIRST + 117)
        ifdef UNICODE
          LVM_GETISEARCHSTRING equ <LVM_GETISEARCHSTRINGW>
        else
          LVM_GETISEARCHSTRING equ <LVM_GETISEARCHSTRINGA>
        endif
        ListView_GetISearchString macro hwndLV, lpsz
          exitm <SNDMSG ((hwndLV), LVM_GETISEARCHSTRING, 0, (LPTSTR) (lpsz))>
        endm
        LVM_SETICONSPACING equ (LVM_FIRST + 53)
        ; -1 for cx and cy means we'll use the default (system settings)
        ; 0 for cx or cy means use the current setting (allows you to change just one param)
        ListView_SetIconSpacing macro hwndLV, cx_, cy
          exitm <SNDMSG ((hwndLV), LVM_SETICONSPACING, 0, MAKELONG(cx_, cy))>
        endm
        LVM_SETEXTENDEDLISTVIEWSTYLE equ (LVM_FIRST + 54); optional wParam == mask

        ListView_SetExtendedListViewStyle macro hwndLV, dw_
          exitm <SNDMSG ((hwndLV), LVM_SETEXTENDEDLISTVIEWSTYLE, 0, dw_)>
        endm
        ListView_SetExtendedListViewStyleEx macro hwndLV, dwMask, dw_
          exitm <SNDMSG ((hwndLV), LVM_SETEXTENDEDLISTVIEWSTYLE, dwMask, dw_)>
        endm
        LVM_GETEXTENDEDLISTVIEWSTYLE equ (LVM_FIRST + 55)
        ListView_GetExtendedListViewStyle macro hwndLV
          exitm <SNDMSG ((hwndLV), LVM_GETEXTENDEDLISTVIEWSTYLE, 0, 0)>
        endm
        LVS_EX_GRIDLINES equ 00000001h
        LVS_EX_SUBITEMIMAGES equ 00000002h
        LVS_EX_CHECKBOXES equ 00000004h
        LVS_EX_TRACKSELECT equ 00000008h
        LVS_EX_HEADERDRAGDROP equ 00000010h
        LVS_EX_FULLROWSELECT equ 00000020h; applies to report mode only

        LVS_EX_ONECLICKACTIVATE equ 00000040h
        LVS_EX_TWOCLICKACTIVATE equ 00000080h
        LVS_EX_FLATSB equ 00000100h
        LVS_EX_REGIONAL equ 00000200h
        LVS_EX_INFOTIP equ 00000400h; listview does InfoTips for you

        LVS_EX_UNDERLINEHOT equ 00000800h
        LVS_EX_UNDERLINECOLD equ 00001000h
        LVS_EX_MULTIWORKAREAS equ 00002000h
        LVS_EX_LABELTIP equ 00004000h; listview unfolds partly hidden labels if it does not have infotip text

        LVS_EX_BORDERSELECT equ 00008000h; border selection style instead of highlight

        if (NTDDI_VERSION ge NTDDI_WINXP)
          LVS_EX_DOUBLEBUFFER equ 00010000h
          LVS_EX_HIDELABELS equ 00020000h
          LVS_EX_SINGLEROW equ 00040000h
          LVS_EX_SNAPTOGRID equ 00080000h; Icons automatically snap to grid.

          LVS_EX_SIMPLESELECT equ 00100000h; Also changes overlay rendering to top right for icon mode.

        endif
        if (NTDDI_VERSION ge NTDDI_VISTA)
          LVS_EX_JUSTIFYCOLUMNS equ 00200000h; Icons are lined up in columns that use up the whole view area.

          LVS_EX_TRANSPARENTBKGND equ 00400000h; Background is painted by the parent via WM_PRINTCLIENT

          LVS_EX_TRANSPARENTSHADOWTEXT equ 00800000h; Enable shadow text on transparent backgrounds only (useful with bitmaps)

          LVS_EX_AUTOAUTOARRANGE equ 01000000h; Icons automatically arrange if no icon positions have been set

          LVS_EX_HEADERINALLVIEWS equ 02000000h; Display column header in all view modes

          LVS_EX_AUTOCHECKSELECT equ 08000000h
          LVS_EX_AUTOSIZECOLUMNS equ 10000000h
          LVS_EX_COLUMNSNAPPOINTS equ 40000000h
          LVS_EX_COLUMNOVERFLOW equ 80000000h
        endif
        LVM_GETSUBITEMRECT equ (LVM_FIRST + 56)
        ListView_GetSubItemRect macro hwnd, iItem, iSubItem, code, prc
          exitm <SNDMSG ((hwnd), LVM_GETSUBITEMRECT, (iItem), ((prc) ? ((((LPRECT) (prc)) - top = (iSubItem)), (((LPRECT) (prc)) - left = (code)), (prc)) : (LPRECT) NULL))>
        endm
        LVM_SUBITEMHITTEST equ (LVM_FIRST + 57)
        ListView_SubItemHitTest macro hwnd, plvhti
          exitm <SNDMSG ((hwnd), LVM_SUBITEMHITTEST, 0, (LPLVHITTESTINFO) (plvhti))>
        endm
        ListView_SubItemHitTestEx macro hwnd, plvhti
          exitm <SNDMSG ((hwnd), LVM_SUBITEMHITTEST, - 1, (LPLVHITTESTINFO) (plvhti))>
        endm
        LVM_SETCOLUMNORDERARRAY equ (LVM_FIRST + 58)
        ListView_SetColumnOrderArray macro hwnd, iCount, pi
          exitm <SNDMSG ((hwnd), LVM_SETCOLUMNORDERARRAY, (iCount), (LPINT) (pi))>
        endm
        LVM_GETCOLUMNORDERARRAY equ (LVM_FIRST + 59)
        ListView_GetColumnOrderArray macro hwnd, iCount, pi
          exitm <SNDMSG ((hwnd), LVM_GETCOLUMNORDERARRAY, (iCount), (LPINT) (pi))>
        endm
        LVM_SETHOTITEM equ (LVM_FIRST + 60)
        ListView_SetHotItem macro hwnd, i
          exitm <SNDMSG ((hwnd), LVM_SETHOTITEM, (i), 0)>
        endm
        LVM_GETHOTITEM equ (LVM_FIRST + 61)
        ListView_GetHotItem macro hwnd
          exitm <SNDMSG ((hwnd), LVM_GETHOTITEM, 0, 0)>
        endm
        LVM_SETHOTCURSOR equ (LVM_FIRST + 62)
        ListView_SetHotCursor macro hwnd, hcur
          exitm <SNDMSG ((hwnd), LVM_SETHOTCURSOR, 0, (hcur))>
        endm
        LVM_GETHOTCURSOR equ (LVM_FIRST + 63)
        ListView_GetHotCursor macro hwnd
          exitm <SNDMSG ((hwnd), LVM_GETHOTCURSOR, 0, 0)>
        endm
        LVM_APPROXIMATEVIEWRECT equ (LVM_FIRST + 64)
        ListView_ApproximateViewRect macro hwnd, iWidth, iHeight, iCount
          exitm <SNDMSG ((hwnd), LVM_APPROXIMATEVIEWRECT, (iCount), MAKELPARAM(iWidth, iHeight))>
        endm
        LV_MAX_WORKAREAS equ 16
        LVM_SETWORKAREAS equ (LVM_FIRST + 65)
        ListView_SetWorkAreas macro hwnd, nWorkAreas, prc
          exitm <SNDMSG ((hwnd), LVM_SETWORKAREAS, (nWorkAreas), (RECT *) (prc))>
        endm
        LVM_GETWORKAREAS equ (LVM_FIRST + 70)
        ListView_GetWorkAreas macro hwnd, nWorkAreas, prc
          exitm <SNDMSG ((hwnd), LVM_GETWORKAREAS, (nWorkAreas), (RECT *) (prc))>
        endm
        LVM_GETNUMBEROFWORKAREAS equ (LVM_FIRST + 73)
        ListView_GetNumberOfWorkAreas macro hwnd, pnWorkAreas
          exitm <SNDMSG ((hwnd), LVM_GETNUMBEROFWORKAREAS, 0, (pnWorkAreas))>
        endm
        LVM_GETSELECTIONMARK equ (LVM_FIRST + 66)
        ListView_GetSelectionMark macro hwnd
          exitm <SNDMSG ((hwnd), LVM_GETSELECTIONMARK, 0, 0)>
        endm
        LVM_SETSELECTIONMARK equ (LVM_FIRST + 67)
        ListView_SetSelectionMark macro hwnd, i
          exitm <SNDMSG ((hwnd), LVM_SETSELECTIONMARK, 0, (i))>
        endm
        LVM_SETHOVERTIME equ (LVM_FIRST + 71)
        ListView_SetHoverTime macro hwndLV, dwHoverTimeMs
          exitm <SNDMSG ((hwndLV), LVM_SETHOVERTIME, 0, (dwHoverTimeMs))>
        endm
        LVM_GETHOVERTIME equ (LVM_FIRST + 72)
        ListView_GetHoverTime macro hwndLV
          exitm <SNDMSG ((hwndLV), LVM_GETHOVERTIME, 0, 0)>
        endm
        LVM_SETTOOLTIPS equ (LVM_FIRST + 74)
        ListView_SetToolTips macro hwndLV, hwndNewHwnd
          exitm <SNDMSG ((hwndLV), LVM_SETTOOLTIPS, (hwndNewHwnd), 0)>
        endm
        LVM_GETTOOLTIPS equ (LVM_FIRST + 78)
        ListView_GetToolTips macro hwndLV
          exitm <SNDMSG ((hwndLV), LVM_GETTOOLTIPS, 0, 0)>
        endm
        LVM_SORTITEMSEX equ (LVM_FIRST + 81)
        ListView_SortItemsEx macro hwndLV, _pfnCompare, _lPrm
          exitm <SNDMSG ((hwndLV), LVM_SORTITEMSEX, (_lPrm), (PFNLVCOMPARE) (_pfnCompare))>
        endm
        LVBKIMAGEA struct
          ulFlags DWORD ?
          ; LVBKIF_*
          hbm HBITMAP ?
          pszImage POINTER ?
          cchImageMax DWORD ?
          xOffsetPercent SDWORD ?
          yOffsetPercent SDWORD ?
        LVBKIMAGEA ends
        tagLVBKIMAGEA typedef LVBKIMAGEA
        LPLVBKIMAGEA typedef ptr LVBKIMAGEA
        LVBKIMAGEW struct
          ulFlags DWORD ?
          ; LVBKIF_*
          hbm HBITMAP ?
          pszImage POINTER ?
          cchImageMax DWORD ?
          xOffsetPercent SDWORD ?
          yOffsetPercent SDWORD ?
        LVBKIMAGEW ends
        tagLVBKIMAGEW typedef LVBKIMAGEW
        LPLVBKIMAGEW typedef ptr LVBKIMAGEW
        LVBKIF_SOURCE_NONE equ 00000000h
        LVBKIF_SOURCE_HBITMAP equ 00000001h
        LVBKIF_SOURCE_URL equ 00000002h
        LVBKIF_SOURCE_MASK equ 00000003h
        LVBKIF_STYLE_NORMAL equ 00000000h
        LVBKIF_STYLE_TILE equ 00000010h
        LVBKIF_STYLE_MASK equ 00000010h
        if (NTDDI_VERSION ge NTDDI_WINXP)
          LVBKIF_FLAG_TILEOFFSET equ 00000100h
          LVBKIF_TYPE_WATERMARK equ 10000000h
          LVBKIF_FLAG_ALPHABLEND equ 20000000h
        endif
        LVM_SETBKIMAGEA equ (LVM_FIRST + 68)
        LVM_SETBKIMAGEW equ (LVM_FIRST + 138)
        LVM_GETBKIMAGEA equ (LVM_FIRST + 69)
        LVM_GETBKIMAGEW equ (LVM_FIRST + 139)
        if (NTDDI_VERSION ge NTDDI_WINXP)
          LVM_SETSELECTEDCOLUMN equ (LVM_FIRST + 140)
          ListView_SetSelectedColumn macro hwnd, iCol
            exitm <SNDMSG ((hwnd), LVM_SETSELECTEDCOLUMN, (iCol), 0)>
          endm
          LV_VIEW_ICON equ 0000h
          LV_VIEW_DETAILS equ 0001h
          LV_VIEW_SMALLICON equ 0002h
          LV_VIEW_LIST equ 0003h
          LV_VIEW_TILE equ 0004h
          LV_VIEW_MAX equ 0004h
          LVM_SETVIEW equ (LVM_FIRST + 142)
          ListView_SetView macro hwnd, iView
            exitm <SNDMSG ((hwnd), LVM_SETVIEW, (iView), 0)>
          endm
          LVM_GETVIEW equ (LVM_FIRST + 143)
          ListView_GetView macro hwnd
            exitm <SNDMSG ((hwnd), LVM_GETVIEW, 0, 0)>
          endm
          LVGF_NONE equ 00000000h
          LVGF_HEADER equ 00000001h
          LVGF_FOOTER equ 00000002h
          LVGF_STATE equ 00000004h
          LVGF_ALIGN equ 00000008h
          LVGF_GROUPID equ 00000010h
          if (NTDDI_VERSION ge NTDDI_VISTA)
            LVGF_SUBTITLE equ 00000100h; pszSubtitle is valid

            LVGF_TASK equ 00000200h; pszTask is valid

            LVGF_DESCRIPTIONTOP equ 00000400h; pszDescriptionTop is valid

            LVGF_DESCRIPTIONBOTTOM equ 00000800h; pszDescriptionBottom is valid

            LVGF_TITLEIMAGE equ 00001000h; iTitleImage is valid

            LVGF_EXTENDEDIMAGE equ 00002000h; iExtendedImage is valid

            LVGF_ITEMS equ 00004000h; iFirstItem and cItems are valid

            LVGF_SUBSET equ 00008000h; pszSubsetTitle is valid

            LVGF_SUBSETITEMS equ 00010000h; readonly, cItems holds count of items in visible subset, iFirstItem is valid

          endif
          LVGS_NORMAL equ 00000000h
          LVGS_COLLAPSED equ 00000001h
          LVGS_HIDDEN equ 00000002h
          LVGS_NOHEADER equ 00000004h
          LVGS_COLLAPSIBLE equ 00000008h
          LVGS_FOCUSED equ 00000010h
          LVGS_SELECTED equ 00000020h
          LVGS_SUBSETED equ 00000040h
          LVGS_SUBSETLINKFOCUSED equ 00000080h
          LVGA_HEADER_LEFT equ 00000001h
          LVGA_HEADER_CENTER equ 00000002h
          LVGA_HEADER_RIGHT equ 00000004h; Don't forget to validate exclusivity

          LVGA_FOOTER_LEFT equ 00000008h
          LVGA_FOOTER_CENTER equ 00000010h
          LVGA_FOOTER_RIGHT equ 00000020h; Don't forget to validate exclusivity

          LVGROUP struct
            cbSize DWORD ?
            mask_ DWORD ?
            pszHeader POINTER ?
            cchHeader SDWORD ?
            pszFooter POINTER ?
            cchFooter SDWORD ?
            iGroupId SDWORD ?
            stateMask DWORD ?
            state DWORD ?
            uAlign DWORD ?
            if (NTDDI_VERSION ge NTDDI_VISTA)
              pszSubtitle POINTER ?
              cchSubtitle DWORD ?
              pszTask POINTER ?
              cchTask DWORD ?
              pszDescriptionTop POINTER ?
              cchDescriptionTop DWORD ?
              pszDescriptionBottom POINTER ?
              cchDescriptionBottom DWORD ?
              iTitleImage SDWORD ?
              iExtendedImage SDWORD ?
              iFirstItem SDWORD ?
              ; Read only
              cItems DWORD ?
              ; Read only
              pszSubsetTitle POINTER ?
              ; NULL if group is not subset
              cchSubsetTitle DWORD ?
              LVGROUP_V5_SIZE equ <CCSIZEOF_STRUCT(LVGROUP, uAlign)>
            endif
          LVGROUP ends
          tagLVGROUP typedef LVGROUP
          PLVGROUP typedef ptr LVGROUP
          LVM_INSERTGROUP equ (LVM_FIRST + 145)
          ListView_InsertGroup macro hwnd, index, pgrp
            exitm <SNDMSG ((hwnd), LVM_INSERTGROUP, (index), (pgrp))>
          endm
          LVM_SETGROUPINFO equ (LVM_FIRST + 147)
          ListView_SetGroupInfo macro hwnd, iGroupId, pgrp
            exitm <SNDMSG ((hwnd), LVM_SETGROUPINFO, (iGroupId), (pgrp))>
          endm
          LVM_GETGROUPINFO equ (LVM_FIRST + 149)
          ListView_GetGroupInfo macro hwnd, iGroupId, pgrp
            exitm <SNDMSG ((hwnd), LVM_GETGROUPINFO, (iGroupId), (pgrp))>
          endm
          LVM_REMOVEGROUP equ (LVM_FIRST + 150)
          ListView_RemoveGroup macro hwnd, iGroupId
            exitm <SNDMSG ((hwnd), LVM_REMOVEGROUP, (iGroupId), 0)>
          endm
          LVM_MOVEGROUP equ (LVM_FIRST + 151)
          ListView_MoveGroup macro hwnd, iGroupId, toIndex
            exitm <SNDMSG ((hwnd), LVM_MOVEGROUP, (iGroupId), (toIndex))>
          endm
          LVM_GETGROUPCOUNT equ (LVM_FIRST + 152)
          ListView_GetGroupCount macro hwnd
            exitm <SNDMSG ((hwnd), LVM_GETGROUPCOUNT, 0, 0)>
          endm
          LVM_GETGROUPINFOBYINDEX equ (LVM_FIRST + 153)
          ListView_GetGroupInfoByIndex macro hwnd, iIndex, pgrp
            exitm <SNDMSG ((hwnd), LVM_GETGROUPINFOBYINDEX, (iIndex), (pgrp))>
          endm
          LVM_MOVEITEMTOGROUP equ (LVM_FIRST + 154)
          ListView_MoveItemToGroup macro hwnd, idItemFrom, idGroupTo
            exitm <SNDMSG ((hwnd), LVM_MOVEITEMTOGROUP, (idItemFrom), (idGroupTo))>
          endm
          LVGGR_GROUP equ 0; Entire expanded group

          LVGGR_HEADER equ 1; Header only (collapsed group)

          LVGGR_LABEL equ 2; Label only

          LVGGR_SUBSETLINK equ 3; subset link only

          LVM_GETGROUPRECT equ (LVM_FIRST + 98)
          ListView_GetGroupRect macro hwnd, iGroupId, type_, prc
            exitm <SNDMSG ((hwnd), LVM_GETGROUPRECT, (iGroupId), ((prc) ? (((RECT *) (prc)) - top = (type_)), (RECT *) (prc) : (RECT *) NULL))>
          endm
          LVGMF_NONE equ 00000000h
          LVGMF_BORDERSIZE equ 00000001h
          LVGMF_BORDERCOLOR equ 00000002h
          LVGMF_TEXTCOLOR equ 00000004h
          LVGROUPMETRICS struct
            cbSize DWORD ?
            mask_ DWORD ?
            Left DWORD ?
            Top DWORD ?
            Right DWORD ?
            Bottom DWORD ?
            crLeft COLORREF ?
            crTop COLORREF ?
            crRight COLORREF ?
            crBottom COLORREF ?
            crHeader COLORREF ?
            crFooter COLORREF ?
          LVGROUPMETRICS ends
          tagLVGROUPMETRICS typedef LVGROUPMETRICS
          PLVGROUPMETRICS typedef ptr LVGROUPMETRICS
          LVM_SETGROUPMETRICS equ (LVM_FIRST + 155)
          ListView_SetGroupMetrics macro hwnd, pGroupMetrics
            exitm <SNDMSG ((hwnd), LVM_SETGROUPMETRICS, 0, (pGroupMetrics))>
          endm
          LVM_GETGROUPMETRICS equ (LVM_FIRST + 156)
          ListView_GetGroupMetrics macro hwnd, pGroupMetrics
            exitm <SNDMSG ((hwnd), LVM_GETGROUPMETRICS, 0, (pGroupMetrics))>
          endm
          LVM_ENABLEGROUPVIEW equ (LVM_FIRST + 157)
          ListView_EnableGroupView macro hwnd, fEnable
            exitm <SNDMSG ((hwnd), LVM_ENABLEGROUPVIEW, (fEnable), 0)>
          endm
          TYPE_PFNLVGROUPCOMPARE typedef proto WIN_STD_CALL_CONV :SDWORD, :SDWORD, :ptr
          PFNLVGROUPCOMPARE typedef ptr TYPE_PFNLVGROUPCOMPARE

          LVM_SORTGROUPS equ (LVM_FIRST + 158)
          ListView_SortGroups macro hwnd, _pfnGroupCompate, _plv
            exitm <SNDMSG ((hwnd), LVM_SORTGROUPS, (_pfnGroupCompate), (_plv))>
          endm
          LVINSERTGROUPSORTED struct
            pfnGroupCompare PFNLVGROUPCOMPARE ?
            pvData POINTER ?
            lvGroup LVGROUP <>
          LVINSERTGROUPSORTED ends
          tagLVINSERTGROUPSORTED typedef LVINSERTGROUPSORTED
          PLVINSERTGROUPSORTED typedef ptr LVINSERTGROUPSORTED
          LVM_INSERTGROUPSORTED equ (LVM_FIRST + 159)
          ListView_InsertGroupSorted macro hwnd, structInsert
            exitm <SNDMSG ((hwnd), LVM_INSERTGROUPSORTED, (structInsert), 0)>
          endm
          LVM_REMOVEALLGROUPS equ (LVM_FIRST + 160)
          ListView_RemoveAllGroups macro hwnd
            exitm <SNDMSG ((hwnd), LVM_REMOVEALLGROUPS, 0, 0)>
          endm
          LVM_HASGROUP equ (LVM_FIRST + 161)
          ListView_HasGroup macro hwnd, dwGroupId
            exitm <SNDMSG ((hwnd), LVM_HASGROUP, dwGroupId, 0)>
          endm
          ListView_SetGroupState macro hwnd, dwGroupId, dwMask, dwState
            exitm <{ LVGROUP _macro_lvg ; _macro_lvg.cbSize = sizeof(_macro_lvg) ; _macro_lvg.mask = LVGF_STATE ; _macro_lvg.stateMask = dwMask ; _macro_lvg.state = dwState ; SNDMSG ((hwnd), LVM_SETGROUPINFO, (dwGroupId), (LVGROUP *) and _macro_lvg) ; }>
          endm
          LVM_GETGROUPSTATE equ (LVM_FIRST + 92)
          ListView_GetGroupState macro hwnd, dwGroupId, dwMask
            exitm <SNDMSG ((hwnd), LVM_GETGROUPSTATE, (dwGroupId), (dwMask))>
          endm
          LVM_GETFOCUSEDGROUP equ (LVM_FIRST + 93)
          ListView_GetFocusedGroup macro hwnd
            exitm <SNDMSG ((hwnd), LVM_GETFOCUSEDGROUP, 0, 0)>
          endm
          LVTVIF_AUTOSIZE equ 00000000h
          LVTVIF_FIXEDWIDTH equ 00000001h
          LVTVIF_FIXEDHEIGHT equ 00000002h
          LVTVIF_FIXEDSIZE equ 00000003h
          if (NTDDI_VERSION ge NTDDI_VISTA)
            LVTVIF_EXTENDED equ 00000004h
          endif
          LVTVIM_TILESIZE equ 00000001h
          LVTVIM_COLUMNS equ 00000002h
          LVTVIM_LABELMARGIN equ 00000004h
          LVTILEVIEWINFO struct
            cbSize DWORD ?
            dwMask DWORD ?
            ;LVTVIM_*
            dwFlags DWORD ?
            ;LVTVIF_*
            sizeTile SIZE_ ?
            cLines SDWORD ?
            rcLabelMargin RECT <>
          LVTILEVIEWINFO ends
          tagLVTILEVIEWINFO typedef LVTILEVIEWINFO
          PLVTILEVIEWINFO typedef ptr LVTILEVIEWINFO
          LVTILEINFO struct
            cbSize DWORD ?
            iItem SDWORD ?
            cColumns DWORD ?
            puColumns PUINT ?
            if (NTDDI_VERSION ge NTDDI_VISTA)
              piColFmt POINTER ?
            endif
          LVTILEINFO ends
          tagLVTILEINFO typedef LVTILEINFO
          PLVTILEINFO typedef ptr LVTILEINFO
          LVTILEINFO_V5_SIZE equ <CCSIZEOF_STRUCT(LVTILEINFO, puColumns)>
          LVM_SETTILEVIEWINFO equ (LVM_FIRST + 162)
          ListView_SetTileViewInfo macro hwnd, ptvi
            exitm <SNDMSG ((hwnd), LVM_SETTILEVIEWINFO, 0, (ptvi))>
          endm
          LVM_GETTILEVIEWINFO equ (LVM_FIRST + 163)
          ListView_GetTileViewInfo macro hwnd, ptvi
            exitm <SNDMSG ((hwnd), LVM_GETTILEVIEWINFO, 0, (ptvi))>
          endm
          LVM_SETTILEINFO equ (LVM_FIRST + 164)
          ListView_SetTileInfo macro hwnd, pti
            exitm <SNDMSG ((hwnd), LVM_SETTILEINFO, 0, (pti))>
          endm
          LVM_GETTILEINFO equ (LVM_FIRST + 165)
          ListView_GetTileInfo macro hwnd, pti
            exitm <SNDMSG ((hwnd), LVM_GETTILEINFO, 0, (pti))>
          endm
          LVINSERTMARK struct
            cbSize DWORD ?
            dwFlags DWORD ?
            iItem SDWORD ?
            dwReserved DWORD ?
          LVINSERTMARK ends
          LPLVINSERTMARK typedef ptr LVINSERTMARK
          LVIM_AFTER equ 00000001h; TRUE = insert After iItem, otherwise before

          LVM_SETINSERTMARK equ (LVM_FIRST + 166)
          ListView_SetInsertMark macro hwnd, lvim
            exitm <SNDMSG ((hwnd), LVM_SETINSERTMARK, 0, (lvim))>
          endm
          LVM_GETINSERTMARK equ (LVM_FIRST + 167)
          ListView_GetInsertMark macro hwnd, lvim
            exitm <SNDMSG ((hwnd), LVM_GETINSERTMARK, 0, (lvim))>
          endm
          LVM_INSERTMARKHITTEST equ (LVM_FIRST + 168)
          ListView_InsertMarkHitTest macro hwnd, point, lvim
            exitm <SNDMSG ((hwnd), LVM_INSERTMARKHITTEST, (LPPOINT) (point), (LPLVINSERTMARK) (lvim))>
          endm
          LVM_GETINSERTMARKRECT equ (LVM_FIRST + 169)
          ListView_GetInsertMarkRect macro hwnd, rc
            exitm <SNDMSG ((hwnd), LVM_GETINSERTMARKRECT, 0, (LPRECT) (rc))>
          endm
          LVM_SETINSERTMARKCOLOR equ (LVM_FIRST + 170)
          ListView_SetInsertMarkColor macro hwnd, color
            exitm <SNDMSG ((hwnd), LVM_SETINSERTMARKCOLOR, 0, (color))>
          endm
          LVM_GETINSERTMARKCOLOR equ (LVM_FIRST + 171)
          ListView_GetInsertMarkColor macro hwnd
            exitm <SNDMSG ((hwnd), LVM_GETINSERTMARKCOLOR, 0, 0)>
          endm
          LVSETINFOTIP struct
            cbSize DWORD ?
            dwFlags DWORD ?
            pszText POINTER ?
            iItem SDWORD ?
            iSubItem SDWORD ?
          LVSETINFOTIP ends
          tagLVSETINFOTIP typedef LVSETINFOTIP
          PLVSETINFOTIP typedef ptr LVSETINFOTIP
          LVM_SETINFOTIP equ (LVM_FIRST + 173)
          ListView_SetInfoTip macro hwndLV, plvInfoTip
            exitm <SNDMSG ((hwndLV), LVM_SETINFOTIP, 0, (plvInfoTip))>
          endm
          LVM_GETSELECTEDCOLUMN equ (LVM_FIRST + 174)
          ListView_GetSelectedColumn macro hwnd
            exitm <SNDMSG ((hwnd), LVM_GETSELECTEDCOLUMN, 0, 0)>
          endm
          LVM_ISGROUPVIEWENABLED equ (LVM_FIRST + 175)
          ListView_IsGroupViewEnabled macro hwnd
            exitm <SNDMSG ((hwnd), LVM_ISGROUPVIEWENABLED, 0, 0)>
          endm
          LVM_GETOUTLINECOLOR equ (LVM_FIRST + 176)
          ListView_GetOutlineColor macro hwnd
            exitm <SNDMSG ((hwnd), LVM_GETOUTLINECOLOR, 0, 0)>
          endm
          LVM_SETOUTLINECOLOR equ (LVM_FIRST + 177)
          ListView_SetOutlineColor macro hwnd, color
            exitm <SNDMSG ((hwnd), LVM_SETOUTLINECOLOR, 0, (color))>
          endm
          LVM_CANCELEDITLABEL equ (LVM_FIRST + 179)
          ListView_CancelEditLabel macro hwnd
            exitm <(VOID) SNDMSG ((hwnd), LVM_CANCELEDITLABEL, 0, 0)>
          endm
          ; These next to methods make it easy to identify an item that can be repositioned
          ; within listview. For example: Many developers use the lParam to store an identifier that is
          ; unique. Unfortunatly, in order to find this item, they have to iterate through all of the items
          ; in the listview. Listview will maintain a unique identifier.  The upper bound is the size of a DWORD.
          LVM_MAPINDEXTOID equ (LVM_FIRST + 180)
          ListView_MapIndexToID macro hwnd, index
            exitm <SNDMSG ((hwnd), LVM_MAPINDEXTOID, (index), 0)>
          endm
          LVM_MAPIDTOINDEX equ (LVM_FIRST + 181)
          ListView_MapIDToIndex macro hwnd, id
            exitm <SNDMSG ((hwnd), LVM_MAPIDTOINDEX, (id), 0)>
          endm
          LVM_ISITEMVISIBLE equ (LVM_FIRST + 182)
          ListView_IsItemVisible macro hwnd, index
            exitm <SNDMSG ((hwnd), LVM_ISITEMVISIBLE, (index), 0)>
          endm
          if (NTDDI_VERSION ge NTDDI_VISTA)
            ListView_SetGroupHeaderImageList macro hwnd, himl
              exitm <SNDMSG ((hwnd), LVM_SETIMAGELIST, LVSIL_GROUPHEADER, (himl))>
            endm
            ListView_GetGroupHeaderImageList macro hwnd
              exitm <SNDMSG ((hwnd), LVM_GETIMAGELIST, LVSIL_GROUPHEADER, 0)>
            endm
            LVM_GETEMPTYTEXT equ (LVM_FIRST + 204)
            ListView_GetEmptyText macro hwnd, pszText, cchText
              exitm <SNDMSG ((hwnd), LVM_GETEMPTYTEXT, (cchText), (pszText))>
            endm
            LVM_GETFOOTERRECT equ (LVM_FIRST + 205)
            ListView_GetFooterRect macro hwnd, prc
              exitm <SNDMSG ((hwnd), LVM_GETFOOTERRECT, (0), (prc))>
            endm
            ; footer flags
            LVFF_ITEMCOUNT equ 00000001h
            LVFOOTERINFO struct
              mask_ DWORD ?
              ; LVFF_*
              pszText POINTER ?
              cchTextMax SDWORD ?
              cItems DWORD ?
            LVFOOTERINFO ends
            tagLVFOOTERINFO typedef LVFOOTERINFO
            LPLVFOOTERINFO typedef ptr LVFOOTERINFO
            LVM_GETFOOTERINFO equ (LVM_FIRST + 206)
            ListView_GetFooterInfo macro hwnd, plvfi
              exitm <SNDMSG ((hwnd), LVM_GETFOOTERINFO, (0), (plvfi))>
            endm
            LVM_GETFOOTERITEMRECT equ (LVM_FIRST + 207)
            ListView_GetFooterItemRect macro hwnd, iItem, prc
              exitm <SNDMSG ((hwnd), LVM_GETFOOTERITEMRECT, (iItem), (prc))>
            endm
            ; footer item flags
            LVFIF_TEXT equ 00000001h
            LVFIF_STATE equ 00000002h
            ; footer item state
            LVFIS_FOCUSED equ 0001h
            LVFOOTERITEM struct
              mask_ DWORD ?
              ; LVFIF_*
              iItem SDWORD ?
              pszText POINTER ?
              cchTextMax SDWORD ?
              state DWORD ?
              ; LVFIS_*
              stateMask DWORD ?
              ; LVFIS_*
            LVFOOTERITEM ends
            tagLVFOOTERITEM typedef LVFOOTERITEM
            LPLVFOOTERITEM typedef ptr LVFOOTERITEM
            LVM_GETFOOTERITEM equ (LVM_FIRST + 208)
            ListView_GetFooterItem macro hwnd, iItem, pfi
              exitm <SNDMSG ((hwnd), LVM_GETFOOTERITEM, (iItem), (pfi))>
            endm
            ; supports a single item in multiple groups.
            LVITEMINDEX struct
              iItem SDWORD ?
              ; listview item index
              iGroup SDWORD ?
              ; group index (must be -1 if group view is not enabled)
            LVITEMINDEX ends
            tagLVITEMINDEX typedef LVITEMINDEX
            PLVITEMINDEX typedef ptr LVITEMINDEX
            LVM_GETITEMINDEXRECT equ (LVM_FIRST + 209)
            ListView_GetItemIndexRect macro hwnd, plvii, iSubItem, code, prc
              exitm <SNDMSG ((hwnd), LVM_GETITEMINDEXRECT, (LVITEMINDEX *) (plvii), ((prc) ? ((((LPRECT) (prc)) - top = (iSubItem)), (((LPRECT) (prc)) - left = (code)), (prc)) : (LPRECT) NULL))>
            endm
            LVM_SETITEMINDEXSTATE equ (LVM_FIRST + 210)
            ListView_SetItemIndexState macro hwndLV, plvii, data, mask_
              exitm <{ LV_ITEM _macro_lvi ; _macro_lvi.stateMask = (mask_) ; _macro_lvi.state = (data) ; SNDMSG ((hwndLV), LVM_SETITEMINDEXSTATE, (LVITEMINDEX *) (plvii), (LV_ITEM *) and _macro_lvi) ; }>
            endm
            LVM_GETNEXTITEMINDEX equ (LVM_FIRST + 211)
            ListView_GetNextItemIndex macro hwnd, plvii, flags
              exitm <SNDMSG ((hwnd), LVM_GETNEXTITEMINDEX, (LVITEMINDEX *) (plvii), MAKELPARAM((flags), 0))>
            endm
          endif
        endif
        ifdef UNICODE
          LVBKIMAGE equ <LVBKIMAGEW>
          LPLVBKIMAGE equ <LPLVBKIMAGEW>
          LVM_SETBKIMAGE equ <LVM_SETBKIMAGEW>
          LVM_GETBKIMAGE equ <LVM_GETBKIMAGEW>
        else
          LVBKIMAGE equ <LVBKIMAGEA>
          LPLVBKIMAGE equ <LPLVBKIMAGEA>
          LVM_SETBKIMAGE equ <LVM_SETBKIMAGEA>
          LVM_GETBKIMAGE equ <LVM_GETBKIMAGEA>
        endif
        ListView_SetBkImage macro hwnd, plvbki
          exitm <SNDMSG ((hwnd), LVM_SETBKIMAGE, 0, (plvbki))>
        endm
        ListView_GetBkImage macro hwnd, plvbki
          exitm <SNDMSG ((hwnd), LVM_GETBKIMAGE, 0, (plvbki))>
        endm
        LPNM_LISTVIEW equ <LPNMLISTVIEW>
        NM_LISTVIEW equ <NMLISTVIEW>
        NMLISTVIEW struct
          hdr NMHDR <>
          iItem SDWORD ?
          iSubItem SDWORD ?
          uNewState DWORD ?
          uOldState DWORD ?
          uChanged DWORD ?
          ptAction POINT <>
          lParam LPARAM ?
        NMLISTVIEW ends
        tagNMLISTVIEW typedef NMLISTVIEW
        LPNMLISTVIEW typedef ptr NMLISTVIEW
        ; NMITEMACTIVATE is used instead of NMLISTVIEW in IE >= 0x400
        ; therefore all the fields are the same except for extra uKeyFlags
        ; they are used to store key flags at the time of the single click with
        ; delayed activation - because by the time the timer goes off a user may
        ; not hold the keys (shift, ctrl) any more
        NMITEMACTIVATE struct
          hdr NMHDR <>
          iItem SDWORD ?
          iSubItem SDWORD ?
          uNewState DWORD ?
          uOldState DWORD ?
          uChanged DWORD ?
          ptAction POINT <>
          lParam LPARAM ?
          uKeyFlags DWORD ?
        NMITEMACTIVATE ends
        tagNMITEMACTIVATE typedef NMITEMACTIVATE
        LPNMITEMACTIVATE typedef ptr NMITEMACTIVATE
        ; key flags stored in uKeyFlags
        LVKF_ALT equ 0001h
        LVKF_CONTROL equ 0002h
        LVKF_SHIFT equ 0004h
        NMLVCUSTOMDRAW_V3_SIZE equ <CCSIZEOF_STRUCT(NMLVCUSTOMDRAW, clrTextBk)>
        NMLVCUSTOMDRAW struct
          nmcd NMCUSTOMDRAW <>
          clrText COLORREF ?
          clrTextBk COLORREF ?
          iSubItem SDWORD ?
          if (NTDDI_VERSION ge NTDDI_WINXP)
            dwItemType DWORD ?
            ; Item custom draw
            clrFace COLORREF ?
            iIconEffect SDWORD ?
            iIconPhase SDWORD ?
            iPartId SDWORD ?
            iStateId SDWORD ?
            ; Group Custom Draw
            rcText RECT <>
            uAlign DWORD ?
            ; Alignment. Use LVGA_HEADER_CENTER, LVGA_HEADER_RIGHT, LVGA_HEADER_LEFT
          endif
        NMLVCUSTOMDRAW ends
        tagNMLVCUSTOMDRAW typedef NMLVCUSTOMDRAW
        LPNMLVCUSTOMDRAW typedef ptr NMLVCUSTOMDRAW
        ; dwItemType
        LVCDI_ITEM equ 00000000h
        LVCDI_GROUP equ 00000001h
        LVCDI_ITEMSLIST equ 00000002h
        ; ListView custom draw return values
        LVCDRF_NOSELECT equ 00010000h
        LVCDRF_NOGROUPFRAME equ 00020000h
        NMLVCACHEHINT struct
          hdr NMHDR <>
          iFrom SDWORD ?
          iTo SDWORD ?
        NMLVCACHEHINT ends
        tagNMLVCACHEHINT typedef NMLVCACHEHINT
        LPNMLVCACHEHINT typedef ptr NMLVCACHEHINT
        LPNM_CACHEHINT equ <LPNMLVCACHEHINT>
        PNM_CACHEHINT equ <LPNMLVCACHEHINT>
        NM_CACHEHINT equ <NMLVCACHEHINT>
        NMLVFINDITEMA struct
          hdr NMHDR <>
          iStart SDWORD ?
          lvfi LVFINDINFOA <>
        NMLVFINDITEMA ends
        tagNMLVFINDITEMA typedef NMLVFINDITEMA
        LPNMLVFINDITEMA typedef ptr NMLVFINDITEMA
        NMLVFINDITEMW struct
          hdr NMHDR <>
          iStart SDWORD ?
          lvfi LVFINDINFOW <>
        NMLVFINDITEMW ends
        tagNMLVFINDITEMW typedef NMLVFINDITEMW
        LPNMLVFINDITEMW typedef ptr NMLVFINDITEMW
        PNM_FINDITEMA equ <LPNMLVFINDITEMA>
        LPNM_FINDITEMA equ <LPNMLVFINDITEMA>
        NM_FINDITEMA equ <NMLVFINDITEMA>
        PNM_FINDITEMW equ <LPNMLVFINDITEMW>
        LPNM_FINDITEMW equ <LPNMLVFINDITEMW>
        NM_FINDITEMW equ <NMLVFINDITEMW>
        ifdef UNICODE
          PNM_FINDITEM equ <PNM_FINDITEMW>
          LPNM_FINDITEM equ <LPNM_FINDITEMW>
          NM_FINDITEM equ <NM_FINDITEMW>
          NMLVFINDITEM equ <NMLVFINDITEMW>
          LPNMLVFINDITEM equ <LPNMLVFINDITEMW>
        else
          PNM_FINDITEM equ <PNM_FINDITEMA>
          LPNM_FINDITEM equ <LPNM_FINDITEMA>
          NM_FINDITEM equ <NM_FINDITEMA>
          NMLVFINDITEM equ <NMLVFINDITEMA>
          LPNMLVFINDITEM equ <LPNMLVFINDITEMA>
        endif
        NMLVODSTATECHANGE struct
          hdr NMHDR <>
          iFrom SDWORD ?
          iTo SDWORD ?
          uNewState DWORD ?
          uOldState DWORD ?
        NMLVODSTATECHANGE ends
        tagNMLVODSTATECHANGE typedef NMLVODSTATECHANGE
        LPNMLVODSTATECHANGE typedef ptr NMLVODSTATECHANGE
        PNM_ODSTATECHANGE equ <LPNMLVODSTATECHANGE>
        LPNM_ODSTATECHANGE equ <LPNMLVODSTATECHANGE>
        NM_ODSTATECHANGE equ <NMLVODSTATECHANGE>
        LVN_ITEMCHANGING equ (LVN_FIRST - 0)
        LVN_ITEMCHANGED equ (LVN_FIRST - 1)
        LVN_INSERTITEM equ (LVN_FIRST - 2)
        LVN_DELETEITEM equ (LVN_FIRST - 3)
        LVN_DELETEALLITEMS equ (LVN_FIRST - 4)
        LVN_BEGINLABELEDITA equ (LVN_FIRST - 5)
        LVN_BEGINLABELEDITW equ (LVN_FIRST - 75)
        LVN_ENDLABELEDITA equ (LVN_FIRST - 6)
        LVN_ENDLABELEDITW equ (LVN_FIRST - 76)
        LVN_COLUMNCLICK equ (LVN_FIRST - 8)
        LVN_BEGINDRAG equ (LVN_FIRST - 9)
        LVN_BEGINRDRAG equ (LVN_FIRST - 11)
        LVN_ODCACHEHINT equ (LVN_FIRST - 13)
        LVN_ODFINDITEMA equ (LVN_FIRST - 52)
        LVN_ODFINDITEMW equ (LVN_FIRST - 79)
        LVN_ITEMACTIVATE equ (LVN_FIRST - 14)
        LVN_ODSTATECHANGED equ (LVN_FIRST - 15)
        ifdef UNICODE
          LVN_ODFINDITEM equ <LVN_ODFINDITEMW>
        else
          LVN_ODFINDITEM equ <LVN_ODFINDITEMA>
        endif
        LVN_HOTTRACK equ (LVN_FIRST - 21)
        LVN_GETDISPINFOA equ (LVN_FIRST - 50)
        LVN_GETDISPINFOW equ (LVN_FIRST - 77)
        LVN_SETDISPINFOA equ (LVN_FIRST - 51)
        LVN_SETDISPINFOW equ (LVN_FIRST - 78)
        ifdef UNICODE
          LVN_BEGINLABELEDIT equ <LVN_BEGINLABELEDITW>
          LVN_ENDLABELEDIT equ <LVN_ENDLABELEDITW>
          LVN_GETDISPINFO equ <LVN_GETDISPINFOW>
          LVN_SETDISPINFO equ <LVN_SETDISPINFOW>
        else
          LVN_BEGINLABELEDIT equ <LVN_BEGINLABELEDITA>
          LVN_ENDLABELEDIT equ <LVN_ENDLABELEDITA>
          LVN_GETDISPINFO equ <LVN_GETDISPINFOA>
          LVN_SETDISPINFO equ <LVN_SETDISPINFOA>
        endif
        LVIF_DI_SETITEM equ 1000h
        LV_DISPINFOA equ <NMLVDISPINFOA>
        LV_DISPINFOW equ <NMLVDISPINFOW>
        LV_DISPINFO equ <NMLVDISPINFO>
        NMLVDISPINFOA struct
          hdr NMHDR <>
          item LVITEMA <>
        NMLVDISPINFOA ends
        tagLVDISPINFO typedef NMLVDISPINFOA
        LPNMLVDISPINFOA typedef ptr NMLVDISPINFOA
        NMLVDISPINFOW struct
          hdr NMHDR <>
          item LVITEMW <>
        NMLVDISPINFOW ends
        tagLVDISPINFOW typedef NMLVDISPINFOW
        LPNMLVDISPINFOW typedef ptr NMLVDISPINFOW
        ifdef UNICODE
          NMLVDISPINFO equ <NMLVDISPINFOW>
        else
          NMLVDISPINFO equ <NMLVDISPINFOA>
        endif
        LVN_KEYDOWN equ (LVN_FIRST - 55)
        LV_KEYDOWN equ <NMLVKEYDOWN>
        ifdef _WIN32
          include pshpack1.inc
        endif
        NMLVKEYDOWN struct
          hdr NMHDR <>
          wVKey WORD ?
          flags DWORD ?
        NMLVKEYDOWN ends
        tagLVKEYDOWN typedef NMLVKEYDOWN
        LPNMLVKEYDOWN typedef ptr NMLVKEYDOWN
        ifdef _WIN32
          include poppack.inc
        endif
        LVN_MARQUEEBEGIN equ (LVN_FIRST - 56)
        if (NTDDI_VERSION ge NTDDI_VISTA)
          NMLVLINK struct
            hdr NMHDR <>
            link LITEM <>
            iItem SDWORD ?
            iSubItem SDWORD ?
          NMLVLINK ends
          tagNMLVLINK typedef NMLVLINK
          PNMLVLINK typedef ptr NMLVLINK
        endif
        NMLVGETINFOTIPA struct
          hdr NMHDR <>
          dwFlags DWORD ?
          pszText POINTER ?
          cchTextMax SDWORD ?
          iItem SDWORD ?
          iSubItem SDWORD ?
          lParam LPARAM ?
        NMLVGETINFOTIPA ends
        tagNMLVGETINFOTIPA typedef NMLVGETINFOTIPA
        LPNMLVGETINFOTIPA typedef ptr NMLVGETINFOTIPA
        NMLVGETINFOTIPW struct
          hdr NMHDR <>
          dwFlags DWORD ?
          pszText POINTER ?
          cchTextMax SDWORD ?
          iItem SDWORD ?
          iSubItem SDWORD ?
          lParam LPARAM ?
        NMLVGETINFOTIPW ends
        tagNMLVGETINFOTIPW typedef NMLVGETINFOTIPW
        LPNMLVGETINFOTIPW typedef ptr NMLVGETINFOTIPW
        ; NMLVGETINFOTIPA.dwFlag values
        LVGIT_UNFOLDED equ 0001h
        LVN_GETINFOTIPA equ (LVN_FIRST - 57)
        LVN_GETINFOTIPW equ (LVN_FIRST - 58)
        ifdef UNICODE
          LVN_GETINFOTIP equ <LVN_GETINFOTIPW>
          NMLVGETINFOTIP equ <NMLVGETINFOTIPW>
          LPNMLVGETINFOTIP equ <LPNMLVGETINFOTIPW>
        else
          LVN_GETINFOTIP equ <LVN_GETINFOTIPA>
          NMLVGETINFOTIP equ <NMLVGETINFOTIPA>
          LPNMLVGETINFOTIP equ <LPNMLVGETINFOTIPA>
        endif
        ;  LVN_INCREMENTALSEARCH gives the app the opportunity to customize
        ;  incremental search.  For example, if the items are numeric,
        ;  the app can do numerical search instead of string search.
        ;  ListView notifies the app with NMLVFINDITEM.
        ;  The app sets pnmfi->lvfi.lParam to the result of the incremental search,
        ;  or to LVNSCH_DEFAULT if ListView should do the default search,
        ;  or to LVNSCH_ERROR to fail the search and just beep,
        ;  or to LVNSCH_IGNORE to stop all ListView processing.
        ;  The return value is not used.
        LVNSCH_DEFAULT equ -1
        LVNSCH_ERROR equ -2
        LVNSCH_IGNORE equ -3
        LVN_INCREMENTALSEARCHA equ (LVN_FIRST - 62)
        LVN_INCREMENTALSEARCHW equ (LVN_FIRST - 63)
        ifdef UNICODE
          LVN_INCREMENTALSEARCH equ <LVN_INCREMENTALSEARCHW>
        else
          LVN_INCREMENTALSEARCH equ <LVN_INCREMENTALSEARCHA>
        endif
        if (NTDDI_VERSION ge NTDDI_VISTA)
          LVN_COLUMNDROPDOWN equ (LVN_FIRST - 64)
          LVN_COLUMNOVERFLOWCLICK equ (LVN_FIRST - 66)
        endif
        ; (NTDDI_VERSION >= NTDDI_VISTA)
        if (NTDDI_VERSION ge NTDDI_WINXP)
          NMLVSCROLL struct
            hdr NMHDR <>
            dx_ SDWORD ?
            dy SDWORD ?
          NMLVSCROLL ends
          tagNMLVSCROLL typedef NMLVSCROLL
          LPNMLVSCROLL typedef ptr NMLVSCROLL
          LVN_BEGINSCROLL equ (LVN_FIRST - 80)
          LVN_ENDSCROLL equ (LVN_FIRST - 81)
        endif
        if (NTDDI_VERSION ge NTDDI_VISTA)
          LVN_LINKCLICK equ (LVN_FIRST - 84)
          EMF_CENTERED equ 00000001h; render markup centered in the listview area

          NMLVEMPTYMARKUP struct
            hdr NMHDR <>
            ; out params from client back to listview
            dwFlags DWORD ?
            ; EMF_*
            szMarkup WORD L_MAX_URL_LENGTH dup (?)
            ; markup displayed
          NMLVEMPTYMARKUP ends
          tagNMLVEMPTYMARKUP typedef NMLVEMPTYMARKUP
          LVN_GETEMPTYMARKUP equ (LVN_FIRST - 87)
        endif
      endif
      ; NOLISTVIEW
      ;====== TREEVIEW CONTROL =====================================================
      ifndef NOTREEVIEW
        ifdef _WIN32
          WC_TREEVIEWA equ <"SysTreeView32">
          WC_TREEVIEWW equ <L("SysTreeView32")>
          ifdef UNICODE
            WC_TREEVIEW equ <WC_TREEVIEWW>
          else
            WC_TREEVIEW equ <WC_TREEVIEWA>
          endif
        else
          ;[...]
        endif
        ; begin_r_commctrl
        TVS_HASBUTTONS equ 0001h
        TVS_HASLINES equ 0002h
        TVS_LINESATROOT equ 0004h
        TVS_EDITLABELS equ 0008h
        TVS_DISABLEDRAGDROP equ 0010h
        TVS_SHOWSELALWAYS equ 0020h
        TVS_RTLREADING equ 0040h
        TVS_NOTOOLTIPS equ 0080h
        TVS_CHECKBOXES equ 0100h
        TVS_TRACKSELECT equ 0200h
        TVS_SINGLEEXPAND equ 0400h
        TVS_INFOTIP equ 0800h
        TVS_FULLROWSELECT equ 1000h
        TVS_NOSCROLL equ 2000h
        TVS_NONEVENHEIGHT equ 4000h
        TVS_NOHSCROLL equ 8000h; TVS_NOSCROLL overrides this

        if (NTDDI_VERSION ge NTDDI_WINXP)
          TVS_EX_NOSINGLECOLLAPSE equ 0001h
        endif
        if (NTDDI_VERSION ge NTDDI_VISTA)
          TVS_EX_MULTISELECT equ 0002h
          TVS_EX_DOUBLEBUFFER equ 0004h
          TVS_EX_NOINDENTSTATE equ 0008h
          TVS_EX_RICHTOOLTIP equ 0010h
          TVS_EX_AUTOHSCROLL equ 0020h
          TVS_EX_FADEINOUTEXPANDOS equ 0040h
          TVS_EX_PARTIALCHECKBOXES equ 0080h
          TVS_EX_EXCLUSIONCHECKBOXES equ 0100h
          TVS_EX_DIMMEDCHECKBOXES equ 0200h
          TVS_EX_DRAWIMAGEASYNC equ 0400h
        endif
        if (NTDDI_VERSION ge NTDDI_WINTHRESHOLD)
        endif
        ; end_r_commctrl
        HTREEITEM typedef ptr _TREEITEM
        TVIF_TEXT equ 0001h
        TVIF_IMAGE equ 0002h
        TVIF_PARAM equ 0004h
        TVIF_STATE equ 0008h
        TVIF_HANDLE equ 0010h
        TVIF_SELECTEDIMAGE equ 0020h
        TVIF_CHILDREN equ 0040h
        TVIF_INTEGRAL equ 0080h
        if (_WIN32_IE ge 0600h)
          TVIF_STATEEX equ 0100h
          TVIF_EXPANDEDIMAGE equ 0200h
        endif
        TVIS_SELECTED equ 0002h
        TVIS_CUT equ 0004h
        TVIS_DROPHILITED equ 0008h
        TVIS_BOLD equ 0010h
        TVIS_EXPANDED equ 0020h
        TVIS_EXPANDEDONCE equ 0040h
        TVIS_EXPANDPARTIAL equ 0080h
        TVIS_OVERLAYMASK equ 0F00h
        TVIS_STATEIMAGEMASK equ 0F000h
        TVIS_USERMASK equ 0F000h
        if (_WIN32_IE ge 0600h)
          TVIS_EX_FLAT equ 0001h
          if (NTDDI_VERSION ge NTDDI_VISTA)
            TVIS_EX_DISABLED equ 0002h
          endif
          TVIS_EX_ALL equ 0002h
          ; Structure for TreeView's NM_TVSTATEIMAGECHANGING notification
          NMTVSTATEIMAGECHANGING struct
            hdr NMHDR <>
            hti HTREEITEM ?
            iOldStateImageIndex SDWORD ?
            iNewStateImageIndex SDWORD ?
          NMTVSTATEIMAGECHANGING ends
          tagNMTVSTATEIMAGECHANGING typedef NMTVSTATEIMAGECHANGING
          LPNMTVSTATEIMAGECHANGING typedef ptr NMTVSTATEIMAGECHANGING
        endif
        I_CHILDRENCALLBACK equ (- 1)
        I_CHILDRENAUTO equ (- 2)
        LPTV_ITEMW equ <LPTVITEMW>
        LPTV_ITEMA equ <LPTVITEMA>
        TV_ITEMW equ <TVITEMW>
        TV_ITEMA equ <TVITEMA>
        LPTV_ITEM equ <LPTVITEM>
        TV_ITEM equ <TVITEM>
        TVITEMA struct
          mask_ DWORD ?
          hItem HTREEITEM ?
          state DWORD ?
          stateMask DWORD ?
          pszText POINTER ?
          cchTextMax SDWORD ?
          iImage SDWORD ?
          iSelectedImage SDWORD ?
          cChildren SDWORD ?
          lParam LPARAM ?
        TVITEMA ends
        tagTVITEMA typedef TVITEMA
        LPTVITEMA typedef ptr TVITEMA
        TVITEMW struct
          mask_ DWORD ?
          hItem HTREEITEM ?
          state DWORD ?
          stateMask DWORD ?
          pszText POINTER ?
          cchTextMax SDWORD ?
          iImage SDWORD ?
          iSelectedImage SDWORD ?
          cChildren SDWORD ?
          lParam LPARAM ?
        TVITEMW ends
        tagTVITEMW typedef TVITEMW
        LPTVITEMW typedef ptr TVITEMW
        ; only used for Get and Set messages.  no notifies
        TVITEMEXA struct
          mask_ DWORD ?
          hItem HTREEITEM ?
          state DWORD ?
          stateMask DWORD ?
          pszText POINTER ?
          cchTextMax SDWORD ?
          iImage SDWORD ?
          iSelectedImage SDWORD ?
          cChildren SDWORD ?
          lParam LPARAM ?
          iIntegral SDWORD ?
          if (_WIN32_IE ge 0600h)
            uStateEx DWORD ?
            hwnd HWND ?
            iExpandedImage SDWORD ?
          endif
          if (NTDDI_VERSION ge NTDDI_WIN7)
            iReserved SDWORD ?
          endif
        TVITEMEXA ends
        tagTVITEMEXA typedef TVITEMEXA
        LPTVITEMEXA typedef ptr TVITEMEXA
        ; only used for Get and Set messages.  no notifies
        TVITEMEXW struct
          mask_ DWORD ?
          hItem HTREEITEM ?
          state DWORD ?
          stateMask DWORD ?
          pszText POINTER ?
          cchTextMax SDWORD ?
          iImage SDWORD ?
          iSelectedImage SDWORD ?
          cChildren SDWORD ?
          lParam LPARAM ?
          iIntegral SDWORD ?
          if (_WIN32_IE ge 0600h)
            uStateEx DWORD ?
            hwnd HWND ?
            iExpandedImage SDWORD ?
          endif
          if (NTDDI_VERSION ge NTDDI_WIN7)
            iReserved SDWORD ?
          endif
        TVITEMEXW ends
        tagTVITEMEXW typedef TVITEMEXW
        LPTVITEMEXW typedef ptr TVITEMEXW
        ifdef UNICODE
          TVITEMEX typedef TVITEMEXW
          LPTVITEMEX typedef LPTVITEMEXW
        else
          TVITEMEX typedef TVITEMEXA
          LPTVITEMEX typedef LPTVITEMEXA
        endif
        ; UNICODE
        ifdef UNICODE
          TVITEM equ <TVITEMW>
          LPTVITEM equ <LPTVITEMW>
        else
          TVITEM equ <TVITEMA>
          LPTVITEM equ <LPTVITEMA>
        endif
        TVI_ROOT equ (- 10000h)
        TVI_FIRST equ (- 0FFFFh)
        TVI_LAST equ (- 0FFFEh)
        TVI_SORT equ (- 0FFFDh)
        LPTV_INSERTSTRUCTA equ <LPTVINSERTSTRUCTA>
        LPTV_INSERTSTRUCTW equ <LPTVINSERTSTRUCTW>
        TV_INSERTSTRUCTA equ <TVINSERTSTRUCTA>
        TV_INSERTSTRUCTW equ <TVINSERTSTRUCTW>
        TV_INSERTSTRUCT equ <TVINSERTSTRUCT>
        LPTV_INSERTSTRUCT equ <LPTVINSERTSTRUCT>
        TVINSERTSTRUCTA_V1_SIZE equ <CCSIZEOF_STRUCT(TVINSERTSTRUCTA, item)>
        TVINSERTSTRUCTW_V1_SIZE equ <CCSIZEOF_STRUCT(TVINSERTSTRUCTW, item)>
        TVINSERTSTRUCTA struct
          hParent HTREEITEM ?
          hInsertAfter HTREEITEM ?
          union
            itemex TVITEMEXA <>
            item TV_ITEMA ?
          ends
        TVINSERTSTRUCTA ends
        tagTVINSERTSTRUCTA typedef TVINSERTSTRUCTA
        LPTVINSERTSTRUCTA typedef ptr TVINSERTSTRUCTA
        TVINSERTSTRUCTW struct
          hParent HTREEITEM ?
          hInsertAfter HTREEITEM ?
          union
            itemex TVITEMEXW <>
            item TV_ITEMW ?
          ends
        TVINSERTSTRUCTW ends
        tagTVINSERTSTRUCTW typedef TVINSERTSTRUCTW
        LPTVINSERTSTRUCTW typedef ptr TVINSERTSTRUCTW
        ifdef UNICODE
          TVINSERTSTRUCT equ <TVINSERTSTRUCTW>
          LPTVINSERTSTRUCT equ <LPTVINSERTSTRUCTW>
          TVINSERTSTRUCT_V1_SIZE equ <TVINSERTSTRUCTW_V1_SIZE>
        else
          TVINSERTSTRUCT equ <TVINSERTSTRUCTA>
          LPTVINSERTSTRUCT equ <LPTVINSERTSTRUCTA>
          TVINSERTSTRUCT_V1_SIZE equ <TVINSERTSTRUCTA_V1_SIZE>
        endif
        TVM_INSERTITEMA equ (TV_FIRST + 0)
        TVM_INSERTITEMW equ (TV_FIRST + 50)
        ifdef UNICODE
          TVM_INSERTITEM equ <TVM_INSERTITEMW>
        else
          TVM_INSERTITEM equ <TVM_INSERTITEMA>
        endif
        TreeView_InsertItem macro hwnd, lpis
          exitm <SNDMSG ((hwnd), TVM_INSERTITEM, 0, (LPTV_INSERTSTRUCT) (lpis))>
        endm
        TVM_DELETEITEM equ (TV_FIRST + 1)
        TreeView_DeleteItem macro hwnd, hitem
          exitm <SNDMSG ((hwnd), TVM_DELETEITEM, 0, (hitem))>
        endm
        TreeView_DeleteAllItems macro hwnd
          exitm <SNDMSG ((hwnd), TVM_DELETEITEM, 0, TVI_ROOT)>
        endm
        TVM_EXPAND equ (TV_FIRST + 2)
        TreeView_Expand macro hwnd, hitem, code
          exitm <SNDMSG ((hwnd), TVM_EXPAND, (code), (hitem))>
        endm
        TVE_COLLAPSE equ 0001h
        TVE_EXPAND equ 0002h
        TVE_TOGGLE equ 0003h
        TVE_EXPANDPARTIAL equ 4000h
        TVE_COLLAPSERESET equ 8000h
        TVM_GETITEMRECT equ (TV_FIRST + 4)
        TreeView_GetItemRect macro hwnd, hitem, prc, code
          exitm <(* (prc) = (hitem), SNDMSG ((hwnd), TVM_GETITEMRECT, (code), (RECT *) (prc)))>
        endm
        TVM_GETCOUNT equ (TV_FIRST + 5)
        TreeView_GetCount macro hwnd
          exitm <SNDMSG ((hwnd), TVM_GETCOUNT, 0, 0)>
        endm
        TVM_GETINDENT equ (TV_FIRST + 6)
        TreeView_GetIndent macro hwnd
          exitm <SNDMSG ((hwnd), TVM_GETINDENT, 0, 0)>
        endm
        TVM_SETINDENT equ (TV_FIRST + 7)
        TreeView_SetIndent macro hwnd, indent
          exitm <SNDMSG ((hwnd), TVM_SETINDENT, (indent), 0)>
        endm
        TVM_GETIMAGELIST equ (TV_FIRST + 8)
        TreeView_GetImageList macro hwnd, iImage
          exitm <SNDMSG ((hwnd), TVM_GETIMAGELIST, iImage, 0)>
        endm
        TVSIL_NORMAL equ 0
        TVSIL_STATE equ 2
        TVM_SETIMAGELIST equ (TV_FIRST + 9)
        TreeView_SetImageList macro hwnd, himl, iImage
          exitm <SNDMSG ((hwnd), TVM_SETIMAGELIST, iImage, (himl))>
        endm
        TVM_GETNEXTITEM equ (TV_FIRST + 10)
        TreeView_GetNextItem macro hwnd, hitem, code
          exitm <SNDMSG ((hwnd), TVM_GETNEXTITEM, (code), (hitem))>
        endm
        TVGN_ROOT equ 0000h
        TVGN_NEXT equ 0001h
        TVGN_PREVIOUS equ 0002h
        TVGN_PARENT equ 0003h
        TVGN_CHILD equ 0004h
        TVGN_FIRSTVISIBLE equ 0005h
        TVGN_NEXTVISIBLE equ 0006h
        TVGN_PREVIOUSVISIBLE equ 0007h
        TVGN_DROPHILITE equ 0008h
        TVGN_CARET equ 0009h
        TVGN_LASTVISIBLE equ 000Ah
        if (_WIN32_IE ge 0600h)
          TVGN_NEXTSELECTED equ 000Bh
        endif
        if (NTDDI_VERSION ge NTDDI_WINXP)
          TVSI_NOSINGLEEXPAND equ 8000h; Should not conflict with TVGN flags.

        endif
        TreeView_GetChild macro hwnd, hitem
          exitm <TreeView_GetNextItem(hwnd, hitem, TVGN_CHILD)>
        endm
        TreeView_GetNextSibling macro hwnd, hitem
          exitm <TreeView_GetNextItem(hwnd, hitem, TVGN_NEXT)>
        endm
        TreeView_GetPrevSibling macro hwnd, hitem
          exitm <TreeView_GetNextItem(hwnd, hitem, TVGN_PREVIOUS)>
        endm
        TreeView_GetParent macro hwnd, hitem
          exitm <TreeView_GetNextItem(hwnd, hitem, TVGN_PARENT)>
        endm
        TreeView_GetFirstVisible macro hwnd
          exitm <TreeView_GetNextItem(hwnd, NULL, TVGN_FIRSTVISIBLE)>
        endm
        TreeView_GetNextVisible macro hwnd, hitem
          exitm <TreeView_GetNextItem(hwnd, hitem, TVGN_NEXTVISIBLE)>
        endm
        TreeView_GetPrevVisible macro hwnd, hitem
          exitm <TreeView_GetNextItem(hwnd, hitem, TVGN_PREVIOUSVISIBLE)>
        endm
        TreeView_GetSelection macro hwnd
          exitm <TreeView_GetNextItem(hwnd, NULL, TVGN_CARET)>
        endm
        TreeView_GetDropHilight macro hwnd
          exitm <TreeView_GetNextItem(hwnd, NULL, TVGN_DROPHILITE)>
        endm
        TreeView_GetRoot macro hwnd
          exitm <TreeView_GetNextItem(hwnd, NULL, TVGN_ROOT)>
        endm
        TreeView_GetLastVisible macro hwnd
          exitm <TreeView_GetNextItem(hwnd, NULL, TVGN_LASTVISIBLE)>
        endm
        if (_WIN32_IE ge 0600h)
          TreeView_GetNextSelected macro hwnd, hitem
            exitm <TreeView_GetNextItem(hwnd, hitem, TVGN_NEXTSELECTED)>
          endm
        endif
        TVM_SELECTITEM equ (TV_FIRST + 11)
        TreeView_Select macro hwnd, hitem, code
          exitm <SNDMSG ((hwnd), TVM_SELECTITEM, (code), (hitem))>
        endm
        TreeView_SelectItem macro hwnd, hitem
          exitm <TreeView_Select(hwnd, hitem, TVGN_CARET)>
        endm
        TreeView_SelectDropTarget macro hwnd, hitem
          exitm <TreeView_Select(hwnd, hitem, TVGN_DROPHILITE)>
        endm
        TreeView_SelectSetFirstVisible macro hwnd, hitem
          exitm <TreeView_Select(hwnd, hitem, TVGN_FIRSTVISIBLE)>
        endm
        TVM_GETITEMA equ (TV_FIRST + 12)
        TVM_GETITEMW equ (TV_FIRST + 62)
        ifdef UNICODE
          TVM_GETITEM equ <TVM_GETITEMW>
        else
          TVM_GETITEM equ <TVM_GETITEMA>
        endif
        TreeView_GetItem macro hwnd, pitem
          exitm <SNDMSG ((hwnd), TVM_GETITEM, 0, (TV_ITEM *) (pitem))>
        endm
        TVM_SETITEMA equ (TV_FIRST + 13)
        TVM_SETITEMW equ (TV_FIRST + 63)
        ifdef UNICODE
          TVM_SETITEM equ <TVM_SETITEMW>
        else
          TVM_SETITEM equ <TVM_SETITEMA>
        endif
        TreeView_SetItem macro hwnd, pitem
          exitm <SNDMSG ((hwnd), TVM_SETITEM, 0, (const TV_ITEM *) (pitem))>
        endm
        TVM_EDITLABELA equ (TV_FIRST + 14)
        TVM_EDITLABELW equ (TV_FIRST + 65)
        ifdef UNICODE
          TVM_EDITLABEL equ <TVM_EDITLABELW>
        else
          TVM_EDITLABEL equ <TVM_EDITLABELA>
        endif
        TreeView_EditLabel macro hwnd, hitem
          exitm <SNDMSG ((hwnd), TVM_EDITLABEL, 0, (hitem))>
        endm
        TVM_GETEDITCONTROL equ (TV_FIRST + 15)
        TreeView_GetEditControl macro hwnd
          exitm <SNDMSG ((hwnd), TVM_GETEDITCONTROL, 0, 0)>
        endm
        TVM_GETVISIBLECOUNT equ (TV_FIRST + 16)
        TreeView_GetVisibleCount macro hwnd
          exitm <SNDMSG ((hwnd), TVM_GETVISIBLECOUNT, 0, 0)>
        endm
        TVM_HITTEST equ (TV_FIRST + 17)
        TreeView_HitTest macro hwnd, lpht
          exitm <SNDMSG ((hwnd), TVM_HITTEST, 0, (LPTV_HITTESTINFO) (lpht))>
        endm
        LPTV_HITTESTINFO equ <LPTVHITTESTINFO>
        TV_HITTESTINFO equ <TVHITTESTINFO>
        TVHITTESTINFO struct
          pt POINT <>
          flags DWORD ?
          hItem HTREEITEM ?
        TVHITTESTINFO ends
        tagTVHITTESTINFO typedef TVHITTESTINFO
        LPTVHITTESTINFO typedef ptr TVHITTESTINFO
        TVHT_NOWHERE equ 0001h
        TVHT_ONITEMICON equ 0002h
        TVHT_ONITEMLABEL equ 0004h
        TVHT_ONITEM equ <(TVHT_ONITEMICON or TVHT_ONITEMLABEL or TVHT_ONITEMSTATEICON)>
        TVHT_ONITEMINDENT equ 0008h
        TVHT_ONITEMBUTTON equ 0010h
        TVHT_ONITEMRIGHT equ 0020h
        TVHT_ONITEMSTATEICON equ 0040h
        TVHT_ABOVE equ 0100h
        TVHT_BELOW equ 0200h
        TVHT_TORIGHT equ 0400h
        TVHT_TOLEFT equ 0800h
        TVM_CREATEDRAGIMAGE equ (TV_FIRST + 18)
        TreeView_CreateDragImage macro hwnd, hitem
          exitm <SNDMSG ((hwnd), TVM_CREATEDRAGIMAGE, 0, (hitem))>
        endm
        TVM_SORTCHILDREN equ (TV_FIRST + 19)
        TreeView_SortChildren macro hwnd, hitem, recurse
          exitm <SNDMSG ((hwnd), TVM_SORTCHILDREN, (recurse), (hitem))>
        endm
        TVM_ENSUREVISIBLE equ (TV_FIRST + 20)
        TreeView_EnsureVisible macro hwnd, hitem
          exitm <SNDMSG ((hwnd), TVM_ENSUREVISIBLE, 0, (hitem))>
        endm
        TVM_SORTCHILDRENCB equ (TV_FIRST + 21)
        TreeView_SortChildrenCB macro hwnd, psort, recurse
          exitm <SNDMSG ((hwnd), TVM_SORTCHILDRENCB, (recurse), (LPTV_SORTCB) (psort))>
        endm
        TVM_ENDEDITLABELNOW equ (TV_FIRST + 22)
        TreeView_EndEditLabelNow macro hwnd, fCancel
          exitm <SNDMSG ((hwnd), TVM_ENDEDITLABELNOW, (fCancel), 0)>
        endm
        TVM_GETISEARCHSTRINGA equ (TV_FIRST + 23)
        TVM_GETISEARCHSTRINGW equ (TV_FIRST + 64)
        ifdef UNICODE
          TVM_GETISEARCHSTRING equ <TVM_GETISEARCHSTRINGW>
        else
          TVM_GETISEARCHSTRING equ <TVM_GETISEARCHSTRINGA>
        endif
        TVM_SETTOOLTIPS equ (TV_FIRST + 24)
        TreeView_SetToolTips macro hwnd, hwndTT
          exitm <SNDMSG ((hwnd), TVM_SETTOOLTIPS, (hwndTT), 0)>
        endm
        TVM_GETTOOLTIPS equ (TV_FIRST + 25)
        TreeView_GetToolTips macro hwnd
          exitm <SNDMSG ((hwnd), TVM_GETTOOLTIPS, 0, 0)>
        endm
        TreeView_GetISearchString macro hwndTV, lpsz
          exitm <SNDMSG ((hwndTV), TVM_GETISEARCHSTRING, 0, (LPTSTR) (lpsz))>
        endm
        TVM_SETINSERTMARK equ (TV_FIRST + 26)
        TreeView_SetInsertMark macro hwnd, hItem, fAfter
          exitm <SNDMSG ((hwnd), TVM_SETINSERTMARK, (fAfter), (hItem))>
        endm
        TVM_SETUNICODEFORMAT equ <CCM_SETUNICODEFORMAT>
        TreeView_SetUnicodeFormat macro hwnd, fUnicode
          exitm <SNDMSG ((hwnd), TVM_SETUNICODEFORMAT, (fUnicode), 0)>
        endm
        TVM_GETUNICODEFORMAT equ <CCM_GETUNICODEFORMAT>
        TreeView_GetUnicodeFormat macro hwnd
          exitm <SNDMSG ((hwnd), TVM_GETUNICODEFORMAT, 0, 0)>
        endm
        TVM_SETITEMHEIGHT equ (TV_FIRST + 27)
        TreeView_SetItemHeight macro hwnd, iHeight
          exitm <SNDMSG ((hwnd), TVM_SETITEMHEIGHT, (iHeight), 0)>
        endm
        TVM_GETITEMHEIGHT equ (TV_FIRST + 28)
        TreeView_GetItemHeight macro hwnd
          exitm <SNDMSG ((hwnd), TVM_GETITEMHEIGHT, 0, 0)>
        endm
        TVM_SETBKCOLOR equ (TV_FIRST + 29)
        TreeView_SetBkColor macro hwnd, clr
          exitm <SNDMSG ((hwnd), TVM_SETBKCOLOR, 0, (clr))>
        endm
        TVM_SETTEXTCOLOR equ (TV_FIRST + 30)
        TreeView_SetTextColor macro hwnd, clr
          exitm <SNDMSG ((hwnd), TVM_SETTEXTCOLOR, 0, (clr))>
        endm
        TVM_GETBKCOLOR equ (TV_FIRST + 31)
        TreeView_GetBkColor macro hwnd
          exitm <SNDMSG ((hwnd), TVM_GETBKCOLOR, 0, 0)>
        endm
        TVM_GETTEXTCOLOR equ (TV_FIRST + 32)
        TreeView_GetTextColor macro hwnd
          exitm <SNDMSG ((hwnd), TVM_GETTEXTCOLOR, 0, 0)>
        endm
        TVM_SETSCROLLTIME equ (TV_FIRST + 33)
        TreeView_SetScrollTime macro hwnd, uTime
          exitm <SNDMSG ((hwnd), TVM_SETSCROLLTIME, uTime, 0)>
        endm
        TVM_GETSCROLLTIME equ (TV_FIRST + 34)
        TreeView_GetScrollTime macro hwnd
          exitm <SNDMSG ((hwnd), TVM_GETSCROLLTIME, 0, 0)>
        endm
        TVM_SETINSERTMARKCOLOR equ (TV_FIRST + 37)
        TreeView_SetInsertMarkColor macro hwnd, clr
          exitm <SNDMSG ((hwnd), TVM_SETINSERTMARKCOLOR, 0, (clr))>
        endm
        TVM_GETINSERTMARKCOLOR equ (TV_FIRST + 38)
        TreeView_GetInsertMarkColor macro hwnd
          exitm <SNDMSG ((hwnd), TVM_GETINSERTMARKCOLOR, 0, 0)>
        endm
        TVM_SETBORDER equ (TV_FIRST + 35)
        TreeView_SetBorder macro hwnd, dwFlags, xBorder, yBorder
          exitm <SNDMSG ((hwnd), TVM_SETBORDER, (dwFlags), MAKELPARAM(xBorder, yBorder))>
        endm
        TVSBF_XBORDER equ 00000001h
        TVSBF_YBORDER equ 00000002h
        ; tvm_?etitemstate only uses mask, state and stateMask.
        ; so unicode or ansi is irrelevant.
        TreeView_SetItemState macro hwndTV, hti, data, _mask
          exitm <{ TVITEM _ms_TVi ; _ms_TVi.mask = TVIF_STATE ; _ms_TVi.hItem = (hti) ; _ms_TVi.stateMask = (_mask) ; _ms_TVi.state = (data) ; SNDMSG ((hwndTV), TVM_SETITEM, 0, (TV_ITEM *) and _ms_TVi) ; }>
        endm
        TreeView_SetCheckState macro hwndTV, hti, fCheck
          exitm <TreeView_SetItemState(hwndTV, hti, INDEXTOSTATEIMAGEMASK((fCheck) ?2 : 1), TVIS_STATEIMAGEMASK)>
        endm
        TVM_GETITEMSTATE equ (TV_FIRST + 39)
        TreeView_GetItemState macro hwndTV, hti, mask_
          exitm <SNDMSG ((hwndTV), TVM_GETITEMSTATE, (hti), (mask_))>
        endm
        TreeView_GetCheckState macro hwndTV, hti
          exitm <((((SNDMSG ((hwndTV), TVM_GETITEMSTATE, (hti), TVIS_STATEIMAGEMASK))) shr 12) - 1)>
        endm
        TVM_SETLINECOLOR equ (TV_FIRST + 40)
        TreeView_SetLineColor macro hwnd, clr
          exitm <SNDMSG ((hwnd), TVM_SETLINECOLOR, 0, (clr))>
        endm
        TVM_GETLINECOLOR equ (TV_FIRST + 41)
        TreeView_GetLineColor macro hwnd
          exitm <SNDMSG ((hwnd), TVM_GETLINECOLOR, 0, 0)>
        endm
        if (NTDDI_VERSION ge NTDDI_WINXP)
          TVM_MAPACCIDTOHTREEITEM equ (TV_FIRST + 42)
          TreeView_MapAccIDToHTREEITEM macro hwnd, id
            exitm <SNDMSG ((hwnd), TVM_MAPACCIDTOHTREEITEM, id, 0)>
          endm
          TVM_MAPHTREEITEMTOACCID equ (TV_FIRST + 43)
          TreeView_MapHTREEITEMToAccID macro hwnd, htreeitem
            exitm <SNDMSG ((hwnd), TVM_MAPHTREEITEMTOACCID, (htreeitem), 0)>
          endm
          TVM_SETEXTENDEDSTYLE equ (TV_FIRST + 44)
          TreeView_SetExtendedStyle macro hwnd, dw_, mask_
            exitm <SNDMSG ((hwnd), TVM_SETEXTENDEDSTYLE, mask_, dw_)>
          endm
          TVM_GETEXTENDEDSTYLE equ (TV_FIRST + 45)
          TreeView_GetExtendedStyle macro hwnd
            exitm <SNDMSG ((hwnd), TVM_GETEXTENDEDSTYLE, 0, 0)>
          endm
          TVM_SETAUTOSCROLLINFO equ (TV_FIRST + 59)
          TreeView_SetAutoScrollInfo macro hwnd, uPixPerSec, uUpdateTime
            exitm <SNDMSG ((hwnd), TVM_SETAUTOSCROLLINFO, (uPixPerSec), (uUpdateTime))>
          endm
        endif
        TVM_SETHOT equ (TV_FIRST + 58)
        TreeView_SetHot macro hwnd, hitem
          exitm <SNDMSG ((hwnd), TVM_SETHOT, 0, (hitem))>
        endm
        if (NTDDI_VERSION ge NTDDI_VISTA)
          TVM_GETSELECTEDCOUNT equ (TV_FIRST + 70)
          TreeView_GetSelectedCount macro hwnd
            exitm <SNDMSG ((hwnd), TVM_GETSELECTEDCOUNT, 0, 0)>
          endm
          TVM_SHOWINFOTIP equ (TV_FIRST + 71)
          TreeView_ShowInfoTip macro hwnd, hitem
            exitm <SNDMSG ((hwnd), TVM_SHOWINFOTIP, 0, (hitem))>
          endm
          TVITEMPART typedef SDWORD
          TVGIPR_BUTTON equ 0001h
          _TVITEMPART typedef TVITEMPART

          TVGETITEMPARTRECTINFO struct
            hti HTREEITEM ?
            prc POINTER ?
            partID TVITEMPART ?
          TVGETITEMPARTRECTINFO ends
          tagTVGETITEMPARTRECTINFO typedef TVGETITEMPARTRECTINFO
          TVM_GETITEMPARTRECT equ (TV_FIRST + 72)
          TreeView_GetItemPartRect macro hwnd, hitem, prc, partid
            exitm <{ TVGETITEMPARTRECTINFO info ; info.hti = (hitem) ; info.prc = (prc) ; info.partID = (partid) ; SNDMSG ((hwnd), TVM_GETITEMPARTRECT, 0, and info) ; }>
          endm
        endif
        TYPE_PFNTVCOMPARE typedef proto WIN_STD_CALL_CONV :LPARAM, :LPARAM, :LPARAM
        PFNTVCOMPARE typedef ptr TYPE_PFNTVCOMPARE

        LPTV_SORTCB equ <LPTVSORTCB>
        TV_SORTCB equ <TVSORTCB>
        TVSORTCB struct
          hParent HTREEITEM ?
          lpfnCompare PFNTVCOMPARE ?
          lParam LPARAM ?
        TVSORTCB ends
        tagTVSORTCB typedef TVSORTCB
        LPTVSORTCB typedef ptr TVSORTCB
        LPNM_TREEVIEWA equ <LPNMTREEVIEWA>
        LPNM_TREEVIEWW equ <LPNMTREEVIEWW>
        NM_TREEVIEWW equ <NMTREEVIEWW>
        NM_TREEVIEWA equ <NMTREEVIEWA>
        LPNM_TREEVIEW equ <LPNMTREEVIEW>
        NM_TREEVIEW equ <NMTREEVIEW>
        NMTREEVIEWA struct
          hdr NMHDR <>
          action DWORD ?
          itemOld TVITEMA <>
          itemNew TVITEMA <>
          ptDrag POINT <>
        NMTREEVIEWA ends
        tagNMTREEVIEWA typedef NMTREEVIEWA
        LPNMTREEVIEWA typedef ptr NMTREEVIEWA
        NMTREEVIEWW struct
          hdr NMHDR <>
          action DWORD ?
          itemOld TVITEMW <>
          itemNew TVITEMW <>
          ptDrag POINT <>
        NMTREEVIEWW ends
        tagNMTREEVIEWW typedef NMTREEVIEWW
        LPNMTREEVIEWW typedef ptr NMTREEVIEWW
        ifdef UNICODE
          NMTREEVIEW equ <NMTREEVIEWW>
          LPNMTREEVIEW equ <LPNMTREEVIEWW>
        else
          NMTREEVIEW equ <NMTREEVIEWA>
          LPNMTREEVIEW equ <LPNMTREEVIEWA>
        endif
        TVN_SELCHANGINGA equ (TVN_FIRST - 1)
        TVN_SELCHANGINGW equ (TVN_FIRST - 50)
        TVN_SELCHANGEDA equ (TVN_FIRST - 2)
        TVN_SELCHANGEDW equ (TVN_FIRST - 51)
        TVC_UNKNOWN equ 0000h
        TVC_BYMOUSE equ 0001h
        TVC_BYKEYBOARD equ 0002h
        TVN_GETDISPINFOA equ (TVN_FIRST - 3)
        TVN_GETDISPINFOW equ (TVN_FIRST - 52)
        TVN_SETDISPINFOA equ (TVN_FIRST - 4)
        TVN_SETDISPINFOW equ (TVN_FIRST - 53)
        TVIF_DI_SETITEM equ 1000h
        TV_DISPINFOA equ <NMTVDISPINFOA>
        TV_DISPINFOW equ <NMTVDISPINFOW>
        TV_DISPINFO equ <NMTVDISPINFO>
        NMTVDISPINFOA struct
          hdr NMHDR <>
          item TVITEMA <>
        NMTVDISPINFOA ends
        tagTVDISPINFOA typedef NMTVDISPINFOA
        LPNMTVDISPINFOA typedef ptr NMTVDISPINFOA
        NMTVDISPINFOW struct
          hdr NMHDR <>
          item TVITEMW <>
        NMTVDISPINFOW ends
        tagTVDISPINFOW typedef NMTVDISPINFOW
        LPNMTVDISPINFOW typedef ptr NMTVDISPINFOW
        ifdef UNICODE
          NMTVDISPINFO equ <NMTVDISPINFOW>
          LPNMTVDISPINFO equ <LPNMTVDISPINFOW>
        else
          NMTVDISPINFO equ <NMTVDISPINFOA>
          LPNMTVDISPINFO equ <LPNMTVDISPINFOA>
        endif
        if (_WIN32_IE ge 0600h)
          NMTVDISPINFOEXA struct
            hdr NMHDR <>
            item TVITEMEXA <>
          NMTVDISPINFOEXA ends
          tagTVDISPINFOEXA typedef NMTVDISPINFOEXA
          LPNMTVDISPINFOEXA typedef ptr NMTVDISPINFOEXA
          NMTVDISPINFOEXW struct
            hdr NMHDR <>
            item TVITEMEXW <>
          NMTVDISPINFOEXW ends
          tagTVDISPINFOEXW typedef NMTVDISPINFOEXW
          LPNMTVDISPINFOEXW typedef ptr NMTVDISPINFOEXW
          ifdef UNICODE
            NMTVDISPINFOEX equ <NMTVDISPINFOEXW>
            LPNMTVDISPINFOEX equ <LPNMTVDISPINFOEXW>
          else
            NMTVDISPINFOEX equ <NMTVDISPINFOEXA>
            LPNMTVDISPINFOEX equ <LPNMTVDISPINFOEXA>
          endif
          TV_DISPINFOEXA equ <NMTVDISPINFOEXA>
          TV_DISPINFOEXW equ <NMTVDISPINFOEXW>
          TV_DISPINFOEX equ <NMTVDISPINFOEX>
        endif
        TVN_ITEMEXPANDINGA equ (TVN_FIRST - 5)
        TVN_ITEMEXPANDINGW equ (TVN_FIRST - 54)
        TVN_ITEMEXPANDEDA equ (TVN_FIRST - 6)
        TVN_ITEMEXPANDEDW equ (TVN_FIRST - 55)
        TVN_BEGINDRAGA equ (TVN_FIRST - 7)
        TVN_BEGINDRAGW equ (TVN_FIRST - 56)
        TVN_BEGINRDRAGA equ (TVN_FIRST - 8)
        TVN_BEGINRDRAGW equ (TVN_FIRST - 57)
        TVN_DELETEITEMA equ (TVN_FIRST - 9)
        TVN_DELETEITEMW equ (TVN_FIRST - 58)
        TVN_BEGINLABELEDITA equ (TVN_FIRST - 10)
        TVN_BEGINLABELEDITW equ (TVN_FIRST - 59)
        TVN_ENDLABELEDITA equ (TVN_FIRST - 11)
        TVN_ENDLABELEDITW equ (TVN_FIRST - 60)
        TVN_KEYDOWN equ (TVN_FIRST - 12)
        TVN_GETINFOTIPA equ (TVN_FIRST - 13)
        TVN_GETINFOTIPW equ (TVN_FIRST - 14)
        TVN_SINGLEEXPAND equ (TVN_FIRST - 15)
        TVNRET_DEFAULT equ 0
        TVNRET_SKIPOLD equ 1
        TVNRET_SKIPNEW equ 2
        if (_WIN32_IE ge 0600h)
          TVN_ITEMCHANGINGA equ (TVN_FIRST - 16)
          TVN_ITEMCHANGINGW equ (TVN_FIRST - 17)
          TVN_ITEMCHANGEDA equ (TVN_FIRST - 18)
          TVN_ITEMCHANGEDW equ (TVN_FIRST - 19)
          TVN_ASYNCDRAW equ (TVN_FIRST - 20)
        endif
        TV_KEYDOWN equ <NMTVKEYDOWN>
        ifdef _WIN32
          include pshpack1.inc
        endif
        NMTVKEYDOWN struct
          hdr NMHDR <>
          wVKey WORD ?
          flags DWORD ?
        NMTVKEYDOWN ends
        tagTVKEYDOWN typedef NMTVKEYDOWN
        LPNMTVKEYDOWN typedef ptr NMTVKEYDOWN
        ifdef _WIN32
          include poppack.inc
        endif
        ifdef UNICODE
          TVN_SELCHANGING equ <TVN_SELCHANGINGW>
          TVN_SELCHANGED equ <TVN_SELCHANGEDW>
          TVN_GETDISPINFO equ <TVN_GETDISPINFOW>
          TVN_SETDISPINFO equ <TVN_SETDISPINFOW>
          TVN_ITEMEXPANDING equ <TVN_ITEMEXPANDINGW>
          TVN_ITEMEXPANDED equ <TVN_ITEMEXPANDEDW>
          TVN_BEGINDRAG equ <TVN_BEGINDRAGW>
          TVN_BEGINRDRAG equ <TVN_BEGINRDRAGW>
          TVN_DELETEITEM equ <TVN_DELETEITEMW>
          TVN_BEGINLABELEDIT equ <TVN_BEGINLABELEDITW>
          TVN_ENDLABELEDIT equ <TVN_ENDLABELEDITW>
        else
          TVN_SELCHANGING equ <TVN_SELCHANGINGA>
          TVN_SELCHANGED equ <TVN_SELCHANGEDA>
          TVN_GETDISPINFO equ <TVN_GETDISPINFOA>
          TVN_SETDISPINFO equ <TVN_SETDISPINFOA>
          TVN_ITEMEXPANDING equ <TVN_ITEMEXPANDINGA>
          TVN_ITEMEXPANDED equ <TVN_ITEMEXPANDEDA>
          TVN_BEGINDRAG equ <TVN_BEGINDRAGA>
          TVN_BEGINRDRAG equ <TVN_BEGINRDRAGA>
          TVN_DELETEITEM equ <TVN_DELETEITEMA>
          TVN_BEGINLABELEDIT equ <TVN_BEGINLABELEDITA>
          TVN_ENDLABELEDIT equ <TVN_ENDLABELEDITA>
        endif
        NMTVCUSTOMDRAW_V3_SIZE equ <CCSIZEOF_STRUCT(NMTVCUSTOMDRAW, clrTextBk)>
        NMTVCUSTOMDRAW struct
          nmcd NMCUSTOMDRAW <>
          clrText COLORREF ?
          clrTextBk COLORREF ?
          iLevel SDWORD ?
        NMTVCUSTOMDRAW ends
        tagNMTVCUSTOMDRAW typedef NMTVCUSTOMDRAW
        LPNMTVCUSTOMDRAW typedef ptr NMTVCUSTOMDRAW
        ; for tooltips
        NMTVGETINFOTIPA struct
          hdr NMHDR <>
          pszText POINTER ?
          cchTextMax SDWORD ?
          hItem HTREEITEM ?
          lParam LPARAM ?
        NMTVGETINFOTIPA ends
        tagNMTVGETINFOTIPA typedef NMTVGETINFOTIPA
        LPNMTVGETINFOTIPA typedef ptr NMTVGETINFOTIPA
        NMTVGETINFOTIPW struct
          hdr NMHDR <>
          pszText POINTER ?
          cchTextMax SDWORD ?
          hItem HTREEITEM ?
          lParam LPARAM ?
        NMTVGETINFOTIPW ends
        tagNMTVGETINFOTIPW typedef NMTVGETINFOTIPW
        LPNMTVGETINFOTIPW typedef ptr NMTVGETINFOTIPW
        ifdef UNICODE
          TVN_GETINFOTIP equ <TVN_GETINFOTIPW>
          NMTVGETINFOTIP equ <NMTVGETINFOTIPW>
          LPNMTVGETINFOTIP equ <LPNMTVGETINFOTIPW>
        else
          TVN_GETINFOTIP equ <TVN_GETINFOTIPA>
          NMTVGETINFOTIP equ <NMTVGETINFOTIPA>
          LPNMTVGETINFOTIP equ <LPNMTVGETINFOTIPA>
        endif
        ; treeview's customdraw return meaning don't draw images.  valid on CDRF_NOTIFYITEMPREPAINT
        TVCDRF_NOIMAGES equ 00010000h
        if (_WIN32_IE gt 0600h)
          NMTVITEMCHANGE struct
            hdr NMHDR <>
            uChanged DWORD ?
            hItem HTREEITEM ?
            uStateNew DWORD ?
            uStateOld DWORD ?
            lParam LPARAM ?
          NMTVITEMCHANGE ends
          tagTVITEMCHANGE typedef NMTVITEMCHANGE
          NMTVASYNCDRAW struct
            hdr NMHDR <>
            pimldp POINTER ?
            ; the draw that failed
            hr HRESULT ?
            ; why it failed
            hItem HTREEITEM ?
            ; item that failed to draw icon
            lParam LPARAM ?
            ; its data
            ; Out Params
            dwRetFlags DWORD ?
            ; What listview should do on return
            iRetImageIndex SDWORD ?
            ; used if ADRF_DRAWIMAGE is returned
          NMTVASYNCDRAW ends
          tagNMTVASYNCDRAW typedef NMTVASYNCDRAW
          ifdef UNICODE
            TVN_ITEMCHANGING equ <TVN_ITEMCHANGINGW>
            TVN_ITEMCHANGED equ <TVN_ITEMCHANGEDW>
          else
            TVN_ITEMCHANGING equ <TVN_ITEMCHANGINGA>
            TVN_ITEMCHANGED equ <TVN_ITEMCHANGEDA>
          endif
        endif
        ; _WIN32_IE >= 0x0600
      endif
      ; NOTREEVIEW
      ifndef NOUSEREXCONTROLS
        ;//////////////////  ComboBoxEx ////////////////////////////////
        WC_COMBOBOXEXW equ <L("ComboBoxEx32")>
        WC_COMBOBOXEXA equ <"ComboBoxEx32">
        ifdef UNICODE
          WC_COMBOBOXEX equ <WC_COMBOBOXEXW>
        else
          WC_COMBOBOXEX equ <WC_COMBOBOXEXA>
        endif
        CBEIF_TEXT equ 00000001h
        CBEIF_IMAGE equ 00000002h
        CBEIF_SELECTEDIMAGE equ 00000004h
        CBEIF_OVERLAY equ 00000008h
        CBEIF_INDENT equ 00000010h
        CBEIF_LPARAM equ 00000020h
        CBEIF_DI_SETITEM equ 10000000h
        COMBOBOXEXITEMA struct
          mask_ DWORD ?
          iItem SXWORD ?
          pszText POINTER ?
          cchTextMax SDWORD ?
          iImage SDWORD ?
          iSelectedImage SDWORD ?
          iOverlay SDWORD ?
          iIndent SDWORD ?
          lParam LPARAM ?
        COMBOBOXEXITEMA ends
        tagCOMBOBOXEXITEMA typedef COMBOBOXEXITEMA
        PCOMBOBOXEXITEMA typedef ptr COMBOBOXEXITEMA
        PCCOMBOEXITEMA typedef ptr COMBOBOXEXITEMA
        COMBOBOXEXITEMW struct
          mask_ DWORD ?
          iItem SXWORD ?
          pszText POINTER ?
          cchTextMax SDWORD ?
          iImage SDWORD ?
          iSelectedImage SDWORD ?
          iOverlay SDWORD ?
          iIndent SDWORD ?
          lParam LPARAM ?
        COMBOBOXEXITEMW ends
        tagCOMBOBOXEXITEMW typedef COMBOBOXEXITEMW
        PCOMBOBOXEXITEMW typedef ptr COMBOBOXEXITEMW
        PCCOMBOEXITEMW typedef ptr COMBOBOXEXITEMW
        ifdef UNICODE
          COMBOBOXEXITEM equ <COMBOBOXEXITEMW>
          PCOMBOBOXEXITEM equ <PCOMBOBOXEXITEMW>
          PCCOMBOBOXEXITEM equ <PCCOMBOBOXEXITEMW>
        else
          COMBOBOXEXITEM equ <COMBOBOXEXITEMA>
          PCOMBOBOXEXITEM equ <PCOMBOBOXEXITEMA>
          PCCOMBOBOXEXITEM equ <PCCOMBOBOXEXITEMA>
        endif
        CBEM_INSERTITEMA equ (WM_USER + 1)
        CBEM_SETIMAGELIST equ (WM_USER + 2)
        CBEM_GETIMAGELIST equ (WM_USER + 3)
        CBEM_GETITEMA equ (WM_USER + 4)
        CBEM_SETITEMA equ (WM_USER + 5)
        CBEM_DELETEITEM equ <CB_DELETESTRING>
        CBEM_GETCOMBOCONTROL equ (WM_USER + 6)
        CBEM_GETEDITCONTROL equ (WM_USER + 7)
        CBEM_SETEXSTYLE equ (WM_USER + 8); use  SETEXTENDEDSTYLE instead

        CBEM_SETEXTENDEDSTYLE equ (WM_USER + 14); lparam == new style, wParam (optional) == mask

        CBEM_GETEXSTYLE equ (WM_USER + 9); use GETEXTENDEDSTYLE instead

        CBEM_GETEXTENDEDSTYLE equ (WM_USER + 9)
        CBEM_SETUNICODEFORMAT equ <CCM_SETUNICODEFORMAT>
        CBEM_GETUNICODEFORMAT equ <CCM_GETUNICODEFORMAT>
        CBEM_HASEDITCHANGED equ (WM_USER + 10)
        CBEM_INSERTITEMW equ (WM_USER + 11)
        CBEM_SETITEMW equ (WM_USER + 12)
        CBEM_GETITEMW equ (WM_USER + 13)
        ifdef UNICODE
          CBEM_INSERTITEM equ <CBEM_INSERTITEMW>
          CBEM_SETITEM equ <CBEM_SETITEMW>
          CBEM_GETITEM equ <CBEM_GETITEMW>
        else
          CBEM_INSERTITEM equ <CBEM_INSERTITEMA>
          CBEM_SETITEM equ <CBEM_SETITEMA>
          CBEM_GETITEM equ <CBEM_GETITEMA>
        endif
        if (NTDDI_VERSION ge NTDDI_WINXP)
          CBEM_SETWINDOWTHEME equ <CCM_SETWINDOWTHEME>
        endif
        CBES_EX_NOEDITIMAGE equ 00000001h
        CBES_EX_NOEDITIMAGEINDENT equ 00000002h
        CBES_EX_PATHWORDBREAKPROC equ 00000004h
        CBES_EX_NOSIZELIMIT equ 00000008h
        CBES_EX_CASESENSITIVE equ 00000010h
        if (NTDDI_VERSION ge NTDDI_VISTA)
          CBES_EX_TEXTENDELLIPSIS equ 00000020h
        endif
        NMCOMBOBOXEXA struct
          hdr NMHDR <>
          ceItem COMBOBOXEXITEMA <>
        NMCOMBOBOXEXA ends
        PNMCOMBOBOXEXA typedef ptr NMCOMBOBOXEXA
        NMCOMBOBOXEXW struct
          hdr NMHDR <>
          ceItem COMBOBOXEXITEMW <>
        NMCOMBOBOXEXW ends
        PNMCOMBOBOXEXW typedef ptr NMCOMBOBOXEXW
        ifdef UNICODE
          NMCOMBOBOXEX equ <NMCOMBOBOXEXW>
          PNMCOMBOBOXEX equ <PNMCOMBOBOXEXW>
          CBEN_GETDISPINFO equ <CBEN_GETDISPINFOW>
        else
          NMCOMBOBOXEX equ <NMCOMBOBOXEXA>
          PNMCOMBOBOXEX equ <PNMCOMBOBOXEXA>
          CBEN_GETDISPINFO equ <CBEN_GETDISPINFOA>
        endif
        CBEN_GETDISPINFOA equ (CBEN_FIRST - 0)
        CBEN_INSERTITEM equ (CBEN_FIRST - 1)
        CBEN_DELETEITEM equ (CBEN_FIRST - 2)
        CBEN_BEGINEDIT equ (CBEN_FIRST - 4)
        CBEN_ENDEDITA equ (CBEN_FIRST - 5)
        CBEN_ENDEDITW equ (CBEN_FIRST - 6)
        CBEN_GETDISPINFOW equ (CBEN_FIRST - 7)
        CBEN_DRAGBEGINA equ (CBEN_FIRST - 8)
        CBEN_DRAGBEGINW equ (CBEN_FIRST - 9)
        ifdef UNICODE
          CBEN_DRAGBEGIN equ <CBEN_DRAGBEGINW>
        else
          CBEN_DRAGBEGIN equ <CBEN_DRAGBEGINA>
        endif
        ; lParam specifies why the endedit is happening
        ifdef UNICODE
          CBEN_ENDEDIT equ <CBEN_ENDEDITW>
        else
          CBEN_ENDEDIT equ <CBEN_ENDEDITA>
        endif
        CBENF_KILLFOCUS equ 1
        CBENF_RETURN equ 2
        CBENF_ESCAPE equ 3
        CBENF_DROPDOWN equ 4
        CBEMAXSTRLEN equ 260
        ; CBEN_DRAGBEGIN sends this information ...
        NMCBEDRAGBEGINW struct
          hdr NMHDR <>
          iItemid SDWORD ?
          szText WORD CBEMAXSTRLEN dup (?)
        NMCBEDRAGBEGINW ends
        LPNMCBEDRAGBEGINW typedef ptr NMCBEDRAGBEGINW
        PNMCBEDRAGBEGINW typedef ptr NMCBEDRAGBEGINW
        NMCBEDRAGBEGINA struct
          hdr NMHDR <>
          iItemid SDWORD ?
          szText SBYTE CBEMAXSTRLEN dup (?)
        NMCBEDRAGBEGINA ends
        LPNMCBEDRAGBEGINA typedef ptr NMCBEDRAGBEGINA
        PNMCBEDRAGBEGINA typedef ptr NMCBEDRAGBEGINA
        ifdef UNICODE
          NMCBEDRAGBEGIN equ <NMCBEDRAGBEGINW>
          LPNMCBEDRAGBEGIN equ <LPNMCBEDRAGBEGINW>
          PNMCBEDRAGBEGIN equ <PNMCBEDRAGBEGINW>
        else
          NMCBEDRAGBEGIN equ <NMCBEDRAGBEGINA>
          LPNMCBEDRAGBEGIN equ <LPNMCBEDRAGBEGINA>
          PNMCBEDRAGBEGIN equ <PNMCBEDRAGBEGINA>
        endif
        ; CBEN_ENDEDIT sends this information...
        ; fChanged if the user actually did anything
        ; iNewSelection gives what would be the new selection unless the notify is failed
        ;                      iNewSelection may be CB_ERR if there's no match
        NMCBEENDEDITW struct
          hdr NMHDR <>
          fChanged DWORD ?
          iNewSelection SDWORD ?
          szText WORD CBEMAXSTRLEN dup (?)
          iWhy SDWORD ?
        NMCBEENDEDITW ends
        LPNMCBEENDEDITW typedef ptr NMCBEENDEDITW
        PNMCBEENDEDITW typedef ptr NMCBEENDEDITW
        NMCBEENDEDITA struct
          hdr NMHDR <>
          fChanged DWORD ?
          iNewSelection SDWORD ?
          szText SBYTE CBEMAXSTRLEN dup (?)
          iWhy SDWORD ?
        NMCBEENDEDITA ends
        LPNMCBEENDEDITA typedef ptr NMCBEENDEDITA
        PNMCBEENDEDITA typedef ptr NMCBEENDEDITA
        ifdef UNICODE
          NMCBEENDEDIT equ <NMCBEENDEDITW>
          LPNMCBEENDEDIT equ <LPNMCBEENDEDITW>
          PNMCBEENDEDIT equ <PNMCBEENDEDITW>
        else
          NMCBEENDEDIT equ <NMCBEENDEDITA>
          LPNMCBEENDEDIT equ <LPNMCBEENDEDITA>
          PNMCBEENDEDIT equ <PNMCBEENDEDITA>
        endif
      endif
      ;====== TAB CONTROL ==========================================================
      ifndef NOTABCONTROL
        ifdef _WIN32
          WC_TABCONTROLA equ <"SysTabControl32">
          WC_TABCONTROLW equ <L("SysTabControl32")>
          ifdef UNICODE
            WC_TABCONTROL equ <WC_TABCONTROLW>
          else
            WC_TABCONTROL equ <WC_TABCONTROLA>
          endif
        else
          ;[...]
        endif
        ; begin_r_commctrl
        TCS_SCROLLOPPOSITE equ 0001h; assumes multiline tab

        TCS_BOTTOM equ 0002h
        TCS_RIGHT equ 0002h
        TCS_MULTISELECT equ 0004h; allow multi-select in button mode

        TCS_FLATBUTTONS equ 0008h
        TCS_FORCEICONLEFT equ 0010h
        TCS_FORCELABELLEFT equ 0020h
        TCS_HOTTRACK equ 0040h
        TCS_VERTICAL equ 0080h
        TCS_TABS equ 0000h
        TCS_BUTTONS equ 0100h
        TCS_SINGLELINE equ 0000h
        TCS_MULTILINE equ 0200h
        TCS_RIGHTJUSTIFY equ 0000h
        TCS_FIXEDWIDTH equ 0400h
        TCS_RAGGEDRIGHT equ 0800h
        TCS_FOCUSONBUTTONDOWN equ 1000h
        TCS_OWNERDRAWFIXED equ 2000h
        TCS_TOOLTIPS equ 4000h
        TCS_FOCUSNEVER equ 8000h
        ; end_r_commctrl
        ; EX styles for use with TCM_SETEXTENDEDSTYLE
        TCS_EX_FLATSEPARATORS equ 00000001h
        TCS_EX_REGISTERDROP equ 00000002h
        TCM_GETIMAGELIST equ (TCM_FIRST + 2)
        TabCtrl_GetImageList macro hwnd
          exitm <SNDMSG ((hwnd), TCM_GETIMAGELIST, 0, 0)>
        endm
        TCM_SETIMAGELIST equ (TCM_FIRST + 3)
        TabCtrl_SetImageList macro hwnd, himl
          exitm <SNDMSG ((hwnd), TCM_SETIMAGELIST, 0, (himl))>
        endm
        TCM_GETITEMCOUNT equ (TCM_FIRST + 4)
        TabCtrl_GetItemCount macro hwnd
          exitm <SNDMSG ((hwnd), TCM_GETITEMCOUNT, 0, 0)>
        endm
        TCIF_TEXT equ 0001h
        TCIF_IMAGE equ 0002h
        TCIF_RTLREADING equ 0004h
        TCIF_PARAM equ 0008h
        TCIF_STATE equ 0010h
        TCIS_BUTTONPRESSED equ 0001h
        TCIS_HIGHLIGHTED equ 0002h
        TC_ITEMHEADERA equ <TCITEMHEADERA>
        TC_ITEMHEADERW equ <TCITEMHEADERW>
        TC_ITEMHEADER equ <TCITEMHEADER>
        TCITEMHEADERA struct
          mask_ DWORD ?
          lpReserved1 DWORD ?
          lpReserved2 DWORD ?
          pszText POINTER ?
          cchTextMax SDWORD ?
          iImage SDWORD ?
        TCITEMHEADERA ends
        tagTCITEMHEADERA typedef TCITEMHEADERA
        LPTCITEMHEADERA typedef ptr TCITEMHEADERA
        TCITEMHEADERW struct
          mask_ DWORD ?
          lpReserved1 DWORD ?
          lpReserved2 DWORD ?
          pszText POINTER ?
          cchTextMax SDWORD ?
          iImage SDWORD ?
        TCITEMHEADERW ends
        tagTCITEMHEADERW typedef TCITEMHEADERW
        LPTCITEMHEADERW typedef ptr TCITEMHEADERW
        ifdef UNICODE
          TCITEMHEADER equ <TCITEMHEADERW>
          LPTCITEMHEADER equ <LPTCITEMHEADERW>
        else
          TCITEMHEADER equ <TCITEMHEADERA>
          LPTCITEMHEADER equ <LPTCITEMHEADERA>
        endif
        TC_ITEMA equ <TCITEMA>
        TC_ITEMW equ <TCITEMW>
        TC_ITEM equ <TCITEM>
        TCITEMA struct
          mask_ DWORD ?
          dwState DWORD ?
          dwStateMask DWORD ?
          pszText POINTER ?
          cchTextMax SDWORD ?
          iImage SDWORD ?
          lParam LPARAM ?
        TCITEMA ends
        tagTCITEMA typedef TCITEMA
        LPTCITEMA typedef ptr TCITEMA
        TCITEMW struct
          mask_ DWORD ?
          dwState DWORD ?
          dwStateMask DWORD ?
          pszText POINTER ?
          cchTextMax SDWORD ?
          iImage SDWORD ?
          lParam LPARAM ?
        TCITEMW ends
        tagTCITEMW typedef TCITEMW
        LPTCITEMW typedef ptr TCITEMW
        ifdef UNICODE
          TCITEM equ <TCITEMW>
          LPTCITEM equ <LPTCITEMW>
        else
          TCITEM equ <TCITEMA>
          LPTCITEM equ <LPTCITEMA>
        endif
        TCM_GETITEMA equ (TCM_FIRST + 5)
        TCM_GETITEMW equ (TCM_FIRST + 60)
        ifdef UNICODE
          TCM_GETITEM equ <TCM_GETITEMW>
        else
          TCM_GETITEM equ <TCM_GETITEMA>
        endif
        TabCtrl_GetItem macro hwnd, iItem, pitem
          exitm <SNDMSG ((hwnd), TCM_GETITEM, (iItem), (TC_ITEM *) (pitem))>
        endm
        TCM_SETITEMA equ (TCM_FIRST + 6)
        TCM_SETITEMW equ (TCM_FIRST + 61)
        ifdef UNICODE
          TCM_SETITEM equ <TCM_SETITEMW>
        else
          TCM_SETITEM equ <TCM_SETITEMA>
        endif
        TabCtrl_SetItem macro hwnd, iItem, pitem
          exitm <SNDMSG ((hwnd), TCM_SETITEM, (iItem), (TC_ITEM *) (pitem))>
        endm
        TCM_INSERTITEMA equ (TCM_FIRST + 7)
        TCM_INSERTITEMW equ (TCM_FIRST + 62)
        ifdef UNICODE
          TCM_INSERTITEM equ <TCM_INSERTITEMW>
        else
          TCM_INSERTITEM equ <TCM_INSERTITEMA>
        endif
        TabCtrl_InsertItem macro hwnd, iItem, pitem
          exitm <SNDMSG ((hwnd), TCM_INSERTITEM, (iItem), (const TC_ITEM *) (pitem))>
        endm
        TCM_DELETEITEM equ (TCM_FIRST + 8)
        TabCtrl_DeleteItem macro hwnd, i
          exitm <SNDMSG ((hwnd), TCM_DELETEITEM, (i), 0)>
        endm
        TCM_DELETEALLITEMS equ (TCM_FIRST + 9)
        TabCtrl_DeleteAllItems macro hwnd
          exitm <SNDMSG ((hwnd), TCM_DELETEALLITEMS, 0, 0)>
        endm
        TCM_GETITEMRECT equ (TCM_FIRST + 10)
        TabCtrl_GetItemRect macro hwnd, i, prc
          exitm <SNDMSG ((hwnd), TCM_GETITEMRECT, (i), (RECT *) (prc))>
        endm
        TCM_GETCURSEL equ (TCM_FIRST + 11)
        TabCtrl_GetCurSel macro hwnd
          exitm <SNDMSG ((hwnd), TCM_GETCURSEL, 0, 0)>
        endm
        TCM_SETCURSEL equ (TCM_FIRST + 12)
        TabCtrl_SetCurSel macro hwnd, i
          exitm <SNDMSG ((hwnd), TCM_SETCURSEL, (i), 0)>
        endm
        TCHT_NOWHERE equ 0001h
        TCHT_ONITEMICON equ 0002h
        TCHT_ONITEMLABEL equ 0004h
        TCHT_ONITEM equ <(TCHT_ONITEMICON or TCHT_ONITEMLABEL)>
        LPTC_HITTESTINFO equ <LPTCHITTESTINFO>
        TC_HITTESTINFO equ <TCHITTESTINFO>
        TCHITTESTINFO struct
          pt POINT <>
          flags DWORD ?
        TCHITTESTINFO ends
        tagTCHITTESTINFO typedef TCHITTESTINFO
        LPTCHITTESTINFO typedef ptr TCHITTESTINFO
        TCM_HITTEST equ (TCM_FIRST + 13)
        TabCtrl_HitTest macro hwndTC, pinfo
          exitm <SNDMSG ((hwndTC), TCM_HITTEST, 0, (TC_HITTESTINFO *) (pinfo))>
        endm
        TCM_SETITEMEXTRA equ (TCM_FIRST + 14)
        TabCtrl_SetItemExtra macro hwndTC, cb
          exitm <SNDMSG ((hwndTC), TCM_SETITEMEXTRA, (cb), 0)>
        endm
        TCM_ADJUSTRECT equ (TCM_FIRST + 40)
        TabCtrl_AdjustRect macro hwnd, bLarger, prc
          exitm <SNDMSG (hwnd, TCM_ADJUSTRECT, (bLarger), (RECT *) (prc))>
        endm
        TCM_SETITEMSIZE equ (TCM_FIRST + 41)
        TabCtrl_SetItemSize macro hwnd, x, y
          exitm <SNDMSG ((hwnd), TCM_SETITEMSIZE, 0, MAKELPARAM(x, y))>
        endm
        TCM_REMOVEIMAGE equ (TCM_FIRST + 42)
        TabCtrl_RemoveImage macro hwnd, i
          exitm <SNDMSG ((hwnd), TCM_REMOVEIMAGE, i, 0)>
        endm
        TCM_SETPADDING equ (TCM_FIRST + 43)
        TabCtrl_SetPadding macro hwnd, cx_, cy
          exitm <SNDMSG ((hwnd), TCM_SETPADDING, 0, MAKELPARAM(cx_, cy))>
        endm
        TCM_GETROWCOUNT equ (TCM_FIRST + 44)
        TabCtrl_GetRowCount macro hwnd
          exitm <SNDMSG ((hwnd), TCM_GETROWCOUNT, 0, 0)>
        endm
        TCM_GETTOOLTIPS equ (TCM_FIRST + 45)
        TabCtrl_GetToolTips macro hwnd
          exitm <SNDMSG ((hwnd), TCM_GETTOOLTIPS, 0, 0)>
        endm
        TCM_SETTOOLTIPS equ (TCM_FIRST + 46)
        TabCtrl_SetToolTips macro hwnd, hwndTT
          exitm <SNDMSG ((hwnd), TCM_SETTOOLTIPS, (hwndTT), 0)>
        endm
        TCM_GETCURFOCUS equ (TCM_FIRST + 47)
        TabCtrl_GetCurFocus macro hwnd
          exitm <SNDMSG ((hwnd), TCM_GETCURFOCUS, 0, 0)>
        endm
        TCM_SETCURFOCUS equ (TCM_FIRST + 48)
        TabCtrl_SetCurFocus macro hwnd, i
          exitm <SNDMSG ((hwnd), TCM_SETCURFOCUS, i, 0)>
        endm
        TCM_SETMINTABWIDTH equ (TCM_FIRST + 49)
        TabCtrl_SetMinTabWidth macro hwnd, x
          exitm <SNDMSG ((hwnd), TCM_SETMINTABWIDTH, 0, x)>
        endm
        TCM_DESELECTALL equ (TCM_FIRST + 50)
        TabCtrl_DeselectAll macro hwnd, fExcludeFocus
          exitm <SNDMSG ((hwnd), TCM_DESELECTALL, fExcludeFocus, 0)>
        endm
        TCM_HIGHLIGHTITEM equ (TCM_FIRST + 51)
        TabCtrl_HighlightItem macro hwnd, i, fHighlight
          exitm <SNDMSG ((hwnd), TCM_HIGHLIGHTITEM, (i), MAKELONG(fHighlight, 0))>
        endm
        TCM_SETEXTENDEDSTYLE equ (TCM_FIRST + 52); optional wParam == mask

        TabCtrl_SetExtendedStyle macro hwnd, dw_
          exitm <SNDMSG ((hwnd), TCM_SETEXTENDEDSTYLE, 0, dw_)>
        endm
        TCM_GETEXTENDEDSTYLE equ (TCM_FIRST + 53)
        TabCtrl_GetExtendedStyle macro hwnd
          exitm <SNDMSG ((hwnd), TCM_GETEXTENDEDSTYLE, 0, 0)>
        endm
        TCM_SETUNICODEFORMAT equ <CCM_SETUNICODEFORMAT>
        TabCtrl_SetUnicodeFormat macro hwnd, fUnicode
          exitm <SNDMSG ((hwnd), TCM_SETUNICODEFORMAT, (fUnicode), 0)>
        endm
        TCM_GETUNICODEFORMAT equ <CCM_GETUNICODEFORMAT>
        TabCtrl_GetUnicodeFormat macro hwnd
          exitm <SNDMSG ((hwnd), TCM_GETUNICODEFORMAT, 0, 0)>
        endm
        TCN_KEYDOWN equ (TCN_FIRST - 0)
        TC_KEYDOWN equ <NMTCKEYDOWN>
        ifdef _WIN32
          include pshpack1.inc
        endif
        NMTCKEYDOWN struct
          hdr NMHDR <>
          wVKey WORD ?
          flags DWORD ?
        NMTCKEYDOWN ends
        tagTCKEYDOWN typedef NMTCKEYDOWN
        ifdef _WIN32
          include poppack.inc
        endif
        TCN_SELCHANGE equ (TCN_FIRST - 1)
        TCN_SELCHANGING equ (TCN_FIRST - 2)
        TCN_GETOBJECT equ (TCN_FIRST - 3)
        TCN_FOCUSCHANGE equ (TCN_FIRST - 4)
      endif
      ; NOTABCONTROL
      ;====== ANIMATE CONTROL ======================================================
      ifndef NOANIMATE
        ifdef _WIN32
          ANIMATE_CLASSW equ <L("SysAnimate32")>
          ANIMATE_CLASSA equ <"SysAnimate32">
          ifdef UNICODE
            ANIMATE_CLASS equ <ANIMATE_CLASSW>
          else
            ANIMATE_CLASS equ <ANIMATE_CLASSA>
          endif
          ; begin_r_commctrl
          ACS_CENTER equ 0001h
          ACS_TRANSPARENT equ 0002h
          ACS_AUTOPLAY equ 0004h
          ACS_TIMER equ 0008h; don't use threads... use timers

          ; end_r_commctrl
          ACM_OPENA equ (WM_USER + 100)
          ACM_OPENW equ (WM_USER + 103)
          ifdef UNICODE
            ACM_OPEN equ <ACM_OPENW>
          else
            ACM_OPEN equ <ACM_OPENA>
          endif
          ACM_PLAY equ (WM_USER + 101)
          ACM_STOP equ (WM_USER + 102)
          ACM_ISPLAYING equ (WM_USER + 104)
          ACN_START equ 1
          ACN_STOP equ 2
          Animate_Create macro hwndP, id, dwStyle, hInstance
            exitm <CreateWindow (ANIMATE_CLASS, NULL, dwStyle, 0, 0, 0, 0, hwndP, (HMENU) (id), hInstance, NULL)>
          endm
          Animate_Open macro hwnd, szName
            exitm <SNDMSG (hwnd, ACM_OPEN, 0, (LPTSTR) (szName))>
          endm
          Animate_OpenEx macro hwnd, hInst, szName
            exitm <SNDMSG (hwnd, ACM_OPEN, (hInst), (LPTSTR) (szName))>
          endm
          Animate_Play macro hwnd, from, to, rep_
            exitm <SNDMSG (hwnd, ACM_PLAY, (rep_), MAKELONG(from, to))>
          endm
          Animate_Stop macro hwnd
            exitm <SNDMSG (hwnd, ACM_STOP, 0, 0)>
          endm
          Animate_IsPlaying macro hwnd
            exitm <SNDMSG (hwnd, ACM_ISPLAYING, 0, 0)>
          endm
          Animate_Close macro hwnd
            exitm <Animate_Open(hwnd, NULL)>
          endm
          Animate_Seek macro hwnd, frame_
            exitm <Animate_Play(hwnd, frame_, frame_, 1)>
          endm
        endif
      endif
      ; NOANIMATE
      ;====== MONTHCAL CONTROL ======================================================
      ifndef NOMONTHCAL
        ifdef _WIN32
          MONTHCAL_CLASSW equ <L("SysMonthCal32")>
          MONTHCAL_CLASSA equ <"SysMonthCal32">
          ifdef UNICODE
            MONTHCAL_CLASS equ <MONTHCAL_CLASSW>
          else
            MONTHCAL_CLASS equ <MONTHCAL_CLASSA>
          endif
          ; bit-packed array of "bold" info for a month
          ; if a bit is on, that day is drawn bold
          MONTHDAYSTATE typedef DWORD
          LPMONTHDAYSTATE typedef ptr DWORD
          MCM_FIRST equ 1000h
          ; BOOL MonthCal_GetCurSel(HWND hmc, LPSYSTEMTIME pst)
          ;   returns FALSE if MCS_MULTISELECT
          ;   returns TRUE and sets *pst to the currently selected date otherwise
          MCM_GETCURSEL equ (MCM_FIRST + 1)
          MonthCal_GetCurSel macro hmc, pst
            exitm <SNDMSG (hmc, MCM_GETCURSEL, 0, (pst))>
          endm
          ; BOOL MonthCal_SetCurSel(HWND hmc, LPSYSTEMTIME pst)
          ;   returns FALSE if MCS_MULTISELECT
          ;   returns TURE and sets the currently selected date to *pst otherwise
          MCM_SETCURSEL equ (MCM_FIRST + 2)
          MonthCal_SetCurSel macro hmc, pst
            exitm <SNDMSG (hmc, MCM_SETCURSEL, 0, (pst))>
          endm
          ; DWORD MonthCal_GetMaxSelCount(HWND hmc)
          ;   returns the maximum number of selectable days allowed
          MCM_GETMAXSELCOUNT equ (MCM_FIRST + 3)
          MonthCal_GetMaxSelCount macro hmc
            exitm <SNDMSG (hmc, MCM_GETMAXSELCOUNT, 0, 0)>
          endm
          ; BOOL MonthCal_SetMaxSelCount(HWND hmc, UINT n)
          ;   sets the max number days that can be selected iff MCS_MULTISELECT
          MCM_SETMAXSELCOUNT equ (MCM_FIRST + 4)
          MonthCal_SetMaxSelCount macro hmc, n
            exitm <SNDMSG (hmc, MCM_SETMAXSELCOUNT, (n), 0)>
          endm
          ; BOOL MonthCal_GetSelRange(HWND hmc, LPSYSTEMTIME rgst)
          ;   sets rgst[0] to the first day of the selection range
          ;   sets rgst[1] to the last day of the selection range
          MCM_GETSELRANGE equ (MCM_FIRST + 5)
          MonthCal_GetSelRange macro hmc, rgst
            exitm <SNDMSG (hmc, MCM_GETSELRANGE, 0, (rgst))>
          endm
          ; BOOL MonthCal_SetSelRange(HWND hmc, LPSYSTEMTIME rgst)
          ;   selects the range of days from rgst[0] to rgst[1]
          MCM_SETSELRANGE equ (MCM_FIRST + 6)
          MonthCal_SetSelRange macro hmc, rgst
            exitm <SNDMSG (hmc, MCM_SETSELRANGE, 0, (rgst))>
          endm
          ; DWORD MonthCal_GetMonthRange(HWND hmc, DWORD gmr, LPSYSTEMTIME rgst)
          ;   if rgst specified, sets rgst[0] to the starting date and
          ;      and rgst[1] to the ending date of the the selectable (non-grayed)
          ;      days if GMR_VISIBLE or all the displayed days (including grayed)
          ;      if GMR_DAYSTATE.
          ;   returns the number of months spanned by the above range.
          MCM_GETMONTHRANGE equ (MCM_FIRST + 7)
          MonthCal_GetMonthRange macro hmc, gmr, rgst
            exitm <SNDMSG (hmc, MCM_GETMONTHRANGE, (gmr), (rgst))>
          endm
          ; BOOL MonthCal_SetDayState(HWND hmc, int cbds, DAYSTATE *rgds)
          ;   cbds is the count of DAYSTATE items in rgds and it must be equal
          ;   to the value returned from MonthCal_GetMonthRange(hmc, GMR_DAYSTATE, NULL)
          ;   This sets the DAYSTATE bits for each month (grayed and non-grayed
          ;   days) displayed in the calendar. The first bit in a month's DAYSTATE
          ;   corresponts to bolding day 1, the second bit affects day 2, etc.
          MCM_SETDAYSTATE equ (MCM_FIRST + 8)
          MonthCal_SetDayState macro hmc, cbds, rgds
            exitm <SNDMSG (hmc, MCM_SETDAYSTATE, (cbds), (rgds))>
          endm
          ; BOOL MonthCal_GetMinReqRect(HWND hmc, LPRECT prc)
          ;   sets *prc the minimal size needed to display one month
          ;   To display two months, undo the AdjustWindowRect calculation already done to
          ;   this rect, double the width, and redo the AdjustWindowRect calculation --
          ;   the monthcal control will display two calendars in this window (if you also
          ;   double the vertical size, you will get 4 calendars)
          ;   NOTE: if you want to gurantee that the "Today" string is not clipped,
          ;   get the MCM_GETMAXTODAYWIDTH and use the max of that width and this width
          MCM_GETMINREQRECT equ (MCM_FIRST + 9)
          MonthCal_GetMinReqRect macro hmc, prc
            exitm <SNDMSG (hmc, MCM_GETMINREQRECT, 0, (prc))>
          endm
          ; set colors to draw control with -- see MCSC_ bits below
          MCM_SETCOLOR equ (MCM_FIRST + 10)
          MonthCal_SetColor macro hmc, iColor, clr
            exitm <SNDMSG (hmc, MCM_SETCOLOR, iColor, clr)>
          endm
          MCM_GETCOLOR equ (MCM_FIRST + 11)
          MonthCal_GetColor macro hmc, iColor
            exitm <SNDMSG (hmc, MCM_GETCOLOR, iColor, 0)>
          endm
          MCSC_BACKGROUND equ 0; the background color (between months)

          MCSC_TEXT equ 1; the dates

          MCSC_TITLEBK equ 2; background of the title

          MCSC_TITLETEXT equ 3
          MCSC_MONTHBK equ 4; background within the month cal

          MCSC_TRAILINGTEXT equ 5; the text color of header & trailing days

          ; set what day is "today"   send NULL to revert back to real date
          MCM_SETTODAY equ (MCM_FIRST + 12)
          MonthCal_SetToday macro hmc, pst
            exitm <SNDMSG (hmc, MCM_SETTODAY, 0, (pst))>
          endm
          ; get what day is "today"
          ; returns BOOL for success/failure
          MCM_GETTODAY equ (MCM_FIRST + 13)
          MonthCal_GetToday macro hmc, pst
            exitm <SNDMSG (hmc, MCM_GETTODAY, 0, (pst))>
          endm
          ; determine what pinfo->pt is over
          MCM_HITTEST equ (MCM_FIRST + 14)
          MonthCal_HitTest macro hmc, pinfo
            exitm <SNDMSG (hmc, MCM_HITTEST, 0, (PMCHITTESTINFO) (pinfo))>
          endm
          MCHITTESTINFO struct
            cbSize DWORD ?
            pt POINT <>
            uHit DWORD ?
            ; out param
            st_ SYSTEMTIME <>
            if (NTDDI_VERSION ge NTDDI_VISTA)
              rc RECT <>
              iOffset SDWORD ?
              iRow SDWORD ?
              iCol SDWORD ?
            endif
          MCHITTESTINFO ends
          PMCHITTESTINFO typedef ptr MCHITTESTINFO
          MCHITTESTINFO_V1_SIZE equ <CCSIZEOF_STRUCT(MCHITTESTINFO, st)>
          MCHT_TITLE equ 00010000h
          MCHT_CALENDAR equ 00020000h
          MCHT_TODAYLINK equ 00030000h
          if (NTDDI_VERSION ge NTDDI_VISTA)
            MCHT_CALENDARCONTROL equ 00100000h
          endif
          MCHT_NEXT equ 01000000h; these indicate that hitting

          MCHT_PREV equ 02000000h; here will go to the next/prev month

          MCHT_NOWHERE equ 00000000h
          MCHT_TITLEBK equ <(MCHT_TITLE)>
          MCHT_TITLEMONTH equ (MCHT_TITLE or 0001h)
          MCHT_TITLEYEAR equ (MCHT_TITLE or 0002h)
          MCHT_TITLEBTNNEXT equ (MCHT_TITLE or MCHT_NEXT or 0003h)
          MCHT_TITLEBTNPREV equ (MCHT_TITLE or MCHT_PREV or 0003h)
          MCHT_CALENDARBK equ <(MCHT_CALENDAR)>
          MCHT_CALENDARDATE equ (MCHT_CALENDAR or 0001h)
          MCHT_CALENDARDATENEXT equ <(MCHT_CALENDARDATE or MCHT_NEXT)>
          MCHT_CALENDARDATEPREV equ <(MCHT_CALENDARDATE or MCHT_PREV)>
          MCHT_CALENDARDAY equ (MCHT_CALENDAR or 0002h)
          MCHT_CALENDARWEEKNUM equ (MCHT_CALENDAR or 0003h)
          MCHT_CALENDARDATEMIN equ (MCHT_CALENDAR or 0004h)
          MCHT_CALENDARDATEMAX equ (MCHT_CALENDAR or 0005h)
          ; set first day of week to iDay:
          ; 0 for Monday, 1 for Tuesday, ..., 6 for Sunday
          ; -1 for means use locale info
          MCM_SETFIRSTDAYOFWEEK equ (MCM_FIRST + 15)
          MonthCal_SetFirstDayOfWeek macro hmc, iDay
            exitm <SNDMSG (hmc, MCM_SETFIRSTDAYOFWEEK, 0, iDay)>
          endm
          ; DWORD result...  low word has the day.  high word is bool if this is app set
          ; or not (FALSE == using locale info)
          MCM_GETFIRSTDAYOFWEEK equ (MCM_FIRST + 16)
          MonthCal_GetFirstDayOfWeek macro hmc
            exitm <SNDMSG (hmc, MCM_GETFIRSTDAYOFWEEK, 0, 0)>
          endm
          ; DWORD MonthCal_GetRange(HWND hmc, LPSYSTEMTIME rgst)
          ;   modifies rgst[0] to be the minimum ALLOWABLE systemtime (or 0 if no minimum)
          ;   modifies rgst[1] to be the maximum ALLOWABLE systemtime (or 0 if no maximum)
          ;   returns GDTR_MIN|GDTR_MAX if there is a minimum|maximum limit
          MCM_GETRANGE equ (MCM_FIRST + 17)
          MonthCal_GetRange macro hmc, rgst
            exitm <SNDMSG (hmc, MCM_GETRANGE, 0, (rgst))>
          endm
          ; BOOL MonthCal_SetRange(HWND hmc, DWORD gdtr, LPSYSTEMTIME rgst)
          ;   if GDTR_MIN, sets the minimum ALLOWABLE systemtime to rgst[0], otherwise removes minimum
          ;   if GDTR_MAX, sets the maximum ALLOWABLE systemtime to rgst[1], otherwise removes maximum
          ;   returns TRUE on success, FALSE on error (such as invalid parameters)
          MCM_SETRANGE equ (MCM_FIRST + 18)
          MonthCal_SetRange macro hmc, gd, rgst
            exitm <SNDMSG (hmc, MCM_SETRANGE, (gd), (rgst))>
          endm
          ; int MonthCal_GetMonthDelta(HWND hmc)
          ;   returns the number of months one click on a next/prev button moves by
          MCM_GETMONTHDELTA equ (MCM_FIRST + 19)
          MonthCal_GetMonthDelta macro hmc
            exitm <SNDMSG (hmc, MCM_GETMONTHDELTA, 0, 0)>
          endm
          ; int MonthCal_SetMonthDelta(HWND hmc, int n)
          ;   sets the month delta to n. n==0 reverts to moving by a page of months
          ;   returns the previous value of n.
          MCM_SETMONTHDELTA equ (MCM_FIRST + 20)
          MonthCal_SetMonthDelta macro hmc, n
            exitm <SNDMSG (hmc, MCM_SETMONTHDELTA, n, 0)>
          endm
          ; DWORD MonthCal_GetMaxTodayWidth(HWND hmc, LPSIZE psz)
          ;   sets *psz to the maximum width/height of the "Today" string displayed
          ;   at the bottom of the calendar (as long as MCS_NOTODAY is not specified)
          MCM_GETMAXTODAYWIDTH equ (MCM_FIRST + 21)
          MonthCal_GetMaxTodayWidth macro hmc
            exitm <SNDMSG (hmc, MCM_GETMAXTODAYWIDTH, 0, 0)>
          endm
          MCM_SETUNICODEFORMAT equ <CCM_SETUNICODEFORMAT>
          MonthCal_SetUnicodeFormat macro hwnd, fUnicode
            exitm <SNDMSG ((hwnd), MCM_SETUNICODEFORMAT, (fUnicode), 0)>
          endm
          MCM_GETUNICODEFORMAT equ <CCM_GETUNICODEFORMAT>
          MonthCal_GetUnicodeFormat macro hwnd
            exitm <SNDMSG ((hwnd), MCM_GETUNICODEFORMAT, 0, 0)>
          endm
          if (NTDDI_VERSION ge NTDDI_VISTA)
            ; View
            MCMV_MONTH equ 0
            MCMV_YEAR equ 1
            MCMV_DECADE equ 2
            MCMV_CENTURY equ 3
            MCMV_MAX equ <MCMV_CENTURY>
            MCM_GETCURRENTVIEW equ (MCM_FIRST + 22)
            MonthCal_GetCurrentView macro hmc
              exitm <SNDMSG (hmc, MCM_GETCURRENTVIEW, 0, 0)>
            endm
            MCM_GETCALENDARCOUNT equ (MCM_FIRST + 23)
            MonthCal_GetCalendarCount macro hmc
              exitm <SNDMSG (hmc, MCM_GETCALENDARCOUNT, 0, 0)>
            endm
            ; Part
            MCGIP_CALENDARCONTROL equ 0
            MCGIP_NEXT equ 1
            MCGIP_PREV equ 2
            MCGIP_FOOTER equ 3
            MCGIP_CALENDAR equ 4
            MCGIP_CALENDARHEADER equ 5
            MCGIP_CALENDARBODY equ 6
            MCGIP_CALENDARROW equ 7
            MCGIP_CALENDARCELL equ 8
            MCGIF_DATE equ 00000001h
            MCGIF_RECT equ 00000002h
            MCGIF_NAME equ 00000004h
            ; Note: iRow of -1 refers to the row header and iCol of -1 refers to the col header.
            MCGRIDINFO struct
              cbSize DWORD ?
              dwPart DWORD ?
              dwFlags DWORD ?
              iCalendar SDWORD ?
              iRow SDWORD ?
              iCol SDWORD ?
              bSelected DWORD ?
              stStart SYSTEMTIME <>
              stEnd SYSTEMTIME <>
              rc RECT <>
              pszName POINTER ?
              cchName XWORD ?
            MCGRIDINFO ends
            tagMCGRIDINFO typedef MCGRIDINFO
            PMCGRIDINFO typedef ptr MCGRIDINFO
            MCM_GETCALENDARGRIDINFO equ (MCM_FIRST + 24)
            MonthCal_GetCalendarGridInfo macro hmc, pmcGridInfo
              exitm <SNDMSG (hmc, MCM_GETCALENDARGRIDINFO, 0, (PMCGRIDINFO) (pmcGridInfo))>
            endm
            MCM_GETCALID equ (MCM_FIRST + 27)
            MonthCal_GetCALID macro hmc
              exitm <(CALID) SNDMSG (hmc, MCM_GETCALID, 0, 0)>
            endm
            MCM_SETCALID equ (MCM_FIRST + 28)
            MonthCal_SetCALID macro hmc, calid
              exitm <SNDMSG (hmc, MCM_SETCALID, (calid), 0)>
            endm
            ; Returns the min rect that will fit the max number of calendars for the passed in rect.
            MCM_SIZERECTTOMIN equ (MCM_FIRST + 29)
            MonthCal_SizeRectToMin macro hmc, prc
              exitm <SNDMSG (hmc, MCM_SIZERECTTOMIN, 0, (prc))>
            endm
            MCM_SETCALENDARBORDER equ (MCM_FIRST + 30)
            MonthCal_SetCalendarBorder macro hmc, fset, xyborder
              exitm <SNDMSG (hmc, MCM_SETCALENDARBORDER, (fset), (xyborder))>
            endm
            MCM_GETCALENDARBORDER equ (MCM_FIRST + 31)
            MonthCal_GetCalendarBorder macro hmc
              exitm <SNDMSG (hmc, MCM_GETCALENDARBORDER, 0, 0)>
            endm
            MCM_SETCURRENTVIEW equ (MCM_FIRST + 32)
            MonthCal_SetCurrentView macro hmc, dwNewView
              exitm <SNDMSG (hmc, MCM_SETCURRENTVIEW, 0, (dwNewView))>
            endm
          endif
          ; MCN_SELCHANGE is sent whenever the currently displayed date changes
          ; via month change, year change, keyboard navigation, prev/next button
          NMSELCHANGE struct
            nmhdr NMHDR <>
            ; this must be first, so we don't break WM_NOTIFY
            stSelStart SYSTEMTIME <>
            stSelEnd SYSTEMTIME <>
          NMSELCHANGE ends
          tagNMSELCHANGE typedef NMSELCHANGE
          LPNMSELCHANGE typedef ptr NMSELCHANGE
          MCN_SELCHANGE equ (MCN_FIRST - 3); -749

          ; MCN_GETDAYSTATE is sent for MCS_DAYSTATE controls whenever new daystate
          ; information is needed (month or year scroll) to draw bolding information.
          ; The app must fill in cDayState months worth of information starting from
          ; stStart date. The app may fill in the array at prgDayState or change
          ; prgDayState to point to a different array out of which the information
          ; will be copied. (similar to tooltips)
          NMDAYSTATE struct
            nmhdr NMHDR <>
            ; this must be first, so we don't break WM_NOTIFY
            stStart SYSTEMTIME <>
            cDayState SDWORD ?
            prgDayState LPMONTHDAYSTATE ?
            ; points to cDayState MONTHDAYSTATEs
          NMDAYSTATE ends
          tagNMDAYSTATE typedef NMDAYSTATE
          LPNMDAYSTATE typedef ptr NMDAYSTATE
          MCN_GETDAYSTATE equ (MCN_FIRST - 1); -747

          ; MCN_SELECT is sent whenever a selection has occured (via mouse or keyboard)
          NMSELECT typedef NMSELCHANGE
          LPNMSELECT typedef ptr NMSELCHANGE
          MCN_SELECT equ <(MCN_FIRST)>; -746

          NMVIEWCHANGE struct
            nmhdr NMHDR <>
            ; this must be first, so we don't break WM_NOTIFY
            dwOldView DWORD ?
            dwNewView DWORD ?
          NMVIEWCHANGE ends
          tagNMVIEWCHANGE typedef NMVIEWCHANGE
          LPNMVIEWCHANGE typedef ptr NMVIEWCHANGE
          MCN_VIEWCHANGE equ (MCN_FIRST - 4); -750

          ; begin_r_commctrl
          MCS_DAYSTATE equ 0001h
          MCS_MULTISELECT equ 0002h
          MCS_WEEKNUMBERS equ 0004h
          MCS_NOTODAYCIRCLE equ 0008h
          MCS_NOTODAY equ 0010h
          if (NTDDI_VERSION ge NTDDI_VISTA)
            MCS_NOTRAILINGDATES equ 0040h
            MCS_SHORTDAYSOFWEEK equ 0080h
            MCS_NOSELCHANGEONNAV equ 0100h
          endif
          ; end_r_commctrl
          GMR_VISIBLE equ 0; visible portion of display

          GMR_DAYSTATE equ 1; above plus the grayed out parts of

          ; partially displayed months
        endif
        ; _WIN32
      endif
      ; NOMONTHCAL
      ;====== DATETIMEPICK CONTROL ==================================================
      ifndef NODATETIMEPICK
        ifdef _WIN32
          DATETIMEPICK_CLASSW equ <L("SysDateTimePick32")>
          DATETIMEPICK_CLASSA equ <"SysDateTimePick32">
          ifdef UNICODE
            DATETIMEPICK_CLASS equ <DATETIMEPICK_CLASSW>
          else
            DATETIMEPICK_CLASS equ <DATETIMEPICK_CLASSA>
          endif
          if (NTDDI_VERSION ge NTDDI_VISTA)
            DATETIMEPICKERINFO struct
              cbSize DWORD ?
              rcCheck RECT <>
              stateCheck DWORD ?
              rcButton RECT <>
              stateButton DWORD ?
              hwndEdit HWND ?
              hwndUD HWND ?
              hwndDropDown HWND ?
            DATETIMEPICKERINFO ends
            tagDATETIMEPICKERINFO typedef DATETIMEPICKERINFO
            LPDATETIMEPICKERINFO typedef ptr DATETIMEPICKERINFO
          endif
          ; (NTDDI_VERSION >= NTDDI_VISTA)
          DTM_FIRST equ 1000h
          ; DWORD DateTimePick_GetSystemtime(HWND hdp, LPSYSTEMTIME pst)
          ;   returns GDT_NONE if "none" is selected (DTS_SHOWNONE only)
          ;   returns GDT_VALID and modifies *pst to be the currently selected value
          DTM_GETSYSTEMTIME equ (DTM_FIRST + 1)
          DateTime_GetSystemtime macro hdp, pst
            exitm <SNDMSG (hdp, DTM_GETSYSTEMTIME, 0, (pst))>
          endm
          ; BOOL DateTime_SetSystemtime(HWND hdp, DWORD gd, LPSYSTEMTIME pst)
          ;   if gd==GDT_NONE, sets datetimepick to None (DTS_SHOWNONE only)
          ;   if gd==GDT_VALID, sets datetimepick to *pst
          ;   returns TRUE on success, FALSE on error (such as bad params)
          DTM_SETSYSTEMTIME equ (DTM_FIRST + 2)
          DateTime_SetSystemtime macro hdp, gd, pst
            exitm <SNDMSG (hdp, DTM_SETSYSTEMTIME, (gd), (pst))>
          endm
          ; DWORD DateTime_GetRange(HWND hdp, LPSYSTEMTIME rgst)
          ;   modifies rgst[0] to be the minimum ALLOWABLE systemtime (or 0 if no minimum)
          ;   modifies rgst[1] to be the maximum ALLOWABLE systemtime (or 0 if no maximum)
          ;   returns GDTR_MIN|GDTR_MAX if there is a minimum|maximum limit
          DTM_GETRANGE equ (DTM_FIRST + 3)
          DateTime_GetRange macro hdp, rgst
            exitm <SNDMSG (hdp, DTM_GETRANGE, 0, (rgst))>
          endm
          ; BOOL DateTime_SetRange(HWND hdp, DWORD gdtr, LPSYSTEMTIME rgst)
          ;   if GDTR_MIN, sets the minimum ALLOWABLE systemtime to rgst[0], otherwise removes minimum
          ;   if GDTR_MAX, sets the maximum ALLOWABLE systemtime to rgst[1], otherwise removes maximum
          ;   returns TRUE on success, FALSE on error (such as invalid parameters)
          DTM_SETRANGE equ (DTM_FIRST + 4)
          DateTime_SetRange macro hdp, gd, rgst
            exitm <SNDMSG (hdp, DTM_SETRANGE, (gd), (rgst))>
          endm
          ; BOOL DateTime_SetFormat(HWND hdp, LPCTSTR sz)
          ;   sets the display formatting string to sz (see GetDateFormat and GetTimeFormat for valid formatting chars)
          ;   NOTE: 'X' is a valid formatting character which indicates that the application
          ;   will determine how to display information. Such apps must support DTN_WMKEYDOWN,
          ;   DTN_FORMAT, and DTN_FORMATQUERY.
          DTM_SETFORMATA equ (DTM_FIRST + 5)
          DTM_SETFORMATW equ (DTM_FIRST + 50)
          ifdef UNICODE
            DTM_SETFORMAT equ <DTM_SETFORMATW>
          else
            DTM_SETFORMAT equ <DTM_SETFORMATA>
          endif
          DateTime_SetFormat macro hdp, sz
            exitm <SNDMSG (hdp, DTM_SETFORMAT, 0, (sz))>
          endm
          DTM_SETMCCOLOR equ (DTM_FIRST + 6)
          DateTime_SetMonthCalColor macro hdp, iColor, clr
            exitm <SNDMSG (hdp, DTM_SETMCCOLOR, iColor, clr)>
          endm
          DTM_GETMCCOLOR equ (DTM_FIRST + 7)
          DateTime_GetMonthCalColor macro hdp, iColor
            exitm <SNDMSG (hdp, DTM_GETMCCOLOR, iColor, 0)>
          endm
          ; HWND DateTime_GetMonthCal(HWND hdp)
          ;   returns the HWND of the MonthCal popup window. Only valid
          ; between DTN_DROPDOWN and DTN_CLOSEUP notifications.
          DTM_GETMONTHCAL equ (DTM_FIRST + 8)
          DateTime_GetMonthCal macro hdp
            exitm <SNDMSG (hdp, DTM_GETMONTHCAL, 0, 0)>
          endm
          DTM_SETMCFONT equ (DTM_FIRST + 9)
          DateTime_SetMonthCalFont macro hdp, hfont, fRedraw
            exitm <SNDMSG (hdp, DTM_SETMCFONT, (hfont), (fRedraw))>
          endm
          DTM_GETMCFONT equ (DTM_FIRST + 10)
          DateTime_GetMonthCalFont macro hdp
            exitm <SNDMSG (hdp, DTM_GETMCFONT, 0, 0)>
          endm
          if (NTDDI_VERSION ge NTDDI_VISTA)
            DTM_SETMCSTYLE equ (DTM_FIRST + 11)
            DateTime_SetMonthCalStyle macro hdp, dwStyle
              exitm <SNDMSG (hdp, DTM_SETMCSTYLE, 0, dwStyle)>
            endm
            DTM_GETMCSTYLE equ (DTM_FIRST + 12)
            DateTime_GetMonthCalStyle macro hdp
              exitm <SNDMSG (hdp, DTM_GETMCSTYLE, 0, 0)>
            endm
            DTM_CLOSEMONTHCAL equ (DTM_FIRST + 13)
            DateTime_CloseMonthCal macro hdp
              exitm <SNDMSG (hdp, DTM_CLOSEMONTHCAL, 0, 0)>
            endm
            ; DateTime_GetDateTimePickerInfo(HWND hdp, DATETIMEPICKERINFO* pdtpi)
            ; Retrieves information about the selected date time picker.
            DTM_GETDATETIMEPICKERINFO equ (DTM_FIRST + 14)
            DateTime_GetDateTimePickerInfo macro hdp, pdtpi
              exitm <SNDMSG (hdp, DTM_GETDATETIMEPICKERINFO, 0, (pdtpi))>
            endm
            DTM_GETIDEALSIZE equ (DTM_FIRST + 15)
            DateTime_GetIdealSize macro hdp, psize
              exitm <SNDMSG ((hdp), DTM_GETIDEALSIZE, 0, (psize))>
            endm
          endif
          ; (NTDDI_VERSION >= NTDDI_VISTA)
          ; begin_r_commctrl
          DTS_UPDOWN equ 0001h; use UPDOWN instead of MONTHCAL

          DTS_SHOWNONE equ 0002h; allow a NONE selection

          DTS_SHORTDATEFORMAT equ 0000h; use the short date format (app must forward WM_WININICHANGE messages)

          DTS_LONGDATEFORMAT equ 0004h; use the long date format (app must forward WM_WININICHANGE messages)

          DTS_SHORTDATECENTURYFORMAT equ 000Ch; short date format with century (app must forward WM_WININICHANGE messages)

          DTS_TIMEFORMAT equ 0009h; use the time format (app must forward WM_WININICHANGE messages)

          DTS_APPCANPARSE equ 0010h; allow user entered strings (app MUST respond to DTN_USERSTRING)

          DTS_RIGHTALIGN equ 0020h; right-align popup instead of left-align it

          ; end_r_commctrl
          DTN_DATETIMECHANGE equ (DTN_FIRST2 - 6); the systemtime has changed, -759

          NMDATETIMECHANGE struct
            nmhdr NMHDR <>
            dwFlags DWORD ?
            ; GDT_VALID or GDT_NONE
            st_ SYSTEMTIME <>
            ; valid iff dwFlags==GDT_VALID
          NMDATETIMECHANGE ends
          tagNMDATETIMECHANGE typedef NMDATETIMECHANGE
          LPNMDATETIMECHANGE typedef ptr NMDATETIMECHANGE
          DTN_USERSTRINGA equ (DTN_FIRST2 - 5); the user has entered a string, -758

          DTN_USERSTRINGW equ (DTN_FIRST - 5); -745

          NMDATETIMESTRINGA struct
            nmhdr NMHDR <>
            pszUserString =POINTER ?
            ; string user entered
            st_ SYSTEMTIME <>
            ; app fills this in
            dwFlags DWORD ?
            ; GDT_VALID or GDT_NONE
          NMDATETIMESTRINGA ends
          tagNMDATETIMESTRINGA typedef NMDATETIMESTRINGA
          LPNMDATETIMESTRINGA typedef ptr NMDATETIMESTRINGA
          NMDATETIMESTRINGW struct
            nmhdr NMHDR <>
            pszUserString =POINTER ?
            ; string user entered
            st_ SYSTEMTIME <>
            ; app fills this in
            dwFlags DWORD ?
            ; GDT_VALID or GDT_NONE
          NMDATETIMESTRINGW ends
          tagNMDATETIMESTRINGW typedef NMDATETIMESTRINGW
          LPNMDATETIMESTRINGW typedef ptr NMDATETIMESTRINGW
          ifdef UNICODE
            DTN_USERSTRING equ <DTN_USERSTRINGW>
            NMDATETIMESTRING equ <NMDATETIMESTRINGW>
            LPNMDATETIMESTRING equ <LPNMDATETIMESTRINGW>
          else
            DTN_USERSTRING equ <DTN_USERSTRINGA>
            NMDATETIMESTRING equ <NMDATETIMESTRINGA>
            LPNMDATETIMESTRING equ <LPNMDATETIMESTRINGA>
          endif
          DTN_WMKEYDOWNA equ (DTN_FIRST2 - 4); modify keydown on app format field (X), , -757

          DTN_WMKEYDOWNW equ (DTN_FIRST - 4); -744

          NMDATETIMEWMKEYDOWNA struct
            nmhdr NMHDR <>
            nVirtKey SDWORD ?
            ; virtual key code of WM_KEYDOWN which MODIFIES an X field
            pszFormat =POINTER ?
            ; format substring
            st_ SYSTEMTIME <>
            ; current systemtime, app should modify based on key
          NMDATETIMEWMKEYDOWNA ends
          tagNMDATETIMEWMKEYDOWNA typedef NMDATETIMEWMKEYDOWNA
          LPNMDATETIMEWMKEYDOWNA typedef ptr NMDATETIMEWMKEYDOWNA
          NMDATETIMEWMKEYDOWNW struct
            nmhdr NMHDR <>
            nVirtKey SDWORD ?
            ; virtual key code of WM_KEYDOWN which MODIFIES an X field
            pszFormat =POINTER ?
            ; format substring
            st_ SYSTEMTIME <>
            ; current systemtime, app should modify based on key
          NMDATETIMEWMKEYDOWNW ends
          tagNMDATETIMEWMKEYDOWNW typedef NMDATETIMEWMKEYDOWNW
          LPNMDATETIMEWMKEYDOWNW typedef ptr NMDATETIMEWMKEYDOWNW
          ifdef UNICODE
            DTN_WMKEYDOWN equ <DTN_WMKEYDOWNW>
            NMDATETIMEWMKEYDOWN equ <NMDATETIMEWMKEYDOWNW>
            LPNMDATETIMEWMKEYDOWN equ <LPNMDATETIMEWMKEYDOWNW>
          else
            DTN_WMKEYDOWN equ <DTN_WMKEYDOWNA>
            NMDATETIMEWMKEYDOWN equ <NMDATETIMEWMKEYDOWNA>
            LPNMDATETIMEWMKEYDOWN equ <LPNMDATETIMEWMKEYDOWNA>
          endif
          DTN_FORMATA equ (DTN_FIRST2 - 3); query display for app format field (X), -756

          DTN_FORMATW equ (DTN_FIRST - 3); -743

          NMDATETIMEFORMATA struct
            nmhdr NMHDR <>
            pszFormat =POINTER ?
            ; format substring
            st_ SYSTEMTIME <>
            ; current systemtime
            pszDisplay =POINTER ?
            ; string to display
            szDisplay SBYTE 64 dup (?)
            ; buffer pszDisplay originally points at
          NMDATETIMEFORMATA ends
          tagNMDATETIMEFORMATA typedef NMDATETIMEFORMATA
          LPNMDATETIMEFORMATA typedef ptr NMDATETIMEFORMATA
          NMDATETIMEFORMATW struct
            nmhdr NMHDR <>
            pszFormat =POINTER ?
            ; format substring
            st_ SYSTEMTIME <>
            ; current systemtime
            pszDisplay =POINTER ?
            ; string to display
            szDisplay WORD 64 dup (?)
            ; buffer pszDisplay originally points at
          NMDATETIMEFORMATW ends
          tagNMDATETIMEFORMATW typedef NMDATETIMEFORMATW
          LPNMDATETIMEFORMATW typedef ptr NMDATETIMEFORMATW
          ifdef UNICODE
            DTN_FORMAT equ <DTN_FORMATW>
            NMDATETIMEFORMAT equ <NMDATETIMEFORMATW>
            LPNMDATETIMEFORMAT equ <LPNMDATETIMEFORMATW>
          else
            DTN_FORMAT equ <DTN_FORMATA>
            NMDATETIMEFORMAT equ <NMDATETIMEFORMATA>
            LPNMDATETIMEFORMAT equ <LPNMDATETIMEFORMATA>
          endif
          DTN_FORMATQUERYA equ (DTN_FIRST2 - 2); query formatting info for app format field (X), -755

          DTN_FORMATQUERYW equ (DTN_FIRST - 2); -742

          NMDATETIMEFORMATQUERYA struct
            nmhdr NMHDR <>
            pszFormat =POINTER ?
            ; format substring
            szMax SIZE_ ?
            ; max bounding rectangle app will use for this format string
          NMDATETIMEFORMATQUERYA ends
          tagNMDATETIMEFORMATQUERYA typedef NMDATETIMEFORMATQUERYA
          LPNMDATETIMEFORMATQUERYA typedef ptr NMDATETIMEFORMATQUERYA
          NMDATETIMEFORMATQUERYW struct
            nmhdr NMHDR <>
            pszFormat =POINTER ?
            ; format substring
            szMax SIZE_ ?
            ; max bounding rectangle app will use for this format string
          NMDATETIMEFORMATQUERYW ends
          tagNMDATETIMEFORMATQUERYW typedef NMDATETIMEFORMATQUERYW
          LPNMDATETIMEFORMATQUERYW typedef ptr NMDATETIMEFORMATQUERYW
          ifdef UNICODE
            DTN_FORMATQUERY equ <DTN_FORMATQUERYW>
            NMDATETIMEFORMATQUERY equ <NMDATETIMEFORMATQUERYW>
            LPNMDATETIMEFORMATQUERY equ <LPNMDATETIMEFORMATQUERYW>
          else
            DTN_FORMATQUERY equ <DTN_FORMATQUERYA>
            NMDATETIMEFORMATQUERY equ <NMDATETIMEFORMATQUERYA>
            LPNMDATETIMEFORMATQUERY equ <LPNMDATETIMEFORMATQUERYA>
          endif
          DTN_DROPDOWN equ (DTN_FIRST2 - 1); MonthCal has dropped down, -754

          DTN_CLOSEUP equ <(DTN_FIRST2)>; MonthCal is popping up, -753

          GDTR_MIN equ 0001h
          GDTR_MAX equ 0002h
          GDT_ERROR equ -1
          GDT_VALID equ 0
          GDT_NONE equ 1
        endif
        ; _WIN32
      endif
      ; NODATETIMEPICK
      ifndef NOIPADDRESS
        ;/////////////////////////////////////////////
        ;    IP Address edit control
        ; Messages sent to IPAddress controls
        IPM_CLEARADDRESS equ (WM_USER + 100); no parameters

        IPM_SETADDRESS equ (WM_USER + 101); lparam = TCP/IP address

        IPM_GETADDRESS equ (WM_USER + 102); lresult = # of non black fields.  lparam = LPDWORD for TCP/IP address

        IPM_SETRANGE equ (WM_USER + 103); wparam = field, lparam = range

        IPM_SETFOCUS equ (WM_USER + 104); wparam = field

        IPM_ISBLANK equ (WM_USER + 105); no parameters

        WC_IPADDRESSW equ <L("SysIPAddress32")>
        WC_IPADDRESSA equ <"SysIPAddress32">
        ifdef UNICODE
          WC_IPADDRESS equ <WC_IPADDRESSW>
        else
          WC_IPADDRESS equ <WC_IPADDRESSA>
        endif
        IPN_FIELDCHANGED equ (IPN_FIRST - 0)
        NMIPADDRESS struct
          hdr NMHDR <>
          iField SDWORD ?
          iValue SDWORD ?
        NMIPADDRESS ends
        tagNMIPADDRESS typedef NMIPADDRESS
        LPNMIPADDRESS typedef ptr NMIPADDRESS
        ; The following is a useful macro for passing the range values in the
        ; IPM_SETRANGE message.
        MAKEIPRANGE macro low_, high_
          exitm <((((high_) shl 8) + (low_)))>
        endm
        ; And this is a useful macro for making the IP Address to be passed
        ; as a LPARAM.
        MAKEIPADDRESS macro b1, b2, b3, b4
          exitm <((((b1) shl 24) + ((b2) shl 16) + ((b3) shl 8) + ((b4))))>
        endm
        ; Get individual number
        FIRST_IPADDRESS macro x
          exitm <(((x) shr 24) and 0ffh)>
        endm
        SECOND_IPADDRESS macro x
          exitm <(((x) shr 16) and 0ffh)>
        endm
        THIRD_IPADDRESS macro x
          exitm <(((x) shr 8) and 0ffh)>
        endm
        FOURTH_IPADDRESS macro x
          exitm <((x) and 0ffh)>
        endm
      endif
      ; NOIPADDRESS
      ;---------------------------------------------------------------------------------------
      ;---------------------------------------------------------------------------------------
      ;  ====================== Pager Control =============================
      ;---------------------------------------------------------------------------------------
      ;---------------------------------------------------------------------------------------
      ifndef NOPAGESCROLLER
        ;Pager Class Name
        WC_PAGESCROLLERW equ <L("SysPager")>
        WC_PAGESCROLLERA equ <"SysPager">
        ifdef UNICODE
          WC_PAGESCROLLER equ <WC_PAGESCROLLERW>
        else
          WC_PAGESCROLLER equ <WC_PAGESCROLLERA>
        endif
        ;---------------------------------------------------------------------------------------
        ; Pager Control Styles
        ;---------------------------------------------------------------------------------------
        ; begin_r_commctrl
        PGS_VERT equ 00000000h
        PGS_HORZ equ 00000001h
        PGS_AUTOSCROLL equ 00000002h
        PGS_DRAGNDROP equ 00000004h
        ; end_r_commctrl
        ;---------------------------------------------------------------------------------------
        ; Pager Button State
        ;---------------------------------------------------------------------------------------
        ;The scroll can be in one of the following control State
        PGF_INVISIBLE equ 0; Scroll button is not visible

        PGF_NORMAL equ 1; Scroll button is in normal state

        PGF_GRAYED equ 2; Scroll button is in grayed state

        PGF_DEPRESSED equ 4; Scroll button is in depressed state

        PGF_HOT equ 8; Scroll button is in hot state

        ; The following identifiers specifies the button control
        PGB_TOPORLEFT equ 0
        PGB_BOTTOMORRIGHT equ 1
        ;---------------------------------------------------------------------------------------
        ; Pager Control  Messages
        ;---------------------------------------------------------------------------------------
        PGM_SETCHILD equ (PGM_FIRST + 1); lParam == hwnd

        Pager_SetChild macro hwnd, hwndChild
          exitm <SNDMSG ((hwnd), PGM_SETCHILD, 0, (hwndChild))>
        endm
        PGM_RECALCSIZE equ (PGM_FIRST + 2)
        Pager_RecalcSize macro hwnd
          exitm <SNDMSG ((hwnd), PGM_RECALCSIZE, 0, 0)>
        endm
        PGM_FORWARDMOUSE equ (PGM_FIRST + 3)
        Pager_ForwardMouse macro hwnd, bForward
          exitm <SNDMSG ((hwnd), PGM_FORWARDMOUSE, (bForward), 0)>
        endm
        PGM_SETBKCOLOR equ (PGM_FIRST + 4)
        Pager_SetBkColor macro hwnd, clr
          exitm <SNDMSG ((hwnd), PGM_SETBKCOLOR, 0, (clr))>
        endm
        PGM_GETBKCOLOR equ (PGM_FIRST + 5)
        Pager_GetBkColor macro hwnd
          exitm <SNDMSG ((hwnd), PGM_GETBKCOLOR, 0, 0)>
        endm
        PGM_SETBORDER equ (PGM_FIRST + 6)
        Pager_SetBorder macro hwnd, iBorder
          exitm <SNDMSG ((hwnd), PGM_SETBORDER, 0, (iBorder))>
        endm
        PGM_GETBORDER equ (PGM_FIRST + 7)
        Pager_GetBorder macro hwnd
          exitm <SNDMSG ((hwnd), PGM_GETBORDER, 0, 0)>
        endm
        PGM_SETPOS equ (PGM_FIRST + 8)
        Pager_SetPos macro hwnd, iPos
          exitm <SNDMSG ((hwnd), PGM_SETPOS, 0, (iPos))>
        endm
        PGM_GETPOS equ (PGM_FIRST + 9)
        Pager_GetPos macro hwnd
          exitm <SNDMSG ((hwnd), PGM_GETPOS, 0, 0)>
        endm
        PGM_SETBUTTONSIZE equ (PGM_FIRST + 10)
        Pager_SetButtonSize macro hwnd, iSize
          exitm <SNDMSG ((hwnd), PGM_SETBUTTONSIZE, 0, (iSize))>
        endm
        PGM_GETBUTTONSIZE equ (PGM_FIRST + 11)
        Pager_GetButtonSize macro hwnd
          exitm <SNDMSG ((hwnd), PGM_GETBUTTONSIZE, 0, 0)>
        endm
        PGM_GETBUTTONSTATE equ (PGM_FIRST + 12)
        Pager_GetButtonState macro hwnd, iButton
          exitm <SNDMSG ((hwnd), PGM_GETBUTTONSTATE, 0, (iButton))>
        endm
        PGM_GETDROPTARGET equ <CCM_GETDROPTARGET>
        Pager_GetDropTarget macro hwnd, ppdt
          exitm <SNDMSG ((hwnd), PGM_GETDROPTARGET, 0, (ppdt))>
        endm
        PGM_SETSCROLLINFO equ (PGM_FIRST + 13)
        Pager_SetScrollInfo macro hwnd, cTimeOut, cLinesPer, cPixelsPerLine
          exitm <SNDMSG ((hwnd), PGM_SETSCROLLINFO, cTimeOut, MAKELONG(cLinesPer, cPixelsPerLine))>
        endm
        ;---------------------------------------------------------------------------------------
        ;Pager Control Notification Messages
        ;---------------------------------------------------------------------------------------
        ; PGN_SCROLL Notification Message
        PGN_SCROLL equ (PGN_FIRST - 1)
        PGF_SCROLLUP equ 1
        PGF_SCROLLDOWN equ 2
        PGF_SCROLLLEFT equ 4
        PGF_SCROLLRIGHT equ 8
        ;Keys down
        PGK_SHIFT equ 1
        PGK_CONTROL equ 2
        PGK_MENU equ 4
        ifdef _WIN32
          include pshpack1.inc
        endif
        ; This structure is sent along with PGN_SCROLL notifications
        NMPGSCROLL struct
          hdr NMHDR <>
          fwKeys WORD ?
          ; Specifies which keys are down when this notification is send
          rcParent RECT <>
          ; Contains Parent Window Rect
          iDir SDWORD ?
          ; Scrolling Direction
          iXpos SDWORD ?
          ; Horizontal scroll position
          iYpos SDWORD ?
          ; Vertical scroll position
          iScroll SDWORD ?
          ; [in/out] Amount to scroll
        NMPGSCROLL ends
        LPNMPGSCROLL typedef ptr NMPGSCROLL
        ifdef _WIN32
          include poppack.inc
        endif
        ; PGN_CALCSIZE Notification Message
        PGN_CALCSIZE equ (PGN_FIRST - 2)
        PGF_CALCWIDTH equ 1
        PGF_CALCHEIGHT equ 2
        NMPGCALCSIZE struct
          hdr NMHDR <>
          dwFlag DWORD ?
          iWidth SDWORD ?
          iHeight SDWORD ?
        NMPGCALCSIZE ends
        LPNMPGCALCSIZE typedef ptr NMPGCALCSIZE
        ; PGN_HOTITEMCHANGE Notification Message
        PGN_HOTITEMCHANGE equ (PGN_FIRST - 3)
        ;*
        ;The PGN_HOTITEMCHANGE notification uses these notification
        ;flags defined in TOOLBAR:
        ;#define HICF_ENTERING       0x00000010          // idOld is invalid
        ;#define HICF_LEAVING        0x00000020          // idNew is invalid
        ;*
        ; Structure for PGN_HOTITEMCHANGE notification
        NMPGHOTITEM struct
          hdr NMHDR <>
          idOld SDWORD ?
          idNew SDWORD ?
          dwFlags DWORD ?
          ; HICF_*
        NMPGHOTITEM ends
        tagNMPGHOTITEM typedef NMPGHOTITEM
        LPNMPGHOTITEM typedef ptr NMPGHOTITEM
      endif
      ; NOPAGESCROLLER
      ;//======================  End Pager Control ==========================================
      ; === Native Font Control ===
      ifndef NONATIVEFONTCTL
        ;NativeFont Class Name
        WC_NATIVEFONTCTLW equ <L("NativeFontCtl")>
        WC_NATIVEFONTCTLA equ <"NativeFontCtl">
        ifdef UNICODE
          WC_NATIVEFONTCTL equ <WC_NATIVEFONTCTLW>
        else
          WC_NATIVEFONTCTL equ <WC_NATIVEFONTCTLA>
        endif
        ; begin_r_commctrl
        ; style definition
        NFS_EDIT equ 0001h
        NFS_STATIC equ 0002h
        NFS_LISTCOMBO equ 0004h
        NFS_BUTTON equ 0008h
        NFS_ALL equ 0010h
        NFS_USEFONTASSOC equ 0020h
        ; end_r_commctrl
      endif
      ; NONATIVEFONTCTL
      ; === End Native Font Control ===
      ; ====================== Button Control =============================
      ifndef NOBUTTON
        ifdef _WIN32
          ; Button Class Name
          WC_BUTTONA equ <"Button">
          WC_BUTTONW equ <L("Button")>
          ifdef UNICODE
            WC_BUTTON equ <WC_BUTTONW>
          else
            WC_BUTTON equ <WC_BUTTONA>
          endif
        else
          ;[...]
        endif
        if (NTDDI_VERSION ge NTDDI_WINXP)
          BUTTON_IMAGELIST_ALIGN_LEFT equ 0
          BUTTON_IMAGELIST_ALIGN_RIGHT equ 1
          BUTTON_IMAGELIST_ALIGN_TOP equ 2
          BUTTON_IMAGELIST_ALIGN_BOTTOM equ 3
          BUTTON_IMAGELIST_ALIGN_CENTER equ 4; Doesn't draw text

          BUTTON_IMAGELIST struct
            himl HIMAGELIST ?
            ; Images: Normal, Hot, Pushed, Disabled. If count is less than 4, we use index 1
            margin RECT <>
            ; Margin around icon.
            uAlign DWORD ?
          BUTTON_IMAGELIST ends
          PBUTTON_IMAGELIST typedef ptr BUTTON_IMAGELIST
          BCM_GETIDEALSIZE equ (BCM_FIRST + 0001h)
          Button_GetIdealSize macro hwnd, psize
            exitm <SNDMSG ((hwnd), BCM_GETIDEALSIZE, 0, (psize))>
          endm
          BCM_SETIMAGELIST equ (BCM_FIRST + 0002h)
          Button_SetImageList macro hwnd, pbuttonImagelist
            exitm <SNDMSG ((hwnd), BCM_SETIMAGELIST, 0, (pbuttonImagelist))>
          endm
          BCM_GETIMAGELIST equ (BCM_FIRST + 0003h)
          Button_GetImageList macro hwnd, pbuttonImagelist
            exitm <SNDMSG ((hwnd), BCM_GETIMAGELIST, 0, (pbuttonImagelist))>
          endm
          BCM_SETTEXTMARGIN equ (BCM_FIRST + 0004h)
          Button_SetTextMargin macro hwnd, pmargin
            exitm <SNDMSG ((hwnd), BCM_SETTEXTMARGIN, 0, (pmargin))>
          endm
          BCM_GETTEXTMARGIN equ (BCM_FIRST + 0005h)
          Button_GetTextMargin macro hwnd, pmargin
            exitm <SNDMSG ((hwnd), BCM_GETTEXTMARGIN, 0, (pmargin))>
          endm
          NMBCHOTITEM struct
            hdr NMHDR <>
            dwFlags DWORD ?
            ; HICF_*
          NMBCHOTITEM ends
          tagNMBCHOTITEM typedef NMBCHOTITEM
          LPNMBCHOTITEM typedef ptr NMBCHOTITEM
          BCN_HOTITEMCHANGE equ (BCN_FIRST + 0001h)
          BST_HOT equ 0200h
        endif
        ; (NTDDI_VERSION >= NTDDI_WINXP)
        if (NTDDI_VERSION ge NTDDI_VISTA)
          ; BUTTON STATE FLAGS
          BST_DROPDOWNPUSHED equ 0400h
          ; begin_r_commctrl
          ; BUTTON STYLES
          BS_SPLITBUTTON equ 0000000Ch
          BS_DEFSPLITBUTTON equ 0000000Dh
          BS_COMMANDLINK equ 0000000Eh
          BS_DEFCOMMANDLINK equ 0000000Fh
          ; SPLIT BUTTON INFO mask flags
          BCSIF_GLYPH equ 0001h
          BCSIF_IMAGE equ 0002h
          BCSIF_STYLE equ 0004h
          BCSIF_SIZE equ 0008h
          ; SPLIT BUTTON STYLE flags
          BCSS_NOSPLIT equ 0001h
          BCSS_STRETCH equ 0002h
          BCSS_ALIGNLEFT equ 0004h
          BCSS_IMAGE equ 0008h
          ; end_r_commctrl
          ; BUTTON STRUCTURES
          BUTTON_SPLITINFO struct
            mask_ DWORD ?
            himlGlyph HIMAGELIST ?
            ; interpreted as WCHAR if BCSIF_GLYPH is set
            uSplitStyle DWORD ?
            size_ SIZE_ ?
          BUTTON_SPLITINFO ends
          tagBUTTON_SPLITINFO typedef BUTTON_SPLITINFO
          PBUTTON_SPLITINFO typedef ptr BUTTON_SPLITINFO
          ; BUTTON MESSAGES
          BCM_SETDROPDOWNSTATE equ (BCM_FIRST + 0006h)
          Button_SetDropDownState macro hwnd, fDropDown
            exitm <SNDMSG ((hwnd), BCM_SETDROPDOWNSTATE, (fDropDown), 0)>
          endm
          BCM_SETSPLITINFO equ (BCM_FIRST + 0007h)
          Button_SetSplitInfo macro hwnd, pInfo
            exitm <SNDMSG ((hwnd), BCM_SETSPLITINFO, 0, (pInfo))>
          endm
          BCM_GETSPLITINFO equ (BCM_FIRST + 0008h)
          Button_GetSplitInfo macro hwnd, pInfo
            exitm <SNDMSG ((hwnd), BCM_GETSPLITINFO, 0, (pInfo))>
          endm
          BCM_SETNOTE equ (BCM_FIRST + 0009h)
          Button_SetNote macro hwnd, psz
            exitm <SNDMSG ((hwnd), BCM_SETNOTE, 0, (psz))>
          endm
          BCM_GETNOTE equ (BCM_FIRST + 000Ah)
          Button_GetNote macro hwnd, psz, pcc
            exitm <SNDMSG ((hwnd), BCM_GETNOTE, pcc, psz)>
          endm
          BCM_GETNOTELENGTH equ (BCM_FIRST + 000Bh)
          Button_GetNoteLength macro hwnd
            exitm <SNDMSG ((hwnd), BCM_GETNOTELENGTH, 0, 0)>
          endm
          if (NTDDI_VERSION ge NTDDI_VISTA)
            ; Macro to use on a button or command link to display an elevated icon
            BCM_SETSHIELD equ (BCM_FIRST + 000Ch)
            Button_SetElevationRequiredState macro hwnd, fRequired
              exitm <SNDMSG ((hwnd), BCM_SETSHIELD, 0, fRequired)>
            endm
          endif
          ; (NTDDI_VERSION >= NTDDI_VISTA)
          ; Value to pass to BCM_SETIMAGELIST to indicate that no glyph should be
          ; displayed
          BCCL_NOGLYPH equ (- 1)
          ; NOTIFICATION MESSAGES
          NMBCDROPDOWN struct
            hdr NMHDR <>
            rcButton RECT <>
          NMBCDROPDOWN ends
          tagNMBCDROPDOWN typedef NMBCDROPDOWN
          LPNMBCDROPDOWN typedef ptr NMBCDROPDOWN
          BCN_DROPDOWN equ (BCN_FIRST + 0002h)
        endif
        ; (NTDDI_VERSION >= NTDDI_VISTA)
      endif
      ; NOBUTTON
      ; =====================  End Button Control =========================
      ; ====================== Static Control =============================
      ifndef NOSTATIC
        ifdef _WIN32
          ; Static Class Name
          WC_STATICA equ <"Static">
          WC_STATICW equ <L("Static")>
          ifdef UNICODE
            WC_STATIC equ <WC_STATICW>
          else
            WC_STATIC equ <WC_STATICA>
          endif
        else
          ;[...]
        endif
      endif
      ; NOSTATIC
      ; =====================  End Static Control =========================
      ; ====================== Edit Control =============================
      ifndef NOEDIT
        ifdef _WIN32
          ; Edit Class Name
          WC_EDITA equ <"Edit">
          WC_EDITW equ <L("Edit")>
          ifdef UNICODE
            WC_EDIT equ <WC_EDITW>
          else
            WC_EDIT equ <WC_EDITA>
          endif
        else
          ;[...]
        endif
        if (NTDDI_VERSION ge NTDDI_WIN10_RS5)
          ; Edit Control Extended Styles to use with EM_SETEXTENDEDSTYLE/EM_GETEXTENDEDSTYLE
          ES_EX_ALLOWEOL_CR equ 0001h
          ES_EX_ALLOWEOL_LF equ 0002h
          ES_EX_ALLOWEOL_ALL equ <(ES_EX_ALLOWEOL_CR or ES_EX_ALLOWEOL_LF)>
          ES_EX_CONVERT_EOL_ON_PASTE equ 0004h
          ES_EX_ZOOMABLE equ 0010h
        endif
        if (NTDDI_VERSION ge NTDDI_WINXP)
          EM_SETCUEBANNER equ (ECM_FIRST + 1); Set the cue banner with the lParm = LPCWSTR

          Edit_SetCueBannerText macro hwnd, lpcwText
            exitm <SNDMSG ((hwnd), EM_SETCUEBANNER, 0, (lpcwText))>
          endm
          Edit_SetCueBannerTextFocused macro hwnd, lpcwText, fDrawFocused
            exitm <SNDMSG ((hwnd), EM_SETCUEBANNER, fDrawFocused, lpcwText)>
          endm
          EM_GETCUEBANNER equ (ECM_FIRST + 2); Set the cue banner with the lParm = LPCWSTR

          Edit_GetCueBannerText macro hwnd, lpwText, cchText
            exitm <SNDMSG ((hwnd), EM_GETCUEBANNER, (lpwText), (cchText))>
          endm
          EDITBALLOONTIP struct
            cbStruct DWORD ?
            pszTitle =POINTER ?
            pszText =POINTER ?
            ttiIcon SDWORD ?
            ; From TTI_*
          EDITBALLOONTIP ends
          _tagEDITBALLOONTIP typedef EDITBALLOONTIP
          PEDITBALLOONTIP typedef ptr EDITBALLOONTIP
          EM_SHOWBALLOONTIP equ (ECM_FIRST + 3); Show a balloon tip associated to the edit control

          Edit_ShowBalloonTip macro hwnd, peditballoontip
            exitm <SNDMSG ((hwnd), EM_SHOWBALLOONTIP, 0, (peditballoontip))>
          endm
          EM_HIDEBALLOONTIP equ (ECM_FIRST + 4); Hide any balloon tip associated with the edit control

          Edit_HideBalloonTip macro hwnd
            exitm <SNDMSG ((hwnd), EM_HIDEBALLOONTIP, 0, 0)>
          endm
        endif
        if (NTDDI_VERSION ge NTDDI_VISTA)
          EM_SETHILITE equ (ECM_FIRST + 5)
          Edit_SetHilite macro hwndCtl, ichStart, ichEnd
            exitm <(SNDMSG ((hwndCtl), EM_SETHILITE, (ichStart), (ichEnd)))>
          endm
          EM_GETHILITE equ (ECM_FIRST + 6)
          Edit_GetHilite macro hwndCtl
            exitm <(SNDMSG ((hwndCtl), EM_GETHILITE, 0, 0))>
          endm
        endif
        EM_NOSETFOCUS equ (ECM_FIRST + 7)
        Edit_NoSetFocus macro hwndCtl
          exitm <(SNDMSG ((hwndCtl), EM_NOSETFOCUS, 0, 0))>
        endm
        EM_TAKEFOCUS equ (ECM_FIRST + 8)
        Edit_TakeFocus macro hwndCtl
          exitm <(SNDMSG ((hwndCtl), EM_TAKEFOCUS, 0, 0))>
        endm
        if (NTDDI_VERSION ge NTDDI_WIN10_RS5)
          ; EM_SETENDOFLINE/EM_GETENDOFLINE options
          EC_ENDOFLINE typedef SDWORD
          EC_ENDOFLINE_DETECTFROMCONTENT equ 0
          EC_ENDOFLINE_CRLF equ 1
          EC_ENDOFLINE_CR equ 2
          EC_ENDOFLINE_LF equ 3

          EM_SETEXTENDEDSTYLE equ (ECM_FIRST + 10)
          Edit_SetExtendedStyle macro hwndCtl, dw_, dwMask
            exitm <SNDMSG ((hwndCtl), EM_SETEXTENDEDSTYLE, (dwMask), (dw_))>
          endm
          EM_GETEXTENDEDSTYLE equ (ECM_FIRST + 11)
          Edit_GetExtendedStyle macro hwndCtl
            exitm <SNDMSG ((hwndCtl), EM_GETEXTENDEDSTYLE, 0, 0)>
          endm
          EM_SETENDOFLINE equ (ECM_FIRST + 12)
          Edit_SetEndOfLine macro hwndCtl, eolType
            exitm <SNDMSG ((hwndCtl), EM_SETENDOFLINE, (eolType), 0)>
          endm
          EM_GETENDOFLINE equ (ECM_FIRST + 13)
          Edit_GetEndOfLine macro hwndCtl
            exitm <(EC_ENDOFLINE) SNDMSG ((hwndCtl), EM_GETENDOFLINE, 0, 0)>
          endm
          EM_ENABLESEARCHWEB equ (ECM_FIRST + 14)
          Edit_EnableSearchWeb macro hwndCtl, enable
            exitm <SNDMSG ((hwndCtl), EM_ENABLESEARCHWEB, (enable), 0)>
          endm
          EM_SEARCHWEB equ (ECM_FIRST + 15)
          Edit_SearchWeb macro hwndCtl
            exitm <SNDMSG ((hwndCtl), EM_SEARCHWEB, 0, 0)>
          endm
          ; Form codes are internal-only so keep the api internal
          EM_SETCARETINDEX equ (ECM_FIRST + 17)
          Edit_SetCaretIndex macro hwndCtl, newCaretPosition
            exitm <SNDMSG ((hwndCtl), EM_SETCARETINDEX, (newCaretIndex), 0)>
          endm
          EM_GETCARETINDEX equ (ECM_FIRST + 18)
          Edit_GetCaretIndex macro hwndCtl
            exitm <SNDMSG ((hwndCtl), EM_GETCARETINDEX, 0, 0)>
          endm
          ; We want to reuse the same messages as richedit.h
          ; which is why these are outside of the ECM_FIRST-ECM_LAST range.
          EM_GETZOOM equ (WM_USER + 224)
          Edit_GetZoom macro hwndCtl, numerator, denominator
            exitm <SNDMSG ((hwndCtl), EM_GETZOOM, (numerator), (denominator))>
          endm
          EM_SETZOOM equ (WM_USER + 225)
          Edit_SetZoom macro hwndCtl, numerator, denominator
            exitm <SNDMSG ((hwndCtl), EM_SETZOOM, (numerator), (denominator))>
          endm
          EM_FILELINEFROMCHAR equ (ECM_FIRST + 19)
          Edit_GetFileLineFromChar macro hwndCtl, characterIndex
            exitm <SNDMSG ((hwndCtl), EM_FILELINEFROMCHAR, (characterIndex), 0)>
          endm
          EM_FILELINEINDEX equ (ECM_FIRST + 20)
          Edit_GetFileLineIndex macro hwndCtl, lineNumber
            exitm <SNDMSG ((hwndCtl), EM_FILELINEINDEX, (lineNumber), 0)>
          endm
          EM_FILELINELENGTH equ (ECM_FIRST + 21)
          Edit_GetFileLineLength macro hwndCtl, characterIndex
            exitm <SNDMSG ((hwndCtl), EM_FILELINELENGTH, (characterIndex), 0)>
          endm
          EM_GETFILELINE equ (ECM_FIRST + 22)
          Edit_GetFileLine macro hwndCtl, lineNumber, textBuffer
            exitm <SNDMSG ((hwndCtl), EM_GETFILELINE, (lineNumber), (textBuffer))>
          endm
          EM_GETFILELINECOUNT equ (ECM_FIRST + 23)
          Edit_GetFileLineCount macro hwndCtl
            exitm <SNDMSG ((hwndCtl), EM_GETFILELINECOUNT, 0, 0)>
          endm
          EN_SEARCHWEB equ (EN_FIRST - 0)
          EC_SEARCHWEB_ENTRYPOINT typedef SDWORD
          EC_SEARCHWEB_ENTRYPOINT_EXTERNAL equ 0
          EC_SEARCHWEB_ENTRYPOINT_CONTEXTMENU equ 1

          NMSEARCHWEB struct
            hdr NMHDR <>
            entrypoint EC_SEARCHWEB_ENTRYPOINT ?
            hasQueryText DWORD ?
            invokeSucceeded DWORD ?
          NMSEARCHWEB ends
        endif
      endif
      ; NOEDIT
      ; =====================  End Edit Control =========================
      ; ====================== Listbox Control =============================
      ifndef NOLISTBOX
        ifdef _WIN32
          ; Listbox Class Name
          WC_LISTBOXA equ <"ListBox">
          WC_LISTBOXW equ <L("ListBox")>
          ifdef UNICODE
            WC_LISTBOX equ <WC_LISTBOXW>
          else
            WC_LISTBOX equ <WC_LISTBOXA>
          endif
        else
          ;[...]
        endif
      endif
      ; NOLISTBOX
      ; =====================  End Listbox Control =========================
      ; ====================== Combobox Control =============================
      ifndef NOCOMBOBOX
        ifdef _WIN32
          ; Combobox Class Name
          WC_COMBOBOXA equ <"ComboBox">
          WC_COMBOBOXW equ <L("ComboBox")>
          ifdef UNICODE
            WC_COMBOBOX equ <WC_COMBOBOXW>
          else
            WC_COMBOBOX equ <WC_COMBOBOXA>
          endif
        else
          ;[...]
        endif
      endif
      ; NOCOMBOBOX
      if (NTDDI_VERSION ge NTDDI_WINXP)
        ; custom combobox control messages
        CB_SETMINVISIBLE equ (CBM_FIRST + 1)
        CB_GETMINVISIBLE equ (CBM_FIRST + 2)
        CB_SETCUEBANNER equ (CBM_FIRST + 3)
        CB_GETCUEBANNER equ (CBM_FIRST + 4)
        ComboBox_SetMinVisible macro hwnd, iMinVisible
          exitm <SNDMSG ((hwnd), CB_SETMINVISIBLE, (iMinVisible), 0)>
        endm
        ComboBox_GetMinVisible macro hwnd
          exitm <SNDMSG ((hwnd), CB_GETMINVISIBLE, 0, 0)>
        endm
        ComboBox_SetCueBannerText macro hwnd, lpcwText
          exitm <SNDMSG ((hwnd), CB_SETCUEBANNER, 0, (lpcwText))>
        endm
        ComboBox_GetCueBannerText macro hwnd, lpwText, cchText
          exitm <SNDMSG ((hwnd), CB_GETCUEBANNER, (lpwText), (cchText))>
        endm
      endif
      ; =====================  End Combobox Control =========================
      ; ====================== Scrollbar Control ============================
      ifndef NOSCROLLBAR
        ifdef _WIN32
          ; Scrollbar Class Name
          WC_SCROLLBARA equ <"ScrollBar">
          WC_SCROLLBARW equ <L("ScrollBar")>
          ifdef UNICODE
            WC_SCROLLBAR equ <WC_SCROLLBARW>
          else
            WC_SCROLLBAR equ <WC_SCROLLBARA>
          endif
        else
          ;[...]
        endif
      endif
      ; NOSCROLLBAR
      ; ===================== End Scrollbar Control =========================
      ; ===================== Task Dialog =========================
      ifndef NOTASKDIALOG
        ; Task Dialog is only available starting Windows Vista
        if (NTDDI_VERSION ge NTDDI_VISTA)
          ifdef _WIN32
            include pshpack1.inc
          endif
          TYPE_PFTASKDIALOGCALLBACK typedef proto WIN_STD_CALL_CONV :HWND, :UINT, :WPARAM, :LPARAM, :LONG_PTR
          PFTASKDIALOGCALLBACK typedef ptr TYPE_PFTASKDIALOGCALLBACK

          ; (NTDDI_VERSION >= NTDDI_WIN8)
          _TASKDIALOG_FLAGS typedef SDWORD
          TDF_ENABLE_HYPERLINKS equ 0001h
          TDF_USE_HICON_MAIN equ 0002h
          TDF_USE_HICON_FOOTER equ 0004h
          TDF_ALLOW_DIALOG_CANCELLATION equ 0008h
          TDF_USE_COMMAND_LINKS equ 0010h
          TDF_USE_COMMAND_LINKS_NO_ICON equ 0020h
          TDF_EXPAND_FOOTER_AREA equ 0040h
          TDF_EXPANDED_BY_DEFAULT equ 0080h
          TDF_VERIFICATION_FLAG_CHECKED equ 0100h
          TDF_SHOW_PROGRESS_BAR equ 0200h
          TDF_SHOW_MARQUEE_PROGRESS_BAR equ 0400h
          TDF_CALLBACK_TIMER equ 0800h
          TDF_POSITION_RELATIVE_TO_WINDOW equ 1000h
          TDF_RTL_LAYOUT equ 2000h
          TDF_NO_DEFAULT_RADIO_BUTTON equ 4000h
          TDF_CAN_BE_MINIMIZED equ 8000h
          if (NTDDI_VERSION ge NTDDI_WIN8)
            TDF_NO_SET_FOREGROUND equ 00010000h
            ; Don't call SetForegroundWindow() when activating the dialog
          endif
          ; (NTDDI_VERSION >= NTDDI_WIN8)
          TDF_SIZE_TO_CONTENT equ 01000000h

          ; used by ShellMessageBox to emulate MessageBox sizing behavior
          TASKDIALOG_FLAGS typedef SDWORD
          ; Note: _TASKDIALOG_FLAGS is an int
          TASKDIALOG_MESSAGES typedef SDWORD
          TDM_NAVIGATE_PAGE equ WM_USER + 101
          TDM_CLICK_BUTTON equ WM_USER + 102
          ; wParam = Button ID
          TDM_SET_MARQUEE_PROGRESS_BAR equ WM_USER + 103
          ; wParam = 0 (nonMarque) wParam != 0 (Marquee)
          TDM_SET_PROGRESS_BAR_STATE equ WM_USER + 104
          ; wParam = new progress state
          TDM_SET_PROGRESS_BAR_RANGE equ WM_USER + 105
          ; lParam = MAKELPARAM(nMinRange, nMaxRange)
          TDM_SET_PROGRESS_BAR_POS equ WM_USER + 106
          ; wParam = new position
          TDM_SET_PROGRESS_BAR_MARQUEE equ WM_USER + 107
          ; wParam = 0 (stop marquee), wParam != 0 (start marquee), lparam = speed (milliseconds between repaints)
          TDM_SET_ELEMENT_TEXT equ WM_USER + 108
          ; wParam = element (TASKDIALOG_ELEMENTS), lParam = new element text (LPCWSTR)
          TDM_CLICK_RADIO_BUTTON equ WM_USER + 110
          ; wParam = Radio Button ID
          TDM_ENABLE_BUTTON equ WM_USER + 111
          ; lParam = 0 (disable), lParam != 0 (enable), wParam = Button ID
          TDM_ENABLE_RADIO_BUTTON equ WM_USER + 112
          ; lParam = 0 (disable), lParam != 0 (enable), wParam = Radio Button ID
          TDM_CLICK_VERIFICATION equ WM_USER + 113
          ; wParam = 0 (unchecked), 1 (checked), lParam = 1 (set key focus)
          TDM_UPDATE_ELEMENT_TEXT equ WM_USER + 114
          ; wParam = element (TASKDIALOG_ELEMENTS), lParam = new element text (LPCWSTR)
          TDM_SET_BUTTON_ELEVATION_REQUIRED_STATE equ WM_USER + 115
          ; wParam = Button ID, lParam = 0 (elevation not required), lParam != 0 (elevation required)
          TDM_UPDATE_ICON equ WM_USER + 116
          _TASKDIALOG_MESSAGES typedef TASKDIALOG_MESSAGES

          ; wParam = icon element (TASKDIALOG_ICON_ELEMENTS), lParam = new icon (hIcon if TDF_USE_HICON_* was set, PCWSTR otherwise)
          TASKDIALOG_NOTIFICATIONS typedef SDWORD
          TDN_CREATED equ 0
          TDN_NAVIGATED equ 1
          TDN_BUTTON_CLICKED equ 2
          ; wParam = Button ID
          TDN_HYPERLINK_CLICKED equ 3
          ; lParam = (LPCWSTR)pszHREF
          TDN_TIMER equ 4
          ; wParam = Milliseconds since dialog created or timer reset
          TDN_DESTROYED equ 5
          TDN_RADIO_BUTTON_CLICKED equ 6
          ; wParam = Radio Button ID
          TDN_DIALOG_CONSTRUCTED equ 7
          TDN_VERIFICATION_CLICKED equ 8
          ; wParam = 1 if checkbox checked, 0 if not, lParam is unused and always 0
          TDN_HELP equ 9
          TDN_EXPANDO_BUTTON_CLICKED equ 10
          _TASKDIALOG_NOTIFICATIONS typedef TASKDIALOG_NOTIFICATIONS

          ; wParam = 0 (dialog is now collapsed), wParam != 0 (dialog is now expanded)
          TASKDIALOG_BUTTON struct
            nButtonID SDWORD ?
            pszButtonText PCWSTR ?
          TASKDIALOG_BUTTON ends
          _TASKDIALOG_BUTTON typedef TASKDIALOG_BUTTON
          TASKDIALOG_ELEMENTS typedef SDWORD
          TDE_CONTENT equ 0
          TDE_EXPANDED_INFORMATION equ 1
          TDE_FOOTER equ 2
          TDE_MAIN_INSTRUCTION equ 3
          _TASKDIALOG_ELEMENTS typedef TASKDIALOG_ELEMENTS

          TASKDIALOG_ICON_ELEMENTS typedef SDWORD
          TDIE_ICON_MAIN equ 0
          TDIE_ICON_FOOTER equ 1
          _TASKDIALOG_ICON_ELEMENTS typedef TASKDIALOG_ICON_ELEMENTS

          TD_WARNING_ICON equ MAKEINTRESOURCEW(- 1)
          TD_ERROR_ICON equ MAKEINTRESOURCEW(- 2)
          TD_INFORMATION_ICON equ MAKEINTRESOURCEW(- 3)
          TD_SHIELD_ICON equ MAKEINTRESOURCEW(- 4)
        endif
        ; (NTDDI_VERSION >= NTDDI_VISTA)
        if (NTDDI_VERSION ge NTDDI_VISTA)
          _TASKDIALOG_COMMON_BUTTON_FLAGS typedef SDWORD
          TDCBF_OK_BUTTON equ 0001h
          ; selected control return value IDOK
          TDCBF_YES_BUTTON equ 0002h
          ; selected control return value IDYES
          TDCBF_NO_BUTTON equ 0004h
          ; selected control return value IDNO
          TDCBF_CANCEL_BUTTON equ 0008h
          ; selected control return value IDCANCEL
          TDCBF_RETRY_BUTTON equ 0010h
          ; selected control return value IDRETRY
          TDCBF_CLOSE_BUTTON equ 0020h

          ; selected control return value IDCLOSE
          TASKDIALOG_COMMON_BUTTON_FLAGS typedef SDWORD
          ; Note: _TASKDIALOG_COMMON_BUTTON_FLAGS is an int
          TASKDIALOGCONFIG struct
            cbSize DWORD ?
            hwndParent HWND ?
            ; incorrectly named, this is the owner window, not a parent.
            hInstance HINSTANCE ?
            ; used for MAKEINTRESOURCE() strings
            dwFlags TASKDIALOG_FLAGS ?
            ; TASKDIALOG_FLAGS (TDF_XXX) flags
            dwCommonButtons TASKDIALOG_COMMON_BUTTON_FLAGS ?
            ; TASKDIALOG_COMMON_BUTTON (TDCBF_XXX) flags
            pszWindowTitle PCWSTR ?
            ; string or MAKEINTRESOURCE()
            union
              hMainIcon HICON ?
              pszMainIcon PCWSTR ?
            ends
            pszMainInstruction PCWSTR ?
            pszContent PCWSTR ?
            cButtons DWORD ?
            pButtons POINTER ?
            nDefaultButton SDWORD ?
            cRadioButtons DWORD ?
            pRadioButtons POINTER ?
            nDefaultRadioButton SDWORD ?
            pszVerificationText PCWSTR ?
            pszExpandedInformation PCWSTR ?
            pszExpandedControlText PCWSTR ?
            pszCollapsedControlText PCWSTR ?
            union
              hFooterIcon HICON ?
              pszFooterIcon PCWSTR ?
            ends
            pszFooter PCWSTR ?
            pfCallback PFTASKDIALOGCALLBACK ?
            lpCallbackData SXWORD ?
            cxWidth DWORD ?
            ; width of the Task Dialog's client area in DLU's. If 0, Task Dialog will calculate the ideal width.
          TASKDIALOGCONFIG ends
          _TASKDIALOGCONFIG typedef TASKDIALOGCONFIG
          @DefProto DllImport, TaskDialogIndirect, WIN_STD_CALL_CONV,, <:ptr TASKDIALOGCONFIG, :ptr SDWORD, :ptr SDWORD, :ptr BOOL>, 16
          @DefProto DllImport, TaskDialog, WIN_STD_CALL_CONV,, <:HWND, :HINSTANCE, :PCWSTR, :PCWSTR, :PCWSTR, :TASKDIALOG_COMMON_BUTTON_FLAGS, :PCWSTR, :ptr SDWORD>, 32
          ifdef _WIN32
            include poppack.inc
          endif
        endif
        ; (NTDDI_VERSION >= NTDDI_VISTA)
      endif
      ; NOTASKDIALOG
      ; ==================== End TaskDialog =======================
      ; === MUI APIs ===
      ifndef NOMUI
        InitMUILanguage proto WIN_STD_CALL_CONV :LANGID
        GetMUILanguage proto WIN_STD_CALL_CONV
      endif
      ; NOMUI
      include dpa_dsa.inc
      ifdef _WIN32
        ;====== TrackMouseEvent  =====================================================
        ifndef NOTRACKMOUSEEVENT
          ; If the messages for TrackMouseEvent have not been defined then define them
          ; now.
          ifndef WM_MOUSEHOVER
            WM_MOUSEHOVER equ 02A1h
            WM_MOUSELEAVE equ 02A3h
          endif
          ; If the TRACKMOUSEEVENT structure and associated flags havent been declared
          ; then declare them now.
          ifndef TME_HOVER
            TME_HOVER equ 00000001h
            TME_LEAVE equ 00000002h
            if (WINVER ge 0500h)
              TME_NONCLIENT equ 00000010h
              ;* WINVER >= 0x0500 *
            endif
            TME_QUERY equ 40000000h
            TME_CANCEL equ 80000000h
            HOVER_DEFAULT equ 0FFFFFFFFh
            TRACKMOUSEEVENT struct
              cbSize DWORD ?
              dwFlags DWORD ?
              hwndTrack HWND ?
              dwHoverTime DWORD ?
            TRACKMOUSEEVENT ends
            tagTRACKMOUSEEVENT typedef TRACKMOUSEEVENT
            LPTRACKMOUSEEVENT typedef ptr TRACKMOUSEEVENT
          endif
          ; !TME_HOVER
          ; Declare _TrackMouseEvent.  This API tries to use the window manager's
          ; implementation of TrackMouseEvent if it is present, otherwise it emulates.
          @DefProto DllImport, _TrackMouseEvent, WIN_STD_CALL_CONV,, <:LPTRACKMOUSEEVENT>, 4
        endif
        ; !NOTRACKMOUSEEVENT
        ;====== Flat Scrollbar APIs=========================================
        ifndef NOFLATSBAPIS
          WSB_PROP_CYVSCROLL equ 00000001h
          WSB_PROP_CXHSCROLL equ 00000002h
          WSB_PROP_CYHSCROLL equ 00000004h
          WSB_PROP_CXVSCROLL equ 00000008h
          WSB_PROP_CXHTHUMB equ 00000010h
          WSB_PROP_CYVTHUMB equ 00000020h
          WSB_PROP_VBKGCOLOR equ 00000040h
          WSB_PROP_HBKGCOLOR equ 00000080h
          WSB_PROP_VSTYLE equ 00000100h
          WSB_PROP_HSTYLE equ 00000200h
          WSB_PROP_WINSTYLE equ 00000400h
          WSB_PROP_PALETTE equ 00000800h
          WSB_PROP_MASK equ 00000FFFh
          FSB_FLAT_MODE equ 2
          FSB_ENCARTA_MODE equ 1
          FSB_REGULAR_MODE equ 0
          @DefProto DllImport, FlatSB_EnableScrollBar, WIN_STD_CALL_CONV,, <:HWND, :SDWORD, :UINT>, 12
          @DefProto DllImport, FlatSB_ShowScrollBar, WIN_STD_CALL_CONV,, <:HWND, :SDWORD, :BOOL>, 12
          @DefProto DllImport, FlatSB_GetScrollRange, WIN_STD_CALL_CONV,, <:HWND, :SDWORD, :LPINT, :LPINT>, 16
          @DefProto DllImport, FlatSB_GetScrollInfo, WIN_STD_CALL_CONV,, <:HWND, :SDWORD, :LPSCROLLINFO>, 12
          @DefProto DllImport, FlatSB_GetScrollPos, WIN_STD_CALL_CONV,, <:HWND, :SDWORD>, 8
          @DefProto DllImport, FlatSB_GetScrollProp, WIN_STD_CALL_CONV,, <:HWND, :SDWORD, :LPINT>, 12
          ifdef _WIN64
            @DefProto DllImport, FlatSB_GetScrollPropPtr, WIN_STD_CALL_CONV,, <:HWND, :SDWORD, :PINT_PTR>, 12
          else
            FlatSB_GetScrollPropPtr equ <FlatSB_GetScrollProp>
          endif
          @DefProto DllImport, FlatSB_SetScrollPos, WIN_STD_CALL_CONV,, <:HWND, :SDWORD, :SDWORD, :BOOL>, 16
          @DefProto DllImport, FlatSB_SetScrollInfo, WIN_STD_CALL_CONV,, <:HWND, :SDWORD, :LPSCROLLINFO, :BOOL>, 16
          @DefProto DllImport, FlatSB_SetScrollRange, WIN_STD_CALL_CONV,, <:HWND, :SDWORD, :SDWORD, :SDWORD, :BOOL>, 20
          @DefProto DllImport, FlatSB_SetScrollProp, WIN_STD_CALL_CONV,, <:HWND, :UINT, :INT_PTR, :BOOL>, 16
          FlatSB_SetScrollPropPtr equ <FlatSB_SetScrollProp>
          @DefProto DllImport, InitializeFlatSB, WIN_STD_CALL_CONV,, <:HWND>, 4
          @DefProto DllImport, UninitializeFlatSB, WIN_STD_CALL_CONV,, <:HWND>, 4
        endif
        ;  NOFLATSBAPIS
        ;* _WIN32 *
      endif
      if (NTDDI_VERSION ge NTDDI_WINXP)
        ; subclassing stuff
        TYPE_SUBCLASSPROC typedef proto WIN_STD_CALL_CONV :HWND, :UINT, :WPARAM, :LPARAM, :UINT_PTR, :DWORD_PTR
        SUBCLASSPROC typedef ptr TYPE_SUBCLASSPROC

        SetWindowSubclass proto WIN_STD_CALL_CONV :HWND, :SUBCLASSPROC, :UINT_PTR, :DWORD_PTR
        GetWindowSubclass proto WIN_STD_CALL_CONV :HWND, :SUBCLASSPROC, :UINT_PTR, :ptr DWORD_PTR
        RemoveWindowSubclass proto WIN_STD_CALL_CONV :HWND, :SUBCLASSPROC, :UINT_PTR
        DefSubclassProc proto WIN_STD_CALL_CONV :HWND, :UINT, :WPARAM, :LPARAM
      endif
      if (NTDDI_VERSION ge NTDDI_VISTA)
        _LI_METRIC typedef SDWORD
        LIM_SMALL equ 0
        ; corresponds to SM_CXSMICON/SM_CYSMICON
        LIM_LARGE equ 1
        ; corresponds to SM_CXICON/SM_CYICON

        @DefProto DllImport, LoadIconMetric, WIN_STD_CALL_CONV,, <:HINSTANCE, :PCWSTR, :SDWORD, :ptr HICON>, 16
        @DefProto DllImport, LoadIconWithScaleDown, WIN_STD_CALL_CONV,, <:HINSTANCE, :PCWSTR, :SDWORD, :SDWORD, :ptr HICON>, 20
      endif
      ; NTDDI_VISTA
      if (NTDDI_VERSION ge NTDDI_WINXP)
        DrawShadowText proto WIN_STD_CALL_CONV :HDC, :LPCWSTR, :UINT, :ptr RECT, :DWORD, :COLORREF, :COLORREF, :SDWORD, :SDWORD
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
    endif
    if Defined(_MSC_VER) and (_MSC_VER ge 1200)
    endif
    ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) *
  endif
  ;* _INC_COMMCTRL *
endif
