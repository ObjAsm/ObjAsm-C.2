; ==================================================================================================
; Title:      RedBlackTree.inc
; Author:     G. Friedrich
; Version:    C.1.1
; Purpose:    ObjAsm support of red-black tree objects.
; Notes:      Version C.1.0, October 2017
;               - First release.
;             Version C.1.1 October 2019
;               - Changable color support added by HSE.
; ==================================================================================================


RBT_RED         equ   0
RBT_BLACK       equ   1

RBT_COLOR_BIT   equ   BIT00
RBT_RES1_BIT    equ   BIT30
RBT_RES2_BIT    equ   BIT31

RBT_TEST_NONE   equ   0
RBT_TEST_TRUE   equ   1       ;NOT FALSE
RBT_TEST_FALSE  equ   2       ;FALSE

PRBT_CALL typedef proto :XWORD, :XWORD

PRBT_NODE typedef ptr RBT_NODE
RBT_NODE struc
  pLeftNode     PRBT_NODE   ?
  pRightNode    PRBT_NODE   ?
  pParentNode   PRBT_NODE   ?
  dFlags        DWORD       ?
RBT_NODE ends

RBT_COLOR_RED   equ   $RGB(255,000,000)
RBT_COLOR_BLACK equ   $RGB(000,000,000)
RBT_COLOR_GREEN equ   $RGB(000,000,255)
RBT_COLOR_TEXT  equ   $RGB(170,170,170)

; 覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧
; Object:     RedBlackTree
; Purpose:    Implement a Red-Black binaray tree.
; Links:      http://www.cs.iupui.edu/~xkzou/teaching/CS580/Red-black_trees.ppt
;             http://en.wikipedia.org/wiki/Red-black_tree
;             http://en.wikipedia.org/wiki/Tree_traversal
;             http://en.wikipedia.org/wiki/Threaded_binary_tree
;             http://www.eternallyconfuzzled.com/tuts/datastructures/jsw_tut_rbtree.aspx
;             http://en.wikipedia.org/wiki/AA_tree
; Notes:      - RedBlackTree and descendants are thread safe using the ObjAsm multithreading
;               support.
;             - A red-black tree is a binary search tree where each node has a color attribute. The
;               value can be either red or black. In addition to the ordinary requirements imposed
;               on binary search trees, the following additional requirements apply to red-black
;               trees:
;               - A node is either red or black.
;               - The root is always black. (This rule is used in some definitions. Since the root
;                 can always be changed from red to black but not necessarily vice-versa this rule
;                 has little effect on analysis).
;               - All leaves are black.
;               - Both children of every red node are black.
;               - Every simple path from a given node to any of its descendant leaves contains the
;                 same number of black nodes.
;             - The keys used to compare the nodes must be unique. This implementation does NOT
;               support duplicate keys yielding to an error if such a node is tried to insert.
;             - In case of duplicate keys, a more complex key must be build to guarantee key
;               uniqueness.
;             - Nodes can be embedded into other structures or objects. The RB-Tree can handle this
;               situation using a node offset which is the number of bytes needed to add from the
;               hosting structure/object to the RBT_NODE.
;             - This implementation doesn't use a sentinel node. The POINTER to the sentinel node
;               is replaced by NULL and the logic is adjusted to it.
;
;
; Typical tree node structure
;
;                                     NULL
;                                      |
;                                      |
;                                     覧・
;                                    | 4 |     Root Node (always black)
;                                     覧・
;                                   /     \
;                                  /       \
;                                 /         \
;                           / ...             ... \
;             Parent Node  /                       \
;                         /                         \
;                       覧・                        覧・
;   Node with key = 2  | 2 |                       | 6 |
;                       覧・                        覧・
;                     /     \                     /     \
;         Left Node  /       \  Right Node       /       \
;                   /         \                 /         \
;                  /           \               /           \
;                覧・          覧・          覧・          覧・
;               | 1 |         | 3 |         | 5 |         | 7 |
;                覧・          覧・          覧・          覧・
;              /     \       /     \       /     \       /     \
;             /       \     /       \     /       \     /       \
;           NULL     NULL NULL     NULL NULL     NULL NULL     NULL    Leave Nodes (always black)
;

Object RedBlackTree, RedBlackTreeID, Streamable
  DynamicMethod     Compare,        POINTER, POINTER
  VirtualMethod     Delete,         POINTER
  VirtualMethod     DeleteAll
  VirtualMethod     Dispose,        POINTER
  VirtualMethod     DisposeAll
  VirtualMethod     Find,           POINTER
  VirtualMethod     FirstThat,      POINTER, XWORD, XWORD     ;-> Proc, 2x Parameters
  VirtualMethod     FirstThatNot,   POINTER, XWORD, XWORD     ;-> Proc, 2x Parameters
  VirtualMethod     ForEach,        POINTER, XWORD, XWORD     ;-> Proc, 2x Parameters
  VirtualMethod     ForEachRev,     POINTER, XWORD, XWORD     ;-> Proc, 2x Parameters
  VirtualMethod     GetFirst
  VirtualMethod     GetLast
  VirtualMethod     GetNext,        POINTER
  VirtualMethod     GetPrev,        POINTER
  RedefineMethod    Init,           POINTER, XWORD
  VirtualMethod     Insert,         POINTER
  VirtualMethod     LastThat,       POINTER, XWORD, XWORD     ;-> Proc, 2x Parameters
  VirtualMethod     LastThatNot,    POINTER, XWORD, XWORD     ;-> Proc, 2x Parameters

  DynamicMethod     GetItem,        $ObjPtr(Stream)           ;-> Stream
  DynamicMethod     PutItem,        $ObjPtr(Stream), POINTER  ;-> Stream, -> Item
  RedefineMethod    Load,           $ObjPtr(Stream), POINTER  ;-> Stream, -> Owner
  RedefineMethod    Store,          $ObjPtr(Stream)           ;-> Stream

  DefineVariable    xNodeOffset,    XWORD,        0           ;Offset from host object to node
  DefineVariable    pRootNode,      PRBT_NODE,    NULL
  DefineVariable    dCount,         DWORD,        0

  DefineVariable    ObjLock,        OBJECT_LOCK,  {}    ;Locking structure for multithreaded access

