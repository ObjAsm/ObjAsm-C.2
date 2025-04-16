; ==================================================================================================
; Title:      DB_StructEditor.inc
; Author:     G. Friedrich
; Version:    C.1.1
; Purpose:    ObjAsm Database DB_RecordEditor object.
; Notes:      Version C.1.1, August 2019
;             - First release.
; ==================================================================================================


SEL_FLAG_INIT           equ   BIT00     ;Control is initializing, nofications are ignored
SEL_FLAG_SELECTED       equ   BIT01
SEL_FLAG_DATA_LOSS      equ   BIT02
SEL_FLAG_CHANGES_SAVED  equ   BIT03
SEL_FLAG_INDEX_REBUILD  equ   BIT04     ;Index complete rebuild required after data mutation

SEL_FLAG_CHANGE_POS     equ   BIT08
SEL_FLAG_CHANGE_NAME    equ   BIT09
SEL_FLAG_CHANGE_TYPE    equ   BIT10
SEL_FLAG_CHANGE_LENGTH  equ   BIT11
SEL_FLAG_CHANGE_PARAM   equ   BIT12
SEL_FLAG_CHANGE_INDEX   equ   BIT13     ;Index file name changed
SEL_FLAG_CHANGE_DATA    equ   SEL_FLAG_CHANGE_NAME or SEL_FLAG_CHANGE_TYPE or \
                              SEL_FLAG_CHANGE_LENGTH or SEL_FLAG_CHANGE_PARAM
SEL_FLAG_CHANGE_ANY     equ   SEL_FLAG_CHANGE_DATA or SEL_FLAG_CHANGE_POS or SEL_FLAG_CHANGE_INDEX

Object DB_StructEditorLine, DB_StructEditorLineID, Primer
  VirtualMethod     CtlsEnable,         DWORD
  VirtualMethod     CtlsGet,            $ObjPtr(DB_Field)
  VirtualMethod     CtlsMove,           POINTER, PCTRL_POSITIONS
  VirtualMethod     CtlsRead
  VirtualMethod     CtlsSet,            $ObjPtr(DB_Field), DWORD
  VirtualMethod     CtlsSetDefaults
  VirtualMethod     CtlsSetStandards
  VirtualMethod     CheckChanges
  VirtualMethod     DisplayInfo
  RedefineMethod    Done
  RedefineMethod    Init,               $ObjPtr(Collection)
  VirtualMethod     SetBuddy,           XWORD, XWORD

  DefineVariable    dFlags,             DWORD,      0
  DefineVariable    hStcInfo,           HWND,       0         ;Static control, displays an icon
  DefineVariable    hEdtFieldName,      HWND,       0
  DefineVariable    hCboFieldType,      HWND,       0
  DefineVariable    hEdtFieldLength,    HWND,       0
  DefineVariable    hUdcFieldLength,    HWND,       0
  DefineVariable    hEdtFieldParam,     HWND,       0
  DefineVariable    hUdcFieldParam,     HWND,       0
  DefineVariable    hEdtFieldIndex,     HWND,       0

  DefineVariable    dPrvFieldPos,       DWORD,      -1        ;From DB_StructEditorDlg.dAppendIndex
  DefineVariable    pPrvFieldIndex,     $ObjPtr(DB_Index), NULL
  DefineVariable    MutationInfo,       FIELD_MUTATION,  {}
ObjectEnd


Object DB_StructEditor, DB_StructEditorID, WinPrimer
  VirtualMethod     CtlsEnable,         DWORD
  VirtualMethod     CtlsGet,            $ObjPtr(DB_Table)
  VirtualMethod     CtlsInit
  VirtualMethod     CtlsMove
  VirtualMethod     CtlsRead
  VirtualMethod     CtlsSet,            $ObjPtr(DB_Table)
  VirtualMethod     Dispatch,           HWND, DWORD, WPARAM, LPARAM
  RedefineMethod    Done
  RedefineMethod    Init,               POINTER, HWND
  VirtualMethod     InitRes,            HWND
  VirtualMethod     Select,             $ObjPtr(DB_StructEditorLine)
  StaticMethod      Startup
  VirtualMethod     WndProc,            DWORD, WPARAM, LPARAM

  ;Events
  StaticEvent       OnCommand,          WM_COMMAND
  StaticEvent       OnCreate,           WM_CREATE
  StaticEvent       OnEnable,           WM_ENABLE
  StaticEvent       OnEraseBkgnd,       WM_ERASEBKGND
  StaticEvent       OnMouseWheel,       WM_MOUSEWHEEL
  StaticEvent       OnVScroll,          WM_VSCROLL
  StaticEvent       OnSize,             WM_SIZE


  DefineVariable    dAllowErase,        DWORD,      0
  DefineVariable    hDWP,               HANDLE,     0

  ;UI elements
  Embed             EditorLines,        Collection
  DefineVariable    hFont,              HFONT,      0
  DefineVariable    hInfoBrush,         HBRUSH,     0
  DefineVariable    pSelEditorLine,     $ObjPtr(DB_StructEditorLine),   NULL
  DefineVariable    hSelected,          HICON,      0
  DefineVariable    hSelGreen,          HICON,      0
  DefineVariable    hSelYellow,         HICON,      0
  DefineVariable    hSelRed,            HICON,      0
  DefineVariable    hUnselected,        HICON,      0
  DefineVariable    hUnselGreen,        HICON,      0
  DefineVariable    hUnselYellow,       HICON,      0
  DefineVariable    hUnselRed,          HICON,      0

  ;Metrics
  DefineVariable    DlgBaseUnit,        POINT,      {0,0}
  DefineVariable    ViewOrigin,         POINT,      {0,0}   ;Pixel offset from 0,0
  DefineVariable    ViewExtent,         POINT,      {0,0}   ;Size of content in pixel
  DefineVariable    ScrollPage,         POINT,      {0,0}   ;Chars and Lines to (page)scroll
  DefineVariable    CtlSize,            POINT,      {0,0}   ;This control size
  DefineVariable    InfoSize,           POINT,      {0, CTL_HEIGHT_EDIT}
  DefineVariable    EdtSize,            POINT,      {0, CTL_HEIGHT_EDIT}    ;Edit control size
  DefineVariable    Margin,             POINT,      {CTL_MARGIN_HORZ, CTL_MARGIN_VERT}
  DefineVariable    Separation,         POINT,      {CTL_SEPARATION_HORZ, CTL_SEPARATION_VERT}
  DefineVariable    dFldNameWidth,      DWORD,      95      ; They will be converted
  DefineVariable    dFldTypeWidth,      DWORD,      80      ; to pixel in CtlsInit
  DefineVariable    dFldLengthWidth,    DWORD,      35      ;
  DefineVariable    dFldParamWidth,     DWORD,      55
ObjectEnd


if IMPLEMENT

; ==================================================================================================
; DB_StructEditorLine
; ==================================================================================================

SEL_CTRLS_PER_LINE  equ   6                             ;Don't include UpDown controls
CTLID_FieldLength   equ   20000
CTLID_FieldParam    equ   20001

; --------------------------------------------------------------------------------------------------
; Method:     DB_StructEditorLine.CtlsEnable
; Purpose:    Set the enable state of the controls and set the standard field values.
; Arguments:  Arg1: TRUE or FALSE
; Return:     Nothing.

Method DB_StructEditorLine.CtlsEnable, uses xdi xsi, dState:DWORD
  local bBuffer[2]:CHRA

;  DbgText "DB_StructEditorLine.CtlsEnable"
  SetObject xsi

  invoke EnableWindow, [xsi].hEdtFieldName, dState
  invoke EnableWindow, [xsi].hCboFieldType, dState

  invoke GetWindowTextA, [xsi].hCboFieldType, addr bBuffer, lengthof bBuffer  ;First character + ZTC
  mov xdi, $invoke(DB_GetStdFieldInfo, BYTE ptr bBuffer)
  .if [xdi].STD_FIELD_INFO.bLength == 0
    invoke EnableWindow, [xsi].hEdtFieldLength, dState
  .else
    invoke EnableWindow, [xsi].hEdtFieldLength, FALSE
  .endif

  .ifBitSet [xdi].STD_FIELD_INFO.bFlags, SFF_HAS_PARAM
    .ifBitSet [xdi].STD_FIELD_INFO.bFlags, SFF_READ_ONLY
      xor edx, edx
      .ifBitSet [xdi].STD_FIELD_INFO.bFlags, SFF_WRITE_SETUP
        .if [xsi].dPrvFieldPos == -1                    ;Check if the Field was appended
          mov edx, dState
        .endif
      .endif
    .else
      mov edx, dState
    .endif
    invoke EnableWindow, [xsi].hEdtFieldParam, edx
  .else
    invoke EnableWindow, [xsi].hEdtFieldParam, FALSE
  .endif

  .ifBitSet [xdi].STD_FIELD_INFO.bFlags, SSF_NO_INDEX
    invoke EnableWindow, [xsi].hEdtFieldIndex, FALSE
  .else
    invoke EnableWindow, [xsi].hEdtFieldIndex, dState
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     DB_StructEditorLine.CtlsGet
; Purpose:    Get xActxxx values and put them in the xPrvxxx object members and in the DB_Field.
; Arguments:  Arg1: -> DB_Field.
; Return:     Nothing.

