; ==================================================================================================
; Title:      LinkedList.inc
; Author:     G. Friedrich, Homer, K. Liebenau, HSE
; Version:    C.1.0
; Purpose:    ObjAsm support of Linear Doubly Linked List (LDLL) objects.
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


; This structure describes the Nodes stored in the LinkedList. Each Node contains a pointer to the
; next and previous Nodes, and also contains a pointer to some object owned by the node.

PLINKED_NODE typedef ptr LINKED_NODE
LINKED_NODE struc
	pLinkFwrd   PLINKED_NODE  ?   ;-> Next Node
	pLinkBack   PLINKED_NODE  ?   ;-> Previous Node
 	pObject     POINTER       ?   ;-> Payload object
LINKED_NODE ends


; --------------------------------------------------------------------------------------------------
; Object:     LinkedList
; Purpose:    Implement a Linear Doubly Linked List (LDLL) of nodes, that contains a POINTER to a
;             payload object.
;
;                          (NULL)
;                            ^
;                            |
;             FirstNode --> Node0 --> Object0
;                            ^ |
;                            | V
;                           Node1 --> Object1
;                            ^ |
;                            | V                        ^  Backward
;                                                       |
;                             .
;                             .
;                             .                         |
;                                                       V  Forward
;                            ^ |
;                            | V
;              LastNode --> NodeN --> ObjectN
;                              |
;                              V
;                            (NULL)


Object LinkedList, LinkedListID, Primer
  VirtualMethod   Append,           POINTER
  VirtualMethod   Clear
  VirtualMethod   Delete,           POINTER
  VirtualMethod   Dispose,          POINTER
  RedefineMethod  Done
  VirtualMethod   GetFirst
  VirtualMethod   GetLast
  VirtualMethod   GetNext
  VirtualMethod   GetNth,           DWORD
  VirtualMethod   GetPrev
  VirtualMethod   InsertAfter,      POINTER, POINTER

  Private
  VirtualMethod   GetNodeByObject,  POINTER

  DefineVariable  pFirstNode,       PLINKED_NODE,  NULL    ;First Node in the chain
  DefineVariable  pLastNode,        PLINKED_NODE,  NULL    ;Last Node in the chain
  DefineVariable  pCurrentNode,     PLINKED_NODE,  NULL    ;Iteration pointer for walking the nodes
  DefineVariable  dCount,           DWORD,         0
ObjectEnd


; ==================================================================================================

if IMPLEMENT

; --------------------------------------------------------------------------------------------------
; Method:     LinkedList.Append
; Purpose:    Append a new object to the end of the Linked List.
; Arguments:  Arg1: -> object to add.
; Return:     xax -> new node or NULL, if allocation failed.

Method LinkedList.Append,, pObject:POINTER
  MemAlloc sizeof LINKED_NODE                           ;Allocate a new LINKED_NODE struc
  SetObject xcx
  .if xax != NULL
    inc [xcx].dCount                                    ;Increment the node count
    m2m [xax].LINKED_NODE.pObject, pObject, xdx         ;Store ptr to payload Object
    xor edx, edx
    mov [xax].LINKED_NODE.pLinkFwrd, xdx
    .if [xcx].pFirstNode == NULL                        ;If there's no first node in the list
      mov [xcx].pFirstNode, xax                         ;  then this will be the first node
    .else                                               ;  else if there's already a first node
      mov xdx, [xcx].pLastNode                          ;    fetch the last node
      mov [xdx].LINKED_NODE.pLinkFwrd, xax              ;    point fwd from old node to new node
    .endif
    mov [xax].LINKED_NODE.pLinkBack, xdx                ;Point back from new node to old last node
    mov [xcx].pLastNode, xax                            ;We just made a new last node
  .else                                                 ;Return -> node
    OCall xcx.ErrorReport, NULL, LLT_OUT_OF_MEMORY
    xor eax, eax                                        ;Return NULL
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     LinkedList.Clear
; Purpose:    Destroy all stored objects and free all allocated resources.
; Arguments:  None.
; Return:     Nothing.

Method LinkedList.Clear, uses xbx xsi
  SetObject xcx
  mov xsi, [xcx].pFirstNode
  mov [xcx].dCount, 0
  mov [xcx].pFirstNode, NULL
  mov [xcx].pLastNode, NULL
  mov [xcx].pCurrentNode, NULL
  .while xsi != NULL
    Destroy [xsi].LINKED_NODE.pObject::OA:Primer.Done   ;Save dispose of linked Object
    mov xbx, [xsi].LINKED_NODE.pLinkFwrd                ;Preserve address of next node
    MemFree xsi                                         ;Free the linked node
    mov xsi, xbx                                        ;Restore address of next node
  .endw
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     LinkedList.Delete
; Purpose:    Remove an object from the linked list.
; Arguments:  Arg1: -> Object to remove.
; Return:     xax -> Object.