ObjectEnd


.code
; ==================================================================================================

if IMPLEMENT

; ==================================================================================================
;  Utility macros and procedures
; ==================================================================================================

; 覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧
; Procedure:  RedBlackTree_Show
; Purpose:    Debug procedure to display the tree structure.
; Arguments:  Arg1: Key offset into the object.
; Return:     Nothing.

if DEBUGGING
CStr DestWindow, "Red-Black Tree"

ShowRBSubtree proc uses xbx pNode:PRBT_NODE, dIndent:DWORD        ;xsi and xdi are passed from
  local bIndBuffer[100]:CHRA, bNumBuffer[100]:CHRA, dColor:DWORD  ;  RedBlackTree_Show proc

  mov xbx, pNode
  lea xax, bIndBuffer
  mov ecx, dIndent
  test ecx, ecx
  .while !ZERO?
    mov CHRA ptr [xax], " "
    inc xax
    dec ecx
  .endw
  m2z CHRA ptr [xax]

  .if [xbx].RBT_NODE.dFlags == RBT_RED
    mov dColor, RBT_COLOR_RED
  .elseif [xbx].RBT_NODE.dFlags == RBT_BLACK
    mov dColor, RBT_COLOR_BLACK
  .else
    mov dColor, RBT_COLOR_GREEN
  .endif

  invoke DbgOutTextA, addr bIndBuffer, dColor, DbgColorBackground, DBG_EFFECT_NORMAL, offset DestWindow
  invoke DbgOutTextA, $OfsCStrA("Object at address "), dColor, DbgColorBackground, DBG_EFFECT_NORMAL, offset DestWindow
  mov xdx, xbx
  sub xdx, [xsi].$Obj(RedBlackTree).xNodeOffset
  invoke xword2hexA, addr bNumBuffer, xdx
  invoke DbgOutTextA, addr bNumBuffer, dColor, DbgColorBackground, DBG_EFFECT_NORMAL, offset DestWindow
  invoke DbgOutTextA, $OfsCStrA($Esc(" =\] Key = ")), dColor, DbgColorBackground, DBG_EFFECT_NORMAL, offset DestWindow
  mov xdx, xbx
  sub xdx, [xsi].$Obj(RedBlackTree).xNodeOffset         ;Host object addr
  add xdx, xdi                                          ;Key addr
  invoke dword2decA, addr bNumBuffer, DWORD ptr [xdx]
  invoke DbgOutTextA, addr bNumBuffer, dColor, DbgColorBackground, DBG_EFFECT_NORMAL, offset DestWindow

;  invoke DbgOutTextA, $OfsCStrA(" parent "), dColor, DbgColorBackground, DBG_EFFECT_NORMAL, offset DestWindow
;  mov xcx, xbx
;  mov xdx, [xcx].RBT_NODE.pParentNode
;  .if xdx != NULL
;    sub xdx, [xsi].$Obj(RedBlackTree).xNodeOffset
;    add xdx, xdi
;    invoke dword2dec, addr bNumBuffer, DWORD ptr [xdx]
;    invoke DbgOutTextA, addr bNumBuffer, dColor, DbgColorBackground, DBG_EFFECT_NORMAL, offset DestWindow
;  .else
;    invoke DbgOutTextA, $OfsCStrA(" (NULL) "), dColor, DbgColorBackground, DBG_EFFECT_NORMAL, offset DestWindow
;  .endif

  invoke DbgOutTextA, offset bCRLF, dColor, DbgColorBackground, DBG_EFFECT_NORMAL, offset DestWindow

  add dIndent, 2

  .if xbx != NULL
    mov xax, [xbx].RBT_NODE.pLeftNode
    .if xax != NULL
      invoke ShowRBSubtree, xax, dIndent
    .else
      invoke DbgOutTextA, addr bIndBuffer, RBT_COLOR_TEXT, DbgColorBackground, DBG_EFFECT_NORMAL, offset DestWindow
      invoke DbgOutTextA, $OfsCStrA("  Null"), RBT_COLOR_TEXT, DbgColorBackground, DBG_EFFECT_NORMAL, offset DestWindow
      invoke DbgOutTextA, offset bCRLF, RBT_COLOR_TEXT, DbgColorBackground, DBG_EFFECT_NORMAL, offset DestWindow
    .endif
    mov xax, [xbx].RBT_NODE.pRightNode
    .if xax != NULL
      invoke ShowRBSubtree, xax, dIndent
    .else
      invoke DbgOutTextA, addr bIndBuffer, RBT_COLOR_TEXT, DbgColorBackground, DBG_EFFECT_NORMAL, offset DestWindow
      invoke DbgOutTextA, $OfsCStrA("  Null"), RBT_COLOR_TEXT, DbgColorBackground, DBG_EFFECT_NORMAL, offset DestWindow
      invoke DbgOutTextA, offset bCRLF, RBT_COLOR_TEXT, DbgColorBackground, DBG_EFFECT_NORMAL, offset DestWindow
    .endif
  .endif

  ret
ShowRBSubtree endp

RedBlackTree_Show proc uses xdi xsi pSelf:$ObjPtr(RedBlackTree), xKeyOffset:XWORD
  SetObject xsi, RedBlackTree                           ;xsi = pSelf, passed to ShowRBSubtree
  mov xdi, xKeyOffset                                   ;xdi = xKeyOffset, passed to ShowRBSubtree
  .if [xsi].dCount != 0
    invoke ShowRBSubtree, [xsi].pRootNode, 0
  .else
    DbgText "Tree is empty", offset DestWindow
  .endif
  DbgLine offset DestWindow
  ret
