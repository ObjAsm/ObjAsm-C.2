; ==================================================================================================
; Title:      DbgBuildCmdMsg_X.inc
; Author:     G. Friedrich
; Version:    C.1.1
; Notes:      Version C.1.0, November 2023
;               - First release.
; ==================================================================================================


; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  DbgBuildCmdMsg
; Purpose:    Debug helper proc that builds a structure in memory to send a command to the
;             DebugCenter server.
; Arguments:  Arg1: Command ID (BYTE).
;             Arg2: First parameter (DWORD).
;             Arg3: Second parameter (DWORD).
;             Arg4: -> Payload. If NULL, the space (Payload size) is reserved anyway.
;             Arg5: Payload size (DWORD).
;             Arg6: -> Destination Window WIDE name.
; Return:     xax -> Allocated memory containig the message.
;                 When no longer needed, it should be deallocated using MemFree.
;             ecx = Byte size of the allocated memory block.
;             xdx -> Payload into message buffer.

; dSize = sizeof(DBG_HEADER_INFO) + sizeof(pDest) + sizeof(DBG_CMD_INFO) + sizeof(Payload)
;                                   -------------                          ---------------
;                                       esi                                     dSize

align ALIGN_CODE
DbgBuildCmdMsg proc uses xsi bCommand:BYTE, dParam1:DWORD, dParam2:DWORD, \
                             pPayload:POINTER, dPayloadSize:DWORD, pDest:POINTER
  local pBuffer:POINTER, dBufferSize:DWORD

  xor eax, eax
  .if pDest
    invoke StrSizeW, pDest                          ;Always a WIDE string
  .endif
  mov esi, eax
  add eax, sizeof(DBG_HEADER_INFO) + sizeof(DBG_CMD_INFO)
  add eax, dPayloadSize
  mov dBufferSize, eax
  MemAlloc dBufferSize
  .if xax != NULL                                   ;Continue only if GlobalAlloc succeeded
    mov pBuffer, xax
    mov [xax].DBG_HEADER_INFO.bBlockID, DBG_MSG_HDR
    mov [xax].DBG_HEADER_INFO.bInfo, 0
    lea ecx, [esi + sizeof(DBG_HEADER_INFO)]
    mov [xax].DBG_HEADER_INFO.dBlockLen, ecx
    .if esi
      invoke MemClone, addr [xax + sizeof(DBG_HEADER_INFO)], pDest, esi
    .endif
    mov xax, pBuffer
    lea xdx, [xax + xsi + sizeof(DBG_HEADER_INFO)]
    mov [xdx].DBG_CMD_INFO.bBlockID, DBG_MSG_CMD
    m2m [xdx].DBG_CMD_INFO.bInfo, bCommand, cl
    mov eax, dPayloadSize
    add eax, sizeof(DBG_CMD_INFO)
    mov [xdx].DBG_CMD_INFO.dBlockLen, eax
    mov eax, dParam1
    mov ecx, dParam2
    mov [xdx].DBG_CMD_INFO.dParam1, eax
    mov [xdx].DBG_CMD_INFO.dParam2, ecx
    lea xsi, [xdx + sizeof(DBG_CMD_INFO)]
    .if pPayload
      invoke MemClone, xsi, pPayload, dPayloadSize
    .endif
    mov xax, pBuffer
    mov xdx, xsi
    mov ecx, dBufferSize
  .else
    xor ecx, ecx
    mov xdx, xcx
  .endif
  ret
DbgBuildCmdMsg endp
