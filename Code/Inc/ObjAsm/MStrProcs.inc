; ==================================================================================================
; Title:      MStrProcs.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm Managed String (MStr) macro and procedure implementations.
; Notes:      Version C.1.0, January 2023
;               - First release.
; ==================================================================================================


MSTR_ALL equ 7FFFFFFFh

MStrFree_X textequ <MemBlockFree_X>

.code

; --------------------------------------------------------------------------------------------------
; Macro:      MStrA / MStrW
; Purpose:    Build a MemBlock structure in the current segment.
; Arguments:  Arg1: (optional) MemBlock flags (MBF_xxx)
;             Arg2: (optional) Minimal payload size.
;             Arg3: Symbol name.
;             Arg4: Quoted text that fills the payload.
; Return:     Symbol reference to the payload.
; Notes:      - Quotation marks can be used as usual. See example.
;             - Partial input strings can be separated by commas.
;             - Break input lines with "\".
;             - Empty input strings ("" or '') causes an error.
;             - Numeric inputs in word range are possible.
;             - sizeof and length of directives work with this macro.
; Example:    MStrA MBF_WRITEABLE, 100, MyString, "Hello World", CRLF

MStrA macro Flags:=<0>, MinFreeSize:=<0>, TextReference:req, QuotedText:vararg
  org $ + MEMBLOCK_HEADER_SIZE
  align MEMBLOCK_PAYLOAD_ALIGNMENT
  ??MemBlockPayloadPosition = $                         ;;Remember this position
  StringA <TextReference>, <QuotedText>                 ;;Set MemBlock.bPayload = ANSI String
  ??Size = ((??StrSize + MinFreeSize + MEMBLOCK_PAYLOAD_GRANULARITY)/ \
            MEMBLOCK_PAYLOAD_GRANULARITY)*MEMBLOCK_PAYLOAD_GRANULARITY
  org ??MemBlockPayloadPosition - MEMBLOCK_HEADER_SIZE
  dw 0                                                  ;;wOffset = 0
  dw Flags
  dd ??Size                                             ;;Set MemBlock.dSize
  dd ??StrSize
  org $ + ??Size
endm

MStrW macro Flags:=<0>, MinFreeSize:=<0>, TextReference:req, QuotedText:vararg
  org $ + MEMBLOCK_HEADER_SIZE
  align MEMBLOCK_PAYLOAD_ALIGNMENT
  ??MemBlockPayloadPosition = $                         ;;Remember this position
  StringW <TextReference>, <QuotedText>                 ;;Set MemBlock.bPayload = WIDE String
  ??Size = ((??StrSize + MinFreeSize + MEMBLOCK_PAYLOAD_GRANULARITY)/ \
            MEMBLOCK_PAYLOAD_GRANULARITY)*MEMBLOCK_PAYLOAD_GRANULARITY
  org ??MemBlockPayloadPosition - MEMBLOCK_HEADER_SIZE
  dw 0                                                  ;;wOffset = 0
  dw Flags
  dd ??Size                                             ;;Set MemBlock.dSize
  dd ??StrSize
  org $ + ??Size
endm

; --------------------------------------------------------------------------------------------------
; Macro:      (C|T|D)MStr(A|B|W) / $Ofs(C|T|D)MStr(A|B|W)
; Purpose:    Construct an MemBlock structure in any segment
; Arguments:  Arg1: (optional) MemBlock flags (MBF_xxx)
;             Arg2: (optional) Minimal payload size.
;             Arg3: Symbol name.
;             Arg4: Quoted string that fills the payload.
; Return:     Symbol reference to the payload or offset to the payload.
; Notes:      - Quotation marks can be used as usual. See example.
;             - Partial input strings can be separated by commas.
;             - Break input lines with "\".
;             - Empty input strings ("" or '') causes an error.
;             - Numeric inputs in word range are possible.
;             - sizeof and length of directives work with this macro.
; Example:    mov xax, $OfsCMStrA("Hello World", CRLF)

