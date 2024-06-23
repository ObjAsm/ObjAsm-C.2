;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; by Biterider, 2019                                       ;
; - extension of the original macros for signed dividends  ;
;   and 64 bit dividends                                   ;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; by qWord, 2009                                           ;
; - the orginal sourcode(c) for the used algorithm can be  ;
;   obtained through AMD's Optimization Guide              ;
; - thanks go to raymond for improving the algorithm       ;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

; macros of interest:
;  +----------------+--------------------------------------+
;  | macro/param    |            description               |
;  |                |                                      |
;  +----------------+--------------------------------------+
;  | cdiv imm32     | calculate the quotient               |
;  |                | EDX = EAX / imm32                    |
;  +----------------+--------------------------------------+
;  | cmod imm32     | calculate the remainder              |
;  |                | EDX = EAX MOD imm32                  |
;  +----------------+--------------------------------------+
;  | cDivMod imm32  | calcualte the remainder and quotient |
;  |                | EDX = EAX MOD imm32                  |
;  |                | EAX = EAX / imm32                    |
;  +----------------+--------------------------------------+
;  USES: EAX EDX (applies to all macros)




;---------------------------------------------------------------;
; divides(unsigned) the content of EAX by an constant (imm32).  ;
; The division is replaced by an multiplication (or cmp/sbb/shr);
;                                                               ;
; In:   imm32   = divisor                                       ;
;       EAX     = dividend                                      ;
; Out:  EDX     = quotient                                      ;
; USES: EAX,EDX                                                 ;
;                                                by qWord, 2009 ;
;---------------------------------------------------------------;
cdiv macro imm32:req

  IF imm32 EQ 0
    .err <division by zero>
    EXITM
  ELSEIF imm32 EQ 1
    %echo WARNING: division by 1 is senseless
    EXITM
  ENDIF

  make_c32 &imm32
  IF mc32_a EQ 0
    mov edx, mc32_m
    mul edx
    IF mc32_s NE 0
      shr edx, mc32_s
    ENDIF
  ELSEIF mc32_a EQ 1
    mov edx, mc32_m
    add eax, 1
    .if !CARRY?
      mul edx
    .endif
    IF mc32_s NE 0
      shr edx, mc32_s
    ENDIF
  ELSEIF mc32_a EQ 2
    xor edx, edx
    cmp eax, imm32
    sbb edx, -1
  ELSEIF mc32_a EQ 3
    shr eax, mc32_s
    mov edx, eax
  ENDIF
endm

icdiv macro imm32:req
  test eax, eax
  .if SIGN?
    neg eax
    cdiv imm32
    neg edx
  .else
    cdiv imm32
  .endif
endm

cdiv64 macro imm32:req

  IF imm32 EQ 0
    .err <division by zero>
    EXITM
  ELSEIF imm32 EQ 1
    %echo WARNING: division by 1 is senseless
    EXITM
  ENDIF

  make_c32 &imm32
  IF mc32_a EQ 0
    mov edx, mc32_m
    mul rdx
    IF mc32_s NE 0
      shr rdx, mc32_s
    ENDIF
  ELSEIF mc32_a EQ 1
    mov edx, mc32_m
    add rax, 1
    .if !CARRY?
      mul rdx
    .endif
    IF mc32_s NE 0
      shr rdx, mc32_s
    ENDIF
  ELSEIF mc32_a EQ 2
    xor edx, edx
    cmp rax, imm32
    sbb rdx, -1
  ELSEIF mc32_a EQ 3
    shr rax, mc32_s
    mov rdx, rax
  ENDIF
endm

icdiv64 macro imm32:req
  test rax, rax
  .if SIGN?
    neg rax
    cdiv64 imm32
    neg rdx
  .else
    cdiv64 imm32
  .endif
endm

