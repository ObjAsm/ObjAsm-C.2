; ==================================================================================================
; Title:      COM_Errors.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm COM Error Codes. Extracted from WinError.h file.
; Notes:      Version C.1.0, October 2017
;               - Initial release.
; ==================================================================================================


; The return value of COM functions and methods is an HRESULT. This is not a HANDLE to anything, but
; is merely a 32-bit value with several fields encoded in the value. The parts of an HRESULT are
; shown below. Many of the macros and functions below were orginally defined to operate on SCODEs.
; SCODEs are no longer used. The macros are still present for compatibility and easy porting of
; Win16 code. Newly written code should use the HRESULT macros and functions.
;
;     HRESULTs are 32 bit values layed out as follows:
;
;      3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1 1 1 0 0 0 0 0 0 0 0 0 0
;      1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0
;     +-+-+-+-+-+---------------------+-------------------------------+
;     |S|R|C|N|r|       Facility      |              Code             |
;     +-+-+-+-+-+---------------------+-------------------------------+
;
;     where:
;     S - Severity - indicates success/fail
;         0 - Success
;         1 - Fail (COERROR)
;     R - reserved portion of the facility code, corresponds to NT's
;         second severity bit.
;     C - reserved portion of the facility code, corresponds to NT's
;         C field.
;     N - reserved portion of the facility code. Used to indicate a
;         mapped NT status value.
;     r - reserved portion of the facility code. Reserved for internal
;         use. Used to indicate HRESULT values that are not status
;         values, but are instead message ids for display strings.
;     Facility - is the facility code
;     Code - is the facility's status code


; Define the facility codes
FACILITY_WINDOWS_CE     equ   24
FACILITY_WINDOWS        equ   8
FACILITY_URT            equ   19
FACILITY_UMI            equ   22
FACILITY_SXS            equ   23
FACILITY_STORAGE        equ   3
FACILITY_SSPI           equ   9
FACILITY_SCARD          equ   16
FACILITY_SETUPAPI       equ   15
FACILITY_SECURITY       equ   9
FACILITY_RPC            equ   1
FACILITY_WIN32          equ   7
FACILITY_CONTROL        equ   10
FACILITY_NULL           equ   0
FACILITY_MSMQ           equ   14
FACILITY_MEDIASERVER    equ   13
FACILITY_INTERNET       equ   12
FACILITY_ITF            equ   4
FACILITY_HTTP           equ   25
FACILITY_DPLAY          equ   21
FACILITY_DISPATCH       equ   2
FACILITY_CONFIGURATION  equ   33
FACILITY_COMPLUS        equ   17
FACILITY_CERT           equ   11
FACILITY_BACKGROUNDCOPY equ   32
FACILITY_ACS            equ   20
FACILITY_AAF            equ   18

FACILITY_NT_BIT         equ   10000000h


; Severity values
SEVERITY_SUCCESS        equ   0
SEVERITY_ERROR          equ   1


; Map a WIN32 error value into a HRESULT
; Note: This assumes that WIN32 errors fall in the range -32k to 32k.
; Define bits here so macros are guaranteed to work

$HRESULT_FROM_WIN32 macro ErrCode:req
  if ErrCode <= 0
    exitm <ErrCode>
  else
    exitm <(ErrCode and 0000FFFFh) or (FACILITY_WIN32 shl 16) or (80000000h)>
  endif
endm

; Map an NT status value into a HRESULT

$HRESULT_FROM_NT macro ErrCode:req
  exitm <(ErrCode or FACILITY_NT_BIT)>
endm


; HRESULT definitions

NOERROR equ 0

; Codes 4000h-40FFh are reserved for OLE

; Catastrophic failure
E_UNEXPECTED equ 8000FFFFh

;#if defined(_WIN32) && !defined(_MAC)

; Not implemented
E_NOTIMPL equ 80004001h

; Ran out of memory
E_OUTOFMEMORY equ 8007000Eh

; One or more arguments are invalid
E_INVALIDARG equ 80070057h

; No such interface supported
E_NOINTERFACE equ 80004002h

; Invalid pointer
E_POINTER equ 80004003h

; Invalid HANDLE
E_HANDLE equ 80070006h

; Operation aborted
E_ABORT equ 80004004h

; Unspecified error
E_FAIL equ 80004005h

; General access denied error
E_ACCESSDENIED equ 80070005h

;#else
;; Not implemented
;E_NOTIMPL equ 80000001h
;
;; Ran out of memory
;E_OUTOFMEMORY equ 80000002h
;
;; One or more arguments are invalid
;E_INVALIDARG equ 80000003h
;
;; No such interface supported
;E_NOINTERFACE equ 80000004h
;
;; Invalid pointer
;E_POINTER equ 80000005h
;
;; Invalid HANDLE
;E_HANDLE equ 80000006h
;
;; Operation aborted
;E_ABORT equ 80000007h
;
;; Unspecified error
;E_FAIL equ 80000008h
;
;; General access denied error
;E_ACCESSDENIED equ 80000009h
;
;#endif ;WIN32

; The data necessary to complete this operation is not yet available.
E_PENDING equ 8000000Ah

; Thread local storage failure
CO_E_INIT_TLS equ 80004006h

; Get shared memory allocator failure
CO_E_INIT_SHARED_ALLOCATOR equ 80004007h

; Get memory allocator failure
CO_E_INIT_MEMORY_ALLOCATOR equ 80004008h

; Unable to initialize class cache
CO_E_INIT_CLASS_CACHE equ 80004009h

; Unable to initialize RPC services
CO_E_INIT_RPC_CHANNEL equ 8000400Ah

; Cannot set thread local storage channel control
CO_E_INIT_TLS_SET_CHANNEL_CONTROL equ 8000400Bh

; Could not allocate thread local storage channel control
CO_E_INIT_TLS_CHANNEL_CONTROL equ 8000400Ch

; The user supplied memory allocator is unacceptable
CO_E_INIT_UNACCEPTED_USER_ALLOCATOR equ 8000400Dh

; The OLE service mutex already exists
CO_E_INIT_SCM_MUTEX_EXISTS equ 8000400Eh

; The OLE service file mapping already exists
CO_E_INIT_SCM_FILE_MAPPING_EXISTS equ 8000400Fh

; Unable to map view of file for OLE service
CO_E_INIT_SCM_MAP_VIEW_OF_FILE equ 80004010h

; Failure attempting to launch OLE service
CO_E_INIT_SCM_EXEC_FAILURE equ 80004011h

; There was an attempt to call CoInitialize a second time while single threaded
CO_E_INIT_ONLY_SINGLE_THREADED equ 80004012h

; A Remote activation was necessary but was not allowed
CO_E_CANT_REMOTE equ 80004013h

; A Remote activation was necessary but the server name provided was invalid
CO_E_BAD_SERVER_NAME equ 80004014h

; The class is configured to run as a security id different from the caller
CO_E_WRONG_SERVER_IDENTITY equ 80004015h

; Use of Ole1 services requiring DDE windows is disabled
CO_E_OLE1DDE_DISABLED equ 80004016h

; A RunAs specification must be <domain name>\<user name> or simply <user name>
CO_E_RUNAS_SYNTAX equ 80004017h

; The server process could not be started. The pathname may be incorrect.
CO_E_CREATEPROCESS_FAILURE equ 80004018h

; The server process could not be started as the configured identity. The pathname may be incorrect or unavailable.
CO_E_RUNAS_CREATEPROCESS_FAILURE equ 80004019h

; The server process could not be started because the configured identity is incorrect. Check the username and password.
CO_E_RUNAS_LOGON_FAILURE equ 8000401Ah

; The client is not allowed to launch this server.
CO_E_LAUNCH_PERMSSION_DENIED equ 8000401Bh

; The service providing this server could not be started.
CO_E_START_SERVICE_FAILURE equ 8000401Ch

; This computer was unable to communicate with the computer providing the server.
CO_E_REMOTE_COMMUNICATION_FAILURE equ 8000401Dh

; The server did not respond after being launched.
CO_E_SERVER_START_TIMEOUT equ 8000401Eh

; The registration information for this server is inconsistent or incomplete.
CO_E_CLSREG_INCONSISTENT equ 8000401Fh

; The registration information for this interface is inconsistent or incomplete.
CO_E_IIDREG_INCONSISTENT equ 80004020h

; The operation attempted is not supported.
CO_E_NOT_SUPPORTED equ 80004021h

; A dll must be loaded.
CO_E_RELOAD_DLL equ 80004022h

; A Microsoft Software Installer error was encountered.
CO_E_MSI_ERROR equ 80004023h

; The specified activation could not occur in the client context as specified.
CO_E_ATTEMPT_TO_CREATE_OUTSIDE_CLIENT_CONTEXT equ 80004024h

; Activations on the server are paused.
CO_E_SERVER_PAUSED equ 80004025h

; Activations on the server are not paused.
CO_E_SERVER_NOT_PAUSED equ 80004026h

; The component or application containing the component has been disabled.
CO_E_CLASS_DISABLED equ 80004027h

; The common language runtime is not available
CO_E_CLRNOTAVAILABLE equ 80004028h

; The thread-pool rejected the submitted asynchronous work.
CO_E_ASYNC_WORK_REJECTED equ 80004029h

; The server started, but did not finish initializing in a timely fashion.
CO_E_SERVER_INIT_TIMEOUT equ 8000402Ah

; Unable to complete the call since there is no COM+ security context inside IObjectControl.Activate.
CO_E_NO_SECCTX_IN_ACTIVATE equ 8000402Bh

; The provided tracker configuration is invalid
CO_E_TRACKER_CONFIG equ 80004030h

; The provided thread pool configuration is invalid
CO_E_THREADPOOL_CONFIG equ 80004031h

; The provided side-by-side configuration is invalid
CO_E_SXS_CONFIG equ 80004032h

; The server principal name (SPN) obtained during security negotiation is malformed.
CO_E_MALFORMED_SPN equ 80004033h


; Success codes
S_OK equ 00000000h
S_FALSE equ 00000001h


; ******************
; FACILITY_ITF
; ******************

; Codes 0000h-01FFh are reserved for the OLE group of
; interfaces.


; Generic OLE errors that may be returned by many inerfaces

OLE_E_FIRST equ 80040000h
OLE_E_LAST  equ 800400FFh
OLE_S_FIRST equ 00040000h
OLE_S_LAST  equ 000400FFh

; Old OLE errors
;
; Invalid OLEVERB structure
OLE_E_OLEVERB equ 80040000h

; Invalid advise flags
OLE_E_ADVF equ 80040001h

; Can't enumerate any more, because the associated data is missing
OLE_E_ENUM_NOMORE equ 80040002h

; This implementation doesn't take advises
OLE_E_ADVISENOTSUPPORTED equ 80040003h

; There is no connection for this connection ID
OLE_E_NOCONNECTION equ 80040004h

; Need to run the object to perform this operation
OLE_E_NOTRUNNING equ 80040005h

; There is no cache to operate on
OLE_E_NOCACHE equ 80040006h

; Uninitialized object
OLE_E_BLANK equ 80040007h

; Linked object's source class has changed
OLE_E_CLASSDIFF equ 80040008h

; Not able to get the moniker of the object
OLE_E_CANT_GETMONIKER equ 80040009h

; Not able to bind to the source
OLE_E_CANT_BINDTOSOURCE equ 8004000Ah

; Object is static; operation not allowed
OLE_E_STATIC equ 8004000Bh

; User canceled out of save dialog
OLE_E_PROMPTSAVECANCELLED equ 8004000Ch

; Invalid rectangle
OLE_E_INVALIDRECT equ 8004000Dh

; compobj.dll is too old for the ole2.dll initialized
OLE_E_WRONGCOMPOBJ equ 8004000Eh

; Invalid window HANDLE
OLE_E_INVALIDHWND equ 8004000Fh

; Object is not in any of the inplace active states
OLE_E_NOT_INPLACEACTIVE equ 80040010h

; Not able to convert object
OLE_E_CANTCONVERT equ 80040011h

; Not able to perform the operation because object is not given storage yet
OLE_E_NOSTORAGE equ 80040012h

; Invalid FORMATETC structure
DV_E_FORMATETC equ 80040064h

; Invalid DVTARGETDEVICE structure
DV_E_DVTARGETDEVICE equ 80040065h

; Invalid STDGMEDIUM structure
DV_E_STGMEDIUM equ 80040066h

; Invalid STATDATA structure
DV_E_STATDATA equ 80040067h

; Invalid lindex
DV_E_LINDEX equ 80040068h

; Invalid tymed
DV_E_TYMED equ 80040069h

; Invalid clipboard format
DV_E_CLIPFORMAT equ 8004006Ah

; Invalid aspect(s)
DV_E_DVASPECT equ 8004006Bh

; tdSize parameter of the DVTARGETDEVICE structure is invalid
DV_E_DVTARGETDEVICE_SIZE equ 8004006Ch

; Object doesn't support IViewObject interface
DV_E_NOIVIEWOBJECT equ 8004006Dh

DRAGDROP_E_FIRST equ 80040100h
DRAGDROP_E_LAST  equ 8004010Fh
DRAGDROP_S_FIRST equ 00040100h
DRAGDROP_S_LAST  equ 0004010Fh

; Trying to revoke a drop target that has not been registered
DRAGDROP_E_NOTREGISTERED equ 80040100h

; This window has already been registered as a drop target
DRAGDROP_E_ALREADYREGISTERED equ 80040101h

; Invalid window HANDLE
DRAGDROP_E_INVALIDHWND equ 80040102h

CLASSFACTORY_E_FIRST equ 80040110h
CLASSFACTORY_E_LAST equ 8004011Fh
CLASSFACTORY_S_FIRST equ 00040110h
CLASSFACTORY_S_LAST equ 0004011Fh

; Class does not support aggregation (or class object is remote)
CLASS_E_NOAGGREGATION equ 80040110h

; ClassFactory cannot supply requested class
CLASS_E_CLASSNOTAVAILABLE equ 80040111h

; Class is not licensed for use
CLASS_E_NOTLICENSED equ 80040112h

MARSHAL_E_FIRST equ 80040120h
MARSHAL_E_LAST equ 8004012Fh
MARSHAL_S_FIRST equ 00040120h
MARSHAL_S_LAST equ 0004012Fh
DATA_E_FIRST equ 80040130h
DATA_E_LAST equ 8004013Fh
DATA_S_FIRST equ 00040130h
DATA_S_LAST equ 0004013Fh
VIEW_E_FIRST equ 80040140h
VIEW_E_LAST equ 8004014Fh
VIEW_S_FIRST equ 00040140h
VIEW_S_LAST equ 0004014Fh

; Error drawing view
VIEW_E_DRAW equ 80040140h

REGDB_E_FIRST equ 80040150h
REGDB_E_LAST equ 8004015Fh
REGDB_S_FIRST equ 00040150h
REGDB_S_LAST equ 0004015Fh

; Could not read key from registry
REGDB_E_READREGDB equ 80040150h

; Could not write key to registry
REGDB_E_WRITEREGDB equ 80040151h

; Could not find the key in the registry
REGDB_E_KEYMISSING equ 80040152h

; Invalid value for registry
REGDB_E_INVALIDVALUE equ 80040153h

; Class not registered
REGDB_E_CLASSNOTREG equ 80040154h

; Interface not registered
REGDB_E_IIDNOTREG equ 80040155h

; Threading model entry is not valid
REGDB_E_BADTHREADINGMODEL equ 80040156h

CAT_E_FIRST equ 80040160h
CAT_E_LAST equ 80040161h

; CATID does not exist
CAT_E_CATIDNOEXIST equ 80040160h

; Description not found
CAT_E_NODESCRIPTION equ 80040161h

;;;;;;;;;;;;;;;;;;
;
; Class Store Error Codes
;
;;;;;;;;;;;;;;;;;;

CS_E_FIRST equ 80040164h
;CS_E_LAST equ 8004016Fh

; No package in the software installation data in the Active Directory meets this criteria.
CS_E_PACKAGE_NOTFOUND equ 80040164h

; Deleting this will break the referential integrity of the software installation data in the Active Directory.
CS_E_NOT_DELETABLE equ 80040165h

; The CLSID was not found in the software installation data in the Active Directory.
CS_E_CLASS_NOTFOUND equ 80040166h

