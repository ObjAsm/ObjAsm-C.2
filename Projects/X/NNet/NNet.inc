; ==================================================================================================
; Title:      Demo10.asm
; Author:     T.Bleek's NeuralNetwork. Ported by Homer (2005).
; Version:    C.1.0
; Purpose:    ObjAsm Neural Network implementation.
; Links:      https://en.wikipedia.org/wiki/Neural_circuit
;             https://en.wikipedia.org/wiki/Artificial_neural_network
;             https://en.wikipedia.org/wiki/Backpropagation
;             https://en.wikipedia.org/wiki/Perceptron
;             https://en.wikipedia.org/wiki/Deep_learning
; Notes:      Version C.1.0, October 2017
;               - First release.
; ==================================================================================================



NNT_INFO_MEMUSE           equ   1       ;Total memory use of network data
NNT_INFO_TOTALNEURONS     equ   2       ;Total number of neurons in network
NNT_INFO_CONNECTIONS      equ   3       ;Total number of connections in network
NNT_INFO_SERDATASIZE      equ   4       ;Total data size of serialized network (for save method)

NNT_FLAG_TOFILE           equ   1       ;Output data to file, Destination is file HANDLE
NNT_FLAG_TOMEM            equ   2       ;Output data to memory, Destination is POINTER to memory
NNT_FLAG_FROMFILE         equ   4       ;Read data from file, Source is file HANDLE
NNT_FLAG_FROMMEM          equ   8       ;Read data from mem, Source is mem POINTER

NNT_ERR_NOERROR           equ   0       ;No error has occurred
NNT_ERR_INVALIDPARAM      equ   1       ;Invalid parameter
NNT_ERR_FILEACCESS        equ   2       ;File access failed (write or read)
NNT_ERR_INVALIDDATA       equ   3       ;Invalid serialized data

NNT_INFO struc
  dNetInputs      DWORD     ?           ;Number of input neurons
  dNetOutputs     DWORD     ?           ;Number of output neurons
  dHiddenLayers   DWORD     ?           ;Number of hidden layers
  dHiddenNeurons  DWORD     ?           ;Number of neurons in one hidden layer
NNT_INFO ends
PNNT_INFO typedef ptr NNT_INFO


;        Neural Network
;        --------------
;
;         Hidden Layers                   Weight Matrix        Output Matrix
;
;         N  x  N  x  N          1)| 2)|   W  W  W  W     3)|  S  S  S  S  S
;       / N  x  N  x  N \          |   |   W  W  W  W       |  S  S  S  S  S
;    I /  N  x  N  x  N  \         |   |   W  W  W  W       |  S  S  S  S  S     I: Network Inputs
;    I    N  x  N  x  N   \        |   |   W  W  W  W       |  S  S  S  S  S     O: Network Outputs
;    I    N  x  N  x  N    O       V   |   W  W  W  W       |  S  S  S  S  S     N: Neutrons
;    I    N  x  N  x  N    O           |   W  W  W  W       |  S  S  S  S  S     x: Connections
;    I    N  x  N  x  N    O           |   W  W  W  W       |  S  S  S  S  S     W: Weights
;    I    N  x  N  x  N   /            |   .  .  .  .       |  S  S  S  S  S     B: Bias
;    I \  N  x  N  x  N  / ^           |   .  .  .  .       |  S  S  S  S  S     S: Neuron output
;       \ N  x  N  x  N /  |           |   .  .  .  .       |  S  S  S  S  S     ?: Unused values
;    ^    N  x  N  x  N    |           |   W  W  W  W       |  S  S  S  S  S
;    |                     |           |   W  W  W  W       V  ?  B  B  B  ?     1) xWeightSkip
; Network               Network        V   W  W  W  W                            2) xOutputLayerSkip
; Input                 Output                                                   3) xOutputLayerSkip
; Values                Values             ^  ^  ^  ^
;                                          |  |  |  |
;                   Hidden Layer weights --------'  '-- Output weights



; --------------------------------------------------------------------------------------------------

NNetID equ 48302