;---------------------------------------------------------------;
; calculate the modulo of division by a constant                ;
;                                                               ;
; In:   imm32   = divisor                                       ;
;       EAX     = dividend                                      ;
; Out:  EDX     = remainder (modulo)                            ;
; USES: EAX,EDX                                                 ;
;                                                by qWord, 2009 ;
;---------------------------------------------------------------;
cmod macro imm32:req

  IF imm32 EQ 0
    .err <division by zero>
    EXITM
  ELSEIF imm32 EQ 1
    %echo WARNING: division by 1 is senseless
    EXITM
  ENDIF

  make_c32 &imm32
  IF mc32_a EQ 0
    mov edx, mc32_m
    mul edx
    IF mc32_s NE 0
      shrd eax, edx, mc32_s
    ENDIF
    inc eax
    mov edx, imm32
    mul edx

  ELSEIF mc32_a EQ 1
    mov edx, mc32_m
    add eax, 1
    .if !CARRY?
      mul edx
    .endif
    IF mc32_s NE 0
      shrd eax, edx, mc32_s
    ENDIF
    inc eax
    mov edx, imm32
    mul edx
  ELSEIF mc32_a EQ 2
    mov edx, eax
    xor eax, eax
    cmp edx, imm32
    sbb eax, -1
    .if !ZERO?
      sub edx, imm32
    .endif
  ELSEIF mc32_a EQ 3
    and eax, NOT(0ffffffffh SHL mc32_s)
    mov edx, eax
  ENDIF
endm

icmod macro imm32:req
  test eax, eax
  .if SIGN?
    neg eax
    cmod imm32
    neg edx
  .else
    cmod imm32
  .endif
endm

cmod64 macro imm32:req

  IF imm32 EQ 0
    .err <division by zero>
    EXITM
  ELSEIF imm32 EQ 1
    %echo WARNING: division by 1 is senseless
    EXITM
  ENDIF

  make_c32 &imm32
  IF mc32_a EQ 0
    mov edx, mc32_m
    mul rdx
    IF mc32_s NE 0
      shrd rax, rdx, mc32_s
    ENDIF
    inc rax
    mov edx, imm32
    mul rdx

  ELSEIF mc32_a EQ 1
    mov edx, mc32_m
    add rax, 1
    .if !CARRY?
      mul rdx
    .endif
    IF mc32_s NE 0
      shrd rax, rdx, mc32_s
    ENDIF
    inc rax
    mov edx, imm32
    mul rdx
  ELSEIF mc32_a EQ 2
    mov rdx, rax
    xor eax, eax
    cmp rdx, imm32
    sbb rax, -1
    .if !ZERO?
      sub rdx, imm32
    .endif
  ELSEIF mc32_a EQ 3
    and rax, NOT(0ffffffffffffffffh SHL mc32_s)
    mov rdx, rax
  ENDIF
endm

icmod64 macro imm32:req
  test rax, rax
  .if SIGN?
    neg rax
    cmod64 imm32
    neg rdx
  .else
    cmod64 imm32
  .endif
endm

;---------------------------------------------------------------;
; calculate the quotient and remainder of division by a         ;
; constant.                                                     ;
;                                                               ;
; In:   imm32   = divisor                                       ;
;       EAX     = dividend                                      ;
; Out:  EAX     = quotient                                      ;
;       EDX     = remainder                                     ;
; USES: EAX,EDX                                                 ;
;                                                by qWord, 2009 ;
;---------------------------------------------------------------;
cDivMod macro imm32:req

  IF imm32 EQ 0
    .err <division by zero>
    EXITM
  ELSEIF imm32 EQ 1
    %echo WARNING: division by 1 is senseless
    EXITM
  ENDIF

  make_c32 &imm32
  IF mc32_a EQ 0
    mov edx, mc32_m
    mul edx
    IF mc32_s NE 0
      shrd eax, edx, mc32_s
    ENDIF
    inc eax
    push xdx
    mov edx, imm32
    mul edx
    pop xax
    IF mc32_s NE 0
      shr eax, mc32_s
    ENDIF
  ELSEIF mc32_a EQ 1
    mov edx, mc32_m
    add eax, 1
    .if !CARRY?
      mul edx
    .endif
    IF mc32_s NE 0
      shrd eax, edx, mc32_s
    ENDIF
    inc eax
    push xdx
    mov edx, imm32
    mul edx
    pop xax
    IF mc32_s NE 0
      shr eax,mc32_s
    ENDIF
  ELSEIF mc32_a EQ 2
    mov edx, eax
    xor eax, eax
    cmp edx, imm32
    sbb eax, -1
    .if !ZERO?
      sub edx, imm32
    .endif
  ELSEIF mc32_a EQ 3
    mov edx, eax
    shr eax, mc32_s
    and edx, NOT(0ffffffffh SHL mc32_s)
  ENDIF
