;Include file created by h2incX, Version C.01.00, 05/02/2023 07:58
;(C) 2018-today by Biterider, 2005-2009 by Japheth
;Source file: 'odbcinst.h', last modified: 13/10/2022 20:10

ifndef __ODBCINST_H
  __ODBCINST_H equ <>
  include winapifamily.inc
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    ifndef __SQL
      include sql.inc
    endif
    ifdef __cplusplus
      ;[...]
    endif
    ifndef ODBCVER
      ODBCVER equ 0380h
    endif
    ifndef WINVER
      WINVER equ 0400h
    endif
    ODBC_ADD_DSN equ 1
    ODBC_CONFIG_DSN equ 2
    ODBC_REMOVE_DSN equ 3
    if (ODBCVER ge 0250h)
      ODBC_ADD_SYS_DSN equ 4
      ODBC_CONFIG_SYS_DSN equ 5
      ODBC_REMOVE_SYS_DSN equ 6
      if (ODBCVER ge 0300h)
        ODBC_REMOVE_DEFAULT_DSN equ 7
      endif
      ODBC_INSTALL_INQUIRY equ 1
      ODBC_INSTALL_COMPLETE equ 2
      ODBC_INSTALL_DRIVER equ 1
      ODBC_REMOVE_DRIVER equ 2
      ODBC_CONFIG_DRIVER equ 3
      ODBC_CONFIG_DRIVER_MAX equ 100
    endif
    if (ODBCVER ge 0300h)
      ODBC_BOTH_DSN equ 0
      ODBC_USER_DSN equ 1
      ODBC_SYSTEM_DSN equ 2
    endif
    if (ODBCVER ge 0300h)
      ODBC_ERROR_GENERAL_ERR equ 1
      ODBC_ERROR_INVALID_BUFF_LEN equ 2
      ODBC_ERROR_INVALID_HWND equ 3
      ODBC_ERROR_INVALID_STR equ 4
      ODBC_ERROR_INVALID_REQUEST_TYPE equ 5
      ODBC_ERROR_COMPONENT_NOT_FOUND equ 6
      ODBC_ERROR_INVALID_NAME equ 7
      ODBC_ERROR_INVALID_KEYWORD_VALUE equ 8
      ODBC_ERROR_INVALID_DSN equ 9
      ODBC_ERROR_INVALID_INF equ 10
      ODBC_ERROR_REQUEST_FAILED equ 11
      ODBC_ERROR_INVALID_PATH equ 12
      ODBC_ERROR_LOAD_LIB_FAILED equ 13
      ODBC_ERROR_INVALID_PARAM_SEQUENCE equ 14
      ODBC_ERROR_INVALID_LOG_FILE equ 15
      ODBC_ERROR_USER_CANCELED equ 16
      ODBC_ERROR_USAGE_UPDATE_FAILED equ 17
      ODBC_ERROR_CREATE_DSN_FAILED equ 18
      ODBC_ERROR_WRITING_SYSINFO_FAILED equ 19
      ODBC_ERROR_REMOVE_DSN_FAILED equ 20
      ODBC_ERROR_OUT_OF_MEM equ 21
      ODBC_ERROR_OUTPUT_STRING_TRUNCATED equ 22
      ODBC_ERROR_NOTRANINFO equ 23
      ODBC_ERROR_MAX equ <ODBC_ERROR_NOTRANINFO>
    endif
    ifndef EXPORT_
      EXPORT_ equ <>
    endif
    ifndef RC_INVOKED
      INSTAPI equ <__stdcall>
      SQLInstallODBC proto WIN_STD_CALL_CONV :HWND, :LPCSTR, :LPCSTR, :LPCSTR
      SQLManageDataSources proto WIN_STD_CALL_CONV :HWND
      SQLCreateDataSource proto WIN_STD_CALL_CONV :HWND, :LPCSTR
      SQLGetTranslator proto WIN_STD_CALL_CONV :HWND, :LPSTR, :WORD, :ptr WORD, :LPSTR, :WORD, :ptr WORD, :ptr DWORD
      SQLInstallDriver proto WIN_STD_CALL_CONV :LPCSTR, :LPCSTR, :LPSTR, :WORD, :ptr WORD
      SQLInstallDriverManager proto WIN_STD_CALL_CONV :LPSTR, :WORD, :ptr WORD
      SQLGetInstalledDrivers proto WIN_STD_CALL_CONV :LPSTR, :WORD, :ptr WORD
      SQLGetAvailableDrivers proto WIN_STD_CALL_CONV :LPCSTR, :LPSTR, :WORD, :ptr WORD
      SQLConfigDataSource proto WIN_STD_CALL_CONV :HWND, :WORD, :LPCSTR, :LPCSTR
      SQLRemoveDefaultDataSource proto WIN_STD_CALL_CONV
      SQLWriteDSNToIni proto WIN_STD_CALL_CONV :LPCSTR, :LPCSTR
      SQLRemoveDSNFromIni proto WIN_STD_CALL_CONV :LPCSTR
      SQLValidDSN proto WIN_STD_CALL_CONV :LPCSTR
      SQLWritePrivateProfileString proto WIN_STD_CALL_CONV :LPCSTR, :LPCSTR, :LPCSTR, :LPCSTR
      SQLGetPrivateProfileString proto WIN_STD_CALL_CONV :LPCSTR, :LPCSTR, :LPCSTR, :LPSTR, :SDWORD, :LPCSTR
      if (ODBCVER ge 0250h)
        SQLRemoveDriverManager proto WIN_STD_CALL_CONV :LPDWORD
        SQLInstallTranslator proto WIN_STD_CALL_CONV :LPCSTR, :LPCSTR, :LPCSTR, :LPSTR, :WORD, :ptr WORD, :WORD, :LPDWORD
        SQLRemoveTranslator proto WIN_STD_CALL_CONV :LPCSTR, :LPDWORD
        SQLRemoveDriver proto WIN_STD_CALL_CONV :LPCSTR, :BOOL, :LPDWORD
        SQLConfigDriver proto WIN_STD_CALL_CONV :HWND, :WORD, :LPCSTR, :LPCSTR, :LPSTR, :WORD, :ptr WORD
      endif
      if (ODBCVER ge 0300h)
        SQLInstallerError proto WIN_STD_CALL_CONV :WORD, :ptr DWORD, :LPSTR, :WORD, :ptr WORD
        SQLPostInstallerError proto WIN_STD_CALL_CONV :DWORD, :LPCSTR
        SQLWriteFileDSN proto WIN_STD_CALL_CONV :LPCSTR, :LPCSTR, :LPCSTR, :LPCSTR
        SQLReadFileDSN proto WIN_STD_CALL_CONV :LPCSTR, :LPCSTR, :LPCSTR, :LPSTR, :WORD, :ptr WORD
        SQLInstallDriverEx proto WIN_STD_CALL_CONV :LPCSTR, :LPCSTR, :LPSTR, :WORD, :ptr WORD, :WORD, :LPDWORD
        SQLInstallTranslatorEx proto WIN_STD_CALL_CONV :LPCSTR, :LPCSTR, :LPSTR, :WORD, :ptr WORD, :WORD, :LPDWORD
        SQLGetConfigMode proto WIN_STD_CALL_CONV :ptr UWORD
        SQLSetConfigMode proto WIN_STD_CALL_CONV :UWORD
      endif
      ConfigDSN proto WIN_STD_CALL_CONV :HWND, :WORD, :LPCSTR, :LPCSTR
      ConfigTranslator proto WIN_STD_CALL_CONV :HWND, :ptr DWORD
      if (ODBCVER ge 0250h)
        ConfigDriver proto WIN_STD_CALL_CONV :HWND, :WORD, :LPCSTR, :LPCSTR, :LPSTR, :WORD, :ptr WORD
      endif
      SQLInstallODBCW proto WIN_STD_CALL_CONV :HWND, :LPCWSTR, :LPCWSTR, :LPCWSTR
      SQLCreateDataSourceW proto WIN_STD_CALL_CONV :HWND, :LPCWSTR
      SQLGetTranslatorW proto WIN_STD_CALL_CONV :HWND, :LPWSTR, :WORD, :ptr WORD, :LPWSTR, :WORD, :ptr WORD, :ptr DWORD
      SQLInstallDriverW proto WIN_STD_CALL_CONV :LPCWSTR, :LPCWSTR, :LPWSTR, :WORD, :ptr WORD
      SQLInstallDriverManagerW proto WIN_STD_CALL_CONV :LPWSTR, :WORD, :ptr WORD
      SQLGetInstalledDriversW proto WIN_STD_CALL_CONV :LPWSTR, :WORD, :ptr WORD
      SQLGetAvailableDriversW proto WIN_STD_CALL_CONV :LPCWSTR, :LPWSTR, :WORD, :ptr WORD
      SQLConfigDataSourceW proto WIN_STD_CALL_CONV :HWND, :WORD, :LPCWSTR, :LPCWSTR
      SQLWriteDSNToIniW proto WIN_STD_CALL_CONV :LPCWSTR, :LPCWSTR
      SQLRemoveDSNFromIniW proto WIN_STD_CALL_CONV :LPCWSTR
      SQLValidDSNW proto WIN_STD_CALL_CONV :LPCWSTR
      SQLWritePrivateProfileStringW proto WIN_STD_CALL_CONV :LPCWSTR, :LPCWSTR, :LPCWSTR, :LPCWSTR
      SQLGetPrivateProfileStringW proto WIN_STD_CALL_CONV :LPCWSTR, :LPCWSTR, :LPCWSTR, :LPWSTR, :SDWORD, :LPCWSTR
      if (ODBCVER ge 0250h)
        SQLInstallTranslatorW proto WIN_STD_CALL_CONV :LPCWSTR, :LPCWSTR, :LPCWSTR, :LPWSTR, :WORD, :ptr WORD, :WORD, :LPDWORD
        SQLRemoveTranslatorW proto WIN_STD_CALL_CONV :LPCWSTR, :LPDWORD
        SQLRemoveDriverW proto WIN_STD_CALL_CONV :LPCWSTR, :BOOL, :LPDWORD
        SQLConfigDriverW proto WIN_STD_CALL_CONV :HWND, :WORD, :LPCWSTR, :LPCWSTR, :LPWSTR, :WORD, :ptr WORD
      endif
      if (ODBCVER ge 0300h)
        SQLInstallerErrorW proto WIN_STD_CALL_CONV :WORD, :ptr DWORD, :LPWSTR, :WORD, :ptr WORD
        SQLPostInstallerErrorW proto WIN_STD_CALL_CONV :DWORD, :LPCWSTR
        SQLWriteFileDSNW proto WIN_STD_CALL_CONV :LPCWSTR, :LPCWSTR, :LPCWSTR, :LPCWSTR
        SQLReadFileDSNW proto WIN_STD_CALL_CONV :LPCWSTR, :LPCWSTR, :LPCWSTR, :LPWSTR, :WORD, :ptr WORD
        SQLInstallDriverExW proto WIN_STD_CALL_CONV :LPCWSTR, :LPCWSTR, :LPWSTR, :WORD, :ptr WORD, :WORD, :LPDWORD
        SQLInstallTranslatorExW proto WIN_STD_CALL_CONV :LPCWSTR, :LPCWSTR, :LPWSTR, :WORD, :ptr WORD, :WORD, :LPDWORD
      endif
      ConfigDSNW proto WIN_STD_CALL_CONV :HWND, :WORD, :LPCWSTR, :LPCWSTR
      if (ODBCVER ge 0250h)
        ConfigDriverW proto WIN_STD_CALL_CONV :HWND, :WORD, :LPCWSTR, :LPCWSTR, :LPWSTR, :WORD, :ptr WORD
      endif
      ifndef SQL_NOUNICODEMAP
        ifdef UNICODE
          SQLInstallODBC equ <SQLInstallODBCW>
          SQLCreateDataSource equ <SQLCreateDataSourceW>
          SQLGetTranslator equ <SQLGetTranslatorW>
          SQLInstallDriver equ <SQLInstallDriverW>
          SQLInstallDriverManager equ <SQLInstallDriverManagerW>
          SQLGetInstalledDrivers equ <SQLGetInstalledDriversW>
          SQLGetAvailableDrivers equ <SQLGetAvailableDriversW>
          SQLConfigDataSource equ <SQLConfigDataSourceW>
          SQLWriteDSNToIni equ <SQLWriteDSNToIniW>
          SQLRemoveDSNFromIni equ <SQLRemoveDSNFromIniW>
          SQLValidDSN equ <SQLValidDSNW>
          SQLWritePrivateProfileString equ <SQLWritePrivateProfileStringW>
          SQLGetPrivateProfileString equ <SQLGetPrivateProfileStringW>
          SQLInstallTranslator equ <SQLInstallTranslatorW>
          SQLRemoveTranslator equ <SQLRemoveTranslatorW>
          SQLRemoveDriver equ <SQLRemoveDriverW>
          SQLConfigDriver equ <SQLConfigDriverW>
          SQLInstallerError equ <SQLInstallerErrorW>
          SQLPostInstallerError equ <SQLPostInstallerErrorW>
          SQLReadFileDSN equ <SQLReadFileDSNW>
          SQLWriteFileDSN equ <SQLWriteFileDSNW>
          SQLInstallDriverEx equ <SQLInstallDriverExW>
          SQLInstallTranslatorEx equ <SQLInstallTranslatorExW>
        endif
      endif
    endif
    ifdef __cplusplus
      ;[...]
    endif
  endif
endif
 