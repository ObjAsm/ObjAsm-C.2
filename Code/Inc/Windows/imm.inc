;Include file created by h2incX, Version B.01.01, 10/09/2018 22:03
;(C) 2018-today by Biterider, 2005-2009 by Japheth
;Source file: '\ObjAsm\Projects\h2IncX\header\imm.h', last modified: 19/04/2018 10:46
;Creation parameters: 

include winapifamily.inc
ifndef _IMM_
  _IMM_ equ <>
  ifdef __cplusplus
    ;[...]
  endif
  if _MSC_VER ge 1200
  endif
  ifndef _IMM_SDK_DEFINED_
    _IMM_SDK_DEFINED_ equ <>
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP)
      if (WINVER ge 040Ah)
        DECLARE_HANDLE HIMC
        DECLARE_HANDLE HIMCC
      else
        HIMC typedef DWORD
        HIMCC typedef DWORD
      endif
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
      LPHKL typedef ptr HKL
      LPUINT typedef ptr UINT
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP)
      COMPOSITIONFORM struct
        dwStyle DWORD ?
        ptCurrentPos POINT <>
        rcArea RECT <>
      COMPOSITIONFORM ends

      tagCOMPOSITIONFORM typedef COMPOSITIONFORM
      PCOMPOSITIONFORM typedef ptr COMPOSITIONFORM
      NPCOMPOSITIONFORM typedef ptr COMPOSITIONFORM
      LPCOMPOSITIONFORM typedef ptr COMPOSITIONFORM
      
      CANDIDATEFORM struct
        dwIndex DWORD ?
        dwStyle DWORD ?
        ptCurrentPos POINT <>
        rcArea RECT <>
      CANDIDATEFORM ends

      tagCANDIDATEFORM typedef CANDIDATEFORM
      PCANDIDATEFORM typedef ptr CANDIDATEFORM
      NPCANDIDATEFORM typedef ptr CANDIDATEFORM
      LPCANDIDATEFORM typedef ptr CANDIDATEFORM
      
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
      CANDIDATELIST struct
        dwSize DWORD ?
        dwStyle DWORD ?
        dwCount DWORD ?
        dwSelection DWORD ?
        dwPageStart DWORD ?
        dwPageSize DWORD ?
        dwOffset DWORD 1 dup (?)
      CANDIDATELIST ends

      tagCANDIDATELIST typedef CANDIDATELIST
      PCANDIDATELIST typedef ptr CANDIDATELIST
      NPCANDIDATELIST typedef ptr CANDIDATELIST
      LPCANDIDATELIST typedef ptr CANDIDATELIST
      
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP)
      REGISTERWORDA struct
        lpReading LPSTR ?
        lpWord LPSTR ?
      REGISTERWORDA ends

      tagREGISTERWORDA typedef REGISTERWORDA
      PREGISTERWORDA typedef ptr REGISTERWORDA
      NPREGISTERWORDA typedef ptr REGISTERWORDA
      LPREGISTERWORDA typedef ptr REGISTERWORDA
      
      REGISTERWORDW struct
        lpReading LPWSTR ?
        lpWord LPWSTR ?
      REGISTERWORDW ends

      tagREGISTERWORDW typedef REGISTERWORDW
      PREGISTERWORDW typedef ptr REGISTERWORDW
      NPREGISTERWORDW typedef ptr REGISTERWORDW
      LPREGISTERWORDW typedef ptr REGISTERWORDW
      
      ifdef UNICODE
        REGISTERWORD typedef REGISTERWORDW
        PREGISTERWORD typedef PREGISTERWORDW
        NPREGISTERWORD typedef NPREGISTERWORDW
        LPREGISTERWORD typedef LPREGISTERWORDW
      else
        REGISTERWORD typedef REGISTERWORDA
        PREGISTERWORD typedef PREGISTERWORDA
        NPREGISTERWORD typedef NPREGISTERWORDA
        LPREGISTERWORD typedef LPREGISTERWORDA
      endif
    endif
    if (WINVER ge 040Ah)
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
        RECONVERTSTRING struct
          dwSize DWORD ?
          dwVersion DWORD ?
          dwStrLen DWORD ?
          dwStrOffset DWORD ?
          dwCompStrLen DWORD ?
          dwCompStrOffset DWORD ?
          dwTargetStrLen DWORD ?
          dwTargetStrOffset DWORD ?
        RECONVERTSTRING ends

        tagRECONVERTSTRING typedef RECONVERTSTRING
        PRECONVERTSTRING typedef ptr RECONVERTSTRING
        NPRECONVERTSTRING typedef ptr RECONVERTSTRING
        LPRECONVERTSTRING typedef ptr RECONVERTSTRING
        
      endif
    endif
    STYLE_DESCRIPTION_SIZE equ 32
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP)
      STYLEBUFA struct
        dwStyle DWORD ?
        szDescription CHAR STYLE_DESCRIPTION_SIZE dup (?)
      STYLEBUFA ends

      tagSTYLEBUFA typedef STYLEBUFA
      PSTYLEBUFA typedef ptr STYLEBUFA
      NPSTYLEBUFA typedef ptr STYLEBUFA
      LPSTYLEBUFA typedef ptr STYLEBUFA
      
      STYLEBUFW struct
        dwStyle DWORD ?
        szDescription WCHAR STYLE_DESCRIPTION_SIZE dup (?)
      STYLEBUFW ends

      tagSTYLEBUFW typedef STYLEBUFW
      PSTYLEBUFW typedef ptr STYLEBUFW
      NPSTYLEBUFW typedef ptr STYLEBUFW
      LPSTYLEBUFW typedef ptr STYLEBUFW
      
      ifdef UNICODE
        STYLEBUF typedef STYLEBUFW
        PSTYLEBUF typedef PSTYLEBUFW
        NPSTYLEBUF typedef NPSTYLEBUFW
        LPSTYLEBUF typedef LPSTYLEBUFW
      else
        STYLEBUF typedef STYLEBUFA
        PSTYLEBUF typedef PSTYLEBUFA
        NPSTYLEBUF typedef NPSTYLEBUFA
        LPSTYLEBUF typedef LPSTYLEBUFA
      endif
    endif
    if (WINVER ge 040Ah)
      IMEMENUITEM_STRING_SIZE equ 80
      if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
        IMEMENUITEMINFOA struct
          cbSize UINT ?
          fType UINT ?
          fState UINT ?
          wID UINT ?
          hbmpChecked HBITMAP ?
          hbmpUnchecked HBITMAP ?
          dwItemData DWORD ?
          szString CHAR IMEMENUITEM_STRING_SIZE dup (?)
          hbmpItem HBITMAP ?
        IMEMENUITEMINFOA ends

        tagIMEMENUITEMINFOA typedef IMEMENUITEMINFOA
        PIMEMENUITEMINFOA typedef ptr IMEMENUITEMINFOA
        NPIMEMENUITEMINFOA typedef ptr IMEMENUITEMINFOA
        LPIMEMENUITEMINFOA typedef ptr IMEMENUITEMINFOA
        
        IMEMENUITEMINFOW struct
          cbSize UINT ?
          fType UINT ?
          fState UINT ?
          wID UINT ?
          hbmpChecked HBITMAP ?
          hbmpUnchecked HBITMAP ?
          dwItemData DWORD ?
          szString WCHAR IMEMENUITEM_STRING_SIZE dup (?)
          hbmpItem HBITMAP ?
        IMEMENUITEMINFOW ends

        tagIMEMENUITEMINFOW typedef IMEMENUITEMINFOW
        PIMEMENUITEMINFOW typedef ptr IMEMENUITEMINFOW
        NPIMEMENUITEMINFOW typedef ptr IMEMENUITEMINFOW
        LPIMEMENUITEMINFOW typedef ptr IMEMENUITEMINFOW
        
        ifdef UNICODE
          IMEMENUITEMINFO typedef IMEMENUITEMINFOW
          PIMEMENUITEMINFO typedef PIMEMENUITEMINFOW
          NPIMEMENUITEMINFO typedef NPIMEMENUITEMINFOW
          LPIMEMENUITEMINFO typedef LPIMEMENUITEMINFOW
        else
          IMEMENUITEMINFO typedef IMEMENUITEMINFOA
          PIMEMENUITEMINFO typedef PIMEMENUITEMINFOA
          NPIMEMENUITEMINFO typedef NPIMEMENUITEMINFOA
          LPIMEMENUITEMINFO typedef LPIMEMENUITEMINFOA
        endif
        IMECHARPOSITION struct
          dwSize DWORD ?
          dwCharPos DWORD ?
          pt POINT <>
          cLineHeight UINT ?
          rcDocument RECT <>
        IMECHARPOSITION ends

        tagIMECHARPOSITION typedef IMECHARPOSITION
        PIMECHARPOSITION typedef ptr IMECHARPOSITION
        NPIMECHARPOSITION typedef ptr IMECHARPOSITION
        LPIMECHARPOSITION typedef ptr IMECHARPOSITION
        
        TYPE_IMCENUMPROC typedef proto WIN_STD_CALL_CONV :HIMC, :LPARAM
        IMCENUMPROC typedef ptr TYPE_IMCENUMPROC
      endif
    endif
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
      ImmInstallIMEA proto WIN_STD_CALL_CONV :LPCSTR, :LPCSTR
      ImmInstallIMEW proto WIN_STD_CALL_CONV :LPCWSTR, :LPCWSTR
      ifdef UNICODE
        ImmInstallIME equ <ImmInstallIMEW>
      else
        ImmInstallIME equ <ImmInstallIMEA>
      endif
      ImmGetDefaultIMEWnd proto WIN_STD_CALL_CONV :HWND
      ImmGetDescriptionA proto WIN_STD_CALL_CONV :HKL, :LPSTR, :UINT
      ImmGetDescriptionW proto WIN_STD_CALL_CONV :HKL, :LPWSTR, :UINT
      ifdef UNICODE
        ImmGetDescription equ <ImmGetDescriptionW>
      else
        ImmGetDescription equ <ImmGetDescriptionA>
      endif
      ImmGetIMEFileNameA proto WIN_STD_CALL_CONV :HKL, :LPSTR, :UINT
      ImmGetIMEFileNameW proto WIN_STD_CALL_CONV :HKL, :LPWSTR, :UINT
      ifdef UNICODE
        ImmGetIMEFileName equ <ImmGetIMEFileNameW>
      else
        ImmGetIMEFileName equ <ImmGetIMEFileNameA>
      endif
      ImmGetProperty proto WIN_STD_CALL_CONV :HKL, :DWORD
      ImmIsIME proto WIN_STD_CALL_CONV :HKL
      ImmSimulateHotKey proto WIN_STD_CALL_CONV :HWND, :DWORD
      ImmCreateContext proto WIN_STD_CALL_CONV
      ImmDestroyContext proto WIN_STD_CALL_CONV :HIMC
      ImmGetContext proto WIN_STD_CALL_CONV :HWND
      ImmReleaseContext proto WIN_STD_CALL_CONV :HWND, :HIMC
      ImmAssociateContext proto WIN_STD_CALL_CONV :HWND, :HIMC
      if (WINVER ge 040Ah)
        ImmAssociateContextEx proto WIN_STD_CALL_CONV :HWND, :HIMC, :DWORD
      endif
      ImmGetCompositionStringA proto WIN_STD_CALL_CONV :HIMC, :DWORD, :LPVOID, :DWORD
      ImmGetCompositionStringW proto WIN_STD_CALL_CONV :HIMC, :DWORD, :LPVOID, :DWORD
      ifdef UNICODE
        ImmGetCompositionString equ <ImmGetCompositionStringW>
      else
        ImmGetCompositionString equ <ImmGetCompositionStringA>
      endif
      ImmSetCompositionStringA proto WIN_STD_CALL_CONV :HIMC, :DWORD, :LPVOID, :DWORD, :LPVOID, :DWORD
      ImmSetCompositionStringW proto WIN_STD_CALL_CONV :HIMC, :DWORD, :LPVOID, :DWORD, :LPVOID, :DWORD
      ifdef UNICODE
        ImmSetCompositionString equ <ImmSetCompositionStringW>
      else
        ImmSetCompositionString equ <ImmSetCompositionStringA>
      endif
      ImmGetCandidateListCountA proto WIN_STD_CALL_CONV :HIMC, :LPDWORD
      ImmGetCandidateListCountW proto WIN_STD_CALL_CONV :HIMC, :LPDWORD
      ifdef UNICODE
        ImmGetCandidateListCount equ <ImmGetCandidateListCountW>
      else
        ImmGetCandidateListCount equ <ImmGetCandidateListCountA>
      endif
      ImmGetCandidateListA proto WIN_STD_CALL_CONV :HIMC, :DWORD, :LPCANDIDATELIST, :DWORD
      ImmGetCandidateListW proto WIN_STD_CALL_CONV :HIMC, :DWORD, :LPCANDIDATELIST, :DWORD
      ifdef UNICODE
        ImmGetCandidateList equ <ImmGetCandidateListW>
      else
        ImmGetCandidateList equ <ImmGetCandidateListA>
      endif
      ImmGetGuideLineA proto WIN_STD_CALL_CONV :HIMC, :DWORD, :LPSTR, :DWORD
      ImmGetGuideLineW proto WIN_STD_CALL_CONV :HIMC, :DWORD, :LPWSTR, :DWORD
      ifdef UNICODE
        ImmGetGuideLine equ <ImmGetGuideLineW>
      else
        ImmGetGuideLine equ <ImmGetGuideLineA>
      endif
      ImmGetConversionStatus proto WIN_STD_CALL_CONV :HIMC, :LPDWORD, :LPDWORD
      ImmSetConversionStatus proto WIN_STD_CALL_CONV :HIMC, :DWORD, :DWORD
      ImmGetOpenStatus proto WIN_STD_CALL_CONV :HIMC
      ImmSetOpenStatus proto WIN_STD_CALL_CONV :HIMC, :BOOL
      if Defined(_WINGDI_) and  not Defined(NOGDI)
        ImmGetCompositionFontA proto WIN_STD_CALL_CONV :HIMC, :LPLOGFONTA
        ImmGetCompositionFontW proto WIN_STD_CALL_CONV :HIMC, :LPLOGFONTW
        ifdef UNICODE
          ImmGetCompositionFont equ <ImmGetCompositionFontW>
        else
          ImmGetCompositionFont equ <ImmGetCompositionFontA>
        endif
        ImmSetCompositionFontA proto WIN_STD_CALL_CONV :HIMC, :LPLOGFONTA
        ImmSetCompositionFontW proto WIN_STD_CALL_CONV :HIMC, :LPLOGFONTW
        ifdef UNICODE
          ImmSetCompositionFont equ <ImmSetCompositionFontW>
        else
          ImmSetCompositionFont equ <ImmSetCompositionFontA>
        endif
      endif
      ImmConfigureIMEA proto WIN_STD_CALL_CONV :HKL, :HWND, :DWORD, :LPVOID
      ImmConfigureIMEW proto WIN_STD_CALL_CONV :HKL, :HWND, :DWORD, :LPVOID
      ifdef UNICODE
        ImmConfigureIME equ <ImmConfigureIMEW>
      else
        ImmConfigureIME equ <ImmConfigureIMEA>
      endif
      ImmEscapeA proto WIN_STD_CALL_CONV :HKL, :HIMC, :UINT, :LPVOID
      ImmEscapeW proto WIN_STD_CALL_CONV :HKL, :HIMC, :UINT, :LPVOID
      ifdef UNICODE
        ImmEscape equ <ImmEscapeW>
      else
        ImmEscape equ <ImmEscapeA>
      endif
      ImmGetConversionListA proto WIN_STD_CALL_CONV :HKL, :HIMC, :LPCSTR, :LPCANDIDATELIST, :DWORD, :UINT
      ImmGetConversionListW proto WIN_STD_CALL_CONV :HKL, :HIMC, :LPCWSTR, :LPCANDIDATELIST, :DWORD, :UINT
      ifdef UNICODE
        ImmGetConversionList equ <ImmGetConversionListW>
      else
        ImmGetConversionList equ <ImmGetConversionListA>
      endif
      ImmNotifyIME proto WIN_STD_CALL_CONV :HIMC, :DWORD, :DWORD, :DWORD
      ImmGetStatusWindowPos proto WIN_STD_CALL_CONV :HIMC, :LPPOINT
      ImmSetStatusWindowPos proto WIN_STD_CALL_CONV :HIMC, :LPPOINT
      ImmGetCompositionWindow proto WIN_STD_CALL_CONV :HIMC, :LPCOMPOSITIONFORM
      ImmSetCompositionWindow proto WIN_STD_CALL_CONV :HIMC, :LPCOMPOSITIONFORM
      ImmGetCandidateWindow proto WIN_STD_CALL_CONV :HIMC, :DWORD, :LPCANDIDATEFORM
      ImmSetCandidateWindow proto WIN_STD_CALL_CONV :HIMC, :LPCANDIDATEFORM
      ImmIsUIMessageA proto WIN_STD_CALL_CONV :HWND, :UINT, :WPARAM, :LPARAM
      ImmIsUIMessageW proto WIN_STD_CALL_CONV :HWND, :UINT, :WPARAM, :LPARAM
      ifdef UNICODE
        ImmIsUIMessage equ <ImmIsUIMessageW>
      else
        ImmIsUIMessage equ <ImmIsUIMessageA>
      endif
      ImmGetVirtualKey proto WIN_STD_CALL_CONV :HWND
      TYPE_REGISTERWORDENUMPROCA typedef proto WIN_STD_CALL_CONV :LPCSTR, :DWORD, :LPCSTR, :LPVOID
      REGISTERWORDENUMPROCA typedef ptr TYPE_REGISTERWORDENUMPROCA
      TYPE_REGISTERWORDENUMPROCW typedef proto WIN_STD_CALL_CONV :LPCWSTR, :DWORD, :LPCWSTR, :LPVOID
      REGISTERWORDENUMPROCW typedef ptr TYPE_REGISTERWORDENUMPROCW
      ifdef UNICODE
        REGISTERWORDENUMPROC equ <REGISTERWORDENUMPROCW>
      else
        REGISTERWORDENUMPROC equ <REGISTERWORDENUMPROCA>
      endif
      ImmRegisterWordA proto WIN_STD_CALL_CONV :HKL, :LPCSTR, :DWORD, :LPCSTR
      ImmRegisterWordW proto WIN_STD_CALL_CONV :HKL, :LPCWSTR, :DWORD, :LPCWSTR
      ifdef UNICODE
        ImmRegisterWord equ <ImmRegisterWordW>
      else
        ImmRegisterWord equ <ImmRegisterWordA>
      endif
      ImmUnregisterWordA proto WIN_STD_CALL_CONV :HKL, :LPCSTR, :DWORD, :LPCSTR
      ImmUnregisterWordW proto WIN_STD_CALL_CONV :HKL, :LPCWSTR, :DWORD, :LPCWSTR
      ifdef UNICODE
        ImmUnregisterWord equ <ImmUnregisterWordW>
      else
        ImmUnregisterWord equ <ImmUnregisterWordA>
      endif
      ImmGetRegisterWordStyleA proto WIN_STD_CALL_CONV :HKL, :UINT, :LPSTYLEBUFA
      ImmGetRegisterWordStyleW proto WIN_STD_CALL_CONV :HKL, :UINT, :LPSTYLEBUFW
      ifdef UNICODE
        ImmGetRegisterWordStyle equ <ImmGetRegisterWordStyleW>
      else
        ImmGetRegisterWordStyle equ <ImmGetRegisterWordStyleA>
      endif
      ImmEnumRegisterWordA proto WIN_STD_CALL_CONV :HKL, :REGISTERWORDENUMPROCA, :LPCSTR, :DWORD, :LPCSTR, :LPVOID
      ImmEnumRegisterWordW proto WIN_STD_CALL_CONV :HKL, :REGISTERWORDENUMPROCW, :LPCWSTR, :DWORD, :LPCWSTR, :LPVOID
      ifdef UNICODE
        ImmEnumRegisterWord equ <ImmEnumRegisterWordW>
      else
        ImmEnumRegisterWord equ <ImmEnumRegisterWordA>
      endif
      if (WINVER ge 040Ah)
        ImmDisableIME proto WIN_STD_CALL_CONV :DWORD
        ImmEnumInputContext proto WIN_STD_CALL_CONV :DWORD, :IMCENUMPROC, :LPARAM
        ImmGetImeMenuItemsA proto WIN_STD_CALL_CONV :HIMC, :DWORD, :DWORD, :LPIMEMENUITEMINFOA, :LPIMEMENUITEMINFOA, :DWORD
        ImmGetImeMenuItemsW proto WIN_STD_CALL_CONV :HIMC, :DWORD, :DWORD, :LPIMEMENUITEMINFOW, :LPIMEMENUITEMINFOW, :DWORD
        ifdef UNICODE
          ImmGetImeMenuItems equ <ImmGetImeMenuItemsW>
        else
          ImmGetImeMenuItems equ <ImmGetImeMenuItemsA>
        endif
        ImmDisableTextFrameService proto WIN_STD_CALL_CONV :DWORD
      endif
      if (WINVER ge 0602h)
        ImmDisableLegacyIME proto WIN_STD_CALL_CONV
      endif
    endif
    IMC_GETCANDIDATEPOS equ 0007h
    IMC_SETCANDIDATEPOS equ 0008h
    IMC_GETCOMPOSITIONFONT equ 0009h
    IMC_SETCOMPOSITIONFONT equ 000Ah
    IMC_GETCOMPOSITIONWINDOW equ 000Bh
    IMC_SETCOMPOSITIONWINDOW equ 000Ch
    IMC_GETSTATUSWINDOWPOS equ 000Fh
    IMC_SETSTATUSWINDOWPOS equ 0010h
    IMC_CLOSESTATUSWINDOW equ 0021h
    IMC_OPENSTATUSWINDOW equ 0022h
    NI_OPENCANDIDATE equ 0010h
    NI_CLOSECANDIDATE equ 0011h
    NI_SELECTCANDIDATESTR equ 0012h
    NI_CHANGECANDIDATELIST equ 0013h
    NI_FINALIZECONVERSIONRESULT equ 0014h
    NI_COMPOSITIONSTR equ 0015h
    NI_SETCANDIDATE_PAGESTART equ 0016h
    NI_SETCANDIDATE_PAGESIZE equ 0017h
    NI_IMEMENUSELECTED equ 0018h
    ISC_SHOWUICANDIDATEWINDOW equ 00000001h
    ISC_SHOWUICOMPOSITIONWINDOW equ 80000000h
    ISC_SHOWUIGUIDELINE equ 40000000h
    ISC_SHOWUIALLCANDIDATEWINDOW equ 0000000Fh
    ISC_SHOWUIALL equ 0C000000Fh
    CPS_COMPLETE equ 0001h
    CPS_CONVERT equ 0002h
    CPS_REVERT equ 0003h
    CPS_CANCEL equ 0004h
    MOD_ALT equ 0001h
    MOD_CONTROL equ 0002h
    MOD_SHIFT equ 0004h
    MOD_LEFT equ 8000h
    MOD_RIGHT equ 4000h
    MOD_ON_KEYUP equ 0800h
    MOD_IGNORE_ALL_MODIFIER equ 0400h
    IME_CHOTKEY_IME_NONIME_TOGGLE equ 10h
    IME_CHOTKEY_SHAPE_TOGGLE equ 11h
    IME_CHOTKEY_SYMBOL_TOGGLE equ 12h
    IME_JHOTKEY_CLOSE_OPEN equ 30h
    IME_KHOTKEY_SHAPE_TOGGLE equ 50h
    IME_KHOTKEY_HANJACONVERT equ 51h
    IME_KHOTKEY_ENGLISH equ 52h
    IME_THOTKEY_IME_NONIME_TOGGLE equ 70h
    IME_THOTKEY_SHAPE_TOGGLE equ 71h
    IME_THOTKEY_SYMBOL_TOGGLE equ 72h
    IME_HOTKEY_DSWITCH_FIRST equ 100h
    IME_HOTKEY_DSWITCH_LAST equ 11Fh
    IME_HOTKEY_PRIVATE_FIRST equ 200h
    IME_ITHOTKEY_RESEND_RESULTSTR equ 200h
    IME_ITHOTKEY_PREVIOUS_COMPOSITION equ 201h
    IME_ITHOTKEY_UISTYLE_TOGGLE equ 202h
    IME_ITHOTKEY_RECONVERTSTRING equ 203h
    IME_HOTKEY_PRIVATE_LAST equ 21Fh
    GCS_COMPREADSTR equ 0001h
    GCS_COMPREADATTR equ 0002h
    GCS_COMPREADCLAUSE equ 0004h
    GCS_COMPSTR equ 0008h
    GCS_COMPATTR equ 0010h
    GCS_COMPCLAUSE equ 0020h
    GCS_CURSORPOS equ 0080h
    GCS_DELTASTART equ 0100h
    GCS_RESULTREADSTR equ 0200h
    GCS_RESULTREADCLAUSE equ 0400h
    GCS_RESULTSTR equ 0800h
    GCS_RESULTCLAUSE equ 1000h
    CS_INSERTCHAR equ 2000h
    CS_NOMOVECARET equ 4000h
    IMEVER_0310 equ 0003000Ah
    IMEVER_0400 equ 00040000h
    IME_PROP_AT_CARET equ 00010000h
    IME_PROP_SPECIAL_UI equ 00020000h
    IME_PROP_CANDLIST_START_FROM_1 equ 00040000h
    IME_PROP_UNICODE equ 00080000h
    IME_PROP_COMPLETE_ON_UNSELECT equ 00100000h
    UI_CAP_2700 equ 00000001h
    UI_CAP_ROT90 equ 00000002h
    UI_CAP_ROTANY equ 00000004h
    SCS_CAP_COMPSTR equ 00000001h
    SCS_CAP_MAKEREAD equ 00000002h
    SCS_CAP_SETRECONVERTSTRING equ 00000004h
    SELECT_CAP_CONVERSION equ 00000001h
    SELECT_CAP_SENTENCE equ 00000002h
    GGL_LEVEL equ 00000001h
    GGL_INDEX equ 00000002h
    GGL_STRING equ 00000003h
    GGL_PRIVATE equ 00000004h
    GL_LEVEL_NOGUIDELINE equ 00000000h
    GL_LEVEL_FATAL equ 00000001h
    GL_LEVEL_ERROR equ 00000002h
    GL_LEVEL_WARNING equ 00000003h
    GL_LEVEL_INFORMATION equ 00000004h
    GL_ID_UNKNOWN equ 00000000h
    GL_ID_NOMODULE equ 00000001h
    GL_ID_NODICTIONARY equ 00000010h
    GL_ID_CANNOTSAVE equ 00000011h
    GL_ID_NOCONVERT equ 00000020h
    GL_ID_TYPINGERROR equ 00000021h
    GL_ID_TOOMANYSTROKE equ 00000022h
    GL_ID_READINGCONFLICT equ 00000023h
    GL_ID_INPUTREADING equ 00000024h
    GL_ID_INPUTRADICAL equ 00000025h
    GL_ID_INPUTCODE equ 00000026h
    GL_ID_INPUTSYMBOL equ 00000027h
    GL_ID_CHOOSECANDIDATE equ 00000028h
    GL_ID_REVERSECONVERSION equ 00000029h
    GL_ID_PRIVATE_FIRST equ 00008000h
    GL_ID_PRIVATE_LAST equ 0000FFFFh
    IGP_GETIMEVERSION equ -4
    IGP_PROPERTY equ 00000004h
    IGP_CONVERSION equ 00000008h
    IGP_SENTENCE equ 0000000ch
    IGP_UI equ 00000010h
    IGP_SETCOMPSTR equ 00000014h
    IGP_SELECT equ 00000018h
    SCS_SETSTR equ <(GCS_COMPREADSTR or GCS_COMPSTR)>
    SCS_CHANGEATTR equ <(GCS_COMPREADATTR or GCS_COMPATTR)>
    SCS_CHANGECLAUSE equ <(GCS_COMPREADCLAUSE or GCS_COMPCLAUSE)>
    SCS_SETRECONVERTSTRING equ 00010000h
    SCS_QUERYRECONVERTSTRING equ 00020000h
    ATTR_INPUT equ 00h
    ATTR_TARGET_CONVERTED equ 01h
    ATTR_CONVERTED equ 02h
    ATTR_TARGET_NOTCONVERTED equ 03h
    ATTR_INPUT_ERROR equ 04h
    ATTR_FIXEDCONVERTED equ 05h
    CFS_DEFAULT equ 0000h
    CFS_RECT equ 0001h
    CFS_POINT equ 0002h
    CFS_FORCE_POSITION equ 0020h
    CFS_CANDIDATEPOS equ 0040h
    CFS_EXCLUDE equ 0080h
    GCL_CONVERSION equ 0001h
    GCL_REVERSECONVERSION equ 0002h
    GCL_REVERSE_LENGTH equ 0003h
    include ime_cmodes.inc
    IME_CMODE_HANGEUL equ <IME_CMODE_NATIVE>
    IME_CMODE_SOFTKBD equ 0080h
    IME_CMODE_NOCONVERSION equ 0100h
    IME_CMODE_EUDC equ 0200h
    IME_CMODE_SYMBOL equ 0400h
    IME_CMODE_FIXED equ 0800h
    IME_CMODE_RESERVED equ 0F0000000h
    IME_SMODE_NONE equ 0000h
    IME_SMODE_PLAURALCLAUSE equ 0001h
    IME_SMODE_SINGLECONVERT equ 0002h
    IME_SMODE_AUTOMATIC equ 0004h
    IME_SMODE_PHRASEPREDICT equ 0008h
    IME_SMODE_CONVERSATION equ 0010h
    IME_SMODE_RESERVED equ 0000F000h
    IME_CAND_UNKNOWN equ 0000h
    IME_CAND_READ equ 0001h
    IME_CAND_CODE equ 0002h
    IME_CAND_MEANING equ 0003h
    IME_CAND_RADICAL equ 0004h
    IME_CAND_STROKE equ 0005h
    IMN_CLOSESTATUSWINDOW equ 0001h
    IMN_OPENSTATUSWINDOW equ 0002h
    IMN_CHANGECANDIDATE equ 0003h
    IMN_CLOSECANDIDATE equ 0004h
    IMN_OPENCANDIDATE equ 0005h
    IMN_SETCONVERSIONMODE equ 0006h
    IMN_SETSENTENCEMODE equ 0007h
    IMN_SETOPENSTATUS equ 0008h
    IMN_SETCANDIDATEPOS equ 0009h
    IMN_SETCOMPOSITIONFONT equ 000Ah
    IMN_SETCOMPOSITIONWINDOW equ 000Bh
    IMN_SETSTATUSWINDOWPOS equ 000Ch
    IMN_GUIDELINE equ 000Dh
    IMN_PRIVATE equ 000Eh
    if (WINVER ge 040Ah)
      IMR_COMPOSITIONWINDOW equ 0001h
      IMR_CANDIDATEWINDOW equ 0002h
      IMR_COMPOSITIONFONT equ 0003h
      IMR_RECONVERTSTRING equ 0004h
      IMR_CONFIRMRECONVERTSTRING equ 0005h
      IMR_QUERYCHARPOSITION equ 0006h
      IMR_DOCUMENTFEED equ 0007h
    endif
    IMM_ERROR_NODATA equ -1
    IMM_ERROR_GENERAL equ -2
    IME_CONFIG_GENERAL equ 1
    IME_CONFIG_REGISTERWORD equ 2
    IME_CONFIG_SELECTDICTIONARY equ 3
    IME_ESC_QUERY_SUPPORT equ 0003h
    IME_ESC_RESERVED_FIRST equ 0004h
    IME_ESC_RESERVED_LAST equ 07FFh
    IME_ESC_PRIVATE_FIRST equ 0800h
    IME_ESC_PRIVATE_LAST equ 0FFFh
    IME_ESC_SEQUENCE_TO_INTERNAL equ 1001h
    IME_ESC_GET_EUDC_DICTIONARY equ 1003h
    IME_ESC_SET_EUDC_DICTIONARY equ 1004h
    IME_ESC_MAX_KEY equ 1005h
    IME_ESC_IME_NAME equ 1006h
    IME_ESC_SYNC_HOTKEY equ 1007h
    IME_ESC_HANJA_MODE equ 1008h
    IME_ESC_AUTOMATA equ 1009h
    IME_ESC_PRIVATE_HOTKEY equ 100ah
    IME_ESC_GETHELPFILENAME equ 100bh
    IME_REGWORD_STYLE_EUDC equ 00000001h
    IME_REGWORD_STYLE_USER_FIRST equ 80000000h
    IME_REGWORD_STYLE_USER_LAST equ 0FFFFFFFFh
    if (WINVER ge 040Ah)
      IACE_CHILDREN equ 0001h
      IACE_DEFAULT equ 0010h
      IACE_IGNORENOCONTEXT equ 0020h
      IGIMIF_RIGHTMENU equ 0001h
      IGIMII_CMODE equ 0001h
      IGIMII_SMODE equ 0002h
      IGIMII_CONFIGURE equ 0004h
      IGIMII_TOOLS equ 0008h
      IGIMII_HELP equ 0010h
      IGIMII_OTHER equ 0020h
      IGIMII_INPUTTOOLS equ 0040h
      IMFT_RADIOCHECK equ 00001h
      IMFT_SEPARATOR equ 00002h
      IMFT_SUBMENU equ 00004h
      IMFS_GRAYED equ <MFS_GRAYED>
      IMFS_DISABLED equ <MFS_DISABLED>
      IMFS_CHECKED equ <MFS_CHECKED>
      IMFS_HILITE equ <MFS_HILITE>
      IMFS_ENABLED equ <MFS_ENABLED>
      IMFS_UNCHECKED equ <MFS_UNCHECKED>
      IMFS_UNHILITE equ <MFS_UNHILITE>
      IMFS_DEFAULT equ <MFS_DEFAULT>
    endif
    SOFTKEYBOARD_TYPE_T1 equ 0001h
    SOFTKEYBOARD_TYPE_C1 equ 0002h
  endif
  if _MSC_VER ge 1200
  endif
  ifdef __cplusplus
    ;[...]
  endif
endif

