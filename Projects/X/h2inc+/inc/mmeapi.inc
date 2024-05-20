;Include file created by h2inc+ version C.2.0 on (UTC) 20/05/2024 18:06:34
;(C) G. Friedrich April 2024
;Source file: d:\objasm\projects\x\h2inc+\h\um_10.0.22621.0\mmeapi.h
;             Created on (UTC) 06/04/2024 06:15:56
;             Last modified on (UTC) 21/02/2024 18:13:22

;********************************************************************************
ifdef _MSC_VER
endif
; _MSC_VER
ifndef _MMEAPI_H_
  _MMEAPI_H_ equ <>
  include apiset.inc
  include apisetcconv.inc
  ifdef _CONTRACT_GEN
    include nt.inc
    include ntrtl.inc
    include nturtl.inc
    include windows.inc
  endif
  ; _CONTRACT_GEN
  include mmsyscom.inc
  ; mm common definitions
  ifdef __cplusplus
    ;[...]
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    ifndef MMNOWAVE
      ;****************************************************************************
      ;Waveform audio support
      ;****************************************************************************
      ;* waveform audio error return values *
      ;* unsupported wave format *
      WAVERR_BADFORMAT equ (WAVERR_BASE + 0)
      ;* still something playing *
      WAVERR_STILLPLAYING equ (WAVERR_BASE + 1)
      ;* header not prepared *
      WAVERR_UNPREPARED equ (WAVERR_BASE + 2)
      ;* device is synchronous *
      WAVERR_SYNC equ (WAVERR_BASE + 3)
      ;* last error in range *
      WAVERR_LASTERROR equ (WAVERR_BASE + 3)
      ;* waveform audio data types *
      DECLARE_HANDLE HWAVE
      DECLARE_HANDLE HWAVEIN
      DECLARE_HANDLE HWAVEOUT
      LPHWAVEIN typedef ptr HWAVEIN
      LPHWAVEOUT typedef ptr HWAVEOUT
      WAVECALLBACK typedef DRVCALLBACK
      LPWAVECALLBACK typedef ptr WAVECALLBACK
      ;* wave callback messages *
      WOM_OPEN equ <MM_WOM_OPEN>
      WOM_CLOSE equ <MM_WOM_CLOSE>
      WOM_DONE equ <MM_WOM_DONE>
      WIM_OPEN equ <MM_WIM_OPEN>
      WIM_CLOSE equ <MM_WIM_CLOSE>
      WIM_DATA equ <MM_WIM_DATA>
      ;* device ID for wave device mapper *
      WAVE_MAPPER equ (- 1)
      ;* flags for dwFlags parameter in waveOutOpen() and waveInOpen() *
      WAVE_FORMAT_QUERY equ 0001h
      WAVE_ALLOWSYNC equ 0002h
      if (WINVER ge 0400h)
        WAVE_MAPPED equ 0004h
        WAVE_FORMAT_DIRECT equ 0008h
        WAVE_FORMAT_DIRECT_QUERY equ <(WAVE_FORMAT_QUERY or WAVE_FORMAT_DIRECT)>
        WAVE_MAPPED_DEFAULT_COMMUNICATION_DEVICE equ 0010h
        ;* (WINVER >= 0x0400) *
      endif
      ;* wave data block header *
      WAVEHDR struct
        lpData POINTER ?
        ;* pointer to locked data buffer *
        dwBufferLength DWORD ?
        ;* length of data buffer *
        dwBytesRecorded DWORD ?
        ;* used for input only *
        dwUser XWORD ?
        ;* for client's use *
        dwFlags DWORD ?
        ;* assorted flags (see defines) *
        dwLoops DWORD ?
        ;* loop control counter *
        lpNext POINTER ?
        ;* reserved for driver *
        reserved XWORD ?
        ;* reserved for driver *
      WAVEHDR ends
      wavehdr_tag typedef WAVEHDR
      PWAVEHDR typedef ptr WAVEHDR
      NPWAVEHDR typedef ptr WAVEHDR
      LPWAVEHDR typedef ptr WAVEHDR
      ;* flags for dwFlags field of WAVEHDR *
      ;* done bit *
      WHDR_DONE equ 00000001h
      ;* set if this header has been prepared *
      WHDR_PREPARED equ 00000002h
      ;* loop start block *
      WHDR_BEGINLOOP equ 00000004h
      ;* loop end block *
      WHDR_ENDLOOP equ 00000008h
      ;* reserved for driver *
      WHDR_INQUEUE equ 00000010h
      ;* waveform output device capabilities structure *
      ifdef _WIN32
        WAVEOUTCAPSA struct
          wMid WORD ?
          ;* manufacturer ID *
          wPid WORD ?
          ;* product ID *
          vDriverVersion MMVERSION ?
          ;* version of the driver *
          szPname SBYTE MAXPNAMELEN dup (?)
          ;* product name (NULL terminated string) *
          dwFormats DWORD ?
          ;* formats supported *
          wChannels WORD ?
          ;* number of sources supported *
          wReserved1 WORD ?
          ;* packing *
          dwSupport DWORD ?
          ;* functionality supported by driver *
        WAVEOUTCAPSA ends
        tagWAVEOUTCAPSA typedef WAVEOUTCAPSA
        PWAVEOUTCAPSA typedef ptr WAVEOUTCAPSA
        NPWAVEOUTCAPSA typedef ptr WAVEOUTCAPSA
        LPWAVEOUTCAPSA typedef ptr WAVEOUTCAPSA
        WAVEOUTCAPSW struct
          wMid WORD ?
          ;* manufacturer ID *
          wPid WORD ?
          ;* product ID *
          vDriverVersion MMVERSION ?
          ;* version of the driver *
          szPname WORD MAXPNAMELEN dup (?)
          ;* product name (NULL terminated string) *
          dwFormats DWORD ?
          ;* formats supported *
          wChannels WORD ?
          ;* number of sources supported *
          wReserved1 WORD ?
          ;* packing *
          dwSupport DWORD ?
          ;* functionality supported by driver *
        WAVEOUTCAPSW ends
        tagWAVEOUTCAPSW typedef WAVEOUTCAPSW
        PWAVEOUTCAPSW typedef ptr WAVEOUTCAPSW
        NPWAVEOUTCAPSW typedef ptr WAVEOUTCAPSW
        LPWAVEOUTCAPSW typedef ptr WAVEOUTCAPSW
        ifdef UNICODE
          WAVEOUTCAPS typedef WAVEOUTCAPSW
          PWAVEOUTCAPS typedef PWAVEOUTCAPSW
          NPWAVEOUTCAPS typedef NPWAVEOUTCAPSW
          LPWAVEOUTCAPS typedef LPWAVEOUTCAPSW
        else
          WAVEOUTCAPS typedef WAVEOUTCAPSA
          PWAVEOUTCAPS typedef PWAVEOUTCAPSA
          NPWAVEOUTCAPS typedef NPWAVEOUTCAPSA
          LPWAVEOUTCAPS typedef LPWAVEOUTCAPSA
        endif
        ; UNICODE
        WAVEOUTCAPS2A struct
          wMid WORD ?
          ;* manufacturer ID *
          wPid WORD ?
          ;* product ID *
          vDriverVersion MMVERSION ?
          ;* version of the driver *
          szPname SBYTE MAXPNAMELEN dup (?)
          ;* product name (NULL terminated string) *
          dwFormats DWORD ?
          ;* formats supported *
          wChannels WORD ?
          ;* number of sources supported *
          wReserved1 WORD ?
          ;* packing *
          dwSupport DWORD ?
          ;* functionality supported by driver *
          ManufacturerGuid GUID <>
          ;* for extensible MID mapping *
          ProductGuid GUID <>
          ;* for extensible PID mapping *
          NameGuid GUID <>
          ;* for name lookup in registry *
        WAVEOUTCAPS2A ends
        tagWAVEOUTCAPS2A typedef WAVEOUTCAPS2A
        PWAVEOUTCAPS2A typedef ptr WAVEOUTCAPS2A
        NPWAVEOUTCAPS2A typedef ptr WAVEOUTCAPS2A
        LPWAVEOUTCAPS2A typedef ptr WAVEOUTCAPS2A
        WAVEOUTCAPS2W struct
          wMid WORD ?
          ;* manufacturer ID *
          wPid WORD ?
          ;* product ID *
          vDriverVersion MMVERSION ?
          ;* version of the driver *
          szPname WORD MAXPNAMELEN dup (?)
          ;* product name (NULL terminated string) *
          dwFormats DWORD ?
          ;* formats supported *
          wChannels WORD ?
          ;* number of sources supported *
          wReserved1 WORD ?
          ;* packing *
          dwSupport DWORD ?
          ;* functionality supported by driver *
          ManufacturerGuid GUID <>
          ;* for extensible MID mapping *
          ProductGuid GUID <>
          ;* for extensible PID mapping *
          NameGuid GUID <>
          ;* for name lookup in registry *
        WAVEOUTCAPS2W ends
        tagWAVEOUTCAPS2W typedef WAVEOUTCAPS2W
        PWAVEOUTCAPS2W typedef ptr WAVEOUTCAPS2W
        NPWAVEOUTCAPS2W typedef ptr WAVEOUTCAPS2W
        LPWAVEOUTCAPS2W typedef ptr WAVEOUTCAPS2W
        ifdef UNICODE
          WAVEOUTCAPS2 typedef WAVEOUTCAPS2W
          PWAVEOUTCAPS2 typedef PWAVEOUTCAPS2W
          NPWAVEOUTCAPS2 typedef NPWAVEOUTCAPS2W
          LPWAVEOUTCAPS2 typedef LPWAVEOUTCAPS2W
        else
          WAVEOUTCAPS2 typedef WAVEOUTCAPS2A
          PWAVEOUTCAPS2 typedef PWAVEOUTCAPS2A
          NPWAVEOUTCAPS2 typedef NPWAVEOUTCAPS2A
          LPWAVEOUTCAPS2 typedef LPWAVEOUTCAPS2A
        endif
        ; UNICODE
      else
        ;[...]
      endif
      ;* flags for dwSupport field of WAVEOUTCAPS *
      ;* supports pitch control *
      WAVECAPS_PITCH equ 0001h
      ;* supports playback rate control *
      WAVECAPS_PLAYBACKRATE equ 0002h
      ;* supports volume control *
      WAVECAPS_VOLUME equ 0004h
      ;* separate left-right volume control *
      WAVECAPS_LRVOLUME equ 0008h
      WAVECAPS_SYNC equ 0010h
      WAVECAPS_SAMPLEACCURATE equ 0020h
      ;* waveform input device capabilities structure *
      ifdef _WIN32
        WAVEINCAPSA struct
          wMid WORD ?
          ;* manufacturer ID *
          wPid WORD ?
          ;* product ID *
          vDriverVersion MMVERSION ?
          ;* version of the driver *
          szPname SBYTE MAXPNAMELEN dup (?)
          ;* product name (NULL terminated string) *
          dwFormats DWORD ?
          ;* formats supported *
          wChannels WORD ?
          ;* number of channels supported *
          wReserved1 WORD ?
          ;* structure packing *
        WAVEINCAPSA ends
        tagWAVEINCAPSA typedef WAVEINCAPSA
        PWAVEINCAPSA typedef ptr WAVEINCAPSA
        NPWAVEINCAPSA typedef ptr WAVEINCAPSA
        LPWAVEINCAPSA typedef ptr WAVEINCAPSA
        WAVEINCAPSW struct
          wMid WORD ?
          ;* manufacturer ID *
          wPid WORD ?
          ;* product ID *
          vDriverVersion MMVERSION ?
          ;* version of the driver *
          szPname WORD MAXPNAMELEN dup (?)
          ;* product name (NULL terminated string) *
          dwFormats DWORD ?
          ;* formats supported *
          wChannels WORD ?
          ;* number of channels supported *
          wReserved1 WORD ?
          ;* structure packing *
        WAVEINCAPSW ends
        tagWAVEINCAPSW typedef WAVEINCAPSW
        PWAVEINCAPSW typedef ptr WAVEINCAPSW
        NPWAVEINCAPSW typedef ptr WAVEINCAPSW
        LPWAVEINCAPSW typedef ptr WAVEINCAPSW
        ifdef UNICODE
          WAVEINCAPS typedef WAVEINCAPSW
          PWAVEINCAPS typedef PWAVEINCAPSW
          NPWAVEINCAPS typedef NPWAVEINCAPSW
          LPWAVEINCAPS typedef LPWAVEINCAPSW
        else
          WAVEINCAPS typedef WAVEINCAPSA
          PWAVEINCAPS typedef PWAVEINCAPSA
          NPWAVEINCAPS typedef NPWAVEINCAPSA
          LPWAVEINCAPS typedef LPWAVEINCAPSA
        endif
        ; UNICODE
        WAVEINCAPS2A struct
          wMid WORD ?
          ;* manufacturer ID *
          wPid WORD ?
          ;* product ID *
          vDriverVersion MMVERSION ?
          ;* version of the driver *
          szPname SBYTE MAXPNAMELEN dup (?)
          ;* product name (NULL terminated string) *
          dwFormats DWORD ?
          ;* formats supported *
          wChannels WORD ?
          ;* number of channels supported *
          wReserved1 WORD ?
          ;* structure packing *
          ManufacturerGuid GUID <>
          ;* for extensible MID mapping *
          ProductGuid GUID <>
          ;* for extensible PID mapping *
          NameGuid GUID <>
          ;* for name lookup in registry *
        WAVEINCAPS2A ends
        tagWAVEINCAPS2A typedef WAVEINCAPS2A
        PWAVEINCAPS2A typedef ptr WAVEINCAPS2A
        NPWAVEINCAPS2A typedef ptr WAVEINCAPS2A
        LPWAVEINCAPS2A typedef ptr WAVEINCAPS2A
        WAVEINCAPS2W struct
          wMid WORD ?
          ;* manufacturer ID *
          wPid WORD ?
          ;* product ID *
          vDriverVersion MMVERSION ?
          ;* version of the driver *
          szPname WORD MAXPNAMELEN dup (?)
          ;* product name (NULL terminated string) *
          dwFormats DWORD ?
          ;* formats supported *
          wChannels WORD ?
          ;* number of channels supported *
          wReserved1 WORD ?
          ;* structure packing *
          ManufacturerGuid GUID <>
          ;* for extensible MID mapping *
          ProductGuid GUID <>
          ;* for extensible PID mapping *
          NameGuid GUID <>
          ;* for name lookup in registry *
        WAVEINCAPS2W ends
        tagWAVEINCAPS2W typedef WAVEINCAPS2W
        PWAVEINCAPS2W typedef ptr WAVEINCAPS2W
        NPWAVEINCAPS2W typedef ptr WAVEINCAPS2W
        LPWAVEINCAPS2W typedef ptr WAVEINCAPS2W
        ifdef UNICODE
          WAVEINCAPS2 typedef WAVEINCAPS2W
          PWAVEINCAPS2 typedef PWAVEINCAPS2W
          NPWAVEINCAPS2 typedef NPWAVEINCAPS2W
          LPWAVEINCAPS2 typedef LPWAVEINCAPS2W
        else
          WAVEINCAPS2 typedef WAVEINCAPS2A
          PWAVEINCAPS2 typedef PWAVEINCAPS2A
          NPWAVEINCAPS2 typedef NPWAVEINCAPS2A
          LPWAVEINCAPS2 typedef LPWAVEINCAPS2A
        endif
        ; UNICODE
      else
        ;[...]
      endif
      ;* defines for dwFormat field of WAVEINCAPS and WAVEOUTCAPS *
      ;* invalid format *
      WAVE_INVALIDFORMAT equ 00000000h
      ;* 11.025 kHz, Mono,   8-bit  *
      WAVE_FORMAT_1M08 equ 00000001h
      ;* 11.025 kHz, Stereo, 8-bit  *
      WAVE_FORMAT_1S08 equ 00000002h
      ;* 11.025 kHz, Mono,   16-bit *
      WAVE_FORMAT_1M16 equ 00000004h
      ;* 11.025 kHz, Stereo, 16-bit *
      WAVE_FORMAT_1S16 equ 00000008h
      ;* 22.05  kHz, Mono,   8-bit  *
      WAVE_FORMAT_2M08 equ 00000010h
      ;* 22.05  kHz, Stereo, 8-bit  *
      WAVE_FORMAT_2S08 equ 00000020h
      ;* 22.05  kHz, Mono,   16-bit *
      WAVE_FORMAT_2M16 equ 00000040h
      ;* 22.05  kHz, Stereo, 16-bit *
      WAVE_FORMAT_2S16 equ 00000080h
      ;* 44.1   kHz, Mono,   8-bit  *
      WAVE_FORMAT_4M08 equ 00000100h
      ;* 44.1   kHz, Stereo, 8-bit  *
      WAVE_FORMAT_4S08 equ 00000200h
      ;* 44.1   kHz, Mono,   16-bit *
      WAVE_FORMAT_4M16 equ 00000400h
      ;* 44.1   kHz, Stereo, 16-bit *
      WAVE_FORMAT_4S16 equ 00000800h
      ;* 44.1   kHz, Mono,   8-bit  *
      WAVE_FORMAT_44M08 equ 00000100h
      ;* 44.1   kHz, Stereo, 8-bit  *
      WAVE_FORMAT_44S08 equ 00000200h
      ;* 44.1   kHz, Mono,   16-bit *
      WAVE_FORMAT_44M16 equ 00000400h
      ;* 44.1   kHz, Stereo, 16-bit *
      WAVE_FORMAT_44S16 equ 00000800h
      ;* 48     kHz, Mono,   8-bit  *
      WAVE_FORMAT_48M08 equ 00001000h
      ;* 48     kHz, Stereo, 8-bit  *
      WAVE_FORMAT_48S08 equ 00002000h
      ;* 48     kHz, Mono,   16-bit *
      WAVE_FORMAT_48M16 equ 00004000h
      ;* 48     kHz, Stereo, 16-bit *
      WAVE_FORMAT_48S16 equ 00008000h
      ;* 96     kHz, Mono,   8-bit  *
      WAVE_FORMAT_96M08 equ 00010000h
      ;* 96     kHz, Stereo, 8-bit  *
      WAVE_FORMAT_96S08 equ 00020000h
      ;* 96     kHz, Mono,   16-bit *
      WAVE_FORMAT_96M16 equ 00040000h
      ;* 96     kHz, Stereo, 16-bit *
      WAVE_FORMAT_96S16 equ 00080000h
      ifndef WAVE_FORMAT_PCM
        ;* OLD general waveform format structure (information common to all formats) *
        WAVEFORMAT struct
          wFormatTag WORD ?
          ;* format type *
          nChannels WORD ?
          ;* number of channels (i.e. mono, stereo, etc.) *
          nSamplesPerSec DWORD ?
          ;* sample rate *
          nAvgBytesPerSec DWORD ?
          ;* for buffer estimation *
          nBlockAlign WORD ?
          ;* block size of data *
        WAVEFORMAT ends
        waveformat_tag typedef WAVEFORMAT
        PWAVEFORMAT typedef ptr WAVEFORMAT
        NPWAVEFORMAT typedef ptr WAVEFORMAT
        LPWAVEFORMAT typedef ptr WAVEFORMAT
        ;* flags for wFormatTag field of WAVEFORMAT *
        WAVE_FORMAT_PCM equ 1
        ;* specific waveform format structure for PCM data *
        PCMWAVEFORMAT struct
          wf WAVEFORMAT <>
          wBitsPerSample WORD ?
        PCMWAVEFORMAT ends
        pcmwaveformat_tag typedef PCMWAVEFORMAT
        PPCMWAVEFORMAT typedef ptr PCMWAVEFORMAT
        NPPCMWAVEFORMAT typedef ptr PCMWAVEFORMAT
        LPPCMWAVEFORMAT typedef ptr PCMWAVEFORMAT
        ;* WAVE_FORMAT_PCM *
      endif
      ifndef _WAVEFORMATEX_
        _WAVEFORMATEX_ equ <>
        ;*
        ;*  extended waveform format structure used for all non-PCM formats. this
        ;*  structure is common to all non-PCM formats.
        ;*
        WAVEFORMATEX struct
          wFormatTag WORD ?
          ;* format type *
          nChannels WORD ?
          ;* number of channels (i.e. mono, stereo...) *
          nSamplesPerSec DWORD ?
          ;* sample rate *
          nAvgBytesPerSec DWORD ?
          ;* for buffer estimation *
          nBlockAlign WORD ?
          ;* block size of data *
          wBitsPerSample WORD ?
          ;* number of bits per sample of mono data *
          cbSize WORD ?
          ;* the count in bytes of the size of *
          ;* extra information (after cbSize) *
        WAVEFORMATEX ends
        tWAVEFORMATEX typedef WAVEFORMATEX
        PWAVEFORMATEX typedef ptr WAVEFORMATEX
        NPWAVEFORMATEX typedef ptr WAVEFORMATEX
        LPWAVEFORMATEX typedef ptr WAVEFORMATEX
        ;* _WAVEFORMATEX_ *
      endif
      LPCWAVEFORMATEX typedef ptr WAVEFORMATEX
      ;* waveform audio function prototypes *
      @DefProto DllImport, waveOutGetNumDevs, WIN_STD_CALL_CONV,, <>, 0
      ifdef _WIN32
        @DefProto DllImport, waveOutGetDevCapsA, WIN_STD_CALL_CONV,, <:UINT_PTR, :LPWAVEOUTCAPSA, :UINT>, 12
        @DefProto DllImport, waveOutGetDevCapsW, WIN_STD_CALL_CONV,, <:UINT_PTR, :LPWAVEOUTCAPSW, :UINT>, 12
        ifdef UNICODE
          waveOutGetDevCaps equ <waveOutGetDevCapsW>
        else
          waveOutGetDevCaps equ <waveOutGetDevCapsA>
        endif
        ; !UNICODE
      else
        ;[...]
      endif
      if (WINVER ge 0400h)
        @DefProto DllImport, waveOutGetVolume, WIN_STD_CALL_CONV,, <:HWAVEOUT, :LPDWORD>, 8
        @DefProto DllImport, waveOutSetVolume, WIN_STD_CALL_CONV,, <:HWAVEOUT, :DWORD>, 8
      else
        @DefProto DllImport, waveOutGetVolume, WIN_STD_CALL_CONV,, <:UINT, :LPDWORD>, 8
        @DefProto DllImport, waveOutSetVolume, WIN_STD_CALL_CONV,, <:UINT, :DWORD>, 8
      endif
      ifdef _WIN32
        @DefProto DllImport, waveOutGetErrorTextA, WIN_STD_CALL_CONV,, <:MMRESULT, :LPSTR, :UINT>, 12
        @DefProto DllImport, waveOutGetErrorTextW, WIN_STD_CALL_CONV,, <:MMRESULT, :LPWSTR, :UINT>, 12
        ifdef UNICODE
          waveOutGetErrorText equ <waveOutGetErrorTextW>
        else
          waveOutGetErrorText equ <waveOutGetErrorTextA>
        endif
        ; !UNICODE
      else
        ;[...]
      endif
      @DefProto DllImport, waveOutOpen, WIN_STD_CALL_CONV,, <:LPHWAVEOUT, :UINT, :LPCWAVEFORMATEX, :DWORD_PTR, :DWORD_PTR, :DWORD>, 24
      @DefProto DllImport, waveOutClose, WIN_STD_CALL_CONV,, <:HWAVEOUT>, 4
      @DefProto DllImport, waveOutPrepareHeader, WIN_STD_CALL_CONV,, <:HWAVEOUT, :LPWAVEHDR, :UINT>, 12
      @DefProto DllImport, waveOutUnprepareHeader, WIN_STD_CALL_CONV,, <:HWAVEOUT, :LPWAVEHDR, :UINT>, 12
      @DefProto DllImport, waveOutWrite, WIN_STD_CALL_CONV,, <:HWAVEOUT, :LPWAVEHDR, :UINT>, 12
      @DefProto DllImport, waveOutPause, WIN_STD_CALL_CONV,, <:HWAVEOUT>, 4
      @DefProto DllImport, waveOutRestart, WIN_STD_CALL_CONV,, <:HWAVEOUT>, 4
      @DefProto DllImport, waveOutReset, WIN_STD_CALL_CONV,, <:HWAVEOUT>, 4
      @DefProto DllImport, waveOutBreakLoop, WIN_STD_CALL_CONV,, <:HWAVEOUT>, 4
      @DefProto DllImport, waveOutGetPosition, WIN_STD_CALL_CONV,, <:HWAVEOUT, :LPMMTIME, :UINT>, 12
      @DefProto DllImport, waveOutGetPitch, WIN_STD_CALL_CONV,, <:HWAVEOUT, :LPDWORD>, 8
      @DefProto DllImport, waveOutSetPitch, WIN_STD_CALL_CONV,, <:HWAVEOUT, :DWORD>, 8
      @DefProto DllImport, waveOutGetPlaybackRate, WIN_STD_CALL_CONV,, <:HWAVEOUT, :LPDWORD>, 8
      @DefProto DllImport, waveOutSetPlaybackRate, WIN_STD_CALL_CONV,, <:HWAVEOUT, :DWORD>, 8
      @DefProto DllImport, waveOutGetID, WIN_STD_CALL_CONV,, <:HWAVEOUT, :LPUINT>, 8
      if (WINVER ge 030ah)
        ifdef _WIN32
          @DefProto DllImport, waveOutMessage, WIN_STD_CALL_CONV,, <:HWAVEOUT, :UINT, :DWORD_PTR, :DWORD_PTR>, 16
        else
          ;[...]
        endif
        ;* ifdef WINVER >= 0x030a *
      endif
      @DefProto DllImport, waveInGetNumDevs, WIN_STD_CALL_CONV,, <>, 0
      ifdef _WIN32
        @DefProto DllImport, waveInGetDevCapsA, WIN_STD_CALL_CONV,, <:UINT_PTR, :LPWAVEINCAPSA, :UINT>, 12
        @DefProto DllImport, waveInGetDevCapsW, WIN_STD_CALL_CONV,, <:UINT_PTR, :LPWAVEINCAPSW, :UINT>, 12
        ifdef UNICODE
          waveInGetDevCaps equ <waveInGetDevCapsW>
        else
          waveInGetDevCaps equ <waveInGetDevCapsA>
        endif
        ; !UNICODE
      else
        ;[...]
      endif
      ifdef _WIN32
        @DefProto DllImport, waveInGetErrorTextA, WIN_STD_CALL_CONV,, <:MMRESULT, :LPSTR, :UINT>, 12
        @DefProto DllImport, waveInGetErrorTextW, WIN_STD_CALL_CONV,, <:MMRESULT, :LPWSTR, :UINT>, 12
        ifdef UNICODE
          waveInGetErrorText equ <waveInGetErrorTextW>
        else
          waveInGetErrorText equ <waveInGetErrorTextA>
        endif
        ; !UNICODE
      else
        ;[...]
      endif
      @DefProto DllImport, waveInOpen, WIN_STD_CALL_CONV,, <:LPHWAVEIN, :UINT, :LPCWAVEFORMATEX, :DWORD_PTR, :DWORD_PTR, :DWORD>, 24
      @DefProto DllImport, waveInClose, WIN_STD_CALL_CONV,, <:HWAVEIN>, 4
      @DefProto DllImport, waveInPrepareHeader, WIN_STD_CALL_CONV,, <:HWAVEIN, :LPWAVEHDR, :UINT>, 12
      @DefProto DllImport, waveInUnprepareHeader, WIN_STD_CALL_CONV,, <:HWAVEIN, :LPWAVEHDR, :UINT>, 12
      @DefProto DllImport, waveInAddBuffer, WIN_STD_CALL_CONV,, <:HWAVEIN, :LPWAVEHDR, :UINT>, 12
      @DefProto DllImport, waveInStart, WIN_STD_CALL_CONV,, <:HWAVEIN>, 4
      @DefProto DllImport, waveInStop, WIN_STD_CALL_CONV,, <:HWAVEIN>, 4
      @DefProto DllImport, waveInReset, WIN_STD_CALL_CONV,, <:HWAVEIN>, 4
      @DefProto DllImport, waveInGetPosition, WIN_STD_CALL_CONV,, <:HWAVEIN, :LPMMTIME, :UINT>, 12
      @DefProto DllImport, waveInGetID, WIN_STD_CALL_CONV,, <:HWAVEIN, :LPUINT>, 8
      if (WINVER ge 030ah)
        ifdef _WIN32
          @DefProto DllImport, waveInMessage, WIN_STD_CALL_CONV,, <:HWAVEIN, :UINT, :DWORD_PTR, :DWORD_PTR>, 16
        else
          ;[...]
        endif
        ;* ifdef WINVER >= 0x030a *
      endif
      ;* ifndef MMNOWAVE *
    endif
    ifndef MMNOMIDI
      ;****************************************************************************
      ;MIDI audio support
      ;****************************************************************************
      ;* MIDI error return values *
      ;* header not prepared *
      MIDIERR_UNPREPARED equ (MIDIERR_BASE + 0)
      ;* still something playing *
      MIDIERR_STILLPLAYING equ (MIDIERR_BASE + 1)
      ;* no configured instruments *
      MIDIERR_NOMAP equ (MIDIERR_BASE + 2)
      ;* hardware is still busy *
      MIDIERR_NOTREADY equ (MIDIERR_BASE + 3)
      ;* port no longer connected *
      MIDIERR_NODEVICE equ (MIDIERR_BASE + 4)
      ;* invalid MIF *
      MIDIERR_INVALIDSETUP equ (MIDIERR_BASE + 5)
      ;* operation unsupported w/ open mode *
      MIDIERR_BADOPENMODE equ (MIDIERR_BASE + 6)
      ;* thru device 'eating' a message *
      MIDIERR_DONT_CONTINUE equ (MIDIERR_BASE + 7)
      ;* last error in range *
      MIDIERR_LASTERROR equ (MIDIERR_BASE + 7)
      ;* MIDI audio data types *
      DECLARE_HANDLE HMIDI
      DECLARE_HANDLE HMIDIIN
      DECLARE_HANDLE HMIDIOUT
      DECLARE_HANDLE HMIDISTRM
      LPHMIDI typedef ptr HMIDI
      LPHMIDIIN typedef ptr HMIDIIN
      LPHMIDIOUT typedef ptr HMIDIOUT
      LPHMIDISTRM typedef ptr HMIDISTRM
      MIDICALLBACK typedef DRVCALLBACK
      LPMIDICALLBACK typedef ptr MIDICALLBACK
      MIDIPATCHSIZE equ 128
      PATCHARRAY struct
        WORD MIDIPATCHSIZE dup (?)
      PATCHARRAY ends
      LPPATCHARRAY typedef ptr WORD
      KEYARRAY struct
        WORD MIDIPATCHSIZE dup (?)
      KEYARRAY ends
      LPKEYARRAY typedef ptr WORD
      ;* MIDI callback messages *
      MIM_OPEN equ <MM_MIM_OPEN>
      MIM_CLOSE equ <MM_MIM_CLOSE>
      MIM_DATA equ <MM_MIM_DATA>
      MIM_LONGDATA equ <MM_MIM_LONGDATA>
      MIM_ERROR equ <MM_MIM_ERROR>
      MIM_LONGERROR equ <MM_MIM_LONGERROR>
      MOM_OPEN equ <MM_MOM_OPEN>
      MOM_CLOSE equ <MM_MOM_CLOSE>
      MOM_DONE equ <MM_MOM_DONE>
      if (WINVER ge 0400h)
        MIM_MOREDATA equ <MM_MIM_MOREDATA>
        MOM_POSITIONCB equ <MM_MOM_POSITIONCB>
        ;* WINVER >= 0x0400 *
      endif
      ;* device ID for MIDI mapper *
      MIDIMAPPER equ (- 1)
      MIDI_MAPPER equ (- 1)
      if (WINVER ge 0400h)
        ;* flags for dwFlags parm of midiInOpen() *
        MIDI_IO_STATUS equ 00000020h
        ;* WINVER >= 0x0400 *
      endif
      ;* flags for wFlags parm of midiOutCachePatches(), midiOutCacheDrumPatches() *
      MIDI_CACHE_ALL equ 1
      MIDI_CACHE_BESTFIT equ 2
      MIDI_CACHE_QUERY equ 3
      MIDI_UNCACHE equ 4
      ;* MIDI output device capabilities structure *
      ifdef _WIN32
        MIDIOUTCAPSA struct
          wMid WORD ?
          ;* manufacturer ID *
          wPid WORD ?
          ;* product ID *
          vDriverVersion MMVERSION ?
          ;* version of the driver *
          szPname SBYTE MAXPNAMELEN dup (?)
          ;* product name (NULL terminated string) *
          wTechnology WORD ?
          ;* type of device *
          wVoices WORD ?
          ;* # of voices (internal synth only) *
          wNotes WORD ?
          ;* max # of notes (internal synth only) *
          wChannelMask WORD ?
          ;* channels used (internal synth only) *
          dwSupport DWORD ?
          ;* functionality supported by driver *
        MIDIOUTCAPSA ends
        tagMIDIOUTCAPSA typedef MIDIOUTCAPSA
        PMIDIOUTCAPSA typedef ptr MIDIOUTCAPSA
        NPMIDIOUTCAPSA typedef ptr MIDIOUTCAPSA
        LPMIDIOUTCAPSA typedef ptr MIDIOUTCAPSA
        MIDIOUTCAPSW struct
          wMid WORD ?
          ;* manufacturer ID *
          wPid WORD ?
          ;* product ID *
          vDriverVersion MMVERSION ?
          ;* version of the driver *
          szPname WORD MAXPNAMELEN dup (?)
          ;* product name (NULL terminated string) *
          wTechnology WORD ?
          ;* type of device *
          wVoices WORD ?
          ;* # of voices (internal synth only) *
          wNotes WORD ?
          ;* max # of notes (internal synth only) *
          wChannelMask WORD ?
          ;* channels used (internal synth only) *
          dwSupport DWORD ?
          ;* functionality supported by driver *
        MIDIOUTCAPSW ends
        tagMIDIOUTCAPSW typedef MIDIOUTCAPSW
        PMIDIOUTCAPSW typedef ptr MIDIOUTCAPSW
        NPMIDIOUTCAPSW typedef ptr MIDIOUTCAPSW
        LPMIDIOUTCAPSW typedef ptr MIDIOUTCAPSW
        ifdef UNICODE
          MIDIOUTCAPS typedef MIDIOUTCAPSW
          PMIDIOUTCAPS typedef PMIDIOUTCAPSW
          NPMIDIOUTCAPS typedef NPMIDIOUTCAPSW
          LPMIDIOUTCAPS typedef LPMIDIOUTCAPSW
        else
          MIDIOUTCAPS typedef MIDIOUTCAPSA
          PMIDIOUTCAPS typedef PMIDIOUTCAPSA
          NPMIDIOUTCAPS typedef NPMIDIOUTCAPSA
          LPMIDIOUTCAPS typedef LPMIDIOUTCAPSA
        endif
        ; UNICODE
        MIDIOUTCAPS2A struct
          wMid WORD ?
          ;* manufacturer ID *
          wPid WORD ?
          ;* product ID *
          vDriverVersion MMVERSION ?
          ;* version of the driver *
          szPname SBYTE MAXPNAMELEN dup (?)
          ;* product name (NULL terminated string) *
          wTechnology WORD ?
          ;* type of device *
          wVoices WORD ?
          ;* # of voices (internal synth only) *
          wNotes WORD ?
          ;* max # of notes (internal synth only) *
          wChannelMask WORD ?
          ;* channels used (internal synth only) *
          dwSupport DWORD ?
          ;* functionality supported by driver *
          ManufacturerGuid GUID <>
          ;* for extensible MID mapping *
          ProductGuid GUID <>
          ;* for extensible PID mapping *
          NameGuid GUID <>
          ;* for name lookup in registry *
        MIDIOUTCAPS2A ends
        tagMIDIOUTCAPS2A typedef MIDIOUTCAPS2A
        PMIDIOUTCAPS2A typedef ptr MIDIOUTCAPS2A
        NPMIDIOUTCAPS2A typedef ptr MIDIOUTCAPS2A
        LPMIDIOUTCAPS2A typedef ptr MIDIOUTCAPS2A
        MIDIOUTCAPS2W struct
          wMid WORD ?
          ;* manufacturer ID *
          wPid WORD ?
          ;* product ID *
          vDriverVersion MMVERSION ?
          ;* version of the driver *
          szPname WORD MAXPNAMELEN dup (?)
          ;* product name (NULL terminated string) *
          wTechnology WORD ?
          ;* type of device *
          wVoices WORD ?
          ;* # of voices (internal synth only) *
          wNotes WORD ?
          ;* max # of notes (internal synth only) *
          wChannelMask WORD ?
          ;* channels used (internal synth only) *
          dwSupport DWORD ?
          ;* functionality supported by driver *
          ManufacturerGuid GUID <>
          ;* for extensible MID mapping *
          ProductGuid GUID <>
          ;* for extensible PID mapping *
          NameGuid GUID <>
          ;* for name lookup in registry *
        MIDIOUTCAPS2W ends
        tagMIDIOUTCAPS2W typedef MIDIOUTCAPS2W
        PMIDIOUTCAPS2W typedef ptr MIDIOUTCAPS2W
        NPMIDIOUTCAPS2W typedef ptr MIDIOUTCAPS2W
        LPMIDIOUTCAPS2W typedef ptr MIDIOUTCAPS2W
        ifdef UNICODE
          MIDIOUTCAPS2 typedef MIDIOUTCAPS2W
          PMIDIOUTCAPS2 typedef PMIDIOUTCAPS2W
          NPMIDIOUTCAPS2 typedef NPMIDIOUTCAPS2W
          LPMIDIOUTCAPS2 typedef LPMIDIOUTCAPS2W
        else
          MIDIOUTCAPS2 typedef MIDIOUTCAPS2A
          PMIDIOUTCAPS2 typedef PMIDIOUTCAPS2A
          NPMIDIOUTCAPS2 typedef NPMIDIOUTCAPS2A
          LPMIDIOUTCAPS2 typedef LPMIDIOUTCAPS2A
        endif
        ; UNICODE
      else
        ;[...]
      endif
      ;* flags for wTechnology field of MIDIOUTCAPS structure *
      ;* output port *
      MOD_MIDIPORT equ 1
      ;* generic internal synth *
      MOD_SYNTH equ 2
      ;* square wave internal synth *
      MOD_SQSYNTH equ 3
      ;* FM internal synth *
      MOD_FMSYNTH equ 4
      ;* MIDI mapper *
      MOD_MAPPER equ 5
      ;* hardware wavetable synth *
      MOD_WAVETABLE equ 6
      ;* software synth *
      MOD_SWSYNTH equ 7
      ;* flags for dwSupport field of MIDIOUTCAPS structure *
      ;* supports volume control *
      MIDICAPS_VOLUME equ 0001h
      ;* separate left-right volume control *
      MIDICAPS_LRVOLUME equ 0002h
      MIDICAPS_CACHE equ 0004h
      if (WINVER ge 0400h)
        ;* driver supports midiStreamOut directly *
        MIDICAPS_STREAM equ 0008h
        ;* WINVER >= 0x0400 *
      endif
      ;* MIDI input device capabilities structure *
      ifdef _WIN32
        MIDIINCAPSA struct
          wMid WORD ?
          ;* manufacturer ID *
          wPid WORD ?
          ;* product ID *
          vDriverVersion MMVERSION ?
          ;* version of the driver *
          szPname SBYTE MAXPNAMELEN dup (?)
          ;* product name (NULL terminated string) *
          if (WINVER ge 0400h)
            dwSupport DWORD ?
            ;* functionality supported by driver *
          endif
        MIDIINCAPSA ends
        tagMIDIINCAPSA typedef MIDIINCAPSA
        PMIDIINCAPSA typedef ptr MIDIINCAPSA
        NPMIDIINCAPSA typedef ptr MIDIINCAPSA
        LPMIDIINCAPSA typedef ptr MIDIINCAPSA
        MIDIINCAPSW struct
          wMid WORD ?
          ;* manufacturer ID *
          wPid WORD ?
          ;* product ID *
          vDriverVersion MMVERSION ?
          ;* version of the driver *
          szPname WORD MAXPNAMELEN dup (?)
          ;* product name (NULL terminated string) *
          if (WINVER ge 0400h)
            dwSupport DWORD ?
            ;* functionality supported by driver *
          endif
        MIDIINCAPSW ends
        tagMIDIINCAPSW typedef MIDIINCAPSW
        PMIDIINCAPSW typedef ptr MIDIINCAPSW
        NPMIDIINCAPSW typedef ptr MIDIINCAPSW
        LPMIDIINCAPSW typedef ptr MIDIINCAPSW
        ifdef UNICODE
          MIDIINCAPS typedef MIDIINCAPSW
          PMIDIINCAPS typedef PMIDIINCAPSW
          NPMIDIINCAPS typedef NPMIDIINCAPSW
          LPMIDIINCAPS typedef LPMIDIINCAPSW
        else
          MIDIINCAPS typedef MIDIINCAPSA
          PMIDIINCAPS typedef PMIDIINCAPSA
          NPMIDIINCAPS typedef NPMIDIINCAPSA
          LPMIDIINCAPS typedef LPMIDIINCAPSA
        endif
        ; UNICODE
        MIDIINCAPS2A struct
          wMid WORD ?
          ;* manufacturer ID *
          wPid WORD ?
          ;* product ID *
          vDriverVersion MMVERSION ?
          ;* version of the driver *
          szPname SBYTE MAXPNAMELEN dup (?)
          ;* product name (NULL terminated string) *
          if (WINVER ge 0400h)
            dwSupport DWORD ?
            ;* functionality supported by driver *
          endif
          ManufacturerGuid GUID <>
          ;* for extensible MID mapping *
          ProductGuid GUID <>
          ;* for extensible PID mapping *
          NameGuid GUID <>
          ;* for name lookup in registry *
        MIDIINCAPS2A ends
        tagMIDIINCAPS2A typedef MIDIINCAPS2A
        PMIDIINCAPS2A typedef ptr MIDIINCAPS2A
        NPMIDIINCAPS2A typedef ptr MIDIINCAPS2A
        LPMIDIINCAPS2A typedef ptr MIDIINCAPS2A
        MIDIINCAPS2W struct
          wMid WORD ?
          ;* manufacturer ID *
          wPid WORD ?
          ;* product ID *
          vDriverVersion MMVERSION ?
          ;* version of the driver *
          szPname WORD MAXPNAMELEN dup (?)
          ;* product name (NULL terminated string) *
          if (WINVER ge 0400h)
            dwSupport DWORD ?
            ;* functionality supported by driver *
          endif
          ManufacturerGuid GUID <>
          ;* for extensible MID mapping *
          ProductGuid GUID <>
          ;* for extensible PID mapping *
          NameGuid GUID <>
          ;* for name lookup in registry *
        MIDIINCAPS2W ends
        tagMIDIINCAPS2W typedef MIDIINCAPS2W
        PMIDIINCAPS2W typedef ptr MIDIINCAPS2W
        NPMIDIINCAPS2W typedef ptr MIDIINCAPS2W
        LPMIDIINCAPS2W typedef ptr MIDIINCAPS2W
        ifdef UNICODE
          MIDIINCAPS2 typedef MIDIINCAPS2W
          PMIDIINCAPS2 typedef PMIDIINCAPS2W
          NPMIDIINCAPS2 typedef NPMIDIINCAPS2W
          LPMIDIINCAPS2 typedef LPMIDIINCAPS2W
        else
          MIDIINCAPS2 typedef MIDIINCAPS2A
          PMIDIINCAPS2 typedef PMIDIINCAPS2A
          NPMIDIINCAPS2 typedef NPMIDIINCAPS2A
          LPMIDIINCAPS2 typedef LPMIDIINCAPS2A
        endif
        ; UNICODE
      else
        ;[...]
      endif
      ;* MIDI data block header *
      MIDIHDR struct
        lpData POINTER ?
        ;* pointer to locked data block *
        dwBufferLength DWORD ?
        ;* length of data in data block *
        dwBytesRecorded DWORD ?
        ;* used for input only *
        dwUser XWORD ?
        ;* for client's use *
        dwFlags DWORD ?
        ;* assorted flags (see defines) *
        lpNext POINTER ?
        ;* reserved for driver *
        reserved XWORD ?
        ;* reserved for driver *
        if (WINVER ge 0400h)
          dwOffset DWORD ?
          ;* Callback offset into buffer *
          dwReserved XWORD 8 dup (?)
          ;* Reserved for MMSYSTEM *
        endif
      MIDIHDR ends
      midihdr_tag typedef MIDIHDR
      PMIDIHDR typedef ptr MIDIHDR
      NPMIDIHDR typedef ptr MIDIHDR
      LPMIDIHDR typedef ptr MIDIHDR
      if (WINVER ge 0400h)
        MIDIEVENT struct
          dwDeltaTime DWORD ?
          ;* Ticks since last event *
          dwStreamID DWORD ?
          ;* Reserved; must be zero *
          dwEvent DWORD ?
          ;* Event type and parameters *
          dwParms DWORD 1 dup (?)
          ;* Parameters if this is a long event *
        MIDIEVENT ends
        midievent_tag typedef MIDIEVENT
        MIDISTRMBUFFVER struct
          dwVersion DWORD ?
          ;* Stream buffer format version *
          dwMid DWORD ?
          ;* Manufacturer ID as defined in MMREG.H *
          dwOEMVersion DWORD ?
          ;* Manufacturer version for custom ext *
        MIDISTRMBUFFVER ends
        midistrmbuffver_tag typedef MIDISTRMBUFFVER
        ;* WINVER >= 0x0400 *
      endif
      ;* flags for dwFlags field of MIDIHDR structure *
      ;* done bit *
      MHDR_DONE equ 00000001h
      ;* set if header prepared *
      MHDR_PREPARED equ 00000002h
      ;* reserved for driver *
      MHDR_INQUEUE equ 00000004h
      ;* Buffer is stream buffer *
      MHDR_ISSTRM equ 00000008h
      if (WINVER ge 0400h)
        ;* *
        ;* Type codes which go in the high byte of the event DWORD of a stream buffer *
        ;* *
        ;* Type codes 00-7F contain parameters within the low 24 bits *
        ;* Type codes 80-FF contain a length of their parameter in the low 24 *
        ;* bits, followed by their parameter data in the buffer. The event *
        ;* DWORD contains the exact byte length; the parm data itself must be *
        ;* padded to be an even multiple of 4 bytes long. *
        ;* *
        MEVT_F_SHORT equ 00000000h
        MEVT_F_LONG equ 80000000h
        MEVT_F_CALLBACK equ 40000000h
        MEVT_EVENTTYPE macro x
          exitm <((((x) shr 24) and 0FFh))>
        endm
        MEVT_EVENTPARM macro x
          exitm <(((x) and 00FFFFFFh))>
        endm
        ;* parm = shortmsg for midiOutShortMsg *
        MEVT_SHORTMSG equ (00h)
        ;* parm = new tempo in microsec/qn     *
        MEVT_TEMPO equ (01h)
        ;* parm = unused; does nothing         *
        MEVT_NOP equ (02h)
        ;* 0x04-0x7F reserved *
        ;* parm = bytes to send verbatim       *
        MEVT_LONGMSG equ (80h)
        ;* parm = comment data                 *
        MEVT_COMMENT equ (82h)
        ;* parm = MIDISTRMBUFFVER struct       *
        MEVT_VERSION equ (84h)
        ;* 0x81-0xFF reserved *
        MIDISTRM_ERROR equ (- 2)
        ;* *
        ;* Structures and defines for midiStreamProperty *
        ;* *
        MIDIPROP_SET equ 80000000h
        MIDIPROP_GET equ 40000000h
        ;* These are intentionally both non-zero so the app cannot accidentally *
        ;* leave the operation off and happen to appear to work due to default *
        ;* action. *
        MIDIPROP_TIMEDIV equ 00000001h
        MIDIPROP_TEMPO equ 00000002h
        MIDIPROPTIMEDIV struct
          cbStruct DWORD ?
          dwTimeDiv DWORD ?
        MIDIPROPTIMEDIV ends
        midiproptimediv_tag typedef MIDIPROPTIMEDIV
        LPMIDIPROPTIMEDIV typedef ptr MIDIPROPTIMEDIV
        MIDIPROPTEMPO struct
          cbStruct DWORD ?
          dwTempo DWORD ?
        MIDIPROPTEMPO ends
        midiproptempo_tag typedef MIDIPROPTEMPO
        LPMIDIPROPTEMPO typedef ptr MIDIPROPTEMPO
        ;* WINVER >= 0x0400 *
      endif
      ;* MIDI function prototypes *
      @DefProto DllImport, midiOutGetNumDevs, WIN_STD_CALL_CONV,, <>, 0
      if (WINVER ge 0400h)
        @DefProto DllImport, midiStreamOpen, WIN_STD_CALL_CONV,, <:LPHMIDISTRM, :LPUINT, :DWORD, :DWORD_PTR, :DWORD_PTR, :DWORD>, 24
        @DefProto DllImport, midiStreamClose, WIN_STD_CALL_CONV,, <:HMIDISTRM>, 4
        @DefProto DllImport, midiStreamProperty, WIN_STD_CALL_CONV,, <:HMIDISTRM, :LPBYTE, :DWORD>, 12
        @DefProto DllImport, midiStreamPosition, WIN_STD_CALL_CONV,, <:HMIDISTRM, :LPMMTIME, :UINT>, 12
        @DefProto DllImport, midiStreamOut, WIN_STD_CALL_CONV,, <:HMIDISTRM, :LPMIDIHDR, :UINT>, 12
        @DefProto DllImport, midiStreamPause, WIN_STD_CALL_CONV,, <:HMIDISTRM>, 4
        @DefProto DllImport, midiStreamRestart, WIN_STD_CALL_CONV,, <:HMIDISTRM>, 4
        @DefProto DllImport, midiStreamStop, WIN_STD_CALL_CONV,, <:HMIDISTRM>, 4
        ifdef _WIN32
          @DefProto DllImport, midiConnect, WIN_STD_CALL_CONV,, <:HMIDI, :HMIDIOUT, :LPVOID>, 12
          @DefProto DllImport, midiDisconnect, WIN_STD_CALL_CONV,, <:HMIDI, :HMIDIOUT, :LPVOID>, 12
        endif
        ;* WINVER >= 0x0400 *
      endif
      ifdef _WIN32
        @DefProto DllImport, midiOutGetDevCapsA, WIN_STD_CALL_CONV,, <:UINT_PTR, :LPMIDIOUTCAPSA, :UINT>, 12
        @DefProto DllImport, midiOutGetDevCapsW, WIN_STD_CALL_CONV,, <:UINT_PTR, :LPMIDIOUTCAPSW, :UINT>, 12
        ifdef UNICODE
          midiOutGetDevCaps equ <midiOutGetDevCapsW>
        else
          midiOutGetDevCaps equ <midiOutGetDevCapsA>
        endif
        ; !UNICODE
      else
        ;[...]
      endif
      if (WINVER ge 0400h)
        @DefProto DllImport, midiOutGetVolume, WIN_STD_CALL_CONV,, <:HMIDIOUT, :LPDWORD>, 8
        @DefProto DllImport, midiOutSetVolume, WIN_STD_CALL_CONV,, <:HMIDIOUT, :DWORD>, 8
      else
        @DefProto DllImport, midiOutGetVolume, WIN_STD_CALL_CONV,, <:UINT, :LPDWORD>, 8
        @DefProto DllImport, midiOutSetVolume, WIN_STD_CALL_CONV,, <:UINT, :DWORD>, 8
      endif
      ifdef _WIN32
        @DefProto DllImport, midiOutGetErrorTextA, WIN_STD_CALL_CONV,, <:MMRESULT, :LPSTR, :UINT>, 12
        @DefProto DllImport, midiOutGetErrorTextW, WIN_STD_CALL_CONV,, <:MMRESULT, :LPWSTR, :UINT>, 12
        ifdef UNICODE
          midiOutGetErrorText equ <midiOutGetErrorTextW>
        else
          midiOutGetErrorText equ <midiOutGetErrorTextA>
        endif
        ; !UNICODE
      else
        ;[...]
      endif
      @DefProto DllImport, midiOutOpen, WIN_STD_CALL_CONV,, <:LPHMIDIOUT, :UINT, :DWORD_PTR, :DWORD_PTR, :DWORD>, 20
      @DefProto DllImport, midiOutClose, WIN_STD_CALL_CONV,, <:HMIDIOUT>, 4
      @DefProto DllImport, midiOutPrepareHeader, WIN_STD_CALL_CONV,, <:HMIDIOUT, :LPMIDIHDR, :UINT>, 12
      @DefProto DllImport, midiOutUnprepareHeader, WIN_STD_CALL_CONV,, <:HMIDIOUT, :LPMIDIHDR, :UINT>, 12
      @DefProto DllImport, midiOutShortMsg, WIN_STD_CALL_CONV,, <:HMIDIOUT, :DWORD>, 8
      @DefProto DllImport, midiOutLongMsg, WIN_STD_CALL_CONV,, <:HMIDIOUT, :LPMIDIHDR, :UINT>, 12
      @DefProto DllImport, midiOutReset, WIN_STD_CALL_CONV,, <:HMIDIOUT>, 4
      @DefProto DllImport, midiOutCachePatches, WIN_STD_CALL_CONV,, <:HMIDIOUT, :UINT, :LPWORD, :UINT>, 16
      @DefProto DllImport, midiOutCacheDrumPatches, WIN_STD_CALL_CONV,, <:HMIDIOUT, :UINT, :LPWORD, :UINT>, 16
      @DefProto DllImport, midiOutGetID, WIN_STD_CALL_CONV,, <:HMIDIOUT, :LPUINT>, 8
      if (WINVER ge 030ah)
        ifdef _WIN32
          @DefProto DllImport, midiOutMessage, WIN_STD_CALL_CONV,, <:HMIDIOUT, :UINT, :DWORD_PTR, :DWORD_PTR>, 16
        else
          ;[...]
        endif
        ;* ifdef WINVER >= 0x030a *
      endif
      @DefProto DllImport, midiInGetNumDevs, WIN_STD_CALL_CONV,, <>, 0
      ifdef _WIN32
        @DefProto DllImport, midiInGetDevCapsA, WIN_STD_CALL_CONV,, <:UINT_PTR, :LPMIDIINCAPSA, :UINT>, 12
        @DefProto DllImport, midiInGetDevCapsW, WIN_STD_CALL_CONV,, <:UINT_PTR, :LPMIDIINCAPSW, :UINT>, 12
        ifdef UNICODE
          midiInGetDevCaps equ <midiInGetDevCapsW>
        else
          midiInGetDevCaps equ <midiInGetDevCapsA>
        endif
        ; !UNICODE
        @DefProto DllImport, midiInGetErrorTextA, WIN_STD_CALL_CONV,, <:MMRESULT, :LPSTR, :UINT>, 12
        @DefProto DllImport, midiInGetErrorTextW, WIN_STD_CALL_CONV,, <:MMRESULT, :LPWSTR, :UINT>, 12
        ifdef UNICODE
          midiInGetErrorText equ <midiInGetErrorTextW>
        else
          midiInGetErrorText equ <midiInGetErrorTextA>
        endif
        ; !UNICODE
      else
        ;[...]
      endif
      @DefProto DllImport, midiInOpen, WIN_STD_CALL_CONV,, <:LPHMIDIIN, :UINT, :DWORD_PTR, :DWORD_PTR, :DWORD>, 20
      @DefProto DllImport, midiInClose, WIN_STD_CALL_CONV,, <:HMIDIIN>, 4
      @DefProto DllImport, midiInPrepareHeader, WIN_STD_CALL_CONV,, <:HMIDIIN, :LPMIDIHDR, :UINT>, 12
      @DefProto DllImport, midiInUnprepareHeader, WIN_STD_CALL_CONV,, <:HMIDIIN, :LPMIDIHDR, :UINT>, 12
      @DefProto DllImport, midiInAddBuffer, WIN_STD_CALL_CONV,, <:HMIDIIN, :LPMIDIHDR, :UINT>, 12
      @DefProto DllImport, midiInStart, WIN_STD_CALL_CONV,, <:HMIDIIN>, 4
      @DefProto DllImport, midiInStop, WIN_STD_CALL_CONV,, <:HMIDIIN>, 4
      @DefProto DllImport, midiInReset, WIN_STD_CALL_CONV,, <:HMIDIIN>, 4
      @DefProto DllImport, midiInGetID, WIN_STD_CALL_CONV,, <:HMIDIIN, :LPUINT>, 8
      if (WINVER ge 030ah)
        ifdef _WIN32
          @DefProto DllImport, midiInMessage, WIN_STD_CALL_CONV,, <:HMIDIIN, :UINT, :DWORD_PTR, :DWORD_PTR>, 16
        else
          ;[...]
        endif
        ;* ifdef WINVER >= 0x030a *
      endif
      ;* ifndef MMNOMIDI *
    endif
    ifndef MMNOAUX
      ;****************************************************************************
      ;Auxiliary audio support
      ;****************************************************************************
      ;* device ID for aux device mapper *
      AUX_MAPPER equ (- 1)
      ;* Auxiliary audio device capabilities structure *
      ifdef _WIN32
        AUXCAPSA struct
          wMid WORD ?
          ;* manufacturer ID *
          wPid WORD ?
          ;* product ID *
          vDriverVersion MMVERSION ?
          ;* version of the driver *
          szPname SBYTE MAXPNAMELEN dup (?)
          ;* product name (NULL terminated string) *
          wTechnology WORD ?
          ;* type of device *
          wReserved1 WORD ?
          ;* padding *
          dwSupport DWORD ?
          ;* functionality supported by driver *
        AUXCAPSA ends
        tagAUXCAPSA typedef AUXCAPSA
        PAUXCAPSA typedef ptr AUXCAPSA
        NPAUXCAPSA typedef ptr AUXCAPSA
        LPAUXCAPSA typedef ptr AUXCAPSA
        AUXCAPSW struct
          wMid WORD ?
          ;* manufacturer ID *
          wPid WORD ?
          ;* product ID *
          vDriverVersion MMVERSION ?
          ;* version of the driver *
          szPname WORD MAXPNAMELEN dup (?)
          ;* product name (NULL terminated string) *
          wTechnology WORD ?
          ;* type of device *
          wReserved1 WORD ?
          ;* padding *
          dwSupport DWORD ?
          ;* functionality supported by driver *
        AUXCAPSW ends
        tagAUXCAPSW typedef AUXCAPSW
        PAUXCAPSW typedef ptr AUXCAPSW
        NPAUXCAPSW typedef ptr AUXCAPSW
        LPAUXCAPSW typedef ptr AUXCAPSW
        ifdef UNICODE
          AUXCAPS typedef AUXCAPSW
          PAUXCAPS typedef PAUXCAPSW
          NPAUXCAPS typedef NPAUXCAPSW
          LPAUXCAPS typedef LPAUXCAPSW
        else
          AUXCAPS typedef AUXCAPSA
          PAUXCAPS typedef PAUXCAPSA
          NPAUXCAPS typedef NPAUXCAPSA
          LPAUXCAPS typedef LPAUXCAPSA
        endif
        ; UNICODE
        AUXCAPS2A struct
          wMid WORD ?
          ;* manufacturer ID *
          wPid WORD ?
          ;* product ID *
          vDriverVersion MMVERSION ?
          ;* version of the driver *
          szPname SBYTE MAXPNAMELEN dup (?)
          ;* product name (NULL terminated string) *
          wTechnology WORD ?
          ;* type of device *
          wReserved1 WORD ?
          ;* padding *
          dwSupport DWORD ?
          ;* functionality supported by driver *
          ManufacturerGuid GUID <>
          ;* for extensible MID mapping *
          ProductGuid GUID <>
          ;* for extensible PID mapping *
          NameGuid GUID <>
          ;* for name lookup in registry *
        AUXCAPS2A ends
        tagAUXCAPS2A typedef AUXCAPS2A
        PAUXCAPS2A typedef ptr AUXCAPS2A
        NPAUXCAPS2A typedef ptr AUXCAPS2A
        LPAUXCAPS2A typedef ptr AUXCAPS2A
        AUXCAPS2W struct
          wMid WORD ?
          ;* manufacturer ID *
          wPid WORD ?
          ;* product ID *
          vDriverVersion MMVERSION ?
          ;* version of the driver *
          szPname WORD MAXPNAMELEN dup (?)
          ;* product name (NULL terminated string) *
          wTechnology WORD ?
          ;* type of device *
          wReserved1 WORD ?
          ;* padding *
          dwSupport DWORD ?
          ;* functionality supported by driver *
          ManufacturerGuid GUID <>
          ;* for extensible MID mapping *
          ProductGuid GUID <>
          ;* for extensible PID mapping *
          NameGuid GUID <>
          ;* for name lookup in registry *
        AUXCAPS2W ends
        tagAUXCAPS2W typedef AUXCAPS2W
        PAUXCAPS2W typedef ptr AUXCAPS2W
        NPAUXCAPS2W typedef ptr AUXCAPS2W
        LPAUXCAPS2W typedef ptr AUXCAPS2W
        ifdef UNICODE
          AUXCAPS2 typedef AUXCAPS2W
          PAUXCAPS2 typedef PAUXCAPS2W
          NPAUXCAPS2 typedef NPAUXCAPS2W
          LPAUXCAPS2 typedef LPAUXCAPS2W
        else
          AUXCAPS2 typedef AUXCAPS2A
          PAUXCAPS2 typedef PAUXCAPS2A
          NPAUXCAPS2 typedef NPAUXCAPS2A
          LPAUXCAPS2 typedef LPAUXCAPS2A
        endif
        ; UNICODE
      else
        ;[...]
      endif
      ;* flags for wTechnology field in AUXCAPS structure *
      ;* audio from internal CD-ROM drive *
      AUXCAPS_CDAUDIO equ 1
      ;* audio from auxiliary input jacks *
      AUXCAPS_AUXIN equ 2
      ;* flags for dwSupport field in AUXCAPS structure *
      ;* supports volume control *
      AUXCAPS_VOLUME equ 0001h
      ;* separate left-right volume control *
      AUXCAPS_LRVOLUME equ 0002h
      ;* auxiliary audio function prototypes *
      @DefProto DllImport, auxGetNumDevs, WIN_STD_CALL_CONV,, <>, 0
      ifdef _WIN32
        @DefProto DllImport, auxGetDevCapsA, WIN_STD_CALL_CONV,, <:UINT_PTR, :LPAUXCAPSA, :UINT>, 12
        @DefProto DllImport, auxGetDevCapsW, WIN_STD_CALL_CONV,, <:UINT_PTR, :LPAUXCAPSW, :UINT>, 12
        ifdef UNICODE
          auxGetDevCaps equ <auxGetDevCapsW>
        else
          auxGetDevCaps equ <auxGetDevCapsA>
        endif
        ; !UNICODE
      else
        ;[...]
      endif
      @DefProto DllImport, auxSetVolume, WIN_STD_CALL_CONV,, <:UINT, :DWORD>, 8
      @DefProto DllImport, auxGetVolume, WIN_STD_CALL_CONV,, <:UINT, :LPDWORD>, 8
      if (WINVER ge 030ah)
        ifdef _WIN32
          @DefProto DllImport, auxOutMessage, WIN_STD_CALL_CONV,, <:UINT, :UINT, :DWORD_PTR, :DWORD_PTR>, 16
        else
          ;[...]
        endif
        ;* ifdef WINVER >= 0x030a *
      endif
      ;* ifndef MMNOAUX *
    endif
    ifndef MMNOMIXER
      ;****************************************************************************
      ;Mixer Support
      ;****************************************************************************
      DECLARE_HANDLE HMIXEROBJ
      LPHMIXEROBJ typedef ptr HMIXEROBJ
      DECLARE_HANDLE HMIXER
      LPHMIXER typedef ptr HMIXER
      MIXER_SHORT_NAME_CHARS equ 16
      MIXER_LONG_NAME_CHARS equ 64
      ;* *
      ;*  MMRESULT error return values specific to the mixer API *
      ;* *
      ;* *
      MIXERR_INVALLINE equ (MIXERR_BASE + 0)
      MIXERR_INVALCONTROL equ (MIXERR_BASE + 1)
      MIXERR_INVALVALUE equ (MIXERR_BASE + 2)
      MIXERR_LASTERROR equ (MIXERR_BASE + 2)
      MIXER_OBJECTF_HANDLE equ 80000000h
      MIXER_OBJECTF_MIXER equ 00000000h
      MIXER_OBJECTF_HMIXER equ <(MIXER_OBJECTF_HANDLE or MIXER_OBJECTF_MIXER)>
      MIXER_OBJECTF_WAVEOUT equ 10000000h
      MIXER_OBJECTF_HWAVEOUT equ <(MIXER_OBJECTF_HANDLE or MIXER_OBJECTF_WAVEOUT)>
      MIXER_OBJECTF_WAVEIN equ 20000000h
      MIXER_OBJECTF_HWAVEIN equ <(MIXER_OBJECTF_HANDLE or MIXER_OBJECTF_WAVEIN)>
      MIXER_OBJECTF_MIDIOUT equ 30000000h
      MIXER_OBJECTF_HMIDIOUT equ <(MIXER_OBJECTF_HANDLE or MIXER_OBJECTF_MIDIOUT)>
      MIXER_OBJECTF_MIDIIN equ 40000000h
      MIXER_OBJECTF_HMIDIIN equ <(MIXER_OBJECTF_HANDLE or MIXER_OBJECTF_MIDIIN)>
      MIXER_OBJECTF_AUX equ 50000000h
      @DefProto DllImport, mixerGetNumDevs, WIN_STD_CALL_CONV,, <>, 0
      ifdef _WIN32
        MIXERCAPSA struct
          wMid WORD ?
          ;* manufacturer id *
          wPid WORD ?
          ;* product id *
          vDriverVersion MMVERSION ?
          ;* version of the driver *
          szPname SBYTE MAXPNAMELEN dup (?)
          ;* product name *
          fdwSupport DWORD ?
          ;* misc. support bits *
          cDestinations DWORD ?
          ;* count of destinations *
        MIXERCAPSA ends
        tagMIXERCAPSA typedef MIXERCAPSA
        PMIXERCAPSA typedef ptr MIXERCAPSA
        LPMIXERCAPSA typedef ptr MIXERCAPSA
        MIXERCAPSW struct
          wMid WORD ?
          ;* manufacturer id *
          wPid WORD ?
          ;* product id *
          vDriverVersion MMVERSION ?
          ;* version of the driver *
          szPname WORD MAXPNAMELEN dup (?)
          ;* product name *
          fdwSupport DWORD ?
          ;* misc. support bits *
          cDestinations DWORD ?
          ;* count of destinations *
        MIXERCAPSW ends
        tagMIXERCAPSW typedef MIXERCAPSW
        PMIXERCAPSW typedef ptr MIXERCAPSW
        LPMIXERCAPSW typedef ptr MIXERCAPSW
        ifdef UNICODE
          MIXERCAPS typedef MIXERCAPSW
          PMIXERCAPS typedef PMIXERCAPSW
          LPMIXERCAPS typedef LPMIXERCAPSW
        else
          MIXERCAPS typedef MIXERCAPSA
          PMIXERCAPS typedef PMIXERCAPSA
          LPMIXERCAPS typedef LPMIXERCAPSA
        endif
        ; UNICODE
        MIXERCAPS2A struct
          wMid WORD ?
          ;* manufacturer id *
          wPid WORD ?
          ;* product id *
          vDriverVersion MMVERSION ?
          ;* version of the driver *
          szPname SBYTE MAXPNAMELEN dup (?)
          ;* product name *
          fdwSupport DWORD ?
          ;* misc. support bits *
          cDestinations DWORD ?
          ;* count of destinations *
          ManufacturerGuid GUID <>
          ;* for extensible MID mapping *
          ProductGuid GUID <>
          ;* for extensible PID mapping *
          NameGuid GUID <>
          ;* for name lookup in registry *
        MIXERCAPS2A ends
        tagMIXERCAPS2A typedef MIXERCAPS2A
        PMIXERCAPS2A typedef ptr MIXERCAPS2A
        LPMIXERCAPS2A typedef ptr MIXERCAPS2A
        MIXERCAPS2W struct
          wMid WORD ?
          ;* manufacturer id *
          wPid WORD ?
          ;* product id *
          vDriverVersion MMVERSION ?
          ;* version of the driver *
          szPname WORD MAXPNAMELEN dup (?)
          ;* product name *
          fdwSupport DWORD ?
          ;* misc. support bits *
          cDestinations DWORD ?
          ;* count of destinations *
          ManufacturerGuid GUID <>
          ;* for extensible MID mapping *
          ProductGuid GUID <>
          ;* for extensible PID mapping *
          NameGuid GUID <>
          ;* for name lookup in registry *
        MIXERCAPS2W ends
        tagMIXERCAPS2W typedef MIXERCAPS2W
        PMIXERCAPS2W typedef ptr MIXERCAPS2W
        LPMIXERCAPS2W typedef ptr MIXERCAPS2W
        ifdef UNICODE
          MIXERCAPS2 typedef MIXERCAPS2W
          PMIXERCAPS2 typedef PMIXERCAPS2W
          LPMIXERCAPS2 typedef LPMIXERCAPS2W
        else
          MIXERCAPS2 typedef MIXERCAPS2A
          PMIXERCAPS2 typedef PMIXERCAPS2A
          LPMIXERCAPS2 typedef LPMIXERCAPS2A
        endif
        ; UNICODE
      else
        ;[...]
      endif
      ifdef _WIN32
        @DefProto DllImport, mixerGetDevCapsA, WIN_STD_CALL_CONV,, <:UINT_PTR, :LPMIXERCAPSA, :UINT>, 12
        @DefProto DllImport, mixerGetDevCapsW, WIN_STD_CALL_CONV,, <:UINT_PTR, :LPMIXERCAPSW, :UINT>, 12
        ifdef UNICODE
          mixerGetDevCaps equ <mixerGetDevCapsW>
        else
          mixerGetDevCaps equ <mixerGetDevCapsA>
        endif
        ; !UNICODE
      else
        ;[...]
      endif
      @DefProto DllImport, mixerOpen, WIN_STD_CALL_CONV,, <:LPHMIXER, :UINT, :DWORD_PTR, :DWORD_PTR, :DWORD>, 20
      @DefProto DllImport, mixerClose, WIN_STD_CALL_CONV,, <:HMIXER>, 4
      @DefProto DllImport, mixerMessage, WIN_STD_CALL_CONV,, <:HMIXER, :UINT, :DWORD_PTR, :DWORD_PTR>, 16
      ifdef _WIN32
        MIXERLINEA struct
          cbStruct DWORD ?
          ;* size of MIXERLINE structure *
          dwDestination DWORD ?
          ;* zero based destination index *
          dwSource DWORD ?
          ;* zero based source index (if source) *
          dwLineID DWORD ?
          ;* unique line id for mixer device *
          fdwLine DWORD ?
          ;* state/information about line *
          dwUser XWORD ?
          ;* driver specific information *
          dwComponentType DWORD ?
          ;* component type line connects to *
          cChannels DWORD ?
          ;* number of channels line supports *
          cConnections DWORD ?
          ;* number of connections [possible] *
          cControls DWORD ?
          ;* number of controls at this line *
          szShortName SBYTE MIXER_SHORT_NAME_CHARS dup (?)
          szName SBYTE MIXER_LONG_NAME_CHARS dup (?)
          struct Target
            dwType DWORD ?
            ;* MIXERLINE_TARGETTYPE_xxxx *
            dwDeviceID DWORD ?
            ;* target device ID of device type *
            wMid WORD ?
            ;* of target device *
            wPid WORD ?
            ;*      " *
            vDriverVersion MMVERSION ?
            ;*      " *
            szPname SBYTE MAXPNAMELEN dup (?)
            ;*      " *
          ends
        MIXERLINEA ends
        tagMIXERLINEA typedef MIXERLINEA
        PMIXERLINEA typedef ptr MIXERLINEA
        LPMIXERLINEA typedef ptr MIXERLINEA
        MIXERLINEW struct
          cbStruct DWORD ?
          ;* size of MIXERLINE structure *
          dwDestination DWORD ?
          ;* zero based destination index *
          dwSource DWORD ?
          ;* zero based source index (if source) *
          dwLineID DWORD ?
          ;* unique line id for mixer device *
          fdwLine DWORD ?
          ;* state/information about line *
          dwUser XWORD ?
          ;* driver specific information *
          dwComponentType DWORD ?
          ;* component type line connects to *
          cChannels DWORD ?
          ;* number of channels line supports *
          cConnections DWORD ?
          ;* number of connections [possible] *
          cControls DWORD ?
          ;* number of controls at this line *
          szShortName WORD MIXER_SHORT_NAME_CHARS dup (?)
          szName WORD MIXER_LONG_NAME_CHARS dup (?)
          struct Target
            dwType DWORD ?
            ;* MIXERLINE_TARGETTYPE_xxxx *
            dwDeviceID DWORD ?
            ;* target device ID of device type *
            wMid WORD ?
            ;* of target device *
            wPid WORD ?
            ;*      " *
            vDriverVersion MMVERSION ?
            ;*      " *
            szPname WORD MAXPNAMELEN dup (?)
            ;*      " *
          ends
        MIXERLINEW ends
        tagMIXERLINEW typedef MIXERLINEW
        PMIXERLINEW typedef ptr MIXERLINEW
        LPMIXERLINEW typedef ptr MIXERLINEW
        ifdef UNICODE
          MIXERLINE typedef MIXERLINEW
          PMIXERLINE typedef PMIXERLINEW
          LPMIXERLINE typedef LPMIXERLINEW
        else
          MIXERLINE typedef MIXERLINEA
          PMIXERLINE typedef PMIXERLINEA
          LPMIXERLINE typedef LPMIXERLINEA
        endif
        ; UNICODE
      else
        ;[...]
      endif
      ;* *
      ;*  MIXERLINE.fdwLine *
      ;* *
      ;* *
      MIXERLINE_LINEF_ACTIVE equ 00000001h
      MIXERLINE_LINEF_DISCONNECTED equ 00008000h
      MIXERLINE_LINEF_SOURCE equ 80000000h
      ;* *
      ;*  MIXERLINE.dwComponentType *
      ;* *
      ;*  component types for destinations and sources *
      ;* *
      ;* *
      MIXERLINE_COMPONENTTYPE_DST_FIRST equ 00000000h
      MIXERLINE_COMPONENTTYPE_DST_UNDEFINED equ (MIXERLINE_COMPONENTTYPE_DST_FIRST + 0)
      MIXERLINE_COMPONENTTYPE_DST_DIGITAL equ (MIXERLINE_COMPONENTTYPE_DST_FIRST + 1)
      MIXERLINE_COMPONENTTYPE_DST_LINE equ (MIXERLINE_COMPONENTTYPE_DST_FIRST + 2)
      MIXERLINE_COMPONENTTYPE_DST_MONITOR equ (MIXERLINE_COMPONENTTYPE_DST_FIRST + 3)
      MIXERLINE_COMPONENTTYPE_DST_SPEAKERS equ (MIXERLINE_COMPONENTTYPE_DST_FIRST + 4)
      MIXERLINE_COMPONENTTYPE_DST_HEADPHONES equ (MIXERLINE_COMPONENTTYPE_DST_FIRST + 5)
      MIXERLINE_COMPONENTTYPE_DST_TELEPHONE equ (MIXERLINE_COMPONENTTYPE_DST_FIRST + 6)
      MIXERLINE_COMPONENTTYPE_DST_WAVEIN equ (MIXERLINE_COMPONENTTYPE_DST_FIRST + 7)
      MIXERLINE_COMPONENTTYPE_DST_VOICEIN equ (MIXERLINE_COMPONENTTYPE_DST_FIRST + 8)
      MIXERLINE_COMPONENTTYPE_DST_LAST equ (MIXERLINE_COMPONENTTYPE_DST_FIRST + 8)
      MIXERLINE_COMPONENTTYPE_SRC_FIRST equ 00001000h
      MIXERLINE_COMPONENTTYPE_SRC_UNDEFINED equ (MIXERLINE_COMPONENTTYPE_SRC_FIRST + 0)
      MIXERLINE_COMPONENTTYPE_SRC_DIGITAL equ (MIXERLINE_COMPONENTTYPE_SRC_FIRST + 1)
      MIXERLINE_COMPONENTTYPE_SRC_LINE equ (MIXERLINE_COMPONENTTYPE_SRC_FIRST + 2)
      MIXERLINE_COMPONENTTYPE_SRC_MICROPHONE equ (MIXERLINE_COMPONENTTYPE_SRC_FIRST + 3)
      MIXERLINE_COMPONENTTYPE_SRC_SYNTHESIZER equ (MIXERLINE_COMPONENTTYPE_SRC_FIRST + 4)
      MIXERLINE_COMPONENTTYPE_SRC_COMPACTDISC equ (MIXERLINE_COMPONENTTYPE_SRC_FIRST + 5)
      MIXERLINE_COMPONENTTYPE_SRC_TELEPHONE equ (MIXERLINE_COMPONENTTYPE_SRC_FIRST + 6)
      MIXERLINE_COMPONENTTYPE_SRC_PCSPEAKER equ (MIXERLINE_COMPONENTTYPE_SRC_FIRST + 7)
      MIXERLINE_COMPONENTTYPE_SRC_WAVEOUT equ (MIXERLINE_COMPONENTTYPE_SRC_FIRST + 8)
      MIXERLINE_COMPONENTTYPE_SRC_AUXILIARY equ (MIXERLINE_COMPONENTTYPE_SRC_FIRST + 9)
      MIXERLINE_COMPONENTTYPE_SRC_ANALOG equ (MIXERLINE_COMPONENTTYPE_SRC_FIRST + 10)
      MIXERLINE_COMPONENTTYPE_SRC_LAST equ (MIXERLINE_COMPONENTTYPE_SRC_FIRST + 10)
      ;* *
      ;*  MIXERLINE.Target.dwType *
      ;* *
      ;* *
      MIXERLINE_TARGETTYPE_UNDEFINED equ 0
      MIXERLINE_TARGETTYPE_WAVEOUT equ 1
      MIXERLINE_TARGETTYPE_WAVEIN equ 2
      MIXERLINE_TARGETTYPE_MIDIOUT equ 3
      MIXERLINE_TARGETTYPE_MIDIIN equ 4
      MIXERLINE_TARGETTYPE_AUX equ 5
      ifdef _WIN32
        @DefProto DllImport, mixerGetLineInfoA, WIN_STD_CALL_CONV,, <:HMIXEROBJ, :LPMIXERLINEA, :DWORD>, 12
        @DefProto DllImport, mixerGetLineInfoW, WIN_STD_CALL_CONV,, <:HMIXEROBJ, :LPMIXERLINEW, :DWORD>, 12
        ifdef UNICODE
          mixerGetLineInfo equ <mixerGetLineInfoW>
        else
          mixerGetLineInfo equ <mixerGetLineInfoA>
        endif
        ; !UNICODE
      else
        ;[...]
      endif
      MIXER_GETLINEINFOF_DESTINATION equ 00000000h
      MIXER_GETLINEINFOF_SOURCE equ 00000001h
      MIXER_GETLINEINFOF_LINEID equ 00000002h
      MIXER_GETLINEINFOF_COMPONENTTYPE equ 00000003h
      MIXER_GETLINEINFOF_TARGETTYPE equ 00000004h
      MIXER_GETLINEINFOF_QUERYMASK equ 0000000Fh
      @DefProto DllImport, mixerGetID, WIN_STD_CALL_CONV,, <:HMIXEROBJ, :ptr UINT, :DWORD>, 12
      ;* *
      ;*  MIXERCONTROL *
      ;* *
      ;* *
      ifdef _WIN32
        MIXERCONTROLA struct
          cbStruct DWORD ?
          ;* size in bytes of MIXERCONTROL *
          dwControlID DWORD ?
          ;* unique control id for mixer device *
          dwControlType DWORD ?
          ;* MIXERCONTROL_CONTROLTYPE_xxx *
          fdwControl DWORD ?
          ;* MIXERCONTROL_CONTROLF_xxx *
          cMultipleItems DWORD ?
          ;* if MIXERCONTROL_CONTROLF_MULTIPLE set *
          szShortName SBYTE MIXER_SHORT_NAME_CHARS dup (?)
          szName SBYTE MIXER_LONG_NAME_CHARS dup (?)
          union Bounds
            struct
              lMinimum SDWORD ?
              ;* signed minimum for this control *
              lMaximum SDWORD ?
              ;* signed maximum for this control *
            ends
            struct
              dwMinimum DWORD ?
              ;* unsigned minimum for this control *
              dwMaximum DWORD ?
              ;* unsigned maximum for this control *
            ends
            dwReserved DWORD 6 dup (?)
          ends
          union Metrics
            cSteps DWORD ?
            ;* # of steps between min & max *
            cbCustomData DWORD ?
            ;* size in bytes of custom data *
            dwReserved DWORD 6 dup (?)
            ;* !!! needed? we have cbStruct.... *
          ends
        MIXERCONTROLA ends
        tagMIXERCONTROLA typedef MIXERCONTROLA
        PMIXERCONTROLA typedef ptr MIXERCONTROLA
        LPMIXERCONTROLA typedef ptr MIXERCONTROLA
        MIXERCONTROLW struct
          cbStruct DWORD ?
          ;* size in bytes of MIXERCONTROL *
          dwControlID DWORD ?
          ;* unique control id for mixer device *
          dwControlType DWORD ?
          ;* MIXERCONTROL_CONTROLTYPE_xxx *
          fdwControl DWORD ?
          ;* MIXERCONTROL_CONTROLF_xxx *
          cMultipleItems DWORD ?
          ;* if MIXERCONTROL_CONTROLF_MULTIPLE set *
          szShortName WORD MIXER_SHORT_NAME_CHARS dup (?)
          szName WORD MIXER_LONG_NAME_CHARS dup (?)
          union Bounds
            struct
              lMinimum SDWORD ?
              ;* signed minimum for this control *
              lMaximum SDWORD ?
              ;* signed maximum for this control *
            ends
            struct
              dwMinimum DWORD ?
              ;* unsigned minimum for this control *
              dwMaximum DWORD ?
              ;* unsigned maximum for this control *
            ends
            dwReserved DWORD 6 dup (?)
          ends
          union Metrics
            cSteps DWORD ?
            ;* # of steps between min & max *
            cbCustomData DWORD ?
            ;* size in bytes of custom data *
            dwReserved DWORD 6 dup (?)
            ;* !!! needed? we have cbStruct.... *
          ends
        MIXERCONTROLW ends
        tagMIXERCONTROLW typedef MIXERCONTROLW
        PMIXERCONTROLW typedef ptr MIXERCONTROLW
        LPMIXERCONTROLW typedef ptr MIXERCONTROLW
        ifdef UNICODE
          MIXERCONTROL typedef MIXERCONTROLW
          PMIXERCONTROL typedef PMIXERCONTROLW
          LPMIXERCONTROL typedef LPMIXERCONTROLW
        else
          MIXERCONTROL typedef MIXERCONTROLA
          PMIXERCONTROL typedef PMIXERCONTROLA
          LPMIXERCONTROL typedef LPMIXERCONTROLA
        endif
        ; UNICODE
      else
        ;[...]
      endif
      ;* *
      ;*  MIXERCONTROL.fdwControl *
      ;* *
      ;* *
      MIXERCONTROL_CONTROLF_UNIFORM equ 00000001h
      MIXERCONTROL_CONTROLF_MULTIPLE equ 00000002h
      MIXERCONTROL_CONTROLF_DISABLED equ 80000000h
      ;* *
      ;*  MIXERCONTROL_CONTROLTYPE_xxx building block defines *
      ;* *
      ;* *
      MIXERCONTROL_CT_CLASS_MASK equ 0F0000000h
      MIXERCONTROL_CT_CLASS_CUSTOM equ 00000000h
      MIXERCONTROL_CT_CLASS_METER equ 10000000h
      MIXERCONTROL_CT_CLASS_SWITCH equ 20000000h
      MIXERCONTROL_CT_CLASS_NUMBER equ 30000000h
      MIXERCONTROL_CT_CLASS_SLIDER equ 40000000h
      MIXERCONTROL_CT_CLASS_FADER equ 50000000h
      MIXERCONTROL_CT_CLASS_TIME equ 60000000h
      MIXERCONTROL_CT_CLASS_LIST equ 70000000h
      MIXERCONTROL_CT_SUBCLASS_MASK equ 0F000000h
      MIXERCONTROL_CT_SC_SWITCH_BOOLEAN equ 00000000h
      MIXERCONTROL_CT_SC_SWITCH_BUTTON equ 01000000h
      MIXERCONTROL_CT_SC_METER_POLLED equ 00000000h
      MIXERCONTROL_CT_SC_TIME_MICROSECS equ 00000000h
      MIXERCONTROL_CT_SC_TIME_MILLISECS equ 01000000h
      MIXERCONTROL_CT_SC_LIST_SINGLE equ 00000000h
      MIXERCONTROL_CT_SC_LIST_MULTIPLE equ 01000000h
      MIXERCONTROL_CT_UNITS_MASK equ 00FF0000h
      MIXERCONTROL_CT_UNITS_CUSTOM equ 00000000h
      MIXERCONTROL_CT_UNITS_BOOLEAN equ 00010000h
      MIXERCONTROL_CT_UNITS_SIGNED equ 00020000h
      MIXERCONTROL_CT_UNITS_UNSIGNED equ 00030000h
      ;* in 10ths *
      MIXERCONTROL_CT_UNITS_DECIBELS equ 00040000h
      ;* in 10ths *
      MIXERCONTROL_CT_UNITS_PERCENT equ 00050000h
      ;* *
      ;*  Commonly used control types for specifying MIXERCONTROL.dwControlType *
      ;* *
      MIXERCONTROL_CONTROLTYPE_CUSTOM equ <(MIXERCONTROL_CT_CLASS_CUSTOM or MIXERCONTROL_CT_UNITS_CUSTOM)>
      MIXERCONTROL_CONTROLTYPE_BOOLEANMETER equ <(MIXERCONTROL_CT_CLASS_METER or MIXERCONTROL_CT_SC_METER_POLLED or MIXERCONTROL_CT_UNITS_BOOLEAN)>
      MIXERCONTROL_CONTROLTYPE_SIGNEDMETER equ <(MIXERCONTROL_CT_CLASS_METER or MIXERCONTROL_CT_SC_METER_POLLED or MIXERCONTROL_CT_UNITS_SIGNED)>
      MIXERCONTROL_CONTROLTYPE_PEAKMETER equ (MIXERCONTROL_CONTROLTYPE_SIGNEDMETER + 1)
      MIXERCONTROL_CONTROLTYPE_UNSIGNEDMETER equ <(MIXERCONTROL_CT_CLASS_METER or MIXERCONTROL_CT_SC_METER_POLLED or MIXERCONTROL_CT_UNITS_UNSIGNED)>
      MIXERCONTROL_CONTROLTYPE_BOOLEAN equ <(MIXERCONTROL_CT_CLASS_SWITCH or MIXERCONTROL_CT_SC_SWITCH_BOOLEAN or MIXERCONTROL_CT_UNITS_BOOLEAN)>
      MIXERCONTROL_CONTROLTYPE_ONOFF equ (MIXERCONTROL_CONTROLTYPE_BOOLEAN + 1)
      MIXERCONTROL_CONTROLTYPE_MUTE equ (MIXERCONTROL_CONTROLTYPE_BOOLEAN + 2)
      MIXERCONTROL_CONTROLTYPE_MONO equ (MIXERCONTROL_CONTROLTYPE_BOOLEAN + 3)
      MIXERCONTROL_CONTROLTYPE_LOUDNESS equ (MIXERCONTROL_CONTROLTYPE_BOOLEAN + 4)
      MIXERCONTROL_CONTROLTYPE_STEREOENH equ (MIXERCONTROL_CONTROLTYPE_BOOLEAN + 5)
      MIXERCONTROL_CONTROLTYPE_BASS_BOOST equ (MIXERCONTROL_CONTROLTYPE_BOOLEAN + 00002277h)
      MIXERCONTROL_CONTROLTYPE_BUTTON equ <(MIXERCONTROL_CT_CLASS_SWITCH or MIXERCONTROL_CT_SC_SWITCH_BUTTON or MIXERCONTROL_CT_UNITS_BOOLEAN)>
      MIXERCONTROL_CONTROLTYPE_DECIBELS equ <(MIXERCONTROL_CT_CLASS_NUMBER or MIXERCONTROL_CT_UNITS_DECIBELS)>
      MIXERCONTROL_CONTROLTYPE_SIGNED equ <(MIXERCONTROL_CT_CLASS_NUMBER or MIXERCONTROL_CT_UNITS_SIGNED)>
      MIXERCONTROL_CONTROLTYPE_UNSIGNED equ <(MIXERCONTROL_CT_CLASS_NUMBER or MIXERCONTROL_CT_UNITS_UNSIGNED)>
      MIXERCONTROL_CONTROLTYPE_PERCENT equ <(MIXERCONTROL_CT_CLASS_NUMBER or MIXERCONTROL_CT_UNITS_PERCENT)>
      MIXERCONTROL_CONTROLTYPE_SLIDER equ <(MIXERCONTROL_CT_CLASS_SLIDER or MIXERCONTROL_CT_UNITS_SIGNED)>
      MIXERCONTROL_CONTROLTYPE_PAN equ (MIXERCONTROL_CONTROLTYPE_SLIDER + 1)
      MIXERCONTROL_CONTROLTYPE_QSOUNDPAN equ (MIXERCONTROL_CONTROLTYPE_SLIDER + 2)
      MIXERCONTROL_CONTROLTYPE_FADER equ <(MIXERCONTROL_CT_CLASS_FADER or MIXERCONTROL_CT_UNITS_UNSIGNED)>
      MIXERCONTROL_CONTROLTYPE_VOLUME equ (MIXERCONTROL_CONTROLTYPE_FADER + 1)
      MIXERCONTROL_CONTROLTYPE_BASS equ (MIXERCONTROL_CONTROLTYPE_FADER + 2)
      MIXERCONTROL_CONTROLTYPE_TREBLE equ (MIXERCONTROL_CONTROLTYPE_FADER + 3)
      MIXERCONTROL_CONTROLTYPE_EQUALIZER equ (MIXERCONTROL_CONTROLTYPE_FADER + 4)
      MIXERCONTROL_CONTROLTYPE_SINGLESELECT equ <(MIXERCONTROL_CT_CLASS_LIST or MIXERCONTROL_CT_SC_LIST_SINGLE or MIXERCONTROL_CT_UNITS_BOOLEAN)>
      MIXERCONTROL_CONTROLTYPE_MUX equ (MIXERCONTROL_CONTROLTYPE_SINGLESELECT + 1)
      MIXERCONTROL_CONTROLTYPE_MULTIPLESELECT equ <(MIXERCONTROL_CT_CLASS_LIST or MIXERCONTROL_CT_SC_LIST_MULTIPLE or MIXERCONTROL_CT_UNITS_BOOLEAN)>
      MIXERCONTROL_CONTROLTYPE_MIXER equ (MIXERCONTROL_CONTROLTYPE_MULTIPLESELECT + 1)
      MIXERCONTROL_CONTROLTYPE_MICROTIME equ <(MIXERCONTROL_CT_CLASS_TIME or MIXERCONTROL_CT_SC_TIME_MICROSECS or MIXERCONTROL_CT_UNITS_UNSIGNED)>
      MIXERCONTROL_CONTROLTYPE_MILLITIME equ <(MIXERCONTROL_CT_CLASS_TIME or MIXERCONTROL_CT_SC_TIME_MILLISECS or MIXERCONTROL_CT_UNITS_UNSIGNED)>
      ;* *
      ;*  MIXERLINECONTROLS *
      ;* *
      ifdef _WIN32
        MIXERLINECONTROLSA struct
          cbStruct DWORD ?
          ;* size in bytes of MIXERLINECONTROLS *
          dwLineID DWORD ?
          ;* line id (from MIXERLINE.dwLineID) *
          union
            dwControlID DWORD ?
            ;* MIXER_GETLINECONTROLSF_ONEBYID *
            dwControlType DWORD ?
            ;* MIXER_GETLINECONTROLSF_ONEBYTYPE *
          ends
          cControls DWORD ?
          ;* count of controls pmxctrl points to *
          cbmxctrl DWORD ?
          ;* size in bytes of _one_ MIXERCONTROL *
          pamxctrl LPMIXERCONTROLA ?
          ;* pointer to first MIXERCONTROL array *
        MIXERLINECONTROLSA ends
        tagMIXERLINECONTROLSA typedef MIXERLINECONTROLSA
        PMIXERLINECONTROLSA typedef ptr MIXERLINECONTROLSA
        LPMIXERLINECONTROLSA typedef ptr MIXERLINECONTROLSA
        MIXERLINECONTROLSW struct
          cbStruct DWORD ?
          ;* size in bytes of MIXERLINECONTROLS *
          dwLineID DWORD ?
          ;* line id (from MIXERLINE.dwLineID) *
          union
            dwControlID DWORD ?
            ;* MIXER_GETLINECONTROLSF_ONEBYID *
            dwControlType DWORD ?
            ;* MIXER_GETLINECONTROLSF_ONEBYTYPE *
          ends
          cControls DWORD ?
          ;* count of controls pmxctrl points to *
          cbmxctrl DWORD ?
          ;* size in bytes of _one_ MIXERCONTROL *
          pamxctrl LPMIXERCONTROLW ?
          ;* pointer to first MIXERCONTROL array *
        MIXERLINECONTROLSW ends
        tagMIXERLINECONTROLSW typedef MIXERLINECONTROLSW
        PMIXERLINECONTROLSW typedef ptr MIXERLINECONTROLSW
        LPMIXERLINECONTROLSW typedef ptr MIXERLINECONTROLSW
        ifdef UNICODE
          MIXERLINECONTROLS typedef MIXERLINECONTROLSW
          PMIXERLINECONTROLS typedef PMIXERLINECONTROLSW
          LPMIXERLINECONTROLS typedef LPMIXERLINECONTROLSW
        else
          MIXERLINECONTROLS typedef MIXERLINECONTROLSA
          PMIXERLINECONTROLS typedef PMIXERLINECONTROLSA
          LPMIXERLINECONTROLS typedef LPMIXERLINECONTROLSA
        endif
        ; UNICODE
      else
        ;[...]
      endif
      ;* *
      ;* *
      ;* *
      ifdef _WIN32
        @DefProto DllImport, mixerGetLineControlsA, WIN_STD_CALL_CONV,, <:HMIXEROBJ, :LPMIXERLINECONTROLSA, :DWORD>, 12
        @DefProto DllImport, mixerGetLineControlsW, WIN_STD_CALL_CONV,, <:HMIXEROBJ, :LPMIXERLINECONTROLSW, :DWORD>, 12
        ifdef UNICODE
          mixerGetLineControls equ <mixerGetLineControlsW>
        else
          mixerGetLineControls equ <mixerGetLineControlsA>
        endif
        ; !UNICODE
      else
        ;[...]
      endif
      MIXER_GETLINECONTROLSF_ALL equ 00000000h
      MIXER_GETLINECONTROLSF_ONEBYID equ 00000001h
      MIXER_GETLINECONTROLSF_ONEBYTYPE equ 00000002h
      MIXER_GETLINECONTROLSF_QUERYMASK equ 0000000Fh
      MIXERCONTROLDETAILS struct
        cbStruct DWORD ?
        ;* size in bytes of MIXERCONTROLDETAILS *
        dwControlID DWORD ?
        ;* control id to get/set details on *
        cChannels DWORD ?
        ;* number of channels in paDetails array *
        union
          hwndOwner HWND ?
          ;* for MIXER_SETCONTROLDETAILSF_CUSTOM *
          cMultipleItems DWORD ?
          ;* if _MULTIPLE, the number of items per channel *
        ends
        cbDetails DWORD ?
        ;* size of _one_ details_XX struct *
        paDetails POINTER ?
        ;* pointer to array of details_XX structs *
      MIXERCONTROLDETAILS ends
      tMIXERCONTROLDETAILS typedef MIXERCONTROLDETAILS
      PMIXERCONTROLDETAILS typedef ptr MIXERCONTROLDETAILS
      LPMIXERCONTROLDETAILS typedef ptr MIXERCONTROLDETAILS
      ;* *
      ;*  MIXER_GETCONTROLDETAILSF_LISTTEXT *
      ;* *
      ;* *
      ifdef _WIN32
        MIXERCONTROLDETAILS_LISTTEXTA struct
          dwParam1 DWORD ?
          dwParam2 DWORD ?
          szName SBYTE MIXER_LONG_NAME_CHARS dup (?)
        MIXERCONTROLDETAILS_LISTTEXTA ends
        tagMIXERCONTROLDETAILS_LISTTEXTA typedef MIXERCONTROLDETAILS_LISTTEXTA
        PMIXERCONTROLDETAILS_LISTTEXTA typedef ptr MIXERCONTROLDETAILS_LISTTEXTA
        LPMIXERCONTROLDETAILS_LISTTEXTA typedef ptr MIXERCONTROLDETAILS_LISTTEXTA
        MIXERCONTROLDETAILS_LISTTEXTW struct
          dwParam1 DWORD ?
          dwParam2 DWORD ?
          szName WORD MIXER_LONG_NAME_CHARS dup (?)
        MIXERCONTROLDETAILS_LISTTEXTW ends
        tagMIXERCONTROLDETAILS_LISTTEXTW typedef MIXERCONTROLDETAILS_LISTTEXTW
        PMIXERCONTROLDETAILS_LISTTEXTW typedef ptr MIXERCONTROLDETAILS_LISTTEXTW
        LPMIXERCONTROLDETAILS_LISTTEXTW typedef ptr MIXERCONTROLDETAILS_LISTTEXTW
        ifdef UNICODE
          MIXERCONTROLDETAILS_LISTTEXT typedef MIXERCONTROLDETAILS_LISTTEXTW
          PMIXERCONTROLDETAILS_LISTTEXT typedef PMIXERCONTROLDETAILS_LISTTEXTW
          LPMIXERCONTROLDETAILS_LISTTEXT typedef LPMIXERCONTROLDETAILS_LISTTEXTW
        else
          MIXERCONTROLDETAILS_LISTTEXT typedef MIXERCONTROLDETAILS_LISTTEXTA
          PMIXERCONTROLDETAILS_LISTTEXT typedef PMIXERCONTROLDETAILS_LISTTEXTA
          LPMIXERCONTROLDETAILS_LISTTEXT typedef LPMIXERCONTROLDETAILS_LISTTEXTA
        endif
        ; UNICODE
      else
        ;[...]
      endif
      ;* *
      ;*  MIXER_GETCONTROLDETAILSF_VALUE *
      ;* *
      ;* *
      MIXERCONTROLDETAILS_BOOLEAN struct
        fValue SDWORD ?
      MIXERCONTROLDETAILS_BOOLEAN ends
      tMIXERCONTROLDETAILS_BOOLEAN typedef MIXERCONTROLDETAILS_BOOLEAN
      PMIXERCONTROLDETAILS_BOOLEAN typedef ptr MIXERCONTROLDETAILS_BOOLEAN
      LPMIXERCONTROLDETAILS_BOOLEAN typedef ptr MIXERCONTROLDETAILS_BOOLEAN
      MIXERCONTROLDETAILS_SIGNED struct
        lValue SDWORD ?
      MIXERCONTROLDETAILS_SIGNED ends
      tMIXERCONTROLDETAILS_SIGNED typedef MIXERCONTROLDETAILS_SIGNED
      PMIXERCONTROLDETAILS_SIGNED typedef ptr MIXERCONTROLDETAILS_SIGNED
      LPMIXERCONTROLDETAILS_SIGNED typedef ptr MIXERCONTROLDETAILS_SIGNED
      MIXERCONTROLDETAILS_UNSIGNED struct
        dwValue DWORD ?
      MIXERCONTROLDETAILS_UNSIGNED ends
      tMIXERCONTROLDETAILS_UNSIGNED typedef MIXERCONTROLDETAILS_UNSIGNED
      PMIXERCONTROLDETAILS_UNSIGNED typedef ptr MIXERCONTROLDETAILS_UNSIGNED
      LPMIXERCONTROLDETAILS_UNSIGNED typedef ptr MIXERCONTROLDETAILS_UNSIGNED
      ifdef _WIN32
        @DefProto DllImport, mixerGetControlDetailsA, WIN_STD_CALL_CONV,, <:HMIXEROBJ, :LPMIXERCONTROLDETAILS, :DWORD>, 12
        @DefProto DllImport, mixerGetControlDetailsW, WIN_STD_CALL_CONV,, <:HMIXEROBJ, :LPMIXERCONTROLDETAILS, :DWORD>, 12
        ifdef UNICODE
          mixerGetControlDetails equ <mixerGetControlDetailsW>
        else
          mixerGetControlDetails equ <mixerGetControlDetailsA>
        endif
        ; !UNICODE
      else
        ;[...]
      endif
      MIXER_GETCONTROLDETAILSF_VALUE equ 00000000h
      MIXER_GETCONTROLDETAILSF_LISTTEXT equ 00000001h
      MIXER_GETCONTROLDETAILSF_QUERYMASK equ 0000000Fh
      @DefProto DllImport, mixerSetControlDetails, WIN_STD_CALL_CONV,, <:HMIXEROBJ, :LPMIXERCONTROLDETAILS, :DWORD>, 12
      MIXER_SETCONTROLDETAILSF_VALUE equ 00000000h
      MIXER_SETCONTROLDETAILSF_CUSTOM equ 00000001h
      MIXER_SETCONTROLDETAILSF_QUERYMASK equ 0000000Fh
      ;* ifndef MMNOMIXER *
    endif
  endif
  ; WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
  ifdef __cplusplus
    ;[...]
  endif
endif
; _MMEAPI_H_
