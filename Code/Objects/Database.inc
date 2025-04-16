; ==================================================================================================
; Title:      Database.inc
; Author:     G. Friedrich
; Version:    C.1.1
; Purpose:    ObjAsm object cluster to support Database tables, indexes and queries.
; Notes:      Version C.1.1, August 2019
;             - First release.
; Links:      - http://en.wikipedia.org/wiki/DBase
;             - http://www.sxlist.com/techref/language/dbase/ndxs.htm
;             - http://www.dbfree.org/webdocs/1-documentation/a-about_indexes.htm
;             - https://devblogs.microsoft.com/oldnewthing/20140306-00/?p=1583
; ==================================================================================================

;To Do:       - Skip does not use the leaf link but updates the InfoStack!
;             - Create both ascending and descending order indexes


DB_DEFAULT_SECTOR_SIZE      equ   512         ;Advanced Format => 4096 Byte; SSD => 4 MB
DB_DEFAULT_MEMO_BLOCK_LEN   equ   512

DB_INDEX_KEY_SIZE_MAX       equ   100
DB_FIELD_KEY_SIZE_MAX       equ   512 - 24
DB_FIELD_NAME_LENGTH        equ   10          ;10 ANSI characters
DB_FIELD_NAME_SIZE          equ   DB_FIELD_NAME_LENGTH + 1  ;FieldName is zero terminated

if TRUE
  ;echo "full memory ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"
  DB_RECORD_CACHE_SIZE_INI  equ   3000000
  DB_RECORD_CACHE_SIZE_INC  equ   3000000
  DB_RECORD_CACHE_SIZE_MAX  equ   COL_MAX_CAPACITY

  DB_BLOCK_CACHE_SIZE_INI   equ   100
  DB_BLOCK_CACHE_SIZE_INC   equ   100
  DB_BLOCK_CACHE_SIZE_MAX   equ   COL_MAX_CAPACITY

  NX_BLOCK_CACHE_SIZE_INI   equ   1000
  NX_BLOCK_CACHE_SIZE_INC   equ   1000
  NX_BLOCK_CACHE_SIZE_MAX   equ   COL_MAX_CAPACITY
else
  ;echo "reduced memory -------------------------------------------------------------"
  DB_RECORD_CACHE_SIZE_INI  equ   10
  DB_RECORD_CACHE_SIZE_INC  equ   10
  DB_RECORD_CACHE_SIZE_MAX  equ   100

  DB_BLOCK_CACHE_SIZE_INI   equ   1
  DB_BLOCK_CACHE_SIZE_INC   equ   1
  DB_BLOCK_CACHE_SIZE_MAX   equ   10

  NX_BLOCK_CACHE_SIZE_INI   equ   1
  NX_BLOCK_CACHE_SIZE_INC   equ   1
  NX_BLOCK_CACHE_SIZE_MAX   equ   10          ;Must have at least room for 4 blocks in memory
endif

LE_TEST                     equ   0
EQ_TEST                     equ   1
GT_TEST                     equ   2

DBT_EOF_MARKER              equ   1Ah         ;End of file marker
DBT_EOH_MARKER              equ   0Dh         ;End of header marker after DB_DATAFILE_DESCRIPTOR + 
                                              ;n*FIELD_INFO
DBM_EOF_MARKER              equ   1Ah         ;End of file marker
DBM_EOH_MARKER              equ   0Dh         ;End of header marker 


;DB_Table flags
DBT_HEADER_CHANGED          equ   BIT00
DBT_USE_STD_FIELD_LENGTHS   equ   BIT01

;DB_Record flags
DBR_DATA_CHANGED            equ   BIT00

;DB_Memo flags
DBM_HEADER_CHANGED          equ   BIT00

;DB_Memo_Block flags
DBB_DATA_CHANGED            equ   BIT00

;DB_Index flags
NDX_HEADER_CHANGED          equ   BIT00

;NdxMemBlock flags
NMB_DATA_CHANGED            equ   BIT00
NMB_READ_ONLY               equ   BIT01

;NDX_BLOCK flags
NBF_LEAF_BLOCK              equ   BIT00
NBF_UNUSED                  equ   BIT01

DB_DATA_LINK_TYPE typedef DWORD
DB_DATA_LINK_SIZE = sizeof(DB_DATA_LINK_TYPE)
PDB_DATA_LINK_TYPE typedef ptr DB_DATA_LINK_TYPE

DB_MEMO_LINK_TYPE typedef DWORD
DB_MEMO_LINK_SIZE = sizeof(DB_MEMO_LINK_TYPE)
PDB_MEMO_LINK_TYPE typedef ptr DB_MEMO_LINK_TYPE

NDX_LINK_TYPE typedef DWORD
NDX_LINK_SIZE = sizeof(NDX_LINK_TYPE)
PNDX_LINK_TYPE typedef ptr NDX_LINK_TYPE

APP_SETUP struct 1
  dLocale             DWORD     ?
  bDateFormat         BYTE      ?         ;FDF_DD?MM?YYYY
  cDateSeparator      CHR       ?         ;"/"
  cTimeSeparator      CHR       ?         ;":"
  cDecimalSeparator   CHR       ?         ;"."
APP_SETUP ends
PAPP_SETUP typedef ptr APP_SETUP

FIELD_NAME_BUFFER struct 1
  CHRA  DB_FIELD_NAME_SIZE DUP(?)
FIELD_NAME_BUFFER ends

