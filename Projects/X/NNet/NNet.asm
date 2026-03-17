; ==================================================================================================
; Title:      NNet.asm
; Author:     Homer
; Version:    1.0.0
; Purpose:    ObjAsm Neural Network Application.
; Links:      https://de.wikipedia.org/wiki/Perzeptron    --> XOR problem
;             https://towardsdatascience.com/perceptrons-logical-functions-and-the-xor-problem-37ca5025790a
; Notes:      Version 1.0.0, October 2017
;               - Initial release.
; ==================================================================================================


%include @Environ(OBJASM_PATH)\\Code\\Macros\\Model.inc ;Include & initialize standard modules
SysSetup OOP, WIN64, WIDE_STRING, DEBUG(WND)            ;Load OOP files and OS related objects

% include &MacPath&fMath.inc                            ;Includes coprocessor math macros

MakeObjects Primer, .\NNet

include NNet_Globals.inc

.const
  Input0    NNT_DATATYPE  0.0, 0.0
  Input1    NNT_DATATYPE  0.0, 1.0
  Input2    NNT_DATATYPE  1.0, 0.0
  Input3    NNT_DATATYPE  1.0, 1.0

  Output0   NNT_DATATYPE  0.0
  Output1   NNT_DATATYPE  1.0
  Output2   NNT_DATATYPE  1.0
  Output3   NNT_DATATYPE  0.0


  XorNetInfo  NNT_INFO   <2,\                           ;Number of Inputs
                          1,\                           ;Number of Outputs
                          2,\                           ;Hidden layers
                          3>                            ;Neurons in each hidden layer

;      N0  N3
;  I0  N1  N4
;  I1  N2  N5  O

.code

ShowResults proc
  local dOutputValue:DWORD

  DbgLine
  OCall $ObjTmpl(NNet)::NNet.Run, addr Input0
  fld REAL8 ptr [xax]
  frndint
  fistp dOutputValue
  DbgDec dOutputValue, "= 0 xor 0"

  OCall $ObjTmpl(NNet)::NNet.Run, addr Input1
  fld REAL8 ptr [xax]
  frndint
  fistp dOutputValue
  DbgDec dOutputValue, "= 0 xor 1"

  OCall $ObjTmpl(NNet)::NNet.Run, addr Input2
  fld REAL8 ptr [xax]
  frndint
  fistp dOutputValue
  DbgDec dOutputValue, "= 1 xor 0"

  OCall $ObjTmpl(NNet)::NNet.Run, addr Input3
  fld REAL8 ptr [xax]
  frndint
  fistp dOutputValue
  DbgDec dOutputValue, "= 1 xor 1"

  ret
ShowResults endp


start proc uses xbx xdi
  SysInit
  DbgClearAll

  DbgWarning "--- Neural Network - XOR demo ---"

  OCall $ObjTmpl(NNet)::NNet.Init, NULL, addr XorNetInfo
  OCall $ObjTmpl(NNet)::NNet.InitRandom

  xor ebx, ebx
  .while ebx < 10
    ;Train the neural network with "expected" outputs
    ;  in order to calculate preferred weights
    xor edi, edi
    ;Train 2000 times
    .while edi < 2000                                   
      OCall $ObjTmpl(NNet)::NNet.Train, addr Input0, addr Output0
      OCall $ObjTmpl(NNet)::NNet.Train, addr Input1, addr Output1
      OCall $ObjTmpl(NNet)::NNet.Train, addr Input2, addr Output2
      OCall $ObjTmpl(NNet)::NNet.Train, addr Input3, addr Output3
      inc edi
    .endw
;    OCall $ObjTmpl(NNet)::NNet.ShowWeights, ebx
    invoke ShowResults

    inc ebx
  .endw
;  OCall $ObjTmpl(NNet)::NNet.ShowWeights, 1000
;  invoke ShowResults

  OCall $ObjTmpl(NNet)::NNet.Done

  SysDone
  invoke ExitProcess, 0
start endp

end
