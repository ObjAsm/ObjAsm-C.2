; ==================================================================================================
; Title:      ComPortNames.inc
; Author:     G. Friedrich
; Version:    C.1.1
; Purpose:    ObjAsm implementation to handle connected COM Ports.
; Notes:      Version C.1.1, October 2020
;               - First release.
; ==================================================================================================


COMPORT_NAME_LEN    equ   8       ;"COMxxx" + ZTC + 1 padding

COMPORT_INFO struct
  cName         CHR       COMPORT_NAME_LEN DUP(?)
  pFriendlyName PSTRING   ?
COMPORT_INFO ends
PCOMPORT_INFO typedef ptr COMPORT_INFO


.code
; --------------------------------------------------------------------------------------------------
; Procedure:  GetComPortNames
; Purpose:    Get connected COM Port names and friendly names.
; Arguments:  None.
; Return:     xax -> COMPORT_INFO array.
;             ecx = array element count.

GetComPortNames proc uses xbx xdi xsi
  local hDevInfoSet:HDEVINFO, DevInfo:SP_DEVINFO_DATA
  local hDeviceKey:HKEY, dStrSize:DWORD
  local InfoBuffer[256]:COMPORT_INFO      ;Max 256 COM Ports [4096 bytes]

  invoke SetupDiGetClassDevs, offset GUID_DEVINTERFACE_COMPORT, NULL, NULL,
                              DIGCF_PRESENT or DIGCF_DEVICEINTERFACE
  xor ebx, ebx
  lea xsi, InfoBuffer
  .if xax != INVALID_HANDLE_VALUE
    mov hDevInfoSet, xax
    mov DevInfo.cbSize, sizeof(SP_DEVINFO_DATA)

    ;Enumerate the current Device Info Set
    .while TRUE
      mov CHR ptr [xsi].COMPORT_INFO.cName, 0
      mov [xsi].COMPORT_INFO.pFriendlyName, NULL
      invoke SetupDiEnumDeviceInfo, hDevInfoSet, ebx, addr DevInfo  ;Fill DevInfo structure
      .break .if eax == FALSE
      ;Get the registry key which stores the port settings
      invoke SetupDiOpenDevRegKey, hDevInfoSet, addr DevInfo, DICS_FLAG_GLOBAL, 0, DIREG_DEV,
                                   KEY_QUERY_VALUE
      .if xax != INVALID_HANDLE_VALUE
        mov hDeviceKey, xax

        mov dStrSize, 0
        invoke RegQueryValueEx, hDeviceKey, $OfsCStr("PortName"), NULL, NULL, NULL, addr dStrSize
        .if xax == ERROR_SUCCESS
          .if dStrSize > COMPORT_NAME_LEN*sizeof(CHR)
            mov dStrSize, COMPORT_NAME_LEN*sizeof(CHR)
          .endif
          invoke RegQueryValueEx, hDeviceKey, $OfsCStr("PortName"), NULL, NULL, \
                                  addr [xsi].COMPORT_INFO.cName, addr dStrSize

          ;Get friendly name
          mov dStrSize, 0
          ;Query initially to get the buffer size required
          invoke SetupDiGetDeviceRegistryProperty, hDevInfoSet, addr DevInfo, SPDRP_DEVICEDESC, \
                                                   NULL, NULL, 0, addr dStrSize
          invoke GlobalAlloc, 0, dStrSize
          mov [xsi].COMPORT_INFO.pFriendlyName, xax
          invoke SetupDiGetDeviceRegistryProperty, hDevInfoSet, addr DevInfo, SPDRP_DEVICEDESC, \
                                                   NULL, [xsi].COMPORT_INFO.pFriendlyName, \
                                                   dStrSize, addr dStrSize
        .endif
        invoke RegCloseKey, hDeviceKey
      .endif
      inc ebx
      add xsi, sizeof COMPORT_INFO
    .endw
    invoke SetupDiDestroyDeviceInfoList, hDevInfoSet
    mov eax, ebx
    mov ecx, sizeof(COMPORT_INFO)
    mul ecx
    mov edi, eax
    MemAlloc eax
    mov xsi, xax
    lea xdx, InfoBuffer
    invoke MemClone, xax, xdx, edi
    mov xax, xsi
    mov ecx, ebx
  .else
    xor eax, eax
    xor ecx, ecx
  .endif
  ret
GetComPortNames endp

; --------------------------------------------------------------------------------------------------
; Procedure:  FreeComPortNames
; Purpose:    Free memory allocated for COMPORT_INFO array
; Arguments:  Arg1 -> COMPORT_INFO array
; Return:     Nothing.

FreeComPortNames proc uses xbx xdi pComPortInfo:PCOMPORT_INFO
  mov xdi, pComPortInfo
  invoke HeapSize, hProcessHeap, HEAP_NO_SERIALIZE, xdi   ;Get Memblock size
  .if eax != -1
    mov ebx, eax
    test ebx, ebx
    .while !ZERO?
      ;Dispose allocated string
      invoke StrDispose, PSTRING ptr [xdi].COMPORT_INFO.pFriendlyName
      add xdi, sizeof COMPORT_INFO
      sub ebx, sizeof COMPORT_INFO
    .endw
  .endif
  ret
FreeComPortNames endp