; The software installation data in the Active Directory is corrupt.
CS_E_INVALID_VERSION equ 80040167h

; There is no software installation data in the Active Directory.
CS_E_NO_CLASSSTORE equ 80040168h

; There is no software installation data object in the Active Directory.
CS_E_OBJECT_NOTFOUND equ 80040169h

; The software installation data object in the Active Directory already exists.
CS_E_OBJECT_ALREADY_EXISTS equ 8004016Ah

; The path to the software installation data in the Active Directory is not correct.
CS_E_INVALID_PATH equ 8004016Bh

; A network error interrupted the operation.
CS_E_NETWORK_ERROR equ 8004016Ch

; The size of this object exceeds the maximum size set by the Administrator.
CS_E_ADMIN_LIMIT_EXCEEDED equ 8004016Dh

; The schema for the software installation data in the Active Directory does not match the required schema.
CS_E_SCHEMA_MISMATCH equ 8004016Eh

; An error occurred in the software installation data in the Active Directory.
CS_E_INTERNAL_ERROR equ 8004016Fh

CACHE_E_FIRST equ 80040170h
CACHE_E_LAST equ 8004017Fh
CACHE_S_FIRST equ 00040170h
CACHE_S_LAST equ 0004017Fh

; Cache not updated
CACHE_E_NOCACHE_UPDATED equ 80040170h

OLEOBJ_E_FIRST equ 80040180h
OLEOBJ_E_LAST equ 8004018Fh
OLEOBJ_S_FIRST equ 00040180h
OLEOBJ_S_LAST equ 0004018Fh

; No verbs for OLE object
OLEOBJ_E_NOVERBS equ 80040180h

; Invalid verb for OLE object
OLEOBJ_E_INVALIDVERB equ 80040181h

CLIENTSITE_E_FIRST equ 80040190h
CLIENTSITE_E_LAST equ 8004019Fh
CLIENTSITE_S_FIRST equ 00040190h
CLIENTSITE_S_LAST equ 0004019Fh

; Undo is not available
INPLACE_E_NOTUNDOABLE equ 800401A0h

; Space for tools is not available
INPLACE_E_NOTOOLSPACE equ 800401A1h

INPLACE_E_FIRST equ 800401A0h
INPLACE_E_LAST equ 800401AFh
INPLACE_S_FIRST equ 000401A0h
INPLACE_S_LAST equ 000401AFh
ENUM_E_FIRST equ 800401B0h
ENUM_E_LAST equ 800401BFh
ENUM_S_FIRST equ 000401B0h
ENUM_S_LAST equ 000401BFh
CONVERT10_E_FIRST equ 800401C0h
CONVERT10_E_LAST equ 800401CFh
CONVERT10_S_FIRST equ 000401C0h
CONVERT10_S_LAST equ 000401CFh

; OLESTREAM Get method failed
CONVERT10_E_OLESTREAM_GET equ 800401C0h

; OLESTREAM Put method failed
CONVERT10_E_OLESTREAM_PUT equ 800401C1h

; Contents of the OLESTREAM not in correct format
CONVERT10_E_OLESTREAM_FMT equ 800401C2h

; There was an error in a Windows GDI call while converting the bitmap to a DIB
CONVERT10_E_OLESTREAM_BITMAP_TO_DIB equ 800401C3h

; Contents of the IStorage not in correct format
CONVERT10_E_STG_FMT equ 800401C4h

; Contents of IStorage is missing one of the standard streams
CONVERT10_E_STG_NO_STD_STREAM equ 800401C5h

; There was an error in a Windows GDI call while converting the DIB to a bitmap.
;
CONVERT10_E_STG_DIB_TO_BITMAP equ 800401C6h

CLIPBRD_E_FIRST equ 800401D0h
CLIPBRD_E_LAST equ 800401DFh
CLIPBRD_S_FIRST equ 000401D0h
CLIPBRD_S_LAST equ 000401DFh

; OpenClipboard Failed
CLIPBRD_E_CANT_OPEN equ 800401D0h

; EmptyClipboard Failed
CLIPBRD_E_CANT_EMPTY equ 800401D1h

; SetClipboard Failed
CLIPBRD_E_CANT_SET equ 800401D2h

; Data on clipboard is invalid
CLIPBRD_E_BAD_DATA equ 800401D3h

; CloseClipboard Failed
CLIPBRD_E_CANT_CLOSE equ 800401D4h

MK_E_FIRST equ 800401E0h
MK_E_LAST equ 800401EFh
MK_S_FIRST equ 000401E0h
MK_S_LAST equ 000401EFh

; Moniker needs to be connected manually
MK_E_CONNECTMANUALLY equ 800401E0h

; Operation exceeded deadline
MK_E_EXCEEDEDDEADLINE equ 800401E1h

; Moniker needs to be generic
MK_E_NEEDGENERIC equ 800401E2h

; Operation unavailable
MK_E_UNAVAILABLE equ 800401E3h

; Invalid syntax
MK_E_SYNTAX equ 800401E4h

; No object for moniker
MK_E_NOOBJECT equ 800401E5h

; Bad extension for file
MK_E_INVALIDEXTENSION equ 800401E6h

; Intermediate operation failed
MK_E_INTERMEDIATEINTERFACENOTSUPPORTED equ 800401E7h

; Moniker is not bindable
MK_E_NOTBINDABLE equ 800401E8h

; Moniker is not bound
MK_E_NOTBOUND equ 800401E9h

; Moniker cannot open file
MK_E_CANTOPENFILE equ 800401EAh

; User input required for operation to succeed
MK_E_MUSTBOTHERUSER equ 800401EBh

; Moniker class has no inverse
MK_E_NOINVERSE equ 800401ECh

; Moniker does not refer to storage
MK_E_NOSTORAGE equ 800401EDh

; No common prefix
MK_E_NOPREFIX equ 800401EEh

; Moniker could not be enumerated
MK_E_ENUMERATION_FAILED equ 800401EFh

CO_E_FIRST equ 800401F0h
CO_E_LAST equ 800401FFh
CO_S_FIRST equ 000401F0h
CO_S_LAST equ 000401FFh

; CoInitialize has not been called.
CO_E_NOTINITIALIZED equ 800401F0h

; CoInitialize has already been called.
CO_E_ALREADYINITIALIZED equ 800401F1h

; Class of object cannot be determined
CO_E_CANTDETERMINECLASS equ 800401F2h

; Invalid class string
CO_E_CLASSSTRING equ 800401F3h

; Invalid interface string
CO_E_IIDSTRING equ 800401F4h

; Application not found
CO_E_APPNOTFOUND equ 800401F5h

; Application cannot be run more than once
CO_E_APPSINGLEUSE equ 800401F6h

; Some error in application program
CO_E_ERRORINAPP equ 800401F7h

; DLL for class not found
CO_E_DLLNOTFOUND equ 800401F8h

; Error in the DLL
CO_E_ERRORINDLL equ 800401F9h

; Wrong OS or OS version for application
CO_E_WRONGOSFORAPP equ 800401FAh

; Object is not registered
CO_E_OBJNOTREG equ 800401FBh

; Object is already registered
CO_E_OBJISREG equ 800401FCh

; Object is not connected to server
CO_E_OBJNOTCONNECTED equ 800401FDh

; Application was launched but it didn't register a class factory
CO_E_APPDIDNTREG equ 800401FEh

; Object has been released
CO_E_RELEASED equ 800401FFh

EVENT_E_FIRST equ 80040200h
EVENT_E_LAST equ 8004021Fh
EVENT_S_FIRST equ 00040200h
EVENT_S_LAST equ 0004021Fh

; An event was able to invoke some but not all of the subscribers
EVENT_S_SOME_SUBSCRIBERS_FAILED equ 00040200h

; An event was unable to invoke any of the subscribers
EVENT_E_ALL_SUBSCRIBERS_FAILED equ 80040201h

; An event was delivered but there were no subscribers
EVENT_S_NOSUBSCRIBERS equ 00040202h

; A syntax error occurred trying to evaluate a query string
EVENT_E_QUERYSYNTAX equ 80040203h

; An invalid field name was used in a query string
EVENT_E_QUERYFIELD equ 80040204h

; An unexpected exception was raised
EVENT_E_INTERNALEXCEPTION equ 80040205h

; An unexpected internal error was detected
EVENT_E_INTERNALERROR equ 80040206h

; The owner SID on a per-user subscription doesn't exist
EVENT_E_INVALID_PER_USER_SID equ 80040207h

; A user-supplied component or subscriber raised an exception
EVENT_E_USER_EXCEPTION equ 80040208h

; An interface has too many methods to fire events from
EVENT_E_TOO_MANY_METHODS equ 80040209h

; A subscription cannot be stored unless its event class already exists
EVENT_E_MISSING_EVENTCLASS equ 8004020Ah

; Not all the objects requested could be removed
EVENT_E_NOT_ALL_REMOVED equ 8004020Bh

; COM+ is required for this operation, but is not installed
EVENT_E_COMPLUS_NOT_INSTALLED equ 8004020Ch

; Cannot modify or delete an object that was not added using the COM+ Admin SDK
EVENT_E_CANT_MODIFY_OR_DELETE_UNCONFIGURED_OBJECT equ 8004020Dh

; Cannot modify or delete an object that was added using the COM+ Admin SDK
EVENT_E_CANT_MODIFY_OR_DELETE_CONFIGURED_OBJECT equ 8004020Eh

; The event class for this subscription is in an invalid partition
EVENT_E_INVALID_EVENT_CLASS_PARTITION equ 8004020Fh

; The owner of the PerUser subscription is not logged on to the system specified
EVENT_E_PER_USER_SID_NOT_LOGGED_ON equ 80040210h

XACT_E_FIRST  equ 8004D000h
;XACT_E_LAST   equ 8004D029h
XACT_S_FIRST  equ 0004D000h
XACT_S_LAST   equ 0004D010h

; Another single phase resource manager has already been enlisted in this transaction.
XACT_E_ALREADYOTHERSINGLEPHASE equ 8004D000h

; A retaining commit or abort is not supported
XACT_E_CANTRETAIN equ 8004D001h

; The transaction failed to commit for an unknown reason. The transaction was aborted.
XACT_E_COMMITFAILED equ 8004D002h

; Cannot call commit on this transaction object because the calling application did not initiate the transaction.
XACT_E_COMMITPREVENTED equ 8004D003h

; Instead of committing, the resource heuristically aborted.
XACT_E_HEURISTICABORT equ 8004D004h

; Instead of aborting, the resource heuristically committed.
XACT_E_HEURISTICCOMMIT equ 8004D005h

; Some of the states of the resource were committed while others were aborted, likely because of heuristic decisions.
XACT_E_HEURISTICDAMAGE equ 8004D006h

; Some of the states of the resource may have been committed while others may have been aborted, likely because of heuristic decisions.
XACT_E_HEURISTICDANGER equ 8004D007h

; The requested isolation level is not valid or supported.
XACT_E_ISOLATIONLEVEL equ 8004D008h

; The transaction manager doesn't support an asynchronous operation for this method.
XACT_E_NOASYNC equ 8004D009h

; Unable to enlist in the transaction.
XACT_E_NOENLIST equ 8004D00Ah

; The requested semantics of retention of isolation across retaining commit and abort boundaries cannot be supported by this transaction implementation, or isoFlags was not equal to zero.
XACT_E_NOISORETAIN equ 8004D00Bh

; There is no resource presently associated with this enlistment
XACT_E_NORESOURCE equ 8004D00Ch

; The transaction failed to commit due to the failure of optimistic concurrency control in at least one of the resource managers.
XACT_E_NOTCURRENT equ 8004D00Dh

; The transaction has already been implicitly or explicitly committed or aborted
XACT_E_NOTRANSACTION equ 8004D00Eh

; An invalid combination of flags was specified
XACT_E_NOTSUPPORTED equ 8004D00Fh

; The resource manager id is not associated with this transaction or the transaction manager.
XACT_E_UNKNOWNRMGRID equ 8004D010h

; This method was called in the wrong state
XACT_E_WRONGSTATE equ 8004D011h

; The indicated unit of work does not match the unit of work expected by the resource manager.
XACT_E_WRONGUOW equ 8004D012h

; An enlistment in a transaction already exists.
XACT_E_XTIONEXISTS equ 8004D013h

; An import object for the transaction could not be found.
XACT_E_NOIMPORTOBJECT equ 8004D014h

; The transaction cookie is invalid.
XACT_E_INVALIDCOOKIE equ 8004D015h

; The transaction status is in doubt. A communication failure occurred, or a transaction manager or resource manager has failed
XACT_E_INDOUBT equ 8004D016h

; A time-out was specified, but time-outs are not supported.
XACT_E_NOTIMEOUT equ 8004D017h

; The requested operation is already in progress for the transaction.
XACT_E_ALREADYINPROGRESS equ 8004D018h

; The transaction has already been aborted.
XACT_E_ABORTED equ 8004D019h

; The Transaction Manager returned a log full error.
XACT_E_LOGFULL equ 8004D01Ah

; The Transaction Manager is not available.
XACT_E_TMNOTAVAILABLE equ 8004D01Bh

; A connection with the transaction manager was lost.
XACT_E_CONNECTION_DOWN equ 8004D01Ch

; A request to establish a connection with the transaction manager was denied.
XACT_E_CONNECTION_DENIED equ 8004D01Dh

; Resource manager reenlistment to determine transaction status timed out.
XACT_E_REENLISTTIMEOUT equ 8004D01Eh

; This transaction manager failed to establish a connection with another TIP transaction manager.
XACT_E_TIP_CONNECT_FAILED equ 8004D01Fh

; This transaction manager encountered a protocol error with another TIP transaction manager.
XACT_E_TIP_PROTOCOL_ERROR equ 8004D020h

; This transaction manager could not propagate a transaction from another TIP transaction manager.
XACT_E_TIP_PULL_FAILED equ 8004D021h

; The Transaction Manager on the destination machine is not available.
XACT_E_DEST_TMNOTAVAILABLE equ 8004D022h

; The Transaction Manager has disabled its support for TIP.
XACT_E_TIP_DISABLED equ 8004D023h

; The transaction manager has disabled its support for remote/network transactions.
XACT_E_NETWORK_TX_DISABLED equ 8004D024h

; The partner transaction manager has disabled its support for remote/network transactions.
XACT_E_PARTNER_NETWORK_TX_DISABLED equ 8004D025h

; The transaction manager has disabled its support for XA transactions.
XACT_E_XA_TX_DISABLED equ 8004D026h

; MSDTC was unable to read its configuration information.
XACT_E_UNABLE_TO_READ_DTC_CONFIG equ 8004D027h

; MSDTC was unable to load the dtc proxy dll.
XACT_E_UNABLE_TO_LOAD_DTC_PROXY equ 8004D028h

; The local transaction has aborted.
XACT_E_ABORTING equ 8004D029h

; TXF & CRM errors start 4d080.
XACT_E_CLERKNOTFOUND equ 8004D080h
XACT_E_CLERKEXISTS equ 8004D081h
XACT_E_RECOVERYINPROGRESS equ 8004D082h
XACT_E_TRANSACTIONCLOSED equ 8004D083h
XACT_E_INVALIDLSN equ 8004D084h
XACT_E_REPLAYREQUEST equ 8004D085h

; OleTx Success codes.
;
; An asynchronous operation was specified. The operation has begun, but its outcome is not known yet.
XACT_S_ASYNC equ 0004D000h

; XACT_S_DEFECT
XACT_S_DEFECT equ 0004D001h

; The method call succeeded because the transaction was read-only.
XACT_S_READONLY equ 0004D002h

; The transaction was successfully aborted. However, this is a coordinated transaction, and some number of enlisted resources were aborted outright because they could not support abort-retaining semantics
XACT_S_SOMENORETAIN equ 0004D003h

; No changes were made during this call, but the sink wants another chance to look if any other sinks make further changes.
XACT_S_OKINFORM equ 0004D004h

; The sink is content and wishes the transaction to proceed. Changes were made to one or more resources during this call.
XACT_S_MADECHANGESCONTENT equ 0004D005h

