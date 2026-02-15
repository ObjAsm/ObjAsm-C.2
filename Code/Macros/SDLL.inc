; ==================================================================================================
; Title:      SDLL.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm support of "Sentinel Doubly Linked List" macros.
; Links:      http://en.wikipedia.org/wiki/Linked_list
; Notes:      No sanity checks are performed by this set of macros!
;             Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


;This structure describes the members stored in the "Sentinel Doubly Linked List".
;Each member contains a pointer to the next and previous member.


;                 SDLL_SENTINEL       (1/2 Sentinel)
;                      ^ |
;                      | V
;                  SDLL_ITEM_0        (first item)
;                      ^ |
;                      | V                                ^  Backward
;                                                         |
;                       .
;                       .
;                       .                                 |
;                                                         V  Forward
;                      ^ |
;                      | V
;                  SDLL_ITEM_N        (last item)
;                      ^ |
;                      | V
;                 SDLL_SENTINEL       (1/2 Sentinel)



; ==================================================================================================


PSDLL_ITEM typedef ptr SDLL_ITEM
SDLL_ITEM struc
  pNextItem     PSDLL_ITEM   ?                          ;-> Next item
  pPrevItem     PSDLL_ITEM   ?                          ;-> Previous item
SDLL_ITEM ends

SDLL_SENTINEL struc
  pFirstItem    PSDLL_ITEM   ?                          ;-> First item
  pLastItem     PSDLL_ITEM   ?                          ;-> Last item
SDLL_SENTINEL ends
PSDLL_SENTINEL typedef ptr SDLL_SENTINEL


; ==================================================================================================


; --------------------------------------------------------------------------------------------------
; Macro:      SDLL_Init
; Purpose:    Initialize the control structure.
; Arguments:  Arg1: Register -> Sentinel structure.

SDLL_Init macro CtlReg:req
  mov [CtlReg].SDLL_SENTINEL.pFirstItem, CtlReg
  mov [CtlReg].SDLL_SENTINEL.pLastItem, CtlReg
endm

; --------------------------------------------------------------------------------------------------
; Macro:      SDLL_InsertAfter
; Purpose:    Inserts an object after another in the linked list.
; Arguments:  Arg1: Register -> Member to insert after.
;             Arg2: Register -> Member to insert.
;             Arg3: Auxiliar register. If not specified, RefReg is used.

SDLL_InsertAfter macro RefReg:req, NewReg:req, AuxReg:=<>
  ifb <AuxReg>
    push [RefReg].SDLL_ITEM.pNextItem
    mov [RefReg].SDLL_ITEM.pNextItem, NewReg
    mov [NewReg].SDLL_ITEM.pPrevItem, RefReg
    pop RefReg
    mov [RefReg].SDLL_ITEM.pPrevItem, NewReg
    mov [NewReg].SDLL_ITEM.pNextItem, RefReg
  else
    mov AuxReg, [RefReg].SDLL_ITEM.pNextItem
    mov [RefReg].SDLL_ITEM.pNextItem, NewReg
    mov [AuxReg].SDLL_ITEM.pPrevItem, NewReg
    mov [NewReg].SDLL_ITEM.pNextItem, AuxReg
    mov [NewReg].SDLL_ITEM.pPrevItem, RefReg
  endif
endm

; --------------------------------------------------------------------------------------------------
; Macro:      SDLL_InsertBefore
; Purpose:    Insert an object before another in the linked list.
; Arguments:  Arg1: Register -> Member to insert before.
;             Arg2: Register -> Member to insert.
;             Arg3: Auxiliar register. If not specified, RefReg is used.

SDLL_InsertBefore macro RefReg:req, NewReg:req, AuxReg:=<>
  ifb <AuxReg>
    push [RefReg].SDLL_ITEM.pPrevItem
    mov [RefReg].SDLL_ITEM.pPrevItem, NewReg
    mov [NewReg].SDLL_ITEM.pNextItem, RefReg
    pop RefReg
    mov [RefReg].SDLL_ITEM.pNextItem, NewReg
    mov [NewReg].SDLL_ITEM.pPrevItem, RefReg
  else
    mov AuxReg, [RefReg].SDLL_ITEM.pPrevItem
    mov [RefReg].SDLL_ITEM.pPrevItem, NewReg
    mov [AuxReg].SDLL_ITEM.pNextItem, NewReg
    mov [NewReg].SDLL_ITEM.pNextItem, RefReg
    mov [NewReg].SDLL_ITEM.pPrevItem, AuxReg
  endif