CMStrA macro TextReference:req, QuotedText:vararg
  public TextReference
  .SegConst
    MStrA 0, <>, <TextReference>, <QuotedText>
  .SegRestore
endm

$OfsCMStrA macro QuotedText:vararg
  .SegConst
    MStrA 0, <>, <>, <QuotedText>
  .SegRestore
  exitm <offset ??MemBlockPayloadPosition>
endm


CMStrW macro TextReference:req, QuotedText:vararg
  public TextReference
  .SegConst
    MStrW 0, <>, <TextReference>, <QuotedText>
  .SegRestore
endm

$OfsCMStrW macro QuotedText:vararg
  .SegConst
    MStrW 0, <>, <>, <QuotedText>
  .SegRestore
  exitm <offset ??MemBlockPayloadPosition>
endm


CMstrB textequ <CMStrW>
$OfsCMStrB textequ <$OfsCMStrW>

if TARGET_STR_TYPE eq STR_TYPE_ANSI
  CMstr textequ <CMStrA>
  $OfsCMStr textequ <$OfsCMStrA>
else
  CMstr textequ <CMStrW>                               ;;Also valid for BStrings
  $OfsCMStr textequ <$OfsCMStrW>
endif


; --------------------------------------------------------------------------------------------------


DMStrA macro MinFreeSize:req, TextReference:req, QuotedText:vararg
  public TextReference
  .SegData
    MStrA MBF_WRITABLE, MinFreeSize, <TextReference>, <QuotedText>
  .SegRestore
endm

$OfsDMStrA macro MinFreeSize:req, QuotedText:vararg
  .SegData
    MStrA MBF_WRITABLE, MinFreeSize, <>, <QuotedText>
  .SegRestore
  exitm <offset ??MemBlockPayloadPosition>
endm


DMStrW macro MinFreeSize:req, TextReference:req, QuotedText:vararg
  public TextReference
  .SegData
    MStrW MBF_WRITABLE, MinFreeSize, <TextReference>, <QuotedText>
  .SegRestore
endm

$OfsDMStrW macro MinFreeSize:req, QuotedText:vararg
  .SegData
    MStrW MBF_WRITABLE, MinFreeSize, <>, <QuotedText>
  .SegRestore
  exitm <offset ??MemBlockPayloadPosition>
endm


DMStrB textequ <DMStrW>
$OfsDMStrB textequ <$OfsDMStrW>


if TARGET_STR_TYPE eq STR_TYPE_ANSI
  DMStr textequ <DMStrA>
  $OfsDMStr textequ <$OfsDMStrA>
else
  DMStr textequ <DMStrW>                                ;;Also valid for BStrings
  $OfsDMStr textequ <$OfsDMStrW>
endif


; --------------------------------------------------------------------------------------------------


TMStrA macro MinFreeSize:req, TextReference:req, QuotedText:vararg
  public TextReference
  .SegTestIsol
    MStrA MBF_WRITABLE, MinFreeSize, <TextReference>, <QuotedText>
  .SegRestore
endm

$OfsTMStrA macro MinFreeSize:req, QuotedText:vararg
  .SegTestIsol
    MStrA MBF_WRITABLE, MinFreeSize, <>, <QuotedText>
  .SegRestore
  exitm <offset ??MemBlockPayloadPosition>
endm


TMStrW macro MinFreeSize:req, TextReference:req, QuotedText:vararg
  public TextReference
  .SegTestIsol
    MStrW MBF_WRITABLE, MinFreeSize, <TextReference>, <QuotedText>
  .SegRestore
endm

$OfsTMStrW macro MinFreeSize:req, QuotedText:vararg
  .SegTestIsol
    MStrW MBF_WRITABLE, MinFreeSize, <>, <QuotedText>
  .SegRestore
  exitm <offset ??MemBlockPayloadPosition>
endm


