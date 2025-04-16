; ==================================================================================================
; Title:      Fireworks.inc
; Author:     G. Friedrich
; Version:    1.0.0
; Purpose:    ObjAsm support of Fireworks objects.
; Notes:      Version 1.0.0, July 2006
;              - First release.
; ==================================================================================================


FRAMERATE       equ   30                    ;Target framerate in frames per second
FireworksID     equ   123456                ;Random number
FWK_OUTOFMEMORY equ   1256987               ;Random number

FWK_Mode  record  FWK_Unused:29 = 0,   \    ;Unused bits
                  FWK_GMode:1 = 0,     \    ;Atmosphere or outer-space
                  FWK_CMode:1 = 0,     \    ;Color shifter
                  FWK_EMode:1 = 0           ;Special effects


; --------------------------------------------------------------------------------------------------
; Object:     Fireworks
; Purpose:    Implement a GDI based firework using MMX technology.

Object Fireworks, FireworksID, Primer
  StaticMethod    Blur
  RedefineMethod  Done
  StaticMethod    FireShellExpodeAG,  POINTER
  StaticMethod    FireShellExpodeOS,  POINTER
  StaticMethod    FireShellRecycle,   POINTER, DWORD, DWORD
  StaticMethod    FireShellRender,    POINTER, DWORD
  StaticMethod    FireThread
  StaticMethod    Flash,              DWORD, DWORD, DWORD
  RedefineMethod  Init,               POINTER, HWND, PRECT

  DefineVariable  hOutputWnd,         HWND,       0
  DefineVariable  OutputRect,         RECT,       {0, 0, 0, 0}
  DefineVariable  dWidth,             DWORD,      0             ;Must be a multiple of 4
  DefineVariable  dHeight,            DWORD,      0
  DefineVariable  hDC,                HDC,        0
  DefineVariable  hFireThread,        HANDLE,     0
  DefineVariable  dTerminate,         DWORD,      FALSE         ;Thread finalization flag
  DefineVariable  pFireShellsMemory,  POINTER,    NULL          ;FireShell memory block
  DefineVariable  dFireShellCount,    DWORD,      5
  DefineVariable  dFireShellSparks,   DWORD,      200           ;Sparks per FireShell
  DefineVariable  dFireShellSize,     DWORD,      0
  DefineVariable  dMode,              FWK_Mode,   {0, 1, 0, 1}
  DefineVariable  dFrameCount,        DWORD,      0
  DefineVariable  BmpInfo,            BITMAPINFO, {{40, 0, 0, 1, 24, 0, 0, 0, 0, 0, 0}}
  DefineVariable  pPixelMemBlock,     POINTER,    NULL          ;Memory block for both Pixelfields
  DefineVariable  pPixelfield1,       POINTER,    NULL          ;-> Source Pixelfield
  DefineVariable  pPixelfield2,       POINTER,    NULL          ;-> Destination Pixelfield
  DefineVariable  LightPosition,      POINT,      {0, 0}
  DefineVariable  dFlashIntensity,    DWORD,      0
  DefineVariable  r4FlashFactor,      REAL4,      0.92
  DefineVariable  dMaxPower,          DWORD,      5
  DefineVariable  dMinLife,           DWORD,      500
  DefineVariable  dFadeLevel,         DWORD,      1
  DefineVariable  r4Gravity,          REAL4,      0.00024
  DefineVariable  r4XCut,             REAL4,      0.00064
  DefineVariable  dMotion,            DWORD,      16

  Embed   RenderWatch,    StopWatch
ObjectEnd

; ==================================================================================================

if IMPLEMENT

.const
Fireworks_ChemTable DWORD $RGB(000h, 0E0h, 0A0h, 0FFh), \
                          $RGB(000h, 0F0h, 080h, 030h), \
                          $RGB(000h, 0E6h, 0C0h, 080h), \
                          $RGB(000h, 040h, 0B0h, 070h), \
                          $RGB(000h, 0AAh, 0D5h, 080h)

