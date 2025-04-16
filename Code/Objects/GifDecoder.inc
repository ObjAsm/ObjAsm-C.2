; ==================================================================================================
; Title:      GifDecoder.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm support of GIF objects.
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


GIF_IMAGEFORMAT_1BIT  equ   2           ;1-bit, monochrome
GIF_IMAGEFORMAT_4BIT  equ   16          ;4-bit, 16-color
GIF_IMAGEFORMAT_8BIT  equ   256         ;8-bit, 256-color

; --------------------------------------------------------------------------------------------------
; Object:     GifDecoder
; Purpose:    This object is a decoding engine for GIF files. It is used by the GifPlayer object.
;             The GIF (Graphics Interchange Format) is the Copyright property of CompuServe Inc.
;             The Unisys LZW patent expired June 20th, 2003 in the USA and one year later
;             (July 7th, 2004) in the rest of the world.
;
;             Supported features:
;               - 2, 4, 8, 16, 32, 64, 128 and 256 color gifs.
;               - Outputting data as monochrome, 16 and 256 color bitmaps.
;
;             Not supported features:
;               - Interlaced gifs.
;               - Non-image drawing extensions (plain text extension).
;
; Note:       The LZW table has the following format:
;             An array of DWORDS represents an array of string entries.
;             One entry consists of a prefix code (which is an index to another entry that
;             should prefix the entry), a string length, and the suffix byte (this byte
;             should be added to the prefix to get the full string).
;             DWORD:
;             | AAAA AAAA | AAAA BBBB | BBBB BBBB | CCCC CCCC |
;               ^                                           ^
;              MSB                                         LSB
;             AAAAAAAAAAAA:  12-bit index in the LZW Table that indicates the prefix
;             BBBBBBBBBBBB:  12-bit length of the string
;             CCCCCCCC    :   8-bit suffix byte

Object GifDecoder, GifDecoderID, Primer
  StaticMethod      Decode,         POINTER, POINTER, DWORD, DWORD, DWORD, DWORD
                                    ;-> Data, -> Buffer, AlignedWidth, Width, Height, Format

  DefineVariable    pDataStream,    POINTER,    NULL    ;-> Compressed data buffer
  DefineVariable    pCurrentByte,   POINTER,    NULL    ;-> Current byte in buffer
  DefineVariable    bIniBitSize,    BYTE,       0       ;Initial LZW code size
  DefineVariable    bCurBitSize,    BYTE,       0       ;Current LZW code size
  DefineVariable    dCurBitMask,    DWORD,      0       ;Bit mask for the current bCurBitSize
  DefineVariable    bEndOfBlock,    BYTE,       FALSE   ;Indicates end of compressed data
  DefineVariable    pLastEOSB,      POINTER,    0       ;-> End of current sub-block
  DefineVariable    dClear,         DWORD,      0       ;Value of LZW Clear code
  DefineVariable    bBitsAvail,     BYTE,       0       ;Nbr of code bits currently available
  DefineVariable    dCurrentBits,   DWORD,      0       ;Holds the current loaded bits
  DefineVariable    bIsFirstCode,   BYTE,       FALSE   ;True if the first code is being read
  DefineVariable    pTable,         POINTER,    NULL    ;-> LZW table
  DefineVariable    dTableSize,     DWORD,      0       ;Current table size
  DefineVariable    dTableCount,    DWORD,      0       ;Current number of entries in table
  DefineVariable    pPixelBuffer,   POINTER,    NULL    ;Output pixel buffer
  DefineVariable    dPixelCounter,  DWORD,      0       ;Counts number of outputed pixels
  DefineVariable    dImageFormat,   DWORD,      0       ;GIF_IMAGEFORMAT_XBIT
  DefineVariable    dImageHeight,   DWORD,      0       ;Image height
  DefineVariable    dImageWidth,    DWORD,      0       ;Image width
  DefineVariable    dImageWidthAln, DWORD,      0       ;Image aligned width