TMStrB textequ <TMStrW>
$OfsTMStrB textequ <$OfsTMStrW>


if TARGET_STR_TYPE eq STR_TYPE_ANSI
  TMStr textequ <TMStrA>
  $OfsTMStr textequ <$OfsTMStrA>
else
  TMStr textequ <TMStrW>                                ;;Also valid for BStrings
  $OfsTMStr textequ <$OfsTMStrW>
endif

; --------------------------------------------------------------------------------------------------
; Macro:      $MStr / $MStrInit
; Purpose:    Allocate an MStr on the stack.
; Arguments:  Arg1: Variable name
;             Arg2: MStr capacity in chars.
; Return:     Sentence to be used wit the local keyword.
; Example:    local $MStr(MyStr, 100)
;             ...
;             mov xcx, $MStrInit(MyStr, <Hello>)

$MStr macro TextReference:req, Chars:req
  ??Size = MEMBLOCK_PAYLOAD_ALIGNMENT + MEMBLOCK_HEADER_SIZE + sizeof(CHR)*Chars + MEMBLOCK_PAYLOAD_GRANULARITY
  %exitm <TextReference[MEMBLOCK_HEADER_SIZE + ??Size]:BYTE>
endm

$MStrInit macro TextReference:req, QuotedText:vararg
  lea xax, [TextReference.MemBlock.bPayload + MEMBLOCK_PAYLOAD_ALIGNMENT] 
  and xax, -MEMBLOCK_PAYLOAD_ALIGNMENT
  lea xcx, TextReference
  add xcx, sizeof(TextReference)
  sub xcx, xax
  ifnb <StrValue>
    %FillQuotedString [xax], QuotedText
  endif
if DEBUGGING
  lea xdx, [TextReference]
  sub xdx, xax
  neg xdx
  mov [xax - MEMBLOCK_HEADER_SIZE].MemBlockHeader.wOffset, dx
else  
  mov [xax - MEMBLOCK_HEADER_SIZE].MemBlockHeader.wOffset, 0
endif
  mov [xax - MEMBLOCK_HEADER_SIZE].MemBlockHeader.wFlags, MBF_WRITABLE
  mov [xax - MEMBLOCK_HEADER_SIZE].MemBlockHeader.dSize, ecx
  mov [xax - MEMBLOCK_HEADER_SIZE].MemBlockHeader.dUsed, ??StrSize
  exitm <xax>
endm

; --------------------------------------------------------------------------------------------------
; Procedure:  MStrNewFromMem
; Purpose:    Create a new dynamic MStr and copy the content pointed to by pMem to the payload.
; Arguments:  Arg1: Mininal payload size.
;             Arg2: -> Source memory.
;             Arg3: Source memory size. In case of a regular string, include the ZTC in the count.
; Return:     xax -> New MemBlock.bPayload.
; Note:       The allocated memory size is a multiple of MEMBLOCK_ALLOC_GRANULARITY
;             and the free space on the payload is at least equal to MEMBLOCK_ALLOC_GRANULARITY.

MStrNewFromMem_XT proc uses xbx xdi dMinSize:DWORD, pMem:POINTER, dMemSize:DWORD
  ?mov ecx, dMinSize
  mov ebx, dMemSize
  cmp ecx, ebx
  cmovl ecx, ebx                                        ;ecx = Max(ebx, ecx)
  invoke MemBlockAlloc_X, ecx                           ;xax -> Payload
  test xax, xax
  jz @@Error
  m2m [xax - MEMBLOCK_HEADER_SIZE].MemBlockHeader.dUsed, ebx
  mov xdx, pMem
  .if xdx != NULL
    mov xdi, xax
    invoke MemClone, xax, xdx, ebx
    mov xax, xdi
  .endif
@@Error:
  ret
MStrNewFromMem_XT endp

