; ==================================================================================================
; Title:      CounterBadge.inc
; Author:     G. Friedrich
; Version:    C.2.0
; Purpose:    ObjAsm support of CounterBadge objects.
; Notes:      Version C.2.0, November 2025
;               - First release.
; ==================================================================================================


; --------------------------------------------------------------------------------------------------
; Object:     CounterBadge
; Purpose:    This is derived object from TextBadge that shows a signed number.

Object CounterBadge, CounterBadgeID, TextBadge
  RedefineMethod    Draw

  VirtualMethod     Add,          SDWORD
  VirtualMethod     Dec
  VirtualMethod     GetValue
  VirtualMethod     Inc
  VirtualMethod     SetValue,     SDWORD
  VirtualMethod     Sub,          SDWORD

  DefineVariable    sdCount,      SDWORD
ObjectEnd


; ==================================================================================================

if IMPLEMENT

; --------------------------------------------------------------------------------------------------
; Method:     CounterBadge.Add
; Purpose:    Add a value to the counter value.
; Arguments:  None.
; Return:     Nothing.

Method CounterBadge.Add,, sdValue:SDWORD
  SetObject xcx
  ?mov edx, sdValue
  add [xcx].sdCount, edx
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     CounterBadge.Dec
; Purpose:    Decrement the counter value.
; Arguments:  None.
; Return:     Nothing.

Method CounterBadge.Dec
  SetObject xcx
  dec [xcx].sdCount
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     CounterBadge.Draw
; Purpose:    Draw the badge on an internal buffer.
; Arguments:  None.
; Return:     Nothing.

Method CounterBadge.Draw, uses xsi
  local cBuffer[SDWORD2DEC_MAX_CHARS]:CHR

  SetObject xsi
  invoke sdword2dec, addr cBuffer, [xsi].sdCount
  ACall xsi.Draw, addr cBuffer
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     CounterBadge.GetValue
; Purpose:    Return the counter value.
; Arguments:  None.
; Return:     eax = Counter.

Method CounterBadge.GetValue
  SetObject xcx
  mov eax, [xcx].sdCount
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     CounterBadge.Inc
; Purpose:    Increment the counter value.
; Arguments:  None.
; Return:     Nothing.

Method CounterBadge.Inc
  SetObject xcx
  inc [xcx].sdCount
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     CounterBadge.SetValue
; Purpose:    Set the counter value.
; Arguments:  Arg1: Signed value.
; Return:     Nothing.

Method CounterBadge.SetValue,, sdValue:SDWORD
  SetObject xcx
  ?mov edx, sdValue
  mov [xcx].sdCount, edx
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     CounterBadge.Sub
; Purpose:    Subtract a value to the counter value.
; Arguments:  None.
; Return:     Nothing.

Method CounterBadge.Sub,, sdValue:SDWORD
  SetObject xcx
  ?mov edx, sdValue
  sub [xcx].sdCount, edx
MethodEnd

endif