RedBlackTree_Show endp

endif

; 覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧
; Macro:      RedBlackTree_GetMax
; Purpose:    Return the node with the biggest key.
; Arguments:  xax -> Start node.
; Return:     xax -> Max node.
; Note:       Unpreserved registers: xdx

RedBlackTree_GetMax macro
  .repeat
    mov xdx, [xax].RBT_NODE.pRightNode
    .break .if xdx == NULL
    mov xax, xdx
  .until FALSE
endm

; 覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧
; Macro:      RedBlackTree_GetMin
; Purpose:    Return the node with the smallest key.
; Arguments:  xax -> Start node.
; Return:     xax -> Min node.
; Note:       Unpreserved registers: xdx

RedBlackTree_GetMin macro
  .repeat
    mov xdx, [xax].RBT_NODE.pLeftNode
    .break .if xdx == NULL
    mov xax, xdx
  .until FALSE
endm

; 覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧
; Macro:      RedBlackTree_RotateLeft
; Purpose:    Rotate the tree to the left around a specified node.
; Arguments:  Reg: -> Node.
; Return:     xax -> Node.
; Note:       Unpreserved registers: xcx, xdx

RedBlackTree_RotateLeft macro Reg:req
  mov xax, Reg
  mov xcx, [xax].RBT_NODE.pRightNode
  mrm [xax].RBT_NODE.pRightNode, [xcx].RBT_NODE.pLeftNode, xdx
  .if xdx != NULL
    mov [xdx].RBT_NODE.pParentNode, xax
  .endif

  mov xdx, [xax].RBT_NODE.pParentNode
  .if xcx != NULL
    mov [xcx].RBT_NODE.pParentNode, xdx
  .endif

  .if xdx != NULL
    .if xax == [xdx].RBT_NODE.pLeftNode
       mov [xdx].RBT_NODE.pLeftNode, xcx
    .else
       mov [xdx].RBT_NODE.pRightNode, xcx
    .endif
  .else
    mov [xsi].pRootNode, xcx
  .endif

  mov [xcx].RBT_NODE.pLeftNode, xax
  .if xax != NULL
    mov [xax].RBT_NODE.pParentNode, xcx
  .endif
endm

; 覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧
; Macro:      RedBlackTree_RotateRight
; Purpose:    Rotate the tree to the right around a specified node.
; Arguments:  Reg: -> Node.
; Return:     xax -> Node.
; Note:       Unpreserved registers: xcx, xdx

RedBlackTree_RotateRight macro Reg:req
  mov xax, Reg
  mov xcx, [xax].RBT_NODE.pLeftNode

  mrm [xax].RBT_NODE.pLeftNode, [xcx].RBT_NODE.pRightNode, xdx
  .if xdx != NULL
    mov [xdx].RBT_NODE.pParentNode, xax
  .endif

  mov xdx, [xax].RBT_NODE.pParentNode
  .if xcx != NULL
    mov [xcx].RBT_NODE.pParentNode, xdx
  .endif

  .if xdx != NULL
    .if xax == [xdx].RBT_NODE.pRightNode
      mov [xdx].RBT_NODE.pRightNode, xcx
    .else
      mov [xdx].RBT_NODE.pLeftNode, xcx
    .endif
  .else
    mov [xsi].pRootNode, xcx
  .endif

  mov [xcx].RBT_NODE.pRightNode, xax
  .if xax != NULL
    mov [xax].RBT_NODE.pParentNode, xcx
  .endif
endm

; 覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧
; Macro:      RedBlackTree_TraverseInOrder
; Purpose:    Macro used to traverse the tree in order (ascending or descending) and invoke a
;             function or callback procedure in an iterator method.
; Arguments:  Branch1/Branch2: Left/Right = forward in order, Right/Left = reverse in order.
;             TestType:
;               RBT_TEST_POSITIVE: no test is performed
;               RBT_TEST_TRUE: test eax != FALSE
;               RBT_TEST_FALSE: test eax == FALSE
; Note:       Uses xdi xsi

RedBlackTree_TraverseInOrder macro Branch1:req, Branch2:req, TestType:req
  SetObject xcx
  .if [xcx].dCount != 0
    mov xbx, pCallAddr
    mov xsi, [xcx].$Obj(RedBlackTree).xNodeOffset

    ;Start at the root node
    mov xdi, [xcx].pRootNode
    ReleaseObject xcx
    jmp @F

    .while xdi != NULL
      .while TRUE
        .if xdx == [xdi].RBT_NODE.p&Branch1&Node
          invoke PRBT_CALL ptr xbx, xArg1, xArg2
          if TestType eq RBT_TEST_TRUE
            test eax, eax
            jnz @@Found
          elseif TestType eq RBT_TEST_FALSE
            test eax, eax
            jz @@Found
          endif
          mov xdx, xdi
          .if [xdi].RBT_NODE.p&Branch2&Node == NULL
            mov xdi, [xdi].RBT_NODE.pParentNode
            .break
          .endif
          mov xdi, [xdi].RBT_NODE.p&Branch2&Node
          .continue

        .else
          .if xdx == [xdi].RBT_NODE.p&Branch2&Node
            mov xdx, xdi
            mov xdi, [xdi].RBT_NODE.pParentNode
            .break
          .endif