Spark struc
  r4X       REAL4   ?                       ;Position
  r4Y       REAL4   ?
  r4XVel    REAL4   ?                       ;Velocity
  r4YVel    REAL4   ?
Spark ends

FireShellHeader struc
  Position  POINT   {?, ?}
  dLife     DWORD   ?
  r4Air     REAL4   ?
FireShellHeader ends

;FireShell struc
;  FireShellHeader {}
;  Spark1  Spark   {}                       ;Array of Sparks
;  Spark2  Spark   {}
;  ...
;FireShell ends

externdef dRandomSeed:DWORD                 ;ObjMem32.lib

.code
; --------------------------------------------------------------------------------------------------
; Method:     Fireworks.Blur
; Purpose:    Blur MMX algo for 24bit color bitmaps.
; Arguments:  None.
; Return:     Nothing.

Method Fireworks.Blur, uses xbx xdi xsi
  local qFadeLevels:QWORD, dScanLineByteCount:DWORD

  SetObject xcx
  ;Swap pointers
  mov xdi, [xcx].pPixelfield2
  mov xsi, [xcx].pPixelfield1
  mov [xcx].pPixelfield1, xdi
  mov [xcx].pPixelfield2, xsi

  pxor MM7, MM7
  mov eax, [xcx].dFadeLevel
  imul eax, 00010001h
  mov DWORD ptr [qFadeLevels], eax
  mov DWORD ptr [qFadeLevels + sizeof(DWORD)], eax
  movq MM6, qFadeLevels
  mov eax, [xcx].dWidth
  lea eax, [eax + eax*2]                                ;*3
  mov ebx, eax
  imul [xcx].dHeight
  mov dScanLineByteCount, eax
  lea edx, [ebx - 3]
  add ebx, 3
  neg xdx
  xor eax, eax
  sub xsi, 3
  ReleaseObject

  align ALIGN_CODE
  .repeat
    movd MM0, [xsi]                                     ;Code enlarged version
    punpcklbw MM0, MM7                                  ; optimized for speed, not size
    movd MM1, [xsi + 8]
    movd MM2, [xsi + 16]
    punpcklbw MM1, MM7
    punpcklbw MM2, MM7

    movd MM3, [xsi + 6]
    movd MM4, [xsi + 14]
    movd MM5, [xsi + 22]
    punpcklbw MM3, MM7
    paddw MM0, MM3
    punpcklbw MM4, MM7
    paddw MM1, MM4
    punpcklbw MM5, MM7
    paddw MM2, MM5

    movd MM3, [xsi + xbx]
    punpcklbw MM3, MM7
    paddw MM0, MM3
    movd MM4, [xsi + xbx + 8]
    movd MM5, [xsi + xbx + 16]
    punpcklbw MM4, MM7
    paddw MM1, MM4
    punpcklbw MM5, MM7
    paddw MM2, MM5

    movd MM3, [xsi + xdx]
    punpcklbw MM3, MM7
    paddw MM0, MM3
    movd MM4, [xsi + xdx + 8]
    movd MM5, [xsi + xdx + 16]
    punpcklbw MM4, MM7
    paddw MM1, MM4
    punpcklbw MM5, MM7
    paddw MM2, MM5

    psrlw MM0, 2                                        ;Neigbours only, i.e. smoky blur
    psrlw MM1, 2
    psrlw MM2, 2
    psubusw MM0, MM6                                    ;Fade
    psubusw MM1, MM6
    psubusw MM2, MM6
    packuswb MM0, MM7
    add xsi, 12
    packuswb MM1, MM7
    packuswb MM2, MM7
    movd [xdi + xax], MM0
    movd [xdi + xax + 8], MM1
    movd [xdi + xax + 16], MM2
    add eax, 12
  .until eax > dScanLineByteCount
  emms                                                  ;Free MMX registers for fp computations
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Fireworks.Done
; Purpose:    Finalize the Fireworks object.
; Arguments:  None.
; Return:     Nothing.