Object NNet, NNetID, Primer
  VirtualMethod     ShowWeights,        DWORD
  VirtualMethod     BackPropagate
  VirtualMethod     CalcOutputs
  VirtualMethod     CalcOutputDeltas,   POINTER
  RedefineMethod    Done
  VirtualMethod     GetInfo,            DWORD
  RedefineMethod    Init,               POINTER, PNNT_INFO
  VirtualMethod     InitRandom
  VirtualMethod     Load,               DWORD, XWORD
  VirtualMethod     Run,                POINTER
  VirtualMethod     Train,              POINTER, POINTER
  VirtualMethod     Save,               DWORD, XWORD

  DefineVariable    dNetInputs,         DWORD,    0
  DefineVariable    dNetOutputs,        DWORD,    0
  DefineVariable    dHiddenLayers,      DWORD,    0
  DefineVariable    dHiddenNeurons,     DWORD,    0
  DefineVariable    dLayerNeurons,      DWORD,    0       ;Max number of neurons on one layer (of all layers)
  DefineVariable    dLayerWeights,      DWORD,    0       ;Number of weights for one layer transition
  DefineVariable    dTotalWeights,      DWORD,    0

  DefineVariable    pOutputArr,         POINTER,  NULL    ;Output array
  DefineVariable    pWeightArr,         POINTER,  NULL    ;Weights array
  DefineVariable    pDeltaArr,          POINTER,  NULL    ;Temporary delta array
  DefineVariable    dOutputArrSize,     DWORD,    0       ;Size of output array
  DefineVariable    dWeightArrSize,     DWORD,    0       ;Size of weight array
  DefineVariable    dDeltaArrSize,      DWORD,    0       ;Size of delta array
  DefineVariable    xWeightSkip,        XWORD,    0       ;Skip weights of one neuron
  DefineVariable    xWeightLayerSkip,   XWORD,    0       ;Skip a complete Weight layer
  DefineVariable    xOutputLayerSkip,   XWORD,    0       ;Skip a complete Output layer


  DefineVariable    r4LearnCoeff,       REAL4,    0.5     ;Learning coefficient
ObjectEnd


; ==================================================================================================
;    NNet implementation
; ==================================================================================================

if IMPLEMENT

NNT_DATATYPE              textequ   <REAL8>
NNT_DATATYPE_SIZE         =  sizeof(NNT_DATATYPE)
NNT_LOG2_DATATYPE_SIZE    =  $Log2(NNT_DATATYPE_SIZE)

NNT_HEADER struc
  dMagic        DWORD     ?           ;Always "NNET" as DWORD (4E4E4554h)
  dWeights      DWORD     ?           ;Size of weight array
NNT_HEADER ends


.code

; --------------------------------------------------------------------------------------------------

Method NNet.ShowWeights, uses xbx xdi xsi, dWindow:DWORD
  local cWindow[100]:CHR, cFloat[100]:CHR

  SetObject xsi
  invoke dword2hex, addr cWindow, dWindow

  mov ebx, [xsi].dTotalWeights
  mov xdi, [xsi].pWeightArr
  test ebx, ebx
  .while !ZERO?
    fld NNT_DATATYPE ptr [xdi + NNT_DATATYPE*xbx]
    invoke St0ToStrA, addr cFloat, 0, DBG_FLOAT_RESOLUTION, 1
    invoke DbgOutTextA, addr cFloat, DbgColorForeground, DbgColorBackground, DBG_EFFECT_NORMAL or DBG_EFFECT_NEWLINE, addr cWindow
    fUnload
    dec ebx
  .endw
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     NNet.BackPropagate
; Purpose:    Backpropagation process.
; Arguments:  None.
; Return:     Nothing.

