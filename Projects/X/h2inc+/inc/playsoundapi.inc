;Include file created by h2inc+ version C.2.0 on (UTC) 19/05/2024 07:52:23
;(C) G. Friedrich April 2024
;Source file: d:\objasm\projects\x\h2inc+\h\um_10.0.22621.0\playsoundapi.h\playsoundapi.h
;             Created on (UTC) 06/04/2024 06:15:57
;             Last modified on (UTC) 21/02/2024 18:13:20

ifdef _MSC_VER
endif
ifndef _PLAYSOUNDAPI_H_
  _PLAYSOUNDAPI_H_ equ <>
  include apiset.inc
  include apisetcconv.inc
  include mmsyscom.inc
  ifdef __cplusplus
    ;[...]
  endif
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    ifndef MMNOSOUND
      ifdef _WIN32
        @DefProto DllImport, sndPlaySoundA, WIN_STD_CALL_CONV,, <:LPCSTR, :UINT>, 8
        @DefProto DllImport, sndPlaySoundW, WIN_STD_CALL_CONV,, <:LPCWSTR, :UINT>, 8
        ifdef UNICODE
          sndPlaySound equ <sndPlaySoundW>
        else
          sndPlaySound equ <sndPlaySoundA>
        endif
      else
        ;[...]
      endif
      SND_SYNC equ 0000h
      SND_ASYNC equ 0001h
      SND_NODEFAULT equ 0002h
      SND_MEMORY equ 0004h
      SND_LOOP equ 0008h
      SND_NOSTOP equ 0010h
      SND_NOWAIT equ 00002000h
      SND_ALIAS equ 00010000h
      SND_ALIAS_ID equ 00110000h
      SND_FILENAME equ 00020000h
      SND_RESOURCE equ 00040004h
      if (WINVER ge 0400h)
        SND_PURGE equ 0040h
        SND_APPLICATION equ 0080h
      endif
      SND_SENTRY equ 00080000h
      SND_RING equ 00100000h
      SND_SYSTEM equ 00200000h
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
      else
        ;[...]
      endif
    endif
  endif
  ifdef __cplusplus
    ;[...]
  endif
endif
