;Include file created by h2incX, Version B.01.01, 10/09/2018 22:03
;(C) 2018-today by Biterider, 2005-2009 by Japheth
;Source file: '\ObjAsm\Projects\h2IncX\header\apiset.h', last modified: 19/04/2018 10:43
;Creation parameters: 

ifndef _API_SET_H_
  _API_SET_H_ equ <>
  API_SET_OVERRIDE macro X
    exitm <X ## Implementation>
  endm
  API_SET_LEGACY_OVERRIDE_DEF macro X
    exitm <X = API_SET_OVERRIDE(X)>
  endm
  API_SET_OVERRIDE_DEF macro X
    exitm <API_SET_LEGACY_OVERRIDE_DEF(X) PRIVATE>
  endm
  ifdef _M_HYBRID_X86_ARM64
    API_SET_CHPE_GUEST equ <X86>
  else
    API_SET_CHPE_GUEST equ <>
  endif
  ifdef _API_SET_HOST
    ;[...]
  else
    ifndef _API_SET_LEGACY_TARGET
      API_SET macro X
        exitm <X>
      endm
      API_SET_DIR macro X, DIR
        exitm <X DIR>
      endm
      API_SET_PRIVATE macro X
        exitm <X PRIVATE>
      endm
      API_SET_PRIVATE_DIR macro X, DIR
        exitm <X DIR PRIVATE>
      endm
      API_SET_BY_ORDINAL macro X, O, PO
        exitm <X @ ## O NONAME>
      endm
      API_SET_BY_ORDINAL_DIR macro X, O, PO, DIR
        exitm <X @ ## O NONAME DIR>
      endm
      API_SET_BY_ORDINAL_PRIVATE macro X, O, PO
        exitm <X @ ## O NONAME PRIVATE>
      endm
      API_SET_BY_ORDINAL_PRIVATE_DIR macro X, O, PO, DIR
        exitm <X @ ## O NONAME DIR PRIVATE>
      endm
      API_SET_LEGACY macro X, L
        exitm <X>
      endm
      API_SET_LEGACY_DIR macro X, L, DIR
        exitm <X DIR>
      endm
      API_SET_LEGACY_PRIVATE macro X, L
        exitm <X PRIVATE>
      endm
      API_SET_LEGACY_PRIVATE_DIR macro X, L, DIR
        exitm <X DIR PRIVATE>
      endm
      API_SET_LEGACY_BY_ORDINAL macro X, L, O, PO
        exitm <X @ ## O NONAME>
      endm
      API_SET_LEGACY_BY_ORDINAL_DIR macro X, L, O, PO, DIR
        exitm <X @ ## O NONAME DIR>
      endm
      API_SET_LEGACY_BY_ORDINAL_PRIVATE macro X, L, O, PO
        exitm <X @ ## O NONAME PRIVATE>
      endm
      API_SET_LEGACY_BY_ORDINAL_PRIVATE_DIR macro X, L, O, PO, DIR
        exitm <X @ ## O NONAME DIR PRIVATE>
      endm
    else
      API_SET macro X
        exitm <X = _API_SET_LEGACY_TARGET ##. ## X>
      endm
      API_SET_DIR macro X, DIR
        exitm <X = _API_SET_LEGACY_TARGET ##. ## X DIR>
      endm
      API_SET_PRIVATE macro X
        exitm <X = _API_SET_LEGACY_TARGET ##. ## X PRIVATE>
      endm
      API_SET_PRIVATE_DIR macro X, DIR
        exitm <X = _API_SET_LEGACY_TARGET ##. ## X DIR PRIVATE>
      endm
      API_SET_BY_ORDINAL macro X, O, PO
        exitm <X = _API_SET_LEGACY_TARGET ##. ## PO @ ## O NONAME>
      endm
      API_SET_BY_ORDINAL_DIR macro X, O, PO, DIR
        exitm <X = _API_SET_LEGACY_TARGET ##. ## PO @ ## O NONAME DIR>
      endm
      API_SET_BY_ORDINAL_PRIVATE macro X, O, PO
        exitm <X = _API_SET_LEGACY_TARGET ##. ## PO @ ## O NONAME PRIVATE>
      endm
      API_SET_BY_ORDINAL_PRIVATE_DIR macro X, O, PO, DIR
        exitm <X = _API_SET_LEGACY_TARGET ##. ## PO @ ## O NONAME DIR PRIVATE>
      endm
      API_SET_LEGACY macro X, L
        exitm <X = L ##. ## X>
      endm
      API_SET_LEGACY_DIR macro X, L, DIR
        exitm <X = L ##. ## X DIR>
      endm
      API_SET_LEGACY_PRIVATE macro X, L
        exitm <X = L ##. ## X PRIVATE>
      endm
      API_SET_LEGACY_PRIVATE_DIR macro X, L, DIR
        exitm <X = L ##. ## X DIR PRIVATE>
      endm
      API_SET_LEGACY_BY_ORDINAL macro X, L, O, PO
        exitm <X = L ##. ## PO @ ## O NONAME>
      endm
      API_SET_LEGACY_BY_ORDINAL_DIR macro X, L, O, PO, DIR
        exitm <X = L ##. ## PO @ ## O NONAME DIR>
      endm
      API_SET_LEGACY_BY_ORDINAL_PRIVATE macro X, L, O, PO
        exitm <X = L ##. ## PO @ ## O NONAME PRIVATE>
      endm
      API_SET_LEGACY_BY_ORDINAL_PRIVATE_DIR macro X, L, O, PO, DIR
        exitm <X = L ##. ## PO @ ## O NONAME DIR PRIVATE>
      endm
    endif
    API_SET_LIBRARY macro X
      exitm <LIBRARY X>
    endm
  endif
endif