Method Fireworks.Done, uses xsi
  SetObject xsi
  mov [xsi].dTerminate, TRUE                            ;Set Termination flag
  invoke WaitForSingleObject, [xsi].hFireThread, 1000
  .if eax == WAIT_TIMEOUT
    DbgWarning "Timeout: terminating fireworks thread"
    invoke TerminateThread, [xsi].hFireThread, -1
  .endif

  ;Start Housekeeping
  .if [xsi].pPixelMemBlock != NULL
    MemFree [xsi].pPixelMemBlock
  .endif
  .if [xsi].pFireShellsMemory != NULL
    MemFree [xsi].pFireShellsMemory
  .endif
  invoke CloseHandle, [xsi].hFireThread
  OCall [xsi].RenderWatch::StopWatch.Done
  invoke ReleaseDC, [xsi].hOutputWnd, [xsi].hDC

  ACall xsi.Done
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Fireworks.FireShellExpodeAG
; Purpose:    Explosion effect with Air and Gravity.
; Arguments:  Arg1: -> FireShell.
; Return:     eax = Remaining life.

Method Fireworks.FireShellExpodeAG, uses xdi, pFireShell:POINTER
  SetObject xcx
  mov xdi, pFireShell
  fld [xcx].r4Gravity                                   ;Acceleration due to gravity
  fld [xdi].FireShellHeader.r4Air                       ;Air resistance
  add xdi, sizeof FireShellHeader
  mov eax, [xcx].dFireShellSparks
  dec eax
  shl eax, 4
  add xdi, xax

  align ALIGN_CODE
  .repeat
    fld [xdi].Spark.r4XVel                              ;x velocity
    fmul st(0), st(1)                                   ;Deceleration by air
    fst [xdi].Spark.r4XVel
    fadd [xdi].Spark.r4X                                ;x coordinate
    fstp [xdi].Spark.r4X
    fld [xdi].Spark.r4YVel                              ;y velocity
    fmul st(0), st(1)                                   ;Deceleration by air
    fadd st(0), st(2)                                   ;Gravity
    fst [xdi].Spark.r4YVel
    fadd [xdi].Spark.r4Y                                ;y coordinate
    fstp [xdi].Spark.r4Y
    sub xdi, sizeof(Spark)
    sub xax, sizeof(Spark)
  .until CARRY?
  fUnload 2
  dec [xdi - sizeof FireShellHeader + sizeof(Spark)].FireShellHeader.dLife
  mov eax, [xdi - sizeof FireShellHeader + sizeof(Spark)].FireShellHeader.dLife  ;Return life
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Fireworks.FireShellExpodeOS
; Purpose:    Explosion effect i Outer Space.
; Arguments:  Arg1: -> FireShell.
; Return:     eax = Remaining life.

Method Fireworks.FireShellExpodeOS, uses xdi, pFireShell:POINTER
  SetObject xcx
  mov xdi, pFireShell
  add xdi, sizeof FireShellHeader
  mov eax, [xcx].dFireShellSparks
  dec eax
  shl eax, $Log2(sizeof(Spark))
  add xdi, xax

  align ALIGN_CODE
  .repeat
    fld [xdi].Spark.r4X                                 ;x coordinate
    fadd [xdi].Spark.r4XVel                             ;x velocity
    fstp [xdi].Spark.r4X
    fld [xdi].Spark.r4Y                                 ;y coordinate
    fadd [xdi].Spark.r4YVel                             ;y velocity
    fstp [xdi].Spark.r4Y
    sub xdi, sizeof(Spark)
    sub xax, sizeof(Spark)
  .until CARRY?
  dec [xdi - sizeof FireShellHeader + sizeof(Spark)].FireShellHeader.dLife
  mov eax, [xdi - sizeof FireShellHeader + sizeof(Spark)].FireShellHeader.dLife  ;Return life
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Fireworks.FireShellRecycle
; Purpose:    Recycle fire shell.
; Arguments:  Arg1: -> FireShell.
;             Arg2: X position.
;             Arg3: Y position.
; Return:     Nothing.

