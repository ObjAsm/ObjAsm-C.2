;Include file created by h2inc+ version C.2.0 on (UTC) 25/05/2024 20:55:09
;(C) G. Friedrich April 2024
;Source file: d:\objasm\projects\x\h2inc+\h\um_10.0.22621.0\richedit.h
;             Created on (UTC) 06/04/2024 06:15:57
;             Last modified on (UTC) 16/12/2023 11:07:52

ifndef _RICHEDIT_
  _RICHEDIT_ equ <>
  include winapifamily.inc
  include wtypes.inc
  include objbase.inc
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    ifdef _WIN32
      include pshpack4.inc
    elseif  not Defined(RC_INVOKED)
    endif
    ifdef __cplusplus
      ;[...]
    endif
    ifndef _RICHEDIT_VER
      _RICHEDIT_VER equ 0810h
    endif
    cchTextLimitDefault equ 32767
    MSFTEDIT_CLASS equ <L("RICHEDIT50W")>
    CERICHEDIT_CLASSA equ <"RichEditCEA">
    CERICHEDIT_CLASSW equ <L("RichEditCEW")>
    RICHEDIT_CLASSA equ <"RichEdit20A">
    RICHEDIT_CLASS10A equ <"RICHEDIT">
    ifndef MACPORT
      RICHEDIT_CLASSW equ <L("RichEdit20W")>
    else
      RICHEDIT_CLASSW equ <TEXT("RichEdit20W")>
    endif
    if (_RICHEDIT_VER ge 0200h)
      ifdef UNICODE
        RICHEDIT_CLASS equ <RICHEDIT_CLASSW>
      else
        RICHEDIT_CLASS equ <RICHEDIT_CLASSA>
      endif
    else
      RICHEDIT_CLASS equ <RICHEDIT_CLASS10A>
    endif
    ifndef WM_CONTEXTMENU
      WM_CONTEXTMENU equ 007Bh
    endif
    ifndef WM_UNICHAR
      WM_UNICHAR equ 0109h
    endif
    ifndef WM_PRINTCLIENT
      WM_PRINTCLIENT equ 0318h
    endif
    ifndef EM_GETLIMITTEXT
      EM_GETLIMITTEXT equ (WM_USER + 37)
    endif
    ifndef EM_POSFROMCHAR
      EM_POSFROMCHAR equ (WM_USER + 38)
      EM_CHARFROMPOS equ (WM_USER + 39)
    endif
    ifndef EM_SCROLLCARET
      EM_SCROLLCARET equ (WM_USER + 49)
    endif
    EM_CANPASTE equ (WM_USER + 50)
    EM_DISPLAYBAND equ (WM_USER + 51)
    EM_EXGETSEL equ (WM_USER + 52)
    EM_EXLIMITTEXT equ (WM_USER + 53)
    EM_EXLINEFROMCHAR equ (WM_USER + 54)
    EM_EXSETSEL equ (WM_USER + 55)
    EM_FINDTEXT equ (WM_USER + 56)
    EM_FORMATRANGE equ (WM_USER + 57)
    EM_GETCHARFORMAT equ (WM_USER + 58)
    EM_GETEVENTMASK equ (WM_USER + 59)
    EM_GETOLEINTERFACE equ (WM_USER + 60)
    EM_GETPARAFORMAT equ (WM_USER + 61)
    EM_GETSELTEXT equ (WM_USER + 62)
    EM_HIDESELECTION equ (WM_USER + 63)
    EM_PASTESPECIAL equ (WM_USER + 64)
    EM_REQUESTRESIZE equ (WM_USER + 65)
    EM_SELECTIONTYPE equ (WM_USER + 66)
    EM_SETBKGNDCOLOR equ (WM_USER + 67)
    EM_SETCHARFORMAT equ (WM_USER + 68)
    EM_SETEVENTMASK equ (WM_USER + 69)
    EM_SETOLECALLBACK equ (WM_USER + 70)
    EM_SETPARAFORMAT equ (WM_USER + 71)
    EM_SETTARGETDEVICE equ (WM_USER + 72)
    EM_STREAMIN equ (WM_USER + 73)
    EM_STREAMOUT equ (WM_USER + 74)
    EM_GETTEXTRANGE equ (WM_USER + 75)
    EM_FINDWORDBREAK equ (WM_USER + 76)
    EM_SETOPTIONS equ (WM_USER + 77)
    EM_GETOPTIONS equ (WM_USER + 78)
    EM_FINDTEXTEX equ (WM_USER + 79)
    ifdef _WIN32
      EM_GETWORDBREAKPROCEX equ (WM_USER + 80)
      EM_SETWORDBREAKPROCEX equ (WM_USER + 81)
    endif
    EM_SETUNDOLIMIT equ (WM_USER + 82)
    EM_REDO equ (WM_USER + 84)
    EM_CANREDO equ (WM_USER + 85)
    EM_GETUNDONAME equ (WM_USER + 86)
    EM_GETREDONAME equ (WM_USER + 87)
    EM_STOPGROUPTYPING equ (WM_USER + 88)
    EM_SETTEXTMODE equ (WM_USER + 89)
    EM_GETTEXTMODE equ (WM_USER + 90)
    TEXTMODE typedef SDWORD
    TM_PLAINTEXT equ 1
    TM_RICHTEXT equ 2
    TM_SINGLELEVELUNDO equ 4
    TM_MULTILEVELUNDO equ 8
    TM_SINGLECODEPAGE equ 16
    TM_MULTICODEPAGE equ 32
    tagTextMode typedef TEXTMODE

    EM_AUTOURLDETECT equ (WM_USER + 91)
    if (_RICHEDIT_VER ge 0800h)
      AURL_ENABLEURL equ 1
      AURL_ENABLEEMAILADDR equ 2
      AURL_ENABLETELNO equ 4
      AURL_ENABLEEAURLS equ 8
      AURL_ENABLEDRIVELETTERS equ 16
      AURL_DISABLEMIXEDLGC equ 32
    endif
    EM_GETAUTOURLDETECT equ (WM_USER + 92)
    EM_SETPALETTE equ (WM_USER + 93)
    EM_GETTEXTEX equ (WM_USER + 94)
    EM_GETTEXTLENGTHEX equ (WM_USER + 95)
    EM_SHOWSCROLLBAR equ (WM_USER + 96)
    EM_SETTEXTEX equ (WM_USER + 97)
    EM_SETPUNCTUATION equ (WM_USER + 100)
    EM_GETPUNCTUATION equ (WM_USER + 101)
    EM_SETWORDWRAPMODE equ (WM_USER + 102)
    EM_GETWORDWRAPMODE equ (WM_USER + 103)
    EM_SETIMECOLOR equ (WM_USER + 104)
    EM_GETIMECOLOR equ (WM_USER + 105)
    EM_SETIMEOPTIONS equ (WM_USER + 106)
    EM_GETIMEOPTIONS equ (WM_USER + 107)
    EM_CONVPOSITION equ (WM_USER + 108)
    EM_SETLANGOPTIONS equ (WM_USER + 120)
    EM_GETLANGOPTIONS equ (WM_USER + 121)
    EM_GETIMECOMPMODE equ (WM_USER + 122)
    EM_FINDTEXTW equ (WM_USER + 123)
    EM_FINDTEXTEXW equ (WM_USER + 124)
    EM_RECONVERSION equ (WM_USER + 125)
    EM_SETIMEMODEBIAS equ (WM_USER + 126)
    EM_GETIMEMODEBIAS equ (WM_USER + 127)
    EM_SETBIDIOPTIONS equ (WM_USER + 200)
    EM_GETBIDIOPTIONS equ (WM_USER + 201)
    EM_SETTYPOGRAPHYOPTIONS equ (WM_USER + 202)
    EM_GETTYPOGRAPHYOPTIONS equ (WM_USER + 203)
    EM_SETEDITSTYLE equ (WM_USER + 204)
    EM_GETEDITSTYLE equ (WM_USER + 205)
    SES_EMULATESYSEDIT equ 1
    SES_BEEPONMAXTEXT equ 2
    SES_EXTENDBACKCOLOR equ 4
    SES_MAPCPS equ 8
    if (_RICHEDIT_VER ge 0500h)
      SES_HYPERLINKTOOLTIPS equ 8
    endif
    SES_EMULATE10 equ 16
    if (_RICHEDIT_VER ge 0700h)
      SES_DEFAULTLATINLIGA equ 16
    endif
    SES_USECRLF equ 32
    if (_RICHEDIT_VER ge 0700h)
      SES_NOFOCUSLINKNOTIFY equ 32
    endif
    SES_USEAIMM equ 64
    SES_NOIME equ 128
    SES_ALLOWBEEPS equ 256
    SES_UPPERCASE equ 512
    SES_LOWERCASE equ 1024
    SES_NOINPUTSEQUENCECHK equ 2048
    SES_BIDI equ 4096
    SES_SCROLLONKILLFOCUS equ 8192
    SES_XLTCRCRLFTOCR equ 16384
    SES_DRAFTMODE equ 32768
    SES_USECTF equ 00010000h
    SES_HIDEGRIDLINES equ 00020000h
    SES_USEATFONT equ 00040000h
    SES_CUSTOMLOOK equ 00080000h
    SES_LBSCROLLNOTIFY equ 00100000h
    SES_CTFALLOWEMBED equ 00200000h
    SES_CTFALLOWSMARTTAG equ 00400000h
    SES_CTFALLOWPROOFING equ 00800000h
    if (_RICHEDIT_VER ge 0500h)
      SES_LOGICALCARET equ 01000000h
      SES_WORDDRAGDROP equ 02000000h
      SES_SMARTDRAGDROP equ 04000000h
      SES_MULTISELECT equ 08000000h
      SES_CTFNOLOCK equ 10000000h
      SES_NOEALINEHEIGHTADJUST equ 20000000h
      SES_MAX equ 20000000h
    endif
    IMF_AUTOKEYBOARD equ 0001h
    IMF_AUTOFONT equ 0002h
    IMF_IMECANCELCOMPLETE equ 0004h
    IMF_IMEALWAYSSENDNOTIFY equ 0008h
    IMF_AUTOFONTSIZEADJUST equ 0010h
    IMF_UIFONTS equ 0020h
    if (_RICHEDIT_VER ge 0800h)
      IMF_NOIMPLICITLANG equ 0040h
    endif
    IMF_DUALFONT equ 0080h
    if (_RICHEDIT_VER ge 0800h)
      IMF_NOKBDLIDFIXUP equ 0200h
    endif
    IMF_NORTFFONTSUBSTITUTE equ 0400h
    if (_RICHEDIT_VER ge 0800h)
      IMF_SPELLCHECKING equ 0800h
      IMF_TKBPREDICTION equ 1000h
    endif
    if (_RICHEDIT_VER ge 0810h)
      IMF_IMEUIINTEGRATION equ 2000h
    endif
    ICM_NOTOPEN equ 0000h
    ICM_LEVEL3 equ 0001h
    ICM_LEVEL2 equ 0002h
    ICM_LEVEL2_5 equ 0003h
    ICM_LEVEL2_SUI equ 0004h
    ICM_CTF equ 0005h
    TO_ADVANCEDTYPOGRAPHY equ 0001h
    TO_SIMPLELINEBREAK equ 0002h
    TO_DISABLECUSTOMTEXTOUT equ 0004h
    TO_ADVANCEDLAYOUT equ 0008h
    EM_OUTLINE equ (WM_USER + 220)
    EM_GETSCROLLPOS equ (WM_USER + 221)
    EM_SETSCROLLPOS equ (WM_USER + 222)
    EM_SETFONTSIZE equ (WM_USER + 223)
    EM_GETZOOM equ (WM_USER + 224)
    EM_SETZOOM equ (WM_USER + 225)
    EM_GETVIEWKIND equ (WM_USER + 226)
    EM_SETVIEWKIND equ (WM_USER + 227)
    EM_GETPAGE equ (WM_USER + 228)
    EM_SETPAGE equ (WM_USER + 229)
    EM_GETHYPHENATEINFO equ (WM_USER + 230)
    EM_SETHYPHENATEINFO equ (WM_USER + 231)
    EM_GETPAGEROTATE equ (WM_USER + 235)
    EM_SETPAGEROTATE equ (WM_USER + 236)
    EM_GETCTFMODEBIAS equ (WM_USER + 237)
    EM_SETCTFMODEBIAS equ (WM_USER + 238)
    EM_GETCTFOPENSTATUS equ (WM_USER + 240)
    EM_SETCTFOPENSTATUS equ (WM_USER + 241)
    EM_GETIMECOMPTEXT equ (WM_USER + 242)
    EM_ISIME equ (WM_USER + 243)
    EM_GETIMEPROPERTY equ (WM_USER + 244)
    EM_GETQUERYRTFOBJ equ (WM_USER + 269)
    EM_SETQUERYRTFOBJ equ (WM_USER + 270)
    EM_SETQUERYCONVERTOLELINKCALLBACK equ (WM_USER + 403)
    EM_SETDISABLEOLELINKCONVERSION equ (WM_USER + 404)
    EPR_0 equ 0
    EPR_270 equ 1
    EPR_180 equ 2
    EPR_90 equ 3
    if (_RICHEDIT_VER ge 0800h)
      EPR_SE equ 5
    endif
    CTFMODEBIAS_DEFAULT equ 0000h
    CTFMODEBIAS_FILENAME equ 0001h
    CTFMODEBIAS_NAME equ 0002h
    CTFMODEBIAS_READING equ 0003h
    CTFMODEBIAS_DATETIME equ 0004h
    CTFMODEBIAS_CONVERSATION equ 0005h
    CTFMODEBIAS_NUMERIC equ 0006h
    CTFMODEBIAS_HIRAGANA equ 0007h
    CTFMODEBIAS_KATAKANA equ 0008h
    CTFMODEBIAS_HANGUL equ 0009h
    CTFMODEBIAS_HALFWIDTHKATAKANA equ 000Ah
    CTFMODEBIAS_FULLWIDTHALPHANUMERIC equ 000Bh
    CTFMODEBIAS_HALFWIDTHALPHANUMERIC equ 000Ch
    IMF_SMODE_PLAURALCLAUSE equ 0001h
    IMF_SMODE_NONE equ 0002h
    IMECOMPTEXT struct
      cb LONG ?
      flags DWORD ?
    IMECOMPTEXT ends
    _imecomptext typedef IMECOMPTEXT
    ICT_RESULTREADSTR equ 1
    EMO_EXIT equ 0
    EMO_ENTER equ 1
    EMO_PROMOTE equ 2
    EMO_EXPAND equ 3
    EMO_MOVESELECTION equ 4
    EMO_GETVIEWMODE equ 5
    EMO_EXPANDSELECTION equ 0
    EMO_EXPANDDOCUMENT equ 1
    VM_NORMAL equ 4
    VM_OUTLINE equ 2
    VM_PAGE equ 9
    if (_RICHEDIT_VER ge 0800h)
      EM_INSERTTABLE equ (WM_USER + 232)
      TABLEROWPARMS struct
        cbRow BYTE ?
        cbCell BYTE ?
        cCell BYTE ?
        cRow BYTE ?
        dxCellMargin LONG ?
        dxIndent LONG ?
        dyHeight LONG ?
        TABLEROWPARMS_REC record TABLEROWPARMS_REC_Filler:24, TABLEROWPARMS_REC_fIdentCells:1, TABLEROWPARMS_REC_fWrap:1, TABLEROWPARMS_REC_fKeepFollow:1, TABLEROWPARMS_REC_fKeep:1, TABLEROWPARMS_REC_fRTL:1, TABLEROWPARMS_REC_nAlignment:3
        TABLEROWPARMS_BITS TABLEROWPARMS_REC <>
        cpStartRow LONG ?
        bTableLevel BYTE ?
        iCell BYTE ?
      TABLEROWPARMS ends
      _tableRowParms typedef TABLEROWPARMS
      TABLECELLPARMS struct
        dxWidth LONG ?
        TABLECELLPARMS_REC record TABLECELLPARMS_REC_Filler:9, TABLECELLPARMS_REC_fMergeCont:1, TABLECELLPARMS_REC_fMergeStart:1, TABLECELLPARMS_REC_fVertical:1, TABLECELLPARMS_REC_fMergePrev:1, TABLECELLPARMS_REC_fMergeTop:1, TABLECELLPARMS_REC_nVertAlign:2
        TABLECELLPARMS_BITS TABLECELLPARMS_REC <>
        wShading WORD ?
        dxBrdrLeft SHORT_ ?
        dyBrdrTop SHORT_ ?
        dxBrdrRight SHORT_ ?
        dyBrdrBottom SHORT_ ?
        crBrdrLeft COLORREF ?
        crBrdrTop COLORREF ?
        crBrdrRight COLORREF ?
        crBrdrBottom COLORREF ?
        crBackPat COLORREF ?
        crForePat COLORREF ?
      TABLECELLPARMS ends
      _tableCellParms typedef TABLECELLPARMS
      EM_GETAUTOCORRECTPROC equ (WM_USER + 233)
      EM_SETAUTOCORRECTPROC equ (WM_USER + 234)
      EM_CALLAUTOCORRECTPROC equ (WM_USER + 255)
      TYPE_AutoCorrectProc typedef proto WIN_STD_CALL_CONV :LANGID, :ptr WCHAR, :ptr WCHAR, :LONG, :ptr LONG
      AutoCorrectProc typedef ptr TYPE_AutoCorrectProc

      ATP_NOCHANGE equ 0
      ATP_CHANGE equ 1
      ATP_NODELIMITER equ 2
      ATP_REPLACEALLTEXT equ 4
      EM_GETTABLEPARMS equ (WM_USER + 265)
      EM_SETEDITSTYLEEX equ (WM_USER + 275)
      EM_GETEDITSTYLEEX equ (WM_USER + 276)
      SES_EX_NOTABLE equ 00000004h
      SES_EX_NOMATH equ 00000040h
      SES_EX_HANDLEFRIENDLYURL equ 00000100h
      SES_EX_NOTHEMING equ 00080000h
      SES_EX_NOACETATESELECTION equ 00100000h
      SES_EX_USESINGLELINE equ 00200000h
      SES_EX_MULTITOUCH equ 08000000h
      SES_EX_HIDETEMPFORMAT equ 10000000h
      SES_EX_USEMOUSEWPARAM equ 20000000h
      EM_GETSTORYTYPE equ (WM_USER + 290)
      EM_SETSTORYTYPE equ (WM_USER + 291)
      EM_GETELLIPSISMODE equ (WM_USER + 305)
      EM_SETELLIPSISMODE equ (WM_USER + 306)
      ELLIPSIS_MASK equ 00000003h
      ELLIPSIS_NONE equ 00000000h
      ELLIPSIS_END equ 00000001h
      ELLIPSIS_WORD equ 00000003h
      EM_SETTABLEPARMS equ (WM_USER + 307)
      EM_GETTOUCHOPTIONS equ (WM_USER + 310)
      EM_SETTOUCHOPTIONS equ (WM_USER + 311)
      EM_INSERTIMAGE equ (WM_USER + 314)
      EM_SETUIANAME equ (WM_USER + 320)
      EM_GETELLIPSISSTATE equ (WM_USER + 322)
      RTO_SHOWHANDLES equ 1
      RTO_DISABLEHANDLES equ 2
      RTO_READINGMODE equ 3
      RICHEDIT_IMAGE_PARAMETERS struct
        xWidth LONG ?
        yHeight LONG ?
        Ascent LONG ?
        Type_ LONG ?
        pwszAlternateText LPCWSTR ?
        pIStream POINTER ?
      RICHEDIT_IMAGE_PARAMETERS ends
      tagRICHEDIT_IMAGE_PARAMETERS typedef RICHEDIT_IMAGE_PARAMETERS
    endif
    EN_MSGFILTER equ 0700h
    EN_REQUESTRESIZE equ 0701h
    EN_SELCHANGE equ 0702h
    EN_DROPFILES equ 0703h
    EN_PROTECTED equ 0704h
    EN_CORRECTTEXT equ 0705h
    EN_STOPNOUNDO equ 0706h
    EN_IMECHANGE equ 0707h
    EN_SAVECLIPBOARD equ 0708h
    EN_OLEOPFAILED equ 0709h
    EN_OBJECTPOSITIONS equ 070ah
    EN_LINK equ 070bh
    EN_DRAGDROPDONE equ 070ch
    EN_PARAGRAPHEXPANDED equ 070dh
    EN_PAGECHANGE equ 070eh
    EN_LOWFIRTF equ 070fh
    EN_ALIGNLTR equ 0710h
    EN_ALIGNRTL equ 0711h
    if (_RICHEDIT_VER ge 0800h)
      EN_CLIPFORMAT equ 0712h
      EN_STARTCOMPOSITION equ 0713h
      EN_ENDCOMPOSITION equ 0714h
      ENDCOMPOSITIONNOTIFY struct
        nmhdr NMHDR <>
        dwCode DWORD ?
      ENDCOMPOSITIONNOTIFY ends
      _endcomposition typedef ENDCOMPOSITIONNOTIFY
      ECN_ENDCOMPOSITION equ 0001h
      ECN_NEWTEXT equ 0002h
    endif
    ENM_NONE equ 00000000h
    ENM_CHANGE equ 00000001h
    ENM_UPDATE equ 00000002h
    ENM_SCROLL equ 00000004h
    ENM_SCROLLEVENTS equ 00000008h
    ENM_DRAGDROPDONE equ 00000010h
    ENM_PARAGRAPHEXPANDED equ 00000020h
    ENM_PAGECHANGE equ 00000040h
    if (_RICHEDIT_VER ge 0800h)
      ENM_CLIPFORMAT equ 00000080h
    endif
    ENM_KEYEVENTS equ 00010000h
    ENM_MOUSEEVENTS equ 00020000h
    ENM_REQUESTRESIZE equ 00040000h
    ENM_SELCHANGE equ 00080000h
    ENM_DROPFILES equ 00100000h
    ENM_PROTECTED equ 00200000h
    ENM_CORRECTTEXT equ 00400000h
    ENM_IMECHANGE equ 00800000h
    ENM_LANGCHANGE equ 01000000h
    ENM_OBJECTPOSITIONS equ 02000000h
    ENM_LINK equ 04000000h
    ENM_LOWFIRTF equ 08000000h
    if (_RICHEDIT_VER ge 0800h)
      ENM_STARTCOMPOSITION equ 10000000h
      ENM_ENDCOMPOSITION equ 20000000h
      ENM_GROUPTYPINGCHANGE equ 40000000h
      ENM_HIDELINKTOOLTIP equ 80000000h
    endif
    ES_SAVESEL equ 00008000h
    ES_SUNKEN equ 00004000h
    ES_DISABLENOSCROLL equ 00002000h
    ES_SELECTIONBAR equ 01000000h
    ES_NOOLEDRAGDROP equ 00000008h
    ES_EX_NOCALLOLEINIT equ 00000000h
    ES_VERTICAL equ 00400000h
    ES_NOIME equ 00080000h
    ES_SELFIME equ 00040000h
    ECO_AUTOWORDSELECTION equ 00000001h
    ECO_AUTOVSCROLL equ 00000040h
    ECO_AUTOHSCROLL equ 00000080h
    ECO_NOHIDESEL equ 00000100h
    ECO_READONLY equ 00000800h
    ECO_WANTRETURN equ 00001000h
    ECO_SAVESEL equ 00008000h
    ECO_SELECTIONBAR equ 01000000h
    ECO_VERTICAL equ 00400000h
    ECOOP_SET equ 0001h
    ECOOP_OR equ 0002h
    ECOOP_AND equ 0003h
    ECOOP_XOR equ 0004h
    WB_CLASSIFY equ 3
    WB_MOVEWORDLEFT equ 4
    WB_MOVEWORDRIGHT equ 5
    WB_LEFTBREAK equ 6
    WB_RIGHTBREAK equ 7
    WB_MOVEWORDPREV equ 4
    WB_MOVEWORDNEXT equ 5
    WB_PREVBREAK equ 6
    WB_NEXTBREAK equ 7
    PC_FOLLOWING equ 1
    PC_LEADING equ 2
    PC_OVERFLOW equ 3
    PC_DELIMITER equ 4
    WBF_WORDWRAP equ 010h
    WBF_WORDBREAK equ 020h
    WBF_OVERFLOW equ 040h
    WBF_LEVEL1 equ 080h
    WBF_LEVEL2 equ 100h
    WBF_CUSTOM equ 200h
    IMF_FORCENONE equ 0001h
    IMF_FORCEENABLE equ 0002h
    IMF_FORCEDISABLE equ 0004h
    IMF_CLOSESTATUSWINDOW equ 0008h
    IMF_VERTICAL equ 0020h
    IMF_FORCEACTIVE equ 0040h
    IMF_FORCEINACTIVE equ 0080h
    IMF_FORCEREMEMBER equ 0100h
    IMF_MULTIPLEEDIT equ 0400h
    WBF_CLASS equ (0Fh)
    WBF_ISWHITE equ (10h)
    WBF_BREAKLINE equ (20h)
    WBF_BREAKAFTER equ (40h)
    ifdef _WIN32
      TYPE_EDITWORDBREAKPROCEX typedef proto WIN_STD_CALL_CONV :ptr SBYTE, :LONG, :BYTE, :INT_
      EDITWORDBREAKPROCEX typedef ptr TYPE_EDITWORDBREAKPROCEX

    endif
    CHARFORMATA struct 4
      cbSize UINT ?
      dwMask DWORD ?
      dwEffects DWORD ?
      yHeight LONG ?
      yOffset LONG ?
      crTextColor COLORREF ?
      bCharSet BYTE ?
      bPitchAndFamily BYTE ?
      szFaceName SBYTE LF_FACESIZE dup (?)
    CHARFORMATA ends
    _charformat typedef CHARFORMATA
    CHARFORMATW struct 4
      cbSize UINT ?
      dwMask DWORD ?
      dwEffects DWORD ?
      yHeight LONG ?
      yOffset LONG ?
      crTextColor COLORREF ?
      bCharSet BYTE ?
      bPitchAndFamily BYTE ?
      szFaceName WCHAR LF_FACESIZE dup (?)
    CHARFORMATW ends
    _charformatw typedef CHARFORMATW
    if (_RICHEDIT_VER ge 0200h)
      ifdef UNICODE
        CHARFORMAT equ <CHARFORMATW>
      else
        CHARFORMAT equ <CHARFORMATA>
      endif
    else
      CHARFORMAT equ <CHARFORMATA>
    endif
    if Defined(__cplusplus)
      ;[...]
    else
      CHARFORMAT2W struct
        cbSize UINT ?
        dwMask DWORD ?
        dwEffects DWORD ?
        yHeight LONG ?
        yOffset LONG ?
        crTextColor COLORREF ?
        bCharSet BYTE ?
        bPitchAndFamily BYTE ?
        szFaceName WCHAR LF_FACESIZE dup (?)
        wWeight WORD ?
        sSpacing SHORT_ ?
        crBackColor COLORREF ?
        lcid LCID ?
        if (_RICHEDIT_VER ge 0500h)
          union
            dwReserved DWORD ?
            dwCookie DWORD ?
          ends
        else
          dwReserved DWORD ?
        endif
        sStyle SHORT_ ?
        wKerning WORD ?
        bUnderlineType BYTE ?
        bAnimation BYTE ?
        bRevAuthor BYTE ?
        if (_RICHEDIT_VER ge 0800h)
          bUnderlineColor BYTE ?
        endif
      CHARFORMAT2W ends
      _charformat2w typedef CHARFORMAT2W
      CHARFORMAT2A struct
        cbSize UINT ?
        dwMask DWORD ?
        dwEffects DWORD ?
        yHeight LONG ?
        yOffset LONG ?
        crTextColor COLORREF ?
        bCharSet BYTE ?
        bPitchAndFamily BYTE ?
        szFaceName SBYTE LF_FACESIZE dup (?)
        wWeight WORD ?
        sSpacing SHORT_ ?
        crBackColor COLORREF ?
        lcid LCID ?
        if (_RICHEDIT_VER ge 0500h)
          union
            dwReserved DWORD ?
            dwCookie DWORD ?
          ends
        else
          dwReserved DWORD ?
        endif
        sStyle SHORT_ ?
        wKerning WORD ?
        bUnderlineType BYTE ?
        bAnimation BYTE ?
        bRevAuthor BYTE ?
        if (_RICHEDIT_VER ge 0800h)
          bUnderlineColor BYTE ?
        endif
      CHARFORMAT2A ends
      _charformat2a typedef CHARFORMAT2A
    endif
    ifdef UNICODE
      CHARFORMAT2 equ <CHARFORMAT2W>
    else
      CHARFORMAT2 equ <CHARFORMAT2A>
    endif
    CHARFORMATDELTA equ <(sizeof(CHARFORMAT2) - sizeof(CHARFORMAT))>
    CFM_BOLD equ 00000001h
    CFM_ITALIC equ 00000002h
    CFM_UNDERLINE equ 00000004h
    CFM_STRIKEOUT equ 00000008h
    CFM_PROTECTED equ 00000010h
    CFM_LINK equ 00000020h
    CFM_SIZE equ 80000000h
    CFM_COLOR equ 40000000h
    CFM_FACE equ 20000000h
    CFM_OFFSET equ 10000000h
    CFM_CHARSET equ 08000000h
    CFE_BOLD equ 00000001h
    CFE_ITALIC equ 00000002h
    CFE_UNDERLINE equ 00000004h
    CFE_STRIKEOUT equ 00000008h
    CFE_PROTECTED equ 00000010h
    CFE_LINK equ 00000020h
    CFE_AUTOCOLOR equ 40000000h
    CFM_SMALLCAPS equ 00000040h
    CFM_ALLCAPS equ 00000080h
    CFM_HIDDEN equ 00000100h
    CFM_OUTLINE equ 00000200h
    CFM_SHADOW equ 00000400h
    CFM_EMBOSS equ 00000800h
    CFM_IMPRINT equ 00001000h
    CFM_DISABLED equ 00002000h
    CFM_REVISED equ 00004000h
    CFM_REVAUTHOR equ 00008000h
    CFE_SUBSCRIPT equ 00010000h
    CFE_SUPERSCRIPT equ 00020000h
    CFM_ANIMATION equ 00040000h
    CFM_STYLE equ 00080000h
    CFM_KERNING equ 00100000h
    CFM_SPACING equ 00200000h
    CFM_WEIGHT equ 00400000h
    CFM_UNDERLINETYPE equ 00800000h
    if (_RICHEDIT_VER ge 0600h)
      CFM_COOKIE equ 01000000h
    endif
    CFM_LCID equ 02000000h
    CFM_BACKCOLOR equ 04000000h
    CFM_SUBSCRIPT equ <(CFE_SUBSCRIPT or CFE_SUPERSCRIPT)>
    CFM_SUPERSCRIPT equ <CFM_SUBSCRIPT>
    CFM_EFFECTS equ <(CFM_BOLD or CFM_ITALIC or CFM_UNDERLINE or CFM_COLOR or CFM_STRIKEOUT or CFE_PROTECTED or CFM_LINK)>
    CFM_ALL equ <(CFM_EFFECTS or CFM_SIZE or CFM_FACE or CFM_OFFSET or CFM_CHARSET)>
    CFM_EFFECTS2 equ <(CFM_EFFECTS or CFM_DISABLED or CFM_SMALLCAPS or CFM_ALLCAPS or CFM_HIDDEN or CFM_OUTLINE or CFM_SHADOW or CFM_EMBOSS or CFM_IMPRINT or CFM_REVISED or CFM_SUBSCRIPT or CFM_SUPERSCRIPT or CFM_BACKCOLOR)>
    if (_RICHEDIT_VER ge 0600h)
      CFM_ALL2 equ <(CFM_ALL or CFM_EFFECTS2 or CFM_BACKCOLOR or CFM_LCID or CFM_UNDERLINETYPE or CFM_WEIGHT or CFM_REVAUTHOR or CFM_SPACING or CFM_KERNING or CFM_STYLE or CFM_ANIMATION or CFM_COOKIE)>
    else
      CFM_ALL2 equ <(CFM_ALL or CFM_EFFECTS2 or CFM_BACKCOLOR or CFM_LCID or CFM_UNDERLINETYPE or CFM_WEIGHT or CFM_REVAUTHOR or CFM_SPACING or CFM_KERNING or CFM_STYLE or CFM_ANIMATION)>
    endif
    CFE_SMALLCAPS equ <CFM_SMALLCAPS>
    CFE_ALLCAPS equ <CFM_ALLCAPS>
    CFE_HIDDEN equ <CFM_HIDDEN>
    CFE_OUTLINE equ <CFM_OUTLINE>
    CFE_SHADOW equ <CFM_SHADOW>
    CFE_EMBOSS equ <CFM_EMBOSS>
    CFE_IMPRINT equ <CFM_IMPRINT>
    CFE_DISABLED equ <CFM_DISABLED>
    CFE_REVISED equ <CFM_REVISED>
    CFE_AUTOBACKCOLOR equ <CFM_BACKCOLOR>
    CFM_FONTBOUND equ 00100000h
    CFM_LINKPROTECTED equ 00800000h
    CFM_EXTENDED equ 02000000h
    CFM_MATHNOBUILDUP equ 08000000h
    CFM_MATH equ 10000000h
    CFM_MATHORDINARY equ 20000000h
    CFM_ALLEFFECTS equ <(CFM_EFFECTS2 or CFM_FONTBOUND or CFM_EXTENDED or CFM_MATHNOBUILDUP or CFM_MATH or CFM_MATHORDINARY)>
    CFE_FONTBOUND equ 00100000h
    CFE_LINKPROTECTED equ 00800000h
    CFE_EXTENDED equ 02000000h
    CFE_MATHNOBUILDUP equ 08000000h
    CFE_MATH equ 10000000h
    CFE_MATHORDINARY equ 20000000h
    CFU_CF1UNDERLINE equ 0FFh
    CFU_INVERT equ 0FEh
    CFU_UNDERLINETHICKLONGDASH equ 18
    CFU_UNDERLINETHICKDOTTED equ 17
    CFU_UNDERLINETHICKDASHDOTDOT equ 16
    CFU_UNDERLINETHICKDASHDOT equ 15
    CFU_UNDERLINETHICKDASH equ 14
    CFU_UNDERLINELONGDASH equ 13
    CFU_UNDERLINEHEAVYWAVE equ 12
    CFU_UNDERLINEDOUBLEWAVE equ 11
    CFU_UNDERLINEHAIRLINE equ 10
    CFU_UNDERLINETHICK equ 9
    CFU_UNDERLINEWAVE equ 8
    CFU_UNDERLINEDASHDOTDOT equ 7
    CFU_UNDERLINEDASHDOT equ 6
    CFU_UNDERLINEDASH equ 5
    CFU_UNDERLINEDOTTED equ 4
    CFU_UNDERLINEDOUBLE equ 3
    CFU_UNDERLINEWORD equ 2
    CFU_UNDERLINE equ 1
    CFU_UNDERLINENONE equ 0
    yHeightCharPtsMost equ 1638
    SCF_SELECTION equ 0001h
    SCF_WORD equ 0002h
    SCF_DEFAULT equ 0000h
    SCF_ALL equ 0004h
    SCF_USEUIRULES equ 0008h
    SCF_ASSOCIATEFONT equ 0010h
    SCF_NOKBUPDATE equ 0020h
    SCF_ASSOCIATEFONT2 equ 0040h
    if (_RICHEDIT_VER ge 0500h)
      SCF_SMARTFONT equ 0080h
      SCF_CHARREPFROMLCID equ 0100h
      SPF_DONTSETDEFAULT equ 0002h
      SPF_SETDEFAULT equ 0004h
    endif
    CHARRANGE struct
      cpMin LONG ?
      cpMax LONG ?
    CHARRANGE ends
    _charrange typedef CHARRANGE
    TEXTRANGEA struct
      chrg CHARRANGE <>
      lpstrText LPSTR ?
    TEXTRANGEA ends
    _textrange typedef TEXTRANGEA
    TEXTRANGEW struct
      chrg CHARRANGE <>
      lpstrText LPWSTR ?
    TEXTRANGEW ends
    _textrangew typedef TEXTRANGEW
    if (_RICHEDIT_VER ge 0200h)
      ifdef UNICODE
        TEXTRANGE equ <TEXTRANGEW>
      else
        TEXTRANGE equ <TEXTRANGEA>
      endif
    else
      TEXTRANGE equ <TEXTRANGEA>
    endif
    TYPE_EDITSTREAMCALLBACK typedef proto WIN_STD_CALL_CONV :DWORD_PTR, :LPBYTE, :LONG, :ptr LONG
    EDITSTREAMCALLBACK typedef ptr TYPE_EDITSTREAMCALLBACK

    EDITSTREAM struct 4
      dwCookie DWORD_PTR ?
      dwError DWORD ?
      pfnCallback EDITSTREAMCALLBACK ?
    EDITSTREAM ends
    _editstream typedef EDITSTREAM
    SF_TEXT equ 0001h
    SF_RTF equ 0002h
    SF_RTFNOOBJS equ 0003h
    SF_TEXTIZED equ 0004h
    SF_UNICODE equ 0010h
    SF_USECODEPAGE equ 0020h
    SF_NCRFORNONASCII equ 40h
    SFF_WRITEXTRAPAR equ 80h
    SFF_SELECTION equ 8000h
    SFF_PLAINRTF equ 4000h
    SFF_PERSISTVIEWSCALE equ 2000h
    SFF_KEEPDOCINFO equ 1000h
    SFF_PWD equ 0800h
    SF_RTFVAL equ 0700h
    FINDTEXTA struct
      chrg CHARRANGE <>
      lpstrText LPCSTR ?
    FINDTEXTA ends
    _findtext typedef FINDTEXTA
    FINDTEXTW struct
      chrg CHARRANGE <>
      lpstrText LPCWSTR ?
    FINDTEXTW ends
    _findtextw typedef FINDTEXTW
    if (_RICHEDIT_VER ge 0200h)
      ifdef UNICODE
        FINDTEXT equ <FINDTEXTW>
      else
        FINDTEXT equ <FINDTEXTA>
      endif
    else
      FINDTEXT equ <FINDTEXTA>
    endif
    FINDTEXTEXA struct
      chrg CHARRANGE <>
      lpstrText LPCSTR ?
      chrgText CHARRANGE <>
    FINDTEXTEXA ends
    _findtextexa typedef FINDTEXTEXA
    FINDTEXTEXW struct
      chrg CHARRANGE <>
      lpstrText LPCWSTR ?
      chrgText CHARRANGE <>
    FINDTEXTEXW ends
    _findtextexw typedef FINDTEXTEXW
    if (_RICHEDIT_VER ge 0200h)
      ifdef UNICODE
        FINDTEXTEX equ <FINDTEXTEXW>
      else
        FINDTEXTEX equ <FINDTEXTEXA>
      endif
    else
      FINDTEXTEX equ <FINDTEXTEXA>
    endif
    FORMATRANGE struct
      hdc HDC ?
      hdcTarget HDC ?
      rc RECT <>
      rcPage RECT <>
      chrg CHARRANGE <>
    FORMATRANGE ends
    _formatrange typedef FORMATRANGE
    MAX_TAB_STOPS equ 32
    lDefaultTab equ 720
    MAX_TABLE_CELLS equ 63
    PARAFORMAT struct
      cbSize UINT ?
      dwMask DWORD ?
      wNumbering WORD ?
      union
        wReserved WORD ?
        wEffects WORD ?
      ends
      dxStartIndent LONG ?
      dxRightIndent LONG ?
      dxOffset LONG ?
      wAlignment WORD ?
      cTabCount SHORT_ ?
      rgxTabs LONG MAX_TAB_STOPS dup (?)
    PARAFORMAT ends
    _paraformat typedef PARAFORMAT
    ifdef __cplusplus
      ;[...]
    else
      PARAFORMAT2 struct
        cbSize UINT ?
        dwMask DWORD ?
        wNumbering WORD ?
        union
          wReserved WORD ?
          wEffects WORD ?
        ends
        dxStartIndent LONG ?
        dxRightIndent LONG ?
        dxOffset LONG ?
        wAlignment WORD ?
        cTabCount SHORT_ ?
        rgxTabs LONG MAX_TAB_STOPS dup (?)
        dySpaceBefore LONG ?
        dySpaceAfter LONG ?
        dyLineSpacing LONG ?
        sStyle SHORT_ ?
        bLineSpacingRule BYTE ?
        bOutlineLevel BYTE ?
        wShadingWeight WORD ?
        wShadingStyle WORD ?
        wNumberingStart WORD ?
        wNumberingStyle WORD ?
        wNumberingTab WORD ?
        wBorderSpace WORD ?
        wBorderWidth WORD ?
        wBorders WORD ?
      PARAFORMAT2 ends
      _paraformat2 typedef PARAFORMAT2
    endif
    PFM_STARTINDENT equ 00000001h
    PFM_RIGHTINDENT equ 00000002h
    PFM_OFFSET equ 00000004h
    PFM_ALIGNMENT equ 00000008h
    PFM_TABSTOPS equ 00000010h
    PFM_NUMBERING equ 00000020h
    PFM_OFFSETINDENT equ 80000000h
    PFM_SPACEBEFORE equ 00000040h
    PFM_SPACEAFTER equ 00000080h
    PFM_LINESPACING equ 00000100h
    PFM_STYLE equ 00000400h
    PFM_BORDER equ 00000800h
    PFM_SHADING equ 00001000h
    PFM_NUMBERINGSTYLE equ 00002000h
    PFM_NUMBERINGTAB equ 00004000h
    PFM_NUMBERINGSTART equ 00008000h
    PFM_RTLPARA equ 00010000h
    PFM_KEEP equ 00020000h
    PFM_KEEPNEXT equ 00040000h
    PFM_PAGEBREAKBEFORE equ 00080000h
    PFM_NOLINENUMBER equ 00100000h
    PFM_NOWIDOWCONTROL equ 00200000h
    PFM_DONOTHYPHEN equ 00400000h
    PFM_SIDEBYSIDE equ 00800000h
    PFM_COLLAPSED equ 01000000h
    PFM_OUTLINELEVEL equ 02000000h
    PFM_BOX equ 04000000h
    PFM_RESERVED2 equ 08000000h
    PFM_TABLEROWDELIMITER equ 10000000h
    PFM_TEXTWRAPPINGBREAK equ 20000000h
    PFM_TABLE equ 40000000h
    PFM_ALL equ <(PFM_STARTINDENT or PFM_RIGHTINDENT or PFM_OFFSET or PFM_ALIGNMENT or PFM_TABSTOPS or PFM_NUMBERING or PFM_OFFSETINDENT or PFM_RTLPARA)>
    PFM_EFFECTS equ <(PFM_RTLPARA or PFM_KEEP or PFM_KEEPNEXT or PFM_TABLE or PFM_PAGEBREAKBEFORE or PFM_NOLINENUMBER or PFM_NOWIDOWCONTROL or PFM_DONOTHYPHEN or PFM_SIDEBYSIDE or PFM_TABLE or PFM_TABLEROWDELIMITER)>
    PFM_ALL2 equ <(PFM_ALL or PFM_EFFECTS or PFM_SPACEBEFORE or PFM_SPACEAFTER or PFM_LINESPACING or PFM_STYLE or PFM_SHADING or PFM_BORDER or PFM_NUMBERINGTAB or PFM_NUMBERINGSTART or PFM_NUMBERINGSTYLE)>
    PFE_RTLPARA equ (PFM_RTLPARA shr 16)
    PFE_KEEP equ (PFM_KEEP shr 16)
    PFE_KEEPNEXT equ (PFM_KEEPNEXT shr 16)
    PFE_PAGEBREAKBEFORE equ (PFM_PAGEBREAKBEFORE shr 16)
    PFE_NOLINENUMBER equ (PFM_NOLINENUMBER shr 16)
    PFE_NOWIDOWCONTROL equ (PFM_NOWIDOWCONTROL shr 16)
    PFE_DONOTHYPHEN equ (PFM_DONOTHYPHEN shr 16)
    PFE_SIDEBYSIDE equ (PFM_SIDEBYSIDE shr 16)
    PFE_TEXTWRAPPINGBREAK equ (PFM_TEXTWRAPPINGBREAK shr 16)
    PFE_COLLAPSED equ (PFM_COLLAPSED shr 16)
    PFE_BOX equ (PFM_BOX shr 16)
    PFE_TABLE equ (PFM_TABLE shr 16)
    PFE_TABLEROWDELIMITER equ (PFM_TABLEROWDELIMITER shr 16)
    PFN_BULLET equ 1
    PFN_ARABIC equ 2
    PFN_LCLETTER equ 3
    PFN_UCLETTER equ 4
    PFN_LCROMAN equ 5
    PFN_UCROMAN equ 6
    PFNS_PAREN equ 000h
    PFNS_PARENS equ 100h
    PFNS_PERIOD equ 200h
    PFNS_PLAIN equ 300h
    PFNS_NONUMBER equ 400h
    PFNS_NEWNUMBER equ 8000h
    PFA_LEFT equ 1
    PFA_RIGHT equ 2
    PFA_CENTER equ 3
    PFA_JUSTIFY equ 4
    PFA_FULL_INTERWORD equ 4
    ifndef WM_NOTIFY
      WM_NOTIFY equ 004Eh
      NMHDR struct
        hwndFrom HWND ?
        idFrom UINT ?
        code UINT ?
      NMHDR ends
      _nmhdr typedef NMHDR
    endif
    MSGFILTER struct
      nmhdr NMHDR <>
      msg UINT ?
      wParam WPARAM ?
      lParam LPARAM ?
    MSGFILTER ends
    _msgfilter typedef MSGFILTER
    REQRESIZE struct
      nmhdr NMHDR <>
      rc RECT <>
    REQRESIZE ends
    _reqresize typedef REQRESIZE
    SELCHANGE struct
      nmhdr NMHDR <>
      chrg CHARRANGE <>
      seltyp WORD ?
    SELCHANGE ends
    _selchange typedef SELCHANGE
    if (_RICHEDIT_VER ge 0800h)
      GROUPTYPINGCHANGE struct
        nmhdr NMHDR <>
        fGroupTyping BOOL ?
      GROUPTYPINGCHANGE ends
      _grouptypingchange typedef GROUPTYPINGCHANGE
    endif
    CLIPBOARDFORMAT struct
      nmhdr NMHDR <>
      cf CLIPFORMAT ?
    CLIPBOARDFORMAT ends
    _clipboardformat typedef CLIPBOARDFORMAT
    SEL_EMPTY equ 0000h
    SEL_TEXT equ 0001h
    SEL_OBJECT equ 0002h
    SEL_MULTICHAR equ 0004h
    SEL_MULTIOBJECT equ 0008h
    GCM_RIGHTMOUSEDROP equ 8000h
    if (_RICHEDIT_VER ge 0800h)
      GETCONTEXTMENUEX struct
        chrg CHARRANGE <>
        dwFlags DWORD ?
        pt POINT <>
        pvReserved POINTER ?
      GETCONTEXTMENUEX ends
      _getcontextmenuex typedef GETCONTEXTMENUEX
      GCMF_GRIPPER equ 00000001h
      GCMF_SPELLING equ 00000002h
      GCMF_TOUCHMENU equ 00004000h
      GCMF_MOUSEMENU equ 00002000h
    endif
    ENDROPFILES struct
      nmhdr NMHDR <>
      hDrop HANDLE ?
      cp LONG ?
      fProtected BOOL ?
    ENDROPFILES ends
    _endropfiles typedef ENDROPFILES
    ENPROTECTED struct
      nmhdr NMHDR <>
      msg UINT ?
      wParam WPARAM ?
      lParam LPARAM ?
      chrg CHARRANGE <>
    ENPROTECTED ends
    _enprotected typedef ENPROTECTED
    ENSAVECLIPBOARD struct
      nmhdr NMHDR <>
      cObjectCount LONG ?
      cch LONG ?
    ENSAVECLIPBOARD ends
    _ensaveclipboard typedef ENSAVECLIPBOARD
    ifndef MACPORT
      ENOLEOPFAILED struct
        nmhdr NMHDR <>
        iob LONG ?
        lOper LONG ?
        hr HRESULT ?
      ENOLEOPFAILED ends
      _enoleopfailed typedef ENOLEOPFAILED
    endif
    OLEOP_DOVERB equ 1
    OBJECTPOSITIONS struct
      nmhdr NMHDR <>
      cObjectCount LONG ?
      pcpPositions POINTER ?
    OBJECTPOSITIONS ends
    _objectpositions typedef OBJECTPOSITIONS
    ENLINK struct
      nmhdr NMHDR <>
      msg UINT ?
      wParam WPARAM ?
      lParam LPARAM ?
      chrg CHARRANGE <>
    ENLINK ends
    _enlink typedef ENLINK
    ENLOWFIRTF struct
      nmhdr NMHDR <>
      szControl POINTER ?
    ENLOWFIRTF ends
    _enlowfirtf typedef ENLOWFIRTF
    ENCORRECTTEXT struct
      nmhdr NMHDR <>
      chrg CHARRANGE <>
      seltyp WORD ?
    ENCORRECTTEXT ends
    _encorrecttext typedef ENCORRECTTEXT
    PUNCTUATION struct
      iSize UINT ?
      szPunctuation LPSTR ?
    PUNCTUATION ends
    _punctuation typedef PUNCTUATION
    COMPCOLOR struct
      crText COLORREF ?
      crBackground COLORREF ?
      dwEffects DWORD ?
    COMPCOLOR ends
    _compcolor typedef COMPCOLOR
    CF_RTF equ <TEXT("Rich Text Format")>
    CF_RTFNOOBJS equ <TEXT("Rich Text Format Without Objects")>
    CF_RETEXTOBJ equ <TEXT("RichEdit Text and Objects")>
    REPASTESPECIAL struct
      dwAspect DWORD ?
      dwParam DWORD_PTR ?
    REPASTESPECIAL ends
    _repastespecial typedef REPASTESPECIAL
    UNDONAMEID typedef SDWORD
    UID_UNKNOWN equ 0
    UID_TYPING equ 1
    UID_DELETE equ 2
    UID_DRAGDROP equ 3
    UID_CUT equ 4
    UID_PASTE equ 5
    UID_AUTOTABLE equ 6
    _undonameid typedef UNDONAMEID

    ST_DEFAULT equ 0
    ST_KEEPUNDO equ 1
    ST_SELECTION equ 2
    ST_NEWCHARS equ 4
    if (_RICHEDIT_VER ge 0500h)
      ST_UNICODE equ 8
    endif
    SETTEXTEX struct
      flags DWORD ?
      codepage UINT ?
    SETTEXTEX ends
    _settextex typedef SETTEXTEX
    GT_DEFAULT equ 0
    GT_USECRLF equ 1
    GT_SELECTION equ 2
    GT_RAWTEXT equ 4
    GT_NOHIDDENTEXT equ 8
    GETTEXTEX struct
      cb DWORD ?
      flags DWORD ?
      codepage UINT ?
      lpDefaultChar LPCSTR ?
      lpUsedDefChar LPBOOL ?
    GETTEXTEX ends
    _gettextex typedef GETTEXTEX
    GTL_DEFAULT equ 0
    GTL_USECRLF equ 1
    GTL_PRECISE equ 2
    GTL_CLOSE equ 4
    GTL_NUMCHARS equ 8
    GTL_NUMBYTES equ 16
    GETTEXTLENGTHEX struct
      flags DWORD ?
      codepage UINT ?
    GETTEXTLENGTHEX ends
    _gettextlengthex typedef GETTEXTLENGTHEX
    BIDIOPTIONS struct
      cbSize UINT ?
      wMask WORD ?
      wEffects WORD ?
    BIDIOPTIONS ends
    _bidioptions typedef BIDIOPTIONS
    if (_RICHEDIT_VER eq 0100h)
      BOM_DEFPARADIR equ 0001h
      BOM_PLAINTEXT equ 0002h
    endif
    BOM_NEUTRALOVERRIDE equ 0004h
    BOM_CONTEXTREADING equ 0008h
    BOM_CONTEXTALIGNMENT equ 0010h
    BOM_LEGACYBIDICLASS equ 0040h
    if (_RICHEDIT_VER ge 0600h)
      BOM_UNICODEBIDI equ 0080h
    endif
    if (_RICHEDIT_VER eq 0100h)
      BOE_RTLDIR equ 0001h
      BOE_PLAINTEXT equ 0002h
    endif
    BOE_NEUTRALOVERRIDE equ 0004h
    BOE_CONTEXTREADING equ 0008h
    BOE_CONTEXTALIGNMENT equ 0010h
    if (_RICHEDIT_VER ge 0800h)
      BOE_FORCERECALC equ 0020h
    endif
    BOE_LEGACYBIDICLASS equ 0040h
    if (_RICHEDIT_VER ge 0600h)
      BOE_UNICODEBIDI equ 0080h
    endif
    FR_MATCHDIAC equ 20000000h
    FR_MATCHKASHIDA equ 40000000h
    FR_MATCHALEFHAMZA equ 80000000h
    ifndef WCH_EMBEDDING
      WCH_EMBEDDING equ 0FFFCh
    endif
    KHYPH typedef SDWORD
    khyphNil equ 0
    khyphNormal equ 1
    khyphAddBefore equ 2
    khyphChangeBefore equ 3
    khyphDeleteBefore equ 4
    khyphChangeAfter equ 5
    khyphDelAndChange equ 6
    tagKHYPH typedef KHYPH

    HYPHRESULT struct
      khyph KHYPH ?
      ichHyph SDWORD ?
      chHyph WCHAR ?
    HYPHRESULT ends
    hyphresult typedef HYPHRESULT
    HyphenateProc proto WIN_STD_CALL_CONV :ptr WCHAR, :LANGID, :SDWORD, :ptr HYPHRESULT
    HYPHENATEINFO struct
      cbSize SHORT_ ?
      dxHyphenateZone SHORT_ ?
      TYPE_pfnHyphenate typedef proto WIN_STD_CALL_CONV :ptr WCHAR, :LANGID, :SDWORD, :ptr HYPHRESULT
      pfnHyphenate typedef ptr TYPE_pfnHyphenate

    HYPHENATEINFO ends
    tagHyphenateInfo typedef HYPHENATEINFO
    ifdef _WIN32
      include poppack.inc
    elseif  not Defined(RC_INVOKED)
    endif
    if (_RICHEDIT_VER ge 0600h)
      ifndef RICHEDIT60_CLASS
        RICHEDIT60_CLASS equ <L("RICHEDIT60W")>
      endif
    endif
    PFA_FULL_NEWSPAPER equ 5
    PFA_FULL_INTERLETTER equ 6
    PFA_FULL_SCALED equ 7
    PFA_FULL_GLYPHS equ 8
    AURL_ENABLEEA equ 1
    GCM_TOUCHMENU equ 4000h
    GCM_MOUSEMENU equ 2000h
    ifdef __cplusplus
      ;[...]
    endif
  endif
endif
