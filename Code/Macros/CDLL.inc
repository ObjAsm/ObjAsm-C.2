; ==================================================================================================
; Title:      CDLL.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm support of "Circular Doubly Linked List" macros.
; Notes:      No sanity checks are performed by this set of macros!
;             Version C.1.0, October 2017
;             - First release.
; ==================================================================================================


;This structure describes the members stored in the "Circular Doubly Linked List".
;Each member contains a pointer to the next and previous members.
;
;
;                        ----------------
;                       |  ------------  |
;                       | |            | |
;                       | V            | |
;   FirstMember -> CDLL_MEMBER_0       | |
;                       ^ |            | |
;                       | V            | |
;                  CDLL_MEMBER_1       | |
;                       ^ |            | |
;                       | V            | |
;                                      | |
;                        .             | |
;                        .             | |
;                        .             | |
;                                      | |
;                       ^ |            | |
;                       | V            | |
;                  CDLL_MEMBER_N       | |
;                       ^ |            | |
;                       |  ------------  |
;                        ----------------
;


; ==================================================================================================


PCDLL_MEMBER typedef ptr CDLL_MEMBER
CDLL_MEMBER struc
  pLinkFwrd     PCDLL_MEMBER    ?                       ;-> Next member
  pLinkBack     PCDLL_MEMBER    ?                       ;-> Previous member
CDLL_MEMBER ends

CDLL_CONTROL struc
  pFirstMember  PCDLL_MEMBER    ?                       ;-> First member
CDLL_CONTROL ends
PCDLL_CONTROL typedef ptr CDLL_CONTROL

; ==================================================================================================


; --------------------------------------------------------------------------------------------------
; Macro:      CDLL_InsertAfter
; Purpose:    Insert an object after another in the linked list.
; Arguments:  Arg1: -> Member to insert after.
;             Arg2: -> Member to insert.
;             Arg3: Auxiliar register, default is rdx.

CDLL_InsertAfter macro RefReg:req, NewReg:req, AuxReg:=<xdx>
  mov AuxReg, [RefReg].CDLL_MEMBER.pLinkFwrd
  mov [RefReg].CDLL_MEMBER.pLinkFwrd, NewReg
  mov [NewReg].CDLL_MEMBER.pLinkBack, RefReg
  mov [NewReg].CDLL_MEMBER.pLinkFwrd, AuxReg
  mov [AuxReg].CDLL_MEMBER.pLinkBack, NewReg
endm

; --------------------------------------------------------------------------------------------------
; Macro:      CDLL_InsertBefore
; Purpose:    Insert an object before another in the linked list.
; Arguments:  Arg1: -> Member to insert before.
;             Arg2: -> Member to insert.
;             Arg3: Auxiliar register, default is rdx.

CDLL_InsertBefore macro RefReg:req, NewReg:req, AuxReg:=<xdx>
  mov AuxReg, [RefReg].CDLL_MEMBER.pLinkBack
  mov [RefReg].CDLL_MEMBER.pLinkBack, NewReg
  mov [NewReg].CDLL_MEMBER.pLinkFwrd, RefReg
  mov [NewReg].CDLL_MEMBER.pLinkBack, AuxReg
  mov [AuxReg].CDLL_MEMBER.pLinkFwrd, NewReg
endm

; --------------------------------------------------------------------------------------------------
; Macro:      LinkedList_InsertFirst
; Purpose:    Insert a new member to the end of the Linked List.
; Arguments:  Arg1: -> Control structure or reference.
;             Arg2: -> Member to insert.
;             Arg3: Auxiliar register, default is rdx.
;             Arg4: Optional auxiliar register

CDLL_InsertFirst macro CtlReg:req, NewReg:req, AuxReg1:=<xdx>, AuxReg2:=<>
  .if [CtlReg].pFirstMember == NULL
    mov [NewReg].CDLL_MEMBER.pLinkFwrd, NewReg
    mov [NewReg].CDLL_MEMBER.pLinkBack, NewReg
  .else
    ifb <AuxReg2>
      mov AuxReg1, [CtlReg].pFirstMember
      push [AuxReg1].CDLL_MEMBER.pLinkBack
      mov [AuxReg1].CDLL_MEMBER.pLinkBack, NewReg
      mov [NewReg1].CDLL_MEMBER.pLinkFwrd, AuxReg1
      pop AuxReg1
      mov [AuxReg1].CDLL_MEMBER.pLinkFwrd, NewReg
      mov [NewReg].CDLL_MEMBER.pLinkBack, AuxReg1
    else
      mov AuxReg1, [CtlReg].pFirstMember
      mov AuxReg2, [AuxReg1].CDLL_MEMBER.pLinkBack
      mov [AuxReg1].CDLL_MEMBER.pLinkBack, NewReg
      mov [NewReg1].CDLL_MEMBER.pLinkFwrd, AuxReg1
      mov [AuxReg2].CDLL_MEMBER.pLinkFwrd, NewReg
      mov [NewReg].CDLL_MEMBER.pLinkBack, AuxReg2
    endif
  .endif
  mov [CtlReg].pFirstMember, NewReg
