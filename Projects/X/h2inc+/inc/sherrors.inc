;Include file created by h2inc+ version C.2.0 on (UTC) 20/05/2024 18:06:34
;(C) G. Friedrich April 2024
;Source file: d:\objasm\projects\x\h2inc+\h\um_10.0.22621.0\sherrors.h
;             Created on (UTC) 06/04/2024 06:15:58
;             Last modified on (UTC) 21/02/2024 18:17:24

; Copyright (c) Microsoft Corporation. All rights reserved.
ifndef _SHERROR_
  _SHERROR_ equ <>
  if Defined(_MSC_VER) and (_MSC_VER ge 1020) and  not Defined(__midl)
  endif
  include winapifamily.inc
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    include winerror.inc
    ;  COPYENGINE codes use FACILITY_SHELL and 0 in the second lowest byte
    ; Success/Informational codes
    COPYENGINE_S_YES equ _HRESULT_TYPEDEF_(00270001h)
    COPYENGINE_S_NOT_HANDLED equ _HRESULT_TYPEDEF_(00270003h)
    COPYENGINE_S_USER_RETRY equ _HRESULT_TYPEDEF_(00270004h)
    COPYENGINE_S_USER_IGNORED equ _HRESULT_TYPEDEF_(00270005h)
    COPYENGINE_S_MERGE equ _HRESULT_TYPEDEF_(00270006h)
    COPYENGINE_S_DONT_PROCESS_CHILDREN equ _HRESULT_TYPEDEF_(00270008h)
    COPYENGINE_S_ALREADY_DONE equ _HRESULT_TYPEDEF_(0027000Ah)
    COPYENGINE_S_PENDING equ _HRESULT_TYPEDEF_(0027000Bh)
    COPYENGINE_S_KEEP_BOTH equ _HRESULT_TYPEDEF_(0027000Ch)
    COPYENGINE_S_CLOSE_PROGRAM equ _HRESULT_TYPEDEF_(0027000Dh); Close the program using the current file

    COPYENGINE_S_COLLISIONRESOLVED equ _HRESULT_TYPEDEF_(0027000Eh); Returned by a transfer source when a collision occurs

    ; during a file operation but the source resolved the collision
    ; on the users behalf
    COPYENGINE_S_PROGRESS_PAUSE equ _HRESULT_TYPEDEF_(0027000Fh)
    COPYENGINE_S_PENDING_DELETE equ _HRESULT_TYPEDEF_(00270010h); Returned by initiating async delete operation. It's different

    ; from COPYENGINE_S_PENDING which is used for operation queued due to error.
    ; Failure/Error codes
    COPYENGINE_E_USER_CANCELLED equ _HRESULT_TYPEDEF_(80270000h); User wants to canceled entire job

    COPYENGINE_E_CANCELLED equ _HRESULT_TYPEDEF_(80270001h); Engine wants to canceled entire job, don't set the CANCELLED bit

    COPYENGINE_E_REQUIRES_ELEVATION equ _HRESULT_TYPEDEF_(80270002h); Need to elevate the process to complete the operation

    COPYENGINE_E_SAME_FILE equ _HRESULT_TYPEDEF_(80270003h); Source and destination file are the same

    COPYENGINE_E_DIFF_DIR equ _HRESULT_TYPEDEF_(80270004h); Trying to rename a file into a different location, use move instead

    COPYENGINE_E_MANY_SRC_1_DEST equ _HRESULT_TYPEDEF_(80270005h); One source specified, multiple destinations

    COPYENGINE_E_DEST_SUBTREE equ _HRESULT_TYPEDEF_(80270009h); The destination is a sub-tree of the source

    COPYENGINE_E_DEST_SAME_TREE equ _HRESULT_TYPEDEF_(8027000Ah); The destination is the same folder as the source

    COPYENGINE_E_FLD_IS_FILE_DEST equ _HRESULT_TYPEDEF_(8027000Bh); Existing destination file with same name as folder

    COPYENGINE_E_FILE_IS_FLD_DEST equ _HRESULT_TYPEDEF_(8027000Ch); Existing destination folder with same name as file

    COPYENGINE_E_FILE_TOO_LARGE equ _HRESULT_TYPEDEF_(8027000Dh); File too large for destination file system

    COPYENGINE_E_REMOVABLE_FULL equ _HRESULT_TYPEDEF_(8027000Eh); Destination device is full and happens to be removable

    COPYENGINE_E_DEST_IS_RO_CD equ _HRESULT_TYPEDEF_(8027000Fh); Destination is a Read-Only CDRom, possibly unformatted

    COPYENGINE_E_DEST_IS_RW_CD equ _HRESULT_TYPEDEF_(80270010h); Destination is a Read/Write CDRom, possibly unformatted

    COPYENGINE_E_DEST_IS_R_CD equ _HRESULT_TYPEDEF_(80270011h); Destination is a Recordable (AudioL) CDRom, possibly unformatted

    COPYENGINE_E_DEST_IS_RO_DVD equ _HRESULT_TYPEDEF_(80270012h); Destination is a Read-Only DVD, possibly unformatted

    COPYENGINE_E_DEST_IS_RW_DVD equ _HRESULT_TYPEDEF_(80270013h); Destination is a Read/Wrote DVD, possibly unformatted

    COPYENGINE_E_DEST_IS_R_DVD equ _HRESULT_TYPEDEF_(80270014h); Destination is a Recordable (AudioL) DVD, possibly unformatted

    COPYENGINE_E_SRC_IS_RO_CD equ _HRESULT_TYPEDEF_(80270015h); Source is a Read-Only CDRom, possibly unformatted

    COPYENGINE_E_SRC_IS_RW_CD equ _HRESULT_TYPEDEF_(80270016h); Source is a Read/Write CDRom, possibly unformatted

    COPYENGINE_E_SRC_IS_R_CD equ _HRESULT_TYPEDEF_(80270017h); Source is a Recordable (AudioL) CDRom, possibly unformatted

    COPYENGINE_E_SRC_IS_RO_DVD equ _HRESULT_TYPEDEF_(80270018h); Source is a Read-Only DVD, possibly unformatted

    COPYENGINE_E_SRC_IS_RW_DVD equ _HRESULT_TYPEDEF_(80270019h); Source is a Read/Wrote DVD, possibly unformatted

    COPYENGINE_E_SRC_IS_R_DVD equ _HRESULT_TYPEDEF_(8027001Ah); Source is a Recordable (AudioL) DVD, possibly unformatted

    COPYENGINE_E_INVALID_FILES_SRC equ _HRESULT_TYPEDEF_(8027001Bh); Invalid source path

    COPYENGINE_E_INVALID_FILES_DEST equ _HRESULT_TYPEDEF_(8027001Ch); Invalid destination path

    COPYENGINE_E_PATH_TOO_DEEP_SRC equ _HRESULT_TYPEDEF_(8027001Dh); Source Files within folders where the overall path is longer than MAX_PATH

    COPYENGINE_E_PATH_TOO_DEEP_DEST equ _HRESULT_TYPEDEF_(8027001Eh); Destination files would be within folders where the overall path is longer than MAX_PATH

    COPYENGINE_E_ROOT_DIR_SRC equ _HRESULT_TYPEDEF_(8027001Fh); Source is a root directory, cannot be moved or renamed

    COPYENGINE_E_ROOT_DIR_DEST equ _HRESULT_TYPEDEF_(80270020h); Destination is a root directory, cannot be renamed

    COPYENGINE_E_ACCESS_DENIED_SRC equ _HRESULT_TYPEDEF_(80270021h); Security problem on source

    COPYENGINE_E_ACCESS_DENIED_DEST equ _HRESULT_TYPEDEF_(80270022h); Security problem on destination

    COPYENGINE_E_PATH_NOT_FOUND_SRC equ _HRESULT_TYPEDEF_(80270023h); Source file does not exist, or is unavailable

    COPYENGINE_E_PATH_NOT_FOUND_DEST equ _HRESULT_TYPEDEF_(80270024h); Destination file does not exist, or is unavailable

    COPYENGINE_E_NET_DISCONNECT_SRC equ _HRESULT_TYPEDEF_(80270025h); Source file is on a disconnected network location

    COPYENGINE_E_NET_DISCONNECT_DEST equ _HRESULT_TYPEDEF_(80270026h); Destination file is on a disconnected network location

    COPYENGINE_E_SHARING_VIOLATION_SRC equ _HRESULT_TYPEDEF_(80270027h); Sharing Violation on source

    COPYENGINE_E_SHARING_VIOLATION_DEST equ _HRESULT_TYPEDEF_(80270028h); Sharing Violation on destination

    COPYENGINE_E_ALREADY_EXISTS_NORMAL equ _HRESULT_TYPEDEF_(80270029h); Destination exists, cannot replace

    COPYENGINE_E_ALREADY_EXISTS_READONLY equ _HRESULT_TYPEDEF_(8027002Ah); Destination with read-only attribute exists, cannot replace

    COPYENGINE_E_ALREADY_EXISTS_SYSTEM equ _HRESULT_TYPEDEF_(8027002Bh); Destination with system attribute exists, cannot replace

    COPYENGINE_E_ALREADY_EXISTS_FOLDER equ _HRESULT_TYPEDEF_(8027002Ch); Destination folder exists, cannot replace

    COPYENGINE_E_STREAM_LOSS equ _HRESULT_TYPEDEF_(8027002Dh); Secondary Stream information would be lost

    COPYENGINE_E_EA_LOSS equ _HRESULT_TYPEDEF_(8027002Eh); Extended Attributes would be lost

    COPYENGINE_E_PROPERTY_LOSS equ _HRESULT_TYPEDEF_(8027002Fh); Property would be lost

    COPYENGINE_E_PROPERTIES_LOSS equ _HRESULT_TYPEDEF_(80270030h); Properties would be lost

    COPYENGINE_E_ENCRYPTION_LOSS equ _HRESULT_TYPEDEF_(80270031h); Encryption would be lost

    COPYENGINE_E_DISK_FULL equ _HRESULT_TYPEDEF_(80270032h); Entire operation likely won't fit

    COPYENGINE_E_DISK_FULL_CLEAN equ _HRESULT_TYPEDEF_(80270033h); Entire operation likely won't fit, clean-up wizard available

    COPYENGINE_E_EA_NOT_SUPPORTED equ _HRESULT_TYPEDEF_(80270034h); Volume does not support Extended Attributes

    COPYENGINE_E_CANT_REACH_SOURCE equ _HRESULT_TYPEDEF_(80270035h); Can't reach source folder

    COPYENGINE_E_RECYCLE_UNKNOWN_ERROR equ _HRESULT_TYPEDEF_(80270035h); ???

    COPYENGINE_E_RECYCLE_FORCE_NUKE equ _HRESULT_TYPEDEF_(80270036h); Recycling not available (usually turned offL)

    COPYENGINE_E_RECYCLE_SIZE_TOO_BIG equ _HRESULT_TYPEDEF_(80270037h); Item is too large for the recycle-bin

    COPYENGINE_E_RECYCLE_PATH_TOO_LONG equ _HRESULT_TYPEDEF_(80270038h); Folder is too deep to fit in the recycle-bin

    COPYENGINE_E_RECYCLE_BIN_NOT_FOUND equ _HRESULT_TYPEDEF_(8027003Ah); Recycle bin could not be found or is unavailable

    COPYENGINE_E_NEWFILE_NAME_TOO_LONG equ _HRESULT_TYPEDEF_(8027003Bh); Name of the new file being created is too long

    COPYENGINE_E_NEWFOLDER_NAME_TOO_LONG equ _HRESULT_TYPEDEF_(8027003Ch); Name of the new folder being created is too long

    COPYENGINE_E_DIR_NOT_EMPTY equ _HRESULT_TYPEDEF_(8027003Dh); The directory being processed is not empty

    COPYENGINE_E_FAT_MAX_IN_ROOT equ _HRESULT_TYPEDEF_(8027003Eh); A Fat drive cannot only store and rename a limited number of items on the root.

    COPYENGINE_E_ACCESSDENIED_READONLY equ _HRESULT_TYPEDEF_(8027003Fh); The item cannot be modified because it is set to readonly.

    COPYENGINE_E_REDIRECTED_TO_WEBPAGE equ _HRESULT_TYPEDEF_(80270040h); The server redirected the download request to a web page.

    COPYENGINE_E_SERVER_BAD_FILE_TYPE equ _HRESULT_TYPEDEF_(80270041h); The server returned data with an unexpected MIME type or extension.

    COPYENGINE_E_INTERNET_ITEM_UNAVAILABLE equ _HRESULT_TYPEDEF_(80270042h); The item is unavailable currently due to no internet connectivity

    COPYENGINE_E_CANNOT_MOVE_FROM_RECYCLE_BIN equ _HRESULT_TYPEDEF_(80270043h); The item cannot be moved out of the recycle bin, can perform other operations like restored/delete

    COPYENGINE_E_CANNOT_MOVE_SHARED_FOLDER equ _HRESULT_TYPEDEF_(80270044h); The item cannot be moved from a grouped folder to another shared folder

    COPYENGINE_E_INTERNET_ITEM_STORAGE_PROVIDER_ERROR equ _HRESULT_TYPEDEF_(80270045h); The item is unavailable currently due to storage provider being in error state

    COPYENGINE_E_INTERNET_ITEM_STORAGE_PROVIDER_PAUSED equ _HRESULT_TYPEDEF_(80270046h); The item is unavailable currently due to storage provider being paused

    COPYENGINE_E_REQUIRES_EDP_CONSENT equ _HRESULT_TYPEDEF_(80270047h); The file can only be copied if the user consents to override the EDP block

    COPYENGINE_E_BLOCKED_BY_EDP_POLICY equ _HRESULT_TYPEDEF_(80270048h); The file cannot be copied per EDP policy

    COPYENGINE_E_REQUIRES_EDP_CONSENT_FOR_REMOVABLE_DRIVE equ _HRESULT_TYPEDEF_(80270049h); The file can be copied as personal if the user consents to override the EDP block

    COPYENGINE_E_BLOCKED_BY_EDP_FOR_REMOVABLE_DRIVE equ _HRESULT_TYPEDEF_(8027004Ah); The file can only be copied as work protected per EDP policy

    COPYENGINE_E_RMS_REQUIRES_EDP_CONSENT_FOR_REMOVABLE_DRIVE equ _HRESULT_TYPEDEF_(8027004Bh); The file can be copied as personal if the user consents to override the EDP block

    COPYENGINE_E_RMS_BLOCKED_BY_EDP_FOR_REMOVABLE_DRIVE equ _HRESULT_TYPEDEF_(8027004Ch); The file can only be copied as work protected per EDP policy

    COPYENGINE_E_WARNED_BY_DLP_POLICY equ _HRESULT_TYPEDEF_(8027004Dh); The file is warned against being copied per DLP policy

    COPYENGINE_E_BLOCKED_BY_DLP_POLICY equ _HRESULT_TYPEDEF_(8027004Eh); The file cannot be copied per DLP policy

    COPYENGINE_E_SILENT_FAIL_BY_DLP_POLICY equ _HRESULT_TYPEDEF_(8027004Fh); The file cannot be copied per DLP policy, and the caller is requested to silently fail

    ;  error codes without a more specific group use FACILITY_SHELL and 0x01 in the second lowest byte.
    NETCACHE_E_NEGATIVE_CACHE equ _HRESULT_TYPEDEF_(80270100h); The item requested is in the negative net parsing cache

    EXECUTE_E_LAUNCH_APPLICATION equ _HRESULT_TYPEDEF_(80270101h); for returned by command delegates to indicate that they did no work 

    SHELL_E_WRONG_BITDEPTH equ _HRESULT_TYPEDEF_(80270102h); returned when trying to create a thumbnail extractor at too low a bitdepth for high fidelity

    LINK_E_DELETE equ _HRESULT_TYPEDEF_(80270103h); returned from IShellLink::Resolve when SLR_OFFER_DELETE_WITHOUT_FILE is passed and the user requested to delete the item

    STORE_E_NEWER_VERSION_AVAILABLE equ _HRESULT_TYPEDEF_(80270104h); returned from IAppItemsStateModify to indicate a commit failed because there is newer version already available

    ; File Placeholder success and error codes
    E_FILE_PLACEHOLDER_NOT_INITIALIZED equ _HRESULT_TYPEDEF_(80270110h); The placeholder file or property store isn't initialized.

    E_FILE_PLACEHOLDER_VERSION_MISMATCH equ _HRESULT_TYPEDEF_(80270111h); The sync engine detected that the local placeholder file's version doesn't match the latest version.

    E_FILE_PLACEHOLDER_SERVER_TIMED_OUT equ _HRESULT_TYPEDEF_(80270112h); The placeholder platform timed out waiting for a stream resolver call that didn't complete in time.

    E_FILE_PLACEHOLDER_STORAGEPROVIDER_NOT_FOUND equ _HRESULT_TYPEDEF_(80270113h); The placeholder platform cannot find the storage provider for the placeholder.

    ; Camera Roll error codes
    CAMERAROLL_E_NO_DOWNSAMPLING_REQUIRED equ _HRESULT_TYPEDEF_(80270120h); The provided image didn't require downsampling because it was small enough already

    ; Error codes for when Shell denies a WinRT app activation request via Window Manager/View Manager.
    ; These should be considered subsets of NAV_E_SHELLVALIDATIONFAILED.
    ; By the time the activation request reached shell, the scenario was already over and the activation is intentionally denied (not an error).
    E_ACTIVATIONDENIED_USERCLOSE equ _HRESULT_TYPEDEF_(80270130h)
    ; The shell hit a critical error while handling the activation request and cannot process it correctly, so the activation must be denied.
    E_ACTIVATIONDENIED_SHELLERROR equ _HRESULT_TYPEDEF_(80270131h)
    ; The shell restarted while the activation was in-progress, and it is unable to process it properly.
    E_ACTIVATIONDENIED_SHELLRESTART equ _HRESULT_TYPEDEF_(80270132h)
    ; Placeholder for an unexpected error that we cannot definitively map into one of the above buckets. Not expected to fire in practice.
    E_ACTIVATIONDENIED_UNEXPECTED equ _HRESULT_TYPEDEF_(80270133h)
    ; The shell was not ready when the activation started, so the activation was aborted immediately.
    E_ACTIVATIONDENIED_SHELLNOTREADY equ _HRESULT_TYPEDEF_(80270134h)
    ; Library error/failure code
    LIBRARY_E_NO_SAVE_LOCATION equ _HRESULT_TYPEDEF_(80270200h)
    LIBRARY_E_NO_ACCESSIBLE_LOCATION equ _HRESULT_TYPEDEF_(80270201h)
    ; User Tile error/failure codes
    E_USERTILE_UNSUPPORTEDFILETYPE equ _HRESULT_TYPEDEF_(80270210h)
    ; User Tile error codes that map to the WinRT enum Windows.System.UserProfile.SetAccountPictureResult
    E_USERTILE_CHANGEDISABLED equ _HRESULT_TYPEDEF_(80270211h)
    E_USERTILE_LARGEORDYNAMIC equ _HRESULT_TYPEDEF_(80270212h)
    E_USERTILE_VIDEOFRAMESIZE equ _HRESULT_TYPEDEF_(80270213h)
    E_USERTILE_FILESIZE equ _HRESULT_TYPEDEF_(80270214h)
    ; Immersive Accessibility Docking Service Error Codes
    IMM_ACC_DOCKING_E_INSUFFICIENTHEIGHT equ _HRESULT_TYPEDEF_(80270230h)
    IMM_ACC_DOCKING_E_DOCKOCCUPIED equ _HRESULT_TYPEDEF_(80270231h)
    ; Immersive Shell Startup Failure Code
    IMSC_E_SHELL_COMPONENT_STARTUP_FAILURE equ _HRESULT_TYPEDEF_(80270233h); An immersive shell component failed to start correctly

    ; Shell Service Host Startup Failure Code
    SHC_E_SHELL_COMPONENT_STARTUP_FAILURE equ _HRESULT_TYPEDEF_(80270234h); A shell service host component failed to start correctly

    ; Tile notifications - Failure to initialize the notification platform
    E_TILE_NOTIFICATIONS_PLATFORM_FAILURE equ _HRESULT_TYPEDEF_(80270249h)
    E_SHELL_EXTENSION_BLOCKED equ _HRESULT_TYPEDEF_(80270301h)
    E_IMAGEFEED_CHANGEDISABLED equ _HRESULT_TYPEDEF_(80270310h)
    ;* WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP) *
  endif
endif
;  _SHERROR_
