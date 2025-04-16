; ==================================================================================================
; Title:      WinHelpers.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm helper macros for Windows Applications.
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


??P_EventHandler typedef proto :POINTER, :LPARAM, :WPARAM

; --------------------------------------------------------------------------------------------------
; Macro:      DispatchEvent
; Purpose:    Search for a specified EventID in the "Event Translation Table". If found,
;             the matching method is called, otherwise the default proc is invoked.
; Arguments:  Default procedure name and common parameters.
; Return:     Nothing.
; Note:       - uses xsi -> object instance.
;             - the event handler receives the event ID (WM_XXX, ...) in eax.

DispatchEvent macro DefProc:=<>, uMsg:=<uMsg>, wParam:=<wParam>, lParam:=<lParam>
  local @@Found, @@Exit, @@DispatchEventJumpTable, @@Static, @@VirtualInterface, @@Dynamic

.const
  @@DispatchEventJumpTable label POINTER
  POINTER offset(@@Static)
  POINTER offset(@@VirtualInterface)
  POINTER offset(@@VirtualInterface)
  POINTER offset(@@Dynamic)

  if TARGET_BITNESS eq 32
    $$Reg1 textequ <eax>
    $$Reg2 textequ <edx>
  else
    $$Reg1 textequ <r10>
    $$Reg2 textequ <r11>
  endif
.code
  mov $$Reg1, POINTER ptr [xsi]                         ;;$$Reg1 -> Dual Method Table
  mov $$Reg2, [$$Reg1 - sizeof(POINTER)]                ;;$$Reg2 -> Event Translation Table
  mov xcx, [$$Reg2]                                     ;;Number of ??EVENT_ENTRYs in table (XWORD)
  add $$Reg2, sizeof(QWORD)                             ;;-> first ??EVENT_ENTRY
  test xcx, xcx                                           
  .while !ZERO?                                         
    mov eax, [$$Reg2].??EVENT_ENTRY.dID                 ;;Recover EventID
    cmp eax, uMsg                                       
    je @@Found                                          ;;EventID found! No hint is necessary.
    add $$Reg2, sizeof(??EVENT_ENTRY)                   ;;Goto next ??EVENT_ENTRY
    dec xcx                                             
  .endw

  ifnb <DefProc>
@@DefProc:  invoke DefProc, uMsg, wParam, lParam        ;;The label should be on the same line!
  else                                                  ;; This way, if a macro is included
    xor eax, eax                                        ;; it expands before the @@DefProc label!
  endif
  jmp @@Exit
@@Found:
  movzx xcx, WORD ptr [$$Reg2].??EVENT_ENTRY.wType      ;;xcx = Method type 1..4, eax = uMsg
  test ecx, ecx
  jz @@EOM
  if TARGET_BITNESS eq 32
    jmp POINTER ptr [@@DispatchEventJumpTable + xcx*sizeof(POINTER) - sizeof(POINTER)] ;;Read & jump
  else
    mov r10, offset(@@DispatchEventJumpTable) - sizeof(POINTER)
    jmp POINTER ptr [r10 + xcx*sizeof(POINTER)]         ;;Read jump table and jump
  endif

@@Static:
  invoke ??P_EventHandler ptr ([$$Reg2].??EVENT_ENTRY.pHandler), xsi, wParam, lParam
  jmp @@Exit
@@VirtualInterface:
  mov $$Reg2, [$$Reg2].??EVENT_ENTRY.pHandler           ;;Offset into DMT
  invoke ??P_EventHandler ptr [$$Reg2], xsi, wParam, lParam
  jmp @@Exit
@@Dynamic:
  mov $$Reg2, [$$Reg2].??EVENT_ENTRY.pHandler           ;;$$Reg2 = offset into object instance
  invoke ??P_EventHandler ptr [xsi + $$Reg2], xsi, wParam, lParam
@@Exit:
endm

; --------------------------------------------------------------------------------------------------
; Macro:      Subclass
; Purpose:    Subclass a system window.
; Arguments:  Arg1: Object name.
;             Arg2: Optional index to allow multiple subclassings.
; Return:     Nothing.
; Note:       xsi has to point to the object instance!