endm

icDivMod macro imm32:req
  test eax, eax
  .if SIGN?
    neg eax
    cDivMod imm32
    neg edx
    neg eax
  .else
    cDivMod imm32
  .endif
endm

cDivMod64 macro imm32:req

  IF imm32 EQ 0
    .err <division by zero>
    EXITM
  ELSEIF imm32 EQ 1
    %echo WARNING: division by 1 is senseless
    EXITM
  ENDIF

  make_c32 &imm32
  IF mc32_a EQ 0
    mov edx, mc32_m
    mul rdx
    IF mc32_s NE 0
      shrd rax, rdx, mc32_s
    ENDIF
    inc rax
    push rdx
    mov rdx, imm32
    mul rdx
    pop rax
    IF mc32_s NE 0
      shr rax, mc32_s
    ENDIF
  ELSEIF mc32_a EQ 1
    mov edx, mc32_m
    add rax, 1
    .if !CARRY?
      mul rdx
    .endif
    IF mc32_s NE 0
      shrd rax, rdx, mc32_s
    ENDIF
    inc rax
    push rdx
    mov edx, imm32
    mul rdx
    pop rax
    IF mc32_s NE 0
      shr rax, mc32_s
    ENDIF
  ELSEIF mc32_a EQ 2
    mov rdx, rax
    xor eax, eax
    cmp rdx, imm32
    sbb rax, -1
    .if !ZERO?
      sub rdx, imm32
    .endif
  ELSEIF mc32_a EQ 3
    mov rdx, rax
    shr rax, mc32_s
    and rdx, NOT(0ffffffffffffffffh SHL mc32_s)
  ENDIF
endm

icDivMod64 macro imm32:req
  test rax, rax
  .if SIGN?
    neg rax
    cDivMod64 imm32
    neg rdx
    neg rax
  .else
    cDivMod64 imm32
  .endif
endm