Method NNet.BackPropagate, uses xbx xdi xsi
  local dLeftNeurons:DWORD, dRightNeurons:DWORD
  local pCurLayerWeights:POINTER, pCurOutputs:POINTER
  local dCurLayer:DWORD, bSwapFlag:DWORD
  local xWeightSkip:XWORD

  SetObject xsi

  m2z bSwapFlag
  m2m xWeightSkip, [xsi].xWeightSkip, xax

  mov eax, [xsi].dWeightArrSize
  add xax, [xsi].pWeightArr
  sub xax, [xsi].xWeightLayerSkip                       ;Move to last layer transition
  mov pCurLayerWeights, xax

  mov eax, [xsi].dOutputArrSize
  add xax, [xsi].pOutputArr
  sub xax, [xsi].xOutputLayerSkip                       ;2 layers
  sub xax, [xsi].xOutputLayerSkip
  mov pCurOutputs, xax

  ;dCurLayer: current transition calculated: dCurLayer=0 means transition from layer1 to 2.
  mov eax, [xsi].dHiddenLayers
  inc eax
  mov dCurLayer, eax
  test eax, eax
  .while !ZERO?
    mov ecx, dCurLayer
    dec ecx                                             ;ecx = dCurLayer here

    ;Get number of neurons in current left layer
    .if ecx == 0
      mov edx, [xsi].dNetInputs
    .else
      mov edx, [xsi].dHiddenNeurons
    .endif
    inc edx                                             ;Add 1 for Bias
    mov dLeftNeurons, edx

    ;Get number of neurons in current right layer
    .if ecx == [xsi].dHiddenLayers
      mov edx, [xsi].dNetOutputs
    .else
      mov edx, [xsi].dHiddenNeurons
    .endif
    inc edx                                             ;Add 1 for Bias
    mov dRightNeurons, edx

    mov xdi, [xsi].pDeltaArr
    mov xdx, xdi
    mov xax, [xsi].xOutputLayerSkip
    .if bSwapFlag
      add xdi, xax
    .else
      add xdx, xax
    .endif

    mov xax, pCurLayerWeights

    ;xdi -> delta array of right layer [in]
    ;xdx -> delta array of left layer [out]
    ;xax -> current layer weights array [in]

    ; --- loop through all neurons in current (left) layer ---
    mov xsi, pCurOutputs
    ;xsi -> output array of left layer [in]

    ; --- calculate left layer deltas loop ---
    xor ebx, ebx
    .while ebx < dLeftNeurons
      xor ecx, ecx
      fldz                                              ;Start with zero for SUM
      inc ecx                                           ;Add 1 to skip Bias
      .while ecx < dRightNeurons
        fld NNT_DATATYPE ptr [xax + NNT_DATATYPE_SIZE*xcx - NNT_DATATYPE_SIZE] ;Load weight value (- is for the 1 in (i-1))
        fmul NNT_DATATYPE ptr  [xdi + NNT_DATATYPE_SIZE*xcx]  ;Multiply by delta value of right neuron
        faddp st(1), st(0)                              ;Add to current sum
        inc ecx
      .endw

      fld NNT_DATATYPE ptr [xsi + NNT_DATATYPE_SIZE*xbx];Load output value of left neuron
      fld1
      fsub st(0), st(1)
      fmulp st(1), st(0)
      fmulp st(1), st(0)                                ;Out*[1 - out]
      fstp NNT_DATATYPE ptr [xdx + NNT_DATATYPE_SIZE*xbx] ;Store delta value for neuron in left layer
      add xax, xWeightSkip
      inc ebx
    .endw

    mov xdx, xsi                                        ;xdx takes over xsi (-> output array of left layer)
    mov xsi, pSelf

    mov xax, pCurLayerWeights

    ;xdi -> delta array of right layer [in]
    ;xdx -> output array of left layer [in]
    ;xax -> current layer weights array [out]

    fld [xsi].r4LearnCoeff                              ;Load learning coefficient
    ; --- adjust weights loop ---
    xor ebx, ebx
    .while ebx < dLeftNeurons
      xor ecx, ecx
      inc ecx                                           ;Add 1 to skip Bias
      .while ecx < dRightNeurons
        fld NNT_DATATYPE ptr [xdx + NNT_DATATYPE_SIZE*xbx]  ;Load output of left neuron
        fmul NNT_DATATYPE ptr [xdi + NNT_DATATYPE_SIZE*xcx] ;Multiply by delta value of right neuron
        fmul st(0), st(1)                                   ;Multiply by learning coefficient
        fadd NNT_DATATYPE ptr [xax + NNT_DATATYPE_SIZE*xcx - NNT_DATATYPE_SIZE]  ;Add delta to old weight value
        fstp NNT_DATATYPE ptr [xax + NNT_DATATYPE_SIZE*xcx - NNT_DATATYPE_SIZE]  ;Store new delta value
        inc ecx
      .endw
      add xax, [xsi].xWeightSkip
      inc ebx
    .endw
    fstp st(0)                                          ;Remove learning coefficient

    mov xax, [xsi].xWeightLayerSkip
    sub pCurLayerWeights, xax
    mov xax, [xsi].xOutputLayerSkip
    sub pCurOutputs, xax

    xor bSwapFlag, 1

    dec dCurLayer
  .endw
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     NNet.CalcOutputs
; Purpose:    Calculate output values.
; Arguments:  None.
; Return:     Nothing.

