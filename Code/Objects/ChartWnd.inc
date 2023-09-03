; ==================================================================================================
; Title:      ChartWnd.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm support of ChartWnd objects.
; Notes:      Version C.1.0, August 2021
;               - First release.
; ==================================================================================================



; ==================================================================================================
;    ChartWnd implementation
; ==================================================================================================

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     ChartWnd.Calc
; Purpose:    Compute internal values of a scale.
; Arguments:  Arg1: Output device context.
;             Arg2: -> Output rect.
; Return:     Nothing.

CalcScaleInternalValues macro Scale
  .ifBitSet Scale.dFlags, CHT_SCALE_AUTO_MIN
    s2s Scale.fScaleMin, Scale.fDataMin, xcx, xdx
  .else
    s2s Scale.fScaleMin, Scale.fSetupMin, xcx, xdx
  .endif

  .ifBitSet Scale.dFlags, CHT_SCALE_AUTO_MAX
    s2s Scale.fScaleMax, Scale.fDataMax, xcx, xdx
  .else
    s2s Scale.fScaleMax, Scale.fSetupMax, xcx, xdx
  .endif

  fld Scale.fScaleMin
  fcomp Scale.fScaleMax
  fGetFlags
  .if ZERO?                                             ;Min = Max
    fld Scale.fScaleMax
    fld1
    faddp st(1), st(0)
    fstp Scale.fScaleMax
  .elseif !CARRY?                                       ;if Min > Max => swap
    s2s TempScaleEnd, Scale.fScaleMin, xcx, xdx
    s2s Scale.fScaleMin, Scale.fScaleMax, xcx, xdx
    s2s Scale.fScaleMax, TempScaleEnd, xcx, xdx
  .endif

  OCall xsi.CalcScaleDivs, addr Scale
endm

SetScaleTitle macro Scale
  m2z CHR ptr [xdi]                                     ;Set first CHR to zero
  .if Scale.pDescription != NULL
    .if $invoke(StrLength, Scale.pDescription)
      invoke StrCCopy, xdi, Scale.pDescription, lengthof cBuffer
    .endif
  .endif
  .if Scale.pUnit != NULL
    .if $invoke(StrLength, Scale.pUnit)
      .if Scale.pDescription != NULL
        .if $invoke(StrLength, Scale.pDescription)
          invoke StrCCatChar, xdi, " ", lengthof cBuffer
        .endif
      .endif
      invoke StrCCatChar, xdi, "[", lengthof cBuffer
      invoke StrCCat, xdi, Scale.pUnit, lengthof cBuffer
      invoke StrCCatChar, xdi, "]", lengthof cBuffer
    .endif
  .endif

  invoke StrDispose, Scale.pTitle
  .if Scale.pDescription != NULL || Scale.pUnit != NULL
    mov Scale.pTitle, $invoke(StrNew, xdi)
  .else
    mov Scale.pTitle, NULL
  .endif
endm

Method ChartWnd.Calc, uses xbx xdi xsi, hDC:HWND, pOutRect:PRECT
  local TextSize1:POINT, TextSize2:POINT, hPrevFont:HFONT
  local cBuffer[1024]:CHR, dValue:DWORD, TempScaleEnd:CHT_FLOAT

;  DbgText "ChartWnd.Calc"
  SetObject xsi
  mov hPrevFont, $invoke(SelectObject, hDC, [xsi].hFontHorz)

  ;Set ViewRect = OutRect and DrawRect = ViewRect - Padding
  mov xbx, pOutRect
  mrm [xsi].ViewRect.left, [xbx].RECT.left, eax
  add eax, [xsi].Padding.left
  mov [xsi].DrawRect.left, eax
  mrm [xsi].ViewRect.top, [xbx].RECT.top, eax
  add eax, [xsi].Padding.top
  mov [xsi].DrawRect.top, eax
  mrm [xsi].ViewRect.right, [xbx].RECT.right, eax
  sub eax, [xsi].Padding.right
  mov [xsi].DrawRect.right, eax
  mrm [xsi].ViewRect.bottom, [xbx].RECT.bottom, eax
  sub eax, [xsi].Padding.bottom
  mov [xsi].DrawRect.bottom, eax

  ;Set scale titles -------------------------------------------------
  lea xdi, cBuffer
  SetScaleTitle [xsi].ScaleX
  SetScaleTitle [xsi].ScaleY1           ;§§§
  SetScaleTitle [xsi].ScaleY2           ;§§§

  ;Calculate scale internal factors ---------------------------------
  CalcScaleInternalValues [xsi].ScaleX
  CalcScaleInternalValues [xsi].ScaleY1
  CalcScaleInternalValues [xsi].ScaleY2

  ;Calculate some plot metrics based on the font metrics ------------
  mov eax, [xsi].TextMetricHorz.tmHeight                ;height = ascent + descent
  shr eax, 1
  mov [xsi].ScaleX.dDivMjrLen, eax
  mov [xsi].ScaleY1.dDivMjrLen, eax
  mov [xsi].ScaleY2.dDivMjrLen, eax
  inc eax
  shr eax, 1
  mov [xsi].ScaleX.dDivMnrLen, eax
  mov [xsi].ScaleY1.dDivMnrLen, eax
  mov [xsi].ScaleY2.dDivMnrLen, eax
  mov [xsi].ScaleY1.dLabelSep, eax                      ;Gap between divisions and label on Y scale
  mov [xsi].ScaleY2.dLabelSep, eax
  mov [xsi].ScaleX.dLabelSep, eax                       ;Gap between divisions and label on X scale
  mov [xsi].ScaleX.dTitleSep, eax                       ;Gap between title and label on X scale
  mov [xsi].ScaleY1.dTitleSep, eax                      ;Gap between title and label on Y scale
  mov [xsi].ScaleY2.dTitleSep, eax

  ;Determine the top plot border ------------------------------------
  mov eax, [xsi].TextMetricHorz.tmHeight                ;height = ascent + descent
  inc eax
  shr eax, 1
  add eax, [xsi].DrawRect.top                           ;Let a small distance
  mov [xsi].PlotRect.top, eax

  ;Determine the left plot border -----------------------------------
  .ifBitSet [xsi].dFlags, CHT_WND_SHOW_Y1
    m2m [xsi].PlotRect.left, [xsi].DrawRect.left, eax

    .ifBitSet [xsi].ScaleY1.dFlags, CHT_SCALE_SHOW_LABEL
      lea xdi, cBuffer
      fld [xsi].ScaleY1.fScaleMin
      invoke St0ToStr, xdi, 0, [xsi].ScaleY1.dDecimals, f_NOR
      fUnload
      invoke StrLength, xdi
      lea xbx, TextSize1
      invoke GetTextExtentPoint32, hDC, xdi, eax, xbx   ;TextSize1 = extent of Y scale Min label

      fld [xsi].ScaleY1.fScaleMax
      invoke St0ToStr, xdi, 0, [xsi].ScaleY1.dDecimals, f_NOR
      fUnload
      invoke StrLength, xdi
      lea xbx, TextSize2
      invoke GetTextExtentPoint32, hDC, xdi, eax, xbx   ;TextSize2 = extent of Y scale Max label

      uMax TextSize1.x, TextSize2.x                     ;eax = Widest Y scale label
      add eax, [xsi].ScaleY1.dLabelSep                  ;add label separation
      add [xsi].PlotRect.left, eax
    .endif

    .ifBitSet [xsi].ScaleY1.dFlags, CHT_SCALE_SHOW_TITLE
      .if [xsi].ScaleY1.pTitle != NULL
        mov eax, [xsi].TextMetricVert.tmHeight
        add eax, [xsi].ScaleY1.dTitleSep
        add [xsi].PlotRect.left, eax                    ;Y scale title height + separation
      .endif
    .endif

    .ifBitSet [xsi].ScaleY1.dFlags, CHT_SCALE_SHOW_MJR_DIV
      mov eax, [xsi].ScaleY1.dDivMjrLen                 ;Major division lenght
      add [xsi].PlotRect.left, eax
    .elseIfBitSet [xsi].ScaleY1.dFlags, CHT_SCALE_SHOW_MNR_DIV
      mov eax, [xsi].ScaleY1.dDivMnrLen                 ;Minor division lenght
      add [xsi].PlotRect.left, eax
    .endif
  .else
    .ifBitSet [xsi].ScaleX.dFlags, CHT_SCALE_SHOW_LABEL
      .ifBitSet [xsi].ScaleX.dFlags, CHT_SCALE_SHOW_AS_DATE or CHT_SCALE_SHOW_AS_DATEDIFF or \
                                       CHT_SCALE_SHOW_AS_TIME
        m2z TextSize1.x
        m2z TextSize2.x
        .ifBitSet [xsi].ScaleX.dFlags, CHT_SCALE_SHOW_AS_DATE or CHT_SCALE_SHOW_AS_DATEDIFF
          .ifBitSet [xsi].ScaleX.dFlags, CHT_SCALE_SHOW_AS_DATEDIFF
            fld [xsi].ScaleX.fScaleMin
            invoke St0ToStr, xdi, 0, 0, f_NOR
            fUnload
            invoke StrLength, xdi
            lea xbx, TextSize1
            invoke GetTextExtentPoint32, hDC, xdi, eax, xbx
          .else
            FillString CHR ptr [xdi], <DD.MM.YYYY>
            lea xbx, TextSize1
            invoke GetTextExtentPoint32, hDC, xdi, 10, xbx
          .endif
        .endif
        .ifBitSet [xsi].ScaleX.dFlags, CHT_SCALE_SHOW_AS_TIME
          FillString CHR ptr [xdi], <00:00:00>
          lea xbx, TextSize2
          invoke GetTextExtentPoint32, hDC, xdi, 8, xbx
        .endif
      .else
        fld [xsi].ScaleX.fScaleMin
        invoke St0ToStr, xdi, 0, [xsi].ScaleX.dDecimals, f_NOR
        fUnload
        invoke StrLength, xdi
        lea xbx, TextSize1
        invoke GetTextExtentPoint32, hDC, xdi, eax, xbx
      .endif

      mov ecx, TextSize1.x
      .if ecx < TextSize2.x
        mov ecx, TextSize2.x
      .endif
      inc ecx
      shr ecx, 1
      mov eax, [xsi].DrawRect.left
      add eax, ecx
    .else
      mov eax, [xsi].DrawRect.left
    .endif
    mov [xsi].PlotRect.left, eax
  .endif

  ;Determine the right plot border ----------------------------------
  .ifBitClr [xsi].dFlags, CHT_WND_SHOW_Y2
    .ifBitSet [xsi].ScaleX.dFlags, CHT_SCALE_SHOW_LABEL
      .ifBitSet [xsi].ScaleX.dFlags, CHT_SCALE_SHOW_AS_DATE or CHT_SCALE_SHOW_AS_DATEDIFF or \
                                       CHT_SCALE_SHOW_AS_TIME
        m2z TextSize1.x
        m2z TextSize2.x
        .ifBitSet [xsi].ScaleX.dFlags, CHT_SCALE_SHOW_AS_DATE or CHT_SCALE_SHOW_AS_DATEDIFF
          .ifBitSet [xsi].ScaleX.dFlags, CHT_SCALE_SHOW_AS_DATEDIFF
            fld [xsi].ScaleX.fScaleMax
            invoke St0ToStr, xdi, 0, 0, f_NOR
            fUnload
            invoke StrLength, xdi
            lea xbx, TextSize1
            invoke GetTextExtentPoint32, hDC, xdi, eax, xbx
          .else
            FillString CHR ptr [xdi], <DD.MM.YYYY>
            lea xbx, TextSize1
            invoke GetTextExtentPoint32, hDC, xdi, 10, xbx
          .endif
        .endif
        .ifBitSet [xsi].ScaleX.dFlags, CHT_SCALE_SHOW_AS_TIME
          FillString CHR ptr [xdi], <00:00:00>
          lea xbx, TextSize2
          invoke GetTextExtentPoint32, hDC, xdi, 8, xbx
        .endif
      .else
        fld [xsi].ScaleX.fScaleMax
        invoke St0ToStr, xdi, 0, [xsi].ScaleX.dDecimals, f_NOR
        fUnload
        invoke StrLength, xdi
        lea xbx, TextSize1
        invoke GetTextExtentPoint32, hDC, xdi, eax, xbx
      .endif

      mov ecx, TextSize1.x
      .if ecx < TextSize2.x
        mov ecx, TextSize2.x
      .endif
      inc ecx
      shr ecx, 1
      mov eax, [xsi].DrawRect.right
      sub eax, ecx
    .else
      mov eax, [xsi].DrawRect.right
    .endif
    .if SDWORD ptr eax < [xsi].PlotRect.left
      mov eax, [xsi].PlotRect.left
    .endif
    mov [xsi].PlotRect.right, eax                       ;This edge is not included in the plot area
  .else
    m2m [xsi].PlotRect.right, [xsi].DrawRect.right, eax

    .ifBitSet [xsi].ScaleY2.dFlags, CHT_SCALE_SHOW_LABEL
      lea xdi, cBuffer
      fld [xsi].ScaleY2.fScaleMin
      invoke St0ToStr, xdi, 0, [xsi].ScaleY2.dDecimals, f_NOR
      fUnload
      invoke StrLength, xdi
      lea xbx, TextSize1
      invoke GetTextExtentPoint32, hDC, xdi, eax, xbx   ;TextSize1 = extent of Y scale Min label

      fld [xsi].ScaleY2.fScaleMax
      invoke St0ToStr, xdi, 0, [xsi].ScaleY2.dDecimals, f_NOR
      fUnload
      invoke StrLength, xdi
      lea xbx, TextSize2
      invoke GetTextExtentPoint32, hDC, xdi, eax, xbx   ;TextSize2 = extent of Y scale Max label

      uMax TextSize1.x, TextSize2.x                     ;eax = Widest Y scale label
      add eax, [xsi].ScaleY2.dLabelSep                  ;add label separation
      sub [xsi].PlotRect.right, eax
    .endif

    .ifBitSet [xsi].ScaleY2.dFlags, CHT_SCALE_SHOW_TITLE
      .if [xsi].ScaleY2.pTitle != NULL
        mov eax, [xsi].TextMetricVert.tmHeight
        add eax, [xsi].ScaleY2.dTitleSep
        sub [xsi].PlotRect.right, eax                   ;Y scale title height + separation
      .endif
    .endif

    .ifBitSet [xsi].ScaleY2.dFlags, CHT_SCALE_SHOW_MJR_DIV
      mov eax, [xsi].ScaleY2.dDivMjrLen                 ;Major division lenght
      sub [xsi].PlotRect.right, eax
    .elseIfBitSet [xsi].ScaleY2.dFlags, CHT_SCALE_SHOW_MNR_DIV
      mov eax, [xsi].ScaleY2.dDivMnrLen                 ;Minor division lenght
      sub [xsi].PlotRect.right, eax
    .endif
  .endif

  ;Determine the bottom plot border ---------------------------------
  xor ecx, ecx
  .ifBitSet [xsi].ScaleX.dFlags, CHT_SCALE_SHOW_TITLE
    .if [xsi].ScaleX.pTitle != NULL
      mov ecx, [xsi].TextMetricHorz.tmHeight
      sub ecx, [xsi].TextMetricHorz.tmInternalLeading
      add ecx, [xsi].ScaleX.dTitleSep                   ;X scale title height + separation
    .endif
  .endif

  .ifBitSet [xsi].ScaleX.dFlags, CHT_SCALE_SHOW_LABEL
    add ecx, [xsi].TextMetricHorz.tmHeight              ;Scale label height
    sub ecx, [xsi].TextMetricHorz.tmInternalLeading
    add ecx, [xsi].ScaleX.dLabelSep                     ;Label separation
    .ifBitSet [xsi].ScaleX.dFlags, CHT_SCALE_SHOW_AS_DATE or CHT_SCALE_SHOW_AS_DATEDIFF
      .ifBitSet [xsi].ScaleX.dFlags, CHT_SCALE_SHOW_AS_TIME
        add ecx, [xsi].TextMetricHorz.tmHeight          ;Add an additional line
        add ecx, [xsi].TextMetricHorz.tmDescent         ;Add a bit more space
      .endif
    .endif
  .endif

  .ifBitSet [xsi].ScaleX.dFlags, CHT_SCALE_SHOW_MJR_DIV
    add ecx, [xsi].ScaleX.dDivMjrLen                    ;Major division length
  .elseIfBitSet [xsi].ScaleX.dFlags, CHT_SCALE_SHOW_MNR_DIV
    add ecx, [xsi].ScaleX.dDivMnrLen                    ;Minor division length
  .endif

  mov eax, [xsi].DrawRect.bottom
  sub eax, ecx

  .if SDWORD ptr eax < [xsi].PlotRect.top
    mov eax, [xsi].PlotRect.top
    add ecx, eax
    mov [xsi].DrawRect.bottom, ecx
  .endif
  mov [xsi].PlotRect.bottom, eax                        ;This edge is not included in the plot area

  ;Calculate scale factors ----------------------------------------
  mov eax, [xsi].PlotRect.right
  sub eax, [xsi].PlotRect.left
  mov dValue, eax
  fld [xsi].ScaleX.fScaleMax
  fsub [xsi].ScaleX.fScaleMin
  fidivr dValue
  fstp [xsi].ScaleX.fScaleFactor

  mov eax, [xsi].PlotRect.bottom
  sub eax, [xsi].PlotRect.top
  mov dValue, eax
  fld [xsi].ScaleY1.fScaleMax
  fsub [xsi].ScaleY1.fScaleMin
  fidivr dValue
  fstp [xsi].ScaleY1.fScaleFactor

  fld [xsi].ScaleY2.fScaleMax
  fsub [xsi].ScaleY2.fScaleMin
  fidivr dValue
  fstp [xsi].ScaleY2.fScaleFactor

  invoke SelectObject, hDC, hPrevFont
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     ChartWnd.CalcScaleDivs
; Purpose:    Compute major and minor scale divisions and scale decimal digits.
; Arguments:  Arg1: -> Scale data.
; Return:     Nothing.