Method DB_StructEditorLine.CtlsGet, uses xbx xdi xsi, pField:$ObjPtr(DB_Field)
  local cBuffer[LOCAL_BUFFER_SIZE]:CHR

;  DbgText "DB_StructEditorLine.CtlsGet"
  SetObject xsi
  mov xbx, pField                                       ; and set the xActxxx members
  lea xdi, cBuffer

  ;Get the field position
  mov [xsi].dPrvFieldPos, $32($OCall([xsi].pOwner::Collection.IndexOf, xsi))

  ;Get the field name (11 bytes, filled with zeros)
  s2s [xsi].MutationInfo.bPrvName, [xsi].MutationInfo.bActName, xax, xcx
  s2s [xbx].$Obj(DB_Field).Descriptor.bName, [xsi].MutationInfo.bActName, xax, xcx

  ;Get the field type
  mov al, [xsi].MutationInfo.bActType
  mov [xsi].MutationInfo.bPrvType, al
  mov [xbx].$Obj(DB_Field).Descriptor.bType, al

  ;Get the field length
  mov al, [xsi].MutationInfo.bActLength
  mov [xsi].MutationInfo.bPrvLength, al
  mov [xbx].$Obj(DB_Field).Descriptor.bLength, al

  ;Get the field parameter, e.g. Decimals or AutoIncrement
  mov eax, [xsi].MutationInfo.dActParam
  .if [xsi].MutationInfo.bActType == FDT_NUMERIC
    mov [xbx].$Obj(DB_Field).Descriptor.bDecimals, al
    m2z [xbx].$Obj(DB_Field).Descriptor.dAutoIncrement
  .elseif [xbx].$Obj(DB_Field).Descriptor.bType == FDT_AUTOINC
    m2z [xbx].$Obj(DB_Field).Descriptor.bDecimals
    mov [xbx].$Obj(DB_Field).Descriptor.dAutoIncrement, eax
  .else
    m2z [xbx].$Obj(DB_Field).Descriptor.bDecimals
    m2z [xbx].$Obj(DB_Field).Descriptor.dAutoIncrement
  .endif
  mov [xsi].MutationInfo.dPrvParam, eax

  .ifBitSet [xsi].dFlags, SEL_FLAG_CHANGE_ANY
    BitClr [xsi].dFlags, SEL_FLAG_CHANGE_DATA or SEL_FLAG_CHANGE_POS or SEL_FLAG_DATA_LOSS
    .ifBitClr [xsi].dFlags, SEL_FLAG_CHANGE_INDEX
      BitSet [xsi].dFlags, SEL_FLAG_CHANGES_SAVED
    .endif
    OCall xsi.DisplayInfo                               ;Update the info box
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     DB_StructEditorLine.CtlsMove
; Purpose:    Moves the controls of the line into the DB_StructEditor control.
; Arguments:  Arg1: -> DB_StructEditor.
;             Arg2: -> CTRL_POSITIONS structure.

Method DB_StructEditorLine.CtlsMove, uses xbx xdi xsi, pControl:POINTER, pCtlPos:PCTRL_POSITIONS
  SetObject xsi
  mov xdi, pControl
  assume xdi:$ObjPtr(DB_StructEditor)
  mov xbx, pCtlPos
  assume xbx:PCTRL_POSITIONS

  invoke DeferWindowPos, [xdi].hDWP, [xsi].hStcInfo, HWND_BOTTOM, \
                         [xbx].sdPosX1, [xbx].LineOrigin.y, [xdi].InfoSize.x, [xdi].InfoSize.y, 0
  mov [xdi].hDWP, xax
  invoke DeferWindowPos, [xdi].hDWP, [xsi].hEdtFieldName, HWND_BOTTOM, \
                         [xbx].sdPosX2, [xbx].LineOrigin.y, [xdi].dFldNameWidth, [xdi].EdtSize.y, 0
  mov [xdi].hDWP, xax
  invoke DeferWindowPos, [xdi].hDWP, [xsi].hCboFieldType, HWND_BOTTOM, \
                         [xbx].sdPosX3, [xbx].LineOrigin.y, [xdi].dFldTypeWidth, [xdi].EdtSize.y, 0
  mov [xdi].hDWP, xax
  invoke DeferWindowPos, [xdi].hDWP, [xsi].hEdtFieldLength, HWND_BOTTOM, \
                         [xbx].sdPosX4, [xbx].LineOrigin.y, [xdi].dFldLengthWidth, [xdi].EdtSize.y,0
  mov [xdi].hDWP, xax
  invoke DeferWindowPos, [xdi].hDWP, [xsi].hEdtFieldParam, HWND_BOTTOM, \
                         [xbx].sdPosX5, [xbx].LineOrigin.y, [xdi].dFldParamWidth, [xdi].EdtSize.y, 0
  mov [xdi].hDWP, xax
  invoke DeferWindowPos, [xdi].hDWP, [xsi].hEdtFieldIndex, HWND_BOTTOM, \
                         [xbx].sdPosX6, [xbx].LineOrigin.y, [xdi].EdtSize.x, [xdi].EdtSize.y, 0
  mov [xdi].hDWP, xax

  ;Increment Y position for the next line.
  mov eax, [xdi].Separation.y
  add [xbx].LineOrigin.y, eax
  assume xdi:NOTHING, xbx:NOTHING
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     DB_StructEditorLine.CtlsRead
; Purpose:    Read the content of the controls, vakudate them and put these values in the
;             xActxxx object members.
; Arguments:  None.
; Return:     Nothing.

Method DB_StructEditorLine.CtlsRead, uses xbx xdi xsi
  local cBuffer[LOCAL_BUFFER_SIZE]:CHR, bDwordBuffer[11]:CHRA