; The sink is for the moment and wishes the transaction to proceed, but if other changes are made following this return by other event sinks then this sink wants another chance to look
XACT_S_MADECHANGESINFORM equ 0004D006h

; The transaction was successfully aborted. However, the abort was non-retaining.
XACT_S_ALLNORETAIN equ 0004D007h

; An abort operation was already in progress.
XACT_S_ABORTING equ 0004D008h

; The resource manager has performed a single-phase commit of the transaction.
XACT_S_SINGLEPHASE equ 0004D009h

; The local transaction has not aborted.
XACT_S_LOCALLY_OK equ 0004D00Ah

; The resource manager has requested to be the coordinator (last resource manager) for the transaction.
XACT_S_LASTRESOURCEMANAGER equ 0004D010h

CONTEXT_E_FIRST equ 8004E000h
CONTEXT_E_LAST equ 8004E02Fh
CONTEXT_S_FIRST equ 0004E000h
CONTEXT_S_LAST equ 0004E02Fh

; The root transaction wanted to commit, but transaction aborted
CONTEXT_E_ABORTED equ 8004E002h

; You made a method call on a COM+ component that has a transaction that has already aborted or in the process of aborting.
CONTEXT_E_ABORTING equ 8004E003h

; There is no MTS object context
CONTEXT_E_NOCONTEXT equ 8004E004h

; The component is configured to use synchronization and a thread has timed out waiting to enter the context.
CONTEXT_E_SYNCH_TIMEOUT equ 8004E006h

; You made a method call on a COM+ component that has a transaction that has already committed or aborted.
CONTEXT_E_OLDREF equ 8004E007h

; The specified role was not configured for the application
CONTEXT_E_ROLENOTFOUND equ 8004E00Ch

; COM+ was unable to talk to the Microsoft Distributed Transaction Coordinator
CONTEXT_E_TMNOTAVAILABLE equ 8004E00Fh

; An unexpected error occurred during COM+ Activation.
CO_E_ACTIVATIONFAILED equ 8004E021h

; COM+ Activation failed. Check the event log for more information
CO_E_ACTIVATIONFAILED_EVENTLOGGED equ 8004E022h

; COM+ Activation failed due to a catalog or configuration error.
CO_E_ACTIVATIONFAILED_CATALOGERROR equ 8004E023h

; COM+ activation failed because the activation could not be completed in the specified amount of time.
CO_E_ACTIVATIONFAILED_TIMEOUT equ 8004E024h

; COM+ Activation failed because an initialization function failed. Check the event log for more information.
CO_E_INITIALIZATIONFAILED equ 8004E025h

; The requested operation requires that JIT be in the current context and it is not
CONTEXT_E_NOJIT equ 8004E026h

; The requested operation requires that the current context have a Transaction, and it does not
CONTEXT_E_NOTRANSACTION equ 8004E027h

; The components threading model has changed after install into a COM+ Application. Please re-install component.
CO_E_THREADINGMODEL_CHANGED equ 8004E028h

; IIS intrinsics not available. Start your work with IIS.
CO_E_NOIISINTRINSICS equ 8004E029h

; An attempt to write a cookie failed.
CO_E_NOCOOKIES equ 8004E02Ah

; An attempt to use a database generated a database specific error.
CO_E_DBERROR equ 8004E02Bh

; The COM+ component you created must use object pooling to work.
CO_E_NOTPOOLED equ 8004E02Ch

; The COM+ component you created must use object construction to work correctly.
CO_E_NOTCONSTRUCTED equ 8004E02Dh

; The COM+ component requires synchronization, and it is not configured for it.
CO_E_NOSYNCHRONIZATION equ 8004E02Eh

; The TxIsolation Level property for the COM+ component being created is stronger than the TxIsolationLevel for the "root" component for the transaction. The creation failed.
CO_E_ISOLEVELMISMATCH equ 8004E02Fh

; Old OLE Success Codes
;
; Use the registry database to provide the requested information
OLE_S_USEREG equ 00040000h

; Success, but static
OLE_S_STATIC equ 00040001h

; Macintosh clipboard format
OLE_S_MAC_CLIPFORMAT equ 00040002h

; Successful drop took place
DRAGDROP_S_DROP equ 00040100h

; Drag-drop operation canceled
DRAGDROP_S_CANCEL equ 00040101h

; Use the default cursor
DRAGDROP_S_USEDEFAULTCURSORS equ 00040102h

; Data has same FORMATETC
DATA_S_SAMEFORMATETC equ 00040130h

; View is already frozen
VIEW_S_ALREADY_FROZEN equ 00040140h

; FORMATETC not supported
CACHE_S_FORMATETC_NOTSUPPORTED equ 00040170h

; Same cache
CACHE_S_SAMECACHE equ 00040171h

; Some cache(s) not updated
CACHE_S_SOMECACHES_NOTUPDATED equ 00040172h

; Invalid verb for OLE object
OLEOBJ_S_INVALIDVERB equ 00040180h

; Verb number is valid but verb cannot be done now
OLEOBJ_S_CANNOT_DOVERB_NOW equ 00040181h

; Invalid window HANDLE passed
OLEOBJ_S_INVALIDHWND equ 00040182h

; Message is too long; some of it had to be truncated before displaying
INPLACE_S_TRUNCATED equ 000401A0h

; Unable to convert OLESTREAM to IStorage
CONVERT10_S_NO_PRESENTATION equ 000401C0h

; Moniker reduced to itself
MK_S_REDUCED_TO_SELF equ 000401E2h

; Common prefix is this moniker
MK_S_ME equ 000401E4h

; Common prefix is input moniker
MK_S_HIM equ 000401E5h

; Common prefix is both monikers
MK_S_US equ 000401E6h

; Moniker is already registered in running object table
MK_S_MONIKERALREADYREGISTERED equ 000401E7h

; Task Scheduler errors
;
; The task is ready to run at its next scheduled time.
SCHED_S_TASK_READY equ 00041300h

; The task is currently running.
SCHED_S_TASK_RUNNING equ 00041301h

; The task will not run at the scheduled times because it has been disabled.
SCHED_S_TASK_DISABLED equ 00041302h

; The task has not yet run.
SCHED_S_TASK_HAS_NOT_RUN equ 00041303h

; There are no more runs scheduled for this task.
SCHED_S_TASK_NO_MORE_RUNS equ 00041304h

; One or more of the properties that are needed to run this task on a schedule have not been set.
SCHED_S_TASK_NOT_SCHEDULED equ 00041305h

; The last run of the task was terminated by the user.
SCHED_S_TASK_TERMINATED equ 00041306h

; Either the task has no triggers or the existing triggers are disabled or not set.
SCHED_S_TASK_NO_VALID_TRIGGERS equ 00041307h

; Event triggers don't have set run times.
SCHED_S_EVENT_TRIGGER equ 00041308h

; Trigger not found.
SCHED_E_TRIGGER_NOT_FOUND equ 80041309h

; One or more of the properties that are needed to run this task have not been set.
SCHED_E_TASK_NOT_READY equ 8004130Ah

; There is no running instance of the task to terminate.
SCHED_E_TASK_NOT_RUNNING equ 8004130Bh

; The Task Scheduler Service is not installed on this computer.
SCHED_E_SERVICE_NOT_INSTALLED equ 8004130Ch

; The task object could not be opened.
SCHED_E_CANNOT_OPEN_TASK equ 8004130Dh

; The object is either an invalid task object or is not a task object.
SCHED_E_INVALID_TASK equ 8004130Eh

; No account information could be found in the Task Scheduler security database for the task indicated.
SCHED_E_ACCOUNT_INFORMATION_NOT_SET equ 8004130Fh

; Unable to establish existence of the account specified.
SCHED_E_ACCOUNT_NAME_NOT_FOUND equ 80041310h

; Corruption was detected in the Task Scheduler security database; the database has been reset.
SCHED_E_ACCOUNT_DBASE_CORRUPT equ 80041311h

; Task Scheduler security services are available only on Windows NT.
SCHED_E_NO_SECURITY_SERVICES equ 80041312h

; The task object version is either unsupported or invalid.
SCHED_E_UNKNOWN_OBJECT_VERSION equ 80041313h

; The task has been configured with an unsupported combination of account settings and run time options.
SCHED_E_UNSUPPORTED_ACCOUNT_OPTION equ 80041314h

; The Task Scheduler Service is not running.
SCHED_E_SERVICE_NOT_RUNNING equ 80041315h

; ******************
; FACILITY_WINDOWS
; ******************
; Codes 0000h-01FFh are reserved for the OLE group of interfaces.
;
; Attempt to create a class object failed
CO_E_CLASS_CREATE_FAILED equ 80080001h

; OLE service could not bind object
CO_E_SCM_ERROR equ 80080002h

; RPC communication failed with OLE service
CO_E_SCM_RPC_FAILURE equ 80080003h

; Bad path to object
CO_E_BAD_PATH equ 80080004h

; Server execution failed
CO_E_SERVER_EXEC_FAILURE equ 80080005h

; OLE service could not communicate with the object server
CO_E_OBJSRV_RPC_FAILURE equ 80080006h

; Moniker path could not be normalized
MK_E_NO_NORMALIZED equ 80080007h

; Object server is stopping when OLE service contacts it
CO_E_SERVER_STOPPING equ 80080008h

; An invalid root block pointer was specified
MEM_E_INVALID_ROOT equ 80080009h

; An allocation chain contained an invalid link pointer
MEM_E_INVALID_LINK equ 80080010h

; The requested allocation size was too large
MEM_E_INVALID_SIZE equ 80080011h

; Not all the requested interfaces were available
CO_S_NOTALLINTERFACES equ 00080012h

; The specified machine name was not found in the cache.
CO_S_MACHINENAMENOTFOUND equ 00080013h

; ******************
; FACILITY_DISPATCH
; ******************

; Unknown interface.
DISP_E_UNKNOWNINTERFACE equ 80020001h

; Member not found.
DISP_E_MEMBERNOTFOUND equ 80020003h

; Parameter not found.
DISP_E_PARAMNOTFOUND equ 80020004h

; Type mismatch.
DISP_E_TYPEMISMATCH equ 80020005h

; Unknown name.
DISP_E_UNKNOWNNAME equ 80020006h

; No named arguments.
DISP_E_NONAMEDARGS equ 80020007h

; Bad variable type.
DISP_E_BADVARTYPE equ 80020008h

; Exception occurred.
DISP_E_EXCEPTION equ 80020009h

; Out of present range.
DISP_E_OVERFLOW equ 8002000Ah

; Invalid index.
DISP_E_BADINDEX equ 8002000Bh

; Unknown language.
DISP_E_UNKNOWNLCID equ 8002000Ch

; Memory is locked.
DISP_E_ARRAYISLOCKED equ 8002000Dh

; Invalid number of parameters.
DISP_E_BADPARAMCOUNT equ 8002000Eh

; Parameter not optional.
DISP_E_PARAMNOTOPTIONAL equ 8002000Fh

; Invalid callee.
DISP_E_BADCALLEE equ 80020010h

; Does not support a collection.
DISP_E_NOTACOLLECTION equ 80020011h

; Division by zero.
DISP_E_DIVBYZERO equ 80020012h

; Buffer too small
DISP_E_BUFFERTOOSMALL equ 80020013h

; Buffer too small.
TYPE_E_BUFFERTOOSMALL equ 80028016h

; Field name not defined in the record.
TYPE_E_FIELDNOTFOUND equ 80028017h

; Old format or invalid type library.
TYPE_E_INVDATAREAD equ 80028018h

; Old format or invalid type library.
TYPE_E_UNSUPFORMAT equ 80028019h

; Error accessing the OLE registry.
TYPE_E_REGISTRYACCESS equ 8002801Ch

; Library not registered.
TYPE_E_LIBNOTREGISTERED equ 8002801Dh

; Bound to unknown type.
TYPE_E_UNDEFINEDTYPE equ 80028027h

; Qualified name disallowed.
TYPE_E_QUALIFIEDNAMEDISALLOWED equ 80028028h

; Invalid forward reference, or reference to uncompiled type.
TYPE_E_INVALIDSTATE equ 80028029h

; Type mismatch.
TYPE_E_WRONGTYPEKIND equ 8002802Ah

; Element not found.
TYPE_E_ELEMENTNOTFOUND equ 8002802Bh

; Ambiguous name.
TYPE_E_AMBIGUOUSNAME equ 8002802Ch

; Name already exists in the library.
TYPE_E_NAMECONFLICT equ 8002802Dh

; Unknown LCID.
TYPE_E_UNKNOWNLCID equ 8002802Eh

; Function not defined in specified DLL.
TYPE_E_DLLFUNCTIONNOTFOUND equ 8002802Fh

; Wrong module kind for the operation.
TYPE_E_BADMODULEKIND equ 800288BDh

; Size may not exceed 64K.
TYPE_E_SIZETOOBIG equ 800288C5h

; Duplicate ID in inheritance hierarchy.
TYPE_E_DUPLICATEID equ 800288C6h

; Incorrect inheritance depth in standard OLE hmember.
TYPE_E_INVALIDID equ 800288CFh

; Type mismatch.
TYPE_E_TYPEMISMATCH equ 80028CA0h

; Invalid number of arguments.
TYPE_E_OUTOFBOUNDS equ 80028CA1h

; I/O Error.
TYPE_E_IOERROR equ 80028CA2h

; Error creating unique tmp file.
TYPE_E_CANTCREATETMPFILE equ 80028CA3h

; Error loading type library/DLL.
TYPE_E_CANTLOADLIBRARY equ 80029C4Ah

; Inconsistent property functions.
TYPE_E_INCONSISTENTPROPFUNCS equ 80029C83h

; Circular dependency between types/modules.
TYPE_E_CIRCULARTYPE equ 80029C84h

; ******************
; FACILITY_STORAGE
; ******************
; Unable to perform requested operation.
STG_E_INVALIDFUNCTION equ 80030001h

; %1 could not be found.
STG_E_FILENOTFOUND equ 80030002h

; The path %1 could not be found.
STG_E_PATHNOTFOUND equ 80030003h

; There are insufficient resources to open another file.
STG_E_TOOMANYOPENFILES equ 80030004h

; Access Denied.
STG_E_ACCESSDENIED equ 80030005h

; Attempted an operation on an invalid object.
STG_E_INVALIDHANDLE equ 80030006h

; There is insufficient memory available to complete operation.
STG_E_INSUFFICIENTMEMORY equ 80030008h

; Invalid pointer error.
STG_E_INVALIDPOINTER equ 80030009h

; There are no more entries to return.
STG_E_NOMOREFILES equ 80030012h

; Disk is write-protected.
STG_E_DISKISWRITEPROTECTED equ 80030013h

; An error occurred during a seek operation.
STG_E_SEEKERROR equ 80030019h

; A disk error occurred during a write operation.
STG_E_WRITEFAULT equ 8003001Dh

; A disk error occurred during a read operation.
STG_E_READFAULT equ 8003001Eh

; A share violation has occurred.
STG_E_SHAREVIOLATION equ 80030020h

; A lock violation has occurred.
STG_E_LOCKVIOLATION equ 80030021h

; %1 already exists.
STG_E_FILEALREADYEXISTS equ 80030050h

; Invalid parameter error.
STG_E_INVALIDPARAMETER equ 80030057h

; There is insufficient disk space to complete operation.
STG_E_MEDIUMFULL equ 80030070h

; Illegal write of non-simple property to simple property set.
STG_E_PROPSETMISMATCHED equ 800300F0h

; An API call exited abnormally.
STG_E_ABNORMALAPIEXIT equ 800300FAh

; The file %1 is not a valid compound file.
STG_E_INVALIDHEADER equ 800300FBh

; The name %1 is not valid.
STG_E_INVALIDNAME equ 800300FCh

; An unexpected error occurred.
STG_E_UNKNOWN equ 800300FDh

; That function is not implemented.
STG_E_UNIMPLEMENTEDFUNCTION equ 800300FEh

; Invalid flag error.
STG_E_INVALIDFLAG equ 800300FFh

; Attempted to use an object that is busy.
STG_E_INUSE equ 80030100h

; The storage has been changed since the last commit.
STG_E_NOTCURRENT equ 80030101h

; Attempted to use an object that has ceased to exist.
STG_E_REVERTED equ 80030102h