@@:
          .if [xdi].RBT_NODE.p&Branch1&Node == NULL
            invoke PRBT_CALL ptr xbx, xArg1, xArg2
            if TestType eq RBT_TEST_TRUE
              test eax, eax
              jnz @@Found
            elseif TestType eq RBT_TEST_FALSE
              test eax, eax
              jz @@Found
            endif
            mov xdx, xdi
            .if [xdi].RBT_NODE.p&Branch2&Node == NULL
              mov xdi, [xdi].RBT_NODE.pParentNode
              .break
            .endif
            mov xdi, [xdi].RBT_NODE.p&Branch2&Node
            .continue
          .endif
          mov xdx, xdi
          mov xdi, [xdi].RBT_NODE.p&Branch1&Node
        .endif
      .endw
    .endw

    if TestType ne RBT_TEST_NONE
    xor eax, eax                                      ;Not found => xax = NULL
    jmp @@Exit

@@Found:
    mov xax, xdi                                      ;Found node address
    sub xax, xsi                                      ;Subtract node offset, xax -> Object
    endif

@@Exit:

  if TestType ne RBT_TEST_NONE
  .else
    xor eax, eax                                      ;Not found => xax = NULL
  endif
  .endif
endm


; ==================================================================================================
;  RedBlackTree implementation
; ==================================================================================================

; 覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧
; Method:     RedBlackTree.Compare
; Purpose:    Compare 2 keys.
; Arguments:  Arg1: -> Object #1.
;             Arg2: -> Object #2.
; Return:     xax = Comparison result. Negative if Key2 > Key1,
;                   zero if equal and positive if Key1 > Key2.
; Note:       This method MUST be redefined or overridden to provide the correct comparison
;             mechanism for each case. Ascending or descending order can be achieved inverting
;             the sign of the result. The result MUST be in xax, not eax!

Method RedBlackTree.Compare,, pObject1:POINTER, pObject2:POINTER
  mov xax, pObject2
  sub xax, pObject1
MethodEnd

; 覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧
; Method:     RedBlackTree.Delete
; Purpose:    Delete a node from the tree.
; Arguments:  Arg1: -> Object.
; Return:     xax -> Deleted object.

Method RedBlackTree.Delete, uses xbx xdi xsi, pObject:POINTER
  local pNode:PRBT_NODE

  SetObject xsi
  mov xax, pObject
  .if xax != NULL
    add xax, [xsi].$Obj(RedBlackTree).xNodeOffset
    mov xdi, xax
    mov xdx, [xax].RBT_NODE.pLeftNode
    mov xcx, [xax].RBT_NODE.pRightNode
    .if xdx != NULL && xcx != NULL
      mov xax, xcx
      RedBlackTree_GetMin
    .endif

    mov xdx, [xax].RBT_NODE.pLeftNode
    .if xdx == NULL
      mov xdx, [xax].RBT_NODE.pRightNode
    .endif
    mov pNode, xdx

    mov xcx, [xax].RBT_NODE.pParentNode
    .if xdx != NULL
      mov [xdx].RBT_NODE.pParentNode, xcx
    .endif
    .if xcx != NULL
      .if xax == [xcx].RBT_NODE.pLeftNode
        mov [xcx].RBT_NODE.pLeftNode, xdx
      .else
        mov [xcx].RBT_NODE.pRightNode, xdx
      .endif
    .else
      mov [xsi].pRootNode, xdx
    .endif

    mov ebx, [xax].RBT_NODE.dFlags

    .if xax != xdi
      ;Replace node
      mov xdx, xdi
      m2m [xax].RBT_NODE.dFlags, [xdx].RBT_NODE.dFlags, xcx
      m2m [xax].RBT_NODE.pLeftNode, [xdx].RBT_NODE.pLeftNode, xcx
      m2m [xax].RBT_NODE.pRightNode, [xdx].RBT_NODE.pRightNode, xcx
      m2m [xax].RBT_NODE.pParentNode, [xdx].RBT_NODE.pParentNode, xcx

      .if [xax].RBT_NODE.pParentNode != NULL
        mov xcx, [xax].RBT_NODE.pParentNode
        .if [xcx].RBT_NODE.pLeftNode == xdx
          mov [xcx].RBT_NODE.pLeftNode, xax
        .else
          mov [xcx].RBT_NODE.pRightNode, xax
        .endif
      .else
        mov [xsi].pRootNode, xax
      .endif

      mov xdx, [xax].RBT_NODE.pLeftNode
      .if xdx != NULL
        mov [xdx].RBT_NODE.pParentNode, xax
      .endif
      mov xdx, [xax].RBT_NODE.pRightNode
      .if xdx != NULL
        mov [xdx].RBT_NODE.pParentNode, xax
      .endif
    .endif

    .if xbx == RBT_BLACK                                  ;Check if the tree is balanced
      ;Fixup deletion
      mov xax, pNode
      .while xax != NULL && xax != [xsi].pRootNode && [xax].RBT_NODE.dFlags == RBT_BLACK
        mov xdx, [xax].RBT_NODE.pParentNode
        .if xax == [xdx].RBT_NODE.pLeftNode
          mov xbx, [xdx].RBT_NODE.pRightNode
          .if [xbx].RBT_NODE.dFlags == RBT_RED
            mov [xbx].RBT_NODE.dFlags, RBT_BLACK
            mov xdx, [xax].RBT_NODE.pParentNode
            mov [xdx].RBT_NODE.dFlags, RBT_RED
            RedBlackTree_RotateLeft xdx
            mov xax, pNode
            mov xdx, [xax].RBT_NODE.pParentNode
            mov xbx, [xdx].RBT_NODE.pRightNode
          .endif

          mov xdx, [xbx].RBT_NODE.pLeftNode
          mov xcx, [xbx].RBT_NODE.pRightNode
          .if [xdx].RBT_NODE.dFlags == RBT_BLACK && [xcx].RBT_NODE.dFlags == RBT_BLACK
            mov [xbx].RBT_NODE.dFlags, RBT_RED
            mov xax, [xax].RBT_NODE.pParentNode
          .else
            mov xdx, [xbx].RBT_NODE.pRightNode
            .if [xdx].RBT_NODE.dFlags == RBT_BLACK
              mov xdx, [xbx].RBT_NODE.pLeftNode
              mov [xdx].RBT_NODE.dFlags, RBT_BLACK
              mov [xbx].RBT_NODE.dFlags, RBT_RED
              RedBlackTree_RotateRight xbx
              mov xax, pNode
              mov xdx, [xax].RBT_NODE.pParentNode
              mov xbx, [xdx].RBT_NODE.pRightNode
            .endif
            mov xdx, [xax].RBT_NODE.pParentNode
            m2m [xbx].RBT_NODE.dFlags, [xdx].RBT_NODE.dFlags, ecx
            mov [xdx].RBT_NODE.dFlags, RBT_BLACK
            mov xcx, [xbx].RBT_NODE.pRightNode
            mov [xcx].RBT_NODE.dFlags, RBT_BLACK
            RedBlackTree_RotateLeft xdx
            mov xax, [xsi].pRootNode
          .endif
        .else
          mov xdx, [xax].RBT_NODE.pParentNode
          mov xbx, [xdx].RBT_NODE.pLeftNode
          .if [xbx].RBT_NODE.dFlags == RBT_RED
            mov [xbx].RBT_NODE.dFlags, RBT_BLACK
            mov xdx, [xax].RBT_NODE.pParentNode
            mov [xdx].RBT_NODE.dFlags, RBT_RED
            RedBlackTree_RotateRight xdx
            mov xax, pNode
            mov xdx, [xax].RBT_NODE.pParentNode
            mov xbx, [xdx].RBT_NODE.pLeftNode
          .endif
          mov xdx, [xbx].RBT_NODE.pRightNode
          mov xcx, [xbx].RBT_NODE.pLeftNode
          .if [xdx].RBT_NODE.dFlags == RBT_BLACK && [xcx].RBT_NODE.dFlags == RBT_BLACK
            mov [xbx].RBT_NODE.dFlags, RBT_RED
            mov xax, [xax].RBT_NODE.pParentNode
          .else
            mov xdx, [xbx].RBT_NODE.pLeftNode
            .if [xdx].RBT_NODE.dFlags == RBT_BLACK
              mov xdx, [xbx].RBT_NODE.pRightNode
              mov [xdx].RBT_NODE.dFlags, RBT_BLACK
              mov [xbx].RBT_NODE.dFlags, RBT_RED
              RedBlackTree_RotateLeft xbx
              mov xax, pNode
              mov xdx, [xax].RBT_NODE.pParentNode
              mov xbx, [xdx].RBT_NODE.pLeftNode
            .endif
            mov xdx, [xax].RBT_NODE.pParentNode
            m2m [xbx].RBT_NODE.dFlags, [xdx].RBT_NODE.dFlags, ecx
            mov [xdx].RBT_NODE.dFlags, RBT_BLACK
            mov xdx, [xbx].RBT_NODE.pLeftNode
            mov [xdx].RBT_NODE.dFlags, RBT_BLACK
            RedBlackTree_RotateRight [xax].RBT_NODE.pParentNode
            mov xax, [xsi].pRootNode
          .endif
        .endif
      .endw
      .if xax != NULL
        mov [xax].RBT_NODE.dFlags, RBT_BLACK
      .endif
    .endif
    dec [xsi].dCount
    mov xax, pObject
  .else
    OCall xsi::RedBlackTree.ErrorReport, NULL, RBT_OBJ_NOT_FOUND
  .endif