ObjectEnd


; ==================================================================================================

if IMPLEMENT

; --------------------------------------------------------------------------------------------------
; Procedure:  GifDecoder_AddToTable
; Purpose:    Add an entry to the LZW Table.
;             The entry consists of a prefix and a suffix (size is calculated automatically).
; Arguments:  Arg1: Entry prefix.
;             Arg2: Entry suffix.
; Return:     eax = Code for the new entry.
; Note:       On entry xsi -> pSelf.

GifDecoder_AddToTable proc uses xbx dPrefix:DWORD, dSuffix:DWORD
  assume xsi:$ObjPtr(GifDecoder)

  ANNOTATION prv:xsi

  ;Check if enough space left in the table
  mov eax, [xsi].dTableCount
  inc eax
  shl eax, 2
  ;If no space left, make the table bigger:
  .if eax >= [xsi].dTableSize
    shl [xsi].dTableSize, 1                             ;Double table size
    mov [xsi].pTable, $MemReAlloc([xsi].pTable, [xsi].dTableSize)
  .endif

  mov edx, [xsi].dTableCount                            ;Create POINTER to first free entry
  mov ebx, edx
  shl xdx, 2
  add xdx, [xsi].pTable

  mov eax, dPrefix                                      ;Find out the size of the string
  shl eax, 2
  add xax, [xsi].pTable
  mov eax, [xax]
  shr eax, 8
  and eax, 0FFFh                                        ;eax now holds the size of
  inc eax                                               ;the prefix string

  mov ecx, dPrefix                                      ;Create the entry DWORD
  shl ecx, 20
  shl eax, 8
  or ecx, eax
  mov eax, dSuffix
  and eax, 0FFh
  or ecx, eax

  mov [xdx], ecx                                        ;Store entry

  inc [xsi].dTableCount
  mov cl, [xsi].bCurBitSize
  xor eax, eax
  inc eax
  shl eax, cl
  dec eax
  .if ebx == eax                                        ;Bit size should be increased
    .if [xsi].bCurBitSize < 12                          ;  but only if we have less than 12 bits
      inc [xsi].bCurBitSize                             ;Increase bitsize
      shl eax, 1
      or eax, 1
      mov [xsi].dCurBitMask, eax
    .endif
  .endif

  mov eax, ebx
  ret
  assume xsi:NOTHING
GifDecoder_AddToTable endp

; --------------------------------------------------------------------------------------------------
; Procedure:  GifDecoder_LoadNextByte
; Purpose:    Load the currentbits entry with new bits.
; Arguments:  None.
; Return:     Nothing.
; Note:       On entry xsi -> pSelf.

GifDecoder_LoadNextByte proc
  assume xsi:$ObjPtr(GifDecoder)

  ANNOTATION prv:xsi

  .if [xsi].bEndOfBlock != FALSE                        ;End of data already reached
    xor al, al                                          ;Return 0 as padding
  .else
    mov xdx, [xsi].pCurrentByte                         ;Get next byte from DataStream

    .if xdx == [xsi].pLastEOSB                          ;End of sub-block reached?
      xor eax, eax
      mov al, [xdx]                                     ;New sub-block size
      .if al == 0                                       ;If size = 0, end of data
        mov [xsi].bEndOfBlock, TRUE                     ;EOB indicator
        xor eax, eax
      .else                                             ;Set new end of sub-block
        inc xdx                                         ;New sub-block with size al
        add xax, xdx
        mov [xsi].pLastEOSB, xax                        ;Set new end of sub-block
        add [xsi].pCurrentByte, 2
        mov al, [xdx]
      .endif
    .else
      mov al, [xdx]                                     ;Get next byte
      inc [xsi].pCurrentByte                            ;Increase for next read
    .endif
  .endif

  ;Got the new byte from the data stream
  mov cl, [xsi].bBitsAvail                              ;Get nbr of bits available
  mov edx, [xsi].dCurrentBits                           ;Get current bits
  and eax, 0FFh                                         ;eax = al
  shl eax, cl                                           ;Shift bits to right position
  or edx, eax                                           ;OR new bits with current bits
  mov [xsi].dCurrentBits, edx                           ;Save bits
  add [xsi].bBitsAvail, 8                               ;Set new bits available
  ret
  assume xsi:NOTHING
