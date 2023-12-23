;Include file created by h2incX, Version C.01.00, 02/12/2023 23:32
;(C) 2018-today by Biterider, 2005-2009 by Japheth
;Source file: 'lua.h', last modified: 02/12/2023 23:31

LUA_VERSION_MAJOR equ <"5">
LUA_VERSION_MINOR equ <"4">
LUA_VERSION_RELEASE equ <"2">
LUA_VERSION_NUM equ 504
LUA_VERSION_RELEASE_NUM equ (LUA_VERSION_NUM * 100 + 0)
LUA_VERSION equ <"Lua " LUA_VERSION_MAJOR "." LUA_VERSION_MINOR>
LUA_RELEASE equ <LUA_VERSION "." LUA_VERSION_RELEASE>
LUA_COPYRIGHT equ <LUA_RELEASE "  Copyright (C) 1994-2020 Lua.org, PUC-Rio">
LUA_AUTHORS equ <"R. Ierusalimschy, L. H. de Figueiredo, W. Celes">
LUA_SIGNATURE equ <,1bh,"Lua">
LUA_MULTRET equ -1
LUA_REGISTRYINDEX equ (- LUAI_MAXSTACK - 1000)
lua_upvalueindex macro i
  exitm <(LUA_REGISTRYINDEX - (i))>
endm
LUA_OK equ 0
LUA_YIELD equ 1
LUA_ERRRUN equ 2
LUA_ERRSYNTAX equ 3
LUA_ERRMEM equ 4
LUA_ERRERR equ 5

lua_State struct
lua_State ends
plua_State typedef ptr lua_State

LUA_TNONE equ -1
LUA_TNIL equ 0
LUA_TBOOLEAN equ 1
LUA_TLIGHTUSERDATA equ 2
LUA_TNUMBER equ 3
LUA_TSTRING equ 4
LUA_TTABLE equ 5
LUA_TFUNCTION equ 6
LUA_TUSERDATA equ 7
LUA_TTHREAD equ 8
LUA_NUMTYPES equ 9
LUA_MINSTACK equ 20
LUA_RIDX_MAINTHREAD equ 1
LUA_RIDX_GLOBALS equ 2
LUA_RIDX_LAST equ <LUA_RIDX_GLOBALS>

LUA_NUMBER typedef REAL8
lua_Number typedef LUA_NUMBER
lua_Integer typedef LUA_INTEGER
lua_Unsigned typedef LUA_UNSIGNED
lua_KContext typedef ptr
lua_CFunction typedef proto :ptr
plua_CFunction typedef ptr lua_CFunction
lua_KFunction typedef proto :ptr, :SDWORD, :lua_KContext
lua_Reader typedef proto :ptr, :ptr, :ptr size_t
lua_Writer typedef proto :ptr, :ptr, :size_t, :ptr
lua_Alloc typedef proto :ptr, :ptr, :size_t, :size_t
lua_WarnFunction typedef proto :ptr, :ptr SBYTE, :SDWORD