Method ChartWnd.CalcScaleDivs, uses xbx, pScaleData:PCHT_SCALE_DATA
  local fNewLoLim:CHT_FLOAT, fNewUpLim:CHT_FLOAT        ;New Lower Limit (NLL)
  local dIndex:DWORD, dBuffer:DWORD                     ;  and New Upper Limit (NUL)

  .const
    bSclMjrDivs  db  05, 04, 06, 04, 05, 06, 07, 08, 09, 10, 11, 06
    bSclMnrDivs  db  04, 05, 05, 05, 05, 05, 02, 02, 05, 02, 02, 05
  .code

  mov xbx, pScaleData
  assume xbx:PCHT_SCALE_DATA
  fld [xbx].fScaleMax
  fsub [xbx].fScaleMin
  fabs                                                  ;Be sure UL-LL > 0
  fLogT
  fRndDn                                                ;E
  fExpT                                                 ;FR = Rounded exponent of |NUL-NLL|

  fld [xbx].fScaleMin
  fdiv st(0), st(1)
  fRndDn
  fmul st(0), st(1)
  fstp fNewLoLim

  fld [xbx].fScaleMax
  fdiv st(0), st(1)
  fRndUp
  fmul st(0), st(1)
  fst fNewUpLim

  fld fNewLoLim
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
  fistp [xbx].dDecimals

  fxch
  fdivr st(0), st(1)
  fRnd
  fistp dIndex                                          ;Index = Rnd(NUL-NLL) / FR
  dec dIndex                                            ;Make zero based index
  .if dIndex >= 12
    mov dIndex, 11                                      ;Clamp the dIndex value
  .endif

  .ifBitSet [xbx].dFlags, CHT_SCALE_AUTO_MNR_DIV
    mov eax, dIndex                                     ;Get minor divisions from table
    lea xbx, bSclMnrDivs                                ;xbx = table base address
    xlatb
    mov xbx, pScaleData
    mov [xbx].dDivMnrCount, eax
  .else
    mrm [xbx].dDivMnrCount, [xbx].dSetupMnrDiv, eax
  .endif
  mov [xbx].dDataMnrDiv, eax

  .ifBitSet [xbx].dFlags, CHT_SCALE_AUTO_MJR_DIV
    mov eax, dIndex                                     ;Get major divisions from table
    lea xbx, bSclMjrDivs
    xlatb
    mov xbx, pScaleData
    mov dBuffer, eax
    fild dBuffer
  .else
    fild [xbx].dSetupMjrDiv
    mov eax, [xbx].dSetupMjrDiv
  .endif
  mov [xbx].dDataMjrDiv, eax

  fdivp st(1), st(0)
  fst [xbx].fDivMjrStp

  fld [xbx].fScaleMin                                   ;Start repeat-until loop
  fld fNewLoLim
@@1:
  fcomi st(0), st(1)
  .if !ZERO? && CARRY?                                  ;while x < fScaleMin
    fadd st(0), st(2)
    jmp @@1
  .endif
  fstp [xbx].fDivMjrFst
  fstp dBuffer

  fld [xbx].fScaleMax                                   ;Start repeat-until loop
  fld fNewUpLim
@@2:
  fcomi st(0),  st(1)
  .if !ZERO? && !CARRY?                                 ;while x > fScaleMax
    fsub st(0), st(2)
    jmp @@2
  .endif

  fUnload 3                                             ;Unload FPU stack

  assume xbx:NOTHING
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     ChartWnd.Dispatch
; Purpose:    Dispatching of window messages.
; Arguments:  Arg1: Window handle.
;             Arg2: Message identifier.
;             Arg3: First message parameter.
;             Arg4: Second message parameter.
; Return:     eax = This value is the result of the message processing and depends on the message.

Method ChartWnd.Dispatch, uses xsi, hWnd:HWND, uMsg:DWORD, wParam:WPARAM, lParam:LPARAM
;  DbgMessage uMsg
  SetObject xsi
  DispatchEvent <DefWindowProc, hWnd>                   ;xsi -> Object instance
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     ChartWnd.Done
; Purpose:    Finalize the ChartWnd object.
; Arguments:  None.
; Return:     Nothing.

Method ChartWnd.Done, uses xsi
  SetObject xsi

  .if [xsi].hWnd != 0
    invoke DestroyWindow, [xsi].hWnd
    mov [xsi].hWnd, 0
  .endif

  invoke StrDispose, [xsi].ScaleX.pTitle
  invoke StrDispose, [xsi].ScaleX.pDescription
  invoke StrDispose, [xsi].ScaleX.pUnit

  invoke StrDispose, [xsi].ScaleY1.pTitle
  invoke StrDispose, [xsi].ScaleY1.pDescription
  invoke StrDispose, [xsi].ScaleY1.pUnit

  invoke StrDispose, [xsi].ScaleY2.pTitle
  invoke StrDispose, [xsi].ScaleY2.pDescription
  invoke StrDispose, [xsi].ScaleY2.pUnit

  OCall [xsi].Data::Collection.Done
  OCall [xsi].InfoAreas::DataCollection.Done

  invoke DestroyWindow, [xsi].hToolTip

  invoke DeleteObject, [xsi].hFontHorz
  invoke DeleteObject, [xsi].hFontVert

  ACall xsi.Done
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     ChartWnd.DrawFrame
; Purpose:    Draw the chart frame.
; Arguments:  Arg1: Output device context.
; Return:     Nothing.

CHT_LABEL_INFO struc
  sdPosition  SDWORD      ?
  fValue      CHT_FLOAT   ?
CHT_LABEL_INFO ends
PCHT_LABEL_INFO typedef ptr CHT_LABEL_INFO

Method ChartWnd.DrawFrame, uses xdi xsi, hDC:HDC
  local hPrevPen:HPEN, hPrevBrush:HBRUSH

  SetObject xsi

  ;Fill output area -------------------------------------------------
  .ifBitSet [xsi].dFlags, CHT_WND_COLOR
    mov eax, [xsi].Colors.Background
  .else
    mov eax, $RGB(255,255,255)
  .endif
  mov xdi, $invoke(CreateSolidBrush, eax)
  invoke FillRect, hDC, addr [xsi].ViewRect, xdi
  invoke DeleteObject, xdi

  ;Plot a line around the plot area and fill the interior  ----------
  .ifBitSet [xsi].dFlags, CHT_WND_COLOR
    mov eax, [xsi].Colors.PlotBorder
  .else
    mov eax, $RGB(000,000,000)
  .endif
  invoke CreatePen, PS_SOLID, 1, eax
  mov hPrevPen, $invoke(SelectObject, hDC, xax)

  .ifBitSet [xsi].dFlags, CHT_WND_COLOR
    mov eax, [xsi].Colors.PlotArea
  .else
    mov eax, $RGB(255,255,255)
  .endif
  invoke CreateSolidBrush, eax
  mov hPrevBrush, $invoke(SelectObject, hDC, xax)

  mov eax, [xsi].PlotRect.right
  mov edi, [xsi].PlotRect.bottom
  inc eax
  inc edi
  invoke Rectangle, hDC, [xsi].PlotRect.left, [xsi].PlotRect.top, eax, edi

  invoke DeleteObject, $invoke(SelectObject, hDC, hPrevBrush)
  invoke DeleteObject, $invoke(SelectObject, hDC, hPrevPen)
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     ChartWnd.DrawScaleX
; Purpose:    Draw the chart X-Scale.
; Arguments:  Arg1: Output device context.
; Return:     Nothing.

