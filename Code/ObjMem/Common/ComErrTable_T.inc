; ==================================================================================================
; Title:      ComErrTable_T.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Notes:      Version C.1.0, August 2022
;               - Initial release.
;               - Character independant code.
;               - https://docs.microsoft.com/en-us/windows/win32/com/com-error-codes
; ==================================================================================================


DOM struc
  dCode   DWORD     ?
  pString POINTER   ?
DOM ends

.const
align ALIGN_DATA
ComErrTable \
  DOM {080000001h, $OfsTStr("Not implemented")}
  DOM {080000002h, $OfsTStr("Ran out of memory")}
  DOM {080000003h, $OfsTStr("One or more arguments are invalid")}
  DOM {080000004h, $OfsTStr("No such interface supported")}
  DOM {080000005h, $OfsTStr("Invalid pointer")}
  DOM {080000006h, $OfsTStr("Invalid HANDLE")}
  DOM {080000007h, $OfsTStr("Operation aborted")}
  DOM {080000008h, $OfsTStr("Unspecified error")}
  DOM {080000009h, $OfsTStr("General access denied error")}
  DOM {08000000Ah, $OfsTStr("The data necessary to complete this operation is not yet available.")}
  DOM {08000000Bh, $OfsTStr("The operation attempted to access data outside the valid range")}
  DOM {08000000Ch, $OfsTStr("A concurrent or interleaved operation changed the state of the object")}
  DOM {08000000Dh, $OfsTStr("An illegal state change was requested.")}
  DOM {08000000Eh, $OfsTStr("A method was called at an unexpected time.")}
  DOM {08000000Fh, $OfsTStr("Typename or Namespace was not found in metadata file.")}
  DOM {080000010h, $OfsTStr("Name is an existing namespace rather than a typename.")}
  DOM {080000011h, $OfsTStr("Typename has an invalid format.")}
  DOM {080000012h, $OfsTStr("Metadata file is invalid or corrupted.")}
  DOM {080000013h, $OfsTStr("The object has been closed.")}
  DOM {080000014h, $OfsTStr("Only one thread may access the object during a write operation.")}
  DOM {080000015h, $OfsTStr("Operation is prohibited during change notification.")}
  DOM {080000016h, $OfsTStr("The text associated with this error code could not be found.")}
  DOM {080000017h, $OfsTStr("String not null terminated.")}
  DOM {080000018h, $OfsTStr("A delegate was assigned when not allowed.")}
  DOM {080000019h, $OfsTStr("An async operation was not properly started.")}
  DOM {08000001Ah, $OfsTStr("The application is exiting and cannot service this request.")}
  DOM {08000001Bh, $OfsTStr("The application view is exiting and cannot service this request.")}
  DOM {08000001Ch, $OfsTStr("The object must support the IAgileObject interface.")}
  DOM {08000001Dh, $OfsTStr("Activating a single-threaded class from MTA is not supported.")}
  DOM {08000001Eh, $OfsTStr("The object has been committed.")}
  DOM {080004001h, $OfsTStr("Not implemented")}
  DOM {080004002h, $OfsTStr("No such interface supported")}
  DOM {080004003h, $OfsTStr("Invalid pointer")}
  DOM {080004004h, $OfsTStr("Operation aborted")}
  DOM {080004005h, $OfsTStr("Unspecified error")}
  DOM {080004006h, $OfsTStr("Thread local storage failure")}
  DOM {080004007h, $OfsTStr("Get shared memory allocator failure")}
  DOM {080004008h, $OfsTStr("Get memory allocator failure")}
  DOM {080004009h, $OfsTStr("Unable to initialize class cache")}
  DOM {08000400Ah, $OfsTStr("Unable to initialize RPC services")}
  DOM {08000400Bh, $OfsTStr("Cannot set thread local storage channel control")}
  DOM {08000400Ch, $OfsTStr("Could not allocate thread local storage channel control")}
  DOM {08000400Dh, $OfsTStr("The user supplied memory allocator is unacceptable")}
  DOM {08000400Eh, $OfsTStr("The OLE service mutex already exists")}
  DOM {08000400Fh, $OfsTStr("The OLE service file mapping already exists")}
  DOM {080004010h, $OfsTStr("Unable to map view of file for OLE service")}
  DOM {080004011h, $OfsTStr("Failure attempting to launch OLE service")}
  DOM {080004012h, $OfsTStr("There was an attempt to call CoInitialize a second time while single threaded")}
  DOM {080004013h, $OfsTStr("A Remote activation was necessary but was not allowed")}
  DOM {080004014h, $OfsTStr("A Remote activation was necessary but the server name provided was invalid")}
  DOM {080004015h, $OfsTStr("The class is configured to run as a security id different from the caller")}
  DOM {080004016h, $OfsTStr("Use of Ole1 services requiring DDE windows is disabled")}
  DOM {080004017h, $OfsTStr("A RunAs specification must be \ name or simply")}
  DOM {080004018h, $OfsTStr("The server process could not be started. The pathname may be incorrect.")}
  DOM {080004019h, $OfsTStr("The server process could not be started as the configured identity. The pathname may be incorrect or unavailable.")}
  DOM {08000401Ah, $OfsTStr("The server process could not be started because the configured identity is incorrect. Check the username and password.")}
  DOM {08000401Bh, $OfsTStr("The client is not allowed to launch this server.")}
  DOM {08000401Ch, $OfsTStr("The service providing this server could not be started.")}
  DOM {08000401Eh, $OfsTStr("The server did not respond after being launched.")}
  DOM {080004020h, $OfsTStr("The registration information for this interface is inconsistent or incomplete.")}
  DOM {080004022h, $OfsTStr("A dll must be loaded.")}
  DOM {080004024h, $OfsTStr("The specified activation could not occur in the client context as specified.")}
  DOM {080004026h, $OfsTStr("Activations on the server are not paused.")}
  DOM {080004027h, $OfsTStr("The component or application containing the component has been disabled.")}
  DOM {080004028h, $OfsTStr("The common language runtime is not available")}
  DOM {080004029h, $OfsTStr("The thread-pool rejected the submitted asynchronous work.")}
  DOM {08000402Ah, $OfsTStr("The server started")}
  DOM {08000402Bh, $OfsTStr("Unable to complete the call since there is no COM+ security context inside IObjectControl.Activate.")}
  DOM {080004030h, $OfsTStr("The provided tracker configuration is invalid")}
  DOM {080004031h, $OfsTStr("The provided thread pool configuration is invalid")}
  DOM {080004032h, $OfsTStr("The provided side-by-side configuration is invalid")}
  DOM {080004033h, $OfsTStr("The server principal name (SPN) obtained during security negotiation is malformed.")}
  DOM {08000FFFFh, $OfsTStr("Catastrophic failure")}
  DOM {080010001h, $OfsTStr("Call was rejected by callee.")}
  DOM {080010002h, $OfsTStr("Call was canceled by the message filter.")}
  DOM {080010003h, $OfsTStr("The caller is dispatching an intertask SendMessage call and cannot call out via PostMessage.")}
  DOM {080010004h, $OfsTStr("The caller is dispatching an asynchronous call and cannot make an outgoing call on behalf of this call.")}
  DOM {080010005h, $OfsTStr("It is illegal to call out while inside message filter.")}
  DOM {080010006h, $OfsTStr("The connection terminated or is in a bogus state and cannot be used any more. Other connections are still valid.")}
  DOM {080010007h, $OfsTStr("The callee (server [not server application]) is not available and disappeared; all connections are invalid. The call may have executed.")}
  DOM {080010008h, $OfsTStr("The caller (client) disappeared while the callee (server) was processing a call.")}
  DOM {080010009h, $OfsTStr("The data packet with the marshalled parameter data is incorrect.")}
  DOM {08001000Ah, $OfsTStr("The call was not transmitted properly; the message queue was full and was not emptied after yielding.")}
  DOM {08001000Bh, $OfsTStr("The client (caller) cannot marshal the parameter data - low memory")}
  DOM {08001000Ch, $OfsTStr("The client (caller) cannot unmarshal the return data - low memory")}
  DOM {08001000Dh, $OfsTStr("The server (callee) cannot marshal the return data - low memory")}
  DOM {08001000Eh, $OfsTStr("The server (callee) cannot unmarshal the parameter data - low memory")}
  DOM {08001000Fh, $OfsTStr("Received data is invalid; could be server or client data.")}
  DOM {080010010h, $OfsTStr("A particular parameter is invalid and cannot be (un)marshalled.")}
  DOM {080010011h, $OfsTStr("There is no second outgoing call on same channel in DDE conversation.")}
  DOM {080010012h, $OfsTStr("The callee (server [not server application]) is not available and disappeared; all connections are invalid. The call did not execute.")}
  DOM {080010100h, $OfsTStr("System call failed.")}
  DOM {080010101h, $OfsTStr("Could not allocate some required resource (memory")}
  DOM {080010102h, $OfsTStr("Attempted to make calls on more than one thread in single threaded mode.")}
  DOM {080010103h, $OfsTStr("The requested interface is not registered on the server object.")}
  DOM {080010104h, $OfsTStr("RPC could not call the server or could not return the results of calling the server.")}
  DOM {080010105h, $OfsTStr("The server threw an exception.")}
  DOM {080010106h, $OfsTStr("Cannot change thread mode after it is set.")}
  DOM {080010107h, $OfsTStr("The method called does not exist on the server.")}
  DOM {080010108h, $OfsTStr("The object invoked has disconnected from its clients.")}
  DOM {080010109h, $OfsTStr("The object invoked chose not to process the call now. Try again later.")}
  DOM {08001010Ah, $OfsTStr("The message filter indicated that the application is busy.")}
  DOM {08001010Bh, $OfsTStr("The message filter rejected the call.")}
  DOM {08001010Ch, $OfsTStr("A call control interfaces was called with invalid data.")}
  DOM {08001010Dh, $OfsTStr("An outgoing call cannot be made since the application is dispatching an input-synchronous call.")}
  DOM {08001010Eh, $OfsTStr("The application called an interface that was marshalled for a different thread.")}
  DOM {08001010Fh, $OfsTStr("CoInitialize has not been called on the current thread.")}
  DOM {080010110h, $OfsTStr("The version of OLE on the client and server machines does not match.")}
  DOM {080010111h, $OfsTStr("OLE received a packet with an invalid header.")}
  DOM {080010112h, $OfsTStr("OLE received a packet with an invalid extension.")}
  DOM {080010113h, $OfsTStr("The requested object or interface does not exist.")}
  DOM {080010115h, $OfsTStr("OLE has sent a request and is waiting for a reply.")}
  DOM {080010117h, $OfsTStr("Call context cannot be accessed after call completed.")}
  DOM {080010119h, $OfsTStr("Security must be initialized before any interfaces are marshalled or unmarshalled. It cannot be changed once initialized.")}
  DOM {08001011Bh, $OfsTStr("Access is denied.")}
  DOM {08001011Dh, $OfsTStr("The marshalled interface data packet (OBJREF) has an invalid or unknown format.")}
  DOM {08001011Fh, $OfsTStr("This operation returned because the timeout period expired.")}
  DOM {080010121h, $OfsTStr("Full subject issuer chain SSL principal name expected from the server.")}
  DOM {080010123h, $OfsTStr("Unable to impersonate DCOM client")}
  DOM {080010125h, $OfsTStr("Unable to open the access token of the current thread")}
  DOM {080010127h, $OfsTStr("The client who called IAccessControl::IsAccessPermitted was not the trustee provided to the method")}
  DOM {080010128h, $OfsTStr("Unable to obtain the client's security blanket")}
  DOM {080010129h, $OfsTStr("Unable to set a discretionary ACL into a security descriptor")}
  DOM {08001012Ah, $OfsTStr("The system function")}
  DOM {08001012Bh, $OfsTStr("Either NetAccessDel or NetAccessAdd returned an error code.")}
  DOM {08001012Ch, $OfsTStr("One of the trustee strings provided by the user did not conform to the [Domain]\[Name] syntax and it was not the '*' string")}
  DOM {08001012Dh, $OfsTStr("One of the security identifiers provided by the user was invalid")}
  DOM {08001012Eh, $OfsTStr("Unable to convert a wide character trustee string to a multibyte trustee string")}
  DOM {08001012Fh, $OfsTStr("Unable to find a security identifier that corresponds to a trustee string provided by the user")}
  DOM {080010130h, $OfsTStr("The system function")}
  DOM {080010131h, $OfsTStr("Unable to find a trustee name that corresponds to a security identifier provided by the user")}
  DOM {080010132h, $OfsTStr("The system function")}
  DOM {080010133h, $OfsTStr("Unable to set or reset a serialization handle")}
  DOM {080010134h, $OfsTStr("Unable to obtain the Windows directory")}
  DOM {080010135h, $OfsTStr("Path too long")}
  DOM {080010136h, $OfsTStr("Unable to generate a uuid.")}
  DOM {080010137h, $OfsTStr("Unable to create file")}
  DOM {080010138h, $OfsTStr("Unable to close a serialization handle or a file handle.")}
  DOM {080010139h, $OfsTStr("The number of ACEs in an ACL exceeds the system limit.")}
  DOM {08001013Ah, $OfsTStr("Not all the DENY_ACCESS ACEs are arranged in front of the GRANT_ACCESS ACEs in the stream.")}
  DOM {08001013Bh, $OfsTStr("The version of ACL format in the stream is not supported by this implementation of IAccessControl")}
  DOM {08001013Ch, $OfsTStr("Unable to open the access token of the server process")}
  DOM {08001013Dh, $OfsTStr("Unable to decode the ACL in the stream provided by the user")}
  DOM {08001013Fh, $OfsTStr("The COM IAccessControl object is not initialized")}
  DOM {080010140h, $OfsTStr("Call Cancellation is disabled")}
  DOM {08001FFFFh, $OfsTStr("An internal error occurred.")}
  DOM {080020001h, $OfsTStr("Unknown interface.")}
  DOM {080020003h, $OfsTStr("Member not found.")}
  DOM {080020004h, $OfsTStr("Parameter not found.")}
  DOM {080020005h, $OfsTStr("Type mismatch.")}
  DOM {080020006h, $OfsTStr("Unknown name.")}
  DOM {080020007h, $OfsTStr("No named arguments.")}
  DOM {080020008h, $OfsTStr("Bad variable type.")}
  DOM {080020009h, $OfsTStr("Exception occurred.")}
  DOM {08002000Ah, $OfsTStr("Out of present range. ")}
  DOM {08002000Bh, $OfsTStr("Invalid index.")}
  DOM {08002000Ch, $OfsTStr("Unknown language.")}
  DOM {08002000Dh, $OfsTStr("Memory is locked.")}
  DOM {08002000Eh, $OfsTStr("Invalid number of parameters.")}
  DOM {08002000Fh, $OfsTStr("Parameter not optional.")}
  DOM {080020010h, $OfsTStr("Invalid callee.")}
  DOM {080020011h, $OfsTStr("Does not support a collection.")}
  DOM {080020012h, $OfsTStr("Division by zero.")}
  DOM {080020013h, $OfsTStr("Buffer too small")}
  DOM {080028016h, $OfsTStr("Buffer too small.")}
  DOM {080028017h, $OfsTStr("Field name not defined in the record.")}
  DOM {080028018h, $OfsTStr("Old format or invalid type library.")}
  DOM {080028019h, $OfsTStr("Old format or invalid type library.")}
  DOM {08002801Ch, $OfsTStr("Error accessing the OLE registry.")}
  DOM {08002801Dh, $OfsTStr("Library not registered.")}
  DOM {080028027h, $OfsTStr("Bound to unknown type.")}
  DOM {080028028h, $OfsTStr("Qualified name disallowed.")}
  DOM {080028029h, $OfsTStr("Invalid forward reference")}
  DOM {08002802Ah, $OfsTStr("Type mismatch.")}
  DOM {08002802Bh, $OfsTStr("Element not found.")}
  DOM {08002802Ch, $OfsTStr("Ambiguous name.")}
  DOM {08002802Dh, $OfsTStr("Name already exists in the library.")}
  DOM {08002802Eh, $OfsTStr("Unknown LCID.")}
  DOM {08002802Fh, $OfsTStr("Function not defined in specified DLL.")}
  DOM {0800288BDh, $OfsTStr("Wrong module kind for the operation.")}
  DOM {0800288C5h, $OfsTStr("Size may not exceed 64K.")}
  DOM {0800288C6h, $OfsTStr("Duplicate ID in inheritance hierarchy.")}
  DOM {0800288CFh, $OfsTStr("Incorrect inheritance depth in standard OLE hmember.")}
  DOM {080028CA0h, $OfsTStr("Type mismatch.")}
  DOM {080028CA1h, $OfsTStr("Invalid number of arguments.")}
  DOM {080028CA2h, $OfsTStr("I/O Error.")}
  DOM {080028CA3h, $OfsTStr("Error creating unique tmp file.")}
  DOM {080029C4Ah, $OfsTStr("Error loading type library/DLL.")}
  DOM {080029C83h, $OfsTStr("Inconsistent property functions.")}
  DOM {080029C84h, $OfsTStr("Circular dependency between types/modules.")}
  DOM {080030001h, $OfsTStr("Unable to perform requested operation.")}
  DOM {080030002h, $OfsTStr("could not be found.")}
  DOM {080030003h, $OfsTStr("The path %1 could not be found.")}
  DOM {080030004h, $OfsTStr("There are insufficient resources to open another file.")}
  DOM {080030005h, $OfsTStr("Access Denied.")}
  DOM {080030006h, $OfsTStr("Attempted an operation on an invalid object.")}
  DOM {080030008h, $OfsTStr("There is insufficient memory available to complete operation.")}
  DOM {080030009h, $OfsTStr("Invalid pointer error.")}
  DOM {080030012h, $OfsTStr("There are no more entries to return.")}
  DOM {080030013h, $OfsTStr("Disk is write-protected.")}
  DOM {080030019h, $OfsTStr("An error occurred during a seek operation.")}
  DOM {08003001Dh, $OfsTStr("A disk error occurred during a write operation.")}
  DOM {08003001Eh, $OfsTStr("A disk error occurred during a read operation.")}
  DOM {080030020h, $OfsTStr("A share violation has occurred.")}
  DOM {080030021h, $OfsTStr("A lock violation has occurred.")}
  DOM {080030050h, $OfsTStr("already exists.")}
  DOM {080030057h, $OfsTStr("Invalid parameter error.")}
  DOM {080030070h, $OfsTStr("There is insufficient disk space to complete operation.")}
  DOM {0800300F0h, $OfsTStr("Illegal write of non-simple property to simple property set.")}
  DOM {0800300FAh, $OfsTStr("An API call exited abnormally.")}
  DOM {0800300FBh, $OfsTStr("The file %1 is not a valid compound file.")}
  DOM {0800300FCh, $OfsTStr("The name %1 is not valid.")}
  DOM {0800300FDh, $OfsTStr("An unexpected error occurred.")}
  DOM {0800300FEh, $OfsTStr("That function is not implemented.")}
  DOM {0800300FFh, $OfsTStr("Invalid flag error.")}
  DOM {080030100h, $OfsTStr("Attempted to use an object that is busy.")}
  DOM {080030101h, $OfsTStr("The storage has been changed since the last commit.")}
  DOM {080030102h, $OfsTStr("Attempted to use an object that has ceased to exist.")}
  DOM {080030103h, $OfsTStr("Can't save.")}
  DOM {080030104h, $OfsTStr("The compound file %1 was produced with an incompatible version of storage.")}
  DOM {080030105h, $OfsTStr("The compound file %1 was produced with a newer version of storage.")}
  DOM {080030106h, $OfsTStr("Share.exe or equivalent is required for operation.")}
  DOM {080030107h, $OfsTStr("Illegal operation called on non-file based storage.")}
  DOM {080030108h, $OfsTStr("Illegal operation called on object with extant marshallings.")}
  DOM {080030109h, $OfsTStr("The docfile has been corrupted.")}
  DOM {080030110h, $OfsTStr("OLE32.DLL has been loaded at the wrong address.")}
  DOM {080030111h, $OfsTStr("The compound file is too large for the current implementation")}
  DOM {080030112h, $OfsTStr("The compound file was not created with the STGM_SIMPLE flag")}
  DOM {080030201h, $OfsTStr("The file download was aborted abnormally. The file is incomplete.")}
  DOM {080030202h, $OfsTStr("The file download has been terminated.")}
  DOM {080030305h, $OfsTStr("Generic Copy Protection Error.")}
  DOM {080030306h, $OfsTStr("Copy Protection Error - DVD CSS Authentication failed.")}
  DOM {080030307h, $OfsTStr("Copy Protection Error - The given sector does not have a valid CSS key.")}
  DOM {080030308h, $OfsTStr("Copy Protection Error - DVD session key not established.")}
  DOM {080030309h, $OfsTStr("Copy Protection Error - The read failed because the sector is encrypted.")}
  DOM {08003030Ah, $OfsTStr("Copy Protection Error - The current DVD's region does not correspond to the region setting of the drive.")}
  DOM {08003030Bh, $OfsTStr("Copy Protection Error - The drive's region setting may be permanent or the number of user resets has been exhausted.")}
  DOM {080040000h, $OfsTStr("Invalid OLEVERB structure")}
  DOM {080040001h, $OfsTStr("Invalid advise flags")}
  DOM {080040002h, $OfsTStr("Can't enumerate any more")}
  DOM {080040003h, $OfsTStr("This implementation doesn't take advises")}
  DOM {080040004h, $OfsTStr("There is no connection for this connection ID")}
  DOM {080040005h, $OfsTStr("Need to run the object to perform this operation")}
  DOM {080040006h, $OfsTStr("There is no cache to operate on")}
  DOM {080040007h, $OfsTStr("Uninitialized object")}
  DOM {080040008h, $OfsTStr("Linked object's source class has changed")}
  DOM {080040009h, $OfsTStr("Not able to get the moniker of the object")}
  DOM {08004000Ah, $OfsTStr("Not able to bind to the source")}
  DOM {08004000Bh, $OfsTStr("Object is static; operation not allowed")}
  DOM {08004000Ch, $OfsTStr("User canceled out of save dialog")}
  DOM {08004000Dh, $OfsTStr("Invalid rectangle")}
  DOM {08004000Eh, $OfsTStr("compobj.dll is too old for the ole2.dll initialized")}
  DOM {08004000Fh, $OfsTStr("Invalid window handle")}
  DOM {080040010h, $OfsTStr("Object is not in any of the inplace active states")}
  DOM {080040011h, $OfsTStr("Not able to convert object")}
  DOM {080040012h, $OfsTStr("Not able to perform the operation because object is not given storage yet")}
  DOM {080040064h, $OfsTStr("Invalid FORMATETC structure")}
  DOM {080040065h, $OfsTStr("Invalid DVTARGETDEVICE structure")}
  DOM {080040066h, $OfsTStr("Invalid STDGMEDIUM structure")}
  DOM {080040067h, $OfsTStr("Invalid STATDATA structure")}
  DOM {080040068h, $OfsTStr("Invalid lindex")}
  DOM {080040069h, $OfsTStr("Invalid tymed")}
  DOM {08004006Ah, $OfsTStr("Invalid clipboard format")}
  DOM {08004006Bh, $OfsTStr("Invalid aspect(s)")}
  DOM {08004006Ch, $OfsTStr("tdSize parameter of the DVTARGETDEVICE structure is invalid")}
  DOM {08004006Dh, $OfsTStr("Object doesn't support IViewObject interface")}
  DOM {080040100h, $OfsTStr("Trying to revoke a drop target that has not been registered")}
  DOM {080040101h, $OfsTStr("This window has already been registered as a drop target")}
  DOM {080040102h, $OfsTStr("Invalid window handle")}
  DOM {080040110h, $OfsTStr("Class does not support aggregation (or class object is remote)")}
  DOM {080040111h, $OfsTStr("ClassFactory cannot supply requested class")}
  DOM {080040112h, $OfsTStr("Class is not licensed for use")}
  DOM {080040140h, $OfsTStr("Error drawing view")}
  DOM {080040150h, $OfsTStr("Could not read key from registry")}
  DOM {080040151h, $OfsTStr("Could not write key to registry")}
  DOM {080040152h, $OfsTStr("Could not find the key in the registry")}
  DOM {080040153h, $OfsTStr("Invalid value for registry")}
  DOM {080040154h, $OfsTStr("Class not registered")}
  DOM {080040155h, $OfsTStr("Interface not registered")}
  DOM {080040156h, $OfsTStr("Threading model entry is not valid")}
  DOM {080040160h, $OfsTStr("CATID does not exist")}
  DOM {080040161h, $OfsTStr("Description not found")}
  DOM {080040164h, $OfsTStr("No package in the software installation data in the Active Directory meets this criteria.")}
  DOM {080040165h, $OfsTStr("Deleting this will break the referential integrity of the software installation data in the Active Directory.")}
  DOM {080040166h, $OfsTStr("The CLSID was not found in the software installation data in the Active Directory.")}
  DOM {080040167h, $OfsTStr("The software installation data in the Active Directory is corrupt.")}
  DOM {080040168h, $OfsTStr("There is no software installation data in the Active Directory.")}
  DOM {080040169h, $OfsTStr("There is no software installation data object in the Active Directory.")}
  DOM {08004016Ah, $OfsTStr("The software installation data object in the Active Directory already exists.")}
  DOM {08004016Bh, $OfsTStr("The path to the software installation data in the Active Directory is not correct.")}
  DOM {08004016Ch, $OfsTStr("A network error interrupted the operation.")}
  DOM {08004016Dh, $OfsTStr("The size of this object exceeds the maximum size set by the Administrator.")}
  DOM {08004016Eh, $OfsTStr("The schema for the software installation data in the Active Directory does not match the required schema.")}
  DOM {08004016Fh, $OfsTStr("An error occurred in the software installation data in the Active Directory.")}
  DOM {080040170h, $OfsTStr("Cache not updated")}
  DOM {080040180h, $OfsTStr("No verbs for OLE object")}
  DOM {080040181h, $OfsTStr("Invalid verb for OLE object")}
  DOM {0800401A0h, $OfsTStr("Undo is not available")}
  DOM {0800401A1h, $OfsTStr("Space for tools is not available")}
  DOM {0800401C0h, $OfsTStr("OLESTREAM Get method failed")}
  DOM {0800401C1h, $OfsTStr("OLESTREAM Put method failed")}
  DOM {0800401C2h, $OfsTStr("Contents of the OLESTREAM not in correct format")}
  DOM {0800401C3h, $OfsTStr("There was an error in a Windows GDI call while converting the bitmap to a DIB")}
  DOM {0800401C4h, $OfsTStr("Contents of the IStorage not in correct format")}
  DOM {0800401C5h, $OfsTStr("Contents of IStorage is missing one of the standard streams")}
  DOM {0800401C6h, $OfsTStr("There was an error in a Windows GDI call while converting the DIB to a bitmap.")}
  DOM {0800401D0h, $OfsTStr("OpenClipboard Failed")}
  DOM {0800401D1h, $OfsTStr("EmptyClipboard Failed")}
  DOM {0800401D2h, $OfsTStr("SetClipboard Failed")}
  DOM {0800401D3h, $OfsTStr("Data on clipboard is invalid")}
  DOM {0800401D4h, $OfsTStr("CloseClipboard Failed")}
  DOM {0800401E0h, $OfsTStr("Moniker needs to be connected manually")}
  DOM {0800401E1h, $OfsTStr("Operation exceeded deadline")}
  DOM {0800401E2h, $OfsTStr("Moniker needs to be generic")}
  DOM {0800401E3h, $OfsTStr("Operation unavailable")}
  DOM {0800401E4h, $OfsTStr("Invalid syntax")}
  DOM {0800401E5h, $OfsTStr("No object for moniker")}
  DOM {0800401E6h, $OfsTStr("Bad extension for file")}
  DOM {0800401E7h, $OfsTStr("Intermediate operation failed")}
  DOM {0800401E8h, $OfsTStr("Moniker is not bindable")}
  DOM {0800401E9h, $OfsTStr("Moniker is not bound")}
  DOM {0800401EAh, $OfsTStr("Moniker cannot open file")}
  DOM {0800401EBh, $OfsTStr("User input required for operation to succeed")}
  DOM {0800401ECh, $OfsTStr("Moniker class has no inverse")}
  DOM {0800401EDh, $OfsTStr("Moniker does not refer to storage")}
  DOM {0800401EEh, $OfsTStr("No common prefix")}
  DOM {0800401EFh, $OfsTStr("Moniker could not be enumerated")}
  DOM {0800401F0h, $OfsTStr("CoInitialize has not been called.")}
  DOM {0800401F1h, $OfsTStr("CoInitialize has already been called.")}
  DOM {0800401F2h, $OfsTStr("Class of object cannot be determined")}
  DOM {0800401F3h, $OfsTStr("Invalid class string")}
  DOM {0800401F4h, $OfsTStr("Invalid interface string")}
  DOM {0800401F5h, $OfsTStr("Application not found")}
  DOM {0800401F6h, $OfsTStr("Application cannot be run more than once")}
  DOM {0800401F7h, $OfsTStr("Some error in application program")}
  DOM {0800401F8h, $OfsTStr("DLL for class not found")}
  DOM {0800401F9h, $OfsTStr("Error in the DLL")}
  DOM {0800401FAh, $OfsTStr("Wrong operating system or operating system version for the application")}
  DOM {0800401FBh, $OfsTStr("Object is not registered")}
  DOM {0800401FCh, $OfsTStr("Object is already registered")}
  DOM {0800401FDh, $OfsTStr("Object is not connected to server")}
  DOM {0800401FEh, $OfsTStr("Application was launched but it didn't register a class factory")}
  DOM {0800401FFh, $OfsTStr("Object has been released")}
  DOM {080040201h, $OfsTStr("An event was unable to invoke any of the subscribers")}
  DOM {080040203h, $OfsTStr("A syntax error occurred trying to evaluate a query string")}
  DOM {080040204h, $OfsTStr("An invalid field name was used in a query string")}
  DOM {080040205h, $OfsTStr("An unexpected exception was raised")}
  DOM {080040206h, $OfsTStr("An unexpected internal error was detected")}
  DOM {080040207h, $OfsTStr("The owner SID on a per-user subscription doesn't exist")}
  DOM {080040208h, $OfsTStr("A user-supplied component or subscriber raised an exception")}
  DOM {080040209h, $OfsTStr("An interface has too many methods to fire events from")}
  DOM {08004020Ah, $OfsTStr("A subscription cannot be stored unless its event class already exists")}
  DOM {08004020Bh, $OfsTStr("Not all the objects requested could be removed")}
  DOM {08004020Ch, $OfsTStr("COM+ is required for this operation")}
  DOM {08004020Dh, $OfsTStr("Cannot modify or delete an object that was not added using the COM+ Admin SDK")}
  DOM {08004020Eh, $OfsTStr("Cannot modify or delete an object that was added using the COM+ Admin SDK")}
  DOM {08004020Fh, $OfsTStr("The event class for this subscription is in an invalid partition")}
  DOM {080040210h, $OfsTStr("The owner of the PerUser subscription is not logged on to the system specified")}
  DOM {080041309h, $OfsTStr("Trigger not found.")}
  DOM {08004130Ah, $OfsTStr("One or more of the properties that are needed to run this task have not been set.")}
  DOM {08004130Bh, $OfsTStr("There is no running instance of the task.")}
  DOM {08004130Ch, $OfsTStr("The Task Scheduler Service is not installed on this computer.")}
  DOM {08004130Dh, $OfsTStr("The task object could not be opened.")}
  DOM {08004130Eh, $OfsTStr("The object is either an invalid task object or is not a task object.")}
  DOM {08004130Fh, $OfsTStr("No account information could be found in the Task Scheduler security database for the task indicated.")}
  DOM {080041310h, $OfsTStr("Unable to establish existence of the account specified.")}
  DOM {080041311h, $OfsTStr("Corruption was detected in the Task Scheduler security database; the database has been reset.")}
  DOM {080041312h, $OfsTStr("Task Scheduler security services are not available.")}
  DOM {080041313h, $OfsTStr("The task object version is either unsupported or invalid.")}
  DOM {080041314h, $OfsTStr("The task has been configured with an unsupported combination of account settings and run time options.")}
  DOM {080041315h, $OfsTStr("The Task Scheduler Service is not running.")}
  DOM {080041316h, $OfsTStr("The task XML contains an unexpected node.")}
  DOM {080041317h, $OfsTStr("The task XML contains an element or attribute from an unexpected namespace.")}
  DOM {080041318h, $OfsTStr("The task XML contains a value which is incorrectly formatted or out of range.")}
  DOM {080041319h, $OfsTStr("The task XML is missing a required element or attribute.")}
  DOM {08004131Ah, $OfsTStr("The task XML is malformed.")}
  DOM {08004131Dh, $OfsTStr("The task XML contains too many nodes of the same type.")}
  DOM {08004131Eh, $OfsTStr("The task cannot be started after the trigger's end boundary.")}
  DOM {08004131Fh, $OfsTStr("An instance of this task is already running.")}
  DOM {080041320h, $OfsTStr("The task will not run because the user is not logged on.")}
  DOM {080041321h, $OfsTStr("The task image is corrupt or has been tampered with.")}
  DOM {080041322h, $OfsTStr("The Task Scheduler service is not available.")}
  DOM {080041323h, $OfsTStr("The Task Scheduler service is too busy to handle your request. Please try again later.")}
  DOM {080041324h, $OfsTStr("The Task Scheduler service attempted to run the task")}
  DOM {080041326h, $OfsTStr("The task is disabled.")}
  DOM {080041327h, $OfsTStr("The task has properties that are not compatible with previous versions of Windows.")}
  DOM {080041328h, $OfsTStr("The task settings do not allow the task to start on demand.")}
  DOM {080041329h, $OfsTStr("The combination of properties that task is using is not compatible with the scheduling engine.")}
  DOM {08004D000h, $OfsTStr("Another single phase resource manager has already been enlisted in this transaction.")}
  DOM {08004D001h, $OfsTStr("A retaining commit or abort is not supported")}
  DOM {08004D002h, $OfsTStr("The transaction failed to commit for an unknown reason. The transaction was aborted.")}
  DOM {08004D003h, $OfsTStr("Cannot call commit on this transaction object because the calling application did not initiate the transaction.")}
  DOM {08004D004h, $OfsTStr("Instead of committing")}
  DOM {08004D005h, $OfsTStr("Instead of aborting")}
  DOM {08004D006h, $OfsTStr("Some of the states of the resource were committed while others were aborted")}
  DOM {08004D007h, $OfsTStr("Some of the states of the resource may have been committed while others may have been aborted")}
  DOM {08004D008h, $OfsTStr("The requested isolation level is not valid or supported.")}
  DOM {08004D009h, $OfsTStr("The transaction manager doesn't support an asynchronous operation for this method.")}
  DOM {08004D00Ah, $OfsTStr("Unable to enlist in the transaction.")}
  DOM {08004D00Bh, $OfsTStr("The requested semantics of retention of isolation across retaining commit and abort boundaries cannot be supported by this transaction implementation")}
  DOM {08004D00Ch, $OfsTStr("There is no resource presently associated with this enlistment")}
  DOM {08004D00Dh, $OfsTStr("The transaction failed to commit due to the failure of optimistic concurrency control in at least one of the resource managers.")}
  DOM {08004D00Eh, $OfsTStr("The transaction has already been implicitly or explicitly committed or aborted")}
  DOM {08004D00Fh, $OfsTStr("An invalid combination of flags was specified")}
  DOM {08004D010h, $OfsTStr("The resource manager id is not associated with this transaction or the transaction manager.")}
  DOM {08004D011h, $OfsTStr("This method was called in the wrong state")}
  DOM {08004D012h, $OfsTStr("The indicated unit of work does not match the unit of work expected by the resource manager.")}
  DOM {08004D013h, $OfsTStr("An enlistment in a transaction already exists.")}
  DOM {08004D014h, $OfsTStr("An import object for the transaction could not be found.")}
  DOM {08004D015h, $OfsTStr("The transaction cookie is invalid.")}
  DOM {08004D016h, $OfsTStr("The transaction status is in doubt. A communication failure occurred")}
  DOM {08004D017h, $OfsTStr("A time-out was specified")}
  DOM {08004D018h, $OfsTStr("The requested operation is already in progress for the transaction.")}
  DOM {08004D019h, $OfsTStr("The transaction has already been aborted.")}
  DOM {08004D01Ah, $OfsTStr("The Transaction Manager returned a log full error.")}
  DOM {08004D01Bh, $OfsTStr("The Transaction Manager is not available.")}
  DOM {08004D01Ch, $OfsTStr("A connection with the transaction manager was lost.")}
  DOM {08004D01Dh, $OfsTStr("A request to establish a connection with the transaction manager was denied.")}
  DOM {08004D01Eh, $OfsTStr("Resource manager reenlistment to determine transaction status timed out.")}
  DOM {08004D01Fh, $OfsTStr("This transaction manager failed to establish a connection with another TIP transaction manager.")}
  DOM {08004D020h, $OfsTStr("This transaction manager encountered a protocol error with another TIP transaction manager.")}
  DOM {08004D021h, $OfsTStr("This transaction manager could not propagate a transaction from another TIP transaction manager.")}
  DOM {08004D022h, $OfsTStr("The Transaction Manager on the destination machine is not available.")}
  DOM {08004D023h, $OfsTStr("The Transaction Manager has disabled its support for TIP.")}
  DOM {08004D024h, $OfsTStr("The transaction manager has disabled its support for remote/network transactions.")}
  DOM {08004D025h, $OfsTStr("The partner transaction manager has disabled its support for remote/network transactions.")}
  DOM {08004D026h, $OfsTStr("The transaction manager has disabled its support for XA transactions.")}
  DOM {08004D027h, $OfsTStr("MSDTC was unable to read its configuration information.")}
  DOM {08004D028h, $OfsTStr("MSDTC was unable to load the dtc proxy dll.")}
  DOM {08004D029h, $OfsTStr("The local transaction has aborted.")}
  DOM {08004D02Ah, $OfsTStr("The MSDTC transaction manager was unable to push the transaction to the destination transaction manager due to communication problems. Possible causes are: a firewall is present and it doesn't have an exception for the MSDTC process")}
  DOM {08004D02Bh, $OfsTStr("The MSDTC transaction manager was unable to pull the transaction from the source transaction manager due to communication problems. Possible causes are: a firewall is present and it doesn't have an exception for the MSDTC process")}
  DOM {08004D02Ch, $OfsTStr("The MSDTC transaction manager has disabled its support for SNA LU 6.2 transactions.")}
  DOM {08004D080h, $OfsTStr("XACT_E_CLERKNOTFOUND")}
  DOM {08004D081h, $OfsTStr("XACT_E_CLERKEXISTS")}
  DOM {08004D082h, $OfsTStr("XACT_E_RECOVERYINPROGRESS")}
  DOM {08004D083h, $OfsTStr("XACT_E_TRANSACTIONCLOSED")}
  DOM {08004D084h, $OfsTStr("XACT_E_INVALIDLSN")}
  DOM {08004D085h, $OfsTStr("XACT_E_REPLAYREQUEST")}
  DOM {08004E002h, $OfsTStr("The root transaction wanted to commit")}
  DOM {08004E003h, $OfsTStr("You made a method call on a COM+ component that has a transaction that has already aborted or in the process of aborting.")}
  DOM {08004E004h, $OfsTStr("There is no MTS object context")}
  DOM {08004E005h, $OfsTStr("The component is configured to use synchronization and this method call would cause a deadlock to occur.")}
  DOM {08004E006h, $OfsTStr("The component is configured to use synchronization and a thread has timed out waiting to enter the context.")}
  DOM {08004E007h, $OfsTStr("You made a method call on a COM+ component that has a transaction that has already committed or aborted.")}
  DOM {08004E00Ch, $OfsTStr("The specified role was not configured for the application")}
  DOM {08004E00Fh, $OfsTStr("COM+ was unable to talk to the Microsoft Distributed Transaction Coordinator")}
  DOM {08004E021h, $OfsTStr("An unexpected error occurred during COM+ Activation.")}
  DOM {08004E022h, $OfsTStr("COM+ Activation failed. Check the event log for more information")}
  DOM {08004E023h, $OfsTStr("COM+ Activation failed due to a catalog or configuration error.")}
  DOM {08004E024h, $OfsTStr("COM+ activation failed because the activation could not be completed in the specified amount of time.")}
  DOM {08004E025h, $OfsTStr("COM+ Activation failed because an initialization function failed. Check the event log for more information.")}
  DOM {08004E026h, $OfsTStr("The requested operation requires that JIT be in the current context and it is not")}
  DOM {08004E027h, $OfsTStr("The requested operation requires that the current context have a Transaction")}
  DOM {08004E028h, $OfsTStr("The components threading model has changed after install into a COM+ Application. Please re-install component.")}
  DOM {08004E029h, $OfsTStr("IIS intrinsics not available. Start your work with IIS.")}
  DOM {08004E02Ah, $OfsTStr("An attempt to write a cookie failed.")}
  DOM {08004E02Bh, $OfsTStr("An attempt to use a database generated a database specific error.")}
  DOM {08004E02Ch, $OfsTStr("The COM+ component you created must use object pooling to work.")}
  DOM {08004E02Dh, $OfsTStr("The COM+ component you created must use object construction to work correctly.")}
  DOM {08004E02Eh, $OfsTStr("The COM+ component requires synchronization")}
  DOM {08004E02Fh, $OfsTStr("The TxIsolation Level property for the COM+ component being created is stronger than the TxIsolationLevel for the 'root' component for the transaction. The creation failed.")}
  DOM {08004E030h, $OfsTStr("The component attempted to make a cross-context call between invocations of EnterTransactionScopeand ExitTransactionScope. This is not allowed. Cross-context calls cannot be made while inside of a transaction scope.")}
  DOM {08004E031h, $OfsTStr("The component made a call to EnterTransactionScope")}
  DOM {080070005h, $OfsTStr("General access denied error")}
  DOM {080070006h, $OfsTStr("Invalid handle")}
  DOM {08007000Eh, $OfsTStr("Ran out of memory")}
  DOM {080070057h, $OfsTStr("One or more arguments are invalid")}
  DOM {080080001h, $OfsTStr("Attempt to create a class object failed")}
  DOM {080080002h, $OfsTStr("OLE service could not bind object")}
  DOM {080080003h, $OfsTStr("RPC communication failed with OLE service")}
  DOM {080080004h, $OfsTStr("Bad path to object")}
  DOM {080080005h, $OfsTStr("Server execution failed")}
  DOM {080080006h, $OfsTStr("OLE service could not communicate with the object server")}
  DOM {080080007h, $OfsTStr("Moniker path could not be normalized")}
  DOM {080080008h, $OfsTStr("Object server is stopping when OLE service contacts it")}
  DOM {080080009h, $OfsTStr("An invalid root block pointer was specified")}
  DOM {080080010h, $OfsTStr("An allocation chain contained an invalid link pointer")}
  DOM {080080011h, $OfsTStr("The requested allocation size was too large")}
  DOM {080080015h, $OfsTStr("The activation requires a display name to be present under the CLSID key.")}
  DOM {080080016h, $OfsTStr("The activation requires that the RunAs value for the application is Activate As Activator.")}
  DOM {080080017h, $OfsTStr("The class is not configured to support Elevated activation.")}
  DOM {080080200h, $OfsTStr("The packaging API has encountered an internal error.")}
  DOM {080080201h, $OfsTStr("The file is not a valid package because its contents are interleaved.")}
  DOM {080080202h, $OfsTStr("The file is not a valid package because it contains OPC relationships.")}
  DOM {080080203h, $OfsTStr("The file is not a valid package because it is missing a manifest or block map")}
  DOM {080080204h, $OfsTStr("The package's manifest is invalid.")}
  DOM {080080205h, $OfsTStr("The package's block map is invalid.")}
  DOM {080080206h, $OfsTStr("The package's content cannot be read because it is corrupt.")}
  DOM {080080207h, $OfsTStr("The computed hash value of the block does not match the one stored in the block map.")}
  DOM {080080208h, $OfsTStr("The requested byte range is over 4GB when translated to byte range of blocks.")}
  DOM {080080209h, $OfsTStr("The SIP_SUBJECTINFO structure used to sign the package didn't contain the required data.")}
  DOM {080090001h, $OfsTStr("Bad UID.")}
  DOM {080090002h, $OfsTStr("Bad Hash.")}
  DOM {080090003h, $OfsTStr("Bad Key.")}
  DOM {080090004h, $OfsTStr("Bad Length.")}
  DOM {080090005h, $OfsTStr("Bad Data.")}
  DOM {080090006h, $OfsTStr("Invalid Signature.")}
  DOM {080090007h, $OfsTStr("Bad Version of provider.")}
  DOM {080090008h, $OfsTStr("Invalid algorithm specified.")}
  DOM {080090009h, $OfsTStr("Invalid flags specified.")}
  DOM {08009000Ah, $OfsTStr("Invalid type specified.")}
  DOM {08009000Bh, $OfsTStr("Key not valid for use in specified state.")}
  DOM {08009000Ch, $OfsTStr("Hash not valid for use in specified state.")}
  DOM {08009000Dh, $OfsTStr("Key does not exist.")}
  DOM {08009000Eh, $OfsTStr("Insufficient memory available for the operation.")}
  DOM {08009000Fh, $OfsTStr("Object already exists.")}
  DOM {080090010h, $OfsTStr("Access denied.")}
  DOM {080090011h, $OfsTStr("Object was not found.")}
  DOM {080090012h, $OfsTStr("Data already encrypted.")}
  DOM {080090013h, $OfsTStr("Invalid provider specified.")}
  DOM {080090014h, $OfsTStr("Invalid provider type specified.")}
  DOM {080090015h, $OfsTStr("Provider's public key is invalid.")}
  DOM {080090016h, $OfsTStr("Keyset does not exist")}
  DOM {080090017h, $OfsTStr("Provider type not defined.")}
  DOM {080090018h, $OfsTStr("Provider type as registered is invalid.")}
  DOM {080090019h, $OfsTStr("The keyset is not defined.")}
  DOM {08009001Ah, $OfsTStr("Keyset as registered is invalid.")}
  DOM {08009001Bh, $OfsTStr("Provider type does not match registered value.")}
  DOM {08009001Ch, $OfsTStr("The digital signature file is corrupt.")}
  DOM {08009001Dh, $OfsTStr("Provider DLL failed to initialize correctly.")}
  DOM {08009001Eh, $OfsTStr("Provider DLL could not be found.")}
  DOM {08009001Fh, $OfsTStr("The Keyset parameter is invalid.")}
  DOM {080090020h, $OfsTStr("An internal error occurred.")}
  DOM {080090021h, $OfsTStr("A base error occurred.")}
  DOM {080090022h, $OfsTStr("Provider could not perform the action since the context was acquired as silent.")}
  DOM {080090023h, $OfsTStr("The security token does not have storage space available for an additional container.")}
  DOM {080090024h, $OfsTStr("The profile for the user is a temporary profile.")}
  DOM {080090025h, $OfsTStr("The key parameters could not be set because the CSP uses fixed parameters.")}
  DOM {080090026h, $OfsTStr("The supplied handle is invalid.")}
  DOM {080090027h, $OfsTStr("The parameter is incorrect.")}
  DOM {080090028h, $OfsTStr("The buffer supplied to a function was too small.")}
  DOM {080090029h, $OfsTStr("The requested operation is not supported.")}
  DOM {08009002Ah, $OfsTStr("No more data is available.")}
  DOM {08009002Bh, $OfsTStr("The supplied buffers overlap incorrectly.")}
  DOM {08009002Ch, $OfsTStr("The specified data could not be decrypted.")}
  DOM {08009002Dh, $OfsTStr("An internal consistency check failed.")}
  DOM {08009002Eh, $OfsTStr("This operation requires input from the user.")}
  DOM {08009002Fh, $OfsTStr("The cryptographic provider does not support HMAC.")}
  DOM {080090030h, $OfsTStr("The device that is required by this cryptographic provider is not ready for use.")}
  DOM {080090031h, $OfsTStr("The dictionary attack mitigation is triggered and the provided authorization was ignored by the provider.")}
  DOM {080090032h, $OfsTStr("The validation of the provided data failed the integrity or signature validation.")}
  DOM {080090033h, $OfsTStr("Incorrect password.")}
  DOM {080090034h, $OfsTStr("Encryption failed.")}
  DOM {080090300h, $OfsTStr("Not enough memory is available to complete this request")}
  DOM {080090301h, $OfsTStr("The handle specified is invalid")}
  DOM {080090302h, $OfsTStr("The function requested is not supported")}
  DOM {080090303h, $OfsTStr("The specified target is unknown or unreachable")}
  DOM {080090304h, $OfsTStr("The Local Security Authority cannot be contacted")}
  DOM {080090305h, $OfsTStr("The requested security package does not exist")}
  DOM {080090306h, $OfsTStr("The caller is not the owner of the desired credentials")}
  DOM {080090307h, $OfsTStr("The security package failed to initialize")}
  DOM {080090308h, $OfsTStr("The token supplied to the function is invalid")}
  DOM {080090309h, $OfsTStr("The security package is not able to marshal the logon buffer")}
  DOM {08009030Ah, $OfsTStr("The per-message Quality of Protection is not supported by the security package")}
  DOM {08009030Bh, $OfsTStr("The security context does not allow impersonation of the client")}
  DOM {08009030Ch, $OfsTStr("The logon attempt failed")}
  DOM {08009030Dh, $OfsTStr("The credentials supplied to the package were not recognized")}
  DOM {08009030Eh, $OfsTStr("No credentials are available in the security package")}
  DOM {08009030Fh, $OfsTStr("The message or signature supplied for verification has been altered")}
  DOM {080090310h, $OfsTStr("The message supplied for verification is out of sequence")}
  DOM {080090311h, $OfsTStr("No authority could be contacted for authentication.")}
  DOM {080090316h, $OfsTStr("The requested security package does not exist")}
  DOM {080090317h, $OfsTStr("The context has expired and can no longer be used.")}
  DOM {080090318h, $OfsTStr("The supplied message is incomplete. The signature was not verified.")}
  DOM {080090320h, $OfsTStr("The credentials supplied were not complete")}
  DOM {080090321h, $OfsTStr("The buffers supplied to a function was too small.")}
  DOM {080090322h, $OfsTStr("The target principal name is incorrect.")}
  DOM {080090324h, $OfsTStr("The clocks on the client and server machines are skewed.")}
  DOM {080090325h, $OfsTStr("The certificate chain was issued by an authority that is not trusted.")}
  DOM {080090326h, $OfsTStr("The message received was unexpected or badly formatted.")}
  DOM {080090327h, $OfsTStr("An unknown error occurred while processing the certificate.")}
  DOM {080090328h, $OfsTStr("The received certificate has expired.")}
  DOM {080090329h, $OfsTStr("The specified data could not be encrypted.")}
  DOM {080090330h, $OfsTStr("The specified data could not be decrypted.")}
  DOM {080090331h, $OfsTStr("The client and server cannot communicate")}
  DOM {080090332h, $OfsTStr("The security context could not be established due to a failure in the requested quality of service (e.g. mutual authentication or delegation).")}
  DOM {080090333h, $OfsTStr("A security context was deleted before the context was completed. This is considered a logon failure.")}
  DOM {080090334h, $OfsTStr("The client is trying to negotiate a context and the server requires user-to-user but didn't send a TGT reply.")}
  DOM {080090335h, $OfsTStr("Unable to accomplish the requested task because the local machine does not have any IP addresses.")}
  DOM {080090336h, $OfsTStr("The supplied credential handle does not match the credential associated with the security context.")}
  DOM {080090337h, $OfsTStr("The crypto system or checksum function is invalid because a required function is unavailable.")}
  DOM {080090338h, $OfsTStr("The number of maximum ticket referrals has been exceeded.")}
  DOM {080090339h, $OfsTStr("The local machine must be a Kerberos KDC (domain controller) and it is not.")}
  DOM {08009033Ah, $OfsTStr("The other end of the security negotiation is requires strong crypto but it is not supported on the local machine.")}
  DOM {08009033Bh, $OfsTStr("The KDC reply contained more than one principal name.")}
  DOM {08009033Ch, $OfsTStr("Expected to find PA data for a hint of what etype to use")}
  DOM {08009033Dh, $OfsTStr("The client certificate does not contain a valid UPN")}
  DOM {08009033Eh, $OfsTStr("Smartcard logon is required and was not used.")}
  DOM {08009033Fh, $OfsTStr("A system shutdown is in progress.")}
  DOM {080090340h, $OfsTStr("An invalid request was sent to the KDC.")}
  DOM {080090341h, $OfsTStr("The KDC was unable to generate a referral for the service requested.")}
  DOM {080090342h, $OfsTStr("The encryption type requested is not supported by the KDC.")}
  DOM {080090343h, $OfsTStr("An unsupported preauthentication mechanism was presented to the Kerberos package.")}
  DOM {080090345h, $OfsTStr("The requested operation cannot be completed. The computer must be trusted for delegation and the current user account must be configured to allow delegation.")}
  DOM {080090346h, $OfsTStr("Client's supplied SSPI channel bindings were incorrect.")}
  DOM {080090347h, $OfsTStr("The received certificate was mapped to multiple accounts.")}
  DOM {080090348h, $OfsTStr("SEC_E_NO_KERB_KEY")}
  DOM {080090349h, $OfsTStr("The certificate is not valid for the requested usage.")}
  DOM {080090350h, $OfsTStr("The system cannot contact a domain controller to service the authentication request. Please try again later.")}
  DOM {080090351h, $OfsTStr("The smartcard certificate used for authentication has been revoked. Please contact your system administrator. There may be additional information in the event log.")}
  DOM {080090352h, $OfsTStr("An untrusted certificate authority was detected While processing the smartcard certificate used for authentication. Please contact your system administrator.")}
  DOM {080090353h, $OfsTStr("The revocation status of the smartcard certificate used for authentication could not be determined. Please contact your system administrator.")}
  DOM {080090354h, $OfsTStr("The smartcard certificate used for authentication was not trusted. Please contact your system administrator.")}
  DOM {080090355h, $OfsTStr("The smartcard certificate used for authentication has expired. Please contact your system administrator.")}
  DOM {080090356h, $OfsTStr("The Kerberos subsystem encountered an error. A service for user protocol request was made against a domain controller which does not support service for user.")}
  DOM {080090357h, $OfsTStr("An attempt was made by this server to make a Kerberos constrained delegation request for a target outside of the server's realm. This is not supported")}
  DOM {080090358h, $OfsTStr("The revocation status of the domain controller certificate used for smartcard authentication could not be determined. There is additional information in the system event log. Please contact your system administrator.")}
  DOM {080090359h, $OfsTStr("An untrusted certificate authority was detected while processing the domain controller certificate used for authentication. There is additional information in the system event log. Please contact your system administrator.")}
  DOM {08009035Ah, $OfsTStr("The domain controller certificate used for smartcard logon has expired. Please contact your system administrator with the contents of your system event log.")}
  DOM {08009035Bh, $OfsTStr("The domain controller certificate used for smartcard logon has been revoked. Please contact your system administrator with the contents of your system event log.")}
  DOM {08009035Dh, $OfsTStr("One or more of the parameters passed to the function was invalid.")}
  DOM {08009035Eh, $OfsTStr("Client policy does not allow credential delegation to target server.")}
  DOM {08009035Fh, $OfsTStr("Client policy does not allow credential delegation to target server with NLTM only authentication.")}
  DOM {080090361h, $OfsTStr("The required security context does not exist.")}
  DOM {080090362h, $OfsTStr("The PKU2U protocol encountered an error while attempting to utilize the associated certificates.")}
  DOM {080090363h, $OfsTStr("The identity of the server computer could not be verified.")}
  DOM {080090365h, $OfsTStr("Only https scheme is allowed.")}
  DOM {080090366h, $OfsTStr("The function completed successfully")}
  DOM {080091001h, $OfsTStr("An error occurred while performing an operation on a cryptographic message.")}
  DOM {080091002h, $OfsTStr("Unknown cryptographic algorithm.")}
  DOM {080091003h, $OfsTStr("The object identifier is poorly formatted.")}
  DOM {080091004h, $OfsTStr("Invalid cryptographic message type.")}
  DOM {080091005h, $OfsTStr("Unexpected cryptographic message encoding.")}
  DOM {080091006h, $OfsTStr("The cryptographic message does not contain an expected authenticated attribute.")}
  DOM {080091007h, $OfsTStr("The hash value is not correct.")}
  DOM {080091008h, $OfsTStr("The index value is not valid.")}
  DOM {080091009h, $OfsTStr("The content of the cryptographic message has already been decrypted.")}
  DOM {08009100Ah, $OfsTStr("The content of the cryptographic message has not been decrypted yet.")}
  DOM {08009100Bh, $OfsTStr("The enveloped-data message does not contain the specified recipient.")}
  DOM {08009100Ch, $OfsTStr("Invalid control type.")}
  DOM {08009100Dh, $OfsTStr("Invalid issuer and/or serial number.")}
  DOM {08009100Eh, $OfsTStr("Cannot find the original signer.")}
  DOM {08009100Fh, $OfsTStr("The cryptographic message does not contain all of the requested attributes.")}
  DOM {080091010h, $OfsTStr("The streamed cryptographic message is not ready to return data.")}
  DOM {080091011h, $OfsTStr("The streamed cryptographic message requires more data to complete the decode operation.")}
  DOM {080092001h, $OfsTStr("The length specified for the output data was insufficient.")}
  DOM {080092002h, $OfsTStr("An error occurred during encode or decode operation.")}
  DOM {080092003h, $OfsTStr("An error occurred while reading or writing to a file.")}
  DOM {080092004h, $OfsTStr("Cannot find object or property.")}
  DOM {080092005h, $OfsTStr("The object or property already exists.")}
  DOM {080092006h, $OfsTStr("No provider was specified for the store or object.")}
  DOM {080092007h, $OfsTStr("The specified certificate is self signed.")}
  DOM {080092008h, $OfsTStr("The previous certificate or CRL context was deleted.")}
  DOM {080092009h, $OfsTStr("Cannot find the requested object.")}
  DOM {08009200Ah, $OfsTStr("The certificate does not have a property that references a private key.")}
  DOM {08009200Bh, $OfsTStr("Cannot find the certificate and private key for decryption.")}
  DOM {08009200Ch, $OfsTStr("Cannot find the certificate and private key to use for decryption.")}
  DOM {08009200Dh, $OfsTStr("Not a cryptographic message or the cryptographic message is not formatted correctly.")}
  DOM {08009200Eh, $OfsTStr("The signed cryptographic message does not have a signer for the specified signer index.")}
  DOM {08009200Fh, $OfsTStr("Final closure is pending until additional frees or closes.")}
  DOM {080092010h, $OfsTStr("The certificate is revoked.")}
  DOM {080092011h, $OfsTStr("No Dll or exported function was found to verify revocation.")}
  DOM {080092012h, $OfsTStr("The revocation function was unable to check revocation for the certificate.")}
  DOM {080092013h, $OfsTStr("The revocation function was unable to check revocation because the revocation server was offline.")}
  DOM {080092014h, $OfsTStr("The certificate is not in the revocation server's database.")}
  DOM {080092020h, $OfsTStr("The string contains a non-numeric character.")}
  DOM {080092021h, $OfsTStr("The string contains a non-printable character.")}
  DOM {080092022h, $OfsTStr("The string contains a character not in the 7 bit ASCII character set.")}
  DOM {080092023h, $OfsTStr("The string contains an invalid X500 name attribute key")}
  DOM {080092024h, $OfsTStr("The dwValueType for the CERT_NAME_VALUE is not one of the character strings. Most likely it is either a CERT_RDN_ENCODED_BLOB or CERT_RDN_OCTET_STRING.")}
  DOM {080092025h, $OfsTStr("The Put operation cannot continue. The file needs to be resized. However")}
  DOM {080092026h, $OfsTStr("The cryptographic operation failed due to a local security option setting.")}
  DOM {080092027h, $OfsTStr("No DLL or exported function was found to verify subject usage.")}
  DOM {080092028h, $OfsTStr("The called function was unable to do a usage check on the subject.")}
  DOM {080092029h, $OfsTStr("Since the server was offline")}
  DOM {08009202Ah, $OfsTStr("The subject was not found in a Certificate Trust List (CTL).")}
  DOM {08009202Bh, $OfsTStr("None of the signers of the cryptographic message or certificate trust list is trusted.")}
  DOM {08009202Ch, $OfsTStr("The public key's algorithm parameters are missing.")}
  DOM {08009202dh, $OfsTStr("An object could not be located using the object locator infrastructure with the given name.")}
  DOM {080093000h, $OfsTStr("OSS Certificate encode/decode error code base See asn1code.h for a definition of the OSS runtime errors. The OSS error values are offset by CRYPT_E_OSS_ERROR.")}
  DOM {080093001h, $OfsTStr("OSS ASN.1 Error: Output Buffer is too small.")}
  DOM {080093002h, $OfsTStr("OSS ASN.1 Error: Signed integer is encoded as a unsigned integer.")}
  DOM {080093003h, $OfsTStr("OSS ASN.1 Error: Unknown ASN.1 data type.")}
  DOM {080093004h, $OfsTStr("OSS ASN.1 Error: Output buffer is too small")}
  DOM {080093005h, $OfsTStr("OSS ASN.1 Error: Invalid data.")}
  DOM {080093006h, $OfsTStr("OSS ASN.1 Error: Invalid argument.")}
  DOM {080093007h, $OfsTStr("OSS ASN.1 Error: Encode/Decode version mismatch.")}
  DOM {080093008h, $OfsTStr("OSS ASN.1 Error: Out of memory.")}
  DOM {080093009h, $OfsTStr("OSS ASN.1 Error: Encode/Decode Error.")}
  DOM {08009300Ah, $OfsTStr("OSS ASN.1 Error: Internal Error.")}
  DOM {08009300Bh, $OfsTStr("OSS ASN.1 Error: Invalid data.")}
  DOM {08009300Ch, $OfsTStr("OSS ASN.1 Error: Invalid data.")}
  DOM {08009300Dh, $OfsTStr("OSS ASN.1 Error: Unsupported BER indefinite-length encoding.")}
  DOM {08009300Eh, $OfsTStr("OSS ASN.1 Error: Access violation.")}
  DOM {08009300Fh, $OfsTStr("OSS ASN.1 Error: Invalid data.")}
  DOM {080093010h, $OfsTStr("OSS ASN.1 Error: Invalid data.")}
  DOM {080093011h, $OfsTStr("OSS ASN.1 Error: Invalid data.")}
  DOM {080093012h, $OfsTStr("OSS ASN.1 Error: Internal Error.")}
  DOM {080093013h, $OfsTStr("OSS ASN.1 Error: Multi-threading conflict.")}
  DOM {080093014h, $OfsTStr("OSS ASN.1 Error: Invalid data.")}
  DOM {080093015h, $OfsTStr("OSS ASN.1 Error: Invalid data.")}
  DOM {080093016h, $OfsTStr("OSS ASN.1 Error: Invalid data.")}
  DOM {080093017h, $OfsTStr("OSS ASN.1 Error: Encode/Decode function not implemented.")}
  DOM {080093018h, $OfsTStr("OSS ASN.1 Error: Trace file error.")}
  DOM {080093019h, $OfsTStr("OSS ASN.1 Error: Function not implemented.")}
  DOM {08009301Ah, $OfsTStr("OSS ASN.1 Error: Program link error.")}
  DOM {08009301Bh, $OfsTStr("OSS ASN.1 Error: Trace file error.")}
  DOM {08009301Ch, $OfsTStr("OSS ASN.1 Error: Trace file error.")}
  DOM {08009301Dh, $OfsTStr("OSS ASN.1 Error: Invalid data.")}
  DOM {08009301Eh, $OfsTStr("OSS ASN.1 Error: Invalid data.")}
  DOM {08009301Fh, $OfsTStr("OSS ASN.1 Error: Program link error.")}
  DOM {080093020h, $OfsTStr("OSS ASN.1 Error: Program link error.")}
  DOM {080093021h, $OfsTStr("OSS ASN.1 Error: Program link error.")}
  DOM {080093022h, $OfsTStr("OSS ASN.1 Error: Program link error.")}
  DOM {080093023h, $OfsTStr("OSS ASN.1 Error: Program link error.")}
  DOM {080093024h, $OfsTStr("OSS ASN.1 Error: Program link error.")}
  DOM {080093025h, $OfsTStr("OSS ASN.1 Error: Program link error.")}
  DOM {080093026h, $OfsTStr("OSS ASN.1 Error: Program link error.")}
  DOM {080093027h, $OfsTStr("OSS ASN.1 Error: Program link error.")}
  DOM {080093028h, $OfsTStr("OSS ASN.1 Error: Program link error.")}
  DOM {080093029h, $OfsTStr("OSS ASN.1 Error: Program link error.")}
  DOM {08009302Ah, $OfsTStr("OSS ASN.1 Error: Program link error.")}
  DOM {08009302Bh, $OfsTStr("OSS ASN.1 Error: Program link error.")}
  DOM {08009302Ch, $OfsTStr("OSS ASN.1 Error: Program link error.")}
  DOM {08009302Dh, $OfsTStr("OSS ASN.1 Error: System resource error.")}
  DOM {08009302Eh, $OfsTStr("OSS ASN.1 Error: Trace file error.")}
  DOM {080093100h, $OfsTStr("ASN1 Certificate encode/decode error code base. The ASN1 error values are offset by CRYPT_E_ASN1_ERROR.")}
  DOM {080093101h, $OfsTStr("ASN1 internal encode or decode error.")}
  DOM {080093102h, $OfsTStr("ASN1 unexpected end of data.")}
  DOM {080093103h, $OfsTStr("ASN1 corrupted data.")}
  DOM {080093104h, $OfsTStr("ASN1 value too large.")}
  DOM {080093105h, $OfsTStr("ASN1 constraint violated.")}
  DOM {080093106h, $OfsTStr("ASN1 out of memory.")}
  DOM {080093107h, $OfsTStr("ASN1 buffer overflow.")}
  DOM {080093108h, $OfsTStr("ASN1 function not supported for this PDU.")}
  DOM {080093109h, $OfsTStr("ASN1 bad arguments to function call.")}
  DOM {08009310Ah, $OfsTStr("ASN1 bad real value.")}
  DOM {08009310Bh, $OfsTStr("ASN1 bad tag value met.")}
  DOM {08009310Ch, $OfsTStr("ASN1 bad choice value.")}
  DOM {08009310Dh, $OfsTStr("ASN1 bad encoding rule.")}
  DOM {08009310Eh, $OfsTStr("ASN1 bad unicode (UTF8).")}
  DOM {080093133h, $OfsTStr("ASN1 bad PDU type.")}
  DOM {080093134h, $OfsTStr("ASN1 not yet implemented.")}
  DOM {080093201h, $OfsTStr("ASN1 skipped unknown extension(s).")}
  DOM {080093202h, $OfsTStr("ASN1 end of data expected")}
  DOM {080094001h, $OfsTStr("The request subject name is invalid or too long.")}
  DOM {080094002h, $OfsTStr("The request does not exist.")}
  DOM {080094003h, $OfsTStr("The request's current status does not allow this operation.")}
  DOM {080094004h, $OfsTStr("The requested property value is empty.")}
  DOM {080094005h, $OfsTStr("The certification authority's certificate contains invalid data.")}
  DOM {080094006h, $OfsTStr("Certificate service has been suspended for a database restore operation.")}
  DOM {080094007h, $OfsTStr("The certificate contains an encoded length that is potentially incompatible with older enrollment software.")}
  DOM {080094008h, $OfsTStr("The operation is denied. The user has multiple roles assigned and the certification authority is configured to enforce role separation.")}
  DOM {080094009h, $OfsTStr("The operation is denied. It can only be performed by a certificate manager that is allowed to manage certificates for the current requester.")}
  DOM {08009400Ah, $OfsTStr("Cannot archive private key. The certification authority is not configured for key archival.")}
  DOM {08009400Bh, $OfsTStr("Cannot archive private key. The certification authority could not verify one or more key recovery certificates.")}
  DOM {08009400Ch, $OfsTStr("The request is incorrectly formatted. The encrypted private key must be in an unauthenticated attribute in an outermost signature.")}
  DOM {08009400Dh, $OfsTStr("At least one security principal must have the permission to manage this CA.")}
  DOM {08009400Eh, $OfsTStr("The request contains an invalid renewal certificate attribute.")}
  DOM {08009400Fh, $OfsTStr("An attempt was made to open a Certification Authority database session")}
  DOM {080094010h, $OfsTStr("A memory reference caused a data alignment fault.")}
  DOM {080094011h, $OfsTStr("The permissions on this certification authority do not allow the current user to enroll for certificates.")}
  DOM {080094012h, $OfsTStr("The permissions on the certificate template do not allow the current user to enroll for this type of certificate.")}
  DOM {080094013h, $OfsTStr("The contacted domain controller cannot support signed LDAP traffic. Update the domain controller or configure Certificate Services to use SSL for Active Directory access.")}
  DOM {080094014h, $OfsTStr("The request was denied by a certificate manager or CA administrator.")}
  DOM {080094015h, $OfsTStr("An enrollment policy server cannot be located.")}
  DOM {080094800h, $OfsTStr("The requested certificate template is not supported by this CA.")}
  DOM {080094801h, $OfsTStr("The request contains no certificate template information.")}
  DOM {080094802h, $OfsTStr("The request contains conflicting template information.")}
  DOM {080094803h, $OfsTStr("The request is missing a required Subject Alternate name extension.")}
  DOM {080094804h, $OfsTStr("The request is missing a required private key for archival by the server.")}
  DOM {080094805h, $OfsTStr("The request is missing a required SMIME capabilities extension.")}
  DOM {080094806h, $OfsTStr("The request was made on behalf of a subject other than the caller. The certificate template must be configured to require at least one signature to authorize the request.")}
  DOM {080094807h, $OfsTStr("The request template version is newer than the supported template version.")}
  DOM {080094808h, $OfsTStr("The template is missing a required signature policy attribute.")}
  DOM {080094809h, $OfsTStr("The request is missing required signature policy information.")}
  DOM {08009480Ah, $OfsTStr("The request is missing one or more required signatures.")}
  DOM {08009480Bh, $OfsTStr("One or more signatures did not include the required application or issuance policies. The request is missing one or more required valid signatures.")}
  DOM {08009480Ch, $OfsTStr("The request is missing one or more required signature issuance policies.")}
  DOM {08009480Dh, $OfsTStr("The UPN is unavailable and cannot be added to the Subject Alternate name.")}
  DOM {08009480Eh, $OfsTStr("The Active Directory GUID is unavailable and cannot be added to the Subject Alternate name.")}
  DOM {08009480Fh, $OfsTStr("The DNS name is unavailable and cannot be added to the Subject Alternate name.")}
  DOM {080094810h, $OfsTStr("The request includes a private key for archival by the server")}
  DOM {080094811h, $OfsTStr("The public key does not meet the minimum size required by the specified certificate template.")}
  DOM {080094812h, $OfsTStr("The EMail name is unavailable and cannot be added to the Subject or Subject Alternate name.")}
  DOM {080094813h, $OfsTStr("One or more certificate templates to be enabled on this certification authority could not be found.")}
  DOM {080094814h, $OfsTStr("The certificate template renewal period is longer than the certificate validity period. The template should be reconfigured or the CA certificate renewed.")}
  DOM {080094815h, $OfsTStr("The certificate template requires too many RA signatures. Only one RA signature is allowed.")}
  DOM {080094816h, $OfsTStr("The certificate template requires renewal with the same public key")}
  DOM {080095000h, $OfsTStr("The key is not exportable.")}
  DOM {080095001h, $OfsTStr("You cannot add the root CA certificate into your local store.")}
  DOM {080095002h, $OfsTStr("The key archival hash attribute was not found in the response.")}
  DOM {080095003h, $OfsTStr("An unexpected key archival hash attribute was found in the response.")}
  DOM {080095004h, $OfsTStr("There is a key archival hash mismatch between the request and the response.")}
  DOM {080095005h, $OfsTStr("Signing certificate cannot include SMIME extension.")}
  DOM {080096001h, $OfsTStr("A system-level error occurred while verifying trust.")}
  DOM {080096002h, $OfsTStr("The certificate for the signer of the message is invalid or not found.")}
  DOM {080096003h, $OfsTStr("One of the counter signatures was invalid.")}
  DOM {080096004h, $OfsTStr("The signature of the certificate cannot be verified.")}
  DOM {080096005h, $OfsTStr("The timestamp signature and/or certificate could not be verified or is malformed.")}
  DOM {080096010h, $OfsTStr("The digital signature of the object did not verify.")}
  DOM {080096019h, $OfsTStr("A certificate's basic constraint extension has not been observed.")}
  DOM {08009601Eh, $OfsTStr("The certificate does not meet or contain the Authenticode(tm) financial extensions.")}
  DOM {080097001h, $OfsTStr("Tried to reference a part of the file outside the proper range.")}
  DOM {080097002h, $OfsTStr("Could not retrieve an object from the file.")}
  DOM {080097003h, $OfsTStr("Could not find the head table in the file.")}
  DOM {080097004h, $OfsTStr("The magic number in the head table is incorrect.")}
  DOM {080097005h, $OfsTStr("The offset table has incorrect values.")}
  DOM {080097006h, $OfsTStr("Duplicate table tags or tags out of alphabetical order.")}
  DOM {080097007h, $OfsTStr("A table does not start on a long word boundary.")}
  DOM {080097008h, $OfsTStr("First table does not appear after header information.")}
  DOM {080097009h, $OfsTStr("Two or more tables overlap.")}
  DOM {08009700Ah, $OfsTStr("Too many pad bytes between tables or pad bytes are not 0.")}
  DOM {08009700Bh, $OfsTStr("File is too small to contain the last table.")}
  DOM {08009700Ch, $OfsTStr("A table checksum is incorrect.")}
  DOM {08009700Dh, $OfsTStr("The file checksum is incorrect.")}
  DOM {080097010h, $OfsTStr("The signature does not have the correct attributes for the policy.")}
  DOM {080097011h, $OfsTStr("The file did not pass the hints check.")}
  DOM {080097012h, $OfsTStr("The file is not an OpenType file.")}
  DOM {080097013h, $OfsTStr("Failed on a file operation (open")}
  DOM {080097014h, $OfsTStr("A call to a CryptoAPI function failed.")}
  DOM {080097015h, $OfsTStr("There is a bad version number in the file.")}
  DOM {080097016h, $OfsTStr("The structure of the DSIG table is incorrect.")}
  DOM {080097017h, $OfsTStr("A check failed in a partially constant table.")}
  DOM {080097018h, $OfsTStr("Some kind of structural error.")}
  DOM {080097019h, $OfsTStr("The requested credential requires confirmation.")}
  DOM {0800B0001h, $OfsTStr("Unknown trust provider.")}
  DOM {0800B0002h, $OfsTStr("The trust verification action specified is not supported by the specified trust provider.")}
  DOM {0800B0003h, $OfsTStr("The form specified for the subject is not one supported or known by the specified trust provider.")}
  DOM {0800B0004h, $OfsTStr("The subject is not trusted for the specified action.")}
  DOM {0800B0005h, $OfsTStr("Error due to problem in ASN.1 encoding process.")}
  DOM {0800B0006h, $OfsTStr("Error due to problem in ASN.1 decoding process.")}
  DOM {0800B0007h, $OfsTStr("Reading / writing Extensions where Attributes are appropriate")}
  DOM {0800B0008h, $OfsTStr("Unspecified cryptographic failure.")}
  DOM {0800B0009h, $OfsTStr("The size of the data could not be determined.")}
  DOM {0800B000Ah, $OfsTStr("The size of the indefinite-sized data could not be determined.")}
  DOM {0800B000Bh, $OfsTStr("This object does not read and write self-sizing data.")}
  DOM {0800B0100h, $OfsTStr("No signature was present in the subject.")}
  DOM {0800B0101h, $OfsTStr("A required certificate is not within its validity period when verifying against the current system clock or the timestamp in the signed file.")}
  DOM {0800B0102h, $OfsTStr("The validity periods of the certification chain do not nest correctly.")}
  DOM {0800B0103h, $OfsTStr("A certificate that can only be used as an end-entity is being used as a CA or visa versa.")}
  DOM {0800B0104h, $OfsTStr("A path length constraint in the certification chain has been violated.")}
  DOM {0800B0105h, $OfsTStr("A certificate contains an unknown extension that is marked 'critical'.")}
  DOM {0800B0106h, $OfsTStr("A certificate being used for a purpose other than the ones specified by its CA.")}
  DOM {0800B0107h, $OfsTStr("A parent of a given certificate in fact did not issue that child certificate.")}
  DOM {0800B0108h, $OfsTStr("A certificate is missing or has an empty value for an important field")}
  DOM {0800B0109h, $OfsTStr("A certificate chain processed")}
  DOM {0800B010Ah, $OfsTStr("A certificate chain could not be built to a trusted root authority.")}
  DOM {0800B010Bh, $OfsTStr("Generic trust failure.")}
  DOM {0800B010Ch, $OfsTStr("A certificate was explicitly revoked by its issuer.")}
  DOM {0800B010Dh, $OfsTStr("The certification path terminates with the test root which is not trusted with the current policy settings.")}
  DOM {0800B010Eh, $OfsTStr("The revocation process could not continue - the certificate(s) could not be checked.")}
  DOM {0800B010Fh, $OfsTStr("The certificate's CN name does not match the passed value.")}
  DOM {0800B0110h, $OfsTStr("The certificate is not valid for the requested usage.")}
  DOM {0800B0111h, $OfsTStr("The certificate was explicitly marked as untrusted by the user.")}
  DOM {0800B0112h, $OfsTStr("A certification chain processed correctly")}
  DOM {0800B0113h, $OfsTStr("The certificate has invalid policy.")}
  DOM {0800B0114h, $OfsTStr("The certificate has an invalid name. The name is not included in the permitted list or is explicitly excluded.")}
  DOM {0800F0000h, $OfsTStr("A non-empty line was encountered in the INF before the start of a section.")}
  DOM {0800F0001h, $OfsTStr("A section name marker in the INF is not complete")}
  DOM {0800F0002h, $OfsTStr("An INF section was encountered whose name exceeds the maximum section name length.")}
  DOM {0800F0003h, $OfsTStr("The syntax of the INF is invalid.")}
  DOM {0800F0100h, $OfsTStr("The style of the INF is different than what was requested.")}
  DOM {0800F0101h, $OfsTStr("The required section was not found in the INF.")}
  DOM {0800F0102h, $OfsTStr("The required line was not found in the INF.")}
  DOM {0800F0103h, $OfsTStr("The files affected by the installation of this file queue have not been backed up for uninstall.")}
  DOM {0800F0200h, $OfsTStr("The INF or the device information set or element does not have an associated install class.")}
  DOM {0800F0201h, $OfsTStr("The INF or the device information set or element does not match the specified install class.")}
  DOM {0800F0202h, $OfsTStr("An existing device was found that is a duplicate of the device being manually installed.")}
  DOM {0800F0203h, $OfsTStr("There is no driver selected for the device information set or element.")}
  DOM {0800F0204h, $OfsTStr("The requested device registry key does not exist.")}
  DOM {0800F0205h, $OfsTStr("The device instance name is invalid.")}
  DOM {0800F0206h, $OfsTStr("The install class is not present or is invalid.")}
  DOM {0800F0207h, $OfsTStr("The device instance cannot be created because it already exists.")}
  DOM {0800F0208h, $OfsTStr("The operation cannot be performed on a device information element that has not been registered.")}
  DOM {0800F0209h, $OfsTStr("The device property code is invalid.")}
  DOM {0800F020Ah, $OfsTStr("The INF from which a driver list is to be built does not exist.")}
  DOM {0800F020Bh, $OfsTStr("The device instance does not exist in the hardware tree.")}
  DOM {0800F020Ch, $OfsTStr("The icon representing this install class cannot be loaded.")}
  DOM {0800F020Dh, $OfsTStr("The class installer registry entry is invalid.")}
  DOM {0800F020Eh, $OfsTStr("The class installer has indicated that the default action should be performed for this installation request.")}
  DOM {0800F020Fh, $OfsTStr("The operation does not require any files to be copied.")}
  DOM {0800F0210h, $OfsTStr("The specified hardware profile does not exist.")}
  DOM {0800F0211h, $OfsTStr("There is no device information element currently selected for this device information set.")}
  DOM {0800F0212h, $OfsTStr("The operation cannot be performed because the device information set is locked.")}
  DOM {0800F0213h, $OfsTStr("The operation cannot be performed because the device information element is locked.")}
  DOM {0800F0214h, $OfsTStr("The specified path does not contain any applicable device INFs.")}
  DOM {0800F0215h, $OfsTStr("No class installer parameters have been set for the device information set or element.")}
  DOM {0800F0216h, $OfsTStr("The operation cannot be performed because the file queue is locked.")}
  DOM {0800F0217h, $OfsTStr("A service installation section in this INF is invalid.")}
  DOM {0800F0218h, $OfsTStr("There is no class driver list for the device information element.")}
  DOM {0800F0219h, $OfsTStr("The installation failed because a function driver was not specified for this device instance.")}
  DOM {0800F021Ah, $OfsTStr("There is presently no default device interface designated for this interface class.")}
  DOM {0800F021Bh, $OfsTStr("The operation cannot be performed because the device interface is currently active.")}
  DOM {0800F021Ch, $OfsTStr("The operation cannot be performed because the device interface has been removed from the system.")}
  DOM {0800F021Dh, $OfsTStr("An interface installation section in this INF is invalid.")}
  DOM {0800F021Eh, $OfsTStr("This interface class does not exist in the system.")}
  DOM {0800F021Fh, $OfsTStr("The reference string supplied for this interface device is invalid.")}
  DOM {0800F0220h, $OfsTStr("The specified machine name does not conform to UNC naming conventions.")}
  DOM {0800F0221h, $OfsTStr("A general remote communication error occurred.")}
  DOM {0800F0222h, $OfsTStr("The machine selected for remote communication is not available at this time.")}
  DOM {0800F0223h, $OfsTStr("The Plug and Play service is not available on the remote machine.")}
  DOM {0800F0224h, $OfsTStr("The property page provider registry entry is invalid.")}
  DOM {0800F0225h, $OfsTStr("The requested device interface is not present in the system.")}
  DOM {0800F0226h, $OfsTStr("The device's co-installer has additional work to perform after installation is complete.")}
  DOM {0800F0227h, $OfsTStr("The device's co-installer is invalid.")}
  DOM {0800F0228h, $OfsTStr("There are no compatible drivers for this device.")}
  DOM {0800F0229h, $OfsTStr("There is no icon that represents this device or device type.")}
  DOM {0800F022Ah, $OfsTStr("A logical configuration specified in this INF is invalid.")}
  DOM {0800F022Bh, $OfsTStr("The class installer has denied the request to install or upgrade this device.")}
  DOM {0800F022Ch, $OfsTStr("One of the filter drivers installed for this device is invalid.")}
  DOM {0800F022Dh, $OfsTStr("The driver selected for this device does not support this version of Windows.")}
  DOM {0800F022Eh, $OfsTStr("The driver selected for this device does not support Windows.")}
  DOM {0800F022Fh, $OfsTStr("The third-party INF does not contain digital signature information.")}
  DOM {0800F0230h, $OfsTStr("An invalid attempt was made to use a device installation file queue for verification of digital signatures relative to other platforms.")}
  DOM {0800F0231h, $OfsTStr("The device cannot be disabled.")}
  DOM {0800F0232h, $OfsTStr("The device could not be dynamically removed.")}
  DOM {0800F0233h, $OfsTStr("Cannot copy to specified target.")}
  DOM {0800F0234h, $OfsTStr("Driver is not intended for this platform.")}
  DOM {0800F0235h, $OfsTStr("Operation not allowed in WOW64.")}
  DOM {0800F0236h, $OfsTStr("The operation involving unsigned file copying was rolled back")}
  DOM {0800F0237h, $OfsTStr("An INF was copied into the Windows INF directory in an improper manner.")}
  DOM {0800F0238h, $OfsTStr("The Security Configuration Editor (SCE) APIs have been disabled on this Embedded product.")}
  DOM {0800F0239h, $OfsTStr("An unknown exception was encountered.")}
  DOM {0800F023Ah, $OfsTStr("A problem was encountered when accessing the Plug and Play registry database.")}
  DOM {0800F023Bh, $OfsTStr("The requested operation is not supported for a remote machine.")}
  DOM {0800F023Ch, $OfsTStr("The specified file is not an installed OEM INF.")}
  DOM {0800F023Dh, $OfsTStr("One or more devices are presently installed using the specified INF.")}
  DOM {0800F023Eh, $OfsTStr("The requested device install operation is obsolete.")}
  DOM {0800F023Fh, $OfsTStr("A file could not be verified because it does not have an associated catalog signed via Authenticode(tm).")}
  DOM {0800F0240h, $OfsTStr("Authenticode(tm) signature verification is not supported for the specified INF.")}
  DOM {0800F0241h, $OfsTStr("The INF was signed with an Authenticode(tm) catalog from a trusted publisher.")}
  DOM {0800F0242h, $OfsTStr("The publisher of an Authenticode(tm) signed catalog has not yet been established as trusted.")}
  DOM {0800F0243h, $OfsTStr("The publisher of an Authenticode(tm) signed catalog was not established as trusted.")}
  DOM {0800F0244h, $OfsTStr("The software was tested for compliance with Windows Logo requirements on a different version of Windows")}
  DOM {0800F0245h, $OfsTStr("The file may only be validated by a catalog signed via Authenticode(tm).")}
  DOM {0800F0246h, $OfsTStr("One of the installers for this device cannot perform the installation at this time.")}
  DOM {0800F0247h, $OfsTStr("A problem was encountered while attempting to add the driver to the store.")}
  DOM {0800F0248h, $OfsTStr("The installation of this device is forbidden by system policy. Contact your system administrator.")}
  DOM {0800F0249h, $OfsTStr("The installation of this driver is forbidden by system policy. Contact your system administrator.")}
  DOM {0800F024Ah, $OfsTStr("The specified INF is the wrong type for this operation.")}
  DOM {0800F024Bh, $OfsTStr("The hash for the file is not present in the specified catalog file. The file is likely corrupt or the victim of tampering.")}
  DOM {0800F024Ch, $OfsTStr("A problem was encountered while attempting to delete the driver from the store.")}
  DOM {0800F0300h, $OfsTStr("An unrecoverable stack overflow was encountered.")}
  DOM {0800F1000h, $OfsTStr("No installed components were detected.")}
  DOM {080100001h, $OfsTStr("An internal consistency check failed.")}
  DOM {080100002h, $OfsTStr("The action was canceled by an SCardCancel request.")}
  DOM {080100003h, $OfsTStr("The supplied handle was invalid.")}
  DOM {080100004h, $OfsTStr("One or more of the supplied parameters could not be properly interpreted.")}
  DOM {080100005h, $OfsTStr("Registry startup information is missing or invalid.")}
  DOM {080100006h, $OfsTStr("Not enough memory available to complete this command.")}
  DOM {080100007h, $OfsTStr("An internal consistency timer has expired.")}
  DOM {080100008h, $OfsTStr("The data buffer to receive returned data is too small for the returned data.")}
  DOM {080100009h, $OfsTStr("The specified reader name is not recognized.")}
  DOM {08010000Ah, $OfsTStr("The user-specified timeout value has expired.")}
  DOM {08010000Bh, $OfsTStr("The smart card cannot be accessed because of other connections outstanding.")}
  DOM {08010000Ch, $OfsTStr("The operation requires a Smart Card")}
  DOM {08010000Dh, $OfsTStr("The specified smart card name is not recognized.")}
  DOM {08010000Eh, $OfsTStr("The system could not dispose of the media in the requested manner.")}
  DOM {08010000Fh, $OfsTStr("The requested protocols are incompatible with the protocol currently in use with the smart card.")}
  DOM {080100010h, $OfsTStr("The reader or smart card is not ready to accept commands.")}
  DOM {080100011h, $OfsTStr("One or more of the supplied parameters values could not be properly interpreted.")}
  DOM {080100012h, $OfsTStr("The action was canceled by the system")}
  DOM {080100013h, $OfsTStr("An internal communications error has been detected.")}
  DOM {080100014h, $OfsTStr("An internal error has been detected")}
  DOM {080100015h, $OfsTStr("An ATR obtained from the registry is not a valid ATR string.")}
  DOM {080100016h, $OfsTStr("An attempt was made to end a non-existent transaction.")}
  DOM {080100017h, $OfsTStr("The specified reader is not currently available for use.")}
  DOM {080100018h, $OfsTStr("The operation has been aborted to allow the server application to exit.")}
  DOM {080100019h, $OfsTStr("The PCI Receive buffer was too small.")}
  DOM {08010001Ah, $OfsTStr("The reader driver does not meet minimal requirements for support.")}
  DOM {08010001Bh, $OfsTStr("The reader driver did not produce a unique reader name.")}
  DOM {08010001Ch, $OfsTStr("The smart card does not meet minimal requirements for support.")}
  DOM {08010001Dh, $OfsTStr("The Smart card resource manager is not running.")}
  DOM {08010001Eh, $OfsTStr("The Smart card resource manager has shut down.")}
  DOM {08010001Fh, $OfsTStr("An unexpected card error has occurred.")}
  DOM {080100020h, $OfsTStr("No Primary Provider can be found for the smart card.")}
  DOM {080100021h, $OfsTStr("The requested order of object creation is not supported.")}
  DOM {080100022h, $OfsTStr("This smart card does not support the requested feature.")}
  DOM {080100023h, $OfsTStr("The identified directory does not exist in the smart card.")}
  DOM {080100024h, $OfsTStr("The identified file does not exist in the smart card.")}
  DOM {080100025h, $OfsTStr("The supplied path does not represent a smart card directory.")}
  DOM {080100026h, $OfsTStr("The supplied path does not represent a smart card file.")}
  DOM {080100027h, $OfsTStr("Access is denied to this file.")}
  DOM {080100028h, $OfsTStr("The smartcard does not have enough memory to store the information.")}
  DOM {080100029h, $OfsTStr("There was an error trying to set the smart card file object pointer.")}
  DOM {08010002Ah, $OfsTStr("The supplied PIN is incorrect.")}
  DOM {08010002Bh, $OfsTStr("An unrecognized error code was returned from a layered component.")}
  DOM {08010002Ch, $OfsTStr("The requested certificate does not exist.")}
  DOM {08010002Dh, $OfsTStr("The requested certificate could not be obtained.")}
  DOM {08010002Eh, $OfsTStr("Cannot find a smart card reader.")}
  DOM {08010002Fh, $OfsTStr("A communications error with the smart card has been detected. Retry the operation.")}
  DOM {080100030h, $OfsTStr("The requested key container does not exist on the smart card.")}
  DOM {080100031h, $OfsTStr("The Smart card resource manager is too busy to complete this operation.")}
  DOM {080100032h, $OfsTStr("The smart card PIN cache has expired.")}
  DOM {080100033h, $OfsTStr("The smart card PIN cannot be cached.")}
  DOM {080100034h, $OfsTStr("The smart card is read only and cannot be written to.")}
  DOM {080100065h, $OfsTStr("The reader cannot communicate with the smart card")}
  DOM {080100066h, $OfsTStr("The smart card is not responding to a reset.")}
  DOM {080100067h, $OfsTStr("Power has been removed from the smart card")}
  DOM {080100068h, $OfsTStr("The smart card has been reset")}
  DOM {080100069h, $OfsTStr("The smart card has been removed")}
  DOM {08010006Ah, $OfsTStr("Access was denied because of a security violation.")}
  DOM {08010006Bh, $OfsTStr("The card cannot be accessed because the wrong PIN was presented.")}
  DOM {08010006Ch, $OfsTStr("The card cannot be accessed because the maximum number of PIN entry attempts has been reached.")}
  DOM {08010006Dh, $OfsTStr("The end of the smart card file has been reached.")}
  DOM {08010006Eh, $OfsTStr("The action was canceled by the user.")}
  DOM {08010006Fh, $OfsTStr("No PIN was presented to the smart card.")}
  DOM {080100070h, $OfsTStr("The requested item could not be found in the cache.")}
  DOM {080100071h, $OfsTStr("The requested cache item is too old and was deleted from the cache.")}
  DOM {080100072h, $OfsTStr("The new cache item exceeds the maximum per-item size defined for the cache.")}
  DOM {080110401h, $OfsTStr("Errors occurred accessing one or more objects - the ErrorInfo collection may have more detail")}
  DOM {080110402h, $OfsTStr("One or more of the object's properties are missing or invalid")}
  DOM {080110403h, $OfsTStr("The object was not found in the catalog")}
  DOM {080110404h, $OfsTStr("The object is already registered")}
  DOM {080110407h, $OfsTStr("Error occurred writing to the application file")}
  DOM {080110408h, $OfsTStr("Error occurred reading the application file")}
  DOM {080110409h, $OfsTStr("Invalid version number in application file")}
  DOM {08011040Ah, $OfsTStr("The file path is invalid")}
  DOM {08011040Bh, $OfsTStr("The application is already installed")}
  DOM {08011040Ch, $OfsTStr("The role already exists")}
  DOM {08011040Dh, $OfsTStr("An error occurred copying the file")}
  DOM {08011040Fh, $OfsTStr("One or more users are not valid")}
  DOM {080110410h, $OfsTStr("One or more users in the application file are not valid")}
  DOM {080110411h, $OfsTStr("The component's CLSID is missing or corrupt")}
  DOM {080110412h, $OfsTStr("The component's progID is missing or corrupt")}
  DOM {080110413h, $OfsTStr("Unable to set required authentication level for update request")}
  DOM {080110414h, $OfsTStr("The identity or password set on the application is not valid")}
  DOM {080110418h, $OfsTStr("Application file CLSIDs or IIDs do not match corresponding DLLs")}
  DOM {080110419h, $OfsTStr("Interface information is either missing or changed")}
  DOM {08011041Ah, $OfsTStr("DllRegisterServer failed on component install")}
  DOM {08011041Bh, $OfsTStr("No server file share available")}
  DOM {08011041Dh, $OfsTStr("DLL could not be loaded")}
  DOM {08011041Eh, $OfsTStr("The registered TypeLib ID is not valid")}
  DOM {08011041Fh, $OfsTStr("Application install directory not found")}
  DOM {080110423h, $OfsTStr("Errors occurred while in the component registrar")}
  DOM {080110424h, $OfsTStr("The file does not exist")}
  DOM {080110425h, $OfsTStr("The DLL could not be loaded")}
  DOM {080110426h, $OfsTStr("GetClassObject failed in the DLL")}
  DOM {080110427h, $OfsTStr("The DLL does not support the components listed in the TypeLib")}
  DOM {080110428h, $OfsTStr("The TypeLib could not be loaded")}
  DOM {080110429h, $OfsTStr("The file does not contain components or component information")}
  DOM {08011042Ah, $OfsTStr("Changes to this object and its sub-objects have been disabled")}
  DOM {08011042Bh, $OfsTStr("The delete function has been disabled for this object")}
  DOM {08011042Ch, $OfsTStr("The server catalog version is not supported")}
  DOM {08011042Dh, $OfsTStr("The component move was disallowed")}
  DOM {08011042Eh, $OfsTStr("The component move failed because the destination application no longer exists")}
  DOM {080110430h, $OfsTStr("The system was unable to register the TypeLib")}
  DOM {080110433h, $OfsTStr("This operation cannot be performed on the system application")}
  DOM {080110434h, $OfsTStr("The component registrar referenced in this file is not available")}
  DOM {080110435h, $OfsTStr("A component in the same DLL is already installed")}
  DOM {080110436h, $OfsTStr("The service is not installed")}
  DOM {080110437h, $OfsTStr("One or more property settings are either invalid or in conflict with each other")}
  DOM {080110438h, $OfsTStr("The object you are attempting to add or rename already exists")}
  DOM {080110439h, $OfsTStr("The component already exists")}
  DOM {08011043Bh, $OfsTStr("The registration file is corrupt")}
  DOM {08011043Ch, $OfsTStr("The property value is too large")}
  DOM {08011043Eh, $OfsTStr("Object was not found in registry")}
  DOM {08011043Fh, $OfsTStr("This object is not poolable")}
  DOM {080110446h, $OfsTStr("A CLSID with the same GUID as the new application ID is already installed on this machine")}
  DOM {080110447h, $OfsTStr("A role assigned to a component")}
  DOM {080110448h, $OfsTStr("You must have components in an application in order to start the application")}
  DOM {080110449h, $OfsTStr("This operation is not enabled on this platform")}
  DOM {08011044Ah, $OfsTStr("Application Proxy is not exportable")}
  DOM {08011044Bh, $OfsTStr("Failed to start application because it is either a library application or an application proxy")}
  DOM {08011044Ch, $OfsTStr("System application is not exportable")}
  DOM {08011044Dh, $OfsTStr("Cannot subscribe to this component (the component may have been imported)")}
  DOM {08011044Eh, $OfsTStr("An event class cannot also be a subscriber component")}
  DOM {08011044Fh, $OfsTStr("Library applications and application proxies are incompatible")}
  DOM {080110450h, $OfsTStr("This function is valid for the base partition only")}
  DOM {080110451h, $OfsTStr("You cannot start an application that has been disabled")}
  DOM {080110457h, $OfsTStr("The specified partition name is already in use on this computer")}
  DOM {080110458h, $OfsTStr("The specified partition name is invalid. Check that the name contains at least one visible character")}
  DOM {080110459h, $OfsTStr("The partition cannot be deleted because it is the default partition for one or more users")}
  DOM {08011045Ah, $OfsTStr("The partition cannot be exported")}
  DOM {08011045Bh, $OfsTStr("Applications that contain one or more imported components cannot be installed into a non-base partition")}
  DOM {08011045Ch, $OfsTStr("The application name is not unique and cannot be resolved to an application id")}
  DOM {08011045Dh, $OfsTStr("The partition name is not unique and cannot be resolved to a partition id")}
  DOM {080110472h, $OfsTStr("The COM+ registry database has not been initialized")}
  DOM {080110473h, $OfsTStr("The COM+ registry database is not open")}
  DOM {080110474h, $OfsTStr("The COM+ registry database detected a system error")}
  DOM {080110475h, $OfsTStr("The COM+ registry database is already running")}
  DOM {080110480h, $OfsTStr("This version of the COM+ registry database cannot be migrated")}
  DOM {080110481h, $OfsTStr("The schema version to be migrated could not be found in the COM+ registry database")}
  DOM {080110482h, $OfsTStr("There was a type mismatch between binaries")}
  DOM {080110483h, $OfsTStr("A binary of unknown or invalid type was provided")}
  DOM {080110484h, $OfsTStr("There was a type mismatch between a binary and an application")}
  DOM {080110485h, $OfsTStr("The application cannot be paused or resumed")}
  DOM {080110486h, $OfsTStr("The COM+ Catalog Server threw an exception during execution")}
  DOM {080110600h, $OfsTStr("Only COM+ Applications marked 'queued' can be invoked using the 'queue' moniker")}
  DOM {080110601h, $OfsTStr("At least one interface must be marked 'queued' in order to create a queued component instance with the 'queue' moniker")}
  DOM {080110602h, $OfsTStr("MSMQ is required for the requested operation and is not installed")}
  DOM {080110603h, $OfsTStr("Unable to marshal an interface that does not support IPersistStream")}
  DOM {080110604h, $OfsTStr("The message is improperly formatted or was damaged in transit")}
  DOM {080110605h, $OfsTStr("An unauthenticated message was received by an application that accepts only authenticated messages")}
  DOM {080110606h, $OfsTStr("The message was requeued or moved by a user not in the 'QC Trusted User' role")}
  DOM {080110701h, $OfsTStr("Cannot create a duplicate resource of type Distributed Transaction Coordinator")}
  DOM {080110808h, $OfsTStr("One of the objects being inserted or updated does not belong to a valid parent collection")}
  DOM {080110809h, $OfsTStr("One of the specified objects cannot be found")}
  DOM {08011080Ah, $OfsTStr("The specified application is not currently running")}
  DOM {08011080Bh, $OfsTStr("The partition(s) specified are not valid.")}
  DOM {08011080Dh, $OfsTStr("COM+ applications that run as NT service may not be pooled or recycled")}
  DOM {08011080Eh, $OfsTStr("One or more users are already assigned to a local partition set.")}
  DOM {08011080Fh, $OfsTStr("Library applications may not be recycled.")}
  DOM {080110811h, $OfsTStr("Applications running as NT services may not be recycled.")}
  DOM {080110812h, $OfsTStr("The process has already been recycled.")}
  DOM {080110813h, $OfsTStr("A paused process may not be recycled.")}
  DOM {080110814h, $OfsTStr("Library applications may not be NT services.")}
  DOM {080110815h, $OfsTStr("The ProgID provided to the copy operation is invalid. The ProgID is in use by another registered CLSID.")}
  DOM {080110816h, $OfsTStr("The partition specified as default is not a member of the partition set.")}
  DOM {080110817h, $OfsTStr("A recycled process may not be paused.")}
  DOM {080110818h, $OfsTStr("Access to the specified partition is denied.")}
  DOM {080110819h, $OfsTStr("Only Application Files (*.MSI files) can be installed into partitions.")}
  DOM {08011081Ah, $OfsTStr("Applications containing one or more legacy components may not be exported to 1.0 format.")}
  DOM {08011081Bh, $OfsTStr("Legacy components may not exist in non-base partitions.")}
  DOM {08011081Ch, $OfsTStr("A component cannot be moved (or copied) from the System Application")}
  DOM {08011081Dh, $OfsTStr("A component cannot be moved (or copied) to the System Application")}
  DOM {08011081Eh, $OfsTStr("A private component cannot be moved (or copied) to a library application or to the base partition")}
  DOM {08011081Fh, $OfsTStr("The Base Application Partition exists in all partition sets and cannot be removed.")}
  DOM {080110820h, $OfsTStr("Event Class components cannot be aliased.")}
  DOM {080110821h, $OfsTStr("Access is denied because the component is private.")}
  DOM {080110822h, $OfsTStr("The specified SAFER level is invalid.")}
  DOM {080110823h, $OfsTStr("The specified user cannot write to the system registry")}
  DOM {080110824h, $OfsTStr("COM+ partitions are currently disabled.")}
  DOM {0801F0001h, $OfsTStr("A handler was not defined by the filter for this operation.")}
  DOM {0801F0002h, $OfsTStr("A context is already defined for this object.")}
  DOM {0801F0003h, $OfsTStr("Asynchronous requests are not valid for this operation.")}
  DOM {0801F0004h, $OfsTStr("Disallow the Fast IO path for this operation.")}
  DOM {0801F0005h, $OfsTStr("An invalid name request was made. The name requested cannot be retrieved at this time.")}
  DOM {0801F0006h, $OfsTStr("Posting this operation to a worker thread for further processing is not safe at this time because it could lead to a system deadlock.")}
  DOM {0801F0007h, $OfsTStr("The Filter Manager was not initialized when a filter tried to register. Make sure that the Filter Manager is getting loaded as a driver.")}
  DOM {0801F0008h, $OfsTStr("The filter is not ready for attachment to volumes because it has not finished initializing (FltStartFiltering has not been called).")}
  DOM {0801F0009h, $OfsTStr("The filter must cleanup any operation specific context at this time because it is being removed from the system before the operation is completed by the lower drivers.")}
  DOM {0801F000Ah, $OfsTStr("The Filter Manager had an internal error from which it cannot recover")}
  DOM {0801F000Bh, $OfsTStr("The object specified for this action is in the process of being deleted")}
  DOM {0801F000Ch, $OfsTStr("Non-paged pool must be used for this type of context.")}
  DOM {0801F000Dh, $OfsTStr("A duplicate handler definition has been provided for an operation.")}
  DOM {0801F000Eh, $OfsTStr("The callback data queue has been disabled.")}
  DOM {0801F000Fh, $OfsTStr("Do not attach the filter to the volume at this time.")}
  DOM {0801F0010h, $OfsTStr("Do not detach the filter from the volume at this time.")}
  DOM {0801F0011h, $OfsTStr("An instance already exists at this altitude on the volume specified.")}
  DOM {0801F0012h, $OfsTStr("An instance already exists with this name on the volume specified.")}
  DOM {0801F0013h, $OfsTStr("The system could not find the filter specified.")}
  DOM {0801F0014h, $OfsTStr("The system could not find the volume specified.")}
  DOM {0801F0015h, $OfsTStr("The system could not find the instance specified.")}
  DOM {0801F0016h, $OfsTStr("No registered context allocation definition was found for the given request.")}
  DOM {0801F0017h, $OfsTStr("An invalid parameter was specified during context registration.")}
  DOM {0801F0018h, $OfsTStr("The name requested was not found in Filter Manager's name cache and could not be retrieved from the file system.")}
  DOM {0801F0019h, $OfsTStr("The requested device object does not exist for the given volume.")}
  DOM {0801F001Ah, $OfsTStr("The specified volume is already mounted.")}
  DOM {0801F001Bh, $OfsTStr("The specified Transaction Context is already enlisted in a transaction")}
  DOM {0801F001Ch, $OfsTStr("The specified context is already attached to another object")}
  DOM {0801F0020h, $OfsTStr("No waiter is present for the filter's reply to this message.")}
  DOM {0801F0023h, $OfsTStr("The filesystem database resource is in use. Registration cannot complete at this time.")}
  DOM {080260001h, $OfsTStr("Display Driver Stopped Responding} The %hs display driver has stopped working normally. Save your work and reboot the system to restore full display functionality. The next time you reboot the machine a dialog will be displayed giving you a chance to report this failure to Microsoft.")}
  DOM {080261001h, $OfsTStr("Monitor descriptor could not be obtained.")}
  DOM {080261002h, $OfsTStr("Format of the obtained monitor descriptor is not supported by this release.")}
  DOM {080263001h, $OfsTStr("Desktop composition is disabled} The operation could not be completed because desktop composition is disabled.")}
  DOM {080263002h, $OfsTStr("Some desktop composition APIs are not supported while remoting} The operation is not supported while running in a remote session.")}
  DOM {080263003h, $OfsTStr("No DWM redirection surface is available} The DWM was unable to provide a redireciton surface to complete the DirectX present.")}
  DOM {080263004h, $OfsTStr("DWM is not queuing presents for the specified window} The window specified is not currently using queued presents.")}
  DOM {080263005h, $OfsTStr("The adapter specified by the LUID is not found} DWM cannot find the adapter specified by the LUID.")}
  DOM {080263007h, $OfsTStr("Redirection surface can not be created. The size of the surface is larger than what is supported on this machine} Redirection surface can not be created. The size of the surface is larger than what is supported on this machine.")}
  DOM {08027025Ah, $OfsTStr("The app didn't start in the required time.")}
  DOM {08027025Bh, $OfsTStr("The app didn't start.")}
  DOM {08027025Ch, $OfsTStr("This app failed to launch because of an issue with its license. Please try again in a moment.")}
  DOM {080280000h, $OfsTStr("This is an error mask to convert TPM hardware errors to win errors.")}
  DOM {080280001h, $OfsTStr("Authentication failed.")}
  DOM {080280002h, $OfsTStr("The index to a PCR")}
  DOM {080280003h, $OfsTStr("One or more parameter is bad.")}
  DOM {080280004h, $OfsTStr("An operation completed successfully but the auditing of that operation failed.")}
  DOM {080280005h, $OfsTStr("The clear disable flag is set and all clear operations now require physical access.")}
  DOM {080280006h, $OfsTStr("Activate the Trusted Platform Module (TPM).")}
  DOM {080280007h, $OfsTStr("Enable the Trusted Platform Module (TPM).")}
  DOM {080280008h, $OfsTStr("The target command has been disabled.")}
  DOM {080280009h, $OfsTStr("The operation failed.")}
  DOM {08028000Ah, $OfsTStr("The ordinal was unknown or inconsistent.")}
  DOM {08028000Bh, $OfsTStr("The ability to install an owner is disabled.")}
  DOM {08028000Ch, $OfsTStr("The key handle cannot be interpreted.")}
  DOM {08028000Dh, $OfsTStr("The key handle points to an invalid key.")}
  DOM {08028000Eh, $OfsTStr("Unacceptable encryption scheme.")}
  DOM {08028000Fh, $OfsTStr("Migration authorization failed.")}
  DOM {080280010h, $OfsTStr("PCR information could not be interpreted.")}
  DOM {080280010h, $OfsTStr("BTPM 2.0: TPM_RC_PRIVATE error.")}
  DOM {080280011h, $OfsTStr("No room to load key.")}
  DOM {080280012h, $OfsTStr("There is no Storage Root Key (SRK) set.")}
  DOM {080280013h, $OfsTStr("An encrypted blob is invalid or was not created by this TPM.")}
  DOM {080280014h, $OfsTStr("The Trusted Platform Module (TPM) already has an owner.")}
  DOM {080280015h, $OfsTStr("The TPM has insufficient internal resources to perform the requested action.")}
  DOM {080280016h, $OfsTStr("A random string was too short.")}
  DOM {080280017h, $OfsTStr("The TPM does not have the space to perform the operation.")}
  DOM {080280018h, $OfsTStr("The named PCR value does not match the current PCR value.")}
  DOM {080280019h, $OfsTStr("The paramSize argument to the command has the incorrect value .")}
  DOM {08028001Ah, $OfsTStr("There is no existing SHA-1 thread.")}
  DOM {08028001Bh, $OfsTStr("The calculation is unable to proceed because the existing SHA-1 thread has already encountered an error.")}
  DOM {08028001Ch, $OfsTStr("The TPM hardware device reported a failure during its internal self test. Try restarting the computer to resolve the problem. If the problem continues")}
  DOM {08028001Dh, $OfsTStr("The authorization for the second key in a 2 key function failed authorization.")}
  DOM {08028001Eh, $OfsTStr("The tag value sent to for a command is invalid.")}
  DOM {08028001Fh, $OfsTStr("An IO error occurred transmitting information to the TPM.")}
  DOM {080280020h, $OfsTStr("The encryption process had a problem.")}
  DOM {080280021h, $OfsTStr("The decryption process did not complete.")}
  DOM {080280022h, $OfsTStr("An invalid handle was used.")}
  DOM {080280023h, $OfsTStr("The TPM does not have an Endorsement Key (EK) installed.")}
  DOM {080280024h, $OfsTStr("The usage of a key is not allowed.")}
  DOM {080280025h, $OfsTStr("The submitted entity type is not allowed.")}
  DOM {080280026h, $OfsTStr("The command was received in the wrong sequence relative to TPM_Init and a subsequent TPM_Startup.")}
  DOM {080280027h, $OfsTStr("Signed data cannot include additional DER information.")}
  DOM {080280028h, $OfsTStr("The key properties in TPM_KEY_PARMs are not supported by this TPM.")}
  DOM {080280029h, $OfsTStr("The migration properties of this key are incorrect.")}
  DOM {08028002Ah, $OfsTStr("The signature or encryption scheme for this key is incorrect or not permitted in this situation.")}
  DOM {08028002Bh, $OfsTStr("The size of the data (or blob) parameter is bad or inconsistent with the referenced key.")}
  DOM {08028002Ch, $OfsTStr("A mode parameter is bad")}
  DOM {08028002Dh, $OfsTStr("Either the physicalPresence or physicalPresenceLock bits have the wrong value.")}
  DOM {08028002Eh, $OfsTStr("The TPM cannot perform this version of the capability.")}
  DOM {08028002Fh, $OfsTStr("The TPM does not allow for wrapped transport sessions.")}
  DOM {080280030h, $OfsTStr("TPM audit construction failed and the underlying command was returning a failure code also.")}
  DOM {080280031h, $OfsTStr("TPM audit construction failed and the underlying command was returning success.")}
  DOM {080280032h, $OfsTStr("Attempt to reset a PCR register that does not have the resettable attribute.")}
  DOM {080280033h, $OfsTStr("Attempt to reset a PCR register that requires locality and locality modifier not part of command transport.")}
  DOM {080280034h, $OfsTStr("Make identity blob not properly typed.")}
  DOM {080280035h, $OfsTStr("When saving context identified resource type does not match actual resource.")}
  DOM {080280036h, $OfsTStr("The TPM is attempting to execute a command only available when in FIPS mode.")}
  DOM {080280037h, $OfsTStr("The command is attempting to use an invalid family ID.")}
  DOM {080280038h, $OfsTStr("The permission to manipulate the NV storage is not available.")}
  DOM {080280039h, $OfsTStr("The operation requires a signed command.")}
  DOM {08028003Ah, $OfsTStr("Wrong operation to load an NV key.")}
  DOM {08028003Bh, $OfsTStr("NV_LoadKey blob requires both owner and blob authorization.")}
  DOM {08028003Ch, $OfsTStr("The NV area is locked and not writtable.")}
  DOM {08028003Dh, $OfsTStr("The locality is incorrect for the attempted operation.")}
  DOM {08028003Eh, $OfsTStr("The NV area is read only and can't be written to.")}
  DOM {08028003Fh, $OfsTStr("There is no protection on the write to the NV area.")}
  DOM {080280040h, $OfsTStr("The family count value does not match.")}
  DOM {080280041h, $OfsTStr("The NV area has already been written to.")}
  DOM {080280042h, $OfsTStr("The NV area attributes conflict.")}
  DOM {080280043h, $OfsTStr("The structure tag and version are invalid or inconsistent.")}
  DOM {080280044h, $OfsTStr("The key is under control of the TPM Owner and can only be evicted by the TPM Owner.")}
  DOM {080280045h, $OfsTStr("The counter handle is incorrect.")}
  DOM {080280046h, $OfsTStr("The write is not a complete write of the area.")}
  DOM {080280047h, $OfsTStr("The gap between saved context counts is too large.")}
  DOM {080280048h, $OfsTStr("The maximum number of NV writes without an owner has been exceeded.")}
  DOM {080280049h, $OfsTStr("No operator AuthData value is set.")}
  DOM {08028004Ah, $OfsTStr("The resource pointed to by context is not loaded.")}
  DOM {08028004Bh, $OfsTStr("The delegate administration is locked.")}
  DOM {08028004Ch, $OfsTStr("Attempt to manage a family other than the delegated family.")}
  DOM {08028004Dh, $OfsTStr("Delegation table management not enabled.")}
  DOM {08028004Eh, $OfsTStr("There was a command executed outside of an exclusive transport session.")}
  DOM {08028004Fh, $OfsTStr("Attempt to context save a owner evict controlled key.")}
  DOM {080280050h, $OfsTStr("The DAA command has no resources availble to execute the command.")}
  DOM {080280051h, $OfsTStr("The consistency check on DAA parameter inputData0 has failed.")}
  DOM {080280052h, $OfsTStr("The consistency check on DAA parameter inputData1 has failed.")}
  DOM {080280053h, $OfsTStr("The consistency check on DAA_issuerSettings has failed.")}
  DOM {080280054h, $OfsTStr("The consistency check on DAA_tpmSpecific has failed.")}
  DOM {080280055h, $OfsTStr("The atomic process indicated by the submitted DAA command is not the expected process.")}
  DOM {080280056h, $OfsTStr("The issuer's validity check has detected an inconsistency.")}
  DOM {080280057h, $OfsTStr("The consistency check on w has failed.")}
  DOM {080280058h, $OfsTStr("The handle is incorrect.")}
  DOM {080280059h, $OfsTStr("Delegation is not correct.")}
  DOM {08028005Ah, $OfsTStr("The context blob is invalid.")}
  DOM {08028005Bh, $OfsTStr("Too many contexts held by the TPM.")}
  DOM {08028005Ch, $OfsTStr("Migration authority signature validation failure.")}
  DOM {08028005Dh, $OfsTStr("Migration destination not authenticated.")}
  DOM {08028005Eh, $OfsTStr("Migration source incorrect.")}
  DOM {08028005Fh, $OfsTStr("Incorrect migration authority.")}
  DOM {080280061h, $OfsTStr("Attempt to revoke the EK and the EK is not revocable.")}
  DOM {080280062h, $OfsTStr("Bad signature of CMK ticket.")}
  DOM {080280063h, $OfsTStr("There is no room in the context list for additional contexts.")}
  DOM {080280082h, $OfsTStr("TPM 2.0: Inconsistent attributes.")}
  DOM {080280083h, $OfsTStr("TPM 2.0: Hash algorithm not supported or not appropriate.")}
  DOM {080280084h, $OfsTStr("TPM 2.0: Value is out of range or is not correct for the context.")}
  DOM {080280085h, $OfsTStr("TPM 2.0: Hierarchy is not enabled or is not correct for the use.")}
  DOM {080280086h, $OfsTStr("TPM 2.0: Key size is not supported.")}
  DOM {080280087h, $OfsTStr("TPM 2.0: Mask generation function not supported/Key fields are not compatible with the selected use.")}
  DOM {080280088h, $OfsTStr("TPM 2.0: Key fields are not compatible with the selected use.")}
  DOM {080280089h, $OfsTStr("TPM 2.0: Mode of operation not supported.")}
  DOM {08028008Ah, $OfsTStr("TPM 2.0: The type of the value is not appropriate for the use.")}
  DOM {08028008Bh, $OfsTStr("TPM 2.0: The Handle is not correct for the use.")}
  DOM {08028008Ch, $OfsTStr("TPM 2.0: Unsupported key derivation function or function not appropriate for use.")}
  DOM {08028008Dh, $OfsTStr("TPM 2.0: Value was out of allowed range.")}
  DOM {08028008Eh, $OfsTStr("TPM 2.0: The authorization HMAC check failed and DA counter incremented.")}
  DOM {08028008Fh, $OfsTStr("TPM 2.0: Invalid nonce size.")}
  DOM {080280092h, $OfsTStr("TPM 2.0: Unsupported or incompatible scheme.")}
  DOM {080280095h, $OfsTStr("TPM 2.0: Structure is wrong size..")}
  DOM {080280096h, $OfsTStr("TPM 2.0: Unsupported symmetric algorithm or key size")}
  DOM {080280097h, $OfsTStr("TPM 2.0: Incorrect structure tag.")}
  DOM {080280098h, $OfsTStr("TPM 2.0: Union selector is incorrect.")}
  DOM {08028009Ah, $OfsTStr("TPM 2.0: The TPM was unable to unmarshal a value because there were not enough octets in the input buffer.")}
  DOM {08028009Bh, $OfsTStr("TPM 2.0: The signature is not valid.")}
  DOM {08028009Dh, $OfsTStr("TPM 2.0: A policy check failed.")}
  DOM {08028009Fh, $OfsTStr("TPM 2.0: Integrity check failed.")}
  DOM {0802800A0h, $OfsTStr("TPM 2.0: Invalid ticket.")}
  DOM {0802800A1h, $OfsTStr("TPM 2.0: Reserved bits not set to zero as required.")}
  DOM {0802800A2h, $OfsTStr("TPM 2.0: Authorization failure without DA implications.")}
  DOM {0802800A3h, $OfsTStr("TPM 2.0: The policy has expired.")}
  DOM {0802800A4h, $OfsTStr("TPM 2.0: The command code in the policy is not the command code of the command or the command code in a policy command references a command that is not implemented.")}
  DOM {0802800A5h, $OfsTStr("TPM 2.0: Public and sensitive portions of an object are not cryptographically bound.")}
  DOM {0802800A6h, $OfsTStr("TPM 2.0: Curve not supported.")}
  DOM {0802800A7h, $OfsTStr("TPM 2.0: Point is not on the required curve.")}
  DOM {080280100h, $OfsTStr("TPM 2.0: TPM not initialized.")}
  DOM {080280101h, $OfsTStr("TPM 2.0: Commands not being accepted because of a TPM failure.")}
  DOM {080280103h, $OfsTStr("TPM 2.0: Improper use of a sequence handle.")}
  DOM {080280119h, $OfsTStr("TPM 2.0: TPM_RC_HMAC.")}
  DOM {080280120h, $OfsTStr("TPM 2.0: TPM_RC_DISABLED.")}
  DOM {080280121h, $OfsTStr("TPM 2.0: Command failed because audit sequence required exclusivity.")}
  DOM {080280123h, $OfsTStr("TPM 2.0: Unsupported ECC curve.")}
  DOM {080280124h, $OfsTStr("TPM 2.0: Authorization handle is not correct for command.")}
  DOM {080280125h, $OfsTStr("TPM 2.0: Command requires an authorization session for handle and is not present.")}
  DOM {080280126h, $OfsTStr("TPM 2.0: Policy failure in Math Operation or an invalid authPolicy value.")}
  DOM {080280127h, $OfsTStr("TPM 2.0: PCR check fail.")}
  DOM {080280128h, $OfsTStr("TPM 2.0: PCR have changed since checked.")}
  DOM {08028012Dh, $OfsTStr("TPM 2.0: The TPM is not in the right mode for upgrade.")}
  DOM {08028012Eh, $OfsTStr("TPM 2.0: Context ID counter is at maximum.")}
  DOM {08028012Fh, $OfsTStr("TPM 2.0: authValue or authPolicy is not available for selected entity.")}
  DOM {080280130h, $OfsTStr("TPM 2.0: A _TPM_Init and Startup(CLEAR) is required before the TPM can resume operation.")}
  DOM {080280131h, $OfsTStr("TPM 2.0: The protection algorithms (hash and symmetric) are not reasonably balanced. The digest size of the hash must be larger than the key size of the symmetric algorithm.")}
  DOM {080280142h, $OfsTStr("TPM 2.0: The TPM command's commandSize value is inconsistent with contents of the command buffer; either the size is not the same as the bytes loaded by the hardware interface layer or the value is not large enough to hold a command header.")}
  DOM {080280143h, $OfsTStr("TPM 2.0: Command code not supported.")}
  DOM {080280144h, $OfsTStr("TPM 2.0: The value of authorizationSize is out of range or the number of octets in the authorization Area is greater than required.")}
  DOM {080280145h, $OfsTStr("TPM 2.0: Use of an authorization session with a context command or another command that cannot have an authorization session.")}
  DOM {080280146h, $OfsTStr("TPM 2.0: NV offset+size is out of range.")}
  DOM {080280147h, $OfsTStr("TPM 2.0: Requested allocation size is larger than allowed.")}
  DOM {080280148h, $OfsTStr("TPM 2.0: NV access locked.")}
  DOM {080280149h, $OfsTStr("TPM 2.0: NV access authorization fails in command actions")}
  DOM {08028014Ah, $OfsTStr("TPM 2.0: An NV index is used before being initialized or the state saved by TPM2_Shutdown(STATE) could not be restored.")}
  DOM {08028014Bh, $OfsTStr("TPM 2.0: Insufficient space for NV allocation.")}
  DOM {08028014Ch, $OfsTStr("TPM 2.0: NV index or persistent object already defined.")}
  DOM {080280150h, $OfsTStr("TPM 2.0: Context in TPM2_ContextLoad() is not valid.")}
  DOM {080280151h, $OfsTStr("TPM 2.0: chHash value already set or not correct for use.")}
  DOM {080280152h, $OfsTStr("TPM 2.0: Handle for parent is not a valid parent.")}
  DOM {080280153h, $OfsTStr("TPM 2.0: Some function needs testing.")}
  DOM {080280154h, $OfsTStr("TPM 2.0: returned when an internal function cannot process a request due to an unspecified problem. This code is usually related to invalid parameters that are not properly filtered by the input unmarshaling code.")}
  DOM {080280155h, $OfsTStr("TPM 2.0: The sensitive area did not unmarshal correctly after decryption - this code is used in lieu of the other unmarshaling errors so that an attacker cannot determine where the unmarshaling error occurred.")}
  DOM {080280400h, $OfsTStr("The command was blocked.")}
  DOM {080280401h, $OfsTStr("The specified handle was not found.")}
  DOM {080280402h, $OfsTStr("The TPM returned a duplicate handle and the command needs to be resubmitted.")}
  DOM {080280403h, $OfsTStr("The command within the transport was blocked.")}
  DOM {080280404h, $OfsTStr("The command within the transport is not supported.")}
  DOM {080280800h, $OfsTStr("The TPM is too busy to respond to the command immediately")}
  DOM {080280801h, $OfsTStr("SelfTestFull has not been run.")}
  DOM {080280802h, $OfsTStr("The TPM is currently executing a full selftest.")}
  DOM {080280803h, $OfsTStr("The TPM is defending against dictionary attacks and is in a time-out period.")}
  DOM {080280901h, $OfsTStr("TPM 2.0: Gap for context ID is too large.")}
  DOM {080280902h, $OfsTStr("TPM 2.0: Out of memory for object contexts.")}
  DOM {080280903h, $OfsTStr("TPM 2.0: Out of memory for session contexts.")}
  DOM {080280904h, $OfsTStr("TPM 2.0: Out of shared object/session memory or need space for internal operations.")}
  DOM {080280905h, $OfsTStr("TPM 2.0: Out of session handles - a session must be flushed before a new session may be created.")}
  DOM {080280906h, $OfsTStr("TPM 2.0: Out of object handles - the handle space for objects is depleted and a reboot is required.")}
  DOM {080280907h, $OfsTStr("TPM 2.0: Bad locality.")}
  DOM {080280908h, $OfsTStr("TPM 2.0: The TPM has suspended operation on the command; forward progress was made and the command may be retried.")}
  DOM {080280909h, $OfsTStr("TPM 2.0: The command was canceled.")}
  DOM {08028090Ah, $OfsTStr("TPM 2.0: TPM is performing self-tests.")}
  DOM {080280920h, $OfsTStr("TPM 2.0: The TPM is rate-limiting accesses to prevent wearout of NV.")}
  DOM {080280921h, $OfsTStr("TPM 2.0: Authorization for objects subject to DA protection are not allowed at this time because the TPM is in DA lockout mode.")}
  DOM {080280922h, $OfsTStr("TPM 2.0: The TPM was not able to start the command.")}
  DOM {080280923h, $OfsTStr("TPM 2.0: the command may require writing of NV and NV is not current accessible..")}
  DOM {080284001h, $OfsTStr("An internal software error has been detected.")}
  DOM {080284002h, $OfsTStr("One or more input parameters is bad.")}
  DOM {080284003h, $OfsTStr("A specified output pointer is bad.")}
  DOM {080284004h, $OfsTStr("The specified context handle does not refer to a valid context.")}
  DOM {080284005h, $OfsTStr("A specified output buffer is too small.")}
  DOM {080284006h, $OfsTStr("An error occurred while communicating with the TPM.")}
  DOM {080284007h, $OfsTStr("One or more context parameters is invalid.")}
  DOM {080284008h, $OfsTStr("The TBS service is not running and could not be started.")}
  DOM {080284009h, $OfsTStr("A new context could not be created because there are too many open contexts.")}
  DOM {08028400Ah, $OfsTStr("A new virtual resource could not be created because there are too many open virtual resources.")}
  DOM {08028400Bh, $OfsTStr("The TBS service has been started but is not yet running.")}
  DOM {08028400Ch, $OfsTStr("The physical presence interface is not supported.")}
  DOM {08028400Dh, $OfsTStr("The command was canceled.")}
  DOM {08028400Eh, $OfsTStr("The input or output buffer is too large.")}
  DOM {08028400Fh, $OfsTStr("A compatible Trusted Platform Module (TPM) Security Device cannot be found on this computer.")}
  DOM {080284010h, $OfsTStr("The TBS service has been disabled.")}
  DOM {080284011h, $OfsTStr("No TCG event log is available.")}
  DOM {080284012h, $OfsTStr("The caller does not have the appropriate rights to perform the requested operation.")}
  DOM {080284013h, $OfsTStr("The TPM provisioning action is not allowed by the specified flags. For provisioning to be successful")}
  DOM {080284014h, $OfsTStr("The Physical Presence Interface of this firmware does not support the requested method.")}
  DOM {080284015h, $OfsTStr("The requested TPM OwnerAuth value was not found.")}
  DOM {080284016h, $OfsTStr("The TPM provisioning did not complete. For more information on completing the provisioning")}
  DOM {080290100h, $OfsTStr("The command buffer is not in the correct state.")}
  DOM {080290101h, $OfsTStr("The command buffer does not contain enough data to satisfy the request.")}
  DOM {080290102h, $OfsTStr("The command buffer cannot contain any more data.")}
  DOM {080290103h, $OfsTStr("One or more output parameters was NULL or invalid.")}
  DOM {080290104h, $OfsTStr("One or more input parameters is invalid.")}
  DOM {080290105h, $OfsTStr("Not enough memory was available to satisfy the request.")}
  DOM {080290106h, $OfsTStr("The specified buffer was too small.")}
  DOM {080290107h, $OfsTStr("An internal error was detected.")}
  DOM {080290108h, $OfsTStr("The caller does not have the appropriate rights to perform the requested operation.")}
  DOM {080290109h, $OfsTStr("The specified authorization information was invalid.")}
  DOM {08029010Ah, $OfsTStr("The specified context handle was not valid.")}
  DOM {08029010Bh, $OfsTStr("An error occurred while communicating with the TBS.")}
  DOM {08029010Ch, $OfsTStr("The TPM returned an unexpected result.")}
  DOM {08029010Dh, $OfsTStr("The message was too large for the encoding scheme.")}
  DOM {08029010Eh, $OfsTStr("The encoding in the blob was not recognized.")}
  DOM {08029010Fh, $OfsTStr("The key size is not valid.")}
  DOM {080290110h, $OfsTStr("The encryption operation failed.")}
  DOM {080290111h, $OfsTStr("The key parameters structure was not valid")}
  DOM {080290112h, $OfsTStr("The requested supplied data does not appear to be a valid migration authorization blob.")}
  DOM {080290113h, $OfsTStr("The specified PCR index was invalid")}
  DOM {080290114h, $OfsTStr("The data given does not appear to be a valid delegate blob.")}
  DOM {080290115h, $OfsTStr("One or more of the specified context parameters was not valid.")}
  DOM {080290116h, $OfsTStr("The data given does not appear to be a valid key blob")}
  DOM {080290117h, $OfsTStr("The specified PCR data was invalid.")}
  DOM {080290118h, $OfsTStr("The format of the owner auth data was invalid.")}
  DOM {080290119h, $OfsTStr("The random number generated did not pass FIPS RNG check.")}
  DOM {08029011Ah, $OfsTStr("The TCG Event Log does not contain any data.")}
  DOM {08029011Bh, $OfsTStr("An entry in the TCG Event Log was invalid.")}
  DOM {08029011Ch, $OfsTStr("A TCG Separator was not found.")}
  DOM {08029011Dh, $OfsTStr("A digest value in a TCG Log entry did not match hashed data.")}
  DOM {08029011Eh, $OfsTStr("The requested operation was blocked by current TPM policy. Please contact your system administrator for assistance.")}
  DOM {080290200h, $OfsTStr("The specified buffer was too small.")}
  DOM {080290201h, $OfsTStr("The context could not be cleaned up.")}
  DOM {080290202h, $OfsTStr("The specified context handle is invalid.")}
  DOM {080290203h, $OfsTStr("An invalid context parameter was specified.")}
  DOM {080290204h, $OfsTStr("An error occurred while communicating with the TPM")}
  DOM {080290205h, $OfsTStr("No entry with the specified key was found.")}
  DOM {080290206h, $OfsTStr("The specified virtual handle matches a virtual handle already in use.")}
  DOM {080290207h, $OfsTStr("The pointer to the returned handle location was NULL or invalid")}
  DOM {080290208h, $OfsTStr("One or more parameters is invalid")}
  DOM {080290209h, $OfsTStr("The RPC subsystem could not be initialized.")}
  DOM {08029020Ah, $OfsTStr("The TBS scheduler is not running.")}
  DOM {08029020Bh, $OfsTStr("The command was canceled.")}
  DOM {08029020Ch, $OfsTStr("There was not enough memory to fulfill the request")}
  DOM {08029020Dh, $OfsTStr("The specified list is empty")}
  DOM {08029020Eh, $OfsTStr("The specified item was not found in the list.")}
  DOM {08029020Fh, $OfsTStr("The TPM does not have enough space to load the requested resource.")}
  DOM {080290210h, $OfsTStr("There are too many TPM contexts in use.")}
  DOM {080290211h, $OfsTStr("The TPM command failed.")}
  DOM {080290212h, $OfsTStr("The TBS does not recognize the specified ordinal.")}
  DOM {080290213h, $OfsTStr("The requested resource is no longer available.")}
  DOM {080290214h, $OfsTStr("The resource type did not match.")}
  DOM {080290215h, $OfsTStr("No resources can be unloaded.")}
  DOM {080290216h, $OfsTStr("No new entries can be added to the hash table.")}
  DOM {080290217h, $OfsTStr("A new TBS context could not be created because there are too many open contexts.")}
  DOM {080290218h, $OfsTStr("A new virtual resource could not be created because there are too many open virtual resources.")}
  DOM {080290219h, $OfsTStr("The physical presence interface is not supported.")}
  DOM {08029021Ah, $OfsTStr("TBS is not compatible with the version of TPM found on the system.")}
  DOM {08029021Bh, $OfsTStr("No TCG event log is available.")}
  DOM {080290300h, $OfsTStr("A general error was detected when attempting to acquire the BIOS's response to a Physical Presence command.")}
  DOM {080290301h, $OfsTStr("The user failed to confirm the TPM operation request.")}
  DOM {080290302h, $OfsTStr("The BIOS failure prevented the successful execution of the requested TPM operation (e.g. invalid TPM operation request")}
  DOM {080290303h, $OfsTStr("The BIOS does not support the physical presence interface.")}
  DOM {080290304h, $OfsTStr("The Physical Presence command was blocked by current BIOS settings. The system owner may be able to reconfigure the BIOS settings to allow the command.")}
  DOM {080290400h, $OfsTStr("This is an error mask to convert Platform Crypto Provider errors to win errors.")}
  DOM {080290401h, $OfsTStr("The Platform Crypto Device is currently not ready. It needs to be fully provisioned to be operational.")}
  DOM {080290402h, $OfsTStr("The handle provided to the Platform Crypto Provider is invalid.")}
  DOM {080290403h, $OfsTStr("A parameter provided to the Platform Crypto Provider is invalid.")}
  DOM {080290404h, $OfsTStr("A provided flag to the Platform Crypto Provider is not supported.")}
  DOM {080290405h, $OfsTStr("The requested operation is not supported by this Platform Crypto Provider.")}
  DOM {080290406h, $OfsTStr("The buffer is too small to contain all data. No information has been written to the buffer.")}
  DOM {080290407h, $OfsTStr("An unexpected internal error has occurred in the Platform Crypto Provider.")}
  DOM {080290408h, $OfsTStr("The authorization to use a provider object has failed.")}
  DOM {080290409h, $OfsTStr("The Platform Crypto Device has ignored the authorization for the provider object")}
  DOM {08029040Ah, $OfsTStr("The referenced policy was not found.")}
  DOM {08029040Bh, $OfsTStr("The referenced profile was not found.")}
  DOM {08029040Ch, $OfsTStr("The validation was not successful.")}
  DOM {08029040Eh, $OfsTStr("An attempt was made to import or load a key under an incorrect storage parent.")}
  DOM {08029040Fh, $OfsTStr("The TPM key is not loaded.")}
  DOM {080290410h, $OfsTStr("The TPM key certification has not been generated.")}
  DOM {080290411h, $OfsTStr("The TPM key is not yet finalized.")}
  DOM {080290412h, $OfsTStr("The TPM attestation challenge is not set.")}
  DOM {080290413h, $OfsTStr("The TPM PCR info is not available.")}
  DOM {080290414h, $OfsTStr("The TPM key is already finalized.")}
  DOM {080290415h, $OfsTStr("The TPM key usage policy is not supported.")}
  DOM {080290416h, $OfsTStr("The TPM key usage policy is invalid.")}
  DOM {080290417h, $OfsTStr("There was a problem with the software key being imported into the TPM.")}
  DOM {080290418h, $OfsTStr("The TPM key is not authenticated.")}
  DOM {080290419h, $OfsTStr("The TPM key is not an AIK.")}
  DOM {08029041Ah, $OfsTStr("The TPM key is not a signing key.")}
  DOM {08029041Bh, $OfsTStr("The TPM is locked out.")}
  DOM {08029041Ch, $OfsTStr("The claim type requested is not supported.")}
  DOM {08029041Dh, $OfsTStr("TPM version is not supported.")}
  DOM {08029041Eh, $OfsTStr("The buffer lengths do not match.")}
  DOM {08029041Fh, $OfsTStr("The RSA key creation is blocked on this TPM due to known security vulnerabilities.")}
  DOM {080290420h, $OfsTStr("A ticket required to use a key was not provided.")}
  DOM {080290421h, $OfsTStr("This key has a raw policy so the KSP can't authenticate against it.")}
  DOM {080290422h, $OfsTStr("The TPM key's handle was unexpectedly invalidated due to a hardware or firmware issue.")}
  DOM {080290500h, $OfsTStr("TPM related network operations are blocked as Zero Exhaust mode is enabled on client.")}
  DOM {080290600h, $OfsTStr("TPM provisioning did not run to completion.")}
  DOM {080290601h, $OfsTStr("An invalid owner authorization value was specified.")}
  DOM {080290602h, $OfsTStr("TPM command returned too much data.")}
  DOM {0802A0001h, $OfsTStr("The object could not be created.")}
  DOM {0802A0002h, $OfsTStr("Shutdown was already called on this object or the object that owns it.")}
  DOM {0802A0003h, $OfsTStr("This method cannot be called during this type of callback.")}
  DOM {0802A0004h, $OfsTStr("This object has been sealed")}
  DOM {0802A0005h, $OfsTStr("The requested value was never set.")}
  DOM {0802A0006h, $OfsTStr("The requested value cannot be determined.")}
  DOM {0802A0007h, $OfsTStr("A callback returned an invalid output parameter.")}
  DOM {0802A0008h, $OfsTStr("A callback returned a success code other than S_OK or S_FALSE.")}
  DOM {0802A0009h, $OfsTStr("A parameter that should be owned by this object is owned by a different object.")}
  DOM {0802A000Ah, $OfsTStr("More than one item matched the search criteria.")}
  DOM {0802A000Bh, $OfsTStr("A floating-point overflow occurred.")}
  DOM {0802A000Ch, $OfsTStr("This method can only be called from the thread that created the object.")}
  DOM {0802A0101h, $OfsTStr("The storyboard is currently in the schedule.")}
  DOM {0802A0102h, $OfsTStr("The storyboard is not playing.")}
  DOM {0802A0103h, $OfsTStr("The start keyframe might occur after the end keyframe.")}
  DOM {0802A0104h, $OfsTStr("It might not be possible to determine the end keyframe time when the start keyframe is reached.")}
  DOM {0802A0105h, $OfsTStr("Two repeated portions of a storyboard might overlap.")}
  DOM {0802A0106h, $OfsTStr("The transition has already been added to a storyboard.")}
  DOM {0802A0107h, $OfsTStr("The transition has not been added to a storyboard.")}
  DOM {0802A0108h, $OfsTStr("The transition might eclipse the beginning of another transition in the storyboard.")}
  DOM {0802A0109h, $OfsTStr("The given time is earlier than the time passed to the last update.")}
  DOM {0802A010Ah, $OfsTStr("This client is already connected to a timer.")}
  DOM {0802A010Bh, $OfsTStr("The passed dimension is invalid or does not match the object's dimension.")}
  DOM {0802A010Ch, $OfsTStr("The added primitive begins at or beyond the duration of the interpolator.")}
  DOM {0802A0201h, $OfsTStr("The operation cannot be completed because the window is being closed.")}
  DOM {080300002h, $OfsTStr("Data Collector Set was not found.")}
  DOM {080300045h, $OfsTStr("Unable to start Data Collector Set because there are too many folders.")}
  DOM {080300070h, $OfsTStr("Not enough free disk space to start Data Collector Set.")}
  DOM {0803000AAh, $OfsTStr("The Data Collector Set or one of its dependencies is already in use.")}
  DOM {0803000B7h, $OfsTStr("Data Collector Set already exists.")}
  DOM {080300101h, $OfsTStr("Property value conflict.")}
  DOM {080300102h, $OfsTStr("The current configuration for this Data Collector Set requires that it contain exactly one Data Collector.")}
  DOM {080300103h, $OfsTStr("A user account is required in order to commit the current Data Collector Set properties.")}
  DOM {080300104h, $OfsTStr("Data Collector Set is not running.")}
  DOM {080300105h, $OfsTStr("A conflict was detected in the list of include/exclude APIs. Do not specify the same API in both the include list and the exclude list.")}
  DOM {080300106h, $OfsTStr("The executable path you have specified refers to a network share or UNC path.")}
  DOM {080300107h, $OfsTStr("The executable path you have specified is already configured for API tracing.")}
  DOM {080300108h, $OfsTStr("The executable path you have specified does not exist. Verify that the specified path is correct.")}
  DOM {080300109h, $OfsTStr("Data Collector already exists.")}
  DOM {08030010Ah, $OfsTStr("The wait for the Data Collector Set start notification has timed out.")}
  DOM {08030010Bh, $OfsTStr("The wait for the Data Collector to start has timed out.")}
  DOM {08030010Ch, $OfsTStr("The wait for the report generation tool to finish has timed out.")}
  DOM {08030010Dh, $OfsTStr("Duplicate items are not allowed.")}
  DOM {08030010Eh, $OfsTStr("When specifying the executable that you want to trace")}
  DOM {08030010Fh, $OfsTStr("The session name provided is invalid.")}
  DOM {080300110h, $OfsTStr("The Event Log channel Microsoft-Windows-Diagnosis-PLA/Operational must be enabled to perform this operation.")}
  DOM {080300111h, $OfsTStr("The Event Log channel Microsoft-Windows-TaskScheduler must be enabled to perform this operation.")}
  DOM {080300112h, $OfsTStr("The execution of the Rules Manager failed.")}
  DOM {080300113h, $OfsTStr("An error occurred while attempting to compress or extract the data.")}
  DOM {080310000h, $OfsTStr("This drive is locked by BitLocker Drive Encryption. You must unlock this drive from Control Panel.")}
  DOM {080310001h, $OfsTStr("The drive is not encrypted.")}
  DOM {080310002h, $OfsTStr("The BIOS did not correctly communicate with the Trusted Platform Module (TPM). Contact the computer manufacturer for BIOS upgrade instructions.")}
  DOM {080310003h, $OfsTStr("The BIOS did not correctly communicate with the master boot record (MBR). Contact the computer manufacturer for BIOS upgrade instructions.")}
  DOM {080310004h, $OfsTStr("A required TPM measurement is missing. If there is a bootable CD or DVD in your computer")}
  DOM {080310005h, $OfsTStr("The boot sector of this drive is not compatible with BitLocker Drive Encryption. Use the Bootrec.exe tool in the Windows Recovery Environment to update or repair the boot manager (BOOTMGR).")}
  DOM {080310006h, $OfsTStr("The boot manager of this operating system is not compatible with BitLocker Drive Encryption. Use the Bootrec.exe tool in the Windows Recovery Environment to update or repair the boot manager (BOOTMGR).")}
  DOM {080310007h, $OfsTStr("At least one secure key protector is required for this operation to be performed.")}
  DOM {080310008h, $OfsTStr("BitLocker Drive Encryption is not enabled on this drive. Turn on BitLocker.")}
  DOM {080310009h, $OfsTStr("BitLocker Drive Encryption cannot perform requested action. This condition may occur when two requests are issued at the same time. Wait a few moments and then try the action again.")}
  DOM {08031000Ah, $OfsTStr("The Active Directory Domain Services forest does not contain the required attributes and classes to host BitLocker Drive Encryption or Trusted Platform Module information. Contact your domain administrator to verify that any required BitLocker Active Directory schema extensions have been installed.")}
  DOM {08031000Bh, $OfsTStr("The type of the data obtained from Active Directory was not expected. The BitLocker recovery information may be missing or corrupted.")}
  DOM {08031000Ch, $OfsTStr("The size of the data obtained from Active Directory was not expected. The BitLocker recovery information may be missing or corrupted.")}
  DOM {08031000Dh, $OfsTStr("The attribute read from Active Directory does not contain any values. The BitLocker recovery information may be missing or corrupted.")}
  DOM {08031000Eh, $OfsTStr("The attribute was not set. Verify that you are logged on with a domain account that has the ability to write information to Active Directory objects.")}
  DOM {08031000Fh, $OfsTStr("The specified attribute cannot be found in Active Directory Domain Services. Contact your domain administrator to verify that any required BitLocker Active Directory schema extensions have been installed.")}
  DOM {080310010h, $OfsTStr("The BitLocker metadata for the encrypted drive is not valid. You can attempt to repair the drive to restore access.")}
  DOM {080310011h, $OfsTStr("The drive cannot be encrypted because it does not have enough free space. Delete any unnecessary data on the drive to create additional free space and then try again.")}
  DOM {080310012h, $OfsTStr("The drive cannot be encrypted because it contains system boot information. Create a separate partition for use as the system drive that contains the boot information and a second partition for use as the operating system drive and then encrypt the operating system drive.")}
  DOM {080310013h, $OfsTStr("The drive cannot be encrypted because the file system is not supported.")}
  DOM {080310014h, $OfsTStr("The file system size is larger than the partition size in the partition table. This drive may be corrupt or may have been tampered with. To use it with BitLocker")}
  DOM {080310015h, $OfsTStr("This drive cannot be encrypted.")}
  DOM {080310016h, $OfsTStr("The data is not valid.")}
  DOM {080310017h, $OfsTStr("The data drive specified is not set to automatically unlock on the current computer and cannot be unlocked automatically.")}
  DOM {080310018h, $OfsTStr("You must initialize the Trusted Platform Module (TPM) before you can use BitLocker Drive Encryption.")}
  DOM {080310019h, $OfsTStr("The operation attempted cannot be performed on an operating system drive.")}
  DOM {08031001Ah, $OfsTStr("The buffer supplied to a function was insufficient to contain the returned data. Increase the buffer size before running the function again.")}
  DOM {08031001Bh, $OfsTStr("A read operation failed while converting the drive. The drive was not converted. Please re-enable BitLocker.")}
  DOM {08031001Ch, $OfsTStr("A write operation failed while converting the drive. The drive was not converted. Please re-enable BitLocker.")}
  DOM {08031001Dh, $OfsTStr("One or more BitLocker key protectors are required. You cannot delete the last key on this drive.")}
  DOM {08031001Eh, $OfsTStr("Cluster configurations are not supported by BitLocker Drive Encryption.")}
  DOM {08031001Fh, $OfsTStr("The drive specified is already configured to be automatically unlocked on the current computer.")}
  DOM {080310020h, $OfsTStr("The operating system drive is not protected by BitLocker Drive Encryption.")}
  DOM {080310021h, $OfsTStr("BitLocker Drive Encryption has been suspended on this drive. All BitLocker key protectors configured for this drive are effectively disabled")}
  DOM {080310022h, $OfsTStr("The drive you are attempting to lock does not have any key protectors available for encryption because BitLocker protection is currently suspended. Re-enable BitLocker to lock this drive.")}
  DOM {080310023h, $OfsTStr("BitLocker cannot use the Trusted Platform Module (TPM) to protect a data drive. TPM protection can only be used with the operating system drive.")}
  DOM {080310024h, $OfsTStr("The BitLocker metadata for the encrypted drive cannot be updated because it was locked for updating by another process. Please try this process again.")}
  DOM {080310025h, $OfsTStr("The authorization data for the storage root key (SRK) of the Trusted Platform Module (TPM) is not zero and is therefore incompatible with BitLocker. Please initialize the TPM before attempting to use it with BitLocker.")}
  DOM {080310026h, $OfsTStr("The drive encryption algorithm cannot be used on this sector size.")}
  DOM {080310027h, $OfsTStr("The drive cannot be unlocked with the key provided. Confirm that you have provided the correct key and try again.")}
  DOM {080310028h, $OfsTStr("The drive specified is not the operating system drive.")}
  DOM {080310029h, $OfsTStr("BitLocker Drive Encryption cannot be turned off on the operating system drive until the auto unlock feature has been disabled for the fixed data drives and removable data drives associated with this computer.")}
  DOM {08031002Ah, $OfsTStr("The system partition boot sector does not perform Trusted Platform Module (TPM) measurements. Use the Bootrec.exe tool in the Windows Recovery Environment to update or repair the boot sector.")}
  DOM {08031002Bh, $OfsTStr("BitLocker Drive Encryption operating system drives must be formatted with the NTFS file system in order to be encrypted. Convert the drive to NTFS")}
  DOM {08031002Ch, $OfsTStr("Group Policy settings require that a recovery password be specified before encrypting the drive.")}
  DOM {08031002Dh, $OfsTStr("The drive encryption algorithm and key cannot be set on a previously encrypted drive. To encrypt this drive with BitLocker Drive Encryption")}
  DOM {08031002Eh, $OfsTStr("BitLocker Drive Encryption cannot encrypt the specified drive because an encryption key is not available. Add a key protector to encrypt this drive.")}
  DOM {080310030h, $OfsTStr("BitLocker Drive Encryption detected bootable media (CD or DVD) in the computer. Remove the media and restart the computer before configuring BitLocker.")}
  DOM {080310031h, $OfsTStr("This key protector cannot be added. Only one key protector of this type is allowed for this drive.")}
  DOM {080310032h, $OfsTStr("The recovery password file was not found because a relative path was specified. Recovery passwords must be saved to a fully qualified path. Environment variables configured on the computer can be used in the path.")}
  DOM {080310033h, $OfsTStr("The specified key protector was not found on the drive. Try another key protector.")}
  DOM {080310034h, $OfsTStr("The recovery key provided is corrupt and cannot be used to access the drive. An alternative recovery method")}
  DOM {080310035h, $OfsTStr("The format of the recovery password provided is invalid. BitLocker recovery passwords are 48 digits. Verify that the recovery password is in the correct format and then try again.")}
  DOM {080310036h, $OfsTStr("The random number generator check test failed.")}
  DOM {080310037h, $OfsTStr("The Group Policy setting requiring FIPS compliance prevents a local recovery password from being generated or used by BitLocker Drive Encryption. When operating in FIPS-compliant mode")}
  DOM {080310038h, $OfsTStr("The Group Policy setting requiring FIPS compliance prevents the recovery password from being saved to Active Directory. When operating in FIPS-compliant mode")}
  DOM {080310039h, $OfsTStr("The drive must be fully decrypted to complete this operation.")}
  DOM {08031003Ah, $OfsTStr("The key protector specified cannot be used for this operation.")}
  DOM {08031003Bh, $OfsTStr("No key protectors exist on the drive to perform the hardware test.")}
  DOM {08031003Ch, $OfsTStr("The BitLocker startup key or recovery password cannot be found on the USB device. Verify that you have the correct USB device")}
  DOM {08031003Dh, $OfsTStr("The BitLocker startup key or recovery password file provided is corrupt or invalid. Verify that you have the correct startup key or recovery password file and try again.")}
  DOM {08031003Eh, $OfsTStr("The BitLocker encryption key cannot be obtained from the startup key or recovery password. Verify that you have the correct startup key or recovery password and try again.")}
  DOM {08031003Fh, $OfsTStr("The Trusted Platform Module (TPM) is disabled. The TPM must be enabled")}
  DOM {080310040h, $OfsTStr("The BitLocker configuration of the specified drive cannot be managed because this computer is currently operating in Safe Mode. While in Safe Mode")}
  DOM {080310041h, $OfsTStr("The Trusted Platform Module (TPM) was not able to unlock the drive because the system boot information has changed or a PIN was not provided correctly. Verify that the drive has not been tampered with and that changes to the system boot information were caused by a trusted source. After verifying that the drive is safe to access")}
  DOM {080310042h, $OfsTStr("The BitLocker encryption key cannot be obtained from the Trusted Platform Module (TPM).")}
  DOM {080310043h, $OfsTStr("The BitLocker encryption key cannot be obtained from the Trusted Platform Module (TPM) and PIN.")}
  DOM {080310044h, $OfsTStr("A boot application has changed since BitLocker Drive Encryption was enabled.")}
  DOM {080310045h, $OfsTStr("The Boot Configuration Data (BCD) settings have changed since BitLocker Drive Encryption was enabled.")}
  DOM {080310046h, $OfsTStr("The Group Policy setting requiring FIPS compliance prohibits the use of unencrypted keys")}
  DOM {080310047h, $OfsTStr("This drive cannot be encrypted by BitLocker Drive Encryption because the file system does not extend to the end of the drive. Repartition this drive and then try again.")}
  DOM {080310048h, $OfsTStr("BitLocker Drive Encryption cannot be enabled on the operating system drive. Contact the computer manufacturer for BIOS upgrade instructions.")}
  DOM {080310049h, $OfsTStr("This version of Windows does not include BitLocker Drive Encryption. To use BitLocker Drive Encryption")}
  DOM {08031004Ah, $OfsTStr("BitLocker Drive Encryption cannot be used because critical BitLocker system files are missing or corrupted. Use Windows Startup Repair to restore these files to your computer.")}
  DOM {08031004Bh, $OfsTStr("The drive cannot be locked when the drive is in use.")}
  DOM {08031004Ch, $OfsTStr("The access token associated with the current thread is not an impersonated token.")}
  DOM {08031004Dh, $OfsTStr("The BitLocker encryption key cannot be obtained. Verify that the Trusted Platform Module (TPM) is enabled and ownership has been taken. If this computer does not have a TPM")}
  DOM {08031004Eh, $OfsTStr("You must restart your computer before continuing with BitLocker Drive Encryption.")}
  DOM {08031004Fh, $OfsTStr("Drive encryption cannot occur while boot debugging is enabled. Use the bcdedit command-line tool to turn off boot debugging.")}
  DOM {080310050h, $OfsTStr("No action was taken as BitLocker Drive Encryption is in raw access mode.")}
  DOM {080310051h, $OfsTStr("BitLocker Drive Encryption cannot enter raw access mode for this drive because the drive is currently in use.")}
  DOM {080310052h, $OfsTStr("The path specified in the Boot Configuration Data (BCD) for a BitLocker Drive Encryption integrity-protected application is incorrect. Please verify and correct your BCD settings and try again.")}
  DOM {080310053h, $OfsTStr("BitLocker Drive Encryption can only be used for limited provisioning or recovery purposes when the computer is running in pre-installation or recovery environments.")}
  DOM {080310054h, $OfsTStr("The auto-unlock master key was not available from the operating system drive.")}
  DOM {080310055h, $OfsTStr("The system firmware failed to enable clearing of system memory when the computer was restarted.")}
  DOM {080310056h, $OfsTStr("The hidden drive cannot be encrypted.")}
  DOM {080310057h, $OfsTStr("BitLocker encryption keys were ignored because the drive was in a transient state.")}
  DOM {080310058h, $OfsTStr("Public key based protectors are not allowed on this drive.")}
  DOM {080310059h, $OfsTStr("BitLocker Drive Encryption is already performing an operation on this drive. Please complete all operations before continuing.")}
  DOM {08031005Ah, $OfsTStr("This version of Windows does not support this feature of BitLocker Drive Encryption. To use this feature")}
  DOM {08031005Bh, $OfsTStr("The Group Policy settings for BitLocker startup options are in conflict and cannot be applied. Contact your system administrator for more information.")}
  DOM {08031005Ch, $OfsTStr("Group policy settings do not permit the creation of a recovery password.")}
  DOM {08031005Dh, $OfsTStr("Group policy settings require the creation of a recovery password.")}
  DOM {08031005Eh, $OfsTStr("Group policy settings do not permit the creation of a recovery key.")}
  DOM {08031005Fh, $OfsTStr("Group policy settings require the creation of a recovery key.")}
  DOM {080310060h, $OfsTStr("Group policy settings do not permit the use of a PIN at startup. Please choose a different BitLocker startup option.")}
  DOM {080310061h, $OfsTStr("Group policy settings require the use of a PIN at startup. Please choose this BitLocker startup option.")}
  DOM {080310062h, $OfsTStr("Group policy settings do not permit the use of a startup key. Please choose a different BitLocker startup option.")}
  DOM {080310063h, $OfsTStr("Group policy settings require the use of a startup key. Please choose this BitLocker startup option.")}
  DOM {080310064h, $OfsTStr("Group policy settings do not permit the use of a startup key and PIN. Please choose a different BitLocker startup option.")}
  DOM {080310065h, $OfsTStr("Group policy settings require the use of a startup key and PIN. Please choose this BitLocker startup option.")}
  DOM {080310066h, $OfsTStr("Group policy does not permit the use of TPM-only at startup. Please choose a different BitLocker startup option.")}
  DOM {080310067h, $OfsTStr("Group policy settings require the use of TPM-only at startup. Please choose this BitLocker startup option.")}
  DOM {080310068h, $OfsTStr("The PIN provided does not meet minimum or maximum length requirements.")}
  DOM {080310069h, $OfsTStr("The key protector is not supported by the version of BitLocker Drive Encryption currently on the drive. Upgrade the drive to add the key protector.")}
  DOM {08031006Ah, $OfsTStr("Group policy settings do not permit the creation of a password.")}
  DOM {08031006Bh, $OfsTStr("Group policy settings require the creation of a password.")}
  DOM {08031006Ch, $OfsTStr("The group policy setting requiring FIPS compliance prevented the password from being generated or used. Please contact your domain administrator for more information.")}
  DOM {08031006Dh, $OfsTStr("A password cannot be added to the operating system drive.")}
  DOM {08031006Eh, $OfsTStr("The BitLocker object identifier (OID) on the drive appears to be invalid or corrupt. Use manage-BDE to reset the OID on this drive.")}
  DOM {08031006Fh, $OfsTStr("The drive is too small to be protected using BitLocker Drive Encryption.")}
  DOM {080310070h, $OfsTStr("The selected discovery drive type is incompatible with the file system on the drive. BitLocker To Go discovery drives must be created on FAT formatted drives.")}
  DOM {080310071h, $OfsTStr("The selected discovery drive type is not allowed by the computer's Group Policy settings. Verify that Group Policy settings allow the creation of discovery drives for use with BitLocker To Go.")}
  DOM {080310072h, $OfsTStr("Group Policy settings do not permit user certificates such as smart cards to be used with BitLocker Drive Encryption.")}
  DOM {080310073h, $OfsTStr("Group Policy settings require that you have a valid user certificate")}
  DOM {080310074h, $OfsTStr("Group Policy settings requires that you use a smart card-based key protector with BitLocker Drive Encryption.")}
  DOM {080310075h, $OfsTStr("Group Policy settings do not permit BitLocker-protected fixed data drives to be automatically unlocked.")}
  DOM {080310076h, $OfsTStr("Group Policy settings do not permit BitLocker-protected removable data drives to be automatically unlocked.")}
  DOM {080310077h, $OfsTStr("Group Policy settings do not permit you to configure BitLocker Drive Encryption on removable data drives.")}
  DOM {080310078h, $OfsTStr("Group Policy settings do not permit you to turn on BitLocker Drive Encryption on removable data drives. Please contact your system administrator if you need to turn on BitLocker.")}
  DOM {080310079h, $OfsTStr("Group Policy settings do not permit turning off BitLocker Drive Encryption on removable data drives. Please contact your system administrator if you need to turn off BitLocker.")}
  DOM {080310080h, $OfsTStr("Your password does not meet minimum password length requirements. By default")}
  DOM {080310081h, $OfsTStr("Your password does not meet the complexity requirements set by your system administrator. Try adding upper and lowercase characters")}
  DOM {080310082h, $OfsTStr("This drive cannot be encrypted because it is reserved for Windows System Recovery Options.")}
  DOM {080310083h, $OfsTStr("BitLocker Drive Encryption cannot be applied to this drive because of conflicting Group Policy settings. BitLocker cannot be configured to automatically unlock fixed data drives when user recovery options are disabled. If you want BitLocker-protected fixed data drives to be automatically unlocked after key validation has occurred")}
  DOM {080310084h, $OfsTStr("BitLocker Drive Encryption cannot be applied to this drive because of conflicting Group Policy settings. BitLocker cannot be configured to automatically unlock removable data drives when user recovery option are disabled. If you want BitLocker-protected removable data drives to be automatically unlocked after key validation has occured")}
  DOM {080310085h, $OfsTStr("The Enhanced Key Usage (EKU) attribute of the specified certificate does not permit it to be used for BitLocker Drive Encryption. BitLocker does not require that a certificate have an EKU attribute")}
  DOM {080310086h, $OfsTStr("BitLocker Drive Encryption cannot be applied to this drive as currently configured because of Group Policy settings. The certificate you provided for drive encryption is self-signed. Current Group Policy settings do not permit the use of self-signed certificates. Obtain a new certificate from your certification authority before attempting to enable BitLocker.")}
  DOM {080310087h, $OfsTStr("BitLocker Encryption cannot be applied to this drive because of conflicting Group Policy settings. When write access to drives not protected by BitLocker is denied")}
  DOM {080310088h, $OfsTStr("BitLocker Drive Encryption cannot be applied to this drive because there are conflicting Group Policy settings for recovery options on operating system drives. Storing recovery information to Active Directory Domain Services cannot be required when the generation of recovery passwords is not permitted. Please have your system administrator resolve these policy conflicts before attempting to enable BitLocker.")}
  DOM {080310089h, $OfsTStr("The requested virtualization size is too big.")}
  DOM {080310090h, $OfsTStr("BitLocker Drive Encryption cannot be applied to this drive because there are conflicting Group Policy settings for recovery options on operating system drives. Storing recovery information to Active Directory Domain Services cannot be required when the generation of recovery passwords is not permitted. Please have your system administrator resolve these policy conflicts before attempting to enable BitLocker.")}
  DOM {080310091h, $OfsTStr("BitLocker Drive Encryption cannot be applied to this drive because there are conflicting Group Policy settings for recovery options on fixed data drives. Storing recovery information to Active Directory Domain Services cannot be required when the generation of recovery passwords is not permitted. Please have your system administrator resolve these policy conflicts before attempting to enable BitLocker.")}
  DOM {080310092h, $OfsTStr("BitLocker Drive Encryption cannot be applied to this drive because there are conflicting Group Policy settings for recovery options on removable data drives. Storing recovery information to Active Directory Domain Services cannot be required when the generation of recovery passwords is not permitted. Please have your system administrator resolve these policy conflicts before attempting to enable BitLocker.")}
  DOM {080310093h, $OfsTStr("The Key Usage (KU) attribute of the specified certificate does not permit it to be used for BitLocker Drive Encryption. BitLocker does not require that a certificate have a KU attribute")}
  DOM {080310094h, $OfsTStr("The private key associated with the specified certificate cannot be authorized. The private key authorization was either not provided or the provided authorization was invalid.")}
  DOM {080310095h, $OfsTStr("Removal of the data recovery agent certificate must be done using the Certificates snap-in.")}
  DOM {080310096h, $OfsTStr("This drive was encrypted using the version of BitLocker Drive Encryption included with Windows Vista and Windows Server 2008 which does not support organizational identifiers. To specify organizational identifiers for this drive upgrade the drive encryption to the latest version using the 'manage-bde -upgrade' command.")}
  DOM {080310097h, $OfsTStr("The drive cannot be locked because it is automatically unlocked on this computer. Remove the automatic unlock protector to lock this drive.")}
  DOM {080310098h, $OfsTStr("The default Bitlocker Key Derivation Function SP800-56A for ECC smart cards is not supported by your smart card. The Group Policy setting requiring FIPS-compliance prevents BitLocker from using any other key derivation function for encryption. You have to use a FIPS compliant smart card in FIPS restricted environments.")}
  DOM {080310099h, $OfsTStr("The BitLocker encryption key could not be obtained from the Trusted Platform Module (TPM) and enhanced PIN. Try using a PIN containing only numerals.")}
  DOM {08031009Ah, $OfsTStr("The requested TPM PIN contains invalid characters.")}
  DOM {08031009Bh, $OfsTStr("The management information stored on the drive contained an unknown type. If you are using an old version of Windows")}
  DOM {08031009Ch, $OfsTStr("The feature is only supported on EFI systems.")}
  DOM {08031009Dh, $OfsTStr("More than one Network Key Protector certificate has been found on the system.")}
  DOM {08031009Eh, $OfsTStr("Removal of the Network Key Protector certificate must be done using the Certificates snap-in.")}
  DOM {08031009Fh, $OfsTStr("An invalid certificate has been found in the Network Key Protector certificate store.")}
  DOM {0803100A0h, $OfsTStr("This drive isn't protected with a PIN.")}
  DOM {0803100A1h, $OfsTStr("Please enter the correct current PIN.")}
  DOM {0803100A2h, $OfsTStr("You must be logged on with an administrator account to change the PIN or password. Click the link to reset the PIN or password as an administrator.")}
  DOM {0803100A3h, $OfsTStr("BitLocker has disabled PIN and password changes after too many failed requests. Click the link to reset the PIN or password as an administrator.")}
  DOM {0803100A4h, $OfsTStr("Your system administrator requires that passwords contain only printable ASCII characters. This includes unaccented letters (A-Z")}
  DOM {0803100A5h, $OfsTStr("BitLocker Drive Encryption only supports used space only encryption on thin provisioned storage.")}
  DOM {0803100A6h, $OfsTStr("BitLocker Drive Encryption does not support wiping free space on thin provisioned storage.")}
  DOM {0803100A7h, $OfsTStr("The required authentication key length is not supported by the drive.")}
  DOM {0803100A8h, $OfsTStr("This drive isn't protected with a password.")}
  DOM {0803100A9h, $OfsTStr("Please enter the correct current password.")}
  DOM {0803100AAh, $OfsTStr("The password cannot exceed 256 characters.")}
  DOM {0803100ABh, $OfsTStr("A password key protector cannot be added because a TPM protector exists on the drive.")}
  DOM {0803100ACh, $OfsTStr("A TPM key protector cannot be added because a password protector exists on the drive.")}
  DOM {0803100ADh, $OfsTStr("This command can only be performed from the coordinator node for the specified CSV volume.")}
  DOM {0803100AEh, $OfsTStr("This command cannot be performed on a volume when it is part of a cluster.")}
  DOM {0803100AFh, $OfsTStr("BitLocker did not revert to using BitLocker software encryption due to group policy configuration.")}
  DOM {0803100B0h, $OfsTStr("The drive cannot be managed by BitLocker because the drive's hardware encryption feature is already in use.")}
  DOM {0803100B1h, $OfsTStr("Group Policy settings do not allow the use of hardware-based encryption.")}
  DOM {0803100B2h, $OfsTStr("The drive specified does not support hardware-based encryption.")}
  DOM {0803100B3h, $OfsTStr("BitLocker cannot be upgraded during disk encryption or decryption.")}
  DOM {0803100B4h, $OfsTStr("Discovery Volumes are not supported for volumes using hardware encryption.")}
  DOM {0803100B5h, $OfsTStr("No pre-boot keyboard detected. The user may not be able to provide required input to unlock the volume.")}
  DOM {0803100B6h, $OfsTStr("No pre-boot keyboard or Windows Recovery Environment detected. The user may not be able to provide required input to unlock the volume.")}
  DOM {0803100B7h, $OfsTStr("Group Policy settings require the creation of a startup PIN")}
  DOM {0803100B8h, $OfsTStr("Group Policy settings require the creation of a recovery password")}
  DOM {0803100B9h, $OfsTStr("Wipe of free space is not currently taking place.")}
  DOM {0803100BAh, $OfsTStr("BitLocker cannot use Secure Boot for platform integrity because Secure Boot has been disabled.")}
  DOM {0803100BBh, $OfsTStr("BitLocker cannot use Secure Boot for platform integrity because the Secure Boot configuration does not meet the requirements for BitLocker.")}
  DOM {0803100BCh, $OfsTStr("Your computer doesn't support BitLocker hardware-based encryption. Check with your computer manufacturer for firmware updates.")}
  DOM {0803100BDh, $OfsTStr("BitLocker cannot be enabled on the volume because it contains a Volume Shadow Copy. Remove all Volume Shadow Copies before encrypting the volume.")}
  DOM {0803100BEh, $OfsTStr("BitLocker Drive Encryption cannot be applied to this drive because the Group Policy setting for Enhanced Boot Configuration Data contains invalid data. Please have your system administrator resolve this invalid configuration before attempting to enable BitLocker.")}
  DOM {0803100BFh, $OfsTStr("This PC's firmware is not capable of supporting hardware encryption.")}
  DOM {0803100C0h, $OfsTStr("BitLocker has disabled password changes after too many failed requests. Click the link to reset the password as an administrator.")}
  DOM {0803100C1h, $OfsTStr("You must be logged on with an administrator account to change the password. Click the link to reset the password as an administrator.")}
  DOM {0803100C2h, $OfsTStr("BitLocker cannot save the recovery password because the specified Microsoft account is Suspended.")}
  DOM {0803100C3h, $OfsTStr("BitLocker cannot save the recovery password because the specified MIcrosoft account is Blocked.")}
  DOM {0803100C4h, $OfsTStr("This PC is not provisioned to support device encryption. Please enable BitLocker on all volumes to comply with device encryption policy.")}
  DOM {0803100C5h, $OfsTStr("This PC cannot support device encryption because unencrypted fixed data volumes are present.")}
  DOM {0803100C6h, $OfsTStr("This PC does not meet the hardware requirements to support device encryption.")}
  DOM {0803100C7h, $OfsTStr("This PC cannot support device encryption because WinRE is not properly configured.")}
  DOM {0803100C8h, $OfsTStr("Protection is enabled on the volume but has been suspended. This is likely to have happened due to an update being applied to your system. Please try again after a reboot.")}
  DOM {0803100C9h, $OfsTStr("This PC is not provisioned to support device encryption.")}
  DOM {0803100CAh, $OfsTStr("Device Lock has been triggered due to too many incorrect password attempts.")}
  DOM {0803100CBh, $OfsTStr("Protection has not been enabled on the volume. Enabling protection requires a connected account. If you already have a connected account and are seeing this error")}
  DOM {0803100CCh, $OfsTStr("Your PIN can only contain numbers from 0 to 9.")}
  DOM {0803100CDh, $OfsTStr("BitLocker cannot use hardware replay protection because no counter is available on your PC.")}
  DOM {0803100CEh, $OfsTStr("Device Lockout state validation failed due to counter mismatch.")}
  DOM {0803100CFh, $OfsTStr("The input buffer is too large.")}
  DOM {080320001h, $OfsTStr("The callout does not exist.")}
  DOM {080320002h, $OfsTStr("The filter condition does not exist.")}
  DOM {080320003h, $OfsTStr("The filter does not exist.")}
  DOM {080320004h, $OfsTStr("The layer does not exist.")}
  DOM {080320005h, $OfsTStr("The provider does not exist.")}
  DOM {080320006h, $OfsTStr("The provider context does not exist.")}
  DOM {080320007h, $OfsTStr("The sublayer does not exist.")}
  DOM {080320008h, $OfsTStr("The object does not exist.")}
  DOM {080320009h, $OfsTStr("An object with that GUID or LUID already exists.")}
  DOM {08032000Ah, $OfsTStr("The object is referenced by other objects so cannot be deleted.")}
  DOM {08032000Bh, $OfsTStr("The call is not allowed from within a dynamic session.")}
  DOM {08032000Ch, $OfsTStr("The call was made from the wrong session so cannot be completed.")}
  DOM {08032000Dh, $OfsTStr("The call must be made from within an explicit transaction.")}
  DOM {08032000Eh, $OfsTStr("The call is not allowed from within an explicit transaction.")}
  DOM {08032000Fh, $OfsTStr("The explicit transaction has been forcibly canceled.")}
  DOM {080320010h, $OfsTStr("The session has been canceled.")}
  DOM {080320011h, $OfsTStr("The call is not allowed from within a read-only transaction.")}
  DOM {080320012h, $OfsTStr("The call timed out while waiting to acquire the transaction lock.")}
  DOM {080320013h, $OfsTStr("Collection of network diagnostic events is disabled.")}
  DOM {080320014h, $OfsTStr("The operation is not supported by the specified layer.")}
  DOM {080320015h, $OfsTStr("The call is allowed for kernel-mode callers only.")}
  DOM {080320016h, $OfsTStr("The call tried to associate two objects with incompatible lifetimes.")}
  DOM {080320017h, $OfsTStr("The object is built in so cannot be deleted.")}
  DOM {080320018h, $OfsTStr("The maximum number of callouts has been reached.")}
  DOM {080320019h, $OfsTStr("A notification could not be delivered because a message queue is at its maximum capacity.")}
  DOM {08032001Ah, $OfsTStr("The traffic parameters do not match those for the security association context.")}
  DOM {08032001Bh, $OfsTStr("The call is not allowed for the current security association state.")}
  DOM {08032001Ch, $OfsTStr("A required pointer is null.")}
  DOM {08032001Dh, $OfsTStr("An enumerator is not valid.")}
  DOM {08032001Eh, $OfsTStr("The flags field contains an invalid value.")}
  DOM {08032001Fh, $OfsTStr("A network mask is not valid.")}
  DOM {080320020h, $OfsTStr("An FWP_RANGE is not valid.")}
  DOM {080320021h, $OfsTStr("The time interval is not valid.")}
  DOM {080320022h, $OfsTStr("An array that must contain at least one element is zero length.")}
  DOM {080320023h, $OfsTStr("The displayData.name field cannot be null.")}
  DOM {080320024h, $OfsTStr("The action type is not one of the allowed action types for a filter.")}
  DOM {080320025h, $OfsTStr("The filter weight is not valid.")}
  DOM {080320026h, $OfsTStr("A filter condition contains a match type that is not compatible with the operands.")}
  DOM {080320027h, $OfsTStr("An FWP_VALUE or FWPM_CONDITION_VALUE is of the wrong type.")}
  DOM {080320028h, $OfsTStr("An integer value is outside the allowed range.")}
  DOM {080320029h, $OfsTStr("A reserved field is nonzero.")}
  DOM {08032002Ah, $OfsTStr("A filter cannot contain multiple conditions operating on a single field.")}
  DOM {08032002Bh, $OfsTStr("A policy cannot contain the same keying module more than once.")}
  DOM {08032002Ch, $OfsTStr("The action type is not compatible with the layer.")}
  DOM {08032002Dh, $OfsTStr("The action type is not compatible with the sublayer.")}
  DOM {08032002Eh, $OfsTStr("The raw context or the provider context is not compatible with the layer.")}
  DOM {08032002Fh, $OfsTStr("The raw context or the provider context is not compatible with the callout.")}
  DOM {080320030h, $OfsTStr("The authentication method is not compatible with the policy type.")}
  DOM {080320031h, $OfsTStr("The Diffie-Hellman group is not compatible with the policy type.")}
  DOM {080320032h, $OfsTStr("An IKE policy cannot contain an Extended Mode policy.")}
  DOM {080320033h, $OfsTStr("The enumeration template or subscription will never match any objects.")}
  DOM {080320034h, $OfsTStr("The provider context is of the wrong type.")}
  DOM {080320035h, $OfsTStr("The parameter is incorrect.")}
  DOM {080320036h, $OfsTStr("The maximum number of sublayers has been reached.")}
  DOM {080320037h, $OfsTStr("The notification function for a callout returned an error.")}
  DOM {080320038h, $OfsTStr("The IPsec authentication transform is not valid.")}
  DOM {080320039h, $OfsTStr("The IPsec cipher transform is not valid.")}
  DOM {08032003Ah, $OfsTStr("The IPsec cipher transform is not compatible with the policy.")}
  DOM {08032003Bh, $OfsTStr("The combination of IPsec transform types is not valid.")}
  DOM {08032003Ch, $OfsTStr("A policy cannot contain the same auth method more than once.")}
  DOM {08032003Dh, $OfsTStr("A tunnel endpoint configuration is invalid.")}
  DOM {08032003Eh, $OfsTStr("The WFP MAC Layers are not ready.")}
  DOM {08032003Fh, $OfsTStr("A key manager capable of key dictation is already registered")}
  DOM {080320040h, $OfsTStr("A key manager dictated invalid keys")}
  DOM {080320041h, $OfsTStr("The BFE IPsec Connection Tracking is disabled.")}
  DOM {080320042h, $OfsTStr("The DNS name is invalid.")}
  DOM {080320043h, $OfsTStr("The engine option is still enabled due to other configuration settings.")}
  DOM {080320044h, $OfsTStr("The IKEEXT service is not running. This service only runs when there is IPsec policy applied to the machine.")}
  DOM {080320104h, $OfsTStr("The packet should be dropped")}
  DOM {080340002h, $OfsTStr("The binding to the network interface is being closed.")}
  DOM {080340004h, $OfsTStr("An invalid version was specified.")}
  DOM {080340005h, $OfsTStr("An invalid characteristics table was used.")}
  DOM {080340006h, $OfsTStr("Failed to find the network interface or network interface is not ready.")}
  DOM {080340007h, $OfsTStr("Failed to open the network interface.")}
  DOM {080340008h, $OfsTStr("Network interface has encountered an internal unrecoverable failure.")}
  DOM {080340009h, $OfsTStr("The multicast list on the network interface is full.")}
  DOM {08034000Ah, $OfsTStr("An attempt was made to add a duplicate multicast address to the list.")}
  DOM {08034000Bh, $OfsTStr("At attempt was made to remove a multicast address that was never added.")}
  DOM {08034000Ch, $OfsTStr("Netowork interface aborted the request.")}
  DOM {08034000Dh, $OfsTStr("Network interface cannot process the request because it is being reset.")}
  DOM {08034000Fh, $OfsTStr("An attempt was made to send an invalid packet on a network interface.")}
  DOM {080340010h, $OfsTStr("The specified request is not a valid operation for the target device.")}
  DOM {080340011h, $OfsTStr("Network interface is not ready to complete this operation.")}
  DOM {080340014h, $OfsTStr("The length of the buffer submitted for this operation is not valid.")}
  DOM {080340015h, $OfsTStr("The data used for this operation is not valid.")}
  DOM {080340016h, $OfsTStr("The length of buffer submitted for this operation is too small.")}
  DOM {080340017h, $OfsTStr("Network interface does not support this OID (Object Identifier)")}
  DOM {080340018h, $OfsTStr("The network interface has been removed.")}
  DOM {080340019h, $OfsTStr("Network interface does not support this media type.")}
  DOM {08034001Ah, $OfsTStr("An attempt was made to remove a token ring group address that is in use by other components.")}
  DOM {08034001Bh, $OfsTStr("An attempt was made to map a file that cannot be found.")}
  DOM {08034001Ch, $OfsTStr("An error occurred while NDIS tried to map the file.")}
  DOM {08034001Dh, $OfsTStr("An attempt was made to map a file that is alreay mapped.")}
  DOM {08034001Eh, $OfsTStr("An attempt to allocate a hardware resource failed because the resource is used by another component.")}
  DOM {08034001Fh, $OfsTStr("The I/O operation failed because network media is disconnected or wireless access point is out of range.")}
  DOM {080340022h, $OfsTStr("The network address used in the request is invalid.")}
  DOM {08034002Ah, $OfsTStr("The offload operation on the network interface has been paused.")}
  DOM {08034002Bh, $OfsTStr("Network interface was not found.")}
  DOM {08034002Ch, $OfsTStr("The revision number specified in the structure is not supported.")}
  DOM {08034002Dh, $OfsTStr("The specified port does not exist on this network interface.")}
  DOM {08034002Eh, $OfsTStr("The current state of the specified port on this network interface does not support the requested operation.")}
  DOM {08034002Fh, $OfsTStr("The miniport adapter is in low power state.")}
  DOM {080340030h, $OfsTStr("This operation requires the miniport adapter to be reinitialized.")}
  DOM {0803400BBh, $OfsTStr("Netword interface does not support this request.")}
  DOM {080342000h, $OfsTStr("The wireless local area network interface is in auto configuration mode and doesn't support the requested parameter change operation.")}
  DOM {080342001h, $OfsTStr("The wireless local area network interface is busy and cannot perform the requested operation.")}
  DOM {080342002h, $OfsTStr("The wireless local area network interface is powered down and doesn't support the requested operation.")}
  DOM {080342003h, $OfsTStr("The list of wake on LAN patterns is full.")}
  DOM {080342004h, $OfsTStr("The list of low power protocol offloads is full.")}
  DOM {080370001h, $OfsTStr("A virtual machine is running with its memory allocated across multiple NUMA nodes. This does not indicate a problem unless the performance of your virtual machine is unusually slow. If you are experiencing performance problems")}
  DOM {080380001h, $OfsTStr("The regeneration operation was not able to copy all data from the active plexes due to bad sectors.")}
  DOM {080380002h, $OfsTStr("One or more disks were not fully migrated to the target pack. They may or may not require reimport after fixing the hardware problems.")}
  DOM {080390001h, $OfsTStr("Some BCD entries were not imported correctly from the BCD store.")}
  DOM {080390003h, $OfsTStr("Some BCD entries were not synchronized correctly with the firmware.")}
  DOM {0803A0001h, $OfsTStr("The virtualization storage subsystem has generated an error.")}
  DOM {0803C0100h, $OfsTStr("The operation was canceled.")}
  DOM {0803C0101h, $OfsTStr("An error occurred when running a PowerShell script.")}
  DOM {0803C0102h, $OfsTStr("An error occurred when interacting with PowerShell runtime.")}
  DOM {0803C0103h, $OfsTStr("An error occurred in the Scripted Diagnostic Managed Host.")}
  DOM {0803C0104h, $OfsTStr("The troubleshooting pack does not contain a required verifier to complete the verification.")}
  DOM {0803C0106h, $OfsTStr("Scripted diagnostics is disabled by group policy.")}
  DOM {0803C0107h, $OfsTStr("Trust validation of the diagnostic package failed.")}
  DOM {0803C0108h, $OfsTStr("The troubleshooting pack cannot be executed on this system.")}
  DOM {0803C0109h, $OfsTStr("This version of the troubleshooting pack is not supported.")}
  DOM {0803C010Ah, $OfsTStr("A required resource cannot be loaded.")}
  DOM {0803C010Bh, $OfsTStr("The troubleshooting pack reported information for a root cause without adding the root cause.")}
  DOM {0803D0000h, $OfsTStr("The input data was not in the expected format or did not have the expected value.")}
  DOM {0803D0001h, $OfsTStr("The operation could not be completed because the object is in a faulted state due to a previous error.")}
  DOM {0803D0002h, $OfsTStr("The operation could not be completed because it would lead to numeric overflow.")}
  DOM {0803D0003h, $OfsTStr("The operation is not allowed due to the current state of the object.")}
  DOM {0803D0004h, $OfsTStr("The operation was aborted.")}
  DOM {0803D0005h, $OfsTStr("Access was denied by the remote endpoint.")}
  DOM {0803D0006h, $OfsTStr("The operation did not complete within the time allotted.")}
  DOM {0803D0007h, $OfsTStr("The operation was abandoned.")}
  DOM {0803D0008h, $OfsTStr("A quota was exceeded.")}
  DOM {0803D0009h, $OfsTStr("The information was not available in the specified language.")}
  DOM {0803D000Ah, $OfsTStr("Security verification was not successful for the received data.")}
  DOM {0803D000Bh, $OfsTStr("The address is already being used.")}
  DOM {0803D000Ch, $OfsTStr("The address is not valid for this context.")}
  DOM {0803D000Dh, $OfsTStr("The remote endpoint does not exist or could not be located.")}
  DOM {0803D000Eh, $OfsTStr("The remote endpoint is not currently in service at this location.")}
  DOM {0803D000Fh, $OfsTStr("The remote endpoint could not process the request.")}
  DOM {0803D0010h, $OfsTStr("The remote endpoint was not reachable.")}
  DOM {0803D0011h, $OfsTStr("The operation was not supported by the remote endpoint.")}
  DOM {0803D0012h, $OfsTStr("The remote endpoint is unable to process the request due to being overloaded.")}
  DOM {0803D0013h, $OfsTStr("A message containing a fault was received from the remote endpoint.")}
  DOM {0803D0014h, $OfsTStr("The connection with the remote endpoint was terminated.")}
  DOM {0803D0015h, $OfsTStr("The HTTP proxy server could not process the request.")}
  DOM {0803D0016h, $OfsTStr("Access was denied by the HTTP proxy server.")}
  DOM {0803D0017h, $OfsTStr("The requested feature is not available on this platform.")}
  DOM {0803D0018h, $OfsTStr("The HTTP proxy server requires HTTP authentication scheme 'basic'.")}
  DOM {0803D0019h, $OfsTStr("The HTTP proxy server requires HTTP authentication scheme 'digest'.")}
  DOM {0803D001Ah, $OfsTStr("The HTTP proxy server requires HTTP authentication scheme 'NTLM'.")}
  DOM {0803D001Bh, $OfsTStr("The HTTP proxy server requires HTTP authentication scheme 'negotiate'.")}
  DOM {0803D001Ch, $OfsTStr("The remote endpoint requires HTTP authentication scheme 'basic'.")}
  DOM {0803D001Dh, $OfsTStr("The remote endpoint requires HTTP authentication scheme 'digest'.")}
  DOM {0803D001Eh, $OfsTStr("The remote endpoint requires HTTP authentication scheme 'NTLM'.")}
  DOM {0803D001Fh, $OfsTStr("The remote endpoint requires HTTP authentication scheme 'negotiate'.")}
  DOM {0803D0020h, $OfsTStr("The endpoint address URL is invalid.")}
  DOM {0803D0021h, $OfsTStr("Unrecognized error occurred in the Windows Web Services framework.")}
  DOM {0803D0022h, $OfsTStr("A security token was rejected by the server because it has expired.")}
  DOM {0803D0023h, $OfsTStr("A security operation failed in the Windows Web Services framework.")}
  DOM {0803E0100h, $OfsTStr("The notification channel has already been closed.")}
  DOM {0803E0101h, $OfsTStr("The notification channel request did not complete successfully.")}
  DOM {0803E0102h, $OfsTStr("The application identifier provided is invalid.")}
  DOM {0803E0103h, $OfsTStr("A notification channel request for the provided application identifier is in progress.")}
  DOM {0803E0104h, $OfsTStr("The channel identifier is already tied to another application endpoint.")}
  DOM {0803E0105h, $OfsTStr("The notification platform is unavailable.")}
  DOM {0803E0106h, $OfsTStr("The notification has already been posted.")}
  DOM {0803E0107h, $OfsTStr("The notification has already been hidden.")}
  DOM {0803E0108h, $OfsTStr("The notification cannot be hidden until it has been shown.")}
  DOM {0803E0109h, $OfsTStr("Cloud notifications have been turned off.")}
  DOM {0803E0110h, $OfsTStr("The application does not have the cloud notification capability.")}
  DOM {0803E0111h, $OfsTStr("Settings prevent the notification from being delivered.")}
  DOM {0803E0112h, $OfsTStr("Application capabilities prevent the notification from being delivered.")}
  DOM {0803E0113h, $OfsTStr("The application does not have the internet access capability.")}
  DOM {0803E0114h, $OfsTStr("Settings prevent the notification type from being delivered.")}
  DOM {0803E0115h, $OfsTStr("The size of the notification content is too large.")}
  DOM {0803E0116h, $OfsTStr("The size of the notification tag is too large.")}
  DOM {0803E0117h, $OfsTStr("The notification platform doesn't have appropriate privilege on resources.")}
  DOM {0803E0118h, $OfsTStr("The notification platform found application is already registered.")}
  DOM {0803E0200h, $OfsTStr("The notification platform has run out of presentation layer sessions.")}
  DOM {0803E0201h, $OfsTStr("The notification platform rejects image download request due to system in power save mode.")}
  DOM {0803E0202h, $OfsTStr("The notification platform doesn't have the requested image in its cache.")}
  DOM {0803E0203h, $OfsTStr("The notification platform cannot complete all of requested image.")}
  DOM {0803E0204h, $OfsTStr("A cloud image downloaded from the notification platform is invalid.")}
  DOM {0803E0205h, $OfsTStr("Notification Id provided as filter is matched with what the notification platform maintains.")}
  DOM {0803E0206h, $OfsTStr("Notification callback interface is already registered.")}
  DOM {0803E0207h, $OfsTStr("Toast Notification was dropped without being displayed to the user.")}
  DOM {0803E0208h, $OfsTStr("The notification platform does not have the proper privileges to complete the request.")}
  DOM {080548201h, $OfsTStr("Context is not activated.")}
  DOM {080548202h, $OfsTStr("Bad SIM is inserted.")}
  DOM {080548203h, $OfsTStr("Requested data class is not available.")}
  DOM {080548204h, $OfsTStr("Access point name (APN) or Access string is incorrect.")}
  DOM {080548205h, $OfsTStr("Max activated contexts have reached.")}
  DOM {080548206h, $OfsTStr("Device is in packet detach state.")}
  DOM {080548207h, $OfsTStr("Provider is not visible.")}
  DOM {080548208h, $OfsTStr("Radio is powered off.")}
  DOM {080548209h, $OfsTStr("MBN subscription is not activated.")}
  DOM {08054820Ah, $OfsTStr("SIM is not inserted.")}
  DOM {08054820Bh, $OfsTStr("Voice call in progress.")}
  DOM {08054820Ch, $OfsTStr("Visible provider cache is invalid.")}
  DOM {08054820Dh, $OfsTStr("Device is not registered.")}
  DOM {08054820Eh, $OfsTStr("Providers not found.")}
  DOM {08054820Fh, $OfsTStr("Pin is not supported.")}
  DOM {080548210h, $OfsTStr("Pin is required.")}
  DOM {080548211h, $OfsTStr("PIN is disabled.")}
  DOM {080548212h, $OfsTStr("Generic Failure.")}
  DOM {080548218h, $OfsTStr("Profile is invalid.")}
  DOM {080548219h, $OfsTStr("Default profile exist.")}
  DOM {080548220h, $OfsTStr("SMS encoding is not supported.")}
  DOM {080548221h, $OfsTStr("SMS filter is not supported.")}
  DOM {080548222h, $OfsTStr("Invalid SMS memory index is used.")}
  DOM {080548223h, $OfsTStr("SMS language is not supported.")}
  DOM {080548224h, $OfsTStr("SMS memory failure occurred.")}
  DOM {080548225h, $OfsTStr("SMS network timeout happened.")}
  DOM {080548226h, $OfsTStr("Unknown SMSC address is used.")}
  DOM {080548227h, $OfsTStr("SMS format is not supported.")}
  DOM {080548228h, $OfsTStr("SMS operation is not allowed.")}
  DOM {080548229h, $OfsTStr("Device SMS memory is full.")}
  DOM {080630001h, $OfsTStr("The IPv6 protocol is not installed.")}
  DOM {080630002h, $OfsTStr("The component has not been initialized.")}
  DOM {080630003h, $OfsTStr("The required service canot be started.")}
  DOM {080630004h, $OfsTStr("The P2P protocol is not licensed to run on this OS.")}
  DOM {080630010h, $OfsTStr("The graph handle is invalid.")}
  DOM {080630011h, $OfsTStr("The GRaphing database name has changed.")}
  DOM {080630012h, $OfsTStr("A graph with the same ID already exists.")}
  DOM {080630013h, $OfsTStr("The graph is not ready.")}
  DOM {080630014h, $OfsTStr("The graph is shutting down.")}
  DOM {080630015h, $OfsTStr("The graph is still in use.")}
  DOM {080630016h, $OfsTStr("The graph database is corrupt.")}
  DOM {080630017h, $OfsTStr("Too many attributes have been used.")}
  DOM {080630103h, $OfsTStr("The connection can not be found.")}
  DOM {080630106h, $OfsTStr("The peer attempted to connect to itself.")}
  DOM {080630107h, $OfsTStr("The peer is already listening for connections.")}
  DOM {080630108h, $OfsTStr("The node was not found.")}
  DOM {080630109h, $OfsTStr("The Connection attempt failed.")}
  DOM {08063010Ah, $OfsTStr("The peer connection could not be authenticated.")}
  DOM {08063010Bh, $OfsTStr("The connection was refused.")}
  DOM {080630201h, $OfsTStr("The peer name classifier is too long.")}
  DOM {080630202h, $OfsTStr("The maximum number of identies have been created.")}
  DOM {080630203h, $OfsTStr("Unable to access a key.")}
  DOM {080630204h, $OfsTStr("The group already exists.")}
  DOM {080630301h, $OfsTStr("The requested record could not be found.")}
  DOM {080630302h, $OfsTStr("Access to the database was denied.")}
  DOM {080630303h, $OfsTStr("The Database could not be initialized.")}
  DOM {080630304h, $OfsTStr("The record is too big.")}
  DOM {080630305h, $OfsTStr("The database already exists.")}
  DOM {080630306h, $OfsTStr("The database could not be found.")}
  DOM {080630401h, $OfsTStr("The identity could not be found.")}
  DOM {080630501h, $OfsTStr("The event handle could not be found.")}
  DOM {080630601h, $OfsTStr("Invalid search.")}
  DOM {080630602h, $OfsTStr("The search attributes are invalid.")}
  DOM {080630701h, $OfsTStr("The invitiation is not trusted.")}
  DOM {080630703h, $OfsTStr("The certchain is too long.")}
  DOM {080630705h, $OfsTStr("The time period is invalid.")}
  DOM {080630706h, $OfsTStr("A circular cert chain was detected.")}
  DOM {080630801h, $OfsTStr("The certstore is corrupted.")}
  DOM {080631001h, $OfsTStr("The specified PNRP cloud deos not exist.")}
  DOM {080631005h, $OfsTStr("The cloud name is ambiguous.")}
  DOM {080632010h, $OfsTStr("The record is invlaid.")}
  DOM {080632020h, $OfsTStr("Not authorized.")}
  DOM {080632021h, $OfsTStr("The password does not meet policy requirements.")}
  DOM {080632030h, $OfsTStr("The record validation has been defered.")}
  DOM {080632040h, $OfsTStr("The group properies are invalid.")}
  DOM {080632050h, $OfsTStr("The peername is invalid.")}
  DOM {080632060h, $OfsTStr("The classifier is invalid.")}
  DOM {080632070h, $OfsTStr("The friendly name is invalid.")}
  DOM {080632071h, $OfsTStr("Invalid role property.")}
  DOM {080632072h, $OfsTStr("Invalid classifier protopery.")}
  DOM {080632080h, $OfsTStr("Invlaid record expiration.")}
  DOM {080632081h, $OfsTStr("Invlaid credential info.")}
  DOM {080632082h, $OfsTStr("Invalid credential.")}
  DOM {080632083h, $OfsTStr("Invalid record size.")}
  DOM {080632090h, $OfsTStr("Unsupported version.")}
  DOM {080632091h, $OfsTStr("The group is not ready.")}
  DOM {080632092h, $OfsTStr("The group is still in use.")}
  DOM {080632093h, $OfsTStr("The group is invalid.")}
  DOM {080632094h, $OfsTStr("No members were found.")}
  DOM {080632095h, $OfsTStr("There are no member connections.")}
  DOM {080632096h, $OfsTStr("Unable to listen.")}
  DOM {0806320A0h, $OfsTStr("The identity does not exist.")}
  DOM {0806320A1h, $OfsTStr("The service is not availible.")}
  DOM {080634001h, $OfsTStr("The peername could not be converted to a DNS pnrp name.")}
  DOM {080634002h, $OfsTStr("Invalid peer host name.")}
  DOM {080634003h, $OfsTStr("No more data could be found.")}
  DOM {080634005h, $OfsTStr("The existing peer name is already registered.")}
  DOM {080636001h, $OfsTStr("The contact could not be found.")}
  DOM {080637000h, $OfsTStr("The app invite request was canceld by the user.")}
  DOM {080637001h, $OfsTStr("No response to the invite was received.")}
  DOM {080637003h, $OfsTStr("User is not siged into serverless presence.")}
  DOM {080637004h, $OfsTStr("The user declinded the privacy policy prompt.")}
  DOM {080637005h, $OfsTStr("A timeout occured.")}
  DOM {080637007h, $OfsTStr("The address is invalid.")}
  DOM {080637008h, $OfsTStr("A required firewall exception is disabled.")}
  DOM {080637009h, $OfsTStr("The service is block by a firewall policy.")}
  DOM {08063700Ah, $OfsTStr("Firewall exceptions are disabled.")}
  DOM {08063700Bh, $OfsTStr("The user declinded to enable the firewall exceptions.")}
  DOM {080650001h, $OfsTStr("The attribute handle given was not valid on this server.")}
  DOM {080650002h, $OfsTStr("The attribute cannot be read.")}
  DOM {080650003h, $OfsTStr("The attribute cannot be written.")}
  DOM {080650004h, $OfsTStr("The attribute PDU was invalid.")}
  DOM {080650005h, $OfsTStr("The attribute requires authentication before it can be read or written.")}
  DOM {080650006h, $OfsTStr("Attribute server does not support the request received from the client.")}
  DOM {080650007h, $OfsTStr("Offset specified was past the end of the attribute.")}
  DOM {080650008h, $OfsTStr("The attribute requires authorization before it can be read or written.")}
  DOM {080650009h, $OfsTStr("Too many prepare writes have been queued.")}
  DOM {08065000Ah, $OfsTStr("No attribute found within the given attribute handle range.")}
  DOM {08065000Bh, $OfsTStr("The attribute cannot be read or written using the Read Blob Request.")}
  DOM {08065000Ch, $OfsTStr("The Encryption Key Size used for encrypting this link is insufficient.")}
  DOM {08065000Dh, $OfsTStr("The attribute value length is invalid for the operation.")}
  DOM {08065000Eh, $OfsTStr("The attribute request that was requested has encountered an error that was unlikely")}
  DOM {08065000Fh, $OfsTStr("The attribute requires encryption before it can be read or written.")}
  DOM {080650010h, $OfsTStr("The attribute type is not a supported grouping attribute as defined by a higher layer specification.")}
  DOM {080650011h, $OfsTStr("Insufficient Resources to complete the request.")}
  DOM {080651000h, $OfsTStr("An error that lies in the reserved range has been received.")}
  DOM {080660001h, $OfsTStr("PortCls could not find an audio engine node exposed by a miniport driver claiming support for IMiniportAudioEngineNode.")}
  DOM {088790001h, $OfsTStr("The application has exceeded the maximum number of unique state objects per Direct3D device. The limit is 4096 for feature levels up to 11.1.")}
  DOM {088790002h, $OfsTStr("The specified file was not found.")}
  DOM {0887A0001h, $OfsTStr("The application made a call that is invalid. Either the parameters of the call or the state of some object was incorrect. Enable the D3D debug layer in order to see details via debug messages.")}
  DOM {0887A0002h, $OfsTStr("The object was not found. If calling IDXGIFactory::EnumAdaptes")}
  DOM {0887A0003h, $OfsTStr("The caller did not supply a sufficiently large buffer.")}
  DOM {0887A0004h, $OfsTStr("The specified device interface or feature level is not supported on this system.")}
  DOM {0887A0005h, $OfsTStr("The GPU device instance has been suspended. Use GetDeviceRemovedReason to determine the appropriate action.")}
  DOM {0887A0006h, $OfsTStr("The GPU will not respond to more commands")}
  DOM {0887A0007h, $OfsTStr("The GPU will not respond to more commands")}
  DOM {0887A000Ah, $OfsTStr("The GPU was busy at the moment when the call was made")}
  DOM {0887A000Bh, $OfsTStr("An event (such as power cycle) interrupted the gathering of presentation statistics. Any previous statistics should be considered invalid.")}
  DOM {0887A000Ch, $OfsTStr("Fullscreen mode could not be achieved because the specified output was already in use.")}
  DOM {0887A0020h, $OfsTStr("An internal issue prevented the driver from carrying out the specified operation. The driver's state is probably suspect")}
  DOM {0887A0021h, $OfsTStr("A global counter resource was in use")}
  DOM {0887A0022h, $OfsTStr("A resource is not available at the time of the call")}
  DOM {0887A0023h, $OfsTStr("The application's remote device has been removed due to session disconnect or network disconnect. The application should call IDXGIFactory1::IsCurrent to find out when the remote device becomes available again.")}
  DOM {0887A0024h, $OfsTStr("The device has been removed during a remote session because the remote computer ran out of memory.")}
  DOM {0887A0025h, $OfsTStr("An on-going mode change prevented completion of the call. The call may succeed if attempted later.")}
  DOM {0887A0026h, $OfsTStr("The keyed mutex was abandoned.")}
  DOM {0887A0027h, $OfsTStr("The timeout value has elapsed and the resource is not yet available.")}
  DOM {0887A0028h, $OfsTStr("The output duplication has been turned off because the Windows session ended or was disconnected. This happens when a remote user disconnects")}
  DOM {0887A0029h, $OfsTStr("The DXGI outuput (monitor) to which the swapchain content was restricted")}
  DOM {0887A002Ah, $OfsTStr("DXGI is unable to provide content protection on the swapchain. This is typically caused by an older driver")}
  DOM {0887A002Bh, $OfsTStr("The application is trying to use a resource to which it does not have the required access privileges. This is most commonly caused by writing to a shared resource with read-only access.")}
  DOM {0887B0001h, $OfsTStr("The GPU was busy when the operation was requested.")}
  DOM {0887B0002h, $OfsTStr("The driver has rejected the creation of this resource.")}
  DOM {0887B0003h, $OfsTStr("The GPU counter was in use by another process or d3d device when application requested access to it.")}
  DOM {0887C0001h, $OfsTStr("The application has exceeded the maximum number of unique state objects per Direct3D device. The limit is 4096 for feature levels up to 11.1.")}
  DOM {0887C0002h, $OfsTStr("The specified file was not found.")}
  DOM {0887C0003h, $OfsTStr("The application has exceeded the maximum number of unique view objects per Direct3D device. The limit is 2^20 for feature levels up to 11.1.")}
  DOM {0887C0004h, $OfsTStr("The application's first call per command list to Map on a deferred context did not use D3D11_MAP_WRITE_DISCARD.")}
  DOM {088982F04h, $OfsTStr("The codec is in the wrong state.")}
  DOM {088982F05h, $OfsTStr("The value is out of range.")}
  DOM {088982F07h, $OfsTStr("The image format is unknown.")}
  DOM {088982F0Bh, $OfsTStr("The SDK version is unsupported.")}
  DOM {088982F0Ch, $OfsTStr("The component is not initialized.")}
  DOM {088982F0Dh, $OfsTStr("There is already an outstanding read or write lock.")}
  DOM {088982F40h, $OfsTStr("The specified bitmap property cannot be found.")}
  DOM {088982F41h, $OfsTStr("The bitmap codec does not support the bitmap property.")}
  DOM {088982F42h, $OfsTStr("The bitmap property size is invalid.")}
  DOM {088982F43h, $OfsTStr("An unknown error has occurred.")}
  DOM {088982F44h, $OfsTStr("The bitmap codec does not support a thumbnail.")}
  DOM {088982F45h, $OfsTStr("The bitmap palette is unavailable.")}
  DOM {088982F46h, $OfsTStr("Too many scanlines were requested.")}
  DOM {088982F48h, $OfsTStr("An internal error occurred.")}
  DOM {088982F49h, $OfsTStr("The bitmap bounds do not match the bitmap dimensions.")}
  DOM {088982F50h, $OfsTStr("The component cannot be found.")}
  DOM {088982F51h, $OfsTStr("The bitmap size is outside the valid range.")}
  DOM {088982F52h, $OfsTStr("There is too much metadata to be written to the bitmap.")}
  DOM {088982F60h, $OfsTStr("The image is unrecognized.")}
  DOM {088982F61h, $OfsTStr("The image header is unrecognized.")}
  DOM {088982F62h, $OfsTStr("The bitmap frame is missing.")}
  DOM {088982F63h, $OfsTStr("The image metadata header is unrecognized.")}
  DOM {088982F70h, $OfsTStr("The stream data is unrecognized.")}
  DOM {088982F71h, $OfsTStr("Failed to write to the stream.")}
  DOM {088982F72h, $OfsTStr("Failed to read from the stream.")}
  DOM {088982F73h, $OfsTStr("The stream is not available.")}
  DOM {088982F80h, $OfsTStr("The bitmap pixel format is unsupported.")}
  DOM {088982F81h, $OfsTStr("The operation is unsupported.")}
  DOM {088982F8Ah, $OfsTStr("The component registration is invalid.")}
  DOM {088982F8Bh, $OfsTStr("The component initialization has failed.")}
  DOM {088982F8Ch, $OfsTStr("The buffer allocated is insufficient.")}
  DOM {088982F8Dh, $OfsTStr("Duplicate metadata is present.")}
  DOM {088982F8Eh, $OfsTStr("The bitmap property type is unexpected.")}
  DOM {088982F8Fh, $OfsTStr("The size is unexpected.")}
  DOM {088982F90h, $OfsTStr("The property query is invalid.")}
  DOM {088982F91h, $OfsTStr("The metadata type is unexpected.")}
  DOM {088982F92h, $OfsTStr("The specified bitmap property is only valid at root level.")}
  DOM {088982F93h, $OfsTStr("The query string contains an invalid character.")}
  DOM {088982F94h, $OfsTStr("Windows Codecs received an error from the Win32 system.")}
  DOM {088982F95h, $OfsTStr("The requested level of detail is not present.")}
  DOM {088985000h, $OfsTStr("Indicates an error in an input file such as a font file.")}
  DOM {088985001h, $OfsTStr("Indicates an error originating in DirectWrite code")}
  DOM {088985002h, $OfsTStr("Indicates the specified font does not exist.")}
  DOM {088985003h, $OfsTStr("A font file could not be opened because the file")}
  DOM {088985004h, $OfsTStr("A font file exists but could not be opened due to access denied")}
  DOM {088985005h, $OfsTStr("A font collection is obsolete due to changes in the system.")}
  DOM {088985006h, $OfsTStr("The given interface is already registered.")}
  DOM {088985007h, $OfsTStr("The font cache contains invalid data.")}
  DOM {088985008h, $OfsTStr("A font cache file corresponds to a different version of DirectWrite.")}
  DOM {088985009h, $OfsTStr("The operation is not supported for this type of font.")}
  DOM {088990001h, $OfsTStr("The object was not in the correct state to process the method.")}
  DOM {088990002h, $OfsTStr("The object has not yet been initialized.")}
  DOM {088990003h, $OfsTStr("The requested operation is not supported.")}
  DOM {088990004h, $OfsTStr("The geometry scanner failed to process the data.")}
  DOM {088990005h, $OfsTStr("Direct2D could not access the screen.")}
  DOM {088990006h, $OfsTStr("A valid display state could not be determined.")}
  DOM {088990007h, $OfsTStr("The supplied vector is zero.")}
  DOM {088990008h, $OfsTStr("An internal error (Direct2D bug) occurred. On checked builds")}
  DOM {088990009h, $OfsTStr("The display format Direct2D needs to render is not supported by the hardware device.")}
  DOM {08899000Ah, $OfsTStr("A call to this method is invalid.")}
  DOM {08899000Bh, $OfsTStr("No hardware rendering device is available for this operation.")}
  DOM {08899000Ch, $OfsTStr("There has been a presentation error that may be recoverable. The caller needs to recreate")}
  DOM {08899000Dh, $OfsTStr("Shader construction failed because it was too complex.")}
  DOM {08899000Eh, $OfsTStr("Shader compilation failed.")}
  DOM {08899000Fh, $OfsTStr("Requested DirectX surface size exceeded maximum texture size.")}
  DOM {088990010h, $OfsTStr("The requested Direct2D version is not supported.")}
  DOM {088990011h, $OfsTStr("Invalid number.")}
  DOM {088990012h, $OfsTStr("Objects used together must be created from the same factory instance.")}
  DOM {088990013h, $OfsTStr("A layer resource can only be in use once at any point in time.")}
  DOM {088990014h, $OfsTStr("The pop call did not match the corresponding push call.")}
  DOM {088990015h, $OfsTStr("The resource was realized on the wrong render target.")}
  DOM {088990016h, $OfsTStr("The push and pop calls were unbalanced.")}
  DOM {088990017h, $OfsTStr("Attempt to copy from a render target while a layer or clip rect is applied.")}
  DOM {088990018h, $OfsTStr("The brush types are incompatible for the call.")}
  DOM {088990019h, $OfsTStr("An unknown win32 failure occurred.")}
  DOM {08899001Ah, $OfsTStr("The render target is not compatible with GDI.")}
  DOM {08899001Bh, $OfsTStr("A text client drawing effect object is of the wrong type.")}
  DOM {08899001Ch, $OfsTStr("The application is holding a reference to the IDWriteTextRenderer interface after the corresponding DrawText or DrawTextLayout call has returned. The IDWriteTextRenderer instance will be invalid.")}
  DOM {08899001Dh, $OfsTStr("The requested size is larger than the guaranteed supported texture size at the Direct3D device's current feature level.")}
  DOM {08899001Eh, $OfsTStr("There was a configuration error in the graph.")}
  DOM {08899001Fh, $OfsTStr("There was a internal configuration error in the graph.")}
  DOM {088990020h, $OfsTStr("There was a cycle in the graph.")}
  DOM {088990021h, $OfsTStr("Cannot draw with a bitmap that has the D2D1_BITMAP_OPTIONS_CANNOT_DRAW option.")}
  DOM {088990022h, $OfsTStr("The operation cannot complete while there are outstanding references to the target bitmap.")}
  DOM {088990023h, $OfsTStr("The operation failed because the original target is not currently bound as a target.")}
  DOM {088990024h, $OfsTStr("Cannot set the image as a target because it is either an effect or is a bitmap that does not have the D2D1_BITMAP_OPTIONS_TARGET flag set.")}
  DOM {088990025h, $OfsTStr("Cannot draw with a bitmap that is currently bound as the target bitmap.")}
  DOM {088990026h, $OfsTStr("D3D Device does not have sufficient capabilities to perform the requested action.")}
  DOM {088990027h, $OfsTStr("The graph could not be rendered with the context's current tiling settings.")}
  DOM {088990028h, $OfsTStr("The CLSID provided to Unregister did not correspond to a registered effect.")}
  DOM {088990029h, $OfsTStr("The specified property does not exist.")}
  DOM {08899002Ah, $OfsTStr("The specified sub-property does not exist.")}
  DOM {08899002Bh, $OfsTStr("AddPage or Close called after print job is already closed.")}
  DOM {08899002Ch, $OfsTStr("Error during print control creation. Indicates that none of the package target types (representing printer formats) are supported by Direct2D print control.")}
  DOM {08899002Dh, $OfsTStr("An effect attempted to use a transform with too many inputs.")}
  DOM {08A020001h, $OfsTStr("Authentication target is invalid or not configured correctly.")}
  DOM {08A020002h, $OfsTStr("Your application cannot get the Online Id properties due to the Terms of Use accepted by the user.")}
  DOM {0C0090001h, $OfsTStr("The specified event is currently not being audited.")}
  DOM {0C0090002h, $OfsTStr("The SID filtering operation removed all SIDs.")}
  DOM {0C0090003h, $OfsTStr("Business rule scripts are disabled for the calling application.")}
  DOM {0C02605E8h, $OfsTStr("The function failed because the current session is changing its type. This function cannot be called when the current session is changing its type. There are currently three types of sessions: console")}
  DOM {0C0261003h, $OfsTStr("Checksum of the obtained monitor descriptor is invalid.")}
  DOM {0C0261004h, $OfsTStr("Monitor descriptor contains an invalid standard timing block.")}
  DOM {0C0261005h, $OfsTStr("WMI data block registration failed for one of the MSMonitorClass WMI subclasses.")}
  DOM {0C0261006h, $OfsTStr("Provided monitor descriptor block is either corrupted or does not contain monitor's detailed serial number.")}
  DOM {0C0261007h, $OfsTStr("Provided monitor descriptor block is either corrupted or does not contain monitor's user friendly name.")}
  DOM {0C0261008h, $OfsTStr("There is no monitor descriptor data at the specified (offset")}
  DOM {0C0261009h, $OfsTStr("Monitor descriptor contains an invalid detailed timing block.")}
  DOM {0C026100Ah, $OfsTStr("Monitor descriptor contains invalid manufacture date.")}
  DOM {0C0262000h, $OfsTStr("Exclusive mode ownership is needed to create unmanaged primary allocation.")}
  DOM {0C0262001h, $OfsTStr("The driver needs more DMA buffer space in order to complete the requested operation.")}
  DOM {0C0262002h, $OfsTStr("Specified display adapter handle is invalid.")}
  DOM {0C0262003h, $OfsTStr("Specified display adapter and all of its state has been reset.")}
  DOM {0C0262004h, $OfsTStr("The driver stack doesn't match the expected driver model.")}
  DOM {0C0262005h, $OfsTStr("Present happened but ended up in the changed desktop")}
  DOM {0C0262006h, $OfsTStr("Nothing to present due to desktop occlusion")}
  DOM {0C0262007h, $OfsTStr("Not able to present due to denial of desktop access")}
  DOM {0C0262008h, $OfsTStr("Not able to present with color convertion")}
  DOM {0C0262009h, $OfsTStr("The kernel driver detected a version mismatch between it and the user mode driver.")}
  DOM {0C026200Bh, $OfsTStr("Present redirection is disabled (desktop windowing management subsystem is off).")}
  DOM {0C026200Ch, $OfsTStr("Previous exclusive VidPn source owner has released its ownership")}
  DOM {0C026200Dh, $OfsTStr("Window DC is not available for presentation")}
  DOM {0C0262100h, $OfsTStr("Not enough video memory available to complete the operation.")}
  DOM {0C0262101h, $OfsTStr("Couldn't probe and lock the underlying memory of an allocation.")}
  DOM {0C0262102h, $OfsTStr("The allocation is currently busy.")}
  DOM {0C0262103h, $OfsTStr("An object being referenced has reach the maximum reference count already and can't be reference further.")}
  DOM {0C0262104h, $OfsTStr("A problem couldn't be solved due to some currently existing condition. The problem should be tried again later.")}
  DOM {0C0262105h, $OfsTStr("A problem couldn't be solved due to some currently existing condition. The problem should be tried again immediately.")}
  DOM {0C0262106h, $OfsTStr("The allocation is invalid.")}
  DOM {0C0262107h, $OfsTStr("No more unswizzling aperture are currently available.")}
  DOM {0C0262108h, $OfsTStr("The current allocation can't be unswizzled by an aperture.")}
  DOM {0C0262109h, $OfsTStr("The request failed because a pinned allocation can't be evicted.")}
  DOM {0C0262110h, $OfsTStr("The allocation can't be used from its current segment location for the specified operation.")}
  DOM {0C0262111h, $OfsTStr("A locked allocation can't be used in the current command buffer.")}
  DOM {0C0262112h, $OfsTStr("The allocation being referenced has been closed permanently.")}
  DOM {0C0262113h, $OfsTStr("An invalid allocation instance is being referenced.")}
  DOM {0C0262114h, $OfsTStr("An invalid allocation handle is being referenced.")}
  DOM {0C0262115h, $OfsTStr("The allocation being referenced doesn't belong to the current device.")}
  DOM {0C0262116h, $OfsTStr("The specified allocation lost its content.")}
  DOM {0C0262200h, $OfsTStr("GPU exception is detected on the given device. The device is not able to be scheduled.")}
  DOM {0C0262300h, $OfsTStr("Specified VidPN topology is invalid.")}
  DOM {0C0262301h, $OfsTStr("Specified VidPN topology is valid but is not supported by this model of the display adapter.")}
  DOM {0C0262302h, $OfsTStr("Specified VidPN topology is valid but is not supported by the display adapter at this time")}
  DOM {0C0262303h, $OfsTStr("Specified VidPN handle is invalid.")}
  DOM {0C0262304h, $OfsTStr("Specified video present source is invalid.")}
  DOM {0C0262305h, $OfsTStr("Specified video present target is invalid.")}
  DOM {0C0262306h, $OfsTStr("Specified VidPN modality is not supported (e.g. at least two of the pinned modes are not cofunctional).")}
  DOM {0C0262308h, $OfsTStr("Specified VidPN source mode set is invalid.")}
  DOM {0C0262309h, $OfsTStr("Specified VidPN target mode set is invalid.")}
  DOM {0C026230Ah, $OfsTStr("Specified video signal frequency is invalid.")}
  DOM {0C026230Bh, $OfsTStr("Specified video signal active region is invalid.")}
  DOM {0C026230Ch, $OfsTStr("Specified video signal total region is invalid.")}
  DOM {0C0262310h, $OfsTStr("Specified video present source mode is invalid.")}
  DOM {0C0262311h, $OfsTStr("Specified video present target mode is invalid.")}
  DOM {0C0262312h, $OfsTStr("Pinned mode must remain in the set on VidPN's cofunctional modality enumeration.")}
  DOM {0C0262313h, $OfsTStr("Specified video present path is already in VidPN's topology.")}
  DOM {0C0262314h, $OfsTStr("Specified mode is already in the mode set.")}
  DOM {0C0262315h, $OfsTStr("Specified video present source set is invalid.")}
  DOM {0C0262316h, $OfsTStr("Specified video present target set is invalid.")}
  DOM {0C0262317h, $OfsTStr("Specified video present source is already in the video present source set.")}
  DOM {0C0262318h, $OfsTStr("Specified video present target is already in the video present target set.")}
  DOM {0C0262319h, $OfsTStr("Specified VidPN present path is invalid.")}
  DOM {0C026231Ah, $OfsTStr("Miniport has no recommendation for augmentation of the specified VidPN's topology.")}
  DOM {0C026231Bh, $OfsTStr("Specified monitor frequency range set is invalid.")}
  DOM {0C026231Ch, $OfsTStr("Specified monitor frequency range is invalid.")}
  DOM {0C026231Dh, $OfsTStr("Specified frequency range is not in the specified monitor frequency range set.")}
  DOM {0C026231Fh, $OfsTStr("Specified frequency range is already in the specified monitor frequency range set.")}
  DOM {0C0262320h, $OfsTStr("Specified mode set is stale. Please reacquire the new mode set.")}
  DOM {0C0262321h, $OfsTStr("Specified monitor source mode set is invalid.")}
  DOM {0C0262322h, $OfsTStr("Specified monitor source mode is invalid.")}
  DOM {0C0262323h, $OfsTStr("Miniport does not have any recommendation regarding the request to provide a functional VidPN given the current display adapter configuration.")}
  DOM {0C0262324h, $OfsTStr("ID of the specified mode is already used by another mode in the set.")}
  DOM {0C0262325h, $OfsTStr("System failed to determine a mode that is supported by both the display adapter and the monitor connected to it.")}
  DOM {0C0262326h, $OfsTStr("Number of video present targets must be greater than or equal to the number of video present sources.")}
  DOM {0C0262327h, $OfsTStr("Specified present path is not in VidPN's topology.")}
  DOM {0C0262328h, $OfsTStr("Display adapter must have at least one video present source.")}
  DOM {0C0262329h, $OfsTStr("Display adapter must have at least one video present target.")}
  DOM {0C026232Ah, $OfsTStr("Specified monitor descriptor set is invalid.")}
  DOM {0C026232Bh, $OfsTStr("Specified monitor descriptor is invalid.")}
  DOM {0C026232Ch, $OfsTStr("Specified descriptor is not in the specified monitor descriptor set.")}
  DOM {0C026232Dh, $OfsTStr("Specified descriptor is already in the specified monitor descriptor set.")}
  DOM {0C026232Eh, $OfsTStr("ID of the specified monitor descriptor is already used by another descriptor in the set.")}
  DOM {0C026232Fh, $OfsTStr("Specified video present target subset type is invalid.")}
  DOM {0C0262330h, $OfsTStr("Two or more of the specified resources are not related to each other")}
  DOM {0C0262331h, $OfsTStr("ID of the specified video present source is already used by another source in the set.")}
  DOM {0C0262332h, $OfsTStr("ID of the specified video present target is already used by another target in the set.")}
  DOM {0C0262333h, $OfsTStr("Specified VidPN source cannot be used because there is no available VidPN target to connect it to.")}
  DOM {0C0262334h, $OfsTStr("Newly arrived monitor could not be associated with a display adapter.")}
  DOM {0C0262335h, $OfsTStr("Display adapter in question does not have an associated VidPN manager.")}
  DOM {0C0262336h, $OfsTStr("VidPN manager of the display adapter in question does not have an active VidPN.")}
  DOM {0C0262337h, $OfsTStr("Specified VidPN topology is stale. Please reacquire the new topology.")}
  DOM {0C0262338h, $OfsTStr("There is no monitor connected on the specified video present target.")}
  DOM {0C0262339h, $OfsTStr("Specified source is not part of the specified VidPN's topology.")}
  DOM {0C026233Ah, $OfsTStr("Specified primary surface size is invalid.")}
  DOM {0C026233Bh, $OfsTStr("Specified visible region size is invalid.")}
  DOM {0C026233Ch, $OfsTStr("Specified stride is invalid.")}
  DOM {0C026233Dh, $OfsTStr("Specified pixel format is invalid.")}
  DOM {0C026233Eh, $OfsTStr("Specified color basis is invalid.")}
  DOM {0C026233Fh, $OfsTStr("Specified pixel value access mode is invalid.")}
  DOM {0C0262340h, $OfsTStr("Specified target is not part of the specified VidPN's topology.")}
  DOM {0C0262341h, $OfsTStr("Failed to acquire display mode management interface.")}
  DOM {0C0262342h, $OfsTStr("Specified VidPN source is already owned by a DMM client and cannot be used until that client releases it.")}
  DOM {0C0262343h, $OfsTStr("Specified VidPN is active and cannot be accessed.")}
  DOM {0C0262344h, $OfsTStr("Specified VidPN present path importance ordinal is invalid.")}
  DOM {0C0262345h, $OfsTStr("Specified VidPN present path content geometry transformation is invalid.")}
  DOM {0C0262346h, $OfsTStr("Specified content geometry transformation is not supported on the respective VidPN present path.")}
  DOM {0C0262347h, $OfsTStr("Specified gamma ramp is invalid.")}
  DOM {0C0262348h, $OfsTStr("Specified gamma ramp is not supported on the respective VidPN present path.")}
  DOM {0C0262349h, $OfsTStr("Multi-sampling is not supported on the respective VidPN present path.")}
  DOM {0C026234Ah, $OfsTStr("Specified mode is not in the specified mode set.")}
  DOM {0C026234Dh, $OfsTStr("Specified VidPN topology recommendation reason is invalid.")}
  DOM {0C026234Eh, $OfsTStr("Specified VidPN present path content type is invalid.")}
  DOM {0C026234Fh, $OfsTStr("Specified VidPN present path copy protection type is invalid.")}
  DOM {0C0262350h, $OfsTStr("No more than one unassigned mode set can exist at any given time for a given VidPN source/target.")}
  DOM {0C0262352h, $OfsTStr("Specified scanline ordering type is invalid.")}
  DOM {0C0262353h, $OfsTStr("Topology changes are not allowed for the specified VidPN.")}
  DOM {0C0262354h, $OfsTStr("All available importance ordinals are already used in specified topology.")}
  DOM {0C0262355h, $OfsTStr("Specified primary surface has a different private format attribute than the current primary surface")}
  DOM {0C0262356h, $OfsTStr("Specified mode pruning algorithm is invalid")}
  DOM {0C0262357h, $OfsTStr("Specified monitor capability origin is invalid.")}
  DOM {0C0262358h, $OfsTStr("Specified monitor frequency range constraint is invalid.")}
  DOM {0C0262359h, $OfsTStr("Maximum supported number of present paths has been reached.")}
  DOM {0C026235Ah, $OfsTStr("Miniport requested that augmentation be canceled for the specified source of the specified VidPN's topology.")}
  DOM {0C026235Bh, $OfsTStr("Specified client type was not recognized.")}
  DOM {0C026235Ch, $OfsTStr("Client VidPN is not set on this adapter (e.g. no user mode initiated mode changes took place on this adapter yet).")}
  DOM {0C0262400h, $OfsTStr("Specified display adapter child device already has an external device connected to it.")}
  DOM {0C0262401h, $OfsTStr("Specified display adapter child device does not support descriptor exposure.")}
  DOM {0C0262430h, $OfsTStr("The display adapter is not linked to any other adapters.")}
  DOM {0C0262431h, $OfsTStr("Lead adapter in a linked configuration was not enumerated yet.")}
  DOM {0C0262432h, $OfsTStr("Some chain adapters in a linked configuration were not enumerated yet.")}
  DOM {0C0262433h, $OfsTStr("The chain of linked adapters is not ready to start because of an unknown failure.")}
  DOM {0C0262434h, $OfsTStr("An attempt was made to start a lead link display adapter when the chain links were not started yet.")}
  DOM {0C0262435h, $OfsTStr("An attempt was made to power up a lead link display adapter when the chain links were powered down.")}
  DOM {0C0262436h, $OfsTStr("The adapter link was found to be in an inconsistent state. Not all adapters are in an expected PNP/Power state.")}
  DOM {0C0262438h, $OfsTStr("The driver trying to start is not the same as the driver for the POSTed display adapter.")}
  DOM {0C026243Bh, $OfsTStr("An operation is being attempted that requires the display adapter to be in a quiescent state.")}
  DOM {0C0262500h, $OfsTStr("The driver does not support OPM.")}
  DOM {0C0262501h, $OfsTStr("The driver does not support COPP.")}
  DOM {0C0262502h, $OfsTStr("The driver does not support UAB.")}
  DOM {0C0262503h, $OfsTStr("The specified encrypted parameters are invalid.")}
  DOM {0C0262505h, $OfsTStr("The GDI display device passed to this function does not have any active video outputs.")}
  DOM {0C026250Bh, $OfsTStr("An internal error caused this operation to fail.")}
  DOM {0C026250Ch, $OfsTStr("The function failed because the caller passed in an invalid OPM user mode handle.")}
  DOM {0C026250Eh, $OfsTStr("A certificate could not be returned because the certificate buffer passed to the function was too small.")}
  DOM {0C026250Fh, $OfsTStr("A video output could not be created because the frame buffer is in spanning mode.")}
  DOM {0C0262510h, $OfsTStr("A video output could not be created because the frame buffer is in theater mode.")}
  DOM {0C0262511h, $OfsTStr("The function failed because the display adapter's Hardware Functionality Scan failed to validate the graphics hardware.")}
  DOM {0C0262512h, $OfsTStr("The HDCP System Renewability Message passed to this function did not comply with section 5 of the HDCP 1.1 specification.")}
  DOM {0C0262513h, $OfsTStr("The video output cannot enable the High-bandwidth Digital Content Protection (HDCP) System because it does not support HDCP.")}
  DOM {0C0262514h, $OfsTStr("The video output cannot enable Analog Copy Protection (ACP) because it does not support ACP.")}
  DOM {0C0262515h, $OfsTStr("The video output cannot enable the Content Generation Management System Analog (CGMS-A) protection technology because it does not support CGMS-A.")}
  DOM {0C0262516h, $OfsTStr("The IOPMVideoOutput::GetInformation method cannot return the version of the SRM being used because the application never successfully passed an SRM to the video output.")}
  DOM {0C0262517h, $OfsTStr("The IOPMVideoOutput::Configure method cannot enable the specified output protection technology because the output's screen resolution is too high.")}
  DOM {0C0262518h, $OfsTStr("The IOPMVideoOutput::Configure method cannot enable HDCP because the display adapter's HDCP hardware is already being used by other physical outputs.")}
  DOM {0C026251Ah, $OfsTStr("The operating system asynchronously destroyed this OPM video output because the operating system's state changed. This error typically occurs because the monitor PDO associated with this video output was removed")}
  DOM {0C026251Bh, $OfsTStr("The method failed because the session is changing its type. No IOPMVideoOutput methods can be called when a session is changing its type. There are currently three types of sessions: console")}
  DOM {0C026251Ch, $OfsTStr("Either the IOPMVideoOutput::COPPCompatibleGetInformation")}
  DOM {0C026251Dh, $OfsTStr("The IOPMVideoOutput::GetInformation and IOPMVideoOutput::COPPCompatibleGetInformation methods return this error if the passed in sequence number is not the expected sequence number or the passed in OMAC value is invalid.")}
  DOM {0C026251Eh, $OfsTStr("The method failed because an unexpected error occurred inside of a display driver.")}
  DOM {0C026251Fh, $OfsTStr("Either the IOPMVideoOutput::COPPCompatibleGetInformation")}
  DOM {0C0262520h, $OfsTStr("The IOPMVideoOutput::COPPCompatibleGetInformation or IOPMVideoOutput::Configure method failed because the display driver does not support the OPM_GET_ACP_AND_CGMSA_SIGNALING and OPM_SET_ACP_AND_CGMSA_SIGNALING GUIDs.")}
  DOM {0C0262521h, $OfsTStr("The IOPMVideoOutput::Configure function returns this error code if the passed in sequence number is not the expected sequence number or the passed in OMAC value is invalid.")}
  DOM {0C0262580h, $OfsTStr("The monitor connected to the specified video output does not have an I2C bus.")}
  DOM {0C0262581h, $OfsTStr("No device on the I2C bus has the specified address.")}
  DOM {0C0262582h, $OfsTStr("An error occurred while transmitting data to the device on the I2C bus.")}
  DOM {0C0262583h, $OfsTStr("An error occurred while receiving data from the device on the I2C bus.")}
  DOM {0C0262584h, $OfsTStr("The monitor does not support the specified VCP code.")}
  DOM {0C0262585h, $OfsTStr("The data received from the monitor is invalid.")}
  DOM {0C0262586h, $OfsTStr("The function failed because a monitor returned an invalid Timing Status byte when the operating system used the DDC/CI Get Timing Report & Timing Message command to get a timing report from a monitor.")}
  DOM {0C0262587h, $OfsTStr("The monitor returned a DDC/CI capabilities string which did not comply with the ACCESS.bus 3.0")}
  DOM {0C0262588h, $OfsTStr("An internal Monitor Configuration API error occurred.")}
  DOM {0C0262589h, $OfsTStr("An operation failed because a DDC/CI message had an invalid value in its command field.")}
  DOM {0C026258Ah, $OfsTStr("An error occurred because the field length of a DDC/CI message contained an invalid value.")}
  DOM {0C026258Bh, $OfsTStr("An error occurred because the checksum field in a DDC/CI message did not match the message's computed checksum value. This error implies that the data was corrupted while it was being transmitted from a monitor to a computer.")}
  DOM {0C026258Ch, $OfsTStr("This function failed because an invalid monitor handle was passed to it.")}
  DOM {0C026258Dh, $OfsTStr("The operating system asynchronously destroyed the monitor which corresponds to this handle because the operating system's state changed. This error typically occurs because the monitor PDO associated with this handle was removed")}
  DOM {0C02625D8h, $OfsTStr("A continuous VCP code's current value is greater than its maximum value. This error code indicates that a monitor returned an invalid value.")}
  DOM {0C02625D9h, $OfsTStr("The monitor's VCP Version (0xDF) VCP code returned an invalid version value.")}
  DOM {0C02625DAh, $OfsTStr("The monitor does not comply with the MCCS specification it claims to support.")}
  DOM {0C02625DBh, $OfsTStr("The MCCS version in a monitor's mccs_ver capability does not match the MCCS version the monitor reports when the VCP Version (0xDF) VCP code is used.")}
  DOM {0C02625DCh, $OfsTStr("The Monitor Configuration API only works with monitors which support the MCCS 1.0 specification")}
  DOM {0C02625DEh, $OfsTStr("The monitor returned an invalid monitor technology type. CRT")}
  DOM {0C02625DFh, $OfsTStr("SetMonitorColorTemperature()'s caller passed a color temperature to it which the current monitor did not support. This error implies that the monitor violated the MCCS 2.0 or MCCS 2.0 Revision 1 specification.")}
  DOM {0C02625E0h, $OfsTStr("This function can only be used if a program is running in the local console session. It cannot be used if the program is running on a remote desktop session or on a terminal server session.")}
  DOM {0C02625E1h, $OfsTStr("This function cannot find an actual GDI display device which corresponds to the specified GDI display device name.")}
  DOM {0C02625E2h, $OfsTStr("The function failed because the specified GDI display device was not attached to the Windows desktop.")}
  DOM {0C02625E3h, $OfsTStr("This function does not support GDI mirroring display devices because GDI mirroring display devices do not have any physical monitors associated with them.")}
  DOM {0C02625E4h, $OfsTStr("The function failed because an invalid pointer parameter was passed to it. A pointer parameter is invalid if it is NULL")}
  DOM {0C02625E5h, $OfsTStr("The function failed because the specified GDI device did not have any monitors associated with it.")}
  DOM {0C02625E6h, $OfsTStr("An array passed to the function cannot hold all of the data that the function must copy into the array.")}
  DOM {0C02625E7h, $OfsTStr("An internal error caused an operation to fail.")}
  DOM {0C034100Fh, $OfsTStr("The TCP connection is not offloadable because of a local policy setting.")}
  DOM {0C0341012h, $OfsTStr("The TCP connection is not offloadable by the Chimney Offload target.")}
  DOM {0C0341013h, $OfsTStr("The IP Path object is not in an offloadable state.")}
  DOM {0C0350002h, $OfsTStr("The hypervisor does not support the operation because the specified hypercall code is not supported.")}
  DOM {0C0350003h, $OfsTStr("The hypervisor does not support the operation because the encoding for the hypercall input register is not supported.")}
  DOM {0C0350004h, $OfsTStr("The hypervisor could not perform the operation because a parameter has an invalid alignment.")}
  DOM {0C0350005h, $OfsTStr("The hypervisor could not perform the operation because an invalid parameter was specified.")}
  DOM {0C0350006h, $OfsTStr("Access to the specified object was denied.")}
  DOM {0C0350007h, $OfsTStr("The hypervisor could not perform the operation because the partition is entering or in an invalid state.")}
  DOM {0C0350008h, $OfsTStr("The operation is not allowed in the current state.")}
  DOM {0C0350009h, $OfsTStr("The hypervisor does not recognize the specified partition property.")}
  DOM {0C035000Ah, $OfsTStr("The specified value of a partition property is out of range or violates an invariant.")}
  DOM {0C035000Bh, $OfsTStr("There is not enough memory in the hypervisor pool to complete the operation.")}
  DOM {0C035000Ch, $OfsTStr("The maximum partition depth has been exceeded for the partition hierarchy.")}
  DOM {0C035000Dh, $OfsTStr("A partition with the specified partition Id does not exist.")}
  DOM {0C035000Eh, $OfsTStr("The hypervisor could not perform the operation because the specified VP index is invalid.")}
  DOM {0C0350011h, $OfsTStr("The hypervisor could not perform the operation because the specified port identifier is invalid.")}
  DOM {0C0350012h, $OfsTStr("The hypervisor could not perform the operation because the specified connection identifier is invalid.")}
  DOM {0C0350013h, $OfsTStr("Not enough buffers were supplied to send a message.")}
  DOM {0C0350014h, $OfsTStr("The previous virtual interrupt has not been acknowledged.")}
  DOM {0C0350016h, $OfsTStr("The previous virtual interrupt has already been acknowledged.")}
  DOM {0C0350017h, $OfsTStr("The indicated partition is not in a valid state for saving or restoring.")}
  DOM {0C0350018h, $OfsTStr("The hypervisor could not complete the operation because a required feature of the synthetic interrupt controller (SynIC) was disabled.")}
  DOM {0C0350019h, $OfsTStr("The hypervisor could not perform the operation because the object or value was either already in use or being used for a purpose that would not permit completing the operation.")}
  DOM {0C035001Ah, $OfsTStr("The proximity domain information is invalid.")}
  DOM {0C035001Bh, $OfsTStr("An attempt to retrieve debugging data failed because none was available.")}
  DOM {0C035001Ch, $OfsTStr("The physical connection being used for debugging has not recorded any receive activity since the last operation.")}
  DOM {0C035001Dh, $OfsTStr("There are not enough resources to complete the operation.")}
  DOM {0C035001Eh, $OfsTStr("A hypervisor feature is not available to the user.")}
  DOM {0C0350038h, $OfsTStr("The maximum number of domains supported by the platform I/O remapping hardware is currently in use. No domains are available to assign this device to this partition.")}
  DOM {0C0350041h, $OfsTStr("The hypervisor could not perform the operation because the specified LP index is invalid.")}
  DOM {0C0351000h, $OfsTStr("No hypervisor is present on this system.")}
  DOM {0C0370001h, $OfsTStr("The handler for the virtualization infrastructure driver is already registered. Restarting the virtual machine may fix the problem. If the problem persists")}
  DOM {0C0370002h, $OfsTStr("The number of registered handlers for the virtualization infrastructure driver exceeded the maximum. Restarting the virtual machine may fix the problem. If the problem persists")}
  DOM {0C0370003h, $OfsTStr("The message queue for the virtualization infrastructure driver is full and cannot accept new messages. Restarting the virtual machine may fix the problem. If the problem persists")}
  DOM {0C0370004h, $OfsTStr("No handler exists to handle the message for the virtualization infrastructure driver. Restarting the virtual machine may fix the problem. If the problem persists")}
  DOM {0C0370005h, $OfsTStr("The name of the partition or message queue for the virtualization infrastructure driver is invalid. Restarting the virtual machine may fix the problem. If the problem persists")}
  DOM {0C0370006h, $OfsTStr("The partition name of the virtualization infrastructure driver exceeds the maximum.")}
  DOM {0C0370007h, $OfsTStr("The message queue name of the virtualization infrastructure driver exceeds the maximum.")}
  DOM {0C0370008h, $OfsTStr("Cannot create the partition for the virtualization infrastructure driver because another partition with the same name already exists.")}
  DOM {0C0370009h, $OfsTStr("The virtualization infrastructure driver has encountered an error. The requested partition does not exist. Restarting the virtual machine may fix the problem. If the problem persists")}
  DOM {0C037000Ah, $OfsTStr("The virtualization infrastructure driver has encountered an error. Could not find the requested partition. Restarting the virtual machine may fix the problem. If the problem persists")}
  DOM {0C037000Bh, $OfsTStr("A message queue with the same name already exists for the virtualization infrastructure driver.")}
  DOM {0C037000Ch, $OfsTStr("The memory block page for the virtualization infrastructure driver cannot be mapped because the page map limit has been reached. Restarting the virtual machine may fix the problem. If the problem persists")}
  DOM {0C037000Dh, $OfsTStr("The memory block for the virtualization infrastructure driver is still being used and cannot be destroyed.")}
  DOM {0C037000Eh, $OfsTStr("Cannot unlock the page array for the guest operating system memory address because it does not match a previous lock request. Restarting the virtual machine may fix the problem. If the problem persists")}
  DOM {0C037000Fh, $OfsTStr("The non-uniform memory access (NUMA) node settings do not match the system NUMA topology. In order to start the virtual machine")}
  DOM {0C0370010h, $OfsTStr("The non-uniform memory access (NUMA) node index does not match a valid index in the system NUMA topology.")}
  DOM {0C0370011h, $OfsTStr("The memory block for the virtualization infrastructure driver is already associated with a message queue.")}
  DOM {0C0370012h, $OfsTStr("The handle is not a valid memory block handle for the virtualization infrastructure driver.")}
  DOM {0C0370013h, $OfsTStr("The request exceeded the memory block page limit for the virtualization infrastructure driver. Restarting the virtual machine may fix the problem. If the problem persists")}
  DOM {0C0370014h, $OfsTStr("The handle is not a valid message queue handle for the virtualization infrastructure driver.")}
  DOM {0C0370015h, $OfsTStr("The handle is not a valid page range handle for the virtualization infrastructure driver.")}
  DOM {0C0370016h, $OfsTStr("Cannot install client notifications because no message queue for the virtualization infrastructure driver is associated with the memory block.")}
  DOM {0C0370017h, $OfsTStr("The request to lock or map a memory block page failed because the virtualization infrastructure driver memory block limit has been reached. Restarting the virtual machine may fix the problem. If the problem persists")}
  DOM {0C0370018h, $OfsTStr("The handle is not a valid parent partition mapping handle for the virtualization infrastructure driver.")}
  DOM {0C0370019h, $OfsTStr("Notifications cannot be created on the memory block because it is use.")}
  DOM {0C037001Ah, $OfsTStr("The message queue for the virtualization infrastructure driver has been closed. Restarting the virtual machine may fix the problem. If the problem persists")}
  DOM {0C037001Bh, $OfsTStr("Cannot add a virtual processor to the partition because the maximum has been reached.")}
  DOM {0C037001Ch, $OfsTStr("Cannot stop the virtual processor immediately because of a pending intercept.")}
  DOM {0C037001Dh, $OfsTStr("Invalid state for the virtual processor. Restarting the virtual machine may fix the problem. If the problem persists")}
  DOM {0C037001Eh, $OfsTStr("The maximum number of kernel mode clients for the virtualization infrastructure driver has been reached. Restarting the virtual machine may fix the problem. If the problem persists")}
  DOM {0C037001Fh, $OfsTStr("This kernel mode interface for the virtualization infrastructure driver has already been initialized. Restarting the virtual machine may fix the problem. If the problem persists")}
  DOM {0C0370020h, $OfsTStr("Cannot set or reset the memory block property more than once for the virtualization infrastructure driver. Restarting the virtual machine may fix the problem. If the problem persists")}
  DOM {0C0370021h, $OfsTStr("The memory mapped I/O for this page range no longer exists. Restarting the virtual machine may fix the problem. If the problem persists")}
  DOM {0C0370022h, $OfsTStr("The lock or unlock request uses an invalid guest operating system memory address. Restarting the virtual machine may fix the problem. If the problem persists")}
  DOM {0C0370023h, $OfsTStr("Cannot destroy or reuse the reserve page set for the virtualization infrastructure driver because it is in use. Restarting the virtual machine may fix the problem. If the problem persists")}
  DOM {0C0370024h, $OfsTStr("The reserve page set for the virtualization infrastructure driver is too small to use in the lock request. Restarting the virtual machine may fix the problem. If the problem persists")}
  DOM {0C0370025h, $OfsTStr("Cannot lock or map the memory block page for the virtualization infrastructure driver because it has already been locked using a reserve page set page. Restarting the virtual machine may fix the problem. If the problem persists")}
  DOM {0C0370026h, $OfsTStr("Cannot create the memory block for the virtualization infrastructure driver because the requested number of pages exceeded the limit. Restarting the virtual machine may fix the problem. If the problem persists")}
  DOM {0C0370027h, $OfsTStr("Cannot restore this virtual machine because the saved state data cannot be read. Delete the saved state data and then try to start the virtual machine.")}
  DOM {0C0370028h, $OfsTStr("Cannot restore this virtual machine because an item read from the saved state data is not recognized. Delete the saved state data and then try to start the virtual machine.")}
  DOM {0C0370029h, $OfsTStr("Cannot restore this virtual machine to the saved state because of hypervisor incompatibility. Delete the saved state data and then try to start the virtual machine.")}
  DOM {0C0380001h, $OfsTStr("The configuration database is full.")}
  DOM {0C0380002h, $OfsTStr("The configuration data on the disk is corrupted.")}
  DOM {0C0380003h, $OfsTStr("The configuration on the disk is not insync with the in-memory configuration.")}
  DOM {0C0380004h, $OfsTStr("A majority of disks failed to be updated with the new configuration.")}
  DOM {0C0380005h, $OfsTStr("The disk contains non-simple volumes.")}
  DOM {0C0380006h, $OfsTStr("The same disk was specified more than once in the migration list.")}
  DOM {0C0380007h, $OfsTStr("The disk is already dynamic.")}
  DOM {0C0380008h, $OfsTStr("The specified disk id is invalid. There are no disks with the specified disk id.")}
  DOM {0C0380009h, $OfsTStr("The specified disk is an invalid disk. Operation cannot complete on an invalid disk.")}
  DOM {0C038000Ah, $OfsTStr("The specified disk(s) cannot be removed since it is the last remaining voter.")}
  DOM {0C038000Bh, $OfsTStr("The specified disk has an invalid disk layout.")}
  DOM {0C038000Ch, $OfsTStr("The disk layout contains non-basic partitions which appear after basic paritions. This is an invalid disk layout.")}
  DOM {0C038000Dh, $OfsTStr("The disk layout contains partitions which are not cylinder aligned.")}
  DOM {0C038000Eh, $OfsTStr("The disk layout contains partitions which are samller than the minimum size.")}
  DOM {0C038000Fh, $OfsTStr("The disk layout contains primary partitions in between logical drives. This is an invalid disk layout.")}
  DOM {0C0380010h, $OfsTStr("The disk layout contains more than the maximum number of supported partitions.")}
  DOM {0C0380011h, $OfsTStr("The specified disk is missing. The operation cannot complete on a missing disk.")}
  DOM {0C0380012h, $OfsTStr("The specified disk is not empty.")}
  DOM {0C0380013h, $OfsTStr("There is not enough usable space for this operation.")}
  DOM {0C0380014h, $OfsTStr("The force revectoring of bad sectors failed.")}
  DOM {0C0380015h, $OfsTStr("The specified disk has an invalid sector size.")}
  DOM {0C0380016h, $OfsTStr("The specified disk set contains volumes which exist on disks outside of the set.")}
  DOM {0C0380017h, $OfsTStr("A disk in the volume layout provides extents to more than one member of a plex.")}
  DOM {0C0380018h, $OfsTStr("A disk in the volume layout provides extents to more than one plex.")}
  DOM {0C0380019h, $OfsTStr("Dynamic disks are not supported on this system.")}
  DOM {0C038001Ah, $OfsTStr("The specified extent is already used by other volumes.")}
  DOM {0C038001Bh, $OfsTStr("The specified volume is retained and can only be extended into a contiguous extent. The specified extent to grow the volume is not contiguous with the specified volume.")}
  DOM {0C038001Ch, $OfsTStr("The specified volume extent is not within the public region of the disk.")}
  DOM {0C038001Dh, $OfsTStr("The specified volume extent is not sector aligned.")}
  DOM {0C038001Eh, $OfsTStr("The specified parition overlaps an EBR (the first track of an extended partition on a MBR disks).")}
  DOM {0C038001Fh, $OfsTStr("The specified extent lengths cannot be used to construct a volume with specified length.")}
  DOM {0C0380020h, $OfsTStr("The system does not support fault tolerant volumes.")}
  DOM {0C0380021h, $OfsTStr("The specified interleave length is invalid.")}
  DOM {0C0380022h, $OfsTStr("There is already a maximum number of registered users.")}
  DOM {0C0380023h, $OfsTStr("The specified member is already in-sync with the other active members. It does not need to be regenerated.")}
  DOM {0C0380024h, $OfsTStr("The same member index was specified more than once.")}
  DOM {0C0380025h, $OfsTStr("The specified member index is greater or equal than the number of members in the volume plex.")}
  DOM {0C0380026h, $OfsTStr("The specified member is missing. It cannot be regenerated.")}
  DOM {0C0380027h, $OfsTStr("The specified member is not detached. Cannot replace a member which is not detached.")}
  DOM {0C0380028h, $OfsTStr("The specified member is already regenerating.")}
  DOM {0C0380029h, $OfsTStr("All disks belonging to the pack failed.")}
  DOM {0C038002Ah, $OfsTStr("There are currently no registered users for notifications. The task number is irrelevant unless there are registered users.")}
  DOM {0C038002Bh, $OfsTStr("The specified notification user does not exist. Failed to unregister user for notifications.")}
  DOM {0C038002Ch, $OfsTStr("The notifications have been reset. Notifications for the current user are invalid. Unregister and re-register for notifications.")}
  DOM {0C038002Dh, $OfsTStr("The specified number of members is invalid.")}
  DOM {0C038002Eh, $OfsTStr("The specified number of plexes is invalid.")}
  DOM {0C038002Fh, $OfsTStr("The specified source and target packs are identical.")}
  DOM {0C0380030h, $OfsTStr("The specified pack id is invalid. There are no packs with the specified pack id.")}
  DOM {0C0380031h, $OfsTStr("The specified pack is the invalid pack. The operation cannot complete with the invalid pack.")}
  DOM {0C0380032h, $OfsTStr("The specified pack name is invalid.")}
  DOM {0C0380033h, $OfsTStr("The specified pack is offline.")}
  DOM {0C0380034h, $OfsTStr("The specified pack already has a quorum of healthy disks.")}
  DOM {0C0380035h, $OfsTStr("The pack does not have a quorum of healthy disks.")}
  DOM {0C0380036h, $OfsTStr("The specified disk has an unsupported partition style. Only MBR and GPT partition styles are supported.")}
  DOM {0C0380037h, $OfsTStr("Failed to update the disk's partition layout.")}
  DOM {0C0380038h, $OfsTStr("The specified plex is already in-sync with the other active plexes. It does not need to be regenerated.")}
  DOM {0C0380039h, $OfsTStr("The same plex index was specified more than once.")}
  DOM {0C038003Ah, $OfsTStr("The specified plex index is greater or equal than the number of plexes in the volume.")}
  DOM {0C038003Bh, $OfsTStr("The specified plex is the last active plex in the volume. The plex cannot be removed or else the volume will go offline.")}
  DOM {0C038003Ch, $OfsTStr("The specified plex is missing.")}
  DOM {0C038003Dh, $OfsTStr("The specified plex is currently regenerating.")}
  DOM {0C038003Eh, $OfsTStr("The specified plex type is invalid.")}
  DOM {0C038003Fh, $OfsTStr("The operation is only supported on RAID-5 plexes.")}
  DOM {0C0380040h, $OfsTStr("The operation is only supported on simple plexes.")}
  DOM {0C0380041h, $OfsTStr("The Size fields in the VM_VOLUME_LAYOUT input structure are incorrectly set.")}
  DOM {0C0380042h, $OfsTStr("There is already a pending request for notifications. Wait for the existing request to return before requesting for more notifications.")}
  DOM {0C0380043h, $OfsTStr("There is currently a transaction in process.")}
  DOM {0C0380044h, $OfsTStr("An unexpected layout change occurred outside of the volume manager.")}
  DOM {0C0380045h, $OfsTStr("The specified volume contains a missing disk.")}
  DOM {0C0380046h, $OfsTStr("The specified volume id is invalid. There are no volumes with the specified volume id.")}
  DOM {0C0380047h, $OfsTStr("The specified volume length is invalid.")}
  DOM {0C0380048h, $OfsTStr("The specified size for the volume is not a multiple of the sector size.")}
  DOM {0C0380049h, $OfsTStr("The operation is only supported on mirrored volumes.")}
  DOM {0C038004Ah, $OfsTStr("The specified volume does not have a retain partition.")}
  DOM {0C038004Bh, $OfsTStr("The specified volume is offline.")}
  DOM {0C038004Ch, $OfsTStr("The specified volume already has a retain partition.")}
  DOM {0C038004Dh, $OfsTStr("The specified number of extents is invalid.")}
  DOM {0C038004Eh, $OfsTStr("All disks participating to the volume must have the same sector size.")}
  DOM {0C038004Fh, $OfsTStr("The boot disk experienced failures.")}
  DOM {0C0380050h, $OfsTStr("The configuration of the pack is offline.")}
  DOM {0C0380051h, $OfsTStr("The configuration of the pack is online.")}
  DOM {0C0380052h, $OfsTStr("The specified pack is not the primary pack.")}
  DOM {0C0380053h, $OfsTStr("All disks failed to be updated with the new content of the log.")}
  DOM {0C0380054h, $OfsTStr("The specified number of disks in a plex is invalid.")}
  DOM {0C0380055h, $OfsTStr("The specified number of disks in a plex member is invalid.")}
  DOM {0C0380056h, $OfsTStr("The operation is not supported on mirrored volumes.")}
  DOM {0C0380057h, $OfsTStr("The operation is only supported on simple and spanned plexes.")}
  DOM {0C0380058h, $OfsTStr("The pack has no valid log copies.")}
  DOM {0C0380059h, $OfsTStr("A primary pack is already present.")}
  DOM {0C038005Ah, $OfsTStr("The specified number of disks is invalid.")}
  DOM {0C038005Bh, $OfsTStr("The system does not support mirrored volumes.")}
  DOM {0C038005Ch, $OfsTStr("The system does not support RAID-5 volumes.")}
  DOM {0C0390002h, $OfsTStr("Entries enumerated have exceeded the allowed threshold.")}
  DOM {0C03A0001h, $OfsTStr("The virtual hard disk is corrupted. The virtual hard disk drive footer is missing.")}
  DOM {0C03A0002h, $OfsTStr("The virtual hard disk is corrupted. The virtual hard disk drive footer checksum does not match the on-disk checksum.")}
  DOM {0C03A0003h, $OfsTStr("The virtual hard disk is corrupted. The virtual hard disk drive footer in the virtual hard disk is corrupted.")}
  DOM {0C03A0004h, $OfsTStr("The system does not recognize the file format of this virtual hard disk.")}
  DOM {0C03A0005h, $OfsTStr("The version does not support this version of the file format.")}
  DOM {0C03A0006h, $OfsTStr("The virtual hard disk is corrupted. The sparse header checksum does not match the on-disk checksum.")}
  DOM {0C03A0007h, $OfsTStr("The system does not support this version of the virtual hard disk.This version of the sparse header is not supported.")}
  DOM {0C03A0008h, $OfsTStr("The virtual hard disk is corrupted. The sparse header in the virtual hard disk is corrupt.")}
  DOM {0C03A0009h, $OfsTStr("Failed to write to the virtual hard disk failed because the system failed to allocate a new block in the virtual hard disk.")}
  DOM {0C03A000Ah, $OfsTStr("The virtual hard disk is corrupted. The block allocation table in the virtual hard disk is corrupt.")}
  DOM {0C03A000Bh, $OfsTStr("The system does not support this version of the virtual hard disk. The block size is invalid.")}
  DOM {0C03A000Ch, $OfsTStr("The virtual hard disk is corrupted. The block bitmap does not match with the block data present in the virtual hard disk.")}
  DOM {0C03A000Dh, $OfsTStr("The chain of virtual hard disks is broken. The system cannot locate the parent virtual hard disk for the differencing disk.")}
  DOM {0C03A000Eh, $OfsTStr("The chain of virtual hard disks is corrupted. There is a mismatch in the identifiers of the parent virtual hard disk and differencing disk.")}
  DOM {0C03A000Fh, $OfsTStr("The chain of virtual hard disks is corrupted. The time stamp of the parent virtual hard disk does not match the time stamp of the differencing disk.")}
  DOM {0C03A0010h, $OfsTStr("Failed to read the metadata of the virtual hard disk.")}
  DOM {0C03A0011h, $OfsTStr("Failed to write to the metadata of the virtual hard disk.")}
  DOM {0C03A0012h, $OfsTStr("The size of the virtual hard disk is not valid.")}
  DOM {0C03A0013h, $OfsTStr("The file size of this virtual hard disk is not valid.")}
  DOM {0C03A0014h, $OfsTStr("A virtual disk support provider for the specified file was not found.")}
  DOM {0C03A0015h, $OfsTStr("The specified disk is not a virtual disk.")}
  DOM {0C03A0016h, $OfsTStr("The chain of virtual hard disks is inaccessible. The process has not been granted access rights to the parent virtual hard disk for the differencing disk.")}
  DOM {0C03A0017h, $OfsTStr("The chain of virtual hard disks is corrupted. There is a mismatch in the virtual sizes of the parent virtual hard disk and differencing disk.")}
  DOM {0C03A0018h, $OfsTStr("The chain of virtual hard disks is corrupted. A differencing disk is indicated in its own parent chain.")}
  DOM {0C03A0019h, $OfsTStr("The chain of virtual hard disks is inaccessible. There was an error opening a virtual hard disk further up the chain.")}
  DOM {0C03A001Ah, $OfsTStr("The requested operation could not be completed due to a virtual disk system limitation. On NTFS")}
  DOM {0C03A001Bh, $OfsTStr("The requested operation cannot be performed on a virtual disk of this type.")}
  DOM {0C03A001Ch, $OfsTStr("The requested operation cannot be performed on the virtual disk in its current state.")}
  DOM {0C03A001Dh, $OfsTStr("The sector size of the physical disk on which the virtual disk resides is not supported.")}
  DOM {0C03A001Eh, $OfsTStr("The disk is already owned by a different owner.")}
  DOM {0C03A001Fh, $OfsTStr("The disk must be offline or read-only.")}
  DOM {0C03A0020h, $OfsTStr("Change Tracking is not initialized for this Virtual Disk.")}
  DOM {0C03A0021h, $OfsTStr("Size of change tracking file exceeded the maximum size limit")}
  DOM {0C03A0022h, $OfsTStr("VHD file is changed due to compaction")}
  DOM {0C03A0023h, $OfsTStr("Change Tracking for the virtual disk is not in a valid state to perform this request. Change tracking could be discontinued or already in the requested state.")}
  DOM {0C03A0024h, $OfsTStr("Change Tracking file for the virtual disk is not in a valid state.")}
  DOM {0C03A0025h, $OfsTStr("The requested resize operation could not be completed because it might truncate user data residing on the virtual disk.")}
  DOM {0C03A0026h, $OfsTStr("The requested operation could not be completed because the virtual disk's minimum safe size could not be determined. This may be due to a missing or corrupt partition table.")}
  DOM {0C03A0027h, $OfsTStr("The requested operation could not be completed because the virtual disk's size cannot be safely reduced further.")}
  DOM {0C03A0028h, $OfsTStr("There is not enough space in the virtual disk file for the provided metadata item.")}
ComErrTableCount equ ($ - ComErrTable)/sizeof(DOM)