externdef lua_ident:SBYTE
@DefProto DllImport, lua_newstate, WIN_STD_CALL_CONV,, <:lua_Alloc, :ptr>, 8
@DefProto DllImport, lua_close, WIN_STD_CALL_CONV,, <:ptr lua_State>, 4
@DefProto DllImport, lua_newthread, WIN_STD_CALL_CONV,, <:ptr lua_State>, 4
@DefProto DllImport, lua_resetthread, WIN_STD_CALL_CONV,, <:ptr lua_State>, 4
@DefProto DllImport, lua_atpanic, WIN_STD_CALL_CONV,, <:ptr lua_State, :ptr lua_CFunction>, 8
@DefProto DllImport, lua_version, WIN_STD_CALL_CONV,, <:ptr lua_State>, 4
@DefProto DllImport, lua_absindex, WIN_STD_CALL_CONV,, <:ptr lua_State, :SDWORD>, 8
@DefProto DllImport, lua_gettop, WIN_STD_CALL_CONV,, <:ptr lua_State>, 4
@DefProto DllImport, lua_settop, WIN_STD_CALL_CONV,, <:ptr lua_State, :SDWORD>, 8
@DefProto DllImport, lua_pushvalue, WIN_STD_CALL_CONV,, <:ptr lua_State, :SDWORD>, 8
@DefProto DllImport, lua_rotate, WIN_STD_CALL_CONV,, <:ptr lua_State, :SDWORD, :SDWORD>, 12
@DefProto DllImport, lua_copy, WIN_STD_CALL_CONV,, <:ptr lua_State, :SDWORD, :SDWORD>, 12
@DefProto DllImport, lua_checkstack, WIN_STD_CALL_CONV,, <:ptr lua_State, :SDWORD>, 8
@DefProto DllImport, lua_xmove, WIN_STD_CALL_CONV,, <:ptr lua_State, :ptr lua_State, :SDWORD>, 12
@DefProto DllImport, lua_isnumber, WIN_STD_CALL_CONV,, <:ptr lua_State, :SDWORD>, 8
@DefProto DllImport, lua_isstring, WIN_STD_CALL_CONV,, <:ptr lua_State, :SDWORD>, 8
@DefProto DllImport, lua_iscfunction, WIN_STD_CALL_CONV,, <:ptr lua_State, :SDWORD>, 8
@DefProto DllImport, lua_isinteger, WIN_STD_CALL_CONV,, <:ptr lua_State, :SDWORD>, 8
@DefProto DllImport, lua_isuserdata, WIN_STD_CALL_CONV,, <:ptr lua_State, :SDWORD>, 8
@DefProto DllImport, lua_type, WIN_STD_CALL_CONV,, <:ptr lua_State, :SDWORD>, 8
@DefProto DllImport, lua_typename, WIN_STD_CALL_CONV,, <:ptr lua_State, :SDWORD>, 8
@DefProto DllImport, lua_tonumberx, WIN_STD_CALL_CONV,, <:ptr lua_State, :SDWORD, :ptr SDWORD>, 12
@DefProto DllImport, lua_tointegerx, WIN_STD_CALL_CONV,, <:ptr lua_State, :SDWORD, :ptr SDWORD>, 12
@DefProto DllImport, lua_toboolean, WIN_STD_CALL_CONV,, <:ptr lua_State, :SDWORD>, 8
@DefProto DllImport, lua_tolstring, WIN_STD_CALL_CONV,, <:ptr lua_State, :SDWORD, :ptr size_t>, 12
@DefProto DllImport, lua_rawlen, WIN_STD_CALL_CONV,, <:ptr lua_State, :SDWORD>, 8
@DefProto DllImport, lua_tocfunction, WIN_STD_CALL_CONV,, <:ptr lua_State, :SDWORD>, 8
@DefProto DllImport, lua_touserdata, WIN_STD_CALL_CONV,, <:ptr lua_State, :SDWORD>, 8
@DefProto DllImport, lua_tothread, WIN_STD_CALL_CONV,, <:ptr lua_State, :SDWORD>, 8
@DefProto DllImport, lua_topointer, WIN_STD_CALL_CONV,, <:ptr lua_State, :SDWORD>, 8

LUA_OPADD equ 0
LUA_OPSUB equ 1
LUA_OPMUL equ 2
LUA_OPMOD equ 3
LUA_OPPOW equ 4
LUA_OPDIV equ 5
LUA_OPIDIV equ 6
LUA_OPBAND equ 7
LUA_OPBOR equ 8
LUA_OPBXOR equ 9
LUA_OPSHL equ 10
LUA_OPSHR equ 11
LUA_OPUNM equ 12
LUA_OPBNOT equ 13

@DefProto DllImport, lua_arith, WIN_STD_CALL_CONV,, <:ptr lua_State, :SDWORD>, 8

