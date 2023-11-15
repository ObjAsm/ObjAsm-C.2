; ==================================================================================================
; Title:      DbgOutMem_XP.inc
; Author:     G. Friedrich
; Version:    C.1.1
; Notes:      Version C.1.0, October 2017
;               - First release.
;             Version C.1.1 June 2022
;               - Bitness and Platform independent code.
;               - UEFI adaptation and addition of UI64, I64, H64.
; ==================================================================================================


externdef DbgColorError:DWORD

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  DbgOutMem / DbgOutMem_UEFI
; Purpose:    Output the content of a memory block.
; Arguments:  Arg1: -> Memory block.
;             Arg2: Memory block size.
;             Arg3: Representation format.
;             Arg4: Memory output RGB color value.
;             Arg5: Representation output RGB color value.
;             Arg5: Background RGB color value.
;             Arg6: -> Destination Window WIDE name.
; Return:     Nothing.

align ALIGN_CODE
ProcName proc uses xbx xdi xsi, pStart:POINTER, dSize:DWORD, dRepresentationFormat:DWORD, \
                                dMemColor:DWORD, dRepColor:DWORD, dBackColor:DWORD, pDest:POINTER
  local bOutBuffer[1024]:CHRA, bAuxBuffer[128]:CHRA, dHeaderCount:DWORD
  local .xsi:XWORD, .xbx:XWORD, .ecx:DWORD

  mov xsi, pStart
  .if xsi == NULL
    invoke DbgOutTextA, $OfsCStrA("NULL pointer"), DbgColorError, dBackColor, DBG_EFFECT_NEWLINE, pDest
    ret
  .endif
  mov ebx, dSize
  .if ebx == NULL
    invoke DbgOutTextA, $OfsCStrA("Zero size"), DbgColorError, dBackColor, DBG_EFFECT_NEWLINE, pDest
    ret
  .endif
  mov dHeaderCount, BYTES_PER_LINE
  .if ebx < BYTES_PER_LINE
    mov dHeaderCount, ebx
  .endif

  .while SDWORD ptr ebx > 0
    lea xdi, bOutBuffer
    invoke xword2hexA, xdi, xsi
    add xdi, sizeof(XWORD)*2
    mov WORD ptr [xdi],  " :"
    add xdi, 2
    mov .xsi, xsi
    mov .xbx, xbx

    ;Dump hex values:
    xor ecx, ecx
    .while ecx < dHeaderCount
      .if ecx != 0
        .ifBitClr ecx, BIT01 or BIT00                ;Divisible by 4
          .if ebx == 0
            mov WORD ptr [xdi], "  "
          .else
            mov WORD ptr [xdi], " |"
          .endif
          add xdi, 2
        .endif
      .endif

      .if ebx == 0
        mov DWORD ptr [xdi], "    "
      .else
        dec ebx
        xor eax, eax
        mov al, [xsi]
        inc xsi
        ror ax, 4
        shr ah, 4
        add ax, 3030h
        cmp ah, 39h
        jbe @F
        add ah, 'A' - 3Ah
@@:
        cmp al, 39h
        jbe @F
        add al, 'A' - 3Ah
