; ==================================================================================================
; Title:      LSLL.inc
; Author:     G. Friedrich
; Version:    C.1.1
; Purpose:    ObjAsm support of "Linear Simply Linked List" macros.
; Notes:      No sanity checks are performed by this set of macros!
;             Version C.1.0, October 2017
;               - First release.
;             Version C.1.1, January 2023
;               - .ListForEach/.ListNext macros added. 
; ==================================================================================================


;This structure describes the members stored in the Simply Linked List.
;Each member contains a pointer to the next member.
;
;
;
;   FirstMember -> LSLL_ITEM_0
;                        |
;                        V
;                  LSLL_ITEM_1
;                        |
;
;                        .
;                        .
;                        .
;
;                        |
;                        V
;                  LSLL_ITEM_N
;                        |
;                        V
;                      (NULL)
;


; ==================================================================================================


PLSLL_ITEM typedef ptr LSLL_ITEM
LSLL_ITEM struc
  pLinkFwrd     PLSLL_ITEM    ?                         ;-> Next member
LSLL_ITEM ends

PLSLL_CONTROL typedef ptr LSLL_CONTROL
LSLL_CONTROL struc
  pFirstMember  PLSLL_ITEM    ?                         ;-> First member
LSLL_CONTROL ends

??ListForEach_ID = 0

; ==================================================================================================


; --------------------------------------------------------------------------------------------------
; Macro:      LSLL.InsertAfter
; Purpose:    Insert an object after another in the linked list.
; Arguments:  Arg1: -> Member to insert after.
;             Arg2: -> Member to insert.
;             Arg3: Auxiliar register.

LSLL_InsertAfter macro RefReg:req, NewReg:req, AuxReg:=<>
  m2m [NewReg].LSLL_ITEM.pLinkFwrd, [RefReg].LSLL_ITEM.pLinkFwrd, AuxReg
  mov [RefReg].LSLL_ITEM.pLinkFwrd, NewReg
endm

; --------------------------------------------------------------------------------------------------
; Macro:      LSLL_RemoveAfter
; Purpose:    Remove a member from the linked list.
; Arguments:  Arg1: -> Member to remove after.
;             Arg2: Auxiliar register, default is xcx.

LSLL_RemoveAfter macro RefReg:req, AuxReg:=<xcx>
  mov AuxReg, [RefReg].LSLL_ITEM.pLinkFwrd
  m2m [RefReg].LSLL_ITEM.pLinkFwrd, [AuxReg].LSLL_ITEM.pLinkFwrd, AuxReg
endm

; --------------------------------------------------------------------------------------------------
; Macro:      .LSLL_ForEach
; Purpose:    Loop through all items of the list.
; Arguments:  Arg1: First member of the list.
;             Arg2: Optional POINTER variable/register. Can not be xax!
; Return:     Nothing.
; Note:       On each loop xax -> List item.
; Example:    .LSLL_ForEach pFirstMember
;               DbgHex [xax].$Obj(Primer).pOwner
;             .LSLL_Next

.LSLL_ForEach macro pFirstMember:req, IndexReg
  ??LSLL_ForEach_ID = ??LSLL_ForEach_ID + 1
  ifb <IndexReg>
    @CatStr(<??LSLL_ForEach_Pointer_>, %??LSLL_ForEach_ID) textequ GetMemBSS(@WordSize)
  else
    @CatStr(<??LSLL_ForEach_Pointer_>, %??LSLL_ForEach_ID) textequ <IndexReg>
  endif
  mov xax, pFirstMember
  .while xax != NULL 
    mov @CatStr(<??LSLL_ForEach_Pointer_>, %??LSLL_ForEach_ID), xax
endm

; --------------------------------------------------------------------------------------------------
; Macro:      .LSLL_Next
; Purpose:    Move to the next list item.
; Arguments:  None
; Return:     Nothing.

.LSLL_Next macro
    if opattr(@CatStr(<??LSLL_ForEach_Pointer_>, %??LSLL_ForEach_ID)) & OAT_REGISTER
      mov xax, [@CatStr(<??LSLL_ForEach_Pointer_>, %??LSLL_ForEach_ID)].LDLL_MEMBER.pLinkFwrd
    else
      mov xax, @CatStr(<??LSLL_ForEach_Pointer_>, %??LSLL_ForEach_ID)
      mov xax, [xax].LDLL_MEMBER.pLinkFwrd
    endif
  .endw
  ??LSLL_ForEach_ID = ??LSLL_ForEach_ID - 1
endm
