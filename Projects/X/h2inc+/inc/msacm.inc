;Include file created by h2inc+ version C.2.0 on (UTC) 20/05/2024 18:06:34
;(C) G. Friedrich April 2024
;Source file: d:\objasm\projects\x\h2inc+\h\um_10.0.22621.0\msacm.h
;             Created on (UTC) 06/04/2024 06:15:56
;             Last modified on (UTC) 21/02/2024 18:13:14

;==========================================================================;
ifndef _INC_ACM
  ;* #defined if msacm.h has been included *
  _INC_ACM equ <>
  if _MSC_VER gt 1000
  endif
  include winapifamily.inc
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    if  not Defined(_INC_MMREG) or (_INC_MMREG lt 142)
      ifndef RC_INVOKED
        .err <MMREG.H version 142 or greater to be included first>
      endif
    endif
    if Defined(WIN32) and  not Defined(_WIN32)
      ;[...]
    endif
    if Defined(UNICODE) and  not Defined(_UNICODE)
      ifndef RC_INVOKED
        echo  MSACM.H: defining _UNICODE because application defined UNICODE
      endif
      _UNICODE equ <>
    endif
    ;* Assume byte packing throughout *
    include pshpack1.inc
    ifdef __cplusplus
      ;[...]
    endif
    ;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - ;
    ;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - ;
    ifndef DRV_MAPPER_PREFERRED_INPUT_GET
      DRV_MAPPER_PREFERRED_INPUT_GET equ (DRV_USER + 0)
    endif
    ifndef DRV_MAPPER_PREFERRED_OUTPUT_GET
      DRV_MAPPER_PREFERRED_OUTPUT_GET equ (DRV_USER + 2)
    endif
    ifndef DRVM_MAPPER_STATUS
      DRVM_MAPPER equ (2000h)
      DRVM_MAPPER_STATUS equ (DRVM_MAPPER + 0)
    endif
    ifndef WIDM_MAPPER_STATUS
      WIDM_MAPPER_STATUS equ (DRVM_MAPPER_STATUS + 0)
      WAVEIN_MAPPER_STATUS_DEVICE equ 0
      WAVEIN_MAPPER_STATUS_MAPPED equ 1
      WAVEIN_MAPPER_STATUS_FORMAT equ 2
    endif
    ifndef WODM_MAPPER_STATUS
      WODM_MAPPER_STATUS equ (DRVM_MAPPER_STATUS + 0)
      WAVEOUT_MAPPER_STATUS_DEVICE equ 0
      WAVEOUT_MAPPER_STATUS_MAPPED equ 1
      WAVEOUT_MAPPER_STATUS_FORMAT equ 2
    endif
    ;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - ;
    ;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - ;
    ifdef _WIN32
      ACMAPI equ <WINAPI>
    else
      ;[...]
    endif
    ;--------------------------------------------------------------------------;
    ;  ACM General API's and Defines
    ;--------------------------------------------------------------------------;
    ;  there are four types of 'handles' used by the ACM. the first three
    ;  are unique types that define specific objects:
    ;  HACMDRIVERID: used to _identify_ an ACM driver. this identifier can be
    ;  used to _open_ the driver for querying details, etc about the driver.
    ;  HACMDRIVER: used to manage a driver (codec, filter, etc). this handle
    ;  is much like a handle to other media drivers--you use it to send
    ;  messages to the converter, query for capabilities, etc.
    ;  HACMSTREAM: used to manage a 'stream' (conversion channel) with the
    ;  ACM. you use a stream handle to convert data from one format/type
    ;  to another--much like dealing with a file handle.
    ;  the fourth handle type is a generic type used on ACM functions that
    ;  can accept two or more of the above handle types (for example the
    ;  acmMetrics and acmDriverID functions).
    ;  HACMOBJ: used to identify ACM objects. this handle is used on functions
    ;  that can accept two or more ACM handle types.
    DECLARE_HANDLE HACMDRIVERID
    PHACMDRIVERID typedef ptr HACMDRIVERID
    LPHACMDRIVERID typedef ptr HACMDRIVERID
    DECLARE_HANDLE HACMDRIVER
    PHACMDRIVER typedef ptr HACMDRIVER
    LPHACMDRIVER typedef ptr HACMDRIVER
    DECLARE_HANDLE HACMSTREAM
    PHACMSTREAM typedef ptr HACMSTREAM
    LPHACMSTREAM typedef ptr HACMSTREAM
    DECLARE_HANDLE HACMOBJ
    PHACMOBJ typedef ptr HACMOBJ
    LPHACMOBJ typedef ptr HACMOBJ
    ;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - ;
    ;  ACM Error Codes
    ;  Note that these error codes are specific errors that apply to the ACM
    ;  directly--general errors are defined as MMSYSERR_*.
    ;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - ;
    ifndef _MMRESULT_
      _MMRESULT_ equ <>
      MMRESULT typedef UINT
    endif
    ACMERR_BASE equ (512)
    ACMERR_NOTPOSSIBLE equ (ACMERR_BASE + 0)
    ACMERR_BUSY equ (ACMERR_BASE + 1)
    ACMERR_UNPREPARED equ (ACMERR_BASE + 2)
    ACMERR_CANCELED equ (ACMERR_BASE + 3)
    ;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - ;
    ;  ACM Window Messages
    ;  These window messages are sent by the ACM or ACM drivers to notify
    ;  applications of events.
    ;  Note that these window message numbers will also be defined in
    ;  mmsystem.
    ;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - ;
    MM_ACM_OPEN equ <(MM_STREAM_OPEN)>; conversion callback messages

    MM_ACM_CLOSE equ <(MM_STREAM_CLOSE)>
    MM_ACM_DONE equ <(MM_STREAM_DONE)>
    ;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - ;
    ;  acmGetVersion()
    ;  the ACM version is a 32 bit number that is broken into three parts as 
    ;  follows:
    ;      bits 24 - 31:   8 bit _major_ version number
    ;      bits 16 - 23:   8 bit _minor_ version number
    ;      bits  0 - 15:   16 bit build number
    ;  this is then displayed as follows:
    ;      bMajor = (BYTE)(dwVersion >> 24)
    ;      bMinor = (BYTE)(dwVersion >> 16) & 
    ;      wBuild = LOWORD(dwVersion)
    ;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - ;
    acmGetVersion proto WIN_STD_CALL_CONV
    ;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - ;
    ;  acmMetrics()
    ;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - ;
    acmMetrics proto WIN_STD_CALL_CONV :HACMOBJ, :UINT, :LPVOID
    ACM_METRIC_COUNT_DRIVERS equ 1
    ACM_METRIC_COUNT_CODECS equ 2
    ACM_METRIC_COUNT_CONVERTERS equ 3
    ACM_METRIC_COUNT_FILTERS equ 4
    ACM_METRIC_COUNT_DISABLED equ 5
    ACM_METRIC_COUNT_HARDWARE equ 6
    ACM_METRIC_COUNT_LOCAL_DRIVERS equ 20
    ACM_METRIC_COUNT_LOCAL_CODECS equ 21
    ACM_METRIC_COUNT_LOCAL_CONVERTERS equ 22
    ACM_METRIC_COUNT_LOCAL_FILTERS equ 23
    ACM_METRIC_COUNT_LOCAL_DISABLED equ 24
    ACM_METRIC_HARDWARE_WAVE_INPUT equ 30
    ACM_METRIC_HARDWARE_WAVE_OUTPUT equ 31
    ACM_METRIC_MAX_SIZE_FORMAT equ 50
    ACM_METRIC_MAX_SIZE_FILTER equ 51
    ACM_METRIC_DRIVER_SUPPORT equ 100
    ACM_METRIC_DRIVER_PRIORITY equ 101
    ;--------------------------------------------------------------------------;
    ;  ACM Drivers
    ;--------------------------------------------------------------------------;
    ;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - ;
    ;  acmDriverEnum()
    ;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - ;
    TYPE_ACMDRIVERENUMCB typedef proto WIN_STD_CALL_CONV :HACMDRIVERID, :DWORD_PTR, :DWORD
    ACMDRIVERENUMCB typedef ptr TYPE_ACMDRIVERENUMCB

    acmDriverEnum proto WIN_STD_CALL_CONV :ACMDRIVERENUMCB, :DWORD_PTR, :DWORD
    ACM_DRIVERENUMF_NOLOCAL equ 40000000h
    ACM_DRIVERENUMF_DISABLED equ 80000000h
    ;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - ;
    ;  acmDriverID()
    ;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - ;
    acmDriverID proto WIN_STD_CALL_CONV :HACMOBJ, :LPHACMDRIVERID, :DWORD
    ;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - ;
    ;  acmDriverAdd()
    ;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - ;
    ifdef _WIN32
      acmDriverAddA proto WIN_STD_CALL_CONV :LPHACMDRIVERID, :HINSTANCE, :LPARAM, :DWORD, :DWORD
      acmDriverAddW proto WIN_STD_CALL_CONV :LPHACMDRIVERID, :HINSTANCE, :LPARAM, :DWORD, :DWORD
      ifdef _UNICODE
        acmDriverAdd equ <acmDriverAddW>
      else
        acmDriverAdd equ <acmDriverAddA>
      endif
    else
      ;[...]
    endif
    ACM_DRIVERADDF_NAME equ 00000001h
    ACM_DRIVERADDF_FUNCTION equ 00000003h; lParam is a procedure

    ACM_DRIVERADDF_NOTIFYHWND equ 00000004h; lParam is notify hwnd

    ACM_DRIVERADDF_TYPEMASK equ 00000007h; driver type mask

    ACM_DRIVERADDF_LOCAL equ 00000000h; is local to current task

    ACM_DRIVERADDF_GLOBAL equ 00000008h; is global

    ;  prototype for ACM driver procedures that are installed as _functions_
    ;  or _notifations_ instead of as a standalone installable driver.
    TYPE_ACMDRIVERPROC typedef proto WIN_STD_CALL_CONV :DWORD_PTR, :HACMDRIVERID, :UINT, :LPARAM, :LPARAM
    ACMDRIVERPROC typedef ptr TYPE_ACMDRIVERPROC

    LPACMDRIVERPROC typedef ptr ACMDRIVERPROC
    ;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - ;
    ;  acmDriverRemove()
    ;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - ;
    acmDriverRemove proto WIN_STD_CALL_CONV :HACMDRIVERID, :DWORD
    ;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - ;
    ;  acmDriverOpen()
    ;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - ;
    acmDriverOpen proto WIN_STD_CALL_CONV :LPHACMDRIVER, :HACMDRIVERID, :DWORD
    ;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - ;
    ;  acmDriverClose()
    ;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - ;
    acmDriverClose proto WIN_STD_CALL_CONV :HACMDRIVER, :DWORD
    ;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - ;
    ;  acmDriverMessage()
    ;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - ;
    acmDriverMessage proto WIN_STD_CALL_CONV :HACMDRIVER, :UINT, :LPARAM, :LPARAM
    ACMDM_USER equ (DRV_USER + 0000h)
    ACMDM_RESERVED_LOW equ (DRV_USER + 2000h)
    ACMDM_RESERVED_HIGH equ (DRV_USER + 2FFFh)
    ACMDM_BASE equ <ACMDM_RESERVED_LOW>
    ACMDM_DRIVER_ABOUT equ (ACMDM_BASE + 11)
    ;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - ;
    ;  acmDriverPriority
    ;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - ;
    acmDriverPriority proto WIN_STD_CALL_CONV :HACMDRIVERID, :DWORD, :DWORD
    ACM_DRIVERPRIORITYF_ENABLE equ 00000001h
    ACM_DRIVERPRIORITYF_DISABLE equ 00000002h
    ACM_DRIVERPRIORITYF_ABLEMASK equ 00000003h
    ACM_DRIVERPRIORITYF_BEGIN equ 00010000h
    ACM_DRIVERPRIORITYF_END equ 00020000h
    ACM_DRIVERPRIORITYF_DEFERMASK equ 00030000h
    ;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - ;
    ;  acmDriverDetails()
    ;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - ;
    ;  ACMDRIVERDETAILS
    ;  the ACMDRIVERDETAILS structure is used to get various capabilities from
    ;  an ACM driver (codec, converter, filter).
    ACMDRIVERDETAILS_SHORTNAME_CHARS equ 32
    ACMDRIVERDETAILS_LONGNAME_CHARS equ 128
    ACMDRIVERDETAILS_COPYRIGHT_CHARS equ 80
    ACMDRIVERDETAILS_LICENSING_CHARS equ 128
    ACMDRIVERDETAILS_FEATURES_CHARS equ 512
    ifdef _WIN32
      ACMDRIVERDETAILSA struct
        cbStruct DWORD ?
        ; number of valid bytes in structure
        fccType FOURCC ?
        ; compressor type 'audc'
        fccComp FOURCC ?
        ; sub-type (not used; reserved)
        wMid WORD ?
        ; manufacturer id
        wPid WORD ?
        ; product id
        vdwACM DWORD ?
        ; version of the ACM *compiled* for
        vdwDriver DWORD ?
        ; version of the driver
        fdwSupport DWORD ?
        ; misc. support flags
        cFormatTags DWORD ?
        ; total unique format tags supported
        cFilterTags DWORD ?
        ; total unique filter tags supported
        hicon HICON ?
        ; handle to custom icon
        szShortName SBYTE ACMDRIVERDETAILS_SHORTNAME_CHARS dup (?)
        szLongName SBYTE ACMDRIVERDETAILS_LONGNAME_CHARS dup (?)
        szCopyright SBYTE ACMDRIVERDETAILS_COPYRIGHT_CHARS dup (?)
        szLicensing SBYTE ACMDRIVERDETAILS_LICENSING_CHARS dup (?)
        szFeatures SBYTE ACMDRIVERDETAILS_FEATURES_CHARS dup (?)
      ACMDRIVERDETAILSA ends
      tACMDRIVERDETAILSA typedef ACMDRIVERDETAILSA
      PACMDRIVERDETAILSA typedef ptr ACMDRIVERDETAILSA
      LPACMDRIVERDETAILSA typedef ptr ACMDRIVERDETAILSA
      ACMDRIVERDETAILSW struct
        cbStruct DWORD ?
        ; number of valid bytes in structure
        fccType FOURCC ?
        ; compressor type 'audc'
        fccComp FOURCC ?
        ; sub-type (not used; reserved)
        wMid WORD ?
        ; manufacturer id
        wPid WORD ?
        ; product id
        vdwACM DWORD ?
        ; version of the ACM *compiled* for
        vdwDriver DWORD ?
        ; version of the driver
        fdwSupport DWORD ?
        ; misc. support flags
        cFormatTags DWORD ?
        ; total unique format tags supported
        cFilterTags DWORD ?
        ; total unique filter tags supported
        hicon HICON ?
        ; handle to custom icon
        szShortName WORD ACMDRIVERDETAILS_SHORTNAME_CHARS dup (?)
        szLongName WORD ACMDRIVERDETAILS_LONGNAME_CHARS dup (?)
        szCopyright WORD ACMDRIVERDETAILS_COPYRIGHT_CHARS dup (?)
        szLicensing WORD ACMDRIVERDETAILS_LICENSING_CHARS dup (?)
        szFeatures WORD ACMDRIVERDETAILS_FEATURES_CHARS dup (?)
      ACMDRIVERDETAILSW ends
      tACMDRIVERDETAILSW typedef ACMDRIVERDETAILSW
      PACMDRIVERDETAILSW typedef ptr ACMDRIVERDETAILSW
      LPACMDRIVERDETAILSW typedef ptr ACMDRIVERDETAILSW
      ifdef _UNICODE
        ACMDRIVERDETAILS equ <ACMDRIVERDETAILSW>
        PACMDRIVERDETAILS equ <PACMDRIVERDETAILSW>
        LPACMDRIVERDETAILS equ <LPACMDRIVERDETAILSW>
      else
        ACMDRIVERDETAILS equ <ACMDRIVERDETAILSA>
        PACMDRIVERDETAILS equ <PACMDRIVERDETAILSA>
        LPACMDRIVERDETAILS equ <LPACMDRIVERDETAILSA>
      endif
    else
      ;[...]
    endif
    ;  ACMDRIVERDETAILS.fccType
    ;  ACMDRIVERDETAILS_FCCTYPE_AUDIOCODEC: the FOURCC used in the fccType
    ;  field of the ACMDRIVERDETAILS structure to specify that this is an ACM
    ;  codec designed for audio.
    ;  ACMDRIVERDETAILS.fccComp
    ;  ACMDRIVERDETAILS_FCCCOMP_UNDEFINED: the FOURCC used in the fccComp
    ;  field of the ACMDRIVERDETAILS structure. this is currently an unused
    ;  field.
    ACMDRIVERDETAILS_FCCTYPE_AUDIOCODEC equ <mmioFOURCC('a', 'u', 'd', 'c')>
    ACMDRIVERDETAILS_FCCCOMP_UNDEFINED equ <mmioFOURCC('\0', '\0', '\0', '\0')>
    ;  the following flags are used to specify the type of conversion(s) that
    ;  the converter/codec/filter supports. these are placed in the fdwSupport
    ;  field of the ACMDRIVERDETAILS structure. note that a converter can
    ;  support one or more of these flags in any combination.
    ;  ACMDRIVERDETAILS_SUPPORTF_CODEC: this flag is set if the driver supports
    ;  conversions from one format tag to another format tag. for example, if a
    ;  converter compresses WAVE_FORMAT_PCM to WAVE_FORMAT_ADPCM, then this bit
    ;  should be set.
    ;  ACMDRIVERDETAILS_SUPPORTF_CONVERTER: this flags is set if the driver
    ;  supports conversions on the same format tag. as an example, the PCM
    ;  converter that is built into the ACM sets this bit (and only this bit)
    ;  because it converts only PCM formats (bits, sample rate).
    ;  ACMDRIVERDETAILS_SUPPORTF_FILTER: this flag is set if the driver supports
    ;  transformations on a single format. for example, a converter that changed
    ;  the 'volume' of PCM data would set this bit. 'echo' and 'reverb' are
    ;  also filter types.
    ;  ACMDRIVERDETAILS_SUPPORTF_HARDWARE: this flag is set if the driver supports
    ;  hardware input and/or output through a waveform device.
    ;  ACMDRIVERDETAILS_SUPPORTF_ASYNC: this flag is set if the driver supports
    ;  async conversions.
    ;  ACMDRIVERDETAILS_SUPPORTF_LOCAL: this flag is set _by the ACM_ if a
    ;  driver has been installed local to the current task. this flag is also
    ;  set in the fdwSupport argument to the enumeration callback function
    ;  for drivers.
    ;  ACMDRIVERDETAILS_SUPPORTF_DISABLED: this flag is set _by the ACM_ if a
    ;  driver has been disabled. this flag is also passed set in the fdwSupport
    ;  argument to the enumeration callback function for drivers.
    ACMDRIVERDETAILS_SUPPORTF_CODEC equ 00000001h
    ACMDRIVERDETAILS_SUPPORTF_CONVERTER equ 00000002h
    ACMDRIVERDETAILS_SUPPORTF_FILTER equ 00000004h
    ACMDRIVERDETAILS_SUPPORTF_HARDWARE equ 00000008h
    ACMDRIVERDETAILS_SUPPORTF_ASYNC equ 00000010h
    ACMDRIVERDETAILS_SUPPORTF_LOCAL equ 40000000h
    ACMDRIVERDETAILS_SUPPORTF_DISABLED equ 80000000h
    ifdef _WIN32
      acmDriverDetailsA proto WIN_STD_CALL_CONV :HACMDRIVERID, :LPACMDRIVERDETAILSA, :DWORD
      acmDriverDetailsW proto WIN_STD_CALL_CONV :HACMDRIVERID, :LPACMDRIVERDETAILSW, :DWORD
      ifdef _UNICODE
        acmDriverDetails equ <acmDriverDetailsW>
      else
        acmDriverDetails equ <acmDriverDetailsA>
      endif
    else
      ;[...]
    endif
    ;--------------------------------------------------------------------------;
    ;  ACM Format Tags
    ;--------------------------------------------------------------------------;
    ;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - ;
    ;  acmFormatTagDetails()
    ;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - ;
    ACMFORMATTAGDETAILS_FORMATTAG_CHARS equ 48
    ifdef _WIN32
      ACMFORMATTAGDETAILSA struct
        cbStruct DWORD ?
        dwFormatTagIndex DWORD ?
        dwFormatTag DWORD ?
        cbFormatSize DWORD ?
        fdwSupport DWORD ?
        cStandardFormats DWORD ?
        szFormatTag SBYTE ACMFORMATTAGDETAILS_FORMATTAG_CHARS dup (?)
      ACMFORMATTAGDETAILSA ends
      tACMFORMATTAGDETAILSA typedef ACMFORMATTAGDETAILSA
      PACMFORMATTAGDETAILSA typedef ptr ACMFORMATTAGDETAILSA
      LPACMFORMATTAGDETAILSA typedef ptr ACMFORMATTAGDETAILSA
      ACMFORMATTAGDETAILSW struct
        cbStruct DWORD ?
        dwFormatTagIndex DWORD ?
        dwFormatTag DWORD ?
        cbFormatSize DWORD ?
        fdwSupport DWORD ?
        cStandardFormats DWORD ?
        szFormatTag WORD ACMFORMATTAGDETAILS_FORMATTAG_CHARS dup (?)
      ACMFORMATTAGDETAILSW ends
      tACMFORMATTAGDETAILSW typedef ACMFORMATTAGDETAILSW
      PACMFORMATTAGDETAILSW typedef ptr ACMFORMATTAGDETAILSW
      LPACMFORMATTAGDETAILSW typedef ptr ACMFORMATTAGDETAILSW
      ifdef _UNICODE
        ACMFORMATTAGDETAILS equ <ACMFORMATTAGDETAILSW>
        PACMFORMATTAGDETAILS equ <PACMFORMATTAGDETAILSW>
        LPACMFORMATTAGDETAILS equ <LPACMFORMATTAGDETAILSW>
      else
        ACMFORMATTAGDETAILS equ <ACMFORMATTAGDETAILSA>
        PACMFORMATTAGDETAILS equ <PACMFORMATTAGDETAILSA>
        LPACMFORMATTAGDETAILS equ <LPACMFORMATTAGDETAILSA>
      endif
    else
      ;[...]
    endif
    ifdef _WIN32
      acmFormatTagDetailsA proto WIN_STD_CALL_CONV :HACMDRIVER, :LPACMFORMATTAGDETAILSA, :DWORD
      acmFormatTagDetailsW proto WIN_STD_CALL_CONV :HACMDRIVER, :LPACMFORMATTAGDETAILSW, :DWORD
      ifdef _UNICODE
        acmFormatTagDetails equ <acmFormatTagDetailsW>
      else
        acmFormatTagDetails equ <acmFormatTagDetailsA>
      endif
    else
      ;[...]
    endif
    ACM_FORMATTAGDETAILSF_INDEX equ 00000000h
    ACM_FORMATTAGDETAILSF_FORMATTAG equ 00000001h
    ACM_FORMATTAGDETAILSF_LARGESTSIZE equ 00000002h
    ACM_FORMATTAGDETAILSF_QUERYMASK equ 0000000Fh
    ;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - ;
    ;  acmFormatTagEnum()
    ;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - ;
    ifdef _WIN32
      TYPE_ACMFORMATTAGENUMCBA typedef proto WIN_STD_CALL_CONV :HACMDRIVERID, :LPACMFORMATTAGDETAILSA, :DWORD_PTR, :DWORD
      ACMFORMATTAGENUMCBA typedef ptr TYPE_ACMFORMATTAGENUMCBA

      acmFormatTagEnumA proto WIN_STD_CALL_CONV :HACMDRIVER, :LPACMFORMATTAGDETAILSA, :ACMFORMATTAGENUMCBA, :DWORD_PTR, :DWORD
      TYPE_ACMFORMATTAGENUMCBW typedef proto WIN_STD_CALL_CONV :HACMDRIVERID, :LPACMFORMATTAGDETAILSW, :DWORD_PTR, :DWORD
      ACMFORMATTAGENUMCBW typedef ptr TYPE_ACMFORMATTAGENUMCBW

      acmFormatTagEnumW proto WIN_STD_CALL_CONV :HACMDRIVER, :LPACMFORMATTAGDETAILSW, :ACMFORMATTAGENUMCBW, :DWORD_PTR, :DWORD
      ifdef _UNICODE
        ACMFORMATTAGENUMCB equ <ACMFORMATTAGENUMCBW>
        acmFormatTagEnum equ <acmFormatTagEnumW>
      else
        ACMFORMATTAGENUMCB equ <ACMFORMATTAGENUMCBA>
        acmFormatTagEnum equ <acmFormatTagEnumA>
      endif
    else
      ;[...]
    endif
    ;--------------------------------------------------------------------------;
    ;  ACM Formats
    ;--------------------------------------------------------------------------;
    ;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - ;
    ;  acmFormatDetails()
    ;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - ;
    ACMFORMATDETAILS_FORMAT_CHARS equ 128
    ifdef _WIN32
      ACMFORMATDETAILSA struct
        cbStruct DWORD ?
        dwFormatIndex DWORD ?
        dwFormatTag DWORD ?
        fdwSupport DWORD ?
        pwfx LPWAVEFORMATEX ?
        cbwfx DWORD ?
        szFormat SBYTE ACMFORMATDETAILS_FORMAT_CHARS dup (?)
      ACMFORMATDETAILSA ends
      tACMFORMATDETAILSA typedef ACMFORMATDETAILSA
      PACMFORMATDETAILSA typedef ptr ACMFORMATDETAILSA
      LPACMFORMATDETAILSA typedef ptr ACMFORMATDETAILSA
      ACMFORMATDETAILSW struct
        cbStruct DWORD ?
        dwFormatIndex DWORD ?
        dwFormatTag DWORD ?
        fdwSupport DWORD ?
        pwfx LPWAVEFORMATEX ?
        cbwfx DWORD ?
        szFormat WORD ACMFORMATDETAILS_FORMAT_CHARS dup (?)
      ACMFORMATDETAILSW ends
      tACMFORMATDETAILSW typedef ACMFORMATDETAILSW
      PACMFORMATDETAILSW typedef ptr ACMFORMATDETAILSW
      LPACMFORMATDETAILSW typedef ptr ACMFORMATDETAILSW
      ifdef _UNICODE
        ACMFORMATDETAILS equ <ACMFORMATDETAILSW>
        PACMFORMATDETAILS equ <PACMFORMATDETAILSW>
        LPACMFORMATDETAILS equ <LPACMFORMATDETAILSW>
      else
        ACMFORMATDETAILS equ <ACMFORMATDETAILSA>
        PACMFORMATDETAILS equ <PACMFORMATDETAILSA>
        LPACMFORMATDETAILS equ <LPACMFORMATDETAILSA>
      endif
    else
      ;[...]
    endif
    ifdef _WIN32
      acmFormatDetailsA proto WIN_STD_CALL_CONV :HACMDRIVER, :LPACMFORMATDETAILSA, :DWORD
      acmFormatDetailsW proto WIN_STD_CALL_CONV :HACMDRIVER, :LPACMFORMATDETAILSW, :DWORD
      ifdef _UNICODE
        acmFormatDetails equ <acmFormatDetailsW>
      else
        acmFormatDetails equ <acmFormatDetailsA>
      endif
    else
      ;[...]
    endif
    ACM_FORMATDETAILSF_INDEX equ 00000000h
    ACM_FORMATDETAILSF_FORMAT equ 00000001h
    ACM_FORMATDETAILSF_QUERYMASK equ 0000000Fh
    ;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - ;
    ;  acmFormatEnum()
    ;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - ;
    ifdef _WIN32
      TYPE_ACMFORMATENUMCBA typedef proto WIN_STD_CALL_CONV :HACMDRIVERID, :LPACMFORMATDETAILSA, :DWORD_PTR, :DWORD
      ACMFORMATENUMCBA typedef ptr TYPE_ACMFORMATENUMCBA

      acmFormatEnumA proto WIN_STD_CALL_CONV :HACMDRIVER, :LPACMFORMATDETAILSA, :ACMFORMATENUMCBA, :DWORD_PTR, :DWORD
      TYPE_ACMFORMATENUMCBW typedef proto WIN_STD_CALL_CONV :HACMDRIVERID, :LPACMFORMATDETAILSW, :DWORD_PTR, :DWORD
      ACMFORMATENUMCBW typedef ptr TYPE_ACMFORMATENUMCBW

      acmFormatEnumW proto WIN_STD_CALL_CONV :HACMDRIVER, :LPACMFORMATDETAILSW, :ACMFORMATENUMCBW, :DWORD_PTR, :DWORD
      ifdef _UNICODE
        ACMFORMATENUMCB equ <ACMFORMATENUMCBW>
        acmFormatEnum equ <acmFormatEnumW>
      else
        ACMFORMATENUMCB equ <ACMFORMATENUMCBA>
        acmFormatEnum equ <acmFormatEnumA>
      endif
    else
      ;[...]
    endif
    ACM_FORMATENUMF_WFORMATTAG equ 00010000h
    ACM_FORMATENUMF_NCHANNELS equ 00020000h
    ACM_FORMATENUMF_NSAMPLESPERSEC equ 00040000h
    ACM_FORMATENUMF_WBITSPERSAMPLE equ 00080000h
    ACM_FORMATENUMF_CONVERT equ 00100000h
    ACM_FORMATENUMF_SUGGEST equ 00200000h
    ACM_FORMATENUMF_HARDWARE equ 00400000h
    ACM_FORMATENUMF_INPUT equ 00800000h
    ACM_FORMATENUMF_OUTPUT equ 01000000h
    ;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - ;
    ;  acmFormatSuggest()
    ;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - ;
    acmFormatSuggest proto WIN_STD_CALL_CONV :HACMDRIVER, :LPWAVEFORMATEX, :LPWAVEFORMATEX, :DWORD, :DWORD
    ACM_FORMATSUGGESTF_WFORMATTAG equ 00010000h
    ACM_FORMATSUGGESTF_NCHANNELS equ 00020000h
    ACM_FORMATSUGGESTF_NSAMPLESPERSEC equ 00040000h
    ACM_FORMATSUGGESTF_WBITSPERSAMPLE equ 00080000h
    ACM_FORMATSUGGESTF_TYPEMASK equ 00FF0000h
    ;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - ;
    ;  acmFormatChoose()
    ;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - ;
    ifdef _WIN32
      ACMHELPMSGSTRINGA equ <"acmchoose_help">
      ACMHELPMSGSTRINGW equ <L("acmchoose_help")>
      ACMHELPMSGCONTEXTMENUA equ <"acmchoose_contextmenu">
      ACMHELPMSGCONTEXTMENUW equ <L("acmchoose_contextmenu")>
      ACMHELPMSGCONTEXTHELPA equ <"acmchoose_contexthelp">
      ACMHELPMSGCONTEXTHELPW equ <L("acmchoose_contexthelp")>
      ifdef _UNICODE
        ACMHELPMSGSTRING equ <ACMHELPMSGSTRINGW>
        ACMHELPMSGCONTEXTMENU equ <ACMHELPMSGCONTEXTMENUW>
        ACMHELPMSGCONTEXTHELP equ <ACMHELPMSGCONTEXTHELPW>
      else
        ACMHELPMSGSTRING equ <ACMHELPMSGSTRINGA>
        ACMHELPMSGCONTEXTMENU equ <ACMHELPMSGCONTEXTMENUA>
        ACMHELPMSGCONTEXTHELP equ <ACMHELPMSGCONTEXTHELPA>
      endif
    else
      ;[...]
    endif
    ;  MM_ACM_FORMATCHOOSE is sent to hook callbacks by the Format Chooser
    ;  Dialog...
    MM_ACM_FORMATCHOOSE equ (8000h)
    FORMATCHOOSE_MESSAGE equ 0
    FORMATCHOOSE_FORMATTAG_VERIFY equ (FORMATCHOOSE_MESSAGE + 0)
    FORMATCHOOSE_FORMAT_VERIFY equ (FORMATCHOOSE_MESSAGE + 1)
    FORMATCHOOSE_CUSTOM_VERIFY equ (FORMATCHOOSE_MESSAGE + 2)
    ifdef _WIN32
      TYPE_ACMFORMATCHOOSEHOOKPROCA typedef proto WIN_STD_CALL_CONV :HWND, :UINT, :WPARAM, :LPARAM
      ACMFORMATCHOOSEHOOKPROCA typedef ptr TYPE_ACMFORMATCHOOSEHOOKPROCA

      TYPE_ACMFORMATCHOOSEHOOKPROCW typedef proto WIN_STD_CALL_CONV :HWND, :UINT, :WPARAM, :LPARAM
      ACMFORMATCHOOSEHOOKPROCW typedef ptr TYPE_ACMFORMATCHOOSEHOOKPROCW

      ifdef _UNICODE
        ACMFORMATCHOOSEHOOKPROC equ <ACMFORMATCHOOSEHOOKPROCW>
      else
        ACMFORMATCHOOSEHOOKPROC equ <ACMFORMATCHOOSEHOOKPROCA>
      endif
    else
      ;[...]
    endif
    ifdef _WIN32
      ACMFORMATCHOOSEA struct
        cbStruct DWORD ?
        ; sizeof(ACMFORMATCHOOSE)
        fdwStyle DWORD ?
        ; chooser style flags
        hwndOwner HWND ?
        ; caller's window handle
        pwfx LPWAVEFORMATEX ?
        ; ptr to wfx buf to receive choice
        cbwfx DWORD ?
        ; size of mem buf for pwfx
        pszTitle =POINTER ?
        ; dialog box title bar
        szFormatTag SBYTE ACMFORMATTAGDETAILS_FORMATTAG_CHARS dup (?)
        szFormat SBYTE ACMFORMATDETAILS_FORMAT_CHARS dup (?)
        pszName POINTER ?
        ; custom name selection
        cchName DWORD ?
        ; size in chars of mem buf for pszName
        fdwEnum DWORD ?
        ; format enumeration restrictions
        pwfxEnum LPWAVEFORMATEX ?
        ; format describing restrictions
        hInstance HINSTANCE ?
        ; app instance containing dlg template
        pszTemplateName =POINTER ?
        ; custom template name
        lCustData LPARAM ?
        ; data passed to hook fn.
        pfnHook ACMFORMATCHOOSEHOOKPROCA ?
        ; ptr to hook function
      ACMFORMATCHOOSEA ends
      tACMFORMATCHOOSEA typedef ACMFORMATCHOOSEA
      PACMFORMATCHOOSEA typedef ptr ACMFORMATCHOOSEA
      LPACMFORMATCHOOSEA typedef ptr ACMFORMATCHOOSEA
      ACMFORMATCHOOSEW struct
        cbStruct DWORD ?
        ; sizeof(ACMFORMATCHOOSE)
        fdwStyle DWORD ?
        ; chooser style flags
        hwndOwner HWND ?
        ; caller's window handle
        pwfx LPWAVEFORMATEX ?
        ; ptr to wfx buf to receive choice
        cbwfx DWORD ?
        ; size of mem buf for pwfx
        pszTitle =POINTER ?
        ; dialog box title bar
        szFormatTag WORD ACMFORMATTAGDETAILS_FORMATTAG_CHARS dup (?)
        szFormat WORD ACMFORMATDETAILS_FORMAT_CHARS dup (?)
        pszName POINTER ?
        ; custom name selection
        cchName DWORD ?
        ; size in chars of mem buf for pszName
        fdwEnum DWORD ?
        ; format enumeration restrictions
        pwfxEnum LPWAVEFORMATEX ?
        ; format describing restrictions
        hInstance HINSTANCE ?
        ; app instance containing dlg template
        pszTemplateName =POINTER ?
        ; custom template name
        lCustData LPARAM ?
        ; data passed to hook fn.
        pfnHook ACMFORMATCHOOSEHOOKPROCW ?
        ; ptr to hook function
      ACMFORMATCHOOSEW ends
      tACMFORMATCHOOSEW typedef ACMFORMATCHOOSEW
      PACMFORMATCHOOSEW typedef ptr ACMFORMATCHOOSEW
      LPACMFORMATCHOOSEW typedef ptr ACMFORMATCHOOSEW
      ifdef _UNICODE
        ACMFORMATCHOOSE equ <ACMFORMATCHOOSEW>
        PACMFORMATCHOOSE equ <PACMFORMATCHOOSEW>
        LPACMFORMATCHOOSE equ <LPACMFORMATCHOOSEW>
      else
        ACMFORMATCHOOSE equ <ACMFORMATCHOOSEA>
        PACMFORMATCHOOSE equ <PACMFORMATCHOOSEA>
        LPACMFORMATCHOOSE equ <LPACMFORMATCHOOSEA>
      endif
    else
      ;[...]
    endif
    ;  ACMFORMATCHOOSE.fdwStyle
    ACMFORMATCHOOSE_STYLEF_SHOWHELP equ 00000004h
    ACMFORMATCHOOSE_STYLEF_ENABLEHOOK equ 00000008h
    ACMFORMATCHOOSE_STYLEF_ENABLETEMPLATE equ 00000010h
    ACMFORMATCHOOSE_STYLEF_ENABLETEMPLATEHANDLE equ 00000020h
    ACMFORMATCHOOSE_STYLEF_INITTOWFXSTRUCT equ 00000040h
    ACMFORMATCHOOSE_STYLEF_CONTEXTHELP equ 00000080h
    ifdef _WIN32
      acmFormatChooseA proto WIN_STD_CALL_CONV :LPACMFORMATCHOOSEA
      acmFormatChooseW proto WIN_STD_CALL_CONV :LPACMFORMATCHOOSEW
      ifdef _UNICODE
        acmFormatChoose equ <acmFormatChooseW>
      else
        acmFormatChoose equ <acmFormatChooseA>
      endif
    else
      ;[...]
    endif
    ;--------------------------------------------------------------------------;
    ;  ACM Filter Tags
    ;--------------------------------------------------------------------------;
    ;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - ;
    ;  acmFilterTagDetails()
    ;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - ;
    ACMFILTERTAGDETAILS_FILTERTAG_CHARS equ 48
    ifdef _WIN32
      ACMFILTERTAGDETAILSA struct
        cbStruct DWORD ?
        dwFilterTagIndex DWORD ?
        dwFilterTag DWORD ?
        cbFilterSize DWORD ?
        fdwSupport DWORD ?
        cStandardFilters DWORD ?
        szFilterTag SBYTE ACMFILTERTAGDETAILS_FILTERTAG_CHARS dup (?)
      ACMFILTERTAGDETAILSA ends
      tACMFILTERTAGDETAILSA typedef ACMFILTERTAGDETAILSA
      PACMFILTERTAGDETAILSA typedef ptr ACMFILTERTAGDETAILSA
      LPACMFILTERTAGDETAILSA typedef ptr ACMFILTERTAGDETAILSA
      ACMFILTERTAGDETAILSW struct
        cbStruct DWORD ?
        dwFilterTagIndex DWORD ?
        dwFilterTag DWORD ?
        cbFilterSize DWORD ?
        fdwSupport DWORD ?
        cStandardFilters DWORD ?
        szFilterTag WORD ACMFILTERTAGDETAILS_FILTERTAG_CHARS dup (?)
      ACMFILTERTAGDETAILSW ends
      tACMFILTERTAGDETAILSW typedef ACMFILTERTAGDETAILSW
      PACMFILTERTAGDETAILSW typedef ptr ACMFILTERTAGDETAILSW
      LPACMFILTERTAGDETAILSW typedef ptr ACMFILTERTAGDETAILSW
      ifdef _UNICODE
        ACMFILTERTAGDETAILS equ <ACMFILTERTAGDETAILSW>
        PACMFILTERTAGDETAILS equ <PACMFILTERTAGDETAILSW>
        LPACMFILTERTAGDETAILS equ <LPACMFILTERTAGDETAILSW>
      else
        ACMFILTERTAGDETAILS equ <ACMFILTERTAGDETAILSA>
        PACMFILTERTAGDETAILS equ <PACMFILTERTAGDETAILSA>
        LPACMFILTERTAGDETAILS equ <LPACMFILTERTAGDETAILSA>
      endif
    else
      ;[...]
    endif
    ifdef _WIN32
      acmFilterTagDetailsA proto WIN_STD_CALL_CONV :HACMDRIVER, :LPACMFILTERTAGDETAILSA, :DWORD
      acmFilterTagDetailsW proto WIN_STD_CALL_CONV :HACMDRIVER, :LPACMFILTERTAGDETAILSW, :DWORD
      ifdef _UNICODE
        acmFilterTagDetails equ <acmFilterTagDetailsW>
      else
        acmFilterTagDetails equ <acmFilterTagDetailsA>
      endif
    else
      ;[...]
    endif
    ACM_FILTERTAGDETAILSF_INDEX equ 00000000h
    ACM_FILTERTAGDETAILSF_FILTERTAG equ 00000001h
    ACM_FILTERTAGDETAILSF_LARGESTSIZE equ 00000002h
    ACM_FILTERTAGDETAILSF_QUERYMASK equ 0000000Fh
    ;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - ;
    ;  acmFilterTagEnum()
    ;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - ;
    ifdef _WIN32
      TYPE_ACMFILTERTAGENUMCBA typedef proto WIN_STD_CALL_CONV :HACMDRIVERID, :LPACMFILTERTAGDETAILSA, :DWORD_PTR, :DWORD
      ACMFILTERTAGENUMCBA typedef ptr TYPE_ACMFILTERTAGENUMCBA

      acmFilterTagEnumA proto WIN_STD_CALL_CONV :HACMDRIVER, :LPACMFILTERTAGDETAILSA, :ACMFILTERTAGENUMCBA, :DWORD_PTR, :DWORD
      TYPE_ACMFILTERTAGENUMCBW typedef proto WIN_STD_CALL_CONV :HACMDRIVERID, :LPACMFILTERTAGDETAILSW, :DWORD_PTR, :DWORD
      ACMFILTERTAGENUMCBW typedef ptr TYPE_ACMFILTERTAGENUMCBW

      acmFilterTagEnumW proto WIN_STD_CALL_CONV :HACMDRIVER, :LPACMFILTERTAGDETAILSW, :ACMFILTERTAGENUMCBW, :DWORD_PTR, :DWORD
      ifdef _UNICODE
        ACMFILTERTAGENUMCB equ <ACMFILTERTAGENUMCBW>
        acmFilterTagEnum equ <acmFilterTagEnumW>
      else
        ACMFILTERTAGENUMCB equ <ACMFILTERTAGENUMCBA>
        acmFilterTagEnum equ <acmFilterTagEnumA>
      endif
    else
      ;[...]
    endif
    ;--------------------------------------------------------------------------;
    ;  ACM Filters
    ;--------------------------------------------------------------------------;
    ;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - ;
    ;  acmFilterDetails()
    ;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - ;
    ACMFILTERDETAILS_FILTER_CHARS equ 128
    ifdef _WIN32
      ACMFILTERDETAILSA struct
        cbStruct DWORD ?
        dwFilterIndex DWORD ?
        dwFilterTag DWORD ?
        fdwSupport DWORD ?
        pwfltr LPWAVEFILTER ?
        cbwfltr DWORD ?
        szFilter SBYTE ACMFILTERDETAILS_FILTER_CHARS dup (?)
      ACMFILTERDETAILSA ends
      tACMFILTERDETAILSA typedef ACMFILTERDETAILSA
      PACMFILTERDETAILSA typedef ptr ACMFILTERDETAILSA
      LPACMFILTERDETAILSA typedef ptr ACMFILTERDETAILSA
      ACMFILTERDETAILSW struct
        cbStruct DWORD ?
        dwFilterIndex DWORD ?
        dwFilterTag DWORD ?
        fdwSupport DWORD ?
        pwfltr LPWAVEFILTER ?
        cbwfltr DWORD ?
        szFilter WORD ACMFILTERDETAILS_FILTER_CHARS dup (?)
      ACMFILTERDETAILSW ends
      tACMFILTERDETAILSW typedef ACMFILTERDETAILSW
      PACMFILTERDETAILSW typedef ptr ACMFILTERDETAILSW
      LPACMFILTERDETAILSW typedef ptr ACMFILTERDETAILSW
      ifdef _UNICODE
        ACMFILTERDETAILS equ <ACMFILTERDETAILSW>
        PACMFILTERDETAILS equ <PACMFILTERDETAILSW>
        LPACMFILTERDETAILS equ <LPACMFILTERDETAILSW>
      else
        ACMFILTERDETAILS equ <ACMFILTERDETAILSA>
        PACMFILTERDETAILS equ <PACMFILTERDETAILSA>
        LPACMFILTERDETAILS equ <LPACMFILTERDETAILSA>
      endif
    else
      ;[...]
    endif
    ifdef _WIN32
      acmFilterDetailsA proto WIN_STD_CALL_CONV :HACMDRIVER, :LPACMFILTERDETAILSA, :DWORD
      acmFilterDetailsW proto WIN_STD_CALL_CONV :HACMDRIVER, :LPACMFILTERDETAILSW, :DWORD
      ifdef _UNICODE
        acmFilterDetails equ <acmFilterDetailsW>
      else
        acmFilterDetails equ <acmFilterDetailsA>
      endif
    else
      ;[...]
    endif
    ACM_FILTERDETAILSF_INDEX equ 00000000h
    ACM_FILTERDETAILSF_FILTER equ 00000001h
    ACM_FILTERDETAILSF_QUERYMASK equ 0000000Fh
    ;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - ;
    ;  acmFilterEnum()
    ;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - ;
    ifdef _WIN32
      TYPE_ACMFILTERENUMCBA typedef proto WIN_STD_CALL_CONV :HACMDRIVERID, :LPACMFILTERDETAILSA, :DWORD_PTR, :DWORD
      ACMFILTERENUMCBA typedef ptr TYPE_ACMFILTERENUMCBA

      acmFilterEnumA proto WIN_STD_CALL_CONV :HACMDRIVER, :LPACMFILTERDETAILSA, :ACMFILTERENUMCBA, :DWORD_PTR, :DWORD
      TYPE_ACMFILTERENUMCBW typedef proto WIN_STD_CALL_CONV :HACMDRIVERID, :LPACMFILTERDETAILSW, :DWORD_PTR, :DWORD
      ACMFILTERENUMCBW typedef ptr TYPE_ACMFILTERENUMCBW

      acmFilterEnumW proto WIN_STD_CALL_CONV :HACMDRIVER, :LPACMFILTERDETAILSW, :ACMFILTERENUMCBW, :DWORD_PTR, :DWORD
      ifdef _UNICODE
        ACMFILTERENUMCB equ <ACMFILTERENUMCBW>
        acmFilterEnum equ <acmFilterEnumW>
      else
        ACMFILTERENUMCB equ <ACMFILTERENUMCBA>
        acmFilterEnum equ <acmFilterEnumA>
      endif
    else
      ;[...]
    endif
    ACM_FILTERENUMF_DWFILTERTAG equ 00010000h
    ;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - ;
    ;  acmFilterChoose()
    ;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - ;
    ;  MM_ACM_FILTERCHOOSE is sent to hook callbacks by the Filter Chooser
    ;  Dialog...
    MM_ACM_FILTERCHOOSE equ (8000h)
    FILTERCHOOSE_MESSAGE equ 0
    FILTERCHOOSE_FILTERTAG_VERIFY equ (FILTERCHOOSE_MESSAGE + 0)
    FILTERCHOOSE_FILTER_VERIFY equ (FILTERCHOOSE_MESSAGE + 1)
    FILTERCHOOSE_CUSTOM_VERIFY equ (FILTERCHOOSE_MESSAGE + 2)
    ifdef _WIN32
      TYPE_ACMFILTERCHOOSEHOOKPROCA typedef proto WIN_STD_CALL_CONV :HWND, :UINT, :WPARAM, :LPARAM
      ACMFILTERCHOOSEHOOKPROCA typedef ptr TYPE_ACMFILTERCHOOSEHOOKPROCA

      TYPE_ACMFILTERCHOOSEHOOKPROCW typedef proto WIN_STD_CALL_CONV :HWND, :UINT, :WPARAM, :LPARAM
      ACMFILTERCHOOSEHOOKPROCW typedef ptr TYPE_ACMFILTERCHOOSEHOOKPROCW

      ifdef _UNICODE
        ACMFILTERCHOOSEHOOKPROC equ <ACMFILTERCHOOSEHOOKPROCW>
      else
        ACMFILTERCHOOSEHOOKPROC equ <ACMFILTERCHOOSEHOOKPROCA>
      endif
    else
      ;[...]
    endif
    ;  ACMFILTERCHOOSE
    ifdef _WIN32
      ACMFILTERCHOOSEA struct
        cbStruct DWORD ?
        ; sizeof(ACMFILTERCHOOSE)
        fdwStyle DWORD ?
        ; chooser style flags
        hwndOwner HWND ?
        ; caller's window handle
        pwfltr LPWAVEFILTER ?
        ; ptr to wfltr buf to receive choice
        cbwfltr DWORD ?
        ; size of mem buf for pwfltr
        pszTitle =POINTER ?
        szFilterTag SBYTE ACMFILTERTAGDETAILS_FILTERTAG_CHARS dup (?)
        szFilter SBYTE ACMFILTERDETAILS_FILTER_CHARS dup (?)
        pszName POINTER ?
        ; custom name selection
        cchName DWORD ?
        ; size in chars of mem buf for pszName
        fdwEnum DWORD ?
        ; filter enumeration restrictions
        pwfltrEnum LPWAVEFILTER ?
        ; filter describing restrictions
        hInstance HINSTANCE ?
        ; app instance containing dlg template
        pszTemplateName =POINTER ?
        ; custom template name
        lCustData LPARAM ?
        ; data passed to hook fn.
        pfnHook ACMFILTERCHOOSEHOOKPROCA ?
        ; ptr to hook function
      ACMFILTERCHOOSEA ends
      tACMFILTERCHOOSEA typedef ACMFILTERCHOOSEA
      PACMFILTERCHOOSEA typedef ptr ACMFILTERCHOOSEA
      LPACMFILTERCHOOSEA typedef ptr ACMFILTERCHOOSEA
      ACMFILTERCHOOSEW struct
        cbStruct DWORD ?
        ; sizeof(ACMFILTERCHOOSE)
        fdwStyle DWORD ?
        ; chooser style flags
        hwndOwner HWND ?
        ; caller's window handle
        pwfltr LPWAVEFILTER ?
        ; ptr to wfltr buf to receive choice
        cbwfltr DWORD ?
        ; size of mem buf for pwfltr
        pszTitle =POINTER ?
        szFilterTag WORD ACMFILTERTAGDETAILS_FILTERTAG_CHARS dup (?)
        szFilter WORD ACMFILTERDETAILS_FILTER_CHARS dup (?)
        pszName POINTER ?
        ; custom name selection
        cchName DWORD ?
        ; size in chars of mem buf for pszName
        fdwEnum DWORD ?
        ; filter enumeration restrictions
        pwfltrEnum LPWAVEFILTER ?
        ; filter describing restrictions
        hInstance HINSTANCE ?
        ; app instance containing dlg template
        pszTemplateName =POINTER ?
        ; custom template name
        lCustData LPARAM ?
        ; data passed to hook fn.
        pfnHook ACMFILTERCHOOSEHOOKPROCW ?
        ; ptr to hook function
      ACMFILTERCHOOSEW ends
      tACMFILTERCHOOSEW typedef ACMFILTERCHOOSEW
      PACMFILTERCHOOSEW typedef ptr ACMFILTERCHOOSEW
      LPACMFILTERCHOOSEW typedef ptr ACMFILTERCHOOSEW
      ifdef _UNICODE
        ACMFILTERCHOOSE equ <ACMFILTERCHOOSEW>
        PACMFILTERCHOOSE equ <PACMFILTERCHOOSEW>
        LPACMFILTERCHOOSE equ <LPACMFILTERCHOOSEW>
      else
        ACMFILTERCHOOSE equ <ACMFILTERCHOOSEA>
        PACMFILTERCHOOSE equ <PACMFILTERCHOOSEA>
        LPACMFILTERCHOOSE equ <LPACMFILTERCHOOSEA>
      endif
    else
      ;[...]
    endif
    ;  ACMFILTERCHOOSE.fdwStyle
    ACMFILTERCHOOSE_STYLEF_SHOWHELP equ 00000004h
    ACMFILTERCHOOSE_STYLEF_ENABLEHOOK equ 00000008h
    ACMFILTERCHOOSE_STYLEF_ENABLETEMPLATE equ 00000010h
    ACMFILTERCHOOSE_STYLEF_ENABLETEMPLATEHANDLE equ 00000020h
    ACMFILTERCHOOSE_STYLEF_INITTOFILTERSTRUCT equ 00000040h
    ACMFILTERCHOOSE_STYLEF_CONTEXTHELP equ 00000080h
    ifdef _WIN32
      acmFilterChooseA proto WIN_STD_CALL_CONV :LPACMFILTERCHOOSEA
      acmFilterChooseW proto WIN_STD_CALL_CONV :LPACMFILTERCHOOSEW
      ifdef _UNICODE
        acmFilterChoose equ <acmFilterChooseW>
      else
        acmFilterChoose equ <acmFilterChooseA>
      endif
    else
      ;[...]
    endif
    ;--------------------------------------------------------------------------;
    ;  ACM Stream API's
    ;--------------------------------------------------------------------------;
    ;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - ;
    ;  acmStreamOpen()
    ;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - ;
    ifdef _WIN64
      _DRVRESERVED equ 15
    else
      _DRVRESERVED equ 10
    endif
    ; _WIN64
    ACMSTREAMHEADER struct
      cbStruct DWORD ?
      ; sizeof(ACMSTREAMHEADER)
      fdwStatus DWORD ?
      ; ACMSTREAMHEADER_STATUSF_*
      dwUser XWORD ?
      ; user instance data for hdr
      pbSrc LPBYTE ?
      cbSrcLength DWORD ?
      cbSrcLengthUsed DWORD ?
      dwSrcUser XWORD ?
      ; user instance data for src
      pbDst LPBYTE ?
      cbDstLength DWORD ?
      cbDstLengthUsed DWORD ?
      dwDstUser XWORD ?
      ; user instance data for dst
      dwReservedDriver DWORD _DRVRESERVED dup (?)
      ; driver reserved work space
    ACMSTREAMHEADER ends
    tACMSTREAMHEADER typedef ACMSTREAMHEADER
    PACMSTREAMHEADER typedef ptr ACMSTREAMHEADER
    LPACMSTREAMHEADER typedef ptr ACMSTREAMHEADER
    ;  ACMSTREAMHEADER.fdwStatus
    ;  ACMSTREAMHEADER_STATUSF_DONE: done bit for async conversions.
    ACMSTREAMHEADER_STATUSF_DONE equ 00010000h
    ACMSTREAMHEADER_STATUSF_PREPARED equ 00020000h
    ACMSTREAMHEADER_STATUSF_INQUEUE equ 00100000h
    acmStreamOpen proto WIN_STD_CALL_CONV :LPHACMSTREAM, :HACMDRIVER, :LPWAVEFORMATEX, :LPWAVEFORMATEX, :LPWAVEFILTER, :DWORD_PTR, :DWORD_PTR, :DWORD
    ; ACM_STREAMOPENF_* and CALLBACK_*
    ACM_STREAMOPENF_QUERY equ 00000001h
    ACM_STREAMOPENF_ASYNC equ 00000002h
    ACM_STREAMOPENF_NONREALTIME equ 00000004h
    ;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - ;
    ;  acmStreamClose()
    ;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - ;
    acmStreamClose proto WIN_STD_CALL_CONV :HACMSTREAM, :DWORD
    ;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - ;
    ;  acmStreamSize()
    ;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - ;
    acmStreamSize proto WIN_STD_CALL_CONV :HACMSTREAM, :DWORD, :LPDWORD, :DWORD
    ACM_STREAMSIZEF_SOURCE equ 00000000h
    ACM_STREAMSIZEF_DESTINATION equ 00000001h
    ACM_STREAMSIZEF_QUERYMASK equ 0000000Fh
    ;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - ;
    ;  acmStreamReset()
    ;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - ;
    acmStreamReset proto WIN_STD_CALL_CONV :HACMSTREAM, :DWORD
    ;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - ;
    ;  acmStreamMessage()
    ;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - ;
    acmStreamMessage proto WIN_STD_CALL_CONV :HACMSTREAM, :UINT, :LPARAM, :LPARAM
    ;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - ;
    ;  acmStreamConvert()
    ;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - ;
    acmStreamConvert proto WIN_STD_CALL_CONV :HACMSTREAM, :LPACMSTREAMHEADER, :DWORD
    ACM_STREAMCONVERTF_BLOCKALIGN equ 00000004h
    ACM_STREAMCONVERTF_START equ 00000010h
    ACM_STREAMCONVERTF_END equ 00000020h
    ;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - ;
    ;  acmStreamPrepareHeader()
    ;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - ;
    acmStreamPrepareHeader proto WIN_STD_CALL_CONV :HACMSTREAM, :LPACMSTREAMHEADER, :DWORD
    ;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - ;
    ;  acmStreamUnprepareHeader()
    ;- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - ;
    acmStreamUnprepareHeader proto WIN_STD_CALL_CONV :HACMSTREAM, :LPACMSTREAMHEADER, :DWORD
    ;* Revert to default packing *
    include poppack.inc
    ifdef __cplusplus
      ;[...]
    endif
    ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) *
  endif
  ;* _INC_ACM *
endif
