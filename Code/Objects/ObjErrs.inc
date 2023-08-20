; ==================================================================================================
; Title:      ObjErrs.inc
; Author:     G. Friedrich
; Version:    C.1.0
; Purpose:    ObjAsm object error codes.
; Notes:      User error codes should have Bit 29 set.
;             See http://msdn.microsoft.com/en-us/library/ms679360(v=vs.85).aspx
;             Version C.1.0, October 2017
;               - First release.
; ==================================================================================================


; ==================================================================================================
;    Object Error Codes
; ==================================================================================================

ERROR_BASE = 0
AddErrMsg OBJ_OK,                     "No Error"

;General errors
ERROR_BASE = BIT29 + 0
AddErrMsg OBJ_OUT_OF_MEMORY,          "Out of memory"
AddErrMsg OBJ_INVALID_POINTER,        "Invalid Pointer (NULL)"
AddErrMsg OBJ_INDEX_OUT_OF_RANGE,     "Index out of range"
AddErrMsg OBJ_OPEN_ERROR,             "Open error"
AddErrMsg OBJ_READ_ERROR,             "Read error"
AddErrMsg OBJ_WRITE_ERROR,            "Write error"
AddErrMsg OBJ_FILE_NOT_FOUND,         "Specified file can not be found"

;Stream
ERROR_BASE = BIT29 + 20
AddErrMsg STM_OPEN_ERROR,             "Error opening a file"
AddErrMsg STM_READ_ERROR,             "Read beyond end of stream"
AddErrMsg STM_WRITE_ERROR,            "Can't write to stream"
AddErrMsg STM_REGISTRATION_ERROR,     "Object not found into object chain"
AddErrMsg STM_INVALID_TYPE_ID,        "Invalid object type ID (0)"
AddErrMsg STM_INCORRECT_TYPE_ID,      "Incorrect object type ID"
AddErrMsg STM_INVALID_OBJECT,         "Invalid object pointer (NULL)"
AddErrMsg STM_OVERFLOW,               "Storage capacity of stream exceeded"
AddErrMsg STM_OUT_OF_MEMORY,          "No more memory available"
AddErrMsg STM_SEEK_ERROR,             "Seek position is out of limit"
AddErrMsg STM_BUFFER_SIZE_ERROR,      "Buffer size = 0"
AddErrMsg STM_FILE_NOT_FOUND,         "Specified file can not be found"
AddErrMsg STM_SETUP_ERROR,            "Configuration parameter error (Check Init method)"

;DesLUT
ERROR_BASE = BIT29 + 35
AddErrMsg DLT_ITEM_NOT_FOUND,         "Item not found in the lookup table"
AddErrMsg DLT_OUT_OF_MEMORY,          "There is no more free memory"
AddErrMsg DLT_SETUP_ERROR,            "Error initiating DesLUT object"

;Collection
ERROR_BASE = BIT29 + 50
AddErrMsg COL_OUT_OF_MEMORY,          "There is no more free memory"
AddErrMsg COL_INDEX_ERROR,            "Index not in range [0..Count-1]"
AddErrMsg COL_OVERFLOW,               "Limit greater than maximal capacity"
AddErrMsg COL_SETUP_ERROR,            "Configuration parameter error (Check Init method)"

;Array
ERROR_BASE = BIT29 + 60
AddErrMsg ARR_OUT_OF_MEMORY,          "No more memory available"
AddErrMsg ARR_INDEX_OUT_OF_RANGE,     "Index not in range"

;RegKey
ERROR_BASE = BIT29 + 80
AddErrMsg RKY_CREATE_FAILED,          "Registry key creation failed"
AddErrMsg RKY_OPEN_FAILED,            "Opening of the registry key failed"
AddErrMsg RKY_CLOSE_FAILED,           "Closing the registry key failed"
AddErrMsg RKY_DELETE_KEY_FAILED,      "Deletion of the registry key failed"
AddErrMsg RKY_DELETE_VAL_FAILED,      "Deletion of a value failed"
AddErrMsg RKY_EXPORT_FAILED,          "Exporting registry key failed"
AddErrMsg RKY_IMPORT_FAILED,          "Importing registry key failed"
AddErrMsg RKY_GET_DW_FAILED,          "Reading a DWORD failed"
AddErrMsg RKY_GET_DATA_FAILED,        "Reading data failed"
AddErrMsg RKY_GET_STR_FAILED,         "Reading a string failed"
AddErrMsg RKY_GET_QW_FAILED,          "Reading a QWORD failed"
AddErrMsg RKY_SET_DW_FAILED,          "Writing a DWORD failed"
AddErrMsg RKY_SET_DATA_FAILED,        "Writing data failed"
AddErrMsg RKY_SET_STR_FAILED,         "Writing a string failed"
AddErrMsg RKY_SET_QW_FAILED,          "Writing a QWORD failed"