DB_DATAFILE_DESCRIPTOR struc 1            ;Size = 32 bytes
  bFileID             BYTE      3         ;Bit 0-2: 3 = dBase level 5, 4 = level 7, Bit 7: memo file
  bUpdateYear         BYTE      0         ;0 means 1900 => 1900..2155
  bUpdateMonth        BYTE      0         ;
  bUpdateDay          BYTE      0         ;
  dNumRecs            DWORD     0         ;Number of records in the database
  wHeaderLen          WORD      33        ;Header size, including field descriptors & terminator
  wRecordLen          WORD      0         ;Record size including deletion mark
  wReserved_00        WORD      0         ;Reserved, always zero
  bTransaction        BYTE      0         ;Flag indicating incomplete dBASE IV transaction.
  bEncrypted          BYTE      0         ;0: Normal visible, 1: Encrypted (not implemented yet)
  bLAN                BYTE      12 dup (0);Reserved for multi-user processing.
  bNdxOnDemand        BYTE      0         ;FALSE => autoupdate indexes / TRUE => only on demand
  bDriverID           BYTE      3         ;Language Driver
                                          ; 0: ignore
                                          ; 1: Codepage  427 DOS USA
                                          ; 2: Codepage  850 DOS multi-lingual
                                          ; 3: Codepage 1250 Windows EE
                                          ; 8: Codepage 1252 Windows ANSI
  wReserved_01        WORD      ?         ;Reserved, always zero
DB_DATAFILE_DESCRIPTOR ends

DB_RECORD struct 1
  bDeletionMark       BYTE      " "
  bData               BYTE      0 dup (0)
DB_RECORD ends

;Symbol| Data Typ  | Byte Size | Description
;  B   | Binary    |     10    | ANSI digits representing a memo block number. The number is stored
;      |           |           | as a string, right justified and padded with blanks (*)
;  C   | Character |      n    | All OEM code page characters - padded with blanks to the width of
;      |           |           | the field. Max. 254 for dBase III compatibility.
;  D   | Date      |      8    | Date stored as a string in the format YYYYMMDD.
;  F   | Float     |      4    | No conversions, stored as a REAL4.
;  G   | OLE       |     10    | ANSI digits representing a memo block number. The number is stored
;      |           |           | as a string, right justified and padded with blanks (*)
;  I   | Long      |      4    | Sored in binary format.
;  L   | Logical   |      1    | Initialized to 0x20 (space) otherwise Y, y, N, n, T, t, F, or f.
;  N   | Numeric   |      n    | Number stored as a string, right justified, and padded with blanks
;      |           |           | up to the width of the field.
;  M   | Memo      |     10    | Index of memo block in accompanying memo file, stored as
;      |           |           | either an ANSI string padded with spaces (*).
;  O   | Double    |      8    | No conversions, stored as a REAL8.
;  Y   | Currency  |      8    | Floating point number, stored as binary in (usually) 8 bytes.
;  W   | WIDE Char |      n    | WIDE (2) characters - padded with blanks to the width of
;      |           |           | the field.
;  8   | UTF8 Char |      n    | UTF8 characters - padded with blanks to the width of
;      |           |           | the field.
;  @   | Timestamp |      8    | First DWORD is for the date and the second DWORD for the time.
;      |           |           | The date is the number of days since 01/01/4713 BC (Julian Day).
;      |           |           | Time is hours*3600000L + minutes*60000L + Seconds*1000L.
;  +   | Autoincr. |      4    | Same as a Long.
;
; Note: (*) Later versions store the memo index as a DWORD.

;Field Data Type enumeration
FDT_BINARY            equ       "B"       ;Blob
FDT_CHAR_ANSI         equ       "C"
FDT_DATE              equ       "D"
FDT_REAL4             equ       "F"
FDT_OLE               equ       "G"       ;Blob
FDT_SDWORD            equ       "I"
FDT_BOOL              equ       "L"
FDT_MEMO_ANSI         equ       "M"       ;Memo
FDT_NUMERIC           equ       "N"
FDT_REAL8             equ       "O"
FDT_REAL10            equ       "T"
FDT_CURRENCY          equ       "Y"
FDT_CHAR_WIDE         equ       "W"
FDT_CHAR_UTF8         equ       "8"
FDT_TIMESTAMP         equ       "@"
FDT_AUTOINC           equ       "+"

STD_FIELD_INFO struc 1
  bType       BYTE    ?
  bLength     BYTE    ?                   ;If = zero => length has to be read from file.
  bTestMode   BYTE    ?
  bFlags      BYTE    ?
  pDesc       PSTRING ?
  bFillType   BYTE    ?
  bMaxInput   BYTE    ?                   ;Max input length (EDIT control)
STD_FIELD_INFO ends
PSTD_FIELD_INFO typedef ptr STD_FIELD_INFO

DB_FIELD_DESCRIPTOR struc 1               ;Size = 32 bytes
  bName               FIELD_NAME_BUFFER {};Unique, non empty name
                                          ;(not case sensitive), filled with 0s.
  bType               BYTE      0         ;FDT_xxx = C, N, D, L, M  (B, @, I, +, F, 0, G)
  dReserved           DWORD     0         ;Usually zero in most implementations
  bLength             BYTE      0         ;Field size in bytes
  bDecimals           BYTE      0         ;Usually 2 (this value does not increment the bLength)
  wLAN_00             WORD      0
  bWorkAreaID         BYTE      0
  wLAN_01             WORD      0
  bFlags              BYTE      0
  dAutoIncrement      DWORD     0         ;Next value that can be used
  bReserved           BYTE      4 dup (0)
