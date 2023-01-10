; ==================================================================================================
; Title:      Pixelmap.inc
; Author:     G. Friedrich / Homer / HSE
; Version:    C.1.0
; Purpose:    Pixelmap application using ObjAsm.
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Gamma correction tables initialized with a Gamma value of 2.20.
; These tables can be reinitialized using the InitGammaTables method.

.data
Lin2GamTable label BYTE
  BYTE  000h,01Ch,025h,02Bh,030h,035h,039h,03Dh,040h,043h,046h,049h,04Bh,04Eh,050h,052h
  BYTE  054h,056h,058h,05Ah,05Ch,05Eh,060h,061h,063h,065h,066h,068h,069h,06Bh,06Ch,06Eh
  BYTE  06Fh,071h,072h,073h,075h,076h,077h,078h,07Ah,07Bh,07Ch,07Dh,07Eh,07Fh,081h,082h
  BYTE  083h,084h,085h,086h,087h,088h,089h,08Ah,08Bh,08Ch,08Dh,08Eh,08Fh,090h,091h,092h
  BYTE  093h,094h,095h,095h,096h,097h,098h,099h,09Ah,09Bh,09Bh,09Ch,09Dh,09Eh,09Fh,0A0h
  BYTE  0A0h,0A1h,0A2h,0A3h,0A4h,0A4h,0A5h,0A6h,0A7h,0A7h,0A8h,0A9h,0AAh,0AAh,0ABh,0ACh
  BYTE  0ADh,0ADh,0AEh,0AFh,0AFh,0B0h,0B1h,0B1h,0B2h,0B3h,0B3h,0B4h,0B5h,0B6h,0B6h,0B7h
  BYTE  0B7h,0B8h,0B9h,0B9h,0BAh,0BBh,0BBh,0BCh,0BDh,0BDh,0BEh,0BEh,0BFh,0C0h,0C0h,0C1h
  BYTE  0C2h,0C2h,0C3h,0C3h,0C4h,0C5h,0C5h,0C6h,0C6h,0C7h,0C7h,0C8h,0C9h,0C9h,0CAh,0CAh
  BYTE  0CBh,0CBh,0CCh,0CDh,0CDh,0CEh,0CEh,0CFh,0CFh,0D0h,0D0h,0D1h,0D1h,0D2h,0D3h,0D3h
  BYTE  0D4h,0D4h,0D5h,0D5h,0D6h,0D6h,0D7h,0D7h,0D8h,0D8h,0D9h,0D9h,0DAh,0DAh,0DBh,0DBh
  BYTE  0DCh,0DCh,0DDh,0DDh,0DEh,0DEh,0DFh,0DFh,0E0h,0E0h,0E1h,0E1h,0E2h,0E2h,0E3h,0E3h
  BYTE  0E4h,0E4h,0E5h,0E5h,0E6h,0E6h,0E6h,0E7h,0E7h,0E8h,0E8h,0E9h,0E9h,0EAh,0EAh,0EBh
  BYTE  0EBh,0EBh,0ECh,0ECh,0EDh,0EDh,0EEh,0EEh,0EFh,0EFh,0F0h,0F0h,0F0h,0F1h,0F1h,0F2h
  BYTE  0F2h,0F3h,0F3h,0F3h,0F4h,0F4h,0F5h,0F5h,0F6h,0F6h,0F6h,0F7h,0F7h,0F8h,0F8h,0F8h
  BYTE  0F9h,0F9h,0FAh,0FAh,0FBh,0FBh,0FBh,0FCh,0FCh,0FDh,0FDh,0FDh,0FEh,0FEh,0FFh,0FFh

Gam2LinTable label BYTE
  BYTE  000h,000h,000h,000h,000h,000h,000h,000h,000h,000h,000h,000h,000h,000h,000h,000h
  BYTE  000h,000h,000h,000h,000h,000h,001h,001h,001h,001h,001h,001h,001h,001h,001h,001h
  BYTE  001h,002h,002h,002h,002h,002h,002h,002h,002h,003h,003h,003h,003h,003h,004h,004h
  BYTE  004h,004h,004h,005h,005h,005h,005h,006h,006h,006h,006h,007h,007h,007h,007h,008h
  BYTE  008h,008h,009h,009h,009h,00Ah,00Ah,00Ah,00Bh,00Bh,00Ch,00Ch,00Ch,00Dh,00Dh,00Eh
  BYTE  00Eh,00Fh,00Fh,00Fh,010h,010h,011h,011h,012h,012h,013h,013h,014h,014h,015h,016h
  BYTE  016h,017h,017h,018h,019h,019h,01Ah,01Ah,01Bh,01Ch,01Ch,01Dh,01Eh,01Eh,01Fh,020h
  BYTE  021h,021h,022h,023h,024h,024h,025h,026h,027h,028h,028h,029h,02Ah,02Bh,02Ch,02Dh
  BYTE  02Eh,02Eh,02Fh,030h,031h,032h,033h,034h,035h,036h,037h,038h,039h,03Ah,03Bh,03Ch
  BYTE  03Dh,03Eh,03Fh,040h,041h,043h,044h,045h,046h,047h,048h,049h,04Bh,04Ch,04Dh,04Eh
  BYTE  050h,051h,052h,053h,055h,056h,057h,059h,05Ah,05Bh,05Dh,05Eh,05Fh,061h,062h,063h
  BYTE  065h,066h,068h,069h,06Bh,06Ch,06Eh,06Fh,071h,072h,074h,075h,077h,079h,07Ah,07Ch
  BYTE  07Dh,07Fh,081h,082h,084h,086h,087h,089h,08Bh,08Dh,08Eh,090h,092h,094h,096h,097h
  BYTE  099h,09Bh,09Dh,09Fh,0A1h,0A3h,0A5h,0A6h,0A8h,0AAh,0ACh,0AEh,0B0h,0B2h,0B4h,0B6h
  BYTE  0B8h,0BAh,0BDh,0BFh,0C1h,0C3h,0C5h,0C7h,0C9h,0CCh,0CEh,0D0h,0D2h,0D4h,0D7h,0D9h
  BYTE  0DBh,0DDh,0E0h,0E2h,0E4h,0E7h,0E9h,0EBh,0EEh,0F0h,0F3h,0F5h,0F8h,0FAh,0FDh,0FFh

PtoPxmProc  typedef proto :ptr RGBQUAD, :XWORD, :XWORD
PPtoPxmProc typedef ptr PtoPxmProc 

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Object:     Pixelmap
; Purpose:    Implement a Pixelmap object. Pixelmaps have a pixel color resolution of 8
;             bits per color channel and 8 bits for an alfa channel. Total color depth of 32 bits.
; Links:      - http://www.3dsoftware.com/Programming/WindowsAPI/DIB_Section/  => hSection info
;             - http://student.kuleuven.be/~m0216922/CG/index.html
;             - http://www.teamten.com/lawrence/graphics/gamma/
;             - http://www.graphics.cornell.edu/~westin/gamma/gamma.html
;             - http://www.poynton.com/notes/reducing_eyestrain/index.html
;             - http://msdn2.microsoft.com/en-us/library/ms534885.aspx
; Note:       Requires Gdi32 and OleAut32 libraries.
;
;             Transparency rules:
;             A. The alfa value of the Foreground pixel is used to calculate the blending factors.
;             B. All color operations are done in the linear color space.
;             C. If a pixel is blended using a Setxxx method on another pixel, the alfa value of the
;                resulting pixel is the value of the forground pixel.
;             D. If a pixel is blended using a Blendxxx method on another pixel, the alfa value of
;                the resulting pixel is the value of the background pixel.

Object Pixelmap, PixelmapID, Streamable
  VirtualMethod   BlendPixel,           DWORD, DWORD, DWORD
  VirtualMethod   BlendVirtualPixel,    REAL4, REAL4, DWORD
  VirtualMethod   Clone
  VirtualMethod   CopyBmp,              HDC, HBITMAP, PRECT, POINT
  VirtualMethod   CopyDisplay,          HDC, PRECT, POINT
  VirtualMethod   CopyPixelmap,         POINTER, PRECT, POINT
  VirtualMethod   CreateDDB,            HDC                           ;Device Dependant Bitmap
  VirtualMethod   CreateDIB                                           ;Device Independent Bitmap
  RedefineMethod  Done
  VirtualMethod   ForEachPixel,         PPtoPxmProc, XWORD, XWORD
  VirtualMethod   GetPixel,             DWORD, DWORD
  VirtualMethod   GetVirtualComponent,  REAL4, REAL4, DWORD
  VirtualMethod   GetVirtualPixel,      REAL4, REAL4
  RedefineMethod  Init,                 POINTER, DWORD, DWORD
  VirtualMethod   InitGammaTables,      REAL4                         ;Gamma value
  RedefineMethod  Load,                 $ObjPtr(Stream), POINTER      ;-> Stream, -> Owner
  VirtualMethod   LoadBmp,              POINTER, HDC, HBITMAP
  VirtualMethod   LoadFileA,            PSTRINGA
  VirtualMethod   LoadFileW,            PSTRINGW
  VirtualMethod   Reset
  VirtualMethod   SaveFileA,            PSTRINGA, DWORD
  VirtualMethod   SaveFileW,            PSTRINGW, DWORD
  VirtualMethod   SetPixel,             DWORD, DWORD, DWORD
  VirtualMethod   SetVirtualComponent,  REAL4, REAL4, DWORD, DWORD
  VirtualMethod   SetVirtualPixel,      REAL4, REAL4, DWORD
  RedefineMethod  Store,                $ObjPtr(Stream)               ;-> Stream
  VirtualMethod   UV2XY,                POINTER, POINTER, DWORD

  Private
  VirtualMethod   Gamma2Linear,         DWORD
  VirtualMethod   Linear2Gamma,         DWORD
  PrivateEnd

  StaticMethod    AlphaBlend,           POINTER, PRECT, POINT
  StaticMethod    Brightness,           DWORD
  StaticMethod    Convolve3x3,          POINTER, PRECT, POINT, POINTER
  StaticMethod    DrawCircle,           SDWORD, SDWORD, SDWORD, DWORD
  StaticMethod    DrawLine,             SDWORD, SDWORD, SDWORD, SDWORD, DWORD
  StaticMethod    DrawStrA,             PSTRINGA, POINT, DWORD, HFONT, DWORD, REAL4
  StaticMethod    DrawStrW,             PSTRINGW, POINT, DWORD, HFONT, DWORD, REAL4
  StaticMethod    FillBkGnd,            DWORD
  StaticMethod    FillRect,             PRECT, DWORD
  StaticMethod    FillRectChannel,      PRECT, DWORD, DWORD
  StaticMethod    FillRectGradHor,      PRECT, DWORD, DWORD
  StaticMethod    FillRectGradVer,      PRECT, DWORD, DWORD
  StaticMethod    FlipRectHor,          PRECT
  StaticMethod    FlipRectVer,          PRECT
  StaticMethod    Gray,                 PRECT
  StaticMethod    Litho,                PRECT, DWORD
  StaticMethod    Replace_ARGB_ARGB,    PRECT, DWORD, DWORD
  StaticMethod    Replace_RGB_ARGB,     PRECT, DWORD, DWORD
  StaticMethod    Replace_RGB_RGB,      PRECT, DWORD, DWORD
  StaticMethod    SetAlphaMask,         POINTER, PRECT, POINT, DWORD


  DefineVariable  dWidth,         DWORD,        0       ;Don't change the order of the
  DefineVariable  dHeight,        DWORD,        0       ;  following 2 dwords
  DefineVariable  hDC,            HDC,          0
  DefineVariable  hDIBSection,    HANDLE,       0
  DefineVariable  pPixels,        POINTER,      NULL    ;Memory block with pixel color information
  DefineVariable  pLin2GamTable,  POINTER,      offset Lin2GamTable
  DefineVariable  pGam2LinTable,  POINTER,      offset Gam2LinTable
  DefineVariable  ObjLock,        OBJECT_LOCK,  {}

  DefineVariable  BmpInfo,        BITMAPINFO,   {{sizeof BITMAPINFOHEADER,0,0,1,32,BI_RGB,0,0,0,0,0}}
  DefineVariable  hPrvBmp,        HBITMAP,      0

ObjectEnd


if TARGET_STR_TYPE eq STR_TYPE_ANSI
  $ObjMthd(DrawStr)   textequ   $ObjMthd(DrawStrA)
  LoadFile  textequ   <LoadFileA>
  SaveFile  textequ   <SaveFileA>
elseif TARGET_STR_TYPE eq STR_TYPE_WIDE
  $ObjMthd(DrawStr)   textequ   $ObjMthd(DrawStrW)
  $ObjMthd(LoadFile)  textequ   $ObjMthd(LoadFileW)
  $ObjMthd(SaveFile)  textequ   $ObjMthd(SaveFileW)
else
  echo <Warning: incompatible TARGET_STR_TYPE>
endif

; ——————————————————————————————————————————————————————————————————————————————————————————————————
;
;   Pixel format in memory (BGRA):                  Loaded into a register (ARGB):
;
;   ——————————————————————————————                  ——————————————————————————————
;  | Blue | Green |  Red  | Alpha |       =>       | Alpha | Red |  Green  | Blue |
;   ——————————————————————————————                  ——————————————————————————————
;


;Some usual 3x3 convolution filter data
.const
Identity          REAL4   +0.0000, +0.0000, +0.0000, +0.0000, +1.0000, +0.0000, +0.0000, +0.0000, +0.0000
Blur              REAL4   +0.0625, +0.1250, +0.0625, +0.1250, +0.2500, +0.1250, +0.0625, +0.1250, +0.0625
GaussianBlur      REAL4   +0.0450, +0.1222, +0.0450, +0.1222, +0.3320, +0.1222, +0.0450, +0.1222, +0.0450
GaussianBlur2     REAL4   +0.0000, +0.2000, +0.0000, +0.2000, +0.2000, +0.2000, +0.0000, +0.2000, +0.0000
BoxBlur           REAL4   +0.1111, +0.1111, +0.1111, +0.1111, +0.1111, +0.1111, +0.1111, +0.1111, +0.1111
Sharpen           REAL4   +0.0000, -1.0000, +0.0000, -1.0000, +5.0000, -1.0000, +0.0000, -1.0000, +0.0000
Sharpen1          REAL4   -1.0000, -1.0000, -1.0000, -1.0000, +9.0000, -1.0000, -1.0000, -1.0000, -1.0000
Sharpen2          REAL4   -1.0000, -1.0000, -1.0000, -1.0000, +16.000, -1.0000, -1.0000, -1.0000, -1.0000
EdgeDetect        REAL4   -0.1250, -0.1250, -0.1250, -0.1250, +1.0000, -0.1250, -0.1250, -0.1250, -0.1250
EdgeDetect2       REAL4   -1.0000, -1.0000, -1.0000, -1.0000, +8.0000, -1.0000, -1.0000, -1.0000, -1.0000
EdgeDetect3       REAL4   -5.0000, +0.0000, +0.0000, +0.0000, +0.0000, +0.0000, +0.0000, +0.0000, +5.0000
EdgeDetect4       REAL4   -1.0000, -1.0000, -1.0000, +0.0000, +0.0000, +0.0000, +1.0000, +1.0000, +1.0000
EdgeDetect5       REAL4   -1.0000, -1.0000, -1.0000, +2.0000, +2.0000, +2.0000, -1.0000, -1.0000, -1.0000
EdgeDetect6       REAL4   -5.0000, -5.0000, -5.0000, -5.0000, +39.000, -5.0000, -5.0000, -5.0000, -5.0000
EdgeDetectLaplace REAL4   +0.0000, +1.0000, +0.0000, +1.0000, -4.0000, +1.0000, +0.0000, +1.0000, +0.0000
SobelHorizontal   REAL4   +1.0000, +2.0000, +1.0000, +0.0000, +0.0000, +0.0000, -1.0000, -2.0000, -1.0000
SobelVertical     REAL4   +1.0000, +0.0000, -1.0000, +2.0000, +0.0000, -2.0000, +1.0000, +0.0000, -1.0000
PrevitHorizontal  REAL4   +1.0000, +1.0000, +1.0000, +0.0000, +0.0000, +0.0000, -1.0000, -1.0000, -1.0000
PrevitVertical    REAL4   +1.0000, +0.0000, -1.0000, +1.0000, +0.0000, -1.0000, +1.0000, +0.0000, -1.0000
Emboss            REAL4   -2.0000, -1.0000, +0.0000, -1.0000, +1.0000, +1.0000, +0.0000, +1.0000, +2.0000
Engrave           REAL4   +2.0000, +1.0000, +0.0000, +1.0000, -1.0000, -1.0000, +0.0000, -1.0000, -2.0000


PXM_CHANNEL_RED     equ   1
PXM_CHANNEL_BLUE    equ   2
PXM_CHANNEL_GREEN   equ   4
PXM_CHANNEL_ALPHA   equ   8

PXM_FORMAT_PXM      equ   0

PXM_ADDR_LIN        equ   0
PXM_ADDR_WRAP       equ   1
PXM_ADDR_MIRROR     equ   2
PXM_ADDR_CLAMP      equ   3


; ==================================================================================================

if IMPLEMENT

; ——————————————————————————————————————————————————————————————————————————————————————————————————

;Some used constants
PXM_MASK_0001             equ   0000000FFh
PXM_MASK_0010             equ   00000FF00h
PXM_MASK_0100             equ   000FF0000h
PXM_MASK_0101             equ   000FF00FFh
PXM_MASK_1010             equ   0FF00FF00h
PXM_MASK_REG_RGB          equ   000FFFFFFh
PXM_MASK_REG_ARGB         equ   0FFFFFFFFh
PXM_MASK_REG_ALPHA        equ   0FF000000h
PXM_MASK_REG_RED          equ   000FF0000h
PXM_MASK_REG_GREEN        equ   00000FF00h
PXM_MASK_REG_BLUE         equ   0000000FFh
PXM_MASK_MEM_RGB          equ   0FFFFFF00h
PXM_MASK_MEM_ARGB         equ   0FFFFFFFFh
PXM_MASK_MEM_ALPHA        equ   0000000FFh
PXM_MASK_MEM_RED          equ   00000FF00h
PXM_MASK_MEM_GREEN        equ   000FF0000h
PXM_MASK_MEM_BLUE         equ   0FF000000h
PXM_CHANNEL_OFFSET_BLUE   equ   0
PXM_CHANNEL_OFFSET_GREEN  equ   1
PXM_CHANNEL_OFFSET_RED    equ   2
PXM_CHANNEL_OFFSET_ALPHA  equ   3

REAL4_SIZE                equ   sizeof REAL4
RGBQUAD_SIZE              equ   sizeof RGBQUAD
LOG2_RGBQUAD_SIZE         equ   $Log2(RGBQUAD_SIZE)

HIMETRIC_INCH   equ   2540      ;25.4 mm/inch * 100

.const
PXM_CHANNEL_OFFSET_TABLE   BYTE  -1, PXM_CHANNEL_OFFSET_RED, PXM_CHANNEL_OFFSET_BLUE, -1, \
                                 PXM_CHANNEL_OFFSET_GREEN, -1, -1, -1, PXM_CHANNEL_OFFSET_ALPHA
PXM_CHANNEL_MEM_MASK_TABLE DWORD PXM_MASK_MEM_ARGB, PXM_MASK_MEM_RED, PXM_MASK_MEM_BLUE, \
                                 PXM_MASK_MEM_ARGB, PXM_MASK_MEM_GREEN, PXM_MASK_MEM_ARGB, \
                                 PXM_MASK_MEM_ARGB, PXM_MASK_MEM_ARGB, PXM_MASK_MEM_ALPHA
PXM_CHANNEL_REG_MASK_TABLE DWORD PXM_MASK_REG_ARGB, PXM_MASK_REG_RED, PXM_MASK_REG_BLUE, \
                                 PXM_MASK_REG_ARGB, PXM_MASK_REG_GREEN, PXM_MASK_REG_ARGB, \
                                 PXM_MASK_REG_ARGB, PXM_MASK_REG_ARGB, PXM_MASK_REG_ALPHA

DefGUID IID_IPicture, %sIID_IPicture

.code

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Purpose:    Compute the 100h complement of the value stored in al, storing the original value in
;             dDens1 and the complement in dDens2. Density values range from 1 to 256.

Pxm_Alpha_Densities macro Reg:req
  shr Reg, 32 - 8                                       ;Get the alpha value in the lower 8 bits
  inc Reg
  mov dDens1, Reg                                       ;Store it in dDens1
  neg Reg
  add Reg, 101h
  mov dDens2, Reg                                       ;Dens2 = Complement to dDens1
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Purpose:    Perform a component intensity multiplication using ARGB pixel nibbles.

Pxm_Blend_ARGB macro Reg1:req, Reg2:req, Density:req
  mov Reg2, Reg1
  and Reg1, PXM_MASK_1010                               ;Get pixel nibbles
  and Reg2, PXM_MASK_0101
  shr Reg1, 8
  imul Reg2, Density                                    ;Compute new component intensity
  imul Reg1, Density
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Purpose:    Perform the merging of partial ARGB blending operations.

Pxm_BlendMerge_ARGB macro Reg1:req, Reg2:req, Reg3:req, Reg4:req
  add Reg2, Reg4
  add Reg1, Reg3                                        ;Merge the 2 pixel nibbles
  shr Reg2, 8
  and Reg1, PXM_MASK_1010
  and Reg2, PXM_MASK_0101
  or Reg1, Reg2
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Purpose:    Perform a component intensity multiplication using RGB pixel nibbles.
;             Alpha value is set to zero.

Pxm_PixelBlend_RGB macro Reg1:req, Reg2:req, Density:req
  mov Reg2, Reg1
  and Reg1, PXM_MASK_0010                               ;Get pixel nibbles
  and Reg2, PXM_MASK_0101
  imul Reg1, Density                                    ;Compute new component intensity
  imul Reg2, Density
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Purpose:    Perform the merging of partial RGB blending operations.
;             Alpha value is set to zero.

Pxm_PixelMerge_RGB macro Reg1:req, Reg2:req, Reg3:req, Reg4:req
  add Reg1, Reg3                                        ;Merge the 2 pixel nibbles
  add Reg2, Reg4
  and Reg1, PXM_MASK_0100
  and Reg2, PXM_MASK_1010
  or Reg1, Reg2
  shr Reg1, 8
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Purpose:    Order the RECT arguments so that RECT.left <= RECT.right and RECT.top <= RECT.bottom.
; Uses:       eax, ecx

Pxm_FlipInvertedRect macro Rct:req
  mov eax, Rct.right
  .if SDWORD ptr eax < Rct.left
    mov ecx, Rct.left
    mov Rct.left, eax
    mov Rct.right, ecx
  .endif
  mov eax, Rct.bottom
  .if SDWORD ptr eax < Rct.top
    mov ecx, Rct.top
    mov Rct.top, eax
    mov Rct.bottom, ecx
  .endif
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Purpose:    Calculate the intersection of 2 RECTs (my replacement of the IntersectRect API).
; Uses:       eax, ecx

Pxm_ClipRect macro DstRct:req, SrcRct1:req, SrcRct2:req
  mov ecx, SrcRct1.left
  cmp ecx, SrcRct2.left
  if @Cpu and CPU_686
    cmovl ecx, SrcRct2.left
  else
    .if SDWORD ptr ecx < SrcRct2.left
      mov ecx, SrcRct2.left
    .endif
  endif
  mov eax, SrcRct1.right
  cmp eax, SrcRct2.right
  if @Cpu and CPU_686
    cmovg eax, SrcRct2.right
  else
    .if SDWORD ptr eax > SrcRct2.right
      mov eax, SrcRct2.right
    .endif
  endif
  cmp eax, ecx
  jle @@EOM                                              ;Early method exit
  mov DstRct.left, ecx
  mov DstRct.right, eax
  mov ecx, SrcRct1.top
  cmp ecx, SrcRct2.top
  if @Cpu and CPU_686
    cmovl ecx, SrcRct2.top
  else
    .if SDWORD ptr ecx < SrcRct2.top
      mov ecx, SrcRct2.top
    .endif
  endif
  mov eax, SrcRct1.bottom
  cmp eax, SrcRct2.bottom
  if @Cpu and CPU_686
    cmovg eax, SrcRct2.bottom
  else
    .if SDWORD ptr eax > SrcRct2.bottom
      mov eax, SrcRct2.bottom
    .endif
  endif
  cmp eax, ecx
  jle @@EOM                                             ;Early method exit
  mov DstRct.top, ecx
  mov DstRct.bottom, eax
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Purpose:    Get address of a pixel in the Pixelmap.
; Uses:       xax

