; ==================================================================================================
; Title:      DlgTempl.inc
; Authors:    G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm support of Dialog template macros.
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


; --------------------------------------------------------------------------------------------------
; Macro:      FlexArg
; Purpose:    Check the Arg parameter to determine if it is blank, contains NULL, a quoted text or
;             an ordinal value to generate a proper segment memory allocation.
; Arguments:  Arg1: Input.
; Return:     Nothing.

FlexArg macro Arg
  local WStr

  ifb <Arg>
    WORD 0000h                                          ;;NULL
  else
    if @InStr(1, <Arg>, <NULL>) eq 1
      WORD 0000h                                        ;;NULL
    else
      if @InStr(1, <Arg>, <!">) eq 0
        WORD 0FFFFh, Arg                                ;;Ordinal
      else
        StringW , <Arg>                                 ;;WIDE string
      endif
    endif
  endif
endm


; --------------------------------------------------------------------------------------------------
; Macro:      DIALOGEX
; Purpose:    Create a DIALOGEX template structure.
; Arguments:  Structure arguments.
; Return:     Nothing.

DIALOGEX macro sName:req, wXPos:=<0>, wYPos:=<0>, wWidth:=<1>, wHeight:=<1>, \
               dHelpID:=<0>, wItems:=<0>, dStyle:=<0>, dExStyle:=<0>, \
               wMenuID:=<0>, sWndClass:=<>, sTitle:=<>, \
               sFont:=<Lucida Console>, wPts:=<8>, wWeight:=<FW_NORMAL>, \
               bItalic:=<FALSE>, sCharset:=<DEFAULT_CHARSET>
align 4
sName WORD 01h                                  ;Dialog version
      WORD 0FFFFh                               ;Signature
      DWORD dHelpID                             ;Help ID
      DWORD dExStyle                            ;Extended style
      DWORD dStyle or DS_SETFONT                ;Regular style
      WORD wItems                               ;Number of controls that follow this structure
      WORD wXPos                                ;X position
      WORD wYPos                                ;Y position
      WORD wWidth                               ;Width
      WORD wHeight                              ;Height
      WORD wMenuID                              ;Menu ID
      FlexArg sWndClass                         ;Dialog class
      FlexArg sTitle                            ;Dialog title
      WORD wPts                                 ;Font size
      WORD wWeight                              ;Font weight
      BYTE bItalic                              ;Italic
      CHRA sCharset                             ;Charset
      FlexArg sFont                             ;Font face
endm

; --------------------------------------------------------------------------------------------------
; Macro:      CONTROL
; Purpose:    Create a control template structure.
; Arguments:  Structure arguments.
; Return:     Nothing.

CONTROL macro sTitle, dCtlID:req, sWndClass:req, dStyle:req, \
              wXPos:=<0>, wYPos:=<0>, wWidth:=<1>, wHeight:=<1>, \
              dExStyle:=<0>, dHelpID:=<0>, wExtra:=<0>
align 4
    DWORD dHelpID
    DWORD dExStyle
    DWORD dStyle or WS_CHILD or WS_VISIBLE
    WORD wXPos
    WORD wYPos
    WORD wWidth
    WORD wHeight
    DWORD dCtlID
    FlexArg sWndClass
    FlexArg sTitle
    WORD wExtra
endm

; --------------------------------------------------------------------------------------------------
; Macro:      PUSHBUTTON
; Purpose:    Create a PUSHBUTTON control template structure.
; Arguments:  sTitle, dCtlID, wXPos, wYPos, wWidth, wHeight, dStyle, dExStyle, dHelpID, wExtra
; Return:     Nothing.

PUSHBUTTON macro sTitle, dCtlID, wXPos, wYPos, wWidth, wHeight, dStyle, dExStyle, dHelpID, wExtra
  ifb <dStyle>
    CONTROL sTitle, dCtlID, 80h, BS_PUSHBUTTON or WS_TABSTOP, wXPos, wYPos, wWidth, wHeight, dExStyle, dHelpID, wExtra
  else
    CONTROL sTitle, dCtlID, 80h, BS_PUSHBUTTON or dStyle, wXPos, wYPos, wWidth, wHeight, dExStyle, dHelpID, wExtra
  endif
endm

; --------------------------------------------------------------------------------------------------
; Macro:      DEFPUSHBUTTON
; Purpose:    Create a DEFPUSHBUTTON control template structure.
; Arguments:  sTitle, dCtlID, wXPos, wYPos, wWidth, wHeight, dStyle, dExStyle, dHelpID, wExtra
; Return:     Nothing.

DEFPUSHBUTTON macro sTitle, dCtlID, wXPos, wYPos, wWidth, wHeight, dStyle, dExStyle, dHelpID, wExtra
  ifb <dStyle>
    CONTROL sTitle, dCtlID, 80h, BS_DEFPUSHBUTTON or WS_TABSTOP, wXPos, wYPos, wWidth, wHeight, dExStyle, dHelpID, wExtra
  else
    CONTROL sTitle, dCtlID, 80h, BS_DEFPUSHBUTTON or dStyle, wXPos, wYPos, wWidth, wHeight, dExStyle, dHelpID, wExtra
  endif
endm

; --------------------------------------------------------------------------------------------------
; Macro:      PUSHBOX
; Purpose:    Create a PUSHBOX control template structure.
; Arguments:  sTitle, dCtlID, wXPos, wYPos, wWidth, wHeight, dStyle, dExStyle, dHelpID, wExtra
; Return:     Nothing.

PUSHBOX macro sTitle, dCtlID, wXPos, wYPos, wWidth, wHeight, dStyle, dExStyle, dHelpID, wExtra
  ifb <dStyle>
    CONTROL sTitle, dCtlID, 80h, BS_PUSHBOX or WS_TABSTOP, wXPos, wYPos, wWidth, wHeight, dExStyle, dHelpID, wExtra
  else
    CONTROL sTitle, dCtlID, 80h, BS_PUSHBOX or dStyle, wXPos, wYPos, wWidth, wHeight, dExStyle, dHelpID, wExtra
  endif
endm

; --------------------------------------------------------------------------------------------------
; Macro:      AUTO3STATE
; Purpose:    Create a AUTO3STATE control template structure.
; Arguments:  sTitle, dCtlID, wXPos, wYPos, wWidth, wHeight, dStyle, dExStyle, dHelpID, wExtra
; Return:     Nothing.

AUTO3STATE macro sTitle, dCtlID, wXPos, wYPos, wWidth, wHeight, dStyle, dExStyle, dHelpID, wExtra
  ifb <dStyle>
    CONTROL sTitle, dCtlID, 80h, BS_AUTO3STATE or WS_TABSTOP, wXPos, wYPos, wWidth, wHeight, dExStyle, dHelpID, wExtra
  else
    CONTROL sTitle, dCtlID, 80h, BS_AUTO3STATE or dStyle, wXPos, wYPos, wWidth, wHeight, dExStyle, dHelpID, wExtra
  endif
endm

; --------------------------------------------------------------------------------------------------
; Macro:      STATE3
; Purpose:    Create a STATE3 control template structure.
; Arguments:  sTitle, dCtlID, wXPos, wYPos, wWidth, wHeight, dStyle, dExStyle, dHelpID, wExtra
; Return:     Nothing.

STATE3 macro sTitle, dCtlID, wXPos, wYPos, wWidth, wHeight, dStyle, dExStyle, dHelpID, wExtra
  ifb   <dStyle>
    CONTROL sTitle, dCtlID, 80h, BS_3STATE or WS_TABSTOP, wXPos, wYPos, wWidth, wHeight, dExStyle, dHelpID, wExtra
  else
    CONTROL sTitle, dCtlID, 80h, BS_3STATE or dStyle, wXPos, wYPos, wWidth, wHeight, dExStyle, dHelpID, wExtra
  endif
endm

; --------------------------------------------------------------------------------------------------
; Macro:      AUTOCHECKBOX
; Purpose:    Create a AUTOCHECKBOX control template structure.
; Arguments:  sTitle, dCtlID, wXPos, wYPos, wWidth, wHeight, dStyle, dExStyle, dHelpID, wExtra
; Return:     Nothing.

AUTOCHECKBOX macro sTitle, dCtlID, wXPos, wYPos, wWidth, wHeight, dStyle, dExStyle, dHelpID, wExtra
  ifb <dStyle>
    CONTROL sTitle, dCtlID, 80h, BS_AUTOCHECKBOX or WS_TABSTOP, wXPos, wYPos, wWidth, wHeight, dExStyle, dHelpID, wExtra
  else
    CONTROL sTitle, dCtlID, 80h, BS_AUTOCHECKBOX or dStyle, wXPos, wYPos, wWidth, wHeight, dExStyle, dHelpID, wExtra
  endif
endm

; --------------------------------------------------------------------------------------------------
; Macro:      CHECKBOX
; Purpose:    Create a CHECKBOX control template structure.
; Arguments:  sTitle, dCtlID, wXPos, wYPos, wWidth, wHeight, dStyle, dExStyle, dHelpID, wExtra
; Return:     Nothing.

CHECKBOX macro sTitle, dCtlID, wXPos, wYPos, wWidth, wHeight, dStyle, dExStyle, dHelpID, wExtra
  ifb   <dStyle>
    CONTROL sTitle, dCtlID, 80h, BS_CHECKBOX or WS_TABSTOP, wXPos, wYPos, wWidth, wHeight, dExStyle, dHelpID, wExtra
  else
    CONTROL sTitle, dCtlID, 80h, BS_CHECKBOX or dStyle, wXPos, wYPos, wWidth, wHeight, dExStyle, dHelpID, wExtra
  endif
endm

; --------------------------------------------------------------------------------------------------
; Macro:      RADIOBUTTON
; Purpose:    Create a RADIOBUTTON control template structure.
; Arguments:  sTitle, dCtlID, wXPos, wYPos, wWidth, wHeight, dStyle, dExStyle, dHelpID, wExtra
; Return:     Nothing.

RADIOBUTTON macro sTitle, dCtlID, wXPos, wYPos, wWidth, wHeight, dStyle, dExStyle, dHelpID, wExtra
  ifb <dStyle>
    CONTROL sTitle, dCtlID, 80h, BS_RADIOBUTTON or WS_TABSTOP, wXPos, wYPos, wWidth, wHeight, dExStyle, dHelpID, wExtra
  else
    CONTROL sTitle, dCtlID, 80h, BS_RADIOBUTTON or dStyle, wXPos, wYPos, wWidth, wHeight, dExStyle, dHelpID, wExtra
  endif
endm

; --------------------------------------------------------------------------------------------------
; Macro:      AUTORADIOBUTTON
; Purpose:    Create a AUTORADIOBUTTON control template structure.
; Arguments:  sTitle, dCtlID, wXPos, wYPos, wWidth, wHeight, dStyle, dExStyle, dHelpID, wExtra
; Return:     Nothing.

AUTORADIOBUTTON macro sTitle, dCtlID, wXPos, wYPos, wWidth, wHeight, dStyle, dExStyle, dHelpID, wExtra
  ifb <dStyle>
    CONTROL sTitle, dCtlID, 80h, BS_AUTORADIOBUTTON or WS_TABSTOP, wXPos, wYPos, wWidth, wHeight, dExStyle, dHelpID, wExtra
  else
    CONTROL sTitle, dCtlID, 80h, BS_AUTORADIOBUTTON or dStyle, wXPos, wYPos, wWidth, wHeight, dExStyle, dHelpID, wExtra
  endif
endm

; --------------------------------------------------------------------------------------------------
; Macro:      GROUPBOX
; Purpose:    Create a GROUPBOX control template structure.
; Arguments:  sTitle, dCtlID, wXPos, wYPos, wWidth, wHeight, dStyle, dExStyle, dHelpID, wExtra
; Return:     Nothing.

GROUPBOX macro sTitle, dCtlID, wXPos, wYPos, wWidth, wHeight, dStyle, dExStyle, dHelpID, wExtra
  ifb <dStyle>
    CONTROL sTitle, dCtlID, 80h, BS_GROUPBOX, wXPos, wYPos, wWidth, wHeight, dExStyle, dHelpID, wExtra
  else
    CONTROL sTitle, dCtlID, 80h, BS_GROUPBOX or dStyle, wXPos, wYPos, wWidth, wHeight, dExStyle, dHelpID, wExtra
  endif
endm

; --------------------------------------------------------------------------------------------------
; Macro:      LTEXT
; Purpose:    Create a LTEXT control template structure.
; Arguments:  sTitle, dCtlID, wXPos, wYPos, wWidth, wHeight, dStyle, dExStyle, dHelpID, wExtra
; Return:     Nothing.

LTEXT macro sTitle, dCtlID, wXPos, wYPos, wWidth, wHeight, dStyle, dExStyle, dHelpID, wExtra
  ifb <dStyle>
    CONTROL sTitle, dCtlID, 82h, SS_LEFT or WS_GROUP, wXPos, wYPos, wWidth, wHeight, dExStyle, dHelpID, wExtra
  else
    CONTROL sTitle, dCtlID, 82h, SS_LEFT or dStyle, wXPos, wYPos, wWidth, wHeight, dExStyle, dHelpID, wExtra
  endif
endm

; --------------------------------------------------------------------------------------------------
; Macro:      RTEXT
; Purpose:    Create a RTEXT control template structure.
; Arguments:  sTitle, dCtlID, wXPos, wYPos, wWidth, wHeight, dStyle, dExStyle, dHelpID, wExtra
; Return:     Nothing.

RTEXT macro sTitle, dCtlID, wXPos, wYPos, wWidth, wHeight, dStyle, dExStyle, dHelpID, wExtra
  ifb <dStyle>
    CONTROL sTitle, dCtlID, 82h, SS_RIGHT or WS_GROUP, wXPos, wYPos, wWidth, wHeight, dExStyle, dHelpID, wExtra
  else
    CONTROL sTitle, dCtlID, 82h, SS_RIGHT or dStyle, wXPos, wYPos, wWidth, wHeight, dExStyle, dHelpID, wExtra
  endif
endm

; --------------------------------------------------------------------------------------------------
; Macro:      CTEXT
; Purpose:    Create a CTEXT control template structure.
; Arguments:  sTitle, dCtlID, wXPos, wYPos, wWidth, wHeight, dStyle, dExStyle, dHelpID, wExtra
; Return:     Nothing.

CTEXT macro sTitle, dCtlID, wXPos, wYPos, wWidth, wHeight, dStyle, dExStyle, dHelpID, wExtra
  ifb <dStyle>
    CONTROL sTitle, dCtlID, 82h, SS_CENTER or WS_GROUP, wXPos, wYPos, wWidth, wHeight, dExStyle, dHelpID, wExtra
  else
    CONTROL sTitle, dCtlID, 82h, SS_CENTER or dStyle, wXPos, wYPos, wWidth, wHeight, dExStyle, dHelpID, wExtra
  endif
endm

; --------------------------------------------------------------------------------------------------
; Macro:      COMBOBOX
; Purpose:    Create a COMBOBOX control template structure.
; Arguments:  sTitle, dCtlID, wXPos, wYPos, wWidth, wHeight, dStyle, dExStyle, dHelpID, wExtra
; Return:     Nothing.

COMBOBOX macro sTitle, dCtlID, wXPos, wYPos, wWidth, wHeight, dStyle, dExStyle, dHelpID, wExtra
  ifb <dStyle>
    CONTROL sTitle, dCtlID, 85h, CBS_SIMPLE or WS_TABSTOP, wXPos, wYPos, wWidth, wHeight, dExStyle, dHelpID, wExtra
  else
    CONTROL sTitle, dCtlID, 85h, dStyle, wXPos, wYPos, wWidth, wHeight, dExStyle, dHelpID, wExtra
  endif
endm

; --------------------------------------------------------------------------------------------------
; Macro:      LISTBOX
; Purpose:    Create a LISTBOX control template structure.
; Arguments:  sTitle, dCtlID, wXPos, wYPos, wWidth, wHeight, dStyle, dExStyle, dHelpID, wExtra
; Return:     Nothing.

LISTBOX macro sTitle, dCtlID, wXPos, wYPos, wWidth, wHeight, dStyle, dExStyle, dHelpID, wExtra
  ifb <dStyle>
    CONTROL sTitle, dCtlID, 83h, LBS_NOTIFY or WS_BORDER, wXPos, wYPos, wWidth, wHeight, dExStyle, dHelpID, wExtra
  else
    CONTROL sTitle, dCtlID, 83h, dStyle, wXPos, wYPos, wWidth, wHeight, dExStyle, dHelpID, wExtra
  endif
endm

; --------------------------------------------------------------------------------------------------
; Macro:      EDITTEXT
; Purpose:    Create a EDITTEXT control template structure.
; Arguments:  sTitle, dCtlID, wXPos, wYPos, wWidth, wHeight, dStyle, dExStyle, dHelpID, wExtra
; Return:     Nothing.

EDITTEXT macro sTitle, dCtlID, wXPos, wYPos, wWidth, wHeight, dStyle, dExStyle, dHelpID, wExtra
  ifb <dStyle>
    CONTROL sTitle, dCtlID, 81h, ES_LEFT or WS_BORDER or WS_TABSTOP, wXPos, wYPos, wWidth, wHeight, dExStyle, dHelpID, wExtra
  else
    CONTROL sTitle, dCtlID, 81h, dStyle, wXPos, wYPos, wWidth, wHeight, dExStyle, dHelpID, wExtra
  endif
endm

; --------------------------------------------------------------------------------------------------
; Macro:      SCROLLBAR
; Purpose:    Create a SCROLLBAR control template structure.
; Arguments:  sTitle, dCtlID, wXPos, wYPos, wWidth, wHeight, dStyle, dExStyle, dHelpID, wExtra
; Return:     Nothing.

SCROLLBAR macro dCtlID, wXPos, wYPos, wWidth, wHeight, dStyle, dExStyle, dHelpID, wExtra
  ifb <dStyle>
    CONTROL NULL, dCtlID, 84h, SBS_HORZ, wXPos, wYPos, wWidth, wHeight, dExStyle, dHelpID, wExtra
  else
    CONTROL NULL, dCtlID, 84h, dStyle, wXPos, wYPos, wWidth, wHeight, dExStyle, dHelpID, wExtra
  endif
endm

; --------------------------------------------------------------------------------------------------
; Macro:      ICON
; Purpose:    Create a ICON control template structure.
; Arguments:  sTitle, dCtlID, wXPos, wYPos, wWidth, wHeight, dStyle, dExStyle, dHelpID, wExtra
; Return:     Nothing.

ICON macro sTitle, dCtlID, wXPos, wYPos, wWidth, wHeight, dStyle, dExStyle, dHelpID, wExtra
  ifb <dStyle>
    CONTROL sTitle, dCtlID, 82h, SS_ICON, wXPos, wYPos, wWidth, wHeight, dExStyle, dHelpID, wExtra
  else
    CONTROL sTitle, dCtlID, 82h, dStyle, wXPos, wYPos, wWidth, wHeight, dExStyle, dHelpID, wExtra
  endif
endm

; --------------------------------------------------------------------------------------------------
; Macro:      TREEVIEW
; Purpose:    Create a TREEVIEW control template structure.
; Arguments:  dCtlID, wXPos, wYPos, wWidth, wHeight, dStyle, dExStyle, dHelpID, wExtra
; Return:     Nothing.

TREEVIEW macro dCtlID, wXPos, wYPos, wWidth, wHeight, dStyle, dExStyle, dHelpID, wExtra
  CONTROL NULL, dCtlID, "SysTreeView32", dStyle, wXPos, wYPos, wWidth, wHeight, dExStyle, dHelpID, wExtra
endm

; --------------------------------------------------------------------------------------------------
; Macro:      LISTVIEW
; Purpose:    Create a LISTVIEW control template structure.
; Arguments:  dCtlID, wXPos, wYPos, wWidth, wHeight, dStyle, dExStyle, dHelpID, wExtra
; Return:     Nothing.

LISTVIEW macro dCtlID, wXPos, wYPos, wWidth, wHeight, dStyle, dExStyle, dHelpID, wExtra
  CONTROL NULL, dCtlID, "SysListView32", dStyle, wXPos, wYPos, wWidth, wHeight, dExStyle, dHelpID, wExtra
endm

; --------------------------------------------------------------------------------------------------
; Macro:      HYPERLINK
; Purpose:    Create a HYPERLINK control template structure.
; Arguments:  sTitle, dCtlID, wXPos, wYPos, wWidth, wHeight, dStyle, dExStyle, dHelpID, wExtra
; Return:     Nothing.

HYPERLINK macro sTitle, dCtlID, wXPos, wYPos, wWidth, wHeight, dStyle, dExStyle, dHelpID, wExtra
  CONTROL sTitle, dCtlID, "Hyperlink", dStyle, wXPos, wYPos, wWidth, wHeight, dExStyle, dHelpID, wExtra
endm
