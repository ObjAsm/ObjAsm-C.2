;Include file created by h2inc+ version C.2.0 on (UTC) 25/05/2024 20:55:09
;(C) G. Friedrich April 2024
;Source file: d:\objasm\projects\x\h2inc+\h\um_10.0.22621.0\rpcsal.h
;             Created on (UTC) 22/05/2024 17:57:08
;             Last modified on (UTC) 16/12/2023 11:05:40

include specstrings.inc
ifndef __RPCSAL_H_VERSION__
  __RPCSAL_H_VERSION__ equ (100)
endif
ifdef __REQUIRED_RPCSAL_H_VERSION__
  if (__RPCSAL_H_VERSION__ lt __REQUIRED_RPCSAL_H_VERSION__)
    .err <incorrect < rpcsal.h > version. Use the header that matches with the MIDL compiler.>
  endif
endif
ifdef __cplusplus
  ;[...]
endif
ifndef _SAL1_2_Source_
  _SAL1_2_Source_ macro Name_, args, annotes
    exitm <_SA_annotes3(SAL_name, # Name_,, "1.2") _Group_(annotes _SAL_nop_impl_)>
  endm
endif
__RPC__in equ <_SAL1_2_Source_(__RPC__in,, _Pre_ _Notref_ _Notnull_ _Pre_ _Valid_)>
__RPC__in_string equ <_SAL1_2_Source_(__RPC__in_string,, __RPC__in _Pre_ _Null_terminated_)>
__RPC__in_ecount macro size_
  exitm <_SAL1_2_Source_(__RPC__in_ecount, (size_), __RPC__in _Pre_readable_size_(size_))>
endm
__RPC__in_ecount_full macro size_
  exitm <_SAL1_2_Source_(__RPC__in_ecount_full, (size_), __RPC__in_ecount(size_))>
endm
__RPC__in_ecount_full_string macro size_
  exitm <_SAL1_2_Source_(__RPC__in_ecount_full_string, (size_), __RPC__in_ecount_full(size_) _Pre_ _Null_terminated_)>
endm
__RPC__in_ecount_part macro size_, length_
  exitm <_SAL1_2_Source_(__RPC__in_ecount_part, (size_, length_), __RPC__in_ecount(length_) _Pre_writable_size_(size_))>
endm
__RPC__in_xcount macro size_
  exitm <_SAL1_2_Source_(__RPC__in_xcount, (size_), __RPC__in _Pre_readable_size_(size_))>
endm
__RPC__in_xcount_full macro size_
  exitm <_SAL1_2_Source_(__RPC__in_xcount_full, (size_), __RPC__in_ecount(size_))>
endm
__RPC__in_xcount_full_string macro size_
  exitm <_SAL1_2_Source_(__RPC__in_xcount_full_string, (size_), __RPC__in_ecount_full(size_) _Pre_ _Null_terminated_)>
endm
__RPC__in_xcount_part macro size_, length_
  exitm <_SAL1_2_Source_(__RPC__in_xcount_part, (size_, length_), __RPC__in_ecount(length_) _Pre_writable_size_(size_))>
endm
__RPC__deref_in equ <_SAL1_2_Source_(__RPC__deref_in,, __RPC__in _At_(* _Curr_, _Pre_ _Notnull_))>
__RPC__deref_in_string equ <_SAL1_2_Source_(__RPC__deref_in_string,, __RPC__deref_in _At_(* _Curr_, _Pre_ _Null_terminated_))>
__RPC__deref_in_opt equ <_SAL1_2_Source_(__RPC__deref_in_opt,, __RPC__in _At_(* _Curr_, _Pre_ _Maybenull_))>
__RPC__deref_in_opt_string equ <_SAL1_2_Source_(__RPC__deref_in_opt_string,, __RPC__deref_in_opt _At_(* _Curr_, _Pre_ _Null_terminated_))>
__RPC__deref_opt_in equ <_SAL1_2_Source_(__RPC__deref_opt_in,, __RPC__in_opt _At_(* _Curr_, _Pre_ _Notnull_))>
__RPC__deref_opt_in_string equ <_SAL1_2_Source_(__RPC__deref_opt_in_string,, __RPC__deref_opt_in _At_(* _Curr_, _Pre_ _Null_terminated_))>
__RPC__deref_opt_in_opt equ <_SAL1_2_Source_(__RPC__deref_opt_in_opt,, __RPC__in_opt _At_(* _Curr_, _Pre_ _Maybenull_))>
__RPC__deref_opt_in_opt_string equ <_SAL1_2_Source_(__RPC__deref_opt_in_opt_string,, __RPC__deref_opt_in_opt _At_(* _Curr_, _Pre_ _Null_terminated_))>
__RPC__deref_in_ecount macro size_
  exitm <_SAL1_2_Source_(__RPC__deref_in_ecount, (size_), __RPC__in _At_(* _Curr_, _Pre_ _Notnull_ _Pre_readable_size_(size_)))>
endm
__RPC__deref_in_ecount_part macro size_, length_
  exitm <_SAL1_2_Source_(__RPC__deref_in_ecount_part, (size_, length_), __RPC__deref_in_ecount(size_) _At_(* _Curr_, _Pre_readable_size_(length_)))>
endm
__RPC__deref_in_ecount_full macro size_
  exitm <_SAL1_2_Source_(__RPC__deref_in_ecount_full, (size_), __RPC__deref_in_ecount_part(size_, size_))>
endm
__RPC__deref_in_ecount_full_opt macro size_
  exitm <_SAL1_2_Source_(__RPC__deref_in_ecount_full_opt, (size_), __RPC__deref_in_ecount_part_opt(size_, size_))>
endm
__RPC__deref_in_ecount_full_opt_string macro size_
  exitm <_SAL1_2_Source_(__RPC__deref_in_ecount_full_opt_string, (size_), __RPC__deref_in_ecount_full_opt(size_) _At_(* _Curr_, _Pre_ _Null_terminated_))>
endm
__RPC__deref_in_ecount_full_string macro size_
  exitm <_SAL1_2_Source_(__RPC__deref_in_ecount_full_string, (size_), __RPC__deref_in_ecount_full(size_) _At_(* _Curr_, _Pre_ _Null_terminated_))>
endm
__RPC__deref_in_ecount_opt macro size_
  exitm <_SAL1_2_Source_(__RPC__deref_in_ecount_opt, (size_), __RPC__in _At_(* _Curr_, _Pre_ _Maybenull_ _Pre_readable_size_(size_)))>
endm
__RPC__deref_in_ecount_opt_string macro size_
  exitm <_SAL1_2_Source_(__RPC__deref_in_ecount_opt_string, (size_), __RPC__deref_in_ecount_opt(size_) _At_(* _Curr_, _Pre_ _Null_terminated_))>
endm
__RPC__deref_in_ecount_part_opt macro size_, length_
  exitm <_SAL1_2_Source_(__RPC__deref_in_ecount_part_opt, (size_, length_), __RPC__deref_in_ecount_opt(size_) _At_(* _Curr_, _Pre_readable_size_(length_)))>
endm
__RPC__deref_in_xcount macro size_
  exitm <_SAL1_2_Source_(__RPC__deref_in_xcount, (size_), __RPC__deref_in_ecount(size_))>
endm
__RPC__deref_in_xcount_part macro size_, length_
  exitm <_SAL1_2_Source_(__RPC__deref_in_xcount_part, (size_, length_), __RPC__deref_in_ecount_part(size_, length_))>
endm
__RPC__deref_in_xcount_full macro size_
  exitm <_SAL1_2_Source_(__RPC__deref_in_xcount_full, (size_), __RPC__deref_in_ecount_part(size_, size_))>
endm
__RPC__deref_in_xcount_full_opt macro size_
  exitm <_SAL1_2_Source_(__RPC__deref_in_xcount_full_opt, (size_), __RPC__deref_in_ecount_full_opt(size_))>
endm
__RPC__deref_in_xcount_full_opt_string macro size_
  exitm <_SAL1_2_Source_(__RPC__deref_in_xcount_full_opt_string, (size_), __RPC__deref_in_ecount_full_opt_string(size_))>
endm
__RPC__deref_in_xcount_full_string macro size_
  exitm <_SAL1_2_Source_(__RPC__deref_in_xcount_full_string, (size_), __RPC__deref_in_ecount_full_string(size_))>
endm
__RPC__deref_in_xcount_opt macro size_
  exitm <_SAL1_2_Source_(__RPC__deref_in_xcount_opt, (size_), __RPC__deref_in_ecount_opt(size_))>
endm
__RPC__deref_in_xcount_opt_string macro size_
  exitm <_SAL1_2_Source_(__RPC__deref_in_xcount_opt_string, (size_), __RPC__deref_in_ecount_opt_string(size_))>
endm
__RPC__deref_in_xcount_part_opt macro size_, length_
  exitm <_SAL1_2_Source_(__RPC__deref_in_xcount_part_opt, (size_, length_), __RPC__deref_in_ecount_part_opt(size_))>
endm
__RPC__out equ <_SAL1_2_Source_(__RPC__out,, _Out_)>
__RPC__out_ecount macro size_
  exitm <_SAL1_2_Source_(__RPC__out_ecount, (size_), _Out_writes_(size_) _Post_writable_size_(size_))>
endm
__RPC__out_ecount_string macro size_
  exitm <_SAL1_2_Source_(__RPC__out_ecount_string, (size_), __RPC__out_ecount(size_) _Post_ _Null_terminated_)>
endm
__RPC__out_ecount_part macro size_, length_
  exitm <_SAL1_2_Source_(__RPC__out_ecount_part, (size_, length_), __RPC__out_ecount(size_) _Post_readable_size_(length_))>
endm
__RPC__out_ecount_full macro size_
  exitm <_SAL1_2_Source_(__RPC__out_ecount_full, (size_), __RPC__out_ecount_part(size_, size_))>
endm
__RPC__out_ecount_full_string macro size_
  exitm <_SAL1_2_Source_(__RPC__out_ecount_full_string, (size_), __RPC__out_ecount_full(size_) _Post_ _Null_terminated_)>
endm
__RPC__out_xcount macro size_
  exitm <_SAL1_2_Source_(__RPC__out_xcount, (size_), _Out_)>
endm
__RPC__out_xcount_string macro size_
  exitm <_SAL1_2_Source_(__RPC__out_xcount_string, (size_), __RPC__out _Post_ _Null_terminated_)>
endm
__RPC__out_xcount_part macro size_, length_
  exitm <_SAL1_2_Source_(__RPC__out_xcount_part, (size_, length_), __RPC__out)>
endm
__RPC__out_xcount_full macro size_
  exitm <_SAL1_2_Source_(__RPC__out_xcount_full, (size_), __RPC__out)>
endm
__RPC__out_xcount_full_string macro size_
  exitm <_SAL1_2_Source_(__RPC__out_xcount_full_string, (size_), __RPC__out _Post_ _Null_terminated_)>
endm
__RPC__inout equ <_SAL1_2_Source_(__RPC__inout,, _Inout_)>
__RPC__inout_string equ <_SAL1_2_Source_(__RPC__inout_string,, __RPC__inout _Pre_ _Null_terminated_ _Post_ _Null_terminated_)>
__RPC__inout_ecount macro size_
  exitm <_SAL1_2_Source_(__RPC__inout_ecount, (size_), _Inout_updates_(size_))>
endm
__RPC__inout_ecount_part macro size_, length_
  exitm <_SAL1_2_Source_(__RPC__inout_ecount_part, (size_, length_), _Inout_updates_to_(size_, length_))>
endm
__RPC__inout_ecount_full macro size_
  exitm <_SAL1_2_Source_(__RPC__inout_ecount_full, (size_), __RPC__inout_ecount_part(size_, size_))>
endm
__RPC__inout_ecount_full_string macro size_
  exitm <_SAL1_2_Source_(__RPC__inout_ecount_full_string, (size_), __RPC__inout_ecount_full(size_) _Pre_ _Null_terminated_ _Post_ _Null_terminated_)>
endm
__RPC__inout_xcount macro size_
  exitm <_SAL1_2_Source_(__RPC__inout_xcount, (size_), _Inout_)>
endm
__RPC__inout_xcount_part macro size_, length_
  exitm <_SAL1_2_Source_(__RPC__inout_xcount_part, (size_, length_), _Inout_)>
endm
__RPC__inout_xcount_full macro size_
  exitm <_SAL1_2_Source_(__RPC__inout_xcount_full, (size_), __RPC__inout)>
endm
__RPC__inout_xcount_full_string macro size_
  exitm <_SAL1_2_Source_(__RPC__inout_xcount_full_string, (size_), __RPC__inout _Pre_ _Null_terminated_ _Post_ _Null_terminated_)>
endm
__RPC__in_opt equ <_SAL1_2_Source_(__RPC__in_opt,, _Pre_ _Notref_ _Maybenull_ _Pre_ _Valid_)>
__RPC__in_opt_string equ <_SAL1_2_Source_(__RPC__in_opt_string,, __RPC__in_opt _Pre_ _Null_terminated_)>
__RPC__in_ecount_opt macro size_
  exitm <_SAL1_2_Source_(__RPC__in_ecount_opt, (size_), __RPC__in_opt _Pre_readable_size_(size_))>
endm
__RPC__in_ecount_opt_string macro size_
  exitm <_SAL1_2_Source_(__RPC__in_ecount_opt_string, (size_), __RPC__in_ecount_opt(size_) _Pre_ _Null_terminated_)>
endm
__RPC__in_ecount_full_opt macro size_
  exitm <_SAL1_2_Source_(__RPC__in_ecount_full_opt, (size_), __RPC__in_ecount_opt(size_))>
endm
__RPC__in_ecount_full_opt_string macro size_
  exitm <_SAL1_2_Source_(__RPC__in_ecount_full_opt_string, (size_), __RPC__in_ecount_full_opt(size_) _Pre_ _Null_terminated_)>
endm
__RPC__in_ecount_part_opt macro size_, length_
  exitm <_SAL1_2_Source_(__RPC__in_ecount_part_opt, (size_, length_), __RPC__in_ecount_opt(length_) _Pre_writable_size_(size_))>
endm
__RPC__in_xcount_full_opt macro size_
  exitm <_SAL1_2_Source_(__RPC__in_xcount_full_opt, (size_), __RPC__in_ecount_opt(size_))>
endm
__RPC__in_xcount_full_opt_string macro size_
  exitm <_SAL1_2_Source_(__RPC__in_xcount_full_opt_string, (size_), __RPC__in_ecount_full_opt(size_) _Pre_ _Null_terminated_)>
endm
__RPC__in_xcount_part_opt macro size_, length_
  exitm <_SAL1_2_Source_(__RPC__in_xcount_part_opt, (size_, length_), __RPC__in_ecount_part_opt(size_, length_))>
endm
__RPC__in_xcount_opt macro size_
  exitm <_SAL1_2_Source_(__RPC__in_xcount_opt, (size_), __RPC__in_ecount_opt(size_))>
endm
__RPC__in_xcount_opt_string macro size_
  exitm <_SAL1_2_Source_(__RPC__in_xcount_opt_string, (size_), __RPC__in_ecount_opt(size_) _Pre_ _Null_terminated_)>
endm
__RPC__inout_opt equ <_SAL1_2_Source_(__RPC__inout_opt,, _Inout_opt_)>
__RPC__inout_opt_string equ <_SAL1_2_Source_(__RPC__inout_opt_string,, __RPC__inout_opt _Pre_ _Null_terminated_)>
__RPC__inout_ecount_opt macro size_
  exitm <_SAL1_2_Source_(__RPC__inout_ecount_opt, (size_), _Inout_updates_opt_(size_))>
endm
__RPC__inout_ecount_part_opt macro size_, length_
  exitm <_SAL1_2_Source_(__RPC__inout_ecount_part_opt, (size_, length_), _Inout_updates_to_opt_(size_, length_))>
endm
__RPC__inout_ecount_full_opt macro size_
  exitm <_SAL1_2_Source_(__RPC__inout_ecount_full_opt, (size_), __RPC__inout_ecount_part_opt(size_, size_))>
endm
__RPC__inout_ecount_full_opt_string macro size_
  exitm <_SAL1_2_Source_(__RPC__inout_ecount_full_opt_string, (size_), __RPC__inout_ecount_full_opt(size_) _Pre_ _Null_terminated_ _Post_ _Null_terminated_)>
endm
__RPC__inout_xcount_opt macro size_
  exitm <_SAL1_2_Source_(__RPC__inout_xcount_opt, (size_), _Inout_opt_)>
endm
__RPC__inout_xcount_part_opt macro size_, length_
  exitm <_SAL1_2_Source_(__RPC__inout_xcount_part_opt, (size_, length_), _Inout_opt_)>
endm
__RPC__inout_xcount_full_opt macro size_
  exitm <_SAL1_2_Source_(__RPC__inout_xcount_full_opt, (size_), __RPC__inout_opt)>
endm
__RPC__inout_xcount_full_opt_string macro size_
  exitm <_SAL1_2_Source_(__RPC__inout_xcount_full_opt_string, (size_), __RPC__inout_opt _Pre_ _Null_terminated_ _Post_ _Null_terminated_)>
endm
__RPC__deref_out equ <_SAL1_2_Source_(__RPC__deref_out,, _Outptr_)>
__RPC__deref_out_string equ <_SAL1_2_Source_(__RPC__deref_out_string,, _Outptr_result_z_)>
__RPC__deref_out_opt equ <_SAL1_2_Source_(__RPC__deref_out_opt,, __RPC__deref_out)>
__RPC__deref_out_opt_string equ <_SAL1_2_Source_(__RPC__deref_out_opt_string,, _Outptr_result_maybenull_z_ _At_(* _Curr_, _Pre_opt_z_))>
__RPC__deref_out_ecount macro size_
  exitm <_SAL1_2_Source_(__RPC__deref_out_ecount, (size_), _Outptr_result_buffer_(size_))>
endm
__RPC__deref_out_ecount_part macro size_, length_
  exitm <_SAL1_2_Source_(__RPC__deref_out_ecount_part, (size_, length_), _Outptr_result_buffer_to_(size_, length_))>
endm
__RPC__deref_out_ecount_full macro size_
  exitm <_SAL1_2_Source_(__RPC__deref_out_ecount_full, (size_), __RPC__deref_out_ecount_part(size_, size_))>
endm
__RPC__deref_out_ecount_full_string macro size_
  exitm <_SAL1_2_Source_(__RPC__deref_out_ecount_full_string, (size_), __RPC__deref_out_ecount_full(size_) _At_(* _Curr_, _Post_ _Null_terminated_))>
endm
__RPC__deref_out_xcount macro size_
  exitm <_SAL1_2_Source_(__RPC__deref_out_xcount, (size_), _Outptr_)>
endm
__RPC__deref_out_xcount_part macro size_, length_
  exitm <_SAL1_2_Source_(__RPC__deref_out_xcount_part, (size_, length_), __RPC__deref_out)>
endm
__RPC__deref_out_xcount_full macro size_
  exitm <_SAL1_2_Source_(__RPC__deref_out_xcount_full, (size_), __RPC__deref_out)>
endm
__RPC__deref_out_xcount_full_string macro size_
  exitm <_SAL1_2_Source_(__RPC__deref_out_xcount_full_string, (size_), __RPC__deref_out _At_(* _Curr_, _Post_ _Null_terminated_))>
endm
__RPC__deref_inout equ <_SAL1_2_Source_(__RPC__deref_inout,, _Inout_ _At_(* _Curr_, _Pre_ _Notnull_ _Post_ _Notnull_))>
__RPC__deref_inout_string equ <_SAL1_2_Source_(__RPC__deref_inout_string,, __RPC__deref_inout _At_(* _Curr_, _Pre_ _Null_terminated_ _Post_ _Null_terminated_))>
__RPC__deref_inout_opt equ <_SAL1_2_Source_(__RPC__deref_inout_opt,, _Inout_ _At_(* _Curr_, _Pre_ _Maybenull_ _Post_ _Maybenull_))>
__RPC__deref_inout_opt_string equ <_SAL1_2_Source_(__RPC__deref_inout_opt_string,, __RPC__deref_inout_opt _At_(* _Curr_, _Pre_ _Null_terminated_ _Post_ _Null_terminated_))>
__RPC__deref_inout_ecount_opt macro size_
  exitm <_SAL1_2_Source_(__RPC__deref_inout_ecount_opt, (size_), __RPC__deref_inout_opt _At_(* _Curr_, _Pre_writable_size_(size_) _Post_writable_size_(size_)))>
endm
__RPC__deref_inout_ecount_part_opt macro size_, length_
  exitm <_SAL1_2_Source_(__RPC__deref_inout_ecount_part_opt, (size_, length_), __RPC__deref_inout_ecount_opt(size_) _At_(* _Curr_, _Pre_readable_size_(length_) _Post_readable_size_(length_)))>
endm
__RPC__deref_inout_ecount_full_opt macro size_
  exitm <_SAL1_2_Source_(__RPC__deref_inout_ecount_full_opt, (size_), __RPC__deref_inout_ecount_part_opt(size_, size_))>
endm
__RPC__deref_inout_ecount_full macro size_
  exitm <_SAL1_2_Source_(__RPC__deref_inout_ecount_full, (size_), __RPC__deref_inout _At_(* _Curr_, _Pre_readable_size_(size_) _Post_readable_size_(size_)))>
endm
__RPC__deref_inout_ecount_full_string macro size_
  exitm <_SAL1_2_Source_(__RPC__deref_inout_ecount_full_string, (size_), __RPC__deref_inout_ecount_full(size_) _At_(* _Curr_, _Post_ _Null_terminated_))>
endm
__RPC__deref_inout_ecount_full_opt_string macro size_
  exitm <_SAL1_2_Source_(__RPC__deref_inout_ecount_full_opt_string, (size_), __RPC__deref_inout_ecount_full_opt(size_) _At_(* _Curr_, _Pre_ _Null_terminated_ _Post_ _Null_terminated_))>
endm
__RPC__deref_inout_xcount_opt macro size_
  exitm <_SAL1_2_Source_(__RPC__deref_inout_xcount_opt, (size_), __RPC__deref_inout_opt)>
endm
__RPC__deref_inout_xcount_part_opt macro size_, length_
  exitm <_SAL1_2_Source_(__RPC__deref_inout_xcount_part_opt, (size_, length_), __RPC__deref_inout_opt)>
endm
__RPC__deref_inout_xcount_full_opt macro size_
  exitm <_SAL1_2_Source_(__RPC__deref_inout_xcount_full_opt, (size_), __RPC__deref_inout_opt)>
endm
__RPC__deref_inout_xcount_full macro size_
  exitm <_SAL1_2_Source_(__RPC__deref_inout_xcount_full, (size_), __RPC__deref_inout)>
endm
__RPC__deref_inout_xcount_full_string macro size_
  exitm <_SAL1_2_Source_(__RPC__deref_inout_xcount_full_string, (size_), __RPC__deref_inout _At_(* _Curr_, _Post_ _Null_terminated_))>
endm
__RPC__deref_inout_xcount_full_opt_string macro size_
  exitm <_SAL1_2_Source_(__RPC__deref_inout_xcount_full_opt_string, (size_), __RPC__deref_inout_opt _At_(* _Curr_, _Pre_ _Null_terminated_ _Post_ _Null_terminated_))>
endm
__RPC__deref_opt_inout equ <_SAL1_2_Source_(__RPC__deref_opt_inout,, _Inout_opt_ _At_(* _Curr_, _Pre_ _Notnull_ _Post_ _Notnull_))>
__RPC__deref_opt_inout_ecount macro size_
  exitm <_SAL1_2_Source_(__RPC__deref_opt_inout_ecount, (size_), __RPC__deref_opt_inout _At_(* _Curr_, _Pre_writable_size_(size_) _Post_writable_size_(size_)))>
endm
__RPC__deref_opt_inout_string equ <_SAL1_2_Source_(__RPC__deref_opt_inout_string,, __RPC__deref_opt_inout _At_(* _Curr_, _Pre_ _Null_terminated_ _Post_ _Null_terminated_))>
__RPC__deref_opt_inout_ecount_part macro size_, length_
  exitm <_SAL1_2_Source_(__RPC__deref_opt_inout_ecount_part, (size_, length_), __RPC__deref_opt_inout_ecount(size_) _At_(* _Curr_, _Pre_readable_size_(length_) _Post_readable_size_(length_)))>
endm
__RPC__deref_opt_inout_ecount_full macro size_
  exitm <_SAL1_2_Source_(__RPC__deref_opt_inout_ecount_full, (size_), __RPC__deref_opt_inout_ecount_part(size_, size_))>
endm
__RPC__deref_opt_inout_ecount_full_string macro size_
  exitm <_SAL1_2_Source_(__RPC__deref_opt_inout_ecount_full_string, (size_), __RPC__deref_opt_inout_ecount_full(size_) _At_(* _Curr_, _Pre_ _Null_terminated_ _Post_ _Null_terminated_))>
endm
__RPC__deref_opt_inout_xcount_part macro size_, length_
  exitm <_SAL1_2_Source_(__RPC__deref_opt_inout_xcount_part, (size_, length_), __RPC__deref_opt_inout)>
endm
__RPC__deref_opt_inout_xcount_full macro size_
  exitm <_SAL1_2_Source_(__RPC__deref_opt_inout_xcount_full, (size_), __RPC__deref_opt_inout)>
endm
__RPC__deref_opt_inout_xcount_full_string macro size_
  exitm <_SAL1_2_Source_(__RPC__deref_opt_inout_xcount_full_string, (size_), __RPC__deref_opt_inout_string)>
endm
__RPC__deref_out_ecount_opt macro size_
  exitm <_SAL1_2_Source_(__RPC__deref_out_ecount_opt, (size_), _Outptr_result_buffer_maybenull_(size_) _At_(* _Curr_, _Pre_maybenull_))>
endm
__RPC__deref_out_ecount_part_opt macro size_, length_
  exitm <_SAL1_2_Source_(__RPC__deref_out_ecount_part_opt, (size_, length_), _Outptr_result_buffer_to_maybenull_(size_, length_) _At_(* _Curr_, _Pre_maybenull_))>
endm
__RPC__deref_out_ecount_full_opt macro size_
  exitm <_SAL1_2_Source_(__RPC__deref_out_ecount_full_opt, (size_), __RPC__deref_out_ecount_part_opt(size_, size_))>
endm
__RPC__deref_out_ecount_full_opt_string macro size_
  exitm <_SAL1_2_Source_(__RPC__deref_out_ecount_full_opt_string, (size_), __RPC__deref_out_ecount_part_opt(size_, size_) _At_(* _Curr_, _Post_ _Null_terminated_))>
endm
__RPC__deref_out_xcount_opt macro size_
  exitm <_SAL1_2_Source_(__RPC__deref_out_xcount_opt, (size_), __RPC__out _At_(* _Curr_, _Pre_maybenull_ _Pre_writable_size_(_Inexpressible_ (size_)) _Post_ _Maybenull_))>
endm
__RPC__deref_out_xcount_part_opt macro size_, length_
  exitm <_SAL1_2_Source_(__RPC__deref_out_xcount_part_opt, (size_, length_), __RPC__deref_out _At_(* _Curr_, _Pre_maybenull_ _Pre_writable_size_(_Inexpressible_ (size_)) _Post_ _Maybenull_))>
endm
__RPC__deref_out_xcount_full_opt macro size_
  exitm <_SAL1_2_Source_(__RPC__deref_out_xcount_full_opt, (size_), __RPC__deref_out_opt _At_(* _Curr_, _Pre_maybenull_ _Pre_writable_size_(_Inexpressible_ (size_))))>
endm
__RPC__deref_out_xcount_full_opt_string macro size_
  exitm <_SAL1_2_Source_(__RPC__deref_out_xcount_full_opt_string, (size_), __RPC__deref_out_opt _At_(* _Curr_, _Pre_maybenull_ _Pre_writable_size_(_Inexpressible_ (size_)) _Post_ _Null_terminated_))>
endm
__RPC__deref_opt_inout_opt equ <_SAL1_2_Source_(__RPC__deref_opt_inout_opt,, _Inout_opt_ _At_(* _Curr_, _Pre_ _Maybenull_ _Post_ _Maybenull_))>
__RPC__deref_opt_inout_opt_string equ <_SAL1_2_Source_(__RPC__deref_opt_inout_opt_string,, __RPC__deref_opt_inout_opt _At_(* _Curr_, _Pre_ _Null_terminated_ _Post_ _Null_terminated_))>
__RPC__deref_opt_inout_ecount_opt macro size_
  exitm <_SAL1_2_Source_(__RPC__deref_opt_inout_ecount_opt, (size_), _Inout_opt_ _At_(* _Curr_, _Pre_ _Maybenull_ _Pre_writable_size_(size_) _Post_ _Maybenull_ _Post_writable_size_(size_)))>
endm
__RPC__deref_opt_inout_ecount_part_opt macro size_, length_
  exitm <_SAL1_2_Source_(__RPC__deref_opt_inout_ecount_part_opt, (size_, length_), __RPC__deref_opt_inout_ecount_opt(size_) _At_(* _Curr_, _Pre_readable_size_(length_) _Post_readable_size_(length_)))>
endm
__RPC__deref_opt_inout_ecount_full_opt macro size_
  exitm <_SAL1_2_Source_(__RPC__deref_opt_inout_ecount_full_opt, (size_), __RPC__deref_opt_inout_ecount_part_opt(size_, size_))>
endm
__RPC__deref_opt_inout_ecount_full_opt_string macro size_
  exitm <_SAL1_2_Source_(__RPC__deref_opt_inout_ecount_full_opt_string, (size_), __RPC__deref_opt_inout_ecount_full_opt(size_) _At_(* _Curr_, _Pre_ _Null_terminated_ _Post_ _Null_terminated_))>
endm
__RPC__deref_opt_inout_xcount_opt macro size_
  exitm <_SAL1_2_Source_(__RPC__deref_opt_inout_xcount_opt, (size_), __RPC__deref_opt_inout_opt)>
endm
__RPC__deref_opt_inout_xcount_part_opt macro size_, length_
  exitm <_SAL1_2_Source_(__RPC__deref_opt_inout_xcount_part_opt, (size_, length_), __RPC__deref_opt_inout_opt)>
endm
__RPC__deref_opt_inout_xcount_full_opt macro size_
  exitm <_SAL1_2_Source_(__RPC__deref_opt_inout_xcount_full_opt, (size_), __RPC__deref_opt_inout_opt)>
endm
__RPC__deref_opt_inout_xcount_full_opt_string macro size_
  exitm <_SAL1_2_Source_(__RPC__deref_opt_inout_xcount_full_opt_string, (size_), __RPC__deref_opt_inout_opt_string)>
endm
__RPC_full_pointer equ <_SAL1_2_Source_(__RPC_full_pointer,, _Maybenull_)>
__RPC_unique_pointer equ <_SAL1_2_Source_(__RPC_unique_pointer,, _Maybenull_)>
__RPC_ref_pointer equ <_SAL1_2_Source_(__RPC_ref_pointer,, _Notnull_)>
__RPC_string equ <_SAL1_2_Source_(__RPC_string,, _Null_terminated_)>
__RPC__range macro min, max
  exitm <_SAL1_2_Source_(__RPC__range, (min, max), __range(min, max))>
endm
__RPC__in_range macro min, max
  exitm <_SAL1_2_Source_(__RPC__in_range, (min, max), _In_range_(min, max))>
endm
ifdef __cplusplus
  ;[...]
endif