endm

; --------------------------------------------------------------------------------------------------
; Macro:      LinkedList_InsertLast
; Purpose:    Insert a new member to the end of the Linked List.
; Arguments:  Arg1: -> Control structure or reference.
;             Arg2: -> Member to insert.
;             Arg3: Auxiliar register, default is rdx.
;             Arg4: Optional auxiliar register

CDLL_InsertLast macro CtlReg:req, NewReg:req, AuxReg1:=<xdx>, AusReg2:=<>
  .if [CtlReg].pFirstMember == NULL
    mov [NewReg].CDLL_MEMBER.pLinkFwrd, NewReg
    mov [NewReg].CDLL_MEMBER.pLinkBack, NewReg
    mov [CtlReg].pFirstMember, NewReg
  .else
    ifb <AuxReg2>
      mov AuxReg1, [CtlReg].pFirstMember
      push [AuxReg1].CDLL_MEMBER.pLinkBack
      mov [AuxReg1].CDLL_MEMBER.pLinkBack, NewReg
      mov [NewReg].CDLL_MEMBER.pLinkFwrd, AuxReg1
      pop AuxReg1
      mov [AuxReg1].CDLL_MEMBER.pLinkFwrd, NewReg
      mov [NewReg].CDLL_MEMBER.pLinkBack, AuxReg1
    else
      mov AuxReg1, [CtlReg].pFirstMember
      mov AusReg2, [AuxReg1].CDLL_MEMBER.pLinkBack
      mov [AuxReg1].CDLL_MEMBER.pLinkBack, NewReg
      mov [NewReg].CDLL_MEMBER.pLinkFwrd, AuxReg1
      mov [AuxReg2].CDLL_MEMBER.pLinkFwrd, NewReg
      mov [NewReg].CDLL_MEMBER.pLinkBack, AuxReg2
    endif
  .endif
endm

CDLL_Append equ CDLL_InsertLast

; --------------------------------------------------------------------------------------------------
; Macro:      CDLL_Remove
; Purpose:    Remove a member from the linked list.
;             If the removed item is the first, the second takes its place.
;             If the list does not contain any item, the pFirst pointer is set to NULL.
; Arguments:  Arg1: -> Control structure or reference.
;             Arg2: -> Member to remove.
;             Arg3: Auxiliar register, default is rcx.
;             Arg4: Auxiliar register, default is rdx.

CDLL_Remove macro CtlReg:req, RefReg:req, AuxReg1:=<xcx>, AuxReg2:=<xdx>
  mov AuxReg1, [RefReg].CDLL_MEMBER.pLinkFwrd
  .if RefReg == AuxReg1
    m2z [CtlReg].pFirstMember
  .else
    mov AuxReg2, [RefReg].CDLL_MEMBER.pLinkBack
    mov [AuxReg1].CDLL_MEMBER.pLinkBack, AuxReg2
    mov [AuxReg2].CDLL_MEMBER.pLinkFwrd, AuxReg1
    .if RefReg == [CtlReg].pFirstMember
      mov [CtlReg].pFirstMember, AuxReg1
    .endif
  .endif
endm

; --------------------------------------------------------------------------------------------------
; Macro:      CDLL_RemoveFirst
; Purpose:    Remove the first member from the linked list.
; Arguments:  Arg1: -> Control structure or reference.
;             Arg2: Auxiliar register.
;             Arg3: Auxiliar register.

CDLL_RemoveFirst macro CtlReg:req, AuxReg1:req, AuxReg2:req
  mov AuxReg1, [CtlReg].pFirstMember
  .if AuxReg1 == [AuxReg1].CDLL_MEMBER.pLinkFwrd
    m2z [CtlReg].pFirstMember
  .else
    mov AuxReg2, [AuxReg1].CDLL_MEMBER.pLinkBack
    mov AuxReg1, [AuxReg1].CDLL_MEMBER.pLinkFrwd
    mov [AuxReg1].CDLL_MEMBER.pLinkBack, AuxReg2
    mov [AuxReg2].CDLL_MEMBER.pLinkFwrd, AuxReg1
  .endif
endm

; --------------------------------------------------------------------------------------------------
; Macro:      CDLL_RemoveLast
; Purpose:    Remove the last member from the linked list.
; Arguments:  Arg1: -> Control structure or reference.
;             Arg2: Auxiliar register.
;             Arg3: Auxiliar register.

CDLL_RemoveLast macro CtlReg:req, AuxReg1:req, AuxReg2:req
  mov AuxReg1, [CtlReg].pFirstMember
  mov AuxReg2, [AuxReg1].CDLL_MEMBER.pLinkLast
  .if AuxReg2 == [AuxReg2].CDLL_MEMBER.pLinkFwrd
    m2z [CtlReg].pFirstMember
  .else
    mov AuxReg2, [AuxReg2].CDLL_MEMBER.pLinkBack
    mov [AuxReg1].CDLL_MEMBER.pLinkBack, AuxReg2
    mov [AuxReg2].CDLL_MEMBER.pLinkFwrd, AuxReg1
  .endif
endm