; Can't save.
STG_E_CANTSAVE equ 80030103h

; The compound file %1 was produced with an incompatible version of storage.
STG_E_OLDFORMAT equ 80030104h

; The compound file %1 was produced with a newer version of storage.
STG_E_OLDDLL equ 80030105h

; Share.exe or equivalent is required for operation.
STG_E_SHAREREQUIRED equ 80030106h

; Illegal operation called on non-file based storage.
STG_E_NOTFILEBASEDSTORAGE equ 80030107h

; Illegal operation called on object with extant marshallings.
STG_E_EXTANTMARSHALLINGS equ 80030108h

; The docfile has been corrupted.
STG_E_DOCFILECORRUPT equ 80030109h

; Ole32.DLL has been loaded at the wrong address.
STG_E_BADBASEADDRESS equ 80030110h

; The compound file is too large for the current implementation
STG_E_DOCFILETOOLARGE equ 80030111h

; The compound file was not created with the STGM_SIMPLE flag
STG_E_NOTSIMPLEFORMAT equ 80030112h

; The file download was aborted abnormally. The file is incomplete.
STG_E_INCOMPLETE equ 80030201h

; The file download has been terminated.
STG_E_TERMINATED equ 80030202h

; The underlying file was converted to compound file format.
STG_S_CONVERTED equ 00030200h

; The storage operation should block until more data is available.
STG_S_BLOCK equ 00030201h

; The storage operation should retry immediately.
STG_S_RETRYNOW equ 00030202h

; The notified event sink will not influence the storage operation.
STG_S_MONITORING equ 00030203h

; Multiple opens prevent consolidated. (commit succeeded).
STG_S_MULTIPLEOPENS equ 00030204h

; Consolidation of the storage file failed. (commit succeeded).
STG_S_CONSOLIDATIONFAILED equ 00030205h

; Consolidation of the storage file is inappropriate. (commit succeeded).
STG_S_CANNOTCONSOLIDATE equ 00030206h


; MessageId's 0305h - 031Fh (inclusive) are reserved for **STORAGE**
; copy protection errors.

; Generic Copy Protection Error.
STG_E_STATUS_COPY_PROTECTION_FAILURE equ 80030305h

; Copy Protection Error - DVD CSS Authentication failed.
STG_E_CSS_AUTHENTICATION_FAILURE equ 80030306h

; Copy Protection Error - The given sector does not have a valid CSS key.
STG_E_CSS_KEY_NOT_PRESENT equ 80030307h

; Copy Protection Error - DVD session key not established.
STG_E_CSS_KEY_NOT_ESTABLISHED equ 80030308h

; Copy Protection Error - The read failed because the sector is encrypted.
STG_E_CSS_SCRAMBLED_SECTOR equ 80030309h

; Copy Protection Error - The current DVD's region does not correspond to the region setting of the drive.
STG_E_CSS_REGION_MISMATCH equ 8003030Ah

; Copy Protection Error - The drive's region setting may be permanent or the number of user resets has been exhausted.
STG_E_RESETS_EXHAUSTED equ 8003030Bh

; MessageId's 0305h - 031Fh (inclusive) are reserved for **STORAGE** copy protection errors.

; ******************
; FACILITY_RPC
; ******************
; Codes 00h-11h are propagated from 16 bit OLE.

; Call was rejected by callee.
RPC_E_CALL_REJECTED equ 80010001h

; Call was canceled by the message filter.
RPC_E_CALL_CANCELED equ 80010002h

; The caller is dispatching an intertask SendMessage call and cannot call out via PostMessage.
RPC_E_CANTPOST_INSENDCALL equ 80010003h

; The caller is dispatching an asynchronous call and cannot make an outgoing call on behalf of this call.
RPC_E_CANTCALLOUT_INASYNCCALL equ 80010004h

; It is illegal to call out while inside message filter.
RPC_E_CANTCALLOUT_INEXTERNALCALL equ 80010005h

; The connection terminated or is in a bogus state and cannot be used any more. Other connections are still valid.
RPC_E_CONNECTION_TERMINATED equ 80010006h

; The callee (server [not server application]) is not available and disappeared; all connections are invalid. The call may have executed.
RPC_E_SERVER_DIED equ 80010007h

; The caller (client) disappeared while the callee (server) was processing a call.
RPC_E_CLIENT_DIED equ 80010008h

; The data packet with the marshalled parameter data is incorrect.
RPC_E_INVALID_DATAPACKET equ 80010009h

; The call was not transmitted properly; the message queue was full and was not emptied after yielding.
RPC_E_CANTTRANSMIT_CALL equ 8001000Ah

; The client (caller) cannot marshall the parameter data - low memory, etc.
RPC_E_CLIENT_CANTMARSHAL_DATA equ 8001000Bh

; The client (caller) cannot unmarshall the return data - low memory, etc.
RPC_E_CLIENT_CANTUNMARSHAL_DATA equ 8001000Ch

; The server (callee) cannot marshall the return data - low memory, etc.
RPC_E_SERVER_CANTMARSHAL_DATA equ 8001000Dh

; The server (callee) cannot unmarshall the parameter data - low memory, etc.
RPC_E_SERVER_CANTUNMARSHAL_DATA equ 8001000Eh

; Received data is invalid; could be server or client data.
RPC_E_INVALID_DATA equ 8001000Fh

; A particular parameter is invalid and cannot be (un)marshalled.
RPC_E_INVALID_PARAMETER equ 80010010h

; There is no second outgoing call on same channel in DDE conversation.
RPC_E_CANTCALLOUT_AGAIN equ 80010011h

; The callee (server [not server application]) is not available and disappeared; all connections are invalid. The call did not execute.
RPC_E_SERVER_DIED_DNE equ 80010012h

; System call failed.
RPC_E_SYS_CALL_FAILED equ 80010100h

; Could not allocate some required resource (memory, events, ...)
RPC_E_OUT_OF_RESOURCES equ 80010101h

; Attempted to make calls on more than one thread in single threaded mode.
RPC_E_ATTEMPTED_MULTITHREAD equ 80010102h

; The requested interface is not registered on the server object.
RPC_E_NOT_REGISTERED equ 80010103h

; RPC could not call the server or could not return the results of calling the server.
RPC_E_FAULT equ 80010104h

; The server threw an exception.
RPC_E_SERVERFAULT equ 80010105h

; Cannot change thread mode after it is set.
RPC_E_CHANGED_MODE equ 80010106h

; The method called does not exist on the server.
RPC_E_INVALIDMETHOD equ 80010107h

; The object invoked has disconnected from its clients.
RPC_E_DISCONNECTED equ 80010108h

; The object invoked chose not to process the call now. Try again later.
RPC_E_RETRY equ 80010109h

; The message filter indicated that the application is busy.
RPC_E_SERVERCALL_RETRYLATER equ 8001010Ah

; The message filter rejected the call.
RPC_E_SERVERCALL_REJECTED equ 8001010Bh

; A call control interfaces was called with invalid data.
RPC_E_INVALID_CALLDATA equ 8001010Ch

; An outgoing call cannot be made since the application is dispatching an input-synchronous call.
RPC_E_CANTCALLOUT_ININPUTSYNCCALL equ 8001010Dh

; The application called an interface that was marshalled for a different thread.
RPC_E_WRONG_THREAD equ 8001010Eh

; CoInitialize has not been called on the current thread.
RPC_E_THREAD_NOT_INIT equ 8001010Fh

; The version of OLE on the client and server machines does not match.
RPC_E_VERSION_MISMATCH equ 80010110h

; OLE received a packet with an invalid header.
RPC_E_INVALID_HEADER equ 80010111h

; OLE received a packet with an invalid extension.
RPC_E_INVALID_EXTENSION equ 80010112h

; The requested object or interface does not exist.
RPC_E_INVALID_IPID equ 80010113h

; The requested object does not exist.
RPC_E_INVALID_OBJECT equ 80010114h

; OLE has sent a request and is waiting for a reply.
RPC_S_CALLPENDING equ 80010115h

; OLE is waiting before retrying a request.
RPC_S_WAITONTIMER equ 80010116h

; Call context cannot be accessed after call completed.
RPC_E_CALL_COMPLETE equ 80010117h

; Impersonate on unsecure calls is not supported.
RPC_E_UNSECURE_CALL equ 80010118h

; Security must be initialized before any interfaces are marshalled or unmarshalled. It cannot be changed once initialized.
RPC_E_TOO_LATE equ 80010119h

; No security packages are installed on this machine or the user is not logged on or there are no compatible security packages between the client and server.
RPC_E_NO_GOOD_SECURITY_PACKAGES equ 8001011Ah

; Access is denied.
RPC_E_ACCESS_DENIED equ 8001011Bh

; Remote calls are not allowed for this process.
RPC_E_REMOTE_DISABLED equ 8001011Ch

; The marshaled interface data packet (OBJREF) has an invalid or unknown format.
RPC_E_INVALID_OBJREF equ 8001011Dh

; No context is associated with this call. This happens for some custom marshalled calls and on the client side of the call.
RPC_E_NO_CONTEXT equ 8001011Eh

; This operation returned because the timeout period expired.
RPC_E_TIMEOUT equ 8001011Fh

; There are no synchronize objects to wait on.
RPC_E_NO_SYNC equ 80010120h

; Full subject issuer chain SSL principal name expected from the server.
RPC_E_FULLSIC_REQUIRED equ 80010121h

; Principal name is not a valid MSSTD name.
RPC_E_INVALID_STD_NAME equ 80010122h

; Unable to impersonate DCOM client
CO_E_FAILEDTOIMPERSONATE equ 80010123h

; Unable to obtain server's security context
CO_E_FAILEDTOGETSECCTX equ 80010124h

; Unable to open the access token of the current thread
CO_E_FAILEDTOOPENTHREADTOKEN equ 80010125h

; Unable to obtain user info from an access token
CO_E_FAILEDTOGETTOKENINFO equ 80010126h

; The client who called IAccessControl::IsAccessPermitted was not the trustee provided to the method
CO_E_TRUSTEEDOESNTMATCHCLIENT equ 80010127h

; Unable to obtain the client's security blanket
CO_E_FAILEDTOQUERYCLIENTBLANKET equ 80010128h

; Unable to set a discretionary ACL into a security descriptor
CO_E_FAILEDTOSETDACL equ 80010129h

; The system function, AccessCheck, returned false
CO_E_ACCESSCHECKFAILED equ 8001012Ah

; Either NetAccessDel or NetAccessAdd returned an error code.
CO_E_NETACCESSAPIFAILED equ 8001012Bh

; One of the trustee strings provided by the user did not conform to the <Domain>\<Name> syntax and it was not the "*" string
CO_E_WRONGTRUSTEENAMESYNTAX equ 8001012Ch

; One of the security identifiers provided by the user was invalid
CO_E_INVALIDSID equ 8001012Dh

; Unable to convert a WIDE character trustee string to a multibyte trustee string
CO_E_CONVERSIONFAILED equ 8001012Eh

; Unable to find a security identifier that corresponds to a trustee string provided by the user
CO_E_NOMATCHINGSIDFOUND equ 8001012Fh

; The system function, LookupAccountSID, failed
CO_E_LOOKUPACCSIDFAILED equ 80010130h

; Unable to find a trustee name that corresponds to a security identifier provided by the user
CO_E_NOMATCHINGNAMEFOUND equ 80010131h

; The system function, LookupAccountName, failed
CO_E_LOOKUPACCNAMEFAILED equ 80010132h

; Unable to set or reset a serialization HANDLE
CO_E_SETSERLHNDLFAILED equ 80010133h

; Unable to obtain the Windows directory
CO_E_FAILEDTOGETWINDIR equ 80010134h

; Path too long
CO_E_PATHTOOLONG equ 80010135h

; Unable to generate a uuid.
CO_E_FAILEDTOGENUUID equ 80010136h

; Unable to create file
CO_E_FAILEDTOCREATEFILE equ 80010137h

; Unable to close a serialization HANDLE or a file HANDLE.
CO_E_FAILEDTOCLOSEHANDLE equ 80010138h

; The number of ACEs in an ACL exceeds the system limit.
CO_E_EXCEEDSYSACLLIMIT equ 80010139h

; Not all the DENY_ACCESS ACEs are arranged in front of the GRANT_ACCESS ACEs in the stream.
CO_E_ACESINWRONGORDER equ 8001013Ah

; The version of ACL format in the stream is not supported by this implementation of IAccessControl
CO_E_INCOMPATIBLESTREAMVERSION equ 8001013Bh

; Unable to open the access token of the server process
CO_E_FAILEDTOOPENPROCESSTOKEN equ 8001013Ch

; Unable to decode the ACL in the stream provided by the user
CO_E_DECODEFAILED equ 8001013Dh

; The COM IAccessControl object is not initialized
CO_E_ACNOTINITIALIZED equ 8001013Fh

; Call Cancellation is disabled
CO_E_CANCEL_DISABLED equ 80010140h

; An internal error occurred.
RPC_E_UNEXPECTED equ 8001FFFFh



;;;;;;;;;;;;;;;;;;;
;
; Additional Security Status Codes
;
; Facility=Security
;
;;;;;;;;;;;;;;;;;;;

; The specified event is currently not being audited.
ERROR_AUDITING_DISABLED equ 0C0090001h

; The SID filtering operation removed all SIDs.
ERROR_ALL_SIDS_FILTERED equ 0C0090002h



 ;;;;;;;;/

 ; FACILITY_SSPI

 ;;;;;;;;/

; Bad UID.
NTE_BAD_UID equ 80090001h

; Bad Hash.
NTE_BAD_HASH equ 80090002h

; Bad Key.
NTE_BAD_KEY equ 80090003h

; Bad Length.
NTE_BAD_LEN equ 80090004h

; Bad Data.
NTE_BAD_DATA equ 80090005h

; Invalid Signature.
NTE_BAD_SIGNATURE equ 80090006h

; Bad Version of provider.
NTE_BAD_VER equ 80090007h

; Invalid algorithm specified.
NTE_BAD_ALGID equ 80090008h

; Invalid flags specified.
NTE_BAD_FLAGS equ 80090009h

; Invalid type specified.
NTE_BAD_TYPE equ 8009000Ah

; Key not valid for use in specified state.
NTE_BAD_KEY_STATE equ 8009000Bh

; Hash not valid for use in specified state.
NTE_BAD_HASH_STATE equ 8009000Ch

; Key does not exist.
NTE_NO_KEY equ 8009000Dh

; Insufficient memory available for the operation.
NTE_NO_MEMORY equ 8009000Eh

; Object already exists.
NTE_EXISTS equ 8009000Fh

; Access denied.
NTE_PERM equ 80090010h

; Object was not found.
NTE_NOT_FOUND equ 80090011h

; Data already encrypted.
NTE_DOUBLE_ENCRYPT equ 80090012h

; Invalid provider specified.
NTE_BAD_PROVIDER equ 80090013h

; Invalid provider type specified.
NTE_BAD_PROV_TYPE equ 80090014h

; Provider's public key is invalid.
NTE_BAD_PUBLIC_KEY equ 80090015h

; Keyset does not exist
NTE_BAD_KEYSET equ 80090016h

; Provider type not defined.
NTE_PROV_TYPE_NOT_DEF equ 80090017h

; Provider type as registered is invalid.
NTE_PROV_TYPE_ENTRY_BAD equ 80090018h

; The keyset is not defined.
NTE_KEYSET_NOT_DEF equ 80090019h

; Keyset as registered is invalid.
NTE_KEYSET_ENTRY_BAD equ 8009001Ah

; Provider type does not match registered value.
NTE_PROV_TYPE_NO_MATCH equ 8009001Bh

; The digital signature file is corrupt.
NTE_SIGNATURE_FILE_BAD equ 8009001Ch

; Provider DLL failed to initialize correctly.
NTE_PROVIDER_DLL_FAIL equ 8009001Dh

; Provider DLL could not be found.
NTE_PROV_DLL_NOT_FOUND equ 8009001Eh

; The Keyset parameter is invalid.
NTE_BAD_KEYSET_PARAM equ 8009001Fh

; An internal error occurred.
NTE_FAIL equ 80090020h

; A base error occurred.
NTE_SYS_ERR equ 80090021h