;  DbgText "DB_StructEditorLine.CtlsRead"
  SetObject xsi
  lea xdi, cBuffer

  ;Get the field type
  invoke GetWindowTextA, [xsi].hCboFieldType, xdi, 2    ;First character + ZTC
  m2m [xsi].MutationInfo.bActType, CHRA ptr [xdi], al

  ;Get the field length
  invoke GetWindowText, [xsi].hEdtFieldLength, xdi, lengthof cBuffer
  invoke dec2dword, xdi
  mov ebx, eax
  and ebx, 0FFh
  .if [xsi].MutationInfo.bActType == FDT_CHAR_WIDE
    .ifBitSet bl, BIT00
      MessageText textequ <Invalid length in WIDE Char field >
      FillTextA cBuffer, <%MessageText>
      invoke GetWindowTextA, [xsi].hEdtFieldName, addr [xdi + @SizeStr(%MessageText)], \
                            LOCAL_BUFFER_SIZE - @SizeStr(%MessageText)
      invoke StrCatA, xdi, $OfsCStrA(".", 10, 13, "Increasing length by 1.")
      mov xax, [xsi].pOwner                             ;xax -> Collection
      mov xcx, [xax].$Obj(Collection).pOwner            ;xcx -> DB_StructEditor
      invoke MessageBoxA, [xcx].$Obj(DB_StructEditor).hWnd, xdi, $OfsCStrA("Error"), \
                          MB_ICONWARNING or MB_OK
      inc ebx
      invoke dword2dec, xdi, ebx
      invoke SetWindowText, [xsi].hEdtFieldLength, xdi
    .endif
  .else
    .if bl == 0
      MessageText textequ <Invalid length in field >
      FillTextA cBuffer, <%MessageText>
      invoke GetWindowTextA, [xsi].hEdtFieldName, addr [xdi + @SizeStr(%MessageText)], \
                            LOCAL_BUFFER_SIZE - @SizeStr(%MessageText)
      invoke StrCatA, xdi, $OfsCStrA(".", 10, 13, "Correcting to length 1.")
      mov xax, [xsi].pOwner                             ;xax -> Collection
      mov xcx, [xax].$Obj(Collection).pOwner            ;xcx -> DB_StructEditor
      invoke MessageBoxA, [xcx].$Obj(DB_StructEditor).hWnd, xdi, $OfsCStrA("Error"), \
                          MB_ICONWARNING or MB_OK
      invoke SetWindowText, [xsi].hEdtFieldLength, $OfsCStr("1")
      mov bl, 1
    .endif
  .endif
  mov [xsi].MutationInfo.bActLength, bl

  ;Get the field parameter, e.g. Decimals or AutoIncrement
  invoke GetWindowText, [xsi].hEdtFieldParam, xdi, lengthof cBuffer
  invoke dec2dword, xdi
  mov [xsi].MutationInfo.dActParam, eax
  .if [xsi].MutationInfo.bActType == FDT_NUMERIC
    ;Check that Decimals is not larger than the field length - 2
    mov cl, [xsi].MutationInfo.bActLength
    dec cl
    .if al != 0 && cl <= al
      movzx eax, [xsi].MutationInfo.bActLength
      .if eax <= 2
        xor eax, eax
      .else
        sub eax, 2
      .endif
      mov [xsi].MutationInfo.dActParam, eax
      invoke dword2decA, addr bDwordBuffer, eax
      invoke SetWindowTextA, [xsi].hEdtFieldParam, addr bDwordBuffer

      MessageText textequ <Invalid decimals in NUMERIC field >
      FillTextA cBuffer, <%MessageText>
      invoke GetWindowTextA, [xsi].hEdtFieldName, addr [xdi + @SizeStr(%MessageText)], \
                             LOCAL_BUFFER_SIZE - @SizeStr(%MessageText)
      invoke StrECatA, xdi, $OfsCStrA(".", 10, 13, "Correcting to ")
      mov xcx, xax
      invoke StrECopyA, xcx, addr bDwordBuffer
      FillStringA [xax], < decimal place(s).>

      mov xax, [xsi].pOwner                             ;xax -> Collection
      mov xcx, [xax].$Obj(Collection).pOwner            ;xcx -> DB_StructEditor
      invoke MessageBoxA, [xcx].$Obj(DB_StructEditor).hWnd, xdi, $OfsCStrA("Error"), \
                          MB_ICONWARNING or MB_OK
    .endif
  .endif


  ;Get the field name (11 bytes, filled with zeros)
  lea xdi, [xsi].MutationInfo.bActName
  invoke GetWindowTextA, [xsi].hEdtFieldName, xdi, DB_FIELD_NAME_SIZE
  invoke StrLRTrimA, xdi, xdi
  ;Fill the rest of the field with zeros.
  invoke StrLengthA, xdi
  .if eax < DB_FIELD_NAME_LENGTH
    mov ecx, DB_FIELD_NAME_SIZE
    sub ecx, eax
    add xdi, xax
    xor eax, eax
    rep stosb
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     DB_StructEditorLine.CtlsSet
; Purpose:    Set the content of the controls and fill the "prv" members.
; Arguments:  Arg1: -> DB_Field.
;             Arg2: Field index.
; Return:     Nothing.

Method DB_StructEditorLine.CtlsSet, uses xbx xdi xsi, pField:$ObjPtr(DB_Field), dFieldIndex:DWORD
  local cBuffer[LOCAL_BUFFER_SIZE]:CHR

;  DbgText "DB_StructEditorLine.CtlsSet"
  SetObject xsi
  mov xbx, pField
  lea xdi, cBuffer

  m2m [xsi].dPrvFieldPos, dFieldIndex, eax

  ;Set the field name (11 bytes, filled with zeros)
  invoke SetWindowTextA, [xsi].hEdtFieldName, addr [xbx].$Obj(DB_Field).Descriptor.bName
  s2s [xsi].MutationInfo.bPrvName, [xbx].$Obj(DB_Field).Descriptor.bName, xax, xcx
  ;Set the field type
  movzx ax, [xbx].$Obj(DB_Field).Descriptor.bType
  mov WORD ptr [xdi], ax
  invoke SendMessageA, [xsi].hCboFieldType, CB_SELECTSTRING, 0, xdi
  m2m [xsi].MutationInfo.bPrvType, [xbx].$Obj(DB_Field).Descriptor.bType, al

  ;Set the field length
  movzx eax, [xbx].$Obj(DB_Field).Descriptor.bLength
  invoke dword2dec, xdi, eax
  invoke SetWindowText, [xsi].hEdtFieldLength, xdi
  m2m [xsi].MutationInfo.bPrvLength, [xbx].$Obj(DB_Field).Descriptor.bLength, al

  ;Set the field parameter, like Decimals or AutoIncrement
  .if [xbx].$Obj(DB_Field).Descriptor.bType == FDT_NUMERIC
    movzx eax, [xbx].$Obj(DB_Field).Descriptor.bDecimals
    mov [xsi].MutationInfo.dPrvParam, eax
    invoke dword2dec, xdi, eax
    movzx eax, [xbx].$Obj(DB_Field).Descriptor.bDecimals
  .elseif [xbx].$Obj(DB_Field).Descriptor.bType == FDT_AUTOINC
    mov eax, [xbx].$Obj(DB_Field).Descriptor.dAutoIncrement
    mov [xsi].MutationInfo.dPrvParam, eax
    invoke dword2dec, xdi, eax
  .else
    m2z CHR ptr [xdi]
    m2z [xsi].MutationInfo.dPrvParam
  .endif
  invoke SetWindowText, [xsi].hEdtFieldParam, xdi

  ;Set the field Index
  mov xcx, [xbx].$Obj(DB_Field).pIndex
  .if xcx != NULL
    mov xax, [xcx].$Obj(DB_Index).pFileName
  .else
    xor eax, eax
  .endif
  mov [xsi].pPrvFieldIndex, xcx
  invoke SetWindowText, [xsi].hEdtFieldIndex, xax
  
  ;Set formating information
  mov xcx, [xbx].$Obj(DB_Field).pOwner                  ;xcx -> Fields collection
  mov xdx, [xcx].$Obj(Collection).pOwner                   ;xdx -> DB_Table
  m2m [xsi].MutationInfo.pAppSetup, [xdx].$Obj(DB_Table).pAppSetup, xax

MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     DB_StructEditorLine.CtlsSetDefaults
; Purpose:    Set the content of the controls and xPrvxxx members with default values.
; Arguments:  None.
; Return:     Nothing.

Method DB_StructEditorLine.CtlsSetDefaults, uses xdi xsi
  local cBuffer[LOCAL_BUFFER_SIZE]:CHR

  SetObject xsi

;  DbgText "DB_StructEditorLine.CtlsSetDefaults"
  mov [xsi].dPrvFieldPos, -1                            ;New Field marker

  OCall [xsi].pOwner::Collection.IndexOf, xsi
  lea xdi, cBuffer
  inc eax
  invoke wsprintfA, xdi, $OfsCStrA("Field_%03u"), eax
  invoke SetWindowTextA, [xsi].hEdtFieldName, xdi

  ;Set the field type
  invoke SendMessageA, [xsi].hCboFieldType, CB_SELECTSTRING, 0, $OfsCStrA("C")

  ;Set the field length
  mov [xsi].MutationInfo.bPrvLength, 1
  invoke SetWindowText, [xsi].hEdtFieldLength, $OfsCStr("1")

  ;Set the field parameter, like Decimals or AutoIncrement
  mov [xsi].MutationInfo.dPrvParam, 0

  ;Set the field Index
  mov [xsi].pPrvFieldIndex, NULL

  OCall xsi.CtlsEnable, TRUE
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     DB_StructEditorLine.CtlsSetStandards
; Purpose:    Set the controls with standard field values.
; Arguments:  None.
; Return:     Nothing.

Method DB_StructEditorLine.CtlsSetStandards, uses xbx xdi xsi
  local cBuffer[LOCAL_BUFFER_SIZE]:CHR

;  DbgText "DB_StructEditorLine.CtlsSetStandards"
  SetObject xsi
  lea xbx, cBuffer

  invoke GetWindowTextA, [xsi].hCboFieldType, xbx, 2  ;First character + ZTC
  mov xdi, $invoke(DB_GetStdFieldInfo, BYTE ptr cBuffer)
  .if [xdi].STD_FIELD_INFO.bLength == 0
    movzx edx, [xsi].MutationInfo.bPrvLength
  .else
    movzx edx, [xdi].STD_FIELD_INFO.bLength
  .endif
  invoke dword2dec, xbx, edx
  invoke SetWindowText, [xsi].hEdtFieldLength, xbx

  .ifBitSet [xdi].STD_FIELD_INFO.bFlags, SFF_HAS_PARAM
    invoke dword2dec, xbx, [xsi].MutationInfo.dPrvParam
    lea xdx, cBuffer
  .else
    xor edx, edx
  .endif
  invoke SetWindowText, [xsi].hEdtFieldParam, xdx

  .ifBitSet [xdi].STD_FIELD_INFO.bFlags, SSF_NO_INDEX
    xor edx, edx
  .else
    mov xcx, [xsi].pPrvFieldIndex
    .if xcx == NULL
      xor edx, edx
    .else
      mov xdx, [xcx].$Obj(DB_Index).pFileName
    .endif
  .endif
  invoke SetWindowText, [xsi].hEdtFieldIndex, xdx
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     DB_StructEditorLine.CheckChanges
; Purpose:    Verify if there are changes in the line and set the flags accordingly.
; Arguments:  None.
; Return:     eax = TRUE if there are changes, otherwise FALSE.