Method Fireworks.FireShellRecycle, uses xbx xdi xsi, pFireShell:POINTER, dx1:DWORD, dy1:DWORD
  local dVar1:DWORD, dVar2:DWORD

  SetObject xsi
  mov xdi, pFireShell
  mov eax, dx1
  mov [xdi].FireShellHeader.Position.x, eax
  mov [xsi].LightPosition.x, eax
  mov eax, dy1
  mov [xdi].FireShellHeader.Position.y, eax
  mov [xsi].LightPosition.y, eax
  mov eax, [xsi].dFlashIntensity                        ;having only one light source
  add eax, 3200                                         ; 3200 million jouls...!
  mov [xsi].dFlashIntensity, eax                        ; add if previous lighting not extinguished

  invoke Random32, 20
  inc eax
  imul [xsi].dMinLife
  mov ebx, eax                                          ;Sync explosions by mouse clicks with rest
  mov eax, [xdi].FireShellHeader.dLife                  ; by maintaining minimum delay of dMminLife'
  xor edx, edx
  idiv [xsi].dMinLife
  add edx, ebx
  mov [xdi].FireShellHeader.dLife, edx

  invoke Random32, 30
  add eax, 10
  mov dVar1, eax
  mov dVar2, 10000
  fld1
  fild dVar1
  fidiv dVar2
  fsubp st(1), st(0)
  fstp [xdi].FireShellHeader.r4Air
  add xdi, sizeof FireShellHeader
  fild dy1
  fild dx1
  mov dVar1, 1000
  fild dVar1                                            ;1000 (constant)
  invoke Random32, [xsi].dMaxPower
  inc eax
  mov dVar1, eax
  fild dVar1                                            ;Power
  mov ebx, [xsi].dFireShellSparks
  dec ebx
  shl ebx, 4
  add xdi, xbx

  align ALIGN_CODE                                      ;Cycle trough all Sparks
  .repeat
    invoke Random32, 2000
    mov dVar2, eax
    fild dVar2
    fsub st(0), st(2)
    fdiv st(0), st(2)
    fmul st(0), st(1)
    fstp [xdi].Spark.r4XVel
    fld st(0)
    fmul st(0), st(0)
    fld [xdi].Spark.r4XVel
    fmul st(0), st(0)
    fsubp st(1), st(0)
    fsqrt
    invoke Random32, 2000
    mov dVar2, eax
    fild dVar2
    fsub st(0), st(3)
    fdiv st(0), st(3)
    fmulp st(1), st(0)
    fstp [xdi].Spark.r4YVel
    fld st(2)
    fstp [xdi].Spark.r4X
    fld st(3)
    fstp [xdi].Spark.r4Y
    sub xdi, sizeof(Spark)
    sub xbx, sizeof(Spark)
  .until CARRY?
  fUnload 2
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Fireworks.FireShellRender
; Purpose:    Render a fire shell.
; Arguments:  Arg1: -> FireShell.
;             Arg2: Color index value.
; Return:     Nothing.