; --------------------------------------------------------------------------------------------------
; Procedure:  MStrNew
; Purpose:    Create a new dynamic MStr and copy the content from a source MStr.
; Arguments:  Arg1: Mininal payload size.
;             Arg2: -> Source MStr.
; Return:     xax -> New MemBlock.bPayload.
; Note:       The allocated memory size is a multiple of MEMBLOCK_ALLOC_GRANULARITY
;             and the free space on the payload is at least equal to MEMBLOCK_ALLOC_GRANULARITY.

MStrNew_X proc dMinSize:DWORD, pSrcMStrPayload:PSTRING
  ?mov edx, pSrcMStrPayload
  invoke MStrNewFromMem_XT, dMinSize, xdx, [xdx - MEMBLOCK_HEADER_SIZE].MemBlockHeader.dUsed
  ret
MStrNew_X endp

; --------------------------------------------------------------------------------------------------
; Procedure:  MStrCat
; Purpose:    Concatenate 2 MStr's.
; Arguments:  Arg1: -> Destination MStr.
;             Arg2: -> Source MStr.
; Return:     xax -> Updated/New MemBlock.bPayload.
; Note:       If the destination MStr is dynamic and writable and has not the capacity to hold
;             the concatenated string, then the payload is resized.
;             If the destination MStr is NOT dynamic, writabe but too short, a new dynamic MStr
;             with the necessary capacity is allocated.
;             In any case, the first attempt on a writable MStr is to do the operation in place.

MStrCat_XT proc uses xbx xsi pDstMStrPayload:PSTRING, pSrcMStrPayload:PSTRING
  ?mov ecx, pDstMStrPayload
  mov xsi, pSrcMStrPayload
  mov eax, [xcx - MEMBLOCK_HEADER_SIZE].MemBlockHeader.dUsed
  add eax, [xsi - MEMBLOCK_HEADER_SIZE].MemBlockHeader.dUsed
  sub eax, sizeof(CHR)                                  ;1 ZTC less
  .if eax > [xcx - MEMBLOCK_HEADER_SIZE].MemBlockHeader.dSize
    lea ebx, [eax + MEMBLOCK_HEADER_SIZE + 2*HEAP_ALLOC_GRANULARITY - 1]
    and ebx, -HEAP_ALLOC_GRANULARITY
    .ifBitSet [xcx - MEMBLOCK_HEADER_SIZE].MemBlockHeader.wFlags, MBF_WRITABLE
      .ifBitSet [xcx - MEMBLOCK_HEADER_SIZE].MemBlockHeader.wFlags, MBF_DYNAMIC
        ;Enlarge destiantion MStr
        lea xax, [xcx - MEMBLOCK_HEADER_SIZE]
        MemReAlloc xax, xbx
        test xax, xax
        jz @@Error
        jmp @F
      .endif
    .endif
    ;Not writable => create a copy and append to it
    invoke MStrNew_X, ebx, pDstMStrPayload                         ;xax -> MemBlock.bPayload
    test xax, xax
    jz @@Error
    sub xax, MEMBLOCK_HEADER_SIZE
@@:
    mov [xax].MemBlockHeader.dSize, ebx
    mov ebx, [xsi - MEMBLOCK_HEADER_SIZE].MemBlockHeader.dUsed
    mov ecx, [xax].MemBlockHeader.dUsed
    add [xax].MemBlockHeader.dUsed, ebx
    sub [xax].MemBlockHeader.dUsed, sizeof(CHR)
    add xax, MEMBLOCK_HEADER_SIZE
    mov pDstMStrPayload, xax
  .else
    .ifBitSet [xcx - MEMBLOCK_HEADER_SIZE].MemBlockHeader.wFlags, MBF_WRITABLE
      ;Append in place
      mov ebx, [xsi - MEMBLOCK_HEADER_SIZE].MemBlockHeader.dUsed
      mov eax, [xcx - MEMBLOCK_HEADER_SIZE].MemBlockHeader.dUsed
      add [xcx - MEMBLOCK_HEADER_SIZE].MemBlockHeader.dUsed, ebx
      sub [xcx - MEMBLOCK_HEADER_SIZE].MemBlockHeader.dUsed, sizeof(CHR)
      mov pDstMStrPayload, xcx
    .else
      ;Not writable => create a copy and append to it
      invoke MStrNew_X, eax, pDstMStrPayload                       ;xax -> MemBlock.bPayload
      test xax, xax
      jz @@Error
      mov ebx, [xsi - MEMBLOCK_HEADER_SIZE].MemBlockHeader.dUsed
      lea edx, [xbx - sizeof(CHR)]
      mov ecx, [xax - MEMBLOCK_HEADER_SIZE].MemBlockHeader.dUsed
      add [xax - MEMBLOCK_HEADER_SIZE].MemBlockHeader.dUsed, edx
      mov pDstMStrPayload, xax
    .endif
  .endif
  invoke MemClone, addr [xcx + xax - sizeof(CHR)], xsi, ebx
  mov xax, pDstMStrPayload

