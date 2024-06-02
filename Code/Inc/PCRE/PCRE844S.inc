;**************************************************
;*       Perl-Compatible Regular Expressions      *
;**************************************************
;
;This is the public header file for the PCRE library, to be #included by
;applications that call the PCRE functions.
;
;          Copyright (c) 1997-2014 University of Cambridge
;
;-----------------------------------------------------------------------------
;Redistribution and use in source and binary forms, with or without
;modification, are permitted provided that the following conditions are met:
;
;   * Redistributions of source code must retain the above copyright notice,
;     this list of conditions and the following disclaimer.
;
;   * Redistributions in binary form must reproduce the above copyright
;     notice, this list of conditions and the following disclaimer in the
;     documentation and/or other materials provided with the distribution.
;
;   * Neither the name of the University of Cambridge nor the names of its
;     contributors may be used to endorse or promote products derived from
;     this software without specific prior written permission.
;
;THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
;AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
;IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
;ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
;LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
;CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
;SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
;INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
;CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
;ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
;POSSIBILITY OF SUCH DAMAGE.
;-----------------------------------------------------------------------------

;The current PCRE version information.

PCRE_MAJOR      equ   8
PCRE_MINOR      equ   44
PCRE_PRERELEASE equ 0
PCRE_DATE       equ   2020-02-12


ifndef defined
  defined macro x
    ifdef x
      exitm <1>
    else
      exitm <0>
    endif
  endm
endif

if defined(_WIN32) AND  0 eq defined(PCRE_STATIC)
  ifndef PCRE_EXP_DECL
  PCRE_EXP_DECL EQU <extern __declspec ( dllimport )>
endif

ifdef __cplusplus
  ifndef PCRECPP_EXP_DECL
    PCRECPP_EXP_DECL EQU <extern __declspec ( dllimport )>
  endif
  ifndef PCRECPP_EXP_DEFN
    PCRECPP_EXP_DEFN EQU <__declspec ( dllimport )>
  endif
endif

endif

ifndef PCRE_EXP_DECL
  ifdef __cplusplus
    PCRE_EXP_DECL EQU <extern "C">
  else
    PCRE_EXP_DECL EQU <extern>
  endif
endif

ifdef __cplusplus
  ifndef PCRECPP_EXP_DECL
    PCRECPP_EXP_DECL EQU <extern>
  endif
  ifndef PCRECPP_EXP_DEFN
    PCRECPP_EXP_DEFN EQU <>
  endif
endif

;Public options. Some are compile-time only, some are run-time only, and some
;are both. Most of the compile-time options are saved with the compiled regex so
;that they can be inspected during studying (and therefore JIT compiling). Note
;that pcre_study() has its own set of options. Originally, all the options
;defined here used distinct bits. However, almost all the bits in a 32-bit word
;are now used, so in order to conserve them, option bits that were previously
;only recognized at matching time (i.e. by pcre_exec() or pcre_dfa_exec()) may
;also be used for compile-time options that affect only compiling and are not
;relevant for studying or JIT compiling.
;
;Some options for pcre_compile() change its behaviour but do not affect the
;behaviour of the execution functions. Other options are passed through to the
;execution functions and affect their behaviour, with or without affecting the
;behaviour of pcre_compile().
;
;Options that can be passed to pcre_compile() are tagged Cx below, with these
;variants:
;
;C1   Affects compile only
;C2   Does not affect compile; affects exec, dfa_exec
;C3   Affects compile, exec, dfa_exec
;C4   Affects compile, exec, dfa_exec, study
;C5   Affects compile, exec, study
;
;Options that can be set for pcre_exec() and/or pcre_dfa_exec() are flagged with
;E and D, respectively. They take precedence over C3, C4, and C5 settings passed
;from pcre_compile(). Those that are compatible with JIT execution are flagged
;with J.