Pxm_PixelAddr macro XPos:req, YPos:req, ObjReg:=<xsi>
  mov eax, YPos
  mul [ObjReg].dWidth
  add eax, XPos
  shl xax, LOG2_RGBQUAD_SIZE
  add xax, [ObjReg].pPixels
endm

$Pxm_PixelAddr macro XPos:req, YPos:req, ObjReg:=<xsi>
  Pxm_PixelAddr XPos, YPos, ObjReg
  exitm <xax>
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Purpose:    Get the bytes to reach the next line
; Uses:       eax

$Pxm_Bytes2Skip macro DimX:req, ObjReg:=<xsi>
  mov eax, [ObjReg].dWidth
  sub eax, DimX
  shl eax, LOG2_RGBQUAD_SIZE
  exitm <xax>
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Purpose:    Transformation from destination to source space => DstRct/SrcPnt to SrcRct/DstPnt
; Uses:       eax, ecx, edx

Dst2SrcSpace macro Rct:req, Pnt:req
  mov ecx, Pnt.x
  mov edx, Rct.left
  mov eax, Rct.right
  sub eax, edx
  add eax, ecx
  mov Rct.left, ecx
  mov Rct.right, eax
  mov Pnt.x, edx

  mov ecx, Pnt.y
  mov edx, Rct.top
  mov eax, Rct.bottom
  sub eax, edx
  add eax, ecx
  mov Rct.top, ecx
  mov Rct.bottom, eax
  mov Pnt.y, edx
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————

.code

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Pixelmap.BlendPixel
; Purpose:    Blend the ARGB value over another pixel.
; Arguments:  Arg1: X location.
;             Arg2: Y location.
;             Arg3: ARGB linear value to blend.
; Return:     Nothing.

Method Pixelmap.BlendPixel, uses xbx xdi xsi, dCoorX:DWORD, dCoorY:DWORD, dARGB:DWORD
  local dDens1:DWORD, dDens2:DWORD

  SetObject xsi
  .if [xsi].hDIBSection != 0
    mov eax, dCoorY
    .if SDWORD ptr eax >= 0 && SDWORD ptr eax < [xsi].dHeight
      mov ecx, dCoorX
      .if SDWORD ptr ecx >= 0 && SDWORD ptr ecx < [xsi].dWidth
        shl xcx, LOG2_RGBQUAD_SIZE
        add xcx, [xsi].pPixels
        mul [xsi].dWidth
        lea xsi, [RGBQUAD_SIZE*xax + xcx]
        mov edi, dARGB
        RGB2BGR edi
        mov edx, edi

        Pxm_Alpha_Densities edx

        ;Get background pixel and transform it into linear color space
        OCall pSelf::Pixelmap.Gamma2Linear, DWORD ptr [xsi]
        Pxm_PixelBlend_RGB eax, ebx, dDens2

        Pxm_PixelBlend_RGB edi, edx, dDens1
        Pxm_PixelMerge_RGB eax, ebx, edi, edx

        OCall pSelf::Pixelmap.Linear2Gamma, eax
        mov ecx, DWORD ptr [xsi]                        ;Set original alfa value
        and ecx, PXM_MASK_REG_ALPHA
        or eax, ecx
        mov DWORD ptr [xsi], eax
      .else
        DbgWarning "X coordinate out of range in BlendPixel"
      .endif
    .else
      DbgWarning "Y coordinate out of range in BlendPixel"
    .endif
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:    Pixelmap.BlendVirtualPixel
; Purpose:   Set an ARGB value of a given virtual pixel and perform a Gamma Correction on the
;            modified pixels. Alpha values of the background pixels are not changed.
; Arguments: Arg1: X location.
;            Arg2: Y location.
;            Arg3: ARGB linear value to blend.
; Return:    Nothing.

.const
d255 DWORD 255
.code

PXM_BlendColors macro
  mov dBackLinColor, $32($OCall(pSelf::Pixelmap.Gamma2Linear, DWORD ptr [xsi])) ;ABGR

  movzx ecx, BYTE ptr dForeLinColor + 3                 ;Alpha
  mov dBuffer, ecx
  fild dBuffer
  fmulp st(1), st(0)
  fidiv d255

  fld1                                                  ;Calc complement to 1
  fsub st(0), st(1)

  movzx ecx, BYTE ptr dForeLinColor + 2                 ;Blue
  mov dBuffer, ecx
  fild dBuffer
  movzx ecx, BYTE ptr dBackLinColor + 0
  fmul st(0), st(2)
  mov dBuffer, ecx
  fild dBuffer
  fmul st(0), st(2)
  faddp st(1), st(0)
  fistp sdBlue

  movzx ecx, BYTE ptr dForeLinColor + 1                 ;Green
  mov dBuffer, ecx
  fild dBuffer
  movzx ecx, BYTE ptr dBackLinColor + 1
  fmul st(0), st(2)
  mov dBuffer, ecx
  fild dBuffer
  fmul st(0), st(2)
  faddp st(1), st(0)
  fistp sdGreen

  movzx ecx, BYTE ptr dForeLinColor + 0                 ;Red
  mov dBuffer, ecx
  fild dBuffer
  movzx ecx, BYTE ptr dBackLinColor + 2
  fmul st(0), st(2)
  mov dBuffer, ecx
  fild dBuffer
  fmul st(0), st(2)
  faddp st(1), st(0)
  fistp sdRed

  fUnload

  ;Compose the new ABGR color and prevent a channel over- or underflow.
  if @Cpu and CPU_686
    mov edx, 255
    xor ecx, ecx
    mov eax, sdRed
    cmp eax, ecx
    cmovl eax, ecx
    cmp eax, edx
    cmovg eax, edx
    mov sdRed, eax

    mov eax, sdGreen
    cmp eax, ecx
    cmovl eax, ecx
    cmp eax, edx
    cmovg eax, edx
    mov sdGreen, eax

    mov eax, sdBlue
    cmp eax, ecx
    cmovl eax, ecx
    cmp eax, edx
    cmovg eax, edx
    mov sdBlue, eax
  else
    .if sdRed > 255
      mov sdRed, 255
    .elseif sdRed < 0
      m2z sdRed
    .endif
    .if sdGreen > 255
      mov sdGreen, 255
    .elseif sdGreen < 0
      m2z sdGreen
    .endif
    .if sdBlue > 255
      mov sdBlue, 255
    .elseif sdBlue < 0
      m2z sdBlue
    .endif
  endif
  mov ah, BYTE ptr dBackLinColor + 3                    ;Preserve background alfa value
  mov al, BYTE ptr sdRed
  shl eax, 16
  mov ah, BYTE ptr sdGreen
  mov al, BYTE ptr sdBlue

  mov DWORD ptr [xsi], $32($OCall(pSelf::Pixelmap.Linear2Gamma, eax))
endm

Method Pixelmap.BlendVirtualPixel, uses xsi, r4CoorX:REAL4, r4CoorY:REAL4, dARGB:DWORD
  local sdCoorX0:SDWORD, sdCoorX1:SDWORD, sdCoorY0:SDWORD, sdCoorY1:SDWORD
  local dBuffer:DWORD, wCurFpuCtrl:WORD, wPrvFpuCtrl:WORD
  local xSkipX:SXWORD, xSkipY:XWORD
  local sdRed:SDWORD, sdGreen:SDWORD, sdBlue:SDWORD
  local dBackLinColor:DWORD, dForeLinColor:DWORD

  ANNOTATION use: dBackLinColor dBuffer sdBlue sdGreen sdRed

  SetObject xsi
  fstcw wPrvFpuCtrl                                     ;Store FPU control word
  m2m wCurFpuCtrl, wPrvFpuCtrl, ax                      ;Duplicate value

  fld r4CoorY

  BitSet wCurFpuCtrl, BIT10                             ;Modify the control word to
  BitClr wCurFpuCtrl, BIT11                             ;  round to -inf
  fldcw wCurFpuCtrl                                     ;Restore modified FPU control word
  fist sdCoorY0

  BitClr wCurFpuCtrl, BIT10                             ;Modify the control word to
  BitSet wCurFpuCtrl, BIT11                             ;  round to +inf
  fldcw wCurFpuCtrl                                     ;Restore modified FPU control word
  fist sdCoorY1

  mov eax, sdCoorY1
  .if sdCoorY0 >= 0 && SDWORD ptr eax < [xsi].dHeight
    fisub sdCoorY0                                      ;B = y - y0
    xor edx, edx
    fld r4CoorX
    cmp eax, sdCoorY0
    je @F
    mov edx, [xsi].dWidth
    shl xdx, LOG2_RGBQUAD_SIZE
  @@:
    mov xSkipY, xdx

    fist sdCoorX1

    BitSet wCurFpuCtrl, BIT10                           ;Modify the control word to
    BitClr wCurFpuCtrl, BIT11                           ;  round to -inf
    fldcw wCurFpuCtrl                                   ;Restore modified FPU control word
    fist sdCoorX0

    mov ecx, sdCoorX1
    .if sdCoorX0 >= 0 && SDWORD ptr ecx < [xsi].dWidth
      BitClr wCurFpuCtrl, (BIT10 or BIT11)              ;Modify the control word to return rnd(x)
      fldcw wCurFpuCtrl                                 ;Restore modified FPU control word
      xor edx, edx
      fisub sdCoorX0                                    ;A = x - x0, B = y - y0
      cmp ecx, sdCoorX0
      je @F
      mov xdx, RGBQUAD_SIZE
    @@:
      mov xSkipX, xdx

      shl ecx, LOG2_RGBQUAD_SIZE
      add xcx, [xsi].pPixels
      mul [xsi].dWidth
      lea xsi, [RGBQUAD_SIZE*xax + xcx]                 ;xsi -> Poisition right/bottom
      mov dForeLinColor, $32($OCall(pSelf::Pixelmap.Gamma2Linear, dARGB))   ;ARGB

      .if xSkipX == 0 && xSkipY == 0
        fUnload
        fld1
        PXM_BlendColors                                 ;xsi -> Position 00

      .elseif xSkipX == 0                               ;A = 0, B <> 0
        fUnload                                         ;Discard A = 0
        fld1
        fsub st(0), st(1)                               ;1 - B, B
        fxch st(1)

        PXM_BlendColors                                 ;xsi -> Position 01
        fUnload
        sub xsi, xSkipY                                 ;xsi -> Position 00
        PXM_BlendColors

      .elseif xSkipY == 0                               ;A <> 0, B = 0
        fxch st(1)
        fUnload                                         ;Discard B = 0
        fld1
        fsub st(0), st(1)                               ;1 - A, A
        fxch st(1)

        PXM_BlendColors                                 ;xsi -> Position 10
        fUnload
        sub xsi, xSkipX                                 ;xsi -> Position 00
        PXM_BlendColors

      .else
        fld st(0)
        fmul st(0), st(2)                               ;f11 = AxB
        fsub st(1), st(0)                               ;f10 = A - AxB
        fsub st(2), st(0)                               ;f01 = B - AxB
        fld1
        fsub st(0), st(1)
        fsub st(0), st(2)                               ;f00 = 1 - f11 - f10 - f01
        fsub st(0), st(3)                               ;f00, f11, f10, f01

        sub xsi, xSkipX                                 ;xsi -> Poisition 01
        sub xsi, xSkipY                                 ;xsi -> Poisition 00
        PXM_BlendColors
        fUnload
        add xsi, xSkipX                                 ;xsi -> Poisition 10
        add xsi, xSkipY                                 ;xsi -> Poisition 11
        PXM_BlendColors
        fUnload
        sub xsi, xSkipY                                 ;xsi -> Poisition 10
        PXM_BlendColors
        fUnload
        sub xsi, xSkipX                                 ;xsi -> Poisition 00
        add xsi, xSkipY                                 ;xsi -> Poisition 01
        PXM_BlendColors
      .endif
      jmp @F
    .else
      DbgWarning "X coordinate out of range in BlendVirtualPixel"
    .endif
    fUnload
  .else
    DbgWarning "Y coordinate out of range in BlendVirtualPixel"
  .endif
@@:
  fUnload
  fldcw wPrvFpuCtrl                                     ;Restore previous FPU control word
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Pixelmap.Clone
; Purpose:    Duplicate the Pixelmap object.
; Arguments:  None.
; Return:     eax -> New cloned Pixelmap object or NULL if failed.

Method Pixelmap.Clone, uses xbx xsi
  SetObject xsi
  New Pixelmap
  .if xax != NULL
    mov xbx, xax
    OCall xbx::Pixelmap.Init, [xsi].pOwner, [xsi].dWidth, [xsi].dHeight
    .if [xbx].$Obj(Pixelmap).dErrorCode == OBJ_OK
      invoke MemClone, [xbx].$Obj(Pixelmap).pPixels, [xsi].pPixels, \
                       [xbx].$Obj(Pixelmap).BmpInfo.BITMAPINFO.bmiHeader.biSizeImage
    .else
      xor eax, eax
    .endif
  .else
    OCall xsi.ErrorReport, NULL, PXM_OUT_OF_MEMORY
    xor eax, eax
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Pixelmap.CopyBmp
; Purpose:    Copy the pixels of a Bitmap (DDB or DIB) RECT to the destination on this Pixelmap.
; Arguments:  Arg1: Source DC HANDLE compatible to the DDB. Don't need to be selected.
;             Arg2: Source Bitmap HANDLE.
;             Arg3: -> Source RECT.
;             Arg4: Destination start point.
; Return:     eax = Error code.

Method Pixelmap.CopyBmp, uses xdi xsi, hDC:HDC, hBmp:HBITMAP, pSrcRct:PRECT, DstPnt:POINT
  local dWidth:DWORD, dHeight:DWORD, xSrcSkipY:XWORD, xDstSkipY:XWORD
  local SrcSpace:RECT, DstSpace:RECT, OutRct:RECT, SrcRct:RECT
  local BmpInfo:BITMAPINFO, Bmp:BITMAP, pScanlineBuffer:POINTER

  SetObject xdi
  .if [xdi].hDIBSection != 0
    invoke GetObject, hBmp, sizeof Bmp, addr Bmp        ;Works only on memory DCs!!!!
    .if eax != 0
      ;Flip SrcRct if necessary
      mov xcx, pSrcRct
      CloneRect SrcRct, RECT ptr [xcx], xax, xdx
      Pxm_FlipInvertedRect SrcRct

      ;Clip SrcRct to SrcSpace
      m2z SrcSpace.left
      m2z SrcSpace.top
      m2m SrcSpace.right, Bmp.bmWidth, eax
      m2m SrcSpace.bottom, Bmp.bmHeight, eax
      Pxm_ClipRect OutRct, SrcRct, SrcSpace

      ;Clip to DstSpace
      mov eax, SrcRct.left
      sub eax, DstPnt.x
      mov DstSpace.left, eax
      add eax, [xdi].dWidth
      mov DstSpace.right, eax
      mov eax, SrcRct.top
      sub eax, DstPnt.y
      mov DstSpace.top, eax
      add eax, [xdi].dHeight
      mov DstSpace.bottom, eax
      Pxm_ClipRect OutRct, OutRct, DstSpace

      ;Calc transfer sizes
      sub eax, ecx
      jz @@EOM
      mov dHeight, eax
      mov ecx, OutRct.right                             ;Width of a scan line
      mov BmpInfo.BITMAPINFO.bmiHeader.biWidth, ecx
      sub ecx, OutRct.left
      jz @@EOM
      mov dWidth, ecx

      xor edx, edx
      mov BmpInfo.bmiHeader.biSize, sizeof BITMAPINFOHEADER
      neg eax                                           ;Top down bitmap
      mov BmpInfo.bmiHeader.biHeight, eax
      mov BmpInfo.bmiHeader.biPlanes, 1
      mov BmpInfo.bmiHeader.biBitCount, 32
      mov BmpInfo.bmiHeader.biCompression, edx
      mov BmpInfo.bmiHeader.biXPelsPerMeter, edx
      mov BmpInfo.bmiHeader.biYPelsPerMeter, edx
      mov BmpInfo.bmiHeader.biClrUsed, edx
      mov BmpInfo.bmiHeader.biClrImportant, edx

      mov eax, dHeight
      mul BmpInfo.BITMAPINFO.bmiHeader.biWidth
      shl eax, LOG2_RGBQUAD_SIZE
      mov BmpInfo.BITMAPINFO.bmiHeader.biSizeImage, eax

      MemAlloc eax
      .if xax != NULL
        mov pScanlineBuffer, xax
        invoke GetDIBits, hDC, hBmp, 0, dHeight, pScanlineBuffer, addr BmpInfo, 0

        ;Now copy from Scanline Buffer to the Pixelmap
        ;Calc skip values
        mov xDstSkipY, $Pxm_Bytes2Skip(dWidth, xdi)
        mov eax, OutRct.left
        shl xax, LOG2_RGBQUAD_SIZE
        mov xSrcSkipY, xax

        ;Calc position of first pixel to transfer in destination space
        mov eax, OutRct.top
        sub eax, SrcRct.top
        add eax, DstPnt.y
        mul [xdi].dWidth
        add eax, OutRct.left
        sub eax, SrcRct.left
        add eax, DstPnt.x
        shl eax, LOG2_RGBQUAD_SIZE
        add xax, [xdi].pPixels
        mov xdi, xax

        ;Initialize transfer loop
        mov xsi, pScanlineBuffer

        ;Do transfer of pixels
        mov edx, dHeight
        test edx, edx
        .while !ZERO?
          mov ecx, dWidth
          add xsi, xSrcSkipY
          rep movsd
          add xdi, xDstSkipY
          dec edx
        .endw

        MemFree pScanlineBuffer
        xor eax, eax                                    ;Return OBJ_OK
      .else
        OCall xdi.ErrorReport, NULL, PXM_OUT_OF_MEMORY
      .endif
    .endif
  .else
    OCall xdi.ErrorReport, NULL, PXM_INVALID_BMP_HANDLE
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Pixelmap.CopyDisplay
; Purpose:    Copy the pixels of a display RECT to the destination on this Pixelmap.
; Arguments:  Arg1: Source Display Device Context.
;             Arg2: -> Source RECT.
;             Arg3: Destination start POINT.
; Return:     eax = Error code.

Method Pixelmap.CopyDisplay, uses xsi, hDispDC:HDC, pSrcRct:PRECT, DstPnt:POINT
  local hMemDDB:HANDLE, hMemDC:HDC, hOldDDB:HANDLE, Rct:RECT, SrcRct:RECT

  SetObject xsi
  .if [xsi].hDIBSection != 0
    m2z Rct.top
    m2z Rct.left
    ;Flip SrcRct if necessary
    mov xcx, pSrcRct
    CloneRect SrcRct, RECT ptr [xcx], xax, xdx
    Pxm_FlipInvertedRect SrcRct
    mov eax, SrcRct.RECT.right
    sub eax, SrcRct.RECT.left
    jz @@EOM
    mov Rct.right, eax
    mov ecx, SrcRct.RECT.bottom
    sub ecx, SrcRct.RECT.top
    jz @@EOM
    mov Rct.bottom, ecx

    invoke CreateCompatibleDC, hDispDC
    .if xax != 0
      mov hMemDC, xax
      mov hMemDDB, $invoke(CreateCompatibleBitmap, hDispDC, Rct.right, Rct.bottom)
      mov hOldDDB, $invoke(SelectObject, hMemDC, hMemDDB)
      invoke BitBlt, hMemDC, 0, 0, Rct.right, Rct.bottom, hDispDC, SrcRct.left, SrcRct.top, SRCCOPY
      OCall xsi.CopyBmp, hMemDC, hMemDDB, addr Rct, DstPnt
      invoke DeleteObject, $invoke(SelectObject, hMemDC, hOldDDB)
      invoke DeleteDC, hMemDC
      xor eax, eax                                      ;Return OBJ_OK
    .else
      OCall xsi.ErrorReport, NULL, PXM_INVALID_DC_HANDLE
    .endif
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Pixelmap.CopyPixelmap
; Purpose:    Copy the pixels contained in a RECT of a source Pixelmap to the destination on this
;             Pixelmap.
; Arguments:  Arg1: Source Pixelmap.
;             Arg2: -> Source RECT.
;             Arg3: Destination start POINT.
; Return:     Nothing.

Method Pixelmap.CopyPixelmap, uses xdi xsi, pSrcPxm:POINTER, pSrcRct:PRECT, DstPnt:POINT
  local xDstSkipY:XWORD, xSrcSkipY:XWORD
  local dWidth:DWORD, dHeight:DWORD
  local SrcSpace:RECT, DstSpace:RECT, OutRct:RECT, SrcRct:RECT

  SetObject xdi
  SetObject xsi,,pSrcPxm

  .if [xsi].hDIBSection != 0 && [xdi].hDIBSection != 0
    ;Flip SrcRct if necessary
    mov xcx, pSrcRct
    CloneRect SrcRct, RECT ptr [xcx], xax, xdx
    Pxm_FlipInvertedRect SrcRct

    ;Clip SrcRct to SrcSpace
    m2z SrcSpace.left
    m2z SrcSpace.top
    m2m SrcSpace.right, [xsi].dWidth, eax
    m2m SrcSpace.bottom, [xsi].dHeight, eax
    Pxm_ClipRect OutRct, SrcRct, SrcSpace

    ;Clip to DstSpace
    mov eax, SrcRct.left
    sub eax, DstPnt.x
    mov DstSpace.left, eax
    add eax, [xdi].dWidth
    mov DstSpace.right, eax
    mov eax, SrcRct.top
    sub eax, DstPnt.y
    mov DstSpace.top, eax
    add eax, [xdi].dHeight
    mov DstSpace.bottom, eax
    Pxm_ClipRect OutRct, OutRct, DstSpace

    ;Calc transfer sizes
    sub eax, ecx
    jz @@EOM
    mov dHeight, eax
    mov eax, OutRct.right
    sub eax, OutRct.left
    jz @@EOM
    mov dWidth, eax

    ;Calc skip values
    mov xDstSkipY, $Pxm_Bytes2Skip(dWidth, xdi)
    mov xSrcSkipY, $Pxm_Bytes2Skip(dWidth, xsi)

    ;Calc position of first pixel to transfer in source space
    mov xsi, $Pxm_PixelAddr(OutRct.left, OutRct.top, xsi)

    ;Calc position of first pixel to transfer in destination space
    mov eax, OutRct.top
    sub eax, SrcRct.top
    add eax, DstPnt.y
    mul [xdi].dWidth
    add eax, OutRct.left
    sub eax, SrcRct.left
    add eax, DstPnt.x
    shl eax, LOG2_RGBQUAD_SIZE
    add xax, [xdi].pPixels
    mov xdi, xax

    ;Do transfer of pixels
    mov edx, dHeight
    test edx, edx
    .while !ZERO?
      mov ecx, dWidth
      rep movsd
      add xdi, xDstSkipY
      add xsi, xSrcSkipY
      dec edx
    .endw
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Pixelmap.CreateDDB
; Purpose:    Create a Device compatible Bitmap from the Pixelmap.
; Arguments:  Arg1: Device Context handle.
; Return:     eax = Bitmap handle or zero if failed.

Method Pixelmap.CreateDDB, uses xsi, hDC:HDC
  SetObject xsi
  .if [xsi].hDIBSection != 0
    lea xdx, [xsi].BmpInfo
    invoke CreateDIBitmap, hDC, xdx, CBM_INIT, [xsi].pPixels, xdx, 0
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Pixelmap.CreateDIB
; Purpose:    Create A Device Independant Bitmap (DIB) from the Pixelmap.
; Arguments:  None.
; Return:     eax = DIB handle or zero if failed.

Method Pixelmap.CreateDIB
  local Bmp:BITMAP

  SetObject xcx
  .if [xcx].hDIBSection != 0
    m2z Bmp.BITMAP.bmType
    mrm Bmp.BITMAP.bmWidth, [xcx].dWidth, eax
    m2m Bmp.BITMAP.bmHeight, [xcx].dHeight, edx
    shl eax, LOG2_RGBQUAD_SIZE
    mov Bmp.BITMAP.bmWidthBytes, eax
    mov Bmp.BITMAP.bmPlanes, 1
    mov Bmp.BITMAP.bmBitsPixel, 32
    m2m Bmp.BITMAP.bmBits, [xcx].pPixels, xdx
    invoke CreateBitmapIndirect, xsp                    ;-> BITMAP structure
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Destructor: Pixelmap.Done
; Purpose:    Finalize the Pixelmap object.
; Arguments:  None.
; Return:     Nothing.