MethodEnd

; 覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧
; Method:     RedBlackTree.DeleteAll
; Purpose:    Wipe the complete tree.
; Arguments:  None.
; Return:     Nothing.

Method RedBlackTree.DeleteAll
  SetObject xcx
  m2z [xcx].pRootNode
  m2z [xcx].dCount
MethodEnd

; 覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧
; Method:     RedBlackTree.Dispose
; Purpose:    Remove an object from the tree and disposes it.
; Arguments:  Arg1: -> Object
; Return:     Nothing.

Method RedBlackTree.Dispose,, pObject:POINTER
  SetObject xcx
  OCall xcx.Delete, pObject                             ;Returns xax -> Object
  Destroy xax                                           ;Safe operation
MethodEnd

; 覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧
; Method:     RedBlackTree.DisposeAll
; Purpose:    Wipe the complete tree and disposes all node hosting objects.
; Arguments:  None.
; Return:     Nothing.

DisposeRBSubtree proc pNode:PRBT_NODE                   ;xsi is passed from DisposeAll
  ANNOTATION prv: xsi

  ;Dispose smaller sibling
  mov xdx, pNode
  mov xax, [xdx].RBT_NODE.pLeftNode
  .if xax != NULL
    invoke DisposeRBSubtree, xax
  .endif

  ;Dispose bigger sibling
  mov xdx, pNode
  mov xax, [xdx].RBT_NODE.pRightNode
  .if xax != NULL
    invoke DisposeRBSubtree, xax
  .endif

  mov xdx, pNode
  sub xdx, [xsi].$Obj(RedBlackTree).xNodeOffset         ;xdx -> Object
  Kill xdx

  ret
DisposeRBSubtree endp

Method RedBlackTree.DisposeAll, uses xsi
  SetObject xsi
  .if [xsi].dCount != 0
    invoke DisposeRBSubtree, [xsi].pRootNode
    OCall xsi.DeleteAll
  .endif
MethodEnd

; 覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧
; Method:     RedBlackTree.Find
; Purpose:    Search for the first node containing the specified key.
; Arguments:  Arg1: -> Object with key data to find.
; Return:     xax -> found Object or NULL if failed.

