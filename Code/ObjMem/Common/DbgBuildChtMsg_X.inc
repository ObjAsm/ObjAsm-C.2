; ==================================================================================================
; Title:      DbgBuildChtMsg_X.inc
; Author:     Héctor S. Enrique / G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, October 2024
;               - First release.
; ==================================================================================================


; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  DbgBuildChtMsg
; Purpose:    Debug helper proc that builds a structure in memory to send a command to the
;             DebugCenter server.
; Arguments:  Arg1: ID (BYTE).
;             Arg2: -> Payload. If NULL, the space (Payload size) is reserved anyway.
;             Arg3: Payload size (DWORD).
;             Arg4: -> Destination Window WIDE name.
; Return:     xax -> Allocated memory containig the message.
;                 When no longer needed, it should be deallocated using MemFree.
;             ecx = Byte size of the allocated memory block.
;             xdx -> Payload into message buffer.

; dSize = sizeof(DBG_HEADER_INFO) + sizeof(pDest) + sizeof(DBG_CHT_INFO) + sizeof(Payload)
;                                   -------------                          ---------------
;                                       esi                                     dSize

align ALIGN_CODE
DbgBuildChtMsg proc uses xsi bChartMsgID:BYTE, pPayload:POINTER, dPayloadSize:DWORD, pDest:POINTER
  local pBuffer:POINTER, dBufferSize:DWORD

  xor eax, eax
  .if pDest
    invoke StrSizeW, pDest                          ;Always a WIDE string
  .endif
  mov esi, eax
  add eax, sizeof(DBG_HEADER_INFO) + sizeof(DBG_CHT_INFO)
  add eax, dPayloadSize
  mov dBufferSize, eax                              ;Total Msg size
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
    mov [xdx].DBG_CHT_INFO.bBlockID, DBG_MSG_CHT
    m2m [xdx].DBG_CHT_INFO.bInfo, bChartMsgID, cl   ;Store Msg ID
    mov eax, dPayloadSize
    add eax, sizeof(DBG_CHT_INFO)
    mov [xdx].DBG_CHT_INFO.dBlockLen, eax
    lea xsi, [xdx + sizeof(DBG_CHT_INFO)]
    .if pPayload
      invoke MemClone, xsi, pPayload, dPayloadSize
    .endif
    mov xax, pBuffer
    mov ecx, dBufferSize
    mov xdx, xsi
  .else
    xor ecx, ecx
    mov xdx, xcx
  .endif
  ret
DbgBuildChtMsg endp
