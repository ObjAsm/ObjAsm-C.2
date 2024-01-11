; ==================================================================================================
; Title:      MemBlock.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm support of MemBlock handling macros.
; Notes:      Version C.1.0, January 2023
;               - First release.
; ==================================================================================================


; MemBlock format:
;                                                MemBlock points here!
;          4 bytes       4 bytes      4 bytes    v
;       ——————————————————————————————————————————————————————————————————
;  ... |    Flags    |  BYTE Size  | BYTE Usage  | BYTE Payload           | ...
;       ——————————————————————————————————————————————————————————————————
;      ^                                         ^
;      Alignment 8/16                            Alignment 4
;
;                                   <------------------------------------>
;                                    BSTR if the payload is a WIDE string


; ==================================================================================================

;https://www.labri.fr/perso/betrema/winnt/heapmm.html
MEMBLOCK_ALLOC_GRANULARITY = 16*sizeof(CHR)             ;Heap allocation granularity is 16 BYTEs

;The MemBlock alignment is 8 on 32 bit and 16 on 64 bit, matching the alignment of Heap allocations. 
MEMBLOCK_ALIGN = 2*@WordSize

;MemBlock Flags
;The remainig bits are left for application specific use
MBF_WRITABLE  equ BIT31
MBF_DYNAMIC   equ BIT30

MemBlockHeader struct
  dFlags    DWORD ?
  dSize     DWORD ?
  dUsed     DWORD ?
MemBlockHeader ends

MemBlock struct
  MemBlockHeader  <>
  bPayload  BYTE  0 DUP (?)
MemBlock ends


; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  MemBlockAlloc
; Purpose:    Allocate a MemBlock with a given payload size.
; Arguments:  Arg1: Payload size in BYTEs.
; Return:     xax -> MemBlock.bPayload.
; Note:       The allocated memory size is a multiple of MEMBLOCK_ALLOC_GRANULARITY
;             and the free space on the payload is at least equal to MEMBLOCK_ALLOC_GRANULARITY.
.code
align ALIGN_CODE
MemBlockAlloc_X proc uses xbx dPayloadSize:DWORD
  ?mov ecx, dPayloadSize
  lea ebx, [ecx + sizeof(MemBlockHeader) + 2*MEMBLOCK_ALLOC_GRANULARITY - 1]
  and ebx, -MEMBLOCK_ALLOC_GRANULARITY
  MemAlloc xbx
  mov [xax].MemBlockHeader.dFlags, MBF_DYNAMIC or MBF_WRITABLE
  mov [xax].MemBlockHeader.dSize, ebx
  mov [xax].MemBlockHeader.dUsed, 0
  if MEMBLOCK_ALLOC_GRANULARITY ge 2
    mov CHRW ptr [xax].MemBlock.bPayload, 0             ;Just in case
  elseif MEMBLOCK_ALLOC_GRANULARITY eq 1
    mov CHRA ptr [xax].MemBlock.bPayload, 0             ;Just in case
  else
    .err <MEMBLOCK_ALLOC_GRANULARITY can NOT be zero>
  endif
  add xax, sizeof(MemBlockHeader)
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
  lea xax, [xcx - sizeof(MemBlockHeader)]
  .ifBitSet [xax].MemBlockHeader.dFlags, MBF_DYNAMIC
    MemFree xax
  .else
    DbgWarning "MemBlock is not DYNAMIC"
  .endif
  ret
MemBlockFree_X endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  MemBlockClone
; Purpose:    Clone a MemBlock.
; Arguments:  Arg1: -> MemBlock.bPayload.
; Return:     xax -> Cloned MemBlock.bPayload.
; Note:       MemBlockHeader.dFlags are set to MBF_DYNAMIC || MBF_WRITABLE.

.code
align ALIGN_CODE
MemBlockClone_X proc uses xbx xdi pMemBlockPayload:POINTER
  ?mov xcx, pMemBlockPayload
  lea xax, [xcx - sizeof(MemBlockHeader)]
  mov ebx, [xax].MemBlockHeader.dSize
  add ebx, sizeof(MemBlockHeader)
  MemAlloc xbx
  test xax, xax
  jz @@Error
  mov xdi, xax
  mov xcx, pMemBlockPayload
  lea xdx, [xcx - sizeof(MemBlockHeader)]
  invoke MemClone, xax, xdx, ebx
  mov xax, xdi
  mov [xdi].MemBlockHeader.dFlags, MBF_DYNAMIC or MBF_WRITABLE
@@Error:
  ret
MemBlockClone_X endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      BlockA / BlockW
; Purpose:    Construct an MemBlock structure in any segment
; Arguments:  Arg1: (optional) MemBlock flags (MBF_xxx)
;             Arg2: (optional) Minimal payload size.
;             Arg3: Symbol name.
;             Arg4: Quoted string that fills the payload.
; Return:     Symbol reference to the payload.
; Notes:      - Quotation marks can be used as usual. See example.
;             - Partial input strings can be separated by commas.
;             - Break input lines with "\".
;             - Empty input strings ("" or '') causes an error.
;             - Numeric inputs in word range are possible.
;             - sizeof and length of directives work with this macro.
; Example:    BlockA MBF_WRITEABLE, 100, MyString, "Hello World", CRLF