Method RedBlackTree.Find, uses xbx xsi, pObject:POINTER
  SetObject xsi
  mov xbx, [xsi].pRootNode
  .while xbx != NULL
    mov xax, xbx
    sub xax, [xsi].xNodeOffset
    OCall xsi.Compare, pObject, xax
    .if xax == 0
      mov xax, xbx
      sub xax, [xsi].xNodeOffset
      jmp @@EOM
    .endif
    .if SIGN?                                         ;Check sign flag, if set, the result is < 0
      mov xbx, [xbx].RBT_NODE.pLeftNode
    .else
      mov xbx, [xbx].RBT_NODE.pRightNode
    .endif
  .endw
  xor eax, eax                                        ;xax = NULL => not found!
MethodEnd

; 覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧
; Method:     RedBlackTree.FirstThat
; Purpose:    Search the first object that doesn't return FALSE in eax.
; Arguments:  Arg1: -> (static addr) Function that evaluates to TRUE or FALSE (return value in eax).
;             Arg2-3: Parameters to be used by the called procedure.
; Return:     xax -> Object or NULL if not found.

Method RedBlackTree.FirstThat, uses xbx xdi xsi, pCallAddr:POINTER, xArg1:XWORD, xArg2:XWORD
  ANNOTATION use:xbx xdi xsi

  RedBlackTree_TraverseInOrder Left, Right, 1
MethodEnd

; 覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧
; Method:     RedBlackTree.FirstThatNot
; Purpose:    Search the first object that returns FALSE in eax.
; Arguments:  Arg1: -> (static addr) Function that evaluates to TRUE or FALSE (return value in eax).
;             Arg2-3: Parameters to be used by the called procedure.
; Return:     xax -> object or NULL if not found.

Method RedBlackTree.FirstThatNot, uses xbx xdi xsi, pCallAddr:POINTER, xArg1:XWORD, xArg2:XWORD
  ANNOTATION use:xbx xdi xsi

  RedBlackTree_TraverseInOrder Left, Right, 2
MethodEnd

; 覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧
; Method:     RedBlackTree.ForEach
; Purpose:    Traverse all nodes in the tree in ascending order.
; Arguments:  Arg1: -> Processing procedure (static address).
;             Arg2-3: Parameters to be used by the processing procedure.
; Return:     Nothing.
; Note:       While the loop is running, no object should be deleted or inserted!

Method RedBlackTree.ForEach, uses xbx xdi xsi, pCallAddr:POINTER, xArg1:XWORD, xArg2:XWORD
  ANNOTATION use:xbx xdi xsi

  RedBlackTree_TraverseInOrder Left, Right, RBT_TEST_NONE
MethodEnd

; 覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧
; Method:     RedBlackTree.ForEachRev
; Purpose:    Traverse all objects in the tree in descending order.
; Arguments:  Arg1: -> Processing procedure (static address).
;             Arg2-3: Parameters to be used by the processing procedure.
; Return:     Nothing.
; Note:       While the loop is running, no object should be deleted or inserted!

Method RedBlackTree.ForEachRev, uses xbx xdi xsi, pCallAddr:POINTER, xArg1:XWORD, xArg2:XWORD
  ANNOTATION use:xbx xdi xsi

  RedBlackTree_TraverseInOrder Right, Left, RBT_TEST_NONE
MethodEnd

; 覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧
; Method:     RedBlackTree.GetFirst
; Purpose:    Return the object with the smallest key.
; Arguments:  Nothing.
; Return:     xax -> Object or NULL if failed.

Method RedBlackTree.GetFirst
  SetObject xcx
  mov xax, [xcx].pRootNode
  RedBlackTree_GetMin
  sub xax, [xcx].xNodeOffset
MethodEnd

; 覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧
; Method:     RedBlackTree.GetLast
; Purpose:    Return the object with the largest key.
; Arguments:  Nothing.
; Return:     xax -> Object or NULL if failed.

Method RedBlackTree.GetLast
  SetObject xcx
  mov xax, [xcx].pRootNode
  RedBlackTree_GetMax
  sub xax, [xcx].xNodeOffset
MethodEnd

; 覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧
; Method:     RedBlackTree.GetNext
; Purpose:    Return the object with a key that is larger than the key of the specified object.
; Arguments:  Arg1: -> Object.
; Return:     xax -> Next object or NULL if failed.

Method RedBlackTree.GetNext,, pObject:POINTER
  SetObject xcx
  ?mov xdx, pObject
  add xdx, [xcx].xNodeOffset
  mov xax, [xdx].RBT_NODE.pRightNode
  .if xax != NULL
    RedBlackTree_GetMin
  .else
    .while [xdx].RBT_NODE.pParentNode != NULL
      mov xax, [xdx].RBT_NODE.pParentNode
      .break .if xdx == [xax].RBT_NODE.pLeftNode
      mov xdx, xax
    .endw
    mov xax, [xdx].RBT_NODE.pParentNode
  .endif
  .if xax != NULL
    sub xax, [xcx].xNodeOffset
  .endif
MethodEnd

; 覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧
; Method:     RedBlackTree.GetPrev
; Purpose:    Return the object with a key that is smaller than the key of the specified object.
; Arguments:  Arg1: -> Object.
; Return:     xax -> Previous object or NULL if failed.

Method RedBlackTree.GetPrev,, pObject:POINTER
  SetObject xcx
  ?mov xdx, pObject
  add xdx, [xcx].xNodeOffset
  mov xax, [xdx].RBT_NODE.pLeftNode
  .if xax != NULL
    RedBlackTree_GetMax
  .else
    .while [xdx].RBT_NODE.pParentNode != NULL
      mov xax, [xdx].RBT_NODE.pParentNode
      .break .if xdx == [xax].RBT_NODE.pRightNode
      mov xdx, xax
    .endw
    mov xax, [xdx].RBT_NODE.pParentNode
  .endif
  .if xax != NULL
    sub xax, [xcx].xNodeOffset                          ;xax -> object/hosting data structure
  .endif
MethodEnd

