; ==================================================================================================
; Title:      PlotXY.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm support of PlotXY objects.
; Notes:      Version 1.0.0, October 2017
;               - First release.
; ==================================================================================================


DefaultScaleOptions record  AutoMin:1 = TRUE, AutoMax:1 = TRUE,
                            AutoMjrDiv:1 = TRUE, AutoMnrDiv:1 = TRUE,
                            ShowGrid:1 = TRUE, XasDate:1 = FALSE

SCALE_BASIC_DATA struc
  r4SetupMax    REAL4       1.0                         ;Setup max value
  r4SetupMin    REAL4       0.0                         ;Setup min value
  r4DataMax     REAL4       1.0                         ;Data max value
  r4DataMin     REAL4       0.0                         ;Data min value
  dSetupMjrDiv  DWORD       2                           ;Setup major divisions
  dSetupMnrDiv  DWORD       2                           ;Setup minor divisions
  dDataMjrDiv   DWORD       2                           ;Data major divisions
  dDataMnrDiv   DWORD       2                           ;Data minor divisions
  bOptions      BYTE        DefaultScaleOptions         ;Scale options
  pDesc         PSTRING     NULL                        ;-> Desrciption string (local allocated)
  pUnit         PSTRING     NULL                        ;-> Unit string (local allocated)
  r8TimeStart   REAL8       0.0                         ;Data/Time of start point
SCALE_BASIC_DATA ends
PSCALE_BASIC_DATA typedef ptr SCALE_BASIC_DATA

SCALE_INTERNAL_DATA struc
  dDigits       DWORD       1                           ;Number of digits used to draw labels
  r4ScaleMax    REAL4       1.0                         ;Max used for drawing scale
  r4ScaleMin    REAL4       0.0                         ;Min used for drawing scale
  r4TickMjrFst  REAL4       0.0                         ;Value of first major tick in plot range
  r4TickMjrStp  REAL4       0.0                         ;Value major tick step
  dTickMjrLen   DWORD       0                           ;Size of major tick
  dTickMnrLen   DWORD       0                           ;Size of minor tick
  dTickMnrCount DWORD       0                           ;Number of minor ticks between major ticks
  dTitleSep     DWORD       0                           ;Title separation
  dLabelSep     DWORD       0                           ;Label separation
  pTitle        PSTRING     NULL                        ;Title string (local allocated)
  pFormatStr    PSTRING     NULL                        ;Label format string (local allocated)
  r4ScaleFactor REAL4       1.0                         ;Scale drawing factor
SCALE_INTERNAL_DATA ends
PSCALE_INTERNAL_DATA typedef ptr SCALE_INTERNAL_DATA

SCALE_DATA struc
  SCALE_BASIC_DATA          {}
  SCALE_INTERNAL_DATA       {}
SCALE_DATA ends
PSCALE_DATA typedef ptr SCALE_DATA

COLOR_CONFIG struc
  dGrid         DWORD       $RGB(128, 128, 128)         ;Grid color
  dPlotArea     DWORD       $RGB(255, 255, 255)         ;Plot area color
  dPlotBorder   DWORD       $RGB(000, 000, 000)         ;Plot border color
  dBackground   DWORD       $RGB(191, 191, 191)         ;Background color
  dScales       DWORD       $RGB(000, 000, 000)         ;Ticks and Scale labels
COLOR_CONFIG ends
PCOLOR_CONFIG typedef ptr COLOR_CONFIG

PLOTXY_DATA struc
  pCollDataX    $ObjPtr(Collection)   NULL              ;Collection of X-Data
  pCollDataY    $ObjPtr(Collection)   NULL              ;Collection of Y-Data
  ScaleX        SCALE_DATA    {}                        ;
  ScaleY        SCALE_DATA    {}                        ;
  Colors        COLOR_CONFIG  {}                        ;
PLOTXY_DATA ends
PPLOTXY_DATA typedef ptr PLOTXY_DATA

NOSELECTION     equ     0
SCALEX          equ     1
SCALEY          equ     2
PLOT            equ     3



;https://docs.microsoft.com/de-de/cpp/c-runtime-library/format-specification-syntax-printf-and-wprintf-functions?view=vs-2019


; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Object:  PlotXY
; Purpose: This object draws a XY plot on a surface. It works using the DataBufferXY object, that
;          holds the information for each data line on the plot. 2 specialized dialogs,
;          DialogSetupScale and DialogSetupColors are used to customize the drawing. They are called
;          when the user doubleclicks on some plot element.
;          Simple drag mouse movements moves the plot area, while pressing the SHIFT key, the plot
;          area is resized.
; Note:    - X and Y data must by single presicion numbers (REAL4).

Object PlotXY, PlotXYID, MsgInterceptor
  VirtualMethod     Calc,               HDC, PRECT
  VirtualMethod     CalcTicks,          PSCALE_DATA
  RedefineMethod    Done
  VirtualMethod     Frame,              HDC, BYTE                   ;hDC, B&W switch
  RedefineMethod    Init,               POINTER, HWND, PPLOTXY_DATA
  VirtualMethod     Plot,               HDC, BYTE                   ;hDC, B&W switch
  VirtualMethod     Refresh
  VirtualMethod     Show,               HDC, PRECT
  RedefineMethod    WndProc,            DWORD, WPARAM, LPARAM

  VirtualEvent      OnMouseMove,        WM_MOUSEMOVE
  VirtualEvent      OnLButtonDblClk,    WM_LBUTTONDBLCLK
  VirtualEvent      OnLButtonDown,      WM_LBUTTONDOWN
  VirtualEvent      OnLButtonUp,        WM_LBUTTONUP

  DefineVariable    PlotXYData,         PLOTXY_DATA,    {}
  DefineVariable    OutputRect,         RECT,           {}
  DefineVariable    PlotRect,           RECT,           {}
  DefineVariable    hFontHorz,          HFONT,          0           ;Horizontal font
  DefineVariable    hFontVert,          HFONT,          0           ;Vertical font
  DefineVariable    bMovingOn,          BYTE,           NOSELECTION ;Selected element
  DefineVariable    MovedLastPoint,     POINT,          {}
ObjectEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Object:  DataBufferXY
; Purpose: Implement a PlotXY internally used data array buffer.

Object DataBufferXY, DataBufferXYID, Array
  RedefineMethod    Done                                            ;Disposes allocated resources
  RedefineMethod    Init,               POINTER, DWORD, DWORD       ;-> Owner, Capacity, DataSize
  RedefineMethod    Load,               $ObjPtr(Stream)             ;-> Stream
  DynamicMethod     Scan,               DWORD, DWORD                ;Scans the buffer from .. to ..
  RedefineMethod    Store,              $ObjPtr(Stream)             ;-> Stream

  DefineVariable    pName,              PSTRING,    NULL            ;-> Buffer name
  DefineVariable    pDesc,              PSTRING,    NULL            ;-> Buffer description
  DefineVariable    pUnit,              PSTRING,    NULL            ;-> Buffer measuring unit
  DefineVariable    dLineColor,         DWORD,      $RGB(0,0,0)     ;Plot line color
  DefineVariable    dLineWidth,         DWORD,      1
  DefineVariable    dDateStamp,         DWORD,      0
  DefineVariable    dTimeStamp,         DWORD,      0
  DefineVariable    dMaxIndex,          DWORD,      -1              ;Biggest data element index
  DefineVariable    dMinIndex,          DWORD,      -1              ;Smallest data element index
ObjectEnd


; ——————————————————————————————————————————————————————————————————————————————————————————————————

IDC_DSS_PREVIEW     equ     100
IDC_DSS_COLORS      equ     101

IDC_DSS_CHECKMIN    equ     104
IDC_DSS_CHECKMAX    equ     105
IDC_DSS_CHECKMJR    equ     106
IDC_DSS_CHECKMNR    equ     107

IDC_DSS_EDITMIN     equ     108
IDC_DSS_EDITMAX     equ     109
IDC_DSS_EDITMJR     equ     110
IDC_DSS_EDITMNR     equ     111

IDC_DSS_EDITDESC    equ     112
IDC_DSS_EDITUNIT    equ     113

IDC_DSS_CHECKGRID   equ     114

IDC_DSS_STATIC0     equ     115
IDC_DSS_STATIC1     equ     116
IDC_DSS_STATIC2     equ     117
IDC_DSS_STATIC3     equ     118
IDC_DSS_STATIC4     equ     119

Object DialogSetupScale,, DialogModal
  RedefineMethod    CtlsSet
  RedefineMethod    CtlsGet
  RedefineMethod    Done
  RedefineMethod    Init,               POINTER, HWND, PSCALE_BASIC_DATA
  RedefineMethod    OnCommand,          WPARAM, LPARAM

  VirtualEvent      OnClose,            WM_CLOSE

  DefineVariable    pScaleData,         PSCALE_DATA,      NULL
  DefineVariable    pPrevDesc,          PSTRING,          NULL
  DefineVariable    pPrevUnit,          PSTRING,          NULL
  DefineVariable    PrvScaleData,       SCALE_BASIC_DATA, {}
ObjectEnd


; ——————————————————————————————————————————————————————————————————————————————————————————————————

IDC_SGC_PREVIEW     equ     100

IDC_SGC_LINE        equ     101
IDC_SGC_GRID        equ     102
IDC_SGC_PLOTAREA    equ     103
IDC_SGC_PLOTBORDER  equ     104
IDC_SGC_BACKGROUND  equ     105
IDC_SGC_SCALES      equ     106

Object DialogSetupColors,, DialogModal
  RedefineMethod    CtlsGet
  RedefineMethod    CtlsSet
  RedefineMethod    Init,               POINTER, HWND
  RedefineMethod    OnCommand,          WPARAM, LPARAM

  VirtualEvent      OnClose,            WM_CLOSE

  DefineVariable    NewColors,          COLOR_CONFIG,     {}  ;Work copy
  DefineVariable    PrvColors,          COLOR_CONFIG,     {}  ;Backup copy
ObjectEnd


; ==================================================================================================

if IMPLEMENT

CStr szPlotXYProp, "PlotXY"

; ==================================================================================================
;    Auxiliary procedures
; ==================================================================================================

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  GetFormatStr
; Purpose:    Generate a format string that must be destroyed after use.
; Arguments:  Number of digits.
; Return:     xax -> string.
; Help:       http://www.cplusplus.com/reference/clibrary/cstdio/sprintf/

GetFormatStr proc uses xbx dDigits:SDWORD
  local cBuffer[256]:CHR

  lea xbx, cBuffer
  m2z CHR ptr [xbx]
  .if dDigits >= 0
    invoke StrCat, xbx, $OfsCStr("%.")
    add xbx, 2*sizeof CHR
    invoke dword2dec, xbx, dDigits
  .else
    invoke StrCopy, xbx, $OfsCStr("%0")
  .endif
  invoke StrCatChar, xbx, "f"
  invoke StrNew, addr cBuffer
  ret
GetFormatStr endp


; ==================================================================================================
;    PlotXY implementation
; ==================================================================================================

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     PlotXY.Calc
; Purpose:    Compute internal values of the plot.
; Arguments:  Arg1: Output device context.
;             Arg2: -> Output rect.
; Return:     Nothing.