LUA_OPEQ equ 0
LUA_OPLT equ 1
LUA_OPLE equ 2

@DefProto DllImport, lua_rawequal, WIN_STD_CALL_CONV,, <:ptr lua_State, :SDWORD, :SDWORD>, 12
@DefProto DllImport, lua_compare, WIN_STD_CALL_CONV,, <:ptr lua_State, :SDWORD, :SDWORD, :SDWORD>, 16
@DefProto DllImport, lua_pushnil, WIN_STD_CALL_CONV,, <:ptr lua_State>, 4
@DefProto DllImport, lua_pushnumber, WIN_STD_CALL_CONV,, <:ptr lua_State, :lua_Number>, 8
@DefProto DllImport, lua_pushinteger, WIN_STD_CALL_CONV,, <:ptr lua_State, :lua_Integer>, 8
@DefProto DllImport, lua_pushlstring, WIN_STD_CALL_CONV,, <:ptr lua_State, :ptr SBYTE, :size_t>, 12
@DefProto DllImport, lua_pushstring, WIN_STD_CALL_CONV,, <:ptr lua_State, :ptr SBYTE>, 8
@DefProto DllImport, lua_pushvfstring, WIN_STD_CALL_CONV,, <:ptr lua_State, :ptr SBYTE, :va_list>, 12
@DefProto DllImport, lua_pushfstring, C,, <:ptr lua_State, :ptr SBYTE, :vararg>, 12
@DefProto DllImport, lua_pushcclosure, WIN_STD_CALL_CONV,, <:ptr lua_State, :ptr lua_CFunction, :SDWORD>, 12
@DefProto DllImport, lua_pushboolean, WIN_STD_CALL_CONV,, <:ptr lua_State, :SDWORD>, 8
@DefProto DllImport, lua_pushlightuserdata, WIN_STD_CALL_CONV,, <:ptr lua_State, :ptr>, 8
@DefProto DllImport, lua_pushthread, WIN_STD_CALL_CONV,, <:ptr lua_State>, 4
@DefProto DllImport, lua_getglobal, WIN_STD_CALL_CONV,, <:ptr lua_State, :ptr SBYTE>, 8
@DefProto DllImport, lua_gettable, WIN_STD_CALL_CONV,, <:ptr lua_State, :SDWORD>, 8
@DefProto DllImport, lua_getfield, WIN_STD_CALL_CONV,, <:ptr lua_State, :SDWORD, :ptr SBYTE>, 12
@DefProto DllImport, lua_geti, WIN_STD_CALL_CONV,, <:ptr lua_State, :SDWORD, :lua_Integer>, 12
@DefProto DllImport, lua_rawget, WIN_STD_CALL_CONV,, <:ptr lua_State, :SDWORD>, 8
@DefProto DllImport, lua_rawgeti, WIN_STD_CALL_CONV,, <:ptr lua_State, :SDWORD, :lua_Integer>, 12
@DefProto DllImport, lua_rawgetp, WIN_STD_CALL_CONV,, <:ptr lua_State, :SDWORD, :ptr>, 12
@DefProto DllImport, lua_createtable, WIN_STD_CALL_CONV,, <:ptr lua_State, :SDWORD, :SDWORD>, 12
@DefProto DllImport, lua_newuserdatauv, WIN_STD_CALL_CONV,, <:ptr lua_State, :size_t, :SDWORD>, 12
@DefProto DllImport, lua_getmetatable, WIN_STD_CALL_CONV,, <:ptr lua_State, :SDWORD>, 8
@DefProto DllImport, lua_getiuservalue, WIN_STD_CALL_CONV,, <:ptr lua_State, :SDWORD, :SDWORD>, 12
@DefProto DllImport, lua_setglobal, WIN_STD_CALL_CONV,, <:ptr lua_State, :ptr SBYTE>, 8
@DefProto DllImport, lua_settable, WIN_STD_CALL_CONV,, <:ptr lua_State, :SDWORD>, 8
@DefProto DllImport, lua_setfield, WIN_STD_CALL_CONV,, <:ptr lua_State, :SDWORD, :ptr SBYTE>, 12
@DefProto DllImport, lua_seti, WIN_STD_CALL_CONV,, <:ptr lua_State, :SDWORD, :lua_Integer>, 12
@DefProto DllImport, lua_rawset, WIN_STD_CALL_CONV,, <:ptr lua_State, :SDWORD>, 8
@DefProto DllImport, lua_rawseti, WIN_STD_CALL_CONV,, <:ptr lua_State, :SDWORD, :lua_Integer>, 12
@DefProto DllImport, lua_rawsetp, WIN_STD_CALL_CONV,, <:ptr lua_State, :SDWORD, :ptr>, 12
@DefProto DllImport, lua_setmetatable, WIN_STD_CALL_CONV,, <:ptr lua_State, :SDWORD>, 8
@DefProto DllImport, lua_setiuservalue, WIN_STD_CALL_CONV,, <:ptr lua_State, :SDWORD, :SDWORD>, 12
@DefProto DllImport, lua_callk, WIN_STD_CALL_CONV,, <:ptr lua_State, :SDWORD, :SDWORD, :lua_KContext, :ptr lua_KFunction>, 20
@DefProto DllImport, lua_pcallk, WIN_STD_CALL_CONV,, <:ptr lua_State, :SDWORD, :SDWORD, :SDWORD, :lua_KContext, :ptr lua_KFunction>, 24
@DefProto DllImport, lua_load, WIN_STD_CALL_CONV,, <:ptr lua_State, :lua_Reader, :ptr, :ptr SBYTE, :ptr SBYTE>, 20
@DefProto DllImport, lua_dump, WIN_STD_CALL_CONV,, <:ptr lua_State, :lua_Writer, :ptr, :SDWORD>, 16
@DefProto DllImport, lua_yieldk, WIN_STD_CALL_CONV,, <:ptr lua_State, :SDWORD, :lua_KContext, :ptr lua_KFunction>, 16
@DefProto DllImport, lua_resume, WIN_STD_CALL_CONV,, <:ptr lua_State, :ptr lua_State, :SDWORD, :ptr SDWORD>, 16
@DefProto DllImport, lua_status, WIN_STD_CALL_CONV,, <:ptr lua_State>, 4
@DefProto DllImport, lua_isyieldable, WIN_STD_CALL_CONV,, <:ptr lua_State>, 4
@DefProto DllImport, lua_setwarnf, WIN_STD_CALL_CONV,, <:ptr lua_State, :lua_WarnFunction, :ptr>, 12
@DefProto DllImport, lua_warning, WIN_STD_CALL_CONV,, <:ptr lua_State, :ptr SBYTE, :SDWORD>, 12