;Matrix
ERROR_BASE = BIT29 + 100
AddErrMsg MTX_SRC_COL_DIF,            "Source matrix has an invalid column number"
AddErrMsg MTX_SRC_ROW_DIF,            "Source matrix has an invalid row number"
AddErrMsg MTX_DST_COL_DIF,            "Destination matrix has an invalid column number"
AddErrMsg MTX_DST_ROW_DIF,            "Destination matrix has an invalid row number"
AddErrMsg MTX_DIF_COL_ROW,            "Rows and columns are not equal"
AddErrMsg MTX_SR_BAD_ASCII,           "Bad ASCII matrix format"
AddErrMsg MTX_INVALID_TYPE,           "Matrix Type is not acceptable"
AddErrMsg MTX_NO_UNIQUE_SOLUTION,     "Matrix is a parametric type with infinite solutions (no unique solution to be found)"

;Database
ERROR_BASE = BIT29 + 120
AddErrMsg DB_FILE_NOT_FOUND,          "File not found"
AddErrMsg DB_INVALID_FILENAME,        "File name pointer is NULL"
AddErrMsg DB_FILE_ERROR,              "Generic file error"
AddErrMsg DB_FILE_CLOSED,             "File closed"
AddErrMsg DB_FILE_ALREADY_OPEN,       "File is already open"
AddErrMsg DB_READ_ERROR,              "File read error"
AddErrMsg DB_WRITE_ERROR,             "File write error"
AddErrMsg DB_SEEK_ERROR,              "File seek error"
AddErrMsg DB_READ_BEYOND_END,         "Read past end of file"
AddErrMsg DB_READ_BEFORE_START,       "Read before file start"
AddErrMsg DB_WRITE_BEFORE_START,      "Write before file start"
AddErrMsg DB_FIELD_ERROR,             "Field defined in DB_Index not found in DB_Table"
AddErrMsg DB_FIELD_TYPE_ERROR,        "Type isn't C, N, D, L or M/Can't sort on memo fields"
AddErrMsg DB_FIELD_INDEX_ERROR,       "File index error"
AddErrMsg DB_DATA_FORMAT_ERROR,       "I.e.: 125A.23 is not a number (Type N)"
AddErrMsg DB_DATA_OVERFLOW,           "Data size is bigger than field lenght"
AddErrMsg DB_OUT_OF_MEMORY,           "Insufficient memory"
AddErrMsg DB_NOT_EMPTY,               "Database is not empty"
AddErrMsg DB_INVALID_POINTER,         "Invalid argument pointer"
AddErrMsg DB_CACHE_OUT_OF_MEMORY,     "Internal Cache has no more memory"
AddErrMsg DB_KEYSIZE_TOO_LARGE,       "Key size too large to fit at least 3 keys in 1 index block"
AddErrMsg DB_INDEX_ERROR,             "Index not in range [0..Count-1]"
AddErrMsg DB_INVALID_TEMPFILE,        "Failed to create a temp-file"
AddErrMsg DB_CANCELED,                "Operation canceled"
AddErrMsg DB_INVALID_PARAMETER,       "Invalid parameter"
AddErrMsg DB_MEMOFILE_READ_ERROR,     "Error reading in Memofile"


;DB_Query
ERROR_BASE = BIT29 + 140

;GIFDecoder / GifPlayer
ERROR_BASE = BIT29 + 160
AddErrMsg GIF_OUT_OF_MEMORY,          "Insufficient memory"
AddErrMsg GIF_RES_NOT_FOUND,          "Resource not found"
AddErrMsg GIF_RES_LOAD_ERROR,         "Resource load error"
AddErrMsg GIF_FILE_NOT_FOUND,         "File not found"
AddErrMsg GIF_FILE_LOAD_ERROR,        "File load error"
AddErrMsg GIF_WRONG_SIGNATURE,        "Not a GIF"
AddErrMsg GIF_FORMAT_ERROR,           "GIF format error"
AddErrMsg GIF_MISSING_COLOR_TABLE,    "Color table is missing"
AddErrMsg GIF_UNKNOWN_BLOCK,          "Unknown block found"
AddErrMsg GIF_DECODER_ERROR,          "Decoder error"