Method LinkedList.Delete, uses xbx, pObject:POINTER
  ;Fetch the linked node containing pObject
  .if $OCall(GetNodeByObject, pObject) != NULL
    SetObject xcx
    dec [xcx].dCount                                    ;Decrement the node count

    ;If we are deleting first node, make the next node be first node
    .if xax == [xcx].pFirstNode
      m2m [xcx].pFirstNode, [xax].LINKED_NODE.pLinkFwrd, xdx
    .endif

    ;If we are deleting current node, make the next node be current node
    .if xax == [xcx].pCurrentNode
      m2m [xcx].pCurrentNode, [xax].LINKED_NODE.pLinkFwrd, xdx
    .endif

    ;If we are deleting last node, the Last node is the previous
    .if xax == [xcx].pLastNode
      m2m [xcx].pLastNode, [xax].LINKED_NODE.pLinkBack, xdx
    .endif

    ReleaseObject

    ;If this node had a parent, patch the parent's link
    .if [xax].LINKED_NODE.pLinkBack != NULL
      mov xcx, [xax].LINKED_NODE.pLinkBack
      m2m [xcx].LINKED_NODE.pLinkFwrd, [xax].LINKED_NODE.pLinkFwrd, xdx
    .endif

    ;If this node had a child, patch the child's link
    .if [xax].LINKED_NODE.pLinkFwrd != NULL
      mov xcx, [xax].LINKED_NODE.pLinkFwrd
      m2m [xcx].LINKED_NODE.pLinkBack, [xax].LINKED_NODE.pLinkBack, xdx
    .endif

    ;Free its node
    mov xbx, [xax].LINKED_NODE.pObject
    MemFree xax
    mov xax, xbx                                        ;Return xax -> Object
  .else
    xor eax, eax
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     LinkedList.Dispose
; Purpose:    Dispose an object from the linked list.
; Arguments:  Arg1: -> Object to dispose.
; Return:     Nothing.

Method LinkedList.Dispose,, pObject:POINTER
  OCall Delete, pObject
  Destroy xax                                           ;Safe dispose of linked Object
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     LinkedList.Done
; Purpose:    Finalize the LinkedList object, destroy all stored objects and free all allocated
;             resources.
; Arguments:  None.
; Return:     Nothing.

Method LinkedList.Done
  OCall Clear
  ACall Done
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     LinkedList.GetFirst
; Purpose:    Return the first object in the chain.
; Arguments:  None.
; Return:     xax -> object or NULL if the Linked List is empty.

Method LinkedList.GetFirst
  SetObject xdx
  mov xcx, [xdx].pFirstNode                             ;Starting with the first node
  .if xcx == NULL                                       ;Check for NULL 1st node (no content in LL)
    mov xax, xcx                                        ;Returns eax = NULL, ecx = NULL
  .else
    mov xax, [xcx].LINKED_NODE.pObject                  ;Returns xax -> Object, xcx -> Node
  .endif
  mov [xdx].pCurrentNode, xcx
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     LinkedList.GetLast
; Purpose:    Return the last object in the chain.
; Arguments:  None.
; Return:     xax -> object or NULL, if the Linked List is empty.

Method LinkedList.GetLast
  SetObject xdx
  mov xcx, [xdx].pLastNode                              ;Starting with the first node
  .if xcx == NULL                                       ;check for NULL first node (no content in LL)
    mov xax, xcx                                        ;Returns xax = NULL, xcx = NULL
  .else
    mov xax, [xcx].LINKED_NODE.pObject                  ;Returns xax -> Object, xcx -> Node
  .endif
  mov [xdx].pCurrentNode, xcx
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     LinkedList.GetNext
; Purpose:    Return the next object in the chain.
; Arguments:  None.
; Return:     xax -> Object.
;             xcx -> Node or NULL if an error occurs.

Method LinkedList.GetNext
  SetObject xax
  mov xcx, [xax].pCurrentNode                           ;Starting with the current node
  .if xcx != NULL
    mov xcx, [xcx].LINKED_NODE.pLinkFwrd                ;Increment the current node
    mov [xax].pCurrentNode, xcx                         ;Set up the incremented current node
    .if xcx == NULL
      mov xax, xcx                                      ;Returns eax = NULL, ecx = NULL
    .else
      mov xax, [xcx].LINKED_NODE.pObject                ;Returns eax -> Object, ecx -> Node
    .endif
  .else
    OCall xax.ErrorReport, NULL, LLT_INDEX_ERROR
    xor eax, eax
    xor ecx, ecx                                        ;Return NULL
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     LinkedList.GetNodeByObject
; Purpose:    Return a pointer to the node that points to a specified object.
; Arguments:  Arg1: -> Object.
; Return:     xax -> Node or NULL if the object could not be found.
;             xcx -> Object.