Method Pixelmap.Done, uses xsi
  SetObject xsi
  OCall xsi.Reset
  ACall xsi::Pixelmap.Done
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Pixelmap.ForEachPixel
; Purpose:    Call ActionProc for each pixel in the Pixelmap.
; Arguments:  Arg1: -> Processing procedure.
;             Arg2-3: Parameters used by the processing procedure.
; Return:     Nothing.

Method Pixelmap.ForEachPixel, uses xbx xdi xsi, pActionProc:PPtoPxmProc, xArg1:XWORD, xArg2:XWORD
  SetObject xcx
  mov xdi, pActionProc
  mov eax, [xcx].dWidth
  mul [xcx].dHeight
  mov ebx, eax                                          ;ebx = number of pixels
  mov xsi, [xcx].pPixels
  ReleaseObject
  test ebx, ebx
  .while !ZERO?
    invoke PtoPxmProc ptr xdi, xsi, xArg1, xArg2
    add xsi, RGBQUAD_SIZE
    dec ebx
  .endw
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Pixelmap.GetPixel
; Purpose:    Return the ARGB value of a given pixel.
; Arguments:  Arg1: X location.
;             Arg2: Y location.
; Return:     eax = ARGB value.

Method Pixelmap.GetPixel,, dCoorX:DWORD, dCoorY:DWORD
  SetObject xdx
  mov eax, dCoorY
  .if SDWORD ptr eax >= 0 && SDWORD ptr eax < [xdx].dHeight
    mov ecx, dCoorX
    .if SDWORD ptr ecx >= 0 && SDWORD ptr ecx < [xdx].dWidth
      shl xcx, LOG2_RGBQUAD_SIZE
      add xcx, [xdx].pPixels
      mul [xdx].dWidth
      mov eax, [RGBQUAD_SIZE*xax + xcx]
      BGR2RGB eax
    .else
      DbgWarning "Y coordinate out of range in GetPixel"
      OCall xdx.ErrorReport, NULL, PXM_OUT_OF_Y_RANGE
      xor eax, eax
    .endif
  .else
    DbgWarning "X coordinate out of range in GetPixel"
    OCall xdx.ErrorReport, NULL, PXM_OUT_OF_X_RANGE
    xor eax, eax
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Pixelmap.GetVirtualComponent
; Purpose:    Return the color component of a virtual pixel.
; Arguments:  Arg1: X location (REAL4).
;             Arg2: Y location (REAL4).
;             Arg3: Color channel (PXM_CHANNEL_XXX).
; Return:     eax = Color component value [0..255].
;
;       —————————————— X
;       |  |  |  |  |
;       |——|——|——|——|—
;       |  |00|10|  |
;       |——|——|——|——|—
;       |  |01|11|  |
;       |——|——|——|——|—
;       |  |  |  |  |
;       Y

Method Pixelmap.GetVirtualComponent, uses xbx xsi, r4CoorX:REAL4, r4CoorY:REAL4, dChannel:DWORD
  local sdCoorX0:SDWORD, sdCoorX1:SDWORD, sdCoorY0:SDWORD, sdCoorY1:SDWORD
  local dBuffer:DWORD, wCurFpuCtrl:WORD, wPrvFpuCtrl:WORD
  local xSkipX:SXWORD, xSkipY:XWORD
  local dColor00:DWORD, dColor10:DWORD, dColor01:DWORD, dColor11:DWORD

  SetObject xsi
  fstcw wPrvFpuCtrl                                     ;Store FPU control word
  m2m wCurFpuCtrl, wPrvFpuCtrl, ax                      ;Duplicate value

  fld r4CoorY

  BitSet wCurFpuCtrl, BIT10                             ;Modify the control word to
  BitClr wCurFpuCtrl, BIT11                             ;  round to -inf
  fldcw wCurFpuCtrl                                     ;Restore modified FPU control word
  fist sdCoorY0

  BitClr wCurFpuCtrl, BIT10                             ;Modify the control word to
  BitSet wCurFpuCtrl, BIT11                             ;  round to +inf
  fldcw wCurFpuCtrl                                     ;Restore modified FPU control word
  fist sdCoorY1

  mov eax, sdCoorY1
  .if sdCoorY0 >= 0 && SDWORD ptr eax < [xsi].dHeight
    fisub sdCoorY0
    xor edx, edx
    fld r4CoorX
    cmp eax, sdCoorY0
    je @F
    mov edx, [xsi].dWidth
    shl xdx, LOG2_RGBQUAD_SIZE
  @@:
    mov xSkipY, xdx

    BitSet wCurFpuCtrl, BIT10                           ;Modify the control word to
    BitClr wCurFpuCtrl, BIT11                           ;  round to -inf
    fldcw wCurFpuCtrl                                   ;Restore modified FPU control word
    fist sdCoorX0

    BitClr wCurFpuCtrl, BIT10                           ;Modify the control word to
    BitSet wCurFpuCtrl, BIT11                           ;  round to +inf
    fldcw wCurFpuCtrl                                   ;Restore modified FPU control word
    fist sdCoorX1

    mov ecx, sdCoorX1
    .if sdCoorX0 >= 0 && SDWORD ptr ecx < [xsi].dWidth
      BitClr wCurFpuCtrl, (BIT10 or BIT11)              ;Modify the control word to return rnd(x)
      fldcw wCurFpuCtrl                                 ;Restore modified FPU control word
      mov xbx, [xsi].pGam2LinTable
      fisub sdCoorX0                                    ;A = x - x0, B = y - y0
      xor edx, edx
      fld st(0)
      cmp ecx, sdCoorX0
      je @F
      mov edx, RGBQUAD_SIZE
    @@:
      mov xSkipX, xdx

      fmul st(0), st(2)                                 ;f11 = AxB
      shl xcx, LOG2_RGBQUAD_SIZE
      fsub st(1), st(0)                                 ;f10 = A - AxB
      add xcx, [xsi].pPixels
      fsub st(2), st(0)                                 ;f01 = B - AxB
      mul [xsi].dWidth
      fld1
      lea xdx, [RGBQUAD_SIZE*xax + xcx]
      fsub st(0), st(1)
      fsub st(0), st(2)                                 ;f00 = 1 - f11 - f10 - f01
      fsub st(0), st(3)                                 ;f00, f11, f10, f01

      ;Get the 4 colors we need
      m2m dColor11, DWORD ptr [xdx], eax
      sub xdx, xSkipX
      m2m dColor01, DWORD ptr [xdx], eax
      sub xdx, xSkipY
      m2m dColor00, DWORD ptr [xdx], eax
      add xdx, xSkipX
      m2m dColor10, DWORD ptr [xdx], eax

      ;Process the channel
      mov edx, dChannel
      .if edx == PXM_CHANNEL_ALPHA                      ;Alpha channel ?
        movzx ecx, BYTE ptr [dColor00 + PXM_CHANNEL_OFFSET_ALPHA]
        mov dBuffer, ecx                                ;Alpha channel is linear per definition =>
        fild dBuffer                                    ;  no need of of gamma correction
        movzx ecx, BYTE ptr [dColor11 + PXM_CHANNEL_OFFSET_ALPHA]
        fmul st(0), st(1)
        mov dBuffer, ecx
        fild dBuffer
        movzx ecx, BYTE ptr [dColor10 + PXM_CHANNEL_OFFSET_ALPHA]
        fmul st(0), st(3)
        mov dBuffer, ecx
        faddp st(1), st(0)
        movzx ecx, BYTE ptr [dColor01 + PXM_CHANNEL_OFFSET_ALPHA]
        fild dBuffer
        fmul st(0), st(4)
        mov dBuffer, ecx
        faddp st(1), st(0)
        fild dBuffer
        fmul st(0), st(5)
        faddp st(1), st(0)
        fistp dBuffer
        mov eax, dBuffer
      .else
        mov xax, offset PXM_CHANNEL_OFFSET_TABLE
        movzx xdx, BYTE ptr [xax + xdx]                 ;Convert channel to mem offset
        movzx xcx, BYTE ptr [dColor00 + xdx]
        mov cl, BYTE ptr [xbx + xcx]                    ;Gamma to linear color space
        mov dBuffer, ecx
        fild dBuffer
        movzx ecx, BYTE ptr [dColor11 + xdx]
        mov cl, BYTE ptr [xbx + xcx]                    ;Gamma to linear color space
        fmul st(0), st(1)
        mov dBuffer, ecx
        fild dBuffer
        movzx ecx, BYTE ptr [dColor10 + xdx]
        mov cl, BYTE ptr [xbx + xcx]                    ;Gamma to linear color space
        fmul st(0), st(3)
        mov dBuffer, ecx
        faddp st(1), st(0)
        movzx ecx, BYTE ptr [dColor01 + xdx]
        fild dBuffer
        mov cl, BYTE ptr [xbx + xcx]                    ;Gamma to linear color space
        fmul st(0), st(4)
        mov dBuffer, ecx
        faddp st(1), st(0)
        fild dBuffer
        fmul st(0), st(5)
        faddp st(1), st(0)
        fistp dBuffer
        mov edx, dBuffer
        add xdx, [xsi].pLin2GamTable
        movzx eax, BYTE ptr [xdx]                       ;Linear to Gamma space
      .endif
      fUnload 2

    .else
      DbgWarning "X coordinate out of range in GetVirtualComponent"
      OCall xsi.ErrorReport, NULL, PXM_OUT_OF_X_RANGE
      xor eax, eax
    .endif
    fUnload
  .else
    DbgWarning "Y coordinate out of range in GetVirtualComponent"
    OCall xsi.ErrorReport, NULL, PXM_OUT_OF_Y_RANGE
    xor eax, eax
  .endif
  fUnload
  fldcw wPrvFpuCtrl                                     ;Restore previous FPU control word
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Pixelmap.GetVirtualPixel
; Purpose:    Return the ARGB value of a given Virtual Pixel.
; Arguments:  Arg1: X location (REAL4).
;             Arg2: Y location (REAL4).
; Return:     eax = ARGB value.
;
;       —————————————— X
;       |  |  |  |  |
;       |——|——|——|——|—
;       |  |00|10|  |
;       |——|——|——|——|—
;       |  |01|11|  |
;       |——|——|——|——|—
;       |  |  |  |  |
;       Y

PXM_AverangeChannel macro ChOfs:req
  movzx ecx, BYTE ptr [dColor00 + ChOfs]
  if ChOfs lt 3                                         ;Alpha channel is linear per definition
    mov cl, BYTE ptr [xbx + xcx]                        ;Gamma to linear color space
  endif
  mov dBuffer, ecx
  fild dBuffer
  movzx ecx, BYTE ptr [dColor11 + ChOfs]
  if ChOfs lt 3                                         ;Alpha channel is linear per definition
    mov cl, BYTE ptr [xbx + xcx]                        ;Gamma to linear color space
  endif
  fmul st(0), st(1)
  mov dBuffer, ecx
  fild dBuffer
  movzx ecx, BYTE ptr [dColor10 + ChOfs]
  if ChOfs lt 3                                         ;Alpha channel is linear per definition
    mov cl, BYTE ptr [xbx + xcx]                        ;Gamma to linear color space
  endif
  fmul st(0), st(3)
  mov dBuffer, ecx
  faddp st(1), st(0)
  movzx ecx, BYTE ptr [dColor01 + ChOfs]
  fild dBuffer
  if ChOfs lt 3                                         ;Alpha channel is linear per definition
    mov cl, BYTE ptr [xbx + xcx]                        ;Gamma to linear color space
  endif
  fmul st(0), st(4)
  mov dBuffer, ecx
  faddp st(1), st(0)
  fild dBuffer
  fmul st(0), st(5)
  faddp st(1), st(0)
endm

Method Pixelmap.GetVirtualPixel, uses xbx xsi, r4CoorX:REAL4, r4CoorY:REAL4
  local sdCoorX0:SDWORD, sdCoorX1:SDWORD, sdCoorY0:SDWORD, sdCoorY1:SDWORD
  local dBuffer:DWORD, wCurFpuCtrl:WORD, wPrvFpuCtrl:WORD
  local xSkipX:SXWORD, xSkipY:XWORD
  local dRed:DWORD, dGreen:DWORD, dBlue:DWORD, dAlpha:DWORD
  local dColor00:DWORD, dColor10:DWORD, dColor01:DWORD, dColor11:DWORD

  ANNOTATION use: dBuffer

  SetObject xsi
  fstcw wPrvFpuCtrl                                     ;Store FPU control word
  m2m wCurFpuCtrl, wPrvFpuCtrl, ax                      ;Duplicate value

  fld r4CoorY

  BitSet wCurFpuCtrl, BIT10                             ;Modify the control word to
  BitClr wCurFpuCtrl, BIT11                             ;  round to -inf
  fldcw wCurFpuCtrl                                     ;Restore modified FPU control word
  fist sdCoorY0

  BitClr wCurFpuCtrl, BIT10                             ;Modify the control word to
  BitSet wCurFpuCtrl, BIT11                             ;  round to +inf
  fldcw wCurFpuCtrl                                     ;Restore modified FPU control word
  fist sdCoorY1

  mov eax, sdCoorY1
  .if sdCoorY0 >= 0 && eax < [xsi].dHeight
    fisub sdCoorY0
    xor edx, edx
    fld r4CoorX
    cmp eax, sdCoorY0
    je @F
    mov edx, [xsi].dWidth
    shl xdx, LOG2_RGBQUAD_SIZE
  @@:
    mov xSkipY, xdx

    BitSet wCurFpuCtrl, BIT10                           ;Modify the control word to
    BitClr wCurFpuCtrl, BIT11                           ;  round to -inf
    fldcw wCurFpuCtrl                                   ;Restore modified FPU control word
    fist sdCoorX0

    BitClr wCurFpuCtrl, BIT10                           ;Modify the control word to
    BitSet wCurFpuCtrl, BIT11                           ;  round to +inf
    fldcw wCurFpuCtrl                                   ;Restore modified FPU control word
    fist sdCoorX1

    mov ecx, sdCoorX1
    .if sdCoorX0 >= 0 && ecx < [xsi].dWidth
      BitClr wCurFpuCtrl, (BIT10 or BIT11)              ;Modify the control word to return rnd(x)
      fldcw wCurFpuCtrl                                 ;Restore modified FPU control word
      mov xbx, [xsi].pGam2LinTable
      fisub sdCoorX0                                    ;A = x - x0, B = y - y0
      xor edx, edx
      fld st(0)
      cmp ecx, sdCoorX0
      je @F
      mov xdx, RGBQUAD_SIZE
    @@:
      mov xSkipX, xdx

      fmul st(0), st(2)                                 ;f11 = AxB
      shl ecx, LOG2_RGBQUAD_SIZE
      fsub st(1), st(0)                                 ;f10 = A - AxB
      add xcx, [xsi].pPixels
      fsub st(2), st(0)                                 ;f01 = B - AxB
      mul [xsi].dWidth
      fld1
      lea edx, [RGBQUAD_SIZE*xax + xcx]
      fsub st(0), st(1)
      fsub st(0), st(2)                                 ;f00 = 1 - f11 - f10 - f01
      fsub st(0), st(3)                                 ;f00, f11, f10, f01

      ;Get the 4 colors we need
      m2m dColor11, DWORD ptr [xdx], eax
      sub xdx, xSkipX
      m2m dColor01, DWORD ptr [xdx], eax
      sub xdx, xSkipY
      m2m dColor00, DWORD ptr [xdx], eax
      add xdx, xSkipX
      m2m dColor10, DWORD ptr [xdx], eax

      ;Process each channel
      PXM_AverangeChannel PXM_CHANNEL_OFFSET_BLUE       ;Blue channel
      fistp dBlue
      PXM_AverangeChannel PXM_CHANNEL_OFFSET_GREEN      ;Green channel
      fistp dGreen
      PXM_AverangeChannel PXM_CHANNEL_OFFSET_RED        ;Red channel
      fistp dRed
      PXM_AverangeChannel PXM_CHANNEL_OFFSET_ALPHA      ;Alpha channel
      fistp dAlpha

      ;Compose it
      mov ah, BYTE ptr dAlpha
      fUnload
      mov al, BYTE ptr dBlue
      fUnload
      shl eax, 16
      mov ah, BYTE ptr dGreen
      mov al, BYTE ptr dRed
      OCall pSelf::Pixelmap.Linear2Gamma, eax

    .else
      DbgWarning "X coordinate out of range in GetVirtualPixel"
      OCall xsi.ErrorReport, NULL, PXM_OUT_OF_X_RANGE
      xor eax, eax
    .endif
    fUnload
  .else
    DbgWarning "Y coordinate out of range in GetVirtualPixel"
    OCall xsi.ErrorReport, NULL, PXM_OUT_OF_Y_RANGE
    xor eax, eax
  .endif
  fUnload
  fldcw wPrvFpuCtrl                                     ;Restore previous FPU control word
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Pixelmap.Init
; Purpose:    Initialize the Pixelmap object.
; Arguments:  Arg1: -> Owner object.
;             Arg2: Pixelmap width.
;             Arg3: Pixelmap height.
; Return:     Nothing.

Method Pixelmap.Init, uses xsi, pOwner:POINTER, dWidth:DWORD, dHeight:DWORD
  local hDesktop:HWND, hDC:HDC

  SetObject xsi
  ACall xsi.Init, pOwner

  mov hDesktop, $invoke(GetDesktopWindow)
  mov hDC, $invoke(GetDC, hDesktop)
  mov [xsi].hDC, $invoke(CreateCompatibleDC, hDC)
  invoke ReleaseDC, hDesktop, hDC

  mrm [xsi].dWidth, dWidth, eax
  mov [xsi].BmpInfo.bmiHeader.biWidth, eax
  mrm [xsi].dHeight, dHeight, ecx
  mul ecx
  shl eax, LOG2_RGBQUAD_SIZE
  mov [xsi].BmpInfo.BITMAPINFO.bmiHeader.biSizeImage, eax
  neg ecx                                 ;Top down scanline arrangement
  mov [xsi].BmpInfo.bmiHeader.biHeight, ecx

  invoke CreateDIBSection, 0, addr [xsi].BmpInfo, DIB_RGB_COLORS, addr [xsi].pPixels, 0, 0
  .if xax != 0
    mov [xsi].hDIBSection, xax            ;System object handle
    mov [xsi].hPrvBmp, $invoke(SelectObject, [xsi].hDC, [xsi].hDIBSection)
    invoke GdiFlush
  .else
    OCall xsi.ErrorReport, NULL, PXM_INIT_FAILED
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Pixelmap.InitGammaTables
; Purpose:    Initialize 2 Gamma/Linear Space transformation tables. By default, all Pixelmap
;             instances share the same tables that are initialized with a Gamma value of 2.2.
;             If a single instance should use customized tables, the pGam2Lin and pLin2Gam pointers
;             have to be used to attach the new customized tables to the object instance.
; Arguments:  Arg1: Gamma value. Usually a value of 2.2 or 2.5is used for standard monitors.
;                   Value 1.0 is used to switch off the Gamma correction.
; Return:     Nothing.

Method Pixelmap.InitGammaTables, uses xsi, r4Gamma:REAL4
  local dSrcBuffer:DWORD, dDstBuffer:DWORD
;  local Stm:DiskStream

  SetObject xsi
  mov eax, 255
  mov dSrcBuffer, eax
  fild dSrcBuffer
  fld r4Gamma
  fld1
  fdivrp st(1), st(0)
  mov xcx, offset Lin2GamTable + 255
@@:
  fld st(0)                               ;Duplicate exponent
  fild dSrcBuffer
  fdiv st(0), st(3)
  fPower
  fmul st(0), st(2)
  fistp dDstBuffer
  mov dl, BYTE ptr dDstBuffer
  mov BYTE ptr [ecx], dl
  dec ecx
  dec dSrcBuffer
  jnz @B
  fUnload 2
  m2m [xsi].pLin2GamTable, offset Lin2GamTable, xax

  mov eax, 255
  mov dSrcBuffer, eax
  fild dSrcBuffer
  fld r4Gamma
  mov xcx, offset Gam2LinTable + 255
@@:
  fld st(0)                               ;Duplicate exponent
  fild dSrcBuffer
  fdiv st(0), st(3)
  fPower
  fmul st(0), st(2)
  fistp dDstBuffer
  mov dl, BYTE ptr dDstBuffer
  mov BYTE ptr [ecx], dl
  dec ecx
  dec dSrcBuffer
  jnz @B
  fUnload 2
  m2m [xsi].pGam2LinTable, offset Gam2LinTable, xax

;  New Stm::DiskStream.Init, NULL, "GammaTable.stm"
;  OCall Stm::DiskStream.BinWrite, offset Lin2GamTable, 256
;  OCall Stm::DiskStream.BinWrite, offset Gam2LinTable, 256
;  OCall Stm::DiskStream.Done

MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Pixelmap.Load
; Purpose:    Load the Pixelmap from a stream object.
; Arguments:  Arg1: -> Stream object.
;             Arg2: -> Owner object.
; Return:     Nothing.

Method Pixelmap.Load, uses xsi, pStream:$ObjPtr(Stream), pOwner:POINTER
  SetObject xsi
  OCall pStream::Stream.BinRead, addr [xsi].dWidth, 2*sizeof(DWORD)
  OCall xsi.Init, pOwner, [xsi].dWidth, [xsi].dHeight
  .if [xsi].hDIBSection != 0
    OCall pStream::Stream.BinRead, [xsi].pPixels, [xsi].BmpInfo.BITMAPINFO.bmiHeader.biSizeImage
  .else
    OCall xsi.ErrorReport, NULL, PXM_STREAMLOAD_FAILED
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Pixelmap.LoadBmp
; Purpose:    Copy the pixels of a Bitmap (DDB or DIB) to this Pixelmap.
; Arguments:  Arg1: -> Owner object.
;             Arg2: Source Device Context handle.
;             Arg3: Source Bitmap handle.
; Return:     Nothing.

Method Pixelmap.LoadBmp, uses xsi, pOwner:POINTER, hDC:HDC, hBmp:HBITMAP
  local Bmp:BITMAP

  SetObject xsi
  invoke GetObject, hBmp, sizeof Bmp, addr Bmp
  .if eax != 0
    OCall xsi.Init, pOwner, Bmp.BITMAP.bmWidth, Bmp.BITMAP.bmHeight
    invoke GetDIBits, hDC, hBmp, 0, [xsi].dHeight, [xsi].pPixels, addr [xsi].BmpInfo, 0
    .if eax == 0
      OCall xsi.ErrorReport, NULL, PXM_LOADBMP_FAILED
    .endif
  .else
    OCall xsi.ErrorReport, NULL, PXM_INVALID_BMP_HANDLE
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Pixelmap.LoadFileA
; Purpose:    Load a Bitmap from a file.
; Arguments:  Arg1: -> ANSI File Name.
; Return:     Nothing.

