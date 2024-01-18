; ==================================================================================================
; Title:      MemBlock.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm support of MemBlock handling macros.
; Notes:      Version C.1.0, January 2023
;               - First release.
; ==================================================================================================


; MemBlock layout:
;                                                              MemBlock points here!
;        Offset BYTEs    WORD     WORD      DWORD         DWORD    v
;       ————————————————————————————————————————————————————————————————————————————————————
;  ... |  Padding     | Offset | Flags |  BYTE Size  | BYTE Usage  | BYTE Payload           | ...
;       ————————————————————————————————————————————————————————————————————————————————————
;      ^                                                           ^
;      Heap Alignment 8/16                                         Alignment 4/8/16/32/...
;
;                                                     <------------------------------------>
;                                                      BSTR if the payload is a WIDE string


; ==================================================================================================


;MemBlock Flags
;The remainig bits are left for application specific use
MBF_WRITABLE  equ BIT00
MBF_DYNAMIC   equ BIT01

MemBlockHeader struct
  wOffset   WORD  ?           ;Offset from start of heap allocation to start of the MemBlockHeader
  wFlags    WORD  ?           ;Flags
  dSize     DWORD ?           ;Payload size in BYTEs
  dUsed     DWORD ?           ;Payload usage (incl. ZTC) in BYTEs
MemBlockHeader ends
MEMBLOCK_HEADER_SIZE equ sizeof(MemBlockHeader)

MemBlock struct
  MemBlockHeader  <>
  bPayload  BYTE  0 dup(?)
MemBlock ends

;The heap allocation granularity is 8 for 32-bit applications and 16 for a 64-bit applications.
;https://techcommunity.microsoft.com/t5/ask-the-performance-team/what-a-heap-of-part-one/ba-p/372424
HEAP_ALLOC_GRANULARITY = TARGET_BITNESS/4

;The heap allocation alignment is 8 for 32-bit applications and 16 for 64-bit applications.
HEAP_ALLOC_ALIGNMENT = TARGET_BITNESS/4

;For heap allocations, padding bytes are required to control payload alignment.
;This value can be changed according to the requirements of the architecture, such as SSE or AVX.
MEMBLOCK_PAYLOAD_ALIGNMENT = 16                 ;SSE architecture, PARA alignment
MEMBLOCK_PAYLOAD_GRANULARITY = 16*sizeof(CHR)   ;At least 128-bit for XMM register access

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  MemBlockAlloc
; Purpose:    Allocate a MemBlock with a given payload size.
; Arguments:  Arg1: Min. payload size in BYTEs.
; Return:     xax -> MemBlock.bPayload or NULL if failed.
; Note:       The allocated memory size is a multiple of MEMBLOCK_ALLOC_GRANULARITY
;             and the free space on the payload is at least equal to MEMBLOCK_ALLOC_GRANULARITY.
.code
align ALIGN_CODE
MemBlockAlloc_X proc uses xbx dMinPayloadSize:DWORD
  ?mov ecx, dMinPayloadSize
  lea ebx, [MEMBLOCK_PAYLOAD_ALIGNMENT + MEMBLOCK_HEADER_SIZE + ecx + MEMBLOCK_PAYLOAD_GRANULARITY]
  and ebx, -HEAP_ALLOC_GRANULARITY
  DbgDec ebx
  MemAlloc xbx
  test xax, xax
  jz @@Error
  lea xcx, [xax + MEMBLOCK_HEADER_SIZE + MEMBLOCK_PAYLOAD_ALIGNMENT]
  and xcx, -MEMBLOCK_PAYLOAD_ALIGNMENT
  sub xcx, xax
  sub xcx, MEMBLOCK_HEADER_SIZE
  .while SIGN?
    add xcx, MEMBLOCK_PAYLOAD_ALIGNMENT
  .endw
  add xax, xcx
  mov [xax].MemBlockHeader.wFlags, MBF_DYNAMIC or MBF_WRITABLE
  mov [xax].MemBlockHeader.wOffset, cx
  sub ebx, MEMBLOCK_HEADER_SIZE
  sub ebx, ecx
  mov [xax].MemBlockHeader.dSize, ebx
  mov [xax].MemBlockHeader.dUsed, 0
  add xax, MEMBLOCK_HEADER_SIZE
@@Error:
  ret
MemBlockAlloc_X endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  MemBlockFree
; Purpose:    Deallocate an MemBlock.
; Arguments:  Arg1: -> MemBlock.bPayload.
; Return:     Nothing.

.code
align ALIGN_CODE
MemBlockFree_X proc pMemBlockPayload:POINTER
  ?mov xcx, pMemBlockPayload
  lea xax, [xcx - MEMBLOCK_HEADER_SIZE]
  .ifBitSet [xax].MemBlockHeader.wFlags, MBF_DYNAMIC
    movzx xcx, [xax].MemBlockHeader.wOffset
    sub xax, xcx
    MemFree xax
  .else
    DbgWarning "MemBlockFree: MemBlock is not DYNAMIC"
  .endif
  ret
MemBlockFree_X endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  MemBlockClone
; Purpose:    Clone a MemBlock.
; Arguments:  Arg1: -> MemBlock.bPayload.
; Return:     xax -> Cloned MemBlock.bPayload.
; Note:       MemBlockHeader.wFlags are set to MBF_DYNAMIC || MBF_WRITABLE.

