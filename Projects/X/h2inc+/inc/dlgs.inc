;Include file created by h2inc+ version C.2.0 on (UTC) 25/05/2024 20:55:09
;(C) G. Friedrich April 2024
;Source file: d:\objasm\projects\x\h2inc+\h\um_10.0.22621.0\dlgs.h
;             Created on (UTC) 06/04/2024 06:15:53
;             Last modified on (UTC) 16/12/2023 11:07:42

include winapifamily.inc
ifndef _DLGSH_INCLUDED_
  _DLGSH_INCLUDED_ equ <>
  if WINAPI_FAMILY_PARTITION(WINAPI_PARTITION_DESKTOP)
    ctlFirst equ 0400h
    ctlLast equ 04ffh
    psh1 equ 0400h
    psh2 equ 0401h
    psh3 equ 0402h
    psh4 equ 0403h
    psh5 equ 0404h
    psh6 equ 0405h
    psh7 equ 0406h
    psh8 equ 0407h
    psh9 equ 0408h
    psh10 equ 0409h
    psh11 equ 040ah
    psh12 equ 040bh
    psh13 equ 040ch
    psh14 equ 040dh
    psh15 equ 040eh
    pshHelp equ <psh15>
    psh16 equ 040fh
    chx1 equ 0410h
    chx2 equ 0411h
    chx3 equ 0412h
    chx4 equ 0413h
    chx5 equ 0414h
    chx6 equ 0415h
    chx7 equ 0416h
    chx8 equ 0417h
    chx9 equ 0418h
    chx10 equ 0419h
    chx11 equ 041ah
    chx12 equ 041bh
    chx13 equ 041ch
    chx14 equ 041dh
    chx15 equ 041eh
    chx16 equ 041fh
    rad1 equ 0420h
    rad2 equ 0421h
    rad3 equ 0422h
    rad4 equ 0423h
    rad5 equ 0424h
    rad6 equ 0425h
    rad7 equ 0426h
    rad8 equ 0427h
    rad9 equ 0428h
    rad10 equ 0429h
    rad11 equ 042ah
    rad12 equ 042bh
    rad13 equ 042ch
    rad14 equ 042dh
    rad15 equ 042eh
    rad16 equ 042fh
    grp1 equ 0430h
    grp2 equ 0431h
    grp3 equ 0432h
    grp4 equ 0433h
    frm1 equ 0434h
    frm2 equ 0435h
    frm3 equ 0436h
    frm4 equ 0437h
    rct1 equ 0438h
    rct2 equ 0439h
    rct3 equ 043ah
    rct4 equ 043bh
    ico1 equ 043ch
    ico2 equ 043dh
    ico3 equ 043eh
    ico4 equ 043fh
    stc1 equ 0440h
    stc2 equ 0441h
    stc3 equ 0442h
    stc4 equ 0443h
    stc5 equ 0444h
    stc6 equ 0445h
    stc7 equ 0446h
    stc8 equ 0447h
    stc9 equ 0448h
    stc10 equ 0449h
    stc11 equ 044ah
    stc12 equ 044bh
    stc13 equ 044ch
    stc14 equ 044dh
    stc15 equ 044eh
    stc16 equ 044fh
    stc17 equ 0450h
    stc18 equ 0451h
    stc19 equ 0452h
    stc20 equ 0453h
    stc21 equ 0454h
    stc22 equ 0455h
    stc23 equ 0456h
    stc24 equ 0457h
    stc25 equ 0458h
    stc26 equ 0459h
    stc27 equ 045ah
    stc28 equ 045bh
    stc29 equ 045ch
    stc30 equ 045dh
    stc31 equ 045eh
    stc32 equ 045fh
    lst1 equ 0460h
    lst2 equ 0461h
    lst3 equ 0462h
    lst4 equ 0463h
    lst5 equ 0464h
    lst6 equ 0465h
    lst7 equ 0466h
    lst8 equ 0467h
    lst9 equ 0468h
    lst10 equ 0469h
    lst11 equ 046ah
    lst12 equ 046bh
    lst13 equ 046ch
    lst14 equ 046dh
    lst15 equ 046eh
    lst16 equ 046fh
    cmb1 equ 0470h
    cmb2 equ 0471h
    cmb3 equ 0472h
    cmb4 equ 0473h
    cmb5 equ 0474h
    cmb6 equ 0475h
    cmb7 equ 0476h
    cmb8 equ 0477h
    cmb9 equ 0478h
    cmb10 equ 0479h
    cmb11 equ 047ah
    cmb12 equ 047bh
    cmb13 equ 047ch
    cmb14 equ 047dh
    cmb15 equ 047eh
    cmb16 equ 047fh
    edt1 equ 0480h
    edt2 equ 0481h
    edt3 equ 0482h
    edt4 equ 0483h
    edt5 equ 0484h
    edt6 equ 0485h
    edt7 equ 0486h
    edt8 equ 0487h
    edt9 equ 0488h
    edt10 equ 0489h
    edt11 equ 048ah
    edt12 equ 048bh
    edt13 equ 048ch
    edt14 equ 048dh
    edt15 equ 048eh
    edt16 equ 048fh
    scr1 equ 0490h
    scr2 equ 0491h
    scr3 equ 0492h
    scr4 equ 0493h
    scr5 equ 0494h
    scr6 equ 0495h
    scr7 equ 0496h
    scr8 equ 0497h
    ctl1 equ 04A0h
    FILEOPENORD equ 1536
    MULTIFILEOPENORD equ 1537
    PRINTDLGORD equ 1538
    PRNSETUPDLGORD equ 1539
    FINDDLGORD equ 1540
    REPLACEDLGORD equ 1541
    FONTDLGORD equ 1542
    FORMATDLGORD31 equ 1543
    FORMATDLGORD30 equ 1544
    RUNDLGORD equ 1545
    if (WINVER ge 400h)
      PAGESETUPDLGORD equ 1546
      NEWFILEOPENORD equ 1547
      PRINTDLGEXORD equ 1549
      PAGESETUPDLGORDMOTIF equ 1550
      COLORMGMTDLGORD equ 1551
      NEWFILEOPENV2ORD equ 1552
    endif
    if (NTDDI_VERSION ge NTDDI_VISTA)
      NEWFILEOPENV3ORD equ 1553
    endif
    if (NTDDI_VERSION ge NTDDI_WIN7)
      NEWFORMATDLGWITHLINK equ 1591
      IDC_MANAGE_LINK equ 1592
    endif
    ifndef RC_INVOKED
      CRGB struct
        bRed BYTE ?
        bGreen BYTE ?
        bBlue BYTE ?
        bExtra BYTE ?
      CRGB ends
      tagCRGB typedef CRGB
    endif
  endif
endif
