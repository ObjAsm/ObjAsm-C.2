; ==================================================================================================
; Title:      ADE_ScrollBarVert.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm implementation of Scrollbar object.
; Notes:      Version 1.0.0, February 2016
;               - First release.
; ==================================================================================================


; ==================================================================================================
; ScrollBarVert implementation 
; ==================================================================================================

;; ——————————————————————————————————————————————————————————————————————————————————————————————————
;; Method:    ScrollBarVert.OnSetScrollInfo
;; Purpose:   Event procedure for SBM_SETSCROLLINFO message.
;; Arguments: Arg1: First message parameter.
;;            Arg2: Second message parameter.
;; Return:    eax = Zero if handled.
;
;Method ScrollBarVert.OnSetScrollInfo, uses xsi, wParam:WPARAM, lParam:LPARAM
;    local SInfo:SCROLLINFO, hDC:HDC
;
;;    DbgText "ScrollBarVert.OnSetScrollInfo"
;
;    SetObject xsi
;;    DbgHex wParam
;;    mov ecx, lParam
;;    DbgDec [ecx].SCROLLINFO.cbSize
;;    DbgDec [ecx].SCROLLINFO.fMask
;;    DbgDec [ecx].SCROLLINFO.nMin
;;    DbgDec [ecx].SCROLLINFO.nMax
;;    DbgDec [ecx].SCROLLINFO.nPage
;;    DbgDec [ecx].SCROLLINFO.nPos
;;    DbgDec [ecx].SCROLLINFO.nTrackPos
;;    DbgLine
;    invoke CallWindowProc, [esi].pPrevWndProc, [esi].hWnd, SBM_SETSCROLLINFO, wParam, lParam
;    .if wParam != FALSE
;      invoke GetDC, [esi].hWnd
;      .if eax != 0
;        mov hDC, eax
;        invoke MoveToEx, hDC, 0,0, NULL 
;        invoke LineTo, hDC, 50, 100
;        invoke ReleaseDC, [esi].hWnd, hDC
;      .endif  
;    .endif
;    xor eax, eax
;MethodEnd
;
;; ——————————————————————————————————————————————————————————————————————————————————————————————————
;; Method:    ScrollBarVert.OnPaint
;; Purpose:   Event procedure for WM_PAINT message.
;; Arguments: Arg1: First message parameter.
;;            Arg2: Second message parameter.
;; Return:    eax = Zero if handled.
;
;Method ScrollBarVert.OnPaint, uses xbx edi esi, wParam:WPARAM, lParam:LPARAM
;    local PS:PAINTSTRUCT, hDC:HDC, CR:RECT, dLineIndex:DWORD, SBR:RECT
;
;;    DbgText "ScrollBarVert.OnPaint"
;
;    SetObject xsi
;    SetOwner ebx, CodeEditor
;    invoke CallWindowProc, [esi].pPrevWndProc, [esi].hWnd, WM_PAINT, wParam, lParam
;;    mov hDC, $invoke(BeginPaint, [esi].hWnd, addr PS)   ;Hides the caret automatically
;;    invoke EndPaint, [esi].hWnd, addr PS                ;Restores the caret if it was previously
;    xor eax, eax                                        ;   hidden by BeginPaint
;MethodEnd
;