PCRE_CASELESS                 equ     00000001h  ;C1
PCRE_MULTILINE                equ     00000002h  ;C1
PCRE_DOTALL                   equ     00000004h  ;C1
PCRE_EXTENDED                 equ     00000008h  ;C1
PCRE_ANCHORED                 equ     00000010h  ;C4 E D
PCRE_DOLLAR_ENDONLY           equ     00000020h  ;C2
PCRE_EXTRA                    equ     00000040h  ;C1
PCRE_NOTBOL                   equ     00000080h  ;   E D J
PCRE_NOTEOL                   equ     00000100h  ;   E D J
PCRE_UNGREEDY                 equ     00000200h  ;C1
PCRE_NOTEMPTY                 equ     00000400h  ;   E D J
PCRE_UTF8                     equ     00000800h  ;C4        )
PCRE_UTF16                    equ     00000800h  ;C4        ) Synonyms
PCRE_UTF32                    equ     00000800h  ;C4        )
PCRE_NO_AUTO_CAPTURE          equ     00001000h  ;C1
PCRE_NO_UTF8_CHECK            equ     00002000h  ;C1 E D J  )
PCRE_NO_UTF16_CHECK           equ     00002000h  ;C1 E D J  ) Synonyms
PCRE_NO_UTF32_CHECK           equ     00002000h  ;C1 E D J  )
PCRE_AUTO_CALLOUT             equ     00004000h  ;C1
PCRE_PARTIAL_SOFT             equ     00008000h  ;   E D J  ) Synonyms
PCRE_PARTIAL                  equ     00008000h  ;   E D J  )

;This pair use the same bit.
PCRE_NEVER_UTF                equ     00010000h  ;C1        ) Overlaid
PCRE_DFA_SHORTEST             equ     00010000h  ;     D    ) Overlaid

;This pair use the same bit.
PCRE_NO_AUTO_POSSESS          equ     00020000h  ;C1        ) Overlaid
PCRE_DFA_RESTART              equ     00020000h  ;     D    ) Overlaid

PCRE_FIRSTLINE                equ     00040000h  ;C3
PCRE_DUPNAMES                 equ     00080000h  ;C1
PCRE_NEWLINE_CR               equ     00100000h  ;C3 E D
PCRE_NEWLINE_LF               equ     00200000h  ;C3 E D
PCRE_NEWLINE_CRLF             equ     00300000h  ;C3 E D
PCRE_NEWLINE_ANY              equ     00400000h  ;C3 E D
PCRE_NEWLINE_ANYCRLF          equ     00500000h  ;C3 E D
PCRE_BSR_ANYCRLF              equ     00800000h  ;C3 E D
PCRE_BSR_UNICODE              equ     01000000h  ;C3 E D
PCRE_JAVASCRIPT_COMPAT        equ     02000000h  ;C5
PCRE_NO_START_OPTIMIZE        equ     04000000h  ;C2 E D    ) Synonyms
PCRE_NO_START_OPTIMISE        equ     04000000h  ;C2 E D    )
PCRE_PARTIAL_HARD             equ     08000000h  ;   E D J
PCRE_NOTEMPTY_ATSTART         equ     10000000h  ;   E D J
PCRE_UCP                      equ     20000000h  ;C3

;Exec-time and get/set-time error codes