DB_FIELD_DESCRIPTOR ends

;Field Date Format enumeration
FDF_DD?MM?YYYY        equ       0
FDF_DD?MM?YY          equ       1
FDF_MM?DD?YYYY        equ       2
FDF_MM?DD?YY          equ       3
FDF_YYYY?MM?DD        equ       4
FDF_YY?MM?DD          equ       5
FDF_END_OF_TABLE      equ       -1        ;Marker


;Key Test Mode
KTM_ANSI              equ       0
KTM_WIDE              equ       1
KTM_UTF8              equ       2
KTM_BIN               equ       3
KTM_REAL              equ       4
KTM_NONE              equ       5

NDX_ENTRY struc 1
  union
    struct
      union
        dRecNo        DB_DATA_LINK_TYPE ? ;RecNo with the matching key
        dLE_BlockNo   NDX_LINK_TYPE   ?   ;BlockNo containing smaller keys
      ends
      bKey            CHRA      0 dup (0) ;Max size = DB_INDEX_KEY_SIZE_MAX
    ends
    dGT_BlockNo       NDX_LINK_TYPE   ?   ;BlockNo containing bigger keys
    dNextLeafBlockNo  NDX_LINK_TYPE   ?   ;BlockNo of the next leaf block
    dNextFreeBlockNo  NDX_LINK_TYPE   ?   ;BlockNo of the next free block
  ends
NDX_ENTRY ends
PNDX_ENTRY typedef ptr NDX_ENTRY

NDX_BLOCK struc 1                         ;Size = SECTOR_SIZE in bytes; BYTE alignment
  union
    struct
      wKeyCount       WORD      ?         ;Actual number of keys in the block
      wFlags          WORD      ?         ;NBF_xxx block flags
    ends
  ends
  Entries             NDX_ENTRY 0 dup (?) ;This serves to get the offset of the following NDX_ENTRYs
                                          ;After the NDX_ENTRYs, the last DWORD is the GT_BlockNo
NDX_BLOCK ends                            ;The block size must hold at least 3 entries!

STACK_INFO struc 1
  dInfo1              NDX_LINK_TYPE ?
  dInfo2              DWORD     ?
STACK_INFO ends