Method DB_StructEditorLine.CheckChanges, uses xbx xsi
  local cBuffer[LOCAL_BUFFER_SIZE]:CHR

;  DbgText "DB_StructEditorLine.CheckChanges"
  SetObject xsi
  lea xbx, cBuffer
  OCall [xsi].pOwner::Collection.IndexOf, xsi
  .if eax == [xsi].dPrvFieldPos
    BitClr [xsi].dFlags, SEL_FLAG_CHANGE_POS
  .else
    BitSet [xsi].dFlags, SEL_FLAG_CHANGE_POS
  .endif

  invoke GetWindowTextA, [xsi].hEdtFieldName, xbx, lengthof(cBuffer)
  invoke StrLRTrimA, xbx, xbx
  invoke StrCompA, xbx, addr [xsi].MutationInfo.bPrvName
  .if eax == 0
    BitClr [xsi].dFlags, SEL_FLAG_CHANGE_NAME
  .else
    BitSet [xsi].dFlags, SEL_FLAG_CHANGE_NAME
  .endif

  invoke GetWindowTextA, [xsi].hCboFieldType, xbx, lengthof(cBuffer)
  mov al, CHRA ptr [xbx]
  .if al == [xsi].MutationInfo.bPrvType
    BitClr [xsi].dFlags, SEL_FLAG_CHANGE_TYPE
  .else
    BitSet [xsi].dFlags, SEL_FLAG_CHANGE_TYPE
  .endif

  .if $invoke(IsWindowEnabled, [xsi].hEdtFieldLength)
    invoke GetWindowText, [xsi].hEdtFieldLength, xbx, lengthof(cBuffer)
    invoke dec2dword, xbx
    .if al == [xsi].MutationInfo.bPrvLength
      BitClr [xsi].dFlags, SEL_FLAG_CHANGE_LENGTH
    .else
      BitSet [xsi].dFlags, SEL_FLAG_CHANGE_LENGTH
    .endif
  .endif

  .if $invoke(IsWindowEnabled, [xsi].hEdtFieldParam)
    invoke GetWindowText, [xsi].hEdtFieldParam, xbx, lengthof(cBuffer)
    invoke dec2dword, xbx
    .if eax == [xsi].MutationInfo.dPrvParam
      BitClr [xsi].dFlags, SEL_FLAG_CHANGE_PARAM
    .else
      BitSet [xsi].dFlags, SEL_FLAG_CHANGE_PARAM
    .endif
  .endif

  invoke GetWindowText, [xsi].hEdtFieldIndex, xbx, lengthof(cBuffer)
  invoke StrLRTrim, xbx, xbx
  mov xcx, [xsi].pPrvFieldIndex
  .if xcx == NULL
    .if CHR ptr [xbx] == 0
      BitClr [xsi].dFlags, SEL_FLAG_CHANGE_INDEX
    .else
      BitSet [xsi].dFlags, SEL_FLAG_CHANGE_INDEX
    .endif
  .else
    invoke StrComp, [xcx].$Obj(DB_Index).pFileName, xbx
    .if eax == 0
      BitClr [xsi].dFlags, SEL_FLAG_CHANGE_INDEX
    .else
      BitSet [xsi].dFlags, SEL_FLAG_CHANGE_INDEX
    .endif
  .endif

  mov ecx, [xsi].dFlags
  xor eax, eax
  test ecx, SEL_FLAG_CHANGE_ANY
  setnz al
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     DB_StructEditorLine.DisplayInfo
; Purpose:    Set the information icon on the left side of the editorline.
; Arguments:  None.
; Return:     Nothing.

Method DB_StructEditorLine.DisplayInfo, uses xsi
  SetObject xsi
  mov xdx, [xsi].pOwner                                 ;xdx -> EditorLines
  mov xcx, [xdx].$Obj(Collection).pOwner                ;xcx -> DB_StructEditor
  .ifBitSet [xsi].dFlags, SEL_FLAG_SELECTED
    .ifBitSet [xsi].dFlags, SEL_FLAG_DATA_LOSS
      mov xax, [xcx].$Obj(DB_StructEditor).hSelRed
    .elseIfBitSet [xsi].dFlags, SEL_FLAG_CHANGE_ANY     ;Check first for these changes
      mov xax, [xcx].$Obj(DB_StructEditor).hSelYellow
    .elseIfBitSet [xsi].dFlags, SEL_FLAG_CHANGES_SAVED  ;And finally for SEL_FLAG_CHANGES_SAVED
      mov xax, [xcx].$Obj(DB_StructEditor).hSelGreen
    .else
      mov xax, [xcx].$Obj(DB_StructEditor).hSelected
    .endif
  .else
    .ifBitSet [xsi].dFlags, SEL_FLAG_DATA_LOSS
      mov xax, [xcx].$Obj(DB_StructEditor).hUnselRed
    .elseIfBitSet [xsi].dFlags, SEL_FLAG_CHANGE_ANY
      mov xax, [xcx].$Obj(DB_StructEditor).hUnselYellow
    .elseIfBitSet [xsi].dFlags, SEL_FLAG_CHANGES_SAVED
      mov xax, [xcx].$Obj(DB_StructEditor).hUnselGreen
    .else
      mov xax, [xcx].$Obj(DB_StructEditor).hUnselected
    .endif
  .endif
  invoke SendMessage, [xsi].hStcInfo, STM_SETICON, xax, NULL
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     DB_StructEditorLine.Done
; Purpose:    Finalize the DB_StructEditorLine object.
; Arguments:  None.
; Return:     Nothing.

Method DB_StructEditorLine.Done, uses xsi
  SetObject xsi
  invoke DestroyWindow, [xsi].hStcInfo
  invoke DestroyWindow, [xsi].hEdtFieldName
  invoke DestroyWindow, [xsi].hCboFieldType
  invoke DestroyWindow, [xsi].hEdtFieldLength
  invoke DestroyWindow, [xsi].hUdcFieldLength
  invoke DestroyWindow, [xsi].hEdtFieldParam
  invoke DestroyWindow, [xsi].hUdcFieldParam
  invoke DestroyWindow, [xsi].hEdtFieldIndex
  ACall xsi.Done
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     DB_StructEditorLine.Init
; Purpose:    Initialize the DB_StructEditor object.
; Arguments:  Arg1: -> DB_StructEditor
; Note:       Avoid setting CtlIDs that equals IDOK and IDCANCEL.
;             If used and the control is disabled, these messages are no longer sent!

