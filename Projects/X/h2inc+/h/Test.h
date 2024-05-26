#define VOID void

enum SYSGEOTYPE {
    GEO_NATION      =       0x0001, // DEPRECATED Not used by name API
    GEO_LATITUDE    =       0x0002,
    GEO_LONGITUDE   =       0x0003,
    GEO_ISO2        =       0x0004,
    GEO_ISO3        =       0x0005,
    GEO_RFC1766     =       0x0006, // DEPRECATED and misleading, not used by name API
    GEO_LCID        =       0x0007, // DEPRECATED Not used by name API
    GEO_FRIENDLYNAME=       0x0008,
    GEO_OFFICIALNAME=       0x0009,
    GEO_TIMEZONES   =       0x000A, // Not implemented
    GEO_OFFICIALLANGUAGES = 0x000B, // Not implemented
    GEO_ISO_UN_NUMBER =     0x000C,
    GEO_PARENT      =       0x000D,
    GEO_DIALINGCODE =       0x000E,
    GEO_CURRENCYCODE=       0x000F, // eg: USD
    GEO_CURRENCYSYMBOL=     0x0010, // eg: $
#if (NTDDI_VERSION >= NTDDI_WIN10_RS3)
    GEO_NAME        =       0x0011, // Name, eg: US or 001
    GEO_ID          =       0x0012  // DEPRECATED - For compatibility, please avoid
#endif
};