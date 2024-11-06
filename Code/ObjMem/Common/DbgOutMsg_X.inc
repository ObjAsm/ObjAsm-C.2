; ==================================================================================================
; Title:      DbgOutMsg_X.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017.
;               - First release.
;               - Bitness independent code.
; ==================================================================================================


DOM struc
  ID    DWORD     ?
  pStr  POINTER   ?
DOM ends

.const
DbgWndMsgTable \
  DOM {WM_NULL,                           $OfsTStrA("WM_NULL")}                           ;0000
  DOM {WM_CREATE,                         $OfsTStrA("WM_CREATE")}                         ;0001
  DOM {WM_DESTROY,                        $OfsTStrA("WM_DESTROY")}                        ;0002
  DOM {WM_MOVE,                           $OfsTStrA("WM_MOVE")}                           ;0003
  DOM {WM_SIZE,                           $OfsTStrA("WM_SIZE")}                           ;0005
  DOM {WM_ACTIVATE,                       $OfsTStrA("WM_ACTIVATE")}                       ;0006
  DOM {WM_SETFOCUS,                       $OfsTStrA("WM_SETFOCUS")}                       ;0007
  DOM {WM_KILLFOCUS,                      $OfsTStrA("WM_KILLFOCUS")}                      ;0008

  DOM {WM_ENABLE,                         $OfsTStrA("WM_ENABLE")}                         ;000A
  DOM {WM_SETREDRAW,                      $OfsTStrA("WM_SETREDRAW")}                      ;000B
  DOM {WM_SETTEXT,                        $OfsTStrA("WM_SETTEXT")}                        ;000C
  DOM {WM_GETTEXT,                        $OfsTStrA("WM_GETTEXT")}                        ;000D
  DOM {WM_GETTEXTLENGTH,                  $OfsTStrA("WM_GETTEXTLENGTH")}                  ;000E
  DOM {WM_PAINT,                          $OfsTStrA("WM_PAINT")}                          ;000F
  DOM {WM_CLOSE,                          $OfsTStrA("WM_CLOSE")}                          ;0010
  DOM {WM_QUERYENDSESSION,                $OfsTStrA("WM_QUERYENDSESSION")}                ;0011
  DOM {WM_QUIT,                           $OfsTStrA("WM_QUIT")}                           ;0012
  DOM {WM_QUERYOPEN,                      $OfsTStrA("WM_QUERYOPEN")}                      ;0013
  DOM {WM_ERASEBKGND,                     $OfsTStrA("WM_ERASEBKGND")}                     ;0014
  DOM {WM_SYSCOLORCHANGE,                 $OfsTStrA("WM_SYSCOLORCHANGE")}                 ;0015
  DOM {WM_ENDSESSION,                     $OfsTStrA("WM_ENDSESSION")}                     ;0016

  DOM {WM_SHOWWINDOW,                     $OfsTStrA("WM_SHOWWINDOW")}                     ;0018

  DOM {WM_WININICHANGE,                   $OfsTStrA("WM_WININICHANGE")}                   ;001A
  DOM {WM_DEVMODECHANGE,                  $OfsTStrA("WM_DEVMODECHANGE")}                  ;001B
  DOM {WM_ACTIVATEAPP,                    $OfsTStrA("WM_ACTIVATEAPP")}                    ;001C
  DOM {WM_FONTCHANGE,                     $OfsTStrA("WM_FONTCHANGE")}                     ;001D
  DOM {WM_TIMECHANGE,                     $OfsTStrA("WM_TIMECHANGE")}                     ;001E
  DOM {WM_CANCELMODE,                     $OfsTStrA("WM_CANCELMODE")}                     ;001F
  DOM {WM_SETCURSOR,                      $OfsTStrA("WM_SETCURSOR")}                      ;0020
  DOM {WM_MOUSEACTIVATE,                  $OfsTStrA("WM_MOUSEACTIVATE")}                  ;0021
  DOM {WM_CHILDACTIVATE,                  $OfsTStrA("WM_CHILDACTIVATE")}                  ;0022
  DOM {WM_QUEUESYNC,                      $OfsTStrA("WM_QUEUESYNC")}                      ;0023
  DOM {WM_GETMINMAXINFO,                  $OfsTStrA("WM_GETMINMAXINFO")}                  ;0024

  DOM {WM_PAINTICON,                      $OfsTStrA("WM_PAINTICON")}                      ;0026
  DOM {WM_ICONERASEBKGND,                 $OfsTStrA("WM_ICONERASEBKGND")}                 ;0027
  DOM {WM_NEXTDLGCTL,                     $OfsTStrA("WM_NEXTDLGCTL")}                     ;0028

  DOM {WM_SPOOLERSTATUS,                  $OfsTStrA("WM_SPOOLERSTATUS")}                  ;002A
  DOM {WM_DRAWITEM,                       $OfsTStrA("WM_DRAWITEM")}                       ;002B
  DOM {WM_MEASUREITEM,                    $OfsTStrA("WM_MEASUREITEM")}                    ;002C
  DOM {WM_DELETEITEM,                     $OfsTStrA("WM_DELETEITEM")}                     ;002D
  DOM {WM_VKEYTOITEM,                     $OfsTStrA("WM_VKEYTOITEM")}                     ;002E
  DOM {WM_CHARTOITEM,                     $OfsTStrA("WM_CHARTOITEM")}                     ;002F
  DOM {WM_SETFONT,                        $OfsTStrA("WM_SETFONT")}                        ;0030
  DOM {WM_GETFONT,                        $OfsTStrA("WM_GETFONT")}                        ;0031
  DOM {WM_SETHOTKEY,                      $OfsTStrA("WM_SETHOTKEY")}                      ;0032
  DOM {WM_GETHOTKEY,                      $OfsTStrA("WM_GETHOTKEY")}                      ;0033

  DOM {WM_QUERYDRAGICON,                  $OfsTStrA("WM_QUERYDRAGICON")}                  ;0037

  DOM {WM_COMPAREITEM,                    $OfsTStrA("WM_COMPAREITEM")}                    ;0039

  DOM {WM_GETOBJECT,                      $OfsTStrA("WM_GETOBJECT")}                      ;003D

  DOM {WM_COMPACTING,                     $OfsTStrA("WM_COMPACTING")}                     ;0041
  DOM {42h,                               $OfsTStrA("WM_OTHERWINDOWCREATED")}             ;0042
  DOM {43h,                               $OfsTStrA("WM_OTHERWINDOWDESTROYED")}           ;0043
  DOM {WM_COMMNOTIFY,                     $OfsTStrA("WM_COMMNOTIFY")}                     ;0044

  DOM {WM_WINDOWPOSCHANGING,              $OfsTStrA("WM_WINDOWPOSCHANGING")}              ;0046
  DOM {WM_WINDOWPOSCHANGED,               $OfsTStrA("WM_WINDOWPOSCHANGED")}               ;0047
  DOM {WM_POWER,                          $OfsTStrA("WM_POWER")}                          ;0048

  DOM {WM_COPYDATA,                       $OfsTStrA("WM_COPYDATA")}                       ;004A
  DOM {WM_CANCELJOURNAL,                  $OfsTStrA("WM_CANCELJOURNAL")}                  ;004B

  DOM {WM_NOTIFY,                         $OfsTStrA("WM_NOTIFY")}                         ;004E

  DOM {WM_INPUTLANGCHANGEREQUEST,         $OfsTStrA("WM_INPUTLANGCHANGEREQ")}             ;0050
  DOM {WM_INPUTLANGCHANGE,                $OfsTStrA("WM_INPUTLANGCHANGE")}                ;0051
  DOM {WM_TCARD,                          $OfsTStrA("WM_TCARD")}                          ;0052
  DOM {WM_HELP,                           $OfsTStrA("WM_HELP")}                           ;0053
  DOM {WM_USERCHANGED,                    $OfsTStrA("WM_USERCHANGED")}                    ;0054
  DOM {WM_NOTIFYFORMAT,                   $OfsTStrA("WM_NOTIFYFORMAT")}                   ;0055

  DOM {WM_CONTEXTMENU,                    $OfsTStrA("WM_CONTEXTMENU")}                    ;007B
  DOM {WM_STYLECHANGING,                  $OfsTStrA("WM_STYLECHANGING")}                  ;007C
  DOM {WM_STYLECHANGED,                   $OfsTStrA("WM_STYLECHANGED")}                   ;007D
  DOM {WM_DISPLAYCHANGE,                  $OfsTStrA("WM_DISPLAYCHANGE")}                  ;007E
  DOM {WM_GETICON,                        $OfsTStrA("WM_GETICON")}                        ;007F
  DOM {WM_SETICON,                        $OfsTStrA("WM_SETICON")}                        ;0080
  DOM {WM_NCCREATE,                       $OfsTStrA("WM_NCCREATE")}                       ;0081
  DOM {WM_NCDESTROY,                      $OfsTStrA("WM_NCDESTROY")}                      ;0082
  DOM {WM_NCCALCSIZE,                     $OfsTStrA("WM_NCCALCSIZE")}                     ;0083
  DOM {WM_NCHITTEST,                      $OfsTStrA("WM_NCHITTEST")}                      ;0084
  DOM {WM_NCPAINT,                        $OfsTStrA("WM_NCPAINT")}                        ;0085
  DOM {WM_NCACTIVATE,                     $OfsTStrA("WM_NCACTIVATE")}                     ;0086
  DOM {WM_GETDLGCODE,                     $OfsTStrA("WM_GETDLGCODE")}                     ;0087
  DOM {WM_SYNCPAINT,                      $OfsTStrA("WM_SYNCPAINT")}                      ;0088

  DOM {90h,                               $OfsTStrA("WM_UAHDESTROYWINDOW")}               ;0090
  DOM {91h,                               $OfsTStrA("WM_UAHDRAWMENU")}                    ;0091
  DOM {92h,                               $OfsTStrA("WM_UAHDRAWMENUITEM")}                ;0092
  DOM {93h,                               $OfsTStrA("WM_UAHINITMENU")}                    ;0093
  DOM {94h,                               $OfsTStrA("WM_UAHMEASUREMENUITEM")}             ;0094
  DOM {95h,                               $OfsTStrA("WM_UAHNCPAINTMENUPOPUP")}            ;0095

  DOM {WM_NCMOUSEMOVE,                    $OfsTStrA("WM_NCMOUSEMOVE")}                    ;00A0
  DOM {WM_NCLBUTTONDOWN,                  $OfsTStrA("WM_NCLBUTTONDOWN")}                  ;00A1
  DOM {WM_NCLBUTTONUP,                    $OfsTStrA("WM_NCLBUTTONUP")}                    ;00A2
  DOM {WM_NCLBUTTONDBLCLK,                $OfsTStrA("WM_NCLBUTTONDBLCLK")}                ;00A3
  DOM {WM_NCRBUTTONDOWN,                  $OfsTStrA("WM_NCRBUTTONDOWN")}                  ;00A4
  DOM {WM_NCRBUTTONUP,                    $OfsTStrA("WM_NCRBUTTONUP")}                    ;00A5
  DOM {WM_NCRBUTTONDBLCLK,                $OfsTStrA("WM_NCRBUTTONDBLCLK")}                ;00A6
  DOM {WM_NCMBUTTONDOWN,                  $OfsTStrA("WM_NCMBUTTONDOWN")}                  ;00A7
  DOM {WM_NCMBUTTONUP,                    $OfsTStrA("WM_NCMBUTTONUP")}                    ;00A8
  DOM {WM_NCMBUTTONDBLCLK,                $OfsTStrA("WM_NCMBUTTONDBLCLK")}                ;00A9

  DOM {WM_NCXBUTTONDOWN,                  $OfsTStrA("WM_NCXBUTTONDOWN")}                  ;00AB
  DOM {WM_NCXBUTTONUP,                    $OfsTStrA("WM_NCXBUTTONUP")}                    ;00AC
  DOM {WM_NCXBUTTONDBLCLK,                $OfsTStrA("WM_NCXBUTTONDBLCLK")}                ;00AD

  DOM {EM_GETSEL,                         $OfsTStrA("EM_GETSEL")}                         ;00B0
  DOM {EM_SETSEL,                         $OfsTStrA("EM_SETSEL")}                         ;00B1
  DOM {EM_GETRECT,                        $OfsTStrA("EM_GETRECT")}                        ;00B2
  DOM {EM_SETRECT,                        $OfsTStrA("EM_SETRECT")}                        ;00B3
  DOM {EM_SETRECTNP,                      $OfsTStrA("EM_SETRECTNP")}                      ;00B4
  DOM {EM_SCROLL,                         $OfsTStrA("EM_SCROLL")}                         ;00B5
  DOM {EM_LINESCROLL,                     $OfsTStrA("EM_LINESCROLL")}                     ;00B6
  DOM {EM_SCROLLCARET,                    $OfsTStrA("EM_SCROLLCARET")}                    ;00B7
  DOM {EM_GETMODIFY,                      $OfsTStrA("EM_GETMODIFY")}                      ;00B8
  DOM {EM_SETMODIFY,                      $OfsTStrA("EM_SETMODIFY")}                      ;00B9
  DOM {EM_GETLINECOUNT,                   $OfsTStrA("EM_GETLINECOUNT")}                   ;00BA
  DOM {EM_LINEINDEX,                      $OfsTStrA("EM_LINEINDEX")}                      ;00BB
  DOM {EM_SETHANDLE,                      $OfsTStrA("EM_SETHANDLE")}                      ;00BC
  DOM {EM_GETHANDLE,                      $OfsTStrA("EM_GETHANDLE")}                      ;00BD
  DOM {EM_GETTHUMB,                       $OfsTStrA("EM_GETTHUMB")}                       ;00BE
  DOM {EM_LINELENGTH,                     $OfsTStrA("EM_LINELENGTH")}                     ;00C1
  DOM {EM_REPLACESEL,                     $OfsTStrA("EM_REPLACESEL")}                     ;00C2
  DOM {EM_GETLINE,                        $OfsTStrA("EM_GETLINE")}                        ;00C4
  DOM {EM_LIMITTEXT,                      $OfsTStrA("EM_LIMITTEXT")}                      ;00C5
  DOM {EM_CANUNDO,                        $OfsTStrA("EM_CANUNDO")}                        ;00C6
  DOM {EM_UNDO,                           $OfsTStrA("EM_UNDO")}                           ;00C7
  DOM {EM_FMTLINES,                       $OfsTStrA("EM_FMTLINES")}                       ;00C8
  DOM {EM_LINEFROMCHAR,                   $OfsTStrA("EM_LINEFROMCHAR")}                   ;00C9
  DOM {EM_SETTABSTOPS,                    $OfsTStrA("EM_SETTABSTOPS")}                    ;00CB
  DOM {EM_SETPASSWORDCHAR,                $OfsTStrA("EM_SETPASSWORDCHAR")}                ;00CC
  DOM {EM_EMPTYUNDOBUFFER,                $OfsTStrA("EM_EMPTYUNDOBUFFER")}                ;00CD
  DOM {EM_GETFIRSTVISIBLELINE,            $OfsTStrA("EM_GETFIRSTVISIBLELINE")}            ;00CE
  DOM {EM_SETREADONLY,                    $OfsTStrA("EM_SETREADONLY")}                    ;00CF
  DOM {EM_SETWORDBREAKPROC,               $OfsTStrA("EM_SETWORDBREAKPROC")}               ;00D0
  DOM {EM_GETWORDBREAKPROC,               $OfsTStrA("EM_GETWORDBREAKPROC")}               ;00D1
  DOM {EM_GETPASSWORDCHAR,                $OfsTStrA("EM_GETPASSWORDCHAR")}                ;00D2
  DOM {EM_SETMARGINS,                     $OfsTStrA("EM_SETMARGINS")}                     ;00D3
  DOM {EM_GETMARGINS,                     $OfsTStrA("EM_GETMARGINS")}                     ;00D4
  DOM {EM_GETLIMITTEXT,                   $OfsTStrA("EM_GETLIMITTEXT")}                   ;00D5
  DOM {EM_POSFROMCHAR,                    $OfsTStrA("EM_POSFROMCHAR")}                    ;00D6
  DOM {EM_CHARFROMPOS,                    $OfsTStrA("EM_CHARFROMPOS")}                    ;00D7
  DOM {EM_SETIMESTATUS,                   $OfsTStrA("EM_SETIMESTATUS")}                   ;00D8
  DOM {EM_GETIMESTATUS,                   $OfsTStrA("EM_GETIMESTATUS")}                   ;00D9

  DOM {SBM_SETSCROLLINFO,                 $OfsTStrA("SBM_SETSCROLLINFO")}                 ;00E9
  DOM {SBM_GETSCROLLINFO,                 $OfsTStrA("SBM_GETSCROLLINFO")}                 ;00EA

  DOM {WM_INPUT_DEVICE_CHANGE,            $OfsTStrA("WM_INPUT_DEVICE_CHANGE")}            ;00FE
  DOM {WM_INPUT,                          $OfsTStrA("WM_INPUT")}                          ;00FF

  DOM {WM_KEYDOWN,                        $OfsTStrA("WM_KEYDOWN")}                        ;0100
  DOM {WM_KEYUP,                          $OfsTStrA("WM_KEYUP")}                          ;0101
  DOM {WM_CHAR,                           $OfsTStrA("WM_CHAR")}                           ;0102
  DOM {WM_DEADCHAR,                       $OfsTStrA("WM_DEADCHAR")}                       ;0103
  DOM {WM_SYSKEYDOWN,                     $OfsTStrA("WM_SYSKEYDOWN")}                     ;0104
  DOM {WM_SYSKEYUP,                       $OfsTStrA("WM_SYSKEYUP")}                       ;0105
  DOM {WM_SYSCHAR,                        $OfsTStrA("WM_SYSCHAR")}                        ;0106
  DOM {WM_SYSDEADCHAR,                    $OfsTStrA("WM_SYSDEADCHAR")}                    ;0107
  DOM {WM_KEYLAST,                        $OfsTStrA("WM_KEYLAST or WM_CONVERTREQUESTEX")} ;0108
  DOM {WM_UNICHAR,                        $OfsTStrA("WM_UNICHAR")}                        ;0109

  DOM {WM_IME_STARTCOMPOSITION,           $OfsTStrA("WM_IME_STARTCOMPOSITION")}           ;010D
  DOM {WM_IME_ENDCOMPOSITION,             $OfsTStrA("WM_IME_ENDCOMPOSITION")}             ;010E
  DOM {WM_IME_COMPOSITION,                $OfsTStrA("WM_IME_COMPOSITION")}                ;010F
  DOM {WM_IME_KEYLAST,                    $OfsTStrA("WM_IME_KEYLAST")}                    ;010F
  DOM {WM_INITDIALOG,                     $OfsTStrA("WM_INITDIALOG")}                     ;0110
  DOM {WM_COMMAND,                        $OfsTStrA("WM_COMMAND")}                        ;0111
  DOM {WM_SYSCOMMAND,                     $OfsTStrA("WM_SYSCOMMAND")}                     ;0112
  DOM {WM_TIMER,                          $OfsTStrA("WM_TIMER")}                          ;0113
  DOM {WM_HSCROLL,                        $OfsTStrA("WM_HSCROLL")}                        ;0114
  DOM {WM_VSCROLL,                        $OfsTStrA("WM_VSCROLL")}                        ;0115
  DOM {WM_INITMENU,                       $OfsTStrA("WM_INITMENU")}                       ;0116
  DOM {WM_INITMENUPOPUP,                  $OfsTStrA("WM_INITMENUPOPUP")}                  ;0117
  DOM {WM_GESTURE,                        $OfsTStrA("WM_GESTURE")}                        ;0119
  DOM {WM_GESTURENOTIFY,                  $OfsTStrA("WM_GESTURENOTIFY")}                  ;011A

  DOM {WM_MENUSELECT,                     $OfsTStrA("WM_MENUSELECT")}                     ;011F
  DOM {WM_MENUCHAR,                       $OfsTStrA("WM_MENUCHAR")}                       ;0120
  DOM {WM_ENTERIDLE,                      $OfsTStrA("WM_ENTERIDLE")}                      ;0121
  DOM {WM_MENURBUTTONUP,                  $OfsTStrA("WM_MENURBUTTONUP")}                  ;0122
  DOM {WM_MENUDRAG,                       $OfsTStrA("WM_MENUDRAG")}                       ;0123
  DOM {WM_MENUGETOBJECT,                  $OfsTStrA("WM_MENUGETOBJECT")}                  ;0124
  DOM {WM_UNINITMENUPOPUP,                $OfsTStrA("WM_UNINITMENUPOPUP")}                ;0125
  DOM {WM_MENUCOMMAND,                    $OfsTStrA("WM_MENUCOMMAND")}                    ;0126
  DOM {WM_CHANGEUISTATE,                  $OfsTStrA("WM_CHANGEUISTATE")}                  ;0127
  DOM {WM_UPDATEUISTATE,                  $OfsTStrA("WM_UPDATEUISTATE")}                  ;0128
  DOM {WM_QUERYUISTATE,                   $OfsTStrA("WM_QUERYUISTATE")}                   ;0129

  DOM {WM_CTLCOLORMSGBOX,                 $OfsTStrA("WM_CTLCOLORMSGBOX")}                 ;0132
  DOM {WM_CTLCOLOREDIT,                   $OfsTStrA("WM_CTLCOLOREDIT")}                   ;0133
  DOM {WM_CTLCOLORLISTBOX,                $OfsTStrA("WM_CTLCOLORLISTBOX")}                ;0134
  DOM {WM_CTLCOLORBTN,                    $OfsTStrA("WM_CTLCOLORBTN")}                    ;0135
  DOM {WM_CTLCOLORDLG,                    $OfsTStrA("WM_CTLCOLORDLG")}                    ;0136
  DOM {WM_CTLCOLORSCROLLBAR,              $OfsTStrA("WM_CTLCOLORSCROLLBAR")}              ;0137
  DOM {WM_CTLCOLORSTATIC,                 $OfsTStrA("WM_CTLCOLORSTATIC")}                 ;0138

  DOM {WM_MOUSEMOVE,                      $OfsTStrA("WM_MOUSEMOVE")}                      ;0200
  DOM {WM_LBUTTONDOWN,                    $OfsTStrA("WM_LBUTTONDOWN")}                    ;0201
  DOM {WM_LBUTTONUP,                      $OfsTStrA("WM_LBUTTONUP")}                      ;0202
  DOM {WM_LBUTTONDBLCLK,                  $OfsTStrA("WM_LBUTTONDBLCLK")}                  ;0203
  DOM {WM_RBUTTONDOWN,                    $OfsTStrA("WM_RBUTTONDOWN")}                    ;0204
  DOM {WM_RBUTTONUP,                      $OfsTStrA("WM_RBUTTONUP")}                      ;0205
  DOM {WM_RBUTTONDBLCLK,                  $OfsTStrA("WM_RBUTTONDBLCLK")}                  ;0206
  DOM {WM_MBUTTONDOWN,                    $OfsTStrA("WM_MBUTTONDOWN")}                    ;0207
  DOM {WM_MBUTTONUP,                      $OfsTStrA("WM_MBUTTONUP")}                      ;0208
  DOM {WM_MBUTTONDBLCLK,                  $OfsTStrA("WM_MBUTTONDBLCLK")}                  ;0209
  DOM {WM_MOUSEWHEEL,                     $OfsTStrA("WM_MOUSEWHEEL")}                     ;020A
  DOM {WM_XBUTTONDOWN,                    $OfsTStrA("WM_XBUTTONDOWN")}                    ;020B
  DOM {WM_XBUTTONUP,                      $OfsTStrA("WM_XBUTTONUP")}                      ;020C
  DOM {WM_XBUTTONDBLCLK,                  $OfsTStrA("WM_XBUTTONDBLCLK")}                  ;020D
  DOM {WM_MOUSEHWHEEL,                    $OfsTStrA("WM_MOUSEHWHEEL")}                    ;020E

  DOM {WM_PARENTNOTIFY,                   $OfsTStrA("WM_PARENTNOTIFY")}                   ;0210
  DOM {WM_ENTERMENULOOP,                  $OfsTStrA("WM_ENTERMENULOOP")}                  ;0211
  DOM {WM_EXITMENULOOP,                   $OfsTStrA("WM_EXITMENULOOP")}                   ;0212
  DOM {WM_NEXTMENU,                       $OfsTStrA("WM_NEXTMENU")}                       ;0213
  DOM {WM_SIZING,                         $OfsTStrA("WM_SIZING")}                         ;0214
  DOM {WM_CAPTURECHANGED,                 $OfsTStrA("WM_CAPTURECHANGED")}                 ;0215
  DOM {WM_MOVING,                         $OfsTStrA("WM_MOVING")}                         ;0216
  DOM {WM_POWERBROADCAST,                 $OfsTStrA("WM_POWERBROADCAST")}                 ;0218
  DOM {WM_DEVICECHANGE,                   $OfsTStrA("WM_DEVICECHANGE")}                   ;0219

  DOM {WM_MDICREATE,                      $OfsTStrA("WM_MDICREATE")}                      ;0220
  DOM {WM_MDIDESTROY,                     $OfsTStrA("WM_MDIDESTROY")}                     ;0221
  DOM {WM_MDIACTIVATE,                    $OfsTStrA("WM_MDIACTIVATE")}                    ;0222
  DOM {WM_MDIRESTORE,                     $OfsTStrA("WM_MDIRESTORE")}                     ;0223
  DOM {WM_MDINEXT,                        $OfsTStrA("WM_MDINEXT")}                        ;0224
  DOM {WM_MDIMAXIMIZE,                    $OfsTStrA("WM_MDIMAXIMIZE")}                    ;0225
  DOM {WM_MDITILE,                        $OfsTStrA("WM_MDITILE")}                        ;0226
  DOM {WM_MDICASCADE,                     $OfsTStrA("WM_MDICASCADE")}                     ;0227
  DOM {WM_MDIICONARRANGE,                 $OfsTStrA("WM_MDIICONARRANGE")}                 ;0228
  DOM {WM_MDIGETACTIVE,                   $OfsTStrA("WM_MDIGETACTIVE")}                   ;0229

  DOM {WM_MDISETMENU,                     $OfsTStrA("WM_MDISETMENU")}                     ;0230
  DOM {WM_ENTERSIZEMOVE,                  $OfsTStrA("WM_ENTERSIZEMOVE")}                  ;0231
  DOM {WM_EXITSIZEMOVE,                   $OfsTStrA("WM_EXITSIZEMOVE")}                   ;0232
  DOM {WM_DROPFILES,                      $OfsTStrA("WM_DROPFILES")}                      ;0233
  DOM {WM_MDIREFRESHMENU,                 $OfsTStrA("WM_MDIREFRESHMENU")}                 ;0234

  DOM {WM_POINTERDEVICECHANGE,            $OfsTStrA("WM_POINTERDEVICECHANGE")}            ;0238
  DOM {WM_POINTERDEVICEINRANGE,           $OfsTStrA("WM_POINTERDEVICEINRANGE")}           ;0239
  DOM {WM_POINTERDEVICEOUTOFRANGE,        $OfsTStrA("WM_POINTERDEVICEOUTOFRANGE")}        ;023A
  DOM {WM_TOUCH,                          $OfsTStrA("WM_TOUCH")}                          ;0240
  DOM {WM_NCPOINTERUPDATE,                $OfsTStrA("WM_NCPOINTERUPDATE")}                ;0241
  DOM {WM_NCPOINTERDOWN,                  $OfsTStrA("WM_NCPOINTERDOWN")}                  ;0242
  DOM {WM_NCPOINTERUP,                    $OfsTStrA("WM_NCPOINTERUP")}                    ;0243
  DOM {WM_POINTERUPDATE,                  $OfsTStrA("WM_POINTERUPDATE")}                  ;0245
  DOM {WM_POINTERDOWN,                    $OfsTStrA("WM_POINTERDOWN")}                    ;0246
  DOM {WM_POINTERUP,                      $OfsTStrA("WM_POINTERUP")}                      ;0247
  DOM {WM_POINTERENTER,                   $OfsTStrA("WM_POINTERENTER")}                   ;0249
  DOM {WM_POINTERLEAVE,                   $OfsTStrA("WM_POINTERLEAVE")}                   ;024A
  DOM {WM_POINTERACTIVATE,                $OfsTStrA("WM_POINTERACTIVATE")}                ;024B
  DOM {WM_POINTERCAPTURECHANGED,          $OfsTStrA("WM_POINTERCAPTURECHANGED")}          ;024C
  DOM {WM_TOUCHHITTESTING,                $OfsTStrA("WM_TOUCHHITTESTING")}                ;024D
  DOM {WM_POINTERWHEEL,                   $OfsTStrA("WM_POINTERWHEEL")}                   ;024E
  DOM {WM_POINTERHWHEEL,                  $OfsTStrA("WM_POINTERHWHEEL")}                  ;024F
  DOM {WM_POINTERROUTEDTO,                $OfsTStrA("WM_POINTERROUTEDTO")}                ;0251
  DOM {WM_POINTERROUTEDAWAY,              $OfsTStrA("WM_POINTERROUTEDAWAY")}              ;0252
  DOM {WM_POINTERROUTEDRELEASED,          $OfsTStrA("WM_POINTERROUTEDRELEASED")}          ;0253

  DOM {WM_IME_SETCONTEXT,                 $OfsTStrA("WM_IME_SETCONTEXT")}                 ;0281
  DOM {WM_IME_NOTIFY,                     $OfsTStrA("WM_IME_NOTIFY")}                     ;0282
  DOM {WM_IME_CONTROL,                    $OfsTStrA("WM_IME_CONTROL")}                    ;0283
  DOM {WM_IME_COMPOSITIONFULL,            $OfsTStrA("WM_IME_COMPOSITIONFULL")}            ;0284
  DOM {WM_IME_SELECT,                     $OfsTStrA("WM_IME_SELECT")}                     ;0285
  DOM {WM_IME_CHAR,                       $OfsTStrA("WM_IME_CHAR")}                       ;0286
  DOM {WM_IME_REQUEST,                    $OfsTStrA("WM_IME_REQUEST")}                    ;0288
  DOM {WM_IME_KEYDOWN,                    $OfsTStrA("WM_IME_KEYDOWN")}                    ;0290
  DOM {WM_IME_KEYUP,                      $OfsTStrA("WM_IME_KEYUP")}                      ;0291

  DOM {WM_NCMOUSEHOVER,                   $OfsTStrA("WM_NCMOUSEHOVER")}                   ;02A0
  DOM {WM_MOUSEHOVER,                     $OfsTStrA("WM_MOUSEHOVER")}                     ;02A1
  DOM {WM_NCMOUSELEAVE,                   $OfsTStrA("WM_NCMOUSELEAVE")}                   ;02A2
  DOM {WM_MOUSELEAVE,                     $OfsTStrA("WM_MOUSELEAVE")}                     ;02A3

  DOM {WM_WTSSESSION_CHANGE,              $OfsTStrA("WM_WTSSESSION_CHANGE")}              ;02B1
  DOM {WM_TABLET_FIRST,                   $OfsTStrA("WM_TABLET_FIRST")}                   ;02C0
  DOM {WM_TABLET_LAST,                    $OfsTStrA("WM_TABLET_LAST")}                    ;02DF

  DOM {WM_DPICHANGED,                     $OfsTStrA("WM_DPICHANGED")}                     ;02E0
  DOM {WM_DPICHANGED_BEFOREPARENT,        $OfsTStrA("WM_DPICHANGED_BEFOREPARENT")}        ;02E2
  DOM {WM_DPICHANGED_AFTERPARENT,         $OfsTStrA("WM_DPICHANGED_AFTERPARENT")}         ;02E3
  DOM {WM_GETDPISCALEDSIZE,               $OfsTStrA("WM_GETDPISCALEDSIZE")}               ;02E4

  DOM {WM_CUT,                            $OfsTStrA("WM_CUT")}                            ;0300
  DOM {WM_COPY,                           $OfsTStrA("WM_COPY")}                           ;0301
  DOM {WM_PASTE,                          $OfsTStrA("WM_PASTE")}                          ;0302
  DOM {WM_CLEAR,                          $OfsTStrA("WM_CLEAR")}                          ;0303
  DOM {WM_UNDO,                           $OfsTStrA("WM_UNDO")}                           ;0304
  DOM {WM_RENDERFORMAT,                   $OfsTStrA("WM_RENDERFORMAT")}                   ;0305
  DOM {WM_RENDERALLFORMATS,               $OfsTStrA("WM_RENDERALLFORMATS")}               ;0306
  DOM {WM_DESTROYCLIPBOARD,               $OfsTStrA("WM_DESTROYCLIPBOARD")}               ;0307
  DOM {WM_DRAWCLIPBOARD,                  $OfsTStrA("WM_DRAWCLIPBOARD")}                  ;0308
  DOM {WM_PAINTCLIPBOARD,                 $OfsTStrA("WM_PAINTCLIPBOARD")}                 ;0309
  DOM {WM_VSCROLLCLIPBOARD,               $OfsTStrA("WM_VSCROLLCLIPBOARD")}               ;030A
  DOM {WM_SIZECLIPBOARD,                  $OfsTStrA("WM_SIZECLIPBOARD")}                  ;030B
  DOM {WM_ASKCBFORMATNAME,                $OfsTStrA("WM_ASKCBFORMATNAME")}                ;030C
  DOM {WM_CHANGECBCHAIN,                  $OfsTStrA("WM_CHANGECBCHAIN")}                  ;030D
  DOM {WM_HSCROLLCLIPBOARD,               $OfsTStrA("WM_HSCROLLCLIPBOARD")}               ;030E
  DOM {WM_QUERYNEWPALETTE,                $OfsTStrA("WM_QUERYNEWPALETTE")}                ;030F
  DOM {WM_PALETTEISCHANGING,              $OfsTStrA("WM_PALETTEISCHANGING")}              ;0310
  DOM {WM_PALETTECHANGED,                 $OfsTStrA("WM_PALETTECHANGED")}                 ;0311
  DOM {WM_HOTKEY,                         $OfsTStrA("WM_HOTKEY")}                         ;0312

  DOM {WM_PRINT,                          $OfsTStrA("WM_PRINT")}                          ;0317
  DOM {WM_PRINTCLIENT,                    $OfsTStrA("WM_PRINTCLIENT")}                    ;0318
  DOM {WM_APPCOMMAND,                     $OfsTStrA("WM_APPCOMMAND")}                     ;0319
  DOM {WM_THEMECHANGED,                   $OfsTStrA("WM_THEMECHANGED")}                   ;031A

  DOM {WM_CLIPBOARDUPDATE,                $OfsTStrA("WM_CLIPBOARDUPDATE")}                ;031D
  DOM {WM_DWMCOMPOSITIONCHANGED,          $OfsTStrA("WM_DWMCOMPOSITIONCHANGED")}          ;031E
  DOM {WM_DWMNCRENDERINGCHANGED,          $OfsTStrA("WM_DWMNCRENDERINGCHANGED")}          ;031F
  DOM {WM_DWMCOLORIZATIONCOLORCHANGED,    $OfsTStrA("WM_DWMCOLORIZATIONCOLORCHANGED")}    ;0320
  DOM {WM_DWMWINDOWMAXIMIZEDCHANGE,       $OfsTStrA("WM_DWMWINDOWMAXIMIZEDCHANGE")}       ;0321
  DOM {WM_DWMSENDICONICTHUMBNAIL,         $OfsTStrA("WM_DWMSENDICONICTHUMBNAIL")}         ;0323
  DOM {WM_DWMSENDICONICLIVEPREVIEWBITMAP, $OfsTStrA("WM_DWMSENDICONICLIVEPREVIEWBITMAP")} ;0326

  DOM {WM_GETTITLEBARINFOEX,              $OfsTStrA("WM_GETTITLEBARINFOEX")}              ;033F

  DOM {WM_HANDHELDFIRST,                  $OfsTStrA("WM_HANDHELDFIRST")}                  ;0358
  DOM {WM_HANDHELDLAST,                   $OfsTStrA("WM_HANDHELDLAST")}                   ;035F
  DOM {WM_AFXFIRST,                       $OfsTStrA("WM_AFXFIRST")}                       ;0360
  DOM {WM_AFXLAST,                        $OfsTStrA("WM_AFXLAST")}                        ;037F
  DOM {WM_PENWINFIRST,                    $OfsTStrA("WM_PENWINFIRST")}                    ;0380
  DOM {WM_PENWINLAST,                     $OfsTStrA("WM_PENWINLAST")}                     ;038F

  DOM {WM_DDE_INITIATE,                   $OfsTStrA("WM_DDE_INITIATE")}                   ;03E0
  DOM {WM_DDE_TERMINATE,                  $OfsTStrA("WM_DDE_TERMINATE")}                  ;03E1
  DOM {WM_DDE_ADVISE,                     $OfsTStrA("WM_DDE_ADVISE")}                     ;03E2
  DOM {WM_DDE_UNADVISE,                   $OfsTStrA("WM_DDE_UNADVISE")}                   ;03E3
  DOM {WM_DDE_ACK,                        $OfsTStrA("WM_DDE_ACK")}                        ;03E4
  DOM {WM_DDE_DATA,                       $OfsTStrA("WM_DDE_DATA")}                       ;03E5
  DOM {WM_DDE_REQUEST,                    $OfsTStrA("WM_DDE_REQUEST")}                    ;03E6
  DOM {WM_DDE_POKE,                       $OfsTStrA("WM_DDE_POKE")}                       ;03E7
  DOM {WM_DDE_EXECUTE,                    $OfsTStrA("WM_DDE_EXECUTE")}                    ;03E8

