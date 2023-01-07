; ==================================================================================================
; Title:      GetFileHashA.asm
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\\Code\\OA_Setup64.inc
% include &ObjMemPath&ObjMemWin.cop

.code
; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  GetFileHashA
; Purpose:    Compute the hash value from the content of a file.
; Arguments:  Arg1: -> Hash return value
;             Arg2: -> ANSI file name.
;             Arg3: Hash type.
; Return:     eax = 0 if succeeded.
; Links:      http://www.masm32.com/board/index.php?topic=4322.msg32297#msg32297
; Notes:      Original translation from MSDN library by Edgar Hansen
;             It requires a fully qualified path to a file to generate a hash for and a pointer
;             to a WIDE string buffer to hold the resulting hash in HEX (16 BYTEs for MDx, 20 BYTEs
;             for SHAx) and an algorithm ID, for MD5 set dHashType to GFH_MD5.
;             See ObjMem.inc GFH_xxx.

align ALIGN_CODE
GetFileHashA proc pHash:POINTER, pFileNameA:POINTER, dHashType:DWORD
  local hProv:HANDLE, hHash:HANDLE, hFile:HANDLE
  local dFileSizeHigh:DWORD, pFileBuffer:POINTER, dBytesRead:DWORD
  local dHashSize:DWORD, bHashBuffer[64]:BYTE

  ;Create a 1MB buffer to hold the file data during the hash
  ;Note that this is just a buffer for block reads and does not limit file size
  invoke VirtualAlloc, NULL, 000100000h, MEM_RESERVE or MEM_COMMIT, PAGE_READWRITE
  test rax, rax
  jz @@ErrorMemory
  mov pFileBuffer, rax

  invoke CreateFileA, pFileNameA, GENERIC_READ, FILE_SHARE_READ, NULL, \
                      OPEN_EXISTING, FILE_FLAG_SEQUENTIAL_SCAN, NULL
  test rax, rax
  js @@ErrorFile
  mov hFile, rax

  invoke GetFileSize, hFile, addr dFileSizeHigh
  cmp dFileSizeHigh, 0
  jne @F
  test rax, rax
  jz @@ErrorContext
@@:

  invoke CryptAcquireContext, addr hProv, NULL, NULL, PROV_RSA_FULL, CRYPT_VERIFYCONTEXT
  test rax, rax
  jz @@ErrorContext

  invoke CryptCreateHash, hProv, dHashType, NULL, NULL, addr hHash
  test rax, rax
  jz @@ErrorHash

@@:
  invoke ReadFile, hFile, pFileBuffer, 000100000h, addr dBytesRead, NULL
  test rax, rax
  jz @@ErrorOther
  cmp dBytesRead, 0
  je @@EndOfFile
  invoke CryptHashData, hHash, pFileBuffer, dBytesRead, NULL
  test rax, rax
  jz @@ErrorOther
  jmp @B

@@EndOfFile:
  mov dHashSize, 64
  invoke CryptGetHashParam, hHash, HP_HASHVAL, addr bHashBuffer, addr dHashSize, NULL
  test rax, rax
  jz @@ErrorOther

  invoke MemClone, pHash, addr bHashBuffer, dHashSize
  
  invoke CryptDestroyHash, hHash
  invoke CryptReleaseContext, hProv, NULL
  invoke CloseHandle, hFile
  invoke VirtualFree, pFileBuffer, NULL, MEM_RELEASE

  xor eax, eax                                        ;Return success (0)
  ret

@@ErrorOther:
  invoke CryptDestroyHash, hHash

@@ErrorHash:
  invoke CryptReleaseContext, hProv, NULL

@@ErrorContext:
  invoke CloseHandle, hFile

@@ErrorFile:
  invoke VirtualFree, pFileBuffer, NULL, MEM_RELEASE

@@ErrorMemory:
  xor eax, eax
  dec rax                                             ;Return error (-1)
  ret
GetFileHashA endp

end
