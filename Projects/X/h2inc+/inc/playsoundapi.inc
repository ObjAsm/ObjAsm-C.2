;Include file created by h2inc+ version C.2.0 on (UTC) 20/05/2024 18:06:34
;(C) G. Friedrich April 2024
;Source file: d:\objasm\projects\x\h2inc+\h\um_10.0.22621.0\playsoundapi.h
;             Created on (UTC) 06/04/2024 06:15:57
;             Last modified on (UTC) 21/02/2024 18:13:20

;********************************************************************************
ifdef _MSC_VER
endif
; _MSC_VER
ifndef _PLAYSOUNDAPI_H_
  _PLAYSOUNDAPI_H_ equ <>
  include apiset.inc
  include apisetcconv.inc
  include mmsyscom.inc
  ; mm common definitions
  ifdef __cplusplus
    ;[...]
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    ifndef MMNOSOUND
      ;****************************************************************************
      ;Sound support
      ;****************************************************************************
      ifdef _WIN32
        @DefProto DllImport, sndPlaySoundA, WIN_STD_CALL_CONV,, <:LPCSTR, :UINT>, 8
        @DefProto DllImport, sndPlaySoundW, WIN_STD_CALL_CONV,, <:LPCWSTR, :UINT>, 8
        ifdef UNICODE
          sndPlaySound equ <sndPlaySoundW>
        else
          sndPlaySound equ <sndPlaySoundA>
        endif
        ; !UNICODE
      else
        ;[...]
      endif
      ;*
      ;*  flag values for fuSound and fdwSound arguments on [snd]PlaySound
      ;*
      ;* play synchronously (default) *
      SND_SYNC equ 0000h
      ;* play asynchronously *
      SND_ASYNC equ 0001h
      ;* silence (!default) if sound not found *
      SND_NODEFAULT equ 0002h
      ;* pszSound points to a memory file *
      SND_MEMORY equ 0004h
      ;* loop the sound until next sndPlaySound *
      SND_LOOP equ 0008h
      ;* don't stop any currently playing sound *
      SND_NOSTOP equ 0010h
      ;* don't wait if the driver is busy *
      SND_NOWAIT equ 00002000h
      ;* name is a registry alias *
      SND_ALIAS equ 00010000h
      ;* alias is a predefined ID *
      SND_ALIAS_ID equ 00110000h
      ;* name is file name *
      SND_FILENAME equ 00020000h
      ;* name is resource name or atom *
      SND_RESOURCE equ 00040004h
      if (WINVER ge 0400h)
        ;* purge non-static events for task *
        SND_PURGE equ 0040h
        ;* look for application specific association *
        SND_APPLICATION equ 0080h
        ;* WINVER >= 0x0400 *
      endif
      ;* Generate a SoundSentry event with this sound *
      SND_SENTRY equ 00080000h
      ;* Treat this as a "ring" from a communications app - don't duck me *
      SND_RING equ 00100000h
      ;* Treat this as a system sound *
      SND_SYSTEM equ 00200000h
      ;* alias base *
      SND_ALIAS_START equ 0
      ifdef _WIN32
        sndAlias macro ch0, ch1
          exitm <(SND_ALIAS_START + (ch0) or ((ch1) shl 8))>
        endm
        SND_ALIAS_SYSTEMASTERISK equ <sndAlias('S', ' * ')>
        SND_ALIAS_SYSTEMQUESTION equ <sndAlias('S', '?')>
        SND_ALIAS_SYSTEMHAND equ <sndAlias('S', 'H')>
        SND_ALIAS_SYSTEMEXIT equ <sndAlias('S', 'E')>
        SND_ALIAS_SYSTEMSTART equ <sndAlias('S', 'S')>
        SND_ALIAS_SYSTEMWELCOME equ <sndAlias('S', 'W')>
        SND_ALIAS_SYSTEMEXCLAMATION equ sndAlias('S', ' not ')
        SND_ALIAS_SYSTEMDEFAULT equ <sndAlias('S', 'D')>
        @DefProto DllImport, PlaySoundA, WIN_STD_CALL_CONV,, <:LPCSTR, :HMODULE, :DWORD>, 12
        @DefProto DllImport, PlaySoundW, WIN_STD_CALL_CONV,, <:LPCWSTR, :HMODULE, :DWORD>, 12
        ifdef UNICODE
          PlaySound equ <PlaySoundW>
        else
          PlaySound equ <PlaySoundA>
        endif
        ; !UNICODE
      else
        ;[...]
      endif
      ;* ifndef MMNOSOUND *
    endif
  endif
  ; WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
  ifdef __cplusplus
    ;[...]
  endif
endif
; _PLAYSOUNDAPI_H_