Method ChartWnd.DrawScaleX, uses xbx xdi xsi, hDC:HDC
  local dPrevBkMode:DWORD, hPrevFont:HFONT, hPrevPen:HPEN, dPrevAlign:DWORD, dPrevColor:DWORD
  local hDivPen:HPEN, hMjrGridPen:HPEN, hMnrGridPen:HPEN, PenBrush:LOGBRUSH, dTempEDI:DWORD
  local LastPoint:POINT, cBuffer[256]:CHR
  local dDivMjrEnd:DWORD, dDivMnrEnd:DWORD, dMjrCount:DWORD, dMnrCount:DWORD, sdPosition:SDWORD
  local r8TimeCurrent:REAL8, pTimeCurrent:POINTER
  local FpuContext:FPU_CONTEXT, LabelInfo[200]:CHT_LABEL_INFO, pCurLabelInfo:PCHT_LABEL_INFO

  SetObject xsi
  mov hPrevFont, $invoke(SelectObject, hDC, [xsi].hFontHorz)
  mov dPrevAlign, $32($invoke(GetTextAlign, hDC))
  mov dPrevBkMode, $32($invoke(SetBkMode, hDC, TRANSPARENT))
  mov hPrevPen, $invoke(GetCurrentObject, hDC, OBJ_PEN)

  ;Create the divisions pen
  .ifBitSet [xsi].dFlags, CHT_WND_COLOR
    mov ebx, [xsi].Colors.Scales
  .else
    mov ebx, $RGB(000,000,000)
  .endif
  mov dPrevColor, $32($invoke(SetTextColor, hDC, ebx))
  mov hDivPen, $invoke(CreatePen, PS_SOLID, 1, ebx)

  ;Create the grid pens
  .ifBitSet [xsi].dFlags, CHT_WND_COLOR
    mov eax, [xsi].Colors.MjrGrid
  .else
    mov eax, $RGB(000,000,000)
  .endif
  mov PenBrush.lbStyle, BS_SOLID
  mov PenBrush.lbColor, eax
  mov ecx, [xsi].ScaleX.dGridMjrLineStyle
  or ecx, PS_ENDCAP_FLAT or PS_GEOMETRIC
  invoke ExtCreatePen, ecx, [xsi].ScaleX.dGridMjrLineSize, addr PenBrush, 0, NULL
  mov hMjrGridPen, xax

  .ifBitSet [xsi].dFlags, CHT_WND_COLOR
    mov eax, [xsi].Colors.MnrGrid
  .else
    mov eax, $RGB(000,000,000)
  .endif
  mov PenBrush.lbStyle, BS_SOLID
  mov PenBrush.lbColor, eax
  mov ecx, [xsi].ScaleX.dGridMnrLineStyle
  or ecx, PS_ENDCAP_FLAT or PS_GEOMETRIC
  invoke ExtCreatePen, ecx, [xsi].ScaleX.dGridMnrLineSize, addr PenBrush, 0, NULL
  mov hMnrGridPen, xax

  ;Start drawing
  mov edx, [xsi].PlotRect.left
  .if SDWORD ptr edx < [xsi].PlotRect.right
    mov eax, [xsi].PlotRect.bottom
    mov ecx, eax
    add eax, [xsi].ScaleX.dDivMjrLen
    add ecx, [xsi].ScaleX.dDivMnrLen
    mov dDivMjrEnd, eax
    mov dDivMnrEnd, ecx

    fld [xsi].ScaleX.fScaleFactor
    fld [xsi].ScaleX.fDivMjrStp
    fild [xsi].ScaleX.dDivMnrCount
    fdivr st(0), st(1)                                  ;MnrStep = DivStep/MnrCount
    ;FPU Stack: MnrStep | MjrStep | ScaleFactor
    fld [xsi].ScaleX.fDivMjrFst
    fld [xsi].ScaleX.fScaleMin
    ;FPU Stack: ScaleMin | DivFirst | MnrStep | MjrStep | ScaleFactor
    lea xax, LabelInfo
    mov pCurLabelInfo, xax

    ;Draw divisions & grid
    xor edi, edi
    .repeat
      mov dMjrCount, edi
      fild dMjrCount
      ;FPU Stack: dMjrCount | ScaleMin | DivFirst | MnrStep | MjrStep | ScaleFactor
      fmul st(0), st(4)
      fadd st(0), st(2)
      mov xcx, pCurLabelInfo
      fst [xcx].CHT_LABEL_INFO.fValue
      fsub st(0), st(1)
      fmul st(0), st(5)
      ;FPU Stack: MjrDivPos | ScaleMin | DivFirst | MnrStep | MjrStep | ScaleFactor
      fist sdPosition
      mov eax, [xsi].PlotRect.left
      add eax, sdPosition
      mov [xcx].CHT_LABEL_INFO.sdPosition, eax          ;Store position onto stack
      add pCurLabelInfo, sizeof CHT_LABEL_INFO
      .break .if SDWORD ptr eax > [xsi].PlotRect.right
      mov sdPosition, eax

      ;Draw major division
      SaveFpuContext FpuContext
      invoke SelectObject, hDC, hDivPen
      .ifBitSet [xsi].ScaleX.dFlags, CHT_SCALE_SHOW_MJR_DIV
        invoke MoveToEx, hDC, sdPosition, [xsi].PlotRect.bottom, addr LastPoint
        invoke LineTo, hDC, sdPosition, dDivMjrEnd
      .else 
        .ifBitSet [xsi].ScaleX.dFlags, CHT_SCALE_SHOW_MNR_DIV
          invoke MoveToEx, hDC, sdPosition, [xsi].PlotRect.bottom, addr LastPoint
          invoke LineTo, hDC, sdPosition, dDivMnrEnd
        .endif 
      .endif

      ;Draw major grid lines
      .ifBitSet [xsi].ScaleX.dFlags, CHT_SCALE_SHOW_MJR_GRID
        mov ecx, sdPosition
        .if (SDWORD ptr ecx < [xsi].PlotRect.right) && (SDWORD ptr ecx > [xsi].PlotRect.left)
          invoke SelectObject, hDC, hMjrGridPen
          invoke MoveToEx, hDC, sdPosition, [xsi].PlotRect.bottom, addr LastPoint
          mov eax, [xsi].PlotRect.top
          inc eax
          invoke LineTo, hDC, sdPosition, eax
          invoke SelectObject, hDC, hDivPen
        .endif
      .endif
      LoadFpuContext FpuContext

      ;Draw minor divisions & grid
      mov dTempEDI, edi
      mov edi, 1
      .while edi < [xsi].ScaleX.dDivMnrCount
        mov dMnrCount, edi
        fild dMnrCount
        ;FPU Stack: dMnrCount | MjrDivPos | ScaleMin | DivFirst | MnrStep | MjrStep | ScaleFactor
        fmul st(0), st(4)
        fmul st(0), st(6)
        fadd st(0), st(1)
        ;FPU Stack: MnrDivPos | MjrDivPos | ScaleMin | DivFirst | MnrStep | MjrStep | ScaleFactor
        fistp sdPosition
        ;FPU Stack: MjrDivPos | ScaleMin | DivFirst | MnrStep | MjrStep | ScaleFactor
        mov eax, sdPosition
        add eax, [xsi].PlotRect.left
        .break .if SDWORD ptr eax > [xsi].PlotRect.right
        mov sdPosition, eax

        ;Draw major division
        SaveFpuContext FpuContext
        .ifBitSet [xsi].ScaleX.dFlags, CHT_SCALE_SHOW_MNR_DIV
          invoke SelectObject, hDC, hDivPen
          invoke MoveToEx, hDC, sdPosition, [xsi].PlotRect.bottom, addr LastPoint
          invoke LineTo, hDC, sdPosition, dDivMnrEnd
        .endif

        ;Draw minor grid lines
        .ifBitSet [xsi].ScaleX.dFlags, CHT_SCALE_SHOW_MNR_GRID
          mov ecx, sdPosition
          .if (SDWORD ptr ecx < [xsi].PlotRect.right) && (SDWORD ptr ecx > [xsi].PlotRect.left)
            mov ecx, sdPosition
            invoke SelectObject, hDC, hMnrGridPen
            invoke MoveToEx, hDC, sdPosition, [xsi].PlotRect.bottom, addr LastPoint
            mov eax, [xsi].PlotRect.top
            inc eax
            invoke LineTo, hDC, sdPosition, eax
            invoke SelectObject, hDC, hDivPen
          .endif
        .endif
        LoadFpuContext FpuContext
        inc edi
      .endw
      mov edi, dTempEDI
      fUnload 1                                         ;Unload FPU stack
      ;FPU Stack: ScaleMin | DivFirst | MnrStep | MjrStep | ScaleFactor
      inc edi
    .until FALSE
    sub pCurLabelInfo, 2*sizeof CHT_LABEL_INFO
    fUnload 1                                           ;Unload FPU stack

    ;Draw remaining minor divisions at the beginning of the X scale
    mov edi, 1
    .while edi < [xsi].ScaleX.dDivMnrCount
      mov dMnrCount, edi
      fild dMnrCount
      ;FPU Stack: dMnrCount | ScaleMin | DivFirst | MnrStep | MjrStep | ScaleFactor
      fmul st(0), st(3)
      fsubr st(0), st(2)
      fsub st(0), st(1)
      fmul st(0), st(5)
      fistp sdPosition
      mov eax, [xsi].PlotRect.left
      add eax, sdPosition
      .break .if SDWORD ptr eax < [xsi].PlotRect.left
      mov sdPosition, eax
      SaveFpuContext FpuContext
      invoke SelectObject, hDC, hDivPen
      invoke MoveToEx, hDC, sdPosition, [xsi].PlotRect.bottom, addr LastPoint
      invoke LineTo, hDC, sdPosition,dDivMnrEnd
      ;Draw remaining minor grid lines
      .ifBitSet [xsi].ScaleX.dFlags, CHT_SCALE_SHOW_MNR_GRID
        mov ecx, sdPosition
        .if (SDWORD ptr ecx < [xsi].PlotRect.right) && (SDWORD ptr ecx > [xsi].PlotRect.left)
          mov ecx, sdPosition
          invoke SelectObject, hDC, hMnrGridPen
          invoke MoveToEx, hDC, sdPosition, [xsi].PlotRect.bottom, addr LastPoint
          mov eax, [xsi].PlotRect.top
          inc eax
          invoke LineTo, hDC, sdPosition, eax
          invoke SelectObject, hDC, hDivPen
        .endif
      .endif
      LoadFpuContext FpuContext
      inc edi
    .endw

    fUnload 5                                           ;Unload FPU stack

    ;Draw X labels
    .ifBitSet [xsi].ScaleX.dFlags, CHT_SCALE_SHOW_LABEL
      invoke SetTextAlign, hDC, TA_TOP or TA_CENTER
      mov ebx, dDivMjrEnd
      sub ebx, [xsi].TextMetricHorz.tmInternalLeading
      add ebx, [xsi].ScaleX.dLabelSep
      .while TRUE
        lea xax, LabelInfo
        .break .if pCurLabelInfo < xax
        mov xdi, pCurLabelInfo
        m2m sdPosition, [xdi].CHT_LABEL_INFO.sdPosition, edx

        SaveFpuContext FpuContext
        fld [xdi].CHT_LABEL_INFO.fValue
        lea xdi, cBuffer
        .ifBitSet [xsi].ScaleX.dFlags, CHT_SCALE_SHOW_AS_DATE or CHT_SCALE_SHOW_AS_DATEDIFF or CHT_SCALE_SHOW_AS_TIME
          .ifBitSet [xsi].ScaleX.dFlags, CHT_SCALE_SHOW_AS_DATE or CHT_SCALE_SHOW_AS_DATEDIFF
            fld st(0)
            fInt
            .ifBitSet [xsi].ScaleX.dFlags, CHT_SCALE_SHOW_AS_DATEDIFF
              invoke St0ToStr, xdi, 0, 0, f_NOR
              invoke StrLength, xdi
              invoke TextOut, hDC, sdPosition, ebx, xdi, eax
            .else
              fst r8TimeCurrent
              invoke VarBstrFromDate, r8TimeCurrent, 0, \
                                      LOCALE_NOUSEROVERRIDE or VAR_DATEVALUEONLY or VAR_FOURDIGITYEARS, \
                                      addr pTimeCurrent
              .if eax == S_OK
                mov xax, pTimeCurrent
                .if CHRW ptr [xax] == 0
                  FillString [xdi], <30.12.1899>
                .else
                  if TARGET_STR_TYPE eq STR_TYPE_ANSI
                    invoke WideCharToMultiByte, CP_ACP, 0, pTimeCurrent, -1, \
                                                xdi, lengthof cBuffer, NULL, NULL
                  else
                    invoke StrCopyW, xdi, pTimeCurrent
                  endif
                .endif
                invoke SysFreeString, pTimeCurrent
              .else
                m2z CHR ptr [xdi]
              .endif

              invoke StrLength, xdi
              invoke TextOut, hDC, sdPosition, ebx, xdi, eax
            .endif
            fUnload
          .endif

          .ifBitSet [xsi].ScaleX.dFlags, CHT_SCALE_SHOW_AS_TIME
            fld st(0)
            fFrac
            fstp r8TimeCurrent
            invoke VarBstrFromDate, r8TimeCurrent, 0, \
                                    LOCALE_NOUSEROVERRIDE or VAR_TIMEVALUEONLY, \
                                    addr pTimeCurrent
            .if eax == S_OK
              if TARGET_STR_TYPE eq STR_TYPE_ANSI
                invoke WideCharToMultiByte, CP_ACP, 0, pTimeCurrent, -1, \
                                            xdi, lengthof cBuffer, NULL, NULL
              else
                invoke StrCopyW, xdi, pTimeCurrent
              endif
              invoke SysFreeString, pTimeCurrent
            .else
              m2z CHR ptr [xdi]
            .endif

            invoke StrLength, xdi
            .ifBitSet [xsi].ScaleX.dFlags, CHT_SCALE_SHOW_AS_DATE or CHT_SCALE_SHOW_AS_DATEDIFF
              add ebx, [xsi].TextMetricHorz.tmHeight
            .endif
            invoke TextOut, hDC, sdPosition, ebx, xdi, eax
            .ifBitSet [xsi].ScaleX.dFlags, CHT_SCALE_SHOW_AS_DATE or CHT_SCALE_SHOW_AS_DATEDIFF
              sub ebx, [xsi].TextMetricHorz.tmHeight
            .endif
          .endif
        .else
          invoke St0ToStr, xdi, 0, [xsi].ScaleX.dDecimals, f_NOR
          invoke StrLength, xdi
          invoke TextOut, hDC, sdPosition, ebx, xdi, eax
        .endif
        fUnload
        LoadFpuContext FpuContext

        sub pCurLabelInfo, sizeof CHT_LABEL_INFO
      .endw
    .endif
  .endif

  ;Delete allocated resources
  invoke DeleteObject, hMjrGridPen
  invoke DeleteObject, hMnrGridPen
  invoke DeleteObject, hDivPen

  ;Draw X scale title
  .ifBitSet [xsi].ScaleX.dFlags, CHT_SCALE_SHOW_TITLE
    SaveFpuContext FpuContext
    lea xbx, [xsi]
    invoke StrLength, [xsi].ScaleX.pTitle
    .if eax != 0
      mov edi, eax
      invoke SetTextAlign, hDC, TA_CENTER or TA_BOTTOM
      mov edx, [xsi].PlotRect.right
      add edx, [xsi].PlotRect.left
      shr edx, 1
      invoke TextOut, hDC, edx, [xsi].DrawRect.bottom, [xsi].ScaleX.pTitle, edi
    .endif
    LoadFpuContext FpuContext
  .endif

  ;Restore previous DC resources
  invoke SelectObject, hDC, hPrevPen
  invoke SelectObject, hDC, hPrevFont
  invoke SetTextAlign, hDC, dPrevAlign
  invoke SetTextColor, hDC, dPrevColor
  invoke SetBkMode, hDC, dPrevBkMode
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     ChartWnd.DrawScaleY1
; Purpose:    Draw the chart Y1-Axis.
; Arguments:  Arg1: Output device context.
; Return:     Nothing.

