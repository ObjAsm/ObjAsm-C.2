;Include file created by h2incX, Version B.01.01, 10/09/2018 22:03
;(C) 2018-today by Biterider, 2005-2009 by Japheth
;Source file: '\ObjAsm\Projects\h2IncX\header\sal.h', last modified: 19/04/2018 10:43
;Creation parameters: 

__ATTR_SAL equ <>
ifndef _SAL_VERSION
  _SAL_VERSION equ 20
endif
ifndef __SAL_H_VERSION
  __SAL_H_VERSION equ 180000000
endif
ifdef _PREFAST_
  ;[...]
else
  ifndef _USE_DECLSPECS_FOR_SAL
    _USE_DECLSPECS_FOR_SAL equ 0
  endif
  ifndef _USE_ATTRIBUTES_FOR_SAL
    _USE_ATTRIBUTES_FOR_SAL equ 0
  endif
endif
if _USE_DECLSPECS_FOR_SAL and (Defined(MIDL_PASS) or Defined(__midl) or Defined(RC_INVOKED) or  not Defined(_PREFAST_))
  _USE_DECLSPECS_FOR_SAL equ 0
endif
if _USE_ATTRIBUTES_FOR_SAL and ( not Defined(_MSC_EXTENSIONS) or Defined(MIDL_PASS) or Defined(__midl) or Defined(RC_INVOKED))
  _USE_ATTRIBUTES_FOR_SAL equ 0
endif
if _USE_DECLSPECS_FOR_SAL or _USE_ATTRIBUTES_FOR_SAL
  __SAL_YesNo typedef SDWORD
  _SAL_notpresent equ 0
  _SAL_no equ 1
  _SAL_maybe equ 2
  _SAL_yes equ 3
  _SAL_default equ 4
  