Method Pixelmap.LoadFileA, uses xbx xdi xsi, pFileName:PSTRINGA
  local pIPicture:POINTER
  local hTmpDC:HDC, hCmpDC:HDC, hPrvBmp:HBITMAP
  local dHmWidth:DWORD, dHmHeight:DWORD, dNegHmHeight:DWORD
  local hDDB:HANDLE, cFileName[MAX_PATH]:CHR

  SetObject xsi
  invoke GetFullPathNameA, pFileName, lengthof cFileName, addr cFileName, NULL
  .if eax < lengthof cFileName
    .if eax != 0
      ;First, we need the filename in Unicode for OleLoadPicturePath
      mov xdi, $StackAlloc(2*MAX_PATH)
      invoke StrA2StrW, xdi, addr cFileName
      ;Now we can create a picture object
      lea xbx, pIPicture
      invoke OleLoadPicturePath, xdi, NULL, NULL, NULL, offset IID_IPicture, xbx
      .if FAILED(eax)
        ;We didn't get the file to open, assume bad filename
        OCall xsi.ErrorReport, NULL, PXM_LOADFILE_FAILED
      .else
        ;Now we are ready to get the hBipmap, we farm this out for reuseability
        mov hCmpDC, $invoke(GetDC, 0)           ;Get a DC to work with => Screen DC
        .if $invoke(CreateCompatibleDC, xax) == 0
          xor ebx, ebx
        .else
          mov hTmpDC, xax
          ;Read out the width and height of the IPicture object
          ICall pIPicture::IPicture.get_Width, addr dHmWidth
          ICall pIPicture::IPicture.get_Height, addr dHmHeight

          ;Convert himetric to pixels
          invoke GetDeviceCaps, hCmpDC, LOGPIXELSX
          invoke MulDiv, dHmWidth, eax, HIMETRIC_INCH
          mov [xsi].dWidth, eax

          invoke GetDeviceCaps, hCmpDC, LOGPIXELSY
          invoke MulDiv, dHmHeight, eax, HIMETRIC_INCH
          mov [xsi].dHeight, eax
          mov eax, dHmHeight
          neg eax
          mov dNegHmHeight, eax

          .if $invoke(CreateCompatibleBitmap, hCmpDC, [xsi].dWidth, [xsi].dHeight) == 0
            OCall xsi.ErrorReport, NULL, PXM_LOADFILE_FAILED
          .else
            .if $invoke(SelectObject, hTmpDC, xax) == 0
              OCall xsi.ErrorReport, NULL, PXM_LOADFILE_FAILED
            .else
              mov hPrvBmp, xax
              ;Now we have our bitmap mounted onto our temporary DC, let's blit to it
              ICall pIPicture::IPicture.Render, hTmpDC, 0, 0, [xsi].dWidth, [xsi].dHeight, 0, \
                                                dHmHeight, dHmWidth, dNegHmHeight, NULL
              .if FAILED(eax)
                OCall xsi.ErrorReport, NULL, PXM_IPICTURE_FAILED
                invoke DeleteObject, $invoke(SelectObject, hTmpDC, hPrvBmp)
                OCall xsi.ErrorReport, NULL, PXM_LOADFILE_FAILED
              .else
                ;We now have the bitmap blitted, let's get it off the dc and clean up.
                ;We're not going to check for errors, cause we did our importaint thing
                ;and if these fail now, other things will fall apart anyway
                mov hDDB, $invoke(SelectObject, hTmpDC, hPrvBmp)
                OCall xsi.LoadBmp, xsi, hCmpDC, hDDB
                invoke DeleteObject, hDDB
              .endif
            .endif
          .endif
          invoke DeleteDC, hTmpDC
        .endif
        invoke ReleaseDC, 0, hCmpDC

        ICall pIPicture::IPicture.Release
      .endif
      StackFree
    .else
      OCall xsi.ErrorReport, NULL, PXM_INVALID_FILENAME
    .endif
  .else
    OCall xsi.ErrorReport, NULL, PXM_FILENAME_TOO_LONG
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Pixelmap.LoadFileW
; Purpose:    Load a Bitmap from a file.
; Arguments:  Arg1: -> WIDE File Name.
; Return:     Nothing.

Method Pixelmap.LoadFileW, uses xbx xdi xsi, pFileName:PSTRINGW
  local pIPicture:POINTER
  local hTmpDC:HDC, hCmpDC:HDC, hPrvBmp:HBITMAP
  local dHmWidth:DWORD, dHmHeight:DWORD, dNegHmHeight:DWORD
  local hDDB:HANDLE, cFileName[2*MAX_PATH]:CHR

  SetObject xsi
  invoke GetFullPathNameW, pFileName, lengthof cFileName, addr cFileName, NULL
  .if eax < lengthof cFileName
    .if eax != 0
      lea xdi, cFileName
      ;Now we can create a picture object
      lea xbx, pIPicture
      invoke OleLoadPicturePath, xdi, NULL, NULL, NULL, offset IID_IPicture, xbx
      .if FAILED(eax)
        ;We didn't get the file to open, assume bad filename
        OCall xsi.ErrorReport, NULL, PXM_LOADFILE_FAILED
      .else
        ;Now we are ready to get the hBipmap, we farm this out for reuseability
        mov hCmpDC, $invoke(GetDC, 0)           ;Get a DC to work with => Screen DC
        .if $invoke(CreateCompatibleDC, xax) == 0
          xor ebx, ebx
        .else
          mov hTmpDC, xax
          ;Read out the width and height of the IPicture object
          ICall pIPicture::IPicture.get_Width, addr dHmWidth
          ICall pIPicture::IPicture.get_Height, addr dHmHeight

          ;Convert himetric to pixels
          invoke GetDeviceCaps, hCmpDC, LOGPIXELSX
          invoke MulDiv, dHmWidth, eax, HIMETRIC_INCH
          mov [xsi].dWidth, eax

          invoke GetDeviceCaps, hCmpDC, LOGPIXELSY
          invoke MulDiv, dHmHeight, eax, HIMETRIC_INCH
          mov [xsi].dHeight, eax
          mov eax, dHmHeight
          neg eax
          mov dNegHmHeight, eax

          .if $invoke(CreateCompatibleBitmap, hCmpDC, [xsi].dWidth, [xsi].dHeight) == 0
            OCall xsi.ErrorReport, NULL, PXM_LOADFILE_FAILED
          .else
            .if $invoke(SelectObject, hTmpDC, xax) == 0
              OCall xsi.ErrorReport, NULL, PXM_LOADFILE_FAILED
            .else
              mov hPrvBmp, xax
              ;Now we have our bitmap mounted onto our temporary DC, let's blit to it
              ICall pIPicture::IPicture.Render, hTmpDC, 0, 0, [xsi].dWidth, [xsi].dHeight, 0, \
                                                dHmHeight, dHmWidth, dNegHmHeight, NULL
              .if FAILED(eax)
                OCall xsi.ErrorReport, NULL, PXM_IPICTURE_FAILED
                invoke DeleteObject, $invoke(SelectObject, hTmpDC, hPrvBmp)
                OCall xsi.ErrorReport, NULL, PXM_LOADFILE_FAILED
              .else
                ;We now have the bitmap blitted, let's get it off the dc and clean up.
                ;We're not going to check for errors, cause we did our importaint thing
                ;and if these fail now, other things will fall apart anyway
                mov hDDB, $invoke(SelectObject, hTmpDC, hPrvBmp)
                OCall xsi.LoadBmp, xsi, hCmpDC, hDDB
                invoke DeleteObject, hDDB
              .endif
            .endif
          .endif
          invoke DeleteDC, hTmpDC
        .endif
        invoke ReleaseDC, 0, hCmpDC

        ICall pIPicture::IPicture.Release
      .endif
    .else
      OCall xsi.ErrorReport, NULL, PXM_INVALID_FILENAME
    .endif
  .else
    OCall xsi.ErrorReport, NULL, PXM_FILENAME_TOO_LONG
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Pixelmap.SaveFileA
; Purpose:    Save the Pixelmap to disk.
; Arguments:  Arg1: -> ANSI FileName
;             Arg2: File format (PXM_FORMAT_PXM, ...)
; Return:     eax = Error code.

Method Pixelmap.SaveFileA, uses xsi, pFileName:PSTRINGA, dFileFormat:DWORD
  local BmpFileHdr:BITMAPFILEHEADER
  local hFile:HANDLE, dBytesWritten:DWORD

  SetObject xsi
  .if [xsi].hDIBSection != 0
    .if dFileFormat == PXM_FORMAT_PXM
      mov BmpFileHdr.BITMAPFILEHEADER.bfType, "MB"    ;"BM" signature
      mov eax, [xsi].BmpInfo.BITMAPINFO.bmiHeader.biSizeImage
      add eax, sizeof BmpFileHdr + sizeof BITMAPINFOHEADER
      mov BmpFileHdr.BITMAPFILEHEADER.bfSize, eax
      m2z BmpFileHdr.BITMAPFILEHEADER.bfReserved1
      m2z BmpFileHdr.BITMAPFILEHEADER.bfReserved2
      mov BmpFileHdr.BITMAPFILEHEADER.bfOffBits, sizeof BmpFileHdr + sizeof BITMAPINFOHEADER

      invoke CreateFileA, pFileName, GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_ARCHIVE, 0
      .if xax == INVALID_HANDLE_VALUE
        OCall xsi.ErrorReport, NULL, PXM_FILEOPEN_FAILED
      .else
        mov hFile, xax
        invoke WriteFile, hFile, addr BmpFileHdr, sizeof BmpFileHdr, addr dBytesWritten, NULL
        .if eax == FALSE
          OCall xsi.ErrorReport, NULL, PXM_FILEWRITE_FAILED
        .else
          invoke WriteFile, hFile, addr [xsi].BmpInfo, sizeof BITMAPINFOHEADER, addr dBytesWritten, NULL
          .if eax == FALSE
            OCall xsi.ErrorReport, NULL, PXM_FILEWRITE_FAILED
          .else
            invoke WriteFile, hFile, [xsi].pPixels, [xsi].BmpInfo.BITMAPINFO.bmiHeader.biSizeImage,\
                              addr dBytesWritten, NULL
            .if eax == FALSE
              OCall xsi.ErrorReport, NULL, PXM_FILEWRITE_FAILED
            .endif
          .endif
        .endif
        invoke CloseHandle, hFile
        xor eax, eax
      .endif
    .else
      OCall xsi.ErrorReport, NULL, PXM_INVALID_FILE_FORMAT
    .endif
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Pixelmap.SaveFileW
; Purpose:    Save the Pixelmap to disk.
; Arguments:  Arg1: -> WIDE FileName
;             Arg2: File format (PXM_FORMAT_PXM, ...)
; Return:     eax = Error code.

Method Pixelmap.SaveFileW, uses xsi, pFileName:PSTRINGW, dFileFormat:DWORD
  local BmpFileHdr:BITMAPFILEHEADER
  local hFile:HANDLE, dBytesWritten:DWORD

  SetObject xsi
  .if [xsi].hDIBSection != 0
    .if dFileFormat == PXM_FORMAT_PXM
      mov BmpFileHdr.BITMAPFILEHEADER.bfType, "MB"    ;"BM" signature
      mov eax, [xsi].BmpInfo.BITMAPINFO.bmiHeader.biSizeImage
      add eax, sizeof BmpFileHdr + sizeof BITMAPINFOHEADER
      mov BmpFileHdr.BITMAPFILEHEADER.bfSize, eax
      m2z BmpFileHdr.BITMAPFILEHEADER.bfReserved1
      m2z BmpFileHdr.BITMAPFILEHEADER.bfReserved2
      mov BmpFileHdr.BITMAPFILEHEADER.bfOffBits, sizeof BmpFileHdr + sizeof BITMAPINFOHEADER

      invoke CreateFileW, pFileName, GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_ARCHIVE, 0
      .if xax == INVALID_HANDLE_VALUE
        OCall xsi.ErrorReport, NULL, PXM_FILEOPEN_FAILED
      .else
        mov hFile, xax
        invoke WriteFile, hFile, addr BmpFileHdr, sizeof BmpFileHdr, addr dBytesWritten, NULL
        .if eax == FALSE
          OCall xsi.ErrorReport, NULL, PXM_FILEWRITE_FAILED
        .else
          invoke WriteFile, hFile, addr [xsi].BmpInfo, sizeof BITMAPINFOHEADER, addr dBytesWritten, NULL
          .if eax == FALSE
            OCall xsi.ErrorReport, NULL, PXM_FILEWRITE_FAILED
          .else
            invoke WriteFile, hFile, [xsi].pPixels, [xsi].BmpInfo.BITMAPINFO.bmiHeader.biSizeImage,\
                              addr dBytesWritten, NULL
            .if eax == FALSE
              OCall xsi.ErrorReport, NULL, PXM_FILEWRITE_FAILED
            .endif
          .endif
        .endif
        invoke CloseHandle, hFile
        xor eax, eax
      .endif
    .else
      OCall xsi.ErrorReport, NULL, PXM_INVALID_FILE_FORMAT
    .endif
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Pixelmap.SetPixel
; Purpose:    Set the ARGB value of a given pixel.
; Arguments:  Arg1: X location.
;             Arg2: Y location.
;             Arg3: New ARGB value.
; Return:     Nothing.

Method Pixelmap.SetPixel,, dCoorX:DWORD, dCoorY:DWORD, dARGB:DWORD
  SetObject xdx
  .if [xdx].hDIBSection != 0
    mov eax, dCoorY
    .if SDWORD ptr eax >= 0 && SDWORD ptr eax < [xdx].dHeight
      mov ecx, dCoorX
      .if SDWORD ptr ecx >= 0 && SDWORD ptr ecx < [xdx].dWidth
        shl xcx, LOG2_RGBQUAD_SIZE
        add xcx, [xdx].pPixels
        mul [xdx].dWidth
        mov edx, dARGB
        RGB2BGR edx
        mov [RGBQUAD_SIZE*xax + xcx], edx
      .else
;        DbgWarning "X coordinate out of range in SetPixel"
      .endif
    .else
;      DbgWarning "Y coordinate out of range in SetPixel"
    .endif
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Pixelmap.SetVirtualComponent
; Purpose:    Set a channel component of a given virtual pixel and perform a Gamma Correction on
;             the modified pixels. Alpha values of the background pixels are adjusted.
; Arguments:  Arg1: X location.
;             Arg2: Y location.
;             Arg3: Channel (PXM_CHANNEL_XXX).
;             Arg3: Component value.
; Return:     Nothing.

PXM_SetComponent macro
  local JumpTable, @@Blue, @@Green, @@Red, @@Alpha

.const
  JumpTable label POINTER
  POINTER offset @@Blue
  POINTER offset @@Green
  POINTER offset @@Red
  POINTER offset @@Alpha

.code
  mov edx, dChannel
  mov xax, offset PXM_CHANNEL_OFFSET_TABLE
  movzx eax, BYTE ptr [xax + xdx]
  movzx edx, BYTE ptr [xsi + xax]
  add xdx, pGam2LinTable
  movzx ecx, BYTE ptr [xdx]                             ;ecx = back linear component

  fld1                                                  ;Calc complement to 1
  fsub st(0), st(1)

  mov xcx, offset JumpTable
  jmp POINTER ptr [xcx + sizeof(POINTER)*xax]

@@Blue:
  fild dComponent
  fmul st(0), st(2)
  mov dBuffer, ecx
  fild dBuffer
  fmul st(0), st(2)
  faddp st(1), st(0)
  fistp dBuffer
  .if SDWORD ptr dBuffer > 255
    mov ecx, 255
  .elseif SDWORD ptr dBuffer < 0
    xor ecx, ecx
  .else
    mov edx, dBuffer
    add xdx, pLin2GamTable
    mov cl, BYTE ptr [xdx]
  .endif
  mov BYTE ptr [xsi], cl                                ;Blue
  jmp @F

@@Green:
  fild dComponent
  fmul st(0), st(2)
  mov dBuffer, ecx
  fild dBuffer
  fmul st(0), st(2)
  faddp st(1), st(0)
  fistp dBuffer
  .if SDWORD ptr dBuffer > 255
    mov ecx, 255
  .elseif SDWORD ptr dBuffer < 0
    xor ecx, ecx
  .else
    mov edx, dBuffer
    add xdx, pLin2GamTable
    mov cl, BYTE ptr [xdx]
  .endif
  mov BYTE ptr [xsi + PXM_CHANNEL_OFFSET_GREEN], cl     ;Green
  jmp @F

@@Red:
  fild dComponent
  fmul st(0), st(2)
  mov dBuffer, ecx
  fild dBuffer
  fmul st(0), st(2)
  faddp st(1), st(0)
  fistp dBuffer
  .if SDWORD ptr dBuffer > 255
    mov ecx, 255
  .elseif SDWORD ptr dBuffer < 0
    xor ecx, ecx
  .else
    mov edx, dBuffer
    add xdx, pLin2GamTable
    mov cl, BYTE ptr [xdx]
  .endif
  mov BYTE ptr [xsi + PXM_CHANNEL_OFFSET_RED], cl       ;Red
  jmp @F

@@Alpha:
  fild dComponent
  fmul st(0), st(2)
  mov dBuffer, ecx
  fild dBuffer
  fmul st(0), st(2)
  faddp st(1), st(0)
  fistp dBuffer
  .if SDWORD ptr dBuffer > 255
    mov ecx, 255
  .elseif SDWORD ptr dBuffer < 0
    xor ecx, ecx
  .else
    mov ecx, dBuffer
  .endif
  mov BYTE ptr [xsi + PXM_CHANNEL_OFFSET_ALPHA], cl     ;Alpha

@@:
  fUnload
endm

Method Pixelmap.SetVirtualComponent, uses xsi, r4CoorX:REAL4, r4CoorY:REAL4, dChannel:DWORD, dComponent:DWORD
  local sdCoorX0:SDWORD, sdCoorX1:SDWORD, sdCoorY0:SDWORD, sdCoorY1:SDWORD
  local dBuffer:DWORD, wCurFpuCtrl:WORD, wPrvFpuCtrl:WORD
  local xSkipX:SXWORD, xSkipY:XWORD
  local sdRed:SDWORD, sdGreen:SDWORD, sdBlue:SDWORD, sdAlpha:SDWORD
  local dBackLinColor:DWORD, dForeLinColor:DWORD
  local dBackLinComp:DWORD, dForeLinComp:DWORD, pGam2LinTable:POINTER, pLin2GamTable:POINTER

  ANNOTATION use: dBackLinColor dBackLinComp dBuffer dForeLinColor dForeLinComp sdAlpha sdBlue sdGreen sdRed

  SetObject xsi
  m2m pGam2LinTable, [xsi].pGam2LinTable, xax
  m2m pLin2GamTable, [xsi].pLin2GamTable, xax

  fstcw wPrvFpuCtrl                                     ;Store FPU control word
  m2m wCurFpuCtrl, wPrvFpuCtrl, ax                      ;Duplicate value

  fld r4CoorY

  BitSet wCurFpuCtrl, BIT10                             ;Modify the control word to
  BitClr wCurFpuCtrl, BIT11                             ;  round to -inf
  fldcw wCurFpuCtrl                                     ;Restore modified FPU control word
  fist sdCoorY0

  BitClr wCurFpuCtrl, BIT10                             ;Modify the control word to
  BitSet wCurFpuCtrl, BIT11                             ;  round to +inf
  fldcw wCurFpuCtrl                                     ;Restore modified FPU control word
  fist sdCoorY1

  mov eax, sdCoorY1
  .if sdCoorY0 >= 0 && SDWORD ptr eax < [xsi].dHeight
    fisub sdCoorY0                                      ;B = y - y0
    xor edx, edx
    fld r4CoorX
    cmp eax, sdCoorY0
    je @F
    mov edx, [xsi].dWidth
    shl xdx, LOG2_RGBQUAD_SIZE
  @@:
    mov xSkipY, xdx

    fist sdCoorX1

    BitSet wCurFpuCtrl, BIT10                           ;Modify the control word to
    BitClr wCurFpuCtrl, BIT11                           ;  round to -inf
    fldcw wCurFpuCtrl                                   ;Restore modified FPU control word
    mov ecx, sdCoorX1
    fist sdCoorX0

    .if sdCoorX0 >= 0 && SDWORD ptr ecx < [xsi].dWidth
      BitClr wCurFpuCtrl, (BIT10 or BIT11)              ;Modify the control word to return rnd(x)
      fldcw wCurFpuCtrl                                 ;Restore modified FPU control word
      xor edx, edx
      fisub sdCoorX0                                    ;A = x - x0, B = y - y0
      cmp ecx, sdCoorX0
      je @F
      mov edx, RGBQUAD_SIZE
    @@:
      mov xSkipX, xdx

      shl ecx, LOG2_RGBQUAD_SIZE
      add xcx, [xsi].pPixels
      mul [xsi].dWidth
      lea xsi, [RGBQUAD_SIZE*xax + xcx]                 ;xsi -> Poisition right/bottom

      .if dChannel != PXM_CHANNEL_ALPHA                 ;Alpha is unchanged
        mov edx, dComponent
        add xdx, pGam2LinTable                          ;  transform from Gamma space to Lin space
        movzx ecx, BYTE ptr [xdx]
        mov dComponent, ecx
      .endif

      .if xSkipX == 0 && xSkipY == 0
        fUnload
        fld1
        PXM_SetComponent                                ;xsi -> Position 00
        fUnload

      .elseif xSkipX == 0                               ;A = 0, B <> 0
        fUnload
        fld1
        fsub st(0), st(1)                               ;1 - B, B
        fxch st(1)

        PXM_SetComponent                                ;xsi -> Position 01
        fUnload
        sub xsi, xSkipY                                 ;xsi -> Position 00
        PXM_SetComponent

      .elseif xSkipY == 0                               ;A <> 0, B = 0
        fxch st(1)
        fUnload
        fld1
        fsub st(0), st(1)                               ;1 - A, A
        fxch st(1)

        PXM_SetComponent                                ;xsi -> Position 10
        fUnload
        sub xsi, xSkipX                                 ;xsi -> Position 00
        PXM_SetComponent

      .else
        fld st(0)
        fmul st(0), st(2)                               ;f11 = AxB
        fsub st(1), st(0)                               ;f10 = A - AxB
        fsub st(2), st(0)                               ;f01 = B - AxB
        fld1
        fsub st(0), st(1)
        fsub st(0), st(2)                               ;f00 = 1 - f11 - f10 - f01
        fsub st(0), st(3)                               ;f00, f11, f10, f01

        sub xsi, xSkipX                                 ;xsi -> Poisition 01
        sub xsi, xSkipY                                 ;xsi -> Poisition 00
        PXM_SetComponent
        fUnload
        add xsi, xSkipX                                 ;xsi -> Poisition 10
        add xsi, xSkipY                                 ;xsi -> Poisition 11
        PXM_SetComponent
        fUnload
        sub xsi, xSkipY                                 ;xsi -> Poisition 10
        PXM_SetComponent
        fUnload
        sub xsi, xSkipX                                 ;xsi -> Poisition 00
        add xsi, xSkipY                                 ;xsi -> Poisition 01
        PXM_SetComponent
      .endif
      jmp @F
    .else
      DbgWarning "X coordinate out of range in SetVirtualComponent"
    .endif
    fUnload
  .else
    DbgWarning "Y coordinate out of range in SetVirtualComponent"
  .endif
@@:
  fUnload
  fldcw wPrvFpuCtrl                                     ;Restore previous FPU control word
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:    Pixelmap.SetVirtualPixel
; Purpose:   Set an ARGB value of a given virtual pixel and perform a Gamma Correction on the
;            modified pixels. Alpha values of the background pixels are adjusted.
; Arguments: Arg1: X location.
;            Arg2: Y location.
;            Arg3: New ARGB value.
; Return:    Nothing.