; Provider could not perform the action since the context was acquired as silent.
NTE_SILENT_CONTEXT equ 80090022h

; The security token does not have storage space available for an additional container.
NTE_TOKEN_KEYSET_STORAGE_FULL equ 80090023h

; The profile for the user is a temporary profile.
NTE_TEMPORARY_PROFILE equ 80090024h

; The key parameters could not be set because the CSP uses fixed parameters.
NTE_FIXEDPARAMETER equ 80090025h

; Not enough memory is available to complete this request
SEC_E_INSUFFICIENT_MEMORY equ 80090300h

; The HANDLE specified is invalid
SEC_E_INVALID_HANDLE equ 80090301h

; The function requested is not supported
SEC_E_UNSUPPORTED_FUNCTION equ 80090302h

; The specified target is unknown or unreachable
SEC_E_TARGET_UNKNOWN equ 80090303h

; The Local Security Authority cannot be contacted
SEC_E_INTERNAL_ERROR equ 80090304h

; The requested security package does not exist
SEC_E_SECPKG_NOT_FOUND equ 80090305h

; The caller is not the owner of the desired credentials
SEC_E_NOT_OWNER equ 80090306h

; The security package failed to initialize, and cannot be installed
SEC_E_CANNOT_INSTALL equ 80090307h

; The token supplied to the function is invalid
SEC_E_INVALID_TOKEN equ 80090308h

; The security package is not able to marshall the logon buffer, so the logon attempt has failed
SEC_E_CANNOT_PACK equ 80090309h

; The per-message Quality of Protection is not supported by the security package
SEC_E_QOP_NOT_SUPPORTED equ 8009030Ah

; The security context does not allow impersonation of the client
SEC_E_NO_IMPERSONATION equ 8009030Bh

; The logon attempt failed
SEC_E_LOGON_DENIED equ 8009030Ch

; The credentials supplied to the package were not recognized
SEC_E_UNKNOWN_CREDENTIALS equ 8009030Dh

; No credentials are available in the security package
SEC_E_NO_CREDENTIALS equ 8009030Eh

; The message or signature supplied for verification has been altered
SEC_E_MESSAGE_ALTERED equ 8009030Fh

; The message supplied for verification is out of sequence
SEC_E_OUT_OF_SEQUENCE equ 80090310h

; No authority could be contacted for authentication.
SEC_E_NO_AUTHENTICATING_AUTHORITY equ 80090311h

; The function completed successfully, but must be called again to complete the context
SEC_I_CONTINUE_NEEDED equ 00090312h

; The function completed successfully, but CompleteToken must be called
SEC_I_COMPLETE_NEEDED equ 00090313h

; The function completed successfully, but both CompleteToken and this function must be called to complete the context
SEC_I_COMPLETE_AND_CONTINUE equ 00090314h

; The logon was completed, but no network authority was available. The logon was made using locally known information
SEC_I_LOCAL_LOGON equ 00090315h

; The requested security package does not exist
SEC_E_BAD_PKGID equ 80090316h

; The context has expired and can no longer be used.
SEC_E_CONTEXT_EXPIRED equ 80090317h

; The context has expired and can no longer be used.
SEC_I_CONTEXT_EXPIRED equ 00090317h

; The supplied message is incomplete. The signature was not verified.
SEC_E_INCOMPLETE_MESSAGE equ 80090318h

; The credentials supplied were not complete, and could not be verified. The context could not be initialized.
SEC_E_INCOMPLETE_CREDENTIALS equ 80090320h

; The buffers supplied to a function was too small.
SEC_E_BUFFER_TOO_SMALL equ 80090321h

; The credentials supplied were not complete, and could not be verified. Additional information can be returned from the context.
SEC_I_INCOMPLETE_CREDENTIALS equ 00090320h

; The context data must be renegotiated with the peer.
SEC_I_RENEGOTIATE equ 00090321h

; The target principal name is incorrect.
SEC_E_WRONG_PRINCIPAL equ 80090322h

; There is no LSA mode context associated with this context.
SEC_I_NO_LSA_CONTEXT equ 00090323h

; The clocks on the client and server machines are skewed.
SEC_E_TIME_SKEW equ 80090324h

; The certificate chain was issued by an authority that is not trusted.
SEC_E_UNTRUSTED_ROOT equ 80090325h

; The message received was unexpected or badly formatted.
SEC_E_ILLEGAL_MESSAGE equ 80090326h

; An unknown error occurred while processing the certificate.
SEC_E_CERT_UNKNOWN equ 80090327h

; The received certificate has expired.
SEC_E_CERT_EXPIRED equ 80090328h

; The specified data could not be encrypted.
SEC_E_ENCRYPT_FAILURE equ 80090329h

; The specified data could not be decrypted.
SEC_E_DECRYPT_FAILURE equ 80090330h

; The client and server cannot communicate, because they do not possess a common algorithm.
SEC_E_ALGORITHM_MISMATCH equ 80090331h

; The security context could not be established due to a failure in the requested quality of service (e.g. mutual authentication or delegation).
SEC_E_SECURITY_QOS_FAILED equ 80090332h

; A security context was deleted before the context was completed. This is considered a logon failure.
SEC_E_UNFINISHED_CONTEXT_DELETED equ 80090333h

; The client is trying to negotiate a context and the server requires user-to-user but didn't send a TGT reply.
SEC_E_NO_TGT_REPLY equ 80090334h

; Unable to accomplish the requested task because the local machine does not have any IP addresses.
SEC_E_NO_IP_ADDRESSES equ 80090335h

; The supplied credential HANDLE does not match the credential associated with the security context.
SEC_E_WRONG_CREDENTIAL_HANDLE equ 80090336h

; The crypto system or checksum function is invalid because a required function is unavailable.
SEC_E_CRYPTO_SYSTEM_INVALID equ 80090337h

; The number of maximum ticket referrals has been exceeded.
SEC_E_MAX_REFERRALS_EXCEEDED equ 80090338h

; The local machine must be a Kerberos KDC (domain controller) and it is not.
SEC_E_MUST_BE_KDC equ 80090339h

; The other end of the security negotiation is requires strong crypto but it is not supported on the local machine.
SEC_E_STRONG_CRYPTO_NOT_SUPPORTED equ 8009033Ah

; The KDC reply contained more than one principal name.
SEC_E_TOO_MANY_PRINCIPALS equ 8009033Bh

; Expected to find PA data for a hint of what etype to use, but it was not found.
SEC_E_NO_PA_DATA equ 8009033Ch

; The client cert name does not matches the user name or the KDC name is incorrect.
SEC_E_PKINIT_NAME_MISMATCH equ 8009033Dh

; Smartcard logon is required and was not used.
SEC_E_SMARTCARD_LOGON_REQUIRED equ 8009033Eh

; A system shutdown is in progress.
SEC_E_SHUTDOWN_IN_PROGRESS equ 8009033Fh

; An invalid request was sent to the KDC.
SEC_E_KDC_INVALID_REQUEST equ 80090340h

; The KDC was unable to generate a referral for the service requested.
SEC_E_KDC_UNABLE_TO_REFER equ 80090341h

; The encryption type requested is not supported by the KDC.
SEC_E_KDC_UNKNOWN_ETYPE equ 80090342h

; An unsupported preauthentication mechanism was presented to the kerberos package.
SEC_E_UNSUPPORTED_PREAUTH equ 80090343h

; The requested operation requires delegation to be enabled on the machine.
SEC_E_DELEGATION_REQUIRED equ 80090345h

; Client's supplied SSPI channel bindings were incorrect.
SEC_E_BAD_BINDINGS equ 80090346h

; The received certificate was mapped to multiple accounts.
SEC_E_MULTIPLE_ACCOUNTS equ 80090347h

; SEC_E_NO_KERB_KEY
SEC_E_NO_KERB_KEY equ 80090348h

; Provided for backwards compatibility

SEC_E_NO_SPM equ SEC_E_INTERNAL_ERROR
SEC_E_NOT_SUPPORTED equ SEC_E_UNSUPPORTED_FUNCTION

; An error occurred while performing an operation on a cryptographic message.
CRYPT_E_MSG_ERROR equ 80091001h

; Unknown cryptographic algorithm.
CRYPT_E_UNKNOWN_ALGO equ 80091002h

; The object identifier is poorly formatted.
CRYPT_E_OID_FORMAT equ 80091003h

; Invalid cryptographic message type.
CRYPT_E_INVALID_MSG_TYPE equ 80091004h

; Unexpected cryptographic message encoding.
CRYPT_E_UNEXPECTED_ENCODING equ 80091005h

; The cryptographic message does not contain an expected authenticated attribute.
CRYPT_E_AUTH_ATTR_MISSING equ 80091006h

; The hash value is not correct.
CRYPT_E_HASH_VALUE equ 80091007h

; The index value is not valid.
CRYPT_E_INVALID_INDEX equ 80091008h

; The content of the cryptographic message has already been decrypted.
CRYPT_E_ALREADY_DECRYPTED equ 80091009h

; The content of the cryptographic message has not been decrypted yet.
CRYPT_E_NOT_DECRYPTED equ 8009100Ah

; The enveloped-data message does not contain the specified recipient.
CRYPT_E_RECIPIENT_NOT_FOUND equ 8009100Bh

; Invalid control type.
CRYPT_E_CONTROL_TYPE equ 8009100Ch

; Invalid issuer and/or serial number.
CRYPT_E_ISSUER_SERIALNUMBER equ 8009100Dh

; Cannot find the original signer.
CRYPT_E_SIGNER_NOT_FOUND equ 8009100Eh

; The cryptographic message does not contain all of the requested attributes.
CRYPT_E_ATTRIBUTES_MISSING equ 8009100Fh

; The streamed cryptographic message is not ready to return data.
CRYPT_E_STREAM_MSG_NOT_READY equ 80091010h

; The streamed cryptographic message requires more data to complete the decode operation.
CRYPT_E_STREAM_INSUFFICIENT_DATA equ 80091011h

; The protected data needs to be re-protected.
CRYPT_I_NEW_PROTECTION_REQUIRED equ 00091012h

; The length specified for the output data was insufficient.
CRYPT_E_BAD_LEN equ 80092001h

; An error occurred during encode or decode operation.
CRYPT_E_BAD_ENCODE equ 80092002h

; An error occurred while reading or writing to a file.
CRYPT_E_FILE_ERROR equ 80092003h

; Cannot find object or property.
CRYPT_E_NOT_FOUND equ 80092004h

; The object or property already exists.
CRYPT_E_EXISTS equ 80092005h

; No provider was specified for the store or object.
CRYPT_E_NO_PROVIDER equ 80092006h

; The specified certificate is self signed.
CRYPT_E_SELF_SIGNED equ 80092007h

; The previous certificate or CRL context was deleted.
CRYPT_E_DELETED_PREV equ 80092008h

; Cannot find the requested object.
CRYPT_E_NO_MATCH equ 80092009h

; The certificate does not have a property that references a private key.
CRYPT_E_UNEXPECTED_MSG_TYPE equ 8009200Ah

; Cannot find the certificate and private key for decryption.
CRYPT_E_NO_KEY_PROPERTY equ 8009200Bh

; Cannot find the certificate and private key to use for decryption.
CRYPT_E_NO_DECRYPT_CERT equ 8009200Ch

; Not a cryptographic message or the cryptographic message is not formatted correctly.
CRYPT_E_BAD_MSG equ 8009200Dh

; The signed cryptographic message does not have a signer for the specified signer index.
CRYPT_E_NO_SIGNER equ 8009200Eh

; Final closure is pending until additional frees or closes.
CRYPT_E_PENDING_CLOSE equ 8009200Fh

; The certificate is revoked.
CRYPT_E_REVOKED equ 80092010h

; No Dll or exported function was found to verify revocation.
CRYPT_E_NO_REVOCATION_DLL equ 80092011h

; The revocation function was unable to check revocation for the certificate.
CRYPT_E_NO_REVOCATION_CHECK equ 80092012h

; The revocation function was unable to check revocation because the revocation server was offline.
CRYPT_E_REVOCATION_OFFLINE equ 80092013h

; The certificate is not in the revocation server's database.
CRYPT_E_NOT_IN_REVOCATION_DATABASE equ 80092014h

; The string contains a non-numeric character.
CRYPT_E_INVALID_NUMERIC_STRING equ 80092020h

; The string contains a non-printable character.
CRYPT_E_INVALID_PRINTABLE_STRING equ 80092021h

; The string contains a character not in the 7 bit ASCII character set.
CRYPT_E_INVALID_IA5_STRING equ 80092022h

; The string contains an invalid X500 name attribute key, oid, value or delimiter.
CRYPT_E_INVALID_X500_STRING equ 80092023h

; The dwValueType for the CERT_NAME_VALUE is not one of the character strings. Most likely it is either a CERT_RDN_ENCODED_BLOB or CERT_TDN_OCTED_STRING.
CRYPT_E_NOT_CHAR_STRING equ 80092024h

; The Put operation can not continue. The file needs to be resized. However, there is already a signature present. A complete signing operation must be done.
CRYPT_E_FILERESIZED equ 80092025h

; The cryptographic operation failed due to a local security option setting.
CRYPT_E_SECURITY_SETTINGS equ 80092026h

; No DLL or exported function was found to verify subject usage.
CRYPT_E_NO_VERIFY_USAGE_DLL equ 80092027h

; The called function was unable to do a usage check on the subject.
CRYPT_E_NO_VERIFY_USAGE_CHECK equ 80092028h

; Since the server was offline, the called function was unable to complete the usage check.
CRYPT_E_VERIFY_USAGE_OFFLINE equ 80092029h

; The subject was not found in a Certificate Trust List (CTL).
CRYPT_E_NOT_IN_CTL equ 8009202Ah

; None of the signers of the cryptographic message or certificate trust list is trusted.
CRYPT_E_NO_TRUSTED_SIGNER equ 8009202Bh

; The public key's algorithm parameters are missing.
CRYPT_E_MISSING_PUBKEY_PARA equ 8009202Ch

; OSS Certificate encode/decode error code base

; See asn1code.h for a definition of the OSS runtime errors. The OSS
; error values are offset by CRYPT_E_OSS_ERROR.

CRYPT_E_OSS_ERROR equ 80093000h

; MessageId: OSS_MORE_BUF
; OSS ASN.1 Error: Output Buffer is too small.
OSS_MORE_BUF equ 80093001h

; OSS ASN.1 Error: Signed integer is encoded as a unsigned integer.
OSS_NEGATIVE_UINTEGER equ 80093002h

; OSS ASN.1 Error: Unknown ASN.1 data type.
OSS_PDU_RANGE equ 80093003h

; OSS ASN.1 Error: Output buffer is too small, the decoded data has been truncated.
OSS_MORE_INPUT equ 80093004h

; OSS ASN.1 Error: Invalid data.
OSS_DATA_ERROR equ 80093005h

; OSS ASN.1 Error: Invalid argument.
OSS_BAD_ARG equ 80093006h

; OSS ASN.1 Error: Encode/Decode version mismatch.
OSS_BAD_VERSION equ 80093007h

; OSS ASN.1 Error: Out of memory.
OSS_OUT_MEMORY equ 80093008h

; OSS ASN.1 Error: Encode/Decode Error.
OSS_PDU_MISMATCH equ 80093009h

; OSS ASN.1 Error: Internal Error.
OSS_LIMITED equ 8009300Ah

; OSS ASN.1 Error: Invalid data.
OSS_BAD_PTR equ 8009300Bh

; OSS ASN.1 Error: Invalid data.
OSS_BAD_TIME equ 8009300Ch

; OSS ASN.1 Error: Unsupported BER indefinite-length encoding.
OSS_INDEFINITE_NOT_SUPPORTED equ 8009300Dh

; OSS ASN.1 Error: Access violation.
OSS_MEM_ERROR equ 8009300Eh

; OSS ASN.1 Error: Invalid data.
OSS_BAD_TABLE equ 8009300Fh

; OSS ASN.1 Error: Invalid data.
OSS_TOO_LONG equ 80093010h

; OSS ASN.1 Error: Invalid data.
OSS_CONSTRAINT_VIOLATED equ 80093011h

; OSS ASN.1 Error: Internal Error.
OSS_FATAL_ERROR equ 80093012h