Method Fireworks.FireShellRender, uses xbx xdi xsi, pFireShell:POINTER, dColorIndex:DWORD
  local r4XCut:DWORD, dVar1:DWORD, dVar2:DWORD, dHeight:DWORD, dWidth:DWORD, dFire:DWORD

  SetObject xsi
  mov xdi, pFireShell
  add xdi, sizeof FireShellHeader
  mov ebx, dColorIndex
  dec ebx
  mov xcx, offset Fireworks_ChemTable
  mov xdx, [xsi].pFireShellsMemory                      ;Floats are beautiful, and cheap source of
  add xdx, 32                                           ; the chemical used for multi colored fires
  mov eax, [xsi].dMode
  and eax, mask FWK_CMode
  cmovz xdx, xcx
  mov edx, [xdx + xbx*4]
  mov ecx, [xsi].dFireShellSparks
  dec ecx
  shl ecx, $Log2(sizeof(Spark))
  mov dFire, edx
  m2m dHeight, [xsi].dHeight, eax
  m2m dWidth, [xsi].dWidth, edx
  m2m r4XCut, [xsi].r4XCut, eax
  mov xsi, [xsi].pPixelfield1
  ReleaseObject
  add xdi, xcx

  align ALIGN_CODE
  .repeat
    fld [xdi].Spark.r4XVel
    fabs
    fld r4XCut                                          ;Low cost code for independant burnouts
    fcomip st(0), st(1)
    fistp dVar1
    .if CARRY?
      fld [xdi].Spark.r4X
      fistp dVar1
      fld [xdi].Spark.r4Y
      fistp dVar2
      mov eax, dVar2
      .if eax < dHeight
        mov ebx, dVar1
        .if ebx < dWidth
          imul dWidth
          add eax, ebx
          lea eax, [eax + eax*2]
          mov edx, dFire
          mov [xsi + xax], dx
          shr edx, 16
          mov [xsi + xax + 2], dl
        .endif
      .endif
    .endif
    sub xdi, sizeof(Spark)
    sub xcx, sizeof(Spark)
  .until CARRY?
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Fireworks.FireThread
; Purpose:    Fireworks generation thread.
; Arguments:  None.
; Return:     Nothing.

Method Fireworks.FireThread, uses xbx xdi xsi
  local dHeight:DWORD, dMotion:DWORD

  SetObject xsi
  .if [xsi].dErrorCode == OBJ_OK
    OCall [xsi].RenderWatch::StopWatch.Start
    align ALIGN_CODE
    .repeat
      m2m dMotion, [xsi].dMotion, eax
      align ALIGN_CODE
      .repeat
        mov ebx, [xsi].dFireShellCount                  ;ebx = ColorIndex
        mov xdi, [xsi].pFireShellsMemory
        align ALIGN_CODE
        .repeat
          OCall xsi.FireShellRender, xdi, ebx           ;xdi -> FireShell
          .ifBitSet [xsi].dMode, mask FWK_GMode
            OCall xsi.FireShellExpodeAG, xdi
          .else
            OCall xsi.FireShellExpodeOS, xdi
          .endif
          test eax, eax
          .if SIGN?                                     ;Expired?
            mov dHeight, $32($invoke(Random32, [xsi].dHeight))
            mov eax, [xsi].dWidth
            shl eax, 1
            invoke Random32, eax
            mov edx, [xsi].dWidth
            shr edx, 1
            sub eax, edx
            OCall xsi.FireShellRecycle, xdi, eax, dHeight
          .endif
          mov eax, [xsi].dFireShellSize
          add xdi, xax                                  ;Move to next FireShell
          dec ebx
        .until ZERO?
        dec dMotion
      .until ZERO?

      .ifBitSet [xsi].dMode, mask FWK_EMode
        .ifBitSet [xsi].dMode, mask FWK_CMode           ;Switch pre/post blur according to -
          OCall xsi.Blur                                ; current chemical in fire
        .endif
        OCall xsi.Flash, [xsi].LightPosition.x, [xsi].LightPosition.y, [xsi].dFlashIntensity
        invoke SetDIBitsToDevice, [xsi].hDC, [xsi].OutputRect.left, [xsi].OutputRect.top, \
                                  [xsi].OutputRect.right, [xsi].OutputRect.bottom, \
                                  0, 0, 0, [xsi].dHeight, \
                                  [xsi].pPixelfield2, addr [xsi].BmpInfo, DIB_RGB_COLORS
        .ifBitClr [xsi].dMode, mask FWK_CMode
          OCall xsi.Blur
        .endif
      .else
        invoke SetDIBitsToDevice, [xsi].hDC, [xsi].OutputRect.left, [xsi].OutputRect.top, \
                                  [xsi].OutputRect.right, [xsi].OutputRect.bottom, \
                                  0, 0, 0, [xsi].dHeight, \
                                  [xsi].pPixelfield1, addr [xsi].BmpInfo, DIB_RGB_COLORS
        mov eax, [xsi].dWidth
        imul [xsi].dHeight
        shl eax, 2
        invoke MemZero, [xsi].pPixelfield1, eax
      .endif

      inc [xsi].dFrameCount                             ;Count the frames => Caption info

      fild [xsi].dFlashIntensity
      fmul [xsi].r4FlashFactor
      fistp [xsi].dFlashIntensity

      OCall [xsi].RenderWatch::StopWatch.Stop
      OCall [xsi].RenderWatch::StopWatch.GetTime
      mov ecx, 1000/FRAMERATE                           ;1000 / 30 = 33 ms
      sub ecx, eax
      .if SIGN?
