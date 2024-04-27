struct DISPLAYCONFIG_TARGET_DEVICE_NAME_FLAGS
{
    union
    {
        struct
        {
            UINT32  friendlyNameFromEdid : 1;
            UINT32  friendlyNameForced : 1;
            UINT32  edidIdsValid : 1;
            UINT32  reserved : 32;
        } DUMMYSTRUCTNAME;
        UINT32  value;
    } DUMMYUNIONNAME;
} DISPLAYCONFIG_TARGET_DEVICE_NAME_FLAGS;



typedef struct {
#ifndef _MAC
  unsigned short bAppReturnCode:8,
                 reserved:6,
                 fBusy:1,
                 fAck:1;
#else
  unsigned short usFlags;
#endif
} DDEACK;

typedef struct {
  unsigned short usFlags1;
  unsigned short usFlags2;
} DDEACK;

#define WM_DDE_FIRST        0x03E0
#define WM_DDE_INITIATE     (WM_DDE_FIRST)
#define WM_DDE_TERMINATE    (WM_DDE_FIRST+1)
#define WM_DDE_ADVISE       (WM_DDE_FIRST+2)
#define WM_DDE_UNADVISE     (WM_DDE_FIRST+3)
#define WM_DDE_ACK          (WM_DDE_FIRST+4)
#define WM_DDE_DATA         (WM_DDE_FIRST+5)
#define WM_DDE_REQUEST      (WM_DDE_FIRST+6)
#define WM_DDE_POKE         (WM_DDE_FIRST+7)
#define WM_DDE_EXECUTE      (WM_DDE_FIRST+8)
#define WM_DDE_LAST         (WM_DDE_FIRST+8)