;IniFile
ERROR_BASE = BIT29 + 180
AddErrMsg INI_INIT_ERROR,             "Initialization error"
AddErrMsg INI_READ_ERROR,             "Read error"
AddErrMsg INI_WRITE_ERROR,            "Write Error"

;RgnButton
ERROR_BASE = BIT29 + 200
AddErrMsg RGB_NO_RES,                 "No resource found"
AddErrMsg RGB_RES_ERROR,              "Resorce error"
AddErrMsg RGB_RES_BMP_ERROR,          "Bitmap resource error"

;IDL (PIDL)
ERROR_BASE = BIT29 + 220
AddErrMsg IDL_OUT_OF_MEMORY,          "Insufficient memory"

;IAT hooking
ERROR_BASE = BIT29 + 240
AddErrMsg IHK_PROC_NOT_FOUND,         "Procedure not found"
AddErrMsg IHK_MEM_WRITE_ERROR,        "Error while writing to memory"

;COM objects
ERROR_BASE = BIT29 + 260
AddErrMsg COM_INTERFACE_REF_ERROR,    "Attempt to decrease the count below zero"
AddErrMsg COM_SERVER_LOCK_ERROR,      "Attempt to decrease the count below zero"
AddErrMsg COM_DLL_REFCNT_ERROR,       "Attempt to decrease the count below zero"

;RadASM Addin
ERROR_BASE = BIT29 + 280
AddErrMsg RAA_INVALID_FILE,           "Invalid file"
AddErrMsg RAA_MENUID_NOT_FOUND,       "Menu resource not found"
AddErrMsg RAA_MENU_APPEND_FAILED,     "Append menu failed"

;LinkedList
ERROR_BASE = BIT29 + 300
AddErrMsg LLT_INDEX_ERROR,            "Index not in range [0..Count-1]"
AddErrMsg LLT_OUT_OF_MEMORY,          "No more memory available"
AddErrMsg LLT_NOT_FOUND    ,          "Object not found"

;LinkedMemberList
ERROR_BASE = BIT29 + 320
AddErrMsg LML_INDEX_ERROR,            "Index not in range [0..Count-1]"
AddErrMsg LML_INVALID_OBJECT,         "Invalid object pointer (NULL)"

;MsgInterceptor
ERROR_BASE = BIT29 + 340
AddErrMsg MIP_SETPROP_ERROR,          "SetProp failed"

;IoPort
ERROR_BASE = BIT29 + 360
AddErrMsg IOP_SCM_CONNECTION_FAILED,  "Connecting to the Service Control Manager failed"
AddErrMsg IOP_DRIVER_REG_FAILED,      "Driver registration failed"
AddErrMsg IOP_DRIVER_START_FAILED,    "Driver start failed"
AddErrMsg IOP_DEVICE_OPEN_FAILED,     "Driver open failed"
AddErrMsg IOP_SCM_CLOSE_FAILED,       "Closing the Service Control Manager failed"
AddErrMsg IOP_SERVICE_STOP_FAILED,    "Stoping the Driver Service failed"
AddErrMsg IOP_SERVICE_CLOSE_FAILED,   "Closing the Driver Service failed"
AddErrMsg IOP_SERVICE_DELETE_FAILED,  "Deleting the Driver Service failed"
AddErrMsg IOP_DEVICE_CLOSE_FAILED,    "Closing the Driver Device failed"

;PNG
ERROR_BASE = BIT29 + 380
AddErrMsg PNG_OUT_OF_MEMORY,          "No more memory available"
AddErrMsg PNG_NOTHING_LOADED,         "No data has been loaded"
AddErrMsg PNG_INVALID_PNG,            "Corrupt or invalid PNG"
AddErrMsg PNG_UNSUPPORTED,            "PNG format not supported"
AddErrMsg PNG_INVALID_FORMAT,         "Invalid format specified"
AddErrMsg PNG_WRONG_STATE,            "Function call at the wrong time"
AddErrMsg PNG_NO_PALETTE,             "Palette requested for a non-paletted image"
AddErrMsg PNG_INVALID_PARAMETER,      "Invalid parameter"
AddErrMsg PNG_CREATE_BITMAP_ERROR,    "Couldn't create bitmap"
AddErrMsg PNG_RES_NOT_FOUND,          "Resource not found"
AddErrMsg PNG_RES_LOAD_ERROR,         "Resource load error"
AddErrMsg PNG_RES_LOCK_ERROR,         "Resource lock error"
AddErrMsg PNG_RES_SIZE_ERROR,         "Wrong resource size"
AddErrMsg PNG_FILE_READ_ERROR,        "File read error"
AddErrMsg PNG_FILE_SIZE_ERROR,        "Wrong file size"
AddErrMsg PNG_FILE_OPEN_ERROR,        "Error opening a file"