; 覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧
; Method:     RedBlackTree.Init
; Purpose:    Initialize the RedBlackTree object.
; Arguments:  Arg1: -> Owner object.
;             Arg2: Node offset within hosting object (i.e. offset Object.RBTN, where RBTN is a
;                   RBT_NODE structure).
; Return:     Nothing.

Method RedBlackTree.Init,, pOwner:POINTER, xNodeOffset:XWORD
  SetObject xcx
  m2m [xcx].xNodeOffset, xNodeOffset, xax
  m2z [xcx].dCount
  ACall xcx.Init, pOwner
MethodEnd

; 覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧
; Method:     RedBlackTree.Insert
; Purpose:    Insert an object in the tree. The object must host an uninitialized node at the
;             specified offset used in the Init method.
; Arguments:  Arg1: -> Object.
; Return:     eax = Error code.
;             xcx -> (inserted) object.

Method RedBlackTree.Insert, uses xbx xdi xsi, pObject:POINTER
  local xCompResult:XWORD, pNode:PRBT_NODE

  SetObject xsi
  mov xax, pObject
  add xax, [xsi].xNodeOffset

  ;Initialize the node
  m2z [xax].RBT_NODE.pParentNode
  m2z [xax].RBT_NODE.pLeftNode
  m2z [xax].RBT_NODE.pRightNode
  mov [xax].RBT_NODE.dFlags, RBT_RED                    ;New inserted nodes are red!
  mov xdi, xax

  mov xbx, [xsi].pRootNode
  mov pNode, NULL

  .while xbx != NULL
    mov xdx, xdi
    sub xdx, [xsi].xNodeOffset
    mov xax, xbx
    sub xax, [xsi].xNodeOffset
    mov xCompResult, $OCall(xsi::RedBlackTree.Compare, xdx, xax)
    .if xax == 0
      OCall xsi::RedBlackTree.ErrorReport, NULL, RBT_NON_UNIQUE_KEY
      jmp @@Exit
    .endif
    mov pNode, xbx
    .ifBitSet xCompResult, BIT31                        ;Negative?
      mov xbx, [xbx].RBT_NODE.pLeftNode
    .else
      mov xbx, [xbx].RBT_NODE.pRightNode
    .endif
  .endw

  .if pNode != NULL
    m2m [xdi].RBT_NODE.pParentNode, pNode, xax
    mov xdx, pNode
    .ifBitSet xCompResult, BIT31                        ;Negative?
      mov [xdx].RBT_NODE.pLeftNode, xdi
    .else
      mov [xdx].RBT_NODE.pRightNode, xdi
    .endif
  .else
    mov [xsi].pRootNode, xdi
    mov [xdi].RBT_NODE.dFlags, RBT_BLACK
  .endif

  ;Fixup insertion
  mov xdx, [xdi].RBT_NODE.pParentNode
  .while xdi != [xsi].pRootNode && [xdx].RBT_NODE.dFlags == RBT_RED
    mov xdx, [xdi].RBT_NODE.pParentNode
    mov xcx, [xdx].RBT_NODE.pParentNode
    .if xdx == [xcx].RBT_NODE.pLeftNode
      mov xdx, [xdx].RBT_NODE.pParentNode
      mov xcx, [xdx].RBT_NODE.pRightNode
      mov xdx, [xdi].RBT_NODE.pParentNode
      .if xcx != NULL && [xcx].RBT_NODE.dFlags == RBT_RED
        mov [xdx].RBT_NODE.dFlags, RBT_BLACK
        mov [xcx].RBT_NODE.dFlags, RBT_BLACK
        mov xdi, [xdx].RBT_NODE.pParentNode
        mov [xdi].RBT_NODE.dFlags, RBT_RED
      .else
        .if xdi == [xdx].RBT_NODE.pRightNode
          RedBlackTree_RotateLeft xdx
        .endif
        mov xdx, [xdi].RBT_NODE.pParentNode
        mov [xdx].RBT_NODE.dFlags, RBT_BLACK
        mov xdx, [xdx].RBT_NODE.pParentNode
        mov [xdx].RBT_NODE.dFlags, RBT_RED
        RedBlackTree_RotateRight xdx
      .endif
    .else
      mov xdx, [xdx].RBT_NODE.pParentNode
      mov xcx, [xdx].RBT_NODE.pLeftNode
      mov xdx, [xdi].RBT_NODE.pParentNode
      .if xcx != NULL && [xcx].RBT_NODE.dFlags == RBT_RED
        mov [xdx].RBT_NODE.dFlags, RBT_BLACK
        mov [xcx].RBT_NODE.dFlags, RBT_BLACK
        mov xdi, [xdx].RBT_NODE.pParentNode
        mov [xdi].RBT_NODE.dFlags, RBT_RED
      .else
        .if xdi == [xdx].RBT_NODE.pLeftNode
          RedBlackTree_RotateRight xdx
        .endif
        mov xdx, [xdi].RBT_NODE.pParentNode
        mov [xdx].RBT_NODE.dFlags, RBT_BLACK
        mov xdx, [xdx].RBT_NODE.pParentNode
        mov [xdx].RBT_NODE.dFlags, RBT_RED
        RedBlackTree_RotateLeft xdx
      .endif
    .endif

    mov xdx, [xdi].RBT_NODE.pParentNode
  .endw

  mov xax, [xsi].pRootNode
  mov [xax].RBT_NODE.dFlags, RBT_BLACK
  xor eax, eax                                          ;eax = OBJ_OK
  inc [xsi].dCount

@@Exit:
  mov xcx, pObject
MethodEnd

; 覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧
; Method:     RedBlackTree.LastThat
; Purpose:    Search the last object that doesn't return FALSE in eax.
; Arguments:  Arg1: -> (static addr) Function that evaluates to TRUE or FALSE (return value in eax).
;             Arg2-3: Parameters to be used by the called procedure.
; Return:     xax -> Object or NULL if not found.