Method ChartWnd.DrawScaleY1, uses xbx xdi xsi, hDC:HDC
  local dPrevBkMode:DWORD, hPrevFont:HFONT, hPrevPen:HPEN, dPrevAlign:DWORD, dPrevColor:DWORD
  local hDivPen:HPEN, hMjrGridPen:HPEN, hMnrGridPen:HPEN, PenBrush:LOGBRUSH, dTempEDI:DWORD
  local dDivMjrEnd:DWORD, dDivMnrEnd:DWORD, dMjrCount:DWORD, dMnrCount:DWORD, sdPosition:SDWORD
  local FpuContext:FPU_CONTEXT, LabelInfo[200]:CHT_LABEL_INFO, pCurLabelInfo:PCHT_LABEL_INFO
  local LastPoint:POINT, cBuffer[256]:CHR

  SetObject xsi
  mov hPrevFont, $invoke(SelectObject, hDC, [xsi].hFontHorz)
  mov dPrevAlign, $32($invoke(GetTextAlign, hDC))
  mov dPrevBkMode, $32($invoke(SetBkMode, hDC, TRANSPARENT))
  mov hPrevPen, $invoke(GetCurrentObject, hDC, OBJ_PEN)

  ;Create the divisions pens
  .ifBitSet [xsi].dFlags, CHT_WND_COLOR
    mov ebx, [xsi].Colors.Scales
  .else
    mov ebx, $RGB(000,000,000)
  .endif
  mov dPrevColor, $32($invoke(SetTextColor, hDC, ebx))
  mov hDivPen, $invoke(CreatePen, PS_SOLID, 1, ebx)

  ;Create the grid pens
  .ifBitSet [xsi].dFlags, CHT_WND_COLOR
    mov eax, [xsi].Colors.MjrGrid
  .else
    mov eax, $RGB(000,000,000)
  .endif
  mov PenBrush.lbStyle, BS_SOLID
  mov PenBrush.lbColor, eax
  mov ecx, [xsi].ScaleY1.dGridMjrLineStyle
  or ecx, PS_ENDCAP_FLAT or PS_GEOMETRIC
  invoke ExtCreatePen, ecx, [xsi].ScaleY1.dGridMjrLineSize, addr PenBrush, 0, NULL
  mov hMjrGridPen, xax

  .ifBitSet [xsi].dFlags, CHT_WND_COLOR
    mov eax, [xsi].Colors.MnrGrid
  .else
    mov eax, $RGB(000,000,000)
  .endif
  mov PenBrush.lbStyle, BS_SOLID
  mov PenBrush.lbColor, eax
  mov ecx, [xsi].ScaleY1.dGridMnrLineStyle
  or ecx, PS_ENDCAP_FLAT or PS_GEOMETRIC
  invoke ExtCreatePen, ecx, [xsi].ScaleY1.dGridMnrLineSize, addr PenBrush, 0, NULL
  mov hMnrGridPen, xax

  ;Start drawing
  mov edx, [xsi].PlotRect.top
  .if SDWORD ptr edx < [xsi].PlotRect.bottom
    mov eax, [xsi].PlotRect.left
    mov ecx, eax
    sub eax, [xsi].ScaleY1.dDivMjrLen
    sub ecx, [xsi].ScaleY1.dDivMnrLen
    mov dDivMjrEnd, eax
    mov dDivMnrEnd, ecx

    fld [xsi].ScaleY1.fScaleFactor
    fld [xsi].ScaleY1.fDivMjrStp
    fild [xsi].ScaleY1.dDivMnrCount
    fdivr st(0), st(1)                                  ;MnrStep = DivStep/MnrCount
    ;FPU Stack: MnrStep | MjrStep | ScaleFactor
    fld [xsi].ScaleY1.fDivMjrFst
    fld [xsi].ScaleY1.fScaleMin
    ;FPU Stack: ScaleMin | DivFirst | MnrStep | MjrStep | ScaleFactor
    lea xax, LabelInfo
    mov pCurLabelInfo, xax
    xor edi, edi
    .repeat
      mov dMjrCount, edi
      fild dMjrCount
      ;FPU Stack: dMjrCount | ScaleMin | DivFirst | MnrStep | MjrStep | ScaleFactor
      fmul st(0), st(4)
      fadd st(0), st(2)
      mov xcx, pCurLabelInfo
      fst [xcx].CHT_LABEL_INFO.fValue
      fsub st(0), st(1)
      fmul st(0), st(5)
      ;FPU Stack: MjrDivPos | ScaleMin | DivFirst | MnrStep | MjrStep | ScaleFactor
      fist sdPosition
      mov eax, [xsi].PlotRect.bottom
      sub eax, sdPosition
      mov [xcx].CHT_LABEL_INFO.sdPosition, eax          ;Store position onto stack
      add pCurLabelInfo, sizeof CHT_LABEL_INFO
      .break .if SDWORD ptr eax < [xsi].PlotRect.top
      mov sdPosition, eax

      ;Draw major division
      SaveFpuContext FpuContext
      invoke SelectObject, hDC, hDivPen
      .ifBitSet [xsi].ScaleX.dFlags, CHT_SCALE_SHOW_MJR_DIV
        invoke MoveToEx, hDC, [xsi].PlotRect.left, sdPosition, addr LastPoint
        invoke LineTo, hDC, dDivMjrEnd, sdPosition
      .else
        .ifBitSet [xsi].ScaleY1.dFlags, CHT_SCALE_SHOW_MNR_DIV
          invoke MoveToEx, hDC, [xsi].PlotRect.left, sdPosition, addr LastPoint
          invoke LineTo, hDC, dDivMnrEnd, sdPosition
        .endif
      .endif

      ;Draw major grid lines
      .ifBitSet [xsi].ScaleY1.dFlags, CHT_SCALE_SHOW_MJR_GRID
        mov ecx, sdPosition
        .if (SDWORD ptr ecx < [xsi].PlotRect.bottom) && (SDWORD ptr ecx > [xsi].PlotRect.top)
          invoke SelectObject, hDC, hMjrGridPen
          mov edx, [xsi].PlotRect.left
          inc edx
          invoke MoveToEx, hDC, edx, sdPosition, addr LastPoint
          invoke LineTo, hDC, [xsi].PlotRect.right, sdPosition
          invoke SelectObject, hDC, hDivPen
        .endif
      .endif
      LoadFpuContext FpuContext

      ;Draw minor divisions
      .ifBitSet [xsi].ScaleY1.dFlags, CHT_SCALE_SHOW_MNR_DIV
        mov dTempEDI, edi
        mov edi, 1
        .while edi < [xsi].ScaleY1.dDivMnrCount
          mov dMnrCount, edi
          fild dMnrCount
          ;FPU Stack: dMnrCount | MjrDivPos | ScaleMin | DivFirst | MnrStep | MjrStep | ScaleFactor
          fmul st(0), st(4)
          fmul st(0), st(6)
          fadd st(0), st(1)
          ;FPU Stack: MnrDivPos | MjrDivPos | ScaleMin | DivFirst | MnrStep | MjrStep | ScaleFactor
          fistp sdPosition
          ;FPU Stack: MjrDivPos | ScaleMin | DivFirst | MnrStep | MjrStep | ScaleFactor
          mov eax, [xsi].PlotRect.bottom
          sub eax, sdPosition
          .break .if SDWORD ptr eax < [xsi].PlotRect.top
          mov sdPosition, eax
          SaveFpuContext FpuContext
          invoke SelectObject, hDC, hDivPen
          invoke MoveToEx, hDC, [xsi].PlotRect.left, sdPosition, addr LastPoint
          invoke LineTo, hDC, dDivMnrEnd, sdPosition
          ;Draw minor grid lines
          .ifBitSet [xsi].ScaleY1.dFlags, CHT_SCALE_SHOW_MNR_GRID
            mov ecx, sdPosition
            .if (SDWORD ptr ecx < [xsi].PlotRect.bottom) && (SDWORD ptr ecx > [xsi].PlotRect.top)
              invoke SelectObject, hDC, hMnrGridPen
              mov edx, [xsi].PlotRect.left
              inc edx
              invoke MoveToEx, hDC, edx, sdPosition, addr LastPoint
              invoke LineTo, hDC, [xsi].PlotRect.right, sdPosition
              invoke SelectObject, hDC, hDivPen
            .endif
          .endif
          LoadFpuContext FpuContext
          inc edi
        .endw
        mov edi, dTempEDI
      .endif
      fUnload 1                                         ;Unload FPU stack
      ;FPU Stack: ScaleMin | DivFirst | MnrStep | MjrStep | ScaleFactor
      inc edi
    .until FALSE
    sub pCurLabelInfo, 2*sizeof CHT_LABEL_INFO
    fUnload 1                                           ;Unload FPU stack

    ;Draw remaining minor divisions at the beginning of the Y scale
    .ifBitSet [xsi].ScaleY1.dFlags, CHT_SCALE_SHOW_MNR_DIV
      mov edi, 1
      .while edi < [xsi].ScaleY1.dDivMnrCount
        mov dMnrCount, edi
        fild dMnrCount
        ;FPU Stack: dMnrCount | ScaleMin | DivFirst | MnrStep | MjrStep | ScaleFactor
        fmul st(0), st(3)
        fsubr st(0), st(2)
        fsub st(0), st(1)
        fmul st(0), st(5)
        fistp sdPosition
        mov eax, [xsi].PlotRect.bottom
        sub eax, sdPosition
        mov sdPosition, eax
        dec eax
        .break .if SDWORD ptr eax >= [xsi].PlotRect.bottom
        SaveFpuContext FpuContext
        invoke SelectObject, hDC, hDivPen
        invoke MoveToEx, hDC, [xsi].PlotRect.left, sdPosition, addr LastPoint
        invoke LineTo, hDC, dDivMnrEnd, sdPosition
        ;Draw remaining minor grid lines
        .ifBitSet [xsi].ScaleY1.dFlags, CHT_SCALE_SHOW_MNR_GRID
          mov ecx, sdPosition
          .if (SDWORD ptr ecx < [xsi].PlotRect.bottom) && (SDWORD ptr ecx > [xsi].PlotRect.top)
            invoke SelectObject, hDC, hMnrGridPen
            mov edx, [xsi].PlotRect.left
            inc edx
            invoke MoveToEx, hDC, edx, sdPosition, addr LastPoint
            invoke LineTo, hDC, [xsi].PlotRect.right, sdPosition
            invoke SelectObject, hDC, hDivPen
          .endif
        .endif
        LoadFpuContext FpuContext
        inc edi
      .endw
    .endif

    fUnload 5                                           ;Unload FPU stack

    ;Draw Y labels ----------------------------------------------------
    .ifBitSet [xsi].ScaleY1.dFlags, CHT_SCALE_SHOW_LABEL
      invoke SetTextAlign, hDC, TA_TOP or TA_RIGHT
      mov eax, [xsi].ScaleY1.dLabelSep
      sub dDivMjrEnd, eax
      .while TRUE
        lea xax, LabelInfo
        .break .if pCurLabelInfo < xax
        mov xdi, pCurLabelInfo
        fld [xdi].CHT_LABEL_INFO.fValue
        invoke St0ToStr, addr cBuffer, 0, [xsi].ScaleY1.dDecimals, f_NOR; or f_TRIM
        fUnload
        invoke StrLength, addr cBuffer
        mov ecx, [xsi].TextMetricHorz.tmAscent
        add ecx, [xsi].TextMetricHorz.tmInternalLeading
        shr ecx, 1
        mov ebx, [xdi].CHT_LABEL_INFO.sdPosition
        sub ebx, ecx
        invoke TextOut, hDC, dDivMjrEnd, ebx, addr cBuffer, eax
        sub pCurLabelInfo, sizeof CHT_LABEL_INFO
      .endw
    .endif
  .endif

  ;Delete allocated resources
  invoke DeleteObject, hMjrGridPen
  invoke DeleteObject, hMnrGridPen
  invoke DeleteObject, hDivPen

  ;Draw Y scale title -----------------------------------------------
  .ifBitSet [xsi].ScaleY1.dFlags, CHT_SCALE_SHOW_TITLE
    .if [xsi].ScaleY1.pTitle != NULL
      invoke StrLength, [xsi].ScaleY1.pTitle
      .if eax != 0
        mov edi, eax
        invoke SelectObject, hDC, [xsi].hFontVert
        invoke SetTextAlign, hDC, TA_CENTER or TA_TOP
        mov eax, [xsi].PlotRect.bottom
        add eax, [xsi].PlotRect.top
        shr eax, 1
        invoke TextOut, hDC, [xsi].DrawRect.left, eax, [xsi].ScaleY1.pTitle, edi
      .endif
    .endif
  .endif

  ;Restore previous DC resources
  invoke SelectObject, hDC, hPrevPen
  invoke SelectObject, hDC, hPrevFont
  invoke SetTextAlign, hDC, dPrevAlign
  invoke SetTextColor, hDC, dPrevColor
  invoke SetBkMode, hDC, dPrevBkMode
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     ChartWnd.DrawScaleY2
; Purpose:    Draw the chart Y2-Axis.
; Arguments:  Arg1: Output device context.
; Return:     Nothing.