;JPG
ERROR_BASE = BIT29 + 400
AddErrMsg JPG_RES_NOT_FOUND,          "Resource not found"
AddErrMsg JPG_RES_LOAD_ERROR,         "Resource load error"
AddErrMsg JPG_RES_LOCK_ERROR,         "Resource lock error"
AddErrMsg JPG_RES_SIZE_ERROR,         "Wrong resource size"
AddErrMsg JPG_OUT_OF_MEMORY,          "No more memory available"
AddErrMsg JPG_FILE_LOAD_ERROR,        "Error while loading the file"
AddErrMsg JPG_DECODE_ERROR,           "Error while decoding the image"

;NTCompressor
ERROR_BASE = BIT29 + 420
AddErrMsg NTC_NO_WINNT,               "OS is not Windows NT based"
AddErrMsg NTC_UNSUPPORTED_API,        "API is not supported in this OS"
AddErrMsg NTC_OUT_OF_MEMORY,          "No more memory available"
AddErrMsg NTC_BUFFER_TOO_SMALL,       "Buffer is too small"
AddErrMsg NTC_COMPRESSON_FAILED,      "Compression failed"
AddErrMsg NTC_DECOMPRESSION_FAILED,   "Decompression failed"
AddErrMsg NTC_INVALID_POINTER,        "Argument pointer is invalid (NULL)"
AddErrMsg NTC_INVALID_FORMAT,         "Specified format is not suppored"

;NTFileCompressor
ERROR_BASE = BIT29 + 440
AddErrMsg NFC_OUT_OF_MEMORY,          "No more memory available"
AddErrMsg NFC_INVALID_POINTER,        "Invalid argument pointer (NULL)"
AddErrMsg NFC_WRONG_SIGNATURE,        "Wrong file signature - not a nfc file"
AddErrMsg NFC_OPEN_FAILED,            "Failed opening a file"
AddErrMsg NFC_INVALID_FILENAME,       "Invalid file name"

;Fireworks
ERROR_BASE = BIT29 + 460
AddErrMsg FWK_OUT_OF_MEMORY,          "No more memory available"

;Pixelmap
ERROR_BASE = BIT29 + 480
AddErrMsg PXM_INIT_FAILED,            "Object initialization failed"
AddErrMsg PXM_OUT_OF_MEMORY,          "No more memory available"
AddErrMsg PXM_OUT_OF_X_RANGE,         "X coordinate bigger than pixelmap width"
AddErrMsg PXM_OUT_OF_Y_RANGE,         "Y coordinate bigger than pixelmap height"
AddErrMsg PXM_INVALID_BMP_HANDLE,     "Invalid Bitmap HANDLE"
AddErrMsg PXM_INVALID_WND_HANDE,      "Invalid Window HANDLE"
AddErrMsg PXM_INVALID_DC_HANDLE,      "Invalid Device Context HANDLE"
AddErrMsg PXM_INVALID_FILE_FORMAT,    "File format is not supported"
AddErrMsg PXM_INVALID_ADDR_MODE,      "Invalid addressing mode"
AddErrMsg PXM_INVALID_POINTER,        "Invalid pointer (NULL)"
AddErrMsg PXM_INVALID_GAMMATABLE,     "Gamma Tables are not properly initialized"
AddErrMsg PXM_INVALID_FILENAME,       "The filename is invalid"
AddErrMsg PXM_FILENAME_TOO_LONG,      "The filename is too long"
AddErrMsg PXM_STREAMLOAD_FAILED,      "Stream load failed"
AddErrMsg PXM_FILEOPEN_FAILED,        "CreateFile failed"
AddErrMsg PXM_FILEWRITE_FAILED,       "WriteFile failed"
AddErrMsg PXM_LOADBMP_FAILED,         "Loading a BMP failed"
AddErrMsg PXM_LOADFILE_FAILED,        "Loading a file failed"
AddErrMsg PXM_IPICTURE_FAILED,        "IPicture COM Object failed"

