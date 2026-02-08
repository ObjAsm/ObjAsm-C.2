;Symbol                     Code   Short Description                              Detailed Description
;-------------------------- ------ ---------------------------------------------- ----------------------------------------------------------------------------------------------------------------------------------------------------------------
;WSA_INVALID_HANDLE         6      Specified event object handle is invalid       An application attempts to use an event object, but the specified handle is not valid.
;WSA_NOT_ENOUGH_MEMORY      8      Insufficient memory available                  A Windows function mapped from Winsock indicates insufficient memory resources.
;WSA_INVALID_PARAMETER      87     One or more parameters are invalid             A Windows function mapped from Winsock indicates invalid parameters.
;WSA_OPERATION_ABORTED      995    Overlapped operation aborted                   The overlapped operation was canceled due to socket closure or SIO_FLUSH.
;WSA_IO_INCOMPLETE          996    Overlapped I/O not completed                   The overlapped operation has not yet completed.
;WSA_IO_PENDING             997    Overlapped operation pending                   The operation will complete later.
;WSAEINTR                   10004  Interrupted function call                      A blocking call was interrupted by WSACancelBlockingCall.
;WSAEBADF                   10009  Invalid file handle                            The supplied file handle is not valid.
;WSAEACCES                  10013  Permission denied                              Access to a socket was denied by permissions or exclusive address use.
;WSAEFAULT                  10014  Bad address                                    An invalid pointer address was supplied.
;WSAEINVAL                  10022  Invalid argument                               An invalid argument or invalid socket state was supplied.
;WSAEMFILE                  10024  Too many open files                            Too many open sockets or file descriptors.
;WSAEWOULDBLOCK             10035  Resource temporarily unavailable               A nonblocking operation could not complete immediately.
;WSAEINPROGRESS             10036  Operation in progress                          Another blocking operation is already executing.
;WSAEALREADY                10037  Operation already in progress                  A nonblocking operation is already underway.
;WSAENOTSOCK                10038  Socket operation on nonsocket                  The handle does not refer to a socket.
;WSAEDESTADDRREQ            10039  Destination address required                   A required address was not supplied.
;WSAEMSGSIZE                10040  Message too long                               The message exceeded buffer or network limits.
;WSAEPROTOTYPE              10041  Protocol wrong type for socket                 The protocol does not support the requested socket type.
;WSAENOPROTOOPT             10042  Bad protocol option                            An unsupported option or level was specified.
;WSAEPROTONOSUPPORT         10043  Protocol not supported                         The requested protocol is not available.
;WSAESOCKTNOSUPPORT         10044  Socket type not supported                      The socket type is unsupported in this address family.
;WSAEOPNOTSUPP              10045  Operation not supported                        The socket does not support this operation.
;WSAEPFNOSUPPORT            10046  Protocol family not supported                  The protocol family is unavailable.
;WSAEAFNOSUPPORT            10047  Address family not supported                   The address family is incompatible with the protocol.
;WSAEADDRINUSE              10048  Address already in use                         The address/port is already bound.
;WSAEADDRNOTAVAIL           10049  Cannot assign requested address                The address is not valid for this host.
;WSAENETDOWN                10050  Network is down                                The network subsystem has failed.
;WSAENETUNREACH             10051  Network is unreachable                         No route exists to the remote network.
;WSAENETRESET               10052  Network reset                                  The connection dropped due to network failure.
;WSAECONNABORTED            10053  Connection aborted                             The local software aborted the connection.
;WSAECONNRESET              10054  Connection reset by peer                       The remote host forcibly closed the connection.
;WSAENOBUFS                 10055  No buffer space available                      Insufficient buffer space or queue full.
;WSAEISCONN                 10056  Socket already connected                       The socket is already connected.
;WSAENOTCONN                10057  Socket not connected                           The socket is not connected.
;WSAESHUTDOWN               10058  Cannot send after shutdown                     The socket has been shut down.
;WSAETOOMANYREFS            10059  Too many references                            Too many references to a kernel object.
;WSAETIMEDOUT               10060  Connection timed out                           The connection attempt timed out.
;WSAECONNREFUSED            10061  Connection refused                             The target host refused the connection.
;WSAELOOP                   10062  Cannot translate name                          Name resolution loop detected.
;WSAENAMETOOLONG            10063  Name too long                                  A name or name component was too long.
;WSAEHOSTDOWN               10064  Host is down                                   The destination host is down.
;WSAEHOSTUNREACH            10065  No route to host                               The host is unreachable.
;WSAENOTEMPTY               10066  Directory not empty                            The directory is not empty.
;WSAEPROCLIM                10067  Too many processes                             Process limit reached.
;WSAEUSERS                  10068  User quota exceeded                            User quota exhausted.
;WSAEDQUOT                  10069  Disk quota exceeded                            Disk quota exhausted.
;WSAESTALE                  10070  Stale file handle                              File handle reference is stale.
;WSAEREMOTE                 10071  Item is remote                                 Item is not available locally.
;WSASYSNOTREADY             10091  Network subsystem unavailable                  Winsock cannot function at this time.
;WSAVERNOTSUPPORTED         10092  Winsock version not supported                  Requested Winsock version unsupported.
;WSANOTINITIALISED          10093  WSAStartup not called                          WSAStartup has not been successfully called.
;WSAEDISCON                 10101  Graceful shutdown in progress                  Remote side initiated shutdown.
;WSAENOMORE                 10102  No more results                                No more lookup results available.
;WSAECANCELLED              10103  Call canceled                                  The operation was canceled.
;WSAEINVALIDPROCTABLE       10104  Invalid procedure table                        Provider returned an invalid function table.
;WSAEINVALIDPROVIDER        10105  Invalid service provider                       The provider is invalid or missing.
;WSAEPROVIDERFAILEDINIT     10106  Provider failed to initialize                  Provider DLL failed to load or initialize.
;WSASYSCALLFAILURE          10107  System call failure                            A system call failed unexpectedly.
;WSASERVICE_NOT_FOUND       10108  Service not found                              The service name was not found.
;WSATYPE_NOT_FOUND          10109  Class type not found                           The specified class was not found.
;WSA_E_NO_MORE              10110  No more results                                No more lookup results available.
;WSA_E_CANCELLED            10111  Call canceled                                  The lookup call was canceled.
;WSAEREFUSED                10112  Database query refused                         The database query was refused.
;WSAHOST_NOT_FOUND          11001  Host not found                                 The host name could not be resolved.
;WSATRY_AGAIN               11002  Try again                                      Temporary failure in name resolution.
;WSANO_RECOVERY             11003  Nonrecoverable error                           A permanent name resolution failure.
;WSANO_DATA                 11004  No data record                                 Name exists but has no associated data.
;WSA_QOS_RECEIVERS          11005  QoS receivers                                  QoS receivers detected.
;WSA_QOS_SENDERS            11006  QoS senders                                    QoS senders detected.
;WSA_QOS_NO_SENDERS         11007  No QoS senders                                 No QoS senders available.
;WSA_QOS_NO_RECEIVERS       11008  No QoS receivers                               No QoS receivers available.
;WSA_QOS_REQUEST_CONFIRMED  11009  QoS request confirmed                          QoS reservation confirmed.
;WSA_QOS_ADMISSION_FAILURE  11010  QoS admission failure                          Admission control failed.
;WSA_QOS_POLICY_FAILURE     11011  QoS policy failure                             Policy system rejected the request.
;WSA_QOS_BAD_STYLE          11012  QoS bad style                                  Invalid or conflicting QoS style.
;WSA_QOS_BAD_OBJECT         11013  QoS bad object                                 Invalid object in provider buffer.
;WSA_QOS_TRAFFIC_CTRL_ERROR 11014  QoS traffic control error                      Traffic control API failure.
;WSA_QOS_GENERIC_ERROR      11015  QoS generic error                              General QoS error.
;WSA_QOS_ESERVICETYPE       11016  QoS service type error                         Invalid QoS service type.
;WSA_QOS_EFLOWSPEC          11017  QoS flowspec error                             Invalid flowspec.
;WSA_QOS_EPROVSPECBUF       11018  Invalid provider buffer                        Invalid provider-specific buffer.
;WSA_QOS_EFILTERSTYLE       11019  Invalid filter style                           Invalid filter style.
;WSA_QOS_EFILTERTYPE        11020  Invalid filter type                            Invalid filter type.
;WSA_QOS_EFILTERCOUNT       11021  Incorrect filter count                         Incorrect number of filters.
;WSA_QOS_EOBJLENGTH         11022  Invalid object length                          Invalid object length field.
;WSA_QOS_EFLOWCOUNT         11023  Incorrect flow count                           Incorrect number of flows.
;WSA_QOS_EUNKOWNPSOBJ       11024  Unknown QoS object                             Unrecognized provider object.
;WSA_QOS_EPOLICYOBJ         11025  Invalid policy object                          Invalid policy object.
;WSA_QOS_EFLOWDESC          11026  Invalid flow descriptor                        Invalid flow descriptor.
;WSA_QOS_EPSFLOWSPEC        11027  Invalid provider flowspec                      Invalid provider flowspec.
;WSA_QOS_EPSFILTERSPEC      11028  Invalid provider filterspec                    Invalid provider filterspec.
;WSA_QOS_ESDMODEOBJ         11029  Invalid discard mode object                    Invalid discard mode object.
;WSA_QOS_ESHAPERATEOBJ      11030  Invalid shaping rate object                    Invalid shaping rate object.
;WSA_QOS_RESERVED_PETYPE    11031  Reserved QoS element                           Reserved policy element found.