;-------------------------------------------------------------;
; determinate the multiplier, shift-count and type of         ;
; algorithm needed for replacing an division (unsigned,32bit) ;
; by multiplication with an constant value                    ;
;                                                             ;
; In:   num      = unsigned 32bit number                      ;
; Out:  mc32_a   = type of algo.: 0,1,2 or 3                  ;
;       mc32_m   = multiplier                                 ;
;       mc32_s   = number of bits to shift after mul.         ;
;                                                             ;
;                                              by qWord, 2009 ;
;-------------------------------------------------------------;
make_c32 macro num

  ;Out:
  mc32_error  = 0
  mc32_err_txt TEXTEQU <>
  mc32_a    = 0
  mc32_s    = 0
  mc32_m    = 0

  IF (num EQ 0) OR (num EQ 1)
    mc32_error = 1
    mc32_err_txt TEXTEQU <senseless or invalid divider>
    EXITM
  ENDIF

  IF num GE 080000000h
    mc32_a = 2
    mc32_m = num
    EXITM
  ENDIF

  mc32_log2   = @BSR_DWORD(num)
  mc32_n      = @BSF_DWORD(num)
  mc32_lg2_t  = mc32_log2 - mc32_n

  IF mc32_lg2_t EQ 0
    mc32_a = 3
    mc32_s = mc32_log2
    mc32_m = 0
    EXITM
  ENDIF

  mc32_t    = _SHR(&num,%mc32_n)
  mc32_pwrL = 1 SHL mc32_lg2_t
  mc32_L    = mc32_lg2_t + 1
  mc32_pwrH = mc32_pwrL*2
  mc32_j    = 0ffffffffh MOD mc32_t

  div_u64 0,%mc32_pwrH,%((-1)-mc32_j),0
  mc32_k = du64_quotient_lo

  div_u64 %mc32_k,%(mc32_pwrH-mc32_t),%mc32_t,0
  mc32_m_high  = _SHR(%du64_quotient_lo,1) OR 080000000h

  div_u64 0,%mc32_pwrH-mc32_t,%mc32_t,0
  mc32_m_low  = _SHR(%du64_quotient_lo,1) OR 080000000h

  IF mc32_m_high NE mc32_m_low
    mc32_a     = 0
    mc32_L     = mc32_L - 1
    mc32_tmp   = @BSR_DWORD(%(mc32_m_high XOR mc32_m_low))
    mc32_m     = _SHR(mc32_m_high,%mc32_tmp)
    mc32_L     = mc32_L - mc32_tmp
  ELSE
    mc32_a     = 1
    mc32_L     = mc32_L - 1

    div_u64 0,%mc32_pwrL,%mc32_t,0
    mc32_m_low = du64_quotient_lo
    mc32_r     = du64_remainder_lo

    IF  (mc32_r AND 0ffffffffh) GT (_SHR(%mc32_t,1))
      mc32_m_low = mc32_m_low + 1
    ENDIF
    mc32_m = mc32_m_low
  ENDIF

  mc32_s = mc32_n + mc32_L

  EXITM

endm

@BSR_DWORD macro number:req
  bsrd_txt   TEXTEQU <>
  bsrd_num  = number
  pushcontext radix
    .radix 2
    bsrd_txt TEXTEQU %(bsrd_num)
  popcontext radix
  IF number NE 0
    EXITM @CatStr(%(@SizeStr(%bsrd_txt)-1))
  ELSE
    EXITM <0>
  ENDIF
endm

@BSF_DWORD macro number:req

  bsfd_value  = number
  bsfd_index  = 0
  bsfd_txt  TEXTEQU <>
  bsfd_pos    = 0
  bsfd_size   = 0

  IF number EQ 0
    EXITM <0>
  ENDIF

  pushcontext radix
    .radix 2
    bsfd_txt TEXTEQU %(bsfd_value)
  popcontext radix

  bsfd_size SIZESTR bsfd_txt
  bsfd_pos   = bsfd_size

  REPEAT bsfd_size
    IFIDN <1>,@SubStr(%bsfd_txt,%bsfd_pos,1)
      EXITM
    ENDIF
    bsfd_pos = bsfd_pos - 1
    bsfd_index = bsfd_index + 1
  ENDM
  EXITM @CatStr(%(bsfd_index))
endm

@BSR_QWORD macro loDword:req,hiDword:req
  IF (loDword EQ 0) AND (hiDword EQ 0)
    EXITM <0>
  ENDIF

  IF hiDword EQ 0
    EXITM @BSR_DWORD(loDword)
  ELSE
    EXITM @CatStr(%(@BSR_DWORD(hiDword)+32t))
  ENDIF
endm

;bugfix for masm v8,9 and 10: SHR is interpreted as SAR
_SHR macro value,nBits
  IF nBits GT 31t
    EXITM <0>
  ELSEIF nBits EQ 0
    EXITM <&value>
  ENDIF

  IF value AND 080000000h
    EXITM @CatStr(%(((value) AND 7fffffffh) SHR nBits) OR (1 SHL (31t-nBits)))
  ELSE
    EXITM @CatStr(%((value) SHR nBits))
  ENDIF
endm

