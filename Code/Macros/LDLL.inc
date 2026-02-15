; ==================================================================================================
; Title:      LDLL.inc
; Author:     G. Friedrich
; Version:    C.1.1
; Purpose:    ObjAsm support of "Linear Doubly Linked List" macros.
; Notes:      No sanity checks are performed by this set of macros!
;             Version C.1.0, October 2017
;               - First release.
;             Version C.1.1, January 2023
;               - .ListForEach/.ListNext and ListForEachRev/.ListPrev macros added. 
; ==================================================================================================


;This structure describes the members stored in the "Linear Doubly Linked List".
;Each member contains a pointer to the next and previous members.
;
;                     (NULL)
;                       ^
;                       |
;   FirstMember -> LDLL_MEMBER_0
;                       ^ |
;                       | V
;                  LDLL_MEMBER_1
;                       ^ |                    ^  Backward
;                       | V                    |
;
;                        .
;                        .                     |
;                        .                     V  Forward
;
;                       ^ |
;                       | V
;    LastMember -> LDLL_MEMBER_N
;                         |
;                         V
;                       (NULL)
;


; ==================================================================================================

PLDLL_MEMBER typedef ptr LDLL_MEMBER
LDLL_MEMBER struc
  pLinkFwrd     PLDLL_MEMBER  ?                         ;-> Next member
  pLinkBack     PLDLL_MEMBER  ?                         ;-> Previous member
LDLL_MEMBER ends

PLDLL_CONTROL typedef ptr LDLL_CONTROL
LDLL_CONTROL struc                                      ;AKA List Head
  pFirstMember  PLDLL_MEMBER  ?                         ;-> First member
  pLastMember   PLDLL_MEMBER  ?                         ;-> Last member
LDLL_CONTROL ends

; ==================================================================================================


; --------------------------------------------------------------------------------------------------
; Macro:      LDLL_InsertAfter
; Purpose:    Insert an object after another in the linked list.
; Arguments:  Arg1: -> Control structure or reference.
;             Arg2: -> Member to insert after.
;             Arg3: -> Member to insert.
;             Arg4: Auxiliar register, default is xdx.

LDLL_InsertAfter macro CtlReg:req, RefReg:req, NewReg:req, AuxReg:=<xdx>
  mov AuxReg, [RefReg].LDLL_MEMBER.pLinkFwrd            ;;AuxReg -> old Child
  mov [RefReg].LDLL_MEMBER.pLinkFwrd, NewReg            ;;Link parent forward to this member
  mov [NewReg].LDLL_MEMBER.pLinkBack, RefReg            ;;Link this member back to parent member
  mov [NewReg].LDLL_MEMBER.pLinkFwrd, AuxReg            ;;Link this member forward to old child
  .if AuxReg != NULL                                    ;;Last member?
    mov [AuxReg].LDLL_MEMBER.pLinkBack, NewReg          ;;Link old child back to this member
  .else
    mov [CtlReg].LDLL_CONTROL.pLastMember, NewReg       ;;Make this member the new last member
  .endif
endm

; --------------------------------------------------------------------------------------------------
; Macro:      LDLL_InsertBefore
; Purpose:    Insert an object before another in the linked list.
; Arguments:  Arg1: -> Control structure or reference.
;             Arg2: -> Member to insert before.
;             Arg3: -> Member to insert.
;             Arg4: Auxiliar register, default is xdx.

LDLL_InsertBefore macro CtlReg:req, RefReg:req, NewReg:req, AuxReg:=<xdx>
  mov AuxReg, [RefReg].LDLL_MEMBER.pLinkBack            ;;AuxReg -> old Child
  mov [RefReg].LDLL_MEMBER.pLinkBack, NewReg            ;;Link parent forward to this member
  mov [NewReg].LDLL_MEMBER.pLinkFwrd, RefReg            ;;Link this member back to parent member
  mov [NewReg].LDLL_MEMBER.pLinkBack, AuxReg            ;;Link this member forward to old child
  .if AuxReg != NULL                                    ;;First member?
    mov [AuxReg].LDLL_MEMBER.pLinkFwrd, NewReg          ;;Link old child back to this member
  .else
    mov [CtlReg].LDLL_CONTROL.pFirstMember, NewReg      ;;Make this member the new last member
  .endif
endm

; --------------------------------------------------------------------------------------------------
; Macro:      LinkedList_InsertFirst
; Purpose:    Insert a new member to the end of the Linked List.
; Arguments:  Arg1: -> Control structure or reference.
;             Arg2: -> Member to insert.
;             Arg3: Auxiliar register, default is xdx.

