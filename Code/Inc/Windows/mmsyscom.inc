;Include file created by h2inc+ version C.2.0 on (UTC) 25/05/2024 16:54:49
;(C) G. Friedrich April 2024
;Source file: d:\objasm\projects\x\h2inc+\h\um_10.0.22621.0\mmsyscom.h
;             Created on (UTC) 06/04/2024 06:15:56
;             Last modified on (UTC) 21/02/2024 18:13:14

include winapifamily.inc
ifndef _INC_MMSYSCOM
  _INC_MMSYSCOM equ <>
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
    MAXPNAMELEN equ 32
    MAXERRORLENGTH equ 256
    MAX_JOYSTICKOEMVXDNAME equ 260
    if (WINVER le 0400h)
      ifndef MM_MICROSOFT
        MM_MICROSOFT equ 1
      endif
      ifndef MM_MIDI_MAPPER
        MM_MIDI_MAPPER equ 1
        MM_WAVE_MAPPER equ 2
        MM_SNDBLST_MIDIOUT equ 3
        MM_SNDBLST_MIDIIN equ 4
        MM_SNDBLST_SYNTH equ 5
        MM_SNDBLST_WAVEOUT equ 6
        MM_SNDBLST_WAVEIN equ 7
        MM_ADLIB equ 9
        MM_MPU401_MIDIOUT equ 10
        MM_MPU401_MIDIIN equ 11
        MM_PC_JOYSTICK equ 12
      endif
    endif
    ifdef _WIN32
      MMVERSION typedef UINT
    else
      ;[...]
    endif
    MMRESULT typedef UINT
    _MMRESULT_ equ <>
    LPUINT typedef ptr UINT
    MMTIME struct
      wType UINT ?
      union u
        ms DWORD ?
        sample DWORD ?
        cb DWORD ?
        ticks DWORD ?
        struct smpte
          hour BYTE ?
          min BYTE ?
          sec BYTE ?
          frame_ BYTE ?
          fps BYTE ?
          dummy BYTE ?
          ifdef _WIN32
            pad BYTE 2 dup (?)
          endif
        ends
        struct midi
          songptrpos DWORD ?
        ends
      ends
    MMTIME ends
    mmtime_tag typedef MMTIME
    PMMTIME typedef ptr MMTIME
    NPMMTIME typedef ptr MMTIME
    LPMMTIME typedef ptr MMTIME
    TIME_MS equ 0001h
    TIME_SAMPLES equ 0002h
    TIME_BYTES equ 0004h
    TIME_SMPTE equ 0008h
    TIME_MIDI equ 0010h
    TIME_TICKS equ 0020h
    MAKEFOURCC macro ch0, ch1, ch2, ch3
      exitm <((ch0) or ((ch1) shl 8) or ((ch2) shl 16) or ((ch3) shl 24))>
    endm
    MM_JOY1MOVE equ 3A0h
    MM_JOY2MOVE equ 3A1h
    MM_JOY1ZMOVE equ 3A2h
    MM_JOY2ZMOVE equ 3A3h
    MM_JOY1BUTTONDOWN equ 3B5h
    MM_JOY2BUTTONDOWN equ 3B6h
    MM_JOY1BUTTONUP equ 3B7h
    MM_JOY2BUTTONUP equ 3B8h
    MM_MCINOTIFY equ 3B9h
    MM_WOM_OPEN equ 3BBh
    MM_WOM_CLOSE equ 3BCh
    MM_WOM_DONE equ 3BDh
    MM_WIM_OPEN equ 3BEh
    MM_WIM_CLOSE equ 3BFh
    MM_WIM_DATA equ 3C0h
    MM_MIM_OPEN equ 3C1h
    MM_MIM_CLOSE equ 3C2h
    MM_MIM_DATA equ 3C3h
    MM_MIM_LONGDATA equ 3C4h
    MM_MIM_ERROR equ 3C5h
    MM_MIM_LONGERROR equ 3C6h
    MM_MOM_OPEN equ 3C7h
    MM_MOM_CLOSE equ 3C8h
    MM_MOM_DONE equ 3C9h
    ifndef MM_DRVM_OPEN
      MM_DRVM_OPEN equ 3D0h
      MM_DRVM_CLOSE equ 3D1h
      MM_DRVM_DATA equ 3D2h
      MM_DRVM_ERROR equ 3D3h
    endif
    MM_STREAM_OPEN equ 3D4h
    MM_STREAM_CLOSE equ 3D5h
    MM_STREAM_DONE equ 3D6h
    MM_STREAM_ERROR equ 3D7h
    if (WINVER ge 0400h)
      MM_MOM_POSITIONCB equ 3CAh
      ifndef MM_MCISIGNAL
        MM_MCISIGNAL equ 3CBh
      endif
      MM_MIM_MOREDATA equ 3CCh
    endif
    MM_MIXM_LINE_CHANGE equ 3D0h
    MM_MIXM_CONTROL_CHANGE equ 3D1h
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
    MMSYSERR_NOERROR equ 0
    MMSYSERR_ERROR equ (MMSYSERR_BASE + 1)
    MMSYSERR_BADDEVICEID equ (MMSYSERR_BASE + 2)
    MMSYSERR_NOTENABLED equ (MMSYSERR_BASE + 3)
    MMSYSERR_ALLOCATED equ (MMSYSERR_BASE + 4)
    MMSYSERR_INVALHANDLE equ (MMSYSERR_BASE + 5)
    MMSYSERR_NODRIVER equ (MMSYSERR_BASE + 6)
    MMSYSERR_NOMEM equ (MMSYSERR_BASE + 7)
    MMSYSERR_NOTSUPPORTED equ (MMSYSERR_BASE + 8)
    MMSYSERR_BADERRNUM equ (MMSYSERR_BASE + 9)
    MMSYSERR_INVALFLAG equ (MMSYSERR_BASE + 10)
    MMSYSERR_INVALPARAM equ (MMSYSERR_BASE + 11)
    MMSYSERR_HANDLEBUSY equ (MMSYSERR_BASE + 12)
    MMSYSERR_INVALIDALIAS equ (MMSYSERR_BASE + 13)
    MMSYSERR_BADDB equ (MMSYSERR_BASE + 14)
    MMSYSERR_KEYNOTFOUND equ (MMSYSERR_BASE + 15)
    MMSYSERR_READERROR equ (MMSYSERR_BASE + 16)
    MMSYSERR_WRITEERROR equ (MMSYSERR_BASE + 17)
    MMSYSERR_DELETEERROR equ (MMSYSERR_BASE + 18)
    MMSYSERR_VALNOTFOUND equ (MMSYSERR_BASE + 19)
    MMSYSERR_NODRIVERCB equ (MMSYSERR_BASE + 20)
    MMSYSERR_MOREDATA equ (MMSYSERR_BASE + 21)
    MMSYSERR_LASTERROR equ (MMSYSERR_BASE + 21)
    if (WINVER lt 030ah) or Defined(_WIN32)
      DECLARE_HANDLE HDRVR
    endif
    CALLBACK_TYPEMASK equ 00070000h
    CALLBACK_NULL equ 00000000h
    CALLBACK_WINDOW equ 00010000h
    CALLBACK_TASK equ 00020000h
    CALLBACK_FUNCTION equ 00030000h
    ifdef _WIN32
      CALLBACK_THREAD equ <(CALLBACK_TASK)>
      CALLBACK_EVENT equ 00050000h
    endif
    TYPE_DRVCALLBACK typedef proto WIN_STD_CALL_CONV :HDRVR, :UINT, :DWORD_PTR, :DWORD_PTR, :DWORD_PTR
    DRVCALLBACK typedef ptr TYPE_DRVCALLBACK

    LPDRVCALLBACK typedef ptr DRVCALLBACK
    ifdef _WIN32
      PDRVCALLBACK typedef ptr DRVCALLBACK
    endif
  endif
  ifdef __cplusplus
    ;[...]
  endif
  ifdef _WIN32
    include poppack.inc
  else
    ;[...]
  endif
endif