; OSS ASN.1 Error: Multi-threading conflict.
OSS_ACCESS_SERIALIZATION_ERROR equ 80093013h

; OSS ASN.1 Error: Invalid data.
OSS_NULL_TBL equ 80093014h

; OSS ASN.1 Error: Invalid data.
OSS_NULL_FCN equ 80093015h

; OSS ASN.1 Error: Invalid data.
OSS_BAD_ENCRULES equ 80093016h

; OSS ASN.1 Error: Encode/Decode function not implemented.
OSS_UNAVAIL_ENCRULES equ 80093017h

; OSS ASN.1 Error: Trace file error.
OSS_CANT_OPEN_TRACE_WINDOW equ 80093018h

; OSS ASN.1 Error: Function not implemented.
OSS_UNIMPLEMENTED equ 80093019h

; OSS ASN.1 Error: Program link error.
OSS_OID_DLL_NOT_LINKED equ 8009301Ah

; OSS ASN.1 Error: Trace file error.
OSS_CANT_OPEN_TRACE_FILE equ 8009301Bh

; OSS ASN.1 Error: Trace file error.
OSS_TRACE_FILE_ALREADY_OPEN equ 8009301Ch

; OSS ASN.1 Error: Invalid data.
OSS_TABLE_MISMATCH equ 8009301Dh

; OSS ASN.1 Error: Invalid data.
OSS_TYPE_NOT_SUPPORTED equ 8009301Eh

; OSS ASN.1 Error: Program link error.
OSS_REAL_DLL_NOT_LINKED equ 8009301Fh

; OSS ASN.1 Error: Program link error.
OSS_REAL_CODE_NOT_LINKED equ 80093020h

; OSS ASN.1 Error: Program link error.
OSS_OUT_OF_RANGE equ 80093021h

; OSS ASN.1 Error: Program link error.
OSS_COPIER_DLL_NOT_LINKED equ 80093022h

; OSS ASN.1 Error: Program link error.
OSS_CONSTRAINT_DLL_NOT_LINKED equ 80093023h

; OSS ASN.1 Error: Program link error.
OSS_COMPARATOR_DLL_NOT_LINKED equ 80093024h

; OSS ASN.1 Error: Program link error.
OSS_COMPARATOR_CODE_NOT_LINKED equ 80093025h

; OSS ASN.1 Error: Program link error.
OSS_MEM_MGR_DLL_NOT_LINKED equ 80093026h

; OSS ASN.1 Error: Program link error.
OSS_PDV_DLL_NOT_LINKED equ 80093027h

; OSS ASN.1 Error: Program link error.
OSS_PDV_CODE_NOT_LINKED equ 80093028h

; OSS ASN.1 Error: Program link error.
OSS_API_DLL_NOT_LINKED equ 80093029h

; OSS ASN.1 Error: Program link error.
OSS_BERDER_DLL_NOT_LINKED equ 8009302Ah

; OSS ASN.1 Error: Program link error.
OSS_PER_DLL_NOT_LINKED equ 8009302Bh

; OSS ASN.1 Error: Program link error.
OSS_OPEN_TYPE_ERROR equ 8009302Ch

; OSS ASN.1 Error: System resource error.
OSS_MUTEX_NOT_CREATED equ 8009302Dh

; OSS ASN.1 Error: Trace file error.
OSS_CANT_CLOSE_TRACE_FILE equ 8009302Eh

; ASN1 Certificate encode/decode error code base.
;
; The ASN1 error values are offset by CRYPT_E_ASN1_ERROR.
CRYPT_E_ASN1_ERROR equ 80093100h

; ASN1 internal encode or decode error.
CRYPT_E_ASN1_INTERNAL equ 80093101h

; ASN1 unexpected end of data.
CRYPT_E_ASN1_EOD equ 80093102h

; ASN1 corrupted data.
CRYPT_E_ASN1_CORRUPT equ 80093103h

; ASN1 value too large.
CRYPT_E_ASN1_LARGE equ 80093104h

; ASN1 constraint violated.
CRYPT_E_ASN1_CONSTRAINT equ 80093105h

; ASN1 out of memory.
CRYPT_E_ASN1_MEMORY equ 80093106h

; ASN1 buffer overflow.
CRYPT_E_ASN1_OVERFLOW equ 80093107h

; ASN1 function not supported for this PDU.
CRYPT_E_ASN1_BADPDU equ 80093108h

; ASN1 bad arguments to function call.
CRYPT_E_ASN1_BADARGS equ 80093109h

; ASN1 bad real value.
CRYPT_E_ASN1_BADREAL equ 8009310Ah

; ASN1 bad tag value met.
CRYPT_E_ASN1_BADTAG equ 8009310Bh

; ASN1 bad choice value.
CRYPT_E_ASN1_CHOICE equ 8009310Ch

; ASN1 bad encoding rule.
CRYPT_E_ASN1_RULE equ 8009310Dh

; ASN1 bad unicode (UTF8).
CRYPT_E_ASN1_UTF8 equ 8009310Eh

; ASN1 bad PDU type.
CRYPT_E_ASN1_PDU_TYPE equ 80093133h

; ASN1 not yet implemented.
CRYPT_E_ASN1_NYI equ 80093134h

; ASN1 skipped unknown extension(s).
CRYPT_E_ASN1_EXTENDED equ 80093201h

; ASN1 end of data expected
CRYPT_E_ASN1_NOEOD equ 80093202h

; The request subject name is invalid or too long.
CERTSRV_E_BAD_REQUESTSUBJECT equ 80094001h

; The request does not exist.
CERTSRV_E_NO_REQUEST equ 80094002h

; The request's current status does not allow this operation.
CERTSRV_E_BAD_REQUESTSTATUS equ 80094003h

; The requested property value is empty.
CERTSRV_E_PROPERTY_EMPTY equ 80094004h

; The certification authority's certificate contains invalid data.
CERTSRV_E_INVALID_CA_CERTIFICATE equ 80094005h

; Certificate service has been suspended for a database restore operation.
CERTSRV_E_SERVER_SUSPENDED equ 80094006h

; The certificate contains an encoded length that is potentially incompatible with older enrollment software.
CERTSRV_E_ENCODING_LENGTH equ 80094007h

; The operation is denied. The user has multiple roles assigned and the certification authority is configured to enforce role separation.
CERTSRV_E_ROLECONFLICT equ 80094008h

; The operation is denied. It can only be performed by a certificate manager that is allowed to manage certificates for the current requester.
CERTSRV_E_RESTRICTEDOFFICER equ 80094009h

; Cannot archive private key. The certification authority is not configured for key archival.
CERTSRV_E_KEY_ARCHIVAL_NOT_CONFIGURED equ 8009400Ah

; Cannot archive private key. The certification authority could not verify one or more key recovery certificates.
CERTSRV_E_NO_VALID_KRA equ 8009400Bh

; The request is incorrectly formatted. The encrypted private key must be in an unauthenticated attribute in an outermost signature.
CERTSRV_E_BAD_REQUEST_KEY_ARCHIVAL equ 8009400Ch

; At least one security principal must have the permission to manage this CA.
CERTSRV_E_NO_CAADMIN_DEFINED equ 8009400Dh

; The request contains an invalid renewal certificate attribute.
CERTSRV_E_BAD_RENEWAL_CERT_ATTRIBUTE equ 8009400Eh

; An attempt was made to open a Certification Authority database session, but there are already too many active sessions. The server may need to be configured to allow additional sessions.
CERTSRV_E_NO_DB_SESSIONS equ 8009400Fh

; A memory reference caused a data alignment fault.
CERTSRV_E_ALIGNMENT_FAULT equ 80094010h

; The permissions on this certification authority do not allow the current user to enroll for certificates.
CERTSRV_E_ENROLL_DENIED equ 80094011h

; The permissions on the certificate template do not allow the current user to enroll for this type of certificate.
CERTSRV_E_TEMPLATE_DENIED equ 80094012h

; The requested certificate template is not supported by this CA.
CERTSRV_E_UNSUPPORTED_CERT_TYPE equ 80094800h

; The request contains no certificate template information.
CERTSRV_E_NO_CERT_TYPE equ 80094801h

; The request contains conflicting template information.
CERTSRV_E_TEMPLATE_CONFLICT equ 80094802h

; The request is missing a required Subject Alternate name extension.
CERTSRV_E_SUBJECT_ALT_NAME_REQUIRED equ 80094803h

; The request is missing a required private key for archival by the server.
CERTSRV_E_ARCHIVED_KEY_REQUIRED equ 80094804h

; The request is missing a required SMIME capabilities extension.
CERTSRV_E_SMIME_REQUIRED equ 80094805h

; The request was made on behalf of a subject other than the caller. The certificate template must be configured to require at least one signature to authorize the request.
CERTSRV_E_BAD_RENEWAL_SUBJECT equ 80094806h

; The request template version is newer than the supported template version.
CERTSRV_E_BAD_TEMPLATE_VERSION equ 80094807h

; The template is missing a required signature policy attribute.
CERTSRV_E_TEMPLATE_POLICY_REQUIRED equ 80094808h

; The request is missing required signature policy information.
CERTSRV_E_SIGNATURE_POLICY_REQUIRED equ 80094809h

; The request is missing one or more required signatures.
CERTSRV_E_SIGNATURE_COUNT equ 8009480Ah

; One or more signatures did not include the required application or issuance policies. The request is missing one or more required valid signatures.
CERTSRV_E_SIGNATURE_REJECTED equ 8009480Bh

; The request is missing one or more required signature issuance policies.
CERTSRV_E_ISSUANCE_POLICY_REQUIRED equ 8009480Ch

; The UPN is unavailable and cannot be added to the Subject Alternate name.
CERTSRV_E_SUBJECT_UPN_REQUIRED equ 8009480Dh

; The Active Directory GUID is unavailable and cannot be added to the Subject Alternate name.
CERTSRV_E_SUBJECT_DIRECTORY_GUID_REQUIRED equ 8009480Eh

; The DNS name is unavailable and cannot be added to the Subject Alternate name.
CERTSRV_E_SUBJECT_DNS_REQUIRED equ 8009480Fh

; The request includes a private key for archival by the server, but key archival is not enabled for the specified certificate template.
CERTSRV_E_ARCHIVED_KEY_UNEXPECTED equ 80094810h

; The public key does not meet the minimum size required by the specified certificate template.
CERTSRV_E_KEY_LENGTH equ 80094811h

; The range 5000h-51FFh is reserved for XENROLL errors.
;
; The key is not exportable.
XENROLL_E_KEY_NOT_EXPORTABLE equ 80095000h

; You cannot add the root CA certificate into your local store.
XENROLL_E_CANNOT_ADD_ROOT_CERT equ 80095001h

; The key archival hash attribute was not found in the response.
XENROLL_E_RESPONSE_KA_HASH_NOT_FOUND equ 80095002h

; An unexpetced key archival hash attribute was found in the response.
XENROLL_E_RESPONSE_UNEXPECTED_KA_HASH equ 80095003h

; There is a key archival hash mismatch between the request and the response.
XENROLL_E_RESPONSE_KA_HASH_MISMATCH equ 80095004h

; Signing certificate cannot include SMIME extension.
XENROLL_E_KEYSPEC_SMIME_MISMATCH equ 80095005h

; A system-level error occurred while verifying trust.
TRUST_E_SYSTEM_ERROR equ 80096001h

; The certificate for the signer of the message is invalid or not found.
TRUST_E_NO_SIGNER_CERT equ 80096002h

; One of the counter signatures was invalid.
TRUST_E_COUNTER_SIGNER equ 80096003h

; The signature of the certificate can not be verified.
TRUST_E_CERT_SIGNATURE equ 80096004h

; The timestamp signature and/or certificate could not be verified or is malformed.
TRUST_E_TIME_STAMP equ 80096005h

; The digital signature of the object did not verify.
TRUST_E_BAD_DIGEST equ 80096010h

; A certificate's basic constraint extension has not been observed.
TRUST_E_BASIC_CONSTRAINTS equ 80096019h

; The certificate does not meet or contain the Authenticode financial extensions.
TRUST_E_FINANCIAL_CRITERIA equ 8009601Eh

; Error codes for mssipotf.dll
; Most of the error codes can only occur when an error occurs during font file signing
;
; Tried to reference a part of the file outside the proper range.
MSSIPOTF_E_OUTOFMEMRANGE equ 80097001h

; Could not retrieve an object from the file.
MSSIPOTF_E_CANTGETOBJECT equ 80097002h

; Could not find the head table in the file.
MSSIPOTF_E_NOHEADTABLE equ 80097003h

; The magic number in the head table is incorrect.
MSSIPOTF_E_BAD_MAGICNUMBER equ 80097004h

; The offset table has incorrect values.
MSSIPOTF_E_BAD_OFFSET_TABLE equ 80097005h

; Duplicate table tags or tags out of alphabetical order.
MSSIPOTF_E_TABLE_TAGORDER equ 80097006h

; A table does not start on a long word boundary.
MSSIPOTF_E_TABLE_LONGWORD equ 80097007h

; First table does not appear after header information.
MSSIPOTF_E_BAD_FIRST_TABLE_PLACEMENT equ 80097008h

; Two or more tables overlap.
MSSIPOTF_E_TABLES_OVERLAP equ 80097009h

; Too many pad bytes between tables or pad bytes are not 0.
MSSIPOTF_E_TABLE_PADBYTES equ 8009700Ah

; File is too small to contain the last table.
MSSIPOTF_E_FILETOOSMALL equ 8009700Bh

; A table checksum is incorrect.
MSSIPOTF_E_TABLE_CHECKSUM equ 8009700Ch

; The file checksum is incorrect.
MSSIPOTF_E_FILE_CHECKSUM equ 8009700Dh

; The signature does not have the correct attributes for the policy.
MSSIPOTF_E_FAILED_POLICY equ 80097010h

; The file did not pass the hints check.
MSSIPOTF_E_FAILED_HINTS_CHECK equ 80097011h

; The file is not an OpenType file.
MSSIPOTF_E_NOT_OPENTYPE equ 80097012h

; Failed on a file operation (open, map, read, write).
MSSIPOTF_E_FILE equ 80097013h

; A call to a CryptoAPI function failed.
MSSIPOTF_E_CRYPT equ 80097014h

; There is a bad version number in the file.
MSSIPOTF_E_BADVERSION equ 80097015h

; The structure of the DSIG table is incorrect.
MSSIPOTF_E_DSIG_STRUCTURE equ 80097016h

; A check failed in a partially constant table.
MSSIPOTF_E_PCONST_CHECK equ 80097017h

; Some kind of structural error.
MSSIPOTF_E_STRUCTURE equ 80097018h

NTE_OP_OK equ 0

; Note that additional FACILITY_SSPI errors are in issperr.h
; ******************
; FACILITY_CERT
; ******************

; Unknown trust provider.
TRUST_E_PROVIDER_UNKNOWN equ 800B0001h

; MessageId: TRUST_E_ACTION_UNKNOWN
; The trust verification action specified is not supported by the specified trust provider.
TRUST_E_ACTION_UNKNOWN equ 800B0002h

; The form specified for the subject is not one supported or known by the specified trust provider.
TRUST_E_SUBJECT_FORM_UNKNOWN equ 800B0003h

; The subject is not trusted for the specified action.
TRUST_E_SUBJECT_NOT_TRUSTED equ 800B0004h

; Error due to problem in ASN.1 encoding process.
DIGSIG_E_ENCODE equ 800B0005h

; Error due to problem in ASN.1 decoding process.
DIGSIG_E_DECODE equ 800B0006h

; Reading / writing Extensions where Attributes are appropriate, and visa versa.
DIGSIG_E_EXTENSIBILITY equ 800B0007h

; Unspecified cryptographic failure.
DIGSIG_E_CRYPTO equ 800B0008h

; The size of the data could not be determined.
PERSIST_E_SIZEDEFINITE equ 800B0009h

; The size of the indefinite-sized data could not be determined.
PERSIST_E_SIZEINDEFINITE equ 800B000Ah

; This object does not read and write self-sizing data.
PERSIST_E_NOTSELFSIZING equ 800B000Bh

; No signature was present in the subject.
TRUST_E_NOSIGNATURE equ 800B0100h

