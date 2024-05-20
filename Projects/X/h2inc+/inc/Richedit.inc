;Include file created by h2inc+ version C.2.0 on (UTC) 20/05/2024 18:06:34
;(C) G. Friedrich April 2024
;Source file: d:\objasm\projects\x\h2inc+\h\um_10.0.22621.0\richedit.h
;             Created on (UTC) 06/04/2024 06:15:57
;             Last modified on (UTC) 16/12/2023 11:07:52

;*
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
    ; __cplusplus
    ; To mimic older RichEdit behavior, set _RICHEDIT_VER to appropriate value
    ;		Version 1.0 	0x0100	
    ;		Version 2.0 	0x0200	
    ;		Version 2.1 	0x0210	
    ifndef _RICHEDIT_VER
      _RICHEDIT_VER equ 0810h
    endif
    cchTextLimitDefault equ 32767
    MSFTEDIT_CLASS equ <L("RICHEDIT50W")>
    ; NOTE:  MSFTEDIT.DLL only registers MSFTEDIT_CLASS.  If an application wants
    ; to use the following RichEdit classes, it needs to load riched20.dll.
    ; Otherwise, CreateWindow with RICHEDIT_CLASS will fail.
    ; This also applies to any dialog that uses RICHEDIT_CLASS
    ; RichEdit 2.0 Window Class
    ; On Windows CE, avoid possible conflicts on Win95
    CERICHEDIT_CLASSA equ <"RichEditCEA">
    CERICHEDIT_CLASSW equ <L("RichEditCEW")>
    RICHEDIT_CLASSA equ <"RichEdit20A">
    RICHEDIT_CLASS10A equ <"RICHEDIT">; Richedit 1.0

    ifndef MACPORT
      RICHEDIT_CLASSW equ <L("RichEdit20W")>
    else
    ;----------------------MACPORT 
      RICHEDIT_CLASSW equ <TEXT("RichEdit20W")>; MACPORT change 

    endif
    ; MACPORT  
    if (_RICHEDIT_VER ge 0200h)
      ifdef UNICODE
        RICHEDIT_CLASS equ <RICHEDIT_CLASSW>
      else
        RICHEDIT_CLASS equ <RICHEDIT_CLASSA>
      endif
      ; UNICODE 
    else
      RICHEDIT_CLASS equ <RICHEDIT_CLASS10A>
    endif
    ; _RICHEDIT_VER >= 0x0200 
    ; RichEdit messages 
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
    ; RichEdit 2.0 messages 
    EM_SETUNDOLIMIT equ (WM_USER + 82)
    EM_REDO equ (WM_USER + 84)
    EM_CANREDO equ (WM_USER + 85)
    EM_GETUNDONAME equ (WM_USER + 86)
    EM_GETREDONAME equ (WM_USER + 87)
    EM_STOPGROUPTYPING equ (WM_USER + 88)
    EM_SETTEXTMODE equ (WM_USER + 89)
    EM_GETTEXTMODE equ (WM_USER + 90)
    ; enum for use with EM_GET/SETTEXTMODE 
    TEXTMODE typedef SDWORD
    TM_PLAINTEXT equ 1
    TM_RICHTEXT equ 2
    ; Default behavior 
    TM_SINGLELEVELUNDO equ 4
    TM_MULTILEVELUNDO equ 8
    ; Default behavior 
    TM_SINGLECODEPAGE equ 16
    TM_MULTICODEPAGE equ 32
    tagTextMode typedef TEXTMODE

    ; Default behavior 
    EM_AUTOURLDETECT equ (WM_USER + 91)
    if (_RICHEDIT_VER ge 0800h)
      AURL_ENABLEURL equ 1
      AURL_ENABLEEMAILADDR equ 2
      AURL_ENABLETELNO equ 4
      AURL_ENABLEEAURLS equ 8
      AURL_ENABLEDRIVELETTERS equ 16
      AURL_DISABLEMIXEDLGC equ 32; Disable mixed Latin Greek Cyrillic IDNs

    endif
    EM_GETAUTOURLDETECT equ (WM_USER + 92)
    EM_SETPALETTE equ (WM_USER + 93)
    EM_GETTEXTEX equ (WM_USER + 94)
    EM_GETTEXTLENGTHEX equ (WM_USER + 95)
    EM_SHOWSCROLLBAR equ (WM_USER + 96)
    EM_SETTEXTEX equ (WM_USER + 97)
    ; East Asia specific messages 
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
    ; RE3.0 FE messages 
    EM_RECONVERSION equ (WM_USER + 125)
    EM_SETIMEMODEBIAS equ (WM_USER + 126)
    EM_GETIMEMODEBIAS equ (WM_USER + 127)
    ; BiDi specific messages 
    EM_SETBIDIOPTIONS equ (WM_USER + 200)
    EM_GETBIDIOPTIONS equ (WM_USER + 201)
    EM_SETTYPOGRAPHYOPTIONS equ (WM_USER + 202)
    EM_GETTYPOGRAPHYOPTIONS equ (WM_USER + 203)
    ; Extended edit style specific messages 
    EM_SETEDITSTYLE equ (WM_USER + 204)
    EM_GETEDITSTYLE equ (WM_USER + 205)
    ; Extended edit style masks 
    SES_EMULATESYSEDIT equ 1
    SES_BEEPONMAXTEXT equ 2
    SES_EXTENDBACKCOLOR equ 4
    SES_MAPCPS equ 8; Obsolete (never used)

    if (_RICHEDIT_VER ge 0500h)
      SES_HYPERLINKTOOLTIPS equ 8
    endif
    SES_EMULATE10 equ 16; Obsolete (never used)

    if (_RICHEDIT_VER ge 0700h)
      SES_DEFAULTLATINLIGA equ 16
    endif
    SES_USECRLF equ 32; Obsolete (never used)

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
    ; Options for EM_SETLANGOPTIONS and EM_GETLANGOPTIONS 
    IMF_AUTOKEYBOARD equ 0001h
    IMF_AUTOFONT equ 0002h
    IMF_IMECANCELCOMPLETE equ 0004h; High completes comp string when aborting, low cancels

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
    ; Values for EM_GETIMECOMPMODE 
    ICM_NOTOPEN equ 0000h
    ICM_LEVEL3 equ 0001h
    ICM_LEVEL2 equ 0002h
    ICM_LEVEL2_5 equ 0003h
    ICM_LEVEL2_SUI equ 0004h
    ICM_CTF equ 0005h
    ; Options for EM_SETTYPOGRAPHYOPTIONS 
    TO_ADVANCEDTYPOGRAPHY equ 0001h
    TO_SIMPLELINEBREAK equ 0002h
    TO_DISABLECUSTOMTEXTOUT equ 0004h
    TO_ADVANCEDLAYOUT equ 0008h
    ; Pegasus outline mode messages (RE 3.0) 
    ; Outline mode message
    EM_OUTLINE equ (WM_USER + 220)
    ; Message for getting and restoring scroll pos
    EM_GETSCROLLPOS equ (WM_USER + 221)
    EM_SETSCROLLPOS equ (WM_USER + 222)
    ; Change fontsize in current selection by wParam
    EM_SETFONTSIZE equ (WM_USER + 223)
    EM_GETZOOM equ (WM_USER + 224)
    EM_SETZOOM equ (WM_USER + 225)
    EM_GETVIEWKIND equ (WM_USER + 226)
    EM_SETVIEWKIND equ (WM_USER + 227)
    ; RichEdit 4.0 messages
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
    ; These messages control what rich edit does when it comes accross
    ; OLE objects during RTF stream in.  Normally rich edit queries the client
    ; application only after OleLoad has been called.  With these messages it is possible to
    ; set the rich edit control to a mode where it will query the client application before
    ; OleLoad is called
    EM_GETQUERYRTFOBJ equ (WM_USER + 269)
    EM_SETQUERYRTFOBJ equ (WM_USER + 270)
    EM_SETQUERYCONVERTOLELINKCALLBACK equ (WM_USER + 403)
    EM_SETDISABLEOLELINKCONVERSION equ (WM_USER + 404)
    ; EM_SETPAGEROTATE wparam values
    EPR_0 equ 0; Text flows left to right and top to bottom

    EPR_270 equ 1; Text flows top to bottom and right to left

    EPR_180 equ 2; Text flows right to left and bottom to top

    EPR_90 equ 3; Text flows bottom to top and left to right

    if (_RICHEDIT_VER ge 0800h)
      EPR_SE equ 5; Text flows top to bottom and left to right (Mongolian text layout)

    endif
    ; EM_SETCTFMODEBIAS wparam values
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
    ; EM_SETIMEMODEBIAS lparam values
    IMF_SMODE_PLAURALCLAUSE equ 0001h
    IMF_SMODE_NONE equ 0002h
    ; EM_GETIMECOMPTEXT wparam structure
    IMECOMPTEXT struct
      cb SDWORD ?
      ; count of bytes in the output buffer.
      flags DWORD ?
      ; value specifying the composition string type.
      ;	Currently only support ICT_RESULTREADSTR
    IMECOMPTEXT ends
    _imecomptext typedef IMECOMPTEXT
    ICT_RESULTREADSTR equ 1
    ; Outline mode wparam values
    EMO_EXIT equ 0; Enter normal mode,  lparam ignored

    EMO_ENTER equ 1; Enter outline mode, lparam ignored

    EMO_PROMOTE equ 2; LOWORD(lparam) == 0 ==>

    ;	promote  to body-text
    ; LOWORD(lparam) != 0 ==>
    ;	promote/demote current selection
    ;	by indicated number of levels
    EMO_EXPAND equ 3; HIWORD(lparam) = EMO_EXPANDSELECTION

    ;	-> expands selection to level
    ;	indicated in LOWORD(lparam)
    ;	LOWORD(lparam) = -1/+1 corresponds
    ;	to collapse/expand button presses
    ;	in winword (other values are
    ;	equivalent to having pressed these
    ;	buttons more than once)
    ;	HIWORD(lparam) = EMO_EXPANDDOCUMENT
    ;	-> expands whole document to
    ;	indicated level
    EMO_MOVESELECTION equ 4; LOWORD(lparam) != 0 -> move current

    ;	selection up/down by indicated amount
    EMO_GETVIEWMODE equ 5; Returns VM_NORMAL or VM_OUTLINE

    ; EMO_EXPAND options
    EMO_EXPANDSELECTION equ 0
    EMO_EXPANDDOCUMENT equ 1
    VM_NORMAL equ 4; Agrees with RTF \viewkindN

    VM_OUTLINE equ 2
    VM_PAGE equ 9; Screen page view (not print layout)

    ;/ New messages as of Win8
    if (_RICHEDIT_VER ge 0800h)
      EM_INSERTTABLE equ (WM_USER + 232)
      ; Microsoft extension -- Bitfield not int
      ; Data type defining table rows for EM_INSERTTABLE
      TABLEROWPARMS struct
        ; EM_INSERTTABLE wparam is a (TABLEROWPARMS *)
        cbRow BYTE ?
        ; Count of bytes in this structure
        cbCell BYTE ?
        ; Count of bytes in TABLECELLPARMS
        cCell BYTE ?
        ; Count of cells
        cRow BYTE ?
        ; Count of rows
        dxCellMargin SDWORD ?
        ; Cell left/right margin (\trgaph)
        dxIndent SDWORD ?
        ; Row left (right if fRTL indent (similar to \trleft)
        dyHeight SDWORD ?
        ; Row height (\trrh)
        ; Row alignment (like PARAFORMAT::bAlignment, \trql, trqr, \trqc)
        ; Display cells in RTL order (\rtlrow)
        ; Keep row together (\trkeep}
        ; Keep row on same page as following row (\trkeepfollow)
        ; Wrap text to right/left (depending on bAlignment)
        ; (see \tdfrmtxtLeftN, \tdfrmtxtRightN)
        ; lparam points at single struct valid for all cells
        TABLEROWPARMS_REC record TABLEROWPARMS_REC_Filler:24, TABLEROWPARMS_REC_fIdentCells:1, TABLEROWPARMS_REC_fWrap:1, TABLEROWPARMS_REC_fKeepFollow:1, TABLEROWPARMS_REC_fKeep:1, TABLEROWPARMS_REC_fRTL:1, TABLEROWPARMS_REC_nAlignment:3
        TABLEROWPARMS_BITS TABLEROWPARMS_REC <>
        ; lparam points at single struct valid for all cells
        cpStartRow SDWORD ?
        ; cp where to insert table (-1 for selection cp)
        ;	(can be used for either TRD by EM_GETTABLEPARMS)
        bTableLevel BYTE ?
        ; Table nesting level (EM_GETTABLEPARMS only)
        iCell BYTE ?
        ; Index of cell to insert/delete (EM_SETTABLEPARMS only)
      TABLEROWPARMS ends
      _tableRowParms typedef TABLEROWPARMS
      ; Data type defining table cells for EM_INSERTTABLE
      TABLECELLPARMS struct
        ; EM_INSERTTABLE lparam is a (TABLECELLPARMS *)
        dxWidth SDWORD ?
        ; Cell width (\cellx)
        ; Vertical alignment (0/1/2 = top/center/bottom
        ;	\clvertalt (def), \clvertalc, \clvertalb)
        ; Top cell for vertical merge (\clvmgf)
        ; Merge with cell above (\clvmrg)
        ; Display text top to bottom, right to left (\cltxtbrlv)
        ; Start set of horizontally merged cells (\clmgf)
        ; Merge with previous cell (\clmrg)
        TABLECELLPARMS_REC record TABLECELLPARMS_REC_Filler:9, TABLECELLPARMS_REC_fMergeCont:1, TABLECELLPARMS_REC_fMergeStart:1, TABLECELLPARMS_REC_fVertical:1, TABLECELLPARMS_REC_fMergePrev:1, TABLECELLPARMS_REC_fMergeTop:1, TABLECELLPARMS_REC_nVertAlign:2
        TABLECELLPARMS_BITS TABLECELLPARMS_REC <>
        ; Merge with previous cell (\clmrg)
        wShading WORD ?
        ; Shading in .01%		(\clshdng) e.g., 10000 flips fore/back
        dxBrdrLeft SWORD ?
        ; Left border width	(\clbrdrl\brdrwN) (in twips)
        dyBrdrTop SWORD ?
        ; Top border width 	(\clbrdrt\brdrwN)
        dxBrdrRight SWORD ?
        ; Right border width	(\clbrdrr\brdrwN)
        dyBrdrBottom SWORD ?
        ; Bottom border width	(\clbrdrb\brdrwN)
        crBrdrLeft COLORREF ?
        ; Left border color	(\clbrdrl\brdrcf)
        crBrdrTop COLORREF ?
        ; Top border color 	(\clbrdrt\brdrcf)
        crBrdrRight COLORREF ?
        ; Right border color	(\clbrdrr\brdrcf)
        crBrdrBottom COLORREF ?
        ; Bottom border color	(\clbrdrb\brdrcf)
        crBackPat COLORREF ?
        ; Background color 	(\clcbpat)
        crForePat COLORREF ?
        ; Foreground color 	(\clcfpat)
      TABLECELLPARMS ends
      _tableCellParms typedef TABLECELLPARMS
      EM_GETAUTOCORRECTPROC equ (WM_USER + 233)
      EM_SETAUTOCORRECTPROC equ (WM_USER + 234)
      EM_CALLAUTOCORRECTPROC equ (WM_USER + 255)
      ; AutoCorrect callback
      TYPE_AutoCorrectProc typedef proto WIN_STD_CALL_CONV :LANGID, :ptr WCHAR, :ptr WCHAR, :LONG, :ptr LONG
      AutoCorrectProc typedef ptr TYPE_AutoCorrectProc

      ATP_NOCHANGE equ 0
      ATP_CHANGE equ 1
      ATP_NODELIMITER equ 2
      ATP_REPLACEALLTEXT equ 4
      EM_GETTABLEPARMS equ (WM_USER + 265)
      EM_SETEDITSTYLEEX equ (WM_USER + 275)
      EM_GETEDITSTYLEEX equ (WM_USER + 276)
      ; wparam values for EM_SETEDITSTYLEEX/EM_GETEDITSTYLEEX
      ; All unused bits are reserved.
      SES_EX_NOTABLE equ 00000004h
      SES_EX_NOMATH equ 00000040h
      SES_EX_HANDLEFRIENDLYURL equ 00000100h
      SES_EX_NOTHEMING equ 00080000h
      SES_EX_NOACETATESELECTION equ 00100000h
      SES_EX_USESINGLELINE equ 00200000h
      SES_EX_MULTITOUCH equ 08000000h; Only works under Win8+

      SES_EX_HIDETEMPFORMAT equ 10000000h
      SES_EX_USEMOUSEWPARAM equ 20000000h; Use wParam when handling WM_MOUSEMOVE message and do not call GetAsyncKeyState

      EM_GETSTORYTYPE equ (WM_USER + 290)
      EM_SETSTORYTYPE equ (WM_USER + 291)
      EM_GETELLIPSISMODE equ (WM_USER + 305)
      EM_SETELLIPSISMODE equ (WM_USER + 306)
      ; DWORD: *lparam for EM_GETELLIPSISMODE, lparam for EM_SETELLIPSISMODE
      ELLIPSIS_MASK equ 00000003h; all meaningful bits

      ELLIPSIS_NONE equ 00000000h; ellipsis disabled

      ELLIPSIS_END equ 00000001h; ellipsis at the end (forced break)

      ELLIPSIS_WORD equ 00000003h; ellipsis at the end (word break)

      EM_SETTABLEPARMS equ (WM_USER + 307)
      EM_GETTOUCHOPTIONS equ (WM_USER + 310)
      EM_SETTOUCHOPTIONS equ (WM_USER + 311)
      EM_INSERTIMAGE equ (WM_USER + 314)
      EM_SETUIANAME equ (WM_USER + 320)
      EM_GETELLIPSISSTATE equ (WM_USER + 322)
      ; Values for EM_SETTOUCHOPTIONS/EM_GETTOUCHOPTIONS
      RTO_SHOWHANDLES equ 1
      RTO_DISABLEHANDLES equ 2
      RTO_READINGMODE equ 3
      ; lparam for EM_INSERTIMAGE
      RICHEDIT_IMAGE_PARAMETERS struct
        xWidth SDWORD ?
        ; Units are HIMETRIC
        yHeight SDWORD ?
        ; Units are HIMETRIC
        Ascent SDWORD ?
        ; Units are HIMETRIC
        Type_ SDWORD ?
        ; Valid values are TA_TOP, TA_BOTTOM and TA_BASELINE
        pwszAlternateText =POINTER ?
        pIStream POINTER ?
      RICHEDIT_IMAGE_PARAMETERS ends
      tagRICHEDIT_IMAGE_PARAMETERS typedef RICHEDIT_IMAGE_PARAMETERS
    endif
    ; New notifications 
    EN_MSGFILTER equ 0700h
    EN_REQUESTRESIZE equ 0701h
    EN_SELCHANGE equ 0702h
    EN_DROPFILES equ 0703h
    EN_PROTECTED equ 0704h
    EN_CORRECTTEXT equ 0705h; PenWin specific 

    EN_STOPNOUNDO equ 0706h
    EN_IMECHANGE equ 0707h; East Asia specific 

    EN_SAVECLIPBOARD equ 0708h
    EN_OLEOPFAILED equ 0709h
    EN_OBJECTPOSITIONS equ 070ah
    EN_LINK equ 070bh
    EN_DRAGDROPDONE equ 070ch
    EN_PARAGRAPHEXPANDED equ 070dh
    EN_PAGECHANGE equ 070eh
    EN_LOWFIRTF equ 070fh
    EN_ALIGNLTR equ 0710h; BiDi specific notification

    EN_ALIGNRTL equ 0711h; BiDi specific notification

    if (_RICHEDIT_VER ge 0800h)
      EN_CLIPFORMAT equ 0712h
      EN_STARTCOMPOSITION equ 0713h
      EN_ENDCOMPOSITION equ 0714h
      ; Notification structure for EN_ENDCOMPOSITION
      ENDCOMPOSITIONNOTIFY struct
        nmhdr NMHDR <>
        dwCode DWORD ?
      ENDCOMPOSITIONNOTIFY ends
      _endcomposition typedef ENDCOMPOSITIONNOTIFY
      ; Constants for ENDCOMPOSITIONNOTIFY dwCode
      ECN_ENDCOMPOSITION equ 0001h
      ECN_NEWTEXT equ 0002h
    endif
    ; Event notification masks 
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
    ENM_CORRECTTEXT equ 00400000h; PenWin specific 

    ENM_IMECHANGE equ 00800000h; Used by RE1.0 compatibility

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
    ; New edit control styles 
    ES_SAVESEL equ 00008000h
    ES_SUNKEN equ 00004000h
    ES_DISABLENOSCROLL equ 00002000h
    ; Same as WS_MAXIMIZE, but that doesn't make sense so we re-use the value 
    ES_SELECTIONBAR equ 01000000h
    ; Same as ES_UPPERCASE, but re-used to completely disable OLE drag'n'drop 
    ES_NOOLEDRAGDROP equ 00000008h
    ; Obsolete Edit Style
    ES_EX_NOCALLOLEINIT equ 00000000h; Not supported in RE 2.0/3.0 

    ; These flags are used in FE Windows 
    ES_VERTICAL equ 00400000h; Not supported in RE 2.0/3.0 

    ES_NOIME equ 00080000h
    ES_SELFIME equ 00040000h
    ; Edit control options 
    ECO_AUTOWORDSELECTION equ 00000001h
    ECO_AUTOVSCROLL equ 00000040h
    ECO_AUTOHSCROLL equ 00000080h
    ECO_NOHIDESEL equ 00000100h
    ECO_READONLY equ 00000800h
    ECO_WANTRETURN equ 00001000h
    ECO_SAVESEL equ 00008000h
    ECO_SELECTIONBAR equ 01000000h
    ECO_VERTICAL equ 00400000h; FE specific 

    ; ECO operations 
    ECOOP_SET equ 0001h
    ECOOP_OR equ 0002h
    ECOOP_AND equ 0003h
    ECOOP_XOR equ 0004h
    ; New word break function actions 
    WB_CLASSIFY equ 3
    WB_MOVEWORDLEFT equ 4
    WB_MOVEWORDRIGHT equ 5
    WB_LEFTBREAK equ 6
    WB_RIGHTBREAK equ 7
    ; East Asia specific flags 
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
    ; East Asia specific flags 
    IMF_FORCENONE equ 0001h
    IMF_FORCEENABLE equ 0002h
    IMF_FORCEDISABLE equ 0004h
    IMF_CLOSESTATUSWINDOW equ 0008h
    IMF_VERTICAL equ 0020h
    IMF_FORCEACTIVE equ 0040h
    IMF_FORCEINACTIVE equ 0080h
    IMF_FORCEREMEMBER equ 0100h
    IMF_MULTIPLEEDIT equ 0400h
    ; Word break flags (used with WB_CLASSIFY) 
    WBF_CLASS equ (0Fh)
    WBF_ISWHITE equ (10h)
    WBF_BREAKLINE equ (20h)
    WBF_BREAKAFTER equ (40h)
    ; Data types 
    ifdef _WIN32
      ; Extended edit word break proc (character set aware) 
      TYPE_EDITWORDBREAKPROCEX typedef proto WIN_STD_CALL_CONV :ptr SBYTE, :LONG, :BYTE, :INT_
      EDITWORDBREAKPROCEX typedef ptr TYPE_EDITWORDBREAKPROCEX

    endif
    ; All character format measurements are in twips 
    CHARFORMATA struct 4
      cbSize DWORD ?
      dwMask DWORD ?
      dwEffects DWORD ?
      yHeight SDWORD ?
      yOffset SDWORD ?
      crTextColor COLORREF ?
      bCharSet BYTE ?
      bPitchAndFamily BYTE ?
      szFaceName SBYTE LF_FACESIZE dup (?)
    CHARFORMATA ends
    _charformat typedef CHARFORMATA
    CHARFORMATW struct 4
      cbSize DWORD ?
      dwMask DWORD ?
      dwEffects DWORD ?
      yHeight SDWORD ?
      yOffset SDWORD ?
      crTextColor COLORREF ?
      bCharSet BYTE ?
      bPitchAndFamily BYTE ?
      szFaceName WORD LF_FACESIZE dup (?)
    CHARFORMATW ends
    _charformatw typedef CHARFORMATW
    if (_RICHEDIT_VER ge 0200h)
      ifdef UNICODE
        CHARFORMAT equ <CHARFORMATW>
      else
        CHARFORMAT equ <CHARFORMATA>
      endif
      ; UNICODE 
    else
      CHARFORMAT equ <CHARFORMATA>
    endif
    ; _RICHEDIT_VER >= 0x0200 
    ; CHARFORMAT2 structure 
    if Defined(__cplusplus)
      ;[...]
    else
    ; regular C-style	
      CHARFORMAT2W struct
        cbSize DWORD ?
        dwMask DWORD ?
        dwEffects DWORD ?
        yHeight SDWORD ?
        yOffset SDWORD ?
        ; > 0 for superscript, < 0 for subscript 
        crTextColor COLORREF ?
        bCharSet BYTE ?
        bPitchAndFamily BYTE ?
        szFaceName WORD LF_FACESIZE dup (?)
        wWeight WORD ?
        ; Font weight (LOGFONT value)		
        sSpacing SWORD ?
        ; Amount to space between letters	
        crBackColor COLORREF ?
        ; Background color 				
        lcid LCID ?
        ; Locale ID						
        if (_RICHEDIT_VER ge 0500h)
          union
            dwReserved DWORD ?
            ; Name up to 5.0
            dwCookie DWORD ?
            ; Client cookie opaque to RichEdit
          ends
        else
          dwReserved DWORD ?
          ; Name up to 5.0
        endif
        sStyle SWORD ?
        ; Style handle 					
        wKerning WORD ?
        ; Twip size above which to kern char pair
        bUnderlineType BYTE ?
        ; Underline type					
        bAnimation BYTE ?
        ; Animated text like marching ants 
        bRevAuthor BYTE ?
        ; Revision author index			
        if (_RICHEDIT_VER ge 0800h)
          bUnderlineColor BYTE ?
          ; Underline color
        endif
      CHARFORMAT2W ends
      _charformat2w typedef CHARFORMAT2W
      CHARFORMAT2A struct
        cbSize DWORD ?
        dwMask DWORD ?
        dwEffects DWORD ?
        yHeight SDWORD ?
        yOffset SDWORD ?
        ; > 0 for superscript, < 0 for subscript 
        crTextColor COLORREF ?
        bCharSet BYTE ?
        bPitchAndFamily BYTE ?
        szFaceName SBYTE LF_FACESIZE dup (?)
        wWeight WORD ?
        ; Font weight (LOGFONT value)		
        sSpacing SWORD ?
        ; Amount to space between letters	
        crBackColor COLORREF ?
        ; Background color 				
        lcid LCID ?
        ; Locale ID						
        if (_RICHEDIT_VER ge 0500h)
          union
            dwReserved DWORD ?
            ; Name up to 5.0
            dwCookie DWORD ?
            ; Client cookie opaque to RichEdit
          ends
        else
          dwReserved DWORD ?
          ; Name up to 5.0
        endif
        sStyle SWORD ?
        ; Style handle 					
        wKerning WORD ?
        ; Twip size above which to kern char pair
        bUnderlineType BYTE ?
        ; Underline type					
        bAnimation BYTE ?
        ; Animated text like marching ants 
        bRevAuthor BYTE ?
        ; Revision author index			
        if (_RICHEDIT_VER ge 0800h)
          bUnderlineColor BYTE ?
          ; Underline color
        endif
      CHARFORMAT2A ends
      _charformat2a typedef CHARFORMAT2A
    endif
    ; C++ 
    ifdef UNICODE
      CHARFORMAT2 equ <CHARFORMAT2W>
    else
      CHARFORMAT2 equ <CHARFORMAT2A>
    endif
    CHARFORMATDELTA equ <(sizeof(CHARFORMAT2) - sizeof(CHARFORMAT))>
    ; CFM_COLOR mirrors CFE_AUTOCOLOR, a little hack to easily deal with autocolor
    ; CHARFORMAT masks 
    CFM_BOLD equ 00000001h
    CFM_ITALIC equ 00000002h
    CFM_UNDERLINE equ 00000004h
    CFM_STRIKEOUT equ 00000008h
    CFM_PROTECTED equ 00000010h
    CFM_LINK equ 00000020h; Exchange hyperlink extension 

    CFM_SIZE equ 80000000h
    CFM_COLOR equ 40000000h
    CFM_FACE equ 20000000h
    CFM_OFFSET equ 10000000h
    CFM_CHARSET equ 08000000h
    ; CHARFORMAT effects 
    CFE_BOLD equ 00000001h
    CFE_ITALIC equ 00000002h
    CFE_UNDERLINE equ 00000004h
    CFE_STRIKEOUT equ 00000008h
    CFE_PROTECTED equ 00000010h
    CFE_LINK equ 00000020h
    CFE_AUTOCOLOR equ 40000000h; NOTE: this corresponds to 

    ; CFM_COLOR, which controls it 
    ; Masks and effects defined for CHARFORMAT2 -- an (*) indicates
    ; that the data is stored by RichEdit 2.0/3.0, but not displayed
    CFM_SMALLCAPS equ 00000040h; (*)	

    CFM_ALLCAPS equ 00000080h; Displayed by 3.0 

    CFM_HIDDEN equ 00000100h; Hidden by 3.0 

    CFM_OUTLINE equ 00000200h; (*)	

    CFM_SHADOW equ 00000400h; (*)	

    CFM_EMBOSS equ 00000800h; (*)	

    CFM_IMPRINT equ 00001000h; (*)	

    CFM_DISABLED equ 00002000h
    CFM_REVISED equ 00004000h
    CFM_REVAUTHOR equ 00008000h
    CFE_SUBSCRIPT equ 00010000h; Superscript and subscript are 

    CFE_SUPERSCRIPT equ 00020000h;	mutually exclusive			 

    CFM_ANIMATION equ 00040000h; (*)	

    CFM_STYLE equ 00080000h; (*)	

    CFM_KERNING equ 00100000h
    CFM_SPACING equ 00200000h; Displayed by 3.0 

    CFM_WEIGHT equ 00400000h
    CFM_UNDERLINETYPE equ 00800000h; Many displayed by 3.0 

    if (_RICHEDIT_VER ge 0600h)
      CFM_COOKIE equ 01000000h; RE 6.0

    endif
    CFM_LCID equ 02000000h
    CFM_BACKCOLOR equ 04000000h; Higher mask bits defined above

    CFM_SUBSCRIPT equ <(CFE_SUBSCRIPT or CFE_SUPERSCRIPT)>
    CFM_SUPERSCRIPT equ <CFM_SUBSCRIPT>
    ; CHARFORMAT "ALL" masks
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
    ; CFE_AUTOCOLOR and CFE_AUTOBACKCOLOR correspond to CFM_COLOR and
    ; CFM_BACKCOLOR, respectively, which control them
    CFE_AUTOBACKCOLOR equ <CFM_BACKCOLOR>
    CFM_FONTBOUND equ 00100000h
    CFM_LINKPROTECTED equ 00800000h; Word hyperlink field

    CFM_EXTENDED equ 02000000h
    CFM_MATHNOBUILDUP equ 08000000h
    CFM_MATH equ 10000000h
    CFM_MATHORDINARY equ 20000000h
    CFM_ALLEFFECTS equ <(CFM_EFFECTS2 or CFM_FONTBOUND or CFM_EXTENDED or CFM_MATHNOBUILDUP or CFM_MATH or CFM_MATHORDINARY)>
    CFE_FONTBOUND equ 00100000h; Font chosen by binder, not user

    CFE_LINKPROTECTED equ 00800000h
    CFE_EXTENDED equ 02000000h
    CFE_MATHNOBUILDUP equ 08000000h
    CFE_MATH equ 10000000h
    CFE_MATHORDINARY equ 20000000h
    ; Underline types. RE 1.0 displays only CFU_UNDERLINE
    CFU_CF1UNDERLINE equ 0FFh; Map charformat's bit underline to CF2

    CFU_INVERT equ 0FEh; For IME composition fake a selection

    CFU_UNDERLINETHICKLONGDASH equ 18; (*) display as dash

    CFU_UNDERLINETHICKDOTTED equ 17; (*) display as dot

    CFU_UNDERLINETHICKDASHDOTDOT equ 16; (*) display as dash dot dot

    CFU_UNDERLINETHICKDASHDOT equ 15; (*) display as dash dot

    CFU_UNDERLINETHICKDASH equ 14; (*) display as dash

    CFU_UNDERLINELONGDASH equ 13; (*) display as dash

    CFU_UNDERLINEHEAVYWAVE equ 12; (*) display as wave

    CFU_UNDERLINEDOUBLEWAVE equ 11; (*) display as wave

    CFU_UNDERLINEHAIRLINE equ 10; (*) display as single	

    CFU_UNDERLINETHICK equ 9
    CFU_UNDERLINEWAVE equ 8
    CFU_UNDERLINEDASHDOTDOT equ 7
    CFU_UNDERLINEDASHDOT equ 6
    CFU_UNDERLINEDASH equ 5
    CFU_UNDERLINEDOTTED equ 4
    CFU_UNDERLINEDOUBLE equ 3; (*) display as single

    CFU_UNDERLINEWORD equ 2; (*) display as single	

    CFU_UNDERLINE equ 1
    CFU_UNDERLINENONE equ 0
    yHeightCharPtsMost equ 1638
    ; EM_SETCHARFORMAT wParam masks 
    SCF_SELECTION equ 0001h
    SCF_WORD equ 0002h
    SCF_DEFAULT equ 0000h; Set default charformat or paraformat

    SCF_ALL equ 0004h; Not valid with SCF_SELECTION or SCF_WORD

    SCF_USEUIRULES equ 0008h; Modifier for SCF_SELECTION; says that

    ;	format came from a toolbar, etc., and
    ;	hence UI formatting rules should be
    ;	used instead of literal formatting
    SCF_ASSOCIATEFONT equ 0010h; Associate fontname with bCharSet (one

    ;	possible for each of Western, ME, FE,
    ;	Thai)
    SCF_NOKBUPDATE equ 0020h; Do not update KB layout for this change

    ;	even if autokeyboard is on
    SCF_ASSOCIATEFONT2 equ 0040h; Associate plane-2 (surrogate) font

    if (_RICHEDIT_VER ge 0500h)
      SCF_SMARTFONT equ 0080h; Apply font only if it can handle script (5.0)

      SCF_CHARREPFROMLCID equ 0100h; Get character repertoire from lcid (5.0)

      SPF_DONTSETDEFAULT equ 0002h; Suppress setting default on empty control

      SPF_SETDEFAULT equ 0004h; Set the default paraformat

    endif
    CHARRANGE struct
      cpMin SDWORD ?
      cpMax SDWORD ?
    CHARRANGE ends
    _charrange typedef CHARRANGE
    TEXTRANGEA struct
      chrg CHARRANGE <>
      lpstrText POINTER ?
      ; Allocated by caller, zero terminated by RichEdit 
    TEXTRANGEA ends
    _textrange typedef TEXTRANGEA
    TEXTRANGEW struct
      chrg CHARRANGE <>
      lpstrText POINTER ?
      ; Allocated by caller, zero terminated by RichEdit 
    TEXTRANGEW ends
    _textrangew typedef TEXTRANGEW
    if (_RICHEDIT_VER ge 0200h)
      ifdef UNICODE
        TEXTRANGE equ <TEXTRANGEW>
      else
        TEXTRANGE equ <TEXTRANGEA>
      endif
      ; UNICODE 
    else
      TEXTRANGE equ <TEXTRANGEA>
    endif
    ; _RICHEDIT_VER >= 0x0200 
    TYPE_EDITSTREAMCALLBACK typedef proto WIN_STD_CALL_CONV :DWORD_PTR, :LPBYTE, :LONG, :ptr LONG
    EDITSTREAMCALLBACK typedef ptr TYPE_EDITSTREAMCALLBACK

    EDITSTREAM struct 4
      dwCookie XWORD ?
      ; User value passed to callback as first parameter 
      dwError DWORD ?
      ; Last error 
      pfnCallback EDITSTREAMCALLBACK ?
    EDITSTREAM ends
    _editstream typedef EDITSTREAM
    ; Stream formats. Flags are all in low word, since high word
    ; gives possible codepage choice. 
    SF_TEXT equ 0001h
    SF_RTF equ 0002h
    SF_RTFNOOBJS equ 0003h; Write only 

    SF_TEXTIZED equ 0004h; Write only

    SF_UNICODE equ 0010h; Unicode file (UCS2 little endian) 

    SF_USECODEPAGE equ 0020h; CodePage given by high word 

    SF_NCRFORNONASCII equ 40h; Output \uN for nonASCII 

    SFF_WRITEXTRAPAR equ 80h; Output \par at end

    ; Flag telling stream operations to operate on selection only 
    ; EM_STREAMIN	replaces current selection 
    ; EM_STREAMOUT streams out current selection 
    SFF_SELECTION equ 8000h
    ; Flag telling stream operations to ignore some FE control words 
    ; having to do with FE word breaking and horiz vs vertical text. 
    ; Not used in RichEdit 2.0 and later	
    SFF_PLAINRTF equ 4000h
    ; Flag telling file stream output (SFF_SELECTION flag not set) to persist 
    ; \viewscaleN control word. 
    SFF_PERSISTVIEWSCALE equ 2000h
    ; Flag telling file stream input with SFF_SELECTION flag not set not to 
    ; close the document 
    SFF_KEEPDOCINFO equ 1000h
    ; Flag telling stream operations to output in Pocket Word format 
    SFF_PWD equ 0800h
    ; 3-bit field specifying the value of N - 1 to use for \rtfN or \pwdN 
    SF_RTFVAL equ 0700h
    FINDTEXTA struct
      chrg CHARRANGE <>
      lpstrText =POINTER ?
    FINDTEXTA ends
    _findtext typedef FINDTEXTA
    FINDTEXTW struct
      chrg CHARRANGE <>
      lpstrText =POINTER ?
    FINDTEXTW ends
    _findtextw typedef FINDTEXTW
    if (_RICHEDIT_VER ge 0200h)
      ifdef UNICODE
        FINDTEXT equ <FINDTEXTW>
      else
        FINDTEXT equ <FINDTEXTA>
      endif
      ; UNICODE 
    else
      FINDTEXT equ <FINDTEXTA>
    endif
    ; _RICHEDIT_VER >= 0x0200 
    FINDTEXTEXA struct
      chrg CHARRANGE <>
      lpstrText =POINTER ?
      chrgText CHARRANGE <>
    FINDTEXTEXA ends
    _findtextexa typedef FINDTEXTEXA
    FINDTEXTEXW struct
      chrg CHARRANGE <>
      lpstrText =POINTER ?
      chrgText CHARRANGE <>
    FINDTEXTEXW ends
    _findtextexw typedef FINDTEXTEXW
    if (_RICHEDIT_VER ge 0200h)
      ifdef UNICODE
        FINDTEXTEX equ <FINDTEXTEXW>
      else
        FINDTEXTEX equ <FINDTEXTEXA>
      endif
      ; UNICODE 
    else
      FINDTEXTEX equ <FINDTEXTEXA>
    endif
    ; _RICHEDIT_VER >= 0x0200 
    FORMATRANGE struct
      hdc HDC ?
      hdcTarget HDC ?
      rc RECT <>
      rcPage RECT <>
      chrg CHARRANGE <>
    FORMATRANGE ends
    _formatrange typedef FORMATRANGE
    ; All paragraph measurements are in twips 
    MAX_TAB_STOPS equ 32
    lDefaultTab equ 720
    MAX_TABLE_CELLS equ 63
    PARAFORMAT struct
      cbSize DWORD ?
      dwMask DWORD ?
      wNumbering WORD ?
      union
        wReserved WORD ?
        wEffects WORD ?
      ends
      dxStartIndent SDWORD ?
      dxRightIndent SDWORD ?
      dxOffset SDWORD ?
      wAlignment WORD ?
      cTabCount SWORD ?
      rgxTabs SDWORD MAX_TAB_STOPS dup (?)
    PARAFORMAT ends
    _paraformat typedef PARAFORMAT
    ifdef __cplusplus
      ;[...]
    else
    ; Regular C-style	
      PARAFORMAT2 struct
        cbSize DWORD ?
        dwMask DWORD ?
        wNumbering WORD ?
        union
          wReserved WORD ?
          wEffects WORD ?
        ends
        dxStartIndent SDWORD ?
        dxRightIndent SDWORD ?
        dxOffset SDWORD ?
        wAlignment WORD ?
        cTabCount SWORD ?
        rgxTabs SDWORD MAX_TAB_STOPS dup (?)
        dySpaceBefore SDWORD ?
        ; Vertical spacing before para 		
        dySpaceAfter SDWORD ?
        ; Vertical spacing after para			
        dyLineSpacing SDWORD ?
        ; Line spacing depending on Rule		
        sStyle SWORD ?
        ; Style handle 						
        bLineSpacingRule BYTE ?
        ; Rule for line spacing (see tom.doc)	
        bOutlineLevel BYTE ?
        ; Outline Level						
        wShadingWeight WORD ?
        ; Shading in hundredths of a per cent	
        wShadingStyle WORD ?
        ; Byte 0: style, nib 2: cfpat, 3: cbpat
        wNumberingStart WORD ?
        ; Starting value for numbering 			
        wNumberingStyle WORD ?
        ; Alignment, Roman/Arabic, (), ), ., etc.
        wNumberingTab WORD ?
        ; Space bet 1st indent and 1st-line text
        wBorderSpace WORD ?
        ; Border-text spaces (nbl/bdr in pts)	
        wBorderWidth WORD ?
        ; Pen widths (nbl/bdr in half twips)	
        wBorders WORD ?
        ; Border styles (nibble/border)		
      PARAFORMAT2 ends
      _paraformat2 typedef PARAFORMAT2
    endif
    ; C++	
    ; PARAFORMAT mask values 
    PFM_STARTINDENT equ 00000001h
    PFM_RIGHTINDENT equ 00000002h
    PFM_OFFSET equ 00000004h
    PFM_ALIGNMENT equ 00000008h
    PFM_TABSTOPS equ 00000010h
    PFM_NUMBERING equ 00000020h
    PFM_OFFSETINDENT equ 80000000h
    ; PARAFORMAT 2.0 masks and effects 
    PFM_SPACEBEFORE equ 00000040h
    PFM_SPACEAFTER equ 00000080h
    PFM_LINESPACING equ 00000100h
    PFM_STYLE equ 00000400h
    PFM_BORDER equ 00000800h; (*)	

    PFM_SHADING equ 00001000h; (*)	

    PFM_NUMBERINGSTYLE equ 00002000h; RE 3.0	

    PFM_NUMBERINGTAB equ 00004000h; RE 3.0	

    PFM_NUMBERINGSTART equ 00008000h; RE 3.0	

    PFM_RTLPARA equ 00010000h
    PFM_KEEP equ 00020000h; (*)	

    PFM_KEEPNEXT equ 00040000h; (*)	

    PFM_PAGEBREAKBEFORE equ 00080000h; (*)	

    PFM_NOLINENUMBER equ 00100000h; (*)	

    PFM_NOWIDOWCONTROL equ 00200000h; (*)	

    PFM_DONOTHYPHEN equ 00400000h; (*)	

    PFM_SIDEBYSIDE equ 00800000h; (*)	

    ; The following two paragraph-format properties are read only
    PFM_COLLAPSED equ 01000000h; RE 3.0 

    PFM_OUTLINELEVEL equ 02000000h; RE 3.0 

    PFM_BOX equ 04000000h; RE 3.0 

    PFM_RESERVED2 equ 08000000h; RE 4.0 

    PFM_TABLEROWDELIMITER equ 10000000h; RE 4.0 

    PFM_TEXTWRAPPINGBREAK equ 20000000h; RE 3.0 

    PFM_TABLE equ 40000000h; RE 3.0 

    ; PARAFORMAT "ALL" masks
    PFM_ALL equ <(PFM_STARTINDENT or PFM_RIGHTINDENT or PFM_OFFSET or PFM_ALIGNMENT or PFM_TABSTOPS or PFM_NUMBERING or PFM_OFFSETINDENT or PFM_RTLPARA)>
    ; Note: PARAFORMAT has no effects (BiDi RichEdit 1.0 does have PFE_RTLPARA)
    PFM_EFFECTS equ <(PFM_RTLPARA or PFM_KEEP or PFM_KEEPNEXT or PFM_TABLE or PFM_PAGEBREAKBEFORE or PFM_NOLINENUMBER or PFM_NOWIDOWCONTROL or PFM_DONOTHYPHEN or PFM_SIDEBYSIDE or PFM_TABLE or PFM_TABLEROWDELIMITER)>
    PFM_ALL2 equ <(PFM_ALL or PFM_EFFECTS or PFM_SPACEBEFORE or PFM_SPACEAFTER or PFM_LINESPACING or PFM_STYLE or PFM_SHADING or PFM_BORDER or PFM_NUMBERINGTAB or PFM_NUMBERINGSTART or PFM_NUMBERINGSTYLE)>
    PFE_RTLPARA equ (PFM_RTLPARA shr 16)
    PFE_KEEP equ (PFM_KEEP shr 16); (*)	

    PFE_KEEPNEXT equ (PFM_KEEPNEXT shr 16); (*)	

    PFE_PAGEBREAKBEFORE equ (PFM_PAGEBREAKBEFORE shr 16); (*)	

    PFE_NOLINENUMBER equ (PFM_NOLINENUMBER shr 16); (*)	

    PFE_NOWIDOWCONTROL equ (PFM_NOWIDOWCONTROL shr 16); (*)	

    PFE_DONOTHYPHEN equ (PFM_DONOTHYPHEN shr 16); (*)	

    PFE_SIDEBYSIDE equ (PFM_SIDEBYSIDE shr 16); (*)	

    PFE_TEXTWRAPPINGBREAK equ (PFM_TEXTWRAPPINGBREAK shr 16); (*)	

    ; The following four effects are read only
    PFE_COLLAPSED equ (PFM_COLLAPSED shr 16); (+)	

    PFE_BOX equ (PFM_BOX shr 16); (+)	

    PFE_TABLE equ (PFM_TABLE shr 16); Inside table row. RE 3.0 

    PFE_TABLEROWDELIMITER equ (PFM_TABLEROWDELIMITER shr 16); Table row start. RE 4.0 

    ; PARAFORMAT numbering options 
    PFN_BULLET equ 1; tomListBullet

    ; PARAFORMAT2 wNumbering options 
    PFN_ARABIC equ 2; tomListNumberAsArabic:	0, 1, 2,	...

    PFN_LCLETTER equ 3; tomListNumberAsLCLetter: a, b, c,	...

    PFN_UCLETTER equ 4; tomListNumberAsUCLetter: A, B, C,	...

    PFN_LCROMAN equ 5; tomListNumberAsLCRoman:	i, ii, iii, ...

    PFN_UCROMAN equ 6; tomListNumberAsUCRoman:	I, II, III, ...

    ; PARAFORMAT2 wNumberingStyle options 
    PFNS_PAREN equ 000h; default, e.g.,				  1)	

    PFNS_PARENS equ 100h; tomListParentheses/256, e.g., (1)	

    PFNS_PERIOD equ 200h; tomListPeriod/256, e.g., 	  1.	

    PFNS_PLAIN equ 300h; tomListPlain/256, e.g.,		  1 	

    PFNS_NONUMBER equ 400h; Used for continuation w/o number

    PFNS_NEWNUMBER equ 8000h; Start new number with wNumberingStart		

    ; (can be combined with other PFNS_xxx)
    ; PARAFORMAT alignment options 
    PFA_LEFT equ 1
    PFA_RIGHT equ 2
    PFA_CENTER equ 3
    ; PARAFORMAT2 alignment options 
    PFA_JUSTIFY equ 4; New paragraph-alignment option 2.0 (*) 

    PFA_FULL_INTERWORD equ 4; These are supported in 3.0 with advanced

    ; Notification structures 
    ifndef WM_NOTIFY
      WM_NOTIFY equ 004Eh
      NMHDR struct
        hwndFrom HWND ?
        idFrom DWORD ?
        code DWORD ?
      NMHDR ends
      _nmhdr typedef NMHDR
    endif
    ; !WM_NOTIFY 
    MSGFILTER struct
      nmhdr NMHDR <>
      msg DWORD ?
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
        fGroupTyping DWORD ?
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
    ; Used with IRichEditOleCallback::GetContextMenu, this flag will be
    ; passed as a "selection type".  It indicates that a context menu for
    ; a right-mouse drag drop should be generated.  The IOleObject parameter
    ; will really be the IDataObject for the drop
    GCM_RIGHTMOUSEDROP equ 8000h
    if (_RICHEDIT_VER ge 0800h)
      GETCONTEXTMENUEX struct
        chrg CHARRANGE <>
        dwFlags DWORD ?
        pt POINT <>
        pvReserved POINTER ?
      GETCONTEXTMENUEX ends
      _getcontextmenuex typedef GETCONTEXTMENUEX
      ; bits for GETCONTEXTMENUEX::dwFlags
      GCMF_GRIPPER equ 00000001h
      GCMF_SPELLING equ 00000002h; pSpellingSuggestions is valid

      ; and points to the list of spelling suggestions
      GCMF_TOUCHMENU equ 00004000h
      GCMF_MOUSEMENU equ 00002000h
    endif
    ENDROPFILES struct
      nmhdr NMHDR <>
      hDrop HANDLE ?
      cp SDWORD ?
      fProtected DWORD ?
    ENDROPFILES ends
    _endropfiles typedef ENDROPFILES
    ENPROTECTED struct
      nmhdr NMHDR <>
      msg DWORD ?
      wParam WPARAM ?
      lParam LPARAM ?
      chrg CHARRANGE <>
    ENPROTECTED ends
    _enprotected typedef ENPROTECTED
    ENSAVECLIPBOARD struct
      nmhdr NMHDR <>
      cObjectCount SDWORD ?
      cch SDWORD ?
    ENSAVECLIPBOARD ends
    _ensaveclipboard typedef ENSAVECLIPBOARD
    ifndef MACPORT
      ENOLEOPFAILED struct
        nmhdr NMHDR <>
        iob SDWORD ?
        lOper SDWORD ?
        hr HRESULT ?
      ENOLEOPFAILED ends
      _enoleopfailed typedef ENOLEOPFAILED
    endif
    OLEOP_DOVERB equ 1
    OBJECTPOSITIONS struct
      nmhdr NMHDR <>
      cObjectCount SDWORD ?
      pcpPositions POINTER ?
    OBJECTPOSITIONS ends
    _objectpositions typedef OBJECTPOSITIONS
    ENLINK struct
      nmhdr NMHDR <>
      msg DWORD ?
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
    ; PenWin specific 
    ENCORRECTTEXT struct
      nmhdr NMHDR <>
      chrg CHARRANGE <>
      seltyp WORD ?
    ENCORRECTTEXT ends
    _encorrecttext typedef ENCORRECTTEXT
    ; East Asia specific 
    PUNCTUATION struct
      iSize DWORD ?
      szPunctuation POINTER ?
    PUNCTUATION ends
    _punctuation typedef PUNCTUATION
    ; East Asia specific 
    COMPCOLOR struct
      crText COLORREF ?
      crBackground COLORREF ?
      dwEffects DWORD ?
    COMPCOLOR ends
    _compcolor typedef COMPCOLOR
    ; Clipboard formats - use as parameter to RegisterClipboardFormat() 
    CF_RTF equ <TEXT("Rich Text Format")>
    CF_RTFNOOBJS equ <TEXT("Rich Text Format Without Objects")>
    CF_RETEXTOBJ equ <TEXT("RichEdit Text and Objects")>
    ; Paste Special 
    REPASTESPECIAL struct
      dwAspect DWORD ?
      dwParam XWORD ?
    REPASTESPECIAL ends
    _repastespecial typedef REPASTESPECIAL
    ;	UndoName info 
    UNDONAMEID typedef SDWORD
    UID_UNKNOWN equ 0
    UID_TYPING equ 1
    UID_DELETE equ 2
    UID_DRAGDROP equ 3
    UID_CUT equ 4
    UID_PASTE equ 5
    UID_AUTOTABLE equ 6
    _undonameid typedef UNDONAMEID

    ; Flags for the SETEXTEX data structure 
    ST_DEFAULT equ 0
    ST_KEEPUNDO equ 1
    ST_SELECTION equ 2
    ST_NEWCHARS equ 4
    if (_RICHEDIT_VER ge 0500h)
      ST_UNICODE equ 8
    endif
    ; EM_SETTEXTEX info; this struct is passed in the wparam of the message 
    SETTEXTEX struct
      flags DWORD ?
      ; Flags (see the ST_XXX defines)
      codepage DWORD ?
      ; Code page for translation (CP_ACP for sys default,
      ;	1200 for Unicode, -1 for control default)
    SETTEXTEX ends
    _settextex typedef SETTEXTEX
    ; Flags for the GETEXTEX data structure 
    GT_DEFAULT equ 0
    GT_USECRLF equ 1
    GT_SELECTION equ 2
    GT_RAWTEXT equ 4
    GT_NOHIDDENTEXT equ 8
    ; EM_GETTEXTEX info; this struct is passed in the wparam of the message 
    GETTEXTEX struct
      cb DWORD ?
      ; Count of bytes in the string
      flags DWORD ?
      ; Flags (see the GT_XXX defines
      codepage DWORD ?
      ; Code page for translation (CP_ACP for sys default,
      ;	1200 for Unicode, -1 for control default)
      lpDefaultChar =POINTER ?
      ; Replacement for unmappable chars
      lpUsedDefChar LPBOOL ?
      ; Pointer to flag set when def char used
    GETTEXTEX ends
    _gettextex typedef GETTEXTEX
    ; Flags for the GETTEXTLENGTHEX data structure
    GTL_DEFAULT equ 0; Do default (return # of chars)

    GTL_USECRLF equ 1; Compute answer using CRLFs for paragraphs

    GTL_PRECISE equ 2; Compute a precise answer

    GTL_CLOSE equ 4; Fast computation of a "close" answer

    GTL_NUMCHARS equ 8; Return number of characters

    GTL_NUMBYTES equ 16; Return number of _bytes_

    ; EM_GETTEXTLENGTHEX info; this struct is passed in the wparam of the msg 
    GETTEXTLENGTHEX struct
      flags DWORD ?
      ; Flags (see GTL_XXX defines)
      codepage DWORD ?
      ; Code page for translation (CP_ACP for default,
      ;	1200 for Unicode)
    GETTEXTLENGTHEX ends
    _gettextlengthex typedef GETTEXTLENGTHEX
    ; BiDi specific features 
    BIDIOPTIONS struct
      cbSize DWORD ?
      wMask WORD ?
      wEffects WORD ?
    BIDIOPTIONS ends
    _bidioptions typedef BIDIOPTIONS
    ; BIDIOPTIONS masks 
    if (_RICHEDIT_VER eq 0100h)
      BOM_DEFPARADIR equ 0001h; Default paragraph direction (implies alignment) (obsolete) 

      BOM_PLAINTEXT equ 0002h; Use plain text layout (obsolete) 

    endif
    ; _RICHEDIT_VER == 0x0100 
    BOM_NEUTRALOVERRIDE equ 0004h; Override neutral layout (obsolete) 

    BOM_CONTEXTREADING equ 0008h; Context reading order 

    BOM_CONTEXTALIGNMENT equ 0010h; Context alignment 

    BOM_LEGACYBIDICLASS equ 0040h; Legacy Bidi classification (obsolete)

    if (_RICHEDIT_VER ge 0600h)
      BOM_UNICODEBIDI equ 0080h; Use Unicode BiDi algorithm

    endif
    ; BIDIOPTIONS effects 
    if (_RICHEDIT_VER eq 0100h)
      BOE_RTLDIR equ 0001h; Default paragraph direction (implies alignment) (obsolete) 

      BOE_PLAINTEXT equ 0002h; Use plain text layout (obsolete) 

    endif
    ; _RICHEDIT_VER == 0x0100 
    BOE_NEUTRALOVERRIDE equ 0004h; Override neutral layout (obsolete) 

    BOE_CONTEXTREADING equ 0008h; Context reading order 

    BOE_CONTEXTALIGNMENT equ 0010h; Context alignment 

    if (_RICHEDIT_VER ge 0800h)
      BOE_FORCERECALC equ 0020h; Force recalc and redraw 

    endif
    BOE_LEGACYBIDICLASS equ 0040h; Legacy Bidi classification (obsolete) 

    if (_RICHEDIT_VER ge 0600h)
      BOE_UNICODEBIDI equ 0080h; Use Unicode BiDi algorithm

    endif
    ; Additional EM_FINDTEXT[EX] flags 
    FR_MATCHDIAC equ 20000000h
    FR_MATCHKASHIDA equ 40000000h
    FR_MATCHALEFHAMZA equ 80000000h
    ; UNICODE embedding character 
    ifndef WCH_EMBEDDING
      WCH_EMBEDDING equ 0FFFCh
    endif
    ; WCH_EMBEDDING 
    ; khyph - Kind of hyphenation
    KHYPH typedef SDWORD
    khyphNil equ 0
    ; No Hyphenation
    khyphNormal equ 1
    ; Normal Hyphenation
    khyphAddBefore equ 2
    ; Add letter before hyphen
    khyphChangeBefore equ 3
    ; Change letter before hyphen
    khyphDeleteBefore equ 4
    ; Delete letter before hyphen
    khyphChangeAfter equ 5
    ; Change letter after hyphen
    khyphDelAndChange equ 6
    tagKHYPH typedef KHYPH

    ;	letter preceding hyphen
    HYPHRESULT struct
      khyph KHYPH ?
      ; Kind of hyphenation
      ichHyph SDWORD ?
      ; Character which was hyphenated
      chHyph WORD ?
      ; Depending on hyphenation type, character added, changed, etc.
    HYPHRESULT ends
    hyphresult typedef HYPHRESULT
    HyphenateProc proto WIN_STD_CALL_CONV :ptr WCHAR, :LANGID, :SDWORD, :ptr HYPHRESULT
    HYPHENATEINFO struct
      cbSize SWORD ?
      ; Size of HYPHENATEINFO structure
      dxHyphenateZone SWORD ?
      ; If a space character is closer to the margin
      ;	than this value, don't hyphenate (in TWIPs)
      TYPE_pfnHyphenate typedef proto WIN_STD_CALL_CONV :ptr WCHAR, :LANGID, :SDWORD, :ptr HYPHRESULT
      pfnHyphenate typedef ptr TYPE_pfnHyphenate

    HYPHENATEINFO ends
    tagHyphenateInfo typedef HYPHENATEINFO
    ifdef _WIN32
      include poppack.inc
    elseif  not Defined(RC_INVOKED)
    endif
    ; Additional class for Richedit 6.0
    if (_RICHEDIT_VER ge 0600h)
      ifndef RICHEDIT60_CLASS
        RICHEDIT60_CLASS equ <L("RICHEDIT60W")>
      endif
    endif
    ; The following identifiers are deprecated
    ; They were in previous versions of richedit.h
    PFA_FULL_NEWSPAPER equ 5; Not implemented

    PFA_FULL_INTERLETTER equ 6; Not implemented

    PFA_FULL_SCALED equ 7; Not implemented

    PFA_FULL_GLYPHS equ 8; Not implemented

    ; This is deprecated identifier.
    ; This constant is used for a discontinued lparam value in EM_AUTOURLDETECT handling
    AURL_ENABLEEA equ 1; Deprecated: use AURL_ENABLEEAURLS

    GCM_TOUCHMENU equ 4000h; Deprecated: Use GCMF_TOUCHMENU

    GCM_MOUSEMENU equ 2000h; Deprecated: Use GCMF_MOUSEMENU

    ifdef __cplusplus
      ;[...]
    endif
    ; __cplusplus 
    ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) *
  endif
endif
; !_RICHEDIT_ 