endm

; --------------------------------------------------------------------------------------------------
; Macros:     LinkedList_InsertFirst
; Purpose:    Insert a new member to the end of the Linked List.
; Arguments:  Arg1: Register -> Sentinel structure.
;             Arg2: Register -> Member to insert register.
;             Arg3: Auxiliar register. If not specified, RefReg is used.

SDLL_InsertFirst equ <SDLL_InsertAfter>

; --------------------------------------------------------------------------------------------------
; Macros:     LinkedList_InsertLast
; Purpose:    Insert a new member to the end of the Linked List.
; Arguments:  Arg1: Register -> Sentinel structure.
;             Arg2: Register -> Member to insert register.
;             Arg3: Auxiliar register. If not specified, RefReg is used.

SDLL_InsertLast equ <SDLL_InsertBefore>

SDLL_Append equ <SDLL_InsertBefore>

; --------------------------------------------------------------------------------------------------
; Macro:      SDLL_Remove
; Purpose:    Remove a member from the linked list.
; Arguments:  Arg1: Register -> Member to remove register or reference.
;             Arg2: Auxiliar register 1.
;             Arg3: Auxiliar register 2. If not specified, RefReg is used.

SDLL_Remove macro RefReg:req, AuxReg1:req, AuxReg2:=<>
  ifb <AuxReg2>
    mov AuxReg1, [RefReg].SDLL_ITEM.pNextItem
    mov RefReg, [RefReg].SDLL_ITEM.pPrevItem
    mov [AuxReg1].SDLL_ITEM.pPrevItem, RefReg
    mov [RefReg].SDLL_ITEM.pNextItem, AuxReg1
  else
    mov AuxReg1, [RefReg].SDLL_ITEM.pNextItem
    mov AuxReg2, [RefReg].SDLL_ITEM.pPrevItem
    mov [AuxReg1].SDLL_ITEM.pPrevItem, AuxReg2
    mov [AuxReg2].SDLL_ITEM.pNextItem, AuxReg1
  endif
endm

; --------------------------------------------------------------------------------------------------
; Macro:      SDLL_RemoveFirst
; Purpose:    Remove the first member from the linked list.
; Arguments:  Arg1: Register -> Sentinel structure.
;             Arg2: Auxiliar register.

SDLL_RemoveFirst macro SnlReg:req, AuxReg:req
  mov AuxReg, [SnlReg].SDLL_SENTINEL.pFirstItem
  mov AuxReg, [AuxReg].SDLL_ITEM.pNextItem
  mov [SnlReg].SDLL_SENTINEL.pFirstItem, AuxReg
  mov [AuxReg].SDLL_ITEM.pPrevItem, SnlReg
endm

; --------------------------------------------------------------------------------------------------
; Macro:      SDLL_RemoveLast
; Purpose:    Remove the first member from the linked list.
; Arguments:  Arg1: Register -> Sentinel structure.
;             Arg2: Auxiliar register 1.

SDLL_RemoveLast macro SnlReg:req, AuxReg:req
  mov AuxReg, [SnlReg].SDLL_SENTINEL.pLastItem
  mov AuxReg, [AuxReg].SDLL_ITEM.pPrevItem
  mov [SnlReg].SDLL_SENTINEL.pLastItem, AuxReg
  mov [AuxReg].SDLL_ITEM.pNextItem, SnlReg
endm

; --------------------------------------------------------------------------------------------------
; Macro:      SDLL_GetFirst
; Purpose:    Return the first item in the list.
; Arguments:  Arg1: Register -> Sentinel structure.
;             Arg2: Return register.
; Note:       If SnlReg == [SnlReg].SDLL_ITEM.pNextItem, then the list is empty!
; Example:    SDLL_GetFirst ecx, eax; jz ...

SDLL_GetFirst macro SnlReg:req, RetReg:req
  mov RetReg, [SnlReg].SDLL_SENTINEL.pFirstItem
  cmp RetReg, SnlReg
endm