LUA_GCSTOP equ 0
LUA_GCRESTART equ 1
LUA_GCCOLLECT equ 2
LUA_GCCOUNT equ 3
LUA_GCCOUNTB equ 4
LUA_GCSTEP equ 5
LUA_GCSETPAUSE equ 6
LUA_GCSETSTEPMUL equ 7
LUA_GCISRUNNING equ 9
LUA_GCGEN equ 10
LUA_GCINC equ 11

@DefProto DllImport, lua_gc, C,, <:ptr lua_State, :SDWORD, :vararg>, 12
@DefProto DllImport, lua_error, WIN_STD_CALL_CONV,, <:ptr lua_State>, 4
@DefProto DllImport, lua_next, WIN_STD_CALL_CONV,, <:ptr lua_State, :SDWORD>, 8
@DefProto DllImport, lua_concat, WIN_STD_CALL_CONV,, <:ptr lua_State, :SDWORD>, 8
@DefProto DllImport, lua_len, WIN_STD_CALL_CONV,, <:ptr lua_State, :SDWORD>, 8
@DefProto DllImport, lua_stringtonumber, WIN_STD_CALL_CONV,, <:ptr lua_State, :ptr SBYTE>, 8
@DefProto DllImport, lua_getallocf, WIN_STD_CALL_CONV,, <:ptr lua_State, :ptr ptr>, 8
@DefProto DllImport, lua_setallocf, WIN_STD_CALL_CONV,, <:ptr lua_State, :lua_Alloc, :ptr>, 12
@DefProto DllImport, lua_toclose, WIN_STD_CALL_CONV,, <:ptr lua_State, :SDWORD>, 8

