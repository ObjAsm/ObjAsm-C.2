
/* ------------------- Resource Compiler Header File -------------------- */

/*  This file supplies the constants used by the resource compiler for
          various 32 bit resource components in .RC script files. */

/* ---------------------------------------------------------------------- */

    #define WM_DDE_FIRST            0x03E0
    #define WM_DDE_INITIATE         (WM_DDE_FIRST)
    #define WM_DDE_TERMINATE        (WM_DDE_FIRST+1)
    #define WM_DDE_ADVISE           (WM_DDE_FIRST+2)
    #define WM_DDE_UNADVISE         (WM_DDE_FIRST+3)
    #define WM_DDE_ACK              (WM_DDE_FIRST+4)
    #define WM_DDE_DATA             (WM_DDE_FIRST+5)
    #define WM_DDE_REQUEST          (WM_DDE_FIRST+6)
    #define WM_DDE_POKE             (WM_DDE_FIRST+7)
    #define WM_DDE_EXECUTE          (WM_DDE_FIRST+8)
    #define WM_DDE_LAST             (WM_DDE_FIRST+8)

    #define HDS_HORZ                0x0000
    #define HDS_BUTTONS             0x0002
    #define HDS_HOTTRACK            0x0004
    #define HDS_HIDDEN              0x0008
    #define HDS_DRAGDROP            0x0040
    #define HDS_FULLDRAG            0x0080
    #define RBS_TOOLTIPS            0x0100
    #define RBS_VARHEIGHT           0x0200
    #define RBS_BANDBORDERS         0x0400
    #define RBS_FIXEDORDER          0x0800
    #define RBS_REGISTERDROP        0x1000
    #define RBS_AUTOSIZE            0x2000
    #define RBS_VERTICALGRIPPER     0x4000
    #define RBS_DBLCLKTOGGLE        0x8000

    #define TTS_ALWAYSTIP           0x01
    #define TTS_NOPREFIX            0x02

    #define SBARS_SIZEGRIP          0x0100

    #define TBS_AUTOTICKS           0x0001
    #define TBS_VERT                0x0002
    #define TBS_HORZ                0x0000
    #define TBS_TOP                 0x0004
    #define TBS_BOTTOM              0x0000
    #define TBS_LEFT                0x0004
    #define TBS_RIGHT               0x0000
    #define TBS_BOTH                0x0008
    #define TBS_NOTICKS             0x0010
    #define TBS_ENABLESELRANGE      0x0020
    #define TBS_FIXEDLENGTH         0x0040
    #define TBS_NOTHUMB             0x0080
    #define TBS_TOOLTIPS            0x0100

    #define UDS_WRAP                0x0001
    #define UDS_SETBUDDYINT         0x0002
    #define UDS_ALIGNRIGHT          0x0004
    #define UDS_ALIGNLEFT           0x0008
    #define UDS_AUTOBUDDY           0x0010
    #define UDS_ARROWKEYS           0x0020
    #define UDS_HORZ                0x0040
    #define UDS_NOTHOUSANDS         0x0080
    #define UDS_HOTTRACK            0x0100

    #define PBS_SMOOTH              0x01
    #define PBS_VERTICAL            0x04