;DataPool
ERROR_BASE = BIT29 + 500
AddErrMsg DPL_OUT_OF_MEMORY,          "No more memory available"
AddErrMsg DPL_BLOB_TOO_SMALL,         "Blob size is too small"
AddErrMsg DPL_WRONG_ITEM_POINTER,     "Item pointer doesnt belong to DataPool"
AddErrMsg DPL_STREAM_ALLOC_ERROR,     "Can't allocate requested memory page(s)"
AddErrMsg DPL_STREAM_READ_ERROR,      "Can't read stream correctly"
AddErrMsg DPL_STREAM_WRITE_ERROR,     "Can't write to stream"

;XML handling objects
ERROR_BASE = BIT29 + 520
AddErrMsg XML_WRONG_TAG,              "XML tags out of order"
AddErrMsg XML_OUT_OF_MEMORY,          "No more memory available"

;SharedMemoryObject
ERROR_BASE = BIT29 + 540
AddErrMsg SMO_CREATE_ERROR,           "Failed to create the SMO"
AddErrMsg SMO_MAPPING_ERROR,          "Failed to map the SMO"

;XTreeView
ERROR_BASE = BIT29 + 560
AddErrMsg XTV_INVALID_POINTER,        "Invalid pointer (NULL)"
AddErrMsg XTV_UNKNOWN_INSERTION_MODE, "Invalid insertion mode"

;MSChart
ERROR_BASE = BIT29 + 570
AddErrMsg MSC_INIT_FAILED,            "MSChart initialization failed"

;Direct D3D
ERROR_BASE = BIT29 + 600
AddErrMsg D3D_INIT_FAILED,            "D3D initialization failed"
AddErrMsg D3D_OUT_OF_MEMORY,          "No more memory available"
AddErrMsg D3D_INVALID_POINTER,        "Invalid pointer (NULL)"
AddErrMsg D3D_INVALID_RENDER_TYPE,    "Invalid Render state type"
AddErrMsg D3D_INVALID_SAMPLER_STAGE,  "Invalid Sampler stage"
AddErrMsg D3D_INVALID_SAMPLER_TYPE,   "Invalid Sampler state type"
AddErrMsg D3D_SETFVF_FAILED,          "SetFVF failed"
AddErrMsg D3D_SETRS_FAILED,           "SetRS failed"
AddErrMsg D3D_SETSS_FAILED,           "SetSS failed"
AddErrMsg D3D_SETTSS_FAILED,          "SetTSS failed"
AddErrMsg D3D_INVALID_OBJECT,         "Invalid object"
AddErrMsg D3D_INVALID_CAPACITY,       "Invalid buffer capacity"
AddErrMsg D3D_INVALID_DEVICE,         "D3D device has a problem"
AddErrMsg D3D_INVALID_POSITION,       "Invalid buffer position"
AddErrMsg D3D_INVALID_FORMAT,         "Invalid buffer format"
AddErrMsg D3D_BUFFER_LOCK_FAILED,     "Buffer lock failed"
AddErrMsg D3D_BUFFER_UNLOCK_FAILED,   "Buffer unlock failed"
AddErrMsg D3D_INVALID_BUFFER,         "Buffer is invalid"
AddErrMsg D3D_BUFFER_TOO_SMALL,       "Buffer is too small"
AddErrMsg D3D_BUFFER_LOAD_FAILED,     "Buffer stream load failed"
AddErrMsg D3D_FILE_LOAD_FAILED,       "Failed to load file"
AddErrMsg D3D_MESH_CREATE_FAILED,     "Mesh creation failed"
AddErrMsg D3D_INVALID_3DXML_FILE,     "Invalid 3DXML file"
AddErrMsg D3D_INVALID_INDEX,          "The index is out of range"
AddErrMsg D3D_FONT_INIT_FAILED,       "Failed to initialize the font object"


;Direct Input
ERROR_BASE = BIT29 + 620
AddErrMsg DI_INIT_FAILED,             "DI initialization failed"
AddErrMsg DI_OUT_OF_MEMORY,           "No more memory available"
AddErrMsg DI_KEYBOARD_FAILED,         "Keyboard initialization failed"
AddErrMsg DI_MOUSE_FAILED,            "Mouse initialization failed "
AddErrMsg DI_JOYSTICK_FAILED,         "Joystick initialization failed "
AddErrMsg DI_KEYBOARD_STATE_FAILED,   "Failed to get the keyboard state"
AddErrMsg DI_MOUSE_STATE_FAILED,      "Failed to get the mouse state"
AddErrMsg DI_JOYSTICK_STATE_FAILED,   "Failed to get the joystick state"
AddErrMsg DI_WRONG_BUTTON_INDEX,      "The requested button doesn't exist"

