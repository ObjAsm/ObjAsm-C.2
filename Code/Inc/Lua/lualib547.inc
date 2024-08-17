;Include file created by h2inc+ version C.2.0 on (UTC) 17/07/2024 16:54:49
;(C) G. Friedrich July 2024
;Source file: lualib.h, last modified: 02/12/2023 23:42


LUA_VERSUFFIX equ <"_" LUA_VERSION_MAJOR "_" LUA_VERSION_MINOR>
@DefProto LUA_IMPORT_ATTR, luaopen_base, WIN_STD_CALL_CONV,, <:ptr lua_State>, 4
LUA_COLIBNAME equ <"coroutine">
@DefProto LUA_IMPORT_ATTR, luaopen_coroutine, WIN_STD_CALL_CONV,, <:ptr lua_State>, 4
LUA_TABLIBNAME equ <"table">
@DefProto LUA_IMPORT_ATTR, luaopen_table, WIN_STD_CALL_CONV,, <:ptr lua_State>, 4
LUA_IOLIBNAME equ <"io">
@DefProto LUA_IMPORT_ATTR, luaopen_io, WIN_STD_CALL_CONV,, <:ptr lua_State>, 4
LUA_OSLIBNAME equ <"os">
@DefProto LUA_IMPORT_ATTR, luaopen_os, WIN_STD_CALL_CONV,, <:ptr lua_State>, 4
LUA_STRLIBNAME equ <"string">
@DefProto LUA_IMPORT_ATTR, luaopen_string, WIN_STD_CALL_CONV,, <:ptr lua_State>, 4
LUA_UTF8LIBNAME equ <"utf8">
@DefProto LUA_IMPORT_ATTR, luaopen_utf8, WIN_STD_CALL_CONV,, <:ptr lua_State>, 4
LUA_MATHLIBNAME equ <"math">
@DefProto LUA_IMPORT_ATTR, luaopen_math, WIN_STD_CALL_CONV,, <:ptr lua_State>, 4
LUA_DBLIBNAME equ <"debug">
@DefProto LUA_IMPORT_ATTR, luaopen_debug, WIN_STD_CALL_CONV,, <:ptr lua_State>, 4
LUA_LOADLIBNAME equ <"package">
@DefProto LUA_IMPORT_ATTR, luaopen_package, WIN_STD_CALL_CONV,, <:ptr lua_State>, 4
@DefProto LUA_IMPORT_ATTR, luaL_openlibs, WIN_STD_CALL_CONV,, <:ptr lua_State>, 4