Method ChartWnd.DrawScaleY2, uses xbx xdi xsi, hDC:HDC
  local dPrevBkMode:DWORD, hPrevFont:HFONT, hPrevPen:HPEN, dPrevAlign:DWORD, dPrevColor:DWORD
  local hDivPen:HPEN, hMjrGridPen:HPEN, hMnrGridPen:HPEN, PenBrush:LOGBRUSH, dTempEDI:DWORD
  local dDivMjrEnd:DWORD, dDivMnrEnd:DWORD, dMjrCount:DWORD, dMnrCount:DWORD, sdPosition:SDWORD
  local FpuContext:FPU_CONTEXT, LabelInfo[200]:CHT_LABEL_INFO, pCurLabelInfo:PCHT_LABEL_INFO
  local LastPoint:POINT, cBuffer[256]:CHR

  SetObject xsi
  mov hPrevFont, $invoke(SelectObject, hDC, [xsi].hFontHorz)
  mov dPrevAlign, $32($invoke(GetTextAlign, hDC))
  mov dPrevBkMode, $32($invoke(SetBkMode, hDC, TRANSPARENT))
  mov hPrevPen, $invoke(GetCurrentObject, hDC, OBJ_PEN)

  ;Create the divisions pens
  .ifBitSet [xsi].dFlags, CHT_WND_COLOR
    mov ebx, [xsi].Colors.Scales
  .else
    mov ebx, $RGB(000,000,000)
  .endif
  mov dPrevColor, $32($invoke(SetTextColor, hDC, ebx))
  mov hDivPen, $invoke(CreatePen, PS_SOLID, 1, ebx)

  ;Create the grid pens
  .ifBitSet [xsi].dFlags, CHT_WND_COLOR
    mov eax, [xsi].Colors.MjrGrid
  .else
    mov eax, $RGB(000,000,000)
  .endif
  mov PenBrush.lbStyle, BS_SOLID
  mov PenBrush.lbColor, eax
  mov ecx, [xsi].ScaleY2.dGridMjrLineStyle
  or ecx, PS_ENDCAP_FLAT or PS_GEOMETRIC
  invoke ExtCreatePen, ecx, [xsi].ScaleY2.dGridMjrLineSize, addr PenBrush, 0, NULL
  mov hMjrGridPen, xax

  .ifBitSet [xsi].dFlags, CHT_WND_COLOR
    mov eax, [xsi].Colors.MnrGrid
  .else
    mov eax, $RGB(000,000,000)
  .endif
  mov PenBrush.lbStyle, BS_SOLID
  mov PenBrush.lbColor, eax
  mov ecx, [xsi].ScaleY2.dGridMnrLineStyle
  or ecx, PS_ENDCAP_FLAT or PS_GEOMETRIC
  invoke ExtCreatePen, ecx, [xsi].ScaleY2.dGridMnrLineSize, addr PenBrush, 0, NULL
  mov hMnrGridPen, xax

  ;Start drawing
  mov edx, [xsi].PlotRect.top
  .if SDWORD ptr edx < [xsi].PlotRect.bottom
    mov eax, [xsi].PlotRect.right
    mov ecx, eax
    add eax, [xsi].ScaleY2.dDivMjrLen
    add ecx, [xsi].ScaleY2.dDivMnrLen
    mov dDivMjrEnd, eax
    mov dDivMnrEnd, ecx

    fld [xsi].ScaleY2.fScaleFactor
    fld [xsi].ScaleY2.fDivMjrStp
    fild [xsi].ScaleY2.dDivMnrCount
    fdivr st(0), st(1)                                  ;MnrStep = DivStep/MnrCount
    ;FPU Stack: MnrStep | MjrStep | ScaleFactor
    fld [xsi].ScaleY2.fDivMjrFst
    fld [xsi].ScaleY2.fScaleMin
    ;FPU Stack: ScaleMin | DivFirst | MnrStep | MjrStep | ScaleFactor
    lea xax, LabelInfo
    mov pCurLabelInfo, xax
    xor edi, edi
    .repeat
      mov dMjrCount, edi
      fild dMjrCount
      ;FPU Stack: dMjrCount | ScaleMin | DivFirst | MnrStep | MjrStep | ScaleFactor
      fmul st(0), st(4)
      fadd st(0), st(2)
      mov xcx, pCurLabelInfo
      fst [xcx].CHT_LABEL_INFO.fValue
      fsub st(0), st(1)
      fmul st(0), st(5)
      ;FPU Stack: MjrDivPos | ScaleMin | DivFirst | MnrStep | MjrStep | ScaleFactor
      fist sdPosition
      mov eax, [xsi].PlotRect.bottom
      sub eax, sdPosition
      mov [xcx].CHT_LABEL_INFO.sdPosition, eax          ;Store position onto stack
      add pCurLabelInfo, sizeof CHT_LABEL_INFO
      .break .if SDWORD ptr eax < [xsi].PlotRect.top
      mov sdPosition, eax

      ;Draw major division
      SaveFpuContext FpuContext
      invoke SelectObject, hDC, hDivPen
      .ifBitSet [xsi].ScaleX.dFlags, CHT_SCALE_SHOW_MJR_DIV
        invoke MoveToEx, hDC, [xsi].PlotRect.right, sdPosition, addr LastPoint
        invoke LineTo, hDC, dDivMjrEnd, sdPosition
      .else
        .ifBitSet [xsi].ScaleY2.dFlags, CHT_SCALE_SHOW_MNR_DIV
          invoke MoveToEx, hDC, [xsi].PlotRect.right, sdPosition, addr LastPoint
          invoke LineTo, hDC, dDivMnrEnd, sdPosition
        .endif
      .endif

      ;Draw major grid lines
      .ifBitSet [xsi].ScaleY2.dFlags, CHT_SCALE_SHOW_MJR_GRID
        mov ecx, sdPosition
        .if (SDWORD ptr ecx < [xsi].PlotRect.bottom) && (SDWORD ptr ecx > [xsi].PlotRect.top)
          invoke SelectObject, hDC, hMjrGridPen
          mov edx, [xsi].PlotRect.left
          inc edx
          invoke MoveToEx, hDC, edx, sdPosition, addr LastPoint
          invoke LineTo, hDC, [xsi].PlotRect.right, sdPosition
          invoke SelectObject, hDC, hDivPen
        .endif
      .endif
      LoadFpuContext FpuContext

      ;Draw minor divisions
      .ifBitSet [xsi].ScaleY2.dFlags, CHT_SCALE_SHOW_MNR_DIV
        mov dTempEDI, edi
        mov edi, 1
        .while edi < [xsi].ScaleY2.dDivMnrCount
          mov dMnrCount, edi
          fild dMnrCount
          ;FPU Stack: dMnrCount | MjrDivPos | ScaleMin | DivFirst | MnrStep | MjrStep | ScaleFactor
          fmul st(0), st(4)
          fmul st(0), st(6)
          fadd st(0), st(1)
          ;FPU Stack: MnrDivPos | MjrDivPos | ScaleMin | DivFirst | MnrStep | MjrStep | ScaleFactor
          fistp sdPosition
          ;FPU Stack: MjrDivPos | ScaleMin | DivFirst | MnrStep | MjrStep | ScaleFactor
          mov eax, [xsi].PlotRect.bottom
          sub eax, sdPosition
          .break .if SDWORD ptr eax < [xsi].PlotRect.top
          mov sdPosition, eax
          SaveFpuContext FpuContext
          invoke SelectObject, hDC, hDivPen
          invoke MoveToEx, hDC, [xsi].PlotRect.right, sdPosition, addr LastPoint
          invoke LineTo, hDC, dDivMnrEnd, sdPosition
          ;Draw minor grid lines
          .ifBitSet [xsi].ScaleY2.dFlags, CHT_SCALE_SHOW_MNR_GRID
            mov ecx, sdPosition
            .if (SDWORD ptr ecx < [xsi].PlotRect.bottom) && (SDWORD ptr ecx > [xsi].PlotRect.top)
              invoke SelectObject, hDC, hMnrGridPen
              mov edx, [xsi].PlotRect.left
              inc edx
              invoke MoveToEx, hDC, edx, sdPosition, addr LastPoint
              invoke LineTo, hDC, [xsi].PlotRect.right, sdPosition
              invoke SelectObject, hDC, hDivPen
            .endif
          .endif
          LoadFpuContext FpuContext
          inc edi
        .endw
        mov edi, dTempEDI
      .endif
      fUnload 1                                         ;Unload FPU stack
      ;FPU Stack: ScaleMin | DivFirst | MnrStep | MjrStep | ScaleFactor
      inc edi
    .until FALSE
    sub pCurLabelInfo, 2*sizeof CHT_LABEL_INFO
    fUnload 1                                           ;Unload FPU stack

    ;Draw remaining minor divisions at the beginning of the Y scale
    .ifBitSet [xsi].ScaleY2.dFlags, CHT_SCALE_SHOW_MNR_DIV
      mov edi, 1
      .while edi < [xsi].ScaleY2.dDivMnrCount
        mov dMnrCount, edi
        fild dMnrCount
        ;FPU Stack: dMnrCount | ScaleMin | DivFirst | MnrStep | MjrStep | ScaleFactor
        fmul st(0), st(3)
        fsubr st(0), st(2)
        fsub st(0), st(1)
        fmul st(0), st(5)
        fistp sdPosition
        mov eax, [xsi].PlotRect.bottom
        sub eax, sdPosition
        mov sdPosition, eax
        dec eax
        .break .if SDWORD ptr eax >= [xsi].PlotRect.bottom
        SaveFpuContext FpuContext
        invoke SelectObject, hDC, hDivPen
        invoke MoveToEx, hDC, [xsi].PlotRect.right, sdPosition, addr LastPoint
        invoke LineTo, hDC, dDivMnrEnd, sdPosition
        ;Draw remaining minor grid lines
        .ifBitSet [xsi].ScaleY2.dFlags, CHT_SCALE_SHOW_MNR_GRID
          mov ecx, sdPosition
          .if (SDWORD ptr ecx < [xsi].PlotRect.bottom) && (SDWORD ptr ecx > [xsi].PlotRect.top)
            invoke SelectObject, hDC, hMnrGridPen
            mov edx, [xsi].PlotRect.left
            inc edx
            invoke MoveToEx, hDC, edx, sdPosition, addr LastPoint
            invoke LineTo, hDC, [xsi].PlotRect.left, sdPosition
            invoke SelectObject, hDC, hDivPen
          .endif
        .endif
        LoadFpuContext FpuContext
        inc edi
      .endw
    .endif

    fUnload 5                                           ;Unload FPU stack

    ;Draw Y labels ----------------------------------------------------
    .ifBitSet [xsi].ScaleY2.dFlags, CHT_SCALE_SHOW_LABEL
      invoke SetTextAlign, hDC, TA_TOP or TA_LEFT
      mov eax, [xsi].ScaleY2.dLabelSep
      add dDivMjrEnd, eax
      .while TRUE
        lea xax, LabelInfo
        .break .if pCurLabelInfo < xax
        mov xdi, pCurLabelInfo
        fld [xdi].CHT_LABEL_INFO.fValue
        invoke St0ToStr, addr cBuffer, 0, [xsi].ScaleY2.dDecimals, f_NOR; or f_TRIM
        fUnload
        invoke StrLength, addr cBuffer
        mov ecx, [xsi].TextMetricHorz.tmAscent
        add ecx, [xsi].TextMetricHorz.tmInternalLeading
        shr ecx, 1
        mov ebx, [xdi].CHT_LABEL_INFO.sdPosition
        sub ebx, ecx
        invoke TextOut, hDC, dDivMjrEnd, ebx, addr cBuffer, eax
        sub pCurLabelInfo, sizeof CHT_LABEL_INFO
      .endw
    .endif
  .endif

  ;Delete allocated resources
  invoke DeleteObject, hMjrGridPen
  invoke DeleteObject, hMnrGridPen
  invoke DeleteObject, hDivPen

  ;Draw Y scale title -----------------------------------------------
  .ifBitSet [xsi].ScaleY2.dFlags, CHT_SCALE_SHOW_TITLE
    .if [xsi].ScaleY2.pTitle != NULL
      invoke StrLength, [xsi].ScaleY2.pTitle
      .if eax != 0
        mov edi, eax
        invoke SelectObject, hDC, [xsi].hFontVert
        invoke SetTextAlign, hDC, TA_CENTER or TA_BOTTOM
        mov eax, [xsi].PlotRect.bottom
        add eax, [xsi].PlotRect.top
        shr eax, 1
        invoke TextOut, hDC, [xsi].DrawRect.right, eax, [xsi].ScaleY2.pTitle, edi
      .endif
    .endif
  .endif

  ;Restore previous DC resources
  invoke SelectObject, hDC, hPrevPen
  invoke SelectObject, hDC, hPrevFont
  invoke SetTextAlign, hDC, dPrevAlign
  invoke SetTextColor, hDC, dPrevColor
  invoke SetBkMode, hDC, dPrevBkMode
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     ChartWnd.Init
; Purpose:    Initialize the ChartWnd object.
; Arguments:  Arg1: -> Owner object.
;             Arg2: Parent Window handle.
;             Arg3: -> Window initialization Data.
; Return:     Nothing.

Method ChartWnd.Init, uses xbx xsi, pOwner:POINTER, hParent:HWND, pDefStruc:PDEF_CHART
  ;DbgText "ChartBarWnd.Init"
  SetObject xsi
  OCall [xsi].Data::Collection.Init, xsi, 10, 10, COL_MAX_CAPACITY
  OCall [xsi].InfoAreas::DataCollection.Init, xsi, 100, 100, COL_MAX_CAPACITY     ;§§§
  mov xbx, pDefStruc
  assume xbx:PDEF_CHART
  mov eax, [xbx].dStyle
  or eax, WS_CHILD or WS_VISIBLE

  invoke CreateWindowEx, [xbx].dExStyle, offset(szChart), NULL, \
                         eax, [xbx].sdPosX, [xbx].sdPosY, [xbx].dWidth, [xbx].dHeight, \
                         hParent, [xbx].xCtlID, hInstance, xsi
  assume xbx:NOTHING
  ACall xsi.Init, pOwner, xax
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     ChartWnd.Load
; Purpose:    Load buffer data from a stream object.
; Arguments:  Arg1: -> Stream object.
; Return:     Nothing.

Method ChartWnd.Load, uses xsi, pStream:$ObjPtr(Stream), pDeserInfo:PDESER_INFO
  SetObject xsi
  ACall xsi.Load, pStream, pDeserInfo
  mov [xsi].dFlags, $32($OCall(pStream::Stream.BinRead32))
  OCall pStream::Stream.BinRead, addr [xsi].ScaleX,   sizeof(CHT_SCALE_DATA)
  OCall pStream::Stream.BinRead, addr [xsi].ScaleY1,  sizeof(CHT_SCALE_DATA)
  OCall pStream::Stream.BinRead, addr [xsi].ScaleY2,  sizeof(CHT_SCALE_DATA)
  OCall pStream::Stream.BinRead, addr [xsi].Colors,   sizeof(CHT_COLOR_CONFIG)
  OCall pStream::Stream.BinRead, addr [xsi].ViewRect, sizeof(RECT)
  OCall pStream::Stream.BinRead, addr [xsi].Padding,  sizeof(RECT)
  OCall pStream::Stream.BinRead, addr [xsi].DrawRect, sizeof(RECT)
  OCall pStream::Stream.BinRead, addr [xsi].PlotRect, sizeof(RECT)
  OCall pStream::Stream.BinRead, addr [xsi].TextMetricHorz,  sizeof(TEXTMETRIC)
  OCall pStream::Stream.BinRead, addr [xsi].TextMetricVert,  sizeof(TEXTMETRIC)
  mov [xsi].sbButtonDownOn, $8($OCall(pStream::Stream.BinRead8))
  OCall pStream::Stream.BinRead, addr [xsi].LastCursorPos,  sizeof(POINT)
  mov [xsi].dGestureZoomFirst, $32($OCall(pStream::Stream.BinRead32))
  mov [xsi].dGestureZoomLast, $32($OCall(pStream::Stream.BinRead32))
  OCall [xsi].Data::Collection.Load, pStream, pDeserInfo
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     ChartWnd.OnButtonDblClk
; Purpose:    Event procedure for WM_LBUTTONDBLCLK and WM_RBUTTONDBLCLK messages.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method ChartWnd.OnButtonDblClk, uses xbx xdi xsi, wParam:WPARAM, lParam:LPARAM
  local DblClkPnt:POINT, PopupPnt:POINT

  SetObject xsi
  PntS2Pnt DblClkPnt, lParam
  mrm PopupPnt.x, DblClkPnt.x, ebx
  mrm PopupPnt.y, DblClkPnt.y, edi
  mov eax, -1

  .ifBitSet [xsi].dFlags, CHT_WND_CTRL_DBLCLK
    .ifBitSet wParam, MK_CONTROL
      .ifBitSet wParam, MK_SHIFT
        ;Check if X scale was double-clicked
        .if [xsi].sbPrvButtonDownOn == CHT_ID_SCALEX
          BitClr [xsi].ScaleX.dFlags, (CHT_SCALE_AUTO_MIN or CHT_SCALE_AUTO_MAX)
          s2s [xsi].ScaleX.fSetupMin, [xsi].ScaleX.fInitMin, xax, xcx
          s2s [xsi].ScaleX.fSetupMax, [xsi].ScaleX.fInitMax, xax, xcx
          OCall xsi.Refresh
        ;Check if an Y scale was double-clicked
        .elseif [xsi].sbPrvButtonDownOn == CHT_ID_SCALEY1
          BitClr [xsi].ScaleY1.dFlags, (CHT_SCALE_AUTO_MIN or CHT_SCALE_AUTO_MAX)
          s2s [xsi].ScaleY1.fSetupMin, [xsi].ScaleY1.fInitMin, xax, xcx
          s2s [xsi].ScaleY1.fSetupMax, [xsi].ScaleY1.fInitMax, xax, xcx
          OCall xsi.Refresh
        .elseif [xsi].sbPrvButtonDownOn == CHT_ID_SCALEY2
          BitClr [xsi].ScaleY2.dFlags, (CHT_SCALE_AUTO_MIN or CHT_SCALE_AUTO_MAX)
          s2s [xsi].ScaleY2.fSetupMin, [xsi].ScaleY2.fInitMin, xax, xcx
          s2s [xsi].ScaleY2.fSetupMax, [xsi].ScaleY2.fInitMax, xax, xcx
          OCall xsi.Refresh
        .endif
        xor eax, eax
        ExitMethod
      .endif
      ;Check if X scale was double-clicked
      .if [xsi].sbPrvButtonDownOn == CHT_ID_SCALEX
        BitSet [xsi].ScaleX.dFlags, (CHT_SCALE_AUTO_MIN or CHT_SCALE_AUTO_MAX)
        OCall xsi.Refresh
      ;Check if an Y scale was double-clicked
      .elseif [xsi].sbPrvButtonDownOn == CHT_ID_SCALEY1
        BitSet [xsi].ScaleY1.dFlags, (CHT_SCALE_AUTO_MIN or CHT_SCALE_AUTO_MAX)
        OCall xsi.Refresh
      .elseif [xsi].sbPrvButtonDownOn == CHT_ID_SCALEY2
        BitSet [xsi].ScaleY2.dFlags, (CHT_SCALE_AUTO_MIN or CHT_SCALE_AUTO_MAX)
        OCall xsi.Refresh
      .endif
      xor eax, eax
      ExitMethod
    .endif
  .endif

ifdef INCLUDE_CHART_SETUP_DIALOG
  ;Get doubleclick client coordinates
  add PopupPnt.x, 10                                   ;Place the Dialog 10 px at the right
  add PopupPnt.y, 20                                   ;Place the Dialog 20 px below

  invoke ClientToScreen, [xsi].hWnd, addr PopupPnt     ;Transform to screen coordiantes
  ;Check if X scale was double clicked
  .if [xsi].sbPrvButtonDownOn == CHT_ID_SCALEX
    .ifBitSet [xsi].ScaleX.dFlags, CHT_SCALE_SHOW_TAB
      OCall xsi.ShowSetupDlg, PopupPnt.x, PopupPnt.y, CHT_ID_SCALEX
    .endif
  ;Check if Y1 scale was double clicked
  .elseif [xsi].sbPrvButtonDownOn == CHT_ID_SCALEY1
    .ifBitSet [xsi].ScaleX.dFlags, CHT_SCALE_SHOW_TAB
      OCall xsi.ShowSetupDlg, PopupPnt.x, PopupPnt.y, CHT_ID_SCALEY1
    .endif
  ;Check if Y2 scale was double clicked
  .elseif [xsi].sbPrvButtonDownOn == CHT_ID_SCALEY2
    .ifBitSet [xsi].ScaleX.dFlags, CHT_SCALE_SHOW_TAB
      OCall xsi.ShowSetupDlg, PopupPnt.x, PopupPnt.y, CHT_ID_SCALEY2
    .endif
  .else
    ;Check if a series was clicked
    DbgDec [xsi].InfoAreas.dCount
    xor ebx, ebx
    .while ebx != [xsi].InfoAreas.dCount
      mov xdi, $OCall([xsi].InfoAreas::DataCollection.ItemAt, ebx)
      invoke PtInRect, addr [xdi].ChartInfoArea.Rect, DblClkPnt
      .if eax != FALSE
        mov xdx, [xdi].ChartInfoArea.pSeries
        .ifBitSet [xdx].$Obj(ChartSeries).dFlags, CHT_SERIES_SHOW_TAB
          OCall [xsi].Data::Collection.IndexOf, xdx
          ;eax is the same index on ChartSetup.TabSeriesColl
          OCall xsi.ShowSetupDlg, PopupPnt.x, PopupPnt.y, eax
          .break
        .endif
      .endif
      inc ebx
    .endw
    .if ebx == [xsi].InfoAreas.dCount
      .ifBitSet [xsi].dFlags, CHT_WND_SHOW_GENERAL_TAB
        ;Launch the general tab on the setup dialog
        OCall xsi.ShowSetupDlg, PopupPnt.x, PopupPnt.y, CHT_ID_PLOT
      .endif
    .endif
  .endif
