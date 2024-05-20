;Include file created by h2inc+ version C.2.0 on (UTC) 20/05/2024 18:06:34
;(C) G. Friedrich April 2024
;Source file: d:\objasm\projects\x\h2inc+\h\um_10.0.22621.0\dsound.h
;             Created on (UTC) 06/04/2024 06:15:55
;             Last modified on (UTC) 21/02/2024 18:13:16

;**************************************************************************
include winapifamily.inc
if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
  COM_NO_WINDOWS_H equ <>
  include objbase.inc
  include float.inc
  include sal.inc
  ifndef DIRECTSOUND_VERSION
    ;* Windows 2000 *
    if (NTDDI_VERSION lt NTDDI_WINXP)
      ;* Version 7.0 *
      DIRECTSOUND_VERSION equ 0700h
      ;* Windows XP and SP1, or Windows Server 2003 *
    elseif (NTDDI_VERSION lt NTDDI_WINXPSP2 or NTDDI_VERSION eq NTDDI_WS03)
      ;* Version 8.0 *
      DIRECTSOUND_VERSION equ 0800h
      ;* Windows XP SP2 and higher, Windows Server 2003 SP1 and higher, Longhorn, or higher *
    else
      ;* Version 9.0 *
      DIRECTSOUND_VERSION equ 0900h
    endif
  endif
  ; DIRECTSOUND_VERSION
  ifdef __cplusplus
    ;[...]
  endif
  ; __cplusplus
  ifndef __DSOUND_INCLUDED__
    __DSOUND_INCLUDED__ equ <>
    ;* Type definitions shared with Direct3D *
    ifndef DX_SHARED_DEFINES
      D3DVALUE typedef REAL4
      LPD3DVALUE typedef ptr REAL4
      ifndef D3DCOLOR_DEFINED
        D3DCOLOR typedef DWORD
        D3DCOLOR_DEFINED equ <>
      endif
      ifndef LPD3DCOLOR_DEFINED
        LPD3DCOLOR typedef ptr DWORD
        LPD3DCOLOR_DEFINED equ <>
      endif
      ifndef D3DVECTOR_DEFINED
        D3DVECTOR struct
          x REAL4 ?
          y REAL4 ?
          z REAL4 ?
        D3DVECTOR ends
        _D3DVECTOR typedef D3DVECTOR
        D3DVECTOR_DEFINED equ <>
      endif
      ifndef LPD3DVECTOR_DEFINED
        LPD3DVECTOR typedef ptr D3DVECTOR
        LPD3DVECTOR_DEFINED equ <>
      endif
      DX_SHARED_DEFINES equ <>
    endif
    ; DX_SHARED_DEFINES
    ;* DirectSound's facility code *
    _FACDS equ 878h
    MAKE_DSHRESULT macro code
      exitm <MAKE_HRESULT(1, _FACDS, code)>
    endm
    ; DirectSound Component GUID {47D4D946-62E8-11CF-93BC-444553540000}
    DEFINE_GUID CLSID_DirectSound, 47d4d946h, 62e8h, 11cfh, 93h, 0bch, 44h, 45h, 53h, 54h, 0h, 0h
    ; DirectSound 8.0 Component GUID {3901CC3F-84B5-4FA4-BA35-AA8172B8A09B}
    DEFINE_GUID CLSID_DirectSound8, 3901cc3fh, 84b5h, 4fa4h, 0bah, 35h, 0aah, 81h, 72h, 0b8h, 0a0h, 9bh
    ; DirectSound Capture Component GUID {B0210780-89CD-11D0-AF08-00A0C925CD16}
    DEFINE_GUID CLSID_DirectSoundCapture, 0b0210780h, 89cdh, 11d0h, 0afh, 8h, 0h, 0a0h, 0c9h, 25h, 0cdh, 16h
    ; DirectSound 8.0 Capture Component GUID {E4BCAC13-7F99-4908-9A8E-74E3BF24B6E1}
    DEFINE_GUID CLSID_DirectSoundCapture8, 0e4bcac13h, 7f99h, 4908h, 9ah, 8eh, 74h, 0e3h, 0bfh, 24h, 0b6h, 0e1h
    ; DirectSound Full Duplex Component GUID {FEA4300C-7959-4147-B26A-2377B9E7A91D}
    DEFINE_GUID CLSID_DirectSoundFullDuplex, 0fea4300ch, 7959h, 4147h, 0b2h, 6ah, 23h, 77h, 0b9h, 0e7h, 0a9h, 1dh
    ; DirectSound default playback device GUID {DEF00000-9C6D-47ED-AAF1-4DDA8F2B5C03}
    DEFINE_GUID DSDEVID_DefaultPlayback, 0def00000h, 9c6dh, 47edh, 0aah, 0f1h, 4dh, 0dah, 8fh, 2bh, 5ch, 03h
    ; DirectSound default capture device GUID {DEF00001-9C6D-47ED-AAF1-4DDA8F2B5C03}
    DEFINE_GUID DSDEVID_DefaultCapture, 0def00001h, 9c6dh, 47edh, 0aah, 0f1h, 4dh, 0dah, 8fh, 2bh, 5ch, 03h
    ; DirectSound default device for voice playback {DEF00002-9C6D-47ED-AAF1-4DDA8F2B5C03}
    DEFINE_GUID DSDEVID_DefaultVoicePlayback, 0def00002h, 9c6dh, 47edh, 0aah, 0f1h, 4dh, 0dah, 8fh, 2bh, 5ch, 03h
    ; DirectSound default device for voice capture {DEF00003-9C6D-47ED-AAF1-4DDA8F2B5C03}
    DEFINE_GUID DSDEVID_DefaultVoiceCapture, 0def00003h, 9c6dh, 47edh, 0aah, 0f1h, 4dh, 0dah, 8fh, 2bh, 5ch, 03h
    ; Forward declarations for interfaces.
    ; 'struct' not 'class' per the way DECLARE_INTERFACE_ is defined
    ifdef __cplusplus
      ;[...]
    endif
    ; __cplusplus
    ; DirectSound 8.0 interfaces.
    if DIRECTSOUND_VERSION ge 0800h
      ifdef __cplusplus
        ;[...]
      endif
      ; __cplusplus
      ; IDirectSound8, IDirectSoundBuffer8 and IDirectSoundCaptureBuffer8 are the
      ; only DirectSound 7.0 interfaces with changed functionality in version 8.0.
      ; The other level 8 interfaces as equivalent to their level 7 counterparts:
      IDirectSoundCapture8 equ <IDirectSoundCapture>
      IDirectSound3DListener8 equ <IDirectSound3DListener>
      IDirectSound3DBuffer8 equ <IDirectSound3DBuffer>
      IDirectSoundNotify8 equ <IDirectSoundNotify>
      IDirectSoundFXGargle8 equ <IDirectSoundFXGargle>
      IDirectSoundFXChorus8 equ <IDirectSoundFXChorus>
      IDirectSoundFXFlanger8 equ <IDirectSoundFXFlanger>
      IDirectSoundFXEcho8 equ <IDirectSoundFXEcho>
      IDirectSoundFXDistortion8 equ <IDirectSoundFXDistortion>
      IDirectSoundFXCompressor8 equ <IDirectSoundFXCompressor>
      IDirectSoundFXParamEq8 equ <IDirectSoundFXParamEq>
      IDirectSoundFXWavesReverb8 equ <IDirectSoundFXWavesReverb>
      IDirectSoundFXI3DL2Reverb8 equ <IDirectSoundFXI3DL2Reverb>
      IDirectSoundCaptureFXAec8 equ <IDirectSoundCaptureFXAec>
      IDirectSoundCaptureFXNoiseSuppress8 equ <IDirectSoundCaptureFXNoiseSuppress>
      IDirectSoundFullDuplex8 equ <IDirectSoundFullDuplex>
    endif
    ; DIRECTSOUND_VERSION >= 0x0800
    LPDIRECTSOUND typedef ptr IDirectSound
    LPDIRECTSOUNDBUFFER typedef ptr IDirectSoundBuffer
    LPDIRECTSOUND3DLISTENER typedef ptr IDirectSound3DListener
    LPDIRECTSOUND3DBUFFER typedef ptr IDirectSound3DBuffer
    LPDIRECTSOUNDCAPTURE typedef ptr IDirectSoundCapture
    LPDIRECTSOUNDCAPTUREBUFFER typedef ptr IDirectSoundCaptureBuffer
    LPDIRECTSOUNDNOTIFY typedef ptr IDirectSoundNotify
    if DIRECTSOUND_VERSION ge 0800h
      LPDIRECTSOUNDFXGARGLE typedef ptr IDirectSoundFXGargle
      LPDIRECTSOUNDFXCHORUS typedef ptr IDirectSoundFXChorus
      LPDIRECTSOUNDFXFLANGER typedef ptr IDirectSoundFXFlanger
      LPDIRECTSOUNDFXECHO typedef ptr IDirectSoundFXEcho
      LPDIRECTSOUNDFXDISTORTION typedef ptr IDirectSoundFXDistortion
      LPDIRECTSOUNDFXCOMPRESSOR typedef ptr IDirectSoundFXCompressor
      LPDIRECTSOUNDFXPARAMEQ typedef ptr IDirectSoundFXParamEq
      LPDIRECTSOUNDFXWAVESREVERB typedef ptr IDirectSoundFXWavesReverb
      LPDIRECTSOUNDFXI3DL2REVERB typedef ptr IDirectSoundFXI3DL2Reverb
      LPDIRECTSOUNDCAPTUREFXAEC typedef ptr IDirectSoundCaptureFXAec
      LPDIRECTSOUNDCAPTUREFXNOISESUPPRESS typedef ptr IDirectSoundCaptureFXNoiseSuppress
      LPDIRECTSOUNDFULLDUPLEX typedef ptr IDirectSoundFullDuplex
      LPDIRECTSOUND8 typedef ptr IDirectSound8
      LPDIRECTSOUNDBUFFER8 typedef ptr IDirectSoundBuffer8
      LPDIRECTSOUND3DLISTENER8 typedef ptr IDirectSound3DListener8
      LPDIRECTSOUND3DBUFFER8 typedef ptr IDirectSound3DBuffer8
      LPDIRECTSOUNDCAPTURE8 typedef ptr IDirectSoundCapture8
      LPDIRECTSOUNDCAPTUREBUFFER8 typedef ptr IDirectSoundCaptureBuffer8
      LPDIRECTSOUNDNOTIFY8 typedef ptr IDirectSoundNotify8
      LPDIRECTSOUNDFXGARGLE8 typedef ptr IDirectSoundFXGargle8
      LPDIRECTSOUNDFXCHORUS8 typedef ptr IDirectSoundFXChorus8
      LPDIRECTSOUNDFXFLANGER8 typedef ptr IDirectSoundFXFlanger8
      LPDIRECTSOUNDFXECHO8 typedef ptr IDirectSoundFXEcho8
      LPDIRECTSOUNDFXDISTORTION8 typedef ptr IDirectSoundFXDistortion8
      LPDIRECTSOUNDFXCOMPRESSOR8 typedef ptr IDirectSoundFXCompressor8
      LPDIRECTSOUNDFXPARAMEQ8 typedef ptr IDirectSoundFXParamEq8
      LPDIRECTSOUNDFXWAVESREVERB8 typedef ptr IDirectSoundFXWavesReverb8
      LPDIRECTSOUNDFXI3DL2REVERB8 typedef ptr IDirectSoundFXI3DL2Reverb8
      LPDIRECTSOUNDCAPTUREFXAEC8 typedef ptr IDirectSoundCaptureFXAec8
      LPDIRECTSOUNDCAPTUREFXNOISESUPPRESS8 typedef ptr IDirectSoundCaptureFXNoiseSuppress8
      LPDIRECTSOUNDFULLDUPLEX8 typedef ptr IDirectSoundFullDuplex8
    endif
    ; DIRECTSOUND_VERSION >= 0x0800
    ; IID definitions for the unchanged DirectSound 8.0 interfaces
    if DIRECTSOUND_VERSION ge 0800h
      IID_IDirectSoundCapture8 equ <IID_IDirectSoundCapture>
      IID_IDirectSound3DListener8 equ <IID_IDirectSound3DListener>
      IID_IDirectSound3DBuffer8 equ <IID_IDirectSound3DBuffer>
      IID_IDirectSoundNotify8 equ <IID_IDirectSoundNotify>
      IID_IDirectSoundFXGargle8 equ <IID_IDirectSoundFXGargle>
      IID_IDirectSoundFXChorus8 equ <IID_IDirectSoundFXChorus>
      IID_IDirectSoundFXFlanger8 equ <IID_IDirectSoundFXFlanger>
      IID_IDirectSoundFXEcho8 equ <IID_IDirectSoundFXEcho>
      IID_IDirectSoundFXDistortion8 equ <IID_IDirectSoundFXDistortion>
      IID_IDirectSoundFXCompressor8 equ <IID_IDirectSoundFXCompressor>
      IID_IDirectSoundFXParamEq8 equ <IID_IDirectSoundFXParamEq>
      IID_IDirectSoundFXWavesReverb8 equ <IID_IDirectSoundFXWavesReverb>
      IID_IDirectSoundFXI3DL2Reverb8 equ <IID_IDirectSoundFXI3DL2Reverb>
      IID_IDirectSoundCaptureFXAec8 equ <IID_IDirectSoundCaptureFXAec>
      IID_IDirectSoundCaptureFXNoiseSuppress8 equ <IID_IDirectSoundCaptureFXNoiseSuppress>
      IID_IDirectSoundFullDuplex8 equ <IID_IDirectSoundFullDuplex>
    endif
    ; DIRECTSOUND_VERSION >= 0x0800
    ; Compatibility typedefs
    ifndef _LPCWAVEFORMATEX_DEFINED
      _LPCWAVEFORMATEX_DEFINED equ <>
      LPCWAVEFORMATEX typedef ptr WAVEFORMATEX
    endif
    ; _LPCWAVEFORMATEX_DEFINED
    ifndef __LPCGUID_DEFINED__
      __LPCGUID_DEFINED__ equ <>
      LPCGUID typedef ptr GUID
    endif
    ; __LPCGUID_DEFINED__
    LPLPDIRECTSOUND typedef ptr LPDIRECTSOUND
    LPLPDIRECTSOUNDBUFFER typedef ptr LPDIRECTSOUNDBUFFER
    LPLPDIRECTSOUND3DLISTENER typedef ptr LPDIRECTSOUND3DLISTENER
    LPLPDIRECTSOUND3DBUFFER typedef ptr LPDIRECTSOUND3DBUFFER
    LPLPDIRECTSOUNDCAPTURE typedef ptr LPDIRECTSOUNDCAPTURE
    LPLPDIRECTSOUNDCAPTUREBUFFER typedef ptr LPDIRECTSOUNDCAPTUREBUFFER
    LPLPDIRECTSOUNDNOTIFY typedef ptr LPDIRECTSOUNDNOTIFY
    if DIRECTSOUND_VERSION ge 0800h
      LPLPDIRECTSOUND8 typedef ptr LPDIRECTSOUND8
      LPLPDIRECTSOUNDBUFFER8 typedef ptr LPDIRECTSOUNDBUFFER8
      LPLPDIRECTSOUNDCAPTURE8 typedef ptr LPDIRECTSOUNDCAPTURE8
      LPLPDIRECTSOUNDCAPTUREBUFFER8 typedef ptr LPDIRECTSOUNDCAPTUREBUFFER8
    endif
    ; DIRECTSOUND_VERSION >= 0x0800
    ; Structures
    DSCAPS struct
      dwSize DWORD ?
      dwFlags DWORD ?
      dwMinSecondarySampleRate DWORD ?
      dwMaxSecondarySampleRate DWORD ?
      dwPrimaryBuffers DWORD ?
      dwMaxHwMixingAllBuffers DWORD ?
      dwMaxHwMixingStaticBuffers DWORD ?
      dwMaxHwMixingStreamingBuffers DWORD ?
      dwFreeHwMixingAllBuffers DWORD ?
      dwFreeHwMixingStaticBuffers DWORD ?
      dwFreeHwMixingStreamingBuffers DWORD ?
      dwMaxHw3DAllBuffers DWORD ?
      dwMaxHw3DStaticBuffers DWORD ?
      dwMaxHw3DStreamingBuffers DWORD ?
      dwFreeHw3DAllBuffers DWORD ?
      dwFreeHw3DStaticBuffers DWORD ?
      dwFreeHw3DStreamingBuffers DWORD ?
      dwTotalHwMemBytes DWORD ?
      dwFreeHwMemBytes DWORD ?
      dwMaxContigFreeHwMemBytes DWORD ?
      dwUnlockTransferRateHwBuffers DWORD ?
      dwPlayCpuOverheadSwBuffers DWORD ?
      dwReserved1 DWORD ?
      dwReserved2 DWORD ?
    DSCAPS ends
    _DSCAPS typedef DSCAPS
    LPDSCAPS typedef ptr DSCAPS
    LPCDSCAPS typedef ptr DSCAPS
    DSBCAPS struct
      dwSize DWORD ?
      dwFlags DWORD ?
      dwBufferBytes DWORD ?
      dwUnlockTransferRate DWORD ?
      dwPlayCpuOverhead DWORD ?
    DSBCAPS ends
    _DSBCAPS typedef DSBCAPS
    LPDSBCAPS typedef ptr DSBCAPS
    LPCDSBCAPS typedef ptr DSBCAPS
    if DIRECTSOUND_VERSION ge 0800h
      DSEFFECTDESC struct
        dwSize DWORD ?
        dwFlags DWORD ?
        guidDSFXClass GUID <>
        dwReserved1 XWORD ?
        dwReserved2 XWORD ?
      DSEFFECTDESC ends
      _DSEFFECTDESC typedef DSEFFECTDESC
      LPDSEFFECTDESC typedef ptr DSEFFECTDESC
      LPCDSEFFECTDESC typedef ptr DSEFFECTDESC
      DSFX_LOCHARDWARE equ 00000001h
      DSFX_LOCSOFTWARE equ 00000002h
      DSFXR_PRESENT equ 0
      ; 0
      DSFXR_LOCHARDWARE equ 1
      ; 1
      DSFXR_LOCSOFTWARE equ 2
      ; 2
      DSFXR_UNALLOCATED equ 3
      ; 3
      DSFXR_FAILED equ 4
      ; 4
      DSFXR_UNKNOWN equ 5
      ; 5
      DSFXR_SENDLOOP equ 6

      ; 6
      DSCEFFECTDESC struct
        dwSize DWORD ?
        dwFlags DWORD ?
        guidDSCFXClass GUID <>
        guidDSCFXInstance GUID <>
        dwReserved1 DWORD ?
        dwReserved2 DWORD ?
      DSCEFFECTDESC ends
      _DSCEFFECTDESC typedef DSCEFFECTDESC
      LPDSCEFFECTDESC typedef ptr DSCEFFECTDESC
      LPCDSCEFFECTDESC typedef ptr DSCEFFECTDESC
      DSCFX_LOCHARDWARE equ 00000001h
      DSCFX_LOCSOFTWARE equ 00000002h
      DSCFXR_LOCHARDWARE equ 00000010h
      DSCFXR_LOCSOFTWARE equ 00000020h
    endif
    ; DIRECTSOUND_VERSION >= 0x0800
    DSBUFFERDESC struct
      dwSize DWORD ?
      dwFlags DWORD ?
      dwBufferBytes DWORD ?
      dwReserved DWORD ?
      lpwfxFormat LPWAVEFORMATEX ?
      if DIRECTSOUND_VERSION ge 0700h
        guid3DAlgorithm GUID <>
      endif
    DSBUFFERDESC ends
    _DSBUFFERDESC typedef DSBUFFERDESC
    LPDSBUFFERDESC typedef ptr DSBUFFERDESC
    LPCDSBUFFERDESC typedef ptr DSBUFFERDESC
    ; Older version of this structure:
    DSBUFFERDESC1 struct
      dwSize DWORD ?
      dwFlags DWORD ?
      dwBufferBytes DWORD ?
      dwReserved DWORD ?
      lpwfxFormat LPWAVEFORMATEX ?
    DSBUFFERDESC1 ends
    _DSBUFFERDESC1 typedef DSBUFFERDESC1
    LPDSBUFFERDESC1 typedef ptr DSBUFFERDESC1
    LPCDSBUFFERDESC1 typedef ptr DSBUFFERDESC1
    DS3DBUFFER struct
      dwSize DWORD ?
      vPosition D3DVECTOR <>
      vVelocity D3DVECTOR <>
      dwInsideConeAngle DWORD ?
      dwOutsideConeAngle DWORD ?
      vConeOrientation D3DVECTOR <>
      lConeOutsideVolume SDWORD ?
      flMinDistance D3DVALUE ?
      flMaxDistance D3DVALUE ?
      dwMode DWORD ?
    DS3DBUFFER ends
    _DS3DBUFFER typedef DS3DBUFFER
    LPDS3DBUFFER typedef ptr DS3DBUFFER
    LPCDS3DBUFFER typedef ptr DS3DBUFFER
    DS3DLISTENER struct
      dwSize DWORD ?
      vPosition D3DVECTOR <>
      vVelocity D3DVECTOR <>
      vOrientFront D3DVECTOR <>
      vOrientTop D3DVECTOR <>
      flDistanceFactor D3DVALUE ?
      flRolloffFactor D3DVALUE ?
      flDopplerFactor D3DVALUE ?
    DS3DLISTENER ends
    _DS3DLISTENER typedef DS3DLISTENER
    LPDS3DLISTENER typedef ptr DS3DLISTENER
    LPCDS3DLISTENER typedef ptr DS3DLISTENER
    DSCCAPS struct
      dwSize DWORD ?
      dwFlags DWORD ?
      dwFormats DWORD ?
      dwChannels DWORD ?
    DSCCAPS ends
    _DSCCAPS typedef DSCCAPS
    LPDSCCAPS typedef ptr DSCCAPS
    LPCDSCCAPS typedef ptr DSCCAPS
    DSCBUFFERDESC1 struct
      dwSize DWORD ?
      dwFlags DWORD ?
      dwBufferBytes DWORD ?
      dwReserved DWORD ?
      lpwfxFormat LPWAVEFORMATEX ?
    DSCBUFFERDESC1 ends
    _DSCBUFFERDESC1 typedef DSCBUFFERDESC1
    LPDSCBUFFERDESC1 typedef ptr DSCBUFFERDESC1
    DSCBUFFERDESC struct
      dwSize DWORD ?
      dwFlags DWORD ?
      dwBufferBytes DWORD ?
      dwReserved DWORD ?
      lpwfxFormat LPWAVEFORMATEX ?
      if DIRECTSOUND_VERSION ge 0800h
        dwFXCount DWORD ?
        lpDSCFXDesc LPDSCEFFECTDESC ?
      endif
    DSCBUFFERDESC ends
    _DSCBUFFERDESC typedef DSCBUFFERDESC
    LPDSCBUFFERDESC typedef ptr DSCBUFFERDESC
    LPCDSCBUFFERDESC typedef ptr DSCBUFFERDESC
    DSCBCAPS struct
      dwSize DWORD ?
      dwFlags DWORD ?
      dwBufferBytes DWORD ?
      dwReserved DWORD ?
    DSCBCAPS ends
    _DSCBCAPS typedef DSCBCAPS
    LPDSCBCAPS typedef ptr DSCBCAPS
    LPCDSCBCAPS typedef ptr DSCBCAPS
    DSBPOSITIONNOTIFY struct
      dwOffset DWORD ?
      hEventNotify HANDLE ?
    DSBPOSITIONNOTIFY ends
    _DSBPOSITIONNOTIFY typedef DSBPOSITIONNOTIFY
    LPDSBPOSITIONNOTIFY typedef ptr DSBPOSITIONNOTIFY
    LPCDSBPOSITIONNOTIFY typedef ptr DSBPOSITIONNOTIFY
    ; DirectSound API
    TYPE_LPDSENUMCALLBACKA typedef proto WIN_STD_CALL_CONV :LPGUID, :LPCSTR, :LPCSTR, :LPVOID
    LPDSENUMCALLBACKA typedef ptr TYPE_LPDSENUMCALLBACKA

    TYPE_LPDSENUMCALLBACKW typedef proto WIN_STD_CALL_CONV :LPGUID, :LPCWSTR, :LPCWSTR, :LPVOID
    LPDSENUMCALLBACKW typedef ptr TYPE_LPDSENUMCALLBACKW

    DirectSoundCreate proto WIN_STD_CALL_CONV :LPCGUID, :ptr LPDIRECTSOUND, :LPUNKNOWN
    DirectSoundEnumerateA proto WIN_STD_CALL_CONV :LPDSENUMCALLBACKA, :LPVOID
    DirectSoundEnumerateW proto WIN_STD_CALL_CONV :LPDSENUMCALLBACKW, :LPVOID
    DirectSoundCaptureCreate proto WIN_STD_CALL_CONV :LPCGUID, :ptr LPDIRECTSOUNDCAPTURE, :LPUNKNOWN
    DirectSoundCaptureEnumerateA proto WIN_STD_CALL_CONV :LPDSENUMCALLBACKA, :LPVOID
    DirectSoundCaptureEnumerateW proto WIN_STD_CALL_CONV :LPDSENUMCALLBACKW, :LPVOID
    if DIRECTSOUND_VERSION ge 0800h
      DirectSoundCreate8 proto WIN_STD_CALL_CONV :LPCGUID, :ptr LPDIRECTSOUND8, :LPUNKNOWN
      DirectSoundCaptureCreate8 proto WIN_STD_CALL_CONV :LPCGUID, :ptr LPDIRECTSOUNDCAPTURE8, :LPUNKNOWN
      DirectSoundFullDuplexCreate proto WIN_STD_CALL_CONV :LPCGUID, :LPCGUID, :LPCDSCBUFFERDESC, :LPCDSBUFFERDESC, :HWND, :DWORD, :ptr LPDIRECTSOUNDFULLDUPLEX, :ptr LPDIRECTSOUNDCAPTUREBUFFER8, :ptr LPDIRECTSOUNDBUFFER8, :LPUNKNOWN
      DirectSoundFullDuplexCreate8 equ <DirectSoundFullDuplexCreate>
      GetDeviceID proto WIN_STD_CALL_CONV :LPCGUID, :LPGUID
    endif
    ; DIRECTSOUND_VERSION >= 0x0800
    ifdef UNICODE
      LPDSENUMCALLBACK equ <LPDSENUMCALLBACKW>
      DirectSoundEnumerate equ <DirectSoundEnumerateW>
      DirectSoundCaptureEnumerate equ <DirectSoundCaptureEnumerateW>
    else
    ; UNICODE
      LPDSENUMCALLBACK equ <LPDSENUMCALLBACKA>
      DirectSoundEnumerate equ <DirectSoundEnumerateA>
      DirectSoundCaptureEnumerate equ <DirectSoundCaptureEnumerateA>
    endif
    ; UNICODE
    ; IUnknown
    if  not Defined(__cplusplus) or Defined(CINTERFACE)
      ifndef IUnknown_QueryInterface
        IUnknown_QueryInterface macro p, a, b
          exitm <(p) - lpVtbl - QueryInterface (p, a, b)>
        endm
      endif
      ; IUnknown_QueryInterface
      ifndef IUnknown_AddRef
        IUnknown_AddRef macro p
          exitm <(p) - lpVtbl - AddRef (p)>
        endm
      endif
      ; IUnknown_AddRef
      ifndef IUnknown_Release
        IUnknown_Release macro p
          exitm <(p) - lpVtbl - Release (p)>
        endm
      endif
      ; IUnknown_Release
    else
    ; !defined(__cplusplus) || defined(CINTERFACE)
      ;[...]
      ; IUnknown_QueryInterface
      ; IUnknown_AddRef
      ; IUnknown_Release
    endif
    ; !defined(__cplusplus) || defined(CINTERFACE)
    ifndef __IReferenceClock_INTERFACE_DEFINED__
      __IReferenceClock_INTERFACE_DEFINED__ equ <>
      REFERENCE_TIME typedef LONGLONG
      LPREFERENCE_TIME typedef ptr REFERENCE_TIME
      DEFINE_GUID IID_IReferenceClock, 56a86897h, 0ad4h, 11ceh, 0b0h, 3ah, 00h, 20h, 0afh, 0bh, 0a7h, 70h
      INTERFACE equ <IReferenceClock>
      DECLARE_INTERFACE_(IReferenceClock, IUnknown)
        ??Interface equ <DSBPOSITIONNOTIFY>
        ; IUnknown methods
        STDMETHOD QueryInterface, :REFIID, :ptr POINTER
        STDMETHOD_ ULONG, AddRef
        STDMETHOD_ ULONG, Release
        ; IReferenceClock methods
        STDMETHOD GetTime, :ptr REFERENCE_TIME
        STDMETHOD AdviseTime, :REFERENCE_TIME, :REFERENCE_TIME, :HANDLE, :LPDWORD
        STDMETHOD AdvisePeriodic, :REFERENCE_TIME, :REFERENCE_TIME, :HANDLE, :LPDWORD
        STDMETHOD Unadvise, :DWORD
      DECLARE_INTERFACE__END

    endif
    ; __IReferenceClock_INTERFACE_DEFINED__
    ifndef IReferenceClock_QueryInterface
      IReferenceClock_QueryInterface macro p, a, b
        exitm <IUnknown_QueryInterface(p, a, b)>
      endm
      IReferenceClock_AddRef macro p
        exitm <IUnknown_AddRef(p)>
      endm
      IReferenceClock_Release macro p
        exitm <IUnknown_Release(p)>
      endm
      if  not Defined(__cplusplus) or Defined(CINTERFACE)
        IReferenceClock_GetTime macro p, a
          exitm <(p) - lpVtbl - GetTime (p, a)>
        endm
        IReferenceClock_AdviseTime macro p, a, b, c_, d
          exitm <(p) - lpVtbl - AdviseTime (p, a, b, c_, d)>
        endm
        IReferenceClock_AdvisePeriodic macro p, a, b, c_, d
          exitm <(p) - lpVtbl - AdvisePeriodic (p, a, b, c_, d)>
        endm
        IReferenceClock_Unadvise macro p, a
          exitm <(p) - lpVtbl - Unadvise (p, a)>
        endm
      else
      ; !defined(__cplusplus) || defined(CINTERFACE)
        ;[...]
      endif
      ; !defined(__cplusplus) || defined(CINTERFACE)
    endif
    ; IReferenceClock_QueryInterface
    ; IDirectSound
    DEFINE_GUID IID_IDirectSound, 279AFA83h, 4981h, 11CEh, 0A5h, 21h, 00h, 20h, 0AFh, 0Bh, 0E5h, 60h
    INTERFACE equ <IDirectSound>
    DECLARE_INTERFACE_(IDirectSound, IUnknown)
      ??Interface equ <DSBPOSITIONNOTIFY>
      ; IUnknown methods
      STDMETHOD QueryInterface, :REFIID, :ptr POINTER
      STDMETHOD_ ULONG, AddRef
      STDMETHOD_ ULONG, Release
      ; IDirectSound methods
      STDMETHOD CreateSoundBuffer, :LPCDSBUFFERDESC, :ptr LPDIRECTSOUNDBUFFER, :LPUNKNOWN
      STDMETHOD GetCaps, :LPDSCAPS
      STDMETHOD DuplicateSoundBuffer, :LPDIRECTSOUNDBUFFER, :ptr LPDIRECTSOUNDBUFFER
      STDMETHOD SetCooperativeLevel, :HWND, :DWORD
      STDMETHOD Compact_
      STDMETHOD GetSpeakerConfig, :LPDWORD
      STDMETHOD SetSpeakerConfig, :DWORD
      STDMETHOD Initialize, :LPCGUID
    DECLARE_INTERFACE__END

    IDirectSound_QueryInterface macro p, a, b
      exitm <IUnknown_QueryInterface(p, a, b)>
    endm
    IDirectSound_AddRef macro p
      exitm <IUnknown_AddRef(p)>
    endm
    IDirectSound_Release macro p
      exitm <IUnknown_Release(p)>
    endm
    if  not Defined(__cplusplus) or Defined(CINTERFACE)
      IDirectSound_CreateSoundBuffer macro p, a, b, c_
        exitm <(p) - lpVtbl - CreateSoundBuffer (p, a, b, c_)>
      endm
      IDirectSound_GetCaps macro p, a
        exitm <(p) - lpVtbl - GetCaps (p, a)>
      endm
      IDirectSound_DuplicateSoundBuffer macro p, a, b
        exitm <(p) - lpVtbl - DuplicateSoundBuffer (p, a, b)>
      endm
      IDirectSound_SetCooperativeLevel macro p, a, b
        exitm <(p) - lpVtbl - SetCooperativeLevel (p, a, b)>
      endm
      IDirectSound_Compact macro p
        exitm <(p) - lpVtbl - Compact (p)>
      endm
      IDirectSound_GetSpeakerConfig macro p, a
        exitm <(p) - lpVtbl - GetSpeakerConfig (p, a)>
      endm
      IDirectSound_SetSpeakerConfig macro p, b
        exitm <(p) - lpVtbl - SetSpeakerConfig (p, b)>
      endm
      IDirectSound_Initialize macro p, a
        exitm <(p) - lpVtbl - Initialize (p, a)>
      endm
    else
    ; !defined(__cplusplus) || defined(CINTERFACE)
      ;[...]
    endif
    ; !defined(__cplusplus) || defined(CINTERFACE)
    if DIRECTSOUND_VERSION ge 0800h
      ; IDirectSound8
      DEFINE_GUID IID_IDirectSound8, 0C50A7E93h, 0F395h, 4834h, 9Eh, 0F6h, 7Fh, 0A9h, 9Dh, 0E5h, 09h, 66h
      INTERFACE equ <IDirectSound8>
      DECLARE_INTERFACE_(IDirectSound8, IDirectSound)
        ??Interface equ <DSBPOSITIONNOTIFY>
        ; IUnknown methods
        STDMETHOD QueryInterface, :REFIID, :ptr POINTER
        STDMETHOD_ ULONG, AddRef
        STDMETHOD_ ULONG, Release
        ; IDirectSound methods
        STDMETHOD CreateSoundBuffer, :LPCDSBUFFERDESC, :ptr LPDIRECTSOUNDBUFFER, :LPUNKNOWN
        STDMETHOD GetCaps, :LPDSCAPS
        STDMETHOD DuplicateSoundBuffer, :LPDIRECTSOUNDBUFFER, :ptr LPDIRECTSOUNDBUFFER
        STDMETHOD SetCooperativeLevel, :HWND, :DWORD
        STDMETHOD Compact_
        STDMETHOD GetSpeakerConfig, :LPDWORD
        STDMETHOD SetSpeakerConfig, :DWORD
        STDMETHOD Initialize, :LPCGUID
        ; IDirectSound8 methods
        STDMETHOD VerifyCertification, :LPDWORD
      DECLARE_INTERFACE__END

      IDirectSound8_QueryInterface macro p, a, b
        exitm <IDirectSound_QueryInterface(p, a, b)>
      endm
      IDirectSound8_AddRef macro p
        exitm <IDirectSound_AddRef(p)>
      endm
      IDirectSound8_Release macro p
        exitm <IDirectSound_Release(p)>
      endm
      IDirectSound8_CreateSoundBuffer macro p, a, b, c_
        exitm <IDirectSound_CreateSoundBuffer(p, a, b, c_)>
      endm
      IDirectSound8_GetCaps macro p, a
        exitm <IDirectSound_GetCaps(p, a)>
      endm
      IDirectSound8_DuplicateSoundBuffer macro p, a, b
        exitm <IDirectSound_DuplicateSoundBuffer(p, a, b)>
      endm
      IDirectSound8_SetCooperativeLevel macro p, a, b
        exitm <IDirectSound_SetCooperativeLevel(p, a, b)>
      endm
      IDirectSound8_Compact macro p
        exitm <IDirectSound_Compact(p)>
      endm
      IDirectSound8_GetSpeakerConfig macro p, a
        exitm <IDirectSound_GetSpeakerConfig(p, a)>
      endm
      IDirectSound8_SetSpeakerConfig macro p, a
        exitm <IDirectSound_SetSpeakerConfig(p, a)>
      endm
      IDirectSound8_Initialize macro p, a
        exitm <IDirectSound_Initialize(p, a)>
      endm
      if  not Defined(__cplusplus) or Defined(CINTERFACE)
        IDirectSound8_VerifyCertification macro p, a
          exitm <(p) - lpVtbl - VerifyCertification (p, a)>
        endm
      else
      ; !defined(__cplusplus) || defined(CINTERFACE)
        ;[...]
      endif
      ; !defined(__cplusplus) || defined(CINTERFACE)
    endif
    ; DIRECTSOUND_VERSION >= 0x0800
    ; IDirectSoundBuffer
    DEFINE_GUID IID_IDirectSoundBuffer, 279AFA85h, 4981h, 11CEh, 0A5h, 21h, 00h, 20h, 0AFh, 0Bh, 0E5h, 60h
    INTERFACE equ <IDirectSoundBuffer>
    DECLARE_INTERFACE_(IDirectSoundBuffer, IUnknown)
      ??Interface equ <DSBPOSITIONNOTIFY>
      ; IUnknown methods
      STDMETHOD QueryInterface, :REFIID, :ptr POINTER
      STDMETHOD_ ULONG, AddRef
      STDMETHOD_ ULONG, Release
      ; IDirectSoundBuffer methods
      STDMETHOD GetCaps, :LPDSBCAPS
      STDMETHOD GetCurrentPosition, :LPDWORD, :LPDWORD
      STDMETHOD GetFormat, :LPWAVEFORMATEX, :DWORD, :LPDWORD
      STDMETHOD GetVolume, :LPLONG
      STDMETHOD GetPan, :LPLONG
      STDMETHOD GetFrequency, :LPDWORD
      STDMETHOD GetStatus, :LPDWORD
      STDMETHOD Initialize, :LPDIRECTSOUND, :LPCDSBUFFERDESC
      STDMETHOD Lock_, :DWORD, :DWORD, :ptr POINTER, :LPDWORD, :ptr POINTER, :LPDWORD, :DWORD
      STDMETHOD Play, :DWORD, :DWORD, :DWORD
      STDMETHOD SetCurrentPosition, :DWORD
      STDMETHOD SetFormat, :LPCWAVEFORMATEX
      STDMETHOD SetVolume, :SDWORD
      STDMETHOD SetPan, :SDWORD
      STDMETHOD SetFrequency, :DWORD
      STDMETHOD Stop
      STDMETHOD Unlock, :POINTER, :DWORD, :POINTER, :DWORD
      STDMETHOD Restore
    DECLARE_INTERFACE__END

    IDirectSoundBuffer_QueryInterface macro p, a, b
      exitm <IUnknown_QueryInterface(p, a, b)>
    endm
    IDirectSoundBuffer_AddRef macro p
      exitm <IUnknown_AddRef(p)>
    endm
    IDirectSoundBuffer_Release macro p
      exitm <IUnknown_Release(p)>
    endm
    if  not Defined(__cplusplus) or Defined(CINTERFACE)
      IDirectSoundBuffer_GetCaps macro p, a
        exitm <(p) - lpVtbl - GetCaps (p, a)>
      endm
      IDirectSoundBuffer_GetCurrentPosition macro p, a, b
        exitm <(p) - lpVtbl - GetCurrentPosition (p, a, b)>
      endm
      IDirectSoundBuffer_GetFormat macro p, a, b, c_
        exitm <(p) - lpVtbl - GetFormat (p, a, b, c_)>
      endm
      IDirectSoundBuffer_GetVolume macro p, a
        exitm <(p) - lpVtbl - GetVolume (p, a)>
      endm
      IDirectSoundBuffer_GetPan macro p, a
        exitm <(p) - lpVtbl - GetPan (p, a)>
      endm
      IDirectSoundBuffer_GetFrequency macro p, a
        exitm <(p) - lpVtbl - GetFrequency (p, a)>
      endm
      IDirectSoundBuffer_GetStatus macro p, a
        exitm <(p) - lpVtbl - GetStatus (p, a)>
      endm
      IDirectSoundBuffer_Initialize macro p, a, b
        exitm <(p) - lpVtbl - Initialize (p, a, b)>
      endm
      IDirectSoundBuffer_Lock macro p, a, b, c_, d, e, f, g
        exitm <(p) - lpVtbl - Lock (p, a, b, c_, d, e, f, g)>
      endm
      IDirectSoundBuffer_Play macro p, a, b, c_
        exitm <(p) - lpVtbl - Play (p, a, b, c_)>
      endm
      IDirectSoundBuffer_SetCurrentPosition macro p, a
        exitm <(p) - lpVtbl - SetCurrentPosition (p, a)>
      endm
      IDirectSoundBuffer_SetFormat macro p, a
        exitm <(p) - lpVtbl - SetFormat (p, a)>
      endm
      IDirectSoundBuffer_SetVolume macro p, a
        exitm <(p) - lpVtbl - SetVolume (p, a)>
      endm
      IDirectSoundBuffer_SetPan macro p, a
        exitm <(p) - lpVtbl - SetPan (p, a)>
      endm
      IDirectSoundBuffer_SetFrequency macro p, a
        exitm <(p) - lpVtbl - SetFrequency (p, a)>
      endm
      IDirectSoundBuffer_Stop macro p
        exitm <(p) - lpVtbl - Stop (p)>
      endm
      IDirectSoundBuffer_Unlock macro p, a, b, c_, d
        exitm <(p) - lpVtbl - Unlock (p, a, b, c_, d)>
      endm
      IDirectSoundBuffer_Restore macro p
        exitm <(p) - lpVtbl - Restore (p)>
      endm
    else
    ; !defined(__cplusplus) || defined(CINTERFACE)
      ;[...]
    endif
    ; !defined(__cplusplus) || defined(CINTERFACE)
    if DIRECTSOUND_VERSION ge 0800h
      ; IDirectSoundBuffer8
      DEFINE_GUID IID_IDirectSoundBuffer8, 6825a449h, 7524h, 4d82h, 92h, 0fh, 50h, 0e3h, 6ah, 0b3h, 0abh, 1eh
      INTERFACE equ <IDirectSoundBuffer8>
      DECLARE_INTERFACE_(IDirectSoundBuffer8, IDirectSoundBuffer)
        ??Interface equ <DSBPOSITIONNOTIFY>
        ; IUnknown methods
        STDMETHOD QueryInterface, :REFIID, :ptr POINTER
        STDMETHOD_ ULONG, AddRef
        STDMETHOD_ ULONG, Release
        ; IDirectSoundBuffer methods
        STDMETHOD GetCaps, :LPDSBCAPS
        STDMETHOD GetCurrentPosition, :LPDWORD, :LPDWORD
        STDMETHOD GetFormat, :LPWAVEFORMATEX, :DWORD, :LPDWORD
        STDMETHOD GetVolume, :LPLONG
        STDMETHOD GetPan, :LPLONG
        STDMETHOD GetFrequency, :LPDWORD
        STDMETHOD GetStatus, :LPDWORD
        STDMETHOD Initialize, :LPDIRECTSOUND, :LPCDSBUFFERDESC
        STDMETHOD Lock_, :DWORD, :DWORD, :ptr POINTER, :LPDWORD, :ptr POINTER, :LPDWORD, :DWORD
        STDMETHOD Play, :DWORD, :DWORD, :DWORD
        STDMETHOD SetCurrentPosition, :DWORD
        STDMETHOD SetFormat, :LPCWAVEFORMATEX
        STDMETHOD SetVolume, :SDWORD
        STDMETHOD SetPan, :SDWORD
        STDMETHOD SetFrequency, :DWORD
        STDMETHOD Stop
        STDMETHOD Unlock, :POINTER, :DWORD, :POINTER, :DWORD
        STDMETHOD Restore
        ; IDirectSoundBuffer8 methods
        STDMETHOD SetFX, :DWORD, :LPDSEFFECTDESC, :LPDWORD
        STDMETHOD AcquireResources, :DWORD, :DWORD, :LPDWORD
        STDMETHOD GetObjectInPath, :REFGUID, :DWORD, :REFGUID, :ptr POINTER
      DECLARE_INTERFACE__END

      ; Special GUID meaning "select all objects" for use in GetObjectInPath()
      DEFINE_GUID GUID_All_Objects, 0aa114de5h, 0c262h, 4169h, 0a1h, 0c8h, 23h, 0d6h, 98h, 0cch, 73h, 0b5h
      IDirectSoundBuffer8_QueryInterface macro p, a, b
        exitm <IUnknown_QueryInterface(p, a, b)>
      endm
      IDirectSoundBuffer8_AddRef macro p
        exitm <IUnknown_AddRef(p)>
      endm
      IDirectSoundBuffer8_Release macro p
        exitm <IUnknown_Release(p)>
      endm
      IDirectSoundBuffer8_GetCaps macro p, a
        exitm <IDirectSoundBuffer_GetCaps(p, a)>
      endm
      IDirectSoundBuffer8_GetCurrentPosition macro p, a, b
        exitm <IDirectSoundBuffer_GetCurrentPosition(p, a, b)>
      endm
      IDirectSoundBuffer8_GetFormat macro p, a, b, c_
        exitm <IDirectSoundBuffer_GetFormat(p, a, b, c_)>
      endm
      IDirectSoundBuffer8_GetVolume macro p, a
        exitm <IDirectSoundBuffer_GetVolume(p, a)>
      endm
      IDirectSoundBuffer8_GetPan macro p, a
        exitm <IDirectSoundBuffer_GetPan(p, a)>
      endm
      IDirectSoundBuffer8_GetFrequency macro p, a
        exitm <IDirectSoundBuffer_GetFrequency(p, a)>
      endm
      IDirectSoundBuffer8_GetStatus macro p, a
        exitm <IDirectSoundBuffer_GetStatus(p, a)>
      endm
      IDirectSoundBuffer8_Initialize macro p, a, b
        exitm <IDirectSoundBuffer_Initialize(p, a, b)>
      endm
      IDirectSoundBuffer8_Lock macro p, a, b, c_, d, e, f, g
        exitm <IDirectSoundBuffer_Lock(p, a, b, c_, d, e, f, g)>
      endm
      IDirectSoundBuffer8_Play macro p, a, b, c_
        exitm <IDirectSoundBuffer_Play(p, a, b, c_)>
      endm
      IDirectSoundBuffer8_SetCurrentPosition macro p, a
        exitm <IDirectSoundBuffer_SetCurrentPosition(p, a)>
      endm
      IDirectSoundBuffer8_SetFormat macro p, a
        exitm <IDirectSoundBuffer_SetFormat(p, a)>
      endm
      IDirectSoundBuffer8_SetVolume macro p, a
        exitm <IDirectSoundBuffer_SetVolume(p, a)>
      endm
      IDirectSoundBuffer8_SetPan macro p, a
        exitm <IDirectSoundBuffer_SetPan(p, a)>
      endm
      IDirectSoundBuffer8_SetFrequency macro p, a
        exitm <IDirectSoundBuffer_SetFrequency(p, a)>
      endm
      IDirectSoundBuffer8_Stop macro p
        exitm <IDirectSoundBuffer_Stop(p)>
      endm
      IDirectSoundBuffer8_Unlock macro p, a, b, c_, d
        exitm <IDirectSoundBuffer_Unlock(p, a, b, c_, d)>
      endm
      IDirectSoundBuffer8_Restore macro p
        exitm <IDirectSoundBuffer_Restore(p)>
      endm
      if  not Defined(__cplusplus) or Defined(CINTERFACE)
        IDirectSoundBuffer8_SetFX macro p, a, b, c_
          exitm <(p) - lpVtbl - SetFX (p, a, b, c_)>
        endm
        IDirectSoundBuffer8_AcquireResources macro p, a, b, c_
          exitm <(p) - lpVtbl - AcquireResources (p, a, b, c_)>
        endm
        IDirectSoundBuffer8_GetObjectInPath macro p, a, b, c_, d
          exitm <(p) - lpVtbl - GetObjectInPath (p, a, b, c_, d)>
        endm
      else
      ; !defined(__cplusplus) || defined(CINTERFACE)
        ;[...]
      endif
      ; !defined(__cplusplus) || defined(CINTERFACE)
    endif
    ; DIRECTSOUND_VERSION >= 0x0800
    ; IDirectSound3DListener
    DEFINE_GUID IID_IDirectSound3DListener, 279AFA84h, 4981h, 11CEh, 0A5h, 21h, 00h, 20h, 0AFh, 0Bh, 0E5h, 60h
    INTERFACE equ <IDirectSound3DListener>
    DECLARE_INTERFACE_(IDirectSound3DListener, IUnknown)
      ??Interface equ <DSBPOSITIONNOTIFY>
      ; IUnknown methods
      STDMETHOD QueryInterface, :REFIID, :ptr POINTER
      STDMETHOD_ ULONG, AddRef
      STDMETHOD_ ULONG, Release
      ; IDirectSound3DListener methods
      STDMETHOD GetAllParameters, :LPDS3DLISTENER
      STDMETHOD GetDistanceFactor, :ptr D3DVALUE
      STDMETHOD GetDopplerFactor, :ptr D3DVALUE
      STDMETHOD GetOrientation, :ptr D3DVECTOR, :ptr D3DVECTOR
      STDMETHOD GetPosition, :ptr D3DVECTOR
      STDMETHOD GetRolloffFactor, :ptr D3DVALUE
      STDMETHOD GetVelocity, :ptr D3DVECTOR
      STDMETHOD SetAllParameters, :LPCDS3DLISTENER, :DWORD
      STDMETHOD SetDistanceFactor, :D3DVALUE, :DWORD
      STDMETHOD SetDopplerFactor, :D3DVALUE, :DWORD
      STDMETHOD SetOrientation, :D3DVALUE, :D3DVALUE, :D3DVALUE, :D3DVALUE, :D3DVALUE, :D3DVALUE, :DWORD
      STDMETHOD SetPosition, :D3DVALUE, :D3DVALUE, :D3DVALUE, :DWORD
      STDMETHOD SetRolloffFactor, :D3DVALUE, :DWORD
      STDMETHOD SetVelocity, :D3DVALUE, :D3DVALUE, :D3DVALUE, :DWORD
      STDMETHOD CommitDeferredSettings
    DECLARE_INTERFACE__END

    IDirectSound3DListener_QueryInterface macro p, a, b
      exitm <IUnknown_QueryInterface(p, a, b)>
    endm
    IDirectSound3DListener_AddRef macro p
      exitm <IUnknown_AddRef(p)>
    endm
    IDirectSound3DListener_Release macro p
      exitm <IUnknown_Release(p)>
    endm
    if  not Defined(__cplusplus) or Defined(CINTERFACE)
      IDirectSound3DListener_GetAllParameters macro p, a
        exitm <(p) - lpVtbl - GetAllParameters (p, a)>
      endm
      IDirectSound3DListener_GetDistanceFactor macro p, a
        exitm <(p) - lpVtbl - GetDistanceFactor (p, a)>
      endm
      IDirectSound3DListener_GetDopplerFactor macro p, a
        exitm <(p) - lpVtbl - GetDopplerFactor (p, a)>
      endm
      IDirectSound3DListener_GetOrientation macro p, a, b
        exitm <(p) - lpVtbl - GetOrientation (p, a, b)>
      endm
      IDirectSound3DListener_GetPosition macro p, a
        exitm <(p) - lpVtbl - GetPosition (p, a)>
      endm
      IDirectSound3DListener_GetRolloffFactor macro p, a
        exitm <(p) - lpVtbl - GetRolloffFactor (p, a)>
      endm
      IDirectSound3DListener_GetVelocity macro p, a
        exitm <(p) - lpVtbl - GetVelocity (p, a)>
      endm
      IDirectSound3DListener_SetAllParameters macro p, a, b
        exitm <(p) - lpVtbl - SetAllParameters (p, a, b)>
      endm
      IDirectSound3DListener_SetDistanceFactor macro p, a, b
        exitm <(p) - lpVtbl - SetDistanceFactor (p, a, b)>
      endm
      IDirectSound3DListener_SetDopplerFactor macro p, a, b
        exitm <(p) - lpVtbl - SetDopplerFactor (p, a, b)>
      endm
      IDirectSound3DListener_SetOrientation macro p, a, b, c_, d, e, f, g
        exitm <(p) - lpVtbl - SetOrientation (p, a, b, c_, d, e, f, g)>
      endm
      IDirectSound3DListener_SetPosition macro p, a, b, c_, d
        exitm <(p) - lpVtbl - SetPosition (p, a, b, c_, d)>
      endm
      IDirectSound3DListener_SetRolloffFactor macro p, a, b
        exitm <(p) - lpVtbl - SetRolloffFactor (p, a, b)>
      endm
      IDirectSound3DListener_SetVelocity macro p, a, b, c_, d
        exitm <(p) - lpVtbl - SetVelocity (p, a, b, c_, d)>
      endm
      IDirectSound3DListener_CommitDeferredSettings macro p
        exitm <(p) - lpVtbl - CommitDeferredSettings (p)>
      endm
    else
    ; !defined(__cplusplus) || defined(CINTERFACE)
      ;[...]
    endif
    ; !defined(__cplusplus) || defined(CINTERFACE)
    ; IDirectSound3DBuffer
    DEFINE_GUID IID_IDirectSound3DBuffer, 279AFA86h, 4981h, 11CEh, 0A5h, 21h, 00h, 20h, 0AFh, 0Bh, 0E5h, 60h
    INTERFACE equ <IDirectSound3DBuffer>
    DECLARE_INTERFACE_(IDirectSound3DBuffer, IUnknown)
      ??Interface equ <DSBPOSITIONNOTIFY>
      ; IUnknown methods
      STDMETHOD QueryInterface, :REFIID, :ptr POINTER
      STDMETHOD_ ULONG, AddRef
      STDMETHOD_ ULONG, Release
      ; IDirectSound3DBuffer methods
      STDMETHOD GetAllParameters, :LPDS3DBUFFER
      STDMETHOD GetConeAngles, :LPDWORD, :LPDWORD
      STDMETHOD GetConeOrientation, :ptr D3DVECTOR
      STDMETHOD GetConeOutsideVolume, :LPLONG
      STDMETHOD GetMaxDistance, :ptr D3DVALUE
      STDMETHOD GetMinDistance, :ptr D3DVALUE
      STDMETHOD GetMode, :LPDWORD
      STDMETHOD GetPosition, :ptr D3DVECTOR
      STDMETHOD GetVelocity, :ptr D3DVECTOR
      STDMETHOD SetAllParameters, :LPCDS3DBUFFER, :DWORD
      STDMETHOD SetConeAngles, :DWORD, :DWORD, :DWORD
      STDMETHOD SetConeOrientation, :D3DVALUE, :D3DVALUE, :D3DVALUE, :DWORD
      STDMETHOD SetConeOutsideVolume, :SDWORD, :DWORD
      STDMETHOD SetMaxDistance, :D3DVALUE, :DWORD
      STDMETHOD SetMinDistance, :D3DVALUE, :DWORD
      STDMETHOD SetMode, :DWORD, :DWORD
      STDMETHOD SetPosition, :D3DVALUE, :D3DVALUE, :D3DVALUE, :DWORD
      STDMETHOD SetVelocity, :D3DVALUE, :D3DVALUE, :D3DVALUE, :DWORD
    DECLARE_INTERFACE__END

    IDirectSound3DBuffer_QueryInterface macro p, a, b
      exitm <IUnknown_QueryInterface(p, a, b)>
    endm
    IDirectSound3DBuffer_AddRef macro p
      exitm <IUnknown_AddRef(p)>
    endm
    IDirectSound3DBuffer_Release macro p
      exitm <IUnknown_Release(p)>
    endm
    if  not Defined(__cplusplus) or Defined(CINTERFACE)
      IDirectSound3DBuffer_GetAllParameters macro p, a
        exitm <(p) - lpVtbl - GetAllParameters (p, a)>
      endm
      IDirectSound3DBuffer_GetConeAngles macro p, a, b
        exitm <(p) - lpVtbl - GetConeAngles (p, a, b)>
      endm
      IDirectSound3DBuffer_GetConeOrientation macro p, a
        exitm <(p) - lpVtbl - GetConeOrientation (p, a)>
      endm
      IDirectSound3DBuffer_GetConeOutsideVolume macro p, a
        exitm <(p) - lpVtbl - GetConeOutsideVolume (p, a)>
      endm
      IDirectSound3DBuffer_GetPosition macro p, a
        exitm <(p) - lpVtbl - GetPosition (p, a)>
      endm
      IDirectSound3DBuffer_GetMinDistance macro p, a
        exitm <(p) - lpVtbl - GetMinDistance (p, a)>
      endm
      IDirectSound3DBuffer_GetMaxDistance macro p, a
        exitm <(p) - lpVtbl - GetMaxDistance (p, a)>
      endm
      IDirectSound3DBuffer_GetMode macro p, a
        exitm <(p) - lpVtbl - GetMode (p, a)>
      endm
      IDirectSound3DBuffer_GetVelocity macro p, a
        exitm <(p) - lpVtbl - GetVelocity (p, a)>
      endm
      IDirectSound3DBuffer_SetAllParameters macro p, a, b
        exitm <(p) - lpVtbl - SetAllParameters (p, a, b)>
      endm
      IDirectSound3DBuffer_SetConeAngles macro p, a, b, c_
        exitm <(p) - lpVtbl - SetConeAngles (p, a, b, c_)>
      endm
      IDirectSound3DBuffer_SetConeOrientation macro p, a, b, c_, d
        exitm <(p) - lpVtbl - SetConeOrientation (p, a, b, c_, d)>
      endm
      IDirectSound3DBuffer_SetConeOutsideVolume macro p, a, b
        exitm <(p) - lpVtbl - SetConeOutsideVolume (p, a, b)>
      endm
      IDirectSound3DBuffer_SetPosition macro p, a, b, c_, d
        exitm <(p) - lpVtbl - SetPosition (p, a, b, c_, d)>
      endm
      IDirectSound3DBuffer_SetMinDistance macro p, a, b
        exitm <(p) - lpVtbl - SetMinDistance (p, a, b)>
      endm
      IDirectSound3DBuffer_SetMaxDistance macro p, a, b
        exitm <(p) - lpVtbl - SetMaxDistance (p, a, b)>
      endm
      IDirectSound3DBuffer_SetMode macro p, a, b
        exitm <(p) - lpVtbl - SetMode (p, a, b)>
      endm
      IDirectSound3DBuffer_SetVelocity macro p, a, b, c_, d
        exitm <(p) - lpVtbl - SetVelocity (p, a, b, c_, d)>
      endm
    else
    ; !defined(__cplusplus) || defined(CINTERFACE)
      ;[...]
    endif
    ; !defined(__cplusplus) || defined(CINTERFACE)
    ; IDirectSoundCapture
    DEFINE_GUID IID_IDirectSoundCapture, 0b0210781h, 89cdh, 11d0h, 0afh, 8h, 0h, 0a0h, 0c9h, 25h, 0cdh, 16h
    INTERFACE equ <IDirectSoundCapture>
    DECLARE_INTERFACE_(IDirectSoundCapture, IUnknown)
      ??Interface equ <DSBPOSITIONNOTIFY>
      ; IUnknown methods
      STDMETHOD QueryInterface, :REFIID, :ptr POINTER
      STDMETHOD_ ULONG, AddRef
      STDMETHOD_ ULONG, Release
      ; IDirectSoundCapture methods
      STDMETHOD CreateCaptureBuffer, :LPCDSCBUFFERDESC, :ptr LPDIRECTSOUNDCAPTUREBUFFER, :LPUNKNOWN
      STDMETHOD GetCaps, :LPDSCCAPS
      STDMETHOD Initialize, :LPCGUID
    DECLARE_INTERFACE__END

    IDirectSoundCapture_QueryInterface macro p, a, b
      exitm <IUnknown_QueryInterface(p, a, b)>
    endm
    IDirectSoundCapture_AddRef macro p
      exitm <IUnknown_AddRef(p)>
    endm
    IDirectSoundCapture_Release macro p
      exitm <IUnknown_Release(p)>
    endm
    if  not Defined(__cplusplus) or Defined(CINTERFACE)
      IDirectSoundCapture_CreateCaptureBuffer macro p, a, b, c_
        exitm <(p) - lpVtbl - CreateCaptureBuffer (p, a, b, c_)>
      endm
      IDirectSoundCapture_GetCaps macro p, a
        exitm <(p) - lpVtbl - GetCaps (p, a)>
      endm
      IDirectSoundCapture_Initialize macro p, a
        exitm <(p) - lpVtbl - Initialize (p, a)>
      endm
    else
    ; !defined(__cplusplus) || defined(CINTERFACE)
      ;[...]
    endif
    ; !defined(__cplusplus) || defined(CINTERFACE)
    ; IDirectSoundCaptureBuffer
    DEFINE_GUID IID_IDirectSoundCaptureBuffer, 0b0210782h, 89cdh, 11d0h, 0afh, 8h, 0h, 0a0h, 0c9h, 25h, 0cdh, 16h
    INTERFACE equ <IDirectSoundCaptureBuffer>
    DECLARE_INTERFACE_(IDirectSoundCaptureBuffer, IUnknown)
      ??Interface equ <DSBPOSITIONNOTIFY>
      ; IUnknown methods
      STDMETHOD QueryInterface, :REFIID, :ptr POINTER
      STDMETHOD_ ULONG, AddRef
      STDMETHOD_ ULONG, Release
      ; IDirectSoundCaptureBuffer methods
      STDMETHOD GetCaps, :LPDSCBCAPS
      STDMETHOD GetCurrentPosition, :LPDWORD, :LPDWORD
      STDMETHOD GetFormat, :LPWAVEFORMATEX, :DWORD, :LPDWORD
      STDMETHOD GetStatus, :LPDWORD
      STDMETHOD Initialize, :LPDIRECTSOUNDCAPTURE, :LPCDSCBUFFERDESC
      STDMETHOD Lock_, :DWORD, :DWORD, :ptr POINTER, :LPDWORD, :ptr POINTER, :LPDWORD, :DWORD
      STDMETHOD Start, :DWORD
      STDMETHOD Stop
      STDMETHOD Unlock, :POINTER, :DWORD, :POINTER, :DWORD
    DECLARE_INTERFACE__END

    IDirectSoundCaptureBuffer_QueryInterface macro p, a, b
      exitm <IUnknown_QueryInterface(p, a, b)>
    endm
    IDirectSoundCaptureBuffer_AddRef macro p
      exitm <IUnknown_AddRef(p)>
    endm
    IDirectSoundCaptureBuffer_Release macro p
      exitm <IUnknown_Release(p)>
    endm
    if  not Defined(__cplusplus) or Defined(CINTERFACE)
      IDirectSoundCaptureBuffer_GetCaps macro p, a
        exitm <(p) - lpVtbl - GetCaps (p, a)>
      endm
      IDirectSoundCaptureBuffer_GetCurrentPosition macro p, a, b
        exitm <(p) - lpVtbl - GetCurrentPosition (p, a, b)>
      endm
      IDirectSoundCaptureBuffer_GetFormat macro p, a, b, c_
        exitm <(p) - lpVtbl - GetFormat (p, a, b, c_)>
      endm
      IDirectSoundCaptureBuffer_GetStatus macro p, a
        exitm <(p) - lpVtbl - GetStatus (p, a)>
      endm
      IDirectSoundCaptureBuffer_Initialize macro p, a, b
        exitm <(p) - lpVtbl - Initialize (p, a, b)>
      endm
      IDirectSoundCaptureBuffer_Lock macro p, a, b, c_, d, e, f, g
        exitm <(p) - lpVtbl - Lock (p, a, b, c_, d, e, f, g)>
      endm
      IDirectSoundCaptureBuffer_Start macro p, a
        exitm <(p) - lpVtbl - Start (p, a)>
      endm
      IDirectSoundCaptureBuffer_Stop macro p
        exitm <(p) - lpVtbl - Stop (p)>
      endm
      IDirectSoundCaptureBuffer_Unlock macro p, a, b, c_, d
        exitm <(p) - lpVtbl - Unlock (p, a, b, c_, d)>
      endm
    else
    ; !defined(__cplusplus) || defined(CINTERFACE)
      ;[...]
    endif
    ; !defined(__cplusplus) || defined(CINTERFACE)
    if DIRECTSOUND_VERSION ge 0800h
      ; IDirectSoundCaptureBuffer8
      DEFINE_GUID IID_IDirectSoundCaptureBuffer8, 990df4h, 0dbbh, 4872h, 83h, 3eh, 6dh, 30h, 3eh, 80h, 0aeh, 0b6h
      INTERFACE equ <IDirectSoundCaptureBuffer8>
      DECLARE_INTERFACE_(IDirectSoundCaptureBuffer8, IDirectSoundCaptureBuffer)
        ??Interface equ <DSBPOSITIONNOTIFY>
        ; IUnknown methods
        STDMETHOD QueryInterface, :REFIID, :ptr POINTER
        STDMETHOD_ ULONG, AddRef
        STDMETHOD_ ULONG, Release
        ; IDirectSoundCaptureBuffer methods
        STDMETHOD GetCaps, :LPDSCBCAPS
        STDMETHOD GetCurrentPosition, :LPDWORD, :LPDWORD
        STDMETHOD GetFormat, :LPWAVEFORMATEX, :DWORD, :LPDWORD
        STDMETHOD GetStatus, :LPDWORD
        STDMETHOD Initialize, :LPDIRECTSOUNDCAPTURE, :LPCDSCBUFFERDESC
        STDMETHOD Lock_, :DWORD, :DWORD, :ptr POINTER, :LPDWORD, :ptr POINTER, :LPDWORD, :DWORD
        STDMETHOD Start, :DWORD
        STDMETHOD Stop
        STDMETHOD Unlock, :POINTER, :DWORD, :POINTER, :DWORD
        ; IDirectSoundCaptureBuffer8 methods
        STDMETHOD GetObjectInPath, :REFGUID, :DWORD, :REFGUID, :ptr POINTER
        STDMETHOD GetFXStatus, :DWORD, :LPDWORD
      DECLARE_INTERFACE__END

      IDirectSoundCaptureBuffer8_QueryInterface macro p, a, b
        exitm <IUnknown_QueryInterface(p, a, b)>
      endm
      IDirectSoundCaptureBuffer8_AddRef macro p
        exitm <IUnknown_AddRef(p)>
      endm
      IDirectSoundCaptureBuffer8_Release macro p
        exitm <IUnknown_Release(p)>
      endm
      IDirectSoundCaptureBuffer8_GetCaps macro p, a
        exitm <IDirectSoundCaptureBuffer_GetCaps(p, a)>
      endm
      IDirectSoundCaptureBuffer8_GetCurrentPosition macro p, a, b
        exitm <IDirectSoundCaptureBuffer_GetCurrentPosition(p, a, b)>
      endm
      IDirectSoundCaptureBuffer8_GetFormat macro p, a, b, c_
        exitm <IDirectSoundCaptureBuffer_GetFormat(p, a, b, c_)>
      endm
      IDirectSoundCaptureBuffer8_GetStatus macro p, a
        exitm <IDirectSoundCaptureBuffer_GetStatus(p, a)>
      endm
      IDirectSoundCaptureBuffer8_Initialize macro p, a, b
        exitm <IDirectSoundCaptureBuffer_Initialize(p, a, b)>
      endm
      IDirectSoundCaptureBuffer8_Lock macro p, a, b, c_, d, e, f, g
        exitm <IDirectSoundCaptureBuffer_Lock(p, a, b, c_, d, e, f, g)>
      endm
      IDirectSoundCaptureBuffer8_Start macro p, a
        exitm <IDirectSoundCaptureBuffer_Start(p, a)>
      endm
      IDirectSoundCaptureBuffer8_Stop macro p
        exitm <IDirectSoundCaptureBuffer_Stop(p))>
      endm
      IDirectSoundCaptureBuffer8_Unlock macro p, a, b, c_, d
        exitm <IDirectSoundCaptureBuffer_Unlock(p, a, b, c_, d)>
      endm
      if  not Defined(__cplusplus) or Defined(CINTERFACE)
        IDirectSoundCaptureBuffer8_GetObjectInPath macro p, a, b, c_, d
          exitm <(p) - lpVtbl - GetObjectInPath (p, a, b, c_, d)>
        endm
        IDirectSoundCaptureBuffer8_GetFXStatus macro p, a, b
          exitm <(p) - lpVtbl - GetFXStatus (p, a, b)>
        endm
      else
      ; !defined(__cplusplus) || defined(CINTERFACE)
        ;[...]
      endif
      ; !defined(__cplusplus) || defined(CINTERFACE)
    endif
    ; DIRECTSOUND_VERSION >= 0x0800
    ; IDirectSoundNotify
    DEFINE_GUID IID_IDirectSoundNotify, 0b0210783h, 89cdh, 11d0h, 0afh, 8h, 0h, 0a0h, 0c9h, 25h, 0cdh, 16h
    INTERFACE equ <IDirectSoundNotify>
    DECLARE_INTERFACE_(IDirectSoundNotify, IUnknown)
      ??Interface equ <DSBPOSITIONNOTIFY>
      ; IUnknown methods
      STDMETHOD QueryInterface, :REFIID, :ptr POINTER
      STDMETHOD_ ULONG, AddRef
      STDMETHOD_ ULONG, Release
      ; IDirectSoundNotify methods
      STDMETHOD SetNotificationPositions, :DWORD, :LPCDSBPOSITIONNOTIFY
    DECLARE_INTERFACE__END

    IDirectSoundNotify_QueryInterface macro p, a, b
      exitm <IUnknown_QueryInterface(p, a, b)>
    endm
    IDirectSoundNotify_AddRef macro p
      exitm <IUnknown_AddRef(p)>
    endm
    IDirectSoundNotify_Release macro p
      exitm <IUnknown_Release(p)>
    endm
    if  not Defined(__cplusplus) or Defined(CINTERFACE)
      IDirectSoundNotify_SetNotificationPositions macro p, a, b
        exitm <(p) - lpVtbl - SetNotificationPositions (p, a, b)>
      endm
    else
    ; !defined(__cplusplus) || defined(CINTERFACE)
      ;[...]
    endif
    ; !defined(__cplusplus) || defined(CINTERFACE)
    ; IKsPropertySet
    ifndef _IKsPropertySet_
      _IKsPropertySet_ equ <>
      ifdef __cplusplus
        ;[...]
      endif
      ; __cplusplus
      LPKSPROPERTYSET typedef ptr IKsPropertySet
      KSPROPERTY_SUPPORT_GET equ 00000001h
      KSPROPERTY_SUPPORT_SET equ 00000002h
      DEFINE_GUID IID_IKsPropertySet, 31efac30h, 515ch, 11d0h, 0a9h, 0aah, 00h, 0aah, 00h, 61h, 0beh, 93h
      INTERFACE equ <IKsPropertySet>
      DECLARE_INTERFACE_(IKsPropertySet, IUnknown)
        ??Interface equ <DSBPOSITIONNOTIFY>
        ; IUnknown methods
        STDMETHOD QueryInterface, :REFIID, :ptr POINTER
        STDMETHOD_ ULONG, AddRef
        STDMETHOD_ ULONG, Release
        ; IKsPropertySet methods
        STDMETHOD Get, :REFGUID, :DWORD, :POINTER, :DWORD, :POINTER, :DWORD, :PULONG
        STDMETHOD Set, :REFGUID, :DWORD, :POINTER, :DWORD, :POINTER, :DWORD
        STDMETHOD QuerySupport, :REFGUID, :DWORD, :PULONG
      DECLARE_INTERFACE__END

      IKsPropertySet_QueryInterface macro p, a, b
        exitm <IUnknown_QueryInterface(p, a, b)>
      endm
      IKsPropertySet_AddRef macro p
        exitm <IUnknown_AddRef(p)>
      endm
      IKsPropertySet_Release macro p
        exitm <IUnknown_Release(p)>
      endm
      if  not Defined(__cplusplus) or Defined(CINTERFACE)
        IKsPropertySet_Get macro p, a, b, c_, d, e, f, g
          exitm <(p) - lpVtbl - Get (p, a, b, c_, d, e, f, g)>
        endm
        IKsPropertySet_Set macro p, a, b, c_, d, e, f
          exitm <(p) - lpVtbl - Set (p, a, b, c_, d, e, f)>
        endm
        IKsPropertySet_QuerySupport macro p, a, b, c_
          exitm <(p) - lpVtbl - QuerySupport (p, a, b, c_)>
        endm
      else
      ; !defined(__cplusplus) || defined(CINTERFACE)
        ;[...]
      endif
      ; !defined(__cplusplus) || defined(CINTERFACE)
    endif
    ; _IKsPropertySet_
    if DIRECTSOUND_VERSION ge 0800h
      ; IDirectSoundFXGargle
      DEFINE_GUID IID_IDirectSoundFXGargle, 0d616f352h, 0d622h, 11ceh, 0aah, 0c5h, 00h, 20h, 0afh, 0bh, 99h, 0a3h
      DSFXGargle struct
        dwRateHz DWORD ?
        ; Rate of modulation in hz
        dwWaveShape DWORD ?
        ; DSFXGARGLE_WAVE_xxx
      DSFXGargle ends
      _DSFXGargle typedef DSFXGargle
      LPDSFXGargle typedef ptr DSFXGargle
      DSFXGARGLE_WAVE_TRIANGLE equ 0
      DSFXGARGLE_WAVE_SQUARE equ 1
      LPCDSFXGargle typedef ptr DSFXGargle
      DSFXGARGLE_RATEHZ_MIN equ 1
      DSFXGARGLE_RATEHZ_MAX equ 1000
      INTERFACE equ <IDirectSoundFXGargle>
      DECLARE_INTERFACE_(IDirectSoundFXGargle, IUnknown)
        ??Interface equ <DSFXGargle>
        ; IUnknown methods
        STDMETHOD QueryInterface, :REFIID, :ptr POINTER
        STDMETHOD_ ULONG, AddRef
        STDMETHOD_ ULONG, Release
        ; IDirectSoundFXGargle methods
        STDMETHOD SetAllParameters, :LPCDSFXGargle
        STDMETHOD GetAllParameters, :LPDSFXGargle
      DECLARE_INTERFACE__END

      IDirectSoundFXGargle_QueryInterface macro p, a, b
        exitm <IUnknown_QueryInterface(p, a, b)>
      endm
      IDirectSoundFXGargle_AddRef macro p
        exitm <IUnknown_AddRef(p)>
      endm
      IDirectSoundFXGargle_Release macro p
        exitm <IUnknown_Release(p)>
      endm
      if  not Defined(__cplusplus) or Defined(CINTERFACE)
        IDirectSoundFXGargle_SetAllParameters macro p, a
          exitm <(p) - lpVtbl - SetAllParameters (p, a)>
        endm
        IDirectSoundFXGargle_GetAllParameters macro p, a
          exitm <(p) - lpVtbl - GetAllParameters (p, a)>
        endm
      else
      ; !defined(__cplusplus) || defined(CINTERFACE)
        ;[...]
      endif
      ; !defined(__cplusplus) || defined(CINTERFACE)
      ; IDirectSoundFXChorus
      DEFINE_GUID IID_IDirectSoundFXChorus, 880842e3h, 145fh, 43e6h, 0a9h, 34h, 0a7h, 18h, 06h, 0e5h, 05h, 47h
      DSFXChorus struct
        fWetDryMix REAL4 ?
        fDepth REAL4 ?
        fFeedback REAL4 ?
        fFrequency REAL4 ?
        lWaveform SDWORD ?
        ; LFO shape; DSFXCHORUS_WAVE_xxx
        fDelay REAL4 ?
        lPhase SDWORD ?
      DSFXChorus ends
      _DSFXChorus typedef DSFXChorus
      LPDSFXChorus typedef ptr DSFXChorus
      LPCDSFXChorus typedef ptr DSFXChorus
      DSFXCHORUS_WAVE_TRIANGLE equ 0
      DSFXCHORUS_WAVE_SIN equ 1
      DSFXCHORUS_WETDRYMIX_MIN equ 0.0
      DSFXCHORUS_WETDRYMIX_MAX equ 100.0
      DSFXCHORUS_DEPTH_MIN equ 0.0
      DSFXCHORUS_DEPTH_MAX equ 100.0
      DSFXCHORUS_FEEDBACK_MIN equ -99.0
      DSFXCHORUS_FEEDBACK_MAX equ 99.0
      DSFXCHORUS_FREQUENCY_MIN equ 0.0
      DSFXCHORUS_FREQUENCY_MAX equ 10.0
      DSFXCHORUS_DELAY_MIN equ 0.0
      DSFXCHORUS_DELAY_MAX equ 20.0
      DSFXCHORUS_PHASE_MIN equ 0
      DSFXCHORUS_PHASE_MAX equ 4
      DSFXCHORUS_PHASE_NEG_180 equ 0
      DSFXCHORUS_PHASE_NEG_90 equ 1
      DSFXCHORUS_PHASE_ZERO equ 2
      DSFXCHORUS_PHASE_90 equ 3
      DSFXCHORUS_PHASE_180 equ 4
      INTERFACE equ <IDirectSoundFXChorus>
      DECLARE_INTERFACE_(IDirectSoundFXChorus, IUnknown)
        ??Interface equ <DSFXChorus>
        ; IUnknown methods
        STDMETHOD QueryInterface, :REFIID, :ptr POINTER
        STDMETHOD_ ULONG, AddRef
        STDMETHOD_ ULONG, Release
        ; IDirectSoundFXChorus methods
        STDMETHOD SetAllParameters, :LPCDSFXChorus
        STDMETHOD GetAllParameters, :LPDSFXChorus
      DECLARE_INTERFACE__END

      IDirectSoundFXChorus_QueryInterface macro p, a, b
        exitm <IUnknown_QueryInterface(p, a, b)>
      endm
      IDirectSoundFXChorus_AddRef macro p
        exitm <IUnknown_AddRef(p)>
      endm
      IDirectSoundFXChorus_Release macro p
        exitm <IUnknown_Release(p)>
      endm
      if  not Defined(__cplusplus) or Defined(CINTERFACE)
        IDirectSoundFXChorus_SetAllParameters macro p, a
          exitm <(p) - lpVtbl - SetAllParameters (p, a)>
        endm
        IDirectSoundFXChorus_GetAllParameters macro p, a
          exitm <(p) - lpVtbl - GetAllParameters (p, a)>
        endm
      else
      ; !defined(__cplusplus) || defined(CINTERFACE)
        ;[...]
      endif
      ; !defined(__cplusplus) || defined(CINTERFACE)
      ; IDirectSoundFXFlanger
      DEFINE_GUID IID_IDirectSoundFXFlanger, 903e9878h, 2c92h, 4072h, 9bh, 2ch, 0eah, 68h, 0f5h, 39h, 67h, 83h
      DSFXFlanger struct
        fWetDryMix REAL4 ?
        fDepth REAL4 ?
        fFeedback REAL4 ?
        fFrequency REAL4 ?
        lWaveform SDWORD ?
        fDelay REAL4 ?
        lPhase SDWORD ?
      DSFXFlanger ends
      _DSFXFlanger typedef DSFXFlanger
      LPDSFXFlanger typedef ptr DSFXFlanger
      LPCDSFXFlanger typedef ptr DSFXFlanger
      DSFXFLANGER_WAVE_TRIANGLE equ 0
      DSFXFLANGER_WAVE_SIN equ 1
      DSFXFLANGER_WETDRYMIX_MIN equ 0.0
      DSFXFLANGER_WETDRYMIX_MAX equ 100.0
      DSFXFLANGER_FREQUENCY_MIN equ 0.0
      DSFXFLANGER_FREQUENCY_MAX equ 10.0
      DSFXFLANGER_DEPTH_MIN equ 0.0
      DSFXFLANGER_DEPTH_MAX equ 100.0
      DSFXFLANGER_PHASE_MIN equ 0
      DSFXFLANGER_PHASE_MAX equ 4
      DSFXFLANGER_FEEDBACK_MIN equ -99.0
      DSFXFLANGER_FEEDBACK_MAX equ 99.0
      DSFXFLANGER_DELAY_MIN equ 0.0
      DSFXFLANGER_DELAY_MAX equ 4.0
      DSFXFLANGER_PHASE_NEG_180 equ 0
      DSFXFLANGER_PHASE_NEG_90 equ 1
      DSFXFLANGER_PHASE_ZERO equ 2
      DSFXFLANGER_PHASE_90 equ 3
      DSFXFLANGER_PHASE_180 equ 4
      INTERFACE equ <IDirectSoundFXFlanger>
      DECLARE_INTERFACE_(IDirectSoundFXFlanger, IUnknown)
        ??Interface equ <DSFXFlanger>
        ; IUnknown methods
        STDMETHOD QueryInterface, :REFIID, :ptr POINTER
        STDMETHOD_ ULONG, AddRef
        STDMETHOD_ ULONG, Release
        ; IDirectSoundFXFlanger methods
        STDMETHOD SetAllParameters, :LPCDSFXFlanger
        STDMETHOD GetAllParameters, :LPDSFXFlanger
      DECLARE_INTERFACE__END

      IDirectSoundFXFlanger_QueryInterface macro p, a, b
        exitm <IUnknown_QueryInterface(p, a, b)>
      endm
      IDirectSoundFXFlanger_AddRef macro p
        exitm <IUnknown_AddRef(p)>
      endm
      IDirectSoundFXFlanger_Release macro p
        exitm <IUnknown_Release(p)>
      endm
      if  not Defined(__cplusplus) or Defined(CINTERFACE)
        IDirectSoundFXFlanger_SetAllParameters macro p, a
          exitm <(p) - lpVtbl - SetAllParameters (p, a)>
        endm
        IDirectSoundFXFlanger_GetAllParameters macro p, a
          exitm <(p) - lpVtbl - GetAllParameters (p, a)>
        endm
      else
      ; !defined(__cplusplus) || defined(CINTERFACE)
        ;[...]
      endif
      ; !defined(__cplusplus) || defined(CINTERFACE)
      ; IDirectSoundFXEcho
      DEFINE_GUID IID_IDirectSoundFXEcho, 8bd28edfh, 50dbh, 4e92h, 0a2h, 0bdh, 44h, 54h, 88h, 0d1h, 0edh, 42h
      DSFXEcho struct
        fWetDryMix REAL4 ?
        fFeedback REAL4 ?
        fLeftDelay REAL4 ?
        fRightDelay REAL4 ?
        lPanDelay SDWORD ?
      DSFXEcho ends
      _DSFXEcho typedef DSFXEcho
      LPDSFXEcho typedef ptr DSFXEcho
      LPCDSFXEcho typedef ptr DSFXEcho
      DSFXECHO_WETDRYMIX_MIN equ 0.0
      DSFXECHO_WETDRYMIX_MAX equ 100.0
      DSFXECHO_FEEDBACK_MIN equ 0.0
      DSFXECHO_FEEDBACK_MAX equ 100.0
      DSFXECHO_LEFTDELAY_MIN equ 1.0
      DSFXECHO_LEFTDELAY_MAX equ 2000.0
      DSFXECHO_RIGHTDELAY_MIN equ 1.0
      DSFXECHO_RIGHTDELAY_MAX equ 2000.0
      DSFXECHO_PANDELAY_MIN equ 0
      DSFXECHO_PANDELAY_MAX equ 1
      INTERFACE equ <IDirectSoundFXEcho>
      DECLARE_INTERFACE_(IDirectSoundFXEcho, IUnknown)
        ??Interface equ <DSFXEcho>
        ; IUnknown methods
        STDMETHOD QueryInterface, :REFIID, :ptr POINTER
        STDMETHOD_ ULONG, AddRef
        STDMETHOD_ ULONG, Release
        ; IDirectSoundFXEcho methods
        STDMETHOD SetAllParameters, :LPCDSFXEcho
        STDMETHOD GetAllParameters, :LPDSFXEcho
      DECLARE_INTERFACE__END

      IDirectSoundFXEcho_QueryInterface macro p, a, b
        exitm <IUnknown_QueryInterface(p, a, b)>
      endm
      IDirectSoundFXEcho_AddRef macro p
        exitm <IUnknown_AddRef(p)>
      endm
      IDirectSoundFXEcho_Release macro p
        exitm <IUnknown_Release(p)>
      endm
      if  not Defined(__cplusplus) or Defined(CINTERFACE)
        IDirectSoundFXEcho_SetAllParameters macro p, a
          exitm <(p) - lpVtbl - SetAllParameters (p, a)>
        endm
        IDirectSoundFXEcho_GetAllParameters macro p, a
          exitm <(p) - lpVtbl - GetAllParameters (p, a)>
        endm
      else
      ; !defined(__cplusplus) || defined(CINTERFACE)
        ;[...]
      endif
      ; !defined(__cplusplus) || defined(CINTERFACE)
      ; IDirectSoundFXDistortion
      DEFINE_GUID IID_IDirectSoundFXDistortion, 8ecf4326h, 455fh, 4d8bh, 0bdh, 0a9h, 8dh, 5dh, 3eh, 9eh, 3eh, 0bh
      DSFXDistortion struct
        fGain REAL4 ?
        fEdge REAL4 ?
        fPostEQCenterFrequency REAL4 ?
        fPostEQBandwidth REAL4 ?
        fPreLowpassCutoff REAL4 ?
      DSFXDistortion ends
      _DSFXDistortion typedef DSFXDistortion
      LPDSFXDistortion typedef ptr DSFXDistortion
      LPCDSFXDistortion typedef ptr DSFXDistortion
      DSFXDISTORTION_GAIN_MIN equ -60.0
      DSFXDISTORTION_GAIN_MAX equ 0.0
      DSFXDISTORTION_EDGE_MIN equ 0.0
      DSFXDISTORTION_EDGE_MAX equ 100.0
      DSFXDISTORTION_POSTEQCENTERFREQUENCY_MIN equ 100.0
      DSFXDISTORTION_POSTEQCENTERFREQUENCY_MAX equ 8000.0
      DSFXDISTORTION_POSTEQBANDWIDTH_MIN equ 100.0
      DSFXDISTORTION_POSTEQBANDWIDTH_MAX equ 8000.0
      DSFXDISTORTION_PRELOWPASSCUTOFF_MIN equ 100.0
      DSFXDISTORTION_PRELOWPASSCUTOFF_MAX equ 8000.0
      INTERFACE equ <IDirectSoundFXDistortion>
      DECLARE_INTERFACE_(IDirectSoundFXDistortion, IUnknown)
        ??Interface equ <DSFXDistortion>
        ; IUnknown methods
        STDMETHOD QueryInterface, :REFIID, :ptr POINTER
        STDMETHOD_ ULONG, AddRef
        STDMETHOD_ ULONG, Release
        ; IDirectSoundFXDistortion methods
        STDMETHOD SetAllParameters, :LPCDSFXDistortion
        STDMETHOD GetAllParameters, :LPDSFXDistortion
      DECLARE_INTERFACE__END

      IDirectSoundFXDistortion_QueryInterface macro p, a, b
        exitm <IUnknown_QueryInterface(p, a, b)>
      endm
      IDirectSoundFXDistortion_AddRef macro p
        exitm <IUnknown_AddRef(p)>
      endm
      IDirectSoundFXDistortion_Release macro p
        exitm <IUnknown_Release(p)>
      endm
      if  not Defined(__cplusplus) or Defined(CINTERFACE)
        IDirectSoundFXDistortion_SetAllParameters macro p, a
          exitm <(p) - lpVtbl - SetAllParameters (p, a)>
        endm
        IDirectSoundFXDistortion_GetAllParameters macro p, a
          exitm <(p) - lpVtbl - GetAllParameters (p, a)>
        endm
      else
      ; !defined(__cplusplus) || defined(CINTERFACE)
        ;[...]
      endif
      ; !defined(__cplusplus) || defined(CINTERFACE)
      ; IDirectSoundFXCompressor
      DEFINE_GUID IID_IDirectSoundFXCompressor, 4bbd1154h, 62f6h, 4e2ch, 0a1h, 5ch, 0d3h, 0b6h, 0c4h, 17h, 0f7h, 0a0h
      DSFXCompressor struct
        fGain REAL4 ?
        fAttack REAL4 ?
        fRelease REAL4 ?
        fThreshold REAL4 ?
        fRatio REAL4 ?
        fPredelay REAL4 ?
      DSFXCompressor ends
      _DSFXCompressor typedef DSFXCompressor
      LPDSFXCompressor typedef ptr DSFXCompressor
      LPCDSFXCompressor typedef ptr DSFXCompressor
      DSFXCOMPRESSOR_GAIN_MIN equ -60.0
      DSFXCOMPRESSOR_GAIN_MAX equ 60.0
      DSFXCOMPRESSOR_ATTACK_MIN equ 0.01
      DSFXCOMPRESSOR_ATTACK_MAX equ 500.0
      DSFXCOMPRESSOR_RELEASE_MIN equ 50.0
      DSFXCOMPRESSOR_RELEASE_MAX equ 3000.0
      DSFXCOMPRESSOR_THRESHOLD_MIN equ -60.0
      DSFXCOMPRESSOR_THRESHOLD_MAX equ 0.0
      DSFXCOMPRESSOR_RATIO_MIN equ 1.0
      DSFXCOMPRESSOR_RATIO_MAX equ 100.0
      DSFXCOMPRESSOR_PREDELAY_MIN equ 0.0
      DSFXCOMPRESSOR_PREDELAY_MAX equ 4.0
      INTERFACE equ <IDirectSoundFXCompressor>
      DECLARE_INTERFACE_(IDirectSoundFXCompressor, IUnknown)
        ??Interface equ <DSFXCompressor>
        ; IUnknown methods
        STDMETHOD QueryInterface, :REFIID, :ptr POINTER
        STDMETHOD_ ULONG, AddRef
        STDMETHOD_ ULONG, Release
        ; IDirectSoundFXCompressor methods
        STDMETHOD SetAllParameters, :LPCDSFXCompressor
        STDMETHOD GetAllParameters, :LPDSFXCompressor
      DECLARE_INTERFACE__END

      IDirectSoundFXCompressor_QueryInterface macro p, a, b
        exitm <IUnknown_QueryInterface(p, a, b)>
      endm
      IDirectSoundFXCompressor_AddRef macro p
        exitm <IUnknown_AddRef(p)>
      endm
      IDirectSoundFXCompressor_Release macro p
        exitm <IUnknown_Release(p)>
      endm
      if  not Defined(__cplusplus) or Defined(CINTERFACE)
        IDirectSoundFXCompressor_SetAllParameters macro p, a
          exitm <(p) - lpVtbl - SetAllParameters (p, a)>
        endm
        IDirectSoundFXCompressor_GetAllParameters macro p, a
          exitm <(p) - lpVtbl - GetAllParameters (p, a)>
        endm
      else
      ; !defined(__cplusplus) || defined(CINTERFACE)
        ;[...]
      endif
      ; !defined(__cplusplus) || defined(CINTERFACE)
      ; IDirectSoundFXParamEq
      DEFINE_GUID IID_IDirectSoundFXParamEq, 0c03ca9feh, 0fe90h, 4204h, 80h, 78h, 82h, 33h, 4ch, 0d1h, 77h, 0dah
      DSFXParamEq struct
        fCenter REAL4 ?
        fBandwidth REAL4 ?
        fGain REAL4 ?
      DSFXParamEq ends
      _DSFXParamEq typedef DSFXParamEq
      LPDSFXParamEq typedef ptr DSFXParamEq
      LPCDSFXParamEq typedef ptr DSFXParamEq
      DSFXPARAMEQ_CENTER_MIN equ 80.0
      DSFXPARAMEQ_CENTER_MAX equ 16000.0
      DSFXPARAMEQ_BANDWIDTH_MIN equ 1.0
      DSFXPARAMEQ_BANDWIDTH_MAX equ 36.0
      DSFXPARAMEQ_GAIN_MIN equ -15.0
      DSFXPARAMEQ_GAIN_MAX equ 15.0
      INTERFACE equ <IDirectSoundFXParamEq>
      DECLARE_INTERFACE_(IDirectSoundFXParamEq, IUnknown)
        ??Interface equ <DSFXParamEq>
        ; IUnknown methods
        STDMETHOD QueryInterface, :REFIID, :ptr POINTER
        STDMETHOD_ ULONG, AddRef
        STDMETHOD_ ULONG, Release
        ; IDirectSoundFXParamEq methods
        STDMETHOD SetAllParameters, :LPCDSFXParamEq
        STDMETHOD GetAllParameters, :LPDSFXParamEq
      DECLARE_INTERFACE__END

      IDirectSoundFXParamEq_QueryInterface macro p, a, b
        exitm <IUnknown_QueryInterface(p, a, b)>
      endm
      IDirectSoundFXParamEq_AddRef macro p
        exitm <IUnknown_AddRef(p)>
      endm
      IDirectSoundFXParamEq_Release macro p
        exitm <IUnknown_Release(p)>
      endm
      if  not Defined(__cplusplus) or Defined(CINTERFACE)
        IDirectSoundFXParamEq_SetAllParameters macro p, a
          exitm <(p) - lpVtbl - SetAllParameters (p, a)>
        endm
        IDirectSoundFXParamEq_GetAllParameters macro p, a
          exitm <(p) - lpVtbl - GetAllParameters (p, a)>
        endm
      else
      ; !defined(__cplusplus) || defined(CINTERFACE)
        ;[...]
      endif
      ; !defined(__cplusplus) || defined(CINTERFACE)
      ; IDirectSoundFXI3DL2Reverb
      DEFINE_GUID IID_IDirectSoundFXI3DL2Reverb, 4b166a6ah, 0d66h, 43f3h, 80h, 0e3h, 0eeh, 62h, 80h, 0deh, 0e1h, 0a4h
      DSFXI3DL2Reverb struct
        lRoom SDWORD ?
        ; [-10000, 0]      default: -1000 mB
        lRoomHF SDWORD ?
        ; [-10000, 0]      default: 0 mB
        flRoomRolloffFactor REAL4 ?
        ; [0.0, 10.0]      default: 0.0
        flDecayTime REAL4 ?
        ; [0.1, 20.0]      default: 1.49s
        flDecayHFRatio REAL4 ?
        ; [0.1, 2.0]       default: 0.83
        lReflections SDWORD ?
        ; [-10000, 1000]   default: -2602 mB
        flReflectionsDelay REAL4 ?
        ; [0.0, 0.3]       default: 0.007 s
        lReverb SDWORD ?
        ; [-10000, 2000]   default: 200 mB
        flReverbDelay REAL4 ?
        ; [0.0, 0.1]       default: 0.011 s
        flDiffusion REAL4 ?
        ; [0.0, 100.0]     default: 100.0 %
        flDensity REAL4 ?
        ; [0.0, 100.0]     default: 100.0 %
        flHFReference REAL4 ?
        ; [20.0, 20000.0]  default: 5000.0 Hz
      DSFXI3DL2Reverb ends
      _DSFXI3DL2Reverb typedef DSFXI3DL2Reverb
      LPDSFXI3DL2Reverb typedef ptr DSFXI3DL2Reverb
      LPCDSFXI3DL2Reverb typedef ptr DSFXI3DL2Reverb
      DSFX_I3DL2REVERB_ROOM_MIN equ (- 10000)
      DSFX_I3DL2REVERB_ROOM_MAX equ 0
      DSFX_I3DL2REVERB_ROOM_DEFAULT equ (- 1000)
      DSFX_I3DL2REVERB_ROOMHF_MIN equ (- 10000)
      DSFX_I3DL2REVERB_ROOMHF_MAX equ 0
      DSFX_I3DL2REVERB_ROOMHF_DEFAULT equ (- 100)
      DSFX_I3DL2REVERB_ROOMROLLOFFFACTOR_MIN equ 0.0
      DSFX_I3DL2REVERB_ROOMROLLOFFFACTOR_MAX equ 10.0
      DSFX_I3DL2REVERB_ROOMROLLOFFFACTOR_DEFAULT equ 0.0
      DSFX_I3DL2REVERB_DECAYTIME_MIN equ 0.1
      DSFX_I3DL2REVERB_DECAYTIME_MAX equ 20.0
      DSFX_I3DL2REVERB_DECAYTIME_DEFAULT equ 1.49
      DSFX_I3DL2REVERB_DECAYHFRATIO_MIN equ 0.1
      DSFX_I3DL2REVERB_DECAYHFRATIO_MAX equ 2.0
      DSFX_I3DL2REVERB_DECAYHFRATIO_DEFAULT equ 0.83
      DSFX_I3DL2REVERB_REFLECTIONS_MIN equ (- 10000)
      DSFX_I3DL2REVERB_REFLECTIONS_MAX equ 1000
      DSFX_I3DL2REVERB_REFLECTIONS_DEFAULT equ (- 2602)
      DSFX_I3DL2REVERB_REFLECTIONSDELAY_MIN equ 0.0
      DSFX_I3DL2REVERB_REFLECTIONSDELAY_MAX equ 0.3
      DSFX_I3DL2REVERB_REFLECTIONSDELAY_DEFAULT equ 0.007
      DSFX_I3DL2REVERB_REVERB_MIN equ (- 10000)
      DSFX_I3DL2REVERB_REVERB_MAX equ 2000
      DSFX_I3DL2REVERB_REVERB_DEFAULT equ (200)
      DSFX_I3DL2REVERB_REVERBDELAY_MIN equ 0.0
      DSFX_I3DL2REVERB_REVERBDELAY_MAX equ 0.1
      DSFX_I3DL2REVERB_REVERBDELAY_DEFAULT equ 0.011
      DSFX_I3DL2REVERB_DIFFUSION_MIN equ 0.0
      DSFX_I3DL2REVERB_DIFFUSION_MAX equ 100.0
      DSFX_I3DL2REVERB_DIFFUSION_DEFAULT equ 100.0
      DSFX_I3DL2REVERB_DENSITY_MIN equ 0.0
      DSFX_I3DL2REVERB_DENSITY_MAX equ 100.0
      DSFX_I3DL2REVERB_DENSITY_DEFAULT equ 100.0
      DSFX_I3DL2REVERB_HFREFERENCE_MIN equ 20.0
      DSFX_I3DL2REVERB_HFREFERENCE_MAX equ 20000.0
      DSFX_I3DL2REVERB_HFREFERENCE_DEFAULT equ 5000.0
      DSFX_I3DL2REVERB_QUALITY_MIN equ 0
      DSFX_I3DL2REVERB_QUALITY_MAX equ 3
      DSFX_I3DL2REVERB_QUALITY_DEFAULT equ 2
      INTERFACE equ <IDirectSoundFXI3DL2Reverb>
      DECLARE_INTERFACE_(IDirectSoundFXI3DL2Reverb, IUnknown)
        ??Interface equ <DSFXI3DL2Reverb>
        ; IUnknown methods
        STDMETHOD QueryInterface, :REFIID, :ptr POINTER
        STDMETHOD_ ULONG, AddRef
        STDMETHOD_ ULONG, Release
        ; IDirectSoundFXI3DL2Reverb methods
        STDMETHOD SetAllParameters, :LPCDSFXI3DL2Reverb
        STDMETHOD GetAllParameters, :LPDSFXI3DL2Reverb
        STDMETHOD SetPreset, :DWORD
        STDMETHOD GetPreset, :LPDWORD
        STDMETHOD SetQuality, :SDWORD
        STDMETHOD GetQuality, :ptr SDWORD
      DECLARE_INTERFACE__END

      IDirectSoundFXI3DL2Reverb_QueryInterface macro p, a, b
        exitm <IUnknown_QueryInterface(p, a, b)>
      endm
      IDirectSoundFXI3DL2Reverb_AddRef macro p
        exitm <IUnknown_AddRef(p)>
      endm
      IDirectSoundFXI3DL2Reverb_Release macro p
        exitm <IUnknown_Release(p)>
      endm
      if  not Defined(__cplusplus) or Defined(CINTERFACE)
        IDirectSoundFXI3DL2Reverb_SetAllParameters macro p, a
          exitm <(p) - lpVtbl - SetAllParameters (p, a)>
        endm
        IDirectSoundFXI3DL2Reverb_GetAllParameters macro p, a
          exitm <(p) - lpVtbl - GetAllParameters (p, a)>
        endm
        IDirectSoundFXI3DL2Reverb_SetPreset macro p, a
          exitm <(p) - lpVtbl - SetPreset (p, a)>
        endm
        IDirectSoundFXI3DL2Reverb_GetPreset macro p, a
          exitm <(p) - lpVtbl - GetPreset (p, a)>
        endm
      else
      ; !defined(__cplusplus) || defined(CINTERFACE)
        ;[...]
      endif
      ; !defined(__cplusplus) || defined(CINTERFACE)
      ; IDirectSoundFXWavesReverb
      DEFINE_GUID IID_IDirectSoundFXWavesReverb, 46858c3ah, 0dc6h, 45e3h, 0b7h, 60h, 0d4h, 0eeh, 0f1h, 6ch, 0b3h, 25h
      DSFXWavesReverb struct
        fInGain REAL4 ?
        ; [-96.0,0.0]            default: 0.0 dB
        fReverbMix REAL4 ?
        ; [-96.0,0.0]            default: 0.0 db
        fReverbTime REAL4 ?
        ; [0.001,3000.0]         default: 1000.0 ms
        fHighFreqRTRatio REAL4 ?
        ; [0.001,0.999]          default: 0.001
      DSFXWavesReverb ends
      _DSFXWavesReverb typedef DSFXWavesReverb
      LPDSFXWavesReverb typedef ptr DSFXWavesReverb
      LPCDSFXWavesReverb typedef ptr DSFXWavesReverb
      DSFX_WAVESREVERB_INGAIN_MIN equ -96.0
      DSFX_WAVESREVERB_INGAIN_MAX equ 0.0
      DSFX_WAVESREVERB_INGAIN_DEFAULT equ 0.0
      DSFX_WAVESREVERB_REVERBMIX_MIN equ -96.0
      DSFX_WAVESREVERB_REVERBMIX_MAX equ 0.0
      DSFX_WAVESREVERB_REVERBMIX_DEFAULT equ 0.0
      DSFX_WAVESREVERB_REVERBTIME_MIN equ 0.001
      DSFX_WAVESREVERB_REVERBTIME_MAX equ 3000.0
      DSFX_WAVESREVERB_REVERBTIME_DEFAULT equ 1000.0
      DSFX_WAVESREVERB_HIGHFREQRTRATIO_MIN equ 0.001
      DSFX_WAVESREVERB_HIGHFREQRTRATIO_MAX equ 0.999
      DSFX_WAVESREVERB_HIGHFREQRTRATIO_DEFAULT equ 0.001
      INTERFACE equ <IDirectSoundFXWavesReverb>
      DECLARE_INTERFACE_(IDirectSoundFXWavesReverb, IUnknown)
        ??Interface equ <DSFXWavesReverb>
        ; IUnknown methods
        STDMETHOD QueryInterface, :REFIID, :ptr POINTER
        STDMETHOD_ ULONG, AddRef
        STDMETHOD_ ULONG, Release
        ; IDirectSoundFXWavesReverb methods
        STDMETHOD SetAllParameters, :LPCDSFXWavesReverb
        STDMETHOD GetAllParameters, :LPDSFXWavesReverb
      DECLARE_INTERFACE__END

      IDirectSoundFXWavesReverb_QueryInterface macro p, a, b
        exitm <IUnknown_QueryInterface(p, a, b)>
      endm
      IDirectSoundFXWavesReverb_AddRef macro p
        exitm <IUnknown_AddRef(p)>
      endm
      IDirectSoundFXWavesReverb_Release macro p
        exitm <IUnknown_Release(p)>
      endm
      if  not Defined(__cplusplus) or Defined(CINTERFACE)
        IDirectSoundFXWavesReverb_SetAllParameters macro p, a
          exitm <(p) - lpVtbl - SetAllParameters (p, a)>
        endm
        IDirectSoundFXWavesReverb_GetAllParameters macro p, a
          exitm <(p) - lpVtbl - GetAllParameters (p, a)>
        endm
      else
      ; !defined(__cplusplus) || defined(CINTERFACE)
        ;[...]
      endif
      ; !defined(__cplusplus) || defined(CINTERFACE)
      ; IDirectSoundCaptureFXAec
      DEFINE_GUID IID_IDirectSoundCaptureFXAec, 0ad74143dh, 903dh, 4ab7h, 80h, 66h, 28h, 0d3h, 63h, 03h, 6dh, 65h
      DSCFXAec struct
        fEnable DWORD ?
        fNoiseFill DWORD ?
        dwMode DWORD ?
      DSCFXAec ends
      _DSCFXAec typedef DSCFXAec
      LPDSCFXAec typedef ptr DSCFXAec
      LPCDSCFXAec typedef ptr DSCFXAec
      ; These match the AEC_MODE_* constants in the DDK's ksmedia.h file
      DSCFX_AEC_MODE_PASS_THROUGH equ 0h
      DSCFX_AEC_MODE_HALF_DUPLEX equ 1h
      DSCFX_AEC_MODE_FULL_DUPLEX equ 2h
      ; These match the AEC_STATUS_* constants in ksmedia.h
      DSCFX_AEC_STATUS_HISTORY_UNINITIALIZED equ 0h
      DSCFX_AEC_STATUS_HISTORY_CONTINUOUSLY_CONVERGED equ 1h
      DSCFX_AEC_STATUS_HISTORY_PREVIOUSLY_DIVERGED equ 2h
      DSCFX_AEC_STATUS_CURRENTLY_CONVERGED equ 8h
      INTERFACE equ <IDirectSoundCaptureFXAec>
      DECLARE_INTERFACE_(IDirectSoundCaptureFXAec, IUnknown)
        ??Interface equ <DSCFXAec>
        ; IUnknown methods
        STDMETHOD QueryInterface, :REFIID, :ptr POINTER
        STDMETHOD_ ULONG, AddRef
        STDMETHOD_ ULONG, Release
        ; IDirectSoundCaptureFXAec methods
        STDMETHOD SetAllParameters, :LPCDSCFXAec
        STDMETHOD GetAllParameters, :LPDSCFXAec
        STDMETHOD GetStatus, :LPDWORD
        STDMETHOD Reset
      DECLARE_INTERFACE__END

      IDirectSoundCaptureFXAec_QueryInterface macro p, a, b
        exitm <IUnknown_QueryInterface(p, a, b)>
      endm
      IDirectSoundCaptureFXAec_AddRef macro p
        exitm <IUnknown_AddRef(p)>
      endm
      IDirectSoundCaptureFXAec_Release macro p
        exitm <IUnknown_Release(p)>
      endm
      if  not Defined(__cplusplus) or Defined(CINTERFACE)
        IDirectSoundCaptureFXAec_SetAllParameters macro p, a
          exitm <(p) - lpVtbl - SetAllParameters (p, a)>
        endm
        IDirectSoundCaptureFXAec_GetAllParameters macro p, a
          exitm <(p) - lpVtbl - GetAllParameters (p, a)>
        endm
      else
      ; !defined(__cplusplus) || defined(CINTERFACE)
        ;[...]
      endif
      ; !defined(__cplusplus) || defined(CINTERFACE)
      ; IDirectSoundCaptureFXNoiseSuppress
      DEFINE_GUID IID_IDirectSoundCaptureFXNoiseSuppress, 0ed311e41h, 0fbaeh, 4175h, 96h, 25h, 0cdh, 8h, 54h, 0f6h, 93h, 0cah
      DSCFXNoiseSuppress struct
        fEnable DWORD ?
      DSCFXNoiseSuppress ends
      _DSCFXNoiseSuppress typedef DSCFXNoiseSuppress
      LPDSCFXNoiseSuppress typedef ptr DSCFXNoiseSuppress
      LPCDSCFXNoiseSuppress typedef ptr DSCFXNoiseSuppress
      INTERFACE equ <IDirectSoundCaptureFXNoiseSuppress>
      DECLARE_INTERFACE_(IDirectSoundCaptureFXNoiseSuppress, IUnknown)
        ??Interface equ <DSCFXNoiseSuppress>
        ; IUnknown methods
        STDMETHOD QueryInterface, :REFIID, :ptr POINTER
        STDMETHOD_ ULONG, AddRef
        STDMETHOD_ ULONG, Release
        ; IDirectSoundCaptureFXNoiseSuppress methods
        STDMETHOD SetAllParameters, :LPCDSCFXNoiseSuppress
        STDMETHOD GetAllParameters, :LPDSCFXNoiseSuppress
        STDMETHOD Reset
      DECLARE_INTERFACE__END

      IDirectSoundCaptureFXNoiseSuppress_QueryInterface macro p, a, b
        exitm <IUnknown_QueryInterface(p, a, b)>
      endm
      IDirectSoundCaptureFXNoiseSuppress_AddRef macro p
        exitm <IUnknown_AddRef(p)>
      endm
      IDirectSoundCaptureFXNoiseSuppress_Release macro p
        exitm <IUnknown_Release(p)>
      endm
      if  not Defined(__cplusplus) or Defined(CINTERFACE)
        IDirectSoundCaptureFXNoiseSuppress_SetAllParameters macro p, a
          exitm <(p) - lpVtbl - SetAllParameters (p, a)>
        endm
        IDirectSoundCaptureFXNoiseSuppress_GetAllParameters macro p, a
          exitm <(p) - lpVtbl - GetAllParameters (p, a)>
        endm
      else
      ; !defined(__cplusplus) || defined(CINTERFACE)
        ;[...]
      endif
      ; !defined(__cplusplus) || defined(CINTERFACE)
      ; IDirectSoundFullDuplex
      ifndef _IDirectSoundFullDuplex_
        _IDirectSoundFullDuplex_ equ <>
        ifdef __cplusplus
          ;[...]
        endif
        ; __cplusplus
        LPDIRECTSOUNDFULLDUPLEX typedef ptr IDirectSoundFullDuplex
        DEFINE_GUID IID_IDirectSoundFullDuplex, 0edcb4c7ah, 0daabh, 4216h, 0a4h, 2eh, 6ch, 50h, 59h, 6dh, 0dch, 1dh
        INTERFACE equ <IDirectSoundFullDuplex>
        DECLARE_INTERFACE_(IDirectSoundFullDuplex, IUnknown)
          ??Interface equ <DSCFXNoiseSuppress>
          ; IUnknown methods
          STDMETHOD QueryInterface, :REFIID, :ptr POINTER
          STDMETHOD_ ULONG, AddRef
          STDMETHOD_ ULONG, Release
          ; IDirectSoundFullDuplex methods
          STDMETHOD Initialize, :LPCGUID, :LPCGUID, :LPCDSCBUFFERDESC, :LPCDSBUFFERDESC, :HWND, :DWORD, :LPLPDIRECTSOUNDCAPTUREBUFFER8, :LPLPDIRECTSOUNDBUFFER8
        DECLARE_INTERFACE__END

        IDirectSoundFullDuplex_QueryInterface macro p, a, b
          exitm <IUnknown_QueryInterface(p, a, b)>
        endm
        IDirectSoundFullDuplex_AddRef macro p
          exitm <IUnknown_AddRef(p)>
        endm
        IDirectSoundFullDuplex_Release macro p
          exitm <IUnknown_Release(p)>
        endm
        if  not Defined(__cplusplus) or Defined(CINTERFACE)
          IDirectSoundFullDuplex_Initialize macro p, a, b, c_, d, e, f, g, h
            exitm <(p) - lpVtbl - Initialize (p, a, b, c_, d, e, f, g, h)>
          endm
        else
        ; !defined(__cplusplus) || defined(CINTERFACE)
          ;[...]
        endif
        ; !defined(__cplusplus) || defined(CINTERFACE)
      endif
      ; _IDirectSoundFullDuplex_
    endif
    ; DIRECTSOUND_VERSION >= 0x0800
    ; Return Codes
    ; The function completed successfully
    DS_OK equ <S_OK>
    ; The call succeeded, but we had to substitute the 3D algorithm
    DS_NO_VIRTUALIZATION equ MAKE_HRESULT(0, _FACDS, 10)
    ; The call failed because resources (such as a priority level)
    ; were already being used by another caller
    DSERR_ALLOCATED equ MAKE_DSHRESULT(10)
    ; The control (vol, pan, etc.) requested by the caller is not available
    DSERR_CONTROLUNAVAIL equ MAKE_DSHRESULT(30)
    ; An invalid parameter was passed to the returning function
    DSERR_INVALIDPARAM equ <E_INVALIDARG>
    ; This call is not valid for the current state of this object
    DSERR_INVALIDCALL equ MAKE_DSHRESULT(50)
    ; An undetermined error occurred inside the DirectSound subsystem
    DSERR_GENERIC equ <E_FAIL>
    ; The caller does not have the priority level required for the function to
    ; succeed
    DSERR_PRIOLEVELNEEDED equ MAKE_DSHRESULT(70)
    ; Not enough free memory is available to complete the operation
    DSERR_OUTOFMEMORY equ <E_OUTOFMEMORY>
    ; The specified WAVE format is not supported
    DSERR_BADFORMAT equ MAKE_DSHRESULT(100)
    ; The function called is not supported at this time
    DSERR_UNSUPPORTED equ <E_NOTIMPL>
    ; No sound driver is available for use
    DSERR_NODRIVER equ MAKE_DSHRESULT(120)
    ; This object is already initialized
    DSERR_ALREADYINITIALIZED equ MAKE_DSHRESULT(130)
    ; This object does not support aggregation
    DSERR_NOAGGREGATION equ <CLASS_E_NOAGGREGATION>
    ; The buffer memory has been lost, and must be restored
    DSERR_BUFFERLOST equ MAKE_DSHRESULT(150)
    ; Another app has a higher priority level, preventing this call from
    ; succeeding
    DSERR_OTHERAPPHASPRIO equ MAKE_DSHRESULT(160)
    ; This object has not been initialized
    DSERR_UNINITIALIZED equ MAKE_DSHRESULT(170)
    ; The requested COM interface is not available
    DSERR_NOINTERFACE equ <E_NOINTERFACE>
    ; Access is denied
    DSERR_ACCESSDENIED equ <E_ACCESSDENIED>
    ; Tried to create a DSBCAPS_CTRLFX buffer shorter than DSBSIZE_FX_MIN milliseconds
    DSERR_BUFFERTOOSMALL equ MAKE_DSHRESULT(180)
    ; Attempt to use DirectSound 8 functionality on an older DirectSound object
    DSERR_DS8_REQUIRED equ MAKE_DSHRESULT(190)
    ; A circular loop of send effects was detected
    DSERR_SENDLOOP equ MAKE_DSHRESULT(200)
    ; The GUID specified in an audiopath file does not match a valid MIXIN buffer
    DSERR_BADSENDBUFFERGUID equ MAKE_DSHRESULT(210)
    ; The object requested was not found (numerically equal to DMUS_E_NOT_FOUND)
    DSERR_OBJECTNOTFOUND equ MAKE_DSHRESULT(4449)
    ; The effects requested could not be found on the system, or they were found
    ; but in the wrong order, or in the wrong hardware/software locations.
    DSERR_FXUNAVAILABLE equ MAKE_DSHRESULT(220)
    ; Flags
    DSCAPS_PRIMARYMONO equ 00000001h
    DSCAPS_PRIMARYSTEREO equ 00000002h
    DSCAPS_PRIMARY8BIT equ 00000004h
    DSCAPS_PRIMARY16BIT equ 00000008h
    DSCAPS_CONTINUOUSRATE equ 00000010h
    DSCAPS_EMULDRIVER equ 00000020h
    DSCAPS_CERTIFIED equ 00000040h
    DSCAPS_SECONDARYMONO equ 00000100h
    DSCAPS_SECONDARYSTEREO equ 00000200h
    DSCAPS_SECONDARY8BIT equ 00000400h
    DSCAPS_SECONDARY16BIT equ 00000800h
    DSSCL_NORMAL equ 00000001h
    DSSCL_PRIORITY equ 00000002h
    DSSCL_EXCLUSIVE equ 00000003h
    DSSCL_WRITEPRIMARY equ 00000004h
    DSSPEAKER_DIRECTOUT equ 00000000h
    DSSPEAKER_HEADPHONE equ 00000001h
    DSSPEAKER_MONO equ 00000002h
    DSSPEAKER_QUAD equ 00000003h
    DSSPEAKER_STEREO equ 00000004h
    DSSPEAKER_SURROUND equ 00000005h
    DSSPEAKER_5POINT1 equ 00000006h; obsolete 5.1 setting

    DSSPEAKER_7POINT1 equ 00000007h; obsolete 7.1 setting

    DSSPEAKER_7POINT1_SURROUND equ 00000008h; correct 7.1 Home Theater setting

    DSSPEAKER_5POINT1_SURROUND equ 00000009h; correct 5.1 setting

    DSSPEAKER_7POINT1_WIDE equ <DSSPEAKER_7POINT1>
    DSSPEAKER_5POINT1_BACK equ <DSSPEAKER_5POINT1>
    DSSPEAKER_GEOMETRY_MIN equ 00000005h;   5 degrees

    DSSPEAKER_GEOMETRY_NARROW equ 0000000Ah;  10 degrees

    DSSPEAKER_GEOMETRY_WIDE equ 00000014h;  20 degrees

    DSSPEAKER_GEOMETRY_MAX equ 000000B4h; 180 degrees

    DSSPEAKER_COMBINED macro c_, g
      exitm <((((c_)) or (((g))) shl 16))>
    endm
    DSSPEAKER_CONFIG macro a
      exitm <((a))>
    endm
    DSSPEAKER_GEOMETRY macro a
      exitm <((((a) shr 16) and 00FFh))>
    endm
    DSBCAPS_PRIMARYBUFFER equ 00000001h
    DSBCAPS_STATIC equ 00000002h
    DSBCAPS_LOCHARDWARE equ 00000004h
    DSBCAPS_LOCSOFTWARE equ 00000008h
    DSBCAPS_CTRL3D equ 00000010h
    DSBCAPS_CTRLFREQUENCY equ 00000020h
    DSBCAPS_CTRLPAN equ 00000040h
    DSBCAPS_CTRLVOLUME equ 00000080h
    DSBCAPS_CTRLPOSITIONNOTIFY equ 00000100h
    DSBCAPS_CTRLFX equ 00000200h
    DSBCAPS_STICKYFOCUS equ 00004000h
    DSBCAPS_GLOBALFOCUS equ 00008000h
    DSBCAPS_GETCURRENTPOSITION2 equ 00010000h
    DSBCAPS_MUTE3DATMAXDISTANCE equ 00020000h
    DSBCAPS_LOCDEFER equ 00040000h
    DSBCAPS_TRUEPLAYPOSITION equ 00080000h
    DSBPLAY_LOOPING equ 00000001h
    DSBPLAY_LOCHARDWARE equ 00000002h
    DSBPLAY_LOCSOFTWARE equ 00000004h
    DSBPLAY_TERMINATEBY_TIME equ 00000008h
    DSBPLAY_TERMINATEBY_DISTANCE equ 000000010h
    DSBPLAY_TERMINATEBY_PRIORITY equ 000000020h
    DSBSTATUS_PLAYING equ 00000001h
    DSBSTATUS_BUFFERLOST equ 00000002h
    DSBSTATUS_LOOPING equ 00000004h
    DSBSTATUS_LOCHARDWARE equ 00000008h
    DSBSTATUS_LOCSOFTWARE equ 00000010h
    DSBSTATUS_TERMINATED equ 00000020h
    DSBLOCK_FROMWRITECURSOR equ 00000001h
    DSBLOCK_ENTIREBUFFER equ 00000002h
    DSBFREQUENCY_ORIGINAL equ 0
    DSBFREQUENCY_MIN equ 100
    if DIRECTSOUND_VERSION ge 0900h
      DSBFREQUENCY_MAX equ 200000
    else
      DSBFREQUENCY_MAX equ 100000
    endif
    DSBPAN_LEFT equ -10000
    DSBPAN_CENTER equ 0
    DSBPAN_RIGHT equ 10000
    DSBVOLUME_MIN equ -10000
    DSBVOLUME_MAX equ 0
    DSBSIZE_MIN equ 4
    DSBSIZE_MAX equ 0FFFFFFFh
    DSBSIZE_FX_MIN equ 150; NOTE: Milliseconds, not bytes

    DSBNOTIFICATIONS_MAX equ 100000
    DS3DMODE_NORMAL equ 00000000h
    DS3DMODE_HEADRELATIVE equ 00000001h
    DS3DMODE_DISABLE equ 00000002h
    DS3D_IMMEDIATE equ 00000000h
    DS3D_DEFERRED equ 00000001h
    DS3D_MINDISTANCEFACTOR equ <FLT_MIN>
    DS3D_MAXDISTANCEFACTOR equ <FLT_MAX>
    DS3D_DEFAULTDISTANCEFACTOR equ 1.0
    DS3D_MINROLLOFFFACTOR equ 0.0
    DS3D_MAXROLLOFFFACTOR equ 10.0
    DS3D_DEFAULTROLLOFFFACTOR equ 1.0
    DS3D_MINDOPPLERFACTOR equ 0.0
    DS3D_MAXDOPPLERFACTOR equ 10.0
    DS3D_DEFAULTDOPPLERFACTOR equ 1.0
    DS3D_DEFAULTMINDISTANCE equ 1.0
    DS3D_DEFAULTMAXDISTANCE equ 1000000000.0
    DS3D_MINCONEANGLE equ 0
    DS3D_MAXCONEANGLE equ 360
    DS3D_DEFAULTCONEANGLE equ 360
    DS3D_DEFAULTCONEOUTSIDEVOLUME equ <DSBVOLUME_MAX>
    ; IDirectSoundCapture attributes
    DSCCAPS_EMULDRIVER equ <DSCAPS_EMULDRIVER>
    DSCCAPS_CERTIFIED equ <DSCAPS_CERTIFIED>
    DSCCAPS_MULTIPLECAPTURE equ 00000001h
    ; IDirectSoundCaptureBuffer attributes
    DSCBCAPS_WAVEMAPPED equ 80000000h
    if DIRECTSOUND_VERSION ge 0800h
      DSCBCAPS_CTRLFX equ 00000200h
    endif
    DSCBLOCK_ENTIREBUFFER equ 00000001h
    DSCBSTATUS_CAPTURING equ 00000001h
    DSCBSTATUS_LOOPING equ 00000002h
    DSCBSTART_LOOPING equ 00000001h
    DSBPN_OFFSETSTOP equ 0FFFFFFFFh
    DS_CERTIFIED equ 00000000h
    DS_UNCERTIFIED equ 00000001h
    ; Flags for the I3DL2 effects
    ; I3DL2 Material Presets
    DSFX_I3DL2_MATERIAL_PRESET_SINGLEWINDOW equ 0
    DSFX_I3DL2_MATERIAL_PRESET_DOUBLEWINDOW equ 1
    DSFX_I3DL2_MATERIAL_PRESET_THINDOOR equ 2
    DSFX_I3DL2_MATERIAL_PRESET_THICKDOOR equ 3
    DSFX_I3DL2_MATERIAL_PRESET_WOODWALL equ 4
    DSFX_I3DL2_MATERIAL_PRESET_BRICKWALL equ 5
    DSFX_I3DL2_MATERIAL_PRESET_STONEWALL equ 6
    DSFX_I3DL2_MATERIAL_PRESET_CURTAIN equ 7

    I3DL2_MATERIAL_PRESET_SINGLEWINDOW equ -2800, 0.71
    I3DL2_MATERIAL_PRESET_DOUBLEWINDOW equ -5000, 0.40
    I3DL2_MATERIAL_PRESET_THINDOOR equ -1800, 0.66
    I3DL2_MATERIAL_PRESET_THICKDOOR equ -4400, 0.64
    I3DL2_MATERIAL_PRESET_WOODWALL equ -4000, 0.50
    I3DL2_MATERIAL_PRESET_BRICKWALL equ -5000, 0.60
    I3DL2_MATERIAL_PRESET_STONEWALL equ -6000, 0.68
    I3DL2_MATERIAL_PRESET_CURTAIN equ -1200, 0.15
    DSFX_I3DL2_ENVIRONMENT_PRESET_DEFAULT equ 0
    DSFX_I3DL2_ENVIRONMENT_PRESET_GENERIC equ 1
    DSFX_I3DL2_ENVIRONMENT_PRESET_PADDEDCELL equ 2
    DSFX_I3DL2_ENVIRONMENT_PRESET_ROOM equ 3
    DSFX_I3DL2_ENVIRONMENT_PRESET_BATHROOM equ 4
    DSFX_I3DL2_ENVIRONMENT_PRESET_LIVINGROOM equ 5
    DSFX_I3DL2_ENVIRONMENT_PRESET_STONEROOM equ 6
    DSFX_I3DL2_ENVIRONMENT_PRESET_AUDITORIUM equ 7
    DSFX_I3DL2_ENVIRONMENT_PRESET_CONCERTHALL equ 8
    DSFX_I3DL2_ENVIRONMENT_PRESET_CAVE equ 9
    DSFX_I3DL2_ENVIRONMENT_PRESET_ARENA equ 10
    DSFX_I3DL2_ENVIRONMENT_PRESET_HANGAR equ 11
    DSFX_I3DL2_ENVIRONMENT_PRESET_CARPETEDHALLWAY equ 12
    DSFX_I3DL2_ENVIRONMENT_PRESET_HALLWAY equ 13
    DSFX_I3DL2_ENVIRONMENT_PRESET_STONECORRIDOR equ 14
    DSFX_I3DL2_ENVIRONMENT_PRESET_ALLEY equ 15
    DSFX_I3DL2_ENVIRONMENT_PRESET_FOREST equ 16
    DSFX_I3DL2_ENVIRONMENT_PRESET_CITY equ 17
    DSFX_I3DL2_ENVIRONMENT_PRESET_MOUNTAINS equ 18
    DSFX_I3DL2_ENVIRONMENT_PRESET_QUARRY equ 19
    DSFX_I3DL2_ENVIRONMENT_PRESET_PLAIN equ 20
    DSFX_I3DL2_ENVIRONMENT_PRESET_PARKINGLOT equ 21
    DSFX_I3DL2_ENVIRONMENT_PRESET_SEWERPIPE equ 22
    DSFX_I3DL2_ENVIRONMENT_PRESET_UNDERWATER equ 23
    DSFX_I3DL2_ENVIRONMENT_PRESET_SMALLROOM equ 24
    DSFX_I3DL2_ENVIRONMENT_PRESET_MEDIUMROOM equ 25
    DSFX_I3DL2_ENVIRONMENT_PRESET_LARGEROOM equ 26
    DSFX_I3DL2_ENVIRONMENT_PRESET_MEDIUMHALL equ 27
    DSFX_I3DL2_ENVIRONMENT_PRESET_LARGEHALL equ 28
    DSFX_I3DL2_ENVIRONMENT_PRESET_PLATE equ 29

    ; I3DL2 Reverberation Presets Values
    I3DL2_ENVIRONMENT_PRESET_DEFAULT equ -1000, - 100, 0.0, 1.49, 0.83, - 2602, 0.007, 200, 0.011, 100.0, 100.0, 5000.0
    I3DL2_ENVIRONMENT_PRESET_GENERIC equ -1000, - 100, 0.0, 1.49, 0.83, - 2602, 0.007, 200, 0.011, 100.0, 100.0, 5000.0
    I3DL2_ENVIRONMENT_PRESET_PADDEDCELL equ -1000, - 6000, 0.0, 0.17, 0.10, - 1204, 0.001, 207, 0.002, 100.0, 100.0, 5000.0
    I3DL2_ENVIRONMENT_PRESET_ROOM equ -1000, - 454, 0.0, 0.40, 0.83, - 1646, 0.002, 53, 0.003, 100.0, 100.0, 5000.0
    I3DL2_ENVIRONMENT_PRESET_BATHROOM equ -1000, - 1200, 0.0, 1.49, 0.54, - 370, 0.007, 1030, 0.011, 100.0, 60.0, 5000.0
    I3DL2_ENVIRONMENT_PRESET_LIVINGROOM equ -1000, - 6000, 0.0, 0.50, 0.10, - 1376, 0.003, - 1104, 0.004, 100.0, 100.0, 5000.0
    I3DL2_ENVIRONMENT_PRESET_STONEROOM equ -1000, - 300, 0.0, 2.31, 0.64, - 711, 0.012, 83, 0.017, 100.0, 100.0, 5000.0
    I3DL2_ENVIRONMENT_PRESET_AUDITORIUM equ -1000, - 476, 0.0, 4.32, 0.59, - 789, 0.020, - 289, 0.030, 100.0, 100.0, 5000.0
    I3DL2_ENVIRONMENT_PRESET_CONCERTHALL equ -1000, - 500, 0.0, 3.92, 0.70, - 1230, 0.020, - 2, 0.029, 100.0, 100.0, 5000.0
    I3DL2_ENVIRONMENT_PRESET_CAVE equ -1000, 0, 0.0, 2.91, 1.30, - 602, 0.015, - 302, 0.022, 100.0, 100.0, 5000.0
    I3DL2_ENVIRONMENT_PRESET_ARENA equ -1000, - 698, 0.0, 7.24, 0.33, - 1166, 0.020, 16, 0.030, 100.0, 100.0, 5000.0
    I3DL2_ENVIRONMENT_PRESET_HANGAR equ -1000, - 1000, 0.0, 10.05, 0.23, - 602, 0.020, 198, 0.030, 100.0, 100.0, 5000.0
    I3DL2_ENVIRONMENT_PRESET_CARPETEDHALLWAY equ -1000, - 4000, 0.0, 0.30, 0.10, - 1831, 0.002, - 1630, 0.030, 100.0, 100.0, 5000.0
    I3DL2_ENVIRONMENT_PRESET_HALLWAY equ -1000, - 300, 0.0, 1.49, 0.59, - 1219, 0.007, 441, 0.011, 100.0, 100.0, 5000.0
    I3DL2_ENVIRONMENT_PRESET_STONECORRIDOR equ -1000, - 237, 0.0, 2.70, 0.79, - 1214, 0.013, 395, 0.020, 100.0, 100.0, 5000.0
    I3DL2_ENVIRONMENT_PRESET_ALLEY equ -1000, - 270, 0.0, 1.49, 0.86, - 1204, 0.007, - 4, 0.011, 100.0, 100.0, 5000.0
    I3DL2_ENVIRONMENT_PRESET_FOREST equ -1000, - 3300, 0.0, 1.49, 0.54, - 2560, 0.162, - 613, 0.088, 79.0, 100.0, 5000.0
    I3DL2_ENVIRONMENT_PRESET_CITY equ -1000, - 800, 0.0, 1.49, 0.67, - 2273, 0.007, - 2217, 0.011, 50.0, 100.0, 5000.0
    I3DL2_ENVIRONMENT_PRESET_MOUNTAINS equ -1000, - 2500, 0.0, 1.49, 0.21, - 2780, 0.300, - 2014, 0.100, 27.0, 100.0, 5000.0
    I3DL2_ENVIRONMENT_PRESET_QUARRY equ -1000, - 1000, 0.0, 1.49, 0.83, - 10000, 0.061, 500, 0.025, 100.0, 100.0, 5000.0
    I3DL2_ENVIRONMENT_PRESET_PLAIN equ -1000, - 2000, 0.0, 1.49, 0.50, - 2466, 0.179, - 2514, 0.100, 21.0, 100.0, 5000.0
    I3DL2_ENVIRONMENT_PRESET_PARKINGLOT equ -1000, 0, 0.0, 1.65, 1.50, - 1363, 0.008, - 1153, 0.012, 100.0, 100.0, 5000.0
    I3DL2_ENVIRONMENT_PRESET_SEWERPIPE equ -1000, - 1000, 0.0, 2.81, 0.14, 429, 0.014, 648, 0.021, 80.0, 60.0, 5000.0
    I3DL2_ENVIRONMENT_PRESET_UNDERWATER equ -1000, - 4000, 0.0, 1.49, 0.10, - 449, 0.007, 1700, 0.011, 100.0, 100.0, 5000.0
    ; Examples simulating 'musical' reverb presets
    ; Name       Decay time   Description
    ; Small Room    1.1s      A small size room with a length of 5m or so.
    ; Medium Room   1.3s      A medium size room with a length of 10m or so.
    ; Large Room    1.5s      A large size room suitable for live performances.
    ; Medium Hall   1.8s      A medium size concert hall.
    ; Large Hall    1.8s      A large size concert hall suitable for a full orchestra.
    ; Plate         1.3s      A plate reverb simulation.
    I3DL2_ENVIRONMENT_PRESET_SMALLROOM equ -1000, - 600, 0.0, 1.10, 0.83, - 400, 0.005, 500, 0.010, 100.0, 100.0, 5000.0
    I3DL2_ENVIRONMENT_PRESET_MEDIUMROOM equ -1000, - 600, 0.0, 1.30, 0.83, - 1000, 0.010, - 200, 0.020, 100.0, 100.0, 5000.0
    I3DL2_ENVIRONMENT_PRESET_LARGEROOM equ -1000, - 600, 0.0, 1.50, 0.83, - 1600, 0.020, - 1000, 0.040, 100.0, 100.0, 5000.0
    I3DL2_ENVIRONMENT_PRESET_MEDIUMHALL equ -1000, - 600, 0.0, 1.80, 0.70, - 1300, 0.015, - 800, 0.030, 100.0, 100.0, 5000.0
    I3DL2_ENVIRONMENT_PRESET_LARGEHALL equ -1000, - 600, 0.0, 1.80, 0.70, - 2000, 0.030, - 1400, 0.060, 100.0, 100.0, 5000.0
    I3DL2_ENVIRONMENT_PRESET_PLATE equ -1000, - 200, 0.0, 1.30, 0.90, 0, 0.002, 0, 0.010, 100.0, 75.0, 5000.0
    ; DirectSound3D Algorithms
    ; Default DirectSound3D algorithm {00000000-0000-0000-0000-000000000000}
    DS3DALG_DEFAULT equ <GUID_NULL>
    ; No virtualization (Pan3D) {C241333F-1C1B-11d2-94F5-00C04FC28ACA}
    DEFINE_GUID DS3DALG_NO_VIRTUALIZATION, 0c241333fh, 1c1bh, 11d2h, 94h, 0f5h, 0h, 0c0h, 4fh, 0c2h, 8ah, 0cah
    ; High-quality HRTF algorithm {C2413340-1C1B-11d2-94F5-00C04FC28ACA}
    DEFINE_GUID DS3DALG_HRTF_FULL, 0c2413340h, 1c1bh, 11d2h, 94h, 0f5h, 0h, 0c0h, 4fh, 0c2h, 8ah, 0cah
    ; Lower-quality HRTF algorithm {C2413342-1C1B-11d2-94F5-00C04FC28ACA}
    DEFINE_GUID DS3DALG_HRTF_LIGHT, 0c2413342h, 1c1bh, 11d2h, 94h, 0f5h, 0h, 0c0h, 4fh, 0c2h, 8ah, 0cah
    if DIRECTSOUND_VERSION ge 0800h
      ; DirectSound Internal Effect Algorithms
      ; Gargle {DAFD8210-5711-4B91-9FE3-F75B7AE279BF}
      DEFINE_GUID GUID_DSFX_STANDARD_GARGLE, 0dafd8210h, 5711h, 4b91h, 9fh, 0e3h, 0f7h, 5bh, 7ah, 0e2h, 79h, 0bfh
      ; Chorus {EFE6629C-81F7-4281-BD91-C9D604A95AF6}
      DEFINE_GUID GUID_DSFX_STANDARD_CHORUS, 0efe6629ch, 81f7h, 4281h, 0bdh, 91h, 0c9h, 0d6h, 04h, 0a9h, 5ah, 0f6h
      ; Flanger {EFCA3D92-DFD8-4672-A603-7420894BAD98}
      DEFINE_GUID GUID_DSFX_STANDARD_FLANGER, 0efca3d92h, 0dfd8h, 4672h, 0a6h, 03h, 74h, 20h, 89h, 4bh, 0adh, 98h
      ; Echo/Delay {EF3E932C-D40B-4F51-8CCF-3F98F1B29D5D}
      DEFINE_GUID GUID_DSFX_STANDARD_ECHO, 0ef3e932ch, 0d40bh, 4f51h, 8ch, 0cfh, 3fh, 98h, 0f1h, 0b2h, 9dh, 5dh
      ; Distortion {EF114C90-CD1D-484E-96E5-09CFAF912A21}
      DEFINE_GUID GUID_DSFX_STANDARD_DISTORTION, 0ef114c90h, 0cd1dh, 484eh, 96h, 0e5h, 09h, 0cfh, 0afh, 91h, 2ah, 21h
      ; Compressor/Limiter {EF011F79-4000-406D-87AF-BFFB3FC39D57}
      DEFINE_GUID GUID_DSFX_STANDARD_COMPRESSOR, 0ef011f79h, 4000h, 406dh, 87h, 0afh, 0bfh, 0fbh, 3fh, 0c3h, 9dh, 57h
      ; Parametric Equalization {120CED89-3BF4-4173-A132-3CB406CF3231}
      DEFINE_GUID GUID_DSFX_STANDARD_PARAMEQ, 120ced89h, 3bf4h, 4173h, 0a1h, 32h, 3ch, 0b4h, 06h, 0cfh, 32h, 31h
      ; I3DL2 Environmental Reverberation: Reverb (Listener) Effect {EF985E71-D5C7-42D4-BA4D-2D073E2E96F4}
      DEFINE_GUID GUID_DSFX_STANDARD_I3DL2REVERB, 0ef985e71h, 0d5c7h, 42d4h, 0bah, 4dh, 2dh, 07h, 3eh, 2eh, 96h, 0f4h
      ; Waves Reverberation {87FC0268-9A55-4360-95AA-004A1D9DE26C}
      DEFINE_GUID GUID_DSFX_WAVES_REVERB, 87fc0268h, 9a55h, 4360h, 95h, 0aah, 00h, 4ah, 1dh, 9dh, 0e2h, 6ch
      ; DirectSound Capture Effect Algorithms
      ; Acoustic Echo Canceller {BF963D80-C559-11D0-8A2B-00A0C9255AC1}
      ; Matches KSNODETYPE_ACOUSTIC_ECHO_CANCEL in ksmedia.h
      DEFINE_GUID GUID_DSCFX_CLASS_AEC, 0BF963D80h, 0C559h, 11D0h, 8Ah, 2Bh, 00h, 0A0h, 0C9h, 25h, 5Ah, 0C1h
      ; Microsoft AEC {CDEBB919-379A-488a-8765-F53CFD36DE40}
      DEFINE_GUID GUID_DSCFX_MS_AEC, 0cdebb919h, 379ah, 488ah, 87h, 65h, 0f5h, 3ch, 0fdh, 36h, 0deh, 40h
      ; System AEC {1C22C56D-9879-4f5b-A389-27996DDC2810}
      DEFINE_GUID GUID_DSCFX_SYSTEM_AEC, 1c22c56dh, 9879h, 4f5bh, 0a3h, 89h, 27h, 99h, 6dh, 0dch, 28h, 10h
      ; Noise Supression {E07F903F-62FD-4e60-8CDD-DEA7236665B5}
      ; Matches KSNODETYPE_NOISE_SUPPRESS in post Windows ME DDK's ksmedia.h
      DEFINE_GUID GUID_DSCFX_CLASS_NS, 0e07f903fh, 62fdh, 4e60h, 8ch, 0ddh, 0deh, 0a7h, 23h, 66h, 65h, 0b5h
      ; Microsoft Noise Suppresion {11C5C73B-66E9-4ba1-A0BA-E814C6EED92D}
      DEFINE_GUID GUID_DSCFX_MS_NS, 11c5c73bh, 66e9h, 4ba1h, 0a0h, 0bah, 0e8h, 14h, 0c6h, 0eeh, 0d9h, 2dh
      ; System Noise Suppresion {5AB0882E-7274-4516-877D-4EEE99BA4FD0}
      DEFINE_GUID GUID_DSCFX_SYSTEM_NS, 5ab0882eh, 7274h, 4516h, 87h, 7dh, 4eh, 0eeh, 99h, 0bah, 4fh, 0d0h
    endif
    ; DIRECTSOUND_VERSION >= 0x0800
  endif
  ; __DSOUND_INCLUDED__
  ifdef __cplusplus
    ;[...]
  endif
  ; __cplusplus
  ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) *
endif