PXM_SetColors macro
  mov dBackLinColor, $32($OCall(pSelf::Pixelmap.Gamma2Linear, DWORD ptr [xsi])) ;ABGR

  fld1                                                  ;Calc complement to 1
  fsub st(0), st(1)

  movzx ecx, BYTE ptr dForeLinColor + 2                 ;Blue
  mov dBuffer, ecx
  fild dBuffer
  movzx ecx, BYTE ptr dBackLinColor + PXM_CHANNEL_OFFSET_BLUE
  fmul st(0), st(2)
  mov dBuffer, ecx
  fild dBuffer
  fmul st(0), st(2)
  faddp st(1), st(0)
  fistp sdBlue

  movzx ecx, BYTE ptr dForeLinColor + 1                 ;Green
  mov dBuffer, ecx
  fild dBuffer
  movzx ecx, BYTE ptr dBackLinColor + PXM_CHANNEL_OFFSET_GREEN
  fmul st(0), st(2)
  mov dBuffer, ecx
  fild dBuffer
  fmul st(0), st(2)
  faddp st(1), st(0)
  fistp sdGreen

  movzx ecx, BYTE ptr dForeLinColor + 0                 ;Red
  mov dBuffer, ecx
  fild dBuffer
  movzx ecx, BYTE ptr dBackLinColor + PXM_CHANNEL_OFFSET_RED
  fmul st(0), st(2)
  mov dBuffer, ecx
  fild dBuffer
  fmul st(0), st(2)
  faddp st(1), st(0)
  fistp sdRed

  movzx ecx, BYTE ptr dForeLinColor + 3                 ;Alpha
  mov dBuffer, ecx
  fild dBuffer
  movzx ecx, BYTE ptr dBackLinColor + PXM_CHANNEL_OFFSET_ALPHA
  fmul st(0), st(2)
  mov dBuffer, ecx
  fild dBuffer
  fmul st(0), st(2)
  faddp st(1), st(0)
  fistp sdAlpha

  fUnload

  ;Compose the new color and prevent a channel over- or underflow.
  if @Cpu and CPU_686
    mov edx, 255
    xor ecx, ecx
    mov eax, sdRed
    cmp eax, ecx
    cmovl eax, ecx
    cmp eax, edx
    cmovg eax, edx
    mov sdRed, eax

    mov eax, sdGreen
    cmp eax, ecx
    cmovl eax, ecx
    cmp eax, edx
    cmovg eax, edx
    mov sdGreen, eax

    mov eax, sdBlue
    cmp eax, ecx
    cmovl eax, ecx
    cmp eax, edx
    cmovg eax, edx
    mov sdBlue, eax

    mov eax, sdAlpha
    cmp eax, ecx
    cmovl eax, ecx
    cmp eax, edx
    cmovg eax, edx
    mov sdAlpha, eax
  else
    .if sdRed > 255
      mov sdRed, 255
    .elseif sdRed < 0
      m2z sdRed
    .endif
    .if sdGreen > 255
      mov sdGreen, 255
    .elseif sdGreen < 0
      m2z sdGreen
    .endif
    .if sdBlue > 255
      mov sdBlue, 255
    .elseif sdBlue < 0
      m2z sdBlue
    .endif
    .if sdAlpha > 255
      mov sdAlpha, 255
    .elseif sdAlpha < 0
      m2z sdAlpha
    .endif
  endif
  mov ah, BYTE ptr sdAlpha
  mov al, BYTE ptr sdRed
  shl eax, 16
  mov ah, BYTE ptr sdGreen
  mov al, BYTE ptr sdBlue

  OCall pSelf::Pixelmap.Linear2Gamma, eax

  mov DWORD ptr [xsi], eax
endm

Method Pixelmap.SetVirtualPixel, uses xsi, r4CoorX:REAL4, r4CoorY:REAL4, dARGB:DWORD
  local sdCoorX0:SDWORD, sdCoorX1:SDWORD, sdCoorY0:SDWORD, sdCoorY1:SDWORD
  local dBuffer:DWORD, wCurFpuCtrl:WORD, wPrvFpuCtrl:WORD
  local xSkipX:SXWORD, xSkipY:XWORD
  local sdRed:SDWORD, sdGreen:SDWORD, sdBlue:SDWORD, sdAlpha:SDWORD
  local dBackLinColor:DWORD, dForeLinColor:DWORD

  ANNOTATION use: dBackLinColor dBuffer sdAlpha sdBlue sdGreen sdRed

  SetObject xsi
  fstcw wPrvFpuCtrl                                     ;Store FPU control word
  m2m wCurFpuCtrl, wPrvFpuCtrl, ax                      ;Duplicate value

  fld r4CoorY

  BitSet wCurFpuCtrl, BIT10                             ;Modify the control word to
  BitClr wCurFpuCtrl, BIT11                             ;  round to -inf
  fldcw wCurFpuCtrl                                     ;Restore modified FPU control word
  fist sdCoorY0

  BitClr wCurFpuCtrl, BIT10                             ;Modify the control word to
  BitSet wCurFpuCtrl, BIT11                             ;  round to +inf
  fldcw wCurFpuCtrl                                     ;Restore modified FPU control word
  fist sdCoorY1

  mov eax, sdCoorY1
  .if sdCoorY0 >= 0 && SDWORD ptr eax < [xsi].dHeight
    fisub sdCoorY0                                      ;B = y - y0
    xor edx, edx
    fld r4CoorX
    cmp eax, sdCoorY0
    je @F
    mov edx, [xsi].dWidth
    shl xdx, LOG2_RGBQUAD_SIZE
  @@:
    mov xSkipY, xdx

    fist sdCoorX1

    BitSet wCurFpuCtrl, BIT10                           ;Modify the control word to
    BitClr wCurFpuCtrl, BIT11                           ;  round to -inf
    fldcw wCurFpuCtrl                                   ;Restore modified FPU control word
    mov ecx, sdCoorX1
    fist sdCoorX0

    .if sdCoorX0 >= 0 && SDWORD ptr ecx < [xsi].dWidth
      BitClr wCurFpuCtrl, (BIT10 or BIT11)              ;Modify the control word to return rnd(x)
      fldcw wCurFpuCtrl                                 ;Restore modified FPU control word
      xor edx, edx
      fisub sdCoorX0                                    ;A = x - x0, B = y - y0
      cmp ecx, sdCoorX0
      je @F
      mov xdx, RGBQUAD_SIZE
    @@:
      mov xSkipX, xdx

      shl xcx, LOG2_RGBQUAD_SIZE
      add xcx, [xsi].pPixels
      mul [xsi].dWidth
      lea xsi, [RGBQUAD_SIZE*xax + xcx]                 ;xsi -> Poisition right/bottom

      .if xSkipX == 0 && xSkipY == 0
        fUnload
        mov dForeLinColor, $32($OCall(pSelf::Pixelmap.Gamma2Linear, dARGB)) ;ARGB
        fld1
        PXM_SetColors                                   ;xsi -> Position 00

      .elseif xSkipX == 0                               ;A = 0, B <> 0
        mov dForeLinColor, $32($OCall(pSelf::Pixelmap.Gamma2Linear, dARGB)) ;ARGB

        fUnload
        fld1
        fsub st(0), st(1)                               ;1 - B, B
        fxch st(1)

        PXM_SetColors                                   ;xsi -> Position 01
        fUnload
        sub xsi, xSkipY                                 ;xsi -> Position 00
        PXM_SetColors

      .elseif xSkipY == 0                               ;A <> 0, B = 0
        mov dForeLinColor, $32($OCall(pSelf::Pixelmap.Gamma2Linear, dARGB)) ;ARGB

        fxch st(1)
        fUnload
        fld1
        fsub st(0), st(1)                               ;1 - A, A
        fxch st(1)

        PXM_SetColors                                   ;xsi -> Position 10
        fUnload
        sub xsi, xSkipX                                 ;xsi -> Position 00
        PXM_SetColors

      .else
        mov dForeLinColor, $32($OCall(pSelf::Pixelmap.Gamma2Linear, dARGB)) ;ARGB

        fld st(0)
        fmul st(0), st(2)                               ;f11 = AxB
        fsub st(1), st(0)                               ;f10 = A - AxB
        fsub st(2), st(0)                               ;f01 = B - AxB
        fld1
        fsub st(0), st(1)
        fsub st(0), st(2)                               ;f00 = 1 - f11 - f10 - f01
        fsub st(0), st(3)                               ;f00, f11, f10, f01

        sub xsi, xSkipX                                 ;xsi -> Poisition 01
        sub xsi, xSkipY                                 ;xsi -> Poisition 00
        PXM_SetColors
        fUnload
        add xsi, xSkipX                                 ;xsi -> Poisition 10
        add xsi, xSkipY                                 ;xsi -> Poisition 11
        PXM_SetColors
        fUnload
        sub xsi, xSkipY                                 ;xsi -> Poisition 10
        PXM_SetColors
        fUnload
        sub xsi, xSkipX                                 ;xsi -> Poisition 00
        add xsi, xSkipY                                 ;xsi -> Poisition 01
        PXM_SetColors
      .endif
      jmp @F
    .else
      DbgWarning "X coordinate out of range in SetVirtualPixel"
    .endif
    fUnload
  .else
    DbgWarning "Y coordinate out of range in SetVirtualPixel"
  .endif
@@:
  fUnload
  fldcw wPrvFpuCtrl                                     ;Restore previous FPU control word
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:    Pixelmap.Store
; Purpose:   Store the Pixelmap in a stream object.
; Arguments: Arg1: -> stream object.
; Return:    Nothing.

Method Pixelmap.Store, uses xsi, pStream:$ObjPtr(Stream)
  SetObject xsi
  .if [xsi].hDIBSection != 0
    lea xax, [xsi].dWidth
    OCall pStream::Stream.BinWrite, xax, 2 * sizeof(DWORD)  ;dWidth, dHeight
    OCall pStream::Stream.BinWrite, [xsi].pPixels, [xsi].BmpInfo.BITMAPINFO.bmiHeader.biSizeImage
  .else
    OCall pStream::Stream.BinWrite64, 0                 ;dWidth = 0, dHeight = 0
  .endif
MethodEnd


; ==================================================================================================
; Static methods
; ==================================================================================================

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:    Pixelmap.AlphaBlend
; Purpose:   Blend a source Pixelmap on a destination RECT
; Arguments: Arg1: -> Source Pixelmap.
;            Arg2: -> Destination RECT.
;            Arg3: Source starting POINT.
; Return:    Nothing.

Method Pixelmap.AlphaBlend, uses xbx xdi xsi, pSrcPxm:POINTER, pSrcRct:PRECT, DstPnt:POINT
  local xDstSkipY:XWORD, xSrcSkipY:XWORD
  local dWidth:DWORD, dHeight:DWORD, dXPos:DWORD
  local SrcSpace:RECT, DstSpace:RECT, OutRct:RECT, SrcRct:RECT
  local dDens1:DWORD, dDens2:DWORD

  SetObject xdi
  SetObject xsi,, pSrcPxm

  .if [xsi].hDIBSection != 0 && [xdi].hDIBSection != 0
    ;Flip SrcRct if necessary
    mov xcx, pSrcRct
    CloneRect SrcRct, RECT ptr [xcx], xax, xdx
    Pxm_FlipInvertedRect SrcRct

    ;Clip SrcRct to SrcSpace
    m2z SrcSpace.left
    m2z SrcSpace.top
    m2m SrcSpace.right, [xsi].dWidth, eax
    m2m SrcSpace.bottom, [xsi].dHeight, eax
    Pxm_ClipRect OutRct, SrcRct, SrcSpace

    ;Clip to DstSpace
    mov eax, SrcRct.left
    sub eax, DstPnt.x
    mov DstSpace.left, eax
    add eax, [xdi].dWidth
    mov DstSpace.right, eax
    mov eax, SrcRct.top
    sub eax, DstPnt.y
    mov DstSpace.top, eax
    add eax, [xdi].dHeight
    mov DstSpace.bottom, eax
    Pxm_ClipRect OutRct, OutRct, DstSpace

    ;Calc transfer sizes
    sub eax, ecx
    jz @@EOM
    mov dHeight, eax
    mov eax, OutRct.right
    sub eax, OutRct.left
    jz @@EOM
    mov dWidth, eax

    ;Calc skip values
    mov xDstSkipY, $Pxm_Bytes2Skip(dWidth, xdi)
    mov xSrcSkipY, $Pxm_Bytes2Skip(dWidth, xsi)

    ;Calc position of first pixel to transfer in source space
    mov xsi, $Pxm_PixelAddr(OutRct.left, OutRct.top, xsi)
    ReleaseObject

    ;Calc position of first pixel that will be transfered into destination space
    mov eax, OutRct.top
    sub eax, SrcRct.top
    add eax, DstPnt.y
    mul [xdi].dWidth
    add eax, OutRct.left
    sub eax, SrcRct.left
    add eax, DstPnt.x
    shl eax, LOG2_RGBQUAD_SIZE
    add xax, [xdi].pPixels
    mov xdi, xax
    ReleaseObject

    ;Do alfablending of pixels
    mov eax, dHeight
    test eax, eax
    .while !ZERO?
      mrm dXPos, dWidth, eax
      test eax, eax
      .while !ZERO?
        mov eax, [xsi]
        Pxm_Alpha_Densities eax
        mov eax, [xdi]                                  ;Get destiantion original pixel
        Pxm_Blend_ARGB eax, ebx, dDens2
        mov ecx, [xsi]                                  ;Get source original pixel
        Pxm_Blend_ARGB ecx, edx, dDens1
        Pxm_BlendMerge_ARGB eax, ebx, ecx, edx
        mov [xdi], eax                                  ;Store new color
        add xsi, RGBQUAD_SIZE
        add xdi, RGBQUAD_SIZE
        dec dXPos
      .endw
      add xdi, xDstSkipY
      add xsi, xSrcSkipY
      dec dHeight
    .endw
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Pixelmap.Brightness
; Purpose:    Adjust the brightness of the source Pixelmap.
; Arguments:  Arg1: Luminicense value (0 = dark, 255 = bright)
; Return:     Nothing.
; Notes:      - Original code by Edgar Hansen - Donkey -

Method Pixelmap.Brightness, uses xbx xdi xsi, dLum:DWORD
  local dLuma:DWORD

  SetObject xsi
  .if [xsi].hDIBSection != 0
    and dLuma, 0FFh
    mov ebx, [xsi].BmpInfo.BITMAPINFO.bmiHeader.biSizeImage     ;In BYTEs
    shr ebx, LOG2_RGBQUAD_SIZE                                  ;In pixels
    mov xsi, [xsi].pPixels
    .if dLum > 127
      mov ecx, 256
      sub ecx, dLum
    .else
      mov ecx, dLum
    .endif
    mov dLuma, ecx
    ReleaseObject

    .while !ZERO?                                       ;ebx != 0
      mov eax, [xsi]
      .if dLum > 127
        not eax
      .endif
      mov edi, eax

      ;Copy alfa channel
      mov ecx, edi
      shr ecx, 16

      ;Process red channel
      mov eax, edi
      shr eax, 16
      and eax, 0FFh
      mul BYTE ptr dLuma
      shr eax, 7
      mov cl, al
      shl ecx, 16

      ;Process green channel
      mov eax, edi
      shr eax, 8
      and eax, 0FFh
      mul BYTE ptr dLuma
      shr eax, 7
      mov ch, al

      ;Process blue channel
      mov eax, edi
      and eax, 0FFh
      mul BYTE ptr dLuma
      shr eax, 7
      mov cl, al

      .if dLum > 127
        not ecx
      .endif

      mov [xsi], ecx
      add xsi, RGBQUAD_SIZE
      dec ebx
    .endw
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Pixelmap.Convolve3x3
; Purpose:    Perform a 3x3 pixel convolution on the source Pixelmap.
; Arguments:  Arg1: -> Source Pixelmap.
;             Arg2: -> Source RECT.
;             Arg3: Destination origin.
;             Arg4: -> Filter data (see "Some usual 3x3 convolution filter data").
; Return:     Nothing.
; Link:       https://en.wikipedia.org/wiki/Kernel_(image_processing)
; Note:       Minimal size = 3x3
;
;        ———————————————
;       | 1 |   2   | 3 |           1,3,7,9 Corners
;       |———|———————|———|           2,4,6,8 bands
;       |   |       |   |           5 inner rect
;       | 4 |   5   | 6 |           
;       |   |       |   |           
;       |———|———————|———|
;       | 7 |   8   | 9 |
;        ———————————————


PXM_Conv_Eval macro Kapa:=<1>
  ;Load the pixel pointed to by xcx
  mov edx, [xcx]
  movzx eax, dl
  mov dBuffer, eax
  fild dBuffer
  movzx eax, dh
  mov dBuffer, eax
  fild dBuffer
  shr edx, 16
  movzx eax, dl
  mov dBuffer, eax
  fild dBuffer

  ;Multiply the color components by the filter data pointed to by xbx
  fld REAL4 ptr [xbx]
  repeat Kapa - 1
    fadd st(0), st(0)
  endm
  fmul st(3), st(0)
  fmul st(2), st(0)
  fmulp st(1), st(0)
endm

PXM_Conv_Add macro
  ;Add color components to the previous values in the FPU stack
  faddp st(3), st(0)
  faddp st(3), st(0)
  faddp st(3), st(0)
endm

$PXM_GetNewColor macro
  ;Compute new color
  fistp sdRed
  fistp sdGreen
  fistp sdBlue

  ;Compose the new color and prevent a channel over- or underflow
  .if sdRed > 255
    mov sdRed, 255
  .elseif sdRed < 0
    m2z sdRed
  .endif
  .if sdGreen > 255
    mov sdGreen, 255
  .elseif sdGreen < 0
    m2z sdGreen
  .endif
  .if sdBlue > 255
    mov sdBlue, 255
  .elseif sdBlue < 0
    m2z sdBlue
  .endif
  mov ah, 255                                           ;Set Alpha = 255
  mov al, BYTE ptr sdRed
  shl eax, 16
  mov ah, BYTE ptr sdGreen
  mov al, BYTE ptr sdBlue
  exitm <eax>
endm

Method Pixelmap.Convolve3x3, uses xbx xdi xsi, pSrcPxm:POINTER, pSrcRct:PRECT, DstPnt:POINT, \
                                               pFilterData:POINTER
  local xDstSkipY:XWORD, xSrcSkipY:XWORD, xFilterSkipY:XWORD
  local dWidth:DWORD, dHeight:DWORD, pFilterFirstData:ptr REAL4
  local SrcSpace:RECT, DstSpace:RECT, OutRct:RECT, SrcRct:RECT, dCounter:DWORD
  local dBuffer:DWORD, sdRed:SDWORD, sdGreen:SDWORD, sdBlue:SDWORD
  local xSrcByteWidth:XWORD, xDstByteWidth:XWORD

  ANNOTATION use: dBuffer sdBlue sdGreen sdRed

  SetObject xdi
  SetObject xsi,, pSrcPxm

  .if [xsi].hDIBSection != 0 && [xdi].hDIBSection != 0
    ;Flip SrcRct if necessary
    mov xcx, pSrcRct
    CloneRect SrcRct, RECT ptr [xcx], xax, xdx
    Pxm_FlipInvertedRect SrcRct

    ;Clip SrcRct to SrcSpace
    m2z SrcSpace.left
    m2z SrcSpace.top
    m2m SrcSpace.right, [xsi].dWidth, eax
    m2m SrcSpace.bottom, [xsi].dHeight, eax
    Pxm_ClipRect OutRct, SrcRct, SrcSpace

    ;Clip to DstSpace
    mov eax, SrcRct.left
    sub eax, DstPnt.x
    mov DstSpace.left, eax
    add eax, [xdi].dWidth
    mov DstSpace.right, eax
    mov eax, SrcRct.top
    sub eax, DstPnt.y
    mov DstSpace.top, eax
    add eax, [xdi].dHeight
    mov DstSpace.bottom, eax
    Pxm_ClipRect OutRct, OutRct, DstSpace

    ;Calc transfer sizes
    sub eax, ecx
    jle @@EOM
    mov dHeight, eax
    mov eax, OutRct.right
    sub eax, OutRct.left
    jle @@EOM
    mov dWidth, eax

    ;Calc filter skip values
    mov eax, [xsi].dWidth
    shl xax, LOG2_RGBQUAD_SIZE
    mov xSrcByteWidth, xax
    lea xcx, [xax - RGBQUAD_SIZE]
    mov xFilterSkipY, xcx
    mov eax, [xdi].dWidth
    shl xax, LOG2_RGBQUAD_SIZE
    mov xDstByteWidth, xax

    ;Calc position of first pixel to transfer in source space
    mov xsi, $Pxm_PixelAddr(OutRct.left, OutRct.top, xsi)
    ReleaseObject

    ;Calc position of first pixel to transfer in destination space
    mov eax, OutRct.top
    sub eax, SrcRct.top
    add eax, DstPnt.y
    mul [xdi].dWidth
    add eax, OutRct.left
    sub eax, SrcRct.left
    add eax, DstPnt.x
    shl eax, LOG2_RGBQUAD_SIZE
    add xax, [xdi].pPixels
    mov xdi, xax
    ReleaseObject

;   ———— Top-Left Corner —————————————————————————————————————————————————————
    mov xbx, pFilterData                                ;xbx -> filter data
    add xbx, 4*REAL4_SIZE
    mov xcx, xsi
    PXM_Conv_Eval 1                                     ;Evaluate color at (+0,+0)
    add xcx, RGBQUAD_SIZE
    add xbx, REAL4_SIZE
    PXM_Conv_Eval 2                                     ;Evaluate color at (+1,+0)
    PXM_Conv_Add
    add xcx, xFilterSkipY
    add xbx, 2*REAL4_SIZE
    add xcx, RGBQUAD_SIZE
    PXM_Conv_Eval 2                                     ;Evaluate color at (+0,+1)
    PXM_Conv_Add
    add xcx, RGBQUAD_SIZE
    add xbx, REAL4_SIZE
    PXM_Conv_Eval 3                                     ;Evaluate color at (+1,+1)
    PXM_Conv_Add
    mov [xdi], $PXM_GetNewColor()                       ;Store the new generated color
    fUnload 1                                           ;Free the last FPU register
;    mov xax, pSelf
;    DbgBmp [xax].$Obj(Pixelmap).hDIBSection, "Top-Left Corner"

;   ———— Upper Band ——————————————————————————————————————————————————————————
    ;Do convolution of upper band
    add xdi, RGBQUAD_SIZE
    mov xbx, pFilterData                                ;xbx -> filter data
    add xbx, 3*REAL4_SIZE                               ;xbx -> filter 4th data element
    mov pFilterFirstData, xbx
    sub xFilterSkipY, RGBQUAD_SIZE
    mov eax, dWidth
    sub eax, 2                                          ;Skip corners
    mov dCounter, eax
    test eax, eax
    .while !ZERO?
      mov xbx, pFilterFirstData
      mov xcx, xsi
      PXM_Conv_Eval                                     ;Evaluate color at (-1,+0)
      add xcx, RGBQUAD_SIZE
      add xbx, REAL4_SIZE
      PXM_Conv_Eval                                     ;Evaluate color at (+0,+0)
      PXM_Conv_Add
      add xcx, RGBQUAD_SIZE
      add xbx, REAL4_SIZE
      PXM_Conv_Eval                                     ;Evaluate color at (+1,+0)
      PXM_Conv_Add

      add xcx, xFilterSkipY
      add xbx, REAL4_SIZE
      PXM_Conv_Eval 2                                   ;Evaluate color at (-1,+1)
      PXM_Conv_Add
      add xcx, RGBQUAD_SIZE
      add xbx, REAL4_SIZE
      PXM_Conv_Eval 2                                   ;Evaluate color at (+0,+1)
      PXM_Conv_Add
      add xcx, RGBQUAD_SIZE
      add xbx, REAL4_SIZE
      PXM_Conv_Eval 2                                   ;Evaluate color at (+1,+1)
      PXM_Conv_Add

      mov [xdi], $PXM_GetNewColor()                     ;Store the new generated color

      add xsi, RGBQUAD_SIZE
      add xdi, RGBQUAD_SIZE
      dec dCounter
    .endw
    fUnload 1                                           ;Free the last FPU register
;    mov xax, pSelf
;    DbgBmp [xax].$Obj(Pixelmap).hDIBSection, "Upper Band"

;   ———— Top-Right Corner ————————————————————————————————————————————————————
    mov xbx, pFilterFirstData                           ;Same as before
    add xFilterSkipY, RGBQUAD_SIZE
    mov xcx, xsi
    PXM_Conv_Eval 2                                     ;Evaluate color at (-1,+0)
    add xcx, RGBQUAD_SIZE
    add xbx, REAL4_SIZE
    PXM_Conv_Eval 1                                     ;Evaluate color at (+0,+0)
    PXM_Conv_Add
    add xcx, xFilterSkipY
    add xbx, 2*REAL4_SIZE
    PXM_Conv_Eval 3                                     ;Evaluate color at (-1,+1)
    PXM_Conv_Add
    add xcx, RGBQUAD_SIZE
    add xbx, REAL4_SIZE
    PXM_Conv_Eval 2                                     ;Evaluate color at (+0,+1)
    PXM_Conv_Add
    mov [xdi], $PXM_GetNewColor()                       ;Store the new generated color
    fUnload 1                                           ;Free the last FPU register
;    mov xax, pSelf
;    DbgBmp [xax].$Obj(Pixelmap).hDIBSection, "Top-Right Corner"
    
