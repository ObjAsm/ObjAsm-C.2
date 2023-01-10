; ==================================================================================================
; Title:      ChartSeries.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm support of ChartSeries objects.
; Notes:      Version 1.0.0, August 2021
;               - First release.
;               - OCall ChartSeries.ItemAt, Element(X, Y), Index(0..DATACOUNT-1)
; ==================================================================================================



; ==================================================================================================
;    ChartSeries implementation
; ==================================================================================================

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     ChartSeries.Done
; Purpose:    Finalize the ChartSeries object.
; Arguments:  None.
; Return:     Nothing.

Method ChartSeries.Done, uses xsi
  SetObject xsi
  invoke StrDispose, [xsi].pName
  invoke StrDispose, [xsi].pDescription
  ACall xsi.Done
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     ChartSeries.GetToolTipText
; Purpose:    Return a string inforation about data.
; Arguments:  Arg1: -> Destination buffer. Max 1024 chars.
;             Arg2: Data index into ChartSeries.
; Return:     Nothing.

Method ChartSeries.GetToolTipText, uses xbx xdi xsi, pBuffer:PSTRING, dDataIndex:DWORD
  local cStrBufferX[20]:CHR, cStrBufferY[20]:CHR

  SetObject xsi
  OCall xsi.ItemAt, 0, dDataIndex
  fld CHT_FLOAT ptr [xax]
  fld CHT_FLOAT ptr [xax + sizeof(CHT_FLOAT)]
  invoke St0ToStr, addr cStrBufferY, 0, 7, f_NOR or f_TRIM
  fUnload
  invoke St0ToStr, addr cStrBufferX, 0, 7, f_NOR or f_TRIM
  fUnload

  mov xcx, [xsi].pOwner
  mov xdx, [xcx].$Obj(Collection).pOwner
  mov xbx, [xdx].$Obj(ChartWnd).ScaleX.pUnit
  .ifBitClr [xsi].dFlags, CHT_SERIES_USE_Y2
    mov xdi, [xdx].$Obj(ChartWnd).ScaleY1.pUnit
  .else
    mov xdi, [xdx].$Obj(ChartWnd).ScaleY2.pUnit
  .endif
    
  invoke wsprintf, pBuffer, $OfsCStr("Series Name: %s", CRLF, "Description: %s", CRLF, \
                                     "  X = %s %s", CRLF, "  Y = %s %s"), \
                   [xsi].pName, [xsi].pDescription, \
                   addr cStrBufferX, xbx, addr cStrBufferY, xdi
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     ChartSeries.Init
; Purpose:    Initialize the ChartSeries object.
; Arguments:  Arg1: -> Owner object = ChartWnd.Data
;             Arg2: Capacity in data points.
; Return:     Nothing.

Method ChartSeries.Init, uses xsi, pOwner:POINTER, dCapacity:DWORD
  SetObject xsi
  ACall xsi.Init, pOwner, sizeof(CHT_FLOAT)
  OCall xsi.DimAppend, 2, ARR_MEM_ZERO                  ;X:0, Y:1
  OCall xsi.DimAppend, dCapacity, ARR_MEM_ZERO          ;data
  OCall pOwner::Collection.Insert, xsi
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     ChartSeries.Load
; Purpose:    Load buffer data from a stream object.
; Arguments:  Arg1 -> Stream object.
; Return:     Nothing.

Method ChartSeries.Load, uses xsi, pStream:$ObjPtr(Stream)
  SetObject xsi
  ACall xsi.Load, pStream
  mov [xsi].pName, $OCall(pStream::Stream.StrRead)
  mov [xsi].pDescription, $OCall(pStream::Stream.StrRead)
  mov [xsi].dDataMaxXIndex, $32($OCall(pStream::Stream.BinRead32))
  mov [xsi].dDataMinXIndex, $32($OCall(pStream::Stream.BinRead32))
  mov [xsi].dDataMaxYIndex, $32($OCall(pStream::Stream.BinRead32))
  mov [xsi].dDataMinXIndex, $32($OCall(pStream::Stream.BinRead32))
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:    ChartSeries.Scan
; Purpose:   Scan the buffers X and Y data to find the min and max values => Min & Max indices are set.
; Arguments: Arg1: First element index, starting from 0 to dCapacity - 1.
;            Arg2: Element count.
; Return:    Nothing.