PCRE_ERROR_NOMATCH            equ      (-1)
PCRE_ERROR_NULL               equ      (-2)
PCRE_ERROR_BADOPTION          equ      (-3)
PCRE_ERROR_BADMAGIC           equ      (-4)
PCRE_ERROR_UNKNOWN_OPCODE     equ      (-5)
PCRE_ERROR_UNKNOWN_NODE       equ      (-5)  ;For backward compatibility
PCRE_ERROR_NOMEMORY           equ      (-6)
PCRE_ERROR_NOSUBSTRING        equ      (-7)
PCRE_ERROR_MATCHLIMIT         equ      (-8)
PCRE_ERROR_CALLOUT            equ      (-9)  ;Never used by PCRE itself
PCRE_ERROR_BADUTF8            equ     (-10)  ;Same for 8/16/32
PCRE_ERROR_BADUTF16           equ     (-10)  ;Same for 8/16/32
PCRE_ERROR_BADUTF32           equ     (-10)  ;Same for 8/16/32
PCRE_ERROR_BADUTF8_OFFSET     equ     (-11)  ;Same for 8/16
PCRE_ERROR_BADUTF16_OFFSET    equ     (-11)  ;Same for 8/16
PCRE_ERROR_PARTIAL            equ     (-12)
PCRE_ERROR_BADPARTIAL         equ     (-13)
PCRE_ERROR_INTERNAL           equ     (-14)
PCRE_ERROR_BADCOUNT           equ     (-15)
PCRE_ERROR_DFA_UITEM          equ     (-16)
PCRE_ERROR_DFA_UCOND          equ     (-17)
PCRE_ERROR_DFA_UMLIMIT        equ     (-18)
PCRE_ERROR_DFA_WSSIZE         equ     (-19)
PCRE_ERROR_DFA_RECURSE        equ     (-20)
PCRE_ERROR_RECURSIONLIMIT     equ     (-21)
PCRE_ERROR_NULLWSLIMIT        equ     (-22)  ;No longer actually used
PCRE_ERROR_BADNEWLINE         equ     (-23)
PCRE_ERROR_BADOFFSET          equ     (-24)
PCRE_ERROR_SHORTUTF8          equ     (-25)
PCRE_ERROR_SHORTUTF16         equ     (-25)  ;Same for 8/16
PCRE_ERROR_RECURSELOOP        equ     (-26)
PCRE_ERROR_JIT_STACKLIMIT     equ     (-27)
PCRE_ERROR_BADMODE            equ     (-28)
PCRE_ERROR_BADENDIANNESS      equ     (-29)
PCRE_ERROR_DFA_BADRESTART     equ     (-30)
PCRE_ERROR_JIT_BADOPTION      equ     (-31)
PCRE_ERROR_BADLENGTH          equ     (-32)
PCRE_ERROR_UNSET              equ     (-33)

;Specific error codes for UTF-8 validity checks

PCRE_UTF8_ERR0                equ      0
PCRE_UTF8_ERR1                equ      1
PCRE_UTF8_ERR2                equ      2
PCRE_UTF8_ERR3                equ      3
PCRE_UTF8_ERR4                equ      4
PCRE_UTF8_ERR5                equ      5
PCRE_UTF8_ERR6                equ      6
PCRE_UTF8_ERR7                equ      7
PCRE_UTF8_ERR8                equ      8
PCRE_UTF8_ERR9                equ      9
PCRE_UTF8_ERR10               equ     10
PCRE_UTF8_ERR11               equ     11
PCRE_UTF8_ERR12               equ     12
PCRE_UTF8_ERR13               equ     13
PCRE_UTF8_ERR14               equ     14
PCRE_UTF8_ERR15               equ     15
PCRE_UTF8_ERR16               equ     16
PCRE_UTF8_ERR17               equ     17
PCRE_UTF8_ERR18               equ     18
PCRE_UTF8_ERR19               equ     19
PCRE_UTF8_ERR20               equ     20
PCRE_UTF8_ERR21               equ     21
PCRE_UTF8_ERR22               equ     22  ;Unused (was non-character)

;Specific error codes for UTF-16 validity checks

PCRE_UTF16_ERR0               equ      0
PCRE_UTF16_ERR1               equ      1
PCRE_UTF16_ERR2               equ      2
PCRE_UTF16_ERR3               equ      3
PCRE_UTF16_ERR4               equ      4  ;Unused (was non-character)

;Specific error codes for UTF-32 validity checks

PCRE_UTF32_ERR0               equ      0
PCRE_UTF32_ERR1               equ      1
PCRE_UTF32_ERR2               equ      2  ;Unused (was non-character)
PCRE_UTF32_ERR3               equ      3

;Request types for pcre_fullinfo()