;   ———— Right Band ——————————————————————————————————————————————————————————
    m2m xSrcSkipY, xSrcByteWidth, xax
    mrm xDstSkipY, xDstByteWidth, xax
    add xdi, xax

    ;Do convolution of right band
    mov eax, dHeight
    sub eax, 2                                          ;Skip corners
    mov dCounter, eax
    test eax, eax
    .while !ZERO?
      mov xbx, pFilterData                              ;xbx -> filter data
      mov xcx, xsi
      PXM_Conv_Eval 2                                   ;Evaluate color at (-1,-1)
      add xcx, RGBQUAD_SIZE
      add xbx, REAL4_SIZE
      PXM_Conv_Eval 1                                   ;Evaluate color at (+0,-1)
      PXM_Conv_Add
      add xcx, xFilterSkipY
      add xbx, 2*REAL4_SIZE
  
      PXM_Conv_Eval 2                                   ;Evaluate color at (-1,+0)
      PXM_Conv_Add
      add xcx, RGBQUAD_SIZE
      add xbx, REAL4_SIZE
      PXM_Conv_Eval 1                                   ;Evaluate color at (+0,+0)
      PXM_Conv_Add
      add xcx, xFilterSkipY
      add xbx, 2*REAL4_SIZE
  
      PXM_Conv_Eval 2                                   ;Evaluate color at (-1,+1)
      PXM_Conv_Add
      add xcx, RGBQUAD_SIZE
      add xbx, REAL4_SIZE
      PXM_Conv_Eval 1                                   ;Evaluate color at (+0,+1)
      PXM_Conv_Add
  
      mov [xdi], $PXM_GetNewColor()                     ;Store the new generated color
  
      add xsi, xSrcSkipY
      add xdi, xDstSkipY
      dec dCounter
    .endw
    fUnload 1                                           ;Free the last FPU register
    mov xax, pSelf
    DbgBmp [xax].$Obj(Pixelmap).hDIBSection, "Right Band"

;   ———— Bottom-Right Corner —————————————————————————————————————————————————
    mov xbx, pFilterData                                ;xbx -> filter data
    mov xcx, xsi
    PXM_Conv_Eval 3                                     ;Evaluate color at (-1,-1)
    add xcx, RGBQUAD_SIZE
    add xbx, REAL4_SIZE
    PXM_Conv_Eval 2                                     ;Evaluate color at (+0,-1)
    PXM_Conv_Add
    add xcx, xFilterSkipY
    add xbx, 2*REAL4_SIZE
    PXM_Conv_Eval 2                                     ;Evaluate color at (-1,+0)
    PXM_Conv_Add
    add xcx, RGBQUAD_SIZE
    add xbx, REAL4_SIZE
    PXM_Conv_Eval 1                                     ;Evaluate color at (+0,+0)
    PXM_Conv_Add
    mov [xdi], $PXM_GetNewColor()                       ;Store the new generated color
    fUnload 1                                           ;Free the last FPU register
;    mov xax, pSelf
;    DbgBmp [xax].$Obj(Pixelmap).hDIBSection, "Bottom-Right Corner"

;   ———— Lower Band ——————————————————————————————————————————————————————————
    sub xsi, 2*RGBQUAD_SIZE
    sub xdi, RGBQUAD_SIZE
 
    ;Do convolution of lower band
    mov eax, dWidth
    sub eax, 2                                          ;Skip corners
    mov dCounter, eax
    test eax, eax
    .while !ZERO?
      mov xbx, pFilterData                              ;xbx -> filter data
      mov xcx, xsi
      PXM_Conv_Eval 2                                   ;Evaluate color at (-1,-1)
      add xcx, RGBQUAD_SIZE
      add xbx, REAL4_SIZE
      PXM_Conv_Eval 2                                   ;Evaluate color at (+0,-1)
      PXM_Conv_Add
      add xcx, RGBQUAD_SIZE
      add xbx, REAL4_SIZE
      PXM_Conv_Eval 2                                   ;Evaluate color at (+1,-1)
      PXM_Conv_Add
  
      add xcx, xFilterSkipY
      add xbx, REAL4_SIZE
      PXM_Conv_Eval 1                                   ;Evaluate color at (-1,+0)
      PXM_Conv_Add
      add xcx, RGBQUAD_SIZE
      add xbx, REAL4_SIZE
      PXM_Conv_Eval 1                                   ;Evaluate color at (+0,+0)
      PXM_Conv_Add
      add xcx, RGBQUAD_SIZE
      add xbx, REAL4_SIZE
      PXM_Conv_Eval 1                                   ;Evaluate color at (+1,+0)
      PXM_Conv_Add
  
      mov [xdi], $PXM_GetNewColor()                     ;Store the new generated color
  
      sub xsi, RGBQUAD_SIZE
      sub xdi, RGBQUAD_SIZE
      dec dCounter
    .endw
    fUnload 1                                           ;Free the last FPU register
    mov xax, pSelf
    DbgBmp [xax].$Obj(Pixelmap).hDIBSection, "Lower Band"

;   ———— Bottom-Left Corner ——————————————————————————————————————————————————
    add xsi, 2*RGBQUAD_SIZE
    mov xbx, pFilterData                                ;xbx -> filter data
    add xbx, REAL4_SIZE
    mov xcx, xsi
    PXM_Conv_Eval 2                                     ;Evaluate color at (+0,-1)
    add xcx, RGBQUAD_SIZE
    add xbx, REAL4_SIZE
    PXM_Conv_Eval 3                                     ;Evaluate color at (+1,-1)
    PXM_Conv_Add
    add xcx, xFilterSkipY
    add xbx, 2*REAL4_SIZE
    PXM_Conv_Eval 1                                     ;Evaluate color at (+0,+0)
    PXM_Conv_Add
    add xcx, RGBQUAD_SIZE
    add xbx, REAL4_SIZE
    PXM_Conv_Eval 2                                     ;Evaluate color at (+1,+0)
    PXM_Conv_Add
    mov [xdi], $PXM_GetNewColor()                       ;Store the new generated color
    fUnload 1                                           ;Free the last FPU register
;    mov xax, pSelf
;    DbgBmp [xax].$Obj(Pixelmap).hDIBSection, "Bottom-Left Corner"

;   ———— Left Band ———————————————————————————————————————————————————————————
    sub xsi, xFilterSkipY
    sub xsi, RGBQUAD_SIZE
    sub xdi, xFilterSkipY
    sub xdi, RGBQUAD_SIZE

    ;Do convolution of left band
    mov xbx, pFilterData                                ;xbx -> filter data
    add xbx, REAL4_SIZE
    mov pFilterFirstData, xbx
    mov eax, dHeight
    sub eax, 2
    mov dCounter, eax
    test eax, eax
    .while !ZERO?
      mov xbx, pFilterFirstData
      mov xcx, xsi
      PXM_Conv_Eval 1                                   ;Evaluate color at (-1,+0)
      add xcx, RGBQUAD_SIZE
      add xbx, REAL4_SIZE
      PXM_Conv_Eval 2                                   ;Evaluate color at (+0,+0)
      PXM_Conv_Add
      add xcx, xFilterSkipY
      add xbx, 2*REAL4_SIZE
  
      PXM_Conv_Eval 1                                   ;Evaluate color at (+1,+0)
      PXM_Conv_Add
      add xcx, RGBQUAD_SIZE
      add xbx, REAL4_SIZE
      PXM_Conv_Eval 2                                   ;Evaluate color at (-1,+1)
      PXM_Conv_Add
      add xcx, xFilterSkipY
      add xbx, 2*REAL4_SIZE
  
      PXM_Conv_Eval 1                                   ;Evaluate color at (+0,+1)
      PXM_Conv_Add
      add xcx, RGBQUAD_SIZE
      add xbx, REAL4_SIZE
      PXM_Conv_Eval 2                                   ;Evaluate color at (+1,+1)
      PXM_Conv_Add
  
      mov [xdi], $PXM_GetNewColor()                     ;Store the new generated color
  
      sub xsi, xSrcSkipY
      sub xdi, xDstSkipY
      dec dCounter
    .endw
    fUnload 1                                           ;Free the last FPU register
;    mov xax, pSelf
;    DbgBmp [xax].$Obj(Pixelmap).hDIBSection, "Left Band"

;   ———— Inner Rect ——————————————————————————————————————————————————————————
    ;Calc inner rect skip values
    add xsi, xSrcSkipY
    add xdi, xDstSkipY
    add xdi, RGBQUAD_SIZE

    sub xFilterSkipY, RGBQUAD_SIZE
    mov eax, dWidth
    sub eax, 2
    shl xax, LOG2_RGBQUAD_SIZE
    sub xDstSkipY, xax
    sub xSrcSkipY, xax

    ;Do convolution of inner RECT
    sub dHeight, 2                                      ;Skip bands
    .while !ZERO?
      m2m dCounter, dWidth, eax
      sub dCounter, 2                                   ;Skip bands  
      .while !ZERO?
        mov xbx, pFilterData                            ;xbx -> filter data
        mov xcx, xsi
        PXM_Conv_Eval 1                                 ;Evaluate color at -1,-1
        add xcx, RGBQUAD_SIZE
        add xbx, REAL4_SIZE
        PXM_Conv_Eval 1                                 ;Evaluate color at +0,-1
        PXM_Conv_Add
        add xcx, RGBQUAD_SIZE
        add xbx, REAL4_SIZE
        PXM_Conv_Eval 1                                 ;Evaluate color at +1,-1
        PXM_Conv_Add

        add xcx, xFilterSkipY
        add xbx, REAL4_SIZE
        PXM_Conv_Eval 1                                 ;Evaluate color at -1,+0
        PXM_Conv_Add
        add xcx, RGBQUAD_SIZE
        add xbx, REAL4_SIZE
        PXM_Conv_Eval 1                                 ;Evaluate color at +0,+0
        PXM_Conv_Add
        add xcx, RGBQUAD_SIZE
        add xbx, REAL4_SIZE
        PXM_Conv_Eval 1                                 ;Evaluate color at +1,+0
        PXM_Conv_Add

        add xcx, xFilterSkipY
        add xbx, REAL4_SIZE
        PXM_Conv_Eval 1                                 ;Evaluate color at -1,+1
        PXM_Conv_Add
        add xcx, RGBQUAD_SIZE
        add xbx, REAL4_SIZE
        PXM_Conv_Eval 1                                 ;Evaluate color at +0,+1
        PXM_Conv_Add
        add xcx, RGBQUAD_SIZE
        add xbx, REAL4_SIZE
        PXM_Conv_Eval 1                                 ;Evaluate color at +1,+1
        PXM_Conv_Add

        mov [xdi], $PXM_GetNewColor()                   ;Store the new generated color

        add xsi, RGBQUAD_SIZE
        add xdi, RGBQUAD_SIZE
        dec dCounter
      .endw
      add xsi, xSrcSkipY
      add xdi, xDstSkipY
      dec dHeight
    .endw
    fUnload 1                                           ;Free the last FPU register

;    mov xax, pSelf
;    DbgBmp [xax].$Obj(Pixelmap).hDIBSection, "Inner Rect"

  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Pixelmap.DrawCircle
; Purpose:    Draw a Circle on the Pixelmap.
; Arguments:  Arg1: x coordinate of the center of the circle.
;             Arg2: y coordinate of the center of the circle.
;             Arg3: Radius in Pixels.
;             Arg4: Color to use.

Method Pixelmap.DrawCircle, uses xsi, sdPosX:SDWORD, sdPosY:SDWORD, dRadius:SDWORD, dColor:DWORD
  local x:DWORD, y:DWORD
  local r4Step:REAL4, r4Angle:REAL4

  SetObject xsi
  fld1                                                  ;Calculate the r4Angle of a triangle whose
  mov eax, dRadius                                      ;base is the dRadius, and whose side is 1.0
  fildReg eax                                           ;This is the inverse tangent of 1/dRadius
  fdiv                                                  ;Note that this value is in radians
  fArcTan
  fstp r4Step

  m2z x
  m2z y

  m2z r4Angle
  .repeat
    fld r4Angle                                         ;X and Y position are calculated via trig
    fsincos
    fimul dRadius
    fRndDn
    fistp y
    fimul dRadius
    fRndDn
    fistp x

    mov edx, sdPosX
    add edx, x
    mov eax, sdPosY
    add eax, y
    OCall xsi.SetPixel, edx, eax, dColor

    ;Increment r4Angle
    fld r4Step
    fadd r4Angle
    fst r4Angle

    ;Check if we have passed "2PI" (a full circle)
    fldpi
    fldpi
    fadd
    fsubr
    fstpReg eax
    .ifBitSet eax, BIT31
      .break
    .endif
  .until FALSE
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Pixelmap.DrawLine
; Purpose:    Draw a line on the Pixelmap.
; Arguments:  Arg1: Start x coordinate.
;             Arg2: start y coordinate.
;             Arg3: End x coordinate.
;             Arg4: End y coordinate.
;             Arg5: Color to use.
; Return:     Nothing.

Method Pixelmap.DrawLine, uses xsi, x0:SDWORD, y0:SDWORD, x1:SDWORD, y1:SDWORD, dColor:DWORD
  local sdDeltaY:SDWORD, sdDeltaX:SDWORD, sdStepX:SDWORD, sdStepY:SDWORD, sdFraction:SDWORD

  SetObject xsi

  mov eax, y1
  sub eax, y0
  mov sdDeltaY, eax

  mov eax, x1
  sub eax, x0
  mov sdDeltaX, eax

  .if sdDeltaY < 0
    xor eax, eax
    sub eax, sdDeltaY
    mov sdDeltaY, eax
    mov sdStepY, -1
  .else
    mov sdStepY, 1
  .endif
  .if sdDeltaX < 0
    xor eax, eax
    sub eax, sdDeltaX
    mov sdDeltaX, eax
    mov sdStepX, -1
  .else
    mov sdStepX, 1
  .endif

  shl sdDeltaY, 1
  shl sdDeltaX, 1

  OCall xsi.SetPixel, x0, y0, dColor

  mov eax, sdDeltaX
  .if eax > sdDeltaY
    shr eax, 1
    mov edx, sdDeltaY
    sub edx, eax
    mov sdFraction, edx

    mov eax, x0
    .while eax != x1
      .if sdFraction >= 0
        mov eax, sdStepY
        add y0, eax
        mov eax, sdDeltaX
        sub sdFraction, eax
      .endif
      mov eax, sdStepX
      add x0, eax
      mov eax, sdDeltaY
      add sdFraction, eax
      OCall xsi.SetPixel, x0, y0, dColor
      mov eax, x0
    .endw
  .else
    mov edx,sdDeltaY
    shr edx,1
    sub eax,edx
    mov sdFraction,eax

    mov eax,y0
    .while eax != y1
      .if sdFraction >= 0
        mov eax, sdStepX
        add x0, eax
        mov eax, sdDeltaY
        sub sdFraction, eax
      .endif
      mov eax, sdStepY
      add y0, eax
      mov eax, sdDeltaX
      add sdFraction, eax
      OCall xsi.SetPixel, x0, y0, dColor
      mov eax, y0
    .endw
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      PxmDrawString
; Purpose:    Generate code for both string types.
; Arguments:  Arg1: <A> or <W>
; Return:     Nothing.

PxmDrawString macro StrType:req
  SetObject xsi

  ;Create a temp DC
  mov hTempDC, $invoke(CreateCompatibleDC, [xsi].hDC)
  mov hPrevFont, $invoke(SelectObject, hTempDC, hFont)
  invoke SetGraphicsMode, hTempDC, GM_ADVANCED

  ;Obtain the dimensions of the printed text, in the context of the temp device
  m2z TextRect.left
  m2z TextRect.top
  m2z TextRect.right
  m2z TextRect.bottom
  mov ebx, dRenderFlags
  or ebx, DT_CALCRECT
  invoke DrawTextEx&StrType&, hTempDC, pText, -1, addr TextRect, ebx, NULL

  ;Reduce the rotation angle to the range [-PI..+PI]
  fld r4Rot
  fabs
  fFitTrigRange
  fldpi
  if (@Cpu and CPU_MODELS) lt CPU_586
    fcom st(1)
    fjge @F
  else
    fcomi st(0), st(1)
    jae @F
  endif
  fdivp st(1), st(0)
  fFrac
  fldpi
  fmul st(1), st(0)
  fsub st(1), st(0)
@@:
  fUnload
  .ifBitSet r4Rot, BIT31                              ;r4Rot > 0
    fchs                                              ;Restore original sign
  .endif
  fst r4Rot                                           ;Save reduced value

  ;Compute the size of the rotated bitmap
  fSinCos
  fild TextRect.right
  fmul st(0), st(1)
  fabs
  fild TextRect.bottom
  fmul st(0), st(3)
  fabs
  faddp st(1), st(0)
  fRndUp
  fistp BmpSize.x

  fild TextRect.bottom
  fmul st(0), st(1)
  fabs
  fild TextRect.right
  fmul st(0), st(3)
  fabs
  faddp st(1), st(0)
  fRndUp
  fistp BmpSize.y

  fld $CReal8(%HALF_PI)
  fld r4Rot
  fabs
  if 1;(@Cpu and CPU_MODELS) lt CPU_586
    fcompp
    fGetFlags
  else
    fcomip st(0), st(1)
    fUnload
  endif
  ;Compute and set the world transformation matrix for a r4Rot rotation
  fst XF.eM11
  fstp XF.eM22
  fst XF.eM12
  fchs
  fstp XF.eM21

  jae @@1                                               ;Take the flags from fcomip st(0), st(1)
    .ifBitClr r4Rot, BIT31                              ;r4Rot > 0
      fild TextRect.bottom
      fmul XF.eM12
      fstp XF.eDx_
      m2z XF.eDy
    .else
      fild TextRect.right
      fmul XF.eM21
      fstp XF.eDy
      m2z XF.eDx_
    .endif
    jmp @@2
  @@1:
    fld XF.eM11
    fchs
    .ifBitClr r4Rot, BIT31                              ;r4Rot > 0
      fimul TextRect.bottom
      fstp XF.eDy
      fild BmpSize.x
      fstp XF.eDx_
    .else
      fimul TextRect.right
      fstp XF.eDx_
      fild BmpSize.y
      fstp XF.eDy
    .endif
  @@2:
  invoke SetWorldTransform, hTempDC, addr XF

  mov BmpInfo.BITMAPINFO.bmiHeader.biSize, sizeof BITMAPINFOHEADER
  m2m BmpInfo.BITMAPINFO.bmiHeader.biWidth, BmpSize.x, ecx
  mov eax, BmpSize.y
  neg eax
  mov BmpInfo.BITMAPINFO.bmiHeader.biHeight, eax
  mov BmpInfo.BITMAPINFO.bmiHeader.biPlanes, 1
  mov BmpInfo.BITMAPINFO.bmiHeader.biBitCount, 32
  mov BmpInfo.BITMAPINFO.bmiHeader.biCompression, BI_RGB
  m2z BmpInfo.BITMAPINFO.bmiHeader.biSizeImage
  m2z BmpInfo.BITMAPINFO.bmiHeader.biXPelsPerMeter
  m2z BmpInfo.BITMAPINFO.bmiHeader.biYPelsPerMeter
  m2z BmpInfo.BITMAPINFO.bmiHeader.biClrUsed
  m2z BmpInfo.BITMAPINFO.bmiHeader.biClrImportant

  invoke CreateDIBSection, 0, addr BmpInfo, DIB_RGB_COLORS, addr pTempBits, 0, 0
  mov hTempDIBSect, xax
  mov hPrevDIBSect, $invoke(SelectObject, hTempDC, hTempDIBSect)

  ;Render the text to the hTempDC
  invoke SetBkMode, hTempDC, TRANSPARENT
  invoke SetTextColor, hTempDC, $RGB(255,0,0,0) ;00XX0000, use this color to facilitate some calcs

  ;Draw rotated text
  invoke DrawTextEx&StrType&, hTempDC, pText, -1, addr TextRect, dRenderFlags, NULL

  ;Release unneeded resources
  invoke SelectObject, hTempDC, hPrevDIBSect
  invoke SelectObject, hTempDC, hPrevFont
  invoke DeleteDC, hTempDC                              ;Delete hTempDC

  ;Precompute some values
  mov edx, dColor
  mov ecx, edx
  and edx, PXM_MASK_REG_RGB
  mov dRGBColor, edx
  shr ecx, 24
  inc ecx
  mov dAlphaColor, ecx

  ;Move pt according to the render flags
  .if dRenderFlags & DT_CENTER                          ;pt is at the horizontal center of the text
    mov eax, BmpSize.x
    shr eax, 1
    sub pt.x, eax
  .elseif dRenderFlags & DT_RIGHT                       ;pt is at the right of the text
    mov eax, BmpSize.x
    sub pt.x, eax
  .endif

  .if dRenderFlags & DT_VCENTER                         ;pt is at the vertical center of the text
    mov eax, BmpSize.y
    shr eax, 1
    sub pt.y, eax
  .elseif dRenderFlags & DT_BOTTOM                      ;pt is at the bottom of the text
    mov eax, BmpSize.y
    sub pt.y, eax
  .endif

  ;Perform the pixel blending for each pixel in the temp bitmap
  xor edi, edi                                          ;edi = Vertical counter
  .while edi < BmpSize.y
    xor ebx, ebx                                        ;ebx = Horizontal counter
    .while ebx < BmpSize.x
      mov xdx, pTempBits
      mov eax, [xdx]
      and eax, PXM_MASK_REG_RGB                         ;Ignore alpha value, evaluate RGB components only
      .if !ZERO?
        mul dAlphaColor
        and eax, PXM_MASK_REG_ALPHA
        or eax, dRGBColor
        mov dARGB, eax

        mov ecx, pt.x
        add ecx, ebx
        mov eax, pt.y
        add eax, edi

        .if SDWORD ptr eax >= 0 && SDWORD ptr eax < [xsi].dHeight
          .if SDWORD ptr ecx >= 0 && SDWORD ptr ecx < [xsi].dWidth
            mov dTempXBX, ebx
            mov dTempXDI, edi
            shl ecx, LOG2_RGBQUAD_SIZE
            add xcx, [xsi].pPixels
            mul [xsi].dWidth
            lea xdi, [RGBQUAD_SIZE*xax + xcx]
            mov edx, dARGB
            RGB2BGR edx
            mov dPixColor, edx                          ;Save pixel
            Pxm_Alpha_Densities edx
            ;Get background pixel and transform it into linear color space
            OCall xsi::Pixelmap.Gamma2Linear, DWORD ptr [xdi]
            Pxm_PixelBlend_RGB eax, ebx, dDens2
            mov ecx, dPixColor                          ;Get pixel to blend
            Pxm_PixelBlend_RGB ecx, edx, dDens1
            Pxm_PixelMerge_RGB eax, ebx, ecx, edx
            OCall xsi::Pixelmap.Linear2Gamma, eax
            mov ecx, DWORD ptr [xdi]                    ;Set source alfa value
            and ecx, PXM_MASK_REG_ALPHA
            or eax, ecx
            mov DWORD ptr [xdi], eax
            mov ebx, dTempXBX
            mov edi, dTempXDI
          .endif
        .endif
      .endif
      inc ebx
      add pTempBits, RGBQUAD_SIZE
    .endw
    inc edi
  .endw
  invoke DeleteObject, hTempDIBSect
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Pixelmap.DrawStrA
; Purpose:    Print antialiased an string on the Pixelmap.
; Arguments:  Arg1: -> ANSI string.
;             Arg2: Point where to start drawing.
;             Arg3: ARGB color value.
;             Arg4: Font handle. Escapement and Orientation MUST both be zero!
;                   CLEARTYPE_QUALITY can be enabled.
;             Arg5: DrawText API render flags.
;                   DT_TOP, DT_LEFT, DT_CENTER, DT_RIGHT, DT_VCENTER, DT_BOTTOM are used
;                   to render on the Pixelmap.
;             Arg6: Rotation angle (REAL4) in radian.
; Return:     Nothing.

