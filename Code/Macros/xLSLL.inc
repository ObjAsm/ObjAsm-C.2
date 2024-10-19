; ==================================================================================================
; Title:      xLSLL.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm support of exlusive "Linear Simply Linked List" macros.
; Notes:      No sanity checks are performed by this set of macros!
;             Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


;This structure describes the members stored in the "Linear Simply Linked List".
;Each member contains a pointer to the next member.
;
;                             
;                        
;   FirstMember -> xLSLL_ITEM_0
;                        |
;                        V
;                  xLSLL_ITEM_1
;                        |
;                        V
;                        .
;                        .
;                        .
;        
;                        |
;                        V
;                  xLSLL_ITEM_N
;                        |
;                        V
;                      (NULL)
;


; ==================================================================================================

PxLSLL_ITEM typedef ptr xLSLL_ITEM
xLSLL_ITEM struc
  pLinkFwrd     PxLSLL_ITEM   ?                         ;-> Next member
xLSLL_ITEM ends

PxLSLL_Control typedef ptr xLSLL_Control
xLSLL_Control struc
  pFirstMember  PxLSLL_ITEM   ?                         ;-> First member
  dLock         DWORD         ?                         ;List lock     
xLSLL_Control ends

; ==================================================================================================


; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      xLSLL.InsertAfter
; Purpose:    Insert an object after another in the linked list.
; Arguments:  Arg1: -> Member to insert after.
;             Arg2: -> Member to insert.
;             Arg3: Auxiliar register.
; Note:       eax is trashed.

xLSLL_InsertAfter macro RefReg:req, NewReg:req, AuxReg:=<>
@@:
  mov AuxReg, 1
  xor eax, eax
  lock cmpxchg [RefReg].xLSLL_Control.dLock, AuxReg
  ht                                                    ;;Hint taken
  je @F
  invoke Sleep, 0
  jmp @B                                                ;;Keep spinning until the lock is released
@@:
  m2m [NewReg].xLSLL_ITEM.pLinkFwrd, [RefReg].xLSLL_ITEM.pLinkFwrd, AuxReg
  mov [RefReg].xLSLL_ITEM.pLinkFwrd, NewReg
  dec [RefReg].xLSLL_Control.dLock
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      xLSLL_RemoveAfter
; Purpose:    Remove a member from the linked list.
; Arguments:  Arg1: -> Member to remove after.
;             Arg2: Auxiliar register, default is ecx.
; Note:       eax is trashed.

xLSLL_RemoveAfter macro RefReg:req, AuxReg:=<rcx>
@@:
  mov AuxReg, 1
  xor eax, eax
  lock cmpxchg [RefReg].xLSLL_Control.dLock, AuxReg
  ht                                                    ;;Hint taken
  je @F
  invoke Sleep, 0
  jmp @B                                                ;;Keep spinning until the lock is released
@@:
  mov AuxReg, [RefReg].xLSLL_ITEM.pLinkFwrd
  m2m [RefReg].xLSLL_ITEM.pLinkFwrd, [AuxReg].xLSLL_ITEM.pLinkFwrd, AuxReg
  dec [RefReg].xLSLL_Control.dLock
endm