Method DB_StructEditorLine.Init, uses xbx xdi xsi, pOwner:$ObjPtr(Collection)
  local xCtlID:XWORD, cBuffer[2]:CHRW

  SetObject xsi
  ACall xsi.Init, pOwner
  mov xdx, pOwner
  mov xdi, [xdx].$Obj(Collection).pOwner                ;xdi -> DB_StructEditor
  assume xdi:$ObjPtr(DB_StructEditor)

  mov ecx, [xdx].$Obj(Collection).dCount                ;Starts with 1
  imul ecx, SEL_CTRLS_PER_LINE
  mov xCtlID, xcx
  ;Use the ANSI version of the control to pass the ANSI caption string (Descriptor.bName)
  invoke CreateWindowEx, 0, $OfsCStr("STATIC"), NULL, \
                         WS_CHILD or WS_VISIBLE or SS_ICON or SS_REALSIZECONTROL, \
                         CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, \
                         [xdi].hWnd, xCtlID, hInstance, 0
  mov [xsi].hStcInfo, xax
  invoke SetWindowLongPtr, [xsi].hEdtFieldName, GWLP_USERDATA, xsi
  invoke SendMessage, [xsi].hEdtFieldName, WM_SETFONT, [xdi].hFont, FALSE

  inc xCtlID
  invoke CreateWindowExA, WS_EX_CLIENTEDGE, $OfsCStrA("EDIT"), NULL, \
                          WS_CHILD or WS_VISIBLE or WS_TABSTOP or ES_AUTOHSCROLL, \
                          CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, \
                          [xdi].hWnd, xCtlID, hInstance, 0
  mov [xsi].hEdtFieldName, xax
  invoke SetWindowLongPtr, [xsi].hEdtFieldName, GWLP_USERDATA, xsi
  invoke SendMessage, [xsi].hEdtFieldName, WM_SETFONT, [xdi].hFont, FALSE
  invoke SendMessage, [xsi].hEdtFieldName, EM_LIMITTEXT, DB_FIELD_NAME_LENGTH, 0

  inc xCtlID
  invoke CreateWindowEx, 0, $OfsCStr("COMBOBOX"), NULL, \
                         WS_CHILD or WS_VISIBLE or WS_TABSTOP or CBS_DROPDOWNLIST,\
                         CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, \
                         [xdi].hWnd, xCtlID, hInstance, 0
  mov [xsi].hCboFieldType, xax
  invoke SetWindowLongPtr, [xsi].hCboFieldType, GWLP_USERDATA, xsi
  invoke SendMessage, [xsi].hCboFieldType, WM_SETFONT, [xdi].hFont, FALSE
  invoke SendMessage, [xsi].hCboFieldType, CB_SETEXTENDEDUI, TRUE, 0

  inc xCtlID
  invoke CreateWindowEx, WS_EX_CLIENTEDGE, $OfsCStr("EDIT"), NULL, \
                         WS_CHILD or WS_VISIBLE or WS_TABSTOP or ES_AUTOHSCROLL or ES_NUMBER,\
                         CW_USEDEFAULT, CW_USEDEFAULT, 20, 20, \
                         [xdi].hWnd, xCtlID, hInstance, 0
  mov [xsi].hEdtFieldLength, xax
  invoke SetWindowLongPtr, [xsi].hEdtFieldLength, GWLP_USERDATA, xsi
  invoke SendMessage, [xsi].hEdtFieldLength, WM_SETFONT, [xdi].hFont, FALSE
  invoke SendMessage, [xsi].hEdtFieldLength, EM_LIMITTEXT, 3, 0

  invoke CreateWindowEx, WS_EX_LEFT, $OfsCStr("msctls_updown32"), NULL, \
                         WS_CHILD or WS_VISIBLE or UDS_SETBUDDYINT or UDS_NOTHOUSANDS or \
                         UDS_ALIGNRIGHT or UDS_ARROWKEYS or UDS_HOTTRACK,\
                         CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, \
                         [xdi].hWnd, CTLID_FieldLength, hInstance, 0
  mov [xsi].hUdcFieldLength, xax
  invoke SendMessage, [xsi].hUdcFieldLength, UDM_SETBASE, 10, 0
  invoke SendMessage, [xsi].hUdcFieldLength, UDM_SETRANGE32, 0, 255

  inc xCtlID
  invoke CreateWindowEx, WS_EX_CLIENTEDGE, $OfsCStr("EDIT"), NULL, \
                         WS_CHILD or WS_VISIBLE or WS_TABSTOP or ES_AUTOHSCROLL or ES_NUMBER,\
                         CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, \
                         [xdi].hWnd, xCtlID, hInstance, 0
  mov [xsi].hEdtFieldParam, xax
  invoke SetWindowLongPtr, [xsi].hEdtFieldParam, GWLP_USERDATA, xsi
  invoke SendMessage, [xsi].hEdtFieldParam, WM_SETFONT, [xdi].hFont, FALSE
  invoke SendMessage, [xsi].hEdtFieldParam, EM_LIMITTEXT, 11, 0

  invoke CreateWindowEx, WS_EX_LEFT, $OfsCStr("msctls_updown32"), NULL, \
                         WS_CHILD or WS_VISIBLE or UDS_SETBUDDYINT or UDS_NOTHOUSANDS or \
                         UDS_ALIGNRIGHT or UDS_ARROWKEYS or UDS_HOTTRACK,\
                         CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, \
                         [xdi].hWnd, CTLID_FieldParam, hInstance, 0
  mov [xsi].hUdcFieldParam, xax
  invoke SendMessage, [xsi].hUdcFieldParam, UDM_SETBASE, 10, 0
  invoke SendMessage, [xsi].hUdcFieldParam, UDM_SETRANGE32, 0, 7FFFFFFFh

  inc xCtlID
  invoke CreateWindowEx, WS_EX_CLIENTEDGE, $OfsCStr("EDIT"), NULL, \
                         WS_CHILD or WS_VISIBLE or WS_TABSTOP or ES_AUTOHSCROLL,\
                         CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, \
                         [xdi].hWnd, xCtlID, hInstance, 0
  mov [xsi].hEdtFieldIndex, xax
  invoke SetWindowLongPtr, [xsi].hEdtFieldIndex, GWLP_USERDATA, xsi
  invoke SendMessage, [xsi].hEdtFieldIndex, WM_SETFONT, [xdi].hFont, FALSE
  invoke SendMessage, [xsi].hEdtFieldIndex, EM_LIMITTEXT, MAX_PATH, 0   ;Set a reasonable limit

  assume xdi:NOTHING

  ;Load the Field type ComboBox
  mov xbx, offset(StdFieldLookupTable)
  .while [xbx].STD_FIELD_INFO.bType != 0
    invoke SendMessage, [xsi].hCboFieldType, CB_ADDSTRING, 0, [xbx].STD_FIELD_INFO.pDesc
    add xbx, sizeof(STD_FIELD_INFO)
  .endw
  movzx cx, [xsi].MutationInfo.bActType
  mov cBuffer, cx
  invoke SendMessageA, [xsi].hCboFieldType, CB_SELECTSTRING, 0, addr cBuffer
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     DB_StructEditorLine.SetBuddy
; Purpose:    Link the UpDown controls to theier buddy controls.
; Arguments:  Arg1: None.
;             Arg2: None.

Method DB_StructEditorLine.SetBuddy, uses xsi, xUnused1:XWORD, xUnused2:XWORD
  SetObject xsi
  invoke SendMessage, [xsi].hUdcFieldLength, UDM_SETBUDDY, [xsi].hEdtFieldLength, 0
  invoke SendMessage, [xsi].hUdcFieldParam,  UDM_SETBUDDY, [xsi].hEdtFieldParam,  0
MethodEnd



; ==================================================================================================
; DB_StructEditor
; ==================================================================================================

CStr szDB_StructEditorClass, "DB_StructEditor"

; --------------------------------------------------------------------------------------------------
; Method:     DB_StructEditor.CtlsEnable
; Purpose:    Set the enable state of the controls.
; Arguments:  Arg1: TRUE or FALSE
; Return:     Nothing.

Method DB_StructEditor.CtlsEnable, uses xbx xsi, dState:DWORD
  SetObject xsi
  xor ebx, ebx
  .while ebx < [xsi].EditorLines.dCount
    OCall [xsi].EditorLines::Collection.ItemAt, ebx
    OCall xax::DB_StructEditorLine.CtlsEnable, dState
    inc ebx
  .endw
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     DB_StructEditor.CtlsGet
; Purpose:    Get the content of the editor controls and put it into the record fields.
; Arguments:  Arg1: -> DB_Record.
; Return:     eax = Error code.

Method DB_StructEditor.CtlsGet, uses xbx xdi xsi, pTable:$ObjPtr(DB_Table)
  local pEditorLine:$ObjPtr(DB_StructEditorLine), pField:$ObjPtr(DB_Field)
  local dOffset:DWORD, dHeaderLen:DWORD

;  DbgText "DB_StructEditor.CtlsGet"
  SetObject xsi
  mov xdi, pTable
  OCall [xdi].$Obj(DB_Table).Fields::Collection.DisposeAll

  xor ebx, ebx
  mov dOffset, 1                                        ;Deletion mark
  mov dHeaderLen, sizeof(DB_DATAFILE_DESCRIPTOR) + 1    ;+ Termination mark
  .while ebx < [xsi].EditorLines.dCount
    mov pEditorLine, $OCall([xsi].EditorLines::Collection.ItemAt, ebx)
    New DB_Field
    .if xax == NULL
      OCall xsi.ErrorReport, NULL, DB_OUT_OF_MEMORY
      DbgWarning "DB_StructEditor.CtlsGet: out of memory creating a DB_Field", offset(szDbgObjErr)
      ExitMethod
    .else
      mov pField, xax
      OCall pField::DB_Field.Init, addr [xdi].$Obj(DB_Table).Fields, dOffset
      OCall pEditorLine::DB_StructEditorLine.CtlsRead
      OCall pEditorLine::DB_StructEditorLine.CtlsGet, pField
      OCall [xdi].$Obj(DB_Table).Fields::Collection.Insert, pField    ;xax = pField
      movzx ecx, [xax].$Obj(DB_Field).Descriptor.bLength
      add dOffset, ecx
      add dHeaderLen, sizeof(DB_FIELD_DESCRIPTOR)
      inc ebx
    .endif
  .endw

  BitSet [xdi].$Obj(DB_Table).dFlags, DBT_HEADER_CHANGED
  mov eax, dOffset
  mov [xdi].$Obj(DB_Table).Descriptor.wRecordLen, ax
  mov ecx, dHeaderLen
  mov [xdi].$Obj(DB_Table).Descriptor.wHeaderLen, cx

  xor eax, eax
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     DB_StructEditor.CtlsInit
; Purpose:    Create and initialize the controls according to the DB_Table information
; Arguments:  None.
; Return:     Nothing.