;       DbgWarning "CPU too slow for target frame rate"
      .elseif !ZERO?
        shr ecx, 1                                      ;Patch
        invoke Sleep, ecx
      .endif
      OCall [xsi].RenderWatch::StopWatch.Reset
      OCall [xsi].RenderWatch::StopWatch.Start

    .until [xsi].dTerminate == TRUE
  .endif
  invoke ExitThread, 0
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Fireworks.Flash
; Purpose:    Perform a light flash on a specified position.
; Arguments:  Arg1: Light position x.
;             Arg2: Light position y.
;             Arg3: Luminosity.
; Return:     Nothing.

Method Fireworks.Flash, uses xbx xdi xsi, dx1:DWORD, dy1:DWORD, dLum:DWORD
  local dMx:DWORD, dMy:DWORD, dx2:DWORD, dy2:DWORD, dTff:DWORD, dMaxX:DWORD, dDist2:DWORD

  SetObject xsi
  mov eax, [xsi].dWidth
  mov dMx, eax
  mov eax, [xsi].dHeight
  dec eax
  mov dMy, eax
  xor eax, eax
  mov dy2, eax
  mov eax, dLum
  shr eax, 1                                            ;Flash: dynamic 2D lighting routine
  mov dLum, eax                                         ; does not uses any pre-computed data
  mov dTff, 255
  m2m dMaxX, [xsi].dWidth, edx
  mov xdi, [xsi].pPixelfield2
  mov xsi, [xsi].pPixelfield1
  ReleaseObject

  align ALIGN_CODE
  .repeat                                               ;2x2 instead of per pixel lighting
    xor eax, eax                                        ; half the quality, but higher speed
    mov dx2, eax
    .repeat
      mov eax, dy2
      sub eax, dy1
      imul eax
      mov ebx, dx2
      sub ebx, dx1
      imul ebx, ebx
      add eax, ebx
      mov edx, dLum
      imul edx, edx
      xor ebx, ebx
      mov dDist2, eax
      .if eax <= edx                                    ;Jump to end causes time waves
        fild dDist2
        fsqrt
        fidiv dLum                                      ;This code is -nonlinear-
        fld1
        fsubrp st(1), st(0)
        fmul st(0), st(0)                               ;Curve
        fmul st(0), st(0)                               ;Curve more
        fimul dTff
        fistp dDist2
        mov ebx, dDist2
        imul ebx, 01010101h
      .endif
      mov eax, dy2
      imul dMaxX
      add eax, dx2
      lea eax, [xax + xax*2]
      mov edx, dMaxX
      lea edx, [xdx + xdx*2]
      add edx, eax

      movd MM2, ebx                                     ;Simply add with saturation
      movq MM0, [xsi + xax]
      psllq MM2, 32
      movq MM1, [xsi + xdx]
      movd MM3, ebx
      por MM2, MM3
      paddusb MM0, MM2
      movd [xdi + xax], MM0
      paddusb MM1, MM2
      psrlq MM0, 32
      movd [xdi + xdx], MM1
      movd ebx, MM0
      psrlq MM1, 32
      mov [xdi + xax + 4], bx
      movd ecx, MM1
      mov [xdi + xdx + 4], cx
      emms                                              ;Free MMX registers for FP computations
      mov eax, dx2
      add eax, 2
      mov dx2, eax
    .until eax > dMx
    mov eax, dy2
    add eax, 2
    mov dy2, eax
  .until eax > dMy
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     Fireworks.Init
; Purpose:    Initialize the Fireworks object.
; Arguments:  Arg1: -> Owner object.
;             Arg2: Output window HANDLE.
;             Arg3: -> Output RECT.
; Return:     Nothing.

