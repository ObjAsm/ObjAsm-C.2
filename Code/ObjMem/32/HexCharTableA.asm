; ==================================================================================================
; Title:      HexCharTableA.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup32.inc
% include &ObjMemPath&ObjMemWin.cop

externdef HexCharTableA:CHRA

.const
align ALIGN_DATA
HexCharTableA \
  db "000102030405060708090A0B0C0D0E0F"
  db "101112131415161718191A1B1C1D1E1F"
  db "202122232425262728292A2B2C2D2E2F"
  db "303132333435363738393A3B3C3D3E3F"
  db "404142434445464748494A4B4C4D4E4F"
  db "505152535455565758595A5B5C5D5E5F"
  db "606162636465666768696A6B6C6D6E6F"
  db "707172737475767778797A7B7C7D7E7F"
  db "808182838485868788898A8B8C8D8E8F"
  db "909192939495969798999A9B9C9D9E9F"
  db "A0A1A2A3A4A5A6A7A8A9AAABACADAEAF"
  db "B0B1B2B3B4B5B6B7B8B9BABBBCBDBEBF"
  db "C0C1C2C3C4C5C6C7C8C9CACBCCCDCECF"
  db "D0D1D2D3D4D5D6D7D8D9DADBDCDDDEDF"
  db "E0E1E2E3E4E5E6E7E8E9EAEBECEDEEEF"
  db "F0F1F2F3F4F5F6F7F8F9FAFBFCFDFEFF"
end