IFNDEF __JWASM__
sub_u64 macro eqLoDest:req,eqHiDest:req,LoSrc:req,HiSrc:req

  IFNDEF eqLoDest
    %echo error: _macro-var expected
    EXITM
  ELSEIFNDEF eqHiDest
    %echo _macro-var expected
    EXITM
  ENDIF

  IF (eqLoDest AND 0ffffffffh) GE (LoSrc AND 0ffffffffh)
    eqLoDest = (eqLoDest - LoSrc)
    eqHiDest = (eqHiDest - HiSrc)
  ELSE
    eqLoDest = (eqLoDest - LoSrc)
    eqHiDest = (eqHiDest - HiSrc - 1)
  ENDIF
  EXITM
endm
ELSE
sub_u64 macro eqLoDest:req,eqHiDest:req,LoSrc:req,HiSrc:req

  IFNDEF eqLoDest
    %echo error: _macro-var expected
    EXITM
  ELSEIFNDEF eqHiDest
    %echo _macro-var expected
    EXITM
  ENDIF

  IF  LOW32 eqLoDest GE LOW32 LoSrc
    eqLoDest = LOW32 (eqLoDest - LoSrc)
    eqHiDest = LOW32 (eqHiDest - HiSrc)
  ELSE
    eqLoDest = LOW32 (eqLoDest - LoSrc)
    eqHiDest = LOW32 (eqHiDest - HiSrc - 1)
  ENDIF
  EXITM
endm
ENDIF

;---------------------------------------------------------------------------;
; divide two unsigned QWORD's                                               ;
; In:   HighDividend::LowDividend            = divident                     ;
;       HighDivisor::LowDivisor              = divisor                      ;
; Out:  du64_quotient_hi::du64_quotient_lo   = qoutient                     ;
;       du64_remainder_hi::du64_remainder_lo = remainder                    ;
;                                                             by qWord 2009 ;
;---------------------------------------------------------------------------;
IFNDEF __JWASM__
div_u64 macro LowDividend:req,HighDividend:req,LowDivisor:req,HighDivisor:req

  ;OUT:
  du64_remainder_lo = LowDividend
  du64_remainder_hi = HighDividend
  du64_quotient_lo  = 0
  du64_quotient_hi  = 0

  ;internal:
  du64_divisor_lo   = LowDivisor
  du64_divisor_hi   = HighDivisor
  du64_dividend_lo  = LowDividend
  du64_dividend_hi  = HighDividend

  IF (LowDivisor EQ 0) AND (HighDivisor EQ 0)
    %echo ERR: div_u64: division by zero!!
    EXITM
  ENDIF

  du64_count = @BSR_QWORD(LowDividend,HighDividend)-@BSR_QWORD(LowDivisor,HighDivisor)
  pushcontext radix
  .radix 10
  IF du64_count GT 0
    IF du64_count LE 31t
      du64_bits    = _SHR(%du64_divisor_lo,%(32t-du64_count))
      du64_divisor_lo = du64_divisor_lo SHL du64_count
      du64_divisor_hi = (du64_divisor_hi SHL du64_count) OR du64_bits
    ELSE
      du64_divisor_hi = du64_divisor_lo SHL (du64_count-32t)
      du64_divisor_lo = 0
    ENDIF
  ENDIF

  WHILE du64_count GE 0
    IF (du64_dividend_hi NE 0) OR (du64_divisor_hi NE 0)
      IF (du64_dividend_hi AND 0ffffffffh) LT (du64_divisor_hi AND 0ffffffffh)
        goto skip
      ELSEIF (du64_dividend_hi AND 0ffffffffh) EQ (du64_divisor_hi AND 0ffffffffh)
        IF (du64_dividend_lo AND 0ffffffffh) LT (du64_divisor_lo AND 0ffffffffh)
          goto skip
        ENDIF
      ENDIF
    ELSE
      IF (du64_dividend_lo AND 0ffffffffh) LT (du64_divisor_lo AND 0ffffffffh)
        goto skip
      ENDIF
    ENDIF
    sub_u64 <du64_dividend_lo>,<du64_dividend_hi>,du64_divisor_lo,du64_divisor_hi
    IF du64_count LE 31t
      du64_quotient_lo = du64_quotient_lo OR (1 SHL du64_count)
    ELSE
      du64_quotient_hi = du64_quotient_hi OR (1 SHL (du64_count-32t))
    ENDIF
    :skip
    du64_divisor_lo = _SHR(%du64_divisor_lo,1) OR (((du64_divisor_hi AND 1) NE 0) AND 080000000h)
    du64_divisor_hi = _SHR(%du64_divisor_hi,1)
    du64_count = du64_count - 1
  ENDM
  popcontext radix
  du64_remainder_lo  = du64_dividend_lo
  du64_remainder_hi  = du64_dividend_hi
  EXITM