GifDecoder_LoadNextByte endp

; --------------------------------------------------------------------------------------------------
; Procedure:  GifDecoder_OutputString
; Purpose:    Write the string of dCode to the output stream.
; Arguments:  Arg1: Code.
; Return:     al = First character of the string.
; Notes:      - On entry xsi -> pSelf.
;             - xsi is preserved by the caller.

GifDecoder_OutputString proc uses xbx xdi dCode:DWORD
  local dCounter:DWORD, dCount:DWORD

  ANNOTATION prv:xsi

  assume xsi:$ObjPtr(GifDecoder)

  mov ebx, dCode
  mov xdi, [xsi].pTable                                 ;Set base POINTER
  mov xcx, [xdi + sizeof(DWORD)*xbx]                    ;Get entry

  shr xcx, 8                                            ;Get size of string
  and xcx, 0FFFh
  mov dCount, ecx

  dec ecx
  mov dCounter, ecx

  ;-- 8 bit output -----------------------------------------------------------------------------
  .if [xsi].dImageFormat == GIF_IMAGEFORMAT_8BIT
    ;Output all codes backward
    .while TRUE
      mov ebx, [xdi + sizeof(DWORD)*xbx]

      ;PixelOffset = (PixelCounter/width)*alignedwidth + (PixelCounter % width)
      mov eax, dCounter
      add eax, [xsi].dPixelCounter

      cdq
      div [xsi].dImageWidth
      mov ecx, edx
      mul [xsi].dImageWidthAln
      add ecx, eax

      ;RealByteOffset = PixelOffset ;RealBitOffset = 0
      mov xdx, [xsi].pPixelBuffer
      or [xdx + xcx], bl

      .break .if dCounter == 0
      shr ebx, 20
      and ebx, 0FFFh
      dec dCounter
    .endw

  ;-- 4 bit output -----------------------------------------------------------------------------
  .elseif [xsi].dImageFormat == GIF_IMAGEFORMAT_4BIT
    ;Output all codes backward
    .while TRUE
      mov ebx, [xdi + sizeof(DWORD)*xbx]

      ;PixelOffset = (PixelCounter/width)*alignedwidth + (PixelCounter % width)
      mov eax, dCounter
      add eax, [xsi].dPixelCounter

      cdq
      div [xsi].dImageWidth
      mov ecx, edx
      mul [xsi].dImageWidthAln
      add ecx, eax

      shr ecx, 1
      mov eax, ebx
      mov xdx, [xsi].pPixelBuffer
      .if !CARRY?                                       ;Use high bits
        shl al, 4
      .endif
      or [xdx + xcx], al

      .break .if dCounter == 0
      shr ebx, 20
      and ebx, 0FFFh
      dec dCounter
    .endw

  ;-- 1 bit output -----------------------------------------------------------------------------
  .elseif [xsi].dImageFormat == GIF_IMAGEFORMAT_1BIT
    ;Output all codes backward
    .while TRUE
      mov ebx, [xdi + sizeof(DWORD)*xbx]

      ;PixelOffset = (PixelCounter/width)*alignedwidth + (PixelCounter % width)
      mov eax, dCounter
      add eax, [xsi].dPixelCounter

      cdq
      div [xsi].dImageWidth
      mov ecx, edx
      mul [xsi].dImageWidthAln
      add ecx, eax
      mov edx, ecx

      mov eax, ebx
      and cl, 111b                                      ;RealBitOffset  = PixelOffset & 111b;
      ror al, 1
      ror al, cl

      mov xcx, [xsi].pPixelBuffer
      shr edx, 3                                        ;RealByteOffset = PixelOffset % 8;
      or [xcx + xdx], al

      .break .if dCounter == 0
      shr ebx, 20
      and ebx, 0FFFh
      dec dCounter
    .endw
  .endif
  mov eax, dCount
  add [xsi].dPixelCounter, eax
  mov al, bl

  ret
  assume xsi:NOTHING
