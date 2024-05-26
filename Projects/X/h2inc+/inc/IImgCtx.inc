;Include file created by h2inc+ version C.2.0 on (UTC) 25/05/2024 20:55:09
;(C) G. Friedrich April 2024
;Source file: d:\objasm\projects\x\h2inc+\h\um_10.0.22621.0\iimgctx.h
;             Created on (UTC) 06/04/2024 06:15:55
;             Last modified on (UTC) 16/12/2023 11:07:06

ifndef _IImgCtxObjects_H_
  _IImgCtxObjects_H_ equ <>
  include winapifamily.inc
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    ifdef __cplusplus
      ;[...]
    endif
    TYPE_PFNIMGCTXCALLBACK typedef proto WIN_STD_CALL_CONV :ptr, :ptr
    PFNIMGCTXCALLBACK typedef ptr TYPE_PFNIMGCTXCALLBACK

    ifdef __cplusplus
      ;[...]
    endif
    IMGCHG_SIZE equ 0001h
    IMGCHG_VIEW equ 0002h
    IMGCHG_COMPLETE equ 0004h
    IMGCHG_ANIMATE equ 0008h
    IMGCHG_MASK equ 000Fh
    IMGLOAD_NOTLOADED equ 00100000h
    IMGLOAD_LOADING equ 00200000h
    IMGLOAD_STOPPED equ 00400000h
    IMGLOAD_ERROR equ 00800000h
    IMGLOAD_COMPLETE equ 01000000h
    IMGLOAD_MASK equ 01F00000h
    IMGBITS_NONE equ 02000000h
    IMGBITS_PARTIAL equ 04000000h
    IMGBITS_TOTAL equ 08000000h
    IMGBITS_MASK equ 0E000000h
    IMGANIM_ANIMATED equ 10000000h
    IMGANIM_MASK equ 10000000h
    IMGTRANS_OPAQUE equ 20000000h
    IMGTRANS_MASK equ 20000000h
    DWN_COLORMODE equ 0000003Fh
    DWN_DOWNLOADONLY equ 00000040h
    DWN_FORCEDITHER equ 00000080h
    DWN_RAWIMAGE equ 00000100h
    DWN_MIRRORIMAGE equ 00000200h
    INTERFACE equ <IImgCtx>
    DEFINE_GUID IID_IImgCtx, 3050f3d7h, 98b5h, 11cfh, 0bbh, 82h, 00h, 0aah, 00h, 0bdh, 0ceh, 0bh
    DECLARE_INTERFACE_(IImgCtx, IUnknown)
      ifndef NO_BASEINTERFACE_FUNCS
        STDMETHOD QueryInterface, :, :ptr 
        STDMETHOD_ ULONG, AddRef
        STDMETHOD_ ULONG, Release
      endif
      STDMETHOD Load, :, :
      STDMETHOD SelectChanges, :, :, :
      STDMETHOD SetCallback, :, :ptr 
      STDMETHOD Disconnect
      STDMETHOD GetUpdateRects, :ptr , :ptr , :ptr 
      STDMETHOD GetStateInfo, :ptr , :ptr , :
      STDMETHOD GetPalette, :ptr 
      STDMETHOD Draw, :, :ptr 
      STDMETHOD Tile, :, :ptr , :ptr , :ptr 
      STDMETHOD StretchBlt, :, :, :, :, :, :, :, :, :, :
    DECLARE_INTERFACE__END

    ifdef COBJMACROS
      ;[...]
    endif
    DEFINE_GUID CLSID_IImgCtx, 3050f3d6h, 98b5h, 11cfh, 0bbh, 82h, 00h, 0aah, 00h, 0bdh, 0ceh, 0bh
  endif
endif