Method LinkedList.GetNodeByObject,, pObject:POINTER
  SetObject xdx
  .if [xdx].pFirstNode != NULL
    mov xax, [xdx].pFirstNode
    mov xcx, pObject
    .while xax != NULL
      .if xcx == [xax].LINKED_NODE.pObject
        ExitMethod
      .endif
      mov xax, [xax].LINKED_NODE.pLinkFwrd
    .endw                                               ;Returns NULL, not found!
  .else
    xor eax, eax
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     LinkedList.GetNth
; Purpose:    Return the Nth object in the chain.
; Arguments:  Arg1: Index in the range [0.. Count-1]
; Return:     xax -> Object.
;             xcx -> Node or NULL if an error occurs.

Method LinkedList.GetNth,, dIndex:DWORD         ;dIndex = [0..Count-1]
  SetObject xcx
  mov eax, dIndex
  .if eax < [xcx].dCount
    mov xcx, [xcx].pFirstNode                           ;Starting with the first node
    ReleaseObject
    .while eax != 0 && xcx != NULL
      mov xcx, [xcx].LINKED_NODE.pLinkFwrd
      dec eax
    .endw
    mov xax, [xcx].LINKED_NODE.pObject                  ;Returns xax -> Object, xcx -> Node
  .else
    OCall xcx::LinkedList.ErrorReport, NULL, LLT_INDEX_ERROR
    xor eax, eax
    xor ecx, ecx                                        ;Return NULL
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     LinkedList.GetPrev
; Purpose:    Return the previous object in the chain.
; Arguments:  None.
; Return:     eax -> Object.
;             ecx -> Node or NULL if an error occurs.

Method LinkedList.GetPrev
  SetObject xax
  mov xcx, [xax].pCurrentNode                           ;Starting with the current node
  .if xcx != NULL
    mov xcx, [xcx].LINKED_NODE.pLinkBack                ;Decrement the current node
    mov [xax].pCurrentNode, xcx                         ;Set up the decremented current node
    ReleaseObject
    .if xcx == NULL
      mov xax, xcx                                      ;Returns xax = NULL, xcx = NULL
    .else
      mov xax, [xax].LINKED_NODE.pObject                ;Returns xax -> Object, xcx -> Node
    .endif
  .else
    OCall xax::LinkedList.ErrorReport, NULL, LLT_INDEX_ERROR
    xor eax, eax
    xor ecx, ecx                                        ;Return NULL
  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     LinkedList.InsertAfter
; Purpose:    Insert an object after another in the linked list chain.
; Arguments:  Arg1: -> Object to insert after.
;             Arg2: -> Object to insert.
; Return:     xax -> Node or NULL if the object could not be found.

Method LinkedList.InsertAfter, uses xbx xsi, pRefObject:POINTER, pNewObject:POINTER
  SetObject xsi

  ; Try to find the LINKED_NODE which owns the object we wish to insert behind.
  ; If this returns NULL, then pRefObject isn't stored in the List
  ; Otherwise it returns a ptr to the LINKED_NODE containing pRefObject
  ; which we want to manipulate.
  OCall xsi.GetNodeByObject, pRefObject
  .if xax != NULL
    mov xbx, xax
    MemAlloc sizeof LINKED_NODE                         ;Allocate a new LINKED_NODE struc
    mov xdx, xbx
    .if xax != NULL
      m2m [xax].LINKED_NODE.pObject, pNewObject, xcx
      inc [xsi].dCount                                  ;Increment the node count
      mov xcx, [xdx].LINKED_NODE.pLinkFwrd              ;xcx -> old Child
      mov [xdx].LINKED_NODE.pLinkFwrd, xax              ;Link Parent forward to this node
      mov [xax].LINKED_NODE.pLinkBack, xdx              ;Link this node back to Parent
      mov [xax].LINKED_NODE.pLinkFwrd, xcx              ;Link this node forward to old child
      .if xcx == NULL                                   ;Last node?
        mov [xsi].pLastNode, xax                        ;Make this node the new last node
      .else
        mov [xcx].LINKED_NODE.pLinkBack, xax            ;Link old Child back to this node
      .endif
    .else
      OCall xsi.ErrorReport, NULL, LLT_OUT_OF_MEMORY
      xor eax, eax                                      ;Return NULL (out of memory)
    .endif
  .else
    xor eax, eax                                        ;Return NULL (not found)
  .endif
MethodEnd

endif