endif
  xor eax, eax
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     ChartWnd.OnButtonDown
; Purpose:    Event procedure for WM_LBUTTONDOWN and WM_RBUTTONDOWN messages.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method ChartWnd.OnButtonDown, uses xsi, wParam:WPARAM, lParam:LPARAM
  ;DbgText "ChartWnd.OnButtonDown"
  SetObject xsi
  PntS2Regs lParam
  mov [xsi].LastCursorPos.x, eax
  mov [xsi].LastCursorPos.y, ecx

  ;Check if X scale was clicked
  .if (SDWORD ptr eax >= [xsi].PlotRect.left) && (SDWORD ptr eax < [xsi].PlotRect.right) && \
    (SDWORD ptr ecx >= [xsi].PlotRect.bottom) && (SDWORD ptr ecx < [xsi].ViewRect.bottom)
    mov [xsi].sbButtonDownOn, CHT_ID_SCALEX
    invoke SetCapture, [xsi].hWnd
  ;Check if Y1 scale was clicked
  .elseif (SDWORD ptr eax >= [xsi].ViewRect.left) && (SDWORD ptr eax < [xsi].PlotRect.left) && \
    (SDWORD ptr ecx >= [xsi].ViewRect.top) && (SDWORD ptr ecx < [xsi].PlotRect.bottom)
    mov [xsi].sbButtonDownOn, CHT_ID_SCALEY1
    invoke SetCapture, [xsi].hWnd
  ;Check if Y2 scale was clicked
  .elseif (SDWORD ptr eax < [xsi].ViewRect.right) && (SDWORD ptr eax >= [xsi].PlotRect.right) && \
    (SDWORD ptr ecx >= [xsi].ViewRect.top) && (SDWORD ptr ecx <= [xsi].PlotRect.bottom)
    mov [xsi].sbButtonDownOn, CHT_ID_SCALEY2
    invoke SetCapture, [xsi].hWnd
  ;Check if plot area was clicked
  .elseif (SDWORD ptr eax >= [xsi].PlotRect.left) && (SDWORD ptr eax < [xsi].PlotRect.right) && \
    (SDWORD ptr ecx >= [xsi].PlotRect.top) && (SDWORD ptr ecx <= [xsi].PlotRect.bottom)
    mov [xsi].sbButtonDownOn, CHT_ID_PLOT
    invoke SetCapture, [xsi].hWnd
  .else
    ;It was clicked somewhere else
    mov [xsi].sbButtonDownOn, CHT_ID_NONE
  .endif
  xor eax, eax
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     ChartWnd.OnButtonUp
; Purpose:    Event procedure for WM_LBUTTONUP and WM_RBUTTONUP messages.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method ChartWnd.OnButtonUp,, wParam:WPARAM, lParam:LPARAM
  ;DbgText "ChartWnd.OnLButtonUp"
  SetObject xcx

  .ifBitClr wParam, MK_LBUTTON
    .ifBitClr wParam, MK_RBUTTON
      m2m [xcx].sbPrvButtonDownOn, [xcx].sbButtonDownOn, eax
      mov [xcx].sbButtonDownOn, CHT_ID_NONE
      invoke ReleaseCapture
    .endif
  .endif
  xor eax, eax
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     ChartWnd.OnCreate
; Purpose:    Event procedure for WM_CREATE message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero to continue creation of the window, else -1.

Method ChartWnd.OnCreate, uses xsi, wParam:WPARAM, lParam:LPARAM
  local LogFnt:LOGFONT, hDC:HDC, hPrevFont:HFONT, ToolInfo:TOOLINFO

  ;DbgText "ChartWnd.OnCreate"
  SetObject xsi

  ;Create a ToolTip window to display popup information when hoovering over an ChartInfoArea
  invoke CreateWindowEx, WS_EX_TOPMOST, $OfsCStr("tooltips_class32"), NULL, \
                         WS_POPUP or TTS_NOPREFIX or TTS_ALWAYSTIP or TTS_BALLOON, \
                         CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, \
                         [xsi].hWnd, 0, hInstance, NULL
  mov [xsi].hToolTip, xax
  invoke SendMessage, [xsi].hToolTip, TTM_ACTIVATE, FALSE, 0
  BitClr [xsi].dFlags, CHT_WND_TOOLTIP_ACTIVE
  invoke SetWindowPos, [xsi].hToolTip, HWND_TOPMOST, 0, 0, 0, 0, \
                       SWP_NOMOVE or SWP_NOSIZE or SWP_NOACTIVATE
  invoke SendMessage, [xsi].hToolTip, TTM_SETMAXTIPWIDTH, 0, 500    ;Set max width to
                                                                    ;enable line breaks
  mov ToolInfo.cbSize, sizeof(ToolInfo)
  mov ToolInfo.uFlags, TTF_SUBCLASS or TTF_IDISHWND
  mrm ToolInfo.hwnd, [xsi].hWnd, xax
  mov ToolInfo.uId, xax
  mov ToolInfo.hinst, 0
  mov ToolInfo.lpszText, NULL
  mov ToolInfo.lParam, 0
  invoke SendMessage, [xsi].hToolTip, TTM_ADDTOOL, 0, addr ToolInfo ;Associate the tooltip

  FillString LogFnt.lfFaceName, <Segoe UI>
  mov hDC, $invoke(GetDC, [xsi].hWnd)
  invoke GetDeviceCaps, hDC, LOGPIXELSY
  invoke MulDiv, 9, eax, -72
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
  mov hPrevFont, $invoke(SelectObject, hDC, xax)
  invoke GetTextMetrics, hDC, addr [xsi].TextMetricHorz

  mov LogFnt.lfEscapement, 900
  mov [xsi].hFontVert, $invoke(CreateFontIndirect, addr LogFnt)
  invoke SelectObject, hDC, xax
  invoke GetTextMetrics, hDC, addr [xsi].TextMetricVert

  invoke SelectObject, hDC, hPrevFont
  invoke ReleaseDC, [xsi].hWnd, hDC
  xor eax, eax
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     ChartWnd.OnGesture
; Purpose:    Event procedure for WM_GESTURE message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter. lParam = info HANDLE identifying the gesture command
; Return:     eax = Zero if handled.
; Link:       https://docs.microsoft.com/en-us/windows/win32/wintouch/improving-the-single-finger-panning-experience

Method ChartWnd.OnGesture, uses xsi, wParam:WPARAM, lParam:LPARAM
  local GestInfo:GESTUREINFO, bResult:BOOL, bHandled:BOOL, sdValue:SDWORD
;  local Pnt1:POINT, bHasChanged:BOOL, dError:DWORD

  ;DbgText "ChartWnd.OnGesture"
  SetObject xsi

  ;Populate and retrieve the extra message info.
  invoke MemZero, addr GestInfo, sizeof GestInfo
  mov GestInfo.cbSize, sizeof GestInfo
  mov bResult, $32($invoke(GetGestureInfo, lParam, addr GestInfo))
  mov bHandled, FALSE

  .if bResult != FALSE
    ;Now interpret the gesture
    .if GestInfo.dwID == GID_ZOOM

      .ifBitSet [xsi].dFlags, CHT_WND_ZOOMABLE
        .ifBitSet GestInfo.dwFlags, GF_BEGIN
          mov eax, DWORD ptr GestInfo.ullArguments
          mov [xsi].dGestureZoomFirst, eax
          mov [xsi].dGestureZoomLast, eax
        .else
          invoke GetKeyState, VK_SHIFT
          mov ecx, DWORD ptr GestInfo.ullArguments
          .ifBitSet eax, BIT15
            .if ecx != [xsi].dGestureZoomLast             ;Take an action if the value has changed
              BitClr [xsi].ScaleX.dFlags, (CHT_SCALE_AUTO_MIN or CHT_SCALE_AUTO_MAX)

              mov [xsi].dGestureZoomLast, ecx             ;Remember the last value
              mov eax, ecx
              sub eax, [xsi].dGestureZoomFirst
              mov [xsi].dGestureZoomFirst, ecx
              mov sdValue, eax

              fld [xsi].ScaleX.fScaleFactor
              fidivr SDWORD ptr sdValue

              fld [xsi].ScaleX.fScaleMax
              fsub st(0), st(1)
              fstp [xsi].ScaleX.fSetupMax
              fld [xsi].ScaleX.fScaleMin
              fadd st(0), st(1)
              fstp [xsi].ScaleX.fSetupMin
              fUnload 1                                   ;Unload FPU stack
            .endif
          .else
            .if ecx != [xsi].dGestureZoomLast             ;Take an action if the value has changed
              BitClr [xsi].ScaleY1.dFlags, (CHT_SCALE_AUTO_MIN or CHT_SCALE_AUTO_MAX)
              BitClr [xsi].ScaleY2.dFlags, (CHT_SCALE_AUTO_MIN or CHT_SCALE_AUTO_MAX)

              mov [xsi].dGestureZoomLast, ecx             ;Remember the last value
              mov eax, ecx
              sub eax, [xsi].dGestureZoomFirst
              mov [xsi].dGestureZoomFirst, ecx
              mov sdValue, eax

              fld [xsi].ScaleY1.fScaleFactor
              fidivr SDWORD ptr sdValue

              fld [xsi].ScaleY1.fScaleMax
              fsub st(0), st(1)
              fstp [xsi].ScaleY1.fSetupMax
              fld [xsi].ScaleY1.fScaleMin
              fadd st(0), st(1)
              fstp [xsi].ScaleY1.fSetupMin
              fUnload 1                                   ;Unload FPU stack

              fld [xsi].ScaleY2.fScaleFactor
              fidivr SDWORD ptr sdValue

              fld [xsi].ScaleY2.fScaleMax
              fsub st(0), st(1)
              fstp [xsi].ScaleY2.fSetupMax
              fld [xsi].ScaleY2.fScaleMin
              fadd st(0), st(1)
              fstp [xsi].ScaleY2.fSetupMin
              fUnload 1                                   ;Unload FPU stack
            .endif
          .endif
          invoke RedrawWindow, [xsi].hWnd, NULL, 0, RDW_INVALIDATE or RDW_UPDATENOW
        .endif
      .endif
      mov bHandled, TRUE

      ;Handle the pan gesture the compatibility way

