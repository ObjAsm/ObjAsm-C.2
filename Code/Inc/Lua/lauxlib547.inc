;Include file created by h2inc+ version C.2.0 on (UTC) 17/07/2024 16:54:49
;(C) G. Friedrich July 2024
;Source file: lauxlib.h, last modified: 02/12/2023 12:17

LUA_GNAME equ <"_G">

LUA_ERRFILE equ (LUA_ERRERR + 1)
LUA_LOADED_TABLE equ <"_LOADED">
LUA_PRELOAD_TABLE equ <"_PRELOAD">

luaL_Reg struct
  name_ POINTER ?
  func  plua_CFunction ?
luaL_Reg ends

LUAL_NUMSIZES equ (sizeof(lua_Integer) * 16 + sizeof(lua_Number))

@DefProto LUA_IMPORT_ATTR, luaL_checkversion_, WIN_STD_CALL_CONV,, <:ptr lua_State, :lua_Number, :size_t>, %(8 + sizeof(lua_Number))
@DefProto LUA_IMPORT_ATTR, luaL_getmetafield, WIN_STD_CALL_CONV,, <:ptr lua_State, :SDWORD, :ptr SBYTE>, 12
@DefProto LUA_IMPORT_ATTR, luaL_callmeta, WIN_STD_CALL_CONV,, <:ptr lua_State, :SDWORD, :ptr SBYTE>, 12
@DefProto LUA_IMPORT_ATTR, luaL_tolstring, WIN_STD_CALL_CONV,, <:ptr lua_State, :SDWORD, :ptr size_t>, 12
@DefProto LUA_IMPORT_ATTR, luaL_argerror, WIN_STD_CALL_CONV,, <:ptr lua_State, :SDWORD, :ptr SBYTE>, 12
@DefProto LUA_IMPORT_ATTR, luaL_typeerror, WIN_STD_CALL_CONV,, <:ptr lua_State, :SDWORD, :ptr SBYTE>, 12
@DefProto LUA_IMPORT_ATTR, luaL_checklstring, WIN_STD_CALL_CONV,, <:ptr lua_State, :SDWORD, :ptr size_t>, 12
@DefProto LUA_IMPORT_ATTR, luaL_optlstring, WIN_STD_CALL_CONV,, <:ptr lua_State, :SDWORD, :ptr SBYTE, :ptr size_t>, 16
@DefProto LUA_IMPORT_ATTR, luaL_checknumber, WIN_STD_CALL_CONV,, <:ptr lua_State, :SDWORD>, 8
@DefProto LUA_IMPORT_ATTR, luaL_optnumber, WIN_STD_CALL_CONV,, <:ptr lua_State, :SDWORD, :lua_Number>, %(8 + sizeof(lua_Number))
@DefProto LUA_IMPORT_ATTR, luaL_checkinteger, WIN_STD_CALL_CONV,, <:ptr lua_State, :SDWORD>, 8
@DefProto LUA_IMPORT_ATTR, luaL_optinteger, WIN_STD_CALL_CONV,, <:ptr lua_State, :SDWORD, :lua_Integer>, %(8 + sizeof(lua_Integer))
@DefProto LUA_IMPORT_ATTR, luaL_checkstack, WIN_STD_CALL_CONV,, <:ptr lua_State, :SDWORD, :ptr SBYTE>, 12
@DefProto LUA_IMPORT_ATTR, luaL_checktype, WIN_STD_CALL_CONV,, <:ptr lua_State, :SDWORD, :SDWORD>, 12
@DefProto LUA_IMPORT_ATTR, luaL_checkany, WIN_STD_CALL_CONV,, <:ptr lua_State, :SDWORD>, 8
@DefProto LUA_IMPORT_ATTR, luaL_newmetatable, WIN_STD_CALL_CONV,, <:ptr lua_State, :ptr SBYTE>, 8
@DefProto LUA_IMPORT_ATTR, luaL_setmetatable, WIN_STD_CALL_CONV,, <:ptr lua_State, :ptr SBYTE>, 8
@DefProto LUA_IMPORT_ATTR, luaL_testudata, WIN_STD_CALL_CONV,, <:ptr lua_State, :SDWORD, :ptr SBYTE>, 12
@DefProto LUA_IMPORT_ATTR, luaL_checkudata, WIN_STD_CALL_CONV,, <:ptr lua_State, :SDWORD, :ptr SBYTE>, 12
@DefProto LUA_IMPORT_ATTR, luaL_where, WIN_STD_CALL_CONV,, <:ptr lua_State, :SDWORD>, 8
@DefProto LUA_IMPORT_ATTR, luaL_error, C,, <:ptr lua_State, :ptr SBYTE, :vararg>, 12
@DefProto LUA_IMPORT_ATTR, luaL_checkoption, WIN_STD_CALL_CONV,, <:ptr lua_State, :SDWORD, :ptr SBYTE, :ptr ptr SBYTE>, 16
@DefProto LUA_IMPORT_ATTR, luaL_fileresult, WIN_STD_CALL_CONV,, <:ptr lua_State, :SDWORD, :ptr SBYTE>, 12
@DefProto LUA_IMPORT_ATTR, luaL_execresult, WIN_STD_CALL_CONV,, <:ptr lua_State, :SDWORD>, 8