endif
if Defined(BUILD_WINDOWS) and  not _USE_ATTRIBUTES_FOR_SAL
  _SAL1_Source_ macro Name_, args, annotes
    exitm <_SA_annotes3(SAL_name, # Name_,, "1") _GrouP_(annotes _SAL_nop_impl_)>
  endm
  _SAL1_1_Source_ macro Name_, args, annotes
    exitm <_SA_annotes3(SAL_name, # Name_,, "1.1") _GrouP_(annotes _SAL_nop_impl_)>
  endm
  _SAL1_2_Source_ macro Name_, args, annotes
    exitm <_SA_annotes3(SAL_name, # Name_,, "1.2") _GrouP_(annotes _SAL_nop_impl_)>
  endm
  _SAL2_Source_ macro Name_, args, annotes
    exitm <_SA_annotes3(SAL_name, # Name_,, "2") _GrouP_(annotes _SAL_nop_impl_)>
  endm
  ifndef _SAL_L_Source_
    _SAL_L_Source_ macro Name_, args, annotes
      exitm <_SA_annotes3(SAL_name, # Name_,, "2") _GrouP_(annotes _SAL_nop_impl_)>
    endm
  endif
else
  _SAL1_Source_ macro Name_, args, annotes
    exitm <_SA_annotes3(SAL_name, # Name_,, "1") _Group_(annotes _SAL_nop_impl_)>
  endm
  _SAL1_1_Source_ macro Name_, args, annotes
    exitm <_SA_annotes3(SAL_name, # Name_,, "1.1") _Group_(annotes _SAL_nop_impl_)>
  endm
  _SAL1_2_Source_ macro Name_, args, annotes
    exitm <_SA_annotes3(SAL_name, # Name_,, "1.2") _Group_(annotes _SAL_nop_impl_)>
  endm
  _SAL2_Source_ macro Name_, args, annotes
    exitm <_SA_annotes3(SAL_name, # Name_,, "2") _Group_(annotes _SAL_nop_impl_)>
  endm
  ifndef _SAL_L_Source_
    _SAL_L_Source_ macro Name_, args, annotes
      exitm <_SA_annotes3(SAL_name, # Name_,, "2") _Group_(annotes _SAL_nop_impl_)>
    endm
  endif
endif
_At_ macro target, annos
  exitm <_At_impl_(target, annos _SAL_nop_impl_)>
endm
_At_buffer_ macro target, iter, bound_, annos
  exitm <_At_buffer_impl_(target, iter, bound_, annos _SAL_nop_impl_)>
endm
_When_ macro expr, annos
  exitm <_When_impl_(expr, annos _SAL_nop_impl_)>
endm
_Group_ macro annos
  exitm <_Group_impl_(annos _SAL_nop_impl_)>
endm
_GrouP_ macro annos
  exitm <_GrouP_impl_(annos _SAL_nop_impl_)>
endm
_Success_ macro expr
  exitm <_SAL2_Source_(_Success_, (expr), _Success_impl_(expr))>
endm
_Return_type_success_ macro expr
  exitm <_SAL2_Source_(_Return_type_success_, (expr), _Success_impl_(expr))>
endm
_On_failure_ macro annos
  exitm <_On_failure_impl_(annos _SAL_nop_impl_)>
endm
_Always_ macro annos
  exitm <_Always_impl_(annos _SAL_nop_impl_)>
endm
_Use_decl_annotations_ equ <_Use_decl_anno_impl_>
_Notref_ equ <_Notref_impl_>
_Pre_defensive_ equ <_SA_annotes0(SAL_pre_defensive)>
_Post_defensive_ equ <_SA_annotes0(SAL_post_defensive)>
_In_defensive_ macro annotes
  exitm <_Pre_defensive_ _Group_(annotes _SAL_nop_impl_)>
endm
_Out_defensive_ macro annotes
  exitm <_Post_defensive_ _Group_(annotes _SAL_nop_impl_)>
endm
_Inout_defensive_ macro annotes
  exitm <_Pre_defensive_ _Post_defensive_ _Group_(annotes _SAL_nop_impl_)>
endm
_Reserved_ equ <_SAL2_Source_(_Reserved_,, _Pre1_impl_(__null_impl))>
_Const_ equ <_SAL2_Source_(_Const_,, _Pre1_impl_(__readaccess_impl_notref))>
_In_ equ <_SAL2_Source_(_In_,, _Pre1_impl_(__notnull_impl_notref) _Pre_valid_impl_ _Deref_pre1_impl_(__readaccess_impl_notref))>
_In_opt_ equ <_SAL2_Source_(_In_opt_,, _Pre1_impl_(__maybenull_impl_notref) _Pre_valid_impl_ _Deref_pre_readonly_)>
_In_z_ equ <_SAL2_Source_(_In_z_,, _In_ _Pre1_impl_(__zterm_impl))>
_In_opt_z_ equ <_SAL2_Source_(_In_opt_z_,, _In_opt_ _Pre1_impl_(__zterm_impl))>
_In_reads_ macro size_
  exitm <_SAL2_Source_(_In_reads_, (size_), _Pre_count_(size_) _Deref_pre_readonly_)>
endm
_In_reads_opt_ macro size_
  exitm <_SAL2_Source_(_In_reads_opt_, (size_), _Pre_opt_count_(size_) _Deref_pre_readonly_)>
endm
_In_reads_bytes_ macro size_
  exitm <_SAL2_Source_(_In_reads_bytes_, (size_), _Pre_bytecount_(size_) _Deref_pre_readonly_)>
endm
_In_reads_bytes_opt_ macro size_
  exitm <_SAL2_Source_(_In_reads_bytes_opt_, (size_), _Pre_opt_bytecount_(size_) _Deref_pre_readonly_)>
endm
_In_reads_z_ macro size_
  exitm <_SAL2_Source_(_In_reads_z_, (size_), _In_reads_(size_) _Pre_z_)>
endm
_In_reads_opt_z_ macro size_
  exitm <_SAL2_Source_(_In_reads_opt_z_, (size_), _Pre_opt_count_(size_) _Deref_pre_readonly_ _Pre_opt_z_)>
endm
_In_reads_or_z_ macro size_
  exitm <_SAL2_Source_(_In_reads_or_z_, (size_), _In_ _When_(_String_length_ (_Curr_) < (size_), _Pre_z_) _When_(_String_length_ (_Curr_) >= (size_), _Pre1_impl_(__count_impl(size_))))>
endm
_In_reads_or_z_opt_ macro size_
  exitm <_SAL2_Source_(_In_reads_or_z_opt_, (size_), _In_opt_ _When_(_String_length_ (_Curr_) < (size_), _Pre_z_) _When_(_String_length_ (_Curr_) >= (size_), _Pre1_impl_(__count_impl(size_))))>
endm
_In_reads_to_ptr_ macro ptr_
  exitm <_SAL2_Source_(_In_reads_to_ptr_, (ptr_), _Pre_ptrdiff_count_(ptr_) _Deref_pre_readonly_)>
endm
_In_reads_to_ptr_opt_ macro ptr_
  exitm <_SAL2_Source_(_In_reads_to_ptr_opt_, (ptr_), _Pre_opt_ptrdiff_count_(ptr_) _Deref_pre_readonly_)>
endm
_In_reads_to_ptr_z_ macro ptr_
  exitm <_SAL2_Source_(_In_reads_to_ptr_z_, (ptr_), _In_reads_to_ptr_(ptr_) _Pre_z_)>
endm
_In_reads_to_ptr_opt_z_ macro ptr_
  exitm <_SAL2_Source_(_In_reads_to_ptr_opt_z_, (ptr_), _Pre_opt_ptrdiff_count_(ptr_) _Deref_pre_readonly_ _Pre_opt_z_)>
endm
_Out_ equ <_SAL2_Source_(_Out_,, _Out_impl_)>
_Out_opt_ equ <_SAL2_Source_(_Out_opt_,, _Out_opt_impl_)>
_Out_writes_ macro size_
  exitm <_SAL2_Source_(_Out_writes_, (size_), _Pre_cap_(size_) _Post_valid_impl_)>
endm
_Out_writes_opt_ macro size_
  exitm <_SAL2_Source_(_Out_writes_opt_, (size_), _Pre_opt_cap_(size_) _Post_valid_impl_)>
endm
_Out_writes_bytes_ macro size_
  exitm <_SAL2_Source_(_Out_writes_bytes_, (size_), _Pre_bytecap_(size_) _Post_valid_impl_)>
endm
_Out_writes_bytes_opt_ macro size_
  exitm <_SAL2_Source_(_Out_writes_bytes_opt_, (size_), _Pre_opt_bytecap_(size_) _Post_valid_impl_)>
endm
_Out_writes_z_ macro size_
  exitm <_SAL2_Source_(_Out_writes_z_, (size_), _Pre_cap_(size_) _Post_valid_impl_ _Post_z_)>
endm
_Out_writes_opt_z_ macro size_
  exitm <_SAL2_Source_(_Out_writes_opt_z_, (size_), _Pre_opt_cap_(size_) _Post_valid_impl_ _Post_z_)>
endm
_Out_writes_to_ macro size_, count
  exitm <_SAL2_Source_(_Out_writes_to_, (size_, count), _Pre_cap_(size_) _Post_valid_impl_ _Post_count_(count))>
endm
_Out_writes_to_opt_ macro size_, count
  exitm <_SAL2_Source_(_Out_writes_to_opt_, (size_, count), _Pre_opt_cap_(size_) _Post_valid_impl_ _Post_count_(count))>
endm
_Out_writes_all_ macro size_
  exitm <_SAL2_Source_(_Out_writes_all_, (size_), _Out_writes_to_(_Old_ (size_), _Old_ (size_)))>
endm
_Out_writes_all_opt_ macro size_
  exitm <_SAL2_Source_(_Out_writes_all_opt_, (size_), _Out_writes_to_opt_(_Old_ (size_), _Old_ (size_)))>
endm
_Out_writes_bytes_to_ macro size_, count
  exitm <_SAL2_Source_(_Out_writes_bytes_to_, (size_, count), _Pre_bytecap_(size_) _Post_valid_impl_ _Post_bytecount_(count))>
endm
_Out_writes_bytes_to_opt_ macro size_, count
  exitm <_SAL2_Source_(_Out_writes_bytes_to_opt_, (size_, count), _Pre_opt_bytecap_(size_) _Post_valid_impl_ _Post_bytecount_(count))>
endm
_Out_writes_bytes_all_ macro size_
  exitm <_SAL2_Source_(_Out_writes_bytes_all_, (size_), _Out_writes_bytes_to_(_Old_ (size_), _Old_ (size_)))>
endm
_Out_writes_bytes_all_opt_ macro size_
  exitm <_SAL2_Source_(_Out_writes_bytes_all_opt_, (size_), _Out_writes_bytes_to_opt_(_Old_ (size_), _Old_ (size_)))>
endm
_Out_writes_to_ptr_ macro ptr_
  exitm <_SAL2_Source_(_Out_writes_to_ptr_, (ptr_), _Pre_ptrdiff_cap_(ptr_) _Post_valid_impl_)>
endm
_Out_writes_to_ptr_opt_ macro ptr_
  exitm <_SAL2_Source_(_Out_writes_to_ptr_opt_, (ptr_), _Pre_opt_ptrdiff_cap_(ptr_) _Post_valid_impl_)>
endm
_Out_writes_to_ptr_z_ macro ptr_
  exitm <_SAL2_Source_(_Out_writes_to_ptr_z_, (ptr_), _Pre_ptrdiff_cap_(ptr_) _Post_valid_impl_ Post_z_)>
endm
_Out_writes_to_ptr_opt_z_ macro ptr_
  exitm <_SAL2_Source_(_Out_writes_to_ptr_opt_z_, (ptr_), _Pre_opt_ptrdiff_cap_(ptr_) _Post_valid_impl_ Post_z_)>
endm
_Inout_ equ <_SAL2_Source_(_Inout_,, _Prepost_valid_)>
_Inout_opt_ equ <_SAL2_Source_(_Inout_opt_,, _Prepost_opt_valid_)>
_Inout_z_ equ <_SAL2_Source_(_Inout_z_,, _Prepost_z_)>
_Inout_opt_z_ equ <_SAL2_Source_(_Inout_opt_z_,, _Prepost_opt_z_)>
_Inout_updates_ macro size_
  exitm <_SAL2_Source_(_Inout_updates_, (size_), _Pre_cap_(size_) _Pre_valid_impl_ _Post_valid_impl_)>
endm
_Inout_updates_opt_ macro size_
  exitm <_SAL2_Source_(_Inout_updates_opt_, (size_), _Pre_opt_cap_(size_) _Pre_valid_impl_ _Post_valid_impl_)>
endm
_Inout_updates_z_ macro size_
  exitm <_SAL2_Source_(_Inout_updates_z_, (size_), _Pre_cap_(size_) _Pre_valid_impl_ _Post_valid_impl_ _Pre1_impl_(__zterm_impl) _Post1_impl_(__zterm_impl))>
endm
_Inout_updates_opt_z_ macro size_
  exitm <_SAL2_Source_(_Inout_updates_opt_z_, (size_), _Pre_opt_cap_(size_) _Pre_valid_impl_ _Post_valid_impl_ _Pre1_impl_(__zterm_impl) _Post1_impl_(__zterm_impl))>
endm
_Inout_updates_to_ macro size_, count
  exitm <_SAL2_Source_(_Inout_updates_to_, (size_, count), _Out_writes_to_(size_, count) _Pre_valid_impl_ _Pre1_impl_(__count_impl(size_)))>
endm
_Inout_updates_to_opt_ macro size_, count
  exitm <_SAL2_Source_(_Inout_updates_to_opt_, (size_, count), _Out_writes_to_opt_(size_, count) _Pre_valid_impl_ _Pre1_impl_(__count_impl(size_)))>
endm
_Inout_updates_all_ macro size_
  exitm <_SAL2_Source_(_Inout_updates_all_, (size_), _Inout_updates_to_(_Old_ (size_), _Old_ (size_)))>
endm
_Inout_updates_all_opt_ macro size_
  exitm <_SAL2_Source_(_Inout_updates_all_opt_, (size_), _Inout_updates_to_opt_(_Old_ (size_), _Old_ (size_)))>
endm
_Inout_updates_bytes_ macro size_
  exitm <_SAL2_Source_(_Inout_updates_bytes_, (size_), _Pre_bytecap_(size_) _Pre_valid_impl_ _Post_valid_impl_)>
endm
_Inout_updates_bytes_opt_ macro size_
  exitm <_SAL2_Source_(_Inout_updates_bytes_opt_, (size_), _Pre_opt_bytecap_(size_) _Pre_valid_impl_ _Post_valid_impl_)>
endm
_Inout_updates_bytes_to_ macro size_, count
  exitm <_SAL2_Source_(_Inout_updates_bytes_to_, (size_, count), _Out_writes_bytes_to_(size_, count) _Pre_valid_impl_ _Pre1_impl_(__bytecount_impl(size_)))>
endm
_Inout_updates_bytes_to_opt_ macro size_, count
  exitm <_SAL2_Source_(_Inout_updates_bytes_to_opt_, (size_, count), _Out_writes_bytes_to_opt_(size_, count) _Pre_valid_impl_ _Pre1_impl_(__bytecount_impl(size_)))>
endm
_Inout_updates_bytes_all_ macro size_
  exitm <_SAL2_Source_(_Inout_updates_bytes_all_, (size_), _Inout_updates_bytes_to_(_Old_ (size_), _Old_ (size_)))>
endm
_Inout_updates_bytes_all_opt_ macro size_
  exitm <_SAL2_Source_(_Inout_updates_bytes_all_opt_, (size_), _Inout_updates_bytes_to_opt_(_Old_ (size_), _Old_ (size_)))>
endm
_Outptr_ equ _SAL2_Source_(_Outptr_,, _Out_impl_ _Deref_post2_impl_(__notnull_impl_notref, __count_impl(1)))
_Outptr_result_maybenull_ equ _SAL2_Source_(_Outptr_result_maybenull_,, _Out_impl_ _Deref_post2_impl_(__maybenull_impl_notref, __count_impl(1)))
_Outptr_opt_ equ _SAL2_Source_(_Outptr_opt_,, _Out_opt_impl_ _Deref_post2_impl_(__notnull_impl_notref, __count_impl(1)))
_Outptr_opt_result_maybenull_ equ _SAL2_Source_(_Outptr_opt_result_maybenull_,, _Out_opt_impl_ _Deref_post2_impl_(__maybenull_impl_notref, __count_impl(1)))
_Outptr_result_z_ equ <_SAL2_Source_(_Outptr_result_z_,, _Out_impl_ _Deref_post_z_)>
_Outptr_opt_result_z_ equ <_SAL2_Source_(_Outptr_opt_result_z_,, _Out_opt_impl_ _Deref_post_z_)>
_Outptr_result_maybenull_z_ equ <_SAL2_Source_(_Outptr_result_maybenull_z_,, _Out_impl_ _Deref_post_opt_z_)>
_Outptr_opt_result_maybenull_z_ equ <_SAL2_Source_(_Outptr_opt_result_maybenull_z_,, _Out_opt_impl_ _Deref_post_opt_z_)>
_Outptr_result_nullonfailure_ equ <_SAL2_Source_(_Outptr_result_nullonfailure_,, _Outptr_ _On_failure_(_Deref_post_null_))>
_Outptr_opt_result_nullonfailure_ equ <_SAL2_Source_(_Outptr_opt_result_nullonfailure_,, _Outptr_opt_ _On_failure_(_Deref_post_null_))>
_COM_Outptr_ equ <_SAL2_Source_(_COM_Outptr_,, _Outptr_ _On_failure_(_Deref_post_null_))>
_COM_Outptr_result_maybenull_ equ <_SAL2_Source_(_COM_Outptr_result_maybenull_,, _Outptr_result_maybenull_ _On_failure_(_Deref_post_null_))>
_COM_Outptr_opt_ equ <_SAL2_Source_(_COM_Outptr_opt_,, _Outptr_opt_ _On_failure_(_Deref_post_null_))>
_COM_Outptr_opt_result_maybenull_ equ <_SAL2_Source_(_COM_Outptr_opt_result_maybenull_,, _Outptr_opt_result_maybenull_ _On_failure_(_Deref_post_null_))>
_Outptr_result_buffer_ macro size_
  exitm <_SAL2_Source_(_Outptr_result_buffer_, (size_), _Out_impl_ _Deref_post2_impl_(__notnull_impl_notref, __cap_impl(size_)))>
endm
_Outptr_opt_result_buffer_ macro size_
  exitm <_SAL2_Source_(_Outptr_opt_result_buffer_, (size_), _Out_opt_impl_ _Deref_post2_impl_(__notnull_impl_notref, __cap_impl(size_)))>
endm
_Outptr_result_buffer_to_ macro size_, count
  exitm <_SAL2_Source_(_Outptr_result_buffer_to_, (size_, count), _Out_impl_ _Deref_post3_impl_(__notnull_impl_notref, __cap_impl(size_), __count_impl(count)))>
endm
_Outptr_opt_result_buffer_to_ macro size_, count
  exitm <_SAL2_Source_(_Outptr_opt_result_buffer_to_, (size_, count), _Out_opt_impl_ _Deref_post3_impl_(__notnull_impl_notref, __cap_impl(size_), __count_impl(count)))>
endm
_Outptr_result_buffer_all_ macro size_
  exitm <_SAL2_Source_(_Outptr_result_buffer_all_, (size_), _Out_impl_ _Deref_post2_impl_(__notnull_impl_notref, __count_impl(size_)))>
endm
_Outptr_opt_result_buffer_all_ macro size_
  exitm <_SAL2_Source_(_Outptr_opt_result_buffer_all_, (size_), _Out_opt_impl_ _Deref_post2_impl_(__notnull_impl_notref, __count_impl(size_)))>
endm
_Outptr_result_buffer_maybenull_ macro size_
  exitm <_SAL2_Source_(_Outptr_result_buffer_maybenull_, (size_), _Out_impl_ _Deref_post2_impl_(__maybenull_impl_notref, __cap_impl(size_)))>
endm
_Outptr_opt_result_buffer_maybenull_ macro size_
  exitm <_SAL2_Source_(_Outptr_opt_result_buffer_maybenull_, (size_), _Out_opt_impl_ _Deref_post2_impl_(__maybenull_impl_notref, __cap_impl(size_)))>
endm
_Outptr_result_buffer_to_maybenull_ macro size_, count
  exitm <_SAL2_Source_(_Outptr_result_buffer_to_maybenull_, (size_, count), _Out_impl_ _Deref_post3_impl_(__maybenull_impl_notref, __cap_impl(size_), __count_impl(count)))>
endm
_Outptr_opt_result_buffer_to_maybenull_ macro size_, count
  exitm <_SAL2_Source_(_Outptr_opt_result_buffer_to_maybenull_, (size_, count), _Out_opt_impl_ _Deref_post3_impl_(__maybenull_impl_notref, __cap_impl(size_), __count_impl(count)))>
endm
_Outptr_result_buffer_all_maybenull_ macro size_
  exitm <_SAL2_Source_(_Outptr_result_buffer_all_maybenull_, (size_), _Out_impl_ _Deref_post2_impl_(__maybenull_impl_notref, __count_impl(size_)))>
endm
_Outptr_opt_result_buffer_all_maybenull_ macro size_
  exitm <_SAL2_Source_(_Outptr_opt_result_buffer_all_maybenull_, (size_), _Out_opt_impl_ _Deref_post2_impl_(__maybenull_impl_notref, __count_impl(size_)))>
endm
_Outptr_result_bytebuffer_ macro size_
  exitm <_SAL2_Source_(_Outptr_result_bytebuffer_, (size_), _Out_impl_ _Deref_post2_impl_(__notnull_impl_notref, __bytecap_impl(size_)))>
endm
_Outptr_opt_result_bytebuffer_ macro size_
  exitm <_SAL2_Source_(_Outptr_opt_result_bytebuffer_, (size_), _Out_opt_impl_ _Deref_post2_impl_(__notnull_impl_notref, __bytecap_impl(size_)))>
endm
_Outptr_result_bytebuffer_to_ macro size_, count
  exitm <_SAL2_Source_(_Outptr_result_bytebuffer_to_, (size_, count), _Out_impl_ _Deref_post3_impl_(__notnull_impl_notref, __bytecap_impl(size_), __bytecount_impl(count)))>
endm
_Outptr_opt_result_bytebuffer_to_ macro size_, count
  exitm <_SAL2_Source_(_Outptr_opt_result_bytebuffer_to_, (size_, count), _Out_opt_impl_ _Deref_post3_impl_(__notnull_impl_notref, __bytecap_impl(size_), __bytecount_impl(count)))>
endm
_Outptr_result_bytebuffer_all_ macro size_
  exitm <_SAL2_Source_(_Outptr_result_bytebuffer_all_, (size_), _Out_impl_ _Deref_post2_impl_(__notnull_impl_notref, __bytecount_impl(size_)))>
endm
_Outptr_opt_result_bytebuffer_all_ macro size_
  exitm <_SAL2_Source_(_Outptr_opt_result_bytebuffer_all_, (size_), _Out_opt_impl_ _Deref_post2_impl_(__notnull_impl_notref, __bytecount_impl(size_)))>
endm
_Outptr_result_bytebuffer_maybenull_ macro size_
  exitm <_SAL2_Source_(_Outptr_result_bytebuffer_maybenull_, (size_), _Out_impl_ _Deref_post2_impl_(__maybenull_impl_notref, __bytecap_impl(size_)))>
endm
_Outptr_opt_result_bytebuffer_maybenull_ macro size_
  exitm <_SAL2_Source_(_Outptr_opt_result_bytebuffer_maybenull_, (size_), _Out_opt_impl_ _Deref_post2_impl_(__maybenull_impl_notref, __bytecap_impl(size_)))>
endm
_Outptr_result_bytebuffer_to_maybenull_ macro size_, count
  exitm <_SAL2_Source_(_Outptr_result_bytebuffer_to_maybenull_, (size_, count), _Out_impl_ _Deref_post3_impl_(__maybenull_impl_notref, __bytecap_impl(size_), __bytecount_impl(count)))>
endm
_Outptr_opt_result_bytebuffer_to_maybenull_ macro size_, count
  exitm <_SAL2_Source_(_Outptr_opt_result_bytebuffer_to_maybenull_, (size_, count), _Out_opt_impl_ _Deref_post3_impl_(__maybenull_impl_notref, __bytecap_impl(size_), __bytecount_impl(count)))>
endm
_Outptr_result_bytebuffer_all_maybenull_ macro size_
  exitm <_SAL2_Source_(_Outptr_result_bytebuffer_all_maybenull_, (size_), _Out_impl_ _Deref_post2_impl_(__maybenull_impl_notref, __bytecount_impl(size_)))>
endm
_Outptr_opt_result_bytebuffer_all_maybenull_ macro size_
  exitm <_SAL2_Source_(_Outptr_opt_result_bytebuffer_all_maybenull_, (size_), _Out_opt_impl_ _Deref_post2_impl_(__maybenull_impl_notref, __bytecount_impl(size_)))>
endm
_Outref_ equ <_SAL2_Source_(_Outref_,, _Out_impl_ _Post_notnull_)>
_Outref_result_maybenull_ equ <_SAL2_Source_(_Outref_result_maybenull_,, _Pre2_impl_(__notnull_impl_notref, __cap_c_one_notref_impl) _Post_maybenull_ _Post_valid_impl_)>
_Outref_result_buffer_ macro size_
  exitm <_SAL2_Source_(_Outref_result_buffer_, (size_), _Outref_ _Post1_impl_(__cap_impl(size_)))>
endm
_Outref_result_bytebuffer_ macro size_
  exitm <_SAL2_Source_(_Outref_result_bytebuffer_, (size_), _Outref_ _Post1_impl_(__bytecap_impl(size_)))>
endm
_Outref_result_buffer_to_ macro size_, count
  exitm <_SAL2_Source_(_Outref_result_buffer_to_, (size_, count), _Outref_result_buffer_(size_) _Post1_impl_(__count_impl(count)))>
endm
_Outref_result_bytebuffer_to_ macro size_, count
  exitm <_SAL2_Source_(_Outref_result_bytebuffer_to_, (size_, count), _Outref_result_bytebuffer_(size_) _Post1_impl_(__bytecount_impl(count)))>
endm
_Outref_result_buffer_all_ macro size_
  exitm <_SAL2_Source_(_Outref_result_buffer_all_, (size_), _Outref_result_buffer_to_(size_, _Old_ (size_)))>
endm
_Outref_result_bytebuffer_all_ macro size_
  exitm <_SAL2_Source_(_Outref_result_bytebuffer_all_, (size_), _Outref_result_bytebuffer_to_(size_, _Old_ (size_)))>
endm
_Outref_result_buffer_maybenull_ macro size_
  exitm <_SAL2_Source_(_Outref_result_buffer_maybenull_, (size_), _Outref_result_maybenull_ _Post1_impl_(__cap_impl(size_)))>
endm
_Outref_result_bytebuffer_maybenull_ macro size_
  exitm <_SAL2_Source_(_Outref_result_bytebuffer_maybenull_, (size_), _Outref_result_maybenull_ _Post1_impl_(__bytecap_impl(size_)))>
endm
_Outref_result_buffer_to_maybenull_ macro size_, count
  exitm <_SAL2_Source_(_Outref_result_buffer_to_maybenull_, (size_, count), _Outref_result_buffer_maybenull_(size_) _Post1_impl_(__count_impl(count)))>
endm
_Outref_result_bytebuffer_to_maybenull_ macro size_, count
  exitm <_SAL2_Source_(_Outref_result_bytebuffer_to_maybenull_, (size_, count), _Outref_result_bytebuffer_maybenull_(size_) _Post1_impl_(__bytecount_impl(count)))>
endm
_Outref_result_buffer_all_maybenull_ macro size_
  exitm <_SAL2_Source_(_Outref_result_buffer_all_maybenull_, (size_), _Outref_result_buffer_to_maybenull_(size_, _Old_ (size_)))>
endm
_Outref_result_bytebuffer_all_maybenull_ macro size_
  exitm <_SAL2_Source_(_Outref_result_bytebuffer_all_maybenull_, (size_), _Outref_result_bytebuffer_to_maybenull_(size_, _Old_ (size_)))>
endm
_Outref_result_nullonfailure_ equ <_SAL2_Source_(_Outref_result_nullonfailure_,, _Outref_ _On_failure_(_Post_null_))>
_Result_nullonfailure_ equ <_SAL2_Source_(_Result_nullonfailure_,, _On_failure_(_Notref_impl_ _Deref_impl_ _Post_null_))>
_Result_zeroonfailure_ equ _SAL2_Source_(_Result_zeroonfailure_,, _On_failure_(_Notref_impl_ _Deref_impl_ _Out_range_(eq, 0)))
_Ret_z_ equ <_SAL2_Source_(_Ret_z_,, _Ret2_impl_(__notnull_impl, __zterm_impl) _Ret_valid_impl_)>
_Ret_maybenull_z_ equ <_SAL2_Source_(_Ret_maybenull_z_,, _Ret2_impl_(__maybenull_impl, __zterm_impl) _Ret_valid_impl_)>
_Ret_notnull_ equ <_SAL2_Source_(_Ret_notnull_,, _Ret1_impl_(__notnull_impl))>
_Ret_maybenull_ equ <_SAL2_Source_(_Ret_maybenull_,, _Ret1_impl_(__maybenull_impl))>
_Ret_null_ equ <_SAL2_Source_(_Ret_null_,, _Ret1_impl_(__null_impl))>
_Ret_valid_ equ <_SAL2_Source_(_Ret_valid_,, _Ret1_impl_(__notnull_impl_notref) _Ret_valid_impl_)>
_Ret_writes_ macro size_
  exitm <_SAL2_Source_(_Ret_writes_, (size_), _Ret2_impl_(__notnull_impl, __count_impl(size_)) _Ret_valid_impl_)>
endm
_Ret_writes_z_ macro size_
  exitm <_SAL2_Source_(_Ret_writes_z_, (size_), _Ret3_impl_(__notnull_impl, __count_impl(size_), __zterm_impl) _Ret_valid_impl_)>
endm
_Ret_writes_bytes_ macro size_
  exitm <_SAL2_Source_(_Ret_writes_bytes_, (size_), _Ret2_impl_(__notnull_impl, __bytecount_impl(size_)) _Ret_valid_impl_)>
endm
_Ret_writes_maybenull_ macro size_
  exitm <_SAL2_Source_(_Ret_writes_maybenull_, (size_), _Ret2_impl_(__maybenull_impl, __count_impl(size_)) _Ret_valid_impl_)>
endm
_Ret_writes_maybenull_z_ macro size_
  exitm <_SAL2_Source_(_Ret_writes_maybenull_z_, (size_), _Ret3_impl_(__maybenull_impl, __count_impl(size_), __zterm_impl) _Ret_valid_impl_)>
endm
_Ret_writes_bytes_maybenull_ macro size_
  exitm <_SAL2_Source_(_Ret_writes_bytes_maybenull_, (size_), _Ret2_impl_(__maybenull_impl, __bytecount_impl(size_)) _Ret_valid_impl_)>
endm
_Ret_writes_to_ macro size_, count
  exitm <_SAL2_Source_(_Ret_writes_to_, (size_, count), _Ret3_impl_(__notnull_impl, __cap_impl(size_), __count_impl(count)) _Ret_valid_impl_)>
endm
_Ret_writes_bytes_to_ macro size_, count
  exitm <_SAL2_Source_(_Ret_writes_bytes_to_, (size_, count), _Ret3_impl_(__notnull_impl, __bytecap_impl(size_), __bytecount_impl(count)) _Ret_valid_impl_)>
endm
_Ret_writes_to_maybenull_ macro size_, count
  exitm <_SAL2_Source_(_Ret_writes_to_maybenull_, (size_, count), _Ret3_impl_(__maybenull_impl, __cap_impl(size_), __count_impl(count)) _Ret_valid_impl_)>
endm
_Ret_writes_bytes_to_maybenull_ macro size_, count
  exitm <_SAL2_Source_(_Ret_writes_bytes_to_maybenull_, (size_, count), _Ret3_impl_(__maybenull_impl, __bytecap_impl(size_), __bytecount_impl(count)) _Ret_valid_impl_)>
endm
_Points_to_data_ equ <_SAL2_Source_(_Points_to_data_,, _Pre_ _Points_to_data_impl_)>
_Literal_ equ <_SAL2_Source_(_Literal_,, _Pre_ _Literal_impl_)>
_Notliteral_ equ <_SAL2_Source_(_Notliteral_,, _Pre_ _Notliteral_impl_)>
_Check_return_ equ <_SAL2_Source_(_Check_return_,, _Check_return_impl_)>
_Must_inspect_result_ equ <_SAL2_Source_(_Must_inspect_result_,, _Must_inspect_impl_ _Check_return_impl_)>
_Printf_format_string_ equ <_SAL2_Source_(_Printf_format_string_,, _Printf_format_string_impl_)>
_Scanf_format_string_ equ <_SAL2_Source_(_Scanf_format_string_,, _Scanf_format_string_impl_)>
_Scanf_s_format_string_ equ <_SAL2_Source_(_Scanf_s_format_string_,, _Scanf_s_format_string_impl_)>
_Format_string_impl_ macro kind, where
  exitm <_SA_annotes2(SAL_IsFormatString2, kind, where)>
endm
_Printf_format_string_params_ macro x
  exitm <_SAL2_Source_(_Printf_format_string_params_, (x), _Format_string_impl_("printf", x))>
endm
_Scanf_format_string_params_ macro x
  exitm <_SAL2_Source_(_Scanf_format_string_params_, (x), _Format_string_impl_("scanf", x))>
endm
_Scanf_s_format_string_params_ macro x
  exitm <_SAL2_Source_(_Scanf_s_format_string_params_, (x), _Format_string_impl_("scanf_s", x))>
endm
_In_range_ macro lb, ub
  exitm <_SAL2_Source_(_In_range_, (lb, ub), _In_range_impl_(lb, ub))>
endm
_Out_range_ macro lb, ub
  exitm <_SAL2_Source_(_Out_range_, (lb, ub), _Out_range_impl_(lb, ub))>
endm
_Ret_range_ macro lb, ub
  exitm <_SAL2_Source_(_Ret_range_, (lb, ub), _Ret_range_impl_(lb, ub))>
endm
_Deref_in_range_ macro lb, ub
  exitm <_SAL2_Source_(_Deref_in_range_, (lb, ub), _Deref_in_range_impl_(lb, ub))>
endm
_Deref_out_range_ macro lb, ub
  exitm <_SAL2_Source_(_Deref_out_range_, (lb, ub), _Deref_out_range_impl_(lb, ub))>
endm
_Deref_ret_range_ macro lb, ub
  exitm <_SAL2_Source_(_Deref_ret_range_, (lb, ub), _Deref_ret_range_impl_(lb, ub))>
endm
_Pre_equal_to_ macro expr
  exitm <_SAL2_Source_(_Pre_equal_to_, (expr), _In_range_(==, expr))>
endm
_Post_equal_to_ macro expr
  exitm <_SAL2_Source_(_Post_equal_to_, (expr), _Out_range_(==, expr))>
endm
_Unchanged_ macro e
  exitm <_SAL2_Source_(_Unchanged_, (e), _At_(e, _Post_equal_to_(_Old_ (e)) _Const_))>
endm
_Pre_satisfies_ macro cond
  exitm <_SAL2_Source_(_Pre_satisfies_, (cond), _Pre_satisfies_impl_(cond))>
endm
_Post_satisfies_ macro cond
  exitm <_SAL2_Source_(_Post_satisfies_, (cond), _Post_satisfies_impl_(cond))>
endm
_Struct_size_bytes_ macro size_
  exitm <_SAL2_Source_(_Struct_size_bytes_, (size_), _Writable_bytes_(size_))>
endm
_Field_size_ macro size_
  exitm <_SAL2_Source_(_Field_size_, (size_), _Notnull_ _Writable_elements_(size_))>
endm
_Field_size_opt_ macro size_
  exitm <_SAL2_Source_(_Field_size_opt_, (size_), _Maybenull_ _Writable_elements_(size_))>
endm
_Field_size_part_ macro size_, count
  exitm <_SAL2_Source_(_Field_size_part_, (size_, count), _Notnull_ _Writable_elements_(size_) _Readable_elements_(count))>
endm
_Field_size_part_opt_ macro size_, count
  exitm <_SAL2_Source_(_Field_size_part_opt_, (size_, count), _Maybenull_ _Writable_elements_(size_) _Readable_elements_(count))>
endm
_Field_size_full_ macro size_
  exitm <_SAL2_Source_(_Field_size_full_, (size_), _Field_size_part_(size_, size_))>
endm
_Field_size_full_opt_ macro size_
  exitm <_SAL2_Source_(_Field_size_full_opt_, (size_), _Field_size_part_opt_(size_, size_))>
endm
_Field_size_bytes_ macro size_
  exitm <_SAL2_Source_(_Field_size_bytes_, (size_), _Notnull_ _Writable_bytes_(size_))>
endm
_Field_size_bytes_opt_ macro size_
  exitm <_SAL2_Source_(_Field_size_bytes_opt_, (size_), _Maybenull_ _Writable_bytes_(size_))>
endm
_Field_size_bytes_part_ macro size_, count
  exitm <_SAL2_Source_(_Field_size_bytes_part_, (size_, count), _Notnull_ _Writable_bytes_(size_) _Readable_bytes_(count))>
endm
_Field_size_bytes_part_opt_ macro size_, count
  exitm <_SAL2_Source_(_Field_size_bytes_part_opt_, (size_, count), _Maybenull_ _Writable_bytes_(size_) _Readable_bytes_(count))>
endm
_Field_size_bytes_full_ macro size_
  exitm <_SAL2_Source_(_Field_size_bytes_full_, (size_), _Field_size_bytes_part_(size_, size_))>
endm
_Field_size_bytes_full_opt_ macro size_
  exitm <_SAL2_Source_(_Field_size_bytes_full_opt_, (size_), _Field_size_bytes_part_opt_(size_, size_))>
endm
_Field_z_ equ <_SAL2_Source_(_Field_z_,, _Null_terminated_)>
_Field_range_ macro min, max
  exitm <_SAL2_Source_(_Field_range_, (min, max), _Field_range_impl_(min, max))>
endm
_Pre_ equ <_Pre_impl_>
_Post_ equ <_Post_impl_>
_Valid_ equ <_Valid_impl_>
_Notvalid_ equ <_Notvalid_impl_>
_Maybevalid_ equ <_Maybevalid_impl_>
_Readable_bytes_ macro size_
  exitm <_SAL2_Source_(_Readable_bytes_, (size_), _Readable_bytes_impl_(size_))>
endm
_Readable_elements_ macro size_
  exitm <_SAL2_Source_(_Readable_elements_, (size_), _Readable_elements_impl_(size_))>
endm
_Writable_bytes_ macro size_
  exitm <_SAL2_Source_(_Writable_bytes_, (size_), _Writable_bytes_impl_(size_))>
endm
_Writable_elements_ macro size_
  exitm <_SAL2_Source_(_Writable_elements_, (size_), _Writable_elements_impl_(size_))>
endm
_Null_terminated_ equ <_SAL2_Source_(_Null_terminated_,, _Null_terminated_impl_)>
_NullNull_terminated_ equ <_SAL2_Source_(_NullNull_terminated_,, _NullNull_terminated_impl_)>
_Pre_readable_size_ macro size_
  exitm <_SAL2_Source_(_Pre_readable_size_, (size_), _Pre1_impl_(__count_impl(size_)) _Pre_valid_impl_)>
endm
_Pre_writable_size_ macro size_
  exitm <_SAL2_Source_(_Pre_writable_size_, (size_), _Pre1_impl_(__cap_impl(size_)))>
endm
_Pre_readable_byte_size_ macro size_
  exitm <_SAL2_Source_(_Pre_readable_byte_size_, (size_), _Pre1_impl_(__bytecount_impl(size_)) _Pre_valid_impl_)>
endm
_Pre_writable_byte_size_ macro size_
  exitm <_SAL2_Source_(_Pre_writable_byte_size_, (size_), _Pre1_impl_(__bytecap_impl(size_)))>
endm
_Post_readable_size_ macro size_
  exitm <_SAL2_Source_(_Post_readable_size_, (size_), _Post1_impl_(__count_impl(size_)) _Post_valid_impl_)>
endm
_Post_writable_size_ macro size_
  exitm <_SAL2_Source_(_Post_writable_size_, (size_), _Post1_impl_(__cap_impl(size_)))>
endm
_Post_readable_byte_size_ macro size_
  exitm <_SAL2_Source_(_Post_readable_byte_size_, (size_), _Post1_impl_(__bytecount_impl(size_)) _Post_valid_impl_)>
endm
_Post_writable_byte_size_ macro size_
  exitm <_SAL2_Source_(_Post_writable_byte_size_, (size_), _Post1_impl_(__bytecap_impl(size_)))>
endm
_Null_ equ <_SAL2_Source_(_Null_,, _Null_impl_)>
_Notnull_ equ <_SAL2_Source_(_Notnull_,, _Notnull_impl_)>
_Maybenull_ equ <_SAL2_Source_(_Maybenull_,, _Maybenull_impl_)>
_Pre_z_ equ <_SAL2_Source_(_Pre_z_,, _Pre1_impl_(__zterm_impl) _Pre_valid_impl_)>
_Pre_valid_ equ <_SAL2_Source_(_Pre_valid_,, _Pre1_impl_(__notnull_impl_notref) _Pre_valid_impl_)>
_Pre_opt_valid_ equ <_SAL2_Source_(_Pre_opt_valid_,, _Pre1_impl_(__maybenull_impl_notref) _Pre_valid_impl_)>
_Pre_invalid_ equ <_SAL2_Source_(_Pre_invalid_,, _Deref_pre1_impl_(__notvalid_impl))>
_Pre_unknown_ equ <_SAL2_Source_(_Pre_unknown_,, _Pre1_impl_(__maybevalid_impl))>
_Pre_notnull_ equ <_SAL2_Source_(_Pre_notnull_,, _Pre1_impl_(__notnull_impl_notref))>
_Pre_maybenull_ equ <_SAL2_Source_(_Pre_maybenull_,, _Pre1_impl_(__maybenull_impl_notref))>
_Pre_null_ equ <_SAL2_Source_(_Pre_null_,, _Pre1_impl_(__null_impl_notref))>
_Post_z_ equ <_SAL2_Source_(_Post_z_,, _Post1_impl_(__zterm_impl) _Post_valid_impl_)>
_Post_valid_ equ <_SAL2_Source_(_Post_valid_,, _Post_valid_impl_)>
_Post_invalid_ equ <_SAL2_Source_(_Post_invalid_,, _Deref_post1_impl_(__notvalid_impl))>
_Post_ptr_invalid_ equ <_SAL2_Source_(_Post_ptr_invalid_,, _Post1_impl_(__notvalid_impl))>
_Post_notnull_ equ <_SAL2_Source_(_Post_notnull_,, _Post1_impl_(__notnull_impl))>
_Post_null_ equ <_SAL2_Source_(_Post_null_,, _Post1_impl_(__null_impl))>
_Post_maybenull_ equ <_SAL2_Source_(_Post_maybenull_,, _Post1_impl_(__maybenull_impl))>
_Prepost_z_ equ <_SAL2_Source_(_Prepost_z_,, _Pre_z_ _Post_z_)>
_In_count_ macro size_
  exitm <_SAL1_1_Source_(_In_count_, (size_), _Pre_count_(size_) _Deref_pre_readonly_)>
endm
_In_opt_count_ macro size_
  exitm <_SAL1_1_Source_(_In_opt_count_, (size_), _Pre_opt_count_(size_) _Deref_pre_readonly_)>
endm
_In_bytecount_ macro size_
  exitm <_SAL1_1_Source_(_In_bytecount_, (size_), _Pre_bytecount_(size_) _Deref_pre_readonly_)>
endm
_In_opt_bytecount_ macro size_
  exitm <_SAL1_1_Source_(_In_opt_bytecount_, (size_), _Pre_opt_bytecount_(size_) _Deref_pre_readonly_)>
endm
_In_count_c_ macro size_
  exitm <_SAL1_1_Source_(_In_count_c_, (size_), _Pre_count_c_(size_) _Deref_pre_readonly_)>
endm
_In_opt_count_c_ macro size_
  exitm <_SAL1_1_Source_(_In_opt_count_c_, (size_), _Pre_opt_count_c_(size_) _Deref_pre_readonly_)>
endm
_In_bytecount_c_ macro size_
  exitm <_SAL1_1_Source_(_In_bytecount_c_, (size_), _Pre_bytecount_c_(size_) _Deref_pre_readonly_)>
endm
_In_opt_bytecount_c_ macro size_
  exitm <_SAL1_1_Source_(_In_opt_bytecount_c_, (size_), _Pre_opt_bytecount_c_(size_) _Deref_pre_readonly_)>
endm
_In_z_count_ macro size_
  exitm <_SAL1_1_Source_(_In_z_count_, (size_), _Pre_z_ _Pre_count_(size_) _Deref_pre_readonly_)>
endm
_In_opt_z_count_ macro size_
  exitm <_SAL1_1_Source_(_In_opt_z_count_, (size_), _Pre_opt_z_ _Pre_opt_count_(size_) _Deref_pre_readonly_)>
endm
_In_z_bytecount_ macro size_
  exitm <_SAL1_1_Source_(_In_z_bytecount_, (size_), _Pre_z_ _Pre_bytecount_(size_) _Deref_pre_readonly_)>
endm
_In_opt_z_bytecount_ macro size_
  exitm <_SAL1_1_Source_(_In_opt_z_bytecount_, (size_), _Pre_opt_z_ _Pre_opt_bytecount_(size_) _Deref_pre_readonly_)>
endm
_In_z_count_c_ macro size_
  exitm <_SAL1_1_Source_(_In_z_count_c_, (size_), _Pre_z_ _Pre_count_c_(size_) _Deref_pre_readonly_)>
endm
_In_opt_z_count_c_ macro size_
  exitm <_SAL1_1_Source_(_In_opt_z_count_c_, (size_), _Pre_opt_z_ _Pre_opt_count_c_(size_) _Deref_pre_readonly_)>
endm
_In_z_bytecount_c_ macro size_
  exitm <_SAL1_1_Source_(_In_z_bytecount_c_, (size_), _Pre_z_ _Pre_bytecount_c_(size_) _Deref_pre_readonly_)>
endm
_In_opt_z_bytecount_c_ macro size_
  exitm <_SAL1_1_Source_(_In_opt_z_bytecount_c_, (size_), _Pre_opt_z_ _Pre_opt_bytecount_c_(size_) _Deref_pre_readonly_)>
endm
_In_ptrdiff_count_ macro size_
  exitm <_SAL1_1_Source_(_In_ptrdiff_count_, (size_), _Pre_ptrdiff_count_(size_) _Deref_pre_readonly_)>
endm
_In_opt_ptrdiff_count_ macro size_
  exitm <_SAL1_1_Source_(_In_opt_ptrdiff_count_, (size_), _Pre_opt_ptrdiff_count_(size_) _Deref_pre_readonly_)>
endm
_In_count_x_ macro size_
  exitm <_SAL1_1_Source_(_In_count_x_, (size_), _Pre_count_x_(size_) _Deref_pre_readonly_)>
endm
_In_opt_count_x_ macro size_
  exitm <_SAL1_1_Source_(_In_opt_count_x_, (size_), _Pre_opt_count_x_(size_) _Deref_pre_readonly_)>
endm
_In_bytecount_x_ macro size_
  exitm <_SAL1_1_Source_(_In_bytecount_x_, (size_), _Pre_bytecount_x_(size_) _Deref_pre_readonly_)>
endm
_In_opt_bytecount_x_ macro size_
  exitm <_SAL1_1_Source_(_In_opt_bytecount_x_, (size_), _Pre_opt_bytecount_x_(size_) _Deref_pre_readonly_)>
endm
_Out_cap_ macro size_
  exitm <_SAL1_1_Source_(_Out_cap_, (size_), _Pre_cap_(size_) _Post_valid_impl_)>
endm
_Out_opt_cap_ macro size_
  exitm <_SAL1_1_Source_(_Out_opt_cap_, (size_), _Pre_opt_cap_(size_) _Post_valid_impl_)>
endm
_Out_bytecap_ macro size_
  exitm <_SAL1_1_Source_(_Out_bytecap_, (size_), _Pre_bytecap_(size_) _Post_valid_impl_)>
endm
_Out_opt_bytecap_ macro size_
  exitm <_SAL1_1_Source_(_Out_opt_bytecap_, (size_), _Pre_opt_bytecap_(size_) _Post_valid_impl_)>
endm
_Out_cap_c_ macro size_
  exitm <_SAL1_1_Source_(_Out_cap_c_, (size_), _Pre_cap_c_(size_) _Post_valid_impl_)>
endm
_Out_opt_cap_c_ macro size_
  exitm <_SAL1_1_Source_(_Out_opt_cap_c_, (size_), _Pre_opt_cap_c_(size_) _Post_valid_impl_)>
endm
_Out_bytecap_c_ macro size_
  exitm <_SAL1_1_Source_(_Out_bytecap_c_, (size_), _Pre_bytecap_c_(size_) _Post_valid_impl_)>
endm
_Out_opt_bytecap_c_ macro size_
  exitm <_SAL1_1_Source_(_Out_opt_bytecap_c_, (size_), _Pre_opt_bytecap_c_(size_) _Post_valid_impl_)>
endm
_Out_cap_m_ macro mult, size_
  exitm <_SAL1_1_Source_(_Out_cap_m_, (mult, size_), _Pre_cap_m_(mult, size_) _Post_valid_impl_)>
endm
_Out_opt_cap_m_ macro mult, size_
  exitm <_SAL1_1_Source_(_Out_opt_cap_m_, (mult, size_), _Pre_opt_cap_m_(mult, size_) _Post_valid_impl_)>
endm
_Out_z_cap_m_ macro mult, size_
  exitm <_SAL1_1_Source_(_Out_z_cap_m_, (mult, size_), _Pre_cap_m_(mult, size_) _Post_valid_impl_ _Post_z_)>
endm
_Out_opt_z_cap_m_ macro mult, size_
  exitm <_SAL1_1_Source_(_Out_opt_z_cap_m_, (mult, size_), _Pre_opt_cap_m_(mult, size_) _Post_valid_impl_ _Post_z_)>
endm
_Out_ptrdiff_cap_ macro size_
  exitm <_SAL1_1_Source_(_Out_ptrdiff_cap_, (size_), _Pre_ptrdiff_cap_(size_) _Post_valid_impl_)>
endm
_Out_opt_ptrdiff_cap_ macro size_
  exitm <_SAL1_1_Source_(_Out_opt_ptrdiff_cap_, (size_), _Pre_opt_ptrdiff_cap_(size_) _Post_valid_impl_)>
endm
_Out_cap_x_ macro size_
  exitm <_SAL1_1_Source_(_Out_cap_x_, (size_), _Pre_cap_x_(size_) _Post_valid_impl_)>
endm
_Out_opt_cap_x_ macro size_
  exitm <_SAL1_1_Source_(_Out_opt_cap_x_, (size_), _Pre_opt_cap_x_(size_) _Post_valid_impl_)>
endm
_Out_bytecap_x_ macro size_
  exitm <_SAL1_1_Source_(_Out_bytecap_x_, (size_), _Pre_bytecap_x_(size_) _Post_valid_impl_)>
endm
_Out_opt_bytecap_x_ macro size_
  exitm <_SAL1_1_Source_(_Out_opt_bytecap_x_, (size_), _Pre_opt_bytecap_x_(size_) _Post_valid_impl_)>
endm
_Out_z_cap_ macro size_
  exitm <_SAL1_1_Source_(_Out_z_cap_, (size_), _Pre_cap_(size_) _Post_valid_impl_ _Post_z_)>
endm
_Out_opt_z_cap_ macro size_
  exitm <_SAL1_1_Source_(_Out_opt_z_cap_, (size_), _Pre_opt_cap_(size_) _Post_valid_impl_ _Post_z_)>
endm
_Out_z_bytecap_ macro size_
  exitm <_SAL1_1_Source_(_Out_z_bytecap_, (size_), _Pre_bytecap_(size_) _Post_valid_impl_ _Post_z_)>
endm
_Out_opt_z_bytecap_ macro size_
  exitm <_SAL1_1_Source_(_Out_opt_z_bytecap_, (size_), _Pre_opt_bytecap_(size_) _Post_valid_impl_ _Post_z_)>
endm
_Out_z_cap_c_ macro size_
  exitm <_SAL1_1_Source_(_Out_z_cap_c_, (size_), _Pre_cap_c_(size_) _Post_valid_impl_ _Post_z_)>
endm
_Out_opt_z_cap_c_ macro size_
  exitm <_SAL1_1_Source_(_Out_opt_z_cap_c_, (size_), _Pre_opt_cap_c_(size_) _Post_valid_impl_ _Post_z_)>
endm
_Out_z_bytecap_c_ macro size_
  exitm <_SAL1_1_Source_(_Out_z_bytecap_c_, (size_), _Pre_bytecap_c_(size_) _Post_valid_impl_ _Post_z_)>
endm
_Out_opt_z_bytecap_c_ macro size_
  exitm <_SAL1_1_Source_(_Out_opt_z_bytecap_c_, (size_), _Pre_opt_bytecap_c_(size_) _Post_valid_impl_ _Post_z_)>
endm
_Out_z_cap_x_ macro size_
  exitm <_SAL1_1_Source_(_Out_z_cap_x_, (size_), _Pre_cap_x_(size_) _Post_valid_impl_ _Post_z_)>
endm
_Out_opt_z_cap_x_ macro size_
  exitm <_SAL1_1_Source_(_Out_opt_z_cap_x_, (size_), _Pre_opt_cap_x_(size_) _Post_valid_impl_ _Post_z_)>
endm
_Out_z_bytecap_x_ macro size_
  exitm <_SAL1_1_Source_(_Out_z_bytecap_x_, (size_), _Pre_bytecap_x_(size_) _Post_valid_impl_ _Post_z_)>
endm
_Out_opt_z_bytecap_x_ macro size_
  exitm <_SAL1_1_Source_(_Out_opt_z_bytecap_x_, (size_), _Pre_opt_bytecap_x_(size_) _Post_valid_impl_ _Post_z_)>
endm
_Out_cap_post_count_ macro cap, count
  exitm <_SAL1_1_Source_(_Out_cap_post_count_, (cap, count), _Pre_cap_(cap) _Post_valid_impl_ _Post_count_(count))>
endm
_Out_opt_cap_post_count_ macro cap, count
  exitm <_SAL1_1_Source_(_Out_opt_cap_post_count_, (cap, count), _Pre_opt_cap_(cap) _Post_valid_impl_ _Post_count_(count))>
endm
_Out_bytecap_post_bytecount_ macro cap, count
  exitm <_SAL1_1_Source_(_Out_bytecap_post_bytecount_, (cap, count), _Pre_bytecap_(cap) _Post_valid_impl_ _Post_bytecount_(count))>
endm
_Out_opt_bytecap_post_bytecount_ macro cap, count
  exitm <_SAL1_1_Source_(_Out_opt_bytecap_post_bytecount_, (cap, count), _Pre_opt_bytecap_(cap) _Post_valid_impl_ _Post_bytecount_(count))>
endm
_Out_z_cap_post_count_ macro cap, count
  exitm <_SAL1_1_Source_(_Out_z_cap_post_count_, (cap, count), _Pre_cap_(cap) _Post_valid_impl_ _Post_z_count_(count))>
endm
_Out_opt_z_cap_post_count_ macro cap, count
  exitm <_SAL1_1_Source_(_Out_opt_z_cap_post_count_, (cap, count), _Pre_opt_cap_(cap) _Post_valid_impl_ _Post_z_count_(count))>
endm
_Out_z_bytecap_post_bytecount_ macro cap, count
  exitm <_SAL1_1_Source_(_Out_z_bytecap_post_bytecount_, (cap, count), _Pre_bytecap_(cap) _Post_valid_impl_ _Post_z_bytecount_(count))>
endm
_Out_opt_z_bytecap_post_bytecount_ macro cap, count
  exitm <_SAL1_1_Source_(_Out_opt_z_bytecap_post_bytecount_, (cap, count), _Pre_opt_bytecap_(cap) _Post_valid_impl_ _Post_z_bytecount_(count))>
endm
_Out_capcount_ macro capcount
  exitm <_SAL1_1_Source_(_Out_capcount_, (capcount), _Pre_cap_(capcount) _Post_valid_impl_ _Post_count_(capcount))>
endm
_Out_opt_capcount_ macro capcount
  exitm <_SAL1_1_Source_(_Out_opt_capcount_, (capcount), _Pre_opt_cap_(capcount) _Post_valid_impl_ _Post_count_(capcount))>
endm
_Out_bytecapcount_ macro capcount
  exitm <_SAL1_1_Source_(_Out_bytecapcount_, (capcount), _Pre_bytecap_(capcount) _Post_valid_impl_ _Post_bytecount_(capcount))>
endm
_Out_opt_bytecapcount_ macro capcount
  exitm <_SAL1_1_Source_(_Out_opt_bytecapcount_, (capcount), _Pre_opt_bytecap_(capcount) _Post_valid_impl_ _Post_bytecount_(capcount))>
endm
_Out_capcount_x_ macro capcount
  exitm <_SAL1_1_Source_(_Out_capcount_x_, (capcount), _Pre_cap_x_(capcount) _Post_valid_impl_ _Post_count_x_(capcount))>
endm
_Out_opt_capcount_x_ macro capcount
  exitm <_SAL1_1_Source_(_Out_opt_capcount_x_, (capcount), _Pre_opt_cap_x_(capcount) _Post_valid_impl_ _Post_count_x_(capcount))>
endm
_Out_bytecapcount_x_ macro capcount
  exitm <_SAL1_1_Source_(_Out_bytecapcount_x_, (capcount), _Pre_bytecap_x_(capcount) _Post_valid_impl_ _Post_bytecount_x_(capcount))>
endm
_Out_opt_bytecapcount_x_ macro capcount
  exitm <_SAL1_1_Source_(_Out_opt_bytecapcount_x_, (capcount), _Pre_opt_bytecap_x_(capcount) _Post_valid_impl_ _Post_bytecount_x_(capcount))>
endm
_Out_z_capcount_ macro capcount
  exitm <_SAL1_1_Source_(_Out_z_capcount_, (capcount), _Pre_cap_(capcount) _Post_valid_impl_ _Post_z_count_(capcount))>
endm
_Out_opt_z_capcount_ macro capcount
  exitm <_SAL1_1_Source_(_Out_opt_z_capcount_, (capcount), _Pre_opt_cap_(capcount) _Post_valid_impl_ _Post_z_count_(capcount))>
endm
_Out_z_bytecapcount_ macro capcount
  exitm <_SAL1_1_Source_(_Out_z_bytecapcount_, (capcount), _Pre_bytecap_(capcount) _Post_valid_impl_ _Post_z_bytecount_(capcount))>
endm
_Out_opt_z_bytecapcount_ macro capcount
  exitm <_SAL1_1_Source_(_Out_opt_z_bytecapcount_, (capcount), _Pre_opt_bytecap_(capcount) _Post_valid_impl_ _Post_z_bytecount_(capcount))>
endm
_Inout_count_ macro size_
  exitm <_SAL1_1_Source_(_Inout_count_, (size_), _Prepost_count_(size_))>
endm
_Inout_opt_count_ macro size_
  exitm <_SAL1_1_Source_(_Inout_opt_count_, (size_), _Prepost_opt_count_(size_))>
endm
_Inout_bytecount_ macro size_
  exitm <_SAL1_1_Source_(_Inout_bytecount_, (size_), _Prepost_bytecount_(size_))>
endm
_Inout_opt_bytecount_ macro size_
  exitm <_SAL1_1_Source_(_Inout_opt_bytecount_, (size_), _Prepost_opt_bytecount_(size_))>
endm
_Inout_count_c_ macro size_
  exitm <_SAL1_1_Source_(_Inout_count_c_, (size_), _Prepost_count_c_(size_))>
endm
_Inout_opt_count_c_ macro size_
  exitm <_SAL1_1_Source_(_Inout_opt_count_c_, (size_), _Prepost_opt_count_c_(size_))>
endm
_Inout_bytecount_c_ macro size_
  exitm <_SAL1_1_Source_(_Inout_bytecount_c_, (size_), _Prepost_bytecount_c_(size_))>
endm
_Inout_opt_bytecount_c_ macro size_
  exitm <_SAL1_1_Source_(_Inout_opt_bytecount_c_, (size_), _Prepost_opt_bytecount_c_(size_))>
endm
_Inout_z_count_ macro size_
  exitm <_SAL1_1_Source_(_Inout_z_count_, (size_), _Prepost_z_ _Prepost_count_(size_))>
endm
_Inout_opt_z_count_ macro size_
  exitm <_SAL1_1_Source_(_Inout_opt_z_count_, (size_), _Prepost_z_ _Prepost_opt_count_(size_))>
endm
_Inout_z_bytecount_ macro size_
  exitm <_SAL1_1_Source_(_Inout_z_bytecount_, (size_), _Prepost_z_ _Prepost_bytecount_(size_))>
endm
_Inout_opt_z_bytecount_ macro size_
  exitm <_SAL1_1_Source_(_Inout_opt_z_bytecount_, (size_), _Prepost_z_ _Prepost_opt_bytecount_(size_))>
endm
_Inout_z_count_c_ macro size_
  exitm <_SAL1_1_Source_(_Inout_z_count_c_, (size_), _Prepost_z_ _Prepost_count_c_(size_))>
endm
_Inout_opt_z_count_c_ macro size_
  exitm <_SAL1_1_Source_(_Inout_opt_z_count_c_, (size_), _Prepost_z_ _Prepost_opt_count_c_(size_))>
endm
_Inout_z_bytecount_c_ macro size_
  exitm <_SAL1_1_Source_(_Inout_z_bytecount_c_, (size_), _Prepost_z_ _Prepost_bytecount_c_(size_))>
endm
_Inout_opt_z_bytecount_c_ macro size_
  exitm <_SAL1_1_Source_(_Inout_opt_z_bytecount_c_, (size_), _Prepost_z_ _Prepost_opt_bytecount_c_(size_))>
endm
_Inout_ptrdiff_count_ macro size_
  exitm <_SAL1_1_Source_(_Inout_ptrdiff_count_, (size_), _Pre_ptrdiff_count_(size_))>
endm
_Inout_opt_ptrdiff_count_ macro size_
  exitm <_SAL1_1_Source_(_Inout_opt_ptrdiff_count_, (size_), _Pre_opt_ptrdiff_count_(size_))>
endm
_Inout_count_x_ macro size_
  exitm <_SAL1_1_Source_(_Inout_count_x_, (size_), _Prepost_count_x_(size_))>
endm
_Inout_opt_count_x_ macro size_
  exitm <_SAL1_1_Source_(_Inout_opt_count_x_, (size_), _Prepost_opt_count_x_(size_))>
endm
_Inout_bytecount_x_ macro size_
  exitm <_SAL1_1_Source_(_Inout_bytecount_x_, (size_), _Prepost_bytecount_x_(size_))>
endm
_Inout_opt_bytecount_x_ macro size_
  exitm <_SAL1_1_Source_(_Inout_opt_bytecount_x_, (size_), _Prepost_opt_bytecount_x_(size_))>
endm
_Inout_cap_ macro size_
  exitm <_SAL1_1_Source_(_Inout_cap_, (size_), _Pre_valid_cap_(size_) _Post_valid_)>
endm
_Inout_opt_cap_ macro size_
  exitm <_SAL1_1_Source_(_Inout_opt_cap_, (size_), _Pre_opt_valid_cap_(size_) _Post_valid_)>
endm
_Inout_bytecap_ macro size_
  exitm <_SAL1_1_Source_(_Inout_bytecap_, (size_), _Pre_valid_bytecap_(size_) _Post_valid_)>
endm
_Inout_opt_bytecap_ macro size_
  exitm <_SAL1_1_Source_(_Inout_opt_bytecap_, (size_), _Pre_opt_valid_bytecap_(size_) _Post_valid_)>
endm
_Inout_cap_c_ macro size_
  exitm <_SAL1_1_Source_(_Inout_cap_c_, (size_), _Pre_valid_cap_c_(size_) _Post_valid_)>
endm
_Inout_opt_cap_c_ macro size_
  exitm <_SAL1_1_Source_(_Inout_opt_cap_c_, (size_), _Pre_opt_valid_cap_c_(size_) _Post_valid_)>
endm
_Inout_bytecap_c_ macro size_
  exitm <_SAL1_1_Source_(_Inout_bytecap_c_, (size_), _Pre_valid_bytecap_c_(size_) _Post_valid_)>
endm
_Inout_opt_bytecap_c_ macro size_
  exitm <_SAL1_1_Source_(_Inout_opt_bytecap_c_, (size_), _Pre_opt_valid_bytecap_c_(size_) _Post_valid_)>
endm
_Inout_cap_x_ macro size_
  exitm <_SAL1_1_Source_(_Inout_cap_x_, (size_), _Pre_valid_cap_x_(size_) _Post_valid_)>
endm
_Inout_opt_cap_x_ macro size_
  exitm <_SAL1_1_Source_(_Inout_opt_cap_x_, (size_), _Pre_opt_valid_cap_x_(size_) _Post_valid_)>
endm
_Inout_bytecap_x_ macro size_
  exitm <_SAL1_1_Source_(_Inout_bytecap_x_, (size_), _Pre_valid_bytecap_x_(size_) _Post_valid_)>
endm
_Inout_opt_bytecap_x_ macro size_
  exitm <_SAL1_1_Source_(_Inout_opt_bytecap_x_, (size_), _Pre_opt_valid_bytecap_x_(size_) _Post_valid_)>
endm
_Inout_z_cap_ macro size_
  exitm <_SAL1_1_Source_(_Inout_z_cap_, (size_), _Pre_z_cap_(size_) _Post_z_)>
endm
_Inout_opt_z_cap_ macro size_
  exitm <_SAL1_1_Source_(_Inout_opt_z_cap_, (size_), _Pre_opt_z_cap_(size_) _Post_z_)>
endm
_Inout_z_bytecap_ macro size_
  exitm <_SAL1_1_Source_(_Inout_z_bytecap_, (size_), _Pre_z_bytecap_(size_) _Post_z_)>
endm
_Inout_opt_z_bytecap_ macro size_
  exitm <_SAL1_1_Source_(_Inout_opt_z_bytecap_, (size_), _Pre_opt_z_bytecap_(size_) _Post_z_)>
endm
_Inout_z_cap_c_ macro size_
  exitm <_SAL1_1_Source_(_Inout_z_cap_c_, (size_), _Pre_z_cap_c_(size_) _Post_z_)>
endm
_Inout_opt_z_cap_c_ macro size_
  exitm <_SAL1_1_Source_(_Inout_opt_z_cap_c_, (size_), _Pre_opt_z_cap_c_(size_) _Post_z_)>
endm
_Inout_z_bytecap_c_ macro size_
  exitm <_SAL1_1_Source_(_Inout_z_bytecap_c_, (size_), _Pre_z_bytecap_c_(size_) _Post_z_)>
endm
_Inout_opt_z_bytecap_c_ macro size_
  exitm <_SAL1_1_Source_(_Inout_opt_z_bytecap_c_, (size_), _Pre_opt_z_bytecap_c_(size_) _Post_z_)>
endm
_Inout_z_cap_x_ macro size_
  exitm <_SAL1_1_Source_(_Inout_z_cap_x_, (size_), _Pre_z_cap_x_(size_) _Post_z_)>
endm
_Inout_opt_z_cap_x_ macro size_
  exitm <_SAL1_1_Source_(_Inout_opt_z_cap_x_, (size_), _Pre_opt_z_cap_x_(size_) _Post_z_)>
endm
_Inout_z_bytecap_x_ macro size_
  exitm <_SAL1_1_Source_(_Inout_z_bytecap_x_, (size_), _Pre_z_bytecap_x_(size_) _Post_z_)>
endm
_Inout_opt_z_bytecap_x_ macro size_
  exitm <_SAL1_1_Source_(_Inout_opt_z_bytecap_x_, (size_), _Pre_opt_z_bytecap_x_(size_) _Post_z_)>
endm
_Ret_ equ <_SAL1_1_Source_(_Ret_,, _Ret_valid_)>
_Ret_opt_ equ <_SAL1_1_Source_(_Ret_opt_,, _Ret_opt_valid_)>
_In_bound_ equ <_SAL1_1_Source_(_In_bound_,, _In_bound_impl_)>
_Out_bound_ equ <_SAL1_1_Source_(_Out_bound_,, _Out_bound_impl_)>
_Ret_bound_ equ <_SAL1_1_Source_(_Ret_bound_,, _Ret_bound_impl_)>
_Deref_in_bound_ equ <_SAL1_1_Source_(_Deref_in_bound_,, _Deref_in_bound_impl_)>
_Deref_out_bound_ equ <_SAL1_1_Source_(_Deref_out_bound_,, _Deref_out_bound_impl_)>
_Deref_inout_bound_ equ <_SAL1_1_Source_(_Deref_inout_bound_,, _Deref_in_bound_ _Deref_out_bound_)>
_Deref_ret_bound_ equ <_SAL1_1_Source_(_Deref_ret_bound_,, _Deref_ret_bound_impl_)>
_Deref_out_ equ <_SAL1_1_Source_(_Deref_out_,, _Out_ _Deref_post_valid_)>
_Deref_out_opt_ equ <_SAL1_1_Source_(_Deref_out_opt_,, _Out_ _Deref_post_opt_valid_)>
_Deref_opt_out_ equ <_SAL1_1_Source_(_Deref_opt_out_,, _Out_opt_ _Deref_post_valid_)>
_Deref_opt_out_opt_ equ <_SAL1_1_Source_(_Deref_opt_out_opt_,, _Out_opt_ _Deref_post_opt_valid_)>
_Deref_out_z_ equ <_SAL1_1_Source_(_Deref_out_z_,, _Out_ _Deref_post_z_)>
_Deref_out_opt_z_ equ <_SAL1_1_Source_(_Deref_out_opt_z_,, _Out_ _Deref_post_opt_z_)>
_Deref_opt_out_z_ equ <_SAL1_1_Source_(_Deref_opt_out_z_,, _Out_opt_ _Deref_post_z_)>
_Deref_opt_out_opt_z_ equ <_SAL1_1_Source_(_Deref_opt_out_opt_z_,, _Out_opt_ _Deref_post_opt_z_)>
_Deref_pre_z_ equ <_SAL1_1_Source_(_Deref_pre_z_,, _Deref_pre1_impl_(__notnull_impl_notref) _Deref_pre1_impl_(__zterm_impl) _Pre_valid_impl_)>
_Deref_pre_opt_z_ equ <_SAL1_1_Source_(_Deref_pre_opt_z_,, _Deref_pre1_impl_(__maybenull_impl_notref) _Deref_pre1_impl_(__zterm_impl) _Pre_valid_impl_)>
_Deref_pre_cap_ macro size_
  exitm <_SAL1_1_Source_(_Deref_pre_cap_, (size_), _Deref_pre1_impl_(__notnull_impl_notref) _Deref_pre1_impl_(__cap_impl(size_)))>
endm
_Deref_pre_opt_cap_ macro size_
  exitm <_SAL1_1_Source_(_Deref_pre_opt_cap_, (size_), _Deref_pre1_impl_(__maybenull_impl_notref) _Deref_pre1_impl_(__cap_impl(size_)))>
endm
_Deref_pre_bytecap_ macro size_
  exitm <_SAL1_1_Source_(_Deref_pre_bytecap_, (size_), _Deref_pre1_impl_(__notnull_impl_notref) _Deref_pre1_impl_(__bytecap_impl(size_)))>
endm
_Deref_pre_opt_bytecap_ macro size_
  exitm <_SAL1_1_Source_(_Deref_pre_opt_bytecap_, (size_), _Deref_pre1_impl_(__maybenull_impl_notref) _Deref_pre1_impl_(__bytecap_impl(size_)))>
endm
_Deref_pre_cap_c_ macro size_
  exitm <_SAL1_1_Source_(_Deref_pre_cap_c_, (size_), _Deref_pre1_impl_(__notnull_impl_notref) _Deref_pre1_impl_(__cap_c_impl(size_)))>
endm
_Deref_pre_opt_cap_c_ macro size_
  exitm <_SAL1_1_Source_(_Deref_pre_opt_cap_c_, (size_), _Deref_pre1_impl_(__maybenull_impl_notref) _Deref_pre1_impl_(__cap_c_impl(size_)))>
endm
_Deref_pre_bytecap_c_ macro size_
  exitm <_SAL1_1_Source_(_Deref_pre_bytecap_c_, (size_), _Deref_pre1_impl_(__notnull_impl_notref) _Deref_pre1_impl_(__bytecap_c_impl(size_)))>
endm
_Deref_pre_opt_bytecap_c_ macro size_
  exitm <_SAL1_1_Source_(_Deref_pre_opt_bytecap_c_, (size_), _Deref_pre1_impl_(__maybenull_impl_notref) _Deref_pre1_impl_(__bytecap_c_impl(size_)))>
endm
_Deref_pre_cap_x_ macro size_
  exitm <_SAL1_1_Source_(_Deref_pre_cap_x_, (size_), _Deref_pre1_impl_(__notnull_impl_notref) _Deref_pre1_impl_(__cap_x_impl(size_)))>
endm
_Deref_pre_opt_cap_x_ macro size_
  exitm <_SAL1_1_Source_(_Deref_pre_opt_cap_x_, (size_), _Deref_pre1_impl_(__maybenull_impl_notref) _Deref_pre1_impl_(__cap_x_impl(size_)))>
endm
_Deref_pre_bytecap_x_ macro size_
  exitm <_SAL1_1_Source_(_Deref_pre_bytecap_x_, (size_), _Deref_pre1_impl_(__notnull_impl_notref) _Deref_pre1_impl_(__bytecap_x_impl(size_)))>
endm
_Deref_pre_opt_bytecap_x_ macro size_
  exitm <_SAL1_1_Source_(_Deref_pre_opt_bytecap_x_, (size_), _Deref_pre1_impl_(__maybenull_impl_notref) _Deref_pre1_impl_(__bytecap_x_impl(size_)))>
endm
_Deref_pre_z_cap_ macro size_
  exitm <_SAL1_1_Source_(_Deref_pre_z_cap_, (size_), _Deref_pre1_impl_(__notnull_impl_notref) _Deref_pre2_impl_(__zterm_impl, __cap_impl(size_)) _Pre_valid_impl_)>
endm
_Deref_pre_opt_z_cap_ macro size_
  exitm <_SAL1_1_Source_(_Deref_pre_opt_z_cap_, (size_), _Deref_pre1_impl_(__maybenull_impl_notref) _Deref_pre2_impl_(__zterm_impl, __cap_impl(size_)) _Pre_valid_impl_)>
endm
_Deref_pre_z_bytecap_ macro size_
  exitm <_SAL1_1_Source_(_Deref_pre_z_bytecap_, (size_), _Deref_pre1_impl_(__notnull_impl_notref) _Deref_pre2_impl_(__zterm_impl, __bytecap_impl(size_)) _Pre_valid_impl_)>
endm
_Deref_pre_opt_z_bytecap_ macro size_
  exitm <_SAL1_1_Source_(_Deref_pre_opt_z_bytecap_, (size_), _Deref_pre1_impl_(__maybenull_impl_notref) _Deref_pre2_impl_(__zterm_impl, __bytecap_impl(size_)) _Pre_valid_impl_)>
endm
_Deref_pre_z_cap_c_ macro size_
  exitm <_SAL1_1_Source_(_Deref_pre_z_cap_c_, (size_), _Deref_pre1_impl_(__notnull_impl_notref) _Deref_pre2_impl_(__zterm_impl, __cap_c_impl(size_)) _Pre_valid_impl_)>
endm
_Deref_pre_opt_z_cap_c_ macro size_
  exitm <_SAL1_1_Source_(_Deref_pre_opt_z_cap_c_, (size_), _Deref_pre1_impl_(__maybenull_impl_notref) _Deref_pre2_impl_(__zterm_impl, __cap_c_impl(size_)) _Pre_valid_impl_)>
endm
_Deref_pre_z_bytecap_c_ macro size_
  exitm <_SAL1_1_Source_(_Deref_pre_z_bytecap_c_, (size_), _Deref_pre1_impl_(__notnull_impl_notref) _Deref_pre2_impl_(__zterm_impl, __bytecap_c_impl(size_)) _Pre_valid_impl_)>
endm
_Deref_pre_opt_z_bytecap_c_ macro size_
  exitm <_SAL1_1_Source_(_Deref_pre_opt_z_bytecap_c_, (size_), _Deref_pre1_impl_(__maybenull_impl_notref) _Deref_pre2_impl_(__zterm_impl, __bytecap_c_impl(size_)) _Pre_valid_impl_)>
endm
_Deref_pre_z_cap_x_ macro size_
  exitm <_SAL1_1_Source_(_Deref_pre_z_cap_x_, (size_), _Deref_pre1_impl_(__notnull_impl_notref) _Deref_pre2_impl_(__zterm_impl, __cap_x_impl(size_)) _Pre_valid_impl_)>
endm
_Deref_pre_opt_z_cap_x_ macro size_
  exitm <_SAL1_1_Source_(_Deref_pre_opt_z_cap_x_, (size_), _Deref_pre1_impl_(__maybenull_impl_notref) _Deref_pre2_impl_(__zterm_impl, __cap_x_impl(size_)) _Pre_valid_impl_)>
endm
_Deref_pre_z_bytecap_x_ macro size_
  exitm <_SAL1_1_Source_(_Deref_pre_z_bytecap_x_, (size_), _Deref_pre1_impl_(__notnull_impl_notref) _Deref_pre2_impl_(__zterm_impl, __bytecap_x_impl(size_)) _Pre_valid_impl_)>
endm
_Deref_pre_opt_z_bytecap_x_ macro size_
  exitm <_SAL1_1_Source_(_Deref_pre_opt_z_bytecap_x_, (size_), _Deref_pre1_impl_(__maybenull_impl_notref) _Deref_pre2_impl_(__zterm_impl, __bytecap_x_impl(size_)) _Pre_valid_impl_)>
endm
_Deref_pre_valid_cap_ macro size_
  exitm <_SAL1_1_Source_(_Deref_pre_valid_cap_, (size_), _Deref_pre1_impl_(__notnull_impl_notref) _Deref_pre1_impl_(__cap_impl(size_)) _Pre_valid_impl_)>
endm
_Deref_pre_opt_valid_cap_ macro size_
  exitm <_SAL1_1_Source_(_Deref_pre_opt_valid_cap_, (size_), _Deref_pre1_impl_(__maybenull_impl_notref) _Deref_pre1_impl_(__cap_impl(size_)) _Pre_valid_impl_)>
endm
_Deref_pre_valid_bytecap_ macro size_
  exitm <_SAL1_1_Source_(_Deref_pre_valid_bytecap_, (size_), _Deref_pre1_impl_(__notnull_impl_notref) _Deref_pre1_impl_(__bytecap_impl(size_)) _Pre_valid_impl_)>
endm
_Deref_pre_opt_valid_bytecap_ macro size_
  exitm <_SAL1_1_Source_(_Deref_pre_opt_valid_bytecap_, (size_), _Deref_pre1_impl_(__maybenull_impl_notref) _Deref_pre1_impl_(__bytecap_impl(size_)) _Pre_valid_impl_)>
endm
_Deref_pre_valid_cap_c_ macro size_
  exitm <_SAL1_1_Source_(_Deref_pre_valid_cap_c_, (size_), _Deref_pre1_impl_(__notnull_impl_notref) _Deref_pre1_impl_(__cap_c_impl(size_)) _Pre_valid_impl_)>
endm
_Deref_pre_opt_valid_cap_c_ macro size_
  exitm <_SAL1_1_Source_(_Deref_pre_opt_valid_cap_c_, (size_), _Deref_pre1_impl_(__maybenull_impl_notref) _Deref_pre1_impl_(__cap_c_impl(size_)) _Pre_valid_impl_)>
endm
_Deref_pre_valid_bytecap_c_ macro size_
  exitm <_SAL1_1_Source_(_Deref_pre_valid_bytecap_c_, (size_), _Deref_pre1_impl_(__notnull_impl_notref) _Deref_pre1_impl_(__bytecap_c_impl(size_)) _Pre_valid_impl_)>
endm
_Deref_pre_opt_valid_bytecap_c_ macro size_
  exitm <_SAL1_1_Source_(_Deref_pre_opt_valid_bytecap_c_, (size_), _Deref_pre1_impl_(__maybenull_impl_notref) _Deref_pre1_impl_(__bytecap_c_impl(size_)) _Pre_valid_impl_)>
endm
_Deref_pre_valid_cap_x_ macro size_
  exitm <_SAL1_1_Source_(_Deref_pre_valid_cap_x_, (size_), _Deref_pre1_impl_(__notnull_impl_notref) _Deref_pre1_impl_(__cap_x_impl(size_)) _Pre_valid_impl_)>
endm
_Deref_pre_opt_valid_cap_x_ macro size_
  exitm <_SAL1_1_Source_(_Deref_pre_opt_valid_cap_x_, (size_), _Deref_pre1_impl_(__maybenull_impl_notref) _Deref_pre1_impl_(__cap_x_impl(size_)) _Pre_valid_impl_)>
endm
_Deref_pre_valid_bytecap_x_ macro size_
  exitm <_SAL1_1_Source_(_Deref_pre_valid_bytecap_x_, (size_), _Deref_pre1_impl_(__notnull_impl_notref) _Deref_pre1_impl_(__bytecap_x_impl(size_)) _Pre_valid_impl_)>
endm
_Deref_pre_opt_valid_bytecap_x_ macro size_
  exitm <_SAL1_1_Source_(_Deref_pre_opt_valid_bytecap_x_, (size_), _Deref_pre1_impl_(__maybenull_impl_notref) _Deref_pre1_impl_(__bytecap_x_impl(size_)) _Pre_valid_impl_)>
endm
_Deref_pre_count_ macro size_
  exitm <_SAL1_1_Source_(_Deref_pre_count_, (size_), _Deref_pre1_impl_(__notnull_impl_notref) _Deref_pre1_impl_(__count_impl(size_)) _Pre_valid_impl_)>
endm
_Deref_pre_opt_count_ macro size_
  exitm <_SAL1_1_Source_(_Deref_pre_opt_count_, (size_), _Deref_pre1_impl_(__maybenull_impl_notref) _Deref_pre1_impl_(__count_impl(size_)) _Pre_valid_impl_)>
endm
_Deref_pre_bytecount_ macro size_
  exitm <_SAL1_1_Source_(_Deref_pre_bytecount_, (size_), _Deref_pre1_impl_(__notnull_impl_notref) _Deref_pre1_impl_(__bytecount_impl(size_)) _Pre_valid_impl_)>
endm
_Deref_pre_opt_bytecount_ macro size_
  exitm <_SAL1_1_Source_(_Deref_pre_opt_bytecount_, (size_), _Deref_pre1_impl_(__maybenull_impl_notref) _Deref_pre1_impl_(__bytecount_impl(size_)) _Pre_valid_impl_)>
endm
_Deref_pre_count_c_ macro size_
  exitm <_SAL1_1_Source_(_Deref_pre_count_c_, (size_), _Deref_pre1_impl_(__notnull_impl_notref) _Deref_pre1_impl_(__count_c_impl(size_)) _Pre_valid_impl_)>
endm
_Deref_pre_opt_count_c_ macro size_
  exitm <_SAL1_1_Source_(_Deref_pre_opt_count_c_, (size_), _Deref_pre1_impl_(__maybenull_impl_notref) _Deref_pre1_impl_(__count_c_impl(size_)) _Pre_valid_impl_)>
endm
_Deref_pre_bytecount_c_ macro size_
  exitm <_SAL1_1_Source_(_Deref_pre_bytecount_c_, (size_), _Deref_pre1_impl_(__notnull_impl_notref) _Deref_pre1_impl_(__bytecount_c_impl(size_)) _Pre_valid_impl_)>
endm
_Deref_pre_opt_bytecount_c_ macro size_
  exitm <_SAL1_1_Source_(_Deref_pre_opt_bytecount_c_, (size_), _Deref_pre1_impl_(__maybenull_impl_notref) _Deref_pre1_impl_(__bytecount_c_impl(size_)) _Pre_valid_impl_)>
endm
_Deref_pre_count_x_ macro size_
  exitm <_SAL1_1_Source_(_Deref_pre_count_x_, (size_), _Deref_pre1_impl_(__notnull_impl_notref) _Deref_pre1_impl_(__count_x_impl(size_)) _Pre_valid_impl_)>
endm
_Deref_pre_opt_count_x_ macro size_
  exitm <_SAL1_1_Source_(_Deref_pre_opt_count_x_, (size_), _Deref_pre1_impl_(__maybenull_impl_notref) _Deref_pre1_impl_(__count_x_impl(size_)) _Pre_valid_impl_)>
endm
_Deref_pre_bytecount_x_ macro size_
  exitm <_SAL1_1_Source_(_Deref_pre_bytecount_x_, (size_), _Deref_pre1_impl_(__notnull_impl_notref) _Deref_pre1_impl_(__bytecount_x_impl(size_)) _Pre_valid_impl_)>
endm
_Deref_pre_opt_bytecount_x_ macro size_
  exitm <_SAL1_1_Source_(_Deref_pre_opt_bytecount_x_, (size_), _Deref_pre1_impl_(__maybenull_impl_notref) _Deref_pre1_impl_(__bytecount_x_impl(size_)) _Pre_valid_impl_)>
endm
_Deref_pre_valid_ equ <_SAL1_1_Source_(_Deref_pre_valid_,, _Deref_pre1_impl_(__notnull_impl_notref) _Pre_valid_impl_)>
_Deref_pre_opt_valid_ equ <_SAL1_1_Source_(_Deref_pre_opt_valid_,, _Deref_pre1_impl_(__maybenull_impl_notref) _Pre_valid_impl_)>
_Deref_pre_invalid_ equ <_SAL1_1_Source_(_Deref_pre_invalid_,, _Deref_pre1_impl_(__notvalid_impl))>
_Deref_pre_notnull_ equ <_SAL1_1_Source_(_Deref_pre_notnull_,, _Deref_pre1_impl_(__notnull_impl_notref))>
_Deref_pre_maybenull_ equ <_SAL1_1_Source_(_Deref_pre_maybenull_,, _Deref_pre1_impl_(__maybenull_impl_notref))>
_Deref_pre_null_ equ <_SAL1_1_Source_(_Deref_pre_null_,, _Deref_pre1_impl_(__null_impl_notref))>
_Deref_pre_readonly_ equ <_SAL1_1_Source_(_Deref_pre_readonly_,, _Deref_pre1_impl_(__readaccess_impl_notref))>
_Deref_pre_writeonly_ equ <_SAL1_1_Source_(_Deref_pre_writeonly_,, _Deref_pre1_impl_(__writeaccess_impl_notref))>
_Deref_post_z_ equ <_SAL1_1_Source_(_Deref_post_z_,, _Deref_post1_impl_(__notnull_impl_notref) _Deref_post1_impl_(__zterm_impl) _Post_valid_impl_)>
_Deref_post_opt_z_ equ <_SAL1_1_Source_(_Deref_post_opt_z_,, _Deref_post1_impl_(__maybenull_impl_notref) _Deref_post1_impl_(__zterm_impl) _Post_valid_impl_)>
_Deref_post_cap_ macro size_
  exitm <_SAL1_1_Source_(_Deref_post_cap_, (size_), _Deref_post1_impl_(__notnull_impl_notref) _Deref_post1_impl_(__cap_impl(size_)))>
endm
_Deref_post_opt_cap_ macro size_
  exitm <_SAL1_1_Source_(_Deref_post_opt_cap_, (size_), _Deref_post1_impl_(__maybenull_impl_notref) _Deref_post1_impl_(__cap_impl(size_)))>
endm
_Deref_post_bytecap_ macro size_
  exitm <_SAL1_1_Source_(_Deref_post_bytecap_, (size_), _Deref_post1_impl_(__notnull_impl_notref) _Deref_post1_impl_(__bytecap_impl(size_)))>
endm
_Deref_post_opt_bytecap_ macro size_
  exitm <_SAL1_1_Source_(_Deref_post_opt_bytecap_, (size_), _Deref_post1_impl_(__maybenull_impl_notref) _Deref_post1_impl_(__bytecap_impl(size_)))>
endm
_Deref_post_cap_c_ macro size_
  exitm <_SAL1_1_Source_(_Deref_post_cap_c_, (size_), _Deref_post1_impl_(__notnull_impl_notref) _Deref_post1_impl_(__cap_c_impl(size_)))>
endm
_Deref_post_opt_cap_c_ macro size_
  exitm <_SAL1_1_Source_(_Deref_post_opt_cap_c_, (size_), _Deref_post1_impl_(__maybenull_impl_notref) _Deref_post1_impl_(__cap_c_impl(size_)))>
endm
_Deref_post_bytecap_c_ macro size_
  exitm <_SAL1_1_Source_(_Deref_post_bytecap_c_, (size_), _Deref_post1_impl_(__notnull_impl_notref) _Deref_post1_impl_(__bytecap_c_impl(size_)))>
endm
_Deref_post_opt_bytecap_c_ macro size_
  exitm <_SAL1_1_Source_(_Deref_post_opt_bytecap_c_, (size_), _Deref_post1_impl_(__maybenull_impl_notref) _Deref_post1_impl_(__bytecap_c_impl(size_)))>
endm
_Deref_post_cap_x_ macro size_
  exitm <_SAL1_1_Source_(_Deref_post_cap_x_, (size_), _Deref_post1_impl_(__notnull_impl_notref) _Deref_post1_impl_(__cap_x_impl(size_)))>
endm
_Deref_post_opt_cap_x_ macro size_
  exitm <_SAL1_1_Source_(_Deref_post_opt_cap_x_, (size_), _Deref_post1_impl_(__maybenull_impl_notref) _Deref_post1_impl_(__cap_x_impl(size_)))>
endm
_Deref_post_bytecap_x_ macro size_
  exitm <_SAL1_1_Source_(_Deref_post_bytecap_x_, (size_), _Deref_post1_impl_(__notnull_impl_notref) _Deref_post1_impl_(__bytecap_x_impl(size_)))>
endm
_Deref_post_opt_bytecap_x_ macro size_
  exitm <_SAL1_1_Source_(_Deref_post_opt_bytecap_x_, (size_), _Deref_post1_impl_(__maybenull_impl_notref) _Deref_post1_impl_(__bytecap_x_impl(size_)))>
endm
_Deref_post_z_cap_ macro size_
  exitm <_SAL1_1_Source_(_Deref_post_z_cap_, (size_), _Deref_post1_impl_(__notnull_impl_notref) _Deref_post2_impl_(__zterm_impl, __cap_impl(size_)) _Post_valid_impl_)>
endm
_Deref_post_opt_z_cap_ macro size_
  exitm <_SAL1_1_Source_(_Deref_post_opt_z_cap_, (size_), _Deref_post1_impl_(__maybenull_impl_notref) _Deref_post2_impl_(__zterm_impl, __cap_impl(size_)) _Post_valid_impl_)>
endm
_Deref_post_z_bytecap_ macro size_
  exitm <_SAL1_1_Source_(_Deref_post_z_bytecap_, (size_), _Deref_post1_impl_(__notnull_impl_notref) _Deref_post2_impl_(__zterm_impl, __bytecap_impl(size_)) _Post_valid_impl_)>
endm
_Deref_post_opt_z_bytecap_ macro size_
  exitm <_SAL1_1_Source_(_Deref_post_opt_z_bytecap_, (size_), _Deref_post1_impl_(__maybenull_impl_notref) _Deref_post2_impl_(__zterm_impl, __bytecap_impl(size_)) _Post_valid_impl_)>
endm
_Deref_post_z_cap_c_ macro size_
  exitm <_SAL1_1_Source_(_Deref_post_z_cap_c_, (size_), _Deref_post1_impl_(__notnull_impl_notref) _Deref_post2_impl_(__zterm_impl, __cap_c_impl(size_)) _Post_valid_impl_)>
endm
_Deref_post_opt_z_cap_c_ macro size_
  exitm <_SAL1_1_Source_(_Deref_post_opt_z_cap_c_, (size_), _Deref_post1_impl_(__maybenull_impl_notref) _Deref_post2_impl_(__zterm_impl, __cap_c_impl(size_)) _Post_valid_impl_)>
endm
_Deref_post_z_bytecap_c_ macro size_
  exitm <_SAL1_1_Source_(_Deref_post_z_bytecap_c_, (size_), _Deref_post1_impl_(__notnull_impl_notref) _Deref_post2_impl_(__zterm_impl, __bytecap_c_impl(size_)) _Post_valid_impl_)>
endm
_Deref_post_opt_z_bytecap_c_ macro size_
  exitm <_SAL1_1_Source_(_Deref_post_opt_z_bytecap_c_, (size_), _Deref_post1_impl_(__maybenull_impl_notref) _Deref_post2_impl_(__zterm_impl, __bytecap_c_impl(size_)) _Post_valid_impl_)>
endm
_Deref_post_z_cap_x_ macro size_
  exitm <_SAL1_1_Source_(_Deref_post_z_cap_x_, (size_), _Deref_post1_impl_(__notnull_impl_notref) _Deref_post2_impl_(__zterm_impl, __cap_x_impl(size_)) _Post_valid_impl_)>
endm
_Deref_post_opt_z_cap_x_ macro size_
  exitm <_SAL1_1_Source_(_Deref_post_opt_z_cap_x_, (size_), _Deref_post1_impl_(__maybenull_impl_notref) _Deref_post2_impl_(__zterm_impl, __cap_x_impl(size_)) _Post_valid_impl_)>
endm
_Deref_post_z_bytecap_x_ macro size_
  exitm <_SAL1_1_Source_(_Deref_post_z_bytecap_x_, (size_), _Deref_post1_impl_(__notnull_impl_notref) _Deref_post2_impl_(__zterm_impl, __bytecap_x_impl(size_)) _Post_valid_impl_)>
endm
_Deref_post_opt_z_bytecap_x_ macro size_
  exitm <_SAL1_1_Source_(_Deref_post_opt_z_bytecap_x_, (size_), _Deref_post1_impl_(__maybenull_impl_notref) _Deref_post2_impl_(__zterm_impl, __bytecap_x_impl(size_)) _Post_valid_impl_)>
endm
_Deref_post_valid_cap_ macro size_
  exitm <_SAL1_1_Source_(_Deref_post_valid_cap_, (size_), _Deref_post1_impl_(__notnull_impl_notref) _Deref_post1_impl_(__cap_impl(size_)) _Post_valid_impl_)>
endm
_Deref_post_opt_valid_cap_ macro size_
  exitm <_SAL1_1_Source_(_Deref_post_opt_valid_cap_, (size_), _Deref_post1_impl_(__maybenull_impl_notref) _Deref_post1_impl_(__cap_impl(size_)) _Post_valid_impl_)>
endm
_Deref_post_valid_bytecap_ macro size_
  exitm <_SAL1_1_Source_(_Deref_post_valid_bytecap_, (size_), _Deref_post1_impl_(__notnull_impl_notref) _Deref_post1_impl_(__bytecap_impl(size_)) _Post_valid_impl_)>
endm
_Deref_post_opt_valid_bytecap_ macro size_
  exitm <_SAL1_1_Source_(_Deref_post_opt_valid_bytecap_, (size_), _Deref_post1_impl_(__maybenull_impl_notref) _Deref_post1_impl_(__bytecap_impl(size_)) _Post_valid_impl_)>
endm
_Deref_post_valid_cap_c_ macro size_
  exitm <_SAL1_1_Source_(_Deref_post_valid_cap_c_, (size_), _Deref_post1_impl_(__notnull_impl_notref) _Deref_post1_impl_(__cap_c_impl(size_)) _Post_valid_impl_)>
endm
_Deref_post_opt_valid_cap_c_ macro size_
  exitm <_SAL1_1_Source_(_Deref_post_opt_valid_cap_c_, (size_), _Deref_post1_impl_(__maybenull_impl_notref) _Deref_post1_impl_(__cap_c_impl(size_)) _Post_valid_impl_)>
endm
_Deref_post_valid_bytecap_c_ macro size_
  exitm <_SAL1_1_Source_(_Deref_post_valid_bytecap_c_, (size_), _Deref_post1_impl_(__notnull_impl_notref) _Deref_post1_impl_(__bytecap_c_impl(size_)) _Post_valid_impl_)>
endm
_Deref_post_opt_valid_bytecap_c_ macro size_
  exitm <_SAL1_1_Source_(_Deref_post_opt_valid_bytecap_c_, (size_), _Deref_post1_impl_(__maybenull_impl_notref) _Deref_post1_impl_(__bytecap_c_impl(size_)) _Post_valid_impl_)>
endm
_Deref_post_valid_cap_x_ macro size_
  exitm <_SAL1_1_Source_(_Deref_post_valid_cap_x_, (size_), _Deref_post1_impl_(__notnull_impl_notref) _Deref_post1_impl_(__cap_x_impl(size_)) _Post_valid_impl_)>
endm
_Deref_post_opt_valid_cap_x_ macro size_
  exitm <_SAL1_1_Source_(_Deref_post_opt_valid_cap_x_, (size_), _Deref_post1_impl_(__maybenull_impl_notref) _Deref_post1_impl_(__cap_x_impl(size_)) _Post_valid_impl_)>
endm
_Deref_post_valid_bytecap_x_ macro size_
  exitm <_SAL1_1_Source_(_Deref_post_valid_bytecap_x_, (size_), _Deref_post1_impl_(__notnull_impl_notref) _Deref_post1_impl_(__bytecap_x_impl(size_)) _Post_valid_impl_)>
endm
_Deref_post_opt_valid_bytecap_x_ macro size_
  exitm <_SAL1_1_Source_(_Deref_post_opt_valid_bytecap_x_, (size_), _Deref_post1_impl_(__maybenull_impl_notref) _Deref_post1_impl_(__bytecap_x_impl(size_)) _Post_valid_impl_)>
endm
_Deref_post_count_ macro size_
  exitm <_SAL1_1_Source_(_Deref_post_count_, (size_), _Deref_post1_impl_(__notnull_impl_notref) _Deref_post1_impl_(__count_impl(size_)) _Post_valid_impl_)>
endm
_Deref_post_opt_count_ macro size_
  exitm <_SAL1_1_Source_(_Deref_post_opt_count_, (size_), _Deref_post1_impl_(__maybenull_impl_notref) _Deref_post1_impl_(__count_impl(size_)) _Post_valid_impl_)>
endm
_Deref_post_bytecount_ macro size_
  exitm <_SAL1_1_Source_(_Deref_post_bytecount_, (size_), _Deref_post1_impl_(__notnull_impl_notref) _Deref_post1_impl_(__bytecount_impl(size_)) _Post_valid_impl_)>
endm
_Deref_post_opt_bytecount_ macro size_
  exitm <_SAL1_1_Source_(_Deref_post_opt_bytecount_, (size_), _Deref_post1_impl_(__maybenull_impl_notref) _Deref_post1_impl_(__bytecount_impl(size_)) _Post_valid_impl_)>
endm
_Deref_post_count_c_ macro size_
  exitm <_SAL1_1_Source_(_Deref_post_count_c_, (size_), _Deref_post1_impl_(__notnull_impl_notref) _Deref_post1_impl_(__count_c_impl(size_)) _Post_valid_impl_)>
endm
_Deref_post_opt_count_c_ macro size_
  exitm <_SAL1_1_Source_(_Deref_post_opt_count_c_, (size_), _Deref_post1_impl_(__maybenull_impl_notref) _Deref_post1_impl_(__count_c_impl(size_)) _Post_valid_impl_)>
endm
_Deref_post_bytecount_c_ macro size_
  exitm <_SAL1_1_Source_(_Deref_post_bytecount_c_, (size_), _Deref_post1_impl_(__notnull_impl_notref) _Deref_post1_impl_(__bytecount_c_impl(size_)) _Post_valid_impl_)>
endm
_Deref_post_opt_bytecount_c_ macro size_
  exitm <_SAL1_1_Source_(_Deref_post_opt_bytecount_c_, (size_), _Deref_post1_impl_(__maybenull_impl_notref) _Deref_post1_impl_(__bytecount_c_impl(size_)) _Post_valid_impl_)>
endm
_Deref_post_count_x_ macro size_
  exitm <_SAL1_1_Source_(_Deref_post_count_x_, (size_), _Deref_post1_impl_(__notnull_impl_notref) _Deref_post1_impl_(__count_x_impl(size_)) _Post_valid_impl_)>
endm
_Deref_post_opt_count_x_ macro size_
  exitm <_SAL1_1_Source_(_Deref_post_opt_count_x_, (size_), _Deref_post1_impl_(__maybenull_impl_notref) _Deref_post1_impl_(__count_x_impl(size_)) _Post_valid_impl_)>
endm
_Deref_post_bytecount_x_ macro size_
  exitm <_SAL1_1_Source_(_Deref_post_bytecount_x_, (size_), _Deref_post1_impl_(__notnull_impl_notref) _Deref_post1_impl_(__bytecount_x_impl(size_)) _Post_valid_impl_)>
endm
_Deref_post_opt_bytecount_x_ macro size_
  exitm <_SAL1_1_Source_(_Deref_post_opt_bytecount_x_, (size_), _Deref_post1_impl_(__maybenull_impl_notref) _Deref_post1_impl_(__bytecount_x_impl(size_)) _Post_valid_impl_)>
endm
_Deref_post_valid_ equ <_SAL1_1_Source_(_Deref_post_valid_,, _Deref_post1_impl_(__notnull_impl_notref) _Post_valid_impl_)>
_Deref_post_opt_valid_ equ <_SAL1_1_Source_(_Deref_post_opt_valid_,, _Deref_post1_impl_(__maybenull_impl_notref) _Post_valid_impl_)>
_Deref_post_notnull_ equ <_SAL1_1_Source_(_Deref_post_notnull_,, _Deref_post1_impl_(__notnull_impl_notref))>
_Deref_post_maybenull_ equ <_SAL1_1_Source_(_Deref_post_maybenull_,, _Deref_post1_impl_(__maybenull_impl_notref))>
_Deref_post_null_ equ <_SAL1_1_Source_(_Deref_post_null_,, _Deref_post1_impl_(__null_impl_notref))>
_Deref_ret_z_ equ <_SAL1_1_Source_(_Deref_ret_z_,, _Deref_ret1_impl_(__notnull_impl_notref) _Deref_ret1_impl_(__zterm_impl))>
_Deref_ret_opt_z_ equ <_SAL1_1_Source_(_Deref_ret_opt_z_,, _Deref_ret1_impl_(__maybenull_impl_notref) _Ret1_impl_(__zterm_impl))>
_Deref2_pre_readonly_ equ <_SAL1_1_Source_(_Deref2_pre_readonly_,, _Deref2_pre1_impl_(__readaccess_impl_notref))>
_Ret_opt_valid_ equ <_SAL1_1_Source_(_Ret_opt_valid_,, _Ret1_impl_(__maybenull_impl_notref) _Ret_valid_impl_)>
_Ret_opt_z_ equ <_SAL1_1_Source_(_Ret_opt_z_,, _Ret2_impl_(__maybenull_impl, __zterm_impl) _Ret_valid_impl_)>
_Ret_cap_ macro size_
  exitm <_SAL1_1_Source_(_Ret_cap_, (size_), _Ret1_impl_(__notnull_impl_notref) _Ret1_impl_(__cap_impl(size_)))>
endm
_Ret_opt_cap_ macro size_
  exitm <_SAL1_1_Source_(_Ret_opt_cap_, (size_), _Ret1_impl_(__maybenull_impl_notref) _Ret1_impl_(__cap_impl(size_)))>
endm
_Ret_bytecap_ macro size_
  exitm <_SAL1_1_Source_(_Ret_bytecap_, (size_), _Ret1_impl_(__notnull_impl_notref) _Ret1_impl_(__bytecap_impl(size_)))>
endm
_Ret_opt_bytecap_ macro size_
  exitm <_SAL1_1_Source_(_Ret_opt_bytecap_, (size_), _Ret1_impl_(__maybenull_impl_notref) _Ret1_impl_(__bytecap_impl(size_)))>
endm
_Ret_cap_c_ macro size_
  exitm <_SAL1_1_Source_(_Ret_cap_c_, (size_), _Ret1_impl_(__notnull_impl_notref) _Ret1_impl_(__cap_c_impl(size_)))>
endm
_Ret_opt_cap_c_ macro size_
  exitm <_SAL1_1_Source_(_Ret_opt_cap_c_, (size_), _Ret1_impl_(__maybenull_impl_notref) _Ret1_impl_(__cap_c_impl(size_)))>
endm
_Ret_bytecap_c_ macro size_
  exitm <_SAL1_1_Source_(_Ret_bytecap_c_, (size_), _Ret1_impl_(__notnull_impl_notref) _Ret1_impl_(__bytecap_c_impl(size_)))>
endm
_Ret_opt_bytecap_c_ macro size_
  exitm <_SAL1_1_Source_(_Ret_opt_bytecap_c_, (size_), _Ret1_impl_(__maybenull_impl_notref) _Ret1_impl_(__bytecap_c_impl(size_)))>
endm
_Ret_cap_x_ macro size_
  exitm <_SAL1_1_Source_(_Ret_cap_x_, (size_), _Ret1_impl_(__notnull_impl_notref) _Ret1_impl_(__cap_x_impl(size_)))>
endm
_Ret_opt_cap_x_ macro size_
  exitm <_SAL1_1_Source_(_Ret_opt_cap_x_, (size_), _Ret1_impl_(__maybenull_impl_notref) _Ret1_impl_(__cap_x_impl(size_)))>
endm
_Ret_bytecap_x_ macro size_
  exitm <_SAL1_1_Source_(_Ret_bytecap_x_, (size_), _Ret1_impl_(__notnull_impl_notref) _Ret1_impl_(__bytecap_x_impl(size_)))>
endm
_Ret_opt_bytecap_x_ macro size_
  exitm <_SAL1_1_Source_(_Ret_opt_bytecap_x_, (size_), _Ret1_impl_(__maybenull_impl_notref) _Ret1_impl_(__bytecap_x_impl(size_)))>
endm
_Ret_z_cap_ macro size_
  exitm <_SAL1_1_Source_(_Ret_z_cap_, (size_), _Ret1_impl_(__notnull_impl_notref) _Ret2_impl_(__zterm_impl, __cap_impl(size_)) _Ret_valid_impl_)>
endm
_Ret_opt_z_cap_ macro size_
  exitm <_SAL1_1_Source_(_Ret_opt_z_cap_, (size_), _Ret1_impl_(__maybenull_impl_notref) _Ret2_impl_(__zterm_impl, __cap_impl(size_)) _Ret_valid_impl_)>
endm
_Ret_z_bytecap_ macro size_
  exitm <_SAL1_1_Source_(_Ret_z_bytecap_, (size_), _Ret1_impl_(__notnull_impl_notref) _Ret2_impl_(__zterm_impl, __bytecap_impl(size_)) _Ret_valid_impl_)>
endm
_Ret_opt_z_bytecap_ macro size_
  exitm <_SAL1_1_Source_(_Ret_opt_z_bytecap_, (size_), _Ret1_impl_(__maybenull_impl_notref) _Ret2_impl_(__zterm_impl, __bytecap_impl(size_)) _Ret_valid_impl_)>
endm
_Ret_count_ macro size_
  exitm <_SAL1_1_Source_(_Ret_count_, (size_), _Ret1_impl_(__notnull_impl_notref) _Ret1_impl_(__count_impl(size_)) _Ret_valid_impl_)>
endm
_Ret_opt_count_ macro size_
  exitm <_SAL1_1_Source_(_Ret_opt_count_, (size_), _Ret1_impl_(__maybenull_impl_notref) _Ret1_impl_(__count_impl(size_)) _Ret_valid_impl_)>
endm
_Ret_bytecount_ macro size_
  exitm <_SAL1_1_Source_(_Ret_bytecount_, (size_), _Ret1_impl_(__notnull_impl_notref) _Ret1_impl_(__bytecount_impl(size_)) _Ret_valid_impl_)>
endm
_Ret_opt_bytecount_ macro size_
  exitm <_SAL1_1_Source_(_Ret_opt_bytecount_, (size_), _Ret1_impl_(__maybenull_impl_notref) _Ret1_impl_(__bytecount_impl(size_)) _Ret_valid_impl_)>
endm
_Ret_count_c_ macro size_
  exitm <_SAL1_1_Source_(_Ret_count_c_, (size_), _Ret1_impl_(__notnull_impl_notref) _Ret1_impl_(__count_c_impl(size_)) _Ret_valid_impl_)>
endm
_Ret_opt_count_c_ macro size_
  exitm <_SAL1_1_Source_(_Ret_opt_count_c_, (size_), _Ret1_impl_(__maybenull_impl_notref) _Ret1_impl_(__count_c_impl(size_)) _Ret_valid_impl_)>
endm
_Ret_bytecount_c_ macro size_
  exitm <_SAL1_1_Source_(_Ret_bytecount_c_, (size_), _Ret1_impl_(__notnull_impl_notref) _Ret1_impl_(__bytecount_c_impl(size_)) _Ret_valid_impl_)>
endm
_Ret_opt_bytecount_c_ macro size_
  exitm <_SAL1_1_Source_(_Ret_opt_bytecount_c_, (size_), _Ret1_impl_(__maybenull_impl_notref) _Ret1_impl_(__bytecount_c_impl(size_)) _Ret_valid_impl_)>
endm
_Ret_count_x_ macro size_
  exitm <_SAL1_1_Source_(_Ret_count_x_, (size_), _Ret1_impl_(__notnull_impl_notref) _Ret1_impl_(__count_x_impl(size_)) _Ret_valid_impl_)>
endm
_Ret_opt_count_x_ macro size_
  exitm <_SAL1_1_Source_(_Ret_opt_count_x_, (size_), _Ret1_impl_(__maybenull_impl_notref) _Ret1_impl_(__count_x_impl(size_)) _Ret_valid_impl_)>
endm
_Ret_bytecount_x_ macro size_
  exitm <_SAL1_1_Source_(_Ret_bytecount_x_, (size_), _Ret1_impl_(__notnull_impl_notref) _Ret1_impl_(__bytecount_x_impl(size_)) _Ret_valid_impl_)>
endm
_Ret_opt_bytecount_x_ macro size_
  exitm <_SAL1_1_Source_(_Ret_opt_bytecount_x_, (size_), _Ret1_impl_(__maybenull_impl_notref) _Ret1_impl_(__bytecount_x_impl(size_)) _Ret_valid_impl_)>
endm
_Ret_z_count_ macro size_
  exitm <_SAL1_1_Source_(_Ret_z_count_, (size_), _Ret1_impl_(__notnull_impl_notref) _Ret2_impl_(__zterm_impl, __count_impl(size_)) _Ret_valid_impl_)>
endm
_Ret_opt_z_count_ macro size_
  exitm <_SAL1_1_Source_(_Ret_opt_z_count_, (size_), _Ret1_impl_(__maybenull_impl_notref) _Ret2_impl_(__zterm_impl, __count_impl(size_)) _Ret_valid_impl_)>
endm
_Ret_z_bytecount_ macro size_
  exitm <_SAL1_1_Source_(_Ret_z_bytecount_, (size_), _Ret1_impl_(__notnull_impl_notref) _Ret2_impl_(__zterm_impl, __bytecount_impl(size_)) _Ret_valid_impl_)>
endm
_Ret_opt_z_bytecount_ macro size_
  exitm <_SAL1_1_Source_(_Ret_opt_z_bytecount_, (size_), _Ret1_impl_(__maybenull_impl_notref) _Ret2_impl_(__zterm_impl, __bytecount_impl(size_)) _Ret_valid_impl_)>
endm
_Pre_opt_z_ equ <_SAL1_1_Source_(_Pre_opt_z_,, _Pre1_impl_(__maybenull_impl_notref) _Pre1_impl_(__zterm_impl) _Pre_valid_impl_)>
_Pre_readonly_ equ <_SAL1_1_Source_(_Pre_readonly_,, _Pre1_impl_(__readaccess_impl_notref))>
_Pre_writeonly_ equ <_SAL1_1_Source_(_Pre_writeonly_,, _Pre1_impl_(__writeaccess_impl_notref))>
_Pre_cap_ macro size_
  exitm <_SAL1_1_Source_(_Pre_cap_, (size_), _Pre1_impl_(__notnull_impl_notref) _Pre1_impl_(__cap_impl(size_)))>
endm
_Pre_opt_cap_ macro size_
  exitm <_SAL1_1_Source_(_Pre_opt_cap_, (size_), _Pre1_impl_(__maybenull_impl_notref) _Pre1_impl_(__cap_impl(size_)))>
endm
_Pre_bytecap_ macro size_
  exitm <_SAL1_1_Source_(_Pre_bytecap_, (size_), _Pre1_impl_(__notnull_impl_notref) _Pre1_impl_(__bytecap_impl(size_)))>
endm
_Pre_opt_bytecap_ macro size_
  exitm <_SAL1_1_Source_(_Pre_opt_bytecap_, (size_), _Pre1_impl_(__maybenull_impl_notref) _Pre1_impl_(__bytecap_impl(size_)))>
endm
_Pre_cap_c_ macro size_
  exitm <_SAL1_1_Source_(_Pre_cap_c_, (size_), _Pre1_impl_(__notnull_impl_notref) _Pre1_impl_(__cap_c_impl(size_)))>
endm
_Pre_opt_cap_c_ macro size_
  exitm <_SAL1_1_Source_(_Pre_opt_cap_c_, (size_), _Pre1_impl_(__maybenull_impl_notref) _Pre1_impl_(__cap_c_impl(size_)))>
endm
_Pre_bytecap_c_ macro size_
  exitm <_SAL1_1_Source_(_Pre_bytecap_c_, (size_), _Pre1_impl_(__notnull_impl_notref) _Pre1_impl_(__bytecap_c_impl(size_)))>
endm
_Pre_opt_bytecap_c_ macro size_
  exitm <_SAL1_1_Source_(_Pre_opt_bytecap_c_, (size_), _Pre1_impl_(__maybenull_impl_notref) _Pre1_impl_(__bytecap_c_impl(size_)))>
endm
_Pre_cap_c_one_ equ <_SAL1_1_Source_(_Pre_cap_c_one_,, _Pre1_impl_(__notnull_impl_notref) _Pre1_impl_(__cap_c_one_notref_impl))>
_Pre_opt_cap_c_one_ equ <_SAL1_1_Source_(_Pre_opt_cap_c_one_,, _Pre1_impl_(__maybenull_impl_notref) _Pre1_impl_(__cap_c_one_notref_impl))>
_Pre_cap_m_ macro mult, size_
  exitm <_SAL1_1_Source_(_Pre_cap_m_, (mult, size_), _Pre1_impl_(__notnull_impl_notref) _Pre1_impl_(__mult_impl(mult, size_)))>
endm
_Pre_opt_cap_m_ macro mult, size_
  exitm <_SAL1_1_Source_(_Pre_opt_cap_m_, (mult, size_), _Pre1_impl_(__maybenull_impl_notref) _Pre1_impl_(__mult_impl(mult, size_)))>
endm
_Pre_cap_for_ macro param
  exitm <_SAL1_1_Source_(_Pre_cap_for_, (param), _Pre1_impl_(__notnull_impl_notref) _Pre1_impl_(__cap_for_impl(param)))>
endm
_Pre_opt_cap_for_ macro param
  exitm <_SAL1_1_Source_(_Pre_opt_cap_for_, (param), _Pre1_impl_(__maybenull_impl_notref) _Pre1_impl_(__cap_for_impl(param)))>
endm
_Pre_cap_x_ macro size_
  exitm <_SAL1_1_Source_(_Pre_cap_x_, (size_), _Pre1_impl_(__notnull_impl_notref) _Pre1_impl_(__cap_x_impl(size_)))>
endm
_Pre_opt_cap_x_ macro size_
  exitm <_SAL1_1_Source_(_Pre_opt_cap_x_, (size_), _Pre1_impl_(__maybenull_impl_notref) _Pre1_impl_(__cap_x_impl(size_)))>
endm
_Pre_bytecap_x_ macro size_
  exitm <_SAL1_1_Source_(_Pre_bytecap_x_, (size_), _Pre1_impl_(__notnull_impl_notref) _Pre1_impl_(__bytecap_x_impl(size_)))>
endm
_Pre_opt_bytecap_x_ macro size_
  exitm <_SAL1_1_Source_(_Pre_opt_bytecap_x_, (size_), _Pre1_impl_(__maybenull_impl_notref) _Pre1_impl_(__bytecap_x_impl(size_)))>
endm
_Pre_ptrdiff_cap_ macro ptr_
  exitm <_SAL1_1_Source_(_Pre_ptrdiff_cap_, (ptr_), _Pre1_impl_(__notnull_impl_notref) _Pre1_impl_(__cap_x_impl(__ptrdiff (ptr_))))>
endm
_Pre_opt_ptrdiff_cap_ macro ptr_
  exitm <_SAL1_1_Source_(_Pre_opt_ptrdiff_cap_, (ptr_), _Pre1_impl_(__maybenull_impl_notref) _Pre1_impl_(__cap_x_impl(__ptrdiff (ptr_))))>
endm
_Pre_z_cap_ macro size_
  exitm <_SAL1_1_Source_(_Pre_z_cap_, (size_), _Pre1_impl_(__notnull_impl_notref) _Pre2_impl_(__zterm_impl, __cap_impl(size_)) _Pre_valid_impl_)>
endm
_Pre_opt_z_cap_ macro size_
  exitm <_SAL1_1_Source_(_Pre_opt_z_cap_, (size_), _Pre1_impl_(__maybenull_impl_notref) _Pre2_impl_(__zterm_impl, __cap_impl(size_)) _Pre_valid_impl_)>
endm
_Pre_z_bytecap_ macro size_
  exitm <_SAL1_1_Source_(_Pre_z_bytecap_, (size_), _Pre1_impl_(__notnull_impl_notref) _Pre2_impl_(__zterm_impl, __bytecap_impl(size_)) _Pre_valid_impl_)>
endm
_Pre_opt_z_bytecap_ macro size_
  exitm <_SAL1_1_Source_(_Pre_opt_z_bytecap_, (size_), _Pre1_impl_(__maybenull_impl_notref) _Pre2_impl_(__zterm_impl, __bytecap_impl(size_)) _Pre_valid_impl_)>
endm
_Pre_z_cap_c_ macro size_
  exitm <_SAL1_1_Source_(_Pre_z_cap_c_, (size_), _Pre1_impl_(__notnull_impl_notref) _Pre2_impl_(__zterm_impl, __cap_c_impl(size_)) _Pre_valid_impl_)>
endm
_Pre_opt_z_cap_c_ macro size_
  exitm <_SAL1_1_Source_(_Pre_opt_z_cap_c_, (size_), _Pre1_impl_(__maybenull_impl_notref) _Pre2_impl_(__zterm_impl, __cap_c_impl(size_)) _Pre_valid_impl_)>
endm
_Pre_z_bytecap_c_ macro size_
  exitm <_SAL1_1_Source_(_Pre_z_bytecap_c_, (size_), _Pre1_impl_(__notnull_impl_notref) _Pre2_impl_(__zterm_impl, __bytecap_c_impl(size_)) _Pre_valid_impl_)>
endm
_Pre_opt_z_bytecap_c_ macro size_
  exitm <_SAL1_1_Source_(_Pre_opt_z_bytecap_c_, (size_), _Pre1_impl_(__maybenull_impl_notref) _Pre2_impl_(__zterm_impl, __bytecap_c_impl(size_)) _Pre_valid_impl_)>
endm
_Pre_z_cap_x_ macro size_
  exitm <_SAL1_1_Source_(_Pre_z_cap_x_, (size_), _Pre1_impl_(__notnull_impl_notref) _Pre2_impl_(__zterm_impl, __cap_x_impl(size_)) _Pre_valid_impl_)>
endm
_Pre_opt_z_cap_x_ macro size_
  exitm <_SAL1_1_Source_(_Pre_opt_z_cap_x_, (size_), _Pre1_impl_(__maybenull_impl_notref) _Pre2_impl_(__zterm_impl, __cap_x_impl(size_)) _Pre_valid_impl_)>
endm
_Pre_z_bytecap_x_ macro size_
  exitm <_SAL1_1_Source_(_Pre_z_bytecap_x_, (size_), _Pre1_impl_(__notnull_impl_notref) _Pre2_impl_(__zterm_impl, __bytecap_x_impl(size_)) _Pre_valid_impl_)>
endm
_Pre_opt_z_bytecap_x_ macro size_
  exitm <_SAL1_1_Source_(_Pre_opt_z_bytecap_x_, (size_), _Pre1_impl_(__maybenull_impl_notref) _Pre2_impl_(__zterm_impl, __bytecap_x_impl(size_)) _Pre_valid_impl_)>
endm
_Pre_valid_cap_ macro size_
  exitm <_SAL1_1_Source_(_Pre_valid_cap_, (size_), _Pre1_impl_(__notnull_impl_notref) _Pre1_impl_(__cap_impl(size_)) _Pre_valid_impl_)>
endm
_Pre_opt_valid_cap_ macro size_
  exitm <_SAL1_1_Source_(_Pre_opt_valid_cap_, (size_), _Pre1_impl_(__maybenull_impl_notref) _Pre1_impl_(__cap_impl(size_)) _Pre_valid_impl_)>
endm
_Pre_valid_bytecap_ macro size_
  exitm <_SAL1_1_Source_(_Pre_valid_bytecap_, (size_), _Pre1_impl_(__notnull_impl_notref) _Pre1_impl_(__bytecap_impl(size_)) _Pre_valid_impl_)>
endm
_Pre_opt_valid_bytecap_ macro size_
  exitm <_SAL1_1_Source_(_Pre_opt_valid_bytecap_, (size_), _Pre1_impl_(__maybenull_impl_notref) _Pre1_impl_(__bytecap_impl(size_)) _Pre_valid_impl_)>
endm
_Pre_valid_cap_c_ macro size_
  exitm <_SAL1_1_Source_(_Pre_valid_cap_c_, (size_), _Pre1_impl_(__notnull_impl_notref) _Pre1_impl_(__cap_c_impl(size_)) _Pre_valid_impl_)>
endm
_Pre_opt_valid_cap_c_ macro size_
  exitm <_SAL1_1_Source_(_Pre_opt_valid_cap_c_, (size_), _Pre1_impl_(__maybenull_impl_notref) _Pre1_impl_(__cap_c_impl(size_)) _Pre_valid_impl_)>
endm
_Pre_valid_bytecap_c_ macro size_
  exitm <_SAL1_1_Source_(_Pre_valid_bytecap_c_, (size_), _Pre1_impl_(__notnull_impl_notref) _Pre1_impl_(__bytecap_c_impl(size_)) _Pre_valid_impl_)>
endm
_Pre_opt_valid_bytecap_c_ macro size_
  exitm <_SAL1_1_Source_(_Pre_opt_valid_bytecap_c_, (size_), _Pre1_impl_(__maybenull_impl_notref) _Pre1_impl_(__bytecap_c_impl(size_)) _Pre_valid_impl_)>
endm
_Pre_valid_cap_x_ macro size_
  exitm <_SAL1_1_Source_(_Pre_valid_cap_x_, (size_), _Pre1_impl_(__notnull_impl_notref) _Pre1_impl_(__cap_x_impl(size_)) _Pre_valid_impl_)>
endm
_Pre_opt_valid_cap_x_ macro size_
  exitm <_SAL1_1_Source_(_Pre_opt_valid_cap_x_, (size_), _Pre1_impl_(__maybenull_impl_notref) _Pre1_impl_(__cap_x_impl(size_)) _Pre_valid_impl_)>
endm
_Pre_valid_bytecap_x_ macro size_
  exitm <_SAL1_1_Source_(_Pre_valid_bytecap_x_, (size_), _Pre1_impl_(__notnull_impl_notref) _Pre1_impl_(__bytecap_x_impl(size_)) _Pre_valid_impl_)>
endm
_Pre_opt_valid_bytecap_x_ macro size_
  exitm <_SAL1_1_Source_(_Pre_opt_valid_bytecap_x_, (size_), _Pre1_impl_(__maybenull_impl_notref) _Pre1_impl_(__bytecap_x_impl(size_)) _Pre_valid_impl_)>
endm
_Pre_count_ macro size_
  exitm <_SAL1_1_Source_(_Pre_count_, (size_), _Pre1_impl_(__notnull_impl_notref) _Pre1_impl_(__count_impl(size_)) _Pre_valid_impl_)>
endm
_Pre_opt_count_ macro size_
  exitm <_SAL1_1_Source_(_Pre_opt_count_, (size_), _Pre1_impl_(__maybenull_impl_notref) _Pre1_impl_(__count_impl(size_)) _Pre_valid_impl_)>
endm
_Pre_bytecount_ macro size_
  exitm <_SAL1_1_Source_(_Pre_bytecount_, (size_), _Pre1_impl_(__notnull_impl_notref) _Pre1_impl_(__bytecount_impl(size_)) _Pre_valid_impl_)>
endm
_Pre_opt_bytecount_ macro size_
  exitm <_SAL1_1_Source_(_Pre_opt_bytecount_, (size_), _Pre1_impl_(__maybenull_impl_notref) _Pre1_impl_(__bytecount_impl(size_)) _Pre_valid_impl_)>
endm
_Pre_count_c_ macro size_
  exitm <_SAL1_1_Source_(_Pre_count_c_, (size_), _Pre1_impl_(__notnull_impl_notref) _Pre1_impl_(__count_c_impl(size_)) _Pre_valid_impl_)>
endm
_Pre_opt_count_c_ macro size_
  exitm <_SAL1_1_Source_(_Pre_opt_count_c_, (size_), _Pre1_impl_(__maybenull_impl_notref) _Pre1_impl_(__count_c_impl(size_)) _Pre_valid_impl_)>
endm
_Pre_bytecount_c_ macro size_
  exitm <_SAL1_1_Source_(_Pre_bytecount_c_, (size_), _Pre1_impl_(__notnull_impl_notref) _Pre1_impl_(__bytecount_c_impl(size_)) _Pre_valid_impl_)>
endm
_Pre_opt_bytecount_c_ macro size_
  exitm <_SAL1_1_Source_(_Pre_opt_bytecount_c_, (size_), _Pre1_impl_(__maybenull_impl_notref) _Pre1_impl_(__bytecount_c_impl(size_)) _Pre_valid_impl_)>
endm
_Pre_count_x_ macro size_
  exitm <_SAL1_1_Source_(_Pre_count_x_, (size_), _Pre1_impl_(__notnull_impl_notref) _Pre1_impl_(__count_x_impl(size_)) _Pre_valid_impl_)>
endm
_Pre_opt_count_x_ macro size_
  exitm <_SAL1_1_Source_(_Pre_opt_count_x_, (size_), _Pre1_impl_(__maybenull_impl_notref) _Pre1_impl_(__count_x_impl(size_)) _Pre_valid_impl_)>
endm
_Pre_bytecount_x_ macro size_
  exitm <_SAL1_1_Source_(_Pre_bytecount_x_, (size_), _Pre1_impl_(__notnull_impl_notref) _Pre1_impl_(__bytecount_x_impl(size_)) _Pre_valid_impl_)>
endm
_Pre_opt_bytecount_x_ macro size_
  exitm <_SAL1_1_Source_(_Pre_opt_bytecount_x_, (size_), _Pre1_impl_(__maybenull_impl_notref) _Pre1_impl_(__bytecount_x_impl(size_)) _Pre_valid_impl_)>
endm
_Pre_ptrdiff_count_ macro ptr_
  exitm <_SAL1_1_Source_(_Pre_ptrdiff_count_, (ptr_), _Pre1_impl_(__notnull_impl_notref) _Pre1_impl_(__count_x_impl(__ptrdiff (ptr_))) _Pre_valid_impl_)>
endm
_Pre_opt_ptrdiff_count_ macro ptr_
  exitm <_SAL1_1_Source_(_Pre_opt_ptrdiff_count_, (ptr_), _Pre1_impl_(__maybenull_impl_notref) _Pre1_impl_(__count_x_impl(__ptrdiff (ptr_))) _Pre_valid_impl_)>
endm
_Post_maybez_ equ <_SAL_L_Source_(_Post_maybez_,, _Post1_impl_(__maybezterm_impl))>
_Post_cap_ macro size_
  exitm <_SAL1_1_Source_(_Post_cap_, (size_), _Post1_impl_(__cap_impl(size_)))>
endm
_Post_bytecap_ macro size_
  exitm <_SAL1_1_Source_(_Post_bytecap_, (size_), _Post1_impl_(__bytecap_impl(size_)))>
endm
_Post_count_ macro size_
  exitm <_SAL1_1_Source_(_Post_count_, (size_), _Post1_impl_(__count_impl(size_)) _Post_valid_impl_)>
endm
_Post_bytecount_ macro size_
  exitm <_SAL1_1_Source_(_Post_bytecount_, (size_), _Post1_impl_(__bytecount_impl(size_)) _Post_valid_impl_)>
endm
_Post_count_c_ macro size_
  exitm <_SAL1_1_Source_(_Post_count_c_, (size_), _Post1_impl_(__count_c_impl(size_)) _Post_valid_impl_)>
endm
_Post_bytecount_c_ macro size_
  exitm <_SAL1_1_Source_(_Post_bytecount_c_, (size_), _Post1_impl_(__bytecount_c_impl(size_)) _Post_valid_impl_)>
endm
_Post_count_x_ macro size_
  exitm <_SAL1_1_Source_(_Post_count_x_, (size_), _Post1_impl_(__count_x_impl(size_)) _Post_valid_impl_)>
endm
_Post_bytecount_x_ macro size_
  exitm <_SAL1_1_Source_(_Post_bytecount_x_, (size_), _Post1_impl_(__bytecount_x_impl(size_)) _Post_valid_impl_)>
endm
_Post_z_count_ macro size_
  exitm <_SAL1_1_Source_(_Post_z_count_, (size_), _Post2_impl_(__zterm_impl, __count_impl(size_)) _Post_valid_impl_)>
endm
_Post_z_bytecount_ macro size_
  exitm <_SAL1_1_Source_(_Post_z_bytecount_, (size_), _Post2_impl_(__zterm_impl, __bytecount_impl(size_)) _Post_valid_impl_)>
endm
_Post_z_count_c_ macro size_
  exitm <_SAL1_1_Source_(_Post_z_count_c_, (size_), _Post2_impl_(__zterm_impl, __count_c_impl(size_)) _Post_valid_impl_)>
endm
_Post_z_bytecount_c_ macro size_
  exitm <_SAL1_1_Source_(_Post_z_bytecount_c_, (size_), _Post2_impl_(__zterm_impl, __bytecount_c_impl(size_)) _Post_valid_impl_)>
endm
_Post_z_count_x_ macro size_
  exitm <_SAL1_1_Source_(_Post_z_count_x_, (size_), _Post2_impl_(__zterm_impl, __count_x_impl(size_)) _Post_valid_impl_)>
endm
_Post_z_bytecount_x_ macro size_
  exitm <_SAL1_1_Source_(_Post_z_bytecount_x_, (size_), _Post2_impl_(__zterm_impl, __bytecount_x_impl(size_)) _Post_valid_impl_)>
endm
_Prepost_opt_z_ equ <_SAL1_1_Source_(_Prepost_opt_z_,, _Pre_opt_z_ _Post_z_)>
_Prepost_count_ macro size_
  exitm <_SAL1_1_Source_(_Prepost_count_, (size_), _Pre_count_(size_) _Post_count_(size_))>
endm
_Prepost_opt_count_ macro size_
  exitm <_SAL1_1_Source_(_Prepost_opt_count_, (size_), _Pre_opt_count_(size_) _Post_count_(size_))>
endm
_Prepost_bytecount_ macro size_
  exitm <_SAL1_1_Source_(_Prepost_bytecount_, (size_), _Pre_bytecount_(size_) _Post_bytecount_(size_))>
endm
_Prepost_opt_bytecount_ macro size_
  exitm <_SAL1_1_Source_(_Prepost_opt_bytecount_, (size_), _Pre_opt_bytecount_(size_) _Post_bytecount_(size_))>
endm
_Prepost_count_c_ macro size_
  exitm <_SAL1_1_Source_(_Prepost_count_c_, (size_), _Pre_count_c_(size_) _Post_count_c_(size_))>
endm
_Prepost_opt_count_c_ macro size_
  exitm <_SAL1_1_Source_(_Prepost_opt_count_c_, (size_), _Pre_opt_count_c_(size_) _Post_count_c_(size_))>
endm
_Prepost_bytecount_c_ macro size_
  exitm <_SAL1_1_Source_(_Prepost_bytecount_c_, (size_), _Pre_bytecount_c_(size_) _Post_bytecount_c_(size_))>
endm
_Prepost_opt_bytecount_c_ macro size_
  exitm <_SAL1_1_Source_(_Prepost_opt_bytecount_c_, (size_), _Pre_opt_bytecount_c_(size_) _Post_bytecount_c_(size_))>
endm
_Prepost_count_x_ macro size_
  exitm <_SAL1_1_Source_(_Prepost_count_x_, (size_), _Pre_count_x_(size_) _Post_count_x_(size_))>
endm
_Prepost_opt_count_x_ macro size_
  exitm <_SAL1_1_Source_(_Prepost_opt_count_x_, (size_), _Pre_opt_count_x_(size_) _Post_count_x_(size_))>
endm
_Prepost_bytecount_x_ macro size_
  exitm <_SAL1_1_Source_(_Prepost_bytecount_x_, (size_), _Pre_bytecount_x_(size_) _Post_bytecount_x_(size_))>
endm
_Prepost_opt_bytecount_x_ macro size_
  exitm <_SAL1_1_Source_(_Prepost_opt_bytecount_x_, (size_), _Pre_opt_bytecount_x_(size_) _Post_bytecount_x_(size_))>
endm
_Prepost_valid_ equ <_SAL1_1_Source_(_Prepost_valid_,, _Pre_valid_ _Post_valid_)>
_Prepost_opt_valid_ equ <_SAL1_1_Source_(_Prepost_opt_valid_,, _Pre_opt_valid_ _Post_valid_)>
_Deref_prepost_z_ equ <_SAL1_1_Source_(_Deref_prepost_z_,, _Deref_pre_z_ _Deref_post_z_)>
_Deref_prepost_opt_z_ equ <_SAL1_1_Source_(_Deref_prepost_opt_z_,, _Deref_pre_opt_z_ _Deref_post_opt_z_)>
_Deref_prepost_cap_ macro size_
  exitm <_SAL1_1_Source_(_Deref_prepost_cap_, (size_), _Deref_pre_cap_(size_) _Deref_post_cap_(size_))>
endm
_Deref_prepost_opt_cap_ macro size_
  exitm <_SAL1_1_Source_(_Deref_prepost_opt_cap_, (size_), _Deref_pre_opt_cap_(size_) _Deref_post_opt_cap_(size_))>
endm
_Deref_prepost_bytecap_ macro size_
  exitm <_SAL1_1_Source_(_Deref_prepost_bytecap_, (size_), _Deref_pre_bytecap_(size_) _Deref_post_bytecap_(size_))>
endm
_Deref_prepost_opt_bytecap_ macro size_
  exitm <_SAL1_1_Source_(_Deref_prepost_opt_bytecap_, (size_), _Deref_pre_opt_bytecap_(size_) _Deref_post_opt_bytecap_(size_))>
endm
_Deref_prepost_cap_x_ macro size_
  exitm <_SAL1_1_Source_(_Deref_prepost_cap_x_, (size_), _Deref_pre_cap_x_(size_) _Deref_post_cap_x_(size_))>
endm
_Deref_prepost_opt_cap_x_ macro size_
  exitm <_SAL1_1_Source_(_Deref_prepost_opt_cap_x_, (size_), _Deref_pre_opt_cap_x_(size_) _Deref_post_opt_cap_x_(size_))>
endm
_Deref_prepost_bytecap_x_ macro size_
  exitm <_SAL1_1_Source_(_Deref_prepost_bytecap_x_, (size_), _Deref_pre_bytecap_x_(size_) _Deref_post_bytecap_x_(size_))>
endm
_Deref_prepost_opt_bytecap_x_ macro size_
  exitm <_SAL1_1_Source_(_Deref_prepost_opt_bytecap_x_, (size_), _Deref_pre_opt_bytecap_x_(size_) _Deref_post_opt_bytecap_x_(size_))>
endm
_Deref_prepost_z_cap_ macro size_
  exitm <_SAL1_1_Source_(_Deref_prepost_z_cap_, (size_), _Deref_pre_z_cap_(size_) _Deref_post_z_cap_(size_))>
endm
_Deref_prepost_opt_z_cap_ macro size_
  exitm <_SAL1_1_Source_(_Deref_prepost_opt_z_cap_, (size_), _Deref_pre_opt_z_cap_(size_) _Deref_post_opt_z_cap_(size_))>
endm
_Deref_prepost_z_bytecap_ macro size_
  exitm <_SAL1_1_Source_(_Deref_prepost_z_bytecap_, (size_), _Deref_pre_z_bytecap_(size_) _Deref_post_z_bytecap_(size_))>
endm
_Deref_prepost_opt_z_bytecap_ macro size_
  exitm <_SAL1_1_Source_(_Deref_prepost_opt_z_bytecap_, (size_), _Deref_pre_opt_z_bytecap_(size_) _Deref_post_opt_z_bytecap_(size_))>
endm
_Deref_prepost_valid_cap_ macro size_
  exitm <_SAL1_1_Source_(_Deref_prepost_valid_cap_, (size_), _Deref_pre_valid_cap_(size_) _Deref_post_valid_cap_(size_))>
endm
_Deref_prepost_opt_valid_cap_ macro size_
  exitm <_SAL1_1_Source_(_Deref_prepost_opt_valid_cap_, (size_), _Deref_pre_opt_valid_cap_(size_) _Deref_post_opt_valid_cap_(size_))>
endm
_Deref_prepost_valid_bytecap_ macro size_
  exitm <_SAL1_1_Source_(_Deref_prepost_valid_bytecap_, (size_), _Deref_pre_valid_bytecap_(size_) _Deref_post_valid_bytecap_(size_))>
endm
_Deref_prepost_opt_valid_bytecap_ macro size_
  exitm <_SAL1_1_Source_(_Deref_prepost_opt_valid_bytecap_, (size_), _Deref_pre_opt_valid_bytecap_(size_) _Deref_post_opt_valid_bytecap_(size_))>
endm
_Deref_prepost_valid_cap_x_ macro size_
  exitm <_SAL1_1_Source_(_Deref_prepost_valid_cap_x_, (size_), _Deref_pre_valid_cap_x_(size_) _Deref_post_valid_cap_x_(size_))>
endm
_Deref_prepost_opt_valid_cap_x_ macro size_
  exitm <_SAL1_1_Source_(_Deref_prepost_opt_valid_cap_x_, (size_), _Deref_pre_opt_valid_cap_x_(size_) _Deref_post_opt_valid_cap_x_(size_))>
endm
_Deref_prepost_valid_bytecap_x_ macro size_
  exitm <_SAL1_1_Source_(_Deref_prepost_valid_bytecap_x_, (size_), _Deref_pre_valid_bytecap_x_(size_) _Deref_post_valid_bytecap_x_(size_))>
endm
_Deref_prepost_opt_valid_bytecap_x_ macro size_
  exitm <_SAL1_1_Source_(_Deref_prepost_opt_valid_bytecap_x_, (size_), _Deref_pre_opt_valid_bytecap_x_(size_) _Deref_post_opt_valid_bytecap_x_(size_))>
endm
_Deref_prepost_count_ macro size_
  exitm <_SAL1_1_Source_(_Deref_prepost_count_, (size_), _Deref_pre_count_(size_) _Deref_post_count_(size_))>
endm
_Deref_prepost_opt_count_ macro size_
  exitm <_SAL1_1_Source_(_Deref_prepost_opt_count_, (size_), _Deref_pre_opt_count_(size_) _Deref_post_opt_count_(size_))>
endm
_Deref_prepost_bytecount_ macro size_
  exitm <_SAL1_1_Source_(_Deref_prepost_bytecount_, (size_), _Deref_pre_bytecount_(size_) _Deref_post_bytecount_(size_))>
endm
_Deref_prepost_opt_bytecount_ macro size_
  exitm <_SAL1_1_Source_(_Deref_prepost_opt_bytecount_, (size_), _Deref_pre_opt_bytecount_(size_) _Deref_post_opt_bytecount_(size_))>
endm
_Deref_prepost_count_x_ macro size_
  exitm <_SAL1_1_Source_(_Deref_prepost_count_x_, (size_), _Deref_pre_count_x_(size_) _Deref_post_count_x_(size_))>
endm
_Deref_prepost_opt_count_x_ macro size_
  exitm <_SAL1_1_Source_(_Deref_prepost_opt_count_x_, (size_), _Deref_pre_opt_count_x_(size_) _Deref_post_opt_count_x_(size_))>
endm
_Deref_prepost_bytecount_x_ macro size_
  exitm <_SAL1_1_Source_(_Deref_prepost_bytecount_x_, (size_), _Deref_pre_bytecount_x_(size_) _Deref_post_bytecount_x_(size_))>
endm
_Deref_prepost_opt_bytecount_x_ macro size_
  exitm <_SAL1_1_Source_(_Deref_prepost_opt_bytecount_x_, (size_), _Deref_pre_opt_bytecount_x_(size_) _Deref_post_opt_bytecount_x_(size_))>
endm
_Deref_prepost_valid_ equ <_SAL1_1_Source_(_Deref_prepost_valid_,, _Deref_pre_valid_ _Deref_post_valid_)>
_Deref_prepost_opt_valid_ equ <_SAL1_1_Source_(_Deref_prepost_opt_valid_,, _Deref_pre_opt_valid_ _Deref_post_opt_valid_)>
_Deref_out_z_cap_c_ macro size_
  exitm <_SAL1_1_Source_(_Deref_out_z_cap_c_, (size_), _Deref_pre_cap_c_(size_) _Deref_post_z_)>
endm
_Deref_inout_z_cap_c_ macro size_
  exitm <_SAL1_1_Source_(_Deref_inout_z_cap_c_, (size_), _Deref_pre_z_cap_c_(size_) _Deref_post_z_)>
endm
_Deref_out_z_bytecap_c_ macro size_
  exitm <_SAL1_1_Source_(_Deref_out_z_bytecap_c_, (size_), _Deref_pre_bytecap_c_(size_) _Deref_post_z_)>
endm
_Deref_inout_z_bytecap_c_ macro size_
  exitm <_SAL1_1_Source_(_Deref_inout_z_bytecap_c_, (size_), _Deref_pre_z_bytecap_c_(size_) _Deref_post_z_)>
endm
_Deref_inout_z_ equ <_SAL1_1_Source_(_Deref_inout_z_,, _Deref_prepost_z_)>
if _USE_ATTRIBUTES_FOR_SAL or _USE_DECLSPECS_FOR_SAL
  _Always_impl_ macro annos
    exitm <_Group_(annos _SAL_nop_impl_) _On_failure_impl_(annos _SAL_nop_impl_)>
  endm
  _Bound_impl_ equ <_SA_annotes0(SAL_bound)>
  _Field_range_impl_ macro min, max
    exitm <_Range_impl_(min, max)>
  endm
  _Literal_impl_ equ <_SA_annotes1(SAL_constant, __yes)>
  _Maybenull_impl_ equ <_SA_annotes1(SAL_null, __maybe)>
  _Maybevalid_impl_ equ <_SA_annotes1(SAL_valid, __maybe)>
  _Must_inspect_impl_ equ <_Post_impl_ _SA_annotes0(SAL_mustInspect)>
  _Notliteral_impl_ equ <_SA_annotes1(SAL_constant, __no)>
  _Notnull_impl_ equ <_SA_annotes1(SAL_null, __no)>
  _Notvalid_impl_ equ <_SA_annotes1(SAL_valid, __no)>
  _NullNull_terminated_impl_ equ <_Group_(_SA_annotes1(SAL_nullTerminated, __yes) _SA_annotes1(SAL_readableTo, inexpressibleCount ("NullNull terminated string")))>
  _Null_impl_ equ <_SA_annotes1(SAL_null, __yes)>
  _Null_terminated_impl_ equ <_SA_annotes1(SAL_nullTerminated, __yes)>
  _Out_impl_ equ <_Pre1_impl_(__notnull_impl_notref) _Pre1_impl_(__cap_c_one_notref_impl) _Post_valid_impl_>
  _Out_opt_impl_ equ <_Pre1_impl_(__maybenull_impl_notref) _Pre1_impl_(__cap_c_one_notref_impl) _Post_valid_impl_>
  _Points_to_data_impl_ equ <_At_(* _Curr_, _SA_annotes1(SAL_mayBePointer, __no))>
  _Post_satisfies_impl_ macro cond
    exitm <_Post_impl_ _Satisfies_impl_(cond)>
  endm
  _Post_valid_impl_ equ <_Post1_impl_(__valid_impl)>
  _Pre_satisfies_impl_ macro cond
    exitm <_Pre_impl_ _Satisfies_impl_(cond)>
  endm
  _Pre_valid_impl_ equ <_Pre1_impl_(__valid_impl)>
  _Range_impl_ macro min, max
    exitm <_SA_annotes2(SAL_range, min, max)>
  endm
  _Readable_bytes_impl_ macro size_
    exitm <_SA_annotes1(SAL_readableTo, byteCount (size_))>
  endm
  _Readable_elements_impl_ macro size_
    exitm <_SA_annotes1(SAL_readableTo, elementCount (size_))>
  endm
  _Ret_valid_impl_ equ <_Ret1_impl_(__valid_impl)>
  _Satisfies_impl_ macro cond
    exitm <_SA_annotes1(SAL_satisfies, cond)>
  endm
  _Valid_impl_ equ <_SA_annotes1(SAL_valid, __yes)>
  _Writable_bytes_impl_ macro size_
    exitm <_SA_annotes1(SAL_writableTo, byteCount (size_))>
  endm
  _Writable_elements_impl_ macro size_
    exitm <_SA_annotes1(SAL_writableTo, elementCount (size_))>
  endm
  _In_range_impl_ macro min, max
    exitm <_Pre_impl_ _Range_impl_(min, max)>
  endm
  _Out_range_impl_ macro min, max
    exitm <_Post_impl_ _Range_impl_(min, max)>
  endm
  _Ret_range_impl_ macro min, max
    exitm <_Post_impl_ _Range_impl_(min, max)>
  endm
  _Deref_in_range_impl_ macro min, max
    exitm <_Deref_pre_impl_ _Range_impl_(min, max)>
  endm
  _Deref_out_range_impl_ macro min, max
    exitm <_Deref_post_impl_ _Range_impl_(min, max)>
  endm
  _Deref_ret_range_impl_ macro min, max
    exitm <_Deref_post_impl_ _Range_impl_(min, max)>
  endm
  _Deref_pre_impl_ equ <_Pre_impl_ _Notref_impl_ _Deref_impl_>
  _Deref_post_impl_ equ <_Post_impl_ _Notref_impl_ _Deref_impl_>
  __AuToQuOtE equ <_SA_annotes0(SAL_AuToQuOtE)>
  __deferTypecheck equ <_SA_annotes0(SAL_deferTypecheck)>
  _SA_SPECSTRIZE macro x
    exitm <# x>
  endm
  _SAL_nop_impl_ equ <>
  __nop_impl macro x
    exitm <x>
  endm
endif
if _USE_ATTRIBUTES_FOR_SAL
  include codeanalysissourceannotations.inc
  _SA_annotes0 macro n
    exitm <[ SAL_annotes (Name = # n) ]>
  endm
  _SA_annotes1 macro n, pp1
    exitm <[ SAL_annotes (Name = # n, p1 = _SA_SPECSTRIZE(pp1)) ]>
  endm
  _SA_annotes2 macro n, pp1, pp2
    exitm <[ SAL_annotes (Name = # n, p1 = _SA_SPECSTRIZE(pp1), p2 = _SA_SPECSTRIZE(pp2)) ]>
  endm
  _SA_annotes3 macro n, pp1, pp2, pp3
    exitm <[ SAL_annotes (Name = # n, p1 = _SA_SPECSTRIZE(pp1), p2 = _SA_SPECSTRIZE(pp2), p3 = _SA_SPECSTRIZE(pp3)) ]>
  endm
  _Pre_impl_ equ <[ SAL_pre ]>
  _Post_impl_ equ <[ SAL_post ]>
  _Deref_impl_ equ <[ SAL_deref ]>
  _Notref_impl_ equ <[ SAL_notref ]>
  __ANNOTATION macro fun
    exitm <_SA_annotes0(SAL_annotation) void __SA_ ## fun ;>
  endm
  __PRIMOP macro type_, fun
    exitm <_SA_annotes0(SAL_primop) type_ __SA_ ## fun ;>
  endm
  __QUALIFIER macro fun
    exitm <_SA_annotes0(SAL_qualifier) void __SA_ ## fun ;>
  endm
  __In_impl_ equ <[ SA_Pre (Valid = SA_Yes) ] [ SA_Pre (Deref = 1, Notref = 1, Access = SA_Read) ] __declspec("SAL_pre SAL_valid")>
elseif _USE_DECLSPECS_FOR_SAL
  _SA_annotes0 macro n
    exitm <__declspec(# n)>
  endm
  _SA_annotes1 macro n, pp1
    exitm <__declspec(# n "(" _SA_SPECSTRIZE(pp1) ")")>
  endm
  _SA_annotes2 macro n, pp1, pp2
    exitm <__declspec(# n "(" _SA_SPECSTRIZE(pp1) "," _SA_SPECSTRIZE(pp2) ")")>
  endm
  _SA_annotes3 macro n, pp1, pp2, pp3
    exitm <__declspec(# n "(" _SA_SPECSTRIZE(pp1) "," _SA_SPECSTRIZE(pp2) "," _SA_SPECSTRIZE(pp3) ")")>
  endm
  _Pre_impl_ equ <_SA_annotes0(SAL_pre)>
  _Post_impl_ equ <_SA_annotes0(SAL_post)>
  _Deref_impl_ equ <_SA_annotes0(SAL_deref)>
  _Notref_impl_ equ <_SA_annotes0(SAL_notref)>
  __ANNOTATION macro fun
    exitm <_SA_annotes0(SAL_annotation) void __SA_ ## fun>
  endm
  __PRIMOP macro type_, fun
    exitm <_SA_annotes0(SAL_primop) type_ __SA_ ## fun>
  endm
  __QUALIFIER macro fun
    exitm <_SA_annotes0(SAL_qualifier) void __SA_ ## fun ;>
  endm
  __In_impl_ equ <_Pre_impl_ _SA_annotes0(SAL_valid) _Pre_impl_ _Deref_impl_ _Notref_impl_ _SA_annotes0(SAL_readonly)>
else
  _SA_annotes0 macro n
    exitm <>
  endm
  _SA_annotes1 macro n, pp1
    exitm <>
  endm
  _SA_annotes2 macro n, pp1, pp2
    exitm <>
  endm
  _SA_annotes3 macro n, pp1, pp2, pp3
    exitm <>
  endm
  __ANNOTATION macro fun
    exitm <>
  endm
  __PRIMOP macro type_, fun
    exitm <>
  endm
  __QUALIFIER macro type_, fun
    exitm <>
  endm
endif
if _USE_ATTRIBUTES_FOR_SAL or _USE_DECLSPECS_FOR_SAL
endif
if _USE_ATTRIBUTES_FOR_SAL
  _Check_return_impl_ equ <[ SA_Post (MustCheck = SA_Yes) ]>
  _Success_impl_ macro expr
    exitm <[ SA_Success (Condition = # expr) ]>
  endm
  _On_failure_impl_ macro annos
    exitm <[ SAL_context (p1 = "SAL_failed") ] _Group_(_Post_impl_ _Group_(annos _SAL_nop_impl_))>
  endm
  _Printf_format_string_impl_ equ <[ SA_FormatString (Style = "printf") ]>
  _Scanf_format_string_impl_ equ <[ SA_FormatString (Style = "scanf") ]>
  _Scanf_s_format_string_impl_ equ <[ SA_FormatString (Style = "scanf_s") ]>
  _In_bound_impl_ equ [ SA_PreBound (Deref = 0) ]
  _Out_bound_impl_ equ [ SA_PostBound (Deref = 0) ]
  _Ret_bound_impl_ equ [ SA_PostBound (Deref = 0) ]
  _Deref_in_bound_impl_ equ [ SA_PreBound (Deref = 1) ]
  _Deref_out_bound_impl_ equ [ SA_PostBound (Deref = 1) ]
  _Deref_ret_bound_impl_ equ [ SA_PostBound (Deref = 1) ]
  __valid_impl equ <Valid = SA_Yes>
  __maybevalid_impl equ <Valid = SA_Maybe>
  __notvalid_impl equ <Valid = SA_No>
  __null_impl equ <Null = SA_Yes>
  __maybenull_impl equ <Null = SA_Maybe>
  __notnull_impl equ <Null = SA_No>
  __null_impl_notref equ Null = SA_Yes, Notref = 1
  __maybenull_impl_notref equ Null = SA_Maybe, Notref = 1
  __notnull_impl_notref equ Null = SA_No, Notref = 1
  __zterm_impl equ <NullTerminated = SA_Yes>
  __maybezterm_impl equ <NullTerminated = SA_Maybe>
  __maybzterm_impl equ <NullTerminated = SA_Maybe>
  __notzterm_impl equ <NullTerminated = SA_No>
  __readaccess_impl equ <Access = SA_Read>
  __writeaccess_impl equ <Access = SA_Write>
  __allaccess_impl equ <Access = SA_ReadWrite>
  __readaccess_impl_notref equ Access = SA_Read, Notref = 1
  __writeaccess_impl_notref equ Access = SA_Write, Notref = 1
  __allaccess_impl_notref equ Access = SA_ReadWrite, Notref = 1
  if _MSC_VER ge 1610
    __cap_impl macro size_
      exitm <WritableElements = 0Ah # size_>
    endm
    __bytecap_impl macro size_
      exitm <WritableBytes = 0Ah # size_>
    endm
    __bytecount_impl macro size_
      exitm <ValidBytes = 0Ah # size_>
    endm
    __count_impl macro size_
      exitm <ValidElements = 0Ah # size_>
    endm
  else
    __cap_impl macro size_
      exitm <WritableElements = # size_>
    endm
    __bytecap_impl macro size_
      exitm <WritableBytes = # size_>
    endm
    __bytecount_impl macro size_
      exitm <ValidBytes = # size_>
    endm
    __count_impl macro size_
      exitm <ValidElements = # size_>
    endm
  endif
  __cap_c_impl macro size_
    exitm <WritableElementsConst = size_>
  endm
  __cap_c_one_notref_impl equ WritableElementsConst = 1, Notref = 1
  __cap_for_impl macro param
    exitm <WritableElementsLength = # param>
  endm
  __cap_x_impl macro size_
    exitm <WritableElements = 0Ah,"@" # size_>
  endm
  __bytecap_c_impl macro size_
    exitm <WritableBytesConst = size_>
  endm
  __bytecap_x_impl macro size_
    exitm <WritableBytes = 0Ah,"@" # size_>
  endm
  __mult_impl macro mult, size_
    exitm <__cap_impl((mult) * (size_))>
  endm
  __count_c_impl macro size_
    exitm <ValidElementsConst = size_>
  endm
  __count_x_impl macro size_
    exitm <ValidElements = 0Ah,"@" # size_>
  endm
  __bytecount_c_impl macro size_
    exitm <ValidBytesConst = size_>
  endm
  __bytecount_x_impl macro size_
    exitm <ValidBytes = 0Ah,"@" # size_>
  endm
  _At_impl_ macro target, annos
    exitm <[ SAL_at (p1 = # target) ] _Group_(annos)>
  endm
  _At_buffer_impl_ macro target, iter, bound_, annos
    exitm <[ SAL_at_buffer (p1 = # target, p2 = # iter, p3 = # bound_) ] _Group_(annos)>
  endm
  _When_impl_ macro expr, annos
    exitm <[ SAL_when (p1 = # expr) ] _Group_(annos)>
  endm
  _Group_impl_ macro annos
    exitm <[ SAL_begin ] annos [ SAL_end ]>
  endm
  _GrouP_impl_ macro annos
    exitm <[ SAL_BEGIN ] annos [ SAL_END ]>
  endm
  _Use_decl_anno_impl_ equ <_SA_annotes0(SAL_useHeader)>
  _Pre1_impl_ macro p1
    exitm <[ SA_Pre (p1) ]>
  endm
  _Pre2_impl_ macro p1, p2
    exitm <[ SA_Pre (p1, p2) ]>
  endm
  _Pre3_impl_ macro p1, p2, p3
    exitm <[ SA_Pre (p1, p2, p3) ]>
  endm
  _Post1_impl_ macro p1
    exitm <[ SA_Post (p1) ]>
  endm
  _Post2_impl_ macro p1, p2
    exitm <[ SA_Post (p1, p2) ]>
  endm
  _Post3_impl_ macro p1, p2, p3
    exitm <[ SA_Post (p1, p2, p3) ]>
  endm
  _Ret1_impl_ macro p1
    exitm <[ SA_Post (p1) ]>
  endm
  _Ret2_impl_ macro p1, p2
    exitm <[ SA_Post (p1, p2) ]>
  endm
  _Ret3_impl_ macro p1, p2, p3
    exitm <[ SA_Post (p1, p2, p3) ]>
  endm
  _Deref_pre1_impl_ macro p1
    exitm <[ SA_Pre (Deref = 1, p1) ]>
  endm
  _Deref_pre2_impl_ macro p1, p2
    exitm <[ SA_Pre (Deref = 1, p1, p2) ]>
  endm
  _Deref_pre3_impl_ macro p1, p2, p3
    exitm <[ SA_Pre (Deref = 1, p1, p2, p3) ]>
  endm
  _Deref_post1_impl_ macro p1
    exitm <[ SA_Post (Deref = 1, p1) ]>
  endm
  _Deref_post2_impl_ macro p1, p2
    exitm <[ SA_Post (Deref = 1, p1, p2) ]>
  endm
  _Deref_post3_impl_ macro p1, p2, p3
    exitm <[ SA_Post (Deref = 1, p1, p2, p3) ]>
  endm
  _Deref_ret1_impl_ macro p1
    exitm <[ SA_Post (Deref = 1, p1) ]>
  endm
  _Deref_ret2_impl_ macro p1, p2
    exitm <[ SA_Post (Deref = 1, p1, p2) ]>
  endm
  _Deref_ret3_impl_ macro p1, p2, p3
    exitm <[ SA_Post (Deref = 1, p1, p2, p3) ]>
  endm
  _Deref2_pre1_impl_ macro p1
    exitm <[ SA_Pre (Deref = 2, Notref = 1, p1) ]>
  endm
  _Deref2_post1_impl_ macro p1
    exitm <[ SA_Post (Deref = 2, Notref = 1, p1) ]>
  endm
  _Deref2_ret1_impl_ macro p1
    exitm <[ SA_Post (Deref = 2, Notref = 1, p1) ]>
  endm
  __inner_typefix macro ctype
    exitm <[ SAL_typefix (p1 = _SA_SPECSTRIZE(ctype)) ]>
  endm
  __inner_exceptthat equ <[ SAL_except ]>
elseif _USE_DECLSPECS_FOR_SAL
  _Check_return_impl_ equ <__post _SA_annotes0(SAL_checkReturn)>
  _Success_impl_ macro expr
    exitm <_SA_annotes1(SAL_success, expr)>
  endm
  _On_failure_impl_ macro annos
    exitm <_SA_annotes1(SAL_context, SAL_failed) _Group_(_Post_impl_ _Group_(_SAL_nop_impl_ annos))>
  endm
  _Printf_format_string_impl_ equ <_SA_annotes1(SAL_IsFormatString, "printf")>
  _Scanf_format_string_impl_ equ <_SA_annotes1(SAL_IsFormatString, "scanf")>
  _Scanf_s_format_string_impl_ equ <_SA_annotes1(SAL_IsFormatString, "scanf_s")>
  _In_bound_impl_ equ <_Pre_impl_ _Bound_impl_>
  _Out_bound_impl_ equ <_Post_impl_ _Bound_impl_>
  _Ret_bound_impl_ equ <_Post_impl_ _Bound_impl_>
  _Deref_in_bound_impl_ equ <_Deref_pre_impl_ _Bound_impl_>
  _Deref_out_bound_impl_ equ <_Deref_post_impl_ _Bound_impl_>
  _Deref_ret_bound_impl_ equ <_Deref_post_impl_ _Bound_impl_>
  __null_impl equ <_SA_annotes0(SAL_null)>
  __notnull_impl equ <_SA_annotes0(SAL_notnull)>
  __maybenull_impl equ <_SA_annotes0(SAL_maybenull)>
  __valid_impl equ <_SA_annotes0(SAL_valid)>
  __notvalid_impl equ <_SA_annotes0(SAL_notvalid)>
  __maybevalid_impl equ <_SA_annotes0(SAL_maybevalid)>
  __null_impl_notref equ <_Notref_ _Null_impl_>
  __maybenull_impl_notref equ <_Notref_ _Maybenull_impl_>
  __notnull_impl_notref equ <_Notref_ _Notnull_impl_>
  __zterm_impl equ <_SA_annotes1(SAL_nullTerminated, __yes)>
  __maybezterm_impl equ <_SA_annotes1(SAL_nullTerminated, __maybe)>
  __maybzterm_impl equ <_SA_annotes1(SAL_nullTerminated, __maybe)>
  __notzterm_impl equ <_SA_annotes1(SAL_nullTerminated, __no)>
  __readaccess_impl equ _SA_annotes1(SAL_access, 1h)
  __writeaccess_impl equ _SA_annotes1(SAL_access, 2h)
  __allaccess_impl equ _SA_annotes1(SAL_access, 3h)
  __readaccess_impl_notref equ _Notref_ _SA_annotes1(SAL_access, 1h)
  __writeaccess_impl_notref equ _Notref_ _SA_annotes1(SAL_access, 2h)
  __allaccess_impl_notref equ _Notref_ _SA_annotes1(SAL_access, 3h)
  __cap_impl macro size_
    exitm <_SA_annotes1(SAL_writableTo, elementCount (size_))>
  endm
  __cap_c_impl macro size_
    exitm <_SA_annotes1(SAL_writableTo, elementCount (size_))>
  endm
  __cap_c_one_notref_impl equ _Notref_ _SA_annotes1(SAL_writableTo, elementCount (1))
  __cap_for_impl macro param
    exitm <_SA_annotes1(SAL_writableTo, inexpressibleCount (sizeof(param)))>
  endm
  __cap_x_impl macro size_
    exitm <_SA_annotes1(SAL_writableTo, inexpressibleCount (# size_))>
  endm
  __bytecap_impl macro size_
    exitm <_SA_annotes1(SAL_writableTo, byteCount (size_))>
  endm
  __bytecap_c_impl macro size_
    exitm <_SA_annotes1(SAL_writableTo, byteCount (size_))>
  endm
  __bytecap_x_impl macro size_
    exitm <_SA_annotes1(SAL_writableTo, inexpressibleCount (# size_))>
  endm
  __mult_impl macro mult, size_
    exitm <_SA_annotes1(SAL_writableTo, (mult) * (size_))>
  endm
  __count_impl macro size_
    exitm <_SA_annotes1(SAL_readableTo, elementCount (size_))>
  endm
  __count_c_impl macro size_
    exitm <_SA_annotes1(SAL_readableTo, elementCount (size_))>
  endm
  __count_x_impl macro size_
    exitm <_SA_annotes1(SAL_readableTo, inexpressibleCount (# size_))>
  endm
  __bytecount_impl macro size_
    exitm <_SA_annotes1(SAL_readableTo, byteCount (size_))>
  endm
  __bytecount_c_impl macro size_
    exitm <_SA_annotes1(SAL_readableTo, byteCount (size_))>
  endm
  __bytecount_x_impl macro size_
    exitm <_SA_annotes1(SAL_readableTo, inexpressibleCount (# size_))>
  endm
  _At_impl_ macro target, annos
    exitm <_SA_annotes0(SAL_at (target)) _Group_(annos)>
  endm
  _At_buffer_impl_ macro target, iter, bound_, annos
    exitm <_SA_annotes3(SAL_at_buffer, target, iter, bound_) _Group_(annos)>
  endm
  _Group_impl_ macro annos
    exitm <_SA_annotes0(SAL_begin) annos _SA_annotes0(SAL_end)>
  endm
  _GrouP_impl_ macro annos
    exitm <_SA_annotes0(SAL_BEGIN) annos _SA_annotes0(SAL_END)>
  endm
  _When_impl_ macro expr, annos
    exitm <_SA_annotes0(SAL_when (expr)) _Group_(annos)>
  endm
  _Use_decl_anno_impl_ equ <__declspec("SAL_useHeader()")>
  _Pre1_impl_ macro p1
    exitm <_Pre_impl_ p1>
  endm
  _Pre2_impl_ macro p1, p2
    exitm <_Pre_impl_ p1 _Pre_impl_ p2>
  endm
  _Pre3_impl_ macro p1, p2, p3
    exitm <_Pre_impl_ p1 _Pre_impl_ p2 _Pre_impl_ p3>
  endm
  _Post1_impl_ macro p1
    exitm <_Post_impl_ p1>
  endm
  _Post2_impl_ macro p1, p2
    exitm <_Post_impl_ p1 _Post_impl_ p2>
  endm
  _Post3_impl_ macro p1, p2, p3
    exitm <_Post_impl_ p1 _Post_impl_ p2 _Post_impl_ p3>
  endm
  _Ret1_impl_ macro p1
    exitm <_Post_impl_ p1>
  endm
  _Ret2_impl_ macro p1, p2
    exitm <_Post_impl_ p1 _Post_impl_ p2>
  endm
  _Ret3_impl_ macro p1, p2, p3
    exitm <_Post_impl_ p1 _Post_impl_ p2 _Post_impl_ p3>
  endm
  _Deref_pre1_impl_ macro p1
    exitm <_Deref_pre_impl_ p1>
  endm
  _Deref_pre2_impl_ macro p1, p2
    exitm <_Deref_pre_impl_ p1 _Deref_pre_impl_ p2>
  endm
  _Deref_pre3_impl_ macro p1, p2, p3
    exitm <_Deref_pre_impl_ p1 _Deref_pre_impl_ p2 _Deref_pre_impl_ p3>
  endm
  _Deref_post1_impl_ macro p1
    exitm <_Deref_post_impl_ p1>
  endm
  _Deref_post2_impl_ macro p1, p2
    exitm <_Deref_post_impl_ p1 _Deref_post_impl_ p2>
  endm
  _Deref_post3_impl_ macro p1, p2, p3
    exitm <_Deref_post_impl_ p1 _Deref_post_impl_ p2 _Deref_post_impl_ p3>
  endm
  _Deref_ret1_impl_ macro p1
    exitm <_Deref_post_impl_ p1>
  endm
  _Deref_ret2_impl_ macro p1, p2
    exitm <_Deref_post_impl_ p1 _Deref_post_impl_ p2>
  endm
  _Deref_ret3_impl_ macro p1, p2, p3
    exitm <_Deref_post_impl_ p1 _Deref_post_impl_ p2 _Deref_post_impl_ p3>
  endm
  _Deref2_pre1_impl_ macro p1
    exitm <_Deref_pre_impl_ _Notref_impl_ _Deref_impl_ p1>
  endm
  _Deref2_post1_impl_ macro p1
    exitm <_Deref_post_impl_ _Notref_impl_ _Deref_impl_ p1>
  endm
  _Deref2_ret1_impl_ macro p1
    exitm <_Deref_post_impl_ _Notref_impl_ _Deref_impl_ p1>
  endm
  __inner_typefix macro ctype
    exitm <_SA_annotes1(SAL_typefix, ctype)>
  endm
  __inner_exceptthat equ <_SA_annotes0(SAL_except)>
elseif Defined(_MSC_EXTENSIONS) and  not Defined(MIDL_PASS) and  not Defined(__midl) and  not Defined(RC_INVOKED) and Defined(_PFT_VER) and _MSC_VER ge 1400
  ifdef __cplusplus
    ;[...]
  else
    SA macro id
      exitm <SA_ ## id>
    endm
    REPEATABLE equ <>
  endif
  source_annotation_attribute proto WIN_STD_CALL_CONV :SA
  __P_impl struct
    ifdef __cplusplus
      ;[...]
    endif
    __d_ SDWORD ?
  __P_impl ends

  ;__P_impl typedef __P_impl
  
  source_annotation_attribute proto WIN_STD_CALL_CONV :SA
  __R_impl struct
    ifdef __cplusplus
      ;[...]
    endif
    __d_ SDWORD ?
  __R_impl ends

  ;__R_impl typedef __R_impl
  
  source_annotation_attribute proto WIN_STD_CALL_CONV :SA
  __M_ struct
    ifdef __cplusplus
      ;[...]
    endif
    __d_ SDWORD ?
  __M_ ends

  ;__M_ typedef __M_
  
  source_annotation_attribute proto WIN_STD_CALL_CONV :SA
  __A_ struct
    ifdef __cplusplus
      ;[...]
    endif
    __d_ SDWORD ?
  __A_ ends

  ;__A_ typedef __A_
  
  source_annotation_attribute proto WIN_STD_CALL_CONV :SA
  __F_ struct
    ifdef __cplusplus
      ;[...]
    endif
    __d_ SDWORD ?
  __F_ ends

  ;__F_ typedef __F_
  
  _SAL_nop_impl_ equ <>
  _At_impl_ macro target, annos
    exitm <[ __A_ (__d_ = 0) ]>
  endm
  _At_buffer_impl_ macro target, iter, bound_, annos
    exitm <[ __A_ (__d_ = 0) ]>
  endm
  _When_impl_ macro expr, annos
    exitm <annos>
  endm
  _Group_impl_ macro annos
    exitm <annos>
  endm
  _GrouP_impl_ macro annos
    exitm <annos>
  endm
  _Use_decl_anno_impl_ equ [ __M_ (__d_ = 0) ]
  _Points_to_data_impl_ equ [ __P_impl (__d_ = 0) ]
  _Literal_impl_ equ [ __P_impl (__d_ = 0) ]
  _Notliteral_impl_ equ [ __P_impl (__d_ = 0) ]
  _Pre_valid_impl_ equ [ __P_impl (__d_ = 0) ]
  _Post_valid_impl_ equ [ __P_impl (__d_ = 0) ]
  _Ret_valid_impl_ equ [ __R_impl (__d_ = 0) ]
  _Check_return_impl_ equ [ __R_impl (__d_ = 0) ]
  _Must_inspect_impl_ equ [ __R_impl (__d_ = 0) ]
  _Success_impl_ macro expr
    exitm <[ __M_ (__d_ = 0) ]>
  endm
  _On_failure_impl_ macro expr
    exitm <[ __M_ (__d_ = 0) ]>
  endm
  _Always_impl_ macro expr
    exitm <[ __M_ (__d_ = 0) ]>
  endm
  _Printf_format_string_impl_ equ [ __P_impl (__d_ = 0) ]
  _Scanf_format_string_impl_ equ [ __P_impl (__d_ = 0) ]
  _Scanf_s_format_string_impl_ equ [ __P_impl (__d_ = 0) ]
  _Raises_SEH_exception_impl_ equ [ __M_ (__d_ = 0) ]
  _Maybe_raises_SEH_exception_impl_ equ [ __M_ (__d_ = 0) ]
  _In_bound_impl_ equ [ __P_impl (__d_ = 0) ]
  _Out_bound_impl_ equ [ __P_impl (__d_ = 0) ]
  _Ret_bound_impl_ equ [ __R_impl (__d_ = 0) ]
  _Deref_in_bound_impl_ equ [ __P_impl (__d_ = 0) ]
  _Deref_out_bound_impl_ equ [ __P_impl (__d_ = 0) ]
  _Deref_ret_bound_impl_ equ [ __R_impl (__d_ = 0) ]
  _Range_impl_ macro min, max
    exitm <[ __P_impl (__d_ = 0) ]>
  endm
  _In_range_impl_ macro min, max
    exitm <[ __P_impl (__d_ = 0) ]>
  endm
  _Out_range_impl_ macro min, max
    exitm <[ __P_impl (__d_ = 0) ]>
  endm
  _Ret_range_impl_ macro min, max
    exitm <[ __R_impl (__d_ = 0) ]>
  endm
  _Deref_in_range_impl_ macro min, max
    exitm <[ __P_impl (__d_ = 0) ]>
  endm
  _Deref_out_range_impl_ macro min, max
    exitm <[ __P_impl (__d_ = 0) ]>
  endm
  _Deref_ret_range_impl_ macro min, max
    exitm <[ __R_impl (__d_ = 0) ]>
  endm
  _Field_range_impl_ macro min, max
    exitm <[ __F_ (__d_ = 0) ]>
  endm
  _Pre_satisfies_impl_ macro cond
    exitm <[ __A_ (__d_ = 0) ]>
  endm
  _Post_satisfies_impl_ macro cond
    exitm <[ __A_ (__d_ = 0) ]>
  endm
  _Satisfies_impl_ macro cond
    exitm <[ __A_ (__d_ = 0) ]>
  endm
  _Null_impl_ equ [ __A_ (__d_ = 0) ]
  _Notnull_impl_ equ [ __A_ (__d_ = 0) ]
  _Maybenull_impl_ equ [ __A_ (__d_ = 0) ]
  _Valid_impl_ equ [ __A_ (__d_ = 0) ]
  _Notvalid_impl_ equ [ __A_ (__d_ = 0) ]
  _Maybevalid_impl_ equ [ __A_ (__d_ = 0) ]
  _Readable_bytes_impl_ macro size_
    exitm <[ __A_ (__d_ = 0) ]>
  endm
  _Readable_elements_impl_ macro size_
    exitm <[ __A_ (__d_ = 0) ]>
  endm
  _Writable_bytes_impl_ macro size_
    exitm <[ __A_ (__d_ = 0) ]>
  endm
  _Writable_elements_impl_ macro size_
    exitm <[ __A_ (__d_ = 0) ]>
  endm
  _Null_terminated_impl_ equ [ __A_ (__d_ = 0) ]
  _NullNull_terminated_impl_ equ [ __A_ (__d_ = 0) ]
  _Pre_impl_ equ [ __P_impl (__d_ = 0) ]
  _Pre1_impl_ macro p1
    exitm <[ __P_impl (__d_ = 0) ]>
  endm
  _Pre2_impl_ macro p1, p2
    exitm <[ __P_impl (__d_ = 0) ]>
  endm
  _Pre3_impl_ macro p1, p2, p3
    exitm <[ __P_impl (__d_ = 0) ]>
  endm
  _Post_impl_ equ [ __P_impl (__d_ = 0) ]
  _Post1_impl_ macro p1
    exitm <[ __P_impl (__d_ = 0) ]>
  endm
  _Post2_impl_ macro p1, p2
    exitm <[ __P_impl (__d_ = 0) ]>
  endm
  _Post3_impl_ macro p1, p2, p3
    exitm <[ __P_impl (__d_ = 0) ]>
  endm
  _Ret1_impl_ macro p1
    exitm <[ __R_impl (__d_ = 0) ]>
  endm
  _Ret2_impl_ macro p1, p2
    exitm <[ __R_impl (__d_ = 0) ]>
  endm
  _Ret3_impl_ macro p1, p2, p3
    exitm <[ __R_impl (__d_ = 0) ]>
  endm
  _Deref_pre1_impl_ macro p1
    exitm <[ __P_impl (__d_ = 0) ]>
  endm
  _Deref_pre2_impl_ macro p1, p2
    exitm <[ __P_impl (__d_ = 0) ]>
  endm
  _Deref_pre3_impl_ macro p1, p2, p3
    exitm <[ __P_impl (__d_ = 0) ]>
  endm
  _Deref_post1_impl_ macro p1
    exitm <[ __P_impl (__d_ = 0) ]>
  endm
  _Deref_post2_impl_ macro p1, p2
    exitm <[ __P_impl (__d_ = 0) ]>
  endm
  _Deref_post3_impl_ macro p1, p2, p3
    exitm <[ __P_impl (__d_ = 0) ]>
  endm
  _Deref_ret1_impl_ macro p1
    exitm <[ __R_impl (__d_ = 0) ]>
  endm
  _Deref_ret2_impl_ macro p1, p2
    exitm <[ __R_impl (__d_ = 0) ]>
  endm
  _Deref_ret3_impl_ macro p1, p2, p3
    exitm <[ __R_impl (__d_ = 0) ]>
  endm
  _Deref2_pre1_impl_ macro p1
    exitm <>
  endm
  _Deref2_post1_impl_ macro p1
    exitm <>
  endm
  _Deref2_ret1_impl_ macro p1
    exitm <>
  endm
else
  _SAL_nop_impl_ equ <X>
  _At_impl_ macro target, annos
    exitm <>
  endm
  _When_impl_ macro expr, annos
    exitm <>
  endm
  _Group_impl_ macro annos
    exitm <>
  endm
  _GrouP_impl_ macro annos
    exitm <>
  endm
  _At_buffer_impl_ macro target, iter, bound_, annos
    exitm <>
  endm
  _Use_decl_anno_impl_ equ <>
  _Points_to_data_impl_ equ <>
  _Literal_impl_ equ <>
  _Notliteral_impl_ equ <>
  _Notref_impl_ equ <>
  _Pre_valid_impl_ equ <>
  _Post_valid_impl_ equ <>
  _Ret_valid_impl_ equ <>
  _Check_return_impl_ equ <>
  _Must_inspect_impl_ equ <>
  _Success_impl_ macro expr
    exitm <>
  endm
  _On_failure_impl_ macro annos
    exitm <>
  endm
  _Always_impl_ macro annos
    exitm <>
  endm
  _Printf_format_string_impl_ equ <>
  _Scanf_format_string_impl_ equ <>
  _Scanf_s_format_string_impl_ equ <>
  _In_bound_impl_ equ <>
  _Out_bound_impl_ equ <>
  _Ret_bound_impl_ equ <>
  _Deref_in_bound_impl_ equ <>
  _Deref_out_bound_impl_ equ <>
  _Deref_ret_bound_impl_ equ <>
  _Range_impl_ macro min, max
    exitm <>
  endm
  _In_range_impl_ macro min, max
    exitm <>
  endm
  _Out_range_impl_ macro min, max
    exitm <>
  endm
  _Ret_range_impl_ macro min, max
    exitm <>
  endm
  _Deref_in_range_impl_ macro min, max
    exitm <>
  endm
  _Deref_out_range_impl_ macro min, max
    exitm <>
  endm
  _Deref_ret_range_impl_ macro min, max
    exitm <>
  endm
  _Satisfies_impl_ macro expr
    exitm <>
  endm
  _Pre_satisfies_impl_ macro expr
    exitm <>
  endm
  _Post_satisfies_impl_ macro expr
    exitm <>
  endm
  _Null_impl_ equ <>
  _Notnull_impl_ equ <>
  _Maybenull_impl_ equ <>
  _Valid_impl_ equ <>
  _Notvalid_impl_ equ <>
  _Maybevalid_impl_ equ <>
  _Field_range_impl_ macro min, max
    exitm <>
  endm
  _Pre_impl_ equ <>
  _Pre1_impl_ macro p1
    exitm <>
  endm
  _Pre2_impl_ macro p1, p2
    exitm <>
  endm
  _Pre3_impl_ macro p1, p2, p3
    exitm <>
  endm
  _Post_impl_ equ <>
  _Post1_impl_ macro p1
    exitm <>
  endm
  _Post2_impl_ macro p1, p2
    exitm <>
  endm
  _Post3_impl_ macro p1, p2, p3
    exitm <>
  endm
  _Ret1_impl_ macro p1
    exitm <>
  endm
  _Ret2_impl_ macro p1, p2
    exitm <>
  endm
  _Ret3_impl_ macro p1, p2, p3
    exitm <>
  endm
  _Deref_pre1_impl_ macro p1
    exitm <>
  endm
  _Deref_pre2_impl_ macro p1, p2
    exitm <>
  endm
  _Deref_pre3_impl_ macro p1, p2, p3
    exitm <>
  endm
  _Deref_post1_impl_ macro p1
    exitm <>
  endm
  _Deref_post2_impl_ macro p1, p2
    exitm <>
  endm
  _Deref_post3_impl_ macro p1, p2, p3
    exitm <>
  endm
  _Deref_ret1_impl_ macro p1
    exitm <>
  endm
  _Deref_ret2_impl_ macro p1, p2
    exitm <>
  endm
  _Deref_ret3_impl_ macro p1, p2, p3
    exitm <>
  endm
  _Deref2_pre1_impl_ macro p1
    exitm <>
  endm
  _Deref2_post1_impl_ macro p1
    exitm <>
  endm
  _Deref2_ret1_impl_ macro p1
    exitm <>
  endm
  _Readable_bytes_impl_ macro size_
    exitm <>
  endm
  _Readable_elements_impl_ macro size_
    exitm <>
  endm
  _Writable_bytes_impl_ macro size_
    exitm <>
  endm
  _Writable_elements_impl_ macro size_
    exitm <>
  endm
  _Null_terminated_impl_ equ <>
  _NullNull_terminated_impl_ equ <>
  __inner_typefix macro ctype
    exitm <>
  endm
  __inner_exceptthat equ <>
endif
__specstrings equ <>
ifdef __cplusplus
  ;[...]
else
  ifndef __nothrow
    __nothrow equ <>
  endif
endif
if  not Defined(__midl) and Defined(_PREFAST_)
  ;[...]
else
  __null equ <>
  __notnull equ <>
  __maybenull equ <>
  __readonly equ <>
  __notreadonly equ <>
  __maybereadonly equ <>
  __valid equ <>
  __notvalid equ <>
  __maybevalid equ <>
  __readableTo macro extent
    exitm <>
  endm
  __elem_readableTo macro size_
    exitm <>
  endm
  __byte_readableTo macro size_
    exitm <>
  endm
  __writableTo macro size_
    exitm <>
  endm
  __elem_writableTo macro size_
    exitm <>
  endm
  __byte_writableTo macro size_
    exitm <>
  endm
  __deref equ <>
  __pre equ <>
  __post equ <>
  __precond macro expr
    exitm <>
  endm
  __postcond macro expr
    exitm <>
  endm
  __exceptthat equ <>
  __inner_override equ <>
  __inner_callback equ <>
  __inner_blocksOn macro resource
    exitm <>
  endm
  __inner_fallthrough_dec equ <>
  __inner_fallthrough equ <>
  __refparam equ <>
  __inner_control_entrypoint macro category
    exitm <>
  endm
  __inner_data_entrypoint macro category
    exitm <>
  endm
  __post_except_maybenull equ <>
  __pre_except_maybenull equ <>
  __post_deref_except_maybenull equ <>
  __pre_deref_except_maybenull equ <>
  __inexpressible_readableTo macro size_
    exitm <>
  endm
  __inexpressible_writableTo macro size_
    exitm <>
  endm
endif
__ecount macro size_
  exitm <_SAL1_Source_(__ecount, (size_), __notnull __elem_writableTo(size_))>
endm
__bcount macro size_
  exitm <_SAL1_Source_(__bcount, (size_), __notnull __byte_writableTo(size_))>
endm
__in equ <_SAL1_Source_(__in,, _In_)>
__in_ecount macro size_
  exitm <_SAL1_Source_(__in_ecount, (size_), _In_reads_(size_))>
endm
__in_bcount macro size_
  exitm <_SAL1_Source_(__in_bcount, (size_), _In_reads_bytes_(size_))>
endm
__in_z equ <_SAL1_Source_(__in_z,, _In_z_)>
__in_ecount_z macro size_
  exitm <_SAL1_Source_(__in_ecount_z, (size_), _In_reads_z_(size_))>
endm
__in_bcount_z macro size_
  exitm <_SAL1_Source_(__in_bcount_z, (size_), __in_bcount(size_) __pre __nullterminated)>
endm
__in_nz equ <_SAL1_Source_(__in_nz,, __in)>
__in_ecount_nz macro size_
  exitm <_SAL1_Source_(__in_ecount_nz, (size_), __in_ecount(size_))>
endm
__in_bcount_nz macro size_
  exitm <_SAL1_Source_(__in_bcount_nz, (size_), __in_bcount(size_))>
endm
__out equ <_SAL1_Source_(__out,, _Out_)>
__out_ecount macro size_
  exitm <_SAL1_Source_(__out_ecount, (size_), _Out_writes_(size_))>
endm
__out_bcount macro size_
  exitm <_SAL1_Source_(__out_bcount, (size_), _Out_writes_bytes_(size_))>
endm
__out_ecount_part macro size_, length_
  exitm <_SAL1_Source_(__out_ecount_part, (size_, length_), _Out_writes_to_(size_, length_))>
endm
__out_bcount_part macro size_, length_
  exitm <_SAL1_Source_(__out_bcount_part, (size_, length_), _Out_writes_bytes_to_(size_, length_))>
endm
__out_ecount_full macro size_
  exitm <_SAL1_Source_(__out_ecount_full, (size_), _Out_writes_all_(size_))>
endm
__out_bcount_full macro size_
  exitm <_SAL1_Source_(__out_bcount_full, (size_), _Out_writes_bytes_all_(size_))>
endm
__out_z equ <_SAL1_Source_(__out_z,, __post __valid __refparam __post __nullterminated)>
__out_z_opt equ <_SAL1_Source_(__out_z_opt,, __post __valid __refparam __post __nullterminated __pre_except_maybenull)>
__out_ecount_z macro size_
  exitm <_SAL1_Source_(__out_ecount_z, (size_), __ecount(size_) __post __valid __refparam __post __nullterminated)>
endm
__out_bcount_z macro size_
  exitm <_SAL1_Source_(__out_bcount_z, (size_), __bcount(size_) __post __valid __refparam __post __nullterminated)>
endm
__out_ecount_part_z macro size_, length_
  exitm <_SAL1_Source_(__out_ecount_part_z, (size_, length_), __out_ecount_part(size_, length_) __post __nullterminated)>
endm
__out_bcount_part_z macro size_, length_
  exitm <_SAL1_Source_(__out_bcount_part_z, (size_, length_), __out_bcount_part(size_, length_) __post __nullterminated)>
endm
__out_ecount_full_z macro size_
  exitm <_SAL1_Source_(__out_ecount_full_z, (size_), __out_ecount_full(size_) __post __nullterminated)>
endm
__out_bcount_full_z macro size_
  exitm <_SAL1_Source_(__out_bcount_full_z, (size_), __out_bcount_full(size_) __post __nullterminated)>
endm
__out_nz equ <_SAL1_Source_(__out_nz,, __post __valid __refparam)>
__out_nz_opt equ <_SAL1_Source_(__out_nz_opt,, __post __valid __refparam __post_except_maybenull_)>
__out_ecount_nz macro size_
  exitm <_SAL1_Source_(__out_ecount_nz, (size_), __ecount(size_) __post __valid __refparam)>
endm
__out_bcount_nz macro size_
  exitm <_SAL1_Source_(__out_bcount_nz, (size_), __bcount(size_) __post __valid __refparam)>
endm
__inout equ <_SAL1_Source_(__inout,, _Inout_)>
__inout_ecount macro size_
  exitm <_SAL1_Source_(__inout_ecount, (size_), _Inout_updates_(size_))>
endm
__inout_bcount macro size_
  exitm <_SAL1_Source_(__inout_bcount, (size_), _Inout_updates_bytes_(size_))>
endm
__inout_ecount_part macro size_, length_
  exitm <_SAL1_Source_(__inout_ecount_part, (size_, length_), _Inout_updates_to_(size_, length_))>
endm
__inout_bcount_part macro size_, length_
  exitm <_SAL1_Source_(__inout_bcount_part, (size_, length_), _Inout_updates_bytes_to_(size_, length_))>
endm
__inout_ecount_full macro size_
  exitm <_SAL1_Source_(__inout_ecount_full, (size_), _Inout_updates_all_(size_))>
endm
__inout_bcount_full macro size_
  exitm <_SAL1_Source_(__inout_bcount_full, (size_), _Inout_updates_bytes_all_(size_))>
endm
__inout_z equ <_SAL1_Source_(__inout_z,, _Inout_z_)>
__inout_ecount_z macro size_
  exitm <_SAL1_Source_(__inout_ecount_z, (size_), _Inout_updates_z_(size_))>
endm
__inout_bcount_z macro size_
  exitm <_SAL1_Source_(__inout_bcount_z, (size_), __inout_bcount(size_) __pre __nullterminated __post __nullterminated)>
endm
__inout_nz equ <_SAL1_Source_(__inout_nz,, __inout)>
__inout_ecount_nz macro size_
  exitm <_SAL1_Source_(__inout_ecount_nz, (size_), __inout_ecount(size_))>
endm
__inout_bcount_nz macro size_
  exitm <_SAL1_Source_(__inout_bcount_nz, (size_), __inout_bcount(size_))>
endm
__ecount_opt macro size_
  exitm <_SAL1_Source_(__ecount_opt, (size_), __ecount(size_) __pre_except_maybenull)>
endm
__bcount_opt macro size_
  exitm <_SAL1_Source_(__bcount_opt, (size_), __bcount(size_) __pre_except_maybenull)>
endm
__in_opt equ <_SAL1_Source_(__in_opt,, _In_opt_)>
__in_ecount_opt macro size_
  exitm <_SAL1_Source_(__in_ecount_opt, (size_), _In_reads_opt_(size_))>
endm
__in_bcount_opt macro size_
  exitm <_SAL1_Source_(__in_bcount_opt, (size_), _In_reads_bytes_opt_(size_))>
endm
__in_z_opt equ <_SAL1_Source_(__in_z_opt,, _In_opt_z_)>
__in_ecount_z_opt macro size_
  exitm <_SAL1_Source_(__in_ecount_z_opt, (size_), __in_ecount_opt(size_) __pre __nullterminated)>
endm
__in_bcount_z_opt macro size_
  exitm <_SAL1_Source_(__in_bcount_z_opt, (size_), __in_bcount_opt(size_) __pre __nullterminated)>
endm
__in_nz_opt equ <_SAL1_Source_(__in_nz_opt,, __in_opt)>
__in_ecount_nz_opt macro size_
  exitm <_SAL1_Source_(__in_ecount_nz_opt, (size_), __in_ecount_opt(size_))>
endm
__in_bcount_nz_opt macro size_
  exitm <_SAL1_Source_(__in_bcount_nz_opt, (size_), __in_bcount_opt(size_))>
endm
__out_opt equ <_SAL1_Source_(__out_opt,, _Out_opt_)>
__out_ecount_opt macro size_
  exitm <_SAL1_Source_(__out_ecount_opt, (size_), _Out_writes_opt_(size_))>
endm
__out_bcount_opt macro size_
  exitm <_SAL1_Source_(__out_bcount_opt, (size_), _Out_writes_bytes_opt_(size_))>
endm
__out_ecount_part_opt macro size_, length_
  exitm <_SAL1_Source_(__out_ecount_part_opt, (size_, length_), __out_ecount_part(size_, length_) __pre_except_maybenull)>
endm
__out_bcount_part_opt macro size_, length_
  exitm <_SAL1_Source_(__out_bcount_part_opt, (size_, length_), __out_bcount_part(size_, length_) __pre_except_maybenull)>
endm
__out_ecount_full_opt macro size_
  exitm <_SAL1_Source_(__out_ecount_full_opt, (size_), __out_ecount_full(size_) __pre_except_maybenull)>
endm
__out_bcount_full_opt macro size_
  exitm <_SAL1_Source_(__out_bcount_full_opt, (size_), __out_bcount_full(size_) __pre_except_maybenull)>
endm
__out_ecount_z_opt macro size_
  exitm <_SAL1_Source_(__out_ecount_z_opt, (size_), __out_ecount_opt(size_) __post __nullterminated)>
endm
__out_bcount_z_opt macro size_
  exitm <_SAL1_Source_(__out_bcount_z_opt, (size_), __out_bcount_opt(size_) __post __nullterminated)>
endm
__out_ecount_part_z_opt macro size_, length_
  exitm <_SAL1_Source_(__out_ecount_part_z_opt, (size_, length_), __out_ecount_part_opt(size_, length_) __post __nullterminated)>
endm
__out_bcount_part_z_opt macro size_, length_
  exitm <_SAL1_Source_(__out_bcount_part_z_opt, (size_, length_), __out_bcount_part_opt(size_, length_) __post __nullterminated)>
endm
__out_ecount_full_z_opt macro size_
  exitm <_SAL1_Source_(__out_ecount_full_z_opt, (size_), __out_ecount_full_opt(size_) __post __nullterminated)>
endm
__out_bcount_full_z_opt macro size_
  exitm <_SAL1_Source_(__out_bcount_full_z_opt, (size_), __out_bcount_full_opt(size_) __post __nullterminated)>
endm
__out_ecount_nz_opt macro size_
  exitm <_SAL1_Source_(__out_ecount_nz_opt, (size_), __out_ecount_opt(size_) __post __nullterminated)>
endm
__out_bcount_nz_opt macro size_
  exitm <_SAL1_Source_(__out_bcount_nz_opt, (size_), __out_bcount_opt(size_) __post __nullterminated)>
endm
__inout_opt equ <_SAL1_Source_(__inout_opt,, _Inout_opt_)>
__inout_ecount_opt macro size_
  exitm <_SAL1_Source_(__inout_ecount_opt, (size_), __inout_ecount(size_) __pre_except_maybenull)>
endm
__inout_bcount_opt macro size_
  exitm <_SAL1_Source_(__inout_bcount_opt, (size_), __inout_bcount(size_) __pre_except_maybenull)>
endm
__inout_ecount_part_opt macro size_, length_
  exitm <_SAL1_Source_(__inout_ecount_part_opt, (size_, length_), __inout_ecount_part(size_, length_) __pre_except_maybenull)>
endm
__inout_bcount_part_opt macro size_, length_
  exitm <_SAL1_Source_(__inout_bcount_part_opt, (size_, length_), __inout_bcount_part(size_, length_) __pre_except_maybenull)>
endm
__inout_ecount_full_opt macro size_
  exitm <_SAL1_Source_(__inout_ecount_full_opt, (size_), __inout_ecount_full(size_) __pre_except_maybenull)>
endm
__inout_bcount_full_opt macro size_
  exitm <_SAL1_Source_(__inout_bcount_full_opt, (size_), __inout_bcount_full(size_) __pre_except_maybenull)>
endm
__inout_z_opt equ <_SAL1_Source_(__inout_z_opt,, __inout_opt __pre __nullterminated __post __nullterminated)>
__inout_ecount_z_opt macro size_
  exitm <_SAL1_Source_(__inout_ecount_z_opt, (size_), __inout_ecount_opt(size_) __pre __nullterminated __post __nullterminated)>
endm
__inout_ecount_z_opt macro size_
  exitm <_SAL1_Source_(__inout_ecount_z_opt, (size_), __inout_ecount_opt(size_) __pre __nullterminated __post __nullterminated)>
endm
__inout_bcount_z_opt macro size_
  exitm <_SAL1_Source_(__inout_bcount_z_opt, (size_), __inout_bcount_opt(size_))>
endm
__inout_nz_opt equ <_SAL1_Source_(__inout_nz_opt,, __inout_opt)>
__inout_ecount_nz_opt macro size_
  exitm <_SAL1_Source_(__inout_ecount_nz_opt, (size_), __inout_ecount_opt(size_))>
endm
__inout_bcount_nz_opt macro size_
  exitm <_SAL1_Source_(__inout_bcount_nz_opt, (size_), __inout_bcount_opt(size_))>
endm
__deref_ecount macro size_
  exitm <_SAL1_Source_(__deref_ecount, (size_), _Notref_ __ecount 1 __post _Notref_ __elem_readableTo 1 __post _Notref_ __deref _Notref_ __notnull __post __deref __elem_writableTo(size_))>
endm
__deref_bcount macro size_
  exitm <_SAL1_Source_(__deref_bcount, (size_), _Notref_ __ecount 1 __post _Notref_ __elem_readableTo 1 __post _Notref_ __deref _Notref_ __notnull __post __deref __byte_writableTo(size_))>
endm
__deref_out equ <_SAL1_Source_(__deref_out,, _Outptr_)>
__deref_out_ecount macro size_
  exitm <_SAL1_Source_(__deref_out_ecount, (size_), _Outptr_result_buffer_(size_))>
endm
__deref_out_bcount macro size_
  exitm <_SAL1_Source_(__deref_out_bcount, (size_), _Outptr_result_bytebuffer_(size_))>
endm
__deref_out_ecount_part macro size_, length_
  exitm <_SAL1_Source_(__deref_out_ecount_part, (size_, length_), _Outptr_result_buffer_to_(size_, length_))>
endm
__deref_out_bcount_part macro size_, length_
  exitm <_SAL1_Source_(__deref_out_bcount_part, (size_, length_), _Outptr_result_bytebuffer_to_(size_, length_))>
endm
__deref_out_ecount_full macro size_
  exitm <_SAL1_Source_(__deref_out_ecount_full, (size_), __deref_out_ecount_part(size_, size_))>
endm
__deref_out_bcount_full macro size_
  exitm <_SAL1_Source_(__deref_out_bcount_full, (size_), __deref_out_bcount_part(size_, size_))>
endm
__deref_out_z equ <_SAL1_Source_(__deref_out_z,, _Outptr_result_z_)>
__deref_out_ecount_z macro size_
  exitm <_SAL1_Source_(__deref_out_ecount_z, (size_), __deref_out_ecount(size_) __post __deref __nullterminated)>
endm
__deref_out_bcount_z macro size_
  exitm <_SAL1_Source_(__deref_out_bcount_z, (size_), __deref_out_bcount(size_) __post __deref __nullterminated)>
endm
__deref_out_nz equ <_SAL1_Source_(__deref_out_nz,, __deref_out)>
__deref_out_ecount_nz macro size_
  exitm <_SAL1_Source_(__deref_out_ecount_nz, (size_), __deref_out_ecount(size_))>
endm
__deref_out_bcount_nz macro size_
  exitm <_SAL1_Source_(__deref_out_bcount_nz, (size_), __deref_out_ecount(size_))>
endm
__deref_inout equ _SAL1_Source_(__deref_inout,, _Notref_ __notnull _Notref_ __elem_readableTo1 __pre __deref __valid __post _Notref_ __deref __valid __refparam)
__deref_inout_z equ <_SAL1_Source_(__deref_inout_z,, __deref_inout __pre __deref __nullterminated __post _Notref_ __deref __nullterminated)>
__deref_inout_ecount macro size_
  exitm <_SAL1_Source_(__deref_inout_ecount, (size_), __deref_inout __pre __deref __elem_writableTo(size_) __post _Notref_ __deref __elem_writableTo(size_))>
endm
__deref_inout_bcount macro size_
  exitm <_SAL1_Source_(__deref_inout_bcount, (size_), __deref_inout __pre __deref __byte_writableTo(size_) __post _Notref_ __deref __byte_writableTo(size_))>
endm
__deref_inout_ecount_part macro size_, length_
  exitm <_SAL1_Source_(__deref_inout_ecount_part, (size_, length_), __deref_inout_ecount(size_) __pre __deref __elem_readableTo(length_) __post __deref __elem_readableTo(length_))>
endm
__deref_inout_bcount_part macro size_, length_
  exitm <_SAL1_Source_(__deref_inout_bcount_part, (size_, length_), __deref_inout_bcount(size_) __pre __deref __byte_readableTo(length_) __post __deref __byte_readableTo(length_))>
endm
__deref_inout_ecount_full macro size_
  exitm <_SAL1_Source_(__deref_inout_ecount_full, (size_), __deref_inout_ecount_part(size_, size_))>
endm
__deref_inout_bcount_full macro size_
  exitm <_SAL1_Source_(__deref_inout_bcount_full, (size_), __deref_inout_bcount_part(size_, size_))>
endm
__deref_inout_ecount_z macro size_
  exitm <_SAL1_Source_(__deref_inout_ecount_z, (size_), __deref_inout_ecount(size_) __pre __deref __nullterminated __post __deref __nullterminated)>
endm
__deref_inout_bcount_z macro size_
  exitm <_SAL1_Source_(__deref_inout_bcount_z, (size_), __deref_inout_bcount(size_) __pre __deref __nullterminated __post __deref __nullterminated)>
endm
__deref_inout_nz equ <_SAL1_Source_(__deref_inout_nz,, __deref_inout)>
__deref_inout_ecount_nz macro size_
  exitm <_SAL1_Source_(__deref_inout_ecount_nz, (size_), __deref_inout_ecount(size_))>
endm
__deref_inout_bcount_nz macro size_
  exitm <_SAL1_Source_(__deref_inout_bcount_nz, (size_), __deref_inout_ecount(size_))>
endm
__deref_ecount_opt macro size_
  exitm <_SAL1_Source_(__deref_ecount_opt, (size_), __deref_ecount(size_) __post_deref_except_maybenull)>
endm
__deref_bcount_opt macro size_
  exitm <_SAL1_Source_(__deref_bcount_opt, (size_), __deref_bcount(size_) __post_deref_except_maybenull)>
endm
__deref_out_opt equ <_SAL1_Source_(__deref_out_opt,, __deref_out __post_deref_except_maybenull)>
__deref_out_ecount_opt macro size_
  exitm <_SAL1_Source_(__deref_out_ecount_opt, (size_), __deref_out_ecount(size_) __post_deref_except_maybenull)>
endm
__deref_out_bcount_opt macro size_
  exitm <_SAL1_Source_(__deref_out_bcount_opt, (size_), __deref_out_bcount(size_) __post_deref_except_maybenull)>
endm
__deref_out_ecount_part_opt macro size_, length_
  exitm <_SAL1_Source_(__deref_out_ecount_part_opt, (size_, length_), __deref_out_ecount_part(size_, length_) __post_deref_except_maybenull)>
endm
__deref_out_bcount_part_opt macro size_, length_
  exitm <_SAL1_Source_(__deref_out_bcount_part_opt, (size_, length_), __deref_out_bcount_part(size_, length_) __post_deref_except_maybenull)>
endm
__deref_out_ecount_full_opt macro size_
  exitm <_SAL1_Source_(__deref_out_ecount_full_opt, (size_), __deref_out_ecount_full(size_) __post_deref_except_maybenull)>
endm
__deref_out_bcount_full_opt macro size_
  exitm <_SAL1_Source_(__deref_out_bcount_full_opt, (size_), __deref_out_bcount_full(size_) __post_deref_except_maybenull)>
endm
__deref_out_z_opt equ <_SAL1_Source_(__deref_out_z_opt,, _Outptr_result_maybenull_z_)>
__deref_out_ecount_z_opt macro size_
  exitm <_SAL1_Source_(__deref_out_ecount_z_opt, (size_), __deref_out_ecount_opt(size_) __post __deref __nullterminated)>
endm
__deref_out_bcount_z_opt macro size_
  exitm <_SAL1_Source_(__deref_out_bcount_z_opt, (size_), __deref_out_bcount_opt(size_) __post __deref __nullterminated)>
endm
__deref_out_nz_opt equ <_SAL1_Source_(__deref_out_nz_opt,, __deref_out_opt)>
__deref_out_ecount_nz_opt macro size_
  exitm <_SAL1_Source_(__deref_out_ecount_nz_opt, (size_), __deref_out_ecount_opt(size_))>
endm
__deref_out_bcount_nz_opt macro size_
  exitm <_SAL1_Source_(__deref_out_bcount_nz_opt, (size_), __deref_out_bcount_opt(size_))>
endm
__deref_inout_opt equ <_SAL1_Source_(__deref_inout_opt,, __deref_inout __pre_deref_except_maybenull __post_deref_except_maybenull)>
__deref_inout_ecount_opt macro size_
  exitm <_SAL1_Source_(__deref_inout_ecount_opt, (size_), __deref_inout_ecount(size_) __pre_deref_except_maybenull __post_deref_except_maybenull)>
endm
__deref_inout_bcount_opt macro size_
  exitm <_SAL1_Source_(__deref_inout_bcount_opt, (size_), __deref_inout_bcount(size_) __pre_deref_except_maybenull __post_deref_except_maybenull)>
endm
__deref_inout_ecount_part_opt macro size_, length_
  exitm <_SAL1_Source_(__deref_inout_ecount_part_opt, (size_, length_), __deref_inout_ecount_part(size_, length_) __pre_deref_except_maybenull __post_deref_except_maybenull)>
endm
__deref_inout_bcount_part_opt macro size_, length_
  exitm <_SAL1_Source_(__deref_inout_bcount_part_opt, (size_, length_), __deref_inout_bcount_part(size_, length_) __pre_deref_except_maybenull __post_deref_except_maybenull)>
endm
__deref_inout_ecount_full_opt macro size_
  exitm <_SAL1_Source_(__deref_inout_ecount_full_opt, (size_), __deref_inout_ecount_full(size_) __pre_deref_except_maybenull __post_deref_except_maybenull)>
endm
__deref_inout_bcount_full_opt macro size_
  exitm <_SAL1_Source_(__deref_inout_bcount_full_opt, (size_), __deref_inout_bcount_full(size_) __pre_deref_except_maybenull __post_deref_except_maybenull)>
endm
__deref_inout_z_opt equ <_SAL1_Source_(__deref_inout_z_opt,, __deref_inout_opt __pre __deref __nullterminated __post __deref __nullterminated)>
__deref_inout_ecount_z_opt macro size_
  exitm <_SAL1_Source_(__deref_inout_ecount_z_opt, (size_), __deref_inout_ecount_opt(size_) __pre __deref __nullterminated __post __deref __nullterminated)>
endm
__deref_inout_bcount_z_opt macro size_
  exitm <_SAL1_Source_(__deref_inout_bcount_z_opt, (size_), __deref_inout_bcount_opt(size_) __pre __deref __nullterminated __post __deref __nullterminated)>
endm
__deref_inout_nz_opt equ <_SAL1_Source_(__deref_inout_nz_opt,, __deref_inout_opt)>
__deref_inout_ecount_nz_opt macro size_
  exitm <_SAL1_Source_(__deref_inout_ecount_nz_opt, (size_), __deref_inout_ecount_opt(size_))>
endm
__deref_inout_bcount_nz_opt macro size_
  exitm <_SAL1_Source_(__deref_inout_bcount_nz_opt, (size_), __deref_inout_bcount_opt(size_))>
endm
__deref_opt_ecount macro size_
  exitm <_SAL1_Source_(__deref_opt_ecount, (size_), __deref_ecount(size_) __pre_except_maybenull)>
endm
__deref_opt_bcount macro size_
  exitm <_SAL1_Source_(__deref_opt_bcount, (size_), __deref_bcount(size_) __pre_except_maybenull)>
endm
__deref_opt_out equ <_SAL1_Source_(__deref_opt_out,, _Outptr_opt_)>
__deref_opt_out_z equ <_SAL1_Source_(__deref_opt_out_z,, _Outptr_opt_result_z_)>
__deref_opt_out_ecount macro size_
  exitm <_SAL1_Source_(__deref_opt_out_ecount, (size_), __deref_out_ecount(size_) __pre_except_maybenull)>
endm
__deref_opt_out_bcount macro size_
  exitm <_SAL1_Source_(__deref_opt_out_bcount, (size_), __deref_out_bcount(size_) __pre_except_maybenull)>
endm
__deref_opt_out_ecount_part macro size_, length_
  exitm <_SAL1_Source_(__deref_opt_out_ecount_part, (size_, length_), __deref_out_ecount_part(size_, length_) __pre_except_maybenull)>
endm
__deref_opt_out_bcount_part macro size_, length_
  exitm <_SAL1_Source_(__deref_opt_out_bcount_part, (size_, length_), __deref_out_bcount_part(size_, length_) __pre_except_maybenull)>
endm
__deref_opt_out_ecount_full macro size_
  exitm <_SAL1_Source_(__deref_opt_out_ecount_full, (size_), __deref_out_ecount_full(size_) __pre_except_maybenull)>
endm
__deref_opt_out_bcount_full macro size_
  exitm <_SAL1_Source_(__deref_opt_out_bcount_full, (size_), __deref_out_bcount_full(size_) __pre_except_maybenull)>
endm
__deref_opt_inout equ <_SAL1_Source_(__deref_opt_inout,, _Inout_opt_)>
__deref_opt_inout_ecount macro size_
  exitm <_SAL1_Source_(__deref_opt_inout_ecount, (size_), __deref_inout_ecount(size_) __pre_except_maybenull)>
endm
__deref_opt_inout_bcount macro size_
  exitm <_SAL1_Source_(__deref_opt_inout_bcount, (size_), __deref_inout_bcount(size_) __pre_except_maybenull)>
endm
__deref_opt_inout_ecount_part macro size_, length_
  exitm <_SAL1_Source_(__deref_opt_inout_ecount_part, (size_, length_), __deref_inout_ecount_part(size_, length_) __pre_except_maybenull)>
endm
__deref_opt_inout_bcount_part macro size_, length_
  exitm <_SAL1_Source_(__deref_opt_inout_bcount_part, (size_, length_), __deref_inout_bcount_part(size_, length_) __pre_except_maybenull)>
endm
__deref_opt_inout_ecount_full macro size_
  exitm <_SAL1_Source_(__deref_opt_inout_ecount_full, (size_), __deref_inout_ecount_full(size_) __pre_except_maybenull)>
endm
__deref_opt_inout_bcount_full macro size_
  exitm <_SAL1_Source_(__deref_opt_inout_bcount_full, (size_), __deref_inout_bcount_full(size_) __pre_except_maybenull)>
endm
__deref_opt_inout_z equ <_SAL1_Source_(__deref_opt_inout_z,, __deref_opt_inout __pre __deref __nullterminated __post __deref __nullterminated)>
__deref_opt_inout_ecount_z macro size_
  exitm <_SAL1_Source_(__deref_opt_inout_ecount_z, (size_), __deref_opt_inout_ecount(size_) __pre __deref __nullterminated __post __deref __nullterminated)>
endm
__deref_opt_inout_bcount_z macro size_
  exitm <_SAL1_Source_(__deref_opt_inout_bcount_z, (size_), __deref_opt_inout_bcount(size_) __pre __deref __nullterminated __post __deref __nullterminated)>
endm
__deref_opt_inout_nz equ <_SAL1_Source_(__deref_opt_inout_nz,, __deref_opt_inout)>
__deref_opt_inout_ecount_nz macro size_
  exitm <_SAL1_Source_(__deref_opt_inout_ecount_nz, (size_), __deref_opt_inout_ecount(size_))>
endm
__deref_opt_inout_bcount_nz macro size_
  exitm <_SAL1_Source_(__deref_opt_inout_bcount_nz, (size_), __deref_opt_inout_bcount(size_))>
endm
__deref_opt_ecount_opt macro size_
  exitm <_SAL1_Source_(__deref_opt_ecount_opt, (size_), __deref_ecount_opt(size_) __pre_except_maybenull)>
endm
__deref_opt_bcount_opt macro size_
  exitm <_SAL1_Source_(__deref_opt_bcount_opt, (size_), __deref_bcount_opt(size_) __pre_except_maybenull)>
endm
__deref_opt_out_opt equ <_SAL1_Source_(__deref_opt_out_opt,, _Outptr_opt_result_maybenull_)>
__deref_opt_out_ecount_opt macro size_
  exitm <_SAL1_Source_(__deref_opt_out_ecount_opt, (size_), __deref_out_ecount_opt(size_) __pre_except_maybenull)>
endm
__deref_opt_out_bcount_opt macro size_
  exitm <_SAL1_Source_(__deref_opt_out_bcount_opt, (size_), __deref_out_bcount_opt(size_) __pre_except_maybenull)>
endm
__deref_opt_out_ecount_part_opt macro size_, length_
  exitm <_SAL1_Source_(__deref_opt_out_ecount_part_opt, (size_, length_), __deref_out_ecount_part_opt(size_, length_) __pre_except_maybenull)>
endm
__deref_opt_out_bcount_part_opt macro size_, length_
  exitm <_SAL1_Source_(__deref_opt_out_bcount_part_opt, (size_, length_), __deref_out_bcount_part_opt(size_, length_) __pre_except_maybenull)>
endm
__deref_opt_out_ecount_full_opt macro size_
  exitm <_SAL1_Source_(__deref_opt_out_ecount_full_opt, (size_), __deref_out_ecount_full_opt(size_) __pre_except_maybenull)>
endm
__deref_opt_out_bcount_full_opt macro size_
  exitm <_SAL1_Source_(__deref_opt_out_bcount_full_opt, (size_), __deref_out_bcount_full_opt(size_) __pre_except_maybenull)>
endm
__deref_opt_out_z_opt equ <_SAL1_Source_(__deref_opt_out_z_opt,, __post __deref __valid __refparam __pre_except_maybenull __pre_deref_except_maybenull __post_deref_except_maybenull __post __deref __nullterminated)>
__deref_opt_out_ecount_z_opt macro size_
  exitm <_SAL1_Source_(__deref_opt_out_ecount_z_opt, (size_), __deref_opt_out_ecount_opt(size_) __post __deref __nullterminated)>
endm
__deref_opt_out_bcount_z_opt macro size_
  exitm <_SAL1_Source_(__deref_opt_out_bcount_z_opt, (size_), __deref_opt_out_bcount_opt(size_) __post __deref __nullterminated)>
endm
__deref_opt_out_nz_opt equ <_SAL1_Source_(__deref_opt_out_nz_opt,, __deref_opt_out_opt)>
__deref_opt_out_ecount_nz_opt macro size_
  exitm <_SAL1_Source_(__deref_opt_out_ecount_nz_opt, (size_), __deref_opt_out_ecount_opt(size_))>
endm
__deref_opt_out_bcount_nz_opt macro size_
  exitm <_SAL1_Source_(__deref_opt_out_bcount_nz_opt, (size_), __deref_opt_out_bcount_opt(size_))>
endm
__deref_opt_inout_opt equ <_SAL1_Source_(__deref_opt_inout_opt,, __deref_inout_opt __pre_except_maybenull)>
__deref_opt_inout_ecount_opt macro size_
  exitm <_SAL1_Source_(__deref_opt_inout_ecount_opt, (size_), __deref_inout_ecount_opt(size_) __pre_except_maybenull)>
endm
__deref_opt_inout_bcount_opt macro size_
  exitm <_SAL1_Source_(__deref_opt_inout_bcount_opt, (size_), __deref_inout_bcount_opt(size_) __pre_except_maybenull)>
endm
__deref_opt_inout_ecount_part_opt macro size_, length_
  exitm <_SAL1_Source_(__deref_opt_inout_ecount_part_opt, (size_, length_), __deref_inout_ecount_part_opt(size_, length_) __pre_except_maybenull)>
endm
__deref_opt_inout_bcount_part_opt macro size_, length_
  exitm <_SAL1_Source_(__deref_opt_inout_bcount_part_opt, (size_, length_), __deref_inout_bcount_part_opt(size_, length_) __pre_except_maybenull)>
endm
__deref_opt_inout_ecount_full_opt macro size_
  exitm <_SAL1_Source_(__deref_opt_inout_ecount_full_opt, (size_), __deref_inout_ecount_full_opt(size_) __pre_except_maybenull)>
endm
__deref_opt_inout_bcount_full_opt macro size_
  exitm <_SAL1_Source_(__deref_opt_inout_bcount_full_opt, (size_), __deref_inout_bcount_full_opt(size_) __pre_except_maybenull)>
endm
__deref_opt_inout_z_opt equ <_SAL1_Source_(__deref_opt_inout_z_opt,, __deref_opt_inout_opt __pre __deref __nullterminated __post __deref __nullterminated)>
__deref_opt_inout_ecount_z_opt macro size_
  exitm <_SAL1_Source_(__deref_opt_inout_ecount_z_opt, (size_), __deref_opt_inout_ecount_opt(size_) __pre __deref __nullterminated __post __deref __nullterminated)>
endm
__deref_opt_inout_bcount_z_opt macro size_
  exitm <_SAL1_Source_(__deref_opt_inout_bcount_z_opt, (size_), __deref_opt_inout_bcount_opt(size_) __pre __deref __nullterminated __post __deref __nullterminated)>
endm
__deref_opt_inout_nz_opt equ <_SAL1_Source_(__deref_opt_inout_nz_opt,, __deref_opt_inout_opt)>
__deref_opt_inout_ecount_nz_opt macro size_
  exitm <_SAL1_Source_(__deref_opt_inout_ecount_nz_opt, (size_), __deref_opt_inout_ecount_opt(size_))>
endm
__deref_opt_inout_bcount_nz_opt macro size_
  exitm <_SAL1_Source_(__deref_opt_inout_bcount_nz_opt, (size_), __deref_opt_inout_bcount_opt(size_))>
endm
__success macro expr
  exitm <_SAL1_1_Source_(__success, (expr), _Success_(expr))>
endm
__nullterminated equ <_SAL1_Source_(__nullterminated,, _Null_terminated_)>
__nullnullterminated equ <_SAL1_Source_(__nullnulltermiated,, _SAL_nop_impl_)>
__reserved equ <_SAL1_Source_(__reserved,, _Reserved_)>
__checkReturn equ <_SAL1_Source_(__checkReturn,, _Check_return_)>
__typefix macro ctype
  exitm <_SAL1_Source_(__typefix, (ctype), __inner_typefix(ctype))>
endm
__override equ <__inner_override>
__callback equ <__inner_callback>
__format_string equ <_SAL1_1_Source_(__format_string,, _Printf_format_string_)>
__blocksOn macro resource
  exitm <_SAL_L_Source_(__blocksOn, (resource), __inner_blocksOn(resource))>
endm
__control_entrypoint macro category
  exitm <_SAL_L_Source_(__control_entrypoint, (category), __inner_control_entrypoint(category))>
endm
__data_entrypoint macro category
  exitm <_SAL_L_Source_(__data_entrypoint, (category), __inner_data_entrypoint(category))>
endm
ifdef _USING_V110_SDK71_
  ifndef _PREFAST_
    __useHeader equ <>
  else
    ;[...]
  endif
else
  __useHeader equ <_Use_decl_anno_impl_>
endif
ifdef _USING_V110_SDK71_
  ifndef _PREFAST_
    __on_failure macro annotes
      exitm <>
    endm
  else
    ;[...]
  endif
else
  __on_failure macro annotes
    exitm <_SAL1_1_Source_(__on_failure, (annotes), _On_failure_impl_(annotes _SAL_nop_impl_))>
  endm
endif
ifndef __fallthrough
  __fallthrough equ <__inner_fallthrough>
endif
ifndef __analysis_assume
  ifdef _PREFAST_
    ;[...]
  else
    __analysis_assume macro expr
      exitm <>
    endm
  endif
endif
ifndef _Analysis_assume_
  ifdef _PREFAST_
    ;[...]
  else
    _Analysis_assume_ macro expr
      exitm <>
    endm
  endif
endif
_Analysis_noreturn_ equ <_SAL2_Source_(_Analysis_noreturn_,, _SA_annotes0(SAL_terminates))>
ifdef _PREFAST_
  ;[...]
else
  _Analysis_assume_nullterminated_ macro x
    exitm <>
  endm
endif
___MKID macro x, y
  exitm <x ## y>
endm
__MKID macro x, y
  exitm <___MKID(x, y)>
endm
__GENSYM macro x
  exitm <__MKID(x, __COUNTER__)>
endm
_Analysis_mode_impl_ macro mode
  exitm <_SAL2_Source_(_Analysis_mode_impl_, (mode), _SA_annotes1(SAL_analysisMode, # mode))>
endm
ifndef _M_IX86
  _Analysis_mode_ macro mode
    exitm <__pragma (warning (disable : 28110 28111 28161 28162)) typedef _Analysis_mode_impl_(mode) int __GENSYM(__prefast_analysis_mode_flag) ;>
  endm
else
  _Analysis_mode_ macro mode
    exitm <typedef _Analysis_mode_impl_(mode) int __GENSYM(__prefast_analysis_mode_flag) ;>
  endm
endif
_In_function_class_ macro x
  exitm <_In_function_class_(# x)>
endm
_Called_from_function_class_ macro x
  exitm <_In_function_class_(x)>
endm
_Function_class_ macro x
  exitm <_SAL2_Source_(_Function_class_, (x), _SA_annotes1(SAL_functionClassNew, _SA_SPECSTRIZE(x)))>
endm
_Enum_is_bitflag_ equ <_SAL2_Source_(_Enum_is_bitflag_,, _SA_annotes0(SAL_enumIsBitflag))>
_Strict_type_match_ equ <_SAL2_Source_(_Strict_type_match,, _SA_annotes0(SAL_strictType2))>
_Maybe_raises_SEH_exception_ equ <_SAL2_Source_(_Maybe_raises_SEH_exception_, (x), _Pre_ _SA_annotes1(SAL_inTry, __yes))>
_Raises_SEH_exception_ equ <_SAL2_Source_(_Raises_SEH_exception_, (x), _Maybe_raises_SEH_exception_ _Analysis_noreturn_)>
_Published_ equ <_SAL2_Source_(_Published_,, _SA_annotes0(SAL_externalIntf))>
ifdef __cplusplus
  ;[...]
endif
include ConcurrencySal.inc

