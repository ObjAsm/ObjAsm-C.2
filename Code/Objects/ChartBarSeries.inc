; ==================================================================================================
; Title:      ChartBarSeries.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm support of ChartBarSeries objects.
; Notes:      Version 1.0.0, August 2021
; ==================================================================================================



; ==================================================================================================
;    ChartBarSeries implementation
; ==================================================================================================

; --------------------------------------------------------------------------------------------------
; Method:     ChartBarSeries.Draw
; Purpose:    Draw the series bar representation.
; Arguments:  Arg1: hDC.
; Return:     Nothing.

Method ChartBarSeries.Draw, uses xbx xdi xsi, hDC:HDC
  local hRgn:HRGN, hPrevRgn:HRGN, hPrvPen:HPEN, hPrvBrush:HBRUSH
  local Pnt:POINT, Bounds:RECT, Intersection:RECT

  SetObject xsi
  mov xcx, [xsi].pOwner
  mov xdi, [xcx].$Obj(Collection).pOwner
  assume xdi:$ObjPtr(ChartWnd)

  ;Clip drowing to the plotarea
  invoke GetClipRgn, hDC, hPrevRgn
  mov hRgn, $invoke(CreateRectRgn, [xdi].PlotRect.left,  [xdi].PlotRect.top, \
                                   [xdi].PlotRect.right, [xdi].PlotRect.bottom)
  invoke SelectClipRgn, hDC, hRgn

  .ifBitSet [xsi].dFlags, CHT_SERIES_SHOW_DEPICTION
    .ifBitSet [xdi].dFlags, CHT_WND_COLOR
      mov eax, [xsi].Setup.BorderColor
    .else
      mov eax, $RGB(000,000,000)
    .endif
    invoke CreatePen, [xsi].Setup.dBorderStyle, [xsi].Setup.dBorderWidth, eax
    mov hPrvPen, $invoke(SelectObject, hDC, xax)

    .if [xsi].Setup.dFillStyle == BAR_FILL_STYLE_SOLID
      .ifBitSet [xdi].dFlags, CHT_WND_COLOR
        mov eax, [xsi].Setup.FillColorBack
      .else
        mov eax, $RGB(255,255,255)
      .endif
      invoke CreateSolidBrush, eax
    .else
      .ifBitSet [xdi].dFlags, CHT_WND_COLOR
        invoke SetBkMode, hDC, OPAQUE
        invoke SetBkColor, hDC, [xsi].Setup.FillColorBack
        invoke CreateHatchBrush, [xsi].Setup.dFillStyle, [xsi].Setup.FillColorFore
      .else
        invoke SetBkMode, hDC, OPAQUE
        invoke SetBkColor, hDC, $RGB(255,255,255) 
        invoke CreateHatchBrush, [xsi].Setup.dFillStyle, $RGB(000,000,000)
      .endif
    .endif
    mov hPrvBrush, $invoke(SelectObject, hDC, xax)

    mov ebx, [xsi].dDataFrom
    add ebx, [xsi].dDataCount
    dec ebx

    fld [xdi].ScaleX.fScaleMin
    fld [xdi].ScaleX.fScaleFactor
    .ifBitClr [xsi].dFlags, CHT_SERIES_USE_Y2
      fld [xdi].ScaleY1.fScaleMin
      fld [xdi].ScaleY1.fScaleFactor        ;Y1.fScaleFactor|Y1.fScaleMin|X.fScaleFactor|X.fScaleMin
    .else
      fld [xdi].ScaleY2.fScaleMin
      fld [xdi].ScaleY2.fScaleFactor        ;Y2.fScaleFactor|Y2.fScaleMin|X.fScaleFactor|X.fScaleMin
    .endif

    .while (SDWORD ptr ebx >= [xsi].dDataFrom)
      OCall xsi::ChartBarSeries.ItemAt, 0, ebx
      fld CHT_FLOAT ptr [xax + 1*sizeof(CHT_FLOAT)]     ;Y
      fsub st(0), st(2)
      fmul st(0), st(1)
      fistp Bounds.top
      neg Bounds.top
      mov edx, [xdi].PlotRect.bottom
      add Bounds.top, edx

      fldz
      fsub st(0), st(2)
      fmul st(0), st(1)
      fistp Bounds.bottom
      neg Bounds.bottom
      mov edx, [xdi].PlotRect.bottom
      add Bounds.bottom, edx

      fld CHT_FLOAT ptr [xax]                           ;X
      fsub st(0), st(4)
      fmul st(0), st(3)
      fistp Pnt.x
      mov edx, [xdi].PlotRect.left
      add edx, [xsi].Setup.sdBarOffset
      add Pnt.x, edx

      mov ecx, [xsi].Setup.dBarWidth
      mov eax, ecx
      shr ecx, 1
      mov edx, Pnt.x
      sub edx, ecx
      mov Bounds.left, edx
      add edx, eax
      mov Bounds.right, edx

      invoke Rectangle, hDC, Bounds.left, Bounds.top, Bounds.right, Bounds.bottom

      ;Check if any part of the bar is visible taking the border into account
      mov ecx, [xsi].Setup.dBorderWidth
      shr ecx, 1
      sub Bounds.left, ecx
      mov edx, Bounds.left
      add edx, [xsi].Setup.dBarWidth
      add edx, [xsi].Setup.dBorderWidth
      mov Bounds.right, edx

      mov edx, Bounds.bottom
      sub edx, Bounds.top
      sub Bounds.top, ecx
      mov ecx, Bounds.top
      add ecx, edx
      add ecx, [xsi].Setup.dBorderWidth
      mov Bounds.bottom, ecx

      ;Create an ChartInfoArea for each visible bar
      invoke IntersectRect, addr Intersection, addr [xdi].PlotRect, addr Bounds
      .if eax != 0
        MemAlloc sizeof(ChartInfoArea)                                          ;§§§
        OCall [xdi].InfoAreas::DataCollection.Insert, xax
        s2s [xax].ChartInfoArea.Rect, Intersection, xcx, xdx, xmm0, xmm1
        ;Save additional information
        mov [xax].ChartInfoArea.pSeries, xsi
        mov [xax].ChartInfoArea.dDataIndex, ebx
      .endif
      dec ebx
    .endw
    fUnload 4
    invoke DeleteObject, $invoke(SelectObject, hDC, hPrvBrush)
    invoke DeleteObject, $invoke(SelectObject, hDC, hPrvPen)
  .endif

  invoke SelectClipRgn, hDC, hPrevRgn
  invoke DeleteObject, hRgn
  assume xdi:NOTHING
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     ChartBarSeries.GetSetupDialogTab
; Purpose:    Creates a new Tab dialog for this series.
; Arguments:  Arg1: Parent window HANDLE.
;             Arg2: -> MaskedImageList.
; Return:     xax -> ChartBarTabSeries.

