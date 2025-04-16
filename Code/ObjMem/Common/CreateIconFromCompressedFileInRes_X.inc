; ==================================================================================================
; Title:      CreateIconFromCompressedFileInRes_X.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2023
;               - First release.
; Links:      https://devblogs.microsoft.com/oldnewthing/20120720-00/?p=7083
;             https://devblogs.microsoft.com/oldnewthing/20231025-00/?p=108925
; ==================================================================================================


% include &ObjMemPath&Common\CursorIconStructs.inc

; --------------------------------------------------------------------------------------------------
; Procedure:  CreateIconFromCompressedFileInRes
; Purpose:    Create an icon from a compressed icon file stored as RCDATA resource. 
;             Compression should be done using a Microsoft compression algorithm: XPRESS, XPRESS
;             with Huffman encoding, MSZIP or LZMS.
; Arguments:  Arg1: hInstance.
;             Arg2: Resource ID.
;             Arg3: Desired icon width.
;             Arg3: Desired icon height.
; Return:     xax = Icon HANDLE.

.code
align ALIGN_CODE
CreateIconFromCompressedFileInRes proc uses xbx xdi xsi hInst:HINSTANCE, xResourceID:XWORD, \
                                                        dDesiredCx:DWORD, dDesiredCy:DWORD
  local pFileData:POINTER, dFileDataSize:DWORD
  local hIcon:HICON, pRsrcDirectory:PGRP_HEADER

  mov hIcon, 0
if TARGET_BITNESS eq 32
  invoke DecompressFileFromRes, hInst, xResourceID
else
  invoke DecompressFileFromRes, rcx, rdx
endif
  .if xax != NULL
    mov pFileData, xax
    mov xsi, xax
    mov dFileDataSize, ecx
    .if WORD ptr [xsi].GRP_HEADER.wResType == RES_ICON
      ;Replicate in memory the structure created by the resource compiler
      movzx edi, [xsi].GRP_HEADER.wResCount
      mov eax, sizeof(GRP_RSRC_ENTRY)
      mul edi
      add eax, sizeof(GRP_HEADER)
      MemAlloc eax
      .if xax != NULL
        mov pRsrcDirectory, xax
        s2s GRP_HEADER ptr [xax], GRP_HEADER ptr [xsi], xcx, xdx
        add xax, sizeof(GRP_HEADER)
        add xsi, sizeof(GRP_HEADER)
        xor ebx, ebx
        .while ebx < edi
          s2s GRP_ENTRY_BEG ptr [xax], GRP_ENTRY_BEG ptr [xsi], xcx, xdx, xmm0, xmm1
          mov [xax].GRP_RSRC_ENTRY.nIconCursorId, bx
          add xax, sizeof(GRP_RSRC_ENTRY)
          add xsi, sizeof(GRP_FILE_ENTRY)
          inc ebx
        .endw
        invoke LookupIconIdFromDirectoryEx, pRsrcDirectory, TRUE, \
                                            dDesiredCx, dDesiredCy, LR_DEFAULTCOLOR
        mov ecx, sizeof(GRP_FILE_ENTRY)
        mul xcx
        add xax, pFileData
        add xax, sizeof(GRP_HEADER)
        mov ecx, [xax].GRP_FILE_ENTRY.dOffset
        add xcx, pFileData
        invoke CreateIconFromResourceEx, xcx, [xax].GRP_FILE_ENTRY.dwBytesInRes, TRUE, 30000h, \
                                         dDesiredCx, dDesiredCy, LR_DEFAULTCOLOR or LR_SHARED
        mov hIcon, xax
        MemFree pRsrcDirectory
      .endif
      MemFree pFileData
    .endif
  .endif
  mov xax, hIcon
  ret
CreateIconFromCompressedFileInRes endp