Method NNet.CalcOutputs, uses xbx xdi xsi
  local dLeftNeurons:DWORD, dRightNeurons:DWORD
  local pCurLayerWeights:POINTER, dCurLayer:DWORD

  SetObject xsi

  m2m pCurLayerWeights, [xsi].pWeightArr, xax

  mov xdi, [xsi].pOutputArr
  ;dCurLayer: current transition (dCurLayer=0 means transition from layer1 to 2)

  xor ecx, ecx
  mov dCurLayer, ecx
  .while ecx <= [xsi].dHiddenLayers                     ;ecx = dCurLayer here
    ;Get number of neurons in current left layer
    .if ecx == 0
      mov edx, [xsi].dNetInputs
    .else
      mov edx, [xsi].dHiddenNeurons
    .endif
    inc edx                                             ;Add 1 for Bias
    mov dLeftNeurons, edx

    ;Get number of neurons in current right layer
    .if ecx == [xsi].dHiddenLayers
      mov edx, [xsi].dNetOutputs
    .else
      mov edx, [xsi].dHiddenNeurons
    .endif
    inc edx                                             ;Add 1 for Bias
    mov dRightNeurons, edx

    mov xdx, xdi
    add xdx, [xsi].xOutputLayerSkip

    ;xsi -> current layer output data
    ;xdx -> next layer output data

    ; --- loop through all neurons in next (right) layer ---
    xor ebx, ebx
    inc ebx                                             ;Bias is not outputted
    .while ebx < dRightNeurons
      lea eax, [NNT_DATATYPE_SIZE*ebx - NNT_DATATYPE_SIZE]
      add xax, pCurLayerWeights

      fld1
      fst NNT_DATATYPE ptr [xdx]                        ;Bias value = 1.0

      fldz
      xor ecx, ecx
      .while ecx < dLeftNeurons
        fld NNT_DATATYPE ptr [xax]                      ;Load weight value
        fmul NNT_DATATYPE ptr [xdi + NNT_DATATYPE_SIZE*xcx] ;Load input value
        add xax, [xsi].xWeightSkip
        faddp st(1), st(0)
        inc ecx
      .endw
      fchs
      fExpN
      fadd st(0), st(1)
      fdivp st(1), st(0)

      fstp NNT_DATATYPE ptr [xdx + NNT_DATATYPE_SIZE*xbx]

      inc ebx
    .endw

    mov xax, [xsi].xWeightLayerSkip
    add pCurLayerWeights, xax

    mov xcx, [xsi].xOutputLayerSkip
    add xdi, xcx

    inc dCurLayer
    mov ecx, dCurLayer
  .endw
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     NNet.CalcOutputDeltas
; Purpose:    Calculate output delta values.
; Arguments:  Arg1: -> Output values.
; Return:     Nothing.

Method NNet.CalcOutputDeltas, uses xbx xdi, pOutputs:POINTER
  SetObject xcx

  ;delta = y*[1 - y]*[d - y]
  mov edi, NNT_DATATYPE_SIZE                            ;Skip last Bias
  add edi, [xcx].dOutputArrSize
  sub xdi, [xcx].xOutputLayerSkip
  add xdi, [xcx].pOutputArr

  mov xdx, [xcx].pDeltaArr
  mov xbx, pOutputs

  ;xdi -> produced output array (index 1, Bias value skipped)
  ;xbx -> desired output array
  ;xdx -> delta array.
  xor eax, eax
  .while eax < [xcx].dNetOutputs
    fld NNT_DATATYPE ptr [xdi + NNT_DATATYPE_SIZE*xax]  ;Load y
    fld NNT_DATATYPE ptr [xbx + NNT_DATATYPE_SIZE*xax]  ;Load d
    fsub st(0), st(1)                                   ;st(0) = d - y, st(1) = y
    fld1
    fsub st(0), st(2)                                   ;st(0) = 1 - y, st(1) = d - y, st(2) = y
    fmulp st(1), st(0)                                  ;st(0) = [d - y]*[1 - y], st(1) = y
    fmulp st(1), st(0)                                  ;st(0) = y*[1 - y]*[d - y] = delta
    fstp NNT_DATATYPE ptr [xdx + NNT_DATATYPE_SIZE*xax + NNT_DATATYPE_SIZE]  ;Store delta
    inc eax
  .endw
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     NNet.Done
; Purpose:    Finalize the neural network.
; Arguments:  None.
; Return:     Nothing.