Method ChartSeries.Scan, uses xbx xdi xsi, dFrom:DWORD, dCount:DWORD
  local dMaxX:DWORD, dMinX:DWORD, dMaxY:DWORD, dMinY:DWORD      ;They are all indices

  SetObject xsi
  .if dCount != 0
    mov edi, dFrom
    mov dMaxX, edi
    mov dMinX, edi
    mov dMaxY, edi
    mov dMinY, edi

    mov xbx, $OCall(xsi.ItemAt, 0, edi)
    fld CHT_FLOAT ptr [xbx]                               ;Load first X data
    fld st(0)                                             ;Copy it
    fld CHT_FLOAT ptr [xbx + sizeof(CHT_FLOAT)]           ;Load first Y data
    fld st(0)                                             ;Copy it

    mov edi, 1                                            ;First values are just loaded
    .while edi < dCount                                   ; MaxY | MinY | MaxX | MinX
      add xbx, 2*sizeof(CHT_FLOAT)
      fld CHT_FLOAT ptr [xbx]                             ;  X  | MaxY | MinY | MaxX | MinX
      fcomi st(0), st(3)                                  ;Compare with maximum
      .if !CARRY?                                         ;st(0) > st(1)
        mov dMaxX, edi                                    ;Store relative index
        fst st(3)                                         ;Store new max
      .endif
      fcomi st(0), st(4)                                  ;Compare with minimum
      .if CARRY?                                          ;st(0) < st(1)
        mov dMinX, edi                                    ;Store relative index
        fst st(4)                                         ;Store new min
      .endif
      fUnload 1                                           ; MaxY | MinY | MaxX | MinX

      fld CHT_FLOAT ptr [xbx + sizeof(CHT_FLOAT)]         ;  Y  | MaxY | MinY | MaxX | MinX
      fcomi st(0), st(1)                                  ;Compare with maximum
      .if !CARRY?                                         ;st(0) > st(1)
        mov dMaxY, edi                                    ;Store relative index
        fst st(1)                                         ;Store new max
      .endif
      fcomi st(0), st(2)                                  ;Compare with minimum
      .if CARRY?                                          ;st(0) < st(1)
        mov dMinY, edi                                    ;Store relative index
        fst st(2)                                         ;Store new min
      .endif
      fUnload 1                                           ; MaxY | MinY | MaxX | MinX

      inc edi
    .endw
    fUnload 4                                             ;Unload FPU stack

    mov ecx, dFrom

    mov eax, dMaxX                                        ;Calculate index of max data X
    add eax, ecx
    mov [xsi].dDataMaxXIndex, eax
    mov eax, dMinX                                        ;Calculate index of min data X
    add eax, ecx
    mov [xsi].dDataMinXIndex, eax

    mov eax, dMaxY                                        ;Calculate index of max data Y
    add eax, ecx
    mov [xsi].dDataMaxYIndex, eax
    add ecx, dMinY                                        ;Calculate index of min data Y
    mov [xsi].dDataMinYIndex, ecx

  .else
    mov ecx, -1
    mov [xsi].dDataMaxXIndex, ecx
    mov [xsi].dDataMinXIndex, ecx
    mov [xsi].dDataMaxYIndex, ecx
    mov [xsi].dDataMinYIndex, ecx
  .endif

MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     ChartSeries.Store
; Purpose:    Store buffer data to a stream object.
; Arguments:  Arg1: -> Stream object.
; Return:     Nothing.

Method ChartSeries.Store, uses xsi, pStream:$ObjPtr(Stream)
  SetObject xsi
  ACall xsi.Store, pStream
  OCall pStream::Stream.StrWrite, [xsi].pName
  OCall pStream::Stream.StrWrite, [xsi].pDescription
  OCall pStream::Stream.BinWrite32, [xsi].dDataMaxXIndex
  OCall pStream::Stream.BinWrite32, [xsi].dDataMinXIndex
  OCall pStream::Stream.BinWrite32, [xsi].dDataMaxYIndex
  OCall pStream::Stream.BinWrite32, [xsi].dDataMinYIndex
MethodEnd