;    .elseif GestInfo.dwID == GID_PAN
;      ;Code for panning goes here
;      .ifBitSet GestInfo.dwFlags, GF_BEGIN
;        movsx eax, GestInfo.ptsLocation.x
;        movsx ecx, GestInfo.ptsLocation.y
;        mov [xsi].GesturePanPos.x, eax
;        mov [xsi].GesturePanPos.y, ecx
;
;      .else
;        movsx ecx, GestInfo.ptsLocation.x
;        mov eax, ecx
;        sub eax, [xsi].GesturePanPos.x
;        mov [xsi].GesturePanPos.x, ecx
;        mov bHasChanged, FALSE
;
;        .ifBitSet [xsi].dFlags, TVIF_SHOW_SB_HORZ
;          mov bHasChanged, TRUE
;          .if SDWORD ptr eax > [xsi].Origin.x
;            mov [xsi].Origin.x, 0
;          .else
;            mov edx, [xsi].ClientRect.right
;            sub edx, [xsi].Padding.left
;            sub edx, [xsi].Padding.right                ;edx = drawable width on the client window
;
;            mov ecx, [xsi].DrawExtent.x
;            sub ecx, [xsi].Origin.x
;            add ecx, eax                                ;ecx = new visible height
;
;            .if SDWORD ptr ecx < edx
;              mov eax, [xsi].DrawExtent.x
;              sub eax, edx
;              mov [xsi].Origin.x, eax
;            .else
;              sub [xsi].Origin.x, eax
;            .endif
;          .endif
;          invoke SetScrollPos, [xsi].hWnd, SB_HORZ, [xsi].Origin.x, TRUE
;        .endif
;
;        movsx ecx, GestInfo.ptsLocation.y
;        mov eax, ecx
;        sub eax, [xsi].GesturePanPos.y                  ;eax = delta pos y
;        mov [xsi].GesturePanPos.y, ecx
;
;        .ifBitSet [xsi].dFlags, TVIF_SHOW_SB_VERT
;          .if SDWORD ptr eax > [xsi].Origin.y
;          mov bHasChanged, TRUE
;            mov [xsi].Origin.y, 0
;          .else
;            mov edx, [xsi].ClientRect.bottom
;            sub edx, [xsi].Padding.top
;            sub edx, [xsi].Padding.bottom               ;edx = drawable height on the client window
;
;            mov ecx, [xsi].DrawExtent.y
;            sub ecx, [xsi].Origin.y
;            add ecx, eax                                ;ecx = new visible height
;
;            .if SDWORD ptr ecx < edx
;              mov eax, [xsi].DrawExtent.y
;              sub eax, edx
;              mov [xsi].Origin.y, eax
;            .else
;              sub [xsi].Origin.y, eax
;            .endif
;          .endif
;          invoke SetScrollPos, [xsi].hWnd, SB_VERT, [xsi].Origin.y, TRUE
;        .endif
;
;        .if bHasChanged
;          invoke RedrawWindow, [xsi].hWnd, NULL, 0, RDW_INVALIDATE or RDW_UPDATENOW
;        .endif
;      .endif
;      invoke DefWindowProc, [xsi].hWnd, WM_GESTURE, wParam, lParam
;      ret
;
;      mov bHandled, TRUE

      invoke CloseGestureInfoHandle, lParam             ;Close the gesture handle
    .endif
  .endif

  .if bHandled
    xor eax, eax
  .else
    invoke DefWindowProc, [xsi].hWnd, WM_GESTURE, wParam, lParam
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     ChartWnd.OnMouseMove
; Purpose:    Event procedure for WM_MOUSEMOVE message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method ChartWnd.OnMouseMove, uses xbx xdi xsi, wParam:WPARAM, lParam:LPARAM
  local sdValue:SDWORD, dDoZoom:DWORD, dDoPan:DWORD, MouseClientPos:POINT
  local xCursor:XWORD, ToolInfo:TOOLINFO
  local cBuffer[1024]:CHR

  ;DbgText "ChartWnd.OnMouseMove"
  SetObject xsi

  ;Eliminate sprious WM_MOUSEMOVE messages
  ;https://devblogs.microsoft.com/oldnewthing/20031001-00/?p=42343
  PntS2Pnt MouseClientPos, lParam
  mov eax, MouseClientPos.x
  mov ecx, MouseClientPos.y
  ExitMethod .if eax == [xsi].LastCursorPos.x && ecx == [xsi].LastCursorPos.y

  mov dDoPan, FALSE
  mov dDoZoom, FALSE
  .ifBitClr wParam, MK_CONTROL
    .ifBitSet [xsi].dFlags, CHT_WND_PANABLE
      mov dDoPan, TRUE
    .endif
  .else
    .ifBitSet [xsi].dFlags, CHT_WND_ZOOMABLE
      mov dDoZoom, TRUE
    .endif
  .endif

  .if dDoPan != FALSE || dDoZoom != FALSE
    .if [xsi].sbButtonDownOn == CHT_ID_SCALEX
      BitClr [xsi].ScaleX.dFlags, (CHT_SCALE_AUTO_MIN or CHT_SCALE_AUTO_MAX)

      mov xax, lParam
      cwde
      mov ecx, [xsi].LastCursorPos.x
      mov [xsi].LastCursorPos.x, eax
      sub eax, ecx
      mov sdValue, eax

      fld [xsi].ScaleX.fScaleFactor
      fidivr SDWORD ptr sdValue
      fld [xsi].ScaleX.fScaleMax
      fsub st(0), st(1)
      fstp [xsi].ScaleX.fSetupMax
      fld [xsi].ScaleX.fScaleMin
      .if dDoZoom != FALSE
        fadd st(0), st(1)
      .else
        fsub st(0), st(1)
      .endif
      fstp [xsi].ScaleX.fSetupMin
      fUnload 1                                           ;Unload FPU stack
      OCall xsi.Refresh

    .elseif [xsi].sbButtonDownOn == CHT_ID_SCALEY1
      BitClr [xsi].ScaleY1.dFlags, (CHT_SCALE_AUTO_MIN or CHT_SCALE_AUTO_MAX)

      mov xax, lParam
      shr eax, 16
      cwde
      mov ecx, [xsi].LastCursorPos.y
      mov [xsi].LastCursorPos.y, eax
      sub ecx, eax
      mov sdValue, ecx

      fld [xsi].ScaleY1.fScaleFactor
      fidivr SDWORD ptr sdValue
      fld [xsi].ScaleY1.fScaleMax
      fsub st(0), st(1)
      fstp [xsi].ScaleY1.fSetupMax
      fld [xsi].ScaleY1.fScaleMin
      .if dDoZoom != FALSE
        fadd st(0), st(1)
      .else
        fsub st(0), st(1)
      .endif
      fstp [xsi].ScaleY1.fSetupMin
      fUnload 1                                         ;Unload FPU stack
      OCall xsi.Refresh

    .elseif [xsi].sbButtonDownOn == CHT_ID_SCALEY2
      BitClr [xsi].ScaleY2.dFlags, (CHT_SCALE_AUTO_MIN or CHT_SCALE_AUTO_MAX)

      mov xax, lParam
      shr eax, 16
      cwde
      mov ecx, [xsi].LastCursorPos.y
      mov [xsi].LastCursorPos.y, eax
      sub ecx, eax
      mov sdValue, ecx

      fld [xsi].ScaleY2.fScaleFactor
      fidivr SDWORD ptr sdValue
      fld [xsi].ScaleY2.fScaleMax
      fsub st(0), st(1)
      fstp [xsi].ScaleY2.fSetupMax
      fld [xsi].ScaleY2.fScaleMin
      .if dDoZoom != FALSE
        fadd st(0), st(1)
      .else
        fsub st(0), st(1)
      .endif
      fstp [xsi].ScaleY2.fSetupMin
      fUnload 1                                         ;Unload FPU stack
      OCall xsi.Refresh

    .elseif [xsi].sbButtonDownOn == CHT_ID_PLOT
      BitClr [xsi].ScaleX.dFlags, (CHT_SCALE_AUTO_MIN or CHT_SCALE_AUTO_MAX)
      mov xax, lParam
      cwde
      mov ecx, [xsi].LastCursorPos.x
      mov [xsi].LastCursorPos.x, eax
      sub eax, ecx
      mov sdValue, eax

      fld [xsi].ScaleX.fScaleFactor
      fidivr SDWORD ptr sdValue
      fld [xsi].ScaleX.fScaleMax
      fsub st(0), st(1)
      fstp [xsi].ScaleX.fSetupMax
      fld [xsi].ScaleX.fScaleMin
      .if dDoZoom != FALSE
        fadd st(0), st(1)
      .else
        fsub st(0), st(1)
      .endif
      fstp [xsi].ScaleX.fSetupMin
      fUnload 1                                         ;Unload FPU stack

      mov xax, lParam
      shr eax, 16
      cwde
      mov ecx, [xsi].LastCursorPos.y
      mov [xsi].LastCursorPos.y, eax
      sub ecx, eax
      mov sdValue, ecx
      .ifBitSet wParam, MK_LBUTTON
        BitClr [xsi].ScaleY1.dFlags, (CHT_SCALE_AUTO_MIN or CHT_SCALE_AUTO_MAX)
        fld [xsi].ScaleY1.fScaleFactor
        fidivr SDWORD ptr sdValue
        fld [xsi].ScaleY1.fScaleMax
        fsub st(0), st(1)
        fstp [xsi].ScaleY1.fSetupMax
        fld [xsi].ScaleY1.fScaleMin
        .if dDoZoom != FALSE
          fadd st(0), st(1)
        .else
          fsub st(0), st(1)
        .endif
        fstp [xsi].ScaleY1.fSetupMin
        fUnload 1                                       ;Unload FPU stack
      .endif

      .ifBitSet wParam, MK_RBUTTON
        BitClr [xsi].ScaleY2.dFlags, (CHT_SCALE_AUTO_MIN or CHT_SCALE_AUTO_MAX)
        fld [xsi].ScaleY2.fScaleFactor
        fidivr SDWORD ptr sdValue
        fld [xsi].ScaleY2.fScaleMax
        fsub st(0), st(1)
        fstp [xsi].ScaleY2.fSetupMax
        fld [xsi].ScaleY2.fScaleMin
        .if dDoZoom != FALSE
          fadd st(0), st(1)
        .else
          fsub st(0), st(1)
        .endif
        fstp [xsi].ScaleY2.fSetupMin
        fUnload 1                                       ;Unload FPU stack
      .endif

      OCall xsi.Refresh
    .endif
  .endif

  mov xCursor, IDC_ARROW                                ;Set default cursor
  mov ebx, -1
  .ifBitSet [xsi].dFlags, CHT_WND_DATA_TOOLTIPS_SHOW
    .if [xsi].sbButtonDownOn == CHT_ID_NONE             ;Nothing clicked on
      invoke PtInRect, addr [xsi].PlotRect, MouseClientPos
      .if eax != FALSE
        mov ebx, [xsi].InfoAreas.dCount                 ;Search in reverse order than the series were drawn
        dec ebx
        .while !SIGN?
          mov xdi, $OCall([xsi].InfoAreas::DataCollection.ItemAt, ebx)
          invoke PtInRect, addr [xdi].ChartInfoArea.Rect, MouseClientPos
          .break .if eax != FALSE
          dec ebx
        .endw

        .ifBitClr [xsi].dFlags, CHT_WND_TOOLTIP_ACTIVE
          .if ebx != -1
            OCall [xdi].ChartInfoArea.pSeries::ChartSeries.GetToolTipText, addr cBuffer, [xdi].ChartInfoArea.dDataIndex
            .if CHR ptr cBuffer[0] != 0
              m2m [xsi].pPrvInfoAreaSeries, [xdi].ChartInfoArea.pSeries, xax
              mov ToolInfo.cbSize, sizeof(ToolInfo)
              lea xax, cBuffer
              m2m ToolInfo.lpszText, xax
              mrm ToolInfo.hwnd, [xsi].hWnd, xcx
              mov ToolInfo.uId, xcx
              invoke SendMessage, [xsi].hToolTip, TTM_ACTIVATE, TRUE, 0
              invoke SendMessage, [xsi].hToolTip, TTM_UPDATETIPTEXT, 0, addr ToolInfo
              BitSet [xsi].dFlags, CHT_WND_TOOLTIP_ACTIVE
            .endif
            jmp @F
          .endif
          invoke SendMessage, [xsi].hToolTip, TTM_ACTIVATE, FALSE, 0
          BitClr [xsi].dFlags, CHT_WND_TOOLTIP_ACTIVE
          m2z [xsi].pPrvInfoAreaSeries
        .else
          mov xax, [xsi].pPrvInfoAreaSeries
          .if xax != [xdi].ChartInfoArea.pSeries || ebx == -1
            invoke SendMessage, [xsi].hToolTip, TTM_ACTIVATE, FALSE, 0
            BitClr [xsi].dFlags, CHT_WND_TOOLTIP_ACTIVE
            m2z [xsi].pPrvInfoAreaSeries
          .endif
        .endif
      .endif
    .endif
  .endif

  .if ebx != -1
    .ifBitClr [xsi].dFlags, CHT_WND_TOOLTIP_SHOW
      mov xCursor, IDC_HELP
    .endif
  .elseIfBitSet [xsi].dFlags, CHT_WND_PANABLE
    .if [xsi].sbButtonDownOn == CHT_ID_SCALEX
      mov xCursor, IDC_SIZEWE                           ;Moving horz direction
    .elseif [xsi].sbButtonDownOn == CHT_ID_SCALEY1 || [xsi].sbButtonDownOn == CHT_ID_SCALEY2
      mov xCursor, IDC_SIZENS                           ;Moving vert direction
    .elseif [xsi].sbButtonDownOn == CHT_ID_PLOT
      mov xCursor, IDC_SIZEALL                          ;Moving all directions
    .endif
  .endif
@@:
  invoke SetCursor, $invoke(LoadCursor, 0, xCursor)

  xor eax, eax
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     ChartWnd.OnMouseWheel
; Purpose:    Event procedure for WM_MOUSEWHEEL message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero.

Method ChartWnd.OnMouseWheel, uses xsi, wParam:WPARAM, lParam:LPARAM
  local sdValue:SDWORD, dDoZoom:DWORD, dDoPan:DWORD

  ;DbgText "ChartWnd.OnMouseWheel"
  SetObject xsi
  mov dDoPan, FALSE
  mov dDoZoom, FALSE
  .ifBitClr wParam, MK_CONTROL
    .ifBitSet [xsi].dFlags, CHT_WND_PANABLE
      mov dDoPan, TRUE
    .endif
  .else
    .ifBitSet [xsi].dFlags, CHT_WND_ZOOMABLE
      mov dDoZoom, TRUE
    .endif
  .endif

  SetObject xsi
  .if dDoPan != FALSE || dDoZoom != FALSE
    mov xax, wParam
    .ifBitSet ax, MK_SHIFT                                ;If SHIFT is pressed then act on the horz SB
      BitClr [xsi].ScaleX.dFlags, (CHT_SCALE_AUTO_MIN or CHT_SCALE_AUTO_MAX)
      sar eax, 16 + 3
      mov sdValue, eax

      fld [xsi].ScaleX.fScaleFactor
      fidivr SDWORD ptr sdValue

      fld [xsi].ScaleX.fScaleMax
      fsub st(0), st(1)
      fstp [xsi].ScaleX.fSetupMax
      fld [xsi].ScaleX.fScaleMin
      .if dDoZoom != FALSE
        fadd st(0), st(1)
      .else
        fsub st(0), st(1)
      .endif
      fstp [xsi].ScaleX.fSetupMin
      fUnload 1                                           ;Unload FPU stack
    .else
      BitClr [xsi].ScaleY1.dFlags, (CHT_SCALE_AUTO_MIN or CHT_SCALE_AUTO_MAX)
      BitClr [xsi].ScaleY2.dFlags, (CHT_SCALE_AUTO_MIN or CHT_SCALE_AUTO_MAX)
      sar eax, 16 + 3
      mov sdValue, eax

      fld [xsi].ScaleY1.fScaleFactor
      fidivr SDWORD ptr sdValue
      fld [xsi].ScaleY1.fScaleMax
      fsub st(0), st(1)
      fstp [xsi].ScaleY1.fSetupMax
      fld [xsi].ScaleY1.fScaleMin
      .if dDoZoom != FALSE
        fadd st(0), st(1)
      .else
        fsub st(0), st(1)
      .endif
      fstp [xsi].ScaleY1.fSetupMin
      fUnload 1                                           ;Unload FPU stack

      fld [xsi].ScaleY2.fScaleFactor
      fidivr SDWORD ptr sdValue
      fld [xsi].ScaleY2.fScaleMax
      fsub st(0), st(1)
      fstp [xsi].ScaleY2.fSetupMax
      fld [xsi].ScaleY2.fScaleMin
      .if dDoZoom != FALSE
        fadd st(0), st(1)
      .else
        fsub st(0), st(1)
      .endif
      fstp [xsi].ScaleY2.fSetupMin
      fUnload 1                                           ;Unload FPU stack
    .endif
    OCall xsi.Refresh
  .endif
  xor eax, eax
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     ChartWnd.OnNotify
; Purpose:    Event procedure for WM_NOTIFY message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero.

Method ChartWnd.OnNotify, uses xsi, wParam:WPARAM, lParam:LPARAM
;  DbgText "ChartWnd.OnNotify"
  SetObject xsi
  mov xax, lParam
  mov xdx, [xsi].hToolTip
  .if [xax].NMHDR.hwndFrom == xdx
    .if [xax].NMHDR.code == TTN_SHOW
      BitSet [xsi].dFlags, CHT_WND_TOOLTIP_SHOW
    .elseif [xax].NMHDR.code == TTN_POP
      BitClr [xsi].dFlags, CHT_WND_TOOLTIP_SHOW
    .endif
    xor eax, eax
  .else
    invoke GetParent, [xsi].hWnd
    invoke SendMessage, xax, WM_NOTIFY, wParam, lParam  ;Forward the msg to the parent wnd
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     ChartWnd.OnPaint
; Purpose:    Event procedure for WM_PAINT message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero.

Method ChartWnd.OnPaint, uses xsi, wParam:WPARAM, lParam:LPARAM
  local PS:PAINTSTRUCT, ClientRect:RECT

  ;DbgText "ChartWnd.OnPaint"
  SetObject xsi
  invoke BeginPaint, [xsi].hWnd, addr PS
  invoke GetClientRect, [xsi].hWnd, addr ClientRect
  OCall xsi.Show, PS.hdc, addr ClientRect
  invoke EndPaint, [xsi].hWnd, addr PS
  xor eax, eax
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     ChartWnd.Refresh
; Purpose:    Refresh the plot object.
; Arguments:  None.
; Return:     Nothing.

Method ChartWnd.Refresh, uses xsi
  local hDC:HDC

  ;DbgText "ChartWnd.Refresh"
  SetObject xsi
  mov hDC, $invoke(GetDC, [xsi].hWnd)
  OCall xsi.Show, hDC, addr [xsi].ViewRect
  invoke ReleaseDC, [xsi].hWnd, hDC
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     ChartWnd.Show
; Purpose:    Draw the ChartWnd object.
; Arguments:  Arg1: DC handle.
;             Arg2: -> RECT structure that indicates where to draw.
; Return:     Nothing.

CheckScaleSetupValues macro Scale
  fld Scale.fSetupMin
  fcomp cFloatMin
  fGetFlags
  .if ZERO?                                             ;fSetupMin = cFloatMin
    s2s Scale.fSetupMin, Scale.fDataMin, xax, xcx
  .endif

  fld Scale.fSetupMax
  fcomp cFloatMax
  fGetFlags
  .if ZERO?                                             ;fSetupMax = cFloatMax
    s2s Scale.fSetupMax, Scale.fDataMax, xax, xcx
  .endif