LUA_NUMTAGS equ <LUA_NUMTYPES>
LUA_HOOKCALL equ 0
LUA_HOOKRET equ 1
LUA_HOOKLINE equ 2
LUA_HOOKCOUNT equ 3
LUA_HOOKTAILCALL equ 4
LUA_MASKCALL equ (1 shl LUA_HOOKCALL)
LUA_MASKRET equ (1 shl LUA_HOOKRET)
LUA_MASKLINE equ (1 shl LUA_HOOKLINE)
LUA_MASKCOUNT equ (1 shl LUA_HOOKCOUNT)

@DefProto DllImport, lua_Hook, WIN_STD_CALL_CONV,, <:ptr lua_Debug>, 4
@DefProto DllImport, lua_getstack, WIN_STD_CALL_CONV,, <:ptr lua_State, :SDWORD, :ptr lua_Debug>, 12
@DefProto DllImport, lua_getinfo, WIN_STD_CALL_CONV,, <:ptr lua_State, :ptr SBYTE, :ptr lua_Debug>, 12
@DefProto DllImport, lua_getlocal, WIN_STD_CALL_CONV,, <:ptr lua_State, :ptr lua_Debug, :SDWORD>, 12
@DefProto DllImport, lua_setlocal, WIN_STD_CALL_CONV,, <:ptr lua_State, :ptr lua_Debug, :SDWORD>, 12
@DefProto DllImport, lua_getupvalue, WIN_STD_CALL_CONV,, <:ptr lua_State, :SDWORD, :SDWORD>, 12
@DefProto DllImport, lua_setupvalue, WIN_STD_CALL_CONV,, <:ptr lua_State, :SDWORD, :SDWORD>, 12
@DefProto DllImport, lua_upvalueid, WIN_STD_CALL_CONV,, <:ptr lua_State, :SDWORD, :SDWORD>, 12
@DefProto DllImport, lua_upvaluejoin, WIN_STD_CALL_CONV,, <:ptr lua_State, :SDWORD, :SDWORD, :SDWORD, :SDWORD>, 20
@DefProto DllImport, lua_sethook, WIN_STD_CALL_CONV,, <:ptr lua_State, :POINTER, :SDWORD, :SDWORD>, 16
@DefProto DllImport, lua_gethook, WIN_STD_CALL_CONV,, <:ptr lua_State>, 4
@DefProto DllImport, lua_gethookmask, WIN_STD_CALL_CONV,, <:ptr lua_State>, 4
@DefProto DllImport, lua_gethookcount, WIN_STD_CALL_CONV,, <:ptr lua_State>, 4
@DefProto DllImport, lua_setcstacklimit, WIN_STD_CALL_CONV,, <:ptr lua_State, :DWORD>, 8

lua_Debug struct
  event_ SDWORD ?
  name_ POINTER ?
  namewhat POINTER ?
  what POINTER ?
  source POINTER ?
  srclen size_t ?
  currentline SDWORD ?
  linedefined SDWORD ?
  lastlinedefined SDWORD ?
  nups BYTE ?
  nparams BYTE ?
  isvararg SBYTE ?
  istailcall SBYTE ?
  ftransfer WORD ?
  ntransfer WORD ?
  short_src SBYTE LUA_IDSIZE dup (?)
  i_ci POINTER ?
lua_Debug ends
 