GifDecoder_OutputString endp

; --------------------------------------------------------------------------------------------------
; Procedure:  GifDecoder_Reset
; Purpose:    Reinitialize the decoder (LZW table, etc).
; Arguments:  None.
; Return:     Nothing.
; Note:       On entry xsi -> pSelf.

GifDecoder_Reset proc
  assume xsi:$ObjPtr(GifDecoder)

  ANNOTATION prv:xsi

  mov cl, [xsi].bIniBitSize                             ;Reset bit size
  mov [xsi].bCurBitSize, cl

  ;Get initial number of entries
  ;mov eax, [xdi].dColorCount
  ;NOTE: THE LINE ABOVE WAS PREVIOUSLY USED TO GET THE NR OF ROOT ENTRIES THIS DIDN'T WORK
  ;      BECAUSE 1-BIT GIF'S ARE FOR AN UNKNOWN REASON CODED AS 2-BIT GIFS, SO THE NR OF
  ;      ROOT ENTRIES HAS TO BE DETERMINED FROM THE INITIAL BITSIZE.

  dec cl
  xor eax, eax
  inc eax
  shl eax, cl                                           ;2^CodeSize
  add eax, 2
  mov [xsi].dTableCount, eax
  mov xdx, [xsi].pTable

  shl xax, 2                                            ;Fill first {2^CodeSize + 2} entries
  add xax, xdx
  xor ecx, ecx
  inc ch                                                ;Size of sting is set to 1
  .while xdx < xax
    mov [xdx], ecx
    inc cl
    add xdx, 4
  .endw

  mov eax, [xsi].dTableCount                            ;Set clear code
  sub eax, 2
  mov [xsi].dClear, eax

  mov [xsi].bIsFirstCode, TRUE
  mov cl, [xsi].bIniBitSize
  xor eax, eax
  inc eax
  shl eax, cl
  dec eax
  mov [xsi].dCurBitMask, eax
  ret
  assume xsi:NOTHING
GifDecoder_Reset endp

; --------------------------------------------------------------------------------------------------
; Method:     GifDecoder.Decode
; Purpose:    Decode the Gif data.
; Arguments:  Arg1: -> Data stream.
;             Arg2: -> Zeroed memory buffer.
;             Arg3: Image aligned width.
;             Arg4: Image width.
;             Arg5: Image height.
;             Arg6: Image format.
; Return:     xax -> last position in data stream.
; Note:       Based on the algorithm of exagon.
;
; LZW Decompression algorithm
;   [1] Initialize string table
;   [2] get first code: <code>
;   [3] output the string for <code> to the charstream
;   [4] <old> = <code>
;   [5] <code> <- next code in codestream;
;   [6] does <code> exist in the string table?
;       (yes: output the string for <code> to the charstream        (A)
;         [...] <- translation for <old>                            (B)
;         K <- first character of translation for <code>            (C)
;         add [...]K to the string table                            (D)
;         <old> <- <code>   )                                       (E)
;       (no: [...] <- translation for <old>                         (F)
;         K <- first character of [...]                             (G)
;         output [...]K to charstream and add it to string table    (H)
;         <old> <- <code>                                           (I)
;       )
;   [7] go to [5];