Method DB_StructEditor.CtlsInit, uses xbx xsi
  local hParent:HWND, hDC:HDC, hPrevFont:HFONT

  SetObject xsi
  mov hParent, $invoke(GetParent, [xsi].hWnd)
  mov [xsi].hFont, $invoke(SendMessage, hParent, WM_GETFONT, 0, 0)
  mov hDC, $invoke(GetDC, hParent)
  mov hPrevFont, $invoke(SelectObject, hDC, [xsi].hFont)

  ;Translate the control metrics from DLU to pixel.
  invoke GetDlgBaseUnits, hDC                           ;eax = DBUX, ecx = DBUY
  mov ebx, eax

  mov [xsi].Margin.x,        $Dlu2PixX([xsi].Margin.x,     ebx)
  mov [xsi].Margin.y,        $Dlu2PixY([xsi].Margin.y,     ecx)
  mov [xsi].Separation.x,    $Dlu2PixX([xsi].Separation.x, ebx)
  mov [xsi].Separation.y,    $Dlu2PixY([xsi].Separation.y, ecx)
  mov [xsi].EdtSize.y,       $Dlu2PixY([xsi].EdtSize.y,    ecx)

  mov [xsi].InfoSize.y,      $Dlu2PixY([xsi].InfoSize.y,   ecx)
  mov [xsi].InfoSize.x,      eax                        ;Same as height

  mov [xsi].dFldNameWidth,   $Dlu2PixX([xsi].dFldNameWidth,   ebx)
  mov [xsi].dFldTypeWidth,   $Dlu2PixX([xsi].dFldTypeWidth,   ebx)
  mov [xsi].dFldLengthWidth, $Dlu2PixX([xsi].dFldLengthWidth, ebx)
  mov [xsi].dFldParamWidth,  $Dlu2PixX([xsi].dFldParamWidth,  ebx)

  ;Load some resources
  mov [xsi].hSelected,    $invoke(LoadImage, hInstance, $OfsCStr("ICON_SEL"), \
                                             IMAGE_ICON, 0, 0, 0)
  mov [xsi].hSelGreen,    $invoke(LoadImage, hInstance, $OfsCStr("ICON_SEL_GREEN"), \
                                             IMAGE_ICON, 0, 0, 0)
  mov [xsi].hSelYellow,   $invoke(LoadImage, hInstance, $OfsCStr("ICON_SEL_YELLOW"), \
                                             IMAGE_ICON, 0, 0, 0)
  mov [xsi].hSelRed,      $invoke(LoadImage, hInstance, $OfsCStr("ICON_SEL_RED"), \
                                             IMAGE_ICON, 0, 0, 0)
  mov [xsi].hUnselected,  $invoke(LoadImage, hInstance, $OfsCStr("ICON_USEL"), \
                                             IMAGE_ICON, 0, 0, 0)
  mov [xsi].hUnselGreen,  $invoke(LoadImage, hInstance, $OfsCStr("ICON_USEL_GREEN"), \
                                             IMAGE_ICON, 0, 0, 0)
  mov [xsi].hUnselYellow, $invoke(LoadImage, hInstance, $OfsCStr("ICON_USEL_YELLOW"), \
                                             IMAGE_ICON, 0, 0, 0)
  mov [xsi].hUnselRed,    $invoke(LoadImage, hInstance, $OfsCStr("ICON_USEL_RED"), \
                                             IMAGE_ICON, 0, 0, 0)

  invoke SelectObject, hDC, hPrevFont
  invoke ReleaseDC, hParent, hDC
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     DB_StructEditor.CtlsMove
; Purpose:    Reposition the controls according to the new Origin.
; Arguments:  None
; Return:     Nothing.

Method DB_StructEditor.CtlsMove, uses xsi
  local ScrollInfo:SCROLLINFO, CtrlPos:CTRL_POSITIONS

;  DbgText "DB_StructEditor.CtlsMove"

  SetObject xsi

  ;Calulate the control fix-positions and set the initial value for the line y-position
  s2s CtrlPos.LineOrigin, [xsi].ViewOrigin, xax, xcx
  xor eax, eax
  mov CtrlPos.sdPosX1, eax
  add eax, [xsi].InfoSize.x
  add eax, [xsi].Separation.x
  mov CtrlPos.sdPosX2, eax
  add eax, [xsi].dFldNameWidth
  add eax, [xsi].Separation.x
  mov CtrlPos.sdPosX3, eax
  add eax, [xsi].dFldTypeWidth
  add eax, [xsi].Separation.x
  mov CtrlPos.sdPosX4, eax
  add eax, [xsi].dFldLengthWidth
  add eax, [xsi].Separation.x
  mov CtrlPos.sdPosX5, eax
  add eax, [xsi].dFldParamWidth
  add eax, [xsi].Separation.x
  mov CtrlPos.sdPosX6, eax

  ;Lock all drawings and enable double buffering while the child windows are repositioned
  SetWndStyleEx [xsi].hWnd, WS_EX_COMPOSITED
  invoke SendMessage, [xsi].hWnd, WM_SETREDRAW, FALSE, 0

  mov eax, [xsi].EditorLines.dCount
  imul eax, SEL_CTRLS_PER_LINE
  mov [xsi].hDWP, $invoke(BeginDeferWindowPos, eax)
  mov xdx, $MethodAddr(DB_StructEditorLine.CtlsMove)
  OCall [xsi].EditorLines::Collection.ForEach, xdx, xsi, addr CtrlPos
  invoke EndDeferWindowPos, [xsi].hDWP
  mov xdx, $MethodAddr(DB_StructEditorLine.SetBuddy)
  OCall [xsi].EditorLines::Collection.ForEach, xdx, 0, 0

  ;Update the Scrollbar information.
  ;This API shows/hides the Scrollbar automatically and may retrigger a WM_SIZE.
  mov ScrollInfo.cbSize, sizeof(ScrollInfo)
  mov ScrollInfo.fMask, SIF_PAGE or SIF_RANGE or SIF_POS
  mov ScrollInfo.nMin, 0
  mov eax, [xsi].ViewExtent.y
  dec eax
  mov ScrollInfo.nMax, eax
  mov eax, [xsi].CtlSize.y
  mov ScrollInfo.nPage, eax
  mov edx, [xsi].ViewOrigin.y
  neg edx
  mov ScrollInfo.nPos, edx
  invoke SetScrollInfo, [xsi].hWnd, SB_VERT, addr ScrollInfo, FALSE

  ;Reenable drawing and reset double buffering to allow smooth effect transitions
  invoke SendMessage, [xsi].hWnd, WM_SETREDRAW, TRUE, 0
  invoke InvalidateRect, [xsi].hWnd, NULL, TRUE
  mov [xsi].dAllowErase, TRUE
  invoke RedrawWindow, [xsi].hWnd, NULL, 0, RDW_UPDATENOW
  ClrWndStyleEx [xsi].hWnd, WS_EX_COMPOSITED
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     DB_StructEditor.CtlsRead
; Purpose:    Read the content of the editor controls and put it into the Actxxx members.
; Arguments:  None.
; Return:     Nothing.

Method DB_StructEditor.CtlsRead, uses xbx xsi
  SetObject xsi
  xor ebx, ebx
  .while ebx < [xsi].EditorLines.dCount
    OCall [xsi].EditorLines::Collection.ItemAt, ebx
    OCall xax::DB_StructEditorLine.CtlsRead
    inc ebx
  .endw
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     DB_StructEditor.CtlsSet
; Purpose:    Set the editor controls with the content of the table fields.
; Arguments:  Arg1: -> DB_Table.
; Return:     Nothing.