PCRE_INFO_OPTIONS             equ      0
PCRE_INFO_SIZE                equ      1
PCRE_INFO_CAPTURECOUNT        equ      2
PCRE_INFO_BACKREFMAX          equ      3
PCRE_INFO_FIRSTBYTE           equ      4
PCRE_INFO_FIRSTCHAR           equ      4  ;For backwards compatibility
PCRE_INFO_FIRSTTABLE          equ      5
PCRE_INFO_LASTLITERAL         equ      6
PCRE_INFO_NAMEENTRYSIZE       equ      7
PCRE_INFO_NAMECOUNT           equ      8
PCRE_INFO_NAMETABLE           equ      9
PCRE_INFO_STUDYSIZE           equ     10
PCRE_INFO_DEFAULT_TABLES      equ     11
PCRE_INFO_OKPARTIAL           equ     12
PCRE_INFO_JCHANGED            equ     13
PCRE_INFO_HASCRORLF           equ     14
PCRE_INFO_MINLENGTH           equ     15
PCRE_INFO_JIT                 equ     16
PCRE_INFO_JITSIZE             equ     17
PCRE_INFO_MAXLOOKBEHIND       equ     18
PCRE_INFO_FIRSTCHARACTER      equ     19
PCRE_INFO_FIRSTCHARACTERFLAGS equ     20
PCRE_INFO_REQUIREDCHAR        equ     21
PCRE_INFO_REQUIREDCHARFLAGS   equ     22
PCRE_INFO_MATCHLIMIT          equ     23
PCRE_INFO_RECURSIONLIMIT      equ     24
PCRE_INFO_MATCH_EMPTY         equ     25

;Request types for pcre_config(). Do not re-arrange, in order to remain
;compatible.

PCRE_CONFIG_UTF8                      equ    0
PCRE_CONFIG_NEWLINE                   equ    1
PCRE_CONFIG_LINK_SIZE                 equ    2
PCRE_CONFIG_POSIX_MALLOC_THRESHOLD    equ    3
PCRE_CONFIG_MATCH_LIMIT               equ    4
PCRE_CONFIG_STACKRECURSE              equ    5
PCRE_CONFIG_UNICODE_PROPERTIES        equ    6
PCRE_CONFIG_MATCH_LIMIT_RECURSION     equ    7
PCRE_CONFIG_BSR                       equ    8
PCRE_CONFIG_JIT                       equ    9
PCRE_CONFIG_UTF16                     equ   10
PCRE_CONFIG_JITTARGET                 equ   11
PCRE_CONFIG_UTF32                     equ   12
PCRE_CONFIG_PARENS_LIMIT              equ   13

;Request types for pcre_study(). Do not re-arrange, in order to remain
;compatible.

PCRE_STUDY_JIT_COMPILE                equ   0001h
PCRE_STUDY_JIT_PARTIAL_SOFT_COMPILE   equ   0002h
PCRE_STUDY_JIT_PARTIAL_HARD_COMPILE   equ   0004h
PCRE_STUDY_EXTRA_NEEDED               equ   0008h

;Bit flags for the pcre[16|32]_extra structure. Do not re-arrange or redefine
;these bits, just add new ones on the end, in order to remain compatible.

PCRE_EXTRA_STUDY_DATA                 equ   0001h
PCRE_EXTRA_MATCH_LIMIT                equ   0002h
PCRE_EXTRA_CALLOUT_DATA               equ   0004h
PCRE_EXTRA_TABLES                     equ   0008h
PCRE_EXTRA_MATCH_LIMIT_RECURSION      equ   0010h
PCRE_EXTRA_MARK                       equ   0020h
PCRE_EXTRA_EXECUTABLE_JIT             equ   0040h


PCRE_UCHAR16  equ <WORD>
PCRE_SPTR16   typedef ptr WORD

PCRE_UCHAR32  equ <DWORD>
PCRE_SPTR32   typedef ptr DWORD

PCRE_SPTR     typedef ptr BYTE

pcre_extra struct
  flags                 DWORD   ?       ;Bits for which fields are set
  study_data            POINTER ?       ;Opaque data from pcre_study()
  match_limit           DWORD   ?       ;Maximum number of calls to match()
  callout_data          POINTER ?       ;Data passed back in callouts
  tables                POINTER ?       ;Pointer to character tables
  match_limit_recursion DWORD   ?       ;Max recursive calls to match()
  mark                  POINTER ?       ;For passing back a mark pointer
  executable_jit        POINTER ?       ;Contains a pointer to a compiled jit code
pcre_extra ends

