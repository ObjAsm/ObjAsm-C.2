; ==================================================================================================
; Title:      ChartXYSeries.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm support of ChartXYSeries objects.
; Notes:      Version 1.0.0, August 2021
; ==================================================================================================



; ==================================================================================================
;    ChartXYSeries implementation
; ==================================================================================================

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     ChartXYSeries.DrawMarkerAt
; Purpose:    Display a marker at a specific position.
; Arguments:  Arg1: Output device context.
;             Arg3: Marker center position X.
;             Arg4: Marker center position Y.
; Return:     Nothing.

Method ChartXYSeries.DrawMarkerAt, uses xbx xsi, hDC:HDC, sdPosX:SDWORD, sdPosY:SDWORD
  local Pos:RECT, PolyPnts[16]:POINT

  SetObject xsi
  .if [xsi].Setup.dMarkerSize != 0
    .if [xsi].Setup.dMarkerShape == CHTXY_MARKER_SQUARE
      mov edx, [xsi].Setup.dMarkerSize
      mov eax, edx
      shr eax, 1
      mov ecx, sdPosX
      sub ecx, eax
      mov Pos.left, ecx
      add ecx, edx
      mov Pos.right, ecx
      mov ecx, sdPosY
      sub ecx, eax
      mov Pos.top, ecx
      add ecx, edx
      mov Pos.bottom, ecx
      invoke Rectangle, hDC, Pos.left, Pos.top, Pos.right, Pos.bottom

    .elseif [xsi].Setup.dMarkerShape == CHTXY_MARKER_RECT_VER
      mov edx, [xsi].Setup.dMarkerSize
      mov eax, edx
      shr eax, 1
      mov ecx, sdPosY
      sub ecx, eax
      mov Pos.top, ecx
      add ecx, edx
      mov Pos.bottom, ecx
      shr edx, 1
      shr eax, 1
      mov ecx, sdPosX
      sub ecx, eax
      mov Pos.left, ecx
      add ecx, edx
      mov Pos.right, ecx
      invoke Rectangle, hDC, Pos.left, Pos.top, Pos.right, Pos.bottom

    .elseif [xsi].Setup.dMarkerShape == CHTXY_MARKER_RECT_HOR
      mov edx, [xsi].Setup.dMarkerSize
      mov eax, edx
      shr eax, 1
      mov ecx, sdPosX
      sub ecx, eax
      mov Pos.left, ecx
      add ecx, edx
      mov Pos.right, ecx
      shr edx, 1
      shr eax, 1
      mov ecx, sdPosY
      sub ecx, eax
      mov Pos.top, ecx
      add ecx, edx
      mov Pos.bottom, ecx
      invoke Rectangle, hDC, Pos.left, Pos.top, Pos.right, Pos.bottom

    .elseif [xsi].Setup.dMarkerShape == CHTXY_MARKER_CIRCLE
      mov edx, [xsi].Setup.dMarkerSize
      mov eax, edx
      shr eax, 1
      mov ecx, sdPosX
      sub ecx, eax
      mov Pos.left, ecx
      add ecx, edx
      mov Pos.right, ecx
      mov ecx, sdPosY
      sub ecx, eax
      mov Pos.top, ecx
      add ecx, edx
      mov Pos.bottom, ecx
      invoke Ellipse, hDC, Pos.left, Pos.top, Pos.right, Pos.bottom

    .elseif [xsi].Setup.dMarkerShape == CHTXY_MARKER_ELLIPSE_VER
      mov edx, [xsi].Setup.dMarkerSize
      mov eax, edx
      shr eax, 1
      mov ecx, sdPosY
      sub ecx, eax
      mov Pos.top, ecx
      add ecx, edx
      mov Pos.bottom, ecx
      shr edx, 1
      shr eax, 1
      mov ecx, sdPosX
      sub ecx, eax
      mov Pos.left, ecx
      add ecx, edx
      mov Pos.right, ecx
      invoke Ellipse, hDC, Pos.left, Pos.top, Pos.right, Pos.bottom

    .elseif [xsi].Setup.dMarkerShape == CHTXY_MARKER_ELLIPSE_HOR
      mov edx, [xsi].Setup.dMarkerSize
      mov eax, edx
      shr eax, 1
      mov ecx, sdPosX
      sub ecx, eax
      mov Pos.left, ecx
      add ecx, edx
      mov Pos.right, ecx
      shr edx, 1
      shr eax, 1
      mov ecx, sdPosY
      sub ecx, eax
      mov Pos.top, ecx
      add ecx, edx
      mov Pos.bottom, ecx
      invoke Ellipse, hDC, Pos.left, Pos.top, Pos.right, Pos.bottom

    .elseif [xsi].Setup.dMarkerShape == CHTXY_MARKER_RHOMBUS
      lea xbx, PolyPnts
      mov eax, sdPosX
      mov [xbx + 0*sizeof(POINT)].POINT.x, eax
      mov [xbx + 2*sizeof(POINT)].POINT.x, eax
      mov ecx, sdPosY
      mov [xbx + 1*sizeof(POINT)].POINT.y, ecx
      mov [xbx + 3*sizeof(POINT)].POINT.y, ecx
      mov edx, [xsi].Setup.dMarkerSize
      shr edx, 1
      sub eax, edx
      mov [xbx + 3*sizeof(POINT)].POINT.x, eax
      add eax, [xsi].Setup.dMarkerSize
      dec eax
      mov [xbx + 1*sizeof(POINT)].POINT.x, eax
      sub ecx, edx
      mov [xbx + 0*sizeof(POINT)].POINT.y, ecx
      add ecx, [xsi].Setup.dMarkerSize
      dec ecx
      mov [xbx + 2*sizeof(POINT)].POINT.y, ecx
      invoke Polygon, hDC, xbx, 4

    .elseif [xsi].Setup.dMarkerShape == CHTXY_MARKER_RHOMBUS_HOR
      lea xbx, PolyPnts
      mov eax, sdPosX
      mov [xbx + 0*sizeof(POINT)].POINT.x, eax
      mov [xbx + 2*sizeof(POINT)].POINT.x, eax
      mov ecx, sdPosY
      mov [xbx + 1*sizeof(POINT)].POINT.y, ecx
      mov [xbx + 3*sizeof(POINT)].POINT.y, ecx
      mov edx, [xsi].Setup.dMarkerSize
      shr edx, 1
      sub eax, edx
      mov [xbx + 3*sizeof(POINT)].POINT.x, eax
      add eax, [xsi].Setup.dMarkerSize
      dec eax
      mov [xbx + 1*sizeof(POINT)].POINT.x, eax
      mov eax, edx
      shr edx, 1
      sub ecx, edx
      mov [xbx + 0*sizeof(POINT)].POINT.y, ecx
      add ecx, eax
      dec ecx
      mov [xbx + 2*sizeof(POINT)].POINT.y, ecx
      invoke Polygon, hDC, xbx, 4

    .elseif [xsi].Setup.dMarkerShape == CHTXY_MARKER_RHOMBUS_VER
      lea xbx, PolyPnts
      mov eax, sdPosX
      mov [xbx + 0*sizeof(POINT)].POINT.x, eax
      mov [xbx + 2*sizeof(POINT)].POINT.x, eax
      mov ecx, sdPosY
      mov [xbx + 1*sizeof(POINT)].POINT.y, ecx
      mov [xbx + 3*sizeof(POINT)].POINT.y, ecx
      mov edx, [xsi].Setup.dMarkerSize
      shr edx, 1
      sub ecx, edx
      mov [xbx + 0*sizeof(POINT)].POINT.y, ecx
      add ecx, [xsi].Setup.dMarkerSize
      dec ecx
      mov [xbx + 2*sizeof(POINT)].POINT.y, ecx
      mov ecx, edx
      shr edx, 1
      sub eax, edx
      mov [xbx + 3*sizeof(POINT)].POINT.x, eax
      add eax, ecx
      dec eax
      mov [xbx + 1*sizeof(POINT)].POINT.x, eax

      invoke Polygon, hDC, xbx, 4

    .elseif [xsi].Setup.dMarkerShape == CHTXY_MARKER_CROSS
      lea xbx, PolyPnts
      mov eax, sdPosX
      mov [xbx + 00*sizeof(POINT)].POINT.x, eax
      mov [xbx + 06*sizeof(POINT)].POINT.x, eax
      mov ecx, sdPosY
      mov [xbx + 03*sizeof(POINT)].POINT.y, ecx
      mov [xbx + 09*sizeof(POINT)].POINT.y, ecx
      mov edx, [xsi].Setup.dMarkerSize
      shr edx, 1
      sub eax, edx
      mov [xbx + 08*sizeof(POINT)].POINT.x, eax
      mov [xbx + 10*sizeof(POINT)].POINT.x, eax
      add eax, [xsi].Setup.dMarkerSize
      dec eax
      mov [xbx + 02*sizeof(POINT)].POINT.x, eax
      mov [xbx + 04*sizeof(POINT)].POINT.x, eax
      sub ecx, edx
      mov [xbx + 01*sizeof(POINT)].POINT.y, ecx
      mov [xbx + 11*sizeof(POINT)].POINT.y, ecx
      add ecx, [xsi].Setup.dMarkerSize
      dec ecx
      mov [xbx + 05*sizeof(POINT)].POINT.y, ecx
      mov [xbx + 07*sizeof(POINT)].POINT.y, ecx
      mov ecx, edx
      shr edx, 1
      mov eax, sdPosX
      sub eax, edx
      mov [xbx + 07*sizeof(POINT)].POINT.x, eax
      mov [xbx + 09*sizeof(POINT)].POINT.x, eax
      mov [xbx + 11*sizeof(POINT)].POINT.x, eax
      add eax, ecx
      mov [xbx + 01*sizeof(POINT)].POINT.x, eax
      mov [xbx + 03*sizeof(POINT)].POINT.x, eax
      mov [xbx + 05*sizeof(POINT)].POINT.x, eax
      mov eax, sdPosY
      sub eax, edx
      mov [xbx + 00*sizeof(POINT)].POINT.y, eax
      mov [xbx + 02*sizeof(POINT)].POINT.y, eax
      mov [xbx + 10*sizeof(POINT)].POINT.y, eax
      add eax, ecx
      mov [xbx + 04*sizeof(POINT)].POINT.y, eax
      mov [xbx + 06*sizeof(POINT)].POINT.y, eax
      mov [xbx + 08*sizeof(POINT)].POINT.y, eax

      invoke Polygon, hDC, xbx, 12

    .elseif [xsi].Setup.dMarkerShape == CHTXY_MARKER_STAR_4
      lea xbx, PolyPnts
      mov eax, sdPosX
      mov [xbx + 00*sizeof(POINT)].POINT.x, eax
      mov [xbx + 04*sizeof(POINT)].POINT.x, eax
      mov ecx, sdPosY
      mov [xbx + 02*sizeof(POINT)].POINT.y, ecx
      mov [xbx + 06*sizeof(POINT)].POINT.y, ecx
      mov edx, [xsi].Setup.dMarkerSize
      shr edx, 1
      sub eax, edx
      mov [xbx + 06*sizeof(POINT)].POINT.x, eax
      add eax, [xsi].Setup.dMarkerSize
      dec eax
      mov [xbx + 02*sizeof(POINT)].POINT.x, eax
      sub ecx, edx
      mov [xbx + 00*sizeof(POINT)].POINT.y, ecx
      add ecx, [xsi].Setup.dMarkerSize
      dec ecx
      mov [xbx + 04*sizeof(POINT)].POINT.y, ecx
      shr edx, 1
      mov ecx, edx
      shr edx, 1
      mov eax, sdPosX
      sub eax, edx
      mov [xbx + 05*sizeof(POINT)].POINT.x, eax
      mov [xbx + 07*sizeof(POINT)].POINT.x, eax
      add eax, ecx
      mov [xbx + 01*sizeof(POINT)].POINT.x, eax
      mov [xbx + 03*sizeof(POINT)].POINT.x, eax
      mov eax, sdPosY
      sub eax, edx
      mov [xbx + 01*sizeof(POINT)].POINT.y, eax
      mov [xbx + 07*sizeof(POINT)].POINT.y, eax
      add eax, ecx
      mov [xbx + 03*sizeof(POINT)].POINT.y, eax
      mov [xbx + 05*sizeof(POINT)].POINT.y, eax
      invoke Polygon, hDC, xbx, 8

    .elseif [xsi].Setup.dMarkerShape == CHTXY_MARKER_STAR_8
      lea xbx, PolyPnts
      mov eax, sdPosX
      mov [xbx + 00*sizeof(POINT)].POINT.x, eax
      mov [xbx + 08*sizeof(POINT)].POINT.x, eax
      mov ecx, sdPosY
      mov [xbx + 04*sizeof(POINT)].POINT.y, ecx
      mov [xbx + 12*sizeof(POINT)].POINT.y, ecx

      mov edx, [xsi].Setup.dMarkerSize
      shr edx, 1
      sub eax, edx
      mov [xbx + 12*sizeof(POINT)].POINT.x, eax
      add eax, [xsi].Setup.dMarkerSize
      dec eax
      mov [xbx + 04*sizeof(POINT)].POINT.x, eax
      sub ecx, edx
      mov [xbx + 00*sizeof(POINT)].POINT.y, ecx
      add ecx, [xsi].Setup.dMarkerSize
      dec ecx
      mov [xbx + 08*sizeof(POINT)].POINT.y, ecx


      mov ecx, edx
      shr edx, 1
      mov eax, sdPosX
      sub eax, edx
      mov [xbx + 11*sizeof(POINT)].POINT.x, eax
      mov [xbx + 13*sizeof(POINT)].POINT.x, eax
      add eax, ecx
      mov [xbx + 03*sizeof(POINT)].POINT.x, eax
      mov [xbx + 05*sizeof(POINT)].POINT.x, eax

      mov eax, sdPosY
      sub eax, edx
      mov [xbx + 01*sizeof(POINT)].POINT.y, eax
      mov [xbx + 15*sizeof(POINT)].POINT.y, eax
      add eax, ecx
      mov [xbx + 07*sizeof(POINT)].POINT.y, eax
      mov [xbx + 09*sizeof(POINT)].POINT.y, eax


      mov ecx, edx
      shr edx, 1
      mov eax, sdPosX
      sub eax, edx
      mov [xbx + 09*sizeof(POINT)].POINT.x, eax
      mov [xbx + 15*sizeof(POINT)].POINT.x, eax
      add eax, ecx
      mov [xbx + 01*sizeof(POINT)].POINT.x, eax
      mov [xbx + 07*sizeof(POINT)].POINT.x, eax

      mov eax, sdPosY
      sub eax, edx
      mov [xbx + 03*sizeof(POINT)].POINT.y, eax
      mov [xbx + 13*sizeof(POINT)].POINT.y, eax
      add eax, ecx
      mov [xbx + 05*sizeof(POINT)].POINT.y, eax
      mov [xbx + 11*sizeof(POINT)].POINT.y, eax


      mov ecx, [xsi].Setup.dMarkerSize
      lea ecx, [2*ecx + ecx]
      shr ecx, 2
      mov edx, ecx
      shr edx, 1

      mov eax, sdPosX
      sub eax, edx
      mov [xbx + 10*sizeof(POINT)].POINT.x, eax
      mov [xbx + 14*sizeof(POINT)].POINT.x, eax
      add eax, ecx
      mov [xbx + 02*sizeof(POINT)].POINT.x, eax
      mov [xbx + 06*sizeof(POINT)].POINT.x, eax

      mov eax, sdPosY
      sub eax, edx
      mov [xbx + 02*sizeof(POINT)].POINT.y, eax
      mov [xbx + 14*sizeof(POINT)].POINT.y, eax
      add eax, ecx
      mov [xbx + 06*sizeof(POINT)].POINT.y, eax
      mov [xbx + 10*sizeof(POINT)].POINT.y, eax

      invoke Polygon, hDC, xbx, 16

    .endif
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     ChartXYSeries.Draw
; Purpose:    Draw the series representation and create the InfoAreas.
; Arguments:  Arg1: hDC.
; Return:     Nothing.