DbgWndMsgTableCount equ ($ - DbgWndMsgTable)/sizeof(DOM)

.data
  DbgMsgBufferUnk    CHRA   "Unknown message ("
  DbgMsgCodeUnk      CHRA   "00000000h)", 0
  DbgMsgBufferUser   CHRA   "WM_USE"
  DbgMsgCodeUser     CHRA   "00000000h", 0
  DbgMsgBufferApp    CHRA   "WM_AP"
  DbgMsgCodeApp      CHRA   "00000000h", 0
  DbgMsgBufferAppStr CHRA   "WM_APPST"
  DbgMsgCodeAppStr   CHRA   "00000000h", 0
  DbgMsgBufferRes    CHRA   "Reserved message ("
  DbgMsgCodeRes      CHRA   "00000000h)", 0

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  DbgOutMsg
; Purpose:    Identify a windows message with a string.
; Arguments:  Arg1: Windows message ID.
;             Arg2: Foreground RGB color value.
;             Arg3: Background RGB color value.
;             Arg4: -> Destination window name.
; Return:     Nothing.

.code
align ALIGN_CODE
DbgOutMsg proc dMsgID:DWORD, dForeColor:DWORD, dBackColor:DWORD, pDest:POINTER
  mov edx, dMsgID                                       ;edx = window message
  mov xax, offset DbgWndMsgTable
  mov ecx, DbgWndMsgTableCount
  test ecx, ecx
  .while !Zero?
    cmp edx, [xax].DOM.ID
    jz @F                                               ;Found!
    add xax, sizeof(DOM)                                ;Move to next entry
    dec ecx
  .endw
  .if edx >= WM_USER && edx <= 7FFFh                    ;Integer msg for use by priv. window classes
    sub edx, WM_USER
    invoke dword2hexA, offset DbgMsgCodeUser, edx
    mov xax, offset DbgMsgCodeUser
    mov QCHRA ptr [xax], 202B2052h                      ; "R + "
    mov CHRA ptr [xax + 8], "h"
    mov xax, offset DbgMsgBufferUser
  .elseif edx >= WM_APP && edx <= 0BFFFh                ;Messages available for use by applications
    sub edx, WM_APP
    invoke dword2hexA, offset DbgMsgCodeApp, edx
    mov xax, offset DbgMsgCodeApp
    mov QCHRA ptr [xax], 202B2050h                      ; "P + "
    mov CHRA ptr [xax + 8], "h"
    mov xax, offset DbgMsgBufferApp
  .elseif edx >= 0C000h && edx <= 0FFFFh                ;String messages for use by applications
    sub edx, 0C000h
    invoke dword2hexA, offset DbgMsgCodeAppStr, edx
    mov xax, offset DbgMsgCodeAppStr
    mov QCHRA ptr [xax], 202B2052h                      ; "R + "
    mov CHRA ptr [xax + 8], "h"
    mov xax, offset DbgMsgBufferAppStr
  .elseif edx > 0FFFFh                                  ;Reserved by the system
    invoke dword2hexA, offset DbgMsgCodeRes, edx
    mov xax, offset DbgMsgCodeRes + 8
    mov CHRA ptr [xax], "h"
    mov xax, offset DbgMsgBufferRes
  .else
    invoke dword2hexA, offset DbgMsgCodeUnk, edx
    mov xax, offset DbgMsgCodeUnk + 8
    mov CHRA ptr [xax], "h"
    mov xax, offset DbgMsgBufferUnk
  .endif
  jmp @@Exit
@@:
  mov xax, [xax].DOM.pStr                               ;Get text pointer
@@Exit:
  invoke DbgOutTextA, xax, dForeColor, dBackColor, DBG_EFFECT_NORMAL, pDest
  ret
DbgOutMsg endp
