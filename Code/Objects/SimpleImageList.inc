; ==================================================================================================
; Title:      SimpleImageList.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm support of windows Imagelist objects.
; Notes:      Include CommCtrl.inc & Comctl32.lib
;             Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


IL_GrowFactor    equ    5

; --------------------------------------------------------------------------------------------------
; Object:     SimpleImageList
; Purpose:    Implement a thin wrapper around the ImageList GDI object.
;             An ImageList is a collection of same-sized images, each of which can be referred to by
;             its index. Image lists are used to efficiently manage large sets of icons or bitmaps.
;             All images in an image list are contained in a single, wide bitmap in screen device
;             format.

Object SimpleImageList, SimpleImageListID, Streamable
  VirtualMethod       Append,           HBITMAP
  RedefineMethod      Done
  VirtualMethod       Draw,             DWORD, HDC, DWORD, DWORD
  VirtualMethod       GetCount
  VirtualMethod       GetInfo,          DWORD, POINTER
  VirtualMethod       GetSize,          PPOINT
  RedefineMethod      Init,             POINTER, DWORD, DWORD, DWORD
  VirtualMethod       Remove,           DWORD
  VirtualMethod       RemoveAll
  VirtualMethod       Replace,          DWORD, HBITMAP

  DefineVariable      hImageList,       HIMAGELIST,   0
ObjectEnd


; ==================================================================================================

if IMPLEMENT

; --------------------------------------------------------------------------------------------------
; Method:     SimpleImageList.Append
; Purpose:    Append an new image to the control. hBmp must be deleted (DeleteObject)
;             after SimpleImageList.Append.
; Arguments:  Arg1: Image handle.
; Return:     eax = Image index into control. -1 if failed.

Method SimpleImageList.Append,, hImage:HBITMAP
  SetObject xcx
  invoke ImageList_Add, [xcx].hImageList, hImage, NULL
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     SimpleImageList.Done
; Purpose:    Finalize the ImageList control.
; Arguments:  None.
; Return:     Nothing.

Method SimpleImageList.Done
  SetObject xcx
  invoke ImageList_Destroy, [xcx].hImageList
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     SimpleImageList.Draw
; Purpose:    Draw an image on a DC at the specified coordinates.
; Arguments:  Arg1: Index of the image to draw.
;             Arg2: Device context handle.
;             Arg3: X position on the device context.
;             Arg4: Y position on the device context.
; Return:     Nothing.

Method SimpleImageList.Draw,, dIndex:DWORD, hDC:HDC, dPx:DWORD, dPy:DWORD
  SetObject xcx
  invoke ImageList_Draw, [xcx].hImageList, dIndex, hDC, dPx, dPy, ILD_NORMAL
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     SimpleImageList.GetCount
; Purpose:    Return the number of images in the ImageList.
; Arguments:  None.
; Return:     eax = Number of images.

Method SimpleImageList.GetCount
  SetObject xcx
  invoke ImageList_GetImageCount, [xcx].hImageList
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     SimpleImageList.GetInfo
; Purpose:    Return information about an image in the InageList.
; Arguments:  Arg1: Image index.
;             Arg2: -> IMAGEINFO structure.
; Return:     eax = TRUE if succeeded. FALSE if failed.

Method SimpleImageList.GetInfo,, dIndex:DWORD, pInfo:POINTER
  SetObject xcx
  invoke ImageList_GetImageInfo, [xcx].hImageList, dIndex, pInfo
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     SimpleImageList.GetSize
; Purpose:    Return the height and width of the images in the list.
; Arguments:  Arg1: -> POINT structure.
; Return:     eax = Zero if failed.

Method SimpleImageList.GetSize,, pPoint:PPOINT
  SetObject xcx
  mov xax, pPoint
  add xax, sizeof(SDWORD)
  invoke ImageList_GetIconSize, [xcx].hImageList, pPoint, xax
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     SimpleImageList.Init
; Purpose:    Initialize the object.
; Arguments:  Arg1: Image X size in pixels.
;             Arg2: Image Y size in pixels.
;             Arg3: Number of images that the image list initially contains.
; Return:     eax = ImageList handle.

Method SimpleImageList.Init,, pOwner:POINTER, dSX:DWORD, dSY:DWORD, dInitCount:DWORD
  invoke ImageList_Create, dSX, dSY, ILC_COLOR32, dInitCount, IL_GrowFactor
  SetObject xcx,, pSelf
  mov [xcx].hImageList, xax
  ACall xcx.Init, pOwner
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     SimpleImageList.Remove
; Purpose:    Remove an image from the control.
; Arguments:  Arg1: Index of the image that will be removed.
; Return:     eax = TRUE if succeeded, FALSE if failed.

Method SimpleImageList.Remove,, dIndex:DWORD
  SetObject xcx
  invoke ImageList_Remove, [xcx].hImageList, dIndex
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     SimpleImageList.RemoveAll
; Purpose:    Remove all images from the control.
; Arguments:  None.
; Return:     Nothing.

Method SimpleImageList.RemoveAll, uses xbx xsi
  SetObject xsi
  invoke ImageList_GetImageCount, [xsi].hImageList
  mov ebx, eax
  dec ebx
  jmp @@2
@@1:
  invoke ImageList_Remove, [xsi].hImageList, ebx
  dec ebx
@@2:
  jns @@1
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     SimpleImageList.Replace
; Purpose:    Replace an image in the control. hImage must be deleted (DeleteObject)
;             after SimpleImageList.Replace.
; Arguments:  Arg1: Index of the image that will be replaced.
;             Arg2: New Image handle.
; Return:     eax = TRUE if succeeded. FALSE if failed.

Method SimpleImageList.Replace,, dIndex:DWORD, hImage:HBITMAP
  SetObject xcx
  invoke ImageList_Replace, [xcx].hImageList, dIndex, hImage, NULL
MethodEnd

endif
