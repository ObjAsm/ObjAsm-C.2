; ==================================================================================================
; Title:      GetFileLines_AX.inc
; Author:     G. Friedrich
; Version:    C.1.1
; Notes:      Version C.1.1, December 2020
;               - Completely reworked and 64 bit version added.
;             Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


GFL_BUFFER_SIZE       equ 512*8                           ;Must be a multiple of 512 (8 sectors)
GFL_LIST_SIZE_INIT    equ PAGESIZE                        ;Must be a multiple of sizeof(DWORD)
GFL_LIST_SIZE_GROW    equ PAGESIZE                        ;Must be a multiple of sizeof(DWORD)
if TARGET_BITNESS eq 32
  GFL_CR_MASK         equ 0D0D0D0Dh
else
  GFL_CR_MASK         equ 0D0D0D0D0D0D0D0Dh
endif


; --------------------------------------------------------------------------------------------------
; Procedure:  GetFileLinesA
; Purpose:    Return an array of line ending offsets of an ANSI text file.
; Arguments:  Arg1: File HANDLE.
; Return:     eax = Number of lines.
;             rcx -> Mem block containing an array of DWORD offsets.
;                    The user must dispose it using MemFree.
;
; Notes:     - Lines must be terminated with the ANSI char sequence 13, 10 (CRLF).
;            - The last line may not terminate with a CRLF.

.code
align ALIGN_CODE
GetFileLinesA proc uses xbx xdi xsi hFile:HANDLE
  local pListBeg:POINTER, pListEnd:POINTER, dListSize:DWORD
  local pBufferBeg:POINTER, pBufferEnd:POINTER
  local dFileOffset:DWORD, dLineEnd:DWORD, dBytesRead:DWORD

  .const
  if TARGET_BITNESS eq 32
  GFL_MASK_TABLE \
    DWORD 0000000FFh
    DWORD 00000FFFFh
    DWORD 000FFFFFFh
  GFL_JUMP_TABLE POINTER @@1, @@2, @@3, @@F
  else
  GFL_MASK_TABLE \
    QWORD 000000000000000FFh
    QWORD 0000000000000FFFFh
    QWORD 00000000000FFFFFFh
    QWORD 000000000FFFFFFFFh
    QWORD 0000000FFFFFFFFFFh
    QWORD 00000FFFFFFFFFFFFh
    QWORD 000FFFFFFFFFFFFFFh
  GFL_JUMP_TABLE POINTER @@1, @@2, @@3, @@4, @@5, @@6, @@7, @@F
  endif

  .code
  ;Ensure all requirements are met
  .if hFile != INVALID_HANDLE_VALUE
    mov dListSize, GFL_LIST_SIZE_INIT
    MemAlloc dListSize                                  ;Create the destination list
    .if xax != NULL
      mov pListBeg, xax
      mov xdi, xax
      mov ecx, dListSize
      add xax, xcx
      mov pListEnd, xax

      MemAlloc GFL_BUFFER_SIZE
      .if xax != NULL
        mov pBufferBeg, xax
        mov dFileOffset, 0
        mov dLineEnd, 0
        mov dBytesRead, 0

@@Loop:
        .repeat
          ;Read a data chunk
          invoke ReadFile, hFile, pBufferBeg, GFL_BUFFER_SIZE, addr dBytesRead, NULL
          .break .if dBytesRead == 0

          ;Compute aligned address of the last QWORD
          mov xsi, pBufferBeg
          mov xcx, xsi
          mov eax, dBytesRead
          add xcx, xax
          mov pBufferEnd, xcx
          dec xcx                                       ;xcx -> last BYTE
          and xcx, -sizeof(QWORD)                       ;Alignment

          ;Fill last QWORD with zeros as needed
          and eax, $Log2(sizeof(QWORD))
          .if !ZERO?
            ;Read mask and apply it mask to the last DWORD
            if TARGET_BITNESS eq 32
              mov edx, [GFL_MASK_TABLE + sizeof(DWORD)*eax - sizeof(DWORD)]
            else
              lea r8, GFL_MASK_TABLE
              mov rdx, [r8 + sizeof(QWORD)*rax - sizeof(QWORD)]
              and [rcx], rdx
            endif
          .endif

          ;Analize the data, searching for the char 13
          .while xsi < pBufferEnd
            mov xbx, [xsi]                              ;Aligned memory read
            mov xdx, GFL_CR_MASK
            xor xbx, xdx                                ;Puts a zero where the CR was found

            test ebx, 0000000FFh
            jz @@Found
@@1:
            inc xsi
            test ebx, 00000FF00h
            jz @@Found
@@2:
            inc xsi
            test ebx, 000FF0000h
            jz @@Found
@@3:
            inc xsi
            test ebx, 0FF000000h
          if TARGET_BITNESS eq 32
            jnz @@F
          else
            jz @@Found
@@4:
            shr rbx, 32
            inc rsi
            test ebx, 0000000FFh
            jz @@Found
@@5:
            inc rsi
            test ebx, 00000FF00h
            jz @@Found
@@6:
            inc rsi
            test ebx, 000FF0000h
            jz @@Found
@@7:
            inc rsi
            test ebx, 0FF000000h
            jnz @@F
          endif

@@Found:
            ;Compute the line end
            mov ecx, dFileOffset
            lea xax, [xsi + xcx + 2]                    ;+2 = CRLF
            sub xax, pBufferBeg
            stosd                                       ;Store it in the list

            ;Check if more memory is needed
            .if xdi >= pListEnd
              ;Extend the list by the factor GFL_LIST_SIZE_GROW
              add dListSize, GFL_LIST_SIZE_GROW
              MemReAlloc pListBeg, dListSize
              .if xax != pListBeg                       ;Not in place?
                .if xax != NULL
                  ;Operation succeeded but not in place => update internal values
                  sub xdi, pListBeg                     ;Calc the current offset in the list
                  mov pListBeg, xax
                  add xdi, xax                          ;Calc new offset position = xdi
                  mov ecx, dListSize
                  add xax, xcx
                  mov pListEnd, xax
                .else
                  ;Operation failed => release allocated resources and exit
                  MemFree pListBeg
                  MemFree pBufferBeg
                  xor eax, eax
                  ret
                .endif
              .endif
            .endif

            ;Continue with the next character in rbx
            mov xcx, xsi
            and ecx, sizeof(XWORD) - 1
            if TARGET_BITNESS eq 32
              jmp POINTER ptr [GFL_JUMP_TABLE + sizeof(POINTER)*ecx]
            else
              mov r8, offset GFL_JUMP_TABLE
              jmp POINTER ptr [r8 + sizeof(POINTER)*rcx]
            endif
@@F:
            inc xsi
          .endw
          mov eax, dBytesRead
          add dFileOffset, eax
        .until FALSE

        ;Check if we have and additional line at the end that doesn't end with CRLF
        mov xsi, pBufferEnd
        mov al, [xsi - 1]                               ;Get last CHRA from buffer
        .if al != 10                                    ;Skip if LF
          mov eax, dFileOffset
          stosd                                         ;Store it in the list
        .endif

        MemFree pBufferBeg

        ;Calc the number of entries in the list
        mov xax, xdi
        sub xax, pListBeg
        shr eax, $Log2(sizeof(DWORD))                   ;eax = # of entries
        mov xcx, pListBeg                               ;xcx -> List
      .else
        MemFree pListBeg
        xor eax, eax
        xor ecx, ecx
      .endif
    .endif
  .else
    xor eax, eax
    xor ecx, ecx
  .endif
  ret
GetFileLinesA endp