NDX_HEADER struc 1                        ;Size = SECTOR_SIZE bytes
  dRootBlockNo        NDX_LINK_TYPE ?     ;00-03: Tree root block number
  dFreeBlockNo        NDX_LINK_TYPE ?     ;04-07: First unused block number. 0 means to grow the ndx
  dBlockLength        DWORD     ?         ;08-11: Usually reserved. Used to store the block size
  wKeyLength          WORD      ?         ;12-13: Key length (<= DB_INDEX_KEY_SIZE_MAX in # of bytes)
  wKeysPerBlock       WORD      ?         ;14-15: Keys per block. Must be more than 0!
  bFieldDataType      BYTE      ?         ;16: See Field Data Type enumeration
  bD1                 BYTE      ?         ;17: Reserved
  wEntryLength        WORD      ?         ;18-19: Length of entry
  wD2                 WORD      ?         ;20-21: Reserved
  wUnique             WORD      ?         ;22-23: Flag if index on unique keys only
  bKeyField           CHRA      0 dup (?) ;Zero terminated lowercase key expression, usually the
NDX_HEADER ends                           ;   DB_Field.bName
PNDX_HEADER typedef ptr NDX_HEADER


DB_MEMOFILE_DESCRIPTOR struc 1
  dSignature          DWORD     "OMEM"
  dVersion            DWORD     1  
  dBlockLen           DWORD     DB_DEFAULT_MEMO_BLOCK_LEN
  dNextAvailBlockNo   DB_MEMO_LINK_TYPE 0 ;0 means that a new block must be taken from EOF
  dLastBlockNo        DWORD     0
  bMarker             BYTE      DBM_EOH_MARKER
DB_MEMOFILE_DESCRIPTOR ends

DB_MEMO_BLOCK struct 1
  dUsed               DWORD     ?         ;Max = dBlockLen - sizeof(DB_MEMO_BLOCK)
  dNextBlockNo        DB_MEMO_LINK_TYPE ?
  bData               BYTE      0 dup (?)
DB_MEMO_BLOCK ends

; --------------------------------------------------------------------------------------------------
; Object:     DB_MemoBlock
; Purpose:    A database memo record is a set of large information. This object manages
;             a single record within the memo file.
; Note:       The record number ranges from 1 to the current number of records in the database.
;             Record number zero is used for special purposes and is considdered an invalid record
;             number.

Object DB_MemoBlock, DB_MemoBlockID, Primer
  RedefineMethod    Init,           POINTER, DB_MEMO_LINK_TYPE  ;-> DB_MemoBlockCache, BlockNo
  StaticMethod      Read                                    ;Read from disk
  StaticMethod      Write,          XWORD, XWORD            ;Write to disk

  DefineVariable    dBlockNo,       DB_MEMO_LINK_TYPE,0     ;Range [1..Number of blocks]
  DefineVariable    dFlags,         DWORD,            0
  DefineVariable    Buffer,         DB_MEMO_BLOCK,    0 dup (0) ;Buffer serves only as a label
ObjectEnd                                                   ;at the end of this object


; --------------------------------------------------------------------------------------------------
; Object:     DB_MemoBlockCache
; Purpose:    A record cache is a in-memory managed memo block pool. Its purpose is to speedup the
;             record information access. This is implemented using an ageing scheme to write back
;             old information to the database. A circular doubly linked list (CDLL) with one pointer
;             to the last accessed NdxMemBlock is used for best performance.
;             This object should never be accessed directly.

Object DB_MemoBlockCache, DB_MemoBlockCacheID, SortedCollection
  RedefineMethod    Compare,        $ObjPtr(DB_MemoBlock), $ObjPtr(DB_MemoBlock)
  RedefineMethod    DisposeAll
  StaticMethod      Flush
  StaticMethod      Get,            DB_MEMO_LINK_TYPE       ;BlockNo
  RedefineMethod    Init,           POINTER                 ;-> Owner = DB_Memo object
ObjectEnd


; --------------------------------------------------------------------------------------------------
; Object:     DB_Memo
; Purpose:    The database memo is an alternative storage for long field contents.
;             It works together with DB_MemoBlockCache.

Object DB_Memo, DB_MemoID, Primer
  VirtualMethod     Close
  VirtualMethod     GetFrom,        DB_MEMO_LINK_TYPE
  StaticMethod      GetFreeBlock
  VirtualMethod     Put,            POINTER, DWORD          ;-> Data, Size
  VirtualMethod     DeleteAt,       DB_MEMO_LINK_TYPE
  RedefineMethod    Done
  StaticMethod      Flush
  RedefineMethod    Init,           POINTER                 ;-> Owner
  VirtualMethod     New,            PSTRING, DWORD, DWORD   ;-> File name, Block size,Overwrite flag
  VirtualMethod     Use,            PSTRING

  DefineVariable    hFile,          HANDLE,     INVALID_HANDLE_VALUE
  DefineVariable    pFileName,      PSTRING,    NULL
  DefineVariable    dFlags,         DWORD,      DBT_USE_STD_FIELD_LENGTHS
  DefineVariable    Descriptor,     DB_MEMOFILE_DESCRIPTOR, {}

  Embed             Blocks,         DB_MemoBlockCache
ObjectEnd


; --------------------------------------------------------------------------------------------------
; Object:     DB_Record
; Purpose:    A database record is a set of heterogene but related information. This object manages
;             a single record within the database. The information contained in the record is
;             divided into fields (see DB_Field).
;             This object is should not be accessed directly. To get access to the record data use
;             the DB_Table object methods.
; Note:       The record number ranges from 1 to the current number of records in the database.
;             Record number zero is used for special purposes and is considdered an invalid record
;             number.

Object DB_Record, DB_RecordID, Primer
  RedefineMethod    Init,           POINTER, DB_DATA_LINK_TYPE  ;-> DB_RecordCache, DataRecNo
  StaticMethod      Read                                    ;Read from disk
  StaticMethod      ReInit,         DB_DATA_LINK_TYPE       ;DataRecNo
  StaticMethod      SetAutoIncs                             ;When appended, sets all AutoInc values
  StaticMethod      Write,          XWORD, XWORD            ;Write to disk

  DefineVariable    pNextRecord,    POINTER,    NULL
  DefineVariable    pPrevRecord,    POINTER,    NULL

  DefineVariable    dRecNo,         DB_DATA_LINK_TYPE,  0   ;Range [1..Number of records]
  DefineVariable    dFlags,         DWORD,            0
  DefineVariable    Buffer,         DB_RECORD,        0 dup (0) ;Buffer serves only as a label
ObjectEnd                                                   ;at the end of this object


; --------------------------------------------------------------------------------------------------
; Object:     DB_RecordCache
; Purpose:    A record cache is a in-memory managed record pool. Its purpose is to speedup the
;             record information access. This is implemented using an ageing scheme to write back
;             old information to the database. A circular doubly linked list (CDLL) with one pointer
;             to the last accessed NdxMemBlock is used for best performance.
;             This object should never be accessed directly.

Object DB_RecordCache, DB_RecordCacheID, SortedCollection
  RedefineMethod    Compare,        $ObjPtr(DB_Record), $ObjPtr(DB_Record)
  RedefineMethod    DeleteAll
  RedefineMethod    DisposeAll
  StaticMethod      Flush
  StaticMethod      Get,            DB_DATA_LINK_TYPE       ;RecNo
  RedefineMethod    Init,           POINTER                 ;-> Owner = DB_Table object

  DefineVariable    pLastAccessed,  $ObjPtr(DB_Record), NULL
ObjectEnd


; --------------------------------------------------------------------------------------------------
; Object:     DB_Field
; Purpose:    A database field is a specific place in a data record. This object manages all the
;             data that defines this storage place and how to handle it.
;             This object is should not be accessed directly. To get access to the field data use
;             the DB_Table object methods.
; Note:       - The first field in the field collection (pFields) is the deletion mark.
;             - Dbase3 compatible names MUST be set up from capital letters, digits or the
;               underscore character. The MUSt also begin with a capital letter and not exceed 10
;               characters and a zero terminating marker.
;             - Valid field types are:
;                  C (43h): Character = OEM character string (blank filled)
;                  N (4Eh): Numeric   = III.DD
;                  D (44h): Date      = 8 bytes in YYYYMMDD format
;                  L (4Ch): Logical   = 1 byte
;                  M (4Dh): Memo      = 10 bytes (or index into Memo file) - not implemented

Object DB_Field, DB_FieldID, Primer
  StaticMethod      DataGet,        $ObjPtr(DB_Record)
  StaticMethod      DataGetStr,     $ObjPtr(DB_Record), PSTRING   ;-> DB_Record, -> STRING
  StaticMethod      DataPut,        $ObjPtr(DB_Record), POINTER   ;-> DB_Record, -> Data
  StaticMethod      DataPutStr,     $ObjPtr(DB_Record), PSTRING   ;-> DB_Record, -> STRING
  RedefineMethod    Done
  StaticMethod      GetStrSize
  RedefineMethod    Init,           $ObjPtr(Collection), DWORD    ;-> Collection, Offset
  StaticMethod      Load
  StaticMethod      Save,           XWORD, XWORD

  DefineVariable    dOffset,        DWORD,      0           ;Data offset into record
  DefineVariable    pIndex,         POINTER,    NULL        ;-> DB_Index
  DefineVariable    Descriptor,     DB_FIELD_DESCRIPTOR, {}
ObjectEnd


; --------------------------------------------------------------------------------------------------
; Object:     DB_Table
; Purpose:    The database table is the central element of this implementation. It is build to be
;             compatible with dBase III file format that enables data loading by any modern database
;             system. It works together with other objects like DB_Field, DB_Record and DB_RecordCache.

Object DB_Table, DB_TableID, Primer
  VirtualMethod     AppendField,    PSTRINGA, DWORD, DWORD, DWORD ;-> Name, Type, Size, Decimals
  VirtualMethod     AppendRecord
  VirtualMethod     Close
  VirtualMethod     DataGetFrom,    DB_DATA_LINK_TYPE, DWORD    ;RecNo[1..Recs], FldNo[0..Flds-1]
  VirtualMethod     DataPutAt,      DB_DATA_LINK_TYPE, DWORD, POINTER ;RecNo, FldNo[0..Flds-1], -> Data
  VirtualMethod     Delete,         DB_DATA_LINK_TYPE, DWORD    ;RecNo[1..Recs], Action: TRUE/FALSE
  VirtualMethod     Deleted?,       DB_DATA_LINK_TYPE           ;RecNo
  RedefineMethod    Done
  StaticMethod      Flush
  VirtualMethod     IndexedOn,      PSTRING                 ;-> Existing file name
  RedefineMethod    Init,           POINTER, PAPP_SETUP     ;-> Owner, -> APP_SETUP 
  VirtualMethod     New,            PSTRING, DWORD          ;-> File name, Overwrite flag
  VirtualMethod     Use,            PSTRING                 ;Can be redefined to add new fields
  VirtualMethod     Pack,           PTaskStatus             ;Wipe out deleted records
  VirtualMethod     Zap                                     ;Clear the entire DB_Table

  DefineVariable    pAppSetup,      PAPP_SETUP, NULL
  DefineVariable    hFile,          HANDLE,     INVALID_HANDLE_VALUE
  DefineVariable    pFileName,      PSTRING,    NULL
  DefineVariable    dFlags,         DWORD,      DBT_USE_STD_FIELD_LENGTHS
  DefineVariable    Descriptor,     DB_DATAFILE_DESCRIPTOR, {}

  Embed             Fields,         Collection
  Embed             Records,        DB_RecordCache
  Embed             Memo,           DB_Memo
ObjectEnd


; --------------------------------------------------------------------------------------------------
; Object:     NdxMemBlock
; Purpose:    A index memory block is a way to keep index information in memory to spped up the
;             access to database records (see "Index introduction" in the above section).

Object NdxMemBlock, NdxMemBlockID, Primer
  VirtualMethod     Check1,         XWORD, XWORD
  VirtualMethod     CheckFlags,     XWORD, XWORD
  VirtualMethod     CheckLock,      XWORD, XWORD
  RedefineMethod    Init,           POINTER, NDX_LINK_TYPE  ;-> Owner = NdxMemBlockCache, BlockNo
  StaticMethod      Read
  StaticMethod      Write,          XWORD, XWORD

  DefineVariable    pNextMemBlock,  POINTER,      NULL      ;Internal linked list
  DefineVariable    pPrevMemBlock,  POINTER,      NULL
  DefineVariable    dBlockNo,       NDX_LINK_TYPE,0         ;Index into index file [1..n]
  DefineVariable    dFlags,         DWORD,        0
  DefineVariable    dLockCount,     DWORD,        0
  DefineVariable    Buffer,         NDX_BLOCK,    0 dup (0) ;Buffer serves only as a label at the
ObjectEnd                                                   ;end of this object


; --------------------------------------------------------------------------------------------------
; Object:     NdxMemBlockCache
; Purpose:    A block cache is a in-memory managed block pool. Its purpose is to speedup the
;             block information access. This is implemented using an ageing scheme to write
;             back old information to the database. A circular doubly linked list (CDLL) with one
;             pointer to the last accessed NdxMemBlock is used for best performance.
;             This object should never be accessed directly.

Object NdxMemBlockCache, NdxBlockCacheID, SortedCollection
  VirtualMethod     Check1
  VirtualMethod     CheckFlags,     DWORD
  VirtualMethod     CheckLocks
  RedefineMethod    Compare,        $ObjPtr(NdxMemBlock), $ObjPtr(NdxMemBlock)
  RedefineMethod    DeleteAll
  RedefineMethod    DisposeAll
  StaticMethod      Free,           $ObjPtr(NdxMemBlock)
  StaticMethod      New,            NDX_LINK_TYPE           ;BlockNo
  StaticMethod      Get,            NDX_LINK_TYPE           ;BlockNo
  StaticMethod      Flush
  RedefineMethod    Init,           POINTER                 ;-> Owner = DB_Index

  DefineVariable    pLastAccessed,  $ObjPtr(NdxMemBlock), NULL
ObjectEnd


; --------------------------------------------------------------------------------------------------
; Object:     DB_Index
; Purpose:    In database programs where most information is stored on disks, the time penalty for
;             accessing secondary storage can be significantly reduced by the proper choice of data
;             structures, B+ Trees (Bayer, McCreight 1972) are one such approaches.
;             One important property of B+ Trees is the size of each entry which can be made as
;             large as the size of a block.
;             A B+ Tree of order n is a multiway search tree with the following properties:
;               - Each block has at most 2*n entries.
;               - Each block has at least n entries, except for the root, which may have just
;                 only 1 entry.
;               - Each block is either a leaf, having no descendents, or a nonleaf, having m+1
;                 descendants, where m is its size (n (or 1 for the root) <= m <= 2*n).
;               - All leaf blocks are on the same level.
;               - The record numbers are stored in the leave entries.
;             In this implementation:
;               - Entry index values range from 0 to m-1.
;               - RecNo and BlockNo values start from 1.
;
; Example:
;                       +--------(LE 20)-- 20;33 --(GT 33)----------+             Root block
;                       |                     |                     |
;                       |                     | (LE 33)             |
;                       |                     |                     |
;                +--- 13;19 --+       +--- 26;31 ---+        +--- 37;41 ---+      Non leaf blocks
;                |       |    |       |       |     |        |       |     |
;                |       |    |       |       |     |        |       |     |
;              11;13  16;19  20     24;25  27;31  32;33    36;37  40;41  44;45    Leaf blocks
;
;
; Block layout:
;                 +-----------------+------------------+------------------+-----+------------+
; Leaf block:     | #Enties | Flags |    RecNo   | Key |    RecNo   | Key | ... |  LeafLink  |
;                 +-----------------+------------------+------------------+-----+------------+
;                 +-----------------+------------------+------------------+-----+------------+
; Non leaf block: | #Enties | Flags | LE_BlockNo | Key | LE_BlockNo | Key | ... | GT_BlockNo |
;                 +-----------------+------------------+------------------+-----+------------+

Object DB_Index, DB_IndexID, Primer
  StaticMethod      AtBottom?
  StaticMethod      AtTop?
  StaticMethod      BlockFree,      $ObjPtr(NdxMemBlock)
  StaticMethod      BlockNew
  StaticMethod      Close
  StaticMethod      DeleteKey
  RedefineMethod    Done
  StaticMethod      Flush
  StaticMethod      InfoPeek
  StaticMethod      InfoPop
  StaticMethod      InfoPush,       NDX_LINK_TYPE, DWORD    ;Info1, Info2
  RedefineMethod    Init,           $ObjPtr(DB_Field)       ;-> Owner
  StaticMethod      InsertKey,      POINTER, DB_DATA_LINK_TYPE    ;-> Key, DataRecNo
  StaticMethod      InsertRecord,   $ObjPtr(DB_Record)
  StaticMethod      KeyTest,        DWORD, POINTER, POINTER ;Test mode, -> Key, -> Key
  StaticMethod      New,            $ObjPtr(DB_Field), PSTRING,   ;-> DB_Field, -> File name
  StaticMethod      Open,           $ObjPtr(DB_Field), PSTRING,   ;-> DB_Field, -> File name
  StaticMethod      Reindex,        PTaskStatus
  StaticMethod      Seek,           POINTER                 ;-> Search key
  StaticMethod      SeekBottom
  StaticMethod      SeekKeyRecNo,   POINTER, DB_DATA_LINK_TYPE    ;-> Search key, RecNo
  StaticMethod      SeekRecNo,      DB_DATA_LINK_TYPE
  StaticMethod      SeekRecord,     $ObjPtr(DB_Record)
  StaticMethod      SeekTop
  StaticMethod      Skip,           SDWORD                  ;Number of records

  Embed             MemBlockCache,  NdxMemBlockCache
  Embed             InfoStack,      DataCollection

  DefineVariable    dKeyTestMode,   DWORD,        KTM_ANSI
  DefineVariable    hFile,          HANDLE,       INVALID_HANDLE_VALUE
  DefineVariable    pFileName,      PSTRING,      NULL
  DefineVariable    dFlags,         DWORD,        0
  DefineVariable    dBlockLength,   DWORD,        0
  DefineVariable    dInfoStackTop,  DWORD,        0         ;1..n, 0 means nothing stored
  DefineVariable    dEOFBlockNo,    NDX_LINK_TYPE,0         ;Number of a free block after EOF
  DefineVariable    pHeader,        PNDX_HEADER,  NULL      ;-> Index file header
  DefineVariable    dBlockMinKeys,  DWORD,        0
  DefineVariable    dBlockMaxKeys,  DWORD,        0
  DefineVariable    xKeySize,       XWORD,        0
  DefineVariable    xEntrySize,     XWORD,        0
ObjectEnd


; --------------------------------------------------------------------------------------------------
; Object:  DB_Query
; Purpose: This object is designed to allow to query a DB_Table for an occurrence defined in filter
;          callback procedure. DB_Query has an internal table where the matching record numbers are
;          stored. This table expands as necessary in steps of 5 entries (default) and doesn't clear
;          itself when a new query is started allowing to add new results. If this behaviour
;          isn't wanted, the DeleteAll method should be used to clear previous results.
; Notes:   - Since this object inherits from Streamable, it is able to store and recall its data
;            members to any type of Stream descendant object.

Object DB_Query, DB_QueryID, Streamable
  VirtualMethod     DeleteAt,       DWORD                 ;Index in range [0..Count-1]
  VirtualMethod     DeleteAll                             ;Deletes all entries
  RedefineMethod    Done                                  ;Destructor
  VirtualMethod     FirstThat,      POINTER, XWORD        ;-> Proc, Parameter
  VirtualMethod     ForEach,        POINTER, XWORD        ;-> Proc, Parameter
  VirtualMethod     ForEachRev,     POINTER, XWORD        ;ForEach in reverse order
  VirtualMethod     GetCount                              ;Number of entries in result table
  RedefineMethod    Init,           POINTER, $ObjPtr(DB_Table)  ;-> Owner, -> DB_Table
  VirtualMethod     Insert,         DB_DATA_LINK_TYPE         ;Record number
  VirtualMethod     InsertAt,       DWORD, DB_DATA_LINK_TYPE  ;Index, Record number
  VirtualMethod     LastThat,       POINTER, XWORD        ;-> Proc, Parameter
  RedefineMethod    Load,           $ObjPtr(Stream), POINTER, PDESER_INFO ;-> Stream, -> Owner, ...
  VirtualMethod     RecNoAt,        DWORD                 ;Index in range [0..Count-1]
  VirtualMethod     Start,          DWORD, POINTER        ;FieldNo, -> FilterProc
  VirtualMethod     SetLimit,       DWORD                 ;Set new limit (internal method)
  RedefineMethod    Store,          $ObjPtr(Stream)       ;-> Stream

  DefineVariable    pTable,         $ObjPtr(DB_Table),  NULL  ;-> DB_Table object
  DefineVariable    pData,          POINTER,    NULL      ;-> Result table
  DefineVariable    dCount,         DWORD,      0         ;Number of entries in result table
  DefineVariable    dDelta,         DWORD,      5         ;Grow factor of result table
  DefineVariable    dLimit,         DWORD,      0         ;Current size of result table
ObjectEnd



; ==================================================================================================

LOCAL_BUFFER_SIZE = 256*sizeof(CHRW) + 20       ;Field content + 20 additional bytes, just in case
COPY_BUFFER_SIZE  = 1024*1024

;Field attributes
SFF_READ_ONLY       equ   BIT00       ;Read Only
SFF_WRITE_SETUP     equ   BIT01       ;Allowed to write on setup (AutoInc)
SFF_MEMO            equ   BIT02       ;Stored as Memo
SFF_NO_VISUAL       equ   BIT03       ;Data has a no visual representation
SFF_HAS_PARAM       equ   BIT04
SSF_NO_INDEX        equ   BIT05

;Field initialization flags
SFM_ZERO            equ   0           ;Fill with zeros
SFM_BLANKA          equ   1           ;Fill with ANSI spaces
SFM_BLANKW          equ   2           ;Fill with WIDE spaces
SFM_LOGIC           equ   3           ;Fill with "F" (Logic FALSE)
SFM_AUTOINC         equ   4           ;Fill counting (AutoInc)
SFM_NOW             equ   5           ;Set now in Timestamp field


FIELD_MUTATION struct 1
  bPrvName      FIELD_NAME_BUFFER   {}
  bActName      FIELD_NAME_BUFFER   {}
  bPrvType      BYTE      ?
  bActType      BYTE      ?
  bPrvLength    BYTE      ?
  bActLength    BYTE      ?
  dPrvParam     DWORD     ?
  dActParam     DWORD     ?
  pInProc       POINTER   ?
  pOutProc      POINTER   ?
  wFlags        WORD      ?
  pAppSetup     PAPP_SETUP  NULL
FIELD_MUTATION ends
PFIELD_MUTATION typedef ptr FIELD_MUTATION

LOCALE_INFO struct
  cDecSeparator   CHR   2 DUP(?)
  cDateFormat     CHR   11 DUP(?)
LOCALE_INFO ends


PMutInProc typedef proto :POINTER, :POINTER, :PFIELD_MUTATION
PMutOutProc typedef proto :POINTER, :POINTER, :PFIELD_MUTATION

externdef StdFieldLookupTable:STD_FIELD_INFO
externdef wBlanks:CHRW
externdef bBlanks:CHRA
externdef bZeros:CHRA
externdef bLogic:CHRA

CreateTempFile proto
GetPhysicalSectorSize proto  :PSTRING
DB_GetStdFieldInfo proto :BYTE
DB_StrToNum proto :PSTRINGA, :PSTRING, :DWORD, :DWORD
DB_NumToStr proto :PSTRING, :POINTER, :DWORD
DB_StrToDate proto :PSTRING, :POINTER, :BYTE
DB_DateToStr proto :PSTRING, :POINTER, :BYTE, :CHR
DB_DateToStrW proto :PSTRING, :POINTER, :BYTE, :CHR
DB_DateToJDN proto :DWORD, :DWORD, :DWORD
DB_JDNToDate proto :DWORD
DB_Real4ToStr proto :PSTRING, :POINTER, :DWORD
DB_StrToReal4 proto :POINTER, :PSTRING
DB_Real8ToStr proto :PSTRING, :POINTER, :BYTE
DB_StrToReal8 proto :POINTER, :PSTRING
DB_Real10ToStr proto :PSTRING, :POINTER, :DWORD
DB_StrToReal10 proto :POINTER, :PSTRING
DB_LogicalToStr proto :PSTRING, :POINTER
DB_StrToLogical proto :PSTRING, :PSTRING
DB_NowToTimestamp proto :POINTER
DB_TimeToMS proto :DWORD, :DWORD, :DWORD, :DWORD
DB_TimestampToStr proto :PSTRING, :POINTER
MUT_CopyData proto :POINTER, :POINTER, :PFIELD_MUTATION
MUT_CopyDataFillA proto :POINTER, :POINTER, :PFIELD_MUTATION
MUT_CopyDataFillW proto :POINTER, :POINTER, :PFIELD_MUTATION
MUT_FillBlank proto :POINTER, :POINTER, :PFIELD_MUTATION
MUT_DeleteMemo proto :POINTER, :POINTER, :PFIELD_MUTATION
MUT_ChrAToBuf proto :POINTER, :POINTER, :PFIELD_MUTATION
MUT_ChrWToBuf proto :POINTER, :POINTER, :PFIELD_MUTATION
MUT_Chr8ToBuf proto :POINTER, :POINTER, :PFIELD_MUTATION
MUT_DateToBuf proto :POINTER, :POINTER, :PFIELD_MUTATION
MUT_DateToFpu proto :POINTER, :POINTER, :PFIELD_MUTATION
MUT_NumToFpu proto :POINTER, :POINTER, :PFIELD_MUTATION
MUT_NumToNum proto :POINTER, :POINTER, :PFIELD_MUTATION
MUT_R4ToFpu proto :POINTER, :POINTER, :PFIELD_MUTATION
MUT_R8ToFpu proto :POINTER, :POINTER, :PFIELD_MUTATION
MUT_R10ToFpu proto :POINTER, :POINTER, :PFIELD_MUTATION
MUT_BoolToFpu proto :POINTER, :POINTER, :PFIELD_MUTATION
MUT_Int32ToFpu proto :POINTER, :POINTER, :PFIELD_MUTATION
MUT_UInt32ToFpu proto :POINTER, :POINTER, :PFIELD_MUTATION
MUT_ChrAToFpu proto :POINTER, :POINTER, :PFIELD_MUTATION
MUT_ChrWToFpu proto :POINTER, :POINTER, :PFIELD_MUTATION
MUT_Chr8ToFpu proto :POINTER, :POINTER, :PFIELD_MUTATION
MUT_TimestampToFpu proto :POINTER, :POINTER, :PFIELD_MUTATION
MUT_BufToChrFillA proto :POINTER, :POINTER, :PFIELD_MUTATION
MUT_BufToChrFillW proto :POINTER, :POINTER, :PFIELD_MUTATION
MUT_BufToChr8 proto :POINTER, :POINTER, :PFIELD_MUTATION
MUT_BufToMemo proto :POINTER, :POINTER, :PFIELD_MUTATION
MUT_BufToBool proto :POINTER, :POINTER, :PFIELD_MUTATION
MUT_BufToNum proto :POINTER, :POINTER, :PFIELD_MUTATION
MUT_BufToDate proto :POINTER, :POINTER, :PFIELD_MUTATION
MUT_FpuToChrA proto :POINTER, :POINTER, :PFIELD_MUTATION
MUT_FpuToChrW proto :POINTER, :POINTER, :PFIELD_MUTATION
MUT_FpuToInt32 proto :POINTER, :POINTER, :PFIELD_MUTATION
MUT_FpuToUInt32 proto :POINTER, :POINTER, :PFIELD_MUTATION
MUT_FpuToNum proto :POINTER, :POINTER, :PFIELD_MUTATION
MUT_FpuToR4 proto :POINTER, :POINTER, :PFIELD_MUTATION
MUT_FpuToR8 proto :POINTER, :POINTER, :PFIELD_MUTATION
MUT_FpuToR10 proto :POINTER, :POINTER, :PFIELD_MUTATION
MUT_FpuToTimestamp proto :POINTER, :POINTER, :PFIELD_MUTATION
MUT_FpuToDate proto :POINTER, :POINTER, :PFIELD_MUTATION
MUT_FpuToBool proto :POINTER, :POINTER, :PFIELD_MUTATION
MemoPutBmp proto :$ObjPtr(DB_Memo), :HANDLE
MemoGetBmp proto :$ObjPtr(DB_Memo), :DWORD

MUT_FpuToChr8 textequ <MUT_FpuToChrA>

; --------------------------------------------------------------------------------------------------

if IMPLEMENT

% include &ObjPath&DB_Routines.inc

% include \OA_Dev\Code\Objects\Closed Source\DB_Field.inc
% include \OA_Dev\Code\Objects\Closed Source\DB_Table.inc
% include \OA_Dev\Code\Objects\Closed Source\DB_Index.inc
% include \OA_Dev\Code\Objects\Closed Source\DB_Memo.inc
% include \OA_Dev\Code\Objects\Closed Source\DB_Query.inc

endif