Method Fireworks.Init, uses xsi, pOwner:POINTER, hOutputWnd:HWND, pOutputRect:PRECT
  local dThreadID:DWORD, dConst:DWORD, dBitmapByteCount:DWORD, dScanLineByteCount:DWORD

  SetObject xsi
  ACall xsi.Init, pOwner
  mov dRandomSeed, $32($invoke(GetTickCount))
  m2m [xsi].hOutputWnd, hOutputWnd, xax
  mov [xsi].hDC, $invoke(GetDC, xax)
  m2m [xsi].hOutputWnd, hOutputWnd, edx

  mov xdx, pOutputRect
  m2m [xsi].OutputRect.left, [xdx].RECT.left, ecx
  m2m [xsi].OutputRect.top, [xdx].RECT.top, eax

  mov ecx, [xdx].RECT.right
  sub ecx, [xdx].RECT.left
  mov [xsi].OutputRect.right, ecx
  add ecx, 3
  and ecx, 0FFFFFFFCh
  mov [xsi].dWidth, ecx                                 ;Multiple of 4
  mov [xsi].BmpInfo.BITMAPINFO.bmiHeader.biWidth, ecx

  mov eax, [xdx].RECT.bottom
  sub eax, [xdx].RECT.top
  mov [xsi].OutputRect.bottom, eax
  mov [xsi].dHeight, eax
  mov [xsi].BmpInfo.BITMAPINFO.bmiHeader.biHeight, eax
  neg [xsi].BmpInfo.BITMAPINFO.bmiHeader.biHeight       ;Top Down scanline arrangement

  shl ecx, $Log2(sizeof(DWORD))                         ;Adjust to DWORD size
  add eax, 2                                            ;Extra top and bottom lines for Blur algo
  mul ecx
  mov dBitmapByteCount, eax
  mov dScanLineByteCount, ecx
  shl eax, 1                                            ;Allocate 2 pixel fields

  mov [xsi].pPixelMemBlock, $MemAlloc(eax, MEM_INIT_ZERO) ;Get memory for the Pixelfields
  .if eax == NULL
    OCall xsi.ErrorReport, NULL, FWK_OUTOFMEMORY
  .else
    mov edx, dScanLineByteCount
    add xax, xdx                                        ;Move to first scanline
    mov [xsi].pPixelfield1, xax
    mov edx, dBitmapByteCount
    add xax, xdx                                        ;Move to second field
    mov [xsi].pPixelfield2, xax

    mov eax, [xsi].dFireShellSparks
    imul eax, sizeof(Spark)
    add eax, sizeof FireShellHeader
    mov [xsi].dFireShellSize, eax
    imul [xsi].dFireShellCount                          ;Array size = dFireShellCount*dFireShellSize
    mov [xsi].pFireShellsMemory, $MemAlloc(eax)
    .if eax == NULL
      OCall xsi.ErrorReport, NULL, FWK_OUTOFMEMORY
    .else
      finit                                             ;Initialise floating point unit
      fSetPrecision f_PRECISION_24BIT                   ;Low precision floats for fireworks... not space rockets

      OCall [xsi].RenderWatch::StopWatch.Init, xsi
      mov dConst, 1000
      fild dConst
      fstp [xsi].RenderWatch.r8Resolution
      mov [xsi].hFireThread, $invoke(CreateThread, 0, 4096, $MethodAddr(xsi::Fireworks.FireThread), xsi, 0, addr dThreadID)
    .endif
  .endif
MethodEnd

endif