pcre16_extra struct
  flags                 DWORD   ?       ;Bits for which fields are set
  study_data            POINTER ?       ;Opaque data from pcre_study()
  match_limit           DWORD   ?       ;Maximum number of calls to match()
  callout_data          POINTER ?       ;Data passed back in callouts
  tables                POINTER ?       ;Pointer to character tables
  match_limit_recursion DWORD   ?       ;Max recursive calls to match()
  mark                  POINTER ?       ;For passing back a mark pointer
  executable_jit        POINTER ?       ;Contains a pointer to a compiled jit code
pcre16_extra ends

pcre32_extra struct
  flags                 DWORD   ?       ;Bits for which fields are set
  study_data            POINTER ?       ;Opaque data from pcre_study()
  match_limit           DWORD   ?       ;Maximum number of calls to match()
  callout_data          POINTER ?       ;Data passed back in callouts
  tables                POINTER ?       ;Pointer to character tables
  match_limit_recursion DWORD   ?       ;Max recursive calls to match()
  mark                  POINTER ?       ;For passing back a mark pointer
  executable_jit        POINTER ?       ;Contains a pointer to a compiled jit code
pcre32_extra ends

pcre_callout_block struct
  version               POINTER ?       ;Identifies version of block
  ;------------------------ Version 0 -------------------------------
  callout_number        DWORD   ?       ;Number compiled into pattern
  offset_vector         DWORD   ?       ;The offset vector
  subject               POINTER ?       ;The subject being matched
  subject_length        DWORD   ?       ;The length of the subject
  start_match           DWORD   ?       ;Offset to start of this match attempt
  current_position      DWORD   ?       ;Where we currently are in the subject
  capture_top           DWORD   ?       ;Max current capture
  capture_last          DWORD   ?       ;Most recently closed capture
  callout_data          DWORD   ?       ;Data passed in with the call
  ;------------------- Added for Version 1 --------------------------
  pattern_position      DWORD   ?       ;Offset to next item in the pattern
  next_item_length      DWORD   ?       ;Length of next item in the pattern
  ;------------------- Added for Version 2 --------------------------
  mark                  POINTER ?       ;Pointer to current mark or NULL
pcre_callout_block ends

pcre16_callout_block struct
  version               POINTER ?       ;Identifies version of block
  ;------------------------ Version 0 -------------------------------
  callout_number        DWORD   ?       ;Number compiled into pattern
  offset_vector         DWORD   ?       ;The offset vector
  subject               POINTER ?       ;The subject being matched
  subject_length        DWORD   ?       ;The length of the subject
  start_match           DWORD   ?       ;Offset to start of this match attempt
  current_position      DWORD   ?       ;Where we currently are in the subject
  capture_top           DWORD   ?       ;Max current capture
  capture_last          DWORD   ?       ;Most recently closed capture
  callout_data          DWORD   ?       ;Data passed in with the call
  ;------------------- Added for Version 1 --------------------------
  pattern_position      DWORD   ?       ;Offset to next item in the pattern
  next_item_length      DWORD   ?       ;Length of next item in the pattern
  ;------------------- Added for Version 2 --------------------------
  mark                  POINTER ?       ;Pointer to current mark or NULL
pcre16_callout_block ends

pcre32_callout_block struct
  version               POINTER ?       ;Identifies version of block
  ;------------------------ Version 0 -------------------------------
  callout_number        DWORD   ?       ;Number compiled into pattern
  offset_vector         DWORD   ?       ;The offset vector
  subject               POINTER ?       ;The subject being matched
  subject_length        DWORD   ?       ;The length of the subject
  start_match           DWORD   ?       ;Offset to start of this match attempt
  current_position      DWORD   ?       ;Where we currently are in the subject
  capture_top           DWORD   ?       ;Max current capture
  capture_last          DWORD   ?       ;Most recently closed capture
  callout_data          DWORD   ?       ;Data passed in with the call
  ;------------------- Added for Version 1 --------------------------
  pattern_position      DWORD   ?       ;Offset to next item in the pattern
  next_item_length      DWORD   ?       ;Length of next item in the pattern
  ;------------------- Added for Version 2 --------------------------
  mark                  POINTER ?       ;Pointer to current mark or NULL
pcre32_callout_block ends

PCRE_OUTDATA struc
  dBegIndex  DWORD   ?      ;Zero based CHR index where the substring begins
  dEndIndex  DWORD   ?      ;Zero based CHR index where the substring ends