Subclass macro Expression:req, Index:=<0>
  PreParseExpr Expression
  if $ParseObjExpr(Expression) eq FALSE
    .err <$Subclass - syntax error: Expression>
  else
    $$sz1 CatStr ??ObjExpr, <_Subclass_>, <Index>
    %ifndef $$sz1
      %CStr $$sz1, "&$$sz1"
    endif
    %invoke SetProp, [xsi].hWnd, offset($$sz1), xsi
    ASSERT eax, "failed to subclass &Expression"
    invoke SetWindowLongPtr, [xsi].hWnd, GWLP_WNDPROC, $MethodAddr(xsi::Expression.WndProc)
    mov [xsi].pPrevWndProc, xax
  endif
endm

; --------------------------------------------------------------------------------------------------
; Macro:      Unsubclass
; Purpose:    Unsubclass a system window.
; Arguments:  Arg1: Object name.
;             Arg2: Optional index to allow multiple subclassings.
; Return:     Nothing.
; Note:       xsi has to point to the object instance!

Unsubclass macro Expression:req, Index:=<0>
  PreParseExpr Expression
  if $ParseObjExpr(Expression) eq FALSE
    .err <Unsubclass - syntax error: Expression>
  else
    $$sz1 CatStr ??ObjExpr, <_Subclass_>, <Index>
    %ifndef $$sz1
      %CStr $$sz1, "&$$sz1"
    endif
    %invoke RemoveProp, [xsi].hWnd, offset($$sz1)
    invoke SetWindowLongPtr, [xsi].hWnd, GWLP_WNDPROC, [xsi].pPrevWndProc
    m2z [xsi].pPrevWndProc
  endif
endm

; --------------------------------------------------------------------------------------------------
; Macro:      ($)GetSubclassingInst
; Purpose:    Return the instance POINTER of the object that subclassed a system window.
; Arguments:  Arg1: Object name.
;             Arg2: Window HANDLE.
;             Arg2: Optional index to allow multiple subclassings.
; Return:     rax -> Instance.
; Note:       xsi has to point to the object instance!

GetSubclassingInst macro Expression:req, hWnd:req, Index:=<0>
  PreParseExpr Expression
  if $ParseObjExpr(Expression) eq FALSE
    .err <GetSubclassingInst - syntax error: Expression>
  else
    $$sz1 CatStr ??ObjExpr, <_Subclass_>, <Index>
    %ifndef $$sz1
      %CStr $$sz1, "&$$sz1"                               ;;Data section is required for some
    endif                                                 ;;  UNICODE conversions
    %invoke GetProp, hWnd, offset($$sz1)
  endif
endm

$GetSubclassingInst macro Expression:req, hWnd:req, Index:=<0>
  GetSubclassingInst Expression, hWnd, Index
  exitm <xax>
endm

; --------------------------------------------------------------------------------------------------
; Macro:      CloneRect
; Purpose:    Copy the coordinates from the source to the destination RECT.
; Arguments:  Arg1: Destination RECT structure.
;             Arg2: Source RECT structure.
;             Arg3: optional registers to be used to copy the RECT content.
; Return:     Nothing.

CloneRect macro DstRct:req, SrcRct:req, AuxRegs:vararg
  ifb <AuxRegs>
    s2s DstRct, SrcRct, xax
  else
    s2s DstRct, SrcRct, AuxRegs
  endif
endm

; --------------------------------------------------------------------------------------------------
; Macro:      GrowRect
; Purpose:    Change the size of a RECT by a specified value.
; Arguments:  Arg1: RECT structure.
;             Arg2: X size to grow.
;             Arg2: (optional) Y size to grow.
; Return:     Nothing.

GrowRect macro Rect:req, dSX:=<0>, dSY:=<>
  ifdifi <dSX>, <0>
    sub Rect.left, dSX
    add Rect.right, dSX
  endif

  ifb <dSY>
    ??SY textequ <dSX>
  else
    ??SY textequ <dSY>
  endif

  %ifdifi <??SY>, <0>
    %sub Rect.top, ??SY
    %add Rect.bottom, ??SY
  endif
endm

; --------------------------------------------------------------------------------------------------
; Macro:      MoveRect
; Purpose:    Move a RECT by a specified X/Y value.
; Arguments:  Arg1: -> RECT structure.
;             Arg2: X size to move.
;             Arg3: (optional) Y size to move.
; Return:     Nothing.

MoveRect macro Rect:req, dSX:req, dSY:=<>
  ifdifi <dSX>, <0>
    add Rect.left, dSX
    add Rect.right, dSX
  endif

  ifb <dSY>
    ??SY textequ <dSX>
  else
    ??SY textequ <dSY>
  endif

  %ifdifi <??SY>, <0>
    %add Rect.top, ??SY
    %add Rect.bottom, ??SY
  endif