Method ChartXYSeries.Draw, uses xbx xdi xsi, hDC:HDC
  local hRgn:HRGN, hPrevRgn:HRGN, hPrvPen:HPEN, hPrvBrush:HBRUSH
  local dDataIndex:DWORD, fXdelta:CHT_FLOAT, fYdelta:CHT_FLOAT
  local fX0:CHT_FLOAT, fY0:CHT_FLOAT, fX1:CHT_FLOAT, fY1:CHT_FLOAT
  local Pnt0:POINT, Pnt1:POINT, PrvPnt0:POINT, PrvPnt1:POINT

;  DbgText "ChartXYSeries.Draw"
  SetObject xsi
  mov xcx, [xsi].pOwner
  mov xdi, [xcx].$Obj(Collection).pOwner                ;xdi -> ChartWnd
  assume xdi:$ObjPtr(ChartWnd)

  .ifBitSet [xsi].dFlags, CHT_SERIES_USE_Y2
    lea xbx, [xdi].ScaleY2
  .else
    lea xbx, [xdi].ScaleY1
  .endif

  ;Clip drawing to the plotarea
  invoke GetClipRgn, hDC, hPrevRgn
  mov hRgn, $invoke(CreateRectRgn, [xdi].PlotRect.left,  [xdi].PlotRect.top, \
                                   [xdi].PlotRect.right, [xdi].PlotRect.bottom)
  invoke SelectClipRgn, hDC, hRgn

  ;Reset all PrvPnt
  xor eax, eax
  mov PrvPnt0.x, eax
  mov PrvPnt0.y, eax
  mov PrvPnt1.x, eax
  mov PrvPnt1.y, eax

  .ifBitSet [xsi].dFlags, CHT_SERIES_SHOW_DEPICTION
    .ifBitSet [xdi].dFlags, CHT_WND_COLOR
      mov eax, [xsi].Setup.LineColor
    .else
      mov eax, $RGB(000,000,000)
    .endif
    invoke CreatePen, [xsi].Setup.dLineStyle, [xsi].Setup.dLineWidth, eax
    mov hPrvPen, $invoke(SelectObject, hDC, xax)

    mov eax, [xsi].dDataFrom
    add eax, [xsi].dDataCount
    dec eax
    mov dDataIndex, eax
    .while (SDWORD ptr eax > [xsi].dDataFrom)
      OCall xsi::ChartXYSeries.ItemAt, 0, dDataIndex
      fld [xdi].ScaleX.fScaleMin
      fld [xdi].ScaleX.fScaleMax
      fld CHT_FLOAT ptr [xax - 2*sizeof(CHT_FLOAT)]     ;xa, xmax, xmin
      fst fX0
      fcomi st(0), st(2)
      fld CHT_FLOAT ptr [xax - 0*sizeof(CHT_FLOAT)]     ;xb, xa, xmax, xmin
      fst fX1
      jae @F
      fcomi st(0), st(3)
      jb @NextLine4                                     ;=> fUnload 4
    @@:
      fcomip st(0), st(2)                               ;xa, xmax, xmin
      jbe @F
      fcomi st(0), st(1)                                ;xa, xmax, xmin
      ja @NextLine3                                     ;=> fUnload 3
    @@:
      fUnload 3

      fld [xbx].CHT_SCALE_DATA.fScaleMin
      fld [xbx].CHT_SCALE_DATA.fScaleMax
      fld CHT_FLOAT ptr [xax - 1*sizeof(CHT_FLOAT)]     ;ya, ymax, ymin
      fst fY0
      fcomi st(0), st(2)
      fld CHT_FLOAT ptr [xax + 1*sizeof(CHT_FLOAT)]     ;yb, ya, ymax, ymin
      fst fY1
      jae @F
      fcomi st(0), st(3)
      jb @NextLine4                                     ;=> fUnload 4
    @@:
      fcomip st(0), st(2)                               ;ya, ymax, ymin
      jbe @F
      fcomi st(0), st(1)                                ;ya, ymax, ymin
      ja @NextLine3                                     ;=> fUnload 3
    @@:
      fUnload 1                                         ;ymax, ymin
      ;If we are here, we excluded all obvious lines outside the clipping rectangle

      fld fX1
      fsub fX0
      fstp fXdelta
      fld fY1
      fsub fY0
      fstp fYdelta

      fld fY0                                           ;fY0, ymax, ymin
      fcomi st(0), st(1)
      jbe @F
      ;Calc intersection on top edge
      fUnload
      fst fY0                                           ;ymax, ymin
      fsub CHT_FLOAT ptr [xax + 1*sizeof(CHT_FLOAT)]    ;ymax - fYb, ymin
      fmul fXdelta
      fdiv fYdelta
      fadd CHT_FLOAT ptr [xax - 0*sizeof(CHT_FLOAT)]    ;(fXdelta/fYdelta)(ymax - fYb) + fXb, ymin
      fstp fX0                                          ;ymin
      fUnload
      jmp @1C
    @@:
      fcomi st(0), st(2)                                ;fY0, ymax, ymin
      jae @1B
      ;Calc intersection on bottom edge
      fUnload 2                                         ;ymin
      fst fY0
      fsub CHT_FLOAT ptr [xax + 1*sizeof(CHT_FLOAT)]    ;ymin - fYb
      fmul fXdelta
      fdiv fYdelta
      fadd CHT_FLOAT ptr [xax - 0*sizeof(CHT_FLOAT)]    ;(fXdelta/fYdelta)(ymin - fYb) + fXb
      fstp fX0
      jmp @1C
    @1B:
      fUnload 3
    @1C:
      fld [xdi].ScaleX.fScaleMin
      fld [xdi].ScaleX.fScaleMax
      fld fX0                                           ;fX0, xmax, xmin
      fcomi st(0), st(1)
      jbe @F
      fUnload                                           ;xmax, xmin
      ;Calc intersection on right edge
      fst fX0
      fsub CHT_FLOAT ptr [xax - 0*sizeof(CHT_FLOAT)]
      fmul fYdelta
      fdiv fXdelta
      fadd CHT_FLOAT ptr [xax + 1*sizeof(CHT_FLOAT)]
      fstp fY0
      jmp @2A                                           ;xmin
    @@:
      fcomi st(0), st(2)                                ;fX0, xmax, xmin
      fUnload 2                                         ;xmin
      jae @2A
      ;Calc intersection on left edge
      fst fX0
      fsub CHT_FLOAT ptr [xax - 0*sizeof(CHT_FLOAT)]
      fmul fYdelta
      fdiv fXdelta
      fadd CHT_FLOAT ptr [xax + 1*sizeof(CHT_FLOAT)]
      fst fY0
    @2A:
      fUnload

      fld [xbx].CHT_SCALE_DATA.fScaleMin
      fld [xbx].CHT_SCALE_DATA.fScaleMax
      fld fY1                                           ;fY1, ymax, ymin
      fcomi st(0), st(1)
      jbe @F
      ;Calc intersection on top edge
      fUnload
      fst fY1                                           ;ymax, ymin
      fsub CHT_FLOAT ptr [xax + 1*sizeof(CHT_FLOAT)]    ;ymax - fYb, ymin
      fmul fXdelta
      fdiv fYdelta
      fadd CHT_FLOAT ptr [xax - 0*sizeof(CHT_FLOAT)]    ;(fXdelta/fYdelta)(ymax - fYb) + fXb, ymin
      fstp fX1                                          ;ymin
      fUnload
      jmp @2C
    @@:
      fcomi st(0), st(2)                                ;fY1, ymax, ymin
      jae @2B
      ;Calc intersection on bottom edge
      fUnload 2                                         ;ymin
      fst fY1
      fsub CHT_FLOAT ptr [xax + 1*sizeof(CHT_FLOAT)]    ;ymin - fYb
      fmul fXdelta
      fdiv fYdelta
      fadd CHT_FLOAT ptr [xax - 0*sizeof(CHT_FLOAT)]    ;(fXdelta/fYdelta)(ymin - fYb) + fXb
      fstp fX1
      jmp @2C
    @2B:
      fUnload 3
    @2C:
      fld [xdi].ScaleX.fScaleMin
      fld [xdi].ScaleX.fScaleMax
      fld fX1                                           ;fX1, xmax, xmin
      fcomi st(0), st(1)
      jbe @F
      fUnload                                           ;xmax, xmin
      ;Calc intersection on right edge
      fst fX1
      fsub CHT_FLOAT ptr [xax - 0*sizeof(CHT_FLOAT)]
      fmul fYdelta
      fdiv fXdelta
      fadd CHT_FLOAT ptr [xax + 1*sizeof(CHT_FLOAT)]
      fstp fY1
      jmp @3                                            ;xmin
    @@:
      fcomi st(0), st(2)
      fUnload 2                                         ;xmin
      jae @3
      ;Calc intersection on left edge
      fst fX1
      fsub CHT_FLOAT ptr [xax - 0*sizeof(CHT_FLOAT)]
      fmul fYdelta
      fdiv fXdelta
      fadd CHT_FLOAT ptr [xax + 1*sizeof(CHT_FLOAT)]
      fst fX1
    @3:
      fUnload
      ;If we are here, we will check our results

      fld [xdi].ScaleX.fScaleMin
      fld [xdi].ScaleX.fScaleMax
      fld fX0                                           ;fX0, xmax, xmin
      fcomi st(0), st(2)
      fld fX1                                           ;fX1, fX0, xmax, xmin
      jae @F
      fcomi st(0), st(3)
      jb @NextLine4                                     ;=> fUnload 4
    @@:
      fcomip st(0), st(2)                               ;fX0, xmax, xmin
      jbe @F
      fcomi st(0), st(1)                                ;xa, xmax, xmin
      ja @NextLine3                                     ;=> fUnload 3
    @@:
      fUnload 3

      ;If we are here, we will draw finally our line
      fld fX0
      fsub [xdi].ScaleX.fScaleMin
      fmul [xdi].ScaleX.fScaleFactor
      fistp Pnt0.x
      mov edx, [xdi].PlotRect.left
      add Pnt0.x, edx
      fld fY0
      fsub [xbx].CHT_SCALE_DATA.fScaleMin
      fmul [xbx].CHT_SCALE_DATA.fScaleFactor
      fistp Pnt0.y
      neg Pnt0.y
      mov edx, [xdi].PlotRect.bottom
      add Pnt0.y, edx

      fld fX1
      fsub [xdi].ScaleX.fScaleMin
      fmul [xdi].ScaleX.fScaleFactor
      fistp Pnt1.x
      mov edx, [xdi].PlotRect.left
      add Pnt1.x, edx
      fld fY1
      fsub [xbx].CHT_SCALE_DATA.fScaleMin
      fmul [xbx].CHT_SCALE_DATA.fScaleFactor
      fistp Pnt1.y
      neg Pnt1.y
      mov edx, [xdi].PlotRect.bottom
      add Pnt1.y, edx

      ;Avoid drawing the same line again.
      ;If the previous line has the same endpoints, then skip it
      mov eax, Pnt1.x
      mov ecx, Pnt1.y
      cmp eax, PrvPnt0.x
      jne @F
      cmp ecx, PrvPnt0.y
      lea xdx, PrvPnt1                          ;If we have a match with PrvPnt0 => check only PrvPnt1
      je @@CheckNextPnt
    @@:
      cmp eax, PrvPnt1.x
      jne @@DrawLine
      cmp ecx, PrvPnt1.y
      jne @@DrawLine
      lea xdx, PrvPnt0                          ;We have a match with PrvPnt1 => check only PrvPnt0

    @@CheckNextPnt:
      mov eax, Pnt0.x
      mov ecx, Pnt0.y
      cmp eax, [xdx].POINT.x
      jne @@DrawLine
      cmp ecx, [xdx].POINT.y
      jne @@DrawLine
      je @F                                     ;Line match found => skip this line

    @@DrawLine:
      invoke MoveToEx, hDC, Pnt0.x, Pnt0.y, NULL
      invoke LineTo, hDC, Pnt1.x, Pnt1.y
      s2s PrvPnt0, Pnt0, xax, xcx, xmm0
      s2s PrvPnt1, Pnt1, xax, xcx, xmm0
      jmp @F
    @NextLine4:
      fUnload
    @NextLine3:
      fUnload 3
    @@:
      dec dDataIndex
      mov eax, dDataIndex
    .endw
    invoke DeleteObject, $invoke(SelectObject, hDC, hPrvPen)
  .endif

  ;Draw the markers
  .ifBitSet [xsi].dFlags, CHT_SERIES_SHOW_MARKER
    .ifBitSet [xdi].dFlags, CHT_WND_COLOR
      mov eax, [xsi].Setup.MarkerBorderColor
    .else
      mov eax, $RGB(000,000,000)
    .endif
    invoke CreatePen, PS_SOLID, [xsi].Setup.dMarkerBorderWidth, eax
    mov hPrvPen, $invoke(SelectObject, hDC, xax)
    .ifBitSet [xdi].dFlags, CHT_WND_COLOR
      mov eax, [xsi].Setup.MarkerFillColor
    .else
      mov eax, $RGB(255,255,255)
    .endif
    invoke CreateSolidBrush, eax
    mov hPrvBrush, $invoke(SelectObject, hDC, xax)

    mov eax, [xsi].dDataFrom
    add eax, [xsi].dDataCount
    dec eax
    mov dDataIndex, eax
    .while (SDWORD ptr eax >= [xsi].dDataFrom)
      OCall xsi::ChartXYSeries.ItemAt, 0, dDataIndex

      fld CHT_FLOAT ptr [xax]
      fsub [xdi].ScaleX.fScaleMin
      fmul [xdi].ScaleX.fScaleFactor
      fistp Pnt0.x
      mov edx, [xdi].PlotRect.left
      add Pnt0.x, edx
      fld CHT_FLOAT ptr [xax + sizeof(CHT_FLOAT)]
      fsub [xbx].CHT_SCALE_DATA.fScaleMin
      fmul [xbx].CHT_SCALE_DATA.fScaleFactor
      fistp Pnt0.y
      neg Pnt0.y
      mov edx, [xdi].PlotRect.bottom
      add Pnt0.y, edx

      ;Check if any part of the marker is visible
      mov ecx, Pnt0.x
      mov edx, [xsi].Setup.dMarkerSize
      shr edx, 1
      lea eax, [ecx + edx]                              ;eax = marker right border
      cmp eax, [xdi].PlotRect.left
      jl @F
      sub ecx, edx                                      ;ecx = marker left border
      cmp ecx, [xdi].PlotRect.right
      jg @F
      mov ecx, Pnt0.y
      lea eax, [ecx + edx]                              ;eax = marker bottom border
      cmp eax, [xdi].PlotRect.top
      jl @F
      sub ecx, edx                                      ;eax = marker top border
      cmp ecx, [xdi].PlotRect.bottom
      jg @F
      OCall xsi.DrawMarkerAt, hDC, Pnt0.x, Pnt0.y

      ;Create an ChartInfoArea for each visible marker
      MemAlloc sizeof(ChartInfoArea)
      OCall [xdi].InfoAreas::DataCollection.Insert, xax

      ;Calc bounding square RECT
      mov edx, [xsi].Setup.dMarkerSize
      mov ecx, Pnt0.x
      shr edx, 1
      sub ecx, edx
      mov [xax].ChartInfoArea.Rect.left, ecx
      add ecx, [xsi].Setup.dMarkerSize
      mov [xax].ChartInfoArea.Rect.right, ecx
      mov ecx, Pnt0.y
      sub ecx, edx
      mov [xax].ChartInfoArea.Rect.top, ecx
      add ecx, [xsi].Setup.dMarkerSize
      mov [xax].ChartInfoArea.Rect.bottom, ecx

      ;Save additional information
      m2m [xax].ChartInfoArea.dDataIndex, dDataIndex, ecx
      mov [xax].ChartInfoArea.pSeries, xsi

    @@:
      dec dDataIndex
      mov eax, dDataIndex
    .endw
    invoke DeleteObject, $invoke(SelectObject, hDC, hPrvPen)
    invoke DeleteObject, $invoke(SelectObject, hDC, hPrvBrush)
  .endif

  invoke SelectClipRgn, hDC, hPrevRgn
  invoke DeleteObject, hRgn
  assume xdi:NOTHING
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     ChartXYSeries.GetSetupDialogTab
; Purpose:    Creates a new Tab dialog for this series.
; Arguments:  Arg1: Parent window HANDLE.
;             Arg2: -> MaskedImageList.
; Return:     xax -> ChartXYTabSeries.

