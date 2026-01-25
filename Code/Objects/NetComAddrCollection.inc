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
; Arguments: Arg1: -> First NETCOMADDR.
;            Arg2: -> Second NETCOMADDR (Search key).
; Return:    eax = Compare result.

Method NetComAddrCollection.Compare,, pItem1:PNETCOMADDR, pItem2:PNETCOMADDR
  mov xcx, pItem1
  mov xdx, pItem2
  mov ax, [xcx].NETCOMADDR.wFamily
  sub ax, [xdx].NETCOMADDR.wFamily
  .if ZERO?
    .if [xcx].NETCOMADDR.wFamily == AF_INET
      mov eax, DWORD ptr [xcx].NETCOMADDR.Address          ;This address fits in a 32 bit register
      sub eax, DWORD ptr [xdx].NETCOMADDR.Address
      DbgHex eax,, "NetComAddrCollection"
;      .if ZERO?
;        mov ax, [xcx].NETCOMADDR.wPort
;        sub ax, [xdx].NETCOMADDR.wPort
;        movsx eax, ax
;      .endif
    .elseif [xcx].NETCOMADDR.wFamily == AF_INET6
      invoke MemComp, addr [xcx].NETCOMADDR.Address, \
                      addr [xdx].NETCOMADDR.Address, \
                      sizeof IN6_ADDR
;      .if eax == 0
;        mov xcx, pItem1
;        mov xdx, pItem2
;        mov ax, [xcx].NETCOMADDR.Address
;        sub ax, [xdx].NETCOMADDR.Address
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
  local pEntry:PNETCOMADDR

  SetObject xsi
  MemAlloc sizeof NETCOMADDR
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