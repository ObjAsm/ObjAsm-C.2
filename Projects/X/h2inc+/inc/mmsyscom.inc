;Include file created by h2inc+ version C.2.0 on (UTC) 20/05/2024 18:06:34
;(C) G. Friedrich April 2024
;Source file: d:\objasm\projects\x\h2inc+\h\um_10.0.22621.0\mmsyscom.h
;             Created on (UTC) 06/04/2024 06:15:56
;             Last modified on (UTC) 21/02/2024 18:13:14

include winapifamily.inc
;*==========================================================================
;*
;*  mmsyscom.h -- Commonm Include file for Multimedia API's
;*
;*  Version 4.00
;*
;*  Copyright (C) 1992-1998 Microsoft Corporation.  All Rights Reserved.
;*
;*==========================================================================
;*
ifndef _INC_MMSYSCOM
  ;* #defined if mmsystem.h has been included *
  _INC_MMSYSCOM equ <>
  ; nameless struct/union
  ifdef _WIN32
    include pshpack1.inc
  else
    ;[...]
  endif
  ifdef __cplusplus
    ;[...]
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
    ifdef _WIN32
      ifndef _WINMM_
        WINMMAPI equ <DECLSPEC_IMPORT>
      else
        WINMMAPI equ <>
      endif
      _loadds equ <>
      _huge equ <>
    else
      ;[...]
    endif
    ifdef _MAC
      ;[...]
    endif
    ;_MAC
    ;****************************************************************************
    ;General constants and data types
    ;****************************************************************************
    ;* general constants *
    ;* max product name length (including NULL) *
    MAXPNAMELEN equ 32
    ;* max error text length (including NULL) *
    MAXERRORLENGTH equ 256
    ;* max oem vxd name length (including NULL) *
    MAX_JOYSTICKOEMVXDNAME equ 260
    ;*
    ;*  Microsoft Manufacturer and Product ID's (these have been moved to
    ;*  MMREG.H for Windows 4.00 and above).
    ;*
    if (WINVER le 0400h)
      ifndef MM_MICROSOFT
        ;* Microsoft Corporation *
        MM_MICROSOFT equ 1
      endif
      ifndef MM_MIDI_MAPPER
        ;* MIDI Mapper *
        MM_MIDI_MAPPER equ 1
        ;* Wave Mapper *
        MM_WAVE_MAPPER equ 2
        ;* Sound Blaster MIDI output port *
        MM_SNDBLST_MIDIOUT equ 3
        ;* Sound Blaster MIDI input port *
        MM_SNDBLST_MIDIIN equ 4
        ;* Sound Blaster internal synthesizer *
        MM_SNDBLST_SYNTH equ 5
        ;* Sound Blaster waveform output *
        MM_SNDBLST_WAVEOUT equ 6
        ;* Sound Blaster waveform input *
        MM_SNDBLST_WAVEIN equ 7
        ;* Ad Lib-compatible synthesizer *
        MM_ADLIB equ 9
        ;* MPU401-compatible MIDI output port *
        MM_MPU401_MIDIOUT equ 10
        ;* MPU401-compatible MIDI input port *
        MM_MPU401_MIDIIN equ 11
        ;* Joystick adapter *
        MM_PC_JOYSTICK equ 12
      endif
    endif
    ;* general data types *
    ifdef _WIN32
      ;* major (high byte), minor (low byte) *
      MMVERSION typedef UINT
    else
      ;[...]
    endif
    ;* error return code, 0 means no error *
    MMRESULT typedef UINT
    ;* call as if(err=xxxx(...)) Error(err); else *
    _MMRESULT_ equ <>
    LPUINT typedef ptr UINT
    ;* MMTIME data structure *
    MMTIME struct
      wType DWORD ?
      ;* indicates the contents of the union *
      union u
        ms DWORD ?
        ;* milliseconds *
        sample DWORD ?
        ;* samples *
        cb DWORD ?
        ;* byte count *
        ticks DWORD ?
        ;* ticks in MIDI stream *
        ;* SMPTE *
        struct smpte
          hour BYTE ?
          ;* hours *
          min BYTE ?
          ;* minutes *
          sec BYTE ?
          ;* seconds *
          frame_ BYTE ?
          ;* frames  *
          fps BYTE ?
          ;* frames per second *
          dummy BYTE ?
          ;* pad *
          ifdef _WIN32
            pad BYTE 2 dup (?)
          endif
        ends
        ;* MIDI *
        struct midi
          songptrpos DWORD ?
          ;* song pointer position *
        ends
      ends
    MMTIME ends
    mmtime_tag typedef MMTIME
    PMMTIME typedef ptr MMTIME
    NPMMTIME typedef ptr MMTIME
    LPMMTIME typedef ptr MMTIME
    ;* types for wType field in MMTIME struct *
    ;* time in milliseconds *
    TIME_MS equ 0001h
    ;* number of wave samples *
    TIME_SAMPLES equ 0002h
    ;* current byte offset *
    TIME_BYTES equ 0004h
    ;* SMPTE time *
    TIME_SMPTE equ 0008h
    ;* MIDI time *
    TIME_MIDI equ 0010h
    ;* Ticks within MIDI stream *
    TIME_TICKS equ 0020h
    ;*
    ;*
    ;*
    ;*
    MAKEFOURCC macro ch0, ch1, ch2, ch3
      exitm <((ch0) or ((ch1) shl 8) or ((ch2) shl 16) or ((ch3) shl 24))>
    endm
    ;****************************************************************************
    ;Multimedia Extensions Window Messages
    ;****************************************************************************
    ;* joystick *
    MM_JOY1MOVE equ 3A0h
    MM_JOY2MOVE equ 3A1h
    MM_JOY1ZMOVE equ 3A2h
    MM_JOY2ZMOVE equ 3A3h
    MM_JOY1BUTTONDOWN equ 3B5h
    MM_JOY2BUTTONDOWN equ 3B6h
    MM_JOY1BUTTONUP equ 3B7h
    MM_JOY2BUTTONUP equ 3B8h
    ;* MCI *
    MM_MCINOTIFY equ 3B9h
    ;* waveform output *
    MM_WOM_OPEN equ 3BBh
    MM_WOM_CLOSE equ 3BCh
    MM_WOM_DONE equ 3BDh
    ;* waveform input *
    MM_WIM_OPEN equ 3BEh
    MM_WIM_CLOSE equ 3BFh
    MM_WIM_DATA equ 3C0h
    ;* MIDI input *
    MM_MIM_OPEN equ 3C1h
    MM_MIM_CLOSE equ 3C2h
    MM_MIM_DATA equ 3C3h
    MM_MIM_LONGDATA equ 3C4h
    MM_MIM_ERROR equ 3C5h
    MM_MIM_LONGERROR equ 3C6h
    ;* MIDI output *
    MM_MOM_OPEN equ 3C7h
    MM_MOM_CLOSE equ 3C8h
    MM_MOM_DONE equ 3C9h
    ;* these are also in msvideo.h *
    ifndef MM_DRVM_OPEN
      ;* installable drivers *
      MM_DRVM_OPEN equ 3D0h
      MM_DRVM_CLOSE equ 3D1h
      MM_DRVM_DATA equ 3D2h
      MM_DRVM_ERROR equ 3D3h
    endif
    ;* these are used by msacm.h *
    MM_STREAM_OPEN equ 3D4h
    MM_STREAM_CLOSE equ 3D5h
    MM_STREAM_DONE equ 3D6h
    MM_STREAM_ERROR equ 3D7h
    if (WINVER ge 0400h)
      ;* Callback for MEVT_POSITIONCB *
      MM_MOM_POSITIONCB equ 3CAh
      ifndef MM_MCISIGNAL
        MM_MCISIGNAL equ 3CBh
      endif
      ;* MIM_DONE w/ pending events *
      MM_MIM_MOREDATA equ 3CCh
      ;* WINVER >= 0x0400 *
    endif
    ;* mixer line change notify *
    MM_MIXM_LINE_CHANGE equ 3D0h
    ;* mixer control change notify *
    MM_MIXM_CONTROL_CHANGE equ 3D1h
    ;****************************************************************************
    ;String resource number bases (internal use)
    ;****************************************************************************
    MMSYSERR_BASE equ 0
    WAVERR_BASE equ 32
    MIDIERR_BASE equ 64
    TIMERR_BASE equ 96
    JOYERR_BASE equ 160
    MCIERR_BASE equ 256
    MIXERR_BASE equ 1024
    MCI_STRING_OFFSET equ 512
    MCI_VD_OFFSET equ 1024
    MCI_CD_OFFSET equ 1088
    MCI_WAVE_OFFSET equ 1152
    MCI_SEQ_OFFSET equ 1216
    ;****************************************************************************
    ;General error return values
    ;****************************************************************************
    ;* general error return values *
    ;* no error *
    MMSYSERR_NOERROR equ 0
    ;* unspecified error *
    MMSYSERR_ERROR equ (MMSYSERR_BASE + 1)
    ;* device ID out of range *
    MMSYSERR_BADDEVICEID equ (MMSYSERR_BASE + 2)
    ;* driver failed enable *
    MMSYSERR_NOTENABLED equ (MMSYSERR_BASE + 3)
    ;* device already allocated *
    MMSYSERR_ALLOCATED equ (MMSYSERR_BASE + 4)
    ;* device handle is invalid *
    MMSYSERR_INVALHANDLE equ (MMSYSERR_BASE + 5)
    ;* no device driver present *
    MMSYSERR_NODRIVER equ (MMSYSERR_BASE + 6)
    ;* memory allocation error *
    MMSYSERR_NOMEM equ (MMSYSERR_BASE + 7)
    ;* function isn't supported *
    MMSYSERR_NOTSUPPORTED equ (MMSYSERR_BASE + 8)
    ;* error value out of range *
    MMSYSERR_BADERRNUM equ (MMSYSERR_BASE + 9)
    ;* invalid flag passed *
    MMSYSERR_INVALFLAG equ (MMSYSERR_BASE + 10)
    ;* invalid parameter passed *
    MMSYSERR_INVALPARAM equ (MMSYSERR_BASE + 11)
    ;* handle being used *
    MMSYSERR_HANDLEBUSY equ (MMSYSERR_BASE + 12)
    ;* simultaneously on another *
    ;* thread (eg callback) *
    ;* specified alias not found *
    MMSYSERR_INVALIDALIAS equ (MMSYSERR_BASE + 13)
    ;* bad registry database *
    MMSYSERR_BADDB equ (MMSYSERR_BASE + 14)
    ;* registry key not found *
    MMSYSERR_KEYNOTFOUND equ (MMSYSERR_BASE + 15)
    ;* registry read error *
    MMSYSERR_READERROR equ (MMSYSERR_BASE + 16)
    ;* registry write error *
    MMSYSERR_WRITEERROR equ (MMSYSERR_BASE + 17)
    ;* registry delete error *
    MMSYSERR_DELETEERROR equ (MMSYSERR_BASE + 18)
    ;* registry value not found *
    MMSYSERR_VALNOTFOUND equ (MMSYSERR_BASE + 19)
    ;* driver does not call DriverCallback *
    MMSYSERR_NODRIVERCB equ (MMSYSERR_BASE + 20)
    ;* more data to be returned *
    MMSYSERR_MOREDATA equ (MMSYSERR_BASE + 21)
    ;* last error in range *
    MMSYSERR_LASTERROR equ (MMSYSERR_BASE + 21)
    if (WINVER lt 030ah) or Defined(_WIN32)
      DECLARE_HANDLE HDRVR
      ;* ifdef WINVER < 0x030a *
    endif
    ;****************************************************************************
    ;Driver callback support
    ;****************************************************************************
    ;* flags used with waveOutOpen(), waveInOpen(), midiInOpen(), and *
    ;* midiOutOpen() to specify the type of the dwCallback parameter. *
    ;* callback type mask *
    CALLBACK_TYPEMASK equ 00070000h
    ;* no callback *
    CALLBACK_NULL equ 00000000h
    ;* dwCallback is a HWND *
    CALLBACK_WINDOW equ 00010000h
    ;* dwCallback is a HTASK *
    CALLBACK_TASK equ 00020000h
    ;* dwCallback is a FARPROC *
    CALLBACK_FUNCTION equ 00030000h
    ifdef _WIN32
      ;* thread ID replaces 16 bit task *
      CALLBACK_THREAD equ <(CALLBACK_TASK)>
      ;* dwCallback is an EVENT Handle *
      CALLBACK_EVENT equ 00050000h
    endif
    TYPE_DRVCALLBACK typedef proto WIN_STD_CALL_CONV :HDRVR, :UINT, :DWORD_PTR, :DWORD_PTR, :DWORD_PTR
    DRVCALLBACK typedef ptr TYPE_DRVCALLBACK

    LPDRVCALLBACK typedef ptr DRVCALLBACK
    ifdef _WIN32
      PDRVCALLBACK typedef ptr DRVCALLBACK
    endif
    ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM) *
  endif
  ifdef __cplusplus
    ;[...]
  endif
  ifdef _WIN32
    include poppack.inc
  else
    ;[...]
  endif
  ;* _INC_MMSYSCOM *
endif