ifdef INCLUDE_CHART_SETUP_DIALOG
Method ChartXYSeries.GetSetupDialogTab, uses xbx, hParent:HWND, pImageList:$ObjPtr(MaskedImageList)
  ;Create a new modeless dialog
  ;It is destroyed when it is disposed from the parent collection.
  mov xbx, $New(ChartXYTabSeries)
  OCall xbx::ChartXYTabSeries.Init, pSelf, hParent, pImageList
  mov xax, xbx
MethodEnd
endif

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     ChartXYSeries.Load
; Purpose:    Load buffer data from a stream object.
; Arguments:  Arg1 -> Stream object.
; Return:     Nothing.

Method ChartXYSeries.Load, uses xsi, pStream:$ObjPtr(Stream)
  SetObject xsi
  ACall xsi.Load, pStream
  OCall pStream::Stream.BinRead, addr [xsi].Setup, sizeof(SeriesSetupXY)
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     ChartXYSeries.Store
; Purpose:    Store buffer data to a stream object.
; Arguments:  Arg1: -> Stream object.
; Return:     Nothing.

Method ChartXYSeries.Store, uses xsi, pStream:$ObjPtr(Stream)
  SetObject xsi
  ACall xsi.Store, pStream
  OCall pStream::Stream.BinWrite, addr [xsi].Setup, sizeof(SeriesSetupXY)
MethodEnd
