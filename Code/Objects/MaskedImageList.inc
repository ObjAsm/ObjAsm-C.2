; ==================================================================================================
; Title:      MaskedImageList.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm support of windows Imagelist GDI objects.
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


; --------------------------------------------------------------------------------------------------
; Object:     MaskedImageList
; Purpose:    Implement a thin wrapper around the ImageList GDI object with monochrome bitmap masks
;             used to draw images with transparency (icon style).
;             An ImageList is a collection of same-sized images, each of which can be referred
;             to by its index. Image lists are used to efficiently manage large sets of icons or
;             bitmaps. All images in an image list are contained in a single, wide bitmap in screen
;             device format.

Object MaskedImageList, MaskedImageListID, SimpleImageList
  RedefineMethod      Append,           HBITMAP, HBITMAP
  VirtualMethod       DrawEmbossed,     DWORD, HDC, DWORD, DWORD
  RedefineMethod      Init,             POINTER, DWORD, DWORD, DWORD
  RedefineMethod      Replace,          DWORD, HBITMAP, HBITMAP
  VirtualMethod       IconAppend,       HICON
  VirtualMethod       IconCreate,       DWORD, DWORD
  VirtualMethod       IconLoadResource, POINTER
ObjectEnd


; ==================================================================================================

if IMPLEMENT

; --------------------------------------------------------------------------------------------------
; Method:     MaskedImageList.Append
; Purpose:    Append a new image to the ImageList. After calling this method, hBmp & hMask may
;             be deleted using the DeleteObject API.
; Arguments:  Arg1: Image handle.
;             Arg2: Mask handle.
; Return:     eax = Image index into control. -1 if failed.

Method MaskedImageList.Append,, hBmp:HBITMAP, hMask:HBITMAP
  SetObject xcx
  invoke ImageList_Add, [xcx].hImageList, hBmp, hMask
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     MaskedImageList.DrawEmbossed
; Purpose:    Draw an embossed image on a DC at the specified coordiantes.
; Arguments:  Arg1: Index of the image to draw.
;             Arg2: Device context handle.
;             Arg3: X position on the device context.
;             Arg4: Y position on the device context.
; Return:     Nothing.

Method MaskedImageList.DrawEmbossed, uses xsi, dIndex:DWORD, hDC:HDC, dPx:DWORD, dPy:DWORD
  local dCx:DWORD, dCy:DWORD, hMemDC:HDC
  local hBmp:HBITMAP, hPrevBmp:HBITMAP, dPrevBackColor:DWORD
  local hShadowBrush:HBRUSH, hHiliteBrush:HBRUSH, hPrevBrush:HBRUSH

  SetObject xsi
  invoke ImageList_GetIconSize, [xsi].hImageList, addr dCx, addr dCy
  mov hMemDC, $invoke(CreateCompatibleDC, hDC)
  mov hBmp, $invoke(CreateCompatibleBitmap, hDC, dCx, dCy)
  mov hPrevBmp, $invoke(SelectObject, hMemDC, hBmp)
  invoke PatBlt, hMemDC, 0, 0, dCx, dCy, WHITENESS
  invoke ImageList_Draw, [xsi].hImageList, dIndex, hMemDC, 0, 0, ILD_TRANSPARENT
  invoke SetBkColor, hDC, $RGB(255,255,255)
  mov dPrevBackColor, eax
  invoke GetSysColor, COLOR_BTNSHADOW
  mov hShadowBrush, $invoke(CreateSolidBrush, eax)
  invoke GetSysColor, COLOR_BTNHILIGHT
  invoke CreateSolidBrush, eax
  mov hHiliteBrush, xax
  mov hPrevBrush, $invoke(SelectObject, hDC, hHiliteBrush)
  inc dPx
  inc dPy
  invoke BitBlt, hDC, dPx, dPy, dCx, dCy, hMemDC, 0, 0, MAGICROP
  invoke SelectObject, hDC, hShadowBrush
  dec dPx
  dec dPy
  invoke BitBlt, hDC, dPx, dPy, dCx, dCy, hMemDC, 0, 0, MAGICROP
  invoke SelectObject, hDC, hPrevBrush
  invoke SetBkColor, hDC, dPrevBackColor
  invoke SelectObject, hMemDC, hPrevBmp

  invoke DeleteObject, hHiliteBrush
  invoke DeleteObject, hShadowBrush
  invoke DeleteObject, hBmp
  invoke DeleteDC, hMemDC
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     MaskedImageList.IconAppend
; Purpose:    Append a new icon to the ImageList. hIcon must not be deleted if loaded
;             with LoadIcon.
; Arguments:  Arg1: Icon handle.
; Return:     eax = Icon index into control. -1 if failed.

Method MaskedImageList.IconAppend,, hIcon:HICON
  SetObject xcx
  invoke ImageList_ReplaceIcon, [xcx].hImageList, -1, hIcon
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     MaskedImageList.IconCreate
; Purpose:    Create a new icon from the ImageList. The created icon must be deleted if no
;             longer needed.
; Arguments:  Arg1: Index into MaskedImageList.
;             Arg2: Icon creation flags.
; Return:     xax = Icon HANDLE or zero if failed.

Method MaskedImageList.IconCreate,, dIndex:DWORD, dFlags:DWORD
  SetObject xcx
  invoke ImageList_GetIcon, [xcx].hImageList, dIndex, dFlags
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     MaskedImageList.IconLoadResource
; Purpose:    Load a new icon from a resource.
; Arguments:  Arg1: -> Resource name.
; Return:     eax = Icon index into control. -1 if failed.

Method MaskedImageList.IconLoadResource, uses xbx xsi, pResName:POINTER
  SetObject xsi
  invoke LoadIcon, hInstance, pResName
  mov xbx, xax
  invoke ImageList_ReplaceIcon, [xsi].hImageList, -1, xbx
  mov xsi, xax
  invoke DestroyIcon, xbx
  mov xax, xsi
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:   	MaskedImageList.Init
; Purpose:  	Initialize the ImageList control.
; Arguments:	Arg1: -> Owner object.
;           	Arg2: Image X size in pixels.
;           	Arg3: Image Y size in pixels.
;           	Arg4: Number of images that the image list initially may contain.
; Return:   	xax = HIMAGELIST.

Method MaskedImageList.Init, uses xsi, pOwner:POINTER, dSX:DWORD, dSY:DWORD, dInitCount:DWORD
  SetObject xsi
  invoke ImageList_Create, dSX, dSY, ILC_MASK or ILC_COLOR32, dInitCount, IL_GrowFactor
  mov [xsi].hImageList, xax
  m2m [xsi].pOwner, pOwner, xcx
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:   	MaskedImageList.Replace
; Purpose:  	Replace an image in the control. hBmp & hMask must be deleted (DeleteObject)
;           	after MaskedImageList.Replace.
; Arguments:	Arg1: Index of the image that will be replaced.
;           	Arg2: New image handle.
;           	Arg3: New mask handle.
; Return:   	eax = TRUE if succeeded, otherwise FALSE.

Method MaskedImageList.Replace,, dIndex:DWORD, hBmp:HBITMAP, hMask:HBITMAP
  SetObject xcx
  invoke ImageList_Replace, [xcx].hImageList, dIndex, hBmp, hMask
MethodEnd

endif