.code
align ALIGN_CODE
MemBlockClone_X proc uses xbx xdi pMemBlockPayload:POINTER
  ?mov xcx, pMemBlockPayload
  lea xax, [xcx - MEMBLOCK_HEADER_SIZE]
  mov ebx, [xax].MemBlockHeader.dSize
  add ebx, MEMBLOCK_HEADER_SIZE
  MemAlloc xbx
  test xax, xax
  jz @@Error
  mov xdi, xax
  mov xcx, pMemBlockPayload
  lea xdx, [xcx - MEMBLOCK_HEADER_SIZE]
  invoke MemClone, xax, xdx, ebx
  mov xax, xdi
  mov [xdi].MemBlockHeader.wFlags, MBF_DYNAMIC or MBF_WRITABLE
@@Error:
  ret
MemBlockClone_X endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      MemBlockA / MemBlockW
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
; Example:    MemBlockA MBF_WRITEABLE, 100, MyString, "Hello World", CRLF

MemBlockA macro Flags:=<0>, MinFreeSize:=<0>, TextReference:req, QuotedText:vararg
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

MemBlockW macro Flags:=<0>, MinFreeSize:=<0>, TextReference:req, QuotedText:vararg
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

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      (C|T|D)Block(A|B|W) / $Ofs(C|T|D)Block(A|B|W)
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
; Example:    mov xax, $OfsCBlockA("Hello World", CRLF)

CBlockA macro TextReference:req, QuotedText:vararg
  public TextReference
  .SegConst
    MemBlockA 0, <>, <TextReference>, <QuotedText>
  .SegRestore
endm

$OfsCBlockA macro QuotedText:vararg
  .SegConst
    MemBlockA 0, <>, <>, <QuotedText>
  .SegRestore
  exitm <offset ??MemBlockPayloadPosition>
endm


CBlockW macro TextReference:req, QuotedText:vararg
  public TextReference
  .SegConst
    MemBlockW 0, <>, <TextReference>, <QuotedText>
  .SegRestore
endm

$OfsCBlockW macro QuotedText:vararg
  .SegConst
    MemBlockW 0, <>, <>, <QuotedText>
  .SegRestore
  exitm <offset ??MemBlockPayloadPosition>
endm


CBlockB textequ <CBlockW>
$OfsCBlockB textequ <$OfsCBlockW>

if TARGET_STR_TYPE eq STR_TYPE_ANSI
  CBlock textequ <CBlockA>
  $OfsCBlock textequ <$OfsCBlockA>
else
  CBlock textequ <CBlockW>                              ;;Also valid for BStrings
  $OfsCBlock textequ <$OfsCBlockW>
endif


; ——————————————————————————————————————————————————————————————————————————————————————————————————


DBlockA macro MinFreeSize:req, TextReference:req, QuotedText:vararg
  public TextReference
  .SegData
    MemBlockA MBF_WRITABLE, MinFreeSize, <TextReference>, <QuotedText>
  .SegRestore
endm

$OfsDBlockA macro MinFreeSize:req, QuotedText:vararg
  .SegData
    MemBlockA MBF_WRITABLE, MinFreeSize, <>, <QuotedText>
  .SegRestore
  exitm <offset ??MemBlockPayloadPosition>
endm


DBlockW macro MinFreeSize:req, TextReference:req, QuotedText:vararg
  public TextReference
  .SegData
    MemBlockW MBF_WRITABLE, MinFreeSize, <TextReference>, <QuotedText>
  .SegRestore
endm

$OfsDBlockW macro MinFreeSize:req, QuotedText:vararg
  .SegData
    MemBlockW MBF_WRITABLE, MinFreeSize, <>, <QuotedText>
  .SegRestore
  exitm <offset ??MemBlockPayloadPosition>
endm


DBlockB textequ <DBlockW>
$OfsDBlockB textequ <$OfsDBlockW>


if TARGET_STR_TYPE eq STR_TYPE_ANSI
  DBlock textequ <DBlockA>
  $OfsDBlock textequ <$OfsDBlockA>
else
  DBlock textequ <DBlockW>                              ;;Also valid for BStrings
  $OfsDBlock textequ <$OfsDBlockW>
endif


; ——————————————————————————————————————————————————————————————————————————————————————————————————


TBlockA macro MinFreeSize:req, TextReference:req, QuotedText:vararg
  public TextReference
  .SegTestIsol
    MemBlockA MBF_WRITABLE, MinFreeSize, <TextReference>, <QuotedText>
  .SegRestore
endm

$OfsTBlockA macro MinFreeSize:req, QuotedText:vararg
  .SegTestIsol
    MemBlockA MBF_WRITABLE, MinFreeSize, <>, <QuotedText>
  .SegRestore
  exitm <offset ??MemBlockPayloadPosition>
endm


TBlockW macro MinFreeSize:req, TextReference:req, QuotedText:vararg
  public TextReference
  .SegTestIsol
    MemBlockW MBF_WRITABLE, MinFreeSize, <TextReference>, <QuotedText>
  .SegRestore
endm

$OfsTBlockW macro MinFreeSize:req, QuotedText:vararg
  .SegTestIsol
    MemBlockW MBF_WRITABLE, MinFreeSize, <>, <QuotedText>
  .SegRestore
  exitm <offset ??MemBlockPayloadPosition>
endm


TBlockB textequ <TBlockW>
$OfsTBlockB textequ <$OfsTBlockW>


if TARGET_STR_TYPE eq STR_TYPE_ANSI
  TBlock textequ <TBlockA>
  $OfsTBlock textequ <$OfsTBlockA>
else
  TBlock textequ <TBlockW>                              ;;Also valid for BStrings
  $OfsTBlock textequ <$OfsTBlockW>
endif

; ——————————————————————————————————————————————————————————————————————————————————————————————————
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
