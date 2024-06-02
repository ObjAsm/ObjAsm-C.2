;Include file created by h2inc+ version C.2.0 on (UTC) 25/05/2024 16:54:49
;(C) G. Friedrich April 2024
;Source file: d:\objasm\projects\x\h2inc+\h\um_10.0.22621.0\specstrings_strict.h
;             Created on (UTC) 22/05/2024 17:57:08
;             Last modified on (UTC) 16/12/2023 11:05:20

ifndef __SPECSTRINGS_STRICT_LEVEL
  __SPECSTRINGS_STRICT_LEVEL equ 1
endif
if (_MSC_VER ge 1400) and  not Defined(__midl) and  not Defined(_PREFAST_) and (__SPECSTRINGS_STRICT_LEVEL gt 0)
  include specstrings_undef.inc
  __ecount macro size_
    exitm <_SAL_VERSION_CHECK(__ecount)>
  endm
  __bcount macro size_
    exitm <_SAL_VERSION_CHECK(__bcount)>
  endm
  __xcount macro size_
    exitm <_SAL_VERSION_CHECK(__xcount)>
  endm
  __in equ <_SAL_VERSION_CHECK(__in)>
  __in_ecount macro size_
    exitm <_SAL_VERSION_CHECK(__in_ecount)>
  endm
  __in_bcount macro size_
    exitm <_SAL_VERSION_CHECK(__in_bcount)>
  endm
  __in_xcount macro size_
    exitm <_SAL_VERSION_CHECK(__in_xcount)>
  endm
  __in_z equ <_SAL_VERSION_CHECK(__in_z)>
  __in_ecount_z macro size_
    exitm <_SAL_VERSION_CHECK(__in_ecount_z)>
  endm
  __in_bcount_z macro size_
    exitm <_SAL_VERSION_CHECK(__in_bcount_z)>
  endm
  __out equ <_SAL_VERSION_CHECK(__out)>
  __out_ecount macro size_
    exitm <_SAL_VERSION_CHECK(__out_ecount)>
  endm
  __out_bcount macro size_
    exitm <_SAL_VERSION_CHECK(__out_bcount)>
  endm
  __out_xcount macro size_
    exitm <_SAL_VERSION_CHECK(__out_xcount)>
  endm
  __out_ecount_part macro size_, len
    exitm <_SAL_VERSION_CHECK(__out_ecount_part)>
  endm
  __out_bcount_part macro size_, len
    exitm <_SAL_VERSION_CHECK(__out_bcount_part)>
  endm
  __out_xcount_part macro size_, len
    exitm <_SAL_VERSION_CHECK(__out_xcount_part)>
  endm
  __out_ecount_full macro size_
    exitm <_SAL_VERSION_CHECK(__out_ecount_full)>
  endm
  __out_bcount_full macro size_
    exitm <_SAL_VERSION_CHECK(__out_bcount_full)>
  endm
  __out_xcount_full macro size_
    exitm <_SAL_VERSION_CHECK(__out_xcount_full)>
  endm
  __out_z equ <_SAL_VERSION_CHECK(__out_z)>
  __out_ecount_z macro size_
    exitm <_SAL_VERSION_CHECK(__out_ecount_z)>
  endm
  __out_bcount_z macro size_
    exitm <_SAL_VERSION_CHECK(__out_bcount_z)>
  endm
  __inout equ <_SAL_VERSION_CHECK(__inout)>
  __inout_ecount macro size_
    exitm <_SAL_VERSION_CHECK(__inout_ecount)>
  endm
  __inout_bcount macro size_
    exitm <_SAL_VERSION_CHECK(__inout_bcount)>
  endm
  __inout_xcount macro size_
    exitm <_SAL_VERSION_CHECK(__inout_xcount)>
  endm
  __inout_ecount_part macro size_, len
    exitm <_SAL_VERSION_CHECK(__inout_ecount_part)>
  endm
  __inout_bcount_part macro size_, len
    exitm <_SAL_VERSION_CHECK(__inout_bcount_part)>
  endm
  __inout_xcount_part macro size_, len
    exitm <_SAL_VERSION_CHECK(__inout_xcount_part)>
  endm
  __inout_ecount_full macro size_
    exitm <_SAL_VERSION_CHECK(__inout_ecount_full)>
  endm
  __inout_bcount_full macro size_
    exitm <_SAL_VERSION_CHECK(__inout_bcount_full)>
  endm
  __inout_xcount_full macro size_
    exitm <_SAL_VERSION_CHECK(__inout_xcount_full)>
  endm
  __inout_z equ <__allowed(on_parameter)>
  __inout_ecount_z macro size_
    exitm <__allowed(on_parameter)>
  endm
  __inout_bcount_z macro size_
    exitm <__allowed(on_parameter)>
  endm
  __ecount_opt macro size_
    exitm <__allowed(on_parameter)>
  endm
  __bcount_opt macro size_
    exitm <__allowed(on_parameter)>
  endm
  __xcount_opt macro size_
    exitm <__allowed(on_parameter)>
  endm
  __in_opt equ <_SAL_VERSION_CHECK(__in_opt)>
  __in_ecount_opt macro size_
    exitm <_SAL_VERSION_CHECK(__in_ecount_opt)>
  endm
  __in_bcount_opt macro size_
    exitm <_SAL_VERSION_CHECK(__in_bcount_opt)>
  endm
  __in_z_opt equ <__allowed(on_parameter)>
  __in_ecount_z_opt macro size_
    exitm <__allowed(on_parameter)>
  endm
  __in_bcount_z_opt macro size_
    exitm <__allowed(on_parameter)>
  endm
  __in_xcount_opt macro size_
    exitm <__allowed(on_parameter)>
  endm
  __out_opt equ <_SAL_VERSION_CHECK(__out_opt)>
  __out_ecount_opt macro size_
    exitm <_SAL_VERSION_CHECK(__out_ecount_opt)>
  endm
  __out_bcount_opt macro size_
    exitm <_SAL_VERSION_CHECK(__out_bcount_opt)>
  endm
  __out_xcount_opt macro size_
    exitm <__allowed(on_parameter)>
  endm
  __out_ecount_part_opt macro size_, len
    exitm <__allowed(on_parameter)>
  endm
  __out_bcount_part_opt macro size_, len
    exitm <__allowed(on_parameter)>
  endm
  __out_xcount_part_opt macro size_, len
    exitm <__allowed(on_parameter)>
  endm
  __out_ecount_full_opt macro size_
    exitm <__allowed(on_parameter)>
  endm
  __out_bcount_full_opt macro size_
    exitm <__allowed(on_parameter)>
  endm
  __out_xcount_full_opt macro size_
    exitm <__allowed(on_parameter)>
  endm
  __out_ecount_z_opt macro size_
    exitm <__allowed(on_parameter)>
  endm
  __out_bcount_z_opt macro size_
    exitm <__allowed(on_parameter)>
  endm
  __inout_opt equ <_SAL_VERSION_CHECK(__inout_opt)>
  __inout_ecount_opt macro size_
    exitm <_SAL_VERSION_CHECK(__inout_ecount_opt)>
  endm
  __inout_bcount_opt macro size_
    exitm <_SAL_VERSION_CHECK(__inout_bcount_opt)>
  endm
  __inout_xcount_opt macro size_
    exitm <_SAL_VERSION_CHECK(__inout_xcount_opt)>
  endm
  __inout_ecount_part_opt macro size_, len
    exitm <_SAL_VERSION_CHECK(__inout_ecount_part_opt)>
  endm
  __inout_bcount_part_opt macro size_, len
    exitm <_SAL_VERSION_CHECK(__inout_bcount_part_opt)>
  endm
  __inout_xcount_part_opt macro size_, len
    exitm <_SAL_VERSION_CHECK(__inout_xcount_part_opt)>
  endm
  __inout_ecount_full_opt macro size_
    exitm <_SAL_VERSION_CHECK(__inout_ecount_full_opt)>
  endm
  __inout_bcount_full_opt macro size_
    exitm <_SAL_VERSION_CHECK(__inout_bcount_full_opt)>
  endm
  __inout_xcount_full_opt macro size_
    exitm <_SAL_VERSION_CHECK(__inout_xcount_full_opt)>
  endm
  __inout_z_opt equ <__allowed(on_parameter)>
  __inout_ecount_z_opt macro size_
    exitm <__allowed(on_parameter)>
  endm
  __inout_ecount_z_opt macro size_
    exitm <__allowed(on_parameter)>
  endm
  __inout_bcount_z_opt macro size_
    exitm <__allowed(on_parameter)>
  endm
  __deref_ecount macro size_
    exitm <__allowed(on_parameter)>
  endm
  __deref_bcount macro size_
    exitm <__allowed(on_parameter)>
  endm
  __deref_xcount macro size_
    exitm <__allowed(on_parameter)>
  endm
  __deref_in equ <_SAL_VERSION_CHECK(__deref_in)>
  __deref_in_ecount macro size_
    exitm <_SAL_VERSION_CHECK(__deref_in_ecount)>
  endm
  __deref_in_bcount macro size_
    exitm <_SAL_VERSION_CHECK(__deref_in_bcount)>
  endm
  __deref_in_xcount macro size_
    exitm <_SAL_VERSION_CHECK(__deref_in_xcount)>
  endm
  __deref_out equ <_SAL_VERSION_CHECK(__deref_out)>
  __deref_out_ecount macro size_
    exitm <_SAL_VERSION_CHECK(__deref_out_ecount)>
  endm
  __deref_out_bcount macro size_
    exitm <_SAL_VERSION_CHECK(__deref_out_bcount)>
  endm
  __deref_out_xcount macro size_
    exitm <_SAL_VERSION_CHECK(__deref_out_xcount)>
  endm
  __deref_out_ecount_part macro size_, len
    exitm <_SAL_VERSION_CHECK(__deref_out_ecount_part)>
  endm
  __deref_out_bcount_part macro size_, len
    exitm <_SAL_VERSION_CHECK(__deref_out_bcount_part)>
  endm
  __deref_out_xcount_part macro size_, len
    exitm <_SAL_VERSION_CHECK(__deref_out_xcount_part)>
  endm
  __deref_out_ecount_full macro size_
    exitm <_SAL_VERSION_CHECK(__deref_out_ecount_full)>
  endm
  __deref_out_bcount_full macro size_
    exitm <_SAL_VERSION_CHECK(__deref_out_bcount_full)>
  endm
  __deref_out_xcount_full macro size_
    exitm <_SAL_VERSION_CHECK(__deref_out_xcount_full)>
  endm
  __deref_out_z equ <__allowed(on_parameter)>
  __deref_out_ecount_z macro size_
    exitm <__allowed(on_parameter)>
  endm
  __deref_out_bcount_z macro size_
    exitm <__allowed(on_parameter)>
  endm
  __deref_inout equ <_SAL_VERSION_CHECK(__deref_inout)>
  __deref_inout_ecount macro size_
    exitm <_SAL_VERSION_CHECK(__deref_inout_ecount)>
  endm
  __deref_inout_bcount macro size_
    exitm <_SAL_VERSION_CHECK(__deref_inout_bcount)>
  endm
  __deref_inout_xcount macro size_
    exitm <_SAL_VERSION_CHECK(__deref_inout_xcount)>
  endm
  __deref_inout_ecount_part macro size_, len
    exitm <__allowed(on_parameter)>
  endm
  __deref_inout_bcount_part macro size_, len
    exitm <__allowed(on_parameter)>
  endm
  __deref_inout_xcount_part macro size_, len
    exitm <__allowed(on_parameter)>
  endm
  __deref_inout_ecount_full macro size_
    exitm <__allowed(on_parameter)>
  endm
  __deref_inout_bcount_full macro size_
    exitm <__allowed(on_parameter)>
  endm
  __deref_inout_xcount_full macro size_
    exitm <__allowed(on_parameter)>
  endm
  __deref_inout_z equ <__allowed(on_parameter)>
  __deref_inout_ecount_z macro size_
    exitm <__allowed(on_parameter)>
  endm
  __deref_inout_bcount_z macro size_
    exitm <__allowed(on_parameter)>
  endm
  __deref_ecount_opt macro size_
    exitm <__allowed(on_parameter)>
  endm
  __deref_bcount_opt macro size_
    exitm <__allowed(on_parameter)>
  endm
  __deref_xcount_opt macro size_
    exitm <__allowed(on_parameter)>
  endm
  __deref_in_opt equ <__allowed(on_parameter)>
  __deref_in_opt_out equ <__allowed(on_parameter)>
  __deref_in_ecount_opt macro size_
    exitm <__allowed(on_parameter)>
  endm
  __deref_in_bcount_opt macro size_
    exitm <__allowed(on_parameter)>
  endm
  __deref_in_xcount_opt macro size_
    exitm <__allowed(on_parameter)>
  endm
  __deref_out_opt equ <_SAL_VERSION_CHECK(__deref_out_opt)>
  __deref_out_ecount_opt macro size_
    exitm <_SAL_VERSION_CHECK(__deref_out_ecount_opt)>
  endm
  __deref_out_bcount_opt macro size_
    exitm <_SAL_VERSION_CHECK(__deref_out_bcount_opt)>
  endm
  __deref_out_xcount_opt macro size_
    exitm <_SAL_VERSION_CHECK(__deref_out_xcount_opt)>
  endm
  __deref_out_ecount_part_opt macro size_, len
    exitm <_SAL_VERSION_CHECK(__deref_out_ecount_part_opt)>
  endm
  __deref_out_bcount_part_opt macro size_, len
    exitm <_SAL_VERSION_CHECK(__deref_out_bcount_part_opt)>
  endm
  __deref_out_xcount_part_opt macro size_, len
    exitm <_SAL_VERSION_CHECK(__deref_out_xcount_part_opt)>
  endm
  __deref_out_ecount_full_opt macro size_
    exitm <_SAL_VERSION_CHECK(__deref_out_ecount_full_opt)>
  endm
  __deref_out_bcount_full_opt macro size_
    exitm <_SAL_VERSION_CHECK(__deref_out_bcount_full_opt)>
  endm
  __deref_out_xcount_full_opt macro size_
    exitm <_SAL_VERSION_CHECK(__deref_out_xcount_full_opt)>
  endm
  __deref_out_z_opt equ <__allowed(on_parameter)>
  __deref_out_ecount_z_opt macro size_
    exitm <__allowed(on_parameter)>
  endm
  __deref_out_bcount_z_opt macro size_
    exitm <__allowed(on_parameter)>
  endm
  __deref_inout_opt equ <__allowed(on_parameter)>
  __deref_inout_ecount_opt macro size_
    exitm <__allowed(on_parameter)>
  endm
  __deref_inout_bcount_opt macro size_
    exitm <__allowed(on_parameter)>
  endm
  __deref_inout_xcount_opt macro size_
    exitm <__allowed(on_parameter)>
  endm
  __deref_inout_ecount_part_opt macro size_, len
    exitm <__allowed(on_parameter)>
  endm
  __deref_inout_bcount_part_opt macro size_, len
    exitm <__allowed(on_parameter)>
  endm
  __deref_inout_xcount_part_opt macro size_, len
    exitm <__allowed(on_parameter)>
  endm
  __deref_inout_ecount_full_opt macro size_
    exitm <__allowed(on_parameter)>
  endm
  __deref_inout_bcount_full_opt macro size_
    exitm <__allowed(on_parameter)>
  endm
  __deref_inout_xcount_full_opt macro size_
    exitm <__allowed(on_parameter)>
  endm
  __deref_inout_z_opt equ <__allowed(on_parameter)>
  __deref_inout_ecount_z_opt macro size_
    exitm <__allowed(on_parameter)>
  endm
  __deref_inout_bcount_z_opt macro size_
    exitm <__allowed(on_parameter)>
  endm
  __deref_opt_ecount macro size_
    exitm <__allowed(on_parameter)>
  endm
  __deref_opt_bcount macro size_
    exitm <__allowed(on_parameter)>
  endm
  __deref_opt_xcount macro size_
    exitm <__allowed(on_parameter)>
  endm
  __deref_opt_in equ <__allowed(on_parameter)>
  __deref_opt_in_ecount macro size_
    exitm <__allowed(on_parameter)>
  endm
  __deref_opt_in_bcount macro size_
    exitm <__allowed(on_parameter)>
  endm
  __deref_opt_in_xcount macro size_
    exitm <__allowed(on_parameter)>
  endm
  __deref_opt_out equ <_SAL_VERSION_CHECK(__deref_opt_out)>
  __deref_opt_out_ecount macro size_
    exitm <_SAL_VERSION_CHECK(__deref_opt_out_ecount)>
  endm
  __deref_opt_out_bcount macro size_
    exitm <_SAL_VERSION_CHECK(__deref_opt_out_bcount)>
  endm
  __deref_opt_out_xcount macro size_
    exitm <_SAL_VERSION_CHECK(__deref_opt_out_xcount)>
  endm
  __deref_opt_out_ecount_part macro size_, len
    exitm <__allowed(on_parameter)>
  endm
  __deref_opt_out_bcount_part macro size_, len
    exitm <__allowed(on_parameter)>
  endm
  __deref_opt_out_xcount_part macro size_, len
    exitm <__allowed(on_parameter)>
  endm
  __deref_opt_out_ecount_full macro size_
    exitm <__allowed(on_parameter)>
  endm
  __deref_opt_out_bcount_full macro size_
    exitm <__allowed(on_parameter)>
  endm
  __deref_opt_out_xcount_full macro size_
    exitm <__allowed(on_parameter)>
  endm
  __deref_opt_inout equ <__allowed(on_parameter)>
  __deref_opt_inout_ecount macro size_
    exitm <__allowed(on_parameter)>
  endm
  __deref_opt_inout_bcount macro size_
    exitm <__allowed(on_parameter)>
  endm
  __deref_opt_inout_xcount macro size_
    exitm <__allowed(on_parameter)>
  endm
  __deref_opt_inout_ecount_part macro size_, len
    exitm <__allowed(on_parameter)>
  endm
  __deref_opt_inout_bcount_part macro size_, len
    exitm <__allowed(on_parameter)>
  endm
  __deref_opt_inout_xcount_part macro size_, len
    exitm <__allowed(on_parameter)>
  endm
  __deref_opt_inout_ecount_full macro size_
    exitm <__allowed(on_parameter)>
  endm
  __deref_opt_inout_bcount_full macro size_
    exitm <__allowed(on_parameter)>
  endm
  __deref_opt_inout_xcount_full macro size_
    exitm <__allowed(on_parameter)>
  endm
  __deref_opt_inout_z equ <__allowed(on_parameter)>
  __deref_opt_inout_ecount_z macro size_
    exitm <__allowed(on_parameter)>
  endm
  __deref_opt_inout_bcount_z macro size_
    exitm <__allowed(on_parameter)>
  endm
  __deref_opt_ecount_opt macro size_
    exitm <__allowed(on_parameter)>
  endm
  __deref_opt_bcount_opt macro size_
    exitm <__allowed(on_parameter)>
  endm
  __deref_opt_xcount_opt macro size_
    exitm <__allowed(on_parameter)>
  endm
  __deref_opt_in_opt equ <__allowed(on_parameter)>
  __deref_opt_in_ecount_opt macro size_
    exitm <__allowed(on_parameter)>
  endm
  __deref_opt_in_bcount_opt macro size_
    exitm <__allowed(on_parameter)>
  endm
  __deref_opt_in_xcount_opt macro size_
    exitm <__allowed(on_parameter)>
  endm
  __deref_opt_out_opt equ <__allowed(on_parameter)>
  __deref_opt_out_ecount_opt macro size_
    exitm <__allowed(on_parameter)>
  endm
  __deref_opt_out_bcount_opt macro size_
    exitm <__allowed(on_parameter)>
  endm
  __deref_opt_out_xcount_opt macro size_
    exitm <__allowed(on_parameter)>
  endm
  __deref_opt_out_ecount_part_opt macro size_, len
    exitm <__allowed(on_parameter)>
  endm
  __deref_opt_out_bcount_part_opt macro size_, len
    exitm <__allowed(on_parameter)>
  endm
  __deref_opt_out_xcount_part_opt macro size_, len
    exitm <__allowed(on_parameter)>
  endm
  __deref_opt_out_ecount_full_opt macro size_
    exitm <__allowed(on_parameter)>
  endm
  __deref_opt_out_bcount_full_opt macro size_
    exitm <__allowed(on_parameter)>
  endm
  __deref_opt_out_xcount_full_opt macro size_
    exitm <__allowed(on_parameter)>
  endm
  __deref_opt_out_z_opt equ <__allowed(on_parameter)>
  __deref_opt_out_ecount_z_opt macro size_
    exitm <__allowed(on_parameter)>
  endm
  __deref_opt_out_bcount_z_opt macro size_
    exitm <__allowed(on_parameter)>
  endm
  __deref_opt_inout_opt equ <__allowed(on_parameter)>
  __deref_opt_inout_ecount_opt macro size_
    exitm <__allowed(on_parameter)>
  endm
  __deref_opt_inout_bcount_opt macro size_
    exitm <__allowed(on_parameter)>
  endm
  __deref_opt_inout_xcount_opt macro size_
    exitm <__allowed(on_parameter)>
  endm
  __deref_opt_inout_ecount_part_opt macro size_, len
    exitm <__allowed(on_parameter)>
  endm
  __deref_opt_inout_bcount_part_opt macro size_, len
    exitm <__allowed(on_parameter)>
  endm
  __deref_opt_inout_xcount_part_opt macro size_, len
    exitm <__allowed(on_parameter)>
  endm
  __deref_opt_inout_ecount_full_opt macro size_
    exitm <__allowed(on_parameter)>
  endm
  __deref_opt_inout_bcount_full_opt macro size_
    exitm <__allowed(on_parameter)>
  endm
  __deref_opt_inout_xcount_full_opt macro size_
    exitm <__allowed(on_parameter)>
  endm
  __deref_opt_inout_z_opt equ <__allowed(on_parameter)>
  __deref_opt_inout_ecount_z_opt macro size_
    exitm <__allowed(on_parameter)>
  endm
  __deref_opt_inout_bcount_z_opt macro size_
    exitm <__allowed(on_parameter)>
  endm
  __deref_in_ecount_iterator macro size_, incr
    exitm <__allowed(on_parameter)>
  endm
  __deref_out_ecount_iterator macro size_, incr
    exitm <__allowed(on_parameter)>
  endm
  __deref_inout_ecount_iterator macro size_, incr
    exitm <__allowed(on_parameter)>
  endm
  __deref_realloc_bcount macro insize, outsize
    exitm <__allowed(on_parameter)>
  endm
  _Outptr_ equ <__allowed(on_parameter)>
  _Outptr_result_maybenull_ equ <__allowed(on_parameter)>
  _Outptr_opt_ equ <__allowed(on_parameter)>
  _Outptr_opt_result_maybenull_ equ <__allowed(on_parameter)>
  _Outptr_result_z_ equ <__allowed(on_parameter)>
  _Outptr_opt_result_z_ equ <__allowed(on_parameter)>
  _Outptr_result_maybenull_z_ equ <__allowed(on_parameter)>
  _Outptr_opt_result_maybenull_z_ equ <__allowed(on_parameter)>
  _Outptr_result_nullonfailure_ equ <__allowed(on_parameter)>
  _Outptr_opt_result_nullonfailure_ equ <__allowed(on_parameter)>
  _COM_Outptr_ equ <__allowed(on_parameter)>
  _COM_Outptr_result_maybenull_ equ <__allowed(on_parameter)>
  _COM_Outptr_opt_ equ <__allowed(on_parameter)>
  _COM_Outptr_opt_result_maybenull_ equ <__allowed(on_parameter)>
  _Outptr_result_buffer_ macro size_
    exitm <__allowed(on_parameter)>
  endm
  _Outptr_opt_result_buffer_ macro size_
    exitm <__allowed(on_parameter)>
  endm
  _Outptr_result_buffer_to_ macro size_, count
    exitm <__allowed(on_parameter)>
  endm
  _Outptr_opt_result_buffer_to_ macro size_, count
    exitm <__allowed(on_parameter)>
  endm
  _Outptr_result_buffer_all_ macro size_
    exitm <__allowed(on_parameter)>
  endm
  _Outptr_opt_result_buffer_all_ macro size_
    exitm <__allowed(on_parameter)>
  endm
  _Outptr_result_buffer_maybenull_ macro size_
    exitm <__allowed(on_parameter)>
  endm
  _Outptr_opt_result_buffer_maybenull_ macro size_
    exitm <__allowed(on_parameter)>
  endm
  _Outptr_result_buffer_to_maybenull_ macro size_, count
    exitm <__allowed(on_parameter)>
  endm
  _Outptr_opt_result_buffer_to_maybenull_ macro size_, count
    exitm <__allowed(on_parameter)>
  endm
  _Outptr_result_buffer_all_maybenull_ macro size_
    exitm <__allowed(on_parameter)>
  endm
  _Outptr_opt_result_buffer_all_maybenull_ macro size_
    exitm <__allowed(on_parameter)>
  endm
  _Outptr_result_bytebuffer_ macro size_
    exitm <__allowed(on_parameter)>
  endm
  _Outptr_opt_result_bytebuffer_ macro size_
    exitm <__allowed(on_parameter)>
  endm
  _Outptr_result_bytebuffer_to_ macro size_, count
    exitm <__allowed(on_parameter)>
  endm
  _Outptr_opt_result_bytebuffer_to_ macro size_, count
    exitm <__allowed(on_parameter)>
  endm
  _Outptr_result_bytebuffer_all_ macro size_
    exitm <__allowed(on_parameter)>
  endm
  _Outptr_opt_result_bytebuffer_all_ macro size_
    exitm <__allowed(on_parameter)>
  endm
  _Outptr_result_bytebuffer_maybenull_ macro size_
    exitm <__allowed(on_parameter)>
  endm
  _Outptr_opt_result_bytebuffer_maybenull_ macro size_
    exitm <__allowed(on_parameter)>
  endm
  _Outptr_result_bytebuffer_to_maybenull_ macro size_, count
    exitm <__allowed(on_parameter)>
  endm
  _Outptr_opt_result_bytebuffer_to_maybenull_ macro size_, count
    exitm <__allowed(on_parameter)>
  endm
  _Outptr_result_bytebuffer_all_maybenull_ macro size_
    exitm <__allowed(on_parameter)>
  endm
  _Outptr_opt_result_bytebuffer_all_maybenull_ macro size_
    exitm <__allowed(on_parameter)>
  endm
  _Deref_out_ equ <_SAL_VERSION_CHECK(_Deref_out_)>
  _Deref_out_opt_ equ <_SAL_VERSION_CHECK(_Deref_out_opt_)>
  _Deref_opt_out_ equ <_SAL_VERSION_CHECK(_Deref_opt_out_)>
  _Deref_opt_out_opt_ equ <_SAL_VERSION_CHECK(_Deref_opt_out_opt_)>
  _In_count_ macro size_
    exitm <_SAL_VERSION_CHECK(_In_count_)>
  endm
  _In_opt_count_ macro size_
    exitm <_SAL_VERSION_CHECK(_In_opt_count_)>
  endm
  _In_bytecount_ macro size_
    exitm <_SAL_VERSION_CHECK(_In_bytecount_)>
  endm
  _In_opt_bytecount_ macro size_
    exitm <_SAL_VERSION_CHECK(_In_opt_bytecount_)>
  endm
  _Out_cap_ macro size_
    exitm <_SAL_VERSION_CHECK(_Out_cap_)>
  endm
  _Out_opt_cap_ macro size_
    exitm <_SAL_VERSION_CHECK(_Out_opt_cap_)>
  endm
  _Out_bytecap_ macro size_
    exitm <_SAL_VERSION_CHECK(_Out_bytecap_)>
  endm
  _Out_opt_bytecap_ macro size_
    exitm <_SAL_VERSION_CHECK(_Out_opt_bytecap_)>
  endm
  _Deref_post_count_ macro size_
    exitm <_SAL_VERSION_CHECK(_Deref_post_count_)>
  endm
  _Deref_post_opt_count_ macro size_
    exitm <_SAL_VERSION_CHECK(_Deref_post_opt_count_)>
  endm
  _Deref_post_bytecount_ macro size_
    exitm <_SAL_VERSION_CHECK(_Deref_post_bytecount_)>
  endm
  _Deref_post_opt_bytecount_ macro size_
    exitm <_SAL_VERSION_CHECK(_Deref_post_opt_bytecount_)>
  endm
  _Deref_post_cap_ macro size_
    exitm <_SAL_VERSION_CHECK(_Deref_post_cap_)>
  endm
  _Deref_post_opt_cap_ macro size_
    exitm <_SAL_VERSION_CHECK(_Deref_post_opt_cap_)>
  endm
  _Deref_post_bytecap_ macro size_
    exitm <_SAL_VERSION_CHECK(_Deref_post_bytecap_)>
  endm
  _Deref_post_opt_bytecap_ macro size_
    exitm <_SAL_VERSION_CHECK(_Deref_post_opt_bytecap_)>
  endm
  _At_ macro expr, annotes
    exitm <__allowed(on_parameter_or_return)>
  endm
  _When_ macro expr, annotes
    exitm <__allowed(on_parameter_or_return)>
  endm
  __success macro expr
    exitm <_SAL_VERSION_CHECK(__success)>
  endm
  __out_awcount macro expr, size_
    exitm <__allowed(on_parameter)>
  endm
  __in_awcount macro expr, size_
    exitm <__allowed(on_parameter)>
  endm
  __nullterminated equ <_SAL_VERSION_CHECK(__nullterminated)>
  __nullnullterminated equ <_SAL_VERSION_CHECK(__nullnullterminated)>
  __reserved equ <_SAL_VERSION_CHECK(__reserved)>
  __checkReturn equ <_SAL_VERSION_CHECK(__checkReturn)>
  __typefix macro ctype
    exitm <__allowed(on_parameter_or_return)>
  endm
  __override equ <__allowed(on_function)>
  __callback equ <__allowed(on_function)>
  __format_string equ <__allowed(on_parameter_or_return)>
  __blocksOn macro resource
    exitm <__allowed(on_function)>
  endm
  __fallthrough equ <__allowed(as_statement)>
  __range macro lb, ub
    exitm <__allowed(on_return)>
  endm
  __in_range macro lb, ub
    exitm <_SAL_VERSION_CHECK(__in_range)>
  endm
  __out_range macro lb, ub
    exitm <_SAL_VERSION_CHECK(__out_range)>
  endm
  __deref_in_range macro lb, ub
    exitm <__allowed(on_parameter)>
  endm
  __deref_out_range macro lb, ub
    exitm <_SAL_VERSION_CHECK(__deref_out_range)>
  endm
  __deref_inout_range macro lb, ub
    exitm <__allowed(on_parameter)>
  endm
  __field_range macro lb, ub
    exitm <_SAL_VERSION_CHECK(__field_range)>
  endm
  __range_max macro a, b
    exitm <__allowed(on_return)>
  endm
  __range_min macro a, b
    exitm <__allowed(on_return)>
  endm
  __bound equ <__allowed(on_return)>
  __in_bound equ <__allowed(on_parameter)>
  __out_bound equ <__allowed(on_parameter)>
  __deref_out_bound equ <__allowed(on_parameter)>
  __assume_bound macro i
    exitm <__allowed(as_statement_with_arg (i))>
  endm
  __analysis_assume_nullterminated macro x
    exitm <__allowed(as_statement_with_arg (x))>
  endm
  __allocator equ <__allowed(on_function)>
  __deallocate macro kind
    exitm <__allowed(on_parameter)>
  endm
  __deallocate_opt macro kind
    exitm <__allowed(on_parameter)>
  endm
  __post_invalid equ <__allowed(on_parameter_or_return)>
  __post_nullnullterminated equ <__allowed(on_parameter_or_return)>
  __null equ <__allowed(on_typedecl)>
  __notnull equ <__allowed(on_typedecl)>
  __maybenull equ <__allowed(on_typedecl)>
  __exceptthat equ <__allowed(on_typedecl)>
  __field_ecount macro size_
    exitm <_SAL_VERSION_CHECK(__field_ecount)>
  endm
  __field_bcount macro size_
    exitm <_SAL_VERSION_CHECK(__field_bcount)>
  endm
  __field_xcount macro size_
    exitm <__allowed(on_field)>
  endm
  __field_ecount_opt macro size_
    exitm <__allowed(on_field)>
  endm
  __field_bcount_opt macro size_
    exitm <__allowed(on_field)>
  endm
  __field_xcount_opt macro size_
    exitm <__allowed(on_field)>
  endm
  __field_ecount_part macro size_, init
    exitm <__allowed(on_field)>
  endm
  __field_bcount_part macro size_, init
    exitm <__allowed(on_field)>
  endm
  __field_xcount_part macro size_, init
    exitm <__allowed(on_field)>
  endm
  __field_ecount_part_opt macro size_, init
    exitm <__allowed(on_field)>
  endm
  __field_bcount_part_opt macro size_, init
    exitm <__allowed(on_field)>
  endm
  __field_xcount_part_opt macro size_, init
    exitm <__allowed(on_field)>
  endm
  __field_ecount_full macro size_
    exitm <__allowed(on_field)>
  endm
  __field_bcount_full macro size_
    exitm <__allowed(on_field)>
  endm
  __field_xcount_full macro size_
    exitm <__allowed(on_field)>
  endm
  __field_ecount_full_opt macro size_
    exitm <__allowed(on_field)>
  endm
  __field_bcount_full_opt macro size_
    exitm <__allowed(on_field)>
  endm
  __field_xcount_full_opt macro size_
    exitm <__allowed(on_field)>
  endm
  __field_nullterminated equ <__allowed(on_field)>
  __struct_bcount macro size_
    exitm <__allowed(on_struct)>
  endm
  __struct_xcount macro size_
    exitm <__allowed(on_struct)>
  endm
  __control_entrypoint macro category
    exitm <__allowed(on_function)>
  endm
  __rpc_entry equ <__allowed(on_function)>
  __kernel_entry equ <__allowed(on_function)>
  __gdi_entry equ <__allowed(on_function)>
  __in_data_source macro src_sym
    exitm <__allowed(on_parameter)>
  endm
  __out_data_source macro src_sym
    exitm <__allowed(on_parameter)>
  endm
  __field_data_source macro src_sym
    exitm <__allowed(on_field)>
  endm
  __this_out_data_source macro src_syn
    exitm <__allowed(on_function)>
  endm
  __out_validated macro filetype_sym
    exitm <__allowed(on_parameter)>
  endm
  __this_out_validated macro filetype_sym
    exitm <__allowed(on_function)>
  endm
  __file_parser macro filetype_sym
    exitm <__allowed(on_function)>
  endm
  __file_parser_class macro filetype_sym
    exitm <__allowed(on_struct)>
  endm
  __file_parser_library macro filetype_sym
    exitm <__allowed(as_global_decl)>
  endm
  __source_code_content macro codetype_sym
    exitm <__allowed(as_global_decl)>
  endm
  __class_code_content macro codetype_sym
    exitm <__allowed(on_struct)>
  endm
  __encoded_pointer equ <>
  __encoded_array equ <>
  __field_encoded_pointer equ <__allowed(on_field)>
  __field_encoded_array equ <__allowed(on_field)>
  __transfer macro formal
    exitm <__allowed(on_parameter_or_return)>
  endm
  __assume_validated macro exp
    exitm <__allowed(as_statement_with_arg (exp))>
  endm
  __analysis_assume macro expr
    exitm <__allowed(as_statement_with_arg (expr))>
  endm
  __analysis_assert macro expr
    exitm <__allowed(as_statement_with_arg (expr))>
  endm
  __analysis_hint macro hint
    exitm <__allowed(on_function)>
  endm
  __type_has_adt_prop macro adt, prop
    exitm <__allowed(on_typdecl)>
  endm
  __out_has_adt_prop macro adt, prop
    exitm <__allowed(on_parameter)>
  endm
  __out_not_has_adt_prop macro adt, prop
    exitm <__allowed(on_parameter)>
  endm
  __out_transfer_adt_prop macro arg
    exitm <__allowed(on_parameter)>
  endm
  __out_has_type_adt_props macro typ
    exitm <__allowed(on_parameter)>
  endm
  __possibly_notnullterminated equ <__allowed(on_parameter_or_return)>
  __volatile equ <__allowed(on_global_or_field)>
  __deref_volatile equ <__allowed(on_global_or_field)>
  __nonvolatile equ <__allowed(on_global_or_field)>
  __deref_nonvolatile equ <__allowed(on_global_or_field)>
  if (__SPECSTRINGS_STRICT_LEVEL gt 1)
  endif
  __in_nz equ <>
  __in_ecount_nz macro size_
    exitm <>
  endm
  __in_bcount_nz macro size_
    exitm <>
  endm
  __out_nz equ <>
  __out_nz_opt equ <>
  __out_ecount_nz macro size_
    exitm <>
  endm
  __out_bcount_nz macro size_
    exitm <>
  endm
  __inout_nz equ <>
  __inout_ecount_nz macro size_
    exitm <>
  endm
  __inout_bcount_nz macro size_
    exitm <>
  endm
  __in_nz_opt equ <>
  __in_ecount_nz_opt macro size_
    exitm <>
  endm
  __in_bcount_nz_opt macro size_
    exitm <>
  endm
  __out_ecount_nz_opt macro size_
    exitm <>
  endm
  __out_bcount_nz_opt macro size_
    exitm <>
  endm
  __inout_nz_opt equ <>
  __inout_ecount_nz_opt macro size_
    exitm <>
  endm
  __inout_bcount_nz_opt macro size_
    exitm <>
  endm
  __deref_out_nz equ <>
  __deref_out_ecount_nz macro size_
    exitm <>
  endm
  __deref_out_bcount_nz macro size_
    exitm <>
  endm
  __deref_inout_nz equ <>
  __deref_inout_ecount_nz macro size_
    exitm <>
  endm
  __deref_inout_bcount_nz macro size_
    exitm <>
  endm
  __deref_out_nz_opt equ <>
  __deref_out_ecount_nz_opt macro size_
    exitm <>
  endm
  __deref_out_bcount_nz_opt macro size_
    exitm <>
  endm
  __deref_inout_nz_opt equ <>
  __deref_inout_ecount_nz_opt macro size_
    exitm <>
  endm
  __deref_inout_bcount_nz_opt macro size_
    exitm <>
  endm
  __deref_opt_inout_nz equ <>
  __deref_opt_inout_ecount_nz macro size_
    exitm <>
  endm
  __deref_opt_inout_bcount_nz macro size_
    exitm <>
  endm
  __deref_opt_out_nz_opt equ <>
  __deref_opt_out_ecount_nz_opt macro size_
    exitm <>
  endm
  __deref_opt_out_bcount_nz_opt macro size_
    exitm <>
  endm
  __deref_opt_inout_nz_opt equ <>
  __deref_opt_inout_ecount_nz_opt macro size_
    exitm <>
  endm
  __deref_opt_inout_bcount_nz_opt macro size_
    exitm <>
  endm
  __deref equ <>
  __pre equ <>
  __post equ <>
  __readableTo macro count
    exitm <>
  endm
  __writableTo macro count
    exitm <>
  endm
  __maybevalid equ <>
  __inexpressible_readableTo macro string
    exitm <>
  endm
  __data_entrypoint macro category
    exitm <>
  endm
  __readonly equ <>
  __byte_writableTo macro count
    exitm <>
  endm
  __byte_readableTo macro count
    exitm <>
  endm
  __elem_readableTo macro count
    exitm <>
  endm
  __elem_writableTo macro count
    exitm <>
  endm
  __valid equ <>
  __notvalid equ <>
  __refparam equ <>
  __precond macro condition
    exitm <>
  endm
  if  not Defined(_MSC_EXTENSIONS) and  not Defined(_PREFAST_) and  not Defined(OACR)
    __allowed macro p
      exitm <>
    endm
  else
    __allowed macro p
      exitm <__$allowed_ ## p>
    endm
    __$allowed_as_global_decl equ <>
    __$allowed_as_statement_with_arg macro x
      exitm <__pragma (warning (push)) __pragma (warning (disable : 4548)) do { __noop (x) ; } while ((0, 0) __pragma (warning (pop)))>
    endm
    __$allowed_as_statement equ __$allowed_as_statement_with_arg(1)
    __$allowed_on_function_or_typedecl equ <>
    if (__SPECSTRINGS_STRICT_LEVEL eq 1) or (__SPECSTRINGS_STRICT_LEVEL eq 2)
      __$allowed_on_typedecl equ <>
      __$allowed_on_return equ <>
      __$allowed_on_parameter equ <>
      __$allowed_on_function equ <>
      __$allowed_on_struct equ <>
      __$allowed_on_field equ <>
      __$allowed_on_parameter_or_return equ <>
      __$allowed_on_global_or_field equ <>
    elseif __SPECSTRINGS_STRICT_LEVEL eq 3
      __$allowed_on_typedecl equ <>
      __$allowed_on_return equ <[ returnvalue : OnReturnOnly ]>
      __$allowed_on_parameter equ <[ OnParameterOnly ]>
      __$allowed_on_function equ <[ method : OnFunctionOnly ]>
      __$allowed_on_struct equ <[ OnStructOnly ]>
      __$allowed_on_field equ <[ OnFieldOnly ]>
      __$allowed_on_parameter_or_return equ <[ OnParameterOrReturnOnly ]>
      __$allowed_on_global_or_field equ <>
      ifdef __cplusplus
        ;[...]
      else
        SA macro x
          exitm <SA_ ## x>
        endm
        DECL_SA macro name_, loc
          exitm <[ source_annotation_attribute (loc) ] struct name_ { const char * ignored ; } ; typedef struct name_ name_ ;>
        endm
      endif
      DECL_SA(OnParameterOnly, SA(Parameter))
      DECL_SA(OnReturnOnly, SA(ReturnValue))
      DECL_SA(OnFunctionOnly, SA(Method))
      DECL_SA(OnStructOnly, SA(Struct))
      DECL_SA(OnFieldOnly, SA(Field))
      DECL_SA(OnParameterOrReturnOnly, SA(Parameter) or SA(ReturnValue))
    endif
  endif
endif
