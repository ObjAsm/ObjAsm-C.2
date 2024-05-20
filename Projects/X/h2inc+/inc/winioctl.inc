;Include file created by h2inc+ version C.2.0 on (UTC) 20/05/2024 18:06:34
;(C) G. Friedrich April 2024
;Source file: d:\objasm\projects\x\h2inc+\h\um_10.0.22621.0\winioctl.h
;             Created on (UTC) 06/04/2024 06:16:03
;             Last modified on (UTC) 21/02/2024 18:15:26

ifdef DEFINE_GUID
  ; Make sure FAR is defined...
  ifndef FAR_
    ifdef _WIN32
      FAR_ equ <>
    else
      ;[...]
    endif
  endif
  DEFINE_GUID GUID_DEVINTERFACE_DISK, 53f56307h, 0b6bfh, 11d0h, 94h, 0f2h, 00h, 0a0h, 0c9h, 1eh, 0fbh, 8bh
  DEFINE_GUID GUID_DEVINTERFACE_CDROM, 53f56308h, 0b6bfh, 11d0h, 94h, 0f2h, 00h, 0a0h, 0c9h, 1eh, 0fbh, 8bh
  DEFINE_GUID GUID_DEVINTERFACE_PARTITION, 53f5630ah, 0b6bfh, 11d0h, 94h, 0f2h, 00h, 0a0h, 0c9h, 1eh, 0fbh, 8bh
  DEFINE_GUID GUID_DEVINTERFACE_TAPE, 53f5630bh, 0b6bfh, 11d0h, 94h, 0f2h, 00h, 0a0h, 0c9h, 1eh, 0fbh, 8bh
  DEFINE_GUID GUID_DEVINTERFACE_WRITEONCEDISK, 53f5630ch, 0b6bfh, 11d0h, 94h, 0f2h, 00h, 0a0h, 0c9h, 1eh, 0fbh, 8bh
  DEFINE_GUID GUID_DEVINTERFACE_VOLUME, 53f5630dh, 0b6bfh, 11d0h, 94h, 0f2h, 00h, 0a0h, 0c9h, 1eh, 0fbh, 8bh
  DEFINE_GUID GUID_DEVINTERFACE_MEDIUMCHANGER, 53f56310h, 0b6bfh, 11d0h, 94h, 0f2h, 00h, 0a0h, 0c9h, 1eh, 0fbh, 8bh
  DEFINE_GUID GUID_DEVINTERFACE_FLOPPY, 53f56311h, 0b6bfh, 11d0h, 94h, 0f2h, 00h, 0a0h, 0c9h, 1eh, 0fbh, 8bh
  DEFINE_GUID GUID_DEVINTERFACE_CDCHANGER, 53f56312h, 0b6bfh, 11d0h, 94h, 0f2h, 00h, 0a0h, 0c9h, 1eh, 0fbh, 8bh
  DEFINE_GUID GUID_DEVINTERFACE_STORAGEPORT, 2accfe60h, 0c130h, 11d2h, 0b0h, 82h, 00h, 0a0h, 0c9h, 1eh, 0fbh, 8bh
  DEFINE_GUID GUID_DEVINTERFACE_VMLUN, 6f416619h, 9f29h, 42a5h, 0b2h, 0bh, 37h, 0e2h, 19h, 0cah, 02h, 0b0h
  DEFINE_GUID GUID_DEVINTERFACE_SES, 1790c9ech, 47d5h, 4df3h, 0b5h, 0afh, 9ah, 0dfh, 3ch, 0f2h, 3eh, 48h
  DEFINE_GUID GUID_DEVINTERFACE_ZNSDISK, 0b87941c5h, 0ffdbh, 43c7h, 0b6h, 0b1h, 20h, 0b6h, 32h, 0f0h, 0b1h, 09h
  WDI_STORAGE_PREDICT_FAILURE_DPS_GUID equ { 0e9f2d03ah, 747ch, 41c2h, { 0bbh, 9ah, 02h, 0c6h, 2bh, 6dh, 5fh, 0cbh } } ;
  ; Interfaces to discover devices that are
  ; not reported  through conventional APIs
  DEFINE_GUID GUID_DEVINTERFACE_SERVICE_VOLUME, 6ead3d82h, 25ech, 46bch, 0b7h, 0fdh, 0c1h, 0f0h, 0dfh, 8fh, 50h, 37h
  DEFINE_GUID GUID_DEVINTERFACE_HIDDEN_VOLUME, 7f108a28h, 9833h, 4b3bh, 0b7h, 80h, 2ch, 6bh, 5fh, 0a5h, 0c0h, 62h
  ; Interface to register for RPMB commands
  DEFINE_GUID GUID_DEVINTERFACE_UNIFIED_ACCESS_RPMB, 27447c21h, 0bcc3h, 4d07h, 0a0h, 5bh, 0a3h, 39h, 5bh, 0b4h, 0eeh, 0e7h
  ; This interface represents a physical persistent memory device, such as an NVDIMM.
  ; {4283609D-4DC2-43BE-BBB4-4F15DFCE2C61}
  DEFINE_GUID GUID_DEVINTERFACE_SCM_PHYSICAL_DEVICE, 4283609dh, 4dc2h, 43beh, 0bbh, 0b4h, 4fh, 15h, 0dfh, 0ceh, 2ch, 61h
  ; When a physical device driver detects a change in the health status of a physical device,
  ; it triggers a PNP custom event (through TARGET_DEVICE_CUSTOM_NOTIFICATION) to alert any
  ; registered components. The custom event's GUID is GUID_SCM_PD_HEALTH_NOTIFICATION
  ; and its payload is SCM_PD_HEALTH_NOTIFICATION_DATA
  ; {9DA2D386-72F5-4EE3-8155-ECA0678E3B06}
  DEFINE_GUID GUID_SCM_PD_HEALTH_NOTIFICATION, 9da2d386h, 72f5h, 4ee3h, 81h, 55h, 0ech, 0a0h, 67h, 8eh, 3bh, 6h
  ; The passthrough protocol GUID for INVDIMM devices. The application and the driver use this value
  ; for the "ProtocolGuid" field of the SCM_PD_PASSTHROUGH_INPUT and SCM_PD_PASSTHROUGH_OUTPUT structures.
  ; {4309AC30-0D11-11E4-9191-0800200C9A66}
  DEFINE_GUID GUID_SCM_PD_PASSTHROUGH_INVDIMM, 4309AC30h, 0D11h, 11E4h, 91h, 91h, 08h, 00h, 20h, 0Ch, 9Ah, 66h
  ; {86E0D1E0-8089-11D0-9CE4-08003E301F73}
  DEFINE_GUID GUID_DEVINTERFACE_COMPORT, 86E0D1E0h, 8089h, 11D0h, 9Ch, 0E4h, 08h, 00h, 3Eh, 30h, 1Fh, 73h
  ; {4D36E978-E325-11CE-BFC1-08002BE10318}
  DEFINE_GUID GUID_DEVINTERFACE_SERENUM_BUS_ENUMERATOR, 4D36E978h, 0E325h, 11CEh, 0BFh, 0C1h, 08h, 00h, 2Bh, 0E1h, 03h, 18h
  ; Obsolete device interface class GUID names.
  ; (use of above GUID_DEVINTERFACE_* names is recommended).
  DiskClassGuid equ <GUID_DEVINTERFACE_DISK>
  CdRomClassGuid equ <GUID_DEVINTERFACE_CDROM>
  PartitionClassGuid equ <GUID_DEVINTERFACE_PARTITION>
  TapeClassGuid equ <GUID_DEVINTERFACE_TAPE>
  WriteOnceDiskClassGuid equ <GUID_DEVINTERFACE_WRITEONCEDISK>
  VolumeClassGuid equ <GUID_DEVINTERFACE_VOLUME>
  MediumChangerClassGuid equ <GUID_DEVINTERFACE_MEDIUMCHANGER>
  FloppyClassGuid equ <GUID_DEVINTERFACE_FLOPPY>
  CdChangerClassGuid equ <GUID_DEVINTERFACE_CDCHANGER>
  StoragePortClassGuid equ <GUID_DEVINTERFACE_STORAGEPORT>
  HiddenVolumeClassGuid equ <GUID_DEVINTERFACE_HIDDEN_VOLUME>
  GUID_CLASS_COMPORT equ <GUID_DEVINTERFACE_COMPORT>
  GUID_SERENUM_BUS_ENUMERATOR equ <GUID_DEVINTERFACE_SERENUM_BUS_ENUMERATOR>
endif
; DEFINE_GUID
; Interface DEVPROPKEY
; need these DEVPROPKEYs outside conditional includes so that user can
;   #include <winioctl.h> in precompiled header
;   #include <devpropdef.h> in a single source file
;   #include <winioctl.h> in that source file a second time to instantiate the DEVPROPKEYs
ifdef DEFINE_DEVPROPKEY
  ; Properties associated with the volume interface.
  DEFINE_DEVPROPKEY proto WIN_STD_CALL_CONV :DEVPKEY_Storage_Portable, :4d1ebee8h, :803h, :4774h, :98h, :42h, :0b7h, :7dh, :0b5h, :2h, :65h, :0e9h, :2
  ; DEVPROP_TYPE_BOOLEAN
  DEFINE_DEVPROPKEY proto WIN_STD_CALL_CONV :DEVPKEY_Storage_Removable_Media, :4d1ebee8h, :803h, :4774h, :98h, :42h, :0b7h, :7dh, :0b5h, :2h, :65h, :0e9h, :3
  ; DEVPROP_TYPE_BOOLEAN
  DEFINE_DEVPROPKEY proto WIN_STD_CALL_CONV :DEVPKEY_Storage_System_Critical, :4d1ebee8h, :803h, :4774h, :98h, :42h, :0b7h, :7dh, :0b5h, :2h, :65h, :0e9h, :4
  ; DEVPROP_TYPE_BOOLEAN
  DEFINE_DEVPROPKEY proto WIN_STD_CALL_CONV :DEVPKEY_Storage_Disk_Number, :4d1ebee8h, :803h, :4774h, :98h, :42h, :0b7h, :7dh, :0b5h, :2h, :65h, :0e9h, :5
  ; DEVPROP_TYPE_UINT32
  DEFINE_DEVPROPKEY proto WIN_STD_CALL_CONV :DEVPKEY_Storage_Partition_Number, :4d1ebee8h, :803h, :4774h, :98h, :42h, :0b7h, :7dh, :0b5h, :2h, :65h, :0e9h, :6
  ; DEVPROP_TYPE_UINT32
  DEFINE_DEVPROPKEY proto WIN_STD_CALL_CONV :DEVPKEY_Storage_Mbr_Type, :4d1ebee8h, :803h, :4774h, :98h, :42h, :0b7h, :7dh, :0b5h, :2h, :65h, :0e9h, :7
  ; DEVPROP_TYPE_BYTE
  DEFINE_DEVPROPKEY proto WIN_STD_CALL_CONV :DEVPKEY_Storage_Gpt_Type, :4d1ebee8h, :803h, :4774h, :98h, :42h, :0b7h, :7dh, :0b5h, :2h, :65h, :0e9h, :8
  ; DEVPROP_TYPE_GUID
  DEFINE_DEVPROPKEY proto WIN_STD_CALL_CONV :DEVPKEY_Storage_Gpt_Name, :4d1ebee8h, :803h, :4774h, :98h, :42h, :0b7h, :7dh, :0b5h, :2h, :65h, :0e9h, :9
  ; DEVPROP_TYPE_STRING
endif
; DEFINE_DEVPROPKEY
ifndef _WINIOCTL_
  _WINIOCTL_ equ <>
  if _MSC_VER ge 1200
    ; nonstandard extension used : nameless struct/union
    ; padding added after data member
  endif
  ifndef _DEVIOCTL_
    _DEVIOCTL_ equ <>
    ; begin_ntddk begin_wdm begin_nthal begin_ntifs
    ; Define the various device type values.  Note that values used by Microsoft
    ; Corporation are in the range 0-32767, and 32768-65535 are reserved for use
    ; by customers.
    DEVICE_TYPE equ <DWORD>
    FILE_DEVICE_BEEP equ 00000001h
    FILE_DEVICE_CD_ROM equ 00000002h
    FILE_DEVICE_CD_ROM_FILE_SYSTEM equ 00000003h
    FILE_DEVICE_CONTROLLER equ 00000004h
    FILE_DEVICE_DATALINK equ 00000005h
    FILE_DEVICE_DFS equ 00000006h
    FILE_DEVICE_DISK equ 00000007h
    FILE_DEVICE_DISK_FILE_SYSTEM equ 00000008h
    FILE_DEVICE_FILE_SYSTEM equ 00000009h
    FILE_DEVICE_INPORT_PORT equ 0000000ah
    FILE_DEVICE_KEYBOARD equ 0000000bh
    FILE_DEVICE_MAILSLOT equ 0000000ch
    FILE_DEVICE_MIDI_IN equ 0000000dh
    FILE_DEVICE_MIDI_OUT equ 0000000eh
    FILE_DEVICE_MOUSE equ 0000000fh
    FILE_DEVICE_MULTI_UNC_PROVIDER equ 00000010h
    FILE_DEVICE_NAMED_PIPE equ 00000011h
    FILE_DEVICE_NETWORK equ 00000012h
    FILE_DEVICE_NETWORK_BROWSER equ 00000013h
    FILE_DEVICE_NETWORK_FILE_SYSTEM equ 00000014h
    FILE_DEVICE_NULL equ 00000015h
    FILE_DEVICE_PARALLEL_PORT equ 00000016h
    FILE_DEVICE_PHYSICAL_NETCARD equ 00000017h
    FILE_DEVICE_PRINTER equ 00000018h
    FILE_DEVICE_SCANNER equ 00000019h
    FILE_DEVICE_SERIAL_MOUSE_PORT equ 0000001ah
    FILE_DEVICE_SERIAL_PORT equ 0000001bh
    FILE_DEVICE_SCREEN equ 0000001ch
    FILE_DEVICE_SOUND equ 0000001dh
    FILE_DEVICE_STREAMS equ 0000001eh
    FILE_DEVICE_TAPE equ 0000001fh
    FILE_DEVICE_TAPE_FILE_SYSTEM equ 00000020h
    FILE_DEVICE_TRANSPORT equ 00000021h
    FILE_DEVICE_UNKNOWN equ 00000022h
    FILE_DEVICE_VIDEO equ 00000023h
    FILE_DEVICE_VIRTUAL_DISK equ 00000024h
    FILE_DEVICE_WAVE_IN equ 00000025h
    FILE_DEVICE_WAVE_OUT equ 00000026h
    FILE_DEVICE_8042_PORT equ 00000027h
    FILE_DEVICE_NETWORK_REDIRECTOR equ 00000028h
    FILE_DEVICE_BATTERY equ 00000029h
    FILE_DEVICE_BUS_EXTENDER equ 0000002ah
    FILE_DEVICE_MODEM equ 0000002bh
    FILE_DEVICE_VDM equ 0000002ch
    FILE_DEVICE_MASS_STORAGE equ 0000002dh
    FILE_DEVICE_SMB equ 0000002eh
    FILE_DEVICE_KS equ 0000002fh
    FILE_DEVICE_CHANGER equ 00000030h
    FILE_DEVICE_SMARTCARD equ 00000031h
    FILE_DEVICE_ACPI equ 00000032h
    FILE_DEVICE_DVD equ 00000033h
    FILE_DEVICE_FULLSCREEN_VIDEO equ 00000034h
    FILE_DEVICE_DFS_FILE_SYSTEM equ 00000035h
    FILE_DEVICE_DFS_VOLUME equ 00000036h
    FILE_DEVICE_SERENUM equ 00000037h
    FILE_DEVICE_TERMSRV equ 00000038h
    FILE_DEVICE_KSEC equ 00000039h
    FILE_DEVICE_FIPS equ 0000003Ah
    FILE_DEVICE_INFINIBAND equ 0000003Bh
    FILE_DEVICE_VMBUS equ 0000003Eh
    FILE_DEVICE_CRYPT_PROVIDER equ 0000003Fh
    FILE_DEVICE_WPD equ 00000040h
    FILE_DEVICE_BLUETOOTH equ 00000041h
    FILE_DEVICE_MT_COMPOSITE equ 00000042h
    FILE_DEVICE_MT_TRANSPORT equ 00000043h
    FILE_DEVICE_BIOMETRIC equ 00000044h
    FILE_DEVICE_PMI equ 00000045h
    FILE_DEVICE_EHSTOR equ 00000046h
    FILE_DEVICE_DEVAPI equ 00000047h
    FILE_DEVICE_GPIO equ 00000048h
    FILE_DEVICE_USBEX equ 00000049h
    FILE_DEVICE_CONSOLE equ 00000050h
    FILE_DEVICE_NFP equ 00000051h
    FILE_DEVICE_SYSENV equ 00000052h
    FILE_DEVICE_VIRTUAL_BLOCK equ 00000053h
    FILE_DEVICE_POINT_OF_SERVICE equ 00000054h
    FILE_DEVICE_STORAGE_REPLICATION equ 00000055h
    FILE_DEVICE_TRUST_ENV equ 00000056h
    FILE_DEVICE_UCM equ 00000057h
    FILE_DEVICE_UCMTCPCI equ 00000058h
    FILE_DEVICE_PERSISTENT_MEMORY equ 00000059h
    FILE_DEVICE_NVDIMM equ 0000005ah
    FILE_DEVICE_HOLOGRAPHIC equ 0000005bh
    FILE_DEVICE_SDFXHCI equ 0000005ch
    FILE_DEVICE_UCMUCSI equ 0000005dh
    FILE_DEVICE_PRM equ 0000005eh
    FILE_DEVICE_EVENT_COLLECTOR equ 0000005fh
    FILE_DEVICE_USB4 equ 00000060h
    FILE_DEVICE_SOUNDWIRE equ 00000061h
    ; Macro definition for defining IOCTL and FSCTL function control codes.  Note
    ; that function codes 0-2047 are reserved for Microsoft Corporation, and
    ; 2048-4095 are reserved for customers.
    CTL_CODE macro DeviceType, Function, Method_, Access
      exitm <(((DeviceType) shl 16) or ((Access) shl 14) or ((Function) shl 2) or (Method_))>
    endm
    ; Macro to extract device type out of the device io control code
    DEVICE_TYPE_FROM_CTL_CODE macro ctrlCode
      exitm <(((ctrlCode and 0ffff0000h)) shr 16)>
    endm
    ; Macro to extract buffering method out of the device io control code
    METHOD_FROM_CTL_CODE macro ctrlCode
      exitm <((ctrlCode and 3))>
    endm
    ; Define the method codes for how buffers are passed for I/O and FS controls
    METHOD_BUFFERED equ 0
    METHOD_IN_DIRECT equ 1
    METHOD_OUT_DIRECT equ 2
    METHOD_NEITHER equ 3
    ; Define some easier to comprehend aliases:
    ;   METHOD_DIRECT_TO_HARDWARE (writes, aka METHOD_IN_DIRECT)
    ;   METHOD_DIRECT_FROM_HARDWARE (reads, aka METHOD_OUT_DIRECT)
    METHOD_DIRECT_TO_HARDWARE equ <METHOD_IN_DIRECT>
    METHOD_DIRECT_FROM_HARDWARE equ <METHOD_OUT_DIRECT>
    ; Define the access check value for any access
    ; The FILE_READ_ACCESS and FILE_WRITE_ACCESS constants are also defined in
    ; ntioapi.h as FILE_READ_DATA and FILE_WRITE_DATA. The values for these
    ; constants *MUST* always be in sync.
    ; FILE_SPECIAL_ACCESS is checked by the NT I/O system the same as FILE_ANY_ACCESS.
    ; The file systems, however, may add additional access checks for I/O and FS controls
    ; that use this value.
    FILE_ANY_ACCESS equ 0
    FILE_SPECIAL_ACCESS equ <(FILE_ANY_ACCESS)>
    FILE_READ_ACCESS equ (0001h); file & pipe

    FILE_WRITE_ACCESS equ (0002h); file & pipe

    ; end_ntddk end_wdm end_nthal end_ntifs
  endif
  ; _DEVIOCTL_
  ifndef _NTDDSTOR_H_
    _NTDDSTOR_H_ equ <>
    if Defined(__cplusplus) and  not Defined(__ALT_GENERATOR__)
      ;[...]
    endif
    if _MSC_VER ge 1200
      ; padding added after data member
    endif
    ; IoControlCode values for storage devices
    IOCTL_STORAGE_BASE equ <FILE_DEVICE_MASS_STORAGE>
    ; The following device control codes are common for all class drivers.  They
    ; should be used in place of the older IOCTL_DISK, IOCTL_CDROM and IOCTL_TAPE
    ; common codes
    IOCTL_STORAGE_CHECK_VERIFY equ CTL_CODE(IOCTL_STORAGE_BASE, 0200h, METHOD_BUFFERED, FILE_READ_ACCESS)
    IOCTL_STORAGE_CHECK_VERIFY2 equ CTL_CODE(IOCTL_STORAGE_BASE, 0200h, METHOD_BUFFERED, FILE_ANY_ACCESS)
    IOCTL_STORAGE_MEDIA_REMOVAL equ CTL_CODE(IOCTL_STORAGE_BASE, 0201h, METHOD_BUFFERED, FILE_READ_ACCESS)
    IOCTL_STORAGE_EJECT_MEDIA equ CTL_CODE(IOCTL_STORAGE_BASE, 0202h, METHOD_BUFFERED, FILE_READ_ACCESS)
    IOCTL_STORAGE_LOAD_MEDIA equ CTL_CODE(IOCTL_STORAGE_BASE, 0203h, METHOD_BUFFERED, FILE_READ_ACCESS)
    IOCTL_STORAGE_LOAD_MEDIA2 equ CTL_CODE(IOCTL_STORAGE_BASE, 0203h, METHOD_BUFFERED, FILE_ANY_ACCESS)
    IOCTL_STORAGE_RESERVE equ CTL_CODE(IOCTL_STORAGE_BASE, 0204h, METHOD_BUFFERED, FILE_READ_ACCESS)
    IOCTL_STORAGE_RELEASE equ CTL_CODE(IOCTL_STORAGE_BASE, 0205h, METHOD_BUFFERED, FILE_READ_ACCESS)
    IOCTL_STORAGE_FIND_NEW_DEVICES equ CTL_CODE(IOCTL_STORAGE_BASE, 0206h, METHOD_BUFFERED, FILE_READ_ACCESS)
    IOCTL_STORAGE_EJECTION_CONTROL equ CTL_CODE(IOCTL_STORAGE_BASE, 0250h, METHOD_BUFFERED, FILE_ANY_ACCESS)
    IOCTL_STORAGE_MCN_CONTROL equ CTL_CODE(IOCTL_STORAGE_BASE, 0251h, METHOD_BUFFERED, FILE_ANY_ACCESS)
    IOCTL_STORAGE_GET_MEDIA_TYPES equ CTL_CODE(IOCTL_STORAGE_BASE, 0300h, METHOD_BUFFERED, FILE_ANY_ACCESS)
    IOCTL_STORAGE_GET_MEDIA_TYPES_EX equ CTL_CODE(IOCTL_STORAGE_BASE, 0301h, METHOD_BUFFERED, FILE_ANY_ACCESS)
    IOCTL_STORAGE_GET_MEDIA_SERIAL_NUMBER equ CTL_CODE(IOCTL_STORAGE_BASE, 0304h, METHOD_BUFFERED, FILE_ANY_ACCESS)
    IOCTL_STORAGE_GET_HOTPLUG_INFO equ CTL_CODE(IOCTL_STORAGE_BASE, 0305h, METHOD_BUFFERED, FILE_ANY_ACCESS)
    IOCTL_STORAGE_SET_HOTPLUG_INFO equ CTL_CODE(IOCTL_STORAGE_BASE, 0306h, METHOD_BUFFERED, FILE_READ_ACCESS or FILE_WRITE_ACCESS)
    IOCTL_STORAGE_RESET_BUS equ CTL_CODE(IOCTL_STORAGE_BASE, 0400h, METHOD_BUFFERED, FILE_READ_ACCESS)
    IOCTL_STORAGE_RESET_DEVICE equ CTL_CODE(IOCTL_STORAGE_BASE, 0401h, METHOD_BUFFERED, FILE_READ_ACCESS)
    IOCTL_STORAGE_BREAK_RESERVATION equ CTL_CODE(IOCTL_STORAGE_BASE, 0405h, METHOD_BUFFERED, FILE_READ_ACCESS)
    IOCTL_STORAGE_PERSISTENT_RESERVE_IN equ CTL_CODE(IOCTL_STORAGE_BASE, 0406h, METHOD_BUFFERED, FILE_READ_ACCESS)
    IOCTL_STORAGE_PERSISTENT_RESERVE_OUT equ CTL_CODE(IOCTL_STORAGE_BASE, 0407h, METHOD_BUFFERED, FILE_READ_ACCESS or FILE_WRITE_ACCESS)
    IOCTL_STORAGE_GET_DEVICE_NUMBER equ CTL_CODE(IOCTL_STORAGE_BASE, 0420h, METHOD_BUFFERED, FILE_ANY_ACCESS)
    ; This IOCTL includes the same information as IOCTL_STORAGE_GET_DEVICE_NUMBER, plus the device GUID.
    IOCTL_STORAGE_GET_DEVICE_NUMBER_EX equ CTL_CODE(IOCTL_STORAGE_BASE, 0421h, METHOD_BUFFERED, FILE_ANY_ACCESS)
    IOCTL_STORAGE_PREDICT_FAILURE equ CTL_CODE(IOCTL_STORAGE_BASE, 0440h, METHOD_BUFFERED, FILE_ANY_ACCESS)
    IOCTL_STORAGE_FAILURE_PREDICTION_CONFIG equ CTL_CODE(IOCTL_STORAGE_BASE, 0441h, METHOD_BUFFERED, FILE_ANY_ACCESS)
    ; This IOCTL retrieves reliability counters for a device.
    IOCTL_STORAGE_GET_COUNTERS equ CTL_CODE(IOCTL_STORAGE_BASE, 442h, METHOD_BUFFERED, FILE_ANY_ACCESS)
    IOCTL_STORAGE_READ_CAPACITY equ CTL_CODE(IOCTL_STORAGE_BASE, 0450h, METHOD_BUFFERED, FILE_READ_ACCESS)
    ; IOCTLs 0x0463 to 0x0468 reserved for dependent disk support.
    ; IOCTLs 0x0470 to 0x047f reserved for device and stack telemetry interfaces
    IOCTL_STORAGE_GET_DEVICE_TELEMETRY equ CTL_CODE(IOCTL_STORAGE_BASE, 0470h, METHOD_BUFFERED, FILE_READ_ACCESS or FILE_WRITE_ACCESS)
    IOCTL_STORAGE_DEVICE_TELEMETRY_NOTIFY equ CTL_CODE(IOCTL_STORAGE_BASE, 0471h, METHOD_BUFFERED, FILE_READ_ACCESS or FILE_WRITE_ACCESS)
    IOCTL_STORAGE_DEVICE_TELEMETRY_QUERY_CAPS equ CTL_CODE(IOCTL_STORAGE_BASE, 0472h, METHOD_BUFFERED, FILE_READ_ACCESS or FILE_WRITE_ACCESS)
    IOCTL_STORAGE_GET_DEVICE_TELEMETRY_RAW equ CTL_CODE(IOCTL_STORAGE_BASE, 0473h, METHOD_BUFFERED, FILE_READ_ACCESS or FILE_WRITE_ACCESS)
    IOCTL_STORAGE_SET_TEMPERATURE_THRESHOLD equ CTL_CODE(IOCTL_STORAGE_BASE, 0480h, METHOD_BUFFERED, FILE_READ_ACCESS or FILE_WRITE_ACCESS)
    IOCTL_STORAGE_PROTOCOL_COMMAND equ CTL_CODE(IOCTL_STORAGE_BASE, 04F0h, METHOD_BUFFERED, FILE_READ_ACCESS or FILE_WRITE_ACCESS)
    IOCTL_STORAGE_SET_PROPERTY equ CTL_CODE(IOCTL_STORAGE_BASE, 04FFh, METHOD_BUFFERED, FILE_WRITE_ACCESS)
    IOCTL_STORAGE_QUERY_PROPERTY equ CTL_CODE(IOCTL_STORAGE_BASE, 0500h, METHOD_BUFFERED, FILE_ANY_ACCESS)
    IOCTL_STORAGE_MANAGE_DATA_SET_ATTRIBUTES equ CTL_CODE(IOCTL_STORAGE_BASE, 0501h, METHOD_BUFFERED, FILE_WRITE_ACCESS)
    IOCTL_STORAGE_GET_LB_PROVISIONING_MAP_RESOURCES equ CTL_CODE(IOCTL_STORAGE_BASE, 0502h, METHOD_BUFFERED, FILE_READ_ACCESS)
    ; IOCTLs 0x0503 to 0x0580 reserved for Enhanced Storage devices.
    ; This IOCTL offloads the erasure process to the storage device. There is no guarantee as to the successful
    ; deletion or recoverability of the data on the storage device after command completion. This IOCTL is limited
    ; to data disks in regular Windows. In WinPE, this IOCTL is supported for both boot and data disks.
    ; This IOCTL has an optional input and returns no output other than status. Callers should first call
    ; FSCTL_LOCK_VOLUME before calling this ioctl to flush out cached data in upper layers. No waiting of outstanding
    ; request completion is done before issuing the command to the device.
    IOCTL_STORAGE_REINITIALIZE_MEDIA equ CTL_CODE(IOCTL_STORAGE_BASE, 0590h, METHOD_BUFFERED, FILE_WRITE_ACCESS)
    ; IOCTLs for bandwidth contracts on storage devices
    ; (Move this to ntddsfio if we decide to use a new base)
    IOCTL_STORAGE_GET_BC_PROPERTIES equ CTL_CODE(IOCTL_STORAGE_BASE, 0600h, METHOD_BUFFERED, FILE_READ_ACCESS)
    IOCTL_STORAGE_ALLOCATE_BC_STREAM equ CTL_CODE(IOCTL_STORAGE_BASE, 0601h, METHOD_BUFFERED, FILE_READ_ACCESS or FILE_WRITE_ACCESS)
    IOCTL_STORAGE_FREE_BC_STREAM equ CTL_CODE(IOCTL_STORAGE_BASE, 0602h, METHOD_BUFFERED, FILE_READ_ACCESS or FILE_WRITE_ACCESS)
    ; IOCTL to check for priority support
    IOCTL_STORAGE_CHECK_PRIORITY_HINT_SUPPORT equ CTL_CODE(IOCTL_STORAGE_BASE, 0620h, METHOD_BUFFERED, FILE_ANY_ACCESS)
    ; IOCTL for data integrity check support
    IOCTL_STORAGE_START_DATA_INTEGRITY_CHECK equ CTL_CODE(IOCTL_STORAGE_BASE, 0621h, METHOD_BUFFERED, FILE_READ_ACCESS or FILE_WRITE_ACCESS)
    IOCTL_STORAGE_STOP_DATA_INTEGRITY_CHECK equ CTL_CODE(IOCTL_STORAGE_BASE, 0622h, METHOD_BUFFERED, FILE_READ_ACCESS or FILE_WRITE_ACCESS)
    ; These ioctl codes are obsolete.  They are defined here to avoid resuing them
    ; and to allow class drivers to respond to them more easily.
    OBSOLETE_IOCTL_STORAGE_RESET_BUS equ CTL_CODE(IOCTL_STORAGE_BASE, 0400h, METHOD_BUFFERED, FILE_READ_ACCESS or FILE_WRITE_ACCESS)
    OBSOLETE_IOCTL_STORAGE_RESET_DEVICE equ CTL_CODE(IOCTL_STORAGE_BASE, 0401h, METHOD_BUFFERED, FILE_READ_ACCESS or FILE_WRITE_ACCESS)
    ; IOCTLs 0x0643 to 0x0655 reserved for VHD disk support.
    ; IOCTLs for firmware upgrade on storage devices
    IOCTL_STORAGE_FIRMWARE_GET_INFO equ CTL_CODE(IOCTL_STORAGE_BASE, 0700h, METHOD_BUFFERED, FILE_ANY_ACCESS)
    IOCTL_STORAGE_FIRMWARE_DOWNLOAD equ CTL_CODE(IOCTL_STORAGE_BASE, 0701h, METHOD_BUFFERED, FILE_READ_ACCESS or FILE_WRITE_ACCESS)
    IOCTL_STORAGE_FIRMWARE_ACTIVATE equ CTL_CODE(IOCTL_STORAGE_BASE, 0702h, METHOD_BUFFERED, FILE_READ_ACCESS or FILE_WRITE_ACCESS)
    ; IOCTL to support Idle Power Management, including Device Wake
    IOCTL_STORAGE_ENABLE_IDLE_POWER equ CTL_CODE(IOCTL_STORAGE_BASE, 0720h, METHOD_BUFFERED, FILE_ANY_ACCESS)
    IOCTL_STORAGE_GET_IDLE_POWERUP_REASON equ CTL_CODE(IOCTL_STORAGE_BASE, 0721h, METHOD_BUFFERED, FILE_ANY_ACCESS)
    ; IOCTLs to allow class drivers to acquire and release active references on
    ; a unit.  These should only be used if the class driver previously sent a
    ; successful IOCTL_STORAGE_ENABLE_IDLE_POWER request to the port driver.
    IOCTL_STORAGE_POWER_ACTIVE equ CTL_CODE(IOCTL_STORAGE_BASE, 0722h, METHOD_BUFFERED, FILE_ANY_ACCESS)
    IOCTL_STORAGE_POWER_IDLE equ CTL_CODE(IOCTL_STORAGE_BASE, 0723h, METHOD_BUFFERED, FILE_ANY_ACCESS)
    ; This IOCTL indicates that the physical device has triggered some sort of event.
    IOCTL_STORAGE_EVENT_NOTIFICATION equ CTL_CODE(IOCTL_STORAGE_BASE, 0724h, METHOD_BUFFERED, FILE_ANY_ACCESS)
    ; IOCTL to specify a power cap for a storage device.
    IOCTL_STORAGE_DEVICE_POWER_CAP equ CTL_CODE(IOCTL_STORAGE_BASE, 0725h, METHOD_BUFFERED, FILE_ANY_ACCESS)
    ; IOCTL to send commands to the RPMB for a storage device.
    IOCTL_STORAGE_RPMB_COMMAND equ CTL_CODE(IOCTL_STORAGE_BASE, 0726h, METHOD_BUFFERED, FILE_ANY_ACCESS)
    ; IOCTL to manage attributes for storage devices
    IOCTL_STORAGE_ATTRIBUTE_MANAGEMENT equ CTL_CODE(IOCTL_STORAGE_BASE, 0727h, METHOD_BUFFERED, FILE_READ_ACCESS or FILE_WRITE_ACCESS)
    ; IOCTL_STORAGE_DIAGNOSTIC IOCTL to query diagnostic data from the storage driver stack
    IOCTL_STORAGE_DIAGNOSTIC equ CTL_CODE(IOCTL_STORAGE_BASE, 0728h, METHOD_BUFFERED, FILE_ANY_ACCESS)
    ; IOCTLs for storage device depopulation support.
    ; IOCTL_STORAGE_GET_PHYSICAL_ELEMENT_STATUS IOCTL to query physical element status from device.
    IOCTL_STORAGE_GET_PHYSICAL_ELEMENT_STATUS equ CTL_CODE(IOCTL_STORAGE_BASE, 0729h, METHOD_BUFFERED, FILE_ANY_ACCESS)
    ; IOCTL_STORAGE_REMOVE_ELEMENT_AND_TRUNCATE IOCTL to remove and truncate element from device.
    IOCTL_STORAGE_REMOVE_ELEMENT_AND_TRUNCATE equ CTL_CODE(IOCTL_STORAGE_BASE, 0730h, METHOD_BUFFERED, FILE_ANY_ACCESS)
    ; IOCTL_STORAGE_GET_DEVICE_INTERNAL_LOG IOCTL to get device internal status data.
    IOCTL_STORAGE_GET_DEVICE_INTERNAL_LOG equ CTL_CODE(IOCTL_STORAGE_BASE, 0731h, METHOD_BUFFERED, FILE_ANY_ACCESS)
    ; Note: Function code values of less than 0x800 are reserved for Microsoft. Values of 0x800 and higher can be used by vendors.
    ;       So do not use function code of 0x800 and higher to define new IOCTLs in this file.
    ; IOCTL_STORAGE_GET_HOTPLUG_INFO
    STORAGE_HOTPLUG_INFO struct
      Size_ DWORD ?
      ; version
      MediaRemovable BYTE ?
      ; ie. zip, jaz, cdrom, mo, etc. vs hdd
      MediaHotplug BYTE ?
      ; ie. does the device succeed a lock even though its not lockable media?
      DeviceHotplug BYTE ?
      ; ie. 1394, USB, etc.
      WriteCacheEnableOverride BYTE ?
      ; This field should not be relied upon because it is no longer used
    STORAGE_HOTPLUG_INFO ends
    _STORAGE_HOTPLUG_INFO typedef STORAGE_HOTPLUG_INFO
    PSTORAGE_HOTPLUG_INFO typedef ptr STORAGE_HOTPLUG_INFO
    ; IOCTL_STORAGE_GET_DEVICE_NUMBER
    ; input - none
    ; output - STORAGE_DEVICE_NUMBER structure
    ;          The values in the STORAGE_DEVICE_NUMBER structure are guaranteed
    ;          to remain unchanged until the system is rebooted.  They are not
    ;          guaranteed to be persistant across boots.
    STORAGE_DEVICE_NUMBER struct
      ; The FILE_DEVICE_XXX type for this device.
      DeviceType DEVICE_TYPE ?
      ; The number of this device
      DeviceNumber DWORD ?
      ; If the device is partitionable, the partition number of the device.
      ; Otherwise -1
      PartitionNumber DWORD ?
    STORAGE_DEVICE_NUMBER ends
    _STORAGE_DEVICE_NUMBER typedef STORAGE_DEVICE_NUMBER
    PSTORAGE_DEVICE_NUMBER typedef ptr STORAGE_DEVICE_NUMBER
    STORAGE_DEVICE_NUMBERS struct
      ; Size of this structure serves
      ; as the version
      Version DWORD ?
      ; Size of this structure
      Size_ DWORD ?
      NumberOfDevices DWORD ?
      Devices STORAGE_DEVICE_NUMBER ANYSIZE_ARRAY dup (<>)
    STORAGE_DEVICE_NUMBERS ends
    _STORAGE_DEVICE_NUMBERS typedef STORAGE_DEVICE_NUMBERS
    PSTORAGE_DEVICE_NUMBERS typedef ptr STORAGE_DEVICE_NUMBERS
    ; IOCTL_STORAGE_GET_DEVICE_NUMBER_EX
    ; input - none
    ; output - STORAGE_DEVICE_NUMBER_EX structure
    ; Possible flags that can be set in Flags field of
    ; STORAGE_DEVICE_NUMBER_EX structure defined below
    ; This flag indicates that deviceguid is randomly created because a deviceguid conflict was observed
    STORAGE_DEVICE_FLAGS_RANDOM_DEVICEGUID_REASON_CONFLICT equ 1h
    ; This flag indicates that deviceguid is randomly created because the HW ID was not available
    STORAGE_DEVICE_FLAGS_RANDOM_DEVICEGUID_REASON_NOHWID equ 2h
    ; This flag indicates that deviceguid is created from the scsi page83 data.
    ; If this flag is not set this implies it's created from serial number or is randomly generated.
    STORAGE_DEVICE_FLAGS_PAGE_83_DEVICEGUID equ 4h
    STORAGE_DEVICE_NUMBER_EX struct
      ; Sizeof(STORAGE_DEVICE_NUMBER_EX).
      Version DWORD ?
      ; Total size of the structure, including any additional data. Currently
      ; this will always be the same as sizeof(STORAGE_DEVICE_NUMBER_EX).
      Size_ DWORD ?
      ; Flags - this shall be a combination of STORAGE_DEVICE_FLAGS_XXX flags
      ; that gives more information about the members of this structure.
      Flags DWORD ?
      ; The FILE_DEVICE_XXX type for this device. This IOCTL is only
      ; supported for disk devices.
      DeviceType DEVICE_TYPE ?
      ; The number of this device.
      DeviceNumber DWORD ?
      ; A globally-unique identification number for this device.
      ; A GUID of {0} indicates that a GUID could not be generated. The GUID
      ; is based on hardware information that doesn't change with firmware updates
      ; (for instance, serial number can be used to form the GUID, but not the firmware
      ; revision). The device GUID remains the same across reboots.
      ; In general, if a device exposes a globally unique identifier, the storage driver
      ; will use that identifier to form the GUID. Otherwise, the storage driver will combine
      ; the device's vendor ID, product ID and serial number to create the GUID.
      ; If a storage driver detects two devices with the same hardware information (which is
      ; an indication of a problem with the device), the driver will generate a random GUID for
      ; one of the two devices. When handling IOCTL_STORAGE_GET_DEVICE_NUMBER_EX for the device
      ; with the random GUID, the driver will add STORAGE_DEVICE_FLAGS_RANDOM_DEVICEGUID_REASON_CONFLICT
      ; to the Flags member of this structure.
      ; If a storage device does not provide any identifying information, the driver will generate a random
      ; GUID and add STORAGE_DEVICE_FLAGS_RANDOM_DEVICEGUID_REASON_NOHWID to the Flags member of this structure.
      ; A random GUID is not persisted and will not be the same after a reboot.
      DeviceGuid GUID <>
      ; If the device is partitionable, the partition number of the device.
      ; Otherwise -1.
      PartitionNumber DWORD ?
    STORAGE_DEVICE_NUMBER_EX ends
    _STORAGE_DEVICE_NUMBER_EX typedef STORAGE_DEVICE_NUMBER_EX
    PSTORAGE_DEVICE_NUMBER_EX typedef ptr STORAGE_DEVICE_NUMBER_EX
    ; Define the structures for scsi resets
    STORAGE_BUS_RESET_REQUEST struct
      PathId BYTE ?
    STORAGE_BUS_RESET_REQUEST ends
    _STORAGE_BUS_RESET_REQUEST typedef STORAGE_BUS_RESET_REQUEST
    PSTORAGE_BUS_RESET_REQUEST typedef ptr STORAGE_BUS_RESET_REQUEST
    ; Break reservation is sent to the Adapter/FDO with the given lun information.
    STORAGE_BREAK_RESERVATION_REQUEST struct
      Length_ DWORD ?
      _unused BYTE ?
      PathId BYTE ?
      TargetId BYTE ?
      Lun BYTE ?
    STORAGE_BREAK_RESERVATION_REQUEST ends
    PSTORAGE_BREAK_RESERVATION_REQUEST typedef ptr STORAGE_BREAK_RESERVATION_REQUEST
    ; IOCTL_STORAGE_MEDIA_REMOVAL disables the mechanism
    ; on a storage device that ejects media. This function
    ; may or may not be supported on storage devices that
    ; support removable media.
    ; TRUE means prevent media from being removed.
    ; FALSE means allow media removal.
    PREVENT_MEDIA_REMOVAL struct
      PreventMediaRemoval BYTE ?
    PREVENT_MEDIA_REMOVAL ends
    _PREVENT_MEDIA_REMOVAL typedef PREVENT_MEDIA_REMOVAL
    PPREVENT_MEDIA_REMOVAL typedef ptr PREVENT_MEDIA_REMOVAL
    ;  This is the format of TARGET_DEVICE_CUSTOM_NOTIFICATION.CustomDataBuffer
    ;  passed to applications by the classpnp autorun code (via IoReportTargetDeviceChangeAsynchronous).
    CLASS_MEDIA_CHANGE_CONTEXT struct
      MediaChangeCount DWORD ?
      NewState DWORD ?
      ; see MEDIA_CHANGE_DETECTION_STATE enum in classpnp.h in DDK
    CLASS_MEDIA_CHANGE_CONTEXT ends
    _CLASS_MEDIA_CHANGE_CONTEXT typedef CLASS_MEDIA_CHANGE_CONTEXT
    PCLASS_MEDIA_CHANGE_CONTEXT typedef ptr CLASS_MEDIA_CHANGE_CONTEXT
    ; begin_ntminitape
    TAPE_STATISTICS struct
      Version DWORD ?
      Flags DWORD ?
      RecoveredWrites LARGE_INTEGER <>
      UnrecoveredWrites LARGE_INTEGER <>
      RecoveredReads LARGE_INTEGER <>
      UnrecoveredReads LARGE_INTEGER <>
      CompressionRatioReads BYTE ?
      CompressionRatioWrites BYTE ?
    TAPE_STATISTICS ends
    _TAPE_STATISTICS typedef TAPE_STATISTICS
    PTAPE_STATISTICS typedef ptr TAPE_STATISTICS
    RECOVERED_WRITES_VALID equ 00000001h
    UNRECOVERED_WRITES_VALID equ 00000002h
    RECOVERED_READS_VALID equ 00000004h
    UNRECOVERED_READS_VALID equ 00000008h
    WRITE_COMPRESSION_INFO_VALID equ 00000010h
    READ_COMPRESSION_INFO_VALID equ 00000020h
    TAPE_GET_STATISTICS struct
      Operation DWORD ?
    TAPE_GET_STATISTICS ends
    _TAPE_GET_STATISTICS typedef TAPE_GET_STATISTICS
    PTAPE_GET_STATISTICS typedef ptr TAPE_GET_STATISTICS
    TAPE_RETURN_STATISTICS equ 0
    TAPE_RETURN_ENV_INFO equ 1
    TAPE_RESET_STATISTICS equ 2
    ; IOCTL_STORAGE_GET_MEDIA_TYPES_EX will return an array of DEVICE_MEDIA_INFO
    ; structures, one per supported type, embedded in the GET_MEDIA_TYPES struct.
    STORAGE_MEDIA_TYPE typedef SDWORD
    ; Following are defined in ntdddisk.h in the MEDIA_TYPE enum
    ; Unknown,                // Format is unknown
    ; F5_1Pt2_512,            // 5.25", 1.2MB,  512 bytes/sector
    ; F3_1Pt44_512,           // 3.5",  1.44MB, 512 bytes/sector
    ; F3_2Pt88_512,           // 3.5",  2.88MB, 512 bytes/sector
    ; F3_20Pt8_512,           // 3.5",  20.8MB, 512 bytes/sector
    ; F3_720_512,             // 3.5",  720KB,  512 bytes/sector
    ; F5_360_512,             // 5.25", 360KB,  512 bytes/sector
    ; F5_320_512,             // 5.25", 320KB,  512 bytes/sector
    ; F5_320_1024,            // 5.25", 320KB,  1024 bytes/sector
    ; F5_180_512,             // 5.25", 180KB,  512 bytes/sector
    ; F5_160_512,             // 5.25", 160KB,  512 bytes/sector
    ; RemovableMedia,         // Removable media other than floppy
    ; FixedMedia,             // Fixed hard disk media
    ; F3_120M_512,            // 3.5", 120M Floppy
    ; F3_640_512,             // 3.5" ,  640KB,  512 bytes/sector
    ; F5_640_512,             // 5.25",  640KB,  512 bytes/sector
    ; F5_720_512,             // 5.25",  720KB,  512 bytes/sector
    ; F3_1Pt2_512,            // 3.5" ,  1.2Mb,  512 bytes/sector
    ; F3_1Pt23_1024,          // 3.5" ,  1.23Mb, 1024 bytes/sector
    ; F5_1Pt23_1024,          // 5.25",  1.23MB, 1024 bytes/sector
    ; F3_128Mb_512,           // 3.5" MO 128Mb   512 bytes/sector
    ; F3_230Mb_512,           // 3.5" MO 230Mb   512 bytes/sector
    ; F8_256_128,             // 8",     256KB,  128 bytes/sector
    ; F3_200Mb_512,           // 3.5",   200M Floppy (HiFD)
    DDS_4mm equ 20h
    ; Tape - DAT DDS1,2,... (all vendors)
    MiniQic equ 1
    ; Tape - miniQIC Tape
    Travan equ 2
    ; Tape - Travan TR-1,2,3,...
    QIC equ 3
    ; Tape - QIC
    MP_8mm equ 4
    ; Tape - 8mm Exabyte Metal Particle
    AME_8mm equ 5
    ; Tape - 8mm Exabyte Advanced Metal Evap
    AIT1_8mm equ 6
    ; Tape - 8mm Sony AIT
    DLT equ 7
    ; Tape - DLT Compact IIIxt, IV
    NCTP equ 8
    ; Tape - Philips NCTP
    IBM_3480 equ 9
    ; Tape - IBM 3480
    IBM_3490E equ 10
    ; Tape - IBM 3490E
    IBM_Magstar_3590 equ 11
    ; Tape - IBM Magstar 3590
    IBM_Magstar_MP equ 12
    ; Tape - IBM Magstar MP
    STK_DATA_D3 equ 13
    ; Tape - STK Data D3
    SONY_DTF equ 14
    ; Tape - Sony DTF
    DV_6mm equ 15
    ; Tape - 6mm Digital Video
    DMI equ 16
    ; Tape - Exabyte DMI and compatibles
    SONY_D2 equ 17
    ; Tape - Sony D2S and D2L
    CLEANER_CARTRIDGE equ 18
    ; Cleaner - All Drive types that support Drive Cleaners
    CD_ROM equ 19
    ; Opt_Disk - CD
    CD_R equ 20
    ; Opt_Disk - CD-Recordable (Write Once)
    CD_RW equ 21
    ; Opt_Disk - CD-Rewriteable
    DVD_ROM equ 22
    ; Opt_Disk - DVD-ROM
    DVD_R equ 23
    ; Opt_Disk - DVD-Recordable (Write Once)
    DVD_RW equ 24
    ; Opt_Disk - DVD-Rewriteable
    MO_3_RW equ 25
    ; Opt_Disk - 3.5" Rewriteable MO Disk
    MO_5_WO equ 26
    ; Opt_Disk - MO 5.25" Write Once
    MO_5_RW equ 27
    ; Opt_Disk - MO 5.25" Rewriteable (not LIMDOW)
    MO_5_LIMDOW equ 28
    ; Opt_Disk - MO 5.25" Rewriteable (LIMDOW)
    PC_5_WO equ 29
    ; Opt_Disk - Phase Change 5.25" Write Once Optical
    PC_5_RW equ 30
    ; Opt_Disk - Phase Change 5.25" Rewriteable
    PD_5_RW equ 31
    ; Opt_Disk - PhaseChange Dual Rewriteable
    ABL_5_WO equ 32
    ; Opt_Disk - Ablative 5.25" Write Once Optical
    PINNACLE_APEX_5_RW equ 33
    ; Opt_Disk - Pinnacle Apex 4.6GB Rewriteable Optical
    SONY_12_WO equ 34
    ; Opt_Disk - Sony 12" Write Once
    PHILIPS_12_WO equ 35
    ; Opt_Disk - Philips/LMS 12" Write Once
    HITACHI_12_WO equ 36
    ; Opt_Disk - Hitachi 12" Write Once
    CYGNET_12_WO equ 37
    ; Opt_Disk - Cygnet/ATG 12" Write Once
    KODAK_14_WO equ 38
    ; Opt_Disk - Kodak 14" Write Once
    MO_NFR_525 equ 39
    ; Opt_Disk - Near Field Recording (Terastor)
    NIKON_12_RW equ 40
    ; Opt_Disk - Nikon 12" Rewriteable
    IOMEGA_ZIP equ 41
    ; Mag_Disk - Iomega Zip
    IOMEGA_JAZ equ 42
    ; Mag_Disk - Iomega Jaz
    SYQUEST_EZ135 equ 43
    ; Mag_Disk - Syquest EZ135
    SYQUEST_EZFLYER equ 44
    ; Mag_Disk - Syquest EzFlyer
    SYQUEST_SYJET equ 45
    ; Mag_Disk - Syquest SyJet
    AVATAR_F2 equ 46
    ; Mag_Disk - 2.5" Floppy
    MP2_8mm equ 47
    ; Tape - 8mm Hitachi
    DST_S equ 48
    ; Ampex DST Small Tapes
    DST_M equ 49
    ; Ampex DST Medium Tapes
    DST_L equ 50
    ; Ampex DST Large Tapes
    VXATape_1 equ 51
    ; Ecrix 8mm Tape
    VXATape_2 equ 52
    ; Ecrix 8mm Tape
    if (NTDDI_VERSION lt NTDDI_WINXP)
      STK_EAGLE equ 53
      ; STK Eagle
    else
      STK_9840 equ 54
      ; STK 9840
    endif
    LTO_Ultrium equ 55
    ; IBM, HP, Seagate LTO Ultrium
    LTO_Accelis equ 56
    ; IBM, HP, Seagate LTO Accelis
    DVD_RAM equ 57
    ; Opt_Disk - DVD-RAM
    AIT_8mm equ 58
    ; AIT2 or higher
    ADR_1 equ 59
    ; OnStream ADR Mediatypes
    ADR_2 equ 60
    STK_9940 equ 61
    ; STK 9940
    SAIT equ 62
    ; SAIT Tapes
    VXATape equ 63
    _STORAGE_MEDIA_TYPE typedef STORAGE_MEDIA_TYPE
    PSTORAGE_MEDIA_TYPE typedef ptr STORAGE_MEDIA_TYPE
    ; VXA (Ecrix 8mm) Tape
    MEDIA_ERASEABLE equ 00000001h
    MEDIA_WRITE_ONCE equ 00000002h
    MEDIA_READ_ONLY equ 00000004h
    MEDIA_READ_WRITE equ 00000008h
    MEDIA_WRITE_PROTECTED equ 00000100h
    MEDIA_CURRENTLY_MOUNTED equ 80000000h
    ; Define the different storage bus types
    ; Bus types below 128 (0x80) are reserved for Microsoft use
    STORAGE_BUS_TYPE typedef SDWORD
    BusTypeUnknown equ 00h
    BusTypeScsi equ 1
    BusTypeAtapi equ 2
    BusTypeAta equ 3
    BusType1394 equ 4
    BusTypeSsa equ 5
    BusTypeFibre equ 6
    BusTypeUsb equ 7
    BusTypeRAID equ 8
    BusTypeiScsi equ 9
    BusTypeSas equ 10
    BusTypeSata equ 11
    BusTypeSd equ 12
    BusTypeMmc equ 13
    BusTypeVirtual equ 14
    BusTypeFileBackedVirtual equ 15
    BusTypeSpaces equ 16
    BusTypeNvme equ 17
    BusTypeSCM equ 18
    BusTypeUfs equ 19
    BusTypeMax equ 20
    BusTypeMaxReserved equ 7Fh
    _STORAGE_BUS_TYPE typedef STORAGE_BUS_TYPE
    PSTORAGE_BUS_TYPE typedef ptr STORAGE_BUS_TYPE
    ; Macro to identify which bus types
    ; support shared storage
    SupportsDeviceSharing macro BusType
      exitm <((BusType == BusTypeScsi) or (BusType == BusTypeFibre) or (BusType == BusTypeiScsi) or (BusType == BusTypeSas) or (BusType == BusTypeSpaces))>
    endm
    DEVICE_MEDIA_INFO struct
      union DeviceSpecific
        struct DiskInfo
          Cylinders LARGE_INTEGER <>
          MediaType STORAGE_MEDIA_TYPE ?
          TracksPerCylinder DWORD ?
          SectorsPerTrack DWORD ?
          BytesPerSector DWORD ?
          NumberMediaSides DWORD ?
          MediaCharacteristics DWORD ?
          ; Bitmask of MEDIA_XXX values.
        ends
        struct RemovableDiskInfo
          Cylinders LARGE_INTEGER <>
          MediaType STORAGE_MEDIA_TYPE ?
          TracksPerCylinder DWORD ?
          SectorsPerTrack DWORD ?
          BytesPerSector DWORD ?
          NumberMediaSides DWORD ?
          MediaCharacteristics DWORD ?
          ; Bitmask of MEDIA_XXX values.
        ends
        struct TapeInfo
          MediaType STORAGE_MEDIA_TYPE ?
          MediaCharacteristics DWORD ?
          ; Bitmask of MEDIA_XXX values.
          CurrentBlockSize DWORD ?
          BusType STORAGE_BUS_TYPE ?
          ; Bus specific information describing the medium supported.
          union BusSpecificData
            struct ScsiInformation
              MediumType BYTE ?
              DensityCode BYTE ?
            ends
          ends
        ends
      ends
    DEVICE_MEDIA_INFO ends
    _DEVICE_MEDIA_INFO typedef DEVICE_MEDIA_INFO
    PDEVICE_MEDIA_INFO typedef ptr DEVICE_MEDIA_INFO
    GET_MEDIA_TYPES struct
      DeviceType DWORD ?
      ; FILE_DEVICE_XXX values
      MediaInfoCount DWORD ?
      MediaInfo DEVICE_MEDIA_INFO 1 dup (<>)
    GET_MEDIA_TYPES ends
    _GET_MEDIA_TYPES typedef GET_MEDIA_TYPES
    PGET_MEDIA_TYPES typedef ptr GET_MEDIA_TYPES
    ; IOCTL_STORAGE_PREDICT_FAILURE
    ; input - none
    ; output - STORAGE_PREDICT_FAILURE structure
    ;          PredictFailure returns zero if no failure predicted and non zero
    ;                         if a failure is predicted.
    ;          VendorSpecific returns 512 bytes of vendor specific information
    ;                         if a failure is predicted
    STORAGE_PREDICT_FAILURE struct
      PredictFailure DWORD ?
      VendorSpecific BYTE 512 dup (?)
    STORAGE_PREDICT_FAILURE ends
    _STORAGE_PREDICT_FAILURE typedef STORAGE_PREDICT_FAILURE
    PSTORAGE_PREDICT_FAILURE typedef ptr STORAGE_PREDICT_FAILURE
    ; IOCTL_STORAGE_FAILURE_PREDICTION_CONFIG
    ; Input - STORAGE_FAILURE_PREDICTION_CONFIG structure.
    ;         If the sender wants to enable or disable failure prediction then
    ;         the sender should set the "Set" field to TRUE.
    ; Output - STORAGE_FAILURE_PREDICTION_CONFIG structure.
    ;          If successful, the "Enabled" field will indicate if failure
    ;          prediction is currently enabled or not.
    STORAGE_FAILURE_PREDICTION_CONFIG struct
      Version DWORD ?
      ; Set to 1 for Blue.
      Size_ DWORD ?
      Set BYTE ?
      ; TRUE if the sender wants to enable/disable failure prediction.
      Enabled BYTE ?
      Reserved WORD ?
    STORAGE_FAILURE_PREDICTION_CONFIG ends
    _STORAGE_FAILURE_PREDICTION_CONFIG typedef STORAGE_FAILURE_PREDICTION_CONFIG
    PSTORAGE_FAILURE_PREDICTION_CONFIG typedef ptr STORAGE_FAILURE_PREDICTION_CONFIG
    STORAGE_FAILURE_PREDICTION_CONFIG_V1 equ 1
    ; end_ntminitape
    ; Property Query Structures
    ; IOCTL_STORAGE_QUERY_PROPERTY
    ; Input Buffer:
    ;      a STORAGE_PROPERTY_QUERY structure which describes what type of query
    ;      is being done, what property is being queried for, and any additional
    ;      parameters which a particular property query requires.
    ;  Output Buffer:
    ;      Contains a buffer to place the results of the query into.  Since all
    ;      property descriptors can be cast into a STORAGE_DESCRIPTOR_HEADER,
    ;      the IOCTL can be called once with a small buffer then again using
    ;      a buffer as large as the header reports is necessary.
    ; Types of queries
    STORAGE_QUERY_TYPE typedef SDWORD
    PropertyStandardQuery equ 0
    ; Retrieves the descriptor
    PropertyExistsQuery equ 1
    ; Used to test whether the descriptor is supported
    PropertyMaskQuery equ 2
    ; Used to retrieve a mask of writeable fields in the descriptor
    PropertyQueryMaxDefined equ 3
    _STORAGE_QUERY_TYPE typedef STORAGE_QUERY_TYPE
    PSTORAGE_QUERY_TYPE typedef ptr STORAGE_QUERY_TYPE
    ; use to validate the value
    ; IOCTL_STORAGE_SET_PROPERTY
    ; Input Buffer:
    ;      a STORAGE_PROPERTY_SET structure which describes what type of property set
    ;      is being done, what property is being set, and any additional
    ;      parameters which a particular property set requires.
    ;  Output Buffer:
    ;      Contains a buffer to place the results of the query into.  Since all
    ;      property descriptors can be cast into a STORAGE_DESCRIPTOR_HEADER,
    ;      the IOCTL can be called once with a small buffer then again using
    ;      a buffer as large as the header reports is necessary.
    ; Types of set operation
    STORAGE_SET_TYPE typedef SDWORD
    PropertyStandardSet equ 0
    ; Sets the descriptor
    PropertyExistsSet equ 1
    ; Used to test whether the descriptor is supported
    PropertySetMaxDefined equ 2
    _STORAGE_SET_TYPE typedef STORAGE_SET_TYPE
    PSTORAGE_SET_TYPE typedef ptr STORAGE_SET_TYPE
    ; use to validate the value
    ; define some initial property id's
    STORAGE_PROPERTY_ID typedef SDWORD
    StorageDeviceProperty equ 0
    StorageAdapterProperty equ 1
    StorageDeviceIdProperty equ 2
    StorageDeviceUniqueIdProperty equ 3
    ; See storduid.h for details
    StorageDeviceWriteCacheProperty equ 4
    StorageMiniportProperty equ 5
    StorageAccessAlignmentProperty equ 6
    StorageDeviceSeekPenaltyProperty equ 7
    StorageDeviceTrimProperty equ 8
    StorageDeviceWriteAggregationProperty equ 9
    StorageDeviceDeviceTelemetryProperty equ 10
    StorageDeviceLBProvisioningProperty equ 11
    StorageDevicePowerProperty equ 12
    StorageDeviceCopyOffloadProperty equ 13
    StorageDeviceResiliencyProperty equ 14
    StorageDeviceMediumProductType equ 15
    StorageAdapterRpmbProperty equ 16
    StorageAdapterCryptoProperty equ 17
    StorageDeviceIoCapabilityProperty equ 48
    StorageAdapterProtocolSpecificProperty equ 49
    StorageDeviceProtocolSpecificProperty equ 50
    StorageAdapterTemperatureProperty equ 51
    StorageDeviceTemperatureProperty equ 52
    StorageAdapterPhysicalTopologyProperty equ 53
    StorageDevicePhysicalTopologyProperty equ 54
    StorageDeviceAttributesProperty equ 55
    StorageDeviceManagementStatus equ 56
    StorageAdapterSerialNumberProperty equ 57
    StorageDeviceLocationProperty equ 58
    StorageDeviceNumaProperty equ 59
    StorageDeviceZonedDeviceProperty equ 60
    StorageDeviceUnsafeShutdownCount equ 61
    StorageDeviceEnduranceProperty equ 62
    StorageDeviceLedStateProperty equ 63
    StorageDeviceSelfEncryptionProperty equ 64
    StorageFruIdProperty equ 65
    _STORAGE_PROPERTY_ID typedef STORAGE_PROPERTY_ID
    PSTORAGE_PROPERTY_ID typedef ptr STORAGE_PROPERTY_ID
    ; Query structure - additional parameters for specific queries can follow
    ; the header
    STORAGE_PROPERTY_QUERY struct
      ; ID of the property being retrieved
      PropertyId STORAGE_PROPERTY_ID ?
      ; Flags indicating the type of query being performed
      QueryType STORAGE_QUERY_TYPE ?
      ; Space for additional parameters if necessary
      AdditionalParameters BYTE 1 dup (?)
    STORAGE_PROPERTY_QUERY ends
    _STORAGE_PROPERTY_QUERY typedef STORAGE_PROPERTY_QUERY
    PSTORAGE_PROPERTY_QUERY typedef ptr STORAGE_PROPERTY_QUERY
    ; Set structure - additional parameters for specific set property that can follow
    ; the header
    STORAGE_PROPERTY_SET struct
      ; ID of the property being retrieved
      PropertyId STORAGE_PROPERTY_ID ?
      ; Flags indicating the type of set property being performed
      SetType STORAGE_SET_TYPE ?
      ; Space for additional parameters if necessary
      AdditionalParameters BYTE 1 dup (?)
    STORAGE_PROPERTY_SET ends
    _STORAGE_PROPERTY_SET typedef STORAGE_PROPERTY_SET
    PSTORAGE_PROPERTY_SET typedef ptr STORAGE_PROPERTY_SET
    ; Standard property descriptor header.  All property pages should use this
    ; as their first element or should contain these two elements
    STORAGE_DESCRIPTOR_HEADER struct
      Version DWORD ?
      Size_ DWORD ?
    STORAGE_DESCRIPTOR_HEADER ends
    _STORAGE_DESCRIPTOR_HEADER typedef STORAGE_DESCRIPTOR_HEADER
    PSTORAGE_DESCRIPTOR_HEADER typedef ptr STORAGE_DESCRIPTOR_HEADER
    ; Device property descriptor - this is really just a rehash of the inquiry
    ; data retrieved from a scsi device
    ; This may only be retrieved from a target device.  Sending this to the bus
    ; will result in an error
    STORAGE_DEVICE_DESCRIPTOR struct
      ; Sizeof(STORAGE_DEVICE_DESCRIPTOR)
      Version DWORD ?
      ; Total size of the descriptor, including the space for additional
      ; data and id strings
      Size_ DWORD ?
      ; The SCSI-2 device type
      DeviceType BYTE ?
      ; The SCSI-2 device type modifier (if any) - this may be zero
      DeviceTypeModifier BYTE ?
      ; Flag indicating whether the device's media (if any) is removable.  This
      ; field should be ignored for media-less devices
      RemovableMedia BYTE ?
      ; Flag indicating whether the device can support mulitple outstanding
      ; commands.  The actual synchronization in this case is the responsibility
      ; of the port driver.
      CommandQueueing BYTE ?
      ; Byte offset to the zero-terminated ascii string containing the device's
      ; vendor id string.  For devices with no such ID this will be zero
      VendorIdOffset DWORD ?
      ; Byte offset to the zero-terminated ascii string containing the device's
      ; product id string.  For devices with no such ID this will be zero
      ProductIdOffset DWORD ?
      ; Byte offset to the zero-terminated ascii string containing the device's
      ; product revision string.  For devices with no such string this will be
      ; zero
      ProductRevisionOffset DWORD ?
      ; Byte offset to the zero-terminated ascii string containing the device's
      ; serial number.  For devices with no serial number this will be zero
      SerialNumberOffset DWORD ?
      ; Contains the bus type (as defined above) of the device.  It should be
      ; used to interpret the raw device properties at the end of this structure
      ; (if any)
      BusType STORAGE_BUS_TYPE ?
      ; The number of bytes of bus-specific data which have been appended to
      ; this descriptor
      RawPropertiesLength DWORD ?
      ; Place holder for the first byte of the bus specific property data
      RawDeviceProperties BYTE 1 dup (?)
    STORAGE_DEVICE_DESCRIPTOR ends
    _STORAGE_DEVICE_DESCRIPTOR typedef STORAGE_DEVICE_DESCRIPTOR
    PSTORAGE_DEVICE_DESCRIPTOR typedef ptr STORAGE_DEVICE_DESCRIPTOR
    ; Adapter properties
    ; This descriptor can be retrieved from a target device object of from the
    ; device object for the bus.  Retrieving from the target device object will
    ; forward the request to the underlying bus
    STORAGE_ADAPTER_DESCRIPTOR struct
      Version DWORD ?
      Size_ DWORD ?
      MaximumTransferLength DWORD ?
      MaximumPhysicalPages DWORD ?
      AlignmentMask DWORD ?
      AdapterUsesPio BYTE ?
      AdapterScansDown BYTE ?
      CommandQueueing BYTE ?
      AcceleratedTransfer BYTE ?
      if (NTDDI_VERSION lt NTDDI_WINXP)
        BusType BYTE ?
      else
        BusType BYTE ?
      endif
      BusMajorVersion WORD ?
      BusMinorVersion WORD ?
      if (NTDDI_VERSION ge NTDDI_WIN8)
        SrbType BYTE ?
        AddressType BYTE ?
      endif
    STORAGE_ADAPTER_DESCRIPTOR ends
    _STORAGE_ADAPTER_DESCRIPTOR typedef STORAGE_ADAPTER_DESCRIPTOR
    PSTORAGE_ADAPTER_DESCRIPTOR typedef ptr STORAGE_ADAPTER_DESCRIPTOR
    if (NTDDI_VERSION ge NTDDI_WIN8)
      NO_SRBTYPE_ADAPTER_DESCRIPTOR_SIZE equ <UFIELD_OFFSET(STORAGE_ADAPTER_DESCRIPTOR, SrbType)>
      if  not Defined(SRB_TYPE_SCSI_REQUEST_BLOCK)
        SRB_TYPE_SCSI_REQUEST_BLOCK equ 0
      endif
      if  not Defined(SRB_TYPE_STORAGE_REQUEST_BLOCK)
        SRB_TYPE_STORAGE_REQUEST_BLOCK equ 1
      endif
      if  not Defined(STORAGE_ADDRESS_TYPE_BTL8)
        STORAGE_ADDRESS_TYPE_BTL8 equ 0
      endif
    endif
    ; (NTDDI_VERSION >= NTDDI_WIN8)
    STORAGE_ACCESS_ALIGNMENT_DESCRIPTOR struct
      ; Sizeof(STORAGE_ACCESS_ALIGNMENT_DESCRIPTOR)
      Version DWORD ?
      ; Total size of the descriptor, including the space for additional
      ; data and id strings
      Size_ DWORD ?
      ; The number of bytes in a cache line of the device
      BytesPerCacheLine DWORD ?
      ; The address offset neccessary for proper cache access alignment in bytes
      BytesOffsetForCacheAlignment DWORD ?
      ; The number of bytes in a physical sector of the device
      BytesPerLogicalSector DWORD ?
      ; The number of bytes in an addressable logical sector (LBA)of the device
      BytesPerPhysicalSector DWORD ?
      ; The address offset neccessary for proper sector access alignment in bytes
      BytesOffsetForSectorAlignment DWORD ?
    STORAGE_ACCESS_ALIGNMENT_DESCRIPTOR ends
    _STORAGE_ACCESS_ALIGNMENT_DESCRIPTOR typedef STORAGE_ACCESS_ALIGNMENT_DESCRIPTOR
    PSTORAGE_ACCESS_ALIGNMENT_DESCRIPTOR typedef ptr STORAGE_ACCESS_ALIGNMENT_DESCRIPTOR
    STORAGE_MEDIUM_PRODUCT_TYPE_DESCRIPTOR struct
      ; Sizeof(STORAGE_MEDIUM_PRODUCT_TYPE_DESCRIPTOR)
      Version DWORD ?
      ; Total size of the descriptor, including the space for additional data
      Size_ DWORD ?
      ; Product type of the supporting storage medium
      MediumProductType DWORD ?
    STORAGE_MEDIUM_PRODUCT_TYPE_DESCRIPTOR ends
    _STORAGE_MEDIUM_PRODUCT_TYPE_DESCRIPTOR typedef STORAGE_MEDIUM_PRODUCT_TYPE_DESCRIPTOR
    PSTORAGE_MEDIUM_PRODUCT_TYPE_DESCRIPTOR typedef ptr STORAGE_MEDIUM_PRODUCT_TYPE_DESCRIPTOR
    STORAGE_PORT_CODE_SET typedef SDWORD
    StoragePortCodeSetReserved equ 0
    StoragePortCodeSetStorport equ 1
    StoragePortCodeSetSCSIport equ 2
    StoragePortCodeSetSpaceport equ 3
    StoragePortCodeSetATAport equ 4
    StoragePortCodeSetUSBport equ 5
    StoragePortCodeSetSBP2port equ 6
    StoragePortCodeSetSDport equ 7
    _STORAGE_PORT_CODE_SET typedef STORAGE_PORT_CODE_SET
    PSTORAGE_PORT_CODE_SET typedef ptr STORAGE_PORT_CODE_SET
    if (NTDDI_VERSION ge NTDDI_WIN8)
      STORAGE_MINIPORT_DESCRIPTOR_V1_SIZE equ <RTL_SIZEOF_THROUGH_FIELD(STORAGE_MINIPORT_DESCRIPTOR, IoTimeoutValue)>
    endif
    ; nameless struct/unions
    ; bit fields other than int to disable this around the struct
    STORAGE_MINIPORT_DESCRIPTOR struct
      Version DWORD ?
      Size_ DWORD ?
      Portdriver STORAGE_PORT_CODE_SET ?
      LUNResetSupported BYTE ?
      TargetResetSupported BYTE ?
      if (NTDDI_VERSION ge NTDDI_WIN8)
        IoTimeoutValue WORD ?
      endif
      if (NTDDI_VERSION ge NTDDI_WINBLUE)
        ExtraIoInfoSupported BYTE ?
        if (NTDDI_VERSION ge NTDDI_WIN10_FE)
          union Flags
            struct
              ANONYMOUS_REC0 record ANONYMOUS_REC0_Reserved:7, ANONYMOUS_REC0_LogicalPoFxForDisk:1
              ANONYMOUS_REC0 <>
            ends
            AsBYTE BYTE ?
          ends
          Reserved0 BYTE 2 dup (?)
        else
          Reserved0 BYTE 3 dup (?)
        endif
        Reserved1 DWORD ?
      endif
    STORAGE_MINIPORT_DESCRIPTOR ends
    _STORAGE_MINIPORT_DESCRIPTOR typedef STORAGE_MINIPORT_DESCRIPTOR
    PSTORAGE_MINIPORT_DESCRIPTOR typedef ptr STORAGE_MINIPORT_DESCRIPTOR
    ; Storage identification descriptor.
    ; The definitions here are based on the SCSI/SBP vital product data
    ; device identifier page.
    STORAGE_IDENTIFIER_CODE_SET typedef SDWORD
    StorageIdCodeSetReserved equ 0
    StorageIdCodeSetBinary equ 1
    StorageIdCodeSetAscii equ 2
    StorageIdCodeSetUtf8 equ 3
    _STORAGE_IDENTIFIER_CODE_SET typedef STORAGE_IDENTIFIER_CODE_SET
    PSTORAGE_IDENTIFIER_CODE_SET typedef ptr STORAGE_IDENTIFIER_CODE_SET
    STORAGE_IDENTIFIER_TYPE typedef SDWORD
    StorageIdTypeVendorSpecific equ 0
    StorageIdTypeVendorId equ 1
    StorageIdTypeEUI64 equ 2
    StorageIdTypeFCPHName equ 3
    StorageIdTypePortRelative equ 4
    StorageIdTypeTargetPortGroup equ 5
    StorageIdTypeLogicalUnitGroup equ 6
    StorageIdTypeMD5LogicalUnitIdentifier equ 7
    StorageIdTypeScsiNameString equ 8
    _STORAGE_IDENTIFIER_TYPE typedef STORAGE_IDENTIFIER_TYPE
    PSTORAGE_IDENTIFIER_TYPE typedef ptr STORAGE_IDENTIFIER_TYPE
    ; Mislabeled above but need to keep it for backwards compatibility
    StorageIdTypeNAA equ <StorageIdTypeFCPHName>
    ; NAA formats (Used with StorageIdTypeNAA)
    STORAGE_ID_NAA_FORMAT typedef SDWORD
    StorageIdNAAFormatIEEEExtended equ 2
    StorageIdNAAFormatIEEERegistered equ 3
    StorageIdNAAFormatIEEEERegisteredExtended equ 5
    _STORAGE_ID_NAA_FORMAT typedef STORAGE_ID_NAA_FORMAT
    PSTORAGE_ID_NAA_FORMAT typedef ptr STORAGE_ID_NAA_FORMAT
    STORAGE_ASSOCIATION_TYPE typedef SDWORD
    StorageIdAssocDevice equ 0
    StorageIdAssocPort equ 1
    StorageIdAssocTarget equ 2
    _STORAGE_ASSOCIATION_TYPE typedef STORAGE_ASSOCIATION_TYPE
    PSTORAGE_ASSOCIATION_TYPE typedef ptr STORAGE_ASSOCIATION_TYPE
    STORAGE_IDENTIFIER struct
      CodeSet STORAGE_IDENTIFIER_CODE_SET ?
      Type_ STORAGE_IDENTIFIER_TYPE ?
      IdentifierSize WORD ?
      NextOffset WORD ?
      ; Add new fields here since existing code depends on
      ; the above layout not changing.
      Association STORAGE_ASSOCIATION_TYPE ?
      ; The identifier is a variable length array of bytes.
      Identifier BYTE 1 dup (?)
    STORAGE_IDENTIFIER ends
    _STORAGE_IDENTIFIER typedef STORAGE_IDENTIFIER
    PSTORAGE_IDENTIFIER typedef ptr STORAGE_IDENTIFIER
    STORAGE_DEVICE_ID_DESCRIPTOR struct
      Version DWORD ?
      Size_ DWORD ?
      ; The number of identifiers reported by the device.
      NumberOfIdentifiers DWORD ?
      ; The following field is actually a variable length array of identification
      ; descriptors.  Unfortunately there's no C notation for an array of
      ; variable length structures so we're forced to just pretend.
      Identifiers BYTE 1 dup (?)
    STORAGE_DEVICE_ID_DESCRIPTOR ends
    _STORAGE_DEVICE_ID_DESCRIPTOR typedef STORAGE_DEVICE_ID_DESCRIPTOR
    PSTORAGE_DEVICE_ID_DESCRIPTOR typedef ptr STORAGE_DEVICE_ID_DESCRIPTOR
    ; output buffer for   StorageDeviceSeekPenaltyProperty & PropertyStandardQuery
    DEVICE_SEEK_PENALTY_DESCRIPTOR struct
      Version DWORD ?
      ; keep compatible with STORAGE_DESCRIPTOR_HEADER
      Size_ DWORD ?
      ; keep compatible with STORAGE_DESCRIPTOR_HEADER
      IncursSeekPenalty BYTE ?
    DEVICE_SEEK_PENALTY_DESCRIPTOR ends
    _DEVICE_SEEK_PENALTY_DESCRIPTOR typedef DEVICE_SEEK_PENALTY_DESCRIPTOR
    PDEVICE_SEEK_PENALTY_DESCRIPTOR typedef ptr DEVICE_SEEK_PENALTY_DESCRIPTOR
    ; output buffer for   StorageDeviceWriteAggregationProperty & PropertyStandardQuery
    DEVICE_WRITE_AGGREGATION_DESCRIPTOR struct
      Version DWORD ?
      ; keep compatible with STORAGE_DESCRIPTOR_HEADER
      Size_ DWORD ?
      ; keep compatible with STORAGE_DESCRIPTOR_HEADER
      BenefitsFromWriteAggregation BYTE ?
    DEVICE_WRITE_AGGREGATION_DESCRIPTOR ends
    _DEVICE_WRITE_AGGREGATION_DESCRIPTOR typedef DEVICE_WRITE_AGGREGATION_DESCRIPTOR
    PDEVICE_WRITE_AGGREGATION_DESCRIPTOR typedef ptr DEVICE_WRITE_AGGREGATION_DESCRIPTOR
    ; output buffer for   StorageDeviceTrimProperty & PropertyStandardQuery
    DEVICE_TRIM_DESCRIPTOR struct
      Version DWORD ?
      ; keep compatible with STORAGE_DESCRIPTOR_HEADER
      Size_ DWORD ?
      ; keep compatible with STORAGE_DESCRIPTOR_HEADER
      TrimEnabled BYTE ?
    DEVICE_TRIM_DESCRIPTOR ends
    _DEVICE_TRIM_DESCRIPTOR typedef DEVICE_TRIM_DESCRIPTOR
    PDEVICE_TRIM_DESCRIPTOR typedef ptr DEVICE_TRIM_DESCRIPTOR
    ; Output buffer for StorageDeviceLBProvisioningProperty & PropertyStandardQuery
    DEVICE_LB_PROVISIONING_DESCRIPTOR struct
      Version DWORD ?
      ; keep compatible with STORAGE_DESCRIPTOR_HEADER
      Size_ DWORD ?
      ; keep compatible with STORAGE_DESCRIPTOR_HEADER
      ; Supports DeviceDsmAction_GetFreeSpace
      ; Supports DeviceDsmAction_Map
      DEVICE_LB_PROVISIONING_DESCRIPTOR_REC record DEVICE_LB_PROVISIONING_DESCRIPTOR_REC_MapSupported:1, DEVICE_LB_PROVISIONING_DESCRIPTOR_REC_GetFreeSpaceSupported:1, DEVICE_LB_PROVISIONING_DESCRIPTOR_REC_UnmapGranularityAlignmentValid:1, DEVICE_LB_PROVISIONING_DESCRIPTOR_REC_AnchorSupported:3, DEVICE_LB_PROVISIONING_DESCRIPTOR_REC_ThinProvisioningReadZeros:1, DEVICE_LB_PROVISIONING_DESCRIPTOR_REC_ThinProvisioningEnabled:1
      DEVICE_LB_PROVISIONING_DESCRIPTOR_BITS DEVICE_LB_PROVISIONING_DESCRIPTOR_REC <>
      ; Supports DeviceDsmAction_Map
      Reserved1 BYTE 7 dup (?)
      OptimalUnmapGranularity QWORD ?
      ; Granularity in bytes.
      UnmapGranularityAlignment QWORD ?
      ; Granularity alignment in bytes.
      if (NTDDI_VERSION ge NTDDI_WINBLUE)
        MaxUnmapLbaCount DWORD ?
        ; Max LBAs that can be unmapped in a single UNMAP command, in logical blocks.
        MaxUnmapBlockDescriptorCount DWORD ?
        ; Max number of descriptors allowed in a single UNMAP command.
      endif
    DEVICE_LB_PROVISIONING_DESCRIPTOR ends
    _DEVICE_LB_PROVISIONING_DESCRIPTOR typedef DEVICE_LB_PROVISIONING_DESCRIPTOR
    PDEVICE_LB_PROVISIONING_DESCRIPTOR typedef ptr DEVICE_LB_PROVISIONING_DESCRIPTOR
    DEVICE_LB_PROVISIONING_DESCRIPTOR_V1_SIZE equ <RTL_SIZEOF_THROUGH_FIELD(DEVICE_LB_PROVISIONING_DESCRIPTOR, UnmapGranularityAlignment)>
    ; IOCTL_STORAGE_GET_LB_PROVISIONING_MAP_RESOURCES
    ; Input Buffer:
    ;      None
    ; Output Buffer:
    ;      Structure of type STORAGE_LB_PROVISIONING_MAP_RESOURCES
    STORAGE_LB_PROVISIONING_MAP_RESOURCES struct
      Size_ DWORD ?
      Version DWORD ?
      STORAGE_LB_PROVISIONING_MAP_RESOURCES_REC record STORAGE_LB_PROVISIONING_MAP_RESOURCES_REC_Reserved0:6, STORAGE_LB_PROVISIONING_MAP_RESOURCES_REC_UsedMappingResourcesValid:1, STORAGE_LB_PROVISIONING_MAP_RESOURCES_REC_AvailableMappingResourcesValid:1
      STORAGE_LB_PROVISIONING_MAP_RESOURCES_BITS STORAGE_LB_PROVISIONING_MAP_RESOURCES_REC <>
      Reserved1 BYTE 3 dup (?)
      ; See LOG_PAGE_LBP_RESOURCE_SCOPE_* definitions in scsi.h for scope values.
      STORAGE_LB_PROVISIONING_MAP_RESOURCES_REC record STORAGE_LB_PROVISIONING_MAP_RESOURCES_REC_Reserved2:4, STORAGE_LB_PROVISIONING_MAP_RESOURCES_REC_UsedMappingResourcesScope:2, STORAGE_LB_PROVISIONING_MAP_RESOURCES_REC_AvailableMappingResourcesScope:2
      STORAGE_LB_PROVISIONING_MAP_RESOURCES_BITS STORAGE_LB_PROVISIONING_MAP_RESOURCES_REC <>
      Reserved3 BYTE 3 dup (?)
      AvailableMappingResources QWORD ?
      ; Available LBA mapping resources, in bytes.
      UsedMappingResources QWORD ?
      ; Used LBA mapping resources, in bytes.
    STORAGE_LB_PROVISIONING_MAP_RESOURCES ends
    _STORAGE_LB_PROVISIONING_MAP_RESOURCES typedef STORAGE_LB_PROVISIONING_MAP_RESOURCES
    PSTORAGE_LB_PROVISIONING_MAP_RESOURCES typedef ptr STORAGE_LB_PROVISIONING_MAP_RESOURCES
    ; output buffer for   StorageDevicePowerProperty & PropertyStandardQuery
    DEVICE_POWER_DESCRIPTOR struct
      Version DWORD ?
      ; keep compatible with STORAGE_DESCRIPTOR_HEADER
      Size_ DWORD ?
      ; keep compatible with STORAGE_DESCRIPTOR_HEADER
      DeviceAttentionSupported BYTE ?
      ; The device supports "device attention".
      AsynchronousNotificationSupported BYTE ?
      ; The device supports asynchronous notifications, delivered via IOCTL_STORAGE_EVENT_NOTIFICATION.
      IdlePowerManagementEnabled BYTE ?
      ; The device has been registered for runtime idle power management.
      D3ColdEnabled BYTE ?
      ; The device will be powered off when put into D3.
      D3ColdSupported BYTE ?
      ; The platform supports D3Cold for this device.
      NoVerifyDuringIdlePower BYTE ?
      ; Device require no verification during idle power transitions.
      Reserved BYTE 2 dup (?)
      IdleTimeoutInMS DWORD ?
      ; The idle timeout value in milliseconds. Only valid if IdlePowerManagementEnabled == TRUE.
    DEVICE_POWER_DESCRIPTOR ends
    _DEVICE_POWER_DESCRIPTOR typedef DEVICE_POWER_DESCRIPTOR
    PDEVICE_POWER_DESCRIPTOR typedef ptr DEVICE_POWER_DESCRIPTOR
    ; Output buffer for StorageDeviceCopyOffloadProperty & PropertyStandardQuery
    DEVICE_COPY_OFFLOAD_DESCRIPTOR struct
      Version DWORD ?
      ; keep compatible with STORAGE_DESCRIPTOR_HEADER
      Size_ DWORD ?
      ; keep compatible with STORAGE_DESCRIPTOR_HEADER
      MaximumTokenLifetime DWORD ?
      DefaultTokenLifetime DWORD ?
      MaximumTransferSize QWORD ?
      OptimalTransferCount QWORD ?
      MaximumDataDescriptors DWORD ?
      MaximumTransferLengthPerDescriptor DWORD ?
      OptimalTransferLengthPerDescriptor DWORD ?
      OptimalTransferLengthGranularity WORD ?
      Reserved BYTE 2 dup (?)
    DEVICE_COPY_OFFLOAD_DESCRIPTOR ends
    _DEVICE_COPY_OFFLOAD_DESCRIPTOR typedef DEVICE_COPY_OFFLOAD_DESCRIPTOR
    PDEVICE_COPY_OFFLOAD_DESCRIPTOR typedef ptr DEVICE_COPY_OFFLOAD_DESCRIPTOR
    ; Output buffer for StorageDeviceResiliencyProperty & PropertyStandardQuery
    STORAGE_DEVICE_RESILIENCY_DESCRIPTOR struct
      ; Size of this structure serves
      ; as the version
      Version DWORD ?
      ; Size of  this structure  plus
      ; all the variable sized fields
      Size_ DWORD ?
      ; Friendly name associated with
      ; this descriptor
      NameOffset DWORD ?
      ; Number of  logical  copies of
      ; data that are available
      NumberOfLogicalCopies DWORD ?
      ; Number of  complete copies of
      ; data that are stored
      NumberOfPhysicalCopies DWORD ?
      ; Number of disks that can fail
      ; without leading to  data loss
      PhysicalDiskRedundancy DWORD ?
      ; Number  of columns associated
      ; with this descriptor
      NumberOfColumns DWORD ?
      ; Stripe  width associated with
      ; this descriptor, in bytes
      Interleave DWORD ?
    STORAGE_DEVICE_RESILIENCY_DESCRIPTOR ends
    _STORAGE_DEVICE_RESILIENCY_DESCRIPTOR typedef STORAGE_DEVICE_RESILIENCY_DESCRIPTOR
    PSTORAGE_DEVICE_RESILIENCY_DESCRIPTOR typedef ptr STORAGE_DEVICE_RESILIENCY_DESCRIPTOR
    ; Output buffer for StorageAdapterRpmbProperty & PropertyStandardQuery
    STORAGE_RPMB_FRAME_TYPE typedef SDWORD
    StorageRpmbFrameTypeUnknown equ 0
    StorageRpmbFrameTypeStandard equ 1
    StorageRpmbFrameTypeMax equ 2
    _STORAGE_RPMB_FRAME_TYPE typedef STORAGE_RPMB_FRAME_TYPE
    PSTORAGE_RPMB_FRAME_TYPE typedef ptr STORAGE_RPMB_FRAME_TYPE
    STORAGE_RPMB_DESCRIPTOR_VERSION_1 equ 1
    STORAGE_RPMB_MINIMUM_RELIABLE_WRITE_SIZE equ 512
    STORAGE_RPMB_DESCRIPTOR struct
      ; Keep compatible with STORAGE_DESCRIPTOR_HEADER
      ; Shall be set to STORAGE_RPMB_DESCRIPTOR_VERSION_1
      Version DWORD ?
      ; Keep compatible with STORAGE_DESCRIPTOR_HEADER
      ; Shall be set to sizeof(STORAGE_RPMB_DESCRIPTOR)
      Size_ DWORD ?
      ; The size of the RPMB, in bytes.
      ; 0 if not supported, RPMB size in bytes otherwise
      SizeInBytes DWORD ?
      ; The maximum amount of data supported in one transaction
      ; in bytes.
      ; 0 if not supported, minimum 512 bytes
      MaxReliableWriteSizeInBytes DWORD ?
      ; To support different RPMB frame formats, specify which
      ; frame format the payload will be in so the port driver
      ; can take the appropriate action
      FrameFormat STORAGE_RPMB_FRAME_TYPE ?
    STORAGE_RPMB_DESCRIPTOR ends
    _STORAGE_RPMB_DESCRIPTOR typedef STORAGE_RPMB_DESCRIPTOR
    PSTORAGE_RPMB_DESCRIPTOR typedef ptr STORAGE_RPMB_DESCRIPTOR
    ; Output buffer for StorageAdapterCryptoProperty & PropertyStandardQuery
    STORAGE_CRYPTO_ALGORITHM_ID typedef SDWORD
    StorageCryptoAlgorithmUnknown equ 0
    StorageCryptoAlgorithmXTSAES equ 1
    StorageCryptoAlgorithmBitlockerAESCBC equ 2
    StorageCryptoAlgorithmAESECB equ 3
    StorageCryptoAlgorithmESSIVAESCBC equ 4
    StorageCryptoAlgorithmMax equ 5
    _STORAGE_CRYPTO_ALGORITHM_ID typedef STORAGE_CRYPTO_ALGORITHM_ID
    PSTORAGE_CRYPTO_ALGORITHM_ID typedef ptr STORAGE_CRYPTO_ALGORITHM_ID
    STORAGE_CRYPTO_KEY_SIZE typedef SDWORD
    StorageCryptoKeySizeUnknown equ 0
    StorageCryptoKeySize128Bits equ 1
    StorageCryptoKeySize192Bits equ 2
    StorageCryptoKeySize256Bits equ 3
    StorageCryptoKeySize512Bits equ 4
    _STORAGE_CRYPTO_KEY_SIZE typedef STORAGE_CRYPTO_KEY_SIZE
    PSTORAGE_CRYPTO_KEY_SIZE typedef ptr STORAGE_CRYPTO_KEY_SIZE
    STORAGE_CRYPTO_CAPABILITY_VERSION_1 equ 1
    STORAGE_CRYPTO_CAPABILITY struct
      ; To enable versioning of this structure. This shall bet set
      ; to STORAGE_CRYPTO_CAPABILITY_VERSION_1
      Version DWORD ?
      ; Size of this structure. This shall be set to
      ; sizeof(STORAGE_CRYPTO_CAPABILITY)
      Size_ DWORD ?
      ; The index for this crypto capability
      CryptoCapabilityIndex DWORD ?
      ; Supported algorithm for this crypto capability
      AlgorithmId STORAGE_CRYPTO_ALGORITHM_ID ?
      ; The supported key size for this algorithm
      KeySize STORAGE_CRYPTO_KEY_SIZE ?
      ; Bitmask for the supported sizes of encryptable data blocks. When bit
      ; j is set (j=0...7), a data unit size of 512*2^j bytes is supported.
      ; Bit 0 represents 512 bytes, 1 represents 1 KB, bit 7 represents 64 KB
      DataUnitSizeBitmask DWORD ?
    STORAGE_CRYPTO_CAPABILITY ends
    _STORAGE_CRYPTO_CAPABILITY typedef STORAGE_CRYPTO_CAPABILITY
    PSTORAGE_CRYPTO_CAPABILITY typedef ptr STORAGE_CRYPTO_CAPABILITY
    STORAGE_CRYPTO_DESCRIPTOR_VERSION_1 equ 1
    STORAGE_CRYPTO_DESCRIPTOR struct
      ; Keep compatible with STORAGE_DESCRIPTOR_HEADER
      ; Shall be set to STORAGE_CRYPTO_DESCRIPTOR_VERSION_1
      Version DWORD ?
      ; Keep compatible with STORAGE_DESCRIPTOR_HEADER
      ; Shall be set to sizeof(STORAGE_CRYPTO_DESCRIPTOR)
      Size_ DWORD ?
      ; The number of keys the crypto engine in the adapter supports
      NumKeysSupported DWORD ?
      ; The number of crypto capability entries. This outlines the
      ; crypto configurations the adapter supports
      NumCryptoCapabilities DWORD ?
      ; Array of Crypto Capabilities
      CryptoCapabilities STORAGE_CRYPTO_CAPABILITY ANYSIZE_ARRAY dup (<>)
    STORAGE_CRYPTO_DESCRIPTOR ends
    _STORAGE_CRYPTO_DESCRIPTOR typedef STORAGE_CRYPTO_DESCRIPTOR
    PSTORAGE_CRYPTO_DESCRIPTOR typedef ptr STORAGE_CRYPTO_DESCRIPTOR
    ;  The STORAGE_TIER is an identifier for the storage tier relative to the volume/LUN.
    ;  The storage tier ID for a particular volume has no relationship to the storage tier
    ;  ID with the same value on a different volume.
    STORAGE_TIER_NAME_LENGTH equ (256)
    STORAGE_TIER_DESCRIPTION_LENGTH equ (512)
    STORAGE_TIER_FLAG_NO_SEEK_PENALTY equ (00020000h)
    STORAGE_TIER_FLAG_WRITE_BACK_CACHE equ (00200000h)
    STORAGE_TIER_FLAG_READ_CACHE equ (00400000h)
    STORAGE_TIER_FLAG_PARITY equ (00800000h)
    STORAGE_TIER_FLAG_SMR equ (01000000h)
    STORAGE_TIER_MEDIA_TYPE typedef SDWORD
    StorageTierMediaTypeUnspecified equ 0
    StorageTierMediaTypeDisk equ 1
    StorageTierMediaTypeSsd equ 2
    StorageTierMediaTypeScm equ 4
    StorageTierMediaTypeMax equ 5
    _STORAGE_TIER_MEDIA_TYPE typedef STORAGE_TIER_MEDIA_TYPE
    PSTORAGE_TIER_MEDIA_TYPE typedef ptr STORAGE_TIER_MEDIA_TYPE
    STORAGE_TIER_CLASS typedef SDWORD
    StorageTierClassUnspecified equ 0
    StorageTierClassCapacity equ 1
    StorageTierClassPerformance equ 2
    StorageTierClassMax equ 3
    _STORAGE_TIER_CLASS typedef STORAGE_TIER_CLASS
    PSTORAGE_TIER_CLASS typedef ptr STORAGE_TIER_CLASS
    STORAGE_TIER struct
      ; Tier ID
      Id GUID <>
      ; Name for the tier
      Name_ WORD STORAGE_TIER_NAME_LENGTH dup (?)
      ; Note for the tier
      Description WORD STORAGE_TIER_NAME_LENGTH dup (?)
      ; Flags: STORAGE_TIER_FLAG_xxx
      Flags QWORD ?
      ; Provisioned capacity of the tier
      ProvisionedCapacity QWORD ?
      ; Media type of the tier
      MediaType STORAGE_TIER_MEDIA_TYPE ?
      ; Classification of the tier
      Class STORAGE_TIER_CLASS ?
    STORAGE_TIER ends
    _STORAGE_TIER typedef STORAGE_TIER
    PSTORAGE_TIER typedef ptr STORAGE_TIER
    ;  The response returns a single structure of STORAGE_DEVICE_TIERING_DESCRIPTOR that has
    ;  all the tiers for this disk.
    STORAGE_DEVICE_TIERING_DESCRIPTOR struct
      ; Size of this structure serves
      ; as the version
      Version DWORD ?
      ; Size of  this structure  plus
      ; all the variable sized fields
      Size_ DWORD ?
      ; Flags. The upper WORD   of these flags is reserved for file system use as
      ; this structure is returned slightly tweaked in FSCTL_QUERY_STORAGE_CLASSES_OUTPUT.
      Flags DWORD ?
      ; The total number of available tiers for this disk
      TotalNumberOfTiers DWORD ?
      ; The number of tiers that fit in the output
      NumberOfTiersReturned DWORD ?
      ; Detailed info on the storage tiers.
      Tiers STORAGE_TIER ANYSIZE_ARRAY dup (<>)
    STORAGE_DEVICE_TIERING_DESCRIPTOR ends
    _STORAGE_DEVICE_TIERING_DESCRIPTOR typedef STORAGE_DEVICE_TIERING_DESCRIPTOR
    PSTORAGE_DEVICE_TIERING_DESCRIPTOR typedef ptr STORAGE_DEVICE_TIERING_DESCRIPTOR
    ; Output buffer for StorageDeviceFaultDomainProperty & PropertyStandardQuery
    STORAGE_DEVICE_FAULT_DOMAIN_DESCRIPTOR struct
      ; Size of this structure serves
      ; as the version
      Version DWORD ?
      ; Size of  this structure  plus
      ; all the variable sized fields
      Size_ DWORD ?
      ; Number of fault domains
      NumberOfFaultDomains DWORD ?
      ; Fault domain ids
      FaultDomainIds GUID ANYSIZE_ARRAY dup (<>)
    STORAGE_DEVICE_FAULT_DOMAIN_DESCRIPTOR ends
    _STORAGE_DEVICE_FAULT_DOMAIN_DESCRIPTOR typedef STORAGE_DEVICE_FAULT_DOMAIN_DESCRIPTOR
    PSTORAGE_DEVICE_FAULT_DOMAIN_DESCRIPTOR typedef ptr STORAGE_DEVICE_FAULT_DOMAIN_DESCRIPTOR
    ; Parameters for StorageAdapterProtocolSpecificProperty (or StorageDeviceProtocolSpecificProperty) & PropertyStandardQuery
    ; Define the different storage command protocols that used between software and hardware.
    ; e.g. command protocol software uses to communicate with hardware.
    ; Protocol types below 128 (0x80) are reserved for Microsoft use.
    STORAGE_PROTOCOL_TYPE typedef SDWORD
    ProtocolTypeUnknown equ 00h
    ProtocolTypeScsi equ 1
    ProtocolTypeAta equ 2
    ProtocolTypeNvme equ 3
    ProtocolTypeSd equ 4
    ProtocolTypeUfs equ 5
    ProtocolTypeProprietary equ 7Eh
    ProtocolTypeMaxReserved equ 7Fh
    _STORAGE_PROTOCOL_TYPE typedef STORAGE_PROTOCOL_TYPE
    PSTORAGE_PROTOCOL_TYPE typedef ptr STORAGE_PROTOCOL_TYPE
    STORAGE_PROTOCOL_NVME_DATA_TYPE typedef SDWORD
    NVMeDataTypeUnknown equ 0
    NVMeDataTypeIdentify equ 1
    ; Retrieved by command - IDENTIFY CONTROLLER or IDENTIFY NAMESPACE
    ; Corresponding values in STORAGE_PROTOCOL_SPECIFIC_DATA,
    ;      ProtocolDataRequestValue - CNS as defined in NVME_IDENTIFY_CNS_CODES
    ;      ProtocolDataRequestSubValue - Namespace Id
    ;      ProtocolDataRequestSubValue2 - CNS Specific Id (CNSID)
    ;      ProtocolDataRequestSubValue3 - Controller Id (CNTID)
    ;      ProtocolDataRequestSubValue4 - Command Set Identifier (CSI)
    NVMeDataTypeLogPage equ 2
    ; Retrieved by command - GET LOG PAGE
    ; Corresponding values in STORAGE_PROTOCOL_SPECIFIC_DATA,
    ;      ProtocolDataRequestValue - Log page id
    ;      ProtocolDataRequestSubValue - Lower 32-bit offset value
    ;      ProtocolDataRequestSubValue2 - Upper 32-bit offset value
    ;      ProtocolDataRequestSubValue3 - Log specific identifier
    NVMeDataTypeFeature equ 3
    ; Retrieved by command - GET FEATURES
    ; Corresponding values in STORAGE_PROTOCOL_SPECIFIC_DATA,
    ;      ProtocolDataRequestValue - Defined in NVME_FEATURES
    ;      ProtocolDataRequestSubValue - Defined in NVME_CDW11_FEATURES
    _STORAGE_PROTOCOL_NVME_DATA_TYPE typedef STORAGE_PROTOCOL_NVME_DATA_TYPE
    PSTORAGE_PROTOCOL_NVME_DATA_TYPE typedef ptr STORAGE_PROTOCOL_NVME_DATA_TYPE
    STORAGE_PROTOCOL_ATA_DATA_TYPE typedef SDWORD
    AtaDataTypeUnknown equ 0
    AtaDataTypeIdentify equ 1
    ; Retrieved by command - IDENTIFY DEVICE
    AtaDataTypeLogPage equ 2
    ; Retrieved by command - READ LOG EXT
    _STORAGE_PROTOCOL_ATA_DATA_TYPE typedef STORAGE_PROTOCOL_ATA_DATA_TYPE
    PSTORAGE_PROTOCOL_ATA_DATA_TYPE typedef ptr STORAGE_PROTOCOL_ATA_DATA_TYPE
    STORAGE_PROTOCOL_UFS_DATA_TYPE typedef SDWORD
    UfsDataTypeUnknown equ 0
    UfsDataTypeQueryDescriptor equ 1
    ; Retrieved by command - QUERY UPIU
    UfsDataTypeQueryAttribute equ 2
    ; Retrieved by command - QUERY UPIU
    UfsDataTypeQueryFlag equ 3
    ; Retrieved by command - QUERY UPIU
    UfsDataTypeQueryDmeAttribute equ 4
    ; Retrieved by command - QUERY UPIU
    UfsDataTypeQueryDmePeerAttribute equ 5
    ; Retrieved by command - QUERY UPIU
    UfsDataTypeMax equ 6
    _STORAGE_PROTOCOL_UFS_DATA_TYPE typedef STORAGE_PROTOCOL_UFS_DATA_TYPE
    PSTORAGE_PROTOCOL_UFS_DATA_TYPE typedef ptr STORAGE_PROTOCOL_UFS_DATA_TYPE
    ; Below definition is used to specify particular command fields when querying
    ; NVMeDataTypeLogPage, and this definition maps to ProtocolDataRequestSubValue4
    ; field in STORAGE_PROTOCOL_SPECIFIC_DATA.
    ; nameless struct/unions
    ; bit fields other than int to disable this around the struct
    STORAGE_PROTOCOL_DATA_SUBVALUE_GET_LOG_PAGE union
      struct
        ANONYMOUS_REC0 record ANONYMOUS_REC0_Reserved:27, ANONYMOUS_REC0_LogSpecificField:4, ANONYMOUS_REC0_RetainAsynEvent:1
        ANONYMOUS_REC0 <>
      ends
      AsUlong DWORD ?
    STORAGE_PROTOCOL_DATA_SUBVALUE_GET_LOG_PAGE ends
    _STORAGE_PROTOCOL_DATA_SUBVALUE_GET_LOG_PAGE typedef STORAGE_PROTOCOL_DATA_SUBVALUE_GET_LOG_PAGE
    PSTORAGE_PROTOCOL_DATA_SUBVALUE_GET_LOG_PAGE typedef ptr STORAGE_PROTOCOL_DATA_SUBVALUE_GET_LOG_PAGE
    ; Protocol Data should follow this data structure in the same buffer.
    ; The offset of Protocol Data from the beginning of this data structure
    ; is reported in data field - "ProtocolDataOffset".
    STORAGE_PROTOCOL_SPECIFIC_DATA struct
      ProtocolType STORAGE_PROTOCOL_TYPE ?
      DataType DWORD ?
      ; The value will be protocol specific, as defined in STORAGE_PROTOCOL_NVME_DATA_TYPE or STORAGE_PROTOCOL_ATA_DATA_TYPE.
      ProtocolDataRequestValue DWORD ?
      ProtocolDataRequestSubValue DWORD ?
      ; Data sub request value
      ProtocolDataOffset DWORD ?
      ; The offset of data buffer is from beginning of this data structure.
      ProtocolDataLength DWORD ?
      FixedProtocolReturnData DWORD ?
      ProtocolDataRequestSubValue2 DWORD ?
      ; First additional data sub request value
      ProtocolDataRequestSubValue3 DWORD ?
      ; Second additional data sub request value
      ProtocolDataRequestSubValue4 DWORD ?
      ; Third additional data sub request value
    STORAGE_PROTOCOL_SPECIFIC_DATA ends
    _STORAGE_PROTOCOL_SPECIFIC_DATA typedef STORAGE_PROTOCOL_SPECIFIC_DATA
    PSTORAGE_PROTOCOL_SPECIFIC_DATA typedef ptr STORAGE_PROTOCOL_SPECIFIC_DATA
    ; Extended type incorporates both Get/Set protocol data
    ; Protocol Data should follow this data structure in the same buffer.
    ; The offset of Protocol Data from the beginning of this data structure
    ; is reported in data field - "ProtocolDataOffset".
    STORAGE_PROTOCOL_SPECIFIC_DATA_EXT struct
      ProtocolType STORAGE_PROTOCOL_TYPE ?
      DataType DWORD ?
      ; The value will be protocol specific, as defined in STORAGE_PROTOCOL_NVME_DATA_TYPE or STORAGE_PROTOCOL_ATA_DATA_TYPE.
      ProtocolDataValue DWORD ?
      ProtocolDataSubValue DWORD ?
      ; Data sub request value
      ProtocolDataOffset DWORD ?
      ; The offset of data buffer is from beginning of this data structure.
      ProtocolDataLength DWORD ?
      FixedProtocolReturnData DWORD ?
      ProtocolDataSubValue2 DWORD ?
      ; First additional data sub request value
      ProtocolDataSubValue3 DWORD ?
      ; Second additional data sub request value
      ProtocolDataSubValue4 DWORD ?
      ; Third additional data sub request value
      ProtocolDataSubValue5 DWORD ?
      ; Fourth additional data sub request value
      Reserved DWORD 5 dup (?)
    STORAGE_PROTOCOL_SPECIFIC_DATA_EXT ends
    _STORAGE_PROTOCOL_SPECIFIC_DATA_EXT typedef STORAGE_PROTOCOL_SPECIFIC_DATA_EXT
    PSTORAGE_PROTOCOL_SPECIFIC_DATA_EXT typedef ptr STORAGE_PROTOCOL_SPECIFIC_DATA_EXT
    ; Input parameters for StorageAdapterProtocolSpecificProperty (or StorageDeviceProtocolSpecificProperty) & PropertyStandardQuery
    ; will be data structure STORAGE_PROPERTY_QUERY, where the data field "AdditionalParameters" is a buffer
    ; in format of STORAGE_PROTOCOL_SPECIFIC_DATA.
    ; Out parameters for StorageAdapterProtocolSpecificProperty (or StorageDeviceProtocolSpecificProperty) & PropertyStandardQuery
    STORAGE_PROTOCOL_DATA_DESCRIPTOR struct
      Version DWORD ?
      Size_ DWORD ?
      ProtocolSpecificData STORAGE_PROTOCOL_SPECIFIC_DATA <>
    STORAGE_PROTOCOL_DATA_DESCRIPTOR ends
    _STORAGE_PROTOCOL_DATA_DESCRIPTOR typedef STORAGE_PROTOCOL_DATA_DESCRIPTOR
    PSTORAGE_PROTOCOL_DATA_DESCRIPTOR typedef ptr STORAGE_PROTOCOL_DATA_DESCRIPTOR
    ; Input parameters for StorageAdapterProtocolSpecificProperty (or StorageDeviceProtocolSpecificProperty) & PropertyStandardQuery (or PropertyStandardSet)
    ; will be data structure STORAGE_PROPERTY_QUERY/STORAGE_PROPERTY_SET, where the data field "AdditionalParameters" is a buffer
    ; in format of STORAGE_PROTOCOL_SPECIFIC_DATA.
    ; Out parameters for StorageAdapterProtocolSpecificProperty (or StorageDeviceProtocolSpecificProperty) & PropertyStandardQuery (or PropertyStandardSet)
    STORAGE_PROTOCOL_DATA_DESCRIPTOR_EXT struct
      Version DWORD ?
      Size_ DWORD ?
      ProtocolSpecificData STORAGE_PROTOCOL_SPECIFIC_DATA_EXT <>
    STORAGE_PROTOCOL_DATA_DESCRIPTOR_EXT ends
    _STORAGE_PROTOCOL_DATA_DESCRIPTOR_EXT typedef STORAGE_PROTOCOL_DATA_DESCRIPTOR_EXT
    PSTORAGE_PROTOCOL_DATA_DESCRIPTOR_EXT typedef ptr STORAGE_PROTOCOL_DATA_DESCRIPTOR_EXT
    ; Parameters for StorageAdapterTemperatureProperty (or StorageDeviceTemperatureProperty) & PropertyStandardQuery
    ; Input parameters for StorageAdapterTemperatureProperty (or StorageDeviceTemperatureProperty) & PropertyStandardQuery
    ; uses data structure STORAGE_PROPERTY_QUERY.
    ; Out parameters for StorageAdapterTemperatureProperty (or StorageDeviceTemperatureProperty) & PropertyStandardQuery
    ; For temperature/threshold data fields, the smallest value of SHORT type - 0x8000 indicates the value is not reported.
    STORAGE_TEMPERATURE_VALUE_NOT_REPORTED equ 8000h
    STORAGE_TEMPERATURE_INFO struct
      Index WORD ?
      ; Starts from 0. Index 0 may indicate a composite value.
      Temperature SWORD ?
      ; Signed value; in Celsius.
      OverThreshold SWORD ?
      ; Signed value; in Celsius.
      UnderThreshold SWORD ?
      ; Signed value; in Celsius.
      OverThresholdChangable BYTE ?
      ; Can the threshold value being changed by using IOCTL_STORAGE_SET_TEMPERATURE_THRESHOLD.
      UnderThresholdChangable BYTE ?
      ; Can the threshold value being changed by using IOCTL_STORAGE_SET_TEMPERATURE_THRESHOLD.
      EventGenerated BYTE ?
      ; Indicates that notification will be generated when temperature cross threshold.
      Reserved0 BYTE ?
      Reserved1 DWORD ?
    STORAGE_TEMPERATURE_INFO ends
    _STORAGE_TEMPERATURE_INFO typedef STORAGE_TEMPERATURE_INFO
    PSTORAGE_TEMPERATURE_INFO typedef ptr STORAGE_TEMPERATURE_INFO
    STORAGE_TEMPERATURE_DATA_DESCRIPTOR struct
      Version DWORD ?
      Size_ DWORD ?
      ; Indicates the maximum temperature in degrees Celsius that may prevent continued normal operation,
      ; possibility of data loss, automatic device shutdown, extreme performance throttling, or permanent damage.
      CriticalTemperature SWORD ?
      ; Signed value; in Celsius.
      ; Indicates the maximum temperature in degrees Celsius at which the device is capable of
      ; operating continuously without degrading operation or reliability.
      WarningTemperature SWORD ?
      ; Signed value; in Celsius.
      InfoCount WORD ?
      ; Some devices may report more than one temperature information as there can be multiple sensors implemented.
      Reserved0 BYTE 2 dup (?)
      Reserved1 DWORD 2 dup (?)
      TemperatureInfo STORAGE_TEMPERATURE_INFO ANYSIZE_ARRAY dup (<>)
    STORAGE_TEMPERATURE_DATA_DESCRIPTOR ends
    _STORAGE_TEMPERATURE_DATA_DESCRIPTOR typedef STORAGE_TEMPERATURE_DATA_DESCRIPTOR
    PSTORAGE_TEMPERATURE_DATA_DESCRIPTOR typedef ptr STORAGE_TEMPERATURE_DATA_DESCRIPTOR
    ; Input parameters for IOCTL_STORAGE_SET_TEMPERATURE_THRESHOLD
    ; Indicate the target of the request other than the device handle/object itself.
    ; This is used in "Flags" field of data structures.
    STORAGE_TEMPERATURE_THRESHOLD_FLAG_ADAPTER_REQUEST equ 0001h
    STORAGE_TEMPERATURE_THRESHOLD struct
      Version DWORD ?
      Size_ DWORD ?
      Flags WORD ?
      Index WORD ?
      Threshold SWORD ?
      ; Signed value; in Celsius.
      OverThreshold BYTE ?
      ; If TRUE, set the OverThreshold value; Otherwise, set the UnderThreshold value.
      Reserved BYTE ?
    STORAGE_TEMPERATURE_THRESHOLD ends
    _STORAGE_TEMPERATURE_THRESHOLD typedef STORAGE_TEMPERATURE_THRESHOLD
    PSTORAGE_TEMPERATURE_THRESHOLD typedef ptr STORAGE_TEMPERATURE_THRESHOLD
    ; Parameters for StorageAdapterPhysicalTopologyProperty (or StorageDevicePhysicalTopologyProperty) & PropertyStandardQuery
    ; Input parameters for StorageAdapterPhysicalTopologyProperty (or StorageDevicePhysicalTopologyProperty) & PropertyStandardQuery
    ; uses data structure STORAGE_PROPERTY_QUERY.
    ; Out parameters for StorageAdapterPhysicalTopologyProperty (or StorageDevicePhysicalTopologyProperty) & PropertyStandardQuery
    ; uses data structure STORAGE_PHYSICAL_TOPOLOGY_DESCRIPTOR
    ; Multiple roles are allowed for a single device.
    STORAGE_COMPONENT_ROLE_CACHE equ 00000001h
    STORAGE_COMPONENT_ROLE_TIERING equ 00000002h
    STORAGE_COMPONENT_ROLE_DATA equ 00000004h
    STORAGE_DEVICE_FORM_FACTOR typedef SDWORD
    FormFactorUnknown equ 0
    FormFactor3_5 equ 1
    ; 3.5 inch nominal form factor
    FormFactor2_5 equ 2
    ; 2.5 inch nominal form factor
    FormFactor1_8 equ 3
    ; 1.8 inch nominal form factor
    FormFactor1_8Less equ 4
    ; Less than 1.8 inch nominal form factor
    FormFactorEmbedded equ 5
    ; Embedded on board.
    FormFactorMemoryCard equ 6
    ; Memory card such as SD, CF.
    FormFactormSata equ 7
    ; mSATA
    FormFactorM_2 equ 8
    ; M.2
    FormFactorPCIeBoard equ 9
    ; PCIe card plug into slot.
    FormFactorDimm equ 10
    ; DIMM Slot
    _STORAGE_DEVICE_FORM_FACTOR typedef STORAGE_DEVICE_FORM_FACTOR
    PSTORAGE_DEVICE_FORM_FACTOR typedef ptr STORAGE_DEVICE_FORM_FACTOR
    STORAGE_COMPONENT_HEALTH_STATUS typedef SDWORD
    HealthStatusUnknown equ 0
    HealthStatusNormal equ 1
    HealthStatusThrottled equ 2
    HealthStatusWarning equ 3
    HealthStatusDisabled equ 4
    HealthStatusFailed equ 5
    _STORAGE_COMPONENT_HEALTH_STATUS typedef STORAGE_COMPONENT_HEALTH_STATUS
    PSTORAGE_COMPONENT_HEALTH_STATUS typedef ptr STORAGE_COMPONENT_HEALTH_STATUS
    ; nameless struct/unions
    STORAGE_SPEC_VERSION union
      struct
        union MinorVersion
          struct
            SubMinor BYTE ?
            Minor BYTE ?
          ends
          AsUshort WORD ?
        ends
        MajorVersion WORD ?
      ends
      AsUlong DWORD ?
    STORAGE_SPEC_VERSION ends
    _STORAGE_SPEC_VERSION typedef STORAGE_SPEC_VERSION
    PSTORAGE_SPEC_VERSION typedef ptr STORAGE_SPEC_VERSION
    STORAGE_PHYSICAL_DEVICE_DATA struct
      DeviceId DWORD ?
      Role DWORD ?
      ; Value(s) of bitmask from STORAGE_COMPONENT_ROLE_xxx
      HealthStatus STORAGE_COMPONENT_HEALTH_STATUS ?
      CommandProtocol STORAGE_PROTOCOL_TYPE ?
      SpecVersion STORAGE_SPEC_VERSION <>
      ; Supported storage spec version. For example: SBC 3, SATA 3.2, NVMe 1.2
      FormFactor STORAGE_DEVICE_FORM_FACTOR ?
      Vendor BYTE 8 dup (?)
      Model BYTE 40 dup (?)
      FirmwareRevision BYTE 16 dup (?)
      Capacity QWORD ?
      ; in unit of Kilo-Bytes (1024 bytes).
      PhysicalLocation BYTE 32 dup (?)
      ; Reserved for future.
      Reserved DWORD 2 dup (?)
    STORAGE_PHYSICAL_DEVICE_DATA ends
    _STORAGE_PHYSICAL_DEVICE_DATA typedef STORAGE_PHYSICAL_DEVICE_DATA
    PSTORAGE_PHYSICAL_DEVICE_DATA typedef ptr STORAGE_PHYSICAL_DEVICE_DATA
    STORAGE_PHYSICAL_ADAPTER_DATA struct
      AdapterId DWORD ?
      HealthStatus STORAGE_COMPONENT_HEALTH_STATUS ?
      CommandProtocol STORAGE_PROTOCOL_TYPE ?
      SpecVersion STORAGE_SPEC_VERSION <>
      ; Supported storage spec version. For example: AHCI 1.3.1
      Vendor BYTE 8 dup (?)
      Model BYTE 40 dup (?)
      FirmwareRevision BYTE 16 dup (?)
      PhysicalLocation BYTE 32 dup (?)
      ; Reserve for future.
      ExpanderConnected BYTE ?
      Reserved0 BYTE 3 dup (?)
      Reserved1 DWORD 3 dup (?)
    STORAGE_PHYSICAL_ADAPTER_DATA ends
    _STORAGE_PHYSICAL_ADAPTER_DATA typedef STORAGE_PHYSICAL_ADAPTER_DATA
    PSTORAGE_PHYSICAL_ADAPTER_DATA typedef ptr STORAGE_PHYSICAL_ADAPTER_DATA
    STORAGE_PHYSICAL_NODE_DATA struct
      NodeId DWORD ?
      AdapterCount DWORD ?
      ; 0 or 1
      AdapterDataLength DWORD ?
      AdapterDataOffset DWORD ?
      ; Offset from beginning of this data structure. The buffer contains an array of STORAGE_PHYSICAL_ADAPTER_DATA.
      DeviceCount DWORD ?
      ; >= 1
      DeviceDataLength DWORD ?
      DeviceDataOffset DWORD ?
      ; Offset from beginning of this data structure. The buffer contains an array of STORAGE_PHYSICAL_DEVICE_DATA.
      Reserved DWORD 3 dup (?)
    STORAGE_PHYSICAL_NODE_DATA ends
    _STORAGE_PHYSICAL_NODE_DATA typedef STORAGE_PHYSICAL_NODE_DATA
    PSTORAGE_PHYSICAL_NODE_DATA typedef ptr STORAGE_PHYSICAL_NODE_DATA
    STORAGE_PHYSICAL_TOPOLOGY_DESCRIPTOR struct
      Version DWORD ?
      ; sizeof(STORAGE_PHYSICAL_TOPOLOGY_DESCRIPTOR)
      Size_ DWORD ?
      ; Total size of the data. Should be >= sizeof(STORAGE_PHYSICAL_TOPOLOGY_DESCRIPTOR)
      NodeCount DWORD ?
      Reserved DWORD ?
      Node STORAGE_PHYSICAL_NODE_DATA ANYSIZE_ARRAY dup (<>)
    STORAGE_PHYSICAL_TOPOLOGY_DESCRIPTOR ends
    _STORAGE_PHYSICAL_TOPOLOGY_DESCRIPTOR typedef STORAGE_PHYSICAL_TOPOLOGY_DESCRIPTOR
    PSTORAGE_PHYSICAL_TOPOLOGY_DESCRIPTOR typedef ptr STORAGE_PHYSICAL_TOPOLOGY_DESCRIPTOR
    ; Output buffer for StorageDeviceIoCapabilityProperty & PropertyStandardQuery
    STORAGE_DEVICE_IO_CAPABILITY_DESCRIPTOR struct
      ; Size of this structure serves
      ; as the version
      Version DWORD ?
      ; Size of this structure
      Size_ DWORD ?
      ; LUN max outstanding IO count
      LunMaxIoCount DWORD ?
      ; Adapter max outstanding IO count
      AdapterMaxIoCount DWORD ?
    STORAGE_DEVICE_IO_CAPABILITY_DESCRIPTOR ends
    _STORAGE_DEVICE_IO_CAPABILITY_DESCRIPTOR typedef STORAGE_DEVICE_IO_CAPABILITY_DESCRIPTOR
    PSTORAGE_DEVICE_IO_CAPABILITY_DESCRIPTOR typedef ptr STORAGE_DEVICE_IO_CAPABILITY_DESCRIPTOR
    ; Output buffer for StorageDeviceAttributesProperty & PropertyStandardQuery
    STORAGE_DEVICE_ATTRIBUTES_DESCRIPTOR struct
      ; Size of this structure serves
      ; as the version
      Version DWORD ?
      ; Size of this structure
      Size_ DWORD ?
      ; Attributes (bit flags)
      Attributes QWORD ?
    STORAGE_DEVICE_ATTRIBUTES_DESCRIPTOR ends
    _STORAGE_DEVICE_ATTRIBUTES_DESCRIPTOR typedef STORAGE_DEVICE_ATTRIBUTES_DESCRIPTOR
    PSTORAGE_DEVICE_ATTRIBUTES_DESCRIPTOR typedef ptr STORAGE_DEVICE_ATTRIBUTES_DESCRIPTOR
    ; Storage Device Attributes Flags
    STORAGE_ATTRIBUTE_BYTE_ADDRESSABLE_IO equ 01h
    STORAGE_ATTRIBUTE_BLOCK_IO equ 02h
    STORAGE_ATTRIBUTE_DYNAMIC_PERSISTENCE equ 04h
    STORAGE_ATTRIBUTE_VOLATILE equ 08h
    STORAGE_ATTRIBUTE_ASYNC_EVENT_NOTIFICATION equ 10h
    STORAGE_ATTRIBUTE_PERF_SIZE_INDEPENDENT equ 20h
    ; Constants for StorageDeviceManagementStatus
    STORAGE_DISK_HEALTH_STATUS typedef SDWORD
    DiskHealthUnknown equ 0
    DiskHealthUnhealthy equ 1
    DiskHealthWarning equ 2
    DiskHealthHealthy equ 3
    DiskHealthMax equ 4
    _STORAGE_DISK_HEALTH_STATUS typedef STORAGE_DISK_HEALTH_STATUS
    PSTORAGE_DISK_HEALTH_STATUS typedef ptr STORAGE_DISK_HEALTH_STATUS
    ; Operational States
    STORAGE_DISK_OPERATIONAL_STATUS typedef SDWORD
    DiskOpStatusNone equ 0
    DiskOpStatusUnknown equ 1
    DiskOpStatusOk equ 2
    DiskOpStatusPredictingFailure equ 3
    DiskOpStatusInService equ 4
    DiskOpStatusHardwareError equ 5
    DiskOpStatusNotUsable equ 6
    DiskOpStatusTransientError equ 7
    DiskOpStatusMissing equ 8
    _STORAGE_DISK_OPERATIONAL_STATUS typedef STORAGE_DISK_OPERATIONAL_STATUS
    PSTORAGE_DISK_OPERATIONAL_STATUS typedef ptr STORAGE_DISK_OPERATIONAL_STATUS
    ; Operational Reasons
    STORAGE_OPERATIONAL_STATUS_REASON typedef SDWORD
    DiskOpReasonUnknown equ 0
    DiskOpReasonScsiSenseCode equ 1
    DiskOpReasonMedia equ 2
    DiskOpReasonIo equ 3
    DiskOpReasonThresholdExceeded equ 4
    DiskOpReasonLostData equ 5
    DiskOpReasonEnergySource equ 6
    DiskOpReasonConfiguration equ 7
    DiskOpReasonDeviceController equ 8
    DiskOpReasonMediaController equ 9
    DiskOpReasonComponent equ 10
    DiskOpReasonNVDIMM_N equ 11
    DiskOpReasonBackgroundOperation equ 12
    DiskOpReasonInvalidFirmware equ 13
    DiskOpReasonHealthCheck equ 14
    DiskOpReasonLostDataPersistence equ 15
    DiskOpReasonDisabledByPlatform equ 16
    DiskOpReasonLostWritePersistence equ 17
    DiskOpReasonDataPersistenceLossImminent equ 18
    DiskOpReasonWritePersistenceLossImminent equ 19
    DiskOpReasonMax equ 20
    _STORAGE_OPERATIONAL_STATUS_REASON typedef STORAGE_OPERATIONAL_STATUS_REASON
    PSTORAGE_OPERATIONAL_STATUS_REASON typedef ptr STORAGE_OPERATIONAL_STATUS_REASON
    STORAGE_OPERATIONAL_REASON struct
      Version DWORD ?
      Size_ DWORD ?
      Reason STORAGE_OPERATIONAL_STATUS_REASON ?
      union RawBytes
        ; This is the format if Reason == DiskOpReasonScsiSenseCode.
        struct ScsiSenseKey
          SenseKey BYTE ?
          ASC BYTE ?
          ASCQ BYTE ?
          Reserved BYTE ?
        ends
        ; This is the format if Reason == DiskOpReasonNVDIMM_N.
        struct NVDIMM_N
          CriticalHealth BYTE ?
          ModuleHealth BYTE 2 dup (?)
          ErrorThresholdStatus BYTE ?
        ends
        AsUlong DWORD ?
      ends
    STORAGE_OPERATIONAL_REASON ends
    _STORAGE_OPERATIONAL_REASON typedef STORAGE_OPERATIONAL_REASON
    PSTORAGE_OPERATIONAL_REASON typedef ptr STORAGE_OPERATIONAL_REASON
    ; Output buffer for StorageDeviceManagementStatus & PropertyStandardQuery
    STORAGE_DEVICE_MAX_OPERATIONAL_STATUS equ 16
    STORAGE_DEVICE_MANAGEMENT_STATUS struct
      ; Sizeof() of this structure serves
      ; as the version.
      Version DWORD ?
      ; The total size of the structure, including operational status reasons
      ; that didn't fit in the caller's array. Callers should use this field to learn
      ; how big the input buffer should be to contain all the available information.
      Size_ DWORD ?
      ; Health status.
      Health STORAGE_DISK_HEALTH_STATUS ?
      ; The number of operational status returned.
      NumberOfOperationalStatus DWORD ?
      ; The number of additional reasons returned.
      NumberOfAdditionalReasons DWORD ?
      ; Operational statuses. The primary operational status is the first element
      ; in the array. There are NumberOfOperationalStatus valid elements in the array.
      OperationalStatus STORAGE_DISK_OPERATIONAL_STATUS STORAGE_DEVICE_MAX_OPERATIONAL_STATUS dup (?)
      ; Additional reasons. There are NumberOfAdditionalReasons valid elements in the array.
      AdditionalReasons STORAGE_OPERATIONAL_REASON ANYSIZE_ARRAY dup (<>)
    STORAGE_DEVICE_MANAGEMENT_STATUS ends
    _STORAGE_DEVICE_MANAGEMENT_STATUS typedef STORAGE_DEVICE_MANAGEMENT_STATUS
    PSTORAGE_DEVICE_MANAGEMENT_STATUS typedef ptr STORAGE_DEVICE_MANAGEMENT_STATUS
    ; Parameter for StorageAdapterSerialNumberProperty.
    ; Use this to get the serial number of the storage adapter.  Note that not all
    ; controllers and host controller interfaces may provide a serial number for
    ; the adapter.  If the serial number is malformed or cannot be obtained this
    ; query will fail.
    ; The serial number can have a maximum of 128 Unicode characters, including
    ; the trailing NULL character.
    STORAGE_ADAPTER_SERIAL_NUMBER_V1_MAX_LENGTH equ (128)
    STORAGE_ADAPTER_SERIAL_NUMBER struct
      Version DWORD ?
      Size_ DWORD ?
      ; NULL-terminated Unicode string of the adapter's serial number.
      SerialNumber WORD STORAGE_ADAPTER_SERIAL_NUMBER_V1_MAX_LENGTH dup (?)
    STORAGE_ADAPTER_SERIAL_NUMBER ends
    _STORAGE_ADAPTER_SERIAL_NUMBER typedef STORAGE_ADAPTER_SERIAL_NUMBER
    PSTORAGE_ADAPTER_SERIAL_NUMBER typedef ptr STORAGE_ADAPTER_SERIAL_NUMBER
    STORAGE_ADAPTER_SERIAL_NUMBER_V1_VERSION equ <(sizeof(STORAGE_ADAPTER_SERIAL_NUMBER))>
    STORAGE_ADAPTER_SERIAL_NUMBER_V1_SIZE equ <(sizeof(STORAGE_ADAPTER_SERIAL_NUMBER))>
    ; Output buffer for StorageDeviceZonedDeviceProperty & PropertyStandardQuery
    STORAGE_ZONED_DEVICE_TYPES typedef SDWORD
    ZonedDeviceTypeUnknown equ 0
    ZonedDeviceTypeHostManaged equ 1
    ZonedDeviceTypeHostAware equ 2
    ZonedDeviceTypeDeviceManaged equ 3
    _STORAGE_ZONED_DEVICE_TYPES typedef STORAGE_ZONED_DEVICE_TYPES
    PSTORAGE_ZONED_DEVICE_TYPES typedef ptr STORAGE_ZONED_DEVICE_TYPES
    STORAGE_ZONE_TYPES typedef SDWORD
    ZoneTypeUnknown equ 0
    ZoneTypeConventional equ 1
    ZoneTypeSequentialWriteRequired equ 2
    ZoneTypeSequentialWritePreferred equ 3
    ZoneTypeMax equ 4
    _STORAGE_ZONE_TYPES typedef STORAGE_ZONE_TYPES
    PSTORAGE_ZONE_TYPES typedef ptr STORAGE_ZONE_TYPES
    STORAGE_ZONE_GROUP struct
      ZoneCount DWORD ?
      ; Count of zones in this group.
      ZoneType STORAGE_ZONE_TYPES ?
      ZoneSize QWORD ?
      ; In Bytes
    STORAGE_ZONE_GROUP ends
    _STORAGE_ZONE_GROUP typedef STORAGE_ZONE_GROUP
    PSTORAGE_ZONE_GROUP typedef ptr STORAGE_ZONE_GROUP
    STORAGE_ZONED_DEVICE_DESCRIPTOR struct
      ; Size of this structure serves as the version
      Version DWORD ?
      ; Size of buffer. The returned value indicates how big the buffer should be
      ; to store complete data.
      Size_ DWORD ?
      ; Zoned device type
      DeviceType STORAGE_ZONED_DEVICE_TYPES ?
      ; Total zone count
      ZoneCount DWORD ?
      ; Zone Attributes
      union ZoneAttributes
        struct SequentialRequiredZone
          MaxOpenZoneCount DWORD ?
          UnrestrictedRead BYTE ?
          Reserved BYTE 3 dup (?)
        ends
        ; Host managed device only
        struct SequentialPreferredZone
          OptimalOpenZoneCount DWORD ?
          Reserved DWORD ?
        ends
        ; Host aware device only
      ends
      ; Zone Layout Information, to provide a picture about locations of different type of zones on disk.
      ; The zone layout starts from the first zone, and groups together zones with same type and size.
      ZoneGroupCount DWORD ?
      ZoneGroup STORAGE_ZONE_GROUP ANYSIZE_ARRAY dup (<>)
    STORAGE_ZONED_DEVICE_DESCRIPTOR ends
    _STORAGE_ZONED_DEVICE_DESCRIPTOR typedef STORAGE_ZONED_DEVICE_DESCRIPTOR
    PSTORAGE_ZONED_DEVICE_DESCRIPTOR typedef ptr STORAGE_ZONED_DEVICE_DESCRIPTOR
    ; Output buffer for StorageDeviceLocationProperty & PropertyStandardQuery
    ; nameless struct/unions
    DEVICE_LOCATION struct
      Socket DWORD ?
      Slot DWORD ?
      Adapter DWORD ?
      Port DWORD ?
      union
        struct
          Channel DWORD ?
          Device DWORD ?
        ends
        struct
          Target DWORD ?
          Lun DWORD ?
        ends
      ends
    DEVICE_LOCATION ends
    _DEVICE_LOCATION typedef DEVICE_LOCATION
    PDEVICE_LOCATION typedef ptr DEVICE_LOCATION
    STORAGE_DEVICE_LOCATION_DESCRIPTOR struct
      Version DWORD ?
      Size_ DWORD ?
      Location DEVICE_LOCATION <>
      StringOffset DWORD ?
    STORAGE_DEVICE_LOCATION_DESCRIPTOR ends
    _STORAGE_DEVICE_LOCATION_DESCRIPTOR typedef STORAGE_DEVICE_LOCATION_DESCRIPTOR
    PSTORAGE_DEVICE_LOCATION_DESCRIPTOR typedef ptr STORAGE_DEVICE_LOCATION_DESCRIPTOR
    ; Output buffer for StorageDeviceNumaProperty.
    ; If the query for this property is successful, then the caller should
    ; validate the NumaNode field before using it to optimize any operations.
    ; That is, the caller should ensure the NumaNode value is less than or equal
    ; to the system's highest NUMA node value and the NumaNode value is not equal
    ; to STORAGE_DEVICE_NUMA_NODE_UNKNOWN.
    STORAGE_DEVICE_NUMA_PROPERTY struct
      Version DWORD ?
      Size_ DWORD ?
      NumaNode DWORD ?
    STORAGE_DEVICE_NUMA_PROPERTY ends
    _STORAGE_DEVICE_NUMA_PROPERTY typedef STORAGE_DEVICE_NUMA_PROPERTY
    PSTORAGE_DEVICE_NUMA_PROPERTY typedef ptr STORAGE_DEVICE_NUMA_PROPERTY
    STORAGE_DEVICE_NUMA_NODE_UNKNOWN equ <MAXDWORD>
    ; Output buffer for StorageDeviceUnsafeShutdownCount.
    ; On persistent memory devices, the unsafe shutdown count is the number of times
    ; the logical persistent memory disk was shut down in a way that might have caused
    ; data loss.
    STORAGE_DEVICE_UNSAFE_SHUTDOWN_COUNT struct
      Version DWORD ?
      Size_ DWORD ?
      UnsafeShutdownCount DWORD ?
    STORAGE_DEVICE_UNSAFE_SHUTDOWN_COUNT ends
    _STORAGE_DEVICE_UNSAFE_SHUTDOWN_COUNT typedef STORAGE_DEVICE_UNSAFE_SHUTDOWN_COUNT
    PSTORAGE_DEVICE_UNSAFE_SHUTDOWN_COUNT typedef ptr STORAGE_DEVICE_UNSAFE_SHUTDOWN_COUNT
    ; bit fields other than int to disable this around the struct
    ; nameless struct/union
    ; Parameters for StorageDeviceEnduranceProperty & PropertyStandardQuery
    ; Input parameters for StorageDeviceEnduranceProperty & PropertyStandardQuery
    ; uses data structure STORAGE_PROPERTY_QUERY.
    ; Out parameters for StorageDeviceEnduranceProperty  & PropertyStandardQuery
    ; For endurance info fields, ValidFields represents bit mapping of valid fields.
    STORAGE_HW_ENDURANCE_INFO struct
      ValidFields DWORD ?
      ; ValidFields represents bit mapping of valid fields of any type
      ; Eg: Bit 0 stands for GroupId, Bit 1 stands for Flags, Bit 3 for BytesReadCount
      GroupId DWORD ?
      ; Set Id Eg: Set Id for NVMe sets
      struct Flags
        ; TRUE if information is shared with multiple units/groups
        Flags_REC record Flags_REC_Reserved:31, Flags_REC_Shared:1
        Flags_BITS Flags_REC <>
      ends
      LifePercentage DWORD ?
      ; Used life percentage
      BytesReadCount BYTE 16 dup (?)
      ; Total bytes read from device (Billion Unit)
      ByteWriteCount BYTE 16 dup (?)
      ; Total bytes written to device (Billion Unit)
    STORAGE_HW_ENDURANCE_INFO ends
    _STORAGE_HW_ENDURANCE_INFO typedef STORAGE_HW_ENDURANCE_INFO
    PSTORAGE_HW_ENDURANCE_INFO typedef ptr STORAGE_HW_ENDURANCE_INFO
    STORAGE_HW_ENDURANCE_DATA_DESCRIPTOR struct
      Version DWORD ?
      ; keep compatible with STORAGE_DESCRIPTOR_HEADER
      Size_ DWORD ?
      ; keep compatible with STORAGE_DESCRIPTOR_HEADER
      EnduranceInfo STORAGE_HW_ENDURANCE_INFO <>
      ; Endurance Information of the device
    STORAGE_HW_ENDURANCE_DATA_DESCRIPTOR ends
    _STORAGE_HW_ENDURANCE_DATA_DESCRIPTOR typedef STORAGE_HW_ENDURANCE_DATA_DESCRIPTOR
    PSTORAGE_HW_ENDURANCE_DATA_DESCRIPTOR typedef ptr STORAGE_HW_ENDURANCE_DATA_DESCRIPTOR
    ; Output buffer for StorageDeviceLedStateProperty.
    STORAGE_DEVICE_LED_STATE_DESCRIPTOR struct
      Version DWORD ?
      Size_ DWORD ?
      State QWORD ?
    STORAGE_DEVICE_LED_STATE_DESCRIPTOR ends
    _STORAGE_DEVICE_LED_STATE_DESCRIPTOR typedef STORAGE_DEVICE_LED_STATE_DESCRIPTOR
    PSTORAGE_DEVICE_LED_STATE_DESCRIPTOR typedef ptr STORAGE_DEVICE_LED_STATE_DESCRIPTOR
    ; Output buffer for StorageDeviceSelfEncryptionProperty.
    ; Version 1 of the structure
    ; Note: This version only checks if the storage device
    ;       is eDrive capable to keep it backward compatible.
    ;       To handle both eDrive and native TCG implementations
    ;       use Version 2 of the structure.
    STORAGE_DEVICE_SELF_ENCRYPTION_PROPERTY struct
      Version DWORD ?
      ; Sizeof(STORAGE_DEVICE_SELF_ENCRYPTION_PROPERTY)
      Size_ DWORD ?
      SupportsSelfEncryption BYTE ?
    STORAGE_DEVICE_SELF_ENCRYPTION_PROPERTY ends
    _STORAGE_DEVICE_SELF_ENCRYPTION_PROPERTY typedef STORAGE_DEVICE_SELF_ENCRYPTION_PROPERTY
    PSTORAGE_DEVICE_SELF_ENCRYPTION_PROPERTY typedef ptr STORAGE_DEVICE_SELF_ENCRYPTION_PROPERTY
    STORAGE_ENCRYPTION_TYPE typedef SDWORD
    StorageEncryptionTypeUnknown equ 00h
    StorageEncryptionTypeEDrive equ 01h
    StorageEncryptionTypeTcgOpal equ 02h
    _STORAGE_ENCRYPTION_TYPE typedef STORAGE_ENCRYPTION_TYPE
    PSTORAGE_ENCRYPTION_TYPE typedef ptr STORAGE_ENCRYPTION_TYPE
    ; Version 2 of the structure
    ; Note: This version handles both eDrive and native TCG implementations.
    ;       To check if a storage device supports a native TCG implementation,
    ;       a client must use this version of the structure.
    STORAGE_DEVICE_SELF_ENCRYPTION_PROPERTY_V2 struct
      Version DWORD ?
      ; Sizeof(STORAGE_DEVICE_SELF_ENCRYPTION_PROPERTY_V2)
      Size_ DWORD ?
      SupportsSelfEncryption BYTE ?
      EncryptionType STORAGE_ENCRYPTION_TYPE ?
    STORAGE_DEVICE_SELF_ENCRYPTION_PROPERTY_V2 ends
    _STORAGE_DEVICE_SELF_ENCRYPTION_PROPERTY_V2 typedef STORAGE_DEVICE_SELF_ENCRYPTION_PROPERTY_V2
    PSTORAGE_DEVICE_SELF_ENCRYPTION_PROPERTY_V2 typedef ptr STORAGE_DEVICE_SELF_ENCRYPTION_PROPERTY_V2
    ; Output buffer for StorageFruIdProperty.
    STORAGE_FRU_ID_DESCRIPTOR struct
      ; Sizeof(STORAGE_FRU_ID_DESCRIPTOR)
      Version DWORD ?
      ; Total size of the data.
      ; Should be >= sizeof(STORAGE_FRU_ID_DESCRIPTOR)
      Size_ DWORD ?
      ; The identifier is a variable length array of bytes.
      IdentifierSize DWORD ?
      Identifier BYTE ANYSIZE_ARRAY dup (?)
    STORAGE_FRU_ID_DESCRIPTOR ends
    _STORAGE_FRU_ID_DESCRIPTOR typedef STORAGE_FRU_ID_DESCRIPTOR
    PSTORAGE_FRU_ID_DESCRIPTOR typedef ptr STORAGE_FRU_ID_DESCRIPTOR
    ;//////////////////////////////////////////////////////////////////////////////
    ; IOCTL_STORAGE_MANAGE_DATA_SET_ATTRIBUTES
    ; Input Buffer:
    ;     Structure of type DEVICE_DSM_INPUT
    ; Output Buffer:
    ;     Structure of type DEVICE_DSM_OUTPUT
    ; DEVICE_DSM_INPUT.Action
    DEVICE_DATA_MANAGEMENT_SET_ACTION typedef DWORD
    DEVICE_DSM_ACTION typedef DWORD
    ; This indicates that the action is
    ; non-destructive and a driver that
    ; does not understand it may safely
    ; forward the IOCTL
    DeviceDsmActionFlag_NonDestructive equ (80000000h)
    IsDsmActionNonDestructive macro _Action
      exitm <(((_Action and DeviceDsmActionFlag_NonDestructive) != 0))>
    endm
    DeviceDsmAction_None equ (00000000h)
    DeviceDsmAction_Trim equ (00000001h)
    DeviceDsmAction_Notification equ (00000002h or DeviceDsmActionFlag_NonDestructive)
    DeviceDsmAction_OffloadRead equ (00000003h or DeviceDsmActionFlag_NonDestructive)
    DeviceDsmAction_OffloadWrite equ (00000004h)
    DeviceDsmAction_Allocation equ (00000005h or DeviceDsmActionFlag_NonDestructive)
    DeviceDsmAction_Repair equ (00000006h or DeviceDsmActionFlag_NonDestructive)
    DeviceDsmAction_Scrub equ (00000007h or DeviceDsmActionFlag_NonDestructive)
    DeviceDsmAction_DrtQuery equ (00000008h or DeviceDsmActionFlag_NonDestructive)
    DeviceDsmAction_DrtClear equ (00000009h or DeviceDsmActionFlag_NonDestructive)
    DeviceDsmAction_DrtDisable equ (0000000Ah or DeviceDsmActionFlag_NonDestructive)
    DeviceDsmAction_TieringQuery equ (0000000Bh or DeviceDsmActionFlag_NonDestructive)
    DeviceDsmAction_Map equ (0000000Ch or DeviceDsmActionFlag_NonDestructive)
    DeviceDsmAction_RegenerateParity equ (0000000Dh or DeviceDsmActionFlag_NonDestructive)
    DeviceDsmAction_NvCache_Change_Priority equ (0000000Eh or DeviceDsmActionFlag_NonDestructive)
    DeviceDsmAction_NvCache_Evict equ (0000000Fh or DeviceDsmActionFlag_NonDestructive)
    DeviceDsmAction_TopologyIdQuery equ (00000010h or DeviceDsmActionFlag_NonDestructive)
    DeviceDsmAction_GetPhysicalAddresses equ (00000011h or DeviceDsmActionFlag_NonDestructive)
    DeviceDsmAction_ScopeRegen equ (00000012h or DeviceDsmActionFlag_NonDestructive)
    DeviceDsmAction_ReportZones equ (00000013h or DeviceDsmActionFlag_NonDestructive)
    DeviceDsmAction_OpenZone equ (00000014h or DeviceDsmActionFlag_NonDestructive)
    DeviceDsmAction_FinishZone equ (00000015h or DeviceDsmActionFlag_NonDestructive)
    DeviceDsmAction_CloseZone equ (00000016h or DeviceDsmActionFlag_NonDestructive)
    DeviceDsmAction_ResetWritePointer equ (00000017h)
    DeviceDsmAction_GetRangeErrorInfo equ (00000018h or DeviceDsmActionFlag_NonDestructive)
    DeviceDsmAction_WriteZeroes equ (00000019h)
    DeviceDsmAction_LostQuery equ (0000001Ah or DeviceDsmActionFlag_NonDestructive)
    DeviceDsmAction_GetFreeSpace equ (0000001Bh or DeviceDsmActionFlag_NonDestructive)
    DeviceDsmAction_ConversionQuery equ (0000001Ch or DeviceDsmActionFlag_NonDestructive)
    DeviceDsmAction_VdtSet equ (0000001Dh)
    ; DEVICE_DSM_INPUT.Flags
    ; Flags that are not specific to an
    ; action are in the lower 16-bits
    ; Action-specific flags  are in the
    ; higher 16-bits
    ; When specified, the DataSetRanges
    ; fields should be 0
    DEVICE_DSM_FLAG_ENTIRE_DATA_SET_RANGE equ 00000001h
    DEVICE_DATA_SET_RANGE struct
      ; Must be a  multiple of sector
      ; size, in bytes
      StartingOffset SQWORD ?
      LengthInBytes QWORD ?
    DEVICE_DATA_SET_RANGE ends
    _DEVICE_DATA_SET_RANGE typedef DEVICE_DATA_SET_RANGE
    PDEVICE_DATA_SET_RANGE typedef ptr DEVICE_DATA_SET_RANGE
    DEVICE_DSM_RANGE typedef DEVICE_DATA_SET_RANGE
    PDEVICE_DSM_RANGE typedef ptr DEVICE_DATA_SET_RANGE
    DEVICE_MANAGE_DATA_SET_ATTRIBUTES struct
      ; Size of this structure serves
      ; as the version
      Size_ DWORD ?
      Action DEVICE_DSM_ACTION ?
      Flags DWORD ?
      ; Must be aligned to __alignof(action-specific struct)
      ParameterBlockOffset DWORD ?
      ParameterBlockLength DWORD ?
      ; Must be aligned to __alignof(DEVICE_DSM_RANGE)
      DataSetRangesOffset DWORD ?
      DataSetRangesLength DWORD ?
    DEVICE_MANAGE_DATA_SET_ATTRIBUTES ends
    _DEVICE_MANAGE_DATA_SET_ATTRIBUTES typedef DEVICE_MANAGE_DATA_SET_ATTRIBUTES
    PDEVICE_MANAGE_DATA_SET_ATTRIBUTES typedef ptr DEVICE_MANAGE_DATA_SET_ATTRIBUTES
    DEVICE_DSM_INPUT typedef DEVICE_MANAGE_DATA_SET_ATTRIBUTES
    PDEVICE_DSM_INPUT typedef ptr DEVICE_MANAGE_DATA_SET_ATTRIBUTES
    DEVICE_MANAGE_DATA_SET_ATTRIBUTES_OUTPUT struct
      ; Size of this structure serves
      ; as the version
      Size_ DWORD ?
      Action DEVICE_DSM_ACTION ?
      Flags DWORD ?
      OperationStatus DWORD ?
      ExtendedError DWORD ?
      TargetDetailedError DWORD ?
      ReservedStatus DWORD ?
      ; Must be aligned to __alignof(corresponding struct)
      OutputBlockOffset DWORD ?
      OutputBlockLength DWORD ?
    DEVICE_MANAGE_DATA_SET_ATTRIBUTES_OUTPUT ends
    _DEVICE_MANAGE_DATA_SET_ATTRIBUTES_OUTPUT typedef DEVICE_MANAGE_DATA_SET_ATTRIBUTES_OUTPUT
    PDEVICE_MANAGE_DATA_SET_ATTRIBUTES_OUTPUT typedef ptr DEVICE_MANAGE_DATA_SET_ATTRIBUTES_OUTPUT
    DEVICE_DSM_OUTPUT typedef DEVICE_MANAGE_DATA_SET_ATTRIBUTES_OUTPUT
    PDEVICE_DSM_OUTPUT typedef ptr DEVICE_MANAGE_DATA_SET_ATTRIBUTES_OUTPUT
    DEVICE_DSM_DEFINITION struct
      Action DEVICE_DSM_ACTION ?
      SingleRange BYTE ?
      ParameterBlockAlignment DWORD ?
      ParameterBlockLength DWORD ?
      HasOutput BYTE ?
      OutputBlockAlignment DWORD ?
      OutputBlockLength DWORD ?
    DEVICE_DSM_DEFINITION ends
    _DEVICE_DSM_DEFINITION typedef DEVICE_DSM_DEFINITION
    PDEVICE_DSM_DEFINITION typedef ptr DEVICE_DSM_DEFINITION
    ;//////////////////////////////////////////////////////////////////////////////
    ; DeviceDsmAction_None
    ; SingleRange    - No
    ; ParameterBlock - No
    ; Output         - No
    ; OutputBlock    - No
    DeviceDsmDefinition_None equ { DeviceDsmAction_None, FALSE, 0, 0, FALSE, 0, 0 }
    ;//////////////////////////////////////////////////////////////////////////////
    ; DeviceDsmAction_Trim
    ; DEVICE_DSM_INPUT.Flags
    ; Indicates that the ranges are not
    ; part of any file
    DEVICE_DSM_FLAG_TRIM_NOT_FS_ALLOCATED equ 80000000h
    ; Indicates that RZAT is not needed
    ; RZAT only applies to ranges  that
    ; are part of a file that  need the
    ; additional protection
    DEVICE_DSM_FLAG_TRIM_BYPASS_RZAT equ 40000000h
    ; SingleRange    - No
    ; ParameterBlock - No
    ; Output         - No
    ; OutputBlock    - No
    DeviceDsmDefinition_Trim equ { DeviceDsmAction_Trim, FALSE, 0, 0, FALSE, 0, 0 }
    ;//////////////////////////////////////////////////////////////////////////////
    ; DeviceDsmAction_Notification
    ; DEVICE_DSM_NOTIFICATION_PARAMETERS.Flags
    ; The  ranges are now in use by the
    ; file type identifier
    DEVICE_DSM_NOTIFY_FLAG_BEGIN equ 00000001h
    ; The  ranges are no longer  in use
    ; by the file type identifier
    DEVICE_DSM_NOTIFY_FLAG_END equ 00000002h
    DEVICE_DSM_NOTIFICATION_PARAMETERS struct
      Size_ DWORD ?
      Flags DWORD ?
      NumFileTypeIDs DWORD ?
      FileTypeID GUID ANYSIZE_ARRAY dup (<>)
    DEVICE_DSM_NOTIFICATION_PARAMETERS ends
    _DEVICE_DSM_NOTIFICATION_PARAMETERS typedef DEVICE_DSM_NOTIFICATION_PARAMETERS
    PDEVICE_DSM_NOTIFICATION_PARAMETERS typedef ptr DEVICE_DSM_NOTIFICATION_PARAMETERS
    ; SingleRange    - No
    ; ParameterBlock - Yes
    ; Output         - No
    ; OutputBlock    - No
    DeviceDsmDefinition_Notification equ { DeviceDsmAction_Notification, FALSE, __alignof(DEVICE_DSM_NOTIFICATION_PARAMETERS), sizeof(DEVICE_DSM_NOTIFICATION_PARAMETERS), FALSE, 0, 0 }
    ;//////////////////////////////////////////////////////////////////////////////
    ; DeviceDsmAction_OffloadRead
    STORAGE_OFFLOAD_MAX_TOKEN_LENGTH equ 512; Keep as DWORD multiple

    STORAGE_OFFLOAD_TOKEN_ID_LENGTH equ 1F8h
    STORAGE_OFFLOAD_TOKEN_TYPE_ZERO_DATA equ 0FFFF0001h
    ; nameless struct/unions
    STORAGE_OFFLOAD_TOKEN struct
      TokenType BYTE 4 dup (?)
      Reserved BYTE 2 dup (?)
      TokenIdLength BYTE 2 dup (?)
      union
        struct StorageOffloadZeroDataToken
          Reserved2 BYTE STORAGE_OFFLOAD_TOKEN_ID_LENGTH dup (?)
        ends
        Token BYTE STORAGE_OFFLOAD_TOKEN_ID_LENGTH dup (?)
      ends
    STORAGE_OFFLOAD_TOKEN ends
    _STORAGE_OFFLOAD_TOKEN typedef STORAGE_OFFLOAD_TOKEN
    PSTORAGE_OFFLOAD_TOKEN typedef ptr STORAGE_OFFLOAD_TOKEN
    MAKE_ZERO_TOKEN macro T
      exitm <(((PSTORAGE_OFFLOAD_TOKEN) T) - TokenType [ 0 ] = 0FFh, ((PSTORAGE_OFFLOAD_TOKEN) T) - TokenType [ 1 ] = 0FFh, ((PSTORAGE_OFFLOAD_TOKEN) T) - TokenType [ 2 ] = 00h, ((PSTORAGE_OFFLOAD_TOKEN) T) - TokenType [ 3 ] = 01h, ((PSTORAGE_OFFLOAD_TOKEN) T) - TokenIdLength [ 0 ] = 01h, ((PSTORAGE_OFFLOAD_TOKEN) T) - TokenIdLength [ 1 ] = 0F8h)>
    endm
    IS_ZERO_TOKEN macro T
      exitm <((((PSTORAGE_OFFLOAD_TOKEN) T) - TokenType [ 0 ] == 0FFh and ((PSTORAGE_OFFLOAD_TOKEN) T) - TokenType [ 1 ] == 0FFh and ((PSTORAGE_OFFLOAD_TOKEN) T) - TokenType [ 2 ] == 00h and ((PSTORAGE_OFFLOAD_TOKEN) T) - TokenType [ 3 ] == 01h and ((PSTORAGE_OFFLOAD_TOKEN) T) - TokenIdLength [ 0 ] == 01h and ((PSTORAGE_OFFLOAD_TOKEN) T) - TokenIdLength [ 1 ] == 0F8h))>
    endm
    DEVICE_DSM_OFFLOAD_READ_PARAMETERS struct
      ; Reserved for future use
      Flags DWORD ?
      ; Token TTL in milli-seconds as
      ; requested by the initiator
      TimeToLive DWORD ?
      Reserved DWORD 2 dup (?)
    DEVICE_DSM_OFFLOAD_READ_PARAMETERS ends
    _DEVICE_DSM_OFFLOAD_READ_PARAMETERS typedef DEVICE_DSM_OFFLOAD_READ_PARAMETERS
    PDEVICE_DSM_OFFLOAD_READ_PARAMETERS typedef ptr DEVICE_DSM_OFFLOAD_READ_PARAMETERS
    ; STORAGE_OFFLOAD_READ_OUTPUT.OffloadReadFlags
    STORAGE_OFFLOAD_READ_RANGE_TRUNCATED equ 00000001h
    ; The token  returned by the target
    ; uniquely  identifies  a "point in
    ; time" snapshot of ranges taken by
    ; the target.  Its format is opaque
    ; We  arbitrarily limit token length to 512. The SCSI interface will/may enable
    ; negotiable size. If we want to add support, we'll need to create a new action
    STORAGE_OFFLOAD_READ_OUTPUT struct
      OffloadReadFlags DWORD ?
      Reserved DWORD ?
      ; Length of the "snapshot" that
      ; is bound to  the token.  Must
      ; be from the lowest range
      LengthProtected QWORD ?
      TokenLength DWORD ?
      Token STORAGE_OFFLOAD_TOKEN <>
    STORAGE_OFFLOAD_READ_OUTPUT ends
    _STORAGE_OFFLOAD_READ_OUTPUT typedef STORAGE_OFFLOAD_READ_OUTPUT
    PSTORAGE_OFFLOAD_READ_OUTPUT typedef ptr STORAGE_OFFLOAD_READ_OUTPUT
    ; SingleRange    - No
    ; ParameterBlock - Yes
    ; Output         - No
    ; OutputBlock    - Yes
    DeviceDsmDefinition_OffloadRead equ <{ DeviceDsmAction_OffloadRead, FALSE, __alignof(DEVICE_DSM_OFFLOAD_READ_PARAMETERS), sizeof(DEVICE_DSM_OFFLOAD_READ_PARAMETERS), FALSE, __alignof(STORAGE_OFFLOAD_READ_OUTPUT), sizeof(STORAGE_OFFLOAD_READ_OUTPUT) }>
    ;//////////////////////////////////////////////////////////////////////////////
    ; DeviceDsmAction_OffloadWrite
    DEVICE_DSM_OFFLOAD_WRITE_PARAMETERS struct
      ; Reserved for future use
      Flags DWORD ?
      Reserved DWORD ?
      ; Starting  offset to copy from
      ; "snapshot" bound to the token
      TokenOffset QWORD ?
      Token STORAGE_OFFLOAD_TOKEN <>
    DEVICE_DSM_OFFLOAD_WRITE_PARAMETERS ends
    _DEVICE_DSM_OFFLOAD_WRITE_PARAMETERS typedef DEVICE_DSM_OFFLOAD_WRITE_PARAMETERS
    PDEVICE_DSM_OFFLOAD_WRITE_PARAMETERS typedef ptr DEVICE_DSM_OFFLOAD_WRITE_PARAMETERS
    ; STORAGE_OFFLOAD_WRITE_OUTPUT.OffloadWriteFlags
    STORAGE_OFFLOAD_WRITE_RANGE_TRUNCATED equ 0001h
    STORAGE_OFFLOAD_TOKEN_INVALID equ 0002h
    STORAGE_OFFLOAD_WRITE_OUTPUT struct
      OffloadWriteFlags DWORD ?
      Reserved DWORD ?
      ; Length of content copied from
      ; the "snapshot" from the start
      LengthCopied QWORD ?
    STORAGE_OFFLOAD_WRITE_OUTPUT ends
    _STORAGE_OFFLOAD_WRITE_OUTPUT typedef STORAGE_OFFLOAD_WRITE_OUTPUT
    PSTORAGE_OFFLOAD_WRITE_OUTPUT typedef ptr STORAGE_OFFLOAD_WRITE_OUTPUT
    ; SingleRange    - No
    ; ParameterBlock - Yes
    ; Output         - No
    ; OutputBlock    - Yes
    DeviceDsmDefinition_OffloadWrite equ <{ DeviceDsmAction_OffloadWrite, FALSE, __alignof(DEVICE_DSM_OFFLOAD_WRITE_PARAMETERS), sizeof(DEVICE_DSM_OFFLOAD_WRITE_PARAMETERS), FALSE, __alignof(STORAGE_OFFLOAD_WRITE_OUTPUT), sizeof(STORAGE_OFFLOAD_WRITE_OUTPUT) }>
    ;//////////////////////////////////////////////////////////////////////////////
    ; DeviceDsmAction_Allocation
    ; DEVICE_DSM_INPUT.Flags
    DEVICE_DSM_FLAG_ALLOCATION_CONSOLIDATEABLE_ONLY equ 40000000h
    DEVICE_DATA_SET_LBP_STATE_PARAMETERS struct
      Version DWORD ?
      Size_ DWORD ?
      ; Reserved for future use
      Flags DWORD ?
      ; DEVICE_DSM_ALLOCATION_OUTPUT_V1 or
      ; DEVICE_DSM_ALLOCATION_OUTPUT_V2
      OutputVersion DWORD ?
    DEVICE_DATA_SET_LBP_STATE_PARAMETERS ends
    _DEVICE_DATA_SET_LBP_STATE_PARAMETERS typedef DEVICE_DATA_SET_LBP_STATE_PARAMETERS
    PDEVICE_DATA_SET_LBP_STATE_PARAMETERS typedef ptr DEVICE_DATA_SET_LBP_STATE_PARAMETERS
    DEVICE_DSM_ALLOCATION_PARAMETERS typedef DEVICE_DATA_SET_LBP_STATE_PARAMETERS
    PDEVICE_DSM_ALLOCATION_PARAMETERS typedef ptr DEVICE_DATA_SET_LBP_STATE_PARAMETERS
    DEVICE_DSM_PARAMETERS_V1 equ 1
    DEVICE_DATA_SET_LBP_STATE_PARAMETERS_VERSION_V1 equ <DEVICE_DSM_PARAMETERS_V1>
    DEVICE_DATA_SET_LB_PROVISIONING_STATE struct
      Size_ DWORD ?
      Version DWORD ?
      SlabSizeInBytes QWORD ?
      ; Delta  from the  start offset
      ; if the requested range is not
      ; aligned to a slab boundary
      SlabOffsetDeltaInBytes DWORD ?
      ; Number of bits that are valid
      SlabAllocationBitMapBitCount DWORD ?
      ; Count of DWORDs in the bitmap
      SlabAllocationBitMapLength DWORD ?
      ; 1 = mapped, 0 = unmapped
      SlabAllocationBitMap DWORD ANYSIZE_ARRAY dup (?)
    DEVICE_DATA_SET_LB_PROVISIONING_STATE ends
    _DEVICE_DATA_SET_LB_PROVISIONING_STATE typedef DEVICE_DATA_SET_LB_PROVISIONING_STATE
    PDEVICE_DATA_SET_LB_PROVISIONING_STATE typedef ptr DEVICE_DATA_SET_LB_PROVISIONING_STATE
    DEVICE_DSM_ALLOCATION_OUTPUT typedef DEVICE_DATA_SET_LB_PROVISIONING_STATE
    PDEVICE_DSM_ALLOCATION_OUTPUT typedef ptr DEVICE_DATA_SET_LB_PROVISIONING_STATE
    DEVICE_DSM_ALLOCATION_OUTPUT_V1 equ <(sizeof(DEVICE_DSM_ALLOCATION_OUTPUT))>
    DEVICE_DATA_SET_LB_PROVISIONING_STATE_VERSION_V1 equ <DEVICE_DSM_ALLOCATION_OUTPUT_V1>
    DEVICE_DATA_SET_LB_PROVISIONING_STATE_V2 struct
      Size_ DWORD ?
      Version DWORD ?
      SlabSizeInBytes QWORD ?
      ; Delta  from the  start offset
      ; if the requested range is not
      ; aligned to a slab boundary
      SlabOffsetDeltaInBytes QWORD ?
      ; Number of bits that are valid
      SlabAllocationBitMapBitCount DWORD ?
      ; Count of DWORDs in the bitmap
      SlabAllocationBitMapLength DWORD ?
      ; 1 = mapped, 0 = unmapped
      SlabAllocationBitMap DWORD ANYSIZE_ARRAY dup (?)
    DEVICE_DATA_SET_LB_PROVISIONING_STATE_V2 ends
    _DEVICE_DATA_SET_LB_PROVISIONING_STATE_V2 typedef DEVICE_DATA_SET_LB_PROVISIONING_STATE_V2
    PDEVICE_DATA_SET_LB_PROVISIONING_STATE_V2 typedef ptr DEVICE_DATA_SET_LB_PROVISIONING_STATE_V2
    DEVICE_DSM_ALLOCATION_OUTPUT2 typedef DEVICE_DATA_SET_LB_PROVISIONING_STATE_V2
    PDEVICE_DSM_ALLOCATION_OUTPUT2 typedef ptr DEVICE_DATA_SET_LB_PROVISIONING_STATE_V2
    DEVICE_DSM_ALLOCATION_OUTPUT_V2 equ <(sizeof(DEVICE_DSM_ALLOCATION_OUTPUT2))>
    DEVICE_DATA_SET_LB_PROVISIONING_STATE_VERSION_V2 equ <DEVICE_DSM_ALLOCATION_OUTPUT_V2>
    ; SingleRange    - Yes
    ; ParameterBlock - Yes
    ; Output         - Yes
    ; OutputBlock    - Yes
    DeviceDsmDefinition_Allocation equ <{ DeviceDsmAction_Allocation, TRUE, __alignof(DEVICE_DSM_ALLOCATION_PARAMETERS), sizeof(DEVICE_DSM_ALLOCATION_PARAMETERS), TRUE, __alignof(DEVICE_DSM_ALLOCATION_OUTPUT2), sizeof(DEVICE_DSM_ALLOCATION_OUTPUT2) }>
    ;//////////////////////////////////////////////////////////////////////////////
    ; DeviceDsmAction_Repair
    ; DEVICE_DSM_INPUT.Flags
    DEVICE_DSM_FLAG_REPAIR_INPUT_TOPOLOGY_ID_PRESENT equ 40000000h
    DEVICE_DATA_SET_REPAIR_PARAMETERS struct
      NumberOfRepairCopies DWORD ?
      SourceCopy DWORD ?
      RepairCopies DWORD ANYSIZE_ARRAY dup (?)
      ; Valid iff DEVICE_DSM_FLAG_REPAIR_INPUT_TOPOLOGY_ID_PRESENT is set
      ; To access this field, use the
      ; below macro
      ; BYTE  TopologyId[16];
    DEVICE_DATA_SET_REPAIR_PARAMETERS ends
    _DEVICE_DATA_SET_REPAIR_PARAMETERS typedef DEVICE_DATA_SET_REPAIR_PARAMETERS
    PDEVICE_DATA_SET_REPAIR_PARAMETERS typedef ptr DEVICE_DATA_SET_REPAIR_PARAMETERS
    DEVICE_DSM_REPAIR_PARAMETERS typedef DEVICE_DATA_SET_REPAIR_PARAMETERS
    PDEVICE_DSM_REPAIR_PARAMETERS typedef ptr DEVICE_DATA_SET_REPAIR_PARAMETERS
    GET_REPAIR_TOPOLOGY_ID macro R
      exitm <RtlOffsetToPointer (R, ALIGN_UP_BY (FIELD_OFFSET(DEVICE_DATA_SET_REPAIR_PARAMETERS, RepairCopies) + sizeof(DWORD) * R - NumberOfRepairCopies, 8))>
    endm
    ; DEVICE_DSM_OUTPUT.Flags
    DEVICE_DSM_FLAG_REPAIR_OUTPUT_PARITY_EXTENT equ 20000000h
    DEVICE_DATA_SET_REPAIR_OUTPUT struct
      ; Valid iff DEVICE_DSM_FLAG_REPAIR_OUTPUT_PARITY_EXTENT is set
      ParityExtent DEVICE_DSM_RANGE <>
    DEVICE_DATA_SET_REPAIR_OUTPUT ends
    _DEVICE_DATA_SET_REPAIR_OUTPUT typedef DEVICE_DATA_SET_REPAIR_OUTPUT
    PDEVICE_DATA_SET_REPAIR_OUTPUT typedef ptr DEVICE_DATA_SET_REPAIR_OUTPUT
    DEVICE_DSM_REPAIR_OUTPUT typedef DEVICE_DATA_SET_REPAIR_OUTPUT
    PDEVICE_DSM_REPAIR_OUTPUT typedef ptr DEVICE_DATA_SET_REPAIR_OUTPUT
    ; SingleRange    - Yes
    ; ParameterBlock - Yes
    ; Output         - Yes
    ; OutputBlock    - Yes
    DeviceDsmDefinition_Repair equ <{ DeviceDsmAction_Repair, TRUE, __alignof(DEVICE_DSM_REPAIR_PARAMETERS), sizeof(DEVICE_DSM_REPAIR_PARAMETERS), TRUE, __alignof(DEVICE_DSM_REPAIR_OUTPUT), sizeof(DEVICE_DSM_REPAIR_OUTPUT) }>
    ;//////////////////////////////////////////////////////////////////////////////
    ; DeviceDsmAction_Scrub
    ; DEVICE_DSM_INPUT.Flags
    DEVICE_DSM_FLAG_SCRUB_SKIP_IN_SYNC equ 10000000h
    DEVICE_DATA_SET_SCRUB_OUTPUT struct
      BytesProcessed QWORD ?
      BytesRepaired QWORD ?
      BytesFailed QWORD ?
    DEVICE_DATA_SET_SCRUB_OUTPUT ends
    _DEVICE_DATA_SET_SCRUB_OUTPUT typedef DEVICE_DATA_SET_SCRUB_OUTPUT
    PDEVICE_DATA_SET_SCRUB_OUTPUT typedef ptr DEVICE_DATA_SET_SCRUB_OUTPUT
    DEVICE_DSM_SCRUB_OUTPUT typedef DEVICE_DATA_SET_SCRUB_OUTPUT
    PDEVICE_DSM_SCRUB_OUTPUT typedef ptr DEVICE_DATA_SET_SCRUB_OUTPUT
    ; DEVICE_DSM_OUTPUT.Flags
    DEVICE_DSM_FLAG_SCRUB_OUTPUT_PARITY_EXTENT equ 20000000h
    DEVICE_DATA_SET_SCRUB_EX_OUTPUT struct
      BytesProcessed QWORD ?
      BytesRepaired QWORD ?
      BytesFailed QWORD ?
      ; Valid iff DEVICE_DSM_FLAG_SCRUB_OUTPUT_PARITY_EXTENT is set
      ParityExtent DEVICE_DSM_RANGE <>
      BytesScrubbed QWORD ?
    DEVICE_DATA_SET_SCRUB_EX_OUTPUT ends
    _DEVICE_DATA_SET_SCRUB_EX_OUTPUT typedef DEVICE_DATA_SET_SCRUB_EX_OUTPUT
    PDEVICE_DATA_SET_SCRUB_EX_OUTPUT typedef ptr DEVICE_DATA_SET_SCRUB_EX_OUTPUT
    DEVICE_DSM_SCRUB_OUTPUT2 typedef DEVICE_DATA_SET_SCRUB_EX_OUTPUT
    PDEVICE_DSM_SCRUB_OUTPUT2 typedef ptr DEVICE_DATA_SET_SCRUB_EX_OUTPUT
    ; SingleRange    - No
    ; ParameterBlock - No
    ; Output         - Yes
    ; OutputBlock    - Yes
    DeviceDsmDefinition_Scrub equ { DeviceDsmAction_Scrub, FALSE, 0, 0, TRUE, __alignof(DEVICE_DSM_SCRUB_OUTPUT2), sizeof(DEVICE_DSM_SCRUB_OUTPUT2) }
    ;//////////////////////////////////////////////////////////////////////////////
    ; DeviceDsmAction_DrtQuery
    ; SingleRange    - No
    ; ParameterBlock - No
    ; Output         - Yes
    ; OutputBlock    - No
    DeviceDsmDefinition_DrtQuery equ { DeviceDsmAction_DrtQuery, FALSE, 0, 0, TRUE, 0, 0 }
    ;//////////////////////////////////////////////////////////////////////////////
    ; DeviceDsmAction_DrtClear
    ; SingleRange    - No
    ; ParameterBlock - No
    ; Output         - No
    ; OutputBlock    - No
    DeviceDsmDefinition_DrtClear equ { DeviceDsmAction_DrtClear, FALSE, 0, 0, FALSE, 0, 0 }
    ;//////////////////////////////////////////////////////////////////////////////
    ; DeviceDsmAction_DrtDisable
    ; SingleRange    - No
    ; ParameterBlock - No
    ; Output         - No
    ; OutputBlock    - No
    DeviceDsmDefinition_DrtDisable equ { DeviceDsmAction_DrtDisable, FALSE, 0, 0, FALSE, 0, 0 }
    ;//////////////////////////////////////////////////////////////////////////////
    ; DeviceDsmAction_TieringQuery
    DEVICE_DSM_TIERING_QUERY_INPUT struct
      Version DWORD ?
      Size_ DWORD ?
      ; Reserved for future use
      Flags DWORD ?
      NumberOfTierIds DWORD ?
      TierIds GUID ANYSIZE_ARRAY dup (<>)
    DEVICE_DSM_TIERING_QUERY_INPUT ends
    _DEVICE_DSM_TIERING_QUERY_INPUT typedef DEVICE_DSM_TIERING_QUERY_INPUT
    PDEVICE_DSM_TIERING_QUERY_INPUT typedef ptr DEVICE_DSM_TIERING_QUERY_INPUT
    DEVICE_DSM_TIERING_QUERY_PARAMETERS typedef DEVICE_DSM_TIERING_QUERY_INPUT
    PDEVICE_DSM_TIERING_QUERY_PARAMETERS typedef ptr DEVICE_DSM_TIERING_QUERY_INPUT
    STORAGE_TIER_REGION struct
      TierId GUID <>
      Offset_ QWORD ?
      Length_ QWORD ?
    STORAGE_TIER_REGION ends
    _STORAGE_TIER_REGION typedef STORAGE_TIER_REGION
    PSTORAGE_TIER_REGION typedef ptr STORAGE_TIER_REGION
    DEVICE_DSM_TIERING_QUERY_OUTPUT struct
      Version DWORD ?
      Size_ DWORD ?
      ; Reserved for future use
      Flags DWORD ?
      Reserved DWORD ?
      ; Delta  from the  start offset
      ; if the requested range is not
      ; aligned to a  region boundary
      Alignment QWORD ?
      ; Total  number of regions that
      ; are in the specified range
      TotalNumberOfRegions DWORD ?
      NumberOfRegionsReturned DWORD ?
      Regions STORAGE_TIER_REGION ANYSIZE_ARRAY dup (<>)
    DEVICE_DSM_TIERING_QUERY_OUTPUT ends
    _DEVICE_DSM_TIERING_QUERY_OUTPUT typedef DEVICE_DSM_TIERING_QUERY_OUTPUT
    PDEVICE_DSM_TIERING_QUERY_OUTPUT typedef ptr DEVICE_DSM_TIERING_QUERY_OUTPUT
    ; SingleRange    - Yes
    ; ParameterBlock - Yes
    ; Output         - Yes
    ; OutputBlock    - Yes
    DeviceDsmDefinition_TieringQuery equ <{ DeviceDsmAction_TieringQuery, TRUE, __alignof(DEVICE_DSM_TIERING_QUERY_PARAMETERS), sizeof(DEVICE_DSM_TIERING_QUERY_PARAMETERS), TRUE, __alignof(DEVICE_DSM_TIERING_QUERY_OUTPUT), sizeof(DEVICE_DSM_TIERING_QUERY_OUTPUT) }>
    ;//////////////////////////////////////////////////////////////////////////////
    ; DeviceDsmAction_Map
    ; SingleRange    - No
    ; ParameterBlock - No
    ; Output         - No
    ; OutputBlock    - No
    DeviceDsmDefinition_Map equ { DeviceDsmAction_Map, FALSE, 0, 0, FALSE, 0, 0 }
    ;//////////////////////////////////////////////////////////////////////////////
    ; DeviceDsmAction_RegenerateParity
    ; SingleRange    - No
    ; ParameterBlock - No
    ; Output         - No
    ; OutputBlock    - No
    DeviceDsmDefinition_RegenerateParity equ { DeviceDsmAction_RegenerateParity, FALSE, 0, 0, FALSE, 0, 0 }
    ;//////////////////////////////////////////////////////////////////////////////
    ; DeviceDsmAction_NvCache_Change_Priority
    DEVICE_DSM_NVCACHE_CHANGE_PRIORITY_PARAMETERS struct
      Size_ DWORD ?
      TargetPriority BYTE ?
      Reserved BYTE 3 dup (?)
    DEVICE_DSM_NVCACHE_CHANGE_PRIORITY_PARAMETERS ends
    _DEVICE_DSM_NVCACHE_CHANGE_PRIORITY_PARAMETERS typedef DEVICE_DSM_NVCACHE_CHANGE_PRIORITY_PARAMETERS
    PDEVICE_DSM_NVCACHE_CHANGE_PRIORITY_PARAMETERS typedef ptr DEVICE_DSM_NVCACHE_CHANGE_PRIORITY_PARAMETERS
    ; SingleRange    - No
    ; ParameterBlock - Yes
    ; Output         - No
    ; OutputBlock    - No
    DeviceDsmDefinition_NvCache_Change_Priority equ { DeviceDsmAction_NvCache_Change_Priority, FALSE, __alignof(DEVICE_DSM_NVCACHE_CHANGE_PRIORITY_PARAMETERS), sizeof(DEVICE_DSM_NVCACHE_CHANGE_PRIORITY_PARAMETERS), FALSE, 0, 0 }
    ;//////////////////////////////////////////////////////////////////////////////
    ; DeviceDsmAction_NvCache_Evict
    ; SingleRange    - No
    ; ParameterBlock - No
    ; Output         - No
    ; OutputBlock    - No
    DeviceDsmDefinition_NvCache_Evict equ { DeviceDsmAction_NvCache_Evict, FALSE, 0, 0, FALSE, 0, 0 }
    ;//////////////////////////////////////////////////////////////////////////////
    ; DeviceDsmAction_TopologyIdQuery
    DEVICE_DATA_SET_TOPOLOGY_ID_QUERY_OUTPUT struct
      ; Number of bytes that topology
      ; id describes  relative to the
      ; start of an input range
      TopologyRangeBytes QWORD ?
      ; The corresponding topology id
      TopologyId BYTE 16 dup (?)
    DEVICE_DATA_SET_TOPOLOGY_ID_QUERY_OUTPUT ends
    _DEVICE_DATA_SET_TOPOLOGY_ID_QUERY_OUTPUT typedef DEVICE_DATA_SET_TOPOLOGY_ID_QUERY_OUTPUT
    PDEVICE_DATA_SET_TOPOLOGY_ID_QUERY_OUTPUT typedef ptr DEVICE_DATA_SET_TOPOLOGY_ID_QUERY_OUTPUT
    DEVICE_DSM_TOPOLOGY_ID_QUERY_OUTPUT typedef DEVICE_DATA_SET_TOPOLOGY_ID_QUERY_OUTPUT
    PDEVICE_DSM_TOPOLOGY_ID_QUERY_OUTPUT typedef ptr DEVICE_DATA_SET_TOPOLOGY_ID_QUERY_OUTPUT
    ; SingleRange    - No
    ; ParameterBlock - No
    ; Output         - Yes
    ; OutputBlock    - Yes
    DeviceDsmDefinition_TopologyIdQuery equ { DeviceDsmAction_TopologyIdQuery, FALSE, 0, 0, TRUE, __alignof(DEVICE_DSM_TOPOLOGY_ID_QUERY_OUTPUT), sizeof(DEVICE_DSM_TOPOLOGY_ID_QUERY_OUTPUT) }
    ;//////////////////////////////////////////////////////////////////////////////
    ; DeviceDsmAction_GetPhysicalAddresses
    ; DEVICE_DSM_INPUT.Flags
    ; If set, TotalNumberOfRanges field will be 0.
    ; A caller that doesn't need to know the total
    ; number of ranges  should set this flag  as a
    ; performance optimization, because the device
    ; might incur some cost  calculating the total
    ; number of ranges.
    DEVICE_DSM_FLAG_PHYSICAL_ADDRESSES_OMIT_TOTAL_RANGES equ 10000000h
    ; A driver can set the StartAddress field to this value
    ; to indicate that an address range has a memory error.
    ; Address ranges with memory errors must not be merged:
    ; if there are two physically contiguous address ranges
    ; with errors, they must be reported as two separate
    ; address ranges, both of which have StartAddress set
    ; to this value.
    DEVICE_DSM_PHYSICAL_ADDRESS_HAS_MEMORY_ERROR equ (- 1)
    DEVICE_STORAGE_ADDRESS_RANGE struct
      StartAddress SQWORD ?
      LengthInBytes QWORD ?
    DEVICE_STORAGE_ADDRESS_RANGE ends
    _DEVICE_STORAGE_ADDRESS_RANGE typedef DEVICE_STORAGE_ADDRESS_RANGE
    PDEVICE_STORAGE_ADDRESS_RANGE typedef ptr DEVICE_STORAGE_ADDRESS_RANGE
    DEVICE_DSM_PHYSICAL_ADDRESSES_OUTPUT struct
      Version DWORD ?
      ; Reserved for future use
      Flags DWORD ?
      ; Total number of ranges within
      ; the specified ranges. Callers
      ; may use it to  determine  the
      ; correct  size of  this output
      ; buffer
      TotalNumberOfRanges DWORD ?
      ; If the buffer provided by the
      ; caller is not large enough to
      ; hold all the requested ranges
      ; a STATUS_BUFFER_OVERFLOW will
      ; be returned
      NumberOfRangesReturned DWORD ?
      Ranges DEVICE_STORAGE_ADDRESS_RANGE ANYSIZE_ARRAY dup (<>)
    DEVICE_DSM_PHYSICAL_ADDRESSES_OUTPUT ends
    _DEVICE_DSM_PHYSICAL_ADDRESSES_OUTPUT typedef DEVICE_DSM_PHYSICAL_ADDRESSES_OUTPUT
    PDEVICE_DSM_PHYSICAL_ADDRESSES_OUTPUT typedef ptr DEVICE_DSM_PHYSICAL_ADDRESSES_OUTPUT
    DEVICE_DSM_PHYSICAL_ADDRESSES_OUTPUT_V1 equ 1
    DEVICE_DSM_PHYSICAL_ADDRESSES_OUTPUT_VERSION_V1 equ <DEVICE_DSM_PHYSICAL_ADDRESSES_OUTPUT_V1>
    ; SingleRange    - No
    ; ParameterBlock - No
    ; Output         - Yes
    ; OutputBlock    - Yes
    DeviceDsmDefinition_GetPhysicalAddresses equ { DeviceDsmAction_GetPhysicalAddresses, FALSE, 0, 0, TRUE, __alignof(DEVICE_DSM_PHYSICAL_ADDRESSES_OUTPUT), sizeof(DEVICE_DSM_PHYSICAL_ADDRESSES_OUTPUT) }
    ;//////////////////////////////////////////////////////////////////////////////
    ; DeviceDsmAction_ScopeRegen
    ; SingleRange    - No
    ; ParameterBlock - No
    ; Output         - No
    ; OutputBlock    - No
    DeviceDsmDefinition_ScopeRegen equ { DeviceDsmAction_ScopeRegen, FALSE, 0, 0, FALSE, 0, 0 }
    ;//////////////////////////////////////////////////////////////////////////////
    ; DeviceDsmAction_ReportZones
    DEVICE_DSM_REPORT_ZONES_PARAMETERS struct
      Size_ DWORD ?
      ReportOption BYTE ?
      ; This  bit affects calculation
      ; of the zone list length
      Partial BYTE ?
      Reserved BYTE 2 dup (?)
    DEVICE_DSM_REPORT_ZONES_PARAMETERS ends
    _DEVICE_DSM_REPORT_ZONES_PARAMETERS typedef DEVICE_DSM_REPORT_ZONES_PARAMETERS
    PDEVICE_DSM_REPORT_ZONES_PARAMETERS typedef ptr DEVICE_DSM_REPORT_ZONES_PARAMETERS
    STORAGE_ZONES_ATTRIBUTES typedef SDWORD
    ZonesAttributeTypeAndLengthMayDifferent equ 0
    ZonesAttributeTypeSameLengthSame equ 1
    ZonesAttributeTypeSameLastZoneLengthDifferent equ 2
    ZonesAttributeTypeMayDifferentLengthSame equ 3
    _STORAGE_ZONES_ATTRIBUTES typedef STORAGE_ZONES_ATTRIBUTES
    PSTORAGE_ZONES_ATTRIBUTES typedef ptr STORAGE_ZONES_ATTRIBUTES
    STORAGE_ZONE_CONDITION typedef SDWORD
    ZoneConditionConventional equ 00h
    ZoneConditionEmpty equ 01h
    ZoneConditionImplicitlyOpened equ 02h
    ZoneConditionExplicitlyOpened equ 03h
    ZoneConditionClosed equ 04h
    ZoneConditionReadOnly equ 0Dh
    ZoneConditionFull equ 0Eh
    ZoneConditionOffline equ 0Fh
    _STORAGE_ZONE_CONDITION typedef STORAGE_ZONE_CONDITION
    PSTORAGE_ZONE_CONDITION typedef ptr STORAGE_ZONE_CONDITION
    STORAGE_ZONE_DESCRIPTOR struct
      Size_ DWORD ?
      ZoneType STORAGE_ZONE_TYPES ?
      ZoneCondition STORAGE_ZONE_CONDITION ?
      ResetWritePointerRecommend BYTE ?
      Reserved0 BYTE 3 dup (?)
      ; In bytes
      ZoneSize QWORD ?
      WritePointerOffset QWORD ?
    STORAGE_ZONE_DESCRIPTOR ends
    _STORAGE_ZONE_DESCRIPTOR typedef STORAGE_ZONE_DESCRIPTOR
    PSTORAGE_ZONE_DESCRIPTOR typedef ptr STORAGE_ZONE_DESCRIPTOR
    DEVICE_DSM_REPORT_ZONES_DATA struct
      Size_ DWORD ?
      ZoneCount DWORD ?
      Attributes STORAGE_ZONES_ATTRIBUTES ?
      Reserved0 DWORD ?
      ZoneDescriptors STORAGE_ZONE_DESCRIPTOR ANYSIZE_ARRAY dup (<>)
    DEVICE_DSM_REPORT_ZONES_DATA ends
    _DEVICE_DSM_REPORT_ZONES_DATA typedef DEVICE_DSM_REPORT_ZONES_DATA
    PDEVICE_DSM_REPORT_ZONES_DATA typedef ptr DEVICE_DSM_REPORT_ZONES_DATA
    DEVICE_DSM_REPORT_ZONES_OUTPUT typedef DEVICE_DSM_REPORT_ZONES_DATA
    PDEVICE_DSM_REPORT_ZONES_OUTPUT typedef ptr DEVICE_DSM_REPORT_ZONES_DATA
    ; SingleRange    - No
    ; ParameterBlock - Yes
    ; Output         - Yes
    ; OutputBlock    - Yes
    DeviceDsmDefinition_ReportZones equ <{ DeviceDsmAction_ReportZones, FALSE, __alignof(DEVICE_DSM_REPORT_ZONES_PARAMETERS), sizeof(DEVICE_DSM_REPORT_ZONES_PARAMETERS), TRUE, __alignof(DEVICE_DSM_REPORT_ZONES_OUTPUT), sizeof(DEVICE_DSM_REPORT_ZONES_OUTPUT) }>
    ;//////////////////////////////////////////////////////////////////////////////
    ; DeviceDsmAction_OpenZone
    ; SingleRange    - No
    ; ParameterBlock - No
    ; Output         - No
    ; OutputBlock    - No
    DeviceDsmDefinition_OpenZone equ { DeviceDsmAction_OpenZone, FALSE, 0, 0, FALSE, 0, 0 }
    ;//////////////////////////////////////////////////////////////////////////////
    ; DeviceDsmAction_FinishZone
    ; SingleRange    - No
    ; ParameterBlock - No
    ; Output         - No
    ; OutputBlock    - No
    DeviceDsmDefinition_FinishZone equ { DeviceDsmAction_FinishZone, FALSE, 0, 0, FALSE, 0, 0 }
    ;//////////////////////////////////////////////////////////////////////////////
    ; DeviceDsmAction_CloseZone
    ; SingleRange    - No
    ; ParameterBlock - No
    ; Output         - No
    ; OutputBlock    - No
    DeviceDsmDefinition_CloseZone equ { DeviceDsmAction_CloseZone, FALSE, 0, 0, FALSE, 0, 0 }
    ;//////////////////////////////////////////////////////////////////////////////
    ; DeviceDsmAction_ResetWritePointer
    ; SingleRange    - No
    ; ParameterBlock - No
    ; Output         - No
    ; OutputBlock    - No
    DeviceDsmDefinition_ResetWritePointer equ { DeviceDsmAction_ResetWritePointer, FALSE, 0, 0, FALSE, 0, 0 }
    ;//////////////////////////////////////////////////////////////////////////////
    ; DeviceDsmAction_GetRangeErrorInfo
    ; nameless struct/unions
    ; bit fields other than int
    DEVICE_STORAGE_RANGE_ATTRIBUTES struct
      ; Must be a  multiple of sector
      ; size, in bytes
      LengthInBytes QWORD ?
      union
        AllFlags DWORD ?
        struct
          ; 1 = bad, 0 = good
          ANONYMOUS_REC0 record ANONYMOUS_REC0_Filler:31, ANONYMOUS_REC0_IsRangeBad:1
          ANONYMOUS_REC0 <>
        ends
      ends
      Reserved DWORD ?
    DEVICE_STORAGE_RANGE_ATTRIBUTES ends
    _DEVICE_STORAGE_RANGE_ATTRIBUTES typedef DEVICE_STORAGE_RANGE_ATTRIBUTES
    PDEVICE_STORAGE_RANGE_ATTRIBUTES typedef ptr DEVICE_STORAGE_RANGE_ATTRIBUTES
    ; DEVICE_DSM_RANGE_ERROR_OUTPUT.Flags
    DEVICE_STORAGE_NO_ERRORS equ 1h
    DEVICE_DSM_RANGE_ERROR_INFO struct
      Version DWORD ?
      Flags DWORD ?
      ; Total number of ranges within
      ; the specified ranges. Callers
      ; may use it to  determine  the
      ; correct  size of  this output
      ; buffer
      TotalNumberOfRanges DWORD ?
      ; If the buffer provided by the
      ; caller is not large enough to
      ; hold all the requested ranges
      ; a STATUS_BUFFER_OVERFLOW will
      ; be returned
      ; The output ranges, which inform the caller about which regions of the requested
      ; ranges are good or bad. The elements of this array are sorted so that their order
      ; corresponds to the order of the input ranges. For example, if the first input
      ; range was broken into 3 output ranges, those will be the first 3 ranges in the array.
      ; The caller can learn which output ranges correspond to an input range by keeping track
      ; of the length of the output ranges.
      NumberOfRangesReturned DWORD ?
      Ranges DEVICE_STORAGE_RANGE_ATTRIBUTES ANYSIZE_ARRAY dup (<>)
    DEVICE_DSM_RANGE_ERROR_INFO ends
    _DEVICE_DSM_RANGE_ERROR_INFO typedef DEVICE_DSM_RANGE_ERROR_INFO
    PDEVICE_DSM_RANGE_ERROR_INFO typedef ptr DEVICE_DSM_RANGE_ERROR_INFO
    DEVICE_DSM_RANGE_ERROR_OUTPUT typedef DEVICE_DSM_RANGE_ERROR_INFO
    PDEVICE_DSM_RANGE_ERROR_OUTPUT typedef ptr DEVICE_DSM_RANGE_ERROR_INFO
    DEVICE_DSM_RANGE_ERROR_OUTPUT_V1 equ 1
    DEVICE_DSM_RANGE_ERROR_INFO_VERSION_V1 equ <DEVICE_DSM_RANGE_ERROR_OUTPUT_V1>
    ; SingleRange    - No
    ; ParameterBlock - No
    ; Output         - Yes
    ; OutputBlock    - Yes
    DeviceDsmDefinition_GetRangeErrorInfo equ { DeviceDsmAction_GetRangeErrorInfo, FALSE, 0, 0, TRUE, __alignof(DEVICE_DSM_RANGE_ERROR_OUTPUT), sizeof(DEVICE_DSM_RANGE_ERROR_OUTPUT) }
    ;//////////////////////////////////////////////////////////////////////////////
    ; DeviceDsmAction_WriteZeroes
    ; ParameterBlock - No
    ; Output         - No
    ; SingleRange    - No
    ; ParameterBlock - No
    ; Output         - No
    ; OutputBlock    - No
    DeviceDsmDefinition_WriteZeroes equ { DeviceDsmAction_WriteZeroes, FALSE, 0, 0, FALSE, 0, 0 }
    ;//////////////////////////////////////////////////////////////////////////////
    ; DeviceDsmAction_LostQuery
    DEVICE_DSM_LOST_QUERY_PARAMETERS struct
      ; Size of this structure serves
      ; as the version
      Version DWORD ?
      Granularity QWORD ?
    DEVICE_DSM_LOST_QUERY_PARAMETERS ends
    _DEVICE_DSM_LOST_QUERY_PARAMETERS typedef DEVICE_DSM_LOST_QUERY_PARAMETERS
    PDEVICE_DSM_LOST_QUERY_PARAMETERS typedef ptr DEVICE_DSM_LOST_QUERY_PARAMETERS
    DEVICE_DSM_LOST_QUERY_OUTPUT struct
      ; Size of this structure serves
      ; as the version
      Version DWORD ?
      ; Size of  this structure  plus
      ; all the variable sized fields
      ; needed for  the  entire range
      Size_ DWORD ?
      ; Delta  from the  start offset
      ; if the requested range is not
      ; granularity aligned
      Alignment QWORD ?
      ; 1 = lost, 0 = readable
      NumberOfBits DWORD ?
      BitMap DWORD ANYSIZE_ARRAY dup (?)
    DEVICE_DSM_LOST_QUERY_OUTPUT ends
    _DEVICE_DSM_LOST_QUERY_OUTPUT typedef DEVICE_DSM_LOST_QUERY_OUTPUT
    PDEVICE_DSM_LOST_QUERY_OUTPUT typedef ptr DEVICE_DSM_LOST_QUERY_OUTPUT
    ; SingleRange    - Yes
    ; ParameterBlock - Yes
    ; Output         - Yes
    ; OutputBlock    - Yes
    DeviceDsmDefinition_LostQuery equ <{ DeviceDsmAction_LostQuery, TRUE, __alignof(DEVICE_DSM_LOST_QUERY_PARAMETERS), sizeof(DEVICE_DSM_LOST_QUERY_PARAMETERS), TRUE, __alignof(DEVICE_DSM_LOST_QUERY_OUTPUT), sizeof(DEVICE_DSM_LOST_QUERY_OUTPUT) }>
    ;//////////////////////////////////////////////////////////////////////////////
    ; DeviceDsmAction_GetFreeSpace
    DEVICE_DSM_FREE_SPACE_OUTPUT struct
      ; Size of this structure serves
      ; as the version
      Version DWORD ?
      ; Shared free space available
      FreeSpace QWORD ?
    DEVICE_DSM_FREE_SPACE_OUTPUT ends
    _DEVICE_DSM_FREE_SPACE_OUTPUT typedef DEVICE_DSM_FREE_SPACE_OUTPUT
    PDEVICE_DSM_FREE_SPACE_OUTPUT typedef ptr DEVICE_DSM_FREE_SPACE_OUTPUT
    ; SingleRange    - No
    ; ParameterBlock - No
    ; Output         - Yes
    ; OutputBlock    - Yes
    DeviceDsmDefinition_GetFreeSpace equ { DeviceDsmAction_GetFreeSpace, FALSE, 0, 0, TRUE, __alignof(DEVICE_DSM_FREE_SPACE_OUTPUT), sizeof(DEVICE_DSM_FREE_SPACE_OUTPUT) }
    ;//////////////////////////////////////////////////////////////////////////////
    ; DeviceDsmAction_ConversionQuery
    DEVICE_DSM_CONVERSION_OUTPUT struct
      ; Size of this structure serves
      ; as the version
      Version DWORD ?
      ; Stable  identifier associated
      ; with the source
      Source GUID <>
    DEVICE_DSM_CONVERSION_OUTPUT ends
    _DEVICE_DSM_CONVERSION_OUTPUT typedef DEVICE_DSM_CONVERSION_OUTPUT
    PDEVICE_DSM_CONVERSION_OUTPUT typedef ptr DEVICE_DSM_CONVERSION_OUTPUT
    ; SingleRange    - Yes
    ; ParameterBlock - No
    ; Output         - Yes
    ; OutputBlock    - Yes
    DeviceDsmDefinition_ConversionQuery equ { DeviceDsmAction_ConversionQuery, TRUE, 0, 0, TRUE, __alignof(DEVICE_DSM_CONVERSION_OUTPUT), sizeof(DEVICE_DSM_CONVERSION_OUTPUT) }
    ;//////////////////////////////////////////////////////////////////////////////
    ; DeviceDsmAction_VdtSet
    ; SingleRange    - No
    ; ParameterBlock - No
    ; Output         - No
    ; OutputBlock    - No
    DeviceDsmDefinition_VdtSet equ { DeviceDsmAction_VdtSet, FALSE, 0, 0, FALSE, 0, 0 }
    ;//////////////////////////////////////////////////////////////////////////////
    ; Dsm helper routines
    DEVICE_DSM_ROUND_UP macro _a, _b
      exitm <(((_a) + ((_b) - 1)) / (_b) * (_b))>
    endm
    DEVICE_DSM_ROUND_DN macro _a, _b
      exitm <(((_a)) / (_b) * (_b))>
    endm
    DeviceDsmParameterBlock proto WIN_STD_CALL_CONV :PDEVICE_DSM_INPUT
    DeviceDsmDataSetRanges proto WIN_STD_CALL_CONV :PDEVICE_DSM_INPUT
    DeviceDsmNumberOfDataSetRanges proto WIN_STD_CALL_CONV :PDEVICE_DSM_INPUT
    DeviceDsmGetInputLength proto WIN_STD_CALL_CONV :PDEVICE_DSM_DEFINITION, :DWORD, :DWORD
    DeviceDsmGetNumberOfDataSetRanges proto WIN_STD_CALL_CONV :PDEVICE_DSM_DEFINITION, :DWORD, :DWORD
    DeviceDsmInitializeInput proto WIN_STD_CALL_CONV :PDEVICE_DSM_DEFINITION, :PDEVICE_DSM_INPUT, :DWORD, :DWORD, :PVOID, :DWORD
    DeviceDsmAddDataSetRange proto WIN_STD_CALL_CONV :PDEVICE_DSM_INPUT, :DWORD, :LONGLONG, :DWORDLONG
    DeviceDsmValidateInput proto WIN_STD_CALL_CONV :PDEVICE_DSM_DEFINITION, :PDEVICE_DSM_INPUT, :DWORD
    DeviceDsmOutputBlock proto WIN_STD_CALL_CONV :PDEVICE_DSM_OUTPUT
    DeviceDsmGetOutputLength proto WIN_STD_CALL_CONV :PDEVICE_DSM_DEFINITION, :DWORD
    DeviceDsmValidateOutputLength proto WIN_STD_CALL_CONV :PDEVICE_DSM_DEFINITION, :DWORD
    DeviceDsmGetOutputBlockLength proto WIN_STD_CALL_CONV :PDEVICE_DSM_DEFINITION, :DWORD
    DeviceDsmInitializeOutput proto WIN_STD_CALL_CONV :PDEVICE_DSM_DEFINITION, :PDEVICE_DSM_OUTPUT, :DWORD, :DWORD
    DeviceDsmValidateOutput proto WIN_STD_CALL_CONV :PDEVICE_DSM_DEFINITION, :PDEVICE_DSM_OUTPUT, :DWORD
    ; end IOCTL_STORAGE_MANAGE_DATA_SET_ATTRIBUTES
    ;//////////////////////////////////////////////////////////////////////////////
    ;  There are some well known GUIDS for certain types of files.  They are
    ;  defined in NTIFS.H
    ; IOCTL_STORAGE_GET_BC_PROPERTIES
    ; Input Buffer:
    ;     None
    ; Output Buffer:
    ;     Structure of type STORAGE_GET_BC_PROPERTIES_OUTPUT
    STORAGE_GET_BC_PROPERTIES_OUTPUT struct
      ; Specifies the maximum number of requests
      ; that can be scheduled per period of time
      MaximumRequestsPerPeriod DWORD ?
      ; Specifies the minimum period that the
      ; device uses  when scheduling requests
      MinimumPeriod DWORD ?
      ; Specifies the maximum transfer size supported
      ; for  bandwidth contracts  on this  device. To
      ; achieve the highest level of performance, all
      ; requests should be of this size
      MaximumRequestSize QWORD ?
      ; Specifies the estimated time taken to
      ; perform an  Io operstion. This  field
      ; is  for  informational purposes  only
      EstimatedTimePerRequest DWORD ?
      ; Specifies the number of requests that should be
      ; kept outstanding.  This helps  keep the  device
      ; device busy and thus obtain maximum throughput.
      ; This will only be filled in if the target  file
      ; has an outstanding contract.
      NumOutStandingRequests DWORD ?
      ; Specifies the required size of requests in this
      ; stream.  This  will  only  be filled in  if the
      ; target file has an outstanding contract.
      RequestSize QWORD ?
    STORAGE_GET_BC_PROPERTIES_OUTPUT ends
    _STORAGE_GET_BC_PROPERTIES_OUTPUT typedef STORAGE_GET_BC_PROPERTIES_OUTPUT
    PSTORAGE_GET_BC_PROPERTIES_OUTPUT typedef ptr STORAGE_GET_BC_PROPERTIES_OUTPUT
    ; IOCTL_STORAGE_ALLOCATE_BC_STREAM
    ; Input Buffer:
    ;     Structure of type STORAGE_ALLOCATE_BC_STREAM_INPUT
    ; Output Buffer:
    ;     Structure of type STORAGE_ALLOCATE_BC_STREAM_OUTPUT
    ; Current version
    IOCTL_STORAGE_BC_VERSION equ 1
    STORAGE_ALLOCATE_BC_STREAM_INPUT struct
      ; Specifies the corresponding structure version
      Version DWORD ?
      ; Specifies the number of requests that
      ; need to  complete  per period of time
      RequestsPerPeriod DWORD ?
      ; Specifies the period of time wherein the
      ; above  number of requests  must complete
      Period DWORD ?
      ; Indicates whether failures
      ; should  be retried  or not
      RetryFailures BYTE ?
      ; Indicates whether reqests that  will miss
      ; their deadline should be discarded or not
      Discardable BYTE ?
      ; Helps align the following field
      Reserved1 BYTE 2 dup (?)
      ; Indicates whether the  Io  will be
      ; comprised of reads, writes or both
      AccessType DWORD ?
      ; Indicates whether the  Io  to the
      ; file will be sequential or random
      AccessMode DWORD ?
    STORAGE_ALLOCATE_BC_STREAM_INPUT ends
    _STORAGE_ALLOCATE_BC_STREAM_INPUT typedef STORAGE_ALLOCATE_BC_STREAM_INPUT
    PSTORAGE_ALLOCATE_BC_STREAM_INPUT typedef ptr STORAGE_ALLOCATE_BC_STREAM_INPUT
    STORAGE_ALLOCATE_BC_STREAM_OUTPUT struct
      ; Specifies the required size
      ; of  requests in this stream
      RequestSize QWORD ?
      ; Specifies the number of requests that should be
      ; kept outstanding.  This helps  keep the  device
      ; device busy and thus obtain maximum  throughput
      NumOutStandingRequests DWORD ?
    STORAGE_ALLOCATE_BC_STREAM_OUTPUT ends
    _STORAGE_ALLOCATE_BC_STREAM_OUTPUT typedef STORAGE_ALLOCATE_BC_STREAM_OUTPUT
    PSTORAGE_ALLOCATE_BC_STREAM_OUTPUT typedef ptr STORAGE_ALLOCATE_BC_STREAM_OUTPUT
    ; IOCTL_STORAGE_FREE_BC_STREAM
    ; Input Buffer:
    ;     None
    ; Output Buffer:
    ;     None
    ; IOCTL_STORAGE_CHECK_PRIORITY_HINT_SUPPORT
    ; Input Buffer :
    ;      None
    ; Output Buffer :
    ;      Structure of type STORAGE_PRIORITY_HINT_SUPPORT
    STORAGE_PRIORITY_HINT_SUPPORTED equ 0001h
    STORAGE_PRIORITY_HINT_SUPPORT struct
      SupportFlags DWORD ?
    STORAGE_PRIORITY_HINT_SUPPORT ends
    _STORAGE_PRIORITY_HINT_SUPPORT typedef STORAGE_PRIORITY_HINT_SUPPORT
    PSTORAGE_PRIORITY_HINT_SUPPORT typedef ptr STORAGE_PRIORITY_HINT_SUPPORT
    ; IOCTL_STORAGE_DIAGNOSTIC
    ; Input Buffer :
    ;      STORAGE_DIAGNOSTIC_REQUEST
    ; Output Buffer :
    ;      STORAGE_DIAGNOSTIC_DATA
    STORAGE_DIAGNOSTIC_LEVEL typedef SDWORD
    StorageDiagnosticLevelDefault equ 0
    StorageDiagnosticLevelMax equ 1
    _STORAGE_DIAGNOSTIC_LEVEL typedef STORAGE_DIAGNOSTIC_LEVEL
    PSTORAGE_DIAGNOSTIC_LEVEL typedef ptr STORAGE_DIAGNOSTIC_LEVEL
    STORAGE_DIAGNOSTIC_TARGET_TYPE typedef SDWORD
    StorageDiagnosticTargetTypeUndefined equ 0
    StorageDiagnosticTargetTypePort equ 1
    StorageDiagnosticTargetTypeMiniport equ 2
    StorageDiagnosticTargetTypeHbaFirmware equ 3
    StorageDiagnosticTargetTypeMax equ 4
    _STORAGE_DIAGNOSTIC_TARGET_TYPE typedef STORAGE_DIAGNOSTIC_TARGET_TYPE
    PSTORAGE_DIAGNOSTIC_TARGET_TYPE typedef ptr STORAGE_DIAGNOSTIC_TARGET_TYPE
    ; Indicate the target of the request other than the device handle/object itself.
    ; This is used in "Flags" field of data structures.
    STORAGE_DIAGNOSTIC_FLAG_ADAPTER_REQUEST equ 00000001h
    ; STORAGE_DIAGNOSTIC_REQUEST
    STORAGE_DIAGNOSTIC_REQUEST struct
      ; Size of this structure.
      Version DWORD ?
      ; Whole size of the structure and the associated data buffer.
      ; (In case adding variable-sized buffer in future.)
      Size_ DWORD ?
      ; Request flag.
      Flags DWORD ?
      ; Request target type. See definitions for STORAGE_DIAGNOSTIC_TARGET_TYPE.
      TargetType STORAGE_DIAGNOSTIC_TARGET_TYPE ?
      ; Diagnostic level. See definitions for STORAGE_DIAGNOSTIC_LEVEL.
      Level STORAGE_DIAGNOSTIC_LEVEL ?
    STORAGE_DIAGNOSTIC_REQUEST ends
    _STORAGE_DIAGNOSTIC_REQUEST typedef STORAGE_DIAGNOSTIC_REQUEST
    PSTORAGE_DIAGNOSTIC_REQUEST typedef ptr STORAGE_DIAGNOSTIC_REQUEST
    ; STORAGE_DIAGNOSTIC_DATA
    STORAGE_DIAGNOSTIC_DATA struct
      ; Size of this structure.
      Version DWORD ?
      ; Whole size of the structure and the associated data buffer.
      Size_ DWORD ?
      ; GUID of diagnostic data provider.
      ProviderId GUID <>
      ; If the request failed because of buffer too small, this field should be filled with the required buffer
      ; size for DiagnosticDataBuffer needed by provider;
      ; if the request is successful, it should be filled with returned buffer size of DiagnosticDataBuffer;
      ; it should be cleared to zero for other cases.
      BufferSize DWORD ?
      ; Reserved for future use.
      Reserved DWORD ?
      ; Diagnostic data buffer.
      DiagnosticDataBuffer BYTE ANYSIZE_ARRAY dup (?)
    STORAGE_DIAGNOSTIC_DATA ends
    _STORAGE_DIAGNOSTIC_DATA typedef STORAGE_DIAGNOSTIC_DATA
    PSTORAGE_DIAGNOSTIC_DATA typedef ptr STORAGE_DIAGNOSTIC_DATA
    ; IOCTL_STORAGE_GET_PHYSICAL_ELEMENT_STATUS
    ; Input:
    ;       PHYSICAL_ELEMENT_STATUS_REQUEST
    ; Output:
    ;       PHYSICAL_ELEMENT_STATUS
    PHYSICAL_ELEMENT_STATUS_REQUEST struct
      Version DWORD ?
      Size_ DWORD ?
      StartingElement DWORD ?
      Filter BYTE ?
      ReportType BYTE ?
      Reserved BYTE 2 dup (?)
    PHYSICAL_ELEMENT_STATUS_REQUEST ends
    _PHYSICAL_ELEMENT_STATUS_REQUEST typedef PHYSICAL_ELEMENT_STATUS_REQUEST
    PPHYSICAL_ELEMENT_STATUS_REQUEST typedef ptr PHYSICAL_ELEMENT_STATUS_REQUEST
    PHYSICAL_ELEMENT_STATUS_DESCRIPTOR struct
      Version DWORD ?
      Size_ DWORD ?
      ElementIdentifier DWORD ?
      PhysicalElementType BYTE ?
      PhysicalElementHealth BYTE ?
      Reserved1 BYTE 2 dup (?)
      ; In unit of LBA.
      AssociatedCapacity QWORD ?
      Reserved2 DWORD 4 dup (?)
    PHYSICAL_ELEMENT_STATUS_DESCRIPTOR ends
    _PHYSICAL_ELEMENT_STATUS_DESCRIPTOR typedef PHYSICAL_ELEMENT_STATUS_DESCRIPTOR
    PPHYSICAL_ELEMENT_STATUS_DESCRIPTOR typedef ptr PHYSICAL_ELEMENT_STATUS_DESCRIPTOR
    PHYSICAL_ELEMENT_STATUS struct
      Version DWORD ?
      Size_ DWORD ?
      DescriptorCount DWORD ?
      ReturnedDescriptorCount DWORD ?
      ElementIdentifierBeingDepoped DWORD ?
      Reserved DWORD ?
      Descriptors PHYSICAL_ELEMENT_STATUS_DESCRIPTOR ANYSIZE_ARRAY dup (<>)
    PHYSICAL_ELEMENT_STATUS ends
    _PHYSICAL_ELEMENT_STATUS typedef PHYSICAL_ELEMENT_STATUS
    PPHYSICAL_ELEMENT_STATUS typedef ptr PHYSICAL_ELEMENT_STATUS
    ; IOCTL_STORAGE_REMOVE_ELEMENT_AND_TRUNCATE
    ; Input:
    ;       REMOVE_ELEMENT_AND_TRUNCATE_REQUEST
    REMOVE_ELEMENT_AND_TRUNCATE_REQUEST struct
      Version DWORD ?
      Size_ DWORD ?
      ; In unit of LBA.
      RequestCapacity QWORD ?
      ElementIdentifier DWORD ?
      Reserved DWORD ?
    REMOVE_ELEMENT_AND_TRUNCATE_REQUEST ends
    _REMOVE_ELEMENT_AND_TRUNCATE_REQUEST typedef REMOVE_ELEMENT_AND_TRUNCATE_REQUEST
    PREMOVE_ELEMENT_AND_TRUNCATE_REQUEST typedef ptr REMOVE_ELEMENT_AND_TRUNCATE_REQUEST
    ; IOCTL_STORAGE_GET_DEVICE_INTERNAL_LOG
    ; Input:
    ;       GET_DEVICE_INTERNAL_STATUS_DATA_REQUEST
    ; Output:
    ;       DEVICE_INTERNAL_STATUS_DATA
    ERROR_HISTORY_DIRECTORY_ENTRY_DEFAULT_COUNT equ 8
    DEVICE_INTERNAL_STATUS_DATA_REQUEST_TYPE typedef SDWORD
    DeviceInternalStatusDataRequestTypeUndefined equ 0
    DeviceCurrentInternalStatusDataHeader equ 1
    DeviceCurrentInternalStatusData equ 2
    DeviceSavedInternalStatusDataHeader equ 3
    DeviceSavedInternalStatusData equ 4
    _DEVICE_INTERNAL_STATUS_DATA_REQUEST_TYPE typedef DEVICE_INTERNAL_STATUS_DATA_REQUEST_TYPE
    PDEVICE_INTERNAL_STATUS_DATA_REQUEST_TYPE typedef ptr DEVICE_INTERNAL_STATUS_DATA_REQUEST_TYPE
    DEVICE_INTERNAL_STATUS_DATA_SET typedef SDWORD
    DeviceStatusDataSetUndefined equ 0
    DeviceStatusDataSet1 equ 1
    DeviceStatusDataSet2 equ 2
    DeviceStatusDataSet3 equ 3
    DeviceStatusDataSet4 equ 4
    DeviceStatusDataSetMax equ 5
    _DEVICE_INTERNAL_STATUS_DATA_SET typedef DEVICE_INTERNAL_STATUS_DATA_SET
    PDEVICE_INTERNAL_STATUS_DATA_SET typedef ptr DEVICE_INTERNAL_STATUS_DATA_SET
    GET_DEVICE_INTERNAL_STATUS_DATA_REQUEST struct
      Version DWORD ?
      Size_ DWORD ?
      RequestDataType DEVICE_INTERNAL_STATUS_DATA_REQUEST_TYPE ?
      RequestDataSet DEVICE_INTERNAL_STATUS_DATA_SET ?
    GET_DEVICE_INTERNAL_STATUS_DATA_REQUEST ends
    _GET_DEVICE_INTERNAL_STATUS_DATA_REQUEST typedef GET_DEVICE_INTERNAL_STATUS_DATA_REQUEST
    PGET_DEVICE_INTERNAL_STATUS_DATA_REQUEST typedef ptr GET_DEVICE_INTERNAL_STATUS_DATA_REQUEST
    DEVICE_INTERNAL_STATUS_DATA struct
      ; Size of this structure.
      Version DWORD ?
      ; Whole size of the structure and the associated data buffer.
      Size_ DWORD ?
      T10VendorId QWORD ?
      DataSet1Length DWORD ?
      DataSet2Length DWORD ?
      DataSet3Length DWORD ?
      DataSet4Length DWORD ?
      StatusDataVersion BYTE ?
      Reserved BYTE 3 dup (?)
      ReasonIdentifier BYTE 128 dup (?)
      StatusDataLength DWORD ?
      StatusData BYTE ANYSIZE_ARRAY dup (?)
    DEVICE_INTERNAL_STATUS_DATA ends
    _DEVICE_INTERNAL_STATUS_DATA typedef DEVICE_INTERNAL_STATUS_DATA
    PDEVICE_INTERNAL_STATUS_DATA typedef ptr DEVICE_INTERNAL_STATUS_DATA
    ; IOCTL_STORAGE_REINITIALIZE_MEDIA
    ; Input Buffer :
    ;      STORAGE_REINITIALIZE_MEDIA - Optional
    ; Output Buffer :
    ;      None
    STORAGE_SANITIZE_METHOD typedef SDWORD
    StorageSanitizeMethodDefault equ 0
    StorageSanitizeMethodBlockErase equ 1
    StorageSanitizeMethodCryptoErase equ 2
    _STORAGE_SANITIZE_METHOD typedef STORAGE_SANITIZE_METHOD
    PSTORAGE_SANITIZE_METHOD typedef ptr STORAGE_SANITIZE_METHOD
    ; bit fields other than int to disable this around the struct
    STORAGE_REINITIALIZE_MEDIA struct
      Version DWORD ?
      Size_ DWORD ?
      TimeoutInSeconds DWORD ?
      ; The SanitizeOption field is only applicable to NVMe devices.
      struct SanitizeOption
        ; This field specifies the sanitize method defined in STORAGE_SANITIZE_METHOD enum.
        ; This field specifies if unrestricted sanitize exit is allowed or not.
        ; By default unrestricted sanitize exit is allowed.
        SanitizeOption_REC record SanitizeOption_REC_Reserved:27, SanitizeOption_REC_DisallowUnrestrictedSanitizeExit:1, SanitizeOption_REC_SanitizeMethod:4
        SanitizeOption_BITS SanitizeOption_REC <>
      ends
    STORAGE_REINITIALIZE_MEDIA ends
    _STORAGE_REINITIALIZE_MEDIA typedef STORAGE_REINITIALIZE_MEDIA
    PSTORAGE_REINITIALIZE_MEDIA typedef ptr STORAGE_REINITIALIZE_MEDIA
    if Defined(_MSC_EXTENSIONS)
      STORAGE_MEDIA_SERIAL_NUMBER_DATA struct
        Reserved WORD ?
        ; the SerialNumberLength will be set to zero
        ; if the command is supported and the media
        ; does not have a valid serial number.
        SerialNumberLength WORD ?
        ; the following data is binary, and is not guaranteed
        ; to be NULL terminated.  this is an excercise for the
        ; caller.
        if  not Defined(__midl)
          SerialNumber BYTE 0 dup (?)
        endif
      STORAGE_MEDIA_SERIAL_NUMBER_DATA ends
      _STORAGE_MEDIA_SERIAL_NUMBER_DATA typedef STORAGE_MEDIA_SERIAL_NUMBER_DATA
      PSTORAGE_MEDIA_SERIAL_NUMBER_DATA typedef ptr STORAGE_MEDIA_SERIAL_NUMBER_DATA
      ;* _MSC_EXTENSIONS *
    endif
    STORAGE_READ_CAPACITY struct
      ; The version number, size of the STORAGE_READ_CAPACITY structure
      Version DWORD ?
      ; The size of the date returned, size of the STORAGE_READ_CAPACITY structure
      Size_ DWORD ?
      ; Number of bytes per block
      BlockLength DWORD ?
      ; Total number of blocks in the disk
      ; This will have the last LBA + 1
      NumberOfBlocks LARGE_INTEGER <>
      ; Disk size in bytes
      DiskLength LARGE_INTEGER <>
    STORAGE_READ_CAPACITY ends
    _STORAGE_READ_CAPACITY typedef STORAGE_READ_CAPACITY
    PSTORAGE_READ_CAPACITY typedef ptr STORAGE_READ_CAPACITY
    ; Device write cache property
    ; This property provides the write cache information
    ; about the target device.
    WRITE_CACHE_TYPE typedef SDWORD
    WriteCacheTypeUnknown equ 0
    WriteCacheTypeNone equ 1
    WriteCacheTypeWriteBack equ 2
    WriteCacheTypeWriteThrough equ 3
    _WRITE_CACHE_TYPE typedef WRITE_CACHE_TYPE

    WRITE_CACHE_ENABLE typedef SDWORD
    WriteCacheEnableUnknown equ 0
    WriteCacheDisabled equ 1
    WriteCacheEnabled equ 2
    _WRITE_CACHE_ENABLE typedef WRITE_CACHE_ENABLE

    WRITE_CACHE_CHANGE typedef SDWORD
    WriteCacheChangeUnknown equ 0
    WriteCacheNotChangeable equ 1
    WriteCacheChangeable equ 2
    _WRITE_CACHE_CHANGE typedef WRITE_CACHE_CHANGE

    WRITE_THROUGH typedef SDWORD
    WriteThroughUnknown equ 0
    WriteThroughNotSupported equ 1
    WriteThroughSupported equ 2
    _WRITE_THROUGH typedef WRITE_THROUGH

    STORAGE_WRITE_CACHE_PROPERTY struct
      ; The version number
      ; Size of STORAGE_WRITE_CACHE_PROPERTY structure
      Version DWORD ?
      ; The size of the date returned
      ; Size of STORAGE_WRITE_CACHE_PROPERTY structure
      Size_ DWORD ?
      ; Current write cache type
      WriteCacheType WRITE_CACHE_TYPE ?
      ; Current write cache value
      WriteCacheEnabled WRITE_CACHE_ENABLE ?
      ; Device write cache change capability
      WriteCacheChangeable WRITE_CACHE_CHANGE ?
      ; Device write through support capability
      WriteThroughSupported WRITE_THROUGH ?
      ; Device flush cache capability
      FlushCacheSupported BYTE ?
      ; User selected power protection option through registry
      UserDefinedPowerProtection BYTE ?
      ; Device has battery backup for write cache
      NVCacheEnabled BYTE ?
    STORAGE_WRITE_CACHE_PROPERTY ends
    _STORAGE_WRITE_CACHE_PROPERTY typedef STORAGE_WRITE_CACHE_PROPERTY
    PSTORAGE_WRITE_CACHE_PROPERTY typedef ptr STORAGE_WRITE_CACHE_PROPERTY
    ; array[0]
    ; nameless struct/unions
    ; bit fields other than int
    if Defined(_MSC_EXTENSIONS)
      PERSISTENT_RESERVE_COMMAND struct
        Version DWORD ?
        Size_ DWORD ?
        union
          struct PR_IN
            ; Persistent Reserve service action.
            ; Number of bytes allocated for returned parameter list.
            PR_IN_REC record PR_IN_REC_Filler:8, PR_IN_REC_Reserved1:3, PR_IN_REC_ServiceAction:5
            PR_IN_BITS PR_IN_REC <>
            ; Number of bytes allocated for returned parameter list.
            AllocationLength WORD ?
          ends
          struct PR_OUT
            ; Persistent Reserve service action.
            ; Persistent Reserve type and scope.
            PR_OUT_REC record PR_OUT_REC_Scope:4, PR_OUT_REC_Type:4, PR_OUT_REC_Reserved1:3, PR_OUT_REC_ServiceAction:5
            PR_OUT_BITS PR_OUT_REC <>
            ; Space for additional PR Out parameters.
            if  not Defined(__midl)
              ParameterList BYTE 0 dup (?)
            endif
          ends
        ends
      PERSISTENT_RESERVE_COMMAND ends
      _PERSISTENT_RESERVE_COMMAND typedef PERSISTENT_RESERVE_COMMAND
      PPERSISTENT_RESERVE_COMMAND typedef ptr PERSISTENT_RESERVE_COMMAND
      ;* _MSC_EXTENSIONS *
    endif
    ;  Device telemetry definitions
    ;  Structures and interfaces dealing with acquistion of device and driver internal telemetry.
    ; For variable size fields we use byte array, defined with zero length in structure template. Length of the field is stored as a separate field.
    ; No more than one variable size field is allowed in one structure and it is always placed last.
    ; Persistent data structures are versioned and "sized" by adding structure version field and structure size field
    DEVICEDUMP_STRUCTURE_VERSION_V1 equ 1
    ; Max size of the identification string
    DEVICEDUMP_MAX_IDSTRING equ 32; Keep proportional to sizeof (DWORD)

    MAX_FW_BUCKET_ID_LENGTH equ 132; 128 (ACS specification + 1 for zero termination + 3 to align on DWORD)

    ; Global telemetry collection parameters in the registry
    STORAGE_CRASH_TELEMETRY_REGKEY equ <L("\Registry\Machine\System\CurrentControlSet\Control\CrashControl\StorageTelemetry")>
    STORAGE_DEVICE_TELEMETRY_REGKEY equ <L("\Registry\Machine\System\CurrentControlSet\Control\Storage\StorageTelemetry")>
    ; Reasons for telemetry collection
    DEVICEDUMP_COLLECTION_TYPEIDE_NOTIFICATION_TYPE typedef SDWORD
    TCCollectionBugCheck equ 1
    ; 1
    TCCollectionApplicationRequested equ 2
    ; 2 (Host Initiated - HITC)
    TCCollectionDeviceRequested equ 3
    _DEVICEDUMP_COLLECTION_TYPE typedef DEVICEDUMP_COLLECTION_TYPEIDE_NOTIFICATION_TYPE
    PDEVICEDUMP_COLLECTION_TYPE typedef ptr DEVICEDUMP_COLLECTION_TYPEIDE_NOTIFICATION_TYPE
    ; 3 (Device initiated - DITC)
    ; Flags for the device dump section
    DDUMP_FLAG_DATA_READ_FROM_DEVICE equ 0001h
    ; Firmware issue IDs (similar to bug check reasons)
    FW_ISSUEID_NO_ISSUE equ 00000000h
    FW_ISSUEID_UNKNOWN equ 0FFFFFFFFh
    include pshpack1.inc
    ; Structures are packed on a byte boundary , because parsers may run on separate machines and different OS flavors
    ;  Device dump section contains common device dump header, followed by set of relative pointers to sub sections
    ;  Each relative pointer contain size in bytes of the subsection and starting offset from the beginning of the section
    ; Layout of the device dump section is as
    ;   HEADER         - common descriptor
    ;   PUBLIC DATA    - publicly accessible data (eg SMART structures)
    ;   RESRICTED DATA - restricted access data (eg encrypted with Microsoft and IHV public keys)
    ;   PRIVATE DATA   - private device data
    ; All fields in the section definition are used cross platform => types used are platform neutral
    ; Relative descript    or of a subsection, contains size of the subsection and relative offset (0 is the start of the section)
    DEVICEDUMP_SUBSECTION_POINTER struct
      dwSize DWORD ?
      ; Size (in bytes) of the subsection
      dwFlags DWORD ?
      ; Parameter flags for the subsection
      dwOffset DWORD ?
      ; Offset (in bytes) of the subsection block from the start of the buffer
    DEVICEDUMP_SUBSECTION_POINTER ends
    _DEVICEDUMP_SUBSECTION_POINTER typedef DEVICEDUMP_SUBSECTION_POINTER
    PDEVICEDUMP_SUBSECTION_POINTER typedef ptr DEVICEDUMP_SUBSECTION_POINTER
    ; Data structure tagging fields (version and size)
    DEVICEDUMP_STRUCTURE_VERSION struct
      ; Header signature, useful for identifying the structure when reading the dump
      dwSignature DWORD ?
      ; Version of the template
      dwVersion DWORD ?
      ; Size of the parent structure in bytes
      dwSize DWORD ?
    DEVICEDUMP_STRUCTURE_VERSION ends
    _DEVICEDUMP_STRUCTURE_VERSION typedef DEVICEDUMP_STRUCTURE_VERSION
    PDEVICEDUMP_STRUCTURE_VERSION typedef ptr DEVICEDUMP_STRUCTURE_VERSION
    ;  Device data header for the secondary data (in crashdump) section , holding device dump information.
    DEVICEDUMP_SECTION_HEADER struct
      ; GUID, identifying device dump section. Same GUID as used in registering for SecondaryData callback, stored here for live telemetry interface consistency
      guidDeviceDataId GUID <>
      ; Device identification fields.
      ; These fields together should uniquely identify the device firmware image.
      ;  ID value, common for storage device vendors. This ID will be used by !analyze to create a vendor ID for WinQual.
      ; Unique identifier assigned to the organization responsible for device quality (firmware quality). In most cases this is OUID (IEEE) or WorldWideName of the device vendor
      sOrganizationID BYTE 16 dup (?)
      ; Firmware revision as indicated in IDENITFY or INQUIRY structures
      dwFirmwareRevision DWORD ?
      ; Device model number (keep the length of the field proportional to sizeof (DWORD))
      sModelNumber BYTE DEVICEDUMP_MAX_IDSTRING dup (?)
      ; Vendor specific device cookie, identifying process and manufacturing parameters. Opaque to the OS and applications.
      szDeviceManufacturingID BYTE DEVICEDUMP_MAX_IDSTRING dup (?)
      ; Keep the length of the field proportional to sizeof (DWORD)
      ; Sourcing indicator flag - used to detect if data was emulated from other structures or obtained directly from the firmware using log command
      ;      Set to 1 if public data was filled in using data from the device telemetry log
      ;      Set to 0 if the device doesn't support the command and the driver filled in as best it could
      dwFlags DWORD ?
      ; Version of private data as indicated by the firmware.Initially always 0 to specify Private only unspecified data
      bRestrictedPrivateDataVersion DWORD ?
      ; Issue identifier (hash value) generated by the firmware. Reflects state of the device firmware and used for cross device type/vendor queries.
      ; We will rely on standardized namespace of issue IDs and good will of firmware developers to taxonomize
      dwFirmwareIssueId DWORD ?
      ;currently unused
      ; Firmware bucket ID - long string, opague to Windows , but useful to create unique bucket in concatenation with device identification data
      szIssueDescriptionString BYTE MAX_FW_BUCKET_ID_LENGTH dup (?)
      ; zero terminated
    DEVICEDUMP_SECTION_HEADER ends
    _DEVICEDUMP_SECTION_HEADER typedef DEVICEDUMP_SECTION_HEADER
    PDEVICEDUMP_SECTION_HEADER typedef ptr DEVICEDUMP_SECTION_HEADER
    ;  Public subsection header - subsection is holding data, describing device state and accessible to everybody.
    TC_PUBLIC_DEVICEDUMP_CONTENT_SMART equ 01h
    TC_PUBLIC_DEVICEDUMP_CONTENT_GPLOG equ 02h
    ; Maximum number of log pages collected into the public section
    TC_PUBLIC_DEVICEDUMP_CONTENT_GPLOG_MAX equ 16
    ; Maximum length of the description of the collected pages (filled by the miniport)
    TC_DEVICEDUMP_SUBSECTION_DESC_LENGTH equ 16
    ; Standard types of collected pages
    TC_PUBLIC_DATA_TYPE_ATAGP equ <"ATAGPLogPages">
    TC_PUBLIC_DATA_TYPE_ATASMART equ <"ATASMARTPages">
    ; Public data is tagged with the table of "log descriptors". Each descriptor has LogAddress and number of pages.
    ; Specific meaning, assigned to the descriptor, is relative to the command set used.
    GP_LOG_PAGE_DESCRIPTOR struct
      LogAddress WORD ?
      LogSectors WORD ?
    GP_LOG_PAGE_DESCRIPTOR ends
    _GP_LOG_PAGE_DESCRIPTOR typedef GP_LOG_PAGE_DESCRIPTOR
    PGP_LOG_PAGE_DESCRIPTOR typedef ptr GP_LOG_PAGE_DESCRIPTOR
    DEVICEDUMP_PUBLIC_SUBSECTION struct
      dwFlags DWORD ?
      GPLogTable GP_LOG_PAGE_DESCRIPTOR TC_PUBLIC_DEVICEDUMP_CONTENT_GPLOG_MAX dup (<>)
      szDescription SBYTE TC_DEVICEDUMP_SUBSECTION_DESC_LENGTH dup (?)
      ; Zero terminated
      bData BYTE ANYSIZE_ARRAY dup (?)
      ; Data byte array ANYSIZE_ARRAY
    DEVICEDUMP_PUBLIC_SUBSECTION ends
    _DEVICEDUMP_PUBLIC_SUBSECTION typedef DEVICEDUMP_PUBLIC_SUBSECTION
    PDEVICEDUMP_PUBLIC_SUBSECTION typedef ptr DEVICEDUMP_PUBLIC_SUBSECTION
    ;  Restricted subsection header - subsection is holding data, describing device state and accessible only to Microsoft and a device vendor
    DEVICEDUMP_RESTRICTED_SUBSECTION struct
      bData BYTE ANYSIZE_ARRAY dup (?)
      ; Data byte array (ANYSIZE_ARRAY)
    DEVICEDUMP_RESTRICTED_SUBSECTION ends
    _DEVICEDUMP_RESTRICTED_SUBSECTION typedef DEVICEDUMP_RESTRICTED_SUBSECTION
    PDEVICEDUMP_RESTRICTED_SUBSECTION typedef ptr DEVICEDUMP_RESTRICTED_SUBSECTION
    ;  Private subsection header - subsection is holding data, describing device state and accessible only to a device vendor
    DEVICEDUMP_PRIVATE_SUBSECTION struct
      dwFlags DWORD ?
      GPLogId GP_LOG_PAGE_DESCRIPTOR <>
      bData BYTE ANYSIZE_ARRAY dup (?)
      ; Data byte array (ANYSIZE_ARRAY)
    DEVICEDUMP_PRIVATE_SUBSECTION ends
    _DEVICEDUMP_PRIVATE_SUBSECTION typedef DEVICEDUMP_PRIVATE_SUBSECTION
    PDEVICEDUMP_PRIVATE_SUBSECTION typedef ptr DEVICEDUMP_PRIVATE_SUBSECTION
    ; Descriptor of the storage device dump section
    DEVICEDUMP_STORAGEDEVICE_DATA struct
      ; Common descriptor (signature,version of the structure)
      Descriptor DEVICEDUMP_STRUCTURE_VERSION <>
      ; Header - set of fields, describing dump section and device (not requiring protocol communication)
      SectionHeader DEVICEDUMP_SECTION_HEADER <>
      ; Size of the whole section buffer, in bytes , including header and sum total of all the variable sized sub sections
      dwBufferSize DWORD ?
      ; Reason for collecting telemetry
      dwReasonForCollection DWORD ?
      ; "Pointers" to individual sub-sections. Sub sections are filled with the information, obtained from the device
      PublicData DEVICEDUMP_SUBSECTION_POINTER <>
      RestrictedData DEVICEDUMP_SUBSECTION_POINTER <>
      PrivateData DEVICEDUMP_SUBSECTION_POINTER <>
    DEVICEDUMP_STORAGEDEVICE_DATA ends
    _DEVICEDUMP_STORAGEDEVICE_DATA typedef DEVICEDUMP_STORAGEDEVICE_DATA
    PDEVICEDUMP_STORAGEDEVICE_DATA typedef ptr DEVICEDUMP_STORAGEDEVICE_DATA
    ; Driver dump section contains common device driver context information:
    ;      - circular buffer of the IO requests as visible by the lower edge of the driver
    ;              (in case of storage that would be an interface to the controller stack or controller itself)
    ; All fields in the section definition are used cross platform => types used are platform neutral
    ; Format of the single record for publicly accessible driver state table
    CDB_SIZE equ 16
    TELEMETRY_COMMAND_SIZE equ 16
    TCRecordStorportSrbFunction equ Command [ 0 ]
    DEVICEDUMP_STORAGESTACK_PUBLIC_STATE_RECORD struct
      ; The CDB for this request. variable sized CDBs are truncated.
      Cdb BYTE CDB_SIZE dup (?)
      ; The actual command for this request.
      Command BYTE TELEMETRY_COMMAND_SIZE dup (?)
      ; the time when driver received the request
      StartTime QWORD ?
      ; the system time when the request was completed
      EndTime QWORD ?
      ; Status value ()
      OperationStatus DWORD ?
      ; Error value (eg error reg for ATAPort, SCSI error for storport)
      OperationError DWORD ?
      ; Stack specific information
      union StackSpecific
        struct ExternalStack
          dwReserved DWORD ?
        ends
        struct AtaPort
          dwAtaPortSpecific DWORD ?
        ends
        struct StorPort
          SrbTag DWORD ?
        ends
      ends
    DEVICEDUMP_STORAGESTACK_PUBLIC_STATE_RECORD ends
    _DEVICEDUMP_STORAGESTACK_PUBLIC_STATE_RECORD typedef DEVICEDUMP_STORAGESTACK_PUBLIC_STATE_RECORD
    PDEVICEDUMP_STORAGESTACK_PUBLIC_STATE_RECORD typedef ptr DEVICEDUMP_STORAGESTACK_PUBLIC_STATE_RECORD
    DEVICEDUMP_STORAGESTACK_PUBLIC_DUMP struct
      ; Common descriptor (signature,version of the structure)
      Descriptor DEVICEDUMP_STRUCTURE_VERSION <>
      ; Reason for collecting telemetry
      dwReasonForCollection DWORD ?
      ; Driver stack and instance
      cDriverName BYTE 16 dup (?)
      ; Standardized log of IO requests issued to the target, starting with number of records.
      ; Log is circular, order is not guaranteed
      uiNumRecords DWORD ?
      RecordArray DEVICEDUMP_STORAGESTACK_PUBLIC_STATE_RECORD ANYSIZE_ARRAY dup (<>)
      ;ANYSIZE_ARRAY
    DEVICEDUMP_STORAGESTACK_PUBLIC_DUMP ends
    _DEVICEDUMP_STORAGESTACK_PUBLIC_DUMP typedef DEVICEDUMP_STORAGESTACK_PUBLIC_DUMP
    PDEVICEDUMP_STORAGESTACK_PUBLIC_DUMP typedef ptr DEVICEDUMP_STORAGESTACK_PUBLIC_DUMP
    ; End of the packed structure group
    include poppack.inc
    ; Telemetry information block descriptor - bit flags in DumpCapabilities field
    DEVICEDUMP_CAP_PRIVATE_SECTION equ 00000001h; Target supports private data

    DEVICEDUMP_CAP_RESTRICTED_SECTION equ 00000002h; Target supports restricted data

    ; bit fields other than int
    ; IOCTL_STORAGE_ENABLE_IDLE_POWER
    ; Input Buffer:
    ;      A STORAGE_IDLE_POWER structure specifying the idle power management
    ;      properties of the device.
    ; Output Buffer:
    ;      None.
    STORAGE_IDLE_POWER struct
      Version DWORD ?
      ; Structure version, should be set to 1 for Win8.
      Size_ DWORD ?
      ; Size of this structure in bytes.
      ; Storage device supports wake from low power states.
      ; Storage device supports D3Cold
      STORAGE_IDLE_POWER_REC record STORAGE_IDLE_POWER_REC_Reserved:30, STORAGE_IDLE_POWER_REC_D3ColdSupported:1, STORAGE_IDLE_POWER_REC_WakeCapableHint:1
      STORAGE_IDLE_POWER_BITS STORAGE_IDLE_POWER_REC <>
      D3IdleTimeout DWORD ?
      ; Idle time in msec before storage device is transitioned to D3 (max of ~49.7 days).
    STORAGE_IDLE_POWER ends
    _STORAGE_IDLE_POWER typedef STORAGE_IDLE_POWER
    PSTORAGE_IDLE_POWER typedef ptr STORAGE_IDLE_POWER
    ; IOCTL_STORAGE_GET_IDLE_POWERUP_REASON
    ; Input Buffer:
    ;      None.
    ; Output Buffer:
    ;      A STORAGE_IDLE_POWERUP_REASON structure specifying what caused the power up.
    STORAGE_POWERUP_REASON_TYPE typedef SDWORD
    StoragePowerupUnknown equ 0
    StoragePowerupIO equ 1
    StoragePowerupDeviceAttention equ 2
    _STORAGE_POWERUP_REASON_TYPE typedef STORAGE_POWERUP_REASON_TYPE
    PSTORAGE_POWERUP_REASON_TYPE typedef ptr STORAGE_POWERUP_REASON_TYPE
    STORAGE_IDLE_POWERUP_REASON struct
      Version DWORD ?
      ; Structure version, should be set to 1 for Win8.
      Size_ DWORD ?
      ; Size of this structure in bytes.
      PowerupReason STORAGE_POWERUP_REASON_TYPE ?
      ; The reason for the power up (see above).
    STORAGE_IDLE_POWERUP_REASON ends
    _STORAGE_IDLE_POWERUP_REASON typedef STORAGE_IDLE_POWERUP_REASON
    PSTORAGE_IDLE_POWERUP_REASON typedef ptr STORAGE_IDLE_POWERUP_REASON
    STORAGE_IDLE_POWERUP_REASON_VERSION_V1 equ 1
    ; IOCTL_STORAGE_DEVICE_POWER_CAP
    ; This IOCTL specifies a maximum *operational* power consumption level for a
    ; storage device.
    ; The storage stack will do its best to transition the device to a power state
    ; that will not exceed the given maximum.  However, this depends on what the
    ; device supports.  The actual maximum may be less than or greater than the
    ; desired maximum.
    ; Input buffer:
    ;  A STORAGE_DEVICE_POWER_CAP structure.
    ;  * The Units field specifies the units of the MaxPower field.  It can be
    ;    either a percentage (0-100%) or an absolute value in milliwatts.
    ;  * The MaxPower field is used to set the desired maximum power consumption
    ;    value for the storage device.
    ; Output buffer:
    ;  On success, the output buffer will contain a STORAGE_DEVICE_POWER_CAP
    ;  structure.
    ;  * The Units field will continue to specify the units of the MaxPower field
    ;    and will match the value from the input buffer.
    ;  * The MaxPower field will contain the value of the actual maximum
    ;    power consumption level of the device.  This may be equal to, less than,
    ;    or greater than the desired cap, depending on what the device supports.
    STORAGE_DEVICE_POWER_CAP_UNITS typedef SDWORD
    StorageDevicePowerCapUnitsPercent equ 0
    StorageDevicePowerCapUnitsMilliwatts equ 1
    _STORAGE_DEVICE_POWER_CAP_UNITS typedef STORAGE_DEVICE_POWER_CAP_UNITS
    PSTORAGE_DEVICE_POWER_CAP_UNITS typedef ptr STORAGE_DEVICE_POWER_CAP_UNITS
    STORAGE_DEVICE_POWER_CAP struct
      Version DWORD ?
      Size_ DWORD ?
      Units STORAGE_DEVICE_POWER_CAP_UNITS ?
      MaxPower QWORD ?
    STORAGE_DEVICE_POWER_CAP ends
    _STORAGE_DEVICE_POWER_CAP typedef STORAGE_DEVICE_POWER_CAP
    PSTORAGE_DEVICE_POWER_CAP typedef ptr STORAGE_DEVICE_POWER_CAP
    STORAGE_DEVICE_POWER_CAP_VERSION_V1 equ 1
    ; IOCTL_STORAGE_RPMB_COMMAND
    ; This IOCTL sends an RPMB command to the underlying storage device.
    ; Input buffer:
    ;  An array of STORAGE_RPMB_DATA_FRAME structures
    ;  * The number of frames included can be calculated by InputBufferLength / sizeof(STORAGE_RPMB_DATA_FRAME)
    ; Output buffer:
    ;  An array of STORAGE_RPMB_DATA_FRAME structures
    ;  * The number of frames included can be calculated by OutputBufferLength / sizeof(STORAGE_RPMB_DATA_FRAME)
    ; Ensure we are byte aligned
    ; This is the RPMB data frame used to compose all RPMB requests and responses.
    ; This corresponds to StorageRpmbFrameTypeStandard
    STORAGE_RPMB_DATA_FRAME struct
      ; Reserved
      Stuff BYTE 196 dup (?)
      ; Either the key to be programmed or the MAC authenticating this frame or series of frames
      KeyOrMAC BYTE 32 dup (?)
      ; The data input or output
      Data BYTE 256 dup (?)
      ; Random 128-bit number generated by host
      Nonce BYTE 16 dup (?)
      ; 32-bit counter
      WriteCounter BYTE 4 dup (?)
      ; The half-sector address to operate on
      Address BYTE 2 dup (?)
      ; The count of half-sector blocks to read/write
      BlockCount BYTE 2 dup (?)
      ; The result of the operation
      OperationResult BYTE 2 dup (?)
      ; The type of request or response
      RequestOrResponseType BYTE 2 dup (?)
    STORAGE_RPMB_DATA_FRAME ends
    _STORAGE_RPMB_DATA_FRAME typedef STORAGE_RPMB_DATA_FRAME
    PSTORAGE_RPMB_DATA_FRAME typedef ptr STORAGE_RPMB_DATA_FRAME
    ; RPMB RequestOrResponseType Values
    STORAGE_RPMB_COMMAND_TYPE typedef SDWORD
    StorRpmbProgramAuthKey equ 00000001h
    StorRpmbQueryWriteCounter equ 00000002h
    StorRpmbAuthenticatedWrite equ 00000003h
    StorRpmbAuthenticatedRead equ 00000004h
    StorRpmbReadResultRequest equ 00000005h
    StorRpmbAuthenticatedDeviceConfigWrite equ 00000006h
    StorRpmbAuthenticatedDeviceConfigRead equ 00000007h
    _STORAGE_RPMB_COMMAND_TYPE typedef STORAGE_RPMB_COMMAND_TYPE
    PSTORAGE_RPMB_COMMAND_TYPE typedef ptr STORAGE_RPMB_COMMAND_TYPE
    ; IOCTL_STORAGE_EVENT_NOTIFICATION
    ; Input Buffer:
    ;      A STORAGE_EVENT_NOTIFICATION structure specifying the event(s) that occurred.
    ; Output Buffer:
    ;      None
    STORAGE_EVENT_NOTIFICATION struct
      Version DWORD ?
      ; Structure version, should be set to 1 for Win8.
      Size_ DWORD ?
      ; Size of this structure in bytes.
      Events QWORD ?
      ; Bitmask of event(s) that occurred.
    STORAGE_EVENT_NOTIFICATION ends
    _STORAGE_EVENT_NOTIFICATION typedef STORAGE_EVENT_NOTIFICATION
    PSTORAGE_EVENT_NOTIFICATION typedef ptr STORAGE_EVENT_NOTIFICATION
    STORAGE_EVENT_NOTIFICATION_VERSION_V1 equ 1
    STORAGE_EVENT_MEDIA_STATUS equ 0000000000000001h
    STORAGE_EVENT_DEVICE_STATUS equ 0000000000000002h
    STORAGE_EVENT_DEVICE_OPERATION equ 0000000000000004h
    STORAGE_EVENT_ALL equ <(STORAGE_EVENT_MEDIA_STATUS or STORAGE_EVENT_DEVICE_STATUS or STORAGE_EVENT_DEVICE_OPERATION)>
    READ_COPY_NUMBER_KEY equ 52434e00h; 'RCN'

    READ_COPY_NUMBER_BYPASS_CACHE_FLAG equ 00000100h
    IsKeyReadCopyNumber macro _k
      exitm <(((_k) and 0FFFFFE00h) == READ_COPY_NUMBER_KEY)>
    endm
    IsKeyReadCopyNumberBypassCache macro _k
      exitm <((_k) and READ_COPY_NUMBER_BYPASS_CACHE_FLAG)>
    endm
    SetReadCopyNumberBypassCacheToKey macro _k
      exitm <((_k) or READ_COPY_NUMBER_BYPASS_CACHE_FLAG)>
    endm
    ReadCopyNumberToKey macro _c
      exitm <(READ_COPY_NUMBER_KEY or (_c))>
    endm
    ReadCopyNumberFromKey macro _k
      exitm <((_k) and 000000FFh)>
    endm
    ; IOCTL_STORAGE_GET_COUNTERS
    ; This IOCTL retrieves reliability counters for a storage device.
    ; The caller can find out the required output buffer size by simply sending
    ; down a single STORAGE_COUNTERS structure. STATUS_BUFFER_OVERFLOW will be
    ; returned and the Size field in the STORAGE_COUNTERS structure will contain
    ; the total size of the required output buffer.
    ; When the output buffer is sufficiently large, STATUS_SUCCESS will be
    ; returned and the output buffer will contain a STORAGE_COUNTERS structure
    ; followed by an array of STORAGE_COUNTER structures.
    ; Input Buffer:
    ;      STORAGE_COUNTERS with the Version field set appropriately.
    ; Output Buffer:
    ;      When successful, a STORAGE_COUNTERS structure with the Counters array
    ;      filled out.  NumberOfCounters will indicate the number of elements in
    ;      the Counters array.
    ;      See above for more details.
    STORAGE_COUNTER_TYPE typedef SDWORD
    StorageCounterTypeUnknown equ 0
    StorageCounterTypeTemperatureCelsius equ 1
    StorageCounterTypeTemperatureCelsiusMax equ 2
    StorageCounterTypeReadErrorsTotal equ 3
    StorageCounterTypeReadErrorsCorrected equ 4
    StorageCounterTypeReadErrorsUncorrected equ 5
    StorageCounterTypeWriteErrorsTotal equ 6
    StorageCounterTypeWriteErrorsCorrected equ 7
    StorageCounterTypeWriteErrorsUncorrected equ 8
    StorageCounterTypeManufactureDate equ 9
    StorageCounterTypeStartStopCycleCount equ 10
    StorageCounterTypeStartStopCycleCountMax equ 11
    StorageCounterTypeLoadUnloadCycleCount equ 12
    StorageCounterTypeLoadUnloadCycleCountMax equ 13
    StorageCounterTypeWearPercentage equ 14
    StorageCounterTypeWearPercentageWarning equ 15
    StorageCounterTypeWearPercentageMax equ 16
    StorageCounterTypePowerOnHours equ 17
    StorageCounterTypeReadLatency100NSMax equ 18
    StorageCounterTypeWriteLatency100NSMax equ 19
    StorageCounterTypeFlushLatency100NSMax equ 20
    StorageCounterTypeMax equ 21
    _STORAGE_COUNTER_TYPE typedef STORAGE_COUNTER_TYPE
    PSTORAGE_COUNTER_TYPE typedef ptr STORAGE_COUNTER_TYPE
    STORAGE_COUNTER struct
      Type_ STORAGE_COUNTER_TYPE ?
      union Value
        struct ManufactureDate
          ; Week is the number of the week in the year, 1-52.
          Week DWORD ?
          ; Year is the last two digits of the year, e.g. 2016 is simply "16".
          Year DWORD ?
        ends
        AsUlonglong QWORD ?
      ends
    STORAGE_COUNTER ends
    _STORAGE_COUNTER typedef STORAGE_COUNTER
    PSTORAGE_COUNTER typedef ptr STORAGE_COUNTER
    STORAGE_COUNTERS struct
      ; Size of this structure serves as the version.
      Version DWORD ?
      ; Total size of this structure plus all the variable-sized fields.
      Size_ DWORD ?
      NumberOfCounters DWORD ?
      Counters STORAGE_COUNTER ANYSIZE_ARRAY dup (<>)
    STORAGE_COUNTERS ends
    _STORAGE_COUNTERS typedef STORAGE_COUNTERS
    PSTORAGE_COUNTERS typedef ptr STORAGE_COUNTERS
    STORAGE_COUNTERS_VERSION_V1 equ <sizeof(STORAGE_COUNTERS)>
    ; Parameter and data structure for firmware upgrade IOCTLs
    ; IOCTL_STORAGE_FIRMWARE_GET_INFO, IOCTL_STORAGE_FIRMWARE_DOWNLOAD, IOCTL_STORAGE_FIRMWARE_ACTIVATE
    ; Indicate the target of the request other than the device handle/object itself.
    ; This is used in "Flags" field of data structures for firmware upgrade request.
    STORAGE_HW_FIRMWARE_REQUEST_FLAG_CONTROLLER equ 00000001h
    ; Indicate that current FW image segment is the last one.
    STORAGE_HW_FIRMWARE_REQUEST_FLAG_LAST_SEGMENT equ 00000002h
    ; Indicate that current FW image segment is the first one.
    STORAGE_HW_FIRMWARE_REQUEST_FLAG_FIRST_SEGMENT equ 00000004h
    ; Indicate that any existing firmware in slot should be replaced with the downloaded image.
    ; Only valid for IOCTL_STORAGE_FIRMWARE_ACTIVATE.
    STORAGE_HW_FIRMWARE_REQUEST_FLAG_REPLACE_EXISTING_IMAGE equ 40000000h
    ; Indicate that the existing firmware in slot should be activated.
    ; Only valid for IOCTL_STORAGE_FIRMWARE_ACTIVATE.
    STORAGE_HW_FIRMWARE_REQUEST_FLAG_SWITCH_TO_EXISTING_FIRMWARE equ 80000000h
    ; Input parameter for IOCTL_STORAGE_FIRMWARE_GET_INFO
    STORAGE_HW_FIRMWARE_INFO_QUERY struct
      Version DWORD ?
      ; sizeof(STORAGE_FIRMWARE_INFO_QUERY)
      Size_ DWORD ?
      ; Whole size of the buffer (in case this data structure being extended to be variable length)
      Flags DWORD ?
      Reserved DWORD ?
    STORAGE_HW_FIRMWARE_INFO_QUERY ends
    _STORAGE_HW_FIRMWARE_INFO_QUERY typedef STORAGE_HW_FIRMWARE_INFO_QUERY
    PSTORAGE_HW_FIRMWARE_INFO_QUERY typedef ptr STORAGE_HW_FIRMWARE_INFO_QUERY
    ; Output parameter for IOCTL_STORAGE_FIRMWARE_GET_INFO
    ; The total size of returned data is for Firmware Info is:
    ;   sizeof(STORAGE_HW_FIRMWARE_INFO) + sizeof(STORAGE_HW_FIRMWARE_SLOT_INFO) * (SlotCount - 1).
    ; If the buffer is not big enough, callee should set the required length in "Size" field of STORAGE_HW_FIRMWARE_INFO,
    ; Following value maybe used in "PendingActiveSlot" field indicating there is no firmware pending to activate.
    STORAGE_HW_FIRMWARE_INVALID_SLOT equ 0FFh
    ; bit fields other than int
    STORAGE_HW_FIRMWARE_REVISION_LENGTH equ 16
    STORAGE_HW_FIRMWARE_SLOT_INFO struct
      Version DWORD ?
      ; sizeof(STORAGE_HW_FIRMWARE_SLOT_INFO)
      Size_ DWORD ?
      ; size the data contained in STORAGE_HW_FIRMWARE_SLOT_INFO.
      SlotNumber BYTE ?
      STORAGE_HW_FIRMWARE_SLOT_INFO_REC record STORAGE_HW_FIRMWARE_SLOT_INFO_REC_Reserved0:7, STORAGE_HW_FIRMWARE_SLOT_INFO_REC_ReadOnly:1
      STORAGE_HW_FIRMWARE_SLOT_INFO_BITS STORAGE_HW_FIRMWARE_SLOT_INFO_REC <>
      Reserved1 BYTE 6 dup (?)
      Revision BYTE STORAGE_HW_FIRMWARE_REVISION_LENGTH dup (?)
    STORAGE_HW_FIRMWARE_SLOT_INFO ends
    _STORAGE_HW_FIRMWARE_SLOT_INFO typedef STORAGE_HW_FIRMWARE_SLOT_INFO
    PSTORAGE_HW_FIRMWARE_SLOT_INFO typedef ptr STORAGE_HW_FIRMWARE_SLOT_INFO
    STORAGE_HW_FIRMWARE_INFO struct
      Version DWORD ?
      ; sizeof(STORAGE_HW_FIRMWARE_INFO)
      Size_ DWORD ?
      ; size of the whole buffer including slot[]
      STORAGE_HW_FIRMWARE_INFO_REC record STORAGE_HW_FIRMWARE_INFO_REC_Reserved0:7, STORAGE_HW_FIRMWARE_INFO_REC_SupportUpgrade:1
      STORAGE_HW_FIRMWARE_INFO_BITS STORAGE_HW_FIRMWARE_INFO_REC <>
      SlotCount BYTE ?
      ActiveSlot BYTE ?
      PendingActivateSlot BYTE ?
      FirmwareShared BYTE ?
      ; The firmware applies to both device and adapter. For example: PCIe SSD.
      Reserved BYTE 3 dup (?)
      ImagePayloadAlignment DWORD ?
      ; Number of bytes. Max: PAGE_SIZE. The transfer size should be multiple of this unit size. Some protocol requires at least sector size. 0 means the value is not valid.
      ImagePayloadMaxSize DWORD ?
      ; for a single command.
      Slot STORAGE_HW_FIRMWARE_SLOT_INFO ANYSIZE_ARRAY dup (<>)
    STORAGE_HW_FIRMWARE_INFO ends
    _STORAGE_HW_FIRMWARE_INFO typedef STORAGE_HW_FIRMWARE_INFO
    PSTORAGE_HW_FIRMWARE_INFO typedef ptr STORAGE_HW_FIRMWARE_INFO
    ; Input parameter for IOCTL_STORAGE_FIRMWARE_DOWNLOAD
    STORAGE_HW_FIRMWARE_DOWNLOAD struct
      Version DWORD ?
      ; sizeof(STORAGE_HW_FIRMWARE_DOWNLOAD)
      Size_ DWORD ?
      ; size of the whole buffer include "ImageBuffer"
      Flags DWORD ?
      Slot BYTE ?
      ; Slot number that firmware image will be downloaded into.
      Reserved BYTE 3 dup (?)
      Offset_ QWORD ?
      ; Image file offset, should be aligned to "ImagePayloadAlignment" value from STORAGE_FIRMWARE_INFO.
      BufferSize QWORD ?
      ; should be multiple of "ImagePayloadAlignment" value from STORAGE_FIRMWARE_INFO.
      ImageBuffer BYTE ANYSIZE_ARRAY dup (?)
      ; firmware image file.
    STORAGE_HW_FIRMWARE_DOWNLOAD ends
    _STORAGE_HW_FIRMWARE_DOWNLOAD typedef STORAGE_HW_FIRMWARE_DOWNLOAD
    PSTORAGE_HW_FIRMWARE_DOWNLOAD typedef ptr STORAGE_HW_FIRMWARE_DOWNLOAD
    STORAGE_HW_FIRMWARE_DOWNLOAD_V2 struct
      Version DWORD ?
      ; sizeof(STORAGE_HW_FIRMWARE_DOWNLOAD_V2)
      Size_ DWORD ?
      ; size of the whole buffer include "ImageBuffer"
      Flags DWORD ?
      Slot BYTE ?
      ; Slot number that firmware image will be downloaded into.
      Reserved BYTE 3 dup (?)
      Offset_ QWORD ?
      ; Image file offset, should be aligned to "ImagePayloadAlignment" value from STORAGE_FIRMWARE_INFO.
      BufferSize QWORD ?
      ; should be multiple of "ImagePayloadAlignment" value from STORAGE_FIRMWARE_INFO.
      ImageSize DWORD ?
      ; Firmware Image size.
      Reserved2 DWORD ?
      ImageBuffer BYTE ANYSIZE_ARRAY dup (?)
      ; firmware image file.
    STORAGE_HW_FIRMWARE_DOWNLOAD_V2 ends
    _STORAGE_HW_FIRMWARE_DOWNLOAD_V2 typedef STORAGE_HW_FIRMWARE_DOWNLOAD_V2
    PSTORAGE_HW_FIRMWARE_DOWNLOAD_V2 typedef ptr STORAGE_HW_FIRMWARE_DOWNLOAD_V2
    ; Input parameter for IOCTL_STORAGE_FIRMWARE_ACTIVATE
    STORAGE_HW_FIRMWARE_ACTIVATE struct
      Version DWORD ?
      Size_ DWORD ?
      Flags DWORD ?
      Slot BYTE ?
      ; Slot with firmware image to be activated.
      Reserved0 BYTE 3 dup (?)
    STORAGE_HW_FIRMWARE_ACTIVATE ends
    _STORAGE_HW_FIRMWARE_ACTIVATE typedef STORAGE_HW_FIRMWARE_ACTIVATE
    PSTORAGE_HW_FIRMWARE_ACTIVATE typedef ptr STORAGE_HW_FIRMWARE_ACTIVATE
    ; Parameter for IOCTL_STORAGE_PROTOCOL_COMMAND
    ; Buffer layout: <STORAGE_PROTOCOL_COMMAND> <Command> [Error Info Buffer] [Data-to-Device Buffer] [Data-from-Device Buffer]
    STORAGE_PROTOCOL_STRUCTURE_VERSION equ 1h
    STORAGE_PROTOCOL_COMMAND struct
      Version DWORD ?
      ; STORAGE_PROTOCOL_STRUCTURE_VERSION
      Length_ DWORD ?
      ; sizeof(STORAGE_PROTOCOL_COMMAND)
      ProtocolType STORAGE_PROTOCOL_TYPE ?
      Flags DWORD ?
      ; Flags for the request
      ReturnStatus DWORD ?
      ; return value
      ErrorCode DWORD ?
      ; return value, optional
      CommandLength DWORD ?
      ; non-zero value should be set by caller
      ErrorInfoLength DWORD ?
      ; optional, can be zero
      DataToDeviceTransferLength DWORD ?
      ; optional, can be zero. Used by WRITE type of request.
      DataFromDeviceTransferLength DWORD ?
      ; optional, can be zero. Used by READ type of request.
      TimeOutValue DWORD ?
      ; in unit of seconds
      ErrorInfoOffset DWORD ?
      ; offsets need to be pointer aligned
      DataToDeviceBufferOffset DWORD ?
      ; offsets need to be pointer aligned
      DataFromDeviceBufferOffset DWORD ?
      ; offsets need to be pointer aligned
      CommandSpecific DWORD ?
      ; optional information passed along with Command.
      Reserved0 DWORD ?
      FixedProtocolReturnData DWORD ?
      ; return data, optional. Some protocol, such as NVMe, may return a small amount data (DWORD0 from completion queue entry) without the need of separate device data transfer.
      Reserved1 DWORD 3 dup (?)
      Command BYTE ANYSIZE_ARRAY dup (?)
    STORAGE_PROTOCOL_COMMAND ends
    _STORAGE_PROTOCOL_COMMAND typedef STORAGE_PROTOCOL_COMMAND
    PSTORAGE_PROTOCOL_COMMAND typedef ptr STORAGE_PROTOCOL_COMMAND
    ; Bit-mask values for STORAGE_PROTOCOL_COMMAND - "Flags" field.
    STORAGE_PROTOCOL_COMMAND_FLAG_ADAPTER_REQUEST equ 80000000h; Flag indicates the request targeting to adapter instead of device.

    ; Status values for STORAGE_PROTOCOL_COMMAND - "ReturnStatus" field.
    STORAGE_PROTOCOL_STATUS_PENDING equ 0h
    STORAGE_PROTOCOL_STATUS_SUCCESS equ 1h
    STORAGE_PROTOCOL_STATUS_ERROR equ 2h
    STORAGE_PROTOCOL_STATUS_INVALID_REQUEST equ 3h
    STORAGE_PROTOCOL_STATUS_NO_DEVICE equ 4h
    STORAGE_PROTOCOL_STATUS_BUSY equ 5h
    STORAGE_PROTOCOL_STATUS_DATA_OVERRUN equ 6h
    STORAGE_PROTOCOL_STATUS_INSUFFICIENT_RESOURCES equ 7h
    STORAGE_PROTOCOL_STATUS_THROTTLED_REQUEST equ 8h
    STORAGE_PROTOCOL_STATUS_NOT_SUPPORTED equ 0FFh
    ; Command Length for Storage Protocols.
    STORAGE_PROTOCOL_COMMAND_LENGTH_NVME equ 40h; NVMe commands are always 64 bytes.

    ; Command Specific Information for Storage Protocols - "CommandSpecific" field.
    STORAGE_PROTOCOL_SPECIFIC_NVME_ADMIN_COMMAND equ 01h
    STORAGE_PROTOCOL_SPECIFIC_NVME_NVM_COMMAND equ 02h
    ; Additional notes when STORAGE_PROTOCOL_TYPE is ProtocolTypeNvme:
    ;  1.  When flag STORAGE_PROTOCOL_COMMAND_FLAG_ADAPTER_REQUEST is set, or the request is sent through adapter, namespace Id from "Command" field is used;
    ;      otherwise, the underneath driver should determine namespace Id from the device that receives the command.
    ;  2.  When a command fails, the "ErrorCode" field contains value from NVMe Completion Queue Entry - DW3 - Status Field.
    ;  3.  "CommandLength" field must have value of 64. e.g. STORAGE_PROTOCOL_COMMAND_LENGTH_NVME.
    ;  4.  "CommandSpecific" field must have value of either STORAGE_PROTOCOL_SPECIFIC_NVME_ADMIN_COMMAND, or STORAGE_PROTOCOL_SPECIFIC_NVME_NVM_COMMAND.
    ;  5.  When a command succeeds, field "FixedProtocolReturnData" may contain value from NVMe Completion Queue Entry - DW0.
    ; IOCTL_STORAGE_ATTRIBUTE_MANAGEMENT
    ; This IOCTL manages an attribute
    ; for a storage device.
    ; When a driver receives this IOCTL it should first
    ; let any lower drivers process the IOCTL.
    ; The driver can override the completion status
    ; from the lower driver layers, if needed.
    ; For example when driver can provide
    ; the required functionality after
    ; doing "Action" on "Attribute", without any support
    ; from lower drivers, it can choose to ignore failure
    ; from lower driver layers, complete the "Action"
    ; and return success.
    ; Input Buffer:
    ;      STORAGE_ATTRIBUTE_MGMT
    ; Output Buffer:
    ;      None.
    ; Valid Management Actions allowed
    ; on the Attribute
    STORAGE_ATTRIBUTE_MGMT_ACTION typedef SDWORD
    StorAttributeMgmt_ClearAttribute equ 0
    StorAttributeMgmt_SetAttribute equ 1
    StorAttributeMgmt_ResetAttribute equ 2
    _STORAGE_ATTRIBUTE_MGMT_ACTION typedef STORAGE_ATTRIBUTE_MGMT_ACTION
    PSTORAGE_ATTRIBUTE_MGMT_ACTION typedef ptr STORAGE_ATTRIBUTE_MGMT_ACTION
    ; Valid Storage Device Attributes
    ; Reserved for future usage.
    STORATTRIBUTE_NONE equ 0
    ; When this attribute is reset, a driver reverts to its
    ; default state. The definition of default state is specific
    ; to each individual driver.
    ; Supported actions: Reset.
    STORATTRIBUTE_MANAGEMENT_STATE equ 1
    STORAGE_ATTRIBUTE_MGMT struct
      ; Size of this structure serves
      ; as the version.
      Version DWORD ?
      ; Size of  this structure  plus
      ; all the variable sized fields.
      Size_ DWORD ?
      ; Indicates what action is requested.
      Action STORAGE_ATTRIBUTE_MGMT_ACTION ?
      ; The attribute on which specified "Action"
      ; needs to be taken.
      Attribute DWORD ?
    STORAGE_ATTRIBUTE_MGMT ends
    _STORAGE_ATTRIBUTE_MGMT typedef STORAGE_ATTRIBUTE_MGMT
    PSTORAGE_ATTRIBUTE_MGMT typedef ptr STORAGE_ATTRIBUTE_MGMT
    if _MSC_VER ge 1200
    endif
    if Defined(__cplusplus) and  not Defined(__ALT_GENERATOR__)
      ;[...]
    endif
  endif
  ; _NTDDSTOR_H_
  ifndef _NTDDSCM_H_
    _NTDDSCM_H_ equ <>
    ; nameless struct/union
    ; bit field types other than int
    if (NTDDI_VERSION ge NTDDI_WIN10_RS5)
      ; Functions 0 to 0x2FF are reserved for the bus device.
      ; Functions 0x300 to 0x5FF are reserved for the logical persistent memory device.
      ; Functions 0x600 to 0x7FF are reserved for the physical persistent memory device.
      ; Functions 0x800 and above are reserved for non-Microsoft users.
      IOCTL_SCMBUS_BASE equ <FILE_DEVICE_PERSISTENT_MEMORY>
      IOCTL_SCMBUS_DEVICE_FUNCTION_BASE equ 0h
      IOCTL_SCM_LOGICAL_DEVICE_FUNCTION_BASE equ 300h
      IOCTL_SCM_PHYSICAL_DEVICE_FUNCTION_BASE equ 600h
      SCMBUS_FUNCTION macro x
        exitm <(IOCTL_SCMBUS_DEVICE_FUNCTION_BASE + x)>
      endm
      SCM_LOGICAL_DEVICE_FUNCTION macro x
        exitm <(IOCTL_SCM_LOGICAL_DEVICE_FUNCTION_BASE + x)>
      endm
      SCM_PHYSICAL_DEVICE_FUNCTION macro x
        exitm <(IOCTL_SCM_PHYSICAL_DEVICE_FUNCTION_BASE + x)>
      endm
      ; Persistent memory (SCM) bus device IOCTLs.
      IOCTL_SCM_BUS_GET_LOGICAL_DEVICES equ CTL_CODE(IOCTL_SCMBUS_BASE, SCMBUS_FUNCTION(00h), METHOD_BUFFERED, FILE_ANY_ACCESS)
      IOCTL_SCM_BUS_GET_PHYSICAL_DEVICES equ CTL_CODE(IOCTL_SCMBUS_BASE, SCMBUS_FUNCTION(01h), METHOD_BUFFERED, FILE_ANY_ACCESS)
      IOCTL_SCM_BUS_GET_REGIONS equ CTL_CODE(IOCTL_SCMBUS_BASE, SCMBUS_FUNCTION(02h), METHOD_BUFFERED, FILE_ANY_ACCESS)
      IOCTL_SCM_BUS_QUERY_PROPERTY equ CTL_CODE(IOCTL_SCMBUS_BASE, SCMBUS_FUNCTION(03h), METHOD_BUFFERED, FILE_ANY_ACCESS)
      IOCTL_SCM_BUS_SET_PROPERTY equ CTL_CODE(IOCTL_SCMBUS_BASE, SCMBUS_FUNCTION(05h), METHOD_BUFFERED, FILE_WRITE_ACCESS)
      ; This IOCTL does not require any input nor produce any output data.
      IOCTL_SCM_BUS_RUNTIME_FW_ACTIVATE equ CTL_CODE(IOCTL_SCMBUS_BASE, SCMBUS_FUNCTION(04h), METHOD_BUFFERED, FILE_WRITE_ACCESS)
      IOCTL_SCM_BUS_REFRESH_NAMESPACE equ CTL_CODE(IOCTL_SCMBUS_BASE, SCMBUS_FUNCTION(06h), METHOD_BUFFERED, FILE_ANY_ACCESS)
      ; Logical persistent memory device IOCTLs.
      IOCTL_SCM_LD_GET_INTERLEAVE_SET equ CTL_CODE(IOCTL_SCMBUS_BASE, SCM_LOGICAL_DEVICE_FUNCTION(00h), METHOD_BUFFERED, FILE_ANY_ACCESS)
      ; IOCTLs exposed by physical persistent memory device objects.
      IOCTL_SCM_PD_QUERY_PROPERTY equ CTL_CODE(IOCTL_SCMBUS_BASE, SCM_PHYSICAL_DEVICE_FUNCTION(00h), METHOD_BUFFERED, FILE_ANY_ACCESS)
      IOCTL_SCM_PD_FIRMWARE_DOWNLOAD equ CTL_CODE(IOCTL_SCMBUS_BASE, SCM_PHYSICAL_DEVICE_FUNCTION(01h), METHOD_BUFFERED, FILE_WRITE_ACCESS)
      IOCTL_SCM_PD_FIRMWARE_ACTIVATE equ CTL_CODE(IOCTL_SCMBUS_BASE, SCM_PHYSICAL_DEVICE_FUNCTION(02h), METHOD_BUFFERED, FILE_WRITE_ACCESS)
      IOCTL_SCM_PD_PASSTHROUGH equ CTL_CODE(IOCTL_SCMBUS_BASE, SCM_PHYSICAL_DEVICE_FUNCTION(03h), METHOD_BUFFERED, FILE_READ_ACCESS or FILE_WRITE_ACCESS)
      IOCTL_SCM_PD_UPDATE_MANAGEMENT_STATUS equ CTL_CODE(IOCTL_SCMBUS_BASE, SCM_PHYSICAL_DEVICE_FUNCTION(04h), METHOD_BUFFERED, FILE_ANY_ACCESS)
      IOCTL_SCM_PD_REINITIALIZE_MEDIA equ CTL_CODE(IOCTL_SCMBUS_BASE, SCM_PHYSICAL_DEVICE_FUNCTION(05h), METHOD_BUFFERED, FILE_WRITE_ACCESS)
      IOCTL_SCM_PD_SET_PROPERTY equ CTL_CODE(IOCTL_SCMBUS_BASE, SCM_PHYSICAL_DEVICE_FUNCTION(06h), METHOD_BUFFERED, FILE_WRITE_ACCESS)
      ; The payload for a physical device health notification.
      SCM_PD_HEALTH_NOTIFICATION_DATA struct
        ; The GUID of the device reporting the health change.
        ; This is the same GUID returned by IOCTL_SCM_PD_QUERY_PROPERTY with
        ; ScmPhysicalDeviceProperty_DeviceInfo.
        DeviceGuid GUID <>
      SCM_PD_HEALTH_NOTIFICATION_DATA ends
      _SCM_PD_HEALTH_NOTIFICATION_DATA typedef SCM_PD_HEALTH_NOTIFICATION_DATA
      PSCM_PD_HEALTH_NOTIFICATION_DATA typedef ptr SCM_PD_HEALTH_NOTIFICATION_DATA
      ; IOCTL_SCM_BUS_GET_LOGICAL_DEVICES
      ; Send this IOCTL to the ScmBus adapter to get a list of all the logical persistent memory
      ; devices on the system.
      ; Input Buffer:
      ;      None
      ; Output Buffer:
      ;      SCM_LOGICAL_DEVICES
      SCM_MAX_SYMLINK_LEN_IN_CHARS equ 256
      SCM_LOGICAL_DEVICE_INSTANCE struct
        ; Sizeof() of this structure serves as the version.
        Version DWORD ?
        ; The total size of the data structure.
        Size_ DWORD ?
        ; The logical device GUID.
        DeviceGuid GUID <>
        ; Symbolic link that can be used to get a handle to the device.
        SymbolicLink WORD SCM_MAX_SYMLINK_LEN_IN_CHARS dup (?)
      SCM_LOGICAL_DEVICE_INSTANCE ends
      _SCM_LOGICAL_DEVICE_INSTANCE typedef SCM_LOGICAL_DEVICE_INSTANCE
      PSCM_LOGICAL_DEVICE_INSTANCE typedef ptr SCM_LOGICAL_DEVICE_INSTANCE
      SCM_LOGICAL_DEVICES struct
        ; Sizeof() of this structure serves as the version.
        Version DWORD ?
        ; The total size of the data structure, including all the elements in the
        ; Devices array.
        Size_ DWORD ?
        ; The number of valid elements in the Devices array.
        DeviceCount DWORD ?
        ; Array of logical device instances.
        Devices SCM_LOGICAL_DEVICE_INSTANCE ANYSIZE_ARRAY dup (<>)
      SCM_LOGICAL_DEVICES ends
      _SCM_LOGICAL_DEVICES typedef SCM_LOGICAL_DEVICES
      PSCM_LOGICAL_DEVICES typedef ptr SCM_LOGICAL_DEVICES
      ; IOCTL_SCM_BUS_GET_PHYSICAL_DEVICES
      ; Send this IOCTL to the ScmBus adapter to get a list of all the physical persistent memory
      ; devices on the system.
      ; Input Buffer:
      ;      None
      ; Output Buffer:
      ;      SCM_PHYSICAL_DEVICES
      SCM_PHYSICAL_DEVICE_INSTANCE struct
        ; Sizeof() of this structure serves as the version.
        Version DWORD ?
        ; The total size of the data structure.
        Size_ DWORD ?
        ; The NFIT handle of the physical device.
        NfitHandle DWORD ?
        ; Symbolic link that can be used to get a handle on the device.
        SymbolicLink WORD SCM_MAX_SYMLINK_LEN_IN_CHARS dup (?)
      SCM_PHYSICAL_DEVICE_INSTANCE ends
      _SCM_PHYSICAL_DEVICE_INSTANCE typedef SCM_PHYSICAL_DEVICE_INSTANCE
      PSCM_PHYSICAL_DEVICE_INSTANCE typedef ptr SCM_PHYSICAL_DEVICE_INSTANCE
      SCM_PHYSICAL_DEVICES struct
        ; Sizeof() of this structure serves as the version.
        Version DWORD ?
        ; The total size of the data structure, including all the elements in the
        ; Devices array.
        Size_ DWORD ?
        ; The number of valid elements in the Devices array.
        DeviceCount DWORD ?
        ; Array of physical device instances.
        Devices SCM_PHYSICAL_DEVICE_INSTANCE ANYSIZE_ARRAY dup (<>)
      SCM_PHYSICAL_DEVICES ends
      _SCM_PHYSICAL_DEVICES typedef SCM_PHYSICAL_DEVICES
      PSCM_PHYSICAL_DEVICES typedef ptr SCM_PHYSICAL_DEVICES
      ; IOCTL_SCM_BUS_GET_REGIONS
      ; Send to a logical persistent memory device stack to get a list of all regions that make up
      ; the logical device.
      ; Send to a physical persistent memory device stack to get a list of all the regions that
      ; reside on that physical device.
      ; Input Buffer:
      ;      None
      ; Output Buffer:
      ;      SCM_REGIONS
      SCM_REGION_FLAG typedef SDWORD
      ScmRegionFlagNone equ 0h
      ; Indicates this region is described by a label.
      ScmRegionFlagLabel equ 1h
      _SCM_REGION_FLAG typedef SCM_REGION_FLAG
      PSCM_REGION_FLAG typedef ptr SCM_REGION_FLAG
      SCM_REGION_SPA_UNKNOWN equ <MAXDWORD64>
      SCM_REGION struct
        ; Sizeof() of this structure serves as the version.
        Version DWORD ?
        ; The total size of the data structure.
        Size_ DWORD ?
        ; Bitmask of SCM_REGION_FLAG values.
        Flags DWORD ?
        ; The NFIT handle of the physical device for this region.
        NfitHandle DWORD ?
        ; The GUID of the logical device for this region, if any.
        LogicalDeviceGuid GUID <>
        ; The address range type (e.g. byte-addressable persistent memory).
        AddressRangeType GUID <>
        ; Regions that are associated with each other (e.g. part of an interleave
        ; set) will share an associated ID.
        AssociatedId DWORD ?
        ; The total size of the region, in bytes.
        Length_ QWORD ?
        ; The starting device physical address of the region
        ; within the physical device.
        StartingDPA QWORD ?
        ; The base system physical address.
        BaseSPA QWORD ?
        ; The region's offset from the base system physical address.
        ; This field may be SCM_REGION_SPA_UNKNOWN if there is not enough
        ; context to calculate the SPA offset for this particular region.
        SPAOffset QWORD ?
        ; The value of the Region Offset field from the associated Region Mapping
        ; Structure.
        RegionOffset QWORD ?
      SCM_REGION ends
      _SCM_REGION typedef SCM_REGION
      PSCM_REGION typedef ptr SCM_REGION
      SCM_REGIONS struct
        ; Sizeof() of this structure serves as the version.
        Version DWORD ?
        ; The total size of the data structure, including all the elements in the
        ; Regions array.
        Size_ DWORD ?
        ; The number of valid elements in the Regions array.
        RegionCount DWORD ?
        ; Array of regions for the logical or physical device.
        Regions SCM_REGION ANYSIZE_ARRAY dup (<>)
      SCM_REGIONS ends
      _SCM_REGIONS typedef SCM_REGIONS
      PSCM_REGIONS typedef ptr SCM_REGIONS
      ; IOCTL_SCM_BUS_QUERY_PROPERTY
      ; Input Buffer:
      ;      An SCM_BUS_PROPERTY_QUERY structure that describes the type of query
      ;      being done, the property being queried, and any additional parameters
      ;      the query requires.
      ;  Output Buffer:
      ;      Contains a buffer to place the results of the query into. Since all
      ;      property descriptors can be cast into an SCM_BUS_DESCRIPTOR_HEADER,
      ;      the IOCTL can be called once with a small buffer then again using
      ;      a buffer as large as the header reports is necessary.
      ; Types of queries
      SCM_BUS_QUERY_TYPE typedef SDWORD
      ScmBusQuery_Descriptor equ 0
      ; Retrieves the descriptor
      ScmBusQuery_IsSupported equ 1
      ; Used to test whether the descriptor is supported
      ScmBusQuery_Max equ 2
      _SCM_BUS_QUERY_TYPE typedef SCM_BUS_QUERY_TYPE
      PSCM_BUS_QUERY_TYPE typedef ptr SCM_BUS_QUERY_TYPE
      ; IOCTL_SCM_BUS_SET_PROPERTY
      ; Input Buffer:
      ;      An SCM_BUS_PROPERTY_SET structure that describes the type of set
      ;      being done, the property being set, and any additional parameters
      ;      the set requires.
      ;  Output Buffer:
      ;      Contains a buffer to place the results of the set into. Since all
      ;      property descriptors can be cast into an SCM_BUS_DESCRIPTOR_HEADER,
      ;      the IOCTL can be called once with a small buffer then again using
      ;      a buffer as large as the header reports is necessary.
      ; Types of sets
      SCM_BUS_SET_TYPE typedef SDWORD
      ScmBusSet_Descriptor equ 0
      ; Retrieves the descriptor
      ScmBusSet_IsSupported equ 1
      ; Used to test whether the descriptor is supported
      ScmBusSet_Max equ 2
      _SCM_BUS_SET_TYPE typedef SCM_BUS_SET_TYPE
      PSCM_BUS_SET_TYPE typedef ptr SCM_BUS_SET_TYPE
      SCM_BUS_PROPERTY_ID typedef SDWORD
      ; Runtime Firmware Activation Information.
      ScmBusProperty_RuntimeFwActivationInfo equ 0
      ; Dedicated Memory Information.
      ScmBusProperty_DedicatedMemoryInfo equ 1
      ; Activate/Deactivate the Dedicated Memory.
      ScmBusProperty_DedicatedMemoryState equ 2
      ScmBusProperty_Max equ 3
      _SCM_BUS_PROPERTY_ID typedef SCM_BUS_PROPERTY_ID
      PSCM_BUS_PROPERTY_ID typedef ptr SCM_BUS_PROPERTY_ID
      ; Query structure - additional parameters for specific queries can follow
      ; the header
      SCM_BUS_PROPERTY_QUERY struct
        ; Sizeof() of this structure serves as the version.
        Version DWORD ?
        ; The size of this structure, including any additional
        ; parameters.
        Size_ DWORD ?
        ; ID of the property being retrieved.
        PropertyId SCM_BUS_PROPERTY_ID ?
        ; The type of query being performed.
        QueryType SCM_BUS_QUERY_TYPE ?
        ; Space for additional parameters if necessary.
        AdditionalParameters BYTE ANYSIZE_ARRAY dup (?)
      SCM_BUS_PROPERTY_QUERY ends
      _SCM_BUS_PROPERTY_QUERY typedef SCM_BUS_PROPERTY_QUERY
      PSCM_BUS_PROPERTY_QUERY typedef ptr SCM_BUS_PROPERTY_QUERY
      ; Output buffer for ScmBusProperty_RuntimeFwActivationInfo
      ; ScmBus Firmware Activation State
      SCM_BUS_FIRMWARE_ACTIVATION_STATE typedef SDWORD
      ScmBusFirmwareActivationState_Idle equ 0
      ; NVDIMM is Idle for firmware update
      ScmBusFirmwareActivationState_Armed equ 1
      ; NVDIMM is armed to activate the staging firmware
      ScmBusFirmwareActivationState_Busy equ 2
      _SCM_BUS_FIRMWARE_ACTIVATION_STATE typedef SCM_BUS_FIRMWARE_ACTIVATION_STATE
      PSCM_BUS_FIRMWARE_ACTIVATION_STATE typedef ptr SCM_BUS_FIRMWARE_ACTIVATION_STATE
      ; NVDIMM firmware activation is underway
      SCM_BUS_RUNTIME_FW_ACTIVATION_INFO struct
        ; Sizeof() of this structure serves as the version.
        Version DWORD ?
        ; Size of the data contained in this structure. If the output buffer is too small
        ; to contain the requested information, the Size field indicates the length of the
        ; output buffer the caller should provide in order to retrieve all the data.
        Size_ DWORD ?
        ; Indicates if runtime firmware activation is supported or not.
        RuntimeFwActivationSupported BYTE ?
        ; Indicates the current Firmware activation state of the DIMMs.
        ; Note: If any one of the NVDIMMs is Armed, the state is Armed.
        FirmwareActivationState SCM_BUS_FIRMWARE_ACTIVATION_STATE ?
        ; Firmware activation capabilities.
        struct FirmwareActivationCapability
          ; Live activation supported with platform firmware managed processor and I/O quiesce.
          ; Live activation supported with OS managed I/O quiesce (device idle) and platform managed processor quiesce.
          ; Warm reset-based activation supported.
          FirmwareActivationCapability_REC record FirmwareActivationCapability_REC_Reserved:29, FirmwareActivationCapability_REC_WarmResetBasedFwActivationSupported:1, FirmwareActivationCapability_REC_OsManagedIoQuiesceFwActivationSupported:1, FirmwareActivationCapability_REC_FwManagedIoQuiesceFwActivationSupported:1
          FirmwareActivationCapability_BITS FirmwareActivationCapability_REC <>
        ends
        ; Estimated firmware activation time in micro seconds.
        EstimatedFirmwareActivationTimeInUSecs QWORD ?
        ; Estimated processor quiesce time during firmware activation in micro seconds.
        ; 0 - no processor quiesce required.
        EstimatedProcessorAccessQuiesceTimeInUSecs QWORD ?
        ; Estimated I/O access to host memory quiesce time during firmware activation in micro seconds.
        ; 0 - no I/O quiesce required.
        EstimatedIOAccessQuiesceTimeInUSecs QWORD ?
        ; Platform firmware supported Max I/O access to memory quiesce time during firmware activation in micro seconds.
        ; 0 - Informaiton not available.
        PlatformSupportedMaxIOAccessQuiesceTimeInUSecs QWORD ?
      SCM_BUS_RUNTIME_FW_ACTIVATION_INFO ends
      _SCM_BUS_RUNTIME_FW_ACTIVATION_INFO typedef SCM_BUS_RUNTIME_FW_ACTIVATION_INFO
      PSCM_BUS_RUNTIME_FW_ACTIVATION_INFO typedef ptr SCM_BUS_RUNTIME_FW_ACTIVATION_INFO
      ; Output buffer for ScmBusProperty_DedicatedMemoryInfo
      SCM_BUS_DEDICATED_MEMORY_DEVICE_INFO struct
        ; The dedicated memory device GUID.
        DeviceGuid GUID <>
        ; The dedicated memory device number.
        DeviceNumber DWORD ?
        struct Flags
          ; Indicates if the dedicated memory is created by registry settings.
          ; Indicates if the dedicated memory is initialized.
          Flags_REC record Flags_REC_Reserved:30, Flags_REC_Initialized:1, Flags_REC_ForcedByRegistry:1
          Flags_BITS Flags_REC <>
        ends
        ; The dedicated memory device size in bytes.
        DeviceSize QWORD ?
      SCM_BUS_DEDICATED_MEMORY_DEVICE_INFO ends
      _SCM_BUS_DEDICATED_MEMORY_DEVICE_INFO typedef SCM_BUS_DEDICATED_MEMORY_DEVICE_INFO
      PSCM_BUS_DEDICATED_MEMORY_DEVICE_INFO typedef ptr SCM_BUS_DEDICATED_MEMORY_DEVICE_INFO
      SCM_BUS_DEDICATED_MEMORY_DEVICES_INFO struct
        ; Sizeof() of this structure serves as the version.
        Version DWORD ?
        ; The total size of the data structure, including all the elements in the
        ; Devices array.
        Size_ DWORD ?
        ; The number of valid elements in the Devices array.
        DeviceCount DWORD ?
        ; Array of dedicated memory devices info.
        Devices SCM_BUS_DEDICATED_MEMORY_DEVICE_INFO ANYSIZE_ARRAY dup (<>)
      SCM_BUS_DEDICATED_MEMORY_DEVICES_INFO ends
      _SCM_BUS_DEDICATED_MEMORY_DEVICES_INFO typedef SCM_BUS_DEDICATED_MEMORY_DEVICES_INFO
      PSCM_BUS_DEDICATED_MEMORY_DEVICES_INFO typedef ptr SCM_BUS_DEDICATED_MEMORY_DEVICES_INFO
      ; Set structure - additional parameters for specific sets can follow
      ; the header
      SCM_BUS_PROPERTY_SET struct
        ; Sizeof() of this structure serves as the version.
        Version DWORD ?
        ; The size of this structure, including any additional
        ; parameters.
        Size_ DWORD ?
        ; ID of the property being set.
        PropertyId SCM_BUS_PROPERTY_ID ?
        ; The type of set being performed.
        SetType SCM_BUS_SET_TYPE ?
        ; Space for additional parameters if necessary.
        AdditionalParameters BYTE ANYSIZE_ARRAY dup (?)
      SCM_BUS_PROPERTY_SET ends
      _SCM_BUS_PROPERTY_SET typedef SCM_BUS_PROPERTY_SET
      PSCM_BUS_PROPERTY_SET typedef ptr SCM_BUS_PROPERTY_SET
      ; Input AdditionalParameters for ScmBusProperty_DedicatedMemoryState
      SCM_BUS_DEDICATED_MEMORY_STATE struct
        ; Dedicated Memory state (Deactivate - FALSE, Activate - TRUE).
        ActivateState BYTE ?
      SCM_BUS_DEDICATED_MEMORY_STATE ends
      _SCM_BUS_DEDICATED_MEMORY_STATE typedef SCM_BUS_DEDICATED_MEMORY_STATE
      PSCM_BUS_DEDICATED_MEMORY_STATE typedef ptr SCM_BUS_DEDICATED_MEMORY_STATE
      ; Definitions for interfaces related to logical persistent memory devices (LDs).
      ; IOCTL_SCM_LD_GET_INTERLEAVE_SET
      ; This IOCTL retrieves the interleave set of a logical persistent memory disk. The interleave set
      ; is comprised of one or more physical persistent memory devices.
      ; Input Buffer:
      ;      None.
      ; Output Buffer:
      ;      SCM_LD_INTERLEAVE_SET_INFO
      SCM_INTERLEAVED_PD_INFO struct
        ; An identifier for the physical device that comes from the NFIT table and
        ; is unique on the local system.
        DeviceHandle DWORD ?
        ; A GUID that uniquely identifies the physical device on the system.
        DeviceGuid GUID <>
      SCM_INTERLEAVED_PD_INFO ends
      _SCM_INTERLEAVED_PD_INFO typedef SCM_INTERLEAVED_PD_INFO
      PSCM_INTERLEAVED_PD_INFO typedef ptr SCM_INTERLEAVED_PD_INFO
      SCM_LD_INTERLEAVE_SET_INFO struct
        ; Sizeof() of this structure serves as the version.
        Version DWORD ?
        ; Total size of the structure, in bytes, including the InterleaveSet array.
        ; If the output buffer is too small to contain the requested information,
        ; the Size field indicates the length of the output buffer the caller should provide
        ; in order to retrieve all the data.
        Size_ DWORD ?
        ; The number of elements in the InterleaveSet array.
        InterleaveSetSize DWORD ?
        ; Information about the physical devices that make up this interleave
        ; set.
        InterleaveSet SCM_INTERLEAVED_PD_INFO ANYSIZE_ARRAY dup (<>)
      SCM_LD_INTERLEAVE_SET_INFO ends
      _SCM_LD_INTERLEAVE_SET_INFO typedef SCM_LD_INTERLEAVE_SET_INFO
      PSCM_LD_INTERLEAVE_SET_INFO typedef ptr SCM_LD_INTERLEAVE_SET_INFO
      ; Definitions for interfaces related to physical persistent memory devices (PDs).
      ; IOCTL_SCM_PD_QUERY_PROPERTY
      ; Input Buffer:
      ;      An SCM_PD_PROPERTY_QUERY structure that describes the type of query
      ;      being done, the property being queried, and any additional parameters
      ;      the query requires.
      ;  Output Buffer:
      ;      Contains a buffer to place the results of the query into. Since all
      ;      property descriptors can be cast into an SCM_PD_DESCRIPTOR_HEADER,
      ;      the IOCTL can be called once with a small buffer then again using
      ;      a buffer as large as the header reports is necessary.
      ; Types of queries
      SCM_PD_QUERY_TYPE typedef SDWORD
      ScmPhysicalDeviceQuery_Descriptor equ 0
      ; Retrieves the descriptor
      ScmPhysicalDeviceQuery_IsSupported equ 1
      ; Used to test whether the descriptor is supported
      ScmPhysicalDeviceQuery_Max equ 2
      _SCM_PD_QUERY_TYPE typedef SCM_PD_QUERY_TYPE
      PSCM_PD_QUERY_TYPE typedef ptr SCM_PD_QUERY_TYPE
      ; IOCTL_SCM_PD_SET_PROPERTY
      ; Input Buffer:
      ;      An SCM_PD_PROPERTY_SET structure that describes the type of set
      ;      being done, the property being set, and any additional parameters
      ;      the set requires.
      ;  Output Buffer:
      ;      Contains a buffer to place the results of the set into. Since all
      ;      property descriptors can be cast into an SCM_PD_DESCRIPTOR_HEADER,
      ;      the IOCTL can be called once with a small buffer then again using
      ;      a buffer as large as the header reports is necessary.
      ; Types of sets
      SCM_PD_SET_TYPE typedef SDWORD
      ScmPhysicalDeviceSet_Descriptor equ 0
      ; Retrieves the descriptor
      ScmPhysicalDeviceSet_IsSupported equ 1
      ; Used to test whether the descriptor is supported
      ScmPhysicalDeviceSet_Max equ 2
      _SCM_PD_SET_TYPE typedef SCM_PD_SET_TYPE
      PSCM_PD_SET_TYPE typedef ptr SCM_PD_SET_TYPE
      SCM_PD_PROPERTY_ID typedef SDWORD
      ; General information about the device.
      ScmPhysicalDeviceProperty_DeviceInfo equ 0
      ; Information about the device's health.
      ScmPhysicalDeviceProperty_ManagementStatus equ 1
      ; Firmware-related information.
      ScmPhysicalDeviceProperty_FirmwareInfo equ 2
      ; Returns a string that identifies where the device is located
      ; on the local system.
      ScmPhysicalDeviceProperty_LocationString equ 3
      ; Returns a series of device-specific information, which give more detail
      ; on the device's status.
      ScmPhysicalDeviceProperty_DeviceSpecificInfo equ 4
      ; Returns a identifying handle of the physical device, which comes from
      ; the NFIT table.
      ScmPhysicalDeviceProperty_DeviceHandle equ 5
      ; Returns a string that identifies the replacement unit housing
      ; the device on the local system.
      ScmPhysicalDeviceProperty_FruIdString equ 6
      ; Returns runtime firmware activation information.
      ScmPhysicalDeviceProperty_RuntimeFwActivationInfo equ 7
      ; Runtime firmware activation arm state.
      ScmPhysicalDeviceProperty_RuntimeFwActivationArmState equ 8
      ScmPhysicalDeviceProperty_Max equ 9
      _SCM_PD_PROPERTY_ID typedef SCM_PD_PROPERTY_ID
      PSCM_PD_PROPERTY_ID typedef ptr SCM_PD_PROPERTY_ID
      ; Query structure - additional parameters for specific queries can follow
      ; the header
      SCM_PD_PROPERTY_QUERY struct
        ; Sizeof() of this structure serves as the version.
        Version DWORD ?
        ; The size of this structure, including any additional
        ; parameters.
        Size_ DWORD ?
        ; ID of the property being retrieved.
        PropertyId SCM_PD_PROPERTY_ID ?
        ; The type of query being performed.
        QueryType SCM_PD_QUERY_TYPE ?
        ; Space for additional parameters if necessary.
        AdditionalParameters BYTE ANYSIZE_ARRAY dup (?)
      SCM_PD_PROPERTY_QUERY ends
      _SCM_PD_PROPERTY_QUERY typedef SCM_PD_PROPERTY_QUERY
      PSCM_PD_PROPERTY_QUERY typedef ptr SCM_PD_PROPERTY_QUERY
      ; Set structure - additional parameters for specific sets can follow
      ; the header
      SCM_PD_PROPERTY_SET struct
        ; Sizeof() of this structure serves as the version.
        Version DWORD ?
        ; The size of this structure, including any additional
        ; parameters.
        Size_ DWORD ?
        ; ID of the property being retrieved.
        PropertyId SCM_PD_PROPERTY_ID ?
        ; The type of set being performed.
        SetType SCM_PD_SET_TYPE ?
        ; Space for additional parameters if necessary.
        AdditionalParameters BYTE ANYSIZE_ARRAY dup (?)
      SCM_PD_PROPERTY_SET ends
      _SCM_PD_PROPERTY_SET typedef SCM_PD_PROPERTY_SET
      PSCM_PD_PROPERTY_SET typedef ptr SCM_PD_PROPERTY_SET
      ; Input AdditionalParameters for ScmPhysicalDeviceProperty_RuntimeFwActivationArmState
      SCM_PD_RUNTIME_FW_ACTIVATION_ARM_STATE struct
        ; Runtime firmware activation arm state (Disarm - FALSE, Arm - TRUE).
        ArmState BYTE ?
      SCM_PD_RUNTIME_FW_ACTIVATION_ARM_STATE ends
      _SCM_PD_RUNTIME_FW_ACTIVATION_ARM_STATE typedef SCM_PD_RUNTIME_FW_ACTIVATION_ARM_STATE
      PSCM_PD_RUNTIME_FW_ACTIVATION_ARM_STATE typedef ptr SCM_PD_RUNTIME_FW_ACTIVATION_ARM_STATE
      ; Standard property descriptor header. All property pages should use this
      ; as their first element or should contain these two elements
      SCM_PD_DESCRIPTOR_HEADER struct
        ; The sizeof() of the entire descriptor (not just the header).
        Version DWORD ?
        ; The size of the entire descriptor (not just the header).
        Size_ DWORD ?
      SCM_PD_DESCRIPTOR_HEADER ends
      _SCM_PD_DESCRIPTOR_HEADER typedef SCM_PD_DESCRIPTOR_HEADER
      PSCM_PD_DESCRIPTOR_HEADER typedef ptr SCM_PD_DESCRIPTOR_HEADER
      ; Output buffer for ScmPhysicalDeviceProperty_DeviceHandle & ScmPhysicalDeviceQuery_Descriptor
      ; The ScmPhysicalDeviceProperty_DeviceHandle property gets identifying information about
      ; a physical device.
      SCM_PD_DEVICE_HANDLE struct
        ; Sizeof() of this structure serves as the version.
        Version DWORD ?
        ; The total size of the structure.
        Size_ DWORD ?
        ; A GUID that uniquely identifies the physical device, based on hardware information.
        DeviceGuid GUID <>
        ; A handle, exposed in the NFIT table, that uniquely identifies the physical device on a local
        ; system.
        DeviceHandle DWORD ?
      SCM_PD_DEVICE_HANDLE ends
      _SCM_PD_DEVICE_HANDLE typedef SCM_PD_DEVICE_HANDLE
      PSCM_PD_DEVICE_HANDLE typedef ptr SCM_PD_DEVICE_HANDLE
      ; Output buffer for ScmPhysicalDeviceProperty_DeviceInfo & ScmPhysicalDeviceQuery_Descriptor
      MAX_INTERFACE_CODES equ 8
      SCM_PD_FIRMWARE_REVISION_LENGTH_BYTES equ 32
      SCM_PD_MEMORY_SIZE_UNKNOWN equ <MAXDWORD64>
      SCM_PD_DEVICE_INFO struct
        ; Sizeof() of this structure serves as the version.
        Version DWORD ?
        ; The total size of the structure, including the serial number at the end.
        ; If the output buffer is too small to contain the requested information,
        ; the Size field indicates the length of the output buffer the caller should provide
        ; in order to retrieve all the data.
        Size_ DWORD ?
        ; A GUID that uniquely identifies the physical device, based on hardware information.
        DeviceGuid GUID <>
        ; The number of times this device went through an unsafe shutdown (i.e. a shutdown
        ; that might have led to data loss).
        UnsafeShutdownCount DWORD ?
        ; The combined size of all the persistent memory regions of the physical device.
        PersistentMemorySizeInBytes QWORD ?
        ; The total size of the volatile memory this device contains, if any.
        ; May be SCM_PD_MEMORY_SIZE_UNKNOWN if it is not reported by the platform.
        VolatileMemorySizeInBytes QWORD ?
        ; The total capacity of this memory device, including persistent and any
        ; volatile memory.
        ; May be SCM_PD_MEMORY_SIZE_UNKNOWN if it is not reported by the platform.
        TotalMemorySizeInBytes QWORD ?
        ; The number of the slot in which the physical device is installed on the system.
        SlotNumber DWORD ?
        ; A handle, exposed in the NFIT table, that uniquely identifies the physical device on a local
        ; system.
        DeviceHandle DWORD ?
        ; The unique ID for this physical device as indicated in the SMBIOS.
        PhysicalId WORD ?
        ; An physical device can have regions that implement different format interface
        ; codes. This is a list of all format interface codes on this physical device.
        NumberOfFormatInterfaceCodes BYTE ?
        FormatInterfaceCodes WORD MAX_INTERFACE_CODES dup (?)
        ; Vendor and product IDs.
        VendorId DWORD ?
        ProductId DWORD ?
        SubsystemDeviceId DWORD ?
        SubsystemVendorId DWORD ?
        ManufacturingLocation BYTE ?
        ManufacturingWeek BYTE ?
        ; *Not* in BCD format.
        ManufacturingYear BYTE ?
        ; *Not* in BCD format.
        SerialNumber4Byte DWORD ?
        ; 4-byte serial number as defined in the JEDEC SPD spec and reported in the NFIT.
        ; The physical device's serial number, as a string.
        SerialNumberLengthInChars DWORD ?
        SerialNumber SBYTE ANYSIZE_ARRAY dup (?)
      SCM_PD_DEVICE_INFO ends
      _SCM_PD_DEVICE_INFO typedef SCM_PD_DEVICE_INFO
      PSCM_PD_DEVICE_INFO typedef ptr SCM_PD_DEVICE_INFO
      ; Output buffer for ScmPhysicalDeviceProperty_DeviceSpecificInfo & ScmPhysicalDeviceQuery_Descriptor
      ; A device specific property is a key-value pair where the key is a string
      ; and the value is a number.
      SCM_PD_PROPERTY_NAME_LENGTH_IN_CHARS equ 128
      SCM_PD_DEVICE_SPECIFIC_PROPERTY struct
        ; NULL-terminated string.
        Name_ WORD SCM_PD_PROPERTY_NAME_LENGTH_IN_CHARS dup (?)
        Value SQWORD ?
      SCM_PD_DEVICE_SPECIFIC_PROPERTY ends
      _SCM_PD_DEVICE_SPECIFIC_PROPERTY typedef SCM_PD_DEVICE_SPECIFIC_PROPERTY
      PSCM_PD_DEVICE_SPECIFIC_PROPERTY typedef ptr SCM_PD_DEVICE_SPECIFIC_PROPERTY
      ; The physical device driver fills in this structure with arbitrary numeric information.
      SCM_PD_DEVICE_SPECIFIC_INFO struct
        ; Sizeof() of this structure serves as the version.
        Version DWORD ?
        ; The total size of the structure, including the DeviceSpecificProperties array.
        ; If the output buffer is too small to contain the requested information,
        ; the Size field indicates the length of the output buffer the caller should provide
        ; in order to retrieve all the data.
        Size_ DWORD ?
        ; The number of elements in the DeviceSpecificProperties array.
        NumberOfProperties DWORD ?
        ; A series of device-specific properties filled in by the driver.
        DeviceSpecificProperties SCM_PD_DEVICE_SPECIFIC_PROPERTY ANYSIZE_ARRAY dup (<>)
      SCM_PD_DEVICE_SPECIFIC_INFO ends
      _SCM_PD_DEVICE_SPECIFIC_INFO typedef SCM_PD_DEVICE_SPECIFIC_INFO
      PSCM_PD_DEVICE_SPECIFIC_INFO typedef ptr SCM_PD_DEVICE_SPECIFIC_INFO
      SCM_PD_FIRMWARE_SLOT_INFO struct
        ; Sizeof() of this structure serves as the version.
        Version DWORD ?
        ; Size of the data contained in this structure.
        Size_ DWORD ?
        SlotNumber BYTE ?
        SCM_PD_FIRMWARE_SLOT_INFO_REC record SCM_PD_FIRMWARE_SLOT_INFO_REC_Reserved0:7, SCM_PD_FIRMWARE_SLOT_INFO_REC_ReadOnly:1
        SCM_PD_FIRMWARE_SLOT_INFO_BITS SCM_PD_FIRMWARE_SLOT_INFO_REC <>
        Reserved1 BYTE 6 dup (?)
        Revision BYTE SCM_PD_FIRMWARE_REVISION_LENGTH_BYTES dup (?)
      SCM_PD_FIRMWARE_SLOT_INFO ends
      _SCM_PD_FIRMWARE_SLOT_INFO typedef SCM_PD_FIRMWARE_SLOT_INFO
      PSCM_PD_FIRMWARE_SLOT_INFO typedef ptr SCM_PD_FIRMWARE_SLOT_INFO
      ; Output buffer for ScmPhysicalDeviceQuery_Descriptor & ScmPhysicalDeviceProperty_FirmwareInfo
      SCM_PD_FIRMWARE_INFO struct
        ; Sizeof() of this structure serves as the version.
        Version DWORD ?
        ; Size of the data contained in this structure, including the Slots
        ; array. If the output buffer is too small to contain the requested information,
        ; the Size field indicates the length of the output buffer the caller should provide
        ; in order to retrieve all the data.
        Size_ DWORD ?
        ; The firmware slot that is currently active.
        ; 
        ActiveSlot BYTE ?
        ; The slot that will become active once the device is reset. A value of 0xFF means
        ; there is no slot waiting to be activated.
        NextActiveSlot BYTE ?
        SlotCount BYTE ?
        Slots SCM_PD_FIRMWARE_SLOT_INFO ANYSIZE_ARRAY dup (<>)
      SCM_PD_FIRMWARE_INFO ends
      _SCM_PD_FIRMWARE_INFO typedef SCM_PD_FIRMWARE_INFO
      PSCM_PD_FIRMWARE_INFO typedef ptr SCM_PD_FIRMWARE_INFO
      ; Constants for ScmPhysicalDeviceProperty_ManagementStatus, which can be queried via
      ; ScmPhysicalDeviceQuery_Descriptor.
      ; Health states.
      SCM_PD_HEALTH_STATUS typedef SDWORD
      ScmPhysicalDeviceHealth_Unknown equ 0
      ScmPhysicalDeviceHealth_Unhealthy equ 1
      ScmPhysicalDeviceHealth_Warning equ 2
      ScmPhysicalDeviceHealth_Healthy equ 3
      ScmPhysicalDeviceHealth_Max equ 4
      _SCM_PD_HEALTH_STATUS typedef SCM_PD_HEALTH_STATUS
      PSCM_PD_HEALTH_STATUS typedef ptr SCM_PD_HEALTH_STATUS
      ; Operational states.
      SCM_PD_OPERATIONAL_STATUS typedef SDWORD
      ScmPhysicalDeviceOpStatus_Unknown equ 0
      ScmPhysicalDeviceOpStatus_Ok equ 1
      ScmPhysicalDeviceOpStatus_PredictingFailure equ 2
      ScmPhysicalDeviceOpStatus_InService equ 3
      ScmPhysicalDeviceOpStatus_HardwareError equ 4
      ScmPhysicalDeviceOpStatus_NotUsable equ 5
      ScmPhysicalDeviceOpStatus_TransientError equ 6
      ScmPhysicalDeviceOpStatus_Missing equ 7
      ScmPhysicalDeviceOpStatus_Max equ 8
      _SCM_PD_OPERATIONAL_STATUS typedef SCM_PD_OPERATIONAL_STATUS
      PSCM_PD_OPERATIONAL_STATUS typedef ptr SCM_PD_OPERATIONAL_STATUS
      ; Operational reasons.
      SCM_PD_OPERATIONAL_STATUS_REASON typedef SDWORD
      ScmPhysicalDeviceOpReason_Unknown equ 0
      ScmPhysicalDeviceOpReason_Media equ 1
      ScmPhysicalDeviceOpReason_ThresholdExceeded equ 2
      ScmPhysicalDeviceOpReason_LostData equ 3
      ScmPhysicalDeviceOpReason_EnergySource equ 4
      ScmPhysicalDeviceOpReason_Configuration equ 5
      ScmPhysicalDeviceOpReason_DeviceController equ 6
      ScmPhysicalDeviceOpReason_MediaController equ 7
      ScmPhysicalDeviceOpReason_Component equ 8
      ScmPhysicalDeviceOpReason_BackgroundOperation equ 9
      ScmPhysicalDeviceOpReason_InvalidFirmware equ 10
      ScmPhysicalDeviceOpReason_HealthCheck equ 11
      ScmPhysicalDeviceOpReason_LostDataPersistence equ 12
      ScmPhysicalDeviceOpReason_DisabledByPlatform equ 13
      ScmPhysicalDeviceOpReason_PermanentError equ 14
      ScmPhysicalDeviceOpReason_LostWritePersistence equ 15
      ScmPhysicalDeviceOpReason_FatalError equ 16
      ScmPhysicalDeviceOpReason_DataPersistenceLossImminent equ 17
      ScmPhysicalDeviceOpReason_WritePersistenceLossImminent equ 18
      ScmPhysicalDeviceOpReason_MediaRemainingSpareBlock equ 19
      ScmPhysicalDeviceOpReason_PerformanceDegradation equ 20
      ScmPhysicalDeviceOpReason_ExcessiveTemperature equ 21
      ScmPhysicalDeviceOpReason_InternalFailure equ 22
      ScmPhysicalDeviceOpReason_Max equ 23
      _SCM_PD_OPERATIONAL_STATUS_REASON typedef SCM_PD_OPERATIONAL_STATUS_REASON
      PSCM_PD_OPERATIONAL_STATUS_REASON typedef ptr SCM_PD_OPERATIONAL_STATUS_REASON
      ; Output buffer for ScmPhysicalDeviceProperty_ManagementStatus & ScmPhysicalDeviceQuery_Descriptor
      SCM_PD_MAX_OPERATIONAL_STATUS equ 16
      SCM_PD_MANAGEMENT_STATUS struct
        ; Sizeof() of this structure serves as the version.
        Version DWORD ?
        ; The total size of the structure, including operational status reasons
        ; that didn't fit in the caller's array. If the output buffer is too small to
        ; contain the requested information, the Size field indicates the length of the
        ; output buffer the caller should provide in order to retrieve all the data.
        Size_ DWORD ?
        ; Health status.
        Health SCM_PD_HEALTH_STATUS ?
        ; The number of operational statuses returned.
        NumberOfOperationalStatus DWORD ?
        ; The number of additional reasons returned.
        NumberOfAdditionalReasons DWORD ?
        ; Operational statuses. The primary operational status is the first element
        ; in the array. There are NumberOfOperationalStatus valid elements in the array.
        OperationalStatus SCM_PD_OPERATIONAL_STATUS SCM_PD_MAX_OPERATIONAL_STATUS dup (?)
        ; Additional reasons. There are NumberOfAdditionalReasons valid elements in the array.
        AdditionalReasons SCM_PD_OPERATIONAL_STATUS_REASON ANYSIZE_ARRAY dup (?)
      SCM_PD_MANAGEMENT_STATUS ends
      _SCM_PD_MANAGEMENT_STATUS typedef SCM_PD_MANAGEMENT_STATUS
      PSCM_PD_MANAGEMENT_STATUS typedef ptr SCM_PD_MANAGEMENT_STATUS
      ; Output buffer for ScmPhysicalDeviceQuery_Descriptor & ScmPhysicalDeviceProperty_LocationString
      SCM_PD_LOCATION_STRING struct
        ; Sizeof() of this structure serves as the version.
        Version DWORD ?
        ; The total size of the structure, including the buffer for the Unicode
        ; string. If the output buffer is too small to contain the requested information,
        ; the Size field indicates the length of the output buffer the caller should provide
        ; in order to retrieve all the data.
        Size_ DWORD ?
        ; The Unicode string that represents the physical location of this physical device.
        Location WORD ANYSIZE_ARRAY dup (?)
      SCM_PD_LOCATION_STRING ends
      _SCM_PD_LOCATION_STRING typedef SCM_PD_LOCATION_STRING
      PSCM_PD_LOCATION_STRING typedef ptr SCM_PD_LOCATION_STRING
      ; Output buffer for ScmPhysicalDeviceQuery_Descriptor & ScmPhysicalDeviceProperty_FruIdString
      SCM_PD_FRU_ID_STRING struct
        ; Sizeof() of this structure serves as the version.
        Version DWORD ?
        ; The total size of the structure, including the buffer for the fru id string.
        ; If the output buffer is too small to contain the requested information,
        ; the Size field indicates the length of the output buffer the caller should provide
        ; in order to retrieve all the data.
        Size_ DWORD ?
        ; The string that represents the fru id of this physical device.
        IdentifierSize DWORD ?
        Identifier BYTE ANYSIZE_ARRAY dup (?)
      SCM_PD_FRU_ID_STRING ends
      _SCM_PD_FRU_ID_STRING typedef SCM_PD_FRU_ID_STRING
      PSCM_PD_FRU_ID_STRING typedef ptr SCM_PD_FRU_ID_STRING
      ; Firmware update IOCTLs.
      ; Signals that the firmware image regions contained in the SCM_PD_FIRMWARE_DOWNLOAD
      ; structure are the last ones of the image. The physical device driver finishes the firmware update
      ; operation when this flag is set.
      SCM_PD_FIRMWARE_LAST_DOWNLOAD equ 1h
      ; Input buffer for IOCTL_SCM_PD_FIRMWARE_DOWNLOAD.
      SCM_PD_FIRMWARE_DOWNLOAD struct
        ; Sizeof() of this structure serves as the version.
        Version DWORD ?
        ; The structure size, including the image.
        Size_ DWORD ?
        ; Additional information about the region being download, such as whether it
        ; is the last region in the image.
        Flags DWORD ?
        ; The firmware slot being upgraded.
        Slot BYTE ?
        Reserved BYTE 3 dup (?)
        ; The offset of this region of the firmware image.
        Offset_ QWORD ?
        ; The size of the FirmwareImage array.
        FirmwareImageSizeInBytes DWORD ?
        ; The firmware region being downloaded to the device.
        FirmwareImage BYTE ANYSIZE_ARRAY dup (?)
      SCM_PD_FIRMWARE_DOWNLOAD ends
      _SCM_PD_FIRMWARE_DOWNLOAD typedef SCM_PD_FIRMWARE_DOWNLOAD
      PSCM_PD_FIRMWARE_DOWNLOAD typedef ptr SCM_PD_FIRMWARE_DOWNLOAD
      ; Input buffer for IOCTL_SCM_PD_FIRMWARE_ACTIVATE.
      SCM_PD_FIRMWARE_ACTIVATE struct
        ; Sizeof() of this structure serves as the version.
        Version DWORD ?
        ; Total size of the structure
        Size_ DWORD ?
        ; Reserved. Callers should set to 0.
        Flags DWORD ?
        ; The slot that contains the firmware image being activated.
        Slot BYTE ?
      SCM_PD_FIRMWARE_ACTIVATE ends
      _SCM_PD_FIRMWARE_ACTIVATE typedef SCM_PD_FIRMWARE_ACTIVATE
      PSCM_PD_FIRMWARE_ACTIVATE typedef ptr SCM_PD_FIRMWARE_ACTIVATE
      ; Output buffer for ScmPhysicalDeviceProperty_RuntimeFwActivationInfo
      ; ScmBus Physical Device Last Firmware Activation Status
      SCM_PD_LAST_FW_ACTIVATION_STATUS typedef SDWORD
      ScmPdLastFwActivationStatus_None equ 0
      ; No Firmware Activation performed. Reset to None on boot
      ScmPdLastFwActivationStatus_Success equ 1
      ; Success
      ScmPdLastFwActivationStatus_FwNotFound equ 2
      ; No new staged firmware to activate
      ScmPdLastFwActivationStatus_ColdRebootRequired equ 3
      ; NVDIMM Reset required to activate staged firmware
      ScmPdLastFwActivaitonStatus_ActivationInProgress equ 4
      ; Media disabled during firmware activation
      ScmPdLastFwActivaitonStatus_Retry equ 5
      ; Activation aborted due to throttling. Retry recommended
      ScmPdLastFwActivaitonStatus_FwUnsupported equ 6
      ; Staged firmware version does not meet activation requirements
      ScmPdLastFwActivaitonStatus_UnknownError equ 7
      _SCM_PD_LAST_FW_ACTIVATION_STATUS typedef SCM_PD_LAST_FW_ACTIVATION_STATUS
      PSCM_PD_LAST_FW_ACTIVATION_STATUS typedef ptr SCM_PD_LAST_FW_ACTIVATION_STATUS
      ; Unclassified firmware activation error
      ; ScmBus Physical Device Firmware Activation State
      SCM_PD_FIRMWARE_ACTIVATION_STATE typedef SDWORD
      ScmPdFirmwareActivationState_Idle equ 0
      ; NVDIMM is Idle for firmware update
      ScmPdFirmwareActivationState_Armed equ 1
      ; NVDIMM is armed to activate the staging firmware
      ScmPdFirmwareActivationState_Busy equ 2
      _SCM_PD_FIRMWARE_ACTIVATION_STATE typedef SCM_PD_FIRMWARE_ACTIVATION_STATE
      PSCM_PD_FIRMWARE_ACTIVATION_STATE typedef ptr SCM_PD_FIRMWARE_ACTIVATION_STATE
      ; NVDIMM firmware activation is underway
      SCM_PD_RUNTIME_FW_ACTIVATION_INFO struct
        ; Sizeof() of this structure serves as the version.
        Version DWORD ?
        ; Size of the data contained in this structure. If the output buffer is too small
        ; to contain the requested information, the Size field indicates the length of the
        ; output buffer the caller should provide in order to retrieve all the data.
        Size_ DWORD ?
        ; This provides the previous Firmware Activation status.
        LastFirmwareActivationStatus SCM_PD_LAST_FW_ACTIVATION_STATUS ?
        ; Indicates the current Firmware activation state of the DIMM.
        FirmwareActivationState SCM_PD_FIRMWARE_ACTIVATION_STATE ?
      SCM_PD_RUNTIME_FW_ACTIVATION_INFO ends
      _SCM_PD_RUNTIME_FW_ACTIVATION_INFO typedef SCM_PD_RUNTIME_FW_ACTIVATION_INFO
      PSCM_PD_RUNTIME_FW_ACTIVATION_INFO typedef ptr SCM_PD_RUNTIME_FW_ACTIVATION_INFO
      ; IOCTL_SCM_PD_PASSTHROUGH
      ; This IOCTL sends a vendor-specific command to a physical device and returns its
      ; output.
      ; Input buffer:
      ;      SCM_PD_PASSTHROUGH_INPUT
      ;      The input structure contains another, physical device-type specific structure.
      ; Output buffer:
      ;      SCM_PD_PASSTHROUGH_OUTPUT
      ;      The output structure contains another, physical device-type specific structure.
      SCM_PD_PASSTHROUGH_INPUT struct
        ; Sizeof() of this structure serves as the version.
        Version DWORD ?
        ; The size of the structure, including the Data field, in bytes.
        Size_ DWORD ?
        ; This GUID defines which command protocol is being used. The driver will
        ; check this field to make sure the application is sending commands for
        ; device types that the driver understands.
        ProtocolGuid GUID <>
        ; The size, in bytes, of the data field.
        DataSize DWORD ?
        ; The physical device-type specific structure which contains the passthrough command.
        Data BYTE ANYSIZE_ARRAY dup (?)
      SCM_PD_PASSTHROUGH_INPUT ends
      _SCM_PD_PASSTHROUGH_INPUT typedef SCM_PD_PASSTHROUGH_INPUT
      PSCM_PD_PASSTHROUGH_INPUT typedef ptr SCM_PD_PASSTHROUGH_INPUT
      SCM_PD_PASSTHROUGH_OUTPUT struct
        ; Sizeof() of this structure serves as the version.
        Version DWORD ?
        ; The size of the structure, including the Data field, in bytes.
        ; The caller is responsible for knowing how large the output buffer
        ; will be. The common approach of sending the IOCTL twice - once to learn
        ; the total required size, and again to retrieve the data - isn't recommended
        ; here because of the performance impact of executing a passthrough command.
        Size_ DWORD ?
        ; This GUID defines which command protocol is being used. The application should
        ; check this field to make sure the driver is using a protocol that it understands.
        ProtocolGuid GUID <>
        ; The size, in bytes, of the data field.
        DataSize DWORD ?
        ; The physical device-type specific structure which contains the output of the passthrough command.
        Data BYTE ANYSIZE_ARRAY dup (?)
      SCM_PD_PASSTHROUGH_OUTPUT ends
      _SCM_PD_PASSTHROUGH_OUTPUT typedef SCM_PD_PASSTHROUGH_OUTPUT
      PSCM_PD_PASSTHROUGH_OUTPUT typedef ptr SCM_PD_PASSTHROUGH_OUTPUT
      ; Passthrough structures and definitions for INVDIMM devices.
      ; This structure defines the input of an INVDIMM command. The application sending a passthrough
      ; command uses this structure as the "Data" field of the SCM_PD_PASSTHROUGH_INPUT structure.
      SCM_PD_PASSTHROUGH_INVDIMM_INPUT struct
        ; The command's opcode.
        Opcode DWORD ?
        ; The length, in bytes, of the OpcodeParameters field.
        ; This can be zero, but the size of this structure must always be equal to
        ; or greater than sizeof(SCM_PD_PASSTHROUGH_INVDIMM_INPUT).
        OpcodeParametersLength DWORD ?
        ; The opcode input payload, if any.
        OpcodeParameters BYTE ANYSIZE_ARRAY dup (?)
      SCM_PD_PASSTHROUGH_INVDIMM_INPUT ends
      _SCM_PD_PASSTHROUGH_INVDIMM_INPUT typedef SCM_PD_PASSTHROUGH_INVDIMM_INPUT
      PSCM_PD_PASSTHROUGH_INVDIMM_INPUT typedef ptr SCM_PD_PASSTHROUGH_INVDIMM_INPUT
      ; This structure defines the output of an INVDIMM command. The driver will respond to
      ; a passthrough request by bundling this structure in the "Data" field of the
      ; SCM_PD_PASSTHROUGH_OUTPUT structure.
      SCM_PD_PASSTHROUGH_INVDIMM_OUTPUT struct
        ; The general status of the command (see the INVDIMM _DSM specification for details).
        GeneralStatus WORD ?
        ; The extended status of the command (see the INVDIMM _DSM specification for details).
        ExtendedStatus WORD ?
        ; The length, in bytes, of the OutputData field. Even when this is zero, the total
        ; size of this structure will be equal to or greater than sizeof(SCM_PD_PASSTHROUGH_INVDIMM_OUTPUT).
        OutputDataLength DWORD ?
        ; The data returned by the device in response to the command.
        OutputData BYTE ANYSIZE_ARRAY dup (?)
      SCM_PD_PASSTHROUGH_INVDIMM_OUTPUT ends
      _SCM_PD_PASSTHROUGH_INVDIMM_OUTPUT typedef SCM_PD_PASSTHROUGH_INVDIMM_OUTPUT
      PSCM_PD_PASSTHROUGH_INVDIMM_OUTPUT typedef ptr SCM_PD_PASSTHROUGH_INVDIMM_OUTPUT
      ; IOCTL_SCM_PD_REINITIALIZE_MEDIA
      ; This IOCTL reinitializes the media of a physical persistent memory device, which erases
      ; all the data on it.
      ; Input buffer:
      ;      SCM_PD_REINITIALIZE_MEDIA_INPUT
      ; Output buffer:
      ;      SCM_PD_REINITIALIZE_MEDIA_OUTPUT
      SCM_PD_REINITIALIZE_MEDIA_INPUT struct
        ; Sizeof() of this structure serves as the version.
        Version DWORD ?
        ; The size of the structure, in bytes.
        Size_ DWORD ?
        ; If Overwrite is set to 1, the physical persistent memory device will
        ; overwrite the entire media, which might take several minutes.
        ; If it is set to 0, the physical persistent device may do a crypto-erase or some
        ; other quicker form of clearing the data on the media.
        struct Options
          Options_REC record Options_REC_Filler:31, Options_REC_Overwrite:1
          Options_BITS Options_REC <>
        ends
      SCM_PD_REINITIALIZE_MEDIA_INPUT ends
      _SCM_PD_REINITIALIZE_MEDIA_INPUT typedef SCM_PD_REINITIALIZE_MEDIA_INPUT
      PSCM_PD_REINITIALIZE_MEDIA_INPUT typedef ptr SCM_PD_REINITIALIZE_MEDIA_INPUT
      SCM_PD_MEDIA_REINITIALIZATION_STATUS typedef SDWORD
      ; The media reinitialization was successful and the device is ready for use.
      ScmPhysicalDeviceReinit_Success equ 0
      ; The media reinitialization was successful, but the device requires a reboot before being used.
      ScmPhysicalDeviceReinit_RebootNeeded equ 1
      ; The media reinitialization was successful, but the device requires a cold boot before being used.
      ScmPhysicalDeviceReinit_ColdBootNeeded equ 2
      ScmPhysicalDeviceReinit_Max equ 3
      _SCM_PD_MEDIA_REINITIALIZATION_STATUS typedef SCM_PD_MEDIA_REINITIALIZATION_STATUS
      PSCM_PD_MEDIA_REINITIALIZATION_STATUS typedef ptr SCM_PD_MEDIA_REINITIALIZATION_STATUS
      SCM_PD_REINITIALIZE_MEDIA_OUTPUT struct
        ; Sizeof() of this structure serves as the version.
        Version DWORD ?
        ; The size of the structure, in bytes.
        Size_ DWORD ?
        ; The detailed status of the reinitialization operation, in case it
        ; was successful. If it failed, the IOCTL itself will fail and callers
        ; should not look at the returned status code instead of this field.
        Status SCM_PD_MEDIA_REINITIALIZATION_STATUS ?
      SCM_PD_REINITIALIZE_MEDIA_OUTPUT ends
      _SCM_PD_REINITIALIZE_MEDIA_OUTPUT typedef SCM_PD_REINITIALIZE_MEDIA_OUTPUT
      PSCM_PD_REINITIALIZE_MEDIA_OUTPUT typedef ptr SCM_PD_REINITIALIZE_MEDIA_OUTPUT
    endif
    ; NTDDI_WIN10_RS5
  endif
  ; _NTDDSCM_H_
  ifndef _NTDDDISK_H_
    _NTDDDISK_H_ equ <>
    include winapifamily.inc
    if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP or WINAPI_PARTITION_SYSTEM)
      if Defined(_MSC_VER)
        if (_MSC_VER ge 1200)
          ; nonstandard extension used : nameless struct/union
          ; nonstandard extension used : bitfield other than int
          ; padding added after data member
        endif
      endif
      ; IoControlCode values for disk devices.
      IOCTL_DISK_BASE equ <FILE_DEVICE_DISK>
      IOCTL_DISK_GET_DRIVE_GEOMETRY equ CTL_CODE(IOCTL_DISK_BASE, 0000h, METHOD_BUFFERED, FILE_ANY_ACCESS)
      IOCTL_DISK_GET_PARTITION_INFO equ CTL_CODE(IOCTL_DISK_BASE, 0001h, METHOD_BUFFERED, FILE_READ_ACCESS)
      IOCTL_DISK_SET_PARTITION_INFO equ CTL_CODE(IOCTL_DISK_BASE, 0002h, METHOD_BUFFERED, FILE_READ_ACCESS or FILE_WRITE_ACCESS)
      IOCTL_DISK_GET_DRIVE_LAYOUT equ CTL_CODE(IOCTL_DISK_BASE, 0003h, METHOD_BUFFERED, FILE_READ_ACCESS)
      IOCTL_DISK_SET_DRIVE_LAYOUT equ CTL_CODE(IOCTL_DISK_BASE, 0004h, METHOD_BUFFERED, FILE_READ_ACCESS or FILE_WRITE_ACCESS)
      IOCTL_DISK_VERIFY equ CTL_CODE(IOCTL_DISK_BASE, 0005h, METHOD_BUFFERED, FILE_ANY_ACCESS)
      IOCTL_DISK_FORMAT_TRACKS equ CTL_CODE(IOCTL_DISK_BASE, 0006h, METHOD_BUFFERED, FILE_READ_ACCESS or FILE_WRITE_ACCESS)
      IOCTL_DISK_REASSIGN_BLOCKS equ CTL_CODE(IOCTL_DISK_BASE, 0007h, METHOD_BUFFERED, FILE_READ_ACCESS or FILE_WRITE_ACCESS)
      IOCTL_DISK_PERFORMANCE equ CTL_CODE(IOCTL_DISK_BASE, 0008h, METHOD_BUFFERED, FILE_ANY_ACCESS)
      IOCTL_DISK_IS_WRITABLE equ CTL_CODE(IOCTL_DISK_BASE, 0009h, METHOD_BUFFERED, FILE_ANY_ACCESS)
      IOCTL_DISK_LOGGING equ CTL_CODE(IOCTL_DISK_BASE, 000ah, METHOD_BUFFERED, FILE_ANY_ACCESS)
      IOCTL_DISK_FORMAT_TRACKS_EX equ CTL_CODE(IOCTL_DISK_BASE, 000bh, METHOD_BUFFERED, FILE_READ_ACCESS or FILE_WRITE_ACCESS)
      IOCTL_DISK_HISTOGRAM_STRUCTURE equ CTL_CODE(IOCTL_DISK_BASE, 000ch, METHOD_BUFFERED, FILE_ANY_ACCESS)
      IOCTL_DISK_HISTOGRAM_DATA equ CTL_CODE(IOCTL_DISK_BASE, 000dh, METHOD_BUFFERED, FILE_ANY_ACCESS)
      IOCTL_DISK_HISTOGRAM_RESET equ CTL_CODE(IOCTL_DISK_BASE, 000eh, METHOD_BUFFERED, FILE_ANY_ACCESS)
      IOCTL_DISK_REQUEST_STRUCTURE equ CTL_CODE(IOCTL_DISK_BASE, 000fh, METHOD_BUFFERED, FILE_ANY_ACCESS)
      IOCTL_DISK_REQUEST_DATA equ CTL_CODE(IOCTL_DISK_BASE, 0010h, METHOD_BUFFERED, FILE_ANY_ACCESS)
      IOCTL_DISK_PERFORMANCE_OFF equ CTL_CODE(IOCTL_DISK_BASE, 0018h, METHOD_BUFFERED, FILE_ANY_ACCESS)
      if (_WIN32_WINNT ge 0400h)
        IOCTL_DISK_CONTROLLER_NUMBER equ CTL_CODE(IOCTL_DISK_BASE, 0011h, METHOD_BUFFERED, FILE_ANY_ACCESS)
        ; IOCTL support for SMART drive fault prediction.
        SMART_GET_VERSION equ CTL_CODE(IOCTL_DISK_BASE, 0020h, METHOD_BUFFERED, FILE_READ_ACCESS)
        SMART_SEND_DRIVE_COMMAND equ CTL_CODE(IOCTL_DISK_BASE, 0021h, METHOD_BUFFERED, FILE_READ_ACCESS or FILE_WRITE_ACCESS)
        SMART_RCV_DRIVE_DATA equ CTL_CODE(IOCTL_DISK_BASE, 0022h, METHOD_BUFFERED, FILE_READ_ACCESS or FILE_WRITE_ACCESS)
        if (NTDDI_VERSION ge NTDDI_WIN10_CO)
          SMART_RCV_DRIVE_DATA_EX equ CTL_CODE(IOCTL_DISK_BASE, 0023h, METHOD_BUFFERED, FILE_ANY_ACCESS)
          ;* NTDDI_VERSION >= NTDDI_WIN10_CO *
        endif
        ;* _WIN32_WINNT >= 0x0400 *
      endif
      if (_WIN32_WINNT ge 500h)
        ; New IOCTLs for GUID Partition tabled disks.
        IOCTL_DISK_GET_PARTITION_INFO_EX equ CTL_CODE(IOCTL_DISK_BASE, 0012h, METHOD_BUFFERED, FILE_ANY_ACCESS)
        IOCTL_DISK_SET_PARTITION_INFO_EX equ CTL_CODE(IOCTL_DISK_BASE, 0013h, METHOD_BUFFERED, FILE_READ_ACCESS or FILE_WRITE_ACCESS)
        IOCTL_DISK_GET_DRIVE_LAYOUT_EX equ CTL_CODE(IOCTL_DISK_BASE, 0014h, METHOD_BUFFERED, FILE_ANY_ACCESS)
        IOCTL_DISK_SET_DRIVE_LAYOUT_EX equ CTL_CODE(IOCTL_DISK_BASE, 0015h, METHOD_BUFFERED, FILE_READ_ACCESS or FILE_WRITE_ACCESS)
        IOCTL_DISK_CREATE_DISK equ CTL_CODE(IOCTL_DISK_BASE, 0016h, METHOD_BUFFERED, FILE_READ_ACCESS or FILE_WRITE_ACCESS)
        IOCTL_DISK_GET_LENGTH_INFO equ CTL_CODE(IOCTL_DISK_BASE, 0017h, METHOD_BUFFERED, FILE_READ_ACCESS)
        IOCTL_DISK_GET_DRIVE_GEOMETRY_EX equ CTL_CODE(IOCTL_DISK_BASE, 0028h, METHOD_BUFFERED, FILE_ANY_ACCESS)
        ;* _WIN32_WINNT >= 0x0500 *
      endif
      if (_WIN32_WINNT ge 0502h)
        ; New IOCTL for disk devices that support 8 byte LBA
        IOCTL_DISK_REASSIGN_BLOCKS_EX equ CTL_CODE(IOCTL_DISK_BASE, 0029h, METHOD_BUFFERED, FILE_READ_ACCESS or FILE_WRITE_ACCESS)
      endif
      ;_WIN32_WINNT >= 0x0502
      if (_WIN32_WINNT ge 0500h)
        IOCTL_DISK_UPDATE_DRIVE_SIZE equ CTL_CODE(IOCTL_DISK_BASE, 0032h, METHOD_BUFFERED, FILE_READ_ACCESS or FILE_WRITE_ACCESS)
        IOCTL_DISK_GROW_PARTITION equ CTL_CODE(IOCTL_DISK_BASE, 0034h, METHOD_BUFFERED, FILE_READ_ACCESS or FILE_WRITE_ACCESS)
        IOCTL_DISK_GET_CACHE_INFORMATION equ CTL_CODE(IOCTL_DISK_BASE, 0035h, METHOD_BUFFERED, FILE_READ_ACCESS)
        IOCTL_DISK_SET_CACHE_INFORMATION equ CTL_CODE(IOCTL_DISK_BASE, 0036h, METHOD_BUFFERED, FILE_READ_ACCESS or FILE_WRITE_ACCESS)
        if (NTDDI_VERSION lt NTDDI_WS03)
          IOCTL_DISK_GET_WRITE_CACHE_STATE equ CTL_CODE(IOCTL_DISK_BASE, 0037h, METHOD_BUFFERED, FILE_READ_ACCESS)
        else
          OBSOLETE_DISK_GET_WRITE_CACHE_STATE equ CTL_CODE(IOCTL_DISK_BASE, 0037h, METHOD_BUFFERED, FILE_READ_ACCESS)
        endif
        IOCTL_DISK_DELETE_DRIVE_LAYOUT equ CTL_CODE(IOCTL_DISK_BASE, 0040h, METHOD_BUFFERED, FILE_READ_ACCESS or FILE_WRITE_ACCESS)
        ; Called to flush cached information that the driver may have about this
        ; device's characteristics.  Not all drivers cache characteristics, and not
        ; cached properties can be flushed.  This simply serves as an update to the
        ; driver that it may want to do an expensive reexamination of the device's
        ; characteristics now (fixed media size, partition table, etc...)
        IOCTL_DISK_UPDATE_PROPERTIES equ CTL_CODE(IOCTL_DISK_BASE, 0050h, METHOD_BUFFERED, FILE_ANY_ACCESS)
        ;  Special IOCTLs needed to support PC-98 machines in Japan
        IOCTL_DISK_FORMAT_DRIVE equ CTL_CODE(IOCTL_DISK_BASE, 00f3h, METHOD_BUFFERED, FILE_READ_ACCESS or FILE_WRITE_ACCESS)
        IOCTL_DISK_SENSE_DEVICE equ CTL_CODE(IOCTL_DISK_BASE, 00f8h, METHOD_BUFFERED, FILE_ANY_ACCESS)
        ;* _WIN32_WINNT >= 0x0500 *
      endif
      ; The following device control codes are common for all class drivers.  The
      ; functions codes defined here must match all of the other class drivers.
      ; Warning: these codes will be replaced in the future by equivalent
      ; IOCTL_STORAGE codes
      IOCTL_DISK_CHECK_VERIFY equ CTL_CODE(IOCTL_DISK_BASE, 0200h, METHOD_BUFFERED, FILE_READ_ACCESS)
      IOCTL_DISK_MEDIA_REMOVAL equ CTL_CODE(IOCTL_DISK_BASE, 0201h, METHOD_BUFFERED, FILE_READ_ACCESS)
      IOCTL_DISK_EJECT_MEDIA equ CTL_CODE(IOCTL_DISK_BASE, 0202h, METHOD_BUFFERED, FILE_READ_ACCESS)
      IOCTL_DISK_LOAD_MEDIA equ CTL_CODE(IOCTL_DISK_BASE, 0203h, METHOD_BUFFERED, FILE_READ_ACCESS)
      IOCTL_DISK_RESERVE equ CTL_CODE(IOCTL_DISK_BASE, 0204h, METHOD_BUFFERED, FILE_READ_ACCESS)
      IOCTL_DISK_RELEASE equ CTL_CODE(IOCTL_DISK_BASE, 0205h, METHOD_BUFFERED, FILE_READ_ACCESS)
      IOCTL_DISK_FIND_NEW_DEVICES equ CTL_CODE(IOCTL_DISK_BASE, 0206h, METHOD_BUFFERED, FILE_READ_ACCESS)
      IOCTL_DISK_GET_MEDIA_TYPES equ CTL_CODE(IOCTL_DISK_BASE, 0300h, METHOD_BUFFERED, FILE_ANY_ACCESS)
      ; Define the partition types returnable by known disk drivers.
      PARTITION_ENTRY_UNUSED equ 00h; Entry unused

      PARTITION_FAT_12 equ 01h; 12-bit FAT entries

      PARTITION_XENIX_1 equ 02h; Xenix

      PARTITION_XENIX_2 equ 03h; Xenix

      PARTITION_FAT_16 equ 04h; 16-bit FAT entries

      PARTITION_EXTENDED equ 05h; Extended partition entry

      PARTITION_HUGE equ 06h; Huge partition MS-DOS V4

      PARTITION_IFS equ 07h; IFS Partition

      PARTITION_OS2BOOTMGR equ 0Ah; OS/2 Boot Manager/OPUS/Coherent swap

      PARTITION_FAT32 equ 0Bh; FAT32

      PARTITION_FAT32_XINT13 equ 0Ch; FAT32 using extended int13 services

      PARTITION_XINT13 equ 0Eh; Win95 partition using extended int13 services

      PARTITION_XINT13_EXTENDED equ 0Fh; Same as type 5 but uses extended int13 services

      PARTITION_MSFT_RECOVERY equ 27h; Microsoft recovery partition

      PARTITION_MAIN_OS equ 28h; Main OS partition

      PARTIITON_OS_DATA equ 29h; OS data partition

      PARTITION_PRE_INSTALLED equ 2ah; PreInstalled partition

      PARTITION_BSP equ 2bh; BSP partition

      PARTITION_DPP equ 2ch; DPP partition

      PARTITION_WINDOWS_SYSTEM equ 2dh; Windows system partition

      PARTITION_PREP equ 41h; PowerPC Reference Platform (PReP) Boot Partition

      PARTITION_LDM equ 42h; Logical Disk Manager partition

      PARTITION_DM equ 54h; OnTrack Disk Manager partition

      PARTITION_EZDRIVE equ 55h; EZ-Drive partition

      PARTITION_UNIX equ 63h; Unix

      PARTITION_SPACES_DATA equ 0D7h; Storage Spaces protective partition

      PARTITION_SPACES equ 0E7h; Storage Spaces protective partition

      PARTITION_GPT equ 0EEh; Gpt protective partition

      PARTITION_SYSTEM equ 0EFh; System partition

      VALID_NTFT equ 0C0h; NTFT uses high order bits

      ; The high bit of the partition type code indicates that a partition
      ; is part of an NTFT mirror or striped array.
      PARTITION_NTFT equ 80h; NTFT partition

      ; The following macro is used to determine which partitions should be
      ; assigned drive letters.
      ;++
      ; BOOLEAN
      ; IsRecognizedPartition(
      ;     IN DWORD PartitionType
      ;     )
      ; Routine Description:
      ;     This macro is used to determine to which partitions drive letters
      ;     should be assigned.
      ; Arguments:
      ;     PartitionType - Supplies the type of the partition being examined.
      ; Return Value:
      ;     The return value is TRUE if the partition type is recognized,
      ;     otherwise FALSE is returned.
      ;--
      if (NTDDI_VERSION lt NTDDI_VISTA)
        IsRecognizedPartition macro PartitionType
          exitm <(((PartitionType and PARTITION_NTFT) and (((PartitionType and not 0C0h) == PARTITION_HUGE) or ((PartitionType and not 0C0h) == PARTITION_IFS) or ((PartitionType and not 0C0h) == PARTITION_FAT32) or ((PartitionType and not 0C0h) == PARTITION_FAT32_XINT13))) or ((PartitionType) == PARTITION_FAT_12) or ((PartitionType) == PARTITION_FAT_16) or ((PartitionType) == PARTITION_HUGE) or ((PartitionType) == PARTITION_IFS) or ((PartitionType) == PARTITION_FAT32) or ((PartitionType) == PARTITION_FAT32_XINT13) or ((PartitionType) == PARTITION_XINT13))>
        endm
      else
        IsRecognizedPartition macro PartitionType
          exitm <(((PartitionType) == PARTITION_BSP) or ((PartitionType) == PARTITION_DPP) or ((PartitionType) == PARTITION_FAT_12) or ((PartitionType) == PARTITION_FAT_16) or ((PartitionType) == PARTITION_FAT32) or ((PartitionType) == PARTITION_FAT32_XINT13) or ((PartitionType) == PARTITION_HUGE) or ((PartitionType) == PARTITION_IFS) or ((PartitionType) == PARTITION_MAIN_OS) or ((PartitionType) == PARTITION_MSFT_RECOVERY) or ((PartitionType) == PARTIITON_OS_DATA) or ((PartitionType) == PARTITION_PRE_INSTALLED) or ((PartitionType) == PARTITION_SYSTEM) or ((PartitionType) == PARTITION_WINDOWS_SYSTEM) or ((PartitionType) == PARTITION_XINT13))>
        endm
      endif
      ;++
      ; BOOLEAN
      ; IsContainerPartition(
      ;     IN DWORD PartitionType
      ;     )
      ; Routine Description:
      ;     This macro is used to determine to which partition types are actually
      ;     containers for other partitions (ie, extended partitions).
      ; Arguments:
      ;     PartitionType - Supplies the type of the partition being examined.
      ; Return Value:
      ;     The return value is TRUE if the partition type is a container,
      ;     otherwise FALSE is returned.
      ;--
      IsContainerPartition macro PartitionType
        exitm <((PartitionType == PARTITION_EXTENDED) or (PartitionType == PARTITION_XINT13_EXTENDED))>
      endm
      ;++
      ; BOOLEAN
      ; IsFTPartition(
      ;     IN DWORD PartitionType
      ;     )
      ; Routine Description:
      ;     This macro is used to determine if the given partition is an FT
      ;     partition.
      ; Arguments:
      ;     PartitionType - Supplies the type of the partition being examined.
      ; Return Value:
      ;     The return value is TRUE if the partition type is an FT partition,
      ;     otherwise FALSE is returned.
      ;--
      IsFTPartition macro PartitionType
        exitm <((PartitionType and PARTITION_NTFT) and (((PartitionType and not 0C0h) == PARTITION_HUGE) or ((PartitionType and not 0C0h) == PARTITION_IFS) or ((PartitionType and not 0C0h) == PARTITION_FAT32) or ((PartitionType and not 0C0h) == PARTITION_FAT32_XINT13)))>
      endm
      ; Define the media types supported by the driver.
      MEDIA_TYPE typedef SDWORD
      Unknown equ 0
      ; Format is unknown
      F5_1Pt2_512 equ 1
      ; 5.25", 1.2MB,  512 bytes/sector
      F3_1Pt44_512 equ 2
      ; 3.5",  1.44MB, 512 bytes/sector
      F3_2Pt88_512 equ 3
      ; 3.5",  2.88MB, 512 bytes/sector
      F3_20Pt8_512 equ 4
      ; 3.5",  20.8MB, 512 bytes/sector
      F3_720_512 equ 5
      ; 3.5",  720KB,  512 bytes/sector
      F5_360_512 equ 6
      ; 5.25", 360KB,  512 bytes/sector
      F5_320_512 equ 7
      ; 5.25", 320KB,  512 bytes/sector
      F5_320_1024 equ 8
      ; 5.25", 320KB,  1024 bytes/sector
      F5_180_512 equ 9
      ; 5.25", 180KB,  512 bytes/sector
      F5_160_512 equ 10
      ; 5.25", 160KB,  512 bytes/sector
      RemovableMedia equ 11
      ; Removable media other than floppy
      FixedMedia equ 12
      ; Fixed hard disk media
      F3_120M_512 equ 13
      ; 3.5", 120M Floppy
      F3_640_512 equ 14
      ; 3.5" ,  640KB,  512 bytes/sector
      F5_640_512 equ 15
      ; 5.25",  640KB,  512 bytes/sector
      F5_720_512 equ 16
      ; 5.25",  720KB,  512 bytes/sector
      F3_1Pt2_512 equ 17
      ; 3.5" ,  1.2Mb,  512 bytes/sector
      F3_1Pt23_1024 equ 18
      ; 3.5" ,  1.23Mb, 1024 bytes/sector
      F5_1Pt23_1024 equ 19
      ; 5.25",  1.23MB, 1024 bytes/sector
      F3_128Mb_512 equ 20
      ; 3.5" MO 128Mb   512 bytes/sector
      F3_230Mb_512 equ 21
      ; 3.5" MO 230Mb   512 bytes/sector
      F8_256_128 equ 22
      ; 8",     256KB,  128 bytes/sector
      F3_200Mb_512 equ 23
      ; 3.5",   200M Floppy (HiFD)
      F3_240M_512 equ 24
      ; 3.5",   240Mb Floppy (HiFD)
      F3_32M_512 equ 25
      _MEDIA_TYPE typedef MEDIA_TYPE
      PMEDIA_TYPE typedef ptr MEDIA_TYPE
      ; 3.5",   32Mb Floppy
      ; Define the input buffer structure for the driver, when
      ; it is called with IOCTL_DISK_FORMAT_TRACKS.
      FORMAT_PARAMETERS struct
        MediaType MEDIA_TYPE ?
        StartCylinderNumber DWORD ?
        EndCylinderNumber DWORD ?
        StartHeadNumber DWORD ?
        EndHeadNumber DWORD ?
      FORMAT_PARAMETERS ends
      _FORMAT_PARAMETERS typedef FORMAT_PARAMETERS
      PFORMAT_PARAMETERS typedef ptr FORMAT_PARAMETERS
      ; Define the BAD_TRACK_NUMBER type. An array of elements of this type is
      ; returned by the driver on IOCTL_DISK_FORMAT_TRACKS requests, to indicate
      ; what tracks were bad during formatting. The length of that array is
      ; reported in the `Information' field of the I/O Status Block.
      BAD_TRACK_NUMBER typedef WORD
      PBAD_TRACK_NUMBER typedef ptr WORD
      ; Define the input buffer structure for the driver, when
      ; it is called with IOCTL_DISK_FORMAT_TRACKS_EX.
      FORMAT_EX_PARAMETERS struct
        MediaType MEDIA_TYPE ?
        StartCylinderNumber DWORD ?
        EndCylinderNumber DWORD ?
        StartHeadNumber DWORD ?
        EndHeadNumber DWORD ?
        FormatGapLength WORD ?
        SectorsPerTrack WORD ?
        SectorNumber WORD 1 dup (?)
      FORMAT_EX_PARAMETERS ends
      _FORMAT_EX_PARAMETERS typedef FORMAT_EX_PARAMETERS
      PFORMAT_EX_PARAMETERS typedef ptr FORMAT_EX_PARAMETERS
      ; The following structure is returned on an IOCTL_DISK_GET_DRIVE_GEOMETRY
      ; request and an array of them is returned on an IOCTL_DISK_GET_MEDIA_TYPES
      ; request.
      DISK_GEOMETRY struct
        Cylinders LARGE_INTEGER <>
        MediaType MEDIA_TYPE ?
        TracksPerCylinder DWORD ?
        SectorsPerTrack DWORD ?
        BytesPerSector DWORD ?
      DISK_GEOMETRY ends
      _DISK_GEOMETRY typedef DISK_GEOMETRY
      PDISK_GEOMETRY typedef ptr DISK_GEOMETRY
      ; This wmi guid returns a DISK_GEOMETRY structure
      WMI_DISK_GEOMETRY_GUID equ { 25007f51h, 57c2h, 11d1h, { 0a5h, 28h, 0h, 0a0h, 0c9h, 6h, 29h, 10h } }
      ; The following structure is returned on an IOCTL_DISK_GET_PARTITION_INFO
      ; and an IOCTL_DISK_GET_DRIVE_LAYOUT request.  It is also used in a request
      ; to change the drive layout, IOCTL_DISK_SET_DRIVE_LAYOUT.
      PARTITION_INFORMATION struct
        StartingOffset LARGE_INTEGER <>
        PartitionLength LARGE_INTEGER <>
        HiddenSectors DWORD ?
        PartitionNumber DWORD ?
        PartitionType BYTE ?
        BootIndicator BYTE ?
        RecognizedPartition BYTE ?
        RewritePartition BYTE ?
      PARTITION_INFORMATION ends
      _PARTITION_INFORMATION typedef PARTITION_INFORMATION
      PPARTITION_INFORMATION typedef ptr PARTITION_INFORMATION
      ; The following structure is used to change the partition type of a
      ; specified disk partition using an IOCTL_DISK_SET_PARTITION_INFO
      ; request.
      SET_PARTITION_INFORMATION struct
        PartitionType BYTE ?
      SET_PARTITION_INFORMATION ends
      _SET_PARTITION_INFORMATION typedef SET_PARTITION_INFORMATION
      PSET_PARTITION_INFORMATION typedef ptr SET_PARTITION_INFORMATION
      ; The following structures is returned on an IOCTL_DISK_GET_DRIVE_LAYOUT
      ; request and given as input to an IOCTL_DISK_SET_DRIVE_LAYOUT request.
      DRIVE_LAYOUT_INFORMATION struct
        PartitionCount DWORD ?
        Signature DWORD ?
        PartitionEntry PARTITION_INFORMATION 1 dup (<>)
      DRIVE_LAYOUT_INFORMATION ends
      _DRIVE_LAYOUT_INFORMATION typedef DRIVE_LAYOUT_INFORMATION
      PDRIVE_LAYOUT_INFORMATION typedef ptr DRIVE_LAYOUT_INFORMATION
      ; The following structure is passed in on an IOCTL_DISK_VERIFY request.
      ; The offset and length parameters are both given in bytes.
      VERIFY_INFORMATION struct
        StartingOffset LARGE_INTEGER <>
        Length_ DWORD ?
      VERIFY_INFORMATION ends
      _VERIFY_INFORMATION typedef VERIFY_INFORMATION
      PVERIFY_INFORMATION typedef ptr VERIFY_INFORMATION
      ; The following structure is passed in on an IOCTL_DISK_REASSIGN_BLOCKS
      ; request.
      REASSIGN_BLOCKS struct
        Reserved WORD ?
        Count WORD ?
        BlockNumber DWORD 1 dup (?)
      REASSIGN_BLOCKS ends
      _REASSIGN_BLOCKS typedef REASSIGN_BLOCKS
      PREASSIGN_BLOCKS typedef ptr REASSIGN_BLOCKS
      ; The following structure is passed in on an IOCTL_DISK_REASSIGN_BLOCKS_EX
      ; request.
      include pshpack1.inc
      REASSIGN_BLOCKS_EX struct
        Reserved WORD ?
        Count WORD ?
        BlockNumber LARGE_INTEGER 1 dup (<>)
      REASSIGN_BLOCKS_EX ends
      _REASSIGN_BLOCKS_EX typedef REASSIGN_BLOCKS_EX
      PREASSIGN_BLOCKS_EX typedef ptr REASSIGN_BLOCKS_EX
      include poppack.inc
      if (_WIN32_WINNT ge 500h)
        ; Support for GUID Partition Table (GPT) disks.
        ; There are currently two ways a disk can be partitioned. With a traditional
        ; AT-style master boot record (PARTITION_STYLE_MBR) and with a new, GPT
        ; partition table (PARTITION_STYLE_GPT). RAW is for an unrecognizable
        ; partition style. There are a very limited number of things you can
        ; do with a RAW partititon.
        PARTITION_STYLE typedef SDWORD
        PARTITION_STYLE_MBR equ 0
        PARTITION_STYLE_GPT equ 1
        PARTITION_STYLE_RAW equ 2
        _PARTITION_STYLE typedef PARTITION_STYLE

        ; The following structure defines information in a GPT partition that is
        ; not common to both GPT and MBR partitions.
        PARTITION_INFORMATION_GPT struct
          PartitionType GUID <>
          ; Partition type. See table 16-3.
          PartitionId GUID <>
          ; Unique GUID for this partition.
          Attributes QWORD ?
          ; See table 16-4.
          Name_ WORD 36 dup (?)
          ; Partition Name in Unicode.
        PARTITION_INFORMATION_GPT ends
        _PARTITION_INFORMATION_GPT typedef PARTITION_INFORMATION_GPT
        PPARTITION_INFORMATION_GPT typedef ptr PARTITION_INFORMATION_GPT
        ;  The following are GPT partition attributes applicable for any
        ;  partition type. These attributes are not OS-specific
        GPT_ATTRIBUTE_PLATFORM_REQUIRED equ (0000000000000001h)
        GPT_ATTRIBUTE_NO_BLOCK_IO_PROTOCOL equ (0000000000000002h)
        GPT_ATTRIBUTE_LEGACY_BIOS_BOOTABLE equ (0000000000000004h)
        ; The following are GPT partition attributes applicable when the
        ; PartitionType is PARTITION_BASIC_DATA_GUID.
        GPT_BASIC_DATA_ATTRIBUTE_NO_DRIVE_LETTER equ (8000000000000000h)
        GPT_BASIC_DATA_ATTRIBUTE_HIDDEN equ (4000000000000000h)
        GPT_BASIC_DATA_ATTRIBUTE_SHADOW_COPY equ (2000000000000000h)
        GPT_BASIC_DATA_ATTRIBUTE_READ_ONLY equ (1000000000000000h)
        GPT_BASIC_DATA_ATTRIBUTE_OFFLINE equ (0800000000000000h)
        GPT_BASIC_DATA_ATTRIBUTE_DAX equ (0400000000000000h)
        GPT_BASIC_DATA_ATTRIBUTE_SERVICE equ (0200000000000000h)
        ; The following are GPT partition attributes applicable when the
        ; PartitionType is PARTITION_SPACES_GUID.
        GPT_SPACES_ATTRIBUTE_NO_METADATA equ (8000000000000000h)
        ; The following structure defines information in an MBR partition that is not
        ; common to both GPT and MBR partitions.
        PARTITION_INFORMATION_MBR struct
          PartitionType BYTE ?
          BootIndicator BYTE ?
          RecognizedPartition BYTE ?
          HiddenSectors DWORD ?
          ;* ABRACADABRA_THRESHOLD *
          if (NTDDI_VERSION ge NTDDI_WINBLUE)
            PartitionId GUID <>
          endif
        PARTITION_INFORMATION_MBR ends
        _PARTITION_INFORMATION_MBR typedef PARTITION_INFORMATION_MBR
        PPARTITION_INFORMATION_MBR typedef ptr PARTITION_INFORMATION_MBR
        ; The structure SET_PARTITION_INFO_EX is used with the ioctl
        ; IOCTL_SET_PARTITION_INFO_EX to set information about a specific
        ; partition. Note that for MBR partitions, you can only set the partition
        ; signature, whereas GPT partitions allow setting of all fields that
        ; you can get.
        SET_PARTITION_INFORMATION_MBR typedef SET_PARTITION_INFORMATION
        SET_PARTITION_INFORMATION_GPT typedef PARTITION_INFORMATION_GPT
        SET_PARTITION_INFORMATION_EX struct
          PartitionStyle PARTITION_STYLE ?
          union
            Mbr SET_PARTITION_INFORMATION_MBR <>
            Gpt SET_PARTITION_INFORMATION_GPT <>
          ends
        SET_PARTITION_INFORMATION_EX ends
        _SET_PARTITION_INFORMATION_EX typedef SET_PARTITION_INFORMATION_EX
        PSET_PARTITION_INFORMATION_EX typedef ptr SET_PARTITION_INFORMATION_EX
        ; The structure CREATE_DISK_GPT with the ioctl IOCTL_DISK_CREATE_DISK
        ; to initialize a disk with an empty GPT partition table.
        CREATE_DISK_GPT struct
          DiskId GUID <>
          ; Unique disk id for the disk.
          MaxPartitionCount DWORD ?
          ; Maximim number of partitions allowable.
        CREATE_DISK_GPT ends
        _CREATE_DISK_GPT typedef CREATE_DISK_GPT
        PCREATE_DISK_GPT typedef ptr CREATE_DISK_GPT
        ; The structure CREATE_DISK_MBR with the ioctl IOCTL_DISK_CREATE_DISK
        ; to initialize a disk with an empty MBR partition table.
        CREATE_DISK_MBR struct
          Signature DWORD ?
        CREATE_DISK_MBR ends
        _CREATE_DISK_MBR typedef CREATE_DISK_MBR
        PCREATE_DISK_MBR typedef ptr CREATE_DISK_MBR
        CREATE_DISK struct
          PartitionStyle PARTITION_STYLE ?
          union
            Mbr CREATE_DISK_MBR <>
            Gpt CREATE_DISK_GPT <>
          ends
        CREATE_DISK ends
        _CREATE_DISK typedef CREATE_DISK
        PCREATE_DISK typedef ptr CREATE_DISK
        ; The structure GET_LENGTH_INFORMATION is used with the ioctl
        ; IOCTL_DISK_GET_LENGTH_INFO to obtain the length, in bytes, of the
        ; disk, partition, or volume.
        GET_LENGTH_INFORMATION struct
          Length_ LARGE_INTEGER <>
        GET_LENGTH_INFORMATION ends
        _GET_LENGTH_INFORMATION typedef GET_LENGTH_INFORMATION
        PGET_LENGTH_INFORMATION typedef ptr GET_LENGTH_INFORMATION
        ; The PARTITION_INFORMATION_EX structure is used with the
        ; IOCTL_DISK_GET_DRIVE_LAYOUT_EX, IOCTL_DISK_SET_DRIVE_LAYOUT_EX,
        ; IOCTL_DISK_GET_PARTITION_INFO_EX and IOCTL_DISK_SET_PARTITION_INFO_EX calls.
        PARTITION_INFORMATION_EX struct
          PartitionStyle PARTITION_STYLE ?
          StartingOffset LARGE_INTEGER <>
          PartitionLength LARGE_INTEGER <>
          PartitionNumber DWORD ?
          RewritePartition BYTE ?
          ;* ABRACADABRA_WIN10_RS3 *
          if (NTDDI_VERSION ge NTDDI_WIN10_RS3)
            IsServicePartition BYTE ?
          endif
          union
            Mbr PARTITION_INFORMATION_MBR <>
            Gpt PARTITION_INFORMATION_GPT <>
          ends
        PARTITION_INFORMATION_EX ends
        _PARTITION_INFORMATION_EX typedef PARTITION_INFORMATION_EX
        PPARTITION_INFORMATION_EX typedef ptr PARTITION_INFORMATION_EX
        ; GPT specific drive layout information.
        DRIVE_LAYOUT_INFORMATION_GPT struct
          DiskId GUID <>
          StartingUsableOffset LARGE_INTEGER <>
          UsableLength LARGE_INTEGER <>
          MaxPartitionCount DWORD ?
        DRIVE_LAYOUT_INFORMATION_GPT ends
        _DRIVE_LAYOUT_INFORMATION_GPT typedef DRIVE_LAYOUT_INFORMATION_GPT
        PDRIVE_LAYOUT_INFORMATION_GPT typedef ptr DRIVE_LAYOUT_INFORMATION_GPT
        ; MBR specific drive layout information.
        DRIVE_LAYOUT_INFORMATION_MBR struct
          Signature DWORD ?
          ;* ABRACADABRA_WIN10_RS1 *
          if (NTDDI_VERSION ge NTDDI_WIN10_RS1)
            CheckSum DWORD ?
          endif
        DRIVE_LAYOUT_INFORMATION_MBR ends
        _DRIVE_LAYOUT_INFORMATION_MBR typedef DRIVE_LAYOUT_INFORMATION_MBR
        PDRIVE_LAYOUT_INFORMATION_MBR typedef ptr DRIVE_LAYOUT_INFORMATION_MBR
        ; The structure DRIVE_LAYOUT_INFORMATION_EX is used with the
        ; IOCTL_SET_DRIVE_LAYOUT_EX and IOCTL_GET_DRIVE_LAYOUT_EX calls.
        DRIVE_LAYOUT_INFORMATION_EX struct
          PartitionStyle DWORD ?
          PartitionCount DWORD ?
          union
            Mbr DRIVE_LAYOUT_INFORMATION_MBR <>
            Gpt DRIVE_LAYOUT_INFORMATION_GPT <>
          ends
          PartitionEntry PARTITION_INFORMATION_EX 1 dup (<>)
        DRIVE_LAYOUT_INFORMATION_EX ends
        _DRIVE_LAYOUT_INFORMATION_EX typedef DRIVE_LAYOUT_INFORMATION_EX
        PDRIVE_LAYOUT_INFORMATION_EX typedef ptr DRIVE_LAYOUT_INFORMATION_EX
      endif
      ; (_WIN32_WINNT >= 0x0500)
      if (_WIN32_WINNT ge 0500h)
        ; The DISK_GEOMETRY_EX structure is returned on issuing an
        ; IOCTL_DISK_GET_DRIVE_GEOMETRY_EX ioctl.
        DETECTION_TYPE typedef SDWORD
        DetectNone equ 0
        DetectInt13 equ 1
        DetectExInt13 equ 2
        _DETECTION_TYPE typedef DETECTION_TYPE

        DISK_INT13_INFO struct
          DriveSelect WORD ?
          MaxCylinders DWORD ?
          SectorsPerTrack WORD ?
          MaxHeads WORD ?
          NumberDrives WORD ?
        DISK_INT13_INFO ends
        _DISK_INT13_INFO typedef DISK_INT13_INFO
        PDISK_INT13_INFO typedef ptr DISK_INT13_INFO
        DISK_EX_INT13_INFO struct
          ExBufferSize WORD ?
          ExFlags WORD ?
          ExCylinders DWORD ?
          ExHeads DWORD ?
          ExSectorsPerTrack DWORD ?
          ExSectorsPerDrive QWORD ?
          ExSectorSize WORD ?
          ExReserved WORD ?
        DISK_EX_INT13_INFO ends
        _DISK_EX_INT13_INFO typedef DISK_EX_INT13_INFO
        PDISK_EX_INT13_INFO typedef ptr DISK_EX_INT13_INFO
        if (_MSC_VER ge 1200)
          ; nonstandard extension used : nameless struct/union
        endif
        DISK_DETECTION_INFO struct
          SizeOfDetectInfo DWORD ?
          DetectionType DETECTION_TYPE ?
          union
            struct
              ; If DetectionType == DETECTION_INT13 then we have just the Int13
              ; information.
              Int13 DISK_INT13_INFO <>
              ; If DetectionType == DETECTION_EX_INT13, then we have the
              ; extended int 13 information.
              ExInt13 DISK_EX_INT13_INFO <>
              ; If DetectionType == DetectExInt13
            ends
          ends
        DISK_DETECTION_INFO ends
        _DISK_DETECTION_INFO typedef DISK_DETECTION_INFO
        PDISK_DETECTION_INFO typedef ptr DISK_DETECTION_INFO
        DISK_PARTITION_INFO struct
          SizeOfPartitionInfo DWORD ?
          PartitionStyle PARTITION_STYLE ?
          ; PartitionStyle = RAW, GPT or MBR
          union
            struct Mbr
              ; If PartitionStyle == MBR
              Signature DWORD ?
              ; MBR Signature
              CheckSum DWORD ?
              ; MBR CheckSum
            ends
            struct Gpt
              ; If PartitionStyle == GPT
              DiskId GUID <>
            ends
          ends
        DISK_PARTITION_INFO ends
        _DISK_PARTITION_INFO typedef DISK_PARTITION_INFO
        PDISK_PARTITION_INFO typedef ptr DISK_PARTITION_INFO
        if (_MSC_VER ge 1200)
        endif
        ; The Geometry structure is a variable length structure composed of a
        ; DISK_GEOMETRY_EX structure followed by a DISK_PARTITION_INFO structure
        ; followed by a DISK_DETECTION_DATA structure.
        if (NTDDI_VERSION lt NTDDI_WS03)
          DiskGeometryGetPartition macro Geometry
            exitm <((PDISK_PARTITION_INFO) ((Geometry) + 1))>
          endm
          DiskGeometryGetDetect macro Geometry
            exitm <((PDISK_DETECTION_INFO) ((DiskGeometryGetPartition(Geometry) + DiskGeometryGetPartition(Geometry) - SizeOfPartitionInfo)))>
          endm
        else
          DiskGeometryGetPartition macro Geometry
            exitm <((PDISK_PARTITION_INFO) ((Geometry) - Data))>
          endm
          DiskGeometryGetDetect macro Geometry
            exitm <((PDISK_DETECTION_INFO) ((DiskGeometryGetPartition(Geometry) + DiskGeometryGetPartition(Geometry) - SizeOfPartitionInfo)))>
          endm
        endif
        DISK_GEOMETRY_EX struct
          Geometry DISK_GEOMETRY <>
          ; Standard disk geometry: may be faked by driver.
          DiskSize LARGE_INTEGER <>
          ; Must always be correct
          Data BYTE 1 dup (?)
          ; Partition, Detect info
        DISK_GEOMETRY_EX ends
        _DISK_GEOMETRY_EX typedef DISK_GEOMETRY_EX
        PDISK_GEOMETRY_EX typedef ptr DISK_GEOMETRY_EX
      endif
      ; (_WIN32_WINNT > 0x0500)
      if (_WIN32_WINNT ge 0400h)
        ; IOCTL_DISK_CONTROLLER_NUMBER returns the controller and disk
        ; number for the handle.  This is used to determine if a disk
        ; is attached to the primary or secondary IDE controller.
        DISK_CONTROLLER_NUMBER struct
          ControllerNumber DWORD ?
          DiskNumber DWORD ?
        DISK_CONTROLLER_NUMBER ends
        _DISK_CONTROLLER_NUMBER typedef DISK_CONTROLLER_NUMBER
        PDISK_CONTROLLER_NUMBER typedef ptr DISK_CONTROLLER_NUMBER
        ;* _WIN32_WINNT >= 0x0400 *
      endif
      if (_WIN32_WINNT ge 0500h)
        ; IOCTL_DISK_SET_CACHE_INFORMATION
        ; Input Buffer:
        ;      A DISK_CACHE_INFORMATION structure which describes how the disk
        ;      read/write caches should be configured.
        ; Output Buffer:
        ;      None
        ; IOCTL_DISK_GET_CACHE_INFORMATION
        ; Input Buffer:
        ;      None
        ; Output Buffer:
        ;      A DISK_CACHE_INFORMATION structure which contains the current state
        ;      of the disk read/write caches.
        DISK_CACHE_RETENTION_PRIORITY typedef SDWORD
        EqualPriority equ 0
        KeepPrefetchedData equ 1
        KeepReadData equ 2

        if (OSVER(NTDDI_VERSION) eq NTDDI_WINXP)
          DISK_WRITE_CACHE_STATE typedef SDWORD
          DiskWriteCacheNormal equ 0
          DiskWriteCacheForceDisable equ 1
          DiskWriteCacheDisableNotSupported equ 2
          _DISK_WRITE_CACHE_STATE typedef DISK_WRITE_CACHE_STATE
          PDISK_WRITE_CACHE_STATE typedef ptr DISK_WRITE_CACHE_STATE
        endif
        DISK_CACHE_INFORMATION struct
          ; on return indicates that the device is capable of saving any parameters
          ; in non-volatile storage.  On send indicates that the device should
          ; save the state in non-volatile storage.
          ParametersSavable BYTE ?
          ; Indicates whether the write and read caches are enabled.
          ReadCacheEnabled BYTE ?
          WriteCacheEnabled BYTE ?
          ; Controls the likelyhood of data remaining in the cache depending on how
          ; it got there.  Data cached from a READ or WRITE operation may be given
          ; higher, lower or equal priority to data entered into the cache for other
          ; means (like prefetch)
          ReadRetentionPriority DISK_CACHE_RETENTION_PRIORITY ?
          WriteRetentionPriority DISK_CACHE_RETENTION_PRIORITY ?
          ; Requests for a larger number of blocks than this may have prefetching
          ; disabled.  If this value is set to 0 prefetch will be disabled.
          DisablePrefetchTransferLength WORD ?
          ; If TRUE then ScalarPrefetch (below) will be valid.  If FALSE then
          ; the minimum and maximum values should be treated as a block count
          ; (BlockPrefetch)
          PrefetchScalar BYTE ?
          ; Contains the minimum and maximum amount of data which will be
          ; will be prefetched into the cache on a disk operation.  This value
          ; may either be a scalar multiplier of the transfer length of the request,
          ; or an abolute number of disk blocks.  PrefetchScalar (above) indicates
          ; which interpretation is used.
          union
            struct ScalarPrefetch
              Minimum WORD ?
              Maximum WORD ?
              ; The maximum number of blocks which will be prefetched - useful
              ; with the scalar limits to set definite upper limits.
              MaximumBlocks WORD ?
            ends
            struct BlockPrefetch
              Minimum WORD ?
              Maximum WORD ?
            ends
          ends
        DISK_CACHE_INFORMATION ends
        _DISK_CACHE_INFORMATION typedef DISK_CACHE_INFORMATION
        PDISK_CACHE_INFORMATION typedef ptr DISK_CACHE_INFORMATION
        ; IOCTL_DISK_GROW_PARTITION will update the size of a partition
        ; by adding sectors to the length. The number of sectors must be
        ; predetermined by examining PARTITION_INFORMATION.
        DISK_GROW_PARTITION struct
          PartitionNumber DWORD ?
          BytesToGrow LARGE_INTEGER <>
        DISK_GROW_PARTITION ends
        _DISK_GROW_PARTITION typedef DISK_GROW_PARTITION
        PDISK_GROW_PARTITION typedef ptr DISK_GROW_PARTITION
        ;* _WIN32_WINNT >= 0x0500 *
      endif
      ;/////////////////////////////////////////////////////
      ;                                                   //
      ; The following structures define disk performance  //
      ; statistics: specifically the locations of all the //
      ; reads and writes which have occured on the disk.  //
      ;                                                   //
      ; To use these structures, you must issue an IOCTL_ //
      ; DISK_HIST_STRUCTURE (with a DISK_HISTOGRAM) to    //
      ; obtain the basic histogram information. The       //
      ; number of buckets which must allocated is part of //
      ; this structure. Allocate the required number of   //
      ; buckets and call an IOCTL_DISK_HIST_DATA to fill  //
      ; in the data                                       //
      ;                                                   //
      ;/////////////////////////////////////////////////////
      HIST_NO_OF_BUCKETS equ 24
      HISTOGRAM_BUCKET struct
        Reads DWORD ?
        Writes DWORD ?
      HISTOGRAM_BUCKET ends
      _HISTOGRAM_BUCKET typedef HISTOGRAM_BUCKET
      PHISTOGRAM_BUCKET typedef ptr HISTOGRAM_BUCKET
      HISTOGRAM_BUCKET_SIZE equ <sizeof(HISTOGRAM_BUCKET)>
      DISK_HISTOGRAM struct
        DiskSize LARGE_INTEGER <>
        Start LARGE_INTEGER <>
        End_ LARGE_INTEGER <>
        Average LARGE_INTEGER <>
        AverageRead LARGE_INTEGER <>
        AverageWrite LARGE_INTEGER <>
        Granularity DWORD ?
        Size_ DWORD ?
        ReadCount DWORD ?
        WriteCount DWORD ?
        Histogram PHISTOGRAM_BUCKET ?
      DISK_HISTOGRAM ends
      _DISK_HISTOGRAM typedef DISK_HISTOGRAM
      PDISK_HISTOGRAM typedef ptr DISK_HISTOGRAM
      DISK_HISTOGRAM_SIZE equ <sizeof(DISK_HISTOGRAM)>
      ;/////////////////////////////////////////////////////
      ;                                                   //
      ; The following structures define disk debugging    //
      ; capabilities. The IOCTLs are directed to one of   //
      ; the two disk filter drivers.                      //
      ;                                                   //
      ; DISKPERF is a utilty for collecting disk request  //
      ; statistics.                                       //
      ;                                                   //
      ; SIMBAD is a utility for injecting faults in       //
      ; IO requests to disks.                             //
      ;                                                   //
      ;/////////////////////////////////////////////////////
      ; The following structure is exchanged on an IOCTL_DISK_GET_PERFORMANCE
      ; request. This ioctl collects summary disk request statistics used
      ; in measuring performance.
      DISK_PERFORMANCE struct
        BytesRead LARGE_INTEGER <>
        BytesWritten LARGE_INTEGER <>
        ReadTime LARGE_INTEGER <>
        WriteTime LARGE_INTEGER <>
        IdleTime LARGE_INTEGER <>
        ReadCount DWORD ?
        WriteCount DWORD ?
        QueueDepth DWORD ?
        SplitCount DWORD ?
        QueryTime LARGE_INTEGER <>
        StorageDeviceNumber DWORD ?
        StorageManagerName WORD 8 dup (?)
      DISK_PERFORMANCE ends
      _DISK_PERFORMANCE typedef DISK_PERFORMANCE
      PDISK_PERFORMANCE typedef ptr DISK_PERFORMANCE
      ; This structure defines the disk logging record. When disk logging
      ; is enabled, one of these is written to an internal buffer for each
      ; disk request.
      DISK_RECORD struct
        ByteOffset LARGE_INTEGER <>
        StartTime LARGE_INTEGER <>
        EndTime LARGE_INTEGER <>
        VirtualAddress POINTER ?
        NumberOfBytes DWORD ?
        DeviceNumber BYTE ?
        ReadRequest BYTE ?
      DISK_RECORD ends
      _DISK_RECORD typedef DISK_RECORD
      PDISK_RECORD typedef ptr DISK_RECORD
      ; The following structure is exchanged on an IOCTL_DISK_LOG request.
      ; Not all fields are valid with each function type.
      DISK_LOGGING struct
        Function BYTE ?
        BufferAddress POINTER ?
        BufferSize DWORD ?
      DISK_LOGGING ends
      _DISK_LOGGING typedef DISK_LOGGING
      PDISK_LOGGING typedef ptr DISK_LOGGING
      ; Disk logging functions
      ; Start disk logging. Only the Function and BufferSize fields are valid.
      DISK_LOGGING_START equ 0
      ; Stop disk logging. Only the Function field is valid.
      DISK_LOGGING_STOP equ 1
      ; Return disk log. All fields are valid. Data will be copied from internal
      ; buffer to buffer specified for the number of bytes requested.
      DISK_LOGGING_DUMP equ 2
      ; DISK BINNING
      ; DISKPERF will keep counters for IO that falls in each of these ranges.
      ; The application determines the number and size of the ranges.
      ; Joe Lin wanted me to keep it flexible as possible, for instance, IO
      ; sizes are interesting in ranges like 0-4096, 4097-16384, 16385-65536, 65537+.
      DISK_BINNING equ 3
      ; Bin types
      BIN_TYPES typedef SDWORD
      RequestSize equ 0
      RequestLocation equ 1
      _BIN_TYPES typedef BIN_TYPES

      ; Bin ranges
      BIN_RANGE struct
        StartValue LARGE_INTEGER <>
        Length_ LARGE_INTEGER <>
      BIN_RANGE ends
      _BIN_RANGE typedef BIN_RANGE
      PBIN_RANGE typedef ptr BIN_RANGE
      ; Bin definition
      PERF_BIN struct
        NumberOfBins DWORD ?
        TypeOfBin DWORD ?
        BinsRanges BIN_RANGE 1 dup (<>)
      PERF_BIN ends
      _PERF_BIN typedef PERF_BIN
      PPERF_BIN typedef ptr PERF_BIN
      ; Bin count
      BIN_COUNT struct
        BinRange BIN_RANGE <>
        BinCount DWORD ?
      BIN_COUNT ends
      _BIN_COUNT typedef BIN_COUNT
      PBIN_COUNT typedef ptr BIN_COUNT
      ; Bin results
      BIN_RESULTS struct
        NumberOfBins DWORD ?
        BinCounts BIN_COUNT 1 dup (<>)
      BIN_RESULTS ends
      _BIN_RESULTS typedef BIN_RESULTS
      PBIN_RESULTS typedef ptr BIN_RESULTS
      if (_WIN32_WINNT ge 0400h)
        ; Data structures for SMART drive fault prediction.
        ; GETVERSIONINPARAMS contains the data returned from the
        ; Get Driver Version function.
        include pshpack1.inc
        GETVERSIONINPARAMS struct
          bVersion BYTE ?
          ; Binary driver version.
          bRevision BYTE ?
          ; Binary driver revision.
          bReserved BYTE ?
          ; Not used.
          bIDEDeviceMap BYTE ?
          ; Bit map of IDE devices.
          fCapabilities DWORD ?
          ; Bit mask of driver capabilities.
          dwReserved DWORD 4 dup (?)
          ; For future use.
        GETVERSIONINPARAMS ends
        _GETVERSIONINPARAMS typedef GETVERSIONINPARAMS
        PGETVERSIONINPARAMS typedef ptr GETVERSIONINPARAMS
        LPGETVERSIONINPARAMS typedef ptr GETVERSIONINPARAMS
        include poppack.inc
        ; Bits returned in the fCapabilities member of GETVERSIONINPARAMS
        CAP_ATA_ID_CMD equ 1; ATA ID command supported

        CAP_ATAPI_ID_CMD equ 2; ATAPI ID command supported

        CAP_SMART_CMD equ 4; SMART commannds supported

        ; IDE registers
        include pshpack1.inc
        IDEREGS struct
          bFeaturesReg BYTE ?
          ; Used for specifying SMART "commands".
          bSectorCountReg BYTE ?
          ; IDE sector count register
          bSectorNumberReg BYTE ?
          ; IDE sector number register
          bCylLowReg BYTE ?
          ; IDE low order cylinder value
          bCylHighReg BYTE ?
          ; IDE high order cylinder value
          bDriveHeadReg BYTE ?
          ; IDE drive/head register
          bCommandReg BYTE ?
          ; Actual IDE command.
          bReserved BYTE ?
          ; reserved for future use.  Must be zero.
        IDEREGS ends
        _IDEREGS typedef IDEREGS
        PIDEREGS typedef ptr IDEREGS
        LPIDEREGS typedef ptr IDEREGS
        include poppack.inc
        ; Valid values for the bCommandReg member of IDEREGS.
        ATAPI_ID_CMD equ 0A1h; Returns ID sector for ATAPI.

        ID_CMD equ 0ECh; Returns ID sector for ATA.

        SMART_CMD equ 0B0h; Performs SMART cmd.

        ; Requires valid bFeaturesReg,
        ; bCylLowReg, and bCylHighReg
        ; Cylinder register defines for SMART command
        SMART_CYL_LOW equ 4Fh
        SMART_CYL_HI equ 0C2h
        ; SENDCMDINPARAMS contains the input parameters for the
        ; Send Command to Drive function.
        include pshpack1.inc
        SENDCMDINPARAMS struct
          cBufferSize DWORD ?
          ; Buffer size in bytes
          irDriveRegs IDEREGS <>
          ; Structure with drive register values.
          bDriveNumber BYTE ?
          ; Physical drive number to send
          ; command to (0,1,2,3).
          bReserved BYTE 3 dup (?)
          ; Reserved for future expansion.
          dwReserved DWORD 4 dup (?)
          ; For future use.
          bBuffer BYTE 1 dup (?)
          ; Input buffer.
        SENDCMDINPARAMS ends
        _SENDCMDINPARAMS typedef SENDCMDINPARAMS
        PSENDCMDINPARAMS typedef ptr SENDCMDINPARAMS
        LPSENDCMDINPARAMS typedef ptr SENDCMDINPARAMS
        include poppack.inc
        ; Status returned from driver
        include pshpack1.inc
        DRIVERSTATUS struct
          bDriverError BYTE ?
          ; Error code from driver,
          ; or 0 if no error.
          bIDEError BYTE ?
          ; Contents of IDE Error register.
          ; Only valid when bDriverError
          ; is SMART_IDE_ERROR.
          bReserved BYTE 2 dup (?)
          ; Reserved for future expansion.
          dwReserved DWORD 2 dup (?)
          ; Reserved for future expansion.
        DRIVERSTATUS ends
        _DRIVERSTATUS typedef DRIVERSTATUS
        PDRIVERSTATUS typedef ptr DRIVERSTATUS
        LPDRIVERSTATUS typedef ptr DRIVERSTATUS
        include poppack.inc
        ; bDriverError values
        SMART_NO_ERROR equ 0; No error

        SMART_IDE_ERROR equ 1; Error from IDE controller

        SMART_INVALID_FLAG equ 2; Invalid command flag

        SMART_INVALID_COMMAND equ 3; Invalid command byte

        SMART_INVALID_BUFFER equ 4; Bad buffer (null, invalid addr..)

        SMART_INVALID_DRIVE equ 5; Drive number not valid

        SMART_INVALID_IOCTL equ 6; Invalid IOCTL

        SMART_ERROR_NO_MEM equ 7; Could not lock user's buffer

        SMART_INVALID_REGISTER equ 8; Some IDE Register not valid

        SMART_NOT_SUPPORTED equ 9; Invalid cmd flag set

        SMART_NO_IDE_DEVICE equ 10; Cmd issued to device not present

        ; although drive number is valid
        ; SMART sub commands for execute offline diags
        SMART_OFFLINE_ROUTINE_OFFLINE equ 0
        SMART_SHORT_SELFTEST_OFFLINE equ 1
        SMART_EXTENDED_SELFTEST_OFFLINE equ 2
        SMART_ABORT_OFFLINE_SELFTEST equ 127
        SMART_SHORT_SELFTEST_CAPTIVE equ 129
        SMART_EXTENDED_SELFTEST_CAPTIVE equ 130
        include pshpack1.inc
        SENDCMDOUTPARAMS struct
          cBufferSize DWORD ?
          ; Size of bBuffer in bytes
          DriverStatus DRIVERSTATUS <>
          ; Driver status structure.
          bBuffer BYTE 1 dup (?)
          ; Buffer of arbitrary length in which to store the data read from the                                                                                  // drive.
        SENDCMDOUTPARAMS ends
        _SENDCMDOUTPARAMS typedef SENDCMDOUTPARAMS
        PSENDCMDOUTPARAMS typedef ptr SENDCMDOUTPARAMS
        LPSENDCMDOUTPARAMS typedef ptr SENDCMDOUTPARAMS
        include poppack.inc
        READ_ATTRIBUTE_BUFFER_SIZE equ 512
        IDENTIFY_BUFFER_SIZE equ 512
        READ_THRESHOLD_BUFFER_SIZE equ 512
        SMART_LOG_SECTOR_SIZE equ 512
        ; Feature register defines for SMART "sub commands"
        READ_ATTRIBUTES equ 0D0h
        READ_THRESHOLDS equ 0D1h
        ENABLE_DISABLE_AUTOSAVE equ 0D2h
        SAVE_ATTRIBUTE_VALUES equ 0D3h
        EXECUTE_OFFLINE_DIAGS equ 0D4h
        SMART_READ_LOG equ 0D5h
        SMART_WRITE_LOG equ 0d6h
        ENABLE_SMART equ 0D8h
        DISABLE_SMART equ 0D9h
        RETURN_SMART_STATUS equ 0DAh
        ENABLE_DISABLE_AUTO_OFFLINE equ 0DBh
        ;* _WIN32_WINNT >= 0x0400 *
      endif
      ; IOCTLs to query and modify attributes
      ; associated with the given disk. These
      ; are persisted within the registry.
      IOCTL_DISK_GET_DISK_ATTRIBUTES equ CTL_CODE(IOCTL_DISK_BASE, 003ch, METHOD_BUFFERED, FILE_ANY_ACCESS)
      IOCTL_DISK_SET_DISK_ATTRIBUTES equ CTL_CODE(IOCTL_DISK_BASE, 003dh, METHOD_BUFFERED, FILE_READ_ACCESS or FILE_WRITE_ACCESS)
      DISK_ATTRIBUTE_OFFLINE equ 0000000000000001h
      DISK_ATTRIBUTE_READ_ONLY equ 0000000000000002h
      ; IOCTL_DISK_GET_DISK_ATTRIBUTES
      ; Input Buffer:
      ;     None
      ; Output Buffer:
      ;     Structure of type GET_DISK_ATTRIBUTES
      GET_DISK_ATTRIBUTES struct
        ; Specifies the size of the
        ; structure for versioning.
        Version DWORD ?
        ; Reserved. Must ignore.
        Reserved1 DWORD ?
        ; Specifies the attributes
        ; associated with the disk.
        Attributes QWORD ?
      GET_DISK_ATTRIBUTES ends
      _GET_DISK_ATTRIBUTES typedef GET_DISK_ATTRIBUTES
      PGET_DISK_ATTRIBUTES typedef ptr GET_DISK_ATTRIBUTES
      ; IOCTL_DISK_SET_DISK_ATTRIBUTES
      ; Input Buffer:
      ;     Structure of type SET_DISK_ATTRIBUTES
      ; Output Buffer:
      ;     None
      SET_DISK_ATTRIBUTES struct
        ; Specifies the size of the
        ; structure for versioning.
        Version DWORD ?
        ; Indicates whether to remember
        ; these settings across reboots
        ; or not.
        Persist BYTE ?
        ; Reserved. Must set to zero.
        Reserved1 BYTE 3 dup (?)
        ; Specifies the new attributes.
        Attributes QWORD ?
        ; Specifies the attributes
        ; that are being modified.
        AttributesMask QWORD ?
        ; Reserved. Must set to zero.
        Reserved2 DWORD 4 dup (?)
      SET_DISK_ATTRIBUTES ends
      _SET_DISK_ATTRIBUTES typedef SET_DISK_ATTRIBUTES
      PSET_DISK_ATTRIBUTES typedef ptr SET_DISK_ATTRIBUTES
      IOCTL_DISK_RESET_SNAPSHOT_INFO equ CTL_CODE(IOCTL_DISK_BASE, 0084h, METHOD_BUFFERED, FILE_READ_ACCESS or FILE_WRITE_ACCESS)
      if Defined(_MSC_VER)
        if (_MSC_VER ge 1200)
        endif
      endif
      ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP | WINAPI_PARTITION_SYSTEM) *
    endif
  endif
  ; _NTDDDISK_H_
  IOCTL_CHANGER_BASE equ <FILE_DEVICE_CHANGER>
  IOCTL_CHANGER_GET_PARAMETERS equ CTL_CODE(IOCTL_CHANGER_BASE, 0000h, METHOD_BUFFERED, FILE_READ_ACCESS)
  IOCTL_CHANGER_GET_STATUS equ CTL_CODE(IOCTL_CHANGER_BASE, 0001h, METHOD_BUFFERED, FILE_READ_ACCESS)
  IOCTL_CHANGER_GET_PRODUCT_DATA equ CTL_CODE(IOCTL_CHANGER_BASE, 0002h, METHOD_BUFFERED, FILE_READ_ACCESS)
  IOCTL_CHANGER_SET_ACCESS equ CTL_CODE(IOCTL_CHANGER_BASE, 0004h, METHOD_BUFFERED, FILE_READ_ACCESS or FILE_WRITE_ACCESS)
  IOCTL_CHANGER_GET_ELEMENT_STATUS equ CTL_CODE(IOCTL_CHANGER_BASE, 0005h, METHOD_BUFFERED, FILE_READ_ACCESS or FILE_WRITE_ACCESS)
  IOCTL_CHANGER_INITIALIZE_ELEMENT_STATUS equ CTL_CODE(IOCTL_CHANGER_BASE, 0006h, METHOD_BUFFERED, FILE_READ_ACCESS)
  IOCTL_CHANGER_SET_POSITION equ CTL_CODE(IOCTL_CHANGER_BASE, 0007h, METHOD_BUFFERED, FILE_READ_ACCESS)
  IOCTL_CHANGER_EXCHANGE_MEDIUM equ CTL_CODE(IOCTL_CHANGER_BASE, 0008h, METHOD_BUFFERED, FILE_READ_ACCESS)
  IOCTL_CHANGER_MOVE_MEDIUM equ CTL_CODE(IOCTL_CHANGER_BASE, 0009h, METHOD_BUFFERED, FILE_READ_ACCESS)
  IOCTL_CHANGER_REINITIALIZE_TRANSPORT equ CTL_CODE(IOCTL_CHANGER_BASE, 000Ah, METHOD_BUFFERED, FILE_READ_ACCESS)
  IOCTL_CHANGER_QUERY_VOLUME_TAGS equ CTL_CODE(IOCTL_CHANGER_BASE, 000Bh, METHOD_BUFFERED, FILE_READ_ACCESS or FILE_WRITE_ACCESS)
  MAX_VOLUME_ID_SIZE equ 36
  MAX_VOLUME_TEMPLATE_SIZE equ 40
  VENDOR_ID_LENGTH equ 8
  PRODUCT_ID_LENGTH equ 16
  REVISION_LENGTH equ 4
  SERIAL_NUMBER_LENGTH equ 32
  ; Common structures describing elements.
  ELEMENT_TYPE typedef SDWORD
  AllElements equ 0
  ; As defined by SCSI
  ChangerTransport equ 1
  ; As defined by SCSI
  ChangerSlot equ 2
  ; As defined by SCSI
  ChangerIEPort equ 3
  ; As defined by SCSI
  ChangerDrive equ 4
  ; As defined by SCSI
  ChangerDoor equ 5
  ; Front panel, used to access internal of cabinet.
  ChangerKeypad equ 6
  ; Keypad/input on front panel.
  ChangerMaxElement equ 7
  _ELEMENT_TYPE typedef ELEMENT_TYPE
  PELEMENT_TYPE typedef ptr ELEMENT_TYPE
  ; Placeholder only. Not a valid type.
  CHANGER_ELEMENT struct
    ElementType ELEMENT_TYPE ?
    ElementAddress DWORD ?
  CHANGER_ELEMENT ends
  _CHANGER_ELEMENT typedef CHANGER_ELEMENT
  PCHANGER_ELEMENT typedef ptr CHANGER_ELEMENT
  CHANGER_ELEMENT_LIST struct
    Element CHANGER_ELEMENT <>
    NumberOfElements DWORD ?
  CHANGER_ELEMENT_LIST ends
  _CHANGER_ELEMENT_LIST typedef CHANGER_ELEMENT_LIST
  PCHANGER_ELEMENT_LIST typedef ptr CHANGER_ELEMENT_LIST
  ; Definitions for  IOCTL_CHANGER_GET_PARAMETERS
  ; Definitions for Features0 of GET_CHANGER_PARAMETERS
  CHANGER_BAR_CODE_SCANNER_INSTALLED equ 00000001h; The medium-changer has a bar code scanner installed.

  CHANGER_INIT_ELEM_STAT_WITH_RANGE equ 00000002h; The medium-changer has the ability to initialize elements within a specified range.

  CHANGER_CLOSE_IEPORT equ 00000004h; The medium-changer has the ability to close the i/e port door.

  CHANGER_OPEN_IEPORT equ 00000008h; The medium-changer can open the i/e port door.

  CHANGER_STATUS_NON_VOLATILE equ 00000010h; The medium-changer uses non-volatile memory for element status information.

  CHANGER_EXCHANGE_MEDIA equ 00000020h; The medium-changer supports exchange operations.

  CHANGER_CLEANER_SLOT equ 00000040h; The medium-changer has a fixed slot designated for cleaner cartridges.

  CHANGER_LOCK_UNLOCK equ 00000080h; The medium-changer can be (un)secured to (allow)prevent media removal.

  CHANGER_CARTRIDGE_MAGAZINE equ 00000100h; The medium-changer uses cartridge magazines for some storage slots.

  CHANGER_MEDIUM_FLIP equ 00000200h; The medium-changer can flip medium.

  CHANGER_POSITION_TO_ELEMENT equ 00000400h; The medium-changer can position the transport to a particular element.

  CHANGER_REPORT_IEPORT_STATE equ 00000800h; The medium-changer can determine whether media is present

  ; in the IE Port.
  CHANGER_STORAGE_DRIVE equ 00001000h; The medium-changer can use a drive as an independent storage element.

  CHANGER_STORAGE_IEPORT equ 00002000h; The medium-changer can use a i/e port as an independent storage element.

  CHANGER_STORAGE_SLOT equ 00004000h; The medium-changer can use a slot as an independent storage element.

  CHANGER_STORAGE_TRANSPORT equ 00008000h; The medium-changer can use a transport as an independent storage element.

  CHANGER_DRIVE_CLEANING_REQUIRED equ 00010000h; The drives controlled by the medium changer require periodic cleaning

  ; initiated by an application.
  CHANGER_PREDISMOUNT_EJECT_REQUIRED equ 00020000h; The medium-changer requires a drive eject command to be issued, before a changer

  ; move / exchange command can be issued to the drive.
  CHANGER_CLEANER_ACCESS_NOT_VALID equ 00040000h; The access bit in GES isn't valid for cleaner cartridges.

  CHANGER_PREMOUNT_EJECT_REQUIRED equ 00080000h; The medium-changer requires a drive eject command to be issued

  ; before a move / exchange command can be issued with the drive as src/dst.
  CHANGER_VOLUME_IDENTIFICATION equ 00100000h; The medium-changer supports volume identification.

  CHANGER_VOLUME_SEARCH equ 00200000h; The medium-changer can search for volume information.

  CHANGER_VOLUME_ASSERT equ 00400000h; The medium-changer can verify volume information.

  CHANGER_VOLUME_REPLACE equ 00800000h; The medium-changer can replace volume information.

  CHANGER_VOLUME_UNDEFINE equ 01000000h; The medium-changer can undefine volume information.

  CHANGER_SERIAL_NUMBER_VALID equ 04000000h; The serial number reported in GetProductData is valid

  ; and unique.
  CHANGER_DEVICE_REINITIALIZE_CAPABLE equ 08000000h; The medium-changer can be issued a ChangerReinitializeUnit.

  CHANGER_KEYPAD_ENABLE_DISABLE equ 10000000h; Indicates that the keypad can be enabled/disabled.

  CHANGER_DRIVE_EMPTY_ON_DOOR_ACCESS equ 20000000h; Drives must be empty before access via the door is possible.

  CHANGER_RESERVED_BIT equ 80000000h; Will be used to indicate Features1 capability bits.

  ; Definitions for Features1 of GET_CHANGER_PARAMETERS
  CHANGER_PREDISMOUNT_ALIGN_TO_SLOT equ 80000001h; The transport must be prepositioned to the slot prior to ejecting the media.

  CHANGER_PREDISMOUNT_ALIGN_TO_DRIVE equ 80000002h; The transport must be prepositioned to the drive prior to ejecting the media.

  CHANGER_CLEANER_AUTODISMOUNT equ 80000004h; The device will move the cleaner cartridge back into the slot when cleaning has completed.

  CHANGER_TRUE_EXCHANGE_CAPABLE equ 80000008h; Device can do src -> dest2 exchanges.

  CHANGER_SLOTS_USE_TRAYS equ 80000010h; Slots have removable trays, requiring multiple moves for inject/eject.

  CHANGER_RTN_MEDIA_TO_ORIGINAL_ADDR equ 80000020h; Media must be returned to the slot from which it originated after a move to another element.

  CHANGER_CLEANER_OPS_NOT_SUPPORTED equ 80000040h; Automated cleaning operations are not supported on this device.

  CHANGER_IEPORT_USER_CONTROL_OPEN equ 80000080h; Indicates that user action is necessary to open a closed ieport.

  CHANGER_IEPORT_USER_CONTROL_CLOSE equ 80000100h; Indicates that user action is necessary to close an opened ieport.

  CHANGER_MOVE_EXTENDS_IEPORT equ 80000200h; Indicates that a move media to the ieport extends the tray.

  CHANGER_MOVE_RETRACTS_IEPORT equ 80000400h; Indicates that a move media from the ieport retracts the tray.

  ; Definitions for MoveFrom, ExchangeFrom, and PositionCapabilities
  CHANGER_TO_TRANSPORT equ 01h; The device can carry out the operation to a transport from the specified element.

  CHANGER_TO_SLOT equ 02h; The device can carry out the operation to a slot from the specified element.

  CHANGER_TO_IEPORT equ 04h; The device can carry out the operation to an IE Port from the specified element.

  CHANGER_TO_DRIVE equ 08h; The device can carry out the operation to a drive from the specified element.

  ; Definitions for LockUnlockCapabilities
  LOCK_UNLOCK_IEPORT equ 01h; The device can lock/unlock the ieport(s).

  LOCK_UNLOCK_DOOR equ 02h; The device can lock/unlock the door(s).

  LOCK_UNLOCK_KEYPAD equ 04h; The device can lock/unlock the keypad.

  GET_CHANGER_PARAMETERS struct
    ; Size of the structure. Can be used for versioning.
    Size_ DWORD ?
    ; Number of N element(s) as defined by the Element Address Page (or equivalent...).
    NumberTransportElements WORD ?
    NumberStorageElements WORD ?
    ; for data cartridges only
    NumberCleanerSlots WORD ?
    ; for cleaner cartridges
    NumberIEElements WORD ?
    NumberDataTransferElements WORD ?
    ; Number of doors/front panels (allows user entry into the cabinet).
    NumberOfDoors WORD ?
    ; The device-specific address (from user manual of the device) of the first N element. Used
    ; by the UI to relate the various elements to the user.
    FirstSlotNumber WORD ?
    FirstDriveNumber WORD ?
    FirstTransportNumber WORD ?
    FirstIEPortNumber WORD ?
    FirstCleanerSlotAddress WORD ?
    ; Indicates the capacity of each magazine, if they exist.
    MagazineSize WORD ?
    ; Specifies the approximate number of seconds for when a cleaning should be completed.
    ; Only applicable if drive cleaning is supported. See Features0.
    DriveCleanTimeout DWORD ?
    ; See features bits, above.
    Features0 DWORD ?
    Features1 DWORD ?
    ; Bitmask defining Move from N element to element. Defined by Device Capabilities Page (or equivalent).
    ; AND-masking with the TO_XXX values will indicate legal destinations.
    MoveFromTransport BYTE ?
    MoveFromSlot BYTE ?
    MoveFromIePort BYTE ?
    MoveFromDrive BYTE ?
    ; Bitmask defining Exchange from N element to element. Defined by Device Capabilities Page (or equivalent).
    ; AND-masking with the TO_XXX values will indicate legal destinations.
    ExchangeFromTransport BYTE ?
    ExchangeFromSlot BYTE ?
    ExchangeFromIePort BYTE ?
    ExchangeFromDrive BYTE ?
    ; Bitmask defining which elements are capable of lock/unlock. Valid only if
    ; CHANGER_LOCK_UNLOCK is set in Features0.
    LockUnlockCapabilities BYTE ?
    ; Bitmask defining which elements valid for positioning operations. Valid only if
    ; CHANGER_POSITION_TO_ELEMENT is set in Features0.
    PositionCapabilities BYTE ?
    ; For future expansion.
    Reserved1 BYTE 2 dup (?)
    Reserved2 DWORD 2 dup (?)
  GET_CHANGER_PARAMETERS ends
  _GET_CHANGER_PARAMETERS typedef GET_CHANGER_PARAMETERS
  PGET_CHANGER_PARAMETERS typedef ptr GET_CHANGER_PARAMETERS
  ; Definitions for IOCTL_CHANGER_GET_PRODUCT_DATA
  CHANGER_PRODUCT_DATA struct
    ; Device manufacturer's name - based on inquiry data
    VendorId BYTE VENDOR_ID_LENGTH dup (?)
    ; Product identification as defined by the vendor - based on Inquiry data
    ProductId BYTE PRODUCT_ID_LENGTH dup (?)
    ; Product revision as defined by the vendor.
    Revision BYTE REVISION_LENGTH dup (?)
    ; Vendor unique value used to globally identify this device. Can
    ; be from Vital Product Data, for example.
    SerialNumber BYTE SERIAL_NUMBER_LENGTH dup (?)
    ; Indicates device type of data transports, as defined by SCSI-2.
    DeviceType BYTE ?
  CHANGER_PRODUCT_DATA ends
  _CHANGER_PRODUCT_DATA typedef CHANGER_PRODUCT_DATA
  PCHANGER_PRODUCT_DATA typedef ptr CHANGER_PRODUCT_DATA
  ; Definitions for IOCTL_CHANGER_SET_ACCESS
  LOCK_ELEMENT equ 0
  UNLOCK_ELEMENT equ 1
  EXTEND_IEPORT equ 2
  RETRACT_IEPORT equ 3
  CHANGER_SET_ACCESS struct
    ; Element can be ChangerIEPort, ChangerDoor, ChangerKeypad
    Element CHANGER_ELEMENT <>
    ; See above for possible operations.
    Control DWORD ?
  CHANGER_SET_ACCESS ends
  _CHANGER_SET_ACCESS typedef CHANGER_SET_ACCESS
  PCHANGER_SET_ACCESS typedef ptr CHANGER_SET_ACCESS
  ; Definitions for IOCTL_CHANGER_GET_ELEMENT_STATUS
  ; Input buffer.
  CHANGER_READ_ELEMENT_STATUS struct
    ; List describing the elements and range on which to return information.
    ElementList CHANGER_ELEMENT_LIST <>
    ; Indicates whether volume tag information is to be returned.
    VolumeTagInfo BYTE ?
  CHANGER_READ_ELEMENT_STATUS ends
  _CHANGER_READ_ELEMENT_STATUS typedef CHANGER_READ_ELEMENT_STATUS
  PCHANGER_READ_ELEMENT_STATUS typedef ptr CHANGER_READ_ELEMENT_STATUS
  ; Output buffer.
  CHANGER_ELEMENT_STATUS struct
    ; Element to which this structure refers.
    Element CHANGER_ELEMENT <>
    ; Address of the element from which the media was originally moved.
    ; Valid if ELEMENT_STATUS_SVALID bit of Flags DWORD is set.
    ; Needs to be converted to a zero-based offset from the device-unique value.
    SrcElementAddress CHANGER_ELEMENT <>
    ; See below.
    Flags DWORD ?
    ; See below for possible values.
    ExceptionCode DWORD ?
    ; Scsi Target Id of this element.
    ; Valid only if ELEMENT_STATUS_ID_VALID is set in Flags.
    TargetId BYTE ?
    ; LogicalUnitNumber of this element.
    ; Valid only if ELEMENT_STATUS_LUN_VALID is set in Flags.
    Lun BYTE ?
    Reserved WORD ?
    ; Primary volume identification for the media.
    ; Valid only if ELEMENT_STATUS_PVOLTAG bit is set in Flags.
    PrimaryVolumeID BYTE MAX_VOLUME_ID_SIZE dup (?)
    ; Alternate volume identification for the media.
    ; Valid for two-sided media only, and pertains to the id. of the inverted side.
    ; Valid only if ELEMENT_STATUS_AVOLTAG bit is set in Flags.
    AlternateVolumeID BYTE MAX_VOLUME_ID_SIZE dup (?)
  CHANGER_ELEMENT_STATUS ends
  _CHANGER_ELEMENT_STATUS typedef CHANGER_ELEMENT_STATUS
  PCHANGER_ELEMENT_STATUS typedef ptr CHANGER_ELEMENT_STATUS
  ; Output buffer. This is same as CHANGER_ELEMENT_STATUS with
  ; the addition of product info fields. New applications should
  ; use this struct instead of the older CHANGER_ELEMENT_STATUS
  CHANGER_ELEMENT_STATUS_EX struct
    ; Element to which this structure refers.
    Element CHANGER_ELEMENT <>
    ; Address of the element from which the media was originally moved.
    ; Valid if ELEMENT_STATUS_SVALID bit of Flags DWORD is set.
    ; Needs to be converted to a zero-based offset from the device-unique value.
    SrcElementAddress CHANGER_ELEMENT <>
    ; See below.
    Flags DWORD ?
    ; See below for possible values.
    ExceptionCode DWORD ?
    ; Scsi Target Id of this element.
    ; Valid only if ELEMENT_STATUS_ID_VALID is set in Flags.
    TargetId BYTE ?
    ; LogicalUnitNumber of this element.
    ; Valid only if ELEMENT_STATUS_LUN_VALID is set in Flags.
    Lun BYTE ?
    Reserved WORD ?
    ; Primary volume identification for the media.
    ; Valid only if ELEMENT_STATUS_PVOLTAG bit is set in Flags.
    PrimaryVolumeID BYTE MAX_VOLUME_ID_SIZE dup (?)
    ; Alternate volume identification for the media.
    ; Valid for two-sided media only, and pertains to the id. of the inverted side.
    ; Valid only if ELEMENT_STATUS_AVOLTAG bit is set in Flags.
    AlternateVolumeID BYTE MAX_VOLUME_ID_SIZE dup (?)
    ; Vendor ID
    VendorIdentification BYTE VENDOR_ID_LENGTH dup (?)
    ; Product ID
    ProductIdentification BYTE PRODUCT_ID_LENGTH dup (?)
    ; Serial number
    SerialNumber BYTE SERIAL_NUMBER_LENGTH dup (?)
  CHANGER_ELEMENT_STATUS_EX ends
  _CHANGER_ELEMENT_STATUS_EX typedef CHANGER_ELEMENT_STATUS_EX
  PCHANGER_ELEMENT_STATUS_EX typedef ptr CHANGER_ELEMENT_STATUS_EX
  ; Possible flag values
  ELEMENT_STATUS_FULL equ 00000001h; Element contains a unit of media.

  ELEMENT_STATUS_IMPEXP equ 00000002h; Media in i/e port was placed there by an operator.

  ELEMENT_STATUS_EXCEPT equ 00000004h; Element is in an abnormal state; check ExceptionCode field for more information.

  ELEMENT_STATUS_ACCESS equ 00000008h; Access to the i/e port from the medium changer is allowed.

  ELEMENT_STATUS_EXENAB equ 00000010h; Export of media is supported.

  ELEMENT_STATUS_INENAB equ 00000020h; Import of media is supported.

  ELEMENT_STATUS_PRODUCT_DATA equ 00000040h; Serial number valid for the drive

  ELEMENT_STATUS_LUN_VALID equ 00001000h; Lun information is valid.

  ELEMENT_STATUS_ID_VALID equ 00002000h; SCSI Id information is valid.

  ELEMENT_STATUS_NOT_BUS equ 00008000h; Lun and SCSI Id fields are not on same bus as medium changer.

  ELEMENT_STATUS_INVERT equ 00400000h; Media in element was inverted (valid only if ELEMENT_STATUS_SVALID bit is set)

  ELEMENT_STATUS_SVALID equ 00800000h; SourceElementAddress field and ELEMENT_STATUS_INVERT bit are valid.

  ELEMENT_STATUS_PVOLTAG equ 10000000h; Primary volume information is valid.

  ELEMENT_STATUS_AVOLTAG equ 20000000h; Alternate volume information is valid.

  ; ExceptionCode values.
  ERROR_LABEL_UNREADABLE equ 00000001h; Bar code scanner could not read bar code label.

  ERROR_LABEL_QUESTIONABLE equ 00000002h; Label could be invalid due to unit attention condition.

  ERROR_SLOT_NOT_PRESENT equ 00000004h; Slot is currently not addressable in the device.

  ERROR_DRIVE_NOT_INSTALLED equ 00000008h; Drive is not installed.

  ERROR_TRAY_MALFUNCTION equ 00000010h; Media tray is malfunctioning/broken.

  ERROR_INIT_STATUS_NEEDED equ 00000011h; An Initialize Element Status command is needed.

  ERROR_UNHANDLED_ERROR equ 0FFFFFFFFh; Unknown error condition

  ; Definitions for IOCTL_CHANGER_INITIALIZE_ELEMENT_STATUS
  CHANGER_INITIALIZE_ELEMENT_STATUS struct
    ; List describing the elements and range on which to initialize.
    ElementList CHANGER_ELEMENT_LIST <>
    ; Indicates whether a bar code scan should be used. Only applicable if
    ; CHANGER_BAR_CODE_SCANNER_INSTALLED is set in Features0 of CHANGER_GET_PARAMETERS.
    BarCodeScan BYTE ?
  CHANGER_INITIALIZE_ELEMENT_STATUS ends
  _CHANGER_INITIALIZE_ELEMENT_STATUS typedef CHANGER_INITIALIZE_ELEMENT_STATUS
  PCHANGER_INITIALIZE_ELEMENT_STATUS typedef ptr CHANGER_INITIALIZE_ELEMENT_STATUS
  ; Definitions for IOCTL_CHANGER_SET_POSITION
  CHANGER_SET_POSITION struct
    ; Indicates which transport to move.
    Transport CHANGER_ELEMENT <>
    ; Indicates the final destination of the transport.
    Destination CHANGER_ELEMENT <>
    ; Indicates whether the media currently carried by Transport, should be flipped.
    Flip BYTE ?
  CHANGER_SET_POSITION ends
  _CHANGER_SET_POSITION typedef CHANGER_SET_POSITION
  PCHANGER_SET_POSITION typedef ptr CHANGER_SET_POSITION
  ; Definitions for IOCTL_CHANGER_EXCHANGE_MEDIUM
  CHANGER_EXCHANGE_MEDIUM struct
    ; Indicates which transport to use for the exchange operation.
    Transport CHANGER_ELEMENT <>
    ; Indicates the source for the media that is to be moved.
    Source CHANGER_ELEMENT <>
    ; Indicates the final destination of the media originally at Source.
    Destination1 CHANGER_ELEMENT <>
    ; Indicates the destination of the media moved from Destination1.
    Destination2 CHANGER_ELEMENT <>
    ; Indicates whether the medium should be flipped.
    Flip1 BYTE ?
    Flip2 BYTE ?
  CHANGER_EXCHANGE_MEDIUM ends
  _CHANGER_EXCHANGE_MEDIUM typedef CHANGER_EXCHANGE_MEDIUM
  PCHANGER_EXCHANGE_MEDIUM typedef ptr CHANGER_EXCHANGE_MEDIUM
  ; Definitions for IOCTL_CHANGER_MOVE_MEDIUM
  CHANGER_MOVE_MEDIUM struct
    ; Indicates which transport to use for the move operation.
    Transport CHANGER_ELEMENT <>
    ; Indicates the source for the media that is to be moved.
    Source CHANGER_ELEMENT <>
    ; Indicates the destination of the media originally at Source.
    Destination CHANGER_ELEMENT <>
    ; Indicates whether the media should be flipped.
    Flip BYTE ?
  CHANGER_MOVE_MEDIUM ends
  _CHANGER_MOVE_MEDIUM typedef CHANGER_MOVE_MEDIUM
  PCHANGER_MOVE_MEDIUM typedef ptr CHANGER_MOVE_MEDIUM
  ; Definitions for IOCTL_QUERY_VOLUME_TAGS
  ; Input buffer.
  CHANGER_SEND_VOLUME_TAG_INFORMATION struct
    ; Describes the starting element for which to return information.
    StartingElement CHANGER_ELEMENT <>
    ; Indicates the specific action to perform. See below.
    ActionCode DWORD ?
    ; Template used by the device to search for volume ids.
    VolumeIDTemplate BYTE MAX_VOLUME_TEMPLATE_SIZE dup (?)
  CHANGER_SEND_VOLUME_TAG_INFORMATION ends
  _CHANGER_SEND_VOLUME_TAG_INFORMATION typedef CHANGER_SEND_VOLUME_TAG_INFORMATION
  PCHANGER_SEND_VOLUME_TAG_INFORMATION typedef ptr CHANGER_SEND_VOLUME_TAG_INFORMATION
  ; Output buffer.
  READ_ELEMENT_ADDRESS_INFO struct
    ; Number of elements matching criteria set forth by ActionCode.
    NumberOfElements DWORD ?
    ; Array of CHANGER_ELEMENT_STATUS structures, one for each element that corresponded
    ; with the information passed in with the CHANGER_SEND_VOLUME_TAG_INFORMATION structure.
    ElementStatus CHANGER_ELEMENT_STATUS 1 dup (<>)
  READ_ELEMENT_ADDRESS_INFO ends
  _READ_ELEMENT_ADDRESS_INFO typedef READ_ELEMENT_ADDRESS_INFO
  PREAD_ELEMENT_ADDRESS_INFO typedef ptr READ_ELEMENT_ADDRESS_INFO
  ; Possible ActionCode values. See Features0 of CHANGER_GET_PARAMETERS for compatibility with
  ; the current device.
  SEARCH_ALL equ 0h; Translate - search all defined volume tags.

  SEARCH_PRIMARY equ 1h; Translate - search only primary volume tags.

  SEARCH_ALTERNATE equ 2h; Translate - search only alternate volume tags.

  SEARCH_ALL_NO_SEQ equ 4h; Translate - search all defined volume tags but ignore sequence numbers.

  SEARCH_PRI_NO_SEQ equ 5h; Translate - search only primary volume tags but ignore sequence numbers.

  SEARCH_ALT_NO_SEQ equ 6h; Translate - search only alternate volume tags but ignore sequence numbers.

  ASSERT_PRIMARY equ 8h; Assert - as the primary volume tag - if tag now undefined.

  ASSERT_ALTERNATE equ 9h; Assert - as the alternate volume tag - if tag now undefined.

  REPLACE_PRIMARY equ 0Ah; Replace - the primary volume tag - current tag ignored.

  REPLACE_ALTERNATE equ 0Bh; Replace - the alternate volume tag - current tag ignored.

  UNDEFINE_PRIMARY equ 0Ch; Undefine - the primary volume tag - current tag ignored.

  UNDEFINE_ALTERNATE equ 0Dh; Undefine - the alternate volume tag - current tag ignored.

  ; Changer diagnostic test related definitions
  CHANGER_DEVICE_PROBLEM_TYPE typedef SDWORD
  DeviceProblemNone equ 0
  DeviceProblemHardware equ 1
  DeviceProblemCHMError equ 2
  DeviceProblemDoorOpen equ 3
  DeviceProblemCalibrationError equ 4
  DeviceProblemTargetFailure equ 5
  DeviceProblemCHMMoveError equ 6
  DeviceProblemCHMZeroError equ 7
  DeviceProblemCartridgeInsertError equ 8
  DeviceProblemPositionError equ 9
  DeviceProblemSensorError equ 10
  DeviceProblemCartridgeEjectError equ 11
  DeviceProblemGripperError equ 12
  DeviceProblemDriveError equ 13
  _CHANGER_DEVICE_PROBLEM_TYPE typedef CHANGER_DEVICE_PROBLEM_TYPE
  PCHANGER_DEVICE_PROBLEM_TYPE typedef ptr CHANGER_DEVICE_PROBLEM_TYPE
  IOCTL_SERIAL_LSRMST_INSERT equ CTL_CODE(FILE_DEVICE_SERIAL_PORT, 31, METHOD_BUFFERED, FILE_ANY_ACCESS)
  IOCTL_SERENUM_EXPOSE_HARDWARE equ CTL_CODE(FILE_DEVICE_SERENUM, 128, METHOD_BUFFERED, FILE_ANY_ACCESS)
  IOCTL_SERENUM_REMOVE_HARDWARE equ CTL_CODE(FILE_DEVICE_SERENUM, 129, METHOD_BUFFERED, FILE_ANY_ACCESS)
  IOCTL_SERENUM_PORT_DESC equ CTL_CODE(FILE_DEVICE_SERENUM, 130, METHOD_BUFFERED, FILE_ANY_ACCESS)
  IOCTL_SERENUM_GET_PORT_NAME equ CTL_CODE(FILE_DEVICE_SERENUM, 131, METHOD_BUFFERED, FILE_ANY_ACCESS)
  ; The following values follow the escape designator in the
  ; data stream if the LSRMST_INSERT mode has been turned on.
  SERIAL_LSRMST_ESCAPE equ (00h)
  ; Following this value is the contents of the line status
  ; register, and then the character in the RX hardware when
  ; the line status register was encountered.
  SERIAL_LSRMST_LSR_DATA equ (01h)
  ; Following this value is the contents of the line status
  ; register.  No error character follows
  SERIAL_LSRMST_LSR_NODATA equ (02h)
  ; Following this value is the contents of the modem status
  ; register.
  SERIAL_LSRMST_MST equ (03h)
  ; Bit values for FIFO Control Register
  SERIAL_IOC_FCR_FIFO_ENABLE equ (00000001h)
  SERIAL_IOC_FCR_RCVR_RESET equ (00000002h)
  SERIAL_IOC_FCR_XMIT_RESET equ (00000004h)
  SERIAL_IOC_FCR_DMA_MODE equ (00000008h)
  SERIAL_IOC_FCR_RES1 equ (00000010h)
  SERIAL_IOC_FCR_RES2 equ (00000020h)
  SERIAL_IOC_FCR_RCVR_TRIGGER_LSB equ (00000040h)
  SERIAL_IOC_FCR_RCVR_TRIGGER_MSB equ (00000080h)
  ; Bit values for Modem Control Register
  SERIAL_IOC_MCR_DTR equ (00000001h)
  SERIAL_IOC_MCR_RTS equ (00000002h)
  SERIAL_IOC_MCR_OUT1 equ (00000004h)
  SERIAL_IOC_MCR_OUT2 equ (00000008h)
  SERIAL_IOC_MCR_LOOP equ (00000010h)
  ifndef _FILESYSTEMFSCTL_
    _FILESYSTEMFSCTL_ equ <>
    ; The following is a list of the native file system fsctls followed by
    ; additional network file system fsctls.  Some values have been
    ; decommissioned.
    FSCTL_REQUEST_OPLOCK_LEVEL_1 equ CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 0, METHOD_BUFFERED, FILE_ANY_ACCESS)
    FSCTL_REQUEST_OPLOCK_LEVEL_2 equ CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 1, METHOD_BUFFERED, FILE_ANY_ACCESS)
    FSCTL_REQUEST_BATCH_OPLOCK equ CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 2, METHOD_BUFFERED, FILE_ANY_ACCESS)
    FSCTL_OPLOCK_BREAK_ACKNOWLEDGE equ CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 3, METHOD_BUFFERED, FILE_ANY_ACCESS)
    FSCTL_OPBATCH_ACK_CLOSE_PENDING equ CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 4, METHOD_BUFFERED, FILE_ANY_ACCESS)
    FSCTL_OPLOCK_BREAK_NOTIFY equ CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 5, METHOD_BUFFERED, FILE_ANY_ACCESS)
    FSCTL_LOCK_VOLUME equ CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 6, METHOD_BUFFERED, FILE_ANY_ACCESS)
    FSCTL_UNLOCK_VOLUME equ CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 7, METHOD_BUFFERED, FILE_ANY_ACCESS)
    FSCTL_DISMOUNT_VOLUME equ CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 8, METHOD_BUFFERED, FILE_ANY_ACCESS)
    ; decommissioned fsctl value                                              9
    FSCTL_IS_VOLUME_MOUNTED equ CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 10, METHOD_BUFFERED, FILE_ANY_ACCESS)
    FSCTL_IS_PATHNAME_VALID equ CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 11, METHOD_BUFFERED, FILE_ANY_ACCESS); PATHNAME_BUFFER,

    FSCTL_MARK_VOLUME_DIRTY equ CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 12, METHOD_BUFFERED, FILE_ANY_ACCESS)
    ; decommissioned fsctl value                                             13
    FSCTL_QUERY_RETRIEVAL_POINTERS equ CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 14, METHOD_NEITHER, FILE_ANY_ACCESS)
    FSCTL_GET_COMPRESSION equ CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 15, METHOD_BUFFERED, FILE_ANY_ACCESS)
    FSCTL_SET_COMPRESSION equ CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 16, METHOD_BUFFERED, FILE_READ_DATA or FILE_WRITE_DATA)
    ; decommissioned fsctl value                                             17
    ; decommissioned fsctl value                                             18
    FSCTL_SET_BOOTLOADER_ACCESSED equ CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 19, METHOD_NEITHER, FILE_ANY_ACCESS)
    FSCTL_MARK_AS_SYSTEM_HIVE equ <FSCTL_SET_BOOTLOADER_ACCESSED>
    FSCTL_OPLOCK_BREAK_ACK_NO_2 equ CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 20, METHOD_BUFFERED, FILE_ANY_ACCESS)
    FSCTL_INVALIDATE_VOLUMES equ CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 21, METHOD_BUFFERED, FILE_ANY_ACCESS)
    FSCTL_QUERY_FAT_BPB equ CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 22, METHOD_BUFFERED, FILE_ANY_ACCESS); FSCTL_QUERY_FAT_BPB_BUFFER

    FSCTL_REQUEST_FILTER_OPLOCK equ CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 23, METHOD_BUFFERED, FILE_ANY_ACCESS)
    FSCTL_FILESYSTEM_GET_STATISTICS equ CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 24, METHOD_BUFFERED, FILE_ANY_ACCESS); FILESYSTEM_STATISTICS

    if (_WIN32_WINNT ge _WIN32_WINNT_NT4)
      FSCTL_GET_NTFS_VOLUME_DATA equ CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 25, METHOD_BUFFERED, FILE_ANY_ACCESS); NTFS_VOLUME_DATA_BUFFER

      FSCTL_GET_NTFS_FILE_RECORD equ CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 26, METHOD_BUFFERED, FILE_ANY_ACCESS); NTFS_FILE_RECORD_INPUT_BUFFER, NTFS_FILE_RECORD_OUTPUT_BUFFER

      FSCTL_GET_VOLUME_BITMAP equ CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 27, METHOD_NEITHER, FILE_ANY_ACCESS); STARTING_LCN_INPUT_BUFFER, VOLUME_BITMAP_BUFFER

      FSCTL_GET_RETRIEVAL_POINTERS equ CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 28, METHOD_NEITHER, FILE_ANY_ACCESS); STARTING_VCN_INPUT_BUFFER, RETRIEVAL_POINTERS_BUFFER

      FSCTL_MOVE_FILE equ CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 29, METHOD_BUFFERED, FILE_SPECIAL_ACCESS); MOVE_FILE_DATA,

      FSCTL_IS_VOLUME_DIRTY equ CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 30, METHOD_BUFFERED, FILE_ANY_ACCESS)
      ; decommissioned fsctl value                                             31
      FSCTL_ALLOW_EXTENDED_DASD_IO equ CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 32, METHOD_NEITHER, FILE_ANY_ACCESS)
      ;* _WIN32_WINNT >= _WIN32_WINNT_NT4 *
    endif
    if (_WIN32_WINNT ge _WIN32_WINNT_WIN2K)
      ; decommissioned fsctl value                                             33
      ; decommissioned fsctl value                                             34
      FSCTL_FIND_FILES_BY_SID equ CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 35, METHOD_NEITHER, FILE_ANY_ACCESS)
      ; decommissioned fsctl value                                             36
      ; decommissioned fsctl value                                             37
      FSCTL_SET_OBJECT_ID equ CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 38, METHOD_BUFFERED, FILE_SPECIAL_ACCESS); FILE_OBJECTID_BUFFER

      FSCTL_GET_OBJECT_ID equ CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 39, METHOD_BUFFERED, FILE_ANY_ACCESS); FILE_OBJECTID_BUFFER

      FSCTL_DELETE_OBJECT_ID equ CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 40, METHOD_BUFFERED, FILE_SPECIAL_ACCESS)
      FSCTL_SET_REPARSE_POINT equ CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 41, METHOD_BUFFERED, FILE_SPECIAL_ACCESS); REPARSE_DATA_BUFFER,

      FSCTL_GET_REPARSE_POINT equ CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 42, METHOD_BUFFERED, FILE_ANY_ACCESS); REPARSE_DATA_BUFFER

      FSCTL_DELETE_REPARSE_POINT equ CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 43, METHOD_BUFFERED, FILE_SPECIAL_ACCESS); REPARSE_DATA_BUFFER,

      FSCTL_ENUM_USN_DATA equ CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 44, METHOD_NEITHER, FILE_ANY_ACCESS); MFT_ENUM_DATA,

      FSCTL_SECURITY_ID_CHECK equ CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 45, METHOD_NEITHER, FILE_READ_DATA); BULK_SECURITY_TEST_DATA,

      FSCTL_READ_USN_JOURNAL equ CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 46, METHOD_NEITHER, FILE_ANY_ACCESS); READ_USN_JOURNAL_DATA, USN

      FSCTL_SET_OBJECT_ID_EXTENDED equ CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 47, METHOD_BUFFERED, FILE_SPECIAL_ACCESS)
      FSCTL_CREATE_OR_GET_OBJECT_ID equ CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 48, METHOD_BUFFERED, FILE_ANY_ACCESS); FILE_OBJECTID_BUFFER

      FSCTL_SET_SPARSE equ CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 49, METHOD_BUFFERED, FILE_SPECIAL_ACCESS)
      FSCTL_SET_ZERO_DATA equ CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 50, METHOD_BUFFERED, FILE_WRITE_DATA); FILE_ZERO_DATA_INFORMATION,

      FSCTL_QUERY_ALLOCATED_RANGES equ CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 51, METHOD_NEITHER, FILE_READ_DATA); FILE_ALLOCATED_RANGE_BUFFER, FILE_ALLOCATED_RANGE_BUFFER

      FSCTL_ENABLE_UPGRADE equ CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 52, METHOD_BUFFERED, FILE_WRITE_DATA)
      FSCTL_SET_ENCRYPTION equ CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 53, METHOD_NEITHER, FILE_ANY_ACCESS); ENCRYPTION_BUFFER, DECRYPTION_STATUS_BUFFER

      FSCTL_ENCRYPTION_FSCTL_IO equ CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 54, METHOD_NEITHER, FILE_ANY_ACCESS)
      FSCTL_WRITE_RAW_ENCRYPTED equ CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 55, METHOD_NEITHER, FILE_SPECIAL_ACCESS); ENCRYPTED_DATA_INFO, EXTENDED_ENCRYPTED_DATA_INFO

      FSCTL_READ_RAW_ENCRYPTED equ CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 56, METHOD_NEITHER, FILE_SPECIAL_ACCESS); REQUEST_RAW_ENCRYPTED_DATA, ENCRYPTED_DATA_INFO, EXTENDED_ENCRYPTED_DATA_INFO

      FSCTL_CREATE_USN_JOURNAL equ CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 57, METHOD_NEITHER, FILE_ANY_ACCESS); CREATE_USN_JOURNAL_DATA,

      FSCTL_READ_FILE_USN_DATA equ CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 58, METHOD_NEITHER, FILE_ANY_ACCESS); Read the Usn Record for a file

      FSCTL_WRITE_USN_CLOSE_RECORD equ CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 59, METHOD_NEITHER, FILE_ANY_ACCESS); Generate Close Usn Record

      FSCTL_EXTEND_VOLUME equ CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 60, METHOD_BUFFERED, FILE_ANY_ACCESS)
      FSCTL_QUERY_USN_JOURNAL equ CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 61, METHOD_BUFFERED, FILE_ANY_ACCESS)
      FSCTL_DELETE_USN_JOURNAL equ CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 62, METHOD_BUFFERED, FILE_ANY_ACCESS)
      FSCTL_MARK_HANDLE equ CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 63, METHOD_BUFFERED, FILE_ANY_ACCESS)
      FSCTL_SIS_COPYFILE equ CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 64, METHOD_BUFFERED, FILE_ANY_ACCESS)
      FSCTL_SIS_LINK_FILES equ CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 65, METHOD_BUFFERED, FILE_READ_DATA or FILE_WRITE_DATA)
      ; decommissioned fsctl value                                             66
      ; decommissioned fsctl value                                             67
      ; decommissioned fsctl value                                             68
      FSCTL_RECALL_FILE equ CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 69, METHOD_NEITHER, FILE_ANY_ACCESS)
      ; decommissioned fsctl value                                             70
      FSCTL_READ_FROM_PLEX equ CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 71, METHOD_OUT_DIRECT, FILE_READ_DATA)
      FSCTL_FILE_PREFETCH equ CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 72, METHOD_BUFFERED, FILE_SPECIAL_ACCESS); FILE_PREFETCH

      ;* _WIN32_WINNT >= _WIN32_WINNT_WIN2K *
    endif
    if (_WIN32_WINNT ge _WIN32_WINNT_VISTA)
      FSCTL_MAKE_MEDIA_COMPATIBLE equ CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 76, METHOD_BUFFERED, FILE_WRITE_DATA); UDFS R/W

      FSCTL_SET_DEFECT_MANAGEMENT equ CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 77, METHOD_BUFFERED, FILE_WRITE_DATA); UDFS R/W

      FSCTL_QUERY_SPARING_INFO equ CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 78, METHOD_BUFFERED, FILE_ANY_ACCESS); UDFS R/W

      FSCTL_QUERY_ON_DISK_VOLUME_INFO equ CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 79, METHOD_BUFFERED, FILE_ANY_ACCESS); C/UDFS

      FSCTL_SET_VOLUME_COMPRESSION_STATE equ CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 80, METHOD_BUFFERED, FILE_SPECIAL_ACCESS); VOLUME_COMPRESSION_STATE

      ; decommissioned fsctl value                                                 80
      FSCTL_TXFS_MODIFY_RM equ CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 81, METHOD_BUFFERED, FILE_WRITE_DATA); TxF

      FSCTL_TXFS_QUERY_RM_INFORMATION equ CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 82, METHOD_BUFFERED, FILE_READ_DATA); TxF

      ; decommissioned fsctl value                                                 83
      FSCTL_TXFS_ROLLFORWARD_REDO equ CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 84, METHOD_BUFFERED, FILE_WRITE_DATA); TxF

      FSCTL_TXFS_ROLLFORWARD_UNDO equ CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 85, METHOD_BUFFERED, FILE_WRITE_DATA); TxF

      FSCTL_TXFS_START_RM equ CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 86, METHOD_BUFFERED, FILE_WRITE_DATA); TxF

      FSCTL_TXFS_SHUTDOWN_RM equ CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 87, METHOD_BUFFERED, FILE_WRITE_DATA); TxF

      FSCTL_TXFS_READ_BACKUP_INFORMATION equ CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 88, METHOD_BUFFERED, FILE_READ_DATA); TxF

      FSCTL_TXFS_WRITE_BACKUP_INFORMATION equ CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 89, METHOD_BUFFERED, FILE_WRITE_DATA); TxF

      FSCTL_TXFS_CREATE_SECONDARY_RM equ CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 90, METHOD_BUFFERED, FILE_WRITE_DATA); TxF

      FSCTL_TXFS_GET_METADATA_INFO equ CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 91, METHOD_BUFFERED, FILE_READ_DATA); TxF

      FSCTL_TXFS_GET_TRANSACTED_VERSION equ CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 92, METHOD_BUFFERED, FILE_READ_DATA); TxF

      ; decommissioned fsctl value                                                 93
      FSCTL_TXFS_SAVEPOINT_INFORMATION equ CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 94, METHOD_BUFFERED, FILE_WRITE_DATA); TxF

      FSCTL_TXFS_CREATE_MINIVERSION equ CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 95, METHOD_BUFFERED, FILE_WRITE_DATA); TxF

      ; decommissioned fsctl value                                                 96
      ; decommissioned fsctl value                                                 97
      ; decommissioned fsctl value                                                 98
      FSCTL_TXFS_TRANSACTION_ACTIVE equ CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 99, METHOD_BUFFERED, FILE_READ_DATA); TxF

      FSCTL_SET_ZERO_ON_DEALLOCATION equ CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 101, METHOD_BUFFERED, FILE_SPECIAL_ACCESS)
      FSCTL_SET_REPAIR equ CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 102, METHOD_BUFFERED, FILE_ANY_ACCESS)
      FSCTL_GET_REPAIR equ CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 103, METHOD_BUFFERED, FILE_ANY_ACCESS)
      FSCTL_WAIT_FOR_REPAIR equ CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 104, METHOD_BUFFERED, FILE_ANY_ACCESS)
      ; decommissioned fsctl value                                                 105
      FSCTL_INITIATE_REPAIR equ CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 106, METHOD_BUFFERED, FILE_ANY_ACCESS)
      FSCTL_CSC_INTERNAL equ CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 107, METHOD_NEITHER, FILE_ANY_ACCESS); CSC internal implementation

      FSCTL_SHRINK_VOLUME equ CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 108, METHOD_BUFFERED, FILE_SPECIAL_ACCESS); SHRINK_VOLUME_INFORMATION

      FSCTL_SET_SHORT_NAME_BEHAVIOR equ CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 109, METHOD_BUFFERED, FILE_ANY_ACCESS)
      FSCTL_DFSR_SET_GHOST_HANDLE_STATE equ CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 110, METHOD_BUFFERED, FILE_ANY_ACCESS)
      ;  Values 111 - 119 are reserved for FSRM.
      FSCTL_TXFS_LIST_TRANSACTION_LOCKED_FILES equ CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 120, METHOD_BUFFERED, FILE_READ_DATA); TxF

      FSCTL_TXFS_LIST_TRANSACTIONS equ CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 121, METHOD_BUFFERED, FILE_READ_DATA); TxF

      FSCTL_QUERY_PAGEFILE_ENCRYPTION equ CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 122, METHOD_BUFFERED, FILE_ANY_ACCESS)
      ;* _WIN32_WINNT >= _WIN32_WINNT_VISTA *
    endif
    if (_WIN32_WINNT ge _WIN32_WINNT_VISTA)
      FSCTL_RESET_VOLUME_ALLOCATION_HINTS equ CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 123, METHOD_BUFFERED, FILE_ANY_ACCESS)
      ;* _WIN32_WINNT >= _WIN32_WINNT_VISTA *
    endif
    if (_WIN32_WINNT ge _WIN32_WINNT_WIN7)
      FSCTL_QUERY_DEPENDENT_VOLUME equ CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 124, METHOD_BUFFERED, FILE_ANY_ACCESS); Dependency File System Filter

      FSCTL_SD_GLOBAL_CHANGE equ CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 125, METHOD_BUFFERED, FILE_ANY_ACCESS); Query/Change NTFS Security Descriptors

      ;* _WIN32_WINNT >= _WIN32_WINNT_WIN7 *
    endif
    if (_WIN32_WINNT ge _WIN32_WINNT_VISTA)
      FSCTL_TXFS_READ_BACKUP_INFORMATION2 equ CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 126, METHOD_BUFFERED, FILE_ANY_ACCESS); TxF

      ;* _WIN32_WINNT >= _WIN32_WINNT_VISTA *
    endif
    if (_WIN32_WINNT ge _WIN32_WINNT_WIN7)
      FSCTL_LOOKUP_STREAM_FROM_CLUSTER equ CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 127, METHOD_BUFFERED, FILE_ANY_ACCESS)
      FSCTL_TXFS_WRITE_BACKUP_INFORMATION2 equ CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 128, METHOD_BUFFERED, FILE_ANY_ACCESS); TxF

      FSCTL_FILE_TYPE_NOTIFICATION equ CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 129, METHOD_BUFFERED, FILE_ANY_ACCESS)
    endif
    if (_WIN32_WINNT ge _WIN32_WINNT_WIN8)
      FSCTL_FILE_LEVEL_TRIM equ CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 130, METHOD_BUFFERED, FILE_WRITE_DATA)
      ;*_WIN32_WINNT >= _WIN32_WINNT_WIN8 *
    endif
    ;  Values 131 - 139 are reserved for FSRM.
    if (_WIN32_WINNT ge _WIN32_WINNT_WIN7)
      FSCTL_GET_BOOT_AREA_INFO equ CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 140, METHOD_BUFFERED, FILE_ANY_ACCESS); BOOT_AREA_INFO

      FSCTL_GET_RETRIEVAL_POINTER_BASE equ CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 141, METHOD_BUFFERED, FILE_ANY_ACCESS); RETRIEVAL_POINTER_BASE

      FSCTL_SET_PERSISTENT_VOLUME_STATE equ CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 142, METHOD_BUFFERED, FILE_ANY_ACCESS); FILE_FS_PERSISTENT_VOLUME_INFORMATION

      FSCTL_QUERY_PERSISTENT_VOLUME_STATE equ CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 143, METHOD_BUFFERED, FILE_ANY_ACCESS); FILE_FS_PERSISTENT_VOLUME_INFORMATION

      FSCTL_REQUEST_OPLOCK equ CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 144, METHOD_BUFFERED, FILE_ANY_ACCESS)
      FSCTL_CSV_TUNNEL_REQUEST equ CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 145, METHOD_BUFFERED, FILE_ANY_ACCESS); CSV_TUNNEL_REQUEST

      FSCTL_IS_CSV_FILE equ CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 146, METHOD_BUFFERED, FILE_ANY_ACCESS); IS_CSV_FILE

      FSCTL_QUERY_FILE_SYSTEM_RECOGNITION equ CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 147, METHOD_BUFFERED, FILE_ANY_ACCESS)
      FSCTL_CSV_GET_VOLUME_PATH_NAME equ CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 148, METHOD_BUFFERED, FILE_ANY_ACCESS)
      FSCTL_CSV_GET_VOLUME_NAME_FOR_VOLUME_MOUNT_POINT equ CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 149, METHOD_BUFFERED, FILE_ANY_ACCESS)
      FSCTL_CSV_GET_VOLUME_PATH_NAMES_FOR_VOLUME_NAME equ CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 150, METHOD_BUFFERED, FILE_ANY_ACCESS)
      FSCTL_IS_FILE_ON_CSV_VOLUME equ CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 151, METHOD_BUFFERED, FILE_ANY_ACCESS)
      ;* _WIN32_WINNT >= _WIN32_WINNT_WIN7 *
    endif
    if (_WIN32_WINNT ge _WIN32_WINNT_WIN8)
      FSCTL_CORRUPTION_HANDLING equ CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 152, METHOD_BUFFERED, FILE_ANY_ACCESS)
      FSCTL_OFFLOAD_READ equ CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 153, METHOD_BUFFERED, FILE_READ_ACCESS)
      FSCTL_OFFLOAD_WRITE equ CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 154, METHOD_BUFFERED, FILE_WRITE_ACCESS)
      ;*_WIN32_WINNT >= _WIN32_WINNT_WIN8 *
    endif
    if (_WIN32_WINNT ge _WIN32_WINNT_WIN7)
      FSCTL_CSV_INTERNAL equ CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 155, METHOD_BUFFERED, FILE_ANY_ACCESS)
      ;* _WIN32_WINNT >= _WIN32_WINNT_WIN7 *
    endif
    if (_WIN32_WINNT ge _WIN32_WINNT_WIN8)
      FSCTL_SET_PURGE_FAILURE_MODE equ CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 156, METHOD_BUFFERED, FILE_ANY_ACCESS)
      FSCTL_QUERY_FILE_LAYOUT equ CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 157, METHOD_NEITHER, FILE_ANY_ACCESS)
      FSCTL_IS_VOLUME_OWNED_BYCSVFS equ CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 158, METHOD_BUFFERED, FILE_ANY_ACCESS)
      FSCTL_GET_INTEGRITY_INFORMATION equ CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 159, METHOD_BUFFERED, FILE_ANY_ACCESS); FSCTL_GET_INTEGRITY_INFORMATION_BUFFER

      FSCTL_SET_INTEGRITY_INFORMATION equ CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 160, METHOD_BUFFERED, FILE_READ_DATA or FILE_WRITE_DATA); FSCTL_SET_INTEGRITY_INFORMATION_BUFFER

      FSCTL_QUERY_FILE_REGIONS equ CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 161, METHOD_BUFFERED, FILE_ANY_ACCESS)
      ;*_WIN32_WINNT >= _WIN32_WINNT_WIN8 *
    endif
    if (_WIN32_WINNT ge _WIN32_WINNT_WIN8)
      FSCTL_RKF_INTERNAL equ CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 171, METHOD_NEITHER, FILE_ANY_ACCESS); Resume Key Filter

      FSCTL_SCRUB_DATA equ CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 172, METHOD_BUFFERED, FILE_ANY_ACCESS)
      FSCTL_REPAIR_COPIES equ CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 173, METHOD_BUFFERED, FILE_READ_DATA or FILE_WRITE_DATA)
      FSCTL_DISABLE_LOCAL_BUFFERING equ CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 174, METHOD_BUFFERED, FILE_ANY_ACCESS)
      FSCTL_CSV_MGMT_LOCK equ CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 175, METHOD_BUFFERED, FILE_ANY_ACCESS)
      FSCTL_CSV_QUERY_DOWN_LEVEL_FILE_SYSTEM_CHARACTERISTICS equ CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 176, METHOD_BUFFERED, FILE_ANY_ACCESS)
      FSCTL_ADVANCE_FILE_ID equ CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 177, METHOD_BUFFERED, FILE_ANY_ACCESS)
      FSCTL_CSV_SYNC_TUNNEL_REQUEST equ CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 178, METHOD_BUFFERED, FILE_ANY_ACCESS)
      FSCTL_CSV_QUERY_VETO_FILE_DIRECT_IO equ CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 179, METHOD_BUFFERED, FILE_ANY_ACCESS)
      FSCTL_WRITE_USN_REASON equ CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 180, METHOD_BUFFERED, FILE_ANY_ACCESS)
      FSCTL_CSV_CONTROL equ CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 181, METHOD_BUFFERED, FILE_ANY_ACCESS)
      FSCTL_GET_REFS_VOLUME_DATA equ CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 182, METHOD_BUFFERED, FILE_ANY_ACCESS)
      FSCTL_CSV_H_BREAKING_SYNC_TUNNEL_REQUEST equ CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 185, METHOD_BUFFERED, FILE_ANY_ACCESS)
      ;*_WIN32_WINNT >= _WIN32_WINNT_WIN8 *
    endif
    if (_WIN32_WINNT ge _WIN32_WINNT_WINBLUE)
      FSCTL_QUERY_STORAGE_CLASSES equ CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 187, METHOD_BUFFERED, FILE_ANY_ACCESS)
      FSCTL_QUERY_REGION_INFO equ CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 188, METHOD_BUFFERED, FILE_ANY_ACCESS)
      FSCTL_USN_TRACK_MODIFIED_RANGES equ CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 189, METHOD_BUFFERED, FILE_ANY_ACCESS); USN_TRACK_MODIFIED_RANGES

      ;* (_WIN32_WINNT >= _WIN32_WINNT_WINBLUE) *
    endif
    if (_WIN32_WINNT ge _WIN32_WINNT_WINBLUE)
      FSCTL_QUERY_SHARED_VIRTUAL_DISK_SUPPORT equ CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 192, METHOD_BUFFERED, FILE_ANY_ACCESS)
      FSCTL_SVHDX_SYNC_TUNNEL_REQUEST equ CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 193, METHOD_BUFFERED, FILE_ANY_ACCESS)
      FSCTL_SVHDX_SET_INITIATOR_INFORMATION equ CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 194, METHOD_BUFFERED, FILE_ANY_ACCESS)
      ;* (_WIN32_WINNT >= _WIN32_WINNT_WINBLUE) *
    endif
    if (_WIN32_WINNT ge _WIN32_WINNT_WIN7)
      FSCTL_SET_EXTERNAL_BACKING equ CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 195, METHOD_BUFFERED, FILE_SPECIAL_ACCESS)
      FSCTL_GET_EXTERNAL_BACKING equ CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 196, METHOD_BUFFERED, FILE_ANY_ACCESS)
      FSCTL_DELETE_EXTERNAL_BACKING equ CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 197, METHOD_BUFFERED, FILE_SPECIAL_ACCESS)
      FSCTL_ENUM_EXTERNAL_BACKING equ CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 198, METHOD_BUFFERED, FILE_ANY_ACCESS)
      FSCTL_ENUM_OVERLAY equ CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 199, METHOD_NEITHER, FILE_ANY_ACCESS)
      FSCTL_ADD_OVERLAY equ CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 204, METHOD_BUFFERED, FILE_WRITE_DATA)
      FSCTL_REMOVE_OVERLAY equ CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 205, METHOD_BUFFERED, FILE_WRITE_DATA)
      FSCTL_UPDATE_OVERLAY equ CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 206, METHOD_BUFFERED, FILE_WRITE_DATA)
      ;* (_WIN32_WINNT >= _WIN32_WINNT_WIN7) *
    endif
    if (_WIN32_WINNT ge _WIN32_WINNT_WIN8)
      FSCTL_SHUFFLE_FILE equ CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 208, METHOD_BUFFERED, FILE_READ_ACCESS or FILE_WRITE_ACCESS); SHUFFLE_FILE_DATA

      ;*_WIN32_WINNT >= _WIN32_WINNT_WIN8 *
    endif
    if (_WIN32_WINNT ge _WIN32_WINNT_WINBLUE)
      FSCTL_DUPLICATE_EXTENTS_TO_FILE equ CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 209, METHOD_BUFFERED, FILE_WRITE_DATA)
      ;* (_WIN32_WINNT >= _WIN32_WINNT_WINBLUE) *
    endif
    if (_WIN32_WINNT ge _WIN32_WINNT_WINBLUE)
      FSCTL_SPARSE_OVERALLOCATE equ CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 211, METHOD_BUFFERED, FILE_SPECIAL_ACCESS)
      FSCTL_STORAGE_QOS_CONTROL equ CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 212, METHOD_BUFFERED, FILE_ANY_ACCESS)
      ;* (_WIN32_WINNT >= _WIN32_WINNT_WINBLUE) *
    endif
    if (_WIN32_WINNT ge _WIN32_WINNT_WINTHRESHOLD)
      FSCTL_INITIATE_FILE_METADATA_OPTIMIZATION equ CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 215, METHOD_BUFFERED, FILE_SPECIAL_ACCESS)
      FSCTL_QUERY_FILE_METADATA_OPTIMIZATION equ CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 216, METHOD_BUFFERED, FILE_SPECIAL_ACCESS)
      ;* (_WIN32_WINNT >= _WIN32_WINNT_WINTHRESHOLD) *
    endif
    if (_WIN32_WINNT ge _WIN32_WINNT_WINBLUE)
      FSCTL_SVHDX_ASYNC_TUNNEL_REQUEST equ CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 217, METHOD_BUFFERED, FILE_ANY_ACCESS)
      ;* (_WIN32_WINNT >= _WIN32_WINNT_WINBLUE) *
    endif
    if (_WIN32_WINNT ge _WIN32_WINNT_WIN7)
      FSCTL_GET_WOF_VERSION equ CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 218, METHOD_BUFFERED, FILE_ANY_ACCESS)
    endif
    if (_WIN32_WINNT ge _WIN32_WINNT_WINTHRESHOLD)
      FSCTL_HCS_SYNC_TUNNEL_REQUEST equ CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 219, METHOD_BUFFERED, FILE_ANY_ACCESS)
      FSCTL_HCS_ASYNC_TUNNEL_REQUEST equ CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 220, METHOD_BUFFERED, FILE_ANY_ACCESS)
      FSCTL_QUERY_EXTENT_READ_CACHE_INFO equ CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 221, METHOD_NEITHER, FILE_ANY_ACCESS); VCN_RANGE_INPUT_BUFFER, EXTENT_READ_CACHE_INFO_BUFFER

      FSCTL_QUERY_REFS_VOLUME_COUNTER_INFO equ CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 222, METHOD_NEITHER, FILE_ANY_ACCESS); REFS_VOLUME_COUNTER_INFO_INPUT_BUFFER, VOLUME_REFS_INFO_BUFFER

      FSCTL_CLEAN_VOLUME_METADATA equ CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 223, METHOD_BUFFERED, FILE_ANY_ACCESS)
      FSCTL_SET_INTEGRITY_INFORMATION_EX equ CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 224, METHOD_BUFFERED, FILE_ANY_ACCESS); FSCTL_SET_INTEGRITY_INFORMATION_BUFFER_EX

      ;* (_WIN32_WINNT >= _WIN32_WINNT_WINTHRESHOLD) *
    endif
    if (_WIN32_WINNT ge _WIN32_WINNT_WIN7)
      FSCTL_SUSPEND_OVERLAY equ CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 225, METHOD_BUFFERED, FILE_ANY_ACCESS)
    endif
    if (_WIN32_WINNT ge _WIN32_WINNT_WINTHRESHOLD)
      FSCTL_VIRTUAL_STORAGE_QUERY_PROPERTY equ CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 226, METHOD_BUFFERED, FILE_ANY_ACCESS)
      FSCTL_FILESYSTEM_GET_STATISTICS_EX equ CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 227, METHOD_BUFFERED, FILE_ANY_ACCESS); FILESYSTEM_STATISTICS_EX

      FSCTL_QUERY_VOLUME_CONTAINER_STATE equ CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 228, METHOD_BUFFERED, FILE_ANY_ACCESS)
      FSCTL_SET_LAYER_ROOT equ CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 229, METHOD_BUFFERED, FILE_ANY_ACCESS); CONTAINER_ROOT_INFO_INPUT CONTAINER_ROOT_INFO_OUTPUT

    endif
    if (_WIN32_WINNT ge _WIN32_WINNT_WIN10_TH2)
      FSCTL_QUERY_DIRECT_ACCESS_EXTENTS equ CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 230, METHOD_NEITHER, FILE_ANY_ACCESS); QUERY_DIRECT_ACCESS_EXTENTS

      FSCTL_NOTIFY_STORAGE_SPACE_ALLOCATION equ CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 231, METHOD_BUFFERED, FILE_ANY_ACCESS)
      FSCTL_SSDI_STORAGE_REQUEST equ CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 232, METHOD_BUFFERED, FILE_ANY_ACCESS)
    endif
    if (_WIN32_WINNT ge _WIN32_WINNT_WIN10_RS1)
      FSCTL_QUERY_DIRECT_IMAGE_ORIGINAL_BASE equ CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 233, METHOD_BUFFERED, FILE_ANY_ACCESS)
      FSCTL_READ_UNPRIVILEGED_USN_JOURNAL equ CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 234, METHOD_NEITHER, FILE_ANY_ACCESS); READ_USN_JOURNAL_DATA, USN

    endif
    if (_WIN32_WINNT ge _WIN32_WINNT_WIN10_TH2)
      FSCTL_GHOST_FILE_EXTENTS equ CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 235, METHOD_BUFFERED, FILE_WRITE_ACCESS); FSCTL_GHOST_FILE_EXTENTS_INPUT_BUFFER

      FSCTL_QUERY_GHOSTED_FILE_EXTENTS equ CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 236, METHOD_BUFFERED, FILE_ANY_ACCESS)
    endif
    if (_WIN32_WINNT ge _WIN32_WINNT_WIN10_TH2)
      FSCTL_UNMAP_SPACE equ CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 237, METHOD_BUFFERED, FILE_ANY_ACCESS)
    endif
    if (_WIN32_WINNT ge _WIN32_WINNT_WINTHRESHOLD)
      FSCTL_HCS_SYNC_NO_WRITE_TUNNEL_REQUEST equ CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 238, METHOD_BUFFERED, FILE_ANY_ACCESS)
    endif
    if (_WIN32_WINNT ge _WIN32_WINNT_WIN10_RS1)
      FSCTL_START_VIRTUALIZATION_INSTANCE equ CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 240, METHOD_BUFFERED, FILE_ANY_ACCESS); VIRTUALIZATION_INSTANCE_INFO_INPUT, VIRTUALIZATION_INSTANCE_INFO_OUTPUT

      FSCTL_GET_FILTER_FILE_IDENTIFIER equ CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 241, METHOD_BUFFERED, FILE_ANY_ACCESS); GET_FILTER_FILE_IDENTIFIER_INPUT, GET_FILTER_FILE_IDENTIFIER_OUTPUT

      ;* (_WIN32_WINNT >= _WIN32_WINNT_WIN10_RS1) *
    endif
    if (_WIN32_WINNT ge _WIN32_WINNT_WIN10_RS2)
      FSCTL_STREAMS_QUERY_PARAMETERS equ CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 241, METHOD_BUFFERED, FILE_ANY_ACCESS)
      FSCTL_STREAMS_ASSOCIATE_ID equ CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 242, METHOD_BUFFERED, FILE_ANY_ACCESS)
      FSCTL_STREAMS_QUERY_ID equ CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 243, METHOD_BUFFERED, FILE_ANY_ACCESS)
      FSCTL_GET_RETRIEVAL_POINTERS_AND_REFCOUNT equ CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 244, METHOD_NEITHER, FILE_ANY_ACCESS); STARTING_VCN_INPUT_BUFFER, RETRIEVAL_POINTERS_AND_REFCOUNT_BUFFER

      FSCTL_QUERY_VOLUME_NUMA_INFO equ CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 245, METHOD_BUFFERED, FILE_ANY_ACCESS)
    endif
    if (_WIN32_WINNT ge _WIN32_WINNT_WIN10_RS2)
      FSCTL_REFS_DEALLOCATE_RANGES equ CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 246, METHOD_BUFFERED, FILE_ANY_ACCESS)
    endif
    if (_WIN32_WINNT ge _WIN32_WINNT_WIN10_TH2)
      FSCTL_QUERY_REFS_SMR_VOLUME_INFO equ CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 247, METHOD_BUFFERED, FILE_ANY_ACCESS)
      FSCTL_SET_REFS_SMR_VOLUME_GC_PARAMETERS equ CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 248, METHOD_BUFFERED, FILE_ANY_ACCESS)
      FSCTL_SET_REFS_FILE_STRICTLY_SEQUENTIAL equ CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 249, METHOD_BUFFERED, FILE_ANY_ACCESS)
    endif
    if (_WIN32_WINNT ge _WIN32_WINNT_WIN10_RS3)
      FSCTL_DUPLICATE_EXTENTS_TO_FILE_EX equ CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 250, METHOD_BUFFERED, FILE_WRITE_DATA)
      FSCTL_QUERY_BAD_RANGES equ CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 251, METHOD_BUFFERED, FILE_ANY_ACCESS)
      FSCTL_SET_DAX_ALLOC_ALIGNMENT_HINT equ CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 252, METHOD_BUFFERED, FILE_ANY_ACCESS)
      FSCTL_DELETE_CORRUPTED_REFS_CONTAINER equ CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 253, METHOD_BUFFERED, FILE_ANY_ACCESS)
      FSCTL_SCRUB_UNDISCOVERABLE_ID equ CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 254, METHOD_BUFFERED, FILE_ANY_ACCESS)
      ;* (_WIN32_WINNT >= _WIN32_WINNT_WIN10_RS3) *
    endif
    if (_WIN32_WINNT ge _WIN32_WINNT_WIN10_RS4)
      FSCTL_NOTIFY_DATA_CHANGE equ CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 255, METHOD_BUFFERED, FILE_ANY_ACCESS)
      ;* (_WIN32_WINNT >= _WIN32_WINNT_WIN10_RS4) *
    endif
    if (_WIN32_WINNT ge _WIN32_WINNT_WIN10_RS1)
      FSCTL_START_VIRTUALIZATION_INSTANCE_EX equ CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 256, METHOD_BUFFERED, FILE_ANY_ACCESS)
      ;* (_WIN32_WINNT >= _WIN32_WINNT_WIN10_RS1) *
    endif
    if (_WIN32_WINNT ge _WIN32_WINNT_WIN10_RS4)
      FSCTL_ENCRYPTION_KEY_CONTROL equ CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 257, METHOD_BUFFERED, FILE_ANY_ACCESS); protect/unprotect under DPL

      FSCTL_VIRTUAL_STORAGE_SET_BEHAVIOR equ CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 258, METHOD_BUFFERED, FILE_ANY_ACCESS)
      ;* (_WIN32_WINNT >= _WIN32_WINNT_WIN10_RS4) *
    endif
    if (_WIN32_WINNT ge _WIN32_WINNT_WIN10_RS1)
      FSCTL_SET_REPARSE_POINT_EX equ CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 259, METHOD_BUFFERED, FILE_SPECIAL_ACCESS); REPARSE_DATA_BUFFER_EX

      ;* (_WIN32_WINNT >= _WIN32_WINNT_WIN10_RS1) *
    endif
    if (_WIN32_WINNT ge _WIN32_WINNT_WIN10_RS5)
      FSCTL_REARRANGE_FILE equ CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 264, METHOD_BUFFERED, FILE_READ_ACCESS or FILE_WRITE_ACCESS); REARRANGE_FILE_DATA

      FSCTL_VIRTUAL_STORAGE_PASSTHROUGH equ CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 265, METHOD_BUFFERED, FILE_ANY_ACCESS)
      FSCTL_GET_RETRIEVAL_POINTER_COUNT equ CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 266, METHOD_NEITHER, FILE_ANY_ACCESS); STARTING_VCN_INPUT_BUFFER, RETRIEVAL_POINTER_COUNT

      if Defined(_WIN64)
        FSCTL_ENABLE_PER_IO_FLAGS equ CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 267, METHOD_BUFFERED, FILE_ANY_ACCESS)
        ;* _WIN64 *
      endif
      ;* (_WIN32_WINNT >= _WIN32_WINNT_WIN10_RS5) *
    endif
    if (NTDDI_VERSION ge NTDDI_WIN10_RS5)
      FSCTL_QUERY_ASYNC_DUPLICATE_EXTENTS_STATUS equ CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 268, METHOD_BUFFERED, FILE_ANY_ACCESS)
    endif
    if (NTDDI_VERSION ge NTDDI_WIN10_MN)
      FSCTL_SMB_SHARE_FLUSH_AND_PURGE equ CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 271, METHOD_BUFFERED, FILE_ANY_ACCESS)
    endif
    if (NTDDI_VERSION ge NTDDI_WIN10_FE)
      FSCTL_REFS_STREAM_SNAPSHOT_MANAGEMENT equ CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 272, METHOD_BUFFERED, FILE_ANY_ACCESS)
    endif
    if (NTDDI_VERSION ge NTDDI_WIN10_CO)
      FSCTL_MANAGE_BYPASS_IO equ CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 274, METHOD_BUFFERED, FILE_ANY_ACCESS)
    endif
    if (NTDDI_VERSION ge NTDDI_WIN10_FE)
      FSCTL_REFS_DEALLOCATE_RANGES_EX equ CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 275, METHOD_BUFFERED, FILE_ANY_ACCESS)
    endif
    if (NTDDI_VERSION ge NTDDI_WIN10_FE)
      FSCTL_SET_CACHED_RUNS_STATE equ CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 276, METHOD_BUFFERED, FILE_ANY_ACCESS)
    endif
    if (NTDDI_VERSION ge NTDDI_WIN10_NI)
      FSCTL_REFS_SET_VOLUME_COMPRESSION_INFO equ CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 277, METHOD_BUFFERED, FILE_ANY_ACCESS)
      FSCTL_REFS_QUERY_VOLUME_COMPRESSION_INFO equ CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 278, METHOD_BUFFERED, FILE_ANY_ACCESS)
    endif
    if (NTDDI_VERSION ge NTDDI_WIN10_NI)
      FSCTL_DUPLICATE_CLUSTER equ CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 279, METHOD_BUFFERED, FILE_ANY_ACCESS)
      FSCTL_CREATE_LCN_WEAK_REFERENCE equ CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 280, METHOD_BUFFERED, FILE_ANY_ACCESS)
      FSCTL_CLEAR_LCN_WEAK_REFERENCE equ CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 281, METHOD_BUFFERED, FILE_ANY_ACCESS)
      FSCTL_QUERY_LCN_WEAK_REFERENCE equ CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 282, METHOD_BUFFERED, FILE_ANY_ACCESS)
      FSCTL_CLEAR_ALL_LCN_WEAK_REFERENCES equ CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 283, METHOD_BUFFERED, FILE_ANY_ACCESS)
      FSCTL_REFS_SET_VOLUME_DEDUP_INFO equ CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 284, METHOD_BUFFERED, FILE_ANY_ACCESS)
      FSCTL_REFS_QUERY_VOLUME_DEDUP_INFO equ CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 285, METHOD_BUFFERED, FILE_ANY_ACCESS)
    endif
    if (NTDDI_VERSION ge NTDDI_WIN10_RS5)
      FSCTL_LMR_QUERY_INFO equ CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 286, METHOD_BUFFERED, FILE_ANY_ACCESS)
    endif
    if (NTDDI_VERSION ge NTDDI_WIN10_NI)
      FSCTL_REFS_CHECKPOINT_VOLUME equ CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 287, METHOD_BUFFERED, FILE_ANY_ACCESS)
      FSCTL_REFS_QUERY_VOLUME_TOTAL_SHARED_LCNS equ CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 288, METHOD_BUFFERED, FILE_ANY_ACCESS)
    endif
    if (NTDDI_VERSION ge NTDDI_WIN10_CU)
      FSCTL_UPGRADE_VOLUME equ CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 289, METHOD_BUFFERED, FILE_ANY_ACCESS)
    endif
    ;* ABRACADABRA_WIN10_ZN?  ABRACADABRA_WIN10_ZN? *
    if (NTDDI_VERSION ge NTDDI_WIN10_CU)
      FSCTL_REFS_SET_VOLUME_IO_METRICS_INFO equ CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 290, METHOD_BUFFERED, FILE_ANY_ACCESS)
      FSCTL_REFS_QUERY_VOLUME_IO_METRICS_INFO equ CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 291, METHOD_BUFFERED, FILE_ANY_ACCESS)
    endif
    ; AVIO IOCTLS.
    IOCTL_AVIO_ALLOCATE_STREAM equ CTL_CODE(FILE_DEVICE_AVIO, 1, METHOD_BUFFERED, FILE_SPECIAL_ACCESS)
    IOCTL_AVIO_FREE_STREAM equ CTL_CODE(FILE_DEVICE_AVIO, 2, METHOD_BUFFERED, FILE_SPECIAL_ACCESS)
    IOCTL_AVIO_MODIFY_STREAM equ CTL_CODE(FILE_DEVICE_AVIO, 3, METHOD_BUFFERED, FILE_SPECIAL_ACCESS)
    ; end_ntddk
    ; begin_ntifs
    ; The following long list of structs are associated with the preceding
    ; file system fsctls.
    ;==================== FSCTL_IS_PATHNAME_VALID ======================
    ; Structure for FSCTL_IS_PATHNAME_VALID
    PATHNAME_BUFFER struct
      PathNameLength DWORD ?
      Name_ WORD 1 dup (?)
    PATHNAME_BUFFER ends
    _PATHNAME_BUFFER typedef PATHNAME_BUFFER
    PPATHNAME_BUFFER typedef ptr PATHNAME_BUFFER
    ;==================== FSCTL_QUERY_BPB_INFO ======================
    ; Structure for FSCTL_QUERY_BPB_INFO
    FSCTL_QUERY_FAT_BPB_BUFFER struct
      First0x24BytesOfBootSector BYTE 24h dup (?)
    FSCTL_QUERY_FAT_BPB_BUFFER ends
    _FSCTL_QUERY_FAT_BPB_BUFFER typedef FSCTL_QUERY_FAT_BPB_BUFFER
    PFSCTL_QUERY_FAT_BPB_BUFFER typedef ptr FSCTL_QUERY_FAT_BPB_BUFFER
    if (_WIN32_WINNT ge _WIN32_WINNT_NT4)
      ;==================== FSCTL_GET_NTFS_VOLUME_DATA ======================
      ; Structures for FSCTL_GET_NTFS_VOLUME_DATA.
      ; The user must pass the basic buffer below.  Ntfs
      ; will return as many fields as available in the extended
      ; buffer which follows immediately after the VOLUME_DATA_BUFFER.
      NTFS_VOLUME_DATA_BUFFER struct
        VolumeSerialNumber LARGE_INTEGER <>
        NumberSectors LARGE_INTEGER <>
        TotalClusters LARGE_INTEGER <>
        FreeClusters LARGE_INTEGER <>
        TotalReserved LARGE_INTEGER <>
        BytesPerSector DWORD ?
        BytesPerCluster DWORD ?
        BytesPerFileRecordSegment DWORD ?
        ClustersPerFileRecordSegment DWORD ?
        MftValidDataLength LARGE_INTEGER <>
        MftStartLcn LARGE_INTEGER <>
        Mft2StartLcn LARGE_INTEGER <>
        MftZoneStart LARGE_INTEGER <>
        MftZoneEnd LARGE_INTEGER <>
      NTFS_VOLUME_DATA_BUFFER ends
      PNTFS_VOLUME_DATA_BUFFER typedef ptr NTFS_VOLUME_DATA_BUFFER
      NTFS_EXTENDED_VOLUME_DATA struct
        ByteCount DWORD ?
        MajorVersion WORD ?
        MinorVersion WORD ?
        BytesPerPhysicalSector DWORD ?
        LfsMajorVersion WORD ?
        LfsMinorVersion WORD ?
        if (_WIN32_WINNT ge _WIN32_WINNT_WINTHRESHOLD)
          MaxDeviceTrimExtentCount DWORD ?
          MaxDeviceTrimByteCount DWORD ?
          MaxVolumeTrimExtentCount DWORD ?
          MaxVolumeTrimByteCount DWORD ?
        endif
      NTFS_EXTENDED_VOLUME_DATA ends
      PNTFS_EXTENDED_VOLUME_DATA typedef ptr NTFS_EXTENDED_VOLUME_DATA
      ;* _WIN32_WINNT >= _WIN32_WINNT_NT4 *
    endif
    if (_WIN32_WINNT ge _WIN32_WINNT_WIN8)
      ;==================== FSCTL_GET_REFS_VOLUME_DATA ======================
      ; Structures for FSCTL_GET_REFS_VOLUME_DATA.
      REFS_VOLUME_DATA_BUFFER struct
        ByteCount DWORD ?
        MajorVersion DWORD ?
        MinorVersion DWORD ?
        BytesPerPhysicalSector DWORD ?
        VolumeSerialNumber LARGE_INTEGER <>
        NumberSectors LARGE_INTEGER <>
        TotalClusters LARGE_INTEGER <>
        FreeClusters LARGE_INTEGER <>
        TotalReserved LARGE_INTEGER <>
        BytesPerSector DWORD ?
        BytesPerCluster DWORD ?
        MaximumSizeOfResidentFile LARGE_INTEGER <>
        FastTierDataFillRatio WORD ?
        ; between 0 and 10000
        SlowTierDataFillRatio WORD ?
        ; between 0 and 10000
        DestagesFastTierToSlowTierRate DWORD ?
        ; in clusters per second
        MetadataChecksumType WORD ?
        Reserved0 BYTE 6 dup (?)
        Reserved LARGE_INTEGER 8 dup (<>)
      REFS_VOLUME_DATA_BUFFER ends
      PREFS_VOLUME_DATA_BUFFER typedef ptr REFS_VOLUME_DATA_BUFFER
      ;* _WIN32_WINNT >= _WIN32_WINNT_WIN8 *
    endif
    if (_WIN32_WINNT ge _WIN32_WINNT_NT4)
      ;==================== FSCTL_GET_VOLUME_BITMAP ======================
      ; Structure for FSCTL_GET_VOLUME_BITMAP
      STARTING_LCN_INPUT_BUFFER struct
        StartingLcn LARGE_INTEGER <>
      STARTING_LCN_INPUT_BUFFER ends
      PSTARTING_LCN_INPUT_BUFFER typedef ptr STARTING_LCN_INPUT_BUFFER
      if (_WIN32_WINNT ge _WIN32_WINNT_WINTHRESHOLD)
        GET_VOLUME_BITMAP_FLAG_MASK_METADATA equ 00000001h
        STARTING_LCN_INPUT_BUFFER_EX struct
          StartingLcn LARGE_INTEGER <>
          Flags DWORD ?
        STARTING_LCN_INPUT_BUFFER_EX ends
        PSTARTING_LCN_INPUT_BUFFER_EX typedef ptr STARTING_LCN_INPUT_BUFFER_EX
        ;* _WIN32_WINNT >= _WIN32_WINNT_WINTHRESHOLD *
      endif
      VOLUME_BITMAP_BUFFER struct
        StartingLcn LARGE_INTEGER <>
        BitmapSize LARGE_INTEGER <>
        Buffer BYTE 1 dup (?)
      VOLUME_BITMAP_BUFFER ends
      PVOLUME_BITMAP_BUFFER typedef ptr VOLUME_BITMAP_BUFFER
      ;* _WIN32_WINNT >= _WIN32_WINNT_NT4 *
    endif
    if (_WIN32_WINNT ge _WIN32_WINNT_NT4)
      ;==================== FSCTL_GET_RETRIEVAL_POINTERS ======================
      ; Structure for FSCTL_GET_RETRIEVAL_POINTERS
      STARTING_VCN_INPUT_BUFFER struct
        StartingVcn LARGE_INTEGER <>
      STARTING_VCN_INPUT_BUFFER ends
      PSTARTING_VCN_INPUT_BUFFER typedef ptr STARTING_VCN_INPUT_BUFFER
      RETRIEVAL_POINTERS_BUFFER struct
        ExtentCount DWORD ?
        StartingVcn LARGE_INTEGER <>
        struct Extents
          NextVcn LARGE_INTEGER <>
          Lcn LARGE_INTEGER <>
        ends
        ] typedef ptr Extents
      RETRIEVAL_POINTERS_BUFFER ends
      PRETRIEVAL_POINTERS_BUFFER typedef ptr RETRIEVAL_POINTERS_BUFFER
      ;* _WIN32_WINNT >= _WIN32_WINNT_NT4 *
    endif
    if (_WIN32_WINNT ge _WIN32_WINNT_WIN10_RS2)
      ;==================== FSCTL_GET_RETRIEVAL_POINTERS_AND_REFCOUNT ======================
      ; Structure for FSCTL_GET_RETRIEVAL_POINTERS_AND_REFCOUNT
      ; Input structure is STARTING_VCN_INPUT_BUFFER
      RETRIEVAL_POINTERS_AND_REFCOUNT_BUFFER struct
        ExtentCount DWORD ?
        StartingVcn LARGE_INTEGER <>
        struct Extents
          NextVcn LARGE_INTEGER <>
          Lcn LARGE_INTEGER <>
          ReferenceCount DWORD ?
        ends
        ] typedef ptr Extents
      RETRIEVAL_POINTERS_AND_REFCOUNT_BUFFER ends
      PRETRIEVAL_POINTERS_AND_REFCOUNT_BUFFER typedef ptr RETRIEVAL_POINTERS_AND_REFCOUNT_BUFFER
      ;* _WIN32_WINNT >= _WIN32_WINNT_WIN10_RS2 *
    endif
    if (_WIN32_WINNT ge _WIN32_WINNT_WIN10_RS5)
      ;==================== FSCTL_GET_RETRIEVAL_POINTER_COUNT ======================
      ; Structure for FSCTL_GET_RETRIEVAL_POINTER_COUNT
      ; Input structure is STARTING_VCN_INPUT_BUFFER
      RETRIEVAL_POINTER_COUNT struct
        ExtentCount DWORD ?
      RETRIEVAL_POINTER_COUNT ends
      PRETRIEVAL_POINTER_COUNT typedef ptr RETRIEVAL_POINTER_COUNT
      ;* _WIN32_WINNT >= _WIN32_WINNT_WIN10_RS5 *
    endif
    if (_WIN32_WINNT ge _WIN32_WINNT_NT4)
      ;==================== FSCTL_GET_NTFS_FILE_RECORD ======================
      ; Structures for FSCTL_GET_NTFS_FILE_RECORD
      NTFS_FILE_RECORD_INPUT_BUFFER struct
        FileReferenceNumber LARGE_INTEGER <>
      NTFS_FILE_RECORD_INPUT_BUFFER ends
      PNTFS_FILE_RECORD_INPUT_BUFFER typedef ptr NTFS_FILE_RECORD_INPUT_BUFFER
      NTFS_FILE_RECORD_OUTPUT_BUFFER struct
        FileReferenceNumber LARGE_INTEGER <>
        FileRecordLength DWORD ?
        FileRecordBuffer BYTE 1 dup (?)
      NTFS_FILE_RECORD_OUTPUT_BUFFER ends
      PNTFS_FILE_RECORD_OUTPUT_BUFFER typedef ptr NTFS_FILE_RECORD_OUTPUT_BUFFER
      ;* _WIN32_WINNT >= _WIN32_WINNT_NT4 *
    endif
    if (_WIN32_WINNT ge _WIN32_WINNT_NT4)
      ;==================== FSCTL_MOVE_FILE ======================
      ; Structure for FSCTL_MOVE_FILE
      MOVE_FILE_DATA struct
        FileHandle HANDLE ?
        StartingVcn LARGE_INTEGER <>
        StartingLcn LARGE_INTEGER <>
        ClusterCount DWORD ?
      MOVE_FILE_DATA ends
      PMOVE_FILE_DATA typedef ptr MOVE_FILE_DATA
      MOVE_FILE_RECORD_DATA struct
        FileHandle HANDLE ?
        SourceFileRecord LARGE_INTEGER <>
        TargetFileRecord LARGE_INTEGER <>
      MOVE_FILE_RECORD_DATA ends
      PMOVE_FILE_RECORD_DATA typedef ptr MOVE_FILE_RECORD_DATA
      if Defined(_WIN64)
        ;  32/64 Bit thunking support structure
        MOVE_FILE_DATA32 struct
          FileHandle DWORD ?
          StartingVcn LARGE_INTEGER <>
          StartingLcn LARGE_INTEGER <>
          ClusterCount DWORD ?
        MOVE_FILE_DATA32 ends
        _MOVE_FILE_DATA32 typedef MOVE_FILE_DATA32
        PMOVE_FILE_DATA32 typedef ptr MOVE_FILE_DATA32
      endif
      ;* _WIN32_WINNT >= _WIN32_WINNT_NT4 *
    endif
    if (_WIN32_WINNT ge _WIN32_WINNT_WIN2K)
      ;==================== FSCTL_FIND_FILES_BY_SID ======================
      ; Structures for FSCTL_FIND_FILES_BY_SID
      FIND_BY_SID_DATA struct
        Restart DWORD ?
        Sid SID <>
      FIND_BY_SID_DATA ends
      PFIND_BY_SID_DATA typedef ptr FIND_BY_SID_DATA
      FIND_BY_SID_OUTPUT struct
        NextEntryOffset DWORD ?
        FileIndex DWORD ?
        FileNameLength DWORD ?
        FileName WORD 1 dup (?)
      FIND_BY_SID_OUTPUT ends
      PFIND_BY_SID_OUTPUT typedef ptr FIND_BY_SID_OUTPUT
      ;* _WIN32_WINNT >= _WIN32_WINNT_WIN2K *
    endif
    if (_WIN32_WINNT ge _WIN32_WINNT_WIN2K)
      ;  The following structures apply to Usn operations.
      ;==================== FSCTL_ENUM_USN_DATA ======================
      ; Structure for FSCTL_ENUM_USN_DATA
      MFT_ENUM_DATA_V0 struct
        StartFileReferenceNumber QWORD ?
        LowUsn USN ?
        HighUsn USN ?
      MFT_ENUM_DATA_V0 ends
      PMFT_ENUM_DATA_V0 typedef ptr MFT_ENUM_DATA_V0
      MFT_ENUM_DATA_V1 struct
        StartFileReferenceNumber QWORD ?
        LowUsn USN ?
        HighUsn USN ?
        MinMajorVersion WORD ?
        MaxMajorVersion WORD ?
      MFT_ENUM_DATA_V1 ends
      PMFT_ENUM_DATA_V1 typedef ptr MFT_ENUM_DATA_V1
      if (NTDDI_VERSION ge NTDDI_WIN8)
        MFT_ENUM_DATA typedef MFT_ENUM_DATA_V1
        PMFT_ENUM_DATA typedef ptr MFT_ENUM_DATA_V1
      else
        MFT_ENUM_DATA typedef MFT_ENUM_DATA_V0
        PMFT_ENUM_DATA typedef ptr MFT_ENUM_DATA_V0
      endif
      ;==================== FSCTL_CREATE_USN_JOURNAL ======================
      ; Structure for FSCTL_CREATE_USN_JOURNAL
      CREATE_USN_JOURNAL_DATA struct
        MaximumSize QWORD ?
        AllocationDelta QWORD ?
      CREATE_USN_JOURNAL_DATA ends
      PCREATE_USN_JOURNAL_DATA typedef ptr CREATE_USN_JOURNAL_DATA
      ;==================== FSCTL_READ_FILE_USN_DATA ====================
      ; Structure for FSCTL_READ_FILE_USN_DATA
      ;  Windows 7 and earlier releases did not use an input buffer
      ;  for this FSCTL.  It is valid to omit this, and doing so
      ;  will default to MinMajorVersion == 2, MaxMajorVersion == 2.
      READ_FILE_USN_DATA struct
        MinMajorVersion WORD ?
        MaxMajorVersion WORD ?
      READ_FILE_USN_DATA ends
      PREAD_FILE_USN_DATA typedef ptr READ_FILE_USN_DATA
      ;==================== FSCTL_READ_USN_JOURNAL ======================
      ; Structure for FSCTL_READ_USN_JOURNAL
      READ_USN_JOURNAL_DATA_V0 struct
        StartUsn USN ?
        ReasonMask DWORD ?
        ReturnOnlyOnClose DWORD ?
        Timeout QWORD ?
        BytesToWaitFor QWORD ?
        UsnJournalID QWORD ?
      READ_USN_JOURNAL_DATA_V0 ends
      PREAD_USN_JOURNAL_DATA_V0 typedef ptr READ_USN_JOURNAL_DATA_V0
      READ_USN_JOURNAL_DATA_V1 struct
        StartUsn USN ?
        ReasonMask DWORD ?
        ReturnOnlyOnClose DWORD ?
        Timeout QWORD ?
        BytesToWaitFor QWORD ?
        UsnJournalID QWORD ?
        MinMajorVersion WORD ?
        MaxMajorVersion WORD ?
      READ_USN_JOURNAL_DATA_V1 ends
      PREAD_USN_JOURNAL_DATA_V1 typedef ptr READ_USN_JOURNAL_DATA_V1
      if (NTDDI_VERSION ge NTDDI_WIN8)
        READ_USN_JOURNAL_DATA typedef READ_USN_JOURNAL_DATA_V1
        PREAD_USN_JOURNAL_DATA typedef ptr READ_USN_JOURNAL_DATA_V1
      else
        READ_USN_JOURNAL_DATA typedef READ_USN_JOURNAL_DATA_V0
        PREAD_USN_JOURNAL_DATA typedef ptr READ_USN_JOURNAL_DATA_V0
      endif
      ;==================== FSCTL_USN_TRACK_MODIFIED_RANGES ======================
      ; Structure for FSCTL_USN_TRACK_MODIFIED_RANGES
      USN_TRACK_MODIFIED_RANGES struct
        Flags DWORD ?
        Unused DWORD ?
        ChunkSize QWORD ?
        FileSizeThreshold SQWORD ?
      USN_TRACK_MODIFIED_RANGES ends
      PUSN_TRACK_MODIFIED_RANGES typedef ptr USN_TRACK_MODIFIED_RANGES
      USN_RANGE_TRACK_OUTPUT struct
        Usn USN ?
      USN_RANGE_TRACK_OUTPUT ends
      PUSN_RANGE_TRACK_OUTPUT typedef ptr USN_RANGE_TRACK_OUTPUT
      FLAG_USN_TRACK_MODIFIED_RANGES_ENABLE equ 00000001h
      ;  The initial Major.Minor version of the Usn record will be 2.0.
      ;  In general, the MinorVersion may be changed if fields are added
      ;  to this structure in such a way that the previous version of the
      ;  software can still correctly the fields it knows about.  The
      ;  MajorVersion should only be changed if the previous version of
      ;  any software using this structure would incorrectly handle new
      ;  records due to structure changes.
      ;  The first update to this will force the structure to version 2.0.
      ;  This will add the extended information about the source as
      ;  well as indicate the file name offset within the structure.
      ;  The following structure is returned with these fsctls.
      ;      FSCTL_READ_USN_JOURNAL
      ;      FSCTL_READ_FILE_USN_DATA
      ;      FSCTL_ENUM_USN_DATA
      USN_RECORD_V2 struct
        RecordLength DWORD ?
        MajorVersion WORD ?
        MinorVersion WORD ?
        FileReferenceNumber QWORD ?
        ParentFileReferenceNumber QWORD ?
        Usn USN ?
        TimeStamp LARGE_INTEGER <>
        Reason DWORD ?
        SourceInfo DWORD ?
        SecurityId DWORD ?
        FileAttributes DWORD ?
        FileNameLength WORD ?
        FileNameOffset WORD ?
        FileName WORD 1 dup (?)
      USN_RECORD_V2 ends
      PUSN_RECORD_V2 typedef ptr USN_RECORD_V2
      USN_RECORD_V3 struct
        RecordLength DWORD ?
        MajorVersion WORD ?
        MinorVersion WORD ?
        FileReferenceNumber FILE_ID_128 <>
        ParentFileReferenceNumber FILE_ID_128 <>
        Usn USN ?
        TimeStamp LARGE_INTEGER <>
        Reason DWORD ?
        SourceInfo DWORD ?
        SecurityId DWORD ?
        FileAttributes DWORD ?
        FileNameLength WORD ?
        FileNameOffset WORD ?
        FileName WORD 1 dup (?)
      USN_RECORD_V3 ends
      PUSN_RECORD_V3 typedef ptr USN_RECORD_V3
      USN_RECORD typedef USN_RECORD_V2
      PUSN_RECORD typedef ptr USN_RECORD_V2
      USN_RECORD_COMMON_HEADER struct
        RecordLength DWORD ?
        MajorVersion WORD ?
        MinorVersion WORD ?
      USN_RECORD_COMMON_HEADER ends
      PUSN_RECORD_COMMON_HEADER typedef ptr USN_RECORD_COMMON_HEADER
      USN_RECORD_EXTENT struct
        Offset_ SQWORD ?
        Length_ SQWORD ?
      USN_RECORD_EXTENT ends
      PUSN_RECORD_EXTENT typedef ptr USN_RECORD_EXTENT
      USN_RECORD_V4 struct
        Header USN_RECORD_COMMON_HEADER <>
        FileReferenceNumber FILE_ID_128 <>
        ParentFileReferenceNumber FILE_ID_128 <>
        Usn USN ?
        Reason DWORD ?
        SourceInfo DWORD ?
        RemainingExtents DWORD ?
        NumberOfExtents WORD ?
        ExtentSize WORD ?
        Extents USN_RECORD_EXTENT 1 dup (<>)
      USN_RECORD_V4 ends
      PUSN_RECORD_V4 typedef ptr USN_RECORD_V4
      USN_RECORD_UNION union
        Header USN_RECORD_COMMON_HEADER <>
        V2 USN_RECORD_V2 <>
        V3 USN_RECORD_V3 <>
        V4 USN_RECORD_V4 <>
      USN_RECORD_UNION ends
      PUSN_RECORD_UNION typedef ptr USN_RECORD_UNION
      USN_PAGE_SIZE equ (1000h)
      USN_REASON_DATA_OVERWRITE equ (00000001h)
      USN_REASON_DATA_EXTEND equ (00000002h)
      USN_REASON_DATA_TRUNCATION equ (00000004h)
      USN_REASON_NAMED_DATA_OVERWRITE equ (00000010h)
      USN_REASON_NAMED_DATA_EXTEND equ (00000020h)
      USN_REASON_NAMED_DATA_TRUNCATION equ (00000040h)
      USN_REASON_FILE_CREATE equ (00000100h)
      USN_REASON_FILE_DELETE equ (00000200h)
      USN_REASON_EA_CHANGE equ (00000400h)
      USN_REASON_SECURITY_CHANGE equ (00000800h)
      USN_REASON_RENAME_OLD_NAME equ (00001000h)
      USN_REASON_RENAME_NEW_NAME equ (00002000h)
      USN_REASON_INDEXABLE_CHANGE equ (00004000h)
      USN_REASON_BASIC_INFO_CHANGE equ (00008000h)
      USN_REASON_HARD_LINK_CHANGE equ (00010000h)
      USN_REASON_COMPRESSION_CHANGE equ (00020000h)
      USN_REASON_ENCRYPTION_CHANGE equ (00040000h)
      USN_REASON_OBJECT_ID_CHANGE equ (00080000h)
      USN_REASON_REPARSE_POINT_CHANGE equ (00100000h)
      USN_REASON_STREAM_CHANGE equ (00200000h)
      USN_REASON_TRANSACTED_CHANGE equ (00400000h)
      USN_REASON_INTEGRITY_CHANGE equ (00800000h)
      USN_REASON_DESIRED_STORAGE_CLASS_CHANGE equ (01000000h)
      USN_REASON_CLOSE equ (80000000h)
      ;==================== FSCTL_QUERY_USN_JOURNAL ======================
      ;  Structure for FSCTL_QUERY_USN_JOURNAL
      USN_JOURNAL_DATA_V0 struct
        UsnJournalID QWORD ?
        FirstUsn USN ?
        NextUsn USN ?
        LowestValidUsn USN ?
        MaxUsn USN ?
        MaximumSize QWORD ?
        AllocationDelta QWORD ?
      USN_JOURNAL_DATA_V0 ends
      PUSN_JOURNAL_DATA_V0 typedef ptr USN_JOURNAL_DATA_V0
      USN_JOURNAL_DATA_V1 struct
        UsnJournalID QWORD ?
        FirstUsn USN ?
        NextUsn USN ?
        LowestValidUsn USN ?
        MaxUsn USN ?
        MaximumSize QWORD ?
        AllocationDelta QWORD ?
        MinSupportedMajorVersion WORD ?
        MaxSupportedMajorVersion WORD ?
      USN_JOURNAL_DATA_V1 ends
      PUSN_JOURNAL_DATA_V1 typedef ptr USN_JOURNAL_DATA_V1
      USN_JOURNAL_DATA_V2 struct
        UsnJournalID QWORD ?
        FirstUsn USN ?
        NextUsn USN ?
        LowestValidUsn USN ?
        MaxUsn USN ?
        MaximumSize QWORD ?
        AllocationDelta QWORD ?
        MinSupportedMajorVersion WORD ?
        MaxSupportedMajorVersion WORD ?
        Flags DWORD ?
        RangeTrackChunkSize QWORD ?
        RangeTrackFileSizeThreshold SQWORD ?
      USN_JOURNAL_DATA_V2 ends
      PUSN_JOURNAL_DATA_V2 typedef ptr USN_JOURNAL_DATA_V2
      if (NTDDI_VERSION ge NTDDI_WIN8)
        USN_JOURNAL_DATA typedef USN_JOURNAL_DATA_V1
        PUSN_JOURNAL_DATA typedef ptr USN_JOURNAL_DATA_V1
      else
        USN_JOURNAL_DATA typedef USN_JOURNAL_DATA_V0
        PUSN_JOURNAL_DATA typedef ptr USN_JOURNAL_DATA_V0
      endif
      ;==================== FSCTL_DELETE_USN_JOURNAL ======================
      ;  Structure for FSCTL_DELETE_USN_JOURNAL
      DELETE_USN_JOURNAL_DATA struct
        UsnJournalID QWORD ?
        DeleteFlags DWORD ?
      DELETE_USN_JOURNAL_DATA ends
      PDELETE_USN_JOURNAL_DATA typedef ptr DELETE_USN_JOURNAL_DATA
      USN_DELETE_FLAG_DELETE equ (00000001h)
      USN_DELETE_FLAG_NOTIFY equ (00000002h)
      USN_DELETE_VALID_FLAGS equ (00000003h)
      ;* _WIN32_WINNT >= _WIN32_WINNT_WIN2K *
    endif
    ;==================== FSCTL_MARK_HANDLE ======================
    ;  Structure for FSCTL_MARK_HANDLE
    if (NTDDI_VERSION ge NTDDI_WIN2K)
      if _MSC_VER ge 1200
      endif
      ; unnamed struct
      MARK_HANDLE_INFO struct
        if (NTDDI_VERSION ge NTDDI_WIN8)
          union
            UsnSourceInfo DWORD ?
            CopyNumber DWORD ?
          ends
        else
          UsnSourceInfo DWORD ?
          ;*NTDDI_VERSION >= NTDDI_WIN8 *
        endif
        VolumeHandle HANDLE ?
        HandleInfo DWORD ?
        ;Flags
      MARK_HANDLE_INFO ends
      _MARK_HANDLE_INFO typedef MARK_HANDLE_INFO
      PMARK_HANDLE_INFO typedef ptr MARK_HANDLE_INFO
      if Defined(_WIN64)
        ;  32/64 Bit thunking support structure
        MARK_HANDLE_INFO32 struct
          if (NTDDI_VERSION ge NTDDI_WIN8)
            union
              UsnSourceInfo DWORD ?
              CopyNumber DWORD ?
            ends
          else
            UsnSourceInfo DWORD ?
            ;*NTDDI_VERSION >= NTDDI_WIN8 *
          endif
          VolumeHandle DWORD ?
          HandleInfo DWORD ?
          ;Flags
        MARK_HANDLE_INFO32 ends
        _MARK_HANDLE_INFO32 typedef MARK_HANDLE_INFO32
        PMARK_HANDLE_INFO32 typedef ptr MARK_HANDLE_INFO32
      endif
      if _MSC_VER ge 1200
      else
        ; unnamed struct
      endif
      ;  Flags for the additional source information above.
      ;  To set any of these values required a volume DASD handle to be specified in
      ;  VolumeHandle field.
      ;      USN_SOURCE_DATA_MANAGEMENT - Service is not modifying the external view
      ;          of any part of the file.  Typical case is HSM moving data to
      ;          and from external storage.
      ;      USN_SOURCE_AUXILIARY_DATA - Service is not modifying the external view
      ;          of the file with regard to the application that created this file.
      ;          Can be used to add private data streams to a file.
      ;      USN_SOURCE_REPLICATION_MANAGEMENT - Service is modifying a file to match
      ;          the contents of the same file which exists in another member of the
      ;          replica set.
      ;      USN_SOURCE_CLIENT_REPLICATION_MANAGEMENT - Replication is being performed
      ;          on client systems either from the cloud or servers.  A volume handle
      ;          is not required to set this value
      USN_SOURCE_DATA_MANAGEMENT equ (00000001h)
      USN_SOURCE_AUXILIARY_DATA equ (00000002h)
      USN_SOURCE_REPLICATION_MANAGEMENT equ (00000004h)
      USN_SOURCE_CLIENT_REPLICATION_MANAGEMENT equ (00000008h)
      USN_SOURCE_VALID_FLAGS equ <(USN_SOURCE_DATA_MANAGEMENT or USN_SOURCE_AUXILIARY_DATA or USN_SOURCE_REPLICATION_MANAGEMENT or USN_SOURCE_CLIENT_REPLICATION_MANAGEMENT)>
      ;  Flags for the HandleInfo field above:
      ;  ------ Introduced in W2K:
      ;  MARK_HANDLE_PROTECT_CLUSTERS - disallow any defragmenting (FSCTL_MOVE_FILE) until the
      ;      the handle is closed
      ;  ------ Introduced in Vista:
      ;  MARK_HANDLE_TXF_SYSTEM_LOG - indicates that this stream is being used as the Txf
      ;      log for an RM on the volume.  Must be called in the kernel using IRP_MN_KERNEL_CALL.
      ;  MARK_HANDLE_NOT_TXF_SYSTEM_LOG - indicates that this component is no longer using this
      ;      object as a TxF log file.
      ;  ------ Introduced in Win7:
      ;  MARK_HANDLE_REALTIME - only supported by the UDFS file system.  Marks the device
      ;      to do realtime streaming of video
      ;  MARK_HANDLE_NOT_REALTIME - only supported by the UDFS file system.  Marks the device
      ;      to no longer do realtime streaming of video
      ;  MARK_HANDLE_CLOUD_SYNC - this flag is deprecated and is no longer used
      ;  ------ Introduced in Win8
      ;  MARK_HANDLE_READ_COPY - indicates the data must be read from the specified copy
      ;      of data.  Only supported for spaces redundent volumes.
      ;  MARK_HANDLE_NOT_READ_COPY - indicates the data is no longer to be read from a specific copy.
      ;  ------ Introduced in WinBlue (win 8.1)
      ;  MARK_HANDLE_FILTER_METADATA - Flag reserved for internal Microsoft use
      ;  MARK_HANDLE_RETURN_PURGE_FAILURE - When intermixing memory mapped/cached IO with
      ;      non-cached IO the system attempts, when a non-cached io is issued, to purge
      ;      memory mappings for the range of the non-cached IO.  If these purges fail
      ;      the system normally does not return the failure to the caller which can
      ;      lead to corrupted state (which is why the documentation says to not do this).
      ;      This flag tells the system to return purge failures for the given handle
      ;      so the application can better handle this situation
      ;  ------ Introduced in WinThreshold (win10)
      ;  MARK_HANDLE_DISABLE_FILE_METADATA_OPTIMIZATION - This disabled the FRS compaction
      ;      feature on the given file.
      ;  MARK_HANDLE_ENABLE_USN_SOURCE_ON_PAGING_IO - Tells NTFS to set the given UsnSourceInfo
      ;      value on Paging writes in the USN Journal.  Traditionally this was not
      ;      done on paging writes since you did not know what thread made the given
      ;      changes.  This is an override.  This only works of the FileObject MM is
      ;      holding on to has this state associated with it.
      ;  MARK_HANDLE_SKIP_COHERENCY_SYNC_DISALLOW_WRITES - Setting this flag tells
      ;      the system that writes are not allowed on this file.  If someone tries
      ;      to open the file for write access, the operation is failed with STATUS_ACCESS_DENIED.
      ;      If a write is seen the operation is failed with STATUS_MARKED_TO_DISALLOW_WRITES
      ;  ------ Introduced in RS4 (win10)
      ;  MARK_HANDLE_ENABLE_CPU_CACHE - Flag reserved for internal Microsoft use
      ;  ------ Introduced in Cobalt (win10)
      ;  MARK_HANDLE_SUPPRESS_VOLUME_OPEN_FLUSH - Normally, on the first read/write operation
      ;      on a volume handle (DASD open) the file system flushes the volume.  This can
      ;      have performance consequences in certain scenarios.  If this flag is set on
      ;      a volume handle it will suppress that flush on first IO.
      MARK_HANDLE_PROTECT_CLUSTERS equ (00000001h)
      ;#define ReservedForFutureUse                          (0x00000002)
      MARK_HANDLE_TXF_SYSTEM_LOG equ (00000004h)
      MARK_HANDLE_NOT_TXF_SYSTEM_LOG equ (00000008h)
      ;#define ReservedForFutureUse                          (0x00000010)
      ;* NTDDI_VERSION >= NTDDI_WIN2K *
    endif
    if (NTDDI_VERSION ge NTDDI_WIN7)
      MARK_HANDLE_REALTIME equ (00000020h)
      MARK_HANDLE_NOT_REALTIME equ (00000040h)
      MARK_HANDLE_CLOUD_SYNC equ (00000800h);deprecated flag - do not use

      ;* NTDDI_VERSION >= NTDDI_WIN7 *
    endif
    if (NTDDI_VERSION ge NTDDI_WIN8)
      MARK_HANDLE_READ_COPY equ (00000080h)
      MARK_HANDLE_NOT_READ_COPY equ (00000100h)
      ;*NTDDI_VERSION >= NTDDI_WIN8 *
    endif
    if (NTDDI_VERSION ge NTDDI_WINBLUE) or (NTDDI_VERSION ge NTDDI_WIN7)
      ;Win7 check is for backward compatibility
      MARK_HANDLE_FILTER_METADATA equ (00000200h); 8.1 and newer

      MARK_HANDLE_RETURN_PURGE_FAILURE equ (00000400h); 8.1 and newer

      ;                                                      (0x00000800)        // defined above: MARK_HANDLE_CLOUD_SYNC
      ;*NTDDI_VERSION >= NTDDI_WINBLUE *
    endif
    if (NTDDI_VERSION ge NTDDI_WINTHRESHOLD)
      MARK_HANDLE_DISABLE_FILE_METADATA_OPTIMIZATION equ (00001000h)
      MARK_HANDLE_ENABLE_USN_SOURCE_ON_PAGING_IO equ (00002000h)
      MARK_HANDLE_SKIP_COHERENCY_SYNC_DISALLOW_WRITES equ (00004000h)
      ;*NTDDI_VERSION >= NTDDI_WINTHRESHOLD *
    endif
    if (NTDDI_VERSION ge NTDDI_WIN10_CO)
      MARK_HANDLE_SUPPRESS_VOLUME_OPEN_FLUSH equ (00008000h)
      ;*NTDDI_VERSION >= NTDDI_WIN10_CO *
    endif
    if (NTDDI_VERSION ge NTDDI_WIN10_RS4)
      MARK_HANDLE_ENABLE_CPU_CACHE equ (10000000h)
      ;*NTDDI_VERSION >= NTDDI_WIN10_RS4 *
    endif
    ;==================== FSCTL_SECURITY_ID_CHECK ======================
    ; Structure for FSCTL_SECURITY_ID_CHECK
    if (_WIN32_WINNT ge _WIN32_WINNT_WIN2K)
      BULK_SECURITY_TEST_DATA struct
        DesiredAccess ACCESS_MASK ?
        SecurityIds DWORD 1 dup (?)
      BULK_SECURITY_TEST_DATA ends
      PBULK_SECURITY_TEST_DATA typedef ptr BULK_SECURITY_TEST_DATA
      ;* _WIN32_WINNT >= _WIN32_WINNT_WIN2K *
    endif
    ;==================== FSCTL_IS_VOLUME_DIRTY ======================
    ;  Output flags for the FSCTL_IS_VOLUME_DIRTY is a DWORD
    if (_WIN32_WINNT ge _WIN32_WINNT_WIN2K)
      VOLUME_IS_DIRTY equ (00000001h)
      VOLUME_UPGRADE_SCHEDULED equ (00000002h)
      VOLUME_SESSION_OPEN equ (00000004h)
      ;* _WIN32_WINNT >= _WIN32_WINNT_WIN2K *
    endif
    ;==================== FSCTL_FILE_PREFETCH ======================
    if (_WIN32_WINNT ge _WIN32_WINNT_WIN2K)
      FILE_PREFETCH struct
        Type_ DWORD ?
        Count DWORD ?
        Prefetch_ QWORD 1 dup (?)
      FILE_PREFETCH ends
      _FILE_PREFETCH typedef FILE_PREFETCH
      PFILE_PREFETCH typedef ptr FILE_PREFETCH
      FILE_PREFETCH_EX struct
        Type_ DWORD ?
        Count DWORD ?
        Context POINTER ?
        Prefetch_ QWORD 1 dup (?)
      FILE_PREFETCH_EX ends
      _FILE_PREFETCH_EX typedef FILE_PREFETCH_EX
      PFILE_PREFETCH_EX typedef ptr FILE_PREFETCH_EX
      FILE_PREFETCH_TYPE_FOR_CREATE equ 1h
      FILE_PREFETCH_TYPE_FOR_DIRENUM equ 2h
      FILE_PREFETCH_TYPE_FOR_CREATE_EX equ 3h
      FILE_PREFETCH_TYPE_FOR_DIRENUM_EX equ 4h
      FILE_PREFETCH_TYPE_MAX equ 4h
      ;* _WIN32_WINNT >= _WIN32_WINNT_WIN2K *
    endif
    ;==================== FSCTL_FILESYSTEM_GET_STATISTICS ======================
    ; Structures for FSCTL_FILESYSTEM_GET_STATISTICS
    ; Filesystem performance counters
    FILESYSTEM_STATISTICS struct
      FileSystemType WORD ?
      Version WORD ?
      ; currently version 1
      SizeOfCompleteStructure DWORD ?
      ; must by a multiple of 64 bytes
      UserFileReads DWORD ?
      UserFileReadBytes DWORD ?
      UserDiskReads DWORD ?
      UserFileWrites DWORD ?
      UserFileWriteBytes DWORD ?
      UserDiskWrites DWORD ?
      MetaDataReads DWORD ?
      MetaDataReadBytes DWORD ?
      MetaDataDiskReads DWORD ?
      MetaDataWrites DWORD ?
      MetaDataWriteBytes DWORD ?
      MetaDataDiskWrites DWORD ?
      ;  The file system's private structure is appended here.
    FILESYSTEM_STATISTICS ends
    _FILESYSTEM_STATISTICS typedef FILESYSTEM_STATISTICS
    PFILESYSTEM_STATISTICS typedef ptr FILESYSTEM_STATISTICS
    ; values for FS_STATISTICS.FileSystemType
    FILESYSTEM_STATISTICS_TYPE_NTFS equ 1
    FILESYSTEM_STATISTICS_TYPE_FAT equ 2
    FILESYSTEM_STATISTICS_TYPE_EXFAT equ 3
    FILESYSTEM_STATISTICS_TYPE_REFS equ 4
    ;  File System Specific Statistics Data
    FAT_STATISTICS struct
      CreateHits DWORD ?
      SuccessfulCreates DWORD ?
      FailedCreates DWORD ?
      NonCachedReads DWORD ?
      NonCachedReadBytes DWORD ?
      NonCachedWrites DWORD ?
      NonCachedWriteBytes DWORD ?
      NonCachedDiskReads DWORD ?
      NonCachedDiskWrites DWORD ?
    FAT_STATISTICS ends
    _FAT_STATISTICS typedef FAT_STATISTICS
    PFAT_STATISTICS typedef ptr FAT_STATISTICS
    EXFAT_STATISTICS struct
      CreateHits DWORD ?
      SuccessfulCreates DWORD ?
      FailedCreates DWORD ?
      NonCachedReads DWORD ?
      NonCachedReadBytes DWORD ?
      NonCachedWrites DWORD ?
      NonCachedWriteBytes DWORD ?
      NonCachedDiskReads DWORD ?
      NonCachedDiskWrites DWORD ?
    EXFAT_STATISTICS ends
    _EXFAT_STATISTICS typedef EXFAT_STATISTICS
    PEXFAT_STATISTICS typedef ptr EXFAT_STATISTICS
    NTFS_STATISTICS struct
      LogFileFullExceptions DWORD ?
      OtherExceptions DWORD ?
      ; Other meta data io's
      MftReads DWORD ?
      MftReadBytes DWORD ?
      MftWrites DWORD ?
      MftWriteBytes DWORD ?
      struct MftWritesUserLevel
        Write WORD ?
        Create WORD ?
        SetInfo WORD ?
        Flush WORD ?
      ends
      MftWritesFlushForLogFileFull WORD ?
      MftWritesLazyWriter WORD ?
      MftWritesUserRequest WORD ?
      Mft2Writes DWORD ?
      Mft2WriteBytes DWORD ?
      struct Mft2WritesUserLevel
        Write WORD ?
        Create WORD ?
        SetInfo WORD ?
        Flush WORD ?
      ends
      Mft2WritesFlushForLogFileFull WORD ?
      Mft2WritesLazyWriter WORD ?
      Mft2WritesUserRequest WORD ?
      RootIndexReads DWORD ?
      RootIndexReadBytes DWORD ?
      RootIndexWrites DWORD ?
      RootIndexWriteBytes DWORD ?
      BitmapReads DWORD ?
      BitmapReadBytes DWORD ?
      BitmapWrites DWORD ?
      BitmapWriteBytes DWORD ?
      BitmapWritesFlushForLogFileFull WORD ?
      BitmapWritesLazyWriter WORD ?
      BitmapWritesUserRequest WORD ?
      struct BitmapWritesUserLevel
        Write WORD ?
        Create WORD ?
        SetInfo WORD ?
      ends
      MftBitmapReads DWORD ?
      MftBitmapReadBytes DWORD ?
      MftBitmapWrites DWORD ?
      MftBitmapWriteBytes DWORD ?
      MftBitmapWritesFlushForLogFileFull WORD ?
      MftBitmapWritesLazyWriter WORD ?
      MftBitmapWritesUserRequest WORD ?
      struct MftBitmapWritesUserLevel
        Write WORD ?
        Create WORD ?
        SetInfo WORD ?
        Flush WORD ?
      ends
      UserIndexReads DWORD ?
      UserIndexReadBytes DWORD ?
      UserIndexWrites DWORD ?
      UserIndexWriteBytes DWORD ?
      ; Additions for NT 5.0
      LogFileReads DWORD ?
      LogFileReadBytes DWORD ?
      LogFileWrites DWORD ?
      LogFileWriteBytes DWORD ?
      struct Allocate
        Calls DWORD ?
        ; number of individual calls to allocate clusters
        Clusters DWORD ?
        ; number of clusters allocated
        Hints DWORD ?
        ; number of times a hint was specified
        RunsReturned DWORD ?
        ; number of runs used to satisfy all the requests
        HintsHonored DWORD ?
        ; number of times the hint was useful
        HintsClusters DWORD ?
        ; number of clusters allocated via the hint
        Cache DWORD ?
        ; number of times the cache was useful other than the hint
        CacheClusters DWORD ?
        ; number of clusters allocated via the cache other than the hint
        CacheMiss DWORD ?
        ; number of times the cache wasn't useful
        CacheMissClusters DWORD ?
        ; number of clusters allocated without the cache
      ends
      ;  Additions for Windows 8.1
      DiskResourcesExhausted DWORD ?
      ;  All future expansion of this structure needs to be in NTFS_STATISTICS_EX starting Windows 10
    NTFS_STATISTICS ends
    _NTFS_STATISTICS typedef NTFS_STATISTICS
    PNTFS_STATISTICS typedef ptr NTFS_STATISTICS
    FILESYSTEM_STATISTICS_EX struct
      FileSystemType WORD ?
      Version WORD ?
      ; currently version 1
      SizeOfCompleteStructure DWORD ?
      ; must by a multiple of 64 bytes
      UserFileReads QWORD ?
      UserFileReadBytes QWORD ?
      UserDiskReads QWORD ?
      UserFileWrites QWORD ?
      UserFileWriteBytes QWORD ?
      UserDiskWrites QWORD ?
      MetaDataReads QWORD ?
      MetaDataReadBytes QWORD ?
      MetaDataDiskReads QWORD ?
      MetaDataWrites QWORD ?
      MetaDataWriteBytes QWORD ?
      MetaDataDiskWrites QWORD ?
      ;  The file system's private structure is appended here.
    FILESYSTEM_STATISTICS_EX ends
    _FILESYSTEM_STATISTICS_EX typedef FILESYSTEM_STATISTICS_EX
    PFILESYSTEM_STATISTICS_EX typedef ptr FILESYSTEM_STATISTICS_EX
    NTFS_STATISTICS_EX struct
      LogFileFullExceptions DWORD ?
      OtherExceptions DWORD ?
      ; Other meta data io's
      MftReads QWORD ?
      MftReadBytes QWORD ?
      MftWrites QWORD ?
      MftWriteBytes QWORD ?
      struct MftWritesUserLevel
        Write DWORD ?
        Create DWORD ?
        SetInfo DWORD ?
        Flush DWORD ?
      ends
      MftWritesFlushForLogFileFull DWORD ?
      MftWritesLazyWriter DWORD ?
      MftWritesUserRequest DWORD ?
      Mft2Writes QWORD ?
      Mft2WriteBytes QWORD ?
      struct Mft2WritesUserLevel
        Write DWORD ?
        Create DWORD ?
        SetInfo DWORD ?
        Flush DWORD ?
      ends
      Mft2WritesFlushForLogFileFull DWORD ?
      Mft2WritesLazyWriter DWORD ?
      Mft2WritesUserRequest DWORD ?
      RootIndexReads QWORD ?
      RootIndexReadBytes QWORD ?
      RootIndexWrites QWORD ?
      RootIndexWriteBytes QWORD ?
      BitmapReads QWORD ?
      BitmapReadBytes QWORD ?
      BitmapWrites QWORD ?
      BitmapWriteBytes QWORD ?
      BitmapWritesFlushForLogFileFull DWORD ?
      BitmapWritesLazyWriter DWORD ?
      BitmapWritesUserRequest DWORD ?
      struct BitmapWritesUserLevel
        Write DWORD ?
        Create DWORD ?
        SetInfo DWORD ?
        Flush DWORD ?
      ends
      MftBitmapReads QWORD ?
      MftBitmapReadBytes QWORD ?
      MftBitmapWrites QWORD ?
      MftBitmapWriteBytes QWORD ?
      MftBitmapWritesFlushForLogFileFull DWORD ?
      MftBitmapWritesLazyWriter DWORD ?
      MftBitmapWritesUserRequest DWORD ?
      struct MftBitmapWritesUserLevel
        Write DWORD ?
        Create DWORD ?
        SetInfo DWORD ?
        Flush DWORD ?
      ends
      UserIndexReads QWORD ?
      UserIndexReadBytes QWORD ?
      UserIndexWrites QWORD ?
      UserIndexWriteBytes QWORD ?
      ; Additions for NT 5.0
      LogFileReads QWORD ?
      LogFileReadBytes QWORD ?
      LogFileWrites QWORD ?
      LogFileWriteBytes QWORD ?
      struct Allocate
        Calls DWORD ?
        ; number of individual calls to allocate clusters
        RunsReturned DWORD ?
        ; number of runs used to satisfy all the requests
        Hints DWORD ?
        ; number of times a hint was specified
        HintsHonored DWORD ?
        ; number of times the hint was useful
        Cache DWORD ?
        ; number of times the cache was useful other than the hint
        CacheMiss DWORD ?
        ; number of times the cache wasn't useful
        Clusters QWORD ?
        ; number of clusters allocated
        HintsClusters QWORD ?
        ; number of clusters allocated via the hint
        CacheClusters QWORD ?
        ; number of clusters allocated via the cache other than the hint
        CacheMissClusters QWORD ?
        ; number of clusters allocated without the cache
      ends
      ;  Additions for Windows 8.1
      DiskResourcesExhausted DWORD ?
      ;  Additions for Windows 10
      VolumeTrimCount QWORD ?
      VolumeTrimTime QWORD ?
      VolumeTrimByteCount QWORD ?
      FileLevelTrimCount QWORD ?
      FileLevelTrimTime QWORD ?
      FileLevelTrimByteCount QWORD ?
      VolumeTrimSkippedCount QWORD ?
      VolumeTrimSkippedByteCount QWORD ?
      ;  Additions for NtfsFillStatInfoFromMftRecord
      NtfsFillStatInfoFromMftRecordCalledCount QWORD ?
      NtfsFillStatInfoFromMftRecordBailedBecauseOfAttributeListCount QWORD ?
      NtfsFillStatInfoFromMftRecordBailedBecauseOfNonResReparsePointCount QWORD ?
    NTFS_STATISTICS_EX ends
    _NTFS_STATISTICS_EX typedef NTFS_STATISTICS_EX
    PNTFS_STATISTICS_EX typedef ptr NTFS_STATISTICS_EX
    ;==================== FSCTL_SET_OBJECT_ID ================================
    ;==================== FSCTL_GET_OBJECT_ID ================================
    ;==================== FSCTL_CREATE_OR_GET_OBJECT_ID ======================
    ;  Structures for FSCTL_SET_OBJECT_ID, FSCTL_GET_OBJECT_ID, and
    ;  FSCTL_CREATE_OR_GET_OBJECT_ID
    if (_WIN32_WINNT ge _WIN32_WINNT_WIN2K)
      if _MSC_VER ge 1200
      endif
      ; unnamed struct
      FILE_OBJECTID_BUFFER struct
        ;  This is the portion of the object id that is indexed.
        ObjectId BYTE 16 dup (?)
        ;  This portion of the object id is not indexed, it's just
        ;  some metadata for the user's benefit.
        union
          struct
            BirthVolumeId BYTE 16 dup (?)
            BirthObjectId BYTE 16 dup (?)
            DomainId BYTE 16 dup (?)
          ends
          ExtendedInfo BYTE 48 dup (?)
        ends
      FILE_OBJECTID_BUFFER ends
      _FILE_OBJECTID_BUFFER typedef FILE_OBJECTID_BUFFER
      PFILE_OBJECTID_BUFFER typedef ptr FILE_OBJECTID_BUFFER
      if _MSC_VER ge 1200
      else
        ;* nonstandard extension used : nameless struct/union *
      endif
      ;* _WIN32_WINNT >= _WIN32_WINNT_WIN2K *
    endif
    ;==================== FSCTL_SET_SPARSE ======================
    ; Structure for FSCTL_SET_SPARSE
    if (_WIN32_WINNT ge _WIN32_WINNT_WIN2K)
      FILE_SET_SPARSE_BUFFER struct
        SetSparse BYTE ?
      FILE_SET_SPARSE_BUFFER ends
      _FILE_SET_SPARSE_BUFFER typedef FILE_SET_SPARSE_BUFFER
      PFILE_SET_SPARSE_BUFFER typedef ptr FILE_SET_SPARSE_BUFFER
      ;* _WIN32_WINNT >= _WIN32_WINNT_WIN2K *
    endif
    ;==================== FSCTL_SET_ZERO_DATA ======================
    ; Structure for FSCTL_SET_ZERO_DATA
    if (_WIN32_WINNT ge _WIN32_WINNT_WIN2K)
      FILE_ZERO_DATA_INFORMATION struct
        FileOffset LARGE_INTEGER <>
        BeyondFinalZero LARGE_INTEGER <>
      FILE_ZERO_DATA_INFORMATION ends
      _FILE_ZERO_DATA_INFORMATION typedef FILE_ZERO_DATA_INFORMATION
      PFILE_ZERO_DATA_INFORMATION typedef ptr FILE_ZERO_DATA_INFORMATION
      ;* _WIN32_WINNT >= _WIN32_WINNT_WIN2K *
    endif
    if (_WIN32_WINNT ge _WIN32_WINNT_WINTHRESHOLD)
      FILE_ZERO_DATA_INFORMATION_EX struct
        FileOffset LARGE_INTEGER <>
        BeyondFinalZero LARGE_INTEGER <>
        Flags DWORD ?
      FILE_ZERO_DATA_INFORMATION_EX ends
      _FILE_ZERO_DATA_INFORMATION_EX typedef FILE_ZERO_DATA_INFORMATION_EX
      PFILE_ZERO_DATA_INFORMATION_EX typedef ptr FILE_ZERO_DATA_INFORMATION_EX
      ;  When set tells the file system to not purge the cache for the given range
      ;  being zeroed
      FILE_ZERO_DATA_INFORMATION_FLAG_PRESERVE_CACHED_DATA equ (00000001h)
      ;* _WIN32_WINNT >= _WIN32_WINNT_WINTHRESHOLD *
    endif
    ;==================== FSCTL_QUERY_ALLOCATED_RANGES ======================
    ; Structure for FSCTL_QUERY_ALLOCATED_RANGES
    if (_WIN32_WINNT ge _WIN32_WINNT_WIN2K)
      ; Querying the allocated ranges requires an output buffer to store the
      ; allocated ranges and an input buffer to specify the range to query.
      ; The input buffer contains a single entry, the output buffer is an
      ; array of the following structure.
      FILE_ALLOCATED_RANGE_BUFFER struct
        FileOffset LARGE_INTEGER <>
        Length_ LARGE_INTEGER <>
      FILE_ALLOCATED_RANGE_BUFFER ends
      _FILE_ALLOCATED_RANGE_BUFFER typedef FILE_ALLOCATED_RANGE_BUFFER
      PFILE_ALLOCATED_RANGE_BUFFER typedef ptr FILE_ALLOCATED_RANGE_BUFFER
      ;* _WIN32_WINNT >= _WIN32_WINNT_WIN2K *
    endif
    ;====================== FSCTL_SET_ENCRYPTION ===============================
    ;====================== FSCTL_WRITE_RAW_ENCRYPTED ==========================
    ;====================== FSCTL_READ_RAW_ENCRYPTED ===========================
    ; Structures for FSCTL_SET_ENCRYPTION, FSCTL_WRITE_RAW_ENCRYPTED, and FSCTL_READ_RAW_ENCRYPTED
    if (_WIN32_WINNT ge _WIN32_WINNT_WIN2K)
      ;  The input buffer to set encryption indicates whether we are to encrypt/decrypt a file
      ;  or an individual stream.
      ENCRYPTION_BUFFER struct
        EncryptionOperation DWORD ?
        Private_ BYTE 1 dup (?)
      ENCRYPTION_BUFFER ends
      _ENCRYPTION_BUFFER typedef ENCRYPTION_BUFFER
      PENCRYPTION_BUFFER typedef ptr ENCRYPTION_BUFFER
      FILE_SET_ENCRYPTION equ 00000001h
      FILE_CLEAR_ENCRYPTION equ 00000002h
      STREAM_SET_ENCRYPTION equ 00000003h
      STREAM_CLEAR_ENCRYPTION equ 00000004h
      MAXIMUM_ENCRYPTION_VALUE equ 00000004h
      ;  The optional output buffer to set encryption indicates that the last encrypted
      ;  stream in a file has been marked as decrypted.
      DECRYPTION_STATUS_BUFFER struct
        NoEncryptedStreams BYTE ?
      DECRYPTION_STATUS_BUFFER ends
      _DECRYPTION_STATUS_BUFFER typedef DECRYPTION_STATUS_BUFFER
      PDECRYPTION_STATUS_BUFFER typedef ptr DECRYPTION_STATUS_BUFFER
      ENCRYPTION_FORMAT_DEFAULT equ (01h)
      ;  Request Encrypted Data structure.  This is used to indicate
      ;  the range of the file to read.  It also describes the
      ;  output buffer used to return the data.
      REQUEST_RAW_ENCRYPTED_DATA struct
        ;  Requested file offset and requested length to read.
        ;  The fsctl will round the starting offset down
        ;  to a file system boundary.  It will also
        ;  round the length up to a file system boundary.
        FileOffset SQWORD ?
        Length_ DWORD ?
      REQUEST_RAW_ENCRYPTED_DATA ends
      _REQUEST_RAW_ENCRYPTED_DATA typedef REQUEST_RAW_ENCRYPTED_DATA
      PREQUEST_RAW_ENCRYPTED_DATA typedef ptr REQUEST_RAW_ENCRYPTED_DATA
      ;  Encrypted Data Information structure.  This structure
      ;  is used to return raw encrypted data from a file in
      ;  order to perform off-line recovery.  The data will be
      ;  encrypted or encrypted and compressed.  The off-line
      ;  service will need to use the encryption and compression
      ;  format information to recover the file data.  In the
      ;  event that the data is both encrypted and compressed then
      ;  the decryption must occur before decompression.  All
      ;  the data units below must be encrypted and compressed
      ;  with the same format.
      ;  The data will be returned in units.  The data unit size
      ;  will be fixed per request.  If the data is compressed
      ;  then the data unit size will be the compression unit size.
      ;  This structure is at the beginning of the buffer used to
      ;  return the encrypted data.  The actual raw bytes from
      ;  the file will follow this buffer.  The offset of the
      ;  raw bytes from the beginning of this structure is
      ;  specified in the REQUEST_RAW_ENCRYPTED_DATA structure
      ;  described above.
      ENCRYPTED_DATA_INFO struct
        ;  This is the file offset for the first entry in the
        ;  data block array.  The file system will round
        ;  the requested start offset down to a boundary
        ;  that is consistent with the format of the file.
        StartingFileOffset QWORD ?
        ;  Data offset in output buffer.  The output buffer
        ;  begins with an ENCRYPTED_DATA_INFO structure.
        ;  The file system will then store the raw bytes from
        ;  disk beginning at the following offset within the
        ;  output buffer.
        OutputBufferOffset DWORD ?
        ;  The number of bytes being returned that are within
        ;  the size of the file.  If this value is less than
        ;  (NumberOfDataBlocks << DataUnitShift), it means the
        ;  end of the file occurs within this transfer.  Any
        ;  data beyond file size is invalid and was never
        ;  passed to the encryption driver.
        BytesWithinFileSize DWORD ?
        ;  The number of bytes being returned that are below
        ;  valid data length.  If this value is less than
        ;  (NumberOfDataBlocks << DataUnitShift), it means the
        ;  end of the valid data occurs within this transfer.
        ;  After decrypting the data from this transfer, any
        ;  byte(s) beyond valid data length must be zeroed.
        BytesWithinValidDataLength DWORD ?
        ;  Code for the compression format as defined in
        ;  ntrtl.h.  Note that COMPRESSION_FORMAT_NONE
        ;  and COMPRESSION_FORMAT_DEFAULT are invalid if
        ;  any of the described chunks are compressed.
        CompressionFormat WORD ?
        ;  The DataUnit is the granularity used to access the
        ;  disk.  It will be the same as the compression unit
        ;  size for a compressed file.  For an uncompressed
        ;  file, it will be some cluster-aligned power of 2 that
        ;  the file system deems convenient.  A caller should
        ;  not expect that successive calls will have the
        ;  same data unit shift value as the previous call.
        ;  Since chunks and compression units are expected to be
        ;  powers of 2 in size, we express them log2.  So, for
        ;  example (1 << ChunkShift) == ChunkSizeInBytes.  The
        ;  ClusterShift indicates how much space must be saved
        ;  to successfully compress a compression unit - each
        ;  successfully compressed data unit must occupy
        ;  at least one cluster less in bytes than an uncompressed
        ;  data block unit.
        DataUnitShift BYTE ?
        ChunkShift BYTE ?
        ClusterShift BYTE ?
        ;  The format for the encryption.
        EncryptionFormat BYTE ?
        ;  This is the number of entries in the data block size
        ;  array.
        NumberOfDataBlocks WORD ?
        ;  This is an array of sizes in the data block array.  There
        ;  must be one entry in this array for each data block
        ;  read from disk.  The size has a different meaning
        ;  depending on whether the file is compressed.
        ;  A size of zero always indicates that the final data consists entirely
        ;  of zeroes.  There is no decryption or decompression to
        ;  perform.
        ;  If the file is compressed then the data block size indicates
        ;  whether this block is compressed.  A size equal to
        ;  the block size indicates that the corresponding block did
        ;  not compress.  Any other non-zero size indicates the
        ;  size of the compressed data which needs to be
        ;  decrypted/decompressed.
        ;  If the file is not compressed then the data block size
        ;  indicates the amount of data within the block that
        ;  needs to be decrypted.  Any other non-zero size indicates
        ;  that the remaining bytes in the data unit within the file
        ;  consists of zeros.  An example of this is when the
        ;  the read spans the valid data length of the file.  There
        ;  is no data to decrypt past the valid data length.
        DataBlockSize DWORD ANYSIZE_ARRAY dup (?)
      ENCRYPTED_DATA_INFO ends
      _ENCRYPTED_DATA_INFO typedef ENCRYPTED_DATA_INFO
      PENCRYPTED_DATA_INFO typedef ptr ENCRYPTED_DATA_INFO
      ;* _WIN32_WINNT >= _WIN32_WINNT_WIN2K *
    endif
    if (_WIN32_WINNT ge _WIN32_WINNT_WIN7)
      ;  Extended encryption structure for read/write raw encrypted operations.
      ;  This was needed so we can explicitly indicate if a file is sparse or not
      ;  Flag to indicate the encrypted file is sparse
      ENCRYPTED_DATA_INFO_SPARSE_FILE equ 1
      EXTENDED_ENCRYPTED_DATA_INFO struct
        ;  This is really a 4 byte character array which
        ;  must have the value "EXTD".  We use this
        ;  to determine if we should read the extended data
        ;  or not.
        ExtendedCode DWORD ?
        ;  The length of the extended data structure
        Length_ DWORD ?
        ;  Encrypted data flags (currently only sparse is defined)
        Flags DWORD ?
        Reserved DWORD ?
      EXTENDED_ENCRYPTED_DATA_INFO ends
      _EXTENDED_ENCRYPTED_DATA_INFO typedef EXTENDED_ENCRYPTED_DATA_INFO
      PEXTENDED_ENCRYPTED_DATA_INFO typedef ptr EXTENDED_ENCRYPTED_DATA_INFO
      ;*(_WIN32_WINNT >= _WIN32_WINNT_WIN7)*
    endif
    ;======================== FSCTL_READ_FROM_PLEX ===========================
    ;  Request Plex Read Data structure.  This is used to indicate
    ;  the range of the file to read.  It also describes
    ;  which plex to perform the read from.
    if (_WIN32_WINNT ge _WIN32_WINNT_WIN2K)
      PLEX_READ_DATA_REQUEST struct
        ;  Requested offset and length to read.
        ;  The offset can be the virtual offset (vbo) in to a file,
        ;  or a volume. In the case of a file offset,
        ;  the fsd will round the starting offset down
        ;  to a file system boundary.  It will also
        ;  round the length up to a file system boundary and
        ;  enforce any other applicable limits.
        ByteOffset LARGE_INTEGER <>
        ByteLength DWORD ?
        PlexNumber DWORD ?
      PLEX_READ_DATA_REQUEST ends
      _PLEX_READ_DATA_REQUEST typedef PLEX_READ_DATA_REQUEST
      PPLEX_READ_DATA_REQUEST typedef ptr PLEX_READ_DATA_REQUEST
      ;* _WIN32_WINNT >= _WIN32_WINNT_WIN2K *
    endif
    ;======================== FSCTL_SIS_COPYFILE ===========================
    ; Source and destination file names are passed in the FileNameBuffer.
    ; Both strings are null terminated, with the source name starting at
    ; the beginning of FileNameBuffer, and the destination name immediately
    ; following.  Length fields include terminating nulls.
    if (_WIN32_WINNT ge _WIN32_WINNT_WIN2K)
      SI_COPYFILE struct
        SourceFileNameLength DWORD ?
        DestinationFileNameLength DWORD ?
        Flags DWORD ?
        FileNameBuffer WORD 1 dup (?)
      SI_COPYFILE ends
      _SI_COPYFILE typedef SI_COPYFILE
      PSI_COPYFILE typedef ptr SI_COPYFILE
      COPYFILE_SIS_LINK equ 0001h; Copy only if source is SIS

      COPYFILE_SIS_REPLACE equ 0002h; Replace destination if it exists, otherwise don't.

      COPYFILE_SIS_FLAGS equ 0003h
      ;* _WIN32_WINNT >= _WIN32_WINNT_WIN2K *
    endif
    ;======================== FSCTL_MAKE_MEDIA_COMPATIBLE ===========================
    ;  Input parameter structure for FSCTL_MAKE_MEDIA_COMPATIBLE
    if (_WIN32_WINNT ge _WIN32_WINNT_VISTA)
      FILE_MAKE_COMPATIBLE_BUFFER struct
        CloseDisc BYTE ?
      FILE_MAKE_COMPATIBLE_BUFFER ends
      _FILE_MAKE_COMPATIBLE_BUFFER typedef FILE_MAKE_COMPATIBLE_BUFFER
      PFILE_MAKE_COMPATIBLE_BUFFER typedef ptr FILE_MAKE_COMPATIBLE_BUFFER
      ;======================== FSCTL_SET_DEFECT_MANAGEMENT ===========================
      ;  Input parameter structure for FSCTL_SET_DEFECT_MANAGEMENT
      FILE_SET_DEFECT_MGMT_BUFFER struct
        Disable BYTE ?
      FILE_SET_DEFECT_MGMT_BUFFER ends
      _FILE_SET_DEFECT_MGMT_BUFFER typedef FILE_SET_DEFECT_MGMT_BUFFER
      PFILE_SET_DEFECT_MGMT_BUFFER typedef ptr FILE_SET_DEFECT_MGMT_BUFFER
      ;======================== FSCTL_QUERY_SPARING_INFO ===========================
      ;  Output structure for FSCTL_QUERY_SPARING_INFO
      FILE_QUERY_SPARING_BUFFER struct
        SparingUnitBytes DWORD ?
        SoftwareSparing BYTE ?
        TotalSpareBlocks DWORD ?
        FreeSpareBlocks DWORD ?
      FILE_QUERY_SPARING_BUFFER ends
      _FILE_QUERY_SPARING_BUFFER typedef FILE_QUERY_SPARING_BUFFER
      PFILE_QUERY_SPARING_BUFFER typedef ptr FILE_QUERY_SPARING_BUFFER
      ;===================== FSCTL_QUERY_ON_DISK_VOLUME_INFO ========================
      ;  Output structure for FSCTL_QUERY_ON_DISK_VOLUME_INFO
      FILE_QUERY_ON_DISK_VOL_INFO_BUFFER struct
        DirectoryCount LARGE_INTEGER <>
        ; -1 = unknown
        FileCount LARGE_INTEGER <>
        ; -1 = unknown
        FsFormatMajVersion WORD ?
        ; -1 = unknown or n/a
        FsFormatMinVersion WORD ?
        ; -1 = unknown or n/a
        FsFormatName WORD 12 dup (?)
        FormatTime LARGE_INTEGER <>
        LastUpdateTime LARGE_INTEGER <>
        CopyrightInfo WORD 34 dup (?)
        AbstractInfo WORD 34 dup (?)
        FormattingImplementationInfo WORD 34 dup (?)
        LastModifyingImplementationInfo WORD 34 dup (?)
      FILE_QUERY_ON_DISK_VOL_INFO_BUFFER ends
      _FILE_QUERY_ON_DISK_VOL_INFO_BUFFER typedef FILE_QUERY_ON_DISK_VOL_INFO_BUFFER
      PFILE_QUERY_ON_DISK_VOL_INFO_BUFFER typedef ptr FILE_QUERY_ON_DISK_VOL_INFO_BUFFER
      ;===================== FSCTL_SET_REPAIR ========================
      ;  Input flags for FSCTL_SET_REPAIR
      SET_REPAIR_ENABLED equ (00000001h)
      SET_REPAIR_WARN_ABOUT_DATA_LOSS equ (00000008h)
      SET_REPAIR_DISABLED_AND_BUGCHECK_ON_CORRUPT equ (00000010h)
      SET_REPAIR_VALID_MASK equ (00000019h)
      ;===================== FSCTL_INITIATE_REPAIR ========================
      ;  Optional output structure for FSCTL_INITIATE_REPAIR
      FILE_INITIATE_REPAIR_HINT1_FILE_RECORD_NOT_IN_USE equ (0000000000000001h)
      FILE_INITIATE_REPAIR_HINT1_FILE_RECORD_REUSED equ (0000000000000002h)
      FILE_INITIATE_REPAIR_HINT1_FILE_RECORD_NOT_EXIST equ (0000000000000004h)
      FILE_INITIATE_REPAIR_HINT1_FILE_RECORD_NOT_BASE_RECORD equ (0000000000000008h)
      FILE_INITIATE_REPAIR_HINT1_SYSTEM_FILE equ (0000000000000010h)
      FILE_INITIATE_REPAIR_HINT1_NOT_IMPLEMENTED equ (0000000000000020h)
      FILE_INITIATE_REPAIR_HINT1_UNABLE_TO_REPAIR equ (0000000000000040h)
      FILE_INITIATE_REPAIR_HINT1_REPAIR_DISABLED equ (0000000000000080h)
      FILE_INITIATE_REPAIR_HINT1_RECURSIVELY_CORRUPTED equ (0000000000000100h)
      FILE_INITIATE_REPAIR_HINT1_ORPHAN_GENERATED equ (0000000000000200h)
      FILE_INITIATE_REPAIR_HINT1_REPAIRED equ (0000000000000400h)
      FILE_INITIATE_REPAIR_HINT1_NOTHING_WRONG equ (0000000000000800h)
      FILE_INITIATE_REPAIR_HINT1_ATTRIBUTE_NOT_FOUND equ (0000000000001000h)
      FILE_INITIATE_REPAIR_HINT1_POTENTIAL_CROSSLINK equ (0000000000002000h)
      FILE_INITIATE_REPAIR_HINT1_STALE_INFORMATION equ (0000000000004000h)
      FILE_INITIATE_REPAIR_HINT1_CLUSTERS_ALREADY_IN_USE equ (0000000000008000h)
      FILE_INITIATE_REPAIR_HINT1_LCN_NOT_EXIST equ (0000000000010000h)
      FILE_INITIATE_REPAIR_HINT1_INVALID_RUN_LENGTH equ (0000000000020000h)
      FILE_INITIATE_REPAIR_HINT1_FILE_RECORD_NOT_ORPHAN equ (0000000000040000h)
      FILE_INITIATE_REPAIR_HINT1_FILE_RECORD_IS_BASE_RECORD equ (0000000000080000h)
      FILE_INITIATE_REPAIR_HINT1_INVALID_ARRAY_LENGTH_COUNT equ (0000000000100000h)
      FILE_INITIATE_REPAIR_HINT1_SID_VALID equ (0000000000200000h)
      FILE_INITIATE_REPAIR_HINT1_SID_MISMATCH equ (0000000000400000h)
      FILE_INITIATE_REPAIR_HINT1_INVALID_PARENT equ (0000000000800000h)
      FILE_INITIATE_REPAIR_HINT1_PARENT_FILE_RECORD_NOT_IN_USE equ (0000000001000000h)
      FILE_INITIATE_REPAIR_HINT1_PARENT_FILE_RECORD_REUSED equ (0000000002000000h)
      FILE_INITIATE_REPAIR_HINT1_PARENT_FILE_RECORD_NOT_EXIST equ (0000000004000000h)
      FILE_INITIATE_REPAIR_HINT1_PARENT_FILE_RECORD_NOT_BASE_RECORD equ (0000000008000000h)
      FILE_INITIATE_REPAIR_HINT1_PARENT_FILE_RECORD_NOT_INDEX equ (0000000010000000h)
      FILE_INITIATE_REPAIR_HINT1_VALID_INDEX_ENTRY equ (0000000020000000h)
      FILE_INITIATE_REPAIR_HINT1_OUT_OF_GENERIC_NAMES equ (0000000040000000h)
      FILE_INITIATE_REPAIR_HINT1_OUT_OF_RESOURCE equ (0000000080000000h)
      FILE_INITIATE_REPAIR_HINT1_INVALID_LCN equ (0000000100000000h)
      FILE_INITIATE_REPAIR_HINT1_INVALID_VCN equ (0000000200000000h)
      FILE_INITIATE_REPAIR_HINT1_NAME_CONFLICT equ (0000000400000000h)
      FILE_INITIATE_REPAIR_HINT1_ORPHAN equ (0000000800000000h)
      FILE_INITIATE_REPAIR_HINT1_ATTRIBUTE_TOO_SMALL equ (0000001000000000h)
      FILE_INITIATE_REPAIR_HINT1_ATTRIBUTE_NON_RESIDENT equ (0000002000000000h)
      FILE_INITIATE_REPAIR_HINT1_DENY_DEFRAG equ (0000004000000000h)
      FILE_INITIATE_REPAIR_HINT1_PREVIOUS_PARENT_STILL_VALID equ (0000008000000000h)
      FILE_INITIATE_REPAIR_HINT1_INDEX_ENTRY_MISMATCH equ (0000010000000000h)
      FILE_INITIATE_REPAIR_HINT1_INVALID_ORPHAN_RECOVERY_NAME equ (0000020000000000h)
      FILE_INITIATE_REPAIR_HINT1_MULTIPLE_FILE_NAME_ATTRIBUTES equ (0000040000000000h)
      ;  We need to expose CLSN definition???????????????
      CLSN typedef DWORDLONG
      FILE_INITIATE_REPAIR_OUTPUT_BUFFER struct
        Hint1 QWORD ?
        Hint2 QWORD ?
        Clsn CLSN ?
        Status DWORD ?
      FILE_INITIATE_REPAIR_OUTPUT_BUFFER ends
      _FILE_INITIATE_REPAIR_OUTPUT_BUFFER typedef FILE_INITIATE_REPAIR_OUTPUT_BUFFER
      PFILE_INITIATE_REPAIR_OUTPUT_BUFFER typedef ptr FILE_INITIATE_REPAIR_OUTPUT_BUFFER
      ;===================== FSCTL_SHRINK_VOLUME ========================
      ;  Input structures for FSCTL_SHRINK_VOLUME.
      SHRINK_VOLUME_REQUEST_TYPES typedef SDWORD
      ShrinkPrepare equ 1
      ShrinkCommit equ 2
      ShrinkAbort equ 3
      _SHRINK_VOLUME_REQUEST_TYPES typedef SHRINK_VOLUME_REQUEST_TYPES
      PSHRINK_VOLUME_REQUEST_TYPES typedef ptr SHRINK_VOLUME_REQUEST_TYPES
      SHRINK_VOLUME_INFORMATION struct
        ShrinkRequestType SHRINK_VOLUME_REQUEST_TYPES ?
        Flags QWORD ?
        NewNumberOfSectors SQWORD ?
      SHRINK_VOLUME_INFORMATION ends
      _SHRINK_VOLUME_INFORMATION typedef SHRINK_VOLUME_INFORMATION
      PSHRINK_VOLUME_INFORMATION typedef ptr SHRINK_VOLUME_INFORMATION
      ;========= FSCTL_TXFS_MODIFY_RM,  FSCTL_TXFS_QUERY_RM_INFORMATION ============
      ;  Structures for FSCTL_TXFS_MODIFY_RM and FSCTL_TXFS_QUERY_RM_INFORMATION
      ;  For ModifyRM, TXFS_RM_FLAG_LOG_GROWTH_INCREMENT_NUM_CONTAINERS and
      ;  TXFS_RM_FLAG_LOG_GROWTH_INCREMENT_PERCENT are mutually exclusive.
      ;  You can specify the log growth amount in number of containers or as a percentage.
      ;  For ModifyRM, TXFS_RM_FLAG_LOG_CONTAINER_COUNT_MAX and
      ;  TXFS_RM_FLAG_LOG_NO_CONTAINER_COUNT_MAX are mutually exclusive.
      ;  For ModifyRM, TXFS_RM_FLAG_LOG_CONTAINER_COUNT_MIN and
      ;  TXFS_RM_FLAG_LOG_NO_CONTAINER_COUNT_MIN are mutually exclusive.
      ;  For ModifyRM, TXFS_RM_FLAG_RESET_RM_AT_NEXT_START and
      ;  TXFS_RM_FLAG_DO_NOT_RESET_RM_AT_NEXT_START are mutually exclusive and only
      ;  apply to default RMs.
      ;  For ModifyRM, TXFS_RM_FLAG_PREFER_CONSISTENCY and
      ;  TXFS_RM_FLAG_PREFER_AVAILABILITY are mutually exclusive.  After calling ModifyRM
      ;  with one of these flags set the RM must be restarted for the change to take effect.
      TXFS_RM_FLAG_LOGGING_MODE equ 00000001h
      TXFS_RM_FLAG_RENAME_RM equ 00000002h
      TXFS_RM_FLAG_LOG_CONTAINER_COUNT_MAX equ 00000004h
      TXFS_RM_FLAG_LOG_CONTAINER_COUNT_MIN equ 00000008h
      TXFS_RM_FLAG_LOG_GROWTH_INCREMENT_NUM_CONTAINERS equ 00000010h
      TXFS_RM_FLAG_LOG_GROWTH_INCREMENT_PERCENT equ 00000020h
      TXFS_RM_FLAG_LOG_AUTO_SHRINK_PERCENTAGE equ 00000040h
      TXFS_RM_FLAG_LOG_NO_CONTAINER_COUNT_MAX equ 00000080h
      TXFS_RM_FLAG_LOG_NO_CONTAINER_COUNT_MIN equ 00000100h
      TXFS_RM_FLAG_GROW_LOG equ 00000400h
      TXFS_RM_FLAG_SHRINK_LOG equ 00000800h
      TXFS_RM_FLAG_ENFORCE_MINIMUM_SIZE equ 00001000h
      TXFS_RM_FLAG_PRESERVE_CHANGES equ 00002000h
      TXFS_RM_FLAG_RESET_RM_AT_NEXT_START equ 00004000h
      TXFS_RM_FLAG_DO_NOT_RESET_RM_AT_NEXT_START equ 00008000h
      TXFS_RM_FLAG_PREFER_CONSISTENCY equ 00010000h
      TXFS_RM_FLAG_PREFER_AVAILABILITY equ 00020000h
      TXFS_LOGGING_MODE_SIMPLE equ (0001h)
      TXFS_LOGGING_MODE_FULL equ (0002h)
      TXFS_TRANSACTION_STATE_NONE equ 00h
      TXFS_TRANSACTION_STATE_ACTIVE equ 01h
      TXFS_TRANSACTION_STATE_PREPARED equ 02h
      TXFS_TRANSACTION_STATE_NOTACTIVE equ 03h
      TXFS_MODIFY_RM_VALID_FLAGS equ <(TXFS_RM_FLAG_LOGGING_MODE or TXFS_RM_FLAG_RENAME_RM or TXFS_RM_FLAG_LOG_CONTAINER_COUNT_MAX or TXFS_RM_FLAG_LOG_CONTAINER_COUNT_MIN or TXFS_RM_FLAG_LOG_GROWTH_INCREMENT_NUM_CONTAINERS or TXFS_RM_FLAG_LOG_GROWTH_INCREMENT_PERCENT or TXFS_RM_FLAG_LOG_AUTO_SHRINK_PERCENTAGE or TXFS_RM_FLAG_LOG_NO_CONTAINER_COUNT_MAX or TXFS_RM_FLAG_LOG_NO_CONTAINER_COUNT_MIN or TXFS_RM_FLAG_SHRINK_LOG or TXFS_RM_FLAG_GROW_LOG or TXFS_RM_FLAG_ENFORCE_MINIMUM_SIZE or TXFS_RM_FLAG_PRESERVE_CHANGES or TXFS_RM_FLAG_RESET_RM_AT_NEXT_START or TXFS_RM_FLAG_DO_NOT_RESET_RM_AT_NEXT_START or TXFS_RM_FLAG_PREFER_CONSISTENCY or TXFS_RM_FLAG_PREFER_AVAILABILITY)>
      TXFS_MODIFY_RM struct
        ;  TXFS_RM_FLAG_* flags
        Flags DWORD ?
        ;  Maximum log container count if TXFS_RM_FLAG_LOG_CONTAINER_COUNT_MAX is set.
        LogContainerCountMax DWORD ?
        ;  Minimum log container count if TXFS_RM_FLAG_LOG_CONTAINER_COUNT_MIN is set.
        LogContainerCountMin DWORD ?
        ;  Target log container count for TXFS_RM_FLAG_SHRINK_LOG or _GROW_LOG.
        LogContainerCount DWORD ?
        ;  When the log is full, increase its size by this much.  Indicated as either a percent of
        ;  the log size or absolute container count, depending on which of the TXFS_RM_FLAG_LOG_GROWTH_INCREMENT_*
        ;  flags is set.
        LogGrowthIncrement DWORD ?
        ;  Sets autoshrink policy if TXFS_RM_FLAG_LOG_AUTO_SHRINK_PERCENTAGE is set.  Autoshrink
        ;  makes the log shrink so that no more than this percentage of the log is free at any time.
        LogAutoShrinkPercentage DWORD ?
        ;  Reserved.
        Reserved QWORD ?
        ;  If TXFS_RM_FLAG_LOGGING_MODE is set, this must contain one of TXFS_LOGGING_MODE_SIMPLE
        ;  or TXFS_LOGGING_MODE_FULL.
        LoggingMode WORD ?
      TXFS_MODIFY_RM ends
      _TXFS_MODIFY_RM typedef TXFS_MODIFY_RM
      PTXFS_MODIFY_RM typedef ptr TXFS_MODIFY_RM
      TXFS_RM_STATE_NOT_STARTED equ 0
      TXFS_RM_STATE_STARTING equ 1
      TXFS_RM_STATE_ACTIVE equ 2
      TXFS_RM_STATE_SHUTTING_DOWN equ 3
      ;  The flags field for query RM information is used for the following information:
      ;  1)  To indicate whether the LogGrowthIncrement field is reported as a percent
      ;      or as a number of containers.  Possible flag values for this are:
      ;      TXFS_RM_FLAG_LOG_GROWTH_INCREMENT_NUM_CONTAINERS xor TXFS_RM_FLAG_LOG_GROWTH_INCREMENT_PERCENT
      ;  2)  To indicate that there is no set maximum or minimum container count.  Possible
      ;      flag values for this are:
      ;      TXFS_RM_FLAG_LOG_NO_CONTAINER_COUNT_MAX
      ;      TXFS_RM_FLAG_LOG_NO_CONTAINER_COUNT_MIN
      ;      Note that these flags are not mutually exclusive.
      ;  2)  To report whether the RM will be reset the next time it is started.  Note that
      ;      only the default RM will report a meaningful value (secondary RMs will always
      ;      report DO_NOT_RESET) Possible flag values for this are:
      ;      TXFS_RM_FLAG_RESET_RM_AT_NEXT_START xor TXFS_RM_FLAG_DO_NOT_RESET_RM_AT_NEXT_START
      ;  3)  To report whether the RM is in consistency mode or availability mode.  Possible
      ;      flag values for this are:
      ;      TXFS_RM_FLAG_PREFER_CONSISTENCY xor TXFS_RM_FLAG_PREFER_AVAILABILITY
      ;  The RmState field can have exactly one of the above-defined TXF_RM_STATE_ values.
      TXFS_QUERY_RM_INFORMATION_VALID_FLAGS equ <(TXFS_RM_FLAG_LOG_GROWTH_INCREMENT_NUM_CONTAINERS or TXFS_RM_FLAG_LOG_GROWTH_INCREMENT_PERCENT or TXFS_RM_FLAG_LOG_NO_CONTAINER_COUNT_MAX or TXFS_RM_FLAG_LOG_NO_CONTAINER_COUNT_MIN or TXFS_RM_FLAG_RESET_RM_AT_NEXT_START or TXFS_RM_FLAG_DO_NOT_RESET_RM_AT_NEXT_START or TXFS_RM_FLAG_PREFER_CONSISTENCY or TXFS_RM_FLAG_PREFER_AVAILABILITY)>
      TXFS_QUERY_RM_INFORMATION struct
        ;  If the return value is STATUS_BUFFER_OVERFLOW (ERROR_MORE_DATA), this
        ;  will indicate how much space is required to hold everything.
        BytesRequired DWORD ?
        ;  LSN of earliest available record in the RM's log.
        TailLsn QWORD ?
        ;  LSN of most recently-written record in the RM's log.
        CurrentLsn QWORD ?
        ;  LSN of the log's archive tail.
        ArchiveTailLsn QWORD ?
        ;  Size of a log container in bytes.
        LogContainerSize QWORD ?
        ;  Highest virtual clock value recorded in this RM's log.
        HighestVirtualClock LARGE_INTEGER <>
        ;  Number of containers in this RM's log.
        LogContainerCount DWORD ?
        ;  Maximum-allowed log container count.
        LogContainerCountMax DWORD ?
        ;  Minimum-allowed log container count.
        LogContainerCountMin DWORD ?
        ;  Amount by which log will grow when it gets full.  Indicated as either a percent of
        ;  the log size or absolute container count, depending on which of the TXFS_RM_FLAG_LOG_GROWTH_INCREMENT_*
        ;  flags is set.
        LogGrowthIncrement DWORD ?
        ;  Reports on the autoshrink policy if.  Autoshrink makes the log shrink so that no more than this
        ;  percentage of the log is free at any time.  A value of 0 indicates that autoshrink is off (i.e.
        ;  the log will not automatically shrink).
        LogAutoShrinkPercentage DWORD ?
        ;  TXFS_RM_FLAG_* flags.  See the comment above at TXFS_QUERY_RM_INFORMATION_VALID_FLAGS to see
        ;  what the flags here mean.
        Flags DWORD ?
        ;  Exactly one of TXFS_LOGGING_MODE_SIMPLE or TXFS_LOGGING_MODE_FULL.
        LoggingMode WORD ?
        ;  Reserved.
        Reserved WORD ?
        ;  Activity state of the RM.  May be exactly one of the above-defined TXF_RM_STATE_ values.
        RmState DWORD ?
        ;  Total capacity of the log in bytes.
        LogCapacity QWORD ?
        ;  Amount of free space in the log in bytes.
        LogFree QWORD ?
        ;  Size of $Tops in bytes.
        TopsSize QWORD ?
        ;  Amount of space in $Tops in use.
        TopsUsed QWORD ?
        ;  Number of transactions active in the RM at the time of the call.
        TransactionCount QWORD ?
        ;  Total number of single-phase commits that have happened the RM.
        OnePCCount QWORD ?
        ;  Total number of two-phase commits that have happened the RM.
        TwoPCCount QWORD ?
        ;  Number of times the log has filled up.
        NumberLogFileFull QWORD ?
        ;  Age of oldest active transaction in the RM, in milliseconds.
        OldestTransactionAge QWORD ?
        ;  Name of the RM.
        RMName GUID <>
        ;  Offset in bytes from the beginning of this structure to a NULL-terminated Unicode
        ;  string indicating the path to the RM's transaction manager's log.
        TmLogPathOffset DWORD ?
      TXFS_QUERY_RM_INFORMATION ends
      _TXFS_QUERY_RM_INFORMATION typedef TXFS_QUERY_RM_INFORMATION
      PTXFS_QUERY_RM_INFORMATION typedef ptr TXFS_QUERY_RM_INFORMATION
      ;======================== FSCTL_TXFS_ROLLFORWARD_REDO ========================
      ; Structures for FSCTL_TXFS_ROLLFORWARD_REDO
      TXFS_ROLLFORWARD_REDO_FLAG_USE_LAST_REDO_LSN equ 01h
      TXFS_ROLLFORWARD_REDO_FLAG_USE_LAST_VIRTUAL_CLOCK equ 02h
      TXFS_ROLLFORWARD_REDO_VALID_FLAGS equ <(TXFS_ROLLFORWARD_REDO_FLAG_USE_LAST_REDO_LSN or TXFS_ROLLFORWARD_REDO_FLAG_USE_LAST_VIRTUAL_CLOCK)>
      TXFS_ROLLFORWARD_REDO_INFORMATION struct
        LastVirtualClock LARGE_INTEGER <>
        LastRedoLsn QWORD ?
        HighestRecoveryLsn QWORD ?
        Flags DWORD ?
      TXFS_ROLLFORWARD_REDO_INFORMATION ends
      _TXFS_ROLLFORWARD_REDO_INFORMATION typedef TXFS_ROLLFORWARD_REDO_INFORMATION
      PTXFS_ROLLFORWARD_REDO_INFORMATION typedef ptr TXFS_ROLLFORWARD_REDO_INFORMATION
      ifdef DEPRECATE_SUPPORTED
        ifndef USE_TXF_DEPRECATED_FUNCTIONALITY
        endif
      endif
      ;======================== FSCTL_TXFS_START_RM ========================
      ;  Structures for FSCTL_TXFS_START_RM
      ;  Note that TXFS_START_RM_FLAG_LOG_GROWTH_INCREMENT_NUM_CONTAINERS and
      ;  TXFS_START_RM_FLAG_LOG_GROWTH_INCREMENT_PERCENT are mutually exclusive.
      ;  You can specify the log growth amount in number of containers or as a percentage.
      ;  TXFS_START_RM_FLAG_CONTAINER_COUNT_MAX and TXFS_START_RM_FLAG_LOG_NO_CONTAINER_COUNT_MAX
      ;  are mutually exclusive.
      ;  TXFS_START_RM_FLAG_LOG_CONTAINER_COUNT_MIN and TXFS_START_RM_FLAG_LOG_NO_CONTAINER_COUNT_MIN
      ;  are mutually exclusive.
      ;  TXFS_START_RM_FLAG_PREFER_CONSISTENCY and TXFS_START_RM_FLAG_PREFER_AVAILABILITY
      ;  are mutually exclusive.
      ;  Optional parameters will have system-supplied defaults applied if omitted.
      TXFS_START_RM_FLAG_LOG_CONTAINER_COUNT_MAX equ 00000001h
      TXFS_START_RM_FLAG_LOG_CONTAINER_COUNT_MIN equ 00000002h
      TXFS_START_RM_FLAG_LOG_CONTAINER_SIZE equ 00000004h
      TXFS_START_RM_FLAG_LOG_GROWTH_INCREMENT_NUM_CONTAINERS equ 00000008h
      TXFS_START_RM_FLAG_LOG_GROWTH_INCREMENT_PERCENT equ 00000010h
      TXFS_START_RM_FLAG_LOG_AUTO_SHRINK_PERCENTAGE equ 00000020h
      TXFS_START_RM_FLAG_LOG_NO_CONTAINER_COUNT_MAX equ 00000040h
      TXFS_START_RM_FLAG_LOG_NO_CONTAINER_COUNT_MIN equ 00000080h
      TXFS_START_RM_FLAG_RECOVER_BEST_EFFORT equ 00000200h
      TXFS_START_RM_FLAG_LOGGING_MODE equ 00000400h
      TXFS_START_RM_FLAG_PRESERVE_CHANGES equ 00000800h
      TXFS_START_RM_FLAG_PREFER_CONSISTENCY equ 00001000h
      TXFS_START_RM_FLAG_PREFER_AVAILABILITY equ 00002000h
      TXFS_START_RM_VALID_FLAGS equ <(TXFS_START_RM_FLAG_LOG_CONTAINER_COUNT_MAX or TXFS_START_RM_FLAG_LOG_CONTAINER_COUNT_MIN or TXFS_START_RM_FLAG_LOG_CONTAINER_SIZE or TXFS_START_RM_FLAG_LOG_GROWTH_INCREMENT_NUM_CONTAINERS or TXFS_START_RM_FLAG_LOG_GROWTH_INCREMENT_PERCENT or TXFS_START_RM_FLAG_LOG_AUTO_SHRINK_PERCENTAGE or TXFS_START_RM_FLAG_RECOVER_BEST_EFFORT or TXFS_START_RM_FLAG_LOG_NO_CONTAINER_COUNT_MAX or TXFS_START_RM_FLAG_LOGGING_MODE or TXFS_START_RM_FLAG_PRESERVE_CHANGES or TXFS_START_RM_FLAG_PREFER_CONSISTENCY or TXFS_START_RM_FLAG_PREFER_AVAILABILITY)>
      TXFS_START_RM_INFORMATION struct
        ;  TXFS_START_RM_FLAG_* flags.
        Flags DWORD ?
        ;  RM log container size, in bytes.  This parameter is optional.
        LogContainerSize QWORD ?
        ;  RM minimum log container count.  This parameter is optional.
        LogContainerCountMin DWORD ?
        ;  RM maximum log container count.  This parameter is optional.
        LogContainerCountMax DWORD ?
        ;  RM log growth increment in number of containers or percent, as indicated
        ;  by TXFS_START_RM_FLAG_LOG_GROWTH_INCREMENT_* flag.  This parameter is
        ;  optional.
        LogGrowthIncrement DWORD ?
        ;  RM log auto shrink percentage.  This parameter is optional.
        LogAutoShrinkPercentage DWORD ?
        ;  Offset from the beginning of this structure to the log path for the KTM
        ;  instance to be used by this RM.  This must be a two-byte (WCHAR) aligned
        ;  value.  This parameter is required.
        TmLogPathOffset DWORD ?
        ;  Length in bytes of log path for the KTM instance to be used by this RM.
        ;  This parameter is required.
        TmLogPathLength WORD ?
        ;  Logging mode for this RM.  One of TXFS_LOGGING_MODE_SIMPLE or
        ;  TXFS_LOGGING_MODE_FULL (mutually exclusive).  This parameter is optional,
        ;  and will default to TXFS_LOGGING_MODE_SIMPLE.
        LoggingMode WORD ?
        ;  Length in bytes of the path to the log to be used by the RM.  This parameter
        ;  is required.
        LogPathLength WORD ?
        ;  Reserved.
        Reserved WORD ?
        ;  The path to the log (in Unicode characters) to be used by the RM goes here.
        ;  This parameter is required.
        LogPath WORD 1 dup (?)
      TXFS_START_RM_INFORMATION ends
      _TXFS_START_RM_INFORMATION typedef TXFS_START_RM_INFORMATION
      PTXFS_START_RM_INFORMATION typedef ptr TXFS_START_RM_INFORMATION
      ifdef DEPRECATE_SUPPORTED
        ifndef USE_TXF_DEPRECATED_FUNCTIONALITY
        endif
      endif
      ;======================== FSCTL_TXFS_GET_METADATA_INFO ========================
      ;  Structures for FSCTL_TXFS_GET_METADATA_INFO
      TXFS_GET_METADATA_INFO_OUT struct
        ;  Returns the TxfId of the file referenced by the handle used to call this routine.
        struct TxfFileId
          LowPart SQWORD ?
          HighPart SQWORD ?
        ends
        ;  The GUID of the transaction that has the file locked, if applicable.
        LockingTransaction GUID <>
        ;  Returns the LSN for the most recent log record we've written for the file.
        LastLsn QWORD ?
        ;  Transaction state, a TXFS_TRANSACTION_STATE_* value.
        TransactionState DWORD ?
      TXFS_GET_METADATA_INFO_OUT ends
      _TXFS_GET_METADATA_INFO_OUT typedef TXFS_GET_METADATA_INFO_OUT
      PTXFS_GET_METADATA_INFO_OUT typedef ptr TXFS_GET_METADATA_INFO_OUT
      ;================= FSCTL_TXFS_LIST_TRANSACTION_LOCKED_FILES ==================
      ;  Structures for FSCTL_TXFS_LIST_TRANSACTION_LOCKED_FILES
      ;  TXFS_LIST_TRANSACTION_LOCKED_FILES_ENTRY_FLAG_CREATED means the reported name was created
      ;  in the locking transaction.
      ;  TXFS_LIST_TRANSACTION_LOCKED_FILES_ENTRY_FLAG_DELETED means the reported name was deleted
      ;  in the locking transaction.
      ;  Note that both flags may appear if the name was both created and deleted in the same
      ;  transaction.  In that case the FileName[] member will contain only "\0", as there is
      ;  no meaningful name to report.
      TXFS_LIST_TRANSACTION_LOCKED_FILES_ENTRY_FLAG_CREATED equ 00000001h
      TXFS_LIST_TRANSACTION_LOCKED_FILES_ENTRY_FLAG_DELETED equ 00000002h
      TXFS_LIST_TRANSACTION_LOCKED_FILES_ENTRY struct
        ;  Offset in bytes from the beginning of the TXFS_LIST_TRANSACTION_LOCKED_FILES
        ;  structure to the next TXFS_LIST_TRANSACTION_LOCKED_FILES_ENTRY.
        Offset_ QWORD ?
        ;  TXFS_LIST_TRANSACTION_LOCKED_FILES_ENTRY_FLAG_* flags to indicate whether the
        ;  current name was deleted or created in the transaction.
        NameFlags DWORD ?
        ;  NTFS File ID of the file.
        FileId SQWORD ?
        ;  Reserved.
        Reserved1 DWORD ?
        Reserved2 DWORD ?
        Reserved3 SQWORD ?
        ;  NULL-terminated Unicode path to this file, relative to RM root.
        FileName WORD 1 dup (?)
      TXFS_LIST_TRANSACTION_LOCKED_FILES_ENTRY ends
      _TXFS_LIST_TRANSACTION_LOCKED_FILES_ENTRY typedef TXFS_LIST_TRANSACTION_LOCKED_FILES_ENTRY
      PTXFS_LIST_TRANSACTION_LOCKED_FILES_ENTRY typedef ptr TXFS_LIST_TRANSACTION_LOCKED_FILES_ENTRY
      TXFS_LIST_TRANSACTION_LOCKED_FILES struct
        ;  GUID name of the KTM transaction that files should be enumerated from.
        KtmTransaction GUID <>
        ;  On output, the number of files involved in the transaction on this RM.
        NumberOfFiles QWORD ?
        ;  The length of the buffer required to obtain the complete list of files.
        ;  This value may change from call to call as the transaction locks more files.
        BufferSizeRequired QWORD ?
        ;  Offset in bytes from the beginning of this structure to the first
        ;  TXFS_LIST_TRANSACTION_LOCKED_FILES_ENTRY.
        Offset_ QWORD ?
      TXFS_LIST_TRANSACTION_LOCKED_FILES ends
      _TXFS_LIST_TRANSACTION_LOCKED_FILES typedef TXFS_LIST_TRANSACTION_LOCKED_FILES
      PTXFS_LIST_TRANSACTION_LOCKED_FILES typedef ptr TXFS_LIST_TRANSACTION_LOCKED_FILES
      ;==================== FSCTL_TXFS_LIST_TRANSACTIONS ======================
      ;  Structures for FSCTL_TXFS_LIST_TRANSACTIONS
      TXFS_LIST_TRANSACTIONS_ENTRY struct
        ;  Transaction GUID.
        TransactionId GUID <>
        ;  Transaction state, a TXFS_TRANSACTION_STATE_* value.
        TransactionState DWORD ?
        ;  Reserved fields
        Reserved1 DWORD ?
        Reserved2 DWORD ?
        Reserved3 SQWORD ?
      TXFS_LIST_TRANSACTIONS_ENTRY ends
      _TXFS_LIST_TRANSACTIONS_ENTRY typedef TXFS_LIST_TRANSACTIONS_ENTRY
      PTXFS_LIST_TRANSACTIONS_ENTRY typedef ptr TXFS_LIST_TRANSACTIONS_ENTRY
      TXFS_LIST_TRANSACTIONS struct
        ;  On output, the number of transactions involved in this RM.
        NumberOfTransactions QWORD ?
        ;  The length of the buffer required to obtain the complete list of
        ;  transactions.  Note that this value may change from call to call
        ;  as transactions enter and exit the system.
        BufferSizeRequired QWORD ?
      TXFS_LIST_TRANSACTIONS ends
      _TXFS_LIST_TRANSACTIONS typedef TXFS_LIST_TRANSACTIONS
      PTXFS_LIST_TRANSACTIONS typedef ptr TXFS_LIST_TRANSACTIONS
      ;==================== FSCTL_TXFS_READ_BACKUP_INFORMATION ======================
      ;  Structures for FSCTL_TXFS_READ_BACKUP_INFORMATION
      if _MSC_VER ge 1200
      endif
      ; unnamed struct
      TXFS_READ_BACKUP_INFORMATION_OUT struct
        union
          ;  Used to return the required buffer size if return code is STATUS_BUFFER_OVERFLOW
          BufferLength DWORD ?
          ;  On success the data is copied here.
          Buffer BYTE 1 dup (?)
        ends
      TXFS_READ_BACKUP_INFORMATION_OUT ends
      _TXFS_READ_BACKUP_INFORMATION_OUT typedef TXFS_READ_BACKUP_INFORMATION_OUT
      PTXFS_READ_BACKUP_INFORMATION_OUT typedef ptr TXFS_READ_BACKUP_INFORMATION_OUT
      if _MSC_VER ge 1200
      else
      endif
      ;==================== FSCTL_TXFS_WRITE_BACKUP_INFORMATION ======================
      ;  Structures for FSCTL_TXFS_WRITE_BACKUP_INFORMATION
      TXFS_WRITE_BACKUP_INFORMATION struct
        ;  The data returned in the Buffer member of a previous call to
        ;  FSCTL_TXFS_READ_BACKUP_INFORMATION goes here.
        Buffer BYTE 1 dup (?)
      TXFS_WRITE_BACKUP_INFORMATION ends
      _TXFS_WRITE_BACKUP_INFORMATION typedef TXFS_WRITE_BACKUP_INFORMATION
      PTXFS_WRITE_BACKUP_INFORMATION typedef ptr TXFS_WRITE_BACKUP_INFORMATION
      ;==================== FSCTL_TXFS_GET_TRANSACTED_VERSION ======================
      ;  Output structure for FSCTL_TXFS_GET_TRANSACTED_VERSION
      TXFS_TRANSACTED_VERSION_NONTRANSACTED equ 0FFFFFFFEh
      TXFS_TRANSACTED_VERSION_UNCOMMITTED equ 0FFFFFFFFh
      TXFS_GET_TRANSACTED_VERSION struct
        ;  The version that this handle is opened to.  This will be
        ;  TXFS_TRANSACTED_VERSION_UNCOMMITTED for nontransacted and
        ;  transactional writer handles.
        ThisBaseVersion DWORD ?
        ;  The most recent committed version available.
        LatestVersion DWORD ?
        ;  If this is a handle to a miniversion, the ID of the miniversion.
        ;  If it is not a handle to a miniversion, this field will be 0.
        ThisMiniVersion WORD ?
        ;  The first available miniversion.  Unless the miniversions are
        ;  visible to the transaction bound to this handle, this field will be zero.
        FirstMiniVersion WORD ?
        ;  The latest available miniversion.  Unless the miniversions are
        ;  visible to the transaction bound to this handle, this field will be zero.
        LatestMiniVersion WORD ?
      TXFS_GET_TRANSACTED_VERSION ends
      _TXFS_GET_TRANSACTED_VERSION typedef TXFS_GET_TRANSACTED_VERSION
      PTXFS_GET_TRANSACTED_VERSION typedef ptr TXFS_GET_TRANSACTED_VERSION
      ;==================== FSCTL_TXFS_SAVEPOINT_INFORMATION ======================
      ;  Structures for FSCTL_TXFS_SAVEPOINT_INFORMATION
      ;  Note that the TXFS_SAVEPOINT_INFORMATION structure is both and in and out structure.
      ;  The KtmTransaction and ActionCode members are always in-parameters, and the SavepointId
      ;  member is either an in-parameter, an out-parameter, or not used (see its definition below).
      ;  Create a new savepoint.
      TXFS_SAVEPOINT_SET equ 00000001h
      ;  Roll back to a specified savepoint.
      TXFS_SAVEPOINT_ROLLBACK equ 00000002h
      ;  Clear (make unavailable for rollback) the most recently set savepoint
      ;  that has not yet been cleared.
      TXFS_SAVEPOINT_CLEAR equ 00000004h
      ;  Clear all savepoints from the transaction.
      TXFS_SAVEPOINT_CLEAR_ALL equ 00000010h
      TXFS_SAVEPOINT_INFORMATION struct
        ;  Handle to the transaction on which to perform the savepoint operation.
        KtmTransaction HANDLE ?
        ;  Specifies the savepoint action to take.  A TXFS_SAVEPOINT_* value.
        ActionCode DWORD ?
        ;  In-parameter for TXFS_ROLLBACK_TO_SAVEPOINT - specifies the savepoint to which
        ;  to roll back.
        ;  Out-parameter for TXFS_SET_SAVEPOINT - the newly-created savepoint ID will be
        ;  returned here.
        ;  Not used for TXFS_CLEAR_SAVEPOINT or TXFS_CLEAR_ALL_SAVEPOINTS.
        SavepointId DWORD ?
      TXFS_SAVEPOINT_INFORMATION ends
      _TXFS_SAVEPOINT_INFORMATION typedef TXFS_SAVEPOINT_INFORMATION
      PTXFS_SAVEPOINT_INFORMATION typedef ptr TXFS_SAVEPOINT_INFORMATION
      ifdef DEPRECATE_SUPPORTED
        ifndef USE_TXF_DEPRECATED_FUNCTIONALITY
        endif
      endif
      ;==================== FSCTL_TXFS_CREATE_MINIVERSION ======================
      ;  Structures for FSCTL_TXFS_CREATE_MINIVERSION
      ;      Only an out parameter is necessary.  That returns the identifier of the new miniversion created.
      TXFS_CREATE_MINIVERSION_INFO struct
        StructureVersion WORD ?
        StructureLength WORD ?
        ;  The base version for the newly created miniversion.
        BaseVersion DWORD ?
        ;  The miniversion that was just created.
        MiniVersion WORD ?
      TXFS_CREATE_MINIVERSION_INFO ends
      _TXFS_CREATE_MINIVERSION_INFO typedef TXFS_CREATE_MINIVERSION_INFO
      PTXFS_CREATE_MINIVERSION_INFO typedef ptr TXFS_CREATE_MINIVERSION_INFO
      ifdef DEPRECATE_SUPPORTED
        ifndef USE_TXF_DEPRECATED_FUNCTIONALITY
        endif
      endif
      ;==================== FSCTL_TXFS_TRANSACTION_ACTIVE ======================
      ;  Structure for FSCTL_TXFS_TRANSACTION_ACTIVE
      TXFS_TRANSACTION_ACTIVE_INFO struct
        ;  Whether or not the volume had active transactions when this snapshot was taken.
        TransactionsActiveAtSnapshot BYTE ?
      TXFS_TRANSACTION_ACTIVE_INFO ends
      _TXFS_TRANSACTION_ACTIVE_INFO typedef TXFS_TRANSACTION_ACTIVE_INFO
      PTXFS_TRANSACTION_ACTIVE_INFO typedef ptr TXFS_TRANSACTION_ACTIVE_INFO
      ;* _WIN32_WINNT >= _WIN32_WINNT_VISTA *
    endif
    if (_WIN32_WINNT ge _WIN32_WINNT_WIN7)
      ;======================= FSCTL_GET_BOOT_AREA_INFO ==========================
      ; Output structure for FSCTL_GET_BOOT_AREA_INFO
      BOOT_AREA_INFO struct
        BootSectorCount DWORD ?
        ; the count of boot sectors present on the file system
        struct BootSectors
          Offset_ LARGE_INTEGER <>
        ends
        ] typedef ptr BootSectors
        ; variable number of boot sectors.
      BOOT_AREA_INFO ends
      _BOOT_AREA_INFO typedef BOOT_AREA_INFO
      PBOOT_AREA_INFO typedef ptr BOOT_AREA_INFO
      ;==================== FSCTL_GET_RETRIEVAL_POINTER_BASE ======================
      ; Output structure for FSCTL_GET_RETRIEVAL_POINTER_BASE
      RETRIEVAL_POINTER_BASE struct
        FileAreaOffset LARGE_INTEGER <>
        ; sector offset to the first allocatable unit on the filesystem
      RETRIEVAL_POINTER_BASE ends
      _RETRIEVAL_POINTER_BASE typedef RETRIEVAL_POINTER_BASE
      PRETRIEVAL_POINTER_BASE typedef ptr RETRIEVAL_POINTER_BASE
      ;==================== FSCTL_QUERY_PERSISTENT_VOLUME_STATE ====================
      ;==================== FSCTL_SET_PERSISTENT_VOLUME_STATE ======================
      ; Structure for FSCTL_SET_PERSISTENT_VOLUME_STATE and
      ;  FSCTL_GET_PERSISTENT_VOLUME_STATE.  The initial version will be 1.0
      FILE_FS_PERSISTENT_VOLUME_INFORMATION struct
        VolumeFlags DWORD ?
        FlagMask DWORD ?
        Version DWORD ?
        Reserved DWORD ?
      FILE_FS_PERSISTENT_VOLUME_INFORMATION ends
      _FILE_FS_PERSISTENT_VOLUME_INFORMATION typedef FILE_FS_PERSISTENT_VOLUME_INFORMATION
      PFILE_FS_PERSISTENT_VOLUME_INFORMATION typedef ptr FILE_FS_PERSISTENT_VOLUME_INFORMATION
      ;  VolumeFlags values
      PERSISTENT_VOLUME_STATE_SHORT_NAME_CREATION_DISABLED equ (00000001h)
      if (_WIN32_WINNT ge _WIN32_WINNT_WIN8)
        PERSISTENT_VOLUME_STATE_VOLUME_SCRUB_DISABLED equ (00000002h)
        ;* (_WIN32_WINNT >= _WIN32_WINNT_WIN8) *
      endif
      if (_WIN32_WINNT ge _WIN32_WINNT_WINBLUE)
        ;  Persistent volume flags to control the file system's storage tiering
        ;  awareness.
        PERSISTENT_VOLUME_STATE_GLOBAL_METADATA_NO_SEEK_PENALTY equ (00000004h)
        PERSISTENT_VOLUME_STATE_LOCAL_METADATA_NO_SEEK_PENALTY equ (00000008h)
        PERSISTENT_VOLUME_STATE_NO_HEAT_GATHERING equ (00000010h)
        ;* (_WIN32_WINNT >= _WIN32_WINNT_WINBLUE) *
      endif
      ;  These are flags that define a volume's dependency on WimBoot file.
      if (_WIN32_WINNT ge _WIN32_WINNT_WIN7)
        ;  The volume backs a system critical volume, typically the one that has wimboot
        ;  image file serving the system files
        PERSISTENT_VOLUME_STATE_CONTAINS_BACKING_WIM equ (00000020h)
        ;  The volume is backed by other volume that actually has the system files.
        ;  And hence this relies on the other volume being present in order for the system to boot up.
        PERSISTENT_VOLUME_STATE_BACKED_BY_WIM equ (00000040h)
        ;* (_WIN32_WINNT >= _WIN32_WINNT_WIN7) *
      endif
      if (_WIN32_WINNT ge _WIN32_WINNT_WINTHRESHOLD)
        ;  Writes dynamic redirection on tiered volumes will be disabled
        PERSISTENT_VOLUME_STATE_NO_WRITE_AUTO_TIERING equ (00000080h)
      endif
      ; #if (_WIN32_WINNT >= _WIN32_WINNT_WINTHRESHOLD)
      if (_WIN32_WINNT ge _WIN32_WINNT_WINTHRESHOLD)
        ;  Disable txf on volume
        PERSISTENT_VOLUME_STATE_TXF_DISABLED equ (00000100h)
      endif
      ; #if (_WIN32_WINNT >= _WIN32_WINNT_WINTHRESHOLD)
      if (NTDDI_VERSION ge NTDDI_WIN10_RS5)
        ;  Always reallocate data writes
        PERSISTENT_VOLUME_STATE_REALLOCATE_ALL_DATA_WRITES equ (00000200h)
      endif
      ; #if (NTDDI_VERSION >= NTDDI_WIN10_RS5)
      if (NTDDI_VERSION ge NTDDI_WIN10_MN)
        ;  This indicates that AutoChk modified this volume and is cleared by AutoChk
        ;  after it ensured that the volume is dismounted or the system is rebooted.
        ;  This can be set or queried.
        PERSISTENT_VOLUME_STATE_CHKDSK_RAN_ONCE equ (00000400h)
        ;  This again indicates that AutoChk modified this volume but is cleared by
        ;  NTFS on next mount.  So if this flag is set it means that the volume was
        ;  modified by AutoChk while it's still mounted and the on-disk state and
        ;  the in memory state could be different.  This can only be queried.
        PERSISTENT_VOLUME_STATE_MODIFIED_BY_CHKDSK equ (00000800h)
        ;  The volume was formatted as DAX.  The volume may not be mounted as DAX
        ;  if the storage is not DAX capable.  This can only be queried.
        PERSISTENT_VOLUME_STATE_DAX_FORMATTED equ (00001000h)
      endif
      ; #if (NTDDI_VERSION >= NTDDI_WIN10_MN)
      if Defined(NTDDI_WIN10_NI) and (NTDDI_VERSION ge NTDDI_WIN10_NI)
        ;  The volume was formatted as a developer volume.  This can be used by the
        ;  file system and other system components to enable optimizations that doe
        ;  not require an administrator to trust the volume on a given machine.
        ;  This is set at format time and can only be queried.
        PERSISTENT_VOLUME_STATE_DEV_VOLUME equ (00002000h)
        ;  An adminstrator on a given machine had trust this volume and is willing
        ;  to enable optimizations like not having anti-virus filters attach to the
        ;  volume.  This information is persisted in the registry on a given machine.
        ;  This can be used by the file system and other system components to enable
        ;  optimizations that require an administrator to trust the volume on a given
        ;  machine.
        ;  NOTE: Today only developer volumes can be trusted, i.e. this flag can be
        ;  set only when PERSISTENT_VOLUME_STATE_DEV_VOLUME is set.
        ;  This can be set and queried.
        PERSISTENT_VOLUME_STATE_TRUSTED_VOLUME equ (00004000h)
      endif
      ; #if (NTDDI_VERSION >= NTDDI_WIN10_NI)
      ;==================== FSCTL_QUERY_FILE_SYSTEM_RECOGNITION ====================
      ;  Structure for FSCTL_QUERY_FILE_SYSTEM_RECOGNITION
      FILE_SYSTEM_RECOGNITION_INFORMATION struct
        FileSystem SBYTE 9 dup (?)
      FILE_SYSTEM_RECOGNITION_INFORMATION ends
      _FILE_SYSTEM_RECOGNITION_INFORMATION typedef FILE_SYSTEM_RECOGNITION_INFORMATION
      PFILE_SYSTEM_RECOGNITION_INFORMATION typedef ptr FILE_SYSTEM_RECOGNITION_INFORMATION
      ;=========================== FSCTL_REQUEST_OPLOCK ===========================
      ;  Structures for FSCTL_REQUEST_OPLOCK
      OPLOCK_LEVEL_CACHE_READ equ (00000001h)
      OPLOCK_LEVEL_CACHE_HANDLE equ (00000002h)
      OPLOCK_LEVEL_CACHE_WRITE equ (00000004h)
      REQUEST_OPLOCK_INPUT_FLAG_REQUEST equ (00000001h)
      REQUEST_OPLOCK_INPUT_FLAG_ACK equ (00000002h)
      REQUEST_OPLOCK_INPUT_FLAG_COMPLETE_ACK_ON_CLOSE equ (00000004h)
      REQUEST_OPLOCK_CURRENT_VERSION equ 1
      REQUEST_OPLOCK_INPUT_BUFFER struct
        ;  This should be set to REQUEST_OPLOCK_CURRENT_VERSION.
        StructureVersion WORD ?
        StructureLength WORD ?
        ;  One or more OPLOCK_LEVEL_CACHE_* values to indicate the desired level of the oplock.
        RequestedOplockLevel DWORD ?
        ;  REQUEST_OPLOCK_INPUT_FLAG_* flags.
        Flags DWORD ?
      REQUEST_OPLOCK_INPUT_BUFFER ends
      _REQUEST_OPLOCK_INPUT_BUFFER typedef REQUEST_OPLOCK_INPUT_BUFFER
      PREQUEST_OPLOCK_INPUT_BUFFER typedef ptr REQUEST_OPLOCK_INPUT_BUFFER
      REQUEST_OPLOCK_OUTPUT_FLAG_ACK_REQUIRED equ (00000001h)
      REQUEST_OPLOCK_OUTPUT_FLAG_MODES_PROVIDED equ (00000002h)
      if (NTDDI_VERSION ge NTDDI_WIN10_VB)
        ; If the oplock request fails with STATUS_OPLOCK_NOT_GRANTED, this flag indicates that the oplock
        ; could not be granted due to the presence of a writable user-mapped section.
        REQUEST_OPLOCK_OUTPUT_FLAG_WRITABLE_SECTION_PRESENT equ (00000004h)
      endif
      REQUEST_OPLOCK_OUTPUT_BUFFER struct
        ;  This should be set to REQUEST_OPLOCK_CURRENT_VERSION.
        StructureVersion WORD ?
        StructureLength WORD ?
        ;  One or more OPLOCK_LEVEL_CACHE_* values indicating the level of the oplock that
        ;  was just broken.
        OriginalOplockLevel DWORD ?
        ;  One or more OPLOCK_LEVEL_CACHE_* values indicating the level to which an oplock
        ;  is being broken, or an oplock level that may be available for granting, depending
        ;  on the operation returning this buffer.
        NewOplockLevel DWORD ?
        ;  REQUEST_OPLOCK_OUTPUT_FLAG_* flags.
        Flags DWORD ?
        ;  When REQUEST_OPLOCK_OUTPUT_FLAG_MODES_PROVIDED is set, and when the
        ;  OPLOCK_LEVEL_CACHE_HANDLE level is being lost in an oplock break, these fields
        ;  contain the access mode and share mode of the request that is causing the break.
        AccessMode ACCESS_MASK ?
        ShareMode WORD ?
      REQUEST_OPLOCK_OUTPUT_BUFFER ends
      _REQUEST_OPLOCK_OUTPUT_BUFFER typedef REQUEST_OPLOCK_OUTPUT_BUFFER
      PREQUEST_OPLOCK_OUTPUT_BUFFER typedef ptr REQUEST_OPLOCK_OUTPUT_BUFFER
      ;======================= FSCTL_QUERY_DEPENDENT_VOLUME =======================
      ifndef _VIRTUAL_STORAGE_TYPE_DEFINED
        _VIRTUAL_STORAGE_TYPE_DEFINED equ <>
        VIRTUAL_STORAGE_TYPE struct
          DeviceId DWORD ?
          VendorId GUID <>
        VIRTUAL_STORAGE_TYPE ends
        _VIRTUAL_STORAGE_TYPE typedef VIRTUAL_STORAGE_TYPE
        PVIRTUAL_STORAGE_TYPE typedef ptr VIRTUAL_STORAGE_TYPE
      endif
      ;  These structures are used by the FSCTL_QUERY_DEPENDENT_VOLUME
      STORAGE_QUERY_DEPENDENT_VOLUME_REQUEST struct
        RequestLevel DWORD ?
        RequestFlags DWORD ?
      STORAGE_QUERY_DEPENDENT_VOLUME_REQUEST ends
      _STORAGE_QUERY_DEPENDENT_VOLUME_REQUEST typedef STORAGE_QUERY_DEPENDENT_VOLUME_REQUEST
      PSTORAGE_QUERY_DEPENDENT_VOLUME_REQUEST typedef ptr STORAGE_QUERY_DEPENDENT_VOLUME_REQUEST
      QUERY_DEPENDENT_VOLUME_REQUEST_FLAG_HOST_VOLUMES equ 1h
      QUERY_DEPENDENT_VOLUME_REQUEST_FLAG_GUEST_VOLUMES equ 2h
      STORAGE_QUERY_DEPENDENT_VOLUME_LEV1_ENTRY struct
        EntryLength DWORD ?
        DependencyTypeFlags DWORD ?
        ProviderSpecificFlags DWORD ?
        VirtualStorageType VIRTUAL_STORAGE_TYPE <>
      STORAGE_QUERY_DEPENDENT_VOLUME_LEV1_ENTRY ends
      _STORAGE_QUERY_DEPENDENT_VOLUME_LEV1_ENTRY typedef STORAGE_QUERY_DEPENDENT_VOLUME_LEV1_ENTRY
      PSTORAGE_QUERY_DEPENDENT_VOLUME_LEV1_ENTRY typedef ptr STORAGE_QUERY_DEPENDENT_VOLUME_LEV1_ENTRY
      STORAGE_QUERY_DEPENDENT_VOLUME_LEV2_ENTRY struct
        EntryLength DWORD ?
        DependencyTypeFlags DWORD ?
        ProviderSpecificFlags DWORD ?
        VirtualStorageType VIRTUAL_STORAGE_TYPE <>
        AncestorLevel DWORD ?
        ; Root parent is 0, every child level after that is incremented
        HostVolumeNameOffset DWORD ?
        HostVolumeNameSize DWORD ?
        DependentVolumeNameOffset DWORD ?
        DependentVolumeNameSize DWORD ?
        RelativePathOffset DWORD ?
        RelativePathSize DWORD ?
        DependentDeviceNameOffset DWORD ?
        DependentDeviceNameSize DWORD ?
      STORAGE_QUERY_DEPENDENT_VOLUME_LEV2_ENTRY ends
      _STORAGE_QUERY_DEPENDENT_VOLUME_LEV2_ENTRY typedef STORAGE_QUERY_DEPENDENT_VOLUME_LEV2_ENTRY
      PSTORAGE_QUERY_DEPENDENT_VOLUME_LEV2_ENTRY typedef ptr STORAGE_QUERY_DEPENDENT_VOLUME_LEV2_ENTRY
      ifdef _MSC_EXTENSIONS
        if _MSC_VER ge 1200
          ; zero length array
        endif
        STORAGE_QUERY_DEPENDENT_VOLUME_RESPONSE struct
          ResponseLevel DWORD ?
          NumberEntries DWORD ?
          union
            Lev1Depends STORAGE_QUERY_DEPENDENT_VOLUME_LEV1_ENTRY 0 dup (<>)
            Lev2Depends STORAGE_QUERY_DEPENDENT_VOLUME_LEV2_ENTRY 0 dup (<>)
          ends
        STORAGE_QUERY_DEPENDENT_VOLUME_RESPONSE ends
        _STORAGE_QUERY_DEPENDENT_VOLUME_RESPONSE typedef STORAGE_QUERY_DEPENDENT_VOLUME_RESPONSE
        PSTORAGE_QUERY_DEPENDENT_VOLUME_RESPONSE typedef ptr STORAGE_QUERY_DEPENDENT_VOLUME_RESPONSE
        if _MSC_VER ge 1200
        endif
      endif
      ;========================== FSCTL_SD_GLOBAL_CHANGE ==========================
      ;  Structures for FSCTL_SD_GLOBAL_CHANGE
      ;  list of operations supported
      SD_GLOBAL_CHANGE_TYPE_MACHINE_SID equ 1
      SD_GLOBAL_CHANGE_TYPE_QUERY_STATS equ (1 shl 16)
      SD_GLOBAL_CHANGE_TYPE_ENUM_SDS equ (2 shl 16)
      ;  Operation specific structures for SD_GLOBAL_CHANGE_TYPE_MACHINE_SID
      SD_CHANGE_MACHINE_SID_INPUT struct
        ;  The current machine SID to change.
        ;  This defines the offset from the beginning of the SD_GLOBAL_CHANGE_INPUT
        ;  structure of where the CurrentMachineSID to replace begins.  This will
        ;  be a SID structure.  The length defines the length of the imbedded SID
        ;  structure.
        CurrentMachineSIDOffset WORD ?
        CurrentMachineSIDLength WORD ?
        ;  The new machine SID value to set in-place of the current machine SID
        ;  This defines the offset from the beginning of the SD_GLOBAL_CHANGE_INPUT
        ;  structure of where the NewMachineSID to set begins.  This will
        ;  be a SID structure.  The length defines the length of the imbedded SID
        ;  structure.
        NewMachineSIDOffset WORD ?
        NewMachineSIDLength WORD ?
      SD_CHANGE_MACHINE_SID_INPUT ends
      _SD_CHANGE_MACHINE_SID_INPUT typedef SD_CHANGE_MACHINE_SID_INPUT
      PSD_CHANGE_MACHINE_SID_INPUT typedef ptr SD_CHANGE_MACHINE_SID_INPUT
      SD_CHANGE_MACHINE_SID_OUTPUT struct
        ;  How many entries were successfully changed in the $Secure stream
        NumSDChangedSuccess QWORD ?
        ;  How many entries failed the update in the $Secure stream
        NumSDChangedFail QWORD ?
        ;  How many entries are unused in the current security stream
        NumSDUnused QWORD ?
        ;  The total number of entries processed in the $Secure stream
        NumSDTotal QWORD ?
        ;  How many entries were successfully changed in the $MFT file
        NumMftSDChangedSuccess QWORD ?
        ;  How many entries failed the update in the $MFT file
        NumMftSDChangedFail QWORD ?
        ;  Total number of entries processed in the $MFT file
        NumMftSDTotal QWORD ?
      SD_CHANGE_MACHINE_SID_OUTPUT ends
      _SD_CHANGE_MACHINE_SID_OUTPUT typedef SD_CHANGE_MACHINE_SID_OUTPUT
      PSD_CHANGE_MACHINE_SID_OUTPUT typedef ptr SD_CHANGE_MACHINE_SID_OUTPUT
      ;  Operation specific structures for SD_GLOBAL_CHANGE_TYPE_QUERY_STATS
      SD_QUERY_STATS_INPUT struct
        Reserved DWORD ?
      SD_QUERY_STATS_INPUT ends
      _SD_QUERY_STATS_INPUT typedef SD_QUERY_STATS_INPUT
      PSD_QUERY_STATS_INPUT typedef ptr SD_QUERY_STATS_INPUT
      SD_QUERY_STATS_OUTPUT struct
        ;  Stream size and allocation size for the security descriptor
        ;  data stream ($Secure:$SDS).
        SdsStreamSize QWORD ?
        SdsAllocationSize QWORD ?
        ;  Stream size and allocation size for the security ID index
        ;  stream ($Secure:$SII).
        SiiStreamSize QWORD ?
        SiiAllocationSize QWORD ?
        ;  Stream size and allocation size for the security descriptor
        ;  hash index stream ($Secure:$SDH).
        SdhStreamSize QWORD ?
        SdhAllocationSize QWORD ?
        ;  The total number of entries in the security descriptor data
        ;  stream.
        NumSDTotal QWORD ?
        ;  The number of unused entries in the security descriptor data
        ;  stream.
        NumSDUnused QWORD ?
      SD_QUERY_STATS_OUTPUT ends
      _SD_QUERY_STATS_OUTPUT typedef SD_QUERY_STATS_OUTPUT
      PSD_QUERY_STATS_OUTPUT typedef ptr SD_QUERY_STATS_OUTPUT
      ;  Operation specific structures for SD_GLOBAL_CHANGE_TYPE_ENUM_SDS
      SD_ENUM_SDS_INPUT struct
        ;  The byte offset within the security descriptor data stream to look
        ;  for security descriptors.  This must be a multiple of 16.
        ;  Note this is a virtual byte offset.  The security descriptor data
        ;  stream contains some additional data embedded inside the stream for
        ;  redundancy, and this extra data does not count toward this byte
        ;  offset.
        StartingOffset QWORD ?
        ;  The maximum number of SD entries to return.  This is primarily
        ;  useful for supporting a model where you only want one entry at
        ;  a time.  Set to 0 for no max.
        MaxSDEntriesToReturn QWORD ?
      SD_ENUM_SDS_INPUT ends
      _SD_ENUM_SDS_INPUT typedef SD_ENUM_SDS_INPUT
      PSD_ENUM_SDS_INPUT typedef ptr SD_ENUM_SDS_INPUT
      SD_ENUM_SDS_ENTRY struct
        ;  Hash value of the security decriptor.
        Hash DWORD ?
        ;  SecurityId for the security descriptor.
        SecurityId DWORD ?
        ;  Virtual byte offset of this header in the security descriptor
        ;  data stream.
        Offset_ QWORD ?
        ;  Length of this header + security descriptor that follows this
        ;  header.
        Length_ DWORD ?
        ;  Actual security decriptor, variable length.
        Descriptor BYTE 1 dup (?)
      SD_ENUM_SDS_ENTRY ends
      _SD_ENUM_SDS_ENTRY typedef SD_ENUM_SDS_ENTRY
      PSD_ENUM_SDS_ENTRY typedef ptr SD_ENUM_SDS_ENTRY
      SD_ENUM_SDS_OUTPUT struct
        ;  The current machine SID to change.
        ;  This defines the offset from the beginning of the SD_GLOBAL_CHANGE_INPUT
        ;  structure of where the CurrentMachineSID to replace begins.  This will
        ;  be a SID structure.  The length defines the length of the imbedded SID
        ;  structure.
        NextOffset QWORD ?
        ;  The total number of entries returned.
        NumSDEntriesReturned QWORD ?
        ;  The total number of bytes of entries returned.
        NumSDBytesReturned QWORD ?
        ;  Variable length array of security descriptor stream entries.
        ;  There should be NumSDEntriesReturned of them.  To walk this array,
        ;  first point to SDEntry[0], then advance a number of bytes equal
        ;  to the entry's Length rounded up to a multiple of 16.  (Each entry
        ;  will be aligned to a 16-byte boundary.)
        SDEntry SD_ENUM_SDS_ENTRY 1 dup (<>)
      SD_ENUM_SDS_OUTPUT ends
      _SD_ENUM_SDS_OUTPUT typedef SD_ENUM_SDS_OUTPUT
      PSD_ENUM_SDS_OUTPUT typedef ptr SD_ENUM_SDS_OUTPUT
      ;  Generic INPUT & OUTPUT structures for FSCTL_SD_GLOBAL_CHANGE
      if _MSC_VER ge 1200
      endif
      ; unnamed struct
      SD_GLOBAL_CHANGE_INPUT struct
        ;  Input flags (none currently defined)
        Flags DWORD ?
        ;  Specifies which type of change we are doing and pics which member
        ;  of the below union is in use.
        ChangeType DWORD ?
        union
          SdChange SD_CHANGE_MACHINE_SID_INPUT <>
          SdQueryStats SD_QUERY_STATS_INPUT <>
          SdEnumSds SD_ENUM_SDS_INPUT <>
        ends
      SD_GLOBAL_CHANGE_INPUT ends
      _SD_GLOBAL_CHANGE_INPUT typedef SD_GLOBAL_CHANGE_INPUT
      PSD_GLOBAL_CHANGE_INPUT typedef ptr SD_GLOBAL_CHANGE_INPUT
      SD_GLOBAL_CHANGE_OUTPUT struct
        ;  Output State Flags (none currently defined)
        Flags DWORD ?
        ;  Specifies which below union to use
        ChangeType DWORD ?
        union
          SdChange SD_CHANGE_MACHINE_SID_OUTPUT <>
          SdQueryStats SD_QUERY_STATS_OUTPUT <>
          SdEnumSds SD_ENUM_SDS_OUTPUT <>
        ends
      SD_GLOBAL_CHANGE_OUTPUT ends
      _SD_GLOBAL_CHANGE_OUTPUT typedef SD_GLOBAL_CHANGE_OUTPUT
      PSD_GLOBAL_CHANGE_OUTPUT typedef ptr SD_GLOBAL_CHANGE_OUTPUT
      if _MSC_VER ge 1200
      else
        ;* nonstandard extension used : nameless struct/union *
      endif
      ;==================== FSCTL_LOOKUP_STREAM_FROM_CLUSTER =======================
      LOOKUP_STREAM_FROM_CLUSTER_INPUT struct
        ;  Flags for the operation.  Currently no flags are defined.
        Flags DWORD ?
        ;  Number of clusters in the following array of clusters.
        ;  The input buffer must be large enough to contain this
        ;  number or the operation will fail.
        NumberOfClusters DWORD ?
        ;  An array of one or more clusters to look up.
        Cluster LARGE_INTEGER 1 dup (<>)
      LOOKUP_STREAM_FROM_CLUSTER_INPUT ends
      _LOOKUP_STREAM_FROM_CLUSTER_INPUT typedef LOOKUP_STREAM_FROM_CLUSTER_INPUT
      PLOOKUP_STREAM_FROM_CLUSTER_INPUT typedef ptr LOOKUP_STREAM_FROM_CLUSTER_INPUT
      LOOKUP_STREAM_FROM_CLUSTER_OUTPUT struct
        ;  Offset from the beginning of this structure to the first entry
        ;  returned.  If no entries are returned, this value is zero.
        Offset_ DWORD ?
        ;  Number of matches to the input criteria.  Note that more matches
        ;  may be found than entries returned if the buffer is not large
        ;  enough.
        NumberOfMatches DWORD ?
        ;  Minimum size of the buffer, in bytes, which would be needed to
        ;  contain all matching entries to the input criteria.
        BufferSizeRequired DWORD ?
      LOOKUP_STREAM_FROM_CLUSTER_OUTPUT ends
      _LOOKUP_STREAM_FROM_CLUSTER_OUTPUT typedef LOOKUP_STREAM_FROM_CLUSTER_OUTPUT
      PLOOKUP_STREAM_FROM_CLUSTER_OUTPUT typedef ptr LOOKUP_STREAM_FROM_CLUSTER_OUTPUT
      LOOKUP_STREAM_FROM_CLUSTER_ENTRY_FLAG_PAGE_FILE equ 00000001h
      LOOKUP_STREAM_FROM_CLUSTER_ENTRY_FLAG_DENY_DEFRAG_SET equ 00000002h
      LOOKUP_STREAM_FROM_CLUSTER_ENTRY_FLAG_FS_SYSTEM_FILE equ 00000004h
      LOOKUP_STREAM_FROM_CLUSTER_ENTRY_FLAG_TXF_SYSTEM_FILE equ 00000008h
      LOOKUP_STREAM_FROM_CLUSTER_ENTRY_ATTRIBUTE_MASK equ 0ff000000h
      LOOKUP_STREAM_FROM_CLUSTER_ENTRY_ATTRIBUTE_DATA equ 01000000h
      LOOKUP_STREAM_FROM_CLUSTER_ENTRY_ATTRIBUTE_INDEX equ 02000000h
      LOOKUP_STREAM_FROM_CLUSTER_ENTRY_ATTRIBUTE_SYSTEM equ 03000000h
      LOOKUP_STREAM_FROM_CLUSTER_ENTRY struct
        ;  Offset from the beginning of this structure to the next entry
        ;  returned.  If there are no more entries, this value is zero.
        OffsetToNext DWORD ?
        ;  Flags describing characteristics about this stream.
        Flags DWORD ?
        ;  This value is reserved and is currently zero.
        Reserved LARGE_INTEGER <>
        ;  This is the cluster that this entry refers to.  It will be one
        ;  of the clusters passed in the input structure.
        Cluster LARGE_INTEGER <>
        ;  A NULL-terminated Unicode string containing the path of the
        ;  object relative to the root of the volume.  This string
        ;  will refer to the attribute or stream represented by the
        ;  cluster.
        FileName WORD 1 dup (?)
      LOOKUP_STREAM_FROM_CLUSTER_ENTRY ends
      _LOOKUP_STREAM_FROM_CLUSTER_ENTRY typedef LOOKUP_STREAM_FROM_CLUSTER_ENTRY
      PLOOKUP_STREAM_FROM_CLUSTER_ENTRY typedef ptr LOOKUP_STREAM_FROM_CLUSTER_ENTRY
      ;==================== FSCTL_FILE_TYPE_NOTIFICATION =======================
      ;  This is the structure for the FSCTL_FILE_TYPE_NOTIFICATION operation.
      ;  Its purpose is to notify the storage stack about the extents of certain
      ;  types of files.  This is only callable from kernel mode
      FILE_TYPE_NOTIFICATION_INPUT struct
        ;  Flags for this operation
        ;  FILE_TYPE_NOTIFICATION_FLAG_*
        Flags DWORD ?
        ;  A count of how many FileTypeID guids are given
        NumFileTypeIDs DWORD ?
        ;  This is a unique identifier for the type of file notification occurring
        FileTypeID GUID 1 dup (<>)
      FILE_TYPE_NOTIFICATION_INPUT ends
      _FILE_TYPE_NOTIFICATION_INPUT typedef FILE_TYPE_NOTIFICATION_INPUT
      PFILE_TYPE_NOTIFICATION_INPUT typedef ptr FILE_TYPE_NOTIFICATION_INPUT
      ;  Flags for the given operation
      FILE_TYPE_NOTIFICATION_FLAG_USAGE_BEGIN equ 00000001h;Set when adding the specified usage on the given file

      FILE_TYPE_NOTIFICATION_FLAG_USAGE_END equ 00000002h;Set when removing the specified usage on the given file

      ;  These are the globally defined file types
      DEFINE_GUID FILE_TYPE_NOTIFICATION_GUID_PAGE_FILE, 0d0a64a1h, 38fch, 4db8h, 9fh, 0e7h, 3fh, 43h, 52h, 0cdh, 7ch, 5ch
      DEFINE_GUID FILE_TYPE_NOTIFICATION_GUID_HIBERNATION_FILE, 0b7624d64h, 0b9a3h, 4cf8h, 80h, 11h, 5bh, 86h, 0c9h, 40h, 0e7h, 0b7h
      DEFINE_GUID FILE_TYPE_NOTIFICATION_GUID_CRASHDUMP_FILE, 9d453eb7h, 0d2a6h, 4dbdh, 0a2h, 0e3h, 0fbh, 0d0h, 0edh, 91h, 09h, 0a9h
      ;=========================FSCTL_CSV_MGMT_LOCK===========================
      CSV_MGMTLOCK_CHECK_VOLUME_REDIRECTED equ 00000001h
      CSV_MGMT_LOCK struct
        Flags DWORD ?
      CSV_MGMT_LOCK ends
      _CSV_MGMT_LOCK typedef CSV_MGMT_LOCK
      PCSV_MGMT_LOCK typedef ptr CSV_MGMT_LOCK
      ;========================= FSCTL_IS_CSV_FILE ============================
      ; Structure for FSCTL_IS_CSV_FILE
      CSV_NAMESPACE_INFO struct
        Version DWORD ?
        DeviceNumber DWORD ?
        StartingOffset LARGE_INTEGER <>
        SectorSize DWORD ?
      CSV_NAMESPACE_INFO ends
      _CSV_NAMESPACE_INFO typedef CSV_NAMESPACE_INFO
      PCSV_NAMESPACE_INFO typedef ptr CSV_NAMESPACE_INFO
      CSV_NAMESPACE_INFO_V1 equ <(sizeof(CSV_NAMESPACE_INFO))>
      CSV_INVALID_DEVICE_NUMBER equ 0FFFFFFFFh
      ;========================= FSCTL_CSV_CONTROL =============================
      CSV_CONTROL_OP typedef SDWORD
      CsvControlStartRedirectFile equ 02h
      CsvControlStopRedirectFile equ 03h
      CsvControlQueryRedirectState equ 04h
      CsvControlQueryFileRevision equ 06h
      CsvControlQueryMdsPath equ 08h
      CsvControlQueryFileRevisionFileId128 equ 09h
      CsvControlQueryVolumeRedirectState equ 0ah
      CsvControlEnableUSNRangeModificationTracking equ 0dh
      CsvControlMarkHandleLocalVolumeMount equ 0eh
      CsvControlUnmarkHandleLocalVolumeMount equ 0fh
      CsvControlGetCsvFsMdsPathV2 equ 12h
      CsvControlDisableCaching equ 13h
      CsvControlEnableCaching equ 14h
      CsvControlStartForceDFO equ 15h
      CsvControlStopForceDFO equ 16h
      CsvControlQueryMdsPathNoPause equ 17h
      CsvControlSetVolumeId equ 18h
      CsvControlQueryVolumeId equ 19h
      _CSV_CONTROL_OP typedef CSV_CONTROL_OP
      PCSV_CONTROL_OP typedef ptr CSV_CONTROL_OP
      CSV_CONTROL_PARAM struct
        Operation CSV_CONTROL_OP ?
        Unused SQWORD ?
      CSV_CONTROL_PARAM ends
      _CSV_CONTROL_PARAM typedef CSV_CONTROL_PARAM
      PCSV_CONTROL_PARAM typedef ptr CSV_CONTROL_PARAM
      ; Output for the CsvControlQueryRedirectState
      CSV_QUERY_REDIRECT_STATE struct
        MdsNodeId DWORD ?
        DsNodeId DWORD ?
        FileRedirected BYTE ?
      CSV_QUERY_REDIRECT_STATE ends
      _CSV_QUERY_REDIRECT_STATE typedef CSV_QUERY_REDIRECT_STATE
      PCSV_QUERY_REDIRECT_STATE typedef ptr CSV_QUERY_REDIRECT_STATE
      ; Output for the CsvControlQueryFileRevision
      ; Note that revision tracking is per file, and not per
      ; stream so it changes every time one of the stream
      ; changes.
      CSV_QUERY_FILE_REVISION struct
        ; NTFS File Id
        FileId SQWORD ?
        ; FileRevision[0] increases each time the CSV MDS
        ; stack is rebuilt and CSVFLT loses its state.
        ; FileRevision[1] increases each time CSV MDS
        ; stack purges the cached revision # for the
        ; file.
        ; FileRevision[2] increases each time CSV MDS
        ; observes that file sizes might have
        ; changed or the file might have been written
        ; to. It also is incremented when one of the
        ; nodes performs the first direct IO on a stream
        ; associated with this file after opening this stream.
        ; If any of the numbers are 0 the caller should
        ; assume that the file was modified
        FileRevision SQWORD 3 dup (?)
      CSV_QUERY_FILE_REVISION ends
      _CSV_QUERY_FILE_REVISION typedef CSV_QUERY_FILE_REVISION
      PCSV_QUERY_FILE_REVISION typedef ptr CSV_QUERY_FILE_REVISION
      ; Output for the CsvControlQueryFileRevisionFileId128
      ; Note that revision tracking is per file, and not per
      ; stream so it changes every time one of the stream
      ; changes.
      CSV_QUERY_FILE_REVISION_FILE_ID_128 struct
        ; File Id
        FileId FILE_ID_128 <>
        ; FileRevision[0] increases each time the CSV MDS
        ; stack is rebuilt and CSVFLT loses its state.
        ; FileRevision[1] increases each time CSV MDS
        ; stack purges the cached revision # for the
        ; file.
        ; FileRevision[2] increases each time CSV MDS
        ; observes that file sizes might have
        ; changed or the file might have been written
        ; to. It also is incremented when one of the
        ; nodes performs the first direct IO on a stream
        ; associated with this file after opening this stream.
        ; If any of the numbers are 0 the caller should
        ; assume that the file was modified
        FileRevision SQWORD 3 dup (?)
      CSV_QUERY_FILE_REVISION_FILE_ID_128 ends
      _CSV_QUERY_FILE_REVISION_FILE_ID_128 typedef CSV_QUERY_FILE_REVISION_FILE_ID_128
      PCSV_QUERY_FILE_REVISION_FILE_ID_128 typedef ptr CSV_QUERY_FILE_REVISION_FILE_ID_128
      ; Output for the CsvControlQueryMdsPath
      ; This control returns the path that is used by CSV to
      ; communicate to the MDS
      CSV_QUERY_MDS_PATH struct
        MdsNodeId DWORD ?
        DsNodeId DWORD ?
        PathLength DWORD ?
        Path WORD 1 dup (?)
      CSV_QUERY_MDS_PATH ends
      _CSV_QUERY_MDS_PATH typedef CSV_QUERY_MDS_PATH
      PCSV_QUERY_MDS_PATH typedef ptr CSV_QUERY_MDS_PATH
      CSVFS_DISK_CONNECTIVITY typedef SDWORD
      CsvFsDiskConnectivityNone equ 0
      CsvFsDiskConnectivityMdsNodeOnly equ 1
      CsvFsDiskConnectivitySubsetOfNodes equ 2
      CsvFsDiskConnectivityAllNodes equ 3
      _CSVFS_DISK_CONNECTIVITY typedef CSVFS_DISK_CONNECTIVITY
      PCSVFS_DISK_CONNECTIVITY typedef ptr CSVFS_DISK_CONNECTIVITY
      ; Output for the CsvControlQueryVolumeRedirectState
      CSV_QUERY_VOLUME_REDIRECT_STATE struct
        MdsNodeId DWORD ?
        DsNodeId DWORD ?
        IsDiskConnected BYTE ?
        ClusterEnableDirectIo BYTE ?
        DiskConnectivity CSVFS_DISK_CONNECTIVITY ?
      CSV_QUERY_VOLUME_REDIRECT_STATE ends
      _CSV_QUERY_VOLUME_REDIRECT_STATE typedef CSV_QUERY_VOLUME_REDIRECT_STATE
      PCSV_QUERY_VOLUME_REDIRECT_STATE typedef ptr CSV_QUERY_VOLUME_REDIRECT_STATE
      ; Structure is defined up to and including field PathLength
      CSV_QUERY_MDS_PATH_V2_VERSION_1 equ 1
      CSV_QUERY_MDS_PATH_FLAG_STORAGE_ON_THIS_NODE_IS_CONNECTED equ 1h
      CSV_QUERY_MDS_PATH_FLAG_CSV_DIRECT_IO_ENABLED equ 2h
      CSV_QUERY_MDS_PATH_FLAG_SMB_BYPASS_CSV_ENABLED equ 4h
      ; Output for the CsvControlGetCsvFsMdsPathV2
      CSV_QUERY_MDS_PATH_V2 struct
        ; Version of the structure.
        ; CSV_QUERY_MDS_PATH_V2_VERSION_*
        Version SQWORD ?
        ; Required output buffer size to completely fit
        ; all the data
        RequiredSize DWORD ?
        ; Id of MDS and of the current node.
        ; When these two Ids are the same then current node is MDS
        ; otherwise current node is a DS
        MdsNodeId DWORD ?
        DsNodeId DWORD ?
        ; A combination of CSV_QUERY_MDS_PATH_FLAG_* flags
        Flags DWORD ?
        ; Describes disk connectivity across all cluster nodes
        DiskConnectivity CSVFS_DISK_CONNECTIVITY ?
        ; Volume GUID of this CSV volume
        VolumeId GUID <>
        ; Offset to an array of DIPs of MDS and number of bytes
        ; in that array. Each array entry has type SOCKADDR_INET
        ; number of elements is IpAddressLength / sizeof(SOCKADDR_INET)
        IpAddressOffset DWORD ?
        IpAddressLength DWORD ?
        ; Offset to the a Unicode string that contains
        ; path this node is using to open files on MDS, and number of
        ; characters in that string
        PathOffset DWORD ?
        PathLength DWORD ?
      CSV_QUERY_MDS_PATH_V2 ends
      _CSV_QUERY_MDS_PATH_V2 typedef CSV_QUERY_MDS_PATH_V2
      PCSV_QUERY_MDS_PATH_V2 typedef ptr CSV_QUERY_MDS_PATH_V2
      ; Input for the CsvControlSetVolumeId
      CSV_SET_VOLUME_ID struct
        VolumeId GUID <>
      CSV_SET_VOLUME_ID ends
      _CSV_SET_VOLUME_ID typedef CSV_SET_VOLUME_ID
      PCSV_SET_VOLUME_ID typedef ptr CSV_SET_VOLUME_ID
      ; Output for the CsvControlQueryVolumeId
      CSV_QUERY_VOLUME_ID struct
        VolumeId GUID <>
      CSV_QUERY_VOLUME_ID ends
      _CSV_QUERY_VOLUME_ID typedef CSV_QUERY_VOLUME_ID
      PCSV_QUERY_VOLUME_ID typedef ptr CSV_QUERY_VOLUME_ID
      ;========================= FSCTL_LMR_QUERY_INFO =============================
      LMR_QUERY_INFO_CLASS typedef SDWORD
      LMRQuerySessionInfo equ 1
      _LMR_QUERY_INFO_CLASS typedef LMR_QUERY_INFO_CLASS
      PLMR_QUERY_INFO_CLASS typedef ptr LMR_QUERY_INFO_CLASS
      LMR_QUERY_INFO_PARAM struct
        Operation LMR_QUERY_INFO_CLASS ?
      LMR_QUERY_INFO_PARAM ends
      _LMR_QUERY_INFO_PARAM typedef LMR_QUERY_INFO_PARAM
      PLMR_QUERY_INFO_PARAM typedef ptr LMR_QUERY_INFO_PARAM
      ; Output for the LMRQuerySessionInfo
      LMR_QUERY_SESSION_INFO struct
        SessionId QWORD ?
      LMR_QUERY_SESSION_INFO ends
      _LMR_QUERY_SESSION_INFO typedef LMR_QUERY_SESSION_INFO
      PLMR_QUERY_SESSION_INFO typedef ptr LMR_QUERY_SESSION_INFO
      ;====================== FSCTL_CSV_QUERY_VETO_FILE_DIRECT_IO =========================
      ; In output buffer set Veto to TRUE to prevent CsvFs from
      ; performing DirectIO on the stream.
      ; VetoedFromAltitude and Reason are optional fields that
      ; are used to help with troubleshooting. CSV writes these
      ; strings to the diagnostic log. Filter can set it to a
      ; string that would hint why volume is in a redirected mode.
      CSV_QUERY_VETO_FILE_DIRECT_IO_OUTPUT struct
        VetoedFromAltitudeIntegral QWORD ?
        VetoedFromAltitudeDecimal QWORD ?
        Reason WORD 256 dup (?)
      CSV_QUERY_VETO_FILE_DIRECT_IO_OUTPUT ends
      _CSV_QUERY_VETO_FILE_DIRECT_IO_OUTPUT typedef CSV_QUERY_VETO_FILE_DIRECT_IO_OUTPUT
      PCSV_QUERY_VETO_FILE_DIRECT_IO_OUTPUT typedef ptr CSV_QUERY_VETO_FILE_DIRECT_IO_OUTPUT
      ;* _WIN32_WINNT >= _WIN32_WINNT_WIN7 *
    endif
    if (_WIN32_WINNT ge _WIN32_WINNT_WIN10_RS5)
      ; Storage Reserve common definitions
      STORAGE_RESERVE_ID typedef SDWORD
      StorageReserveIdNone equ 0
      StorageReserveIdHard equ 1
      StorageReserveIdSoft equ 2
      StorageReserveIdUpdateScratch equ 3
      StorageReserveIdMax equ 4
      _STORAGE_RESERVE_ID typedef STORAGE_RESERVE_ID
      PSTORAGE_RESERVE_ID typedef ptr STORAGE_RESERVE_ID
      ;* (_WIN32_WINNT >= _WIN32_WINNT_WIN10_RS5) *
    endif
    if (_WIN32_WINNT ge _WIN32_WINNT_WIN8)
      ;========================= FSCTL_IS_VOLUME_OWNED_BYCSVFS ============================
      CSV_IS_OWNED_BY_CSVFS struct
        OwnedByCSVFS BYTE ?
      CSV_IS_OWNED_BY_CSVFS ends
      _CSV_IS_OWNED_BY_CSVFS typedef CSV_IS_OWNED_BY_CSVFS
      PCSV_IS_OWNED_BY_CSVFS typedef ptr CSV_IS_OWNED_BY_CSVFS
      ;======================== FSCTL_FILE_LEVEL_TRIM ===========================
      ;  Structure definitions for supporting file level trim
      FILE_LEVEL_TRIM_RANGE struct
        ;  Bytes offset from the front of the given file to trim at
        Offset_ QWORD ?
        ;  Length in bytes to trim from the given offset
        Length_ QWORD ?
      FILE_LEVEL_TRIM_RANGE ends
      _FILE_LEVEL_TRIM_RANGE typedef FILE_LEVEL_TRIM_RANGE
      PFILE_LEVEL_TRIM_RANGE typedef ptr FILE_LEVEL_TRIM_RANGE
      ;  Input buffer defining what ranges to trim
      FILE_LEVEL_TRIM struct
        ; Used when interacting with byte range locks. Set to zero if not SMB or
        ;  similar.
        Key DWORD ?
        ; A count of how many Offset:Length pairs are given
        NumRanges DWORD ?
        ;  All the pairs.
        Ranges FILE_LEVEL_TRIM_RANGE 1 dup (<>)
      FILE_LEVEL_TRIM ends
      _FILE_LEVEL_TRIM typedef FILE_LEVEL_TRIM
      PFILE_LEVEL_TRIM typedef ptr FILE_LEVEL_TRIM
      ;  This is an optional output buffer
      FILE_LEVEL_TRIM_OUTPUT struct
        ;  Receives the number of input ranges
        ;  that were processed
        NumRangesProcessed DWORD ?
      FILE_LEVEL_TRIM_OUTPUT ends
      _FILE_LEVEL_TRIM_OUTPUT typedef FILE_LEVEL_TRIM_OUTPUT
      PFILE_LEVEL_TRIM_OUTPUT typedef ptr FILE_LEVEL_TRIM_OUTPUT
      ;==================== FSCTL_QUERY_FILE_LAYOUT ===========================
      ; Clear the state of the internal cursor.
      QUERY_FILE_LAYOUT_RESTART equ (00000001h)
      ;  Request that the API call retrieve name information for the
      ;  objects on the volume.
      QUERY_FILE_LAYOUT_INCLUDE_NAMES equ (00000002h)
      ;  Request that the API call include streams of the file.
      QUERY_FILE_LAYOUT_INCLUDE_STREAMS equ (00000004h)
      ;  Include extent information with the attribute entries, where applicable.
      ;  Use of this flag requires the _INCLUDE_STREAMS flag.
      QUERY_FILE_LAYOUT_INCLUDE_EXTENTS equ (00000008h)
      ;  Include extra information, such as modification times and security
      ;  IDs, with each returned file layout entry.
      QUERY_FILE_LAYOUT_INCLUDE_EXTRA_INFO equ (00000010h)
      ;  Include unallocated attributes in the enumeration, which in NTFS means one
      ;  of three cases:
      ;      1. Resident attributes.
      ;      2. Nonresident attributes of length 0.
      ;      3. Compressed or sparse nonresident attributes with no physical
      ;         allocation (consisting only of a sparse hole).
      ;  This flag may only be used when no cluster ranges are specified (i.e.
      ;  on a whole-volume query).
      QUERY_FILE_LAYOUT_INCLUDE_STREAMS_WITH_NO_CLUSTERS_ALLOCATED equ (00000020h)
      ;  Request the full path to the file be included in the file name.
      ;  This flag must be used with QUERY_FILE_LAYOUT_INCLUDE_NAMES
      QUERY_FILE_LAYOUT_INCLUDE_FULL_PATH_IN_NAMES equ (00000040h)
      ;  Enable QueryFileLayout to include information on attribute streams.
      ;  Additionally, individual stream information flags must be enabled for
      ;  information on a given stream to be returned.
      QUERY_FILE_LAYOUT_INCLUDE_STREAM_INFORMATION equ (00000080h)
      ;  Have QueryFileLayout include information (defined by DesiredStorageClass in StreamInformation)
      ;  on DSC streams.
      ;  This flag must be used in conjunction with QUERY_FILE_LAYOUT_INCLUDE_STREAM_INFORMATION
      QUERY_FILE_LAYOUT_INCLUDE_STREAM_INFORMATION_FOR_DSC_ATTRIBUTE equ (00000100h)
      ;  Have QueryFileLayout include information on TxF streams.
      ;  This flag must be used in conjunction with QUERY_FILE_LAYOUT_INCLUDE_STREAM_INFORMATION
      QUERY_FILE_LAYOUT_INCLUDE_STREAM_INFORMATION_FOR_TXF_ATTRIBUTE equ (00000200h)
      ;  Have QueryFileLayout include information on EFS streams.
      ;  This flag must be used in conjunction with QUERY_FILE_LAYOUT_INCLUDE_STREAM_INFORMATION
      QUERY_FILE_LAYOUT_INCLUDE_STREAM_INFORMATION_FOR_EFS_ATTRIBUTE equ (00000400h)
      ;  We can ask (politely) QueryFileLayout to only return files that have
      ;  a given set of attributes present. This flag must be used with at least
      ;  one attribute type flag or Query File Layout will return no files.
      QUERY_FILE_LAYOUT_INCLUDE_ONLY_FILES_WITH_SPECIFIC_ATTRIBUTES equ (00000800h)
      ;  Have QueryFileLayout include files with a DSC attribute in the output buffer.
      ;  This must be used in conjunction with QUERY_FILE_LAYOUT_INCLUDE_ONLY_FILES_WITH_SPECIFIC_ATTRIBUTES
      QUERY_FILE_LAYOUT_INCLUDE_FILES_WITH_DSC_ATTRIBUTE equ (00001000h)
      ;  Have QueryFileLayout include information (defined by DataStream in StreamInformation) on $DATA streams.
      ;  This flag must be used in conjunction with QUERY_FILE_LAYOUT_INCLUDE_STREAM_INFORMATION
      QUERY_FILE_LAYOUT_INCLUDE_STREAM_INFORMATION_FOR_DATA_ATTRIBUTE equ (00002000h)
      ;  Have QueryFileLayout include information (defined by Reparse in StreamInformation) on $REPARSE_POINT streams.
      ;  This flag must be used in conjunction with QUERY_FILE_LAYOUT_INCLUDE_STREAM_INFORMATION
      QUERY_FILE_LAYOUT_INCLUDE_STREAM_INFORMATION_FOR_REPARSE_ATTRIBUTE equ (00004000h)
      ;  Have QueryFileLayout include information (defined by Ea as in StreamInformation) on $EA streams.
      ;  This flag must be used in conjunction with QUERY_FILE_LAYOUT_INCLUDE_STREAM_INFORMATION
      QUERY_FILE_LAYOUT_INCLUDE_STREAM_INFORMATION_FOR_EA_ATTRIBUTE equ (00008000h)
      QUERY_FILE_LAYOUT_FILTER_TYPE typedef SDWORD
      QUERY_FILE_LAYOUT_FILTER_TYPE_NONE equ 0
      QUERY_FILE_LAYOUT_FILTER_TYPE_CLUSTERS equ 1
      QUERY_FILE_LAYOUT_FILTER_TYPE_FILEID equ 2
      if (_WIN32_WINNT ge _WIN32_WINNT_WIN10_RS5)
        QUERY_FILE_LAYOUT_FILTER_TYPE_STORAGE_RESERVE_ID equ 3
        ;* (_WIN32_WINNT >= _WIN32_WINNT_WIN10_RS5) *
      endif
      QUERY_FILE_LAYOUT_NUM_FILTER_TYPES equ 4
      _QUERY_FILE_LAYOUT_FILTER_TYPE typedef QUERY_FILE_LAYOUT_FILTER_TYPE

      CLUSTER_RANGE struct
        ; The starting cluster for this query region
        ; (inclusive).
        StartingCluster LARGE_INTEGER <>
        ; The length of the cluster region.
        ClusterCount LARGE_INTEGER <>
      CLUSTER_RANGE ends
      _CLUSTER_RANGE typedef CLUSTER_RANGE
      PCLUSTER_RANGE typedef ptr CLUSTER_RANGE
      FILE_REFERENCE_RANGE struct
        ; The starting file reference number for this
        ; query region (inclusive).
        StartingFileReferenceNumber QWORD ?
        ; The ending file reference number for this
        ; query region (inclusive).
        EndingFileReferenceNumber QWORD ?
      FILE_REFERENCE_RANGE ends
      _FILE_REFERENCE_RANGE typedef FILE_REFERENCE_RANGE
      PFILE_REFERENCE_RANGE typedef ptr FILE_REFERENCE_RANGE
      QUERY_FILE_LAYOUT_INPUT struct
        ; Number of filter entries in the following array.
        ; The input buffer must be large enough to contain this
        ; number or the operation will fail.
        ; This was originally named NumberOfPairs when there
        ; was only one type of filter.  The union is simply to
        ; maintain code compatibility.
        union
          FilterEntryCount DWORD ?
          NumberOfPairs DWORD ?
        ends
        ; Flags for the operation.
        Flags DWORD ?
        ;  The type of filter being applied for this operation.
        FilterType QUERY_FILE_LAYOUT_FILTER_TYPE ?
        ;  Reserved for future use. Should be set to zero.
        Reserved DWORD ?
        ;  A pointer to the filter-type-specific information.  This is
        ;  the caller's actual set of cluster ranges, etc.
        union Filter
          ;  The following is used when the caller wishes to filter
          ;  on a set of cluster ranges.
          ClusterRanges CLUSTER_RANGE 1 dup (<>)
          ;  The following is used when the caller wishes to filter
          ;  on a set of file reference ranges.
          FileReferenceRanges FILE_REFERENCE_RANGE 1 dup (<>)
          ;  The following is used when the caller wishes to filter
          ;  on a set of storage reserve IDs.
          if (_WIN32_WINNT ge _WIN32_WINNT_WIN10_RS5)
            StorageReserveIds STORAGE_RESERVE_ID 1 dup (?)
            ;* (_WIN32_WINNT >= _WIN32_WINNT_WIN10_RS5) *
          endif
        ends
      QUERY_FILE_LAYOUT_INPUT ends
      _QUERY_FILE_LAYOUT_INPUT typedef QUERY_FILE_LAYOUT_INPUT
      PQUERY_FILE_LAYOUT_INPUT typedef ptr QUERY_FILE_LAYOUT_INPUT
      ; Indicates that the filesystem is returning stream extents in a
      ; single-instanced fashion.
      QUERY_FILE_LAYOUT_SINGLE_INSTANCED equ (00000001h)
      QUERY_FILE_LAYOUT_OUTPUT struct
        ; Number of file entries following this header.
        ; Includes only the number of file entries in
        ; this iteration.
        FileEntryCount DWORD ?
        ; Offset to the first file entry in this buffer,
        ; expressed in bytes.
        FirstFileOffset DWORD ?
        ; Flags indicating context that is applicable to the
        ; entire output set.
        Flags DWORD ?
        ; For alignment/later use.
        Reserved DWORD ?
      QUERY_FILE_LAYOUT_OUTPUT ends
      _QUERY_FILE_LAYOUT_OUTPUT typedef QUERY_FILE_LAYOUT_OUTPUT
      PQUERY_FILE_LAYOUT_OUTPUT typedef ptr QUERY_FILE_LAYOUT_OUTPUT
      FILE_LAYOUT_ENTRY struct
        ; Version number of this structure
        ; (current version number is 1).
        Version DWORD ?
        ; Offset to next file entry (in bytes)
        ; or zero if this is the last entry.
        NextFileOffset DWORD ?
        ; Flags containing context applicable to this
        ; file.
        Flags DWORD ?
        ; File attributes.
        FileAttributes DWORD ?
        ; File ID for this file.
        FileReferenceNumber QWORD ?
        ; Offset to the first name entry
        ; from the start of this record, or
        ; zero if there are no link records.
        FirstNameOffset DWORD ?
        ; Offset to the first stream entry
        ; from the start of this record, or
        ; zero if there are no stream records.
        FirstStreamOffset DWORD ?
        ; Offset to additional per-file information,
        ; contained in a FILE_LAYOUT_INFO_ENTRY
        ; structure, or zero if this information was
        ; not returned.
        ExtraInfoOffset DWORD ?
        if (_WIN32_WINNT lt _WIN32_WINNT_WIN10_RS5)
          ; For alignment/future use.
          Reserved DWORD ?
        else
          ; Number of bytes accessible in additional per-file
          ; information, contained in a FILE_LAYOUT_INFO_ENTRY
          ; structure, or zero if this information was
          ; not returned.
          ; Since pre-RS5 this was a reserved field that was
          ; always set to zero by the file system, if
          ; ExtraInfoOffset is non-zero but ExtraInfoLength
          ; is zero then callers can assume the extra info
          ; includes all fields up to Usn.  If ExtraInfoLength
          ; is non-zero then it should be used by callers to
          ; determine which fields are safe to access.
          ExtraInfoLength DWORD ?
          ;* (_WIN32_WINNT < _WIN32_WINNT_WIN10_RS5) *
        endif
        ; The structure may be extended here to support
        ; additional static fields (e.g. pointing to
        ; a FILE_BASIC_INFORMATION structure, etc.). This
        ; sort of change should coincide with a version
        ; number increase.
      FILE_LAYOUT_ENTRY ends
      _FILE_LAYOUT_ENTRY typedef FILE_LAYOUT_ENTRY
      PFILE_LAYOUT_ENTRY typedef ptr FILE_LAYOUT_ENTRY
      ; Each file name entry may be one, both, or neither of
      ; these.
      FILE_LAYOUT_NAME_ENTRY_PRIMARY equ (00000001h)
      FILE_LAYOUT_NAME_ENTRY_DOS equ (00000002h)
      FILE_LAYOUT_NAME_ENTRY struct
        ; Offset to next name entry (in bytes)
        ; or zero if this is the last entry.
        NextNameOffset DWORD ?
        ; Flags for this file name entry.
        Flags DWORD ?
        ; Parent FRN for this link.
        ParentFileReferenceNumber QWORD ?
        ; File name length (bytes).
        FileNameLength DWORD ?
        ; For later use/alignment.
        Reserved DWORD ?
        ; Starting point for the name itself
        ; (NOT null-terminated).
        FileName WORD 1 dup (?)
      FILE_LAYOUT_NAME_ENTRY ends
      _FILE_LAYOUT_NAME_ENTRY typedef FILE_LAYOUT_NAME_ENTRY
      PFILE_LAYOUT_NAME_ENTRY typedef ptr FILE_LAYOUT_NAME_ENTRY
      FILE_LAYOUT_INFO_ENTRY struct
        ; Basic information for this file.
        struct BasicInformation
          CreationTime LARGE_INTEGER <>
          LastAccessTime LARGE_INTEGER <>
          LastWriteTime LARGE_INTEGER <>
          ChangeTime LARGE_INTEGER <>
          FileAttributes DWORD ?
        ends
        ; Owner ID for this file.
        OwnerId DWORD ?
        ; Security ID for this file.
        SecurityId DWORD ?
        ; Update sequence number for this file.
        Usn USN ?
        if (_WIN32_WINNT ge _WIN32_WINNT_WIN10_RS5)
          ; Storage Reserve ID assigned to the file (0 for none).
          StorageReserveId STORAGE_RESERVE_ID ?
          ;* (_WIN32_WINNT < _WIN32_WINNT_WIN10_RS5) *
        endif
      FILE_LAYOUT_INFO_ENTRY ends
      _FILE_LAYOUT_INFO_ENTRY typedef FILE_LAYOUT_INFO_ENTRY
      PFILE_LAYOUT_INFO_ENTRY typedef ptr FILE_LAYOUT_INFO_ENTRY
      ; This attribute/stream is known to the filesystem to be immovable.
      STREAM_LAYOUT_ENTRY_IMMOVABLE equ (00000001h)
      ; This attribute/stream is currently pinned by another application.
      ; It is unmovable for the duration of the pin.
      STREAM_LAYOUT_ENTRY_PINNED equ (00000002h)
      ; This attribute is resident.
      STREAM_LAYOUT_ENTRY_RESIDENT equ (00000004h)
      ; This attribute has no clusters allocated to it.
      STREAM_LAYOUT_ENTRY_NO_CLUSTERS_ALLOCATED equ (00000008h)
      ; This layout entry contains the information (data) for the attribute
      STREAM_LAYOUT_ENTRY_HAS_INFORMATION equ (00000010h)
      STREAM_LAYOUT_ENTRY struct
        ; Version of this struct. Current version is 2.
        Version DWORD ?
        ; Offset to the next stream entry (bytes).
        NextStreamOffset DWORD ?
        ; FSCTL-specific flags.
        Flags DWORD ?
        ; Offset to the extent information buffer
        ; for this stream, or zero if none exists.
        ; This is relative to the start of this
        ; stream record.
        ExtentInformationOffset DWORD ?
        ; Total allocated size of this stream,
        ; in bytes.
        AllocationSize LARGE_INTEGER <>
        ; End of file location as a byte offset.
        EndOfFile LARGE_INTEGER <>
        ;  Offset to stream information. This is the
        ;  content of the stream
        StreamInformationOffset DWORD ?
        ; Attribute code.
        AttributeTypeCode DWORD ?
        ; Stream attribute flags.
        AttributeFlags DWORD ?
        ; Length of the stream identifier, in bytes.
        StreamIdentifierLength DWORD ?
        ; Starting point for the stream identifier
        ; buffer.
        StreamIdentifier WORD 1 dup (?)
      STREAM_LAYOUT_ENTRY ends
      _STREAM_LAYOUT_ENTRY typedef STREAM_LAYOUT_ENTRY
      PSTREAM_LAYOUT_ENTRY typedef ptr STREAM_LAYOUT_ENTRY
      ; Flag noting that the extent information may be interpreted as
      ; a RETRIEVAL_POINTERS_BUFFER structure
      STREAM_EXTENT_ENTRY_AS_RETRIEVAL_POINTERS equ (00000001h)
      ; Flag noting that all of the stream's extents are returned in
      ; this structure, even if only some of them fall within the caller's
      ; specified interest region(s).
      STREAM_EXTENT_ENTRY_ALL_EXTENTS equ (00000002h)
      STREAM_EXTENT_ENTRY struct
        ; Extent-level flags for this entry.
        Flags DWORD ?
        union ExtentInformation
          ; All that's defined for now is a retrieval
          ; pointers buffer, since this is what NTFS
          ; will use.
          RetrievalPointers RETRIEVAL_POINTERS_BUFFER <>
        ends
      STREAM_EXTENT_ENTRY ends
      _STREAM_EXTENT_ENTRY typedef STREAM_EXTENT_ENTRY
      PSTREAM_EXTENT_ENTRY typedef ptr STREAM_EXTENT_ENTRY
      ;==================== FSCTL_GET_INTEGRITY_INFORMATION / FSCTL_SET_INTEGRITY_INFORMATION ===========================
      CHECKSUM_TYPE_UNCHANGED equ 0FFFFh
      CHECKSUM_TYPE_NONE equ (0)
      CHECKSUM_TYPE_CRC32 equ (1)
      CHECKSUM_TYPE_CRC64 equ (2)
      CHECKSUM_TYPE_ECC equ (3)
      CHECKSUM_TYPE_SHA256 equ (4)
      CHECKSUM_TYPE_FIRST_UNUSED_TYPE equ (5)
      FSCTL_INTEGRITY_FLAG_CHECKSUM_ENFORCEMENT_OFF equ (1)
      FSCTL_GET_INTEGRITY_INFORMATION_BUFFER struct
        ChecksumAlgorithm WORD ?
        ; Checksum algorithm. e.g. CHECKSUM_TYPE_UNCHANGED, CHECKSUM_TYPE_NONE, CHECKSUM_TYPE_CRC32
        Reserved WORD ?
        ; Must be 0
        Flags DWORD ?
        ; FSCTL_INTEGRITY_FLAG_xxx
        ChecksumChunkSizeInBytes DWORD ?
        ClusterSizeInBytes DWORD ?
      FSCTL_GET_INTEGRITY_INFORMATION_BUFFER ends
      _FSCTL_GET_INTEGRITY_INFORMATION_BUFFER typedef FSCTL_GET_INTEGRITY_INFORMATION_BUFFER
      PFSCTL_GET_INTEGRITY_INFORMATION_BUFFER typedef ptr FSCTL_GET_INTEGRITY_INFORMATION_BUFFER
      FSCTL_SET_INTEGRITY_INFORMATION_BUFFER struct
        ChecksumAlgorithm WORD ?
        ; Checksum algorithm. e.g. CHECKSUM_TYPE_UNCHANGED, CHECKSUM_TYPE_NONE, CHECKSUM_TYPE_CRC32
        Reserved WORD ?
        ; Must be 0
        Flags DWORD ?
        ; FSCTL_INTEGRITY_FLAG_xxx
      FSCTL_SET_INTEGRITY_INFORMATION_BUFFER ends
      _FSCTL_SET_INTEGRITY_INFORMATION_BUFFER typedef FSCTL_SET_INTEGRITY_INFORMATION_BUFFER
      PFSCTL_SET_INTEGRITY_INFORMATION_BUFFER typedef ptr FSCTL_SET_INTEGRITY_INFORMATION_BUFFER
      ;==================== FSCTL_SET_INTEGRITY_INFORMATION_EX ===========================
      if (_WIN32_WINNT ge _WIN32_WINNT_WINTHRESHOLD)
        FSCTL_SET_INTEGRITY_INFORMATION_BUFFER_EX struct
          EnableIntegrity BYTE ?
          ; 0 to disable integrity, 1 to enable integrity
          KeepIntegrityStateUnchanged BYTE ?
          ; 1 to keep the current integrity state and ignore the value in EnableIntegrity, 0 to use EnableIntegrity value
          Reserved WORD ?
          ; Must be 0
          Flags DWORD ?
          ; FSCTL_INTEGRITY_FLAG_xxx
          Version BYTE ?
          ; Structure version info, must be 1
          Reserved2 BYTE 7 dup (?)
          ; Must be 0
        FSCTL_SET_INTEGRITY_INFORMATION_BUFFER_EX ends
        _FSCTL_SET_INTEGRITY_INFORMATION_BUFFER_EX typedef FSCTL_SET_INTEGRITY_INFORMATION_BUFFER_EX
        PFSCTL_SET_INTEGRITY_INFORMATION_BUFFER_EX typedef ptr FSCTL_SET_INTEGRITY_INFORMATION_BUFFER_EX
      endif
      ; #if (_WIN32_WINNT >= _WIN32_WINNT_WINTHRESHOLD)
      ;======================== FSCTL_OFFLOAD_READ ==============================
      ;  Structures used by FSCTL_OFFLOAD_READ operation
      FSCTL_OFFLOAD_READ_INPUT struct
        Size_ DWORD ?
        Flags DWORD ?
        TokenTimeToLive DWORD ?
        ; In milliseconds
        Reserved DWORD ?
        FileOffset QWORD ?
        CopyLength QWORD ?
      FSCTL_OFFLOAD_READ_INPUT ends
      _FSCTL_OFFLOAD_READ_INPUT typedef FSCTL_OFFLOAD_READ_INPUT
      PFSCTL_OFFLOAD_READ_INPUT typedef ptr FSCTL_OFFLOAD_READ_INPUT
      FSCTL_OFFLOAD_READ_OUTPUT struct
        Size_ DWORD ?
        Flags DWORD ?
        TransferLength QWORD ?
        Token BYTE 512 dup (?)
      FSCTL_OFFLOAD_READ_OUTPUT ends
      _FSCTL_OFFLOAD_READ_OUTPUT typedef FSCTL_OFFLOAD_READ_OUTPUT
      PFSCTL_OFFLOAD_READ_OUTPUT typedef ptr FSCTL_OFFLOAD_READ_OUTPUT
      OFFLOAD_READ_FLAG_ALL_ZERO_BEYOND_CURRENT_RANGE equ (1)
      ;======================== FSCTL_OFFLOAD_WRITE =============================
      ;  Structures used by FSCTL_OFFLOAD_WRITE operation
      FSCTL_OFFLOAD_WRITE_INPUT struct
        Size_ DWORD ?
        Flags DWORD ?
        FileOffset QWORD ?
        CopyLength QWORD ?
        TransferOffset QWORD ?
        Token BYTE 512 dup (?)
      FSCTL_OFFLOAD_WRITE_INPUT ends
      _FSCTL_OFFLOAD_WRITE_INPUT typedef FSCTL_OFFLOAD_WRITE_INPUT
      PFSCTL_OFFLOAD_WRITE_INPUT typedef ptr FSCTL_OFFLOAD_WRITE_INPUT
      FSCTL_OFFLOAD_WRITE_OUTPUT struct
        Size_ DWORD ?
        Flags DWORD ?
        LengthWritten QWORD ?
      FSCTL_OFFLOAD_WRITE_OUTPUT ends
      _FSCTL_OFFLOAD_WRITE_OUTPUT typedef FSCTL_OFFLOAD_WRITE_OUTPUT
      PFSCTL_OFFLOAD_WRITE_OUTPUT typedef ptr FSCTL_OFFLOAD_WRITE_OUTPUT
      ;======================== FSCTL_SET_PURGE_FAILURE_MODE ===========================
      ;  Structure definitions for supporting purge failure mode
      SET_PURGE_FAILURE_MODE_INPUT struct
        Flags DWORD ?
      SET_PURGE_FAILURE_MODE_INPUT ends
      _SET_PURGE_FAILURE_MODE_INPUT typedef SET_PURGE_FAILURE_MODE_INPUT
      PSET_PURGE_FAILURE_MODE_INPUT typedef ptr SET_PURGE_FAILURE_MODE_INPUT
      SET_PURGE_FAILURE_MODE_ENABLED equ 00000001h; Enable purge failure mode

      SET_PURGE_FAILURE_MODE_DISABLED equ 00000002h; Disable purge failure mode

      ;======================= FSCTL_REPAIR_COPIES =============================
      REPAIR_COPIES_INPUT struct
        Size_ DWORD ?
        ; sizeof(REPAIR_COPIES_INPUT)
        Flags DWORD ?
        ; Reserved (must be zero)
        FileOffset LARGE_INTEGER <>
        Length_ DWORD ?
        SourceCopy DWORD ?
        ; The copy number of the source copy.
        NumberOfRepairCopies DWORD ?
        ; The number of copies that will be repaired.
        RepairCopies DWORD ANYSIZE_ARRAY dup (?)
        ; The copy numbers of all the copies that will be repaired.
      REPAIR_COPIES_INPUT ends
      _REPAIR_COPIES_INPUT typedef REPAIR_COPIES_INPUT
      PREPAIR_COPIES_INPUT typedef ptr REPAIR_COPIES_INPUT
      REPAIR_COPIES_OUTPUT struct
        Size_ DWORD ?
        ; sizeof(REPAIR_COPIES_OUTPUT)
        Status DWORD ?
        ; Operational status
        ResumeFileOffset LARGE_INTEGER <>
        ; File Offset hint to use to resume repair operation skipping
        ; the range where errors were found (operational Status is non-success).
      REPAIR_COPIES_OUTPUT ends
      _REPAIR_COPIES_OUTPUT typedef REPAIR_COPIES_OUTPUT
      PREPAIR_COPIES_OUTPUT typedef ptr REPAIR_COPIES_OUTPUT
      ;======================= FSCTL_QUERY_FILE_REGIONS =============================
      ;  Structures used for querying for Various file region definitions
      ;  The initial values if for query VDL
      ;  Bit flags which may be OR'd together to define the usage of the given range
      ;      If the given bit is SET, then the specified region has that attribute
      ;      if the bit is NOT set, then the specified region does NOT have that attribute
      FILE_REGION_USAGE_VALID_CACHED_DATA equ 00000001h
      FILE_REGION_USAGE_VALID_NONCACHED_DATA equ 00000002h
      FILE_REGION_USAGE_OTHER_PAGE_ALIGNMENT equ 00000004h
      FILE_REGION_USAGE_LARGE_PAGE_ALIGNMENT equ 00000008h
      ifdef _WIN64
        FILE_REGION_USAGE_HUGE_PAGE_ALIGNMENT equ 00000010h
        FILE_REGION_USAGE_QUERY_ALIGNMENT equ <(FILE_REGION_USAGE_LARGE_PAGE_ALIGNMENT or FILE_REGION_USAGE_HUGE_PAGE_ALIGNMENT)>
      else
        FILE_REGION_USAGE_QUERY_ALIGNMENT equ <(FILE_REGION_USAGE_LARGE_PAGE_ALIGNMENT)>
      endif
      ; _WIN64
      FILE_REGION_INFO struct
        FileOffset SQWORD ?
        Length_ SQWORD ?
        Usage DWORD ?
        Reserved DWORD ?
      FILE_REGION_INFO ends
      _FILE_REGION_INFO typedef FILE_REGION_INFO
      PFILE_REGION_INFO typedef ptr FILE_REGION_INFO
      FILE_REGION_OUTPUT struct
        Flags DWORD ?
        ;none currently defined
        TotalRegionEntryCount DWORD ?
        ;count of total regions that could be returned
        RegionEntryCount DWORD ?
        ;count of regions that were returned
        Reserved DWORD ?
        ;for longlong alignment
        Region FILE_REGION_INFO 1 dup (<>)
      FILE_REGION_OUTPUT ends
      _FILE_REGION_OUTPUT typedef FILE_REGION_OUTPUT
      PFILE_REGION_OUTPUT typedef ptr FILE_REGION_OUTPUT
      ;  This is an optional buffer given on input to specify a region of the
      ;  file the caller is interested in
      FILE_REGION_INPUT struct
        FileOffset SQWORD ?
        Length_ SQWORD ?
        DesiredUsage DWORD ?
      FILE_REGION_INPUT ends
      _FILE_REGION_INPUT typedef FILE_REGION_INPUT
      PFILE_REGION_INPUT typedef ptr FILE_REGION_INPUT
      ;*_WIN32_WINNT >= _WIN32_WINNT_WIN8 *
    endif
    if (_WIN32_WINNT ge _WIN32_WINNT_WIN8)
      ;======================= FSCTL_WRITE_USN_REASON =============================
      ;  The list of valid USN reasons that can be set with this FSCTL.  Any bits
      ;  which are specified which are not defined by this mask are silently
      ;  stripped.  This operation will not be failed for sending undefined reasons
      ;  This operation is only supported from kernel mode.
      ;  The output of this operation is a USN structure.
      VALID_WRITE_USN_REASON_MASK equ <(USN_REASON_DATA_OVERWRITE or USN_REASON_CLOSE)>
      WRITE_USN_REASON_INPUT struct
        Flags DWORD ?
        ; Flags for this operation (none defined)
        UsnReasonToWrite DWORD ?
        ; A list of USN reasons to set
      WRITE_USN_REASON_INPUT ends
      _WRITE_USN_REASON_INPUT typedef WRITE_USN_REASON_INPUT
      PWRITE_USN_REASON_INPUT typedef ptr WRITE_USN_REASON_INPUT
      ;No Flags currently defined
      ;*_WIN32_WINNT >= _WIN32_WINNT_WIN8 *
    endif
    if (_WIN32_WINNT ge _WIN32_WINNT_WINBLUE)
      ; ****************** FSCTL_QUERY_STORAGE_CLASSES ***************************
      ;  The FILE_STORAGE_TIER is an identifier for the storage tier relative to the volume.
      ;  The storage tier ID for a particular volume has no relationship to the storage tier
      ;  ID with the same value on a different volume.
      ;  Note! The MediaType is used to indicate an uninitialized in-memory DSC structure.
      ;  Do not use values 0xfe or 0xff as media types.
      FILE_STORAGE_TIER_NAME_LENGTH equ (256)
      FILE_STORAGE_TIER_DESCRIPTION_LENGTH equ (512)
      ;  These flags *must* match those for _STORAGE_TIER as the file system does a
      ;  pass through.
      FILE_STORAGE_TIER_FLAG_NO_SEEK_PENALTY equ (00020000h)
      FILE_STORAGE_TIER_FLAG_WRITE_BACK_CACHE equ (00200000h)
      FILE_STORAGE_TIER_FLAG_READ_CACHE equ (00400000h)
      FILE_STORAGE_TIER_FLAG_PARITY equ (00800000h)
      FILE_STORAGE_TIER_FLAG_SMR equ (01000000h)
      FILE_STORAGE_TIER_MEDIA_TYPE typedef SDWORD
      FileStorageTierMediaTypeUnspecified equ 0
      FileStorageTierMediaTypeDisk equ 1
      FileStorageTierMediaTypeSsd equ 2
      FileStorageTierMediaTypeScm equ 4
      FileStorageTierMediaTypeMax equ 5
      _FILE_STORAGE_TIER_MEDIA_TYPE typedef FILE_STORAGE_TIER_MEDIA_TYPE
      PFILE_STORAGE_TIER_MEDIA_TYPE typedef ptr FILE_STORAGE_TIER_MEDIA_TYPE
      FILE_STORAGE_TIER_CLASS typedef SDWORD
      FileStorageTierClassUnspecified equ 0
      FileStorageTierClassCapacity equ 1
      FileStorageTierClassPerformance equ 2
      FileStorageTierClassMax equ 3
      _FILE_STORAGE_TIER_CLASS typedef FILE_STORAGE_TIER_CLASS
      PFILE_STORAGE_TIER_CLASS typedef ptr FILE_STORAGE_TIER_CLASS
      FILE_STORAGE_TIER struct
        ; Tier ID
        Id GUID <>
        ; Name for the tier
        Name_ WORD FILE_STORAGE_TIER_NAME_LENGTH dup (?)
        ; Note for the tier
        Description WORD FILE_STORAGE_TIER_NAME_LENGTH dup (?)
        ; Flags: FILE_STORAGE_TIER_FLAG_xxx
        Flags QWORD ?
        ; Provisioned capacity of the tier
        ProvisionedCapacity QWORD ?
        ; Media type of the tier
        MediaType FILE_STORAGE_TIER_MEDIA_TYPE ?
        ; Classification of the tier
        Class FILE_STORAGE_TIER_CLASS ?
      FILE_STORAGE_TIER ends
      _FILE_STORAGE_TIER typedef FILE_STORAGE_TIER
      PFILE_STORAGE_TIER typedef ptr FILE_STORAGE_TIER
      ;  This structure has the same fields as STORAGE_DEVICE_TIERING_DESCRIPTOR and
      ;  that structure reserves the upper WORD   of the Flags field for file system use.
      ;  We define the following possible values for the Flags field.
      QUERY_STORAGE_CLASSES_FLAGS_MEASURE_WRITE equ 80000000h
      QUERY_STORAGE_CLASSES_FLAGS_MEASURE_READ equ 40000000h
      QUERY_STORAGE_CLASSES_FLAGS_NO_DEFRAG_VOLUME equ 20000000h
      ;  The response returns a single structure of FSCTL_QUERY_STORAGE_CLASSES_OUTPUT
      ;  that has all the tiers for this volume.
      FSCTL_QUERY_STORAGE_CLASSES_OUTPUT struct
        ; Size of this structure serves
        ; as the version
        Version DWORD ?
        ; Size of  this structure  plus
        ; all the variable sized fields
        Size_ DWORD ?
        ; Flags
        Flags DWORD ?
        ; The total number of available tiers for this disk
        TotalNumberOfTiers DWORD ?
        ; The number of tiers that fit in the output
        NumberOfTiersReturned DWORD ?
        ; Detailed info on the storage tiers.
        Tiers FILE_STORAGE_TIER ANYSIZE_ARRAY dup (<>)
      FSCTL_QUERY_STORAGE_CLASSES_OUTPUT ends
      _FSCTL_QUERY_STORAGE_CLASSES_OUTPUT typedef FSCTL_QUERY_STORAGE_CLASSES_OUTPUT
      PFSCTL_QUERY_STORAGE_CLASSES_OUTPUT typedef ptr FSCTL_QUERY_STORAGE_CLASSES_OUTPUT
      FSCTL_QUERY_STORAGE_CLASSES_OUTPUT_VERSION equ <sizeof(FSCTL_QUERY_STORAGE_CLASSES_OUTPUT)>
      ;  Below are flags used by the Reparse union type within STREAM_INFORMATION_ENTRY.
      QUERY_FILE_LAYOUT_REPARSE_DATA_INVALID equ (0001h); invalid reparse data, corresponds to ERROR_INVALID_REPARSE_DATA

      QUERY_FILE_LAYOUT_REPARSE_TAG_INVALID equ (0002h); invalid reparse tag, corresponds to ERROR_REPARSE_TAG_INVALID

      ;  This structure lists information on the stream.
      ; (NTDDI_VERSION >= NTDDI_WIN10_VB)
      STREAM_INFORMATION_ENTRY struct
        ; Version of this struct. Current version is 1.
        Version DWORD ?
        ; Flags
        Flags DWORD ?
        ; The stream information varies by type of stream. We enclose
        ; the various types in a union.
        ; (NTDDI_VERSION >= NTDDI_WIN10_VB)
        union StreamInformation
          ;  Desired Storage Class
          struct DesiredStorageClass
            ;  Class
            Class FILE_STORAGE_TIER_CLASS ?
            ;  Flags
            Flags DWORD ?
          ends
          if (NTDDI_VERSION ge NTDDI_WIN10_VB)
            struct DataStream
              ;  Total Length of STREAM_INFORMATION_ENTRY structure.
              Length_ WORD ?
              ;  Flags (Reserved for future use)
              Flags WORD ?
              ;  Reserved.
              Reserved DWORD ?
              ;  The Vdl (Valid Data Length) of data stream.
              Vdl QWORD ?
            ends
            struct Reparse
              ;  Total Length of STREAM_INFORMATION_ENTRY structure.
              Length_ WORD ?
              ;  Flags
              Flags WORD ?
              ;  The size of Reparse data buffer.
              ReparseDataSize DWORD ?
              ;  Offset to reparse point data buffer (REPARSE_DATA_BUFFER or REPARSE_GUID_DATA_BUFFER).
              ReparseDataOffset DWORD ?
            ends
            struct Ea
              ;  Total Length of STREAM_INFORMATION_ENTRY structure.
              Length_ WORD ?
              ;  Flags (Reserved for future use)
              Flags WORD ?
              ;  The size of Ea.
              EaSize DWORD ?
              ;  Offset to EA (Extended Attributes) information buffer (FILE_FULL_EA_INFORMATION).
              EaInformationOffset DWORD ?
            ends
          endif
          ; (NTDDI_VERSION >= NTDDI_WIN10_VB)
        ends
      STREAM_INFORMATION_ENTRY ends
      _STREAM_INFORMATION_ENTRY typedef STREAM_INFORMATION_ENTRY
      PSTREAM_INFORMATION_ENTRY typedef ptr STREAM_INFORMATION_ENTRY
      ; ****************** FSCTL_QUERY_REGION_INFO *******************************
      ;  Input structure for FSCTL_QUERY_REGION_INFO.
      ;  This FSCTL returns the storage tier regions from the storage
      ;  stack for a particular volume.
      FSCTL_QUERY_REGION_INFO_INPUT struct
        Version DWORD ?
        ; The version of this structure.
        Size_ DWORD ?
        ; The size of this structure in bytes.
        Flags DWORD ?
        ; Reserved for future use.
        NumberOfTierIds DWORD ?
        ; Number of entries in TierIds, 0 for all for volume
        TierIds GUID ANYSIZE_ARRAY dup (<>)
        ; Storage tiers to return information for
      FSCTL_QUERY_REGION_INFO_INPUT ends
      _FSCTL_QUERY_REGION_INFO_INPUT typedef FSCTL_QUERY_REGION_INFO_INPUT
      PFSCTL_QUERY_REGION_INFO_INPUT typedef ptr FSCTL_QUERY_REGION_INFO_INPUT
      FSCTL_QUERY_REGION_INFO_INPUT_VERSION equ <sizeof(FSCTL_QUERY_REGION_INFO_INPUT)>
      ;  Structure that describes a single storage tier region.
      FILE_STORAGE_TIER_REGION struct
        TierId GUID <>
        ; Tier ID
        Offset_ QWORD ?
        ; offset of region in bytes
        Length_ QWORD ?
        ; length of region in bytes
      FILE_STORAGE_TIER_REGION ends
      _FILE_STORAGE_TIER_REGION typedef FILE_STORAGE_TIER_REGION
      PFILE_STORAGE_TIER_REGION typedef ptr FILE_STORAGE_TIER_REGION
      ;  Output structure for FSCTL_QUERY_REGION_INFO.
      ;  The FSCTL_QUERY_REGION_INFO response returns a single one of these that include
      ;  multiple FILE_STORAGE_TIER_REGION records, one for each region.
      FSCTL_QUERY_REGION_INFO_OUTPUT struct
        Version DWORD ?
        ; The version of this structure.
        Size_ DWORD ?
        ; The size of this structure in bytes.
        Flags DWORD ?
        ; Reserved for future use.
        Reserved DWORD ?
        ; Reserved for future use.
        Alignment QWORD ?
        ; in bytes, must align to slab boundary
        TotalNumberOfRegions DWORD ?
        ; Total number of available regions.
        NumberOfRegionsReturned DWORD ?
        ; Number of regions that fit in the output.
        Regions FILE_STORAGE_TIER_REGION ANYSIZE_ARRAY dup (<>)
        ; Detailed info on the regions.
      FSCTL_QUERY_REGION_INFO_OUTPUT ends
      _FSCTL_QUERY_REGION_INFO_OUTPUT typedef FSCTL_QUERY_REGION_INFO_OUTPUT
      PFSCTL_QUERY_REGION_INFO_OUTPUT typedef ptr FSCTL_QUERY_REGION_INFO_OUTPUT
      FSCTL_QUERY_REGION_INFO_OUTPUT_VERSION equ <sizeof(FSCTL_QUERY_REGION_INFO_OUTPUT)>
      ;  This structure contains the information for the Desired Storage Class attribute.
      FILE_DESIRED_STORAGE_CLASS_INFORMATION struct
        ; Class type of the tier
        Class FILE_STORAGE_TIER_CLASS ?
        ; Flags
        Flags DWORD ?
      FILE_DESIRED_STORAGE_CLASS_INFORMATION ends
      _FILE_DESIRED_STORAGE_CLASS_INFORMATION typedef FILE_DESIRED_STORAGE_CLASS_INFORMATION
      PFILE_DESIRED_STORAGE_CLASS_INFORMATION typedef ptr FILE_DESIRED_STORAGE_CLASS_INFORMATION
      ;  This structure has the same fields as STORAGE_DEVICE_TIERING_DESCRIPTOR and
      ;  that structure reserves the upper WORD   of the Flags field for file system use.
      ;  We define the following possible values for the Flags field.
      QUERY_STORAGE_CLASSES_FLAGS_MEASURE_WRITE equ 80000000h
      QUERY_STORAGE_CLASSES_FLAGS_MEASURE_READ equ 40000000h
      ;=============== FSCTL_DUPLICATE_EXTENTS_TO_FILE ====================
      DUPLICATE_EXTENTS_DATA struct
        FileHandle HANDLE ?
        SourceFileOffset LARGE_INTEGER <>
        TargetFileOffset LARGE_INTEGER <>
        ByteCount LARGE_INTEGER <>
      DUPLICATE_EXTENTS_DATA ends
      _DUPLICATE_EXTENTS_DATA typedef DUPLICATE_EXTENTS_DATA
      PDUPLICATE_EXTENTS_DATA typedef ptr DUPLICATE_EXTENTS_DATA
      if ((_WIN32_WINNT ge _WIN32_WINNT_WIN10_RS2) and Defined(_WIN64))
        ;  32/64 Bit thunking support structure
        DUPLICATE_EXTENTS_DATA32 struct
          FileHandle DWORD ?
          SourceFileOffset LARGE_INTEGER <>
          TargetFileOffset LARGE_INTEGER <>
          ByteCount LARGE_INTEGER <>
        DUPLICATE_EXTENTS_DATA32 ends
        _DUPLICATE_EXTENTS_DATA32 typedef DUPLICATE_EXTENTS_DATA32
        PDUPLICATE_EXTENTS_DATA32 typedef ptr DUPLICATE_EXTENTS_DATA32
        ;* ((_WIN32_WINNT >= _WIN32_WINNT_WIN10_RS2) && defined(_WIN64)) *
      endif
      ;* (_WIN32_WINNT >= _WIN32_WINNT_WINBLUE) *
    endif
    if (NTDDI_VERSION ge NTDDI_WIN10_RS3)
      ;=============== FSCTL_DUPLICATE_EXTENTS_TO_FILE_EX ==================
      DUPLICATE_EXTENTS_DATA_EX_SOURCE_ATOMIC equ 00000001h
      if (NTDDI_VERSION ge NTDDI_WIN10_VB)
        DUPLICATE_EXTENTS_DATA_EX_ASYNC equ 00000002h
      endif
      ; (NTDDI_VERSION >= NTDDI_WIN10_VB)
      DUPLICATE_EXTENTS_DATA_EX struct
        Size_ XWORD ?
        FileHandle HANDLE ?
        SourceFileOffset LARGE_INTEGER <>
        TargetFileOffset LARGE_INTEGER <>
        ByteCount LARGE_INTEGER <>
        Flags DWORD ?
      DUPLICATE_EXTENTS_DATA_EX ends
      _DUPLICATE_EXTENTS_DATA_EX typedef DUPLICATE_EXTENTS_DATA_EX
      PDUPLICATE_EXTENTS_DATA_EX typedef ptr DUPLICATE_EXTENTS_DATA_EX
      if ((NTDDI_VERSION ge NTDDI_WIN10_RS3) and Defined(_WIN64))
        ;  32/64 Bit thunking support structure
        DUPLICATE_EXTENTS_DATA_EX32 struct
          Size_ DWORD ?
          FileHandle DWORD ?
          SourceFileOffset LARGE_INTEGER <>
          TargetFileOffset LARGE_INTEGER <>
          ByteCount LARGE_INTEGER <>
          Flags DWORD ?
        DUPLICATE_EXTENTS_DATA_EX32 ends
        _DUPLICATE_EXTENTS_DATA_EX32 typedef DUPLICATE_EXTENTS_DATA_EX32
        PDUPLICATE_EXTENTS_DATA_EX32 typedef ptr DUPLICATE_EXTENTS_DATA_EX32
        ;* ((NTDDI_VERSION >= NTDDI_WIN10_RS3) && defined(_WIN64)) *
      endif
      ;* (NTDDI_VERSION >= NTDDI_WIN10_RS3) *
    endif
    if (NTDDI_VERSION ge NTDDI_WIN10_RS5)
      ;=============== FSCTL_QUERY_ASYNC_DUPLICATE_EXTENTS_STATUS ==================
      DUPLICATE_EXTENTS_STATE typedef SDWORD
      FileSnapStateInactive equ 0
      FileSnapStateSource equ 1
      FileSnapStateTarget equ 2
      _DUPLICATE_EXTENTS_STATE typedef DUPLICATE_EXTENTS_STATE
      PDUPLICATE_EXTENTS_STATE typedef ptr DUPLICATE_EXTENTS_STATE
      ASYNC_DUPLICATE_EXTENTS_STATUS struct
        Version DWORD ?
        State DUPLICATE_EXTENTS_STATE ?
        SourceFileOffset QWORD ?
        TargetFileOffset QWORD ?
        ByteCount QWORD ?
        BytesDuplicated QWORD ?
      ASYNC_DUPLICATE_EXTENTS_STATUS ends
      _ASYNC_DUPLICATE_EXTENTS_STATUS typedef ASYNC_DUPLICATE_EXTENTS_STATUS
      PASYNC_DUPLICATE_EXTENTS_STATUS typedef ptr ASYNC_DUPLICATE_EXTENTS_STATUS
      ASYNC_DUPLICATE_EXTENTS_STATUS_V1 equ <sizeof(ASYNC_DUPLICATE_EXTENTS_STATUS)>
    endif
    if (_WIN32_WINNT ge _WIN32_WINNT_WIN10_RS2)
      ;==================== FSCTL_QUERY_REFS_SMR_VOLUME_INFO =======================
      REFS_SMR_VOLUME_INFO_OUTPUT_VERSION_V0 equ 0
      REFS_SMR_VOLUME_INFO_OUTPUT_VERSION_V1 equ 1
      REFS_SMR_VOLUME_GC_STATE typedef SDWORD
      SmrGcStateInactive equ 0
      SmrGcStatePaused equ 1
      SmrGcStateActive equ 2
      SmrGcStateActiveFullSpeed equ 3
      _REFS_SMR_VOLUME_GC_STATE typedef REFS_SMR_VOLUME_GC_STATE
      PREFS_SMR_VOLUME_GC_STATE typedef ptr REFS_SMR_VOLUME_GC_STATE
      REFS_SMR_VOLUME_INFO_OUTPUT struct
        Version DWORD ?
        Flags DWORD ?
        SizeOfRandomlyWritableTier LARGE_INTEGER <>
        FreeSpaceInRandomlyWritableTier LARGE_INTEGER <>
        SizeofSMRTier LARGE_INTEGER <>
        FreeSpaceInSMRTier LARGE_INTEGER <>
        UsableFreeSpaceInSMRTier LARGE_INTEGER <>
        VolumeGcState REFS_SMR_VOLUME_GC_STATE ?
        VolumeGcLastStatus DWORD ?
        ;  Fields added in V1
        CurrentGcBandFillPercentage DWORD ?
        Unused QWORD 6 dup (?)
      REFS_SMR_VOLUME_INFO_OUTPUT ends
      _REFS_SMR_VOLUME_INFO_OUTPUT typedef REFS_SMR_VOLUME_INFO_OUTPUT
      PREFS_SMR_VOLUME_INFO_OUTPUT typedef ptr REFS_SMR_VOLUME_INFO_OUTPUT
      ;==================== FSCTL_SET_REFS_SMR_VOLUME_GC_PARAMETERS =======================
      REFS_SMR_VOLUME_GC_PARAMETERS_VERSION_V1 equ 1
      REFS_SMR_VOLUME_GC_ACTION typedef SDWORD
      SmrGcActionStart equ 1
      SmrGcActionStartFullSpeed equ 2
      SmrGcActionPause equ 3
      SmrGcActionStop equ 4
      _REFS_SMR_VOLUME_GC_ACTION typedef REFS_SMR_VOLUME_GC_ACTION
      PREFS_SMR_VOLUME_GC_ACTION typedef ptr REFS_SMR_VOLUME_GC_ACTION
      REFS_SMR_VOLUME_GC_METHOD typedef SDWORD
      SmrGcMethodCompaction equ 1
      SmrGcMethodCompression equ 2
      SmrGcMethodRotation equ 3
      _REFS_SMR_VOLUME_GC_METHOD typedef REFS_SMR_VOLUME_GC_METHOD
      PREFS_SMR_VOLUME_GC_METHOD typedef ptr REFS_SMR_VOLUME_GC_METHOD
      REFS_SMR_VOLUME_GC_PARAMETERS struct
        Version DWORD ?
        Flags DWORD ?
        Action REFS_SMR_VOLUME_GC_ACTION ?
        Method_ REFS_SMR_VOLUME_GC_METHOD ?
        IoGranularity DWORD ?
        CompressionFormat DWORD ?
        Unused QWORD 8 dup (?)
      REFS_SMR_VOLUME_GC_PARAMETERS ends
      _REFS_SMR_VOLUME_GC_PARAMETERS typedef REFS_SMR_VOLUME_GC_PARAMETERS
      PREFS_SMR_VOLUME_GC_PARAMETERS typedef ptr REFS_SMR_VOLUME_GC_PARAMETERS
      ;==================== STREAMS CONSTANTS =======================
      STREAMS_INVALID_ID equ (0)
      STREAMS_MAX_ID equ <(MAXWORD)>
      ;==================== FSCTL_STREAMS_QUERY_PARAMETERS =======================
      STREAMS_QUERY_PARAMETERS_OUTPUT_BUFFER struct
        OptimalWriteSize DWORD ?
        StreamGranularitySize DWORD ?
        StreamIdMin DWORD ?
        StreamIdMax DWORD ?
      STREAMS_QUERY_PARAMETERS_OUTPUT_BUFFER ends
      _STREAMS_QUERY_PARAMETERS_OUTPUT_BUFFER typedef STREAMS_QUERY_PARAMETERS_OUTPUT_BUFFER
      PSTREAMS_QUERY_PARAMETERS_OUTPUT_BUFFER typedef ptr STREAMS_QUERY_PARAMETERS_OUTPUT_BUFFER
      ;==================== FSCTL_STREAMS_ASSOCIATE_ID =======================
      STREAMS_ASSOCIATE_ID_CLEAR equ (1h)
      STREAMS_ASSOCIATE_ID_SET equ (2h)
      STREAMS_ASSOCIATE_ID_INPUT_BUFFER struct
        Flags DWORD ?
        StreamId DWORD ?
      STREAMS_ASSOCIATE_ID_INPUT_BUFFER ends
      _STREAMS_ASSOCIATE_ID_INPUT_BUFFER typedef STREAMS_ASSOCIATE_ID_INPUT_BUFFER
      PSTREAMS_ASSOCIATE_ID_INPUT_BUFFER typedef ptr STREAMS_ASSOCIATE_ID_INPUT_BUFFER
      ;==================== FSCTL_STREAMS_QUERY_ID =======================
      STREAMS_QUERY_ID_OUTPUT_BUFFER struct
        StreamId DWORD ?
      STREAMS_QUERY_ID_OUTPUT_BUFFER ends
      _STREAMS_QUERY_ID_OUTPUT_BUFFER typedef STREAMS_QUERY_ID_OUTPUT_BUFFER
      PSTREAMS_QUERY_ID_OUTPUT_BUFFER typedef ptr STREAMS_QUERY_ID_OUTPUT_BUFFER
    endif
    ; #if (_WIN32_WINNT >= _WIN32_WINNT_WIN10_RS2)
    if (_WIN32_WINNT ge _WIN32_WINNT_WIN10_RS3)
      ;=============== FSCTL_QUERY_BAD_RANGES ==================
      QUERY_BAD_RANGES_INPUT_RANGE struct
        ;  Starting offset of the range in bytes.
        StartOffset QWORD ?
        ;  Length of the range in bytes.
        LengthInBytes QWORD ?
      QUERY_BAD_RANGES_INPUT_RANGE ends
      _QUERY_BAD_RANGES_INPUT_RANGE typedef QUERY_BAD_RANGES_INPUT_RANGE
      PQUERY_BAD_RANGES_INPUT_RANGE typedef ptr QUERY_BAD_RANGES_INPUT_RANGE
      ;  Input buffer defining the ranges in the file to look for
      ;  bad ranges.  A NULL input buffer would lookup the entire
      ;  file.
      QUERY_BAD_RANGES_INPUT struct
        Flags DWORD ?
        ;  Number of ranges given, in the Ranges array.
        NumRanges DWORD ?
        ;  Array of ranges (<Offset,  Length> pairs)  to look for
        ;  bad ranges.  A range with MAXDWORDDWORD as LengthInBytes
        ;  would represent a range till end of the file allocation.
        ;  For that matter a range going beyond allocation size
        ;  will be capped at allocation size.
        Ranges QUERY_BAD_RANGES_INPUT_RANGE 1 dup (<>)
      QUERY_BAD_RANGES_INPUT ends
      _QUERY_BAD_RANGES_INPUT typedef QUERY_BAD_RANGES_INPUT
      PQUERY_BAD_RANGES_INPUT typedef ptr QUERY_BAD_RANGES_INPUT
      QUERY_BAD_RANGES_OUTPUT_RANGE struct
        ;  Flags, reserved for future.
        Flags DWORD ?
        Reserved DWORD ?
        ;  Starting offset of the range in bytes.
        StartOffset QWORD ?
        ;  Length of the range in bytes.
        LengthInBytes QWORD ?
      QUERY_BAD_RANGES_OUTPUT_RANGE ends
      _QUERY_BAD_RANGES_OUTPUT_RANGE typedef QUERY_BAD_RANGES_OUTPUT_RANGE
      PQUERY_BAD_RANGES_OUTPUT_RANGE typedef ptr QUERY_BAD_RANGES_OUTPUT_RANGE
      ;  Output buffer defining the bad ranges.
      QUERY_BAD_RANGES_OUTPUT struct
        Flags DWORD ?
        ;  Number of bad ranges populated in the Ranges
        ;  array.
        NumBadRanges DWORD ?
        ;  If the output buffer is not big enough to hold all the
        ;  bad ranges, the FSCTL would get STATUS_BUFFER_OVERFLOW
        ;  with as many bad ranges as  that can fit  in the given
        ;  output buffer and  NextOffsetToLookUp gives the offset
        ;  from which the user can requery the remaining bad ranges.
        NextOffsetToLookUp QWORD ?
        ;  Array of bad ranges (<Offset, Length> pairs) in the
        ;  ranges that user asked for.
        BadRanges QUERY_BAD_RANGES_OUTPUT_RANGE 1 dup (<>)
      QUERY_BAD_RANGES_OUTPUT ends
      _QUERY_BAD_RANGES_OUTPUT typedef QUERY_BAD_RANGES_OUTPUT
      PQUERY_BAD_RANGES_OUTPUT typedef ptr QUERY_BAD_RANGES_OUTPUT
      ;========= FSCTL_SET_DAX_ALLOC_ALIGNMENT_HINT =========
      ;  Once this FSCTL is issued for a file, the following
      ;  allocations to the file will be examined to see if
      ;  the given offset is being allocated and if so the
      ;  allocation will be placed such that the physical
      ;  address corresponding to that allocation is aligned
      ;  to the given AlignmentValue, if we have free space
      ;  available at aligned regions.
      ;  To reset the alignment constraint you can issue this
      ;  FSCTL with AlignmentValue of 1 i.e. AlignmentShift
      ;  as 0.
      SET_DAX_ALLOC_ALIGNMENT_HINT_INPUT struct
        Flags DWORD ?
        ;  The block size to align the given offset of the file.
        ;  The file is allocated such that the physical address
        ;  corresponding to the file is aligned to this block
        ;  size.  The actual alignment value is given by:
        ;    AlignmentValue = (1 << AlignmentShift);
        AlignmentShift DWORD ?
        ;  Offset in file that should be aligned to the given
        ;  AlignmentValue.  This should be cluster aligned.
        ;  NOTE: MM supports huge page only if the file offset
        ;  and the physical address are 1gb aligned.
        FileOffsetToAlign QWORD ?
        if (_WIN32_WINNT ge _WIN32_WINNT_WIN10_RS4)
          ;  If DAX_ALLOC_ALIGNMENT_FLAG_FALLBACK_SPECIFIED is present in
          ;  Flags, this field specifies a fallback block size to align
          ;  the given offset of the file whenever allocation satisfying
          ;  AlignmentShift could not be found.
          FallbackAlignmentShift DWORD ?
          ;* (_WIN32_WINNT >= _WIN32_WINNT_WIN10_RS4) *
        endif
      SET_DAX_ALLOC_ALIGNMENT_HINT_INPUT ends
      _SET_DAX_ALLOC_ALIGNMENT_HINT_INPUT typedef SET_DAX_ALLOC_ALIGNMENT_HINT_INPUT
      PSET_DAX_ALLOC_ALIGNMENT_HINT_INPUT typedef ptr SET_DAX_ALLOC_ALIGNMENT_HINT_INPUT
      if (_WIN32_WINNT ge _WIN32_WINNT_WIN10_RS4)
        ;  MANDATORY - If allocation satisfying AlignmentShift (or at least
        ;     FallbackAlignmentShift if specified) cannot be found, then fail
        ;     the file system operation (e.g. extending the file).
        DAX_ALLOC_ALIGNMENT_FLAG_MANDATORY equ (00000001h)
        ;  FALLBACK_SPECIFIED - Indicates that the FallbackAlignmentShift field
        ;      is present in the input structure and indicates a fallback
        ;      alignment if the optimal alignment isn't available.
        DAX_ALLOC_ALIGNMENT_FLAG_FALLBACK_SPECIFIED equ (00000002h)
        ;* (_WIN32_WINNT >= _WIN32_WINNT_WIN10_RS4) *
      endif
      ;========= FSCTL_VIRTUAL_STORAGE_SET_BEHAVIOR =========
      ;  Configures file system-specific behaviors for files
      ;  used as backing stored for virtual storage devices.
      VIRTUAL_STORAGE_BEHAVIOR_CODE typedef SDWORD
      VirtualStorageBehaviorUndefined equ 0
      VirtualStorageBehaviorCacheWriteThrough equ 1
      VirtualStorageBehaviorCacheWriteBack equ 2
      VirtualStorageBehaviorStopIoProcessing equ 3
      VirtualStorageBehaviorRestartIoProcessing equ 4
      _VIRTUAL_STORAGE_BEHAVIOR_CODE typedef VIRTUAL_STORAGE_BEHAVIOR_CODE
      PVIRTUAL_STORAGE_BEHAVIOR_CODE typedef ptr VIRTUAL_STORAGE_BEHAVIOR_CODE
      VIRTUAL_STORAGE_SET_BEHAVIOR_INPUT struct
        Size_ DWORD ?
        BehaviorCode VIRTUAL_STORAGE_BEHAVIOR_CODE ?
      VIRTUAL_STORAGE_SET_BEHAVIOR_INPUT ends
      _VIRTUAL_STORAGE_SET_BEHAVIOR_INPUT typedef VIRTUAL_STORAGE_SET_BEHAVIOR_INPUT
      PVIRTUAL_STORAGE_SET_BEHAVIOR_INPUT typedef ptr VIRTUAL_STORAGE_SET_BEHAVIOR_INPUT
      ; EFS DPL key availability data structure for FSCTL_ENCRYPTION_KEY_CONTROL
      ENCRYPTION_KEY_CTRL_INPUT struct
        HeaderSize DWORD ?
        ; Structure header size, usable for structure versioning.
        StructureSize DWORD ?
        ; Full structure size.
        KeyOffset WORD ?
        ; Byte offset of the key blob relative to the start of this structure.
        ; Could be 0 if key blob is not passed.
        KeySize WORD ?
        ; Size of the key blob.
        ; Could be 0 if key blob is not passed.
        DplLock DWORD ?
        ; DPL lock/unlock indicator: 1 means lock, 0 means unlock.
        DplUserId QWORD ?
        ; DPL user runtime ID for who this control is issued.
        DplCredentialId QWORD ?
        ; DPL credential runtime ID which is being impacted.
      ENCRYPTION_KEY_CTRL_INPUT ends
      _ENCRYPTION_KEY_CTRL_INPUT typedef ENCRYPTION_KEY_CTRL_INPUT
      PENCRYPTION_KEY_CTRL_INPUT typedef ptr ENCRYPTION_KEY_CTRL_INPUT
      ;* (_WIN32_WINNT >= _WIN32_WINNT_WIN10_RS3) *
    endif
    if (_WIN32_WINNT ge _WIN32_WINNT_WIN7)
      ; Generic fsctl headers which can be sent to the driver.
      WOF_CURRENT_VERSION equ (00000001h)
      WOF_PROVIDER_WIM equ (00000001h)
      WOF_PROVIDER_FILE equ (00000002h)
      WOF_PROVIDER_CLOUD equ (00000003h)
      WOF_EXTERNAL_INFO struct
        Version DWORD ?
        Provider DWORD ?
      WOF_EXTERNAL_INFO ends
      _WOF_EXTERNAL_INFO typedef WOF_EXTERNAL_INFO
      PWOF_EXTERNAL_INFO typedef ptr WOF_EXTERNAL_INFO
      WOF_EXTERNAL_FILE_ID struct
        FileId FILE_ID_128 <>
      WOF_EXTERNAL_FILE_ID ends
      _WOF_EXTERNAL_FILE_ID typedef WOF_EXTERNAL_FILE_ID
      PWOF_EXTERNAL_FILE_ID typedef ptr WOF_EXTERNAL_FILE_ID
      WOF_VERSION_INFO struct
        WofVersion DWORD ?
      WOF_VERSION_INFO ends
      _WOF_VERSION_INFO typedef WOF_VERSION_INFO
      PWOF_VERSION_INFO typedef ptr WOF_VERSION_INFO
      ; Structures for WIM provider specific fsctl's.
      ifndef WIM_PROVIDER_HASH_SIZE
        WIM_PROVIDER_HASH_SIZE equ 20
      endif
      WIM_PROVIDER_CURRENT_VERSION equ (00000001h)
      WIM_PROVIDER_EXTERNAL_FLAG_NOT_ACTIVE equ (00000001h)
      WIM_PROVIDER_EXTERNAL_FLAG_SUSPENDED equ (00000002h)
      WIM_PROVIDER_EXTERNAL_INFO struct
        Version DWORD ?
        Flags DWORD ?
        DataSourceId LARGE_INTEGER <>
        ResourceHash BYTE WIM_PROVIDER_HASH_SIZE dup (?)
      WIM_PROVIDER_EXTERNAL_INFO ends
      _WIM_PROVIDER_EXTERNAL_INFO typedef WIM_PROVIDER_EXTERNAL_INFO
      PWIM_PROVIDER_EXTERNAL_INFO typedef ptr WIM_PROVIDER_EXTERNAL_INFO
      ;  WimType specifies a set of flags corresponding to the type of WIM.
      ;  WIM_BOOT_OS_WIM means the wim contains Windows system files.
      ;  WIM_BOOT_NOT_OS_WIM means the wim contains 3rd party files or data files.
      ;  Do not use WIM_BOOT_OS_WIM for data that should be preserved on
      ;  system upgrade.
      WIM_BOOT_OS_WIM equ (00000001h)
      WIM_BOOT_NOT_OS_WIM equ (00000000h)
      WIM_PROVIDER_ADD_OVERLAY_INPUT struct
        WimType DWORD ?
        WimIndex DWORD ?
        WimFileNameOffset DWORD ?
        WimFileNameLength DWORD ?
      WIM_PROVIDER_ADD_OVERLAY_INPUT ends
      _WIM_PROVIDER_ADD_OVERLAY_INPUT typedef WIM_PROVIDER_ADD_OVERLAY_INPUT
      PWIM_PROVIDER_ADD_OVERLAY_INPUT typedef ptr WIM_PROVIDER_ADD_OVERLAY_INPUT
      WIM_PROVIDER_UPDATE_OVERLAY_INPUT struct
        DataSourceId LARGE_INTEGER <>
        WimFileNameOffset DWORD ?
        WimFileNameLength DWORD ?
      WIM_PROVIDER_UPDATE_OVERLAY_INPUT ends
      _WIM_PROVIDER_UPDATE_OVERLAY_INPUT typedef WIM_PROVIDER_UPDATE_OVERLAY_INPUT
      PWIM_PROVIDER_UPDATE_OVERLAY_INPUT typedef ptr WIM_PROVIDER_UPDATE_OVERLAY_INPUT
      WIM_PROVIDER_REMOVE_OVERLAY_INPUT struct
        DataSourceId LARGE_INTEGER <>
      WIM_PROVIDER_REMOVE_OVERLAY_INPUT ends
      _WIM_PROVIDER_REMOVE_OVERLAY_INPUT typedef WIM_PROVIDER_REMOVE_OVERLAY_INPUT
      PWIM_PROVIDER_REMOVE_OVERLAY_INPUT typedef ptr WIM_PROVIDER_REMOVE_OVERLAY_INPUT
      WIM_PROVIDER_SUSPEND_OVERLAY_INPUT struct
        DataSourceId LARGE_INTEGER <>
      WIM_PROVIDER_SUSPEND_OVERLAY_INPUT ends
      _WIM_PROVIDER_SUSPEND_OVERLAY_INPUT typedef WIM_PROVIDER_SUSPEND_OVERLAY_INPUT
      PWIM_PROVIDER_SUSPEND_OVERLAY_INPUT typedef ptr WIM_PROVIDER_SUSPEND_OVERLAY_INPUT
      WIM_PROVIDER_OVERLAY_ENTRY struct
        NextEntryOffset DWORD ?
        DataSourceId LARGE_INTEGER <>
        WimGuid GUID <>
        WimFileNameOffset DWORD ?
        WimType DWORD ?
        WimIndex DWORD ?
        Flags DWORD ?
      WIM_PROVIDER_OVERLAY_ENTRY ends
      _WIM_PROVIDER_OVERLAY_ENTRY typedef WIM_PROVIDER_OVERLAY_ENTRY
      PWIM_PROVIDER_OVERLAY_ENTRY typedef ptr WIM_PROVIDER_OVERLAY_ENTRY
    endif
    if (_WIN32_WINNT ge _WIN32_WINNT_WIN7)
      ; Structures for WOF File provider specific fsctl's.
      FILE_PROVIDER_CURRENT_VERSION equ (00000001h)
      FILE_PROVIDER_SINGLE_FILE equ (00000001h)
      FILE_PROVIDER_COMPRESSION_XPRESS4K equ (00000000h)
      FILE_PROVIDER_COMPRESSION_LZX equ (00000001h)
      FILE_PROVIDER_COMPRESSION_XPRESS8K equ (00000002h)
      FILE_PROVIDER_COMPRESSION_XPRESS16K equ (00000003h)
      FILE_PROVIDER_COMPRESSION_MAXIMUM equ (00000004h)
      FILE_PROVIDER_FLAG_COMPRESS_ON_WRITE equ (00000001h)
      FILE_PROVIDER_EXTERNAL_INFO_V0 struct
        Version DWORD ?
        Algorithm DWORD ?
      FILE_PROVIDER_EXTERNAL_INFO_V0 ends
      _FILE_PROVIDER_EXTERNAL_INFO_V0 typedef FILE_PROVIDER_EXTERNAL_INFO_V0
      PFILE_PROVIDER_EXTERNAL_INFO_V0 typedef ptr FILE_PROVIDER_EXTERNAL_INFO_V0
      FILE_PROVIDER_EXTERNAL_INFO_V1 struct
        Version DWORD ?
        Algorithm DWORD ?
        Flags DWORD ?
      FILE_PROVIDER_EXTERNAL_INFO_V1 ends
      _FILE_PROVIDER_EXTERNAL_INFO_V1 typedef FILE_PROVIDER_EXTERNAL_INFO_V1
      PFILE_PROVIDER_EXTERNAL_INFO_V1 typedef ptr FILE_PROVIDER_EXTERNAL_INFO_V1
      FILE_PROVIDER_EXTERNAL_INFO typedef FILE_PROVIDER_EXTERNAL_INFO_V1
      PFILE_PROVIDER_EXTERNAL_INFO typedef PFILE_PROVIDER_EXTERNAL_INFO_V1
    endif
    ;  (_WIN32_WINNT >= _WIN32_WINNT_WIN7)
    if (_WIN32_WINNT ge _WIN32_WINNT_WINTHRESHOLD)
      CONTAINER_VOLUME_STATE struct
        Flags DWORD ?
      CONTAINER_VOLUME_STATE ends
      _CONTAINER_VOLUME_STATE typedef CONTAINER_VOLUME_STATE
      PCONTAINER_VOLUME_STATE typedef ptr CONTAINER_VOLUME_STATE
      CONTAINER_VOLUME_STATE_HOSTING_CONTAINER equ (00000001h)
      CONTAINER_ROOT_INFO_INPUT struct
        Flags DWORD ?
      CONTAINER_ROOT_INFO_INPUT ends
      _CONTAINER_ROOT_INFO_INPUT typedef CONTAINER_ROOT_INFO_INPUT
      PCONTAINER_ROOT_INFO_INPUT typedef ptr CONTAINER_ROOT_INFO_INPUT
      CONTAINER_ROOT_INFO_OUTPUT struct
        ContainerRootIdLength WORD ?
        ContainerRootId BYTE ANYSIZE_ARRAY dup (?)
      CONTAINER_ROOT_INFO_OUTPUT ends
      _CONTAINER_ROOT_INFO_OUTPUT typedef CONTAINER_ROOT_INFO_OUTPUT
      PCONTAINER_ROOT_INFO_OUTPUT typedef ptr CONTAINER_ROOT_INFO_OUTPUT
      CONTAINER_ROOT_INFO_FLAG_SCRATCH_ROOT equ (00000001h)
      CONTAINER_ROOT_INFO_FLAG_LAYER_ROOT equ (00000002h)
      CONTAINER_ROOT_INFO_FLAG_VIRTUALIZATION_ROOT equ (00000004h)
      CONTAINER_ROOT_INFO_FLAG_VIRTUALIZATION_TARGET_ROOT equ (00000008h)
      CONTAINER_ROOT_INFO_FLAG_VIRTUALIZATION_EXCEPTION_ROOT equ (00000010h)
      CONTAINER_ROOT_INFO_FLAG_BIND_ROOT equ (00000020h)
      CONTAINER_ROOT_INFO_FLAG_BIND_TARGET_ROOT equ (00000040h)
      CONTAINER_ROOT_INFO_FLAG_BIND_EXCEPTION_ROOT equ (00000080h)
      CONTAINER_ROOT_INFO_FLAG_BIND_DO_NOT_MAP_NAME equ (00000100h)
      CONTAINER_ROOT_INFO_FLAG_UNION_LAYER_ROOT equ (00000200h)
      CONTAINER_ROOT_INFO_VALID_FLAGS equ (000003ffh)
    endif
    if (_WIN32_WINNT ge _WIN32_WINNT_WIN10_RS1)
      VIRTUALIZATION_INSTANCE_INFO_INPUT struct
        NumberOfWorkerThreads DWORD ?
        Flags DWORD ?
      VIRTUALIZATION_INSTANCE_INFO_INPUT ends
      _VIRTUALIZATION_INSTANCE_INFO_INPUT typedef VIRTUALIZATION_INSTANCE_INFO_INPUT
      PVIRTUALIZATION_INSTANCE_INFO_INPUT typedef ptr VIRTUALIZATION_INSTANCE_INFO_INPUT
      PROJFS_PROTOCOL_VERSION equ 3
      VIRTUALIZATION_INSTANCE_INFO_INPUT_EX struct
        HeaderSize WORD ?
        ; sizeof(VIRTUALIZATION_INSTANCE_INFO_INPUT_EX)
        Flags DWORD ?
        NotificationInfoSize DWORD ?
        ; Total Size of the NotificationInfo Buffer.
        NotificationInfoOffset WORD ?
        ; Offset from beginning of this struct to the NotificationInfo Buffer.
        ProviderMajorVersion WORD ?
        ; This should be set to PROJFS_PROTOCOL_VERSION.
      VIRTUALIZATION_INSTANCE_INFO_INPUT_EX ends
      _VIRTUALIZATION_INSTANCE_INFO_INPUT_EX typedef VIRTUALIZATION_INSTANCE_INFO_INPUT_EX
      PVIRTUALIZATION_INSTANCE_INFO_INPUT_EX typedef ptr VIRTUALIZATION_INSTANCE_INFO_INPUT_EX
      VIRTUALIZATION_INSTANCE_INFO_OUTPUT struct
        VirtualizationInstanceID GUID <>
      VIRTUALIZATION_INSTANCE_INFO_OUTPUT ends
      _VIRTUALIZATION_INSTANCE_INFO_OUTPUT typedef VIRTUALIZATION_INSTANCE_INFO_OUTPUT
      PVIRTUALIZATION_INSTANCE_INFO_OUTPUT typedef ptr VIRTUALIZATION_INSTANCE_INFO_OUTPUT
      ;  Structures for FSCTL_GET_FILTER_FILE_IDENTIFIER.
      GET_FILTER_FILE_IDENTIFIER_INPUT struct
        AltitudeLength WORD ?
        Altitude WORD ANYSIZE_ARRAY dup (?)
      GET_FILTER_FILE_IDENTIFIER_INPUT ends
      _GET_FILTER_FILE_IDENTIFIER_INPUT typedef GET_FILTER_FILE_IDENTIFIER_INPUT
      PGET_FILTER_FILE_IDENTIFIER_INPUT typedef ptr GET_FILTER_FILE_IDENTIFIER_INPUT
      GET_FILTER_FILE_IDENTIFIER_OUTPUT struct
        FilterFileIdentifierLength WORD ?
        FilterFileIdentifier BYTE ANYSIZE_ARRAY dup (?)
      GET_FILTER_FILE_IDENTIFIER_OUTPUT ends
      _GET_FILTER_FILE_IDENTIFIER_OUTPUT typedef GET_FILTER_FILE_IDENTIFIER_OUTPUT
      PGET_FILTER_FILE_IDENTIFIER_OUTPUT typedef ptr GET_FILTER_FILE_IDENTIFIER_OUTPUT
    endif
    ;  (_WIN32_WINNT >= _WIN32_WINNT_WIN10_RS1)
    ; end_ntosifs
    ; begin_ntifs begin_winioctl
    if (NTDDI_VERSION ge NTDDI_WIN10_CO)
      ; nameless struct/unions
      ;============== FSCTL_MANAGE_BYPASS_IO ================
      ;  This FSCTL is used to control BypassIO operations on a given file in the
      ;  filter and file system stacks
      ;  Defines the various operations supported by the BypassIO FSCTL
      FS_BPIO_OPERATIONS typedef SDWORD
      ;  This request can come from user or kernel mode.  This is a request to enable
      ;  BypassIO for the given file which means a driver may not see all reads/writes
      ;  for that file.
      ;  On the pre-operation, if a driver can support BypassIO for the given file
      ;  it should forward the request down the stack.
      ;  On the pre-operation if a driver CAN NOT support BypassIO for the given
      ;  file they should complete the FSCTL with STATUS_SUCCESS and should call
      ;  FltVetoBypassIo to update the FS_BPIO_OUTPUT structure with appropriate
      ;  OpStatus, FailingDriverName and FailureReason reasons.
      ;  During the post-operation they can see if all drivers below them are
      ;  capable of supporting BypassIO.  If yes, the driver should preserve any
      ;  needed state for the file and continue completion processing. It is the
      ;  filter and file systems responsibility to maintain state to properly
      ;  handle requests that may not be compatible with the BypassIO enabled state.
      ;  During the post-operation processing if a driver determines they can no
      ;  longer support BypassIO, they can  call FltVetoBypassIo to inform the
      ;  stack below them that BypassIO is now disabled.  They should set appropriate
      ;  OpStatus, FailingDriverName and FailureReason reasons as to why it can not
      ;  be supported.
      FS_BPIO_OP_ENABLE equ 1
      ;  This request can come from user or kernel mode.  This informs filters and
      ;  file systems that BypassIO is being disabled on this file.  It allows a
      ;  driver to cleanup any associated BypassIO state.
      ;  If a driver has previously allowed BypassIO to be enabled on this file and
      ;  now needs to turn off BypassIO support for a file (a good example is an encryption
      ;  driver wanting to encrypt this file).  They should send this FSCTL to the top
      ;  of the file system stack using the associated handle.
      ;  This can be received by a driver that currently does not have BypassIO enabled,
      ;  it should be ignored.  If sent on a file that currently does not have BypassIO
      ;  enabled, it should be ignored.
      ;  This operation should not be failed.
      FS_BPIO_OP_DISABLE equ 2
      ;  This request can come from user or kernel mode.  This is an informational
      ;  request to see if BypassIO can be enabled for the given file.  This
      ;  should be processed the same as an ENABLE operation with the appropriate
      ;  fields in the FS_BPIO_OUTPUT structure filled out.  The only difference
      ;  is that the driver does not enter the ENABLE state.
      FS_BPIO_OP_QUERY equ 3
      ;  This request can come from user or kernel mode.  This is a request to PAUSE
      ;  BypassIO on this volume/storage stack.  All active BypassIO enabled files will
      ;  stop doing storage stack level BypassIO operations.  This can be sent on a
      ;  volume handle or any file handle for the given volume.
      ;  Bitlocker is an example of a component that would use this when it needs to
      ;  enable encryption on a volume.  It is fine to send this even if BypassIO is
      ;  not currently enabled on any files on the volume
      ;  This operation will not return until all active BypassIO files have transitioned
      ;  to normal operating mode and all outstanding Bypass IO's have completed.
      ;  This operation should not be failed.
      FS_BPIO_OP_VOLUME_STACK_PAUSE equ 4
      ;  This request can come from user or kernel mode.  This should be sent by a driver
      ;  which has previously PAUSED BypassIO on a volume/storage stack and can
      ;  now allow the stack to continue doing BypassIO.
      ;  Volsnap is an example of a component that would PAUSE BypassIO (via
      ;  FS_BPIO_VOLUME_STACK_PAUSE) when a snapshot is created and would send this when
      ;  the snapshot is deleted.
      ;  This operation should not be failed.
      FS_BPIO_OP_VOLUME_STACK_RESUME equ 5
      ;  This request can come from user or kernel mode.  This is a request to PAUSE
      ;  BypassIO on this stream.  All active BypassIO enabled files will stop doing
      ;  BypassIO operations.  It is fine to send this even if BypassIO is
      ;  not currently enabled on any files on the stream
      ;  This operation will not return until all active BypassIO's on this stream
      ;  have completed and no new BypassIO operations are being generated.
      ;  This operation should not be failed.
      FS_BPIO_OP_STREAM_PAUSE equ 6
      ;  This request can come from user or kernel mode.  This should be sent by a
      ;  filter which has previously PAUSED BypassIO on this stream and can now
      ;  allow them to be used again.
      ;  This operaiton should not be failed by filters.  The file system will
      ;  determine if Bypass can be resumed on the stream by issuing a FS_BPIO_OP_QUERY
      ;  to the top of the filter stack.
      FS_BPIO_OP_STREAM_RESUME equ 7
      ;  This request can come from user or kernel mode.  This returns information
      ;  about the BypassIO state of the volume.
      FS_BPIO_OP_GET_INFO equ 8
      ;  All valid operations will be less than this value
      FS_BPIO_OP_MAX_OPERATION equ 9
      _FS_BPIO_OPERATIONS typedef FS_BPIO_OPERATIONS

      ;  Defines the BypassIO INPUT flags
      FS_BPIO_INFLAGS typedef SDWORD
      FSBPIO_INFL_None equ 0
      ;  Only applies to QUERY operations. When set it will suppress sending the
      ;  BypassIO IOCTL to the storage stack.  It will return results based only
      ;  on the filter stack.  This has no effect on ENABLE operations.
      FSBPIO_INFL_SKIP_STORAGE_STACK_QUERY equ 1
      _FS_BPIO_INFLAGS typedef FS_BPIO_INFLAGS

      DEFINE_ENUM_FLAG_OPERATORS(FS_BPIO_INFLAGS)
      ;  Defines the INPUT structure for FSCTL_MANAGE_BYPASS_IO
      FS_BPIO_INPUT struct
        ;  The BypassIO operation being requested
        Operation FS_BPIO_OPERATIONS ?
        ;  Input flags for this operation.
        InFlags FS_BPIO_INFLAGS ?
        ;  Reserved fields for future improvements, these fields MUST be set to zero
        Reserved1 QWORD ?
        Reserved2 QWORD ?
      FS_BPIO_INPUT ends
      _FS_BPIO_INPUT typedef FS_BPIO_INPUT
      PFS_BPIO_INPUT typedef ptr FS_BPIO_INPUT
      ;  Defines the BypassIO OUTPUT flags
      FS_BPIO_OUTFLAGS typedef SDWORD
      FSBPIO_OUTFL_None equ 0
      ;  When set it means BypassIO has been temporarily PAUSED for this volume
      FSBPIO_OUTFL_VOLUME_STACK_BYPASS_PAUSED equ 00000001h
      ;  When set it means BypassIO has been temporarily PAUSED for this Stream
      FSBPIO_OUTFL_STREAM_BYPASS_PAUSED equ 00000002h
      ;  When set, a minifilter has attached to this volume whose supported
      ;  features state says it does not suport BypassIO.  All BypassIO is
      ;  blocked on this volume.
      FSBPIO_OUTFL_FILTER_ATTACH_BLOCKED equ 00000004h
      ;  When set, the storage driver for this volume is BypassIO compatible.
      ;  This flag is only defined for ENABLE/QUERY/GETINFO operations
      FSBPIO_OUTFL_COMPATIBLE_STORAGE_DRIVER equ 00000008h
      _FS_BPIO_OUTFLAGS typedef FS_BPIO_OUTFLAGS

      DEFINE_ENUM_FLAG_OPERATORS(FS_BPIO_OUTFLAGS)
      ;  This structure defines operation specific outputs for both the ENABLE
      ;  and QUERY operations
      FS_BPIO_RESULTS struct
        ;  A status code that will be available to users which identifies WHY
        ;  the specified driver can't support BypassIO for this file.  This should
        ;  only be set by the first driver to fail the enable/acquire request.
        OpStatus DWORD ?
        ;  Receives the name of the driver that failed the request.  For diagnostic
        ;  reasons it is required that drivers store their name when failing an
        ;  ENABLE/ASK requests.  The name should match the actual name of the driver
        ;  used by the system with extension.  Ex: "ntfs.sys".
        ;  FailingDriversNameLen contains the length of the string in CHARACTERS.
        ;  No one should assume the string is NULL terminated.
        FailingDriverNameLen WORD ?
        FailingDriverName WORD 32 dup (?)
        ;  Receives a reasonable description of why the driver can not support the
        ;  ENABLE/QUERY request.  This string is used for diagnostic reasons and should
        ;  identify the WHY.
        ;  This string should be in English and does not need to be localized.
        ;  FailureReasonLen contains the length of the string in CHARACTERS.
        ;  No one should assume the strings is NULL terminated.
        FailureReasonLen WORD ?
        FailureReason WORD 128 dup (?)
      FS_BPIO_RESULTS ends
      _FS_BPIO_RESULTS typedef FS_BPIO_RESULTS
      PFS_BPIO_RESULTS typedef ptr FS_BPIO_RESULTS
      ;  This structure defines operation specific outputs for both the ENABLE
      ;  and QUERY operations
      FS_BPIO_INFO struct
        ;  Count of how many BypassIO enabled files are currently open
        ActiveBypassIoCount DWORD ?
        ;  Returns the name of the storage driver for this volume
        StorageDriverNameLen WORD ?
        StorageDriverName WORD 32 dup (?)
      FS_BPIO_INFO ends
      _FS_BPIO_INFO typedef FS_BPIO_INFO
      PFS_BPIO_INFO typedef ptr FS_BPIO_INFO
      ;  Defines the variable sized OUTPUT structure for FSCTL_MANAGE_BYPASS_IO
      FS_BPIO_OUTPUT struct
        ;  The BypassIO operation being requested.  This should be set to the
        ;  same value passed in the INPUT structure
        Operation FS_BPIO_OPERATIONS ?
        ;  Output flags for this operation.
        OutFlags FS_BPIO_OUTFLAGS ?
        ;  Reserved fields used for future improvements
        Reserved1 QWORD ?
        Reserved2 QWORD ?
        ;  Operation specific outputs
        union
          Enable FS_BPIO_RESULTS <>
          Query FS_BPIO_RESULTS <>
          VolumeStackResume FS_BPIO_RESULTS <>
          StreamResume FS_BPIO_RESULTS <>
          GetInfo FS_BPIO_INFO <>
        ends
      FS_BPIO_OUTPUT ends
      _FS_BPIO_OUTPUT typedef FS_BPIO_OUTPUT
      PFS_BPIO_OUTPUT typedef ptr FS_BPIO_OUTPUT
      ;  Structure size based on operations type
      FS_BPIO_OUTPUT_ENABLE_SIZE equ <(RTL_SIZEOF_THROUGH_FIELD(FS_BPIO_OUTPUT, Enable))>
      FS_BPIO_OUTPUT_QUERY_SIZE equ <(RTL_SIZEOF_THROUGH_FIELD(FS_BPIO_OUTPUT, Query))>
      FS_BPIO_OUTPUT_DISABLE_SIZE equ <(FIELD_OFFSET (FS_BPIO_OUTPUT, Enable))>
      FS_BPIO_OUTPUT_VOLUME_STACK_PAUSE_SIZE equ <(FIELD_OFFSET (FS_BPIO_OUTPUT, Enable))>
      FS_BPIO_OUTPUT_VOLUME_STACK_RESUME_SIZE equ <(RTL_SIZEOF_THROUGH_FIELD(FS_BPIO_OUTPUT, VolumeStackResume))>
      FS_BPIO_OUTPUT_STREAM_PAUSE_SIZE equ <(FIELD_OFFSET (FS_BPIO_OUTPUT, Enable))>
      FS_BPIO_OUTPUT_STREAM_RESUME_SIZE equ <(RTL_SIZEOF_THROUGH_FIELD(FS_BPIO_OUTPUT, StreamResume))>
      FS_BPIO_OUTPUT_GET_INFO_SIZE equ <(RTL_SIZEOF_THROUGH_FIELD(FS_BPIO_OUTPUT, GetInfo))>
    endif
    ; (NTDDI_VERSION >= NTDDI_WIN10_CO)
    ; ****************** Insert New FSCTLs above Here ****************************
  endif
  ; _FILESYSTEMFSCTL_
  ;=============== END FileSystem FSCTL Structure Definitions ==================
  ; Some applications include both ntioapi_x.h and winioctl.h
  ifndef SMB_CCF_APP_INSTANCE_EA_NAME
    SMB_CCF_APP_INSTANCE_EA_NAME equ <"ClusteredApplicationInstance">
  endif
  ;SMB_CCF_APP_INSTANCE_EA_NAME
  ifndef _NETWORK_APP_INSTANCE_EA_DEFINED
    _NETWORK_APP_INSTANCE_EA_DEFINED equ <>
    if (NTDDI_VERSION ge NTDDI_WIN10)
      ; Define the SMB Cluster Client Failover AppInstance Extended Attribute name
      ; newer version of input payload assumes that EA is not just a GUID,
      ; but instead is a structure that contains additional information
      ; Is used only when file is opened directly on CSVFS. This flag is ignored when file
      ; is opened over SMB.
      ; Tells CSVFS that this file open should be valid only on coordinating node.
      ; If open comes to CSVFS, and this node is not a coordinating then open would fail.
      ; If file is opened, and coordinating node is moved then file open will be invalidated
      ifndef NETWORK_APP_INSTANCE_CSV_FLAGS_VALID_ONLY_IF_CSV_COORDINATOR
        NETWORK_APP_INSTANCE_CSV_FLAGS_VALID_ONLY_IF_CSV_COORDINATOR equ 00000001h
      endif
      ;NETWORK_APP_INSTANCE_CSV_FLAGS_VALID_ONLY_IF_CSV_COORDINATOR
      NETWORK_APP_INSTANCE_EA struct
        ;  The caller places a GUID that should always be unique for a single instance of
        ;  the application.
        AppInstanceID GUID <>
        ;  Combination of the NETWORK_APP_INSTANCE_CSV_FLAGS_* flags
        CsvFlags DWORD ?
      NETWORK_APP_INSTANCE_EA ends
      _NETWORK_APP_INSTANCE_EA typedef NETWORK_APP_INSTANCE_EA
      PNETWORK_APP_INSTANCE_EA typedef ptr NETWORK_APP_INSTANCE_EA
    endif
    ; (NTDDI_VERSION >= NTDDI_WIN10)
  endif
  ;_NETWORK_APP_INSTANCE_EA_DEFINED
  if (NTDDI_VERSION ge NTDDI_WIN10_MN)
    ;=============== FSCTL_SMB_SHARE_FLUSH_AND_PURGE =================
    ifndef SMB_SHARE_FLUSH_AND_PURGE_INPUT_DESCRIPTORS_DEFINED
      SMB_SHARE_FLUSH_AND_PURGE_INPUT_DESCRIPTORS_DEFINED equ <>
      SMB_SHARE_FLUSH_AND_PURGE_INPUT struct
        Version WORD ?
        ; sizeof(SMB_SHARE_FLUSH_AND_PURGE)
      SMB_SHARE_FLUSH_AND_PURGE_INPUT ends
      _SMB_SHARE_FLUSH_AND_PURGE_INPUT typedef SMB_SHARE_FLUSH_AND_PURGE_INPUT
      PSMB_SHARE_FLUSH_AND_PURGE_INPUT typedef ptr SMB_SHARE_FLUSH_AND_PURGE_INPUT
      PCSMB_SHARE_FLUSH_AND_PURGE_INPUT typedef ptr _SMB_SHARE_FLUSH_AND_PURGE_INPUT
      SMB_SHARE_FLUSH_AND_PURGE_OUTPUT struct
        cEntriesPurged DWORD ?
      SMB_SHARE_FLUSH_AND_PURGE_OUTPUT ends
      _SMB_SHARE_FLUSH_AND_PURGE_OUTPUT typedef SMB_SHARE_FLUSH_AND_PURGE_OUTPUT
      PSMB_SHARE_FLUSH_AND_PURGE_OUTPUT typedef ptr SMB_SHARE_FLUSH_AND_PURGE_OUTPUT
      PCSMB_SHARE_FLUSH_AND_PURGE_OUTPUT typedef ptr _SMB_SHARE_FLUSH_AND_PURGE_OUTPUT
    endif
    ; defined(SMB_SHARE_FLUSH_AND_PURGE_INPUT_DESCRIPTORS_DEFINED)
  endif
  ; (NTDDI_VERSION >= NTDDI_WIN10_MN)
  IOCTL_VOLUME_BASE equ 00000056h; 'V'

  if (NTDDI_VERSION ge NTDDI_WIN2K)
    ; IOCTL to obtain the physical location of
    ; the specified volume on one or more disks.
    IOCTL_VOLUME_GET_VOLUME_DISK_EXTENTS equ CTL_CODE(IOCTL_VOLUME_BASE, 0, METHOD_BUFFERED, FILE_ANY_ACCESS)
    ; IOCTL_VOLUME_GET_VOLUME_DISK_EXTENTS
    ; Input Buffer:
    ;     None
    ; Output Buffer:
    ;     Structure of type VOLUME_DISK_EXTENTS
    DISK_EXTENT struct
      ; Specifies the storage device number of
      ; the disk on which this extent resides.
      DiskNumber DWORD ?
      ; Specifies the offset and length of this
      ; extent relative to the beginning of the
      ; disk.
      StartingOffset LARGE_INTEGER <>
      ExtentLength LARGE_INTEGER <>
    DISK_EXTENT ends
    _DISK_EXTENT typedef DISK_EXTENT
    PDISK_EXTENT typedef ptr DISK_EXTENT
    VOLUME_DISK_EXTENTS struct
      ; Specifies one or more contiguous range
      ; of sectors that make up this volume.
      NumberOfDiskExtents DWORD ?
      Extents DISK_EXTENT ANYSIZE_ARRAY dup (<>)
    VOLUME_DISK_EXTENTS ends
    _VOLUME_DISK_EXTENTS typedef VOLUME_DISK_EXTENTS
    PVOLUME_DISK_EXTENTS typedef ptr VOLUME_DISK_EXTENTS
    ; IOCTLs to transition the specified volume
    ; between r/w and non r/w modes.
    IOCTL_VOLUME_ONLINE equ CTL_CODE(IOCTL_VOLUME_BASE, 2, METHOD_BUFFERED, FILE_READ_ACCESS or FILE_WRITE_ACCESS)
    IOCTL_VOLUME_OFFLINE equ CTL_CODE(IOCTL_VOLUME_BASE, 3, METHOD_BUFFERED, FILE_READ_ACCESS or FILE_WRITE_ACCESS)
    ; IOCTL_VOLUME_ONLINE
    ; IOCTL_VOLUME_OFFLINE
    ; Input Buffer:
    ;     None
    ; Output Buffer:
    ;     None
  endif
  ; NTDDI_VERSION >= NTDDI_WIN2K
  if (NTDDI_VERSION ge NTDDI_WINXP)
    ; IOCTL to determine  whether  the specified
    ; volume resides on a disk that is an online
    ; cluster resource or not.
    IOCTL_VOLUME_IS_CLUSTERED equ CTL_CODE(IOCTL_VOLUME_BASE, 12, METHOD_BUFFERED, FILE_ANY_ACCESS)
    ; IOCTL_VOLUME_IS_CLUSTERED
    ; Input Buffer:
    ;     None
    ; Output Buffer:
    ;     None
    ; IOCTL to query the attributes on volumes.
    IOCTL_VOLUME_GET_GPT_ATTRIBUTES equ CTL_CODE(IOCTL_VOLUME_BASE, 14, METHOD_BUFFERED, FILE_ANY_ACCESS)
    ; IOCTL_VOLUME_GET_GPT_ATTRIBUTES
    ; Input Buffer:
    ;     None
    ; Output Buffer:
    ;     Structure of type VOLUME_GET_GPT_ATTRIBUTES_INFORMATION
    VOLUME_GET_GPT_ATTRIBUTES_INFORMATION struct
      ; Specifies all the attributes
      ; associated with this volume.
      GptAttributes QWORD ?
    VOLUME_GET_GPT_ATTRIBUTES_INFORMATION ends
    _VOLUME_GET_GPT_ATTRIBUTES_INFORMATION typedef VOLUME_GET_GPT_ATTRIBUTES_INFORMATION
    PVOLUME_GET_GPT_ATTRIBUTES_INFORMATION typedef ptr VOLUME_GET_GPT_ATTRIBUTES_INFORMATION
  endif
  ; NTDDI_VERSION >= NTDDI_WINXP
  if (NTDDI_VERSION ge NTDDI_WINTHRESHOLD)
    ;  This is a function prototype for a routine that will be called from the
    ;  IoPropagateIrpExtensionEx routine whenever the IopFsTrackOffsetType
    ;  extension type is set for a given IRP
    ifndef _IO_IRP_EXT_TRACK_OFFSET_HEADER_
      _IO_IRP_EXT_TRACK_OFFSET_HEADER_ equ <>
      TYPE_PIO_IRP_EXT_PROCESS_TRACKED_OFFSET_CALLBACK typedef proto WIN_STD_CALL_CONV :ptr _IO_IRP_EXT_TRACK_OFFSET_HEADER, :ptr _IO_IRP_EXT_TRACK_OFFSET_HEADER, :LONGLONG
      PIO_IRP_EXT_PROCESS_TRACKED_OFFSET_CALLBACK typedef ptr TYPE_PIO_IRP_EXT_PROCESS_TRACKED_OFFSET_CALLBACK

      ;  When any IRP extension exists which has an OFFSET which needs processing,
      ;  the Irp extension field in the IRP must point to one of these structures.
      ;  This is so IoPropagateIrpExtensionEx can calculate proper file offset
      ;  adjustments for the sub IRPS as they are split and shifted
      IRP_EXT_TRACK_OFFSET_HEADER_VALIDATION_VALUE equ <'TO'>;Track Offset

      IO_IRP_EXT_TRACK_OFFSET_HEADER struct
        Validation WORD ?
        ;  Each consumer of this IRP extension must define a flag that helps
        ;  identify the usage of the header. eg: EFS_TRACKED_OFFSET_HEADER_FLAG
        Flags WORD ?
        TrackedOffsetCallback PIO_IRP_EXT_PROCESS_TRACKED_OFFSET_CALLBACK ?
      IO_IRP_EXT_TRACK_OFFSET_HEADER ends
      _IO_IRP_EXT_TRACK_OFFSET_HEADER typedef IO_IRP_EXT_TRACK_OFFSET_HEADER
      PIO_IRP_EXT_TRACK_OFFSET_HEADER typedef ptr IO_IRP_EXT_TRACK_OFFSET_HEADER
      ;  When using the TrackedOffset IRP extension one of the following
      ;  flag must be specified so that we can distinguish it from other
      ;  components setting this IRP extension
      EFS_TRACKED_OFFSET_HEADER_FLAG equ 0001h;EFS Flag

      SPACES_TRACKED_OFFSET_HEADER_FLAG equ 0002h;SPACES Flag

    endif
    ; _IO_IRP_EXT_TRACK_OFFSET_HEADER_
  endif
  ; (NTDDI_VERSION >= NTDDI_WINTHRESHOLD)
  if _MSC_VER ge 1200
  endif
endif
; _WINIOCTL_