Method NNet.Done, uses xsi
  SetObject xsi
  .if [xsi].pOutputArr != NULL
    MemFree [xsi].pOutputArr
  .endif
  .if [xsi].pWeightArr != NULL
    MemFree [xsi].pWeightArr
  .endif
  .if [xsi].pDeltaArr != NULL
    MemFree [xsi].pDeltaArr
  .endif
  ACall xsi.Done
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     NNet.GetInfo
; Purpose:    Retievs information of the neural net.
; Arguments:  Arg1: Information type. NNT_INFO_xxx
; Return:     eax = requested information.

Method NNet.GetInfo, uses xsi, dType:DWORD
  SetObject xsi

  mov eax, dType
  .if eax == NNT_INFO_MEMUSE
    mov eax, [xsi].dWeightArrSize
    add eax, [xsi].dDeltaArrSize
    add eax, [xsi].dOutputArrSize

  .elseif eax == NNT_INFO_TOTALNEURONS
    mov eax, [xsi].dHiddenLayers
    mul [xsi].dHiddenNeurons
    add eax, [xsi].dNetInputs
    add eax, [xsi].dNetOutputs

  .elseif  eax == NNT_INFO_SERDATASIZE
    mov eax, [xsi].dWeightArrSize
    add eax, sizeof NNT_HEADER

  .elseif eax == NNT_INFO_CONNECTIONS
    mov eax, [xsi].dNetInputs
    inc eax
    mul [xsi].dHiddenNeurons
    mov ecx, eax
    mov eax, [xsi].dHiddenLayers
    .if eax > 1
      dec eax
      mov edx, [xsi].dHiddenNeurons
      inc edx
      mul edx
      mul [xsi].dHiddenNeurons
      add ecx, eax
    .endif
    mov eax, [xsi].dHiddenNeurons
    inc eax
    mul [xsi].dNetOutputs
    add eax, ecx

  .else
    OCall xsi.ErrorReport, NULL, NNT_ERR_INVALIDPARAM
    mov eax, -1

  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     NNet.Init
; Purpose:    Initialize the neural network.
; Arguments:  Arg1: -> Owner.
;             Arg2: -> Neural Net Info.
; Return:     Nothing.