@@Error:
  ret
MStrCat_XT endp

; --------------------------------------------------------------------------------------------------
; Procedure:  MStrCatChr
; Purpose:    Concatenate a char to a MStr.
; Arguments:  Arg1: -> Destination MStr.
;             Arg2: Character.
; Return:     xax -> Updated/New MemBlock.bPayload.
; Note:       If the destination MStr is dynamic and writable and has not the capacity to hold
;             the concatenated string, then the payload is resized.
;             If the destination MStr is NOT dynamic, writabe but too short, a new dynamic MStr
;             with the necessary capacity is allocated.
;             In any case, the first attempt on a writable MStr is to do the operation in place.

MStrCatChr_XT proc pDstMStrPayload:PSTRING, Char:CHR
  local $MStr(MStrChar, 2*sizeof(CHR))                  ;Local (temporary) MStr that holds the Char

  movzx $SubReg(edx, 2*sizeof(CHR)), Char               ;Load the ZTC at the same time
  mov MStrChar.MemBlockHeader.dUsed, 2*sizeof(CHR)      ;Set the size
  mov DCHR ptr MStrChar.MemBlock.bPayload[0], $SubReg(xdx, 2*sizeof(CHR))   ;Store the Payload
  invoke MStrCat_XT, pDstMStrPayload, addr MStrChar.MemBlock.bPayload       ;Append the local MStr
  ret
MStrCatChr_XT endp


; --------------------------------------------------------------------------------------------------
; Procedure:  MStrMid
; Purpose:    Extract a subMStr from an MStr.
; Arguments:  Arg1: -> Source MStr.
;             Arg2: From position. If negative, the counting starts from the end.
;             Arg3: Character count.
; Return:     xax -> New dynamic MemBlock.bPayload.

