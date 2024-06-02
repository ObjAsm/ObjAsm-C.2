;Include file created by h2inc+ version C.2.0 on (UTC) 25/05/2024 16:54:49
;(C) G. Friedrich April 2024
;Source file: d:\objasm\projects\x\h2inc+\h\um_10.0.22621.0\apiset.h
;             Created on (UTC) 22/05/2024 17:57:06
;             Last modified on (UTC) 12/02/2024 17:05:34

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
    if Defined(_API_SET_LEGACY_TARGET)
      API_SET macro X
        exitm <X = _API_SET_LEGACY_TARGET ##. ## X>
      endm
      API_SET_DIR macro X, DIR
        exitm <X = _API_SET_LEGACY_TARGET ##. ## X DIR>
      endm
      API_SET_BY_ORDINAL macro X, O, PO
        exitm <X = _API_SET_LEGACY_TARGET ##. ## PO @ ## O NONAME>
      endm
      API_SET_BY_ORDINAL_DIR macro X, O, PO, DIR
        exitm <X = _API_SET_LEGACY_TARGET ##. ## PO @ ## O NONAME DIR>
      endm
      API_SET_WITH_OPTIONAL_ORDINAL macro X, O, PO
        exitm <X = _API_SET_LEGACY_TARGET ##. ## PO @ ## O>
      endm
      API_SET_WITH_OPTIONAL_ORDINAL_DIR macro X, O, PO, DIR
        exitm <X = _API_SET_LEGACY_TARGET ##. ## PO @ ## O DIR>
      endm
      API_SET_LEGACY macro X, L
        exitm <X = L ##. ## X>
      endm
      API_SET_LEGACY_DIR macro X, L, DIR
        exitm <X = L ##. ## X DIR>
      endm
      API_SET_LEGACY_BY_ORDINAL macro X, L, O, PO
        exitm <X = L ##. ## PO @ ## O NONAME>
      endm
      API_SET_LEGACY_BY_ORDINAL_DIR macro X, L, O, PO, DIR
        exitm <X = L ##. ## PO @ ## O NONAME DIR>
      endm
      API_SET_LEGACY_WITH_OPTIONAL_ORDINAL macro X, L, O, PO
        exitm <X = L ##. ## PO @ ## O>
      endm
      API_SET_LEGACY_WITH_OPTIONAL_ORDINAL_DIR macro X, L, O, PO, DIR
        exitm <X = L ##. ## PO @ ## O DIR>
      endm
    elseif Defined(_API_SET_FORWARDER_TARGET)
      API_SET macro X
        exitm <X = _API_SET_FORWARDER_TARGET ##. ## X>
      endm
      API_SET_DIR macro X, DIR
        exitm <X = _API_SET_FORWARDER_TARGET ##. ## X DIR>
      endm
      API_SET_BY_ORDINAL macro X, O, PO
        exitm <X = _API_SET_FORWARDER_TARGET ##. ## PO @ ## O NONAME>
      endm
      API_SET_BY_ORDINAL_DIR macro X, O, PO, DIR
        exitm <X = _API_SET_FORWARDER_TARGET ##. ## PO @ ## O NONAME DIR>
      endm
      API_SET_WITH_OPTIONAL_ORDINAL macro X, O, PO
        exitm <X = _API_SET_FORWARDER_TARGET ##. ## PO @ ## O>
      endm
      API_SET_WITH_OPTIONAL_ORDINAL_DIR macro X, O, PO, DIR
        exitm <X = _API_SET_FORWARDER_TARGET ##. ## PO @ ## O DIR>
      endm
      API_SET_LEGACY macro X, L
        exitm <X = _API_SET_FORWARDER_TARGET ##. ## X>
      endm
      API_SET_LEGACY_DIR macro X, L, DIR
        exitm <X = _API_SET_FORWARDER_TARGET ##. ## X DIR>
      endm
      API_SET_LEGACY_BY_ORDINAL macro X, L, O, PO
        exitm <X = _API_SET_FORWARDER_TARGET ##. ## PO @ ## O NONAME>
      endm
      API_SET_LEGACY_BY_ORDINAL_DIR macro X, L, O, PO, DIR
        exitm <X = _API_SET_FORWARDER_TARGET ##. ## PO @ ## O NONAME DIR>
      endm
      API_SET_LEGACY_WITH_OPTIONAL_ORDINAL macro X, L, O, PO
        exitm <X = _API_SET_FORWARDER_TARGET ##. ## PO @ ## O>
      endm
      API_SET_LEGACY_WITH_OPTIONAL_ORDINAL_DIR macro X, L, O, PO, DIR
        exitm <X = _API_SET_FORWARDER_TARGET ##. ## PO @ ## O DIR>
      endm
    else
      API_SET macro X
        exitm <X>
      endm
      API_SET_DIR macro X, DIR
        exitm <X DIR>
      endm
      API_SET_BY_ORDINAL macro X, O, PO
        exitm <X @ ## O NONAME>
      endm
      API_SET_BY_ORDINAL_DIR macro X, O, PO, DIR
        exitm <X @ ## O NONAME DIR>
      endm
      API_SET_WITH_OPTIONAL_ORDINAL macro X, O, PO
        exitm <X @ ## O>
      endm
      API_SET_WITH_OPTIONAL_ORDINAL_DIR macro X, O, PO, DIR
        exitm <X @ ## O DIR>
      endm
      API_SET_LEGACY macro X, L
        exitm <X>
      endm
      API_SET_LEGACY_DIR macro X, L, DIR
        exitm <X DIR>
      endm
      API_SET_LEGACY_BY_ORDINAL macro X, L, O, PO
        exitm <X @ ## O NONAME>
      endm
      API_SET_LEGACY_BY_ORDINAL_DIR macro X, L, O, PO, DIR
        exitm <X @ ## O NONAME DIR>
      endm
      API_SET_LEGACY_WITH_OPTIONAL_ORDINAL macro X, L, O, PO
        exitm <X @ ## O>
      endm
      API_SET_LEGACY_WITH_OPTIONAL_ORDINAL_DIR macro X, L, O, PO, DIR
        exitm <X @ ## O DIR>
      endm
    endif
    API_SET_LIBRARY macro X
      exitm <LIBRARY X>
    endm
  endif
endif
