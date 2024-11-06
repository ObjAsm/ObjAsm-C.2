; ==================================================================================================
; Title:      hex2dw_Table_X.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


externdef h2dw_Tbl1:BYTE
externdef h2dw_Tbl2:BYTE

.const
align ALIGN_DATA
h2dw_Tbl1 \
  db 000h,010h,020h,030h,040h,050h,060h,070h,080h,090h,000h,000h,000h,000h,000h,000h      ; 63
  db 000h,0A0h,0B0h,0C0h,0D0h,0E0h,0F0h,000h,000h,000h,000h,000h,000h,000h,000h,000h      ; 79
  db 000h,000h,000h,000h,000h,000h,000h,000h,000h,000h,000h,000h,000h,000h,000h,000h      ; 95
  db 000h,0A0h,0B0h,0C0h,0D0h,0E0h,0F0h

h2dw_Tbl2 \
  db 000h,001h,002h,003h,004h,005h,006h,007h,008h,009h,000h,000h,000h,000h,000h,000h      ; 63
  db 000h,00Ah,00Bh,00Ch,00Dh,00Eh,00Fh,000h,000h,000h,000h,000h,000h,000h,000h,000h      ; 79
  db 000h,000h,000h,000h,000h,000h,000h,000h,000h,000h,000h,000h,000h,000h,000h,000h      ; 95
  db 000h,00Ah,00Bh,00Ch,00Dh,00Eh,00Fh