Method DB_StructEditor.CtlsSet, uses xbx xdi xsi, pTable:$ObjPtr(DB_Table)
  local pEditorLine:$ObjPtr(DB_StructEditorLine)

  SetObject xsi
  OCall [xsi].EditorLines::Collection.DisposeAll
  mov xdi, pTable
  xor ebx, ebx
  .while ebx < [xdi].$Obj(DB_Table).Fields.dCount
    New DB_StructEditorLine
    .if xax == NULL
      OCall xsi.ErrorReport, NULL, DB_OUT_OF_MEMORY
      DbgWarning "DB_StructEditor.Set: out of memory creating a DB_StructEditorLine", \
                  offset(szDbgObjErr)
      .break
    .endif
    mov pEditorLine, xax
    BitSet [xax].$Obj(DB_StructEditorLine).dFlags, SEL_FLAG_INIT

    OCall pEditorLine::DB_StructEditorLine.Init, addr [xsi].EditorLines
    OCall [xdi].$Obj(DB_Table).Fields::Collection.ItemAt, ebx
    OCall pEditorLine::DB_StructEditorLine.CtlsSet, xax, ebx
    invoke IsWindowEnabled, [xsi].hWnd
    OCall pEditorLine::DB_StructEditorLine.CtlsEnable, eax
    OCall [xsi].EditorLines::Collection.Insert, pEditorLine

    mov xcx, pEditorLine
    BitClr [xcx].$Obj(DB_StructEditorLine).dFlags, SEL_FLAG_CHANGE_ANY or \
                                                   SEL_FLAG_DATA_LOSS or SEL_FLAG_INIT
    inc ebx
  .endw
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     DB_StructEditor.Dispatch
; Purpose:    Dispatching of window messages.
; Arguments:  Arg1: Window handle.
;             Arg2: Message identifier.
;             Arg3: First message parameter.
;             Arg4: Second message parameter.
; Return:     eax = This value is the result of the message processing and depends on the message.

Method DB_StructEditor.Dispatch, uses xsi, hWnd:HWND, uMsg:DWORD, wParam:WPARAM, lParam:LPARAM
;  DbgMessage uMsg
  SetObject xsi
  DispatchEvent <DefWindowProc, hWnd>                   ;xsi -> Object instance
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     DB_StructEditor.Done
; Purpose:    Finalize the DB_StructEditor object.
; Arguments:  None.
; Return:     Nothing.

Method DB_StructEditor.Done, uses xsi
  SetObject xsi
  OCall [xsi].EditorLines::Collection.Done
  invoke DeleteObject, [xsi].hSelected
  invoke DeleteObject, [xsi].hSelRed
  invoke DeleteObject, [xsi].hSelYellow
  invoke DeleteObject, [xsi].hSelGreen
  invoke DeleteObject, [xsi].hUnselRed
  invoke DeleteObject, [xsi].hUnselYellow
  invoke DeleteObject, [xsi].hUnselGreen
  ACall xsi.Done
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     DB_StructEditor.Init
; Purpose:    Initialize the DB_StructEditor object.
; Arguments:  Arg1: -> Owner object.
;             Arg2: Parent window HANDLE.
; Return:     xax = hWnd or 0 if failed.

Method DB_StructEditor.Init, uses xsi, pOwner:POINTER, hParent:HWND
;  DbgText "DB_StructEditor.Init"

  SetObject xsi
  ACall xsi.Init, pOwner, 0

  ;Create DB_StructEditor Window
  invoke CreateWindowEx, 0, offset(szDB_StructEditorClass), NULL, \
                         WS_CHILD or WS_CLIPSIBLINGS or WS_CLIPCHILDREN or WS_VSCROLL, \
                         CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, \
                         hParent, NULL, hInstance, 0
  .if xax != 0
    mov [xsi].hWnd, xax
    invoke ShowWindow, [xsi].hWnd, SW_SHOWDEFAULT
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     DB_StructEditor.InitRes
; Purpose:    Initialize the Button object from a resource.
; Arguments:  Arg1: Button window handle.
; Return:     Nothing.

Method DB_StructEditor.InitRes,, hWnd:HWND
;  DbgText "DB_StructEditor.InitRes"
  SetObject xcx
  ?mov xdx, hWnd
  mov [xcx].hWnd, xdx
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     DB_StructEditor.OnCommand
; Purpose:    Event procedure for WM_COMMAND message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method DB_StructEditor.OnCommand, uses xbx xsi, wParam:WPARAM, lParam:LPARAM
;  DbgText "DB_StructEditor.OnCommand"
  SetObject xsi
  mov xax, wParam
  shr eax, 16
  .if ax == CBN_SELCHANGE
    invoke GetWindowLongPtr, lParam, GWLP_USERDATA      ;xax -> DB_StructEditorLine
    .ifBitClr [xax].$Obj(DB_StructEditorLine).dFlags, SEL_FLAG_INIT
      mov xbx, xax
      OCall xbx::DB_StructEditorLine.CtlsSetStandards   ;Check standard field content
      OCall xbx::DB_StructEditorLine.CtlsEnable, TRUE   ;Set enable state
      OCall xbx::DB_StructEditorLine.CheckChanges
      OCall xbx::DB_StructEditorLine.DisplayInfo
    .endif
  .elseif ax == EN_CHANGE
    invoke GetWindowLongPtr, lParam, GWLP_USERDATA      ;xax -> DB_StructEditorLine
    .ifBitClr [xax].$Obj(DB_StructEditorLine).dFlags, SEL_FLAG_INIT
      mov xbx, xax
      OCall xbx::DB_StructEditorLine.CheckChanges
      OCall xbx::DB_StructEditorLine.DisplayInfo
    .endif
  .endif

  .if ax == EN_SETFOCUS || ax == CBN_SETFOCUS
    invoke GetWindowLongPtr, lParam, GWLP_USERDATA      ;xax -> DB_StructEditorLine
    .if xax != NULL
      OCall xsi.Select, xax
    .endif
  .endif
  xor eax, eax
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     DB_StructEditor.OnCreate
; Purpose:    Event procedure for WM_CREATE message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero to continue the window creation process and -1 to stop it.

Method DB_StructEditor.OnCreate, uses xsi, wParam:WPARAM, lParam:LPARAM
;  DbgText "DB_StructEditor.OnCreate"
  SetObject xsi
  OCall [xsi].EditorLines::Collection.Init, xsi, 10, 10, COL_MAX_CAPACITY
  xor eax, eax
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     DB_StructEditor.OnEnable
; Purpose:    Event procedure for WM_ENABLE message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method DB_StructEditor.OnEnable,, wParam:WPARAM, lParam:LPARAM
;  DbgText "DB_StructEditor.OnEnable"
  SetObject xcx
  mov xax, wParam
  OCall xcx.CtlsEnable, eax
  xor eax, eax
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     DB_StructEditor.OnEraseBkgnd
; Purpose:    Event procedure for WM_ERASEBKGND message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Non zero if handled.

Method DB_StructEditor.OnEraseBkgnd, uses xsi, wParam:WPARAM, lParam:LPARAM
  local CRect:RECT

;  DbgText "DB_StructEditor.OnEraseBkgnd"
  SetObject xsi
  .if [xsi].dAllowErase == TRUE
    mov [xsi].dAllowErase, FALSE
    invoke GetClientRect, [xsi].hWnd, addr CRect
    invoke GetParent, [xsi].hWnd
    invoke SendMessage, xax, WM_CTLCOLORSTATIC, wParam, [xsi].hWnd  ;On return xax = Brush handle
    lea xdx, CRect
    invoke FillRect, wParam, xdx, xax
  .endif
  mov eax, TRUE
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     DB_StructEditor.OnMouseWheel
; Purpose:    Event procedure for WM_MOUSEWHEEL message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     Nothing.

Method DB_StructEditor.OnMouseWheel, uses xsi, wParam:WPARAM, lParam:LPARAM
;  DbgText "DB_StructEditor.OnMouseWheel"
  SetObject xsi
  mov eax, [xsi].ViewExtent.y
  .if eax > [xsi].CtlSize.y
    mov xdx, wParam
    shr edx, 16
    movsx ecx, dx                                       ;ecx = distance the wheel is rotated
    mov eax, [xsi].ViewOrigin.y

    ;Vertical scroll
    .ifBitSet wParam, MK_CONTROL
      ;Page scroll
      .if SDWORD ptr ecx > 0
        add eax, [xsi].CtlSize.y
      .else
        sub eax, [xsi].CtlSize.y
      .endif
    .else
      ;Regular scroll = 120 px
      .if SDWORD ptr ecx < 0
        mov eax, [xsi].ViewOrigin.y
        mov ecx, [xsi].Separation.y
        cdq
        idiv ecx
        dec eax
        imul ecx
        mov ecx, [xsi].ViewExtent.y
        sub ecx, [xsi].CtlSize.y
        neg ecx
        .if SDWORD ptr eax < ecx
          mov eax, ecx
        .endif
      .else
        mov eax, [xsi].ViewOrigin.y
        mov ecx, [xsi].Separation.y
        cdq
        idiv ecx
        .if edx == 0
          inc eax
        .endif
        imul ecx
        .if SDWORD ptr eax > 0
          xor eax, eax
        .endif
      .endif
    .endif

    ;Bound check
    .if SDWORD ptr eax > 0
      xor eax, eax
    .else
      mov ecx, [xsi].ViewExtent.y
      sub ecx, [xsi].CtlSize.y
      neg ecx
      .if SDWORD ptr eax < ecx
        mov eax, ecx
      .endif
    .endif

    .if eax != [xsi].ViewOrigin.y
      mov [xsi].ViewOrigin.y, eax

      OCall xsi.CtlsMove
    .endif
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     DB_StructEditor.OnSize
; Purpose:    Event procedure for WM_SIZE message.
; Arguments:  Arg1: First message parameter. wParam = SIZE_xxx
;             Arg2: Second message parameter. lParam = POINTS containing client area size.
; Return:     eax = Zero if handled.