endm
ELSE
div_u64 macro LowDividend:req,HighDividend:req,LowDivisor:req,HighDivisor:req

  ;OUT:
  du64_remainder_lo = LOW32 LowDividend
  du64_remainder_hi = LOW32 HighDividend
  du64_quotient_lo  = 0
  du64_quotient_hi  = 0

  ;internal:
  du64_divisor_lo   = LOW32 LowDivisor
  du64_divisor_hi   = LOW32 HighDivisor
  du64_dividend_lo  = LOW32 LowDividend
  du64_dividend_hi  = LOW32 HighDividend

  IF (LowDivisor EQ 0) AND (HighDivisor EQ 0)
    %echo ERR: div_u64: division by zero!!
    EXITM
  ENDIF

  du64_count = @BSR_QWORD(LOW32 LowDividend,LOW32 HighDividend)-@BSR_QWORD(LOW32 LowDivisor,LOW32 HighDivisor)
  pushcontext radix
  .radix 10
  IF du64_count GT 0
    IF du64_count LE 31t
      du64_bits       = _SHR(%LOW32 du64_divisor_lo,%(32t-du64_count))
      du64_divisor_lo = LOW32 (LOW32 du64_divisor_lo SHL du64_count)
      du64_divisor_hi = LOW32 ((LOW32 du64_divisor_hi SHL du64_count) OR LOW32 du64_bits)
    ELSE
      du64_divisor_hi = LOW32 (LOW32 du64_divisor_lo SHL (du64_count-32t))
      du64_divisor_lo = 0
    ENDIF
  ENDIF

  WHILE du64_count GE 0
    IF (du64_dividend_hi NE 0) OR (du64_divisor_hi NE 0)
      IF LOW32 du64_dividend_hi LT LOW32 du64_divisor_hi
        goto skip
      ELSEIF  LOW32 du64_dividend_hi EQ LOW32 du64_divisor_hi
        IF LOW32 du64_dividend_lo LT LOW32 du64_divisor_lo
          goto skip
        ENDIF
      ENDIF
    ELSE
      IF LOW32 du64_dividend_lo LT LOW32 du64_divisor_lo
        goto skip
      ENDIF
    ENDIF
    sub_u64 <du64_dividend_lo>,<du64_dividend_hi>,%LOW32 du64_divisor_lo,%LOW32 du64_divisor_hi
    IF du64_count LE 31t
      du64_quotient_lo = LOW32 (LOW32 du64_quotient_lo OR (1 SHL du64_count))
    ELSE
      du64_quotient_hi = LOW32 (LOW32 du64_quotient_hi OR (1 SHL (du64_count-32t)))
    ENDIF
    :skip
    du64_divisor_lo = LOW32 _SHR(%LOW32 du64_divisor_lo,1) OR ((((LOW32 du64_divisor_hi) AND 1) NE 0) AND 080000000h)
    du64_divisor_hi = LOW32 _SHR(%LOW32 du64_divisor_hi,1)
    du64_count = du64_count - 1
  ENDM
  popcontext radix
  du64_remainder_lo = LOW32 du64_dividend_lo
  du64_remainder_hi = LOW32 du64_dividend_hi
  EXITM
endm
ENDIF