/* --------------------- Common Control Styles ------------------------- */

    #define CCS_TOP                 0x00000001L
    #define CCS_NOMOVEY             0x00000002L
    #define CCS_BOTTOM              0x00000003L
    #define CCS_NORESIZE            0x00000004L
    #define CCS_NOPARENTALIGN       0x00000008L
    #define CCS_ADJUSTABLE          0x00000020L
    #define CCS_NODIVIDER           0x00000040L
    #define CCS_VERT                0x00000080L
    #define CCS_LEFT                (CCS_VERT | CCS_TOP)
    #define CCS_RIGHT               (CCS_VERT | CCS_BOTTOM)
    #define CCS_NOMOVEX             (CCS_VERT | CCS_NOMOVEY)

    #define LVS_ICON                0x0000
    #define LVS_REPORT              0x0001
    #define LVS_SMALLICON           0x0002
    #define LVS_LIST                0x0003
    #define LVS_TYPEMASK            0x0003
    #define LVS_SINGLESEL           0x0004
    #define LVS_SHOWSELALWAYS       0x0008
    #define LVS_SORTASCENDING       0x0010
    #define LVS_SORTDESCENDING      0x0020
    #define LVS_SHAREIMAGELISTS     0x0040
    #define LVS_NOLABELWRAP         0x0080
    #define LVS_AUTOARRANGE         0x0100
    #define LVS_EDITLABELS          0x0200
    #define LVS_OWNERDATA           0x1000
    #define LVS_NOSCROLL            0x2000
    #define LVS_TYPESTYLEMASK       0xfc00
    #define LVS_ALIGNTOP            0x0000
    #define LVS_ALIGNLEFT           0x0800
    #define LVS_ALIGNMASK           0x0c00
    #define LVS_OWNERDRAWFIXED      0x0400
    #define LVS_NOCOLUMNHEADER      0x4000
    #define LVS_NOSORTHEADER        0x8000
    #define TVS_HASBUTTONS          0x0001
    #define TVS_HASLINES            0x0002
    #define TVS_LINESATROOT         0x0004
    #define TVS_EDITLABELS          0x0008
    #define TVS_DISABLEDRAGDROP     0x0010
    #define TVS_SHOWSELALWAYS       0x0020
    #define TVS_RTLREADING          0x0040
    #define TVS_NOTOOLTIPS          0x0080
    #define TVS_CHECKBOXES          0x0100
    #define TVS_TRACKSELECT         0x0200
    #define TVS_SINGLEEXPAND        0x0400
    #define TVS_INFOTIP             0x0800
    #define TVS_FULLROWSELECT       0x1000
    #define TVS_NOSCROLL            0x2000
    #define TVS_NONEVENHEIGHT       0x4000

    #define TCS_SCROLLOPPOSITE      0x0001
    #define TCS_BOTTOM              0x0002
    #define TCS_RIGHT               0x0002
    #define TCS_MULTISELECT         0x0004
    #define TCS_FLATBUTTONS         0x0008
    #define TCS_FORCEICONLEFT       0x0010
    #define TCS_FORCELABELLEFT      0x0020
    #define TCS_HOTTRACK            0x0040
    #define TCS_VERTICAL            0x0080
    #define TCS_TABS                0x0000
    #define TCS_BUTTONS             0x0100
    #define TCS_SINGLELINE          0x0000
    #define TCS_MULTILINE           0x0200
    #define TCS_RIGHTJUSTIFY        0x0000
    #define TCS_FIXEDWIDTH          0x0400
    #define TCS_RAGGEDRIGHT         0x0800
    #define TCS_FOCUSONBUTTONDOWN   0x1000
    #define TCS_OWNERDRAWFIXED      0x2000
    #define TCS_TOOLTIPS            0x4000
    #define TCS_FOCUSNEVER          0x8000

    #define ACS_CENTER              0x0001
    #define ACS_TRANSPARENT         0x0002
    #define ACS_AUTOPLAY            0x0004
    #define ACS_TIMER               0x0008

    #define DTS_UPDOWN              0x0001
    #define DTS_SHOWNONE            0x0002
    #define DTS_SHORTDATEFORMAT     0x0000
    #define DTS_LONGDATEFORMAT      0x0004
    #define DTS_TIMEFORMAT          0x0009
    #define DTS_APPCANPARSE         0x0010
    #define DTS_RIGHTALIGN          0x0020

    #define PGS_VERT                0x00000000
    #define PGS_HORZ                0x00000001
    #define PGS_AUTOSCROLL          0x00000002
    #define PGS_DRAGNDROP           0x00000004

    /* style definition */

    #define NFS_EDIT                0x0001
    #define NFS_STATIC              0x0002
    #define NFS_LISTCOMBO           0x0004
    #define NFS_BUTTON              0x0008
    #define NFS_ALL                 0x0010

    /* ShowWindow() Commands */

    #define SW_HIDE             0
    #define SW_SHOWNORMAL       1
    #define SW_NORMAL           1
    #define SW_SHOWMINIMIZED    2
    #define SW_SHOWMAXIMIZED    3
    #define SW_MAXIMIZE         3
    #define SW_SHOWNOACTIVATE   4
    #define SW_SHOW             5
    #define SW_MINIMIZE         6
    #define SW_SHOWMINNOACTIVE  7
    #define SW_SHOWNA           8
    #define SW_RESTORE          9
    #define SW_SHOWDEFAULT      10
    #define SW_FORCEMINIMIZE    11
    #define SW_MAX              11

    /*
     * Old ShowWindow() Commands
     */
    #define HIDE_WINDOW         0
    #define SHOW_OPENWINDOW     1
    #define SHOW_ICONWINDOW     2
    #define SHOW_FULLSCREEN     3
    #define SHOW_OPENNOACTIVATE 4

    /*
     * Identifiers for the WM_SHOWWINDOW message
     */
    #define SW_PARENTCLOSING    1
    #define SW_OTHERZOOM        2
    #define SW_PARENTOPENING    3
    #define SW_OTHERUNZOOM      4

    /*
     * Virtual Keys, Standard Set
     */
    #define VK_LBUTTON        0x01
    #define VK_RBUTTON        0x02
    #define VK_CANCEL         0x03
    #define VK_MBUTTON        0x04

    #define VK_BACK           0x08
    #define VK_TAB            0x09

    #define VK_CLEAR          0x0C
    #define VK_RETURN         0x0D

    #define VK_SHIFT          0x10
    #define VK_CONTROL        0x11
    #define VK_MENU           0x12
    #define VK_PAUSE          0x13
    #define VK_CAPITAL        0x14

    #define VK_KANA           0x15
    #define VK_HANGEUL        0x15
    #define VK_HANGUL         0x15
    #define VK_JUNJA          0x17
    #define VK_FINAL          0x18
    #define VK_HANJA          0x19
    #define VK_KANJI          0x19

    #define VK_ESCAPE         0x1B

    #define VK_CONVERT        0x1C
    #define VK_NONCONVERT     0x1D
    #define VK_ACCEPT         0x1E
    #define VK_MODECHANGE     0x1F

    #define VK_SPACE          0x20
    #define VK_PRIOR          0x21
    #define VK_NEXT           0x22
    #define VK_END            0x23
    #define VK_HOME           0x24
    #define VK_LEFT           0x25
    #define VK_UP             0x26
    #define VK_RIGHT          0x27
    #define VK_DOWN           0x28
    #define VK_SELECT         0x29
    #define VK_PRINT          0x2A
    #define VK_EXECUTE        0x2B
    #define VK_SNAPSHOT       0x2C
    #define VK_INSERT         0x2D
    #define VK_DELETE         0x2E
    #define VK_HELP           0x2F

    /* VK_0 thru VK_9 are the same as ASCII '0' thru '9' (0x30 - 0x39) */
    /* VK_A thru VK_Z are the same as ASCII 'A' thru 'Z' (0x41 - 0x5A) */

    #define VK_LWIN           0x5B
    #define VK_RWIN           0x5C
    #define VK_APPS           0x5D

    #define VK_NUMPAD0        0x60
    #define VK_NUMPAD1        0x61
    #define VK_NUMPAD2        0x62
    #define VK_NUMPAD3        0x63
    #define VK_NUMPAD4        0x64
    #define VK_NUMPAD5        0x65
    #define VK_NUMPAD6        0x66
    #define VK_NUMPAD7        0x67
    #define VK_NUMPAD8        0x68
    #define VK_NUMPAD9        0x69
    #define VK_MULTIPLY       0x6A
    #define VK_ADD            0x6B
    #define VK_SEPARATOR      0x6C
    #define VK_SUBTRACT       0x6D
    #define VK_DECIMAL        0x6E
    #define VK_DIVIDE         0x6F
    #define VK_F1             0x70
    #define VK_F2             0x71
    #define VK_F3             0x72
    #define VK_F4             0x73
    #define VK_F5             0x74
    #define VK_F6             0x75
    #define VK_F7             0x76
    #define VK_F8             0x77
    #define VK_F9             0x78
    #define VK_F10            0x79
    #define VK_F11            0x7A
    #define VK_F12            0x7B
    #define VK_F13            0x7C
    #define VK_F14            0x7D
    #define VK_F15            0x7E
    #define VK_F16            0x7F
    #define VK_F17            0x80
    #define VK_F18            0x81
    #define VK_F19            0x82
    #define VK_F20            0x83
    #define VK_F21            0x84
    #define VK_F22            0x85
    #define VK_F23            0x86
    #define VK_F24            0x87
    #define VK_NUMLOCK        0x90
    #define VK_SCROLL         0x91
    #define VK_LSHIFT         0xA0
    #define VK_RSHIFT         0xA1
    #define VK_LCONTROL       0xA2
    #define VK_RCONTROL       0xA3
    #define VK_LMENU          0xA4
    #define VK_RMENU          0xA5
    #define VK_PROCESSKEY     0xE5
    #define VK_ATTN           0xF6
    #define VK_CRSEL          0xF7
    #define VK_EXSEL          0xF8
    #define VK_EREOF          0xF9
    #define VK_PLAY           0xFA
    #define VK_ZOOM           0xFB
    #define VK_NONAME         0xFC
    #define VK_PA1            0xFD
    #define VK_OEM_CLEAR      0xFE

    #define WM_NULL                         0x0000
    #define WM_CREATE                       0x0001
    #define WM_DESTROY                      0x0002
    #define WM_MOVE                         0x0003
    #define WM_SIZE                         0x0005
    #define WM_ACTIVATE                     0x0006

    /* WM_ACTIVATE state values */

    #define     WA_INACTIVE                 0
    #define     WA_ACTIVE                   1
    #define     WA_CLICKACTIVE              2

    #define WM_SETFOCUS                     0x0007
    #define WM_KILLFOCUS                    0x0008
    #define WM_ENABLE                       0x000A
    #define WM_SETREDRAW                    0x000B
    #define WM_SETTEXT                      0x000C
    #define WM_GETTEXT                      0x000D
    #define WM_GETTEXTLENGTH                0x000E
    #define WM_PAINT                        0x000F
    #define WM_CLOSE                        0x0010
    #define WM_QUERYENDSESSION              0x0011
    #define WM_QUIT                         0x0012
    #define WM_QUERYOPEN                    0x0013
    #define WM_ERASEBKGND                   0x0014
    #define WM_SYSCOLORCHANGE               0x0015
    #define WM_ENDSESSION                   0x0016
    #define WM_SHOWWINDOW                   0x0018
    #define WM_WININICHANGE                 0x001A
    #define WM_SETTINGCHANGE                WM_WININICHANGE

    #define WM_DEVMODECHANGE                0x001B
    #define WM_ACTIVATEAPP                  0x001C
    #define WM_FONTCHANGE                   0x001D
    #define WM_TIMECHANGE                   0x001E
    #define WM_CANCELMODE                   0x001F
    #define WM_SETCURSOR                    0x0020
    #define WM_MOUSEACTIVATE                0x0021
    #define WM_CHILDACTIVATE                0x0022
    #define WM_QUEUESYNC                    0x0023

    #define WM_GETMINMAXINFO                0x0024
    #define WM_PAINTICON                    0x0026
    #define WM_ICONERASEBKGND               0x0027
    #define WM_NEXTDLGCTL                   0x0028
    #define WM_SPOOLERSTATUS                0x002A
    #define WM_DRAWITEM                     0x002B
    #define WM_MEASUREITEM                  0x002C
    #define WM_DELETEITEM                   0x002D
    #define WM_VKEYTOITEM                   0x002E
    #define WM_CHARTOITEM                   0x002F
    #define WM_SETFONT                      0x0030
    #define WM_GETFONT                      0x0031
    #define WM_SETHOTKEY                    0x0032
    #define WM_GETHOTKEY                    0x0033
    #define WM_QUERYDRAGICON                0x0037
    #define WM_COMPAREITEM                  0x0039
    #define WM_GETOBJECT                    0x003D
    #define WM_COMPACTING                   0x0041
    #define WM_COMMNOTIFY                   0x0044
    #define WM_WINDOWPOSCHANGING            0x0046
    #define WM_WINDOWPOSCHANGED             0x0047
    #define WM_POWER                        0x0048

    /* wParam for WM_POWER window message and DRV_POWER driver notification */

    #define PWR_OK                          1
    #define PWR_FAIL                        (-1)
    #define PWR_SUSPENDREQUEST              1
    #define PWR_SUSPENDRESUME               2
    #define PWR_CRITICALRESUME              3

    #define WM_COPYDATA                     0x004A
    #define WM_CANCELJOURNAL                0x004B

    #define WM_NOTIFY                       0x004E
    #define WM_INPUTLANGCHANGEREQUEST       0x0050
    #define WM_INPUTLANGCHANGE              0x0051
    #define WM_TCARD                        0x0052
    #define WM_HELP                         0x0053
    #define WM_USERCHANGED                  0x0054
    #define WM_NOTIFYFORMAT                 0x0055

    #define NFR_ANSI                             1
    #define NFR_UNICODE                          2
    #define NF_QUERY                             3
    #define NF_REQUERY                           4

    #define WM_CONTEXTMENU                  0x007B
    #define WM_STYLECHANGING                0x007C
    #define WM_STYLECHANGED                 0x007D
    #define WM_DISPLAYCHANGE                0x007E
    #define WM_GETICON                      0x007F
    #define WM_SETICON                      0x0080

    #define WM_NCCREATE                     0x0081
    #define WM_NCDESTROY                    0x0082
    #define WM_NCCALCSIZE                   0x0083
    #define WM_NCHITTEST                    0x0084
    #define WM_NCPAINT                      0x0085
    #define WM_NCACTIVATE                   0x0086
    #define WM_GETDLGCODE                   0x0087
    #define WM_SYNCPAINT                    0x0088
    #define WM_NCMOUSEMOVE                  0x00A0
    #define WM_NCLBUTTONDOWN                0x00A1
    #define WM_NCLBUTTONUP                  0x00A2
    #define WM_NCLBUTTONDBLCLK              0x00A3
    #define WM_NCRBUTTONDOWN                0x00A4
    #define WM_NCRBUTTONUP                  0x00A5
    #define WM_NCRBUTTONDBLCLK              0x00A6
    #define WM_NCMBUTTONDOWN                0x00A7
    #define WM_NCMBUTTONUP                  0x00A8
    #define WM_NCMBUTTONDBLCLK              0x00A9

    #define WM_KEYFIRST                     0x0100
    #define WM_KEYDOWN                      0x0100
    #define WM_KEYUP                        0x0101
    #define WM_CHAR                         0x0102
    #define WM_DEADCHAR                     0x0103
    #define WM_SYSKEYDOWN                   0x0104
    #define WM_SYSKEYUP                     0x0105
    #define WM_SYSCHAR                      0x0106
    #define WM_SYSDEADCHAR                  0x0107
    #define WM_KEYLAST                      0x0108

    #define WM_IME_STARTCOMPOSITION         0x010D
    #define WM_IME_ENDCOMPOSITION           0x010E
    #define WM_IME_COMPOSITION              0x010F
    #define WM_IME_KEYLAST                  0x010F

    #define WM_INITDIALOG                   0x0110
    #define WM_COMMAND                      0x0111
    #define WM_SYSCOMMAND                   0x0112
    #define WM_TIMER                        0x0113
    #define WM_HSCROLL                      0x0114
    #define WM_VSCROLL                      0x0115
    #define WM_INITMENU                     0x0116
    #define WM_INITMENUPOPUP                0x0117
    #define WM_MENUSELECT                   0x011F
    #define WM_MENUCHAR                     0x0120
    #define WM_ENTERIDLE                    0x0121
    #define WM_MENURBUTTONUP                0x0122
    #define WM_MENUDRAG                     0x0123
    #define WM_MENUGETOBJECT                0x0124
    #define WM_UNINITMENUPOPUP              0x0125
    #define WM_MENUCOMMAND                  0x0126

    #define WM_CTLCOLORMSGBOX               0x0132
    #define WM_CTLCOLOREDIT                 0x0133
    #define WM_CTLCOLORLISTBOX              0x0134
    #define WM_CTLCOLORBTN                  0x0135
    #define WM_CTLCOLORDLG                  0x0136
    #define WM_CTLCOLORSCROLLBAR            0x0137
    #define WM_CTLCOLORSTATIC               0x0138

    #define WM_MOUSEFIRST                   0x0200
    #define WM_MOUSEMOVE                    0x0200
    #define WM_LBUTTONDOWN                  0x0201
    #define WM_LBUTTONUP                    0x0202
    #define WM_LBUTTONDBLCLK                0x0203
    #define WM_RBUTTONDOWN                  0x0204
    #define WM_RBUTTONUP                    0x0205
    #define WM_RBUTTONDBLCLK                0x0206
    #define WM_MBUTTONDOWN                  0x0207
    #define WM_MBUTTONUP                    0x0208
    #define WM_MBUTTONDBLCLK                0x0209

    #define WHEEL_DELTA                     120
    #define WHEEL_PAGESCROLL                (UINT_MAX)

    #define WM_PARENTNOTIFY                 0x0210
    #define WM_ENTERMENULOOP                0x0211
    #define WM_EXITMENULOOP                 0x0212

    #define WM_NEXTMENU                     0x0213
    #define WM_SIZING                       0x0214
    #define WM_CAPTURECHANGED               0x0215
    #define WM_MOVING                       0x0216
    #define WM_POWERBROADCAST               0x0218
    #define WM_DEVICECHANGE                 0x0219
    #define WM_MDICREATE                    0x0220
    #define WM_MDIDESTROY                   0x0221
    #define WM_MDIACTIVATE                  0x0222
    #define WM_MDIRESTORE                   0x0223
    #define WM_MDINEXT                      0x0224
    #define WM_MDIMAXIMIZE                  0x0225
    #define WM_MDITILE                      0x0226
    #define WM_MDICASCADE                   0x0227
    #define WM_MDIICONARRANGE               0x0228
    #define WM_MDIGETACTIVE                 0x0229

    #define WM_MDISETMENU                   0x0230
    #define WM_ENTERSIZEMOVE                0x0231
    #define WM_EXITSIZEMOVE                 0x0232
    #define WM_DROPFILES                    0x0233
    #define WM_MDIREFRESHMENU               0x0234

    #define WM_IME_SETCONTEXT               0x0281
    #define WM_IME_NOTIFY                   0x0282
    #define WM_IME_CONTROL                  0x0283
    #define WM_IME_COMPOSITIONFULL          0x0284
    #define WM_IME_SELECT                   0x0285
    #define WM_IME_CHAR                     0x0286
    #define WM_IME_REQUEST                  0x0288
    #define WM_IME_KEYDOWN                  0x0290
    #define WM_IME_KEYUP                    0x0291

    #define WM_MOUSEHOVER                   0x02A1
    #define WM_MOUSELEAVE                   0x02A3

    #define WM_CUT                          0x0300
    #define WM_COPY                         0x0301
    #define WM_PASTE                        0x0302
    #define WM_CLEAR                        0x0303
    #define WM_UNDO                         0x0304
    #define WM_RENDERFORMAT                 0x0305
    #define WM_RENDERALLFORMATS             0x0306
    #define WM_DESTROYCLIPBOARD             0x0307
    #define WM_DRAWCLIPBOARD                0x0308
    #define WM_PAINTCLIPBOARD               0x0309
    #define WM_VSCROLLCLIPBOARD             0x030A
    #define WM_SIZECLIPBOARD                0x030B
    #define WM_ASKCBFORMATNAME              0x030C
    #define WM_CHANGECBCHAIN                0x030D
    #define WM_HSCROLLCLIPBOARD             0x030E
    #define WM_QUERYNEWPALETTE              0x030F
    #define WM_PALETTEISCHANGING            0x0310
    #define WM_PALETTECHANGED               0x0311
    #define WM_HOTKEY                       0x0312

    #define WM_PRINT                        0x0317
    #define WM_PRINTCLIENT                  0x0318

    #define WM_HANDHELDFIRST                0x0358
    #define WM_HANDHELDLAST                 0x035F

    #define WM_AFXFIRST                     0x0360
    #define WM_AFXLAST                      0x037F

    #define WM_PENWINFIRST                  0x0380
    #define WM_PENWINLAST                   0x038F
    #define WM_APP                          0x8000

    #define WM_USER                         0x0400

    /*  wParam for WM_SIZING message  */

    #define WMSZ_LEFT           1
    #define WMSZ_RIGHT          2
    #define WMSZ_TOP            3
    #define WMSZ_TOPLEFT        4
    #define WMSZ_TOPRIGHT       5
    #define WMSZ_BOTTOM         6
    #define WMSZ_BOTTOMLEFT     7
    #define WMSZ_BOTTOMRIGHT    8

    /* WM_NCHITTEST and MOUSEHOOKSTRUCT Mouse Position Codes */

    #define HTERROR             (-2)
    #define HTTRANSPARENT       (-1)
    #define HTNOWHERE           0
    #define HTCLIENT            1
    #define HTCAPTION           2
    #define HTSYSMENU           3
    #define HTGROWBOX           4
    #define HTSIZE              HTGROWBOX
    #define HTMENU              5
    #define HTHSCROLL           6
    #define HTVSCROLL           7
    #define HTMINBUTTON         8
    #define HTMAXBUTTON         9
    #define HTLEFT              10
    #define HTRIGHT             11
    #define HTTOP               12
    #define HTTOPLEFT           13
    #define HTTOPRIGHT          14
    #define HTBOTTOM            15
    #define HTBOTTOMLEFT        16
    #define HTBOTTOMRIGHT       17
    #define HTBORDER            18
    #define HTREDUCE            HTMINBUTTON
    #define HTZOOM              HTMAXBUTTON
    #define HTSIZEFIRST         HTLEFT
    #define HTSIZELAST          HTBOTTOMRIGHT
    #define HTOBJECT            19
    #define HTCLOSE             20
    #define HTHELP              21

    #define SMTO_NORMAL         0x0000
    #define SMTO_BLOCK          0x0001
    #define SMTO_ABORTIFHUNG    0x0002
    #define SMTO_NOTIMEOUTIFNOTHUNG 0x0008

    /* WM_MOUSEACTIVATE Return Codes */

    #define MA_ACTIVATE         1
    #define MA_ACTIVATEANDEAT   2
    #define MA_NOACTIVATE       3
    #define MA_NOACTIVATEANDEAT 4

    /* WM_SETICON / WM_GETICON Type Codes */

    #define ICON_SMALL          0
    #define ICON_BIG            1

    /* WM_SIZE message wParam values */

    #define SIZE_RESTORED       0
    #define SIZE_MINIMIZED      1
    #define SIZE_MAXIMIZED      2
    #define SIZE_MAXSHOW        3
    #define SIZE_MAXHIDE        4

    /* Obsolete constant names */

    #define SIZENORMAL          SIZE_RESTORED
    #define SIZEICONIC          SIZE_MINIMIZED
    #define SIZEFULLSCREEN      SIZE_MAXIMIZED
    #define SIZEZOOMSHOW        SIZE_MAXSHOW
    #define SIZEZOOMHIDE        SIZE_MAXHIDE

    /* WM_NCCALCSIZE "window valid rect" return values */

    #define WVR_ALIGNTOP        0x0010
    #define WVR_ALIGNLEFT       0x0020
    #define WVR_ALIGNBOTTOM     0x0040
    #define WVR_ALIGNRIGHT      0x0080
    #define WVR_HREDRAW         0x0100
    #define WVR_VREDRAW         0x0200
    #define WVR_REDRAW         (WVR_HREDRAW | \
                                WVR_VREDRAW)

    /* Key State Masks for Mouse Messages */

    #define MK_LBUTTON          0x0001
    #define MK_RBUTTON          0x0002
    #define MK_SHIFT            0x0004
    #define MK_CONTROL          0x0008
    #define MK_MBUTTON          0x0010

    #define TME_HOVER           0x00000001
    #define TME_LEAVE           0x00000002
    #define TME_QUERY           0x40000000
    #define TME_CANCEL          0x80000000

    #define HOVER_DEFAULT       0xFFFFFFFF

    /* Window Styles */

    #define WS_OVERLAPPED       0x00000000L
    #define WS_POPUP            0x80000000L
    #define WS_CHILD            0x40000000L
    #define WS_MINIMIZE         0x20000000L
    #define WS_VISIBLE          0x10000000L
    #define WS_DISABLED         0x08000000L
    #define WS_CLIPSIBLINGS     0x04000000L
    #define WS_CLIPCHILDREN     0x02000000L
    #define WS_MAXIMIZE         0x01000000L
    #define WS_CAPTION          0x00C00000L
    #define WS_BORDER           0x00800000L
    #define WS_DLGFRAME         0x00400000L
    #define WS_VSCROLL          0x00200000L
    #define WS_HSCROLL          0x00100000L
    #define WS_SYSMENU          0x00080000L
    #define WS_THICKFRAME       0x00040000L
    #define WS_GROUP            0x00020000L
    #define WS_TABSTOP          0x00010000L

    #define WS_MINIMIZEBOX      0x00020000L
    #define WS_MAXIMIZEBOX      0x00010000L

    #define WS_TILED            WS_OVERLAPPED
    #define WS_ICONIC           WS_MINIMIZE
    #define WS_SIZEBOX          WS_THICKFRAME
    #define WS_TILEDWINDOW      WS_OVERLAPPEDWINDOW

    /* Common Window Styles */

    #define WS_OVERLAPPEDWINDOW (WS_OVERLAPPED     | \
                                 WS_CAPTION        | \
                                 WS_SYSMENU        | \
                                 WS_THICKFRAME     | \
                                 WS_MINIMIZEBOX    | \
                                 WS_MAXIMIZEBOX)

    #define WS_POPUPWINDOW      (WS_POPUP          | \
                                 WS_BORDER         | \
                                 WS_SYSMENU)

    #define WS_CHILDWINDOW      (WS_CHILD)

    /* Extended Window Styles */

    #define WS_EX_DLGMODALFRAME     0x00000001L
    #define WS_EX_NOPARENTNOTIFY    0x00000004L
    #define WS_EX_TOPMOST           0x00000008L
    #define WS_EX_ACCEPTFILES       0x00000010L
    #define WS_EX_TRANSPARENT       0x00000020L
    #define WS_EX_MDICHILD          0x00000040L
    #define WS_EX_TOOLWINDOW        0x00000080L
    #define WS_EX_WINDOWEDGE        0x00000100L
    #define WS_EX_CLIENTEDGE        0x00000200L
    #define WS_EX_CONTEXTHELP       0x00000400L
    #define WS_EX_RIGHT             0x00001000L
    #define WS_EX_LEFT              0x00000000L
    #define WS_EX_RTLREADING        0x00002000L
    #define WS_EX_LTRREADING        0x00000000L
    #define WS_EX_LEFTSCROLLBAR     0x00004000L
    #define WS_EX_RIGHTSCROLLBAR    0x00000000L
    #define WS_EX_CONTROLPARENT     0x00010000L
    #define WS_EX_STATICEDGE        0x00020000L
    #define WS_EX_APPWINDOW         0x00040000L
    #define WS_EX_LAYERED           0x00080000L
    #define WS_EX_OVERLAPPEDWINDOW  (WS_EX_WINDOWEDGE | WS_EX_CLIENTEDGE)
    #define WS_EX_PALETTEWINDOW     (WS_EX_WINDOWEDGE | WS_EX_TOOLWINDOW | WS_EX_TOPMOST)

    /* Class styles */

    #define CS_VREDRAW          0x0001
    #define CS_HREDRAW          0x0002
    #define CS_DBLCLKS          0x0008
    #define CS_OWNDC            0x0020
    #define CS_CLASSDC          0x0040
    #define CS_PARENTDC         0x0080
    #define CS_NOCLOSE          0x0200
    #define CS_SAVEBITS         0x0800
    #define CS_BYTEALIGNCLIENT  0x1000
    #define CS_BYTEALIGNWINDOW  0x2000
    #define CS_GLOBALCLASS      0x4000

    #define CS_IME              0x00010000

    /* Predefined Clipboard Formats */

    #define CF_TEXT             1
    #define CF_BITMAP           2
    #define CF_METAFILEPICT     3
    #define CF_SYLK             4
    #define CF_DIF              5
    #define CF_TIFF             6
    #define CF_OEMTEXT          7
    #define CF_DIB              8
    #define CF_PALETTE          9
    #define CF_PENDATA          10
    #define CF_RIFF             11
    #define CF_WAVE             12
    #define CF_UNICODETEXT      13
    #define CF_ENHMETAFILE      14
    #define CF_HDROP            15
    #define CF_LOCALE           16
    #define CF_MAX              17
    #define CF_OWNERDISPLAY     0x0080
    #define CF_DSPTEXT          0x0081
    #define CF_DSPBITMAP        0x0082
    #define CF_DSPMETAFILEPICT  0x0083
    #define CF_DSPENHMETAFILE   0x008E

    /* "Private" formats don't get GlobalFree()'d */

    #define CF_PRIVATEFIRST     0x0200
    #define CF_PRIVATELAST      0x02FF

    /* "GDIOBJ" formats do get DeleteObject()'d */

    #define CF_GDIOBJFIRST      0x0300
    #define CF_GDIOBJLAST       0x03FF

    /* Menu flags for Add/Check/EnableMenuItem() */

    #define MF_INSERT           0x00000000L
    #define MF_CHANGE           0x00000080L
    #define MF_APPEND           0x00000100L
    #define MF_DELETE           0x00000200L
    #define MF_REMOVE           0x00001000L

    #define MF_BYCOMMAND        0x00000000L
    #define MF_BYPOSITION       0x00000400L

    #define MF_SEPARATOR        0x00000800L

    #define MF_ENABLED          0x00000000L
    #define MF_GRAYED           0x00000001L
    #define MF_DISABLED         0x00000002L

    #define MF_UNCHECKED        0x00000000L
    #define MF_CHECKED          0x00000008L
    #define MF_USECHECKBITMAPS  0x00000200L

    #define MF_STRING           0x00000000L
    #define MF_BITMAP           0x00000004L
    #define MF_OWNERDRAW        0x00000100L

    #define MF_POPUP            0x00000010L
    #define MF_MENUBARBREAK     0x00000020L
    #define MF_MENUBREAK        0x00000040L

    #define MF_UNHILITE         0x00000000L
    #define MF_HILITE           0x00000080L

    #define MF_DEFAULT          0x00001000L
    #define MF_SYSMENU          0x00002000L
    #define MF_HELP             0x00004000L
    #define MF_RIGHTJUSTIFY     0x00004000L

    #define MF_MOUSESELECT      0x00008000L
    #define MF_END              0x00000080L

    #define MFT_STRING          MF_STRING
    #define MFT_BITMAP          MF_BITMAP
    #define MFT_MENUBARBREAK    MF_MENUBARBREAK
    #define MFT_MENUBREAK       MF_MENUBREAK
    #define MFT_OWNERDRAW       MF_OWNERDRAW
    #define MFT_RADIOCHECK      0x00000200L
    #define MFT_SEPARATOR       MF_SEPARATOR
    #define MFT_RIGHTORDER      0x00002000L
    #define MFT_RIGHTJUSTIFY    MF_RIGHTJUSTIFY

    /* Menu flags for Add/Check/EnableMenuItem() */

    #define MFS_GRAYED          0x00000003L
    #define MFS_DISABLED        MFS_GRAYED
    #define MFS_CHECKED         MF_CHECKED
    #define MFS_HILITE          MF_HILITE
    #define MFS_ENABLED         MF_ENABLED
    #define MFS_UNCHECKED       MF_UNCHECKED
    #define MFS_UNHILITE        MF_UNHILITE
    #define MFS_DEFAULT         MF_DEFAULT
    #define MFS_MASK            0x0000108BL
    #define MFS_HOTTRACKDRAWN   0x10000000L
    #define MFS_CACHEDBMP       0x20000000L
    #define MFS_BOTTOMGAPDROP   0x40000000L
    #define MFS_TOPGAPDROP      0x80000000L
    #define MFS_GAPDROP         0xC0000000L

    #define MF_END              0x00000080L

    /* System Menu Command Values */

    #define SC_SIZE             0xF000
    #define SC_MOVE             0xF010
    #define SC_MINIMIZE         0xF020
    #define SC_MAXIMIZE         0xF030
    #define SC_NEXTWINDOW       0xF040
    #define SC_PREVWINDOW       0xF050
    #define SC_CLOSE            0xF060
    #define SC_VSCROLL          0xF070
    #define SC_HSCROLL          0xF080
    #define SC_MOUSEMENU        0xF090
    #define SC_KEYMENU          0xF100
    #define SC_ARRANGE          0xF110
    #define SC_RESTORE          0xF120
    #define SC_TASKLIST         0xF130
    #define SC_SCREENSAVE       0xF140
    #define SC_HOTKEY           0xF150
    #define SC_DEFAULT          0xF160
    #define SC_MONITORPOWER     0xF170
    #define SC_CONTEXTHELP      0xF180
    #define SC_SEPARATOR        0xF00F

    /* Obsolete names */

    #define SC_ICON         SC_MINIMIZE
    #define SC_ZOOM         SC_MAXIMIZE

    /* OEM Resource Ordinal Numbers */

    #define OBM_CLOSE           32754
    #define OBM_UPARROW         32753
    #define OBM_DNARROW         32752
    #define OBM_RGARROW         32751
    #define OBM_LFARROW         32750
    #define OBM_REDUCE          32749
    #define OBM_ZOOM            32748
    #define OBM_RESTORE         32747
    #define OBM_REDUCED         32746
    #define OBM_ZOOMD           32745
    #define OBM_RESTORED        32744
    #define OBM_UPARROWD        32743
    #define OBM_DNARROWD        32742
    #define OBM_RGARROWD        32741
    #define OBM_LFARROWD        32740
    #define OBM_MNARROW         32739
    #define OBM_COMBO           32738
    #define OBM_UPARROWI        32737
    #define OBM_DNARROWI        32736
    #define OBM_RGARROWI        32735
    #define OBM_LFARROWI        32734

    #define OBM_OLD_CLOSE       32767
    #define OBM_SIZE            32766
    #define OBM_OLD_UPARROW     32765
    #define OBM_OLD_DNARROW     32764
    #define OBM_OLD_RGARROW     32763
    #define OBM_OLD_LFARROW     32762
    #define OBM_BTSIZE          32761
    #define OBM_CHECK           32760
    #define OBM_CHECKBOXES      32759
    #define OBM_BTNCORNERS      32758
    #define OBM_OLD_REDUCE      32757
    #define OBM_OLD_ZOOM        32756
    #define OBM_OLD_RESTORE     32755

    #define OCR_NORMAL          32512
    #define OCR_IBEAM           32513
    #define OCR_WAIT            32514
    #define OCR_CROSS           32515
    #define OCR_UP              32516
    #define OCR_SIZE            32640
    #define OCR_ICON            32641
    #define OCR_SIZENWSE        32642
    #define OCR_SIZENESW        32643
    #define OCR_SIZEWE          32644
    #define OCR_SIZENS          32645
    #define OCR_SIZEALL         32646
    #define OCR_ICOCUR          32647
    #define OCR_NO              32648
    #define OCR_HAND            32649
    #define OCR_APPSTARTING     32650

    #define OIC_SAMPLE          32512
    #define OIC_HAND            32513
    #define OIC_QUES            32514
    #define OIC_BANG            32515
    #define OIC_NOTE            32516
    #define OIC_WINLOGO         32517
    #define OIC_WARNING         OIC_BANG
    #define OIC_ERROR           OIC_HAND
    #define OIC_INFORMATION     OIC_NOTE

    /* Standard Icon IDs */

    #define IDI_APPLICATION     32512
    #define IDI_HAND            32513
    #define IDI_QUESTION        32514
    #define IDI_EXCLAMATION     32515
    #define IDI_ASTERISK        32516
    #define IDI_WINLOGO         32517

    #define IDI_WARNING     IDI_EXCLAMATION
    #define IDI_ERROR       IDI_HAND
    #define IDI_INFORMATION IDI_ASTERISK

    /* Dialog Box Command IDs */

    #define IDOK                1
    #define IDCANCEL            2
    #define IDABORT             3
    #define IDRETRY             4
    #define IDIGNORE            5
    #define IDYES               6
    #define IDNO                7
    #define IDCLOSE             8
    #define IDHELP              9

    /* Edit Control Styles */

    #define ES_LEFT             0x0000L
    #define ES_CENTER           0x0001L
    #define ES_RIGHT            0x0002L
    #define ES_MULTILINE        0x0004L
    #define ES_UPPERCASE        0x0008L
    #define ES_LOWERCASE        0x0010L
    #define ES_PASSWORD         0x0020L
    #define ES_AUTOVSCROLL      0x0040L
    #define ES_AUTOHSCROLL      0x0080L
    #define ES_NOHIDESEL        0x0100L
    #define ES_OEMCONVERT       0x0400L
    #define ES_READONLY         0x0800L
    #define ES_WANTRETURN       0x1000L
    #define ES_NUMBER           0x2000L

    /* Edit Control Messages */

    #define EM_GETSEL               0x00B0
    #define EM_SETSEL               0x00B1
    #define EM_GETRECT              0x00B2
    #define EM_SETRECT              0x00B3
    #define EM_SETRECTNP            0x00B4
    #define EM_SCROLL               0x00B5
    #define EM_LINESCROLL           0x00B6
    #define EM_SCROLLCARET          0x00B7
    #define EM_GETMODIFY            0x00B8
    #define EM_SETMODIFY            0x00B9
    #define EM_GETLINECOUNT         0x00BA
    #define EM_LINEINDEX            0x00BB
    #define EM_SETHANDLE            0x00BC
    #define EM_GETHANDLE            0x00BD
    #define EM_GETTHUMB             0x00BE
    #define EM_LINELENGTH           0x00C1
    #define EM_REPLACESEL           0x00C2
    #define EM_GETLINE              0x00C4
    #define EM_LIMITTEXT            0x00C5
    #define EM_CANUNDO              0x00C6
    #define EM_UNDO                 0x00C7
    #define EM_FMTLINES             0x00C8
    #define EM_LINEFROMCHAR         0x00C9
    #define EM_SETTABSTOPS          0x00CB
    #define EM_SETPASSWORDCHAR      0x00CC
    #define EM_EMPTYUNDOBUFFER      0x00CD
    #define EM_GETFIRSTVISIBLELINE  0x00CE
    #define EM_SETREADONLY          0x00CF
    #define EM_SETWORDBREAKPROC     0x00D0
    #define EM_GETWORDBREAKPROC     0x00D1
    #define EM_GETPASSWORDCHAR      0x00D2
    #define EM_SETMARGINS           0x00D3
    #define EM_GETMARGINS           0x00D4
    #define EM_SETLIMITTEXT         EM_LIMITTEXT
    #define EM_GETLIMITTEXT         0x00D5
    #define EM_POSFROMCHAR          0x00D6
    #define EM_CHARFROMPOS          0x00D7

    #define EM_SETIMESTATUS         0x00D8
    #define EM_GETIMESTATUS         0x00D9

    /* Button Control Styles */

    #define BS_PUSHBUTTON       0x00000000L
    #define BS_DEFPUSHBUTTON    0x00000001L
    #define BS_CHECKBOX         0x00000002L
    #define BS_AUTOCHECKBOX     0x00000003L
    #define BS_RADIOBUTTON      0x00000004L
    #define BS_3STATE           0x00000005L
    #define BS_AUTO3STATE       0x00000006L
    #define BS_GROUPBOX         0x00000007L
    #define BS_USERBUTTON       0x00000008L
    #define BS_AUTORADIOBUTTON  0x00000009L
    #define BS_OWNERDRAW        0x0000000BL
    #define BS_LEFTTEXT         0x00000020L
    #define BS_TEXT             0x00000000L
    #define BS_ICON             0x00000040L
    #define BS_BITMAP           0x00000080L
    #define BS_LEFT             0x00000100L
    #define BS_RIGHT            0x00000200L
    #define BS_CENTER           0x00000300L
    #define BS_TOP              0x00000400L
    #define BS_BOTTOM           0x00000800L
    #define BS_VCENTER          0x00000C00L
    #define BS_PUSHLIKE         0x00001000L
    #define BS_MULTILINE        0x00002000L
    #define BS_NOTIFY           0x00004000L
    #define BS_FLAT             0x00008000L
    #define BS_RIGHTBUTTON      BS_LEFTTEXT

    /* User Button Notification Codes */

    #define BN_CLICKED          0
    #define BN_PAINT            1
    #define BN_HILITE           2
    #define BN_UNHILITE         3
    #define BN_DISABLE          4
    #define BN_DOUBLECLICKED    5
    #define BN_PUSHED           BN_HILITE
    #define BN_UNPUSHED         BN_UNHILITE
    #define BN_DBLCLK           BN_DOUBLECLICKED
    #define BN_SETFOCUS         6
    #define BN_KILLFOCUS        7

    /* Button Control Messages */

    #define BM_GETCHECK        0x00F0
    #define BM_SETCHECK        0x00F1
    #define BM_GETSTATE        0x00F2
    #define BM_SETSTATE        0x00F3
    #define BM_SETSTYLE        0x00F4
    #define BM_CLICK           0x00F5
    #define BM_GETIMAGE        0x00F6
    #define BM_SETIMAGE        0x00F7

    #define BST_UNCHECKED      0x0000
    #define BST_CHECKED        0x0001
    #define BST_INDETERMINATE  0x0002
    #define BST_PUSHED         0x0004
    #define BST_FOCUS          0x0008

    /* Static Control Constants */

    #define SS_LEFT             0x00000000L
    #define SS_CENTER           0x00000001L
    #define SS_RIGHT            0x00000002L
    #define SS_ICON             0x00000003L
    #define SS_BLACKRECT        0x00000004L
    #define SS_GRAYRECT         0x00000005L
    #define SS_WHITERECT        0x00000006L
    #define SS_BLACKFRAME       0x00000007L
    #define SS_GRAYFRAME        0x00000008L
    #define SS_WHITEFRAME       0x00000009L
    #define SS_USERITEM         0x0000000AL
    #define SS_SIMPLE           0x0000000BL
    #define SS_LEFTNOWORDWRAP   0x0000000CL
    #define SS_OWNERDRAW        0x0000000DL
    #define SS_BITMAP           0x0000000EL
    #define SS_ENHMETAFILE      0x0000000FL
    #define SS_ETCHEDHORZ       0x00000010L
    #define SS_ETCHEDVERT       0x00000011L
    #define SS_ETCHEDFRAME      0x00000012L
    #define SS_TYPEMASK         0x0000001FL
    #define SS_NOPREFIX         0x00000080L
    #define SS_NOTIFY           0x00000100L
    #define SS_CENTERIMAGE      0x00000200L
    #define SS_RIGHTJUST        0x00000400L
    #define SS_REALSIZEIMAGE    0x00000800L
    #define SS_SUNKEN           0x00001000L
    #define SS_ENDELLIPSIS      0x00004000L
    #define SS_PATHELLIPSIS     0x00008000L
    #define SS_WORDELLIPSIS     0x0000C000L
    #define SS_ELLIPSISMASK     0x0000C000L

    /* Dialog Styles */

    #define DS_ABSALIGN         0x01L
    #define DS_SYSMODAL         0x02L
    #define DS_LOCALEDIT        0x20L
    #define DS_SETFONT          0x40L
    #define DS_MODALFRAME       0x80L
    #define DS_NOIDLEMSG        0x100L
    #define DS_SETFOREGROUND    0x200L

    #define DS_3DLOOK           0x0004L
    #define DS_FIXEDSYS         0x0008L
    #define DS_NOFAILCREATE     0x0010L
    #define DS_CONTROL          0x0400L
    #define DS_CENTER           0x0800L
    #define DS_CENTERMOUSE      0x1000L
    #define DS_CONTEXTHELP      0x2000L

    /* Listbox Styles */

    #define LBS_NOTIFY            0x0001L
    #define LBS_SORT              0x0002L
    #define LBS_NOREDRAW          0x0004L
    #define LBS_MULTIPLESEL       0x0008L
    #define LBS_OWNERDRAWFIXED    0x0010L
    #define LBS_OWNERDRAWVARIABLE 0x0020L
    #define LBS_HASSTRINGS        0x0040L
    #define LBS_USETABSTOPS       0x0080L
    #define LBS_NOINTEGRALHEIGHT  0x0100L
    #define LBS_MULTICOLUMN       0x0200L
    #define LBS_WANTKEYBOARDINPUT 0x0400L
    #define LBS_EXTENDEDSEL       0x0800L
    #define LBS_DISABLENOSCROLL   0x1000L
    #define LBS_NODATA            0x2000L
    #define LBS_NOSEL             0x4000L
    #define LBS_STANDARD          (LBS_NOTIFY | LBS_SORT | WS_VSCROLL | WS_BORDER)

    /* Combo Box styles */

    #define CBS_SIMPLE              0x0001L
    #define CBS_DROPDOWN            0x0002L
    #define CBS_DROPDOWNLIST        0x0003L
    #define CBS_OWNERDRAWFIXED      0x0010L
    #define CBS_OWNERDRAWVARIABLE   0x0020L
    #define CBS_AUTOHSCROLL         0x0040L
    #define CBS_OEMCONVERT          0x0080L
    #define CBS_SORT                0x0100L
    #define CBS_HASSTRINGS          0x0200L
    #define CBS_NOINTEGRALHEIGHT    0x0400L
    #define CBS_DISABLENOSCROLL     0x0800L
    #define CBS_UPPERCASE           0x2000L
    #define CBS_LOWERCASE           0x4000L

    /* Scroll Bar Styles */

    #define SBS_HORZ                    0x0000L
    #define SBS_VERT                    0x0001L
    #define SBS_TOPALIGN                0x0002L
    #define SBS_LEFTALIGN               0x0002L
    #define SBS_BOTTOMALIGN             0x0004L
    #define SBS_RIGHTALIGN              0x0004L
    #define SBS_SIZEBOXTOPLEFTALIGN     0x0002L
    #define SBS_SIZEBOXBOTTOMRIGHTALIGN 0x0004L
    #define SBS_SIZEBOX                 0x0008L
    #define SBS_SIZEGRIP                0x0010L

    /* Commands to pass to WinHelp() */

    #define HELP_CONTEXT      0x0001L
    #define HELP_QUIT         0x0002L
    #define HELP_INDEX        0x0003L
    #define HELP_CONTENTS     0x0003L
    #define HELP_HELPONHELP   0x0004L
    #define HELP_SETINDEX     0x0005L
    #define HELP_SETCONTENTS  0x0005L
    #define HELP_CONTEXTPOPUP 0x0008L
    #define HELP_FORCEFILE    0x0009L
    #define HELP_KEY          0x0101L
    #define HELP_COMMAND      0x0102L
    #define HELP_PARTIALKEY   0x0105L
    #define HELP_MULTIKEY     0x0201L
    #define HELP_SETWINPOS    0x0203L
    #define HELP_CONTEXTMENU  0x000a
    #define HELP_FINDER       0x000b
    #define HELP_WM_HELP      0x000c
    #define HELP_SETPOPUP_POS 0x000d

    #define HELP_TCARD              0x8000
    #define HELP_TCARD_DATA         0x0010
    #define HELP_TCARD_OTHER_CALLER 0x0011

    /* These are in winhelp.h in Win95. */

    #define IDH_NO_HELP                     28440
    #define IDH_MISSING_CONTEXT             28441
    #define IDH_GENERIC_HELP_BUTTON         28442
    #define IDH_OK                          28443
    #define IDH_CANCEL                      28444
    #define IDH_HELP                        28445


    #define IDC_STATIC                         -1
    #define IDC_EDIT1                        3000
    #define IDC_EDIT2                        3001
    #define IDC_BUTTON1                      3002
    #define IDC_BUTTON2                      3003
    #define IDC_USER1                        3000

    #define LANG_NEUTRAL                     0x0000
    #define LANG_BULGARIAN                   0x0002
    #define LANG_CHINESE                     0x0004
    #define LANG_CROATIAN                    0x001a
    #define LANG_CZECH                       0x0005
    #define LANG_DANISH                      0x0006
    #define LANG_DUTCH                       0x0013
    #define LANG_ENGLISH                     0x0009
    #define LANG_FINNISH                     0x000b
    #define LANG_FRENCH                      0x000c
    #define LANG_GERMAN                      0x0007
    #define LANG_GREEK                       0x0008
    #define LANG_HUNGARIAN                   0x000e
    #define LANG_ICELANDIC                   0x000f
    #define LANG_ITALIAN                     0x0010
    #define LANG_JAPANESE                    0x0011
    #define LANG_KOREAN                      0x0012
    #define LANG_NORWEGIAN                   0x0014
    #define LANG_POLISH                      0x0015
    #define LANG_PORTUGUESE                  0x0016
    #define LANG_ROMANIAN                    0x0018
    #define LANG_RUSSIAN                     0x0019
    #define LANG_SLOVAK                      0x001b
    #define LANG_SLOVENIAN                   0x0024
    #define LANG_SPANISH                     0x000a
    #define LANG_SWEDISH                     0x001d
    #define LANG_TURKISH                     0x001f

    #define SUBLANG_NEUTRAL                  0x0000    /* language neutral */
    #define SUBLANG_DEFAULT                  0x0001    /* user default */
    #define SUBLANG_SYS_DEFAULT              0x0002    /* system default */
    #define SUBLANG_CHINESE_TRADITIONAL      0x0001    /* Chinese (Taiwan) */
    #define SUBLANG_CHINESE_SIMPLIFIED       0x0002    /* Chinese (PR China) */
    #define SUBLANG_CHINESE_HONGKONG         0x0003    /* Chinese (Hong Kong) */
    #define SUBLANG_CHINESE_SINGAPORE        0x0004    /* Chinese (Singapore) */
    #define SUBLANG_DUTCH                    0x0001    /* Dutch */
    #define SUBLANG_DUTCH_BELGIAN            0x0002    /* Dutch (Belgian) */
    #define SUBLANG_ENGLISH_US               0x0001    /* English (USA) */
    #define SUBLANG_ENGLISH_UK               0x0002    /* English (UK) */
    #define SUBLANG_ENGLISH_AUS              0x0003    /* English (Australian) */
    #define SUBLANG_ENGLISH_CAN              0x0004    /* English (Canadian) */
    #define SUBLANG_ENGLISH_NZ               0x0005    /* English (New Zealand) */
    #define SUBLANG_ENGLISH_EIRE             0x0006    /* English (Irish) */
    #define SUBLANG_FRENCH                   0x0001    /* French */
    #define SUBLANG_FRENCH_BELGIAN           0x0002    /* French (Belgian) */
    #define SUBLANG_FRENCH_CANADIAN          0x0003    /* French (Canadian) */
    #define SUBLANG_FRENCH_SWISS             0x0004    /* French (Swiss) */
    #define SUBLANG_GERMAN                   0x0001    /* German */
    #define SUBLANG_GERMAN_SWISS             0x0002    /* German (Swiss) */
    #define SUBLANG_GERMAN_AUSTRIAN          0x0003    /* German (Austrian) */
    #define SUBLANG_ITALIAN                  0x0001    /* Italian */
    #define SUBLANG_ITALIAN_SWISS            0x0002    /* Italian (Swiss) */
    #define SUBLANG_NORWEGIAN_BOKMAL         0x0001    /* Norwegian (Bokmal) */
    #define SUBLANG_NORWEGIAN_NYNORSK        0x0002    /* Norwegian (Nynorsk) */
    #define SUBLANG_PORTUGUESE               0x0002    /* Portuguese */
    #define SUBLANG_PORTUGUESE_BRAZILIAN     0x0001    /* Portuguese (Brazilian) */
    #define SUBLANG_SPANISH                  0x0001    /* Spanish (Castilian) */
    #define SUBLANG_SPANISH_MEXICAN          0x0002    /* Spanish (Mexican) */
    #define SUBLANG_SPANISH_MODERN           0x0003    /* Spanish (Modern) */


    /* Manifest IDs */

    #define RT_MANIFEST                                           24
    #define CREATEPROCESS_MANIFEST_RESOURCE_ID                    1
    #define ISOLATIONAWARE_MANIFEST_RESOURCE_ID                   2
    #define ISOLATIONAWARE_NOSTATICIMPORT_MANIFEST_RESOURCE_ID    3
    #define MINIMUM_RESERVED_MANIFEST_RESOURCE_ID                 1
    #define MAXIMUM_RESERVED_MANIFEST_RESOURCE_ID                 16


    /* Version VER.H */

    #define VS_FFI_SIGNATURE            0xFEEF04BDL
    #define VS_FFI_STRUCVERSION         0x00010000L
    #define VS_FFI_FILEFLAGSMASK        0x0000003FL

    /* VS_VERSION.dwFileFlags */
    #define VS_FF_DEBUG                 0x1
    #define VS_FF_PRERELEASE            0x2
    #define VS_FF_PATCHED               0x4
    #define VS_FF_PRIVATEBUILD          0x8
    #define VS_FF_INFOINFERRED          0x10
    #define VS_FF_SPECIALBUILD          0x20

    /* VS_VERSION.dwFileOS */
    #define VOS_UNKNOWN                 0x0
    #define VOS_DOS                     0x10000
    #define VOS_OS216                   0x20000
    #define VOS_OS232                   0x30000
    #define VOS_NT                      0x40000

    #define VOS__BASE                   0x0
    #define VOS__WINDOWS16              0x1
    #define VOS__PM16                   0x2
    #define VOS__PM32                   0x3
    #define VOS__WINDOWS32              0x4

    #define VOS_DOS_WINDOWS16           0x10001
    #define VOS_DOS_WINDOWS32           0x10004
    #define VOS_OS216_PM16              0x20002
    #define VOS_OS232_PM32              0x30003
    #define VOS_NT_WINDOWS32            0x40004

    /* VS_VERSION.dwFileType */
    #define VFT_UNKNOWN                 0x0
    #define VFT_APP                     0x1
    #define VFT_DLL                     0x2
    #define VFT_DRV                     0x3
    #define VFT_FONT                    0x4
    #define VFT_VXD                     0x5
    #define VFT_STATIC_LIB              0x7

    /* VS_VERSION.dwFileSubtype for VFT_WINDOWS_DRV */
    #define VFT2_UNKNOWN                0x0
    #define VFT2_DRV_PRINTER            0x1
    #define VFT2_DRV_KEYBOARD           0x2
    #define VFT2_DRV_LANGUAGE           0x3
    #define VFT2_DRV_DISPLAY            0x4
    #define VFT2_DRV_MOUSE              0x5
    #define VFT2_DRV_NETWORK            0x6
    #define VFT2_DRV_SYSTEM             0x7
    #define VFT2_DRV_INSTALLABLE        0x8
    #define VFT2_DRV_SOUND              0x9
    #define VFT2_DRV_COMM               0xA

    #define VFT2_FONT_RASTER            0x1
    #define VFT2_FONT_VECTOR            0x2
    #define VFT2_FONT_TRUETYPE          0x3

    #define RLS                         0x0
    #define DBG                         0x1

    #define EXE                         0x0
    #define DLL                         0x1
    #define LIB                         0x2

    #define IMAGE                       2110

