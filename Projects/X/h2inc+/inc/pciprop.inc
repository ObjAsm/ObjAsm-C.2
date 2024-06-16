;Include file created by h2inc+ version C.2.0 on (UTC) 15/06/2024 16:37:44
;(C) G. Friedrich April 2024
;Source file: d:\objasm\projects\x\h2inc+\h\um_10.0.22621.0\pciprop.h
;             Created on (UTC) 22/05/2024 17:57:08
;             Last modified on (UTC) 12/02/2024 17:05:38

ifndef _PCIPROP_
  _PCIPROP_ equ <>
  include winapifamily.inc
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    DEFINE_PCI_ROOT_BUS_DEVPKEY macro _DevPkeyName, _Pid
      exitm <DEFINE_DEVPROPKEY((_DevPkeyName), 0d817fc28h, 793eh, 4b9eh, 99h, 70h, 46h, 9dh, 8bh, 0e6h, 30h, 73h, (_Pid))>
    endm
    DevProp_PciRootBus_SecondaryInterface_PciConventional equ 0
    DevProp_PciRootBus_SecondaryInterface_PciXMode1 equ 1
    DevProp_PciRootBus_SecondaryInterface_PciXMode2 equ 2
    DevProp_PciRootBus_SecondaryInterface_PciExpress equ 3
    DEFINE_PCI_ROOT_BUS_DEVPKEY(DEVPKEY_PciRootBus_SecondaryInterface, 1)
    DevProp_PciRootBus_CurrentSpeedAndMode_Pci_Conventional_33Mhz equ 0
    DevProp_PciRootBus_CurrentSpeedAndMode_Pci_Conventional_66Mhz equ 1
    DevProp_PciRootBus_CurrentSpeedAndMode_Pci_X_Mode1_66Mhz equ 2
    DevProp_PciRootBus_CurrentSpeedAndMode_Pci_X_Mode1_100Mhz equ 3
    DevProp_PciRootBus_CurrentSpeedAndMode_Pci_X_Mode1_133Mhz equ 4
    DevProp_PciRootBus_CurrentSpeedAndMode_Pci_X_Mode1_ECC_66Mhz equ 5
    DevProp_PciRootBus_CurrentSpeedAndMode_Pci_X_Mode1_ECC_100Mhz equ 6
    DevProp_PciRootBus_CurrentSpeedAndMode_Pci_X_Mode1_ECC_133Mhz equ 7
    DevProp_PciRootBus_CurrentSpeedAndMode_Pci_X_266_Mode2_66Mhz equ 8
    DevProp_PciRootBus_CurrentSpeedAndMode_Pci_X_266_Mode2_100Mhz equ 9
    DevProp_PciRootBus_CurrentSpeedAndMode_Pci_X_266_Mode2_133Mhz equ 10
    DevProp_PciRootBus_CurrentSpeedAndMode_Pci_X_533_Mode2_66Mhz equ 11
    DevProp_PciRootBus_CurrentSpeedAndMode_Pci_X_533_Mode2_100Mhz equ 12
    DevProp_PciRootBus_CurrentSpeedAndMode_Pci_X_533_Mode2_133Mhz equ 13
    DEFINE_PCI_ROOT_BUS_DEVPKEY(DEVPKEY_PciRootBus_CurrentSpeedAndMode, 2)
    DevProp_PciRootBus_SupportedSpeedsAndModes_Pci_Conventional_33Mhz equ 1
    DevProp_PciRootBus_SupportedSpeedsAndModes_Pci_Conventional_66Mhz equ 2
    DevProp_PciRootBus_SupportedSpeedsAndModes_Pci_X_66Mhz equ 4
    DevProp_PciRootBus_SupportedSpeedsAndModes_Pci_X_133Mhz equ 8
    DevProp_PciRootBus_SupportedSpeedsAndModes_Pci_X_266Mhz equ 16
    DevProp_PciRootBus_SupportedSpeedsAndModes_Pci_X_533Mhz equ 32
    DEFINE_PCI_ROOT_BUS_DEVPKEY(DEVPKEY_PciRootBus_SupportedSpeedsAndModes, 3)
    DEFINE_PCI_ROOT_BUS_DEVPKEY(DEVPKEY_PciRootBus_DeviceIDMessagingCapable, 4)
    DevProp_PciRootBus_BusWidth_32Bits equ 0
    DevProp_PciRootBus_BusWidth_64Bits equ 1
    DEFINE_PCI_ROOT_BUS_DEVPKEY(DEVPKEY_PciRootBus_SecondaryBusWidth, 5)
    DEFINE_PCI_ROOT_BUS_DEVPKEY(DEVPKEY_PciRootBus_ExtendedConfigAvailable, 6)
    DEFINE_PCI_ROOT_BUS_DEVPKEY(DEVPKEY_PciRootBus_ExtendedPCIConfigOpRegionSupport, 7)
    DEFINE_PCI_ROOT_BUS_DEVPKEY(DEVPKEY_PciRootBus_ASPMSupport, 8)
    DEFINE_PCI_ROOT_BUS_DEVPKEY(DEVPKEY_PciRootBus_ClockPowerManagementSupport, 9)
    DEFINE_PCI_ROOT_BUS_DEVPKEY(DEVPKEY_PciRootBus_PCISegmentGroupsSupport, 10)
    DEFINE_PCI_ROOT_BUS_DEVPKEY(DEVPKEY_PciRootBus_MSISupport, 11)
    DEFINE_PCI_ROOT_BUS_DEVPKEY(DEVPKEY_PciRootBus_PCIExpressNativeHotPlugControl, 12)
    DEFINE_PCI_ROOT_BUS_DEVPKEY(DEVPKEY_PciRootBus_SHPCNativeHotPlugControl, 13)
    DEFINE_PCI_ROOT_BUS_DEVPKEY(DEVPKEY_PciRootBus_PCIExpressNativePMEControl, 14)
    DEFINE_PCI_ROOT_BUS_DEVPKEY(DEVPKEY_PciRootBus_PCIExpressAERControl, 15)
    DEFINE_PCI_ROOT_BUS_DEVPKEY(DEVPKEY_PciRootBus_PCIExpressCapabilityControl, 16)
    DEFINE_PCI_ROOT_BUS_DEVPKEY(DEVPKEY_PciRootBus_NativePciExpressControl, 17)
    DEFINE_PCI_ROOT_BUS_DEVPKEY(DEVPKEY_PciRootBus_SystemMsiSupport, 18)
    DEFINE_PCI_DEVICE_DEVPKEY macro _DevPkeyName, _Pid
      exitm <DEFINE_DEVPROPKEY((_DevPkeyName), 3ab22e31h, 8264h, 4b4eh, 9ah, 0f5h, 0a8h, 0d2h, 0d8h, 0e3h, 3eh, 62h, (_Pid))>
    endm
    DevProp_PciDevice_DeviceType_PciConventional equ 0
    DevProp_PciDevice_DeviceType_PciX equ 1
    DevProp_PciDevice_DeviceType_PciExpressEndpoint equ 2
    DevProp_PciDevice_DeviceType_PciExpressLegacyEndpoint equ 3
    DevProp_PciDevice_DeviceType_PciExpressRootComplexIntegratedEndpoint equ 4
    DevProp_PciDevice_DeviceType_PciExpressTreatedAsPci equ 5
    DevProp_PciDevice_BridgeType_PciConventional equ 6
    DevProp_PciDevice_BridgeType_PciX equ 7
    DevProp_PciDevice_BridgeType_PciExpressRootPort equ 8
    DevProp_PciDevice_BridgeType_PciExpressUpstreamSwitchPort equ 9
    DevProp_PciDevice_BridgeType_PciExpressDownstreamSwitchPort equ 10
    DevProp_PciDevice_BridgeType_PciExpressToPciXBridge equ 11
    DevProp_PciDevice_BridgeType_PciXToExpressBridge equ 12
    DevProp_PciDevice_BridgeType_PciExpressTreatedAsPci equ 13
    DevProp_PciDevice_BridgeType_PciExpressEventCollector equ 14
    DEFINE_PCI_DEVICE_DEVPKEY(DEVPKEY_PciDevice_DeviceType, 1)
    DevProp_PciDevice_CurrentSpeedAndMode_Pci_Conventional_33MHz equ 0
    DevProp_PciDevice_CurrentSpeedAndMode_Pci_Conventional_66MHz equ 1
    DevProp_PciDevice_CurrentSpeedAndMode_PciX_Mode_Conventional_Pci equ 0h
    DevProp_PciDevice_CurrentSpeedAndMode_PciX_Mode1_66Mhz equ 1h
    DevProp_PciDevice_CurrentSpeedAndMode_PciX_Mode1_100Mhz equ 2h
    DevProp_PciDevice_CurrentSpeedAndMode_PciX_Mode1_133MHZ equ 3h
    DevProp_PciDevice_CurrentSpeedAndMode_PciX_Mode1_ECC_66Mhz equ 5h
    DevProp_PciDevice_CurrentSpeedAndMode_PciX_Mode1_ECC_100Mhz equ 6h
    DevProp_PciDevice_CurrentSpeedAndMode_PciX_Mode1_ECC_133Mhz equ 7h
    DevProp_PciDevice_CurrentSpeedAndMode_PciX_Mode2_266_66MHz equ 9h
    DevProp_PciDevice_CurrentSpeedAndMode_PciX_Mode2_266_100MHz equ 0Ah
    DevProp_PciDevice_CurrentSpeedAndMode_PciX_Mode2_266_133MHz equ 0Bh
    DevProp_PciDevice_CurrentSpeedAndMode_PciX_Mode2_533_66MHz equ 0Dh
    DevProp_PciDevice_CurrentSpeedAndMode_PciX_Mode2_533_100MHz equ 0Eh
    DevProp_PciDevice_CurrentSpeedAndMode_PciX_Mode2_533_133MHz equ 0Fh
    DEFINE_PCI_DEVICE_DEVPKEY(DEVPKEY_PciDevice_CurrentSpeedAndMode, 2)
    DEFINE_PCI_DEVICE_DEVPKEY(DEVPKEY_PciDevice_BaseClass, 3)
    DEFINE_PCI_DEVICE_DEVPKEY(DEVPKEY_PciDevice_SubClass, 4)
    DEFINE_PCI_DEVICE_DEVPKEY(DEVPKEY_PciDevice_ProgIf, 5)
    DevProp_PciExpressDevice_PayloadOrRequestSize_128Bytes equ 0
    DevProp_PciExpressDevice_PayloadOrRequestSize_256Bytes equ 1
    DevProp_PciExpressDevice_PayloadOrRequestSize_512Bytes equ 2
    DevProp_PciExpressDevice_PayloadOrRequestSize_1024Bytes equ 3
    DevProp_PciExpressDevice_PayloadOrRequestSize_2048Bytes equ 4
    DevProp_PciExpressDevice_PayloadOrRequestSize_4096Bytes equ 5
    DEFINE_PCI_DEVICE_DEVPKEY(DEVPKEY_PciDevice_CurrentPayloadSize, 6)
    DEFINE_PCI_DEVICE_DEVPKEY(DEVPKEY_PciDevice_MaxPayloadSize, 7)
    DEFINE_PCI_DEVICE_DEVPKEY(DEVPKEY_PciDevice_MaxReadRequestSize, 8)
    DevProp_PciExpressDevice_LinkSpeed_TwoAndHalf_Gbps equ 1
    DevProp_PciExpressDevice_LinkSpeed_Five_Gbps equ 2
    DEFINE_PCI_DEVICE_DEVPKEY(DEVPKEY_PciDevice_CurrentLinkSpeed, 9)
    DevProp_PciExpressDevice_LinkWidth_By_1 equ 1
    DevProp_PciExpressDevice_LinkWidth_By_2 equ 2
    DevProp_PciExpressDevice_LinkWidth_By_4 equ 4
    DevProp_PciExpressDevice_LinkWidth_By_8 equ 8
    DevProp_PciExpressDevice_LinkWidth_By_12 equ 12
    DevProp_PciExpressDevice_LinkWidth_By_16 equ 16
    DevProp_PciExpressDevice_LinkWidth_By_32 equ 32
    DEFINE_PCI_DEVICE_DEVPKEY(DEVPKEY_PciDevice_CurrentLinkWidth, 10)
    DevProp_PciExpressDevice_LinkSpeed_TwoAndHalf_Gbps equ 1
    DEFINE_PCI_DEVICE_DEVPKEY(DEVPKEY_PciDevice_MaxLinkSpeed, 11)
    DEFINE_PCI_DEVICE_DEVPKEY(DEVPKEY_PciDevice_MaxLinkWidth, 12)
    DevProp_PciExpressDevice_Spec_Version_10 equ 1
    DevProp_PciExpressDevice_Spec_Version_11 equ 2
    DEFINE_PCI_DEVICE_DEVPKEY(DEVPKEY_PciDevice_ExpressSpecVersion, 13)
    DevProp_PciDevice_InterruptType_LineBased equ 1
    DevProp_PciDevice_InterruptType_Msi equ 2
    DevProp_PciDevice_InterruptType_MsiX equ 4
    DEFINE_PCI_DEVICE_DEVPKEY(DEVPKEY_PciDevice_InterruptSupport, 14)
    DEFINE_PCI_DEVICE_DEVPKEY(DEVPKEY_PciDevice_InterruptMessageMaximum, 15)
    DevProp_PciDevice_IoBarCount macro _PropertyData
      exitm <((_PropertyData) and 0FFh)>
    endm
    DevProp_PciDevice_NonPrefetchable_MemoryBarCount macro _PropertyData
      exitm <(((_PropertyData) shr 8) and 0FFh)>
    endm
    DevProp_PciDevice_32BitPrefetchable_MemoryBarCount macro _PropertyData
      exitm <(((_PropertyData) shr 16) and 0FFh)>
    endm
    DevProp_PciDevice_64BitPrefetchable_MemoryBarCount macro _PropertyData
      exitm <(((_PropertyData) shr 24) and 0FFh)>
    endm
    DEFINE_PCI_DEVICE_DEVPKEY(DEVPKEY_PciDevice_BarTypes, 16)
    DEFINE_PCI_DEVICE_DEVPKEY(DEVPKEY_PciDevice_AERCapabilityPresent, 17)
    DEFINE_PCI_DEVICE_DEVPKEY(DEVPKEY_PciDevice_FirmwareErrorHandling, 18)
    DEFINE_PCI_DEVICE_DEVPKEY(DEVPKEY_PciDevice_Uncorrectable_Error_Mask, 19)
    DEFINE_PCI_DEVICE_DEVPKEY(DEVPKEY_PciDevice_Uncorrectable_Error_Severity, 20)
    DEFINE_PCI_DEVICE_DEVPKEY(DEVPKEY_PciDevice_Correctable_Error_Mask, 21)
    DEFINE_PCI_DEVICE_DEVPKEY(DEVPKEY_PciDevice_ECRC_Errors, 22)
    DEFINE_PCI_DEVICE_DEVPKEY(DEVPKEY_PciDevice_Error_Reporting, 23)
    DEFINE_PCI_DEVICE_DEVPKEY(DEVPKEY_PciDevice_RootError_Reporting, 24)
    DEFINE_PCI_DEVICE_DEVPKEY(DEVPKEY_PciDevice_S0WakeupSupported, 25)
    DevProp_PciDevice_SriovSupport_Ok equ 0h
    DevProp_PciDevice_SriovSupport_MissingAcs equ 1h
    DevProp_PciDevice_SriovSupport_MissingPfDriver equ 2h
    DevProp_PciDevice_SriovSupport_NoBusResource equ 3h
    DevProp_PciDevice_SriovSupport_DidntGetVfBarSpace equ 4h
    DEFINE_PCI_DEVICE_DEVPKEY(DEVPKEY_PciDevice_SriovSupport, 26)
    DEFINE_PCI_DEVICE_DEVPKEY(DEVPKEY_PciDevice_Label_Id, 27)
    DEFINE_PCI_DEVICE_DEVPKEY(DEVPKEY_PciDevice_Label_String, 28)
    DevProp_PciDevice_AcsSupport_Present equ 0h
    DevProp_PciDevice_AcsSupport_NotNeeded equ 1h
    DevProp_PciDevice_AcsSupport_Missing equ 2h
    DEFINE_PCI_DEVICE_DEVPKEY(DEVPKEY_PciDevice_AcsSupport, 29)
    DEFINE_PCI_DEVICE_DEVPKEY(DEVPKEY_PciDevice_AriSupport, 30)
    DevProp_PciDevice_AcsCompatibleUpHierarchy_NotSupported equ 0h
    DevProp_PciDevice_AcsCompatibleUpHierarchy_SingleFunctionSupported equ 1h
    DevProp_PciDevice_AcsCompatibleUpHierarchy_NoP2PSupported equ 2h
    DevProp_PciDevice_AcsCompatibleUpHierarchy_Supported equ 3h
    DevProp_PciDevice_AcsCompatibleUpHierarchy_Enhanced equ 4h
    DEFINE_PCI_DEVICE_DEVPKEY(DEVPKEY_PciDevice_AcsCompatibleUpHierarchy, 31)
    DEFINE_PCI_DEVICE_DEVPKEY(DEVPKEY_PciDevice_AcsCapabilityRegister, 32)
    DEFINE_PCI_DEVICE_DEVPKEY(DEVPKEY_PciDevice_AtsSupport, 33)
    DEFINE_PCI_DEVICE_DEVPKEY(DEVPKEY_PciDevice_RequiresReservedMemoryRegion, 34)
    DEFINE_PCI_DEVICE_DEVPKEY(DEVPKEY_PciDevice_AtomicsSupported, 35)
    DEFINE_PCI_DEVICE_DEVPKEY(DEVPKEY_PciDevice_SupportedLinkSubState, 36)
    DEFINE_PCI_DEVICE_DEVPKEY(DEVPKEY_PciDevice_OnPostPath, 37)
    DEFINE_PCI_DEVICE_DEVPKEY(DEVPKEY_PciDevice_D3ColdSupport, 38)
    DEFINE_PCI_DEVICE_DEVPKEY(DEVPKEY_PciDevice_SerialNumber, 40)
    DEFINE_PCI_DEVICE_DEVPKEY(DEVPKEY_PciDevice_UsbDvsecPortType, 41)
    DEFINE_PCI_DEVICE_DEVPKEY(DEVPKEY_PciDevice_UsbDvsecPortSpecificAttributes, 42)
    DEFINE_PCI_DEVICE_DEVPKEY(DEVPKEY_PciDevice_UsbComponentRelation, 43)
    DEFINE_PCI_DEVICE_DEVPKEY(DEVPKEY_PciDevice_UsbHostRouterName, 44)
    DEFINE_PCI_DEVICE_DEVPKEY(DEVPKEY_PciDevice_ParentSerialNumber, 45)
    DEFINE_PCI_DEVICE_DEVPKEY(DEVPKEY_PciDevice_IsTunneledDevice, 47)
  endif
endif