endm

; --------------------------------------------------------------------------------------------------
; Macro:      $MakePointS
; Purpose:    Return a POINTS structure (DWORD) containing the coordinates indicated in args.
; Arguments:  Arg1: X position.
;             Arg2: Y position.
; Return:     POINT structure.

$MakePointS macro XPos:req, YPos:req
  exitm <YPos*0FFFFh + XPos>
endm

; --------------------------------------------------------------------------------------------------
; Macro:      EnableDlgControl
; Purpose:    Enable or disable a dialog control.
; Arguments:  Arg1: Dialog HANDLE.
;             Arg2: Control ID.
;             Arg3: Action (TRUE=Enable, FALSE=Disable).
; Return:     Nothing.

EnableDlgControl macro hDlg:req, dCtrlID:req, dAction:=<TRUE>
  invoke GetDlgItem, hDlg, dCtrlID                      ;;Get control HANDLE
  invoke EnableWindow, xax, dAction
endm

; --------------------------------------------------------------------------------------------------
; Macro:      EnableDlgCtrlNotif
; Purpose:    Enable the parent notification machanism of a dialog control, which was disabled
;             by default.
; Arguments:  Arg1: Dialog HANDLE.
;             Arg2: Control ID.

EnableDlgCtrlNotif macro hDlg:req, dCtrlID:req
  invoke GetDlgItem, hDlg, dCtrlID                      ;;Get control HANDLE
  push xax                                              ;;Store it
  sub xsp, @WordSize + 20h                              ;;Alignment + reserve homing space
  invoke GetWindowLongPtr, xax, GWL_EXSTYLE             ;;By default WS_EX_NOPARENTNOTIFY is set!
  BitClr eax, WS_EX_NOPARENTNOTIFY                      ;;Clear it
  add xsp, @WordSize + 20h                              
  pop xcx                                               ;;Recover control HANDLE
  invoke SetWindowLongPtr, xcx, GWL_EXSTYLE, xax        ;;Restore modified ExStyle
endm

; --------------------------------------------------------------------------------------------------
; Macro:      PntS2Pnt
; Purpose:    Convert the POINTS contained in PntS into a POINT contained in Pnt.
; Arguments:  POINT, POINTS
; Return:     Nothing.

PntS2Pnt macro Pnt:req, PntS:req
  ifidni <PntS>, <eax>
    .err <PntS2Pnt - input can not be eax>
  elseifidni <PntS>, <rax>
    .err <PntS2Pnt - input can not be rax>
  endif
  if type(PntS) eq 8
    mov rax, PntS
  else
    mov eax, PntS
  endif
  shr eax, 16
  cwde                                                  ;;Converts negative integers too
  mov Pnt.y, eax                                        ;;Pnt.y = height
  if type(PntS) eq 8
    mov rax, PntS
  else
    mov eax, PntS
  endif
  cwde                                                  ;;Converts negative integers too
  mov Pnt.x, eax                                        ;;Pnt.x= width
endm

; --------------------------------------------------------------------------------------------------
; Macro:      PntS2Regs
; Purpose:    Convert the POINTS contained in PntS to DWORD values in the eax and ecx registers.
; Arguments:  POINTS, Reg32
; Return:     eax = x, Reg32 = y.
; Example:    PntS2Regs lParam

PntS2Regs macro PntS:req, Reg32:=<ecx>
  ifidni <PntS>, <eax>
    .err <PntS2Pnt - input can not be eax>
  endif
  if type(PntS) eq 8
    mov rax, PntS
  else
    mov eax, PntS
  endif
  shr eax, 16
  cwde                                                  ;;Converts negative integers too
  mov Reg32, eax                                        ;;Reg32 = y
  if type(PntS) eq 8
    mov rax, PntS
  else
    mov eax, PntS
  endif
  cwde                                                  ;;eax = x
endm

; --------------------------------------------------------------------------------------------------
; Macro:      Pnt2Reg32
; Purpose:    Convert a POINT to a Reg32.
; Arguments:  Arg1: Reg32.
;             Arg2: POINT.

Pnt2Reg32 macro Reg32:req, Pnt:req
  mov Reg32, Pnt.y
  shl Reg32, 16
  add Reg32, Pnt.x
endm

; --------------------------------------------------------------------------------------------------
; Macro:      $MakeLangID
; Purpose:    Create a resource language ID.
; Arguments:  Arg1: Primary language.
;             Arg2: Sublanguage.
; Return:     Language ID.

