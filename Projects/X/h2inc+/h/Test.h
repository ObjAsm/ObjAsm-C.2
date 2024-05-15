static __inline LRESULT VFWAPI_INLINE
ICSetStatusProc(
            _In_ HIC hic,
            _In_ DWORD dwFlags,
            _In_ LRESULT lParam,
            _In_ LONG (CALLBACK *fpfnStatus)(_In_ LPARAM, _In_ UINT, _In_ LONG) )
{
    ICSETSTATUSPROC ic;

    ic.dwFlags = dwFlags;
    ic.lParam = lParam;
    ic.Status = fpfnStatus;

    // note that ICM swaps round the length and pointer
    // length in lparam2, pointer in lparam1
    return ICSendMessage(hic, ICM_SET_STATUS_PROC, (DWORD_PTR)&ic, sizeof(ic));
}