Method PlotXY.Calc, uses xdi xbx xsi, hDC:HWND, pRect:PRECT
  local TextSize1:POINT, TextSize2:POINT, dTextWidth:DWORD
  local cBuffer[1024]:CHR, dValue:DWORD, wFpuStatus:WORD

  SetObject xsi
  invoke MemClone, addr [xsi].OutputRect, pRect, sizeof RECT

  ;Set scale titles
  lea xdi, cBuffer

  m2z CHR ptr [xdi]                                     ;Set first byte to zero
  .if [xsi].PlotXYData.ScaleX.pDesc != NULL
    .if $invoke(StrLength, [xsi].PlotXYData.ScaleX.pDesc)
      invoke StrCCopy, xdi, [xsi].PlotXYData.ScaleX.pDesc, lengthof cBuffer
    .endif
  .endif
  .if [xsi].PlotXYData.ScaleX.pUnit != NULL
    .if $invoke(StrLength, [xsi].PlotXYData.ScaleX.pUnit)
      .if [xsi].PlotXYData.ScaleX.pDesc != NULL
        .if $invoke(StrLength, [xsi].PlotXYData.ScaleX.pDesc)
          invoke StrCCatChar, xdi, " ", lengthof cBuffer
        .endif
      .endif
      invoke StrCCatChar, xdi, "[", lengthof cBuffer
      invoke StrCCat, xdi, [xsi].PlotXYData.ScaleX.pUnit, lengthof cBuffer
      invoke StrCCatChar, xdi, "]", lengthof cBuffer
    .endif
  .endif
  invoke StrDispose, [xsi].PlotXYData.ScaleX.pTitle
  mov [xsi].PlotXYData.ScaleX.pTitle, $invoke(StrNew, xdi)

  m2z CHR ptr [xdi]                                     ;Set first byte to zero
  .if [xsi].PlotXYData.ScaleY.pDesc != NULL
    .if $invoke(StrLength, [xsi].PlotXYData.ScaleY.pDesc)
      invoke StrCCopy, xdi, [xsi].PlotXYData.ScaleY.pDesc, lengthof cBuffer
    .endif
  .endif
  .if [xsi].PlotXYData.ScaleY.pUnit != NULL
    .if $invoke(StrLength, [xsi].PlotXYData.ScaleY.pUnit)
      .if [xsi].PlotXYData.ScaleY.pDesc != NULL
        .if $invoke(StrLength, [xsi].PlotXYData.ScaleY.pDesc)
          invoke StrCCatChar, xdi, " ", lengthof cBuffer
        .endif
      .endif
      invoke StrCCatChar, xdi, "[", lengthof cBuffer
      invoke StrCCat, xdi, [xsi].PlotXYData.ScaleY.pUnit, lengthof cBuffer
      invoke StrCCatChar, xdi, "]", lengthof cBuffer
    .endif
  .endif
  invoke StrDispose, [xsi].PlotXYData.ScaleY.pTitle
  mov [xsi].PlotXYData.ScaleY.pTitle, $invoke(StrNew, xdi)

  ;---------------------------------------------------
  ;Calculate internal factors

  .ifBitSet [xsi].PlotXYData.ScaleX.bOptions, mask AutoMin
    mov edx, [xsi].PlotXYData.ScaleX.r4DataMin
  .else
    mov edx, [xsi].PlotXYData.ScaleX.r4SetupMin
  .endif
  mov [xsi].PlotXYData.ScaleX.r4ScaleMin, edx

  .ifBitSet [xsi].PlotXYData.ScaleX.bOptions, mask AutoMax
    mov edx, [xsi].PlotXYData.ScaleX.r4DataMax
  .else
    mov edx, [xsi].PlotXYData.ScaleX.r4SetupMax
  .endif
  mov [xsi].PlotXYData.ScaleX.r4ScaleMax, edx

  fld [xsi].PlotXYData.ScaleX.r4ScaleMin
  fcomp [xsi].PlotXYData.ScaleX.r4ScaleMax
  fnstsw wFpuStatus
  mov ax, wFpuStatus
  sahf
  .if ZERO?                                             ;Min = Max
    fld [xsi].PlotXYData.ScaleX.r4ScaleMax
    fld1
    faddp st(1), st(0)
    fstp [xsi].PlotXYData.ScaleX.r4ScaleMax
  .elseif !CARRY?                                       ;Min > Max -> swap
    mov edx, [xsi].PlotXYData.ScaleX.r4ScaleMin
    mov ecx, [xsi].PlotXYData.ScaleX.r4ScaleMax
    mov [xsi].PlotXYData.ScaleX.r4ScaleMin, ecx
    mov [xsi].PlotXYData.ScaleX.r4ScaleMax, edx
  .endif

  OCall xsi.CalcTicks, addr [xsi].PlotXYData.ScaleX
  invoke StrDispose, [xsi].PlotXYData.ScaleX.pFormatStr
  mov [xsi].PlotXYData.ScaleX.pFormatStr, $invoke(GetFormatStr, [xsi].PlotXYData.ScaleX.dDigits)

  ;---------------------------------------------------

  .ifBitSet [xsi].PlotXYData.ScaleY.bOptions, mask AutoMin
    mov edx, [xsi].PlotXYData.ScaleY.r4DataMin
  .else
    mov edx, [xsi].PlotXYData.ScaleY.r4SetupMin
  .endif
  mov [xsi].PlotXYData.ScaleY.r4ScaleMin, edx

  .ifBitSet [xsi].PlotXYData.ScaleY.bOptions, mask AutoMax
    mov edx, [xsi].PlotXYData.ScaleY.r4DataMax
  .else
    mov edx, [xsi].PlotXYData.ScaleY.r4SetupMax
  .endif
  mov [xsi].PlotXYData.ScaleY.r4ScaleMax, edx

  fld [xsi].PlotXYData.ScaleY.r4ScaleMin
  fcomp [xsi].PlotXYData.ScaleY.r4ScaleMax
  fnstsw wFpuStatus
  mov ax, wFpuStatus
  sahf
  .if ZERO?                                             ;Min = Max
    fld [xsi].PlotXYData.ScaleY.r4ScaleMax
    fld1
    faddp st(1), st(0)
    fstp [xsi].PlotXYData.ScaleY.r4ScaleMax
  .elseif !CARRY?                                       ;Min > Max -> swap
    mov edx, [xsi].PlotXYData.ScaleY.r4ScaleMin
    mov ecx, [xsi].PlotXYData.ScaleY.r4ScaleMax
    mov [xsi].PlotXYData.ScaleY.r4ScaleMin, ecx
    mov [xsi].PlotXYData.ScaleY.r4ScaleMax, edx
  .endif

  OCall xsi.CalcTicks, addr [xsi].PlotXYData.ScaleY
  invoke StrDispose, [xsi].PlotXYData.ScaleY.pFormatStr
  mov [xsi].PlotXYData.ScaleY.pFormatStr, $invoke(GetFormatStr, [xsi].PlotXYData.ScaleY.dDigits)

  ; --------------------------------------------------

  invoke GetTextExtentPoint32, hDC, $OfsCStr("0"), 1, addr TextSize1
  mov eax, TextSize1.x
  mov [xsi].PlotXYData.ScaleX.dTickMjrLen, eax          ;the width of "0"
  mov [xsi].PlotXYData.ScaleY.dTickMjrLen, eax          ;Copy to Y-scale
  shr eax, 1
  mov [xsi].PlotXYData.ScaleX.dTickMnrLen, eax          ;half the width of "0"
  mov [xsi].PlotXYData.ScaleY.dTickMnrLen, eax          ;Copy to Y-scale
  mov eax, TextSize1.y
  shr eax, 1
  mov [xsi].PlotXYData.ScaleX.dTitleSep, eax            ;Gap between Title and Label on X-Scale
  mov [xsi].PlotXYData.ScaleY.dTitleSep, eax            ;Gap between Title and Label on Y-Scale
  mov eax, TextSize1.x
  shr eax, 1
  mov [xsi].PlotXYData.ScaleX.dLabelSep, eax            ;Gap between Tick and label on X-Scale
  mov [xsi].PlotXYData.ScaleY.dLabelSep, eax            ;Gap between Tick and Label on Y-Scale

  ;---------------------------------------------------
  ;Determine the top border
  mov eax, [xsi].OutputRect.top
  shr TextSize1.y, 1
  add eax, TextSize1.y
  mov [xsi].PlotRect.top, eax

  ;---------------------------------------------------
  ;Determine the left border
  lea xdi, cBuffer
  fld [xsi].PlotXYData.ScaleY.r4ScaleMin
  invoke St0ToStr, xdi, 0, 0, f_NOR or f_TRIM
  fUnload
  invoke StrLength, xdi
  lea xbx, TextSize1
  invoke GetTextExtentPoint32, hDC, xdi, eax, xbx

  fld [xsi].PlotXYData.ScaleY.r4ScaleMax
  invoke St0ToStr, xdi, 0, 0, f_NOR or f_TRIM
  fUnload
  invoke StrLength, xdi
  lea xbx, TextSize2
  invoke GetTextExtentPoint32, hDC, xdi, eax, xbx

  mov dTextWidth, $uMax(TextSize1.x, TextSize2.x)
  .if $invoke(StrLength, [xsi].PlotXYData.ScaleY.pTitle)
    lea xbx, TextSize1
    invoke GetTextExtentPoint32, hDC, [xsi].PlotXYData.ScaleY.pTitle, eax, xbx
    mov eax, [xsi].PlotXYData.ScaleY.dTitleSep
    add TextSize1.y, eax                                ;Y scale title height + separation
  .else
    m2z TextSize1.y
  .endif

  mov eax, [xsi].OutputRect.left
  add eax, TextSize1.y                                  ;Y scale title height + separation
  add eax, dTextWidth                                   ;Max. label size
  add eax, [xsi].PlotXYData.ScaleY.dLabelSep            ;Label separation
  add eax, [xsi].PlotXYData.ScaleY.dTickMjrLen          ;Major tick lenght
  mov [xsi].PlotRect.left, eax

  ;---------------------------------------------------
  ;Determine the right border
  .ifBitSet [xsi].PlotXYData.ScaleX.bOptions, mask XasDate
    ;for best placing (w/o time stamp)
    FillString CHR ptr [xdi], <DD.MM.YYYY>
    mov eax, 10
  .else
    fld [xsi].PlotXYData.ScaleX.r4ScaleMax
    invoke St0ToStr, xdi, 0, 0 , f_NOR or f_TRIM
    fUnload
    invoke StrLength, xdi
  .endif
  lea xbx, TextSize1
  invoke GetTextExtentPoint32, hDC, xdi, eax, xbx

  mov eax, [xsi].OutputRect.right
  shr TextSize1.x, 1
  sub eax, TextSize1.x
  mov [xsi].PlotRect.right, eax

  ;---------------------------------------------------
  ;Determine the bottom border
  invoke GetTextExtentPoint32, hDC, $OfsCStr("0"), 1, addr TextSize2
  .if $invoke(StrLength, [xsi].PlotXYData.ScaleX.pTitle)
    lea xbx, TextSize1
    invoke GetTextExtentPoint32, hDC, [xsi].PlotXYData.ScaleX.pTitle, eax, xbx
    mov eax, [xsi].PlotXYData.ScaleX.dTitleSep
    add TextSize1.y, eax                                ;X scale title height + separation
  .else
    m2z TextSize1.y
  .endif

  .ifBitSet [xsi].PlotXYData.ScaleX.bOptions, mask XasDate
    mov eax, TextSize2.y
    add TextSize1.y, eax
  .endif

  mov eax, [xsi].OutputRect.bottom
  sub eax, TextSize1.y                                  ;X scale title height + separation
  sub eax, TextSize2.y                                  ;Scale label height
  sub eax, [xsi].PlotXYData.ScaleX.dLabelSep            ;Label separation
  sub eax, [xsi].PlotXYData.ScaleX.dTickMjrLen          ;Major tick length
  mov [xsi].PlotRect.bottom, eax

  ;---------------------------------------------------
  ;Calculate Scaling Factors
  mov eax, [xsi].PlotRect.right
  sub eax, [xsi].PlotRect.left
  mov dValue, eax
  fld [xsi].PlotXYData.ScaleX.r4ScaleMax
  fsub [xsi].PlotXYData.ScaleX.r4ScaleMin
  fidivr dValue
  fstp [xsi].PlotXYData.ScaleX.r4ScaleFactor

  mov eax, [xsi].PlotRect.bottom
  sub eax, [xsi].PlotRect.top
  mov dValue, eax
  fld [xsi].PlotXYData.ScaleY.r4ScaleMax
  fsub [xsi].PlotXYData.ScaleY.r4ScaleMin
  fidivr dValue
  fstp [xsi].PlotXYData.ScaleY.r4ScaleFactor
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     PlotXY.CalcTicks
; Purpose:    Compute all relative to major and minor scale ticks.
; Arguments:  Arg1: -> Scale data.
; Return:     Nothing.