endm

GetScaleMinMax macro Index, MinIndex, MaxIndex
  mov pSeries, xax
  mov eax, [xax].$Obj(ChartSeries).&MaxIndex
  .if eax != -1
    inc edi                                             ;Set flag
    OCall pSeries::ChartSeries.ItemAt, Index, eax
    fld CHT_FLOAT ptr [xax]                             ;Xmax| Min | Max
    fcomi st(0), st(2)                                  ;Compare with maximum
    .if !CARRY?                                         ;st(0) > st(1)
      fst st(2)                                         ;Xmax| Min |Xmax
    .endif
    fUnload 1                                           ; Min | Max
  .endif

  mov xcx, pSeries
  mov eax, [xcx].$Obj(ChartSeries).&MinIndex
  .if eax != -1
    inc edi                                             ;Set flag
    OCall pSeries::ChartSeries.ItemAt, Index, eax
    fld CHT_FLOAT ptr [xax]                             ;Xmin| Min | Max
    fcomi st(0), st(1)                                  ;Compare with minimum
    .if CARRY?                                          ;st(0) < st(1)
      fst st(1)                                         ;Xmin|Xmin| Max
    .endif
    fUnload 1                                           ; Min | Max
  .endif
endm

Method ChartWnd.Show, uses xbx xdi xsi, hDC:HDC, pRect:PRECT
  local hPrevBmp:HBITMAP, pSeries:$ObjPtr(ChartSeries)

;  DbgText "ChartWnd.Show"
  SetObject xsi

  ;Reset Tooltip
  invoke SendMessage, [xsi].hToolTip, TTM_ACTIVATE, FALSE, 0
  BitClr [xsi].dFlags, CHT_WND_TOOLTIP_ACTIVE

  ;Do some initialization if the chart is shown for the first time
  .ifBitClr [xsi].dFlags, CHT_WND_SHOWN_FIRST_TIME

    ;Scan all series
    xor ebx, ebx
    .while ebx < [xsi].Data.dCount
      OCall [xsi].Data::Collection.ItemAt, ebx
      OCall xax::ChartSeries.Scan, [xax].$Obj(ChartSeries).dDataFrom, \
                                   [xax].$Obj(ChartSeries).dDataCount
      inc ebx
    .endw

    ;Set fDataMin and fDataMax values for the ScaleX
    fld cFloatMin                                         ;Min
    xor ebx, ebx
    fld cFloatMax                                         ;Min | Max
    xor edi, edi                                          ;Reset flag
    .while ebx < [xsi].Data.dCount
      OCall [xsi].Data::Collection.ItemAt, ebx
      GetScaleMinMax 0, dDataMinXIndex, dDataMaxXIndex    ;Modifies edi
      inc ebx
    .endw
    .if edi != 0                                          ;Check if something has changed
      fstp CHT_FLOAT ptr [xsi].ScaleX.fDataMin
      fstp CHT_FLOAT ptr [xsi].ScaleX.fDataMax
    .else
      fUnload 2
    .endif

    ;Set fDataMin and fDataMax values for the ScaleY1
    fld cFloatMin                                         ;Min
    xor ebx, ebx
    fld cFloatMax                                         ;Min | Max
    xor edi, edi                                          ;Reset flag
    .while ebx < [xsi].Data.dCount
      OCall [xsi].Data::Collection.ItemAt, ebx
      .ifBitClr [xax].$Obj(ChartSeries).dFlags, CHT_SERIES_USE_Y2
        GetScaleMinMax 1, dDataMinYIndex, dDataMaxYIndex  ;Modifies edi
      .endif
      inc ebx
    .endw
    .if edi != 0                                          ;Check if something has changed
      fstp CHT_FLOAT ptr [xsi].ScaleY1.fDataMin
      fstp CHT_FLOAT ptr [xsi].ScaleY1.fDataMax
    .else
      fUnload 2
    .endif

    ;Set fDataMin and fDataMax values for the ScaleY2
    fld cFloatMin                                         ;Min
    xor ebx, ebx
    fld cFloatMax                                         ;Min | Max
    xor edi, edi                                          ;Reset flag
    .while ebx < [xsi].Data.dCount
      OCall [xsi].Data::Collection.ItemAt, ebx
      .ifBitSet [xax].$Obj(ChartSeries).dFlags, CHT_SERIES_USE_Y2
        GetScaleMinMax 1, dDataMinYIndex, dDataMaxYIndex  ;Modifies edi
      .endif
      inc ebx
    .endw
    .if edi != 0                                          ;Check if something has changed
      fstp CHT_FLOAT ptr [xsi].ScaleY2.fDataMin
      fstp CHT_FLOAT ptr [xsi].ScaleY2.fDataMax
    .else
      fUnload 2
    .endif

    ;Sanity check fSetupMin and fSetupMax values
    CheckScaleSetupValues [xsi].ScaleX
    CheckScaleSetupValues [xsi].ScaleY1
    CheckScaleSetupValues [xsi].ScaleY2

    ;Store fInit values
    s2s [xsi].ScaleX.fInitMin, [xsi].ScaleX.fSetupMin, xax, xcx
    s2s [xsi].ScaleX.fInitMax, [xsi].ScaleX.fSetupMax, xax, xcx
    s2s [xsi].ScaleY1.fInitMin, [xsi].ScaleY1.fSetupMin, xax, xcx
    s2s [xsi].ScaleY1.fInitMax, [xsi].ScaleY1.fSetupMax, xax, xcx
    s2s [xsi].ScaleY2.fInitMin, [xsi].ScaleY2.fSetupMin, xax, xcx
    s2s [xsi].ScaleY2.fInitMax, [xsi].ScaleY2.fSetupMax, xax, xcx

    BitSet [xsi].dFlags, CHT_WND_SHOWN_FIRST_TIME
  .endif

  ;Draw on a memory DC to avoid flicker
  mov xdi, $invoke(CreateCompatibleDC, hDC)             ;Create Mem DC
  mov xbx, pRect
  invoke CreateCompatibleBitmap, hDC, [xbx].RECT.right, [xbx].RECT.bottom
  mov hPrevBmp, $invoke(SelectObject, xdi, xax)

  ;Check if we need an Y1 scale
  .ifBitSet [xsi].dFlags, CHT_WND_FORCE_Y1
    BitSet [xsi].dFlags, CHT_WND_SHOW_Y1
  .else
    BitClr [xsi].dFlags, CHT_WND_SHOW_Y1
    xor ebx, ebx
    .while ebx < [xsi].Data.dCount
      OCall [xsi].Data::Collection.ItemAt, ebx
      .ifBitClr [xax].$Obj(ChartSeries).dFlags, CHT_SERIES_USE_Y2
        BitSet [xsi].dFlags, CHT_WND_SHOW_Y1
        .break
      .endif
      inc ebx
    .endw
  .endif

  ;Check if we need an Y2 scale
  .ifBitSet [xsi].dFlags, CHT_WND_FORCE_Y2
    BitSet [xsi].dFlags, CHT_WND_SHOW_Y2
  .else
    BitClr [xsi].dFlags, CHT_WND_SHOW_Y2
    xor ebx, ebx
    .while ebx < [xsi].Data.dCount
      OCall [xsi].Data::Collection.ItemAt, ebx
      .ifBitSet [xax].$Obj(ChartSeries).dFlags, CHT_SERIES_USE_Y2
        BitSet [xsi].dFlags, CHT_WND_SHOW_Y2
        .break
      .endif
      inc ebx
    .endw
  .endif

  ;Draw frame, scales, etc.
  OCall xsi.Calc, xdi, pRect

  OCall xsi.DrawFrame, xdi
  OCall xsi.DrawScaleX, xdi
  .ifBitSet [xsi].dFlags, CHT_WND_SHOW_Y1
    OCall xsi.DrawScaleY1, xdi
  .endif
  .ifBitSet [xsi].dFlags, CHT_WND_SHOW_Y2
    OCall xsi.DrawScaleY2, xdi
  .endif

  ;Draw all series
  OCall [xsi].InfoAreas::DataCollection.DisposeAll      ;Dispose all previous ChartInfoAreas
  mov eax, [xsi].PlotRect.right
  mov ecx, [xsi].PlotRect.bottom
  .if (SDWORD ptr eax > [xsi].PlotRect.left) && (SDWORD ptr ecx > [xsi].PlotRect.top)
    xor ebx, ebx
    .while ebx != [xsi].Data.dCount
      OCall [xsi].Data::Collection.ItemAt, ebx
      OCall xax::ChartSeries.Draw, xdi                  ;Polymorphic call
      inc ebx
    .endw
  .endif

  ;Copy the drawn chart on memory DC to window DC
  mov xbx, pRect
  invoke BitBlt, hDC, [xbx].RECT.left, [xbx].RECT.top, [xbx].RECT.right, [xbx].RECT.bottom, \
                 xdi, [xbx].RECT.left, [xbx].RECT.top, SRCCOPY

  invoke DeleteObject, $invoke(SelectObject, xdi, hPrevBmp)   ;Release hMemBmp
  invoke DeleteDC, xdi                                        ;Release memory DC
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     ChartWnd.ShowSetupDlg
; Purpose:    Displays the chart setup dialog.
; Arguments:  Arg1: Dialog popup X position on screen.
;             Arg2: Dialog popup Y position on screen.
;             Arg3: ID of the selected chart element.
; Return:     Nothing.

ifdef INCLUDE_CHART_SETUP_DIALOG
Method ChartWnd.ShowSetupDlg, uses xsi, sdPosX:SDWORD, sdPosY:SDWORD, sdSelElementID:SDWORD
  local SetupDlg:$Obj(ChartSetup)

  ;DbgText "ChartWnd.ShowSetupDlg"
  SetObject xsi
  New SetupDlg::ChartSetup
  OCall SetupDlg::ChartSetup.Init, xsi, [xsi].hWnd, sdSelElementID
  OCall SetupDlg::ChartSetup.ShowAt, sdPosX, sdPosY
  OCall SetupDlg::ChartSetup.Done
MethodEnd
endif
; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     ChartWnd.Store
; Purpose:    Store buffer data to a stream object.
; Arguments:  Arg1: -> Stream object.
; Return:     Nothing.

Method ChartWnd.Store, uses xsi, pStream:$ObjPtr(Stream)
  SetObject xsi
  ACall xsi.Store, pStream
  OCall pStream::Stream.BinWrite32, [xsi].dFlags
  OCall pStream::Stream.BinWrite, addr [xsi].ScaleX,   sizeof(CHT_SCALE_DATA)
  OCall pStream::Stream.BinWrite, addr [xsi].ScaleY1,  sizeof(CHT_SCALE_DATA)
  OCall pStream::Stream.BinWrite, addr [xsi].ScaleY2,  sizeof(CHT_SCALE_DATA)
  OCall pStream::Stream.BinWrite, addr [xsi].Colors,   sizeof(CHT_COLOR_CONFIG)
  OCall pStream::Stream.BinWrite, addr [xsi].ViewRect, sizeof(RECT)
  OCall pStream::Stream.BinWrite, addr [xsi].Padding,  sizeof(RECT)
  OCall pStream::Stream.BinWrite, addr [xsi].DrawRect, sizeof(RECT)
  OCall pStream::Stream.BinWrite, addr [xsi].PlotRect, sizeof(RECT)
  OCall pStream::Stream.BinWrite, addr [xsi].TextMetricHorz,  sizeof(TEXTMETRIC)
  OCall pStream::Stream.BinWrite, addr [xsi].TextMetricVert,  sizeof(TEXTMETRIC)
  OCall pStream::Stream.BinWrite8, [xsi].sbButtonDownOn
  OCall pStream::Stream.BinWrite, addr [xsi].LastCursorPos,   sizeof(POINT)
  OCall pStream::Stream.BinWrite32, addr [xsi].dGestureZoomFirst
  OCall pStream::Stream.BinWrite32, addr [xsi].dGestureZoomLast
  OCall [xsi].Data::Collection.Store, pStream
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     ChartWnd.Startup
; Purpose:    Register the object with the OS.
; Arguments:  None.
; Return:     Nothing.

Method ChartWnd.Startup
  local WC:WNDCLASSEX

  mov WC.cbSize, sizeof WNDCLASSEX
  mov WC.style, CS_DBLCLKS or CS_HREDRAW or CS_VREDRAW
  m2m WC.lpfnWndProc, $MethodAddr(ChartWnd.WndProc), xdx
  m2z WC.cbClsExtra
  m2z WC.cbWndExtra
  m2m WC.hInstance, hInstance, xdx
  m2z WC.hbrBackground
  m2z WC.lpszMenuName
  c2m WC.lpszClassName, offset szChart, xdx
  mov WC.hIcon, 0
  mov WC.hCursor, 0
  m2z WC.hIconSm

  invoke RegisterClassEx, addr WC
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     ChartWnd.WindowProc
; Purpose:    Dispatching of window messages.
; Arguments:  Arg1: Message identifier.
;             Arg2: First message parameter.
;             Arg3: Second message parameter.
; Return:     eax = This value is the result of the message processing and depends on the msg ID.
;             Window HANDLE is passed in pSelf (hidden parameter).

Method ChartWnd.WndProc, uses xsi, uMsg:DWORD, wParam:WPARAM, lParam:LPARAM
  ;DbgMessage uMsg,, "ChartWnd.WndProc"
  .if uMsg == WM_NCCREATE
    mov xax, lParam
    .if [xax].CREATESTRUCT.lpCreateParams == NULL
      ;If lpCreateParams is 0, then it is a resource call => Create new object instance
      mov xsi, $New(ChartWnd)
      invoke GetParent, pSelf
      .if xax != 0
        invoke SendMessage, xax, WM_GETOBJECTINSTANCE, 0, 0 ;Get instance POINTER of the parent object
      .endif
      ACall xsi::ChartWnd.Init, xax, pSelf              ;Window.Init
      BitSet [xsi].$Obj(ChartWnd).dFlags, CHT_WND_SELF_INST
    .else
      ;Code call
      mov xsi, [xax].CREATESTRUCT.lpCreateParams
      m2m [xsi].$Obj(ChartWnd).hWnd, pSelf, xax
      BitClr [xsi].$Obj(ChartWnd).dFlags, CHT_WND_SELF_INST
    .endif
    invoke SetWindowLongPtr, pSelf, GWLP_USERDATA, xsi  ;Store the instance pointer
    OCall xsi::ChartWnd.Dispatch, pSelf, uMsg, wParam, lParam
  .else
    invoke GetWindowLongPtr, pSelf, GWLP_USERDATA       ;if GWLP_USERDATA wasn't set,
    .if xax == NULL                                     ;GetWindowLongPtr returns NULL
      invoke DefWindowProc, pSelf, uMsg, wParam, lParam
    .else
      mov xsi, xax
      OCall xsi::ChartWnd.Dispatch, pSelf, uMsg, wParam, lParam
      .if uMsg == WM_NCDESTROY
        .ifBitSet [xsi].$Obj(ChartWnd).dFlags, CHT_WND_SELF_INST
          Destroy xsi
        .endif
      .endif
    .endif
  .endif
MethodEnd