MStrMid_TX proc uses xbx xdi xsi pSrcMStrPayload:PSTRINGA, sdFromChar:SDWORD, dCharCount:DWORD
  mov xsi, pSrcMStrPayload
  mov eax, sdFromChar
  mov ebx, dCharCount
  .if SDWORD ptr eax >= 0                               ;Counting from the left, starting with 0
    mov ecx, [xsi - MEMBLOCK_HEADER_SIZE].MemBlock.dUsed
  if TARGET_STR_TYPE eq STR_TYPE_WIDE
    shr ecx, 1
  endif
    dec ecx                                             ;ZTC
    .if SIGN? || eax < ecx
      add eax, ebx
      .if eax > ecx
        mov eax, ecx
        sub eax, sdFromChar
        mov ebx, eax
      .endif
  if TARGET_STR_TYPE eq STR_TYPE_ANSI
      inc ebx
  else
      lea ebx, [sizeof(CHRW)*ebx + sizeof(CHRW)]
  endif
      invoke MemBlockAlloc_X, ebx
      mov xdi, xax
      mov [xax - MEMBLOCK_HEADER_SIZE].MemBlock.dUsed, ebx
      sub ebx, sizeof(CHR)
      mov edx, sdFromChar
      m2z CHR ptr [xax + xbx]
      lea xdx, [xsi + sizeof(CHR)*xdx]
      invoke MemClone, xax, xdx, ebx
      mov xax, xdi
    .else
      invoke MemBlockAlloc_X, 0
    .endif

  .else
    mov ecx, [xsi - MEMBLOCK_HEADER_SIZE].MemBlock.dUsed
  if TARGET_STR_TYPE eq STR_TYPE_WIDE
    shr ecx, 1
  endif
    dec ecx
    add eax, ecx
    mov sdFromChar, eax

    .if !SIGN?
      add eax, ebx
      .if eax > ecx
        mov eax, ecx
        sub eax, sdFromChar
        mov ebx, eax
      .endif
  if TARGET_STR_TYPE eq STR_TYPE_ANSI
      inc ebx
  else
      lea ebx, [sizeof(CHRW)*ebx + sizeof(CHRW)]
  endif
      invoke MemBlockAlloc_X, ebx
      mov xdi, xax
      mov [xax - MEMBLOCK_HEADER_SIZE].MemBlock.dUsed, ebx
      sub ebx, sizeof(CHR)
      m2z CHR ptr [xax + xbx]
      mov edx, sdFromChar
      lea xdx, [xsi + sizeof(CHR)*xdx]
      invoke MemClone, xax, xdx, ebx
      mov xax, xdi
    .else
      add eax, ebx
      .if !SIGN?
        lea ebx, [sizeof(CHR)*eax + sizeof(CHR)]
        invoke MemBlockAlloc_X, ebx
        mov xdi, xax
        mov [xax - MEMBLOCK_HEADER_SIZE].MemBlock.dUsed, ebx
        sub ebx, sizeof(CHR)
        m2z CHRA ptr [xax + xbx]
        invoke MemClone, xax, xsi, ebx
        mov xax, xdi
      .else
        invoke MemBlockAlloc_X, 0
      .endif
    .endif
  .endif
  ret
MStrMid_TX endp

; --------------------------------------------------------------------------------------------------
; Procedure:  MStrSize
; Purpose:    Get the payload byte size of a MStr.
; Arguments:  Arg1: -> Source MStr.
; Return:     eax = Payload byte size (including the ZTC).

MStrSize proc pSrcMStrPayload:PSTRING
  ?mov ecx, pSrcMStrPayload
  mov eax, [xcx - MEMBLOCK_HEADER_SIZE].MemBlockHeader.dUsed
  ret
MStrSize endp

; --------------------------------------------------------------------------------------------------
; Procedure:  MStrLength
; Purpose:    Get the payload String length of a MStr.
; Arguments:  Arg1: -> Source MStr.
; Return:     eax = Payload String character count (NOT including the ZTC).

MStrLength_TX proc pSrcMStrPayload:PSTRING
  ?mov ecx, pSrcMStrPayload
  mov eax, [xcx - MEMBLOCK_HEADER_SIZE].MemBlockHeader.dUsed
  .if eax >= sizeof(CHR)
    sub eax, sizeof(CHR)
  .else
    xor eax, eax                                        ;Just in case when STR_TYPE_WIDE and eax = 1
  .endif
  ret
MStrLength_TX endp

; --------------------------------------------------------------------------------------------------
; Procedure:  MStrRTrim
; Purpose:    Get the right trimmed MStr of a given MStr.
; Arguments:  Arg1: -> Source MStr.
; Return:     xax -> Right trimmed MStr.

MStrRTrim_TX proc pSrcMStrPayload:PSTRING
  $$ChrReg equ $SubReg(ecx, sizeof(CHR))

if TARGET_BITNESS eq 32
  mov edx, pSrcMStrPayload
else
  mov rdx, rcx
endif
  mov eax, [xdx - MEMBLOCK_HEADER_SIZE].MemBlockHeader.dUsed
  lea xax, [xdx + xax - sizeof(CHR)]