;D3D_MeshManager
ERROR_BASE = BIT29 + 640
AddErrMsg MMR_OUT_OF_MEMORY,          "No more memory available"
AddErrMsg MMR_INVALID_POINTER,        "Invalid pointer (NULL)"

;D3D_VectorManager
ERROR_BASE = BIT29 + 660
AddErrMsg VCM_OUT_OF_MEMORY,          "No more memory available"

;D3D_VectorGroup
ERROR_BASE = BIT29 + 680
AddErrMsg VCG_OUT_OF_MEMORY,          "No more memory available"
AddErrMsg VCG_INVALID_DIR_VECTOR,     "Invalid direction vector {0,0,0}"
AddErrMsg VCG_INVALID_POINTER,        "Invalid pointer (NULL)"


;Red-Black Tree
ERROR_BASE = BIT29 + 690
AddErrMsg RBT_INVALID_POINTER,        "Invalid pointer (NULL)"
AddErrMsg RBT_OUT_OF_MEMORY,          "No more memory available"
AddErrMsg RBT_NON_UNIQUE_KEY,         "The specified key is already present"
AddErrMsg RBT_OBJ_NOT_FOUND,          "Object can not be found on the R-B Tree"

;OcxContainer
ERROR_BASE = BIT29 + 700
AddErrMsg OCT_INVALID_POINTER,        "Invalid pointer (NULL)"
AddErrMsg OCT_OUT_OF_MEMORY,          "No more memory available"
AddErrMsg OCT_COCREATEINSTANCE_FAILED,"CoCreateInstance failed to create the requested object"

;OcxClientSite
ERROR_BASE = BIT29 + 710
AddErrMsg OCS_INVALID_POINTER,        "Invalid pointer (NULL)"
AddErrMsg OCS_OUT_OF_MEMORY,          "No more memory available"

;RegEx
ERROR_BASE = BIT29 + 720
AddErrMsg REX_INIT_FAILED,            "Initialization failed"
AddErrMsg REX_OUT_OF_MEMORY,          "No more memory available"

;Autobuffer
ERROR_BASE = BIT29 + 730
AddErrMsg ABF_OUT_OF_MEMORY,          "No more memory available"
AddErrMsg ABF_MEMORY_EXHAUSTED,       "Internal buffer limit reached"

;StringManager
ERROR_BASE = BIT29 + 740
AddErrMsg SMR_INIT_FAILED,            "Object initialization failed"
AddErrMsg SMR_OUT_OF_MEMORY,          "No more memory available"
AddErrMsg SMR_INVALID_ENCODING,       "Invalid string encoding"
AddErrMsg SMR_INVALID_HANDLE,         "Invalid string HANDLE"
AddErrMsg SMR_INVALID_POINTER,        "Invalid pointer"
AddErrMsg SMR_INVALID_ARGUMENT,       "Invalid argument"
AddErrMsg SMR_INVALID_INDEX,          "Invalid character index"
AddErrMsg SMR_RES_NOT_FOUND,          "Resource not found"
AddErrMsg SMR_INVALID_PREFIX,         "Prefix circular reference"
AddErrMsg SMR_INVALID_SUFFIX,         "Suffix circular reference"
AddErrMsg SMR_BUFFER_TOO_SMALL,       "External buffer too small"

;HashMap
ERROR_BASE = BIT29 + 750
AddErrMsg HMP_OUT_OF_MEMORY,          "No more memory available"
AddErrMsg HMP_INVALID_ARGUMENT,       "Invalid argument"
AddErrMsg HMP_MAP_FULL,               "Map is full"
AddErrMsg HMP_NO_ITEM_FOUND,          "No item found"

;CE_KeywordCollection
ERROR_BASE = BIT29 + 760
AddErrMsg KWC_OUT_OF_MEMORY,          "No more memory available"

;CE_TextLine
ERROR_BASE = BIT29 + 770
AddErrMsg CET_OUT_OF_MEMORY,          "No more memory available"

;CE_View
ERROR_BASE = BIT29 + 780
AddErrMsg CEV_OUT_OF_MEMORY,          "No more memory available"

;CodeEditor
ERROR_BASE = BIT29 + 790
AddErrMsg CED_OUT_OF_MEMORY,          "No more memory available"

;IAT_Hook
ERROR_BASE = BIT29 + 800
AddErrMsg IHK_MEMWRITEERROR,          "Memory write error"
AddErrMsg IHK_PROCNOTFOUND,           "IAT procedure entry not found" 