Method GifDecoder.Decode, uses xbx xdi xsi, pDataStream:POINTER, pBuffer:POINTER, \
                          dImageWidthAln:DWORD, dImageWidth:DWORD, dImageHeight:DWORD, \
                          dImageFormat:DWORD
  local bChar:BYTE, dPrefix:DWORD

  SetObject xsi
  mrm [xsi].pDataStream, pDataStream, xax
  mov cl, [xax]                                         ;Get initial LZW code size
  inc cl
  mov [xsi].bIniBitSize, cl
  mov [xsi].bCurBitSize, cl                             ;Set current bit size to initial bitsize
  inc xax
  mov [xsi].pCurrentByte, xax
  mov [xsi].pLastEOSB, xax

  m2m [xsi].pPixelBuffer, pBuffer, xax
  m2m [xsi].dImageWidthAln, dImageWidthAln, eax
  m2m [xsi].dImageWidth, dImageWidth, eax
  m2m [xsi].dImageHeight, dImageHeight, eax
  m2m [xsi].dImageFormat, dImageFormat, eax

  ;Set size of LZW table
  .if cl < 8                                            ;if initial code size is less than 8-bits,
    mov cl, 8                                           ;set to 8-bits, if higher, don't change it
  .endif

  ;Calculate size of code table and allocate it
  xor eax, eax
  inc eax
  add cl, 2                                             ;bitsize + 2
  shl eax, cl                                           ;eax = 2 ^ (bitsize + 2) = 4 * (2^bitsize)
  mov [xsi].dTableSize, eax
  mov [xsi].pTable, $MemAlloc(xax)                      ;Allocate memory for LZW Table and store POINTER
  invoke GifDecoder_Reset                               ;LZW Reset
  m2z [xsi].bBitsAvail
  m2z [xsi].dCurrentBits
  m2z [xsi].dPixelCounter
  m2z [xsi].bEndOfBlock

  invoke GifDecoder_LoadNextByte                        ;Load 4 bytes
  invoke GifDecoder_LoadNextByte
  invoke GifDecoder_LoadNextByte
  invoke GifDecoder_LoadNextByte

  mov eax, [xsi].dImageWidth
  mul [xsi].dImageHeight
  mov edi, eax                                          ;This is an OutputCode counter
                                                        ;not nbr of compressed codes
  .while edi != [xsi].dPixelCounter                     ;Done
    mov ebx, [xsi].dCurrentBits
    and ebx, [xsi].dCurBitMask
    mov cl, [xsi].bCurBitSize
    shr [xsi].dCurrentBits, cl                          ;Shift used bits
    sub [xsi].bBitsAvail, cl                            ;Decrease # of bits available
    .while [xsi].bBitsAvail <= 24                       ;Load as many bits as possible
      invoke GifDecoder_LoadNextByte
    .endw                                               ;ebx = Return bits

    .if ebx == [xsi].dClear                             ;Check for clearcode
      invoke GifDecoder_Reset                           ;Reset LZW
    .else
      .if [xsi].bIsFirstCode != FALSE                   ;Check for steps [1]-[4]
        m2z [xsi].bIsFirstCode                          ;[2]
        invoke GifDecoder_OutputString, ebx             ;[3]
        mov bChar, al                                   ;Saved for (G)
      .else
        .if ebx < [xsi].dTableCount                     ;[6] Is code in table?
          invoke GifDecoder_OutputString, ebx           ;(B) Yes
          mov bChar, al                                 ;Saved for (G)
          invoke GifDecoder_AddToTable, dPrefix, eax       ;(D)
        .else
          mov al, bChar                                 ;(G) No
          invoke GifDecoder_AddToTable, dPrefix, eax    ;(H)
          invoke GifDecoder_OutputString, ebx           ;(H)
          mov bChar, al                                 ;Saved for (G)
        .endif
      .endif
      mov dPrefix, ebx                                  ;[4]
    .endif
  .endw                                                 ;[7]

  MemFree [xsi].pTable                                  ;Free allocated LZW table
  mov xax, [xsi].pCurrentByte                           ;Return last pos. in stream
MethodEnd

endif