LDLL_InsertFirst macro CtlReg:req, NewReg:req, AuxReg:=<xdx>
  m2z [NewReg].LDLL_MEMBER.pLinkBack                    ;;Set back link to NULL
  .if [CtlReg].LDLL_CONTROL.pFirstMember == NULL        ;;If it is no first member in the list
    mov [CtlReg].LDLL_CONTROL.pLastMember, NewReg       ;;This will be the last member
    m2z [NewReg].LDLL_MEMBER.pLinkFwrd                  ;;Set forward link to NULL
  .else
    mov AuxReg, [CtlReg].LDLL_CONTROL.pFirstMember      ;;Fetch the first member
    mov [AuxReg].LDLL_MEMBER.pLinkBack, NewReg          ;;Set the back link
    mov [NewReg].LDLL_MEMBER.pLinkFwrd, AuxReg          ;;-> fwrd from new member to old 1st member
  .endif
  mov [CtlReg].LDLL_CONTROL.pFirstMember, NewReg        ;;We just made a new first member
endm

; --------------------------------------------------------------------------------------------------
; Macro:      LinkedList_InsertLast
; Purpose:    Insert a new member to the end of the Linked List.
; Arguments:  Arg1: -> Control structure or reference.
;             Arg2: -> Member to insert.
;             Arg3: Auxiliar register, default is xdx.

LDLL_InsertLast macro CtlReg:req, NewReg:req, AuxReg:=<xdx>
  m2z [NewReg].LDLL_MEMBER.pLinkFwrd                    ;;Set forward link to NULL
  .if [CtlReg].LDLL_CONTROL.pLastMember == NULL         ;;If it is no last member in the list
    mov [CtlReg].LDLL_CONTROL.pFirstMember, NewReg      ;;This will be the last member
    m2z [NewReg].LDLL_MEMBER.pLinkBack                  ;;Set back link to NULL
  .else                                                 ;;  else if there is already a last member
    mov AuxReg, [CtlReg].LDLL_CONTROL.pLastMember       ;;Fetch the last member
    mov [AuxReg].LDLL_MEMBER.pLinkFwrd, NewReg          ;;Set the forward link
    mov [NewReg].LDLL_MEMBER.pLinkBack, AuxReg          ;;-> back from new member to old last member
  .endif
  mov [CtlReg].LDLL_CONTROL.pLastMember, NewReg         ;;We just made a new last member
endm

LDLL_Append equ LDLL_InsertLast

; --------------------------------------------------------------------------------------------------
; Macro:      LDLL_Remove
; Purpose:    Remove a member from the linked list.
; Arguments:  Arg1: -> Control structure or reference.
;             Arg2: -> Member to remove.
;             Arg3: Auxiliar register, default is rcx.
;             Arg4: Optional auxiliar register.

LDLL_Remove macro CtlReg:req, RefReg:req, AuxReg1:=<xcx>, AuxReg2:=<>
  mov AuxReg1, [RefReg].LDLL_MEMBER.pLinkFwrd
  ;;If we are removing the first member, make the next member be first member
  cmp RefReg, [CtlReg].LDLL_CONTROL.pFirstMember
  ht                                                    ;Hint taken
  jnz @F
  mov [CtlReg].LDLL_CONTROL.pFirstMember, AuxReg1

  @@:
  ;;If this member has a next member, patch its link
  or AuxReg1, AuxReg1
  jz @F
  m2m [AuxReg1].LDLL_MEMBER.pLinkBack, [RefReg].LDLL_MEMBER.pLinkBack, AuxReg2

  @@:
  mov AuxReg1, [RefReg].LDLL_MEMBER.pLinkBack
  ;;If we are removing the last member, the last member is the previous member
  cmp RefReg, [CtlReg].LDLL_CONTROL.pLastMember
  ht                                                    ;Hint taken
  jnz @F
  m2m [CtlReg].LDLL_CONTROL.pLastMember, [RefReg].LDLL_MEMBER.pLinkBack, AuxReg1

  @@:
  ;;If this member has a previous member, patch its link
  or AuxReg1, AuxReg1
  jz @F
  m2m [AuxReg1].LDLL_MEMBER.pLinkFwrd, [RefReg].LDLL_MEMBER.pLinkFwrd, AuxReg2
  @@:
endm

; --------------------------------------------------------------------------------------------------
; Macro:      LDLL_RemoveFirst
; Purpose:    Remove the first member from the linked list.
; Arguments:  Arg1: -> Control structure or reference.
;             Arg2: Auxiliar register

LDLL_RemoveFirst macro CtlReg:req, AuxReg1:req
  mov AuxReg1, [CtlReg].LDLL_CONTROL.pFirstMember
  .if AuxReg1 == [CtlReg].LDLL_CONTROL.pLastMember
    m2z [CtlReg].LDLL_CONTROL.pFirstMember
    m2z [CtlReg].LDLL_CONTROL.pLastMember
  .else
    mov AuxReg1, [AuxReg1].LDLL_MEMBER.pLinkFwrd
    m2z [AuxReg1].LDLL_MEMBER.pLinkBack
    mov [CtlReg].LDLL_CONTROL.pFirstMember, AuxReg1
  .endif
endm