Method Pixelmap.DrawStrA, uses xbx xdi xsi, pText:PSTRINGA, pt:POINT, dColor:DWORD, \
                                            hFont:HFONT, dRenderFlags:DWORD, \
                                            r4Rot:REAL4
  local TextRect:RECT, hTempDC:HDC
  local BmpInfo:BITMAPINFO, hTempDIBSect:HANDLE, pTempBits:POINTER
  local dAlphaColor:DWORD, dRGBColor:DWORD, dPixColor:DWORD
  local dARGB:DWORD, dDens1:DWORD, dDens2:DWORD
  local XF:XFORM, BmpSize:POINT
  local hPrevFont:HFONT, hPrevDIBSect:HBITMAP
  local dTempXBX:DWORD, dTempXDI:DWORD

  ANNOTATION use: xbx xdi xsi
  ANNOTATION use: BmpInfo BmpSize TextRect XF dARGB dAlphaColor dDens1 dDens2 dPixColor dRGBColor
  ANNOTATION use: dTempXBX dTempXDI hPrevDIBSect hPrevFont hTempDC hTempDIBSect pTempBits
  ANNOTATION use: dColor pText pt

  PxmDrawString <A>
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Pixelmap.DrawStrW
; Purpose:    Print antialiased an string on the Pixelmap.
; Arguments:  Arg1: -> WIDE string.
;             Arg2: Point where to start drawing.
;             Arg3: ARGB color value.
;             Arg4: Font handle. Escapement and Orientation MUST both be zero!
;                   CLEARTYPE_QUALITY can be enabled.
;             Arg5: DrawText API render flags.
;                   DT_TOP, DT_LEFT, DT_CENTER, DT_RIGHT, DT_VCENTER, DT_BOTTOM are used
;                   to render on the Pixelmap.
;             Arg6: Rotation angle (REAL4) in radian.
; Return:     Nothing.

Method Pixelmap.DrawStrW, uses xbx xdi xsi, pText:PSTRINGW, pt:POINT, dColor:DWORD, \
                                            hFont:HFONT, dRenderFlags:DWORD, \
                                            r4Rot:REAL4
  local TextRect:RECT, hTempDC:HDC
  local BmpInfo:BITMAPINFO, hTempDIBSect:HANDLE, pTempBits:POINTER
  local dAlphaColor:DWORD, dRGBColor:DWORD, dPixColor:DWORD
  local dARGB:DWORD, dDens1:DWORD, dDens2:DWORD
  local XF:XFORM, BmpSize:POINT
  local hPrevFont:HFONT, hPrevDIBSect:HBITMAP
  local dTempXBX:DWORD, dTempXDI:DWORD

  ANNOTATION use: xbx xdi xsi
  ANNOTATION use: BmpInfo BmpSize TextRect XF dARGB dAlphaColor dDens1 dDens2 dPixColor dRGBColor
  ANNOTATION use: dTempXBX dTempXDI hPrevDIBSect hPrevFont hTempDC hTempDIBSect pTempBits
  ANNOTATION use: dColor pText pt

  PxmDrawString <W>
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Pixelmap.FillBkGnd
; Purpose:    Fill the Pixelmap with a given color. No alfablending is applied!
; Arguments:  Arg1: ARGB background color.
; Return:     Nothing.

Method Pixelmap.FillBkGnd, uses xdi, dARGB:DWORD
  SetObject xdx
  .if [xdx].hDIBSection != 0
    mov ecx, [xdx].BmpInfo.BITMAPINFO.bmiHeader.biSizeImage
    mov xdi, [xdx].pPixels
    shr ecx, LOG2_RGBQUAD_SIZE                          ;BYTE count to RGBQUAD count
    mov eax, dARGB
    RGB2BGR eax
    rep stosd
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Pixelmap.FillRect
; Purpose:    Fill a rectangular area of the Pixelmap with an ARGB value.
; Arguments:  Arg1: -> RECT to fill.
;             Arg2: ARGB value.
; Return:     Nothing.

Method Pixelmap.FillRect, uses xbx xdi xsi, pDstRct:PRECT, dARGB:DWORD
  local xSkipY:XWORD, dWidth:DWORD, dHeight:DWORD
  local DstSpace:RECT, OutRct:RECT, DstRct:RECT
  local dDens1:DWORD, dDens2:DWORD

  SetObject xsi
  .if [xsi].hDIBSection != 0
    ;Flip SrcRct if necessary
    mov xcx, pDstRct
    CloneRect DstRct, RECT ptr [xcx], xax, xdx
    Pxm_FlipInvertedRect DstRct

    ;Clip SrcRct to SrcSpace
    m2z DstSpace.left
    m2z DstSpace.top
    m2m DstSpace.right, [xsi].dWidth, eax
    m2m DstSpace.bottom, [xsi].dHeight, eax
    Pxm_ClipRect OutRct, DstRct, DstSpace

    mov eax, OutRct.right
    mov ecx, OutRct.bottom
    sub eax, OutRct.left
    jz @@EOM
    sub ecx, OutRct.top
    jz @@EOM
    mov dWidth, eax
    mov dHeight, ecx

    mov xSkipY, $Pxm_Bytes2Skip(dWidth, xsi)
    mov xsi, $Pxm_PixelAddr(OutRct.left, OutRct.top, xsi)
    ReleaseObject

    mov ecx, dARGB
    RGB2BGR ecx
    mov eax, dARGB
    shr eax, 32 - 8

    .if al == 255
      mov ebx, dHeight
      test ebx, ebx
      .while !ZERO?
        mov edi, dWidth
        test edi, edi
        .while !ZERO?
          mov [xsi], ecx
          add xsi, RGBQUAD_SIZE
          dec edi
        .endw
        add xsi, xSkipY
        dec ebx
      .endw

    .elseif al != 0
      mov dDens1, eax
      neg ax
      add ax, 0FFh
      mov dDens2, eax                                   ;Dens2 = Complement to dDens1

      Pxm_Blend_ARGB ecx, edx, dDens1
      mov eax, dHeight
      test eax, eax
      .while !ZERO?
        mov edi, dWidth
        test edi, edi
        .while !ZERO?
          mov eax, [xsi]                                ;Get original pixel
          Pxm_Blend_ARGB eax, ebx, dDens2
          Pxm_BlendMerge_ARGB eax, ebx, ecx, edx
          mov [xsi], eax                                ;Store new color
          add xsi, RGBQUAD_SIZE
          dec edi
        .endw
        add xsi, xSkipY
        dec dHeight
      .endw
    .endif
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Pixelmap.FillRectChannel
; Purpose:    Fill a c color channel of rectangular area of the Pixelmap with a given value.
; Arguments:  Arg1: -> RECT to fill.
;             Arg2: Color channel (PXM_CHANNEL_XXX).
;             Arg2: Fill value (Byte).
; Return:     Nothing.

Method Pixelmap.FillRectChannel, uses xsi, pDstRct:PRECT, dChannel:DWORD, dFillValue:DWORD
  local xSkipY:XWORD, dWidth:DWORD, dHeight:DWORD
  local DstSpace:RECT, OutRct:RECT, DstRct:RECT

  SetObject xsi
  .if [xsi].hDIBSection != 0
    ;Flip SrcRct if necessary
    ?mov edx, pDstRct
    CloneRect DstRct, RECT ptr [xdx], xax, xcx

    Pxm_FlipInvertedRect DstRct

    ;Clip SrcRct to SrcSpace
    m2z DstSpace.left
    m2z DstSpace.top
    m2m DstSpace.right, [xsi].dWidth, eax
    m2m DstSpace.bottom, [xsi].dHeight, eax
    Pxm_ClipRect OutRct, DstRct, DstSpace

    mov eax, OutRct.right
    mov ecx, OutRct.bottom
    sub eax, OutRct.left
    jz @@EOM
    sub ecx, OutRct.top
    jz @@EOM
    mov dWidth, eax
    mov dHeight, ecx

    mov xSkipY, $Pxm_Bytes2Skip(dWidth, xsi)
    mov xsi, $Pxm_PixelAddr(OutRct.left, OutRct.top, xsi)
    mov ecx, dChannel
    mov xax, offset PXM_CHANNEL_OFFSET_TABLE
    movzx edx, BYTE ptr [xax + xcx]
    add xsi, xdx
    ReleaseObject

    mov eax, dFillValue
    mov ecx, dHeight
    test ecx, ecx
    .while !ZERO?
      mov edx, dWidth
      test edx, edx
      .while !ZERO?
        mov [xsi], al
        add xsi, RGBQUAD_SIZE
        dec edx
      .endw
      add xsi, xSkipY
      dec ecx
    .endw
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Pixelmap.FillRectGradHor
; Purpose:    Fill a rect with an horizontal gradient. Alphablending is applied if necessary.
; Arguments:  Arg1: -> RECT to fill.
;             Arg2: Left ARGB color.
;             Arg3: Right ARGB color.
; Return:     Nothing.

Method Pixelmap.FillRectGradHor, uses xbx xdi xsi, pDstRct:PRECT, dLftColor:DWORD, dRgtColor:DWORD
  local dRed:DWORD, dGreen:DWORD, dBlue:DWORD, dAlpha:DWORD, dBuffer:DWORD
  local xSkipX:XWORD, xSkipY:XWORD, dWidth:DWORD, dHeight:DWORD
  local DstSpace:RECT, OutRct:RECT, DstRct:RECT
  local dDens1:DWORD, dDens2:DWORD, dColor:DWORD

  SetObject xsi
  .if [xsi].hDIBSection != 0
    ;Flip SrcRct if necessary
    ?mov edx, pDstRct
    CloneRect DstRct, RECT ptr [xdx], xax, xcx
    Pxm_FlipInvertedRect DstRct

    ;Clip SrcRct to SrcSpace
    m2z DstSpace.left
    m2z DstSpace.top
    m2m DstSpace.right, [xsi].dWidth, eax
    m2m DstSpace.bottom, [xsi].dHeight, eax
    Pxm_ClipRect OutRct, DstRct, DstSpace

    mov eax, OutRct.right
    mov ecx, OutRct.bottom
    sub eax, OutRct.left
    jz @@EOM
    sub ecx, OutRct.top
    jz @@EOM
    mov dWidth, eax
    mov dHeight, ecx

    ;Calculate X/Y skip values
    mov eax, [xsi].dWidth
    shl xax, LOG2_RGBQUAD_SIZE
    mov xSkipY, xax
    mul xcx
    sub xax, RGBQUAD_SIZE
    mov xSkipX, xax

    ;Calculate first pixel position
    mov xsi, $Pxm_PixelAddr(OutRct.left, OutRct.top, xsi)
    ReleaseObject

    ;Calculate the color steps
    fild dWidth

    ;Red step
    mov edx, dRgtColor
    mov ecx, dLftColor
    movzx eax, dl
    mov dBuffer, eax
    fild dBuffer
    movzx eax, cl
    mov dBuffer, eax
    fild dBuffer
    fsubp st(1), st(0)
    fdiv st(0), st(1)
    fxch st(1)

    ;Green step
    movzx eax, dh
    mov dBuffer, eax
    fild dBuffer
    movzx eax, ch
    mov dBuffer, eax
    fild dBuffer
    fsubp st(1), st(0)
    fdiv st(0), st(1)
    fxch st(1)

    ;Blue step
    shr edx, 16
    movzx eax, dl
    mov dBuffer, eax
    fild dBuffer
    shr ecx, 16
    movzx eax, cl
    mov dBuffer, eax
    fild dBuffer
    fsubp st(1), st(0)
    fdiv st(0), st(1)
    fxch st(1)

    ;Check if we have trasparent colors
    .if dh != 255 || ch != 255
      ;Transparent colors
      ;Alpha step
      movzx eax, dh
      mov dBuffer, eax
      fild dBuffer
      movzx eax, ch
      mov dBuffer, eax
      fild dBuffer
      fsubp st(1), st(0)
      fdiv st(0), st(1)
      fxch st(1)

      fUnload 1

      ;Load LftColor components
      mov edx, dLftColor
      movzx eax, dl
      mov dBuffer, eax
      fild dBuffer
      movzx eax, dh
      mov dBuffer, eax
      fild dBuffer
      shr edx, 16
      movzx eax, dl
      mov dBuffer, eax
      fild dBuffer
      movzx eax, dh
      mov dBuffer, eax
      fild dBuffer

      mov eax, dLftColor

      RGB2BGR eax
      mov eax, dWidth
      test eax, eax
      .while !ZERO?
        mov edi, dHeight
        test edi, edi
        .while !ZERO?
          mov dColor, eax
          mov ecx, eax
          Pxm_Alpha_Densities ecx
          Pxm_Blend_ARGB eax, ebx, dDens1
          mov ecx, [xsi]                      ;Get source pixel
          Pxm_Blend_ARGB ecx, edx, dDens2
          Pxm_BlendMerge_ARGB eax, ebx, ecx, edx
          mov [xsi], eax                      ;Store new color
          mov eax, dColor
    
          add xsi, xSkipY
          dec edi
        .endw
  
        ;Compute new color
        fxch st(3)
        fadd st(0), st(7)
        fist dRed
        fxch st(3)
  
        fxch st(2)
        fadd st(0), st(6)
        fist dGreen
        fxch st(2)
  
        fxch st(1)
        fadd st(0), st(5)
        fist dBlue
        fxch st(1)
  
        fadd st(0), st(4)
        fist dAlpha
  
        ;Compose it
        mov ah, BYTE ptr dAlpha
        mov al, BYTE ptr dRed
        shl eax, 16
        mov ah, BYTE ptr dGreen
        mov al, BYTE ptr dBlue
  
        sub xsi, xSkipX
        dec dWidth
      .endw
      fUnload 8

    ; ————————————————————————————————————————————————————

    .else
      ;Solid colors
      fUnload 1

      ;Load LftColor components
      mov edx, dLftColor
      movzx eax, dl
      mov dBuffer, eax
      fild dBuffer
      movzx eax, dh
      mov dBuffer, eax
      fild dBuffer
      shr edx, 16
      movzx eax, dl
      mov dBuffer, eax
      fild dBuffer

      mov ebx, dWidth
      mov eax, dLftColor
      RGB2BGR eax
      test ebx, ebx
      .while !ZERO?
        mov edi, dHeight
        test edi, edi
        .while !ZERO?
          mov [xsi], eax
          add xsi, xSkipY
          dec edi
        .endw
  
        ;Compute new color
        fxch st(2)
        fadd st(0), st(5)
        fist dRed
        fxch st(2)
  
        fxch st(1)
        fadd st(0), st(4)
        fist dGreen
        fxch st(1)
  
        fadd st(0), st(3)
        fist dBlue
  
        ;Compose it
        mov ah, 255
        mov al, BYTE ptr dRed
        shl eax, 16
        mov ah, BYTE ptr dGreen
        mov al, BYTE ptr dBlue
  
        sub xsi, xSkipX
  
        dec ebx
      .endw
      fUnload 6

    .endif
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Pixelmap.FillRectGradVer
; Purpose:    Fill a rect with a vertical gradient. Alphablending is applied if necessary.
; Arguments:  Arg1: -> RECT to fill.
;             Arg2: Left ARGB color.
;             Arg3: Right ARGB color.
; Return:     Nothing.

Method Pixelmap.FillRectGradVer, uses xbx xdi xsi, pDstRct:PRECT, dTopColor:DWORD, dBtmColor:DWORD
  local dRed:DWORD, dGreen:DWORD, dBlue:DWORD, dAlpha:DWORD, dBuffer:DWORD, dColor:RGBQUAD
  local xSkipY:XWORD, dWidth:DWORD, dHeight:DWORD
  local DstSpace:RECT, OutRct:RECT, DstRct:RECT
  local dDens1:DWORD, dDens2:DWORD

  SetObject xsi
  .if [xsi].hDIBSection != 0
    ;Flip SrcRct if necessary
    ?mov edx, pDstRct
    CloneRect DstRct, RECT ptr [xdx], xax, xcx
    Pxm_FlipInvertedRect DstRct

    ;Clip SrcRct to SrcSpace
    m2z DstSpace.left
    m2z DstSpace.top
    m2m DstSpace.right, [xsi].dWidth, eax
    m2m DstSpace.bottom, [xsi].dHeight, eax
    Pxm_ClipRect OutRct, DstRct, DstSpace

    mov eax, OutRct.right
    mov ecx, OutRct.bottom
    sub eax, OutRct.left
    jz @@EOM
    sub ecx, OutRct.top
    jz @@EOM
    mov dWidth, eax
    mov dHeight, ecx

    ;Calculate X/Y skip values
    mov xSkipY, $Pxm_Bytes2Skip(dWidth, xsi)

    ;Calculate first pixel position
    mov xsi, $Pxm_PixelAddr(OutRct.left, OutRct.top, xsi)
    ReleaseObject

    ;Calculate the color steps
    fild dHeight

    ;Red step
    mov edx, dBtmColor
    mov ecx, dTopColor
    movzx eax, dl
    mov dBuffer, eax
    fild dBuffer
    movzx eax, cl
    mov dBuffer, eax
    fild dBuffer
    fsubp st(1), st(0)
    fdiv st(0), st(1)
    fxch st(1)

    ;Green step
    movzx eax, dh
    mov dBuffer, eax
    fild dBuffer
    movzx eax, ch
    mov dBuffer, eax
    fild dBuffer
    fsubp st(1), st(0)
    fdiv st(0), st(1)
    fxch st(1)

    ;Blue step
    shr edx, 16
    movzx eax, dl
    mov dBuffer, eax
    fild dBuffer
    shr ecx, 16
    movzx eax, cl
    mov dBuffer, eax
    fild dBuffer
    fsubp st(1), st(0)
    fdiv st(0), st(1)
    fxch st(1)

    ;Check if we have transparent colors
    .if dh != 255 || ch != 255
      ;Transparent colors
      ;Alpha step
      movzx eax, dh
      mov dBuffer, eax
      fild dBuffer
      movzx eax, ch
      mov dBuffer, eax
      fild dBuffer
      fsubp st(1), st(0)
      fdiv st(0), st(1)
      fxch st(1)

      fUnload 1

      ;Load LftColor components
      mov edx, dTopColor
      movzx eax, dl
      mov dBuffer, eax
      fild dBuffer
      movzx eax, dh
      mov dBuffer, eax
      fild dBuffer
      shr edx, 16
      movzx eax, dl
      mov dBuffer, eax
      fild dBuffer
      movzx eax, dh
      mov dBuffer, eax
      fild dBuffer

      mov eax, dTopColor
      RGB2BGR eax
      mov eax, dHeight
      test eax, eax
      .while !ZERO?
        mov edi, dWidth
        test edi, edi
        .while !ZERO?
          mov dColor, eax
          mov ecx, eax
          Pxm_Alpha_Densities ecx
          Pxm_Blend_ARGB eax, ebx, dDens1
          mov ecx, [xsi]                      ;Get source pixel
          Pxm_Blend_ARGB ecx, edx, dDens2
          Pxm_BlendMerge_ARGB eax, ebx, ecx, edx
          mov [xsi], eax                      ;Store new color
          mov eax, dColor                     ;Restore current color
          add xsi, RGBQUAD_SIZE
          dec edi
        .endw

        ;Compute new color
        fxch st(3)
        fadd st(0), st(7)
        fist dRed
        fxch st(3)

        fxch st(2)
        fadd st(0), st(6)
        fist dGreen
        fxch st(2)

        fxch st(1)
        fadd st(0), st(5)
        fist dBlue
        fxch st(1)

        fadd st(0), st(4)
        fist dAlpha

        ;Compose it
        mov ah, BYTE ptr dAlpha
        mov al, BYTE ptr dRed
        shl eax, 16
        mov ah, BYTE ptr dGreen
        mov al, BYTE ptr dBlue

        add xsi, xSkipY
        dec dHeight
      .endw

      fUnload 8

    ; ————————————————————————————————————————————————————

    .else
      ;Solid colors
      fUnload 1

      ;Load LftColor components
      mov edx, dTopColor
      movzx eax, dl
      mov dBuffer, eax
      fild dBuffer
      movzx eax, dh
      mov dBuffer, eax
      fild dBuffer
      shr edx, 16
      movzx eax, dl
      mov dBuffer, eax
      fild dBuffer

      mov ebx, dHeight
      mov eax, dTopColor
      RGB2BGR eax
      test ebx, ebx
      .while !ZERO?
        mov edi, dWidth
        test edi, edi
        .while !ZERO?
          mov [xsi], eax
          add xsi, RGBQUAD_SIZE
          dec edi
        .endw

        ;Compute new color
        fxch st(2)
        fadd st(0), st(5)
        fist dRed
        fxch st(2)

        fxch st(1)
        fadd st(0), st(4)
        fist dGreen
        fxch st(1)

        fadd st(0), st(3)
        fist dBlue

        ;Compose it
        mov ah, 255
        mov al, BYTE ptr dRed
        shl eax, 16
        mov ah, BYTE ptr dGreen
        mov al, BYTE ptr dBlue

        add xsi, xSkipY
        dec ebx
      .endw

      fUnload 6

    .endif
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Pixelmap.FlipRectHor
; Purpose:    Flip horizontally a rectangular area of the Pixelmap.
; Arguments:  Arg1: -> RECT to flip.
; Return:     Nothing.

Method Pixelmap.FlipRectHor, uses xbx xdi xsi, pDstRct:PRECT
  local xSkipY:XWORD, dWidth:DWORD, dHeight:DWORD
  local DstSpace:RECT, OutRct:RECT, DstRct:RECT

  SetObject xsi
  .if [xsi].hDIBSection != 0
    ;Flip DstRct if necessary
    ?mov edx, pDstRct
    CloneRect DstRct, RECT ptr [xdx], xax, xcx
    Pxm_FlipInvertedRect DstRct

    ;Clip DstRct to SrcSpace
    m2z DstSpace.left
    m2z DstSpace.top
    m2m DstSpace.right, [xsi].dWidth, eax
    m2m DstSpace.bottom, [xsi].dHeight, eax
    Pxm_ClipRect OutRct, DstRct, DstSpace

    ;Calc width and height
    mov ecx, OutRct.right
    mov eax, OutRct.bottom
    sub ecx, OutRct.left
    jz @@EOM
    sub eax, OutRct.top
    jz @@EOM
    mov dWidth, ecx
    mov dHeight, eax

    ;Calculate skip value
    shr ecx, 1
    mov eax, [xsi].dWidth
    sub eax, ecx
    shl xax, LOG2_RGBQUAD_SIZE
    mov xSkipY, xax

    ;Calculate pointer to first pixel in OutRct
    mov xsi, $Pxm_PixelAddr(OutRct.left, OutRct.top, xsi)
    ReleaseObject

    ;Flip now
    mov ebx, dHeight
    test ebx, ebx
    .while !ZERO?
      mov edi, dWidth
      lea edx, [xsi + RGBQUAD_SIZE*xdi]
      shr xdi, 1
      .while !ZERO?
        mov eax, [xsi]
        mov ecx, [xdx]
        mov [xsi], ecx
        mov [xdx], eax
        add xsi, RGBQUAD_SIZE
        sub edx, RGBQUAD_SIZE
        dec edi
      .endw
      add xsi, xSkipY
      dec ebx
    .endw
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Pixelmap.FlipRectVer
; Purpose:    Flip vertically a rectangular area of the Pixelmap.
; Arguments:  Arg1: -> RECT to flip.
; Return:     Nothing.

Method Pixelmap.FlipRectVer, uses xbx xdi xsi, pDstRct:PRECT
  local xSkipYPos:XWORD, xSkipYNeg:XWORD, dWidth:DWORD, dHeight:DWORD
  local DstSpace:RECT, OutRct:RECT, DstRct:RECT

  SetObject xsi
  .if [xsi].hDIBSection != 0
    ;Flip DstRct if necessary
    ?mov edx, pDstRct
    CloneRect DstRct, RECT ptr [xdx], xax, xcx
    Pxm_FlipInvertedRect DstRct

    ;Clip DstRct to SrcSpace
    m2z DstSpace.left
    m2z DstSpace.top
    m2m DstSpace.right, [xsi].dWidth, eax
    m2m DstSpace.bottom, [xsi].dHeight, eax
    Pxm_ClipRect OutRct, DstRct, DstSpace

    ;Calc width and height
    mov eax, OutRct.right
    mov ecx, OutRct.bottom
    sub eax, OutRct.left
    jz @@EOM
    sub ecx, OutRct.top
    jz @@EOM
    mov dWidth, eax
    mov dHeight, ecx

    ;Calculate skip values
    mov ecx, [xsi].dWidth
    sub xcx, xax
    shl xcx, LOG2_RGBQUAD_SIZE
    mov xSkipYPos, xcx
    add eax, [xsi].dWidth
    shl xax, LOG2_RGBQUAD_SIZE
    mov xSkipYNeg, xax

    ;Calculate pointer to first pixel in OutRct
    mov xsi, $Pxm_PixelAddr(OutRct.left, OutRct.top, xsi)
    ReleaseObject

    ;Initialize flip routine
    mov ebx, dHeight
    mov eax, dWidth
    mul ebx
    shl eax, LOG2_RGBQUAD_SIZE
    mov xdx, xsi
    add xdx, xax
    shr ebx, 1

    ;Flip now
    .while !ZERO?                                       ;Use flags from prev. instruction
      mov edi, dWidth
      test edi, edi
      .while !ZERO?
        mov eax, [xsi]
        mov ecx, [xdx]
        mov [xsi], ecx
        mov [xdx], eax
        add xsi, RGBQUAD_SIZE
        add xdx, RGBQUAD_SIZE
        dec edi
      .endw
      add xsi, xSkipYPos
      sub xdx, xSkipYNeg
      dec ebx
    .endw

  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:    Pixelmap.Gray