; --------------------------------------------------------------------------------------------------
; Macro:      SDLL_GetLast
; Purpose:    Return the last item in the list.
; Arguments:  Arg1: Register -> Sentinel structure.
;             Arg2: Return register.
; Note:       If SnlReg == [SnlReg].SDLL_ITEM.pPrevItem, then the list is empty!
; Example:    SDLL_GetLast ecx, eax; jz ...

SDLL_GetLast macro SnlReg:req, RetReg:req
  mov RetReg, [SnlReg].SDLL_SENTINEL.pLastItem
  cmp RetReg, SnlReg
endm

; --------------------------------------------------------------------------------------------------
; Macro:      SDLL_GetNext
; Purpose:    Return the next item in the list.
; Arguments:  Arg1: Register -> Reference item.
;             Arg2: Register -> Sentinel structure.
;             Arg3: Return register. If not specified, the RefReg is used as return register.
; Note:       If SnlReg == [RefReg].SDLL_ITEM.pNextItem, then the list is empty!
; Example:    SDLL_GetNext ecx, eax; jz ...

SDLL_GetNext macro RefReg:req, SnlReg:req, RetReg:=<>
  ifb <RetReg>
    mov RefReg, [RefReg].SDLL_ITEM.pNextItem
    cmp SnlReg, RefReg
  else
    mov RetReg, [RefReg].SDLL_ITEM.pNextItem
    cmp SnlReg, RetReg
  endif
endm

; --------------------------------------------------------------------------------------------------
; Macro:      SDLL_GetPrev
; Purpose:    Return the previous item in the list.
; Arguments:  Arg1: Register -> Reference item.
;             Arg2: Register -> Sentinel structure.
;             Arg3: Return register. If not specified, the RefReg is used as return register.
; Note:       If SnlReg == [RefReg].SDLL_ITEM.pNextItem, then the list is empty!
; Example:    SDLL_GetNext ecx, eax; jz ...

SDLL_GetPrev macro RefReg:req, SnlReg:req, RetReg:=<>
  ifb <RetReg>
    mov RefReg, [RefReg].SDLL_ITEM.pPrevItem
    cmp SnlReg, RefReg
  else
    mov RetReg, [RefReg].SDLL_ITEM.pPrevItem
    cmp SnlReg, RetReg
  endif
endm

; --------------------------------------------------------------------------------------------------
; Macro:      .SDLL_ForEach
; Purpose:    Loop through all items of the list.
; Arguments:  Arg1: Non volatile Register -> Sentinel structure.
;             Arg2: Optional POINTER variable/non volatile register. Can not be xax!
; Return:     Nothing.
; Note:       On each loop xax -> List item.
; Example:    lea xbx, MyList
;             .SDLL_ForEach xbx              
;               DbgHex [xax].$Obj(Primer).pOwner
;             .SDLL_Next

.SDLL_ForEach macro SnlReg:req, IndexReg
  ??SDLL_ForEach_ID = ??SDLL_ForEach_ID + 1
  ifb <IndexReg>
    @CatStr(<??SDLL_ForEach_Pointer_>, %??SDLL_ForEach_ID) textequ GetMemBSS(@WordSize)
  else
    @CatStr(<??SDLL_ForEach_Pointer_>, %??SDLL_ForEach_ID) textequ <IndexReg>
  endif
  mov xax, [SnlReg].SDLL_SENTINEL.pFirstItem
  .while xax != SnlReg
    mov @CatStr(<??SDLL_ForEach_Pointer_>, %??SDLL_ForEach_ID), xax
endm

; --------------------------------------------------------------------------------------------------
; Macro:      .SDLL_Next
; Purpose:    Move to the next list item.
; Arguments:  None
; Return:     Nothing.

.SDLL_Next macro
    if opattr(@CatStr(<??SDLL_ForEach_Pointer_>, %??SDLL_ForEach_ID)) & OAT_REGISTER
      mov xax, [@CatStr(<??SDLL_ForEach_Pointer_>, %??SDLL_ForEach_ID)].SDLL_ITEM.pNextItem
    else
      mov xax, @CatStr(<??SDLL_ForEach_Pointer_>, %??SDLL_ForEach_ID)
      mov xax, [xax].SDLL_ITEM.pNextItem
    endif
  .endw
  ??SDLL_ForEach_ID = ??SDLL_ForEach_ID - 1
endm