Method PlotXY.CalcTicks, uses xbx, pScaleData:PSCALE_DATA
  local r4NLL:REAL4, r4NUL:REAL4                        ;New Lower Limit and New Upper Limit
  local dIndex:DWORD, dBuffer:DWORD

  .const
    bSclMjrTicks  db  05, 04, 06, 04, 05, 06, 07, 08, 09, 10, 11, 06
    bSclMnrTicks  db  04, 05, 05, 05, 05, 05, 02, 02, 05, 02, 02, 05
  .code

  mov xbx, pScaleData
  assume xbx:PSCALE_DATA
  fld [xbx].r4ScaleMax
  fsub [xbx].r4ScaleMin
  fabs                                                  ;Be sure UL-LL > 0
  fLogT
  fRndDn                                                ;E
  fExpT                                                 ;FR = Rounded exponent of NUL-NLL

  fld [xbx].r4ScaleMin
  fdiv st(0), st(1)
  fRndDn
  fmul st(0), st(1)
  fstp r4NLL

  fld [xbx].r4ScaleMax
  fdiv st(0), st(1)
  fRndUp
  fmul st(0), st(1)
  fst r4NUL

  fld r4NLL
  fsubp st(1), st(0)
  fabs                                                  ;Be sure NUL-NLL > 0
  fld st(0)
  fLogT
  fRndDn                                                ;F = RndDn(Log(Abs((NUL-NLL)))

  fld1
  fcomi st(0), st(1)
  .if !CARRY? && !ZERO?                                 ;st(1) < 1
    fsubrp st(1), st(0)
  .else
    fUnload 2                                           ;Unload FPU stack
    fldz
  .endif
  fistp [xbx].dDigits

  fxch
  fdivr st(0), st(1)
  fRnd
  fistp dIndex                                          ;Index = Rnd(NUL-NLL) / FR
  dec dIndex                                            ;Make zero based index

  .ifBitSet [xbx].bOptions, mask AutoMnrDiv
    mov eax, dIndex                                     ;Get minor divisions from table
    lea xbx, bSclMnrTicks
    xlatb
    mov xbx, pScaleData
    mov [xbx].dTickMnrCount, eax
  .else
    m2m [xbx].dTickMnrCount, [xbx].dSetupMnrDiv, xdx
  .endif
  m2m [xbx].dDataMnrDiv, [xbx].dTickMnrCount, xdx

  .ifBitSet [xbx].bOptions, mask AutoMjrDiv
    mov eax, dIndex                                     ;Get major divisions from table
    lea xbx, bSclMjrTicks
    xlatb
    mov xbx, pScaleData
    mov dBuffer, eax
    fild dBuffer

    mov [xbx].dDataMjrDiv, eax
  .else
    fild [xbx].dSetupMjrDiv

    m2m [xbx].dDataMjrDiv, [xbx].dSetupMjrDiv, xdx
  .endif

  fdivp st(1), st(0)
  fst [xbx].r4TickMjrStp

  fld [xbx].r4ScaleMin                                  ;Start repeat-until loop
  fld r4NLL
@@1:
  fcomi st(0), st(1)
  .if !ZERO? && CARRY?                                  ;while x < r4ScaleMin
    fadd st(0), st(2)
    jmp @@1
  .endif
  fstp [xbx].r4TickMjrFst
  fstp dBuffer

  fld [xbx].r4ScaleMax                                  ;Start repeat-until loop
  fld r4NUL
@@2:
  fcomi st(0),  st(1)
  .if !ZERO? && !CARRY?                                 ;while x > r4ScaleMax
    fsub st(0), st(2)
    jmp @@2
  .endif

  fUnload 3                                             ;Unload FPU stack

  assume xbx:NOTHING
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     PlotXY.Done
; Purpose:    Finalize the PlotXY object.
; Arguments:  None.
; Return:     Nothing.

Method PlotXY.Done, uses xbx xsi
  SetObject xsi

  lea xbx, [xsi].PlotXYData
  assume xbx:PPLOTXY_DATA
  invoke StrDispose, [xbx].ScaleX.pTitle
  invoke StrDispose, [xbx].ScaleX.pFormatStr
  invoke StrDispose, [xbx].ScaleX.pDesc
  invoke StrDispose, [xbx].ScaleX.pUnit

  invoke StrDispose, [xbx].ScaleY.pTitle
  invoke StrDispose, [xbx].ScaleY.pFormatStr
  invoke StrDispose, [xbx].ScaleY.pDesc
  invoke StrDispose, [xbx].ScaleY.pUnit

  Destroy [xbx].pCollDataX
  Destroy [xbx].pCollDataY
  assume xbx:NOTHING

  invoke DeleteObject, [xsi].hFontHorz
  invoke DeleteObject, [xsi].hFontVert

  ACall xsi.Done
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     PlotXY.Frame
; Purpose:    Display the plot frame.
; Arguments:  Arg1: Output device context.
;             Arg2: Color switch for B&W printers
; Return:     Nothing.

LABEL_INFO struc
  dPosition   DWORD   ?
  r8Value     REAL8   ?
LABEL_INFO ends
PLABEL_INFO typedef ptr LABEL_INFO

Method PlotXY.Frame, uses xbx xdi xsi, hDC:HDC, bUseColor:BYTE
  local hPrevPen:HPEN, hPrevBrush:HBRUSH, dPrevColor:DWORD, hPrevFont:HFONT
  local dPrevBkMode:DWORD, dPrevAlign:DWORD, dTempEDI:DWORD
  local LastPoint:POINT, cBuffer[256]:CHR
  local dTickBeg:DWORD, dTickMjrEnd:DWORD, dTickMnrEnd:DWORD
  local dMjrCount:DWORD, dMnrCount:DWORD, dVal:DWORD
  local hTickPen:HPEN, hGridPen:HPEN
  local TextSize:POINT, dColor:DWORD, dBottom:DWORD
  local r8TimeCurrent:REAL8, pTimeCurrent:POINTER
  local FpuContext:FPU_CONTEXT
  local LabelInfo[200]:LABEL_INFO, pCurLabelInfo:PLABEL_INFO

  SetObject xsi

  ;---------------------------------------------------
  ;Fill output region, plot a line around the plot area and fill the interior
  lea xbx, [xsi].PlotXYData
  assume xbx:PPLOTXY_DATA

  Choose32 bUseColor, $RGB(255,255,255), [xbx].Colors.dBackground
  mov xdi, $invoke(CreateSolidBrush, eax)
  invoke FillRect, hDC, addr [xsi].OutputRect, xdi
  invoke DeleteObject, xdi

  Choose32 bUseColor, $RGB(000,000,000), [xbx].Colors.dPlotBorder
  invoke CreatePen, PS_SOLID, 1, eax
  mov hPrevPen, $invoke(SelectObject, hDC, xax)

  Choose32 bUseColor, $RGB(255,255,255), [xbx].Colors.dPlotArea
  invoke CreateSolidBrush, eax
  mov hPrevBrush, $invoke(SelectObject, hDC, xax)

  mov eax, [xsi].PlotRect.right
  mov edi, [xsi].PlotRect.bottom
  inc eax
  inc edi
  invoke Rectangle, hDC, [xsi].PlotRect.left, [xsi].PlotRect.top, eax, edi

  invoke DeleteObject, $invoke(SelectObject, hDC, hPrevBrush)

  Choose32 bUseColor, $RGB(000,000,000), [xbx].Colors.dScales
  mov dColor, eax
  mov dPrevColor, $32($invoke(SetTextColor, hDC, eax))

  mov hTickPen, $invoke(CreatePen, PS_SOLID, 1, dColor)
  invoke DeleteObject, $invoke(SelectObject, hDC, xax)  ;Delete PlotBorder pen

  Choose32 bUseColor, $RGB(000,000,000), [xbx].Colors.dGrid
  mov hGridPen, $invoke(CreatePen, PS_DOT, 1, eax)

  mov dPrevBkMode, $32($invoke(SetBkMode, hDC, TRANSPARENT))

  ;---------------------------------------------------
  ;Plot X-Scale

  mov hPrevFont, $invoke(SelectObject, hDC, [xsi].hFontHorz)
  mov dPrevAlign, $32($invoke(SetTextAlign, hDC, TA_CENTER or TA_TOP))
  invoke GetTextExtentPoint32, hDC, $OfsCStr("0"), 1, addr TextSize

  mov eax, [xsi].PlotRect.bottom
  mov dTickBeg, eax
  add eax, [xbx].ScaleX.dTickMjrLen
  mov dTickMjrEnd, eax

  mov ecx, dTickBeg
  add ecx, [xbx].ScaleX.dTickMnrLen
  mov dTickMnrEnd, ecx

  fld [xbx].ScaleX.r4ScaleFactor
  fld [xbx].ScaleX.r4TickMjrStp
  fild [xbx].ScaleX.dTickMnrCount
  fdivr st(0), st(1)                                    ;MnrStep = TickStep/MnrCount
  ;FPU Stack: MnrStep | MjrStep | ScaleFactor
  fld [xbx].ScaleX.r4TickMjrFst
  fld [xbx].ScaleX.r4ScaleMin
  ;FPU Stack: ScaleMin | TickFirst | MnrStep | MjrStep | ScaleFactor
  lea xax, LabelInfo
  mov pCurLabelInfo, xax
  xor edi, edi
  .repeat
    mov dMjrCount, edi
    fild dMjrCount
    ;FPU Stack: dMjrCount | ScaleMin | TickFirst | MnrStep | MjrStep | ScaleFactor
    fmul st(0), st(4)
    fadd st(0), st(2)
    mov xcx, pCurLabelInfo
    fst [xcx].LABEL_INFO.r8Value
    fsub st(0), st(1)
    fmul st(0), st(5)
    ;FPU Stack: MjrTickPos | ScaleMin | TickFirst | MnrStep | MjrStep | ScaleFactor
    fist dVal
    mov eax, [xsi].PlotRect.left
    add eax, dVal
    mov [xcx].LABEL_INFO.dPosition, eax                 ;Store position onto stack
    add pCurLabelInfo, sizeof LABEL_INFO
    .break .if eax > [xsi].PlotRect.right
    mov dVal, eax

    ;Draw major tick
    SaveFpuContext FpuContext
    invoke MoveToEx, hDC, dVal, dTickMjrEnd, addr LastPoint
    invoke LineTo, hDC, dVal, dTickBeg

    ;Draw Grid lines
    .ifBitSet [xbx].ScaleX.bOptions, mask ShowGrid
      mov ecx, dVal
      .if (ecx < [xsi].PlotRect.right) && (ecx > [xsi].PlotRect.left)
        invoke SelectObject, hDC, hGridPen
        m2m dBottom, [xsi].PlotRect.bottom, ecx
        dec dBottom
        invoke MoveToEx, hDC, dVal, dBottom, addr LastPoint
        invoke LineTo, hDC, dVal, [xsi].PlotRect.top
        invoke SelectObject, hDC, hTickPen
      .endif
    .endif
    LoadFpuContext FpuContext

    ;Draw minor ticks
    mov dTempEDI, edi
    mov edi, 1
    .while edi < [xbx].ScaleX.dTickMnrCount
      mov dMnrCount, edi
      fild dMnrCount
      ;FPU Stack: dMnrCount | MjrTickPos | ScaleMin | TickFirst | MnrStep | MjrStep | ScaleFactor
      fmul st(0), st(4)
      fmul st(0), st(6)
      fadd st(0), st(1)
      ;FPU Stack: MnrTickPos | MjrTickPos | ScaleMin | TickFirst | MnrStep | MjrStep | ScaleFactor
      fistp dVal
      ;FPU Stack: MjrTickPos | ScaleMin | TickFirst | MnrStep | MjrStep | ScaleFactor
      mov eax, [xsi].PlotRect.left
      add dVal, eax
      mov eax, dVal
      .break .if SDWORD ptr eax > [xsi].PlotRect.right
      SaveFpuContext FpuContext
      invoke MoveToEx, hDC, dVal, dTickBeg, addr LastPoint
      invoke LineTo, hDC, dVal, dTickMnrEnd
      LoadFpuContext FpuContext
      inc edi
    .endw
    mov edi, dTempEDI
    fUnload 1                                           ;Unload FPU stack
    ;FPU Stack: ScaleMin | TickFirst | MnrStep | MjrStep | ScaleFactor
    inc edi
  .until FALSE
  sub pCurLabelInfo, 2*sizeof LABEL_INFO
  fUnload 1                                             ;Unload FPU stack

  ;Draw remaining minor ticks at the beginning of the X-Scale
  mov edi, 1
  .while edi < [xbx].ScaleX.dTickMnrCount
    mov dMnrCount, edi
    fild dMnrCount
    ;FPU Stack: dMnrCount | ScaleMin | TickFirst | MnrStep | MjrStep | ScaleFactor
    fmul st(0), st(3)
    fsubr st(0), st(2)
    fsub st(0), st(1)
    fmul st(0), st(5)
    fistp dVal
    mov eax, [xsi].PlotRect.left
    add eax, dVal
    .break .if SDWORD ptr eax < [xsi].PlotRect.left
    mov dVal, eax
    SaveFpuContext FpuContext
    invoke MoveToEx, hDC, dVal, dTickBeg, addr LastPoint
    invoke LineTo, hDC, dVal,dTickMnrEnd
    LoadFpuContext FpuContext
    inc edi
  .endw

  fUnload 5                                             ;Unload FPU stack

  ;Draw TickLabels
  mov eax, TextSize.y
  shr eax, 1
  add dTickMjrEnd, eax

  .while TRUE
    lea xax, LabelInfo
    .break .if pCurLabelInfo < xax
    mov xdi, pCurLabelInfo
    m2m dVal, [xdi].LABEL_INFO.dPosition, edx
    .ifBitSet [xbx].ScaleX.bOptions, mask XasDate
      fld [xdi].LABEL_INFO.r8Value
      mov eax, 24
      fildReg eax
      fdiv
      fadd [xbx].ScaleX.r8TimeStart
      fstp r8TimeCurrent

      SaveFpuContext FpuContext
      if TARGET_STR_TYPE eq STR_TYPE_ANSI
        lea xax, pTimeCurrent
      else
        lea xax, cBuffer
      endif
      invoke VarBstrFromDate, r8TimeCurrent, 0, LOCALE_NOUSEROVERRIDE, xax
      if TARGET_STR_TYPE eq STR_TYPE_ANSI
        invoke WideCharToMultiByte, CP_ACP, 0, pTimeCurrent, -1, \
                                    addr cBuffer, lengthof cBuffer, NULL, NULL
        invoke SysFreeString, pTimeCurrent
      endif

      mov xdi, $invoke(StrLScan, addr cBuffer, ' ')
      .if xdi != NULL
        add xdi, sizeof CHR
        invoke TextOut, hDC, dVal, dTickMjrEnd, xdi, $32($invoke(StrLength, xdi))
        add xdi, sizeof CHR
        m2z CHR ptr [xdi]
      .else
        invoke TextOut, hDC, dVal, dTickMjrEnd, $OfsCStr(" "), 1
      .endif

      mov edi, dTickMjrEnd
      add edi, 11
      invoke TextOut, hDC, dVal, edi, addr cBuffer, $32($invoke(StrLength, addr cBuffer))
      LoadFpuContext FpuContext

    .else
      SaveFpuContext FpuContext
      fld [xdi].LABEL_INFO.r8Value
      invoke St0ToStr, addr cBuffer, 0, 0 , f_NOR or f_TRIM
      fUnload
      invoke StrLength, addr cBuffer
      invoke TextOut, hDC, dVal, dTickMjrEnd, addr cBuffer, eax
      LoadFpuContext FpuContext
    .endif

    sub pCurLabelInfo, sizeof LABEL_INFO
  .endw

  SaveFpuContext FpuContext
  lea xbx, [xsi].PlotXYData
  mov edi, $32($invoke(StrLength, [xbx].ScaleX.pTitle))
  .if edi > 0
    invoke SetTextAlign, hDC, TA_CENTER or TA_BOTTOM
    mov edx, [xsi].PlotRect.right
    add edx, [xsi].PlotRect.left
    shr edx, 1
    invoke TextOut, hDC, edx, [xsi].OutputRect.bottom, [xbx].ScaleX.pTitle, edi
  .endif
  LoadFpuContext FpuContext


  ;---------------------------------------------------
  ;Plot Y-Scale

  mov dPrevAlign, $32($invoke(SetTextAlign, hDC, TA_BASELINE or TA_RIGHT))

  mov eax, [xsi].PlotRect.left
  mov dTickBeg, eax
  sub eax, [xbx].ScaleY.dTickMjrLen
  mov dTickMjrEnd, eax

  mov ecx, dTickBeg
  sub ecx, [xbx].ScaleY.dTickMnrLen
  mov dTickMnrEnd, ecx

  fld [xbx].ScaleY.r4ScaleFactor
  fld [xbx].ScaleY.r4TickMjrStp
  fild [xbx].ScaleY.dTickMnrCount
  fdivr st(0), st(1)                                    ;MnrStep = TickStep/MnrCount
  ;FPU Stack: MnrStep | MjrStep | ScaleFactor
  fld [xbx].ScaleY.r4TickMjrFst
  fld [xbx].ScaleY.r4ScaleMin
  ;FPU Stack: ScaleMin | TickFirst | MnrStep | MjrStep | ScaleFactor
  lea xax, LabelInfo
  mov pCurLabelInfo, xax
  xor edi, edi
  .repeat
    mov dMjrCount, edi
    fild dMjrCount
    ;FPU Stack: dMjrCount | ScaleMin | TickFirst | MnrStep | MjrStep | ScaleFactor
    fmul st(0), st(4)
    fadd st(0), st(2)
    mov xcx, pCurLabelInfo
    fst [xcx].LABEL_INFO.r8Value
    fsub st(0), st(1)
    fmul st(0), st(5)
    ;FPU Stack: MjrTickPos | ScaleMin | TickFirst | MnrStep | MjrStep | ScaleFactor
    fist dVal
    mov eax, [xsi].PlotRect.bottom
    sub eax, dVal
    mov [xcx].LABEL_INFO.dPosition, eax                 ;Store position onto stack
    add pCurLabelInfo, sizeof LABEL_INFO
    .break .if SDWORD ptr eax < [xsi].PlotRect.top
    mov dVal, eax

    ;Draw major tick
    SaveFpuContext FpuContext
    invoke MoveToEx, hDC, dTickMjrEnd, dVal, addr LastPoint
    invoke LineTo, hDC, dTickBeg, dVal

    ;Draw Grid lines
    .ifBitSet [xbx].ScaleY.bOptions, mask ShowGrid
      mov ecx, dVal
      .if (ecx < [xsi].PlotRect.bottom) && (ecx > [xsi].PlotRect.top)
        invoke SelectObject, hDC, hGridPen
        mov edx, [xsi].PlotRect.left
        inc edx
        invoke MoveToEx, hDC, edx, dVal, addr LastPoint
        invoke LineTo, hDC, [xsi].PlotRect.right, dVal
        invoke SelectObject, hDC, hTickPen
      .endif
    .endif
    LoadFpuContext FpuContext

    ;Draw minor ticks
    mov dTempEDI, edi
    mov edi, 1
    .while edi < [xbx].ScaleY.dTickMnrCount
      mov dMnrCount, edi
      fild dMnrCount
      ;FPU Stack: dMnrCount | MjrTickPos | ScaleMin | TickFirst | MnrStep | MjrStep | ScaleFactor
      fmul st(0), st(4)
      fmul st(0), st(6)
      fadd st(0), st(1)
      ;FPU Stack: MnrTickPos | MjrTickPos | ScaleMin | TickFirst | MnrStep | MjrStep | ScaleFactor
      fistp dVal
      ;FPU Stack: MjrTickPos | ScaleMin | TickFirst | MnrStep | MjrStep | ScaleFactor
      mov eax, [xsi].PlotRect.bottom
      sub eax, dVal
      .break .if SDWORD ptr eax < [xsi].PlotRect.top
      mov dVal, eax
      SaveFpuContext FpuContext
      invoke MoveToEx, hDC, dTickBeg, dVal, addr LastPoint
      invoke LineTo, hDC,dTickMnrEnd, dVal
      LoadFpuContext FpuContext
      inc edi
    .endw
    mov edi, dTempEDI
    fUnload 1                                           ;Unload FPU stack
    ;FPU Stack: ScaleMin | TickFirst | MnrStep | MjrStep | ScaleFactor
    inc edi
  .until FALSE
  sub pCurLabelInfo, 2*sizeof LABEL_INFO
  fUnload 1                                             ;Unload FPU stack

  ;Draw remaining minor ticks at the beginning of the Y-Scale
  mov edi, 1
  .while edi < [xbx].ScaleY.dTickMnrCount
    mov dMnrCount, edi
    fild dMnrCount
    ;FPU Stack: dMnrCount | ScaleMin | TickFirst | MnrStep | MjrStep | ScaleFactor
    fmul st(0), st(3)
    fsubr st(0), st(2)
    fsub st(0), st(1)
    fmul st(0), st(5)
    fistp dVal
    mov eax, [xsi].PlotRect.bottom
    sub eax, dVal
    mov dVal, eax
    dec eax
    .break .if SDWORD ptr eax >= [xsi].PlotRect.bottom
    SaveFpuContext FpuContext
    invoke MoveToEx, hDC, dTickBeg, dVal, addr LastPoint
    invoke LineTo, hDC, dTickMnrEnd, dVal
    LoadFpuContext FpuContext
    inc edi
  .endw

  fUnload 5                                             ;Unload FPU stack

  ;Draw TickLabels
  xor edx, edx
  mov eax, TextSize.y
  shl eax, 2
  mov ecx, 14
  idiv ecx
  mov edi, eax
  mov eax, TextSize.y
  shr eax, 1
  sub dTickMjrEnd, eax

  .while TRUE
    lea xax, LabelInfo
    .break .if pCurLabelInfo < xax
    mov xdi, pCurLabelInfo
    fld [xdi].LABEL_INFO.r8Value
    invoke St0ToStr, addr cBuffer, 0, 0 , f_NOR or f_TRIM
    fUnload
    invoke StrLength, addr cBuffer
    invoke TextOut, hDC, dTickMjrEnd, [xdi].LABEL_INFO.dPosition, addr cBuffer, eax
    sub pCurLabelInfo, sizeof LABEL_INFO
  .endw

  invoke SelectObject, hDC, [xsi].hFontVert
  mov edi, $32($invoke(StrLength, [xbx].ScaleY.pTitle))
  .if edi > 0
    invoke SetTextAlign, hDC, TA_CENTER or TA_TOP
    mov eax, [xsi].PlotRect.bottom
    add eax, [xsi].PlotRect.top
    shr eax, 1
    invoke TextOut, hDC, [xsi].OutputRect.left, eax, [xbx].ScaleY.pTitle, edi
  .endif

  ;---------------------------------------------------

  invoke DeleteObject, $invoke(SelectObject, hDC, hPrevPen)   ;Deletes hTickPen
  invoke DeleteObject, hGridPen
  invoke SetTextColor, hDC, dPrevColor
  invoke SetTextAlign, hDC, dPrevAlign
  invoke SetBkMode, hDC, dPrevBkMode
  invoke SelectObject, hDC, hPrevFont                   ;hFonts are deleted by the Done method

  assume xbx:NOTHING
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:    PlotXY.Init
; Purpose:   Initialize the PlotXY object.
; Arguments: Arg1: -> Owner object.
;            Arg2: Window handle.
;            Arg3: -> Data.
; Return:    Nothing.

Method PlotXY.Init, uses xbx xsi xdi, pOwner:POINTER, hWnd:HWND, pData:PPLOTXY_DATA
  local LogFnt:LOGFONT, hDC:HDC, dCount:DWORD
  local r4LastMIN:REAL4, r4LastMAX:REAL4
  local pDataBufferX:$ObjPtr(DataBufferXY), pDataBufferY:$ObjPtr(DataBufferXY)

  SetObject xsi
  ACall xsi.Init, pOwner, hWnd, offset szPlotXYProp
  invoke MemClone, addr [xsi].PlotXYData, pData, sizeof PLOTXY_DATA

  ;X's axis
  mov xdi, [xsi].PlotXYData.pCollDataX

  .ifBitSet [xsi].PlotXYData.ScaleX.bOptions, mask AutoMax or mask AutoMin
    mrm dCount, [xdi].$Obj(Collection).dCount, ecx
    .if ecx != 0
      xor ebx, ebx
      .while (ebx < dCount)
        mov pDataBufferX, $OCall(xdi::Collection.ItemAt, ebx)
        mov xcx, [xax].$Obj(DataBufferXY).pDims
        .if DWORD ptr [xcx] != 0
          fld r4LastMAX                                 ; st(1)
          OCall pDataBufferX::DataBufferXY.ItemAt, [xax].$Obj(DataBufferXY).dMaxIndex
          .if ebx != 0
            fld REAL4 ptr [xax]                         ; st(0)
            fcomip st(0), st(1)
            .if !CARRY?                                 ; st(0) > st(1)
            @@:
              m2m r4LastMAX, REAL4 ptr [xax], edx
            .endif
          .else
            jmp @B
          .endif
          fUnload 1                                     ;Unload FPU stack
    
          fld r4LastMIN                                 ; st(1)
          mov pDataBufferX, $OCall(xdi::Collection.ItemAt, ebx)
          OCall pDataBufferX::DataBufferXY.ItemAt, [xax].$Obj(DataBufferXY).dMinIndex
          .if ebx
            fld REAL4 ptr [xax]                         ; st(0)
            fcomip st(0), st(1)
            .if CARRY?                                  ; st(0) < st(1)
            @@:
              m2m r4LastMIN, REAL4 ptr [xax], edx
            .endif
          .else
            jmp @B
          .endif
          fUnload 1                                     ;Unload FPU stack
        .endif
  
        inc ebx
      .endw
    .endif
  .endif

  lea xbx, [xsi].PlotXYData.ScaleX
  .ifBitSet [xsi].PlotXYData.ScaleX.bOptions, mask AutoMax
    m2m [xbx].SCALE_BASIC_DATA.r4DataMax, r4LastMAX, edx
  .endif
  .ifBitSet [xsi].PlotXYData.ScaleX.bOptions, mask AutoMin
    m2m [xbx].SCALE_BASIC_DATA.r4DataMin, r4LastMIN, edx
  .endif

  mov xbx, $OCall(xdi::Collection.ItemAt, 0)
  mov [xsi].PlotXYData.ScaleX.pDesc, $invoke(StrNew, [xbx].$Obj(DataBufferXY).pDesc)
  mov [xsi].PlotXYData.ScaleX.pUnit, $invoke(StrNew, [xbx].$Obj(DataBufferXY).pUnit)

  ;Y's axis
  mov xdi, [xsi].PlotXYData.pCollDataY

  .ifBitSet [xsi].PlotXYData.ScaleY.bOptions, mask AutoMax or mask AutoMin
    mrm dCount, [xdi].$Obj(Collection).dCount, ecx
    .if ecx != 0
      xor ebx, ebx
      .while (ebx < dCount)
        mov pDataBufferY, $OCall(xdi::Collection.ItemAt, ebx)
        mov xcx, [xax].$Obj(DataBufferXY).pDims
        .if DWORD ptr [xcx] != 0
          OCall pDataBufferY::DataBufferXY.ItemAt, [xax].$Obj(DataBufferXY).dMaxIndex
          fld r4LastMAX
          .if ebx != 0
            fld REAL4 ptr [xax]                         ; st(0)
            fcomip st(0), st(1)
            .if !CARRY?                                 ; st(0) > st(1)
            @@:
              m2m r4LastMAX, REAL4 ptr [xax], edx
            .endif
          .else
            jmp @B
          .endif
          fUnload 1                                     ;Unload FPU stack
    
          fld r4LastMIN
          mov pDataBufferY, $OCall(xdi::Collection.ItemAt, ebx)
          OCall pDataBufferY::DataBufferXY.ItemAt, [xax].$Obj(DataBufferXY).dMinIndex
          .if ebx
            fld REAL4 ptr [xax]                         ; st(0)
            fcomip st(0), st(1)
            .if CARRY?                                  ; st(0) < st(1)
            @@:
              m2m r4LastMIN, REAL4 ptr [xax], edx
            .endif
          .else
            jmp @B
          .endif
          fUnload 1                                     ;Unload FPU stack
        .endif
  
        inc ebx
      .endw
    .endif
  .endif

  lea xbx, [xsi].PlotXYData.ScaleY
  .ifBitSet [xsi].PlotXYData.ScaleY.bOptions, mask AutoMax
    m2m [xbx].SCALE_BASIC_DATA.r4DataMax, r4LastMAX, edx
  .endif
  .ifBitSet [xsi].PlotXYData.ScaleY.bOptions, mask AutoMin
    m2m [xbx].SCALE_BASIC_DATA.r4DataMin, r4LastMIN, edx
  .endif

  mov xbx, $OCall(xdi::Collection.ItemAt, 0)
  mov [xsi].PlotXYData.ScaleY.pDesc, $invoke(StrNew, [xbx].$Obj(DataBufferXY).pDesc)
  mov [xsi].PlotXYData.ScaleY.pUnit, $invoke(StrNew, [xbx].$Obj(DataBufferXY).pUnit)

  FillString LogFnt.lfFaceName, <Arial>
  mov hDC, $invoke(GetDC, hWnd)
  invoke GetDeviceCaps, hDC, LOGPIXELSY
  invoke MulDiv, 8, eax, -72
  mov LogFnt.lfHeight, eax
  m2z LogFnt.lfWidth
  m2z LogFnt.lfEscapement
  m2z LogFnt.lfOrientation
  mov LogFnt.lfWeight, FW_DONTCARE
  m2z LogFnt.lfItalic
  m2z LogFnt.lfUnderline
  m2z LogFnt.lfStrikeOut
  mov LogFnt.lfCharSet, DEFAULT_CHARSET
  mov LogFnt.lfOutPrecision, OUT_DEFAULT_PRECIS
  mov LogFnt.lfClipPrecision, CLIP_DEFAULT_PRECIS
  mov LogFnt.lfQuality, DEFAULT_QUALITY
  mov LogFnt.lfPitchAndFamily, DEFAULT_PITCH or FF_DONTCARE
  mov [xsi].hFontHorz, $invoke(CreateFontIndirect, addr LogFnt)

  mov LogFnt.lfEscapement, 900
  mov [xsi].hFontVert, $invoke(CreateFontIndirect, addr LogFnt)
  invoke ReleaseDC, hWnd, hDC
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     PlotXY.OnMouseMove
; Purpose:    Event procedure for WM_MOUSEMOVE message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method PlotXY.OnMouseMove, uses xsi, wParam:WPARAM, lParam:LPARAM
  local sdValue:SDWORD

  SetObject xsi
  .if [xsi].bMovingOn == SCALEX
    BitClr [xsi].PlotXYData.ScaleX.bOptions, (mask AutoMax or mask AutoMin)

    mov xax, lParam
    cwde
    mov ecx, [xsi].MovedLastPoint.x
    mov [xsi].MovedLastPoint.x, eax
    sub eax, ecx
    mov sdValue, eax

    fld [xsi].PlotXYData.ScaleX.r4ScaleFactor
    fidivr SDWORD ptr sdValue
    fld [xsi].PlotXYData.ScaleX.r4ScaleMax
    fsub st(0), st(1)
    fstp [xsi].PlotXYData.ScaleX.r4SetupMax
    fld [xsi].PlotXYData.ScaleX.r4ScaleMin
    .ifBitSet wParam, MK_SHIFT
      fadd st(0), st(1)
    .else
      fsub st(0), st(1)
    .endif
    fstp [xsi].PlotXYData.ScaleX.r4SetupMin
    fUnload 1                                           ;Unload FPU stack
    OCall xsi.Refresh
  .elseif [xsi].bMovingOn == SCALEY
    BitClr [xsi].PlotXYData.ScaleY.bOptions, (mask AutoMax or mask AutoMin)

    mov xax, lParam
    shr eax, 16
    cwde
    mov ecx, [xsi].MovedLastPoint.y
    mov [xsi].MovedLastPoint.y, eax
    sub ecx, eax
    mov sdValue, ecx

    fld [xsi].PlotXYData.ScaleY.r4ScaleFactor
    fidivr SDWORD ptr sdValue
    fld [xsi].PlotXYData.ScaleY.r4ScaleMax
    fsub st(0), st(1)
    fstp [xsi].PlotXYData.ScaleY.r4SetupMax
    fld [xsi].PlotXYData.ScaleY.r4ScaleMin
    .ifBitSet wParam, MK_SHIFT
      fadd st(0), st(1)
    .else
      fsub st(0), st(1)
    .endif
    fstp [xsi].PlotXYData.ScaleY.r4SetupMin
    fUnload 1                                           ;Unload FPU stack
    OCall xsi.Refresh
  .elseif [xsi].bMovingOn == PLOT
    BitClr [xsi].PlotXYData.ScaleX.bOptions, (mask AutoMax or mask AutoMin)

    mov xax, lParam
    cwde
    mov ecx, [xsi].MovedLastPoint.x
    mov [xsi].MovedLastPoint.x, eax
    sub eax, ecx
    mov sdValue, eax

    fld [xsi].PlotXYData.ScaleX.r4ScaleFactor
    fidivr SDWORD ptr sdValue
    fld [xsi].PlotXYData.ScaleX.r4ScaleMax
    fsub st(0), st(1)
    fstp [xsi].PlotXYData.ScaleX.r4SetupMax
    fld [xsi].PlotXYData.ScaleX.r4ScaleMin
    .ifBitSet wParam, MK_SHIFT
      fadd st(0), st(1)
    .else
      fsub st(0), st(1)
    .endif
    fstp [xsi].PlotXYData.ScaleX.r4SetupMin
    fUnload 1                                           ;Unload FPU stack

    BitClr [xsi].PlotXYData.ScaleY.bOptions, (mask AutoMax or mask AutoMin)

    mov xax, lParam
    shr eax, 16
    cwde
    mov ecx, [xsi].MovedLastPoint.y
    mov [xsi].MovedLastPoint.y, eax
    sub ecx, eax
    mov sdValue, ecx

    fld [xsi].PlotXYData.ScaleY.r4ScaleFactor
    fidivr SDWORD ptr sdValue
    fld [xsi].PlotXYData.ScaleY.r4ScaleMax
    fsub st(0), st(1)
    fstp [xsi].PlotXYData.ScaleY.r4SetupMax
    fld [xsi].PlotXYData.ScaleY.r4ScaleMin
    .ifBitSet wParam, MK_SHIFT
      fadd st(0), st(1)
    .else
      fsub st(0), st(1)
    .endif
    fstp [xsi].PlotXYData.ScaleY.r4SetupMin
    fUnload 1                                           ;Unload FPU stack
    OCall xsi.Refresh
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     PlotXY.OnLButtonDblClk
; Purpose:    Event procedure for WM_LBUTTONDBLCLK message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method PlotXY.OnLButtonDblClk, uses xbx xdi xsi, wParam:WPARAM, lParam:LPARAM
  local pDlg:POINTER, DblClkPnt:POINT

  SetObject xsi
  ;Get doubleclick client coordinates
  PntS2Pnt DblClkPnt, lParam
  mov ebx, DblClkPnt.x
  add DblClkPnt.x, 10                                   ;Place the Dialog 10 px at the right
  mov edi, DblClkPnt.y
  add DblClkPnt.y, 20                                   ;Place the Dialog 20 px below
  invoke ClientToScreen, [xsi].hWnd, addr DblClkPnt     ;Transform to screen coordiantes
  ;Check if X scale was double clicked
  .if (ebx >= [xsi].PlotRect.left) && (ebx <= [xsi].OutputRect.right) && \
      (edi >= [xsi].PlotRect.bottom) && (edi <= [xsi].OutputRect.bottom)
    mov pDlg, $New(DialogSetupScale)
    OCall pDlg::DialogSetupScale.Init, xsi, [xsi].hWnd, addr [xsi].PlotXYData.ScaleX
    OCall pDlg::DialogSetupScale.ShowAt, DblClkPnt.x, DblClkPnt.y
    Destroy pDlg
  ;Check if Y scale was double clicked
  .elseif (ebx >= [xsi].OutputRect.left) && (ebx <= [xsi].PlotRect.left) && \
          (edi >= [xsi].OutputRect.top) && (edi <= [xsi].PlotRect.bottom)
    mov pDlg, $New(DialogSetupScale)
    OCall pDlg::DialogSetupScale.Init, xsi, [xsi].hWnd, addr [xsi].PlotXYData.ScaleY
    OCall pDlg::DialogSetupScale.ShowAt, DblClkPnt.x, DblClkPnt.y
    Destroy pDlg
  .else
    ;Launch the color setup dialog
    mov pDlg, $New(DialogSetupColors)
    OCall pDlg::DialogSetupColors.Init, xsi, [xsi].hWnd
    OCall pDlg::DialogSetupColors.ShowAt, DblClkPnt.x, DblClkPnt.y
    Destroy pDlg
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     PlotXY.OnLButtonDown
; Purpose:    Event procedure for WM_LBUTTONDOWN message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method PlotXY.OnLButtonDown, uses xsi, wParam:WPARAM, lParam:LPARAM
  SetObject xsi
  PntS2Regs lParam
  mov [xsi].MovedLastPoint.x, eax
  mov [xsi].MovedLastPoint.y, ecx

  ;Check if X scale was clicked
  .if (eax >= [xsi].PlotRect.left) && (eax <= [xsi].OutputRect.right) && \
    (ecx >= [xsi].PlotRect.bottom) && (ecx <= [xsi].OutputRect.bottom)
    mov [xsi].bMovingOn, SCALEX
    invoke SetCapture, [xsi].hWnd
  ;Check if Y scale was clicked
  .elseif (eax >= [xsi].OutputRect.left) && (eax <= [xsi].PlotRect.left) && \
    (ecx >= [xsi].OutputRect.top) && (ecx <= [xsi].PlotRect.bottom)
    mov [xsi].bMovingOn, SCALEY
    invoke SetCapture, [xsi].hWnd
  ;Check if plot was clicked
  .elseif (eax >= [xsi].PlotRect.left) && (eax <= [xsi].PlotRect.right) && \
    (ecx >= [xsi].PlotRect.top) && (ecx <= [xsi].PlotRect.bottom)
    mov [xsi].bMovingOn, PLOT
    invoke SetCapture, [xsi].hWnd
  ;It was clicked somewhere else
  .else
    mov [xsi].bMovingOn, NOSELECTION
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     PlotXY.OnLButtonUp
; Purpose:    Event procedure for WM_LBUTTONUP message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method PlotXY.OnLButtonUp,, wParam:WPARAM, lParam:LPARAM
  SetObject xcx
  mov [xcx].bMovingOn, NOSELECTION
  invoke ReleaseCapture
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     PlotXY.Plot
; Purpose:    Displays the plot data as a line.
; Arguments:  Arg1: Output device context.
;             Arg2: Color switch for B&W printers.
; Return:     Nothing.

Method PlotXY.Plot, uses xbx xdi xsi, hDC:HDC, bUseColor:BYTE
  local hRgn:HRGN, hPrevRgn:HRGN;, hPrevPen:HPEN
  local pPoints:POINTER, pCurPoint:POINTER, dCount:DWORD, dCountX:DWORD, dPointCount:DWORD
  local dFirstX:DWORD, dLastX:DWORD
  local pDataBufferX:$ObjPtr(DataBufferXY), pDataBufferY:$ObjPtr(DataBufferXY)
  local hPrvPen:HPEN

  SetObject xsi

  invoke GetClipRgn, hDC, hPrevRgn
  mov hRgn, $invoke(CreateRectRgn, [xsi].PlotRect.left,  [xsi].PlotRect.top, \
                                   [xsi].PlotRect.right, [xsi].PlotRect.bottom)
  invoke SelectClipRgn, hDC, hRgn

  mov xbx, [xsi].PlotXYData.pCollDataX
  m2m dCountX, [xbx].$Obj(Collection).dCount, ecx
  xor ebx, ebx
  .while (ebx < dCountX)
    mov pDataBufferX, $OCall([xsi].PlotXYData.pCollDataX::Collection.ItemAt, ebx)
    mov pDataBufferY, $OCall([xsi].PlotXYData.pCollDataY::Collection.ItemAt, ebx)

    mov xdi, pDataBufferX
    mov xax, [xdi].$Obj(DataBufferXY).pDims
    m2m dCount, DWORD ptr [xax], edx

    mov xdi, pDataBufferY
    invoke CreatePen, PS_SOLID, [xdi].$Obj(DataBufferXY).dLineWidth, \
                                [xdi].$Obj(DataBufferXY).dLineColor
    mov hPrvPen, $invoke(SelectObject, hDC, xax)

    ;-----------------------------------------------
    ;Search the greatest x-value less than ScaleMin to reduce drawing activity
    xor edi, edi
    fld [xsi].PlotXYData.ScaleX.r4ScaleMin
    .while edi < dCount
      OCall pDataBufferX::DataBufferXY.ItemAt, edi
      fld REAL4 ptr [xax]
      fcomip st(0), st(1)
      .break .if !CARRY?                              ;st(0) > st(1)
      inc edi
    .endw
    .if edi != 0
      dec edi
    .endif
    fUnload 1                                         ;Unload FPU stack
    mov dFirstX, edi

    ;-----------------------------------------------
    ;Search the lowest x-value greater than ScaleMax to reduce drawing activity
    mov edi, dCount
    dec edi
    fld [xsi].PlotXYData.ScaleX.r4ScaleMax
    .while SDWORD ptr edi >= 0
      OCall pDataBufferX::DataBufferXY.ItemAt, edi
      fld REAL4 ptr [xax]
      fcomip st(0), st(1)
      .break .if CARRY?                               ;st(0) < st(1)
      dec edi
    .endw
    mov eax, dCount
    dec eax
    .if edi != eax
      inc edi
    .endif
    fUnload 1                                         ;Unload FPU stack
    mov dLastX, edi

    ;-----------------------------------------------
    mov eax, dLastX
    sub eax, dFirstX
    inc eax
    mov dPointCount, eax
    shl eax, $Log2(sizeof(POINT))
    MemAlloc eax
    .if xax != NULL
      mov pPoints, xax
      mov pCurPoint, xax

      fld [xsi].PlotXYData.ScaleX.r4ScaleFactor
      fld [xsi].PlotXYData.ScaleY.r4ScaleFactor
      fld [xsi].PlotXYData.ScaleX.r4ScaleMin
      fld [xsi].PlotXYData.ScaleY.r4ScaleMin
      .while (SDWORD ptr edi >= dFirstX)
        OCall pDataBufferY::DataBufferXY.ItemAt, edi
        fld REAL4 ptr [xax]
        ;st(0)=y, st(1)=YScaleMin, st(2)=XScaleMin, st(3)=YScaleFactor, st(4)=XScaleFactor
        fsub st(0), st(1)
        fmul st(0), st(3)

        mov xcx, pCurPoint
        fistp SDWORD ptr [xcx].POINT.y
        neg SDWORD ptr [xcx].POINT.y
        mov eax, [xsi].PlotRect.bottom
        add [xcx].POINT.y, eax

        OCall pDataBufferX::DataBufferXY.ItemAt, edi
        fld REAL4 ptr [xax]
        ;st(0)=x, st(1)=YScaleMin, st(2)=XScaleMin, st(3)=YScaleFactor, st(4)=XScaleFactor
        fsub st(0), st(2)
        fmul st(0), st(4)
        mov xcx, pCurPoint
        fistp SDWORD ptr [xcx].POINT.x
        mov eax, [xsi].PlotRect.left
        add SDWORD ptr [xcx].POINT.x, eax
        add pCurPoint, sizeof POINT

        dec edi
      .endw
      fUnload 4                                         ;Unload FPU stack

      invoke Polyline, hDC, pPoints, dPointCount

      MemFree pPoints
    .endif

    invoke DeleteObject, $invoke(SelectObject, hDC, hPrvPen)

    inc ebx
  .endw

  invoke SelectClipRgn, hDC, hPrevRgn

  invoke DeleteObject, hRgn
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     PlotXY.Refresh
; Purpose:    Refresh the plot object.
; Arguments:  None.
; Return:     Nothing.

Method PlotXY.Refresh, uses xsi
  local hDC:HDC, hWnd:HWND

  SetObject xsi
  mov xdx, [xsi].pOwner
  mrm hWnd, [xdx].$Obj(WinPrimer).hWnd, xcx             ;xcx = hDC
  mov hDC, $invoke(GetDC, xcx)
  OCall xsi.Show, hDC, addr [xsi].OutputRect
  invoke ReleaseDC, hWnd, hDC
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     PlotXY.Show
; Purpose:    Draw the PlotXY object.
; Arguments:  Arg1: DC handle.
;             Arg2: -> RECT structure that indicates where to draw.
; Return:     Nothing.

Method PlotXY.Show, uses xbx xsi, hDC:HDC, pRect:PRECT
  local hMemDC:HDC, hPrevBmp:HBITMAP

  SetObject xsi
  ;Draw on a memory DC to avoid flicker
  mov hMemDC, $invoke(CreateCompatibleDC, hDC)
  mov xax, pRect
  invoke CreateCompatibleBitmap, hDC, [xax].RECT.right, [xax].RECT.bottom
  mov hPrevBmp, $invoke(SelectObject, hMemDC, xax)

  OCall xsi.Calc, hMemDC, pRect
  OCall xsi.Frame, hMemDC, TRUE
  OCall xsi.Plot, hMemDC, TRUE

  ;Copy plot to hDC
  mov xbx, pRect
  invoke BitBlt, hDC, [xbx].RECT.left, [xbx].RECT.top, [xbx].RECT.right, [xbx].RECT.bottom, \
                 hMemDC, [xbx].RECT.left, [xbx].RECT.top, SRCCOPY
  invoke DeleteObject, $invoke(SelectObject, hMemDC, hPrevBmp)    ;Deletes hMemBmp
  invoke DeleteDC, hMemDC
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     PlotXY.WndProc
; Purpose:    Processing of window messages.
; Arguments:  Arg1: Message identifier.
;             Arg2: First message parameter.
;             Arg3: Second message parameter.
; Return:     eax = This value is the result of the message processing and depends on the message ID.
; Note:       Window handle is passed in pSelf (hidden parameter).

Method PlotXY.WndProc,, uMsg:DWORD, wParam:WPARAM, lParam:LPARAM
  invoke GetProp, pSelf, offset szPlotXYProp
  OCall xax::PlotXY.Dispatch, pSelf, uMsg, wParam, lParam
MethodEnd



; ==================================================================================================
;    DataBufferXY implementation
; ==================================================================================================

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     DataBufferXY.Done
; Purpose:    Finalize the DataBufferXY object.
; Arguments:  None.
; Return:     Nothing.

Method DataBufferXY.Done, uses xsi
  SetObject xsi
  invoke StrDispose, [xsi].pName
  invoke StrDispose, [xsi].pDesc
  invoke StrDispose, [xsi].pUnit
  ACall xsi.Done
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     DataBufferXY.Init
; Purpose:    Initialize the DataBufferXY object.
; Arguments:  Arg1: -> Owner object.
;             Arg2: Capacity in bytes.
;             Arg3: Data size in bytes.
; Return:     Nothing.

Method DataBufferXY.Init, uses xsi, pOwner:POINTER, dCapacity:DWORD, dDataSize:DWORD
  SetObject xsi
  ACall xsi.Init, pOwner, dDataSize
  OCall xsi.DimAppend, dCapacity, ARR_MEM_ZERO
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     DataBufferXY.Load
; Purpose:    Load buffer data from a stream object.
; Arguments:  Arg1 -> Stream object.
; Return:     Nothing.

Method DataBufferXY.Load, uses xsi, pStream:$ObjPtr(Stream)
  SetObject xsi

  mov [xsi].pName, $OCall(pStream::Stream.StrRead)
  mov [xsi].pDesc, $OCall(pStream::Stream.StrRead)
  mov [xsi].pUnit, $OCall(pStream::Stream.StrRead)

  mov [xsi].dDateStamp, $32($OCall(pStream::Stream.BinRead32))
  mov [xsi].dTimeStamp, $32($OCall(pStream::Stream.BinRead32))

  mov [xsi].dMaxIndex, $32($OCall(pStream::Stream.BinRead32))
  mov [xsi].dMinIndex, $32($OCall(pStream::Stream.BinRead32))

  ACall xsi.Load, pStream
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:    DataBufferXY.Scan
; Purpose:   Scan the buffer data to find the min and max data. Min & Max indices are set.
; Arguments: Arg1: Index of first element.
;            Arg2: Index of last element.
; Return:    Nothing.

Method DataBufferXY.Scan, uses xbx xdi xsi, dFirst:DWORD, dLast:DWORD
  local pMax:POINTER, pMin:POINTER

  SetObject xsi
  mov edx, dFirst
  mov [xsi].dMaxIndex, edx
  mov [xsi].dMinIndex, edx
  mov ebx, dFirst
  mov eax, [xsi].dItemSize
  xor edx, edx
  mul ebx
  mov edi, eax
  add xdi, [xsi].pData
  mov pMax, xdi
  mov pMin, xdi
  fld REAL4 ptr [xdi]
  fld st(0)
  .while ebx < dLast
    mov eax, [xsi].dItemSize
    add xdi, xax
    inc ebx
    fld REAL4 ptr [xdi]
    fcomi st(0), st(1)                                  ;Compare with maximum
    .if !CARRY?                                         ;st(0) > st(1)
      mov pMax, xdi
      fst st(1)                                         ;Store new max
    .endif
    fcomi st(0), st(2)                                  ;Compare with minimum
    .if CARRY?                                          ;st(0) < st(1)
      mov pMin, xdi
      fst st(2)                                         ;Store new min
    .endif
    fUnload 1
  .endw
  fUnload 2                                             ;Unload FPU stack

  xor edx, edx
  mov xax, pMax                                         ;Calculate index of max data
  sub xax, [xsi].pData
  div [xsi].dItemSize
  mov [xsi].dMaxIndex, eax

  xor edx, edx
  mov xax, pMin                                         ;Calculate index of min data
  sub xax, [xsi].pData
  div [xsi].dItemSize
  mov [xsi].dMinIndex, eax
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     DataBufferXY.Store
; Purpose:    Store buffer data to a stream object.
; Arguments:  Arg1: -> Stream object.
; Return:     Nothing.

Method DataBufferXY.Store, uses xsi, pStream:$ObjPtr(Stream)
  SetObject xsi
  OCall pStream::Stream.StrWrite, [xsi].pName
  OCall pStream::Stream.StrWrite, [xsi].pDesc
  OCall pStream::Stream.StrWrite, [xsi].pUnit

  OCall pStream::Stream.BinWrite32, [xsi].dDateStamp
  OCall pStream::Stream.BinWrite32, [xsi].dTimeStamp

  OCall pStream::Stream.BinWrite32, [xsi].dMaxIndex
  OCall pStream::Stream.BinWrite32, [xsi].dMinIndex

  ACall xsi.Store, pStream
MethodEnd



; ==================================================================================================
;    DialogSetupScale implementation
; ==================================================================================================

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     DialogSetupScale.CtlsGet
; Purpose:    Read the controls in this dialog window.
; Arguments:  None.
; Return:     Nothing.

Method DialogSetupScale.CtlsGet, uses xbx xdi xsi
  local cBuffer[1024]:CHR, dFailure:DWORD
  local cTemp[1024]:CHR, rTime:REAL8

  SetObject xsi
  lea xbx, cBuffer
  mov xdi, [xsi].pScaleData
  assume xdi:PSCALE_DATA
  mov al, [xdi].bOptions
  m2z [xdi].bOptions

  .ifBitSet al, mask XasDate
    or [xdi].bOptions, mask XasDate
  .endif
  ;---------------------------------------------------
  invoke IsDlgButtonChecked, [xsi].hWnd, IDC_DSS_CHECKMAX
  .if eax != FALSE
    or [xdi].bOptions, mask AutoMax
  .endif
  invoke GetDlgItemText, [xsi].hWnd, IDC_DSS_EDITMAX, xbx, lengthof cBuffer

  .ifBitSet [xdi].bOptions, mask XasDate
    invoke MultiByteToWideChar, CP_ACP, 0, xbx, -1, addr cTemp, lengthof cTemp
    invoke VarDateFromStr, addr cTemp, 0, LOCALE_NOUSEROVERRIDE, addr rTime
    fld rTime
    fsub [xdi].r8TimeStart
    mov eax, 24
    fildReg eax
    fmul
  .else
    fldStr xbx
  .endif

  fstp [xdi].r4SetupMax
  ;---------------------------------------------------
  invoke IsDlgButtonChecked, [xsi].hWnd, IDC_DSS_CHECKMIN
  .if eax != FALSE
    or [xdi].bOptions, mask AutoMin
  .endif
  invoke GetDlgItemText, [xsi].hWnd, IDC_DSS_EDITMIN, xbx, lengthof cBuffer
  .ifBitSet [xdi].bOptions, mask XasDate
    invoke MultiByteToWideChar, CP_ACP, 0, xbx, -1, addr cTemp, lengthof cTemp
    invoke VarDateFromStr, addr cTemp, 0, LOCALE_NOUSEROVERRIDE, addr rTime

    fld rTime
    fsub [xdi].r8TimeStart
    mov eax, 24
    fildReg eax
    fmul
  .else
    fldStr xbx
  .endif
  fstp [xdi].r4SetupMin
  ;---------------------------------------------------
  invoke IsDlgButtonChecked, [xsi].hWnd, IDC_DSS_CHECKMJR
  .if eax == TRUE
    or [xdi].bOptions, mask AutoMjrDiv
  .endif
  invoke GetDlgItemInt, [xsi].hWnd, IDC_DSS_EDITMJR, addr dFailure, FALSE
  .if dFailure == TRUE
    .if (eax > 0) && (eax <= 20)
      mov [xdi].dSetupMjrDiv, eax
    .endif
  .endif
  ;---------------------------------------------------
  invoke IsDlgButtonChecked, [xsi].hWnd, IDC_DSS_CHECKMNR
  .if eax == TRUE
    or [xdi].bOptions, mask AutoMnrDiv
  .endif
  invoke GetDlgItemInt, [xsi].hWnd, IDC_DSS_EDITMNR, addr dFailure, FALSE
  .if dFailure == TRUE
    .if (eax > 0) && (eax <= 10)
      mov [xdi].dSetupMnrDiv, eax
    .endif
  .endif
  ;---------------------------------------------------
  invoke IsDlgButtonChecked, [xsi].hWnd, IDC_DSS_CHECKGRID
  .if eax == TRUE
    or [xdi].bOptions, mask ShowGrid
  .endif
  ;---------------------------------------------------
  invoke GetDlgItemText, [xsi].hWnd, IDC_DSS_EDITDESC, xbx, lengthof cBuffer
  invoke StrDispose, [xdi].pDesc
  mov [xdi].pDesc, $invoke(StrNew, xbx)
  ;---------------------------------------------------
  invoke GetDlgItemText, [xsi].hWnd, IDC_DSS_EDITUNIT, xbx, lengthof cBuffer
  invoke StrDispose, [xdi].pUnit
  mov [xdi].pUnit, $invoke(StrNew, xbx)

  assume xdi:NOTHING
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:    DialogSetupScale.CtlsSet
; Purpose:   Set the controls in this dialog window.
; Arguments: None.
; Return:    Nothing.

Method DialogSetupScale.CtlsSet, uses xbx xdi xsi
  local cBuffer[256]:CHR
  local r8TimeCurrent:REAL8, pTimeCurrent:POINTER

  SetObject xsi
  lea xbx, cBuffer
  mov xdi, [xsi].pScaleData
  assume xdi:PSCALE_DATA
  ;---------------------------------------------------
  .ifBitSet [xdi].bOptions, mask AutoMin
    invoke EnableWindow, $invoke(GetDlgItem, [xsi].hWnd, IDC_DSS_EDITMIN), FALSE
    m2m [xdi].r4SetupMin, [xdi].r4DataMin, edx
    mov eax, BST_CHECKED
  .else
    invoke EnableWindow, $invoke(GetDlgItem, [xsi].hWnd, IDC_DSS_EDITMIN), TRUE
    mov eax, BST_UNCHECKED
  .endif
  invoke CheckDlgButton, [xsi].hWnd, IDC_DSS_CHECKMIN, eax

  fld [xdi].r4SetupMin
  .ifBitSet [xdi].bOptions, mask XasDate
    mov eax, 24
    fildReg eax
    fdiv
    fadd [xdi].r8TimeStart
    fstp r8TimeCurrent

    ;We have to build the VarBstrFromDate stack manually since its proto has a bug
    if TARGET_STR_TYPE eq STR_TYPE_ANSI
      lea xax, pTimeCurrent
    else
      lea xax, cBuffer
    endif
    invoke VarBstrFromDate, r8TimeCurrent, 0, LOCALE_NOUSEROVERRIDE, xax
    if TARGET_STR_TYPE eq STR_TYPE_ANSI
      invoke WideCharToMultiByte, CP_ACP, 0, pTimeCurrent, -1, xbx, lengthof cBuffer, NULL, NULL
      invoke SysFreeString, pTimeCurrent
    endif
  .else
    invoke St0ToStr, xbx, 0, -1, f_NOR or f_NOR or f_TRIM
    fUnload
  .endif
  invoke SetDlgItemText, [xsi].hWnd, IDC_DSS_EDITMIN, xbx
  ;---------------------------------------------------
  .ifBitSet [xdi].bOptions, mask AutoMax
    invoke EnableWindow, $invoke(GetDlgItem, [xsi].hWnd, IDC_DSS_EDITMAX), FALSE
    m2m [xdi].r4SetupMax, [xdi].r4DataMax, edx
    mov eax, BST_CHECKED
  .else
    invoke EnableWindow, $invoke(GetDlgItem, [xsi].hWnd, IDC_DSS_EDITMAX), TRUE
    mov eax, BST_UNCHECKED
  .endif
  invoke CheckDlgButton, [xsi].hWnd, IDC_DSS_CHECKMAX, eax

  fld [xdi].r4SetupMax
  .ifBitSet [xdi].bOptions, mask XasDate
    mov eax, 24
    fildReg eax
    fdiv
    fadd [xdi].r8TimeStart
    fstp r8TimeCurrent

    if TARGET_STR_TYPE eq STR_TYPE_ANSI
      lea xax, pTimeCurrent
    else
      lea xax, cBuffer
    endif
    invoke VarBstrFromDate, r8TimeCurrent, 0, LOCALE_NOUSEROVERRIDE, xax
    if TARGET_STR_TYPE eq STR_TYPE_ANSI
      invoke WideCharToMultiByte, CP_ACP, 0, pTimeCurrent, -1, xbx, lengthof cBuffer, NULL, NULL
      invoke SysFreeString, pTimeCurrent
    endif
  .else
    invoke St0ToStr, xbx, 0, -1, f_NOR or f_TRIM
    fUnload
  .endif
  invoke SetDlgItemText, [xsi].hWnd, IDC_DSS_EDITMAX, xbx
  ;---------------------------------------------------
  .ifBitSet [xdi].bOptions, mask AutoMjrDiv
    invoke EnableWindow, $invoke(GetDlgItem, [xsi].hWnd, IDC_DSS_EDITMJR), FALSE
    m2m [xdi].dSetupMjrDiv, [xdi].dDataMjrDiv, edx
    mov eax, BST_CHECKED
  .else
    invoke EnableWindow, $invoke(GetDlgItem, [xsi].hWnd, IDC_DSS_EDITMJR), TRUE
    mov eax, BST_UNCHECKED
  .endif
  invoke CheckDlgButton, [xsi].hWnd, IDC_DSS_CHECKMJR, eax

  invoke SetDlgItemInt, [xsi].hWnd, IDC_DSS_EDITMJR, [xdi].dSetupMjrDiv, FALSE
  ;---------------------------------------------------
  .ifBitSet [xdi].bOptions, mask AutoMnrDiv
    invoke EnableWindow, $invoke(GetDlgItem, [xsi].hWnd, IDC_DSS_EDITMNR), FALSE
    m2m [xdi].dSetupMnrDiv, [xdi].dDataMnrDiv, edx
    mov eax, BST_CHECKED
  .else
    invoke EnableWindow, $invoke(GetDlgItem, [xsi].hWnd, IDC_DSS_EDITMNR), TRUE
    mov eax, BST_UNCHECKED
  .endif
  invoke CheckDlgButton, [xsi].hWnd, IDC_DSS_CHECKMNR, eax

  invoke SetDlgItemInt, [xsi].hWnd, IDC_DSS_EDITMNR, [xdi].dSetupMnrDiv, FALSE
  ;---------------------------------------------------
  .ifBitSet [xdi].bOptions, mask ShowGrid
    mov eax, BST_CHECKED
  .else
    mov eax, BST_UNCHECKED
  .endif
  invoke CheckDlgButton, [xsi].hWnd, IDC_DSS_CHECKGRID, eax
  ;---------------------------------------------------
  invoke SetDlgItemText, [xsi].hWnd, IDC_DSS_EDITDESC, [xdi].pDesc
  ;---------------------------------------------------
  invoke SetDlgItemText, [xsi].hWnd, IDC_DSS_EDITUNIT, [xdi].pUnit

  assume xdi:NOTHING
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     DialogSetupScale.Done
; Purpose:    Finalize a dialog.
; Arguments:  None.
; Return:     Nothing.

Method DialogSetupScale.Done, uses xsi
  SetObject xsi
  invoke StrDispose, [xsi].pPrevDesc
  invoke StrDispose, [xsi].pPrevUnit
  ACall xsi.Done
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     DialogSetupScale.Init
; Purpose:    Initialaize the DialogSetupScale dialog object.
; Arguments:  Arg1: -> Owner object.
;             Arg2: Parent window HANDLE.
;             Arg3: -> SCALE_BASIC_DATA.
; Return:     Nothing.

Method DialogSetupScale.Init, uses xbx xsi, pOwner:POINTER, hParent:HWND, pScaleData:PSCALE_BASIC_DATA
  SetObject xsi
  ACall xsi.Init, pOwner, hParent, $OfsCStr("DialogSetupScale")
  invoke MemClone, addr [xsi].PrvScaleData, pScaleData, sizeof SCALE_BASIC_DATA
  mov xbx, pScaleData
  mov [xsi].pScaleData, xbx
  mov [xsi].pPrevDesc, $invoke(StrNew, [xbx].SCALE_BASIC_DATA.pDesc)
  mov [xsi].pPrevUnit, $invoke(StrNew, [xbx].SCALE_BASIC_DATA.pUnit)
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     DialogSetupScale.OnClose
; Purpose:    Event procedure for WM_CLOSE message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method DialogSetupScale.OnClose,, wParam:WPARAM, lParam:LPARAM
  SetObject xcx
  invoke SendMessage, [xcx].hWnd, WM_COMMAND, IDCANCEL, 0
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     DialogSetupScale.OnCommand
; Purpose:    Event procedure for WM_COMMAND message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method DialogSetupScale.OnCommand, uses xbx xdi xsi, wParam:WPARAM, lParam:LPARAM
  SetObject xsi

  xor eax, eax
  LoWord wParam

  mov ecx, eax
  .if ecx == IDOK
    OCall xsi.CtlsGet
    OCall xsi.DestroyDialog, wParam
    OCall [xsi].pOwner::PlotXY.Refresh

  .elseif ecx == IDCANCEL
    ;Restore previous settings
    mov xbx, [xsi].pScaleData
    mov xcx, [xbx].SCALE_DATA.pDesc
    m2m [xbx].SCALE_DATA.pDesc, [xsi].pPrevDesc, xdx
    mov [xsi].pPrevDesc, xcx
    mov xcx, [xbx].SCALE_DATA.pUnit
    m2m [xbx].SCALE_DATA.pUnit, [xsi].pPrevUnit, xdx
    mov [xsi].pPrevUnit, xcx
    invoke MemClone, xbx, addr [xsi].PrvScaleData, sizeof SCALE_BASIC_DATA - 16 ; w/o last three items
    OCall xsi.DestroyDialog, wParam
    OCall [xsi].pOwner::PlotXY.Refresh

  .elseif ecx == IDC_DSS_PREVIEW
    OCall xsi.CtlsGet
    OCall [xsi].pOwner::PlotXY.Refresh
    OCall xsi.CtlsSet

  .elseif ecx == IDC_DSS_COLORS
    mov xbx, $New(DialogSetupColors)
    OCall xbx::DialogSetupColors.Init, [xsi].pOwner, [xsi].hWnd
    OCall xbx::DialogSetupColors.Show
    Destroy xbx
    OCall [xsi].pOwner::PlotXY.Refresh

  .elseif (ecx >= IDC_DSS_CHECKMIN) && (ecx <= IDC_DSS_CHECKMNR)
    HiWord wParam
    .if eax == BN_CLICKED
      mov edi, ecx
      mov edx, ecx
      add edx, IDC_DSS_EDITMIN - IDC_DSS_CHECKMIN
      mov xbx, $invoke(GetDlgItem, [xsi].hWnd, edx)
      invoke IsDlgButtonChecked, [xsi].hWnd, edi
      Choose eax, TRUE, FALSE
      invoke EnableWindow, xbx, eax
    .endif
  .endif
MethodEnd



; ==================================================================================================
;    DialogSetupColors implementation
; ==================================================================================================

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     DialogSetupColors.CtlsSet
; Purpose:    Set the controls in this dialog window.
; Arguments:  None.
; Return:     Nothing.

Method DialogSetupColors.CtlsSet, uses xdi xsi
  SetObject xsi
  mov xcx, [xsi].pOwner
  lea xdi, [xcx].$Obj(PlotXY).PlotXYData.Colors
  assume xdi:PCOLOR_CONFIG

  invoke MemClone, addr [xsi].NewColors, xdi, sizeof COLOR_CONFIG   ;Make a work copy
  invoke MemClone, addr [xsi].PrvColors, xdi, sizeof COLOR_CONFIG   ;Make a backup copy

  invoke GetDlgItem, [xsi].hWnd, IDC_SGC_GRID
  invoke SendMessage, xax, BM_SETCOLOR, 0, [xdi].dGrid
  invoke GetDlgItem, [xsi].hWnd, IDC_SGC_PLOTAREA
  invoke SendMessage, xax, BM_SETCOLOR, 0, [xdi].dPlotArea
  invoke GetDlgItem, [xsi].hWnd, IDC_SGC_PLOTBORDER
  invoke SendMessage, xax, BM_SETCOLOR, 0, [xdi].dPlotBorder
  invoke GetDlgItem, [xsi].hWnd, IDC_SGC_BACKGROUND
  invoke SendMessage, xax, BM_SETCOLOR, 0, [xdi].dBackground
  invoke GetDlgItem, [xsi].hWnd, IDC_SGC_SCALES
  invoke SendMessage, xax, BM_SETCOLOR, 0, [xdi].dScales

  assume xdi:NOTHING
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     DialogSetupColors.CtlsGet
; Purpose:    Read the controls in this dialog window.
; Arguments:  None.
; Return:     Nothing.

Method DialogSetupColors.CtlsGet
  SetObject xdx
  mov xax, [xdx].pOwner
  lea xcx, [xax].$Obj(PlotXY).PlotXYData.Colors
  invoke MemClone, xcx, addr [xdx].NewColors, sizeof COLOR_CONFIG   ;Return colors to XGraph
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     DialogSetupColors.Init
; Purpose:    Initialaize the DialogSetupColors dialog object.
; Arguments:  Arg1: -> Owner object.
;             Arg2: Parent window HANDLE.
; Return:     Nothing.

Method DialogSetupColors.Init,, pOwner:POINTER, hParent:HWND
  ACall Init, pOwner, hParent, $OfsCStr("DialogSetupGraph2dColors")
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     DialogSetupColors.OnClose
; Purpose:    Event procedure for WM_CLOSE message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method DialogSetupColors.OnClose,, wParam:WPARAM, lParam:LPARAM
  SetObject xcx
  invoke SendMessage, [xcx].hWnd, WM_COMMAND, IDCANCEL, 0
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     DialogSetupColors.OnCommand
; Purpose:    Event procedure for WM_COMMAND message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method DialogSetupColors.OnCommand, uses xbx xdi xsi, wParam:WPARAM, lParam:LPARAM
  local CC:CHOOSECOLOR, ColorRef[16]:DWORD

  SetObject xsi
  .if wParam == IDOK
    OCall xsi.CtlsGet
    OCall xsi.DestroyDialog, wParam
    OCall [xsi].pOwner::PlotXY.Refresh
  .elseif wParam == IDCANCEL
    mov xax, [xsi].pOwner
    lea xcx, [xax].$Obj(PlotXY).PlotXYData.Colors
    invoke MemClone, xcx, addr [xsi].PrvColors, sizeof COLOR_CONFIG
    OCall xsi.DestroyDialog, wParam
    OCall [xsi].pOwner::PlotXY.Refresh
  .elseif wParam == IDC_SGC_PREVIEW
    OCall xsi.CtlsGet
    OCall [xsi].pOwner::PlotXY.Refresh
  .elseif (wParam >= IDC_SGC_GRID) && (wParam <= IDC_SGC_SCALES)
    mov CC.lStructSize, sizeof CC
    m2m CC.hwndOwner, [xsi].hWnd, xdx
    m2m CC.hInstance, hInstance, xdx
    mov CC.Flags, CC_RGBINIT; or CC_FULLOPEN
    m2z CC.lCustData
    m2z CC.lpfnHook
    m2z CC.lpTemplateName

    ;Fill 1st part with the COLOR_CONFIG colors
    lea xdi, ColorRef
    mov CC.lpCustColors, xdi
    lea xax, [xsi].NewColors
    invoke MemClone, xdi, xax, sizeof COLOR_CONFIG

    ;Fill the 2 remaining colors with white
    lea xdi, ColorRef + 6*sizeof DWORD
    mov eax, 255
    mov ecx, 3
    rep stosb                                           ;Store B = G = R = eax
    xor eax, eax
    stosb                                               ;Store alpha = 0
    mov eax, 255
    mov ecx, 3
    rep stosb                                           ;Store B = G = R = eax
    xor eax, eax
    stosb                                               ;Store alpha = 0

    ;Fill 2nd part with a gray scale
    mov edx, 255*256
    .repeat
      mov eax, edx
      shr eax, 8                                        ;/256
      mov ecx, 3
      rep stosb                                         ;Store B = G = R = eax
      xor eax, eax
      stosb                                             ;Store alpha = 0
      sub edx, 9325                                     ;int(255 * 256 / 7)
    .until SIGN?

    .if wParam == IDC_SGC_GRID
      lea xbx, [xsi].NewColors.dGrid
    .elseif wParam ==  IDC_SGC_PLOTAREA
      lea xbx, [xsi].NewColors.dPlotArea
    .elseif wParam == IDC_SGC_PLOTBORDER
      lea xbx, [xsi].NewColors.dPlotBorder
    .elseif wParam == IDC_SGC_BACKGROUND
      lea xbx, [xsi].NewColors.dBackground
    .elseif wParam == IDC_SGC_SCALES
      lea xbx, [xsi].NewColors.dScales
    .endif

    m2m CC.rgbResult, DWORD ptr [xbx], edx
    invoke ChooseColor, addr CC
    .if eax
      m2m [xbx], CC.rgbResult, edx
      invoke GetDlgItem, [xsi].hWnd, DWORD ptr wParam
      invoke SendMessage, xax, BM_SETCOLOR, 0, CC.rgbResult
    .endif
  .endif
MethodEnd

endif