Method NNet.Init, uses xsi, pOwner:POINTER, pNNInfo:PNNT_INFO
  SetObject xsi
  ACall xsi.Init, pOwner

  mov xcx, pNNInfo
  assume xcx:ptr NNT_INFO

  DbgLine

  ; --- Number of input neurons ---
  mrm [xsi].dNetInputs, [xcx].dNetInputs, eax
  mov edx, eax                                          ;Store #inputs in edx
  DbgDec eax, "Number of input neurons"

  ; --- Number of output neurons ---
  mrm [xsi].dNetOutputs, [xcx].dNetOutputs, eax
  .if eax > edx
    mov edx, eax                                        ;Store #outputs in edx if bigger than #inputs
  .endif

  DbgDec eax, "Number of output neurons"
  DbgLine

  ; --- Number of hidden neurons per layer ---
  mrm [xsi].dHiddenNeurons, [xcx].dHiddenNeurons, eax
  .if eax > edx
    mov edx, eax                                        ;Store #hidden in edx if bigger than #inputs & #outputs
  .endif
  mov [xsi].dLayerNeurons, edx                          ;Max neurons per layer (max of input, output and hidden)

  DbgDec edx, "Number of hidden neurons per layer"

  ; --- Hidden layers ---
  mrm [xsi].dHiddenLayers, [xcx].dHiddenLayers, eax
  DbgDec eax, "Number of hidden layers"

  assume xcx:NOTHING

  ; --- allocate memory for outputs ---

  ;hiddenlayers + 2 = total number of layers
  add eax, 2
  DbgDec eax, "Total number of layers"
  DbgLine
  inc edx                                               ;Add one to max neurons per layer, for Bias.
  mul edx                                               ;total layers * (max neurons per layer + 1) = total output values

  DbgDec eax, "Total number of output values = (neuronsperlayer + 1 * totallayers)"
  shl eax, NNT_LOG2_DATATYPE_SIZE
  mov [xsi].dOutputArrSize, eax

  mov [xsi].pOutputArr, $MemAlloc(eax, MEM_INIT_ZERO)

  ; --- allocate memory for weights ---

  mov eax, [xsi].dLayerNeurons
  mov ecx, eax
  inc ecx                                               ;Add 1 for Bias
  mul ecx                                               ;(layerneurons + 1)*(layerneurons)
  mov [xsi].dLayerWeights, eax
  DbgDec eax, "Total number of weights per layer"
  mov ecx, [xsi].dHiddenLayers
  inc ecx                                               ;(hiddenlayers + 1) = (totallayers - 1)
  mul ecx                                               ;(totallayers - 1)*(layerneurons + 1)*(layerneurons)
  DbgDec eax,"Total number of weights for all layers"
  mov [xsi].dTotalWeights, eax
  shl eax, NNT_LOG2_DATATYPE_SIZE
  mov [xsi].dWeightArrSize, eax
  mov [xsi].pWeightArr, $MemAlloc(eax)

  ; --- allocate memory for temp delta array ---

  mov eax, [xsi].dLayerNeurons
  inc eax                                               ;Add one for Bias
  shl eax, NNT_LOG2_DATATYPE_SIZE + 1                   ;*2 (current&next)*NNT_DATATYPE_SIZE
  mov [xsi].pDeltaArr, $MemAlloc(eax, MEM_INIT_ZERO)

  mov eax, [xsi].dLayerNeurons
  shl eax, NNT_LOG2_DATATYPE_SIZE
  mov [xsi].xWeightSkip, xax                            ;Bytes to skip to next neuron

  add eax, NNT_DATATYPE_SIZE
  mov [xsi].xOutputLayerSkip, xax                       ;Bytes to skip to next output layer

  mov eax, [xsi].dLayerWeights
  shl eax, NNT_LOG2_DATATYPE_SIZE
  mov [xsi].xWeightLayerSkip, xax                       ;Bytes to skip to next weight layer

MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     NNet.InitRandom
; Purpose:    Fill Weights array with random floats (-1 thru +1).
; Arguments:  None.
; Return:     Nothing.

NNT_INIT_RANGE = 07FFFFFFFh

Method NNet.InitRandom, uses xbx xdi
  local dValue:DWORD

;  DbgLine
  SetObject xcx
  mov xdi, [xcx].pWeightArr
  mov ebx, [xcx].dTotalWeights

  ;Fill with floats between -1.0 and +1.0
  test ebx, ebx
  .while !ZERO?
    invoke Random32, NNT_INIT_RANGE
    mov dValue, eax
    fild dValue
    mov dValue, NNT_INIT_RANGE / 2
    fild dValue
    fdivp
    fld1
    fsubp st(1), st(0)
    fstp NNT_DATATYPE ptr [xdi]
;    DbgFloat NNT_DATATYPE ptr [xdi]
    add xdi, NNT_DATATYPE_SIZE
    dec ebx
  .endw
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     NNet.Load
; Purpose:    Lead the neural net from a stream.
; Arguments:  Arg1: Flags.
;             Arg2: HANDLE or POINTER.
; Return:     Nothing.

Method NNet.Load, uses xsi, dFlags:DWORD, Source:XWORD
  local NetHeader:NNT_HEADER, dBytesRead:DWORD

  SetObject xsi
  mov ecx, dFlags
  .if (ecx & NNT_FLAG_FROMFILE)
    invoke ReadFile, Source, addr NetHeader, sizeof NetHeader, addr dBytesRead, 0
    .if (!eax) || (dBytesRead != sizeof NetHeader)
      OCall xsi.ErrorReport, NULL, NNT_ERR_FILEACCESS
      xor eax, eax
      ExitMethod
    .endif
    mov eax, NetHeader.dWeights
    .if (NetHeader.dMagic != "NNET" || eax != [xsi].dWeightArrSize)
      OCall xsi.ErrorReport, NULL, NNT_ERR_INVALIDDATA
      xor eax, eax
      ExitMethod
    .endif
    invoke ReadFile, Source, [xsi].pWeightArr, [xsi].dWeightArrSize, addr dBytesRead, 0
    mov ecx, NetHeader.dWeights
    .if (!eax) || (dBytesRead != ecx)
      OCall xsi.ErrorReport, NULL, NNT_ERR_FILEACCESS
      xor eax, eax
      ExitMethod
    .endif
    xor eax, eax
    inc eax

  .elseif (ecx & NNT_FLAG_FROMMEM)
    mov xdx, Source
    assume xdx:ptr NNT_HEADER
    mov eax, [xdx].dWeights
    .if ([xdx].dMagic != "NNET" || eax != [xsi].dWeightArrSize)
      OCall xsi.ErrorReport, NULL, NNT_ERR_INVALIDDATA
      xor eax, eax
      ExitMethod
    .endif
    assume xdx:NOTHING
    add xdx, NNT_DATATYPE_SIZE
    invoke MemClone, [xsi].pWeightArr, xdx, [xsi].dWeightArrSize
    xor eax, eax
    inc eax

  .else
    OCall xsi.ErrorReport, NULL, NNT_ERR_INVALIDPARAM
    xor eax, eax

  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     NNet.Run