PCRE_OUTDATA ends


;Indirection for store get and free functions. These can be set to
;alternative malloc/free functions if required. Special ones are used in the
;non-recursive case for "frames". There is also an optional callout function
;that is triggered by the (?) regex item. For Virtual Pascal, these definitions
;have to take another form.

pcre_malloc_type typedef proto  :DWORD
externdef pcre_malloc:ptr pcre_malloc_type
pcre_free_type typedef proto  :POINTER
externdef pcre_free:ptr pcre_free_type
pcre_stack_malloc_type typedef proto  :DWORD
externdef pcre_stack_malloc:ptr pcre_stack_malloc_type
pcre_stack_free_type typedef proto  :POINTER
externdef pcre_stack_free:ptr pcre_stack_free_type
pcre_callout_type typedef proto  :DWORD
externdef pcre_callout:ptr pcre_callout_type
pcre_stack_guard_type typedef proto
externdef pcre_stack_guard:ptr pcre_stack_guard_type

pcre16_malloc_type typedef proto  :DWORD
externdef pcre16_malloc:ptr pcre16_malloc_type
pcre16_free_type typedef proto  :POINTER
externdef pcre16_free:ptr pcre16_free_type
pcre16_stack_malloc_type typedef proto  :DWORD
externdef pcre16_stack_malloc:ptr pcre16_stack_malloc_type
pcre16_stack_free_type typedef proto  :POINTER
externdef pcre16_stack_free:ptr pcre16_stack_free_type
pcre16_callout_type typedef proto  :DWORD
externdef pcre16_callout:ptr pcre16_callout_type
pcre16_stack_guard_type typedef proto
externdef pcre16_stack_guard:ptr pcre16_stack_guard_type

pcre32_malloc_type typedef proto  :DWORD
externdef pcre32_malloc:ptr pcre32_malloc_type
pcre32_free_type typedef proto  :POINTER
externdef pcre32_free:ptr pcre32_free_type
pcre32_stack_malloc_type typedef proto  :DWORD
externdef pcre32_stack_malloc:ptr pcre32_stack_malloc_type
pcre32_stack_free_type typedef proto  :POINTER
externdef pcre32_stack_free:ptr pcre32_stack_free_type
pcre32_callout_type typedef proto  :DWORD
externdef pcre32_callout:ptr pcre32_callout_type
pcre32_stack_guard_type typedef proto
externdef pcre32_stack_guard:ptr pcre32_stack_guard_type


proto_pcre_jit_callback typedef proto  :ptr
pcre_jit_callback typedef ptr proto_pcre_jit_callback
proto_pcre16_jit_callback typedef proto  :ptr
pcre16_jit_callback typedef ptr proto_pcre16_jit_callback
proto_pcre32_jit_callback typedef proto  :ptr
pcre32_jit_callback typedef ptr proto_pcre32_jit_callback