; Purpose:   Transform the Pixelmap into a gray scale image.
; Arguments: Arg1: -> RECT to transform.
; Return:    Nothing.

Method Pixelmap.Gray, uses xbx xdi xsi, pDstRct:PRECT
  local xSkipY:XWORD, dWidth:DWORD, dHeight:DWORD
  local DstSpace:RECT, OutRct:RECT, DstRct:RECT

  SetObject xsi
  .if [xsi].hDIBSection != 0
    ;Flip SrcRct if necessary
    ?mov edx, pDstRct
    CloneRect DstRct, RECT ptr [xdx], xax, xcx
    Pxm_FlipInvertedRect DstRct

    ;Clip SrcRct to SrcSpace
    m2z DstSpace.left
    m2z DstSpace.top
    m2m DstSpace.right, [xsi].dWidth, eax
    m2m DstSpace.bottom, [xsi].dHeight, eax
    Pxm_ClipRect OutRct, DstRct, DstSpace

    mov eax, OutRct.right
    mov ecx, OutRct.bottom
    sub eax, OutRct.left
    jz @@EOM
    sub ecx, OutRct.top
    jz @@EOM
    mov dWidth, eax
    mov dHeight, ecx

    ;Calculate X/Y skip values
    mov xSkipY, $Pxm_Bytes2Skip(dWidth, xsi)

    ;Calculate first pixel position
    mov xsi, $Pxm_PixelAddr(OutRct.left, OutRct.top, xsi)
    ReleaseObject

    mov ebx, dHeight
    test ebx, ebx
    .while !ZERO?
      mov edi, dWidth
      test edi, edi
      .while !ZERO?
        mov eax, [xsi]
        movzx ecx, al                                   ;Blue
        imul ecx, ecx, 25
        movzx edx, ah                                   ;Green
        imul edx, edx, 129
        add edx, ecx
        shr eax, 16                                     ;Red
        imul eax, eax, 66
        add eax, edx
        add eax, 128
        shr eax, 8
        add eax, 16
        and eax, 0FFh
        imul eax, eax, 010101h
        mov [xsi], eax
        add xsi, RGBQUAD_SIZE
        dec edi
      .endw
      add xsi, xSkipY
      dec ebx
    .endw
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Pixelmap.Litho
; Purpose:    Transform the Pixelmap into a lithographic image.
; Arguments:  Arg1: -> Destination RECT.
;             Arg2: Threshhold value.
; Return:     Nothing.
; Notes:      - Original code by Edgar Hansen - Donkey -

Method Pixelmap.Litho, uses xbx xdi xsi, pDstRct:PRECT, dThreshhold:DWORD
  local DstSpace:RECT, OutRct:RECT, DstRct:RECT
  local xSkipY:XWORD, dWidth:DWORD, dHeight:DWORD
  local dWhite:DWORD, dBlack:DWORD

  SetObject xsi
  .if [xsi].hDIBSection != 0
    ;Flip SrcRct if necessary
    ?mov edx, pDstRct
    CloneRect DstRct, RECT ptr [xdx], xax, xcx
    Pxm_FlipInvertedRect DstRct

    ;Clip SrcRct to SrcSpace
    m2z DstSpace.left
    m2z DstSpace.top
    m2m DstSpace.right, [xsi].dWidth, eax
    m2m DstSpace.bottom, [xsi].dHeight, eax
    Pxm_ClipRect OutRct, DstRct, DstSpace

    mov eax, OutRct.right
    mov ecx, OutRct.bottom
    sub eax, OutRct.left
    jz @@EOM
    sub ecx, OutRct.top
    jz @@EOM
    mov dWidth, eax
    mov dHeight, ecx

    ;Calculate X/Y skip values
    mov xSkipY, $Pxm_Bytes2Skip(dWidth, xsi)

    ;Calculate first pixel position
    mov xsi, $Pxm_PixelAddr(OutRct.left, OutRct.top, xsi)
    ReleaseObject

    ;Initialize start values
    m2z dBlack
    mov dWhite, 00FFFFFFh
    mov eax, dThreshhold
    test eax, eax
    .if SIGN?
      mov dBlack, 00FFFFFFh
      m2z dWhite
      neg eax
      mov dThreshhold, eax
    .endif

    mov ebx, dHeight
    test ebx, ebx
    .while !ZERO?
      mov edi, dWidth
      test edi, edi
      .while !ZERO?
        mov eax, [xsi]
        movzx ecx, al                                   ;Blue
        imul ecx, ecx, 25
        movzx edx, ah                                   ;Green
        imul edx, edx, 129
        add edx, ecx
        shr eax, 16                                     ;Red
        imul eax, eax, 66
        add eax, edx
        add eax, 128
        shr eax, 8
        add eax, 16
        and eax, 0FFh

        .if eax <= dThreshhold
          mov eax, dBlack
        .else
          mov eax, dWhite
        .endif
        mov [xsi], eax

        mov [xsi], eax
        add xsi, RGBQUAD_SIZE
        dec edi
      .endw
      add xsi, xSkipY
      dec ebx
    .endw
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Pixelmap.Replace_ARGB_ARGB
; Purpose:    Replace an ARGB color with another.
; Arguments:  Arg1: -> Destination RECT.
;             Arg2: Final ARGB value.
;             Arg3: ARGB value to replace.
; Return:     Nothing.

Method Pixelmap.Replace_ARGB_ARGB, uses xbx xdi xsi, pDstRct:PRECT, dDstARGB:DWORD, dSrcARGB:DWORD
  local xSkipY:XWORD, dWidth:DWORD, dHeight:DWORD
  local DstSpace:RECT, OutRct:RECT, DstRct:RECT

  SetObject xsi
  .if [xsi].hDIBSection != 0

    ;Flip SrcRct if necessary
    ?mov edx, pDstRct
    CloneRect DstRct, RECT ptr [xdx], xax, xcx
    Pxm_FlipInvertedRect DstRct

    ;Clip SrcRct to SrcSpace
    m2z DstSpace.left
    m2z DstSpace.top
    m2m DstSpace.right, [xsi].dWidth, eax
    m2m DstSpace.bottom, [xsi].dHeight, eax
    Pxm_ClipRect OutRct, DstRct, DstSpace

    mov eax, OutRct.right
    mov ecx, OutRct.bottom
    sub eax, OutRct.left
    jz @@EOM
    sub ecx, OutRct.top
    jz @@EOM
    mov dWidth, eax
    mov dHeight, ecx

    mov xSkipY, $Pxm_Bytes2Skip(dWidth, xsi)
    mov xsi, $Pxm_PixelAddr(OutRct.left, OutRct.top, xsi)
    ReleaseObject

    mov eax, dSrcARGB
    RGB2BGR eax
    mov ecx, dDstARGB
    RGB2BGR ecx

    mov ebx, dHeight
    test ebx, ebx
    .while !ZERO?
      mov edi, dWidth
      test edi, edi
      .while !ZERO?
        mov edx, [xsi]
        sub edx, eax
        .if ZERO?
          mov [xsi], ecx
        .endif
        add xsi, RGBQUAD_SIZE
        dec edi
      .endw
      add xsi, xSkipY
      dec ebx
    .endw
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Pixelmap.Replace_RGB_ARGB
; Purpose:    Replace a pixel that matchs the RGB colors with an ARGB color.
; Arguments:  Arg1: -> RECT where to applay the change.
;             Arg2: Final ARGB value.
;             Arg3: RGB value to change.
; Return:     Nothing.

Method Pixelmap.Replace_RGB_ARGB, uses xbx xdi xsi, pDstRct:PRECT, dDstARGB:DWORD, dSrcRGB:DWORD
  local xSkipY:XWORD, dWidth:DWORD, dHeight:DWORD
  local DstSpace:RECT, OutRct:RECT, DstRct:RECT

  SetObject xsi
  .if [xsi].hDIBSection != 0

    ;Flip SrcRct if necessary
    ?mov edx, pDstRct
    CloneRect DstRct, RECT ptr [xdx], xax, xcx
    Pxm_FlipInvertedRect DstRct

    ;Clip SrcRct to SrcSpace
    m2z DstSpace.left
    m2z DstSpace.top
    m2m DstSpace.right, [xsi].dWidth, eax
    m2m DstSpace.bottom, [xsi].dHeight, eax
    Pxm_ClipRect OutRct, DstRct, DstSpace

    mov eax, OutRct.right
    mov ecx, OutRct.bottom
    sub eax, OutRct.left
    jz @@EOM
    sub ecx, OutRct.top
    jz @@EOM
    mov dWidth, eax
    mov dHeight, ecx

    mov xSkipY, $Pxm_Bytes2Skip(dWidth, xsi)
    mov xsi, $Pxm_PixelAddr(OutRct.left, OutRct.top, xsi)
    ReleaseObject

    mov eax, dSrcRGB
    RGB2BGR eax
    and eax, PXM_MASK_REG_RGB
    mov ecx, dDstARGB
    RGB2BGR ecx

    mov ebx, dHeight
    test ebx, ebx
    .while !ZERO?
      mov edi, dWidth
      test edi, edi
      .while !ZERO?
        mov edx, [xsi]
        and edx, PXM_MASK_REG_RGB
        sub edx, eax
        .if ZERO?
          mov [xsi], ecx
        .endif
        add xsi, RGBQUAD_SIZE
        dec edi
      .endw
      add xsi, xSkipY
      dec ebx
    .endw
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Pixelmap.Replace_RGB_RGB
; Purpose:    Replace all pixels with a given RGB value.
; Arguments:  Arg1: -> Destination RECT.
;             Arg2: Final RGB value.
;             Arg3: RGB value to replace.
; Return:     Nothing.

Method Pixelmap.Replace_RGB_RGB, uses xbx xdi xsi, pDstRct:PRECT, dDstRGB:DWORD, dSrcRGB:DWORD
  local xSkipY:XWORD, dWidth:DWORD, dHeight:DWORD
  local DstSpace:RECT, OutRct:RECT, DstRct:RECT

  SetObject xsi
  .if [xsi].hDIBSection != 0

    ;Flip SrcRct if necessary
    ?mov edx, pDstRct
    CloneRect DstRct, RECT ptr [xdx], xax, xcx
    Pxm_FlipInvertedRect DstRct

    ;Clip SrcRct to SrcSpace
    m2z DstSpace.left
    m2z DstSpace.top
    m2m DstSpace.right, [xsi].dWidth, eax
    m2m DstSpace.bottom, [xsi].dHeight, eax
    Pxm_ClipRect OutRct, DstRct, DstSpace

    mov eax, OutRct.right
    mov ecx, OutRct.bottom
    sub eax, OutRct.left
    jz @@EOM
    sub ecx, OutRct.top
    jz @@EOM
    mov dWidth, eax
    mov dHeight, ecx

    mov xSkipY, $Pxm_Bytes2Skip(dWidth, xsi)
    mov xsi, $Pxm_PixelAddr(OutRct.left, DstRct.top, xsi)
    ReleaseObject

    mov eax, dSrcRGB
    RGB2BGR eax
    and eax, PXM_MASK_REG_RGB
    mov ecx, dDstRGB
    RGB2BGR ecx
    and ecx, PXM_MASK_REG_RGB

    mov ebx, dHeight
    test ebx, ebx
    .while !ZERO?
      mov edi, dWidth
      test edi, edi
      .while !ZERO?
        mov edx, [xsi]
        and edx, PXM_MASK_REG_RGB
        sub edx, eax
        .if ZERO?
          mov edx, [xsi]
          and edx, PXM_MASK_REG_ALPHA                   ;Preserve alfa value
          or edx, ecx
          mov [xsi], edx
        .endif
        add xsi, RGBQUAD_SIZE
        dec edi
      .endw
      add xsi, xSkipY
      dec ebx
    .endw
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Pixelmap.Reset
; Purpose:    Free associated resources.
; Arguments:  None.
; Return:     Nothing.

Method Pixelmap.Reset, uses xsi
  SetObject xsi
  .if [xsi].hDC != 0
    invoke SelectObject, [xsi].hDC, [xsi].hPrvBmp
    invoke DeleteDC, [xsi].hDC
  .endif
  .if [xsi].hDIBSection != 0
    invoke DeleteObject, [xsi].hDIBSection
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Pixelmap.SetAlphaMask
; Purpose:    Copy a channel of a given Pixelmap to the alfa channel.
; Arguments:  Arg1: -> Source Pixelmap.
;             Arg2: -> Source RECT.
;             Arg3: Destination starting POINT.
;             Arg4: Channel to use (PXM_CHANNEL_XXX).
; Return:     Nothing.

Method Pixelmap.SetAlphaMask, uses xbx xdi xsi, pSrcPxm:POINTER, pSrcRct:PRECT, DstPnt:POINT, dChannel:DWORD
  local xDstSkipY:XWORD, xSrcSkipY:XWORD, dSrcMask:DWORD
  local dWidth:DWORD, dHeight:DWORD
  local SrcSpace:RECT, DstSpace:RECT, OutRct:RECT, SrcRct:RECT

  SetObject xdi
  SetObject xsi,,pSrcPxm

  .if [xsi].hDIBSection != 0 && [xdi].hDIBSection != 0
    ;Flip SrcRct if necessary
    mov xcx, pSrcRct
    CloneRect SrcRct, RECT ptr [xcx], xax, xdx
    Pxm_FlipInvertedRect SrcRct

    ;Clip SrcRct to SrcSpace
    m2z SrcSpace.left
    m2z SrcSpace.top
    m2m SrcSpace.right, [xsi].dWidth, eax
    m2m SrcSpace.bottom, [xsi].dHeight, eax
    Pxm_ClipRect OutRct, SrcRct, SrcSpace

    ;Clip to DstSpace
    mov eax, SrcRct.left
    sub eax, DstPnt.x
    mov DstSpace.left, eax
    add eax, [xdi].dWidth
    mov DstSpace.right, eax
    mov eax, SrcRct.top
    sub eax, DstPnt.y
    mov DstSpace.top, eax
    add eax, [xdi].dHeight
    mov DstSpace.bottom, eax
    Pxm_ClipRect OutRct, OutRct, DstSpace

    ;Calc transfer sizes
    sub eax, ecx
    jz @@EOM
    mov dHeight, eax
    mov eax, OutRct.right
    sub eax, OutRct.left
    jz @@EOM
    mov dWidth, eax

    ;Calc skip values
    mov xDstSkipY, $Pxm_Bytes2Skip(dWidth, xdi)
    mov xSrcSkipY, $Pxm_Bytes2Skip(dWidth, xsi)

    ;Calc position of first pixel to transfer in source space
    mov xsi, $Pxm_PixelAddr(OutRct.left, OutRct.top, xsi)
    ReleaseObject

    ;Calc position of first pixel to transfer in destination space
    mov eax, OutRct.top
    sub eax, SrcRct.top
    add eax, DstPnt.y
    mul [xdi].dWidth
    add eax, OutRct.left
    sub eax, SrcRct.left
    add eax, DstPnt.x
    shl xax, LOG2_RGBQUAD_SIZE
    add xax, [xdi].pPixels
    mov xdi, xax
    ReleaseObject

    ;Prepare source channel mask anf shift value
    mov edx, dChannel
    mov xcx, offset PXM_CHANNEL_REG_MASK_TABLE
    movzx eax, BYTE ptr [xcx + xdx]
    mov dSrcMask, eax
    mov xax, offset PXM_CHANNEL_OFFSET_TABLE
    movzx ecx, BYTE ptr [xax + xdx]
    mov ecx, 24
    shl edx, 3
    sub ecx, edx

;      mov eax, 0FFh
;      mov ecx, dChannel
;      and ecx, 011b
;      shl ecx, 3
;      shl eax, cl
;      mov dSrcMask, eax
;      neg ecx
;      add ecx, 24

    ;Do transfer of alfa channel
    align ALIGN_CODE
    mov eax, dHeight
    test eax, eax
    .while !ZERO?
      mov ebx, dWidth
      test ebx, ebx
      .while !ZERO?
        mov eax, [xsi]
        mov edx, [xdi]
        and eax, dSrcMask
        and edx, PXM_MASK_REG_RGB
        shl eax, cl
        or eax, edx
        mov [xdi], eax
        add xsi, RGBQUAD_SIZE
        add edi, RGBQUAD_SIZE
        dec ebx
      .endw
      add xsi, xSrcSkipY
      add xdi, xDstSkipY
      dec dHeight
    .endw
  .endif
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Pixelmap.UV2XY
; Purpose:    Convert pixel coordinate from floating UV to floating XY.
; Arguments:  Arg1: -> output REAL4 coordinates, i.e. VEC2 (2 x REAL4).
;             Arg2: -> input REAL4 coordinates, i.e. VEC2 (2 x REAL4).
;             Arg3: (optional) addressing mode:
;                    - PXM_ADDR_LIN: (default) linear conversion, no limit is applied.
;                    - PXM_ADDR_WRAP: tiles if range [0..1] is exceeded.
;                    - PXM_ADDR_MIRROR: mirrors if range [0..1] is exceeded.
;                    - PXM_ADDR_CLAMP: returns 1 or 0 if range [0..1] is exceeded.
; Return:     eax = Error code.

Method Pixelmap.UV2XY, uses xsi, pOutCoords:POINTER, pInCoords:POINTER, dMode:DWORD
  local wCurFpuCtrl:WORD, wPrvFpuCtrl:WORD, dBuffer:DWORD

.const
  @@UV2XY_JumpTable label POINTER
  POINTER offset @@ADDR_LIN
  POINTER offset @@ADDR_WRAP
  POINTER offset @@ADDR_MIRROR
  POINTER offset @@ADDR_CLAMP

.code
  SetObject xsi
  mov xax, pInCoords
  test xax, pInCoords
  jz @@Err
  mov xax, pOutCoords
  test xax, pOutCoords
  jnz @F
@@Err:
  OCall xsi.ErrorReport, NULL, PXM_INVALID_POINTER
  jmp @@EOM
@@:
  mov ecx, dMode
  .if ecx < 4
    mov xax, offset @@UV2XY_JumpTable
    jmp POINTER ptr [xax + sizeof(POINTER)*xcx]
  .endif
  OCall xsi.ErrorReport, NULL, PXM_INVALID_ADDR_MODE
  jmp @@EOM

@@ADDR_LIN:
  fld REAL4 ptr [xax]
  fld REAL4 ptr [xax + REAL4_SIZE]
  jmp @@Final

@@ADDR_WRAP:
  fstcw wPrvFpuCtrl                                     ;Store FPU control word
  m2m wCurFpuCtrl, wPrvFpuCtrl, cx                      ;Duplicate value

  BitSet wCurFpuCtrl, BIT10                             ;Modify the control word to
  BitClr wCurFpuCtrl, BIT11                             ;  round to -inf
  fldcw wCurFpuCtrl                                     ;Restore modified FPU control word

  fld REAL4 ptr [xax]
  fld st(0)
  frndint                                               ;Round down
  fsubp st(1), st(0)                                    ;Frac(x) = x - int(x)

  fld REAL4 ptr [xax + REAL4_SIZE]
  fld st(0)
  frndint                                               ;Round down
  fsubp st(1), st(0)                                    ;Frac(x) = x - int(x)

  fldcw wPrvFpuCtrl                                     ;Restore previous FPU control word

  jmp @@Final

@@ADDR_MIRROR:
  fstcw wPrvFpuCtrl                                     ;Store FPU control word
  m2m wCurFpuCtrl, wPrvFpuCtrl, cx                      ;Duplicate value
  BitSet wCurFpuCtrl, BIT10                             ;Modify the control word to
  BitClr wCurFpuCtrl, BIT11                             ;  round to -inf
  fldcw wCurFpuCtrl                                     ;Restore modified FPU control word

  fld REAL4 ptr [xax + REAL4_SIZE]                      ;y = abs(x-z) and z = int((x+1)/2)*2
  fld st(0)
  fld1
  faddp st(1), st(0)
  fmul $CReal4(+0.5)
  frndint                                               ;Round down
  fmul $CReal4(+2.0)
  fsubp st(1), st(0)
  fabs

  fld REAL4 ptr [xax]
  fld st(0)
  fld1
  faddp st(1), st(0)
  fmul $CReal4(+0.5)
  frndint                                               ;Round down
  fmul $CReal4(+2.0)
  fsubp st(1), st(0)
  fabs

  fldcw wPrvFpuCtrl                                     ;Restore previous FPU control word

  jmp @@Final

@@ADDR_CLAMP:
  fcmp REAL4 ptr [xax], 3F800000h                       ;1.0
  jg @@XClampTo1
  fcmp REAL4 ptr [xax], 00000000h                       ;0.0
  jl @@XClampTo0
  fld REAL4 ptr [xax]
  jmp @F
@@XClampTo1:
  fld1
  jmp @F
@@XClampTo0:
  fldz

@@:
  fcmp REAL4 ptr [xax + REAL4_SIZE], 3F800000h          ;1.0
  jg @@YClampTo1
  fcmp REAL4 ptr [xax + REAL4_SIZE], 00000000h          ;0.0
  jl @@YClampTo0
  fld REAL4 ptr [xax + REAL4_SIZE]
  jmp @F
@@YClampTo1:
  fld1
  jmp @F
@@YClampTo0:
  fldz
@@:

@@Final:
  mov xdx, pOutCoords                                   ;Compute XY coordinates
  mov eax, [xsi].dHeight
  mov ecx, [xsi].dWidth
  dec eax
  dec ecx
  mov dBuffer, eax
  fimul dBuffer                                         ;Multiply by Height - 1
  mov dBuffer, ecx
  fstp REAL4 ptr [xdx + REAL4_SIZE]
  fimul dBuffer                                         ;Multiply by Width - 1
  xor eax, eax                                          ;Return OBJ_OK
  fstp REAL4 ptr [xdx]

MethodEnd


; ==================================================================================================
; Private methods
; ==================================================================================================

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Pixelmap.Gamma2Linear
; Purpose:    Convert from gamma to linear color space. Alpha value remains unchanged!
; Arguments:  Arg1: ARGB color.
; Return:     eax = Converted ARGB color.

Method Pixelmap.Gamma2Linear,, dARGB:DWORD
  SetObject xcx
  mov xdx, [xcx].pGam2LinTable
  mov eax, dARGB
  movzx ecx, BYTE ptr [dARGB]                           ;Blue channel
  and eax, PXM_MASK_REG_ALPHA                           ;Alpha is unchanged
  or al, BYTE ptr [xcx + xdx]                           ;Get the blue corrected value
  movzx ecx, BYTE ptr [dARGB + 1]                       ;Green Channel
  or ah, BYTE ptr [xcx + xdx]                           ;Get the green corrected value
  movzx ecx, BYTE ptr [dARGB + 2]                       ;Red Channel
  movzx ecx, BYTE ptr [xcx + xdx]                       ;Get the red corrected value
  shl ecx, 16
  or eax, ecx
MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Pixelmap.Linear2Gamma
; Purpose:    Convert from linear to gamma color space. Alpha value remains unchanged!
; Arguments:  Arg1: ARGB color.
; Return:     eax = Converted ARGB color.

Method Pixelmap.Linear2Gamma,, dARGB:DWORD
  SetObject xcx
  mov xdx, [xcx].pLin2GamTable
  mov eax, dARGB
  movzx ecx, BYTE ptr [dARGB]                           ;Blue channel
  and eax, PXM_MASK_REG_ALPHA                           ;Alpha is unchanged
  or al, BYTE ptr [xcx + xdx]                           ;Get the blue corrected value
  movzx ecx, BYTE ptr [dARGB + 1]                       ;Green Channel
  or ah, BYTE ptr [xcx + xdx]                           ;Get the green corrected value
  movzx ecx, BYTE ptr [dARGB + 2]                       ;Red Channel
  movzx ecx, BYTE ptr [xcx + xdx]                       ;Get the red corrected value
  shl ecx, 16
  or eax, ecx
MethodEnd

endif
