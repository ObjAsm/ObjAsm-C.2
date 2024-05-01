    interface IUnknown
    {
        CONST_VTBL struct IUnknownVtbl *lpVtbl;
    };



#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("00000000-0000-0000-C000-000000000046")
    IUnknown
    {
    public:
        BEGIN_INTERFACE
        virtual HRESULT STDMETHODCALLTYPE QueryInterface( 
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject) = 0;
        
        virtual ULONG STDMETHODCALLTYPE AddRef( void) = 0;
        
        virtual ULONG STDMETHODCALLTYPE Release( void) = 0;
        
        END_INTERFACE
    };
    
    
#else 	/* C style interface */

    typedef struct IUnknownVtbl
    {
        BEGIN_INTERFACE
        
        DECLSPEC_XFGVIRT(IUnknown, QueryInterface)
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IUnknown * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        DECLSPEC_XFGVIRT(IUnknown, AddRef)
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IUnknown * This);
        
        DECLSPEC_XFGVIRT(IUnknown, Release)
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IUnknown * This);
        
        END_INTERFACE
    } IUnknownVtbl;

    interface IUnknown
    {
        CONST_VTBL struct IUnknownVtbl *lpVtbl;
    };
#endif 	/* C style interface */


typedef struct tagINPUT_TRANSFORM {
    union {
        struct {
            float        _11, _12, _13, _14;
            float        _21, _22, _23, _24;
            float        _31, _32, _33, _34;
            float        _41, _42, _43, _44;
        } DUMMYSTRUCTNAME;
        float m[4][4];
    } DUMMYUNIONNAME;
} INPUT_TRANSFORM;


typedef DWORD (APIENTRY PM_COLLECT_PROC)(
    _In_opt_ LPWSTR pValueName,
    _Inout_
        _At_(*ppData, _Pre_writable_byte_size_(*pcbTotalBytes) _Post_writable_byte_size_(*pcbTotalBytes))
        _At_(_Old_(*ppData), _Post_writable_byte_size_(*pcbTotalBytes))
        void** ppData,
    _Inout_ DWORD* pcbTotalBytes,
    _Out_ DWORD* pNumObjectTypes
    );


typedef struct WIN32_MEMORY_REGION_INFORMATION {
    PVOID AllocationBase;
    ULONG AllocationProtect;

    union {
        ULONG Flags;

        struct {
            ULONG Private : 1;
            ULONG MappedDataFile : 1;
            ULONG MappedImage : 1;
            ULONG MappedPageFile : 1;
            ULONG MappedPhysical : 1;
            ULONG DirectMapped : 1;
            ULONG Reserved : 26;
        } DUMMYSTRUCTNAME;
    } DUMMYUNIONNAME;

    SIZE_T RegionSize;
    SIZE_T CommitSize;
} WIN32_MEMORY_REGION_INFORMATION;

typedef struct _COMSTAT {
    DWORD fCtsHold : 1;
    DWORD fDsrHold : 1;
    DWORD fRlsdHold : 1;
    DWORD fXoffHold : 1;
    DWORD fXoffSent : 1;
    DWORD fEof : 1;
    DWORD fTxim : 1;
    DWORD fReserved : 25;
    DWORD cbInQue;
    DWORD cbOutQue;
} COMSTAT, *LPCOMSTAT;

typedef struct {
	BYTE	 Value[1][2];
} DDEDATA;


typedef struct {
#ifndef _MAC
  unsigned short reserved:14,
                 fDeferUpd:1,
		             fAckReq:1;
#else
  unsigned short usFlags;
#endif
	short     cfFormat;
} DDEADVISE;


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