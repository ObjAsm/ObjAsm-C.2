;Include file created by h2incX, Version C.01.00, 27/06/2019 10:12
;(C) 2018-today by Biterider, 2005-2009 by Japheth
;Source file: 'D:\ObjAsm\Projects\32\h2IncX\Header_10.0.17763.0\compressapi.h', last modified: 22/10/2018 21:35

include windef.inc
if (NTDDI_VERSION ge NTDDI_WIN8)
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_APP or WINAPI_PARTITION_SYSTEM)
    COMPRESSOR_HANDLE typedef HANDLE
    PCOMPRESSOR_HANDLE typedef ptr COMPRESSOR_HANDLE
    DECOMPRESSOR_HANDLE typedef COMPRESSOR_HANDLE
    PDECOMPRESSOR_HANDLE typedef ptr COMPRESSOR_HANDLE
    COMPRESS_ALGORITHM_INVALID equ 0
    COMPRESS_ALGORITHM_NULL equ 1
    COMPRESS_ALGORITHM_MSZIP equ 2
    COMPRESS_ALGORITHM_XPRESS equ 3
    COMPRESS_ALGORITHM_XPRESS_HUFF equ 4
    COMPRESS_ALGORITHM_LZMS equ 5
    COMPRESS_ALGORITHM_MAX equ 6
    COMPRESS_RAW equ (1 shl 29)
    TYPE_PFN_COMPRESS_ALLOCATE typedef proto c :PVOID, :SIZE_T
    PFN_COMPRESS_ALLOCATE typedef ptr TYPE_PFN_COMPRESS_ALLOCATE
    TYPE_PFN_COMPRESS_FREE typedef proto c :PVOID, :PVOID
    PFN_COMPRESS_FREE typedef ptr TYPE_PFN_COMPRESS_FREE
    COMPRESS_ALLOCATION_ROUTINES struct
      Allocate PFN_COMPRESS_ALLOCATE ?
      Free PFN_COMPRESS_FREE ?
      UserContext PVOID ?
    COMPRESS_ALLOCATION_ROUTINES ends
    _COMPRESS_ALLOCATION_ROUTINES typedef COMPRESS_ALLOCATION_ROUTINES
    PCOMPRESS_ALLOCATION_ROUTINES typedef ptr COMPRESS_ALLOCATION_ROUTINES
    
    COMPRESS_INFORMATION_CLASS typedef SDWORD
    COMPRESS_INFORMATION_CLASS_INVALID equ 0
    COMPRESS_INFORMATION_CLASS_BLOCK_SIZE equ 1
    COMPRESS_INFORMATION_CLASS_LEVEL equ 2
    
    CreateCompressor proto WIN_STD_CALL_CONV :DWORD, :PCOMPRESS_ALLOCATION_ROUTINES, :PCOMPRESSOR_HANDLE
    SetCompressorInformation proto WIN_STD_CALL_CONV :COMPRESSOR_HANDLE, :COMPRESS_INFORMATION_CLASS, :LPCVOID, :SIZE_T
    QueryCompressorInformation proto WIN_STD_CALL_CONV :COMPRESSOR_HANDLE, :COMPRESS_INFORMATION_CLASS, :PVOID, :SIZE_T
    Compress proto WIN_STD_CALL_CONV :COMPRESSOR_HANDLE, :LPCVOID, :SIZE_T, :PVOID, :SIZE_T, :PSIZE_T
    ResetCompressor proto WIN_STD_CALL_CONV :COMPRESSOR_HANDLE
    CloseCompressor proto WIN_STD_CALL_CONV :COMPRESSOR_HANDLE
    CreateDecompressor proto WIN_STD_CALL_CONV :DWORD, :PCOMPRESS_ALLOCATION_ROUTINES, :PDECOMPRESSOR_HANDLE
    SetDecompressorInformation proto WIN_STD_CALL_CONV :DECOMPRESSOR_HANDLE, :COMPRESS_INFORMATION_CLASS, :LPCVOID, :SIZE_T
    QueryDecompressorInformation proto WIN_STD_CALL_CONV :DECOMPRESSOR_HANDLE, :COMPRESS_INFORMATION_CLASS, :PVOID, :SIZE_T
    Decompress proto WIN_STD_CALL_CONV :DECOMPRESSOR_HANDLE, :LPCVOID, :SIZE_T, :PVOID, :SIZE_T, :PSIZE_T
    ResetDecompressor proto WIN_STD_CALL_CONV :DECOMPRESSOR_HANDLE
    CloseDecompressor proto WIN_STD_CALL_CONV :DECOMPRESSOR_HANDLE
  endif
endif
 