; --------------------------------------------------------------------------------------------------
; Macro:      LDLL_RemoveLast
; Purpose:    Remove the last member from the linked list.
; Arguments:  Arg1: -> Control structure or reference.
;             Arg2: Auxiliar register

LDLL_RemoveLast macro CtlReg:req, AuxReg1:req
  mov AuxReg1, [CtlReg].LDLL_CONTROL.pLastMember
  .if AuxReg1 == [CtlReg].LDLL_CONTROL.pFirstMember
    m2z [CtlReg].LDLL_CONTROL.pFirstMember
    m2z [CtlReg].LDLL_CONTROL.pLastMember
  .else
    mov AuxReg1, [AuxReg1].LDLL_MEMBER.pLinkBack
    m2z [AuxReg1].LDLL_MEMBER.pLinkFwrd
    mov [CtlReg].LDLL_CONTROL.pLastMember, AuxReg1
  .endif
endm


??ListForEach_ID = 0

; --------------------------------------------------------------------------------------------------
; Macro:      .LDLL_ForEach
; Purpose:    Loop through all items of the list.
; Arguments:  Arg1: First member of the list.
;             Arg2: Optional POINTER variable/register. Can not be xax!
; Return:     Nothing.
; Note:       On each loop xax -> LDLL_ item.
; Example:    .LDLL_ForEach MyList
;               DbgHex [xax].$Obj(Primer).pOwner
;             .LDLL_Next

.LDLL_ForEach macro pFirstMember:req, IndexReg
  ??LDLL_ForEach_ID = ??LDLL_ForEach_ID + 1
  ifb <IndexReg>
    @CatStr(<??LDLL_ForEach_Pointer_>, %??LDLL_ForEach_ID) textequ GetMemBSS(@WordSize)
  else
    @CatStr(<??LDLL_ForEach_Pointer_>, %??LDLL_ForEach_ID) textequ <IndexReg>
  endif
  mov xax, pFirstMember
  .while xax != NULL 
    mov @CatStr(<??LDLL_ForEach_Pointer_>, %??LDLL_ForEach_ID), xax
endm

; --------------------------------------------------------------------------------------------------
; Macro:      .LDLL_Next
; Purpose:    Move to the next list item.
; Arguments:  None
; Return:     Nothing.

.LDLL_Next macro
    if opattr(@CatStr(<??LDLL_ForEach_Pointer_>, %??LDLL_ForEach_ID)) & OAT_REGISTER
      mov xax, [@CatStr(<??LDLL_ForEach_Pointer_>, %??LDLL_ForEach_ID)].LDLL_MEMBER.pLinkFwrd
    else
      mov xax, @CatStr(<??LDLL_ForEach_Pointer_>, %??LDLL_ForEach_ID)
      mov xax, [xax].LDLL_MEMBER.pLinkFwrd
    endif
  .endw
  ??LDLL_ForEach_ID = ??LDLL_ForEach_ID - 1
endm

; --------------------------------------------------------------------------------------------------
; Macro:      .LDLL_ForEachRev
; Purpose:    Loop through all items of the list in reverse order.
; Arguments:  Arg1: Last member of the list.
;             Arg2: Optional POINTER variable/register. Can not be xax!
; Return:     Nothing.
; Note:       On each loop xax -> List item.
; Example:    .LDLL_ForEachRev MyList
;               DbgHex [xax].$Obj(Primer).pOwner
;             .LDLL_Prev

.LDLL_ForEachRev macro pLastMember:req, IndexReg
  ??LDLL_ForEach_ID = ??LDLL_ForEach_ID + 1
  ifb <IndexReg>
    @CatStr(<??LDLL_ForEach_Pointer_>, %??LDLL_ForEach_ID) textequ GetMemBSS(@WordSize)
  else
    @CatStr(<??LDLL_ForEach_Pointer_>, %??LDLL_ForEach_ID) textequ <IndexReg>
  endif
  mov xax, pLastMember
  .while xax != NULL 
    mov @CatStr(<??LDLL_ForEach_Pointer_>, %??LDLL_ForEach_ID), xax
endm

; --------------------------------------------------------------------------------------------------
; Macro:      .LDLL_Prev
; Purpose:    Move to the next List item.
; Arguments:  None
; Return:     Nothing.

.LDLL_Prev macro
    if opattr(@CatStr(<??LDLL_ForEach_Pointer_>, %??LDLL_ForEach_ID)) & OAT_REGISTER
      mov xax, [@CatStr(<??LDLL_ForEach_Pointer_>, %??LDLL_ForEach_ID)].LDLL_MEMBER.pLinkBack
    else
      mov xax, @CatStr(<??LDLL_ForEach_Pointer_>, %??LDLL_ForEach_ID)
      mov xax, [xax].LDLL_MEMBER.pLinkBack
    endif
  .endw
  ??LDLL_ForEach_ID = ??LDLL_ForEach_ID - 1
endm
