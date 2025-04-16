; ==================================================================================================
; Title:      NetComAddrCollection.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm support of NetComAddrCollection objects.
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


.code

if IMPLEMENT

; ==================================================================================================
;    NetComAddrCollection implementation
; ==================================================================================================

; --------------------------------------------------------------------------------------------------
; Method:    NetComAddrCollection.Compare
; Purpose:   Compare 2 NETCOMADDR_ENTRYs
; Arguments: Arg1: -> First NETCOMADDR_ENTRY.
;            Arg2: -> Second NETCOMADDR (Search key).
; Return:    eax = Compare result.

Method NetComAddrCollection.Compare,, pItem1:PNETCOMADDR_ENTRY, pItem2:PNETCOMADDR
  mov xcx, pItem1
  mov xdx, pItem2
  mov ax, [xcx].NETCOMADDR_ENTRY.sa_family
  sub ax, [xdx].NETCOMADDR_ENTRY.sa_family
  .if ZERO?
    .if [xcx].NETCOMADDR_ENTRY.sa_family == AF_INET
      mov eax, [xcx].NETCOMADDR_ENTRY.sin_addr          ;This address fits in a 32 bit register
      sub eax, [xdx].NETCOMADDR_ENTRY.sin_addr
      DbgHex eax,, "NetComAddrCollection"
;      .if ZERO?
;        mov ax, [xcx].NETCOMADDR_ENTRY.sin_port
;        sub ax, [xdx].NETCOMADDR_ENTRY.sin_port
;        movsx eax, ax
;      .endif
    .elseif [xcx].NETCOMADDR_ENTRY.sa_family == AF_INET6
      invoke MemComp, addr [xcx].SOCKADDR_IN6.sin6_addr, \
                      addr [xdx].SOCKADDR_IN6.sin6_addr, \
                      sizeof IN6_ADDR
;      .if eax == 0
;        mov xcx, pItem1
;        mov xdx, pItem2
;        mov ax, [xcx].SOCKADDR_IN6.sin6_port
;        sub ax, [xdx].SOCKADDR_IN6.sin6_port
;        movsx eax, ax
;      .endif
    .else
      DbgWarning "NetComAddrCollection.Compare - ss_family comparison not implemented"
      mov eax, -1
    .endif
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:    NetComAddrCollection.Init
; Purpose:   Initialize the NetComAddrCollection object.
; Arguments: Arg1: -> Owner object.
;            Arg2: Limit value of the collection (items).
;            Arg3: Growing factor of the collection (items).
;            Arg4: Maximum size of the collection (items).
; Return:    eax = Zero if succeeded, otherwise an error code.

Method NetComAddrCollection.Init, uses xsi, pOwner:POINTER, dLimit:DWORD, dDelta:DWORD, \
                                            dMaxCapacity:DWORD
  SetObject xsi
  ACall xsi.Init, pOwner, dLimit, dDelta, dMaxCapacity
  mov [xsi].dDuplicates, FALSE
  xor eax, eax
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     NetComAddrCollection.Insert
; Purpose:    Insert item at the end of the collection.
; Arguments:  Arg1: -> NETCOMADDR.
; Return:     xax -> Inserted item or NULL if failed.

Method NetComAddrCollection.Insert, uses xsi, pItem:POINTER
  local pEntry:PNETCOMADDR_ENTRY

  SetObject xsi
  MemAlloc sizeof NETCOMADDR_ENTRY
  .if xax != NULL
    mov pEntry, xax
    invoke MemClone, xax, pItem, sizeof NETCOMADDR
    ACall xsi.Insert, pEntry
  .else
    OCall xsi.ErrorReport, NULL, COL_OUT_OF_MEMORY
    xor eax, eax                                        ;Return NULL
  .endif
MethodEnd

endif