ifdef INCLUDE_CHART_SETUP_DIALOG
Method ChartBarSeries.GetSetupDialogTab, uses xbx, hParent:HWND, pImageList:$ObjPtr(MaskedImageList)
  ;Create a new modeless dialog
  ;It is destroyed when it is disposed from the parent collection.
  mov xbx, $New(ChartBarTabSeries)
  OCall xbx::ChartBarTabSeries.Init, pSelf, hParent, pImageList
  mov xax, xbx
MethodEnd
endif

; --------------------------------------------------------------------------------------------------
; Method:     ChartBarSeries.Load
; Purpose:    Load buffer data from a stream object.
; Arguments:  Arg1: -> Stream object.
; Return:     Nothing.

Method ChartBarSeries.Load, uses xsi, pStream:$ObjPtr(Stream)
  SetObject xsi
  ACall xsi.Load, pStream
  OCall pStream::Stream.BinRead, addr [xsi].Setup, sizeof(SeriesSetupBar)
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:    ChartBarSeries.Scan
; Purpose:   Scan the buffers X and Y data to find the min and max values => Min & Max indices are set.
; Arguments: Arg1: First element index, starting from 0 to dCapacity - 1.
;            Arg2: Element count.
; Return:    Nothing.

Method ChartBarSeries.Scan, uses xbx xdi xsi, dFrom:DWORD, dCount:DWORD
  local dMaxX:DWORD, dMinX:DWORD, dMaxY:DWORD, dMinY:DWORD

  SetObject xsi
  mov edi, dCount
  .if edi != 0
    mov ebx, dFrom
    mov dMaxX, edi
    mov dMinX, edi
    mov dMaxY, edi
    mov dMinY, edi
    shl ebx, 1 + $Log2(sizeof(CHT_FLOAT))
    add xbx, [xsi].pData

    fld CHT_FLOAT ptr [xbx]                               ;Load first X data
    fld st(0)                                             ;Copy it
    fld CHT_FLOAT ptr [xbx + sizeof(CHT_FLOAT)]           ;Load first Y data
    fld st(0)                                             ;Copy it
    dec edi
    .while !ZERO?                                         ; MaxY | MinY | MaxX | MinX
      add xbx, 2*sizeof(CHT_FLOAT)
      fld CHT_FLOAT ptr [xbx]                             ;  X  | MaxY | MinY | MaxX | MinX
      fcomi st(0), st(3)                                  ;Compare with maximum
      .if !CARRY?                                         ;st(0) > st(1)
        mov dMaxX, edi
        fst st(3)                                         ;Store new max
      .endif
      fcomi st(0), st(4)                                  ;Compare with minimum
      .if CARRY?                                          ;st(0) < st(1)
        mov dMinX, edi
        fst st(4)                                         ;Store new min
      .endif
      fUnload 1                                           ; MaxY | MinY | MaxX | MinX

      fld CHT_FLOAT ptr [xbx + sizeof(CHT_FLOAT)]         ;  Y  | MaxY | MinY | MaxX | MinX
      fcomi st(0), st(1)                                  ;Compare with maximum
      .if !CARRY?                                         ;st(0) > st(1)
        mov dMaxY, edi
        fst st(1)                                         ;Store new max
      .endif
      fcomi st(0), st(2)                                  ;Compare with minimum
      .if CARRY?                                          ;st(0) < st(1)
        mov dMinX, edi
        fst st(2)                                         ;Store new min
      .endif
      fUnload 1                                           ; MaxY | MinY | MaxX | MinX

      dec edi
    .endw
    fUnload 4                                             ;Unload FPU stack

    mov edx, dCount
    mov ecx, dFrom

    mov eax, edx
    sub eax, dMaxX                                        ;Calculate index of max data X
    add eax, ecx
    mov [xsi].dDataMaxXIndex, eax
    mov eax, edx
    sub eax, dMinX                                        ;Calculate index of min data X
    add eax, ecx
    mov [xsi].dDataMinXIndex, eax

    mov eax, edx
    sub eax, dMaxY                                        ;Calculate index of max data Y
    add eax, ecx
    mov [xsi].dDataMaxYIndex, eax
    sub edx, dMinY                                        ;Calculate index of min data Y
    add edx, ecx
    mov [xsi].dDataMinYIndex, edx

  .else
    mov ecx, -1
    mov [xsi].dDataMaxXIndex, ecx
    mov [xsi].dDataMinXIndex, ecx
    mov [xsi].dDataMaxYIndex, ecx
    mov [xsi].dDataMinYIndex, ecx
  .endif

MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     ChartBarSeries.Store
; Purpose:    Store buffer data to a stream object.
; Arguments:  Arg1: -> Stream object.
; Return:     Nothing.

Method ChartBarSeries.Store, uses xsi, pStream:$ObjPtr(Stream)
  SetObject xsi
  ACall xsi.Store, pStream
  OCall pStream::Stream.BinWrite, addr [xsi].Setup, sizeof(SeriesSetupBar)
MethodEnd
