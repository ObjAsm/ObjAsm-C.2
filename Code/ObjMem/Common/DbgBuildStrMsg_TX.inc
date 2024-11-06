; ==================================================================================================
; Title:      DbgBuildStrMsg_TX.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, November 2023
;               - First release.
; ==================================================================================================


; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  DbgBuildStrMsgA / DbgBuildStrMsgW
; Purpose:    Debug helper proc that builds a structure in memory to send a string to the
;             DebugCenter server.
; Arguments:  Arg1: -> Zero terminated string.
;             Arg2: Foreground RGB color value.
;             Arg3: Background RGB color value.
;             Arg4: Effect value (DBG_EFFECT_XXX)
;             Arg5: -> Destination window WIDE name.
; Return:     xax -> Allocated memory containig the message.
;                 When no longer needed, it should be deallocated using MemFree.
;             ecx = Byte size of the allocated memory block.

; dSize = sizeof(DBG_HEADER_INFO) + sizeof(pDest) + sizeof(DBG_STR_INFO) + sizeof(pString)
;                                   -------------                          ---------------
;                                      dSize2                                  dSize4    
;         ---------------------------------------   --------------------------------------
;                         dSize1                                     dSize3  

.code
align ALIGN_CODE
ProcName proc pString:POINTER, dForeColor:DWORD, dBackColor:DWORD, dEffects:DWORD, pDest:POINTER
  local pData:POINTER, dSize:DWORD, dSize1:DWORD, dSize2:DWORD, dSize3:DWORD, dSize4:DWORD

  invoke StrSize, pString                           ;String size
  mov dSize4, eax
  add eax, sizeof(DBG_STR_INFO)                     ;This includes the ZTC
  mov dSize3, eax
  mov dSize, eax
  invoke StrSizeW, pDest
  mov dSize2, eax                                   ;String size
  add eax, sizeof(DBG_HEADER_INFO)
  mov dSize1, eax
  add dSize, eax
  MemAlloc dSize
  .if xax != NULL                                   ;Continue only if GlobalAlloc succeeded
    mov pData, xax
    mov [xax].DBG_HEADER_INFO.bBlockID, DBG_MSG_HDR ;Set block type = header
    mov [xax].DBG_HEADER_INFO.bInfo, 0
    m2m [xax].DBG_HEADER_INFO.dBlockLen, dSize1, ecx
    invoke MemClone, addr [xax + sizeof(DBG_HEADER_INFO)], pDest, dSize2
    mov xax, pData
    mov ecx, [xax].DBG_HEADER_INFO.dBlockLen
    add xax, xcx
    mov [xax].DBG_STR_INFO.bBlockID, DBG_MSG_STR    ;Set block type = string
    mov [xax].DBG_STR_INFO.bInfo, 0
    m2m [xax].DBG_STR_INFO.dBlockLen, dSize3, ecx
    m2m [xax].DBG_STR_INFO.dForeColor, dForeColor, edx
    m2m [xax].DBG_STR_INFO.dBackColor, dBackColor, ecx
    mov edx, dEffects
  if TARGET_STR_TYPE eq STR_TYPE_WIDE
    BitSet edx, DBG_CHARTYPE_WIDE                   ;Clear if ANSI
  endif
    mov [xax].DBG_STR_INFO.dEffects, edx
    invoke MemClone, addr [xax + sizeof(DBG_STR_INFO)], pString, dSize4
    mov xax, pData
    mov ecx, dSize
  .else
    xor ecx, ecx
  .endif
  ret
ProcName endp