$MakeLangID macro PL:req, SL:req
  local aVal, aOut

  %aVal equ (SL shl 10) or PL
  aOut textequ %aVal
  exitm <&aOut>
endm

; --------------------------------------------------------------------------------------------------
; Macro:      $PrimaryLangID
; Purpose:    Return the primary language from a Language ID.
; Arguments:  Language ID.
; Return:     Primary Language ID.

$PrimaryLangID MACRO LangID:REQ
  local aVal, aOut

  %aVal equ (LangID and 03FFh)
  aOut textequ %aVal
  exitm <&aOut>
endm

; --------------------------------------------------------------------------------------------------
; Macro:      $SubLangID
; Purpose:    Return the sublanguage from a Language ID.
; Arguments:  Language ID.
; Return:     Sublanguage ID.

$SubLangID MACRO LangID:REQ
  local aVal, aOut

  %aVal equ (LangID shr 10)
  aOut textequ %aVal
  exitm <&aOut>
endm

; --------------------------------------------------------------------------------------------------
; Macro:      $Dlu2PixX
; Purpose:    Converts X Dialog Logic Units to pixel.
; Arguments:  Arg1: X DLU value.
;             Arg2: X DBU value obtained from GetDlgBaseUnits.
; Return:     eax = Pixel value.
; Note:       Uses xdx.

$Dlu2PixX macro DluValX:req, DbuValX:req
  ifdifi <DbuValX>, <eax>
    mov eax, DbuValX
  endif
  if (opattr DluValX) and OAT_IMMEDIATE
    mov edx, DluValX
    mul edx
  else 
    mul DluValX
  endif
  shr eax, 2
  exitm <eax>
endm

; --------------------------------------------------------------------------------------------------
; Macro:      $Dlu2PixY
; Purpose:    Converts Y Dialog Logic Units to pixel.
; Arguments:  Arg1: Y DLU value.
;             Arg2: Y DBU value obtained from GetDlgBaseUnits.
; Return:     eax = Pixel value.
; Note:       Uses xdx.

$Dlu2PixY macro DluValY:req, DbuValY:req
  ifdifi <DbuValY>, <eax>
    mov eax, DbuValY
  endif
  if (opattr DluValY) and OAT_IMMEDIATE
    mov edx, DluValY
    mul edx
  else
    mul DluValY
  endif
  shr eax, 3
  exitm <eax>
endm

; --------------------------------------------------------------------------------------------------
; Macro:      SetWndStyle
; Purpose:    Set the style flag of a window.
; Arguments:  Arg1: Style flag.
; Note:       Uses volatile registers.

SetWndStyle macro hWnd:req, dStyle:req
  invoke GetWindowLongPtr, hWnd, GWL_STYLE
  BitSet eax, dStyle
  invoke SetWindowLongPtr, hWnd, GWL_STYLE, eax
endm

; --------------------------------------------------------------------------------------------------
; Macro:      ClrWndStyle
; Purpose:    Clear the style flag of a window.
; Arguments:  Arg1: Style flag.
; Note:       Uses volatile registers.

ClrWndStyle macro hWnd:req, dStyle:req
  invoke GetWindowLongPtr, hWnd, GWL_STYLE
  BitClr eax, dStyle
  invoke SetWindowLongPtr, hWnd, GWL_STYLE, eax
endm

; --------------------------------------------------------------------------------------------------
; Macro:      SetWndStyleEx
; Purpose:    Set the extended style flag of a window.
; Arguments:  Arg1: Extended style flag.
; Note:       Uses volatile registers.

SetWndStyleEx macro hWnd:req, dExStyle:req
  invoke GetWindowLongPtr, hWnd, GWL_EXSTYLE
  BitSet eax, dExStyle
  invoke SetWindowLongPtr, hWnd, GWL_EXSTYLE, eax
endm

; --------------------------------------------------------------------------------------------------
; Macro:      ClrWndStyleEx
; Purpose:    Clear the extended style flag of a window.
; Arguments:  Arg1: Extenden style flag.
; Note:       Uses volatile registers.

ClrWndStyleEx macro hWnd:req, dExStyle:req
  invoke GetWindowLongPtr, hWnd, GWL_EXSTYLE
  BitClr eax, dExStyle
  invoke SetWindowLongPtr, hWnd, GWL_EXSTYLE, eax
endm
