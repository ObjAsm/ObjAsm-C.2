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