@@:
        mov WORD ptr [xdi], ax
        mov WORD ptr [xdi + 2], " h"
      .endif
      add xdi, 4
      inc ecx
    .endw
    mov xbx, .xbx
    mov xsi, .xsi

    m2z BYTE ptr [xdi]
    invoke DbgOutTextA, addr bOutBuffer, dMemColor, dBackColor, DBG_EFFECT_NORMAL, pDest
    lea xdi, bOutBuffer

    .if dRepresentationFormat == DBG_MEM_NONE
      .if ebx > BYTES_PER_LINE
        sub ebx, BYTES_PER_LINE
        add xsi, BYTES_PER_LINE
      .else
        xor ebx, ebx
      .endif
      m2z BYTE ptr [xdi]
      invoke DbgOutTextA, xdi, dRepColor, dBackColor, DBG_EFFECT_NEWLINE, pDest

    .elseif dRepresentationFormat == DBG_MEM_STRA
      mov DWORD ptr [xdi], " A: "
      add xdi, 4

      xor ecx, ecx
      .while ecx < BYTES_PER_LINE
        .if ebx > 0
          mov al, [xsi]
          dec ebx
          inc xsi
          .if (al < ' ') || (al > 127)      ;Not printable
            mov al, '.'
          .endif
          mov [xdi], al
          inc xdi
        .endif
        inc ecx
      .endw
      m2z BYTE ptr [xdi]
      invoke DbgOutTextA, addr bOutBuffer, dRepColor, dBackColor, DBG_EFFECT_NEWLINE, pDest

    .elseif dRepresentationFormat == DBG_MEM_STRW
      mov DWORD ptr [xdi], 65536*':' + ' '
      mov DWORD ptr [xdi + 4], 65536*' ' + 'W'
      add xdi, 8

      xor ecx, ecx
      .while ecx < BYTES_PER_LINE/2 && ebx != 0
        .if ebx >= sizeof(WORD)
          mov ax, [xsi]
          sub ebx, sizeof(WORD)
          add xsi, sizeof(WORD)
          .if ax < ' '                      ;Not printable
            mov ax, '.'
          .endif
          mov [xdi], ax
          add xdi, sizeof(WORD)
          inc ecx
        .else
          mov WORD ptr [xdi], '?'
          add xdi, sizeof(WORD)
          xor ebx, ebx
          .break
        .endif
      .endw
      m2z WORD ptr [xdi]
      invoke DbgOutTextW, addr bOutBuffer, dRepColor, dBackColor, DBG_EFFECT_NEWLINE, pDest

    .elseif dRepresentationFormat == DBG_MEM_UI8
      mov DWORD ptr [xdi], " U: "
      add xdi, 4

      xor ecx, ecx
      .while ecx < BYTES_PER_LINE
        .if ebx > 0
          movzx edx, BYTE ptr [xsi]
          dec ebx
          inc xsi
          mov .ecx, ecx
          FillWordA [bAuxBuffer], <00>
          invoke udword2decA, addr [bAuxBuffer + 2], edx
          invoke StrEndA, addr [bAuxBuffer + 2]
          mov BYTE ptr [xax], ' '
          m2m DWORD ptr [xdi], [xax - 3], ecx
          mov ecx, .ecx
          add xdi, 4

          mov eax, ecx
          inc ecx
          and eax, 3
          .if (eax == 3) && (ebx != 0) && (ecx != BYTES_PER_LINE)
            mov WORD ptr [xdi], " |"
            add xdi, sizeof(WORD)
          .endif
        .else
          .break
        .endif
      .endw
      m2z BYTE ptr [xdi]
      invoke DbgOutTextA, addr bOutBuffer, dRepColor, dBackColor, DBG_EFFECT_NEWLINE, pDest

    .elseif dRepresentationFormat == DBG_MEM_UI16
      mov DWORD ptr [xdi], " U: "
      add xdi, 4

      xor ecx, ecx
      .while ecx < BYTES_PER_LINE/sizeof(WORD) && ebx != 0
        .if ebx >= sizeof(WORD)
          movzx edx, WORD ptr [xsi]
          sub ebx, sizeof(WORD)
          add xsi, sizeof(WORD)

          mov .ecx, ecx
          FillWordA [bAuxBuffer], <0000>
          invoke udword2decA, addr [bAuxBuffer + 4], edx
          invoke StrEndA, addr [bAuxBuffer + 4]
          mov BYTE ptr [xax], ' '
          m2m DWORD ptr [xdi], [xax - 5], ecx
          m2m WORD ptr [xdi + 4], [xax - 5 + 4], edx
          mov ecx, .ecx
          add xdi, 6

          mov eax, ecx
          inc ecx
          and eax, 1
          .if (eax == 1) && (ebx != 0) && (ecx != BYTES_PER_LINE/sizeof(WORD))
            mov WORD ptr [xdi], " |"
            add xdi, sizeof(WORD)
          .endif
        .else
          mov BYTE ptr [xdi], '?'
          inc xdi
          xor ebx, ebx
          .break
        .endif
      .endw
      m2z BYTE ptr [xdi]
      invoke DbgOutTextA, addr bOutBuffer, dRepColor, dBackColor, DBG_EFFECT_NEWLINE, pDest

    .elseif dRepresentationFormat == DBG_MEM_UI32
      mov DWORD ptr [xdi], " U: "
      add xdi, 4

      xor ecx, ecx
      .while ecx < BYTES_PER_LINE/sizeof(DWORD) && ebx != 0
        .if ebx >= sizeof(DWORD)
          mov edx, [xsi]
          sub ebx, sizeof(DWORD)
          add xsi, sizeof(DWORD)

          mov .ecx, ecx
          FillWordA [bAuxBuffer], <0000000000>
          invoke udword2decA, addr [bAuxBuffer + 10], edx
          invoke StrEndA, addr [bAuxBuffer + 10]
          mov BYTE ptr [xax], ' '
          m2m DWORD ptr [xdi], [xax - 10], edx
          m2m DWORD ptr [xdi + 4], [xax - 10 + 4], ecx
          m2m WORD ptr [xdi + 8], [xax - 10 + 8], edx
          m2m BYTE ptr [xdi + 10], [xax - 10 + 10], edx
          mov ecx, .ecx
          add xdi, 11

          inc ecx
          .if (ebx != 0) && (ecx != BYTES_PER_LINE/sizeof(DWORD))
            mov WORD ptr [xdi], " |"
            add xdi, sizeof(WORD)
          .endif
        .else
          mov BYTE ptr [xdi], '?'
          inc xdi
          xor ebx, ebx
          .break
        .endif
      .endw
      m2z BYTE ptr [xdi]
      invoke DbgOutTextA, addr bOutBuffer, dRepColor, dBackColor, DBG_EFFECT_NEWLINE, pDest

    .elseif dRepresentationFormat == DBG_MEM_I8
      mov DWORD ptr [xdi], " S: "
      add xdi, 4

      xor ecx, ecx
      .while ecx < BYTES_PER_LINE && ebx != 0
        .if ebx > 0
          mov al, [xsi]
          dec ebx
          inc xsi
          mov .ecx, ecx
          FillWordA [bAuxBuffer], <00>
          .ifBitSet al, BIT07
            neg al
            movzx edx, al
            invoke sdword2decA, addr [bAuxBuffer + 2], edx
            mov BYTE ptr [xdi], '-'
          .else
            movzx edx, al
            invoke sdword2decA, addr [bAuxBuffer + 2], edx
            mov BYTE ptr [xdi], '+'
          .endif
          invoke StrEndA, addr [bAuxBuffer + 2]
          mov BYTE ptr [xax], ' '
          m2m DWORD ptr [xdi + 1], [xax - 3], edx
          mov ecx, .ecx
          add xdi, 5

          mov eax, ecx
          inc ecx
          and eax, 3
          .if (eax == 3) && (ebx != 0) && (ecx != BYTES_PER_LINE)
            mov WORD ptr [xdi], " |"
            add xdi, sizeof(WORD)
          .endif
        .else
          .break
        .endif
      .endw
      m2z BYTE ptr [xdi]
      invoke DbgOutTextA, addr bOutBuffer, dRepColor, dBackColor, DBG_EFFECT_NEWLINE, pDest

    .elseif dRepresentationFormat == DBG_MEM_I16
      mov DWORD ptr [xdi], " S: "
      add xdi, 4

      xor ecx, ecx
      .while ecx < BYTES_PER_LINE/sizeof(WORD) && ebx != 0
        .if ebx >= sizeof(WORD)
          mov ax, [xsi]
          sub ebx, sizeof(WORD)
          add xsi, sizeof(WORD)
          mov .ecx, ecx
          FillWordA [bAuxBuffer], <0000>
          .ifBitSet ax, BIT15
            neg ax
            movzx edx, ax
            invoke sdword2decA, addr [bAuxBuffer + 4], edx
            mov BYTE ptr [xdi], '-'
          .else
            movzx edx, ax
            invoke sdword2decA, addr [bAuxBuffer + 4], edx
            mov BYTE ptr [xdi], '+'
          .endif
          invoke StrEndA, addr [bAuxBuffer + 4]
          mov BYTE ptr [xax], ' '
          m2m DWORD ptr [xdi + 1], [xax - 5], ecx
          m2m WORD ptr [xdi + 1 + 4], [xax - 5 + 4], edx
          mov ecx, .ecx
          add xdi, 7

          mov eax, ecx
          inc ecx
          and eax, 1
          .if (eax == 1) && (ebx != 0) && (ecx != BYTES_PER_LINE/sizeof(WORD))
            mov WORD ptr [xdi], " |"
            add xdi, sizeof(WORD)
          .endif
        .else
          mov BYTE ptr [xdi], '?'
          inc xdi
          xor ebx, ebx
          .break
        .endif
      .endw
      m2z BYTE ptr [xdi]
      invoke DbgOutTextA, addr bOutBuffer, dRepColor, dBackColor, DBG_EFFECT_NEWLINE, pDest

    .elseif dRepresentationFormat == DBG_MEM_I32
      mov DWORD ptr [xdi], " S: "
      add xdi, 4

      xor ecx, ecx
      .while ecx < BYTES_PER_LINE/sizeof(SDWORD) && ebx != 0
        .if ebx >= sizeof(SDWORD)
          mov edx, [xsi]
          sub ebx, sizeof(SDWORD)
          add xsi, sizeof(SDWORD)

          mov .ecx, ecx
          FillWordA [bAuxBuffer], <0000000000>
          .ifBitSet edx, BIT31
            neg edx
            invoke sdword2decA, addr [bAuxBuffer + 10], edx
            mov BYTE ptr [xdi], '-'
          .else
            invoke sdword2decA, addr [bAuxBuffer + 10], edx
            mov BYTE ptr [xdi], '+'
          .endif
          invoke StrEndA, addr [bAuxBuffer + 10]
          mov BYTE ptr [xax], ' '
          m2m DWORD ptr [xdi + 1], [xax - 10], edx
          m2m DWORD ptr [xdi + 1 + 4], [xax - 10 + 4], ecx
          m2m DWORD ptr [xdi + 1 + 8], [xax - 10 + 8], edx
          mov ecx, .ecx
          add xdi, 12

          inc ecx
          .if (ebx != 0) && (ecx != BYTES_PER_LINE/sizeof(SDWORD))
            mov WORD ptr [xdi], " |"
            add xdi, sizeof(WORD)
          .endif
        .else
          mov BYTE ptr [xdi], '?'
          inc xdi
          xor ebx, ebx
          .break
        .endif
      .endw
      m2z BYTE ptr [xdi]
      invoke DbgOutTextA, addr bOutBuffer, dRepColor, dBackColor, DBG_EFFECT_NEWLINE, pDest

    .elseif dRepresentationFormat == DBG_MEM_R4
      mov DWORD ptr [xdi], " R: "
      add xdi, 4

      xor ecx, ecx
      .while ecx < BYTES_PER_LINE/sizeof(REAL4) && ebx != 0
        .if ebx >= sizeof(REAL4)
          fld REAL4 ptr [xsi]
          sub ebx, sizeof(REAL4)
          add xsi, sizeof(REAL4)

          mov .ecx, ecx
          invoke St0ToStrA, xdi, 0, 4, f_SCI
          fUnload
          .if BYTE ptr [xdi] == ' '
            mov BYTE ptr [xdi], '+'
          .endif
          mov BYTE ptr [xdi + 13], ' '
          mov ecx, .ecx
          add xdi, 14

          inc ecx
          .if (ebx != 0) && (ecx != BYTES_PER_LINE/sizeof(REAL4))
            mov WORD ptr [xdi], " |"
            add xdi, sizeof(WORD)
          .endif
        .else
          mov BYTE ptr [xdi], "?"
          inc xdi
          xor ebx, ebx
          .break
        .endif
      .endw
      m2z BYTE ptr [xdi]
      invoke DbgOutTextA, addr bOutBuffer, dRepColor, dBackColor, DBG_EFFECT_NEWLINE, pDest

    .elseif dRepresentationFormat == DBG_MEM_R8
      mov DWORD ptr [xdi], " R: "
      add xdi, 4

      xor ecx, ecx
      .while ecx < BYTES_PER_LINE/sizeof(REAL8) && ebx != 0
        .if ebx >= sizeof(REAL8)
          fld REAL8 ptr [xsi]
          sub ebx, sizeof(REAL8)
          add xsi, sizeof(REAL8)

          mov .ecx, ecx
          invoke St0ToStrA, xdi, 0, 8, f_SCI
          fUnload
          .if BYTE ptr [xdi] == ' '
            mov BYTE ptr [xdi], '+'
          .endif
          mov BYTE ptr [xdi + 17], ' '
          mov ecx, .ecx
          add xdi, 18

          inc ecx
          .if (ebx != 0) && (ecx != BYTES_PER_LINE/sizeof(REAL8))
            mov WORD ptr [xdi], " |"
            add xdi, sizeof(WORD)
          .endif
        .else
          mov BYTE ptr [xdi], "?"
          inc xdi
          xor ebx, ebx
          .break
        .endif
      .endw
      m2z BYTE ptr [xdi]
      invoke DbgOutTextA, addr bOutBuffer, dRepColor, dBackColor, DBG_EFFECT_NEWLINE, pDest

    .elseif dRepresentationFormat == DBG_MEM_H8
      mov DWORD ptr [xdi], " H: "
      add xdi, 4

      xor ecx, ecx
      .while ecx < BYTES_PER_LINE
        .if ebx > 0
          movzx edx, BYTE ptr [xsi]
          dec ebx
          inc xsi
          mov .ecx, ecx
          invoke dword2hexA, addr bAuxBuffer, edx
          lea xax, bAuxBuffer
          add xax, 8
          mov WORD ptr [xax], " h"
          m2m DWORD ptr [xdi], [xax - 2], edx
          mov ecx, .ecx
          add xdi, 4

          mov eax, ecx
          inc ecx
          and eax, 3
          .if (eax == 3) && (ebx != 0) && (ecx != BYTES_PER_LINE)
            mov WORD ptr [xdi], " |"
            add xdi, sizeof(WORD)
          .endif
        .endif
      .endw
      m2z BYTE ptr [xdi]
      invoke DbgOutTextA, addr bOutBuffer, dRepColor, dBackColor, DBG_EFFECT_NEWLINE, pDest

    .elseif dRepresentationFormat == DBG_MEM_H16
      mov DWORD ptr [xdi], " H: "
      add xdi, 4

      xor ecx, ecx
      .while ecx < BYTES_PER_LINE/sizeof(WORD) && ebx != 0
        .if ebx >= sizeof(WORD)
          movzx edx, WORD ptr [xsi]
          sub ebx, sizeof(WORD)
          add xsi, sizeof(WORD)
          mov .ecx, ecx
          invoke dword2hexA, addr bAuxBuffer, edx
          lea xax, [bAuxBuffer + 4]
          m2m DWORD ptr [xdi], [xax], edx
          mov WORD ptr [xdi + 4], " h"
          mov ecx, .ecx
          add xdi, 6

          mov eax, ecx
          inc ecx
          and eax, 1
          .if (eax == 1) && (ebx != 0) && (ecx != BYTES_PER_LINE/sizeof(WORD))
            mov WORD ptr [xdi], " |"
            add xdi, sizeof(WORD)
          .endif
        .else
          mov BYTE ptr [xdi], '?'
          inc xdi
          xor ebx, ebx
          .break
        .endif
      .endw
      m2z BYTE ptr [xdi]
      invoke DbgOutTextA, addr bOutBuffer, dRepColor, dBackColor, DBG_EFFECT_NEWLINE, pDest

    .elseif dRepresentationFormat == DBG_MEM_H32
      mov DWORD ptr [xdi], " H: "
      add xdi, 4

      xor ecx, ecx
      .while ecx < BYTES_PER_LINE/sizeof(DWORD) && ebx != 0
        .if ebx >= sizeof(DWORD)
          mov edx, [xsi]
          sub ebx, sizeof(DWORD)
          add xsi, sizeof(DWORD)
          mov .ecx, ecx
          invoke dword2hexA, addr bAuxBuffer, edx
          lea xax, [bAuxBuffer]
          m2m DWORD ptr [xdi], [xax], edx
          m2m DWORD ptr [xdi + 4], [xax + 4], ecx
          mov WORD ptr [xdi + 8], " h"
          mov ecx, .ecx
          add xdi, 10

          inc ecx
          .if (ebx != 0) && (ecx != BYTES_PER_LINE/sizeof(DWORD))
            mov WORD ptr [xdi], " |"
            add xdi, sizeof(WORD)
          .endif
        .else
          mov BYTE ptr [xdi], '?'
          inc xdi
          xor ebx, ebx
          .break
        .endif
      .endw
      m2z BYTE ptr [xdi]
      invoke DbgOutTextA, addr bOutBuffer, dRepColor, dBackColor, DBG_EFFECT_NEWLINE, pDest

    if TARGET_BITNESS eq 64
    .elseif dRepresentationFormat == DBG_MEM_H64
      mov DWORD ptr [xdi], " H: "
      add xdi, 4

      xor ecx, ecx
      .while ecx < BYTES_PER_LINE/sizeof(QWORD) && ebx != 0
        .if ebx >= sizeof(QWORD)
          mov rdx, [xsi]
          sub ebx, sizeof(QWORD)
          add xsi, sizeof(QWORD)
          mov .ecx, ecx
          invoke qword2hexA, addr bAuxBuffer, rdx
          lea xax, [bAuxBuffer]
          m2m QWORD ptr [xdi], [xax], edx
          m2m QWORD ptr [xdi + 8], [xax + 8], ecx
          mov WORD ptr [xdi + 16], " h"
          mov ecx, .ecx
          add xdi, 18

          inc ecx
          .if (ebx != 0) && (ecx != BYTES_PER_LINE/sizeof(QWORD))
            mov WORD ptr [xdi], " |"
            add xdi, sizeof(WORD)
          .endif
        .else
          mov BYTE ptr [xdi], '?'
          inc xdi
          xor ebx, ebx
          .break
        .endif
      .endw
      m2z BYTE ptr [xdi]
      invoke DbgOutTextA, addr bOutBuffer, dRepColor, dBackColor, DBG_EFFECT_NEWLINE, pDest

    .elseif dRepresentationFormat == DBG_MEM_UI64
      mov DWORD ptr [xdi], " U: "
      add xdi, 4

      xor ecx, ecx
      .while ecx < BYTES_PER_LINE/sizeof(QWORD) && ebx != 0
        .if ebx >= sizeof(QWORD)
          mov rdx, [xsi]
          sub ebx, sizeof(QWORD)
          add xsi, sizeof(QWORD)

          mov .ecx, ecx
          FillWordA [bAuxBuffer], <0000000000000000000>
          invoke uqword2decA, addr [bAuxBuffer + 19], rdx
          invoke StrEndA, addr [bAuxBuffer + 19]
          mov BYTE ptr [xax], ' '
          m2m QWORD ptr [xdi], [xax - 20], edx
          m2m QWORD ptr [xdi + 8], [xax - 20 + 8], edx
          m2m DWORD ptr [xdi + 16], [xax - 20 + 16], ecx
          m2m BYTE ptr [xdi + 20], [xax - 20 + 20], edx
          mov ecx, .ecx
          add xdi, 21

          inc ecx
          .if (ebx != 0) && (ecx != BYTES_PER_LINE/sizeof(QWORD))
            mov WORD ptr [xdi], " |"
            add xdi, sizeof(WORD)
          .endif
        .else
          mov BYTE ptr [xdi], '?'
          inc xdi
          xor ebx, ebx
          .break
        .endif
      .endw
      m2z BYTE ptr [xdi]
      invoke DbgOutTextA, addr bOutBuffer, dRepColor, dBackColor, DBG_EFFECT_NEWLINE, pDest

    .elseif dRepresentationFormat == DBG_MEM_I64
      mov DWORD ptr [xdi], " S: "
      add xdi, 4

      xor ecx, ecx
      .while ecx < BYTES_PER_LINE/sizeof(SQWORD) && ebx != 0
        .if ebx >= sizeof(SQWORD)
          mov rdx, [xsi]
          sub ebx, sizeof(SQWORD)
          add xsi, sizeof(SQWORD)

          mov .ecx, ecx
          FillWordA [bAuxBuffer], <0000000000000000000>
          mov rcx, BIT63
          .ifBitSet rdx, rcx
            neg rdx
            invoke sqword2decA, addr [bAuxBuffer + 19], rdx
            mov BYTE ptr [xdi], '-'
          .else
            invoke sqword2decA, addr [bAuxBuffer + 19], rdx
            mov BYTE ptr [xdi], '+'
          .endif
          invoke StrEndA, addr [bAuxBuffer + 19]
          mov BYTE ptr [xax], ' '
          m2m QWORD ptr [xdi + 1], [xax - 20], edx
          m2m QWORD ptr [xdi + 9], [xax - 20 + 8], edx
          m2m DWORD ptr [xdi + 17], [xax - 20 + 16], ecx
          m2m BYTE ptr [xdi + 21], [xax - 20 + 20], edx
          mov ecx, .ecx
          add xdi, 22

          inc ecx
          .if (ebx != 0) && (ecx != BYTES_PER_LINE/sizeof(SQWORD))
            mov WORD ptr [xdi], " |"
            add xdi, sizeof(WORD)
          .endif
        .else
          mov BYTE ptr [xdi], '?'
          inc xdi
          xor ebx, ebx
          .break
        .endif
      .endw
      m2z BYTE ptr [xdi]
      invoke DbgOutTextA, addr bOutBuffer, dRepColor, dBackColor, DBG_EFFECT_NEWLINE, pDest
    endif

    .else
      mov DWORD ptr [xdi], " ?: "
      add xdi, 3
      .if ebx > BYTES_PER_LINE
        sub ebx, BYTES_PER_LINE
        add xsi, BYTES_PER_LINE
      .else
        xor ebx, ebx
      .endif
      m2z BYTE ptr [xdi]
      invoke DbgOutTextA, addr bOutBuffer, dRepColor, dBackColor, DBG_EFFECT_NEWLINE, pDest
    .endif

  .endw
  ret
ProcName endp