; Purpose:    Run the neural netword with a given set of input values.
; Arguments:  Arg1: -> Input values.
; Return:     xax -> Output array.

Method NNet.Run, uses xsi, pInputs:POINTER
  SetObject xsi

  ; --- Copy inputs ---
  mov ecx, NNT_DATATYPE_SIZE                            ;Skip first Bias value
  add xcx, [xsi].pOutputArr
  mov eax, [xsi].dNetInputs
  shl eax, NNT_LOG2_DATATYPE_SIZE
  invoke MemClone, xcx, pInputs, eax

  OCall xsi.CalcOutputs
  mov eax, [xsi].dOutputArrSize
  add eax, NNT_DATATYPE_SIZE
  sub xax, [xsi].xOutputLayerSkip
  add xax, [xsi].pOutputArr
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     NNet.Save
; Purpose:    Save the neural net on a stream.
; Arguments:  Arg1: Flags.
;             Arg2: HANDLE or POINTER.
; Return:     Nothing.

Method NNet.Save, uses xsi, dFlags:DWORD, Destination:XWORD
  local NetHeader:NNT_HEADER, dBytesWritten:DWORD

  SetObject xsi

  mov NetHeader.dMagic, "NNET"
  mrm NetHeader.dWeights, [xsi].dWeightArrSize, eax

  mov ecx, dFlags
  .if (ecx & NNT_FLAG_TOFILE)
    invoke WriteFile, Destination, addr NetHeader, sizeof NetHeader, addr dBytesWritten, 0
    .if !eax
      OCall xsi.ErrorReport, NULL, NNT_ERR_FILEACCESS
      xor eax, eax
      ExitMethod
    .endif
    invoke WriteFile, Destination, [xsi].pWeightArr, [xsi].dWeightArrSize, addr dBytesWritten, 0
    .if !eax
      OCall xsi.ErrorReport, NULL, NNT_ERR_FILEACCESS
      xor eax, eax
      ExitMethod
    .endif
    xor eax, eax
    inc eax

  .elseif (ecx & NNT_FLAG_TOMEM)
    invoke MemClone, Destination, addr NetHeader, sizeof NetHeader
    mov ecx, sizeof NetHeader
    add xcx, Destination
    invoke MemClone, xcx, [xsi].pWeightArr, [xsi].dWeightArrSize
    xor eax, eax
    inc eax

  .else
    OCall xsi.ErrorReport, NULL, NNT_ERR_INVALIDPARAM
    xor eax, eax

  .endif
MethodEnd

; --------------------------------------------------------------------------------------------------
; Method:     NNet.Train
; Purpose:    Train the neural network with a set of input and output values.
; Arguments:  Arg1: -> Input values.
;             Arg2: -> Expected output values.
; Return:     Nothing.

Method NNet.Train, uses xsi, pInputs:POINTER, pOutputs:POINTER
  SetObject xsi

  ; --- Copy inputs ---
  mov ecx, NNT_DATATYPE_SIZE                            ;Skip first Bias value
  add xcx, [xsi].pOutputArr
  mov eax, [xsi].dNetInputs
  shl eax, NNT_LOG2_DATATYPE_SIZE
  invoke MemClone, xcx, pInputs, eax

  OCall xsi.CalcOutputs
  OCall xsi.CalcOutputDeltas, pOutputs
  OCall xsi.BackPropagate
MethodEnd

endif