Method DB_StructEditor.OnSize, uses xsi, wParam:WPARAM, lParam:LPARAM
  local NewCtlSize:POINT

;  DbgText "DB_StructEditor.OnSize"
  SetObject xsi

  .if wParam != SIZE_MINIMIZED && lParam != 0           ;x = 0 & y = 0
    PntS2Pnt NewCtlSize, lParam

    mov eax, NewCtlSize.y
    .if eax > [xsi].CtlSize.y
      sub eax, [xsi].CtlSize.y
      add [xsi].ViewOrigin.y, eax
      .if !SIGN?
        m2z [xsi].ViewOrigin.y
      .endif
    .endif
    s2s [xsi].CtlSize, NewCtlSize, xax, xcx

    mov eax, [xsi].EditorLines.dCount
    .if eax != 0
      ;Calculate the new ViewExtent
      m2m [xsi].ViewExtent.x, [xsi].CtlSize.x, edx
      dec eax
      mul [xsi].Separation.y
      add eax, [xsi].EdtSize.y
      mov ecx, [xsi].Margin.y
      shl ecx, 1
      add ecx, eax
      xor eax, eax
    .else
      xor ecx, ecx
    .endif
    mov [xsi].ViewExtent.y, ecx

    ;Calculate the X size of the last edit control.
    mov edx, [xsi].CtlSize.x
    sub edx, [xsi].Margin.x
    .if ecx > [xsi].CtlSize.y
      sub edx, [xsi].Margin.x
    .endif
    mov eax, [xsi].Separation.x
    imul eax, SEL_CTRLS_PER_LINE - 1
    sub edx, eax
    sub edx, [xsi].InfoSize.x
    sub edx, [xsi].dFldNameWidth
    sub edx, [xsi].dFldTypeWidth
    sub edx, [xsi].dFldLengthWidth
    sub edx, [xsi].dFldParamWidth
    mov [xsi].EdtSize.x, edx

    OCall xsi.CtlsMove

    xor eax, eax
  .else
    mov eax, -1
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     DB_StructEditor.OnVScroll
; Purpose:    Event procedure for WM_VSCROLL message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method DB_StructEditor.OnVScroll, uses xsi, wParam:WPARAM, lParam:LPARAM
  local ScrollInfo:SCROLLINFO

;  DbgText "DB_StructEditor.OnVScroll"
  SetObject xsi
  mov xax, wParam
  .if ax == SB_THUMBTRACK
    mov ScrollInfo.cbSize, sizeof(ScrollInfo)
    mov ScrollInfo.fMask, SIF_TRACKPOS
    invoke GetScrollInfo, [xsi].hWnd, SB_VERT, addr ScrollInfo
    mov eax, ScrollInfo.nTrackPos
    neg eax

  .elseif ax == SB_LINEUP
    mov eax, [xsi].ViewOrigin.y
    mov ecx, [xsi].Separation.y
    cdq
    idiv ecx
    .if edx == 0
      inc eax
    .endif
    imul ecx
    .if SDWORD ptr eax > 0
      xor eax, eax
    .endif

  .elseif ax == SB_LINEDOWN
    mov eax, [xsi].ViewOrigin.y
    mov ecx, [xsi].Separation.y
    cdq
    idiv ecx
    dec eax
    imul ecx
    mov ecx, [xsi].ViewExtent.y
    sub ecx, [xsi].CtlSize.y
    neg ecx
    .if SDWORD ptr eax < ecx
      mov eax, ecx
    .endif

  .elseif ax == SB_PAGEUP
    mov eax, [xsi].ViewOrigin.y
    mov ecx, [xsi].CtlSize.y
    add eax, ecx
    .if SDWORD ptr eax > 0
      xor eax, eax
    .endif

  .elseif ax == SB_PAGEDOWN
    mov eax, [xsi].ViewOrigin.y
    mov ecx, [xsi].CtlSize.y
    sub eax, ecx
    mov ecx, [xsi].ViewExtent.y
    sub ecx, [xsi].CtlSize.y
    neg ecx
    .if SDWORD ptr eax < ecx
      mov eax, ecx
    .endif

  .else
    jmp @F
  .endif

  mov [xsi].ViewOrigin.y, eax

  OCall xsi.CtlsMove

@@:
  xor eax, eax
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     DB_StructEditor.Select
; Purpose:    Select a new DB_StructEditorLine. The previous is deselected.
; Arguments:  Arg1: -> DB_StructEditorLine.
; Return:     Nothing.

Method DB_StructEditor.Select, uses xsi, pEditorLine:$ObjPtr(DB_StructEditorLine)
;  DbgText "DB_StructEditor.Select"
  SetObject xsi
  .if [xsi].pSelEditorLine != NULL
    mov xcx, [xsi].pSelEditorLine
    mov edx, [xcx].$Obj(DB_StructEditorLine).dFlags
    BitClr edx, SEL_FLAG_SELECTED
    mov [xcx].$Obj(DB_StructEditorLine).dFlags, edx
    OCall [xsi].pSelEditorLine::DB_StructEditorLine.CheckChanges
    OCall [xsi].pSelEditorLine::DB_StructEditorLine.DisplayInfo
  .endif
  mrm [xsi].pSelEditorLine, pEditorLine, xcx
  .if xcx != NULL
    mov edx, [xcx].$Obj(DB_StructEditorLine).dFlags
    BitSet edx, SEL_FLAG_SELECTED
    mov [xcx].$Obj(DB_StructEditorLine).dFlags, edx
    OCall xcx::DB_StructEditorLine.DisplayInfo
  .endif

  ;Notify parent to update its own controls
  invoke GetParent, [xsi].hWnd
  invoke SendMessage, xax, WM_COMMAND, IDC_STRUC_EDT, [xsi].hWnd
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     DB_StructEditor.Startup
; Purpose:    Register the DB_StructEditor object with the OS.
; Arguments:  None.
; Return:     Nothing.

Method DB_StructEditor.Startup
  local WC:WNDCLASSEX

;  DbgText "DB_StructEditor.Startup"
  mov WC.cbSize, sizeof(WNDCLASSEX)
  mov WC.style, 0
  m2m WC.lpfnWndProc, $MethodAddr(DB_StructEditor.WndProc), xdx
  m2z WC.cbClsExtra
  m2z WC.cbWndExtra
  m2m WC.hInstance, hInstance, edx
  mov WC.hbrBackground, 0
  m2z WC.lpszMenuName
  c2m WC.lpszClassName, offset(szDB_StructEditorClass), xdx
  m2z WC.hIcon
  mov WC.hCursor, $invoke(LoadCursor, 0, IDC_ARROW)
  m2z WC.hIconSm

  invoke RegisterClassEx, addr WC
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     DB_StructEditor.WindowProc
; Purpose:    Processing of window messages.
; Arguments:  Arg1: Message identifier.
;             Arg2: First message parameter.
;             Arg3: Second message parameter.
; Return:     eax = The value is the result of the message processing and depends on the message ID.
; Note:       Window HANDLE is passed in pSelf (hidden argument).

Method DB_StructEditor.WndProc, uses xsi, uMsg:DWORD, wParam:WPARAM, lParam:LPARAM
;  DbgMessage uMsg, "DB_StructEditor.WndProc"

  .if uMsg == WM_NCCREATE
    mov xax, lParam
    .if [xax].CREATESTRUCT.lpCreateParams == NULL
      ;If lpCreateParams is 0, then it is a resource call => Create new object instance
      mov xsi, $New(DB_StructEditor)
      OCall xax::DB_StructEditor.InitRes, pSelf
    .else
      ;Init call
      mov xsi, [xax].CREATESTRUCT.lpCreateParams
      m2m [xsi].$Obj(DB_StructEditor).hWnd, pSelf, xdx
    .endif
    invoke SetWindowLongPtr, pSelf, GWLP_USERDATA, xsi
    OCall xsi::DB_StructEditor.Dispatch, pSelf, uMsg, wParam, lParam
  .else
    invoke GetWindowLongPtr, pSelf, GWLP_USERDATA       ;If GWL_USERDATA wasn't set,
    .if xax == NULL                                     ;GetWindowLong returns NULL
      invoke DefWindowProc, pSelf, uMsg, wParam, lParam
    .else
      OCall xax::DB_StructEditor.Dispatch, pSelf, uMsg, wParam, lParam
    .endif
  .endif
MethodEnd

endif