LUA_NOREF equ -2
LUA_REFNIL equ -1

@DefProto LUA_IMPORT_ATTR, luaL_ref, WIN_STD_CALL_CONV,, <:ptr lua_State, :SDWORD>, 8
@DefProto LUA_IMPORT_ATTR, luaL_unref, WIN_STD_CALL_CONV,, <:ptr lua_State, :SDWORD, :SDWORD>, 12
@DefProto LUA_IMPORT_ATTR, luaL_loadfilex, WIN_STD_CALL_CONV,, <:ptr lua_State, :ptr SBYTE, :ptr SBYTE>, 12
@DefProto LUA_IMPORT_ATTR, luaL_loadbufferx, WIN_STD_CALL_CONV,, <:ptr lua_State, :ptr SBYTE, :size_t, :ptr SBYTE, :ptr SBYTE>, 20
@DefProto LUA_IMPORT_ATTR, luaL_loadstring, WIN_STD_CALL_CONV,, <:ptr lua_State, :ptr SBYTE>, 8
@DefProto LUA_IMPORT_ATTR, luaL_newstate, WIN_STD_CALL_CONV,, <>, 0
@DefProto LUA_IMPORT_ATTR, luaL_len, WIN_STD_CALL_CONV,, <:ptr lua_State, :SDWORD>, 8
@DefProto LUA_IMPORT_ATTR, luaL_addgsub, WIN_STD_CALL_CONV,, <:ptr luaL_Buffer, :ptr SBYTE, :ptr SBYTE, :ptr SBYTE>, 16
@DefProto LUA_IMPORT_ATTR, luaL_gsub, WIN_STD_CALL_CONV,, <:ptr lua_State, :ptr SBYTE, :ptr SBYTE, :ptr SBYTE>, 16
@DefProto LUA_IMPORT_ATTR, luaL_setfuncs, WIN_STD_CALL_CONV,, <:ptr lua_State, :ptr luaL_Reg, :SDWORD>, 12
@DefProto LUA_IMPORT_ATTR, luaL_getsubtable, WIN_STD_CALL_CONV,, <:ptr lua_State, :SDWORD, :ptr SBYTE>, 12
@DefProto LUA_IMPORT_ATTR, luaL_traceback, WIN_STD_CALL_CONV,, <:ptr lua_State, :ptr lua_State, :ptr SBYTE, :SDWORD>, 16
@DefProto LUA_IMPORT_ATTR, luaL_requiref, WIN_STD_CALL_CONV,, <:ptr lua_State, :ptr SBYTE, :ptr lua_CFunction, :SDWORD>, 16

luaL_Buffer struct
  b POINTER ?
  size_ size_t ?
  n size_t ?
  L POINTER ?
  union init
    b SBYTE LUAL_BUFFERSIZE dup (?)
  ends
luaL_Buffer ends

@DefProto LUA_IMPORT_ATTR, luaL_buffinit, WIN_STD_CALL_CONV,, <:ptr lua_State, :ptr luaL_Buffer>, 8
@DefProto LUA_IMPORT_ATTR, luaL_prepbuffsize, WIN_STD_CALL_CONV,, <:ptr luaL_Buffer, :size_t>, 8
@DefProto LUA_IMPORT_ATTR, luaL_addlstring, WIN_STD_CALL_CONV,, <:ptr luaL_Buffer, :ptr SBYTE, :size_t>, 12
@DefProto LUA_IMPORT_ATTR, luaL_addstring, WIN_STD_CALL_CONV,, <:ptr luaL_Buffer, :ptr SBYTE>, 8
@DefProto LUA_IMPORT_ATTR, luaL_addvalue, WIN_STD_CALL_CONV,, <:ptr luaL_Buffer>, 4
@DefProto LUA_IMPORT_ATTR, luaL_pushresult, WIN_STD_CALL_CONV,, <:ptr luaL_Buffer>, 4
@DefProto LUA_IMPORT_ATTR, luaL_pushresultsize, WIN_STD_CALL_CONV,, <:ptr luaL_Buffer, :size_t>, 8
@DefProto LUA_IMPORT_ATTR, luaL_buffinitsize, WIN_STD_CALL_CONV,, <:ptr lua_State, :ptr luaL_Buffer, :size_t>, 12
LUA_FILEHANDLE equ HANDLE

luaL_Stream struct
  f       POINTER ?
  closef  plua_CFunction ?
luaL_Stream ends