; A required certificate is not within its validity period when verifying against the current system clock or the timestamp in the signed file.
CERT_E_EXPIRED equ 800B0101h

; The validity periods of the certification chain do not nest correctly.
CERT_E_VALIDITYPERIODNESTING equ 800B0102h

; A certificate that can only be used as an end-entity is being used as a CA or visa versa.
CERT_E_ROLE equ 800B0103h

; A path length constraint in the certification chain has been violated.
CERT_E_PATHLENCONST equ 800B0104h

; A certificate contains an unknown extension that is marked 'critical'.
CERT_E_CRITICAL equ 800B0105h

; A certificate being used for a purpose other than the ones specified by its CA.
CERT_E_PURPOSE equ 800B0106h

; A parent of a given certificate in fact did not issue that child certificate.
CERT_E_ISSUERCHAINING equ 800B0107h

; A certificate is missing or has an empty value for an important field, such as a subject or issuer name.
CERT_E_MALFORMED equ 800B0108h

; A certificate chain processed, but terminated in a root certificate which is not trusted by the trust provider.
CERT_E_UNTRUSTEDROOT equ 800B0109h

; An internal certificate chaining error has occurred.
CERT_E_CHAINING equ 800B010Ah

; Generic trust failure.
TRUST_E_FAIL equ 800B010Bh

; A certificate was explicitly revoked by its issuer.
CERT_E_REVOKED equ 800B010Ch

; The certification path terminates with the test root which is not trusted with the current policy settings.
CERT_E_UNTRUSTEDTESTROOT equ 800B010Dh

; The revocation process could not continue - the certificate(s) could not be checked.
CERT_E_REVOCATION_FAILURE equ 800B010Eh

; The certificate's CN name does not match the passed value.
CERT_E_CN_NO_MATCH equ 800B010Fh

; The certificate is not valid for the requested usage.
CERT_E_WRONG_USAGE equ 800B0110h

; The certificate was explicitly marked as untrusted by the user.
TRUST_E_EXPLICIT_DISTRUST equ 800B0111h

; A certification chain processed correctly, but one of the CA certificates is not trusted by the policy provider.
CERT_E_UNTRUSTEDCA equ 800B0112h

; The certificate has invalid policy.
CERT_E_INVALID_POLICY equ 800B0113h

; The certificate has an invalid name. The name is not included in the permitted list or is explicitly excluded.
CERT_E_INVALID_NAME equ 800B0114h

; *****************
; FACILITY_SETUPAPI
; *****************
; Since these error codes aren't in the standard Win32 range (i.e., 0-64K), define a
; macro to map either Win32 or SetupAPI error codes into an HRESULT.
;HRESULT_FROM_SETUPAPI(x) ((((x) & (APPLICATION_ERROR_MASK|ERROR_SEVERITY_ERROR)) == (APPLICATION_ERROR_MASK|ERROR_SEVERITY_ERROR)) \
; ? ((HRESULT) (((x) & 0x0000FFFF) | (FACILITY_SETUPAPI << 16) | 0x80000000)) \
; : HRESULT_FROM_WIN32(x))

; A non-empty line was encountered in the INF before the start of a section.
SPAPI_E_EXPECTED_SECTION_NAME equ 800F0000h

; A section name marker in the INF is not complete, or does not exist on a line by itself.
SPAPI_E_BAD_SECTION_NAME_LINE equ 800F0001h

; An INF section was encountered whose name exceeds the maximum section name length.
SPAPI_E_SECTION_NAME_TOO_LONG equ 800F0002h

; The syntax of the INF is invalid.
SPAPI_E_GENERAL_SYNTAX equ 800F0003h

; The style of the INF is different than what was requested.
SPAPI_E_WRONG_INF_STYLE equ 800F0100h

; The required section was not found in the INF.
SPAPI_E_SECTION_NOT_FOUND equ 800F0101h

; The required line was not found in the INF.
SPAPI_E_LINE_NOT_FOUND equ 800F0102h

; The files affected by the installation of this file queue have not been backed up for uninstall.
SPAPI_E_NO_BACKUP equ 800F0103h

; The INF or the device information set or element does not have an associated install class.
SPAPI_E_NO_ASSOCIATED_CLASS equ 800F0200h

; The INF or the device information set or element does not match the specified install class.
SPAPI_E_CLASS_MISMATCH equ 800F0201h

; An existing device was found that is a duplicate of the device being manually installed.
SPAPI_E_DUPLICATE_FOUND equ 800F0202h

; There is no driver selected for the device information set or element.
SPAPI_E_NO_DRIVER_SELECTED equ 800F0203h

; The requested device registry key does not exist.
SPAPI_E_KEY_DOES_NOT_EXIST equ 800F0204h

; The device instance name is invalid.
SPAPI_E_INVALID_DEVINST_NAME equ 800F0205h

; The install class is not present or is invalid.
SPAPI_E_INVALID_CLASS equ 800F0206h

; The device instance cannot be created because it already exists.
SPAPI_E_DEVINST_ALREADY_EXISTS equ 800F0207h

; The operation cannot be performed on a device information element that has not been registered.
SPAPI_E_DEVINFO_NOT_REGISTERED equ 800F0208h

; The device property code is invalid.
SPAPI_E_INVALID_REG_PROPERTY equ 800F0209h

; The INF from which a driver list is to be built does not exist.
SPAPI_E_NO_INF equ 800F020Ah

; The device instance does not exist in the hardware tree.
SPAPI_E_NO_SUCH_DEVINST equ 800F020Bh

; The icon representing this install class cannot be loaded.
SPAPI_E_CANT_LOAD_CLASS_ICON equ 800F020Ch

; The class installer registry entry is invalid.
SPAPI_E_INVALID_CLASS_INSTALLER equ 800F020Dh

; The class installer has indicated that the default action should be performed for this installation request.
SPAPI_E_DI_DO_DEFAULT equ 800F020Eh

; The operation does not require any files to be copied.
SPAPI_E_DI_NOFILECOPY equ 800F020Fh

; The specified hardware profile does not exist.
SPAPI_E_INVALID_HWPROFILE equ 800F0210h

; There is no device information element currently selected for this device information set.
SPAPI_E_NO_DEVICE_SELECTED equ 800F0211h

; The operation cannot be performed because the device information set is locked.
SPAPI_E_DEVINFO_LIST_LOCKED equ 800F0212h

; The operation cannot be performed because the device information element is locked.
SPAPI_E_DEVINFO_DATA_LOCKED equ 800F0213h

; The specified path does not contain any applicable device INFs.
SPAPI_E_DI_BAD_PATH equ 800F0214h

; No class installer parameters have been set for the device information set or element.
SPAPI_E_NO_CLASSINSTALL_PARAMS equ 800F0215h

; The operation cannot be performed because the file queue is locked.
SPAPI_E_FILEQUEUE_LOCKED equ 800F0216h

; A service installation section in this INF is invalid.
SPAPI_E_BAD_SERVICE_INSTALLSECT equ 800F0217h

; There is no class driver list for the device information element.
SPAPI_E_NO_CLASS_DRIVER_LIST equ 800F0218h

; The installation failed because a function driver was not specified for this device instance.
SPAPI_E_NO_ASSOCIATED_SERVICE equ 800F0219h

; There is presently no default device interface designated for this interface class.
SPAPI_E_NO_DEFAULT_DEVICE_INTERFACE equ 800F021Ah

; The operation cannot be performed because the device interface is currently active.
SPAPI_E_DEVICE_INTERFACE_ACTIVE equ 800F021Bh

; The operation cannot be performed because the device interface has been removed from the system.
SPAPI_E_DEVICE_INTERFACE_REMOVED equ 800F021Ch

; An interface installation section in this INF is invalid.
SPAPI_E_BAD_INTERFACE_INSTALLSECT equ 800F021Dh

; This interface class does not exist in the system.
SPAPI_E_NO_SUCH_INTERFACE_CLASS equ 800F021Eh

; The reference string supplied for this interface device is invalid.
SPAPI_E_INVALID_REFERENCE_STRING equ 800F021Fh

; The specified machine name does not conform to UNC naming conventions.
SPAPI_E_INVALID_MACHINENAME equ 800F0220h

; A general remote communication error occurred.
SPAPI_E_REMOTE_COMM_FAILURE equ 800F0221h

; The machine selected for remote communication is not available at this time.
SPAPI_E_MACHINE_UNAVAILABLE equ 800F0222h

; The Plug and Play service is not available on the remote machine.
SPAPI_E_NO_CONFIGMGR_SERVICES equ 800F0223h

; The property page provider registry entry is invalid.
SPAPI_E_INVALID_PROPPAGE_PROVIDER equ 800F0224h

; The requested device interface is not present in the system.
SPAPI_E_NO_SUCH_DEVICE_INTERFACE equ 800F0225h

; The device's co-installer has additional work to perform after installation is complete.
SPAPI_E_DI_POSTPROCESSING_REQUIRED equ 800F0226h

; The device's co-installer is invalid.
SPAPI_E_INVALID_COINSTALLER equ 800F0227h

; There are no compatible drivers for this device.
SPAPI_E_NO_COMPAT_DRIVERS equ 800F0228h

; There is no icon that represents this device or device type.
SPAPI_E_NO_DEVICE_ICON equ 800F0229h

; A logical configuration specified in this INF is invalid.
SPAPI_E_INVALID_INF_LOGCONFIG equ 800F022Ah

; The class installer has denied the request to install or upgrade this device.
SPAPI_E_DI_DONT_INSTALL equ 800F022Bh

; One of the filter drivers installed for this device is invalid.
SPAPI_E_INVALID_FILTER_DRIVER equ 800F022Ch

; The driver selected for this device does not support Windows 2000.
SPAPI_E_NON_WINDOWS_NT_DRIVER equ 800F022Dh

; The driver selected for this device does not support Windows.
SPAPI_E_NON_WINDOWS_DRIVER equ 800F022Eh

; The third-party INF does not contain digital signature information.
SPAPI_E_NO_CATALOG_FOR_OEM_INF equ 800F022Fh

; An invalid attempt was made to use a device installation file queue for verification of digital signatures relative to other platforms.
SPAPI_E_DEVINSTALL_QUEUE_NONNATIVE equ 800F0230h

; The device cannot be disabled.
SPAPI_E_NOT_DISABLEABLE equ 800F0231h

; The device could not be dynamically removed.
SPAPI_E_CANT_REMOVE_DEVINST equ 800F0232h

; Cannot copy to specified target.
SPAPI_E_INVALID_TARGET equ 800F0233h

; Driver is not intended for this platform.
SPAPI_E_DRIVER_NONNATIVE equ 800F0234h

; Operation not allowed in WOW64.
SPAPI_E_IN_WOW64 equ 800F0235h

; The operation involving unsigned file copying was rolled back, so that a system restore point could be set.
SPAPI_E_SET_SYSTEM_RESTORE_POINT equ 800F0236h

; An INF was copied into the Windows INF directory in an improper manner.
SPAPI_E_INCORRECTLY_COPIED_INF equ 800F0237h

; The Security Configuration Editor (SCE) APIs have been disabled on this Embedded product.
SPAPI_E_SCE_DISABLED equ 800F0238h

; No installed components were detected.
SPAPI_E_ERROR_NOT_INSTALLED equ 800F1000h

; *****************
; FACILITY_SCARD
; *****************
; =============================
; Facility SCARD Error Messages
; =============================
SCARD_S_SUCCESS equ NO_ERROR

; An internal consistency check failed.
SCARD_F_INTERNAL_ERROR equ 80100001h

; The action was cancelled by an SCardCancel request.
SCARD_E_CANCELLED equ 80100002h

; The supplied HANDLE was invalid.
SCARD_E_INVALID_HANDLE equ 80100003h

; One or more of the supplied parameters could not be properly interpreted.
SCARD_E_INVALID_PARAMETER equ 80100004h

; Registry startup information is missing or invalid.
SCARD_E_INVALID_TARGET equ 80100005h

; Not enough memory available to complete this command.
SCARD_E_NO_MEMORY equ 80100006h

; An internal consistency timer has expired.
SCARD_F_WAITED_TOO_LONG equ 80100007h

; The data buffer to receive returned data is too small for the returned data.
SCARD_E_INSUFFICIENT_BUFFER equ 80100008h

; The specified reader name is not recognized.
SCARD_E_UNKNOWN_READER equ 80100009h

; The user-specified timeout value has expired.
SCARD_E_TIMEOUT equ 8010000Ah

; The smart card cannot be accessed because of other connections outstanding.
SCARD_E_SHARING_VIOLATION equ 8010000Bh

; The operation requires a Smart Card, but no Smart Card is currently in the device.
SCARD_E_NO_SMARTCARD equ 8010000Ch

; The specified smart card name is not recognized.
SCARD_E_UNKNOWN_CARD equ 8010000Dh

; The system could not dispose of the media in the requested manner.
SCARD_E_CANT_DISPOSE equ 8010000Eh

; The requested protocols are incompatible with the protocol currently in use with the smart card.
SCARD_E_PROTO_MISMATCH equ 8010000Fh

; The reader or smart card is not ready to accept commands.
SCARD_E_NOT_READY equ 80100010h

; One or more of the supplied parameters values could not be properly interpreted.
SCARD_E_INVALID_VALUE equ 80100011h

; The action was cancelled by the system, presumably to log off or shut down.
SCARD_E_SYSTEM_CANCELLED equ 80100012h

; An internal communications error has been detected.
SCARD_F_COMM_ERROR equ 80100013h

; An internal error has been detected, but the source is unknown.
SCARD_F_UNKNOWN_ERROR equ 80100014h

; An ATR obtained from the registry is not a valid ATR string.
SCARD_E_INVALID_ATR equ 80100015h

; An attempt was made to end a non-existent transaction.
SCARD_E_NOT_TRANSACTED equ 80100016h

; The specified reader is not currently available for use.
SCARD_E_READER_UNAVAILABLE equ 80100017h

; The operation has been aborted to allow the server application to exit.
SCARD_P_SHUTDOWN equ 80100018h

; The PCI Receive buffer was too small.
SCARD_E_PCI_TOO_SMALL equ 80100019h

; The reader driver does not meet minimal requirements for support.
SCARD_E_READER_UNSUPPORTED equ 8010001Ah

; The reader driver did not produce a unique reader name.
SCARD_E_DUPLICATE_READER equ 8010001Bh

; The smart card does not meet minimal requirements for support.
SCARD_E_CARD_UNSUPPORTED equ 8010001Ch

; The Smart card resource manager is not running.
SCARD_E_NO_SERVICE equ 8010001Dh

; The Smart card resource manager has shut down.
SCARD_E_SERVICE_STOPPED equ 8010001Eh

; An unexpected card error has occurred.
SCARD_E_UNEXPECTED equ 8010001Fh

; No Primary Provider can be found for the smart card.
SCARD_E_ICC_INSTALLATION equ 80100020h

; The requested order of object creation is not supported.
SCARD_E_ICC_CREATEORDER equ 80100021h

; This smart card does not support the requested feature.
SCARD_E_UNSUPPORTED_FEATURE equ 80100022h

; The identified directory does not exist in the smart card.
SCARD_E_DIR_NOT_FOUND equ 80100023h

; The identified file does not exist in the smart card.
SCARD_E_FILE_NOT_FOUND equ 80100024h

; The supplied path does not represent a smart card directory.
SCARD_E_NO_DIR equ 80100025h

; The supplied path does not represent a smart card file.
SCARD_E_NO_FILE equ 80100026h

; Access is denied to this file.
SCARD_E_NO_ACCESS equ 80100027h

; The smartcard does not have enough memory to store the information.
SCARD_E_WRITE_TOO_MANY equ 80100028h

; There was an error trying to set the smart card file object pointer.
SCARD_E_BAD_SEEK equ 80100029h

; The supplied PIN is incorrect.
SCARD_E_INVALID_CHV equ 8010002Ah

; An unrecognized error code was returned from a layered component.
SCARD_E_UNKNOWN_RES_MNG equ 8010002Bh

; The requested certificate does not exist.
SCARD_E_NO_SUCH_CERTIFICATE equ 8010002Ch