BlockA macro Flags:=<0>, MinAlloc:=<0>, TextReference:req, QuotedText:vararg
  align MEMBLOCK_ALIGN
  ??BlockBase = $
  ??BlockPayload = $ + sizeof(MemBlockHeader)
  org ??BlockPayload                                    ;;Move to MemBlock.Payload begin
  StringA <TextReference>, <QuotedText>                 ;;Set MemBlock.Payload = WIDE String
  org ??BlockBase
  dd Flags                                              ;;Set MemBlock.dFlags
  ??Size = ??StrSize
  ifnb <MinAlloc>                                       ;;If MinAlloc is specified
    if MinAlloc gt ??StrSize                            ;; and is bigger than ??StrSize
      ??Size = MinAlloc                                 ;; then use it
    endif
  endif
  ??Size = sizeof(MemBlockHeader) + ??Size + 2*MEMBLOCK_ALLOC_GRANULARITY - 1
  ??Size = ??Size and -MEMBLOCK_ALLOC_GRANULARITY
  dd ??Size                                             ;;Set MemBlock.dSize
  dd ??StrSize                                          ;;Set MemBlock.dUsed = Current usage
  org ??BlockPayload + ??Size                           ;;Move to the end of the MemBlock
endm

BlockW macro Flags:=<0>, MinAlloc:=<0>, TextReference:req, QuotedText:vararg
  align MEMBLOCK_ALIGN
  ??BlockBase = $
  ??BlockPayload = $ + sizeof(MemBlockHeader)
  org ??BlockPayload                                    ;;Move to MemBlock.Payload begin
  StringW <TextReference>, <QuotedText>                 ;;Set MemBlock.Payload = WIDE String
  org ??BlockBase
  dd Flags                                              ;;Set MemBlock.dFlags
  ??Size = ??StrSize
  ifnb <MinAlloc>                                       ;;If MinAlloc is specified
    if MinAlloc gt ??StrSize                            ;; and is bigger than ??StrSize
      ??Size = MinAlloc                                 ;; then use it
    endif
  endif
  dd ??Size                                             ;;Set MemBlock.dSize
  dd ??StrSize                                          ;;Set MemBlock.dUsed = Current usage
  org ??BlockPayload + ??Size                           ;;Move to the end of the MemBlock
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
  S_CONST segment
    BlockA 0, <>, <TextReference>, <QuotedText>
  S_CONST ends
endm

$OfsCBlockA macro QuotedText:vararg
  S_CONST segment
    BlockA 0, <>, <>, <QuotedText>
  S_CONST ends
  exitm <offset(??BlockPayload)>
endm


CBlockW macro TextReference:req, QuotedText:vararg
  public TextReference
  S_CONST segment
    BlockW 0, <>, <TextReference>, <QuotedText>
  S_CONST ends
endm

$OfsCBlockW macro QuotedText:vararg
  S_CONST segment
    BlockW 0, <>, <>, <QuotedText>
  S_CONST ends
  exitm <offset(??BlockPayload)>
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


DBlockA macro MinSize:req, TextReference:req, QuotedText:vararg
  public TextReference
  S_DATA segment
    BlockA MBF_WRITABLE, MinSize, <TextReference>, <QuotedText>
  S_DATA ends
endm

$OfsDBlockA macro MinSize:req, QuotedText:vararg
  S_DATA segment
    BlockA MBF_WRITABLE, MinSize, <>, <QuotedText>
  S_DATA ends
  exitm <offset(??BlockPayload)>
endm


DBlockW macro MinSize:req, TextReference:req, QuotedText:vararg
  public TextReference
  S_DATA segment
    BlockW MBF_WRITABLE, MinSize, <TextReference>, <QuotedText>
  S_DATA ends
endm

$OfsDBlockW macro MinSize:req, QuotedText:vararg
  S_DATA segment
    BlockW MBF_WRITABLE, MinSize, <>, <QuotedText>
  S_DATA ends
  exitm <offset(??BlockPayload)>
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


TBlockA macro MinSize:req, TextReference:req, QuotedText:vararg
  public TextReference
  S_TEXT segment
    BlockA MBF_WRITABLE, MinSize, <TextReference>, <QuotedText>
  S_TEXT ends
endm

$OfsTBlockA macro MinSize:req, QuotedText:vararg
  S_TEXT segment
    BlockA MBF_WRITABLE, MinSize, <>, <QuotedText>
  S_TEXT ends
  exitm <offset(??BlockPayload)>
endm


TBlockW macro MinSize:req, TextReference:req, QuotedText:vararg
  public TextReference
  S_TEXT segment
    BlockW MBF_WRITABLE, MinSize, <TextReference>, <QuotedText>
  S_TEXT ends
endm

$OfsTBlockW macro MinSize:req, QuotedText:vararg
  S_TEXT segment
    BlockW MBF_WRITABLE, MinSize, <>, <QuotedText>
  S_TEXT ends
  exitm <offset(??BlockPayload)>
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
; Macro:      $MStr
; Purpose:    Allocate an MStr on the stack.
; Arguments:  Arg1: Variable name
;             Arg2: MStr capacity in chars.
; Return:     Sentence to be used wit the local keyword.
; Example:    local $MStr(MyStr, 100)
;             ...
;             mov xcx, $MStrInit(MyStr, <Hello>)


$MStr macro TextReference:req, Chars:req
  %exitm <TextReference[sizeof(MemBlockHeader) + sizeof(CHR)*Chars]:BYTE>
endm

$MStrInit macro TextReference:req, StrValue
  ??PayloadSize = sizeof(TextReference) - sizeof(MemBlockHeader)
  lea xax, TextReference.MemBlock.bPayload
  ifnb <StrValue>
    %FillString [xax], <StrValue>
  endif
  mov TextReference.MemBlockHeader.dFlags, MBF_WRITABLE
  mov TextReference.MemBlockHeader.dSize, ??PayloadSize
  mov TextReference.MemBlockHeader.dUsed, ??StrSize
  exitm <xax>
endm