@@:
  sub xax, sizeof(CHR)                                  ;Move to prev char
  cmp xax, xdx
  jb @F
  mov $$ChrReg, [xax]
  cmp $$ChrReg, ' '                                     ;Loop if space
  je @B
  cmp $$ChrReg, TAB                                     ;Loop if tab
  je @B
@@:
  sub xax, xdx                                          ;pSrcString
  add xax, sizeof(CHR)
  m2z CHR ptr [xax + xdx]
  invoke MStrNewFromMem_XT, 0, xdx, eax
  ret
MStrRTrim_TX endp

; --------------------------------------------------------------------------------------------------
; Procedure:  MStrLTrim
; Purpose:    Get the left trimmed MStr of a given MStr.
; Arguments:  Arg1: -> Source MStr.
; Return:     xax -> Left trimmed MStr.

MStrLTrim_TX proc pSrcMStrPayload:PSTRING
  $$ChrReg equ $SubReg(eax, sizeof(CHR))

if TARGET_BITNESS eq 32
  mov ecx, pSrcMStrPayload
endif
  mov xdx, xcx
@@:
  mov $$ChrReg, [xdx]
  add xdx, sizeof(CHR)                                  ;Move to next char
  cmp $$ChrReg, 0                                       ;ZTC?
  je @F
  cmp $$ChrReg, ' '                                     ;Loop if space
  je @B
  cmp $$ChrReg, TAB                                     ;Loop if tab
  je @B
@@:
  sub xdx, sizeof(CHR)
  mov eax, [xcx - MEMBLOCK_HEADER_SIZE].MemBlockHeader.dUsed
  sub xax, xdx
  add xax, xcx
  invoke MStrNewFromMem_XT, 0, xdx, eax
  ret
MStrLTrim_TX endp

; --------------------------------------------------------------------------------------------------
; Procedure:  MStrTrim
; Purpose:    Get the left & right trimmed MStr of a given MStr.
; Arguments:  Arg1: -> Source MStr.
; Return:     xax -> Left & right trimmed MStr.

MStrTrim_TX proc pSrcMStrPayload:PSTRING
  $$ChrReg equ $SubReg(eax, sizeof(CHR))

if TARGET_BITNESS eq 32
  mov ecx, pSrcMStrPayload
endif
  mov xdx, xcx
@@:
  mov $$ChrReg, [xdx]
  add xdx, sizeof(CHR)                                  ;Move to next char
  cmp $$ChrReg, 0                                       ;ZTC?
  je @F
  cmp $$ChrReg, ' '                                     ;Loop if space
  je @B
  cmp $$ChrReg, TAB                                     ;Loop if tab
  je @B
@@:
  sub xdx, sizeof(CHR)
  mov eax, [xcx - MEMBLOCK_HEADER_SIZE].MemBlockHeader.dUsed
  sub xax, xdx
  add xax, xcx                                          ;xdx -> 1st char; eax = # bytes

  $$ChrReg equ $SubReg(ecx, sizeof(CHR))

  lea xax, [xax + xdx - sizeof(CHR)]                    ;xax -> ZTC
@@:
  sub xax, sizeof(CHR)                                  ;Move to prev char
  cmp xax, xdx
  jb @F
  mov $$ChrReg, [xax]
  cmp $$ChrReg, ' '                                     ;Loop if space
  je @B
  cmp $$ChrReg, TAB                                     ;Loop if tab
  je @B
@@:
  sub xax, xdx                                          ;pSrcString
  add xax, sizeof(CHR)
  invoke MStrNewFromMem_XT, 0, xdx, eax
  mov ecx, [xax - MEMBLOCK_HEADER_SIZE].MemBlockHeader.dUsed
  add [xax - MEMBLOCK_HEADER_SIZE].MemBlockHeader.dUsed, sizeof(CHR)
  m2z CHR ptr [xax + xcx]
  ret
MStrTrim_TX endp