Method RedBlackTree.LastThat, uses xbx xdi xsi, pCallAddr:POINTER, xArg1:XWORD, xArg2:XWORD
  ANNOTATION use:xbx xdi xsi

  RedBlackTree_TraverseInOrder Right, Left, RBT_TEST_TRUE
MethodEnd

; 覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧
; Method:     RedBlackTree.LastThatNot
; Purpose:    Search the first object that returns FALSE in eax.
; Arguments:  Arg1: -> (static addr) Function that evaluates to TRUE or FALSE (return value in eax).
;             Arg2-3: Parameters to be used by the called procedure.
; Return:     xax -> object or NULL if not found.

Method RedBlackTree.LastThatNot, uses xbx xdi xsi, pCallAddr:POINTER, xArg1:XWORD, xArg2:XWORD
  ANNOTATION use:xbx xdi xsi

  RedBlackTree_TraverseInOrder Right, Left, RBT_TEST_FALSE
MethodEnd

; 覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧
; Method:     RedBlackTree.GetItem
; Purpose:    Load an item from a stream object.
; Arguments:  Arg1: -> Stream object containing an object.
; Return:     xax -> New loaded object.

Method RedBlackTree.GetItem,, pStream:$ObjPtr(Stream)
  OCall pStream::Stream.Get, pSelf
MethodEnd

; 覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧
; Method:     RedBlackTree.PutItem
; Purpose:    Store an item of the RedBlackTree in a stream object.
; Arguments:  Arg1: -> Stream.
;             Arg2: -> Item.
; Return:     Nothing.
; Note:       The hosting object/data structure dont need to save the node information since it is
;             rebuild when loading from stream.

Method RedBlackTree.PutItem,, pStream:$ObjPtr(Stream), pItem:POINTER
  OCall pStream::Stream.Put, pItem
MethodEnd

; 覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧
; Method:     RedBlackTree.Load
; Purpose:    Load and initializes the RedBlackTree from a stream object.
; Arguments:  Arg1: -> Stream object.
;             Arg2: -> Owner object.
; Return:     Nothing.

LoadRBSubtree proc uses xdi pParentNode:PRBT_NODE       ;xbx and xsi is passed from Load
  local dFlags:DWORD

  ANNOTATION prv: xbx xsi

  OCall xsi::RedBlackTree.GetItem, xbx                  ;Load the object
  add xax, [xsi].$Obj(RedBlackTree).xNodeOffset
  mov xdi, xax
  m2m [xdi].RBT_NODE.pParentNode, pParentNode, xax      ;Set Parent node
  OCall xbx::Stream.BinRead32
  mov dFlags, eax
  and eax, 1
  mov [xdi].RBT_NODE.dFlags, eax                        ;Set color

  .ifBitSet dFlags, RBT_RES1_BIT
    invoke LoadRBSubtree, xdi
  .else
    xor eax, eax
  .endif
  mov [xdi].RBT_NODE.pLeftNode, xax                     ;Set left node

  .ifBitSet dFlags, RBT_RES2_BIT
    invoke LoadRBSubtree, xdi
  .else
    xor eax, eax
  .endif
  mov [xdi].RBT_NODE.pRightNode, xax                    ;Set right node

  mov xax, xdi                                          ;xax -> loaded node
  ret
LoadRBSubtree endp

Method RedBlackTree.Load, uses xbx xsi, pStream:$ObjPtr(Stream), pOwner:POINTER
  SetObject xsi
  mov xbx, pStream
  OCall xsi.Init, pOwner, 0
  mov [xsi].dErrorCode, $32($OCall(xbx::Stream.BinRead32))
  mov [xsi].xNodeOffset, $OCall(xbx::Stream.BinReadX)
  mov [xsi].dCount, $32($OCall(xbx::Stream.BinRead32))
  .if [xsi].dCount != 0
    invoke LoadRBSubtree, NULL
  .else
    xor eax, eax
  .endif
  mov [xsi].pRootNode, xax
MethodEnd

; 覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧覧
; Method:     RedBlackTree.Store
; Purpose:    Store the RedBlackTree in a stream object.
; Arguments:  Arg1: -> Stream object.
; Return:     Nothing.

StoreRBSubtree proc uses xdi pNode:PRBT_NODE            ;xbx and xsi are passed from Store
  ANNOTATION prv: xbx xsi

  mov xdi, pNode
  mov xax, xdi
  sub xax, [xsi].$Obj(RedBlackTree).xNodeOffset         ;xax -> Object
  OCall xsi::RedBlackTree.PutItem, xbx, xax             ;Save the object

  ;Calc and save node information
  xor eax, eax
  mov edx, [xdi].RBT_NODE.dFlags
  .if xax != [xdi].RBT_NODE.pLeftNode
    BitSet edx, RBT_RES1_BIT
  .endif
  .if xax != [xdi].RBT_NODE.pRightNode
    BitSet edx, RBT_RES2_BIT
  .endif
  OCall xbx::Stream.BinWrite32, edx                     ;Save it

  ;Save children objects
  mov xcx, [xdi].RBT_NODE.pLeftNode
  .if xcx != NULL
    invoke StoreRBSubtree, xcx
  .endif
  mov xcx, [xdi].RBT_NODE.pRightNode
  .if xcx != NULL
    invoke StoreRBSubtree, xcx
  .endif

  ret
StoreRBSubtree endp

Method RedBlackTree.Store, uses xbx xsi, pStream:$ObjPtr(Stream)
  SetObject xsi
  mov xbx, pStream
  OCall xbx::Stream.BinWrite32, [xsi].dErrorCode
  OCall xbx::Stream.BinWriteX, [xsi].xNodeOffset
  OCall xbx::Stream.BinWrite32, [xsi].dCount
  .if [xsi].dCount != 0
    invoke StoreRBSubtree, [xsi].pRootNode
  .endif
MethodEnd

endif