; The requested certificate could not be obtained.
SCARD_E_CERTIFICATE_UNAVAILABLE equ 8010002Dh

; Cannot find a smart card reader.
SCARD_E_NO_READERS_AVAILABLE equ 8010002Eh

; A communications error with the smart card has been detected. Retry the operation.
SCARD_E_COMM_DATA_LOST equ 8010002Fh

; The requested key container does not exist on the smart card.
SCARD_E_NO_KEY_CONTAINER equ 80100030h

; These are warning codes.
;
; The reader cannot communicate with the smart card, due to ATR configuration conflicts.
SCARD_W_UNSUPPORTED_CARD equ 80100065h

; The smart card is not responding to a reset.
SCARD_W_UNRESPONSIVE_CARD equ 80100066h

; Power has been removed from the smart card, so that further communication is not possible.
SCARD_W_UNPOWERED_CARD equ 80100067h

; The smart card has been reset, so any shared state information is invalid.
SCARD_W_RESET_CARD equ 80100068h

; The smart card has been removed, so that further communication is not possible.
SCARD_W_REMOVED_CARD equ 80100069h

; Access was denied because of a security violation.
SCARD_W_SECURITY_VIOLATION equ 8010006Ah

; The card cannot be accessed because the wrong PIN was presented.
SCARD_W_WRONG_CHV equ 8010006Bh

; The card cannot be accessed because the maximum number of PIN entry attempts has been reached.
SCARD_W_CHV_BLOCKED equ 8010006Ch

; The end of the smart card file has been reached.
SCARD_W_EOF equ 8010006Dh

; The action was cancelled by the user.
SCARD_W_CANCELLED_BY_USER equ 8010006Eh

; No PIN was presented to the smart card.
SCARD_W_CARD_NOT_AUTHENTICATED equ 8010006Fh

; *****************
; FACILITY_COMPLUS
; *****************
; ===============================
; Facility COMPLUS Error Messages
; ===============================
;
; The following are the subranges within the COMPLUS facility
; 400h - 4FFh COMADMIN_E_CAT
; 600h - 6FFh COMQC errors
; 700h - 7FFh MSDTC errors
; 800h - 8FFh Other COMADMIN errors
; COMPLUS Admin errors
;
; Errors occurred accessing one or more objects - the ErrorInfo collection may have more detail
COMADMIN_E_OBJECTERRORS equ 80110401h

; One or more of the object's properties are missing or invalid
COMADMIN_E_OBJECTINVALID equ 80110402h

; The object was not found in the catalog
COMADMIN_E_KEYMISSING equ 80110403h

; The object is already registered
COMADMIN_E_ALREADYINSTALLED equ 80110404h

; Error occurred writing to the application file
COMADMIN_E_APP_FILE_WRITEFAIL equ 80110407h

; Error occurred reading the application file
COMADMIN_E_APP_FILE_READFAIL equ 80110408h

; Invalid version number in application file
COMADMIN_E_APP_FILE_VERSION equ 80110409h

; The file path is invalid
COMADMIN_E_BADPATH equ 8011040Ah

; The application is already installed
COMADMIN_E_APPLICATIONEXISTS equ 8011040Bh

; The role already exists
COMADMIN_E_ROLEEXISTS equ 8011040Ch

; An error occurred copying the file
COMADMIN_E_CANTCOPYFILE equ 8011040Dh

; One or more users are not valid
COMADMIN_E_NOUSER equ 8011040Fh

; One or more users in the application file are not valid
COMADMIN_E_INVALIDUSERIDS equ 80110410h

; The component's CLSID is missing or corrupt
COMADMIN_E_NOREGISTRYCLSID equ 80110411h

; The component's progID is missing or corrupt
COMADMIN_E_BADREGISTRYPROGID equ 80110412h

; Unable to set required authentication level for update request
COMADMIN_E_AUTHENTICATIONLEVEL equ 80110413h

; The identity or password set on the application is not valid
COMADMIN_E_USERPASSWDNOTVALID equ 80110414h

; Application file CLSIDs or IIDs do not match corresponding DLLs
COMADMIN_E_CLSIDORIIDMISMATCH equ 80110418h

; Interface information is either missing or changed
COMADMIN_E_REMOTEINTERFACE equ 80110419h

; DllRegisterServer failed on component install
COMADMIN_E_DLLREGISTERSERVER equ 8011041Ah

; No server file share available
COMADMIN_E_NOSERVERSHARE equ 8011041Bh

; DLL could not be loaded
COMADMIN_E_DLLLOADFAILED equ 8011041Dh

; The registered TypeLib ID is not valid
COMADMIN_E_BADREGISTRYLIBID equ 8011041Eh

; Application install directory not found
COMADMIN_E_APPDIRNOTFOUND equ 8011041Fh

; Errors occurred while in the component registrar
COMADMIN_E_REGISTRARFAILED equ 80110423h

; The file does not exist
COMADMIN_E_COMPFILE_DOESNOTEXIST equ 80110424h

; The DLL could not be loaded
COMADMIN_E_COMPFILE_LOADDLLFAIL equ 80110425h

; GetClassObject failed in the DLL
COMADMIN_E_COMPFILE_GETCLASSOBJ equ 80110426h

; The DLL does not support the components listed in the TypeLib
COMADMIN_E_COMPFILE_CLASSNOTAVAIL equ 80110427h

; The TypeLib could not be loaded
COMADMIN_E_COMPFILE_BADTLB equ 80110428h

; The file does not contain components or component information
COMADMIN_E_COMPFILE_NOTINSTALLABLE equ 80110429h

; Changes to this object and its sub-objects have been disabled
COMADMIN_E_NOTCHANGEABLE equ 8011042Ah

; The delete function has been disabled for this object
COMADMIN_E_NOTDELETEABLE equ 8011042Bh

; The server catalog version is not supported
COMADMIN_E_SESSION equ 8011042Ch

; The component move was disallowed, because the source or destination application is either a system application or currently locked against changes
COMADMIN_E_COMP_MOVE_LOCKED equ 8011042Dh

; The component move failed because the destination application no longer exists
COMADMIN_E_COMP_MOVE_BAD_DEST equ 8011042Eh

; The system was unable to register the TypeLib
COMADMIN_E_REGISTERTLB equ 80110430h

; This operation can not be performed on the system application
COMADMIN_E_SYSTEMAPP equ 80110433h

; The component registrar referenced in this file is not available
COMADMIN_E_COMPFILE_NOREGISTRAR equ 80110434h

; A component in the same DLL is already installed
COMADMIN_E_COREQCOMPINSTALLED equ 80110435h

; The service is not installed
COMADMIN_E_SERVICENOTINSTALLED equ 80110436h

; One or more property settings are either invalid or in conflict with each other
COMADMIN_E_PROPERTYSAVEFAILED equ 80110437h

; The object you are attempting to add or rename already exists
COMADMIN_E_OBJECTEXISTS equ 80110438h

; The component already exists
COMADMIN_E_COMPONENTEXISTS equ 80110439h

; The registration file is corrupt
COMADMIN_E_REGFILE_CORRUPT equ 8011043Bh

; The property value is too large
COMADMIN_E_PROPERTY_OVERFLOW equ 8011043Ch

; Object was not found in registry
COMADMIN_E_NOTINREGISTRY equ 8011043Eh

; This object is not poolable
COMADMIN_E_OBJECTNOTPOOLABLE equ 8011043Fh

; A CLSID with the same GUID as the new application ID is already installed on this machine
COMADMIN_E_APPLID_MATCHES_CLSID equ 80110446h

; A role assigned to a component, interface, or method did not exist in the application
COMADMIN_E_ROLE_DOES_NOT_EXIST equ 80110447h

; You must have components in an application in order to start the application
COMADMIN_E_START_APP_NEEDS_COMPONENTS equ 80110448h

; This operation is not enabled on this platform
COMADMIN_E_REQUIRES_DIFFERENT_PLATFORM equ 80110449h

; Application Proxy is not exportable
COMADMIN_E_CAN_NOT_EXPORT_APP_PROXY equ 8011044Ah

; Failed to start application because it is either a library application or an application proxy
COMADMIN_E_CAN_NOT_START_APP equ 8011044Bh

; System application is not exportable
COMADMIN_E_CAN_NOT_EXPORT_SYS_APP equ 8011044Ch

; Can not subscribe to this component (the component may have been imported)
COMADMIN_E_CANT_SUBSCRIBE_TO_COMPONENT equ 8011044Dh

; An event class cannot also be a subscriber component
COMADMIN_E_EVENTCLASS_CANT_BE_SUBSCRIBER equ 8011044Eh

; Library applications and application proxies are incompatible
COMADMIN_E_LIB_APP_PROXY_INCOMPATIBLE equ 8011044Fh

; This function is valid for the base partition only
COMADMIN_E_BASE_PARTITION_ONLY equ 80110450h

; You cannot start an application that has been disabled
COMADMIN_E_START_APP_DISABLED equ 80110451h

; The specified partition name is already in use on this computer
COMADMIN_E_CAT_DUPLICATE_PARTITION_NAME equ 80110457h

; The specified partition name is invalid. Check that the name contains at least one visible character
COMADMIN_E_CAT_INVALID_PARTITION_NAME equ 80110458h

; The partition cannot be deleted because it is the default partition for one or more users
COMADMIN_E_CAT_PARTITION_IN_USE equ 80110459h

; The partition cannot be exported, because one or more components in the partition have the same file name
COMADMIN_E_FILE_PARTITION_DUPLICATE_FILES equ 8011045Ah

; Applications that contain one or more imported components cannot be installed into a non-base partition
COMADMIN_E_CAT_IMPORTED_COMPONENTS_NOT_ALLOWED equ 8011045Bh

; The application name is not unique and cannot be resolved to an application id
COMADMIN_E_AMBIGUOUS_APPLICATION_NAME equ 8011045Ch

; The partition name is not unique and cannot be resolved to a partition id
COMADMIN_E_AMBIGUOUS_PARTITION_NAME equ 8011045Dh

; The COM+ registry database has not been initialized
COMADMIN_E_REGDB_NOTINITIALIZED equ 80110472h

; The COM+ registry database is not open
COMADMIN_E_REGDB_NOTOPEN equ 80110473h

; The COM+ registry database detected a system error
COMADMIN_E_REGDB_SYSTEMERR equ 80110474h

; The COM+ registry database is already running
COMADMIN_E_REGDB_ALREADYRUNNING equ 80110475h

; This version of the COM+ registry database cannot be migrated
COMADMIN_E_MIG_VERSIONNOTSUPPORTED equ 80110480h

; The schema version to be migrated could not be found in the COM+ registry database
COMADMIN_E_MIG_SCHEMANOTFOUND equ 80110481h

; There was a type mismatch between binaries
COMADMIN_E_CAT_BITNESSMISMATCH equ 80110482h

; A binary of unknown or invalid type was provided
COMADMIN_E_CAT_UNACCEPTABLEBITNESS equ 80110483h

; There was a type mismatch between a binary and an application
COMADMIN_E_CAT_WRONGAPPBITNESS equ 80110484h

; The application cannot be paused or resumed
COMADMIN_E_CAT_PAUSE_RESUME_NOT_SUPPORTED equ 80110485h

; The COM+ Catalog Server threw an exception during execution
COMADMIN_E_CAT_SERVERFAULT equ 80110486h

; COMPLUS Queued component errors
;
; Only COM+ Applications marked "queued" can be invoked using the "queue" moniker
COMQC_E_APPLICATION_NOT_QUEUED equ 80110600h

; At least one interface must be marked "queued" in order to create a queued component instance with the "queue" moniker
COMQC_E_NO_QUEUEABLE_INTERFACES equ 80110601h

; MSMQ is required for the requested operation and is not installed
COMQC_E_QUEUING_SERVICE_NOT_AVAILABLE equ 80110602h

; Unable to marshal an interface that does not support IPersistStream
COMQC_E_NO_IPERSISTSTREAM equ 80110603h

; The message is improperly formatted or was damaged in transit
COMQC_E_BAD_MESSAGE equ 80110604h

; An unauthenticated message was received by an application that accepts only authenticated messages
COMQC_E_UNAUTHENTICATED equ 80110605h

; The message was requeued or moved by a user not in the "QC Trusted User" role
COMQC_E_UNTRUSTED_ENQUEUER equ 80110606h

; The range 700h-7FFh is reserved for MSDTC errors.
;
; Cannot create a duplicate resource of type Distributed Transaction Coordinator
MSDTC_E_DUPLICATE_RESOURCE equ 80110701h

; More COMADMIN errors from 8**h
;
; One of the objects being inserted or updated does not belong to a valid parent collection
COMADMIN_E_OBJECT_PARENT_MISSING equ 80110808h

; One of the specified objects cannot be found
COMADMIN_E_OBJECT_DOES_NOT_EXIST equ 80110809h

; The specified application is not currently running
COMADMIN_E_APP_NOT_RUNNING equ 8011080Ah

; The partition(s) specified are not valid.
COMADMIN_E_INVALID_PARTITION equ 8011080Bh

; COM+ applications that run as NT service may not be pooled or recycled
COMADMIN_E_SVCAPP_NOT_POOLABLE_OR_RECYCLABLE equ 8011080Dh

; One or more users are already assigned to a local partition set.
COMADMIN_E_USER_IN_SET equ 8011080Eh

; Library applications may not be recycled.
COMADMIN_E_CANTRECYCLELIBRARYAPPS equ 8011080Fh

; Applications running as NT services may not be recycled.
COMADMIN_E_CANTRECYCLESERVICEAPPS equ 80110811h

; The process has already been recycled.
COMADMIN_E_PROCESSALREADYRECYCLED equ 80110812h

; A paused process may not be recycled.
COMADMIN_E_PAUSEDPROCESSMAYNOTBERECYCLED equ 80110813h

; Library applications may not be NT services.
COMADMIN_E_CANTMAKEINPROCSERVICE equ 80110814h

; The ProgID provided to the copy operation is invalid. The ProgID is in use by another registered CLSID.
COMADMIN_E_PROGIDINUSEBYCLSID equ 80110815h

; The partition specified as default is not a member of the partition set.
COMADMIN_E_DEFAULT_PARTITION_NOT_IN_SET equ 80110816h

; A recycled process may not be paused.
COMADMIN_E_RECYCLEDPROCESSMAYNOTBEPAUSED equ 80110817h

; Access to the specified partition is denied.
COMADMIN_E_PARTITION_ACCESSDENIED equ 80110818h

; Only Application Files (*.MSI files) can be installed into partitions.
COMADMIN_E_PARTITION_MSI_ONLY equ 80110819h

; Applications containing one or more legacy components may not be exported to 1.0 format.
COMADMIN_E_LEGACYCOMPS_NOT_ALLOWED_IN_1_0_FORMAT equ 8011081Ah

; Legacy components may not exist in non-base partitions.
COMADMIN_E_LEGACYCOMPS_NOT_ALLOWED_IN_NONBASE_PARTITIONS equ 8011081Bh

; A component cannot be moved (or copied) from the System Application, an application proxy or a non-changeable application
COMADMIN_E_COMP_MOVE_SOURCE equ 8011081Ch

; A component cannot be moved (or copied) to the System Application, an application proxy or a non-changeable application
COMADMIN_E_COMP_MOVE_DEST equ 8011081Dh

; A private component cannot be moved (or copied) to a library application or to the base partition
COMADMIN_E_COMP_MOVE_PRIVATE equ 8011081Eh

; The Base Application Partition exists in all partition sets and cannot be removed.
COMADMIN_E_BASEPARTITION_REQUIRED_IN_SET equ 8011081Fh

; Alas, Event Class components cannot be aliased.
COMADMIN_E_CANNOT_ALIAS_EVENTCLASS equ 80110820h

; Access is denied because the component is private.
COMADMIN_E_PRIVATE_ACCESSDENIED equ 80110821h

; The specified SAFER level is invalid.
COMADMIN_E_SAFERINVALID equ 80110822h

; REMOVE THESE WHEN POSSIBLE
;
; REMOVE THIS ERROR
COMADMIN_E_CAT_DUPLICATE_PARTITION_SET_NAME equ 80110900h

; REMOVE THIS ERROR
COMADMIN_E_CAT_INVALID_PARTITION_SET_NAME equ 80110901h