pcre_compile proto  :ptr SBYTE, :DWORD, :ptr ptr SBYTE, :ptr DWORD, :ptr BYTE
pcre16_compile proto  :PCRE_SPTR16, :DWORD, :ptr ptr SBYTE, :ptr DWORD, :ptr BYTE
pcre32_compile proto  :PCRE_SPTR32, :DWORD, :ptr ptr SBYTE, :ptr DWORD, :ptr BYTE
pcre_compile2 proto  :ptr SBYTE, :DWORD, :ptr DWORD, :ptr ptr SBYTE, :ptr DWORD, :ptr BYTE
pcre16_compile2 proto  :PCRE_SPTR16, :DWORD, :ptr DWORD, :ptr ptr SBYTE, :ptr DWORD, :ptr BYTE
pcre32_compile2 proto  :PCRE_SPTR32, :DWORD, :ptr DWORD, :ptr ptr SBYTE, :ptr DWORD, :ptr BYTE
pcre_config proto  :DWORD, :ptr
pcre16_config proto  :DWORD, :ptr
pcre32_config proto  :DWORD, :ptr
pcre_copy_named_substring proto  :ptr pcre, :ptr SBYTE, :ptr DWORD, :DWORD, :ptr SBYTE, :ptr SBYTE, :DWORD
pcre16_copy_named_substring proto  :ptr pcre16, :PCRE_SPTR16, :ptr DWORD, :DWORD, :PCRE_SPTR16, :ptr PCRE_UCHAR16, :DWORD
pcre32_copy_named_substring proto  :ptr pcre32, :PCRE_SPTR32, :ptr DWORD, :DWORD, :PCRE_SPTR32, :ptr PCRE_UCHAR32, :DWORD
pcre_copy_substring proto  :ptr SBYTE, :ptr DWORD, :DWORD, :DWORD, :ptr SBYTE, :DWORD
pcre16_copy_substring proto  :PCRE_SPTR16, :ptr DWORD, :DWORD, :DWORD, :ptr PCRE_UCHAR16, :DWORD
pcre32_copy_substring proto  :PCRE_SPTR32, :ptr DWORD, :DWORD, :DWORD, :ptr PCRE_UCHAR32, :DWORD
pcre_dfa_exec proto  :ptr pcre, :ptr pcre_extra, :ptr SBYTE, :DWORD, :DWORD, :DWORD, :ptr DWORD, :DWORD, :ptr DWORD, :DWORD
pcre16_dfa_exec proto  :ptr pcre16, :ptr pcre16_extra, :PCRE_SPTR16, :DWORD, :DWORD, :DWORD, :ptr DWORD, :DWORD, :ptr DWORD, :DWORD
pcre32_dfa_exec proto  :ptr pcre32, :ptr pcre32_extra, :PCRE_SPTR32, :DWORD, :DWORD, :DWORD, :ptr DWORD, :DWORD, :ptr DWORD, :DWORD
pcre_exec proto  :ptr pcre, :ptr pcre_extra, :PCRE_SPTR, :DWORD, :DWORD, :DWORD, :ptr DWORD, :DWORD
pcre16_exec proto  :ptr pcre16, :ptr pcre16_extra, :PCRE_SPTR16, :DWORD, :DWORD, :DWORD, :ptr DWORD, :DWORD
pcre32_exec proto  :ptr pcre32, :ptr pcre32_extra, :PCRE_SPTR32, :DWORD, :DWORD, :DWORD, :ptr DWORD, :DWORD
pcre_jit_exec proto  :ptr pcre, :ptr pcre_extra, :PCRE_SPTR, :DWORD, :DWORD, :DWORD, :ptr DWORD, :DWORD, :ptr pcre_jit_stack
pcre16_jit_exec proto  :ptr pcre16, :ptr pcre16_extra, :PCRE_SPTR16, :DWORD, :DWORD, :DWORD, :ptr DWORD, :DWORD, :ptr pcre16_jit_stack
pcre32_jit_exec proto  :ptr pcre32, :ptr pcre32_extra, :PCRE_SPTR32, :DWORD, :DWORD, :DWORD, :ptr DWORD, :DWORD, :ptr pcre32_jit_stack
pcre_free_substring proto  :ptr SBYTE
pcre16_free_substring proto  :PCRE_SPTR16
pcre32_free_substring proto  :PCRE_SPTR32
pcre_free_substring_list proto  :ptr ptr SBYTE
pcre16_free_substring_list proto  :ptr PCRE_SPTR16
pcre32_free_substring_list proto  :ptr PCRE_SPTR32
pcre_fullinfo proto  :ptr pcre, :ptr pcre_extra, :DWORD, :ptr
pcre16_fullinfo proto  :ptr pcre16, :ptr pcre16_extra, :DWORD, :ptr
pcre32_fullinfo proto  :ptr pcre32, :ptr pcre32_extra, :DWORD, :ptr
pcre_get_named_substring proto  :ptr pcre, :ptr SBYTE, :ptr DWORD, :DWORD, :ptr SBYTE, :ptr ptr SBYTE
pcre16_get_named_substring proto  :ptr pcre16, :PCRE_SPTR16, :ptr DWORD, :DWORD, :PCRE_SPTR16, :ptr PCRE_SPTR16
pcre32_get_named_substring proto  :ptr pcre32, :PCRE_SPTR32, :ptr DWORD, :DWORD, :PCRE_SPTR32, :ptr PCRE_SPTR32
pcre_get_stringnumber proto  :ptr pcre, :ptr SBYTE
pcre16_get_stringnumber proto  :ptr pcre16, :PCRE_SPTR16
pcre32_get_stringnumber proto  :ptr pcre32, :PCRE_SPTR32
pcre_get_stringtable_entries proto  :ptr pcre, :ptr SBYTE, :ptr ptr SBYTE, :ptr ptr SBYTE
pcre16_get_stringtable_entries proto  :ptr pcre16, :PCRE_SPTR16, :ptr ptr PCRE_UCHAR16, :ptr ptr PCRE_UCHAR16
pcre32_get_stringtable_entries proto  :ptr pcre32, :PCRE_SPTR32, :ptr ptr PCRE_UCHAR32, :ptr ptr PCRE_UCHAR32
pcre_get_substring proto  :ptr SBYTE, :ptr DWORD, :DWORD, :DWORD, :ptr ptr SBYTE
pcre16_get_substring proto  :PCRE_SPTR16, :ptr DWORD, :DWORD, :DWORD, :ptr PCRE_SPTR16
pcre32_get_substring proto  :PCRE_SPTR32, :ptr DWORD, :DWORD, :DWORD, :ptr PCRE_SPTR32
pcre_get_substring_list proto  :ptr SBYTE, :ptr DWORD, :DWORD, :ptr ptr ptr SBYTE
pcre16_get_substring_list proto  :PCRE_SPTR16, :ptr DWORD, :DWORD, :ptr ptr PCRE_SPTR16
pcre32_get_substring_list proto  :PCRE_SPTR32, :ptr DWORD, :DWORD, :ptr ptr PCRE_SPTR32
pcre_maketables proto
pcre16_maketables proto
pcre32_maketables proto
pcre_refcount proto  :ptr pcre, :DWORD
pcre16_refcount proto  :ptr pcre16, :DWORD
pcre32_refcount proto  :ptr pcre32, :DWORD
pcre_study proto  :ptr pcre, :DWORD, :ptr ptr SBYTE
pcre16_study proto  :ptr pcre16, :DWORD, :ptr ptr SBYTE
pcre32_study proto  :ptr pcre32, :DWORD, :ptr ptr SBYTE
pcre_free_study proto  :ptr pcre_extra
pcre16_free_study proto  :ptr pcre16_extra
pcre32_free_study proto  :ptr pcre32_extra
pcre_version proto
pcre16_version proto
pcre32_version proto
pcre_pattern_to_host_byte_order proto  :ptr pcre, :ptr pcre_extra, :ptr BYTE
pcre16_pattern_to_host_byte_order proto  :ptr pcre16, :ptr pcre16_extra, :ptr BYTE
pcre32_pattern_to_host_byte_order proto  :ptr pcre32, :ptr pcre32_extra, :ptr BYTE
pcre16_utf16_to_host_byte_order proto  :ptr PCRE_UCHAR16, :PCRE_SPTR16, :DWORD, :ptr DWORD, :DWORD
pcre32_utf32_to_host_byte_order proto  :ptr PCRE_UCHAR32, :PCRE_SPTR32, :DWORD, :ptr DWORD, :DWORD
pcre_jit_stack_alloc proto  :DWORD, :DWORD
pcre16_jit_stack_alloc proto  :DWORD, :DWORD
pcre32_jit_stack_alloc proto  :DWORD, :DWORD
pcre_jit_stack_free proto  :ptr pcre_jit_stack
pcre16_jit_stack_free proto  :ptr pcre16_jit_stack
pcre32_jit_stack_free proto  :ptr pcre32_jit_stack
pcre_assign_jit_stack proto  :ptr pcre_extra, :pcre_jit_callback, :ptr
pcre16_assign_jit_stack proto  :ptr pcre16_extra, :pcre16_jit_callback, :ptr
pcre32_assign_jit_stack proto  :ptr pcre32_extra, :pcre32_jit_callback, :ptr
pcre_jit_free_unused_memory proto
pcre16_jit_free_unused_memory proto
pcre32_jit_free_unused_memory proto


